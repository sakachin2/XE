//*CID://+v6BkR:                              update#=  162;       //~v6BkR
//*********************************************************************//~v131I~
//* define --common to DOS/OS2/WIN95/UNX/LNX                       //~v321R~
//*********************************************************************//~v131I~
//v6G3:161212 (Win10) missing error.h , use winerror.h             //~v6BkI
//v6Bk:160220 (LNX)compiler warning                                //~v6xkI
//v6xk:150115 (BUG:W32)spwanxx deplicated,use _spawnxx(return intptr_t, Linux returns int pid)//~v6xkI
//v6xh:150115 (BUG)invalid dword calc;on 64bit linux long/ulong is 64bit,so DWADD dose not overflow//~v6xhI
//v6uY:140613 (LNX)f2u accept always UCS4 like as W32              //~v6uYI
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~v6uBI
//v6u9:140408 (Win)use UNICODE Api using special filename fmt.     //~v6u9I
//v6q3:131129 (LNX)compiler warning;dereferencing type-punned pointer//~v6q3I
//v6n1:130905 memcpy implementation of suse12.3(err if region overlap)(also for Windows spec)//~v6n1I
//v6k6:130619 (BUG of v6hc)OSTYPE=6 for 2010 64bit                 //+v6k6I~
//v6hC:120901 change Windows id "W"-->"6"(64bit)/"3"(32bit vc10)   //~v6hCI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v69A:101004 (BUG)2byte ucs to string(middle byte is invalid)     //~v69AI~
//v69c:100809 converter parm support for each b2m/m2b translation  //~v69cI~
//v693:100731 ostype="z" for s390 LP64                             //~v693I~
//v691:100730 LP64 wchar_t is 4byte on LP64                        //~v691I~
//v690:100701 m62(LP64:: int:32, long,void*:64) support (__LP64_)  //~v690I~
//v66X:100614 (LNX)CN-EBCDIC(CP935) si 2 byte dbcs only but local may be 4 byte dbcs for under GB18030(ex.u-81-x81308131)//~v66XI~
//v660:100325 local EBCDIC translation support                     //~v660I~
//v65i:100327 (WinCons)display 0x1b by unicodwe letterlike symbols u21xx because 0x1b make trouble for line clear//~v65iI~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v657:100217 (BUG:LNX):check endian by endian.h("#define BIGENDIAN" is not set for PPC)//~v657I~
//v647:100115 (WIN)wchar_t is ushort on Windows,consideration for UCS4//~v647I~
//v5nD:090329 S390 support                                         //~v5nDI~
//v5nu:081107 (Win)\\x\y remote filename support                   //~v5nuI~
//v5ng:081020 parmprefix for cygwin(windows version but unix like) //~v5ngI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5mQ:080806 (CJK)DBCS chk for C(J)K                              //~v5mQI~
//v5mn:080323 regex GCC support                                    //~v5mnI~
//v5mk:080312 regex OS/2 support                                   //~v5mkI~
//v5mj:080312 define REGEXSUPP macro                               //~v5mjI~
//v5mb:080220 (UTF)pre relese CHOFTYPE for xeacb                   //~v5mbI~
//v5ma:080219 (BUG)C;C break process after system(),spawn() because it loose console mode//~v5maI~
//v61g:071207*(LNX)locale support                                  //~v5maI~
//v600:070710 (UTF8)new typdef                                     //~v600I~
//v5k2:061227 (LNX/WIN)bc_dweditnum64(long long int edit func) add //~v5k2I~
//v5k0:061226 (LNX/WIN)largefile(>4GB) support                     //~v5k0I~
//v5g6:050613 (XXE)xxe support                                     //~v5g6I~
//v5c3:040325 (WIN)#define WINCON                                  //~v5c3I~
//v59u:031223 ftp support:DIR_ALL_MEMB is common to WIN and UNX(="*")//~v59uI~
//v59d:030816 ftp support                                          //~v59dI~
//v59b:031027 OSTYPE='A' for aix                                   //~v59bI~
//v57g:021229 ucs conv support except native dos                   //~v57gI~
//v421:010101 TLinux:libc5 stdlib.h include errno.h,but libc2 is not.//~v421I~
//v40m:001128 AIX support:Big endian                               //~v40mI~
//v344:000925 LINUX support(command flag parm prefix is "-" not "/")//~v344I~
//v321 000729:UNIX support                                         //~v321R~
//v208:981223 uimage.h                                             //~v208I~
//v189:980802 UGETVALUE macro                                      //~v189I~
//v131:971220 OSTYPE macro to ulibdef.h                            //~v131I~
//*********************************************************************//~v131I~
#ifdef DOS                                                         //~v690I~
	#ifdef DPMI                                                    //~v690I~
        #define DOSGCC      //id of gcc dos                        //~v690I~
	#else                                                          //~v690I~
        #define DOSDOS      //id of native dos                     //~v690I~
	#endif                                                         //~v690I~
