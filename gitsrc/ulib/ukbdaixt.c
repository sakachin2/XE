//*CID://+v5mvR~:                             update#=  235;       //+v5mvR~
//*************************************************************
//*ukbdaixt.c                                                      //~v584R~
//*kbd get for teraterm screen                                     //~0B22R~
//*************************************************************
//v5mv:080521 (LNX:CON)accept R-Ctrl key string definition max 4   //+v5mvI~
//v5mu:080521 (LNX:CON:BUG)accept string not start with 0x1b as esc string//~v5muI~
//v5bp:040215 (UNX)ctrl+char function support(return scancode)     //~v5bpI~
//v598:031021 reset vt100 option support                           //~v598I~
//v58e:030824 (UNX) move key registration to another header file,ukbdl2.h//~v58eI~
//v58b:030819 (AIX:BUG) user key overflow msg                      //~v58bI~
//v58a:030819 (AIX) --t{t|l} option if TERM!=VT100 for esc str for key ins del etc//~v58aI~
//v589:030819 integrate UKBDLNXC_-->UKBDL_                         //~v58aR~
//v584:030813 (AIX)key file support                                //~v584I~
//v57X:030801 (AIX)defalt curses key setup for all X-term if not duplicated//~v57XI~
//v55w:020601 (UNX)display original input string before trnaslation//~v55wI~
//v55v:020530 (AIX:BUG)chked all key touch                         //~v55tI~
//v55u:020529 (AIX:BUG)null(x00) required scancode(Ctrl+2)         //~v55tI~
//v55t:020528 (AIX:BUG)cannot handle Alt+a etc                     //~v55tI~
//v55s:020528 (AIX)hex notation support for .Xdefaults(0x1b~~xxyyz fmt)//~v55sI~
//v55p:020521 (AIX)aix string allowed 0x01<-->0x7f only,use 0x01 for 0x00 at char code part//~v55pI~
//v555:020421 (AIX)accept key for aixterm                          //~v555I~
//v554:020421 (AIX:BUG)swap left<-->right,pgup<-->pgdn             //~v554I~
//v536:020318 (UNX:BUG)kbd read faile cause loop                   //~v536I~
//v50z:010521 LINUX support:support getch/kbhit                    //~v50zI~
//v504:010307 AIX-X support:use terminfo string                    //~v504I~
//v503:010307 AIX support:print string                             //~v503I~
//v40u:010215 AIX support:(BUG)chng key                            //~v40uI~
//v40u:010111 AIX support:(BUG)for char key                        //~v40uR~
//v40m:001128 AIX support:Ctl+2 for null                           //~0B28I~
//v40g:001111 AIX support:kbd for aix+teraterm                     //~0B11I~
//            accept terminfo key for common operation with vi etc.//~v40gI~
//     001122 teraterm meta option is avail(Alt+char-->esc+char)   //~0B22I~
//     001128 ctl+2 for null.                                      //~0B28I~
//     001129 Alt+BS by 1b08                                       //~0B29I~
//     001211 S+Fn by TERATERM string                              //~0C11I~
//*************************************************************    //~v324I~
#include <stdlib.h>                                                //~v40gI~
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <fcntl.h>
#include <unistd.h>
                                                                   //~v40gI~
#ifdef LNX                                                         //~v40gI~
#include <getopt.h>
#include <linux/types.h>
#include <linux/kd.h>
#include <linux/keyboard.h>
#else                                                              //~v40gI~
	#include <termios.h>                                           //~v40gI~
#endif                                                             //~v40gI~
                                                                   //~v40gI~
#include <sys/ioctl.h>
#include <sys/stat.h>                                              //~v386I~
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <ucurses.h>                                               //~v40gR~
#include <term.h>                                                  //~v324I~

#include <ulib.h>                                                  //~v386I~
#include <ukbdl.h>                                                 //~v40gI~
#include <ukbdlnxc.h>                                              //~v503R~
#define GBL_UKBDAIXT	//generate gbl var in ukbdaixt.h           //~v504I~
#include <ukbdaixt.h>                                              //~v40gI~
#include <ueh.h>                                                   //~v40gI~
#include <uehl.h>                                                  //~v324I~
#include <utrace.h>                                                //~v383I~
#include <ufile.h>                                                 //~v386I~
#include <ualloc.h>                                                //~v386I~
#include <uerr.h>                                                  //~v40gI~
#include <ustring.h>                                               //~v57XI~
//*********************************************************************
//*********************************************************************
#define MODX_PLAIN     0
#define MODX_SHIFT     1
#define MODX_CONTROL   2
#define MODX_ALT       3
#define MODX_EXTKEY   0x10  //on shift id,ID of char code should be 1 down//~v55pI~
                                                                   //~v40gI~
#define TERMINFOSTRID     '['	//string by terminfo original      //~v40gI~
                                                                   //~v324I~
#define CH_ESCAPE        0x1b
#define CH_BACKSP        0x08                                      //~v584I~
#define CH_DELETE        0x7f                                      //~v584I~
#define CH_DELETE_ALT    0xff   //with meta bit                    //~v584I~
#define CH_BACKSP_ALT    0x88   //with meta bit                    //~v584I~
#define READSIZE  32
//*********************************************************************
typedef struct _CURSESKEYTBL{                                      //~v40gI~
                        PFUNCKEYTBL CKTpfkt;                       //~v555R~
                        int     CKTmodx;                           //~v40gI~
                        char   *CKTstring;//terminfo string        //~v40gI~
                        int     CKTlen;   //terminfo string len    //~v40gI~
                    } CURSESKEYTBL,*PCURSESKEYTBL;                 //~v40gI~
#define AIXTERMSTDLEN    6 //x1b[xxxq                              //~v555I~
#define AIXTERMSTDID     'q'                                       //~v555I~
typedef  struct _AIXPFKTBL  {                                      //~v555I~
						PFUNCKEYTBL APTpfkt;                       //~v555I~
                        int         APTmodx;                       //~v555I~
                        int         APTscan_char;                  //~v55tI~
                      } AIXPFKTBL, *PAIXPFKTBL;                    //~v555I~
//*********************************************************************//~v40gI~
static  int Sbs_del_sw=0;//del(0x7f) is assigned for bs(0x08)      //~v584R~
static  int Sdel_by_7f=0; //treate 7f as Del key                   //~v584R~
static AIXPFKTBL Saixpfktbl[256];                                  //~v555I~
static int Skbdinitsw=0;                                           //~0B20R~
static void *Spurr;		//uehl_setsh return eh registration record //~v324I~
static  int  Sreslen;                                              //~v324M~
static  int  Sreadlen;					//read len                 //~v503I~
static  int  Stermid=0; 				//term id by $TERM         //~v57XI~
static unsigned char Sbuff[READSIZE*2];                            //~v503M~
static unsigned char Sorgbuff[READSIZE*2];	//for xekbchk          //~v55wI~
static  unsigned char *Snextpos=0;                                 //~0B20R~
//static  char *Saixstring=0;    //parm from setupcktsub2 to setupcktsub//~v57XR~
static  int Sfd;
//static char Sttstrlineid[]=TTSTRLINEID; //string=                //~v584R~
static char Skfstrlineid[]=KFSTRLINEID; //key parm file            //~v57XI~

static  char *Sshiftidstr[]={"","S+","C+","A+"};                   //~0C11I~
                                                                   //~0C11I~
static  int Sshiftid[]={0,
                      UKBDLNXC_MOD_SHIFTL|UKBDLNXC_MOD_SHIFTR,
                      UKBDLNXC_MOD_CONTROL,
                      UKBDLNXC_MOD_ALT                             //~v40gR~
                      };
//*Alt+char code conversion tbl for doskey(ESC+char)               //~0B22I~
static  unsigned short Saltchartbl[]={                             //~0B22I~
                     0,      //0x00                                //~v55tR~
                     0,      //0x01                                //~0B22I~
                     0,      //0x02                                //~0B22I~
                     0,      //0x03                                //~0B22I~
                     0,      //0x04                                //~0B22I~
                     0,      //0x05                                //~0B22I~
                     0,      //0x06                                //~0B22I~
                     0,      //0x07                                //~0B22I~
                    0x0e00,  //0x08  BackSpace                     //~0B22I~
                    0xa500,  //0x09  Tab                           //~0B22I~
                     0,      //0x0a                                //~0B22I~
                     0,      //0x0b                                //~0B22I~
                     0,      //0x0c                                //~0B22I~
                    0x1c00,  //0x0d  Enter                         //~0B22I~
                     0,      //0x0e                                //~0B22I~
                     0,      //0x0f                                //~0B22I~
                                                                   //~0B22I~
                     0,      //0x10                                //~0B22I~
                     0,      //0x11                                //~0B22I~
                     0,      //0x12                                //~0B22I~
                     0,      //0x13                                //~0B22I~
                     0,      //0x14                                //~0B22I~
                     0,      //0x15                                //~0B22I~
                     0,      //0x16                                //~0B22I~
                     0,      //0x17                                //~0B22I~
                     0,      //0x18                                //~0B22I~
                     0,      //0x19                                //~0B22I~
                     0,      //0x1a                                //~0B22I~
                    0x0100,  //0x1b  Escape                        //~0B22I~
                     0,      //0x1c                                //~0B22I~
                     0,      //0x1d                                //~0B22I~
                     0,      //0x1e                                //~0B22I~
                     0,      //0x1f                                //~0B22I~
                                                                   //~0B22I~
                    0x3920,  //0x20                                //~0B22I~
                     0,      //0x21  !                             //~0B22I~
                     0,      //0x22  "                             //~0B22I~
                     0,      //0x23  #                             //~0B22I~
                     0,      //0x24  $                             //~0B22I~
                     0,      //0x25  %                             //~0B22I~
                     0,      //0x26  &                             //~0B22I~
                     0,      //0x27  '                             //~0B22I~
                     0,      //0x28  (                             //~0B22I~
                     0,      //0x29  )                             //~0B22I~
                     0,      //0x2a  *                             //~0B22I~
                     0,      //0x2b  +                             //~0B22I~
                    0x3300,  //0x2c  ,                             //~0B22I~
                    0x8200,  //0x2d  -                             //~0B22I~
                    0x3400,  //0x2e  .                             //~0B22I~
                    0x3500,  //0x2f  /                             //~0B22I~
                                                                   //~0B22I~
                    0x8100,  //0x30  0                             //~0B22I~
                    0x7800,  //0x31  1                             //~0B22I~
                    0x7900,  //0x32  2                             //~0B22I~
                    0x7a00,  //0x33  3                             //~0B22I~
                    0x7b00,  //0x34  4                             //~0B22I~
                    0x7c00,  //0x35  5                             //~0B22I~
                    0x7d00,  //0x36  6                             //~0B22I~
                    0x7e00,  //0x37  7                             //~0B22I~
                    0x7f00,  //0x38  8                             //~0B22I~
                    0x8000,  //0x39  9                             //~0B22I~
                    0x2800,  //0x3a  :                             //~0B22I~
//                  0x2700   //0x3b  ;                             //~0B22I~
                    0x2700,  //0x3b  ;                             //~0B22I~
                     0,      //0x3c                                //~0B22I~
                     0,      //0x3d                                //~0B22I~
                     0,      //0x3e                                //~0B22I~
                     0,      //0x3f                                //~0B22I~
                                                                   //~0B22I~
                    0x1a00,  //0x40    @                           //~0B22I~
                     0,      //0x41    A                           //~0B22I~
                     0,      //0x42    B                           //~0B22I~
                     0,      //0x43    C                           //~0B22I~
                     0,      //0x44    D                           //~0B22I~
                     0,      //0x45    E                           //~0B22I~
                     0,      //0x46    F                           //~0B22I~
                     0,      //0x47    G                           //~0B22I~
                     0,      //0x48    H                           //~0B22I~
                     0,      //0x49    I                           //~0B22I~
                     0,      //0x4a    J                           //~0B22I~
                     0,      //0x4b    K                           //~0B22I~
                     0,      //0x4c    L                           //~0B22I~
                     0,      //0x4d    M                           //~0B22I~
                     0,      //0x4e    N                           //~0B22I~
                     0,      //0x4f    O                           //~0B22I~
                                                                   //~0B22I~
                     0,      //0x50    P                           //~0B22I~
                     0,      //0x51    Q                           //~0B22I~
                     0,      //0x52    R                           //~0B22I~
                     0,      //0x53    S                           //~0B22I~
                     0,      //0x54    T                           //~0B22I~
                     0,      //0x55    U                           //~0B22I~
                     0,      //0x56    V                           //~0B22I~
                     0,      //0x57    W                           //~0B22I~
                     0,      //0x58    X                           //~0B22I~
                     0,      //0x59    Y                           //~0B22I~
                     0,      //0x5a    Z                           //~0B22I~
                    0x1b00,  //0x5b   [                            //~0B22I~
//                  0x7d00,  //0x5c   "\"                          //~v55tR~
                     0,      //0x5c   "\"                          //~v55tI~
                    0x2b00,  //0x5d   ]                            //~0B22I~
                    0x8300,  //0x5e   ^                            //~0B22I~
                     0,      //0x5f    _ under_score               //~0B22I~
                                                                   //~0B22I~
                     0,      //0x60    ` grave                     //~0B22I~
                    0x1e00,  //0x61    a                           //~0B22I~
                    0x3000,  //0x62    b                           //~0B22I~
                    0x2e00,  //0x63    c                           //~0B22I~
                    0x2000,  //0x64    d                           //~0B22I~
                    0x1200,  //0x65    e                           //~0B22I~
                    0x2100,  //0x66    f                           //~0B22I~
                    0x2200,  //0x67    g                           //~0B22I~
                    0x2300,  //0x68    h                           //~0B22I~
                    0x1700,  //0x69    i                           //~0B22I~
                    0x2400,  //0x6a    j                           //~0B22I~
                    0x2500,  //0x6b    k                           //~0B22I~
                    0x2600,  //0x6c    l                           //~0B22I~
                    0x3200,  //0x6d    m                           //~0B22I~
                    0x3100,  //0x6e    n                           //~0B22I~
                    0x1800,  //0x6f    o                           //~0B22I~
                                                                   //~0B22I~
                    0x1900,  //0x70    p                           //~0B22I~
                    0x1000,  //0x71    q                           //~0B22I~
                    0x1300,  //0x72    r                           //~0B22I~
                    0x1f00,  //0x73    s                           //~0B22I~
                    0x1400,  //0x74    t                           //~0B22I~
                    0x1600,  //0x75    u                           //~0B22I~
                    0x2f00,  //0x76    v                           //~0B22I~
                    0x1100,  //0x77    w                           //~0B22I~
                    0x2d00,  //0x78    x                           //~0B22I~
                    0x1500,  //0x79    y                           //~0B22I~
                    0x2c00,  //0x7a    z                           //~0B22I~
                     0,      //0x7b                                //~0B22I~
                     0,      //0x7c                                //~0B22I~
                     0,      //0x7d                                //~0B22I~
                     0,      //0x7e                                //~0B22I~
                     0       //0x7f                                //~0B22I~
                    };                                             //~0B22I~
