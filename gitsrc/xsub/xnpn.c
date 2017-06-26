//*CID://+v2acR~:                             update#=   41;       //~v2acR~
//*************************************************************
//*XNP.c   Number Place Puzzle
//*format
//*      xnp  datafile
//*           datafile fmt
//*            9*9 matrix seperated by comma.set '0' for space.
//*            a line is  like as  7,8,0,0,0,0,0,5,2
//*************************************************************
//va2c:051012 xnpn:v1.2 same registry pswd ok chk as wnp           //~v2acI~
//*010317 xnp v1.1:common source for both 4*4 and 5*5              //~v1.1I~
//*001115 xnp v0.5:4*4 matrix version                              //~v0.5I~
//*000104 xnp v0.1:no rgid when no patern data                     //~v0.4I~
//*000103 xnp v0.1:Win(C++) support                                //~v0.1I~
//*v100 first
//*************************************************************
//#define VERSION  "v1.1"                                          //~v2acR~
#define VERSION  "v1.2"                                            //~v2acI~
#define PGMID    "xnp"                                             //~v2acR~
#define HELPMSG uerrhelpmsg(stdout,stderr,
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
#else
  #ifdef W32
  	#include <windows.h>                                           //~v1.1I~
  #else
  #endif
#endif
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
//********************
#define GBL_MAIN        //generate global var                      //~v0.5I~
#include "xnpnsub.h"                                               //~v0.5R~
#include "xnpnsub2.h"                                              //~v0.5R~
//********************
//********************
static	char Spgmver[16];
static  int  Soptions=XNP_RIGID|XNP_PRINTIDATA;
static  int  Sqmakesw;
static  int  Ssetlimit=SETMAX;      //dencity                      //~0116R~
static  int  Srepeatmax;		//loop max time limit(seconds)     //~v0.1R~
static  int  Stmsgfreq;  		//time msg frequency each 10 seconds//~v0.1R~
static  int  Sseed;          		//random-no seed
static  int  Splan;          		//strategy of search pos for make
static  int  Srcmaxl=0;          		//strategy of search pos for make//~v1.1R~
static  UCHAR Slevel;
//********************
void titlemsg(void);
void help(void);
int  xnpansmain(char *Pfnm);
int xnpqmkmain(char *pfnm);
int  xnpreaddata(FILE *Ppfh,int *Pdata);
static int pswdchk(void);                                          //~v1.1R~
//*************************************************************
int main(int parmc,char * parmp[])
{
    int parmno,posparmno=0,atoiwk,sortopt=0;                       //~v0.1R~
    char *cptr,ch,*fnm=0,*pc;
//**********************
	sprintf(Spgmver,"# %s:%s: ",PGMID,VERSION);
	uerrmsg_init("# ",stdout,0);//msg to stdout
	uerrexit_init(Spgmver,stdout,0,0,0);//stdout only,no pathmsg
	uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit
#ifdef DPMI					//DPMI version
    putenv("LFN=Y");                 //need for ufileisvfat
	ufileisvfat(ISVFAT_FORCE);      //force vfat
#endif                      //DPMI or not
	if (parmc==1)
    {
    	help();
        exit (4);
    }
//*******************************
//* parm process                *
//*******************************
	for (parmno=1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
  		if(*cptr=='/'||*cptr=='-')
  		{//option
    		ch=*(++cptr);                      //first option byte
    		switch(toupper(ch))             //option
    		{
    		case '?':
    		case 'H':                                              //~v0.5R~
        		help();
        		exit(8);
                break;
#ifdef XNP_MAKE                                                    //~v0.5I~
    		case 'D':       //set limit
                Ssetlimit=atoi(cptr+1);
                if (!Ssetlimit)
                	Ssetlimit=SETMAX;
                else
//                  if (Ssetlimit<3)                               //~v0.5R~
//                  	uerrexit("Limit should be >=3.",0);        //~v0.5I~
                    if (Ssetlimit<MM_BASE)                         //~v0.5R~
                    	uerrexit("Limit should be >=%d.",0,        //~v0.5R~
									MM_BASE);                      //~v0.5R~
                break;
#endif                                                             //~v0.5I~
#ifdef XNP_MAKE                                                    //~v0.5I~
    		case 'G':               //strategy                     //~0116I~
			    switch(toupper(*(cptr+1)))                         //~0116M~
    			{                                                  //~0116M~
    			case 0:                                            //~0116M~
    				Splan=0;                                       //~0116M~
        			break;                                         //~0116M~
    			case 'N':		//minimum                          //~0116M~
            		atoiwk=atoi(cptr+2);                           //~0116M~
                	if (atoiwk)                                    //~0116M~
                		Splan=-atoiwk;                             //~0116M~
                    else                                           //~0116M~
//                  	Splan=-9;                                  //~v0.5R~
                    	Splan=-MM_MAXN;                            //~v0.5R~
        			break;                                         //~0116M~
    			case 'X':		//maximum                          //~0116M~
            		atoiwk=atoi(cptr+2);                           //~0116M~
                	if (atoiwk)                                    //~0116M~
    					Splan=atoiwk;                              //~0116M~
                    else                                           //~0116M~
//    					Splan=9;                                   //~v0.5R~
      					Splan=MM_MAXN;                             //~v0.5R~
        			break;                                         //~0116M~
				default:                                           //~0116M~
                	uerrexit("Make strategy option parm(%s) err",0,//~0116M~
                                    cptr);                         //~0116M~
                }                                                  //~0116M~
                break;                                             //~0116M~
#endif                                                             //~v0.5I~
#ifdef XNP_MAKE                                                    //~v0.5I~
    		case 'M':          // /M
                Sqmakesw=1;
            	Slevel=(UCHAR)toupper(*(cptr+1));
                if (Slevel)
                    if (!(Slevel=='H' || Slevel=='M' || Slevel=='E'))
                        uerrexit("Make level option(%s) err",0,
                                        cptr+1);
                break;
#endif                                                             //~v0.5I~
    		case 'P':
                Soptions|=XNP_PILOT;
                break;
    		case 'R':			// /R
                Soptions|=XNP_REDUNDANTCK;
                atoiwk=atoi(cptr+1);                               //~v1.1R~
                Srcmaxl=atoiwk;                                    //~v1.1R~
//printf("%d,%d \n",Srchkmaxlevel,atoi(cptr+1));                   //~v1.1R~
//exit(8);                                                         //~v1.1R~
                break;
#ifdef XNP_MAKE                                                    //~v0.5I~
    		case 'S':
            	atoiwk=atoi(cptr+1);
                if (atoiwk)
                	Sseed=atoiwk;
                break;
#endif                                                             //~v0.5I~
    		case 'T':           //timeout                          //~0116I~
            	atoiwk=atoi(cptr+1);                               //~0116M~
                if (atoiwk)                                        //~0116M~
                	Srepeatmax=atoiwk;                             //~0116M~
                if (pc=strchr(cptr+1,'/'),pc)                      //~0116M~
                {                                                  //~0116M~
            		atoiwk=atoi(pc+1);                             //~0116M~
                	if (atoiwk)                                    //~0116M~
                		Stmsgfreq=atoiwk;                          //~0116M~
				}                                                  //~0116M~
                break;                                             //~0116M~
    		case 'Y':
                while(ch=*(++cptr),ch)
                {
                    switch(toupper(ch))             //option
                    {
                    case '9':
                        UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                        UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs
                        break;
			   		case 'P':
            		    Soptions|=XNP_PRINTIDATA;
                		break;
			   		case 'R':
            		    Soptions|=XNP_RIGID;
                		break;
			   		case 'S':                                      //~v0.1I~
                    	sortopt=1;                                 //~v0.1I~
            		    Soptions|=XNP_SORT;                        //~v0.1I~
                		break;                                     //~v0.1I~
                    case 'T':
                        Soptions|=XNP_TEST;
                        break;
                    default :                           //not option
                        uerrexit("undefined option parm(%s)",0,
                                    parmp[parmno]);
                    }
                }
                break;
    		case 'N':
        	  	while(ch=*(++cptr),ch)
              	{
                    switch(toupper(ch))             //option
                    {
                    case '9':
                        UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                        UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs
                        break;
			   		case 'P':
            		    Soptions&=~XNP_PRINTIDATA;
                		break;
			   		case 'R':
            		    Soptions&=~XNP_RIGID;
                		break;
			   		case 'S':                                      //~v0.1I~
                    	sortopt=1;                                 //~v0.1I~
            		    Soptions&=~XNP_SORT;                       //~v0.1I~
                		break;                                     //~v0.1I~
                    case 'T':
                        Soptions&=~XNP_TEST;
                        break;
                    default :                           //not option
                        uerrexit("undefined option parm(%s)",0,
                                    parmp[parmno]);
                    }
              	}
                break;
    		default	:                           //not option
      			uerrexit("undefined option parm(%s)",0,
							parmp[parmno]);
            }//sw
    	}//flag
      	else
      	{//positional parmno
        	posparmno++;
        	switch (posparmno)
        	{
        	case  1:          //first parm
          		fnm=cptr;
          		break;
            default:
              	uerrexit("too many positional parameter(%s)",0,cptr);
            }//switch by parmno
  		}//option or posparm
	}//for all parm
    if (pswdchk())                                                 //~v1.1R~
    	uerrexit("Set Password by \"wnpmfc.exe\"",                 //~v1.1I~
        		"\"wnpmfc.exe\" プログラムでパスワード設定してください");//~v1.1I~
    if (Sqmakesw)
    {                                                              //~v0.1I~
	    if (!sortopt)                                              //~v0.1I~
            Soptions|=XNP_SORT;	//default for make                 //~v0.1I~
        xnpqmkmain(fnm);
	}                                                              //~v0.1I~
    else
    {
    	if (!fnm)
        	uerrexit("Specify Question data file name",
						"問題データファイル名を指定して下さい");
    	xnpansmain(fnm);		//fill initial data
	}
    titlemsg();
    return 0;
}//main
//**********************************************************************
//* write help msg
//**********************************************************************
void titlemsg(void)
{
        HELPMSG
"#%s:%s(%c):%s: ==== Number Place Puzzle =============== by EBURI-syo\n",
"#%s:%s(%c):%s: ==== ナンバープレース パズル ======== by 木八小 学 ==\n",//~v0.1R~
            PGMID,VERSION,OSTYPE,__DATE__);
    return;
}//titlemsg
//*********************
void help(void)
{
//************
	titlemsg();
#ifdef XNP_MAKE                                                    //~v0.5I~
HELPMSG
"This program solves Number Place Puzzle,or make Puzzle automaticaly.\n",
"ナンバープレース パズルを解いたり問題を自動生成したりするプログラムです\n");
#else                                                              //~v0.5I~
	HELPMSG                                                        //~v0.5I~
	"This program solves Number Place Puzzle of maxtrix size from 3 to 5.\n",//~v0.5I~
	"行列のサイズが 3 から 5 までのナンバープレース パズルを解くプログラムです\n");//~v0.5I~
