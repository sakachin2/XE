//*CID://+v6a0R~:                             update#=    5;       //~v6a0R~
//*********************************************************************//~v351I~
//ucurses.h  for AIX                                               //~v401R~
//*********************************************************************//~v351I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v401:001027 AIX support:ncurses.h should be curses.h             //~v401I~
#ifdef LNX                                                         //~v401I~
  #ifdef MGW32                                                     //~v5ncI~
	#include <curses.h>                                            //~v5ncI~
  #else                                                            //~v5ncI~
#if !(defined(ARM) && defined(XXE))                                //~v6a0I~
#ifndef NOCURSES                                                   //+v6a0I~
	#include <ncurses.h>                                           //~v401I~
#endif //NOCURSES                                                  //+v6a0I~
#endif //ARMXXE                                                    //~v6a0I~
  #endif                                                           //~v5ncI~
#else                                                              //~v401R~
	#include <curses.h>                                            //~v401R~
#endif                                                             //~v401I~
