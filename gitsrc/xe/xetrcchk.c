//CID://+vanfR~:               update#=      3                     //~vanfR~
// ******************************************************************
// * xetrcchk.c                                                    //~v1.0R~
// *  translate keyin value on xe.trc                              //~v1.0R~
// *  parm1 : input file spec(xe trace file)                       //~v1.0R~
// **********************************************/
//vanf:131209 alias cmd;support addtional parm;%*,%^ for filename,%@ all remaining//~vanfI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//v69Y:060722 add A+"=" to virtical line for 101 keyboard (scancode=13, "^" on japanese kbd)//~v69yI~
// 990710 v1.0 created                                             //~v1.0R~
// **********************************************/                 //~v1.0R~
#define VER    "V1.1"        //version                             //~v69yR~
// *******************************************************************
// *******************************************************************//~v1.1I~

#include <time.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>                                                 //~v1.0I~
                                                                //~5C24I~
#ifdef DOS                                                         //~v1.0I~
	#include <dos.h>                                               //~v1.0I~
#else                                                              //~v1.0I~
	#ifdef W32                                                     //~v1.0I~
//  	#include <windows.h>                                       //~v1.0I~
	#else                                                          //~v1.0I~
	#define INCL_BASE                                              //~v1.0I~
	#include <os2.h>                                               //~v1.0I~
	#endif                                                         //~v1.0I~
#endif                                                             //~v1.0I~
//***********************************                              //~v1.0I~
#include <ulib.h>                                                  //~v1.0R~
#include <ukbd.h>                                                  //~v1.0I~
#include <uedit.h>                                                 //~v1.0I~
#include <uque.h>                                                  //+vanfI~
//********************************************************************
#include "xescr.h"                                                 //~vanfI~
#include "xekbd.h"                                                 //~v1.0I~
//********************************************************************//~v1.0I~