#endif                                                             //~v0.5I~
                                                                   //~v0.5I~
HELPMSG
"\n",
"\n");
HELPMSG
"format: %s [file-name] [/option ...]\n",
"形式  : %s [ファイル名] [/オプション ...]\n",
				PGMID);
                                                                   //~v0.5I~
#ifdef XNP_MAKE                                                    //~v0.5I~
HELPMSG
"  file-name:Problem data or optional patern data to make puzzle.\n",
" ファイル名:問題データ或は問題作成のときのオプションのパターンデータ。\n");
#else                                                              //~v0.5I~
	HELPMSG                                                        //~v0.5I~
	"  file-name:Problem data file.\n",                            //~v0.5I~
	" ファイル名:問題データファイル。\n");                         //~v0.5I~
#endif                                                             //~v0.5I~
                                                                   //~v0.5I~
#ifdef XNP_MAKE                                                    //~v0.5I~
HELPMSG
".option for solution.\n",
"・解答用のオプション。\n");
#else                                                              //~v0.5I~
	HELPMSG                                                        //~v0.5I~
	".option,Default is in ( ).\n",                                //~v0.5I~
	"・オプション。括弧内は省略値。\n");                           //~v0.5I~
#endif                                                             //~v0.5I~
                                                                   //~v0.5I~
