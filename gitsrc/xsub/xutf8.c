//*CID://+vaa0R~:                             update#=  200;       //+vaa0R~
//*************************************************************
//*xutf8                                                           //~va3eR~
//*write file utf8 code file of the unicode range specified by parameter
//*************************************************************
#define VER "1.2"                                                  //~va3kR~//+vaa0R~
//*************************************************************    //~va3eI~
//vaa0:160417 Lnx compiler warning                                 //+vaa0I~
//va3k:080125 xutf8 v1.1 compiler warning for 0x5c                 //~va3kI~
//va3e:070922 xutf8 v1.0 new                                       //~va3eI~
//*************************************************************
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ulib.h>
#include <ustring.h>
#include <utrace.h>
#include <uque.h>
#include <ucvucs.h>
#include <uerr.h>
//********************
#define HELPMSG         uerrhelpmsg(stdout,stderr,
#define MAXRANGE 100
//********************                                             //~va3eI~
static int Srange1[MAXRANGE],Srange2[MAXRANGE];
static int  Srangeno=0,Swidth=0,Slfrange,Sheadersw=0;              //~va3eR~
static char *Spgm="xutf8";
static char *Sver=VER;
//*************************************************************
void parmchk(int parmc,char *parmp[]);
void help(void);
void optionerr(char *type,char* value);
//*************************************************************
int main(int parmc,char * parmp[])
{
	char utf8[8];
    int ucs1,ucs2,ucs,ii,cnt,len,lfsw=0;                           //~va3eR~
//**********************
	parmchk(parmc,parmp);
    if (Sheadersw)                                                 //~va3eI~
    	lfsw=1;                                                    //~va3eI~
	for (ii=0;ii<Srangeno;ii++)
    {
    	ucs1=Srange1[ii];
    	ucs2=Srange2[ii];
    	for (ucs=ucs1,cnt=0;ucs<=ucs2;ucs++,cnt++)
        {
            len=uccvucs2utf(ucs,utf8);                             //~va3eR~
            if (!len)                                              //~va3eI~
            {	                                                   //~va3eI~
            	uerrmsg("\n%08x is too big as supported unicode",0,//~va3eR~
							ucs);                                  //~va3eI~
                break;                                             //~va3eI~
            }                                                      //~va3eI~
            *(utf8+len)=0;
            if (lfsw && Sheadersw)                                 //~va3eI~
            	printf("%06x:",ucs);                               //~va3eR~
            printf("%s",utf8);
            lfsw=0;
            if (Swidth && (cnt+1)%Swidth==0)                       //~va3eR~
            {
	            printf("\n");
                lfsw=1;
            }
        }
        if (Slfrange)
            if (!lfsw)
            {                                                      //~va3eI~
		    	printf("\n");
                lfsw=1;                                            //~va3eI~
            }                                                      //~va3eI~
    }
	return 0;
}//charin
//**********************************************************************
//*parameter chk
//**********************************************************************
void parmchk(int parmc,char *parmp[])
{
    unsigned char c;
    char *cptr,*cptr0,*pc;                                         //~va3eR~
    int parmno,len;
    int width,ucs1,ucs2; //parm count work                         //~va3eR~
//*************************
    if (parmc<2 || *parmp[1]=='?')
    {
      	help();
      	exit(0);
    }
//*******************************
//* parm process                *
//*******************************
    for (parmno=1;parmno<parmc;parmno++)
    {
        cptr=cptr0=parmp[parmno];
        if(*cptr=='/')
        {//option
        	for (;;)
            {
                c=*(++cptr);                      //first option byte
                if (!c)
                	break;
                switch(toupper(c))             //option
                {
                case '?':           //cmd string start
                case 'H':           //apply to file
                    help();
                    exit(0);
                    break;
                case 'Y':           //toggle on
                    for (;;)
                    {
                        c=*(++cptr);
                        if (!c)
                        {
                        	cptr--;
                            break;
                        }
                        switch(toupper(c))
                        {
                        case '9':       //dbcs sw
                            UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                            UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs
                            break;
                        default:                           //not option
                            optionerr("Yes/No option",cptr0);
                        }
                    }
                    break;
                case 'N':           //toggle on
                    for (;;)
                    {
                        c=*(++cptr);
                        if (!c)
                        {
                        	cptr--;
                            break;
                        }
                        switch(toupper(c))
                        {
                        case '9':       //dbcs sw
                            UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                            UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs
                            break;
                        default:                           //not option
                            optionerr("Yes/No option",cptr0);
                        }
                    }
                    break;
                default:                           //not option
                    uerrexit("undefined option parm(%s)\n",
                             "未定義パラメータ(%s)\n",
                              cptr0);
                }//switch  by first option byte
            }
            continue;
		}//option
//pos parm
	    switch(sscanf(cptr,"%X-%X",&ucs1,&ucs2))
        {
        case 2:
//      printf("%d-%d\n",ucs1,ucs2);
        	if (ucs1>ucs2)
            	optionerr("range parm err",cptr);
            if (Srangeno>MAXRANGE)
            	uerrexit("Too many parameter",0);
        	Srange1[Srangeno]=ucs1;
        	Srange2[Srangeno]=ucs2;
        	Srangeno++;
            break;
        default:
//          len=strlen(cptr);                                      //+vaa0R~
            len=(int)strlen(cptr);                                 //+vaa0I~
	        for (pc=cptr+len-1;len>0;len--,pc--)                   //~va3eI~
            {                                                      //~va3eI~
            	if (toupper(*pc)=='R')                             //~va3eR~
            		Slfrange=1;	//linefeed for each range          //~va3eR~
                else                                               //~va3eI~
            	if (toupper(*pc)=='H')                             //~va3eI~
            		Sheadersw=1;	//linefeed for each range      //~va3eI~
                else                                               //~va3eI~
                	break;                                         //~va3eI~
            }                                                      //~va3eI~
            if (len)
            {
            	width=atoi(cptr);
            	if (!width)
            		optionerr("line width parm err",cptr);
            	Swidth=width;
            }
        }//switch by parmno
	}//for all parm
    if (!Srangeno)
    	uerrexit("Missing unicode range\n",
            	 "unicodeの範囲を指定して下さい");
//combination chk
//printf("op=%c opt=%x\n",Soper,Sparmopt);
}//parmchk
//**********************************************************************
//* write option err msg  v3.8a
//**********************************************************************
void optionerr(char *type,char* value)
{
        uerrexit("invalid %s option parm value(%s)\n",
                         "%s の値(%s)の誤り\n",
                        type,value);
}//optionerr
//**********************************************************************
//* write help msg
//**********************************************************************
void help(void)
{
//*******************
        HELPMSG
"%s : %s=(%c)= Write utf8 code to stdout correspond to the unicode ranges.\n",//~va3eR~
"%s : %s=(%c)= 指定の範囲のユニコードに対応するUTF8コードを標準出力に書く。\n",//~va3eR~
                Spgm,Sver,OSTYPE);
        HELPMSG