#define PGMID  "XETRCCHK"     //program id                         //~v1.0R~
//*******************************************************************
void putmsg(int exitcode,UCHAR *patern,...);                       //~v1.0I~
//*******************************************************************
//************************************************                 //~v1.0I~
//** define available key conbination for function key             //~v1.0I~
//************************************************                 //~v1.0I~
#define KTDEF(key) 	{KEY_##key,KEY_S_##key,KEY_A_##key,KEY_C_##key}//~v1.0I~
#define KTDEFDUP(key,flag) 	{KEY_##key,KEY_S_##key,KEY_A_##key,KEY_C_##key},{0,0,0,flag}//~v1.0I~
#define KTDEFDUPS(key,flags,flag) 	{KEY_##key,KEY_S_##key,KEY_A_##key,KEY_C_##key},{0,flags,0,flag}//~v1.0I~
#define KTCHAR(key) {0,0,KEY_A_##key,KEY_C_##key},{0,0,KTCHARKEY,KTCHARKEY}//~v1.0I~
#define KTCHARDUP(key,flag1,flag2) {0,0,KEY_A_##key,KEY_C_##key},{0,0,KTCHARKEY|flag1,KTCHARKEY|flag2}//~v69yI~
static  KEYTBL Sfkeytbl[]=                                         //~v1.0I~
{//  key-name(Eng),keyname(Jap),4 key value                        //~v1.0I~
	{"Esc"        ,"Esc"       ,KTDEF(ESC),  {0,KTSHIFTDUP}},      //~v1.0I~
	{"Tab"        ,"タブ"      ,KTDEF(TAB)   },                    //~v1.0I~
	{"Backspace"  ,"後退"      ,KTDEF(BS),   {0,KTSHIFTDUP}},      //~v1.0I~
	{"Enter"      ,"改行"      ,KTDEF(ENTER),{0,KTSHIFTDUP}},      //~v1.0I~
	{"Insert"     ,"挿入"      ,KTDEFDUPS(INS,  KTSHIFTDUP,KTCTLDUP1)},//~v1.0I~
	{"Delete"     ,"削除"      ,KTDEFDUPS(DEL,  KTSHIFTDUP,KTCTLDUP1)},//~v1.0I~
	{"Home"       ,"Home"      ,KTDEFDUPS(HOME, KTSHIFTDUP,KTCTLDUP1)},//~v1.0I~
	{"End"        ,"End"       ,KTDEFDUPS(END,  KTSHIFTDUP,KTCTLDUP1)},//~v1.0I~
	{"Page-up"    ,"前頁"    ,KTDEFDUPS(PGUP, KTSHIFTDUP,KTCTLDUP1)},//~v1.0R~
	{"Page-down"  ,"次頁"    ,KTDEFDUPS(PGDN, KTSHIFTDUP,KTCTLDUP1)},//~v1.0R~
	{"Left-arrow" ,"左"      ,KTDEFDUPS(LEFT, KTSHIFTDUP,KTCTLDUP1)},//~v1.0R~
	{"Right-arrow","右"      ,KTDEFDUPS(RIGHT,KTSHIFTDUP,KTCTLDUP1)},//~v1.0R~
	{"Up-arrow"   ,"上"      ,KTDEFDUPS(UP,   KTSHIFTDUP,KTCTLDUP1)},//~v1.0R~
	{"Down-arrow" ,"下"      ,KTDEFDUPS(DOWN, KTSHIFTDUP,KTCTLDUP1)},//~v1.0R~
	{"F1"         ,"F1"        ,KTDEF(F1)    },                    //~v1.0I~
	{"F2"         ,"F2"        ,KTDEF(F2)    },                    //~v1.0I~
	{"F3"         ,"F3"        ,KTDEF(F3)    },                    //~v1.0I~
	{"F4"         ,"F4"        ,KTDEF(F4)    },                    //~v1.0I~
	{"F5"         ,"F5"        ,KTDEF(F5)    },                    //~v1.0I~
	{"F6"         ,"F6"        ,KTDEF(F6)    },                    //~v1.0I~
	{"F7"         ,"F7"        ,KTDEF(F7)    },                    //~v1.0I~
	{"F8"         ,"F8"        ,KTDEF(F8)    },                    //~v1.0I~
	{"F9"         ,"F9"        ,KTDEF(F9)    },                    //~v1.0I~
	{"F10"        ,"F10"       ,KTDEF(F10)   },                    //~v1.0I~
	{"F11"        ,"F11"       ,KTDEF(F11)   },                    //~v1.0I~
	{"F12"        ,"F12"       ,KTDEF(F12)   },                    //~v1.0I~
//*for alt+char key                                                //~v1.0I~
//*top line                                                        //~v1.0I~
	{"1"    ,"1"   ,KTCHAR(1)},                                    //~v1.0I~
	{"2"    ,"2"   ,KTCHAR(2)},                                    //~v1.0I~
	{"3"    ,"3"   ,KTCHAR(3)},                                    //~v1.0I~
	{"4"    ,"4"   ,KTCHAR(4)},                                    //~v1.0I~
	{"5"    ,"5"   ,KTCHAR(5)},                                    //~v1.0I~
	{"6"    ,"6"   ,KTCHAR(6)},                                    //~v1.0I~
	{"7"    ,"7"   ,KTCHAR(7)},                                    //~v1.0I~
	{"8"    ,"8"   ,KTCHAR(8)},                                    //~v1.0I~
	{"9"    ,"9"   ,KTCHAR(9)},                                    //~v1.0I~
	{"0"    ,"0"   ,KTCHAR(0)},                                    //~v1.0I~
	{"-"    ,"-"   ,KTCHAR(MINUS)},                                //~v1.0I~
//  {"^"    ,"^"   ,KTCHAR(HAT)},                                  //~v69yR~
    {"^"    ,"^"   ,KTCHARDUP(HAT,KTALTDUP1,0)},                   //~v69yI~
    {"="    ,"="   ,KTCHARDUP(EQUAL,KTALTDUP1,0)},  //0n 101,same as HAT on Japanese kbd//~v69yI~
	{"\\"    ,"\\" ,KTCHAR(YEN)},                                  //~v1.0I~
//*2nd line                                                        //~v1.0I~
	{"q"    ,"q"   ,KTCHAR(q)},                                    //~v1.0I~
	{"w"    ,"w"   ,KTCHAR(w)},                                    //~v1.0I~
	{"e"    ,"e"   ,KTCHAR(e)},                                    //~v1.0I~
	{"r"    ,"r"   ,KTCHAR(r)},                                    //~v1.0I~
	{"t"    ,"t"   ,KTCHAR(t)},                                    //~v1.0I~
	{"y"    ,"y"   ,KTCHAR(y)},                                    //~v1.0I~
	{"u"    ,"u"   ,KTCHAR(u)},                                    //~v1.0I~
	{"i"    ,"i"   ,KTCHAR(i)},                                    //~v1.0I~
	{"o"    ,"o"   ,KTCHAR(o)},                                    //~v1.0I~
	{"p"    ,"p"   ,KTCHAR(p)},                                    //~v1.0I~
	{"@"    ,"@"   ,KTCHAR(ACCNT)},                                //~v1.0I~
	{"["    ,"["   ,KTCHAR(LMP)},//left middle parenthesis         //~v1.0I~
                                                                   //~v1.0I~
//*3rd line                                                        //~v1.0I~
	{"a"    ,"a"   ,KTCHAR(a)},                                    //~v1.0I~
	{"s"    ,"s"   ,KTCHAR(s)},                                    //~v1.0I~
	{"d"    ,"d"   ,KTCHAR(d)},                                    //~v1.0I~
	{"f"    ,"f"   ,KTCHAR(f)},                                    //~v1.0I~
	{"g"    ,"g"   ,KTCHAR(g)},                                    //~v1.0I~
	{"h"    ,"h"   ,KTCHAR(h)},                                    //~v1.0I~
	{"j"    ,"j"   ,KTCHAR(j)},                                    //~v1.0I~
	{"k"    ,"k"   ,KTCHAR(k)},                                    //~v1.0I~
	{"l"    ,"l"   ,KTCHAR(l)},                                    //~v1.0I~
	{";"    ,";"   ,KTCHAR(SEMICOLON)},                            //~v1.0I~
	{":"    ,":"   ,KTCHAR(COLON)},                                //~v1.0I~
	{"]"    ,"]"   ,KTCHAR(RMP)},//right middle parenthesis        //~v1.0I~
                                                                   //~v1.0I~
//*4th line                                                        //~v1.0I~
	{"z"    ,"z"   ,KTCHAR(z)},                                    //~v1.0I~
	{"x"    ,"x"   ,KTCHAR(x)},                                    //~v1.0I~
	{"c"    ,"c"   ,KTCHAR(c)},                                    //~v1.0I~
	{"v"    ,"v"   ,KTCHAR(v)},                                    //~v1.0I~
	{"b"    ,"b"   ,KTCHAR(b)},                                    //~v1.0I~
	{"n"    ,"n"   ,KTCHAR(n)},                                    //~v1.0I~
	{"m"    ,"m"   ,KTCHAR(m)},                                    //~v1.0I~
	{","    ,","   ,KTCHAR(COMMA)},                                //~v1.0I~
	{"."    ,"."   ,KTCHAR(PERIOD)},                               //~v1.0I~
	{"/"    ,"/"   ,KTCHAR(SLASH)},                                //~v1.0I~
	{"\x5c"    ,"\x5c",KTCHAR(BSLASH)},                            //~v1.0I~
                                                                   //~v1.0I~
	{"10KEY-0"    ,"10KEY-0"   ,KTDEFDUP(P0,KTCTLDUP2)    },       //~v1.0I~
	{"10KEY-1"    ,"10KEY-1"   ,KTDEFDUP(P1,KTCTLDUP2)    },       //~v1.0I~
	{"10KEY-2"    ,"10KEY-2"   ,KTDEFDUP(P2,KTCTLDUP2)    },       //~v1.0I~
	{"10KEY-3"    ,"10KEY-3"   ,KTDEFDUP(P3,KTCTLDUP2)    },       //~v1.0I~
	{"10KEY-4"    ,"10KEY-4"   ,KTDEFDUP(P4,KTCTLDUP2)    },       //~v1.0I~
	{"10KEY-5"    ,"10KEY-5"   ,KTDEF(P5)    },                    //~v1.0I~
	{"10KEY-6"    ,"10KEY-6"   ,KTDEFDUP(P6,KTCTLDUP2)    },       //~v1.0I~
	{"10KEY-7"    ,"10KEY-7"   ,KTDEFDUP(P7,KTCTLDUP2)    },       //~v1.0I~
	{"10KEY-8"    ,"10KEY-8"   ,KTDEFDUP(P8,KTCTLDUP2)    },       //~v1.0I~
	{"10KEY-9"    ,"10KEY-9"   ,KTDEFDUP(P9,KTCTLDUP2)    },       //~v1.0I~
	{"10KEY-/"    ,"10KEY-/"   ,KTDEF(PDIVIDE)},                   //~v1.0I~
	{"10KEY-*"    ,"10KEY-*"   ,KTDEF(PMULTIPLY)},                 //~v1.0I~
	{"10KEY--"    ,"10KEY--"   ,KTDEF(PMINUS)},                    //~v1.0I~
	{"10KEY-+"    ,"10KEY-+"   ,KTDEF(PPLUS) },                    //~v1.0I~
	{"10KEY-."    ,"10KEY-."   ,KTDEFDUP(PPERIOD,KTCTLDUP2)},      //~v1.0I~
	{"10KEY-,"    ,"10KEY-,"   ,KTDEF(PCOMMA)},                    //~v1.0I~
	{"10KEY-Enter","10キー改行",KTDEF(PENTR),{0,KTSHIFTDUP}},      //~v1.0I~
                                                                   //~v1.0I~
	{""}//terminater                                               //~v1.0I~
};                                                                 //~v1.0I~
//*******************************************************************//~v1.0I~
int main(int parmc,UCHAR *parmp[])                                 //~v1.1R~
{
    struct {                                                       //~v1.0I~
            	UCHAR ls[3];                                       //~v1.0I~
                UCHAR delm2;                                       //~v1.0I~
            	UCHAR rs[3];                                       //~v1.0M~
                UCHAR delm1;                                       //~v1.0M~
            	UCHAR ct[3];                                       //~v1.0I~
                UCHAR delm3;                                       //~v1.0I~
            	UCHAR al[3];                                       //~v1.0I~
                UCHAR delm4;                                       //~v1.0I~
            	UCHAR so[3];                                       //~v1.0I~
                UCHAR delm5;                                       //~v1.0I~
            	UCHAR no[3];                                       //~v1.0I~
                UCHAR delm6;                                       //~v1.0I~
            	UCHAR co[3];                                       //~v1.0I~
                UCHAR delm7;                                       //~v1.0I~
            	UCHAR io[3];                                       //~v1.0I~
                UCHAR delm8;                                       //~v1.0I~
            	UCHAR lc[3];                                       //~v1.0I~
                UCHAR delma;                                       //~v1.0I~
            	UCHAR rc[3];                                       //~v1.0I~
                UCHAR delm9;                                       //~v1.0M~
            	UCHAR la[3];                                       //~v1.0M~
                UCHAR delmb;                                       //~v1.0I~
            	UCHAR ra[3];                                       //~v1.0I~
                UCHAR delmc;                                       //~v1.0I~
            	UCHAR sc[3];                                       //~v1.0I~
                UCHAR delmd;                                       //~v1.0I~
            	UCHAR nu[3];                                       //~v1.0I~
                UCHAR delme;                                       //~v1.0I~
            	UCHAR ca[3];                                       //~v1.0I~
                UCHAR delmf;                                       //~v1.0I~
            	UCHAR sy[3];                                       //~v1.0I~
                UCHAR delm0;                                       //~v1.0I~
            } ss;                                                  //~v1.0I~
	KBDKEYINFO keyinf;                                             //~v1.0I~
	KEYTBL  *pkt;                                                  //~v1.0I~
	UCHAR  buff[512],*inputfname;                                  //~v1.0R~
    FILE *fh;                                                   //~5C24I~
    int    klsw,oklsw,ilctr=0,kictr=0,kidx;                        //~v1.0R~
    USHORT scch;                                                   //~v1.0I~
    UCHAR  wkx[12];                                                //~v1.0I~
//*******************************************************************

//**************************
//* initialize             *
//**************************
    if (parmc<2||*parmp[1]=='?')                                   //~v1.0R~
      	putmsg(4,"%s xe-trace-file-name\n",PGMID);                 //~v1.0R~
    inputfname=parmp[1];                                           //~v1.0R~
    if (!(fh=fopen(inputfname,"r")))                               //~v1.0R~
      	putmsg(4,"input file:%s open err,rc=%d\n",inputfname,errno);//~v1.0R~

    ss.delm0=0;                                                    //~v1.0I~
//*****************************
//*main line                                                       //~v1.0I~
//*****************************
	klsw=0;			//keyin data line detected sw                  //~v1.0I~
  	while (fgets(buff,sizeof(buff),fh))                         //~5C24R~
  	{                                                           //~5C24R~
    	ilctr++;                                                   //~v1.0I~
    	oklsw=klsw;                                                //~v1.0I~
	    klsw=(strstr(buff," ukbdcharin")!=0);	//hdr line of keyin data//~v1.0R~
        if (oklsw)	//keyin data line                              //~v1.0R~
        {                                                          //~v1.0I~
        	kictr++;                                               //~v1.0I~
        	ugethex(buff+10,wkx,8);                                //~v1.0R~
        	ugethex(buff+19,wkx+4,8);                              //~v1.0I~
        	ugethex(buff+28,wkx+8,4);                              //~v1.0I~
      		keyinf.chChar   =wkx[0];                               //~v1.0I~
      		keyinf.chScan   =wkx[1];                               //~v1.0I~
      		keyinf.fbStatus =wkx[2];                               //~v1.0I~
      		keyinf.bNlsShift=wkx[3];                               //~v1.0I~
      		keyinf.fsState  =*(USHORT*)(void*)(wkx+4);             //~v1.0I~
      		keyinf.time     =*(ULONG*)(void*)(wkx+6);              //~v1.0I~
                                                                   //~v1.0I~
			memset(&ss,' ',sizeof(ss)-1);                          //~v1.0R~
//shift status                                                     //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_RIGHTSHIFT)                //~v1.0R~
            	memcpy(ss.rs,"r-S",3);                             //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_LEFTSHIFT)                 //~v1.0R~
            	memcpy(ss.ls,"l-S",3);                             //~v1.0R~
	      	if (keyinf.fsState & KBDSTF_CONTROL)                   //~v1.0R~
            	memcpy(ss.ct,"Ctrl",4);                            //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_ALT)                       //~v1.0R~
            	memcpy(ss.al,"Alt",3);                             //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_SCROLLLOCK_ON)             //~v1.0R~
            	memcpy(ss.so,"ScrOn",5);                           //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_NUMLOCK_ON)                //~v1.0R~
            	memcpy(ss.no,"NumOn",3);                           //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_CAPSLOCK_ON)               //~v1.0R~
            	memcpy(ss.co,"CapOn",3);                           //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_INSERT_ON)                 //~v1.0R~
   				memcpy(ss.io,"InsOn",3);                           //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_LEFTCONTROL)               //~v1.0R~
   				memcpy(ss.lc,"l-C",3);                             //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_LEFTALT)                   //~v1.0R~
   				memcpy(ss.la,"l-A",3);                             //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_RIGHTCONTROL)              //~v1.0R~
   				memcpy(ss.rc,"r-C",3);                             //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_RIGHTALT)                  //~v1.0R~
   				memcpy(ss.ra,"r-A",3);                             //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_SCROLLLOCK)                //~v1.0R~
   				memcpy(ss.sc,"Scr",3);                             //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_NUMLOCK)                   //~v1.0R~
   				memcpy(ss.nu,"Num",3);                             //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_CAPSLOCK)                  //~v1.0R~
   				memcpy(ss.ca,"Num",3);                             //~v1.0I~
	      	if (keyinf.fsState & KBDSTF_SYSREQ)                    //~v1.0R~
   				memcpy(ss.sy,"Sys",3);                             //~v1.0I~
//printf("klswon %s\n",&ss);                                       //~v1.0R~
//key name                                                         //~v1.0I~
            if (keyinf.chChar==0xE0)                               //~v1.0R~
            	scch=(USHORT)(keyinf.chScan<<8);                   //~v1.0R~
            else                                                   //~v1.0I~
            	scch=*(USHORT*)(void*)&keyinf.chChar;              //~v1.0I~
            kidx=kbdsrchkt(scch,&pkt);                             //~v1.0I~
            if (kidx!=4)	//defined                              //~v1.0I~
            	sprintf(buff+35,"= %-4s %s\n",pkt->KTnamej,ss.ls); //~v1.0R~
//printf("ktsrch rc=%d,%04x\n",kidx,(int)scch);                    //~v1.0R~
        }                                                       //~5C24I~
        printf(buff);                                              //~v1.0I~
  	}                                                           //~5C24R~
//                                                              //~5C24I~
    printf ("************************\n");                      //~5C24I~
    printf("%s input =%d lines, keyin = %d lines\n",               //~v1.0R~
    		inputfname,ilctr,kictr);                               //~v1.0R~
  	return 0;                                                   //~5C24R~
}   //end main
//**************************************************               //~v1.0I~
//*function key definition chk                                     //~v1.0I~
//*parm1:key                                                       //~v1.0I~
//*parm2:output key tbl addr(null if err)                          //~v1.0I~
//*return:keytbl scancode tbl index(4 if err)                      //~v1.0I~
//**************************************************               //~v1.0I~
int kbdsrchkt(USHORT Pkey,KEYTBL **Ppkt)                           //~v1.0I~
{                                                                  //~v1.0I~
	KEYTBL *pkt;                                                   //~v1.0I~
	int i=0;                                                         //~v1.0I~//~vafcR~
//****************                                                 //~v1.0I~
	for (pkt=Sfkeytbl;*(pkt->KTnamee);pkt++)                       //~v1.0I~
	{                                                              //~v1.0I~
		for (i=0;i<4;i++)                                          //~v1.0I~
			if (Pkey==pkt->KTkey[i])                               //~v1.0I~
				break;                                             //~v1.0I~
		if (i<4)	//found                                        //~v1.0I~
			break;                                                 //~v1.0I~
	}                                                              //~v1.0I~
	if (i==4)                                                      //~v1.0I~
		*Ppkt=0;                                                   //~v1.0I~
	else                                                           //~v1.0I~
		*Ppkt=pkt;                                                 //~v1.0I~
	return i;                                                      //~v1.0I~
}//kbdsrchkt                                                       //~v1.0I~
                                                                   //~v1.0I~
