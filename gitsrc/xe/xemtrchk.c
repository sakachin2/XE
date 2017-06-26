//CID://+vak7R~:                                                   //~vak7R~
// ******************************************************************
//  malloc/free pair chk                                           //~v53sR~
//    parm1 : input file spec(maaloc trace file)                   //~v53sR~
// **********************************************/
//vak7:130906 redirect memcpy to memmove when overlaped            //~v53sI~
//v1.3 v53s:031004 malloc trace opt to print 2 level return addr   //~v53sI~
//v19N:000925 V1.2 LINUX support(xemtrchk.c:compiler warning;main parm UCHAR* -->char *)//~v1.2I~
// 960709 v1.1 alloc/free size chk                                 //~v1.1I~
// **********************************************/                 //~v1.1I~
#define VER    "V1.4"        //version                             //~vak7R~
// *******************************************************************
//#define UCHAR unsigned char                                      //~vak7R~
//#define PVOID void *                                             //~vak7R~
// *******************************************************************//~v1.1I~

#include <time.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>                                                 //~v1.1I~
                                                                //~5C24I~
#include <ulib.h>      // redefne memcpy                           //~vak7R~
#include <uque.h>                                               //~5C24I~

//********************************************************************

#define PGMID  "XEMTRCHK"      //program id                        //~v1.1R~
//*******************************************************************
typedef  struct _ADDRLIST {                                     //~5C24R~
                             UQUEE  ALqe;//storage addr         //~5C24R~
                             UCHAR  ALaddr[8];  //hex addr      //~5C24R~
                             UCHAR  ALrsv1;                     //~5C24R~
                             UCHAR  ALlen[8];  //hex addr       //~5C24I~
                             UCHAR  ALrsv2;                     //~5C24I~
                             UCHAR  ALret[8];  //hex addr          //~v53sI~
                             UCHAR  ALrsv3;                        //~v53sI~
                             UCHAR  ALret2[8];  //hex addr         //~v53sI~
                             UCHAR  ALrsv4;                        //~v53sI~
                          } ADDRLIST;                           //~5C24R~
typedef ADDRLIST* PADDRLIST;                                    //~5C24R~
#define ADDRLISTSZ sizeof(ADDRLIST)                             //~5C24I~

//***********
int addrcomp(PUQUEE Ppfnqe,PVOID Ppfname);                      //~5C24I~
void putmsg(int,UCHAR*,...);         /*err msg display*/        //~5C24I~
//***********

//*******************************************************************

