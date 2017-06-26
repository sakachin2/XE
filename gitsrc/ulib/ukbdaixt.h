//*CID://+v58bR~:                             update#=   57;       //~v58bR~
//**************************************************************** //~v40gI~
//ukbdaixt.h                                                       //~v57XR~
//**************************************************************** //~v40gI~
//v58b:030819 (AIX:BUG) user key overflow msg                      //~v58bI~
//v58a:030819 (AIX) --t option if TERM!=VT100 for esc str for key ins del etc//~v58aI~
//v584:030813 (AIX)key file support                                //~v584I~
//v57X:030801 (AIX)defalt curses key setup for all X-term if not duplicated//~v57XI~
//v55s:020528 (AIX)hex notation support for .Xdefaults(0x1b~~xxyyz fmt)//~v55sI~
//v555:020421 (AIX)accept key for aixterm                          //~v555I~
//v504:010307 AIX-X support:use terminfo string                    //~v503I~
//v503:010307 AIX support:print string                             //~v503I~
//v40g:001111 AIX support:kbd for aix+teraterm                     //~v40gI~
//**************************************************************** //~v40gI~
#define MAX_USERKEY 	99  //teraterm max user key definition     //~v40gM~
#define FUNCSTRID 0x7e                                             //~v40gM~
#define USERSTRLEN  5                                              //~v503I~
#define USERSTRLEN2 8       //1b~~xxyyz fmt(xx:scan,yy:char,z:shiftid)//~v55sR~
#define USERSTRLEN3 7       //linux:1b~xxyyz fmt(xx:scan,yy:char,z:shiftid)//~v584I~
#define TTSTRLINEID "TeraTermString:"                              //~v57XR~
#define TTSTRLINEID2 "Keyname="                                    //~v57XR~
#define TTERMID      "vt100"                                       //~v58aI~
//#ifdef FKT_MAX_SYM                                               //~v57XR~
//    #undef FKT_MAX_SYM                                           //~v57XR~
//#endif                                                           //~v57XR~
//#define FKT_MAX_SYM 4                                            //~v57XR~
//for ukbdlnxc.h compatible                                        //~v503I~
#define _FUNCKEYTBL _FKTAIX        //funckeytbl for aix            //~v503M~
#define FUNCKEYTBL FKTAIX        //funckeytbl for aix              //~v503M~
#define PFUNCKEYTBL PFKTAIX                                        //~v503M~
#define _CURSESKEYTBL _CKTAIX        //funckeytbl for aix          //~v503M~
#define CURSESKEYTBL CKTAIX        //funckeytbl for aix            //~v503M~
#define PCURSESKEYTBL PCKTAIX                                      //~v503M~
                                                                   //~v503I~
#ifdef GBL_UKBDAIXT                                                //~v504I~
	int Gkbdaixt_opt;  //under tterm                               //~v504I~
#else                                                              //~v504I~
extern 	int Gkbdaixt_opt;  //under tterm                           //~v504I~
#endif                                                             //~v504I~
#define GKBAIX_XXTERM   0x01  //xterm on x                         //~v504R~
#define GKBAIX_XAIXTERM 0x04  //aixterm on x                       //~v555I~
#define GKBAIX_TELNET   0x10  //telnet entry                       //~v584I~
#define GKBAIX_TTERM    0x20  //teraterm                           //~v584I~
//**************************************************************** //~v40gI~
typedef struct _FUNCKEYTBL{                                        //~v40gM~
                            int FKTkeycode; //linux keycode        //~v40gM~
                            char *FKTkeyname;                      //~v503R~
#ifdef FKT_MAX_SYM                                                 //~v57XM~
    #undef FKT_MAX_SYM                                             //~v57XM~
    #undef FKT_MAX_STR                                             //~v57XM~
#endif                                                             //~v57XM~
#define FKT_MAX_SYM 4                                              //~v57XM~
#define FKT_MAX_STR 8                                              //~v57XM~
                            unsigned short FKTfkassign[FKT_MAX_SYM];//for all modifier//~v40gM~
#define FKT_TTUSERKEY          1   //use tera-term Userxx assign ment//~v58bR~
#define FKT_TTORGASSIGNED   0xf0  //teraterm org key assigned      //+v58bR~
                            unsigned short FKTdoskey[FKT_MAX_SYM];//for all modifier//~v40gM~
//                          char *FKTttstring[FKT_MAX_SYM];//teraterm string//~v57XR~
                            char *FKTttstring[FKT_MAX_SYM][FKT_MAX_STR];//teraterm string//~v57XI~
                            char *FKTtistring[FKT_MAX_SYM];//terminfo string//~v504I~
                            int   FKTflag[FKT_MAX_SYM][FKT_MAX_STR];//for all modifier//~v57XI~
//#define FKT_TTREPKEY        2   //use native teraterm string     //~v584M~
#ifdef FKT_TTREPKEY                                                //~v58aI~
	#undef FKT_TTREPKEY                                            //~v58aI~
#endif                                                             //~v58aI~
#define FKT_TTREPKEY        4   //by parm file;same value as ukbdlnxc.h to avoid compile warning//~v584M~
#define FKT_TTORGKEY        9   //use native teraterm string       //~v584M~
#define FKT_AIXORGKEY      10   //use native teraterm string       //~v584M~
#define FKT_LINUX          11   //str for linux                    //~v584M~
                            char  FKTuserstring[FKT_MAX_SYM][8];   //~v503R~
                            int   FKTaixfunckeyno[FKT_MAX_SYM];    //~v584I~
                        } FUNCKEYTBL,*PFUNCKEYTBL;                 //~v40gM~
typedef struct _USERKEYTBL{                                        //~v40gM~
                        PFUNCKEYTBL UKTpfkt;                       //~v40gM~
                        int     UKTmodx;                           //~v40gM~
                    } USERKEYTBL,*PUSERKEYTBL;                     //~v40gM~
//**************************************************************** //~v40gI~
int ukbdaixt_setupuserkey(PFUNCKEYTBL **Pppfkt,int Popt);          //~v40gR~
//**************************************************************** //~v40gI~
//int ukbdaixt_printttkey(PFUNCKEYTBL Ppfkt,int Pmodx);            //~v584R~
//**************************************************************** //~v40gI~
//int ukbdaixt_chngttkey(char *Pkeyfnm);                           //~v58aR~
int ukbdaixt_chngttkey(int Popt,char *Pkeyfnm);                    //~v58aI~
//**************************************************************** //~v503I~
int ukbdaixt_gettbl(PFUNCKEYTBL **Pppfkt,int *Ppfktno,             //~v503I~
					char **Ppreadbuff,int **Ppreadlen);            //~v503I~
