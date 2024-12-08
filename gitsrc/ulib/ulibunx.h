//*CID://+v6h0R~:      update#=     2                              //~v6h0R~
//*********************************************************************//~v321I~
//ulibunx.h                                                        //~v321I~
//  for UNIX/LINUX                                                 //~v321I~
//*********************************************************************//~v321I~
//v6h0:120604 (LNX:BUG)dlcmd "d" caused 0c4 by long pathname.      //~v6h0I~
//            512 is too short,MAXPATHLEN:1024,PATH_MAX:4096; use 4096.//~v6h0I~
//v5nD:090329 S390 support                                         //~v5nDI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5g6:050613 (XXE)xxe support                                     //~v5g6I~
//v424:010101 TLinux:sys/vfs.h dose not include linux/vfs.h now.   //~v424I~
//v405:001109 AIX support:macro _MINMAX required for min/max macro define//~v400I~
//v400:001027 AIX support:_MAX_PATH is duplicated to extention.h   //~v400I~
//v321 000729:UNIX support                                         //~v321I~
//#define _MAX_PATH 512                                            //~v400R~
#ifdef LNX                                                         //~v321I~
//  #define _MAX_PATH 512                                          //~v400I~//~v6h0R~
    #define _MAX_PATH_FOR_INIFILE 512  //to avoid inifile version unmatch//+v6h0I~
    #define _MAX_PATH 4096                                         //~v6h0I~
	#define min(a,b) (((a)<(b))?(a):(b))                           //~v321I~
	#define max(a,b) (((a)>(b))?(a):(b))                           //~v321I~
	#define ICONV_PCTYPE(pc) ((char **__restrict)(pc))             //~v5ncI~
	#define ICONV_SZTYPE(sz) ((size_t *__restrict)(sz))            //~v5nDI~
	#include <linux/types.h>                                       //~v321R~
  #ifdef XXE                                                       //~v5g6I~
    typedef   int BOOL;                                            //~v5g6R~
  #endif                                                           //~v5g6I~
#else                                                              //~v321I~
    #define _MINMAX                                                //~v405R~
	#include <extension.h>                                         //~0222I~
#endif                                                             //~v321I~
    #include <sys/vfs.h>                                           //~v321R~
    #include <ugcclib.h>                                           //~v321I~
