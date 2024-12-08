//CID://+v6b1R~:                                                   //+v6b1R~
//*******************************************************          //~v5m9I~
//*uregex.h                                                        //~v5m9I~
//*******************************************************          //~v5m9I~
//v6b1:110705 try list wildcard membername                         //+v6b1I~
//v5mL:080719 (LNX)regex.h on arch linux cause compile err, so include gnu regex.h like as win version//~v5mLI~
//            They say use _GNU_SOURCE,but it is not effective because features.h is previously included//~v5mLI~
//            So GNU_SOURCE dose not define __USE_GNU              //~v5mLI~
//v5mh:080308 (W32)regex support using GNU regex v2.7.             //~v5m9I~
//*******************************************************          //~v5m9I~
//#define _GNU_SOURCE     //__USE_GNU for regex                    //~v5mLI~
#define __USE_GNU         //__USE_GNU for regex                    //~v5mLI~
#define REGEX_STATIC    //static link                              //~v5m9R~
#ifdef ARM                                                         //+v6b1I~
	#include <gnuregex/regex.h>  //compile err wehen arm regex.h is used//+v6b1I~
#else                                                              //+v6b1I~
#include <regex.h>                                                 //~v5m9I~
#endif                                                             //+v6b1I~
