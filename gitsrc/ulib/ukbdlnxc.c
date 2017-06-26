//*CID://+v6FdR~:                             update#=  484;       //~v6EYR~//~v6FdR~
//*************************************************************
//*ukbdlnxc.c                                                      //~v5mvR~
//*kbd get for linux console screen
//*************************************************************
//v6Fd:160918 (BUG)curses key tbl overflow                         //~v6FdI~
//v6Ey:160824 for FindPSx register S+C+F5,S+A+F5                   //~v6EYI~
//v6D1:160418 LNX64 compiler warning                               //~v6D1I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6qh:131214 change terminal type:SCO Esc string by v6q6 as optional//~v6qhI~
//v6q5:131202 (LNX)rep 0x1b Alt+ if no esc code defined to avoid screen corruption//~v6q5I~
//v6q4:131201 (LNX)PuTTY generate 0x1b1b[13~ for Alt+F3(F3 is 0x1b@13~)//~v6q4I~
//            treate 0x1+0x1b as 0x1b(Alt+) nad next 0x1b__        //~v6q4I~
//v6q3:131129 (LNX)compiler warning;dereferencing type-punned pointer//~v6q3I~
//v6j0:121102 for xcifb; -DNOCURSES -DXSUB                         //~v6j0I~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v63c:091120 (BUG)Ubuntu9 compiler warning                        //~v63CI~
//v62T:091015_(BUG)more over on V629; continueous key press miss func key when 0x1b was left on read string//~v62TI~
//            cause of remaining 1b is cutting by buffsize         //~v62TI~
//v62H:091006_(LNX:BUG)avoid kbd hung by read next utf8 char when ENV is UTF8 but terminal emulator generate locale code//~v62HI~
//v629:090720 (BUG)FC10 returns char after some intervals after 0x1b for Alt+char key.//~v629I~
//            try read after 1 byte 0x1b was read.                 //~v629I~
//v5nD:090329 S390 support                                         //~v5nDI~
//v5nr:081106 european char(>0x80)treated as Alt+x; assume Alt+x is 0x1b+x//~v5nrI~
//v5mv:080521 (LNX:CON)accept R-Ctrl key string definition max 4   //~v5mvI~
//v5mu:080521 (LNX:CON)accept string not start with 0x1b as esc string//~v5muI~
//v5mf:080229 (LNXCON)utilize A+{|} as A+S+[|] for FWF/FWB cmd     //~v5mfI~
//v5md:080229 (LNX:BUG)Ctrl+] is not available because scan code is not set//~v5mdI~
//v5m1:080126 (LNX:BUG)uerrmsg->konchk(from xcv) abend when stdin is redirected(ttyname errno=22:invalid arg)//~v5m1I~
//v5k9:070302-(LNX)keymap file syntax chk;not err but ignore string not specified;it's same as xeputty//~v5k9I~
//v5k8:070301-(LNX)keymap file open err when ~/ is used            //~v5k8I~
//v5k7:070301-(LNX)process of --kmapfile;allow space between modifier and keyname like as xeputty//~v5k7I~
//v5ip:060801 (BUG)C+10key,C+"-",c+"+" is ignored                  //~v5ipI~
//v5im:060722*101 kbd support(for line drawing char '^' is '=' on 101 kbd)//~v5imI~
//v5bp:040215 (UNX)ctrl+char function support(return scancode)     //~v5bpI~
//v592:030928 (LNX)mouse support                                   //~v592I~
//v58e:030824 (UNX) move key registration to another header file,ukbdl2.h//~v58eI~
//v58c:030824 (LNX) Alt+10key registration;not used now but.       //~v58cI~
//v589:030819 integrate UKBDLNXC_-->UKBDL_                         //~v589I~
//v586:030816 (LNX)use same keyname as AIX to share key change file//~v586I~
//v57Z:030805 (LNX)allow hex notion on parm key string(for kterm bug 1b[\x00 of Home,End key)//~v57ZI~
//v57Y:030802 (LNX)option of assign 0x7f to BS/DEL/CHAR            //~v57YI~
//v57R:030720 (LNX)(RH9)ctl+2 dose not generat x00                 //~v57RI~
//v57N:030712 (LNX)defalt curses key setup for all X-term if not duplicated//~v57NI~
//v57M:030709 (LNX)option to skip set function string              //~v57MI~
//v57L:030706 (LNX)common key mapping file for gnome-terminal/xterm/kterm//~v57LI~
//v57K:030706 (LNX)consideration for 7f(del or bs) when alt=meta;additional to v57C//~v57LR~
//v57D:030419 (LNX)accept DBCS                                     //~v57DI~
//v57C:030419 (LNX)accept meta bit on char under X if 1 byte input //~v57CI~
//v57B:030419 (LNX)no process chain when xe executed by shell      //~v57BI~
//v57z:030406 (LNX)gnome-terminal support                          //~v57zI~
//v57y:030405 (LNX)support user key string specification file(for bush when runlevel=5)//~v57yI~
//v57x:030405 (LNX:BUG)under x,getkeysim faile,so BS and DEL exchange dose not work//~v57xI~
//v57w:030223 (LNX:BUG)xterm/kterm should determined by cmd name not by TERM env var.//~v57wI~
//v55w:020601 (UNX)display original input string before trnaslation//~v55wI~
//v55v:020530 (AIX:BUG)chked all key touch                         //~v55vI~
//            alt+\-->Alt+6                                        //~v55vI~
//v536:020318 (UNX:BUG)kbd read faile cause loop                   //~v536I~
//v525:020114 (LNX:BUG)all key is not restored at all xe term      //~v525I~
//v524:020114 (LNX)use flock to chk last xe to restore kbd chng    //~v524I~
//v515:011212 (BUG:LNX)10-key for keisen not available             //~v515R~
//v50z:010521 LINUX support:support getch/kbhit                    //~v50zI~
//v50v:010422 konchk performance up                                //~v501I~
//v501:010305 X support:kterm/xterm generate 0x1b[A(hard codes in input.c)//~v500I~
//v500:010305 X support:kterm terminfo is home by find,end by select.//~v500I~
//v428:010218 TLinux:ps operand is not same as SW3.5               //~v428I~
//v427:010108 TLinux:no responce by Alt+BS                         //~v427I~
//v426:010108 TLinux:del key return 7f,set as default of TL        //~v426I~
//v425:010101 TLinux:del key return 7f                             //~v425I~
//v424:010101 TLinux:terminfo define S+Fn,but showkey return same string as Fn//~v424R~
//v423:010101 TLinux:another SignalHandler definition insignal.h   //~v423I~
//v3a1:010226 LINUX support:print string(xekbchk) support          //~v3a1I~
//v39Z:010204 LINUX support:set is not avail but get is avail for pty//~v39ZI~
//            (get from tty corresponding to the pty)              //~v39ZI~
//v39S:010129 LINUX support:accept doskey evenif not internaly defined.//~v39SI~
//                          (allow to setup by loadkey with key and string)//~v39SI~
//v39M:010121 LINUX support:confirm func string over terminfo;for the case exit witout restoreing.//~v39MI~
//v39L:010120 LINUX support:use hex char str for scancode on funcstring//~v39LR~
//v39K:010120 LINUX support:missing clear st restore for the string is previously null//~v39JI~
//v39J:010120 LINUX support:allow PFxx assign change by keyboard.map//~v39JI~
//                         (use doskey scancode as funckey string) //~v39JI~
//v39w:010108 LINUX support:(BUG)should return Alt+BS(x0e00) when BS is by 0x7f//~v39wI~
//v39v:010108 LINUX support:for kon(getsym fail);default is BS for 7f//~v39vI~
//v39u:010108 LINUX support:no reset keysym of BS to x08 for compatibility.//~v39uI~
//v39t:010108 LINUX support:for debug,change macro SETUPCKT to function.//~v39tI~
//v39p:001209 LINUX support:Ctrl+@ return x00,which is treated as break//~v39pI~
//v39i:001126 LINUX support:NumPad key support                     //~v39iI~
//v39e:001124 LINUX support:(BUG) Ctl+2 generate x00,it is same as ctl+pause(00/00)//~v39eI~
//                          use string for ctl+2 and generate scan=03,char=00//~v39eI~
//v39b:001113 LINUX support:move posix logic(common to linux and aix) to ukbdl from ukbdlnxc//~v39bI~
//v39a:001113 LINUX support:(BUG) "," missing                      //~v39aI~
//v398:001111 LINUX support:cleanup before exit                    //~v398I~
//v395:001105 LINUX support:switch echo,noraw<-->noecho,raw for sub-shell mode//~v395I~
//v386:001007 LINUX support(multi session support,kbd set at first/reset at last)//~v386I~
//v384:001001 LINUX support(hearing of key assign from kbdinit)    //~v384I~
//v383:001001 BUG of v373                                          //~v383I~
//v373:000928 LINUX support(BUG:alt pfk use ignored when original string assigned//~v373I~
//            because shell catch it before xe;so set another string)//~v373I~
//v368:000927 LINUX support(Shift+Tab receive 09;so ignore key_btab and set PFK)//~v368I~
//v362:000927 LINUX support(support getch where out of curses)     //~v362I~
//v324 000813:LINUX support                                        //~v324I~
//*************************************************************    //~v324I~
#include <stdlib.h>                                                //~v39ZI~
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <linux/types.h>
#include <linux/kd.h>
#include <linux/keyboard.h>
#include <sys/ioctl.h>
#include <sys/stat.h>                                              //~v386I~
#include <sys/file.h>                                              //~v524I~
#include <sys/time.h>                                              //~v592I~
#include <string.h>
#include <errno.h>
#include <signal.h>
#ifndef NOCURSES                                                   //~v6a0R~
#include <ncurses.h>                                               //~v324I~
//#include <term.h>                                                //~v6j0R~
#endif                                                             //~v6a0I~
#ifndef ARM                                                        //~v6j0I~
	#include <term.h>                                              //~v6j0I~
#endif                                                             //~v6j0I~

#include <ulib.h>                                                  //~v386I~
#include <ukbdl.h>                                                 //~v39bI~
#include <ukbdlnxc.h>                                              //~v324R~
#include <ukbdlnxm.h>                                              //~v592I~
#include <ueh.h>                                                   //~v423I~
#include <uehl.h>                                                  //~v324I~
#include <utrace.h>                                                //~v383I~
#include <ufile.h>                                                 //~v386I~
#include <ufile4.h>                                                //~v39ZI~
#include <ualloc.h>                                                //~v386I~
#include <uabend.h>                                                //~v398I~
#include <uerr.h>                                                  //~v39ZI~
#include <uproc.h>                                                 //~v39ZI~
#include <ustring.h>                                               //~v57yI~
#include <uedit.h>                                                 //~v57ZI~
#ifdef UTF8SUPPH                                                   //~v629I~
	#include <uproc4.h>                                            //~v629I~
#endif                                                             //~v629I~
#include <uviol.h>                                                 //~v6a0I~
//*********************************************************************
//*********************************************************************
#define MODX_PLAIN     0
#define MODX_SHIFT     1
#define MODX_CONTROL   2
#define MODX_ALT       3
#define MODX_ALTGR     4

#define MODX_CONSOLE   5

#define MODX_CON_ALTL  5
#define MODX_CON_ALTR  6
#define MODX_CON_SALTL 7
#define MODX_CON_SALTR 8
#define MODX_CON_CALTL 9
#define MODX_CON_CALTR 10
#define MODX_SCO     0x0100 //optional to terminal type:sco of puTTY//~v6qhI~
#define MODX_Z2      0x0200 //^[[Z is S+F2 by SCO                  //~v6qhI~
#define MODX_ZT      0x0400 //^[[Z is S+Tab as usual               //~v6qhR~
#define MODX_SHIFT_REPORT  0x0800 //Shift+Alt or Shift+Control     //~v6EYI~

                                                                   //~v6qhI~
#define RCTLID         0xffe4   //=XK_Control_R internal used RCTL id//~v5mvI~
                                                                   //~v5mvI~
#define FUNCSTRID 0x7e
//#define FUNCSTR_START    0x04 //to avoid write 0x03(SIGINT:user send Ctrl+C)//~v39JR~
//#define FUNCSTR_SKIPSQ   0x1c //to avoid write 0x1c(SIGQUIT:Ctrl+\)//~v39JR~
//#define FUNC_STRLEN      5  // string lne; 1b,[,scan,modx        //~v39SR~
#define FUNC_STRLEN      7  // string lne; 1b,[,scan(2),char(2),modx(1)//~v39SI~
                                                                   //~v324I~
//#define TERMINFOSTRID     '['	//string by terminfo original      //~v3a1R~

#define CH_ESCAPE        0x1b
#define CH_BACKSP        0x08
#define CH_DELETE        0x7f
#define CH_DELETE_ALT    0xff   //with meta bit                    //~v57KI~
#define CH_BACKSP_ALT    0x88   //with meta bit                    //~v57KR~
                                                                   //~v39wI~
//#define READSIZE  32                                             //~v62TR~
#define READSIZE  128                                              //~v62TR~
#define TH_READNEXT  8   //read next data when read buff exausted after full read//~v62TI~

#define DEADKEY_KATAKANA  '`'         //use DGRAVE as katakana deadkey
#define DEADKEY_KEYCODE   58          //use alt+eisu as deadkey
#define TERMNAME_G     "gnome-terminal"                            //~v57LI~
#define TERMNAME_K     "kterm"                                     //~v57LI~
#define TERMNAME_X     "xterm"                                     //~v57LI~
#define TERMNAME_COMM  "common"                                    //~v57LI~
//*********************************************************************
static int Skbdinitsw;                                             //~v324I~
static char *Slockfile="/tmp/lockfile_ukbdlnxc";                   //~v386R~
static char *Slockfile2="/tmp/xe_lockfile";                        //~v524I~
static int  Sfdlockfile;                                           //~v386I~
static int  Sfdlockfile2;	//lock chk file                        //~v524I~
static int  Slockfsavedsw;	//saved by me                          //~v386I~
//static int  Spidlocksw;	//pidlock file allocated sw            //~v524R~
static int  Slockstatus;	//pidlock file allocated sw            //~v524I~
#define  LS_SH      0x01    //SHARED lock gotten                   //~v524I~
#define  LS_EX      0x02    //EXCLUSIVE lock gotten                //~v524I~
#define  LS_FIRST   0x10    //created  save file                   //~v524I~
#define  LS_LAST    0x20    //last xe,reset kbd                    //~v524I~
static char Skfstrlineid[]=KFSTRLINEID; //string=                  //~v57NR~
static  char *Sshiftidstr[]={"","S+","C+","A+"};                   //~v57yI~
static void *Spurr;		//uehl_setsh return eh registration record //~v324I~
static int Scursessw;                                              //~v324I~
static int Snonescentrytop=-1;//use esc string not startwith 0x1b  //~v5mvR~
static int Stermid;                                                //~v501R~
static int Stermnameid=0;                                          //~v57NI~
static unsigned char Sbuff[READSIZE*2]; //read buff                //~v3a1I~
static unsigned char Sorgbuff[READSIZE*2]; //read buff             //~v55wI~
static  int  Sreadlen;					//read len                 //~v3a1I~
static  int  Sreslen;                                              //~v324M~
static  unsigned char *Snextpos;                                   //~v324I~
static  int Sfd;			//fd for read                          //~v39ZR~
static  int Sfdioctl;		//tty fd for ioctl                     //~v39ZI~
static  int Sbs_del_sw;//del(0x7f) is assigned for bs(0x08)        //~v324R~
static  int Sdel_by_7f; //treate 7f as Del key                     //~v425I~
static struct  kbdiacrs Ssavecompose;                              //~v386R~

static  int Smapid[FKT_MAX_SYM]={0,1<<KG_SHIFT,1<<KG_CTRL,1<<KG_ALT,1<<KG_ALTGR};
static  int Sshiftid[]={0,
                      UKBDLNXC_MOD_SHIFTL|UKBDLNXC_MOD_SHIFTR,
                      UKBDLNXC_MOD_CONTROL,
                      UKBDLNXC_MOD_ALT|UKBDLNXC_MOD_ALTL,
                      UKBDLNXC_MOD_ALT|UKBDLNXC_MOD_ALTR
                     ,UKBDLNXC_MOD_CONTROL|UKBDLNXC_MOD_CTLR       //~v5mvI~
                      };
//*Alt+char code conversion tbl for doskey
static  unsigned short Saltchartbl[]={
//                  -1,      //0x00                                //~v39pR~//~v6D0R~
                      0xffff,//0x00                                //~v6D0R~
                      0xffff,//0x01                                //~v6D0R~
                      0xffff,//0x02                                //~v6D0R~
                      0xffff,//0x03                                //~v6D0R~
                      0xffff,//0x04                                //~v6D0R~
                      0xffff,//0x05                                //~v6D0R~
                      0xffff,//0x06                                //~v6D0R~
                      0xffff,//0x07                                //~v6D0R~
                    0x0e00,  //0x08  BackSpace
                    0xa500,  //0x09  Tab
                      0xffff,//0x0a                                //~v6D0R~
                      0xffff,//0x0b                                //~v6D0R~
                      0xffff,//0x0c                                //~v6D0R~
                    0x1c00,  //0x0d  Enter
                      0xffff,//0x0e                                //~v6D0R~
                      0xffff,//0x0f                                //~v6D0R~

                      0xffff,//0x10                                //~v6D0R~
                      0xffff,//0x11                                //~v6D0R~
                      0xffff,//0x12                                //~v6D0R~
                      0xffff,//0x13                                //~v6D0R~
                      0xffff,//0x14                                //~v6D0R~
                      0xffff,//0x15                                //~v6D0R~
                      0xffff,//0x16                                //~v6D0R~
                      0xffff,//0x17                                //~v6D0R~
                      0xffff,//0x18                                //~v6D0R~
                      0xffff,//0x19                                //~v6D0R~
                      0xffff,//0x1a                                //~v6D0R~
                    0x0100,  //0x1b  Escape
                      0xffff,//0x1c                                //~v6D0R~
                      0xffff,//0x1d                                //~v6D0R~
                      0xffff,//0x1e                                //~v6D0R~
                      0xffff,//0x1f                                //~v6D0R~

                    0x3920,  //0x20
                      0xffff,//0x21  !                             //~v6D0R~
                      0xffff,//0x22  "                             //~v6D0R~
                      0xffff,//0x23  #                             //~v6D0R~
                      0xffff,//0x24  $                             //~v6D0R~
                      0xffff,//0x25  %                             //~v6D0R~
                      0xffff,//0x26  &                             //~v6D0R~
                      0xffff,//0x27  '                             //~v6D0R~
                      0xffff,//0x28  (                             //~v6D0R~
                      0xffff,//0x29  )                             //~v6D0R~
                      0xffff,//0x2a  *                             //~v6D0R~
                      0xffff,//0x2b  +                             //~v6D0R~
                    0x3300,  //0x2c  ,
                    0x8200,  //0x2d  -
                    0x3400,  //0x2e  .
                    0x3500,  //0x2f  /

                    0x8100,  //0x30  0
                    0x7800,  //0x31  1
                    0x7900,  //0x32  2
                    0x7a00,  //0x33  3
                    0x7b00,  //0x34  4
                    0x7c00,  //0x35  5
                    0x7d00,  //0x36  6
                    0x7e00,  //0x37  7
                    0x7f00,  //0x38  8
                    0x8000,  //0x39  9
                    0x2800,  //0x3a  :
//                  0x2700   //0x3b  ;                             //~v39aR~
                    0x2700,  //0x3b  ;                             //~v39aI~
                      0xffff,//0x3c                                //~v6D0R~
//                  -1,      //0x3d                                //~v5imR~
                    0x8300,  //0x3d  =     on 101,same as ^ on japanese kbd//~v5imI~
                      0xffff,//0x3e                                //~v6D0R~
                      0xffff,//0x3f                                //~v6D0R~

                    0x1a00,  //0x40    @
                      0xffff,//0x41    A                           //~v6D0R~
                      0xffff,//0x42    B                           //~v6D0R~
                      0xffff,//0x43    C                           //~v6D0R~
                      0xffff,//0x44    D                           //~v6D0R~
                      0xffff,//0x45    E                           //~v6D0R~
                      0xffff,//0x46    F                           //~v6D0R~
                      0xffff,//0x47    G                           //~v6D0R~
                      0xffff,//0x48    H                           //~v6D0R~
                      0xffff,//0x49    I                           //~v6D0R~
                      0xffff,//0x4a    J                           //~v6D0R~
                      0xffff,//0x4b    K                           //~v6D0R~
                      0xffff,//0x4c    L                           //~v6D0R~
                      0xffff,//0x4d    M                           //~v6D0R~
                      0xffff,//0x4e    N                           //~v6D0R~
                      0xffff,//0x4f    O                           //~v6D0R~

                      0xffff,//0x50    P                           //~v6D0R~
                      0xffff,//0x51    Q                           //~v6D0R~
                      0xffff,//0x52    R                           //~v6D0R~
                      0xffff,//0x53    S                           //~v6D0R~
                      0xffff,//0x54    T                           //~v6D0R~
                      0xffff,//0x55    U                           //~v6D0R~
                      0xffff,//0x56    V                           //~v6D0R~
                      0xffff,//0x57    W                           //~v6D0R~
                      0xffff,//0x58    X                           //~v6D0R~
                      0xffff,//0x59    Y                           //~v6D0R~
                      0xffff,//0x5a    Z                           //~v6D0R~
                    0x1b00,  //0x5b   [
//                  0x7d00,  //0x5c   "\"   7d00 is same as alt+6  //~v55vR~
                      0xffff,//0x5c   "\"                          //~v55vI~//~v6D0R~
                    0x2b00,  //0x5d   ]
                    0x8300,  //0x5e   ^
                      0xffff,//0x5f    _ under_score               //~v6D0R~

                      0xffff,//0x60    ` grave                     //~v6D0R~
                    0x1e00,  //0x61    a
                    0x3000,  //0x62    b
                    0x2e00,  //0x63    c
                    0x2000,  //0x64    d
                    0x1200,  //0x65    e
                    0x2100,  //0x66    f
                    0x2200,  //0x67    g
                    0x2300,  //0x68    h
                    0x1700,  //0x69    i
                    0x2400,  //0x6a    j
                    0x2500,  //0x6b    k
                    0x2600,  //0x6c    l
                    0x3200,  //0x6d    m
                    0x3100,  //0x6e    n
                    0x1800,  //0x6f    o

                    0x1900,  //0x70    p
                    0x1000,  //0x71    q
                    0x1300,  //0x72    r
                    0x1f00,  //0x73    s
                    0x1400,  //0x74    t
                    0x1600,  //0x75    u
                    0x2f00,  //0x76    v
                    0x1100,  //0x77    w
                    0x2d00,  //0x78    x
                    0x1500,  //0x79    y
                    0x2c00,  //0x7a    z
//                  -1,      //0x7b                                //~v5mfR~
                    0x1b01,  //0x7b    A+S+[ : A+{ ,01:Shift,cleared later                    -1,      //0x7c//~v5mfR~
                      0xffff,//0x7c    A+S+\ : A+|                 //~v5mfI~//~v6D0R~
//                  -1,      //0x7d                                //~v5mfR~
                    0x2b01,  //0x7d    A+S+] : A+}                 //~v5mfR~
                      0xffff,//0x7e                                //~v6D0R~
                      0xffff //0x7f                                //~v6D0R~
                    };
//scancode table for char<x20                                      //~v324I~
static  unsigned char Snormalscantbl[]={                           //~v324R~
//                   0,      //0x00                                //~v39pR~
                    0x03/*00*/, //0x00    return null              //~v39pI~
          0x1e,//    0,      //0x01  ctrl+a                        //~v5bpR~
          0x30,//    0,      //0x02  ctrl+b                        //~v5bpR~
          0x2e,//    0,      //0x03  ctrl+c                        //~v5bpR~
          0x20,//    0,      //0x04  ctrl+d                        //~v5bpR~
          0x12,//    0,      //0x05  ctrl+e                        //~v5bpR~
          0x21,//    0,      //0x06  ctrl+f                        //~v5bpR~
          0x22,//    0,      //0x07  ctrl+g                        //~v5bpR~
                    0x0e/*08*/,  //0x08  BackSpace                 //~v324R~
                    0x0f/*09*/,  //0x09  Tab                       //~v324R~
          0x24,//    0,      //0x0a  ctrl+j                        //~v5bpR~
          0x25,//    0,      //0x0b  ctrl+k                        //~v5bpR~
          0x26,//    0,      //0x0c  ctrl+l                        //~v5bpR~
                    0x1c/*0d*/,  //0x0d  Enter                     //~v324R~
          0x31,//    0,      //0x0e  ctrl+n                        //~v5bpR~
          0x18,//    0,      //0x0f  ctrl+o                        //~v5bpR~
                                                                   //~v324R~
          0x19,//    0,      //0x10  ctrl+p                        //~v5bpR~
          0x10,//    0,      //0x11  ctrl+q                        //~v5bpR~
          0x13,//    0,      //0x12  ctrl+r                        //~v5bpR~
          0x1f,//    0,      //0x13  ctrl+s                        //~v5bpR~
          0x14,//    0,      //0x14  ctrl+t                        //~v5bpR~
          0x16,//    0,      //0x15  ctrl+u                        //~v5bpR~
          0x2f,//    0,      //0x16  ctrl+v                        //~v5bpR~
          0x11,//    0,      //0x17  ctrl+w                        //~v5bpR~
          0x2d,//    0,      //0x18  ctrl+x                        //~v5bpR~
          0x15,//    0,      //0x19  ctrl+y                        //~v5bpR~
          0x2c,//    0,      //0x1a  ctrl+z                        //~v5bpR~
                    0x01/*1b*/,  //0x1b  Escape                    //~v324R~
//                   0,      //0x1c                                //~v5mdR~
//                   0,      //0x1d                                //~v5mdR~
//                   0,      //0x1e                                //~v5mdR~
//                   0       //0x1f                                //~v5mdR~
                  0x7d,      //0x1c     C+"\"                      //~v5mdI~
                  0x2b,      //0x1d     C+"]"                      //~v5mdI~
                  0x07,      //0x1e     C+"6"                      //~v5mdI~
                  0x0c       //0x1f     C+"-"(at fc5 windows mgr intercept)//~v5mdI~
                     };                                            //~v324R~
                                                                   //~v324I~
