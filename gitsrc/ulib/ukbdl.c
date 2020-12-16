//*CID://+v721R~:                             update#=  232;       //~v720R~//+v721R~
//*************************************************************
//ukbdl.c    (intf between ukbd and ukbdlnxc)                      //~v57BR~
//*kbd get for linux console screen
//*************************************************************
//v721:201212 (LNX)Drop -Nm option. it may be used for wxe+IME          //~v720I~//+v721R~
//v720:201211 (BUG)LNX Console;-Nm option did not work(DBCS chk is done)//~v720I~
//v702:200615 ARM compiler warning                                 //~v702I~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Be:160207 utf8 char input emulation                            //~v6B2I~
//v6s2:140213 add xfce4-terminal as terminal emulator              //~v6s2I~
//v6k0:130524 mkarmnc is compile err(term.h not found) by v6j0     //~v6k0I~
//v6j0:121102 (NOCUSRSES)for xcifb                                 //~v6j0I~
//v6f7:120421 subchar detection for ucs2mb(ICU)                    //~v6f7I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v691:100730 LP64 wchar_t is 4byte on LP64                        //~v691I~
//v65d:100311 RAW unicode input(ucs2local fail but accept it when env is utf8)//~v65dI~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62H:091006_(LNX:BUG)avoid kbd hung by read next utf8 char when ENV is UTF8 but terminal emulator generate locale code//~v62HI~
//v62i:090905 termid:TELNET for Linux                              //~v62iI~
//v620:090506 merge UTF8 version                                   //~v5ncI~
//            force utf8->locale option(gnome:utf8,env:locale case)//~v5ncI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5mv:080521 (LNX:CON)accept R-Ctrl key string definition max 4   //~v5mvI~
//v5kk:070531 (LNX)support Konsole as X-terminal                   //~v5kkI~
//v5kh:070531*(LNX:BUG)on sub dos cmd console,line dose not line-feed//~v5khI~
//v5g9:050708 (LNX)openwith support(add terminal sim nxterm,color-xterm,rxvt)//~v5g9I~
//v5ec:040211 (AIX:BUG)shellmode dosenot understand cr(carrige return)//~v5ecR~
//v5bm:040211 (AIX)force tab delay mode(rep tab by space)          //~v5bmI~
//v592:030928 (LNX)mouse support                                   //~v592I~
//v587:030816 (AIX)chk term-sim id by "ps -ef"                     //~v587I~
//v57X:030801 (AIX)defalt curses key setup for all X-term if not duplicated//~v57XI~
//v57N:030712 (LNX)defalt curses key setup for all X-term if not duplicated//~v57NI~
//v57E:030419 (AIX)getsimid func for aix                           //~v57EI~
//v57B:030419 (LNX)no process chain when xe executed by shell      //~v57BI~
//v57A:030413 (LNX)TTY=pts/n under X(ptsn for kon,ttyn for console)//~v57AI~
//v57z:030406 (LNX)gnome-terminal support                          //~v57zI~
//v57w:030223 (LNX:BUG)xterm/kterm should determined by cmd name not by TERM env var.//~v57wI~
//v555:020421 (AIX)accept key for aixterm                          //~v555I~
//v50M:010724 AIX:shell mode(if raw "sh" return immediately)       //~v50MR~
//v50z:010521 LINUX support:support getch/kbhit                    //~v50zI~
//v501:010305 X support:kterm/xterm generate 0x1b[A(hard codes in input.c)//~v501I~
//            but terminfo is 0x1bOA for up cursor key.            //~v501I~
//v39b:001113 LINUX support:move posix logic(common to linux and aix) to ukbdl from ukbdlnxc//~v39bI~
//v395:001105 LINUX support:switch echo,noraw<-->noecho,raw for sub-shell mode//~v395I~
//v384:001001 LINUX support(hearing of key assign from kbdinit)    //~v384I~
//v324 000813:LINUX support                                        //~v324I~
//*************************************************************    //~v324I~
#include <stdio.h>
#include <stdlib.h>                                                //~v324I~
#include <string.h>                                                //~v555I~
                                                                   //~v395I~
#ifdef AIX                                                         //~v395I~
	#include <curses.h>                                            //~v395I~
	#include <errno.h>                                             //~v50zI~
	#include <unistd.h>                                            //~v57ER~
#else                                                              //~v395I~
  #ifdef MGW32                                                     //~v5ncI~
	#include <ucurses.h>                                           //~v5ncI~
  #else                                                            //~v5ncI~
   #if !(defined(ARM) && defined(XXE))                             //~v6a0R~
   #ifndef NOCURSES                                                //~v6a0I~
	#include <ncurses.h>                                           //~v395I~
   #endif //NOCURSES                                               //~v6a0I~
   #endif //ARMXXE                                                 //~v6a0R~
  #endif                                                           //~v5ncI~
	#include <unistd.h>                                            //~v57wI~
	#include <iconv.h>                                             //~v5n8R~
#endif                                                             //~v395I~
#if !(defined(ARM) && defined(XXE))                                //~v6a0R~
//#ifndef NOCURSES                                                 //~v6j0R~
  #ifndef NOCURSES                                                 //~v6k0I~
#include <term.h>                                                  //~v39bI~
  #endif //NOCURSES                                                //~v6k0I~
//#endif //NOCURSES                                                //~v6j0R~
#endif //ARMXXE                                                    //~v6a0R~
                                                                   //~v324I~
#include <ulib.h>                                                  //~v324R~
#include <uabend.h>                                                //~v39bI~
#include <ukbd.h>                                                  //~v324I~
#include <uproc.h>                                                 //~v57wI~
#include <uerr.h>                                                  //~v57wI~
#include <udbcschk.h>                                              //~v5n8I~
#include <ucvucs.h>                                                //~v5n8I~
#include <ucvebc.h>                                                //~v5n8I~
#include <ucvext.h>                                                //~v5n8I~
#include <utrace.h>                                                //~v5n8I~
                                                                   //~v50zI~
#define UKBDL_GBL		//for ukbdl.h,generate gbl                 //~v50zI~
#include <ukbdl.h>                                                 //~v324I~
                                                                   //~v50zI~
#include <ukbdlnxc.h>                                              //~v324I~
#ifdef LNX                                                         //~v592I~
	#include <ukbdlnxm.h> 	//mouse                                //~v592I~
#endif                                                             //~v592I~
#include <utf.h>                                                   //~v5n8I~
#include <utf22.h>                                                 //~v65cI~
#ifdef XXE                                                         //~v5n8I~
#include <xxexei.h>                                                //~v5n8I~
#endif                                                             //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v5n8I~
	#include <ustring.h>                                           //~v5n8I~
#endif                                                             //~v5n8I~
                                                                   //~v384I~
//*********************************************************************
#ifndef ARMXXE                                                     //~v702I~
static int Sfd;		//fd returned by init                          //~v39bR~
static int Sgetchinit=0,Sgetcheinit=0;                             //~v555R~
static struct termios Soldgetch,Soldgetche;                        //~v39bI~
#endif                                                             //~v702I~
	iconv_t *Sphiconv;                                             //~v5n8R~
//* udbcschk:Sconverters; if LOCALICU mode Ptr to list of UConverters and Subchars*//~v6f7I~
	int   Swcstat=0;                                               //~v5n8R~
#ifndef ARMXXE                                                     //~v6a0I~
//*********************************************************************//~v5n8I~
int ukbdl_readutf8(int Pctr,KBDKEYINFO *Pkeyinfo);                 //~v5n8R~
int ukbdl_readdbcs(int Pctr,KBDKEYINFO *Pkeyinfo);                 //~v62UR~
//**************************************************               //~v324I~
//*kbdpeek                                                         //~v324I~
//*peek keyin                                                      //~v324I~
//*rc   :0:no data, 1:data exist                                   //~v324I~
//**************************************************               //~v324I~
int ukbdpeek(PKBDKEYINFO Pkeyinfo)                                 //~v324I~
{                                                                  //~v324I~
//*********************                                            //~v324I~
    return ukbdcharin(Pkeyinfo,-1);                                //~v324R~
}//ukbdpeek                                                        //~v324I~
                                                                   //~v324I~