HELPMSG
"   /R[d]   : Redundancy chk,d:depth(1).\n",                       //~v0.5R~
"   /R[d]   : Redundancy chk;無くてもよいデータの有無をチェック。(d:深さ)\n");//~v0.5R~
                                                                   //~v0.5I~
#ifdef XNP_MAKE                                                    //~v0.5I~
HELPMSG
".option for making puzzle.\n",
"・問題作成用のオプション。\n");
HELPMSG
"   /Dcnt   : Density;max count in each box,row,col.\n",
"   /Dcnt   : Density;同じ行、列、箱に最大いくつまで置いてよいか。\n");
HELPMSG
//"             Default is 5,Minimum 3.\n",                        //~v0.5R~
//"             省略値は 5 、最小値は 3。\n");                     //~v0.5R~
"             Default is %d,Minimum %d.\n",                        //~v0.5I~
"             省略値は %d 、最小値は %d。\n",                      //~v0.5I~
				SETMAX,MM_BASE);                                   //~v0.5R~
HELPMSG
"   /M[x]   : Request of Make Puzzle.\n",                          //~v0.1R~
"   /M[x]   : Make;問題作成モードの指示。\n");                     //~v0.1R~
HELPMSG
"             By patern file,specify position where digit is placed if you want.\n",
"             パターンファイルを指定すれば数字を置く場所を指定できます。\n");
HELPMSG
"             x:Dificulty level request. x=H(hard), M(medium) or E(easy).\n",
"             x:作成する問題のレベルの指定。x=H(難), M(中) または E(易)．\n");
HELPMSG
"   /Sseed  : Seed of random-number generation.\n",
"   /Sseed  : Seed;乱数発生の種の数字。\n");
HELPMSG
"             Default is time-stamp.Use it to get same result from same data.\n",
"             省略値は時刻。同じデータで同じ結果を得るには同じ種を使用する。\n");
HELPMSG
".option for both.\n",
"・共通のオプション。\n");
                                                                   //~v0.5I~
#endif		//make                                                 //~v0.5I~
                                                                   //~v0.5I~
HELPMSG
"   /P      : Pilot;print intermediate step.\n",
"   /P      : Pilot;解答にいたるまでのまでの途中の1手1手を出力。\n");
#ifdef XNP_MAKE                                                    //~v0.5I~
HELPMSG                                                            //~v0.1M~
"   /Tl[/f] : Timeout limit.Default is in parenthesis.\n",         //~v0.1M~
"   /Tl[/f] : Timeout;制限時間(秒),括弧内は解答/作成それぞれのモードでの省略値。\n");//~v0.1R~
HELPMSG                                                            //~v0.1M~
"             l:limit seconds(%d/%d sec),f:iteration msg frequency(%d/%d sec).\n",//~v0.1R~
"             l:制限時間(%d/%d秒), f:経過MSGの表示頻度(%d/%d秒毎)。\n",//~v0.1R~
				ANS_TIMEOUT,MAKE_TIMEOUT,ANS_MSGFREQ,MAKE_MSGFREQ);//~v0.1I~
