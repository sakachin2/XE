//CID://+DATER~:                                                   //~0901R~
//*************************************************************
//*udosl.c  LINUX version of                                       //~0901R~
//          udos_version,uharderr,udosiswin,udosiswinnt,udosisos2  //~0901R~
//*************************************************************
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
//*******************************************************
//*******************************************************
#include <ulib.h>
#include <udos.h>                                                  //~v052R~
#include <uerr.h>                                                  //~v052I~
#include <uedit.h>                                                 //~v074I~
#include <ustring.h>                                               //~v159I~
#ifdef DOS                                                         //~v052I~
	static int Sharderropt;                                        //~v052I~
#endif                                                             //~v052I~
//*******************************************************
//*get os version                                                  //~v039R~
//*parm 1:major version output area                                //~v039R~
//*parm 2:minor version output area                                //~v039I~
//*parm 3:other information output area                            //~v039R~
//*       DOS:1 byte ROM option, 0:not on ROM,8:on ROM             //~v039R~
//*       OS2:int revision letter                                  //~v039I~
//*       Win:int revision letter,bit0 is off if NT                //~v133I~
//*******************************************************
int udos_version(int *Ppmaj,int *Ppmin,void *Ppinfo)
{
//**************************************
    *Ppmaj=0;                                                      //~0901R~
    *Ppmin=0;                                                      //~0901R~
	*(char*)Ppinfo=0;                                              //+0901R~
    return 0;                                                      //~v039I~
}//udos_version
//*******************************************************          //~v162I~
//*udosiswin                                                       //~v162I~
//*return true if os is win(include winnt)                         //~v162R~
//*parm :none                                                      //~v162I~
//*return: 1:win 0:not windows                                     //~v162I~
//*******************************************************          //~v162I~
int udosiswin(void)                                                //~v162I~
{                                                                  //~v162I~
    return 0;                                                      //~0901R~
}//udosiswin                                                       //~v162I~
//*******************************************************          //~v136I~
//*udosiswinnt                                                     //~v136I~
//*return true if os is winnt                                      //~v136I~
//*parm :none                                                      //~v136I~
//*return: 1:winnt 0:win95                                         //~v136I~
//*******************************************************          //~v136I~
int udosiswinnt(void)                                              //~v136I~
{                                                                  //~v136I~
//***********************                                          //~v136I~
    return 0;                                                      //~v162I~
}//udosiswinnt                                                     //~v136I~
//*******************************************************          //~v159I~
//*udosisos2                                                       //~v159I~
//*return true if os is os2 DOS session                            //~v159I~
//*parm :none                                                      //~v159I~
//*return: 1:OS/2  0:not OS/2                                      //~v159I~
//*******************************************************          //~v159I~
int udosisos2(void)                                                //~v159I~
{                                                                  //~v159I~
	return 0;   //win version                                      //~0901R~
}//udosisos2                                                       //~v187R~