static struct  kbdiacr Skatakanalist[]={                           //~v386R~
                {DEADKEY_KATAKANA,'1','ﾇ'},
                {DEADKEY_KATAKANA,'2','ﾌ'},
                {DEADKEY_KATAKANA,'3','ｱ'},
                {DEADKEY_KATAKANA,'#','ｧ'},  //komoji
                {DEADKEY_KATAKANA,'4','ｳ'},
                {DEADKEY_KATAKANA,'$','ｩ'},  //komoji
                {DEADKEY_KATAKANA,'5','ｴ'},
                {DEADKEY_KATAKANA,'%','ｪ'},  //komoji
                {DEADKEY_KATAKANA,'6','ｵ'},
                {DEADKEY_KATAKANA,'&','ｫ'},  //komoji
                {DEADKEY_KATAKANA,'7','ﾔ'},
                {DEADKEY_KATAKANA,'\'','ｬ'}, //komoji
                {DEADKEY_KATAKANA,'8','ﾕ'},
                {DEADKEY_KATAKANA,'(','ｭ'},  //komoji
                {DEADKEY_KATAKANA,'9','ﾖ'},
                {DEADKEY_KATAKANA,')','ｮ'},  //komoji
                {DEADKEY_KATAKANA,'0','ﾜ'},
                {DEADKEY_KATAKANA,'-','ﾎ'},
                {DEADKEY_KATAKANA,'^','ﾍ'},

                {DEADKEY_KATAKANA,'q','ﾀ'},
                {DEADKEY_KATAKANA,'w','ﾃ'},
                {DEADKEY_KATAKANA,'e','ｲ'},
                {DEADKEY_KATAKANA,'E','ｨ'},   //komiji
                {DEADKEY_KATAKANA,'r','ｽ'},
                {DEADKEY_KATAKANA,'t','ｶ'},
                {DEADKEY_KATAKANA,'y','ﾝ'},
                {DEADKEY_KATAKANA,'u','ﾅ'},
                {DEADKEY_KATAKANA,'i','ﾆ'},
                {DEADKEY_KATAKANA,'o','ﾗ'},
                {DEADKEY_KATAKANA,'p','ｾ'},

                {DEADKEY_KATAKANA,'a','ﾁ'},
                {DEADKEY_KATAKANA,'s','ﾄ'},
                {DEADKEY_KATAKANA,'d','ｼ'},
                {DEADKEY_KATAKANA,'f','ﾊ'},
                {DEADKEY_KATAKANA,'g','ｷ'},
                {DEADKEY_KATAKANA,'h','ｸ'},
                {DEADKEY_KATAKANA,'j','ﾏ'},
                {DEADKEY_KATAKANA,'k','ﾉ'},
                {DEADKEY_KATAKANA,'l','ﾘ'},
                {DEADKEY_KATAKANA,';','ﾚ'},
                {DEADKEY_KATAKANA,':','ｹ'},
                {DEADKEY_KATAKANA,']','ﾑ'},

                {DEADKEY_KATAKANA,'z','ﾂ'},
                {DEADKEY_KATAKANA,'Z','ｯ'},  //komoji
                {DEADKEY_KATAKANA,'x','ｻ'},
                {DEADKEY_KATAKANA,'c','ｿ'},
                {DEADKEY_KATAKANA,'v','ﾋ'},
                {DEADKEY_KATAKANA,'b','ｺ'},
                {DEADKEY_KATAKANA,'n','ﾐ'},
                {DEADKEY_KATAKANA,'m','ﾓ'},
                {DEADKEY_KATAKANA,',','ﾈ'},
                {DEADKEY_KATAKANA,'.','ﾙ'},
                {DEADKEY_KATAKANA,'/','ﾒ'},
                {DEADKEY_KATAKANA,'\\','ﾛ'}
               };
static struct  kbdiacrs Scompose={sizeof(Skatakanalist)/sizeof(Skatakanalist[0])};//~v386R~

//*Fxx and doskey code assingn to Funckey with modifier
static  FUNCKEYTBL Sfkt_F1    ={"F1" ,K_F1 ,{K_F1 ,K_F13,K_F25,K_F37},{0x3b00,0x5400,0x5e00,0x6800}};//~v3a1R~
static  FUNCKEYTBL Sfkt_F2    ={"F2" ,K_F2 ,{K_F2 ,K_F14,K_F26,K_F38},{0x3c00,0x5500,0x5f00,0x6900}};//~v3a1R~
static  FUNCKEYTBL Sfkt_F3    ={"F3" ,K_F3 ,{K_F3 ,K_F15,K_F27,K_F39},{0x3d00,0x5600,0x6000,0x6a00}};//~v3a1R~
static  FUNCKEYTBL Sfkt_F4    ={"F4" ,K_F4 ,{K_F4 ,K_F16,K_F28,K_F40},{0x3e00,0x5700,0x6100,0x6b00}};//~v3a1R~
static  FUNCKEYTBL Sfkt_F5    ={"F5" ,K_F5 ,{K_F5 ,K_F17,K_F29,K_F41},{0x3f00,0x5800,0x6200,0x6c00}};//~v3a1R~
static  FUNCKEYTBL Sfkt_F6    ={"F6" ,K_F6 ,{K_F6 ,K_F18,K_F30,K_F42},{0x4000,0x5900,0x6300,0x6d00}};//~v3a1R~
static  FUNCKEYTBL Sfkt_F7    ={"F7" ,K_F7 ,{K_F7 ,K_F19,K_F31,K_F43},{0x4100,0x5a00,0x6400,0x6e00}};//~v3a1R~
static  FUNCKEYTBL Sfkt_F8    ={"F8" ,K_F8 ,{K_F8 ,K_F20,K_F32,K_F44},{0x4200,0x5b00,0x6500,0x6f00}};//~v3a1R~
static  FUNCKEYTBL Sfkt_F9    ={"F9" ,K_F9 ,{K_F9 ,K_F21,K_F33,K_F45},{0x4300,0x5c00,0x6600,0x7000}};//~v3a1R~
static  FUNCKEYTBL Sfkt_F10   ={"F10",K_F10,{K_F10,K_F22,K_F34,K_F46},{0x4400,0x5d00,0x6700,0x7100}};//~v3a1R~
static  FUNCKEYTBL Sfkt_F11   ={"F11",K_F11,{K_F11,K_F23,K_F35,K_F47},{0x8500,0x8700,0x8900,0x8b00}};//~v3a1R~
static  FUNCKEYTBL Sfkt_F12   ={"F12",K_F12,{K_F12,K_F24,K_F36,K_F48},{0x8600,0x8800,0x8a00,0x8c00}};//~v3a1R~

static  FUNCKEYTBL Sfkt_FIND  ={"Home"  ,K_FIND  ,{K_FIND  ,K_F49,K_F50,K_F51},{0x4700,0x4700,0x7700,0x9700}};//Home//~v3a1R~
static  FUNCKEYTBL Sfkt_SELECT={"End"   ,K_SELECT,{K_SELECT,K_F52,K_F53,K_F54},{0x4f00,0x4f00,0x7500,0x9f00}};//End//~v3a1R~
//static  FUNCKEYTBL Sfkt_INSERT={"Ins"   ,K_INSERT,{K_INSERT,K_F55,K_F56,K_F57},{0x5200,0x5200,0x9200,0xa200}};//~v586R~
static  FUNCKEYTBL Sfkt_INSERT={"Insert",K_INSERT,{K_INSERT,K_F55,K_F56,K_F57},{0x5200,0x5200,0x9200,0xa200}};//~v586I~
//static  FUNCKEYTBL Sfkt_REMOVE={"Del"   ,K_REMOVE,{K_REMOVE,K_F58,K_F59,K_F60},{0x5300,0x5300,0x9300,0xa300}};//~v586R~
static  FUNCKEYTBL Sfkt_REMOVE={"Delete",K_REMOVE,{K_REMOVE,K_F58,K_F59,K_F60},{0x5300,0x5300,0x9300,0xa300}};//~v586I~
//static  FUNCKEYTBL Sfkt_PGUP  ={"PgUp"  ,K_PGUP  ,{K_PGUP  ,K_F61,K_F62,K_F63},{0x4900,0x4900,0x8400,0x9900}};//~v586R~
static  FUNCKEYTBL Sfkt_PGUP  ={"PageUp",K_PGUP  ,{K_PGUP  ,K_F61,K_F62,K_F63},{0x4900,0x4900,0x8400,0x9900}};//~v586I~
//static  FUNCKEYTBL Sfkt_PGDN  ={"PgDn"  ,K_PGDN  ,{K_PGDN  ,K_F64,K_F65,K_F66},{0x5100,0x5100,0x7600,0xa100}};//~v586R~
static  FUNCKEYTBL Sfkt_PGDN  ={"PageDown",K_PGDN  ,{K_PGDN  ,K_F64,K_F65,K_F66},{0x5100,0x5100,0x7600,0xa100}};//~v586I~
static  FUNCKEYTBL Sfkt_UP    ={"Up"    ,K_UP    ,{K_F67,K_F68,K_F69,K_F70},{0x4800,0x4800,0x8d00,0x9800}};//~v3a1R~
static  FUNCKEYTBL Sfkt_DOWN  ={"Down"  ,K_DOWN  ,{K_F71,K_F72,K_F73,K_F74},{0x5000,0x5000,0x9100,0xa000}};//~v3a1R~
static  FUNCKEYTBL Sfkt_LEFT  ={"Left"  ,K_LEFT  ,{K_F75,K_F76,K_F77,K_F78},{0x4b00,0x4b00,0x7300,0x9b00}};//~v3a1R~
static  FUNCKEYTBL Sfkt_RIGHT ={"Right" ,K_RIGHT ,{K_F79,K_F80,K_F81,K_F82},{0x4d00,0x4d00,0x7400,0x9d00}};//~v3a1R~

static  FUNCKEYTBL Sfkt_ESCAPE={"Esc"   ,CH_ESCAPE,{0    ,K_F83,K_F84,0    },{0x011b,0x011b,0x011b,0x0100}};//~v3a1R~
//static  FUNCKEYTBL Sfkt_BS    ={CH_BACKSP,{K_F85,K_F86,K_F87,0    },{0x0e08,0x0e08,0x0e7f,0x0e00}};//~v324R~
//static  FUNCKEYTBL Sfkt_BS    ={CH_BACKSP,{0    ,K_F86,K_F87,0    },{0x0e08,0x0e08,0x0e7f,0x0e00}};//~v427R~
//static  FUNCKEYTBL Sfkt_BS    ={"BS"    ,CH_BACKSP,{0    ,K_F86,K_F87,K(KT_META,CH_BACKSP)},{0x0e08,0x0e08,0x0e7f,0x0e00}};//~v586R~
static  FUNCKEYTBL Sfkt_BS    ={"BackSpace",CH_BACKSP,{0    ,K_F86,K_F87,K(KT_META,CH_BACKSP)},{0x0e08,0x0e08,0x0e7f,0x0e00}};//~v586I~
static  FUNCKEYTBL Sfkt_TAB   ={"Tab"   ,'\t'     ,{0    ,K_F88,K_F89,0    },{0x0f09,0x0f00,0x9400,0xa500}};//~v3a1R~
static  FUNCKEYTBL Sfkt_ENTER ={"Enter" ,K_ENTER  ,{0    ,K_F90,K_F91,0    },{0x1c0d,0x1c0d,0x1c0a,0x1c00}};//~v3a1R~
//static  FUNCKEYTBL Sfkt_PENTER={"Penter",K_PENTER ,{K_F92,K_F93,K_F94,K_F95},{0xe00d,0xe00d,0xe00a,0xa600}};//~v586R~
static  FUNCKEYTBL Sfkt_PENTER={"KP_Enter",K_PENTER ,{K_F92,K_F93,K_F94,K_F95},{0xe00d,0xe00d,0xe00a,0xa600}};//~v586R~
                                                                   //~v324R~
static  FUNCKEYTBL Sfkt_H     ={"h"     ,'h'      ,{0    ,0    ,K_F96,0    },{0x2368,0x2348,0x2308,0x2300}};//BS//~v3a1R~
static  FUNCKEYTBL Sfkt_I     ={"i"     ,'i'      ,{0    ,0    ,K_F97,0    },{0x1769,0x1749,0x1709,0x1700}};//TAB//~v3a1R~
static  FUNCKEYTBL Sfkt_M     ={"m"     ,'m'      ,{0    ,0    ,K_F98,0    },{0x326d,0x324d,0x320d,0x3200}};//ENTER//~v3a1R~
static  FUNCKEYTBL Sfkt_LBRCT ={"["     ,'['      ,{0    ,0    ,K_F99,0    },{0x1b5b,0x1b7b,0x1b1b,0x1b00}};//ESC//~v3a1R~
                                                                   //~v324I~
//static  FUNCKEYTBL Sfkt_2     ={'2'      ,{0    ,0    ,K_F100,0   },{0x0332,0x0322,0x0300,0x7900}};//ESC//~v57RR~
static  FUNCKEYTBL Sfkt_2     ={"2"     ,'2'      ,{0    ,0    ,K_F100,0   },{0x0332,0x0322,0x0300,0x7900}};//ESC//~v57RI~
                                                                   //~v39eI~
//static  FUNCKEYTBL Sfkt_P0    ={K_P0     ,{0    ,0    ,K_F101,0   },{0x5230,0x5200,0x9200,0     }};//~v39JR~
//static  FUNCKEYTBL Sfkt_P1    ={K_P1     ,{0    ,0    ,K_F102,0   },{0x4f31,0x4f00,0x7500,0     }};//~v39JR~
//static  FUNCKEYTBL Sfkt_P2    ={K_P2     ,{0    ,0    ,K_F103,0   },{0x5032,0x5000,0x9100,0     }};//~v39JR~
//static  FUNCKEYTBL Sfkt_P3    ={K_P3     ,{0    ,0    ,K_F104,0   },{0x5133,0x5100,0x7600,0     }};//~v39JR~
//static  FUNCKEYTBL Sfkt_P4    ={K_P4     ,{0    ,0    ,K_F105,0   },{0x4b34,0x4b00,0x7300,0     }};//~v39JR~
//static  FUNCKEYTBL Sfkt_P5    ={K_P5     ,{0    ,0    ,K_F106,0   },{0x4c35,0x4c00,0x8f00,0     }};//~v39JR~
//static  FUNCKEYTBL Sfkt_P6    ={K_P6     ,{0    ,0    ,K_F107,0   },{0x4d36,0x4d00,0x7400,0     }};//~v39JR~
//static  FUNCKEYTBL Sfkt_P7    ={K_P7     ,{0    ,0    ,K_F108,0   },{0x4737,0x4700,0x7700,0     }};//~v39JR~
//static  FUNCKEYTBL Sfkt_P8    ={K_P8     ,{0    ,0    ,K_F109,0   },{0x4838,0x4800,0x8d00,0     }};//~v39JR~
//static  FUNCKEYTBL Sfkt_P9    ={K_P9     ,{0    ,0    ,K_F110,0   },{0x4939,0x4900,0x8400,0     }};//~v39JR~
static  FUNCKEYTBL Sfkt_P0    ={"P0"       ,K_P0     ,{0    ,0    ,K_F101,0   },{0x5230,0x5200,0x9200,0     }};//~v515R~
static  FUNCKEYTBL Sfkt_P1    ={"P1"       ,K_P1     ,{0    ,0    ,K_F102,0   },{0x4f31,0x4f00,0x7500,0     }};//~v515R~
static  FUNCKEYTBL Sfkt_P2    ={"P2"       ,K_P2     ,{0    ,0    ,K_F103,0   },{0x5032,0x5000,0x9100,0     }};//~v515R~
static  FUNCKEYTBL Sfkt_P3    ={"P3"       ,K_P3     ,{0    ,0    ,K_F104,0   },{0x5133,0x5100,0x7600,0     }};//~v515R~
static  FUNCKEYTBL Sfkt_P4    ={"P4"       ,K_P4     ,{0    ,0    ,K_F105,0   },{0x4b34,0x4b00,0x7300,0     }};//~v515R~
//static  FUNCKEYTBL Sfkt_P5    ={"P5"       ,K_P5     ,{0    ,0    ,K_F106,0   },{0x4c35,0x4c00,0x8f00,0     }};//~v5ipR~
static  FUNCKEYTBL Sfkt_P5    ={"P5"       ,K_P5     ,{0    ,0    ,K_F106,0   },{0x4c00,0x0035,0x8f00,0     }};//~v5ipI~
static  FUNCKEYTBL Sfkt_P6    ={"P6"       ,K_P6     ,{0    ,0    ,K_F107,0   },{0x4d36,0x4d00,0x7400,0     }};//~v515R~
static  FUNCKEYTBL Sfkt_P7    ={"P7"       ,K_P7     ,{0    ,0    ,K_F108,0   },{0x4737,0x4700,0x7700,0     }};//~v515R~
static  FUNCKEYTBL Sfkt_P8    ={"P8"       ,K_P8     ,{0    ,0    ,K_F109,0   },{0x4838,0x4800,0x8d00,0     }};//~v515R~
static  FUNCKEYTBL Sfkt_P9    ={"P9"       ,K_P9     ,{0    ,0    ,K_F110,0   },{0x4939,0x4900,0x8400,0     }};//~v515R~
//static  FUNCKEYTBL Sfkt_PPLUS ={"P+"       ,K_PPLUS  ,{0    ,0    ,K_F111,0   },{0x4e2b,0x4e2b,0x9000,0     }};//~v58cR~
//static  FUNCKEYTBL Sfkt_PMINUS={"P-"       ,K_PMINUS ,{0    ,0    ,K_F112,0   },{0x4a2d,0x4a2d,0x8e00,0     }};//~v58cR~
//static  FUNCKEYTBL Sfkt_PSTAR ={"P*"       ,K_PSTAR  ,{0    ,0    ,K_F114,0   },{0x372a,0x372a,0x9600,0     }};//~v58cR~
//static  FUNCKEYTBL Sfkt_PSLASH={"P/"       ,K_PSLASH ,{0    ,0    ,K_F115,0   },{0x352f,0x342f,0x9500,0     }};//~v58cR~
static  FUNCKEYTBL Sfkt_PPLUS ={"P+"       ,K_PPLUS  ,{0    ,0    ,K_F111,0   },{0x4e2b,0x4e2b,0x9000,0x4e00}};//~v58cI~
static  FUNCKEYTBL Sfkt_PMINUS={"P-"       ,K_PMINUS ,{0    ,0    ,K_F112,0   },{0x4a2d,0x4a2d,0x8e00,0x4a00}};//~v58cI~
static  FUNCKEYTBL Sfkt_PSTAR ={"P*"       ,K_PSTAR  ,{0    ,0    ,K_F114,0   },{0x372a,0x372a,0x9600,0x3700}};//~v58cI~
static  FUNCKEYTBL Sfkt_PSLASH={"P/"       ,K_PSLASH ,{0    ,0    ,K_F115,0   },{0x352f,0x342f,0x9500,0xa400}};//~v58cI~
//staticFUNCKEYTBL Sfkt_PCOMMA={K_PCOMMA ,{0    ,0    ,K_F115,0   },{0xe02c,0xe02c,0xffff,0     }};//~v39iR~
//static  FUNCKEYTBL Sfkt_PDOT  ={K_PDOT   ,{0    ,0    ,K_F116,0   },{0x532e,0x5300,0x9300,0     }};//~v39JR~
static  FUNCKEYTBL Sfkt_PDOT  ={"P."       ,K_PDOT   ,{0    ,0    ,K_F116,0   },{0x532e,0x5300,0x9300,0     }};//~v515R~
static  FUNCKEYTBL Sfkt_RCTL  ={"R-Ctl"    ,K_CTRLR  ,{K_F117,0   ,0     ,0   },{RCTLID,RCTLID,RCTLID,RCTLID}};//same as enter//~v5mvR~
#define RCTL_ASSIGN    0    //func/string set on plain map for TTYLCONS mode//~v5mvI~
                                                                   //~v39iI~
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
         PFKTGEN(PENTER),                                          //~v324R~
                                                                   //~v324I~
         PFKTGEN(H     ),                                          //~v324I~
         PFKTGEN(I     ),                                          //~v324I~
         PFKTGEN(M     ),                                          //~v324I~
         PFKTGEN(LBRCT ),                                          //~v39eR~
                                                                   //~v39eI~
         PFKTGEN(2     ),                                          //~v57RR~
                                                                   //~v39iI~
//         PFKTGEN(P0    ),                                        //~v39JR~
//         PFKTGEN(P1    ),                                        //~v39JR~
//         PFKTGEN(P2    ),                                        //~v39JR~
//         PFKTGEN(P3    ),                                        //~v39JR~
//         PFKTGEN(P4    ),                                        //~v39JR~
//         PFKTGEN(P5    ),                                        //~v39JR~
//         PFKTGEN(P6    ),                                        //~v39JR~
//         PFKTGEN(P7    ),                                        //~v39JR~
//         PFKTGEN(P8    ),                                        //~v39JR~
//         PFKTGEN(P9    ),                                        //~v39JR~
         PFKTGEN(P0    ),                                          //~v515R~
         PFKTGEN(P1    ),                                          //~v515R~
         PFKTGEN(P2    ),                                          //~v515R~
         PFKTGEN(P3    ),                                          //~v515R~
         PFKTGEN(P4    ),                                          //~v515R~
         PFKTGEN(P5    ),                                          //~v515R~
         PFKTGEN(P6    ),                                          //~v515R~
         PFKTGEN(P7    ),                                          //~v515R~
         PFKTGEN(P8    ),                                          //~v515R~
         PFKTGEN(P9    ),                                          //~v515R~
         PFKTGEN(PPLUS ),                                          //~v39iI~
         PFKTGEN(PMINUS),                                          //~v39iI~
         PFKTGEN(PSTAR ),                                          //~v39iI~
         PFKTGEN(PSLASH)                                           //~v39JR~
//         PFKTGEN(PDOT  )                                         //~v39JR~
        ,PFKTGEN(PDOT  )                                           //~v515R~
        ,PFKTGEN(RCTL  )                                           //~v5mvR~
                                                                   //~v39iI~
         };