#endif                                                             //~v690I~
//******                                                           //~v690I~
#ifdef __LP64__ //by -m64 cpl parm                                 //~v690I~
//*Linux 64bit(also long is 64bit)                                 //~v6uYI
    #define ULIB64  //internal use                                 //~v690I~
#endif                                                             //~v690I~
#ifdef _M_X64    //vs2010                                          //~v6hhI~
//*Windows 64bit(ptr is 64bit,long is 32bit)                       //~v6uYI
    #define ULIB64X  //internal use                                //~v6hhI~
#endif                                                             //~v6hhI~
#ifdef DOSDOS                                                      //~v690I~
  	#define UINT4 ULONG     //keep 4 byte                          //~v690I~
  	#define  INT4 LONG     //keep 4 byte                           //~v690I~
#else                                                              //~v690I~
  	#define UINT4 unsigned                                         //~v690I~
  	#define  INT4 int                                              //~v690I~
#endif                                                             //~v690I~
#ifdef ULIB64X	//ptr:64bit,long:32bit                             //~v6hhI~
	typedef unsigned long long ULPTR;                              //~v6hhI~
	typedef          long long SLPTR;                              //~v6hhI~
	#define  	LONGHANDLE intptr_t         //64bit                //~v6xkR
#else       //32bit or LP64(ptr:64,long:64                         //~v6hhI~
	typedef unsigned long      ULPTR;                              //~v6hhI~
	typedef          long      SLPTR;                              //~v6hhI~
    #ifdef W32                                                     //~v6xkI
		#define LONGHANDLE intptr_t 	//32bit                    //~v6xkR
    #else                                                          //~v6xkI
		#define LONGHANDLE int 			//32bit                    //~v6xkR
    #endif                                                         //~v6xkI
#endif                                                             //~v6hhI~
//*"long" is 8 byte on 64bit                                       //~v6a0I~
//  #define LLONG    long                                          //~v690I~//~v6hhR~
//  #define ULLONG   unsigned long                                 //~v690I~//~v6hhR~
//  #define PTRDIFF(ptr,ptr0)  ((ULLONG)(ptr)-(ULLONG)(ptr0))      //~v690I~//~v6hhR~
    #define PTRDIFF(ptr,ptr0)  ((int)((ULPTR)(ptr)-(ULPTR)(ptr0))) //~v6hhR~
//	#define PTRSZ sizeof(void *)                                   //~v690I~//~v6xkR
  	#define PTRSZ (int)sizeof(void *)                                   //~v690I~//~v6xkI
#ifdef LNX                                                         //~v6xkI
    #define UWUCS    WUCS                                          //~v6xkI
#else                                                              //~v6xkI
    #define UWUCS    UINT4                                         //~v690I~//~v691R~
#endif                                                             //~v6xkI
//  #define UWUCSSZ  sizeof(UWUCS)                                 //~v6uBI//~v6BkR
    #define UWUCSSZ  ((int)sizeof(UWUCS))                          //~v6BkI
//  typedef unsigned long  TYPEPTR2UL;  //for ucalc("long" replaced by #define),not used,use ULPTR til now//~v690I~//~v6hhR~
//******                                                           //~v690I~
#ifdef ARM                            //wchar_t:char if APIlevel<9 //~v6a0I~
    #define UTF8UCS4    //ucs4 support                             //~v6a0I~
    #define UTF8UCS416   //surrogate support                       //~v6uYI
   	#ifdef ARMAPI9	                                               //~v6a0I~
//  	typedef wchar_t WUCS,*PWUCS;                               //~v6a0I~//~v6xkR
   		#define  WUCS wchar_t                                      //~v6xkI
   		#define  PWUCS wchar_t*                                    //~v6xkI
		typedef wchar_t UWCHART,*PUWCHART;                         //~v6a0R~
    #else  //ARMAPI4:force 4byte wchar_t in ulib                   //~v6a0I~
		typedef int WUCS,*PWUCS;                                   //~v6a0I~
		typedef int UWCHART,*PUWCHART;                             //~v6a0I~
    #endif                                                         //~v6a0I~
#else                                                              //~v6a0I~
#ifdef UTF8UCS2                                                    //~v647I~
typedef wchar_t        UWCHART,*PUWCHART;                          //~v647R~
    #ifdef LNX                                                     //~v65cM~
        #define UTF8UCS4    //ucs4 support                         //~v65cM~
    #endif                                                         //~v65cM~
    #ifdef W32                                                     //~v6uBI
        #define UTF8UTF16   //surrogate support                    //~v6uBI
    #endif                                                         //~v65cM~//~v6uBI
    #if defined(UTF8UCS4) || defined(UTF8UTF16)                    //~v6uBI
        #define UTF8UCS416   //surrogate support                   //~v6uBI
    #endif                                                         //~v6uBI
    #ifdef UTF8UCS4                                                //~v65cI~
