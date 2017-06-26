//*CID://+v6EqR~:                             update#=  405;       //+v6EqR~
//*************************************************************
//v6Eq:160812 lineopt should be cleared by USDFNCELL               //+v6EqI~
//v6Em:160807 (LNX) v6Ei for LNX(specify ligature on/off,combine on/of line by line(used for edit/filename  panel))//~v6EmI~
//v6D9:160610 (LNX)when combining char exists under combineing mode,//~v6D9I~
//  		  hdr line filename contains black space after each combining char if ligature off,after string if ligature on.//~v6D9I~
//v6Bh:160212 (LNX)compiler warning                                //~v6BhI~
//v6j0:121102 for xcifb; -DNOCURSES -DXSUB                         //~v6j0I~
//v6hc:120613 (FC12)avoid uninitialized variable warning by gcc 4.4.4 on FC12(copile optio -Ox is required also)//~v6hcI~
//v6h9:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(copile optio -Ox is required also)//~v6h9I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v690:100701 m64(LP64:: int:32, long,void*:64) support (__LP64_):chk pointer size at 1st.//~v690I~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v5nF:090418 (LNX:BUG:SUSE11)mvin_wchnstr read 2 cchar_t when requested 1 char//~v5nFI~
//v5ns:081106 (LNX:BUG)mvinchnstr read ucs str when write by cchar //~v5nsI~
//v5nj:081029 (LNX)set unprintable for also >=0x80 (Gpdbcstbl even if DBCS 1st)//~v5njI~
//v5ni:081027 (LNX:BUG)english mode acs is not displayed(cause may be A_ALTCHARSET on CONSOLE mode)//~v5niI~
//v5nb:081003 (LNX)on CONSOLE, A_BOLD bit cause invalid char display. on CONSOLE init_color API works, so no BOLD required.//~v5nbI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5m7:080204 move internal function to header for xeacb.c         //~v5m7I~
//v5m1:080126 (LNX:BUG)uerrmsg->konchk(from xcv) abend when stdin is redirected(ttyname errno=22:invalid arg)//~v5m1R~
//v5kf:070527 (LNX)add UNDERLINE option for insert mode as default for X-console-mode//~v5kfI~
//v5ke:070522 (LNX)No cursor visble if not blink set at Kubuntu(not gnome-terminal).//~v5keI~
//v5in:060728 line drawing char ini file support(avoid replace dbcs)//~v5inI~
//v5ij:060710 (LNX:BUG)box drawing char ineffective                //~v5ijI~
//v5h3:050814 (LNX)FC4;alternative of v5h2,use bkgd()              //~v5h3I~
//v5h2:050812 (LNX)FC4;if color pallette is 07(bg=0=black,fg=7=white) drawn by background color of gnome terminal setup//~v5h2I~
//v59c:030816 (UNX:BUG)of v588;dbcs chk failed                     //~v59cR~
//            uviol.c                                              //~v589I~
//v588:030816 (UNX)fg=white for ins mode cursor by rev if color terminal//~v588I~
//            USE A_REVERSE,previously HIGHLIGHT_FG/BG(A_REVERSE) is used only when monocolor//~v588I~
//v585:030816 (AIX)telnet by linux support(as curser draw by linux like v580)//~v585I~
//v581:030808 (LNX)under X DBCS cursor is maintaind automaticaly   //~v580I~
//v580:030806 (LNX)under X RVERSE bit is reset by cursor reverse;so use BOLD.//~v580I~
//            BLINK is no effect under X;ignore requested parm.    //~v580I~
//v57Q:030719 (LNX)console determination                           //~v57QR~
//v57B:030419 (LNX)no process chain when xe executed by shell      //~v57BI~
//v55x:020603 (AIX)dtterm is color pair#=8                         //~v55xI~
//v534:020315 (WIN/AIX)screen width parameter support              //~v534I~
//v517:011223 clear_ok is not always issued(only when full draw)   //~v517R~
//			  space should be always written by altchar to clear prev image.//~v510I~
//v510:011208 (UNX)use dbcstbl of xe for csr attr write            //~v510I~
//			   because 2nd byte chk is also required but not avail.//~v510I~
//v50Z:011202 (UNX)prev csr line is requested re-draw by xe;no need save prev csr stat//~v50ZI~
//v50S:010920 UNX:clear screen before draw is option               //~v50SI~
//v50M:010724 AIX:shell mode(if raw "sh" return immediately)       //~v50MI~
//v50L:010720 LINUX:try clearok(1) for alternative of ALT_CHAR|' ' under kon//~v50LR~
//v50K:010718 AIX support:add clearto ok to prepare to redraw full screen//~v50KR~
//            (avoid dbcs split by curses escape seq)              //~v62UR~
//v50z:010521 LINUX support:support getch/kbhit                    //~v50zI~
//v50v:010422 konchk performance up                                //~v50vI~
//v50u:010421 EUC japanese errmsg under kon                        //~v50uI~
//v502:010305 X support:kterm/xterm:space write ignored            //~v502I~
//v40u:010115 AIX support:acs_map(linux) not defined,another name exist.//~v40uR~
//v40t:010104 AIX support:dbcs attr may be same for 1st and 2nd byte.//~v40tI~
//v40s:001205 AIX support:insert mode curser by blink because cusor shape is defined on teraterm.ini//~v40sI~
//v40r:001205 AIX support:cursor and reverse and highlight;hilight by bold+revers(white in blue)//~v40rI~
//v40q:001130 AIX support:ALTCHAR set for DBCS cause err when dbcs display//~v40qI~
//v40p:001130 AIX support:chtype format different(char is last 2 byte)//~v40pI~
//v40j:001117 AIX support:Big endian(cell is char+attr)            //~v40jI~
//v40f:001109 AIX support:curses data structure diferent           //~v40fI~
//v407:001109 AIX support:no native SignalHandler definition       //~v407I~
//v401:001027 AIX support:ncurses.h should be curses.h             //~v39fI~
//v39W:010204 LINUX support:kon chk by ps cmd                      //~v39WI~
//v39E:010114 LINUX support:same dbcs cursol attr of insert mode   //~v39EI~
//v39B:010114 LINUX support:kon status chk subrtn                  //~v39AI~
//v39A:010114 LINUX support:keisen display                         //~v39yI~
//v39y:010113 LINUX support:Under kon,A_ALTCHARSET is better to space//~v39yI~
//            overwrite for SBCS.But,DBCS is not displayed when A_ALTCHARSET on.//~v39yI~
//v39r:010105 LINUX support:(BUG)ins mode curser reset by del/erase eof.//~v39rI~
//v39o:001209 LINUX support:mono color insert cursor               //~v39oI~
//            gray in reverse except on where highlight-reverse(black in reverse)//~v39oI~
//v39n:001202 LINUX support:space write under kon is caused by A_ALTCHARSET//~v39nI~
//v39m:001202 LINUX support:deny v39j;font is invalid              //~v39mI~
//v39j:001202 LINUX support:try A_ALTCHARSET off for >=0x80        //~v39jI~
//v39f:001124 LINUX support:(BUG) reverse required A_REVERSE under mono mode//~v39fI~
//v39d:001123 LINUX support:(BUG) scroll count err                 //~v39dI~
//v39c:001123 LINUX support:(BUG) uviol work should be get at init;//~v39cI~
//v399:001112 LINUX support:curses ok?(no effect of setattr)       //~v399I~
//v392:001021 LINUX support(BUG:color level3 -->rgb value 1000)    //~v392I~
//v391:001015 LINUX support(fix MAX color to 8)                    //~v391I~
//v382:001001 del trace                                            //~v382I~
//v354:000926 LINUX support(BUG:urr returned by uehl_setsh is to be freeed)//~v354I~
//v353:000926 LINUX support(BUG:clear initsw at term)              //~v353I~
//v347:000925 LINUX support(insert cursor option;BLINK and/or REVERSE)//~v347I~
//v342:000924 LINUX support(mono color option)                     //~v342I~
//v324 000813:LINUX support  
//     000923:alternative of cursor visible(half box)-->blink      //~v324I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <signal.h>

#define _XOPEN_SOURCE_EXTENDED		//ncurses define               //~v5n8R~
#include <ucurses.h>                                               //~v401R~
#include <term.h>                                                  //~v324I~
#ifdef LNX                                                         //~v39WI~
	#include <unistd.h>                                            //~v39WI~
#endif                                                             //~v39WI~
//*******************************************************
#include <ulib.h>
#include <ualloc.h>                                                //~v5n8I~
#include <uvio.h>
#include <uvio2.h>
#include <uerr.h>
                                                                   //~v50uI~
#define UVIOL_GBLDEF    //define extern var                        //~v50uI~
#define UVIOL_INTERNAL  //define uviol_cell2attr                   //~v5m7I~
#include <uviol.h>
#include <uviom.h>                                                 //~v5n8I~
                                                                   //~v50uI~
#include <ukbdl.h>                                                 //~v342I~
#include <ueh.h>                                                   //~v407I~
#include <uehl.h>
#include <udbcschk.h>                                              //~v40tI~
#include <utrace.h>                                                //~v324I~
#include <ufile.h>                                                 //~v39WI~
#include <ufile4.h>                                                //~v39WI~
#include <uproc.h>                                                 //~v39WI~
#ifdef AIX                                                         //~v588I~
	#include <ukbdaixt.h>                                          //~v588I~
#endif                                                             //~v588I~
#ifdef LNX                                                         //~v6a0I~
	#include <ukbdlnxc.h>                                          //~v6a0I~
#endif                                                             //~v6a0I~
//*******************************************************
//#define CSR_REDRAW		//csr reset not requred after csr move //~v50ZR~
                        //because csr line is drawed twice         //~v50ZI~
#define RANGE_CHKERR(row,col,len) \
      ((row<0||row>=Sscrheight)    \
    || (col<0||col>=Sscrwidth)     \
    || (row*Sscrwidth+col+len>Sscrsize))                           //~v324R~
//set to display non ascii char                                    //~v324I~
#ifdef LNX                                                         //~v40pI~
                                                                   //~v39yI~
//#define ALTCHARSET(chtype)                                       //~v39yR~
//    if (Skonsw)                                                  //~v39yR~
//    {                                                            //~v39yR~
//      if (!((chtype) & A_CHARTEXT)) chtype|=(' '|A_ALTCHARSET);  //~v39yR~
//      else                                                       //~v39yR~
//      if (((chtype) & A_CHARTEXT)==' ') chtype|=(' '|A_ALTCHARSET);//~v39yR~
//      else                                                       //~v39yR~
//      if (!((chtype) & 0xe0)) chtype|=A_ALTCHARSET;              //~v39yR~
//      else                                                       //~v39yR~
//      if ((chtype) & 0x80) chtype|=A_ALTCHARSET;                 //~v39yR~
//    }                                                            //~v39yR~
//    else                                                         //~v39yR~
//    */                                                           //~v39yR~
//      if (!((chtype) & A_CHARTEXT)) chtype|=0x20;                //~v39yR~
//      else                                                       //~v39yR~
//      if (!((chtype) & 0xe0)) chtype|=A_ALTCHARSET;              //~v39yR~
//      else                                                       //~v39yR~
//      if ((chtype) & 0x80) chtype|=A_ALTCHARSET;                 //~v39yR~
////    if (((chtype) & 0x80)|| !((chtype) & 0xe0)) chtype|=A_ALTCHARSET;//~v39yR~
                                                                   //~v39yI~
//	chtype uviol_altcharset(chtype Pcht); //string validate        //~v5inR~
//	chtype uviol_altcharset(chtype Pcht,char Pdbcssw); //string validate//~v5n8R~
                                                                   //~v39yI~
	#define ALTCHARSET(chtype)       \
/*  	chtype=uviol_altcharset(chtype) */ \
    	chtype=uviol_altcharset(chtype,0)                          //~v5inI~
	#define ALTCHARSET_S(chtype)	/*string type*/  \
/*    	chtype=uviol_altcharset(chtype) */ \
     	chtype=uviol_altcharset(chtype,0)                          //~v5inR~
	#define ALTCHARSET2(chtype,dbcssw)       \
    	chtype=uviol_altcharset(chtype,dbcssw)                     //~v5inI~
	#define ALTCHARSET2_S(chtype,dbcssw)	/*string type*/  \
     	chtype=uviol_altcharset(chtype,dbcssw)                     //~v5inR~
#else                                                              //~v40qR~
	#define ALTCHARSET(chtype)       \
      	if (!((chtype) & A_CHARTEXT)) chtype|=0x20;                //~v40qR~
	#define ALTCHARSET_S(chtype)       /* string*/   \
      	if (!((chtype) & A_CHARTEXT)) chtype|=0x20;                //~v39yI~
#endif                                                             //~v40qR~
//*******************************************************
#ifndef NOCURSES                                                   //~v6j0I~
	static int Skbdopt;		//option to uviol_init                 //~v50SI~
	static int Sinitsw=0;		//ncurses initsw                   //~v55xR~
	static int Skonsw=0;	//under kon                            //~v39nI~
	static int Stermid; 	//under kon                            //~v502I~
#ifdef LNX                                                         //~v57QI~
	static int Stermnameid=0;                                      //~v57QI~
	static int SunderX=0;                                          //~v580I~
	static int Sundergt=0; 	//gnome-terminal has no cursor color option//~v588I~
  #ifndef CURSESW                                                  //~v5n8R~
	static chtype  *Spspaceline;                                   //~v5n8R~
  #endif                                                           //~v5n8R~
#endif                                                             //~v57QI~
	static void *Spurr;		//uehl_setsh return eh registration record//~v354I~
	static int Sinsertmode=0;  //insert mode attr                  //~v55xR~
                                                                   //~v324I~
    static  int         Srgbunit=0;                                //~v55xR~
    static  int         Sattrcount=1;   //use color attr only
    static  int         Senglishsw;     //english mode sw
    static  int         Sscrsize;       //screen size(row*col)
    static  int         Sscrwidth=0;      //scr line size          //~v55xR~
    static  int         Sscrheight=0;     //scr line size          //~v55xR~
    static  int         Smaxcolorpair;    //color pair
    static  int         Smaxcolor=0;     //color number supported  //~v55xR~
    static  int         Sattrfg=0,Sattrbg=0; //color attr mask     //~v55xR~
    static  chtype     *Spwkchtype;      //ch type work
    static  UCHAR      *Spwkstr;         //string  work            //~v324I~
    static  UCHAR      *Sdbcstbl;        //of xe                   //~v510I~
                                                                   //~v50ZI~
#ifndef CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
                                                                   //~v50ZI~
    static  int         Svisibleblink=0;   //0:no blink,1:blink    //~v55xR~
    static  int         Svisible_oldrow=-1,Svisible_oldcol=-1;   //pos set blink//~v324I~
    static  int         Svisible_oldrev=0;  //reverse before ins mode set on//~v39fI~
//#ifdef AIX                                                       //~v510R~
//    static  int         Svisible_oldrev2=0; //for dbcs 2nd byte  //~v510R~
//#endif                                                           //~v510R~
                                                                   //~v50ZI~
#endif                                                             //~v50ZI~
    static UCHAR Scmap_dos2linux[16];	//colorno map dos to linux //~v342I~
                                                                   //~v342I~
    static short Sorgcolor_saver[16];	//original color content to restore at term//~v342I~
    static short Sorgcolor_saveg[16];	//original color content to restore at term//~v342I~
    static short Sorgcolor_saveb[16];	//original color content to restore at term//~v342I~
    static int   Sorgcolor_saved=0;	//original color content to restore at term//~v55xR~
    static int   Sorgcolor_changed=0; //original color content changed at once//~v55xR~
#ifdef AIX                                                         //~v55xI~
    static int Snobgcolorsw=0;                                     //~v55xI~
#endif                                                             //~v55xI~

static VIOMODEINFO SvioModeInfo;    //save current mode
    static chtype   Sacsmap[256]; //altcharset definition          //~v39AR~