//**************************************************               //~v324I~
//*get keyboard input                                              //~v324I~
//*wait option: 0(IO_WAIT) 1(IO_NOWAIT),-1(PEEK)                   //~v324R~
//*rc   :0:no data(NO WAIT only), 1:data exist                     //~v324I~
//**************************************************               //~v324I~
int ukbdcharin(KBDKEYINFO *Pkeyinfo,int Pnowait)                   //~v324R~
{                                                                  //~v324I~
    char inp[4];                                                   //~v324R~
    int  len,shiftstatus;                                      //~v324R~
#ifdef LNX                                                         //~v5n8I~
static int Sutf8pendctr=0;	                                       //~v5n8I~
#endif                                                             //~v5n8I~
//*********************                                            //~v324I~
#ifdef LNX                                                         //~v5n8I~
	if (Sutf8pendctr)                                              //~v5n8I~
    {                                                              //~v5n8I~
    	Sutf8pendctr=ukbdl_readutf8(Sutf8pendctr,Pkeyinfo);   //read 2nd byte of//~v5n8R~
        return 1;                                                  //~v5n8I~
    }                                                              //~v5n8I~
#endif                                                             //~v5n8I~
    memset(Pkeyinfo,0,sizeof(KBDKEYINFO));                         //~v324R~
    len=ukbdlnxc_read(inp,&shiftstatus,Pnowait);                   //~v324R~
    Pkeyinfo->fsState=(USHORT)shiftstatus;                          //~v324I~
    if (!len)                                                      //~v324I~
        return 0;                                                  //~v324R~
    Pkeyinfo->chChar=inp[0];                                        //~v324I~
    Pkeyinfo->chScan=inp[1];                                        //~v324I~
#ifdef LNX                                                         //~v592I~
    if (Pkeyinfo->chScan==UKLM_MOUSEID)                            //~v592I~
    {                                                              //~v592I~
   	 	Pkeyinfo->chMouseposx=inp[2];                              //~v592R~
    	Pkeyinfo->chMouseposy=inp[3];                              //~v592R~
    }                                                              //~v592I~
    else                                                           //~v5n8I~
    if (shiftstatus & UKBDLNXC_MOD_CTLR) //rctl use and detected rctl//~v5mvI~
    {                                                              //~v5mvI~
		Pkeyinfo->fbStatus=KBDTRF_SHIFT_KEY_IN;//shift report      //~v5mvI~
    }                                                              //~v5mvI~
    else                                                           //~v5n8I~
	if (Swcstat & UDCWCIO_KBDUTF8)   //utf8 kbd input              //~v5n8I~
    {                                                              //~v5n8I~
		if (!inp[1]  	//char code                                //~v5n8I~
        &&   UTF8_ISTOPBYTE(inp[0])		//start of UTF8 byte       //~v5n8I~
        )                                                          //~v5n8I~
        	Sutf8pendctr=ukbdl_readutf8(0,Pkeyinfo);   //read whole utf8 char//~v5n8R~
    }                                                              //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v62UR~
    else                                                           //~v62UR~
//	if (Gudbcschk_flag  & UDBCSCHK_KBDNOUTF8) //     0x04000000  //-Nm option on UTF8 env//~v720R~
//      ;                                                          //~v720R~
//  else                                                           //~v720R~
    if (Swcstat & UDCWCIO_DBCSREAD	//dbcs read at once in dbcs env//~v62UR~
    &&  UDBCSCHK_ISDBCS1ST(inp[0]))//it may be DBCS                //~v62UR~
    	ukbdl_readdbcs(0,Pkeyinfo);   //read whole dbcs char       //~v62UR~
#endif                                                             //~v62UR~
#endif                                                             //~v592I~
    return 1;                                                      //~v324I~
}//ukbdcharin                                                      //~v324I~
//**************************************************               //~v324I~
//*keyboard init for linux                                         //~v324I~
//**************************************************               //~v324I~
void ukbdl_init(int Popt,UCHAR *Pkeyassign)                        //~v384R~
{                                                                  //~v324I~
    UCHAR usekey[MAXPFKNO][4],*pc;    //f1-f12,plain,shift,control,alt//~v384R~
    int   exaltctl[4]={0,1,3,2};  //exchange alt<-->ctl            //~v384R~
    int   ii,jj;                                                   //~v384R~
//*********************                                            //~v324I~
//*get key assign info                                             //~v384I~
    for (ii=0,pc=Pkeyassign;ii<MAXPFKNO;ii++)                      //~v384R~
    	for (jj=0;jj<4;jj++,pc++)                                  //~v384R~
            usekey[ii][exaltctl[jj]]=*pc;                          //~v384R~
    Sfd=ukbdlnxc_init(Popt,(UCHAR*)usekey);                        //~v39bR~
    return;                                                        //~v324I~
}                                                                  //~v324I~
//**************************************************               //~v324I~
//*keyboard init for linux                                         //~v324I~
//**************************************************               //~v324I~
void ukbdl_term(void)                                              //~v324R~
{                                                                  //~v324I~
//*********************                                            //~v324I~
    ukbdlnxc_term(1);  //restore                                               //~v324I~
    return;                                                        //~v324I~
}                                                                  //~v324I~
//*********************************************************************//~v39bI~
//* assign sym to keycode with modifier                            //~v39bI~
//*********************************************************************//~v39bI~
void ukbdl_setkbmode(int Prestoresw)                               //~v39bI~
{                                                                  //~v39bI~
static int S1stsw=0;                                               //~v555R~
static struct termios Soldtios;                                    //~v39bI~
//************************                                         //~v39bI~
    if (Prestoresw)                                                //~v39bI~
    {                                                              //~v39bI~
        if (!S1stsw)                                               //~v39bI~
            return;                                                //~v39bI~
    	ukbdl_tcsetattr(Sfd,&Soldtios);                            //~v39bI~
    }                                                              //~v39bI~
    else                                                           //~v39bI~
    {                                                              //~v39bI~
        S1stsw=1;                                                  //~v39bI~
#ifdef AIX                                                         //~v5bmI~
		ukbdl_setgetchmode(Sfd,-2,&Soldtios);		//-2:set TABDLY//~v5bmI~
#else                                                              //~v5bmI~
		ukbdl_setgetchmode(Sfd,0,&Soldtios);		//no echo      //~v39bI~
#endif                                                             //~v5bmI~
    }                                                              //~v39bI~
    return;                                                        //~v39bI~
}//ukbdl_setkbmode                                                 //~v39bI~
//**************************************************               //~v395I~
//*for sub-shell mode,switch echo,noraw<-->noecho,raw mode         //~v395I~
//**************************************************               //~v395I~
void ukbdl_shellmode(int Pentrysw)                                 //~v395I~
{                                                                  //~v395I~
	struct termios oldtios,newtios;                                //~v39bI~
//************************                                         //~v39bI~
#ifdef AIX                                                         //~v50MR~
    switch(Pentrysw)                                               //~v50MR~
    {                                                              //~v50MR~
	case -1:    //from uviol_init;save shellmode                   //~v50MR~
        def_shell_mode();   //for later reset_shell_mode           //~v50MR~
        return;                                                    //~v50MR~
    case 2:     //exit by any exit cmd                             //~v50MR~
        def_prog_mode();    //save cur mode as curses mode for later restore//~v50MR~
        noraw();                                                   //~v50MR~
        reset_shell_mode();   //reset to shell mode saved at uviol_init//~v50MR~
        return;                                                    //~v50MR~
    case 3:     //temp exit                                        //~v50MR~
        raw();                                                     //~v50MR~
        reset_prog_mode();   //reset to prog mode saved before entry to shellmode//~v50MR~
        return;                                                    //~v50MR~
    }                                                              //~v50MR~
#endif                                                             //~v50MR~
    ukbdl_tcgetattr(Sfd,&oldtios);                                 //~v39bI~
    memcpy(&newtios,&oldtios,sizeof(newtios));                     //~v39bI~
    switch(Pentrysw)                                               //~v39bI~
    {                                                              //~v39bI~
    case 0:     //temp entry(exit by any key)                      //~v39bI~
        newtios.c_oflag |=  ONLCR; //change lf to crlf             //~v39bI~
        newtios.c_oflag |=  OPOST; //change lf to crlf             //~v5ecR~
        break;                                                     //~v39bI~
    case 1:     //temp exit                                        //~v39bI~
//      newtios.c_oflag &= ~ONLCR; //restore                       //~v39bI~//~v6B2R~
        newtios.c_oflag &= (UINT)~ONLCR; //restore                 //~v6B2I~
//      newtios.c_oflag &= ~OPOST; //change lf to crlf             //~v5ecR~//~v6B2R~
        newtios.c_oflag &= (UINT)(~OPOST); //change lf to crlf     //~v6B2I~
        break;                                                     //~v39bI~
#ifdef AIX                                                         //~v50MR~
#else                                                              //~v50MR~
    case 2:     //exit by any exit cmd                             //~v39bI~
        newtios.c_oflag |=  OPOST; //mandatory to process oflag    //~v5khI~
        newtios.c_oflag |=  ONLCR; //change lf to crlf             //~v39bI~
        newtios.c_lflag |=  ECHO ; //change lf to crlf             //~v39bI~
        break;                                                     //~v39bI~
    case 3:     //temp exit                                        //~v39bI~
//      newtios.c_oflag &= ~OPOST; //mandatory to process oflag    //~v5khI~//~v6B2R~
        newtios.c_oflag &= (UINT)(~OPOST); //mandatory to process oflag//~v6B2I~
//      newtios.c_oflag &= ~ONLCR; //restore                       //~v39bI~//~v6B2R~
        newtios.c_oflag &= (UINT)(~ONLCR); //restore               //~v6B2I~
//      newtios.c_lflag &= ~ECHO ; //change lf to crlf             //~v39bI~//~v6B2R~
        newtios.c_lflag &= (UINT)(~ECHO) ; //change lf to crlf     //~v6B2I~
        break;                                                     //~v39bI~
#endif                                                             //~v50MR~
    }                                                              //~v39bI~
    ukbdl_tcsetattr(Sfd,&newtios);                                 //~v39bI~
    return;                                                        //~v39bI~
}//ukbdl_shellmode                                                 //~v39bI~
//*********************************************************************//~v39bM~
//* assign sym to keycode with modifier                            //~v39bM~
//* p1rm2:0:no echo,1:echo,-1:peek mode(and no echo)               //~v50zI~
//*********************************************************************//~v39bM~
void ukbdl_setgetchmode(int Pfd,int Pechosw,struct termios *Ppoldtios)//~v39bR~
{                                                                  //~v39bM~
    struct termios newtios;                                        //~v39bR~
//************************                                         //~v39bM~
    ukbdl_tcgetattr(Pfd,Ppoldtios);                                //~v39bR~
    memcpy(&newtios,Ppoldtios,sizeof(newtios));                    //~v39bR~
//  newtios.c_lflag &= ~ (ICANON | ISIG);                          //~v39bR~//~v6B2R~
    newtios.c_lflag &= (UINT)(~ (ICANON | ISIG));                  //~v6B2I~
    if (Pechosw>0)   //getch but not getche                        //~v50zR~
        newtios.c_lflag |=   ECHO;  //echo off                     //~v50zI~
    else            //getch but not getche                         //~v50zI~
    {                                                              //~v5bmI~
//      newtios.c_lflag &= ~ ECHO;  //echo off                     //~v39bR~//~v6B2R~
        newtios.c_lflag &= (UINT)(~ ECHO);  //echo off             //~v6B2I~
#ifdef AIX                                                         //~v5bmI~
      if (Pechosw==-2)   //called from ukbdl_setkbmode             //~v5bmI~
      {                                                            //~v5bmI~
        newtios.c_oflag &= TABDLY;  //tab delay(rep tab by space)  //~v5bmI~
        Pechosw=0;		//not peek		                           //~v5bmI~
      }                                                            //~v5bmI~
#endif                                                             //~v5bmI~
    }                                                              //~v5bmI~
    newtios.c_iflag = 0;                                           //~v39bR~
    if (Pechosw<0)   //peek mode                                   //~v50zI~
    {                                                              //~v50zI~
    	newtios.c_cc[VMIN] = 0; //expect no read                   //~v50zI~
    	newtios.c_cc[VTIME] = 0; //no wait                         //~v50zI~
    }                                                              //~v50zI~
    else                                                           //~v50zI~
    {                                                              //~v50zI~
    newtios.c_cc[VMIN] = 1; //at least 1 byte wait                 //~v39bR~
    newtios.c_cc[VTIME] = 1;    /* 0.1 sec intercharacter timeout *///~v39bR~
    }                                                              //~v50zI~
    ukbdl_tcsetattr(Pfd,&newtios);                                 //~v39bI~
    return;                                                        //~v39bM~
}//ukbdl_setgetchmode                                              //~v39bI~
//*********************************************************************//~v39bM~
//* tc get attr                                                    //~v39bM~
//*********************************************************************//~v39bM~
void ukbdl_tcgetattr(int Pfd,struct termios *Pptios)               //~v39bI~
{                                                                  //~v39bM~
    int rc;                                                        //~v39bM~
//************************                                         //~v39bM~
    rc=tcgetattr(Pfd,Pptios);                                      //~v39bI~
    if (rc)                                                        //~v39bM~
    {                                                              //~v39bM~
        fprintf(stderr,"fd=%d,tcgetattr rc=%d :",Pfd,rc);          //~v39bI~
        perror("tcgetattr");                                       //~v39bM~
        fprintf(stderr,"\r");                                      //~v39bM~
//      uabend(1,errno,0,0);                                       //~v39bM~//~v6B2R~
        uabend(1,(ULONG)errno,0,0);                                //~v6B2I~
    }                                                              //~v39bM~
    return;                                                        //~v39bM~
}//ukbdl_tcgetattr                                                 //~v39bI~
//*********************************************************************//~v39bM~
//* tc set attr                                                    //~v39bM~
//*********************************************************************//~v39bM~
void ukbdl_tcsetattr(int Pfd,struct termios *Pptios)               //~v39bI~
{                                                                  //~v39bM~
    int rc;                                                        //~v39bM~
//************************                                         //~v39bM~
//  rc=tcsetattr(Pfd,TCSAFLUSH,Pptios);                            //~v50zR~
    rc=tcsetattr(Pfd,TCSANOW,Pptios);                              //~v50zI~
    if (rc)                                                        //~v39bM~
    {                                                              //~v39bM~
        fprintf(stderr,"fd=%d,tcsetattr rc=%d :",Pfd,rc);          //~v39bI~
        perror("tcsetattr");                                       //~v39bM~
        fprintf(stderr,"\r");                                      //~v39bM~
//      uabend(2,errno,0,0);                                       //~v39bM~//~v6B2R~
        uabend(2,(ULONG)errno,0,0);                                //~v6B2I~
    }                                                              //~v39bM~
    return;                                                        //~v39bM~
}//ukbdl_tcsetattr                                                 //~v39bI~
//*********************************************************************//~v39bI~
//* init for getch out of curses                                   //~v39bI~
//*********************************************************************//~v39bI~
int ukbdl_getch_init(void)                                         //~v39bI~
{                                                                  //~v39bI~
//*******************************                                  //~v39bI~
	if (Sgetchinit)                                                //~v39bI~
    	return 0;                                                  //~v39bI~
	ukbdl_getche_term();		//reset previous getche            //~v50zI~
	ukbdl_setgetchmode(0,0,&Soldgetch);                            //~v39bI~
    Sgetchinit=1;                                                  //~v39bI~
    return 0;                                                      //~v39bI~
}//ukbdl_getch_init                                                //~v39bI~
//*********************************************************************//~v39bI~
//* init for getche out of curses                                  //~v39bI~
//*********************************************************************//~v39bI~
int ukbdl_getche_init(void)                                        //~v39bI~
{                                                                  //~v39bI~
//*******************************                                  //~v39bI~
	if (Sgetcheinit)                                               //~v39bI~
    	return 0;                                                  //~v39bI~
	ukbdl_getch_term();		//reset previous getch                 //~v50zI~
	ukbdl_setgetchmode(0,1,&Soldgetche);                           //~v39bI~
    Sgetcheinit=1;                                                 //~v39bI~
    return 0;                                                      //~v39bI~
}//ukbdl_getche_init                                               //~v39bI~
//*********************************************************************//~v39bI~
//* end of getch env                                               //~v39bI~
//*********************************************************************//~v39bI~
int ukbdl_getch_term(void)                                         //~v39bI~
{                                                                  //~v39bI~
//*******************************                                  //~v39bI~
	if (!Sgetchinit)                                               //~v39bI~
    	return 0;                                                  //~v39bI~
	ukbdl_tcsetattr(0,&Soldgetch);                                 //~v39bI~
    Sgetchinit=0;                                                  //~v39bI~
    return 0;                                                      //~v39bI~
}//ukbdl_getch_term                                                //~v39bI~
//*********************************************************************//~v39bI~
//* end of getch env                                               //~v39bI~
//*********************************************************************//~v39bI~
int ukbdl_getche_term(void)                                        //~v39bR~
{                                                                  //~v39bI~
//*******************************                                  //~v39bI~
	if (!Sgetcheinit)                                              //~v39bI~
    	return 0;                                                  //~v39bI~
	ukbdl_tcsetattr(0,&Soldgetche);                                //~v39bI~
    Sgetcheinit=0;                                                 //~v39bI~
    return 0;                                                      //~v39bI~
}//ukbdlnxc_getche_term                                            //~v39bR~
//*********************************************************************//~v50zI~
//* peek once by kbhit                                             //~v50zI~
//  return:0:no hit,1:hit any                                      //~v50zI~
//*********************************************************************//~v50zI~
int ukbdl_kbhit(void)                                              //~v50zI~
{                                                                  //~v50zI~
	struct termios oldtios;                                        //~v50zR~
	KBDKEYINFO keyinfo;                                            //~v50zI~
    int rc;                                                        //~v50zI~
//*******************************                                  //~v50zI~
    ukbdl_setgetchmode(0,-1,&oldtios);	//peek mode                //~v50zI~
	rc=ukbdpeek(&keyinfo);                                         //~v50zI~
	ukbdl_tcsetattr(0,&oldtios);                                   //~v50zR~
    return rc;                                                     //~v50zI~
}//ukbdl_kbhit                                                     //~v50zI~
//*********************************************************************//~v39bI~
//* getch                                                          //~v39bI~
//* ret:char ,-1:err                                               //~v39bI~
//*********************************************************************//~v39bI~
int ukbdl_getch(int Popt)                                          //~v39bI~
{                                                                  //~v39bI~
    int modx=0,ch;                                                 //~v39bI~
    char outch[16];                                                //~v39bR~
//************************                                         //~v39bI~
	if (!Sgetchinit)                                               //~v39bI~
		ukbdl_getch_init();                                        //~v39bI~
    if (!ukbdlnxc_read(outch,&modx,0))                             //~v39bR~
    	ch=-1;                                                     //~v39bI~
                                                                   //~v39bI~
    else                                                           //~v39bI~
    if (!outch[0])                                                 //~v39bI~
    	ch=(int)(outch[1]);                                        //~v39bI~
    else                                                           //~v39bI~
    	ch=(int)(outch[0]);                                        //~v39bI~
    if (Popt & UKBDL_GETCH_ONCE)                                   //~v39bR~
		ukbdl_getch_term();                                        //~v39bI~
    return ch;                                                     //~v39bI~
}//ukbdl_getch                                                     //~v39bI~
//*********************************************************************//~v50zI~
//* getch                                                          //~v50zI~
//* ret:char ,-1:err                                               //~v50zI~
//*********************************************************************//~v50zI~
int ukbdl_getche(int Popt)                                         //~v50zI~
{                                                                  //~v50zI~
    int modx=0,ch;                                                 //~v50zI~
    char outch[16];                                                //~v50zI~
//************************                                         //~v50zI~
	if (!Sgetcheinit)                                              //~v50zI~
		ukbdl_getche_init();                                       //~v50zI~
    if (!ukbdlnxc_read(outch,&modx,0))                             //~v50zI~
    	ch=-1;                                                     //~v50zI~
    else                                                           //~v50zI~
    if (!outch[0])                                                 //~v50zI~
    	ch=(int)(outch[1]);                                        //~v50zI~
    else                                                           //~v50zI~
    	ch=(int)(outch[0]);                                        //~v50zI~
    if (Popt & UKBDL_GETCHE_ONCE)                                  //~v50zI~
		ukbdl_getche_term();                                       //~v50zI~
    return ch;                                                     //~v50zI~
}//ukbdl_getche                                                    //~v50zI~
#endif  //ARMXXE                                                   //~v6a0M~
#ifndef ARMXXE                                                     //~v6a0I~
//*********************************************************************//~v501I~
//* xterm chk                                                      //~v501I~
//* ret:termid(xterm/kterm)                                        //~v501I~
//*********************************************************************//~v501I~
int ukbdl_gettermid(void)                                          //~v501I~
{                                                                  //~v501I~
//#ifdef LNX                                                       //~v587R~
    int termsimid;                                                 //~v57wI~
//#endif                                                           //~v587R~
    char *envterm;                                                 //~v501M~
    int termid=0;                                                  //~v501I~
//************************                                         //~v501I~
#ifdef LNX                                                         //~v57wI~
    if (ukbdlnxc_getkeysym(0,1,0))  //0:msgopt,1:keycode,0:normal=plain//~v57NR~
    	termid=TERM_TTYLCONS;                                      //~v57EI~
    else                                                           //~v57EI~
    {                                                              //~v57EI~
#endif                                                             //~v587I~
    termsimid=ukbdl_gettermsim();                                  //~v57wR~
//#endif                                                           //~v587R~
    if ((envterm=getenv("TERM"))!=0)                               //~v501I~
    {                                                              //~v501I~
    	if (!strcmp(envterm,"kterm"))                              //~v501R~
        	termid=TERM_KTERM;                                     //~v501I~
        else                                                       //~v501I~
	    	if (!strcmp(envterm,"xterm"))                          //~v501R~
    	    	termid=TERM_XTERM;                                 //~v501I~
        else                                                       //~v555I~
	    	if (!strcmp(envterm,"aixterm"))                        //~v555I~
    	    	termid=TERM_AIXTERM;                               //~v555I~
        else                                                       //~v555I~
	    	if (!strcmp(envterm,"dtterm"))                         //~v555I~
    	    	termid=TERM_DTTERM;                                //~v555I~
        else                                                       //~v57XI~
	    	if (!strcmp(envterm,"vt100"))                          //~v57XI~
    	    	termid=TERM_VT100;                                 //~v57XI~
    }                                                              //~v501I~
//#ifdef LNX                                                       //~v587R~
    termid|=termsimid;                                             //~v57wI~
#ifdef LNX                                                         //~v587I~
    }//not tty console                                             //~v57EI~
#endif                                                             //~v57wI~
    return termid;                                                 //~v501I~
}//ukbdl_gettermid                                                 //~v501I~
//#ifdef LNX                                                       //~v57BR~
//*********************************************************************//~v57wI~
//* xterm chk by parent process command                            //~v57wI~
//* ret:termid(xterm/kterm)                                        //~v57wI~
//*********************************************************************//~v57wI~
int ukbdl_gettermsim(void)                                         //~v57wI~
{                                                                  //~v57wI~
	PUPSINFO pupsinfo,pupsinfo0;                                   //~v57wI~
	PUPSINFO pupsinfo1st=0;                                        //~v57BR~
    char *pc;                                                      //~v57wR~
    int  pid,termid=0;                                             //~v57zR~
    int  sw1st=0,konsw=0;                                          //~v57AR~
    int opt=0,conid=0;                                             //~v57BR~
static int Stermid=0;                                              //~v57wI~
//************************                                         //~v57wI~
	if (Stermid)			//2nd time                             //~v57wI~
    	return Stermid;                                            //~v57wI~
    Stermid=TERM_SIMCHKSW;                                         //~v57zI~
    if (!uproc_getpsinfo(0,&pupsinfo0))                            //~v57wR~
    {                                                              //~v57wR~
    	ugeterrmsg();	//clear errmsg for exec cmd                //~v57wI~
//      for (pid=getppid();;)               //parent               //~v57wR~
        for (pid=getpid();;)               //parent may not found
        {                                                          //~v57wR~
//printf("**pid=%d\n",pid);                                        //~v57ER~
//          if (!(pupsinfo=uproc_srchpsinfo(pupsinfo0,pid)))       //~v57BR~
            if (!(pupsinfo=uproc_srchpsinfo(UPSPSI_PPID,pupsinfo0,pid)))//~v57BR~
            {                                                      //~v57BI~
              if (!pupsinfo1st)	//no any parent found              //~v57BR~
                break;                                             //~v57wR~
	            pupsinfo=uproc_srchpsinfo(opt,pupsinfo0,conid);    //~v57BR~
              	if (!pupsinfo)                                     //~v57BI~
                	break;                                         //~v57BI~
//printf("same pty pid=%d,ppid=%d,pts=%d,cmd=%s\n",pupsinfo->UPSIpid,pupsinfo->UPSIppid,pupsinfo->UPSIptyno,pupsinfo->UPSIcmd);//~v57ER~
            }                                                      //~v57BI~
            pupsinfo->UPSIflag |= UPSIFPATH;	//found sw         //~v57BI~
//printf("pid=%d,ppid=%d,pts=%d,cmd=%s\n",pupsinfo->UPSIpid,pupsinfo->UPSIppid,pupsinfo->UPSIptyno,pupsinfo->UPSIcmd);//~v57ER~
			if (!sw1st)                                            //~v57AI~
            {                                                      //~v57AI~
            	sw1st=1;                                           //~v57AI~
                pupsinfo1st=pupsinfo;                              //~v57BI~
                if (pupsinfo->UPSIflag & UPSIFPTS)                 //~v57BI~
                {                                                  //~v57BM~
					opt=UPSPSI_CONPTS;                             //~v57BM~
                    conid=pupsinfo->UPSIptyno;                     //~v57BI~
                }                                                  //~v57BM~
                else                                               //~v57BM~
                if (pupsinfo->UPSIflag & UPSIFPTY)                 //~v57BI~
                {                                                  //~v57BM~
                	opt=UPSPSI_CONPTY;                             //~v57BM~
                    conid=pupsinfo->UPSIptyno;                     //~v57BI~
                }                                                  //~v57BM~
                else                                               //~v57BM~
                {                                                  //~v57BM~
                	opt=UPSPSI_CONTTY;                             //~v57BM~
                    conid=pupsinfo->UPSIttyno;                     //~v57BI~
                }                                                  //~v57BM~
                opt|=UPSPSI_CONID;                                 //~v57BM~
                if (pupsinfo->UPSIflag & UPSIFPTS)                 //~v57AI~
                    Stermid|=TERM_UNDERPTS;                        //~v57BR~
            }                                                      //~v57AI~
            if (pupsinfo->UPSIcmd)                                 //~v57wR~
            {                                                      //~v57wR~
#ifdef AIX                                                         //~v587I~
                if (pc=strstr(pupsinfo->UPSIcmd,"telnetd"),pc)     //~v587I~
                {                                                  //~v587I~
                    termid=TERM_TELNET;                            //~v587I~
                    termid|=TERM_UNDERTN; //under telnet           //~v62iI~
                    break;                                         //~v587I~
                }                                                  //~v587I~
                else                                               //~v587I~
#endif                                                             //~v587I~
#ifdef LNX                                                         //~v62iI~
                if (pc=strstr(pupsinfo->UPSIcmd,"telnetd"),pc)     //~v62iI~
                {                                                  //~v62iI~
                    termid|=TERM_UNDERTN; //under telnet           //~v62iI~
                }                                                  //~v62iI~
                else                                               //~v62iI~
#endif                                                             //~v62iI~
                if (pc=strstr(pupsinfo->UPSIcmd,"aixterm"),pc)     //~v57ER~
                {                                                  //~v57ER~
                    termid=TERM_AIXTERMSIM;                        //~v57ER~
                    break;                                         //~v57ER~
                }                                                  //~v57ER~
                else                                               //~v57ER~
                if (pc=strstr(pupsinfo->UPSIcmd,"xterm"),pc)       //~v57wR~
                {                                                  //~v57wI~
                    termid=TERM_XTERMSIM;                          //~v57zR~
                    break;                                         //~v57wI~
                }                                                  //~v57wI~
                else                                               //~v57wR~
                if (pc=strstr(pupsinfo->UPSIcmd,"kterm"),pc)       //~v57wR~
                {                                                  //~v57wI~
                    termid=TERM_KTERMSIM;                          //~v57wR~
                    break;                                         //~v57wI~
                }                                                  //~v57wI~
                else                                               //~v57AI~
                if (pc=strstr(pupsinfo->UPSIcmd,"gnome-terminal"),pc)//~v57zI~
                {                                                  //~v57zI~
                    termid=TERM_GTERMSIM;                          //~v57zI~
                    break;                                         //~v57zI~
                }                                                  //~v57zI~
                else                                               //~v57AI~
                if (pc=strstr(pupsinfo->UPSIcmd,"dtterm"),pc)      //~v57ER~
                {                                                  //~v57ER~
                    termid=TERM_DTTERMSIM;                         //~v57ER~
                    break;                                         //~v57ER~
                }                                                  //~v57ER~
                else                                               //~v57ER~
                if (pc=strstr(pupsinfo->UPSIcmd,"nxterm"),pc)      //~v5g9I~
                {                                                  //~v5g9I~
                    termid=TERM_NXTERMSIM;                         //~v5g9I~
                    break;                                         //~v5g9I~
                }                                                  //~v5g9I~
                else                                               //~v5g9I~
                if (pc=strstr(pupsinfo->UPSIcmd,"color-xterm"),pc) //~v5g9I~
                {                                                  //~v5g9I~
                    termid=TERM_COLORXSIM;                         //~v5g9I~
                    break;                                         //~v5g9I~
                }                                                  //~v5g9I~
                else                                               //~v5g9I~
                if (pc=strstr(pupsinfo->UPSIcmd,"rxvt"),pc)        //~v5g9I~
                {                                                  //~v5g9I~
                    termid=TERM_RXVTSIM;                           //~v5g9I~
                    break;                                         //~v5g9I~
                }                                                  //~v5g9I~
                else                                               //~v5g9I~
                if (pc=strstr(pupsinfo->UPSIcmd,"konsole"),pc)     //~v5kkR~
                {                                                  //~v5kkI~
                    termid=TERM_KONSOLE;                           //~v5kkI~
                    break;                                         //~v5kkI~
                }                                                  //~v5kkI~
                else                                               //~v5kkI~
                if (pc=strstr(pupsinfo->UPSIcmd,"xfce4-terminal"),pc)//~v6s2I~
                {                                                  //~v6s2I~
                    termid=TERM_XFCE4TERM;                         //~v6s2I~
                    break;                                         //~v6s2I~
                }                                                  //~v6s2I~
                else                                               //~v6s2I~
                if (pc=strstr(pupsinfo->UPSIcmd,"kon"),            //~v57BR~
                    (pc && (*(pc+3)==' '||!*(pc+3))))              //~v57BI~
                    konsw=1;                                       //~v57AI~
            }                                                      //~v57wR~
            pid=pupsinfo->UPSIppid;     //parent pid               //~v57wR~
            if (pid==1)                                            //~v57wR~
                break;                                             //~v57wR~
        }                                                          //~v57wR~
        uproc_freepsinfo(pupsinfo0);                               //~v57wR~
    }//getpsinfo success                                           //~v57wR~
    if (!termid)	//no terminal sim found                        //~v57BI~
    	if (getenv("DISPLAY"))                                     //~v57BI~
        	termid=TERM_OTHERSIM;                                  //~v57BI~
    Stermid|=termid;                                               //~v57zI~
    if (konsw && (Stermid & TERM_UNDERPTS)==0)                     //~v57BR~
    	Stermid|=TERM_UNDERKON;                                    //~v57AR~
//printf("teimid=%x\n",Stermid);                                   //~v57ER~
    return Stermid;                                                //~v57wI~
}//ukbdl_gettermsim                                                //~v57wI~
//#endif                                                           //~v57BR~
//*********************************************************************//~v57NI~
//* edit esc string                                                //~v57NI~
//*********************************************************************//~v57NI~
void ukbdl_editstring(char *Pstr,char *Poutstr)                    //~v57NI~
{                                                                  //~v57NI~
	char *pci,*pco;                                                //~v57NI~
    int ii;                                                        //~v57NI~
//************************                                         //~v57NI~
    if (*Pstr==0x1b)                                               //~v57NI~
        sprintf(Poutstr,"^[%s",Pstr+1);                            //~v57NI~
    else                                                           //~v57NI~
    {                                                              //~v57NI~
        pci=Pstr;                                                  //~v57NI~
        pco=Poutstr;                                               //~v57NI~
//      for (ii=strlen(Pstr);ii>0;ii--,pci++)                      //~v57NR~//~v6B2R~
        for (ii=(int)strlen(Pstr);ii>0;ii--,pci++)                 //~v6B2I~
        	pco+=sprintf(pco,"0x%02X",*pci);                       //~v57NI~
    }                                                              //~v57NI~
}//ukbdl_editstring                                                //~v57NI~
//**************************************************               //~v5mvI~
//*ukbdsetstatus                                                   //~v5mvI~
//*set kbd status(binary mode,shift report etc)                    //~v5mvI~
//*parm1:KBDINFO addr                                              //~v5mvI~
//*rc   :0 or 504(ERROR_KBD_EXTENDED_SG)                           //~v5mvI~
//**************************************************               //~v5mvI~
int ukbdsetstatus(PKBDINFO Ppkbdinfo)                              //~v5mvI~
{                                                                  //~v5mvI~
	int rc=0,old_flag;                                             //~v5mvR~
//***************************************                          //~v5mvI~
#ifdef AIX                                                         //~v5mvI~
	return rc;                                                     //~v5mvI~
#endif                                                             //~v5mvI~
	old_flag=Gukbdl_flag;                                          //~v5mvR~
    if (Ppkbdinfo->fsMask & KEYBOARD_SHIFT_REPORT) //RCTL use      //~v5mvR~
		Gukbdl_flag |= GUKBDL_RCTLUSE;                             //~v5mvI~
    else                                                           //~v5mvI~
		Gukbdl_flag &= ~GUKBDL_RCTLUSE;                            //~v5mvI~
    if (Gukbdl_flag!=old_flag)                                     //~v5mvI~
    	rc=ukbdlnxc_setrctl(((Gukbdl_flag & GUKBDL_RCTLUSE)!=0)|UKBDLNXC_SRCO_SET);//~v5mvR~
	return rc;                                                     //~v5mvI~
}//ukbdsetstatus                                                   //~v5mvI~
#endif //ARMXXE                                                    //~v6a0M~
//**************************************************               //~v5n8R~
//*ukbd_localeinit                                                 //~v5n8R~
//*parm :none                                                      //~v5n8R~
//*rc   :none                                                      //~v5n8R~
//**************************************************               //~v5n8R~
int ukbdl_wcinit(int Popt,ULONG Pcodepage,UCHAR *Pcharset)         //~v5n8R~
{                                                                  //~v5n8R~
//***************************************                          //~v5n8R~
    if (Pcodepage)                                                 //~v5n8I~
		Sphiconv=(iconv_t *)Pcodepage;                             //~v5n8R~
    Swcstat|=Popt;                                                 //~v5n8R~
//  if (Swcstat & UDCWCIO_KBDNOUTF8)                               //~v5n8R~//~v720R~
//      Swcstat&=~UDCWCIO_KBDUTF8;   //return mbstring             //~v5n8R~//~v720R~
//  else                                                           //~v5n8I~//~v720R~
    {                                                              //~v620R~
#ifdef UTF8SUPPH                                                   //~v62iI~
      if (Swcstat & UDCWCIO_KBDFORCEUTF8)                          //~v620R~
	    Swcstat|=UDCWCIO_KBDUTF8;   //return mbstring              //~v620R~
      else                                                         //~v620R~
#endif // UTF8SUPPH                                                //~v62iI~
      {                                                            //~v620R~
    	if (UDBCSCHK_ISUTF8())                                     //~v5n8I~
		    Swcstat|=UDCWCIO_KBDUTF8;   //return mbstring          //~v5n8I~
        else                                                       //~v5n8I~
		    Swcstat&=~UDCWCIO_KBDUTF8;   //return mbstring         //~v5n8I~
      }                                                            //~v620R~
    }                                                              //~v620R~
#ifdef AAA                                                         //+v721R~
#ifndef XXE                                                        //~v720I~
    if (Swcstat & UDCWCIO_KBDNOUTF8)                               //~v720I~
    {                                                              //~v720I~
		if (Swcstat & UDCWCIO_KBDUTF8)   //utf8 env                //~v720I~
        {                                                          //~v720I~
//  		Swcstat&=~UDCWCIO_KBDUTF8;   //return mbstring         //~v720R~
			Gudbcschk_flag|=UDBCSCHK_KBDNOUTF8; //     0x04000000  //-Nm option on UTF8 env//~v720R~
        }                                                          //~v720I~
        else                                                       //~v720I~
        {                                                          //~v720I~
	    	uerrexit("-Nm option s invalid for NOT UTF8 environment",0);//~v720R~
        }                                                          //~v720I~
    }                                                              //~v720I~
#endif  //!XXE                                                     //~v720I~
#endif  //AAA                                                      //+v721R~
    UTRACEP("kbdl wcinit stat=%x\n",Swcstat);                      //~v5n8R~
#ifdef XXE                                                         //~v5n8I~
	xxe_kbdwcinit(0,Swcstat,(ULONG)Sphiconv,Pcharset);		//notify to xxe//~v5n8R~
#endif                                                             //~v5n8I~
    return 0;                                                      //~v5n8R~
}//ukbdl_wcinit                                                    //~v5n8R~
#ifndef ARMXXE                                                     //~v6a0R~
//**************************************************               //~v5n8I~
//*ukbd utf8 char read                                             //~v5n8I~
//*return pending byte ctr                                         //~v5n8I~
//**************************************************               //~v5n8I~
int ukbdl_readutf8(int Pctr,KBDKEYINFO *Pkeyinfo)                  //~v5n8R~
{                                                                  //~v5n8I~
static KBDKEYINFO Skeyinfo;                                        //~v5n8I~
static UCHAR Smbstr[MAX_MBCSLEN];                                  //~v5n8I~
static int Smblen;                                                 //~v5n8I~
	UCHAR utf8char[UTF8_MAXCHARSZMAX];                             //~v5n8I~
	int len,offs,shiftstatus,chklen,errsw,ii;                      //~v5n8R~
//  ULONG ucs;                                                     //~v5n8I~//~v691R~
    UWUCS ucs;                                                     //~v691I~
#ifdef UTF8UCS4                                                    //~v65cI~
	int opt;                                                       //~v65cI~
#endif                                                             //~v65cI~
	int wwuc;                                                      //~v65dI~
//***************************************                          //~v5n8I~
	if (Pctr)   //read 2nd                                         //~v5n8I~
    {                                                              //~v5n8I~
    	offs=Pctr;                                                 //~v5n8I~
        memcpy(Pkeyinfo,&Skeyinfo,sizeof(KBDKEYINFO));             //~v5n8R~
#ifdef UTF8SUPPH                                                   //~v62iI~
		Pkeyinfo->bNlsShift=KBDNLS_F2L_DBCS2ND;                    //~v5n8R~
#endif                                                             //~v62iI~
		Pkeyinfo->chChar=Smbstr[offs++];                           //~v5n8R~
        if (offs>=Smblen)                                          //~v5n8I~
        {                                                          //~v5n8I~
        	Smblen=0;                                              //~v5n8I~
        	return 0;                                              //~v5n8I~
        }                                                          //~v5n8I~
        return offs;	//next raed offset                         //~v5n8I~
    }                                                              //~v5n8I~
    for (errsw=1;;)                                                //~v5n8I~
    {                                                              //~v5n8I~
		len=UTF8CHARLEN(Pkeyinfo->chChar);                         //~v5n8R~
    	if (!len)	//err utf8                                     //~v5n8I~
    		break;                                                 //~v5n8I~
    	for (ii=1;ii<len;ii++)                                     //~v5n8R~
    	{                                                          //~v5n8I~
                                                                   //~v62HI~
#ifdef UTF8SUPPH                                                   //~v62HI~
    		if (!ukbdlnxc_read(utf8char+ii,&shiftstatus,UKBDLNXCO_NEXT))//~v62HM~
#else                                                              //~v62HI~
    		if (!ukbdlnxc_read(utf8char+ii,&shiftstatus,0))        //~v5n8R~//~v62HR~
#endif                                                             //~v62HI~
        		break;                                             //~v5n8I~
    	}                                                          //~v5n8I~
   		if (ii!=len)	//whole read                               //~v5n8I~
    		break;                                                 //~v5n8I~
    	utf8char[0]=Pkeyinfo->chChar;                              //~v5n8R~
UTRACED("ukbdl utf8str",utf8char,sizeof(utf8char));                //~v5n8I~
#ifdef UTF8UCS4                                                    //~v65cI~
		opt=UCVUCS_UCS4; //accept ucs4                             //~v65cI~
//  	if (uccvutf2ucs(opt,utf8char,len,&ucs,&chklen))            //~v65cI~//~v6B2R~
    	if (uccvutf2ucs((ULONG)opt,utf8char,len,&ucs,&chklen))     //~v6B2I~
#else                                                              //~v65cI~
		if (uccvutf2ucs(0,utf8char,len,&ucs,&chklen))              //~v5n8I~
#endif                                                             //~v65cI~
    		break;                                                 //~v5n8I~
UTRACEP("ukbdl ucs=%04x,len=%d,chklen=%d\n",ucs,len,chklen);       //~v5n8I~
	  if (UDBCSCHK_IS_LOCALICU())                                  //~v6f3I~
      {                                                            //~v6f3I~
  		opt=UCVEXTO_SETSUBCHRC;                                    //~v6f3I~//~v6f7R~
//		opt=0;                                                     //~v6f3I~//~v6f7R~
		if (ucvext_icuucs2mb1(opt,(ULONG*)(ULONG)(Sphiconv),ucs,Smbstr,&Smblen))//WUCS is ucs4 on Linux//~v6f3R~//~v6f7R~
        {                                                          //~v6f3I~
            errsw=2;    //trans err                                //~v6f3I~
    		break;                                                 //~v6f3I~
        }                                                          //~v6f3I~
      }                                                            //~v6f3I~
      else                                                         //~v6f3I~
      {                                                            //~v6f3I~
		if (ucvext_iconvucs2local1(0,(ULONG)Sphiconv,(WUCS)ucs,Smbstr,&Smblen)>1)//~v5n8R~
        {                                                          //~v65dI~
            errsw=2;    //trans err                                //~v65dI~
    		break;                                                 //~v5n8I~
        }                                                          //~v65dI~
      }                                                            //~v6f3I~
UTRACED("ukbdl mbstr",Smbstr,Smblen);                              //~v620R~
        errsw=0;                                                   //~v5n8I~
        break;                                                     //~v5n8I~
    }                                                              //~v5n8I~
    if (errsw==2)                                                  //~v65dI~
    {                                                              //~v65dI~
	    Smbstr[0]=CHAR_ASCII_ERR;	//set to chChar later          //~v65dI~
        Smblen=1;                                                  //~v65cI~
//      wwuc=utfwcwidth(0,ucs,0/*flag*/);                          //~v65cI~//~v6BkR~
        wwuc=utfwcwidth(0,(ULONG)ucs,0/*flag*/);                   //~v6BkI~
        if (wwuc<0||wwuc>1)	//unprintable or dbcs                  //~v65cI~
        {                                                          //~v65cI~
	    	Smbstr[1]=CHAR_ASCII_ERR;	//set to chChar later      //~v65cI~
            Smblen++;                                              //~v65cI~
        }                                                          //~v65cI~
    }                                                              //~v65dI~
    else                                                           //~v65dI~
    if (errsw)                                                     //~v5n8I~
    {                                                              //~v5n8I~
		Pkeyinfo->chChar=CHAR_ASCII_ERR;                           //~v5n8R~
	    Smblen=0;                                                  //~v5n8I~
        return 0;                                                  //~v5n8I~
    }                                                              //~v5n8I~
	if (Swcstat & UDCWCIO_KBDUNICODE)   //return unicode (for xekbchk)//~v5n8I~
    {                                                              //~v5n8I~
		Pkeyinfo->bNlsShift=KBDNLS_UNICODE;                        //~v5n8R~
//  	Pkeyinfo->chScan=ucs & 0xff;                               //~v5n8R~//~v6BkR~
    	Pkeyinfo->chScan=(UCHAR)(ucs & 0xff);                      //~v6BkI~
//  	Pkeyinfo->chChar=ucs>>8;                                   //~v5n8R~//~v6B2R~
    	Pkeyinfo->chChar=(UCHAR)(ucs>>8);                          //~v6B2I~
#ifdef UTF8UCS4                                                    //~v65dI~//~v65cI~
		UTF_SETUCS4TOBESTR(ucs,Pkeyinfo->mbstr);                   //~v65dI~//~v65cI~
#endif                                                             //~v65dI~//~v65cI~
        return 0;                                                  //~v5n8I~
    }                                                              //~v5n8I~
    Pkeyinfo->chChar=Smbstr[0];                                    //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v5n8I~
//  UmemcpyZ(Pkeyinfo->u8str,utf8char,chklen);                     //~v5n8I~//~v6B2R~
    UmemcpyZ(Pkeyinfo->u8str,utf8char,(size_t)chklen);             //~v6B2I~
#endif                                                             //~v5n8I~
    if (errsw==2)                                                  //~v65dI~
    {                                                              //~v65dI~
//      UmemcpyZ(Pkeyinfo->mbstr,Smbstr,Smblen);                   //~v65cR~//~v6B2R~
        UmemcpyZ(Pkeyinfo->mbstr,Smbstr,(size_t)Smblen);           //~v6B2I~
        if (Smblen==1)                                             //~v65cI~
			Pkeyinfo->bNlsShift=KBDNLS_F2L_ERR|KBDNLS_F2L_SBCS;    //~v65cR~
        else                                                       //~v65cI~
			Pkeyinfo->bNlsShift=KBDNLS_F2L_ERR|KBDNLS_F2L_DBCS1ST|KBDNLS_F2L_DBCS2ND;//~v65cI~
UTRACEP("ukbdl u2lerr ucs=%x,width=%d\n",ucs,Smblen);                                //~v65dI~//~v65cR~
        Smblen=0;                                                  //~v65dI~//~v65cM~
        return 0;                                                  //~v65dI~
    }                                                              //~v65dI~
    if (Smblen==1)                                                 //~v5n8I~
    {                                                              //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v62iI~
		Pkeyinfo->bNlsShift=KBDNLS_F2L_SBCS;                       //~v5n8I~
#endif                                                             //~v62iI~
        Smblen=0;                                                  //~v5n8I~
        return 0;                                                  //~v5n8I~
    }                                                              //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v62iI~
	Pkeyinfo->bNlsShift=KBDNLS_F2L_DBCS1ST;                        //~v5n8R~
    if (Swcstat & UDCWCIO_DBCSREAD                                 //~v62UR~
    &&  Smblen>=2 && Smblen<=4)                                    //~v62UR~
    {                                                              //~v62UR~
        if (Smblen==2)                                             //~v62UR~
            Pkeyinfo->bNlsShift|=KBDNLS_F2L_DBCS2ND;               //~v62UR~
        else                                                       //~v62UR~
        if (Smblen==3)                                             //~v62UR~
            Pkeyinfo->bNlsShift|=KBDNLS_SS3;                       //~v62UR~
        else                                                       //~v62UR~
        if (Smblen==4)                                             //~v62UR~
            Pkeyinfo->bNlsShift|=KBDNLS_GB4;                       //~v62UR~
        strncpy(Pkeyinfo->mbstr,Smbstr,sizeof(Pkeyinfo->mbstr));   //~v62UR~
        Smblen=0;                                                  //~v62UR~
        return 0;                                                  //~v62UR~
    }                                                              //~v62UR~
    memcpy(&Skeyinfo,Pkeyinfo,sizeof(KBDKEYINFO));                 //~v620I~
#endif                                                             //~v62iI~
//  return 1;	//next read 2nd byte                               //~v62UR~
    return Smblen-1;	//next read 2nd byte                       //~v62UR~
}//ukbdl_readutf8                                                  //~v620R~
#ifdef UTF8SUPPH                                                   //~v62UR~
//**************************************************               //~v62UR~
//*ukbd dbcs char read                                             //~v62UR~
//*return pending byte ctr                                         //~v62UR~
//**************************************************               //~v62UR~
int ukbdl_readdbcs(int Pctr,KBDKEYINFO *Pkeyinfo)                  //~v62UR~
{                                                                  //~v62UR~
	UCHAR readwk[MAX_MBCSLENLC];                                   //~v62UR~
	UCHAR ch,ch2;;                                                 //~v62UR~
	int len,shiftstatus,errsw;                                     //~v62UR~
//***************************************                          //~v62UR~
	ch=Pkeyinfo->chChar;                                           //~v62UR~
    readwk[0]=ch;                                                  //~v62UR~
    for (errsw=1;;)                                                //~v62UR~
    {                                                              //~v62UR~
    	if (!ukbdlnxc_read(readwk+1,&shiftstatus,UKBDLNXCO_NEXT))  //~v62UR~
        	break;                                                 //~v62UR~
        ch2=*readwk;                                               //~v62UR~
		if (ISSS3(ch)	//SS3 at EUC env                           //~v62UR~
        && UDBCSCHK_ISDBCS1ST(ch2)                                 //~v62UR~
        )                                                          //~v62UR~
        {                                                          //~v62UR~
	    	if (!ukbdlnxc_read(readwk+2,&shiftstatus,UKBDLNXCO_NEXT))//~v62UR~
	        	break;                                             //~v62UR~
			if (!ISSS3STR(readwk,3))//SS3 at EUC env               //~v62UR~
	        	break;                                             //~v62UR~
        	len=UDBCSCHK_SS3SZ;                                    //~v62UR~
			Pkeyinfo->bNlsShift=(KBDNLS_SS3|KBDNLS_DBCS);          //~v62UR~
        }                                                          //~v62UR~
        else                                                       //~v62UR~
		if (UDBCSCHK_ISGB41STHALF(readwk,2)) //at gb18030 env      //~v62UR~
        {                                                          //~v62UR~
	    	if (!ukbdlnxc_read(readwk+2,&shiftstatus,UKBDLNXCO_NEXT))//~v62UR~
	        	break;                                             //~v62UR~
	    	if (!ukbdlnxc_read(readwk+3,&shiftstatus,UKBDLNXCO_NEXT))//~v62UR~
	        	break;                                             //~v62UR~
			if (!UDBCSCHK_ISGB4STR(readwk,4))                      //~v62UR~
	        	break;                                             //~v62UR~
	        len=UDBCSCHK_GB4SZ;                                    //~v62UR~
			Pkeyinfo->bNlsShift=(KBDNLS_GB4|KBDNLS_DBCS);          //~v62UR~
        }                                                          //~v62UR~
        else                                                       //~v62UR~
        {                                                          //~v62UR~
		    len=UDBCSCHK_DBCSSZ;                                   //~v62UR~
			Pkeyinfo->bNlsShift=KBDNLS_DBCS;                       //~v62UR~
        }                                                          //~v62UR~
UTRACED("ukbdl dbcsstr",readwk,len);                               //~v62UR~
        errsw=0;                                                   //~v62UR~
        break;                                                     //~v62UR~
    }                                                              //~v62UR~
    if (errsw)                                                     //~v62UR~
    {                                                              //~v62UR~
		Pkeyinfo->chChar=CHAR_ASCII_ERR;                           //~v62UR~
        return 0;                                                  //~v62UR~
    }                                                              //~v62UR~
    Pkeyinfo->chChar=readwk[0];                                    //~v62UR~
    memcpy(Pkeyinfo->mbstr,readwk,(UINT)len);                      //~v62UR~
    return len;                                                    //~v62UR~
}//ukbdl_readdbcs                                                  //~v62UR~
#endif	//UTF8SUPPH                                                //~v62UR~
//#ifdef AAA                                                         //~v5n8I~//~v6f3R~
////**************************************************               //~v5n8R~//~v6f3R~
////*ukbd unicode to multibyte                                       //~v5n8R~//~v6f3R~
////**************************************************               //~v5n8R~//~v6f3R~
//int ukbd_u2m(int Popt,USHORT Pucs,UCHAR *Ppmbs,int *Ppoutlen)      //~v5n8R~//~v6f3R~
//{                                                                  //~v5n8R~//~v6f3R~
//    int mbslen,rc;                                                 //~v5n8R~//~v6f3R~
////***************************************                          //~v5n8R~//~v6f3R~
//    rc=ucvext_iconvucs2local1(0,(ULONG)Sphiconv,Pucs,Ppmbs,&mbslen);//~v5n8R~//~v6f3R~
//    if (rc>1)                                                      //~v5n8R~//~v6f3R~
//    {                                                              //~v5n8R~//~v6f3R~
//        mbslen=1;                                                  //~v5n8R~//~v6f3R~
//        *Ppmbs=CHAR_ASCII_ERR;                                     //~v5n8R~//~v6f3R~
//    }                                                              //~v5n8R~//~v6f3R~
//    *Ppoutlen=mbslen;                                              //~v5n8R~//~v6f3R~
//    return rc;                                                     //~v5n8R~//~v6f3R~
//}//ukbd_u2m                                                        //~v5n8R~//~v6f3R~
//#endif                                                             //~v5n8I~//~v6f3R~
#endif //ARMXXE                                                    //~v6a0I~
//*****************************************************************//~v6BeR~
//*utf-->mb for kbd simutf8                                        //~v6BeR~
//*****************************************************************//~v6BeR~
int ukbd_simutf8_f2l(int Popt,char *Putf8,int Plen,char *Ppout,int Pbuffsz,int *Ppoutlen)//~v6BeR~
{                                                                  //~v6BeR~
    UCHAR mbstr[MAX_MBCSLEN+1];                                    //~v6BeR~
    int mbslen=1;                                                  //~v6BeR~
    int rc,chklen;                                                 //~v6BeR~
    UWUCS ucs;                                                     //~v6BeR~
    int opt;                                                       //~v6BeR~
    int wwuc;                                                      //~v6BeR~
    char errrep;                                                   //~v6BeR~
//***************************************                          //~v6BeR~
//  errrep=(char)Popt & UKSF2LO_ERRREPCH;                          //~v6BkR~
    errrep=(char)(Popt & UKSF2LO_ERRREPCH);                        //~v6BkI~
    for (rc=1;;)                                                   //~v6BeR~
    {                                                              //~v6BeR~
        opt=UCVUCS_UCS4; //accept ucs4                             //~v6BeR~
        if (uccvutf2ucs((ULONG)opt,Putf8,Plen,&ucs,&chklen))       //~v6BeR~
            break;                                                 //~v6BeR~
        if (UDBCSCHK_IS_LOCALICU())                                //~v6BeR~
        {                                                          //~v6BeR~
            opt=UCVEXTO_SETSUBCHRC;                                //~v6BeR~
            if (ucvext_icuucs2mb1(opt,(ULONG*)(ULONG)(Sphiconv),ucs,mbstr,&mbslen))//WUCS is ucs4 on Linux//~v6BeR~
            {                                                      //~v6BeR~
                rc=2;    //trans err                               //~v6BeR~
                break;                                             //~v6BeR~
            }                                                      //~v6BeR~
        }                                                          //~v6BeR~
        else                                                       //~v6BeR~
        {                                                          //~v6BeR~
            if (ucvext_iconvucs2local1(0,(ULONG)Sphiconv,(WUCS)ucs,mbstr,&mbslen)>1)//~v6BeR~
            {                                                      //~v6BeR~
                rc=2;    //trans err                               //~v6BeR~
                break;                                             //~v6BeR~
            }                                                      //~v6BeR~
        }                                                          //~v6BeR~
        rc=0;                                                      //~v6BeR~
        mbslen=min(mbslen,Pbuffsz);                                //~v6BeI~
        memcpy(Ppout,mbstr,(size_t)mbslen);                        //~v6BeR~
        break;                                                     //~v6BeR~
    }                                                              //~v6BeR~
    if (rc==2)                                                     //~v6BeR~
    {                                                              //~v6BeR~
        *Ppout=errrep;   //?                                       //~v6BeR~
        mbslen=1;                                                  //~v6BeR~
//      wwuc=utfwcwidth(0,ucs,0/*flag*/);                          //~v6BeR~//~v6BkR~
        wwuc=utfwcwidth(0,(ULONG)ucs,0/*flag*/);                   //~v6BkI~
        if (wwuc<0||wwuc>1) //unprintable or dbcs                  //~v6BeR~
        {                                                          //~v6BeR~
            *(Ppout+1)=errrep;   //?                               //~v6BeR~
            mbslen++;                                              //~v6BeR~
        }                                                          //~v6BeR~
    }                                                              //~v6BeR~
    else                                                           //~v6BeR~
    if (rc)                                                        //~v6BeR~
    {                                                              //~v6BeR~
        *Ppout=errrep;   //?                                       //~v6BeR~
        mbslen=1;                                                  //~v6BeR~
    }                                                              //~v6BeR~
    *Ppoutlen=mbslen;                                              //~v6BeR~
    UTRACED("out mbs",Ppout,mbslen);                               //~v6BeR~
    return rc;  //next read 2nd byte                               //~v6BeR~
}//ukbd_simutf8_f2l                                                //~v6BeR~
