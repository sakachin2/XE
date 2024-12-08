//CID://+v1.1R~:                                                   //+v1.1R~
//*************************************************************
//*xfdd.c :dump floppy disk                                        //~v295R~
//*************************************************************    //~v053R~
//************************************************************* //~5617I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <direct.h>                                             //~5708I~
#include <io.h>                                                 //~5A14I~
#include <errno.h>                                                 //~v053R~
#include <dos.h>                                                   //~v295R~
#include <bios.h>                                                  //~v295I~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <ustring.h>                                               //~v016R~
#include <utrace.h>                                                //~v036I~
//*******************************************************
#define SECTSIZE	512                                            //~v295R~
#define READCNT 	40                                             //~v295R~
#define HEADSIZE 	2                                              //~v295R~
#define CYLSIZE 	80                                             //~v295R~
#define TRKSIZE 	18                                             //~v295R~
//*******************************************************      //~4C18I~
int resetdisk(int Pdrv);                                           //~v295I~
int diskparm(int Pdrv);                                            //~v295I~
int readsector(int Pdrv,int Phead,int Pcyl,int Psector,int Psectorcnt,char *Pbuff);//~v295I~
int  breakchk(void);                                               //~v295R~
//*******************************************************      //~4C18I~
int main(int argc,char **argp)                                     //~v295R~
{                                                              //~4C18I~
	char *buff,*buff0,*fnm;                                        //~v295R~
    int rc,ii,jj,kk,mm,drvno=0,startcyl=0,cylcnt=CYLSIZE,len,retry=1;//~v295R~
    int ll;                                                        //~v295I~
    FILE *fh;                                                      //~v295R~
//*********************************                            //~4C18I~
	if (argc<=2)                                                   //~v295I~
    {                                                              //~v295I~
    	printf("p1=out-fnm,p2=drvno(0:A,1:B),p3=start cyl,p4=read cyl count");//~v295R~
        exit(1);                                                   //~v295I~
    }                                                              //~v295I~
    fnm=argp[1];                                                   //~v295I~
                                                                   //~v295I~
	if (argc>2)                                                    //~v295I~
    	drvno=atoi(argp[2]);                                       //~v295I~
	if (argc>3)                                                    //~v295I~
    	startcyl=atoi(argp[3]);                                    //~v295I~
	if (argc>4)                                                    //~v295I~
    	cylcnt=atoi(argp[4]);                                      //~v295I~
	if (argc>5)                                                    //~v295I~
    	retry=atoi(argp[5]);                                       //~v295I~
                                                                   //~v295I~
	len=TRKSIZE*SECTSIZE;	//buff for 1 cyl                       //~v295R~
	buff=malloc((UINT)len);	//buff for 1 cyl                       //~v295I~
	buff0=malloc((UINT)len);	//buff for 1 cyl                   //~v295I~
	memset(buff0,0,(UINT)len);	//buff for 1 cyl                   //~v295I~
                                                                   //~v295I~
	fh=fopen(fnm,"wb");                                            //~v295R~
    if (!fh)                                                       //~v295R~
    {                                                              //~v295I~
    	printf("%s open failed rc=%d\n",fnm,errno);                //~v295I~
        exit(4);                                                   //~v295I~
    }                                                              //~v295I~
    printf("start cyl=%d,read cyl=%d\n",startcyl,cylcnt);          //~v295I~
    printf("Hit Esc key to break\n");                              //+v1.1I~
                                                                   //~v295I~
	resetdisk(drvno);                                              //~v295I~
	diskparm(drvno);                                               //~v295I~
    for (ii=startcyl,jj=0;ii<CYLSIZE && jj<cylcnt;ii++,jj++)    //cyls//~v295R~
    {                                                              //~v295I~
    	for (kk=0;kk<HEADSIZE;kk++)    //head                      //~v295R~
        {                                                          //~v295I~
            for (mm=0;mm<retry;mm++)                               //~v295I~
            {                                                      //~v295I~
                memset(buff,0,(UINT)len);                          //~v295R~
                rc=readsector(drvno,kk/*head*/,ii/*cyl*/,1/*sector*/,TRKSIZE,buff);//~v295R~
                if (rc) //track read failed                        //~v295R~
                    for (ll=1;ll<TRKSIZE;ll++)  //read 1 sector    //~v295R~
                    {                                              //~v295R~
                        memset(buff,0,SECTSIZE);                   //~v295R~
                        rc=readsector(drvno,kk/*head*/,ii/*cyl*/,ll/*sector*/,1,buff);//~v295R~
                        if (rc)                                    //~v295R~
                            printf("sector read failed cyl=%d,head=%d,sect=%d,rc=%d\n",ii,kk,ll,rc);//~v295R~
                        if (SECTSIZE!=fwrite(buff,1,SECTSIZE,fh))  //~v295R~
                        {                                          //~v295R~
                            printf("write failed at cyl=%d,head=%d,sect=%d,rc=%d\n",ii,kk,ll,errno);//~v295R~
                            exit(4);                               //~v295R~
                        }                                          //~v295R~
                    }                                              //~v295R~
                else                                               //~v295R~
                {                                                  //~v295I~
                    if ((UINT)len!=fwrite(buff,1,(UINT)len,fh))    //~v295R~
                    {                                              //~v295R~
                        printf("write failed at cyl=%d,head=%d,rc=%d\n",ii,kk,errno);//~v295R~
                        exit(4);                                   //~v295R~
                    }                                              //~v295R~
                    break;                                         //~v295I~
                }                                                  //~v295I~
				resetdisk(drvno);                                  //~v295I~
            }//retry                                               //~v295I~
        }//head                                                    //~v295R~
    }//cyl                                                         //~v295R~
    fclose(fh);                                                    //~v295I~
    return 0;                                                      //~v295I~
}//main                                                            //~v295I~
//*******************************************************          //~v295I~
//*read sector                                                     //~v295I~
//*return:rc                                                       //~v295I~
//*******************************************************          //~v295I~
int resetdisk(int Pdrv)                                            //~v295I~
{                                                                  //~v295I~
	union 	REGS	reg;                                           //~v295I~
	struct 	SREGS 	segreg;                                        //~v295I~
	char wk[512];                                                  //~v295I~
	char *pc;                                                      //~v295I~
//*********************************                                //~v295I~
	reg.h.dl=Pdrv;			//drive no(0,1,...)                    //~v295I~
	reg.h.ah=0x00;			//reset disk                           //~v295I~
	int86(0x13,&reg,&reg);                                         //~v295I~
	if (reg.x.cflag)				//carry                        //~v295I~
    	printf("reset disk failed rc=%d\n",reg.h.ah);              //~v295I~
 	return 0;                                                      //~v295I~
}//readsector                                                      //~v295I~
//*******************************************************          //~v295I~
//*display disk parm                                               //~v295I~
//*return:rc                                                       //~v295I~
//*******************************************************          //~v295I~
int diskparm(int Pdrv)                                             //~v295I~
{                                                                  //~v295I~
	union 	REGS	reg;                                           //~v295I~
	struct 	SREGS 	segreg;                                        //~v295I~
	char wk[512];                                                  //~v295I~
	char *pc;                                                      //~v295I~
//*********************************                                //~v295I~
	reg.h.dl=Pdrv;			//drive no(0,1,...)                    //~v295I~
	reg.h.ah=0x08;			//reset disk                           //~v295I~
	int86(0x13,&reg,&reg);                                         //~v295I~
    printf("disk parm head=%d,cyl=%d,sector=%d\n",                 //~v295I~
			reg.h.dh,reg.h.ch,reg.h.cl);                           //~v295I~
 	return 0;                                                      //~v295I~
}//readsector                                                      //~v295I~
//*******************************************************          //~v295I~
//*read sector                                                     //~v295I~
//*return:rc                                                       //~v295I~
//*******************************************************          //~v295I~
int readsector(int Pdrv,int Phead,int Pcyl,int Psector,int Psectorcnt,char *Pbuff)//~v295I~
{                                                                  //~v295I~
	union 	REGS	reg;                                           //~v295I~
	struct 	SREGS 	segreg;                                        //~v295I~
	char wk[512];                                                  //~v295I~
	char *pc;                                                      //~v295I~
//*********************************                                //~v295I~
	if (breakchk())                                                //~v295I~
    {                                                              //~v295I~
    	printf("Break by Esc Key\n");                              //~v295I~
        exit(4);                                                   //~v295I~
    }                                                              //~v295I~
	reg.h.dl=Pdrv;			//drive no(0,1,...)                    //~v295I~
	reg.h.dh=Phead;			//head  no(0,1,...)                    //~v295I~
	reg.h.ch=Pcyl & 0xff; 			//cylinder(0,1,...)            //~v295I~
	reg.h.cl=((Pcyl & 0x30)>>2)+(Psector & 0x3f); //cylinder+sector//~v295I~
	reg.h.al=Psectorcnt;			//read sector count            //~v295I~
	reg.h.ah=0x02;					//read sector                  //~v295I~
    segreg.es=FP_SEG(Pbuff);			//output dir name ptr      //~v295I~
	reg.x.bx=FP_OFF(Pbuff);			//output dir name ptr          //~v295I~
	int86x(0x13,&reg,&reg,&segreg);                                //~v295R~
    return reg.h.ah;                                               //~v295R~
}//readsector                                                      //~v295I~
//*******************************************************          //~v295I~
//*ESC key press chk                                               //~v295I~
//*return:rc  1:breaked                                            //~v295I~
//*******************************************************          //~v295I~
int  breakchk(void)                                                //~v295R~
{                                                                  //~v295I~
	int ch;		//v4.7r                                            //~v295I~
//***************                                                  //~v295I~
	ch=_bios_keybrd(_KEYBRD_READY);		//v7.0r                    //~v295I~
    if (ch)                                                        //~v295I~
    {                                                              //~v295I~
		ch=_bios_keybrd(_KEYBRD_READ);	//v7.0r                    //~v295R~
		if ((ch&255)==0x1b)				//ESC                      //~v295I~
        	return 1;                                              //~v295I~
    }                                                              //~v295I~
    return 0;                                                      //~v295I~
}//breakchk                                                        //~v295I~