//  	typedef long int WUCS,*PWUCS;                              //~v65cR~//~v691R~
// 		typedef wchar_t  WUCS,*PWUCS;                              //~v691I~//~v6xkR
   		#define  WUCS wchar_t                                      //~v6xkI
   		#define  PWUCS wchar_t*                                    //~v6xkI
    #else                                                          //~v65cI~
typedef unsigned short WUCS,*PWUCS;                                //~v647I~
    #endif                                                         //~v65cI~
#else                                                              //~v647I~
//typedef unsigned short WUCS;                                       //~v5n8I~//~v5nDR~//~v647R~//~v691R~
typedef unsigned short WUCS,*PWUCS;                                //~v691I~
#endif                                                             //~v647I~
#endif  //ARM                                                      //~v6a0I~
//#define WUCSSZ   (sizeof(WUCS))                                    //~v5n8I~//~v6BkR
#define WUCSSZ   ((int)sizeof(WUCS))                                    //~v5n8I~//~v6BkI
                                                                   //~v5n8I~
#ifdef UTF8UCS4                                                    //~v65cI~
	#define if_UTF8UCS4(code)  code                                //~v65cI~
#else                                                              //~v65cI~
	#define if_UTF8UCS4(code)                                      //~v65cI~
#endif                                                             //~v65cI~
//#define MAXLOCALESZ  32	//locale id size                       //~v5n8R~
#define MAXLOCALESZ  64	//locale id size                           //~v5n8I~
#define ENTNOOF(tbl) (sizeof(tbl)/sizeof(tbl[0]))                  //~v321I~
#define ENTNOOF2(tbl) (sizeof(tbl)/sizeof(tbl[0][0]))              //~v321I~
#ifdef UNX                                                         //~v321R~
    #ifdef XXE                                                     //~v5g6I~
        #define W32XXE                                             //~v5g6I~
        #define WXEXXE                                             //~v5g6I~
#ifdef ARM                                                         //~v6a0I~
        #define ARMXXE                                             //~v6a0I~
#endif //ARM                                                       //~v6a0I~
    #endif                                                         //~v5g6I~
	#ifdef LNX           //linux                                   //~v321I~
      #ifdef XXE                                                   //~v65iI~
      	#define LNXCON                                             //~v65iI~
      #endif                                                       //~v65iI~
      #ifdef __s390__                                              //~v5nDR~
        #ifndef S390                                               //~v5nDI~
            #define S390                                           //~v5nDI~
        #endif                                                     //~v5nDI~
      #endif                                                       //~v5nDI~
      #ifdef S390                                                  //~v5nDI~
	    #define BIGENDIAN          //for S390                      //~v5nDI~
       #ifdef ULIB64                                               //~v693I~
    	#define	OSTYPE 'z'                                         //~v693I~
       #else                                                       //~v693I~
    	#define	OSTYPE '3'                                         //~v5nDR~
       #endif                                                      //~v693I~
      #else                                                        //~v5nDI~
        #include <endian.h>                                        //~v657I~
		#if __BYTE_ORDER == __BIG_ENDIAN                           //~v657I~
	    	#define BIGENDIAN          //for PPC                   //~v657I~
	    #endif //S390                                              //~v657I~
       #ifdef ARM                                                  //~v6a0I~
    	#define	OSTYPE 'a'       //arm(android)                    //~v6a0I~
       #else                                                       //~v6a0I~
    	#define	OSTYPE 'L'                                         //~v321I~
       #endif                                                      //~v6a0I~
      #endif //S390                                                //~v5nDI~
        #ifdef LNXLC2                                              //~v421I~
            #include <errno.h>     //alternatve libc5 stdlib.h     //~v421I~
        #endif                                                     //~v421I~
        #ifdef _LARGEFILE64_SOURCE    //use stat64                 //~v5k2R~
            #define LFSSUPP 1                                      //~v5k2I~
        #else                                                      //~v5k2I~
	    	#if defined _FILE_OFFSET_BITS && _FILE_OFFSET_BITS == 64 //stat is defined as stat64 by default//~v5k2I~
	            #define LFSSUPP 2     //api is 64 as default(xsub use)//~v5k2I~
            #endif                                                 //~v5k2I~
        #endif                                                     //~v5k2I~
        #ifdef LFSSUPP                                             //~v5k2R~
    		#define FILESZ_EDIT  "ll"         //long long          //~v5k2R~
            typedef long long int FILESZT;                         //~v5k0I~
    		#define FILESZ_MAX   0x7fffffffffffffffLL              //~v5k2I~
            typedef long long int FILESZT_S;//signed               //~v5k2I~
        #else                                                      //~v5k0I~
    		#define FILESZ_EDIT  "l"         //long long           //~v5k2R~
            typedef unsigned long FILESZT;                         //~v5k0I~
    		#define FILESZ_MAX   0xffffffffUL                      //~v5k2I~
            typedef          long FILESZT_S; //siged               //~v5k2I~
        #endif                                                     //~v5k0I~
        #define INT64SUPP                                          //~v5k2I~
        typedef long long int INT64;                               //~v5k2I~
        typedef unsigned long long int UINT64;                               //~v5k2I~//~v6xhI
    	#define SYNSUPP         //LNX:syntax highlight support     //~v5maI~
    	#define REGEXSUPP         //grep support                   //~v5mjR~
    #else                //unix                                    //~v321I~
        typedef unsigned long FILESZT;                             //~v5k0I~
    	#define FILESZ_MAX   0xffffffffUL                          //~v5k2I~
        typedef          long FILESZT_S; //siged                   //~v5k2I~
