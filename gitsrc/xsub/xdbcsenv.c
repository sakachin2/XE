//***********************************************************
//* XCUT : seperate large file into two file
//***********************************************************
#define VER "V1.1"   //version
//***********************************************************
//*940709 def buff as unsigned char for avoid errornouse eff chk(for char ff)
//*940504 first version
//***********************************************************

#define PGM "XCUT"

//**********************************************/
//*parm1 : input file name
//*parm2 : output file1 name
//*parm3 : output file2 name
//*parm4 : output file1 size
//*r.c   : none
//**********************************************/
//*
#ifdef DOS                           

#else                               

#define INCL_BASE                     
#include <os2.h>         

#endif                               
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <ulib.h>
#include <udbcschk.h>
//*********************************************************************

//*********************************************************************
//* return 0:sbcs mode
//*        1:dbcs mode
//*********************************************************************
int main(void)
{
//**********************
	return udbcschk(0x81);
}//main
