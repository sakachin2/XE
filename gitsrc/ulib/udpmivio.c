//CID://+v086R~:                                                   //~v086R~
//*************************************************************
//*udpmivio.c vio functions for DPMI                               //~v053R~
//*************************************************************    //~v053I~
//v086:970601 (BUG:GCC english only)usage of gettext,puttext       //~v086I~
//            last row not wrriten                                 //~v086I~
//            endcol set err                                       //~v086I~
//v053:970107:gcc version(control by DPMI)                         //~v053R~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//*******************************************************
#include <dos.h>                                                   //~v053R~
#include <dpmi.h>                                                  //~v053R~
#include <conio.h>                                                 //~v053I~
#include <sys/movedata.h>                                          //~v053I~
//*******************************************************
#include <ulib.h>                                                  //~v022R~
#include <uerr.h>                                                  //~v053I~
#include <uedit.h>                                                 //~v053I~
#include <udpmivio.h>                                              //~v053R~
#include <udpmisub.h>                                              //~v053I~
//*******************************************************
static int Swidth;   				//screen width                 //~v053I~
static int Sheight;  				//screen height                //~v053I~
//*******************************************************          //~v053I~
//*udpmivio_init                                                   //~v053R~
//*get parm from uvio                                              //~v053R~
//*parm1:screen width                                              //~v053R~
//*parm2:screen height                                             //~v053I~
//*ret  :none                                                      //~v053I~
//*******************************************************          //~v053I~
void udpmivio_init(int Pwidth,int Pheight)                         //~v053R~
{                                                                  //~v053I~
//*******************                                              //~v053I~
	Swidth=Pwidth;                                                 //~v053I~
	Sheight=Pheight;                                               //~v053I~
	return;                                                        //~v053I~
}//udpmivio_init                                                   //~v053R~
                                                                   //~v053I~
//********************************************************************//~v053I~
//*udpmiviogettext                                                 //~v053R~
// interface to gcc gettext(read char+attr from video buff)        //~v053I~
// parm1:output buff                                               //~v053I~
// parm2:request len                                               //~v053I~
// parm3:row                                                       //~v053I~
// parm4:col                                                       //~v053I~
//********************************************************************//~v053I~
int udpmiviogettext(PCH pchCellStr,int Pcelllen,int Prow,int Pcol) //~v053R~
{                                                                  //~v053I~
	int len,row,col,endcol,step;                                   //~v053R~
    int len2;                                                      //~v086I~
    PCH pc;                                                        //~v053R~
//*************                                                    //~v053I~
	if (Prow>=Sheight || Pcol>=Swidth)                             //~v053R~
    	return 4;                                                  //~v053I~
    step=0;                                                        //~v053I~
    for (row=Prow+1,col=Pcol+1,len=Pcelllen,pc=pchCellStr;         //~v053I~
//  	 len>0 && row<Sheight;                                     //~v086R~
    	 len>0 && row<=Sheight;                                    //~v086I~
		 row++,len-=step,pc+=step)                                 //~v053I~
    {                                                              //~v053I~
//  	endcol=min(len,Swidth);                                    //~v086R~
    	len2=(len>>1);                                             //+v086R~
    	endcol=min(len2,Swidth)+col-1;                             //~v086I~
//  	gettext(row,col,row,endcol,pc);                            //~v086R~
    	gettext(col,row,endcol,row,pc);	//left,top,right,bottom,source//~v086R~
		step=((endcol-col+1)<<1);			//moved len            //~v053R~
        col=1;                                                     //~v053I~
	}                                                              //~v053I~
    return 0;                                                      //~v053I~
}//udpmiviogettext                                                 //~v053R~
                                                                   //~v053I~
//********************************************************************//~v053I~
//*udpmivioputtext                                                 //~v053I~
//*interface to gcc putettext(write char+attr to video buff)       //~v053I~
// parm1:output buff                                               //~v053I~
// parm2:request len                                               //~v053I~
// parm3:row                                                       //~v053I~
// parm4:col                                                       //~v053I~
//********************************************************************//~v053I~
int udpmivioputtext(PCH pchCellStr,int Pcelllen,int Prow,int Pcol) //~v053R~
{                                                                  //~v053I~
	int len,row,col,endcol,step;                                   //~v053R~
    int len2;                                                      //~v086I~
    PCH pc;                                                        //~v053R~
//*************                                                    //~v053I~
	if (Prow>=Sheight || Pcol>=Swidth)                             //~v053R~
    	return 4;                                                  //~v053I~
    step=0;                                                        //~v053I~
    for (row=Prow+1,col=Pcol+1,len=Pcelllen,pc=pchCellStr;         //~v053I~
//  	 len>0 && row<Sheight;                                     //~v086R~
		 len>0 && row<=Sheight;                                    //~v086I~
		 row++,len-=step,pc+=step)                                 //~v053I~
    {                                                              //~v053I~
//  	endcol=min(len,Swidth);                                    //~v086R~
    	len2=(len>>1);                                             //+v086R~
    	endcol=min(len2,Swidth)+col-1;                             //~v086I~
//  	puttext(row,col,row,endcol,pc);                            //~v086R~
    	puttext(col,row,endcol,row,pc);    	//left,top,right,bottom,source//~v086I~
		step=((endcol-col+1)<<1);			//moved len            //~v053I~
        col=1;                                                     //~v053I~
	}                                                              //~v053I~
    return 0;                                                      //~v053I~
}//udpmivioputtext                                                 //~v053R~
                                                                   //~v053I~