//********************************************************************//~v1.0I~
//* error msg output and exit                                      //~v1.0I~
//*   input:                                                       //~v1.0I~
//*     p1    :exit code,exit program if not 0                     //~v1.0I~
//*     p2    :printf patern                                       //~v1.0I~
//*     p3-p12:edit parameter(max 10 edit parm)                    //~v1.0I~
//*   output:                                                      //~v1.0I~
//*     standard error output                                      //~v1.0I~
//********************************************************************//~v1.0I~
                                                                   //~v1.0I~
void putmsg(int exitcode,UCHAR *patern,...)                        //~v1.0I~
{                                                                  //~v1.0I~
  UCHAR errmsg[512];      //for lineput                            //~v1.0I~
//**************                                                   //~v1.0I~
  sprintf(errmsg,"\n%s-%s:",PGMID,VER);                            //~v1.0I~
  sprintf(errmsg+strlen(errmsg),patern,                            //~v1.0I~
          *(&patern+1), //edit parm 1                              //~v1.0I~
          *(&patern+2), //edit parm 2                              //~v1.0I~
          *(&patern+3), //edit parm 3                              //~v1.0I~
          *(&patern+4), //edit parm 4                              //~v1.0I~
          *(&patern+5), //edit parm 5                              //~v1.0I~
          *(&patern+6), //edit parm 6                              //~v1.0I~
          *(&patern+7), //edit parm 7                              //~v1.0I~
          *(&patern+8), //edit parm 8                              //~v1.0I~
          *(&patern+9), //edit parm 9                              //~v1.0I~
          *(&patern+10));//edit parm 10                            //~v1.0I~
  fprintf(stderr,"%s",errmsg);                                     //~v1.0I~
  if (exitcode)                                                    //~v1.0I~
    exit(exitcode);//terminate                                     //~v1.0I~
}//endof putmsg                                                    //~v1.0I~