#define PFKTNO (sizeof(Spfktbl)/sizeof(Spfktbl[0]))
//***********************************************************
//*Fxx assign to modifier level
#define FSTGEN(funcname,modifier)       \
            {&Sfkt_##funcname,modifier}
#define FSTGEN2(funcname)       \
            FSTGEN(funcname,MODX_SHIFT),        \
            FSTGEN(funcname,MODX_CONTROL)
#define FSTGEN3(funcname)       \
            FSTGEN(funcname,MODX_SHIFT),        \
            FSTGEN(funcname,MODX_CONTROL),      \
            FSTGEN(funcname,MODX_ALT)
#define FSTGEN4(funcname)       \
            FSTGEN(funcname,MODX_PLAIN),        \
            FSTGEN(funcname,MODX_SHIFT),        \
            FSTGEN(funcname,MODX_CONTROL),      \
            FSTGEN(funcname,MODX_ALT)
#define FSTGEN12(modifier)       \
            FSTGEN(F1 ,modifier),  \
            FSTGEN(F2 ,modifier),  \
            FSTGEN(F3 ,modifier),  \
            FSTGEN(F4 ,modifier),  \
            FSTGEN(F5 ,modifier),  \
            FSTGEN(F6 ,modifier),  \
            FSTGEN(F7 ,modifier),  \
            FSTGEN(F8 ,modifier),  \
            FSTGEN(F9 ,modifier),  \
            FSTGEN(F10,modifier),  \
            FSTGEN(F11,modifier),  \
            FSTGEN(F12,modifier)

static FUNCSTRTBL Sstrtbl[]={   //string::symbol+modifier
                FSTGEN12(0),           //f1-f12
                FSTGEN12(MODX_SHIFT),
                FSTGEN12(MODX_CONTROL),
                FSTGEN12(MODX_ALT),

                FSTGEN4(FIND),         //plain,shift,ctrl,alt
                FSTGEN4(SELECT),
                FSTGEN4(INSERT),
                FSTGEN4(REMOVE),
                FSTGEN4(PGUP),
                FSTGEN4(PGDN),
                FSTGEN4(UP),
                FSTGEN4(DOWN),
                FSTGEN4(LEFT),
                FSTGEN4(RIGHT),

                FSTGEN2(ESCAPE),           //shft,ctrl
                FSTGEN2(BS),
                FSTGEN2(TAB),
                FSTGEN2(ENTER),
                FSTGEN4(PENTER),           //plain,shift,ctrl,alt  //~v324R~
                                                                   //~v324I~
            	FSTGEN(H,MODX_CONTROL),                            //~v324I~
            	FSTGEN(I,MODX_CONTROL),                            //~v324I~
            	FSTGEN(M,MODX_CONTROL),                            //~v324I~
            	FSTGEN(LBRCT,MODX_CONTROL),                        //~v39eR~
                                                                   //~v39eI~
                FSTGEN(2,MODX_CONTROL),                            //~v57RR~
                                                                   //~v39iI~
////              FSTGEN(P0    ,MODX_CONTROL),                     //~v39JR~
//                FSTGEN(P0    ,MODX_CONTROL),                     //~v39JR~
//                FSTGEN(P1    ,MODX_CONTROL),                     //~v39JR~
//                FSTGEN(P2    ,MODX_CONTROL),                     //~v39JR~
//                FSTGEN(P3    ,MODX_CONTROL),                     //~v39JR~
//                FSTGEN(P4    ,MODX_CONTROL),                     //~v39JR~
//                FSTGEN(P5    ,MODX_CONTROL),                     //~v39JR~
//                FSTGEN(P6    ,MODX_CONTROL),                     //~v39JR~
//                FSTGEN(P7    ,MODX_CONTROL),                     //~v39JR~
//                FSTGEN(P8    ,MODX_CONTROL),                     //~v39JR~
//                FSTGEN(P9    ,MODX_CONTROL),                     //~v39JR~
                FSTGEN(P0    ,MODX_CONTROL),                       //~v515R~
                FSTGEN(P1    ,MODX_CONTROL),                       //~v515R~
                FSTGEN(P2    ,MODX_CONTROL),                       //~v515R~
                FSTGEN(P3    ,MODX_CONTROL),                       //~v515R~
                FSTGEN(P4    ,MODX_CONTROL),                       //~v515R~
                FSTGEN(P5    ,MODX_CONTROL),                       //~v515R~
                FSTGEN(P6    ,MODX_CONTROL),                       //~v515R~
                FSTGEN(P7    ,MODX_CONTROL),                       //~v515R~
                FSTGEN(P8    ,MODX_CONTROL),                       //~v515R~
                FSTGEN(P9    ,MODX_CONTROL),                       //~v515R~
                FSTGEN(PPLUS ,MODX_CONTROL),                       //~v39iI~
                FSTGEN(PMINUS,MODX_CONTROL),                       //~v39iI~
                FSTGEN(PSTAR ,MODX_CONTROL),                       //~v39iI~
                FSTGEN(PSLASH,MODX_CONTROL)                        //~v39JR~
//                FSTGEN(PDOT  ,MODX_CONTROL)                      //~v39JR~
               ,FSTGEN(PDOT  ,MODX_CONTROL)                        //~v515R~
               ,FSTGEN(RCTL  ,0           )        //for console mode setfuncstring//~v5mvR~
                };
#define FSTNO (sizeof(Sstrtbl)/sizeof(Sstrtbl[0]))
static int Sstrtmap[256][4];	//index of strtbl indexed by scancode//~v39JR~
//*                                                                //~v324I~
static int Skeycode_symid[NR_KEYS];     //symid for all keycode
//*curses key table                                                //~v324I~
#define CKTNO (FSTNO*FKT_MAX_STR)                                  //~v57NI~
//static CURSESKEYTBL Scurseskeytbl[FSTNO];                        //~v57NR~
static CURSESKEYTBL Scurseskeytbl[CKTNO];                          //~v57NI~
static int          Scktno;             //count of to use terminfo string//~v324I~
static int          Seventctr=0;        //kbd or mouse event ctr   //~v592I~
static int          Smouseeventctr=-2;        //kbd or mouse event ctr//~v592I~
static int          Skbdopt;                                       //~v6qhI~
//*********************************************************************
void ukbdlnxc_optproc(int Popt,unsigned char *);                   //~v384R~
void ukbdlnxc_termexit(int Psigno);                                 //~v324R~
int ukbdlnxc_readkbd(char *Pout,int *Pmodifier,int Ppeeksw);       //~v50zR~
void ukbdlnxc_cleanup(int Prestoresw);
//int  ukbdlnxc_getplainsym(void);                                 //~v57YR~
int  ukbdlnxc_getplainsym(int Popt);                               //~v57YI~
void ukbdlnxc_chkothersym(void);                                   //~v57RI~
//int  ukbdlnxc_xbsdel(void);                                      //~v57YR~
int  ukbdlnxc_xbsdel(int Popt);                                    //~v57YI~
int  ukbdlnxc_delopt(int Popt);                                    //~v57YI~
void ukbdlnxc_setcompose(int Prestoresw);
void ukbdlnxc_setfunckey(int Prestoresw);
void ukbdlnxc_setfuncstr(int Prestoresw);
//int  ukbdlnxc_getkeysym(int Pkeycode,int Pkeymap);               //~v57NR~
void ukbdlnxc_setkeysym(int Pkeycode,int Pkeymap,int Psymid);
char *ukbdlnxc_getstring(int Psymid);
void ukbdlnxc_setstring(int Psymid,char *Pstr);
void ukbdlnxc_getdiacr(struct kbdiacrs *Pkd);
void ukbdlnxc_setdiacr(struct kbdiacrs *Pkd);
int ukbdlnxc_setmetamode(int Prestoresw);
int ukbdlnxc_getconsole(int *Ppttyfd);                             //~v39ZR~
int ukbdlnxc_open(char *Pname);
int ukbdlnxc_chkconsole(int Pfd);
void ukbdlnxc_setupckt(void);                                      //~v324R~
void ukbdlnxc_setupcktx(void);                                     //~v57NI~
void ukbdlnxc_addstrtbl(int Popt,int Pflag,char *Pstring,FUNCKEYTBL *Ppfkt,int Pmodx,int len);//~v57NI~
#define ADDSTT_CLEARASSIGN  0x01                                   //~v57NI~
#define ADDSTT_RCTL         0x02    //add rctl string              //~v5mvI~
int ukbdlnxc_dupstrchk(char *Pstring,FUNCKEYTBL *Ppfkt,int Pmodx,int Plen);//~v57NI~
int ukbdlnxc_save1st(void);                                        //~v386I~
int ukbdlnxc_restorelast(void);                                    //~v386I~
int ukbdlnxc_lockfwrite(void *Paddr,int Plen);                     //~v386I~
int ukbdlnxc_lockfread(void *Paddr,int Plen);                      //~v386I~
int ukbdlnxc_pidsetlock(void);                                     //~v386I~
int ukbdlnxc_pidresetlock(void);                                   //~v386I~
int ukbdlnxc_pidchklock(void);                                     //~v386I~
//*********************************************************************//~v324I~
//*********************************************************************//~v3a1I~
//* return pfktbl addr                                             //~v3a1I~
//*********************************************************************//~v3a1I~
int ukbdlnxc_gettbl(PFUNCKEYTBL **Pppfkt,int *Ppfktno,             //~v3a1R~
					char **Ppreadbuff,int **Ppreadlen)             //~v3a1I~
{                                                                  //~v3a1I~
	if (Pppfkt)                                                    //~v3a1R~
		*Pppfkt=Spfktbl;                                           //~v3a1R~
	if (Ppfktno)                                                   //~v3a1R~
    	*Ppfktno=PFKTNO;                                           //~v3a1R~
	if (Ppreadbuff)                                                //~v3a1I~
//  	*Ppreadbuff=Sbuff;                                         //~v55wR~
    	*Ppreadbuff=Sorgbuff;                                      //~v55wI~
	if (Ppreadlen)                                                 //~v3a1I~
		*Ppreadlen=&Sreadlen;                                      //~v3a1R~
    return 0;                                                      //~v3a1R~
}//ukbdlnxc_gettbl                                                 //~v3a1R~
//*********************************************************************
//* kbd init
//* parm1:option by -- flag parm (and default)                     //~v384I~
//* parm2:Fn key assign table for xe with shift modifier           //~v384I~
//* return fd                                                      //~v39bI~
//*********************************************************************
int ukbdlnxc_init(int Popt,unsigned char *Passignkey)              //~v384R~
{
//*******************************
    if (Skbdinitsw)	//second time                                  //~v324R~
    	return Sfd;                                                //~v39bR~
    Skbdopt=Popt;                                                  //~v6qhI~
    Skbdinitsw=1;                                                  //~v324I~
    Stermid=ukbdl_gettermid();                                     //~v501I~
  	Stermnameid=Stermid & TERM_IDMASK;                             //~v57NI~
	Scursessw=Popt & UKBDL_CURSES;                                 //~v589R~
    ukbdlnxc_optproc(Popt,Passignkey);                             //~v384R~
    Sfd=ukbdlnxc_getconsole(&Sfdioctl);                            //~v39ZR~
    if (!Sfdioctl)   		//not under pty                        //~v39ZI~
    	Sfdioctl=Sfd;       //fd for ioctl of tty                  //~v39ZI~
    Spurr=uehl_setsh((void*)ukbdlnxc_termexit);                    //~v324R~
  if (Stermnameid==TERM_TTYLCONS)	//console                      //~v57NI~
  {                                                                //~v57NI~
//  ukbdlnxc_getplainsym();     //get symbol of plain keymap       //~v57YR~
    ukbdlnxc_getplainsym(Popt);     //get symbol of plain keymap   //~v57YI~
	ukbdlnxc_chkothersym();     //chk other sym assignment         //~v57RI~
    if (Scursessw)                                                 //~v324M~
    	ukbdlnxc_setupckt();                                       //~v324I~
    ukbdlnxc_setfunckey(0);      //assing funckey
    ukbdlnxc_setfuncstr(0);     //assing string to funckey
	ukbdlnxc_setrctl(UKBDLNXC_SRCO_SET);// reset  once rctl func(leave string)//~v5mvI~
    if (Popt & UKBDL_COMPOSE)                                      //~v589R~
        ukbdlnxc_setcompose(0);     //assing compose char
    ukbdlnxc_setmetamode(0);
    if (!Scursessw)  //uviol already set metamode                  //~v39bI~
    	ukbdl_setkbmode(0);      //set raw mode                    //~v39bR~
    ukbdlnxc_save1st();         //save old status if 1st time      //~v386I~
  }//console only                                                  //~v57NI~
  else                                                             //~v57NI~
  {                                                                //~v57NI~
#ifndef XSUB                                                       //~v6j0I~
  	ukbdlnxm_mouseinit();  //mouse init                            //~v592I~
#endif                                                             //~v6j0I~
//  ukbdlnxc_xbsdel();     //chk bs and del for 7f under X         //~v57YR~
    ukbdlnxc_xbsdel(Popt);     //chk bs and del for 7f under X     //~v57YI~
    ukbdlnxc_setupcktx(); 	//add default to curases key table for all X terminal//~v57NI~
  }//X terminal                                                    //~v57NI~
    Sreslen=0;                                                     //~v324I~
    return Sfd;                                                    //~v39bR~
}//ukbdlnxc_init
//*********************************************************************
//* kbd term
//*********************************************************************
int ukbdlnxc_term(int Prestoresw)
{
//*******************************
    if (!Skbdinitsw)                                               //~v324I~
    	return 0;                                                  //~v324I~
#ifndef XSUB                                                       //~v6j0I~
  	if (Stermnameid!=TERM_TTYLCONS)	//console                      //~v592I~
  		ukbdlnxm_mouseterm();  //mouse init                        //~v592I~
#endif                                                             //~v6j0I~
    ukbdlnxc_cleanup(Prestoresw);
    uehl_resetsh(Spurr);                                           //~v324I~
    Skbdinitsw=0;                                                  //~v324I~
    return 1;                                                      //~v398R~
}//ukbdlnxc_term                                                   //~v324R~
#ifdef UTF8SUPPH                                                   //~v629I~
//*********************************************************************//~v629I~
//* try read after 1 byte Esc read                                 //~v629I~
//* return readlen,0 if fail                                       //~v629R~
//*********************************************************************//~v629I~
int ukbdlnxc_getnext(int Pfd,char *Pbuff,int Pbuffsz)              //~v629R~
{                                                                  //~v629I~
	int rc;                                                        //~v629R~
//***********************                                          //~v629I~
	rc=uproc_select(0,Sfd,-1/*wfd*/,-1/*errfd*/,10/*milisec*/,0/*no wait child*/);//~v629I~
    if (rc>0) 	//ready                                            //~v629I~
//      rc=read(Pfd,Pbuff,Pbuffsz);                                //~v629R~//~v6D0R~
//      rc=read(Pfd,Pbuff,(size_t)Pbuffsz);                        //~v6D0I~//~v6D1R~
        rc=(int)read(Pfd,Pbuff,(size_t)Pbuffsz);                   //~v6D1I~
    rc=max(0,rc);                                                  //~v629I~
UTRACEP("ukbdlnxc_getnext rc=%d\n",rc);                            //~v629I~
UTRACED("ukbdlnxc_getnext",Pbuff,rc);                              //~v629R~
    return rc;                                                     //~v629I~
}//ukbdlnxc_getnext(void)                                          //~v629I~
#endif                                                             //~v629I~
//*********************************************************************
//* read kbd
//* Pnowait:0:read wait,1:read nowait,-1:peek                      //~v324I~
//* Pout:char+scan(even for BigEndian)                             //~v6q5I~
//* ret:outputlen 1:letter,2:extended key
//*********************************************************************
int ukbdlnxc_read(char *Pout,int *Pshiftstatus,int Pnowait)        //~v324R~
{
    int modx,rc;                                                   //~v50zR~
#ifdef UTF8SUPPH                                                   //~v62HI~
    int opt;                                                       //~v62HI~
#endif                                                             //~v62HI~
//    unsigned char *nextpos;                                      //~v50zR~
	int swshiftreport;                                             //~v6EYI~
//************************
#ifdef UTF8SUPPH                                                   //~v62HI~
    if (Pnowait<0)     //no wait                                   //~v62HI~
        opt=UKBDLNXCO_PEEK;                                        //~v62HI~
    else                                                           //~v62HI~
        opt=Pnowait;                                               //~v62HI~
#endif                                                             //~v62HI~
    Seventctr++;    //to chk dbl click                             //~v592I~
    *Pshiftstatus=0;
//  if (!Sreslen && Pnowait)    //nowait req                       //~v50zR~
//  	return 0;				                                   //~v50zR~
//    reslen=Sreslen;                                              //~v50zR~
//    nextpos=Snextpos;                                            //~v50zR~
  for (;;)                                                         //~v5mvI~
  {                                                                //~v5mvI~
#ifdef UTF8SUPPH                                                   //~v62HI~
    rc=ukbdlnxc_readkbd(Pout,&modx,opt);                           //~v62HI~
#else                                                              //~v62HI~
    rc=ukbdlnxc_readkbd(Pout,&modx,(Pnowait<0));                   //~v50zR~//~v62HR~
#endif                                                             //~v62HI~
	if (modx & MODX_SHIFT_REPORT)	//  0x0800 //Shift+Alt or Shift+Control//~v6EYI~
    {                                                              //~v6EYI~
		modx &= ~MODX_SHIFT_REPORT;	//  0x0800 //Shift+Alt or Shift+Control//~v6EYI~
        swshiftreport=1;                                           //~v6EYI~
    }                                                              //~v6EYI~
    else                                                           //~v6EYI~
        swshiftreport=0;                                           //~v6EYI~
    if (modx==MODX_CONTROL                                         //~v5mvR~
//  &&  *(USHORT*)(ULONG)Pout==RCTLID)                             //~v5mvR~//~v5nDR~
    &&  USTR2US(Pout)==RCTLID)                                     //~v5nDI~
    {                                                              //~v5mvR~
    	if (!(Gukbdl_flag & GUKBDL_RCTLUSE))  //should be ignored  //~v5mvI~
        {                                                          //~v5mvI~
        	if (!Pnowait)                                          //~v5mvI~
            	continue;                                          //~v5mvI~
    		rc=0;                                                  //~v5mvI~
        }                                                          //~v5mvI~
    	*Pshiftstatus=Sshiftid[5];  //report CTLR                  //~v5mvR~
    }                                                              //~v5mvR~
    break;                                                         //~v5mvI~
  }                                                                //~v5mvI~
  if (!*Pshiftstatus) //not shift report case                      //~v5mvI~
  {                                                                //~v5mvI~
    *Pshiftstatus=Sshiftid[modx];                                  //~v324M~
    if (rc==2)  //with shift key                                   //~v5mfI~
    {                                                              //~v5mfI~
    	rc=1;                                                      //~v5mfI~
    	*Pshiftstatus=Sshiftid[modx]|UKBDLNXC_MOD_SHIFTL;          //~v5mfI~
    }                                                              //~v5mfI~
    if (swshiftreport)                                             //~v6EYI~
    	*Pshiftstatus|=UKBDLNXC_MOD_SHIFTL;                        //~v6EYI~
  }                                                                //~v5mvI~
//    if (Pnowait<0)  //peek req                                   //~v50zR~
//    {                                                            //~v50zR~
//        Sreslen=reslen;                                          //~v50zR~
//        Snextpos=nextpos;                                        //~v50zR~
//    }                                                            //~v50zR~
    return rc;                                                     //~v324R~
}//ukbdlnxc_read
//*********************************************************************
//* read kbd
//* ret:0:no input,1:data gotten                                   //~v324R~
//* Pout:char+scan(even for BigEndian)                             //~v6q5I~
//*********************************************************************
int ukbdlnxc_readkbd(char *Pout,int *Pmodifier,int Ppeeksw)        //~v50zR~
{
static  int Sdbcssw=0;                                             //~v57DI~
//  PFUNCKEYTBL pfkt;                                              //~v39SR~
    PCURSESKEYTBL pckt,pckte;                                      //~v324R~
    int funcno,modx,len,xwork;                                     //~v39LR~
    unsigned short code;
    int ii;                                                        //~v536I~
    int rc;                                                        //~v592I~
    struct timeval tv,*ptv;                                        //~v592I~
#define PRINTF(casen,top,len)\
    {int xx;char *pc;        \
      if (Scursessw)          \
        printw("case=%d: ",casen); \
      else                     \
        printf("case=%d: ",casen); \
        for (xx=len,pc=top;xx>0;xx--,pc++) \
      		if (Scursessw)                \
             	printw("%02x ",*pc);         \
            else                           \
             	printf("%02x ",*pc);         \
      	if (Scursessw)                      \
        	printw("\n");                      \
        else                                 \
        	printf("\n");                      \
    }                                         
#ifdef UTF8SUPPH                                                   //~v629I~
  	int nextlen;                                                   //~v629I~
#endif                                                             //~v629I~
//************************
//printf("entry reslen=%d\n",Sreslen);
    *Pmodifier=0;
    *(Pout+1)=0;	//clear scan code                              //~v324I~
    ptv=0;                                                         //~v592I~
    if (Seventctr-Smouseeventctr==1)	//previous is mouse event  //~v592R~
    	if (gettimeofday(&tv,NULL)!=-1) //time before read         //~v592R~
        	ptv=&tv;                                               //~v592R~
                                                                   //~v592I~
//  if (!Sreslen)                                                  //~v536R~
    if (Sreslen<=0)                                                //~v536I~
    {
        Snextpos=Sbuff;                                            //~v324M~
      for (ii=0;ii<10;ii++)	//try 10 times                         //~v536I~
      {                                                            //~v536I~
#ifdef UTF8SUPPH                                                   //~v62HI~
       if (Ppeeksw & UKBDLNXCO_NEXT)                               //~v62HR~
       {                                                           //~v62HI~
        nextlen=ukbdlnxc_getnext(Sfd,Sbuff,READSIZE);              //~v62HI~
        if (!nextlen)                                              //~v62HI~
        	return 0;		//read timeout                         //~v62HI~
        Sreadlen=Sreslen=nextlen;                                  //~v62HI~
       }                                                           //~v62HI~
       else                                                        //~v62HI~
#endif                                                             //~v62HI~
        Sreadlen=                                                  //~v3a1I~
//      Sreslen=read(Sfd,Sbuff,READSIZE);                          //~v324R~//~v6D1R~
        Sreslen=(int)read(Sfd,Sbuff,READSIZE);                     //~v6D1I~
//PRINTF(0,Sbuff,Sreslen);                                         //~v324R~
UTRACED("ukbdlnxc_readkbd",Sbuff,Sreadlen);                      //~v501R~//~v5nDR~
		if (Sreslen>0)                                             //~v536I~
        	break;                                                 //~v536I~
      }                                                            //~v536I~
	  if (Sreslen<=0)                                              //~v536I~
      	return 0;                                                  //~v536I~
//#ifdef UTF8SUPPH                                                   //~v629I~//~v62TR~
//        if (*Snextpos==CH_ESCAPE && Sreslen==1) //1 byte esc only  //~v629I~//~v62TR~
//        {                                                          //~v629I~//~v62TR~
//            nextlen=ukbdlnxc_getnext(Sfd,Sbuff+1,READSIZE-1);      //~v629R~//~v62TR~
//            Sreadlen+=nextlen;                                     //~v629I~//~v62TR~
//            Sreslen+=nextlen;                                      //~v629I~//~v62TR~
//        }                                                          //~v629I~//~v62TR~
//#endif                                                             //~v629I~//~v62TR~
    }
#ifdef UTF8SUPPH                                                   //~v62TI~
UTRACED("ukbdlnxc_readkbd residual data",Snextpos,Sreslen);        //~v62TI~
    if ((*Snextpos==CH_ESCAPE && Sreslen==1) //1 byte esc only     //~v62TR~
    || (((ULONG)Snextpos-(ULONG)Sbuff)>(READSIZE-TH_READNEXT))	//data may be cut by read buff size//~v62TR~
    )                                                              //~v62TI~
    {                                                              //~v62TI~
UTRACEP("ukbdlnxc_readkbd residual data shortage reslen=%d",Sreslen);//~v62TI~
    	memcpy(Sbuff,Snextpos,(UINT)Sreslen);                      //~v62TI~
    	Snextpos=Sbuff;                                            //~v62TR~
        nextlen=ukbdlnxc_getnext(Sfd,Snextpos+Sreslen,READSIZE-Sreslen);//~v62TR~
        Sreslen+=nextlen;                                          //~v62TR~
    }                                                              //~v62TI~
#endif                                                             //~v62TI~
    memcpy(Sorgbuff,Sbuff,READSIZE); //for xekbchk                 //~v55wR~
#ifdef UTF8SUPPH                                                   //~v62HI~
    if (Ppeeksw & UKBDLNXCO_PEEK)                                  //~v62HR~
#else                                                              //~v62HI~
    if (Ppeeksw)                                                   //~v50zI~//~v62HR~
#endif                                                             //~v62HI~
    	return Sreslen;                                            //~v50zI~
    if (Sdbcssw)                                                   //~v57DI~
    {                                                              //~v57DI~
        Sdbcssw=0;                                                 //~v57DI~
        *Pout=*Snextpos++;                                         //~v57DI~
        Sreslen--;                                                 //~v57DI~
        return 1;                                                  //~v57DI~
    }                                                              //~v57DI~
    while(1)
    {
        if (*Snextpos!=CH_ESCAPE||Sreslen==1)	//or esc only      //~v324R~
        {                                                          //~v324I~
//  		if (*Snextpos==CH_DELETE && Sbs_del_sw)	//0x7f by BS key//~v425R~
    		if (*Snextpos==CH_DELETE)                              //~v425I~
            {                                                      //~v425I~
              if (Sbs_del_sw)	//0x7f by BS key                   //~v425I~
            	*Snextpos=CH_BACKSP;                               //~v324I~
              else                                                 //~v425I~
			  if (Sdel_by_7f) //treate 7f as Del key               //~v425I~
              {                                                    //~v425I~
                Sreslen=0;      //processed                        //~v425I~
        		*Pmodifier=0;	//shift is not identified          //~v425I~
        		*(unsigned short *)(void*)Pout=Sfkt_REMOVE.FKTdoskey[0];//~v425I~
                IFBIG_SWAPPC2(Pout);   //swap to char+scan if BIGENDIAN//~v5nDI~
        		return 1;                                          //~v425I~
        	  }                                                    //~v425I~
            }                                                      //~v425I~
            if (*Snextpos<0x20)                                    //~v324I~
            {                                                      //~v57CI~
                if (Snormalscantbl[*Snextpos])                     //~v324I~
                {                                                  //~v324I~
                    *Pout++=*Snextpos;                             //~v324I~
                    *Snextpos=Snormalscantbl[*Snextpos];           //~v324I~
                }                                                  //~v324I~
            }                                                      //~v57CI~
            else                                                   //~v57CI~
            if (*Snextpos & 0x80)//meta bit                        //~v57CR~
            {                                                      //~v57CI~
            	if (Snonescentrytop>=0)                            //~v5mvR~
                {                                                  //~v5muI~
//* search terminfo key string tbl                                 //~v5muI~
                    for (pckt=Scurseskeytbl+Snonescentrytop,pckte=Scurseskeytbl+Scktno;pckt<pckte;pckt++)//~v5muI~
                    {                                              //~v5muI~
                        len=pckt->CKTlen;                          //~v5muI~
//                      if (Sreslen==len && !memcmp(Snextpos,pckt->CKTstring,len)) //potect string is part of normal dbcs//~v5mvR~//~v6D0R~
                        if (Sreslen==len && !memcmp(Snextpos,pckt->CKTstring,(size_t)len)) //potect string is part of normal dbcs//~v6D0I~
                        {                                          //~v5muI~
                            Sreslen-=len;                          //~v5muI~
                            Snextpos+=len;                         //~v5muI~
                            modx=pckt->CKTmodx;                    //~v5muI~
                            *Pmodifier=modx;                       //~v5muI~
                            code=pckt->CKTpfkt->FKTdoskey[modx];   //~v5muI~
                            *(unsigned short *)(void*)Pout=code;   //~v5muI~
			                IFBIG_SWAPPC2(Pout);   //swap to char+scan if BIGENDIAN//~v5nDI~
                            return 1;                              //~v5muI~
                        }                                          //~v5muI~
                    }//search loop                                 //~v5muI~
                }                                                  //~v5muI~
                if (Sreslen==1)//not dbcs meta char                //~v57CI~
                {                                                  //~v57CI~
					if (Gukbdl_flag & GUKBDL_METAMODE)	//meta is esc+x,>0x80 is char(for european)//~v5nrI~
            			break;	//returns 1 byte char code         //~v5nrI~
//                  if (Stermid & TERM_SIMID)   //X terminal sim (smeta() ignored)//~v57NR~
				  	if (Stermnameid!=TERM_TTYLCONS)	//not console  //~v57NI~
                    {                                              //~v57CR~
                        if (*Snextpos==CH_DELETE_ALT)              //~v57KI~
                        {                                          //~v57KI~
                          	if (Sbs_del_sw)   //0x7f by BS key     //~v57KI~
                            	*Snextpos=CH_BACKSP_ALT;           //~v57KI~
                          	else                                   //~v57KI~
                                if (Sdel_by_7f) //treate 7f as Del key//~v57KI~
                                {                                  //~v57KI~
                                  	Sreslen=0;      //processed    //~v57KI~
            						*Pmodifier=MODX_ALT;           //~v57KI~
                                  	*(unsigned short *)(void*)Pout=Sfkt_REMOVE.FKTdoskey[MODX_ALT];//~v57KI~
		                			IFBIG_SWAPPC2(Pout);   //swap to char+scan if BIGENDIAN//~v5nDI~
                                  	return 1;                      //~v57KI~
                                }                                  //~v57KI~
                        }                                          //~v57KI~
                        *(unsigned short *)(void *)Pout=Saltchartbl[(int)(*Snextpos&0x7f)];//~v57CI~
		                IFBIG_SWAPPC2(Pout);   //swap to char+scan if BIGENDIAN//~v5nDI~
                        Sreslen=0;                                 //~v57CI~
                        Snextpos++;                                //~v57CI~
                        return 1;                                  //~v57CI~
                    }                                              //~v57CR~
                }                                                  //~v57CI~
                else                                               //~v57DR~
                    if (Sreslen==2)//dbcs                          //~v57DR~
                    {                                              //~v57DR~
                        Sdbcssw=1;                                 //~v57DR~
                        *Pout=*Snextpos++;                         //~v57DR~
                        Sreslen=1;                                 //~v57DR~
                        return 1;                                  //~v57DR~
                    }                                              //~v57DR~
            }                                                      //~v57CI~
            break;  //letter key                                   //~v324R~
        }                                                          //~v324I~
//esc & len>1                                                      //~v592R~
        if (*(Snextpos+1)!=FUNCSTRID)    //                        //~v39LR~
        {
//mouse chk                                                        //~v592I~
#ifndef NOCURSES                                                   //~v6a0I~
            if (Sreslen>=MOUSE_ESCLEN                              //~v592I~
        	&&  *(Snextpos+1)=='['                                 //~v592R~
        	&&  *(Snextpos+2)==MOUSE_ESCID)     //esc[Mbxy fmt     //~v592I~
            {                                                      //~v592I~
		    	if (Seventctr-Smouseeventctr!=1)	//previous is mouse event//~v592R~
                	ptv=0;  //no double click chk                  //~v592I~
                if (rc=ukbdlnxm_getmouse(Sfd,ptv,&Snextpos,&Sreslen,Pout,Pmodifier),rc)//~v592R~
                {                                                  //~v592I~
                	if (rc==UKLM_RC_CLICK)                         //~v592I~
	                	Smouseeventctr=Seventctr;//next chk dblclick//~v592R~
                	return 1;                                      //~v592R~
                }//mouse event                                     //~v592I~
        	}                                   //esc[Mbxy fmt     //~v592I~
#endif                                                             //~v6a0I~
//      	if (*(Snextpos+1)==TERMINFOSTRID)   //'['              //~v3a1R~
//          {                                                      //~v3a1R~
//* search terminfo key string tbl                                 //~v324I~
    			for (pckt=Scurseskeytbl,pckte=Scurseskeytbl+Scktno;pckt<pckte;pckt++)//~v324I~
    			{                                                  //~v324I~
        			len=pckt->CKTlen;                              //~v324I~
//      			if (Sreslen>=len && !memcmp(Snextpos,pckt->CKTstring,len))//~v324R~//~v6D0R~
        			if (Sreslen>=len && !memcmp(Snextpos,pckt->CKTstring,(size_t)len))//~v6D0I~
                    {                                              //~v324I~
                        Sreslen-=len;                              //~v324I~
                        Snextpos+=len;                             //~v324I~
                        modx=pckt->CKTmodx;                        //~v324I~
                        *Pmodifier=modx;                           //~v324I~
						modx &= ~MODX_SHIFT_REPORT;	//Pmodifier was set,to access char code//~v6EYM~
                        code=pckt->CKTpfkt->FKTdoskey[modx];       //~v324I~
                        *(unsigned short *)(void*)Pout=code;       //~v324I~
		                IFBIG_SWAPPC2(Pout);   //swap to char+scan if BIGENDIAN//~v5nDI~
                        return 1;                                  //~v324R~
                    }                                              //~v324I~
                }//search loop                                     //~v324I~
//          }//esc+[                                               //~v3a1R~
//meta+                                                            //~v324I~
			if (!(Gukbdl_flag & GUKBDL_METAMODE))	//not meta is esc+x//~v50zI~
            	break;	//return 1b                                //~v50zI~
            *Pmodifier=MODX_ALT;
            Sreslen--;                                             //~v324M~
            Snextpos++;                                            //~v324M~
//*0x1b0x1b... for Alt+Funckey for PuTTY                           //~v6q4I~
            if (*Snextpos==CH_ESCAPE && Sreslen>1)                 //~v6q4I~
            {                                                      //~v6q4I~
//* search terminfo key string tbl                                 //~v6q4I~
    			for (pckt=Scurseskeytbl,pckte=Scurseskeytbl+Scktno;pckt<pckte;pckt++)//~v6q4I~
    			{                                                  //~v6q4I~
        			len=pckt->CKTlen;                              //~v6q4I~
//      			if (Sreslen>=len && !memcmp(Snextpos,pckt->CKTstring,len))//~v6q4I~//~v6D0R~
        			if (Sreslen>=len && !memcmp(Snextpos,pckt->CKTstring,(size_t)len))//~v6D0I~
                    {                                              //~v6q4I~
                        Sreslen-=len;                              //~v6q4I~
                        Snextpos+=len;                             //~v6q4I~
                        modx=pckt->CKTmodx;                        //~v6q4I~
                        if (modx)                                  //~v6q4M~
                        	*Pmodifier=modx;                       //~v6q4R~
                        else                                       //~v6q4I~
            				modx=MODX_ALT;                         //~v6q4I~
                        code=pckt->CKTpfkt->FKTdoskey[modx];       //~v6q4R~
                        *(unsigned short *)(void*)Pout=code;       //~v6q4I~
		                IFBIG_SWAPPC2(Pout);   //swap to char+scan if BIGENDIAN//~v6q4I~
                        return 1;                                  //~v6q4I~
                    }                                              //~v6q4I~
                }//search loop                                     //~v6q4I~
                continue;   //ignore 1st 0x1b                      //~v6q5I~
            }                                                      //~v6q4I~
//*for Putty end                                                   //~v6q4I~
            if (*Snextpos==CH_DELETE)                              //~v57KI~
            {                                                      //~v57KI~
                if (Sbs_del_sw)   //0x7f by BS key                 //~v57KI~
                    *Snextpos=CH_BACKSP;                           //~v57KI~
                else                                               //~v57KI~
                    if (Sdel_by_7f) //treate 7f as Del key         //~v57KI~
                    {                                              //~v57KI~
                        Sreslen=0;      //processed                //~v57KI~
                        *Pmodifier=MODX_ALT;                       //~v57KI~
                        *(unsigned short *)(void*)Pout=Sfkt_REMOVE.FKTdoskey[MODX_ALT];//~v57KI~
		                IFBIG_SWAPPC2(Pout);   //swap to char+scan if BIGENDIAN//~v5nDI~
                        return 1;                                  //~v57KI~
                    }                                              //~v57KI~
            }                                                      //~v57KI~
#ifdef AAA                                                         //~v5mfI~
        	*(unsigned short *)(void *)Pout=Saltchartbl[(int)*Snextpos];//~v324R~
#else                                                              //~v5mfI~
        	code=Saltchartbl[(int)*Snextpos];                      //~v5mfI~
            rc=1;                                                  //~v5mfI~
            if (code & 0xff)    //shft value                       //~v5mfI~
            {                                                      //~v5mfI~
                code&=0xff00;   //drop shift id                    //~v5mfR~
                rc=2;           //tell to caller                   //~v5mfR~
            }                                                      //~v5mfI~
        	*(unsigned short *)(void *)Pout=code;                  //~v5mfI~
#endif                                                             //~v5mfI~
		    IFBIG_SWAPPC2(Pout);   //swap to char+scan if BIGENDIAN//~v5nDI~
            Sreslen--;                                             //~v324I~
            Snextpos++;                                            //~v324I~
#ifdef AAA                                                         //~v5mfI~
            return 1;                                              //~v324R~
#else                                                              //~v5mfI~
            return rc;                                             //~v5mfI~
#endif                                                             //~v5mfI~
//end of not xe key                                                //~v592I~
        }
//      if (Sreslen==2)     //1b + next keyin                      //~v39LR~
        if (Sreslen<FUNC_STRLEN)	//not enough input             //~v39LI~
            break;                                                 //~v324R~
//      funcno=*(Snextpos+2);                                      //~v39LR~
//      if (funcno>FUNCSTR_SKIPSQ)                                 //~v39JR~
//          funcno--;                                              //~v39JR~
//      funcno-=FUNCSTR_START;                                     //~v39JR~
//      if (funcno<0 || funcno>=FSTNO)                             //~v39JR~
//          break;                                                 //~v39JR~
//scancode                                                         //~v39SI~
        xwork=*(Snextpos+2);                                       //~v39LI~
        if (xwork>='0' && xwork<='9')                              //~v39LI~
        	funcno=xwork-'0';                                      //~v39LI~
        else                                                       //~v39LI~
        if (xwork>='A' && xwork<='F')                              //~v39LI~
        	funcno=xwork-'A'+10;                                   //~v39LR~
        else                                                       //~v39LI~
        if (xwork>='a' && xwork<='f')                              //~v39SI~
        	funcno=xwork-'a'+10;                                   //~v39SI~
        else                                                       //~v39SI~
            break;                                                 //~v39LI~
        funcno<<=4;                                                //~v39LR~
        xwork=*(Snextpos+3);                                       //~v39LI~
        if (xwork>='0' && xwork<='9')                              //~v39LI~
        	funcno+=xwork-'0';                                     //~v39LI~
        else                                                       //~v39LI~
        if (xwork>='A' && xwork<='F')                              //~v39LI~
        	funcno+=xwork-'A'+10;                                  //~v39LR~
        else                                                       //~v39LI~
        if (xwork>='a' && xwork<='f')                              //~v39SI~
        	funcno+=xwork-'a'+10;                                  //~v39SI~
        else                                                       //~v39SI~
            break;                                                 //~v39LI~
//      code=funcno<<8;                                            //~v39SI~//~v6D0R~
        code=(USHORT)(funcno<<8);                                  //~v6D0I~
//charcode                                                         //~v39SI~
        xwork=*(Snextpos+4);                                       //~v39SI~
        if (xwork>='0' && xwork<='9')                              //~v39SI~
        	funcno=xwork-'0';                                      //~v39SI~
        else                                                       //~v39SI~
        if (xwork>='A' && xwork<='F')                              //~v39SI~
        	funcno=xwork-'A'+10;                                   //~v39SI~
        else                                                       //~v39SI~
        if (xwork>='a' && xwork<='f')                              //~v39SI~
        	funcno=xwork-'a'+10;                                   //~v39SI~
        else                                                       //~v39SI~
            break;                                                 //~v39SI~
        funcno<<=4;                                                //~v39SI~
        xwork=*(Snextpos+5);                                       //~v39SI~
        if (xwork>='0' && xwork<='9')                              //~v39SI~
        	funcno+=xwork-'0';                                     //~v39SI~
        else                                                       //~v39SI~
        if (xwork>='A' && xwork<='F')                              //~v39SI~
        	funcno+=xwork-'A'+10;                                  //~v39SI~
        else                                                       //~v39SI~
        if (xwork>='a' && xwork<='f')                              //~v39SI~
        	funcno+=xwork-'a'+10;                                  //~v39SI~
        else                                                       //~v39SI~
            break;                                                 //~v39SI~
//      code+=funcno;                                              //~v39SI~//~v6D0R~
        code=(USHORT)(code+funcno);                                //~v6D0R~
//      modx=*(Snextpos+3)-MODX_CHAR;                              //~v39LR~
//      modx=*(Snextpos+4)-'0';                                    //~v39SR~
        modx=*(Snextpos+6)-'0';                                    //~v39SI~
        if (modx<0||modx>=4)	//1:shift,2:control,3:alt          //~v39MR~
        	break;                                                 //~v39JI~
//      funcno=Sstrtmap[funcno][modx];    //index to Sstrtbl;      //~v39SR~
//      if (!funcno)				//not defined                  //~v39SR~
//      	break;                                                 //~v39SR~
//      Sreslen-=3;                                                //~v39JR~
//      Snextpos+=3;                                               //~v39JR~
        Sreslen-=FUNC_STRLEN;                                      //~v39JI~
        Snextpos+=FUNC_STRLEN;                                     //~v39JI~
//      pfkt=Sstrtbl[funcno].FSTpfkt;                              //~v39SR~
//      modx=Sstrtbl[funcno].FSTmodx;                              //~v39SR~
        *Pmodifier=modx;
//      code=pfkt->FKTdoskey[modx];                                //~v39SR~
        *(unsigned short *)(void*)Pout=code;
		IFBIG_SWAPPC2(Pout);   //swap to char+scan if BIGENDIAN    //~v5nDI~
//printf("exit1 reslen=%d\n",Sreslen);
        return 1;                                                  //~v324R~
    }
    Sreslen--;
//printf("exit2 reslen=%d\n",Sreslen);
    *Pout=*Snextpos++;
    return 1;                                                      //~v324R~
}//ukbdlnxc_readkbd                                                //~v6q5R~
//*********************************************************************
//* process option bit
//*********************************************************************
void ukbdlnxc_optproc(int Popt,unsigned char *Passignkey)          //~v384R~
{                            
    PFUNCKEYTBL pfkt;
    int ii,jj;                                                     //~v384R~
//  int pfkmask,pfkmasko;                                          //~v384I~
    unsigned char *pakt;                                           //~v384R~
//**********************************
//*pfk assign chk                                                  //~v384R~
	for (ii=0,pakt=Passignkey;ii<MAXPFKNO;ii++)                    //~v384R~
    	for (jj=0;jj<4;jj++,pakt++)                                //~v384I~
        	if (!*pakt)	//no xe assigned                           //~v384I~
            	Spfktbl[ii]->FKTfkassign[jj]=0;  //bypass key-set,str-set//~v384R~
    	                                                           //~v384I~
//*alt-R usage for all key                                         //~v324R~
    if (Popt & UKBDL_USEALTR)    //use alt-R key                   //~v589R~
        for (ii=0;ii<PFKTNO;ii++)   //copy alt-L(predefined)
        {
            pfkt=Spfktbl[ii];
            pfkt->FKTfkassign[MODX_ALTGR]=pfkt->FKTfkassign[MODX_ALT];//ALTL is predefined
            pfkt->FKTdoskey[MODX_ALTGR]=pfkt->FKTdoskey[MODX_ALT];//ALTL is predefined
        }
//*alt-L usage
    if (!(Popt & UKBDL_USEALTL))    //use alt-L key                //~v589R~
        for (ii=0;ii<PFKTNO;ii++)   //clear alt-L(predefined)
        {
            pfkt=Spfktbl[ii];
            pfkt->FKTfkassign[MODX_ALT]=0;  //clear use
            pfkt->FKTdoskey[MODX_ALT]=0;  //clear use
        }
//clear unused alt+pfk assign                                      //~v383I~
//    pfkmask=Popt & UKBDLNXC_ALTPFKMASK;                          //~v384R~
//    for (ii=0;ii<12;ii++)   //clear alt-L(predefined)            //~v384R~
//    {                                                            //~v384R~
//        pfkmasko=pfkmask;                                        //~v384R~
//        pfkmask>>=1;                                             //~v384R~
//        if ((pfkmask<<1)==pfkmasko) //bit off;xe used            //~v384R~
//        {                                                        //~v384R~
//            if (!(Popt & UKBDLNXC_USEALTL))                      //~v384R~
//                Spfktbl[ii]->FKTfkassign[MODX_ALT]=0;  //clear use//~v384R~
//            if (!(Popt & UKBDLNXC_USEALTR))                      //~v384R~
//                Spfktbl[ii]->FKTfkassign[MODX_ALTGR]=0;  //clear use//~v384R~
//        }                                                        //~v384R~
//        else                                                     //~v384R~
//        {                                                        //~v384R~
//            Spfktbl[ii]->FKTfkassign[MODX_ALT]=0;  //clear use   //~v384R~
//            Spfktbl[ii]->FKTfkassign[MODX_ALTGR]=0;  //clear use //~v384R~
//        }                                                        //~v384R~
//    }                                                            //~v384R~
    return;                                                        //~v324I~
}//ukblnxc_optproc
//*********************************************************************//~v324I~
//* setup curses key table                                         //~v324R~
//*   accept string defined on terminfo except Backspace(not Escape(1b+) but only 08 or 7f//~v324R~
//* (for common key operation with other application)              //~v324R~
//*********************************************************************//~v324I~
void ukbdlnxc_setupckt(void)                                       //~v324R~
{                                                                  //~v324I~
#ifndef NOCURSES                                                   //~v6a0R~
#define SETCKT(terminfostr,fktkey,modx)		\
		ukbdlnxc_setupcktsub(0,key_##terminfostr,&Sfkt_##fktkey,modx);//~v501R~
//#define SETCKTC(keyname,fktkey,modx)        \ //                 //~v57NR~
//        ukbdlnxc_setupcktsub(1,XT_##keyname,&Sfkt_##fktkey,modx);//~v57NR~
////following is hardcoded in xterm/kterm                          //~v57NR~
//#define XT_up     "\x1b[A"     //terminfo is \x1bOA              //~v57NR~
//#define XT_down   "\x1b[B"     //                 B              //~v57NR~
//#define XT_left   "\x1b[D"     //                 D              //~v57NR~
//#define XT_right  "\x1b[C"     //                 C              //~v57NR~
//#define XT_f1x    "\x1bOP"     //terminfo may be \x1b[11~ for xterm//~v57NR~
//#define XT_f2x    "\x1bOQ"     //                    [12~        //~v57NR~
//#define XT_f3x    "\x1bOR"     //                    [13~        //~v57NR~
//#define XT_f4x    "\x1bOS"     //                    [14~        //~v57NR~
//#define XT_f1k    "\x1b[11~"   //terminfo may be \x1bOP for kterm//~v57NR~
//#define XT_f2k    "\x1b[12~"   //                    OQ          //~v57NR~
//#define XT_f3k    "\x1b[13~"   //                    OR          //~v57NR~
//#define XT_f4k    "\x1b[14~"   //                    OS          //~v57NR~
                                                                   //~v500I~
void ukbdlnxc_setupcktsub(int Popt,char *Pterminfostr,FUNCKEYTBL *Ppfkt,int Pmodx);//~v501R~
//    int termid;                                                  //~v57NR~
//**********************************                               //~v324I~
//    if ((Stermid & TERM_SIMID)==TERM_XTERMSIM)  //under xterm sim//~v57NR~
//        termid=TERM_XTERM;  //xterm or kterm                     //~v57NR~
//    else                                                         //~v57NR~
//    if ((Stermid & TERM_SIMID)==TERM_KTERMSIM)  //under kterm sim//~v57NR~
//        termid=TERM_KTERM;  //xterm or kterm                     //~v57NR~
//    else                                                         //~v57NR~
//      if (!(Stermid & TERM_SIMID))  //not other x term sim       //~v57NR~
//        termid=(Stermid & 0xff);        //by $TERM env var       //~v57NR~
////*       term.h ,ncurses.h ,fkt                                 //~v57NR~
    SETCKT(backspace,BS   ,0);//no 08 returned                     //~v57NR~
//  SETCKT(tab      ,TAB  ,0);                                     //~v57NR~
    SETCKT(enter    ,ENTER,0);                                     //~v57NI~
//if (Stermid & TERM_XTERM)	//xterm or kterm                       //~v57wR~
//  if (termid & TERM_XTERM)  //on xterm or kterm simulater        //~v57NR~
//  {                                                              //~v57NR~
//    SETCKTC(up    ,UP    ,0)                                     //~v57NR~
//    SETCKTC(down  ,DOWN  ,0)                                     //~v57NR~
//    SETCKTC(left  ,LEFT  ,0)                                     //~v57NR~
//    SETCKTC(right ,RIGHT ,0)                                     //~v57NR~
//  }                                                              //~v57NR~
//  else                                                           //~v57NR~
//  {                                                              //~v57NR~
    SETCKT(up    ,UP    ,0)                                        //~v324R~
    SETCKT(down  ,DOWN  ,0)                                        //~v324R~
    SETCKT(left  ,LEFT  ,0)                                        //~v324R~
    SETCKT(right ,RIGHT ,0)                                        //~v324R~
//  }                                                              //~v57NR~
    SETCKT(npage ,PGDN  ,0)                                        //~v324R~
    SETCKT(ppage ,PGUP  ,0)                                        //~v324R~
  if (key_home)   //terminfo string defined                        //~v500I~
  {                                                                //~v500I~
    SETCKT(home  ,FIND  ,0)                                        //~v324R~
    SETCKT(end   ,SELECT,0)                                        //~v324R~
  }                                                                //~v500I~
  else                                                             //~v500I~
  {                                                                //~v500I~
    SETCKT(find  ,FIND  ,0)                                        //~v500I~
    SETCKT(select,SELECT,0)                                        //~v500I~
  }                                                                //~v500I~
    SETCKT(ic    ,INSERT,0)                                        //~v324R~
    SETCKT(dc    ,REMOVE,0)                                        //~v324R~
//if (Stermid==TERM_XTERM)	//xterm only                           //~v57wR~
//  if (termid==TERM_XTERM)   //xterm only                         //~v57NR~
//  {                                                              //~v57NR~
//    SETCKTC(f1x   ,F1    ,0)                                     //~v57NR~
//    SETCKTC(f2x   ,F2    ,0)                                     //~v57NR~
//    SETCKTC(f3x   ,F3    ,0)                                     //~v57NR~
//    SETCKTC(f4x   ,F4    ,0)                                     //~v57NR~
//  }                                                              //~v57NR~
//  else                                                           //~v57NR~
////if (Stermid == TERM_KTERM)    //xterm only                     //~v57NR~
//  if (termid==TERM_KTERM)   //kterm only                         //~v57NR~
//  {                                                              //~v57NR~
//    SETCKTC(f1k   ,F1    ,0)                                     //~v57NR~
//    SETCKTC(f2k   ,F2    ,0)                                     //~v57NR~
//    SETCKTC(f3k   ,F3    ,0)                                     //~v57NR~
//    SETCKTC(f4k   ,F4    ,0)                                     //~v57NR~
//  }                                                              //~v57NR~
//  else                                                           //~v57NR~
//  {                                                              //~v57NR~
    SETCKT(f1    ,F1    ,0)                                        //~v324R~
    SETCKT(f2    ,F2    ,0)                                        //~v324R~
    SETCKT(f3    ,F3    ,0)                                        //~v324R~
    SETCKT(f4    ,F4    ,0)                                        //~v324R~
//  }                                                              //~v57NR~
    SETCKT(f5    ,F5    ,0)                                        //~v324R~
    SETCKT(f6    ,F6    ,0)                                        //~v324R~
    SETCKT(f7    ,F7    ,0)                                        //~v324R~
    SETCKT(f8    ,F8    ,0)                                        //~v324R~
    SETCKT(f9    ,F9    ,0)                                        //~v324R~
    SETCKT(f10   ,F10   ,0)                                        //~v324R~
    SETCKT(f11   ,F11   ,0)   //ignore it may be S+F1-->F11        //~v324R~
    SETCKT(f12   ,F12   ,0)                                        //~v324R~
//for shift+                                                       //~v324I~
//  SETCKT(btab   ,TAB   ,MODX_SHIFT)//no 09 returned              //~v368R~
                                                                   //~v324R~
    SETCKT(sleft  ,LEFT  ,MODX_SHIFT)                              //~v324R~
    SETCKT(sright ,RIGHT ,MODX_SHIFT)                              //~v324R~
    SETCKT(shome  ,FIND  ,MODX_SHIFT)                              //~v324R~
    SETCKT(send   ,SELECT,MODX_SHIFT)                              //~v324R~
    SETCKT(sic    ,INSERT,MODX_SHIFT)                              //~v324R~
    SETCKT(sdc    ,REMOVE,MODX_SHIFT)                              //~v324R~
                                                                   //~v324I~
//#ifdef LNXLC2       //libc2 TurboLinux                           //~v39MR~
//#else                                                            //~v39MR~
////chk terminfo set S+F1 is F11                                   //~v39MR~
//    keycode=Sfkt_F1.FKTkeycode;                                  //~v39MR~
//    symid=ukbdlnxc_getkeysym(keycode,MODX_SHIFT); //symid of S+F1//~v39MR~
//    if (!(symid==K_F11 && Sfkt_F11.FKTkeycode)) //not S+F1-->F11 & F11 defined//~v39MR~
//    {                                                            //~v39MR~
        SETCKT(f13    ,F1    ,MODX_SHIFT)                          //~v324R~
        SETCKT(f14    ,F2    ,MODX_SHIFT)                          //~v324R~
        SETCKT(f15    ,F3    ,MODX_SHIFT)                          //~v324R~
        SETCKT(f16    ,F4    ,MODX_SHIFT)                          //~v324R~
        SETCKT(f17    ,F5    ,MODX_SHIFT)                          //~v324R~
        SETCKT(f18    ,F6    ,MODX_SHIFT)                          //~v324R~
        SETCKT(f19    ,F7    ,MODX_SHIFT)                          //~v324R~
        SETCKT(f20    ,F8    ,MODX_SHIFT)                          //~v324R~
        SETCKT(f21    ,F9    ,MODX_SHIFT)                          //~v324R~
        SETCKT(f22    ,F10   ,MODX_SHIFT)                          //~v324R~
        SETCKT(f23    ,F11   ,MODX_SHIFT)                          //~v324R~
        SETCKT(f24    ,F12   ,MODX_SHIFT)                          //~v324R~
//    }                                                            //~v39MR~
//#endif              //libc2 TurboLinux                           //~v39MR~
#endif // NCURSES                                                  //~v6a0I~
    return;                                                        //~v324I~
}//ukbdlnxc_setupckt                                               //~v324I~
//*********************************************************************//~v39tI~
//* setup curses key table sub                                     //~v39tI~
//*********************************************************************//~v39tI~
void ukbdlnxc_setupcktsub(int Popt,char *Pterminfostr,FUNCKEYTBL *Ppfkt,int Pmodx)//~v500R~
{                                                                  //~v39tI~
    int symid,keycode,len,symclearsw=1;                            //~v39MR~
    char *oldstr,*pc;                                              //~v39MR~
    int addopt;                                                    //~v57NI~
//*********************************                                //~v39MI~
//UTRACEP("terminfostr:%s,symid=%x,mod=%d\n",Pterminfostr,Ppfkt->FKTsymid,Pmodx);//~v57NR~
        oldstr=Pterminfostr;                                       //~v39MI~
        Ppfkt->FKTterminfo[Pmodx]=oldstr;   //for xekbchk,print etrminfo string//~v3a1I~
//     	if (Ppfkt->FKTflag[Pmodx] & FKT_TTREPKEY)//string by parm file//~v57NR~
       	if (Ppfkt->FKTflag[Pmodx][0] & FKT_TTREPKEY)//string by parm file//~v57NR~
        {                                                          //~v57yI~
	    	Ppfkt->FKTfkassign[Pmodx]=0; //skip keysym change      //~v57yI~
        	return;                                                //~v57yI~
        }                                                          //~v57yI~
        keycode=Ppfkt->FKTkeycode;                                 //~v39MI~
        if (keycode)                                               //~v39MI~
        {                                                          //~v39MI~
            if (!Pmodx)	//base                                     //~v39MI~
            {                                                      //~v39MI~
                symid=Ppfkt->FKTsymid;                             //~v39MI~
              if (!Popt)    //not kterm/xterm const                //~v501I~
	            if (symid && KTYP(symid)==KT_FN) //has string      //~v39MI~
            		if (pc=ukbdlnxc_getstring(symid),pc)//under kon oldstr may 0//~v39MI~
                		oldstr=pc;                                 //~v39MI~
            }                                                      //~v39MI~
            else	//shift                                        //~v39MI~
            {                                                      //~v39MI~
                symid=ukbdlnxc_getkeysym(1,keycode,Smapid[Pmodx]);  //keysym of shift key//~v57NR~
                if (symid!=Ppfkt->FKTfkassign[Pmodx])   //chng keysym requiered if string not defined//~v39MI~
                {                                                  //~v39MI~
//UTRACEP("symid=%x-->%x\n",symid,Ppfkt->FKTfkassign[Pmodx]);      //~v39MR~
                	symid=Ppfkt->FKTfkassign[Pmodx];   //chng keysym requiered if string not defined//~v39MI~
                	symclearsw=0;                                  //~v39MI~
                }                                                  //~v39MI~
              if (!Popt)    //not kterm/xterm const                //~v501I~
                if (symid && KTYP(symid)==KT_FN) //has string      //~v39MR~
                    if (pc=ukbdlnxc_getstring(symid),pc)//under kon oldstr may 0//~v39MR~
                        oldstr=pc;                                 //~v39MR~
            }//shift                                               //~v39MI~
        }//keycode!=0                                              //~v39MI~
        Pterminfostr=oldstr;                                       //~v39MI~
//UTRACEP("setupckt,oldstr=%s\n",oldstr);                          //~v57NR~
		if (oldstr && *oldstr)	//string defined                   //~v39MR~
        {                                                          //~v39tI~
//UTRACEP("symid=%x,oldstr=%s\n",symid,Pterminfostr);              //~v39MR~
//          Ppfkt->FKTfkassign[Pmodx]=0;      /*drop Fxx assign*/  //~v39MI~
//          if (*(Pterminfostr+1)==TERMINFOSTRID)/*1b[*/           //~v3a1R~
//          {                                                      //~v3a1R~
//UTRACEP("use original\n");                                       //~v39MR~
//printf("use original=%s\n",oldstr);                              //~v525R~
//              if (Popt)                                          //~v57NR~
//                Ppfkt->FKTflag[Pmodx]|=FKT_USEXTERM;//xterm constant//~v57NR~
//              else                                               //~v57NR~
//                Ppfkt->FKTflag[Pmodx]|=FKT_USEORGSTR;            //~v57NR~
//  			if (symclearsw)                                    //~v57NR~
//              	Ppfkt->FKTfkassign[Pmodx]=0; //drop keysym change//~v57NR~
//              Scurseskeytbl[Scktno].CKTpfkt=Ppfkt;               //~v57NR~
//              Scurseskeytbl[Scktno].CKTmodx=Pmodx;               //~v57NR~
//              len=strlen(Pterminfostr);                          //~v39MI~//~v6D0R~
                len=(int)strlen(Pterminfostr);                     //~v6D0I~
//              oldstr=malloc(len+1);                              //~v39MI~//~v6D0R~
                oldstr=malloc((size_t)len+1);                      //~v6D0I~
//              memcpy(oldstr,Pterminfostr,len+1);                 //~v39MI~//~v6D0R~
                memcpy(oldstr,Pterminfostr,(size_t)len+1);         //~v6D0I~
//              Scurseskeytbl[Scktno].CKTstring=oldstr;            //~v57NR~
//              Scurseskeytbl[Scktno].CKTlen=len;                  //~v57NR~
//              Scktno++;                                          //~v57NR~
    			if (symclearsw)                                    //~v57NI~
                    addopt=ADDSTT_CLEARASSIGN;                     //~v57NR~
                else                                               //~v57NI~
                    addopt=0;                                      //~v57NI~
				ukbdlnxc_addstrtbl(addopt,FKT_USEORGSTR,oldstr,Ppfkt,Pmodx,len);//~v57NI~
//          }                                                      //~v3a1R~
            /*else char key*/                                      //~v39tI~
        }                                                          //~v39tI~
        /*else xe use or not defined on terminfo*/                 //~v39tI~
    return;                                                        //~v39MI~
}//ukbdlnxc_setupcktsub                                            //~v39tI~
//*********************************************************************//~v57NI~
//* setup curses key table of default for X-term                   //~v57NI~
//*********************************************************************//~v57NI~
void ukbdlnxc_setupcktx(void)                                      //~v57NI~
{                                                                  //~v57NI~
#define SETCKTX(string,fktkey,modx)        \
        ukbdlnxc_addstrtbl(ADDSTT_CLEARASSIGN,FKT_XDEFAULT,string,&Sfkt_##fktkey,modx,strlen(string));//~v57NR~
    static int S1stsw=0;                                           //~v57NI~
//**********************************                               //~v57NI~
    if (S1stsw)	//only once set default                            //~v57NI~
    	return;                                                    //~v57NI~
    S1stsw=1;                                                      //~v57NI~
    #include <ukbdl2.h>                                            //~v58eI~
    return;                                                        //~v57NI~
}//ukbdlnxc_setupcktx                                              //~v57NI~
//*********************************************************************//~v6FdI~
int cktovferr(char *Pstring)                                       //~v6FdI~
{                                                                  //~v6FdI~
	static int Scktovf;                                            //~v6FdR~
    int rc=0;                                                      //~v6FdI~
//**********************                                           //~v6FdI~
  	if (Scktno>=CKTNO)                                             //~v6FdI~
  	{                                                              //~v6FdI~
  		if (!Scktovf)                                              //~v6FdI~
    	{                                                          //~v6FdI~
  			uerrmsg("CursesKeyTable overflow(max=%d) for %s",0,    //~v6FdI~
    		CKTNO,Pstring);                                        //~v6FdI~
 	   	}                                                          //~v6FdI~
  		Scktovf=1;                                                 //~v6FdI~
        rc=4;                                                      //~v6FdI~
  	}                                                              //~v6FdI~
    UTRACEP("%s:Scktno=%d max=%d string=%s\n",UTT,Scktno,CKTNO,Pstring);//~v6FdR~
    return rc;                                                     //~v6FdI~
}//cktovferr                                                       //~v6FdI~
//*********************************************************************//~v57NI~
//* setup curses key table sub                                     //~v57NI~
//*********************************************************************//~v57NI~
void ukbdlnxc_addstrtbl(int Popt,int Pflag,char *Pstring,FUNCKEYTBL *Ppfkt,int Pmodx,int Plen)//~v57NR~
{                                                                  //~v57NI~
    int ii;                                                        //~v57NI~
    char editwk[32];                                               //~v57NI~
    int swshift;                                                   //+v6FdI~
//*********************************                                //~v57NI~
	swshift=Pmodx & MODX_SHIFT_REPORT;                             //+v6FdI~
	Pmodx &= ~MODX_SHIFT_REPORT;                                   //+v6FdI~
	if (Pmodx & MODX_SCO)                                          //~v6qhI~
    {                                                              //~v6qhI~
    	Pmodx&=~MODX_SCO;                                          //~v6qhI~
        if (Skbdopt & UKBDL_NOSCO)                                 //~v6qhR~
        	return;                                                //~v6qhI~
    }                                                              //~v6qhI~
	if (Pmodx & MODX_Z2) 	//entry:^[[Z for S+F2                  //~v6qhI~
    {                                                              //~v6qhI~
    	Pmodx&=~MODX_Z2;                                           //~v6qhI~
        if (!(Skbdopt & UKBDL_Z2))                                 //~v6qhI~
        	return;                                                //~v6qhI~
    }                                                              //~v6qhI~
	if (Pmodx & MODX_ZT) 	//entry:^[[Z for S+Tab                 //~v6qhI~
    {                                                              //~v6qhI~
    	Pmodx&=~MODX_ZT;                                           //~v6qhI~
        if ((Skbdopt & UKBDL_Z2))                                  //~v6qhI~
        	return;                                                //~v6qhI~
    }                                                              //~v6qhI~
    for (ii=0;ii<FKT_MAX_STR;ii++)                                 //~v57NI~
    {                                                              //~v57NI~
   		if (!Ppfkt->FKTttstring[Pmodx][ii])                        //~v57NI~
            break;                                                 //~v57NI~
    }                                                              //~v57NI~
    if (ii==FKT_MAX_STR)                                           //~v57NI~
    {                                                              //~v57NI~
        ukbdl_editstring(Pstring,editwk);                          //~v57NI~
//      fprintf(stderr, "add:string assignment overflow(max is %d) for %s%s,%s ignored\n",//~v5mvR~
        uerrmsg("add:string assignment overflow(max is %d) for %s%s,%s ignored",0,//~v5mvI~
            	FKT_MAX_STR,Sshiftidstr[Pmodx],Ppfkt->FKTkeyname,editwk);//~v57NR~
	    return;                                                    //~v57NI~
    }                                                              //~v57NI~
  if (Ppfkt->FKTsymid==K_CTRLR)                                    //~v5mvR~
	ukbdlnxc_setrctl(UKBDLNXC_SRCO_SETSTR);                        //~v5mvI~
  else                                                             //~v5mvI~
	if (Popt & ADDSTT_CLEARASSIGN)                                 //~v57NI~
		Ppfkt->FKTfkassign[Pmodx]=0; //drop keysym change          //~v57NI~
    Ppfkt->FKTttstring[Pmodx][ii]=Pstring;                         //~v57NI~
    Ppfkt->FKTflag[Pmodx][ii]=Pflag;                               //~v57NR~
  if (!cktovferr(Pstring))                                         //~v6FdI~
  {                                                                //~v6FdI~
    Scurseskeytbl[Scktno].CKTpfkt=Ppfkt;                           //~v57NI~
//  Scurseskeytbl[Scktno].CKTmodx=Pmodx;                           //+v6FdR~
    Scurseskeytbl[Scktno].CKTmodx=Pmodx|swshift;                   //+v6FdI~
    Scurseskeytbl[Scktno].CKTstring=Pstring;                       //~v57NI~
    Scurseskeytbl[Scktno].CKTlen=Plen;                             //~v57NR~
//UTRACEP("addstring mod=%d,name=%s,str=%s\n",Pmodx,Ppfkt->FKTkeyname,Pstring);//~v57NR~
    Scktno++;                                                      //~v57NI~
  }                                                                //~v6FdI~
    return;                                                        //~v57NI~
}//ukbdlnxc_addstrtbl                                              //~v57NR~
//*********************************************************************//~v57NI~
//* setup curses key table sub                                     //~v57NI~
//*********************************************************************//~v57NI~
int ukbdlnxc_dupstrchk(char *Pstring,FUNCKEYTBL *Ppfkt,int Pmodx,int Plen)//~v57NI~
{                                                                  //~v57NI~
	char **ppstr;                                                  //~v57NI~
    int len,modx,ii;                                               //~v57NR~
    PCURSESKEYTBL pckt,pckte;                                      //~v57NI~
    PFUNCKEYTBL pfkt;                                              //~v57NI~
    char editwk[32];                                               //~v57NI~
//*********************************                                //~v57NI~
    for (pckt=Scurseskeytbl,pckte=Scurseskeytbl+Scktno;pckt<pckte;pckt++)//~v57NI~
    {                                                              //~v57NI~
        len=pckt->CKTlen;                                          //~v57NI~
//      if (len==Plen && !memcmp(Pstring,pckt->CKTstring,len))     //~v57NI~//~v6D0R~
        if (len==Plen && !memcmp(Pstring,pckt->CKTstring,(size_t)len))//~v6D0I~
        	break;                                                 //~v57NR~
    }//search loop                                                 //~v57NI~
    if (pckt>=pckte)	//not dup	                               //~v57NI~
    	return 0;                                                  //~v57NI~
    modx=pckt->CKTmodx;                                            //~v57NI~
    pfkt=pckt->CKTpfkt;                                            //~v57NI~
	ppstr=pfkt->FKTttstring[modx];                                 //~v57NI~
    for (ii=0;ii<FKT_MAX_STR;ii++)                                 //~v57NI~
    {                                                              //~v5muI~
//  	if (*ppstr && !memcmp(*ppstr,Pstring,len))                 //~v57NI~//~v6D0R~
    	if (*ppstr && !memcmp(*ppstr,Pstring,(size_t)len))         //~v6D0I~
            break;                                                 //~v57NI~
        ppstr++;                                                   //~v5muI~
    }                                                              //~v5muI~
    if (ii>=FKT_MAX_STR)                                           //~v57NI~
    {                                                              //~v57NI~
        ukbdl_editstring(Pstring,editwk);                          //~v57NI~
        fprintf(stderr, "str tbl logical err for %s%s,newstr=%s\n",//~v57NR~
            	Sshiftidstr[Pmodx],Ppfkt->FKTkeyname,editwk);      //~v57NR~
	    return 4;                                                  //~v57NI~
    }                                                              //~v57NI~
    if (pfkt==Ppfkt && modx==Pmodx)	//for same key                 //~v57NI~
    	return 0;                                                  //~v57NI~
//reset old                                                        //~v57NI~
    *ppstr=0;                                                      //~v57NI~
    pfkt->FKTflag[modx][ii]=0;                                     //~v57NR~
//set new                                                          //~v57NI~
    for (ii=0;ii<FKT_MAX_STR;ii++)                                 //~v57NI~
    {                                                              //~v57NI~
   		if (!Ppfkt->FKTttstring[Pmodx][ii])                        //~v57NI~
            break;                                                 //~v57NI~
    }                                                              //~v57NI~
    if (ii==FKT_MAX_STR)                                           //~v57NI~
    {                                                              //~v57NI~
        ukbdl_editstring(Pstring,editwk);                          //~v57NI~
        fprintf(stderr, "move:string assignment overflow(max is %d) for %s%s,%s ignored\n",//~v57NR~
            	FKT_MAX_STR,Sshiftidstr[Pmodx],Ppfkt->FKTkeyname,editwk);//~v57NR~
	    return 4;                                                  //~v57NR~
    }                                                              //~v57NI~
  	if (Ppfkt->FKTsymid==K_CTRLR)                                  //~v5mvR~
		ukbdlnxc_setrctl(UKBDLNXC_SRCO_SETSTR);                    //~v5mvI~
    Ppfkt->FKTttstring[Pmodx][ii]=Pstring;                         //~v57NI~
    Ppfkt->FKTflag[Pmodx][ii]=FKT_TTREPKEY;                        //~v57NI~
//  Scurseskeytbl[Scktno].CKTpfkt=Ppfkt;                           //~v5mvR~
//  Scurseskeytbl[Scktno].CKTmodx=Pmodx;                           //~v5mvR~
    pckt->CKTpfkt=Ppfkt;                                           //~v5mvI~
    pckt->CKTmodx=Pmodx;                                           //~v5mvI~
    return 1;	//dup found                                        //~v57NI~
}//ukbdlnxc_dupstrchk                                              //~v5muR~
//*********************************************************************
//* restore kbd status
//*********************************************************************
void ukbdlnxc_cleanup(int Prestoresw)
{
  if (Stermnameid==TERM_TTYLCONS)	//console                      //~v57NI~
  {                                                                //~v57NI~
    if (Prestoresw)
    {
      if (ukbdlnxc_restorelast())   //restore saved status if last closer//~v386R~
      {                                                            //~v386I~
        ukbdlnxc_setfunckey(1);     //restore original funckey assignment
        ukbdlnxc_setfuncstr(1);     //restore original funckey string assignment
        ukbdlnxc_setcompose(1);     //assing compose char
        ukbdlnxc_setmetamode(1);    //restore original metamode
      }//if not last leave change                                  //~v386I~
    }
    if (!Scursessw)  //uviol already set metamode                  //~v39bI~
    	ukbdl_setkbmode(1);      //restore cannonical mode         //~v39bR~
  }//console only                                                  //~v57NI~
}//ukblnxc_cleanup
//*********************************************************************
//* signal handler
//*********************************************************************
void ukbdlnxc_termexit(int Psigid)
{
    printf("ukbdlnxc.c:Detected Signal %d\n",Psigid);              //~v324R~
    ukbdlnxc_cleanup(1);
}//ukbdlnxc_termexit
//*********************************************************************
//* setup ukeymap(get keycode)                                     //~v324R~
//*********************************************************************
//int  ukbdlnxc_getplainsym(void)                                  //~v57YR~
int  ukbdlnxc_getplainsym(int Popt)                                //~v57YI~
{
    int ii,jj,symid,kc_delete=0,kc_backspace=0;                    //~v324R~
    PFUNCKEYTBL pfkt;
    int ctlkeyctr=0,symid2;                                        //~v5mvR~
//************************
//get all symid on plane keymap and setup symtbl
    for (ii=1;ii<NR_KEYS;ii++)        //keycode
    {
        symid=ukbdlnxc_getkeysym(1,ii,0);     //keysym of plain keymap//~v57NR~
        symid2=ukbdlnxc_getkeysym(1,ii,1);    //for control(play may changed by other xe session)//~v5mvI~
//UTRACEP("plainsym:ii=%d,symid=%x\n",ii,symid);                   //~v57NR~
//to chk Backspace definition change
        if (symid==CH_DELETE)
            kc_delete=ii;
        else
        if (symid==CH_BACKSP)
            kc_backspace=ii;
        else                                                       //~v5mvI~
        if (symid2==K_CTRL)  //CTLR is not show by getsym          //~v5mvR~
        {                                                          //~v5mvI~
        	if (ctlkeyctr)                                         //~v5mvI~
            	Sfkt_RCTL.FKTkeycode=ii;   //2nd ctl               //~v5mvR~
            ctlkeyctr++;                                           //~v5mvI~
        }                                                          //~v5mvI~
        else                                                       //~v5mvR~
        if (symid==K_CTRLR)  //CTLR is not show by getsym          //~v5mvI~
            Sfkt_RCTL.FKTkeycode=ii;   //2nd ctl                   //~v5mvI~
        Skeycode_symid[ii]=symid;
//search sym tbl
        for (jj=0;jj<PFKTNO;jj++)
        {
            pfkt=Spfktbl[jj];
            if (symid==pfkt->FKTsymid                              //~v324R~
            ||  symid==K(KT_LETTER,pfkt->FKTsymid))//ex 'h' is 0b68//~v324I~
            {
                if (!pfkt->FKTkeycode)  //for double define
                {                                                  //~v57NI~
//UTRACEP("keycode=%x,symid=%x,name=%s\n",ii,symid,pfkt->FKTkeyname);//~v57NR~
                    pfkt->FKTkeycode=ii;
                }                                                  //~v57NI~
                break;
            }
        }
    }//for
//UTRACED("del",&Sfkt_REMOVE,sizeof(Sfkt_REMOVE));                 //~v57NR~
//UTRACED("bs",&Sfkt_BS,sizeof(Sfkt_BS));                          //~v57NR~
                                                                   //~v57YI~
  if (!ukbdlnxc_delopt(Popt))	//no force option                  //~v57YI~
  {                                                                //~v57YI~
    if (!kc_backspace)                   //backspace may changed
    {                                                              //~v425I~
#ifdef LNXLC2       //libc2 TurboLinux                             //~v426I~
        if (kc_delete)                   //to delete               //~v426I~
        {                                                          //~v426I~
            Sfkt_BS.FKTkeycode=kc_delete;                          //~v426I~
			Sbs_del_sw=1; //BS(0x08) changed to Del(0x7f)          //~v426I~
        }                                                          //~v426I~
        else                                                       //~v426I~
        {       //both not defined,chk terminfo                    //~v57xI~
#ifndef NOCURSES	//key_xxx is defined on term.h                 //~v6a0I~
            if (key_backspace && *key_backspace==0x7f)  //under x,getkeysym return 0//~v57xI~
				Sbs_del_sw=1; //BS by del(7f)                      //~v57xI~
            else                                                   //~v57xI~
#endif                                                             //~v6a0I~
			Sdel_by_7f=1; //treate 7f as Del key                   //~v426I~
        }                                                          //~v57xI~
#else                                                              //~v426I~
//      if (kc_delete)                   //to delete               //~v39vR~
//      {                                                          //~v39vR~
            Sfkt_BS.FKTkeycode=kc_delete;
			Sbs_del_sw=1; //BS(0x08) changed to Del(0x7f)          //~v324I~
//      }                                                          //~v39vR~
#endif                                                             //~v426I~
    }                                                              //~v425I~
    else    //backspace defined                                    //~v425I~
        if (kc_delete)                   //to delete               //~v425I~
        {                                                          //~v425I~
            if (!Sfkt_REMOVE.FKTkeycode)                           //~v425I~
            {                                                      //~v425I~
				Sdel_by_7f=1; //treate 7f as Del key               //~v425I~
            	Sfkt_REMOVE.FKTkeycode=kc_delete;                  //~v425I~
            }                                                      //~v425I~
        }                                                          //~v425I~
    if (Sbs_del_sw) //BS(0x08) by Del(0x7f)                        //~v427M~
    {                                                              //~v427I~
		Sfkt_BS.FKTfkassign[MODX_ALT]=K(KT_META,CH_DELETE);//receive alt+DEL//~v427I~
		Saltchartbl[CH_DELETE]=Saltchartbl[CH_BACKSP];	//translate to alt+BS//~v427I~
    }                                                              //~v427I~
 }//no force option                                                //~v57YI~
    return 0;
}//ukbdlnxc_getplainsym
//*********************************************************************//~v57RI~
//* chk other keysim assignment                                    //~v57RI~
//*********************************************************************//~v57RI~
void ukbdlnxc_chkothersym(void)                                    //~v57RI~
{                                                                  //~v57RI~
    int symid,keycode;                                             //~v57RI~
    PFUNCKEYTBL pfkt;                                              //~v57RI~
//************************                                         //~v57RI~
//special for RH9                                                  //~v57RI~
    pfkt=&Sfkt_2;                                                  //~v57RR~
    keycode=pfkt->FKTkeycode;                                      //~v57RI~
    symid=ukbdlnxc_getkeysym(1,keycode,Smapid[MODX_CONTROL]);      //keysym of plain keymap//~v57RI~
//UTRACEP("pfkt_2,keycode=%d,sym=%x\n",keycode,symid);             //~v57NR~
    if (symid!=K_HOLE)	//RedHat9 define sym=0200(special char+00),it dose not generate key event//~v57RR~
        pfkt->FKTfkassign[MODX_CONTROL]=0;	//use original keymap  //~v57RI~
    return;                                                        //~v57RI~
}//ukbdlnxc_chkothersym                                            //~v57RI~
//*********************************************************************//~v57NI~
//* chk 7f is bs or del by terminfo                                //~v57NI~
//*********************************************************************//~v57NI~
//int  ukbdlnxc_xbsdel(void)                                       //~v57YR~
int  ukbdlnxc_xbsdel(int Popt)                                     //~v57YI~
{                                                                  //~v57NI~
    char *strbs,*strdc;                                            //~v57NI~
//************************                                         //~v57NI~
  if (!ukbdlnxc_delopt(Popt))	//no force option                  //~v57YI~
  {                                                                //~v57YI~
#ifndef NOCURSES	//key_xxx is defined on term.h                 //~v6a0M~
    strbs=key_backspace;  //curses setup from terminfo             //~v57NI~
    if (!strbs)                                                    //~v57NI~
#endif                                                             //~v6a0I~
    	strbs="";                                                  //~v57NI~
#ifndef NOCURSES	//key_xxx is defined on term.h                 //~v6a0I~
    strdc=key_dc;                                                  //~v57NI~
    if (!strdc)                                                    //~v57NI~
#endif                                                             //~v6a0I~
    	strdc="";                                                  //~v57NI~
    if (*strbs==CH_DELETE)	//backspace by 7f                      //~v57NR~
    {                                                              //~v57NI~
		Sbs_del_sw=1; //BS(0x08) changed to Del(0x7f)              //~v57NI~
        Sfkt_BS.FKTkeycode=CH_DELETE;                              //~v57YI~
		Sfkt_BS.FKTfkassign[MODX_ALT]=K(KT_META,CH_DELETE);//receive alt+DEL//~v57NI~
		Saltchartbl[CH_DELETE]=Saltchartbl[CH_BACKSP];	//translate to alt+BS//~v57NI~
    }                                                              //~v57NI~
    else                                                           //~v57NI~
    {                                                              //~v57NI~
		Sdel_by_7f=1; //treate 7f as Del key                       //~v57NI~
        Sfkt_REMOVE.FKTkeycode=CH_DELETE;                          //~v57YI~
    }                                                              //~v57NI~
  }//no force option                                               //~v57YI~
    return 0;                                                      //~v57NI~
}//ukbdlnxc_xbsdel                                                 //~v57NI~
//*********************************************************************//~v57YI~
//* chk 7f is bs or del by cmd parm                                //~v57YI~
//* rc:0:no option,1:char 7f,2:BS,3:DEL                            //~v57YI~
//*********************************************************************//~v57YI~
int  ukbdlnxc_delopt(int Popt)                                     //~v57YI~
{                                                                  //~v57YI~
    char rc;                                                       //~v57YI~
//************************                                         //~v57YI~
  	if (Popt & UKBDL_7fBS)                                         //~v589R~
    {                                                              //~v57YI~
    	rc=2;                                                      //~v57YI~
		Sbs_del_sw=1; //BS by Del(0x7f)                            //~v57YI~
        Sfkt_BS.FKTkeycode=CH_DELETE;                              //~v57YI~
		Sfkt_BS.FKTfkassign[MODX_ALT]=K(KT_META,CH_DELETE);//receive alt+DEL//~v57YI~
		Saltchartbl[CH_DELETE]=Saltchartbl[CH_BACKSP];	//translate to alt+BS//~v57YI~
    }                                                              //~v57YI~
    else                                                           //~v57YI~
  	if (Popt & UKBDL_7fDEL)                                        //~v589R~
    {                                                              //~v57YI~
    	rc=3;                                                      //~v57YI~
		Sdel_by_7f=1; //treate 7f as Del key                       //~v57YI~
        Sfkt_REMOVE.FKTkeycode=CH_DELETE;                          //~v57YI~
    }                                                              //~v57YI~
    else                                                           //~v57YI~
  	if (Popt & UKBDL_7fCHAR)                                       //~v589R~
    	rc=1;                                                      //~v57YI~
    else                                                           //~v57YI~
        rc=0;                                                      //~v57YI~
    return rc;                                                     //~v57YI~
}//ukbdlnxc_delopt                                                 //~v57YI~
//*********************************************************************
//* assign sym to keycode with modifier
//*********************************************************************
void ukbdlnxc_setfunckey(int Prestoresw)
{
    int ii,jj,symid,symidold,keycode;
    PFUNCKEYTBL pfkt;
//************************
//assign Fxx to modifier 
//printf("PFKTNO=%d\n",PFKTNO);
    for (ii=0;ii<PFKTNO;ii++)        //keycode
    {
        pfkt=Spfktbl[ii];
        keycode=pfkt->FKTkeycode;
//UTRACEP("ii=%d,pfkt=%08x,keyname=%s,keycode=%d\n",ii,pfkt,pfkt->FKTkeyname,keycode);//~v515R~
        if (!keycode)
        {
//printf("no keycode assign for pfkt=%08x,symid=%d\n",pfkt,pfkt->FKTsymid);//~v50zR~
            continue;
        }
        for (jj=0;jj<FKT_MAX_SYM;jj++)
        {
            symid=pfkt->FKTfkassign[jj];
//UTRACEP("ii=%d,jj=%d,sym=%04x,keycode=%d\n",ii,jj,symid,keycode);//~v515R~
            if (!symid)  //change required
                continue;
            symidold=ukbdlnxc_getkeysym(1,keycode,Smapid[jj]);      //keysym of plain keymap//~v57NR~
            if (Prestoresw)
            {
                symid=pfkt->FKTfksaveold[jj];
                if (!symid)
                    continue;
            }
            else
            {
                if (!pfkt->FKTfksaveold[jj])
//                  pfkt->FKTfksaveold[jj]=symidold;               //~v6D0R~
                    pfkt->FKTfksaveold[jj]=(USHORT)symidold;       //~v6D0I~
            }
//UTRACEP("set keysym jj=%d,sym=%04x,oldsym=%04x,keycode=%d\n",jj,symid,symidold,keycode);//~v57NR~
            if (symid==symidold)
                continue;
            ukbdlnxc_setkeysym(keycode,Smapid[jj],symid);
        }//jj        6                                             //~v5mvR~
    }
//    if (Sbs_del_sw) //BS(0x08) changed to Del(0x7f)              //~v39uR~
//    {                                                            //~v39uR~
////printf("Del assigned to BS\n");                                //~v39uR~
//        pfkt=&Sfkt_BS;                                           //~v39uR~
//        keycode=pfkt->FKTkeycode;                                //~v39uR~
//        if (Prestoresw)                                          //~v39uR~
//            symid=CH_DELETE;                                     //~v39uR~
//        else                                                     //~v39uR~
//            symid=CH_BACKSP;                                     //~v39uR~
//        ukbdlnxc_setkeysym(keycode,Smapid[MODX_PLAIN],symid);    //~v39uR~
//        ukbdlnxc_setkeysym(keycode,Smapid[MODX_ALT],K(KT_META,symid));//~v39uR~
//    }                                                            //~v39uR~

    symidold=ukbdlnxc_getkeysym(1,DEADKEY_KEYCODE,Smapid[MODX_ALT]);//~v57RI~
  if (symidold!=K_DGRAVE)                                          //~v57RI~
    ukbdlnxc_setkeysym(DEADKEY_KEYCODE,Smapid[MODX_ALT],K_DGRAVE);
                         //DEADKEY_KATAKANA+a-->katakana a
//printf("return setfunckey\n");
}//ukbdlnxc_setfunckey
//*********************************************************************
//* assign funckey string
//*********************************************************************
void ukbdlnxc_setfuncstr(int Prestoresw)
{
//static char *Sxconv={"0123456789ABCDEF"};                        //~v39SR~
static char Snewstr[8]={0x1b,FUNCSTRID};                           //~v39LI~
    int ii,symid,modifier,funcno,doskey;                           //~v39SR~
    PFUNCKEYTBL pfkt;
    char  *setstr,*oldstr,*savestr;
//************************
    for (ii=0;ii<FSTNO;ii++)        //keycode
    {
        pfkt=Sstrtbl[ii].FSTpfkt;
        modifier=Sstrtbl[ii].FSTmodx;
//printf("setfuncstr ii=%d,pfkt=%s,mod=%d\n",ii,pfkt->FKTkeyname,modifier);//~v525R~
        symid=pfkt->FKTfkassign[modifier];
//printf("ii=%d,symid=%d\n",ii,symid);
//        if (!symid)                 //add not required           //~v383R~
//          if (!modifier)          //plane map                    //~v383R~
//              symid=pfkt->FKTsymid;   //use original symid       //~v383R~
//printf("restoresw=%d,ii=%d,symid=%d\n",Prestoresw,ii,symid);     //~v524R~
        if (Prestoresw)
        {
            if (!symid)         //set 0 for xe-non-used key        //~v525I~
                continue;                                          //~v525I~
            setstr=Sstrtbl[ii].FSTstrold;
//printf("restore,ii=%d,symid=%d,str=%s\n",ii,symid,setstr);       //~v525R~
            if (!setstr)
                continue;
        }
        else
        {
            if (!symid)
                continue;
            if (KTYP(symid)!=KT_FN)
                continue;
//          if (pfkt->FKTflag[modifier] & FKT_USEORGSTR)	//use original str//~v57yR~
            if (pfkt->FKTflag[modifier][0] & (FKT_USEORGSTR|FKT_TTREPKEY))	//use original str//~v57NR~
                continue;                                          //~v39MI~
//          funcno=ii+FUNCSTR_START;                               //~v39JR~
//          if (funcno>=FUNCSTR_SKIPSQ)                            //~v39JR~
//              funcno++;                                          //~v39JR~
			doskey=                                                //~v39SI~
            funcno=pfkt->FKTdoskey[modifier];   //scancode+charcode//~v39JR~
            funcno>>=8;     //scancode                             //~v39JI~
            if (Sstrtmap[funcno][modifier])		//dup key          //~v39JR~
              if (!(KTYP(pfkt->FKTsymid)==KT_PAD && modifier==MODX_CONTROL))//ctl+10key is same as C+home etc//~v515R~
            	fprintf(stderr,"scancode %x,modifier %d is duplicated\n",funcno,modifier);//~v39JR~
            Sstrtmap[funcno][modifier]=ii;        //index to pft and modifier//~v39JR~
//          sprintf(newstr,"\x1b%c%c",FUNCSTRID,funcno);           //~v39JR~
//  		Snewstr[2]=Sxconv[funcno>>4];                          //~v39SR~
//  		Snewstr[3]=Sxconv[funcno & 0x0f];                      //~v39SR~
//  		Snewstr[4]=modifier+'0';                               //~v39SR~
          if (doskey==RCTLID)                                      //~v5mvR~
            sprintf(Snewstr+2,"%04X%d",doskey,MODX_CONTROL); //for _ukbdlnxc_read chk//~v5mvI~
          else                                                     //~v5mvI~
            sprintf(Snewstr+2,"%04X%d",doskey,modifier);           //~v39SR~
            setstr=Snewstr;                                        //~v39LR~
            strncpy(Sstrtbl[ii].FSTstrnew,setstr,sizeof(Sstrtbl[ii].FSTstrnew));//~v3a1I~
            pfkt->FKTpfst[modifier]=Sstrtbl+ii;                    //~v3a1R~
        }   
//printf("getstrcall ii=%d,symid=%4x\n",ii,symid);
        oldstr=ukbdlnxc_getstring(symid);
        if (!oldstr)                                               //~v39JI~
        	oldstr="";		//id of none                           //~v39JI~
        if (!strcmp(oldstr,setstr))
            continue;
        if (!Prestoresw)
        {
//printf("setfuncstr ii=%d,symid=%4x,prev=%s,oldstr=%s\n",ii,symid,Sstrtbl[ii].FSTstrold,oldstr);//~v525R~
            if (!Sstrtbl[ii].FSTstrold)
            {
                savestr=(char*)malloc(strlen(oldstr)+1);
                strcpy(savestr,oldstr);
                Sstrtbl[ii].FSTstrold=savestr;
            }
        }
        ukbdlnxc_setstring(symid,setstr);
        if (Prestoresw)
        {
            free(setstr);
            Sstrtbl[ii].FSTstrold=0;
        }
    }//for                             
//printf("end of setfuncstr\n");
}//ukbdlnxc_setfuncstr
//*********************************************************************
//* save compose
//*********************************************************************
void ukbdlnxc_setcompose(int Prestoresw)
{
    struct kbdiacrs *pkd;
//************************
    if (Prestoresw)
    {
        if (!Ssavecompose.kbdiacr[0].base)
            return;                         //not saved
        pkd=&Ssavecompose;
    }
    else
    {
        if (Ssavecompose.kbdiacr[0].base)
            return;                         //already
        memcpy(Scompose.kbdiacr,Skatakanalist,sizeof(Skatakanalist));
        ukbdlnxc_getdiacr(&Ssavecompose);
        pkd=&Scompose;
    }
    ukbdlnxc_setdiacr(pkd);
}//ukbdlnxc_setcompose
//*********************************************************************
//* get sym of keycode
//*********************************************************************
int ukbdlnxc_getkeysym(int Pmsgopt,int Pkeycode,int Pkeymap)       //~v57NR~
{
    struct kbentry ke;
static int Smsgsw;                                                 //~v398I~
//************************
//  if (Stermid & TERM_SIMID)   //X terminal sim                   //~v57NR~
//      return 0;                                                  //~v57NR~
//  ke.kb_index=Pkeycode;                                          //~v6D0R~
    ke.kb_index=(UCHAR)Pkeycode;                                   //~v6D0I~
//  ke.kb_table=Pkeymap;                                           //~v6D0R~
    ke.kb_table=(UCHAR)Pkeymap;                                    //~v6D0I~
    if (ioctl(Sfdioctl,KDGKBENT,(unsigned long)&ke))               //~v39ZR~
    {
UTRACEP("getkeysym err=%d, keycode=%d,map=%d,sym=%04x\n",errno,Pkeycode,Pkeymap,ke.kb_value);//~v5mvR~
      if (Pmsgopt)                                                 //~v57NI~
    	if (!Smsgsw)                                               //~v398I~
        {                                                          //~v398I~
        	Smsgsw=1;                                              //~v398I~
        	fprintf(stderr, "KDGKBENT at index %d in table %d:",   //~v398R~
            	Pkeycode,Pkeymap);                                 //~v398R~
        	perror("");                                            //~v398R~
        	fprintf(stderr,"\r");                                  //~v398I~
        }                                                          //~v398I~
//      uabend(3,errno,0,0);                                       //~v398R~
        return 0;                                                  //~v398I~
    }
UTRACEP("getkeysym keycode=%d,map=%d,sym=%04x\n",Pkeycode,Pkeymap,ke.kb_value);//~v5mvR~
    return ke.kb_value;
}//ukbdlnxc_getkeysym
//*********************************************************************
//* set sym of keycode
//*********************************************************************
void ukbdlnxc_setkeysym(int Pkeycode,int Pkeymap,int Psymid)
{
    struct kbentry ke;
static int Smsgsw;                                                 //~v398I~
//************************
//  if (Stermid & TERM_SIMID)   //X terminal sim                   //~v57NR~
//      return;                                                    //~v57NR~

//  ke.kb_index=Pkeycode;                                          //~v6D0R~
    ke.kb_index=(UCHAR)Pkeycode;                                   //~v6D0I~
//  ke.kb_table=Pkeymap;                                           //~v6D0R~
    ke.kb_table=(UCHAR)Pkeymap;                                    //~v6D0I~
//  ke.kb_value=Psymid;                                            //~v6D0R~
    ke.kb_value=(USHORT)Psymid;                                    //~v6D0I~
//UTRACEP("setkeysym keycode=%x,map=%d,sym=%04x\n",Pkeycode,Pkeymap,Psymid);//~v57NR~
  
    if (ioctl(Sfdioctl,KDSKBENT,(unsigned long)&ke))               //~v39ZR~
    {
    	if (!Smsgsw)                                               //~v398I~
        {                                                          //~v398I~
        	Smsgsw=1;                                              //~v398I~
        	fprintf(stderr, "KDSKBENT sym=%04x at index %d in table %d: ",//~v398R~
            	    Psymid,Pkeycode,Pkeymap);                      //~v398R~
        	perror("");                                            //~v398R~
        	fprintf(stderr,"\r");                                  //~v398I~
        }                                                          //~v398I~
//      uabend(4,errno,0,0);                                       //~v398R~
    }
  
    return;
}//ukbdlnxc_setkeysym(void)
//*********************************************************************
//* get string of func key
//*********************************************************************
char *ukbdlnxc_getstring(int Psymid)
{
static  struct kbsentry Skbs;
static int Smsgsw;                                                 //~v398I~
//************************
//  if (Stermid & TERM_SIMID)   //X terminal sim                   //~v57NR~
//      return "";                                                 //~v57NR~
//  Skbs.kb_func=KVAL(Psymid);                                     //~v6D0R~
    Skbs.kb_func=(UCHAR)KVAL(Psymid);                              //~v6D0I~
//printf("getstr strno=%04x\n",Skbs.kb_func);
    if (ioctl(Sfdioctl,KDGKBSENT,(unsigned long)&Skbs))            //~v39ZR~
    {
    	if (!Smsgsw)                                               //~v398I~
        {                                                          //~v398I~
        	Smsgsw=1;                                              //~v398I~
       		fprintf(stderr,"KDGKBSENT at index %d: ",KVAL(Psymid));//~v398R~
        	perror("");                                            //~v398R~
        	fprintf(stderr,"\r");                                  //~v398I~
//      	uabend(5,errno,0,0);                                   //~v398R~
		}                                                          //~v398I~
        return "";                                                 //~v398I~
    }
//UTRACEP("getstr sym=%04x,str=%02x %02x %02x %02x %02x\n",Psymid, //~v57NR~
//        *Skbs.kb_string,                                         //~v57NR~
//        *(Skbs.kb_string+1),                                     //~v57NR~
//        *(Skbs.kb_string+2),                                     //~v57NR~
//        *(Skbs.kb_string+3),                                     //~v57NR~
//        *(Skbs.kb_string+4));                                    //~v57NR~
    return Skbs.kb_string;
}//ukbdlnxc_getstring
//*********************************************************************
//* set string of func key
//*********************************************************************
void ukbdlnxc_setstring(int Psymid,char *Pstr)
{
    struct kbsentry kbs;
static int Smsgsw;                                                 //~v398I~
//************************
	if (Gukbdl_flag & GUKBDL_NOSETSTR)	//bypass set string req by xekbchk//~v57MI~
        return;                                                    //~v57MI~
//  if (Stermid & TERM_SIMID)   //X terminal sim                   //~v57NR~
//      return;                                                    //~v57NR~
//  kbs.kb_func=KVAL(Psymid);                                      //~v6D0R~
    kbs.kb_func=(UCHAR)KVAL(Psymid);                               //~v6D0I~
    strcpy(kbs.kb_string,Pstr);
//UTRACEP("setstr sym=%04x,str=%02x %02x %02x %02x %02x\n",Psymid,*Pstr,*(Pstr+1),*(Pstr+2),*(Pstr+3),*(Pstr+4));//~v524R~
//printf("setstr sym=%04x,str=%02x %02x %02x %02x %02x\n",Psymid,*Pstr,*(Pstr+1),*(Pstr+2),*(Pstr+3),*(Pstr+4));//~v525R~
  
    if (ioctl(Sfdioctl,KDSKBSENT,(unsigned long)&kbs))             //~v39ZR~
    {
    	if (!Smsgsw)                                               //~v398I~
        {                                                          //~v398I~
        	Smsgsw=1;                                              //~v398I~
        	fprintf(stderr, "KDSKBSENT failed to bind string '%s' to function %04x :",//~v57BR~
            	    Pstr,KVAL(Psymid));                            //~v398R~
        	perror("");                                            //~v398R~
        	fprintf(stderr,"\r");                                  //~v398I~
        }                                                          //~v398I~
//      uabend(6,errno,0,0);                                       //~v398R~
    }
  
    return;
}//ukbdlnxc_setstring(void)
//*********************************************************************
//* get compose
//*********************************************************************
void ukbdlnxc_getdiacr(struct kbdiacrs *Pkd)
{
static int Smsgsw;                                                 //~v398I~
//************************
//  if (Stermid & TERM_SIMID)   //X terminal sim                   //~v57NR~
//      return;                                                    //~v57NR~
    if(ioctl(Sfdioctl,KDGKBDIACR,(unsigned long)Pkd))              //~v39ZR~
    {
    	if (!Smsgsw)                                               //~v398I~
        {                                                          //~v398I~
        	Smsgsw=1;                                              //~v398I~
        	fprintf(stderr,"KDGKBDIACR failed: ");                 //~v398R~
        	perror("");                                            //~v398R~
        	fprintf(stderr,"\r");                                  //~v398I~
        }                                                          //~v398I~
//      uabend(7,errno,0,0);                                       //~v398R~
    }
    return;                                                        //~v57BI~
}//ukbdlnxc_getdiacr
//*********************************************************************
//* set compose
//*********************************************************************
void ukbdlnxc_setdiacr(struct kbdiacrs *Pkd)
{
static int Smsgsw;                                                 //~v398I~
//************************
//  if (Stermid & TERM_SIMID)   //X terminal sim                   //~v57NR~
//      return;                                                    //~v57NR~
    if(ioctl(Sfdioctl,KDSKBDIACR,(unsigned long)Pkd))              //~v39ZR~
    {
    	if (!Smsgsw)                                               //~v398I~
        {                                                          //~v398I~
        	Smsgsw=1;                                              //~v398I~
        	fprintf(stderr, "KDSKBDIACR failed: ");                //~v398R~
        	perror("");                                            //~v398R~
        	fprintf(stderr,"\r");                                  //~v398I~
        }                                                          //~v398I~
//      uabend(8,errno,0,0);                                       //~v398R~
    }
    return;                                                        //~v57BI~
}//ukbdlnxc_setdiacr
//*********************************************************************
//* set meta mode
//ret 0:ok,4:parm err
//*********************************************************************
int ukbdlnxc_setmetamode(int Prestoresw)
{
static int Sometamode;
    int cmetamode,nmetamode;
//*************************************
    if (Scursessw)  //uviol already set metamode                   //~v324I~
        return 0;                                                  //~v324I~
    if (ioctl(Sfdioctl,KDGKBMETA,&cmetamode))                      //~v39ZR~
    {
        fprintf(stderr, "Error reading current setting. Maybe stdin is not a VT?\n");
        perror("KDGKBMETA");
        fprintf(stderr,"\r");                                      //~v398I~
//      uabend(9,errno,0,0);                                       //~v398R~//~v6D0R~
        uabend(9,(ULONG)errno,0,0);                                //~v6D0I~
    }
    if (Prestoresw)
        if (Sometamode)
            nmetamode=Sometamode;
        else
            return 4;
    else
        nmetamode=K_ESCPREFIX;
printf("before setmetamode curr=%d,new=%d\n",cmetamode,nmetamode); //~v57BR~
    if (nmetamode==cmetamode)
        return 0;
    if (ioctl(Sfdioctl,KDSKBMETA,nmetamode))                       //~v39ZR~
    {
        perror("KDSKBMETA");
//      uabend(10,errno,0,0);                                      //~v398R~//~v6D0R~
        uabend(10,(ULONG)errno,0,0);                               //~v6D0I~
    }
    if (nmetamode==K_ESCPREFIX)         //prefix mode              //~v50zI~
		Gukbdl_flag|=GUKBDL_METAMODE;	//set metamode             //~v50zI~
    else                                                           //~v50zI~
		Gukbdl_flag&=~GUKBDL_METAMODE;	//reset metamode           //~v50zI~
printf("after setmetamode curr=%d,new=%d,Gbl=%x\n",cmetamode,nmetamode,Gukbdl_flag);//~v57BR~
    if (!Prestoresw)
        if (!Sometamode)           //save only at first
            Sometamode=nmetamode;
    return 0;
}//ukbdlnxc_setmetamode
//*********************************************************************
//* set string of func key
//*********************************************************************
int ukbdlnxc_getconsole(int *Ppttyfd)                              //~v39ZR~
{
    int fd;
    int ttyno;                                                     //~v39ZI~
    char *ttyn;                                                    //~v398I~
    char pttynm[16]; 	//parent tty of pty                        //~v39ZR~
//*************************************
//  ttyn=ttyname(0);	//ttyname of stdin                         //~v6a0R~
    ttyn=uttyname(0);	//ttyname of stdin                         //~v6a0I~
    *Ppttyfd=0;                                                    //~v39ZR~
  if (ttyn)                                                        //~v5m1I~
    if (*(ttyn+8)=='p')  //under pty                               //~v39ZR~
    {                                                              //~v39ZI~
		ttyno=ukbdlnxc_getptty();                                  //~v39ZI~
        if (ttyno)                                                 //~v39ZI~
        {                                                          //~v39ZI~
        	sprintf(pttynm,"/dev/tty%d",ttyno);                    //~v39ZR~
    		*Ppttyfd=ukbdlnxc_open(pttynm);                        //~v39ZR~
        }                                                          //~v39ZI~
    }                                                              //~v39ZI~
    fd=ukbdlnxc_open("/dev/tty");	//current term                 //~v398R~
    if (fd>=0)
      return fd;

    fd=ukbdlnxc_open("/dev/console");
    if (fd >= 0)
      return fd;
                                                                   //~v398I~
//  ttyn=ttyname(0);	//ttyname of stdin                         //~v39ZR~
  if (ttyn)                                                        //~v5m1I~
  {                                                                //~v5m1I~
    fd=ukbdlnxc_open(ttyn);                                        //~v398I~
    if (fd >= 0)                                                   //~v398I~
      return fd;                                                   //~v398I~
  }                                                                //~v5m1I~

    for (fd=0;fd<3;fd++)
      if (ukbdlnxc_chkconsole(fd))
        return fd;

    fprintf(stderr,"Couldnt get a file descriptor referring to the console;use stdin\r\n");//~v398R~
//  uabend(11,errno,0,0);                                          //~v398R~
    return fileno(stdin);                                          //~v398M~
}//ukbdlnxc_getconsole                                             //~v398R~
//*********************************************************************//~v39ZI~
//* get tty number of pty                                          //~v428R~
//  PID TTY STAT TIME COMMAND                                      //~v39ZI~
//   97   6 S    0:00 /sbin/agetty 38400 tty6 linux                //~v39ZI~
//   92   1 S    0:01 -bash                                        //~v39ZI~
//  787   1 S    0:02  \_ kon                                      //~v39ZI~
//  788  p0 S    0:00      \_ -bash                                //~v39ZI~
//  857  p0 R    0:00          \_ ps -fa                           //~v39ZI~
//ret :1:under kon,0:not under kon                                 //~v39ZI~
//*********************************************************************//~v39ZI~
int ukbdlnxc_getptty(void)                                         //~v39ZI~
{                                                                  //~v39ZI~
	PUPSINFO pupsinfo,pupsinfo0;                                   //~v501R~
    static int S1stsw,Sttynosv;                                    //~v39ZI~
    int  pid;                                                      //~v501R~
    char *ttyn;                                                    //~v428I~
//************************                                         //~v39ZI~
	if (S1stsw)			//2nd time                                 //~v39ZI~
    	return Sttynosv;                                           //~v39ZI~
    S1stsw=1;                                                      //~v39ZI~
    Sttynosv=0;                                                    //~v39ZI~
//  ttyn=ttyname(0);                                               //~v6a0R~
    ttyn=uttyname(0);                                              //~v6a0I~
    if (ttyn)                                                      //~v5m1I~
    	return 0;                                                  //~v5m1I~
    if (*(ttyn+8)!='p')          // /dev/ttypxx                    //~v39ZI~
    	return 0;				//not kon                          //~v39ZI~
    if (uproc_getpsinfo(0,&pupsinfo0))                             //~v501R~
    	return 0;                                                  //~v501I~
    ugeterrmsg();   //clear errmsg for exec cmd                    //~v57BI~
    for (pid=getppid();;)				//parent                   //~v428I~
    {                                                              //~v428I~
//  	if (rc=uproc_getpsinfo(pid,&upsinfo),rc)                   //~v501R~
//  	if (!(pupsinfo=uproc_srchpsinfo(pupsinfo0,pid)))           //~v57zR~
    	if (!(pupsinfo=uproc_srchpsinfo(UPSPSI_PPID,pupsinfo0,pid)))//~v57BR~
//      	return 0;                                              //~v501R~
        {                                                          //~v501I~
        	Sttynosv=0;                                            //~v501I~
        	break;                                                 //~v501I~
        }                                                          //~v501I~
//      if ((Sttynosv=upsinfo.UPSIttyno)>0)                        //~v501R~
        if ((Sttynosv=pupsinfo->UPSIttyno)>0)//serch first tty(not pty)//~v501I~
        	break;                                                 //~v428I~
//      pid=upsinfo.UPSIppid;		//parent pid                   //~v501R~
        pid=pupsinfo->UPSIppid;		//parent pid                   //~v501I~
    }                                                              //~v428I~
    uproc_freepsinfo(pupsinfo0);                                   //~v501I~
    return Sttynosv;                                               //~v39ZI~
}//ukbdlnxc_getptty                                                //~v39ZI~
//*********************************************************************
//* open console
//*********************************************************************
int ukbdlnxc_open(char *Pname)
{
    int fd;
//*************************************
    fd=open(Pname,O_RDONLY);
//printf("open %s,fd=%d\n",Pname,fd);
    if (fd < 0 && errno == EACCES)
        fd=open(Pname,O_WRONLY);
    if (fd < 0 || ! ukbdlnxc_chkconsole(fd))
      return -1;
    return fd;
}//ukbdlnxc_open
//*********************************************************************
//* chk fd is console
//* ret 1:valid,0:invalid
//*********************************************************************
int ukbdlnxc_chkconsole(int Pfd)
{
#ifdef TEST                                                        //~v39iI~
    char arg=0;
    int  rc;
//*************************************
    if (ioctl(Pfd,KDGKBTYPE,&arg))
    {                                                              //~v398I~
		fprintf(stderr,"KDGKBTYPE fd=%d,rc=%d : ",Pfd,errno);      //~v398R~
        perror("");                                                //~v398I~
        fprintf(stderr,"\r");                                      //~v398I~
        return 0;
    }                                                              //~v398I~
    rc=((arg == KB_101) || (arg == KB_84));
    if (!rc)                                                       //~v398I~
		fprintf(stderr,"keyboard type err;fd=%d,arg=%d\r\n",Pfd,arg);//~v398R~
    return rc;
#else                                                              //~v39iI~
    return isatty(Pfd);                                            //~v39iI~
#endif                                                             //~v39iI~
}//ukbdlnxc_chkconsole(int Pfd)
//*********************************************************************//~v386I~
//* save status to be restored if 1st session                      //~v386I~
//* ret  :1 1st session then saved,0:not 1st session               //~v386I~
//*********************************************************************//~v386I~
int ukbdlnxc_save1st(void)                                         //~v386I~
{                                                                  //~v386I~
    int ctr,len,ii;                                                //~v386R~
    char *oldstr;                                                  //~v386R~
//******************************                                   //~v386I~
	if (Stermid)	//xterm/kterm                                  //~v501I~
    	return 0;                                                  //~v501I~
	if (ukbdlnxc_pidsetlock())	//create pid lock file             //~v386I~
        return 0;                                                  //~v386I~
//create save file                                                 //~v386I~
	if ((Sfdlockfile=open(Slockfile,O_WRONLY|O_CREAT|O_EXCL|O_SYNC,0666))<=0)//~v386R~
    {                                                              //~v386I~
    	if (errno!=EEXIST)	//not exist err                        //~v386R~
            printf("%s create-open failed,rc=%d\n",Slockfile,errno);//~v386R~
        printf("\nukbdlnxc:kbd save file already exist\n");        //~v524R~
        return 0;                                                  //~v386I~
    }                                                              //~v386I~
    Slockstatus|=LS_FIRST;  //save file created                    //~v524I~
//header                                                           //~v386R~
    ukbdlnxc_lockfwrite("KeyInfo:",8);                             //~v386I~
//keyinfo                                                          //~v386I~
    ukbdlnxc_lockfwrite("Funckey:",8);                             //~v386I~
    ctr=PFKTNO;                                                    //~v386I~
    ukbdlnxc_lockfwrite(&ctr,sizeof(ctr));                         //~v386I~
//  len=sizeof(FUNCKEYTBL)*ctr;                                    //~v386I~//~v6D0R~
    len=(int)sizeof(FUNCKEYTBL)*ctr;                               //~v6D0I~
    ukbdlnxc_lockfwrite(Spfktbl[0],len);                           //~v386I~
//compose                                                          //~v386I~
    ukbdlnxc_lockfwrite("Compose:",8);                             //~v386I~
    len=sizeof(Ssavecompose);                                      //~v386I~
    ukbdlnxc_lockfwrite(&Ssavecompose,len);                        //~v386I~
//string                                                           //~v386I~
    ukbdlnxc_lockfwrite("String :",8);                             //~v386I~
    ctr=FSTNO;                                                     //~v386I~
    ukbdlnxc_lockfwrite(&ctr,sizeof(ctr));                         //~v386I~
//  len=sizeof(FUNCSTRTBL)*ctr;                                    //~v386I~//~v6D0R~
    len=(int)sizeof(FUNCSTRTBL)*ctr;                               //~v6D0I~
    ukbdlnxc_lockfwrite(&Sstrtbl,len);                             //~v386I~
//write total string len                                           //~v386I~
    for (ii=0,len=0;ii<FSTNO;ii++)        //keycode                //~v386I~
    {                                                              //~v386I~
        oldstr=Sstrtbl[ii].FSTstrold;                              //~v386I~
        if (oldstr)                                                //~v386I~
//      	len+=strlen(oldstr)+1;	//total len                    //~v386I~//~v6D0R~
        	len+=(int)strlen(oldstr)+1;	//total len                //~v6D0I~
    }//for                                                         //~v386I~
    ukbdlnxc_lockfwrite(&len,sizeof(len));                         //~v386I~
//write string                                                     //~v386I~
    for (ii=0;ii<FSTNO;ii++)        //keycode                      //~v386I~
    {                                                              //~v386I~
        oldstr=Sstrtbl[ii].FSTstrold;                              //~v386I~
//printf("savestr ii=%d,%s\n",ii,oldstr);                          //~v525R~
        if (oldstr)                                                //~v386I~
        {                                                          //~v386I~
//      	len=strlen(oldstr)+1;                                  //~v386I~//~v6D0R~
        	len=(int)strlen(oldstr)+1;                             //~v6D0I~
    		ukbdlnxc_lockfwrite(oldstr,len);                       //~v386I~
        }                                                          //~v386I~
    }//for                                                         //~v386I~
//endmark                                                          //~v386I~
    ukbdlnxc_lockfwrite("EndFile:",8);                             //~v386I~
    if (close(Sfdlockfile))	//force write                          //~v386R~
    {                                                              //~v386I~
    	printf("%s close failed,rc=%d\n",Slockfile,errno);         //~v386R~
        return 0;                                                  //~v386I~
    }                                                              //~v386I~
    if (chmod(Slockfile,0666))	//deney umask                      //~v386I~
    	printf("%s chmod failed,rc=%d\n",Slockfile,errno);         //~v386I~
	Slockfsavedsw=1;	//saved by me                              //~v386R~
    return 1;                                                      //~v386I~
}//ukbdlnxc_save1st                                                //~v386I~
//*********************************************************************//~v386I~
//* chk last session by ock file,restre saved status if last.      //~v386I~
//* ret 1:last session,0:not last                                  //~v386I~
//*********************************************************************//~v386I~
int ukbdlnxc_restorelast(void)                                     //~v386I~
{                                                                  //~v386I~
    int ctr,len,ii,jj;                                             //~v386R~
    char buff[16];                                                 //~v386I~
    char *poldstrsaved0,*poldstrsaved,*poldstr;                    //~v386R~
    PFUNCSTRTBL pstrt,pstrtsaved,pstrtsaved0;                      //~v386I~
    PFUNCKEYTBL pfkt,pfktsaved,pfktsaved0;                         //~v386I~
    struct kbdiacrs *pkdsaved;                                     //~v386I~
//******************************                                   //~v386I~
	if (Stermid)	//xterm/kterm                                  //~v501I~
    	return 0;                                                  //~v501I~
//  if (ukbdlnxc_pidresetlock())	//delete pid lock file         //~v524R~
//      return 1;			//restore                              //~v524R~
	if (ukbdlnxc_pidchklock())	//held by other                    //~v386I~
        return 0;			//leave key change                     //~v386R~
	if ((Sfdlockfile=open(Slockfile,O_RDONLY,0))<=0)               //~v386R~
    {                                                              //~v386I~
        printf("%s open failed,rc=%d\n",Slockfile,errno);          //~v386I~
        return 1;                                                  //~v386R~
    }                                                              //~v386I~
//hdr                                                              //~v386R~
    if (ukbdlnxc_lockfread(buff,8))                                //~v386R~
        return 1;			//restore                              //~v386I~
    if (memcmp(buff,"KeyInfo:",8))                                 //~v386I~
    {                                                              //~v386I~
    	printf("%s header corrupted\n",Slockfile);                 //~v386R~
        return 1;			//restore                              //~v386I~
    }                                                              //~v386I~
//keyinfo                                                          //~v386I~
    if (ukbdlnxc_lockfread(buff,8+sizeof(ctr)))                    //~v386I~
        return 1;			//restore                              //~v386I~
    ctr=*(int*)(void*)(buff+8);                                    //~v386I~
	if (ctr!=PFKTNO)                                               //~v386I~
    {                                                              //~v386I~
    	printf("%s data-1 corrupted\n",Slockfile);                 //~v386R~
        return 1;			//restore                              //~v386I~
    }                                                              //~v386I~
//  len=sizeof(FUNCKEYTBL)*ctr;                                    //~v386I~//~v6D0R~
    len=(int)sizeof(FUNCKEYTBL)*ctr;                               //~v6D0I~
//  pfktsaved0=pfktsaved=(PFUNCKEYTBL)malloc(len);                 //~v386I~//~v6D0R~
    pfktsaved0=pfktsaved=(PFUNCKEYTBL)malloc((size_t)len);         //~v6D0I~
    if (ukbdlnxc_lockfread(pfktsaved,len))                         //~v386I~
        return 1;			//restore                              //~v386I~
//compose                                                          //~v386I~
    if (ukbdlnxc_lockfread(buff,8))                                //~v386I~
        return 1;			//restore                              //~v386I~
    len=sizeof(Ssavecompose);                                      //~v386I~
//  pkdsaved=(struct kbdiacrs *)malloc(len);                       //~v386I~//~v6D0R~
    pkdsaved=(struct kbdiacrs *)malloc((size_t)len);               //~v6D0I~
    if (ukbdlnxc_lockfread(pkdsaved,len))                          //~v386I~
        return 1;			//restore                              //~v386I~
//string                                                           //~v386I~
    if (ukbdlnxc_lockfread(buff,8+sizeof(ctr)))                    //~v386I~
        return 1;			//restore                              //~v386I~
    ctr=*(int*)(void*)(buff+8);                                    //~v386I~
	if (ctr!=FSTNO)                                                //~v386I~
    {                                                              //~v386I~
    	printf("%s data-2 corrupted\n",Slockfile);                 //~v386R~
        return 1;			//restore                              //~v386I~
    }                                                              //~v386I~
//  len=sizeof(FUNCSTRTBL)*ctr;                                    //~v386I~//~v6D0R~
    len=(int)sizeof(FUNCSTRTBL)*ctr;                               //~v6D0I~
//  pstrtsaved0=pstrtsaved=(PFUNCSTRTBL)malloc(len);               //~v386I~//~v6D0R~
    pstrtsaved0=pstrtsaved=(PFUNCSTRTBL)malloc((size_t)len);       //~v6D0I~
    if (ukbdlnxc_lockfread(pstrtsaved,len))                        //~v386I~
        return 1;			//restore                              //~v386I~
//read funcstr                                                     //~v386I~
    if (ukbdlnxc_lockfread(buff,sizeof(len)))                      //~v386I~
        return 1;			//restore                              //~v386I~
//  len=*(int*)(void*)buff;                                        //~v386I~//~v6q3R~
//  len=USTR2UL(buff);  //get int value                            //~v6q3I~//~v6D0R~
    len=(int)USTR2UL(buff);  //get int value                       //~v6D0I~
//  poldstrsaved0=poldstrsaved=(char *)malloc(len);                //~v386I~//~v6D0R~
    poldstrsaved0=poldstrsaved=(char *)malloc((size_t)len);        //~v6D0I~
    if (ukbdlnxc_lockfread(poldstrsaved,len))                      //~v386I~
        return 1;			//restore                              //~v386I~
//endmark                                                          //~v386I~
    if (ukbdlnxc_lockfread(buff,8))                                //~v386R~
        return 1;			//restore                              //~v386I~
//chk last session                                                 //~v386I~
    if (close(Sfdlockfile))                                        //~v386R~
    {                                                              //~v386I~
    	printf("%s last close faied,rc=%d\n",Slockfile,errno);     //~v386R~
        return 1;			//restore                              //~v386I~
    }                                                              //~v386I~
//  if (unlink(Slockfile))                                         //~v524R~
//  {                                                              //~v524R~
//  	printf("%s unlink faied,rc=%d\n",Slockfile,errno);         //~v524R~
//      return 1;			//restore                              //~v524R~
//  }                                                              //~v524R~
//***repl info to be restored                                      //~v386I~
	if (!Slockfsavedsw)	//not by me                                //~v386R~
    {                                                              //~v386I~
//keyinfo                                                          //~v386I~
        for (ii=0,pfkt=Spfktbl[0];ii<PFKTNO;ii++,pfkt++,pfktsaved++)//~v386R~
            for (jj=0;jj<FKT_MAX_SYM;jj++)                         //~v386R~
                pfkt->FKTfksaveold[jj]=pfktsaved->FKTfksaveold[jj];//~v386R~
//compose                                                          //~v386I~
        memcpy(&Ssavecompose,pkdsaved,sizeof(Ssavecompose));       //~v386R~
//string                                                           //~v386I~
//      for (ii=0,pstrt=Sstrtbl,poldstr=poldstrsaved;ii<PFKTNO;ii++,pstrt++,pstrtsaved++)//~v525R~
        for (ii=0,pstrt=Sstrtbl,poldstr=poldstrsaved;ii<FSTNO;ii++,pstrt++,pstrtsaved++)//~v525R~
        {                                                          //~v386R~
//printf("readstr ii=%d,%p=%s\n",ii,pstrtsaved->FSTstrold,poldstr);//~v525R~
            if ((pstrt->FSTstrold=pstrtsaved->FSTstrold)!=0)       //~v386R~
            {                                                      //~v386R~
//              len=strlen(poldstr)+1;                             //~v386R~//~v6D0R~
                len=(int)strlen(poldstr)+1;                        //~v6D0I~
//              pstrt->FSTstrold=malloc(len);   //for later free   //~v386R~//~v6D0R~
                pstrt->FSTstrold=malloc((size_t)len);   //for later free//~v6D0I~
//              memcpy(pstrt->FSTstrold,poldstr,len);              //~v386R~//~v6D0R~
                memcpy(pstrt->FSTstrold,poldstr,(size_t)len);      //~v6D0I~
                poldstr+=len;                                      //~v386R~
            }                                                      //~v386R~
        }                                                          //~v386R~
    }                                                              //~v386I~
    free(pfktsaved0);                                              //~v386I~
    free(pstrtsaved0);                                             //~v386I~
    free(poldstrsaved0);                                           //~v386I~
    return 1;			//restore                                  //~v386I~
}//ukbdlnxc_restorelast                                            //~v386I~
//*********************************************************************//~v386I~
//* write                                                          //~v386I~
//*********************************************************************//~v386I~
int ukbdlnxc_lockfwrite(void *Paddr,int Plen)                      //~v386I~
{                                                                  //~v386I~
//******************************                                   //~v386I~
    if (write(Sfdlockfile,Paddr,(size_t)Plen)==Plen)               //~v386R~
    	return 0;                                                  //~v386I~
    printf("%s write err,rc=%d\n",Slockfile,errno);                //~v386R~
    return 4;                                                      //~v386I~
}//ukbdlnxc_lockfwrite                                             //~v386I~
//*********************************************************************//~v386I~
//* read                                                           //~v386I~
//*********************************************************************//~v386I~
int ukbdlnxc_lockfread(void *Paddr,int Plen)                       //~v386I~
{                                                                  //~v386I~
//******************************                                   //~v386I~
    if (read(Sfdlockfile,Paddr,(size_t)Plen)==Plen)                //~v386R~
    	return 0;                                                  //~v386I~
    printf("%s read err,rc=%d\n",Slockfile,errno);                 //~v386I~
    return 4;                                                      //~v386I~
}//ukbdlnxc_lockfread                                              //~v386I~
//*********************************************************************//~v386I~
//* setlock                                                        //~v386I~
//* rc:0:lock gotten,4:err                                         //~v386I~
//*********************************************************************//~v386I~
int ukbdlnxc_pidsetlock(void)                                      //~v386I~
{                                                                  //~v386I~
//  char lockpidfile[64];                                          //~v524R~
//  pid_t pid;                                                     //~v524R~
//  int fd;                                                        //~v524R~
//******************************                                   //~v386I~
//create lock file                                                 //~v386M~
//  pid=getpid();                                                  //~v524R~
//  sprintf(lockpidfile,"%s_%d",Slockfile,pid);                    //~v524R~
//  if ((fd=open(lockpidfile,O_WRONLY|O_CREAT,0666))<=0)           //~v524R~
    if ((Sfdlockfile2=open(Slockfile2,O_WRONLY|O_CREAT,0666))<=0)  //~v524I~
    {                                                              //~v386M~
        printf("%s create-open failed,rc=%d\n",Slockfile2,errno);  //~v524R~
        return 4;                                                  //~v386I~
    }                                                              //~v386M~
//  Spidlocksw=1;	//pidlock file allocated sw                    //~v524R~
    if (flock(Sfdlockfile2,LOCK_SH))                               //~v524I~
    {                                                              //~v524I~
        printf("%s flock(SHARED) failed,rc=%d\n",Slockfile2,errno);//~v524I~
        return 4;                                                  //~v524I~
    }                                                              //~v524I~
    Slockstatus|=LS_SH;	//SHARED gotten                            //~v524I~
//  if (close(fd))//force write                                    //~v524R~
//  {                                                              //~v524R~
//  	printf("%s close failed,rc=%d\n",lockpidfile,errno);       //~v524R~
//      return 4;                                                  //~v524R~
//  }                                                              //~v524R~
	return 0;                                                      //~v386I~
}//ukbdlnxc_pidsetlock(void)                                       //~v386I~
//*********************************************************************//~v386I~
//* resetlock                                                      //~v386I~
//* rc:0:lock reset,4:err                                          //~v386I~
//*********************************************************************//~v386I~
int ukbdlnxc_pidresetlock(void)                                    //~v386I~
{                                                                  //~v386I~
//  char lockpidfile[64];                                          //~v524R~
//  pid_t pid;                                                     //~v524R~
//******************************                                   //~v386I~
//  if (!Spidlocksw)                                               //~v524R~
    if (!(Slockstatus & (LS_SH|LS_EX)))	//SHARED not gotten        //~v524R~
    	return 1;                                                  //~v386R~
//create lock file                                                 //~v386I~
//  pid=getpid();                                                  //~v524R~
//  sprintf(lockpidfile,"%s_%d",Slockfile,pid);                    //~v524R~
//  if (unlink(lockpidfile))                                       //~v524R~
//  {                                                              //~v524R~
//  	printf("%s unlink failed,rc=%d\n",lockpidfile,errno);      //~v524R~
//      return 4;			//restore                              //~v524R~
//  }                                                              //~v524R~
//  Spidlocksw=0;                                                  //~v524R~
    if (flock(Sfdlockfile2,LOCK_UN))                               //~v524I~
    {                                                              //~v524I~
        printf("%s flock(UNLOCK) failed,rc=%d\n",Slockfile2,errno);//~v524I~
        return 4;                                                  //~v524I~
    }                                                              //~v524I~
    Slockstatus&=~(LS_SH|LS_EX);	//reset lock                   //~v524I~
	return 0;                                                      //~v386I~
}//ukbdlnxc_pidresetlock(void)                                     //~v386I~
//*********************************************************************//~v386I~
//* chklock                                                        //~v386I~
//* rc:0:free,1:hold by other                                      //~v386I~
//*********************************************************************//~v386I~
int ukbdlnxc_pidchklock(void)                                      //~v386I~
{                                                                  //~v386I~
//  PUDIRLIST pudirlist;                                           //~v524R~
//  char lockpidfile[64];                                          //~v524R~
//******************************                                   //~v386I~
//  sprintf(lockpidfile,"%s_*",Slockfile);                         //~v524R~
//  if (udirlistnomsg(lockpidfile,FILE_NORMAL,&pudirlist,0)>0)//nosort                    int Psorttype)//~v524R~
//  {                                                              //~v524R~
//      ufree(pudirlist);                                          //~v524R~
//      return 1;           //not last                             //~v524R~
//  }                                                              //~v524R~
    if (flock(Sfdlockfile2,LOCK_EX|LOCK_NB)) 	//EXCLUSIVE by NO BLOCK mode//~v524I~
    {                                                              //~v524I~
    	if (errno==EWOULDBLOCK)	//blocked                          //~v524I~
        {                                                          //~v524I~
            printf("\nukbdlnxc:another xe is active at termination\n");//~v524R~
			return 1;           //not last                         //~v524I~
        }                                                          //~v524I~
        printf("%s flock(EXCLUSIVE) failed,rc=%d\n",Slockfile2,errno);//~v524I~
        return 4;                                                  //~v524I~
    }                                                              //~v524I~
    Slockstatus|=(LS_EX|LS_LAST);	//EXCLUSIVE lock gotten        //~v524I~
    printf("\nukbdlnxc:restored kbd status\n");                    //~v524R~
	return 0;                                                      //~v386I~
}//ukbdlnxc_pidchklock                                             //~v524R~
//**********************************************************************//~v57yI~
//* process input mapfile                                          //~v57yI~
//*    record fmt   ;; @key=keyname=^[xxx                          //~v57yI~
//**********************************************************************//~v57yI~
//int ukbdlnxc_chngttkey(char *Ppfile)                             //~v5mvR~
int ukbdlnxc_chngttkey(int Popt,char *Ppfile)                      //~v5mvI~
{                                                                  //~v57yI~
	PFUNCKEYTBL pfkt;                                              //~v57yI~
    int ii,rc=0,modx,errsw/*,idlen*/;                                  //~v57yR~//~v6b9R~
	int foundsw,keynmlen,strll,strll2;                         //~v57ZR~
    FILE *fh;                                                      //~v57yI~
    char buff[512],*pc,*keynm,*keynme,*str,*stre,*pc2;             //~v57ZR~
    int termsimid,applysw;                                         //~v57LI~
    char *envterm;                                                 //~v57LI~
    char *envxeterm;                                               //~v57NI~
    int termid,dupid,len;                                          //~v57NR~
    char fpath[_MAX_PATH];                                         //~v5k8I~
    int  escsw;                                                    //~v5muI~
	static int Sdupchk;                                            //~v5mvI~
//************************                                         //~v57yI~
	if (Sdupchk)                                                   //~v5mvI~
    	return 1;                                                  //~v5mvI~
    Sdupchk=1;                                                     //~v5mvI~
    envterm=getenv("TERM");                                        //~v57LI~
    envxeterm=getenv("XETERM");                                    //~v57NI~
//  termsimid=ukbdl_gettermid() & TERM_SIMID; 	//terminal simulater//~v57NR~
    termid=ukbdl_gettermid();                                      //~v57NI~
    termsimid=termid  & TERM_SIMID; 	//terminal simulater       //~v57NI~
    if (termid!=TERM_TTYLCONS)  //under X                          //~v57NI~
		ukbdlnxc_setupcktx();	//default setup for X term         //~v57NI~
    if (!strcmp(Ppfile,"-"))                                       //~v57yI~
    	fh=stdin;                                                  //~v57yI~
    else                                                           //~v57yI~
    {                                                              //~v5k8I~
//      if (!(fh=fopen(Ppfile,"r")))  //open input fail            //~v5k8R~
        ufullpath(fpath,Ppfile,sizeof(fpath));                     //~v5k8R~
        if (!(fh=fopen(fpath,"r")))  //open input fail             //~v5k8I~
        {                                                          //~v5mvI~
		  if (!(Popt & UKBDLNXC_CTKINIT))                          //~v5mvR~
            uerrexit("input file(%s) open err",                    //~v57yR~
                        "入力ファイル(%s) のオープンエラー",       //~v57yR~
                            Ppfile);                               //~v57yR~
        }                                                          //~v5mvI~
    }                                                              //~v5k8I~
    if (fh<=0)                                                     //~v57yI~
    {                                                              //~v57yI~
	  if ((Popt & UKBDLNXC_CTKINIT))                               //~v5mvI~
      {                                                            //~v5mvI~
        uerrmsg("keycode map file(%s) open failed rc=%d\n",0,      //~v5mvR~
                Ppfile,errno);                                     //~v5mvR~
        return 4;                                                  //~v5mvI~
      }                                                            //~v5mvI~
      else                                                         //~v5mvI~
        uerrexit("keycode map file open failed rc=%d\n",0,         //~v57yI~
                Ppfile);                                           //~v57yI~
    }                                                              //~v57yI~
    rc=0;                                                          //~v57yI~
//  idlen=strlen(Skfstrlineid);	//keyname pos                      //~v57NR~//~v6b9R~
    applysw=0;                                                     //~v57LI~
    while (fgets(buff,sizeof(buff),fh))                            //~v57yI~
    {                                                              //~v57yI~
        pc=buff+strspn(buff," \t");                                //~v57yI~
        if (*pc=='#'||*pc=='!'||*pc=='\n')                         //~v57zR~
        	continue;                                              //~v57yI~
        if (*pc=='[')	//termname section                         //~v57LI~
        {                                                          //~v57LI~
            pc++;                                                  //~v57LI~
            len=0;                                                 //~v57NI~
        	if (envxeterm && *envxeterm && !memicmp(pc,envxeterm,strlen(envxeterm)))	//by TERM env//~v57NR~
//              len=strlen(envxeterm);                             //~v57NI~//~v6D0R~
                len=(int)strlen(envxeterm);                        //~v6D0I~
            else                                                   //~v57NI~
        	if (!memicmp(pc,TERMNAME_COMM,sizeof(TERMNAME_COMM)-1))	//common//~v57LR~
//              applysw=1;                                         //~v57NR~
        		len=sizeof(TERMNAME_COMM)-1;	//common           //~v57NI~
            else                                                   //~v57LI~
        	if (!memicmp(pc,TERMNAME_G,sizeof(TERMNAME_G)-1))	//gnome-terminal//~v57LR~
            {                                                      //~v57LI~
            	if (termsimid==TERM_GTERMSIM)                      //~v57LI~
//                  applysw=1;                                     //~v57NR~
        			len=sizeof(TERMNAME_G)-1;	//common           //~v57NI~
//              else                                               //~v57NR~
//                  applysw=0;                                     //~v57NR~
            }                                                      //~v57LI~
            else                                                   //~v57LI~
        	if (!memicmp(pc,TERMNAME_K,sizeof(TERMNAME_K)-1))	//kterm//~v57LR~
            {                                                      //~v57LI~
            	if (termsimid==TERM_KTERMSIM)                      //~v57LI~
//                  applysw=1;                                     //~v57NR~
        	        len=sizeof(TERMNAME_K)-1; 	//kterm            //~v57NI~
//              else                                               //~v57NR~
//                  applysw=0;                                     //~v57NR~
            }                                                      //~v57LI~
            else                                                   //~v57LI~
        	if (!memicmp(pc,TERMNAME_X,sizeof(TERMNAME_X)-1))	//xterm//~v57LR~
            {                                                      //~v57LI~
            	if (termsimid==TERM_XTERMSIM)                      //~v57LI~
//                  applysw=1;                                     //~v57NR~
        	        len=sizeof(TERMNAME_X)-1;	//xterm            //~v57NR~
//              else                                               //~v57NR~
//                  applysw=0;                                     //~v57NR~
            }                                                      //~v57LI~
            else                                                   //~v57LI~
        	if (envterm && *envterm && !memicmp(pc,envterm,strlen(envterm)))	//by TERM env//~v57NR~
//              applysw=1;                                         //~v57NR~
//      	    len=strlen(envterm); 	//by TERM env              //~v57NI~//~v6D0R~
        	    len=(int)strlen(envterm); 	//by TERM env          //~v6D0I~
//          else                                                   //~v57NR~
//              applysw=0;                                         //~v57NR~
            if (len && *(pc+len)==']')                             //~v57NR~
                applysw=1;                                         //~v57NI~
            else                                                   //~v57NI~
                applysw=0;                                         //~v57NI~
            continue;	//section hdr                              //~v57LI~
        }                                                          //~v57LI~
        if (!applysw)                                              //~v57LI~
        	continue;                                              //~v57LI~
    	for (;;)                                                   //~v57yI~
        {                                                          //~v57yI~
        	errsw=1;                                               //~v57yI~
//          if (!(pc=umemstri(buff,Skfstrlineid,strlen(buff))))    //~v57NR~//~v6D1R~
            if (!(pc=umemstri(buff,Skfstrlineid,(unsigned)strlen(buff))))//~v6D1I~
            {                                                      //~v57yI~
                uerrmsg("line format err:line-id \"%s\" is not found: %s",0,//~v57yR~
                            Skfstrlineid,buff);                    //~v57NR~
                break;                                             //~v57yR~
            }                                                      //~v57yI~
            keynm=pc+strlen(Skfstrlineid);  //keyname pos          //~v57NR~
            keynm+=strspn(keynm," ");                              //~v57yR~
//          keynme=strpbrk(keynm," \t,=");                         //~v5k7R~
//          if (!keynme)                                           //~v5k7R~
//          {                                                      //~v5k7R~
//              uerrmsg("line format err:no string found: %s",0,   //~v5k7R~
//                          buff);                                 //~v5k7R~
//              break;                                             //~v5k7R~
//          }                                                      //~v5k7R~
            modx=0;                                                //~v57yR~
            if (*(keynm+1)=='+')                                   //~v57yR~
                for (;modx<4;modx++)                               //~v57yR~
                    if (toupper(*keynm)==*Sshiftidstr[modx])       //~v57yR~
                    {                                              //~v57yR~
                        keynm+=2;                                  //~v57yR~
                        break;                                     //~v57yR~
                    }                                              //~v57yR~
            if (modx>=4)                                           //~v57yR~
            {                                                      //~v57yR~
                uerrmsg("Shift modifier err: %s",0,                //~v57yR~
                            buff);                                 //~v57yR~
                break;                                             //~v57yR~
            }                                                      //~v57yI~
            keynm+=strspn(keynm," ");                              //~v5k7I~
            keynme=strpbrk(keynm," \t,=");                         //~v5k7I~
            if (!keynme)                                           //~v5k7I~
            {                                                      //~v5k7I~
                uerrmsg("line format err:no string found: %s",0,   //~v5k7I~
                            buff);                                 //~v5k7I~
                break;                                             //~v5k7I~
            }                                                      //~v5k7I~
//          keynmlen=(ULONG)keynme-(ULONG)keynm;                   //~v57yR~//~v6D0R~
            keynmlen=PTRDIFF(keynme,keynm);                        //~v6D0I~
        	pc=strchr(keynme,'=');                                 //~v57yI~
            if (!pc)                                               //~v57yI~
            {                                                      //~v57yI~
                uerrmsg("line format err:no string found: %s",0,   //~v57yI~
                            buff);                                 //~v57yI~
                break;                                             //~v57yI~
            }                                                      //~v57yI~
            pc++;                                                  //~v57yR~
            pc+=strspn(pc," ");                                    //~v57yR~
            if (*pc=='#'||*pc=='\n'||*pc=='\r')                    //~v5k9I~
            {                                                      //~v5k9I~
                errsw=0;                                           //~v5k9I~
            	break;//next line                                  //~v5k9R~
            }                                                      //~v5k9I~
        	if (*pc!='^'||*(pc+1)!='[')                            //~v57yR~
        	{                                                      //~v57yI~
//              uerrmsg("line format err:string should start by \"^[\": %s",0,//~v5muR~
//                          buff);                                 //~v5muR~
//              break;                                             //~v5muR~
                escsw=0;                                           //~v5muI~
            }                                                      //~v57yI~
            else                                                   //~v5muI~
                escsw=1;                                           //~v5muI~
            str=pc;                                                //~v57yR~
//          stre=strpbrk(str," \t,\n");                            //~v5k9R~
            stre=strpbrk(str," \t,\n,\r#");                        //~v5k9R~
            if (stre)                                              //~v57yR~
//              strll=(ULONG)stre-(ULONG)str;                      //~v57yR~//~v6D0R~
                strll=PTRDIFF(stre,str);                           //~v6D0I~
            else                                                   //~v57yR~
//              strll=strlen(str);                                 //~v57yR~//~v6D0R~
                strll=(int)strlen(str);                            //~v6D0I~
            for (ii=strll,strll2=0,pc=pc2=str;ii>0;ii--,pc++)      //~v57ZR~
            {                                                      //~v57ZI~
                if (*pc=='\\' && ii>=4 && toupper(*(pc+1))=='X')   //~v57ZI~
                {                                                  //~v57ZI~
                    if (ugethex(pc+2,pc2,2)<0)                     //~v57ZR~
                        break;                                     //~v57ZI~
                    pc+=3;                                         //~v57ZI~
                    ii-=3;                                         //~v57ZR~
                    pc2++;                                         //~v57ZI~
                }                                                  //~v57ZI~
                else                                               //~v57ZI~
                    *pc2++=*pc;                                    //~v57ZI~
                strll2++;                                          //~v57ZI~
            }                                                      //~v57ZI~
            strll=strll2;                                          //~v57ZI~
            if (ii>0)                                              //~v57ZI~
            {                                                      //~v57ZI~
                uerrmsg("invalid hex notation(%s)",0,              //~v57ZI~
                        pc);                                       //~v57ZI~
                break;                                             //~v57ZI~
            }                                                      //~v57ZI~
            foundsw=0;                                             //~v57yR~
            for (ii=0;ii<PFKTNO;ii++)        //keycode             //~v57yR~
            {                                                      //~v57yR~
                pfkt=Spfktbl[ii];                                  //~v57yR~
                if (keynmlen==strlen(pfkt->FKTkeyname)             //~v57yR~
//              &&  !memicmp(pfkt->FKTkeyname,keynm,keynmlen))     //~v57yR~//~v6D0R~
                &&  !memicmp(pfkt->FKTkeyname,keynm,(size_t)keynmlen))//~v6D0I~
                {                                                  //~v57yR~
                    foundsw=1;                                     //~v57yR~
                    break;                                         //~v57yR~
                }                                                  //~v57yR~
            }                                                      //~v57yR~
            if (!foundsw)                                          //~v57yR~
            {                                                      //~v57yR~
                uerrmsg("keyname (%.*s) is invalid: %s",0,         //~v57yR~
                        keynmlen,keynm,buff);                      //~v57yR~
                break;                                             //~v57yI~
            }                                                      //~v57yR~
            if (pfkt->FKTsymid==K_CTRLR)                           //~v5mvR~
              modx=MODX_CONTROL;                                   //~v5mvI~
          if (escsw) //start with 0x1b                             //~v5muI~
          {                                                        //~v5muI~
            if (strll<=3)   //del req                              //~v57yR~
                pfkt->FKTfkassign[modx]=0;                         //~v57yR~
            else                                                   //~v57yR~
            {                                                      //~v57yR~
//              pc=malloc(strll);                                  //~v57yR~//~v6D0R~
                pc=malloc((size_t)strll);                          //~v6D0I~
                *pc=0x1b;                                          //~v57yR~
//              memcpy(pc+1,str+2,strll-2);                        //~v57yR~//~v6D0R~
                memcpy(pc+1,str+2,(size_t)strll-2);                //~v6D0I~
                *(pc+strll-1)=0;                                   //~v57yR~
//                pfkt->FKTttstring[modx]=pc;                      //~v57NR~
//                pfkt->FKTflag[modx]=FKT_TTREPKEY;                //~v57NR~
////add to string chk tbl                                          //~v57NR~
//                pfkt->FKTfkassign[modx]=0; //skip keysym change  //~v57NR~
//                Scurseskeytbl[Scktno].CKTpfkt=pfkt;              //~v57NR~
//                Scurseskeytbl[Scktno].CKTmodx=modx;              //~v57NR~
//                Scurseskeytbl[Scktno].CKTstring=pc;              //~v57NR~
//                Scurseskeytbl[Scktno].CKTlen=strll-1;            //~v57NR~
//                Scktno++;                                        //~v57NR~
				if (termid!=TERM_TTYLCONS)  //under X              //~v57NI~
					dupid=ukbdlnxc_dupstrchk(pc,pfkt,modx,strll-1);//~v57NR~
                else                                               //~v57NI~
                	dupid=0;                                       //~v57NI~
                if (!dupid)	//not dup                              //~v57NR~
					ukbdlnxc_addstrtbl(ADDSTT_CLEARASSIGN,FKT_TTREPKEY,pc,pfkt,modx,strll-1);//~v57NR~
            }                                                      //~v57yR~
          }                                                        //~v5muI~
          else                                                     //~v5muI~
          {                                                        //~v5muI~
            if (strll<=0)   //del req                              //~v5muI~
                pfkt->FKTfkassign[modx]=0;                         //~v5muI~
            else                                                   //~v5muI~
            {                                                      //~v5muI~
                if (*str<=0x7f) //ascii                            //~v5muI~
                {                                                  //~v5muM~
              		uerrmsg("line format err:string should not start by ascii char: %s",0,//~v5muI~
                            buff);                                 //~v5muM~
		            break;                                         //~v5muM~
                }                                                  //~v5muM~
//              pc=malloc(strll+1);                                //~v5muI~//~v6D0R~
                pc=malloc((size_t)strll+1);                        //~v6D0I~
//              memcpy(pc,str,strll);                              //~v5muI~//~v6D0R~
                memcpy(pc,str,(size_t)strll);                      //~v6D0I~
                *(pc+strll)=0;                                     //~v5muI~
				if (termid!=TERM_TTYLCONS)  //under X              //~v5muI~
					dupid=ukbdlnxc_dupstrchk(pc,pfkt,modx,strll);  //~v5muI~
                else                                               //~v5muI~
                	dupid=0;                                       //~v5muI~
                if (!dupid)	//not dup                              //~v5muI~
                {                                                  //~v5muI~
                	if (Snonescentrytop<0)                         //~v5mvR~
				  		Snonescentrytop=Scktno; //use esc string not startwith 0x1b//~v5muI~
					ukbdlnxc_addstrtbl(ADDSTT_CLEARASSIGN,FKT_TTREPKEY,pc,pfkt,modx,strll);//~v5muI~
                }                                                  //~v5muI~
            }                                                      //~v5muI~
          }//not start with 0x1b                                   //~v5muI~
            errsw=0;                                               //~v57yI~
            break;                                                 //~v57yI~
        }//err break loop                                          //~v57yI~
        if (errsw)                                                 //~v57yI~
        	rc++;                                                  //~v57yI~
    }                                                              //~v57yI~
    if (rc)                                                        //~v57yI~
    {                                                              //~v5mvI~
	  if ((Popt & UKBDLNXC_CTKINIT))                               //~v5mvI~
        uerrmsgcat(";\"%s\" contain %d err line",0,                //~v5mvR~
  	               Ppfile,rc);                                     //~v5mvR~
      else                                                         //~v5mvI~
//      uerrexit("\"%s\" contain %d err line;fmt=\"%skeyname=string\". ",0,//~v5mvR~
//  	               Ppfile,rc,Skfstrlineid);                    //~v5mvR~
        uerrexit("\"%s\" contain %d err line;",0,                  //~v5mvI~
  	               Ppfile,rc);                                     //~v5mvI~
    }                                                              //~v5mvI~
    return rc;                                                     //~v57yI~
}//ukbdlnxc_chngttkey                                              //~v5mvR~
//**********************************************************************//~v5mvI~
//* setup rctl env                                                 //~v5mvI~
//**********************************************************************//~v5mvI~
int ukbdlnxc_setrctl(int Popt)                                     //~v5mvR~
{                                                                  //~v5mvI~
	int rc=0,symid,keycode;                                        //~v5mvR~
//    char *setstr=0;                                              //~v5mvR~
//    PFUNCSTRTBL pfst;                                            //~v5mvR~
//************************                                         //~v5mvI~
  	if (Stermnameid==TERM_TTYLCONS)	//set by ioctl                 //~v5mvI~
    {                                                              //~v5mvI~
		if (Popt & UKBDLNXC_SRCO_SET)	//set on/off               //~v5mvI~
        {                                                          //~v5mvI~
			if (Popt & UKBDLNXC_SRCO_SETON)	//set on               //~v5mvI~
                symid=Sfkt_RCTL.FKTfkassign[RCTL_ASSIGN];          //~v5mvR~
            else                                                   //~v5mvI~
                symid=K_CTRL;      //back to original              //~v5mvR~
        	keycode=Sfkt_RCTL.FKTkeycode;                          //~v5mvI~
//            pfst=Sfkt_RCTL.FKTpfst[RCTL_ASSIGN];                 //~v5mvR~
//            if (pfst)                                            //~v5mvR~
//                setstr=pfst->FSTstrnew;                          //~v5mvR~
        	if (symid && keycode)                                  //~v5mvR~
            {                                                      //~v5mvI~
            	ukbdlnxc_setkeysym(keycode,Smapid[RCTL_ASSIGN],symid);//~v5mvR~
//				if ((Popt & UKBDLNXC_SRCO_SETON) && setstr)        //~v5mvR~
//            		ukbdlnxc_setstring(symid,setstr);              //~v5mvR~
            }                                                      //~v5mvI~
        }                                                          //~v5mvI~
    }                                                              //~v5mvI~
    else                                                           //~v5mvI~
    {                                                              //~v5mvI~
		if (Popt & UKBDLNXC_SRCO_SET)	//set on/off               //~v5mvR~
        {                                                          //~v5mvI~
			if (Popt & UKBDLNXC_SRCO_SETON)	//set on               //~v5mvR~
                if (!(Gukbdl_flag & GUKBDL_RCTLSTRSET)) //string defined for RCTL key by ini file etc//~v5mvI~
                {                                                  //~v5mvI~
                    uerrmsg("Control_R key is not avail because mapping string is not defined by keymap file",0);//~v5mvR~
                    rc=4;   //no Esc string defined                //~v5mvI~
                }                                                  //~v5mvI~
        }                                                          //~v5mvI~
		if (Popt & UKBDLNXC_SRCO_SETSTR)	//set on/off           //~v5mvR~
			Gukbdl_flag|=GUKBDL_RCTLSTRSET;                        //~v5mvI~
    }                                                              //~v5mvI~
    return rc;                                                     //~v5mvR~
}//ukbdlnxc_setrctl                                                //~v5mvI~
//**********************************************************************//~v5mvI~
//* setup rctl string by ini file                                  //~v5mvI~
//**********************************************************************//~v5mvI~
int ukbdlnxc_setrctlstr(int Popt,char *Pstr)                       //~v5mvI~
{                                                                  //~v5mvI~
	PFUNCKEYTBL pfkt;                                              //~v5mvI~
    int ii,rc=0,modx,errsw;                                        //~v5mvR~
	int strll,strll2;                                              //~v5mvR~
    char *pc,*str,*stre,*pc2;                                      //~v5mvR~
    int dupid;                                                     //~v63CR~
    int  escsw;                                                    //~v5mvI~
    char buff[128];                                                //~v5mvI~
//************************                                         //~v5mvI~
//  if (termid==TERM_TTYLCONS)  //not under X                      //~v63CR~
    if (Stermid==TERM_TTYLCONS)  //not under X                     //~v63CI~
    	return 0;                                                  //~v5mvI~
	pfkt=&Sfkt_RCTL;                                               //~v5mvI~
    modx=MODX_CONTROL;                                             //~v5mvI~
    pc=Pstr+strspn(Pstr," ");                                      //~v5mvI~
    strncpy(buff,pc,sizeof(buff)-1);                               //~v5mvR~
    pc=buff;                                                       //~v5mvI~
    for (;;)                                                       //~v5mvI~
    {                                                              //~v5mvI~
        errsw=1;                                                   //~v5mvI~
        if (*pc!='^'||*(pc+1)!='[')                                //~v5mvI~
        {                                                          //~v5mvI~
            escsw=0;                                               //~v5mvI~
        }                                                          //~v5mvI~
        else                                                       //~v5mvI~
            escsw=1;                                               //~v5mvI~
        str=pc;                                                    //~v5mvI~
        stre=strpbrk(str," \t,\n,\r#");                            //~v5mvI~
        if (stre)                                                  //~v5mvI~
//          strll=(ULONG)stre-(ULONG)str;                          //~v5mvI~//~v6D0R~
            strll=PTRDIFF(stre,str);                               //~v6D0I~
        else                                                       //~v5mvI~
//          strll=strlen(str);                                     //~v5mvI~//~v6D0R~
            strll=(int)strlen(str);                                //~v6D0I~
        for (ii=strll,strll2=0,pc=pc2=str;ii>0;ii--,pc++)          //~v5mvI~
        {                                                          //~v5mvI~
            if (*pc=='\\' && ii>=4 && toupper(*(pc+1))=='X')       //~v5mvI~
            {                                                      //~v5mvI~
                if (ugethex(pc+2,pc2,2)<0)                         //~v5mvI~
                    break;                                         //~v5mvI~
                pc+=3;                                             //~v5mvI~
                ii-=3;                                             //~v5mvI~
                pc2++;                                             //~v5mvI~
            }                                                      //~v5mvI~
            else                                                   //~v5mvI~
                *pc2++=*pc;                                        //~v5mvI~
            strll2++;                                              //~v5mvI~
        }                                                          //~v5mvI~
        strll=strll2;                                              //~v5mvI~
        if (ii>0)                                                  //~v5mvI~
        {                                                          //~v5mvI~
            uerrmsg("invalid hex notation(%s)",0,                  //~v5mvI~
                    pc);                                           //~v5mvI~
            break;                                                 //~v5mvI~
        }                                                          //~v5mvI~
      if (escsw) //start with 0x1b                                 //~v5mvI~
      {                                                            //~v5mvI~
//          pc=malloc(strll);                                      //~v5mvI~//~v6D0R~
            pc=malloc((size_t)strll);                              //~v6D0I~
            *pc=0x1b;                                              //~v5mvI~
//          memcpy(pc+1,str+2,strll-2);                            //~v5mvI~//~v6D0R~
            memcpy(pc+1,str+2,(size_t)strll-2);                    //~v6D0I~
            *(pc+strll-1)=0;                                       //~v5mvI~
            dupid=ukbdlnxc_dupstrchk(pc,pfkt,modx,strll-1);        //~v5mvI~
            if (!dupid) //not dup                                  //~v5mvI~
                ukbdlnxc_addstrtbl(ADDSTT_CLEARASSIGN,FKT_TTREPKEY,pc,pfkt,modx,strll-1);//~v5mvI~
      }                                                            //~v5mvI~
      else                                                         //~v5mvI~
      {                                                            //~v5mvI~
            if (*str<=0x7f) //ascii                                //~v5mvI~
            {                                                      //~v5mvI~
                uerrmsg("string should not start by ascii char: %s",0,//~v5mvR~
                        Pstr);                                     //~v5mvR~
                break;                                             //~v5mvI~
            }                                                      //~v5mvI~
//          pc=malloc(strll+1);                                    //~v5mvI~//~v6D0R~
            pc=malloc((size_t)strll+1);                            //~v6D0I~
//          memcpy(pc,str,strll);                                  //~v5mvI~//~v6D0R~
            memcpy(pc,str,(size_t)strll);                          //~v6D0I~
            *(pc+strll)=0;                                         //~v5mvI~
            dupid=ukbdlnxc_dupstrchk(pc,pfkt,modx,strll);          //~v5mvI~
            if (!dupid) //not dup                                  //~v5mvI~
            {                                                      //~v5mvI~
                if (Snonescentrytop<0)                             //~v5mvR~
                    Snonescentrytop=Scktno; //use esc string not startwith 0x1b//~v5mvI~
                ukbdlnxc_addstrtbl(ADDSTT_CLEARASSIGN,FKT_TTREPKEY,pc,pfkt,modx,strll);//~v5mvI~
            }                                                      //~v5mvI~
      }//not start with 0x1b                                       //~v5mvI~
        errsw=0;                                                   //~v5mvI~
        break;                                                     //~v5mvI~
    }//err break loop                                              //~v5mvI~
    if (errsw)                                                     //~v5mvI~
    	rc++;                                                      //~v5mvI~
    return 0;                                                      //~v5mvI~
}//ukbdlnxc_setrctlstr                                             //~v5mvI~
//************************************************************************//~v6a0M~
//************************************************************************//~v6a0M~
char *uttyname(int fd)                                             //~v6a0M~
{                                                                  //~v6a0M~
#ifdef ARM                                                         //~v6a0M~
	return "/dev/ttyp01";	//assume not console but pts           //~v6a0M~
#else                                                              //~v6a0M~
	return ttyname(fd);                                            //~v6a0M~
#endif                                                             //~v6a0M~
}//uttyname                                                        //~v6a0M~
