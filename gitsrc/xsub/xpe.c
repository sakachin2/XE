//*CID://+vak0R~:                             update#=   58;       //~vak0R~
//***********************************************************
//* xpe    : print numonic errno
//***********************************************************
//vak0:180817 xver1.3: force english if chcp!=932                  //~vak0I~
//va37:070522 xpe:sys_nerr duplicated                              //~va37I~
//va2n:060907 xpe:1.1 (WIN)support errorcode by GetLastError()     //~va2nI~
//*v1.0 020330 first version
//***********************************************************

#define VER "V1.3"   //version                                     //~va37R~//~vak0R~
#define PGM "xpe"

//**********************************************/
//*parm1 : errno | all
//*r.c   : 0 :all file area same
//**********************************************/
//*
#ifdef DOS
#else
    #ifdef W32
    #else
	#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

//*********************************************************************
#include <ulib.h>
#include <uerr.h>
#include <uedit.h>
#include <udbcschk.h>                                              //~vak0I~
//*********************************************************************
#ifdef AIX                                                         //~v001I~
	#define MAX_ERRNO_AIX   EOVERFLOW  //     127                  //~v001I~
#endif                                                             //~v001I~

//*********************************************************************
static char *Spgm=PGM,*Sver=VER;
static int Sopt=0;                                                 //~va2nI~
#define OPT_WIN          0x01   //code by GetLastError             //~va2nI~
#define OPT_ALL          0x02   //code by GetLastError             //~va2nR~
#ifdef W32                                                         //~va2nI~
	#define WINMAX_DEFAULT     256                                 //~va2nI~
	static int Swinmax=WINMAX_DEFAULT;                             //~va2nI~
#endif                                                             //~va2nI~
//********************
void pesub(int Perrno);
void parmchk(int parmc,char *parmp[]);
void parmerr(char* value);
void help(void);
//*********************************************************************
int main(int parmc,char *parmp[])
{
    int parmno,ii,maxerr;                                          //~v001R~
    char *cptr;
#ifdef LNX                                                         //~va37I~
	char *pc,unknownerrno[32];                                     //~va37R~
#endif                                                             //~va37I~
//**********************
#ifdef W32                                                         //~vak0I~
  if (!udbcschkcp())		//dbcstbl or cp!=932               //~v150I~//+vak0R~
    uerrmsg_init("",stdout,UERR_FORCE_ENGLISH);//msg to stdout     //~vak0I~
  else                                                             //~vak0I~
#endif                                                             //~vak0I~
	uerrmsg_init("",stdout,0);//msg to stdout
	uerrexit_init("",stdout,0,0,0);//stdout only,no pathmsg
    parmchk(parmc,parmp);
//*******************************
//* parm process                *
//*******************************
	for (parmno=1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
#ifdef UNX
  		if(*cptr!='-')
#else
  		if(*cptr!='/'&& *cptr!='-')
#endif
  		{//positional parmno
        	if (!stricmp(cptr,"ALL"))
            {                                                      //~v001I~
		        Sopt|=OPT_ALL;                                     //~va2nI~
#ifdef W32                                                         //~va2nI~
		      if (Sopt & OPT_WIN)                                  //~va2nI~
              	maxerr=Swinmax+1;                                  //~va2nR~
              else                                                 //~va2nI~
#endif                                                             //~va2nI~
#ifdef OS2                                                         //~v001I~
            	maxerr=EOS2ERR+1;		//sys_errlist entry no (contain errno=0)//~v001R~
#else                                                              //~v001I~
    #ifdef AIX                                                     //~v001I~
				maxerr=MAX_ERRNO_AIX+1;                            //~v001I~
    #else                                                          //~v001I~
      #ifdef LNX                                                   //~va37I~
            	maxerr=9999;	//sys_errlist entry no (contain errno=0)//~va37I~
//            	printf("max=%d\n",sys_nerr);	//sys_errlist entry no (contain errno=0)//~va37R~
      #else                                                        //~va37I~
            	maxerr=sys_nerr;	//sys_errlist entry no (contain errno=0)//~v001I~
      #endif                                                       //~va37I~
    #endif                                                         //~v001I~
#endif                                                             //~v001I~
			   	for (ii=1;ii<maxerr;ii++)                          //~v001R~
                {                                                  //~va37I~
      			  	#ifdef LNX                                     //~va37I~
                        sprintf(unknownerrno,"%d",ii);             //~va37R~
    					pc=strerror(ii);	//if invalid errno is set//~va37R~
                        if (ii>100 && strstr(pc,unknownerrno))	//unknown errno contained in errmsg//~va37R~
                        	break;                                 //~va37I~
                    #endif                                         //~va37I~
            		pesub(ii);
                }                                                  //~va37I~
            }                                                      //~va2nI~
            else
            {
                if (unumlen(cptr,0,(int)strlen(cptr))!=(int)strlen(cptr))//~v001R~
                	uerrmsg("%s is invalid parm",
                    		"パラメータエラー(%s)",
                            cptr);
                else
            		pesub(atoi(cptr));
            }
  		}//option or posparm
	}//for all parm
	return 0;
}//main
//**********************************************************************
//*all
//**********************************************************************
void pesub(int Perrno)
{
//  char strerrid[8];                                              //~v001R~
#ifdef W32                                                         //~va2nI~
    char *pc;                                                      //~va2nI~
#endif                                                             //~va2nI~
//*************************
//  sprintf(strerrid,"% 3d",Perrno);                               //~v001R~
//  errno=Perrno;                                                  //~v001R~
//  printf(_strerror(strerrid));                                   //~v001R~
#ifdef W32                                                         //~va2nI~
    if (!(Sopt & OPT_WIN))                                         //~va2nR~
    	if (Perrno<sys_nerr)	//sys_errlist entry no (contain errno=0)//~va2nR~
		    printf("errno: %3d : %s\n",Perrno,strerror(Perrno));   //~va2nR~
    if (!(Sopt & OPT_WIN))                                         //~va2nI~
		if (Sopt&OPT_ALL)                                          //~va2nI~
        	return;		//all and no win option                    //~va2nI~
    pc=ugetlasterror(&Perrno);                                     //~va2nR~
    if (!pc)                                                       //~va2nR~
    {                                                              //~va2nR~
        if (Sopt & OPT_ALL)                                        //~va2nR~
            return;         //print skip when all                  //~va2nR~
        pc="Unknown";                                              //~va2nR~
    }                                                              //~va2nR~
    printf(" %5d : %s\n",Perrno,pc);                               //~va2nR~
#else                                                              //~va2nI~
    printf(" %3d : %s\n",Perrno,strerror(Perrno));                 //~v001R~
#endif                                                             //~va2nM~
    return;
}//pesub
//**********************************************************************
//*parameter chk
//**********************************************************************
void parmchk(int parmc,char *parmp[])
{
  	char *cptr,c;         //char ptr work
  	int parmno; //parm count work
    int yesno;
#ifdef W32                                                         //~va2nI~
    int winmax=0;                                                  //~va2nI~
#endif                                                             //~va2nI~
    int posparmctr=0;                                              //~vak0I~
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
  		cptr=parmp[parmno];
#ifdef UNX
  		if(*cptr=='-')
#else
  		if(*cptr=='/'||*cptr=='-')
#endif
  		{//option
    		c=*(++cptr);                      //first option byte
    		c=(UCHAR)toupper(c);
    		switch(c)             //option
    		{
    		case '?':                      //date
                help();
                exit(0);
                break;
//  		case 'D':                      //date                  //~va2nR~
#ifdef W32                                                         //~va2nI~
    		case 'W':                      //date                  //~va2nI~
                Sopt|=OPT_WIN;                                     //~va2nI~
                winmax=atoi(cptr+1);                               //~va2nI~
                if (winmax)                                        //~va2nI~
                    Swinmax=winmax;                                //~va2nI~
                break;                                             //~va2nI~
#endif                                                             //~va2nI~
    		case 'Y':                      //time
            case 'N':
                yesno=(c=='Y');
	    		c=*(++cptr);                      //first option byte
	    		c=(UCHAR)toupper(c);
                switch(c)
                {
                case '9':   //japnese
                    uerrmsg_init("",stdout,UERR_FORCE_ENGLISH*(!yesno));//msg to stdout
                    break;
                default:
                    parmerr(cptr-2);
                }
                break;
    		default:                           //not option
        		parmerr(cptr-1);
    		}//switch  by first option byte
  		}
        else                                                       //~vak0I~
            posparmctr++;                                          //~vak0I~
	}//for all parm
    if (!posparmctr)                                               //~vak0I~
  	{                                                              //~vak0I~
    	help();                                                    //~vak0I~
    	exit(0);                                                   //~vak0I~
  	}                                                              //~vak0I~
    return;
}//parmchk
//**********************************************************************
//* write option err msg
//**********************************************************************
void parmerr(char* value)
{
  	uerrexit("Invalid switch(%s)\n",
	  		 "パラメータの誤り(%s)\n",
			value);
    return;
}//parmerr

