//*CID://+v6HsR~:                             update#=   31;       //+v6HsR~
//*********************************************************************
//ulibdef.h                                                        //~v321R~
//  include from ulib.h when the case except <os2.h> is included.  //~v053I~
//*********************************************************************
//v6Hs:170122 (Win)Support maxpath:32767                           //+v6HsI~
//v6Hr:170122 try _MAX_PATH=4096 for linux:sambasg server          //~v6HrI~
//v6Hg:170117 (Win)CreateDirectory maxpath is 248                  //~v6HgI~
//v6Hc:170114 (Win)_MAX_PATH is wchar ctr,for dbcs size is doubled.(dir=240,file=255)//~v6HcI~
//v6H9:170109 (Win)del longname using \\?\ prefix(path max is 32767) and Unicode API because move to shortpath dir could not delete dir/file name longer >=260.//~v6H9I~
//v6H1:161231 filename >_MAX_PATH occurse when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v6H1I~
//            and it cause fpath area overflow then 0c4            //~v6H1I~
//v690:100701 m64(LP64:: int:32, long,void*:64) support (__LP64_):chk pointer size at 1st.//~v690I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v590:030913 define MAX_INTVAL                                    //~v590R~
//v547:020330 (WIN)keep ctime(creatio time)/atime(last access time) for xff cmd//~v547I~
//v321 000729:UNIX support                                         //~v321I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -missing macro min,max,_MAX_PATH                     //~v053I~
//            -short int is not int but short int                  //~v053I~
//v038:961024:define HANDLE for the case <windows.h> not included  //~v038I~
//v023:960825:copy from os2.h to shorten compile time              //~v023I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//*********************************************************************//~v189I~
#ifdef W32                                                         //~v6HcI~
    #define MAX_PATH_CTR   260 //=_MAXPATH                         //~v6HcR~
    #define MAX_PATH_CTR_DIR   248 //Limit of CreateDirectory      //~v6HgI~
    #define MAX_PATH_CTR_LINUX 4096                                //~v6HcI~
    #define MAX_PATH_SZ_LINUX  MAX_PATH_CTR_LINUX //linux test utf8 code limit is 255 for each path//~v6HcR~
    #define MAX_PATH_LONGNAME_MAXCTR 32768       //by \\?\ support max 32767 chars//+v6HsI~
    #ifdef  _MAX_PATH                                              //~v6HcI~
   		#undef  _MAX_PATH                                          //~v6HcI~
    #endif                                                         //~v6HcI~
//  #define _MAX_PATH MAX_PATH_SZ       //260*4=1040               //~v6HcR~//~v6HrR~
    #define _MAX_PATH MAX_PATH_SZ_LINUX //260*4=1040<4096=_MAX_PATH_LONG//~v6HrI~
#else                                                              //~v6HgI~
    #define MAX_PATH_CTR   _MAX_PATH    //4096                     //~v6HgI~
#endif                                                             //~v6HcI~
    #define MAX_UCS2MBCS   MAX_MBCSLENLC    //4  for GB18030       //~v6HgM~
    #define MAX_UCS2UTF8   UTF8_MAXCHARSZ   //4  up to u-10ffff    //~v6HgM~
    #define MAX_PATH_MBCS  (MAX_PATH_CTR*MAX_UCS2MBCS) //260*4=1040:for dbcs(ucsctr=1,gb18030 is 4 byte dbcs)//~v6HgM~
    #define MAX_PATH_UTF8  (MAX_PATH_CTR*MAX_UCS2UTF8) //260*4=1040:for dbcs(ucsctr=1,gb18030 is 4 byte dbcs)//~v6HgM~
//  #define MAX_PATH_SZ    MAX_PATH_MBCS                           //~v6HgM~//~v6HrR~
#ifdef DOS                                                         //~v022R~
  #ifdef DPMI					//DPMI version                     //~v053I~
	#define SHORT    short           /* s   */                     //~v053I~
	typedef unsigned short USHORT;   /* us  */                     //~v053I~
	typedef USHORT  *PUSHORT;                                      //~v053I~
    #define MAX_INT_VAL  0x7fffffff                                //~v590R~
  #else                       //not DPMI                           //~v053I~
	#define SHORT    int             /* s   */                     //~v022R~
	typedef unsigned int   USHORT;   /* us  */                     //~v022R~
	typedef USHORT  *PUSHORT;                                      //~v022R~
    #define MAX_INT_VAL  0x7fff                                    //~v590R~
  #endif                      //DPMI or not                        //~v053I~
  #define VOID     void                                            //~v053I~
