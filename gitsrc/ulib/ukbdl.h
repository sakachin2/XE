//*CID://+v6s2R~:                             update#=   78;       //~v6s2R~
//****************************************************************
//ukbdl.h    (intf between ukbd and ukbdlnxc)                      //~v324R~
//****************************************************************
//v6s2:140213 add xfce4-terminal as terminal emulator              //+v6s2R~
//v6qh:131214 change terminal type:SCO Esc string by v6q6 as optional//~v6qhI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v62i:090905 termid:TELNET for Linux                              //~v62iI~
//v5nb:081003 (LNX)on CONSOLE, A_BOLD bit cause invalid char display. on CONSOLE init_color API works, so no BOLD required.//~v5nbI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5mv:080521 (LNX:CON)accept R-Ctrl key string definition max 4   //~v5mvI~
//v5kk:070531 (LNX)support Konsole as X-terminal                   //~v5kkI~
//v5kf:070527 (LNX)add UNDERLINE option for insert mode as default for X-console-mode//~v5kfI~
//v5g9:050708 (LNX)openwith support(add terminal sim nxterm,color-xterm,rxvt)//~v5g9I~
//v598:031021 reset vt100 option support                           //~v598I~
//v589:030819 integrate UKBDLNXC_-->UKBDL_                         //~v589I~
//v587:030816 (AIX)chk term-sim id by "ps -ef"                     //~v587I~
//v57X:030801 (AIX)defalt curses key setup for all X-term if not duplicated//~v57XI~
//v57N:030712 (LNX)defalt curses key setup for all X-term if not duplicated//~v57NI~
//v57M:030709 (LNX)option to skip set function string              //~v57MI~
//v57E:030419 (AIX)getsimid func for aix                           //~v57EI~
//v57B:030419 (LNX)no process chain when xe executed by shell      //~v57BI~
//v57A:030413 (LNX)TTY=pts/n under X(ptsn for kon,ttyn for console)//~v57AI~
//v57z:030406 (LNX)gnome-terminal support                          //~v57zI~
//v57w:030223 (LNX:BUG)xterm/kterm should determined by cmd name not by TERM env var.//~v57wI~
//v555:020421 (AIX)accept key for aixterm                          //~v555I~
//v527:020217 option of clearok if not splitted                    //~v527I~
//v514:011212 dbcs clear mode option by --cd                       //~v514I~
//v50S:010920 UNX:clear screen before draw is option               //~v50SI~
//v50z:010521 LINUX support:support getch/kbhit                    //~v50zI~
//v501:010305 X support:kterm/xterm generate 0x1b[A(hard codes in input.c)//~v501I~
//            but terminfo is 0x1bOA for up cursor key.            //~v501I~
//v39b:001113 LINUX support:move posix logic(common to linux and aix) to ukbdl from ukbdlnxc//~v39bI~
//v395:001105 LINUX support:switch echo,noraw<-->noecho,raw for sub-shell mode//~v395I~
//v384:001001 LINUX support(hearing of key assign from kbdinit)    //~v384I~
//v347:000925 LINUX support(insert cursor option;BLINK and/or REVERSE)//~v347I~
//v342:000924 LINUX support(mono color option)                     //~v342R~
//v324 000813:LINUX support                                        //~v324I~
//**************************************************************** //~v324I~
#ifdef ARM                                                         //~v6a0I~
    #include <termios.h>                                           //~v6a0I~
#endif                                                             //~v6a0I~
#ifdef UKBDL_GBL                                                   //~v50zI~
	int Gukbdl_flag;                                               //~v50zI~
#else                                                              //~v50zI~
	extern int Gukbdl_flag;                                        //~v50zI~
#endif	                                                           //~v50zI~
#define GUKBDL_METAMODE    0x01	//metamode                         //~v50zI~
#define GUKBDL_NOSETSTR    0x02	//bypass set console func key string//~v57MR~
#define GUKBDL_RCTLUSE     0x04	//use Control_R key                //~v5mvI~
#define GUKBDL_RCTLSTRSET  0x08	//string defined for RCTL key by ini file etc//~v5mvI~
//**************************************************************** //~v50zI~
void ukbdl_init(int Popt,unsigned char *Pkeyassign);               //~v384R~
//#define UKBDL_ALTPFKMASK 0x00000fff    //use altL as ALT func key//~v384R~
#define UKBDL_USEALTL    0x01000000    //use altL as ALT func key  //~v324I~
#define UKBDL_USEALTR    0x02000000    //use altR as ALT func key  //~v324R~
#define UKBDL_COMPOSE    0x04000000    //set katakana composer     //~v324R~
#define UKBDL_CURSES     0x08000000    //under curses;use curses keymapping also//~v324R~
#define UKBDL_MONO       0x10000000    //mono color                //~v347R~
#define UKBDL_BLINK      0x20000000    //blink when inser mode     //~v347I~
#define UKBDL_REVERSE    0x40000000    //reverse when inser mode   //~v347I~
#define UKBDL_CLEAR      0x80000000    //clear before scr draw     //~v50SI~
#define UKBDL_CLEARDBCS  0x00010000    //clear before scr draw     //~v514I~
#define UKBDL_CLEAR1     0x00020000    //clear if not splitted scr //~v527I~
#define UKBDL_7fBS       0x00040000  //force 0x7f to BS            //~v589I~
#define UKBDL_7fDEL      0x00080000  //force 0x7f to DEL           //~v589I~
#define UKBDL_7fCHAR     0x00100000  //force 0x7f to 0x7f          //~v589I~
#define UKBDL_TNTT       0x00200000  //force teraterm esc string   //~v589I~
#define UKBDL_TNLNX      0x00400000  //force not teraterm esc string//~v598I~
#define UKBDL_UNDERLINE  0x00800000  //underline for insertmode    //~v5kfR~
#define UKBDL_BOLD       0x00008000  //use A_BOLD on CONSOLE       //~v5nbR~
#define UKBDL_NOSCO      0x00004000  //no use terminal type:SCO esc string//~v6qhI~
#define UKBDL_Z2         0x00002000  //^[[Z is F2 by SCO,if not S+Tab//~v6qhR~
                                                                   //~v6qhI~
