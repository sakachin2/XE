//*CID://+v6a0R~:                             update#=   41;       //+v6a0R~
//****************************************************************
//ukbdlnxc.h                                                          //~v324R~
//****************************************************************
//v6a0:110520 Android porting(-DARM)                               //+v6a0I~
//v62H:091006_(LNX:BUG)avoid kbd hung by read next utf8 char when ENV is UTF8 but terminal emulator generate locale code//~v62HI~
//v5mv:080521 (LNX:CON)accept R-Ctrl key string definition max 4   //~v5mvI~
//v589:030819 integrate UKBDLNXC_-->UKBDL_                         //~v589I~
//v57Y:030802 (LNX)option of assign 0x7f to BS/DEL/CHAR            //~v57YI~
//v57N:030712 (LNX)defalt curses key setup for all X-term if not duplicated//~v57yI~
//v57y:030405 (LNX)support user key string specification file(for bush when runlevel=5)//~v57yR~
//v527:020217 option of clearok if not splitted                    //~v527I~
//v514:011212 dbcs clear mode option by --cd                       //~v514I~
//v50S:010920 UNX:clear screen before draw is option               //~v50SI~
//v501:010305 X support:kterm/xterm generate 0x1b[A(hard codes in input.c)//~v501I~
//v3a1:010226 LINUX support:print string(xekbchk) support          //~v3a1I~
//v39Z:010204 LINUX support:set is not avail but get is avail for pty//~v39ZI~
//            (get from tty corresponding to the pty)              //~v39ZI~
//v39b:001113 LINUX support:move posix logic(common to linux and aix) to ukbdl from ukbdlnxc//~v39bI~
//v395:001105 LINUX support:switch echo,noraw<-->noecho,raw for sub-shell mode//~v395I~
//v384:001001 LINUX support(hearing of key assign from kbdinit)    //~v384I~
//v362:000927 LINUX support(support getch where out of curses)     //~v362I~
//v347:000925 LINUX support(insert cursor option;BLINK and/or REVERSE)//~v347I~
//v342:000924 LINUX support(mono color option)                     //~v342R~
//v324 000813:LINUX support                                        //~v324I~
//**************************************************************** //~v324I~
#define MAXPFKNO         12                                        //~v384I~
#define KFSTRLINEID "KeyString:"                                   //~v57NR~
//**************************************************************** //~v3a1I~
typedef struct _FUNCKEYTBL{                                        //~v3a1M~
                            char *FKTkeyname;                      //~v3a1I~
                            int FKTsymid;                          //~v3a1M~
#define FKT_MAX_SYM 11                                             //~v3a1M~
//#define FKT_MAX_STR 4                                            //~v5mvR~
#define FKT_MAX_STR 8                                              //~v5mvI~
                            unsigned short FKTfkassign[FKT_MAX_SYM];//for all modifier//~v3a1M~
                            unsigned short FKTdoskey[FKT_MAX_SYM];//for all modifier//~v3a1M~
                            unsigned short FKTfksaveold[FKT_MAX_SYM];//save for restore//~v3a1M~
//                          int            FKTflag[FKT_MAX_SYM];   //~v57NR~
                            int            FKTflag[FKT_MAX_SYM][FKT_MAX_STR];//~v57NR~
#define FKT_USEORGSTR       0x01           //use func string of system//~v3a1M~
//#define FKT_USEXTERM        0x02           //FKTterminfo is set internaly for XTERM/KTERM//~v57NR~
#define FKT_XDEFAULT        0x02           //default for under X   //~v57NI~
#define FKT_TTREPKEY        0x04           //specifyed by parm file//~v57yR~
                            void          *FKTpfst[FKT_MAX_SYM];   //~v501M~
//                          char          *FKTttstring[FKT_MAX_SYM];//by keyfile//~v57NR~
                            char          *FKTttstring[FKT_MAX_SYM][FKT_MAX_STR];//by keyfile//~v57NI~
                            char          *FKTterminfo[FKT_MAX_SYM];//terminfo string//~v3a1I~
                            int FKTkeycode; //linux keycode        //~v3a1M~
                        } FUNCKEYTBL,*PFUNCKEYTBL;                 //~v3a1M~
typedef struct _FUNCSTRTBL{                                        //~v3a1M~
                        PFUNCKEYTBL FSTpfkt;                       //~v3a1M~
                        int     FSTmodx;                           //~v3a1M~
                        char   *FSTstrold;                         //~v3a1M~
                        char    FSTstrnew[16];                     //~v3a1I~
                    } FUNCSTRTBL,*PFUNCSTRTBL;                     //~v3a1M~