//scancode table for char<x20                                      //~v324I~
static  unsigned char Snormalscantbl[]={                           //~v324R~
//                   0,      //0x00                                //~v55tR~
                    0x03/*00*/,  //0x00 null char(C+2)             //~v55tR~
          0x1e,//    0,      //0x01                                //~v5bpR~
          0x30,//    0,      //0x02                                //~v5bpR~
          0x2e,//    0,      //0x03                                //~v5bpR~
          0x20,//    0,      //0x04                                //~v5bpR~
          0x12,//    0,      //0x05                                //~v5bpR~
          0x21,//    0,      //0x06                                //~v5bpR~
          0x22,//    0,      //0x07                                //~v5bpR~
                    0x0e/*08*/,  //0x08  BackSpace                 //~v324R~
                    0x0f/*09*/,  //0x09  Tab                       //~v324R~
          0x24,//    0,      //0x0a                                //~v5bpR~
          0x25,//    0,      //0x0b                                //~v5bpR~
          0x26,//    0,      //0x0c                                //~v5bpR~
                    0x1c/*0d*/,  //0x0d  Enter                     //~v324R~
          0x31,//    0,      //0x0e                                //~v5bpR~
          0x18,//    0,      //0x0f                                //~v5bpR~
                                                                   //~v324R~
          0x19,//    0,      //0x10                                //~v5bpR~
          0x10,//    0,      //0x11                                //~v5bpR~
          0x13,//    0,      //0x12                                //~v5bpR~
          0x1f,//    0,      //0x13                                //~v5bpR~
          0x14,//    0,      //0x14                                //~v5bpR~
          0x16,//    0,      //0x15                                //~v5bpR~
          0x2f,//    0,      //0x16                                //~v5bpR~
          0x11,//    0,      //0x17                                //~v5bpR~
          0x2d,//    0,      //0x18                                //~v5bpR~
          0x15,//    0,      //0x19                                //~v5bpR~
          0x2c,//    0,      //0x1a                                //~v5bpR~
                    0x01/*1b*/,  //0x1b  Escape                    //~v324R~
                     0,      //0x1c                                //~v324R~
                     0,      //0x1d                                //~v324R~
                     0,      //0x1e                                //~v324R~
                     0       //0x1f                                //~v324R~
                     };                                            //~v324R~
                                                                   //~v324I~

//*Fxx and doskey code assingn to Funckey with modifier(plain,shift,ctrl,alt)//~v40gR~
static  FUNCKEYTBL Sfkt_F1    ={ 59,"F1" ,{1,1,1,1},{0x3b00,0x5400,0x5e00,0x6800}};//~v555R~
static  FUNCKEYTBL Sfkt_F2    ={ 60,"F2" ,{1,1,1,1},{0x3c00,0x5500,0x5f00,0x6900}};//~v555R~
static  FUNCKEYTBL Sfkt_F3    ={ 61,"F3" ,{1,1,1,1},{0x3d00,0x5600,0x6000,0x6a00}};//~v555R~
static  FUNCKEYTBL Sfkt_F4    ={ 62,"F4" ,{1,1,1,1},{0x3e00,0x5700,0x6100,0x6b00}};//~v555R~
static  FUNCKEYTBL Sfkt_F5    ={ 63,"F5" ,{1,1,1,1},{0x3f00,0x5800,0x6200,0x6c00}};//~v555R~
static  FUNCKEYTBL Sfkt_F6    ={ 64,"F6" ,{1,1,1,1},{0x4000,0x5900,0x6300,0x6d00}};//~v555R~
static  FUNCKEYTBL Sfkt_F7    ={ 65,"F7" ,{1,1,1,1},{0x4100,0x5a00,0x6400,0x6e00}};//~v555R~
static  FUNCKEYTBL Sfkt_F8    ={ 66,"F8" ,{1,1,1,1},{0x4200,0x5b00,0x6500,0x6f00}};//~v555R~
static  FUNCKEYTBL Sfkt_F9    ={ 67,"F9" ,{1,1,1,1},{0x4300,0x5c00,0x6600,0x7000}};//~v555R~
static  FUNCKEYTBL Sfkt_F10   ={ 68,"F10",{1,1,1,1},{0x4400,0x5d00,0x6700,0x7100}};//~v555R~
static  FUNCKEYTBL Sfkt_F11   ={ 87,"F11",{1,1,1,1},{0x8500,0x8700,0x8900,0x8b00}};//~v555R~
static  FUNCKEYTBL Sfkt_F12   ={ 88,"F12",{1,1,1,1},{0x8600,0x8800,0x8a00,0x8c00}};//~v555R~

static  FUNCKEYTBL Sfkt_FIND  ={327,"Home"    ,{1,1,1,1},{0x4700,0x4700,0x7700,0x9700}};//Home//~v555R~
static  FUNCKEYTBL Sfkt_SELECT={335,"End"     ,{1,1,1,1},{0x4f00,0x4f00,0x7500,0x9f00}};//End//~v555R~
static  FUNCKEYTBL Sfkt_INSERT={338,"Insert"  ,{1,1,1,1},{0x5200,0x5200,0x9200,0xa200}};//~v555R~
static  FUNCKEYTBL Sfkt_REMOVE={339,"Delete"  ,{1,1,1,1},{0x5300,0x5300,0x9300,0xa300}};//~v555R~
static  FUNCKEYTBL Sfkt_PGUP  ={329,"PageUp"  ,{1,1,1,1},{0x4900,0x4900,0x8400,0x9900}};//~v555R~
static  FUNCKEYTBL Sfkt_PGDN  ={337,"PageDown",{1,1,1,1},{0x5100,0x5100,0x7600,0xa100}};//~v555R~
static  FUNCKEYTBL Sfkt_UP    ={328,"Up"      ,{1,1,1,1},{0x4800,0x4800,0x8d00,0x9800}};//~v555R~
static  FUNCKEYTBL Sfkt_DOWN  ={336,"Down"    ,{1,1,1,1},{0x5000,0x5000,0x9100,0xa000}};//~v555R~
static  FUNCKEYTBL Sfkt_LEFT  ={331,"Left"    ,{1,1,1,1},{0x4b00,0x4b00,0x7300,0x9b00}};//~v555R~
static  FUNCKEYTBL Sfkt_RIGHT ={333,"Right"   ,{1,1,1,1},{0x4d00,0x4d00,0x7400,0x9d00}};//~v555R~

static  FUNCKEYTBL Sfkt_ESCAPE={  1,"Esc"      ,{0,1,1,0},{0x011b,0x011b,0x011b,0x0100}};//~v555R~
static  FUNCKEYTBL Sfkt_BS    ={ 14,"Backspace",{0,1,1,0},{0x0e08,0x0e08,0x0e7f,0x0e00}};//~v555R~
static  FUNCKEYTBL Sfkt_TAB   ={ 15,"Tab"      ,{0,1,1,0},{0x0f09,0x0f00,0x9400,0xa500}};//~v555R~
static  FUNCKEYTBL Sfkt_ENTER ={ 28,"Enter"    ,{0,1,1,0},{0x1c0d,0x1c0d,0x1c0a,0x1c00}};//~v555R~
                                                                   //~0B28I~
static  FUNCKEYTBL Sfkt_2     ={  3,"2"        ,{0,0,1,0},{0x0332,0x0322,0x0300,0x7900}};//~v555R~
                                                                   //~0B23I~
static  FUNCKEYTBL Sfkt_NENTER={284,"KP_Enter" ,{1,1,1,1},{0xe00d,0xe00d,0xe00a,0xa600}};//~v584R~
                                                                   //~0B23I~
//#ifdef  NUMPADAVIL      //only num with no shift is available by tterm//~0B29R~
static  FUNCKEYTBL Sfkt_N0    ={ 82,"P0"      ,{0,0,1,0},{0xffff,0xffff,0x9200,0xffff}};//~v584R~
static  FUNCKEYTBL Sfkt_N1    ={ 79,"P1"      ,{0,0,1,0},{0xffff,0xffff,0x7500,0xffff}};//~v584R~
static  FUNCKEYTBL Sfkt_N2    ={ 80,"P2"      ,{0,0,1,0},{0xffff,0xffff,0x9100,0xffff}};//~v584R~
static  FUNCKEYTBL Sfkt_N3    ={ 81,"P3"      ,{0,0,1,0},{0xffff,0xffff,0x7600,0xffff}};//~v584R~
static  FUNCKEYTBL Sfkt_N4    ={ 75,"P4"      ,{0,0,1,0},{0xffff,0xffff,0x7300,0xffff}};//~v584R~
static  FUNCKEYTBL Sfkt_N5    ={ 76,"P5"      ,{0,0,1,0},{0xffff,0xffff,0x8f00,0xffff}};//~v584R~
static  FUNCKEYTBL Sfkt_N6    ={ 77,"P6"      ,{0,0,1,0},{0xffff,0xffff,0x7400,0xffff}};//~v584R~
static  FUNCKEYTBL Sfkt_N7    ={ 71,"P7"      ,{0,0,1,0},{0xffff,0xffff,0x7700,0xffff}};//~v584R~
static  FUNCKEYTBL Sfkt_N8    ={ 72,"P8"      ,{0,0,1,0},{0xffff,0xffff,0x8d00,0xffff}};//~v584R~
static  FUNCKEYTBL Sfkt_N9    ={ 73,"P9"      ,{0,0,1,0},{0xffff,0xffff,0x8400,0xffff}};//~v584R~
                                                                   //~0B23I~
static  FUNCKEYTBL Sfkt_NPLUS ={ 78,"P+"      ,{0,0,1,0},{0xffff,0xffff,0x9000,0x4e00}};//~v584R~
static  FUNCKEYTBL Sfkt_NMINUS={ 74,"P-"      ,{0,0,1,0},{0xffff,0xffff,0x8e00,0x4a00}};//~v584R~
static  FUNCKEYTBL Sfkt_NMUL  ={ 55,"P*"      ,{0,0,1,0},{0xffff,0xffff,0x9600,0x3700}};//~v584R~
static  FUNCKEYTBL Sfkt_NDIV  ={309,"P/"      ,{0,0,1,0},{0xffff,0xffff,0x9500,0xa400}};//~v584R~
static  FUNCKEYTBL Sfkt_NDOT  ={ 83,"P."      ,{0,0,1,0},{0xffff,0xffff,0x9300,0xffff}};//~v584R~
//#endif                                                           //~0B29R~
                                                                   //~v324R~
#define PFKTGEN(funcname)       \
            &Sfkt_##funcname
static PFUNCKEYTBL Spfktbl[]={
         PFKTGEN(F1 ),
         PFKTGEN(F2 ),
         PFKTGEN(F3 ),
         PFKTGEN(F4 ),
         PFKTGEN(F5 ),
         PFKTGEN(F6 ),
         PFKTGEN(F7 ),
         PFKTGEN(F8 ),
         PFKTGEN(F9 ),
         PFKTGEN(F10),
         PFKTGEN(F11),
         PFKTGEN(F12),

         PFKTGEN(FIND  ), //Home                                   //~v324R~
         PFKTGEN(SELECT), //End                                    //~v324R~
         PFKTGEN(INSERT),
         PFKTGEN(REMOVE),
         PFKTGEN(PGUP  ),
         PFKTGEN(PGDN  ),
         PFKTGEN(UP    ),
         PFKTGEN(DOWN  ),
         PFKTGEN(LEFT  ),
         PFKTGEN(RIGHT ),

         PFKTGEN(ESCAPE),
         PFKTGEN(BS    ),
         PFKTGEN(TAB   ),
         PFKTGEN(ENTER ),
                                                                   //~0B28I~
         PFKTGEN(2     ),                                          //~0B28I~
                                                                   //~0B23I~
         PFKTGEN(NENTER),                                          //~0B23R~
                                                                   //~0B29I~
//#ifdef  NUMPADAVIL      //only num with no shift is available by tterm//~0B29R~
         PFKTGEN(N0    ),                                          //~0B23I~
         PFKTGEN(N1    ),                                          //~0B23I~
         PFKTGEN(N2    ),                                          //~0B23I~
         PFKTGEN(N3    ),                                          //~0B23I~
         PFKTGEN(N4    ),                                          //~0B23I~
         PFKTGEN(N5    ),                                          //~0B23I~
         PFKTGEN(N6    ),                                          //~0B23I~
         PFKTGEN(N7    ),                                          //~0B23I~
         PFKTGEN(N8    ),                                          //~0B23I~
         PFKTGEN(N9    ),                                          //~0B23I~
         PFKTGEN(NPLUS ),                                          //~0B23I~
         PFKTGEN(NMINUS),                                          //~0B23I~
         PFKTGEN(NMUL  ),                                          //~0B23I~
         PFKTGEN(NDIV  ),                                          //~0B23I~
         PFKTGEN(NDOT  )                                           //~0B23I~
//#endif                                                           //~0B29R~
                                                                   //~0B29I~
         };
#define PFKTNO (sizeof(Spfktbl)/sizeof(Spfktbl[0]))
                                                                   //~0B11I~
//*curses key table                                                //~v40gI~
//#define CKTNO PFKTNO                                             //~v555R~
#define CKTNO (PFKTNO*4)                                           //~v555R~
static CURSESKEYTBL Scurseskeytbl[CKTNO];                          //~v40gI~
static int          Scktno=0;             //count of to use terminfo string//~0B20R~
                                                                   //~v40gI~
//*tera-term userkey                                               //~v40gI~
//static  USERKEYTBL Suserkeytbl[256*2];//indexed by ext-key scancode//~v503R~
                                                                   //~v40gI~
