//CID://+v026R~:                                                   //+v026R~
//*************************************************************
//*XNPSUB2.c   Number Place Puzzle(Make puzzle)
//*************************************************************
//v026:051105 (BUG)lmay loop when patern specified make            //+v026I~
//wnp-v010:051003 Static init missing cause 2nd result is not same as 1st even seed is same//~v010I~
//wnp-v009:051002 rand dose not same rand sequence for same seed when multithread//~v009I~
//*v104 new pattern for each level matching                        //~v104I~
//*v103 protect copy(set same num on top-right of box3 and box7)   //~v103R~
//*v102 output seed for retry                                      //~v102I~
//*v101 make performance;once create random pater data,then try make//~v101I~
//*v100 first
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
#define MINSELECTSTART    18	//men method after this number of place filled
#define LEVELCHNGPAT      20	//if over change pattern data      //~v104I~
//********************
#ifdef WNP_CALL                                                    //~v104I~
	int	GblSubthreadStopReq;	//thread communication with wnp    //~v104R~
#endif                                                             //~v104I~
static  int Stestsw;
static  int Smask[10]={0,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x100};

static  int Srigidsw;
static  int Ssetlimit;
static  int Spospatcnt;   		                                   //~v104R~
static  int Spospatcnt_u;       //by the user                      //~v104I~
static  int Spospatsw;                                             //~v103I~
static  int *Spospattbl;
static  int Stmsgfreq;		//loop msg frequency
static  int Srepeatmax;		//loop max
static  int Splan;			//strategy of search pos
static  unsigned int Sloopcnt;
static  time_t Stm0,Stm;
static int SrandR=1;                                               //~v009I~
static int Stotloop=0;                                             //~v010I~
//********************
int xnpmqlvl(int Popt,PNPWORKT Ppnpwt,int Plevel,int *Pqouttbl,int Prandompattern);//~v104R~
int xnpmqsub(PNPWORKT Ppnpwt,int Psw1st);                          //~v103R~
void xnprandseq(int Pmax,int *Prandseq);
int  xnpsrchpos(PNPWORKT Ppnpwt,int *Pprow,int *Ppcol,int *Pprow2,int *Ppcol2,int Psw1st);//~v103R~
int xnpsrchpatpos(PNPWORKT Ppnpwt,int *Pprow,int *Ppcol);          //~v103R~
int xnpsrchpatpos1st(PNPWORKT Ppnpwt,int *Pprow,int *Ppcol,int Ptype);//~v103R~
int xnpmqsetuppat(PNPWORKT Ppnpwt,int *Ppatdata,int Psetlimit);    //~v104R~
void usrand(int seed);                                             //~v009I~
int  urand(void);                                                  //~v009I~
//*************************************************************
//***************************************************************
//* search candidate for make puzzle
//* rc:0 ok,-1:end,4:err
//***************************************************************
int xnpmakequestion(int Popt,PNPWORKT Ppnpwt,int *Ppattbl,int Psetlimit,
					int Ptmsgfreq,int Prepeatmax,int Pseed,int Pplan,UCHAR Plevel,int *Pactseed)//~v102R~
{
	NPWORKT npwt0;                                                 //~v104R~
    time_t tm;
    int  *pi,rc,randompattern;                                     //~v104R~
	int  qouttbl[9][9];     	//number place	init data table
    UINT seed;                                                     //~v102I~
//************
 	Spospatcnt=0;                          //                      //~v010I~
 	Spospatcnt_u=0;       //by the user    //                      //~v010I~
	Stotloop=0;                                                    //~v010I~
                                                                   //~v010I~
	Stestsw=Popt & XNP_TEST;
	Srigidsw=Popt & XNP_RIGID;
    Stmsgfreq=Ptmsgfreq;
    Srepeatmax=Prepeatmax;
    Sloopcnt=0;
    Splan=Pplan;
    Ssetlimit=Psetlimit;	//limit count in same row/col/box      //~v101M~
    if (Pseed)
    	tm=(time_t)Pseed;
    else
        time(&tm);
    seed=(UINT)((long)tm & 0x7fff);                                //~v102I~
    *Pactseed=seed;                                                //~v102I~
//  srand(seed);                                                   //~v009R~
    usrand(seed);                                                  //~v009I~

//printf("plan=%d,cnt=%d\n",Splan,Spospatcnt);
//init npwt
    memset(qouttbl,0,sizeof(qouttbl));
    pi=&qouttbl[0][0];
    xnpansinit((Popt & ~(XNP_PILOT|XNP_SORT))|XNP_SOLOFMAKE,pi,Ppnpwt);//~v104R~
    Ppnpwt->stat|=STAT_MAKE;        //make mode

    time(&Stm0);		//start time                               //~v101R~
    npwt0=*Ppnpwt;
    for (;;)                                                       //~v101I~
    {                                                              //~v101I~
	    *Ppnpwt=npwt0;                                             //~v101I~
		randompattern=xnpmqsetuppat(Ppnpwt,(int*)Ppattbl,Psetlimit);//~v104R~
		rc=xnpmqlvl(Popt & ~XNP_SORT,Ppnpwt,Plevel,pi,randompattern);	//difficulty level matching//~v104R~
        if (rc!=-2)				//level unmatch;retry by another pattern//~v104I~
        {                                                          //~v104I~
            if (Ppattbl||Splan)     //pattern specified            //~v104R~
                break;                                             //~v104R~
            if (!rc)                                               //~v104R~
                break;                                             //~v104R~
		}                                                          //~v104I~
	    memset(qouttbl,0,sizeof(qouttbl));                         //~v101I~
    }                                                              //~v101I~
    time(&Stm);
    uerrmsg("=== Make Question == %5d times repeated,%5d sec expired. ===",
            "=== 問題の作成 == %5d 回繰り返し,%5d 秒使用 ===",
			Sloopcnt,(int)((long)Stm-(long)Stm0));
	if (!rc)
    {
        pi=&qouttbl[0][0];
        if (!(Popt & XNP_PILOT))
            Popt|=(XNP_PILOT|XNP_PILOTNOMSG);
        Popt|=XNP_ANSOFMAKE;
        xnpgetanswer(Popt,pi,Ppnpwt,0,0); //success                //~v104R~
    }
    return rc;
}//xnpmakequestion
//***************************************************************  //~v101I~
//* level matching of maked question with request level            //~v101I~
//* rc:0 ok,-1:end,-2:retry by new pattern,4:err                   //~v104R~
//***************************************************************  //~v101I~
int xnpmqlvl(int Popt,PNPWORKT Ppnpwt,int Plevel,int *Pqouttbl,int Prandompattern)//~v104R~
{                                                                  //~v101I~
	NPWORKT npwt0,npwt;                                            //~v101R~
	PM99  pm99;                                                    //~v101I~
    int  *pi,ii,jj,rc,level,retrycnt;                              //~v104R~
//*********************                                            //~v101I~
    npwt0=*Ppnpwt;  //save initial status                          //~v101I~
    for (retrycnt=0;;retrycnt++)        //retry until level match  //~v104R~
    {                                                              //~v101M~
    	*Ppnpwt=npwt0;				//reset by org                 //~v101M~
        rc=xnpmqsub(Ppnpwt,Prandompattern);		//1st srch pos     //~v104R~
//printf("rc=%d Plevel=%c,level=%04x\n",rc,Plevel,Ppnpwt->level);  //~v104R~
        if (rc)                                                    //~v101M~
        	break;                                                 //~v101M~
//get question table                                               //~v101M~
        pm99=&Ppnpwt->m99[0][0];     //answer                      //~v101M~
        pi=Pqouttbl;                                               //~v101I~
        for (ii=0;ii<9;ii++)                                       //~v101M~
            for (jj=0;jj<9;jj++,pi++,pm99++)                       //~v101M~
                if (pm99->dlvl==LEVEL_INIT)                        //~v101M~
                    *pi=pm99->fnum;                                //~v101M~
                else                                               //~v101M~
                    *pi=0;      //for retry case                   //~v101M~
		if (!Plevel)	//no level specification                   //~v101M~
        	break;                                                 //~v101M~
        pi=Pqouttbl;                                               //~v101I~
        rc=xnpgetanswer(Popt|(XNP_PILOT|XNP_PILOTNOMSG|XNP_ANSOFMAKE|XNP_NOPRINTIN|XNP_NOPRINTOUT),//~v101M~
						pi,&npwt,0,0); //success                   //~v104R~
        level=npwt.level;                                          //~v101M~
//printf("rc=%d level=%04x\n",rc,level);                           //~v101M~
        if (level & (LEVEL_HARD_S|LEVEL_HARDP1_S|LEVEL_HARDP2_S))  //~v101M~
        {                                                          //~v101M~
        	if (Plevel=='H')                                       //~v101M~
            	break;                                             //~v101M~
		}                                                          //~v101M~
        else                                                       //~v101M~
        	if (level & LEVEL_MEDIUM_S)                            //~v101M~
            {                                                      //~v101M~
        		if (Plevel=='M')                                   //~v101M~
            		break;                                         //~v101M~
			}                                                      //~v101M~
            else                                                   //~v101M~
	        	if (level & LEVEL_EASY_S)                          //~v101M~
        			if (Plevel=='E')                               //~v101M~
            			break;                                     //~v101M~
        time(&Stm);                                                //~v101M~
        uerrmsg("=== Made,but level unmatch,try next(%5d sec expired). ===",//~v101M~
                "=== レベルが合わないのでリトライします(%5d 秒経過) ===",//~v101M~
                (int)((long)Stm-(long)Stm0));                      //~v101M~
		if (Prandompattern)                                        //~v104I~
	    	if (retrycnt>=LEVELCHNGPAT)                            //~v104R~
            {                                                      //~v104I~
//printf("new pattern\n");            	                           //~v104R~
    			return -2;				//request change max       //~v104I~
			}                                                      //~v104I~
	}                                                              //~v101M~
    return rc;                                                     //~v101I~
}//xnpmqlvl                                                        //~v101I~
//***************************************************************
//* search candidate for make puzzle
//* rc:0 ok,-1:end,4:err
//***************************************************************
int xnpmqsub(PNPWORKT Ppnpwt,int Psw1st)                           //~v103R~
{
    int   row,col,kk,ccnt,cmsk,rc,num;
    int   *pic1,*pic2,*pic20,*pic3;
    int   row2,col2;                                               //~v103R~
    PNPWORKT pnpwt;
//************
//malloc recursive work and save data
	pnpwt=(PNPWORKT)umalloc((UINT)(sizeof(NPWORKT)+sizeof(int)*3*9));
    pic1=(int*)((ULONG)pnpwt+sizeof(NPWORKT));	//candidate list
    pic2=pic20=pic1+9;            	//candidate list random seq
    pic3=pic2+9;   		         	//random seq

	*pnpwt=*Ppnpwt;	//save for retry
//determin point to be filled
    if ((rc=xnpsrchpos(Ppnpwt,&row,&col,&row2,&col2,Psw1st))!=0)   //~v103R~
    {
//printf("srchpos faile rc=%d\n",rc);                              //~v103R~
//xnpprintnum(0,0,0,Ppnpwt,0,0);   //print initial data
        ufree(pnpwt);
    	return rc;					//stepback;
    }
    cmsk=Ppnpwt->m99[row][col].cmsk;
//listup candidate
	ccnt=0;
    for (kk=1;kk<=9;kk++)
        if (cmsk & Smask[kk])
            *(pic1+ccnt++)=kk;
//random seq of candidate
	xnprandseq(ccnt,pic3);			//get random seq
    for (kk=0;kk<ccnt;kk++)
    	*pic2++=*(pic1+*pic3++);	//random seq of candidate no
//try up to end
	for (kk=0,pic2=pic20;kk<ccnt;kk++,pic2++)
    {
    	num=*pic2;
	    *Ppnpwt=*pnpwt;	//parm value
  		rc=xnpfix(row,col,num,Ppnpwt,LEVEL_INIT,0);
//printf("make:init candidate seqno=%d (%d,%d),num=%d,rc=%d\n",Ppnpwt->seqno,row,col,num,rc);//~v104R~
//xnpprintcan(Ppnpwt);
		if (rc)					//dup or inconsistent(made candidate to 0)
        	continue;
    	if (row2>=0)		//patern srch                          //~v103I~
			xnpfix(row2,col2,num,Ppnpwt,LEVEL_INIT,0);             //~v103I~
//printf("getanswer seqno=%d\n",seqno);
	    rc=xnpsolution(Ppnpwt);
//printf("solution seqno=%d,rc=%d\n",Ppnpwt->seqno,rc);
//xnpprintcan(Ppnpwt);
        if (!rc)				//success
        	break;
		if (rc!=4 && rc!=12)//4:more required,8:data conflict,12:multiple solution
        	continue;	//try next data
    	Ppnpwt->stat &=~(STAT_MULTISOL|STAT_DATA_CONFLICT);        //~v1.2R~
//printf("level down\n");
        rc=xnpmqsub(Ppnpwt,0);	//level down                       //~v103R~
//printf("qmsrchc rc=%d\n",rc);
        if (rc<=0)		//ok or loop limit
        	break;
	}//all candidate at random
//printf("return rc=%d,seqno=%d\n",rc,Ppnpwt->seqno);
//if (Ppnpwt->seqno>70)
//    xnptrace(Ppnpwt);
//xnpprintcan(Ppnpwt);
	ufree(pnpwt);
    return rc;
}//xnpmqsub
//***************************************************************
//* randomize
//*   get random seq
//***************************************************************
void xnprandseq(int Pmax,int *Prandseq)
{
    int ii,randno,*pis,*pis0,*pise,*pit;
//*****************************
    if (Pmax==1)
    {
        *Prandseq=0;
        return;
    }
    pis0=pis=umalloc((UINT)(sizeof(int)*Pmax));
    pise=pis0+Pmax;
    for (ii=0;ii<Pmax;ii++)
    	*pis++=ii;
    pit=Prandseq;
    for (ii=Pmax;ii>1;ii--)
    {
//      randno=rand()%ii;                                          //~v009R~
    	randno=urand()%ii;                                         //~v009I~
        pis=pis0+randno;
        *pit++=*pis;
        for (;++pis<pise;)
        	*(pis-1)=*pis;        //drop used and shift
    }
    *pit=*pis0;				//last one
    ufree(pis0);
    return;
}//xnprandseq
//***************************************************************
//* search free pos randomly
//*   max 5 in a box/line
//* rc:4 no free pos found,8:patern exausted,-1:loop limit
//***************************************************************
int xnpsrchpos(PNPWORKT Ppnpwt,int *Pprow,int *Ppcol,int *Pprow2,int *Ppcol2,int Psw1st)//~v103R~
{
	PM99  pm99,pm990;
    int   ii,jj,kk,seqposno,seqno,entno,rc;                        //~v104R~
//*****************************
#ifdef WNP_CALL                                                    //~v104I~
	Sloopcnt++;                                                    //~v104M~
	if (GblSubthreadStopReq)	//thread communication with wnp    //~v104I~
        if (GblSubthreadStopReq==2)	//timeout                      //~v104I~
	    	uerrexit("Time Expired",                               //~v104I~
    	    		"タイムアウト");                               //~v104I~
        else                                                       //~v104I~
	    	uerrexit("Forced Thread Termination",                  //~v104R~
    	    		"強制終了");                                   //~v104R~
#else                                                              //~v104R~
	#define MSG_CHK_FREQ 10                                        //~v104R~
//  static int Stotloop;                                           //~v010R~
	static time_t Stottm0,Smsgtm;                                  //~v104I~
	static time_t tottm;                                           //~v104I~
                                                                   //~v104I~
	Sloopcnt++;                                                    //~v104I~
    if (!Stotloop)                                                 //~v104I~
        Smsgtm=time(&Stottm0);                                     //~v104I~
    if (!(++Stotloop % MSG_CHK_FREQ))                              //~v104R~
    {
        time(&tottm);                                              //~v104R~
        if (Stmsgfreq && tottm-Smsgtm>=Stmsgfreq)	//each msg freq//~v104R~
        {                                                          //~v104I~
        	fprintf(stderr,"processing ... %5d times trial,%4d sec expired.\n",
							Stotloop,(int)(tottm-Stottm0));        //~v104R~
	        Smsgtm=tottm;                                          //~v104I~
		}                                                          //~v104I~
        if (Srepeatmax && tottm-Stottm0>=Srepeatmax)               //~v104R~
        {                                                          //~v104I~
    		uerrmsg("Timeout;%5d sec expired. ===",                //~v104R~
		            "時間切れ;%5d 秒経過 ===",                     //~v104R~
					(int)(tottm-Stottm0));                         //~v104R~
    		return -1;				//stop calc                    //~v104R~
        }                                                          //~v104I~
    }                                                              //~v104M~
#endif                                                             //~v104I~
	*Pprow2=-1;			//id of no pattern                         //~v104M~
    seqno=Ppnpwt->seqno;
    pm990=&Ppnpwt->m99[0][0];     //answer
//determin point to be filled
    if (seqno>=81)
    {
		xnpprintcan(Ppnpwt);
        uerrexit("Int Logic Err;seqno >=81,posseq=%d",0,
					seqno);
    }
//printf("srch seqno=%d\n",seqno);
    if (Spospatcnt && Spospatcnt!=81)	//patern specified(except no patern and strategy)
    {
        for (;;)    //chk limit count                              //~v104I~
        {                                                          //~v104I~
            rc=1;                                                  //~v104R~
            if (Psw1st)     //1st time                             //~v104R~
                rc=xnpsrchpatpos1st(Ppnpwt,Pprow,Ppcol,0);//select top-right//~v104R~
            if (rc) //not random pattern                           //~v104R~
                rc=xnpsrchpatpos(Ppnpwt,Pprow,Ppcol);              //~v104R~
//printf("patpos rc=%d,seq=%d,row=%d,col=%d\n",rc,seqno,*Pprow,*Ppcol);//~v104R~
			ii=*Pprow;                                             //~v104I~
			jj=*Ppcol;                                             //~v104I~
        	kk=ii/3*3+jj/3;                                        //~v104I~
            if (!rc && Psw1st)                                     //~v104I~
                rc=xnpsrchpatpos1st(Ppnpwt,Pprow2,Ppcol2,1);//select bottom-left//~v104I~
            if (rc || Srigidsw || !Ssetlimit)                      //~v104I~
                return rc;                                         //~v104I~
        	if ((Ppnpwt->icnt[0][ii]<Ssetlimit)                    //~v104R~
        	&&  (Ppnpwt->icnt[1][jj]<Ssetlimit)                    //~v104R~
        	&&  (Ppnpwt->icnt[2][kk]<Ssetlimit))                   //~v104R~
                return 0;                                          //~v104I~
            Ppnpwt->m99[ii][jj].flag |= M99F_LIMIT;	//out of select//~v104R~
//printf("over limit(>%d) seq=%d,row=%d,col=%d\n",Ssetlimit,seqno,*Pprow,*Ppcol);//~v104R~
        }//limit cnt                                               //~v104I~
    }//patern residual
//*no patern case
    entno=81-seqno;
    for (;;)
    {
    	if (Splan>0                      //get from max candidate place
        ||  (Splan<0 && seqno>MINSELECTSTART))//at first randow,chng to min method
        {                                //to avoid dencity
        	rc=xnpsrchpatpos(Ppnpwt,&ii,&jj);                      //~v103R~
			if (rc)	//no place
            {                                                      //~v104I~
    			xnptrace(Ppnpwt);                                  //~v104R~
                uerrexit("Internal Logic Err;No place found for plan at seq(%d)",0,
                        	seqno);
            }                                                      //~v104I~
            pm99=pm990+ii*9+jj;
//printf("by plan posno=%d,(%d,%d)\n",seqno,ii,jj);
        }
        else
        {
//          seqposno=rand()%entno;         //to be fixed seq pos;  //~v009R~
            seqposno=urand()%entno;         //to be fixed seq pos; //~v009I~
            pm99=pm990;
//printf("posno=%d\n",seqposno);
            for (ii=0,kk=seqposno;ii<9;ii++)
            {
                for (jj=0;jj<9;jj++,pm99++)
                    if (!pm99->fnum     //not fixed
                    &&  !(pm99->flag & M99F_LIMIT))
                        if (!kk--)            //rand pos
                            break;
                if (kk<0)
                    break;
            }//row
            if (kk>=0)
                uerrexit("Internal Logic Err;Residual place(%d) of %d and seq(%d)",0,
                        kk,seqposno,seqno);
		}//no plan
        if (!pm99->cmsk)		//has no candidate
            return 4;           //step back required
//limit chk
        if ((Ppnpwt->icnt[0][ii]>=Ssetlimit)
        ||  (Ppnpwt->icnt[1][jj]>=Ssetlimit)
        ||  (Ppnpwt->icnt[2][ii/3*3+jj/3]>=Ssetlimit))
        {
        	pm99->flag|=M99F_LIMIT;		//out of candidate
            entno--;
            if (!entno)
            	return 4;				//step back
//printf("seqno=%d,seqposno=%d,fixed(%d or %d or %d) over limit(%d) at (%d,%d)\n",
//			seqno,seqposno,
//        	Ppnpwt->icnt[0][ii],Ppnpwt->icnt[1][jj],Ppnpwt->icnt[2][ii/3*3+jj/3],
//				Ssetlimit,ii,jj);
//xnptrace(Ppnpwt);
        	continue;
		}
		break;
	}//limitation
    *Pprow=ii;
    *Ppcol=jj;
    return 0;
}//xnpsrchpos
//***************************************************************
//* search free pos randomly;
//*   patern specified case,select least candidate place
//* rc:4:all fixed
//***************************************************************
int xnpsrchpatpos(PNPWORKT Ppnpwt,int *Pprow,int *Ppcol)           //~v103R~
{
	PM99  pm99,pm990;
    int   ii,kk,pospatc,randno,entno,row,col,minmaxccnt,minmaxccnt0,*ppat,ccnt;//~v104R~
//*****************************
    pm990=&Ppnpwt->m99[0][0];     //answer
    ppat=Spospattbl;
//get lowest candidateno
	if (Splan<0)
    	minmaxccnt0=10;
	else
    	minmaxccnt0=-1;
    if (Spospatcnt_u && Spospatcnt_u<Spospatcnt)	//no rigid and user pattern//~v104I~
		pospatc=Spospatcnt_u;	//search at first in the range of user//~v104I~
    else	                                                       //~v104I~
		pospatc=Spospatcnt;		//search all                       //~v104I~
  	kk=0;                                                          //~v104I~
    minmaxccnt=minmaxccnt0;                                        //~v104I~
  for (ii=0;ii<2;ii++)                                        //~v104I~
  {                                                                //~v104I~
    for (;kk<pospatc;kk++)		//patern exauste                   //~v104R~
    {
    	row=*ppat++;
        col=*ppat++;
        pm99=pm990+row*9+col;
        if (!(ccnt=pm99->ccnt)) //fixed
			continue;
        if (pm99->flag & M99F_LIMIT)                               //~v104R~
			continue;                                              //~v104I~
		if (Splan<0)	//search lowest ccntno
        {
			if (minmaxccnt>ccnt)
        		minmaxccnt=ccnt;
		}
        else           //search having highest ccnt
        {
			if (minmaxccnt<ccnt)
        		minmaxccnt=ccnt;
		}
	}
//printf("Splan=%d,%d ?= %d\n",Splan,minmaxccnt,minmaxccnt0);
    if (minmaxccnt==minmaxccnt0)
    {                                                              //~v104I~
	    if (pospatc<Spospatcnt)	//no rigid and user pattern        //~v104I~
        {                                                          //~v104I~
//  		xnptrace(Ppnpwt);                                      //~v104R~
			pospatc=Spospatcnt;		//search all                   //~v104I~
            continue;				//search later half            //~v104I~
		}                                                          //~v104I~
    	return 4;			//all fixed
    }                                                              //~v104I~
    break;                                                         //~v104I~
  }//2 times loop                                                  //~v104I~
//count lowest candidate place
    ppat=Spospattbl;
    for (kk=0,entno=0;kk<pospatc;kk++)		//patern exauste       //~v104R~
    {
    	row=*ppat++;
        col=*ppat++;
        pm99=pm990+row*9+col;
        if (!(ccnt=pm99->ccnt)) //fixed
			continue;
        if (pm99->flag & M99F_LIMIT)                               //~v104R~
			continue;                                              //~v104I~
        if (pm99->ccnt==minmaxccnt) //fixed
        	entno++;
	}
//select plase by random no                                        //~v104R~
	if (entno==1)
    	randno=0;
	else
//  	randno=rand()%entno;                                       //~v009R~
    	randno=urand()%entno;                                      //~v009I~
    ppat=Spospattbl;
    for (kk=0,entno=0;kk<pospatc;kk++)		//patern exauste       //~v104R~
    {
    	row=*ppat++;
        col=*ppat++;
        pm99=pm990+row*9+col;
        if (pm99->flag & M99F_LIMIT)                               //~v104R~
			continue;                                              //~v104I~
        if (pm99->ccnt==minmaxccnt) //fixed
        	if (entno++==randno)
            {
            	*Pprow=row;
            	*Ppcol=col;
//printf("lowest ccnt=%d,entno=%d,randno=%d,row=%d,col=%d\n",minmaxccnt,entno,randno,row,col);//~v104R~
                return 0;
			}
	}
    return 8;       //logic err
}//xnpsrchpatpos
//***************************************************************  //~v103I~
//* search top-right and bottom-left of pattern                    //~v103I~
//* rc:4:no pattern data on the box                                //~v103I~
//***************************************************************  //~v103I~
int xnpsrchpatpos1st(PNPWORKT Ppnpwt,int *Pprow,int *Ppcol,int Ptype)//~v103R~
{                                                                  //~v103I~
    int   ii,jj,rc;                                                //~v103R~
	PM99  pm99;                                                    //~v103I~
//*****************************                                    //~v103I~
    pm99=&Ppnpwt->m99[0][0];     //answer                          //~v103I~
    rc=4;                                                          //~v103I~
    if (!Ptype)		//top right of box3                            //~v103R~
        for (ii=0;ii<3;ii++)                                       //~v103I~
        {                                                          //~v103I~
            for (jj=8;jj>5;jj--)                                   //~v103I~
                if ((pm99+ii*9+jj)->flag & M99F_PATERN)            //~v103R~
                {                                                  //~v103I~
                	rc=0;                                          //~v103I~
                    break;                                         //~v103I~
				}                                                  //~v103I~
            if (!rc)                                               //~v103I~
                break;                                             //~v103I~
        }                                                          //~v103I~
	else              //top roght of box7                          //~v103R~
        for (ii=6;ii<9;ii++)                                       //~v103R~
        {                                                          //~v103I~
            for (jj=3;jj>=0;jj--)                                  //~v103R~
                if ((pm99+ii*9+jj)->flag & M99F_PATERN)            //~v103I~
                {                                                  //~v103I~
                	rc=0;                                          //~v103I~
                    break;                                         //~v103I~
				}                                                  //~v103I~
            if (!rc)                                               //~v103I~
                break;                                             //~v103I~
        }                                                          //~v103I~
    if (!rc)                                                       //~v103R~
    {                                                              //~v103I~
    	*Pprow=ii;                                                 //~v103I~
    	*Ppcol=jj;                                                 //~v103I~
    }                                                              //~v103I~
    return rc;                                                     //~v103I~
}//xnpsrchpatpos1st                                                //~v103I~
//***************************************************************  //~v101I~
//* setup pattern data when not specified up to 45 box(no RIGID make)//~v101I~
//*parm1:out pattern adat area                                     //~v101I~
//*parm2:limit in row/col/box                                      //~v101I~
//*ret  :1 if random patern created                                //~v104R~
//***************************************************************  //~v101I~
int xnpmqsetuppat(PNPWORKT Ppnpwt,int *Ppatdata,int Psetlimit)     //~v104R~
{                                                                  //~v101I~
	PM99  pm99;                                                    //~v101I~
    int *pi,pos,ii,jj,kk,ibox,posmax,randompattern=0;              //~v104R~
	NPWORKT npwt;	//work to chk limit                            //~v101I~
    int pospat[81];                                                //~v101I~
    int maskr,maskc,maskb;                                         //~v104I~
static Spptbl[81][2];                                              //~v101I~
//*****************************                                    //~v101I~
	memset(Spptbl,0,sizeof(Spptbl));                               //~v101I~
    Spospatcnt=0;                                                  //~v101I~
    pm99=&Ppnpwt->m99[0][0];     //answer                          //~v101I~
//patern specified                                                 //~v101I~
    if (Ppatdata)		//patern specified                         //~v101I~
    {                                                              //~v101I~
    	for (pi=Ppatdata,ii=0;ii<9;ii++)                           //~v101I~
        	for (jj=0;jj<9;jj++,pi++,pm99++)                       //~v101I~
            	if (*pi)		//place to be filled               //~v101I~
                {                                                  //~v101I~
            		Spptbl[Spospatcnt][0]=ii;                      //~v101I~
            		Spptbl[Spospatcnt++][1]=jj;                    //~v101I~
                    pm99->flag|=M99F_PATERN;                       //~v101I~
				}                                                  //~v101I~
		Spospattbl=&Spptbl[0][0];                                  //~v101I~
	}                                                              //~v101I~
    if (Srigidsw)                                                  //~v104I~
        if (!Ppatdata || Spospatcnt<XNP_MINIDATA)                  //~v104I~
            uerrexit("Specify minimum %d pattern data if /Yr",     //~v104I~
                    "/Yr の時は少なくとも %d 個のパターン指定が必要",//~v104I~
                    XNP_MINIDATA);                                 //~v104I~
	                                                               //~v104I~
    if (Ppatdata)		//patern specified                         //~v104I~
	    if (Srigidsw)                                              //~v104I~
        	return 0;                                              //~v104I~
//strategy specified                                               //~v101I~
  if (!Ppatdata)		//patern specified                         //~v104I~
    if (Splan)          //strategy specified                       //~v101I~
    {                                                              //~v101I~
	    pm99=&Ppnpwt->m99[0][0];     //answer                      //~v104I~
        for (ii=0;ii<9;ii++)                                       //~v101I~
            for (jj=0;jj<9;jj++,pm99++)                            //~v101I~
            {                                                      //~v101I~
                Spptbl[Spospatcnt][0]=ii;                          //~v101I~
                Spptbl[Spospatcnt++][1]=jj;                        //~v101I~
            }                                                      //~v101I~
        Spospattbl=&Spptbl[0][0];       //all place as patern      //~v101I~
        return 0;                                                  //~v104R~
    }                                                              //~v101I~
//create pattern                                                   //~v101I~
	Srigidsw=0;                                                    //~v101I~
	memset(pospat,0,sizeof(pospat));                               //~v101I~
	if (!(posmax=Psetlimit))                                       //~v101I~
    	posmax=SETMAX;                                             //~v101I~
	memset(&npwt,0,sizeof(npwt));	//work for fiill count         //~v101R~
//  for (maskr=0,maskc=0,maskb=0,kk=0;;kk++)                       //+v026R~
    for (maskr=0,maskc=0,maskb=0,kk=0;kk<81;kk++)                  //+v026I~
    {                                                              //~v101I~
      if (kk<Spospatcnt)                                           //~v104I~
    	pos=Spptbl[kk][0]*9+Spptbl[kk][1];		//user specified pattern//~v104I~
      else                                                         //~v104I~
//  	pos=(rand()%81);         //to be fixed seq pos;            //~v009R~
    	pos=(urand()%81);         //to be fixed seq pos;           //~v009I~
        if (*(pospat+pos))	//already filled                       //~v101I~
        	continue;                                              //~v101I~
      if (kk<Spospatcnt)                                           //~v104I~
        *(pospat+pos)=1;	//of user                              //~v104R~
      else                                                         //~v104I~
        *(pospat+pos)=2;	//of /Nr                               //~v104I~
        ii=pos/9;                                                  //~v101M~
        jj=pos%9;                                                  //~v101M~
        ibox=(ii/3*3)+jj/3;                                        //~v101I~
        if (++npwt.icnt[0][ii]>=posmax)                            //~v104R~
        	maskr|=Smask[ii+1];                                    //~v104R~
        if (++npwt.icnt[1][jj]>=posmax)                            //~v104R~
        	maskc|=Smask[jj+1];                                    //~v104R~
        if (++npwt.icnt[2][ibox]>=posmax)                          //~v104R~
        	maskb|=Smask[ibox+1];                                  //~v104R~
        if (maskr==ALL_CANDIDATE                                   //~v104R~
        &&  maskc==ALL_CANDIDATE                                   //~v104R~
        &&  maskb==ALL_CANDIDATE)                                  //~v104R~
	      if (kk>=Spospatcnt)                                      //~v104I~
            break;                                                 //~v101I~
//printf("mask=%04x,%04x,%04x\n",maskr,maskc,maskb);               //~v104R~
	}                                                              //~v101I~
    Spospatcnt_u=Spospatcnt;                                       //~v104R~
    Spospatcnt=0;                                                  //~v104I~
  for (kk=1;kk<=2;kk++)            //at first user pattern         //~v104I~
  {                                                                //~v104I~
    pm99=&Ppnpwt->m99[0][0];     //answer                          //~v104I~
    for (pi=pospat,ii=0;ii<9;ii++)                                 //~v101I~
        for (jj=0;jj<9;jj++,pi++,pm99++)                           //~v101I~
            if (*pi==kk)        //place to be filled               //~v104R~
            {                                                      //~v101I~
                Spptbl[Spospatcnt][0]=ii;                          //~v101I~
                Spptbl[Spospatcnt++][1]=jj;                        //~v101I~
                pm99->flag|=M99F_PATERN;                           //~v101I~
            }                                                      //~v101I~
  }	                                                               //~v104I~
    Spospattbl=&Spptbl[0][0];                                      //~v101I~
//printf("Spospatcnt=%d,posmax=%d\n",Spospatcnt,posmax);           //~v104R~
    return 1;			//random pattern created                   //~v104R~
}//xnpmqsetuppat                                                   //~v101I~
//**************************************************               //~v009I~
//*rand init                                                       //~v009I~
//**************************************************               //~v009I~
void usrand(int seed)                                              //~v009I~
{                                                                  //~v009I~
    SrandR=seed;                                                   //~v009I~
}                                                                  //~v009I~
//**************************************************               //~v009I~
//*rand  get 0,nnn,nn0  from result                                //~v009I~
//* Mixed congruential method                                      //~v009I~
//**************************************************               //~v009I~
int  urand(void)                                                   //~v009I~
{                                                                  //~v009I~
static int SrandP=673;                                             //~v009I~
static int SrandQ=944;                                             //~v009I~
    return (SrandR=(SrandP*SrandR+SrandQ)/10%100000);	//Xn=(A*Xn-1+C)/M   M:max number//~v009I~
}                                                                  //~v009I~
