//*CID://+v1.1R~:                             update#=   23;       //~v1.1R~
//*************************************************************
//*XNPSUB.c   Number Place Puzzle
//*************************************************************
//*010317 xnp v1.1:common source for both 4*4 and 5*5              //~v1.1I~
//*001115 xnp v0.5:4*4 matrix version                              //~v0.5I~
//*000103 xnp v0.1:Win(C++) support                                //~v0.1I~
//*               :internal logic err for no place whenmake(err ret when no candidate)//~v0.1I~
//*v100 first
//*************************************************************
#include <time.h>                                                  //~0103R~
#include <stdio.h>                                                 //~0103R~
#include <stdlib.h>                                                //~0103R~
#include <ctype.h>                                                 //~0103R~
#include <string.h>                                                //~0103R~
#ifdef DOS
#else
  #ifdef W32
  #else
  #endif
#endif
#include <ulib.h>                                                  //~0103R~
#include <uerr.h>                                                  //~0103R~
#include <ualloc.h>                                                //~0103R~
//********************
#include "xnpnsub.h"                                               //~v0.5R~
//********************
//#define LOOPPROT MM_TOTN      //81                               //~v1.1R~
#define LOOPPROT (Gmm_totn)      //81                              //~v1.1I~
//********************
#ifdef WNP_CALL                                                    //~v0.1I~
extern	int	GblSubthreadStopReq;	//thread communication with wnp//~v0.1I~
#endif                                                             //~v0.1I~
static  int Stestsw;
static  int Srchkmaxlevel;
static  int Stmsgfreq;		//loop msg frequency                   //~v0.1I~
static  int Srepeatmax;		//loop max                             //~v0.1I~
static  int Stotloop;                                              //~v0.1I~
static  time_t Stottm0;                                            //~v0.1R~
static  int Srlistcnt;       //redundancy list count
static  int Srlist[XNP_MAXRLIST*2];                                //~v0.1I~
static  int Smaxrclvl;       //max redundancy level detected
//static  int Smask[10]={0,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x100};//~v0.5R~
//static  int Smask[MM_MAXN+1]={0,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x100,//~v0.5R~
//                              0x200,0x400,0x800,0x1000,0x2000,0x4000,0x8000};//~v0.5R~
static  int Smask[MM_MAXN+1]={0,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x100,//~v0.5I~
                              0x200,0x400,0x800,0x1000,0x2000,0x4000,0x8000,//~v0.5I~
                              0x10000, 0x20000, 0x40000, 0x80000,  //~v0.5I~
		    				  0x100000,0x200000,0x400000,0x800000,0x1000000};//~v0.5I~
