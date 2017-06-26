//****************************************************************//~5429I~
//*xeini.h                                                      //~5429I~
//****************************************************************//~5429I~
//**************************************************            //~5429I~
//*inigetparm                                                   //~5429I~
//* get parm from .ini file                                     //~5429I~
//*parm :ini file name parameter                                //~5501R~
//*      nul:no parm(use dafault), "":no use ini file           //~5501I~
//*ret  :rc                                                     //~5501R~
//**************************************************            //~5429I~
int inigetparm(UCHAR *Pinifile);                                //~5501R~
                                                                //~5503I~
//**************************************************            //~5503I~
//*inigetfname                                                  //~5503I~
//* get ini file name                                           //~5503I~
//*parm:output area if you want copy                            //~5503I~
//*ret :same as input(if input is 0,return internal static area addr)//~5503I~
//**************************************************            //~5503I~
UCHAR *inigetfname(UCHAR *Pfname);                              //+5503R~