//t main(int parmc,UCHAR *parmp[])                                 //~v1.2R~
int main(int parmc,char  *parmp[])                                 //~v1.2I~
{
	UCHAR  buff[512],*pc,*inputfname;                           //~5C24R~
    FILE *fh;                                                   //~5C24I~
    PADDRLIST pal;                                              //~5C24I~
  	int allocctr=0,freectr=0,notallocctr=0,pendctr=0,lenerrctr=0;  //~v1.1R~
static	UQUEH Sqh;                                              //~5C24I~
	int linectr=0;                                                 //~vak7I~
//*******************************************************************

//**************************
//* initialize             *
//**************************
  if (parmc<2||*parmp[1]=='?')
    putmsg(4,"%s trace-file-name\n",PGMID);                     //~5C24R~
  inputfname=parmp[1];                                          //~5C24R~
  if (!(fh=fopen(inputfname,"r")))                              //~5C24R~
    putmsg(4,"input file:%s open err,rc=%d\n",inputfname,errno);//~5C24R~

//*****************************
//* edit all header record    *
//*****************************
  	while (fgets(buff,sizeof(buff),fh))                         //~5C24R~
  	{                                                           //~5C24R~
    	linectr++;                                                 //~vak7I~
//      printf("line=%d,buff=%s\n",linectr,buff);//@@@@test        //+vak7R~
		if (!(pc=strchr(buff,'=')))                             //~5C24R~
		    putmsg(4,"data err 1,%s\n",buff);                      //~v1.1R~
	    if (memcmp(buff,"free",4))	//not free                  //~5C24R~
        {                                                       //~5C24I~
        	if (!(pal=calloc(1,ADDRLISTSZ)))                    //~5C24I~
			    putmsg(4,"malloc failed\n");                    //~5C24I~
			memcpy(pal->ALaddr,pc+1,8);                         //~5C24I~
			pal->ALrsv1=0;                                      //~5C24R~
			if (!(pc=strchr(pc+1,'=')))                         //~5C24I~
			    putmsg(4,"data err 2,%s\n",buff);                  //~v1.1R~
			memcpy(pal->ALlen,pc+1,8);                          //~5C24I~
			pal->ALrsv2=0;                                      //~5C24I~
			pal->ALrsv3=0;                                         //~v53sI~
			pal->ALrsv4=0;                                         //~v53sI~
            memset(pal->ALret,' ',8);                              //~v53sI~
            memset(pal->ALret2,' ',8);                             //~v53sI~
			if (pc=strchr(pc+1,'='),pc)                            //~v53sR~
				if (pc=strchr(pc+1,'='),pc)                        //~v53sR~
                {                                                  //~v53sI~
					memcpy(pal->ALret,pc+1,8);                     //~v53sI~
					if (pc=strchr(pc+1,'='),pc)                    //~v53sR~
						memcpy(pal->ALret2,pc+1,8);                //~v53sI~
            	}                                                  //~v53sI~
            UENQ(UQUE_END,&Sqh,pal);                            //~5C24R~
            allocctr++;                                         //~5C24I~
        }                                                       //~5C24I~
        else	//free req                                      //~5C24I~
        {                                                       //~5C24I~
            freectr++;                                          //~5C24M~
			if (!(pal=uqscan(UQUE_TOP,&Sqh,addrcomp,pc+1)))//not found//~5C24I~
            {                                                   //~5C24I~
            	printf("free only : %s",buff);                     //~v1.1R~
	            notallocctr++;                                  //~5C24I~
                continue;                                       //~5C24I~
            }                                                   //~5C24I~
			if (!(pc=strchr(pc+1,'=')))                            //~v1.1I~
			    putmsg(4,"data err 3,%s\n",buff);                  //~v1.1I~
			if (memcmp(pal->ALlen,pc+1,8))	//length unmatch       //~v1.1I~
            {                                                      //~v1.1I~
            	*(pc+1+8)=0;                                       //~v1.1I~
//          	printf("length unmatch: %s,alloc=%s,free=%s\n",    //~v53sR~
//  					pal->ALaddr,pal->ALlen,pc+1);              //~v53sR~
            	printf("length unmatch: %s,alloc=%s,free=%s,ret=(%s,%s)\n",//~v53sR~
    					pal->ALaddr,pal->ALlen,pc+1,pal->ALret,pal->ALret2);//~v53sI~
	            lenerrctr++;                                       //~v1.1I~
            }                                                      //~v1.1I~
            UDEQ(UQUE_ENT,&Sqh,pal);                            //~5C24R~
        }                                                       //~5C24I~
  	}                                                           //~5C24R~
//                                                              //~5C24I~
    printf ("************************\n");                      //~5C24I~
	while(pal=UDEQ(UQUE_TOP,&Sqh,0),pal)                        //~5C24R~
    {                                                           //~5C24I~
//     	printf("not freed : %s (len=%s)\n",pal->ALaddr,pal->ALlen);//~v53sR~
       	printf("not freed : %s (len=%s), ret=(%s,%s) \n",pal->ALaddr,pal->ALlen,pal->ALret,pal->ALret2);//~v53sR~
	    pendctr++;                                              //~5C24I~
    }                                                           //~5C24I~
    printf("not freed=%d,not alloced=%d,length unequal=%d(get=%d,free=%d)\n",//~v1.1R~
    		pendctr,notallocctr,lenerrctr,allocctr,freectr);       //~v1.1R~
  	return 0;                                                   //~5C24R~
}   //end main
//********                                                      //~5C24I~
int addrcomp(PUQUEE Ppfnqe,PVOID Ppfname)                       //~5C24R~
{                                                               //~5C24I~
//retrn 0 if match ,1 if unmatch                                //~5C24I~
	return memcmp(Ppfname,((PADDRLIST)(PVOID)Ppfnqe)->ALaddr,8)!=0;//~5C24I~
}//addrcomp                                                     //~5C24R~
//********************************************************************//~5C24I~
//* error msg output and exit                                   //~5C24I~
//*   input:                                                    //~5C24I~
//*     p1    :exit code,exit program if not 0                  //~5C24I~
//*     p2    :printf patern                                    //~5C24I~
//*     p3-p12:edit parameter(max 10 edit parm)                 //~5C24I~
//*   output:                                                   //~5C24I~
//*     standard error output                                   //~5C24I~
//********************************************************************//~5C24I~
                                                                //~5C24I~
void putmsg(int exitcode,UCHAR *patern,...)                     //~5C24I~
{                                                               //~5C24I~
  UCHAR errmsg[512];      //for lineput                         //~5C24I~
//**************                                                //~5C24I~
  sprintf(errmsg,"\n%s-%s:",PGMID,VER);                         //~5C24I~
  sprintf(errmsg+strlen(errmsg),patern,                         //~5C24I~
          *(&patern+1), //edit parm 1                           //~5C24I~
          *(&patern+2), //edit parm 2                           //~5C24I~
          *(&patern+3), //edit parm 3                           //~5C24I~
          *(&patern+4), //edit parm 4                           //~5C24I~
          *(&patern+5), //edit parm 5                           //~5C24I~
          *(&patern+6), //edit parm 6                           //~5C24I~
          *(&patern+7), //edit parm 7                           //~5C24I~
          *(&patern+8), //edit parm 8                           //~5C24I~
          *(&patern+9), //edit parm 9                           //~5C24I~
          *(&patern+10));//edit parm 10                         //~5C24I~
  fprintf(stderr,"%s",errmsg);                                  //~5C24I~
  if (exitcode)                                                 //~5C24I~
    exit(exitcode);//terminate                                  //~5C24I~
}//endof putmsg                                                 //~5C24I~