//  	#define	OSTYPE 'U'                                         //~v59bR~
    	#define	OSTYPE 'A'                                         //~v59bI~
        #define BIGENDIAN          //for AIX                       //~v40mI~
    #endif                                                         //~v321I~
    #define FTPSUPP         //ftp support=yes for win and unx      //~v59dI~
    #define WCSUPP          //wide char api(mbtowc etc) support    //~v5mQI~
    #define DIR_SEPC  '/'                                          //~v321R~
    #define DIR_SEPS  "/"                                          //~v321I~
    #define DIR_ALLMEMB "*"                                        //~v321I~
    #define CMDFLAG_PREFIX  '-'                                    //~v344I~
    #define CMDFLAG_PREFIX2 '/'                                    //~v344I~
//check command flag for parm ***************************          //~v344I~
//  '-':flag,'/' flag when not 1st parm of except '-'              //~v344I~
    #define CMDFLAGCHK(topbyte,secondsw) /* top byte and parm seqno except flag*/\
       ( ((topbyte)==CMDFLAG_PREFIX) ? 1 :   /* flag if '-' */\
            ( ((topbyte)!=CMDFLAG_PREFIX2) ? 0 : /* parm if not '-' and '/'*/\
                 ( (secondsw) ? 1 : 0 ) ) )/*1st "/" is parm*/     //~v344R~
    #define CMDFLAGCHK_AND_CYGWIN(cygwinsw,topbyte,secondsw) \
    		CMDFLAGCHK(topbyte,secondsw)                           //~v5ngI~
#else                                                              //~v321R~
    #define DIR_SEPC '\\'                                          //~v321R~
    #define DIR_SEPS "\\"                                          //~v321I~
  #ifdef W32                                                       //~v59uI~
    #define DIR_ALLMEMB "*"                                        //~v59uI~
  #else                                                            //~v59uI~
    #define DIR_ALLMEMB "*.*"                                      //~v321I~
  #endif                                                           //~v59uI~
    #define CMDFLAG_PREFIX  '/'                                    //~v344M~
    #define CMDFLAG_PREFIX2 '-'                                    //~v344M~
//check command flag for parm ***************************          //~v344I~
//  '-':flag,'/' flag when not 1st parm of except '-'              //~v344I~
    #define CMDFLAGCHK(topbyte,secondsw) /* top byte and parm seqno except flag*/\
       ( ((topbyte)==CMDFLAG_PREFIX) ? 1 :   /* flag if '/' */\
            ( ((topbyte)!=CMDFLAG_PREFIX2) ? 0 : 1 ) ) /* parm if not '-' and '/'*///~v5bhR~
    #define CMDFLAGCHK_CYGWIN(topbyte,secondsw) /* top byte and parm seqno except flag*/\
       ( ((topbyte)==CMDFLAG_PREFIX2) ? 1 :   /* flag if '-' */\
            ( ((topbyte)!=CMDFLAG_PREFIX) ? 0 : /* parm if not '-' and '/'*/\
                 ( (secondsw) ? 1 : 0 ) ) )/*1st "/" is parm*/     //~v5ngI~
    #define CMDFLAGCHK_AND_CYGWIN(cygwinsw,topbyte,secondsw) \
    	(                                                                               \
            (cygwinsw)?CMDFLAGCHK_CYGWIN(topbyte,secondsw):CMDFLAGCHK(topbyte,secondsw) \
        )                                                          //~v5ngI~
#ifdef DOS                                                         //~v131I~
	#ifdef DPMI                                                    //~v131I~
//      #define DOSGCC      //id of gcc dos                        //~v57gI~//~v690R~
    	#define	OSTYPE 'G'                                         //~v131I~
    	#define REGEXSUPP         //grep support                   //~v5mnI~
	#else                                                          //~v131I~
