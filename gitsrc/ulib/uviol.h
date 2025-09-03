//*CID://+vbDaR~:                             update#=   33;       //~vbDaR~
//******************************************************
// uviol.h                                                         //~v324I~
//******************************************************           //~v324I~
//vbDa:250703 (gxe)helpmsg was not controled by scr height.        //~vbDaI~
//v6Em:160807 (LNX) v6Ei for LNX(specify ligature on/off,combine on/of line by line(used for edit/filename  panel))//~v6EmI~
//v6D9:160610 (LNX)when combining char exists under combineing mode,//~v6D9I~
//  		  hdr line filename contains black space after each combining char if ligature off,after string if ligature on.//~v6D9I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v5nb:081003 (LNX)on CONSOLE, A_BOLD bit cause invalid char display. on CONSOLE init_color API works, so no BOLD required.//~v5nbI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5m7:080204 move internal function to header for xeacb.c         //~v5m7I~
//v5ij:060710 (LNX:BUG)box drawing char ineffective                //~vijxI~
//v55x:020603 (AIX)dtterm is color pair#=8                         //~v55xI~
//v510:011208 (UNX)use dbcstbl of xe for csr attr write            //~v510I~
//			   because 2nd byte chk is also required but not avail.//~v510I~
//v50K:010718 AIX support:add clearto ok to prepare to redraw full screen//~v50KI~
//            (avoid dbcs split by curses escape seq)              //~v50KI~
//v50u:010421 EUC japanese errmsg under kon                        //~v50uI~
//v39B:010114 LINUX support:kon status chk subrtn                  //~v39BI~
//v391:001015 LINUX support(fix MAX color to 8)                    //~v391I~
//v341:000924 LINUX support(mono color option)                     //~v341I~
//v324 000813:LINUX support                                        //~v324I~
//******************************************************           //~v022I~
#ifdef UVIOL_GBLDEF                                                //~v50uI~
    int Guviol_flag;                                               //~v50uI~
#else                                                              //~v50uI~
    extern int Guviol_flag;                                        //~v50uI~
#endif                                                             //~v50uI~
#define UVIOL_KON      0x80                                        //~v50uR~
#define UVIOL_NOBGCOL  0x40     //maxcolor=pairno(no bg color like as dtterm)//~v55xI~
#define UVIOL_KONCHKS  0x01     //konchk started,flag for uerrmsg request konchk//~v50uI~
#define UVIOL_KONCHKE  0x02     //konchk ended                     //~v50uI~
#define UVIOL_CHGCOLOR 0x04     //color value changable            //~v5nbI~
                                                                   //~v50uI~
#define NC_MAX_COLOR   8    //curses max color                     //~v391I~
                                                                   //~v5m7I~
#define ATTR2PAIR(attr) (uviol_cell2attr(attr))                    //~v5m7I~
#ifdef UVIOL_INTERNAL                                              //~v5m7I~
  #if !(defined(ARM) && defined(XXE))                              //~v6a0I~
  #define PAIR2ATTR(attr) (uviol_attr2cell(attr))                  //~v6D9I~
  #ifndef NOCURSES                                                 //~v6a0I~
	chtype uviol_cell2attr(USHORT Pcell);                          //~v5m7I~
  	chtype uviol_altcharset(chtype Pcht,char Pdbcssw); //string validate//~v5n8I~
	int  uviol_attr2cell(chtype Pcht);                             //~v6D9I~
  #endif //NOCURSES                                                //~v6a0I~
  #endif //ARMXXE                                                  //~v6a0I~
#endif                                                             //~v5m7I~
//******************************************************           //~v6EmI~
#ifdef LNX                                                         //~v6EmI~
int  uviol_repfg(int Pcht,int Pfg);                                //~v6EmR~
#endif                                                             //~v6EmI~
//******************************************************           //~v391I~
int uviol_init(int Popt);                                          //~v342R~
//******************************************************           //~v510I~
void uviol_init2(UCHAR *Pdbcstbl);                                 //~v510I~
//******************************************************           //~v324I~
int uviol_term(void);                                              //~v324I~
//******************************************************           //~v324I~
int uviol_clear(void);                                             //~v324I~
//******************************************************           //~v324I~
int uviol_clearok(int Popt);                                       //~v50KR~
//******************************************************           //~v50KR~
int uviol_refresh(void);                                           //~v324I~
//******************************************************           //~v324I~
int uviol_beep(void);                                              //~v324I~
//******************************************************           //~v39BI~
int uviol_konchk(void);                                            //~v39BI~
//******************************************************           //~v5n8I~
int uviol_konchk2(void);                                           //~v5n8I~
//******************************************************           //~vijxI~
#ifdef LNX                                                         //~v5ijR~
#ifndef XXE                                                        //~v5ijR~
void uviol_acssetup(int Psetsw,int Pentno,UCHAR *Pacstbl);         //~v5ijR~
int uviol_set_padattrsub(int Popt,int Pcolorno);                   //~v6D9R~
#else                                                              //+vbDaI~
int uviolxGetMaxHelpLines();                                       //~vbDaI~
#endif                                                             //~v5ijR~
#endif                                                             //~v5ijR~