//**********************************************************************
//* write help msg
//**********************************************************************
void help(void)
{
#ifdef W32                                                         //~va2nI~
   uerrmsg("%s:%s:==(%c)== print errno / GetLastError code description =============",//~va2nI~
           "%s:%s:==(%c)== errno / GetLastError の解説\x95\\示 =========================",//~va2nI~
			Spgm,Sver,OSTYPE);                                     //~va2nI~
#else                                                              //~va2nI~
   uerrmsg("%s:%s:==(%c)== print errno description =================================",
           "%s:%s:==(%c)== errno の解説\x95\\示 ========================================",
			Spgm,Sver,OSTYPE);
#endif                                                             //~va2nI~
#ifdef W32                                                         //~va2nI~
   uerrmsg("format:  %s [-W[nnn]] {errno [ errno ...] | all }",    //~va2nR~
           "形式 :　 %s [-W[nnn]] {errno [ errno ...] | all }",    //~va2nR~
    		Spgm);                                                 //~va2nI~
   uerrmsg("   -W :  code is of GetLastError().",                  //~va2nR~
           "  -W :   Windows の GetLastError()のコードの説明");    //~va2nI~
   uerrmsg("      :  nnn:max errcode to be list if \"all\" is specified.",//~va2nI~
           "     :   nnn:\"all\"が指定された時のリストする最大エラーコード");//~va2nR~
   uerrmsg("         default is %d.",                              //~va2nI~
           "         省略値は %d。",                               //~va2nI~
                    WINMAX_DEFAULT);                               //~va2nI~
#else                                                              //~va2nI~
   uerrmsg("format:  %s {errno [ errno ...] | all }",              //~v001R~
           "形式 :　 %s {errno [ errno ...] | all }",              //~v001R~
    		Spgm);
#endif                                                             //~va2nI~
#ifdef W32                                                         //~va2nI~
   uerrmsg(" ex)  :  %s 2 13;  %s all; %s -w1024 all;",            //~va2nI~
           " 例) :   %s 2 13;  %s all; %s -w1024 all;",            //~va2nR~
			Spgm,Spgm,Spgm);                                       //~va2nI~
#else                                                              //~va2nI~
   uerrmsg(" ex)  :  %s 2 13;  %s all;",                           //~v001R~
           " 例) :   %s 2 13;  %s all;",                           //~v001R~
			Spgm,Spgm);
#endif                                                             //~va2nI~
    return;
}//help