//      #define DOSDOS      //id of native dos                     //~v57gI~//~v690R~
    	#define	OSTYPE 'D'                                         //~v131I~
	#endif        	                                               //~v131I~
    #define FILESZ_EDIT  "l"         //long                        //~v5k2R~
    typedef unsigned long FILESZT;                                 //~v5k0I~
    #define FILESZ_MAX   0xffffffffUL                              //~v5k2I~
    typedef          long FILESZT_S; //siged                       //~v5k2I~
#else                                                              //~v131I~
	#ifdef W32                                                     //~v131I~
        #define W32XXE                                             //~v5g6I~
//    #ifdef LIB64X                                                //+v6k6R~
      #ifdef ULIB64X                                               //+v6k6I~
    	#define	OSTYPE '6'                                         //~v6hCI~
      #elif defined VC10EXP                                        //~v6hCR~
    	#define	OSTYPE '3'                                         //~v6hCI~
      #else                                                        //~v6hCI~
    	#define	OSTYPE 'W'                                         //~v131I~
      #endif                                                       //~v6hCI~
    	#define FTPSUPP         //ftp support=yes for win and unx  //~v59dI~
    	#define WCSUPP          //wide char api(mbtowc etc) support//~v5mQI~
    	#define SYNSUPP         //Win syntax highlight support     //~v5maI~
    	#define REGEXSUPP         //LNX:syntax highlight support   //~v5mjI~
    	#define WINREMOTESUPP     //\\xxx\yy support               //~v5nuI~
                                                                   //~v5k0I~
        #define LFSSUPP         //large file support               //~v5k0I~
	    #define FILESZ_EDIT  "I64"    //long long                  //~v5k2R~
        typedef __int64 FILESZT;                                   //~v5k0R~
        #define FILESZ_MAX   0x7fffffffffffffffI64                 //~v5k2I~
        typedef __int64 FILESZT_S;                                 //~v5k2I~
        #define INT64SUPP                                          //~v5k2I~
        typedef __int64 INT64;                                     //~v5k2I~
        typedef unsigned __int64 UINT64;                                     //~v5k2I~//~v6xhI
                                                                   //~v5k0I~
        #ifndef WXE                                                //~v5c3I~
        	#define WINCON		//windows console version          //~v5c3I~
        #else                                                      //~v5g6I~
	        #define WXEXXE                                         //~v5g6I~
        #endif                                                     //~v5c3I~
	#else                                                          //~v131I~
    	#define	OSTYPE '2'                                         //~v131I~
	    #define FILESZ_EDIT  "I"     //long                        //~v5k2R~
    	typedef unsigned long FILESZT;                             //~v5k0I~
        #define FILESZ_MAX   0xffffffffUL                          //~v5k2I~
    	typedef          long FILESZT_S;                           //~v5k2I~
    	#define REGEXSUPP         //grep support                   //~v5mkR~
	#endif                                                         //~v131I~
#endif                                                             //~v131I~
#endif                                                             //~v321R~
//*********************************************************************//~v189I~
#define UGETPV(type,ptr) ( *(type*)( (unsigned long)(ptr) ) )      //~v189R~
//*********************************************************************//~v208I~
#ifndef _WINNT_                                                    //~v208I~
//*****                                                            //~v208I~
//*for uimage.h  copy from windef.h                                //~v208I~
//*****                                                            //~v208I~
    typedef unsigned short         WCHAR;                          //~v208I~
                                                                   //~v208I~
    #ifdef DOS                                                     //~v208I~
		#ifdef DPMI                                                //~v208I~
			typedef unsigned long       DWORD,*PDWORD;             //~v208R~
			typedef unsigned short      WORD,PWORD;                //~v208R~
        #else                                                      //~v208I~
			typedef unsigned long       DWORD,*PDWORD;             //~v208I~
			typedef unsigned int        WORD,PWORD;                //~v208I~
        #endif                                                     //~v208I~
    #else                                                          //~v208I~
      #ifndef _WINDOWS_H //mingw windowsh                          //~v5ncR~
		typedef unsigned int        DWORD,*PDWORD;                 //~v208I~
		typedef unsigned short      WORD,PWORD;                    //~v208I~
      #endif                                                       //~v5ncI~
    #endif                                                         //~v208I~
//*****                                                            //~v208I~
#endif                                                             //~v208I~
#ifdef WINCON                                                      //~v5maI~
    #define IFDEF_WINCON(code) code                                //~v5maI~
#else                                                              //~v5maI~
    #define IFDEF_WINCON(code)                                     //~v5maI~
#endif                                                             //~v5maI~
#ifdef UTF8SUPP                                                    //~v5mbI~
	#define IFDEF_UTF8UPP(code) code                               //~v5mbR~
