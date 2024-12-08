//CID://+v927R~:                                                   //+v927R~
//***********************************************************
//* xpw95ws.c
//***********************************************************
//070511 v927 (BUG)compile err by LONG long file size support      //+v927I~
//971123 v829 :(BUG:W95)wait kbd input                             //~v829I~
//970928 v826 :w95 version
//*************************************************************
#include <time.h>                                                  //~v826R~
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>                                                 //~v826R~
#include <string.h>                                                //~v826R~
#include <conio.h>                                                 //~v826I~
//*************************************************************

#include <windows.h>
//*********************************************************************
#include  <ulib.h>                                                 //+v927I~
#include  <ufile.h>                                                //~v826I~
#include  <ukbd.h>                                                 //~v826I~
#include  <uedit.h>                                                //~v826I~
#include  <uerr.h>                                                 //~v826I~
//*********************************************************************//~v826I~
#include  "xp.h"
#include  "xpw95s.h"
//*********************************************************************
//int xpw95kbdpeek(void);                                          //~v829R~
//HANDLE xpw95getstdhandle(int Pid);                               //~v829R~
//**************************************************               //~v826I~
//*chk dbcs env                                                    //~v826I~
//*parm :none                                                      //~v826I~
//*rc   :1:dbcs env,0:no dbcs env                                  //~v826I~
//**************************************************               //~v826I~
int xpw95dbcsenv(void)                                             //~v826I~
{                                                                  //~v826I~
    CPINFO cpi;                                                    //~v826I~
    BOOL   success;                                                //~v826I~
//*********************                                            //~v826I~
    success=GetCPInfo(CP_ACP,&cpi);                                //~v826I~
    if (!success)                   //false                        //~v826I~
        uerrexit("GetCPInfo failed",0);                            //~v826I~
    return cpi.LeadByte[0]!=0;                                     //~v826I~
}//xpw95dbcsenv                                                    //~v826I~
//**************************************************
//*get keyboard input
//*parm :wait option: 0(IO_WAIT) 1(IO_NOWAIT)
//*rc   :read char
//**************************************************
int xpw95kbinp(int Pwait)
{
//*********************
    if (Pwait==IO_NOWAIT)                                          //~v829R~
    {                                                              //~v829I~
//      return xpw95kbdpeek();                                     //~v829R~
        return kbhit();                                            //~v829I~
    }                                                              //~v829I~
    return getch();                                                //~v829R~
}//xpw95kbinp
////*******************************************************        //~v829R~
////retuen 0:no data or char in console buff                       //~v829R~
////*******************************************************        //~v829R~
//int xpw95kbdpeek(void)                                           //~v829R~
//{                                                                //~v829R~
//static HANDLE Shstdin;                                           //~v829R~
//    DWORD readctr;                                               //~v829R~
//    INPUT_RECORD inprec;                                         //~v829R~
//    int rc;                                                      //~v829R~
////*********************                                          //~v829R~
//    if (!Shstdin)                                                //~v829R~
//        Shstdin=xpw95getstdhandle(STD_INPUT_HANDLE);             //~v829R~
//    rc=PeekConsoleInput(Shstdin,                                 //~v829R~
//                        &inprec,                                 //~v829R~
//                        1,          //request count              //~v829R~
//                        &readctr);                               //~v829R~
//    if (!rc)                //BOOL                               //~v829R~
//        uerrapi1x("PeekConsoleInput","STD_INPUT",GetLastError());//~v829R~
//    if (!readctr)                                                //~v829R~
//        return 0;                                                //~v829R~
//    return inprec.Event.KeyEvent.uChar.AsciiChar;                //~v829R~
//}//xpw95kbdpeek                                                  //~v829R~
////*******************************************************        //~v829R~
//HANDLE xpw95getstdhandle(int Pid)                                //~v829R~
//{                                                                //~v829R~
//    HANDLE h;                                                    //~v829R~
////**********************                                         //~v829R~
//    h=GetStdHandle(Pid);                                         //~v829R~
//    if (h==INVALID_HANDLE_VALUE)                                 //~v829R~
//        uerrapi1x("GetStdHandle",uitoa10(Pid),GetLastError());   //~v829R~
//    return h;                                                    //~v829R~
//}//xpw95getstdhandle                                             //~v829R~
