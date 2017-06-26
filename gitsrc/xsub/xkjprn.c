//CID://+v00hR~:                                                   //~v00hI~
//*************************************************************    //~v00hI~
//*kjprn.c                                                         //~v00hI~
//*      print all kanki code                                      //~v00hI~
//*************************************************************    //~v00hI~
//*************************************************************    //~v00hI~
#include <time.h>                                                  //~v00hI~
#include <stdio.h>                                                 //~v00hI~
#include <stdlib.h>                                                //~v00hI~
#include <ctype.h>                                                 //~v00hI~
#include <string.h>                                                //~v00hI~
#include <errno.h>                                                 //~v00hI~
//********************                                             //~v00hI~
#include <ulib.h>                                                  //~v00hI~
//********************                                             //~v00hI~
//*************************************************************    //~v00hI~
int main(int parmc,char * parmp[])                                 //~v00hI~
{                                                                  //~v00hI~
    int ii,jj,kk,ll,jj1,jj2;                                       //~v00hI~
	UCHAR dbcs1[4][2]={'\x81','\x8f','\x90','\x9f','\xe0','\xef','\xf0','\xfc'};//~v00hR~
//**********************                                           //~v00hI~
    for (ii=0;ii<4;ii++)                                           //~v00hI~
    {                                                              //~v00hI~
		jj1=dbcs1[ii][0];                                          //~v00hI~
		jj2=dbcs1[ii][1];                                          //~v00hI~
		for (jj=jj1;jj<jj2;jj++)                                   //~v00hI~
        {	                                                       //~v00hI~
        	printf("0x%02Xxx\n",jj);                               //~v00hI~
        	for (kk=0;kk<16;kk++)                                  //~v00hI~
            {                                                      //~v00hI~
                printf("  --%x0--",kk);                            //+v00hI~
            	for (ll=0;ll<16;ll++)                              //~v00hI~
                	printf(" %c%c ",jj,(kk<<4)+ll);                //~v00hR~
                printf("\n");                                      //~v00hI~
			}                                                      //~v00hI~
        }                                                          //~v00hI~
	}                                                              //~v00hI~
	return 0;                                                      //~v00hI~
}//main                                                            //~v00hI~