#else	                                                           //~v5mbI~
	#define IFDEF_UTF8UPP(code)                                    //~v5mbR~
#endif                                                             //~v5mbI~
#ifdef FTPSUPP                                                     //~v5mbI~
	#define IFDEF_FTPSUPP(code) code                               //~v5mbR~
#else                                                              //~v5mbI~
	#define IFDEF_FTPSUPP(code)                                    //~v5mbR~
#endif                                                             //~v5mbI~
#ifdef WCSUPP                                                      //~v5mQI~
	#define IFDEF_WCSUPP(code) code                                //~v5mQI~
#else                                                              //~v5mQI~
	#define IFDEF_WCSUPP(code)                                     //~v5mQI~
#endif                                                             //~v5mQI~
#ifdef SYNSUPP                                                     //~v5mbI~
	#define IFDEF_SYNSUPP(code) code                               //~v5mbI~
#else                                                              //~v5mbI~
	#define IFDEF_SYNSUPP(code)                                    //~v5mbI~
#endif                                                             //~v5mbI~
#ifdef WXE                                                         //~v5mbI~
	#define IFDEF_WXE(code) code                                   //~v5mbR~
#else                                                              //~v5mbI~
	#define IFDEF_WXE(code)                                        //~v5mbR~
#endif                                                             //~v5mbI~
#ifdef XXE                                                         //~v5mbI~
	#define IFDEF_XXE(code) code                                   //~v5mbR~
#else                                                              //~v5mbI~
	#define IFDEF_XXE(code)                                        //~v5mbR~
#endif                                                             //~v5mbI~
#ifdef WXEXXE                                                      //~v5mbI~
	#define IFDEF_WXEXXE(code) code                                //~v5mbR~
#else                                                              //~v5mbI~
	#define IFDEF_WXEXXE(code)                                     //~v5mbR~
#endif                                                             //~v5mbI~
#ifdef LNX                                                         //~v5mbI~
	#define IFDEF_LNX(code) code                                   //~v5mbR~
#else                                                              //~v5mbI~
	#define IFDEF_LNX(code)                                        //~v5mbR~
#endif                                                             //~v5mbI~
#ifdef W32                                                         //~v5mbI~
	#define IFDEF_W32(code) code                                   //~v5mbR~
#else                                                              //~v5mbI~
	#define IFDEF_W32(code)                                        //~v5mbR~
#endif                                                             //~v5mbI~
#ifdef DOS                                                         //~v5mbI~
	#define IFDEF_DOS(code) code                                   //~v5mbR~
#else                                                              //~v5mbI~
	#define IFDEF_DOS(code)                                        //~v5mbR~
#endif                                                             //~v5mbI~
#ifdef DOSGCC                                                      //~v5mbI~
	#define IFDEF_DOSGCC(code) code                                //~v5mbR~
#else                                                              //~v5mbI~
	#define IFDEF_DOSGCC(code)                                     //~v5mbR~
#endif                                                             //~v5mbI~
#ifdef DOSDOS                                                      //~v5mbI~
	#define IFDEF_DOSDOS(code) code                                //~v5mbR~
#else                                                              //~v5mbI~
	#define IFDEF_DOSDOS(code)                                     //~v5mbR~
#endif                                                             //~v5mbI~
#ifdef OS2                                                         //~v5mbI~
	#define IFDEF_OS2(code) code                                   //~v5mbR~
#else                                                              //~v5mbI~
	#define IFDEF_OS2(code)                                        //~v5mbR~
#endif                                                             //~v5mbI~
#ifdef BIGENDIAN                                                   //~v5nDI~
//little->big for ushort                                           //~v5nDI~
    #define IFBIG_SWAPUS(puso,usi)  *(puso)=(unsigned short)(((unsigned short)(usi)&255<<8)+((unsigned short)(usi)>>8))//~v5nDR~
//little->big for char*                                            //~v5nDI~
    #define IFBIG_SWAPPC2(pc)    *(unsigned short *)(void*)(pc)=(unsigned short)(((unsigned char)(*(pc+1))<<8)+(unsigned char)(*(pc)))//~v5nDR~
//load big endian ushort from char*                                //~v5nDI~
//  #define USTR2US(pc)  (unsigned short)(((unsigned char)(*(pc))<<8)+(unsigned char)(*(pc+1)))//~v5nDI~//~v6q3R
    #define USTR2US(pc)  (unsigned short)(  ((*(unsigned char*)(pc))<<8) + *((unsigned char*)(pc)+1)  )//~v5nDI~//~v6q3R
    #define USTR2UL(pc)  (  ((ULONG)USTR2US(pc)<<16)+(ULONG)USTR2US(pc+2)  )//~v6q3I
