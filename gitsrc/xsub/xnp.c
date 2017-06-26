//CID://+v0.4R~:                                                   //+v0.4R~
//*************************************************************
//*XNP.c   Number Place Puzzle
//*format
//*      xnp  datafile
//*           datafile fmt
//*            9*9 matrix seperated by comma.set '0' for space.
//*            a line is  like as  7,8,0,0,0,0,0,5,2
//*************************************************************
//*000104 xnp v0.1:no rgid when no patern data                     //+v0.4I~
//*000103 xnp v0.1:Win(C++) support                                //~v0.1I~
//*v100 first
//*************************************************************
#define VERSION  "v1.0"
#define PGMID    "XNP"
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
  #else
  #endif
#endif
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
//********************
#include "xnpsub.h"
#include "xnpsub2.h"
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
static  int  Srchkmaxlevel;          		//strategy of search pos for make
static  UCHAR Slevel;
//********************
void titlemsg(void);
void help(void);
int  xnpansmain(char *Pfnm);
int xnpqmkmain(char *pfnm);
int  xnpreaddata(FILE *Ppfh,int *Pdata);
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
        		help();
        		exit(8);
                break;
    		case 'D':       //set limit
                Ssetlimit=atoi(cptr+1);
                if (!Ssetlimit)
                	Ssetlimit=SETMAX;
                else
	                if (Ssetlimit<3)
                    	uerrexit("Limit should be >=3.",0);
                break;
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
                    	Splan=-9;                                  //~0116M~
        			break;                                         //~0116M~
    			case 'X':		//maximum                          //~0116M~
            		atoiwk=atoi(cptr+2);                           //~0116M~
                	if (atoiwk)                                    //~0116M~
    					Splan=atoiwk;                              //~0116M~
                    else                                           //~0116M~
    					Splan=9;                                   //~0116M~
        			break;                                         //~0116M~
				default:                                           //~0116M~
                	uerrexit("Make strategy option parm(%s) err",0,//~0116M~
                                    cptr);                         //~0116M~
                }                                                  //~0116M~
                break;                                             //~0116M~
    		case 'M':          // /M
                Sqmakesw=1;
            	Slevel=(UCHAR)toupper(*(cptr+1));
                if (Slevel)
                    if (!(Slevel=='H' || Slevel=='M' || Slevel=='E'))
                        uerrexit("Make level option(%s) err",0,
                                        cptr+1);
                break;
    		case 'P':
                Soptions|=XNP_PILOT;
                break;
    		case 'R':			// /R
                Soptions|=XNP_REDUNDANTCK;
                Srchkmaxlevel=atoi(cptr+1);
                break;
    		case 'S':
            	atoiwk=atoi(cptr+1);
                if (atoiwk)
                	Sseed=atoiwk;
                break;
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
HELPMSG
"This program solves Number Place Puzzle,or make Puzzle automaticaly.\n",
"ナンバープレース パズルを解いたり問題を自動生成したりするプログラムです\n");
HELPMSG
"\n",
"\n");
HELPMSG
"format: %s [file-name] [/option ...]\n",
"形式  : %s [ファイル名] [/オプション ...]\n",
				PGMID);
HELPMSG
"  file-name:Problem data or optional patern data to make puzzle.\n",
" ファイル名:問題データ或は問題作成のときのオプションのパターンデータ。\n");
HELPMSG
".option for solution.\n",
"・解答用のオプション。\n");
HELPMSG
"   /R      : Redundancy chk.\n",
"   /R      : Redundancy chk;無くてもよいデータの有無をチェック。\n");
HELPMSG
".option for making puzzle.\n",
"・問題作成用のオプション。\n");
HELPMSG
"   /Dcnt   : Density;max count in each box,row,col.\n",
"   /Dcnt   : Density;同じ行、列、箱に最大いくつまで置いてよいか。\n");
HELPMSG
"             Default is 5,Minimum 3.\n",
"             省略値は 5 、最小値は 3。\n");
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
HELPMSG
"   /P      : Pilot;print intermediate step.\n",
"   /P      : Pilot;解答にいたるまでのまでの途中の1手1手を出力。\n");
HELPMSG                                                            //~v0.1M~
"   /Tl[/f] : Timeout limit.Default is in parenthesis.\n",         //~v0.1M~
"   /Tl[/f] : Timeout;制限時間(秒),括弧内は解答/作成それぞれのモードでの省略値。\n");//~v0.1R~
HELPMSG                                                            //~v0.1M~
"             l:limit seconds(%d/%d sec),f:iteration msg frequency(%d/%d sec).\n",//~v0.1R~
"             l:制限時間(%d/%d秒), f:経過MSGの表示頻度(%d/%d秒毎)。\n",//~v0.1R~
				ANS_TIMEOUT,MAKE_TIMEOUT,ANS_MSGFREQ,MAKE_MSGFREQ);//~v0.1I~