#else                                                              //~v0.5I~
	HELPMSG                                                        //~v0.5I~
	"   /Tl[/f] : Timeout limit.\n",                               //~v0.5I~
	"   /Tl[/f] : Timeout;制限時間(秒)。\n");                      //~v0.5I~
	HELPMSG                                                        //~v0.5I~
	"             l:limit seconds(%d sec),f:iteration msg frequency(%d sec).\n",//~v0.5I~
	"             l:制限時間(%d秒), f:経過MSGの表示頻度(%d秒毎)。\n",//~v0.5I~
					ANS_TIMEOUT,ANS_MSGFREQ);                      //~v0.5I~
#endif                                                             //~v0.5I~
HELPMSG
"   /Yx,/Nx : Yes/No:x is following option.\n",                    //~v0.5R~
"   /Yx,/Nx : 次の様なオプションが Yes か No か を指定する。\n");  //~v0.5R~
HELPMSG
"      x:p  : print data file contents.\n",
"      x:p  : データファイルの内容を出力する.(/Yp)\n");
                                                                   //~v0.5I~
#ifdef XNP_MAKE                                                    //~v0.5I~
HELPMSG                                                            //~v0.1I~
"      x:r  : Accept pattern as firmed.loosely use pattern data if /Nr.(/Yr)\n",//~v0.1R~
"      x:r  : パターンデータを遵守して作成する。/Nrのときは目安とする。(/Yr)\n");//~v0.1R~
HELPMSG                                                            //~v0.1I~
"      x:s  : Sort probrem data.(/Ys for Make mode,/Ns for Answer mode)\n",//~v0.1I~
"      x:s  : 問題データを整列する.(作成モードで/Ys、解答モードで/Ns)\n");//~v0.1I~
#else                                                              //~v0.5I~
	HELPMSG                                                        //~v0.5I~
	"      x:s  : Sort probrem data.(/Ns)\n",                      //~v0.5I~
	"      x:s  : 問題データを整列する.(/Ns)\n");                  //~v0.5I~
#endif                                                             //~v0.5I~
                                                                   //~v0.5I~
#ifdef XNP_MAKE                                                    //~v0.5I~
HELPMSG
//"  (Ex.) : %s xnpdata.#99 /p;  %s /m /d3; %s /m pat#01 /Np; \n", //~v0.5R~
//"  (例)  : %s xnpdata.#99 /p;  %s /m /d3; %s /m pat#01 /Np; \n", //~v0.5R~
//  			PGMID,PGMID,PGMID);                                //~v0.5R~
"  (Ex.) : %s xnpdata.#%d%d /p;  %s /m /d%d; %s /m pat#01 /Np; \n",//~v0.5I~
"  (例)  : %s xnpdata.#%d%d /p;  %s /m /d%d; %s /m pat#01 /Np; \n",//~v0.5R~
				PGMID,MM_BASE,MM_BASE,PGMID,MM_BASE,PGMID);        //~v0.5R~
#else                                                              //~v0.5I~
	HELPMSG                                                        //~v0.5I~
	"  (Ex.) : %s xnpdata.#%d%d /p;\n",                            //~v0.5I~
	"  (例)  : %s xnpdata.#%d%d /p;\n",                            //~v0.5I~
				PGMID,MM_BASE,MM_BASE);                            //~v0.5I~
#endif                                                             //~v0.5I~
                                                                   //~v0.5I~
#ifdef XNP_MAKE                                                    //~v0.5I~
HELPMSG
//".data fmt   : specify 9 x 9 matrix.\n",                         //~v0.5R~
//"・データ形式 : 9 x 9 の行列を指定します。\n");                  //~v0.5R~
".data fmt   : specify %d x %d matrix.\n",                         //~v0.5R~
"・データ形式 : %d x %d の行列を指定します。\n",                   //~v0.5R~
				MM_MAXN,MM_MAXN);                                  //~v0.5I~
#else                                                              //~v0.5I~
	HELPMSG                                                        //~v0.5I~
	".data fmt   : specify n x n matrix.(n=3,4,5)\n",              //~v0.5I~
	"・データ形式 : n x n の行列を指定します。(n=3,4,5)\n");       //~v0.5I~
#endif                                                             //~v0.5I~
                                                                   //~v0.5I~