#define MAX_DEPTH   10
static  int Srchkwk[MAX_DEPTH][4]; //max 10 depth,row,col,iold,inew
//********************
int xnpgasub(int Popt,int *Pdata,PNPWORKT Ppnpwt);
int xnprchk(int Popt,int *Pdata,int Prlevel,int Pstartpos,PNPWORKT Ppnpwt);//~v1.1R~
void xnprprint(void);
int xnpchk(int Prow,int Pcol,int *Pdata);
int xnpmethod1(PNPWORKT Ppnpwt);
int xnpmethod1x(PNPWORKT Ppnpwt);
int xnpmethod2box(PNPWORKT Ppnpwt,int Pnum);
int xnpmethod2line(PNPWORKT Ppnpwt,int Pnum);
int xnpmethod3(PNPWORKT Ppnpwt,int Pnum);
int xnpmethod4(PNPWORKT Ppnpwt);
int xnpm3sub(PNPWORKT Ppnpwt,int Pcase,int Prow,int Pcol,int Pnum);
int xnpmethod6(PNPWORKT Ppnpwt);
int xnpmethod9(PNPWORKT Ppnpwt);
int xnpsrchleast(PNPWORKT Ppnpwt,int *Pprow,int *Ppcol);
int xnpm6sub(int Pcase,int Pmask,int Prow1,int Pcol1,int Prow2,int Pcol2,PNPWORKT Ppnpwt);
int xnpdropcan(PNPWORKT Ppnpwt,int Prow,int Pcol,int Pmask,char *Pcase,int Plevel);
void xnpcmchk(PNPWORKT Ppnpwt,int Pcnt,int Pmsk);
int xnplastchk(PNPWORKT Ppnpwt);
int xnpfixbymask(int Prow,int Pcol,int Pmask,PNPWORKT Ppnpwt,int Plevel,char *Pcase);
//*************************************************************
//**********************************************************************
//* solution more human like
//* rc:0-ok, 4-not fixed exist
//**********************************************************************
int xnpgetanswer(int Popt,int *Pdata,PNPWORKT Ppnpwt,int Ptmsgfreq,int Prepeatmax)//~v0.1R~
{
    int      rc;
//************
    Stmsgfreq=Ptmsgfreq;                                           //~v0.1I~
    Srepeatmax=Prepeatmax;                                         //~v0.1I~
	Stotloop=0;                                                    //~v0.1I~
	Srlistcnt=0;                                                   //~v0.1I~
    rc=xnpgasub(Popt & ~XNP_REDUNDANTCK,Pdata,Ppnpwt);
    if (!(Popt & XNP_REDUNDANTCK) || rc)
    	return rc;
//redundancy chk
    Smaxrclvl=-1;         //redundancy level
	rc=xnprchk(Popt,Pdata,0,0,Ppnpwt);	//depth=0,start pos=0      //~v1.1R~
    if (Smaxrclvl)
        if (Srlistcnt)                                             //~v0.1I~
			uerrmsg("Redundancy Level=%d(parm=%d),Listed %d case.",//~v1.1R~
			        "冗長な場所が 最大 %d 個所あります(パラメータ指定は %d)。(%d ケース)",//~v1.1R~
						Smaxrclvl,Srchkmaxlevel,Srlistcnt);        //~v1.1R~
		else                                                       //~v0.1I~
			uerrmsg("No Redundancy",                               //~v0.1I~
//  		        "冗長な場所は有りません。",                    //~v0.1I~//+v1.1R~
    		        "冗長な場所は有りません。");                   //+v1.1I~
//  					Srlistcnt);                                //~v0.1I~//+v1.1R~
#ifdef WNP_CALL                                                    //~v0.1R~
	Ppnpwt->rclistcnt=Srlistcnt;                                    //~v0.1I~
	Ppnpwt->rclist=Srlist;                                          //~v0.1I~
#endif                                                             //~v0.1I~
    return rc;                                                     //~v1.1R~
}//xnpgetanswer
//**********************************************************************
//* redundancy chk
//* rc:0-ok, 4-timeout                                             //~v1.1R~
//**********************************************************************
int xnprchk(int Popt,int *Pdata,int Prlevel,int Pstartpos,PNPWORKT Ppnpwt)//~v1.1R~
{
    int      idata[MM_MAXN][MM_MAXN];                              //~v0.5R~
    int      *pi,*pi0,loop,iold,inew,row,col,rlevel;
    int      rc=0;                                                 //~v1.1I~
	PNPWORKT pnpwt;
//************
    if (Prlevel>=MAX_DEPTH)
    {
        xnprprint();        //print redundancy
        uerrexit("Too many redundancy(over %d places)",            //~v0.1R~
					"冗長な個所が %d 以上あります",                //~v0.1I~
                    MAX_DEPTH);
    }
    pi0=&idata[0][0];
    pnpwt=umalloc(sizeof(NPWORKT));
    memcpy(pi0,Pdata,sizeof(idata));    //to drop one
    for (loop=Pstartpos,pi=pi0+Pstartpos;loop<Gmm_totn;loop++,pi++)//no need to start from 0//~v1.1I~
    {
    	if (!*pi)	//no init data
        	continue;
        iold=*pi;
        *pi=0;  //try drop one data
        row=loop/Gmm_maxn;                                         //~v1.1R~
        col=loop%Gmm_maxn;                                         //~v1.1R~
//printf("level=%d,loop=%d,num=%d,row=%d,col=%d\n",Prlevel,loop,iold,row,col);
        if (!xnpgasub((Popt|XNP_NOPRINTIN|XNP_NOPRINTOUT)&~XNP_PILOT,pi0,pnpwt))
        {
//          inew=pnpwt->mxx[row][col].fnum;   //fixed num          //~v1.1R~
            inew=PMXXIJ(pnpwt,row,col)->fnum;   //fixed num        //~v1.1I~
            Srchkwk[Prlevel][0]=row;    //save redundant point
            Srchkwk[Prlevel][1]=col;
            Srchkwk[Prlevel][2]=iold;
            Srchkwk[Prlevel][3]=inew;
	        rlevel=Prlevel+1;
            if (rlevel>Smaxrclvl)
                Smaxrclvl=rlevel;
//printf("fwd level=%d,max=%d,row=%d,col=%d,old=%d,new=%d\n",
//          rlevel,Smaxrclvl,row,col,iold,inew);
//level down
			if (rlevel<Srchkmaxlevel)
	            rc=xnprchk(Popt,pi0,Prlevel+1,loop+1,pnpwt);       //~v1.1R~
            else
            {
                xnprprint();        //redundancy list
//              xnpprintnum(0,0,0,pnpwt,0,0);   //print initial data//~v1.1R~
//              xnpprintnum(2,row,col,pnpwt,0,0);   //print last data//~v1.1R~
                xnpprintnum(2,Prlevel,0,pnpwt,0,0); //print last data with redundancy pos//~v1.1I~
            }
		}//redundancy
        else                                                       //~v1.1I~
    		if (pnpwt->stat & STAT_TIMEOUT)//print require at last //~v1.1R~
            	rc=4;                                              //~v1.1I~
        *pi=iold;		//recov
        if (rc)                                                    //~v1.1I~
        	break;                                                 //~v1.1I~
	}//all idata
//printf("back level==%d,max=%d\n",Prlevel,Smaxrclvl);
    if (rlevel==Smaxrclvl  //first back step
    &&  rlevel<Srchkmaxlevel
    &&  Smaxrclvl>=0)
    {
        xnprprint();		//redundancy list
	    xnpprintnum(0,0,0,pnpwt,0,0);	//print initial data
	}
    ufree(pnpwt);
    return rc;                                                     //~v1.1R~
}//xnprchk
//**********************************************************************
//* redundancy chk list print
//* rc:0-ok, 4-not fixed exist
//**********************************************************************
void xnprprint(void)
{
#ifdef WNP_CALL                                                    //~v0.1M~
	Srlist[Srlistcnt*2]=Srchkwk[0][0];   	//x                    //~v0.1I~
	Srlist[Srlistcnt*2+1]=Srchkwk[0][1];  //y                      //~v0.1I~
	Srlistcnt++;                                                   //~v0.1M~
#else                                                              //~v0.1M~
    int *pi,ii;
//************
	Srlistcnt++;
    uerrmsg("---Redundancy List\n---",
			"---冗長性検査結果---");
    pi=Srchkwk[0];
    for (ii=0;ii<Smaxrclvl;ii++,pi+=4)
    {
        if (*(pi+2)!=*(pi+3)) //number changed
            printf("#depth=%2d    (%d,%d)(!=%d)  \n",ii+1,*pi+1,*(pi+1)+1,*(pi+2));//~v1.1R~
        else
            printf("#depth=%2d    (%d,%d)(==%d)  \n",ii+1,*pi+1,*(pi+1)+1,*(pi+2));//~v1.1R~
    }
#endif                                                             //~v0.1I~
    return;
}//xnprprint
//**********************************************************************
//* solution more human like
//* rc:0-ok, 4-not fixed exist, 8:data conflict, 12:multiple solution
//**********************************************************************
int xnpgasub(int Popt,int *Pdata,PNPWORKT Ppnpwt)
{
    int rc,opt;
//************
//*init by parm data
    rc=xnpansinit(Popt,Pdata,Ppnpwt);

    Srchkmaxlevel=(Popt>>12);		//max rchk level
    if (!(Popt & XNP_NOPRINTIN))
	    xnpprintnum(0,0,0,Ppnpwt,0,0);	//print initial data
    if (rc)
    {
	    if ((Popt & XNP_NOPRINTIN))		//not printed
		    xnpprintnum(0,0,0,Ppnpwt,0,0);	//print initial data
        if (rc==16)                                                //~v0.1I~
            uerrexit("Specify minimum %d init data",               //~v0.1I~
                    "少なくとも %d 個の指定が必要",                //~v0.1I~
                    XNP_MINIDATA);                                 //~v0.1I~
        else                                                       //~v0.1I~
            uerrexit("Initial data error(rc=%d)",                  //~v0.1R~
                    "問題データに誤りがあります(rc=%d)",           //~v0.1R~
                    rc);                                           //~v0.1R~
	}
//resolution
	rc=xnpsolution(Ppnpwt);
    if (!(Ppnpwt->stat & (STAT_MULTISOL|STAT_TIMEOUT)))//print require at last//~v0.1R~
        if (!(Popt & XNP_NOPRINTOUT))
        {
            if (rc)
            {
                if (rc==4) 		//space remain
                    opt=-2;     //failed (last chk failed,space remain)
                else            //conflict
                    opt=-1;     //aborted
            }
            else
                opt=2;      //success
            xnpprintnum(opt,0,0,Ppnpwt,0,0);    //print answer at last
        }
    return rc;
}//xnpgasub
//*************************************
//*work tbl init by initial data
//*rc: data dup err 16:too few data                                //~v0.1R~
//*************************************
int xnpansinit(int Popt,int *Pdata,PNPWORKT Ppnpwt)
{
	PMXX  pmxx;                                                    //~v0.5R~
    int *pi;
	int ii,jj;                                                     //~v0.1R~
//********************************
    Stestsw=Popt & XNP_TEST;
    if (Popt & XNP_SOLOFMAKE)                                      //~v0.1R~
    {                                                              //~v0.1I~
    	Srepeatmax=ANS_TIMEOUT;                                    //~v0.1I~
    	Stmsgfreq=ANS_MSGFREQ;                                     //~v0.1I~
        Stotloop=0;                                                //~v0.1R~
	}                                                              //~v0.1I~
    if (Popt & XNP_SORT)                                           //~v0.1I~
        if (xnpsortdata(Pdata,Pdata))                              //~v0.1R~
        	return 4;			//init data err                    //~v0.1I~
//tbl init
	memset(Ppnpwt,0,NPWORKTSZ);
    if (Popt & XNP_PILOT)
    {
    	Ppnpwt->stat|=STAT_PILOT;
		if (!(Popt & XNP_PILOTNOMSG))
    		Ppnpwt->stat|=STAT_PILOTMSG;
	}
    if (Popt & XNP_REDUNDANTCK)
    	Ppnpwt->stat|=STAT_RCHK;
    if (Popt & XNP_ANSOFMAKE)
    	Ppnpwt->stat|=STAT_ANSOFMAKE;
	pmxx=&Ppnpwt->mxx[0][0];                                       //~v0.5R~
	for (ii=0;ii<Gmm_maxn;ii++)                                    //~v1.1R~
		for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
        {
        	pmxx->cmsk=Gmm_all_candidate;		//all number is candidate at init//~v1.1R~
        	pmxx->ccnt=Gmm_maxn;					//candidate count//~v1.1R~
		}
//*set initial data
	for (ii=0,pi=Pdata;ii<Gmm_maxn;ii++)                           //~v1.1R~
		for (jj=0;jj<Gmm_maxn;jj++,pi++)                           //~v1.1R~
        	if (*pi)				//initial data
            {
            	if (xnpfix(ii,jj,*pi,Ppnpwt,LEVEL_INIT,0))//set fixed data
                	return 4;		//dup err                      //~v0.1R~
			}
    if (Ppnpwt->idatano<XNP_MINIDATA)                              //~v0.1R~
        return 16;                                                 //~v0.1I~
	return 0;                                                      //~v0.1R~
}//xnpansinit
//**********************************************************************//~v0.1I~
//* sort probrem data                                              //~v0.1I~
//**********************************************************************//~v0.1I~
int xnpsortdata(int *Ppdata,int *Ppdatamask)                       //~v0.1R~
{                                                                  //~v0.1I~
    int ii,jj,*pi,*pimask,num,map[10],sortwk[10];;                 //~v0.1R~
//************                                                     //~v0.1I~
//*assign seqno                                                    //~v0.1I~
    memset(sortwk,0,sizeof(sortwk));                               //~v0.1I~
    memset(map,0,sizeof(map));  //for the case fo number appeared  //~v0.1I~
    for (ii=0,jj=0,pi=Ppdata,pimask=Ppdatamask;ii<Gmm_totn;ii++,pi++,pimask++)//~v1.1R~
    {                                                              //~v0.1I~
    	num=*pi;                                                   //~v0.1I~
        if (num<0 || num>Gmm_maxn)                                 //~v1.1R~
        	return 4;                                              //~v0.1I~
        if (!num)                                                  //~v0.1I~
            continue;                                              //~v0.1I~
		if (!*pimask)	//not prob data                            //~v0.1I~
        	continue;                                              //~v0.1I~
        if (sortwk[num])	//not first time appeared              //~v0.1I~
        	continue;                                              //~v0.1I~
        sortwk[num]=1;	//not first time appeared                  //~v0.1I~
        map[++jj]=num;	//translate num to jj                      //~v0.1I~
    }                                                              //~v0.1I~
//*reverse translation                                             //~v0.1I~
    memset(sortwk,0,sizeof(sortwk));                               //~v0.1I~
    for (ii=1,pi=map;ii<=Gmm_maxn;ii++,pi++)                       //~v1.1R~
    	sortwk[map[ii]]=ii;                                        //~v0.1I~
//*translation                                                     //~v0.1I~
    for (ii=0,pi=Ppdata;ii<Gmm_totn;ii++,pi++)                     //~v1.1R~
    {                                                              //~v0.1I~
    	num=*pi;                                                   //~v0.1I~
        if (!num)                                                  //~v0.1I~
        	continue;                                              //~v0.1I~
        *pi=sortwk[num];                                           //~v0.1I~
    }                                                              //~v0.1I~
    return 0;                                                      //~v0.1I~
}//xnpsortdata                                                     //~v0.1I~
//**********************************************************************
//* solution more human like
//* rc:0-ok, 4:free space remain(xnplastchk rc),8:data conflict,12:multi solution
//*    20:answer timeout                                           //~v0.1I~
//**********************************************************************
int xnpsolution(PNPWORKT Ppnpwt)
{
    int loop,oldseq,num,rc,rcw;
//************
    for (loop=0;loop<LOOPPROT;loop++)
    {
        oldseq=Ppnpwt->seqno;
        if (Ppnpwt->stat & STAT_PILOT)
        {
//try always from easy method
			for (;;)
            {
            	if (!(rcw=xnpmethod1(Ppnpwt)))//all last remaind place
                	break;				//try next bethod
                if (rcw==-1) 			//fix err
                	return 8;
			}

            for (num=1;num<=Gmm_maxn;num++)    //all number        //~v1.1R~
            {
                if ((rcw=xnpmethod2box(Ppnpwt,num))==1) //free place in box
                    break;              //fixed,retry from first
	            if (rcw==-1)				//fix err
    	        	return 8;				//conflict
			}
            if (num<=Gmm_maxn)                 //fix occured       //~v1.1R~
                continue;               //retry from first

            if ((rcw=xnpmethod1x(Ppnpwt))==1)    //search only one remained in row+col+box
                continue;               //retry from first
            if (rcw==-1)				//fix err
            	return 8;				//conflict

            for (num=1;num<=Gmm_maxn;num++)    //all number        //~v1.1R~
            {
                if ((rcw=xnpmethod2line(Ppnpwt,num))==1) //free place in row or col
                    break;              //fixed,retry from first
	            if (rcw==-1)				//fix err
    	        	return 8;				//conflict
			}
            if (num<=Gmm_maxn)                 //fix occured       //~v1.1R~
                continue;               //retry from first
        }//pilot mode

        for (num=1;num<=Gmm_maxn;num++)    //all number            //~v1.1R~
        {
            if ((rcw=xnpmethod3(Ppnpwt,num))==1) //free place row+col+box
                break;  			//fixed,retry from first
            if (rcw==-1)                //fix err
                return 8;               //conflict
		}
        if (num<=Gmm_maxn)					//fix occured          //~v1.1R~
            continue;               //retry from first

		if ((rcw=xnpmethod4(Ppnpwt))==1)	    //search single candidate
            continue;               //retry from first
        if (rcw==-1)                //fix err
            return 8;               //conflict

		if (rcw=xnpmethod6(Ppnpwt),rcw)	    //drop candidate by matching pair//~v0.1R~
    	{
        	if (rcw<0)                  //no candidate place       //~v0.1I~
            	return 8;                                          //~v0.1I~
    		rcw=xnpmethod4(Ppnpwt);
	        if (rcw==-1)                //fix err
    	        return 8;               //conflict
            continue;               //retry from first
    	}

        if (Ppnpwt->seqno==Gmm_totn)	//end                      //~v1.1R~
        	break;
        if (oldseq!=Ppnpwt->seqno)	//progress
        	continue;
		rc=xnpmethod9(Ppnpwt);
        if (rc==4)		//not 1st level
        	return 0;	//return now by success rc
        if (Ppnpwt->stat & STAT_TIMEOUT)                           //~v0.1I~
            return 20;                 //timeout                   //~v0.1I~
	    if (!rc)		//failed
        	break;
	}
    if (Ppnpwt->stat & STAT_DATA_CONFLICT)
        return 8;                  //problem err
    if (Ppnpwt->stat & STAT_MULTISOL)
        return 12;                 //multi solution err
    return xnplastchk(Ppnpwt);     //rc=0 or 4 or 8
}//xnpsolution
//**********************************************************************
//* fill last remained space in the row/col/box for all row
//* (search last empty place in  row,col or box)
//* rc:1:fixed a number,0:no progress -1:fix err
//**********************************************************************
int xnpmethod1(PNPWORKT Ppnpwt)
{
    PMXX pmxx;                                                     //~v0.5R~
	int  ii,jj,ibox,*pilc;
	int  row,col,fixctr=0;
//************************
//row
    pilc=&Ppnpwt->fcnt[0][0];      //line(row) fixed cnt
    for (ii=0;ii<Gmm_maxn;ii++,pilc++)                             //~v1.1R~
    {
        if (*pilc!=Gmm_last) 				//not the case only one remained//~v1.1R~
        	continue;
//      pmxx=&Ppnpwt->mxx[ii][0];   //matrix of each plase         //~v1.1R~
        pmxx=PMXXIJ(Ppnpwt,ii,0);                                  //~v1.1I~
        for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
            if (!pmxx->fnum)        //not fixed                    //~v0.5R~
            {
	            if (xnpfixbymask(ii,jj,pmxx->cmsk,Ppnpwt,LEVEL_EASY,"m1R"))//~v0.5R~
			    	return -1;
            	fixctr++;			//rc
            }
    }//row
//col
    pilc=&Ppnpwt->fcnt[1][0];      //line(col) fixed cnt
    for (jj=0;jj<Gmm_maxn;jj++,pilc++)                             //~v1.1R~
    {
        if (*pilc!=Gmm_last) 				//not the case only one remained//~v1.1R~
        	continue;
	    pmxx=&Ppnpwt->mxx[0][jj];   //matrix of each plase         //~v0.5R~
        for (ii=0;ii<Gmm_maxn;ii++,pmxx+=Gmm_maxn)                 //~v1.1R~
            if (!pmxx->fnum)        //not fixed                    //~v0.5R~
            {
	            if (xnpfixbymask(ii,jj,pmxx->cmsk,Ppnpwt,LEVEL_EASY,"m1C"))//~v0.5R~
			    	return -1;
            	fixctr++;			//rc
            }
    }//col
//box
    pilc=&Ppnpwt->fcnt[2][0];      //line(box) fixed cnt
    for (ibox=0;ibox<Gmm_maxn;ibox++,pilc++)  //all box            //~v1.1R~
    {
        if (*pilc!=Gmm_last) 				//not the case only one remained//~v1.1R~
        	continue;
        row=(ibox/Gmm_base)*Gmm_base;     //box top row            //~v1.1R~
        col=(ibox%Gmm_base)*Gmm_base;     //box left col           //~v1.1R~
//      pmxx=&Ppnpwt->mxx[row][col];       //matrix of each plase  //~v1.1R~
        pmxx=PMXXIJ(Ppnpwt,row,col);                               //~v1.1I~
        for (ii=row;ii<row+Gmm_base;ii++,pmxx+=Gmm_next)           //~v1.1R~
            for (jj=col;jj<col+Gmm_base;jj++,pmxx++)               //~v1.1R~
	            if (!pmxx->fnum)        //not fixed                //~v0.5R~
                {
                    if (xnpfixbymask(ii,jj,pmxx->cmsk,Ppnpwt,LEVEL_EASY,"m1B"))//~v0.5R~
				    	return -1;
	            	fixctr++;			//rc
                }
    }//all box
    return fixctr;		//no one fixed
}//xnpmethod1
//**********************************************************************
//* last unused number in the sum set of row,col and box.
//* rc:1:fixed a number,0:no progress,-1:fix err
//**********************************************************************
int xnpmethod1x(PNPWORKT Ppnpwt)
{
	PMXX  pmxx;                                                    //~v0.5R~
    int   ii,jj,mask;
//************
	pmxx=&Ppnpwt->mxx[0][0];		//candidate count              //~v0.5R~
	for (ii=0;ii<Gmm_maxn;ii++)                                    //~v1.1R~
		for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
        	if (!pmxx->fnum)		//not fixed                    //~v0.5R~
            {
//printf("method1x mask=%04x row=%04x,col=%04x,box=%04x\n",mask,
//       Ppnpwt->fmsk[0][ii],Ppnpwt->fmsk[1][jj],Ppnpwt->fcnt[2][ii/Gmm_base*Gmm_base+jj/Gmm_base]);//~v1.1R~
                mask=Ppnpwt->fmsk[0][ii]
                    	|Ppnpwt->fmsk[1][jj]
                    	|Ppnpwt->fmsk[2][ii/Gmm_base*Gmm_base+jj/Gmm_base];	//used number mask//~v1.1R~
                mask=Gmm_all_candidate & ~mask;	        //unused number mask//~v1.1R~
                if (!(mask & (mask-1)))	//only 1 bit or 0 bit on
                	if (mask)			//only 1 bit on
                {
    	            if (xnpfixbymask(ii,jj,mask,Ppnpwt,LEVEL_MEDIUM,"m1x"))
				    	return -1;
                    return 1;
				}
			}//num not fixed
    return 0;		//no fix
}//xnpmethod1x
//***************************************************************
//* for A number,
//* search remained place in a box which is out of effect from filled row and col
//* (box is more easy to find than in row or col)
//* rc :1:one place fixed,0:no place fixed,-1:fix err
//***************************************************************
int xnpmethod2box(PNPWORKT Ppnpwt,int Pnum)
{
    PMXX pmxx;                                                     //~v0.5R~
	int  ii,jj,ibox,mask,cctr,*pilm;
	int  row,col,frow,fcol;
//************
    mask=Smask[Pnum];
    pilm=&Ppnpwt->fmsk[2][0];      //line(col) fixed mask
    for (ibox=0;ibox<Gmm_maxn;ibox++,pilm++)  //all box            //~v1.1R~
    {
        if (*pilm & mask)  //already fixed in this box
        	continue;
        row=(ibox/Gmm_base)*Gmm_base;     //box top row            //~v1.1R~
        col=(ibox%Gmm_base)*Gmm_base;     //box left col           //~v1.1R~
//      pmxx=&Ppnpwt->mxx[row][col];       //matrix of each plase  //~v1.1R~
        pmxx=PMXXIJ(Ppnpwt,row,col);                               //~v1.1I~
        for (cctr=0,ii=row;ii<row+Gmm_base;ii++,pmxx+=Gmm_next)    //~v1.1R~
            for (jj=col;jj<col+Gmm_base;jj++,pmxx++)               //~v1.1R~
            {
	            if (!pmxx->fnum       //not yet fixed              //~v0.5R~
	    		&&  !(Ppnpwt->fmsk[0][ii] & mask)      //line(row) fixed mask
	    		&&  !(Ppnpwt->fmsk[1][jj] & mask))      //line(row) fixed mask
                {
                    cctr++;
                    frow=ii;
                    fcol=jj;
                }
			}
        if (cctr==1)        //only one candidate
        {
            if (xnpfix(frow,fcol,Pnum,Ppnpwt,LEVEL_EASY,"m2B"))
				return -1;
            return 1;
        }
    }//all box
    return 0;		//failed
}//xnpmethod2box
//***************************************************************
//* for A number,
//* search place in row/col where is free from col/row using filled mask
//* rc :1:some place fixed,0:no place fixed,-1:fix err
//***************************************************************
int xnpmethod2line(PNPWORKT Ppnpwt,int Pnum)
{
    PMXX pmxx;                                                     //~v0.5R~
	int  ii,jj,mask,cctr,*pilm,*pilm2;
	int  frow,fcol;
//************
    mask=Smask[Pnum];
//printf("****Pnum=%d,mask=%04x\n",Pnum,mask);
//row
    pilm=&Ppnpwt->fmsk[0][0];      //line(row) fixed mask
    for (ii=0;ii<Gmm_maxn;ii++,pilm++)                             //~v1.1R~
    {
        if (*pilm & mask)  //already fixed in this row
        	continue;
//      pmxx=&Ppnpwt->mxx[ii][0];       //matrix of each plase     //~v1.1R~
        pmxx=PMXXIJ(Ppnpwt,ii,0);                                  //~v1.1I~
	    pilm2=&Ppnpwt->fmsk[1][0];      //line(col) fixed mask
        for (cctr=0,jj=0;jj<Gmm_maxn;jj++,pmxx++,pilm2++)          //~v1.1R~
        {
            if (pmxx->fnum)        //already fixed                 //~v0.5R~
                continue;
            if (Ppnpwt->fmsk[2][ii/Gmm_base*Gmm_base+jj/Gmm_base] & mask) //num is on box//~v1.1R~
                continue;
            if (*pilm2 & mask)     //num is on column
                continue;
            cctr++;
            fcol=jj;
//printf("easy row row=%d,col=%d,num=%d,mask=%04x,nummask=\n",ii,jj,Pnum,pmxx->cmsk,mask);//~v0.5R~
		}//col
        if (cctr==1)        //only one candidate in row
        {
            if (xnpfix(ii,fcol,Pnum,Ppnpwt,LEVEL_MEDIUM,"m2R"))
				return -1;
            return 1;
        }
    }//row
//col
    pilm=&Ppnpwt->fmsk[1][0];      //line(col) fixed mask
    for (jj=0;jj<Gmm_maxn;jj++,pilm++)                             //~v1.1R~
    {
        if (*pilm & mask)  //already fixed in this col
        	continue;
        pmxx=&Ppnpwt->mxx[0][jj];       //matrix of each plase     //~v0.5R~
	    pilm2=&Ppnpwt->fmsk[0][0];      //line(row) fixed mask
        for (cctr=0,ii=0;ii<Gmm_maxn;ii++,pmxx+=Gmm_maxn,pilm2++)  //~v1.1R~
        {
//printf("(%d,%d) num=%d, mask=%04x\n",ii,jj,pmxx->fnum,mask);     //~v0.5R~
            if (pmxx->fnum)        //already fixed                 //~v0.5R~
                continue;
//printf("fmsk2=%04x\n",Ppnpwt->fmsk[2][ii/Gmm_base*Gmm_base+jj/Gmm_base]);//~v1.1R~
            if (Ppnpwt->fmsk[2][ii/Gmm_base*Gmm_base+jj/Gmm_base] & mask) //num is on box//~v1.1R~
                continue;
//printf("plim2 row mask=%04x\n",*pilm2);
            if (*pilm2 & mask)  	//num is on the row
                continue;
            cctr++;
            frow=ii;
//printf("cctr=%d\n",cctr);
		}//row
        if (cctr==1)        //only one candidate
        {
            if (xnpfix(frow,jj,Pnum,Ppnpwt,LEVEL_MEDIUM,"m2C"))
				return -1;
            return 1;
        }
    }//col
    return 0;		//failed
}//xnpmethod2line
//***************************************************************
//* for A number,
//* search place in row/col where is free from box and col/row
//*   using candidate mask.
//* And,drop mask on the line/box when the mask is all enclosed in the box/line
//* rc :1:some place fixed,0:no place fixed,-1:fix err
//***************************************************************
int xnpmethod3(PNPWORKT Ppnpwt,int Pnum)
{
    PMXX pmxx;                                                     //~v0.5R~
	int  ii,jj,mask,cctr,*pilm,rcw;
	int  frow=0,fcol=0,ibox,row,col,sameboxsw,samerowsw,samecolsw;
//************
    mask=Smask[Pnum];
//row
    pilm=&Ppnpwt->fmsk[0][0];      //line(row) fixed mask
    for (ii=0;ii<Gmm_maxn;ii++,pilm++)                             //~v1.1R~
    {
        if (*pilm & mask)  //already fixed in this row
        	continue;
//      pmxx=&Ppnpwt->mxx[ii][0];       //matrix of each plase     //~v1.1R~
        pmxx=PMXXIJ(Ppnpwt,ii,0);                                  //~v1.1I~
        sameboxsw=1;
        for (cctr=0,jj=0;jj<Gmm_maxn;jj++,pmxx++)                  //~v1.1R~
        {
        	if (!(pmxx->cmsk & mask))  //not candidate             //~v0.5R~
            	continue;
            if (cctr)    //not first time candidate
                if (fcol/Gmm_base!=jj/Gmm_base)                    //~v1.1R~
                    sameboxsw=0;
            cctr++;
            fcol=jj;
		}//col
        if (cctr==1)        //only one candidate
        {
            if (xnpfix(ii,fcol,Pnum,Ppnpwt,LEVEL_HARD,"m3R"))
				return -1;
            return 1;
        }
        if (sameboxsw)       //to be dropped for other box
        	if ((rcw=xnpm3sub(Ppnpwt,0,ii,fcol,Pnum)))	//0:box by row
        		return rcw;
    }//row
//col
    pilm=&Ppnpwt->fmsk[1][0];      //line(col) fixed mask
    for (jj=0;jj<Gmm_maxn;jj++,pilm++)                             //~v1.1R~
    {
        if (*pilm & mask)  //already fixed in this col
        	continue;
        pmxx=&Ppnpwt->mxx[0][jj];       //matrix of each plase     //~v0.5R~
        sameboxsw=1;
        for (cctr=0,ii=0;ii<Gmm_maxn;ii++,pmxx+=Gmm_maxn)          //~v1.1R~
        {
            if (!(pmxx->cmsk & mask))  //not candidate             //~v0.5R~
            	continue;
            if (cctr)    //not first time candidate
                if (frow/Gmm_base!=ii/Gmm_base)                    //~v1.1R~
                    sameboxsw=0;
//printf("COL num=%d,cctr=%d,row=%d,col=%d,mask=%04x\n",Pnum,cctr,ii,jj,pmxx->cmsk);//~v0.5R~
            cctr++;
            frow=ii;
		}//row
        if (cctr==1)        //only one candidate
        {
            if (xnpfix(frow,jj,Pnum,Ppnpwt,LEVEL_HARD,"m3R"))
				return -1;
            return 1;
        }
        if (sameboxsw)
    	    if ((rcw=xnpm3sub(Ppnpwt,1,frow,jj,Pnum)))	//1:box by col
        		return rcw;		//1:changed -1:fix err
    }//col
//box
    pilm=&Ppnpwt->fmsk[2][0];      //box fixed mask
    for (ibox=0;ibox<Gmm_maxn;ibox++,pilm++)  //all box            //~v1.1R~
    {
        if (*pilm & mask)  //already fixed in this box
        	continue;
        row=(ibox/Gmm_base)*Gmm_base;     //box top row            //~v1.1R~
        col=(ibox%Gmm_base)*Gmm_base;     //box left col           //~v1.1R~
//      pmxx=&Ppnpwt->mxx[row][col];       //matrix of each plase  //~v1.1R~
        pmxx=PMXXIJ(Ppnpwt,row,col);                               //~v1.1I~
        samerowsw=1;
        samecolsw=1;
        for (cctr=0,ii=row;ii<row+Gmm_base;ii++,pmxx+=Gmm_next)    //~v1.1R~
            for (jj=col;jj<col+Gmm_base;jj++,pmxx++)               //~v1.1R~
            {
            	if (!(pmxx->cmsk & mask))  //not candidate         //~v0.5R~
            		continue;
                if (cctr)    //not first time candidate
                {
                    if (ii!=frow)
                        samerowsw=0;
                    if (jj!=fcol)
                        samecolsw=0;
                }
                cctr++;
                frow=ii;
                fcol=jj;
			}
        if (cctr==1)        //only one candidate
        {
            if (xnpfix(frow,fcol,Pnum,Ppnpwt,LEVEL_HARD,"m3B"))
				return -1;
            return 1;
        }
        if (samerowsw)
        	if ((rcw=xnpm3sub(Ppnpwt,2,frow,fcol,Pnum)))	//2:row by box
        		return rcw;		//1:changed -1:fix err
        if (samecolsw)
        	if ((rcw=xnpm3sub(Ppnpwt,3,frow,fcol,Pnum)))	//2:col by box
        		return rcw;		//1:changed -1:fix err
    }//all box
    return 0;		//failed
}//xnpmethod3
//**********************************************************************
//* drop candidate mask
//* case:0:candidate in row is in the range of a box?
//*      1:candidate in col is in the range of a box?
//*      2:candidate in box is in the range of a row/col
//* rc:1:droped a candidate,0:no advancing,-1:fix err
//**********************************************************************
int xnpm3sub(PNPWORKT Ppnpwt,int Pcase,int Prow,int Pcol,int Pnum)
{
	PMXX  pmxx;                                                    //~v0.5R~
    int   ii,jj,mask,row,col,box,chngsw=0,rcw;                     //~v0.1R~
//************
	mask=Smask[Pnum];
	switch(Pcase)
    {
    case 0:			//in row,same box
        row=Prow/Gmm_base*Gmm_base;                                //~v1.1R~
        col=Pcol/Gmm_base*Gmm_base;                                //~v1.1R~
//      pmxx=&Ppnpwt->mxx[row][col];       //matrix of each plase  //~v1.1R~
        pmxx=PMXXIJ(Ppnpwt,row,col);                               //~v1.1I~
        for (ii=row;ii<row+Gmm_base;ii++,pmxx+=Gmm_next)           //~v1.1R~
            for (jj=col;jj<col+Gmm_base;jj++,pmxx++)               //~v1.1R~
            {
            	if (!(pmxx->cmsk & mask))  //not candidate         //~v0.5R~
            		continue;
				if (ii==Prow)
                    continue;
                chngsw+=(rcw=xnpdropcan(Ppnpwt,ii,jj,mask,"m3sr",LEVEL_HARD));//~v0.1R~
                if (rcw<0)                                         //~v0.1I~
                	return -1;                                     //~v0.1I~
			}
        break;
    case 1:			//in col,same box
        row=Prow/Gmm_base*Gmm_base;                                //~v1.1R~
        col=Pcol/Gmm_base*Gmm_base;                                //~v1.1R~
//      pmxx=&Ppnpwt->mxx[row][col];       //matrix of each plase  //~v1.1R~
        pmxx=PMXXIJ(Ppnpwt,row,col);                               //~v1.1I~
        for (ii=row;ii<row+Gmm_base;ii++,pmxx+=Gmm_next)           //~v1.1R~
            for (jj=col;jj<col+Gmm_base;jj++,pmxx++)               //~v1.1R~
            {
            	if (!(pmxx->cmsk & mask))  //not candidate         //~v0.5R~
            		continue;
				if (jj==Pcol)
                    continue;
                chngsw+=(rcw=xnpdropcan(Ppnpwt,ii,jj,mask,"m3sc",LEVEL_HARD));//~v0.1R~
                if (rcw<0)                                         //~v0.1I~
                	return -1;                                     //~v0.1I~
			}
        break;
    case 2:			//in box,same row
//      pmxx=&Ppnpwt->mxx[Prow][0];       //matrix of each plase   //~v1.1R~
        pmxx=PMXXIJ(Ppnpwt,Prow,0);                                //~v1.1I~
        box=Pcol/Gmm_base;                                         //~v1.1R~
        for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
        {
            if (!(pmxx->cmsk & mask))  //not candidate             //~v0.5R~
                continue;
            if (jj/Gmm_base==box)                                  //~v1.1R~
                continue;
            chngsw+=(rcw=xnpdropcan(Ppnpwt,Prow,jj,mask,"m3sbr",LEVEL_HARD));//~v0.1R~
            if (rcw<0)                                             //~v0.1I~
                return -1;                                         //~v0.1I~
		}//row
        break;
    case 3:			//in box,same col
        pmxx=&Ppnpwt->mxx[0][Pcol];       //matrix of each plase   //~v0.5R~
        box=Prow/Gmm_base;                                         //~v1.1R~
        for (ii=0;ii<Gmm_maxn;ii++,pmxx+=Gmm_maxn)                 //~v1.1R~
        {
            if (!(pmxx->cmsk & mask))  //not candidate             //~v0.5R~
                continue;
            if (ii/Gmm_base==box)                                  //~v1.1R~
                continue;
            chngsw+=(rcw=xnpdropcan(Ppnpwt,ii,Pcol,mask,"m3sbc",LEVEL_HARD));//~v0.1R~
            if (rcw<0)                                             //~v0.1I~
                return -1;                                         //~v0.1I~
		}//row
        break;
    }//case
    if (chngsw)
    	return xnpmethod4(Ppnpwt);
    return 0;
}//xnpm3sub
//**********************************************************************
//* search place where cnadidate count=1
//* rc:1:fixed a number,0:no advancing,-1:fix err
//**********************************************************************
int xnpmethod4(PNPWORKT Ppnpwt)
{
	PMXX  pmxx;                                                    //~v0.5R~
    int   ii,jj,mask;
//************
	pmxx=&Ppnpwt->mxx[0][0];		//candidate count              //~v0.5R~
//xnptrace(Ppnpwt);
	for (ii=0;ii<Gmm_maxn;ii++)                                    //~v1.1R~
		for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
        	if (pmxx->ccnt==1)                                     //~v0.5R~
            {
            	mask=pmxx->cmsk;                                   //~v0.5R~
                if (xnpfixbymask(ii,jj,mask,Ppnpwt,LEVEL_HARD,"m4 "))
					return -1;
            	return 1;
			}
    return 0;		//0:no status changed
}//xnpmethod4
//**********************************************************************
//* search pair with same candidate;It mean other place of the line
//* can be drop the two candidate.
//* for ex,when 2 place have candidate (3,5) on the same row/col,
//* the (3,5) should be droped from candidate from the other box of same line.
//* rc:0-not found,1:droped candidate,-1:data conflict             //~v0.1R~
//**********************************************************************
int xnpmethod6(PNPWORKT Ppnpwt)
{
	PMXX  pmxx,pmxxp;                                              //~v0.5R~
    int   ii,jj,kk,ll,ibox,row,col,mask,rcw;                       //~v0.1R~
//************
//search pair in the row
    pmxx=&Ppnpwt->mxx[0][0];        //candidate count              //~v0.5R~
    for (ii=0;ii<Gmm_maxn;ii++)                                    //~v1.1R~
        for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
        {
//printf("pair srch row=%d,col=%d, ccnt=%d,mask=%04x\n",ii,jj,pmxx->ccnt,pmxx->cmsk);//~v0.5R~
            if (pmxx->ccnt==2)  //2 candidate                      //~v0.5R~
            {
                mask=pmxx->cmsk;                                   //~v0.5R~
                for (kk=jj+1,pmxxp=pmxx+1;kk<Gmm_maxn;kk++,pmxxp++)//~v1.1R~
                {
//printf("pair srch row=%d, col=%d-%d,mask=%04x-%04x\n",ii,jj,kk,mask,pmxxp->cmsk);//~v0.5R~
                    if (pmxxp->cmsk==mask)  //pair with 2 candidate//~v0.5R~
                        if ((rcw=xnpm6sub(0,mask,ii,jj,ii,kk,Ppnpwt)),rcw)  //0:row//~v0.1R~
                        {                                          //~v0.1I~
                        	if (rcw<0)                             //~v0.1I~
                            	return -1;                         //~v0.1I~
                        	return 1;
						}                                          //~v0.1I~
                }//right of a place
            }//2 candidate
        }//col
//search pair in the col
    for (jj=0;jj<Gmm_maxn;jj++)                                    //~v1.1R~
    {
        pmxx=&Ppnpwt->mxx[0][jj];       //candidate count          //~v0.5R~
        for (ii=0;ii<Gmm_maxn;ii++,pmxx+=Gmm_maxn)                 //~v1.1R~
        {
//printf("pair srch row=%d,col=%d,ccnt=%d, mask=%04x\n",ii,jj,pmxx->ccnt,pmxx->cmsk);//~v0.5R~
            if (pmxx->ccnt==2)                                     //~v0.5R~
            {
                mask=pmxx->cmsk;                                   //~v0.5R~
                for (kk=ii+1,pmxxp=pmxx+Gmm_maxn;kk<Gmm_maxn;kk++,pmxxp+=Gmm_maxn)//~v1.1R~
                {
//printf("pair srch col=%d, row=%d-%d,mask=%04x,%04x\n",jj,ii,kk,mask,pmxxp->cmsk);//~v0.5R~
                    if (pmxxp->cmsk==mask)  //pair with same twe candidate//~v0.5R~
                        if ((rcw=xnpm6sub(1,mask,ii,jj,kk,jj,Ppnpwt)),rcw)  //0:col//~v0.1R~
                        {                                          //~v0.1I~
                        	if (rcw<0)                             //~v0.1I~
                            	return -1;                         //~v0.1I~
                        	return 1;
						}                                          //~v0.1I~
                }
            }//pair has same two candidate
        }//all row
    }//all col
//search pair in the box
    for (ibox=0;ibox<Gmm_maxn;ibox++)  //all box                   //~v1.1R~
    {
        row=(ibox/Gmm_base)*Gmm_base;     //box top row            //~v1.1R~
        col=(ibox%Gmm_base)*Gmm_base;     //box left col           //~v1.1R~
//      pmxx=&Ppnpwt->mxx[row][col];       //matrix of each plase  //~v1.1R~
        pmxx=PMXXIJ(Ppnpwt,row,col);                               //~v1.1I~
        for (ii=row;ii<row+Gmm_base;ii++,pmxx+=Gmm_next)           //~v1.1R~
            for (jj=col;jj<col+Gmm_base;jj++,pmxx++)               //~v1.1R~
            	if (pmxx->ccnt==2)                                 //~v0.5R~
                {
                	mask=pmxx->cmsk;                               //~v0.5R~
                	for (kk=ii;kk<row+Gmm_base;kk++,pmxxp+=Gmm_next)//~v1.1R~
                    	for (ll=jj+1,pmxxp=pmxx+1;ll<col+Gmm_base;ll++,pmxxp++)//~v1.1R~
                    		if (pmxxp->cmsk==mask)  //pair with same twe candidate//~v0.5R~
                        		if ((rcw=xnpm6sub(2,mask,ii,jj,kk,ll,Ppnpwt)),rcw)  //0:col//~v0.1R~
		                        {                                  //~v0.1I~
         			               	if (rcw<0)                     //~v0.1I~
                    		        	return -1;                 //~v0.1I~
                        			return 1;
                                }                                  //~v0.1I~
                }
    }//all box
    return 0;
}//xnpmethod6
//**********************************************************************
//* drop candidate by pair,return candidate updated flag
//* rc:0-not changed,1:droped candidate,-1:data conflict           //~v0.1R~
//**********************************************************************
int xnpm6sub(int Pcase,int Pmask,int Prow1,int Pcol1,int Prow2,int Pcol2,PNPWORKT Ppnpwt)
{
	int ii,jj,row,col,mask,maskon1,maskon2,changesw=0,num1,num2,rcw;//~v0.1R~
//************
//  if (Ppnpwt->mxx[Prow1][Pcol1].pair)	//once processed           //~v1.1R~
    if (PMXXIJ(Ppnpwt,Prow1,Pcol1)->pair)                          //~v1.1I~
    	return 0;
//  Ppnpwt->mxx[Prow1][Pcol1].pair=1;	//once processed id        //~v1.1R~
    PMXXIJ(Ppnpwt,Prow1,Pcol1)->pair=1;                            //~v1.1I~
//  Ppnpwt->mxx[Prow2][Pcol2].pair=1;	//once processed id        //~v1.1R~
    PMXXIJ(Ppnpwt,Prow2,Pcol2)->pair=1;                            //~v1.1I~
//get 2 candidate
    mask=Pmask;
    for (num1=1;num1<=Gmm_maxn;num1++)                             //~v1.1R~
    	if (!(mask>>=1))
        	break;
    mask=Pmask-Smask[num1];
    for (num2=1;num2<=Gmm_maxn;num2++)                             //~v1.1R~
    	if (!(mask>>=1))
        	break;
//printf("mask=%04x,num1=%d,num2=%d\n",Pmask,num1,num2);
	maskon1=Smask[num1];
	maskon2=Smask[num2];

    if (!Pcase)               //pair in the row
    {
//row
        for (jj=0;jj<Gmm_maxn;jj++)                                //~v1.1R~
            if (jj!=Pcol1 && jj!=Pcol2)
            {
                changesw+=(rcw=xnpdropcan(Ppnpwt,Prow1,jj,maskon1,"m6r",LEVEL_HARDP1));//~v0.1R~
            	if (rcw<0)                                         //~v0.1I~
                	return -1;                                     //~v0.1I~
                changesw+=(rcw=xnpdropcan(Ppnpwt,Prow1,jj,maskon2,"m6r",LEVEL_HARDP1));//~v0.1R~
            	if (rcw<0)                                         //~v0.1I~
                	return -1;                                     //~v0.1I~
			}
    }//row
    if (Pcase==1)               //pair in the row
    {
//col
        for (ii=0;ii<Gmm_maxn;ii++)                                //~v1.1R~
            if (ii!=Prow1 && ii!=Prow2)
            {
                changesw+=(rcw=xnpdropcan(Ppnpwt,ii,Pcol1,maskon1,",m6c",LEVEL_HARDP1));//~v0.1R~
            	if (rcw<0)                                         //~v0.1I~
                	return -1;                                     //~v0.1I~
                changesw+=(rcw=xnpdropcan(Ppnpwt,ii,Pcol1,maskon2,",m6c",LEVEL_HARDP1));//~v0.1R~
            	if (rcw<0)                                         //~v0.1I~
                	return -1;                                     //~v0.1I~
			}
    }//col
//box
    row=Prow1/Gmm_base*Gmm_base;         //top col of box          //~v1.1R~
    col=Pcol1/Gmm_base*Gmm_base;        //left col of box          //~v1.1R~
    if (row==Prow2/Gmm_base*Gmm_base && col==Pcol2/Gmm_base*Gmm_base)    //in same box?//~v1.1R~
        for (ii=row;ii<row+Gmm_base;ii++)                          //~v1.1R~
            for (jj=col;jj<col+Gmm_base;jj++)                      //~v1.1R~
                if (!(ii==Prow1 && jj==Pcol1)
                &&  !(ii==Prow2 && jj==Pcol2))
                {
                	changesw+=(rcw=xnpdropcan(Ppnpwt,ii,jj,maskon1,"m6b",LEVEL_HARDP1));//~v0.1R~
	            	if (rcw<0)                                     //~v0.1I~
    	            	return -1;                                 //~v0.1I~
                	changesw+=(rcw=xnpdropcan(Ppnpwt,ii,jj,maskon2,"m6b",LEVEL_HARDP1));//~v0.1R~
	            	if (rcw<0)                                     //~v0.1I~
    	            	return -1;                                 //~v0.1I~
                }
    return changesw!=0;
}//xnpm6sub
//***************************************************************
//* try and err method
//* rc :1 sunccess,0: fail,4:success(multi level),-1:multiple solution or timeout//~v0.1R~
//***************************************************************
int xnpmethod9(PNPWORKT Ppnpwt)
{
    int   row,col,kk,ccnt,cmsk,rc,num;
    int   *pic,clist[MM_MAXN],okcnt,oknum,taelvl,level,lasttaelvl; //~v0.5R~
    PNPWORKT pnpwt,pnpwtok;
    char  mcase[12];
//************
    taelvl=Ppnpwt->taelvl;
    if (taelvl==MAX_TAELVL)//max level reached
    {
//  	printf("Try and error depth reached to max(%d)\n",MAX_TAELVL);
    	return 0;
	}
    taelvl++;
    if ((rc=xnpsrchleast(Ppnpwt,&row,&col))<=0)                    //~v0.1R~
    	return rc;                                                 //~v0.1R~
    if (Ppnpwt->stat & STAT_MAKE)   //make mode
//      if (Ppnpwt->mxx[row][col].ccnt>2)   //for performance      //~v1.1R~
        if (PMXXIJ(Ppnpwt,row,col)->ccnt>2)                        //~v1.1I~
            return 0;
//listup candidate
	ccnt=0;
//  cmsk=Ppnpwt->mxx[row][col].cmsk;                               //~v1.1R~
    cmsk=PMXXIJ(Ppnpwt,row,col)->cmsk;                             //~v1.1I~
    for (kk=1;kk<=Gmm_maxn;kk++)                                   //~v1.1R~
        if (cmsk & Smask[kk])
            clist[ccnt++]=kk;
//try up to end
	pnpwt=(PNPWORKT)umalloc(sizeof(NPWORKT)*2);
	pnpwtok=pnpwt+1;
	for (kk=0,pic=clist,okcnt=0;kk<ccnt;kk++,pic++)
    {
    	num=*pic;
	    *pnpwt=*Ppnpwt;
    	pnpwt->taelvl=taelvl;
        if (!Stestsw)
	        pnpwt->stat&=~STAT_PILOTMSG;		//no pilot msg when try and err
//printf("tryander start level=%d,row=%d,col=%d,num=%d\n",taelvl,row,col,num);
//xnpprintcan(pnpwt);
//printf("hard2 try and err fix\n");
  		rc=xnpfix(row,col,num,pnpwt,LEVEL_HARD,"m9");
//printf("step down level=%d\n",taelvl);
		if (rc)					//dup or inconsistent(made candidate to 0)
        	continue;
	    rc=xnpsolution(pnpwt);
//printf("tryanderr end level=%d,row=%d,col=%d,num=%d,rc=%d\n",taelvl,row,col,num,rc);
		if (pnpwt->stat & STAT_MULTISOL)   //multiple solution
        {
        	okcnt=0;			//err process
			Ppnpwt->stat |= STAT_MULTISOL;   //multiple solution
        	break;
		}
		if (pnpwt->stat & STAT_TIMEOUT)   //multiple solution      //~v0.1I~
        {                                                          //~v0.1I~
        	okcnt=0;			//err process                      //~v0.1I~
			Ppnpwt->stat |= STAT_TIMEOUT;   //timeout              //~v0.1I~
        	break;                                                 //~v0.1I~
		}                                                          //~v0.1I~
        if (!rc)				//success
        {
        	oknum=num;
        	okcnt++;
//printf("okcnt=%d\n",okcnt);
            if (Stestsw)
                xnpprintnum(2,0,0,pnpwt,0,0);   //print last data
            if (okcnt==1)
			    *pnpwtok=*pnpwt;	//save first ok
            else				//question has multiple solution
            {
            	if (Stestsw)
                	printf("Vague data\n");
                okcnt=0;        //err process
                Ppnpwt->stat |= STAT_MULTISOL;   //multiple solution
                if (!(Ppnpwt->stat & (STAT_RCHK|STAT_MAKE)))    //not redundancy chk
                {
                    xnpprintnum(-3,0,0,pnpwtok,0,0);   //print last data
                    xnpprintnum(-4,0,0,pnpwt,0,0);   //print last data
                }
                break;
            }
		}
	}//all candidate at random
//printf("level=%d,okcnt=%d\n",taelvl,okcnt);
	lasttaelvl=pnpwtok->taelvl;
	ufree(pnpwt);
	if (Ppnpwt->stat & STAT_TIMEOUT)   //multiple solution         //~v0.1I~
    	return -1;                                                 //~v0.1I~
    if (!okcnt)
    	return 0;	//failed
    Ppnpwt->method=0;       //clear previos reset method
//printf("tryanderr okcnt=%d,taelvl=%d\n",okcnt,taelvl);
    if (taelvl!=1)
    {
		Ppnpwt->taelvl=lasttaelvl;
        return 4;			//step up now
	}
    if (lasttaelvl==1)
        level=LEVEL_HARD;
    else
    if (lasttaelvl<=3)
        level=LEVEL_HARDP1;
    else
        level=LEVEL_HARDP2;
    sprintf(mcase,"m9:%2d",lasttaelvl);
//xnpprintcan(pnpwt);
    xnpfix(row,col,oknum,Ppnpwt,level,mcase);
    return 1;
}//xnpmethod9
//**********************************************************************
//* search smallest candidate number place
//* rc:1:found,0:not found,-1:timeout                              //~v0.1R~
//**********************************************************************
int xnpsrchleast(PNPWORKT Ppnpwt,int *Pprow,int *Ppcol)
{
	PMXX  pmxx;                                                    //~v0.5R~
    int   ii,jj,minccnt,ccnt;
#ifdef WNP_CALL
#else	
	#define MSG_CHK_FREQ 10                                            //~v0.1I~
	static time_t Smsgtm;
       time_t tottm;                                               //~v0.1I~
#endif
//************
#ifdef WNP_CALL                                                    //~v0.1I~
	if (GblSubthreadStopReq)	//thread communication with wnp    //~v0.1I~
        if (GblSubthreadStopReq==2)	//timeout                      //~v0.1I~
	    	uerrexit("Time Expired",                               //~v0.1I~
    	    		"タイムアウト");                               //~v0.1I~
        else                                                       //~v0.1I~
	    	uerrexit("Forced Thread Termination",                  //~v0.1I~
    	    		"強制終了");                                   //~v0.1I~
#else                                                              //~v0.1I~
    if (!Stotloop)                                                 //~v0.1I~
        Smsgtm=time(&Stottm0);                                     //~v0.1I~
    if (!(++Stotloop % MSG_CHK_FREQ))                              //~v0.1I~
    {                                                              //~v0.1I~
        time(&tottm);                                              //~v0.1I~
        if (Stmsgfreq && tottm-Smsgtm>=Stmsgfreq)	//each msg freq//~v0.1R~
        {                                                          //~v0.1I~
        	fprintf(stderr,"processing ... %5d times trial,%4d sec expired.\n",//~v0.1I~
							Stotloop,(int)(tottm-Stottm0));        //~v0.1I~
	        Smsgtm=tottm;                                          //~v0.1I~
		}                                                          //~v0.1I~
        if (Srepeatmax && tottm-Stottm0>=Srepeatmax)               //~v0.1R~
        {                                                          //~v0.1I~
            if (!(Ppnpwt->stat & STAT_MAKE))                       //~v0.1R~
            {                                                      //~v0.1I~
  		  		uerrmsg("Timeout;%5d sec expired. ===",            //~v0.1R~
			            "時間切れ;%5d 秒経過 ===",                 //~v0.1R~
						(int)(tottm-Stottm0));                     //~v0.1R~
                Ppnpwt->stat|=STAT_TIMEOUT;                        //~v0.1I~
            }                                                      //~v0.1I~
    		return -1;				//stop calc                    //~v0.1I~
        }                                                          //~v0.1I~
    }                                                              //~v0.1I~
#endif                                                             //~v0.1I~
    pmxx=&Ppnpwt->mxx[0][0];        //candidate count              //~v0.5R~
    for (ii=0,minccnt=10;ii<Gmm_maxn;ii++)                         //~v1.1R~
        for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
        {
            ccnt=pmxx->ccnt;                                       //~v0.5R~
            if (ccnt && ccnt<minccnt)
            {
            	minccnt=ccnt;
                *Pprow=ii;
                *Ppcol=jj;
            }
		}
    return minccnt!=10;
}//xnpsrchleast
//**********************************************************************
//* drop candidate bit sub
//* rc:0-not changed,1:droped candidate,-1:reached to candidate cond//~v0.1R~
//**********************************************************************
int xnpdropcan(PNPWORKT Ppnpwt,int Prow,int Pcol,int Pmask,char *Pcase,int Plevel)
{
	int *pcmsk;
//***************************
//printf("dropcan (%d,%d),mask=%04x,case=%s,level=%04x\n",Prow,Pcol,Pmask,Pcase,Plevel);
//  pcmsk=&Ppnpwt->mxx[Prow][Pcol].cmsk;                           //~v1.1R~
    pcmsk=&PMXXIJ(Ppnpwt,Prow,Pcol)->cmsk;                         //~v1.1R~
    if (*pcmsk & Pmask)
    {
        if (Stestsw)
        {
			xnpprintcan(Ppnpwt);
			printf("dropc row=%d,col=%d,mask=%04x,case=%s\n",Prow,Pcol,Pmask,Pcase);
		}
        *pcmsk&=(Gmm_all_candidate-Pmask);                         //~v1.1R~
//  	Ppnpwt->mxx[Prow][Pcol].ccnt--;                            //~v1.1R~
    	PMXXIJ(Ppnpwt,Prow,Pcol)->ccnt--;                          //~v1.1I~
//  	if (!Ppnpwt->mxx[Prow][Pcol].ccnt)                         //~v1.1R~
    	if (!PMXXIJ(Ppnpwt,Prow,Pcol)->ccnt)                       //~v1.1I~
        	return -1;                                             //~v0.1I~
        Ppnpwt->level|=Plevel;  //hard sw on after prev
        Ppnpwt->method=Pcase;     //
//xnpprintcan(Ppnpwt);
    }
    return 1;
}//xnpdropcan
//***************************************************************
//* interface to xnpfix by  candidate mask
//* rc : 0:ok ,-1:dup err 4:inconsistent
//***************************************************************
int xnpfixbymask(int Prow,int Pcol,int Pmask,PNPWORKT Ppnpwt,int Plevel,char *Pcase)
{
	int num,mask;
//************
	mask=Pmask;
    for (num=1;num<=Gmm_maxn;num++)                                //~v1.1R~
        if (!(mask>>=1))
            break;
	return xnpfix(Prow,Pcol,num,Ppnpwt,Plevel,Pcase);
}//xnpfixbymask
//***************************************************************
//* set fixed number,drop other place candidate
//* rc : 0:ok ,-1:dup err,4:inconsistent(made cnadidate cnt=0)
//***************************************************************
int xnpfix(int Prow,int Pcol,int Pnum,PNPWORKT Ppnpwt,int Plevel,char *Pcase)
{
	PMXX  pmxx;                                                    //~v0.5R~
	int ii,jj,boxrow,boxcol,ibox,maskon,maskof,rc=0,row,col,errsw1=0;
//************
//  if (Stestsw)
//  	xnptrace(Ppnpwt);
//xnpprintcan(Ppnpwt);
	maskon=Smask[Pnum];
	maskof=Gmm_all_candidate-maskon;                               //~v1.1R~
    boxrow=Prow/Gmm_base;                                          //~v1.1R~
    boxcol=Pcol/Gmm_base;                                          //~v1.1R~
    ibox=boxrow*Gmm_base+boxcol;                                   //~v1.1R~
//set fixed info
    Ppnpwt->level |=Plevel;		//dificulty level
//  Ppnpwt->mxx[Prow][Pcol].fnum=Pnum;				//number fixed //~v1.1R~
    PMXXIJ(Ppnpwt,Prow,Pcol)->fnum=Pnum;                           //~v1.1I~
    if (Plevel==LEVEL_INIT)		//initial data setting
    	Ppnpwt->idatano++;
//  Ppnpwt->mxx[Prow][Pcol].fseq=++Ppnpwt->seqno;     //seqno up   //~v1.1R~
    PMXXIJ(Ppnpwt,Prow,Pcol)->fseq=++Ppnpwt->seqno;     //seqno up //~v1.1I~
//dup chk before fixed mask on
	if ((Ppnpwt->fmsk[0][Prow] & maskon)	//already fixed the number in the row
	||  (Ppnpwt->fmsk[1][Pcol] & maskon)	//already fixed the number in the col
	||  (Ppnpwt->fmsk[2][ibox] & maskon))	//already fixed the number in the box
    {
	    if (Ppnpwt->taelvl)
            return -1;
        if (Ppnpwt->stat & (STAT_RCHK|STAT_MAKE))    //not redundancy chk
            return -1;
    	if (Plevel!=LEVEL_INIT)		//initial data setting
        {
	    	xnpprintnum(1,Prow,Pcol,Ppnpwt,Plevel,0);	//print answer as err
	        uerrexit("\nNumber %d at (%d,%d) is duplicated !!\n",
	                 "\nナンバー %d が  %d 行, %d 列 にセットできません!!\n",
						Pnum,Prow,Pcol);
		}
        if (Stestsw)
            printf("fix failed dup data row=%d,col=%d,num=%d\n",Prow,Pcol,Pnum);
        rc=-1;			//initial data case
	}
    Ppnpwt->fmsk[0][Prow]|=maskon; //fixed number mask,row
	Ppnpwt->fmsk[1][Pcol]|=maskon; //fixed number mask,col
	Ppnpwt->fmsk[2][ibox]|=maskon;//fixed number mask,box
    Ppnpwt->fcnt[0][Prow]++; //fixed number count,row
	Ppnpwt->fcnt[1][Pcol]++; //fixed number count,col
	Ppnpwt->fcnt[2][ibox]++;//fixed number count,box
    if (Plevel==LEVEL_INIT)		//initial data setting
    {
	    Ppnpwt->icnt[0][Prow]++;//init data cnt for make puzzle
        Ppnpwt->icnt[1][Pcol]++;//init data cnt for make puzzle
        Ppnpwt->icnt[2][ibox]++;//init data cnt for make puzzle
    }
//  Ppnpwt->mxx[Prow][Pcol].cmsk=0;                   //no candidate//~v1.1R~
    PMXXIJ(Ppnpwt,Prow,Pcol)->cmsk=0;                              //~v1.1I~
//  Ppnpwt->mxx[Prow][Pcol].ccnt=0;                                //~v1.1R~
    PMXXIJ(Ppnpwt,Prow,Pcol)->ccnt=0;                              //~v1.1I~
//  Ppnpwt->mxx[Prow][Pcol].dlvl=Plevel;   //0:init,               //~v1.1R~
    PMXXIJ(Ppnpwt,Prow,Pcol)->dlvl=Plevel;                         //~v1.1I~
//drop candidate
//row
//  pmxx=&Ppnpwt->mxx[Prow][0];                                    //~v1.1R~
    pmxx=PMXXIJ(Ppnpwt,Prow,0);                                    //~v1.1I~
    for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                             //~v1.1R~
        if (pmxx->cmsk & maskon) //now candidate                   //~v0.5R~
        {
//printf("row can off num=%d,(%d,%d) by (%d,%d) mask=%04x\n",Pnum,Prow,jj,Prow,Pcol,pmxx->cmsk);//~v0.5R~
            pmxx->cmsk &=maskof; //drop candidate                  //~v0.5R~
            if (pmxx->ccnt)                                        //~v0.5R~
            {
                if (!--pmxx->ccnt)                                 //~v0.5R~
                    rc=4;           //no candidate place
                if (Stestsw)
                    xnpcmchk(Ppnpwt,pmxx->ccnt,pmxx->cmsk);        //~v0.5R~
            }
            else
                errsw1=1;
        }
//col
    pmxx=&Ppnpwt->mxx[0][Pcol];                                    //~v0.5R~
    for (ii=0;ii<Gmm_maxn;ii++,pmxx+=Gmm_maxn)                     //~v1.1R~
        if (pmxx->cmsk & maskon) //now candidate                   //~v0.5R~
        {
//printf("col can off num=%d,(%d,%d) by (%d,%d) mask=%04x\n",Pnum,ii,Pcol,Prow,Pcol,pmxx->cmsk);//~v0.5R~
            pmxx->cmsk &=maskof; //drop candidate                  //~v0.5R~
            if (pmxx->ccnt)                                        //~v0.5R~
            {
                if (!--pmxx->ccnt)                                 //~v0.5R~
                    rc=4;           //no candidate place
                if (Stestsw)
                    xnpcmchk(Ppnpwt,pmxx->ccnt,pmxx->cmsk);        //~v0.5R~
            }
            else
                errsw1=1;
        }
//box
    row=boxrow*Gmm_base;                                           //~v1.1R~
    col=boxcol*Gmm_base;                                           //~v1.1R~
//  pmxx=&Ppnpwt->mxx[row][col];                                   //~v1.1R~
    pmxx=PMXXIJ(Ppnpwt,row,col);                                   //~v1.1I~
    for (ii=row;ii<row+Gmm_base;ii++,pmxx+=Gmm_next)               //~v1.1R~
        for (jj=col;jj<col+Gmm_base;jj++,pmxx++)                   //~v1.1R~
            if (pmxx->cmsk & maskon) //now candidate               //~v0.5R~
            {
//printf("box can off num=%d,(%d,%d) by (%d,%d) mask=%04x\n",Pnum,ii,jj,Prow,Pcol,pmxx->cmsk);//~v0.5R~
                pmxx->cmsk &=maskof; //drop candidate              //~v0.5R~
                if (pmxx->ccnt)                                    //~v0.5R~
                {
                    if (!--pmxx->ccnt)                             //~v0.5R~
                        rc=4;           //no candidate place
                    if (Stestsw)
                        xnpcmchk(Ppnpwt,pmxx->ccnt,pmxx->cmsk);    //~v0.5R~
                }
                else
                    errsw1=1;
            }
	if (Ppnpwt->stat & STAT_PILOTMSG)
    	if (Plevel!=LEVEL_INIT)		//initial data setting
		    xnpprintnum(1,Prow,Pcol,Ppnpwt,Plevel,Pcase);	//print intermediate
    Ppnpwt->level &=~LEVEL_FIX; //once chked of each fix case
    if (errsw1)
    {
    	xnptrace(Ppnpwt);
        uerrexit("Internal Logic Err;cmsk and ccnt conflict",0);		//inconsistent
	}
    if (rc)
        Ppnpwt->stat|=STAT_DATA_CONFLICT;            //problem err
//xnpprintcan(Ppnpwt);
//printf("pnpwt=%08x,level=%04x\n",Ppnpwt,Ppnpwt->level);
    return rc;		//ok
}//xnpfix
//***************************************************************
//* count mask conflict chk for internal logic err when Stestsw on
//* rc : 1 if err
//***************************************************************
void xnpcmchk(PNPWORKT Ppnpwt,int Pcnt,int Pmsk)
{
    int ii,cnt;
//************
    for (ii=1,cnt=0;ii<=Gmm_maxn;ii++)                             //~v1.1R~
    	if (Pmsk & Smask[ii])
        	cnt++;
	if (cnt!=Pcnt)
    {
    	xnptrace(Ppnpwt);
    	uerrexit("Internal Logic Err;count(%d) and mask(%04x) conflict",0,
        			Pcnt,Pmsk);
	}
	return;
}//xnpcmchk
//***************************************************************
//* last validity chk
//* rc : 0:all fixed,4:free space exist 8:conflict data
//***************************************************************
int xnplastchk(PNPWORKT Ppnpwt)
{
	PMXX  pmxx;                                                    //~v0.5R~
    int   mask,maskon,ii,jj,ibox,row,col,conflictsw=0,incompletesw=0;
//************
//row
	pmxx=&Ppnpwt->mxx[0][0];       //matrix of each plase          //~v0.5R~
    for (ii=0;ii<Gmm_maxn;ii++)                                    //~v1.1R~
    {
        for (jj=0,mask=0;jj<Gmm_maxn;jj++,pmxx++)                  //~v1.1R~
        {
        	maskon=Smask[pmxx->fnum];                              //~v0.5R~
            if (mask & maskon)
            	conflictsw=1;
            else
            	mask|=maskon;
		}//col
        if (mask!=Gmm_all_candidate)        //only one candidate   //~v1.1R~
        	incompletesw=1;
    }//row
//col
    for (jj=0;jj<Gmm_maxn;jj++)                                    //~v1.1R~
    {
        pmxx=&Ppnpwt->mxx[0][jj];       //matrix of each plase     //~v0.5R~
        for (ii=0,mask=0;ii<Gmm_maxn;ii++,pmxx+=Gmm_maxn)          //~v1.1R~
        {
        	maskon=Smask[pmxx->fnum];                              //~v0.5R~
            if (mask & maskon)
            	conflictsw=1;
            else
            	mask|=maskon;
		}//row
        if (mask!=Gmm_all_candidate)        //only one candidate   //~v1.1R~
        	incompletesw=1;
    }//col
//box
    for (ibox=0;ibox<Gmm_maxn;ibox++)  //all box                   //~v1.1R~
    {
        row=(ibox/Gmm_base)*Gmm_base;     //box top row            //~v1.1R~
        col=(ibox%Gmm_base)*Gmm_base;     //box left col           //~v1.1R~
//      pmxx=&Ppnpwt->mxx[row][col];       //matrix of each plase  //~v1.1R~
	    pmxx=PMXXIJ(Ppnpwt,row,col);                               //~v1.1I~
        for (ii=row,mask=0;ii<row+Gmm_base;ii++,pmxx+=Gmm_next)    //~v1.1R~
            for (jj=col;jj<col+Gmm_base;jj++,pmxx++)               //~v1.1R~
            {
	        	maskon=Smask[pmxx->fnum];                          //~v0.5R~
            	if (mask & maskon)
            		conflictsw=1;
            	else
            		mask|=maskon;
			}
        if (mask!=Gmm_all_candidate)        //only one candidate   //~v1.1R~
        	incompletesw=1;
	}//all box
    if (conflictsw)
    	return 8;
    if (incompletesw)
    	return 4;
    return 0;		//ok
}//xnplastchk
//***************************************************************
//* print final result
//* opt : 0:init data,1:intermediate result,2:last success data,
//*        -1:last failed,-2:aborted,-3/-4:multiple solution
//***************************************************************
void xnpprintnum(int Popt,int Prow,int Pcol,PNPWORKT Ppnpwt,int Plevel,char *Pcase)
{
	PMXX  pmxx;                                                    //~v0.5R~
    int   ii,jj,kk,level,num,rchkmode;                             //~v1.1R~
    char  *clvl,*clvl2,*subcase;
//************
	if (!(subcase=Ppnpwt->method))
    	subcase="";		//candidate bit reset method not worked
    else
    	Ppnpwt->method=0;		//printed
	rchkmode=Ppnpwt->stat & STAT_RCHK;
	switch(Popt)
    {
    case 0:
		uerrmsg("------ Question ---- %d space --",
		        "------ 問題 ---- %d space --",
				Ppnpwt->idatano);
        break;
    case 1:
	    if (Ppnpwt->level & LEVEL_HARDP2_F)	//hard sw on after prev
        	clvl="Hard++";
        else
	    if (Ppnpwt->level & LEVEL_HARDP1_F)	//hard sw on after prev
        	clvl="Hard+";
        else
	    if (Ppnpwt->level & LEVEL_HARD_F)	//hard sw on after prev
        	clvl="Hard";
        else
        if (Plevel & LEVEL_MEDIUM_F)
            clvl="Medium";
        else
            clvl="Easy";
		printf("Seq=+%2d (%2d) (%s)",Ppnpwt->seqno-Ppnpwt->idatano,Ppnpwt->seqno,clvl);
        if (Stestsw && Pcase)
        	printf(" %s %s---\n",Pcase,subcase);
        else
        	printf("\n");
        break;
    case 2:
    case -3: 		//multiple solution
    case -4: 		//multiple solution
		uerrmsg("------ Answer ------\n",
				"------ 答 ------");
        break;
	default:
    	if (Popt==-1)
            uerrmsg("---- Question data conflict! ----",
					"---- 問題のデータに矛盾が有ります----");
		uerrmsg("------ Aborted -----",
				"------ 頓挫 ------");
        ubell();                                                   //~v0.5I~
    }
    pmxx=&Ppnpwt->mxx[0][0];     //answer                          //~v0.5R~
    for (ii=0;ii<Gmm_maxn;ii++)                                    //~v1.1R~
    {
        printf("   ");                                             //~v0.5R~
        for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
        {
            num=pmxx->fnum;                                        //~v0.5R~
            if (num)
                if (!Popt)
					if (pmxx->dlvl==LEVEL_INIT)                    //~v0.5R~
                    	printf("%4d",num);                         //~v0.5R~
                    else
						if (pmxx->flag==MXXF_PATERN)               //~v0.5R~
		                	printf(" +%2d",num);                   //~v0.5R~
                        else
		                	printf("   _");                        //~v0.5R~
                else
					if (rchkmode)
						if (pmxx->dlvl==LEVEL_INIT)                //~v0.5R~
                            printf(" *%2d",num);                   //~v0.5R~
                        else
                        {                                          //~v1.1I~
//                          if (ii==Prow && jj==Pcol) //placed now //~v1.1R~
//redundancy level chk                                             //~v1.1I~
                            for (kk=0;kk<=Prow;kk++) //Prow is Srchkwk level//~v1.1I~
                                if (ii==Srchkwk[kk][0] && jj==Srchkwk[kk][1])//~v1.1R~
                                    break;                         //~v1.1I~
                            if (kk<=Prow) //found in redundancy list//~v1.1R~
	                            printf(" =%2d",num);               //~v0.5R~
    	                    else
                            	printf("  %2d",num);               //~v0.5R~
                    	}                                          //~v1.1I~
                    else
                        if (Popt==1 && ii==Prow && jj==Pcol) //placed now
                            printf(" *%2d",num);                   //~v0.5R~
                        else
                        	if (Popt==2)
                        		if (pmxx->dlvl==LEVEL_INIT)        //~v0.5R~
                            		printf("  %2d",num);           //~v0.5R~
                            	else
                            		printf(" *%2d",num);           //~v0.5R~
                            else
                            	printf("  %2d",num);               //~v0.5R~
            else
                printf("   _");                                    //~v0.5R~
            if (jj%Gmm_base==Gmm_base-1)                           //~v1.1R~
                printf("  ");
        }//a line
        if (ii%Gmm_base==Gmm_base-1)                               //~v1.1R~
            printf("\n\n");
        else
            printf("\n");
    }//all line

	switch(Popt)
    {
    case 2: 		//success
//printf("case 2:ppnpwt=%08x,level=%04x\n",Ppnpwt,Ppnpwt->level);
        if (Ppnpwt->stat & STAT_PILOT)
        {
            level=Ppnpwt->level;
            if (level & LEVEL_HARDP2_S)
                clvl="Hard++";
            else
            if (level & LEVEL_HARDP1_S)
                clvl="Hard+";
            else
            if (level & LEVEL_HARD_S)
                clvl="Hard";
            else
            if (level & LEVEL_MEDIUM_S)
                clvl="Medium";
            else
                clvl="Easy";
        	if (Ppnpwt->stat & STAT_ANSOFMAKE)
            	clvl2="Level=";
            else
            	clvl2="";
        }
        else
        	clvl2=
            clvl="";
        if (Ppnpwt->stat & STAT_ANSOFMAKE)                         //~v0.1I~
			uerrmsg("====== Make Success ======  %s%s !!",         //~v0.1I~
		    	    "====== 作成完了 ======  %s%s !!",             //~v0.1I~
				clvl2,clvl);                                       //~v0.1I~
        else                                                       //~v0.1I~
			uerrmsg("====== Success ======  %s%s !!",              //~v0.1R~
		    	    "====== 完了 ======  %s%s !!",                 //~v0.1R~
				clvl2,clvl);
        break;
	case -2:
        if (Stestsw)
            xnptrace(Ppnpwt);
		xnpprintcan(Ppnpwt);
		uerrmsg("?????? Failure (%d space remained) ??????",
		        "?????? 失敗です ( %d 個 残プレース) ??????",
				Gmm_totn-Ppnpwt->seqno);                           //~v1.1R~
        ubell();
        break;
	case -3:
        uerrmsg(" OR\n",
				" と\n");
        break;
	case -4:
		uerrmsg("?????? Question data is vague ??????",
		        "?????? 問題データにあいまいな個所が有ります ??????");
        ubell();
	}
    return;
}//xnpprintnum
//***************************************************************
//* print candidate
//***************************************************************
void xnpprintcan(PNPWORKT Ppnpwt)
{
	PMXX  pmxx;                                                    //~v0.5R~
    char  clist[24],*pc;
    int   ii,jj,kk,cmsk,cctr;
//************
	uerrmsg("------ Remaining Candidate List ------\n",
			"------ 残った場所に置く事が出来るナンバー ------\n");

    pmxx=&Ppnpwt->mxx[0][0];     //answer                          //~v0.5R~
    for (ii=0;ii<Gmm_maxn;ii++)                                    //~v1.1R~
    {
        printf("      ");
        for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
        {
            if (pmxx->fnum)                                        //~v0.5R~
                printf("(%d)        ",pmxx->fnum);                 //~v0.5R~
            else
            {
                cmsk=pmxx->cmsk;                                   //~v0.5R~
                pc=clist;
                clist[0]='_';           //when no candidate
                clist[1]=0;             //strz
                for (pc=clist,cctr=0,kk=1;kk<=Gmm_maxn;kk++)       //~v1.1R~
                    if (cmsk & Smask[kk])
                    {
                        if (cctr)
                            *pc++=',';
                        cctr++;
                        *pc++=(char)(kk+'0');
                        *pc=0;      //strz
                    }
                printf("%-10s ",clist);
            }

            if (jj%Gmm_base==Gmm_base-1)                           //~v1.1R~
                printf("  ");
        }//a line
        if (ii%Gmm_base==Gmm_base-1)                               //~v1.1R~
            printf("\n\n");
        else
            printf("\n");
    }//all line
    return;
}//xnpprintcan
//***************************************************************
//* print final result
//***************************************************************
void xnptrace(PNPWORKT Ppnpwt)
{
	PMXX  pmxx;                                                    //~v0.5R~
    int   ii,jj,*pi;
//************
	printf("------ seq=%d ----\n",Ppnpwt->seqno);

    printf("\n num     \n");
    pmxx=&Ppnpwt->mxx[0][0];                                       //~v0.5R~
    for (ii=0;ii<Gmm_maxn;ii++)                                    //~v1.1R~
    {
        for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
            printf("%3d",pmxx->fnum);                              //~v0.5R~
		printf("\n");
    }//all line

    printf("\n cmask   \n");
    pmxx=&Ppnpwt->mxx[0][0];                                       //~v0.5R~
    for (ii=0;ii<Gmm_maxn;ii++)                                    //~v1.1R~
    {
        for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
            printf("  %04x ",pmxx->cmsk);                          //~v0.5R~
		printf("\n");
    }//all line

    printf("\n ccntr   \n");
    pmxx=&Ppnpwt->mxx[0][0];                                       //~v0.5R~
    for (ii=0;ii<Gmm_maxn;ii++)                                    //~v1.1R~
    {
        for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
            printf("%3d",pmxx->ccnt);                              //~v0.5R~
		printf("\n");
    }//all line

    printf("\n level   \n");
    pmxx=&Ppnpwt->mxx[0][0];                                       //~v0.5R~
    for (ii=0;ii<Gmm_maxn;ii++)                                    //~v1.1R~
    {
        for (jj=0;jj<Gmm_maxn;jj++,pmxx++)                         //~v1.1R~
            printf(" %02x ",pmxx->dlvl);                           //~v0.5R~
		printf("\n");
    }//all line

    printf("\n line mask\n");
    pi=&Ppnpwt->fmsk[0][0];
    for (ii=0;ii<Gmm_base;ii++)                                    //~v1.1R~
    {
        for (jj=0;jj<Gmm_maxn;jj++,pi++)                           //~v1.1R~
            printf("  %04x ",*pi);
		printf("\n");
    }//all line

    return;
}//xnptrace