typedef struct _CURSESKEYTBL{                                      //~v3a1M~
                        PFUNCKEYTBL CKTpfkt;                       //~v3a1M~
                        int     CKTmodx;                           //~v3a1M~
                        char   *CKTstring;//terminfo string        //~v3a1M~
                        int     CKTlen;   //terminfo string len    //~v3a1M~
                    } CURSESKEYTBL,*PCURSESKEYTBL;                 //~v3a1M~
//**************************************************************** //~v384I~
int ukbdlnxc_init(int Popt,unsigned char *Pkeyassign);             //~v384R~
//#define UKBDLNXC_ALTPFKMASK 0x00000fff     //12bit;mask of ALT-L+Fn use(001 is F1//~v384R~
//#define UKBDLNXC_USEALTL    0x01000000     //use ALT-L as modifier key//~v589R~
//#define UKBDLNXC_USEALTR    0x02000000     //use alt-R as modifier key//~v589R~
//#define UKBDLNXC_COMPOSE    0x04000000  //set katakana composer  //~v589R~
//#define UKBDLNXC_CURSES     0x08000000  //use curses             //~v589R~
//#define UKBDLNXC_MONO       0x10000000  //mono color mode        //~v589R~
//#define UKBDLNXC_BLINK      0x20000000  //blink when inser mode  //~v589R~
//#define UKBDLNXC_REVERSE    0x40000000  //reverse when inser mode//~v589R~
//#define UKBDLNXC_CLEAR      0x80000000  //clear screen befaore draw//~v589R~
//#define UKBDLNXC_CLEARDBCS  0x00010000    //clear before scr draw//~v589R~
//#define UKBDLNXC_CLEAR1     0x00020000  //clearok if not splitted scr//~v589R~
//#define UKBDLNXC_7fBS       0x00040000  //force 0x7f to BS       //~v589R~
//#define UKBDLNXC_7fDEL      0x00080000  //force 0x7f to DEL      //~v589R~
//#define UKBDLNXC_7fCHAR     0x00100000  //force 0x7f to 0x7f     //~v589R~
//*********************************************************************//~v362I~
int ukbdlnxc_term(int Prestoresw);
//*********************************************************************//~v362I~
int ukbdlnxc_read(char *Pout,int *Pmodifier,int Pnowait);          //~v324R~
#define UKBDLNXCO_PEEK        0x01     //peek                      //~v62HI~
#define UKBDLNXCO_NEXT        0x02     //read with timeout         //~v62HI~
#define UKBDLNXC_MOD_SHIFTR   0x0001  //SHIFT-R and SHIFT-L is on both//~v324R~
#define UKBDLNXC_MOD_SHIFTL   0x0002                               //~v324R~
#define UKBDLNXC_MOD_CONTROL  0x0004                               //~v324R~
#define UKBDLNXC_MOD_ALT      0x0008                               //~v324R~
#define UKBDLNXC_MOD_ALTL     0x0200                               //~v324R~
#define UKBDLNXC_MOD_CTLR     0x0400     //=KBDSTF_RIGHTCONTROL    //~v5mvI~
#define UKBDLNXC_MOD_ALTR     0x0800                               //~v324R~
//#define UKBDLNXC_MOD_ALTR     0x0800                             //~v5mvR~
//*********************************************************************//~v362I~
int ukbdlnxc_getptty(void);                                        //~v39ZI~
//*********************************************************************//~v3a1I~
int ukbdlnxc_gettbl(PFUNCKEYTBL **Pppfkt,int *Ppfktno,             //~v3a1R~
					char **Ppreadbuff,int **Ppreadlen);            //~v3a1I~
//*********************************************************************//~v57yR~
//int ukbdlnxc_chngttkey(char *Ppfile);                            //~v5mvR~
int ukbdlnxc_chngttkey(int Popt,char *Ppfile);                     //~v5mvI~
#define UKBDLNXC_CTKINIT  0x01   //filename by inifile             //~v5mvI~
//*********************************************************************//~v57NI~
int  ukbdlnxc_getkeysym(int Pmsgopt,int Pkeycode,int Pkeymap);     //~v57NR~
//*********************************************************************//~v5mvI~
int ukbdlnxc_setrctl(int Popt);                                    //~v5mvI~
#define UKBDLNXC_SRCO_SETON    0x01                                //~v5mvI~
#define UKBDLNXC_SRCO_SET      0x02                                //~v5mvI~
#define UKBDLNXC_SRCO_SETSTR   0x04                                //~v5mvI~
//*********************************************************************//~v5mvI~
int ukbdlnxc_setrctlstr(int Popt,char *Pstr);                      //~v5mvR~
//*********************************************************************//+v6a0I~
char *uttyname(int fd);                                            //+v6a0I~