static int Sheightparm=0,Swidthparm=0;	//user specification       //~v534R~
//*******************************************************
int uviol_colorinit(int Pmaxcolor,int Pmaxpair);                   //~v324I~
void uviol_cleanup(void);
void uviol_termexit(int Psigid);
//int uviol_mvaddchnstr(int Prow,int Pcol,chtype *Ppcht,int Plen);   //~v324I~//~v6EmR~
int uviol_mvaddchnstr(int Plineopt,int Prow,int Pcol,chtype *Ppcht,int Plen);//~v6EmI~
//int uviol_moveafter(int Prow,int Pcol,int Plen);                 //~v399R~
int uviol_attrupdate(int Prow,int Pcol,int Pattr,int Ponsw);       //~v324I~
#endif //!NOCURSES                                                 //~v6j0I~
#ifndef NOCURSES                                                   //~v6j0R~
//#define ATTR2PAIR(attr)                                          //~v324R~
//      COLOR_PAIR(((attr&Sattrbg)>>12)*Smaxcolor+((attr&Sattrfg)>>8))//~v324R~
//#define ATTR2PAIR(attr) (uviol_cell2attr(attr))                  //~v5m7R~
//*******************************************************          //~v324I~
//*uvio_cell2attr                                                  //~v324I~
//*cell attr change to color-pair+attr                             //~v324I~
//*parm cell:char(8:lower byte)+                                   //~v40qI~
//           bg-highlight(1)+bg-colorno(3)+fg-highlight(1)+fg-colorno(3)//~v39fR~
//*******************************************************          //~v324I~
chtype uviol_cell2attr(USHORT Pcell)                               //~v324I~
{                                                                  //~v324I~
    chtype cht,bg,fg;                                              //~v39fR~
//*********************************                                //~v324I~
//  cht=COLOR_PAIR(((Pcell & Sattrbg)>>12)*Smaxcolor+((Pcell & Sattrfg)>>8));//~v39fR~
//  bg=((Pcell>>8) & Sattrbg);	//2nd byte is AH                   //~v40qI~//~v6BhR~
    bg=(chtype)((Pcell>>8) & Sattrbg);	//2nd byte is AH           //~v6BhR~
//  fg=((Pcell>>8) & Sattrfg);                                     //~v40qI~//~v6BhR~
    fg=(chtype)((Pcell>>8) & Sattrfg);                             //~v6BhI~
//  if (Smaxcolor==2 && !fg)	//mono color and fg=black          //~v40pR~
//  	cht=COLOR_PAIR(bg>>8)|A_REVERSE;	//no BOLD(insmode rev id)//~v40pR~
    if (Smaxcolor==2)	//mono color and fg=black                  //~v40pI~
    {                                                              //~v40pI~
#ifdef LNX                                                         //~v40rI~
        if (Pcell & (HIGHLIGHT_BG<<8))   //reverse req             //~v40pR~
			cht=A_REVERSE;	//no BOLD(insmode rev id)              //~v40pI~
        else                                                       //~v40pI~
        	cht=0;                                                 //~v40pI~
#else	//AIX                                                      //~v40rI~
        if (Pcell & (HIGHLIGHT_BG<<8))   //reverse req             //~v40rI~
    		if (Pcell & (HIGHLIGHT_FG<<8)) //highlight and reverse //~v40rI~
        		cht=A_BOLD;                     //blue in white    //~v40rI~
            else                                                   //~v40rI~
				cht=A_REVERSE;	//reverse only                     //~v40rI~
        else                                                       //~v40rI~
    		if (Pcell & (HIGHLIGHT_FG<<8)) //highlight only        //~v40rI~
				cht=A_REVERSE+A_BOLD;	//white in blue            //~v40rI~
            else                                                   //~v40rI~
        		cht=0;                                             //~v40rI~
#endif   //AIX                                                     //~v40rI~
    }                                                              //~v40pI~
    else                                                           //~v39fI~
    {                                                              //~v55xI~
//  cht=COLOR_PAIR((bg>>12)*Smaxcolor+(fg>>8));                    //~v40pR~
#ifdef AIX                                                         //~v55xI~
      if (Snobgcolorsw)  //no bg color support(maxcolor==maxpair)  //~v55xI~
      {                                                            //~v55xI~
        if (fg)                                                    //~v55xI~
			cht=COLOR_PAIR(fg);                                    //~v55xI~
        else                                                       //~v55xI~
            if (bg)                                                //~v55xI~
			    cht=(COLOR_PAIR(bg>>4)| A_REVERSE);	//reverse only //~v55xR~
            else                                                   //~v55xI~
                cht=0;                                             //~v55xI~
      }                                                            //~v55xI~
      else                                                         //~v55xI~
#endif                                                             //~v55xI~
//		cht=COLOR_PAIR((bg>>4)*Smaxcolor+fg);                      //~v40pR~//~v6BhR~
  		cht=(chtype)COLOR_PAIR(((int)bg>>4)*Smaxcolor+(int)fg);    //~v6BhR~
//UTRACEP("colorpair bg=%02x,fg=%02x chr=%04x\n",bg,fg,cht);         //~v62UR~//~v6j0R~
    }                                                              //~v55xI~
#ifdef LNX                                                         //~v40rI~
//  if (Pcell & FG_HILIGHT)                                        //~v40pR~
    if (Pcell & (HIGHLIGHT_FG<<8))                                 //~v40pR~
    {                                                              //~v5n8I~
  	  if (Guviol_flag & UVIOL_CHGCOLOR)	//on CONSOLE               //~v5n8R~
      {                                                            //~v5n8I~
       if (Skbdopt & UKBDL_BOLD)  //reset NO BOLD use              //~v5n8R~
      	cht|=A_BOLD;                                               //~v324I~
      }                                                            //~v5n8I~
      else                                                         //~v5n8I~
      {                                                            //~v5n8I~
       if (!(Skbdopt & UKBDL_BOLD))  //no reset BOLD use           //~v5n8R~
      	cht|=A_BOLD;                                               //~v5n8I~
      }                                                            //~v5n8I~
    }                                                              //~v5n8I~
#endif		//LNX                                                  //~v40rI~
    return cht;                                                    //~v324I~
}//uviol_cell2att                                                  //~v324I~
//#define PAIR2ATTR(cht)                                           //~v324R~
//      ((PAIR_NUMBER(cht)/Smaxcolor<<4)|(PAIR_NUMBER(cht)%Smaxcolor))//~v324R~
//#define PAIR2ATTR(attr) (uviol_attr2cell(attr))                    //~v324I~//~v6D9R~
//*******************************************************          //~v324I~
//*uvio_attr2cell                                                  //~v324I~
//*chtype change to cell attr                                      //~v324I~
//*parm:chtype                                                     //~v324I~
//*******************************************************          //~v324I~
int  uviol_attr2cell(chtype Pcht)                                  //~v324R~
{                                                                  //~v324I~
    int    color;                                                  //~v324R~
//*********************************                                //~v324I~
//  color=PAIR_NUMBER(Pcht);                                       //~v40pR~
//  if (Pcht & A_REVERSE                                           //~v40pR~
//  &&  Smaxcolor==2                                               //~v40pR~
//  &&  !(Pcht & A_BOLD))	//bold is for insmode                  //~v40pR~
//	 	color=((color%Smaxcolor)<<4);   //move fg to bg pos        //~v40pI~
	if (Smaxcolor==2)                                              //~v40pI~
    {                                                              //~v40pI~
#ifdef LNX                                                         //~v40rI~
        color=0;                                                   //~v39oI~
		if (Pcht & A_BOLD)                                         //~v39oR~
        	color=HIGHLIGHT_FG;                                    //~v39oR~
		if (Pcht & A_REVERSE)                                      //~v39oR~
	    	color=HIGHLIGHT_BG;                                    //~v39oR~
#else                                                              //~v40rI~
		if (Pcht & A_BOLD)	//bold is for highlighte               //~v40rI~
			if (Pcht & A_REVERSE)	//both on is normal highlight  //~v40rI~
        		color=HIGHLIGHT_FG;                                //~v40rI~
        	else           //bold only	is reverse of highlight    //~v40rI~
        		color=HIGHLIGHT_FG+HIGHLIGHT_BG;                   //~v40rI~
        else                                                       //~v40rI~
			if (Pcht & A_REVERSE)                                  //~v40rI~
	    		color=HIGHLIGHT_BG;   //id by bg highlight         //~v40rI~
        	else                                                   //~v40rI~
        		color=0;                                           //~v40rI~
#endif                                                             //~v40rI~
    }                                                              //~v40pI~
    else                                                           //~v39fI~
    {                                                              //~v40pI~
#ifdef AIX                                                         //~v55xI~
    if (Snobgcolorsw)  //no bg color support(maxcolor==maxpair)    //~v55xI~
    {                                                              //~v55xI~
        color=PAIR_NUMBER(Pcht);                                   //~v55xR~
		if (Pcht & A_REVERSE)                                      //~v55xR~
        	color<<=4;                                             //~v55xI~
    }                                                              //~v55xI~
    else                                                           //~v55xI~
#endif                                                             //~v55xI~
    {                                                              //~v55xI~
    color=PAIR_NUMBER(Pcht);                                       //~v40pI~
    color=((color/Smaxcolor)<<4)+color%Smaxcolor;                  //~v324R~
	if (Pcht & A_BOLD)                                             //~v324R~
//      color|=FG_HILIGHT;                                         //~v40pR~
	    color|=HIGHLIGHT_FG;                                          //~v40pR~
    }                                                              //~v55xI~
    }                                                              //~v39fM~
    return color;                                                  //~v324I~
}//uviol_attr2cell                                                 //~v324R~
#ifdef LNX                                                         //~v6EmI~
//*******************************************************          //~v6EmI~
//*uvio_repfg                                                      //~v6EmI~
//*replace fg of attr                                              //~v6EmI~
//*parm Pcht(color+text)                                           //~v6EmI~
//*return attr shifted to right                                    //~v6EmR~
//*******************************************************          //~v6EmI~
int  uviol_repfg(int Pcht,int Pfg)                                 //~v6EmR~
{                                                                  //~v6EmI~
    int attrold,attrnew,bgfg;                                      //~v6EmI~
//*********************************                                //~v6EmI~
    attrold=(int)((ULONG)Pcht & A_COLOR); //original attr          //~v6EmR~
    UTRACEP("%s:Pcht=%08x,colorold=%04x,Pfg=%02x\n",UTT,Pcht,attrold,Pfg);//~v6EmR~
	bgfg=uviol_attr2cell((chtype)attrold);                         //~v6EmI~
    UTRACEP("%s:bgfg=%04x\n",UTT,bgfg);                            //~v6EmI~
    bgfg=(bgfg & 0xf0)|Pfg;                                        //~v6EmI~
    attrnew=(int)uviol_cell2attr((USHORT)(bgfg<<8));               //~v6EmR~
    UTRACEP("%s:new attr=%08x\n",UTT,attrnew);                     //~v6EmI~
    attrnew>>=8;                                                   //~v6EmI~
    UTRACEP("%s:return attr=%08x\n",UTT,attrnew);                  //~v6EmR~
    return attrnew;                                                //~v6EmI~
}//uviol_attr2cell                                                 //~v6EmI~
#endif                                                             //~v6EmI~
#ifdef LNX                                                         //~v39yI~
//*******************************************************          //~v39yI~
//*uvio_altcharset                                                 //~v39yI~
//*validate chartype                                               //~v39yI~
//*parm:chtype                                                     //~v39yI~
//*******************************************************          //~v39yI~
//chtype uviol_altcharset(chtype Pcht)                             //~v5inR~
chtype uviol_altcharset(chtype Pcht,char Pdbcssw)                  //~v5inI~
{                                                                  //~v39yI~
    char ch;                                                       //~v39yI~
//*********************************                                //~v39yI~
    ch=Pcht & A_CHARTEXT;                                          //~v39yI~
#ifdef UTF8UCS2                                                    //~v640R~
    if (!ch && Pdbcssw) //0x00 is part of ucs                      //~v640R~
        return Pcht;                                               //~v640R~
#endif                                                             //~v640R~
//  if (Skonsw)                                                    //~v502R~
                                                                   //~v57QI~
//  if (Skonsw||(Stermid & TERM_XTERM)) //kon or kterm/xterm       //~v57QR~
    if (Skonsw||(Stermnameid!=TERM_TTYLCONS))   //kon or not console//~v57QI~
    {                                                              //~v39yI~
//    	if (!ch) Pcht|=(' '|A_ALTCHARSET);                         //~v50LR~
//    	if (!ch) Pcht|=' ';                                        //~v50SR~
      	if (!ch||ch==' ')                                          //~v50SI~
//          if (Skbdopt & UKBDL_CLEAR)  //clear at redraw          //~v517R~
//  			Pcht|=' ';                                         //~v517R~
//          else                                                   //~v517R~
#ifdef LNXLC2       //libc2 TurboLinux                             //~v57BI~
//  			Pcht|=' ';                                         //~v5h2R~
//  			Pcht|=(' '|A_DIM);//DIM is not use for LNX,use to draw black bg for space char,ALTCHARSET is not printed//~v5h3R~
    			Pcht|=' ';                                         //~v5h3I~
#else                                                              //~v57BI~
				Pcht|=(' '|A_ALTCHARSET);                          //~v50SI~
#endif                                                             //~v57BI~
      	else                                                       //~v39yR~
//      if (Sacsmap[(int)ch])                                      //~v5inR~
        if (!Pdbcssw && Sacsmap[(int)ch])                          //~v5inI~
        	Pcht=Sacsmap[(int)ch]|(Pcht & A_ATTRIBUTES);//acs defined//~v5ijR~
      	else                                                       //~v5ijI~
#ifndef CURSESW                                                    //~v5n8R~
#ifdef BBB                                                         //~v5n8I~
      	if (ch<=' ') Pcht|=A_ALTCHARSET;    	                   //~v39yR~
#else                                                              //~v5n8I~
      	if (ch<=' ') Pcht='.';  //for safety                       //~v5n8I~
#endif                                                             //~v5n8I~
#else                                                              //~v5n8I~
			;	//leave it,replaced by "." later if unprintable    //~v5n8R~
#endif                                                             //~v5n8I~
//    	else                                                       //~v39yR~
//    	if (!ISEUC(ch)) Pcht|=A_ALTCHARSET;                        //~v39yR~
    }                                                              //~v39yI~
    else                                                           //~v39yI~
      	if (!ch) Pcht|=' ';                                        //~v39yR~
        else                                                       //~v39yI~
#define TEST2  //no need to use acs ;eng mode console display grph by direct code//~v5niR~
#ifdef TEST2                                                       //~v5niR~
	#ifndef CURSESW                                                //~v5niR~
        if (Sacsmap[(int)ch]) Pcht|=A_ALTCHARSET;	//acs defined  //~v39AR~
    #else                                                          //~v5niI~
        if (Sacsmap[(int)ch]) 	//no use of A_ALTCHARSET           //~v5niR~
        {                                                          //~v5niI~
            if (ch<128)           //not cp470 graphic char         //~v5niI~
        		Pcht=Sacsmap[(int)ch]|(Pcht & A_ATTRIBUTES);//acs defined//~v5niI~
        }                                                          //~v5niI~
    #endif                                                         //~v5niI~
#else                                                              //~v5ijI~
//      if (Sacsmap[(int)ch])                                      //~v5inR~
        if (!Pdbcssw && Sacsmap[(int)ch])                          //~v5inI~
        	Pcht=Sacsmap[(int)ch]|(Pcht & A_ATTRIBUTES);//acs defined//~v5ijI~
#endif                                                             //~v5ijI~
        else                                                       //~v57QR~
#ifndef CURSESW                                                    //~v5n8R~
#ifdef BBB                                                         //~v5n8I~
       	if (ch<0x20) Pcht|=A_ALTCHARSET;		//ctr char         //~v57QR~
#else                                                              //~v5n8I~
       	if (ch<0x20) Pcht='.';		//ctr char,for safety          //~v5n8I~
#endif                                                             //~v5n8I~
#else                                                              //~v5n8I~
			;	//leave it,replaced by "." later if unprintable    //~v5n8R~
#endif                                                             //~v5n8I~
    return Pcht;                                                   //~v39yI~
}//uviol_altcharset(chtype Pcht)                                   //~v39yI~
#endif                                                             //~v39yI~
//*******************************************************          //~v534R~
//*uvio_initparm                                                   //~v534R~
//*******************************************************          //~v534R~
void uvio_initparm(int *Pscrparm)                                  //~v534R~
{                                                                  //~v534R~
	if (Pscrparm)                                                  //~v534R~
    {                                                              //~v534R~
    	Sheightparm=Pscrparm[0];                                   //~v534R~
    	Swidthparm=Pscrparm[1];                                    //~v534R~
    }                                                              //~v534R~
    return;                                                        //~v534R~
}//uvio_initparm                                                   //~v534R~
//*******************************************************
//*VioGetMode
//*rc=1:mean redirected(Win)
//*******************************************************
UINT uviogetmode(PVIOMODEINFO PvioModeInfo)
{
    int ii;                                                        //~v324R~
    int color;
//*********************************
    if (!Sinitsw)                                                  //~v342I~
        return 4;                                                  //~v342I~
    Senglishsw=1;               //englsh mode
    memset(PvioModeInfo,0,sizeof(VIOMODEINFO));
    PvioModeInfo->cb=sizeof(VIOMODEINFO);
//text mode
    PvioModeInfo->fbType=(UCHAR)(0*VGMT_GRAPHICS);
//  color;
    color=Smaxcolor;         //ncuesus ext variable
    for (ii=0;;ii++)
    {
        color=color>>1;
        if (!color)
           break;
    }
    PvioModeInfo->color=(UCHAR)ii;  //16=2**4
//  Sattrbg=(Smaxcolor-1)<<12;      //0x7000 for maxcolr=8         //~v40qI~
//  Sattrfg=(Smaxcolor-1)<<8;       //0x0700                       //~v40qI~
    Sattrbg=0x70;                   //0x7000 for maxcolr=8         //~v40qR~
    Sattrfg=0x07;                   //0x0700                       //~v40qR~
//colomn
//  PvioModeInfo->col=Sscrwidth;       //ncuesus ext variable      //~v6BhR~
    PvioModeInfo->col=(USHORT)Sscrwidth;       //ncuesus ext variable//~v6BhI~
//row
//  PvioModeInfo->row=Sscrheight;       //ncuesus ext variable     //~v6BhR~
    PvioModeInfo->row=(USHORT)Sscrheight;       //ncuesus ext variable//~v6BhI~
//fmt_ID                //temp use
    PvioModeInfo->fmt_ID=(UCHAR)3;
//atrribute byte count
    PvioModeInfo->attrib=(UCHAR)Sattrcount;
//  Spwkchtype=malloc((Sscrsize+1)*sizeof(chtype)); //read chtype work//~v39cR~
//  Spwkstr=malloc(Sscrsize+1); //read string work                 //~v39cR~
    SvioModeInfo=*PvioModeInfo; //save current
   	uviom_init(0/*opt*/,0/*Shconout*/,Sscrwidth,Sscrsize,0/*windows toplineoffs*/);	//pass to uvio2//~v5n8R~
    return 0;
}//uviogetmode
//*********************************************************************
//* uviol_init                                                     //~v324R~
//*   color,curses keyboard init                                   //~v324I~
//*********************************************************************
int uviol_init(int Popt)                                           //~v342R~
{
    chtype cht;                                                    //~v39yI~
    int ii,ch;                                                     //~v57QR~
#ifdef LNX                                                         //~v5n8R~
    #ifndef CURSESW                                                //~v5n8R~
	    chtype *pcht;                                              //~v5n8R~
    #endif                                                         //~v5n8R~
#endif                                                             //~v5n8R~
//*******************************
    if (Sinitsw)                                                   //~v324R~
        return 0;                                                  //~v324R~
    Skbdopt=Popt;                                                  //~v50SI~
    Sinitsw=1;
	Spurr=uehl_setsh((void*)uviol_termexit);//uehl_setsh return eh registration record//~v354I~
#ifdef AIX                                                         //~v50MR~
    ukbdl_shellmode(-1);    //save shell mode                      //~v50MR~
#else                                                              //~v5inI~
    ukbdl_shellmode(-1);    //save shell mode  62U@                //~v5inI~//~v62UR~
#endif                                                             //~v50MR~
    initscr();
    keypad(stdscr,FALSE); //for getch();NO ketboard mapping by terminfo//~v324R~
//  keypad(stdscr,TRUE);  //for getch();curses Code by ketboard mapping of terminfo//~v324R~
//  cbreak();             //ICANNON:off,ICRNL:off,ISIG:on          //~v324R~
    raw();               //ICANNON:off,ISIG:off,COOKED_INPUT:off   //~v324I~
    nonl();                 //no NL->CR/NL on output               //~v324M~
    noecho();               //dont echo input
    meta(0,TRUE);          //dont echo input                       //~v324R~
	Gukbdl_flag|=GUKBDL_METAMODE;	//metamode                     //~v50zI~
    if (Popt & UKBDL_BLINK)                                        //~v347I~
//  	Sinsertmode|=A_BLINK;                                      //~v347R~//~v6BhR~
    	Sinsertmode|=(int)A_BLINK;                                 //~v6BhI~
    if (!(Popt & UKBDL_MONO) && has_colors())                      //~v342R~
    {
        start_color();
        Smaxcolorpair=COLOR_PAIRS;            //ncuesus ext variable//~v324R~
        Smaxcolor=COLORS;            //ncuesus ext variable        //~v324R~
        if (Smaxcolor>NC_MAX_COLOR)                                //~v391I~
        	Smaxcolor=NC_MAX_COLOR;                                //~v391I~
	    uviol_colorinit(Smaxcolor,Smaxcolorpair);                  //~v324I~
    }
    else
    {                                                              //~v324I~
        Smaxcolorpair=2;                                           //~v324R~
        Smaxcolor=2;                                               //~v324R~
    }                                                              //~v324I~
    Sscrwidth=COLS;
    Sscrheight=LINES;
//#ifdef AIX                                                       //~v534R~
    if (Sheightparm)                                               //~v534R~
    {                                                              //~v534R~
        if (Sheightparm>Sscrheight)                                //~v534R~
        {                                                          //~v534R~
			uviol_cleanup();                                       //~v534I~
            printf("Screen height parm(%d)>screen buff size(%d)\n",//~v534R~
                    Sheightparm,Sscrheight);                       //~v534R~
            return 2;                                              //~v534R~
        }                                                          //~v534R~
        Sscrheight=Sheightparm;                                    //~v534R~
    }                                                              //~v534R~
    if (Swidthparm)                                                //~v534R~
    {                                                              //~v534R~
        if (Swidthparm>Sscrwidth)                                  //~v534R~
        {                                                          //~v534R~
			uviol_cleanup();                                       //~v534I~
            printf("Screen width parm(%d)>screen buff size(%d)\n", //~v534R~
                    Swidthparm,Sscrwidth);                         //~v534R~
            return 2;                                              //~v534R~
        }                                                          //~v534R~
        Sscrwidth=Swidthparm;                                      //~v534R~
    }                                                              //~v534R~
//#endif                                                           //~v534R~
    Skonsw=uviol_konchk();                                         //~v39BI~
    Stermid=ukbdl_gettermid();                                     //~v502I~
#ifdef LNX                                                         //~v57QI~
  	Stermnameid=Stermid & TERM_IDMASK;                             //~v57QI~
//  SunderX=(Stermid & TERM_TTYLCONS)==0; //under X;sw for A_REVERSE and cursor reverse//~v588R~
    SunderX=(Stermnameid!=TERM_TTYLCONS); //under X;sw for A_REVERSE and cursor reverse//~v588I~
    Sundergt=((Stermid & TERM_SIMID)==TERM_GTERMSIM); //under X;sw for A_REVERSE and cursor reverse//~v588R~
  	if ((Stermid & TERM_SIMID)!=TERM_XTERMSIM)	//except xterm sim //~v5n8I~
    {                                                              //~v5n8I~
        if (Stermid & TERM_SIMID) 	//other sim under X            //~v5n8R~
  			Guviol_flag |= UVIOL_KON;   //for uerrmsgedit          //~v5n8R~
        else                                                       //~v5n8I~
  	    if (Stermid & TERM_UNDERKON) 	//under kon                //~v5n8R~
  			Guviol_flag |= UVIOL_KON;                              //~v5n8R~
    }                                                              //~v5n8I~
#endif                                                             //~v57QI~
    Sscrsize=Sscrwidth*Sscrheight;
//  Spwkchtype=malloc((Sscrsize+1)*sizeof(chtype)); //read chtype work//~v39cI~//~v6BhR~
    Spwkchtype=malloc((size_t)(Sscrsize+1)*sizeof(chtype)); //read chtype work//~v6BhI~
//  Spwkstr=malloc(Sscrsize+1); //read string work                 //~v39cI~//~v6BhR~
    Spwkstr=malloc((size_t)Sscrsize+1); //read string work         //~v6BhI~
#ifdef LNX                                                         //~v5kfI~
  #ifndef CURSESW                                                  //~v5n8R~
	Spspaceline=(chtype *)malloc(Sscrwidth*sizeof(chtype));        //~v5n8R~
    for (pcht=Spspaceline,ii=0;ii<Sscrwidth;ii++)                  //~v5n8R~
    	*pcht++=0x20;                                              //~v5n8R~
  #endif                                                           //~v5n8R~
    if (Popt & UKBDL_UNDERLINE                                     //~v5kfI~
    &&  Popt & UKBDL_REVERSE)	//no ins parm                      //~v5kfI~
    {                                                              //~v5kfI~
    	if (SunderX)                                               //~v5kfI~
			Popt&=~UKBDL_REVERSE;	//default is underline         //~v5kfI~
        else                                                       //~v5kfI~
			Popt&=~UKBDL_UNDERLINE;	//default is reverse           //~v5kfI~
    }                                                              //~v5kfI~
    if (Popt & UKBDL_UNDERLINE)                                    //~v5kfI~
//		Sinsertmode|=A_UNDERLINE;                                  //~v5kfI~//~v6BhR~
  		Sinsertmode|=(int)A_UNDERLINE;                             //~v6BhI~
    else                                                           //~v5kfI~
#endif                                                             //~v5kfI~
    if (Popt & UKBDL_REVERSE)                                      //~v39fM~
    {                                                              //~v39fM~
//  	Sinsertmode|=A_REVERSE;	//BOLD is id of rev by insmode     //~v39fM~//~v6BhR~
    	Sinsertmode|=(int)A_REVERSE;	//BOLD is id of rev by insmode//~v6BhI~
        if (Smaxcolor==2)                                          //~v39fM~
//      	Sinsertmode|=A_BOLD;	//id of monoclor insert pos    //~v39fM~//~v6BhR~
        	Sinsertmode|=(int)A_BOLD;	//id of monoclor insert pos//~v6BhI~
    }                                                              //~v39fM~
//printw("col=%d,row=%d\n",COLS,LINES);                            //~v324R~
//printw("color=%d,pair=%d\n",COLORS,COLOR_PAIRS);                 //~v324R~
//map of altcharset defined                                        //~v39AR~
#ifdef LNX                                                         //~v40uI~
UTRACED("system acsmap",acs_map,128*4);                            //~v5n8R~
    for (ii=0;ii<128;ii++)                                         //~v39AR~
    {                                                              //~v39AR~
        cht=acs_map[ii];                                           //~v39AR~
        ch=cht & A_CHARTEXT;   //acs_map['{'(0x7b)]=Pi(ALT_CHAR+0xe3)//~v57QR~
        if (ch)         //defined(printable?)                      //~v57QR~
        if (ch!=ii)	//rh9 acsmap is acs_map[ii]==A_ALTCHARSET+ii   //~v57QI~
        Sacsmap[ch]=cht;                                           //~v57QR~
    }                                                              //~v39AR~
#else                                                              //~v40uI~
    for (ii=0;ii<128;ii++)                                         //~v40uI~
    {                                                              //~v40uI~
        cht=_WACS_TO_ACS(wacs_map+ii);                             //~v40uR~
        ch=cht & A_CHARTEXT;                                       //~v40uI~
        if (cht & A_ALTCHARSET)                                    //~v40uR~
        	Sacsmap[ch]=cht;                                       //~v40uR~
    }                                                              //~v40uI~
#endif                                                             //~v40uI~
UTRACED("Sacsmap",Sacsmap,sizeof(Sacsmap));                        //~v5n8I~
    return 0;                                                      //~v324R~
}//uviol_init
#ifdef LNX                                                         //~v5ijI~
#ifndef XXE                                                        //~v5ijI~
//*********************************************************************//~v5ijI~
//* uviol_acssetup                                                 //~v5ijI~
//*   parm seq is fix                                              //~v5ijI~
//*********************************************************************//~v5ijI~
void uviol_acssetup(int Psetsw,int Pentno,UCHAR *Pacstbl)          //~v5ijI~
{                                                                  //~v5ijI~
	int ii;                                                        //~v5ijI~
	UCHAR *pc;                                                     //~v5ijR~
#define MAX_LINEACS  11                                            //~v5ijI~
    chtype cht[MAX_LINEACS]={                                      //~v5ijI~
					ACS_LLCORNER,	//	(acs_map['m'])	/* lower left corner *///~v5ijI~
					ACS_BTEE,		//	(acs_map['v'])	/* tee pointing up *///~v5ijI~
					ACS_LRCORNER,	//	(acs_map['j'])	/* lower right corner *///~v5ijI~
					ACS_LTEE,		//	(acs_map['t'])	/* tee pointing right *///~v5ijI~
					ACS_PLUS,		//	(acs_map['n'])	/* large plus or crossover *///~v5ijI~
					ACS_RTEE,		//	(acs_map['u'])	/* tee pointing left *///~v5ijI~
					ACS_ULCORNER,	//	(acs_map['l'])	/* upper left corner *///~v5ijI~
					ACS_TTEE,		//	(acs_map['w'])	/* tee pointing down *///~v5ijI~
					ACS_URCORNER,	//	(acs_map['k'])	/* upper right corner *///~v5ijI~
					ACS_HLINE,		//	(acs_map['q'])	/* horizontal line *///~v5ijI~
					ACS_VLINE};		//	(acs_map['q'])	/* horizontal line *///~v5ijI~
//*************************                                        //~v5ijI~
UTRACEP("acssetup setsw=%d\n",Psetsw);                             //~v5n8I~
    memset(Sacsmap,0,sizeof(Sacsmap));                             //~v5inI~
    if (Psetsw)	//not set req                                      //~v5inR~
        for (ii=0,pc=Pacstbl;ii<MAX_LINEACS;ii++,pc++)             //~v5ijR~
        {                                                          //~v5ijI~
         	if (ii<Pentno && *pc)                                  //~v5ijI~
            	Sacsmap[*pc]=cht[ii];                              //~v5ijI~
        }                                                          //~v5ijI~
UTRACED("Sacsmap",Sacsmap,sizeof(Sacsmap));                        //~v5n8I~
    return;                                                        //~v5ijI~
}//uviol_acssetup                                                  //~v5ijI~
#endif                                                             //~v5ijI~
#endif                                                             //~v5ijI~
//*********************************************************************//~v510I~
//* uviol_init2                                                    //~v510I~
//*   get dbcstbl addr from xe                                     //~v510I~
//*********************************************************************//~v510I~
void uviol_init2(UCHAR *Pdbcstbl)                                  //~v510I~
{                                                                  //~v510I~
	Sdbcstbl=Pdbcstbl;                                             //~v510I~
    return;                                                        //~v510I~
}//uviol_init2                                                     //~v510I~
//*********************************************************************//~v39WI~
//int uviol_konchk(void)                                           //~v39WI~
//{                                                                //~v39WI~
//    int konsw;                                                   //~v39WI~
////****************                                               //~v39WI~
//    if (LINES>25)      //may be under kon                        //~v39WI~
//        konsw=1;                                                 //~v39WI~
//    else                                                         //~v39WI~
//        konsw=0;                                                 //~v39WI~
//    return konsw;                                                //~v39WI~
//}//uviol_konchk                                                  //~v39WI~
#endif //!NOCURSES                                                 //~v6j0I~
#ifdef LNX                                                         //~v39WI~
//*********************************************************************//~v39WI~
//* chk under kon                                                  //~v39WI~
//  PID TTY STAT TIME COMMAND                                      //~v39WI~
//   97   6 S    0:00 /sbin/agetty 38400 tty6 linux                //~v39WI~
//   92   1 S    0:01 -bash                                        //~v39WI~
//  787   1 S    0:02  \_ kon                                      //~v39WI~
//  788  p0 S    0:00      \_ -bash                                //~v39WI~
//  857  p0 R    0:00          \_ ps -fa                           //~v39WI~
//ret :1:under kon,0:not under kon                                 //~v39WI~
//*********************************************************************//~v39WI~
int uviol_konchk(void)                                             //~v39WI~
{                                                                  //~v39WI~
#ifndef XSUB                                                       //~v6j0I~
    static int S1stsw,Skonswsv;                                    //~v39WR~
    char *ttyn;                                                    //~v57BR~
    int  rc=0;                                                     //~v57BR~
//************************                                         //~v39WI~
	if (S1stsw)			//2nd time                                 //~v39WI~
    	return Skonswsv;                                           //~v39WI~
    Guviol_flag|=UVIOL_KONCHKS;	//until KONCHKE,bypass call konchk from uerrmsg//~v50uI~
    S1stsw=1;                                                      //~v39WI~
    Skonswsv=0;                                                    //~v39WI~
//  ttyn=ttyname(0);                                               //~v6a0R~
    ttyn=uttyname(0);                                              //~v6a0I~
 if (ttyn)                                                         //~v5m1R~
  if (*(ttyn+8)=='p')          // /dev/ttypxx                      //~v50uR~
  {                                                                //~v50vI~
//   if (!uproc_getpsinfo(0,&pupsinfo0))                           //~v57BR~
//   {                                                             //~v57BR~
//    for (pid=getppid();;)               //parent                 //~v57BR~
//    {                                                            //~v57BR~
//        if (!(pupsinfo=uproc_srchpsinfo(pupsinfo0,pid)))         //~v57BR~
////          return 0;                                            //~v57BR~
//            break;                                               //~v57BR~
//      if (pupsinfo->UPSIcmd)                                     //~v57BR~
//        if (pc=strstr(pupsinfo->UPSIcmd,"kon"),pc)               //~v57BR~
//            if (!*(pc+3) || *(pc+3)==' ')                        //~v57BR~
            if (ukbdl_gettermsim() & TERM_UNDERKON)                //~v57BI~
	        {                                                      //~v39WI~
    			Guviol_flag|=UVIOL_KON;                            //~v50uR~
    			Skonswsv=1;                                        //~v39WR~
//      		return 1;                                          //~v50uR~
        		rc=1;                                              //~v50uI~
//                break;                                           //~v57BR~
        	}                                                      //~v39WR~
//        pid=pupsinfo->UPSIppid;     //parent pid                 //~v57BR~
//        if (pid==1)                                              //~v57BR~
//            break;                                               //~v57BR~
//    }                                                            //~v57BR~
//    uproc_freepsinfo(pupsinfo0);                                 //~v57BR~
//   }//getpsinfo success                                          //~v57BR~
  }//pty                                                           //~v50vI~
    Guviol_flag|=UVIOL_KONCHKE;                                    //~v50uI~
    return rc;                                                     //~v50uR~
#else       //!XSUB                                                //~v6j0I~
    Guviol_flag=(UVIOL_KONCHKS|UVIOL_KONCHKE);                     //~v6j0I~
	return 0;                                                      //~v6j0I~
#endif                                                             //~v6j0I~
}//uviol_konchk                                                    //~v39WI~
                                                                   //~v39WI~
