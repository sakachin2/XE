//CID://+v1.0R~:                                                   //+v1.0R~
//***********************************************************
//* XAGP.C :print AGNYAN\AGNES browse output spool file            //~v1.0R~
//*           cut by line size and drop ecxept asm list
//***********************************************************
//***********************************************************

#define VER "V1.0"   //version
#define PGM "XAGP"                                                 //~v1.0R~

//**********************************************/
//*parm1 : in-file
//*parm2 : out-file
//*parm3 : line size
//*r.c   : 0 :normal,else err
//**********************************************/
//*
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>

#ifdef DOS
	#include <errno.h>
#else
	#define INCL_BASE
	#include <os2.h>
#endif

//*********************************************************************
#include <ulib.h>
#include <uerr.h>
//*********************************************************************
#define MAXBUFFSZ 32000                                            //~v1.0R~
#define HELPMSG 	uerrhelpmsg(stdout,stderr,
//*********************************************************************
static char *Spgm=PGM,*Sver=VER;
static char *Sinpf,*Soutf;
static int  Sinpctr,Soutctr,Snotmultctr,Sskipctr,Sgetctr;          //~v1.0R~
static int Slinesz=80;
static int Sbuffsz=MAXBUFFSZ;
//********************
void parmchk(int,char *[]);
void titlemsg(void);
void help(void);
void optionerr(char *type,char* value);
int mainproc(void);
//*********************************************************************
//* parm    :infile,outfile,cut-linesz,buffsz
//* return 0:
//*        1:unmatch exist
//*        4:encountered error condition
//*********************************************************************
int main(int parmc,char *parmp[])
{
	int rc;
//**********************************
//* main
//**********************************
	parmchk(parmc,parmp);
//*navigate
  	rc=mainproc();
//printf("rc=%d\n",rc);
    uerrmsg("\ninput = %d record(by %d read,%d record is not multiple of line size),\n\
output = %d record.(%d record skipped)",0,                         //~v1.0R~
			Sinpctr,Sgetctr,Snotmultctr,Soutctr,Sskipctr);         //~v1.0R~
	titlemsg();
	return rc;
}//end main
//**********************************************************************
//*mainproc
//**********************************************************************
int mainproc(void)
{
	FILE *fhi,*fho;
    char *buff,*pc,savec;
    UINT ulen,ulen2,ulen3,reslen;                                  //~v1.0R~
    int buffsz,endsw;                                              //~v1.0R~
//**********************
	if (!(fhi=fopen(Sinpf,"r")))
    	uerrapi1x("fopen",Sinpf,errno);
	if (Soutf)
    {
    	if (!(fho=fopen(Soutf,"w")))                               //~v1.0R~
        	uerrapi1x("fopen",Soutf,errno);
	}
    else
    	fho=stdout;
	buffsz=Sbuffsz+Slinesz+1;                                      //~v1.0R~
    if (buffsz<0)                                                  //~v1.0I~
		uerrexit("too large linesize parm(linesz=%d)",0,           //~v1.0I~
					Slinesz);                                      //~v1.0I~
    buff=malloc((UINT)buffsz);                                     //~v1.0R~
    if (!buff)
		uerrexit("buffer allocation err(size=x%04x)",0,
					buffsz);                                       //~v1.0R~
    reslen=0;                                                      //~v1.0I~
	while(fgets(buff+reslen,(int)(buffsz-reslen),fhi))             //~v1.0R~
    {
    	Sgetctr++;                                                 //~v1.0R~
    	ulen=strlen(buff);
        if (*(buff+ulen-1)=='\n')                                  //~v1.0R~
        {                                                          //~v1.0I~
	    	Sinpctr++;                                             //~v1.0I~
			endsw=1;                                               //~v1.0R~
        	ulen--;			//drop last \n                         //~v1.0R~
        }                                                          //~v1.0I~
        else                                                       //~v1.0I~
        	endsw=0;		//continue to next line                //~v1.0I~
        pc=buff;
        while(ulen)
        {
        	if ((UINT)Slinesz>ulen)
            {
            	ulen2=ulen;
                Snotmultctr++;
			}
			else
            	ulen2=(UINT)Slinesz;
            if (ulen2==(UINT)Slinesz || endsw)   //middle or last with \n//~v1.0R~
            {                                                      //~v1.0I~
                if (*pc=='-' || *pc=='>')                          //~v1.0R~
                	Sskipctr++;                                    //~v1.0R~
    			else                                               //~v1.0R~
                {                                                  //~v1.0R~
                    Soutctr++;                                     //~v1.0R~
                	savec=*(pc+ulen2);                             //~v1.0I~
                	*(pc+ulen2)='\n';                              //~v1.0I~
                    ulen3=ulen2+1;                                 //~v1.0I~
                    if (fwrite(pc,1,ulen3,fho)!=ulen3)             //~v1.0R~
        				uerrexit("output failed at input line no.%d,output line no.%d",0,//~v1.0R~
        						Sinpctr,Soutctr);                  //~v1.0R~
                	*(pc+ulen2)=savec;                             //~v1.0I~
    			}                                                  //~v1.0R~
    			ulen-=ulen2;                                       //~v1.0R~
                pc+=ulen2;                                         //~v1.0R~
                reslen=0;                                          //~v1.0I~
            }//middle or last with \n                              //~v1.0I~
            else	//last residual                                //~v1.0I~
            {                                                      //~v1.0I~
            	memcpy(buff,pc,ulen2);                             //~v1.0I~
                reslen=ulen2;                                      //~v1.0I~
                ulen=0;                                            //~v1.0I~
            }                                                      //~v1.0I~
        }//output loop
    }//input loop
    if (Sgetctr && !endsw)  	//last has no \n                   //~v1.0R~
    	Sinpctr++;                                                 //~v1.0I~
    return 0;
}//mainproc
//**********************************************************************
//*parameter chk
//**********************************************************************
void parmchk(int parmc,char *parmp[])
{
    unsigned char c;    //read char
    char *cptr,*cptr0;         //char ptr work
    int parmno; //parm count work
    int posparmno=0; //parm count work
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
        if(*cptr=='/'||*cptr=='-')
        {//option
          	c=*(++cptr);                      //first option byte
            switch(toupper(c))             //option
            {
//**************************
//* cmd string     /?      *
//**************************
            case '?':           //cmd string start
            case 'H':           //apply to file
                help();
                exit(0);
              	break;
			default:
              	uerrexit("undefined option parm(%s)\n",
              				"未定義パラメータ(%s)\n",
						cptr0);
			}
            continue;
		}//option
//pos parm
		posparmno++;
		switch (posparmno)
		{
//**************************
//* input file             *
//**************************
		case  1:          //first parm
  			Sinpf=cptr0;
  			break;
//**************************
//* output file            *
//**************************
		case 2:
  			Soutf=cptr0;
  			break;
//**************************
//* line size              *
//**************************
		case 3:
  			Slinesz=atoi(cptr0);
            if (Slinesz<=0)
            	optionerr("Line size(3rd parm)",cptr0);
  			break;
//************************************
		default:
  			uerrexit("too many %s positional parameter(%s)\n",
  			         "多過ぎる %s の定位置パラメータ(%s)\n",
						Spgm,cptr0);
		}//switch by parmno
	}//for all parm
//chk more
  	if (!posparmno)
    {
        help();
        exit(0);
	}
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
"%s : utility cut AGNES browse screen print file by line size\n",0,
		Spgm);
	HELPMSG
"format: %s in-file [out-file] [line-size] \n",0,                  //~v1.0R~
		Spgm);
	HELPMSG
"  in-file   :AGNES browse screen print filename.\n",0);           //~v1.0R~
	HELPMSG
"  out-file  :optional output filename(stdout if omitted)\n",0);   //~v1.0R~
	HELPMSG
"  line-size :optional line size(default is %d)\n",0,
		Slinesz);
	HELPMSG
"(ex.): %s 000015.spl prn %d\n",0,
        Spgm,Slinesz);
	titlemsg();
	return;
}//help
//**********************************************************************
//* write help msg
//**********************************************************************
void titlemsg(void)
{
	HELPMSG
"%s:%s:(%s) =====================================================",
"%s:%s:(%s) =====================================================",
    Spgm,Sver,__DATE__);
	return;
}//titlemsg