HELPMSG
"   /Yx,/Nx : Yes/No:x is following option.Default is in ( )\n",
"   /Yx,/Nx : 次の様なオプションが Yes か No か を指定する。括弧内は省略値\n");
HELPMSG
"      x:p  : print data file contents.\n",
"      x:p  : データファイルの内容を出力する.(/Yp)\n");
HELPMSG                                                            //~v0.1I~
"      x:r  : Accept pattern as firmed.loosely use pattern data if /Nr.(/Yr)\n",//~v0.1R~
"      x:r  : パターンデータを遵守して作成する。/Nrのときは目安とする。(/Yr)\n");//~v0.1R~
HELPMSG                                                            //~v0.1I~
"      x:s  : Sort probrem data.(/Ys for Make mode,/Ns for Answer mode)\n",//~v0.1I~
"      x:s  : 問題データを整列する.(作成モードで/Ys、解答モードで/Ns)\n");//~v0.1I~
HELPMSG
"  (Ex.) : %s xnpdata.#99 /p;  %s /m /d3; %s /m pat#01 /Np; \n",
"  (例)  : %s xnpdata.#99 /p;  %s /m /d3; %s /m pat#01 /Np; \n",
				PGMID,PGMID,PGMID);
HELPMSG
".data fmt   : specify 9 x 9 matrix.\n",
"・データ形式 : 9 x 9 の行列を指定します。\n");
HELPMSG
"  (Ex.)        # Ex (19)\n",
"  (例)         # 例題 19。\n");
HELPMSG
"                 7  8  _    _  _  _    _  5  2\n",
"                 7  8  _    _  _  _    _  5  2\n");
HELPMSG
"                 2  _  _    _  5  _    _  _  3\n",
"                 2  _  _    _  5  _    _  _  3\n");
HELPMSG
"                 _  _  _    4  _  6    _  _  _\n",
"                 _  _  _    4  _  6    _  _  _\n");
HELPMSG
"               #==============================\n",
"               #==============================\n");
HELPMSG
"                 _  _  1    _  _  _    4  _  _\n",
"                 _  _  1    _  _  _    4  _  _\n");
HELPMSG
"\n",
"\n");
HELPMSG
"             .Space line is ignored,first '#' means comment line.\n",
"             .空白行は無視されます、最初が '#' はコメント行です。\n");
HELPMSG
"             .Another input format is 81 byte continuous digit string per line.\n",
"             .1行に81個の連続した数字の文字列を指定する形式でもOKです。\n");
HELPMSG
"             .A file may contain multiple quetion/patern data.\n",
"             .ファイルには複数の問題或いはパターンデータを書けます。\n");
HELPMSG
"             .Non zero digit means the point where digit is placed.\n",
"             .問題作成のパターンデータの場合設定したい所に 0 以外の数字を置く。\n");
HELPMSG
" When too long time is expired,retry after break(Ctrl+C).\n",
" 問題作成で時間がかかり過ぎるようなら、一旦ブレーク(Ctrl+C)して再試行してみて\n");
HELPMSG
" Random-number is used,so another seed may change result.\n",
" 下さい。乱数を使用しているので種を変えて与えるのも方法です。\n");
	return;
}//help
//*************************************************************
int xnpansmain(char *Pfnm)
{
	int  datatbl[9][9];     	//number place	init data table
	NPWORKT npwt;			//worktbl
    int *pi,qcnt,failedcnt;
	FILE *pfh;
//**********************
    if (!(pfh=fopen(Pfnm,"r")))
    	uerrexit("%s Open failed",0,
        			Pfnm);
    if (!(Soptions & XNP_PILOT))
    	Soptions|=(XNP_PILOT|XNP_PILOTNOMSG);
	Soptions|=(Srchkmaxlevel<<12);
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
    char numstr[9][MAXNUMSTRSZ],*pc,*pce;
    int ii,jj,*pi,fldno,len,soffs;
//************
    for (ii=0,pi=Pdata;ii<9;)
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
		if (((ULONG)pce-(ULONG)pc)==81)	//81 digt and lf
        {
			for (jj=0;jj<81;jj++,pi++,pc++)
            {
                if (*pc>='0' && *pc<='9')
    	    		*pi=*pc-'0';
                else
                	*pi=0;
            }
            ii=9;
            break;		//return
        }
//printf("data=%s\n",buff);
        fldno=sscanf(buff,"%s %s %s %s %s %s %s %s %s",
                    		numstr[0],numstr[1],numstr[2],
                    		numstr[3],numstr[4],numstr[5],
                    		numstr[6],numstr[7],numstr[8]);
        if (fldno<=0)	//no data or all space
            continue;
		if (fldno!=9)
        	uerrexit("data format err;%s",0,
            			buff);
		for (jj=0,pc=&numstr[0][0];jj<9;jj++,pi++,pc+=MAXNUMSTRSZ)
        	*pi=atoi(pc);
        ii++;
    }
    if (!ii)
    	return -1;			//eof
    if (ii<9)
        uerrexit("required just 9 line for each probrem data",0);
    return 0;
}//xnpreaddata
//*********************
//*make puzzle       **
//*********************
int xnpqmkmain(char *Ppfnm)
{
	FILE *pfh;
	int  qpattbl[9][9];     	//patern reques table
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
		rc=xnpmakequestion(Soptions & XNP_MAKEMASK & ~XNP_RIGID,   //+v0.4R~
				&npwt,0,Ssetlimit,Stmsgfreq,Srepeatmax,Sseed,Splan,Slevel,&actseed);//~9B27R~
	if (rc)
		uerrexit("Sorry,Make failed,Try one more.",0);
	uerrmsg("Actualy used seed=%d",0,                              //~0116R~
    		actseed);                                              //~9B27I~
    return 0;
}//xnpqmkmain