"fmt  : %s xxx1-yyy1 [xxx2-yyy2 ...] [[nn][R][H]]\n",              //~va3eR~
"形式 : %s xxx1-yyy1 [xxx2-yyy2 ...] [[nn][R][H]]\n",              //~va3eR~
                Spgm);
        HELPMSG
"  xxxx-yyyy :unicode range by hex notation.\n",
"  xxxx-yyyy :ヘキサ\x95\\記によるユニコードの範囲指定。\n");      //~va3kR~
        HELPMSG
"  nn        :LineFeed for each nn characters.\n",
"  nn        :nn文字ごとに改行を入れる。\n");
        HELPMSG
"  R         :LineFeed for each range.\n",
"  R         :各範囲ごとに改行を入れる。\n");
        HELPMSG                                                    //~va3eI~
"  H         :print unicode as line header.\n",                    //~va3eI~
"  H         :各行に最初にユニコードのヘキサ\x95\\記を出力。\n");  //~va3kR~
        HELPMSG
"ex)%s 00-100  ; %s  00-100 2000-2fff 32r ; %s 3000-3800 16H",     //~va3eR~
"例)%s 00-100  ; %s  00-100 2000-2fff 32r ; %s 3000-3800 16H",     //~va3eR~
				Spgm,Spgm,Spgm);                                   //~va3eR~
	return;
}//help