HELPMSG
"  (Ex.1)       # Ex (19) 3x3\n",                                  //~v0.5R~
"  (例1)        # 例題 19。3x3\n");                                //~v0.5R~
HELPMSG                                                            //~v0.5R~
"                 7  8  _    _  _  _    _  5  2\n",                //~v0.5R~
"                 7  8  _    _  _  _    _  5  2\n");               //~v0.5R~
HELPMSG                                                            //~v0.5R~
"                 2  _  _    _  5  _    _  _  3\n",                //~v0.5R~
"                 2  _  _    _  5  _    _  _  3\n");               //~v0.5R~
HELPMSG                                                            //~v0.5R~
"                 _  _  _    4  _  6    _  _  _\n",                //~v0.5R~
"                 _  _  _    4  _  6    _  _  _\n");               //~v0.5R~
HELPMSG                                                            //~v0.5R~
"               #==============================\n",                //~v0.5R~
"               #==============================\n");               //~v0.5R~
HELPMSG                                                            //~v0.5R~
"                 _  _  1    _  _  _    4  _  _\n",                //~v0.5R~
"                 _  _  1    _  _  _    4  _  _\n");               //~v0.5R~
HELPMSG                                                            //~v0.5I~
"\n",                                                              //~v0.5I~
"\n");                                                             //~v0.5I~
HELPMSG                                                            //~v0.5I~
"  (Ex.2)       # Ex (20) 4x4\n",                                  //~v0.5R~
"  (例2)        # 例題 20。4x4\n");                                //~v0.5R~
HELPMSG                                                            //~v0.5I~
"                 _  8  7  _   16  2  _ 14   10  _  9  3    _  5  4  _\n",//~v0.5R~
"                 _  8  7  _   16  2  _ 14   10  _  9  3    _  5  4  _\n");//~v0.5I~
HELPMSG                                                            //~v0.5I~
"                 4  _  _  2    _  9  8  _    _ 11 13  _    3  _  _  7\n",//~v0.5I~
"                 4  _  _  2    _  9  8  _    _ 11 13  _    3  _  _  7\n");//~v0.5I~
HELPMSG                                                            //~v0.5I~
"                 5  _  1  _    _  7  _  4    8  _ 16  _    _ 15  _  2\n",//~v0.5R~
"                 5  _  1  _    _  7  _  4    8  _ 16  _    _ 15  _  2\n");//~v0.5I~
HELPMSG                                                            //~v0.5I~
"                 _ 10  _  9    _  _ 15  _    _  1  _  _   11  _  6  _\n",//~v0.5R~
"                 _ 10  _  9    _  _ 15  _    _  1  _  _   11  _  6  _\n");//~v0.5I~
HELPMSG                                                            //~v0.5I~
"               #======================================================\n",//~v0.5R~
"               #======================================================\n");//~v0.5R~
HELPMSG                                                            //~v0.5I~
"                 3  _  _  _    7  _  4  _    _  5  _ 10    _  _  _ 14\n",//~v0.5R~
"                 3  _  _  _    7  _  4  _    _  5  _ 10    _  _  _ 14\n");//~v0.5I~
HELPMSG
"\n",
"\n");
HELPMSG
"             .Space line is ignored,first '#' means comment line.\n",
"             .空白行は無視されます、最初が '#' はコメント行です。\n");
HELPMSG
//"             .Another input format is 81 byte continuous digit string per line.\n",//~v0.5R~
//"             .1行に81個の連続した数字の文字列を指定する形式でもOKです。\n");//~v0.5R~
"             .Another input format is %d byte continuous digit string per line.\n"//~v0.5R~
"              Use hex notation for number over 9(10-->a,16-->g).\n",//~v0.5I~
"             .3 x 3 の場合１行に全データを連続数字列として指定する形式もOKです\n");//~v0.5R~
#ifdef XNP_MAKE                                                    //~v0.5I~
HELPMSG
"             .A file may contain multiple quetion/patern data.\n",
"             .ファイルには複数の問題或いはパターンデータを書けます。\n");
#else                                                              //~v0.5I~
	HELPMSG                                                        //~v0.5I~
	"             .A file may contain multiple quetion data.\n",   //~v0.5R~
	"             .ファイルには複数の問題データを書けます。\n");   //~v0.5R~
#endif                                                             //~v0.5I~
                                                                   //~v0.5I~