#else		//w95 or os2 without os2.h                             //~v022R~
    #define MAX_INT_VAL  0x7fffffff                                //~v590R~
    #ifndef _INC_WINDOWS   //os2 without os2.h,w95 without windows.h//~v022R~
    #ifndef _WINDOWS_H     //mingw windows.h                       //~v5ncI~
        #define VOID     void                                      //~v053I~
		#define SHORT    short           /* s   */                 //~v022R~
		typedef SHORT   *PSHORT;                                   //~v022R~
		typedef unsigned short  USHORT;  /* us  */                 //~v022R~
		typedef USHORT  *PUSHORT;                                  //~v022R~
		typedef void    *HANDLE;                                   //~v038I~
//* to avoid include windows.h                                     //~v547I~
		typedef struct _FILETIME{                                  //~v547I~
                					unsigned int dwLowDateTime;    //~v547R~
                					unsigned int dwHighDateTime;   //~v547R~
                				} FILETIME;                        //~v547I~
	#endif  //_WINDOWS_H                                           //~v5ncI~
	#endif                                                         //~v022R~
#endif                                                             //~v022M~
//when os2,without os2.h                                           //~v022R~
	#define APIRET      ULONG                                      //~v022R~
	#define APIRET16 	USHORT                                     //~v021I~//~v022R~
	typedef unsigned long    LHANDLE;                              //~v023I~
#ifndef _INC_WINDOWS   //dos,os2 without os2.h,w95 without windows.h//~v022R~
  #ifndef _WINDOWS_H     //mingw windows.h                         //~v5ncI~
	typedef unsigned char  UCHAR;   /* uch */                      //~v022R~
	typedef UCHAR *PUCHAR;                                         //~v022R~
	typedef char CHAR;            /* ch  */                        //~v022R~
	typedef CHAR *PCHAR;                                           //~v022R~
	typedef char BYTE;     /* b   */                               //~v022R~
  #ifdef LNX                                                       //~v690R~
	typedef UCHAR *PBYTE;                                          //~v690R~
  #else                                                            //~v690R~
	typedef BYTE *PBYTE;                                           //~v022R~
  #endif                                                           //~v690R~
	typedef char *PSZ;                                             //~v022R~
  #ifdef LNX                                                       //~v690R~
	typedef UCHAR *PCH;                                            //~v690R~
  #else                                                            //~v690R~
	typedef char *PCH;                                             //~v022R~
  #endif                                                           //~v690R~
	typedef unsigned long  ULONG;   /* ul  */                      //~v022R~
	typedef ULONG *PULONG;                                         //~v022R~
	typedef long   LONG;           /* l   */                       //~v022R~
	typedef LONG *PLONG;                                           //~v022R~
	typedef unsigned int   UINT;                                   //~v022R~
	typedef int            INT;                                    //~v022R~
	typedef VOID   *PVOID;                                         //~v022R~
	typedef PVOID  *PPVOID;                                        //~v022R~
  #endif //_WINDOWS_H                                              //~v5ncI~
#endif                                                             //~v022R~
//*copy from os2.h for shorten compile time                        //~v023I~
#ifdef UNX                                                         //~v321R~
	#include <ulibunx.h>                                           //~v321R~
#else                                                              //~v321R~
#ifdef DOS                                                         //~v023I~
    #ifdef DPMI					//DPMI version                     //~v053I~
        #define max(a,b) (((a)>(b)) ? (a):(b))                     //~v053I~
        #define min(a,b) (((a)<(b)) ? (a):(b))                     //~v053I~
        #define _MAX_PATH 260        /*same as MSC6*/              //~v053R~
    #else                       //not DPMI                         //~v053I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v023I~
    #ifdef W32                                                     //~v023I~
      #ifndef max  //mingw stdlib missing min max                  //~v5ncI~
        #define max(a,b) (((a)>(b)) ? (a):(b))                     //~v5ncI~
      #endif                                                       //~v5ncI~
      #ifndef min                                                  //~v5ncI~
        #define min(a,b) (((a)<(b)) ? (a):(b))                     //~v5ncI~
      #endif                                                       //~v5ncI~
    #else                       //os2                              //~v023I~
		#include <ulibos2.h>                                       //~v023R~
	#endif                                                         //~v023I~
#endif                                                             //~v023I~
#endif                                                             //~v321R~
#ifdef W32                                                         //~v6H9I~
//#define _MAX_PATH_LONG   4096    //\\?\c:\... fmt allows max 32767,but linux max is 4096(samba/ftp,each file max is 255)//~v6H9R~//~v6HcR~
	#define _MAX_PATH_LONG   (MAX_PATH_SZ_LINUX)                   //~v6HcR~
#else                                                              //~v6H9I~
	#define _MAX_PATH_LONG  _MAX_PATH                                  //~v6H9I~//~v6HcR~
#endif                                                             //~v6H9I~
                                                                   //~v6HcI~
#define _MAX_PATH2       (_MAX_PATH*2) //260*2 or 4096*2                 //~v6H1R~//~v6HcI~
#define _MAX_PATH2_LONG  (_MAX_PATH_LONG*2)                        //~v6H9R~//~v6HcI~