#define OPTSTR_NOSCO  "NOSCO"                                      //~vangI~//~v6qhM~
#define OPTSTR_Z2     "Z2"                                         //~v6qhI~
//**************************************************************** //~v324I~
void ukbdl_term(void);                                             //~v324I~
//**************************************************************** //~v395I~
void ukbdl_shellmode(int Pentrysw);                                //~v395I~
//**************************************************************** //~v39bI~
void ukbdl_setkbmode(int Prestoresw);                              //~v39bI~
//**************************************************************** //~v39bI~
void ukbdl_tcgetattr(int Pfd,struct termios *Pptios);              //~v39bI~
//**************************************************************** //~v39bI~
void ukbdl_tcsetattr(int Pfd,struct termios *Pptios);              //~v39bI~
//**************************************************************** //~v39bI~
void ukbdl_setgetchmode(int Pfd,int Pechosw,struct termios *Ppoldtios);//~v39bR~
//**************************************************************** //~v39bI~
int ukbdl_getch_init(void);                                        //~v39bI~
int ukbdl_getche_init(void);                                       //~v39bI~
int ukbdl_getch_term(void);                                        //~v39bI~
int ukbdl_getche_term(void);                                       //~v39bR~
//**************************************************************** //~v50zI~
int ukbdl_kbhit(void);                                             //~v50zI~
//**************************************************************** //~v39bI~
int ukbdl_getch(int Popt);                                         //~v39bI~
#define UKBDL_GETCH_ONCE  0x01                                     //~v39bI~
#define UKBDL_GETCH_CONT  0x00                                     //~v39bI~
//**************************************************************** //~v50zI~
int ukbdl_getche(int Popt);                                        //~v50zI~
#define UKBDL_GETCHE_ONCE  0x01                                    //~v50zI~
#define UKBDL_GETCHE_CONT  0x00                                    //~v50zI~
//**************************************************************** //~v501I~
int ukbdl_gettermid(void);                                         //~v501I~
#define    TERM_XTERM   1                                          //~v501M~
#define    TERM_KTERM   3   //and also xterm                       //~v501I~
#define    TERM_AIXTERM 5   //and also xterm                       //~v555I~
#define    TERM_DTTERM  9   //and also xterm                       //~v555I~
#define    TERM_TTYLCONS 16 //tty linux console                    //~v57NI~
#define    TERM_VT100    16 //aix teraterm                         //~v57XR~
#define    TERM_IDMASK   0x00ff                                    //~v57NI~
#define    TERM_SIMID    0xff00                                    //~v57wR~
#define    TERM_XTERMSIM 0x0100 //parent process is xterm          //~v57wI~
#define    TERM_KTERMSIM 0x0300                                    //~v57wR~
#define    TERM_GTERMSIM 0x0400 //gnome terminal                   //~v57zR~
#define    TERM_OTHERSIM 0x0800 //other x-terminal                 //~v57zR~
#define    TERM_KONSOLE  0x0900 //Kubuntu Konsole                  //~v5kkI~
#define    TERM_XFCE4TERM  0x0b00 //xfce4-terminal                 //+v6s2I~
#define    TERM_AIXTERMSIM 0x1000 //aixterm                        //~v57ER~
#define    TERM_DTTERMSIM  0x2000 //dtterm                         //~v57ER~
#define    TERM_TELNET     0x3000 //through telnet(also for teraterm)//~v587I~
#define    TERM_NXTERMSIM  0x4000 //nxterm                         //~v5g9I~
#define    TERM_COLORXSIM  0x5000 //color-xterm                    //~v5g9I~
#define    TERM_RXVTSIM    0x6000 //rxvt                           //~v5g9I~
#define    TERM_SIMCHKSW 0x800000 //initsw                         //~v57zR~
#define    TERM_UNDERPTS 0x400000 //term under X                   //~v57BR~
#define    TERM_UNDERKON 0x200000 //kon(on console)                //~v57AI~
#define    TERM_UNDERTN  0x100000 //Linux:throu telnet             //~v62iI~
                                                                   //~v57BI~
//#ifdef LNX                                                       //~v57ER~
	int ukbdl_gettermsim(void);                                    //~v57BM~
//#endif                                                           //~v57ER~
void ukbdl_editstring(char *Pstr,char *Poutstr);                   //~v57NR~
int ukbdl_gettermpgm(int Popt,char *Pcmd,char *Pout);              //~v5kkI~
int ukbdl_wcinit(int Popt,ULONG Pcodepage,UCHAR *Pcharset);        //~v5n8R~