//*********************************************************************
void ukbdaixt_optproc(int Popt,unsigned char *);                   //~v40gR~
int  ukbdaixt_delopt(int Popt);                                    //~v584I~
void ukbdaixt_termexit(int Psigno);                                //~0B11R~
int ukbdaixt_readkbd(char *Pout,int *Pmodifier,int Ppeeksw);       //~v50zR~
void ukbdaixt_cleanup(int Prestoresw);                             //~0B11R~
int ukbdaixt_getconsole(void);                                     //~0B11R~
int ukbdaixt_open(char *Pname);                                    //~0B11R~
int ukbdaixt_chkconsole(int Pfd);                                  //~0B11R~
void ukbdaixt_setupckt(void);                                      //~v40gR~
void ukbdaixt_setupcktx(void);                                     //~v57XI~
void ukbdaixt_setupcktlnx(void);                                   //~v57XI~
void ukbdaixt_addstrtbl(int Popt,int Pflag,char *Pstring,FUNCKEYTBL *Ppfkt,int Pmodx,int len);//~v57XI~
int ukbdaixt_dupstrchk(int Popt,char *Pstring,FUNCKEYTBL *Ppfkt,int Pmodx,int Plen);//~v57XI~
#define ADDSTT_DUPIGNORE    0x01                                   //~v57XI~
#define ADDSTT_DUPRESET     0x02                                   //~v57XI~
//int ukbdaixt_setupcktsub(PFUNCKEYTBL Ppfkt,int Pmodx,char *Pstring,char *Ptistr);//~v57XR~
int ukbdaixt_setupcktsub(int Pflag,PFUNCKEYTBL Ppfkt,int Pmodx,char *Pstring,char *Ptistr);//~v57XI~
//int ukbdaixt_setupcktsub2(PFUNCKEYTBL Ppfkt,int Pmodx,char *Paixstring,char *Ptistr);//~v57XR~
void ukbdaixt_setupaixstd(void);                                   //~v555I~
//*********************************************************************//~v324I~
//*********************************************************************//~v503I~
//* return pfktbl addr                                             //~v503I~
//*********************************************************************//~v503I~
int ukbdaixt_gettbl(PFUNCKEYTBL **Pppfkt,int *Ppfktno,             //~v503I~
					char **Ppreadbuff,int **Ppreadlen)             //~v503I~
{                                                                  //~v503I~
	if (Pppfkt)                                                    //~v503I~
		*Pppfkt=Spfktbl;                                           //~v503I~
	if (Ppfktno)                                                   //~v503I~
    	*Ppfktno=PFKTNO;                                           //~v503I~
	if (Ppreadbuff)                                                //~v503I~
//  	*Ppreadbuff=Sbuff;                                         //~v55wR~
    	*Ppreadbuff=Sorgbuff;                                      //~v55wI~
	if (Ppreadlen)                                                 //~v503I~
		*Ppreadlen=&Sreadlen;                                      //~v503I~
    return 0;                                                      //~v503I~
}//ukbdlnxc_gettbl                                                 //~v503I~
//*********************************************************************
//* kbd init
//* parm1:option by -- flag parm (and default)                     //~v384I~
//* parm2:Fn key assign table for xe with shift modifier           //~v384I~
//*********************************************************************
int ukbdlnxc_init(int Popt,unsigned char *Passignkey)              //~v40gR~
{
    int termid;                                                    //~v555I~
//*******************************
    if (Skbdinitsw)	//second time                                  //~v324R~
    	return 0;                                                  //~v324I~
    Skbdinitsw=1;                                                  //~v324I~
  if (Stermid)     //chngttkey called                              //~v584I~
    termid=Stermid;                                                //~v584R~
  else                                                             //~v584I~
    Stermid=                                                       //~v57XI~
    termid=ukbdl_gettermid();                                      //~v555R~
    termid&=TERM_SIMID;                                            //~v584I~
//  if (termid==TERM_AIXTERM)                                      //~v584I~
//      Gkbdaixt_opt|=(GKBAIX_XAIXTERM|GKBAIX_XXTERM);     //xterm on x//~v584I~
//  if (termid==TERM_DTTERM)                                       //~v584I~
//      Gkbdaixt_opt|=GKBAIX_XXTERM;     //xterm on x              //~v584I~
  	if (termid && termid==TERM_TELNET)                             //~v584R~
    {                                                              //~v584I~
        Gkbdaixt_opt|=GKBAIX_TELNET;     //xterm on x              //~v584I~
        if ((Stermid & TERM_IDMASK)==TERM_VT100)  	//teraterm     //~v584I~
        {                                                          //~v598I~
          if (!(Popt & UKBDL_TNLNX))      //not force linux        //~v598I~
        	Gkbdaixt_opt|=GKBAIX_TTERM;     //teraterm             //~v584I~
        }                                                          //~v598I~
        else                                                       //~v58aI~
        if (Popt & UKBDL_TNTT)      //force teraterm option        //~v58aI~
        	Gkbdaixt_opt|=GKBAIX_TTERM;     //teraterm             //~v58aI~
    }                                                              //~v584I~
    else                                                           //~v584I~
  	{                                                              //~v584I~
        Gkbdaixt_opt|=GKBAIX_XXTERM;     //xterm on x              //~v584I~
    	if (termid==TERM_AIXTERM)                                  //~v584R~
        	Gkbdaixt_opt|=GKBAIX_XAIXTERM;                         //~v584R~
  	}                                                              //~v584I~
    ukbdaixt_optproc(Popt,Passignkey);                             //~0B11R~
    Sfd=ukbdaixt_getconsole();                                     //~0B11R~
    Spurr=uehl_setsh((void*)ukbdaixt_termexit);                    //~0B11R~
    ukbdaixt_setupuserkey(0,0); //assing user keyno,no ptr output  //~0B23R~
    ukbdl_setkbmode(0);      //set raw mode                        //~v40gR~
    Sreslen=0;                                                     //~v324I~
    return 0;
}//ukbdlnxc_init                                                   //~v40gR~
//*********************************************************************
//* kbd term
//*********************************************************************
int ukbdlnxc_term(int Prestoresw)                                  //~v40gR~
{
//*******************************
    if (!Skbdinitsw)                                               //~v324I~
    	return 0;                                                  //~v324I~
    ukbdaixt_cleanup(Prestoresw);                                  //~0B11R~
    uehl_resetsh(Spurr);                                           //~v324I~
    Skbdinitsw=0;                                                  //~v324I~
    return 0;
}//ukbdlnxc_term                                                   //~v40gR~
//*********************************************************************
//* read kbd
//* Pnowait:0:read wait,1:read nowait,-1:peek                      //~v324I~
//* ret:outputlen 1:letter,2:extended key
//*********************************************************************
int ukbdlnxc_read(char *Pout,int *Pshiftstatus,int Pnowait)        //~v40gR~
{
    int modx,rc;                                                   //~v50zR~
//    unsigned char *nextpos;                                      //~v50zR~
//************************
    *Pshiftstatus=0;
//  if (!Sreslen && Pnowait)    //nowait req                       //~v50zR~
//  	return 0;				                                   //~v50zR~
//    reslen=Sreslen;                                              //~v50zR~
//    nextpos=Snextpos;                                            //~v50zR~
    rc=ukbdaixt_readkbd(Pout,&modx,(Pnowait<0));                   //~v50zR~
    *Pshiftstatus=Sshiftid[modx];                                  //~v324M~
//    if (Pnowait<0)  //peek req                                   //~v50zR~
//    {                                                            //~v50zR~
//        Sreslen=reslen;                                          //~v50zR~
//        Snextpos=nextpos;                                        //~v50zR~
//    }                                                            //~v50zR~
    return rc;                                                     //~v324R~
}//ukbdlnxc_read                                                   //~v40gR~
//*********************************************************************
//* read kbd
//* parm1:2byte output(charcode+scancode)                          //~0B18I~
//* parm2:output shift modifier 1:shift,2:ctl,4:alt                //~0B18I~
//* ret:0:no input,1:data gotten                                   //~v324R~
//*********************************************************************
int ukbdaixt_readkbd(char *Pout,int *Pmodifier,int Ppeeksw)        //~v50zR~
{
static  int Sdbcssw=0;                                             //~v584I~
    PCURSESKEYTBL pckt,pckte;                                      //~v40gI~
    PFUNCKEYTBL pfkt;                                              //~v555R~
    int scancode,charcode,doskey,modx,len;                         //~0B23R~
    int ii;                                                        //~v536I~
    int funcno,xwork;                                              //~v55sI~
    int aixpfkno,dgt;                                              //~v555R~
#define PRINTF(casen,top,len)\
    {int xx;char *pc;        \
        printw("case=%d: ",casen); \
        for (xx=len,pc=top;xx>0;xx--,pc++) \
             	printw("%02x ",*pc);         \
        	printw("\n");                      \
    }                                         
//************************
//printf("entry reslen=%d\n",Sreslen);
    *Pmodifier=0;
    *(Pout+1)=0;	//clear scan code for char key                 //~0B18R~
//  if (!Sreslen)                                                  //~v536R~
    if (Sreslen<=0)		//confirm loop protection                  //~v536R~
    {
        Snextpos=Sbuff;                                            //~v324M~
      for (ii=0;ii<10;ii++)	//try 10 times                         //~v536M~
      {                                                            //~v536M~
        Sreadlen=                                                  //~v503I~
        Sreslen=read(Sfd,Sbuff,READSIZE);                          //~v324R~
//PRINTF(0,Sbuff,Sreslen);                                         //~v324R~
		if (Sreslen>0)                                             //~v536I~
        	break;                                                 //~v536I~
      }                                                            //~v536I~
	  if (Sreslen<=0)                                              //~v536I~
      	return 0;                                                  //~v536I~
    }
    memcpy(Sorgbuff,Sbuff,READSIZE); //for xekbchk                 //~v55wR~
    if (Ppeeksw)                                                   //~v50zI~
    	return Sreslen;                                            //~v50zI~
    if (Sdbcssw)                                                   //~v584I~
    {                                                              //~v584I~
        Sdbcssw=0;                                                 //~v584I~
        *Pout=*Snextpos++;                                         //~v584I~
        Sreslen--;                                                 //~v584I~
        return 1;                                                  //~v584I~
    }                                                              //~v584I~
    for(;;)                                                        //~v40gR~
    {
        if (*Snextpos!=CH_ESCAPE||Sreslen==1)	//or esc only      //~v324R~
        {                                                          //~v324I~
    		if (*Snextpos==CH_DELETE)                              //~v584I~
            {                                                      //~v584I~
              	if (Sbs_del_sw)	//0x7f by BS key                   //~v584I~
            		*Snextpos=CH_BACKSP;                           //~v584I~
              	else                                               //~v584I~
			  	if (Sdel_by_7f) //treate 7f as Del key             //~v584I~
              	{                                                  //~v584I~
                	Sreslen=0;      //processed                    //~v584I~
        			*Pmodifier=0;	//shift is not identified      //~v584I~
        			*(unsigned short *)(void*)Pout=Sfkt_REMOVE.FKTdoskey[0];//~v584I~
        			return 1;                                      //~v584I~
        	  	}                                                  //~v584I~
            }                                                      //~v584I~
            if (*Snextpos<0x20)                                    //~v324I~
            {                                                      //~v584I~
                if (Snormalscantbl[*Snextpos])                     //~v324I~
                {                                                  //~v324I~
                    *Pout++=*Snextpos;                             //~v324I~
                    *Snextpos=Snormalscantbl[*Snextpos];           //~v324I~
                }                                                  //~v324I~
            }	//ctl ctar                                         //~v584I~
            else                                                   //~v584I~
            if (*Snextpos & 0x80)//meta bit                        //~v584I~
            {                                                      //~v584I~
                if (Sreslen==1)//not dbcs meta char                //~v584I~
                {                                                  //~v584I~
                    if (*Snextpos==CH_DELETE_ALT)                  //~v584I~
                    {                                              //~v584I~
                        if (Sdel_by_7f) //treate 7f as Del key     //~v584I~
                        {                                          //~v584I~
                            Sreslen=0;      //processed            //~v584I~
                            *Pmodifier=MODX_ALT;                   //~v584I~
                            *(unsigned short *)(void*)Pout=Sfkt_REMOVE.FKTdoskey[MODX_ALT];//~v584I~
                            return 1;                              //~v584I~
                        }                                          //~v584I~
                    }                                              //~v584I~
                    *(unsigned short *)(void *)Pout=Saltchartbl[(int)(*Snextpos&0x7f)];//~v584I~
                    Sreslen=0;                                     //~v584I~
                    Snextpos++;                                    //~v584I~
                    return 1;                                      //~v584I~
                }                                                  //~v584I~
                else                                               //~v584I~
                {                                                  //~v584I~
                    if (Sreslen>=2)//dbcs                          //~v584R~
                    {                                              //~v584I~
                        Sdbcssw=1;                                 //~v584I~
                        *Pout=*Snextpos++;                         //~v584I~
                        Sreslen--;                                 //~v584R~
                        return 1;                                  //~v584I~
                    }                                              //~v584I~
                }//sbcs/dbcs                                       //~v584I~
            }                                                      //~v584I~
            break;  //letter key                                   //~v324R~
        }                                                          //~v324I~
                                                                   //~v324I~
        if (*(Snextpos+1)!=FUNCSTRID)   //teraterm user key        //~0B22R~
        {
//* search teraterm key string tbl                                 //~0B23R~
        	if (*(Snextpos+1)==TERMINFOSTRID)   //'['              //~v40gI~
            {                                                      //~v40gI~
//* chk aixterm std fmt 	ESC[xxxq                               //~v555I~
				if (Sreslen>=AIXTERMSTDLEN                         //~v555I~
                && *(Snextpos+AIXTERMSTDLEN-1)==AIXTERMSTDID)      //~v555R~
                {                                                  //~v555I~
                    dgt=*(Snextpos+2);                             //~v555I~
                    if (dgt>='0' && dgt<='9')                      //~v555I~
                    {                                              //~v555I~
                        aixpfkno=dgt-'0';                          //~v555I~
                    	dgt=*(Snextpos+3);                         //~v555I~
                    	if (dgt>='0' && dgt<='9')                  //~v555I~
                        {                                          //~v555I~
	                        aixpfkno=aixpfkno*10+dgt-'0';          //~v555I~
                    	    dgt=*(Snextpos+4);                     //~v555I~
	                    	if (dgt>='0' && dgt<='9')              //~v555I~
                        	{                                      //~v555I~
	                        	aixpfkno=aixpfkno*10+dgt-'0';      //~v555I~
                                if (aixpfkno>0 && aixpfkno<256)    //~v555I~
                    			{                                  //~v555R~
                        			if (pfkt=Saixpfktbl[aixpfkno].APTpfkt,pfkt)//~v555R~
                        			{                              //~v555R~
                            			Sreslen-=AIXTERMSTDLEN;    //~v555R~
                            			Snextpos+=AIXTERMSTDLEN;   //~v555R~
                            			modx=Saixpfktbl[aixpfkno].APTmodx;//~v555R~
                            			*Pmodifier=modx;           //~v555R~
                                      if (pfkt==(PFUNCKEYTBL)(-1))   //pfk for Mod+char//~v55tR~
                        			 	doskey=Saixpfktbl[aixpfkno].APTscan_char;//~v55tI~
                                      else                         //~v55tI~
                            			doskey=pfkt->FKTdoskey[modx];//~v555R~
    //output char+scan for char key                                //~v555R~
                            			*Pout=(unsigned char)(doskey&255);  //charcode//~v555R~
                            			*(Pout+1)=(unsigned char)((unsigned)doskey>>8);//scan code//~v555R~
                            			return 1;//data exist      //~v555R~
                                    }//assigned                    //~v555R~
                                }//1-255                           //~v555I~
                            }//3rd id digit                        //~v555I~
                        }//2nd is digit                            //~v555R~
                    }//1st is digit                                //~v555I~
                }//<esc>[xxxq                                      //~v555R~
            }//esc+[                                               //~v584I~
//* search teraterm key string tbl                                 //~0B23R~
    			for (pckt=Scurseskeytbl,pckte=Scurseskeytbl+Scktno;pckt<pckte;pckt++)//~v40gI~
    			{                                                  //~v40gI~
        			len=pckt->CKTlen;                              //~v40gI~
        			if (Sreslen>=len && !memcmp(Snextpos,pckt->CKTstring,len))//~v40gI~
                    {                                              //~v40gI~
                        Sreslen-=len;                              //~v40gI~
                        Snextpos+=len;                             //~v40gI~
                        modx=pckt->CKTmodx;                        //~v40gI~
                        *Pmodifier=modx;                           //~v40gI~
                        doskey=pckt->CKTpfkt->FKTdoskey[modx];     //~0B18R~
//output char+scan for char key                                    //~0B18R~
        				*Pout=(unsigned char)(doskey&255);	//charcode//~0B20R~
        				*(Pout+1)=(unsigned char)((unsigned)doskey>>8);//scan code//~0B20R~
                        return 1;//data exist                      //~v40gR~
                    }                                              //~v40gI~
                }//search loop                                     //~v40gI~
//          }//esc+[                                               //~v584R~
//meta+                                                            //~0B22I~
            if (*(Snextpos+1)==CH_DELETE)                          //~v584I~
            {                                                      //~v584I~
                if (Sdel_by_7f) //treate 7f as Del key             //~v584I~
                {                                                  //~v584I~
                    Sreslen-=2;      //processed                   //~v584I~
                    Snextpos+=2;      //processed                  //~v584I~
                    *Pmodifier=MODX_ALT;                           //~v584I~
                    *(unsigned short *)(void*)Pout=Sfkt_REMOVE.FKTdoskey[MODX_ALT];//~v584I~
                    return 1;                                      //~v584I~
                }                                                  //~v584I~
            }                                                      //~v584I~
        	doskey=Saltchartbl[(int)*(Snextpos+1)];                //~0B29R~
            if (doskey)	//Alt+char defined                         //~0B22I~
            {                                                      //~0B22I~
	            *Pmodifier=MODX_ALT;                               //~0B22I~
        		*Pout=(unsigned char)(doskey&255);	//charcode     //~0B22I~
        		*(Pout+1)=(unsigned char)((unsigned)doskey>>8);//scan code//~0B22I~
            	Sreslen-=2;                                        //~0B22I~
            	Snextpos+=2;                                       //~0B22I~
            	return 1;                                          //~0B22I~
            }                                                      //~0B22I~
			break;                                                 //~v40gI~
        }
        if (Sreslen<USERSTRLEN)     //1b7e+scan+char+modx;         //~v503R~
            break;                                                 //~v324R~
      if (*(Snextpos+2)==FUNCSTRID    //1b~~xxyyz fmt              //~v55sI~
      &&  Sreslen>=USERSTRLEN2)                                    //~v55sI~
      {                                                            //~v55sI~
//scancode                                                         //~v55sI~
        xwork=*(Snextpos+3);                                       //~v55sI~
        if (xwork>='0' && xwork<='9')                              //~v55sI~
            funcno=xwork-'0';                                      //~v55sI~
        else                                                       //~v55sI~
        if (xwork>='A' && xwork<='F')                              //~v55sI~
            funcno=xwork-'A'+10;                                   //~v55sI~
        else                                                       //~v55sI~
        if (xwork>='a' && xwork<='f')                              //~v55sI~
            funcno=xwork-'a'+10;                                   //~v55sI~
        else                                                       //~v55sI~
            break;                                                 //~v55sI~
        funcno<<=4;                                                //~v55sI~
        xwork=*(Snextpos+4);                                       //~v55sI~
        if (xwork>='0' && xwork<='9')                              //~v55sI~
            funcno+=xwork-'0';                                     //~v55sI~
        else                                                       //~v55sI~
        if (xwork>='A' && xwork<='F')                              //~v55sI~
            funcno+=xwork-'A'+10;                                  //~v55sI~
        else                                                       //~v55sI~
        if (xwork>='a' && xwork<='f')                              //~v55sI~
            funcno+=xwork-'a'+10;                                  //~v55sI~
        else                                                       //~v55sI~
            break;                                                 //~v55sI~
        scancode=funcno;                                           //~v55sI~
//charcode                                                         //~v55sI~
        xwork=*(Snextpos+5);                                       //~v55sI~
        if (xwork>='0' && xwork<='9')                              //~v55sI~
            funcno=xwork-'0';                                      //~v55sI~
        else                                                       //~v55sI~
        if (xwork>='A' && xwork<='F')                              //~v55sI~
            funcno=xwork-'A'+10;                                   //~v55sI~
        else                                                       //~v55sI~
        if (xwork>='a' && xwork<='f')                              //~v55sI~
            funcno=xwork-'a'+10;                                   //~v55sI~
        else                                                       //~v55sI~
            break;                                                 //~v55sI~
        funcno<<=4;                                                //~v55sI~
        xwork=*(Snextpos+6);                                       //~v55sI~
        if (xwork>='0' && xwork<='9')                              //~v55sI~
            funcno+=xwork-'0';                                     //~v55sI~
        else                                                       //~v55sI~
        if (xwork>='A' && xwork<='F')                              //~v55sI~
            funcno+=xwork-'A'+10;                                  //~v55sI~
        else                                                       //~v55sI~
        if (xwork>='a' && xwork<='f')                              //~v55sI~
            funcno+=xwork-'a'+10;                                  //~v55sI~
        else                                                       //~v55sI~
            break;                                                 //~v55sI~
        charcode=funcno;                                           //~v55sI~
        modx=*(Snextpos+7)-'0';                                    //~v55sI~
        if (modx<0||modx>=4)    //1:shift,2:control,3:alt          //~v55sI~
            break;                                                 //~v55sI~
        Sreslen-=USERSTRLEN2;                                      //~v55sI~
        Snextpos+=USERSTRLEN2;                                     //~v55sI~
      }                                                            //~v55sI~
      else                                                         //~v55sI~
      if (Sreslen>=USERSTRLEN3                                     //~v584R~
      &&  (*(Snextpos+6)>='0' && *(Snextpos+6)<='4')) //linux 1b~xxyyz  fmt//~v584R~
      {                                                            //~v584I~
//scancode                                                         //~v584I~
        xwork=*(Snextpos+2);                                       //~v584I~
        if (xwork>='0' && xwork<='9')                              //~v584I~
            funcno=xwork-'0';                                      //~v584I~
        else                                                       //~v584I~
        if (xwork>='A' && xwork<='F')                              //~v584I~
            funcno=xwork-'A'+10;                                   //~v584I~
        else                                                       //~v584I~
        if (xwork>='a' && xwork<='f')                              //~v584I~
            funcno=xwork-'a'+10;                                   //~v584I~
        else                                                       //~v584I~
            break;                                                 //~v584I~
        funcno<<=4;                                                //~v584I~
        xwork=*(Snextpos+3);                                       //~v584I~
        if (xwork>='0' && xwork<='9')                              //~v584I~
            funcno+=xwork-'0';                                     //~v584I~
        else                                                       //~v584I~
        if (xwork>='A' && xwork<='F')                              //~v584I~
            funcno+=xwork-'A'+10;                                  //~v584I~
        else                                                       //~v584I~
        if (xwork>='a' && xwork<='f')                              //~v584I~
            funcno+=xwork-'a'+10;                                  //~v584I~
        else                                                       //~v584I~
            break;                                                 //~v584I~
        scancode=funcno;                                           //~v584I~
//charcode                                                         //~v584I~
        xwork=*(Snextpos+4);                                       //~v584I~
        if (xwork>='0' && xwork<='9')                              //~v584I~
            funcno=xwork-'0';                                      //~v584I~
        else                                                       //~v584I~
        if (xwork>='A' && xwork<='F')                              //~v584I~
            funcno=xwork-'A'+10;                                   //~v584I~
        else                                                       //~v584I~
        if (xwork>='a' && xwork<='f')                              //~v584I~
            funcno=xwork-'a'+10;                                   //~v584I~
        else                                                       //~v584I~
            break;                                                 //~v584I~
        funcno<<=4;                                                //~v584I~
        xwork=*(Snextpos+5);                                       //~v584I~
        if (xwork>='0' && xwork<='9')                              //~v584I~
            funcno+=xwork-'0';                                     //~v584I~
        else                                                       //~v584I~
        if (xwork>='A' && xwork<='F')                              //~v584I~
            funcno+=xwork-'A'+10;                                  //~v584I~
        else                                                       //~v584I~
        if (xwork>='a' && xwork<='f')                              //~v584I~
            funcno+=xwork-'a'+10;                                  //~v584I~
        else                                                       //~v584I~
            break;                                                 //~v584I~
        charcode=funcno;                                           //~v584I~
        modx=*(Snextpos+6)-'0';                                    //~v584I~
        Sreslen-=USERSTRLEN3;                                      //~v584I~
        Snextpos+=USERSTRLEN3;                                     //~v584I~
      }                                                            //~v584I~
      else                                                         //~v584I~
      {                                                            //~v55sI~
        scancode=*(Snextpos+2);                                    //~v40gR~
        charcode=*(Snextpos+3);                                    //~v40gI~
        modx=*(Snextpos+4);                                        //~v503I~
        if (modx & MODX_EXTKEY)                                    //~v55pI~
        {                                                          //~v55pI~
        	modx-=MODX_EXTKEY;                                     //~v55pI~
            charcode--;                                            //~v55pI~
        }                                                          //~v55pI~
        if (modx>3)                                                //~v503I~
        	break;                                                 //~v503I~
//        if (charcode)                                            //~v503R~
//        {                                                        //~v503R~
//            modx=charcode;            //ahift only for char code //~v503R~
//            if (modx>3)                                          //~v503R~
//                break;                                           //~v503R~
//            pfkt=Suserkeytbl[256+scancode].UKTpfkt;              //~v503R~
//            if (!pfkt)                                           //~v503R~
//                break;                                           //~v503R~
//            charcode=pfkt->FKTdoskey[modx] & 255;                //~v503R~
//        }                                                        //~v503R~
//        else    //extended key                                   //~v503R~
//        {                                                        //~v503R~
//            modx=Suserkeytbl[scancode].UKTmodx;                  //~v503R~
//            pfkt=Suserkeytbl[scancode].UKTpfkt;                  //~v503R~
//            if (!pfkt)      //tera-term setup err(undefined scancode)//~v503R~
//                break;      //return a byte                      //~v503R~
//        }                                                        //~v503R~
        Sreslen-=USERSTRLEN;                                       //~v503R~
        Snextpos+=USERSTRLEN;                                      //~v503R~
      }//hex notation or binary notation                           //~v55sI~
        *Pmodifier=modx;
//output char+scan for ext key                                     //~0B18I~
        *Pout=(unsigned char)charcode;                             //~0B20R~
        *(Pout+1)=(unsigned char)scancode;                         //~0B20R~
//printf("exit1 reslen=%d\n",Sreslen);
        return 1;           //data exist                           //~v40gR~
    }
    Sreslen--;
//printf("exit2 reslen=%d\n",Sreslen);
    *Pout=*Snextpos++;
    return 1;                                                      //~v324R~
}//ukbdaixt_readkbd                                                //~v40gR~
//*********************************************************************
//* process option bit
//*********************************************************************
void ukbdaixt_optproc(int Popt,unsigned char *Passignkey)          //~0B11R~
{                            
    int ii,jj;                                                     //~v57XI~
    unsigned char *pakt;                                           //~v57XI~
//**********************************
//*pfk assign chk                                                  //~v384R~
//    for (ii=0,pakt=Passignkey;ii<MAXPFKNO;ii++)                  //~v40gR~
//        for (jj=0;jj<4;jj++,pakt++)                              //~v40gR~
//            if (!*pakt) //no xe assigned                         //~v40gR~
//                Spfktbl[ii]->FKTfkassign[jj]=0;  //bypass key-set,str-set//~v40gR~
    for (ii=0,pakt=Passignkey;ii<MAXPFKNO;ii++)                    //~v57XI~
        for (jj=0;jj<4;jj++,pakt++)                                //~v57XI~
            if (!*pakt) //no xe assigned                           //~v57XI~
                Spfktbl[ii]->FKTfkassign[jj]=0;  //bypass key-set,str-set//~v57XI~
    	                                                           //~v384I~
	ukbdaixt_delopt(Popt);	//chk 7f usage option                  //~v584I~
    return;                                                        //~v324I~
}//ukblnxc_optproc
//*********************************************************************//~v584I~
//* chk 7f is bs or del by cmd parm                                //~v584I~
//* rc:0:no option,1:char 7f,2:BS,3:DEL                            //~v584I~
//*********************************************************************//~v584I~
int  ukbdaixt_delopt(int Popt)                                     //~v584I~
{                                                                  //~v584I~
    char rc;                                                       //~v584I~
//************************                                         //~v584I~
  	if (Popt & UKBDL_7fBS)                                         //~v589R~
    {                                                              //~v584I~
    	rc=2;                                                      //~v584I~
		Sbs_del_sw=1; //BS by Del(0x7f)                            //~v584I~
        Sfkt_BS.FKTkeycode=CH_DELETE;                              //~v584I~
		Sfkt_BS.FKTfkassign[MODX_ALT]=CH_DELETE_ALT;//receive alt+DEL//~v584R~
		Saltchartbl[CH_DELETE]=Saltchartbl[CH_BACKSP];	//translate to alt+BS//~v584I~
    }                                                              //~v584I~
    else                                                           //~v584I~
  	if (Popt & UKBDL_7fDEL)                                        //~v589R~
    {                                                              //~v584I~
    	rc=3;                                                      //~v584I~
		Sdel_by_7f=1; //treate 7f as Del key                       //~v584I~
        Sfkt_REMOVE.FKTkeycode=CH_DELETE;                          //~v584I~
    }                                                              //~v584I~
    else                                                           //~v584I~
  	if (Popt & UKBDL_7fCHAR)                                       //~v589R~
    	rc=1;                                                      //~v584I~
    else                                                           //~v584I~
        rc=0;                                                      //~v584I~
    return rc;                                                     //~v584I~
}//ukbdaixt_delopt                                                 //~v584I~
//*********************************************************************
//* restore kbd status
//*********************************************************************
void ukbdaixt_cleanup(int Prestoresw)                              //~0B11R~
{
    ukbdl_setkbmode(1);      //restore cannonical mode             //~v40gR~
}//ukblnxc_cleanup
//*********************************************************************
//* signal handler
//*********************************************************************
void ukbdaixt_termexit(int Psigid)                                 //~0B11R~
{
    printf("ukbdaixt.c:Detected Signal %d\n",Psigid);              //~0B11R~
    ukbdaixt_cleanup(1);                                           //~0B11R~
}//ukbdaixt_termexit                                               //~0B11R~
//*********************************************************************//~0B11I~
//* assign userkey no and setup ptr tbl indexed by user key no     //~0B11I~
//*********************************************************************//~0B11I~
int ukbdaixt_setupuserkey(PFUNCKEYTBL **Pppfkt,int Popt)           //~0B23R~
{                                                                  //~0B11I~
    int ii,jj,userkeyno=0,ovfsw=0,scancode,charcode,doskey;        //~v536R~
    PFUNCKEYTBL pfkt;                                              //~0B23R~
//************************                                         //~0B11I~
	ukbdaixt_setupckt();//                                         //~v40gR~
//assign Fxx to modifier                                           //~0B11I~
//printf("PFKTNO=%d\n",PFKTNO);                                    //~0B11I~
    for (ii=0;ii<PFKTNO;ii++)        //keycode                     //~0B11I~
    {                                                              //~0B11I~
        pfkt=Spfktbl[ii];                                          //~0B11I~
        for (jj=0;jj<FKT_MAX_SYM;jj++)                             //~0B11I~
        {                                                          //~0B11I~
//printf("jj=%d,sym=%04x,keycode=%d\n",jj,assignsw,keycode);       //~v40gM~
//          if (pfkt->FKTfkassign[jj]!=FKT_TTUSERKEY)//not assigned or use terminfo str//~v584R~
//          if (!pfkt->FKTfkassign[jj])//no use                    //~v58bR~
            if (pfkt->FKTfkassign[jj]!=FKT_TTUSERKEY)//not assigned or use terminfo str//~v58bI~
                continue;                                          //~0B11I~
            if (userkeyno>=MAX_USERKEY)                            //~v40gR~
            {                                                      //~v40gI~
                if (!ovfsw)                                        //~v40gI~
                {                                                  //~v40gI~
                    ovfsw=1;                                       //~v40gI~
                    uerrmsg("========Overflow (Max is %d) ========\n",0,//~v40gR~
								MAX_USERKEY);                      //~v40gI~
                }                                                  //~v40gI~
            }                                                      //~v40gI~
            userkeyno++;                                           //~v40gM~
//setup userkey table indexed by scancode                          //~v40gI~
			doskey=pfkt->FKTdoskey[jj];                            //~v40gI~
			scancode=((unsigned)doskey>>8);                        //~0B20R~
			charcode=(doskey&255);                                 //~v40gI~
//            if (charcode)                                        //~v503R~
//            {                                                    //~v503R~
//                startpos=256;   //first half for ext key         //~v503R~
//                sprintf(pfkt->FKTuserstring,"\x1b~%02X%02X",scancode,jj);//~v503R~
//            }                                                    //~v503R~
//            else                                                 //~v503R~
//            {                                                    //~v503R~
//                startpos=0;     //later half for char key        //~v503R~
//                sprintf(pfkt->FKTuserstring,"\x1b~%02X%02X",scancode,0);//~v503R~
//            }                                                    //~v503R~
            sprintf(pfkt->FKTuserstring[jj],"\x1b~%02X%02X%d",scancode,charcode,jj);//~v504R~
//          printf("%d=%s=%s\n",userkeyno,pfkt->FKTkeyname,pfkt->FKTuserstring[jj]);//~v58bR~
//            if (Suserkeytbl[startpos+scancode].UKTpfkt)          //~v503R~
//            {                                                    //~v503R~
//                pshift=Suserkeytbl[startpos+scancode].UKTmodx;   //~v503R~
//                if (Popt)   //dupchk req                         //~v503R~
//                    uerrmsg("prev=%s(%04x-%d),curr=%s(%04x-%d)",0,//~v503R~
//                            Suserkeytbl[startpos+scancode].UKTpfkt->FKTkeyname,//~v503R~
//                            Suserkeytbl[startpos+scancode].UKTpfkt->FKTdoskey[pshift],//~v503R~
//                            pshift,                              //~v503R~
//                            pfkt->FKTkeyname,doskey,jj);         //~v503R~
//            }                                                    //~v503R~
//            else                                                 //~v503R~
//            {                                                    //~v503R~
//                Suserkeytbl[startpos+scancode].UKTpfkt=pfkt;     //~v503R~
//                Suserkeytbl[startpos+scancode].UKTmodx=jj;       //~v503R~
//            }                                                    //~v503R~
        }//jj                                                      //~0B11I~
    }                                                              //~0B11I~
//printf("return setfunckey\n");                                   //~0B11I~
	if (Pppfkt)             	//output required                  //~0B18R~
    	*Pppfkt=&Spfktbl[0];                                       //~0B18R~
	return PFKTNO;                                                 //~0B18R~
}//ukbdaixt_setupuserkey                                           //~v40gR~
//*********************************************************************//~v40gI~
//* setup teraterm key table                                       //~0B22R~
//*   setup teraterm string table                                  //~0B22R~
//* .for common key operation with other application               //~0B23R~
//*  and reduce userkey definition.(teraterm max is 99.            //~0B23I~
//*teraterm string    ttuse:teraterm intercept                     //~0B23M~
//*  key       normal    shift     ctrl      alt                   //~0B23M~
//                                                                 //~0B23M~
//   f1        ^[[11~    ______    ______    ______                //~0B23M~
//   f2        ^[[12~    ______    ______    ______                //~0B23M~
//   f3        ^[[13~    ^[[25~    ______    ______                //~0B23M~
//   f4        ^[[14~    ^[[26~    ______    ttuse                 //~0B23M~
//   f5        ^[[15~    ^[[28~    ______    ______                //~0B23M~
//   f6        ^[[17~    ^[[29~    ______    ______                //~0B23M~
//   f7        ^[[18~    ^[[31~    ______    ______                //~0B23M~
//   f8        ^[[19~    ^[[32~    ______    ______                //~0B23M~
//   f9        ^[[20~    ^[[33~    ______    ______                //~0B23M~
//   f10       ^[[21~    ^[[34~    ______    ______                //~0B23M~
//   f11       ^[[23~    ______    ______    ______                //~0B23M~
//   f12       ^[[24~    ______    ______    ______                //~0B23M~
                                                                   //~0B23M~