#else                                                              //~v39WI~
                                                                   //~v39WI~
//*******************************************************          //~v39WI~
//for aix alwas return FALSE                                       //~v39WI~
//*******************************************************          //~v39WI~
int uviol_konchk(void)	//for AIX                                  //~v39WI~
{                                                                  //~v39WI~
    Guviol_flag=(UVIOL_KONCHKS|UVIOL_KONCHKE);                     //~v50uI~
	return 0;                                                      //~v39WI~
}                                                                  //~v39WI~
                                                                   //~v39WI~
#endif                                                             //~v39WI~
//*******************************************************          //~v5n8I~
//konchk for xsub uerrmsgedit                                      //~v5n8I~
//*******************************************************          //~v5n8I~
int uviol_konchk2(void)                                            //~v5n8I~
{                                                                  //~v5n8I~
#ifdef LNX                                                         //~v5n8I~
	int termid,konsw=0;                                            //~v5n8I~
//*************************                                        //~v5n8I~
    termid=ukbdl_gettermid();                                      //~v5n8I~
  	if ((termid & TERM_SIMID)!=TERM_XTERMSIM)	//except xterm sim //~v5n8I~
    {                                                              //~v5n8I~
        if (termid & TERM_SIMID) 	//other sim under X            //~v5n8I~
  			konsw=1;   //for uerrmsgedit                           //~v5n8I~
        else                                                       //~v5n8I~
  	    if (termid & TERM_UNDERKON) 	//under kon                //~v5n8I~
  			konsw=1;                                               //~v5n8I~
    }                                                              //~v5n8I~
    return konsw;                                                  //~v5n8I~
#else                                                              //~v5n8I~
	return 0;	//for AIX                                          //~v5n8I~
#endif                                                             //~v5n8I~
}//uviol_konchk2(void)	//for AIX                                  //~v5n8I~
#ifndef NOCURSES                                                   //~v6j0I~
//*******************************************************          //~v324M~
//*set color                                                       //~v324M~
//*parm:color BG-HL+BG(3bit)+FG-HL+FG(3bit)                        //~v324M~
//*******************************************************          //~v324M~
int uviol_colorinit(int Pmaxcolor,int Pmaxpair)                    //~v324I~
{                                                                  //~v324M~
    int ii,jj,rc=0,cno;                                            //~v342R~
    int maxbg;                                                     //~v55xI~
    short fg,bg;                                                   //~v342R~
//*********************************                                //~v324M~
    if (!Pmaxcolor)                                                 //~v324I~
        return 4;                                                  //~v324I~
    Scmap_dos2linux[ PALNO_BLACK ]=COLOR_BLACK;                    //~v342M~
    Scmap_dos2linux[ PALNO_HBLACK]=COLOR_BLACK;                    //~v342M~
    Scmap_dos2linux[ PALNO_RGB   ]=COLOR_WHITE;                    //~v342I~
    Scmap_dos2linux[ PALNO_HRGB  ]=COLOR_WHITE;                    //~v342I~
    Scmap_dos2linux[ PALNO_R     ]=COLOR_RED;                      //~v342I~
    Scmap_dos2linux[ PALNO_HR    ]=COLOR_RED;                      //~v342I~
    Scmap_dos2linux[ PALNO_G     ]=COLOR_GREEN;                    //~v342I~
    Scmap_dos2linux[ PALNO_HG    ]=COLOR_GREEN;                    //~v342I~
    Scmap_dos2linux[ PALNO_B     ]=COLOR_BLUE;                     //~v342I~
    Scmap_dos2linux[ PALNO_HB    ]=COLOR_BLUE;                     //~v342I~
    Scmap_dos2linux[ PALNO_RG    ]=COLOR_YELLOW;                   //~v342I~
    Scmap_dos2linux[ PALNO_HRG   ]=COLOR_YELLOW;                   //~v342I~
    Scmap_dos2linux[ PALNO_RB    ]=COLOR_MAGENTA;                  //~v342I~
    Scmap_dos2linux[ PALNO_HRB   ]=COLOR_MAGENTA;                  //~v342I~
    Scmap_dos2linux[ PALNO_GB    ]=COLOR_CYAN;                     //~v342I~
    Scmap_dos2linux[ PALNO_HGB   ]=COLOR_CYAN;                     //~v342I~
                                                                   //~v342I~
    if (Pmaxcolor==Pmaxpair)                                       //~v55xI~
    {                                                              //~v55xI~
#ifdef AIX                                                         //~v55xI~
        if (Pmaxcolor>2)                                           //~v55xI~
        {                                                          //~v55xI~
            Guviol_flag|=UVIOL_NOBGCOL;          //maxcolor=pairno(no bg color like as dtterm)//~v55xI~
            Snobgcolorsw=1;                                        //~v55xI~
        }                                                          //~v55xI~
#endif                                                             //~v55xI~
    	maxbg=1;                                                   //~v55xI~
    }                                                              //~v55xI~
    else                                                           //~v55xI~
    	maxbg=Pmaxcolor;                                           //~v55xI~
//  for (cno=0,jj=0;jj<Pmaxcolor;jj++)                             //~v55xR~
    for (cno=0,jj=0;jj<maxbg;jj++)                                 //~v55xI~
    {                                                              //~v342I~
        bg=Scmap_dos2linux[jj];                                    //~v342R~
        for (ii=0;ii<Pmaxcolor;ii++,cno++)                         //~v342R~
        {                                                          //~v342R~
//#ifdef AIX                                                       //~v55xR~
//            if (cno>=Pmaxpair)  //define black(default may dim black)//~v55xR~
//#else                                                            //~v55xR~
            if (!cno || cno>=Pmaxpair)                             //~v342I~
//#endif                                                           //~v55xR~
            	continue;                                          //~v342I~
//reverse BGR(1=red) to RGB(4=red) for XE                          //~v324I~
            fg=Scmap_dos2linux[ii];                                //~v342R~
//          rc+=init_pair(cno,fg,bg);                              //~v342R~//~v6BhR~
            rc+=init_pair((short)cno,fg,bg);                       //~v6BhI~
UTRACEP("%s:init_pair rc=%d,cno=%02x,fg=%d,bg=%d\n",UTT,rc,cno,fg,bg);     //~v342R~//~v6BhR~
        }                                                          //~v342R~
    }                                                              //~v342I~
#ifdef LNX                                                         //~v5h3I~
    bkgdset(0x0700);   //white on black                            //~v5h3I~
#endif                                                             //~v5h3I~
    return rc;                                                       //~v324I~
}//uviol_colorinit                                                 //~v324I~
//*********************************************************************
//* signal handler
//*********************************************************************
void uviol_termexit(int Psigid)
{
    uviol_cleanup();
    printf("uviol.c:Detected Signal %d\n",Psigid);                 //~v324R~
}//uviol_termexit                                                  //~v324R~
//*********************************************************************
//* restore kbd status
//*********************************************************************
void uviol_cleanup(void)
{
	int colorno,linuxcolor;                                        //~v342I~
    short r,g,b;                                                   //~v342I~
//*************************                                        //~v342I~
	Gukbdl_flag&=~GUKBDL_METAMODE;	//reset metamode               //~v50zI~
    if (Sorgcolor_changed) //original color content changed at once//~v342I~
        for (colorno=0;colorno<=Sorgcolor_saved;colorno++)         //~v342I~
        {                                                          //~v342I~
            linuxcolor=Scmap_dos2linux[colorno];                   //~v342I~
            r=Sorgcolor_saver[colorno]; //original color content to restore at term//~v342I~
            g=Sorgcolor_saveg[colorno]; //original color content to restore at term//~v342I~
            b=Sorgcolor_saveb[colorno]; //original color content to restore at term//~v342I~
//          init_color(linuxcolor,r,g,b);//restore original        //~v342I~//~v6BhR~
            init_color((short)linuxcolor,r,g,b);//restore original //~v6BhI~
        }                                                          //~v342I~
    refresh();
    endwin();
}//ukbl_cleanup
//*********************************************************************
//* vio term
//*********************************************************************
int uviol_term(void)
{
//*******************************
    if (!Sinitsw)                                                  //~v324I~
        return 0;                                                  //~v324I~
    uviol_cleanup();
	uehl_resetsh(Spurr);//uehl_setsh return eh registration record //~v354I~
    Sinitsw=0;                                                     //~v353I~
#ifdef XXE                                                         //~v5n8I~
#else                                                              //~v5n8I~
	UFREECLEARIFNZ(Guviombuffu);                                   //~v5n8I~
#endif                                                             //~v5n8I~
    return 0;
}//uviol_term                                                      //~v324R~
#endif //!NOCURSES                                                 //~v6j0I~
//*********************************************************************//~v324I~
//* beep                                                           //~v342R~
//*********************************************************************//~v324I~
int uviol_beep(void)                                               //~v324I~
{                                                                  //~v324I~
//*******************************                                  //~v324I~
#ifndef NOCURSES                                                   //~v6j0I~
    if (Sinitsw)                                                   //~v324I~
    	beep();                                                    //~v324I~
    else                                                           //~v324I~
#endif //!NOCURSES                                                 //~v6j0I~
    	printf("\a\n");		//0x07                                 //~v324I~
    return 0;                                                      //~v324I~
}//uviol_beep                                                      //~v324R~
#ifndef NOCURSES                                                   //~v6j0I~
//*******************************************************
//*VioSetMode(do nothing for linux
//*parm:pviomodeinfo,if 0 free work and return
//*******************************************************
UINT uviosetmode (PVIOMODEINFO pvioModeInfo)
{
//*********************************
    if (!pvioModeInfo)   //clear req                               //~v324R~
    {                                                              //~v324I~
//  	return uviol_term();                                       //~v324I~//~v6BhR~
    	return (UINT)uviol_term();                                 //~v6BhI~
    }                                                              //~v324I~
    return 4;
}//uviosetmode
//*******************************************************
//*VioReadCellStr
//*p1:(char+attr) string addr
//*p2:string len(=cell-count*2)
//*******************************************************
UINT uvioreadcellstr(PCH pchCellStr,int *Pplen,int Prow,int Pcol)
{
    int len,ii;
    chtype *pcht,cht;                                              //~v324R~
    USHORT *pcell;
//*********************************
    len=*Pplen/(Sattrcount+1);                                                    //~v324R~
    if (RANGE_CHKERR(Prow,Pcol,len))
        return 4;
#ifdef CURSESW                                                     //~v5n8I~
	uviom_readcell(0,Prow,Pcol,Spwkchtype,len);                    //~v5n8R~
#else                                                              //~v5n8I~
    mvinchnstr(Prow,Pcol,Spwkchtype,len);
#endif //!CURSESW                                                  //~v5n8I~
//  uviol_moveafter(Prow,Pcol,len);                                //~v399R~
    for (ii=0,pcell=(USHORT*)(void*)pchCellStr,pcht=Spwkchtype;ii<len;ii++)//~v324R~
//      *pcell++=*(USHORT*)(void*)pcht++;       //use color attr only//~v324R~
    {                                                              //~v324R~
        cht=*pcht++;                                               //~v324R~
//printw("read cht=%0x\n",cht);                                    //~v324R~
#ifndef BIGENDIAN                                                  //~v40jI~
//      *pcell++=(USHORT)((cht & A_CHARTEXT)+(PAIR2ATTR(cht)<<8));       //~v324I~//~v6BhR~
        *pcell++=(USHORT)((cht & A_CHARTEXT)+((chtype)PAIR2ATTR(cht)<<8));//~v6BhI~
#else                                                              //~v40jI~
        *pcell++=(USHORT)(((cht & A_CHARTEXT)<<8)+PAIR2ATTR(cht)); //~v40jI~
#endif                                                             //~v40jI~
    }                                                              //~v324I~
    return 0;                                                      //~v324R~
}//uvioreadcellstr
//*******************************************************
//*VioWrtCellStr
//*opt:lineopt                                                     //~v6EmR~
//*ret  :rc                                                        //~v6EmI~
//*******************************************************
//UINT uviowrtcellstr (PCH pchCellStr,int Plen,int Prow,int Pcol)  //~v6EmR~
UINT uviowrtcellstr(int Popt,PCH pchCellStr,int Plen,int Prow,int Pcol)//~v6EmI~
{
    int ii,len;
    chtype *pcht;
    USHORT *pcell,cell;                                            //~v324R~
    char *pdbcs=NULL;                                              //~v6h9R~
//*********************************
    len=Plen/(Sattrcount+1);
    if (RANGE_CHKERR(Prow,Pcol,len))
        return 4;
//UTRACED("cell",pchCellStr,len*2);                                  //~v5n8M~//~v6j0R~
    if (Sdbcstbl)                                                  //~v5inI~
    	pdbcs=Sdbcstbl+Prow*Sscrwidth+Pcol;                        //~v5inR~
    for (ii=0,pcell=(USHORT*)(void*)pchCellStr,pcht=Spwkchtype;ii<len;ii++)//~v324R~
//      *pcht++=*pcell++;   //use color attr only                  //~v324R~
    {                                                              //~v324I~
        cell=*pcell++;   //use color attr only                     //~v324I~
#ifdef BIGENDIAN                                                   //~v40jI~
        cell=(cell>>8)+((cell&255)<<8);	//swap text and attr       //~v40jI~
#endif                                                             //~v40jI~
        *pcht=(cell & 255)+ATTR2PAIR(cell);   //use color attr only//~v324R~
//      ALTCHARSET(*pcht);                                         //~v39yR~
#ifdef LNX                                                         //~v5inI~
		if (Sdbcstbl)                                              //~v5inI~
        {                                                          //~v5inI~
        	ALTCHARSET2_S(*pcht,*pdbcs);                           //~v5inI~
            pdbcs++;                                               //~v5inI~
        }                                                          //~v5inI~
        else                                                       //~v5inI~
#endif                                                             //~v5inI~
        ALTCHARSET_S(*pcht);                                       //~v39yI~
        pcht++;                                                    //~v324R~
//printw("cell=%0x,pair=%x,cht=%x\n",cell,ATTR2PAIR(cell),*(pcht-1));   
    }                                                              //~v324I~
//UTRACED("cell",Spwkchtype,len*4);                                  //~v5n8M~//~v6j0R~
//  uviol_mvaddchnstr(Prow,Pcol,Spwkchtype,len);                   //~v324R~//~v6EmR~
    uviol_mvaddchnstr(Popt,Prow,Pcol,Spwkchtype,len);              //~v6EmI~
    return 0;                                                      //~v324R~
}//uviowrtcellstr
//*******************************************************
//*VioReadCharStr(read char+attr then pick up char)
//*******************************************************
UINT uvioreadcharstr(PCH pchStr,int *Pplen,int Prow,int Pcol)
{
    int len;                                                       //~v324R~
//*********************************
    len=*Pplen;                                                    //~v324R~
    if (RANGE_CHKERR(Prow,Pcol,len))                               //~v324R~
        return 4;
    mvinnstr(Prow,Pcol,Spwkstr,len);    //last null is added       //~v324R~
//  uviol_moveafter(Prow,Pcol,len);                                //~v399R~
    memcpy(pchStr,Spwkstr,(UINT)len);                              //~v324I~
    return 0;
}//uvioreadcharstr
//*******************************************************
//*VioWrtCharStr(read char+attr and merge char then write)
//*******************************************************
//UINT uviowrtcharstr(PCH pchStr,int Plen,int Prow,int Pcol)       //~v6EmR~
UINT uviowrtcharstr(int Plineopt,PCH pchStr,int Plen,int Prow,int Pcol)//~v6EmI~
{
//*********************************
    if (RANGE_CHKERR(Prow,Pcol,Plen))
        return 4;
    mvaddnstr(Prow,Pcol,pchStr,Plen);
    UTRACED("pchStr",pchStr,Plen);                                 //~v6BhI~
//  uviol_moveafter(Prow,Pcol,Plen);                               //~v399R~
    move(Prow,Pcol);  //mvaddnstr miss cur pos                     //~v399R~
    return 0;
}//uviowrtcharstr
//*******************************************************
//*VioWrtCharStrAtt(support 3 byte attr)
//*******************************************************
//UINT uviowrtcharstratt(PCH Ppch,int Plen,int Prow,int Pcol,PBYTE pAttr)//~v6EmR~
UINT uviowrtcharstratt(int Popt,PCH Ppch,int Plen,int Prow,int Pcol,PBYTE pAttr)//~v6EmI~
{
    PCH pch;
    USHORT cell;
//  int ii,color;                                                  //~v6BhR~
    int ii;                                                        //~v6BhI~
    chtype color;                                                  //~v6BhI~
    chtype *pcht,cht;
    char *pdbcs=NULL;                                              //~v6h9R~
//*********************************
UTRACEP("wrtchatstratt row=%d,col=%d\n",Prow,Pcol);                //~v640I~
UTRACED("wrtchatstratt",Ppch,Plen);                                //~v640R~
    if (RANGE_CHKERR(Prow,Pcol,Plen))
        return 4;
//  cell=*pAttr<<8;                                                //~v6BhR~
    cell=(USHORT)(*pAttr<<8);                                      //~v6BhI~
    color=ATTR2PAIR(cell);                               //~v324R~
    if (Sdbcstbl)                                                  //~v5inI~
    	pdbcs=Sdbcstbl+Prow*Sscrwidth+Pcol;                        //~v5inR~
    for (ii=0,pcht=Spwkchtype,pch=Ppch;ii<Plen;ii++)    //drop attr
    {
        cht=color|*pch++;
//  	ALTCHARSET(cht);                                           //~v39yR~
#ifdef LNX                                                         //~v5inI~
		if (Sdbcstbl)                                              //~v5inI~
        {                                                          //~v5inI~
        	ALTCHARSET2_S(cht,*pdbcs);                             //~v5inI~
            pdbcs++;                                               //~v5inI~
        }                                                          //~v5inI~
        else                                                       //~v5inI~
#endif                                                             //~v5inI~
    	ALTCHARSET_S(cht);                                         //~v39yI~
        *pcht++=cht;
    }
//  uviol_mvaddchnstr(Prow,Pcol,Spwkchtype,Plen);                  //~v324R~//~v6EmR~
    uviol_mvaddchnstr(Popt,Prow,Pcol,Spwkchtype,Plen);             //~v6EmI~
    return 0;
}//uviowrtcharstratt
//*******************************************************
//*VioWrtNAtrr(read char+attr and merge attr then write)
//*******************************************************
UINT uviowrtnattr (PBYTE pAttr,int Plen,int Prow,int Pcol)
{
//  int ii,color;                                                  //~v6BhR~
    int ii;                                                        //~v6BhI~
    chtype color;                                                  //~v6BhI~
    USHORT cell;
    chtype *pcht,cht;
    char *pdbcs=NULL;                                              //~v6h9R~
//*********************************
    if (RANGE_CHKERR(Prow,Pcol,Plen))
        return 4;
#ifdef CURSESW                                                     //~v5nsI~
	uviom_readcell(0,Prow,Pcol,Spwkchtype,Plen);                   //~v5nsI~
#else                                                              //~v5nsI~
    mvinchnstr(Prow,Pcol,Spwkchtype,Plen);
#endif                                                             //~v5nsI~
//  cell=*pAttr<<8;                                                //~v6BhR~
    cell=(USHORT)(*pAttr<<8);                                      //~v6BhI~
    color=ATTR2PAIR(cell);                                //~v324R~
    if (Sdbcstbl)                                                  //~v5inI~
    	pdbcs=Sdbcstbl+Prow*Sscrwidth+Pcol;                        //~v5inR~
    for (ii=0,pcht=Spwkchtype;ii<Plen;ii++)    //drop attr
    {
        cht=color|(*pcht & ~A_COLOR);           //change color     //~v324R~
#ifdef LNX                                                         //~v5inI~
		if (Sdbcstbl)                                              //~v5inI~
        {                                                          //~v5inI~
        	ALTCHARSET2(cht,*pdbcs);                               //~v5inI~
            pdbcs++;                                               //~v5inI~
        }                                                          //~v5inI~
        else                                                       //~v5inI~
#endif                                                             //~v5inI~
        ALTCHARSET(cht);                                           //~v324I~
        *pcht++=cht;
    }
//  uviol_mvaddchnstr(Prow,Pcol,Spwkchtype,Plen);                  //~v324R~//~v6EmR~
    uviol_mvaddchnstr(0/*lineopt*/,Prow,Pcol,Spwkchtype,Plen);     //~v6EmI~
    return 0;
}//uviowrtnattr
//*******************************************************
//*VioWrtNCell(setup buff and write cell(char+attr))
//*******************************************************
//UINT uviowrtncell(PBYTE pCell,int Plen,int Prow,int Pcol)        //+v6EqR~
UINT uviowrtncell(int Popt,PBYTE pCell,int Plen,int Prow,int Pcol) //+v6EqI~
{
    int ii;
    USHORT cell;
    chtype *pcht,cht;
//*********************************
    if (RANGE_CHKERR(Prow,Pcol,Plen))
        return 4;
#ifndef BIGENDIAN                                                  //~v40jI~
    cell=*(USHORT*)(void*)pCell;                                                 //~v324R~
#else                                                              //~v40jI~
    cell=*pCell+(*(pCell+1)<<8);                                   //~v40jI~
#endif                                                             //~v40jI~
    cht=ATTR2PAIR(cell)+(cell&255);                                          //~v324R~
    ALTCHARSET(cht);                                               //~v324I~
    for (ii=0,pcht=Spwkchtype;ii<Plen;ii++)             //set NAttr
        *pcht++=cht;
//  uviol_mvaddchnstr(Prow,Pcol,Spwkchtype,Plen);                  //~v324R~//~v6EmR~
//  uviol_mvaddchnstr(0/*lineopt*/,Prow,Pcol,Spwkchtype,Plen);     //+v6EqR~
    uviol_mvaddchnstr(Popt/*lineopt*/,Prow,Pcol,Spwkchtype,Plen);  //+v6EqI~
    return 0;
}//uviowrtncell
//*******************************************************
//*VioWrtNChar(read char+attr and merge same char then write)
//*******************************************************
UINT uviowrtnchar(PCH pchChar,int Plen,int Prow,int Pcol)
{
    int ii;
    chtype *pcht,cht;
//*********************************
    if (RANGE_CHKERR(Prow,Pcol,Plen))
        return 4;
#ifdef CURSESW                                                     //~v5nsI~
	uviom_readcell(0,Prow,Pcol,Spwkchtype,Plen);                   //~v5nsI~
#else                                                              //~v5nsI~
    mvinchnstr(Prow,Pcol,Spwkchtype,Plen);
#endif                                                             //~v5nsI~
    for (ii=0,pcht=Spwkchtype;ii<Plen;ii++)    //drop attr
    {
        cht=(*pcht & A_ATTRIBUTES)|*pchChar;
        *pcht++=cht;
    }
//  uviol_mvaddchnstr(Prow,Pcol,Spwkchtype,Plen);                  //~v324R~//~v6EmR~
    uviol_mvaddchnstr(0/*lineopt*/,Prow,Pcol,Spwkchtype,Plen);     //~v6EmI~
    return 0;
}//uviowrtnchar
//*******************************************************
//*VioGetCurPos
//*******************************************************
UINT uviogetcurpos (int *Pprow,int *Ppcol)
{
    int y=0,x=0;                                                   //~v6hcR~
//*********************************
    getsyx(y,x);         //macro
   *Pprow=y;
   *Ppcol=x;
   return 0;
}//uviogetcurpos
//*******************************************************
//*VioSetCurPos
//*	blink when insert mode                                         //~v324I~
//*******************************************************
UINT uviosetcurpos (int Prow,int Pcol)
{
//*********************************
//UTRACEP("uviosetcurpos (%d,%d)\n",Prow,Pcol);                    //~v589R~
    if (RANGE_CHKERR(Prow,Pcol,1))                                 //~v324I~
        return 4;                                                  //~v324I~
#ifndef CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
	if (Svisibleblink)                                             //~v324R~
    	if (Svisible_oldcol>=0)	//not 1st time                     //~v324I~
        	if (Prow!=Svisible_oldrow||Pcol!=Svisible_oldcol)      //~v324I~
    			uviol_attrupdate(Svisible_oldrow,Svisible_oldcol,Sinsertmode,0);//reset//~v347R~
	if (Svisibleblink)                                             //~v324I~
//      if (Prow!=Svisible_oldrow||Pcol!=Svisible_oldcol)          //~v39rR~
#endif //CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
            uviol_attrupdate(Prow,Pcol,Sinsertmode,1);//set on     //~v347R~
    move(Prow,Pcol);                                               //~v399M~
    return 0;                                                      //~v324I~
}//uviosetcurpos
//*******************************************************
//*VioGetCurType
//*******************************************************
UINT uviogetcurtype(PVIOCURSORINFO pvioCursorInfo)
{
    int visible;//0:invisible,1:normal,2:visible(half box)         //~v324I~
//*********************************
    visible=curs_set(1);	//get prev value;                      //~v324I~
    curs_set(visible);		//restore                              //~v324I~
    memset(pvioCursorInfo,0,sizeof(VIOCURSORINFO));                //~v324I~
    switch(visible)                                                //~v324I~
    {                                                              //~v324I~
    case 0: //invisible                                            //~v324I~
    	pvioCursorInfo->yStart=0;                                  //~v324I~
    	pvioCursorInfo->cEnd=0;                                    //~v324I~
        break;                                                     //~v324I~
    case 2: //visible                                              //~v324R~
    	pvioCursorInfo->yStart=1;                                  //~v324I~
    	pvioCursorInfo->cEnd=2;                                    //~v324I~
        break;                                                     //~v324I~
    default:          //normal                                     //~v324I~
    	pvioCursorInfo->yStart=2;                                  //~v324I~
    	pvioCursorInfo->cEnd=2;                                    //~v324I~
    }                                                              //~v324I~
    return 0;                                                      //~v324R~
}//uviogetcurtype

