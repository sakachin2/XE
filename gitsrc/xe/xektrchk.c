//CID://+DATER~:               update#=     27                     //~5826R~
// ******************************************************************
// * xektrchk.c           2025/08/26                               //~5827R~
// *  print keyname of trc_kbd file                                //~5826R~
// **********************************************/
// **********************************************/                 //~v1.0R~
#define VER    "V1.1"        //version                             //~v69yR~
// *******************************************************************
// *******************************************************************//~v1.1I~

#include <time.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>                                                 //~v1.0I~
#include <ctype.h>                                                 //~5826I~
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
#include <uque.h>                                                  //~vanfI~
//********************************************************************
#include "xescr.h"                                                 //~vanfI~
#include "xekbd.h"                                                 //~v1.0I~
//********************************************************************//~v1.0I~

#define PGMID  "xetrckbdchk"     //program id                      //~5826R~
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
static KEYTBL *Sextkey[256];                                       //~5826R~
static int     SextkeyMod[256];                                    //~5826I~
static char *Smodid[4]={"","S","A","C"};                           //~5826R~
//*******************************************************************//~5826I~
void setupKey2Name()                                               //~5826R~
{                                                                  //~5826I~
	KEYTBL *pkt;                                                   //~5826I~
	USHORT key;                                                    //~5826I~
    int ii,scan,ch;                                                //~5826I~
	for (pkt=Sfkeytbl;*(pkt->KTnamee);pkt++)                       //~5826I~
	{                                                              //~5826I~
		for (ii=0;ii<4;ii++)                                       //~5826I~
        {                                                          //~5826I~
			key=pkt->KTkey[ii];                                    //~5826I~
            if (!key)                                              //~5826I~
            	continue;                                          //~5826I~
            ch=key>>8;                                             //+5827R~
            scan=key&0xff;                                         //+5827R~
            if (!scan)	//extkey                                   //+5827R~
            {                                                      //~5826I~
            	if (!Sextkey[ch])                                  //+5827R~
                {                                                  //~5826I~
            		Sextkey[ch]=pkt;                               //+5827R~
					SextkeyMod[ch]=ii;                             //+5827R~
                }                                                  //~5826I~
            }                                                      //~5826I~
        }                                                          //~5826I~
	}                                                              //~5826I~
                                                                   //~5826I~
}                                                                  //~5826I~
//*******************************************************************//~5826I~
void getKeyname(int Pkeytype,int Pscanchar,char *Pname)            //~5826R~
{                                                                  //~5826I~
	KEYTBL *pkt;                                                   //~5826I~
    int scan,ch,mod;                                               //~5826R~
    *Pname=0;                                                      //~5826I~
    int keytype=Pkeytype-'0';                                      //~5826I~
    switch(keytype)                                                //~5826I~
    {                                                              //~5826I~
    case UCWKTEXTKEY:                                              //~5826I~
    case UCWKTSBCS:                                                //~5826I~
        ch=Pscanchar>>8;                                           //~5826R~
        scan=Pscanchar&0xff;                                       //~5826R~
        if (!scan && ch) //extkey                                  //~5826R~
        {                                                          //~5826R~
            pkt=Sextkey[ch];                                       //~5826R~
            mod=SextkeyMod[ch];                                    //~5826R~
            if (mod)                                               //~5826R~
                sprintf(Pname,"%s_%s",Smodid[mod],pkt->KTnamee);   //~5826R~
            else                                                   //~5826R~
                sprintf(Pname,"%s",pkt->KTnamee);                  //~5826R~
        }                                                          //~5826R~
        else                                                       //~5826R~
        {                                                          //~5826R~
            if (ch=='\r')                                          //~5826R~
                strcpy(Pname,"Return");                            //~5826I~
            else                                                   //~5826I~
            if (isprint(ch))                                       //~5826R~
                sprintf(Pname,"\"%c\"",ch);                        //~5826R~
        }                                                          //~5826R~
        break;                                                     //~5826I~
    case UCWKTDBCS:                                                //~5826I~
        ch=Pscanchar>>8;                                           //~5827I~
        scan=Pscanchar&0xff;                                       //~5827I~
    	sprintf(Pname,"DBCS(%c%c)",ch,scan);                       //~5827R~
        break;                                                     //~5826I~
    case UCWKTSCRDRAW:                                             //~5826I~
    	strcpy(Pname,"SCRDRAW");                                   //~5826I~
        break;                                                     //~5826I~
    case UCWKTCMD:                                                 //~5826I~
    	strcpy(Pname,"CMD");                                       //~5826I~
        break;                                                     //~5826I~
    case UCWKTMOUSE:                                               //~5826I~
    	strcpy(Pname,"MOUSE");                                     //~5826I~
        break;                                                     //~5826I~
    case UCWKTFUNCID:                                              //~5826I~
    	strcpy(Pname,"FUNCID");                                    //~5826I~
        break;                                                     //~5826I~
    }                                                              //~5826I~
}                                                                  //~5826I~
//*******************************************************************//~v1.0I~
int main(int parmc,UCHAR *parmp[])                                 //~v1.1R~
{
	UCHAR  buff[512],*inputfname;                                  //~v1.0R~
    FILE *fh;                                                   //~5C24I~
    UCHAR  wkx[12];                                                //~v1.0I~
    char keynm[32],*pc;                                            //~5826R~

    if (parmc<2||*parmp[1]=='?')                                   //~v1.0R~
      	putmsg(4,"%s xe-trace-file-name\n",PGMID);                 //~v1.0R~
    inputfname=parmp[1];                                           //~v1.0R~
    if (!(fh=fopen(inputfname,"r")))                               //~v1.0R~
      	putmsg(4,"input file:%s open err,rc=%d\n",inputfname,errno);//~v1.0R~

	setupKey2Name();                                               //~5826I~
//*****************************
//*main line                                                       //~v1.0I~
//*****************************
  	while (fgets(buff,sizeof(buff),fh))                         //~5C24R~
  	{                                                           //~5C24R~
        char *pce=strchr(buff,'\n');                               //~5826M~
        if (pce)                                                   //~5826M~
        	*pce=0;                                                //~5826M~
	    pc=strstr(buff,"keytype=");                                //~5826R~
        if (!pc)                                                   //~5826I~
        {                                                          //~5826I~
        	printf("%s\n",buff);                                   //~5826I~
        	continue;                                              //~5826I~
        }                                                          //~5826I~
        int keytype=*(pc+8);                                       //~5826I~
	    pc=strstr(pc,"key=");                                      //~5826R~
        if (!pc)                                                   //~5826I~
        {                                                          //~5826I~
        	printf("%s\n",buff);                                   //~5826I~
        	continue;                                              //~5826I~
        }                                                          //~5826I~
        ugethex(pc+4,wkx,8);                                       //~5826R~
      	int scanchar=(wkx[0]<<8)+(wkx[1]);                         //~5826R~
		getKeyname(keytype,scanchar,keynm);                        //~5826R~
        printf("%s::%s\n",buff,keynm);                             //~5826R~
  	}                                                           //~5C24R~
  	return 0;                                                   //~5C24R~
}   //end main
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