//   Ins       ^[[1~     ______    ______    ______                //~0B23M~
//   Home      ^[[2~     ttuse     ttuse     ______                //~0B23M~
//   Pgup      ^[[3~     ttuse     ttuse     ______                //~0B23M~
//   Del       ^[[4~     ______    ______    ______                //~0B23M~
//   End       ^[[5~     ______    ______    ______                //~0B23M~
//   Pgdn      ^[[6~     ttuse     ttuse     ______                //~0B23M~
                                                                   //~0B23I~
//   Up        ^[[A      ______    ttuse     ______                //~0B23I~
//   Down      ^[[B      ______    ttuse     ______                //~0B23I~
//   Right     ^[[C      ______    ______    ______                //~0B23I~
//   Left      ^[[D      ______    ______    ______                //~0B23I~
//*********************************************************************//~v40gI~
void ukbdaixt_setupckt(void)                                       //~0B18R~
{                                                                  //~v40gI~
//#define SETCKT(terminfostr,fktkey,modx,ttstring)		\
//		ukbdaixt_setupcktsub(&Sfkt_##fktkey,modx,ttstring,key_##terminfostr);//~v57XR~
#define SETCKT(terminfostr,fktkey,modx,ttstring)		\
		ukbdaixt_setupcktsub(FKT_TTORGKEY,&Sfkt_##fktkey,modx,ttstring,key_##terminfostr);//~v57XI~
//#define SETCKT3(terminfostr,fktkey,modx,ttstring)		\
//		ukbdaixt_setupcktsub(&Sfkt_##fktkey,modx,ttstring,      terminfostr);//~v57XR~
//#define SETCKT2(terminfostr,fktkey,modx,aixtistring)		\
//		ukbdaixt_setupcktsub2(&Sfkt_##fktkey,modx,aixtistring,key_##terminfostr);//~v57XR~
#define SETCKT2(terminfostr,fktkey,modx,aixtistring)        \
        ukbdaixt_setupcktsub(FKT_AIXORGKEY,&Sfkt_##fktkey,modx,aixtistring,key_##terminfostr);//~v57XI~
#define key_0  ""      //for the case no name defined              //~v555I~
    int teratermsw;                                                //~v584I~
//**********************************                               //~v40gI~
    ukbdaixt_setupcktx();                                          //~v57XI~
    SETCKT(up    ,UP    ,0,"\x1b[A")                               //~v504R~
    SETCKT(down  ,DOWN  ,0,"\x1b[B")                               //~v504R~
//  SETCKT(left  ,RIGHT ,0,"\x1b[C")                               //~v554R~
    SETCKT(left  ,LEFT  ,0,"\x1b[D")                               //~v554I~
//  SETCKT(right ,LEFT  ,0,"\x1b[D")                               //~v554R~
    SETCKT(right ,RIGHT ,0,"\x1b[C")                               //~v554I~
                                                                   //~0B23I~
// if (Stermid==TERM_VT100) 	//teraterm                         //~v584R~
 teratermsw=(Gkbdaixt_opt & GKBAIX_TTERM);     //teraterm          //~v584R~
 if (teratermsw)                                                   //~v584I~
 {                                                                 //~v57XI~
    SETCKT(ic    ,INSERT,0,"\x1b[1~")                              //~v504R~
  if (key_home)   //terminfo string defined                        //~v504I~
    SETCKT(home  ,FIND  ,0,"\x1b[2~")	//Home                     //~v504I~
  else                                                             //~v504I~
    SETCKT(find  ,FIND  ,0,"\x1b[2~")	//Home                     //~v504R~
//  SETCKT(npage ,PGUP  ,0,"\x1b[3~")                              //~v554R~
    SETCKT(ppage ,PGUP  ,0,"\x1b[3~")                              //~v554I~
    SETCKT(dc    ,REMOVE,0,"\x1b[4~")  //Del                       //~v504R~
  if (key_end)   //terminfo string defined                         //~v504I~
    SETCKT(end   ,SELECT,0,"\x1b[5~")  //End                       //~v504I~
  else                                                             //~v504I~
    SETCKT(select,SELECT,0,"\x1b[5~")  //End                       //~v504R~
//  SETCKT(ppage ,PGDN  ,0,"\x1b[6~")                              //~v554R~
    SETCKT(npage ,PGDN  ,0,"\x1b[6~")                              //~v554I~
 }                                                                 //~v57XI~
 else                                                              //~v57XI~
 {                                                                 //~v57XI~
    SETCKT2(ic    ,INSERT,0,"\x1b[2~")                             //~v57XI~
  if (key_home)   //terminfo string defined                        //~v57XI~
    SETCKT2(home  ,FIND  ,0,"\x1b[1~")	//Home                     //~v57XI~
  else                                                             //~v57XI~
    SETCKT2(find  ,FIND  ,0,"\x1b[1~")	//Home                     //~v57XI~
    SETCKT2(ppage ,PGUP  ,0,"\x1b[5~")                             //~v57XI~
    SETCKT2(dc    ,REMOVE,0,"\x1b[3~")  //Del                      //~v57XI~
  if (key_end)   //terminfo string defined                         //~v57XI~
    SETCKT2(end   ,SELECT,0,"\x1b[4~")  //End                      //~v57XI~
  else                                                             //~v57XI~
    SETCKT2(select,SELECT,0,"\x1b[4~")  //End                      //~v57XI~
    SETCKT2(npage ,PGDN  ,0,"\x1b[6~")                             //~v57XI~
 }                                                                 //~v57XI~
                                                                   //~0B23I~
    SETCKT(f1    ,F1    ,0,"\x1b[11~")                             //~v504R~
    SETCKT(f2    ,F2    ,0,"\x1b[12~")                             //~v504R~
    SETCKT(f3    ,F3    ,0,"\x1b[13~")                             //~v504R~
    SETCKT(f4    ,F4    ,0,"\x1b[14~")                             //~v504R~
    SETCKT(f5    ,F5    ,0,"\x1b[15~")                             //~v504R~
    SETCKT(f6    ,F6    ,0,"\x1b[17~")                             //~v504R~
    SETCKT(f7    ,F7    ,0,"\x1b[18~")                             //~v504R~
    SETCKT(f8    ,F8    ,0,"\x1b[19~")                             //~v504R~
    SETCKT(f9    ,F9    ,0,"\x1b[20~")                             //~v504R~
    SETCKT(f10   ,F10   ,0,"\x1b[21~")                             //~v504R~
    SETCKT(f11   ,F11   ,0,"\x1b[23~")                             //~v504R~
    SETCKT(f12   ,F12   ,0,"\x1b[24~")                             //~v504R~
//if (!(Gkbdaixt_opt & GKBAIX_XAIXTERM))     //xterm on x          //~v584R~
  if (teratermsw)                                                  //~v584I~
  {                                                                //~v555I~
//Shift+F1,F2,F11,F12 issue no string                              //~0C11I~
    SETCKT(f13    ,F1    ,MODX_SHIFT,0         )                   //~v504I~
    SETCKT(f14    ,F2    ,MODX_SHIFT,0         )                   //~v504I~
                                                                   //~v504I~
    SETCKT(f15    ,F3    ,MODX_SHIFT,"\x1b[25~")                   //~v504R~
    SETCKT(f16    ,F4    ,MODX_SHIFT,"\x1b[26~")                   //~v504R~
    SETCKT(f17    ,F5    ,MODX_SHIFT,"\x1b[28~")                   //~v504R~
    SETCKT(f18    ,F6    ,MODX_SHIFT,"\x1b[29~")                   //~v504R~
    SETCKT(f19    ,F7    ,MODX_SHIFT,"\x1b[31~")                   //~v504R~
    SETCKT(f20    ,F8    ,MODX_SHIFT,"\x1b[32~")                   //~v504R~
    SETCKT(f21    ,F9    ,MODX_SHIFT,"\x1b[33~")                   //~v504R~
    SETCKT(f22    ,F10   ,MODX_SHIFT,"\x1b[34~")                   //~v504R~
                                                                   //~v504I~
    SETCKT(f23    ,F11   ,MODX_SHIFT,0         )                   //~v504I~
    SETCKT(f24    ,F12   ,MODX_SHIFT,0         )                   //~v504I~
  }                                                                //~v555I~
//  if (Gkbdaixt_opt & GKBAIX_XAIXTERM)     //xterm on x           //~v57XR~
//  {                                                              //~v57XR~
//    SETCKT2(0      ,REMOVE,MODX_SHIFT  ,"\x1b[P")                //~v57XR~
//    SETCKT2(0      ,REMOVE,MODX_ALT    ,"\x1b[M")                //~v57XR~
//    SETCKT2(0      ,TAB   ,MODX_SHIFT  ,"\x1b[Z")                //~v57XR~
	ukbdaixt_setupaixstd(); 	//ESC[xxxq fmt aix std             //~v555R~
//  }                                                              //~v57XR~
//  else                                                           //~v57XR~
//  {                                                              //~v57XR~
//    SETCKT(btab        ,TAB   ,MODX_SHIFT,"\x1b[Z")              //~v57XR~
//  }                                                              //~v57XR~
	ukbdaixt_setupcktlnx();                                        //~v57XI~
    return;                                                        //~v504R~
}//ukbdaixt_setupckt                                               //~0B18R~
//*********************************************************************//~v57XI~
//* setup curses key table for not duplicated                      //~v57XI~
//*********************************************************************//~v57XI~
void ukbdaixt_setupcktx(void)                                      //~v57XI~
{                                                                  //~v57XI~
#define SETCKTAIX(fktkey,modx,str)		\
	    ukbdaixt_addstrtbl(ADDSTT_DUPIGNORE,FKT_AIXORGKEY,str,&Sfkt_##fktkey,modx,strlen(str));//~v584R~
//**********************************                               //~v57XI~
//for aixterm                                                      //~v57XI~
    SETCKTAIX(TAB   ,MODX_SHIFT,"\x1b[Z")                          //~v57XI~
    SETCKTAIX(REMOVE,0         ,"\x1b[P")                          //~v57XI~
    SETCKTAIX(REMOVE,MODX_ALT  ,"\x1b[M")                          //~v57XI~
    SETCKTAIX(FIND  ,0         ,"\x1b[H")                          //~v57XI~
    return;                                                        //~v57XI~
}//ukbdaixt_setupcktx                                              //~v57XI~
//*********************************************************************//~v57XI~
//* setup curses key table of linux for the case telnet from linux to aix//~v57XI~
//*********************************************************************//~v57XI~
void ukbdaixt_setupcktlnx(void)                                    //~v57XI~
{                                                                  //~v57XI~
#define SETCKTX(string,fktkey,modx)        \
        ukbdaixt_addstrtbl(ADDSTT_DUPIGNORE,FKT_LINUX,string,&Sfkt_##fktkey,modx,strlen(string));//~v57XI~
//**********************************                               //~v57XI~
    #include <ukbdl2.h>                                            //~v58eI~
    return;                                                        //~v57XI~
}//ukbdlnxc_setupcktx                                              //~v57XI~
//*********************************************************************//~v555I~
//* aixterm std PFKnnn table setup                                 //~v555I~
//*********************************************************************//~v555I~
void ukbdaixt_setupaixstd(void)                                    //~v555I~
{                                                                  //~v555I~
#define SETCKTAIXSTD(fktkey,modx,pfkno)			\
        if (!Saixpfktbl[pfkno].APTpfkt)				\
        {                                       \
        	Saixpfktbl[pfkno].APTpfkt=&Sfkt_##fktkey; \
        	Saixpfktbl[pfkno].APTmodx=modx;           \
        	Sfkt_##fktkey.FKTaixfunckeyno[modx]=pfkno;\
        }                                                          //~v555I~
#define SETCKTAIX_CH(scan_char,modx,pfkno)			\
        if (!Saixpfktbl[pfkno].APTpfkt)				\
        {                                       \
        	Saixpfktbl[pfkno].APTpfkt=(PFUNCKEYTBL)(-1); \
        	Saixpfktbl[pfkno].APTmodx=modx;           \
        	Saixpfktbl[pfkno].APTscan_char=scan_char;      \
        }                                                          //~v55tI~
//**********************************                               //~v555I~
//1,2,3,4,5,6,7,8,9,0                                              //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,       49  )   //1         //~v55tI~
    SETCKTAIX_CH(0x7800   ,MODX_ALT    ,       58  )   //1         //~v55tI~
                                                       //C+2:0300  //~v55tI~
    SETCKTAIX_CH(0x7900   ,MODX_ALT    ,       59  )   //2         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,       50  )   //3         //~v55tI~
    SETCKTAIX_CH(0x7a00   ,MODX_ALT    ,       60  )   //3         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,       51  )   //4         //~v55tI~
    SETCKTAIX_CH(0x7b00   ,MODX_ALT    ,       61  )   //4         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,       52  )   //5         //~v55tI~
    SETCKTAIX_CH(0x7c00   ,MODX_ALT    ,       62  )   //5         //~v55tI~
                                                       //C+6:071e  //~v55tI~
    SETCKTAIX_CH(0x7d00   ,MODX_ALT    ,       63  )   //6         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,       53  )   //7         //~v55tI~
    SETCKTAIX_CH(0x7e00   ,MODX_ALT    ,       64  )   //7         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,       54  )   //8         //~v55tI~
    SETCKTAIX_CH(0x7f00   ,MODX_ALT    ,       65  )   //8         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,       55  )   //9         //~v55tI~
    SETCKTAIX_CH(0x8000   ,MODX_ALT    ,       66  )   //9         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,       56  )   //0         //~v55tI~
    SETCKTAIX_CH(0x8100   ,MODX_ALT    ,       67  )   //0         //~v55tI~
//-,^,\
                                                       //C+-:0c1f  //~v55tI~
    SETCKTAIX_CH(0x8200   ,MODX_ALT    ,       68  )   //-         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,       69  )   //^         //~v55tI~
    SETCKTAIX_CH(0x8300   ,MODX_ALT    ,       70  )   //^         //~v55tI~
                                                       //C+\:7d1c  //~v55tI~
                                                       //A+\:7d00  //~v55tR~
//qwertyuiop@[                                                     //~v55tI~
    SETCKTAIX_CH(0x1000   ,MODX_ALT    ,       74  )   //q         //~v55tI~
    SETCKTAIX_CH(0x1100   ,MODX_ALT    ,       75  )   //w         //~v55tI~
    SETCKTAIX_CH(0x1200   ,MODX_ALT    ,       76  )   //e         //~v55tI~
    SETCKTAIX_CH(0x1300   ,MODX_ALT    ,       77  )   //r         //~v55tI~
    SETCKTAIX_CH(0x1400   ,MODX_ALT    ,       78  )   //t         //~v55tI~
    SETCKTAIX_CH(0x1500   ,MODX_ALT    ,       79  )   //y         //~v55tI~
    SETCKTAIX_CH(0x1600   ,MODX_ALT    ,       80  )   //u         //~v55tI~
    SETCKTAIX_CH(0x1700   ,MODX_ALT    ,       81  )   //i         //~v55tI~
    SETCKTAIX_CH(0x1800   ,MODX_ALT    ,       82  )   //o         //~v55tI~
    SETCKTAIX_CH(0x1900   ,MODX_ALT    ,       83  )   //p         //~v55tI~
    SETCKTAIX_CH(0x1a00   ,MODX_ALT    ,       84  )   //@         //~v55tI~
    SETCKTAIX_CH(0x1b00   ,MODX_ALT    ,       85  )   //[         //~v55tI~
//asdfghjkl;:]                                                     //~v55tI~
    SETCKTAIX_CH(0x1e00   ,MODX_ALT    ,       87  )   //a         //~v55tI~
    SETCKTAIX_CH(0x1f00   ,MODX_ALT    ,       88  )   //s         //~v55tI~
    SETCKTAIX_CH(0x2000   ,MODX_ALT    ,       89  )   //d         //~v55tI~
    SETCKTAIX_CH(0x2100   ,MODX_ALT    ,       90  )   //f         //~v55tI~
    SETCKTAIX_CH(0x2200   ,MODX_ALT    ,       91  )   //g         //~v55tI~
    SETCKTAIX_CH(0x2300   ,MODX_ALT    ,       92  )   //h         //~v55tI~
    SETCKTAIX_CH(0x2400   ,MODX_ALT    ,       93  )   //j         //~v55tI~
    SETCKTAIX_CH(0x2500   ,MODX_ALT    ,       94  )   //k         //~v55tI~
    SETCKTAIX_CH(0x2600   ,MODX_ALT    ,       95  )   //l         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,       96  )   //;         //~v55tI~
    SETCKTAIX_CH(0x2700   ,MODX_ALT    ,       97  )   //;         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,       98  )   //:         //~v55tI~
    SETCKTAIX_CH(0x2800   ,MODX_ALT    ,       99  )   //:         //~v55tI~
//  SETCKTAIX_CH(0x2b00   ,MODX_ALT    ,           )   //]         //~v55tI~
//zxcvbnm,./\  //                                                  //~v55tR~
    SETCKTAIX_CH(0x2c00   ,MODX_ALT    ,      101  )   //z         //~v55tI~
    SETCKTAIX_CH(0x2d00   ,MODX_ALT    ,      102  )   //x         //~v55tI~
    SETCKTAIX_CH(0x2e00   ,MODX_ALT    ,      103  )   //c         //~v55tI~
    SETCKTAIX_CH(0x2f00   ,MODX_ALT    ,      104  )   //v         //~v55tI~
    SETCKTAIX_CH(0x3000   ,MODX_ALT    ,      105  )   //b         //~v55tI~
    SETCKTAIX_CH(0x3100   ,MODX_ALT    ,      106  )   //n         //~v55tI~
    SETCKTAIX_CH(0x3200   ,MODX_ALT    ,      107  )   //m         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,      108  )   //,         //~v55tI~
    SETCKTAIX_CH(0x3300   ,MODX_ALT    ,      109  )   //,         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,      110  )   //.         //~v55tI~
    SETCKTAIX_CH(0x3400   ,MODX_ALT    ,      111  )   //.         //~v55tI~
//  SETCKTAIX_CH(-1       ,MODX_CONTROL,      112  )   ///         //~v55tI~
    SETCKTAIX_CH(0x3500   ,MODX_ALT    ,      113  )   ///         //~v55tI~
    SETCKTAIX_CH(0xb300   ,MODX_ALT    ,       86  )   //\
//Ins                                                              //~v555I~
    SETCKTAIXSTD(   INSERT,MODX_PLAIN  ,      139  )               //~v555I~
    SETCKTAIXSTD(   INSERT,MODX_SHIFT  ,      139  )               //~v555I~
    SETCKTAIXSTD(   INSERT,MODX_CONTROL,      140  )               //~v555I~
    SETCKTAIXSTD(   INSERT,MODX_ALT    ,      141  )               //~v555I~
//Del                                                              //~v555I~
    //                     MODX_PLAIN  ,"\x1b[P")                  //~v555I~
    //                     MODX_SHIFT  ,"\x1b[P")                  //~v555I~
    SETCKTAIXSTD(   REMOVE,MODX_CONTROL,      142  )               //~v555I~
    //                     MODX_ALT    ,"\x1b[M")                  //~v555I~
//Home                                                             //~v555I~
    //                     MODX_PLAIN  ,"\x1b[H")                  //~v555I~
    SETCKTAIXSTD(   FIND  ,MODX_SHIFT  ,      143  )               //~v555I~
    SETCKTAIXSTD(   FIND  ,MODX_CONTROL,      144  )               //~v555I~
    SETCKTAIXSTD(   FIND  ,MODX_ALT    ,      145  )               //~v555I~
//End                                                              //~v555I~
    SETCKTAIXSTD(   SELECT,MODX_PLAIN  ,      146  )               //~v555I~
    SETCKTAIXSTD(   SELECT,MODX_SHIFT  ,      147  )               //~v555I~
    SETCKTAIXSTD(   SELECT,MODX_CONTROL,      148  )               //~v555I~
    SETCKTAIXSTD(   SELECT,MODX_ALT    ,      149  )               //~v555I~
//PgUp                                                             //~v555I~
    SETCKTAIXSTD(   PGUP  ,MODX_PLAIN  ,      150  )               //~v555I~
    SETCKTAIXSTD(   PGUP  ,MODX_SHIFT  ,      151  )               //~v555I~
    SETCKTAIXSTD(   PGUP  ,MODX_CONTROL,      152  )               //~v555I~
    SETCKTAIXSTD(   PGUP  ,MODX_ALT    ,      153  )               //~v555I~
//PgDn                                                             //~v555I~
    SETCKTAIXSTD(   PGDN  ,MODX_PLAIN  ,      154  )               //~v555I~
    SETCKTAIXSTD(   PGDN  ,MODX_SHIFT  ,      155  )               //~v555I~
    SETCKTAIXSTD(   PGDN  ,MODX_CONTROL,      156  )               //~v555I~
    SETCKTAIXSTD(   PGDN  ,MODX_ALT    ,      157  )               //~v555I~
//Left                                                             //~v555I~
    //                     MODX_PLAIN  ,"\x1b[D")                  //~v555I~
    SETCKTAIXSTD(   LEFT  ,MODX_SHIFT  ,      158  )               //~v555I~
    SETCKTAIXSTD(   LEFT  ,MODX_CONTROL,      159  )               //~v555I~
    SETCKTAIXSTD(   LEFT  ,MODX_ALT    ,      160  )               //~v555I~
//Up                                                               //~v555I~
    //                     MODX_PLAIN  ,"\x1b[A")                  //~v555I~
    SETCKTAIXSTD(   UP    ,MODX_SHIFT  ,      161  )               //~v555I~
    SETCKTAIXSTD(   UP    ,MODX_CONTROL,      162  )               //~v555I~
    SETCKTAIXSTD(   UP    ,MODX_ALT    ,      163  )               //~v555I~
//Down                                                             //~v555I~
    //                     MODX_PLAIN  ,"\x1b[B")                  //~v555I~
    SETCKTAIXSTD(   DOWN  ,MODX_SHIFT  ,      164  )               //~v555I~
    SETCKTAIXSTD(   DOWN  ,MODX_CONTROL,      165  )               //~v555I~
    SETCKTAIXSTD(   DOWN  ,MODX_ALT    ,      166  )               //~v555I~
//Right                                                            //~v555I~
    SETCKT2(sright ,RIGHT ,MODX_SHIFT  ,"\x1b[C")                  //~v555I~
    SETCKTAIXSTD(   RIGHT ,MODX_SHIFT  ,      167  )               //~v555I~
    SETCKTAIXSTD(   RIGHT ,MODX_CONTROL,      168  )               //~v555I~
    SETCKTAIXSTD(   RIGHT ,MODX_ALT    ,      169  )               //~v555I~
//BackSpace                                                        //~v555I~
//                         MODX_PLAIN  ,"\x08")                    //~v555I~
//                         MODX_SHIFT  ,"\x08")                    //~v555I~
//                         MODX_CONTROL,"\x7f")                    //~v555I~
    SETCKTAIXSTD(   BS    ,MODX_ALT    ,       71  )               //~v555R~
//Esc                                                              //~v555I~
//                         MODX_PLAIN  ,"\x01")                    //~v555I~
    SETCKTAIXSTD(   ESCAPE,MODX_SHIFT  ,      120  )               //~v55tR~
    SETCKTAIXSTD(   ESCAPE,MODX_CONTROL,      121  )               //~v55tI~
    SETCKTAIXSTD(   ESCAPE,MODX_ALT    ,      122  )               //~v55tR~
//Tab                                                              //~v555I~
//                         MODX_PLAIN  ,"\x09")                    //~v555I~
//                         MODX_SHIFT  ,"\x1b[Z")                  //~v555I~
    SETCKTAIXSTD(   TAB   ,MODX_CONTROL,       72  )               //~v555R~
    SETCKTAIXSTD(   TAB   ,MODX_ALT    ,       73  )               //~v555R~
//Enter                                                            //~v555I~
//                         MODX_PLAIN  ,"\x0d")                    //~v555I~
//                         MODX_SHIFT  ,"\x0d")                    //~v555I~
//                         MODX_CONTROL,"0x0d")                    //~v555I~
    SETCKTAIXSTD(   ENTER ,MODX_ALT    ,      100  )               //~v555I~
//Penter                                                           //~v555I~
//                         MODX_PLAIN  ,"\x0d")                    //~v555I~
//                         MODX_SHIFT  ,"\x0d")                    //~v555I~
//                         MODX_CONTROL,"0x0d")                    //~v555I~
    SETCKTAIXSTD(  NENTER ,MODX_ALT    ,      100  )               //~v55tR~
//plain                                                            //~v555I~
    SETCKTAIXSTD(   F1    ,MODX_PLAIN  ,        1  )               //~v555R~
    SETCKTAIXSTD(   F2    ,MODX_PLAIN  ,        2  )               //~v555R~
    SETCKTAIXSTD(   F3    ,MODX_PLAIN  ,        3  )               //~v555R~
    SETCKTAIXSTD(   F4    ,MODX_PLAIN  ,        4  )               //~v555R~
    SETCKTAIXSTD(   F5    ,MODX_PLAIN  ,        5  )               //~v555R~
    SETCKTAIXSTD(   F6    ,MODX_PLAIN  ,        6  )               //~v555R~
    SETCKTAIXSTD(   F7    ,MODX_PLAIN  ,        7  )               //~v555R~
    SETCKTAIXSTD(   F8    ,MODX_PLAIN  ,        8  )               //~v555R~
    SETCKTAIXSTD(   F9    ,MODX_PLAIN  ,        9  )               //~v555R~
    SETCKTAIXSTD(   F10   ,MODX_PLAIN  ,       10  )               //~v555R~
    SETCKTAIXSTD(   F11   ,MODX_PLAIN  ,       11  )               //~v555R~
    SETCKTAIXSTD(   F12   ,MODX_PLAIN  ,       12  )               //~v555R~
//shift                                                            //~v555I~
    SETCKTAIXSTD(   F1    ,MODX_SHIFT  ,       13  )               //~v555R~
    SETCKTAIXSTD(   F2    ,MODX_SHIFT  ,       14  )               //~v555R~
    SETCKTAIXSTD(   F3    ,MODX_SHIFT  ,       15  )               //~v555R~
    SETCKTAIXSTD(   F4    ,MODX_SHIFT  ,       16  )               //~v555R~
    SETCKTAIXSTD(   F5    ,MODX_SHIFT  ,       17  )               //~v555R~
    SETCKTAIXSTD(   F6    ,MODX_SHIFT  ,       18  )               //~v555R~
    SETCKTAIXSTD(   F7    ,MODX_SHIFT  ,       19  )               //~v555R~
    SETCKTAIXSTD(   F8    ,MODX_SHIFT  ,       20  )               //~v555R~
    SETCKTAIXSTD(   F9    ,MODX_SHIFT  ,       21  )               //~v555R~
    SETCKTAIXSTD(   F10   ,MODX_SHIFT  ,       22  )               //~v555R~
    SETCKTAIXSTD(   F11   ,MODX_SHIFT  ,       23  )               //~v555R~
    SETCKTAIXSTD(   F12   ,MODX_SHIFT  ,       24  )               //~v555R~
//ctl                                                              //~v555I~
    SETCKTAIXSTD(   F1    ,MODX_CONTROL,       25  )               //~v555R~
    SETCKTAIXSTD(   F2    ,MODX_CONTROL,       26  )               //~v555R~
    SETCKTAIXSTD(   F3    ,MODX_CONTROL,       27  )               //~v555R~
    SETCKTAIXSTD(   F4    ,MODX_CONTROL,       28  )               //~v555R~
    SETCKTAIXSTD(   F5    ,MODX_CONTROL,       29  )               //~v555R~
    SETCKTAIXSTD(   F6    ,MODX_CONTROL,       30  )               //~v555R~
    SETCKTAIXSTD(   F7    ,MODX_CONTROL,       31  )               //~v555R~
    SETCKTAIXSTD(   F8    ,MODX_CONTROL,       32  )               //~v555R~
    SETCKTAIXSTD(   F9    ,MODX_CONTROL,       33  )               //~v555R~
    SETCKTAIXSTD(   F10   ,MODX_CONTROL,       34  )               //~v555R~
    SETCKTAIXSTD(   F11   ,MODX_CONTROL,       35  )               //~v555R~
    SETCKTAIXSTD(   F12   ,MODX_CONTROL,       36  )               //~v555R~
//alt                                                              //~v555I~
    SETCKTAIXSTD(   F1    ,MODX_ALT    ,       37  )               //~v555R~
    SETCKTAIXSTD(   F2    ,MODX_ALT    ,       38  )               //~v555R~
    SETCKTAIXSTD(   F3    ,MODX_ALT    ,       39  )               //~v555R~
    SETCKTAIXSTD(   F4    ,MODX_ALT    ,       40  )               //~v555R~
    SETCKTAIXSTD(   F5    ,MODX_ALT    ,       41  )               //~v555R~
    SETCKTAIXSTD(   F6    ,MODX_ALT    ,       42  )               //~v555R~
    SETCKTAIXSTD(   F7    ,MODX_ALT    ,       43  )               //~v555R~
    SETCKTAIXSTD(   F8    ,MODX_ALT    ,       44  )               //~v555R~
    SETCKTAIXSTD(   F9    ,MODX_ALT    ,       45  )               //~v555R~
    SETCKTAIXSTD(   F10   ,MODX_ALT    ,       46  )               //~v555R~
    SETCKTAIXSTD(   F11   ,MODX_ALT    ,       47  )               //~v555R~
    SETCKTAIXSTD(   F12   ,MODX_ALT    ,       48  )               //~v555R~
  	return;                                                        //~v555I~
}//ukbdaixt_setupaixstd                                            //~v555I~
//*******************************************************************//~v40uI~
//int ukbdaixt_setupcktsub2(PFUNCKEYTBL Ppfkt,int Pmodx,char *Paixstring,char *Ptistr)//~v57XR~
//{                                                                //~v57XR~
//    int rc;                                                      //~v57XR~
////**********************                                         //~v57XR~
//    Saixstring=Paixstring;                                       //~v57XR~
//    rc=ukbdaixt_setupcktsub(Ppfkt,Pmodx,0,Ptistr);//no teraterm string//~v57XR~
//    Saixstring=0;                                                //~v57XR~
//    return rc;                                                   //~v57XR~
//}//ukbdaixt_setupcktsub2                                         //~v57XR~
                                                                   //~v555I~
//*******************************************************************//~v555I~
//int ukbdaixt_setupcktsub(PFUNCKEYTBL Ppfkt,int Pmodx,char *Pstring,char *Ptistr)//~v57XR~
int ukbdaixt_setupcktsub(int Pflag,PFUNCKEYTBL Ppfkt,int Pmodx,char *Pstring,char *Ptistr)//~v57XI~
{                                                                  //~v555I~
	char *str;                                                     //~v555I~
//***************************                                      //~v40uI~
//    if (!Ppfkt->FKTttstring[Pmodx])                              //~v57XR~
//    {                                                            //~v57XR~
//        Ppfkt->FKTfkassign[Pmodx]=FKT_TTORGKEY;                  //~v57XR~
//        Ppfkt->FKTttstring[Pmodx]=Pstring;                       //~v57XR~
//    }                                                            //~v57XR~
    Ppfkt->FKTtistring[Pmodx]=Ptistr;                              //~v504I~
  if (!(Gkbdaixt_opt & GKBAIX_XXTERM))     //xterm on x            //~v504I~
//  str=Ppfkt->FKTttstring[Pmodx];                                 //~v57XR~
    str=Pstring;                                                   //~v57XI~
  else                                                             //~v504I~
   if (Ptistr && *Ptistr)     //terminfo defined                   //~v555R~
    str=Ptistr;                                                    //~v504I~
// else            //use hardcoded under X(for aixterm)            //~v57XR~
//  str=Saixstring;   //parm from sub2                             //~v57XR~
  if (str && *str)                                                 //~v504I~
  {                                                                //~v504I~
//    if (Scktno>=CKTNO)                                           //~v57XR~
//        uerrexit("CKT overflow",0);                              //~v57XR~
//    Scurseskeytbl[Scktno].CKTpfkt=Ppfkt;                         //~v57XR~
//    Scurseskeytbl[Scktno].CKTmodx=Pmodx;                         //~v57XR~
//    Scurseskeytbl[Scktno].CKTstring=str;                         //~v57XR~
//    Scurseskeytbl[Scktno].CKTlen=(int)strlen(str);               //~v57XR~
//    Scurseskeytbl[Scktno].CKTstring=str;                         //~v57XR~
//    Scktno++;                                                    //~v57XR~
	ukbdaixt_addstrtbl(ADDSTT_DUPIGNORE,Pflag,str,Ppfkt,Pmodx,strlen(str));//~v584R~
//printf("%d=%s\n",Pmodx,str);                                     //~v555R~
  }                                                                //~v504I~
    return 0;                                                      //~v40uI~
}//ukbdaixt_setupcktsub                                            //~v40uI~
//*********************************************************************//~v57XI~
//* setup curses key table sub                                     //~v57XI~
//*********************************************************************//~v57XI~
void ukbdaixt_addstrtbl(int Popt,int Pflag,char *Pstring,FUNCKEYTBL *Ppfkt,int Pmodx,int Plen)//~v57XI~
{                                                                  //~v57XI~
    int ii,dupchksw;                                               //~v57XI~
    char editwk[32];                                               //~v57XI~
//*********************************                                //~v57XI~
    dupchksw=(Popt & (ADDSTT_DUPIGNORE|ADDSTT_DUPRESET));          //~v57XI~
    if (dupchksw)                                                  //~v57XI~
    {                                                              //~v57XI~
		if (ukbdaixt_dupstrchk(dupchksw,Pstring,Ppfkt,Pmodx,Plen)>1)//~v57XI~
        	return;                                                //~v57XI~
    }                                                              //~v57XI~
    for (ii=0;ii<FKT_MAX_STR;ii++)                                 //~v57XI~
    {                                                              //~v57XI~
   		if (!Ppfkt->FKTttstring[Pmodx][ii])                        //~v57XI~
            break;                                                 //~v57XI~
    }                                                              //~v57XI~
    if (ii==FKT_MAX_STR)                                           //~v57XI~
    {                                                              //~v57XI~
        ukbdl_editstring(Pstring,editwk);                          //~v57XI~
        fprintf(stderr, "add:string assignment overflow(max is %d) for %s%s,%s ignored\n",//~v57XI~
            	FKT_MAX_STR,Sshiftidstr[Pmodx],Ppfkt->FKTkeyname,editwk);//~v57XI~
	    return;                                                    //~v57XI~
    }                                                              //~v57XI~
//  if (Popt & ADDSTT_CLEARASSIGN)                                 //~v57XI~
//  	Ppfkt->FKTfkassign[Pmodx]=0; //drop keysym change          //~v57XI~
    Ppfkt->FKTttstring[Pmodx][ii]=Pstring;                         //~v57XI~
    Ppfkt->FKTflag[Pmodx][ii]=Pflag;                               //~v57XI~
    if (Pflag==FKT_TTORGKEY)                                       //~v58bI~
	    Ppfkt->FKTfkassign[Pmodx]=FKT_TTORGASSIGNED;               //~v58bI~
    Scurseskeytbl[Scktno].CKTpfkt=Ppfkt;                           //~v57XI~
    Scurseskeytbl[Scktno].CKTmodx=Pmodx;                           //~v57XI~
    Scurseskeytbl[Scktno].CKTstring=Pstring;                       //~v57XI~
    Scurseskeytbl[Scktno].CKTlen=Plen;                             //~v57XI~
//UTRACEP("addstring mod=%d,name=%s,str=%s\n",Pmodx,Ppfkt->FKTkeyname,Pstring);//~v57XI~
    Scktno++;                                                      //~v57XI~
    return;                                                        //~v57XI~
}//ukbdaixt_addstrtbl                                              //~v57XI~
//*********************************************************************//~v57XI~
//* setup curses key table sub                                     //~v57XI~
//*********************************************************************//~v57XI~
int ukbdaixt_dupstrchk(int Popt,char *Pstring,FUNCKEYTBL *Ppfkt,int Pmodx,int Plen)//~v57XI~
{                                                                  //~v57XI~
	char **ppstr;                                                  //~v57XI~
    int len,modx,ii;                                               //~v57XI~
    PCURSESKEYTBL pckt,pckte;                                      //~v57XI~
    PFUNCKEYTBL pfkt;                                              //~v57XI~
    char editwk[32];                                               //~v57XI~
//*********************************                                //~v57XI~
    for (pckt=Scurseskeytbl,pckte=Scurseskeytbl+Scktno;pckt<pckte;pckt++)//~v57XI~
    {                                                              //~v57XI~
        len=pckt->CKTlen;                                          //~v57XI~
        if (len==Plen && !memcmp(Pstring,pckt->CKTstring,len))     //~v57XI~
        	break;                                                 //~v57XI~
    }//search loop                                                 //~v57XI~
    if (pckt>=pckte)	//not dup                                  //~v57XI~
    	return 0;                                                  //~v57XI~
    if (Popt & ADDSTT_DUPIGNORE)                                   //~v57XI~
    	return 2;                                                  //~v57XI~
    modx=pckt->CKTmodx;                                            //~v57XI~
    pfkt=pckt->CKTpfkt;                                            //~v57XI~
	ppstr=pfkt->FKTttstring[modx];                                 //~v57XI~
    for (ii=0;ii<FKT_MAX_STR;ii++)                                 //~v57XI~
    {                                                              //~v5muI~
    	if (*ppstr && !memcmp(*ppstr,Pstring,len))                 //~v57XI~
            break;                                                 //~v57XI~
        ppstr++;                                                   //~v5muI~
    }                                                              //~v5muI~
    if (ii>=FKT_MAX_STR)                                           //~v57XI~
    {                                                              //~v57XI~
        ukbdl_editstring(Pstring,editwk);                          //~v57XI~
        fprintf(stderr, "str tbl logical err for %s%s,newstr=%s\n",//~v57XI~
            	Sshiftidstr[Pmodx],Ppfkt->FKTkeyname,editwk);      //~v57XI~
	    return 4;                                                  //~v57XI~
    }                                                              //~v57XI~
    if (pfkt==Ppfkt && modx==Pmodx)	//for same key                 //~v57XI~
    	return 0;                                                  //~v57XI~
//reset old                                                        //~v57XI~
    *ppstr=0;                                                      //~v57XI~
    pfkt->FKTflag[modx][ii]=0;                                     //~v57XI~
//set new                                                          //~v57XI~
    for (ii=0;ii<FKT_MAX_STR;ii++)                                 //~v57XI~
    {                                                              //~v57XI~
   		if (!Ppfkt->FKTttstring[Pmodx][ii])                        //~v57XI~
            break;                                                 //~v57XI~
    }                                                              //~v57XI~
    if (ii==FKT_MAX_STR)                                           //~v57XI~
    {                                                              //~v57XI~
        ukbdl_editstring(Pstring,editwk);                          //~v57XI~
        fprintf(stderr, "move:string assignment overflow(max is %d) for %s%s,%s ignored\n",//~v57XI~
            	FKT_MAX_STR,Sshiftidstr[Pmodx],Ppfkt->FKTkeyname,editwk);//~v57XI~
	    return 4;                                                  //~v57XI~
    }                                                              //~v57XI~
    Ppfkt->FKTttstring[Pmodx][ii]=Pstring;                         //~v57XI~
    Ppfkt->FKTflag[Pmodx][ii]=FKT_TTREPKEY;                        //~v57XI~
//  Scurseskeytbl[Scktno].CKTpfkt=Ppfkt;                           //+v5mvR~
//  Scurseskeytbl[Scktno].CKTmodx=Pmodx;                           //+v5mvR~
    pckt->CKTpfkt=Ppfkt;                                           //+v5mvI~
    pckt->CKTmodx=Pmodx;                                           //+v5mvI~
    return 1;	//dup found                                        //~v57XI~
}//ukbdaixt_dupstrchk                                              //~v57XI~
////**********************************************************************//~v584R~
////* process input mapfile                                        //~v584R~
////*    record fmt   ;; @key=keyname=^[[xxx                       //~v584R~
////**********************************************************************//~v584R~
//int ukbdaixt_printttkey(PFUNCKEYTBL Ppfkt,int Pmodx)             //~v584R~
//{                                                                //~v584R~
//    char *typ;                                                   //~v584R~
//    char keynm[32];                                              //~v584R~
////************************                                       //~v584R~
////  if (Ppfkt->FKTfkassign[Pmodx]==FKT_TTORGKEY)                 //~v584R~
//    if (Ppfkt->FKTflag[Pmodx][0]==FKT_TTORGKEY)                  //~v584R~
//        typ="ORG";                                               //~v584R~
//    else                                                         //~v584R~
//        typ="REP";                                               //~v584R~
//    sprintf(keynm,"%s%s",Sshiftidstr[Pmodx],Ppfkt->FKTkeyname);  //~v584R~
//    printf(";;#          %s %s%-9.*s=^[%s\n",                    //~v584R~
//                        typ,                                     //~v584R~
//                        Sttstrlineid,                            //~v584R~
//                        (int)strlen(keynm),                      //~v584R~
//                        keynm,                                   //~v584R~
//                        Ppfkt->FKTttstring[Pmodx]+1);            //~v584R~
//    return 0;                                                    //~v584R~
//}//ukbdaixt_printttkey                                           //~v584R~
//**********************************************************************//~0B23I~
//* process input mapfile                                          //~0B23I~
//*    record fmt   ;; @key=keyname=^[xxx                          //~0B23I~
//**********************************************************************//~0B23I~
//int ukbdaixt_chngttkey(char *Ppfile)                             //~v58aR~
int ukbdaixt_chngttkey(int Popt,char *Ppfile)                      //~v58aI~
{                                                                  //~v584R~
//    PFUNCKEYTBL pfkt;                                            //~v57XR~
//    int ii,rc=0,modx;                                            //~v57XR~
//    int foundsw,keynmlen,strll;                                  //~v57XR~
//    FILE *fh;                                                    //~v57XR~
//    char buff[512],*pc,*keynm,*keynme,*str,*stre;                //~v57XR~
////************************                                       //~v57XR~
//    if (!(fh=fopen(Ppfile,"r")))  //open input fail              //~v57XR~
//        uerrexit("input file(%s) open err",                      //~v57XR~
//                    "入力ファイル(%s) のオープンエラー",         //~v57XR~
//                        Ppfile);                                 //~v57XR~
//    if (fh<=0)                                                   //~v57XR~
//    {                                                            //~v57XR~
//        uerrexit("keycode map file open failed rc=%d\n",0,       //~v57XR~
//                Ppfile);                                         //~v57XR~
//    }                                                            //~v57XR~
//    rc=0;                                                        //~v57XR~
//    while (fgets(buff,sizeof(buff),fh))                          //~v57XR~
//    {                                                            //~v57XR~
//        if (!(pc=strstr(buff,Sttstrlineid)))                     //~v57XR~
//            continue;                                            //~v57XR~
//        keynm=pc+strlen(Sttstrlineid);  //keyname pos            //~v57XR~
//        keynm+=strspn(keynm," ");                                //~v57XR~
//        keynme=strpbrk(keynm," \t,=");                           //~v57XR~
//        if (!keynme)                                             //~v57XR~
//        {                                                        //~v57XR~
//            uerrmsg("line format err:no keyname found on %s",0,  //~v57XR~
//                        buff);                                   //~v57XR~
//            rc=4;                                                //~v57XR~
//            continue;                                            //~v57XR~
//        }                                                        //~v57XR~
//        modx=0;                                                  //~v57XR~
//        if (*(keynm+1)=='+')                                     //~v57XR~
//            for (;modx<4;modx++)                                 //~v57XR~
//                if (*keynm==*Sshiftidstr[modx])                  //~v57XR~
//                {                                                //~v57XR~
//                    keynm+=2;                                    //~v57XR~
//                    break;                                       //~v57XR~
//                }                                                //~v57XR~
//        if (modx>=4)                                             //~v57XR~
//        {                                                        //~v57XR~
//            uerrmsg("Shift modifier err on %s",0,                //~v57XR~
//                        buff);                                   //~v57XR~
//            rc=4;                                                //~v57XR~
//            continue;                                            //~v57XR~
//        }                                                        //~v57XR~
//        keynmlen=(ULONG)keynme-(ULONG)keynm;                     //~v57XR~
//        pc=strchr(keynme,'=');                                   //~v57XR~
//        if (!pc)                                                 //~v57XR~
//        {                                                        //~v57XR~
//            uerrmsg("line format err:no string found on %s",0,   //~v57XR~
//                        buff);                                   //~v57XR~
//            rc=4;                                                //~v57XR~
//            continue;                                            //~v57XR~
//        }                                                        //~v57XR~
//        pc++;                                                    //~v57XR~
//        pc+=strspn(pc," ");                                      //~v57XR~
//        if (*pc!='^'||*(pc+1)!='['||*(pc+2)!='[')                //~v57XR~
//        {                                                        //~v57XR~
//            uerrmsg("line format err:string should start by ^[[,(%.3s)err on %s",0,//~v57XR~
//                        pc,buff);                                //~v57XR~
//            rc=4;                                                //~v57XR~
//            continue;                                            //~v57XR~
//        }                                                        //~v57XR~
//        str=pc;                                                  //~v57XR~
////      stre=strpbrk(str," \t,");                                //~v57XR~
//        stre=strpbrk(str," \t,\n");                              //~v57XR~
//        if (stre)                                                //~v57XR~
//            strll=(ULONG)stre-(ULONG)str;                        //~v57XR~
//        else                                                     //~v57XR~
//            strll=strlen(str);                                   //~v57XR~
//        foundsw=0;                                               //~v57XR~
//        for (ii=0;ii<PFKTNO;ii++)        //keycode               //~v57XR~
//        {                                                        //~v57XR~
//            pfkt=Spfktbl[ii];                                    //~v57XR~
//            if (keynmlen==strlen(pfkt->FKTkeyname)               //~v57XR~
//            &&  !memicmp(pfkt->FKTkeyname,keynm,keynmlen))       //~v57XR~
//            {                                                    //~v57XR~
//                foundsw=1;                                       //~v57XR~
//                break;                                           //~v57XR~
//            }                                                    //~v57XR~
//        }                                                        //~v57XR~
//        if (!foundsw)                                            //~v57XR~
//        {                                                        //~v57XR~
//            uerrmsg("keyname (%.*s) is invalid on %s",0,         //~v57XR~
//                    keynmlen,keynm,buff);                        //~v57XR~
//            rc=4;                                                //~v57XR~
//            continue;                                            //~v57XR~
//        }                                                        //~v57XR~
//        if (strll<=3)   //del req                                //~v57XR~
//            pfkt->FKTfkassign[modx]=0;                           //~v57XR~
//        else                                                     //~v57XR~
//        {                                                        //~v57XR~
//            pc=malloc(strll);                                    //~v57XR~
//            *pc=0x1b;                                            //~v57XR~
//            memcpy(pc+1,str+2,strll-2);                          //~v57XR~
//            *(pc+strll-1)=0;                                     //~v57XR~
//            pfkt->FKTttstring[modx]=pc;                          //~v57XR~
//            pfkt->FKTfkassign[modx]=FKT_TTREPKEY;                //~v57XR~
//        }                                                        //~v57XR~
//    }                                                            //~v57XR~
//    return rc;                                                   //~v57XR~
//}//ukbdaixt_chngttkey                                            //~v57XR~
	PFUNCKEYTBL pfkt;                                              //~v57XI~
    int ii,rc=0,modx,errsw,idlen;                                  //~v57XI~
	int foundsw,keynmlen,strll;                                    //~v57XI~
    FILE *fh;                                                      //~v57XI~
    char buff[512],*pc,*keynm,*keynme,*str,*stre;                  //~v57XI~
    int applysw;                                                   //~v584R~
    char *envterm;                                                 //~v57XI~
    char *envxeterm;                                               //~v57XI~
    int        len;                                                //~v57XI~
typedef struct _SECTIONTBL{                                        //~v57XI~
                            int  STsectid;                         //~v57XI~
                            char *STsectname;                      //~v57XI~
                            int  STnamelen;                        //~v57XI~
                           } SECTIONTBL,*PSECTIONTBL;              //~v57XI~
                                                                   //~v57XI~
static SECTIONTBL Ssectbl[]={{0,            "common" ,6},          //~v57XI~
//                           {TERM_VT100,   "vt100"  ,5},          //~v58aR~
                             {TERM_VT100,   TTERMID  ,5},          //~v58aI~
                             {TERM_AIXTERM, "aixterm",7},          //~v57XI~
                             {TERM_XTERM,   "xterm"  ,5},          //~v57XI~
                             {TERM_KTERM,   "kterm"  ,5}           //~v57XI~
                            };                                     //~v57XI~
#define SECTBLSZ (sizeof(Ssectbl)/sizeof(SECTIONTBL))              //~v584I~
	PSECTIONTBL ps;                                                //~v57XI~
//************************                                         //~v57XI~
    envterm=getenv("TERM");                                        //~v57XI~
    if (Popt & UKBDL_TNTT)                                         //~v58aI~
    	envterm=TTERMID;                                           //~v58aI~
    envxeterm=getenv("XETERM");                                    //~v57XI~
    Stermid=ukbdl_gettermid();                                     //~v584I~
    if (!(fh=fopen(Ppfile,"r")))  //open input fail                //~v57XI~
        uerrexit("input file(%s) open err",                        //~v57XI~
                    "入力ファイル(%s) のオープンエラー",           //~v57XI~
                        Ppfile);                                   //~v57XI~
    if (fh<=0)                                                     //~v57XI~
    {                                                              //~v57XI~
        uerrexit("keycode map file open failed rc=%d\n",0,         //~v57XI~
                Ppfile);                                           //~v57XI~
    }                                                              //~v57XI~
    rc=0;                                                          //~v57XI~
    idlen=strlen(Skfstrlineid);	//keyname pos                      //~v57XI~
    applysw=0;                                                     //~v57XI~
    while (fgets(buff,sizeof(buff),fh))                            //~v57XI~
    {                                                              //~v57XI~
        pc=buff+strspn(buff," \t");                                //~v57XI~
        if (*pc=='#'||*pc=='!'||*pc=='\n')                         //~v57XI~
        	continue;                                              //~v57XI~
        if (*pc=='[')	//termname section                         //~v57XI~
        {                                                          //~v57XI~
            pc++;                                                  //~v57XI~
            len=0;                                                 //~v57XI~
        	if (envxeterm && *envxeterm && !memicmp(pc,envxeterm,strlen(envxeterm)))	//by TERM env//~v57XI~
                len=strlen(envxeterm);                             //~v57XI~
            else                                                   //~v57XI~
            {                                                      //~v57XI~
//          	for (ps=Ssectbl,ii=0;ii<sizeof(Ssectbl);ii++,ps++) //~v584R~
            	for (ps=Ssectbl,ii=0;ii<SECTBLSZ;ii++,ps++)        //~v584I~
                {                                                  //~v57XI~
        	        if (!memicmp(pc,ps->STsectname,ps->STnamelen))	//common//~v57XI~
                    {                                              //~v57XI~
                    	if (!ps->STsectid || ps->STsectid==Stermid)//~v57XI~
	        	        	len=ps->STnamelen;                     //~v57XI~
                    	break;                                     //~v57XI~
                    }                                              //~v57XI~
                }                                                  //~v57XI~
                if (!len)                                          //~v57XI~
                    if (envterm && *envterm && !memicmp(pc,envterm,strlen(envterm)))    //by TERM env//~v57XI~
         	           len=strlen(envterm);    //by TERM env       //~v57XI~
            }                                                      //~v57XI~
            if (len && *(pc+len)==']')                             //~v57XI~
                applysw=1;                                         //~v57XI~
            else                                                   //~v57XI~
                applysw=0;                                         //~v57XI~
            continue;	//section hdr                              //~v57XI~
        }                                                          //~v57XI~
        if (!applysw)                                              //~v57XI~
        	continue;                                              //~v57XI~
    	for (;;)                                                   //~v57XI~
        {                                                          //~v57XI~
        	errsw=1;                                               //~v57XI~
            if (!(pc=umemstri(buff,Skfstrlineid,strlen(buff))))    //~v57XI~
            {                                                      //~v57XI~
                uerrmsg("line format err:line-id \"%s\" is not found: %s",0,//~v57XI~
                            Skfstrlineid,buff);                    //~v57XI~
                break;                                             //~v57XI~
            }                                                      //~v57XI~
            keynm=pc+idlen;  //keyname pos                         //~v57XI~
            keynm+=strspn(keynm," ");                              //~v57XI~
            keynme=strpbrk(keynm," \t,=");                         //~v57XI~
            if (!keynme)                                           //~v57XI~
            {                                                      //~v57XI~
                uerrmsg("line format err:no string found: %s",0,   //~v57XI~
                            buff);                                 //~v57XI~
                break;                                             //~v57XI~
            }                                                      //~v57XI~
            modx=0;                                                //~v57XI~
            if (*(keynm+1)=='+')                                   //~v57XI~
                for (;modx<4;modx++)                               //~v57XI~
                    if (toupper(*keynm)==*Sshiftidstr[modx])       //~v57XI~
                    {                                              //~v57XI~
                        keynm+=2;                                  //~v57XI~
                        break;                                     //~v57XI~
                    }                                              //~v57XI~
            if (modx>=4)                                           //~v57XI~
            {                                                      //~v57XI~
                uerrmsg("Shift modifier err: %s",0,                //~v57XI~
                            buff);                                 //~v57XI~
                break;                                             //~v57XI~
            }                                                      //~v57XI~
            keynmlen=(ULONG)keynme-(ULONG)keynm;                   //~v57XI~
        	pc=strchr(keynme,'=');                                 //~v57XI~
            if (!pc)                                               //~v57XI~
            {                                                      //~v57XI~
                uerrmsg("line format err:no string found: %s",0,   //~v57XI~
                            buff);                                 //~v57XI~
                break;                                             //~v57XI~
            }                                                      //~v57XI~
            pc++;                                                  //~v57XI~
            pc+=strspn(pc," ");                                    //~v57XI~
        	if (*pc!='^'||*(pc+1)!='[')                            //~v57XI~
        	{                                                      //~v57XI~
                uerrmsg("line format err:string should start by \"^[\": %s",0,//~v57XI~
                            buff);                                 //~v57XI~
                break;                                             //~v57XI~
            }                                                      //~v57XI~
            str=pc;                                                //~v57XI~
            stre=strpbrk(str," \t,\n");                            //~v57XI~
            if (stre)                                              //~v57XI~
                strll=(ULONG)stre-(ULONG)str;                      //~v57XI~
            else                                                   //~v57XI~
                strll=strlen(str);                                 //~v57XI~
            foundsw=0;                                             //~v57XI~
            for (ii=0;ii<PFKTNO;ii++)        //keycode             //~v57XI~
            {                                                      //~v57XI~
                pfkt=Spfktbl[ii];                                  //~v57XI~
                if (keynmlen==strlen(pfkt->FKTkeyname)             //~v57XI~
                &&  !memicmp(pfkt->FKTkeyname,keynm,keynmlen))     //~v57XI~
                {                                                  //~v57XI~
                    foundsw=1;                                     //~v57XI~
                    break;                                         //~v57XI~
                }                                                  //~v57XI~
            }                                                      //~v57XI~
            if (!foundsw)                                          //~v57XI~
            {                                                      //~v57XI~
                uerrmsg("keyname (%.*s) is invalid: %s",0,         //~v57XI~
                        keynmlen,keynm,buff);                      //~v57XI~
                break;                                             //~v57XI~
            }                                                      //~v57XI~
            if (strll<=3)   //del req                              //~v57XI~
            {                                                      //~v57XI~
                pc="";                                             //~v57XI~
                strll=0;                                           //~v57XI~
            }                                                      //~v57XI~
            else                                                   //~v57XI~
            {                                                      //~v57XI~
                pc=malloc(strll);                                  //~v57XI~
                *pc=0x1b;                                          //~v57XI~
                memcpy(pc+1,str+2,strll-2);                        //~v57XI~
                *(pc+strll-1)=0;                                   //~v57XI~
                strll--;                                           //~v57XI~
            }                                                      //~v57XI~
			ukbdaixt_addstrtbl(ADDSTT_DUPRESET,FKT_TTREPKEY,pc,pfkt,modx,strll);//~v584R~
            errsw=0;                                               //~v57XI~
            break;                                                 //~v57XI~
        }//err break loop                                          //~v57XI~
        if (errsw)                                                 //~v57XI~
        	rc++;                                                  //~v57XI~
    }                                                              //~v57XI~
    if (rc)                                                        //~v57XI~
        uerrexit("\"%s\" contain %d err line;fmt=\"%skeyname=string\". ",0,//~v57XI~
  	               Ppfile,rc,Skfstrlineid);                        //~v57XI~
    return rc;                                                     //~v57XI~
}//ukbdaixt_chngttkeysub                                           //~v57XI~
//*********************************************************************
//* set string of func key
//*********************************************************************
int ukbdaixt_getconsole(void)                                      //~0B11R~
{
    int fd;
//*************************************
    fd=ukbdaixt_open("/dev/tty");                                  //~0B11R~
    if (fd>=0)
      return fd;

    fd=ukbdaixt_open("/dev/console");                              //~0B11R~
    if (fd >= 0)
      return fd;

    for (fd=0;fd<3;fd++)
      if (ukbdaixt_chkconsole(fd))                                 //~0B11R~
        return fd;

    fprintf(stderr,
        "Couldnt get a file descriptor referring to the console\n");
    return fileno(stdout);                                         //~v40gI~
}
//*********************************************************************
//* open console
//*********************************************************************
int ukbdaixt_open(char *Pname)                                     //~0B11R~
{
    int fd;
//*************************************
    fd=open(Pname,O_RDONLY);
//printf("open %s,fd=%d\n",Pname,fd);
    if (fd < 0 && errno == EACCES)
        fd=open(Pname,O_WRONLY);
    if (fd < 0 || ! ukbdaixt_chkconsole(fd))                       //~0B11R~
      return -1;
    return fd;
}//ukbdaixt_open                                                   //~0B11R~
//*********************************************************************
//* chk fd is console
//* ret 1:valid,0:invalid
//*********************************************************************
int ukbdaixt_chkconsole(int Pfd)                                   //~0B11R~
{
    return isatty(Pfd);                                            //~v40gI~
}//ukbdaixt_chkconsole(int Pfd)                                    //~0B11R~
