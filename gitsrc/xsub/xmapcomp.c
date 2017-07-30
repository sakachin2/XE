// *******************************************************************
// * xemapchk.c                                                    //~6526R~
// * ‹@”\ŠT—v   : module compare by function size on map file      //~6526R~
// *******************************************************************
//*************************************************************    //~6526I~
#include <time.h>                                                  //~6526I~
#include <stdio.h>                                                 //~6526I~
#include <stdlib.h>                                                //~6526I~
#include <ctype.h>                                                 //~6526I~
#include <string.h>                                                //~6526I~
//*************************************************************    //~6526I~
#ifdef DOS                                                         //~6526I~
#else                                                              //~6526I~
	#define INCL_BASE                                              //~6526I~
	#include <os2.h>                                               //~6526I~
#endif                                                             //~6526I~
//*******************************************************          //~6526I~
#include <ulib.h>                                                  //~6526I~
#include <ufuncmap.h>                                              //~6526I~
//*******************************************************          //~6526I~
#define VER "V1.0"   //version                                     //~6526I~
#define PGM "XMAPCOMP"                                             //~6526R~
//*******************************************************          //~6526I~
#define USEDID    0x01                                             //~6526I~
static 	UCHAR *Smapf1,*Smapf2;                                     //~6526I~
static 	int Ssamectr;                                              //~6526I~
static 	int Sunmatchonly;                                          //~6526R~
                                                                   //~6526I~
//**************************************************************** //~6526I~
int main(int parmc,char *parmp[])                                  //~6526I~
{                                                                  //~6526I~
	PEPATBL  ptb1t,ptb2t,ptb1,ptb2;                                //~6526I~
    void printout(int Psw,PEPATBL Pptb1,PEPATBL Pptb2);                //~6526I~//+7727R~
    int ctr1=0,ctr2=0;                                             //~6526R~
//******************                                               //~6526I~
	if (parmc<3)                                                   //~6526I~
	{                                                              //~6526I~
    	printf("%s:%s:size compare by map file\n",PGM,VER);        //~6526R~
    	printf("      %s mapf1 mapf2 [/u]\n",PGM);                 //~6526I~
    	printf("        /u :display unmatch only\n");          //~6526I~//+7727R~
		exit(4);                                                   //~6526I~
	}                                                              //~6526I~
	if (parmc>=4)                                                  //~6526I~
	{                                                              //~6526I~
        if (!stricmp(parmp[3],"/u"))                               //~6526I~
        	Sunmatchonly=1;                                        //~6526I~
	}                                                              //~6526I~
    Smapf1=parmp[1];                                               //~6526R~
    Smapf2=parmp[2];                                               //~6526R~
	ufuncmap(Smapf1,0,&ptb1t);                                     //~6526R~
	ufuncmap(Smapf2,0,&ptb2t);                                     //~6526R~
                                                                   //~6526I~
	for (ptb2=ptb2t;*ptb2->funcname;ptb2++)                        //~6526I~
     	ctr2++;                                                    //~6526I~
//*                                                                //~6526I~
	for (ptb1=ptb1t;*ptb1->funcname;ptb1++)                        //~6526R~
	{                                                              //~6526I~
    	ctr1++;                                                    //~6526I~
		for (ptb2=ptb2t;*ptb2->funcname;ptb2++)                    //~6526R~
		{                                                          //~6526I~
        	if (!stricmp(ptb1->funcname,ptb2->funcname))           //~6526I~
            {                                                      //~6526I~
                printout(0,ptb1,ptb2);                                 //~6526I~//+7727R~
	        	*ptb2->funcname=USEDID;                            //~6526I~
                break;                                             //~6526I~
            }                                                      //~6526I~
		}                                                          //~6526I~
		if (!*ptb2->funcname)	//not found                        //~6526I~
        	printout(1,ptb1,0);                                        //~6526R~//+7727R~
	}                                                              //~6526I~
	for(ptb2=ptb2t;*ptb2->funcname;ptb2++)                         //~6526I~
	{                                                              //~6526I~
		if (*ptb2->funcname!=USEDID)                               //~6526I~
        	printout(2,0,ptb2);                                        //~6526R~//+7727R~
	}                                                              //~6526I~
	printf("\n%s has %d,%s has %d, %d are same size\n",            //~6526R~
			Smapf1,ctr1,Smapf2,ctr2,Ssamectr);                     //~6526I~
	return 0;                                                      //~6526I~
}//main                                                            //~6526I~
//***********************************************************      //~6526I~
//***********************************************************      //~6526I~
//***********************************************************      //~6526I~
void printout(int Psw,PEPATBL Pptb1,PEPATBL Pptb2)                     //~6526I~//+7727R~
{                                                                  //~6526I~
//************                                                     //~6526I~
	if (!Psw)                                                      //~6526I~
		if (Pptb1->len==Pptb2->len)                                //~6526I~
        {                                                          //~6526I~
        	Ssamectr++;                                            //~6526I~
            if (!Sunmatchonly)	                                   //~6526I~
		    	printf("\n%-32.32s (%10ld) ==",Pptb1->funcname,Pptb1->len);//~6526R~
		}                                                          //~6526I~
        else                                                       //~6526I~
	    	printf("\n%-32.32s (%10ld  != %10ld)",Pptb1->funcname,Pptb1->len,Pptb2->len);//~6526R~
    else                                                           //~6526I~
    	if (Psw==1)                                                //~6526I~
	    	printf("\n%-32.32s (%10ld) is %s only",Pptb1->funcname,Pptb1->len,Smapf1);//~6526R~
		else                                                       //~6526R~
	    	printf("\n%-32.32s (%10ld) is %s only",Pptb2->funcname,Pptb2->len,Smapf2);//~6526R~
	return;                                                        //~6526I~
}//outp                                                            //~6526I~