//  #define UBESTR2UL(pc)   /*get ulong from be string*/           //~v690R~
//        ( *(ULONG*)(ULONG)(pc) )                                 //~v66XI~//~v690R~
    #define UBESTR2UL4(pc)   /*get 4byte ulong from be string*/ \
          ( *(UINT4*)(ULONG)(pc) )                                 //~v690I~
                                                                   //~v690I~
    #define UBESTR2US(pc)   /*get ushort from be 2 byte string*/ \
          ( *(USHORT*)(ULONG)(pc) )                                //~v66XI~
    #define UBESTR2UL3(pc)   /*get ulong from be 3 byte string*/ \
          ( (UBESTR2US(pc)<<8) | (((UCHAR)(pc)[2])) )              //~v66XI~
//  #define UUL2BESTR(reg,pc)   /*set ulong to be string*/         //~v690R~
//         *(ULONG*)(ULONG)(pc)=(ULONG)(reg)                       //~v690R~
    #define UUL42BESTR(reg,pc)   /*set ulong to be string*/ \
           *(UINT4*)(ULONG)(pc)=(UINT4)(reg)                       //~v690I~
                                                                   //~v690I~
    #define UUL32BESTR(reg,pc)   /*set ulong to 3 byte be string*/ \
          ( (pc)[0]=(UCHAR)(((ULONG)(reg)>>16)&0xff),UUS2BESTR(reg,(pc)+1) )//~v66XI~
    #define UUS2BESTR(reg,pc)   /*set ushort to be string*/ \
           *(USHORT*)(ULONG)(pc)=(USHORT)(reg)                     //~v66XI~
                                                                   //~v690I~
  #ifdef ULIB64                                                    //~v690I~
    #define UBESTR2UL UBESTR2UL4                                   //~v690I~
    #define UBESTR2ULL(pc)   /*get ulong from be string*/ \
              ( *(ULONG*)(ULONG)(pc) )                             //~v690I~
    #define UUL2BESTR   UUL42BESTR                                 //~v690I~
    #define UULL2BESTR(reg,pc)   /*set ulong to be string*/ \
           *(ULONG*)(ULONG)(pc)=(ULONG)(reg)                       //~v690I~
  #else                                                            //~v690I~
    #define UBESTR2UL   UBESTR2UL4                                 //~v690I~
    #define UBESTR2ULL  UBESTR2UL4                                 //~v690I~
    #define UUL2BESTR   UUL42BESTR                                 //~v690I~
    #define UULL2BESTR  UUL42BESTR                                 //~v690I~
  #endif                                                           //~v690I~
                                                                   //~v690I~
#else                                                              //~v5nDI~
//**************                                                   //~v690I~
//*LittleEndian                                                    //~v690I~
//**************                                                   //~v690I~
    #define IFBIG_SWAPUS(uso,usi)                                  //~v5nDR~
    #define IFBIG_SWAPPC2(pc)                                      //~v5nDR~
//load little endian ushort from char*                             //~v5nDI~
//  #define USTR2US(pc)  (unsigned short)(((unsigned char)(*(pc+1))<<8)+(unsigned char)(*(pc)))//~v5nDI~//~v6q3R
    #define USTR2US(pc)  (unsigned short)(  (*((unsigned char*)(pc)+1)<<8) + *(unsigned char*)(pc)  )//~v5nDI~//~v6q3R
    #define USTR2UL(pc)  (  ((ULONG)USTR2US(pc+2)<<16)+(ULONG)USTR2US(pc)  )//~v6q3I
//  #define UBESTR2UL(pc)   /*get ulong from be string*/           //~v690R~
//        ( (((UCHAR)(pc)[0])<<24) | (((UCHAR)(pc)[1])<<16) | (((UCHAR)(pc)[2])<<8) | (((UCHAR)(pc)[3])) )//~v66XR~//~v690R~
                                                                   //~v690I~
    #define UBESTR2UL4(pc)   /*get ulong from be string*/ \
          ( (((UCHAR)(pc)[0])<<24) | (((UCHAR)(pc)[1])<<16) | (((UCHAR)(pc)[2])<<8) | (((UCHAR)(pc)[3])) )//~v690I~
                                                                   //~v690I~
    #define UBESTR2US(pc)   /*get ushort from be 2 byte string*/ \
          ( (((UCHAR)(pc)[0])<<8) | (((UCHAR)(pc)[1])) )           //~v66XI~
    #define UBESTR2UL3(pc)   /*get ulong from be 3 byte string*/ \
          ( (UBESTR2US(pc)<<8) | (((UCHAR)(pc)[2])) )              //~v66XI~
                                                                   //~v690I~
