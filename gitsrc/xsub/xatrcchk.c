//***********************************************************
//* XATRCCHK.C :ualloc trace chk
//**********************************************/
//*parm  : ualloc trace file name              */
//*return: 0:normal                            */
//*        else error                          */
//**********************************************/
//***********************************************************
#define VER "V1.0"   //version
//***********************************************************
#define PGMID   "XATRCCHK"
#define RBUFFSZ 4096
#define MAXREC  10000
//*************************************************************
#ifdef DOS                           

#else                               

#define INCL_BASE                     
#include <os2.h>         

#endif                               
//*************************************************************
#include <time.h>     
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    
#include <string.h>   

#include <ulib.h>
#include <uerr.h>
#include <ufile.h>
#include <ualloc.h>
//*********************************************************************
static FILE *openinput(char *Ppfile);
static void help(void);
static void fileproc(char *Pfilename,FILE *Pinputfh);
static int getinput(UCHAR *Pfilenm,FILE *Pfh);
static char Sline[RBUFFSZ];
static FILE *inputfh=NULL;        //handle
//*********************************************************************
int main(int parmc,char *parmp[])
{
	char *cptr,ch;         //char ptr work
	int parmno,posparmno=0; //parm count work
	char pgmver[18],*inpfname;
//*************************
	sprintf(pgmver,"%s:%s:",PGMID,VER);
	uerrexit_init(pgmver,stdout,0,0,0);//no mapfile,no exit,no exit parm

	if (parmc<2) //no parm
	{
	    help();
	    exit(4);
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
    if (*(++cptr)==':')               // /o:x format      
      cptr++;                         //skip :
    switch(toupper(ch))       //option     
    {                                                     
//**************************
//* help msg      /H*
//**************************
    case '?':
    case 'H':
	  help();
      exit(4);
      break;
//**************************
//* option err             *
//**************************
    default:                           //not option 
		uerrexit("\nundefined option parm(%s)",
					"\n%s は認識できません",
					parmp[parmno]);
    }//switch  by first option byte
  }
  else
  {//positional parmno
    posparmno++;
    switch (posparmno)
    {
//**************************
//* input file             *
//**************************
    case  1:          //first parm 
      inpfname=cptr;  
      break;                                 
//************************************
    default:
	 	uerrexit("\ntoo many positional parameter(%s)",
					"\nパラメータが多過ぎます(%s)",
					cptr);
    }//switch by parmno

  }//option or posparm
}//for all parm
//***no pos parm chk
	if (posparmno!=1)
		uerrexit("\nspecify input and output file name.",
    				"\n入力ファイルを指定して下さい");
	inputfh=openinput(inpfname);
	fileproc(inpfname,inputfh);
	fclose(inputfh);

	return 0;

}//end main

//**********************************************************************
//* main process
//**********************************************************************
void fileproc(char *Pfilename,FILE *Pinputfh)
{
typedef struct _ALLOCREC {LONG addr;LONG len;} ALLOCREC;
	ALLOCREC *pallocrec,*pallocreco,*pallocrecs;
	int allocctr=0,ii;
	LONG freeaddr,freelen;
	int readctr=0;
	UCHAR *pc;
//*********
	pallocrec=pallocreco=malloc(sizeof(ALLOCREC)*MAXREC);

	while(!getinput(Pfilename,Pinputfh))     //until eof
	{
		readctr++;
		if (!memcmp(Sline,"alloc",5))
		{
			if (allocctr==MAXREC)
				uerrexit("record count overflow(max %d)\n",0,MAXREC);
			pallocrec->addr=strtol(Sline+11,&pc,16);//conv xxxxxxxx 
			pallocrec->len=strtol(Sline+24,&pc,16);//conv xxxxxxxx 
			allocctr++;
			pallocrec++;
		}
		else
		{
			freeaddr=strtol(Sline+11,&pc,16);//conv xxxxxxxx 
			freelen=strtol(Sline+24,&pc,16);//conv xxxxxxxx 
			pallocrecs=pallocreco;
			for (ii=0;ii<allocctr;ii++,pallocrecs++)
				if (freeaddr==pallocrecs->addr)
				{
					if (freelen!=pallocrecs->len)
						uerrmsg("rec %d:addr %08X,alloclen(%08X) != freelen(%08X)\n",0,
								readctr,freeaddr,pallocrecs->len,freelen); 
					pallocrecs->addr=0;
					break;
				}
			if (ii==allocctr)
				uerrmsg("rec %d:addr %08X is not allocated len=%08X\n",0,
						readctr,freeaddr,freelen); 
		}
	}//until eof
	pallocrecs=pallocreco;
	for (ii=0;ii<allocctr;ii++,pallocrecs++)
		if (pallocrecs->addr)
			uerrmsg("rec %d:addr %08X,alloclen(%08X) was not freeed\n",0,
					ii,pallocrecs->addr,pallocrecs->len); 
	return;
}//procfile
//**********************************************************************
// find and open input file
//**********************************************************************
FILE *openinput(char *Ppfile)    
{
	FILE *fh;
  	if (!(fh=fopen(Ppfile,"r")))  //open input fail
		uerrexit("\ninput file(%s) open err",
					"\n入力ファイル(%s) のオープンエラー",
						Ppfile);
	return fh;
}//openinput

//**********************************************************************
//* get 1 byte input char		
//**********************************************************************
int getinput(UCHAR *Pfilenm,FILE *Pfh)
{
	int len;
static readcount;
//****************
	readcount++;
	if (!fgets(Sline,RBUFFSZ,Pfh))	//null return if error or eof
		if (ferror(Pfh))
			uerrexit("\n%s read error",0,Pfilenm);
		else
			return 4;
	len=(int)strlen(Sline);			//read len
	if (*(Sline+len-1)!='\n')
		uerrmsg("\n%s has too long record over %d byte at line %d",0,
				Pfilenm,RBUFFSZ-1,readcount);
	return 0;
}//end of getinput

//**********************************************************************
//* write help msg  
//**********************************************************************
void help(void)
{
//*******************
	uerrmsg("ualloc trace file chk program (%s).\n",
			"ualloc トレースファイル　チェック PGM (%s).\n",
			__DATE__);
	uerrmsg("format: %s in-file \n",
			" 形式 : %s 入力ファイル \n",
			PGMID);
	return;
}//help
