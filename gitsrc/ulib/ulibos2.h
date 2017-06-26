//*CID://+v023R~:                                                  //~v023R~
//*********************************************************************
//ulibos2.h                                                        //+v023I~
//include from ulibdef.h when os2                                  //+v023I~
//ulibdef.h is called from ulib.h when the case except <os2.h> is included.//+v023I~
//* selective copy from os2.h to shorten compile time              //~v023R~
//*********************************************************************
//*copy from bsedos.h *************************************************//~v023R~
 //*************************************************************************
 //* CCHMAXPATHCOMP is the maximum individual path component name length   *
 //* including a terminating NULL.                                         *
 //*************************************************************************
   #define CCHMAXPATHCOMP     256                                  //~v023I~
//*                                                                //~v023I~
   /* known as Dos File Mode bits... */                            //~v023I~
   #define FILE_NORMAL     0x0000                                  //~v023I~
   #define FILE_READONLY   0x0001                                  //~v023I~
   #define FILE_HIDDEN     0x0002                                  //~v023I~
   #define FILE_SYSTEM     0x0004                                  //~v023I~
   #define FILE_DIRECTORY  0x0010                                  //~v023I~
   #define FILE_ARCHIVED   0x0020                                  //~v023I~
//*                                                                //~v023I~
   typedef LHANDLE HDIR;        /* hdir */                         //~v023I~
   typedef HDIR    *PHDIR;                                         //~v023I~
//*FDATE/FTIME  *                                                  //~v023I~
      /* File time and date types */                               //~v023I~
      #ifdef __IBMC__                                              //~v023I~
         typedef struct _FTIME           /* ftime */               //~v023I~
         {                                                         //~v023I~
            UINT   twosecs : 5;                                    //~v023I~
            UINT   minutes : 6;                                    //~v023I~
            UINT   hours   : 5;                                    //~v023I~
         } FTIME;                                                  //~v023I~
         typedef FTIME *PFTIME;                                    //~v023I~
      #else                                                        //~v023I~
         typedef struct _FTIME           /* ftime */               //~v023I~
         {                                                         //~v023I~
            USHORT   twosecs : 5;                                  //~v023I~
            USHORT   minutes : 6;                                  //~v023I~
            USHORT   hours   : 5;                                  //~v023I~
         } FTIME;                                                  //~v023I~
         typedef FTIME *PFTIME;                                    //~v023I~
      #endif                                                       //~v023I~
                                                                   //~v023I~
      #ifdef __IBMC__                                              //~v023I~
         typedef struct _FDATE           /* fdate */               //~v023I~
         {                                                         //~v023I~
            UINT   day     : 5;                                    //~v023I~
            UINT   month   : 4;                                    //~v023I~
            UINT   year    : 7;                                    //~v023I~
         } FDATE;                                                  //~v023I~
         typedef FDATE   *PFDATE;                                  //~v023I~
      #else                                                        //~v023I~
         typedef struct _FDATE           /* fdate */               //~v023I~
         {                                                         //~v023I~
            USHORT   day     : 5;                                  //~v023I~
            USHORT   month   : 4;                                  //~v023I~
            USHORT   year    : 7;                                  //~v023I~
         } FDATE;                                                  //~v023I~
         typedef FDATE   *PFDATE;                                  //~v023I~
      #endif                                                       //~v023I~
//*FILEFINDBUF3 *                                                  //~v023I~
      typedef struct _FILEFINDBUF3                 /* findbuf3 */  //~v023I~
      {                                                            //~v023I~
         ULONG   oNextEntryOffset;            /* new field */      //~v023I~
         FDATE   fdateCreation;                                    //~v023I~
         FTIME   ftimeCreation;                                    //~v023I~
         FDATE   fdateLastAccess;                                  //~v023I~
         FTIME   ftimeLastAccess;                                  //~v023I~
         FDATE   fdateLastWrite;                                   //~v023I~
         FTIME   ftimeLastWrite;                                   //~v023I~
         ULONG   cbFile;                                           //~v023I~
         ULONG   cbFileAlloc;                                      //~v023I~
         ULONG   attrFile;                    /* widened field */  //~v023I~
         UCHAR   cchName;                                          //~v023I~
         CHAR    achName[CCHMAXPATHCOMP];                          //~v023I~
      } FILEFINDBUF3;                                              //~v023I~
      typedef FILEFINDBUF3 *PFILEFINDBUF3;                         //~v023I~
                                                                   //~v023I~