//  #define UUL2BESTR(reg,pc)   /*set ulong to be string*/         //~v690R~
//        ( (pc)[0]=(UCHAR)(((ULONG)(reg)>>24)),(pc)[1]=(UCHAR)(((ULONG)(reg)>>16)&0xff),(pc)[2]=(UCHAR)(((ULONG)(reg)>>8)&0xff),(pc)[3]=(UCHAR)((ULONG)(reg)&0xff) )//~v66XR~//~v690R~
    #define UUL42BESTR(reg,pc)   /*set ulong to be string*/ \
          ( (pc)[0]=(UCHAR)(((UINT4)(reg)>>24)),(pc)[1]=(UCHAR)(((UINT4)(reg)>>16)&0xff),(pc)[2]=(UCHAR)(((UINT4)(reg)>>8)&0xff),(pc)[3]=(UCHAR)((UINT4)(reg)&0xff) )//~v690M~
                                                                   //~v690M~
                                                                   //~v690I~
    #define UUL32BESTR(reg,pc)   /*set ulong to 3 byte be string*/ \
          ( (pc)[0]=(UCHAR)(((ULONG)(reg)>>16)&0xff),(pc)[1]=(UCHAR)(((ULONG)(reg)>>8)&0xff),(pc)[2]=(UCHAR)((ULONG)(reg)&0xff) )//~v66XR~//~v69AR~
//        ( (pc)[0]=(UCHAR)(((ULONG)(reg)>>16)&0xff),(pc)[1]=(UCHAR)(((ULONG)(reg)>>16)&0xff),(pc)[2]=(UCHAR)((ULONG)(reg)&0xff) )//~v69AI~
    #define UUS2BESTR(reg,pc)   /*set ushort to be string*/ \
          ( (pc)[0]=(UCHAR)(((USHORT)(reg)>>8)&0xff),(pc)[1]=(UCHAR)(((ULONG)(reg))) )//~v66XI~
  #ifdef ULIB64                                                    //~v690I~
    #define UBESTR2UL UBESTR2UL4                                   //~v690I~
    #define UBESTR2ULL(pc)   /*get ulong from be string*/ \
          ( ((ULONG)UBESR2UL4(pc)<<32) | ((ULONG)UBESTR2UL4(((pc)+4)) )//~v690M~
    #define UUL2BESTR    UUL42BESTR                                //~v690I~
    #define UULL2BESTR(reg,pc)   /*set ulong to be string*/ \
          ( UUL42BESTR((UINT4)((ULONG)(reg)>>32),  (pc)), \
            UUL42BESTR((UINT4)((reg) & 0xffffffff),(pc)+4), \
          )                                                        //~v690M~
  #else                                                            //~v690I~
    #define UBESTR2UL    UBESTR2UL4                                //~v690I~
    #define UBESTR2ULL   UBESTR2UL4                                //~v690I~
    #define UUL2BESTR    UUL42BESTR                                //~v690I~
    #define UULL2BESTR   UUL42BESTR                                //~v690I~
  #endif                                                           //~v690I~
#endif                                                             //~v5nDI~
#define UGETSTDARG(ptype,argsave,parm0,maxparmno)     /*get variable parameter addr*/\
	{                                                    \
    	va_list pargn0;                                  \
        int ii0;                                         \
        /******/                                         \
    	va_start(pargn0,parm0);   /*argn point next arg*/\
    	for (ii0=0;ii0<maxparmno;ii0++)                  \
        	argsave[ii0]=va_arg(pargn0,ptype);           \
    	va_end(pargn0);                                  \
    }  //UGETSTDARG                                                //~v5nDR~
                                                                   //~v660I~
#define UWHICH(sw,v1,v2) ((sw)?(v1):(v2))                          //~v660R~
#define UBITCHKALL(flag,bits) (((flag) & (bits))==(bits))          //~v66XI~
#define MAX_CSNAMESZ  60                                           //~v69cI~
//**search char and set pos and substring len                      //~v6u9I
#define USUBSTRLEN(pc,ch,len,pcend,substrlen) \
    do {                                          \
        char *_pc2;                                \
        int _len;                                 \
        _pc2=memchr((pc),ch,(len));                \
        if (_pc2)                                  \
            _len=PTRDIFF(_pc2,(pc));                \
        else                                      \
            _len=(len);                           \
        *(substrlen)=_len;                        \
        *(pcend)=_pc2;                                \
   }while(0)                                                       //~v6u9I
                                                                   //~v6u9I
	typedef unsigned short UWCH,*PUWCH; //for filename utf16(unsigned short)//~v6uYI
	#define UWCHSZ           sizeof(UWCH)                          //~v6uYI
                                                                   //~v6uYI
#include  <ustrcpy.h>                                             //~v600I~//~v6n1I
                                                                   //~v660I~
#include  <ulibdefu.h>                                             //~v600I~
#include  <ulibarm.h>                                              //~v6a0R~
#include  <ulibdefw.h>     //ucs string fuctions                   //~v6u9I