//*******************************************************
//*VioSetCurType
// invisible:start=0,end=0                                         //~v324I~
// visible  :start=1,end=2                                         //~v324I~
// normal   :start=2,end=2                                         //~v324I~
//rc:0:ok, 4:box not supported                                     //~v324I~
//*******************************************************
UINT uviosetcurtype (PVIOCURSORINFO pvioCursorInfo)
{
    int visible;//0:invisible,1:normal,2:visible(half box)         //~v324I~
    int start,end;                                                 //~v324I~
    int x,y;                                                       //~v50ZR~
#ifndef CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
    int oldvis;                                                    //~v50ZI~
#endif //CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
//*********************************
#ifndef CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
	oldvis=Svisibleblink;                                          //~v324I~
    Svisibleblink=0;                                               //~v324I~
#endif //CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
    start=pvioCursorInfo->yStart;                                  //~v324R~
    end=pvioCursorInfo->cEnd;                                      //~v324R~
    if (!start && !end)                                            //~v324I~
    	visible=0;                                                 //~v324I~
    else                                                           //~v324I~
    if (start==1 && end==2)                                        //~v324I~
    	visible=2;                                                 //~v324I~
    else                                                           //~v324I~
    	visible=1;                                                 //~v324I~
    curs_set(visible);		//restore                              //~v324I~
    if (visible==2)			//request box                          //~v324I~
    {                                                              //~v324I~
#ifdef LNX     //aix may change,but tterm cursor type is fixed     //~v40sI~
//  	if (!cursor_visible)	//term.h string to set visible     //~v39oR~
//      {                                                          //~v39oR~
#endif                                                             //~v40sI~
#ifndef CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
            Svisibleblink=1;    //blink when insert mode           //~v39qR~
#endif //CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
            uviogetcurpos(&y,&x);                                  //~v39qR~
//UTRACEP("uviosetcurtyp visible =2(%d,%d)\n",y,x);                //~v589R~
            uviol_attrupdate(y,x,Sinsertmode,1);//set on           //~v39qR~
        	return 4;                                              //~v324I~
#ifdef LNX                                                         //~v40sI~
//      }                                                          //~v39oR~
#endif                                                             //~v40sI~
    }                                                              //~v324I~
#ifndef CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
    else                                                           //~v324I~
    	if (oldvis)	//blinking                                     //~v324R~
        {                                                          //~v324I~
			uviogetcurpos(&y,&x);                                  //~v324I~
//UTRACEP("uviosetcurtyp visible reset(%d,%d)\n",y,x);             //~v589R~
            uviol_attrupdate(y,x,Sinsertmode,0);//reset            //~v347R~
    	}                                                          //~v324I~
#endif //CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
    return 0;                                                      //~v324R~
}//uviosetcurtype
//*******************************************************
//*VioWrtTTY
//*******************************************************
UINT uviowrttty(PCH pch,int Plen)
{
//*********************************
//  return addnstr(pch,Plen);                                      //~v324R~//~v6BhR~
    return (UINT)addnstr(pch,Plen);                                //~v6BhI~
}//uviowrttty
//*******************************************************          //~v324I~
//*uviol_rgb2colorno                                               //~v324I~
//* convert colorno from rgb value                                 //~v324I~
//* parm rgb                                                       //~v324I~
//*******************************************************          //~v324I~
int uviol_rgb2colorno(int *Prgbindex,USHORT Pr,USHORT Pg,USHORT Pb)//~v324I~
{                                                                  //~v324I~
//  USHORT r;                                                      //~v324I~//~v690R~
    short r;                                                       //~v690I~
    int   ir,ig,ib,color=0;                                        //~v324I~
#ifndef BBB                                                        //~v5nbI~
//  USHORT sr,sg,sb;                                                //~v5nbR~//~v690R~
    short  sr,sg,sb;                                               //~v690I~
//**********************************************************       //~v324I~
    color_content(COLOR_YELLOW,&sr,&sg,&sb);                       //~v5nbR~
UTRACEP("color contents yellow no=%d,r=%x,g=%x,b=%x\n",COLOR_YELLOW,sr,sg,sb);//~v5nbR~
    color_content(COLOR_CYAN,&sr,&sg,&sb);                         //~v5nbR~
UTRACEP("color contents cyan no=%d,r=%x,g=%x,b=%x\n",COLOR_CYAN,sr,sg,sb);//~v5nbR~
    color_content(COLOR_MAGENTA,&sr,&sg,&sb);                      //~v5nbR~
UTRACEP("color contents magenta no=%d,r=%x,g=%x,b=%x\n",COLOR_MAGENTA,sr,sg,sb);//~v5nbR~
    color_content(COLOR_WHITE,&sr,&sg,&sb);                        //~v5nbI~
UTRACEP("color contents white no=%d,r=%x,g=%x,b=%x\n",COLOR_WHITE,sr,sg,sb);//~v5nbI~
#endif                                                             //~v5nbI~
	if (!Srgbunit)                                                 //~v324I~
    {                                                              //~v324I~
    	color_content(COLOR_WHITE,&r,&r,&r);                       //~v324I~
        Srgbunit=r/3;	//4 level                                  //~v392R~
        if (!Srgbunit)                                             //~v324I~
        	return 4;                                              //~v324I~
    }                                                              //~v324I~
    ir=Pr/Srgbunit;                                                //~v342R~
    ig=Pg/Srgbunit;                                                //~v342R~
    ib=Pb/Srgbunit;                                                //~v342R~
                                                                   //~v392I~
    if (ir & 0x01)                                                 //~v342R~
    	color|=0x20;	//l. .h..	red   low                      //~v324I~
    if (ir & 0x02)                                                 //~v342R~
    	color|=0x04;	//l. .h..	red   high                     //~v324I~
    if (ig & 0x01)                                                 //~v342R~
    	color|=0x10;	//.l ..h.	green low                      //~v324I~
    if (ig & 0x02)                                                 //~v342R~
    	color|=0x02;	//.l ..h.	green high                     //~v324I~
    if (ib & 0x01)                                                 //~v342R~
    	color|=0x08;	//.. l..h	green low                      //~v324I~
    if (ib & 0x02)                                                 //~v342R~
    	color|=0x01;	//.. l..h	green high                     //~v324I~
    *Prgbindex=color;                                              //~v324I~
	return 0;                                                      //~v324I~
}//uviol_colorno2rgb                                               //~v324I~
//*******************************************************          //~v324I~
//*uviol_colorno2rgb                                               //~v324I~
//* convert color no to rgb value                                  //~v324I~
//* parm colorno:DOS color register value(same as int x10 ah=x10)  //~v324I~
//*******************************************************          //~v324I~
int uviol_colorno2rgb(int Prgbindex,USHORT *Pr,USHORT *Pg,USHORT *Pb)//~v324I~
{                                                                  //~v324I~
//  USHORT r;                                                      //~v324I~//~v690R~
    short  r;                                                      //~v690I~
//**********************************************************       //~v324I~
	if (!Srgbunit)                                                 //~v324I~
    {	                                                           //~v324I~
    	color_content(COLOR_WHITE,&r,&r,&r);                       //~v324I~
        Srgbunit=r/3;	//4 level                                  //~v392R~
        if (!Srgbunit)                                             //~v324I~
        	return 4;                                              //~v324I~
    }                                                              //~v324I~
	if (Prgbindex>=64) //4bit value                                //~v324I~
    	return 4;                                                  //~v324I~
//	*Pr=(((Prgbindex&0x04)>>1)+((Prgbindex&0x20)>>5))*Srgbunit;	//l. .h..	red//~v392R~//~v6BhR~
  	*Pr=(USHORT)((((Prgbindex&0x04)>>1)+((Prgbindex&0x20)>>5))*Srgbunit);	//l. .h..	red//~v6BhI~
//  *Pg=(((Prgbindex&0x02)   )+((Prgbindex&0x10)>>4))*Srgbunit;	//.l ..h.	green//~v392R~//~v6BhR~
    *Pg=(USHORT)((((Prgbindex&0x02)   )+((Prgbindex&0x10)>>4))*Srgbunit);	//.l ..h.	green//~v6BhI~
//  *Pb=(((Prgbindex&0x01)<<1)+((Prgbindex&0x08)>>3))*Srgbunit;	//.. l..h	blue//~v392R~//~v6BhR~
    *Pb=(USHORT)((((Prgbindex&0x01)<<1)+((Prgbindex&0x08)>>3))*Srgbunit);	//.. l..h	blue//~v6BhI~
	return 0;                                                      //~v324I~
}//uviol_colorno2rgb                                               //~v324I~
//*******************************************************
//*uviogetstate
//* for DOS,supprt pallette reg and overscan reg
//*parm:req block addr
//*******************************************************
UINT uviogetstate(PVOID Ppreqblk)
{
	int reqtype,ii,maxcnt,rgbindex,colorno,linuxcolor,chngcolor=0; //~v342R~
    short  r,g,b;                                                  //~v342R~
	PVIOPALSTATE ppal;                                             //~v324I~
//*********************************                                //~v324I~
  	reqtype=(int)(*((short*)Ppreqblk+1));                          //~v324I~
	switch(reqtype)                                                //~v324I~
	{                                                              //~v324I~
	case 0:		//pallette reg get req                             //~v324I~
		ppal=Ppreqblk;                                             //~v324I~
		if (ppal->cb < sizeof(VIOPALSTATE)                         //~v324I~
		||  ppal->cb > sizeof(VIOPALSTATE)+15*2)                   //~v324I~
			return ERROR_VIO_INVALID_LENGTH;                       //~v324I~
        colorno=ppal->iFirst;                                      //~v324R~
//        if (colorno >= Smaxcolor)                                //~v324I~
//            return ERROR_VIO_INVALID_PARMS;                      //~v324R~
//  	maxcnt=(ppal->cb-sizeof(VIOPALSTATE))/2+1;                 //~v324I~//~v6BhR~
    	maxcnt=(ppal->cb-(int)sizeof(VIOPALSTATE))/2+1;            //~v6BhI~
//        if (colorno+maxcnt>Smaxcolor)                            //~v324R~
//            return ERROR_VIO_INVALID_PARMS;                      //~v324R~
		for (ii=0;ii<maxcnt;ii++,colorno++)                        //~v324I~
		{                                                          //~v324I~
        	if (Smaxcolor==2)	//mono color                       //~v324I~
            {                                                      //~v324I~
            	if (colorno)	//not 1st                          //~v324I~
                	rgbindex=1;     //white                        //~v324I~
                else                                               //~v324I~
                	rgbindex=0; 	//black                        //~v324I~
//				ppal->acolor[ii]=rgbindex;                         //~v324I~//~v6BhR~
  				ppal->acolor[ii]=(USHORT)rgbindex;                 //~v6BhI~
            }                                                      //~v324I~
            else                                                   //~v324I~
            {                                                      //~v324I~
            	if (colorno<Smaxcolor)	//not 1st                  //~v324I~
                {                                                  //~v324I~
					linuxcolor=Scmap_dos2linux[colorno];           //~v342I~
//                  color_content(linuxcolor,&r,&g,&b);            //~v342R~//~v6BhR~
                    color_content((short)linuxcolor,&r,&g,&b);     //~v6BhI~
                    if (!Sorgcolor_saved)	//1st time             //~v342I~
                    {                                              //~v342I~
                    	chngcolor=colorno;                         //~v342I~
    					Sorgcolor_saver[colorno]=r;	//original color content to restore at term//~v342I~
    					Sorgcolor_saveg[colorno]=g;	//original color content to restore at term//~v342I~
    					Sorgcolor_saveb[colorno]=b;	//original color content to restore at term//~v342I~
                    }                                              //~v342I~
//                  if (uviol_rgb2colorno(&rgbindex,r,g,b))        //~v324R~//~v6BhR~
                    if (uviol_rgb2colorno(&rgbindex,(USHORT)r,(USHORT)g,(USHORT)b))//~v6BhI~
                        return ERROR_VIO_EXTENDED_SG;   //not supported//~v324R~
                }                                                  //~v324I~
//              ppal->acolor[ii]=rgbindex;                         //~v324R~//~v6BhR~
                ppal->acolor[ii]=(USHORT)rgbindex;                 //~v6BhI~
            }                                                      //~v324I~
		}//reg count                                               //~v324I~
        Sorgcolor_saved=chngcolor;	//save color count             //~v342I~
	    if (!can_change_color())                                   //~v342I~
    		return ERROR_VIO_EXTENDED_SG;   //not supported        //~v342I~
	    Guviol_flag|=UVIOL_CHGCOLOR;                               //~v5nbI~
		break;                                                     //~v324I~
	case 1:		//overscan reg set req:not supported               //~v342I~
		break;                                                     //~v342I~
	case 2:		//brink or highlight background:not supported      //~v342I~
		break;                                                     //~v342I~
	default:                                                       //~v324I~
		return ERROR_VIO_INVALID_PARMS;                            //~v324I~
	}//switch by reqtype                                           //~v324I~
	return 0;                                                      //~v324I~
}//uvigetstate
//*******************************************************
//*uviosetstate
//* support color reg change only                                  //~v324R~
//*parm:req block addr
//*******************************************************
UINT uviosetstate(PVOID Ppreqblk)
{
	int reqtype,ii,maxcnt,colorno,rgbindex,linuxcolor;             //~v342R~
//  short  r,g,b;                                                  //~v342R~//~v690R~
    USHORT r,g,b;                                                  //~v690I~
	PVIOPALSTATE  ppal;                                            //~v324I~
//*********************************                                //~v324I~
    reqtype=(int)(*((short*)Ppreqblk+1));                          //~v324I~
	switch(reqtype)                                                //~v324I~
	{                                                              //~v324I~
	case 0:		//pallette reg set req                             //~v324I~
		ppal=Ppreqblk;                                             //~v324I~
		if (ppal->cb < sizeof(VIOPALSTATE)                         //~v324I~
		||  ppal->cb > sizeof(VIOPALSTATE)+15*2)                   //~v324I~
			return ERROR_VIO_INVALID_LENGTH;                       //~v324I~
		colorno=ppal->iFirst;                                      //~v324R~
//        if (colorno >= Smaxcolor)                                //~v324I~
//            return ERROR_VIO_INVALID_PARMS;                      //~v324R~
//  	maxcnt=(ppal->cb-sizeof(VIOPALSTATE))/2+1;                 //~v324I~//~v6BhR~
    	maxcnt=(ppal->cb-(int)sizeof(VIOPALSTATE))/2+1;            //~v6BhI~
//        if (colorno+maxcnt>Smaxcolor)                            //~v324R~
//            return ERROR_VIO_INVALID_PARMS;                      //~v324R~
		for (ii=0;ii<maxcnt;ii++,colorno++)                        //~v324I~
		{                                                          //~v324I~
        	if (Smaxcolor==2)	//mono color                       //~v324I~
            	break;                                             //~v324I~
            if (colorno>=Smaxcolor)                                //~v324I~
            	break;                                             //~v324I~
            rgbindex=ppal->acolor[ii];  //color reg of the pallette//~v324R~
            if (uviol_colorno2rgb(rgbindex,&r,&g,&b))              //~v324R~
                return ERROR_VIO_INVALID_PARMS;                    //~v324R~
			linuxcolor=Scmap_dos2linux[colorno];                   //~v342I~
//          if (init_color(linuxcolor,r,g,b))                      //~v342R~//~v6BhR~
            if (init_color((short)linuxcolor,(short)r,(short)g,(short)b))//~v6BhI~
                return 4;                                          //~v324R~
UTRACEP("init_color no=%d,r=%d,g=%d,b=%d\n",linuxcolor,r,g,b);     //~v5nbI~
    		Sorgcolor_changed=1; //original color content changed at once//~v342I~
		}//reg count                                               //~v324I~
		break;                                                     //~v324I~
	case 1:		//overscan reg set req:not supported               //~v342I~
		break;                                                     //~v342I~
	case 2:		//brink or highlight background:not supported      //~v342I~
		break;                                                     //~v342I~
	default:                                                       //~v324I~
		return ERROR_VIO_INVALID_PARMS;                            //~v324I~
	}//switch by reqtype                                           //~v324I~
	return 0;                                                      //~v324I~
}//uviosetstate
//*******************************************************
//*uvioscrolldn
//* scrool down(backward)
//*parm:range (top left and bottom right):colomn ignored
//*    :scroll count(line count inserted to top)
//*    :  if 0,full scroll
//*    :insert line padding char and attr
//*    :   for dos char ignored and always space is written
//*******************************************************
UINT uvioscrolldn(int Ptoprow,int Pleftcol,int Pbottomrow,int Prightcol,int Pline,UCHAR *Pcell)
{
    int ii,width,rto,rfrom,downcnt;                                //~v39dR~
    chtype cht,*pcht;                                              //~v324R~
    USHORT cell;
//*********************************
    width=Prightcol-Pleftcol;
    if (RANGE_CHKERR(Ptoprow,Pleftcol,width))
        return 4;
    if (RANGE_CHKERR(Pbottomrow,Pleftcol,width))
        return 4;
    rto=Pbottomrow+Pline;                                          //~v324R~
    rfrom=Pbottomrow;                                              //~v324R~
    downcnt=Pbottomrow-Ptoprow+1;                                  //~v39dR~
    width++;                                                       //~v39dI~
//  for (ii=0;ii<Pline && rfrom>=0;ii++,rto--,rfrom--)             //~v39dR~
    for (ii=0;ii<downcnt && rfrom>=0;ii++,rto--,rfrom--)           //~v39dI~
    {
        if (rto>=Sscrheight)                                       //~v324R~
            continue;                                              //~v324R~
        mvinchnstr(rfrom,Pleftcol,Spwkchtype,width);               //~v324R~
//      uviol_mvaddchnstr(rto,Pleftcol,Spwkchtype,width);          //~v324R~//~v6EmR~
        uviol_mvaddchnstr(0/*lineopt*/,rto,Pleftcol,Spwkchtype,width);//~v6EmI~
    }
#ifndef BIGENDIAN                                                  //~v40jI~
    cell=*(USHORT*)(void*)Pcell;                                                 //~v324R~
#else                                                              //~v40jI~
    cell=*Pcell+(*(Pcell+1)<<8);	//source is text+attr          //~v40jI~
#endif                                                             //~v40jI~
    cht=ATTR2PAIR(cell)+(cell&255);                                          //~v324R~
    ALTCHARSET(cht);                                               //~v324I~
    for (ii=0,pcht=Spwkchtype;ii<width;ii++)
        *pcht++=cht;                       //clear line            //~v324R~
    for (ii=rto;ii>=Ptoprow;ii--)                                  //~v324R~
//      uviol_mvaddchnstr(ii,Pleftcol,Spwkchtype,width);           //~v324R~//~v6EmR~
        uviol_mvaddchnstr(0/*lineopt*/,ii,Pleftcol,Spwkchtype,width);//~v6EmI~
    move(Ptoprow,Pleftcol);                                        //~v324I~
    return 0;
}//uvioscrolldn
//*******************************************************
//*uvioscrollup
//* scrool down(forward)
//*parm:range (top left and bottom right)
//*    :scroll count(line count inserted to bottom)
//*    :  if 0,full scroll
//*    :insert line padding char and attr
//*    :   for dos char ignored and always space is written
//*******************************************************
UINT uvioscrollup(int Ptoprow,int Pleftcol,int Pbottomrow,int Prightcol,int Pline,UCHAR *Pcell)
{
    int ii,width,rto,rfrom,upcnt;                                  //~v39dR~
    chtype cht,*pcht;                                              //~v324R~
    USHORT cell;
//*********************************
    width=Prightcol-Pleftcol;
    if (RANGE_CHKERR(Ptoprow,Pleftcol,width))
        return 4;
    if (RANGE_CHKERR(Pbottomrow,Pleftcol,width))
        return 4;
    rto=Ptoprow-Pline;                                             //~v324R~
    rfrom=Ptoprow;                                                 //~v324R~
    upcnt=Pbottomrow-Ptoprow+1;                                    //~v39dR~
    width++;                                                       //~v39dI~
//  for (ii=0;ii<Pline && rfrom<Sscrheight;ii++,rto++,rfrom++)     //~v39dR~
    for (ii=0;ii<upcnt && rfrom<Sscrheight;ii++,rto++,rfrom++)     //~v39dI~
    {
        if (rto<0)                                                 //~v324R~
            continue;                                              //~v324R~
        mvinchnstr(rfrom,Pleftcol,Spwkchtype,width);               //~v324R~
//      uviol_mvaddchnstr(rto,Pleftcol,Spwkchtype,width);          //~v324R~//~v6EmR~
        uviol_mvaddchnstr(0/*lineopt*/,rto,Pleftcol,Spwkchtype,width);//~v6EmI~
    }
#ifndef BIGENDIAN                                                  //~v40jI~
    cell=*(USHORT*)(void*)Pcell;                                                 //~v324R~
#else                                                              //~v40jI~
    cell=*Pcell+(*(Pcell+1)<<8);	//source is text+attr          //~v40jI~
#endif                                                             //~v40jI~
    cht=ATTR2PAIR(cell)+(cell&255);                                          //~v324R~
    ALTCHARSET(cht);                                               //~v324I~
    for (ii=0,pcht=Spwkchtype;ii<width;ii++)
        *pcht++=cht;                       //clear line            //~v324R~
    for (ii=rto;ii<=Pbottomrow;ii++)                               //~v39dR~
//      uviol_mvaddchnstr(ii,Pleftcol,Spwkchtype,width);           //~v324R~//~v6EmR~
        uviol_mvaddchnstr(0/*lineopt*/,ii,Pleftcol,Spwkchtype,width);//~v6EmI~
    move(Ptoprow,Pleftcol);                                        //~v324I~
    return 0;
}//uvioscrollup
//*******************************************************
//*clear screen                                                    //~v324R~
//*******************************************************
int uviol_clear(void)
{
//*********************************
    clear();                                                       //~v324R~
    refresh();
    return 0;
}//uviol_clear
//*******************************************************          //~v50KR~
//*draw screen                                                     //~v50KR~
//*******************************************************          //~v50KR~
int uviol_clearok(int Popt)                                        //~v50KR~
{                                                                  //~v50KR~
//*********************************                                //~v50KR~
UTRACEP("clearok %d\n",Popt);                                      //~v5n8I~
    clearok(stdscr,Popt);                                          //~v50KR~
    return 0;                                                      //~v50KR~
}//uviol_clearok                                                   //~v50KR~
//*******************************************************
//*draw screen                                                     //~v324R~
//*******************************************************
int uviol_refresh(void)
{
//*********************************
UTRACEP("refresh\n");                                              //~v5n8R~
    refresh();
    return 0;
}//uviol_refresh
#ifdef LNX                                                         //~v5n8R~
#ifndef CURSESW                                                    //~v5n8R~
//*******************************************************          //~v5n8R~
//*uvio_mvaddchnstrD                                               //~v5n8R~
//write multibyte by mvaddchnstr for hankaku-katakana(multibyte but wcwidth=1)//~v5n8R~
//-->But no frute gotten(display shrink line)                      //~v5n8R~
//*ret  :rc                                                        //~v5n8R~
//*******************************************************          //~v5n8R~
int uviol_mvaddchnstrD(int Prow,int Pcol,chtype *Ppcht,UCHAR *Ppdbcs,int Plen)//~v5n8R~
                                                                   //~v5n8R~
{                                                                  //~v5n8R~
    int rc=0,ch,escsw,noasciisw,ii,linewidth,mbslen,poss,pos,errrep;//~v5n8R~
    int dbcssw,reslen;                                             //~v5n8R~
    UCHAR  *pdbcs;                                                 //~v5n8R~
    chtype wkcht[UTF8_MAXCHARSZ],*pcht,*pchts;                     //~v5n8R~
//************************                                         //~v5n8R~
    UTRACEP("uvio_mvaddchnstrD len=%d,row=%d,col=%d\n",Plen,Prow,Pcol);//~v5n8R~
    UTRACED("chtype",Ppcht,Plen*CCTSZ);                            //~v5n8R~
    UTRACED("dbcs",Ppdbcs,Plen);                                   //~v5n8R~
    errrep=UVIO_ERRREP;                                            //~v5n8R~
    linewidth=min(Plen,Sscrwidth);                                 //~v5n8R~
    for (ii=0,noasciisw=0,escsw=0,pcht=Ppcht;ii<linewidth;ii++,pcht++)//~v5n8R~
    {                                                              //~v5n8R~
        ch=(*pcht & A_CHARTEXT);                                   //~v5n8R~
        if (ch>=0x80)                                              //~v5n8R~
            noasciisw=1;                                           //~v5n8R~
        else                                                       //~v5n8R~
        if (Gpdbcstbl[ch]&UDBCSCHK_TYPEUNP) //unprintable ascii    //~v5n8R~
            *pcht=(*pcht & ~(A_CHARTEXT|A_ALTCHARSET))|errrep; //reset uviol_altcharset's setting//~v5n8R~
        else                                                       //~v5n8R~
        if (ch==0x1b)                                              //~v5n8R~
            escsw=1;                                               //~v5n8R~
    }                                                              //~v5n8R~
    UTRACEP("noasciisw=%d escsw=%d\n",noasciisw,escsw);            //~v5n8R~
    if (!noasciisw  //all ascii                                    //~v5n8R~
    )                                                              //~v5n8R~
    {                                                              //~v5n8R~
        if (escsw)                                                 //~v5n8R~
        {                                                          //~v5n8R~
            mvaddchnstr(Prow,Pcol,Spspaceline,linewidth);          //~v5n8R~
            UTRACEP("clear by esc row=%d,col=%d\n",Prow,Pcol);     //~v5n8R~
        }                                                          //~v5n8R~
        mvaddchnstr(Prow,Pcol,Ppcht,linewidth);                    //~v5n8R~
        UTRACEP("%s:mvaddchnstr row=%d,col=%d\n",UTT,Prow,Pcol);   //~v6BhI~
        UTRACED("mvaddchnstr",Ppcht,linewidth*CCTSZ);              //~v6BhI~
        return 0;                                                  //~v5n8R~
    }                                                              //~v5n8R~
    if (!(Guviomopt & UDCWCIO_VIOCLEARDBCS))    //xescr write twice for dbcs//~v5n8R~
    {                                                              //~v5n8R~
        mvaddchnstr(Prow,Pcol,Spspaceline,linewidth);              //~v5n8R~
        UTRACEP("clear by DBCS row=%d,col=%d,len=%d\n",Prow,Pcol,linewidth);//~v5n8R~
    }                                                              //~v5n8R~
    for (pchts=0,pcht=Ppcht,pdbcs=Ppdbcs,pos=Pcol,poss=0,ii=0;     //~v5n8R~
            ii<linewidth;ii+=mbslen,pdbcs+=mbslen,pos+=mbslen)     //~v5n8R~
    {                                                              //~v5n8R~
        ch=(*pcht & A_CHARTEXT);                                   //~v5n8R~
        wkcht[0]=*pcht++;                                          //~v5n8R~
        mbslen=1;                                                  //~v5n8R~
        if (ch>=0x80)                                              //~v5n8R~
        {                                                          //~v5n8R~
            if (pchts)//preceding asccii string                    //~v5n8R~
            {                                                      //~v5n8R~
                mvaddchnstr(Prow,poss,pchts,pos-poss);             //~v5n8R~
    UTRACEP("sbcs row=%d,col=%d,len=&d\n",Prow,poss,pos-poss);     //~v5n8R~
    UTRACED("sbcs mvaddchnstr",pchts,(pos-poss)*CCTSZ);                //~v5n8R~//~v6BhR~
                pchts=0;                                           //~v5n8R~
            }                                                      //~v5n8R~
//not CURSESW                                                      //~v62UR~
            dbcssw=(*pdbcs==UDBCSCHK_DBCS1ST);                     //~v5n8R~
            reslen=linewidth-ii;                                   //~v5n8R~
            if (dbcssw && reslen>1)                                //~v5n8R~
            {                                                      //~v5n8R~
                wkcht[1]=*pcht++;                                  //~v5n8R~
                mbslen=2;                                          //~v5n8R~
            }                                                      //~v5n8R~
            else                                                   //~v5njI~
        		if (Gpdbcstbl[ch]&UDBCSCHK_TYPEUNP) //unprintable ascii//~v5njI~
            		wkcht[0]=(wkcht[0] & ~(A_CHARTEXT|A_ALTCHARSET))|errrep; //reset uviol_altcharset's setting//~v5njI~
            mvaddchnstr(Prow,pos,wkcht,mbslen);                    //~v5n8R~
    UTRACEP("dbcs/hankana row=%d,col=%d,len=%d\n",Prow,pos,mbslen);//~v5n8R~
    UTRACED("dbcs/hankana mvaddchnstr",wkcht,mbslen*CCTSZ);                    //~v5n8R~//~v6BhR~
        }                                                          //~v5n8R~
        else                                                       //~v5n8R~
        {                                                          //~v5n8R~
            if (!pchts)     //1st ascii                            //~v5n8R~
            {                                                      //~v5n8R~
                pchts=pcht-1;                                      //~v5n8R~
                poss=pos;   //ascii start col                      //~v5n8R~
            }                                                      //~v5n8R~
        }                                                          //~v5n8R~
    }                                                              //~v5n8R~
    if (pchts)//preceding asccii string                            //~v5n8R~
    {                                                              //~v5n8R~
        mvaddchnstr(Prow,poss,pchts,pos-poss);                     //~v5n8R~
UTRACED("sbcs LASTF mvaddchnstr",pchts,(pos-poss)*CCTSZ);                    //~v5n8R~//~v6BhR~
    }                                                              //~v5n8R~
UTRACEP("uvio_mvaddchnstrD return rc=%d\n",rc);                    //~v5n8R~
    return rc;                                                     //~v5n8R~
}//uvio_mvaddchnstrD                                               //~v5n8R~
#endif //!CURSESW                                                  //~v5n8R~
#endif //LNX                                                       //~v5n8R~
//************************************************************************//~v324I~
//*direct write chtype                                             //~v324R~
//*(because addchnstr reset color by attrset value if it is set)   //~v324I~
//************************************************************************//~v324I~
//int uviol_mvaddchnstr(int Prow,int Pcol,chtype *Ppcht,int Plen)    //~v324I~//~v6EmR~
int uviol_mvaddchnstr(int Plineopt,int Prow,int Pcol,chtype *Ppcht,int Plen)//~v6EmI~
{                                                                  //~v324I~
#ifdef LNX                                                         //~v40fI~
	UCHAR *pdbcs;                                                  //~v5n8I~
#ifdef CURSESW  //USE_WIDEC_SUPPORT                                //~v5nbM~
    int opt;                                                       //~v5n8I~
#endif                                                             //~v5n8I~
#ifdef TEST1                                                       //~v399R~
    int ii,x,y;                                                    //~v324R~
    chtype *pcht;                                                  //~v324R~
    struct ldat *pldat;                                            //~v324I~
//*********************************                                //~v324I~
    if (RANGE_CHKERR(Prow,Pcol,Plen))   //confirm                  //~v324R~
        return 4;                                                  //~v324R~
//  UTRACED("input text ",Ppcht,81*4);                             //~v392M~
    y=Prow;                                                        //~v324R~
    x=Pcol;                                                        //~v324I~
    pldat=&stdscr->_line[y];                                       //~v324R~
    for (ii=0,pcht=Ppcht;ii<Plen;ii++)                             //~v324I~
    {                                                              //~v324I~
        if (x>=Sscrwidth)                                          //~v324M~
        {                                                          //~v324M~
            y++;                                                   //~v324M~
            x=0;                                                   //~v324M~
    		pldat=&stdscr->_line[y];                               //~v324M~
        }                                                          //~v324M~
    	if (pldat->firstchar==_NOCHANGE)                           //~v324R~
    		pldat->firstchar=pldat->lastchar=x;                    //~v324R~
        else                                                       //~v324I~
    	if (x<pldat->firstchar)                                    //~v324R~
    		pldat->firstchar=x;                                    //~v324R~
        else                                                       //~v324I~
    	if (x>pldat->lastchar)                                     //~v324R~
    		pldat->lastchar=x;                                     //~v324R~
                                                                   //~v324I~
        pldat->text[x++]=*pcht++;                                  //~v324R~
    }                                                              //~v324I~
#else                                                              //~v399R~
#ifdef CURSESW  //USE_WIDEC_SUPPORT                                //~v5n8I~
  if (Guviomopt & UDCWCIO_KBDUTF8)	//env is utf8                  //~v5n8R~
  {                                                                //~v5n8I~
    pdbcs=Sdbcstbl+Prow*Sscrwidth+Pcol;                            //~v5n8I~
	opt=UVIOMWFO_UTF8OUT;                                          //~v5n8R~
	if (Guviomopt & UDCWCIO_VIOFROMUTF8)                           //~v5n8I~
//*user is xekbchk only                                            //~v640I~
		opt|=UVIOMWFO_UTF8IN;     //src:utf8->vio:utf8             //~v5n8R~
    else                                                           //~v5n8I~
		opt|=UVIOMWFO_MBIN;       //src:multibyte->vio:unicode(uvio_mvaddchnstrW)//~v5n8R~
  	if (!(Guviomopt & UDCWCIO_VIOCLEARDBCS))    //xescr write twice for dbcs//~v5nbI~
		opt|=UVIOMWFO_NODBCSCLEAR;       //no need to clear dbcs line//~v5nbI~
//  uvio_mvaddchnstrF(opt,Prow,Pcol,Ppcht,pdbcs,Plen);	//translate to utf8 then write//~v5n8R~//~v6EmR~
    uvio_mvaddchnstrF(opt,Plineopt,Prow,Pcol,Ppcht,pdbcs,Plen);	//translate to utf8 then write//~v6EmI~
  }                                                                //~v5n8I~
  else                                                             //~v5n8I~
#ifdef AAA  //ncusesw's mvaddchnstr with USE_WIDEC_SUPPORT simply put cchar to line from chtype assuming chtyupe is unicode ascii//~v5n8R~
  if (Guviomopt & (UDCWCIO_VIOCLEARDBCS|UDCWCIO_WCDBCS))    //xescr request;non utf8,clear line then write if DBCS contained for Japanese;and CN+KR//~v5n8R~
#endif      //so,when linking ncursesw addwchnstr should be used always//~v5n8R~
  {                                                                //~v5n8I~
    pdbcs=Sdbcstbl+Prow*Sscrwidth+Pcol;                            //~v5n8I~
	opt=UVIOMWFO_MBIN;       //src:multibyte->vio:unicode(uvio_mvaddchnstrW)//~v5n8I~
  	if (!(Guviomopt & UDCWCIO_VIOCLEARDBCS))    //xescr write twice for dbcs//~v5n8I~
		opt|=UVIOMWFO_NODBCSCLEAR;       //no need to clear dbcs line//~v5n8I~
//  uvio_mvaddchnstrF(opt,Prow,Pcol,Ppcht,pdbcs,Plen);	//multibyte->mb+unprintable/dbcsclear processing//~v5n8R~//~v6EmR~
    uvio_mvaddchnstrF(opt,Plineopt,Prow,Pcol,Ppcht,pdbcs,Plen);	//multibyte->mb+unprintable/dbcsclear processing//~v6EmI~
  }                                                                //~v5n8I~
#else  //!CURSESW                                                  //~v5n8I~
  #ifdef LNX                                                       //~v5nbI~
    pdbcs=Sdbcstbl+Prow*Sscrwidth+Pcol;                            //~v5nbM~
    uviol_mvaddchnstrD(Prow,Pcol,Ppcht,pdbcs,Plen);                //~v5nbM~
UTRACED("uviol_mvaddchnstrpldat",Ppcht,Plen*4);                    //~v5nbM~
  #else                                                            //~v5nbI~
    mvaddchnstr(Prow,Pcol,Ppcht,Plen);                             //~v5nbR~
  #endif                                                           //~v5nbI~
#endif                                                             //~v5n8I~
	move(Prow,Pcol);    //mvaddchnstr miss current pos             //~v399I~
#endif                                                             //~v399R~
//  return uviol_moveafter(Prow,Pcol,Plen);                        //~v324R~
//  UTRACED("pldat",pldat,sizeof(struct ldat));                    //~v382R~
//UTRACEP("mvaddchnstr row=%d,col=%d,len=%d\n",Prow,Pcol,Plen);    //~v5kfR~
    return 0;//xe issue no csrwrite when no csr moved              //~v324I~
#else	//!LNX                                                       //~v40fI~
//UTRACED("pldat",Ppcht,Plen*4);                                   //~v55xR~
	return mvaddchnstr(Prow,Pcol,Ppcht,Plen);                         //~v40fI~
#endif  //!LNX                                                     //~v40fI~
}//uviol_mvaddchnstr                                               //~v324I~
//************************************************************************//~v324I~
//*change attr                                                     //~v324I~
//*Ponsw:1-On,0-Off                                                //~v324I~
//************************************************************************//~v324I~
int uviol_attrupdate(int Prow,int Pcol,int Pattr,int Ponsw)        //~v324I~
{                                                                  //~v324I~
#ifdef TEST1                                                       //~v392R~
    chtype *pcht;                                                  //~v324I~
    struct ldat *pldat;                                            //~v324I~
#else                                                              //~v392I~
    chtype cht;                                                    //~v392I~
//#ifdef AIX                                                       //~v39ER~
#ifdef CURSESW  //Linux:USE_WIDEC_SUPPORT                          //~v5n8M~
#ifdef BBB                                                         //~v5n8M~
    chtype wkchtstr[2];                                            //~v5n8M~
    int    opt;                                                    //~v5n8M~
    UCHAR  wkdbcst[2];                                             //~v5n8M~
#else                                                              //~v5n8M~
//  cchar_t wkcchar;                                               //~v5n8M~//~v5nFR~
    cchar_t wkcchar2[2];                                           //~v5nFI~
#define wkcchar wkcchar2[0]                                        //~v5nFI~
#endif                                                             //~v5n8M~
#else                                                              //~v5n8I~
    chtype cht2;	//for dbcs 2nd byte                            //~v40tR~
#endif                                                             //~v5n8M~
//#endif                                                           //~v39ER~
    int    cy,cx;	//current pos to restore                       //~v39fR~
#endif                                                             //~v392I~
    int    chngsw=0;                                               //~v324I~
    int    dbcssw;                                                 //~v510I~
    int revisrtcsrsw=0;                                            //~v588I~
//*********************************                                //~v324I~
    if (RANGE_CHKERR(Prow,Pcol,1))                                 //~v324I~
        return 4;                                                  //~v324I~
#ifdef LNX     //linuxX maintain cursor automaticaly               //~v581I~
    if (SunderX)    //underX                                       //~v588R~
    {                                                              //~v588R~
      if (Smaxcolor==2)	//mono color and fg=black                  //~v588I~
        return 0;                                                  //~v581R~
//    if (Sundergt)	//gnome-terminal has no cursor color option    //~v5keR~
//no attr setting for cursor position                              //~v5keI~
//      return 0;                                                  //~v5kfR~
//    revisrtcsrsw=1;                                              //~v5keR~
    }                                                              //~v588R~
#else		//AIX                                                  //~v581I~
  	if (!(Gkbdaixt_opt & GKBAIX_TTERM))    //teraterm              //~v585R~
    {                                                              //~v588I~
      if (Smaxcolor==2	//mono color and fg=black                  //~v588I~
      ||  Snobgcolorsw)	//no bg color support                      //~v588R~
    	return 0;                                                  //~v585I~
      else                                                         //~v588I~
        revisrtcsrsw=1;                                            //~v588I~
    }                                                              //~v588I~
#endif                                                             //~v581I~
#ifdef TEST1                                                       //~v392R~
    pldat=&stdscr->_line[Prow];                                    //~v324I~
    pcht=&pldat->text[Pcol];                                       //~v324I~
    if (Ponsw)                                                     //~v324I~
    {                                                              //~v324I~
    	if ((*pcht & Pattr)!=Pattr)	//more bit tob set on          //~v324I~
        {                                                          //~v324I~
	    	*pcht|=Pattr;                                          //~v324I~
        	chngsw=1;                                              //~v324I~
        }                                                          //~v324I~
        Svisible_oldrow=Prow;                                      //~v324I~
        Svisible_oldcol=Pcol;                                      //~v324I~
    }                                                              //~v324I~
    else             //set off req                                 //~v324I~
    {                                                              //~v324I~
    	if ((*pcht & Pattr))	//more bit tob set on              //~v324I~
        {                                                          //~v324I~
	    	*pcht&=~Pattr;                                         //~v324I~
        	chngsw=1;                                              //~v324I~
        }                                                          //~v324I~
        Svisible_oldrow=-1;                                        //~v324I~
        Svisible_oldcol=-1;                                        //~v324I~
    }                                                              //~v324I~
    if (chngsw)                                                    //~v324I~
    {                                                              //~v324I~
    	if (pldat->firstchar==_NOCHANGE)                           //~v324I~
    		pldat->firstchar=pldat->lastchar=Pcol;                 //~v324I~
        else                                                       //~v324I~
    	if (Pcol<pldat->firstchar)                                 //~v324I~
    		pldat->firstchar=Pcol;                                 //~v324I~
        else                                                       //~v324I~
    	if (Pcol>pldat->lastchar)                                  //~v324I~
    		pldat->lastchar=Pcol;                                  //~v324I~
    }                                                              //~v324I~
#else	//!TEST                                                    //~v392R~
	uviogetcurpos(&cy,&cx);                                        //~v40fR~
#ifdef CURSESW  //Linux:USE_WIDEC_SUPPORT                          //~v5n8I~
	mvin_wchnstr(Prow,Pcol,&wkcchar,1);  //1 for also for DBCS     //~v5n8I~
UTRACED("attr update mvinwch",&wkcchar,sizeof(wkcchar));           //~v5n8I~
    cht=wkcchar.attr & A_ATTRIBUTES;                               //~v5n8I~
#else                                                              //~v5n8I~
    cht=mvinch(Prow,Pcol);                                         //~v40fR~
#endif                                                             //~v5n8I~
//#ifdef AIX                                                       //~v39ER~
//  if (udbcschk(cht & A_CHARTEXT))                                //~v510R~
//    if (Pcol+1<Sscrwidth)                                        //~v510R~
// 		cht2=mvinch(Prow,Pcol+1); //get dbcs 2nd byte              //~v510R~
//    else                                                         //~v510R~
//  	cht2=0;                                                    //~v510R~
//  else                                                           //~v510R~
//  	cht2=0;                                                    //~v510R~
//#endif                                                           //~v39ER~
//  dbcssw=*(Sdbcstbl+Prow*Sscrwidth+Pcol);                        //~v588R~
//  dbcssw=Sdbcstbl && *(Sdbcstbl+Prow*Sscrwidth+Pcol);            //~v59cR~
    if (Sdbcstbl)                                                  //~v59cR~
    	dbcssw=*(Sdbcstbl+Prow*Sscrwidth+Pcol);                    //~v59cR~
    else                                                           //~v59cR~
    	dbcssw=0;                                                  //~v59cR~
//UTRACED("dbcs tbl",Sdbcstbl,Prow*Sscrwidth+Pcol+2);              //~v589R~
//if (dbcssw==UDBCSCHK_DBCS2ND)                                    //~v62UR~
  if (UDBCSCHK_DBCSNOT1ST(dbcssw))                                 //~v62UR~
  {                                                                //~v510I~
        Svisible_oldrow=-1;                                        //~v510I~
        Svisible_oldcol=-1;	//not cursor written                   //~v510I~
  }                                                                //~v510I~
  else                                                             //~v510I~
  {                                                                //~v510I~
    if (Ponsw)                                                     //~v40fR~
    {                                                              //~v40fR~
#ifdef LNX                                                         //~v40sM~
      if (revisrtcsrsw)	//insert mode csr fg=white for color X-term//~v588I~
      {                                                            //~v588I~
      		cht |=A_REVERSE;		//reverse is only attr used in this env//~v588I~
	        chngsw=1;                                              //~v588I~
      }                                                            //~v588I~
      else		//not monocolor or console                         //~v588I~
      {                                                            //~v588I~
//      if (SunderX) //underX BLINK has no effect                  //~v580R~
//      {                                                          //~v580R~
//            if (dbcssw==UDBCSCHK_DBCS1ST)                        //~v580R~
//                chngsw=1;                                        //~v580R~
//      }                                                          //~v580R~
//      else //console mode                                        //~v580R~
//      {                                                          //~v580R~
        if (Smaxcolor==2)    //mono color                          //~v39oI~
        {                                                          //~v39oI~
//          if (Pattr & A_BLINK)                                   //~v39oI~//~v6BhR~
            if ((attr_t)Pattr & A_BLINK)                           //~v6BhI~
            {                                                      //~v39oI~
    	    	chngsw=1;                                          //~v39oI~
                cht |=A_BLINK;                                     //~v39oI~
//              cht2|=A_BLINK;                                     //~v510R~
            }                                                      //~v39oI~
            else                                                   //~v39oI~
            {                                                      //~v39oI~
              if (!(cht & A_STANDOUT))        //id of by ins mode  //~v39oI~
              {                                                    //~v39oI~
#ifndef CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
		    	Svisible_oldrev=cht & (A_REVERSE|A_BOLD);          //~v39oI~
#endif //CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
                if ((cht & (A_BOLD|A_REVERSE))==(A_BOLD|A_REVERSE))//gray in reverse//~v39oI~
                	cht &= ~A_BOLD;			//black in reverse     //~v39oR~
                else                                               //~v39oI~
                	cht |= (A_BOLD|A_REVERSE); //gray in reverse   //~v39oI~
                cht |=A_STANDOUT;        //id of by ins mode       //~v39oI~
//              cht2|=A_STANDOUT;        //id of by ins mode       //~v510R~
	        	chngsw=1;                                          //~v39oI~
              }                                                    //~v39oI~
            }                                                      //~v39oI~
        }                                                          //~v39oI~
        else                                                       //~v39oI~
//  	if ((cht & Pattr)!=Pattr)	//more bit tob set on          //~v40fR~//~v6BhR~
    	if ((cht & (attr_t)Pattr)!=(attr_t)Pattr)	//more bit tob set on//~v6BhI~
        {                                                          //~v40fR~
//      	cht|=Pattr;                                            //~v40fR~//~v6BhR~
        	cht|=(chtype)Pattr;                                    //~v6BhI~
//      	cht2|=Pattr;                                           //~v510R~
//          if ((Smaxcolor!=2) && (Pattr!=A_BLINK) && (cht & A_BOLD))//color and bold+rev//~v39fR~
//      		cht&=~A_BOLD;	//avoid gray fg                    //~v39fR~
        	chngsw=1;                                              //~v40fR~
        }                                                          //~v40fR~
//      }//console mode                                            //~v580R~
      }		//not monocolor or console                             //~v588I~
#else 	//AIX                                                      //~v40rI~
      if (revisrtcsrsw)	//insert mode csr fg=white for color X-term//~v588I~
      {                                                            //~v588I~
      		cht |=A_REVERSE;		//reverse is only attr used in this env//~v588I~
	        chngsw=1;                                              //~v588I~
      }                                                            //~v588I~
      else		//not monocolor or console                         //~v588I~
      {                                                            //~v588I~
        if (Pattr & A_BLINK)                                       //~v40sI~
        {                                                          //~v40tI~
        	cht |=A_BLINK;                                         //~v40sR~
//      	cht2|=A_BLINK;                                         //~v510R~
	        chngsw=1;                                              //~v39rI~
        }                                                          //~v40tI~
        else                                                       //~v40sI~
        {                                                          //~v40sI~
          if (!(cht & A_DIM))	//not yet rev by insmode           //~v39rI~
          {                                                        //~v39rI~
#ifndef CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
    		Svisible_oldrev=cht & (A_REVERSE|A_BOLD|A_BLINK);      //~v39rI~
//  		Svisible_oldrev2=cht2 & (A_REVERSE|A_BOLD|A_BLINK);    //~v510R~
#endif //CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
    		cht ^=A_REVERSE;	//reverse REVERSE bit              //~v39rR~
//  		cht2^=A_REVERSE;	//reverse REVERSE bit              //~v510R~
        	cht |=A_DIM;        //id of by ins mode                //~v39qR~
//      	cht2|=A_DIM;        //id of by ins mode                //~v510R~
	        chngsw=1;                                              //~v39rI~
          }                                                        //~v39rI~
        }                                                          //~v40sI~
      }		//not monocolor or console                             //~v588I~
#endif                                                             //~v40rI~
#ifndef CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
        Svisible_oldrow=Prow;                                      //~v40fR~
        Svisible_oldcol=Pcol;                                      //~v40fR~
#endif //CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
    }                                                              //~v40fR~
#ifndef CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
    else             //set off req                                 //~v392I~
    {                                                              //~v392I~
#ifdef LNX                                                         //~v40rI~
      if (revisrtcsrsw)	//insert mode csr fg=white for color X-term//~v588I~
      {                                                            //~v588I~
      		cht &=~A_REVERSE;		//reverse is only attr used in this env//~v588I~
	        chngsw=1;                                              //~v588I~
      }                                                            //~v588I~
      else		//not monocolor or console                         //~v588I~
      {                                                            //~v588I~
//      if (SunderX) //underX BLINK has no effect                  //~v580R~
//      {                                                          //~v580R~
//            if (dbcssw==UDBCSCHK_DBCS1ST)                        //~v580R~
//                chngsw=1;                                        //~v580R~
//      }                                                          //~v580R~
//      else //console mode                                        //~v580R~
//      {                                                          //~v580R~
        if (Smaxcolor==2)     //mono color                         //~v39oI~
        {                                                          //~v39oI~
//          if (Pattr & A_BLINK)                                   //~v39oI~//~v6BhR~
            if ((attr_t)Pattr & A_BLINK)                           //~v6BhI~
            {                                                      //~v39oI~
                cht &=~A_BLINK;                                    //~v39oI~
//              cht2&=~A_BLINK;                                    //~v510R~
	            chngsw=1;                                          //~v39oI~
            }                                                      //~v39oI~
            else    //reverse option                               //~v39oI~
                if (cht & A_STANDOUT)    //previously set by ins mode//~v39oI~
                {                                                  //~v39oI~
                    cht &=~(A_REVERSE|A_BOLD|A_STANDOUT);  //once reset//~v39oR~
//                  cht |= Svisible_oldrev;     //recover          //~v39oI~//~v6BhR~
                    cht |= (chtype)Svisible_oldrev;     //recover  //~v6BhI~
//                  cht2&=~(A_REVERSE|A_BOLD|A_STANDOUT);  //once reset//~v510R~
//                  cht2|= Svisible_oldrev;     //recover          //~v510R~
		            chngsw=1;                                      //~v39oI~
                }//else rewritten data                             //~v39oI~
        }                                                          //~v39oI~
        else                                                       //~v39oI~
//  	if ((cht & Pattr))	//more bit tob set on                  //~v39fR~
//    	if ((cht & Pattr)==Pattr)	//more bit tob set on          //~v39fI~//~v6BhR~
      	if ((cht & (attr_t)Pattr)==(attr_t)Pattr)	//more bit tob set on//~v6BhI~
        {                                                          //~v40fR~
//  		    if (Pattr!=A_BLINK    //reverse for insert mode    //~v39rR~
//  			&&  Svisible_oldrev & A_BOLD)	//prev is bold     //~v39rR~
//      			cht|=A_BOLD;                                   //~v39rR~
//      	cht&=~Pattr;                                           //~v40fR~//~v6BhR~
        	cht&=~(attr_t)Pattr;                                   //~v6BhI~
//      	cht2&=~Pattr;                                          //~v510R~
        	chngsw=1;                                              //~v40fR~
        }                                                          //~v40fR~
//      }    //console mode                                        //~v580R~
      }		//not monocolor or console                             //~v588I~
#else 	//AIX                                                      //~v40rI~
      if (revisrtcsrsw)	//insert mode csr fg=white for color X-term//~v588I~
      {                                                            //~v588I~
      		cht &=~A_REVERSE;		//reverse is only attr used in this env//~v588I~
	        chngsw=1;                                              //~v588I~
      }                                                            //~v588I~
      else		//not monocolor or console                         //~v588I~
      {                                                            //~v588I~
        if (Pattr & A_BLINK)                                       //~v40sI~
        {                                                          //~v39oI~
        	cht &=~A_BLINK;                                        //~v40sI~
//      	cht2&=~A_BLINK;                                        //~v510R~
	        chngsw=1;                                              //~v39oI~
        }                                                          //~v39oI~
        else 	//reverse option                                   //~v40sI~
        	if (cht & A_DIM)	//rev by ins mode                  //~v39qR~
        	{                                                      //~v40sI~
    			cht &=~(A_REVERSE|A_BOLD|A_DIM);	//once reset   //~v39qR~
//  	    	cht2&=~(A_REVERSE|A_BOLD|A_DIM);	//once reset   //~v510R~
            	cht |= Svisible_oldrev;     //recover              //~v39qR~
//          	cht2|= Svisible_oldrev2;     //recover             //~v510R~
		        chngsw=1;                                          //~v39oI~
        	}//else rewritten data                                 //~v40sI~
      }		//not monocolor or console                             //~v588I~
#endif                                                             //~v40rI~
        Svisible_oldrow=-1;                                        //~v40fR~
        Svisible_oldcol=-1;                                        //~v40fR~
    }                                                              //~v40fR~
  }//not on dbcs 2nd byte                                          //~v510I~
#endif //CSR_REDRAW		//attr save requred for csr move           //~v50ZI~
//UTRACEP("attr update chngsw=%d,dbcssw=%d\n",chngsw,dbcssw);      //~v589R~
    if (chngsw)                                                    //~v40fR~
    {                                                              //~v40fR~
#ifdef CURSESW  //Linux:USE_WIDEC_SUPPORT                          //~v5n8I~
#ifdef BBB                                                         //~v5n8I~
    	wkchtstr[0]=cht;                                           //~v5n8I~
        wkdbcst[0]=dbcssw;                                         //~v5n8I~
//BBB                                                              //~v62UR~
        if (dbcssw==UDBCSCHK_DBCS1ST)                              //~v5n8I~
        {                                                          //~v5n8I~
   			cht2=mvinch(Prow,Pcol+1); //get dbcs 2nd byte          //~v5n8I~
        	cht2=(cht & A_ATTRIBUTES)|(cht2 & A_CHARTEXT);	//same attr as 1st byte//~v5n8I~
	    	wkchtstr[1]=cht2;                                      //~v5n8I~
//BBB                                                              //~v62UR~
	    	wkdbcst[1]=UDBCSCHK_DBCS2ND;                           //~v5n8I~
        }                                                          //~v5n8I~
		opt|=UVIOMWFO_MBIN; //currently no UTF8 source is for xekbchk only//~v5n8I~
//BBB                                                              //~v62UR~
		uvio_mvaddchnstrF(opt,Prow,Pcol,wkchstr,wkdbcst,1+(dbcssw==UDBCSCHK_DBCS1ST));	//translate to utf8 then write//~v5n8I~
//UTRACEP("attr update mvaddch DBCS2 (%d,%d),cht=%x\n",Prow,Pcol+1,cht2);//~v5n8M~
#else   //write cchar_t                                            //~v5n8I~
	    mvin_wchnstr(Prow,Pcol,&wkcchar,1);  //1 for also for DBCS //~v5n8R~
UTRACED("attr update mvinwch",&wkcchar,sizeof(wkcchar));           //~v5n8I~
        wkcchar.attr=cht & A_ATTRIBUTES;                           //~v5n8R~
		uviom_mvaddwchnstr(Prow,Pcol,&wkcchar,1);	//translate to utf8 then write//~v5n8R~
UTRACED("attr update write cchar",&wkcchar,sizeof(wkcchar));       //~v5n8I~
#endif                                                             //~v5n8I~
#else                                                              //~v5n8I~
//  	cht=mvaddch(Prow,Pcol,cht);	//pos advance                  //~v510R~
    	    mvaddch(Prow,Pcol,cht);	//pos advance                  //~v510I~
//UTRACEP("attr update mvaddch (%d,%d),cht=%x\n",Prow,Pcol,cht);   //~v589R~
//#ifdef AIX                                                       //~v39ER~
//  	if (cht2 & A_CHARTEXT)                                     //~v510R~
        if (dbcssw==UDBCSCHK_DBCS1ST)                              //~v510R~
        {                                                          //~v510I~
   			cht2=mvinch(Prow,Pcol+1); //get dbcs 2nd byte          //~v510I~
        	cht2=(cht & A_ATTRIBUTES)|(cht2 & A_CHARTEXT);	//same attr as 1st byte//~v510I~
    		mvaddch(Prow,Pcol+1,cht2);	//dbcs 2nd byte            //~v510R~
            if (Pcol+2<Sscrwidth)                                  //~v62UR~
            {                                                      //~v62UR~
//!CURSESW                                                         //~v640I~
    			if (UDBCSCH_DBCSNOT1ST(*(Sdbcstbl+Prow*Sscrwidth+Pcol+2)))//~v62UR~
                {                                                  //~v62UR~
		   			cht2=mvinch(Prow,Pcol+2); //get dbcs 2nd byte  //~v62UR~
        			cht2=(cht & A_ATTRIBUTES)|(cht2 & A_CHARTEXT);	//same attr as 1st byte//~v62UR~
    				mvaddch(Prow,Pcol+2,cht2);	//dbcs 2nd byte    //~v62UR~
            	}                                                  //~v62UR~
            }                                                      //~v62UR~
            if (Pcol+3<Sscrwidth)                                  //~v62UR~
            {                                                      //~v62UR~
//!CURSESW                                                         //~v640I~
    			if (UDBCSCHK_DBCSNOT1ST(*(Sdbcstbl+Prow*Sscrwidth+Pcol+3)))//~v62UR~
                {                                                  //~v62UR~
		   			cht2=mvinch(Prow,Pcol+3); //get dbcs 2nd byte  //~v62UR~
        			cht2=(cht & A_ATTRIBUTES)|(cht2 & A_CHARTEXT);	//same attr as 1st byte//~v62UR~
    				mvaddch(Prow,Pcol+3,cht2);	//dbcs 2nd byte    //~v62UR~
            	}                                                  //~v62UR~
            }                                                      //~v62UR~
//UTRACEP("attr update mvaddch DBCS2 (%d,%d),cht=%x\n",Prow,Pcol+1,cht2);//~v589R~
        }                                                          //~v510I~
//#endif                                                           //~v39ER~
#endif	//!CURSESW                                                 //~v5n8I~
    	move(cy,cx);            //so restore                       //~v40fR~
    }                                                              //~v40fR~
#endif  //!TEST                                                    //~v392R~
    return 0;                                                      //~v324I~
}//uviol_attrupdate                                                //~v324I~
//************************************************************************//~v324I~
//*move cursor after read/write pos                                //~v324I~
//************************************************************************//~v324I~
//int uviol_moveafter(int Prow,int Pcol,int Plen)                  //~v399R~
//{                                                                //~v399R~
////*********************************                              //~v399R~
//    Prow+=(Pcol+Plen)/Sscrwidth;                                 //~v399R~
//    Pcol =(Pcol+Plen)%Sscrwidth;                                 //~v399R~
//    if (Prow>=Sscrheight)                                        //~v399R~
//        Prow=0;                                                  //~v399R~
//    return move(Prow,Pcol);                                      //~v399R~
//}//uviol_moveafter                                               //~v399R~
//*******************************************************          //~v6D9M~
//*draw line by one OutputCharacterW if attr indicate printable,else Ligature//~v6D9M~
//*because OutputCharacter 1 by 1 inserts space between each dbcs  //~v6D9M~
//*ret  :rc                                                        //~v6D9M~
//*******************************************************          //~v6D9M~
int uviol_set_padattrsub(int Popt,int Pcolorno)                    //~v6D9R~
{                                                                  //~v6D9M~
	int bgfg,colno;                                                //~v6D9M~
//**********************************                               //~v6D9M~
    bgfg=PAIR2ATTR((chtype)(Pcolorno<<8));       //colorno to bgfg //~v6D9R~
    bgfg=(bgfg & 0xf0)|UVIOM_PADATTR;  //change fg                 //~v6D9M~
    bgfg<<=8;  //as chtype                                         //~v6D9M~
    colno=(int)ATTR2PAIR((USHORT)bgfg)>>8;          //colorno      //~v6D9R~
    UTRACEP("%s:input inp color=%04x,out colorno=%08x\n",UTT,Pcolorno,colno);//~v6D9R~
    return colno;                                                  //~v6D9M~
}//uviol_set_padattrsub                                            //~v6D9R~
#endif //!NOCURSES                                                 //~v6j0I~