#ifdef XNP_MAKE                                                    //~v0.5I~
HELPMSG
"             .Non zero digit means the point where digit is placed.\n",
"             .問題作成のパターンデータの場合設定したい所に 0 以外の数字を置く。\n");
HELPMSG
" When too long time is expired,retry after break(Ctrl+C).\n",
" 問題作成で時間がかかり過ぎるようなら、一旦ブレーク(Ctrl+C)して再試行してみて\n");
HELPMSG
" Random-number is used,so another seed may change result.\n",
" 下さい。乱数を使用しているので種を変えて与えるのも方法です。\n");
#endif                                                             //~v0.5I~
	return;
}//help
//*************************************************************
int xnpansmain(char *Pfnm)
{
//	int  datatbl[9][9];     	//number place	init data table    //~v0.5R~
	int  datatbl[MM_MAXN][MM_MAXN];     	//number place	init data table//~v0.5I~
	NPWORKT npwt;			//worktbl
    int *pi,qcnt,failedcnt;
	FILE *pfh;
//**********************
    if (!(pfh=fopen(Pfnm,"r")))
    	uerrexit("%s Open failed",0,
        			Pfnm);
    if (!(Soptions & XNP_PILOT))
    	Soptions|=(XNP_PILOT|XNP_PILOTNOMSG);
	Soptions|=(Srcmaxl<<12);                                       //~v1.1R~
    pi=&datatbl[0][0];
    if (!Srepeatmax)                                               //~v0.1I~
    	Srepeatmax=ANS_TIMEOUT;                                    //~v0.1I~
    if (!Stmsgfreq)                                                //~v0.1I~
    	Stmsgfreq=ANS_MSGFREQ;                                     //~v0.1I~
	for (qcnt=0,failedcnt=0;;)	//until eof
    {
        if (xnpreaddata(pfh,pi))
        	break;
		qcnt++;
    	if (xnpgetanswer(Soptions & XNP_SOLVMASK,pi,&npwt,Stmsgfreq,Srepeatmax))//~v0.1R~
        	failedcnt++;
	}
    if (qcnt>1)
    	uerrmsg("Result: %d success in %d questions",
    	        "結果: %d 問 成功 ( %d 問中)",
					qcnt-failedcnt,qcnt);
    fclose(pfh);
    return failedcnt;
}//xnpmain
//*********************
//*read initial data **
//*********************
int  xnpreaddata(FILE *Ppfh,int *Pdata)
{
#define BUFFSZ 512
    char buff[BUFFSZ];
#define MAXNUMSTRSZ 5
//  char numstr[9][MAXNUMSTRSZ],*pc,*pce;                          //~v0.5R~
    char numstr[MM_MAXN][MAXNUMSTRSZ],*pc,*pce;                    //~v0.5I~
    int ii,jj,*pi,fldno,len,soffs;
    int mm_maxn=0;                                                 //~v0.5I~
//************
//  for (ii=0,pi=Pdata;ii<9;)                                      //~v0.5R~
    for (ii=0,pi=Pdata;ii<MM_MAXN;)                                //~v0.5I~
    {
    	if (!fgets(buff,BUFFSZ,Ppfh))	//read 1 line
        	break;

        len=strlen(buff)-1;
        if (*(buff+len)=='\n')
        	*(buff+len)=0;
        if (Soptions & XNP_PRINTIDATA)
            uerrmsg("===>%s",0,
                        buff);
		soffs=strspn(buff," ");
		pc=buff+soffs;
        pce=strpbrk(pc," \t");
        if (*pc=='#')
            continue;
	  	if (((ULONG)pce-(ULONG)pc)==81)	//81 digt and lf           //~v0.5R~
        {
			for (jj=0;jj<81;jj++,pi++,pc++)                        //~v0.5R~
            {
                if (*pc>='0' && *pc<='9')
    	    		*pi=*pc-'0';
                else
                	*pi=0;
            }
	        ii=9;                                                  //~v0.5R~
            Gmm_base=3;                                            //~v0.5I~
            break;		//return
        }
//printf("data=%s\n",buff);
//      fldno=sscanf(buff,"%s %s %s %s %s %s %s %s %s",            //~v0.5R~
//                          numstr[0],numstr[1],numstr[2],         //~v0.5R~
//                          numstr[3],numstr[4],numstr[5],         //~v0.5R~
//                          numstr[6],numstr[7],numstr[8]);        //~v0.5R~
        fldno=sscanf(buff,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",//~v0.5R~
                            numstr[ 0],numstr[ 1],numstr[ 2],numstr[ 3],//~v0.5I~
                            numstr[ 4],numstr[ 5],numstr[ 6],numstr[ 7],//~v0.5I~
                            numstr[ 8],numstr[ 9],numstr[10],numstr[11],//~v0.5R~
                            numstr[12],numstr[13],numstr[14],numstr[15],//~v0.5R~
                            numstr[16],numstr[17],numstr[18],numstr[19],//~v0.5I~
                            numstr[20],numstr[21],numstr[22],numstr[23],//~v0.5I~
                            numstr[24]);    //max 5*5              //~v0.5I~
        if (fldno<=0)	//no data or all space
            continue;
        if (!mm_maxn)   //1st time                                 //~v0.5I~
        {                                                          //~v0.5I~
            if(fldno==3*3)                                         //~v0.5I~
	            Gmm_base=3;                                        //~v0.5I~
			else                                                   //~v0.5I~
			if (fldno==4*4)                                        //~v0.5R~
	            Gmm_base=4;                                        //~v0.5I~
            else                                                   //~v0.5I~
			if (fldno==5*5)                                        //~v0.5I~
	            Gmm_base=5;                                        //~v0.5I~
            else                                                   //~v0.5I~
        		uerrexit("Maxtrix size err,9 or 16 or 25 number per line is OK\n%s",//~v0.5I~
							"行列サイズは 9(3*3),16(4*4),25(5*5)でなければなりません。\n%s",//~v0.5I~
            				buff);                                 //~v0.5I~
            mm_maxn=fldno;                                         //~v0.5I~
        }                                                          //~v0.5I~
//		if (fldno!=9)                                              //~v0.5R~
//		if (fldno!=MM_MAXN)                                        //~v0.5R~
  		if (fldno!=mm_maxn)                                        //~v0.5I~
        	uerrexit("data cnt err(prev line is %d)\n%s",          //~v0.5R~
					"項目数エラー(前の行は %d)\n%s",               //~v0.5I~
            			mm_maxn,buff);                             //~v0.5R~
//		for (jj=0,pc=&numstr[0][0];jj<9;jj++,pi++,pc+=MAXNUMSTRSZ) //~v0.5R~
//  	for (jj=0,pc=&numstr[0][0];jj<MM_MAXN;jj++,pi++,pc+=MAXNUMSTRSZ)//~v0.5R~
    	for (jj=0,pc=&numstr[0][0];jj<mm_maxn;jj++,pi++,pc+=MAXNUMSTRSZ)//~v0.5I~
        	*pi=atoi(pc);
        ii++;
        if (ii==mm_maxn)                                           //~v0.5I~
            break;                                                 //~v0.5I~
    }
    if (!ii)
    	return -1;			//eof
//  if (ii<9)                                                      //~v0.5R~
//      uerrexit("required just 9 line for each probrem data",0);  //~v0.5R~
//  if (ii<MM_MAXN)                                                //~v0.5R~
    if (ii<mm_maxn)                                                //~v0.5I~
        uerrexit("required just %d line for each probrem data",0,  //~v0.5I~
					mm_maxn);                                      //~v0.5R~
	Gmm_maxn=(Gmm_base*Gmm_base);    //matrix size                 //~v0.5M~
	Gmm_totn=(Gmm_maxn*Gmm_maxn);    //matrix total place count    //~v0.5M~
	Gmm_next=(Gmm_maxn-Gmm_base);    //count on other box          //~v0.5M~
	Gmm_last=(Gmm_maxn-1);           //1 more residual             //~v0.5M~
	Gmm_all_candidate=((1<<Gmm_maxn)-1);	//candidate bit mask for all 9,8,...1//~v0.5I~
    return 0;
}//xnpreaddata
//*********************
//*make puzzle       **
//*********************
int xnpqmkmain(char *Ppfnm)
{
	FILE *pfh;
//	int  qpattbl[9][9];     	//patern reques table              //~v0.5R~
	int  qpattbl[MM_MAXN][MM_MAXN];     	//patern reques table  //~v0.5I~
	NPWORKT npwt;			//worktbl
    int *pi,rc;
    int actseed;		//output selected seed                     //~9B27I~
//**********************
//init
//patern specification
    if (!Srepeatmax)                                               //~v0.1I~
    	Srepeatmax=MAKE_TIMEOUT;                                   //~v0.1I~
    if (!Stmsgfreq)                                                //~v0.1I~
    	Stmsgfreq=MAKE_MSGFREQ;                                    //~v0.1I~
	rc=4;
    if (Ppfnm)
    {
    	pi=&qpattbl[0][0];
	    if (!(pfh=fopen(Ppfnm,"r")))
    		uerrexit("%s Open failed",0,
        				Ppfnm);
		for (;;)
        {
    		if (xnpreaddata(pfh,pi))			//fill initial data
            	break;
			if (rc=xnpmakequestion(Soptions & XNP_MAKEMASK,
				&npwt,pi,Ssetlimit,Stmsgfreq,Srepeatmax,Sseed,Splan,Slevel,&actseed),rc)//~9B27R~
                break;
		}
	    fclose(pfh);
    }
    else
		rc=xnpmakequestion(Soptions & XNP_MAKEMASK & ~XNP_RIGID,   //~v0.4R~
				&npwt,0,Ssetlimit,Stmsgfreq,Srepeatmax,Sseed,Splan,Slevel,&actseed);//~9B27R~
	if (rc)
		uerrexit("Sorry,Make failed,Try one more.",0);
	uerrmsg("Actualy used seed=%d",0,                              //~0116R~
    		actseed);                                              //~9B27I~
    return 0;
}//xnpqmkmain
//******************************************************************************//~v1.1I~
//*password chk *                                                  //~v1.1I~
//******************************************************************************//~v1.1I~
#define NP_KEYNAME   "WNPMFC"                                      //~v1.1I~
#define MY_SIGN        "木八小 学"                                 //~v1.1I~
#define PSWDSZ 64                                                  //~v1.1I~
static int ureg_keygetvalue(UCHAR *Pkeyname,UCHAR *Pkeyvalue,ULONG *Pvaluelen);//~v1.1R~
static int pswdchksub(char *Pkeyname,char *Pkeyvalue);             //~v1.1I~
static int pswdvalidate(char *Ppswd);                              //~v1.1R~
//******************************************************************************//~v1.1I~
//******************************************************************************//~v1.1I~
int pswdchk(void)                                                  //~v1.1R~
{                                                                  //~v1.1I~
	UCHAR keyvalue[PSWDSZ];                                        //~v1.1I~
//*********************                                            //~v1.1I~
    return pswdchksub(NP_KEYNAME,keyvalue);                        //~v1.1R~
}//pswdchk                                                         //~v1.1I~
//******************************************************************************//~v1.1I~
int  pswdchksub(char *Pkeyname,char *Pkeyvalue)                    //~v1.1R~
{                                                                  //~v1.1I~
	UCHAR pswd[PSWDSZ];                                            //~v1.1I~
    int rc;                                                        //~v1.1I~
	DWORD pswdsz;                                                  //~v1.1I~
    DWORD disp=0;                                                  //~v1.1I~
//*********************                                            //~v1.1I~
    pswdsz=sizeof(pswd);                                           //~v1.1I~
    rc=ureg_keygetvalue(Pkeyname,pswd,&pswdsz);                    //~v1.1I~
    if (!rc && !pswdvalidate(pswd))                                //~v1.1I~
    	return 0;		//pswd ok                                  //~v1.1R~
    return 4;                                                      //~v1.1R~
}//pswdchksub                                                      //~v1.1I~
//******************************************************************************//~v1.1I~
int ureg_keygetvalue(UCHAR *Pkeyname,UCHAR *Pkeyvalue,ULONG *Pvaluelen)//~v1.1I~
{                                                                  //~v1.1I~
    HKEY hkey=0;                                                   //~v1.1I~
    LONG rc,rcrc;                                                  //~v1.1I~
    ULONG dwtype;                                                  //~v1.1I~
//**************************                                       //~v1.1I~
    rc=RegOpenKeyEx(HKEY_CLASSES_ROOT,//parent key                 //~v1.1I~
                           (const char *)Pkeyname,      //keyname  //~v1.1I~
                           0,                //rsv                 //~v1.1I~
                           KEY_ALL_ACCESS|KEY_EXECUTE|KEY_SET_VALUE,//access option//~v1.1I~
                           &hkey);			//output handle        //~v1.1I~
//  printf("OpenKey=%s:rc=%d,hkey=%08x\n",Pkeyname,rc,hkey);       //+v2acR~
    if (rc!=ERROR_SUCCESS)                                         //~v1.1I~
    	return rc;                                                 //~v1.1I~
    rcrc=RegQueryValueEx(hkey,        //key                        //~v1.1I~
                       "",           //name                        //~v1.1I~
                       0,                //rsv                     //~v1.1I~
                       &dwtype,           //data type              //~v1.1I~
                       Pkeyvalue,           //value                //~v1.1I~
                       Pvaluelen);                                 //~v1.1I~
//  printf("QueryValue:rc=%d,value=%s,type=%08x,len=%d\n",rc,Pkeyvalue,dwtype,*Pvaluelen);//+v2acR~
    rc=RegCloseKey(hkey);       //key                              //~v1.1I~
//  printf("CloseKey:rc=%d\n",rc);                                 //+v2acR~
    return rcrc;                                                   //~v1.1I~
}//ureg_keygetvalue                                                //~v1.1I~
//******************************************************************************//~v1.1I~
//int  pswdvalidate(char *Ppswd)                                   //~v2acR~
//{                                                                //~v2acR~
//    int ii,jj;                                                   //~v2acR~
//    char *pc;                                                    //~v2acR~
//    char pswdwk[PSWDSZ];                                         //~v2acR~
////************************                                       //~v2acR~
//    if (strlen(Ppswd)<6)                                         //~v2acR~
//        return 4;                                                //~v2acR~
//    sscanf(Ppswd,"%x",pswdwk);                                   //~v2acR~
//    *(pswdwk+4)=*(pswdwk+2);    //reverse seq                    //~v2acR~
//    *(pswdwk+5)=*(pswdwk+1);    //reverse seq                    //~v2acR~
//    *(pswdwk+6)=*(pswdwk+0);    //reverse seq                    //~v2acR~
//    if (!memcmp(pswdwk+3,MY_SIGN,4))    //special ok             //~v2acR~
//        return 0;                                                //~v2acR~
//    memcpy(pswdwk,Ppswd,6);                                      //~v2acR~
//    if (*pswdwk<='9')   //1st should not be numeric              //~v2acR~
//        return 4;                                                //~v2acR~
//    if (*(pswdwk+5)<='9')   //1st should not be numeric          //~v2acR~
//        return 4;                                                //~v2acR~
//    for (ii=0,jj=0,pc=pswdwk;ii<6;ii++,pc++)                     //~v2acR~
//        jj+=*pc;                                                 //~v2acR~
//    return jj%19;                                                //~v2acR~
//}                                                                //~v2acR~
int  pswdvalidate(char *Ppswd)                                     //~v2acI~
{                                                                  //~v2acI~
    int  pswdwk=0;                                                 //~v2acI~
//************************                                         //~v2acI~
    sscanf(Ppswd,"%x",&pswdwk);                                    //~v2acI~
    if ((pswdwk&0x3000)==0x3000)                                   //~v2acI~
    	return 0;                                                  //~v2acI~
    return 4;                                                      //~v2acI~
}                                                                  //~v2acI~
