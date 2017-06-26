//*CID://+vad1R~:                             update#=  658;       //+vad1R~
//***********************************************************
//* XDComp : directory status compare                              //~v1.aR~
//***********************************************************
//vad1:170103 xdc v2.28 correct err msg                            //+vad1I~
//vaa2:160424 Lnx64 compiler warning(FDATE/FTIME)                  //~vaa2I~
//vaa1:160418 Lnx64 compiler warning                               //~vaa1I~
//vaa0:160417 Lnx compiler warning                                 //~vaa0I~
//va9E:160404 compiler warning win64                               //~va9EI~
//va9D:160310 xdc v2.26 for /X entry,not skip write but not select for valid entry count//~va9DI~
//va9C:160310 xdc v2.26 uninitialized data was written to interfile//~va9CI~
//va9B:160310 xdc v2.26 (BUG of va91)uninitialized area was printed//~va9BI~
//va9A:160310 xdc v2.26 support multiple filename mask to include  //~va9AI~
//va9z:160310 xdc v2.26 allow excludemask compare match * with 0 byte("a*" match with "a")//~va9zI~
//va9k:150305 xdc v2.25 add /=N (no consideration for "=")         //~va9kI~
//va9h:150303 xdc v2.25 add /=F (apply \"=" to fullpath)           //~va9gI~
//va9g:150303 xdc v2.25 add /Xexcludename option                   //~va9gI~
//va9f:150303 xdc v2.25 add /Uo (disply "only-1"/"only-2")                      //~va9fI~//~va9gR~
//va9e:150228 xdc v2.25 support copy path specification ../=/..    //~va9eI~//~va9fR~
//va91:140503 xdc v2.24:(Win)UNICODE version                       //~va91R~
//va78:131129 (LNX)compiler warning;dereferencing type-punned pointer//~va78I~
//va76:130622 compiler warning and err by ndk-r9                   //~va76I~
//va73:130618 (LNX)xdc change default slink chk is no              //~va73I~
//            if skip on, chk slink entry but do not step down into the target dir//~va71I~
//va71:130618 (W32)dirwalk support windows slink/junction/mountpoint//~va71I~
//va70:121022 udosfindnext was changed by symlink support          //~va70I~
//va6c:120807 xdc v2.19 compare timestamp by not 2secs but 1sec    //~va6cI~
//va6b:120805 xdc v2.19 time zone parameter /TZ(-)hh:mm, compare file1+TZ==file2//~va6bI~
//va69:120730 xdc v2.19 Java:ZipEntry.getTime returns +1 sec for odd number of lastmodified time.//~va69I~
//            So,time stamp compare result "(",")" for diff<=2 seconds//~va69I~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va65I~
//va65:120621 (BUG)found vy fc12 compiler warning                  //~va65I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va62:120407 xdc:2.18 uid/gid compare                             //~va62I~
//va52:111119 xdc:2.17 compiler warning:unused-but-set             //~va52I~
//va51:111102 xdc:2.17 xfc fails is /fr(redirect-dir) option missing(/fc only)//~va51I~
//va4u:110517 xdc:2.16 add option to filecompare by any command(default:xfc)//~va4uR~
//va4t:110402 xdc:2.15 (BUG) LongFilename option reset when NT filesystem//~va4tI~
//va4b:090413 xdc v2.14 (s390)big endian interface file            //~va4bI~
//va43:080831 xdc.c v2.13:/FT:textmode file compare option even when file size isnot same//~va43I~
//va3w:080503 xdc.c v2.12:(BUG) /L option reset LFN                //~va3wI~
//va3n:080129 xdc v2.11 english msg spell miss                     //~va3nI~
//va3b:070620 xdc:2.10 modify last help msg for used from xe       //~va3bR~
//va35:070519 xdc:(BUG of LNX findfirst:see ulib v5ka)errmsg  "fnm is not dir or not found"//~va35R~
//va30:061227 xdc v2.9:filesize>4GB support                        //~va30I~
//va22:050215 xdc:v2.8:/f option:file binary compare if size equal //~va1BI~
//va1V:050116 xdc:v2.8:(BUG)subdir search bypass whe file mask specified//~va1BI~
//va1B:041116 xdc:v2.7:2 path specification required for both is intermediate file//~va1BI~
//va1A:041116 xdc:v2.7:(BUG)dir only msg when intmfile and dir compare and dir has no member//~va1AI~
//                          (it remains "." on local variable fstat.achNmae)//~va1AI~
//va1z:041116 xdc:v2.7:support subdir on intermedoate input file   //~va1zI~
//*va1d:040221 xdc:v2.6:v141:(BUG) not found for c: (no fullpath drive only case)//~va1dI~
//*va18:031123 xdc:v2.6:use userrmsg for sjis & euc conversion under LNX//~va18I~
//*va17:031103 xdc:v2.6:ftp support(4 byte udirlist attr for ! UNX)//~va17I~
//021009 xdc:v2.5 v266 (UNX)slink err msg option(/Nm)(u#244)       //~v266I~
//020925 xdc:v2.5 v265 ROOTDIR chk both unix and pc when intm file chk.//~v264I~
//020925 xdc:v2.5 v264 (BUG of v262) dir entry has last "/"; so back to old logic//~v264I~
//                     dirn only msg but attr is not same ctr is count-upeed.//~v264I~
//020924 xdc:v2.5 v263 (BUG) inthdr miss pathname when root        //~v263I~
//020921 xdc:v2.5 v262 (BUG of v257)because fnt->fnm is member name;complen-1 is invalid//~v261R~
//020921 xdc:v2.5 v261 (BUG)compare unix and dos;                  //~v261I~
//                     dos intfile is case insensitive seq but unit is sensitive seq//~v261I~
//020921 xdc:v2.5 v260 (BUG)not found msg at 2nd level when mask used//~v259R~
//020921 xdc:v2.5 v259 display mask when intermediate file is reated//~v259I~
//020919 xdc:v2.5 v258 performance2 tuning; raedsub call           //~v258I~
//020908 xdc:v2.5 v257 performance tuning; pathlen call            //~v258R~
//020908 xdc:v2.5 v256 (UNX)slink skip opt /Ns(over update#129)    //~v256R~
//020908 xdc:v2.5 v255 (UNX)slink loop chk(over update#125)        //~v256R~
//020808 xdc:v2.5 v254 (BUG)1 Shfile for 2 intf-file               //~v254I~
//020807 xdc:v2.5 v253 Long name max length parm support /Lnn      //~v252I~
//020807 xdc:v2.5 v252 (BUG)wildcard compare DBCS filename support //~v252I~
//020714 xdc:v2.5 v251 (UNX)allow special file                     //~v251I~
//*011215 xdc:v23g option of list unmatch but low/high date/time only//~v23gI~
//*011210 xdc:v23f issue notfound msg for dir/file parm            //~v23fI~
//*011129 xdc:v23e add option to list time stamp unmatch only(-ut) //~v23eI~
//*011124 xdc:v23d add option to list file size unmatch only(-us)  //~v23dR~
//*011124 xdc:v23c (BUG) ufstat fail for "a:"                      //~v23bI~
//*011101 xdc:v23b (BUG) when /io and parm1 is file,output interf is invalid//~v23bI~
//*011015 xdc:v23a (BUG:UNX) case sensitive for filename comp      //~v23aI~
//*011001 xdc:v239 (BUG:AIX) big endian                            //~v239I~
//*010930 xdc:v238 (BUG)mask ignored when intmfile used            //~v238I~
//*010930 xdc:v237 (BUG) display fnm as null                       //~v236I~
//*010920 xdc:v236 (BUG:AIX) big endian                            //~v236I~
//*010914 xdc:v235 unit attr edit fmt(rwxd/lugt fmt)               //~v234I~
//*010913 xdc:v234 Both intf support                               //~v234I~
//*010910 xdc:v233 (BUG:AIX)FTIME/FDATE is int(4 byte),time stamp compare failed//~v233I~
//*010908 xdc:v232 cmd flag prefix on errmsg,intermediate file name on stdout//~v232I~
//*010519 xdc v231:filenme comapre case option                     //~v231I~
//*010331 xdc v2.3:LINUX support:                                  //~v2.3R~
//*             default int attr,crlf of cont line,printf fmt chk  //~v2.3I~
//*             option prefix,all_memb,dir seperator               //~v2.3R~
//*             case-sensitive filename                            //~v2.3I~
//*             dos and unix compare support                       //~v2.3I~
//*             4 byte attr(not upward compatibility)              //~v2.3I~
//*v2.2 *000213 y2kBUG(2000->100)                                  //~v2.2I~
//*v2.1 *980926 relese version                                     //~v1.xI~
//*v1.x *980926 helpmsg pause                                      //~v1.xI~
//*v1.w *980926 display attr on detaile line                       //~v1.wI~
//*v1.v *980926 report * as sign of warning                        //~v1.vI~
//*v1.u *980924 report detail attr unmatch                         //~v1.uI~
//*v1.t *980924 for dbcs filename(\ may be dbcs 2nd byte);protection apply//~v1.tI~
//*v1.s *980923 no need @ support for intermediate file if /I is specified//~v1.sI~
//*v1.r *980923 save space for intermediate file(have lrecl)       //~v1.rI~
//*v1.q *980921 filename .a or ..a etc under win95                 //~v1.qI~
//* 980921 v1.p os type on intermediate file output last msg       //~v1.pI~
//* 980921 v1.o re-link by new FTIME/FDATE                         //~v1.oR~
//*             for intermediate file compatibility between WIN and others//~v1.oR~
//* 971220 v1.n:(BUG) errnous PATHLEN for not init field           //~v1.mI~
//              cause not found for 2nd dir(o:\-->o:\\*.*)         //~v1.mI~
//* 971220 v1.m:W95/GCC version                                    //~v1.mR~
//* 971220 v1.l:LFN support                                        //~v1.lI~
//* 971220 v1.k:summary report                                     //~v1.kI~
//* will rel with xe 9.0                                           //~v1.jI~
//* 961117 v1.j:(BUG)set strz for dir1/dir2                        //~v1.jI~
//* rel with xe 8.0                                                //~v1.jI~
//* 960923 v1.i:use ulib unumedit because DOS issue dup funcname err//~v1.iI~
//*            :use ulib for \ as dbcs filename                    //~v1.iI~
//* 960916 v1.h:distinguish not same for file and directory        //~v1.hI~
//*            :use ulib for \ as dbcs filename                    //~v1.hI~
//* 960713 v1.g:same file name counter display                     //~v1.gI~
//* 960602 v1.f:total size edit by unumedit                        //~v1.fR~
//* 960602 v1.e:(bug)file name sort seq abc\>abcde                 //~v1.fI~
//* 960601 v1.d:sub dir process by ascending seq(malloc for dir entry)//~v1.dI~
//* 960601 v1.c:dir size print                                     //~v1.cI~
//* 960601 v1.b:add chk result for attribute                       //~v1.bI~
//* 960526 v1.a:chk result date/time and size for each             //~v1.bR~
//* 960526 v1.9:option to compare through file                     //~v1.aR~
//* 960525 v1.8:dir name on no corresponding dir msg               //~v1.8I~
//* 960525 v1.7:work malloc size for OS/2                          //~v1.7R~
//*            :(BUG) when last is \(c:\ etc) and subdir sw(/s)    //~v1.7I~
//* 960520 v1.6:print line width<80(filename without pathname,32-->20)//~v1.6R~
//* 950916 v1.5:-bug,attr set miss when not fild card           //~v1.5I~
//*             -bug of v1.3,DosFindFirst faile(no corresp file!)//~v1.5I~
//*             -for hidden dir                                 //~v1.5I~
//* 940801 v1.4:-os2
//* 940801 v1.3:-add /1,/2 option
//* 940722 v1.2:-bug of v1.1 drive letter only support
//*              mask is ignored when first file is not subdir
//* 940424 v1.1:-for root dir(drive letter only)
//*              findfirst return no file for c: or c:\  ;         //~va1BR~
//*             -file exist chk at first level
//*             -dir2 only subdir display
//***********************************************************

#define VER "V2.28"   //version                                    //+vad1R~
//#ifdef UNX                                                         //~v2.3I~//~va9eR~
	#define PGM "xdc"                                              //~v2.3I~
//#else                                                              //~v2.3I~//~va9eR~
//#define PGM "XDC"                                                  //~v1.7R~//~va9eR~
//#endif                                                             //~v2.3I~//~va9eR~

//**********************************************/
//*parm1 : file name 1
//*parm2 : file name 2
//*r.c   : 0 :all file area same
//*      : 1 :unequal file exist
//*      : 4 :parameter err
//**********************************************/
//*
#ifdef DOS                   

	#include <dos.h>            
	#include <errno.h>          
#else
  #ifdef W32                                                       //~v1.lR~
	#include <dos.h>                                               //~v1.mI~
  #else                                                            //~v1.lI~
	#define INCL_BASE
	#include <os2.h>     
  #endif                                                           //~v1.lI~
#endif               
                                                                //~v1.5I~
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#ifdef UNX                                                         //~v256I~
	#include <sys/stat.h>                                          //~v256I~
#endif                                                             //~v256I~
                                                                   //~v1.hI~
//*********************************************************************//~v1.hI~
#include <ulib.h>                                                  //~v1.hI~
#include <ualloc.h>                                                //~va9gI~
#include <ufile.h>                                                 //~v1.hI~
#include <ufile2.h> 		//ufileisvfat                          //~va6bI~
#include <ufile4.h> 		//ufileisvfat                          //~v1.mI~
#include <ufile5.h> 		//ufileisvfat                          //~v238I~
#include <uedit.h>                                                 //~v1.iI~
#include <uedit2.h>                                                //~v1.wI~
#include <uerr.h>                                                  //~v1.xI~
#include <udbcschk.h>                                              //~v1.xI~
#include <ustring.h>                                               //~v2.3I~
#include <uque.h>                                                  //~v258I~
#include <ufemsg.h>                                                //~va30I~
#include <uproc.h>                                                 //~va4uI~
#include <ucalc.h>                                                 //~va69I~
#include <ucalc2.h>                                                //~va69I~
#include <utrace.h>                                                //~va4uI~
#include <ufilew.h>                                                //~va91I~
#include <utf.h>                                                   //~va91I~
//*********************************************************************

#ifdef DOS                                                         //~v1.7R~
//  #define MAXFNSZ 12                                             //~v1.lR~
    #define MAXFNSZ MAXFILENAMEZ                                   //~v1.lI~
    #ifdef DPMI					//DPMI version                     //~v1.lI~
		#define TBLSZ   1024000                                    //~v1.lI~
    #else                                                          //~v1.lI~
	#define TBLSZ   65502                                          //~v1.7R~
    #endif                                                         //~v1.lI~
#else                                                              //~v1.7R~
	#define MAXFNSZ _MAX_PATH                                      //~v1.7R~
 #ifdef UNX                                                        //~v255I~
	#define TBLSZ   (sizeof(FNTBL)*10000)                          //~v255I~
 #else                                                             //~v255I~
	#define TBLSZ   1024000                                        //~v1.7R~
 #endif                                                            //~v255I~
#endif                                                             //~v1.7R~
#define MAXPATH _MAX_PATH                                          //~v1.7R~
#define MAXLEVEL 32                                                //~v1.cI~
#define FILENAMEFLDSZ 20                                           //~v1.6I~
#define MAX_FILENAMEFLDSZ 128                                      //~v252I~
#if defined(DOS) && !defined(DPMI)                                 //~va43M~
	#define BUFFSZ  	32760   //32k                              //~va43M~
#else                                                              //~va43M~
	#define BUFFSZ  	131072	//128k                             //~va43M~
#endif                                                             //~va43M~
//*********************************************************************
#ifdef W32                                                         //~v1.oI~
#pragma pack(push,1)                                               //~v1.oI~
#endif                                                             //~v1.oI~
                                                                   //~v1.oI~
typedef struct _POSTB {                                            //~v258I~
					   UQUEE POSTqh;                               //~v258I~
                       ULONG POSTpos;                              //~v258I~
                       ULONG POSTposchild;                         //~v258I~
                       int   POSTdirnmlen;                         //~v258I~
                       char  POSTdirnm[1];                         //~v258I~
                       } POSTB,*PPOSTB;                            //~v258I~
#define POSTBSZ sizeof(POSTB)                                      //~v258I~
typedef struct _MASKLIST {                                         //~va9gI~
					   UQUEE MLqh;                                 //~va9gI~
                       char  MLname[1];                            //~va9gI~
                       } MASKLIST,*PMASKLIST;                      //~va9gI~
#define MASKLISTSZ sizeof(MASKLIST)                                //~va9gI~
                                                                   //~v258I~
typedef struct _FNTBL   
				{
                	char          fnm[MAXFNSZ+1+1];                //~v1.6R~
//              	char          fattr;                           //~v2.3R~
                	ULONG         fattr;                           //~v2.3I~
//#ifdef UNX                                                       //~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
	#define         FNT_SLINKLOOP     0x00000100 //slink loop detected//~v256I~
#endif                                                             //~v256I~
//                  unsigned long fsz;                             //~va30R~
                    FILESZT       fsz;     //64bit support         //~va30I~
                    FTIME 		  ftm;
                    FDATE 		  fdt;
                    UINT          uid;                             //~va62I~
                    UINT          gid;                             //~va62I~
                    UINT          sec1;                            //~va6cI~
#if defined(W32)||defined(UNX)                                     //~va71I~
                    char          *slink;                          //~va71I~
#endif                                                             //~va71I~
				} FNTBL;
#define ENTSZ   (sizeof(FNTBL))                                    //~v1.8M~

#ifdef LFSSUPP                                                     //~va30I~
typedef struct _INTMTBLADD2     //additional data uid/gid          //~va62I~
				{                                                  //~va62I~
                    UINT uid;                                      //~va62I~
                    UINT gid;                                      //~va62I~
//                  UINT rsv[2];                                   //~va6cR~
                    UINT sec1;                                     //~va6cI~
                    UINT rsv[1];                                   //~va6cI~
				} INTMTBLADD2,*PINTMTBLADD2;                       //~va62I~
#define INTMTBLADDSZ2   (sizeof(INTMTBLADD2))                      //~va62I~
typedef struct _INTMTBLADD      //additional data(file size 64bit high//~va30I~
				{                                                  //~va30I~
                    unsigned long sepdata;     //null seperation data//~va30I~
#define LFSID       0x00ffff00				   //different with eolid,save for big/little endian//~va30I~
#define LFSID2      0x00fdfd00				   //contains uid/gid data//~va62I~
                    unsigned long fszhigh;     //high 32bit of filesize//~va30I~
                    INTMTBLADD2 moredata2;     //uid,gid           //~va62I~
				} INTMTBLADD,*PINTMTBLADD;                         //~va30I~
#define INTMTBLADDSZ   (sizeof(INTMTBLADD))                        //~va30I~
#endif                                                             //~va30I~
                                                                   //~va30I~
typedef struct _INTMTBL                                            //~v1.8I~
				{                                                  //~v1.8I~
//              	char          fnm[MAXPATH];                    //~v1.rR~
                	USHORT        lrecl;                           //~v1.rI~
                	USHORT        recid;                           //~v1.rI~
#define INTMFRECID 0xbeef                                          //~v1.rR~
#define INTMFRECID2 0xefbe      //little endian                    //~v239I~
//****                                                             //~v1.rI~
                    unsigned long fsz;                             //~v1.8I~
#ifdef AIX                                                         //~v239I~//~va4bR~
                    USHORT		  ftm;                             //~v239I~
                    USHORT		  fdt;                             //~v239I~
#else                                                              //~v239I~
                    FTIME 		  ftm;                             //~v1.8I~
                    FDATE 		  fdt;                             //~v1.8I~
#endif                                                             //~v239I~
//                  char          fattr;                           //~v2.3R~
                    ULONG         fattr;                           //~v2.3I~
//****9 byte from fsz for header record                            //~v1.rI~
//                  char          rsv[2];                          //~v1.rR~
                	char          fnm[MAXPATH];                    //~v1.rI~
#ifdef LFSSUPP                                                     //~va30I~
                    INTMTBLADD    moredata;                        //~va30I~
#endif                                                             //~va30I~
//                  char          eor;                             //~v1.rR~
//                  char          zeor[3];  	//x'00'+cr+lf(0d0a)//~v2.3R~
                    char          zeor[4];  	//x'00'+cr+lf(0d0a)+boundary(sizeof for UNIX)//~v2.3I~
				} INTMTBL,*PINTMTBL;                               //~v1.rR~
#define INTMTBLSZ   (sizeof(INTMTBL))                              //~v1.8I~
#define PREREADLEN  (sizeof(((PINTMTBL)0)->lrecl)+sizeof(((PINTMTBL)0)->recid))//~v1.rI~
                                                                   //~v1.rI~
                                                                   //~v1.8I~
#ifdef W32                                                         //~v1.oI~
#pragma pack(pop)                                                  //~v1.oI~
#endif                                                             //~v1.oI~
                                                                   //~v1.oI~
#define SLINK_TARGET_UNMATCH  '@'                                  //~va71I~
#define INTMFID   '@'                                              //~v1.8I~
#define INTMFIDS  "@"                                              //~v1.8I~
#define MASKAPPENDID  0x01                                         //~v259I~
#define ACRONYM   "XDC!INT!\a"                                     //~v1.8R~
#define ACRONYMSZ (sizeof(ACRONYM)-1)                              //~v1.8R~
//*********************************************************************
static char *Spgm=PGM,*Sver=VER;                                   //~v1.9I~
static char *Suneqopt=0;                                           //~v23gI~
//static int Sdbcssw;                                              //~va1BR~
//#ifdef UNX                                                       //~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
//	static int Sslinkchksw=1;                                      //~va73R~
	static int Sslinkchksw=0;                                      //~va73I~
#endif                                                             //~v256I~
static int Stoplevelsw=1;                                          //~v259I~
static int Subdirsw=0;
static int Sfilenamefldsz=FILENAMEFLDSZ;	//filename display field size//~v252I~
static int Uneqsw=0;
static int Uneqsws=0;                                              //~v23dI~
static int Uneqswo=0;                                              //~va9fI~
static int Uneqswt=0;            //list timestamp unmatch only     //~v23eI~
static int Uneqswu=0;            //uid/gid unmatch                 //~va62I~
static int Samecnt=0;           //same file cnt                    //~v1.hR~
static int Swcopt=UFWC_DOS_DEFAULT | UFWC_CASE_DEFAULT;            //~v252R~
//static int Samecnt2=0;          //date and size is same file cnt //~v1.kR~
static int Samecntdir=0;        //same dir cnt                     //~v1.hI~
//static int Samecntdir2=0;       //date and size is same dir cnt  //~v1.kR~
//static int Bothdircnt=0;        //it is dir on both dir          //~v1.kR~
static int Dir1cnt=0,Dir2cnt=0;	//only ctr for file                //~v1.kR~
static int Dir1cntdir=0,Dir2cntdir=0;	//only ctr for dir         //~v23aR~
static int Samenamecnt=0;       //path-filename equal count        //~v1.gI~
static int Dir1sw=0,Dir2sw=0;	//v1.3a
static int Sdir1dossw=0,Sdir2dossw=0;	//dos dir sw               //~v2.3I~
static int Sdossw=0;                                               //~v239I~
static int Tot1=0,Tot2=0;
static int Tot1dir=0,Tot2dir=0;                                    //~v23aR~
static int Sfileanddircnt=0;       //same name but attr is dir and file//~v23aR~
static int Sdirandfilecnt=0;       //dir on dir1 and file on dir2  //~v23aR~
static int Ssizenecnt=0;       	//same name and size is unequal    //~v23aR~
static int Scontentsnecnt=0;       //both is file and same size but contents compare fail//~va1BR~
static int Ssizenetextcompokctr=0;                                 //~va43I~
static int Ssizenecntdir=0;       //same name and size is unequal dir//~v23aR~
static int Stsnecnt=0;       		//same name and timestamp is unequal//~v23aR~
static int Stsnecntdir=0;       	//same name and timestamp is unequal dir//~v23aR~
static int Sts2seccnt=0;       		//same name and timestamp is unequal//~va69I~
static int Sts2seccntdir=0;       	//same name and timestamp is unequal dir//~va69I~
static int Sattrnecnt=0;       	//same name and attr except dir is unequal//~v23aR~
static int Sattrnecntdir=0;       //same name and attr except dir is unequal dir//~v23aR~
static int Suidnecnt=0;       	//same name and attr except dir is unequal//~va62I~
static int Suidnecntdir=0;       //same name and attr except dir is unequal dir//~va62I~
static int Swarningsw=0;                                           //~v23aR~
static int Scaseoption=0;     //filename compare case option       //~v23aR~
static int  SattrRnecnt=0;                                         //~v23aR~
static int  SattrHnecnt=0;                                         //~v23aR~
static int  SattrSnecnt=0;                                         //~v23aR~
static int  SattrAnecnt=0;                                         //~v23aR~
static int  SattrRnecntdir=0;                                      //~v23aR~
static int  SattrHnecntdir=0;                                      //~v23aR~
static int  SattrSnecntdir=0;                                      //~v23aR~
static int  SattrAnecntdir=0;                                      //~v23aR~
#ifdef UNX                                                         //~v2.3I~
	static int  SattrRWXnecnt=0;                                   //~v23aR~
	static int  SattrRWXnecntdir=0;                                //~v23aR~
#endif                                                             //~v2.3I~
#if defined(W32)||defined(UNX)                                     //~va71I~
	static int  SattrSLINKnecnt=0;                                 //~va71I~
	static int  SattrSLINKnecntdir=0;                              //~va71I~
#endif                                                             //~va71I~
static char Scnteditp[]="zzz,zz9";                                 //~v1.kR~
//static int Pathlen1,Pathlen2;                                    //~v1.8R~
//static int Scomppathlen1,Scomppathlen2;   //compare pathlen parm //~v262R~
static char Sintfmask[3][_MAX_PATH];                               //~v259I~
static FNTBL *Tbl1,*Tbl2;
static char *Dir1="",*Dir2="",*Mask=""; 
static char fnameedit[]="-nn.nnds";                                //~v1.6I~
static char *Sinterfnm=0;	//intermideate file                    //~v23aR~
static char *Sinterfnm1;	//1st intfname for read                //~v234I~
static char *Sinterfnm2=0;	//2nd intfname when both is intf       //~v23aR~
static char *Sinterpath=0;	//path specification in intermediatefile//~va1zI~
static char *Sinterpath2=0;	//path specification in intermediatefile//~va1BI~
static int  Sintfsw=0;	//intermideate input/output sw             //~v23aR~
// 1:fn1=file,fnm2=dir,2:fnm1=dir,fnm2=file,3:fnm1 or fnm2=file as output//~v236I~
static int  maxent,tblsz=TBLSZ;                                    //~v1.8I~
//static long Sdirsz[2][MAXLEVEL+1];	//dir total size           //~va30R~
static FILESZT Sdirsz[2][MAXLEVEL+1];	//dir total size           //~va30I~
static int  Slevel=0;                                              //~v23aR~
static FILE *Shfile=0;                                             //~v23aR~
static FILE *Shfiletbl[3];  //1:dir1,2:dir2                        //~v254I~
static	char Spgmver[16];                                          //~v1.xI~
static	int Stzparm;                                               //~va6bI~
//static long Scurpos;	//current position(after read) to recov next pos//~v1.dR~
//static long Snextpos;	//findnext rext pos after level down       //~v1.dR~
//static char *Scurpath;	//current path for findnext            //~v1.dR~
#if defined(W32) || defined(DPMI)                                  //~va3wI~
static int Slfnsw=0;                                               //~v23aR~
#endif                                                             //~va3wI~
static char Szcrlf[4]={0x00,0x0d,0x0a,0x00};                       //~v23aR~
long  Sposafterhdr;			//save detail record pos               //~v1.rI~
long  Sposafterhdrtbl[3];			//save detail record pos       //~v254I~
PPOSTB Spostbl[3];			//dir pos tbl chain top                //~v258I~
PPOSTB Spostbltop;			//pos tbl top entry                    //~v258I~
static FILEFINDBUF3 Sfstat31,Sfstat32;                             //~v234I~
static int  Sfilecompsw=0;                                         //~va1BI~
//                           0x01:bincomp for same size,0x02:textcomp for not same size//~va43I~
#define COMP_BY_XFC          0x04                                  //~va4uI~
static char *Sfilecomppath1,*Sfilecomppath2;   //parm to lineprint for filecompare//~va1BR~
#ifdef LFSSUPP                                                     //~va30I~
	static int Slfsintf[3];            //intermediate file is written by system support LFS//~va30R~
#endif                                                             //~va30I~
static char *Scompcmd;                                             //~va4uR~
static char *Scompcmdredirect;                                     //~va4uR~
static char *Sfindfirstdir; //for findnext,dir at findfirst        //~va70R~
static char *Sstartdir; //top dir to slink loop chk                //~va71I~
static UQUEH Sqhxmask; //exclude mask que header                   //~va9gI~
static UQUEH Sqhimask; //exclude mask que header                   //~va9AI~
static int Sswxmask;                                               //~va9gI~
static int Sswimask;                                               //~va9AI~
//********************
void parmchk(int,char *[]);
void stackfile(int Pdirid,char *Pdir,char *Pmask,FNTBL *Pfnt,int *Pentno,int *Pentnodir);//~v1.kR~
int  lineprint(FNTBL *,FNTBL *);//compare result line print
void help(void);
//int findfile(int Pdirid,char *Pfile,int Pattr,FILEFINDBUF3 *Pfstat,ULONG *Phdir);//~v1.mR~
//int findfile(int Pdirid,char *Pfile,int Pattr,FILEFINDBUF3 *Pfstat,HDIR *Phdir,int Pmasksw);//~v238R~//~va9DR~
int findfile(int Pdirid,char *Pfile,int Pattr,FILEFINDBUF3 *Pfstat,HDIR *Phdir,int Popt);//~va9DI~
int compare(const void*,const void*);//sort
char *tsedit(char*,FNTBL*);//edit date and time of directory
//int unumedit(unsigned long Pnum,unsigned char *Ppatern,unsigned char *Pout);//~v1.iR~
void  proc1level(char*,char*,char*,char *);//one dir level process;//~v1.8R~
void wtintf(char *Ppath,FNTBL *Pfnt);                              //~v1.9R~
//char *ufullpath(char *Pfullpath,char *Pfilename,size_t Plen);    //~v1.hR~
//int rdintf(int Pmasksw,char *Pfile,FILEFINDBUF3 *Pfstat);          //~v238R~//~va9DR~
int rdintf(int Popt,char *Pfile,FILEFINDBUF3 *Pfstat);             //~va9DI~
int freadsub(void *Pioa);                                          //~v1.9R~
void rdintfhdr(char *Pfullpath,char *Pmask);                       //~v259R~
void psummline(int Pcnt1,int Pcnt2,int Ptotalsw,char *Pcomment,int Perrsw);//~v1.vR~
FNTBL *getdirtbl(FNTBL *Pfntbl,int Pentry,int *Pdirentry);         //~v1.dI~
FNTBL *srchdirtbl(FNTBL *Pfntbl,int Pentry,char *Pfilenm);         //~v1.dR~
int xdcpathlen(char *Pfilename);                                   //~v2.3I~
void xdcdirsepcat(char *Pfnm);                                     //~v2.3I~
int xdcfnmcmp(char *Pfnm1,char *Pfnm2,UINT Plen);                  //~v2.3R~
void interfmsg(int Pdirid);                                        //~v234I~
int xdcchklastsepc(char *Pfilename,int Plen);                      //~v257I~
PPOSTB xdcpostblgen(void);                                         //~v258R~
int xdcsetchild(UQUEH *Ppqh,char *Ppathnm,int Ppathlen,ULONG Ppos);//~v258I~
void xdcfseek(ULONG Ppos);                                         //~v258I~
void xdcinterpath(char *Pfpath,char *Pinterpath);                  //~va1zI~
int filecomp(FNTBL *Pfnt1,FNTBL *Pfnt2);                           //~va1BI~
int filecomptext(FNTBL *Pfnt1,FNTBL *Pfnt2);                       //~va43R~
FILE *openfile(char *Pfile,char *Popt,int Pmsgsw);                 //~va43I~
int filecompbyxfc(FNTBL *Pfnt1,FNTBL *Pfnt2);                      //~va4uI~
int setlinefnm(char *Pline,char *Pfnm,char *Pfnameedit,int Pfldsz,char **Ppcontpos);//~va91R~
void stackMask(UQUEH *Ppqh,char *Pmask);                           //~va9gI~
int chkMask(int Popt,UQUEH *Ppqh,char *Pmask);                     //~va9gR~
#define CMO_NOEXPAND 0x01                                          //~va9gI~
void printxmask();                                                 //~va9gI~
void printimask();                                                 //~va9AI~
char *getallmaskstring(int Popt,UQUEH *Ppqh,UQUEH *Ppqhx);                      //~va9AR~//~va9BR~
//*********************************************************************//~v239I~
//*convert little<-->big endian 4 byte int                         //~v239I~
//*********************************************************************//~v239I~
UINT xdcgetuint(void *Ppuint)                                      //~v239I~
{                                                                  //~v239I~
	UCHAR *pc;                                                     //~v239I~
    UINT  ret;                                                     //~v239I~
//*******************************                                  //~v239I~
    pc=Ppuint;                                                     //~v239I~
//#ifdef AIX                                                         //~v239I~//~va4bR~
#ifdef BIGENDIAN                                                   //~va4bI~
    if (!Sdossw)                                                   //~v239I~
        return *(UINT*)Ppuint;                                     //~v239R~
    ret=(UINT)( (UINT)*(pc+0)                                      //~v239I~
              | ((UINT)*(pc+1)<<8)                                 //~v239I~
              | ((UINT)*(pc+2)<<16)                                //~v239I~
              | ((UINT)*(pc+3)<<24)                                //~v239I~
              );                                                   //~v239I~
    return ret;                                                    //~v239I~
#else                                                              //~v239I~
    if (Sdossw)                                                    //~v239I~
        return *(UINT*)Ppuint;                                     //~v239R~
    ret=(UINT)(  (UINT)*(pc+3)                                     //~v239I~
              | ((UINT)*(pc+2)<<8)                                 //~v239I~
              | ((UINT)*(pc+1)<<16)                                //~v239R~
              | ((UINT)*(pc+0)<<24)                                //~v239I~
              );                                                   //~v239I~
    return ret;                                                    //~v239I~
#endif                                                             //~v239I~
}//xdcgetuint                                                      //~v239I~
//*********************************************************************//~v239I~
//*convert little<-->big endian 4 byte int                         //~v239I~
//*********************************************************************//~v239I~
USHORT xdcgetushort(void *Ppushort)                                //~v239I~
{                                                                  //~v239I~
	UCHAR *pc;                                                     //~v239I~
    USHORT ret;                                                    //~v239I~
//*******************************                                  //~v239I~
    pc=Ppushort;                                                   //~v239I~
//#ifdef AIX                                                         //~v239I~//~va4bR~
#ifdef BIGENDIAN                                                   //~va4bI~
    if (!Sdossw)                                                   //~v239I~
        return *(USHORT*)Ppushort;                                 //~v239R~
    ret=(USHORT)(  (UINT)*(pc+0)                                   //~v23aR~
             | ((UINT)*(pc+1)<<8)                                  //~v239I~
             );                                                    //~v239I~
    return ret;                                                    //~v239I~
#else                                                              //~v239I~
    if (Sdossw)                                                    //~v239I~
        return *(USHORT*)Ppushort;                                 //~v239R~
    ret=(USHORT)(  (UINT)*(pc+1)                                   //~v23aR~
             | ((UINT)*(pc+0)<<8)                                  //~v239I~
             );                                                    //~v239I~
    return ret;                                                    //~v239I~
#endif                                                             //~v239I~
}//xdcgetushort                                                    //~v239I~
//*********************************************************************//~v239I~
//*convert little<-->big endian fdate/ftime                        //~v239I~
//*********************************************************************//~v239I~
void xdcfdtcnv(void *Ppfdt)                                        //~v239R~
{                                                                  //~v239I~
//*******************************                                  //~v239I~
    *(USHORT*)Ppfdt=xdcgetushort(Ppfdt);                           //~v239I~
}//xdcfdtcnv                                                       //~v239R~
                                                                   //~v239I~
#ifdef AIX                                                         //~v239I~//~va4bR~
//*********************************************************************//~v239I~
//*convert FDTAE/FTIME record to table                             //~v239I~
//*********************************************************************//~v239I~
void xdcfdtcnvr2t(void *Prec,void *Ptbl)                           //~v239I~
{                                                                  //~v239I~
//*******************************                                  //~v239I~
    *(ULONG*)Ptbl=(ULONG)*(USHORT*)Prec;                           //~v239I~
}//xdcfdtcnvr2t                                                    //~v239I~
//*********************************************************************//~v239I~
//*convert FDTAE/FTIME table to record                             //~v239I~
//*********************************************************************//~v239I~
void xdcfdtcnvt2r(void *Ptbl,void *Prec)                           //~v239I~
{                                                                  //~v239I~
//*******************************                                  //~v239I~
    *(USHORT*)Prec=(USHORT)*(ULONG*)Ptbl;                          //~v239I~
}//xdcfdtcnvt2r                                                    //~v239I~
#endif                                                             //~v239I~
                                                                   //~v239I~
//*********************************************************************
//* return 0:fully equall
//*        1:unmatch exist
//*        4:encountered error condition
//*********************************************************************
int main(int parmc,char *parmp[])
{
    char fullpath1[MAXPATH+1],fullpath2[MAXPATH+1];                //~v1.8R~
    char fullpathi[MAXPATH+1];                                     //~v1.9I~
    char fullpathi2[MAXPATH+1];                                    //~v234I~
    char numeditwk[16];                                            //~v1.fI~
    char cnteditwk[8];                                             //~v1.kR~
//  HDIR hdir;                                                     //~va35R~
	FILEFINDBUF3 fstat;                                            //~v1.9I~
#ifdef UNX                                                         //~v251I~
	int attr=FILE_ALLSP;                                           //~v251I~
#else                                                              //~v251I~
	int attr=FILE_ALL;                                             //~v1.9R~
#endif                                                             //~v251I~
    int tot;                                                       //~v1.fI~
    unsigned long sz;                                              //~va30R~
    char *dirnm;                                                   //~v1.fI~
//  char *mask;                                                    //~v1.kI~//~va9AR~
  	time_t stck;                 //stck value                      //~v1.kR~
  	char timewk[26];             //www mmm dd hh:mm:ss yyyy\n\0    //~v1.kR~
//***

//**********************************
//* main
//**********************************
#ifdef W32UNICODE                                                  //~va91I~
    SET_UDMODE();  //filename by UD format                         //~va91I~
#endif                                                             //~va91I~
//*errmsg init start ***                                           //~v1.xI~
	sprintf(Spgmver,"%s:%s(%c): ",PGM,VER,OSTYPE);                 //~v1.xI~
	uerrmsg_init(Spgmver,stdout,0);//msg to stdout                 //~v1.xI~
	uerrexit_init(Spgmver,stdout,0,0,0);//stdout only,no pathmsg   //~v1.xI~
	uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit       //~v1.xI~
//  Sdbcssw=udbcschkcp();                                          //~va1BR~
//*errmsg init end *****                                           //~v1.xI~
#if defined(W32) || defined(DPMI)                                  //~v1.mI~
    #ifdef DPMI					//DPMI version                     //~v1.mI~
        putenv("LFN=Y");                 //need for ufileisvfat    //~v1.mI~
    #else                       //not DPMI                         //~v1.mI~
    #endif                      //DPMI or not                      //~v1.mI~
  #if defined(DPMI)	//NT file system avail for both,depend /A option//~va4tI~
	Slfnsw=ufileisvfat(ISVFAT_FORCE);                              //~v1.mI~
  #else                                                            //~va4tI~
	Slfnsw=1;                                                      //~va4tI~
  #endif                      //DPMI or not                        //~va4tI~
#endif                      //DPMI or not                          //~v1.mI~
//  sprintf(fnameedit,"%%-%02d.%02ds",FILENAMEFLDSZ,FILENAMEFLDSZ);//~v252R~
//  printf("%s\n",fnameedit);                                      //~v1.6R~
  parmchk(parmc,parmp);
    sprintf(fnameedit,"%%-%02d.%02ds",Sfilenamefldsz,Sfilenamefldsz);//~v252M~
//  maxent=tblsz/ENTSZ-1;                                          //~v1.8I~//~vaa0R~
    maxent=tblsz/(int)ENTSZ-1;                                     //~vaa0I~
  Tbl1=malloc((UINT)tblsz);	                                       //~v1.8R~
  if (!Tbl1)	
  {	
  	  printf("%s:%s:table size=%d,malloc failed\n",Spgm,Sver,tblsz);//~v1.9R~
      exit(4);
  }
  Tbl2=malloc((UINT)tblsz);	                                       //~v1.8R~
  if (!Tbl2)	
  {	
  	  printf("%s:%s:table size=%d,malloc failed\n",Spgm,Sver,tblsz);//~v1.9R~
      exit(4);
  }

	if (Sinterfnm)                                                 //~v1.9I~
    {                                                              //~v1.9I~
        if (!ufullpath(fullpathi,Sinterfnm,sizeof(fullpathi)))     //~v1.9I~
	    {                                                          //~v1.9I~
			printf("\n%s:%s: %s is path error.\n",                 //~v1.9I~
					Spgm,Sver,Sinterfnm);                          //~v1.9I~
			exit(4);                                               //~v1.9I~
	    }                                                          //~v1.9I~
    	Sinterfnm=fullpathi;                                       //~v1.9I~
    	Sinterfnm1=fullpathi;                                      //~v234I~
	}                                                              //~v1.9I~
	if (Sinterfnm2)                                                //~v234I~
    {                                                              //~v234I~
        if (!ufullpath(fullpathi2,Sinterfnm2,sizeof(fullpathi2)))  //~v234I~
	    {                                                          //~v234I~
			printf("\n%s:%s: %s is path error.\n",                 //~v234I~
					Spgm,Sver,Sinterfnm2);                         //~v234I~
			exit(4);                                               //~v234I~
	    }                                                          //~v234I~
    	Sinterfnm2=fullpathi2;                                     //~v234I~
	}                                                              //~v234I~
    	                                                           //~v1.9I~
    if (Dir1)                                                      //~v1.8I~
    {                                                              //~v1.8I~
//      if (Sintfsw==1)                                            //~v234R~
        if (Sintfsw==1 ||  Sinterfnm2)                             //~v234R~
        {                                                          //~v232I~
//          interfmsg(1);                                          //~v259R~
            Sinterfnm=Sinterfnm1;                                  //~v234I~
            rdintfhdr(fullpath1,Sintfmask[1]);                     //~v259R~
#ifdef LFSSUPP                                                     //~va30M~
            Slfsintf[1]=Slfsintf[0];	//lfs sw                   //~va30M~
#endif                                                             //~va30M~
            interfmsg(1);                                          //~v259I~
            Shfiletbl[1]=Shfile;                                   //~v254I~
            Sposafterhdrtbl[1]=Sposafterhdr;                       //~v254I~
    		Spostbl[1]=xdcpostblgen();                             //~v258I~
//          printf("********** dir1 is by %s **********\n",fullpathi);//~v234R~
        }                                                          //~v232I~
        else                                                       //~v1.8I~
        {                                                          //~v1.9I~
	        if (!ufullpath(fullpath1,Dir1,sizeof(fullpath1)))      //~v1.8R~
    	    {                                                      //~v1.8R~
				printf("\n%s:%s: %s is path error.\n",             //~v1.8R~
						Spgm,Sver,Dir1);                           //~v1.9R~
				exit(4);                                           //~v1.8R~
    	    }                                                      //~v1.8R~
//printf("p1:Dir1=%s,fullpath1=%s,arg=%s\n",Dir1,fullpath1,parmp[1]);//@@@@//~v1.mR~
          if (!ROOTDIR(fullpath1))                                 //~v1.mI~
//			if (findfile(1,fullpath1,attr,&fstat,&hdir,0)  //dir1 exist v1.3a//~va35R~
  			if (findfile(1,fullpath1,attr,&fstat,0,0)  //hdir=0:means return attr of dir itself//~va35I~
    		||  !(fstat.attrFile & FILE_DIRECTORY)) //not dir      //~v1.9R~
//              if (!ROOTDIR(fullpath1))                           //~v1.mR~
    		    {                                                  //~v1.dI~
					printf("\n%s:%s:%s is not directory,or not found.\n",//~v1.dR~
							Spgm,Sver,fullpath1);                  //~v1.dR~
					exit(4);                                       //~v1.dR~
	    	    }                                                  //~v1.dR~
		}                                                          //~v1.9I~
        Dir1=fullpath1;                                            //~v1.8I~
//		Pathlen1=(int)strlen(Dir1);		//v1.4r                    //~v1.8R~
		Sdir1dossw=(*Dir1!='/');	//not unix type filename       //~v2.3I~
    }                                                              //~v1.8I~
    if (Dir2)                                                      //~v1.8I~
    {                                                              //~v1.8I~
        if (Sintfsw==2)                                            //~v1.8I~
        {                                                          //~v232I~
          	if (Sinterfnm2)                                        //~v234I~
            	Sinterfnm=Sinterfnm2;                              //~v234I~
            else                                                   //~v234I~
            	Sinterfnm=Sinterfnm1;                              //~v234I~
//          interfmsg(2);                                          //~v259R~
            rdintfhdr(fullpath2,Sintfmask[2]);                     //~v259R~
#ifdef LFSSUPP                                                     //~va30M~
            Slfsintf[2]=Slfsintf[0];	//lfs sw                   //~va30M~
#endif                                                             //~va30M~
            interfmsg(2);                                          //~v259I~
            Shfiletbl[2]=Shfile;                                   //~v254I~
            Sposafterhdrtbl[2]=Sposafterhdr;                       //~v254I~
    		Spostbl[2]=xdcpostblgen();                             //~v258I~
//          printf("********** dir2 is by %s **********\n",fullpathi);//~v234R~
//          printf("********** dir2 is by %s **********\n",Sinterfnm);//~v234R~
        }                                                          //~v232I~
        else                                                       //~v1.8I~
        {                                                          //~v1.9I~
	        if (!ufullpath(fullpath2,Dir2,sizeof(fullpath2)))      //~v1.8R~
    	    {                                                      //~v1.8R~
				printf("\n%s:%s: %s is path error.\n",             //~v1.8R~
						Spgm,Sver,Dir2);                           //~v1.9R~
				exit(4);                                           //~v1.8R~
    	    }                                                      //~v1.8R~
//printf("p2:Dir2=%s,fullpath2=%s,arg=%s\n",Dir2,fullpath2,parmp[2]);//@@@@//~v1.mR~
        if (!ROOTDIR(fullpath2))                                   //~v1.mI~
//  		if (findfile(2,fullpath2,attr,&fstat,&hdir,0) //dir2 exist v1.3a//~va35R~
    		if (findfile(2,fullpath2,attr,&fstat,0,0) //dir2 exist v1.3a; 0:attr is of dir itself//~va35I~
    		||  !(fstat.attrFile & FILE_DIRECTORY)) //not dir      //~v1.9R~
//              if (!ROOTDIR(fullpath2))                           //~v1.mR~
	    	    {                                                  //~v1.dR~
					printf("\n%s:%s:%s is not directory,or not found.\n",//~v1.dR~
							Spgm,Sver,fullpath2);                  //~v1.dR~
					exit(4);                                       //~v1.dR~
	    	    }                                                  //~v1.dR~
		}                                                          //~v1.9I~
        Dir2=fullpath2;                                            //~v1.8I~
//		Pathlen2=(int)strlen(Dir2);		//v1.4r                    //~v1.8R~
		Sdir2dossw=(*Dir2!='/');	//not unix type filename       //~v2.3I~
    }                                                              //~v1.8I~
    if (Dir1)                                                      //~va1zI~
    {                                                              //~va1zI~
        if (Sintfsw==1 ||  Sinterfnm2)                             //~va1zM~
        {                                                          //~va1zM~
            if (Sinterpath)                                        //~va1zM~
                xdcinterpath(fullpath1,Sinterpath);//after Sdir1dossw/Sdir2dossw set//~va1zI~
        }                                                          //~va1zM~
    }                                                              //~va1zI~
    if (Dir2)                                                      //~va1zI~
    {                                                              //~va1zI~
        if (Sintfsw==2)                                            //~va1zM~
        {                                                          //~va1zM~
            if (Sinterpath2)                                       //~va1BI~
                xdcinterpath(fullpath2,Sinterpath2);               //~va1BI~
            else                                                   //~va1BI~
            if (Sinterpath)                                        //~va1zM~
                xdcinterpath(fullpath2,Sinterpath);                //~va1zM~
        }                                                          //~va1zM~
    }                                                              //~va1zI~
//wildcard compare type for unix                                   //~v238I~
	if (Sintfsw && Sintfsw!=3 && *Mask)		//intmf read and mask used//~v238I~
    {                                                              //~va17I~
    	if (!Sdir1dossw && !Sdir2dossw)	//both unix                //~v238I~
//      	udoseditnameopt(DEN_UNIX);//unix type wildcard compare //~v252R~
        	Swcopt&=~UFWC_DOS;//case sensitive compare             //~v252I~
        else                                                       //~v238I~
    		if (Sdir1dossw!=Sdir2dossw)	//unix and dos             //~v238I~
            	uerrmsg("Warning! UNIX and DOS is differrent for \".\" in wild card mask.",0);//~v254R~
    }                                                              //~va17I~
    proc1level(Dir1,Dir2,Mask,0);//one dir level process; 	       //~v1.8R~
	if (Sintfsw==3)		//output                                   //~v1.fR~
	{                                                              //~v1.fI~
	    if (Dir1)                                                  //~v1.fR~
        {                                                          //~v1.fI~
            dirnm=Dir1;                                            //~v1.fI~
	    	tot=Tot1;                                              //~v1.fI~
//          sz=(unsigned long)Sdirsz[0][0];                        //~va30R~
    	    ufileeditsz(0,Sdirsz[0][0],numeditwk);                 //~va30I~
		}                                                          //~v1.fI~
        else                                                       //~v1.fI~
        {                                                          //~v1.fI~
            dirnm=Dir2;                                            //~v1.fI~
	    	tot=Tot2;                                              //~v1.fI~
//          sz=(unsigned long)Sdirsz[1][0];                        //~va30R~
    	    ufileeditsz(0,Sdirsz[1][0],numeditwk);                 //~va30I~
		}                                                          //~v1.fI~
//  	unumedit(sz,"z,zzz,zzz,zz9",numeditwk);                    //~va30R~
//  	printf("\n%s:%s: %-32.32s has %5d files(%s ),\n\      //   //~va1BR~
//          (mask=%s), written to %s\n",                           //~v1.pI~
//  		Spgm,Sver,dirnm,tot,numeditwk,Mask,Sinterfnm);         //~v1.pI~
    	printf("\n%s:%s:=(%c)===  %s  has %d files(%s ),\n\
             written to %s ===\n",                                 //~va9AM~
    		Spgm,Sver,OSTYPE,dirnm,tot,numeditwk,Sinterfnm);       //~va9AM~
//          (mask=%s), written to %s ===\n",                       //~v1.pR~//~va9AR~
//  		Spgm,Sver,OSTYPE,dirnm,tot,numeditwk,Mask,Sinterfnm);  //~v1.pR~//~va9AR~
	}                                                              //~v1.fI~
  	else                                                           //~v1.fR~
    {                                                              //~v1.9I~
		time(&stck);                                               //~v1.kI~
		strcpy(timewk,asctime(localtime(&stck))+4);//drop week     //~v1.kI~
        *(timewk+26-4-2)=0;	//drop \n                              //~v1.kI~
//      mask=Mask;                                                 //~v1.kI~//~va9AR~
//      if (!*Mask)                                                //~v1.kI~//~va9AR~
//          mask="*.*";                                            //~v2.3R~
//          mask=DIR_ALLMEMB;                                      //~v2.3R~//~va9AR~
//      printf("\n=== Compare Summary === at %s === (Mask=%s",     //~v23fR~//~va9AR~
//  			timewk,mask);                                      //~v1.kR~//~va9AI~
        printf("\n=== Compare Summary === at %s ===",              //~va9AR~
    			timewk);                                           //~va9AI~
        if (Suneqopt)                                              //~v23gI~
        	printf(",opt=%s",Suneqopt);                            //~v23gR~
        if (Sintfsw)        //output                               //~v1.kI~
          if (Sinterfnm2)	//both is intf                         //~v234R~
//          printf(",through %s and %s).\n",Sinterfnm,Sinterfnm2); //~v234I~//~va9AR~
            printf(" ,through %s and %s.\n",Sinterfnm,Sinterfnm2); //~va9AR~
          else                                                     //~v234I~
//          printf(",through %s).\n",Sinterfnm);                   //~v1.kI~//~va9AR~
            printf(" ,through %s.\n",Sinterfnm);                   //~va9AR~
        else                                                       //~v1.kI~
//          printf(") ===\n");                                     //~v1.kR~//~va9AR~
            printf("===\n");                                       //~va9AR~
        printimask();                                              //~va9AI~
        printxmask();                                              //~va9gR~
//      sz=(unsigned long)Sdirsz[0][0];                            //~va30R~
//  	unumedit(sz,"z,zzz,zzz,zz9",numeditwk);                    //~va30R~
    	ufileeditsz(0,Sdirsz[0][0],numeditwk);                     //~va30R~
        sz=(unsigned long)Tot1;			//dir1 total               //~v1.kI~
    	unumedit(sz,Scnteditp,cnteditwk);                          //~v1.kI~
//        printf("\n%s:%s: %-32.32s has %5d file/dir(%s ),\n",     //~v1.kR~
//                Spgm,Sver,Dir1,Tot1,numeditwk);                  //~v1.kR~
        printf(" Dir1= %-32.32s ;entry=%s ,size=%s\n",             //~v1.kR~
                  Dir1,cnteditwk,numeditwk);                       //~v1.kR~
//      sz=(unsigned long)Sdirsz[1][0];                            //~va30R~
//  	unumedit(sz,"z,zzz,zzz,zz9",numeditwk);                    //~va30R~
    	ufileeditsz(0,Sdirsz[1][0],numeditwk);                     //~va30I~
        sz=(unsigned long)Tot2;			//dir1 total               //~v1.kI~
    	unumedit(sz,Scnteditp,cnteditwk);                          //~v1.kI~
//      printf("          %-32.32s has %5d file/dir(%s ).\n\    // //~va1BR~
//        %d files(s) are same out of %d same name(mask=%s",       //~v1.hR~
//  		Dir2,Tot2,numeditwk,Samecnt,Samenamecnt,Mask);         //~v1.hR~
//        printf("          %-32.32s has %5d file/dir(%s )\n",     //~v1.kR~
//            Dir2,Tot2,numeditwk);                                //~v1.kR~
        printf(" Dir2= %-32.32s ;entry=%s ,size=%s\n",             //~v1.kR~
                  Dir2,cnteditwk,numeditwk);                       //~v1.kR~
//hdr                                                              //~v1.kI~
		psummline(-1,0,0,0,0);	//header line                      //~v1.vR~
//dir1 cnt                                                         //~v1.kI~
		psummline(Tot1-Tot1dir,Tot1dir,1,"Dir1 entry",0);          //~v1.vR~
//dir2 cnt                                                         //~v1.kI~
		psummline(Tot2-Tot2dir,Tot2dir,1,"Dir2 entry",0);          //~v1.vR~
//        printf("          %d / %d ( %d / %d for dir) is unmatch among the same name,\n",//~v1.kR~
//            Samenamecnt-(Samecnt+Samecntdir),Samenamecnt,        //~v1.kR~
//            Bothdircnt-Samecntdir,Bothdircnt);                   //~v1.kR~
//        printf("          %d ( %d for dir) is unmatch in size or timestamp only,\n",//~v1.kR~
//            Samenamecnt-(Samecnt2+Samecntdir2),                  //~v1.kR~
//            Bothdircnt-Samecntdir2);                             //~v1.kR~
//match                                                            //~v1.kI~
	  if (Sfilecompsw)                                             //~va1BI~
		psummline(Samecnt,Samecntdir,1,"Completely matched",0);    //~v1.vR~
      else                                                         //~va1BI~
		psummline(Samecnt,Samecntdir,1,"Completely matched(w/o file compare)",0);//~va1BR~
//trailer                                                          //~v1.mI~
		psummline(0,-1,0,0,0);	//header line                      //~v1.vR~
//size unmatch                                                     //~v1.kI~
		psummline(Ssizenecnt,Ssizenecntdir,1,"Size is not same",   //~v1.vR~
					1);		//err when unmatch for total           //~v1.vI~
    	if (Sfilecompsw)                                           //~va43R~
//  		psummline(Scontentsnecnt,0,1,"\"!\":file compare failed",//~va43R~
    		psummline(Scontentsnecnt,0,1,"\"!\":size is EQ, file compare failed",//~va43I~
					1);		//err when unmatch for total           //~va1BI~
    	if (Sfilecompsw & 2)                                       //~va43R~
			psummline(Ssizenetextcompokctr,0,1,"\"^\":size is not EQ but text file compare ok",//~va43R~
					0);		//err when unmatch for total           //~va43R~
//timestamp unmatch                                                //~v1.kI~
		psummline(Stsnecnt,Stsnecntdir,1,"Timestamp is not same",  //~v1.vR~
					4);		//err when unmatch for file            //~v1.vR~
		psummline(Sts2seccnt,Sts2seccntdir,1,"(Time difference<=2 seconds)",//~va69R~
					0);                                            //~va69I~
#ifdef UNX                                                         //~va62I~
//uid/gid   unmatch                                                //~va62I~
		psummline(Suidnecnt,Suidnecntdir,1,"uid/gid is not same",  //~va62I~
					4);		//err when unmatch for file            //~va62I~
#endif                                                             //~va62I~
//attr  unmatch                                                    //~v1.kI~
//    	psummline(Sfileanddircnt,Sfileanddircnt,0,"DIR attribute unmatch");//~v1.uR~
//  	psummline(Sattrnecnt,Sattrnecntdir,1,"Attribute except DIR is not same");//~v1.uR~
    	psummline(Sattrnecnt+Sfileanddircnt+Sdirandfilecnt,        //~v1.vR~
					Sattrnecntdir+Sfileanddircnt+Sdirandfilecnt,   //~v1.vI~
					1,"Attribute is not same",0);                  //~v1.vI~
    if (Sdir1dossw == Sdir2dossw)	//both is same dos or unix     //~v2.3I~
    {                                                              //~v2.3I~
      if (Sdir1dossw && Sdir2dossw)	//both dos type dir            //~v2.3I~
      {                                                            //~v2.3I~
//file and dir                                                     //~v1.kI~
//  	psummline(Sfileanddircnt,Sfileanddircnt,0,"DIR attribute is not same");//~v1.vR~
		psummline(SattrRnecnt,SattrRnecntdir,1,"  -READ ONLY",     //~v1.vR~
						4);	//err for file                         //~v1.vR~
		psummline(SattrHnecnt,SattrHnecntdir,1,"  -HIDDEN",        //~v1.vR~
					4);	//err for file                             //~v1.xR~
		psummline(SattrSnecnt,SattrSnecntdir,1,"  -SYSTEM",        //~v1.vR~
					4);	//err for file                             //~v1.xR~
		psummline(SattrAnecnt,SattrAnecntdir,1,"  -ARCHIV",0);     //~v1.vR~
#ifdef W32                                                         //~va71I~
		psummline(SattrSLINKnecnt,SattrSLINKnecntdir,1,"  -SLINK",0);//~va71I~
#endif                                                             //~va71I~
      }                                                            //~v2.3I~
#ifdef UNX                                                         //~v2.3I~
      else			//both unix                                    //~v2.3I~
      {                                                            //~v2.3I~
		psummline(SattrRWXnecnt,SattrRWXnecntdir,1,"  -RWXSGT",    //~v2.3I~
						4);	//err for file                         //~v2.3I~
		psummline(SattrSLINKnecnt,SattrSLINKnecntdir,1,"  -SLINK",0);//~va71I~
      }                                                            //~v2.3I~
#endif                                                             //~v2.3I~
    }                                                              //~v2.3I~
//    	psummline(Sfileanddircnt+Sdirandfilecnt,Sfileanddircnt+Sdirandfilecnt,0,"DIRECTORY attr unmatch",//~v1.vR~
//  				1);		//err when total not 0                 //~v1.vR~
      	psummline(Sfileanddircnt,Sdirandfilecnt,1,"  -DIRECTORY (dir1)",//~v1.vI~
					1);	//err for total                            //~v1.vM~
      	psummline(Sdirandfilecnt,Sfileanddircnt,1,"  -DIRECTORY (dir2)",//~v1.vI~
					1);	//err for total                            //~v1.vM~
//        printf("          dir1 only= %d, dir2 only= %d.",        //~v1.kR~
//            Dir1cnt,Dir2cnt);                                    //~v1.kR~
//trailer                                                          //~v1.mI~
		psummline(0,-1,0,0,0);	//header line                      //~v1.vR~
//dir1 only                                                        //~v1.kI~
//  	psummline(Dir1cnt,Dir1cntdir,1,"Only on dir1");            //~v1.uR~
    	psummline(Dir1cnt-Sfileanddircnt,Dir1cntdir-Sdirandfilecnt,1,"in dir1 only",//~v1.vR~
					1);	//err for total                            //~v1.vI~
//dir2 only                                                        //~v1.kI~
//  	psummline(Dir2cnt,Dir2cntdir,1,"Only on dir2");            //~v1.uR~
    	psummline(Dir2cnt-Sdirandfilecnt,Dir2cntdir-Sfileanddircnt,1,"in dir2 only",//~v1.vR~
					1);	//err for total                            //~v1.vI~
//trailer                                                          //~v1.kI~
		psummline(0,-1,0,0,0);	//header line                      //~v1.vR~
//        if (*Mask)                                               //~v1.kR~
//            printf(" (mask is %s",                               //~v1.kR~
//                Mask);                                           //~v1.kR~
//        else                                                     //~v1.kR~
//            printf(" (mask is *.*");                             //~v1.kR~
//        if (Sintfsw)        //output                             //~v1.kR~
//            printf(",through %s).\n",Sinterfnm);                 //~v1.kR~
//        else                                                     //~v1.kR~
//            printf(").\n");                                      //~v1.kR~
		if (Swarningsw)          //sever err                       //~v1.vR~
            Swarningsw=8;                                          //~v1.vI~
        else                    //no sever err                     //~v1.vI~
        	if (Samecnt   !=Tot1-Tot1dir || Samecnt   !=Tot2-Tot2dir//~v1.vR~
            ||  Samecntdir!=Tot1dir      || Samecntdir!=Tot2dir)   //~v1.vR~
            	Swarningsw=4;                                      //~v1.vI~
//      if (Sdbcssw)                                               //~va18R~
//      printf("%s:%s(%c):=%s=== ディレクトリー比較 ==== rc :% 2d =================\n",//~va18R~
//  			Spgm,Sver,OSTYPE,__DATE__,Swarningsw);             //~va18R~
//      else                                                       //~va18R~
//      printf("%s:%s(%c):=%s=== Directory Compare  ==== rc :% 2d =================\n",//~va18R~
//  			Spgm,Sver,OSTYPE,__DATE__,Swarningsw);             //~va18R~
        uerrmsg("=%s=== Directory Compare  ==== rc :% 2d =================",//~va18R~
                "=%s=== ディレクトリー比較 ==== rc :% 2d =================",//~va18R~
    			__DATE__,Swarningsw);                              //~va18R~
    }                                                              //~v1.9I~
//  return !(((Samecnt+Samecntdir)*2)==(Tot1+Tot2));               //~v1.vR~
    return Swarningsw;                                             //~v1.vI~
}//main                                                            //~v1.vR~
//**********************************************************************//~v1.kI~
//* summary line print                                             //~v1.kI~
//*  parm1:ctr1                                                    //~v1.kI~
//*  parm2:ctr2                                                    //~va69R~
//*  parm3:totalsw :1=add ctr1 and ctr2,0=total is ctr1            //~v1.kI~
//*  parm4:comment                                                 //~v1.kR~
//*  parm5:errsw set '*' if value!=0 for                           //~v1.vI~
//         x'04':file cnt,x'02':dir cnt,x'01',total cnt            //~v1.vI~
//*  return:none                                                   //~v1.kI~
//**********************************************************************//~v1.kI~
void psummline(int Pcnt1,int Pcnt2,int Ptotalsw,char *Pcomment,int Perrsw)//~v1.vR~
{                                                                  //~v1.kI~
static   char Ssummlinep[] =" |  %s %c|  %s %c|  %s %c| = %s\n";   //~v1.vR~
static   char Ssummlineh[] =" |  file(s)  |   dir(s)  |    total  |\n";//~v1.kR~
static   char Ssummlinet[] =" +-----------+-----------+-----------+\n";//~v1.kR~
    char cnteditwk1[8],cnteditwk2[8],cnteditwk3[8];                //~v1.kR~
    int total;                                                     //~v1.kI~
    char  errswf=' ',errswd=' ',errswt=' ';                        //~v1.vI~
//************                                                     //~v1.kI~
	if (Pcnt1==-1)                                                 //~v1.kI~
    {                                                              //~v1.kI~
//        printf(Ssummlinet);                                        //~v1.kI~//~va76R~
//        printf(Ssummlineh);                                        //~v1.kI~//~va76R~
//        printf(Ssummlinet);                                        //~v1.kI~//~va76R~
        printf("%s",Ssummlinet);                                   //~va76I~
        printf("%s",Ssummlineh);                                   //~va76I~
        printf("%s",Ssummlinet);                                   //~va76I~
	}                                                              //~v1.kI~
	else                                                           //~v1.kI~
	if (Pcnt2==-1)                                                 //~v1.kI~
//        printf(Ssummlinet);                                        //~v1.kI~//~va76R~
        printf("%s",Ssummlinet);                                   //~va76I~
	else                                                           //~v1.kI~
    {                                                              //~v1.kI~
    	unumedit((unsigned long)Pcnt1,Scnteditp,cnteditwk1);       //~v1.kR~
    	unumedit((unsigned long)Pcnt2,Scnteditp,cnteditwk2);       //~v1.kR~
        if (Ptotalsw)                                              //~v1.kI~
        	total=Pcnt1+Pcnt2;                                     //~v1.kR~
		else                                                       //~v1.kI~
        	total=Pcnt1;                                           //~v1.kR~
    	unumedit((unsigned long)total,Scnteditp,cnteditwk3);       //~v1.kI~
        if (Perrsw & '\x04')                                       //~v1.vI~
        	if (Pcnt1)                                             //~v1.vI~
            {                                                      //~v1.vI~
                Swarningsw=1;                                      //~v1.vI~
            	errswf='*';                                        //~v1.vI~
            }                                                      //~v1.vI~
        if (Perrsw & '\x02')                                       //~v1.vI~
        	if (Pcnt2)                                             //~v1.vI~
            {                                                      //~v1.vI~
                Swarningsw=1;                                      //~v1.vI~
            	errswd='*';                                        //~v1.vI~
            }                                                      //~v1.vI~
        if (Perrsw & '\x01')                                       //~v1.vI~
        	if (total)                                             //~v1.vI~
            {                                                      //~v1.vI~
                Swarningsw=1;                                      //~v1.vI~
            	errswt='*';                                        //~v1.vI~
            }                                                      //~v1.vI~
    	printf(Ssummlinep,cnteditwk1,errswf,cnteditwk2,errswd,cnteditwk3,errswt,Pcomment);//~v1.vR~
    }                                                              //~v1.kI~
    return;                                                        //~v1.kI~
}//psummline                                                       //~v1.kI~
//**********************************************************************
//* process 1 dir level
//*  parm1:dir1(must be dirname without last \)                    //~v1.9R~
//*  parm2:dir2(must be dirname without last \)                    //~v1.9R~
//*  parm3:mask
//*  parm4:file table for dir1
//*  parm5:file table for dir1
//*  return:none
//**********************************************************************
void  proc1level(char *Pdir1,char *Pdir2,char *Pmask,char *Pnocorresp)//~v1.8R~
{
	int rc;	
  	int  i,j;
//	int attr=FILE_ALL;                                             //~v1.dR~
	int pathlen1=0,pathlen2=0;                                     //~v1.9R~
	int entry1=0;
	int entry2=0;
	int entry1dir=0;                                               //~v1.kI~
	int entry2dir=0;                                               //~v1.kI~
	int direntry1,direntry2;                                       //~v1.dI~
//  HDIR hdir;  //dir handle  //v1.4r                              //~v1.dR~
//  HDIR hdir2;  //dir handle  v1.3a //v1.4r                       //~v1.dR~
//  HDIR hdir3;  //dir handle  v1.4a                               //~v1.dR~
//	FILEFINDBUF3 fstat;			//v1.3r                            //~v1.dR~
	char path1[MAXPATH];                                           //~v1.7R~
	char path2[MAXPATH];                                           //~v1.7R~
	char *dircom1,*dircom2,*dirn1,*dirn2;			//v1.4a     //~v1.5R~
	char *dirno1,*dirno2;                                          //~v1.8R~
//  long pos;                                                      //~v1.dR~
//  char *parentpath;                                              //~v1.dR~
	FNTBL *dirtbl1,*dirtbl2;                                       //~v1.dI~
	FNTBL *fnt1,*fnt2;                                             //~v1.dI~
    char numeditwk[16];                                            //~v1.fI~
#ifdef W32UNICODE                                                  //~va91I~
    char printwk[_MAX_PATH*2];                                     //~va91I~
#endif                                                             //~va91I~
//*******************************
//printf("proclevel1 %s %s\n",Pdir1,Pdir2);                        //~v254R~
	Slevel++;                                                      //~v1.cI~
    UTRACEP("proclevel1 level=%d,dir1=%s,dir2=%s\n",Slevel,Pdir1,Pdir2);//~va71R~
	Sdirsz[0][Slevel]=0;                                           //~v1.cR~
	Sdirsz[1][Slevel]=0;                                           //~v1.cR~
//  pos=Scurpos;                                                   //~v1.dR~
//  parentpath=Scurpath;	//parent path                          //~v1.dR~
	if (Pdir1)			//v1.3a
	{//v1.4a
        pathlen1=(int)strlen(Pdir1);                               //~v1.9R~
		memcpy(path1,Pdir1,(UINT)pathlen1);                        //~v1.9R~
        *(path1+pathlen1)=0;    //for PATHLEN                      //~v1.mI~
//      if (*(path1+pathlen1-1)!='\\')                             //~v1.hR~
//      if (xdcpathlen(path1)!=pathlen1)   //last is not \(sbcs)   //~v257R~
        if (!xdcchklastsepc(path1,pathlen1))   //last is not \(sbcs)//~v257R~
        {                                                          //~v1.dI~
//  		strcpy(path1+pathlen1,"\\");                           //~v2.3R~
    		xdcdirsepcat(path1);                                   //~v2.3R~
    	    pathlen1++;                                            //~v1.dR~
        }                                                          //~v1.dI~
        *(path1+pathlen1)=0;                                       //~v1.jI~
		stackfile(1,path1,Pmask,Tbl1,&entry1,&entry1dir);          //~v1.kR~
		dirn1=Pdir1;		//print hdr                         //~v1.5I~
		dirno1="";                                                 //~v1.8I~
	}//v1.4a
	else				//v1.3a
	{//v1.4a
		dirn1=Pnocorresp;	//print hdr                            //~v1.8R~
//  	dircom1="_____";	//v1.4a                                //~v1.8R~
		dirno1="  (--Not exist--)";	//v1.4a                        //~v1.8R~
	}//v1.4a
	dircom1="dir1=";	//v1.4a                                    //~v1.8I~
//	stackfile(Pathlen2,Pdir2,Pmask,Tbl2,&entry2);			//v1.2d

//v1.1add
	if (Pdir2)			//v1.3a
	{//v1.4a
        pathlen2=(int)strlen(Pdir2);                               //~v1.9R~
		memcpy(path2,Pdir2,(UINT)pathlen2);                        //~v1.9R~
        *(path2+pathlen2)=0;    //for PATHLEN                      //~v1.mI~
//      if (*(path2+pathlen2-1)!='\\')                             //~v1.hR~
//      if (xdcpathlen(path2)!=pathlen2)   //last is not \(sbcs)   //~v257R~
        if (!xdcchklastsepc(path2,pathlen2))   //last is not \(sbcs)//~v257R~
        {                                                          //~v1.dI~
//  		strcpy(path2+pathlen2,"\\");                           //~v2.3R~
    		xdcdirsepcat(path2);                                   //~v2.3R~
    	    pathlen2++;                                            //~v1.dR~
        }                                                          //~v1.dI~
        *(path2+pathlen2)=0;                                       //~v1.jR~
	  	stackfile(2,path2,Pmask,Tbl2,&entry2,&entry2dir);//v1.2a //v1.3r//~v1.kR~
		dirn2=Pdir2;		//print hdr                         //~v1.5I~
		dirno2="";                                                 //~v1.8I~
	}//v1.4a
	else				//v1.3a
	{//v1.4a
		dirn2=Pnocorresp;	//print hdr                            //~v1.8R~
//		dircom2="_____";	//v1.4a                                //~v1.8R~
		dirno2="  (--Not exist--)";                                //~v1.8R~
	}//v1.4a
	dircom2="dir2=";	//v1.4a                                    //~v1.8I~
	
	Tot1+=entry1;
	Tot2+=entry2;
	Tot1dir+=entry1dir;                                            //~v1.kI~
	Tot2dir+=entry2dir;                                            //~v1.kI~
//  Scomppathlen1=pathlen1;	//parm to compare function             //~v262R~
//  Scomppathlen2=pathlen1;	//parm to compare function             //~v262R~
//printf("qsort1,len=%d\n",pathlen1);                              //~v262R~
  	qsort(Tbl1,(UINT)entry1,ENTSZ,compare); //v1.4r
//  Scomppathlen1=pathlen2;	//parm to compare function             //~v262R~
//  Scomppathlen2=pathlen2;	//parm to compare function             //~v262R~
//printf("qsort2,len=%d\n",pathlen2);                              //~v262R~
  	qsort(Tbl2,(UINT)entry2,ENTSZ,compare);	//v1.4r

  	Tbl1[entry1].fnm[0]=0xff;	//high value		
  	Tbl2[entry2].fnm[0]=0xff;	//high value		
  if (Sintfsw!=3)		//output                                   //~v1.8R~
  {                                                                //~va9BI~
#ifdef W32UNICODE                                                  //~va91I~
	sprintf(printwk,"----------  %s%s%s",dircom1,dirn1,dirno1);    //~va91I~
    uprintfW("%s\n",printwk);                                      //~va91I~
	sprintf(printwk,"            %s%s%s",dircom2,dirn2,dirno2);	//v1.4r//~va91I~
    uprintfW("%s\n",printwk);                                      //~va91I~
#else                                                              //~va91I~
	printf("----------  %s%s%s\n            %s%s%s\n",             //~v1.8R~
			dircom1,dirn1,dirno1,dircom2,dirn2,dirno2);	//v1.4r    //~v1.8R~
#endif                                                             //~va91I~
  }                                                                //~va9BI~
  	i=j=0;
//  Scomppathlen1=pathlen1;	//parm to compare function             //~v262R~
//  Scomppathlen2=pathlen2;	//parm to compare function             //~v262R~
    Sfilecomppath1=path1;   //parm to lineprint for filecompare    //~va1BI~
    Sfilecomppath2=path2;                                          //~va1BI~
  	while (i<entry1 || j<entry2)
  	{
//    	rc=memcmp(Tbl1[i].fnm,Tbl2[j].fnm,MAXFNSZ);                //~v1.eR~
    	rc=compare((void*)&Tbl1[i],(void*)&Tbl2[j]);               //~v1.eR~
//printf("compare rc=%d,f1=%s,f2=%s\n",rc,Tbl1[i].fnm,Tbl2[j].fnm);//@@@@@//~v262R~
    	if (rc==0)	//same file
		{
            Samenamecnt++;                                         //~v1.gI~
//			Samecnt+=lineprint(Tbl1+i,Tbl2+j);                     //~v1.hI~
			rc=lineprint(Tbl1+i,Tbl2+j);                           //~v1.hR~
//          if (rc<0)   //both directory, -1:match -2:unmatch      //~v1.kR~
//          {                                                      //~v1.kR~
//          	Bothdircnt++;                                      //~v1.kR~
//  		}                                                      //~v1.kR~
//  		else        //file                                     //~v1.kR~
//          	Samecnt+=rc;                                       //~v1.kR~
			i++;
			j++;
		}
		else
	    	if (rc<0)	//dir1 entry <dir2 entry
			{
				if (!Dir2sw)			 //not print dir2 member only v1.3a
                {                                                  //~v1.hI~
                    if (Sintfsw==3)		//output                   //~v1.8R~
                    	wtintf(path1,Tbl1+i);                      //~v1.9R~
                    else                                           //~v1.8I~
					lineprint(Tbl1+i,0); //dir1 only
                  if ((Tbl1+i)->fattr & FILE_DIRECTORY)            //~v1.kR~
                    Dir1cntdir++;	//dir on dir1 only             //~v1.kI~
                  else                                             //~v1.kI~
                    Dir1cnt++;                                     //~v1.hI~
				}                                                  //~v1.hI~
				i++;
			}
	    	else 		//dir1 entry <dir2 entry
			{
				if (!Dir1sw)			 //not print dir1 member only v1.3a
                {                                                  //~v1.hI~
                    if (Sintfsw==3)		//output                   //~v1.8R~
//                  	wtintf(path2,Tbl2+i);                      //~v23bR~
                    	wtintf(path2,Tbl2+j);                      //~v23bI~
                    else                                           //~v1.8I~
					lineprint(0,Tbl2+j); //dir2 only
                  if ((Tbl2+j)->fattr & FILE_DIRECTORY)            //~v1.kR~
                    Dir2cntdir++;	//dir on dir2 only             //~v1.kI~
                  else                                             //~v1.kI~
                    Dir2cnt++;                                     //~v1.hI~
				}                                                  //~v1.hI~
				j++;
			}
  	}//all entry
    Stoplevelsw=0;      //subdir srch                              //~v259I~
//*sub directory search 
	if (Subdirsw && *Mask)	//mask specified for subdir search case//~va1BI~
    {                                                              //~va1BI~
//Tbl1/Tbl2 is reused                                              //~va1BI~
    	if (Pdir1)                                                 //~va1BI~
			stackfile(1,path1,"",Tbl1,&entry1,0);	//nomask,0:subdir get id//~va1BR~
        else                                                       //~va1BI~
        	entry1=0;                                              //~va1BI~
    	if (Pdir2)                                                 //~va1BI~
			stackfile(2,path2,"",Tbl2,&entry2,0);	//nomask,0:subdir get id//~va1BR~
        else                                                       //~va1BI~
        	entry2=0;                                              //~va1BI~
    }                                                              //~va1BI~
	dirtbl1=getdirtbl(Tbl1,entry1,&direntry1);                     //~v1.dI~
	dirtbl2=getdirtbl(Tbl2,entry2,&direntry2);                     //~v1.dI~
	if (Subdirsw && dirtbl1)                                       //~v1.dR~
	{
//  	strcat(path1,"*.*");                                       //~v2.3R~
    	strcat(path1,DIR_ALLMEMB);                                 //~v2.3I~
//   	rc=findfile(1,path1,attr,&fstat,&hdir);                    //~v1.dR~
//      Scurpath=path1;                                            //~v1.dR~
	  	for (i=0,fnt1=dirtbl1;i<direntry1;i++,fnt1++)              //~v1.dR~
		{
//            if (Sswxmask)                                          //~va9gI~//~va9DR~
//            {                                                      //~va9gI~//~va9DR~
//                if (chkMask(CMO_NOEXPAND,&Sqhxmask,fnt1->fnm))     //~va9gR~//~va9DR~
//                {                                                  //~va9AI~//~va9DR~
//                    printf("@@@3 dir1 exclude %s\n",fnt1->fnm);    //~va9AI~//~va9DR~
//                    continue;                                      //~va9gR~//~va9DR~
//                }                                                  //~va9AI~//~va9DR~
//            }                                                      //~va9gI~//~va9DR~
//  		if (  strcmp(fstat.achName,".")                        //~v1.dR~
//  		   && strcmp(fstat.achName,".."))                      //~v1.dR~
//  		{                                                      //~v1.dR~
//  			if (fstat.attrFile & FILE_DIRECTORY) //sub dir //v1.4r//~v1.dR~
//  			{                                                  //~v1.dR~
					strcpy(path1+pathlen1,fnt1->fnm);              //~v1.dR~
                    if (Pdir2)                                     //~v1.dR~
						strcpy(path2+pathlen2,fnt1->fnm);          //~v1.dR~
				 	if (dirtbl2                                    //~v1.dR~
//  				&&  !findfile(2,path2,attr,&fstat2,&hdir2) //dir2 exist v1.3a//~v1.dR~
//  				&& (fstat2.attrFile & FILE_DIRECTORY)) //sub dir v1.3a //v1.4r//~v1.dR~
                    &&  srchdirtbl(dirtbl2,direntry2,fnt1->fnm)) //dir2 exist v1.3a//~v1.dI~
	    	        	proc1level(path1,path2,Pmask,0);           //~v1.8R~
					else									//dir1 only	v1.3a 
						if (!Dir2sw)			 //not print dir2 member only vv1.3a
                        {                                          //~va17I~
                        	if (Pdir2)                             //~v1.8I~
		    		        	proc1level(path1,0,Pmask,path2);	//v1.3a//~v1.8R~
                            else                                   //~v1.8I~
		    		        	proc1level(path1,0,Pmask,Pnocorresp);	//v1.3a//~v1.8R~
                        }                                          //~va17I~
//  			}                                                  //~v1.dR~
//  		}                                                      //~v1.dR~
//   		rc=findfile(1,0,attr,&fstat,&hdir);                    //~v1.dR~
    	}                                                          //~v1.dR~
    }//sub dir sw
//*****by dir2 v1.3a start
	if (Subdirsw && dirtbl2)                                       //~v1.dR~
	{
//  	strcat(path2,"*.*");                                       //~v2.3R~
    	strcat(path2,DIR_ALLMEMB);                                 //~v2.3I~
//	 	rc=findfile(2,path2,attr,&fstat,&hdir3);                   //~v1.dR~
//      Scurpath=path2;                                            //~v1.dR~
	  	for (i=0,fnt2=dirtbl2;i<direntry2;i++,fnt2++)              //~v1.dI~
		{
//            if (Sswxmask)                                          //~va9gI~//~va9DR~
//            {                                                      //~va9gI~//~va9DR~
//                if (chkMask(CMO_NOEXPAND,&Sqhxmask,fnt2->fnm))     //~va9gR~//~va9DR~
//                {                                                  //~va9AI~//~va9DR~
//                    printf("@@@4 dir2 exclude %s\n",fnt2->fnm);    //~va9AI~//~va9DR~
//                    continue;                                      //~va9gR~//~va9DR~
//                }                                                  //~va9AI~//~va9DR~
//            }                                                      //~va9gI~//~va9DR~
//			if (  strcmp(fstat.achName,".")                        //~v1.dR~
//			   && strcmp(fstat.achName,".."))                      //~v1.dR~
//			{                                                      //~v1.dR~
//    			if (fstat.attrFile & FILE_DIRECTORY) //sub dir //v1.4r//~v1.dR~
//    			{                                                  //~v1.dR~
                	if (Pdir1)                                  //~v1.5I~
						strcpy(path1+pathlen1,fnt2->fnm);          //~v1.dR~
					strcpy(path2+pathlen2,fnt2->fnm);              //~v1.dR~
				 	if (!dirtbl1                                   //~v1.dR~
//  				||  findfile(1,path1,attr,&fstat2,&hdir2) //dir1 not exist//~v1.dR~
//  				|| !(fstat2.attrFile & FILE_DIRECTORY)) //not sub dir //v1.4r//~v1.dR~
                    || !srchdirtbl(dirtbl1,direntry1,fnt2->fnm)) //dir2 exist v1.3a//~v1.dI~
						if (!Dir1sw)			 //not print dir2 member only
                        {                                          //~va17I~
                        	if (Pdir1)                             //~v1.8I~
		    		        	proc1level(0,path2,Pmask,path1);   //~v1.8R~
                            else                                   //~v1.8I~
		    		        	proc1level(0,path2,Pmask,Pnocorresp);//~v1.8I~
                        }                                          //~va17I~
//    			}                                                  //~v1.dR~
//			}                                                      //~v1.dR~
//	 		rc=findfile(2,0,attr,&fstat,&hdir3);                   //~v1.dR~
		}
    }//sub dir sw
    if (dirtbl1)                                                   //~v1.dI~
	    free(dirtbl1);                                             //~v1.dI~
    if (dirtbl2)                                                   //~v1.dI~
    	free(dirtbl2);                                             //~v1.dI~
//*****by dir2 v1.3a end
	if (Sintfsw!=3)		//not intermediate file output             //~v1.cI~
    {                                                              //~v1.cI~
		if (Pdir1)                                                 //~v1.cI~
        {                                                          //~v1.fI~
//      	unumedit((unsigned long)Sdirsz[0][Slevel],"z,zzz,zzz,zz9",numeditwk);//~va30R~
        	ufileeditsz(0,Sdirsz[0][Slevel],numeditwk);            //~va30R~
#ifdef W32UNICODE                                                  //~va91I~
			sprintf(printwk,"            (1)=%s byte use (%s)",numeditwk,dirn1);//~va91I~
   			uprintfW("%s\n",printwk);                              //~va91I~
#else                                                              //~va91I~
			printf("            (1)=%s byte use (%s)\n",           //~v1.fR~
					numeditwk,dirn1);                              //~v1.fR~
#endif                                                             //~va91I~
		}                                                          //~v1.fI~
		if (Pdir2)                                                 //~v1.cI~
        {                                                          //~v1.fI~
//      	unumedit((unsigned long)Sdirsz[1][Slevel],"z,zzz,zzz,zz9",numeditwk);//~va30R~
        	ufileeditsz(0,Sdirsz[1][Slevel],numeditwk);            //~va30R~
#ifdef W32UNICODE                                                  //~va91I~
			sprintf(printwk,"            (2)=%s byte use (%s)",numeditwk,dirn2);//~va91I~
   			uprintfW("%s\n",printwk);                              //~va91I~
#else                                                              //~va91I~
			printf("            (2)=%s byte use (%s)\n",           //~v1.fR~
					numeditwk,dirn2);                              //~v1.fR~
#endif                                                             //~va91I~
		}                                                          //~v1.fI~
	}                                                              //~v1.cI~
	Sdirsz[0][Slevel-1]+=Sdirsz[0][Slevel];                        //~v1.cR~
	Sdirsz[1][Slevel-1]+=Sdirsz[1][Slevel];                        //~v1.cR~
	Slevel--;                                                      //~v1.cI~
//  Snextpos=pos;	//entry pos;                                   //~v1.dR~
//  Scurpath=parentpath;	//parent path recovry                  //~v1.dR~
    return;                                                        //~v1.cI~
}//proc1level	                                                   //~va91R~
//**********************************************************************//~v1.dI~
//* create tbl for subdir member only                              //~v1.dI~
//*  parm1:all member tbl                                          //~v1.dI~
//*  parm2:member count                                            //~v1.dI~
//*  parm3:dir count output                                        //~v1.dI~
//*  return:malloced FNTBL for dir                                 //~v1.dI~
//**********************************************************************//~v1.dI~
FNTBL *getdirtbl(FNTBL *Pfntbl,int Pentry,int *Pdirentry)          //~v1.dI~
{                                                                  //~v1.dI~
  	int  ii,jj;                                                    //~v1.dI~
	FNTBL *fnt,*fnt0,*fnt2;                                        //~v1.dI~
//*******************************                                  //~v1.dI~
  	for (ii=jj=0,fnt=Pfntbl;ii<Pentry;ii++,fnt++)                  //~v1.dR~
		if (strcmp(fnt->fnm,".")                                   //~v1.dI~
		&&  strcmp(fnt->fnm,".."))                                 //~v1.dI~
			if (fnt->fattr & FILE_DIRECTORY) //sub dir             //~v1.dI~
            {                                                      //~va17I~
//#ifdef UNX                                                       //~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
              if(fnt->fattr & FNT_SLINKLOOP)                       //~v256R~
              	continue;                                          //~v256I~
              else                                                 //~v256I~
              if (!Sslinkchksw   //slink skip option               //~v256R~
//            &&  S_ISLNK(FILE_GETMODE(fnt->fattr)))               //~va71R~
              &&  FILE_ISSLINK(fnt->fattr))                        //~va71I~
              	continue;                                          //~v256I~
              else                                                 //~v256I~
#endif                                                             //~v256I~
    	    	jj++;		//dir count                            //~v1.dI~
            }                                                      //~va17I~
	if (!(*Pdirentry=jj))                                          //~v1.dI~
    	return 0;	//no subdir                                    //~v1.dI~
//  if (!(fnt0=malloc((UINT)(ENTSZ*jj))))                          //~v1.dR~//~vaa0R~
    if (!(fnt0=malloc((ENTSZ*(size_t)jj))))                        //~vaa0I~
    {                                                              //~v1.dI~
		printf("\n%s:%s:storage shortage(req size=%d).\n",         //~v1.dI~
//  			Spgm,Sver,(int)(ENTSZ*jj));                        //~v1.mR~//~vaa0R~
    			Spgm,Sver,((int)ENTSZ*jj));                        //~vaa0I~
		exit(4);                                                   //~v1.dI~
    }                                                              //~v1.dI~
  	for (ii=0,fnt=Pfntbl,fnt2=fnt0;ii<Pentry;ii++,fnt++)           //~v1.dR~
	  if (strcmp(fnt->fnm,".")                                     //~v256I~
	  &&  strcmp(fnt->fnm,".."))                                   //~v256I~
		if (fnt->fattr & FILE_DIRECTORY) //sub dir                 //~v1.dI~
        {                                                          //~v1.dI~
        UTRACEP("getdirtbl attr=%x,name=%s\n",fnt->fattr,fnt->fnm);//~va71I~
//#ifdef UNX                                                       //~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
          if(fnt->fattr & FNT_SLINKLOOP) //slink loop              //~v256R~
            continue;                                              //~v256I~
          else                                                     //~v256I~
          if (!Sslinkchksw   //slink skip option                   //~v256I~
//        &&  S_ISLNK(FILE_GETMODE(fnt->fattr)))                   //~va71R~
          &&  FILE_ISSLINK(fnt->fattr))                            //~va71I~
            continue;                                              //~v256I~
          else                                                     //~v256I~
#endif                                                             //~v256I~
        	memcpy(fnt2,fnt,ENTSZ);                                //~v1.dI~
            *(fnt2->fnm+strlen(fnt2->fnm)-1)=0;	//drop last '\\'   //~v1.dI~
            fnt2++;                                                //~v1.dI~
		}                                                          //~v1.dI~
    return fnt0;                                                   //~v1.dI~
}//getdirtbl                                                       //~v1.dI~
//**********************************************************************//~v1.dI~
//* search subdir member                                           //~v1.dI~
//*  parm1:dir member tbl                                          //~v1.dI~
//*  parm2:path name                                               //~v1.dI~
//*  parm3:dir count output                                        //~v1.dI~
//*  return:found entry addr                                       //~v1.dR~
//**********************************************************************//~v1.dI~
FNTBL *srchdirtbl(FNTBL *Pfntbl,int Pentry,char *Pfilenm)          //~v1.dR~
{                                                                  //~v1.dI~
  	int  ii;                                                       //~v1.dI~
  	UINT ulen;                                                     //~v23aR~
	FNTBL *fnt;                                                    //~v1.dI~
//*******************************                                  //~v1.dI~
//  ulen=strlen(Pfilenm);                                          //~v23aR~//~vaa1R~
    ulen=(UINT)strlen(Pfilenm);                                    //~vaa1I~
  	for (ii=0,fnt=Pfntbl;ii<Pentry;ii++,fnt++)                     //~v1.dR~
//  	if (!stricmp(fnt->fnm,Pfilenm))                            //~v23aR~
		if (strlen(fnt->fnm)==ulen                                 //~v23aI~
		&&  !xdcfnmcmp(fnt->fnm,Pfilenm,ulen))                     //~v23aI~
    		return fnt;                                            //~v1.dR~
	return 0;                                                      //~v1.dI~
}//srchdirtbl                                                      //~v1.dI~
                                                                   //~v1.dI~
//**********************************************************************
//* search file
//*  parm1 :dir1 or dir2                                           //~v1.8R~
//*  parm2 :recursive flag(1:top dir ,0:sub dir)                   //~v1.8I~
//*  parm3 :directory name                                         //~v1.8R~
//*  parm4 :file name mask                                         //~v1.8R~
//*  parm5 :file name table pointer                                //~v1.8R~
//*  parm6 :current entry no                                       //~v1.8R~
//*  return:none                                                   //~v1.9R~
//**********************************************************************
void stackfile(int Pdirid,char *Pdir,char *Pmask,FNTBL *Pfnt,int *Pentno,int *Pentnodir)//~v1.kR~
{
	char path[MAXPATH];                                            //~v1.7R~
//	char fname[MAXFNSZ+1];                                         //~v1.7R~
    char *fnm;                                                     //~va1AI~
	FILEFINDBUF3 fstat;
	FNTBL *fnt;
	int attr;
	int rc;
    HDIR hdir;  //dir handle  //v1.4r
//  long totsz=0;                                                  //~va30R~
    FILESZT totsz=0;                                               //~va30I~
    int entnodir=0;                                                //~v1.kR~
    int swskip;                                                    //~va9AI~
//********************
//printf("stackfile dirid=%d,dir=%s\n",Pdirid,Pdir);               //~v254R~
	strcpy(path,Pdir);
    UTRACEP("level=%d,dir=%s\n",Slevel,path);                      //~va71I~
	if (Slevel==1)                                                 //~va71I~
    	Sstartdir=path;	//for slink loopchk                        //~va71I~
	*Pentno=0;
#ifdef UNX                                                         //~v251I~
   	attr=FILE_ALLSP;                                               //~v251I~
#else                                                              //~v251I~
   	attr=FILE_ALL;                                              //~v1.5R~
#endif                                                             //~v251I~
//  attr=FILE_READONLY | FILE_HIDDEN | FILE_SYSTEM | FILE_DIRECTORY;//~v1.9R~
//	strcat(path,"\\");                                             //~v1.dR~
//  if (*Pmask)                                                    //~v1.9R~//~va9AR~
//  {                                                              //~v1.9R~//~va9AR~
//  	strcat(path,Pmask);                                        //~v1.9R~//~va9AR~
//  }                                                              //~v1.9R~//~va9AR~
//  else                                                           //~v1.9R~//~va9AR~
//  	strcat(path,"*.*");                                        //~v2.3R~
    	strcat(path,DIR_ALLMEMB);                                  //~v2.3I~
//  Scurpath=path;                                                 //~v1.dR~
//  Snextpos=0;     //normal findnext(no seek)                     //~v1.dR~

//*file search
// 	attr&=~FILE_DIRECTORY;	//v1.1del also dirname compare
 	rc=findfile(Pdirid,path,attr,&fstat,&hdir,*Pmask!=0);          //~v238R~
//printf("stack file findfile rc=%d:dirid=%d,Dir=%s\n",rc,Pdirid,path);//@@@@//~v254R~
    if (rc)                                                        //~va1BI~
		if (Slevel==1)                                             //~va1BI~
        {                                                          //~va1BI~
          if (Pdirid==Sintfsw || Sinterfnm2)    //intermediate file input//~va1BI~
        	printf("%s is not found in intermediate file\n",path); //~va1BR~
//          exit(4);                                               //~va1BR~
        }                                                          //~va1BI~
                                                                   //~v1.mI~
  	while(!rc)
	{
//  	if (fstat.achName[0]!='.')	//not path dir > or .. v1.1add //~v1.qR~
//  	if (strcmp(fstat.achName,".")	//not path dir > or .. v1.1add//~va1AR~
//  	&&  strcmp(fstat.achName,".."))	//not path dir > or .. v1.1add//~va1AR~
#if defined(W32) || defined(DPMI)                                  //~va1AI~
        if (Slfnsw)                                                //~va1AI~
            fnm=fstat.cFileName;                                   //~va1AI~
        else                                                       //~va1AI~
            fnm=fstat.achName;                                     //~va1AI~
#else                                                              //~va1AI~
        fnm=fstat.achName;                                         //~va1AI~
#endif                                                             //~va1AI~
    	if (strcmp(fnm,".")	//not path dir > or .. v1.1add         //~va1AI~
        && (Pentnodir||(fstat.attrFile & FILE_DIRECTORY))//serch by mask or search subdir & dir//~va1BI~
    	&&  strcmp(fnm,".."))	//not path dir > or .. v1.1add     //~va1AI~
		{							//v1.1add
			if (*Pentno==(maxent-1))                               //~v1.8R~
		  	{
        		printf("%s:%s:Dir %s has too many files(Max is %d),\n\
expand work area by /W(current is %d)\n",Spgm,Sver,path,maxent,tblsz);//~v1.9R~
        		exit (4);
			}
			fnt=Pfnt+*Pentno;
//#ifdef UNX                                                       //~v256R~
//          if (!*fstat.slink                                      //~v256R~
//          ||  !ufileslinkchk(Pdir,fstat.achName,fstat.slink))    //~v256R~
//          {                                                      //~v256R~
//#endif                                                           //~v256R~
//  		strcpy(fname,Pdir);                                    //~v1.7R~
//  		strcat(fname,"\\");                                    //~v1.7R~
//  		strcat(fname,fstat.achName);                           //~v1.7R~
   			memset(fnt->fnm,0,sizeof(fnt->fnm));	               //~v1.6R~
//			strcpy(fnt->fnm,fname+Ptoplen+1);//drop top dir name   //~v1.7R~
#if defined(W32) || defined(DPMI)                                  //~v1.mI~
			if (Slfnsw)                                            //~v1.mI~
  				strncpy(fnt->fnm,fstat.cFileName,MAXFNSZ);//lfn    //~v1.mR~
            else                                                   //~v1.mI~
  				strncpy(fnt->fnm,fstat.achName,MAXFNSZ);    //filename only//~v1.mI~
#else                                                              //~v1.mI~
  			strncpy(fnt->fnm,fstat.achName,MAXFNSZ);    //filename only//~v1.7R~
#endif                                                             //~v1.mI~
//printf("@@@0 stackfile %s\n",fnt->fnm);                               //~v254R~//~va9AR~//~va9DR~
            swskip=0;                                              //~va9AI~
            if (Sswxmask)                                          //~va9DI~
            {                                                      //~va9DI~
                if (chkMask(0,&Sqhxmask,fnt->fnm))                 //~va9DI~
                {                                                  //~va9DI~
//                    printf("@@@3 stackfile exclude %s\n",fnt->fnm);//~va9DR~
                    swskip=1;                                      //~va9DI~
                }                                                  //~va9DI~
            }                                                      //~va9DI~
          if (!swskip)                                             //~va9DI~
          {                                                        //~va9DI~
			if (fstat.attrFile & FILE_DIRECTORY) //v1.1add //v1.4r
            {                                                      //~v1.kI~
//  			strcat(fnt->fnm,"\\");         //v1.1add           //~v2.3R~
    			xdcdirsepcat(fnt->fnm);         //v1.1add          //~v2.3R~
                entnodir++;                                        //~v1.kI~
			}                                                      //~v1.kI~
            else    //file entry                                   //~va9AI~
            {                                                      //~va9AI~
                if (Sswimask)                                        //~va9AI~//~va9DR~
                {                                                  //~va9AI~
                    if (!chkMask(0/*file only*/,&Sqhimask,fnt->fnm))//~va9AI~
                    {                                              //~va9AI~
//                        printf("@@@1 stackfile include NG %s\n",fnt->fnm);//~va9AI~//~va9DR~
                        swskip=1;                                  //~va9AI~
                    }                                              //~va9AI~
//                    else                                           //~va9AI~//~va9DR~
//                        printf("@@@2 stackfile include OK %s\n",fnt->fnm);//~va9AI~//~va9DR~
                }                                                  //~va9AI~
            }                                                      //~va9AI~
          }//!skip by exclude mask                                 //~va9DI~
          if (!swskip)                                             //~va9AM~
          {                                                        //~va9AM~
			fnt->fsz=fstat.cbFile;
			fnt->ftm=fstat.ftimeLastWrite;
			fnt->fdt=fstat.fdateLastWrite;
//#ifdef UNX                                                       //~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
			fnt->fattr=fstat.attrFile;                             //~v2.3I~
            fnt->slink=0;                                          //~va71I~
            if (Pdirid==Sintfsw || Sinterfnm2)    //intermediate file input//~v256I~
                ;                                                  //~v256I~
            else                                                   //~v256I~
                if (*fstat.slink)                                  //~v256I~
                {                                                  //~va71I~
//				    if (ufileslinkchk(Pdir,fstat.achName,fstat.slink))	//loop//~va71R~
  				    if (ufileslinkloopchk2(0/*opt*/,Sstartdir,Pdir,fstat.achName,fstat.slink))	//loop//~va71R~
                	    fnt->fattr |= FNT_SLINKLOOP;               //~v256I~
                    fnt->slink=malloc(strlen(fstat.slink)+1);      //~va71R~
                    strcpy(fnt->slink,fstat.slink);                //~va71R~
                }                                                  //~va71I~
	#if defined(W32)                                               //~va71M~
            fnt->uid=0;                                            //~va71I~
            fnt->gid=0;                                            //~va71I~
            fnt->sec1=ftime2sec(&fstat.ftLastWriteTime,0);         //~va71M~
    #else                                                          //~va71M~
            fnt->uid=fstat.uid;                                    //~va62I~
            fnt->gid=fstat.gid;                                    //~va62I~
            fnt->sec1=fstat.mtime & 1;  //odd sec                  //~va6cI~
    #endif                                                         //~va71I~
#else                                                              //~v2.3I~
			fnt->fattr=(char)fstat.attrFile;                       //~v1.9R~
            fnt->uid=0;                                            //~va62I~
            fnt->gid=0;                                            //~va62I~
            fnt->sec1=ftime2sec(&fstat.ftLastWriteTime,0);         //~va6cR~
#endif                                                             //~v2.3I~
		  if (Pentnodir)                                           //~va1BI~
//  		totsz+=(long int)fnt->fsz;	//displayed file size total//~va30R~
    		totsz+=fnt->fsz;	//displayed file size total        //~va30I~
			(*Pentno)++;
//#ifdef UNX                                                       //~v256R~
//          }//no slink loop                                       //~v256R~
//#endif                                                           //~v256R~
          }//!swskip                                               //~va9AI~
		}//v1.1add
        Sfindfirstdir=Pdir;                                        //~va70R~
     	rc=findfile(Pdirid,0,attr,&fstat,&hdir,*Pmask!=0);//next search
    }
	Sdirsz[Pdirid-1][Slevel]=totsz;        	//displayed file size total//~v1.cI~
  if (Pentnodir)                                                   //~va1BI~
    *Pentnodir=entnodir;                                           //~v1.kR~
	return;                                                        //~v1.9R~
}//stackfile
//**********************************************************************
//*find file under file mask
//*  parm1:dir1 or dir2                                            //~v1.8R~
//*  parm2:dirname(find first) or 0(find next)                     //~v1.8I~
//*  parm3:search file attribute                                   //~v1.8R~
//*  parm4:output file status                                      //~v1.8R~
//*  parm5:dir handle for os/2                                     //~v1.8R~
//*  return code: 0- normal
//*               4- not found(find first)
//*              -1- no more file(find next)
//**********************************************************************
//int findfile(int Pdirid,char *Pfile,int Pattr,FILEFINDBUF3 *Pfstat,ULONG *Phdir)//~v1.mR~
//int findfile(int Pdirid,char *Pfile,int Pattr,FILEFINDBUF3 *Pfstat,HDIR *Phdir,int Pmasksw)//~v238R~//~va9DR~
int findfile(int Pdirid,char *Pfile,int Pattr,FILEFINDBUF3 *Pfstat,HDIR *Phdir,int Popt)//~va9DI~
{
  int rc;
//*********************************
//  if (Pdirid==Sintfsw)    //intermediate file input              //~v234R~
    if (Pdirid==Sintfsw || Sinterfnm2)    //intermediate file input//~v234I~
    {                                                              //~v234I~
    	if (Sinterfnm2)    //intermediate file input               //~v234I~
        {                                                          //~va17I~
        	if (Pdirid==1)                                         //~v234I~
            	Sinterfnm=Sinterfnm1;                              //~v234I~
            else                                                   //~v234I~
            	Sinterfnm=Sinterfnm2;                              //~v234I~
        }                                                          //~va17I~
//printf("intf=%s\n",Sinterfnm);                                   //~v254R~
		Shfile=Shfiletbl[Pdirid];                                  //~v254I~
    	Sposafterhdr=Sposafterhdrtbl[Pdirid];                      //~v258R~
    	Spostbltop=Spostbl[Pdirid];                                //~v258R~
#ifdef LFSSUPP                                                     //~va30I~
	    Slfsintf[0]=Slfsintf[Pdirid];	//parm to rdintf           //~va30I~
#endif                                                             //~va30I~
//      return rdintf(Pmasksw,Pfile,Pfstat);                       //~v257R~//~va9DR~
        return rdintf(Popt,Pfile,Pfstat);                          //~va9DI~
    }                                                              //~v234I~
                                                                   //~v1.8I~
//	printf("%s;atrrib=%X\n",Pfstat->achName,Pfstat->attrib); //v1.2
    if (Pfile)                          //first time               //~v1.mI~
    {                                                              //~v1.mI~
	  if (Stoplevelsw)                                             //~v259I~
      	rc=(int)udosfindfirst(Pfile,Phdir,(UINT)Pattr,Pfstat);     //~v1.mR~
      else                                                         //~v259I~
      	rc=(int)udosfindfirstnomsg(Pfile,Phdir,(UINT)Pattr,Pfstat);//~v259I~
      	if(rc)                                                     //~v1.mI~
            return 4;                                              //~v1.mI~
    }                                                              //~v1.mI~
    else //request next file                                       //~v1.mI~
    {                                                              //~v1.mI~
//    	rc=(int)udosfindnext(*Phdir,Pfstat);                       //~v1.mR~//~va70R~
//    	rc=(int)udosfindnext(Pfile,*Phdir,Pfstat);                 //~va70R~
      	rc=(int)udosfindnext(Sfindfirstdir,*Phdir,Pfstat);         //~va70R~
      	if (rc)                                                    //~v1.mI~
      	{                                                          //~v1.mI~
          	if (rc==4)                                             //~v1.mI~
              	return -1;  //no more file                         //~v1.mI~
			printf("%s:%s:udosfindnext failed,rc=%d\n",Spgm,Sver,rc);//~v1.mR~
          	exit (4);                                              //~v1.mI~
      	}                                                          //~v1.mI~
  	}//next req                                                    //~v1.mI~
	return 0;
}//findfile
//**********************************************************************//~va9DI~
//*rc=1 when noy in include or in exclude spec                     //~va9DI~
//**********************************************************************//~va9DI~
int skipRecord(int Popt,PINTMTBL Prec,int Ppos)                    //~va9DI~
{                                                                  //~va9DI~
	int rc=0;                                                      //~va9DI~
//****************                                                 //~va9DI~
//    printf("@@@5 skipRecord fnm=%s\n",Prec->fnm+Ppos);           //~va9DR~
	if (Sswxmask)                                                  //~va9DI~
    {                                                              //~va9DI~
    	rc=chkMask(0/*file only*/,&Sqhxmask,Prec->fnm+Ppos)!=0; //match->skip//~va9DI~
//        printf("@@@5 skipRecord exclude skiprc=%d\n",rc);        //~va9DR~
	}                                                              //~va9DI~
	if (!rc && Sswimask)                                           //~va9DI~
    {                                                              //~va9DM~
    	if (!(Prec->fattr & FILE_DIRECTORY))                       //~va9DM~
        {                                                          //~va9DM~
    		rc=chkMask(0/*file only*/,&Sqhimask,Prec->fnm+Ppos)==0; //unmatch->skip//~va9DM~
//            printf("@@@5 skipRecord include non dir skiprc=%d\n",rc);//~va9DR~
		}                                                          //~va9DM~
	}                                                              //~va9DM~
    return rc;                                                     //~va9DI~
}//skipRecord                                                      //~va9DI~
//**********************************************************************//~v1.8I~
//*read intermediate file                                          //~v1.8I~
//*  parm1:mask parm specified sw                                  //~v238I~
//*  parm2:dir name                                                //~v238R~
//*  parm3:output filefindbuf3                                     //~v238R~
//*  return code: 0- normal                                        //~v1.8I~
//*               4- not found(find first)                         //~v1.8I~
//*              -1- no more file(find next)                       //~v1.8I~
//**********************************************************************//~v1.8I~
//int rdintf(int Pmasksw,char *Pfile,FILEFINDBUF3 *Pfstat)           //~v238R~//~va9DR~
int rdintf(int Popt,char *Pfile,FILEFINDBUF3 *Pfstat)              //~va9DI~
{                                                                  //~v1.8I~
    INTMTBL rec;                                                   //~v1.8I~
    int 	wildcardsw,fullpathlen;                                //~v1.9R~
    int     cmp;                                                   //~v1.dR~
    static char  Scurpath[_MAX_PATH];                              //~v238R~
    static int   Spathlen;                                         //~v1.dR~
    int    fnmlen,pathlen;                                         //~v238I~
    ULONG  seekpos=0;                                                //~v258I~//~va64R~
    PPOSTB ppost;                                                  //~v258I~
#ifdef LFSSUPP                                                     //~va30I~
    PINTMTBLADD   pmoredata;                                       //~va30I~
#endif                                                             //~va30I~
//*********************************                                //~v1.8I~
//printf("@@@0 rdintf file=%s\n",Pfile);                                    //~v258R~//~va9DR~
	if (Pfile)                          //first time               //~v1.8I~
  	{                                                              //~v1.8I~
//  	if (fseek(Shfile,(long)INTMTBLSZ,SEEK_SET))                //~v1.rR~
//  	if (fseek(Shfile,Sposafterhdr,SEEK_SET))                   //~v257R~
//      {                                                          //~v258R~
//  		printf("%s:%s:fsetpos(%s-%08lx) failed,rc=%d\n",       //~v258R~
//  				Spgm,Sver,Sinterfnm,Sposafterhdr,errno);       //~v258R~
//  		exit(4);                                               //~v258R~
//  	}                                                          //~v258R~
        strcpy(Scurpath,Pfile);                                    //~v238I~
        Spathlen=xdcpathlen(Pfile);                                //~v2.3R~
        fullpathlen=(int)strlen(Pfile);                            //~v1.9R~
        wildcardsw=(WILDCARD(Pfile)!=0);                           //~v1.9R~
        cmp=1;      //for the case no subdir found(postbl is null) //~v258I~
		for (ppost=Spostbltop;ppost;ppost=UGETQNEXT(ppost))        //~v258I~
        {                                                          //~v258I~
//printf("postsrch,%s\n",ppost->POSTdirnm);                        //~v258R~
            fnmlen=ppost->POSTdirnmlen;                            //~v258I~
            if (wildcardsw)                                        //~v258I~
            {                                                      //~v258I~
				cmp=!((fnmlen==Spathlen-1)   //chk path            //~v258I~
                    && (xdcfnmcmp(Pfile,ppost->POSTdirnm,(UINT)fnmlen)==0));	//comp last \ also//~v258I~
//printf("tblsrch cmp=%d,len=%d,%s:%s\n",cmp,Spathlen,Pfile,ppost->POSTdirnm);//~v258R~
                seekpos=ppost->POSTposchild;                       //~v258I~
                if (!cmp && !seekpos)	//found and no child       //~v258I~
                    return 4;   //no child                         //~v258R~
            }                                                      //~v258I~
            else                                                   //~v258I~
            {                                                      //~v258I~
				cmp=!((fnmlen==fullpathlen)                        //~v258I~
					 &&(xdcfnmcmp(Pfile,rec.fnm,(UINT)fullpathlen)==0));//~v258I~
                seekpos=ppost->POSTpos;                            //~v258I~
            }                                                      //~v258I~
            if (!cmp)                                              //~v258I~
                break;                                             //~v258I~
		}//postbl search                                           //~v258I~
        if (cmp)                                                   //~v258I~
	        seekpos=(ULONG)Sposafterhdr;                           //~va1BR~
//printf("tblsrch cmp=%d,   %s\n",cmp,Pfile);                      //~v258R~
        xdcfseek(seekpos);                                         //~v258I~
//file search                                                      //~v258I~
		for (;;)                                                   //~v1.9R~
        {                                                          //~v1.9I~
			if (freadsub(&rec))	//eof                              //~v1.9I~
            	return 4;                                          //~v1.9I~
//printf("@@@5 rdintf read attr dir?=%d,%s\n",rec.fattr & FILE_DIRECTORY,rec.fnm);//~va9DR~
            fnmlen=(int)strlen(rec.fnm);                           //~v238I~
        	pathlen=xdcpathlen(rec.fnm);                           //~v238I~
            if (wildcardsw)                                        //~v1.9I~
            {                                                      //~v238I~
    			cmp=!((pathlen==Spathlen)                          //~v258R~
                    && (xdcfnmcmp(Pfile,rec.fnm,(UINT)Spathlen)==0));	//comp last \ also//~v238I~
//printf("find1st @@@7 cmp=%d,Spathlen=%d,pathlen=%d,%s:%s\n",cmp,Spathlen,pathlen,Pfile,rec.fnm);//~v258R~//~va9DR~
//              if (!cmp && Pmasksw)	//mask parm,to be chked    //~v238I~//~va9DR~
//              if (!cmp && Sswimask)	//mask parm,to be chked    //~va9DR~
//              {                                                  //~v238I~//~va9DR~
//              	udoseditname(rec.fnm+Spathlen,Mask,Scurpath+Spathlen);//~v252R~
//                  cmp=!(((int)strlen(Scurpath+Spathlen)==fnmlen-pathlen)//~v252R~
//  				    && (xdcfnmcmp(Scurpath+Spathlen,rec.fnm+Spathlen,//~v252R~
//                             (UINT)(fnmlen-Spathlen))==0));	//comp last \ also//~v252R~
//                  cmp=ufilewildcomp(Swcopt,rec.fnm+Spathlen,Mask,0);//~v252R~//~va9AR~
//  				cmp=chkMask(0/*file only*/,&Sqhimask,rec.fnm+Spathlen)==0;//~va9AR~//~va9CR~//~va9DR~
//printf("@@@5 rdintf comp1=%d,%s\n",cmp,rec.fnm+Spathlen);            //~v258R~//~va9AR~//~va9DR~
//              }                                                  //~v238I~//~va9DR~
            }                                                      //~v238I~
            else                                                   //~v1.9I~
				cmp=!((fnmlen==fullpathlen)                        //~v238R~
					 &&(xdcfnmcmp(Pfile,rec.fnm,(UINT)fullpathlen)==0));//~v238I~
            if (!cmp)                                              //~va9DI~
                cmp=skipRecord(0,&rec,Spathlen);                   //~va9DR~
            if (!cmp)	//match                                    //~v1.9R~
	            break;                                             //~v1.9R~
		}//loop                                                    //~v1.8I~
//      Scurpath=Pfile;                                            //~v238R~
	}                                                              //~v1.8I~
  	else //request next file                                       //~v1.8I~
  	{                                                              //~v1.8I~
//  	if (Snextpos)                                              //~v1.dR~
//      {                                                          //~v1.dR~
//          if (fseek(Shfile,Snextpos,SEEK_SET))                   //~v1.dR~
//          {                                                      //~v1.dR~
//  			printf("%s:%s:fseek(%s-%08x) failed,rc=%d\n",      //~v1.dR~
//  					Spgm,Sver,Sinterfnm,Snextpos,errno);       //~v1.dR~
//  			exit(4);                                           //~v1.dR~
//      	}                                                      //~v1.dR~
//      	Snextpos=0;	//repositioned                             //~v1.dR~
//      }                                                          //~v1.dR~
//      pathlen=PATHLEN(Scurpath);                                 //~v1.dR~
	  for (;;)                                                     //~v238I~
      {                                                            //~v238I~
                                                                   //~v238I~
		if (freadsub(&rec)                                         //~v1.9R~
        ||  Spathlen!=xdcpathlen(rec.fnm)                          //~v238R~
        ||  xdcfnmcmp(Scurpath,rec.fnm,(UINT)Spathlen)	//after wildcard//~v238I~
//      ||  strchr(rec.fnm+Spathlen,'\\'))	//subdir member        //~v1.hR~
        ||  xdcpathlen(rec.fnm+Spathlen)>0)	//subdir member        //~v2.3R~
            return 4;                                              //~v1.9I~
//      if (!Pmasksw)    //no mask                                 //~v238I~//~va9DR~
//      	break;                                                 //~v238I~//~va9DR~
        fnmlen=(int)strlen(rec.fnm);                               //~v238I~
//      udoseditname(rec.fnm+Spathlen,Mask,Scurpath+Spathlen);     //~v252R~
//      cmp=!(((int)strlen(Scurpath+Spathlen)==fnmlen-Spathlen)    //~v252R~
//           && (xdcfnmcmp(Scurpath+Spathlen,rec.fnm+Spathlen,(UINT)(fnmlen-Spathlen))==0));    //comp last \ also//~v252R~
//      cmp=ufilewildcomp(Swcopt,rec.fnm+Spathlen,Mask,0);         //~v252R~//~va9AR~
        cmp=skipRecord(0,&rec,Spathlen);                           //~va9DR~
        if (!cmp)   //match                                        //~v238I~
            break;                                                 //~v238I~
      }                                                            //~v238I~
  	}//next req                                                    //~v1.8I~
#if defined(W32) || defined(DPMI)                                  //~v2.3R~
	if (Slfnsw)                                                    //~v1.mI~
	    strncpy(Pfstat->cFileName,rec.fnm+Spathlen,sizeof(Pfstat->cFileName)-1);//~v1.mM~
    else                                                           //~v1.mI~
	    strncpy(Pfstat->achName,rec.fnm+Spathlen,sizeof(Pfstat->achName)-1);//~v1.mM~
#else                                                              //~v1.mI~
    strcpy(Pfstat->achName,rec.fnm+Spathlen);                      //~v1.dR~
#endif                                                             //~v1.mI~
    Pfstat->attrFile=rec.fattr;                                    //~v1.9R~
#ifdef AIX    //AIX fstat is int(4 byte)                           //~v239I~//~va4bR~
	xdcfdtcnvr2t(&rec.ftm,&Pfstat->ftimeLastWrite);                //~v239I~
	xdcfdtcnvr2t(&rec.fdt,&Pfstat->fdateLastWrite);                //~v239I~
#else                                                              //~v239I~
    Pfstat->ftimeLastWrite=rec.ftm;                                //~v1.9R~
    Pfstat->fdateLastWrite=rec.fdt;                                //~v1.9R~
#endif                                                             //~v239I~
//  Pfstat->cbFile=rec.fsz;                                        //~v1.9I~//~vaa1R~
    Pfstat->cbFile=(FILESZT)rec.fsz;                               //~vaa1I~
#ifdef LFSSUPP                                                     //~va30I~
    if (Slfsintf[0])                                               //~va30R~
    {                                                              //~va30I~
      if (Slfsintf[0]==1)                                          //~va62I~
//    	pmoredata=(PINTMTBLADD)((ULONG)&rec+rec.lrecl-(INTMTBLADDSZ-INTMTBLADDSZ2)-sizeof(rec.zeor));//~va62I~//~va65R~
      	pmoredata=(PINTMTBLADD)((ULPTR)&rec+rec.lrecl-(INTMTBLADDSZ-INTMTBLADDSZ2)-sizeof(rec.zeor));//~va65I~
      else                                                         //~va62I~
//    	pmoredata=(PINTMTBLADD)((ULONG)&rec+rec.lrecl-INTMTBLADDSZ-sizeof(rec.zeor));//~va30R~//~va65R~
    	pmoredata=(PINTMTBLADD)((ULPTR)&rec+rec.lrecl-INTMTBLADDSZ-sizeof(rec.zeor));//~va65I~
        Pfstat->cbFile|=(FILESZT)(pmoredata->fszhigh)<<32;         //~va30I~
	#ifdef UNX                                                     //~va62M~
    	if (Slfsintf[0]==2)                                        //~va62I~
        {                                                          //~va62I~
        	Pfstat->uid=pmoredata->moredata2.uid;                  //~va62I~
        	Pfstat->gid=pmoredata->moredata2.gid;                  //~va62I~
//      	Pfstat->mtime=pmoredata->moredata2.sec1;               //~va6cI~//~vaa0R~
        	Pfstat->mtime=(time_t)(pmoredata->moredata2.sec1);	//time_t may be int32 or int64//~vaa0I~
        }                                                          //~va62I~
    #endif                                                         //~va62M~
    }                                                              //~va30I~
#endif                                                             //~va30I~
//printf("rdintf ret %s\n",rec.fnm);                               //~v254R~
	return 0;                                                      //~v1.8I~
}//rdintf                                                          //~v1.8I~
//**********************************************************************//~v258I~
//*create intm file pos tbl for all dir                            //~v258I~
//**********************************************************************//~v258I~
void xdcfseek(ULONG Ppos)                                          //~v258I~
{                                                                  //~v258I~
//printf("xdcfseek %08x\n",Ppos);                                  //~v258R~
	if (fseek(Shfile,(LONG)Ppos,SEEK_SET))                         //~va1BR~
    {                                                              //~v258I~
        printf("%s:%s:fseek to %08lx failed,rc=%d\n",              //~v258I~
                Spgm,Sver,Ppos,errno);                             //~v258I~
        exit(4);                                                   //~v258I~
    }                                                              //~v258I~
    return;                                                        //~v258I~
}//xdcseek                                                         //~v258I~
//**********************************************************************//~v258I~
//*create intm file pos tbl for all dir                            //~v258I~
//**********************************************************************//~v258I~
PPOSTB xdcpostblgen(void)                                          //~v258R~
{                                                                  //~v258I~
	UQUEH   qhpos;                                                 //~v258I~
    INTMTBL rec;                                                   //~v258I~
    ULONG cpos,posafter;                                           //~v258R~
    PPOSTB ppost;                                                  //~v258I~
    int dirnmlen,pathlen,pathlenp;                                 //~v258R~
    char fnmp[_MAX_PATH];                                          //~v258I~
//*********************************                                //~v258I~
	memset(&qhpos,0,sizeof(qhpos));                                //~v258R~
    if (fseek(Shfile,Sposafterhdr,SEEK_SET))                       //~v258I~
    {                                                              //~v258I~
        printf("%s:%s:fsetpos(%s-%08lx) failed,rc=%d\n",           //~v258I~
                Spgm,Sver,Sinterfnm,Sposafterhdr,errno);           //~v258I~
        exit(4);                                                   //~v258I~
    }                                                              //~v258I~
	posafter=(ULONG)Sposafterhdr;                                  //~va1BR~
    pathlenp=0;		//prev entry pathlen                           //~v258I~
    for (;;)                                                       //~v258I~
    {                                                              //~v258I~
        cpos=posafter;                                             //~v258R~
        if (freadsub(&rec)) //eof                                  //~v258I~
            break;                                                 //~v258I~
    	posafter=(ULONG)ftell(Shfile);			//save detail record pos//~va1BR~
        dirnmlen=(int)strlen(rec.fnm);                             //~v258M~
		pathlen=xdcpathlen(rec.fnm);                               //~v258I~
        if ((pathlen && pathlen!=pathlenp)                         //~v258R~
        ||  memcmp(rec.fnm,fnmp,(UINT)pathlen))	//different parent //~va1BR~
        {                                                          //~v258I~
        	pathlenp=pathlen;                                      //~v258I~
            memcpy(fnmp,rec.fnm,(UINT)pathlen);                    //~v258I~
        	xdcsetchild(&qhpos,rec.fnm,pathlen-1,cpos);            //~v258R~
        }                                                          //~v258I~
        if (!(rec.fattr & FILE_DIRECTORY))                         //~v258I~
            continue;                                              //~v258I~
        ppost=(PPOSTB)malloc(POSTBSZ+(UINT)dirnmlen);              //~va1BR~
        memset(ppost,0,POSTBSZ);                                   //~v258I~
        ppost->POSTpos=cpos;                                       //~v258I~
        ppost->POSTdirnmlen=dirnmlen;                              //~v258I~
        memcpy(ppost->POSTdirnm,rec.fnm,(UINT)dirnmlen+1);         //~va1BR~
//printf("dirpos %08x=%s\n",cpos,rec.fnm);                         //~v258R~
		UENQ(UQUE_END,&qhpos,ppost);                               //~v258I~
    }//loop                                                        //~v258I~
    ppost=UGETQTOP(&qhpos);                                        //~v258I~
	return ppost;                                                  //~v258I~
}//xdcpostblgen                                                    //~v258R~
//**********************************************************************//~v258I~
//*set 1st child pos to parent                                     //~v258I~
//**********************************************************************//~v258I~
int xdcsetchild(UQUEH *Ppqh,char *Ppathnm,int Ppathlen,ULONG Ppos) //~v258I~
{                                                                  //~v258I~
    PPOSTB ppost;                                                  //~v258I~
//*********************************                                //~v258I~
//printf("set child len=%d %s\n",Ppathlen,Ppathnm);                //~v258R~
	for (ppost=UGETQEND(Ppqh);ppost;ppost=UGETQPREV(ppost))        //~v258R~
    {                                                              //~v258I~
    	if (Ppathlen==ppost->POSTdirnmlen                          //~v258I~
        &&  !memcmp(Ppathnm,ppost->POSTdirnm,(UINT)Ppathlen))      //~va1BR~
        	break;                                                 //~v258I~
    }                                                              //~v258I~
    if (ppost)                                                     //~v258I~
    	if (!ppost->POSTposchild)                                  //~v258I~
        {                                                          //~v258I~
	    	ppost->POSTposchild=Ppos;                              //~v258I~
//printf("set child pos=%08X %s\n",Ppos,Ppathnm);                  //~v258R~
        }                                                          //~v258I~
	return 0;                                                      //~v258I~
}//xdcsetchild                                                     //~v258I~
//**********************************************************************//~v1.8I~
//*read intermediate file hdr                                      //~v1.8I~
//*  parm1:output fullpath name                                    //~v1.8I~
//*  return code:none                                              //~v1.8I~
//**********************************************************************//~v1.8I~
void rdintfhdr(char *Pfullpath,char *Pmask)                        //~v259R~
{                                                                  //~v1.8I~
	size_t len,lenr;                                               //~v1.rR~
    INTMTBL rec;                                                   //~v1.8I~
    char *pc;                                                      //~v259I~
#ifdef LFSSUPP                                                     //~va30I~
    INTMTBLADD   *pmoredata;                                       //~va30I~
    INTMTBLADD   *pmoredataold;                                    //~va62I~
#endif                                                             //~va30I~
//*********************************                                //~v1.8I~
#ifdef LFSSUPP                                                     //~va30I~
    Slfsintf[0]=0;	//lfs sw                                       //~va30I~
#endif                                                             //~va30I~
	if (!(Shfile=fopen(Sinterfnm,"rb")))                           //~v1.8I~
    {                                                              //~v1.8I~
		printf("%s:%s:open(\"%s\") failed,errno=%d(%s)\n",         //~v1.9R~
				Spgm,Sver,Sinterfnm,errno,strerror(errno));        //~v1.9R~
		exit(4);                                                   //~v1.8I~
    }                                                              //~v1.8I~
//  len=(int)fread(&rec,1,INTMTBLSZ,Shfile);                       //~v1.rR~
	len=PREREADLEN;                                                //~v1.rI~
    lenr=fread(&rec,1,len,Shfile);                                 //~v1.rI~
//#ifdef AIX                                                         //~v239I~//~va4bR~
#ifdef BIGENDIAN                                                   //~va4bI~
    if (rec.recid==INTMFRECID2)     //written by little endian     //~v239I~
        Sdossw=1;                                                  //~v239I~
    else                                                           //~v239I~
        Sdossw=0;                                                  //~v239I~
#else                                                              //~v239I~
    if (rec.recid==INTMFRECID)     //written by little endian      //~v239I~
        Sdossw=1;                                                  //~v239I~
    else                                                           //~v239I~
        Sdossw=0;                                                  //~v239I~
#endif                                                             //~v239I~
    rec.recid=xdcgetushort(&rec.recid); //big<-->little endian     //~v239I~
    rec.lrecl=xdcgetushort(&rec.lrecl); //big<-->little endian     //~v239I~
    if (lenr!=len                                                  //~v1.rI~
    || rec.recid!=INTMFRECID)                                      //~v1.rI~
    {                                                              //~v1.rI~
		printf("%s:%s:%s is invalid intermediate file(1st record recid err)\n",//~v1.rI~
				Spgm,Sver,Sinterfnm);                              //~v1.rI~
		exit(4);                                                   //~v1.rI~
    }                                                              //~v1.rI~
    len=(size_t)rec.lrecl-PREREADLEN;                              //~v1.rI~
    lenr=fread(&(rec.fsz),1,len,Shfile);                           //~v1.rI~
//  if (len!=INTMTBLSZ                                             //~v1.rR~
//  ||  memcmp(&rec,ACRONYM,ACRONYMSZ))                            //~v1.rR~
    if (lenr!=len                                                  //~v1.rI~
    ||  memcmp(&(rec.fsz),ACRONYM,ACRONYMSZ))                      //~v1.rI~
    {                                                              //~v1.8I~
		printf("%s:%s:%s is invalid intermediate file(header record err)\n",//~v1.rR~
				Spgm,Sver,Sinterfnm);                              //~v1.9R~
		exit(4);                                                   //~v1.8I~
    }                                                              //~v1.8I~
//  strcpy(Pfullpath,rec.fnm+ACRONYMSZ);                           //~v1.rR~
    len+=PREREADLEN;                    //lrecl                    //~v1.rI~
#ifdef LFSSUPP                                                     //~va30M~
//  pmoredata=(PINTMTBLADD)((ULONG)&rec+rec.lrecl-INTMTBLADDSZ-sizeof(rec.zeor));//~va30M~//~va65R~
    pmoredata=(PINTMTBLADD)((ULPTR)&rec+rec.lrecl-INTMTBLADDSZ-sizeof(rec.zeor));//~va65I~
//  pmoredataold=(PINTMTBLADD)((ULONG)&rec+rec.lrecl-(INTMTBLADDSZ-INTMTBLADDSZ2)-sizeof(rec.zeor));//~va62I~//~va65R~
    pmoredataold=(PINTMTBLADD)((ULPTR)&rec+rec.lrecl-(INTMTBLADDSZ-INTMTBLADDSZ2)-sizeof(rec.zeor));//~va65I~
//  if (pmoredata->sepdata==LFSID)                                 //~va62R~
    if (pmoredataold->sepdata==LFSID)                              //~va62I~
	    Slfsintf[0]=1;	//lfs sw                                   //~va30M~
    else                                                           //~va62I~
    if (pmoredata->sepdata==LFSID2)                                //~va62I~
	    Slfsintf[0]=2;	//lfs sw with uid/gid                      //~va62I~
  if (!Slfsintf[0])	//no lfs sw                                    //~va30I~
    len-=(INTMTBLSZ-INTMTBLADDSZ-MAXPATH);           //filename len//~va30I~
  else                                                             //~va30I~
  if (Slfsintf[0]==1)	//no uid/gid                               //~va62I~
    len-=(INTMTBLSZ-INTMTBLADDSZ2-MAXPATH);           //filename len//~va62I~
  else                                                             //~va62I~
#endif                                                             //~va30M~
    len-=(INTMTBLSZ-MAXPATH);           //filename len             //~v1.rI~
    pc=memchr(rec.fnm,MASKAPPENDID,len);                           //~v259I~
  if (pc)                                                          //~v259I~
  {                                                                //~v259R~
//  memcpy(Pfullpath,rec.fnm,(ULONG)pc-(ULONG)rec.fnm);	//with last null//~va3nR~
//  memcpy(Pfullpath,rec.fnm,(UINT)((ULONG)pc-(ULONG)rec.fnm));	//with last null//~va3nI~//~va65R~
    memcpy(Pfullpath,rec.fnm,(UINT)((ULPTR)pc-(ULPTR)rec.fnm));	//with last null//~va65I~
//  *(Pfullpath+((ULONG)pc-(ULONG)rec.fnm))=0;	//with last null   //~v259R~//~va65R~
    *(Pfullpath+((ULPTR)pc-(ULPTR)rec.fnm))=0;	//with last null   //~va65I~
//  len-=(ULONG)pc-(ULONG)rec.fnm+1;                               //~v259R~//~va65R~
    len-=(ULPTR)pc-(ULPTR)rec.fnm+1;                               //~va65I~
    memcpy(Pmask,pc+1,len+1);                                      //~v259I~
  }                                                                //~v259I~
  else                                                             //~v259I~
  {                                                                //~v259I~
    memcpy(Pfullpath,rec.fnm,len+1);	//with last null           //~v1.rR~
    *Pmask=0;                                                      //~v259I~
  }                                                                //~v259I~
    Sposafterhdr=ftell(Shfile);			//save detail record pos   //~v1.rI~
	return;                                                        //~v1.8I~
}//rdintfhdr                                                       //~v1.8I~
//**********************************************************************//~v1.8I~
//*read intermediate file sub                                      //~v1.8I~
//*  parm1:io area                                                 //~v1.8I~
//*  return code: 0- normal                                        //~v1.8I~
//*               1- eof                                           //~v1.8I~
//**********************************************************************//~v1.8I~
int freadsub(void *Pioa)                                           //~v1.9R~
{                                                                  //~v1.8I~
	size_t len;                                                    //~v1.8R~
	size_t lenr;                                                   //~v1.rI~
    PINTMTBL prec;                                                 //~v1.rR~
//  char *pc;                                                      //~v1.hR~
//******************                                               //~v1.8I~
    prec=Pioa;                                                     //~v1.rI~
//  len=fread(Pioa,1,INTMTBLSZ,Shfile);                            //~v1.rR~
    len=fread(Pioa,1,PREREADLEN,Shfile);	//read lrecl+recid     //~v1.rI~
    if (!len)                                                      //~v1.8I~
        return 1;	//retry                                        //~v1.8I~
//#ifdef AIX                                                         //~v239I~//~va4bR~
#ifdef BIGENDIAN                                                   //~va4bI~
    if (prec->recid==INTMFRECID2)     //written by little endian   //~v239R~
        Sdossw=1;                                                  //~v239I~
    else                                                           //~v239I~
        Sdossw=0;                                                  //~v239I~
#else                                                              //~v239I~
    if (prec->recid==INTMFRECID)     //written by little endian    //~v239R~
        Sdossw=1;                                                  //~v239I~
    else                                                           //~v239I~
        Sdossw=0;                                                  //~v239I~
#endif                                                             //~v239I~
    prec->recid=xdcgetushort(&prec->recid); //big<-->little endian //~v239R~
    prec->lrecl=xdcgetushort(&prec->lrecl); //big<-->little endian //~v239R~
//  if (len!=INTMTBLSZ)                                            //~v1.rR~
    if (len!=PREREADLEN                                            //~v1.rI~
    || prec->recid!=INTMFRECID)                                    //~v1.rI~
    {                                                              //~v1.8I~
		printf("%s:%s:%s has invalid intermediate file record id\n",//~v1.rR~
				Spgm,Sver,Sinterfnm);                              //~v1.9R~
		exit(4);                                                   //~v1.8I~
    }                                                              //~v1.8I~
    len=(size_t)prec->lrecl-PREREADLEN;                            //~v1.rI~
    lenr=fread(&(prec->fsz),1,len,Shfile);                         //~v1.rI~
    if (lenr!=len)                                                 //~v1.rI~
    {                                                              //~v1.rI~
		printf("%s:%s:%s is has invalid intermediate file record format\n",//~v1.rI~
				Spgm,Sver,Sinterfnm);                              //~v1.rI~
		exit(4);                                                   //~v1.rI~
    }                                                              //~v1.rI~
    prec->fsz  =xdcgetuint(&prec->fsz); //big<-->little endian     //~v239R~
    prec->fattr=xdcgetuint(&prec->fattr); //big<-->little endian   //~v239R~
    prec->fattr=xdcgetuint(&prec->fattr); //big<-->little endian   //~v239R~
    xdcfdtcnv(&prec->ftm); //big<-->little endian                  //~v239R~
    xdcfdtcnv(&prec->fdt); //big<-->little endian                  //~v239R~
//  pc=(char*)Pioa+strlen(Pioa)-1;                                 //~v1.hR~
//  if (*pc=='\\')                                                 //~v1.hR~
//  	*pc=0;	//drop last "\"                                    //~v1.hR~
//  len=strlen(Pioa);                                              //~v1.rR~
    len+=PREREADLEN;                    //lrecl                    //~v1.rI~
#ifdef LFSSUPP                                                     //~va30I~
  if (!Slfsintf[0])	//input has no high value                      //~va30I~
    len-=(INTMTBLSZ-INTMTBLADDSZ-MAXPATH);           //filename len//~va30I~
  else                                                             //~va30I~
  if (Slfsintf[0]==1)	//without uid/gid                          //~va62I~
    len-=(INTMTBLSZ-INTMTBLADDSZ2-MAXPATH);           //filename len//~va62I~
  else                                                             //~va62I~
#endif                                                             //~va30I~
    len-=(INTMTBLSZ-MAXPATH);           //filename len             //~v1.rI~
//  if (PATHLEN(Pioa)==(int)len)   //last is \(sbcs)               //~v1.rR~
//  	*(char*)((ULONG)Pioa+len-1)=0;		//drop last "\"        //~v1.rR~
//  if (xdcpathlen(prec->fnm)==(int)len)   //last is \(sbcs)       //~v257R~
    if (xdcchklastsepc(prec->fnm,(int)len))  //last is not \(sbcs) //~va1BR~
    	*(prec->fnm+len-1)=0;		//drop last "\"                //~v1.rI~
//	if ((Scurpos=ftell(Shfile))==-1L)                              //~v1.dR~
//  {                                                              //~v1.dR~
//		printf("%s:%s:%s ftell failed,rc=%d\n",                    //~v1.dR~
//				Spgm,Sver,Sinterfnm,errno);                        //~v1.dR~
//		exit(4);                                                   //~v1.dR~
//  }                                                              //~v1.dR~
//printf("freadsub=%s\n",prec->fnm);                               //~v258R~
    return 0;                                                      //~v1.8I~
}//freadsub                                                        //~v1.8I~
//**********************************************************************//~v1.8I~
//* write intermediate file                                        //~v1.8I~
//*  parm1:path name(with last \)                                  //~v1.8R~
//*  parm2:filename table                                          //~v1.8I~
//*  return: none                                                  //~v1.8I~
//**********************************************************************//~v1.8I~
void wtintf(char *Ppath,FNTBL *Pfnt)                               //~v1.9R~
{                                                                  //~v1.8I~
    INTMTBL rec;                                                   //~v1.8I~
#ifdef LFSSUPP                                                     //~va30I~
    INTMTBLADD   *pmoredata;                                       //~va30I~
#endif                                                             //~va30I~
    size_t len,lenw;                                               //~v1.rR~
//**************************                                       //~v1.8I~
//  memset(rec.rsv,' ',sizeof(rec.rsv));                           //~v1.rR~
//  rec.eor='\n';                                                  //~v1.rR~
	if (!Shfile)                                                   //~v1.8I~
    {                                                              //~v1.8I~
    	if (!(Shfile=fopen(Sinterfnm,"wb")))                       //~v1.8I~
        {                                                          //~v1.8I~
			printf("%s:%s:open(\"%s\") failed,errno=%d\n",         //~v1.9R~
					Spgm,Sver,Sinterfnm,errno);                    //~v1.9R~
			exit(4);                                               //~v1.8I~
        }                                                          //~v1.8I~
        memset(&rec,0,sizeof(rec));                                //~v1.oR~
//      memcpy(rec.fnm,ACRONYM,ACRONYMSZ);                         //~v1.rR~
        memcpy(&rec.fsz,ACRONYM,ACRONYMSZ);                        //~v1.rR~
//      strcpy(rec.fnm+ACRONYMSZ,Ppath);                           //~v1.rR~
        len=strlen(Ppath)-1;        //drop last \ oo               //~v1.rI~
//    if (ROOTDIR(Ppath))                                          //~v265R~
      if ((len==0)        //    "/"                                //~v265R~
      ||  (len==2 &&  *(Ppath+1)==':')) //d:\   oo                 //~v265R~
        len++;           // keep last \ oo                         //~v263I~
        memcpy(rec.fnm,Ppath,len);                                 //~v1.rI~
      	if (*Mask)                                                 //~v259I~
      	{                                                          //~v259I~
	        sprintf(rec.fnm+len,"%c%s",MASKAPPENDID,Mask);         //~v259I~
            len+=1+strlen(Mask);                                   //~v259R~
      	}                                                          //~v259I~
#ifdef LFSSUPP                                                     //~va30I~
//    	pmoredata=(PINTMTBLADD)(ULONG)(rec.fnm+len);               //~va30I~//~va65R~
    	pmoredata=(PINTMTBLADD)(ULPTR)(rec.fnm+len);               //~va65I~
//  	pmoredata->sepdata=LFSID;                                  //~va62R~
    	pmoredata->sepdata=LFSID2;  //with uid/gid                 //~va62I~
		pmoredata->fszhigh=0;                                      //~va30I~
		pmoredata->moredata2.uid=0;                                //~va62I~
		pmoredata->moredata2.gid=0;                                //~va62I~
		pmoredata->moredata2.sec1=0;                               //~va6cI~
        memcpy(rec.fnm+len+INTMTBLADDSZ,Szcrlf,sizeof(Szcrlf));    //~va30R~
#else                                                              //~va30I~
        memcpy(rec.fnm+len,Szcrlf,sizeof(Szcrlf));                 //~v1.rR~
#endif                                                             //~va30M~
//      *(rec.fnm+ACRONYMSZ+strlen(Ppath)-1)=0;	//drop last "\"    //~v1.rR~
        len+=INTMTBLSZ-MAXPATH;                                    //~v1.rI~
        rec.lrecl=(USHORT)len;                                     //~v1.rI~
        rec.recid=INTMFRECID;                                      //~v1.rR~
//     	if (fwrite(&rec,1,INTMTBLSZ,Shfile)!=INTMTBLSZ)            //~v1.rR~
       	if ((lenw=fwrite(&rec,1,len,Shfile))!=len)                 //~v1.rR~
    	{                                                          //~v1.8I~
			printf("%s:%s:file(\"%s\") write failed,errno=%d(req=%ld,written=%ld)\n",//~v1.rR~
					Spgm,Sver,Sinterfnm,errno,(long)len,(long)lenw);//~v2.3R~
			exit(4);                                               //~v1.8I~
    	}                                                          //~v1.8I~
	}                                                              //~v1.8I~
	                                                               //~v1.8I~
//  strncpy(rec.fnm,Ppath,sizeof(rec.fnm));                        //~v1.rR~
    len=strlen(Ppath);        //path len                           //~v1.rI~
    memcpy(rec.fnm,Ppath,len);                                     //~v1.rI~
//  strcat(rec.fnm,Pfnt->fnm);                                     //~v1.rR~
    lenw=strlen(Pfnt->fnm);        //path len                      //~v1.rI~
    memcpy(rec.fnm+len,Pfnt->fnm,lenw);                            //~v1.rI~
    len+=lenw;                                                     //~v1.rI~
#ifdef LFSSUPP                                                     //~va30I~
//  pmoredata=(PINTMTBLADD)(ULONG)(rec.fnm+len);                   //~va30M~//~va65R~
    pmoredata=(PINTMTBLADD)(ULPTR)(rec.fnm+len);                   //~va65I~
	pmoredata->sepdata=0;                                          //~va30R~
	pmoredata->fszhigh=(ULONG)(Pfnt->fsz>>32);                     //~va30R~
    memcpy(rec.fnm+len+INTMTBLADDSZ,Szcrlf,sizeof(Szcrlf));        //~va30R~
    rec.fsz=(ULONG)Pfnt->fsz;                                      //~va30I~
    memset(&(pmoredata->moredata2),0,sizeof(pmoredata->moredata2));//~va9CR~
	pmoredata->moredata2.uid=Pfnt->uid;                            //~va62I~
	pmoredata->moredata2.gid=Pfnt->gid;                            //~va62I~
	pmoredata->moredata2.sec1=Pfnt->sec1;                          //~va6cI~
#else                                                              //~va30I~
    memcpy(rec.fnm+len,Szcrlf,sizeof(Szcrlf));                     //~v1.rR~
    rec.fsz=Pfnt->fsz;                                             //~v1.8I~
#endif                                                             //~va30I~
#ifdef AIX                                                         //~v239I~//~va4bR~
	xdcfdtcnvt2r(&Pfnt->ftm,&rec.ftm);                             //~v239I~
	xdcfdtcnvt2r(&Pfnt->fdt,&rec.fdt);                             //~v239I~
#else                                                              //~v239I~
    rec.ftm=Pfnt->ftm;                                             //~v1.8I~
    rec.fdt=Pfnt->fdt;                                             //~v1.8I~
#endif                                                             //~v239I~
    rec.fattr=Pfnt->fattr;                                         //~v1.9I~
    len+=INTMTBLSZ-MAXPATH;                                        //~v1.rI~
    rec.lrecl=(USHORT)len;                                         //~v1.rI~
    rec.recid=INTMFRECID;                                          //~v1.rI~
// 	if (fwrite(&rec,1,INTMTBLSZ,Shfile)!=INTMTBLSZ)                //~v1.rR~
   	if ((lenw=fwrite(&rec,1,len,Shfile))!=len)                     //~v1.rI~
    {                                                              //~v1.8I~
		printf("%s:%s:%s write failed,errno=%d(req=%ld,written=%ld)\n",//~v1.rR~
				Spgm,Sver,Sinterfnm,errno,(long)len,(long)lenw);   //~v2.3R~
		exit(4);                                                   //~v1.8I~
    }                                                              //~v1.8I~
    return;                                                        //~v1.8I~
}//wtintf                                                          //~v1.9R~
//**********************************************************************//~va6bI~
//*diff time(ts1>ts2)                                              //~va6bI~
//**********************************************************************//~va6bI~
ULONG adjustTZ(ULONG Pts1)                                         //~va6bR~
{                                                                  //~va6bI~
	FDATE *pd1;                                                    //~va6bI~
	FTIME *pt1;                                                    //~va6bI~
	FDATE fd1;                                                     //~va78I~
	FTIME ft1;                                                     //~va78I~
    USHORT d1,t1;                                                  //~va6bI~
    LONG ts1[4],ts2[4],ts1old,ts1new,fdft;                         //~va6bI~
    int opt,nextday=0;                                             //~va6bR~
    int yy,mm,dd;                                                  //~va6bI~
//***********************                                          //~va6bI~
    d1=(USHORT)(Pts1>>16);                                         //~va6bR~
    t1=(USHORT)(Pts1&0xffff);                                      //~va6bI~
//  pd1=(FDATE*)(ULPTR)(&d1);                                      //~va6bI~//~va78R~
//  pt1=(FTIME*)(ULPTR)(&t1);                                      //~va6bI~//~va78R~
    USHORT2FDATE(fd1,d1);                                          //~va78I~
    USHORT2FTIME(ft1,t1);                                          //~va78I~
    pd1=&fd1;                                                      //~va78I~
    pt1=&ft1;                                                      //~va78I~
    memset(ts1,0,sizeof(ts1));                                     //~va6bI~
    memset(ts2,0,sizeof(ts2));                                     //~va6bI~
    ts1[0]=ts1old=(pt1->hours<<16)+(pt1->minutes<<8)+pt1->twosecs*2;//~va6bI~
    ts2[0]=Stzparm;                                                //~va6bI~
    opt=CALC_TIME_CONV2SEC; //result by sec because BORROW is ignored//~va6bI~
    ucalc_time(opt,'+',ts1,ts2);	//get diff by seconds          //~va6bI~
    opt=CALC_TIME_CONV2HMS|CALC_TIME_BORROW;                       //~va6bI~
    ucalc_time(opt,'=',ts1,ts1);	//get diff by seconds          //~va6bR~
    ts1new=ts1[0];                                                 //~va6bI~
//  if (Stzparm & CALC_TIME_MINUS)                                 //~va6bI~//~vaa0R~
    if ((unsigned)Stzparm & CALC_TIME_MINUS)                       //~vaa0I~
    {                                                              //~va6bI~
    	if (ts1new>ts1old)	//back date                            //~va6bI~
        	nextday=-1;                                            //~va6bI~
    }                                                              //~va6bI~
    else  //                                                       //~va6bI~
    {                                                              //~va6bI~
    	if (ts1new>0x180000)	// hh=24                           //~va6bR~
        {                                                          //~va6bI~
            ts1[0]=(ts1new-=0x180000);                             //~va6bR~
        	nextday=1;                                             //~va6bI~
        }                                                          //~va6bI~
    }                                                              //~va6bI~
//  pt1->hours=(unsigned short)(ts1new>>16);                       //~va6cR~//~vaa2R~
//  pt1->minutes=(unsigned short)((ts1new>>8)& 0xff);              //~va6cR~//~vaa2R~
//  pt1->twosecs=(unsigned short)((ts1new & 0xff)/2);              //~va6cR~//~vaa2R~
    ueditsetftimeUSHORT(0,(int)(ts1new>>16),(int)((ts1new>>8)& 0xff),(int)(ts1new & 0xff)/2,pt1);//~vaa2R~
    if (nextday)                                                   //~va6bI~
    {                                                              //~va6bI~
    	yy=pd1->year+1980;                                         //~va6bI~
        mm=pd1->month;                                             //~va6bI~
        dd=pd1->day;                                               //~va6bI~
//priintf("date nextday=%d,old=%d:%02d:%02d",nextday,yy,mm,dd);    //~va6bR~
        ucalc_nextday(nextday,&yy,&mm,&dd);                        //~va6bI~
//printf(", new=%d:%02d:%02d\n",yy,mm,dd);                         //~va6bR~
//      pd1->year=(unsigned short)(yy-1980);                       //~va6cR~//~vaa2R~
//      pd1->month=(unsigned short)(mm);                           //~va6cR~//~vaa2R~
//      pd1->day=(unsigned short)(dd);                             //~va6cR~//~vaa2R~
	    ueditsetfdateUSHORT(0,yy-1980,mm,dd,pd1);                  //~vaa2R~
    }                                                              //~va6bI~
//  fdft=FDATETIME2ULONG(d1,t1);                                   //~va6bI~//~va78R~
//  fdft=PFDATETIME2ULONG(pd1,pt1);                                //~va78R~//~vaa0R~
    fdft=(LONG)PFDATETIME2ULONG(pd1,pt1);                          //~vaa0I~
//printf("ts old=%08lx,new=%08lx,tz=%08x,fdft=%08lx->%08lx\n",ts1old,ts1new,Stzparm,Pts1,fdft);//~va6cR~//~va6bR~
//  return fdft;                                                   //~va6bI~//~vaa0R~
    return (ULONG)fdft;                                            //~vaa0I~
}//adjustTZ                                                        //~vaa0R~
//**********************************************************************//~va69I~
//*diff time(ts1>ts2)                                              //~va69I~
//**********************************************************************//~va69I~
int diff2sec(ULONG Pts1,ULONG Pts2)                                //~va69I~
{                                                                  //~va69I~
	FDATE /* *pd1,*/ *pd2;                                               //~va69I~//~va76R~
	FTIME *pt1,*pt2;                                               //~va69I~
    USHORT d1,d2,t1,t2;                                            //~va69I~
    LONG ts1[4],ts2[4];                                            //~va69I~
    int rc=0;                                                      //~va69R~
    int yy,mm,dd;                                                  //~va69I~
//***********************                                          //~va69I~
    d1=(USHORT)(Pts1>>16);                                         //~va69R~
    t1=(USHORT)(Pts1&0xffff);                                      //~va69R~
    d2=(USHORT)(Pts2>>16);                                         //~va69R~
    t2=(USHORT)(Pts2&0xffff);                                      //~va69R~
//  pd1=(FDATE*)(ULPTR)(&d1);                                      //~va69R~//~va76R~
    pt1=(FTIME*)(ULPTR)(&t1);                                      //~va69R~
    pd2=(FDATE*)(ULPTR)(&d2);                                      //~va69R~
    pt2=(FTIME*)(ULPTR)(&t2);                                      //~va69R~
    memset(ts1,0,sizeof(ts1));                                     //~va69R~
    memset(ts2,0,sizeof(ts2));                                     //~va69R~
    ts1[0]=(pt1->hours<<16)+(pt1->minutes<<8)+pt1->twosecs*2;      //~va69R~
    ts2[0]=(pt2->hours<<16)+(pt2->minutes<<8)+pt2->twosecs*2;      //~va69R~
    ucalc_time(CALC_TIME_CONV2SEC,'-',ts1,ts2);	//get diff by seconds//~va69I~
    if (ts1[0]==2)  //diff 2 seconds                               //~va69R~
    {                                                              //~va69I~
        if (d1==d2)                                                //~va69I~
            rc=1;                                                  //~va69R~
    }                                                              //~va69I~
    else                                                           //~va69I~
    if (ts1[0]==-2)  //diff 2 seconds                              //~va69I~
    {                                                              //~va69I~
        if (t1==0)   //beyond 24H                                  //~va69I~
        {                                                          //~va69I~
            yy=pd2->year+1980;                                     //~va69R~
            mm=pd2->month;                                         //~va69R~
            dd=pd2->day;                                           //~va69R~
            ucalc_nextday(1,&yy,&mm,&dd);                          //~va69R~
        }                                                          //~va69I~
    }                                                              //~va69I~
    return rc;                                                     //~va69R~
}//diff2sec                                                        //~va69I~
//**********************************************************************
//* result print
//*  parm1:dir1 file status
//*  parm2:dir2 file status
//*  return     1:same
//*             0:not same
//**********************************************************************
int lineprint(FNTBL *Pfnt1,FNTBL *Pfnt2)
{
	char line[512];                                                //~v1.wR~
	char *pos,*comp;
    char  comp2[4];                                                //~v1.aI~
	FNTBL *fnt;
	ULONG *ts1,*ts2;
	ULONG ts1v,ts2v;                                               //~va65I~
	int   samesw=0,len,bothdirsw=0;                                //~v1.kR~
	int   sizenesw=0,tsnesw=0,attrnesw=0,bothfilesw=0;             //~v1.kR~
	int   ts2secsw=0;                                              //~va69I~
#ifdef UNX                                                         //~va62I~
    int   uidnesw=0;                                               //~va62I~
#endif //UNX/!UNX                                                  //~va62I~
	int   tslowsw=0,tshighsw=0;                                    //~v23gI~
	int   attrAnesw=0,attrSnesw=0,attrRnesw=0,attrHnesw=0;         //~v1.uR~
#if defined(W32) || defined(UNX)                                   //~va71I~
	int   attrSLINKnesw=0;                                         //~va71I~
#endif                                                             //~va71I~
	int   contentsnesw=0;                                          //~va1BI~
    int putsw;                                                     //~v23eI~
#ifdef UNX                                                         //~v2.3I~
	int   attrRWXnesw=0;                                           //~v2.3I~
#endif //UNX/!UNX                                                  //~v2.3I~
    USHORT tmdt[4];                                                //~v1.mI~
    char dbcswk[MAX_FILENAMEFLDSZ+2];                              //~v252R~
    char *contpos=0;                                               //~v252R~
    int diff1sec;                                                  //~va6cI~
//**************************
//    if (Sswxmask)                                                  //~va9gI~//~va9DR~
//    {                                                              //~va9gI~//~va9DR~
//        if (Pfnt1)                                                 //~va9gI~//~va9DR~
//            if (chkMask(0,&Sqhxmask,Pfnt1->fnm))                   //~va9gR~//~va9DR~
//            {                                                      //~va9AI~//~va9DR~
//                printf("@@@8 lineprint skip %s\n",Pfnt1->fnm);     //~va9AR~//~va9DR~
//                return 0;                                          //~va9gR~//~va9DR~
//            }                                                      //~va9AI~//~va9DR~
//        if (Pfnt2)                                                 //~va9gI~//~va9DR~
//            if (chkMask(0,&Sqhxmask,Pfnt2->fnm))                   //~va9gR~//~va9DR~
//            {                                                      //~va9AI~//~va9DR~
//                printf("@@@9 lineprint skip %s\n",Pfnt2->fnm);     //~va9AR~//~va9DR~
//                return 0;                                          //~va9gR~//~va9DR~
//            }                                                      //~va9AI~//~va9DR~
//    }                                                              //~va9gI~//~va9DR~
    putsw=0;                                                       //~va62I~
	fnt=(Pfnt1?Pfnt1:Pfnt2);
//  if (strlen(fnt->fnm)>32)                                       //~v1.7R~
//  	pos=line+sprintf(line,"%20.20s",fnt->fnm);//right justify  //~v1.7R~
//  else                                                           //~v1.7R~
//  	pos=line+sprintf(line,"%-20.20s",fnt->fnm);//left justify  //~v1.7R~
//  len=(int)strlen(fnt->fnm);                                     //~v1.7R~
//  if (*(fnt->fnm+len-1)=='\\')	//dir                          //~v1.7R~
//  {                                                              //~v1.7R~
//      *(fnt->fnm+len-1)=0;                                       //~v1.7R~
//  	pos=strrchr(fnt->fnm,'\\');	//last                         //~v1.7R~
//      *(fnt->fnm+len-1)='\\';                                    //~v1.7R~
//  }                                                              //~v1.7R~
//  else                                                           //~v1.7R~
//  	pos=strrchr(fnt->fnm,'\\');	//last                         //~v1.7R~
//  if (pos)                                                       //~v1.7R~
//      pos++;                                                     //~v1.7R~
//  else                                                           //~v1.7R~
//  	pos=fnt->fnm;                                              //~v1.7R~
// 	len=sprintf(line,fnameedit,pos);                               //~v1.7R~
#ifdef W32UNICODE                                                  //~va91I~
  if (strchr(fnt->fnm,UD_NOTLC))    //UD fmt                       //~va91I~
    len=setlinefnm(line,fnt->fnm,fnameedit,Sfilenamefldsz,&contpos);//~va91I~
  else                                                             //~va91I~
#endif                                                             //~va91I~
  {                                                                //~va91I~
   	len=sprintf(line,fnameedit,fnt->fnm);                          //~v1.7R~
    UTRACEP("fntfnm1=%s\n",fnt->fnm);                              //~va91R~
//printf("len=%d,fldsz=%d,line=%s\n",len,Sfilenamefldsz,line);     //~v252R~
//  if (len>FILENAMEFLDSZ)                                         //~v252R~
    if ((int)strlen(fnt->fnm)>Sfilenamefldsz)                      //~v252R~
    {                                                              //~v252I~
    	usetdbcstbl(USDT_CODE_DEFAULT,fnt->fnm,dbcswk,Sfilenamefldsz+1);//~v252R~
//printf("dbcs =%c\n",*(dbcswk+FILENAMEFLDSZ-1));                  //~v252R~
        if (*(dbcswk+Sfilenamefldsz-1)==UDBCSCHK_DBCS1ST)	//dbcs split//~v252R~
        	*(line+Sfilenamefldsz-1)='.';	//repl 1st byte to space//~v252R~
    	len=Sfilenamefldsz;                                        //~v252R~
        contpos=line+len;                                          //~v252I~
    }                                                              //~v252I~
  }                                                                //~va91I~
   	pos=line+len;                                                  //~v1.6I~
                                                                   //~v1.mI~
//  ts1=(ULONG*)(void*)(&Pfnt1->ftm);                              //~v1.mR~
//  ts2=(ULONG*)(void*)(&Pfnt2->ftm);                              //~v1.mR~

    if (Pfnt1 && Stzparm)                                          //~va6bR~
    {                                                              //~va6bI~
//      ts1v=(((*(SHORT*)(ULPTR)(&Pfnt1->fdt))&0x0ffff)<<16)       //~va6bR~//~va78R~
//      	|(((*(SHORT*)(ULPTR)(&Pfnt1->ftm))&0x0ffff));          //~va6bR~//~va78R~
        ts1v=FDATETIME2ULONG(Pfnt1->fdt,Pfnt1->ftm);               //~va78R~
        ts1v=adjustTZ(ts1v);                                       //~va6bI~
#ifdef AIX                                                         //~va6bM~
        *(ULONG*)(void*)(&Pfnt1->fdt)=(ULONG)(ts1v>>16);           //~va6bI~
        *(ULONG*)(void*)(&Pfnt1->ftm)=(ULONG)(ts1v&0xffff);        //~va6bI~
#else                                                              //~va6bM~
//      *(USHORT*)(void*)(&Pfnt1->fdt)=(USHORT)(ts1v>>16);         //~va6bI~//~va78R~
//      *(USHORT*)(void*)(&Pfnt1->ftm)=(USHORT)(ts1v&0xffff);      //~va6bI~//~va78R~
        USHORT2FDATE(Pfnt1->fdt,(USHORT)(ts1v>>16));               //~va78I~
        USHORT2FTIME(Pfnt1->ftm,(USHORT)(ts1v&0xffff));            //~va78R~
#endif                                                             //~va6bM~
    }                                                              //~va6bI~
	pos=tsedit(pos,fnt);
    if (contpos)                                                   //~v252I~
        *contpos='.';   //filename continued id                    //~v252I~
	if (Pfnt1&&Pfnt2)
	{
        bothdirsw=(int)(Pfnt1->fattr & Pfnt2->fattr & FILE_DIRECTORY);	//both dir//~va1BI~
        bothfilesw=( !(Pfnt1->fattr & FILE_DIRECTORY)              //~va1BI~
        		   &&!(Pfnt2->fattr & FILE_DIRECTORY) );           //~va1BI~
#ifdef AIX                                                         //~v233I~//~va4bR~
//        tmdt[0]=(USHORT)(*(ULONG*)(void*)(&Pfnt1->ftm));         //~v236R~
//        tmdt[1]=(USHORT)(*(ULONG*)(void*)(&Pfnt1->fdt));         //~v236R~
//        tmdt[2]=(USHORT)(*(ULONG*)(void*)(&Pfnt2->ftm));         //~v236R~
//        tmdt[3]=(USHORT)(*(ULONG*)(void*)(&Pfnt2->fdt));         //~v236R~
        tmdt[0]=(USHORT)(*(ULONG*)(void*)(&Pfnt1->fdt));           //~v236I~
        tmdt[1]=(USHORT)(*(ULONG*)(void*)(&Pfnt1->ftm));           //~v236I~
        tmdt[2]=(USHORT)(*(ULONG*)(void*)(&Pfnt2->fdt));           //~v236I~
        tmdt[3]=(USHORT)(*(ULONG*)(void*)(&Pfnt2->ftm));           //~v236I~
#else                                                              //~v233I~
//        tmdt[0]=*(USHORT*)(void*)(&Pfnt1->ftm);                  //~va69R~
//        tmdt[1]=*(USHORT*)(void*)(&Pfnt1->fdt);                  //~va69R~
//        tmdt[2]=*(USHORT*)(void*)(&Pfnt2->ftm);                  //~va69R~
//        tmdt[3]=*(USHORT*)(void*)(&Pfnt2->fdt);                  //~va69R~
//        tmdt[0]=*(USHORT*)(ULPTR)(&Pfnt1->ftm);                    //~va69I~//~va78R~
//        tmdt[1]=*(USHORT*)(ULPTR)(&Pfnt1->fdt);                    //~va69I~//~va78R~
//        tmdt[2]=*(USHORT*)(ULPTR)(&Pfnt2->ftm);                    //~va69I~//~va78R~
//        tmdt[3]=*(USHORT*)(ULPTR)(&Pfnt2->fdt);                    //~va69I~//~va78R~
        tmdt[0]=FTIME2USHORT(Pfnt1->ftm);                          //~va78I~
        tmdt[1]=FDATE2USHORT(Pfnt1->fdt);                          //~va78I~
        tmdt[2]=FTIME2USHORT(Pfnt2->ftm);                          //~va78I~
        tmdt[3]=FDATE2USHORT(Pfnt2->fdt);                          //~va78I~
#endif                                                             //~v233I~
//      ts1=(ULONG*)(void*)tmdt;                                   //~va65R~
//      ts1v=tmdt[1]<<16|(tmdt[0] & 0xffff);//short to long,for BIG endian//~va65R~//~vaa0R~
        ts1v=(ULONG)tmdt[1]<<16|((ULONG)tmdt[0] & 0xffff);//short to long,for BIG endian//~vaa0I~
        ts1=&ts1v;                                                 //~va65I~
//      ts2=(ULONG*)(void*)(tmdt+2);                               //~va65R~
//      ts2v=tmdt[3]<<16|(tmdt[2] & 0xffff);//short to long,for BIG endian//~va65R~//~vaa0R~
        ts2v=(ULONG)tmdt[3]<<16|((ULONG)tmdt[2] & 0xffff);//short to long,for BIG endian//~vaa0I~
        ts2=&ts2v;                                                 //~va65I~
//printf("%s ts1=%8lx=%08x ts2=%8lx=%08x\n",Pfnt1->fnm,*ts1,ts1,*ts2,ts2);//@@@@//~v1.mM~
//printf("ts1=%04x-%04x ts2=%04x-%04x\n",                          //~v1.mM~
//        (int)(*(USHORT*)(void*)(&Pfnt1->ftm)),                   //~v1.mM~
//        (int)(*(USHORT*)(void*)(&Pfnt1->fdt)),                   //~v1.mM~
//        (int)(*(USHORT*)(void*)(&Pfnt2->ftm)),                   //~v1.mM~
//        (int)(*(USHORT*)(void*)(&Pfnt2->fdt)));//@@@@            //~v1.mM~
#ifdef UNX                                                         //~va62I~
        if (Pfnt1->uid!=Pfnt2->uid                                 //~va62I~
        ||  Pfnt1->gid!=Pfnt2->gid)                                //~va62I~
        	uidnesw=1;                                             //~va62I~
#endif                                                             //~va62I~
//      if (Pfnt1->fattr==Pfnt2->fattr)                            //~va71R~
//      if ((Pfnt1->fattr&~FNT_SLINKLOOP)==(Pfnt2->fattr&~FNT_SLINKLOOP))//~va71I~//~vaa0R~
        if ((Pfnt1->fattr&~(ULONG)FNT_SLINKLOOP)==(Pfnt2->fattr&~(ULONG)FNT_SLINKLOOP))//~vaa0I~
        {                                                          //~va62I~
#ifdef UNX                                                         //~va62I~
          if (uidnesw)                                             //~va62I~
	        comp2[1]='%';        //attr match but uid unmatch      //~va62I~
          else                                                     //~va62I~
#endif                                                             //~va62I~
	        comp2[1]=' ';                                          //~v1.bR~
#if defined(W32) || defined(UNX)                                   //~va71I~
            if (Pfnt1->slink && Pfnt2->slink && strcmp(Pfnt1->slink,Pfnt2->slink))//~va71I~
            {                                                      //~va71I~
	        	comp2[1]=SLINK_TARGET_UNMATCH;                     //~va71I~
	        	attrSLINKnesw=1;                                   //~va71I~
            }                                                      //~va71I~
#endif                                                             //~va71I~
        }                                                          //~va62I~
		else                                                       //~v1.bI~
        {                                                          //~v1.kI~
          if (Sdir1dossw!=Sdir2dossw)	//dos and unix compare     //~v2.3I~
	        comp2[1]='?';                                          //~v2.3R~
          else                                                     //~v2.3I~
          {                                                        //~v2.3I~
        	attrnesw=1;	//time stamp not equal                     //~v1.kI~
            UTRACEP("attrne %s=%x,%s=%x\n",Pfnt1->fnm,Pfnt1->fattr,Pfnt2->fnm,Pfnt2->fattr);//~va71I~
	        comp2[1]='*';                                          //~v1.bR~
	        attrRnesw=((Pfnt1->fattr&FILE_READONLY)!=(Pfnt2->fattr&FILE_READONLY));//~v1.uI~
	        attrHnesw=((Pfnt1->fattr&FILE_HIDDEN  )!=(Pfnt2->fattr&FILE_HIDDEN  ));//~v1.uI~
	        attrSnesw=((Pfnt1->fattr&FILE_SYSTEM  )!=(Pfnt2->fattr&FILE_SYSTEM  ));//~v1.uI~
           if (Sdir1dossw && Sdir2dossw)	//both dos type dir    //~v2.3R~
	        attrAnesw=((Pfnt1->fattr&FILE_ARCHIVED)!=(Pfnt2->fattr&FILE_ARCHIVED));//~v1.uI~
#ifdef UNX                                                         //~v2.3I~
	        attrRWXnesw=(FILE_GETMODE(Pfnt1->fattr)!=FILE_GETMODE(Pfnt2->fattr));//~v2.3I~
#endif //UNX/!UNX                                                  //~v2.3I~
#if defined(W32) || defined(UNX)                                   //~va71I~
	        attrSLINKnesw=((Pfnt1->fattr&FILE_SLINK  )!=(Pfnt2->fattr&FILE_SLINK  ));//~va71I~
            if (Pfnt1->slink && Pfnt2->slink && strcmp(Pfnt1->slink,Pfnt2->slink))//~va71R~
            {                                                      //~va71I~
	        	comp2[1]=SLINK_TARGET_UNMATCH;                     //~va71I~
	        	attrSLINKnesw=1;                                   //~va71I~
            }                                                      //~va71I~
#endif                                                             //~va71I~
          }                                                        //~v2.3I~
		}                                                          //~v1.kI~
        comp2[3]=0;                                                //~v1.aI~
		comp=comp2;                                                //~v1.aM~
		if (*ts1==*ts2)
        {                                                          //~va6cI~
//printf("diff1sec %d<-->%d\n",Pfnt1->sec1,Pfnt2->sec1);             //~va6cI~//~va6bR~
//      	diff1sec=Pfnt1->sec1-Pfnt2->sec1;                      //~va6cI~//~vaa0R~
        	diff1sec=(int)(Pfnt1->sec1-Pfnt2->sec1);               //~vaa0I~
          if (diff1sec>0)                                          //~va6cI~
          {                                                        //~va6cI~
			comp2[0]=')';                                          //~va6cI~
            ts2secsw=1;                                            //~va6cI~
        	tsnesw=1;	//time stamp not equal                     //~va6cI~
          }                                                        //~va6cI~
          else                                                     //~va6cI~
          if (diff1sec<0)                                          //~va6cI~
          {                                                        //~va6cI~
			comp2[0]='(';                                          //~va6cI~
            ts2secsw=1;                                            //~va6cI~
        	tsnesw=1;	//time stamp not equal                     //~va6cI~
          }                                                        //~va6cI~
          else                                                     //~va6cI~
			comp2[0]='=';                                          //~v1.aR~
        }                                                          //~va6cI~
		else	
        {                                                          //~v1.kI~
        	tsnesw=1;	//time stamp not equal                     //~v1.kI~
			if (*ts1 > *ts2)
            {                                                      //~v23gI~
	        	tshighsw=1;	//dir1>dir2                            //~v23gI~
              if (diff2sec(*ts1,*ts2))                             //~va69R~
              {                                                    //~va69I~
				comp2[0]=')';                                      //~va69R~
                ts2secsw=1;                                        //~va69I~
              }                                                    //~va69I~
              else                                                 //~va69I~
				comp2[0]='>';                                      //~v1.aR~
            }                                                      //~v23gI~
            else                                                   //~v1.aR~
            {                                                      //~v23gI~
	        	tslowsw=1;	//dir1<dir2                            //~v23gI~
              if (diff2sec(*ts2,*ts1))                             //~va69R~
              {                                                    //~va69I~
				comp2[0]='(';                                      //~va69R~
                ts2secsw=1;                                        //~va69I~
              }                                                    //~va69I~
              else                                                 //~va69I~
				comp2[0]='<';                                      //~v1.aR~
            }                                                      //~v23gI~
		}                                                          //~v1.kI~
		if (Pfnt1->fsz==Pfnt2->fsz)                                //~v1.aI~
        {                                                          //~v1.aI~
            comp2[2]='=';                                          //~v1.aI~
            samesw=(comp[0]=='='&& (comp[1]==' '||comp[1]=='?'));  //~v2.3R~
            if (Sfilecompsw && bothfilesw)    //file bincomp option//~va1BI~
                if (filecomp(Pfnt1,Pfnt2))//unmatch                //~va1BI~
                {                                                  //~va1BI~
                    contentsnesw=1;                                //~va1BR~
					comp2[2]='!';                                  //~va1BI~
                    samesw=0;	                                   //~va1BI~
              		if (Sfilecompsw & COMP_BY_XFC)    //file bincomp option//~va4uI~
                		filecompbyxfc(Pfnt1,Pfnt2);                //~va4uI~
                }                                                  //~va1BI~
//          if (comp[0]=='=') 	                                   //~v1.kR~
//          	samesw2=1;	//date and size match                  //~v1.kR~
        }                                                          //~v1.aI~
        else                                                       //~v1.aI~
        {                                                          //~v1.kI~
        	sizenesw=1;	//time stamp not equal                     //~v1.kI~
            if ((Sfilecompsw & 2) && bothfilesw     //file bincomp option//~va43R~
            &&  !filecomptext(Pfnt1,Pfnt2))//match                 //~va43R~
            {                                                      //~va43I~
			    comp2[2]='^';                                      //~va43I~
                Ssizenetextcompokctr++;                            //~va43I~
            }                                                      //~va43I~
            else                                                   //~va43I~
            {                                                      //~va4uI~
			if (Pfnt1->fsz < Pfnt2->fsz)                           //~v1.aI~
	            comp2[2]='<';                                      //~v1.aI~
            else                                                   //~v1.aI~
	            comp2[2]='>';                                      //~v1.aI~
	            if (Sfilecompsw & COMP_BY_XFC)                     //~va4uI~
    				filecompbyxfc(Pfnt1,Pfnt2);                    //~va4uI~
            }                                                      //~va4uI~
		}                                                          //~v1.kI~
//      bothdirsw=(int)(Pfnt1->fattr & Pfnt2->fattr & FILE_DIRECTORY);	//both dir//~va1BR~
//      bothfilesw=( !(Pfnt1->fattr & FILE_DIRECTORY)              //~va1BR~
//      		   &&!(Pfnt2->fattr & FILE_DIRECTORY) );           //~va1BR~
//printf("%s attrsw=%d,bothdirsw=%d\n",Pfnt1->fnm,attrnesw,bothdirsw);//@@@@//~v1.lR~
        if (bothfilesw)                                            //~v1.kI~
        {                                                          //~v1.kI~
        	Scontentsnecnt+=contentsnesw;                          //~va1BR~
        	Ssizenecnt+=sizenesw;                                  //~v1.kI~
        	Stsnecnt  +=tsnesw;                                    //~v1.kI~
        	Sts2seccnt  +=ts2secsw;                                //~va69I~
        	Sattrnecnt+=attrnesw;                                  //~v1.kI~
#ifdef UNX                                                         //~va62I~
        	Suidnecnt+=uidnesw;                                    //~va62I~
#endif //UNX/!UNX                                                  //~va62I~
            Samecnt   +=samesw;                                    //~v1.kI~
	        SattrRnecnt+=attrRnesw;                                //~v1.uI~
	        SattrHnecnt+=attrHnesw;                                //~v1.uI~
	        SattrSnecnt+=attrSnesw;                                //~v1.uI~
	        SattrAnecnt+=attrAnesw;                                //~v1.uI~
#ifdef UNX                                                         //~v2.3I~
	        SattrRnecnt+=attrRWXnesw;                              //~v2.3I~
#endif //UNX/!UNX                                                  //~v2.3I~
#if defined(W32)||defined(UNX)                                     //~va71I~
	        SattrSLINKnecnt+=attrSLINKnesw;                        //~va71I~
#endif //UNX/!UNX                                                  //~va71I~
		}                                                          //~v1.kI~
        else                                                       //~v1.kI~
        	if (bothdirsw)                                         //~v1.kI~
            {                                                      //~v1.kI~
        		Ssizenecntdir+=sizenesw;                           //~v1.kI~
        		Stsnecntdir  +=tsnesw;                             //~v1.kI~
        		Sts2seccntdir+=ts2secsw;                           //~va69I~
        		Sattrnecntdir+=attrnesw;                           //~v1.kI~
#ifdef UNX                                                         //~va62I~
        		Suidnecntdir +=uidnesw;                            //~va62I~
#endif //UNX/!UNX                                                  //~va62I~
            	Samecntdir   +=samesw;                             //~v1.kI~
                SattrRnecntdir+=attrRnesw;                         //~v1.uI~
                SattrHnecntdir+=attrHnesw;                         //~v1.uI~
                SattrSnecntdir+=attrSnesw;                         //~v1.uI~
                SattrAnecntdir+=attrAnesw;                         //~v1.uI~
#ifdef UNX                                                         //~v2.3I~
                SattrRnecntdir+=attrRWXnesw;                       //~v2.3I~
#endif //UNX/!UNX                                                  //~v2.3I~
#if defined(W32)||defined(UNX)                                     //~va71I~
	        	SattrSLINKnecntdir+=attrSLINKnesw;                 //~va71I~
#endif //UNX/!UNX                                                  //~va71I~
        	}                                                      //~v1.kI~
	}
	else
    {                                                              //~va9fI~
		if (Pfnt1)
			comp="is DIR-1 only";
		else
			comp="is DIR-2 only";
	    if (Uneqswo)      //print only member                      //~va9fI~
        	putsw=1;                                               //~va9fI~
    }                                                              //~va9fI~

	pos+=sprintf(pos," %s",comp);                                  //~v1.8R~
	if (Pfnt1&&Pfnt2&&!samesw)
		pos=tsedit(pos,Pfnt2);
	strcat(pos++,"\n");

  if (!putsw)   //not "ONLY" case                                  //~va9fI~
  {                                                                //~vaa0I~
    if (Uneqsws)      //size chk                                   //~v23eI~
    {                                                              //~va62I~
    	if (Uneqswt)         //ts chk                              //~v23eI~
          switch(Uneqswt)                                          //~v23gI~
          {                                                        //~v23gI~
          case 2:     //Low                                        //~v23gI~
			putsw=sizenesw||tslowsw;	//unmatch one of both      //~v23gI~
            break;                                                 //~v23gI~
          case 3:     //High                                       //~v23gI~
			putsw=sizenesw||tshighsw;	//unmatch one of both      //~v23gI~
            break;                                                 //~v23gI~
          default:                                                 //~v23gI~
			putsw=sizenesw||tsnesw;	//unmatch one of both          //~v23eI~
          }                                                        //~v23gI~
        else                 //size chk only                       //~v23eI~
        	putsw=sizenesw;  //size unmatch                        //~v23eI~
#ifdef UNX                                                         //~va62I~
        if (Uneqswu)	//uid chk                                  //~va62I~
        	putsw|=uidnesw;  //uid cvhk                            //~va62I~
#endif //UNX/!UNX                                                  //~va62I~
    }                                                              //~va62I~
    else			//ignore size                                  //~v23eI~
    {                                                              //~va62I~
    	if (Uneqswt)         //ts chk only                         //~v23eI~
          switch(Uneqswt)                                          //~v23gI~
          {                                                        //~v23gI~
          case 2:     //Low                                        //~v23gI~
			putsw=tslowsw;	//unmatch one of both                  //~v23gI~
            break;                                                 //~v23gI~
          case 3:     //High                                       //~v23gI~
			putsw=tshighsw;	//unmatch one of both                  //~v23gI~
            break;                                                 //~v23gI~
          default:                                                 //~v23gI~
			putsw=tsnesw;	//unmatch one of both                  //~v23eI~
          }                                                        //~v23gI~
        else                 //no chk size/ts                      //~v23eI~
#ifdef UNX                                                         //~va62I~
        if (Uneqswu)	//uid chk                                  //~va62I~
        	putsw|=uidnesw;  //uid cvhk                            //~va62I~
        else                                                       //~va62I~
#endif //UNX/!UNX                                                  //~va62I~
	    if (!Uneqswo)      //not only "ONLY",other unmatch part    //~va9fI~
        	putsw=1;  		//put if unmatch only sw               //~v23eI~
    }                                                              //~va62I~
  }                                                                //~vaa0I~
	if (!Uneqsw || !samesw) //print all or unmatch
      if (putsw)                                                   //~v23eR~
      {                                                            //~va62I~
#ifdef UNX                                                         //~va62I~
       	if (uidnesw)                                               //~va62I~
	    	pos+=sprintf(pos-1,"(u/g=%4d/%4d :: %4d/%4d)\n",       //~va62R~
        				Pfnt1->uid,Pfnt1->gid,Pfnt2->uid,Pfnt2->gid)-1;//~va62I~
#endif //UNX/!UNX                                                  //~va62I~
//	    fwrite(line,1,(unsigned int)((ULONG)pos-(ULONG)line),stdout); //stdout //v1.4r//~va65R~
#ifdef W32UNICODE                                                  //~va91I~
	    ufwriteWCONS(line,1,(unsigned int)((ULPTR)pos-(ULPTR)line),stdout); //stdout //v1.4r//~va91R~
#else                                                              //~va91I~
	    fwrite(line,1,(unsigned int)((ULPTR)pos-(ULPTR)line),stdout); //stdout //v1.4r//~va65I~
#endif                                                             //~va91I~
      }                                                            //~va62I~
    if (bothdirsw)	//both dir                                     //~v1.hI~
    {                                                          //~v1.hI~//~v1.hI~
        samesw-=2;	//-1:match,-2:unmatch                      //~v1.hI~//~v1.hI~
//      Samecntdir2+=samesw2;                                  //~v1.hR~//~v1.kR~
	}                                                          //~v1.hI~//~v1.hI~
//  else                                                       //+v1.hI~//~v1.kR~
//      Samecnt2+=samesw2;                                     //~v1.hR~//~v1.kI~
	return samesw;
}//lineprint
//**********************************************************************
//* file name compare for sort
//*  return code: -1: ent1<ent2
//*                0: ent1=ent2
//*                1: ent1>ent2
//**********************************************************************
int compare(const void *ent1,const void *ent2)
{
	UINT len1,len2,len1c,len2c,len;                                //~v1.eI~
    int rc;                                                        //~v1.eI~
//*************	                                                   //~v1.eI~
//  len1=strlen(ent1);                                             //~v1.eI~//~vaa1R~
    len1=(UINT)strlen(ent1);                                       //~vaa1I~
//  if (*((char*)ent1+len1-1)=='\\')                               //~v1.tR~
//  if (xdcpathlen((UCHAR*)(ULONG)ent1)==(int)len1)                //~va1BR~//~va65R~
    if (xdcpathlen((UCHAR*)(ULPTR)ent1)==(int)len1)                //~va65I~
//  if (Scomppathlen1==(int)len1)                                  //~v262R~
    	len1c=len1-1;                                              //~v264R~
    else                                                           //~v264R~
    	len1c=len1;                                                //~v1.eI~
//  len2=strlen(ent2);                                             //~v1.eI~//~vaa1R~
    len2=(UINT)strlen(ent2);                                       //~vaa1I~
//  if (*((char*)ent2+len2-1)=='\\')                               //~v1.tR~
//  if (xdcpathlen((UCHAR*)(ULONG)ent2)==(int)len2)                //~va1BR~//~va65R~
    if (xdcpathlen((UCHAR*)(ULPTR)ent2)==(int)len2)                //~va65I~
//  if (Scomppathlen2==(int)len2)                                  //~v262R~
    	len2c=len2-1;                                              //~v264R~
    else                                                           //~v264R~
    	len2c=len2;                                                //~v1.eI~
    len=min(len1c,len2c);                                          //~v1.eI~
//printf("compare sub l1=%d,l2=%d,f1=%s,f2=%s\n",len1c,len2c,ent1,ent2);//@@@@//~v264R~
//  if (rc=xdcfnmcmp((void*)(ULONG)ent1,(void*)(ULONG)ent2,len),rc)//~va1BR~//~va65R~
    if (rc=xdcfnmcmp((void*)(ULPTR)ent1,(void*)(ULPTR)ent2,len),rc)//~va65I~
    	return rc;                                                 //~v1.eI~
    if (rc=(int)len1c-(int)len2c,rc)                               //~v1.eR~
    	return rc;                                                 //~v1.eR~
//  return (int)len1-(int)len2;                                    //~v1.kR~
    rc=(int)len1-(int)len2;                                        //~v1.kI~
    if (rc)                                                        //~v1.kI~
    {                                                              //~va17I~
      if (rc<0)          //len1<len2   file and dir                //~v1.uI~
        Sfileanddircnt++;                                          //~v1.uI~
      else               //dir and fir                             //~v1.uI~
        Sdirandfilecnt++;                                          //~v1.uR~
    }                                                              //~va17I~
//printf("compare sub rc=%d,l1=%d,l2=%d,f1=%s,f2=%s\n",rc,len1c,len2c,ent1,ent2);//@@@@//~v264R~
    return rc;                                                     //~v1.kI~
}//compare
//*******************************************************          //~v2.3I~
//*get file path name length(length containing last '\' or '/' from top)//~v2.3I~
//*parm 1:filename                                                 //~v2.3I~
//*return:length, <0 if err                                        //~v2.3I~
//*******************************************************          //~v2.3I~
int xdcpathlen(char *Pfilename)                                    //~v2.3I~
{                                                                  //~v2.3I~
    char *pc;                                                      //~v2.3I~
//*********************************                                //~v2.3I~
//for unix filename                                                //~v2.3I~
	if (*Pfilename=='/')		//unix pattern                     //~v2.3I~
    {                                                              //~v2.3I~
    	if (pc=ustrrchr2(Pfilename,'/'),!pc)                       //~v256R~
        	return -16;     //avoid -1                             //~v2.3I~
//    	return (int)((ULONG)pc-(ULONG)Pfilename)+1;                //~v2.3I~//~va65R~
    	return (int)((ULPTR)pc-(ULPTR)Pfilename)+1;                //~va65I~
    }                                                              //~v2.3I~
//for dos filename                                                 //~v2.3I~
	if (*(Pfilename+1)==':' && *(Pfilename+2)=='\\')		//unix pattern//~v2.3I~
    {                                                              //~v2.3I~
	    if (pc=ustrrchr2(Pfilename,'\\'),!pc)                      //~v2.3I~
    	    return -16;     //avoid -1                             //~v2.3I~
//    	return (int)((ULONG)pc-(ULONG)Pfilename)+1;                //~v2.3I~//~va65R~
    	return (int)((ULPTR)pc-(ULPTR)Pfilename)+1;                //~va65I~
    }                                                              //~v2.3I~
//by exe envirinment                                               //~v2.3I~
    return PATHLEN(Pfilename);                                     //~v2.3I~
}//xdcpathlen                                                      //~v2.3I~
//*******************************************************          //~v257I~
//*chk last dir sepc                                               //~v257I~
//*parm 1:filename                                                 //~v257I~
//*parm 2:pathlen                                                  //~v257I~
//*return:1:last is DIR_SEPC                                       //~v257I~
//*******************************************************          //~v257I~
int xdcchklastsepc(char *Pfilename,int Plen)                       //~v257I~
{                                                                  //~v257I~
    int len;                                                       //~v257I~
//*********************************                                //~v257I~
//for unix filename                                                //~v257I~
	len=(int)strlen(Pfilename);                                    //~v257I~
	if (*Pfilename=='/')		//unix pattern                     //~v257I~
    {                                                              //~v257I~
    	if (*(Pfilename+len-1)!='/')                               //~v257I~
        	return 0;                                              //~v257I~
    }                                                              //~v257I~
//for dos filename                                                 //~v257I~
	if (*(Pfilename+1)==':' && *(Pfilename+2)=='\\')		//unix pattern//~v257I~
    {                                                              //~v257I~
    	if (*(Pfilename+len-1)!='\\')                              //~v257I~
        	return 0;                                              //~v257I~
    }                                                              //~v257I~
    if (Plen<0)                                                    //~vazAI~
    	return 1;	//last is sepc                                 //~vazAI~
    return (xdcpathlen(Pfilename)==Plen);                          //~v257I~
}//xdcchklastsepc                                                  //~v257I~
//*******************************************************          //~v2.3I~
//*strcat dir seperator                                            //~v2.3I~
//*parm 1:fullpath filename                                        //~v2.3R~
//*return:none                                                     //~v2.3I~
//*******************************************************          //~v2.3I~
void xdcdirsepcat(char *Pfilename)                                 //~v2.3I~
{                                                                  //~v2.3I~
//*********************************                                //~v2.3I~
	if (*Pfilename=='/')		//unix pattern                     //~v2.3I~
    	strcat(Pfilename,"/");                                     //~v2.3I~
    else                                                           //~v2.3I~
	if (*(Pfilename+1)==':' && *(Pfilename+2)=='\\')		//unix pattern//~v2.3I~
    	strcat(Pfilename,"\\");                                    //~v2.3I~
    else                                                           //~v2.3I~
    	strcat(Pfilename,DIR_SEPS);		                           //~v2.3I~
    return;                                                        //~v2.3I~
}//xdcdirsepcat                                                    //~v2.3I~
//*******************************************************          //~v2.3I~
//*filename compare                                                //~v2.3I~
//*parm 1/2:filename                                               //~v2.3I~
//*parm  3 :filename len                                           //~v2.3I~
//*return:none                                                     //~v2.3I~
//*******************************************************          //~v2.3I~
int xdcfnmcmp(char *Pfnm1,char *Pfnm2,UINT Plen)                   //~v2.3R~
{                                                                  //~v2.3I~
//*********************************                                //~v2.3I~
//printf("xdcfnmcmp %s -- %s\n",Pfnm1,Pfnm2);                      //~v254R~
  switch(Scaseoption)     //filename compare case option           //~v231I~
  {                                                                //~v231I~
  case 0:                //default                                 //~v231I~
//  if (!Sdir1dossw && !Sdir2dossw)	//both unix type               //~v261R~
    if (!Sdir1dossw || !Sdir2dossw)	//one is unix type             //~v261I~
		return memcmp(Pfnm1,Pfnm2,Plen);                           //~v2.3I~
	return memicmp(Pfnm1,Pfnm2,Plen);                              //~v2.3I~
  case 1:			//insensitive                                  //~v231I~
	return memicmp(Pfnm1,Pfnm2,Plen);                              //~v231I~
  }                                                                //~v231I~
	return memcmp(Pfnm1,Pfnm2,Plen);                               //~v231I~
}//xdcfnmcmp                                                       //~v2.3R~
//**********************************************************************//~va1zM~
//* create top dir in intermediate file by -P parameter            //~va1zM~
//**********************************************************************//~va1zM~
void xdcinterpath(char *Pfpath,char *Pinterpath)                   //~va1zM~
{                                                                  //~va1zM~
    int len,len2;                                                  //~va1zI~
//*************************                                        //~va1zM~
	len=(int)strlen(Pfpath);                                       //~va1BR~
    if (!xdcchklastsepc(Pfpath,-1))   //-1:return 1 if last is sep //~vazAR~
    {                                                              //~vazAI~
    	xdcdirsepcat(Pfpath);                                      //~vazAR~
    	len++;                                                     //~vazAR~
    }                                                              //~vazAI~
	if ((*(Pinterpath+1)==':' && *(Pinterpath+2)=='\\')		//unix pattern//~va1zR~
    ||   *(Pinterpath)=='/')	//from root                        //~va1zR~
    {                                                              //~va1zM~
    	len2=(int)strlen(Pinterpath);                              //~va1BR~
        if (len>len2	//path parm include fpath in intermedeate file//~va1zM~
        ||  xdcfnmcmp(Pfpath,Pinterpath,(UINT)len))   //path err   //~va1BR~
        {                                                          //~va1zM~
            printf("path parm(%s) is not subdir in intermediate file",Pinterpath);//~va1zM~
            exit(8);                                               //~va1zM~
        }                                                          //~va1zM~
        strcpy(Pfpath+len,Pinterpath+len);                         //~va1zM~
    }                                                              //~va1zM~
    else                                                           //~va1zM~
    	strcpy(Pfpath+len,Pinterpath);                             //~va1zM~
    return;                                                        //~va1zM~
}//xdcinterpath                                                    //~va1zM~
//**********************************************************************
// find and open input file
//* parm1 :output area
//* parm2 :file tbl entry
//* parm3 :same sw(if on print space)
//*  return : output next addr
//**********************************************************************
char * tsedit(char *Pline,FNTBL* Pfnt)
{
	char *lastpos;
//  char attrwk[8];                                                //~va71R~
    char attrwk[12];                                               //~va71I~
//******************
  if (Sdir1dossw!=Sdir2dossw)	//dos and unix compare             //~v2.3I~
    attrwk[0]=0;                //skip attr print                  //~v2.3I~
  else                                                             //~v2.3I~
#ifdef UNX                                                         //~v2.3I~
//  ueditfattr(Pfnt->fattr,attrwk,UEFA_SZ|UEFA_DIR);//stringz,set DIR also//~v234R~
    ueditfattr(Pfnt->fattr,attrwk,UEFA_SZ|UEFA_UFMT);//@dsgt fmt   //~v234R~
#else                                                              //~v2.3I~
//  ueditfattr((UCHAR)Pfnt->fattr,attrwk,UEFA_SZ|UEFA_DIR);//stringz,set DIR also//~va17R~
    ueditfattr(Pfnt->fattr,attrwk,UEFA_SZ|UEFA_DIR);//stringz,set DIR also//~va17I~
#endif                                                             //~v2.3I~
#if defined(W32)||defined(UNX)                                     //~va71I~
	if (FILE_ISSLINK(Pfnt->fattr))                                 //~va71I~
    	strcat(attrwk,"@");                                        //~va71I~
    else                                                           //~va71I~
    	strcat(attrwk," ");                                        //~va71I~
#endif                                                             //~va71I~
#ifdef LFSSUPP                                                     //~va30I~
	lastpos=Pline+sprintf(Pline," (%02d-%02d-%02d %02d:%02d %s%10s)",//~va30I~
    	    	    		 		(Pfnt->fdt.year+80)%100,       //~va30I~
        	    			 		Pfnt->fdt.month,               //~va30I~
           					 		Pfnt->fdt.day,                 //~va30I~
      		    			 		Pfnt->ftm.hours,               //~va30I~
          					 		Pfnt->ftm.minutes,             //~va30I~
                                    attrwk,                        //~va30I~
    	          					ufileeditsz(0,Pfnt->fsz,0));   //~va30I~
#else                                                              //~va30I~
	lastpos=Pline+sprintf(Pline," (%02d-%02d-%02d %02d:%02d %s%10ld)",//~v1.wR~
    	    	    		 		(Pfnt->fdt.year+80)%100,       //~v2.2R~
        	    			 		Pfnt->fdt.month,
           					 		Pfnt->fdt.day,
      		    			 		Pfnt->ftm.hours,
          					 		Pfnt->ftm.minutes,
                                    attrwk,                        //~v1.wI~
    	          					Pfnt->fsz);
#endif                                                             //~va30I~
	return lastpos;
}//tsedit
//*********************************************************************//~va1BI~
//* return 0:fully equall                                          //~va1BI~
//*        1:unmatch exist                                         //~va1BI~
//*        4:encountered error condition                           //~va1BI~
//*********************************************************************//~va1BI~
int filecomp(FNTBL *Pfnt1,FNTBL *Pfnt2)                            //~va1BI~
{                                                                  //~va1BI~
//  FILE *openfile(char *Pfile,char *Popt,int Pmsgsw);             //~va43R~
	UINT getinput(char *Pfnm,FILE *Pfh,char *Pbuff,UINT Preqsz);   //~va1BI~
	FILE *fh1,*fh2;                                                //~va1BI~
    UINT readlen1,readlen2;                                        //~va1BI~
    int rc=0;                                                      //~va1BR~
    UCHAR *buff1,*buff2;                                           //~va1BR~
static char *Sbuff1=0,*Sbuff2=0;                                   //~va1BR~
	char fpath1[_MAX_PATH],fpath2[_MAX_PATH];                      //~va1BI~
//*****************************                                    //~va1BI~
	strcpy(fpath1,Sfilecomppath1);                                 //~va1BI~
	strcpy(fpath2,Sfilecomppath2);                                 //~va1BI~
    strcat(fpath1,Pfnt1->fnm);                                     //~va1BI~
    strcat(fpath2,Pfnt2->fnm);                                     //~va1BI~
	fh1=openfile(fpath1,"rb",0);	//exit when open faile         //~va1BR~
	fh2=openfile(fpath2,"rb",0);	//exit when open faile         //~va1BR~
    if (!(buff1=Sbuff1))                                           //~va1BI~
	    if (!(buff1=malloc(BUFFSZ)))                               //~va1BI~
			uerrexit("malloc failed for buff1,size=%d)",0,BUFFSZ); //~va1BI~
    if (!(buff2=Sbuff2))                                           //~va1BI~
	    if (!(buff2=malloc(BUFFSZ)))                               //~va1BI~
			uerrexit("malloc failed for buff2,size=%d)",0,BUFFSZ); //~va1BI~
    for (;;)                                                       //~va1BI~
    {                                                              //~va1BI~
		readlen1=getinput(fpath1,fh1,buff1,BUFFSZ);                //~va1BR~
		readlen2=getinput(fpath2,fh2,buff2,BUFFSZ);                //~va1BR~
        if (readlen1!=readlen2)                                    //~va1BR~
        {                                                          //~va1BI~
        	rc=4;                                                  //~va1BI~
		    break;                                                 //~va1BR~
        }                                                          //~va1BI~
		if (memcmp(buff1,buff2,readlen1))                          //~va1BR~
        {                                                          //~va1BI~
        	rc=3;                                                  //~va1BI~
            break;                                                 //~va1BI~
        }                                                          //~va1BI~
        if (readlen1<BUFFSZ)                                       //~va1BI~
        	break;                                                 //~va1BI~
    }                                                              //~va1BI~
    fclose(fh1);                                                   //~va1BI~
    fclose(fh2);                                                   //~va1BI~
    return rc;                                                     //~va1BI~
}//filecomp                                                        //~va1BR~
//*********************************************************************//~va43I~
//* return 0:fully equall                                          //~va43I~
//*        1:unmatch exist                                         //~va43I~
//*        4:encountered error condition                           //~va43I~
//*********************************************************************//~va43I~
int filecomptext(FNTBL *Pfnt1,FNTBL *Pfnt2)                        //~va43I~
{                                                                  //~va43I~
	FILE *fh1,*fh2;                                                //~va43I~
    UINT readlen1,readlen2;                                        //~va43I~
    int rc=0;                                                      //~va43I~
    UCHAR *buff1,*buff2,*pc1,*pc2,*pc;                             //~va43R~
static char *Sbuff1=0,*Sbuff2=0;                                   //~va43I~
	char fpath1[_MAX_PATH],fpath2[_MAX_PATH];                      //~va43I~
//*****************************                                    //~va43I~
	strcpy(fpath1,Sfilecomppath1);                                 //~va43I~
	strcpy(fpath2,Sfilecomppath2);                                 //~va43I~
    strcat(fpath1,Pfnt1->fnm);                                     //~va43I~
    strcat(fpath2,Pfnt2->fnm);                                     //~va43I~
	fh1=openfile(fpath1,"r",0);	//exit when open faile             //~va43I~
	fh2=openfile(fpath2,"r",0);	//exit when open faile             //~va43I~
    if (!(buff1=Sbuff1))                                           //~va43I~
	    if (!(buff1=malloc(BUFFSZ)))                               //~va43I~
			uerrexit("malloc failed for buff1,size=%d)",0,BUFFSZ); //~va43I~
    if (!(buff2=Sbuff2))                                           //~va43I~
	    if (!(buff2=malloc(BUFFSZ)))                               //~va43I~
			uerrexit("malloc failed for buff2,size=%d)",0,BUFFSZ); //~va43I~
    for (;;)                                                       //~va43I~
    {                                                              //~va43I~
        readlen1=readlen2=0;                                       //~va43I~
		pc1=fgets(buff1,BUFFSZ,fh1);                               //~va43R~
		pc2=fgets(buff2,BUFFSZ,fh2);                               //~va43R~
        if (pc1)                                                   //~va43I~
        {                                                          //~va43I~
            pc=memchr(buff1,'\n',BUFFSZ);                          //~va43I~
            if (pc)                                                //~va43I~
//              readlen1=(ULONG)pc-(ULONG)buff1+1;                 //~va43I~//~va65R~
//              readlen1=(ULPTR)pc-(ULPTR)buff1+1;                 //~va65I~//~va9ER~
                readlen1=(UINT)((ULPTR)pc-(ULPTR)buff1+1);         //~va9EI~
        }                                                          //~va43I~
        if (pc2)                                                   //~va43I~
        {                                                          //~va43I~
            pc=memchr(buff2,'\n',BUFFSZ);                          //~va43I~
            if (pc)                                                //~va43I~
//              readlen2=(ULONG)pc-(ULONG)buff2+1;                 //~va43I~//~va65R~
//              readlen2=(ULPTR)pc-(ULPTR)buff2+1;                 //~va65I~//~va9ER~
                readlen2=(UINT)((ULPTR)pc-(ULPTR)buff2+1);         //~va9EI~
        }                                                          //~va43I~
        if (!readlen1 && !readlen2)                                //~va43I~
        	break;                                                 //~va43I~
        if (readlen1==readlen2)                                    //~va43I~
        {                                                          //~va43I~
			if (memcmp(buff1,buff2,readlen1))                      //~va43I~
        	{                                                      //~va43I~
        		rc=3;                                              //~va43I~
            	break;                                             //~va43I~
        	}                                                      //~va43I~
        }                                                          //~va43I~
        else                                                       //~va43I~
	    {                                                          //~va43I~
    	  	rc=4;                                                  //~va43I~
		    break;                                                 //~va43I~
        }                                                          //~va43I~
    }                                                              //~va43I~
    fclose(fh1);                                                   //~va43I~
    fclose(fh2);                                                   //~va43I~
    return rc;                                                     //~va43I~
}//filecomptext                                                    //~va43I~
//*********************************************************************//~va4uI~
//* return 0:SAME is BOTH                                          //~va4uI~
//*        1:unmatch exist                                         //~va4uI~
//*********************************************************************//~va4uI~
int filecompbyxfc(FNTBL *Pfnt1,FNTBL *Pfnt2)                       //~va4uI~
{                                                                  //~va4uI~
    int rc=0,len,redirectsw;                                       //~va4uR~
	char fpath1[_MAX_PATH],fpath2[_MAX_PATH];                      //~va4uI~
	char cmd[_MAX_PATH*4],*cmdstr;                                 //~va4uR~
	char redirect[_MAX_PATH];                                      //~va4uI~
	char suffix[12],*pc,*pc2;                                      //~va4uI~
#ifdef W32UNICODE                                                  //~va91I~
	char cmdstrx[_MAX_PATH*4];                                     //~va91I~
    int cmdstrxlen;                                                //~va91I~
#endif                                                             //~va91I~
//*****************************                                    //~va4uI~
	strcpy(fpath1,Sfilecomppath1);                                 //~va4uI~
	strcpy(fpath2,Sfilecomppath2);                                 //~va4uI~
    strcat(fpath1,Pfnt1->fnm);                                     //~va4uI~
    strcat(fpath2,Pfnt2->fnm);                                     //~va4uI~
    redirectsw=(Scompcmdredirect && *Scompcmdredirect);            //~va4uI~
    if (Scompcmd && *Scompcmd)                                     //~va4uR~
    {                                                              //~va4uI~
    	cmdstr=Scompcmd;                                           //~va4uR~
        if (redirectsw)                                            //~va4uI~
        {                                                          //~va4uI~
            pc=strchr(cmdstr,' ');                                 //~va4uR~
    UTRACEP("cmd=%s,pc=%s\n",cmdstr,pc);                           //~va4uI~
            if (!pc)                                               //~va4uR~
                pc=cmdstr+strlen(cmdstr);                          //~va4uR~
//          len=(ULONG)pc-(ULONG)cmdstr;                           //~va4uR~//~va65R~
//          len=(ULPTR)pc-(ULPTR)cmdstr;                           //~va65I~//~va9ER~
            len=(int)((ULPTR)pc-(ULPTR)cmdstr);                    //~va9EI~
//          pc2=umemrpbrk(cmdstr,"\\/",len);                       //~va4uR~//~vaa0R~
            pc2=umemrpbrk(cmdstr,"\\/",(size_t)len);               //~vaa0I~
            if (pc2)                                               //~va4uR~
                pc2++;                                             //~va4uR~
            else                                                   //~va4uI~
                pc2=cmdstr;                                        //~va4uI~
//          len=(ULONG)pc-(ULONG)pc2;                              //~va4uR~//~va65R~
//          len=(ULPTR)pc-(ULPTR)pc2;                              //~va65I~//~va9ER~
            len=(int)((ULPTR)pc-(ULPTR)pc2);                       //~va9EI~
            len=min(len,8);                                        //~va4uR~
//          UmemcpyZ(suffix,pc2,len);                              //~va4uR~//~vaa0R~
            UmemcpyZ(suffix,pc2,(size_t)len);                      //~vaa0I~
        }                                                          //~va4uI~
    }                                                              //~va4uI~
    else                                                           //~va4uI~
    {                                                              //~va4uI~
    	strcpy(suffix,"xfc");                                      //~va4uI~
//        if (redirectsw)                                            //~va4uI~//~va51R~
	    	cmdstr="xfc -c";                                       //~va4uR~
    }                                                              //~va4uI~
    if (strchr(cmdstr,'%'))                                        //~va4uI~
	    sprintf(cmd,cmdstr,fpath1,fpath2);                         //~va4uR~
    else                                                           //~va4uI~
	    sprintf(cmd,"%s \"%s\" \"%s\"",cmdstr,fpath1,fpath2);      //~va4uI~
    if (redirectsw)                                                //~va4uI~
    {                                                              //~va4uI~
    	sprintf(redirect,"> \"%s%c.%s.%s\"",Scompcmdredirect,DIR_SEPC,Pfnt1->fnm,suffix);//~va4uR~
    	strcat(cmd,redirect);                                      //~va4uI~
    }                                                              //~va4uI~
    UTRACEP("xfc cmd=%s\n",cmd);                                   //~va4uI~
#ifdef W32UNICODE                                                  //~va91I~
  if (strchr(cmd,UD_NOTLC))                                        //~va91R~
  {                                                                //~va91I~
    ufilecvUD2UDX(UFCVO_STRZ,cmd,strlen(cmd),cmdstrx,sizeof(cmdstrx),&cmdstrxlen);  //by hex notation to avaoid locale translation by system//~va91R~
    UTRACEP("xfc cmdx=%s\n",cmdstrx);                              //~va91I~
	usystem2(UPROC_NOMSG|UPROC_NOOKMSG,cmdstrx);	//no msg       //~va91I~
  }                                                                //~va91I~
  else                                                             //~va91I~
#endif                                                             //~va91I~
	usystem2(UPROC_NOMSG|UPROC_NOOKMSG,cmd);	//no msg           //~va4uR~
    return rc;                                                     //~va4uI~
}//filecompbyxfc                                                   //~va4uI~
//**********************************************************************//~va1BI~
//* open file name                                                 //~va1BI~
//* parm1:open file name                                           //~va1BI~
//* parm2:open option                                              //~va1BI~
//* parm3:msg sw 0:no opened msg,1:display opened msg,-1:return if open err//~va1BI~
//**********************************************************************//~va1BI~
FILE *openfile(char *Pfile,char *Popt,int Pmsgsw)                  //~va1BI~
{                                                                  //~va1BI~
	FILE *file;                                                    //~va1BI~
//****************                                                 //~va1BI~
	if (!(file=fopen(Pfile,Popt)))                                 //~va1BI~
    {                                                              //~va1BI~
    	if (Pmsgsw==-1)                                            //~va1BI~
        	return 0;                                              //~va1BI~
        else                                                       //~va1BI~
			uerrexit("%s open failed rc=%d",0,                     //~va1BI~
					Pfile,errno);                                  //~va1BI~
    }                                                              //~va1BI~
	if (Pmsgsw==1)                                                 //~va1BI~
    	printf("%s opened.",Pfile);                                //~va1BI~
	return file;                                                   //~va1BI~
}//openfile                                                        //~va1BI~
//**********************************************************************//~va1BI~
//* get input up to the size                                       //~va1BI~
//**********************************************************************//~va1BI~
UINT getinput(char *Pfnm,FILE *Pfh,char *Pbuff,UINT Preqsz)        //~va1BI~
{                                                                  //~va1BI~
	UINT readlen;                                                  //~va1BI~
//****************                                                 //~va1BI~
//  readlen=fread(Pbuff,1,Preqsz,Pfh);	//read 1 block             //~va1BI~//~vaa1R~
    readlen=(UINT)fread(Pbuff,1,Preqsz,Pfh);	//read 1 block     //~vaa1I~
//printf("read=%08x,req=%08x\n",readlen,Preqsz);                   //~va1BI~
    if (readlen<Preqsz)                                            //~va1BI~
		if (ferror(Pfh))                                           //~va1BI~
        	uerrexit("\n%s read failed rc=%d,req=%d,read=%d",0,    //~va1BI~
						Pfnm,errno,Preqsz,readlen);                //~va1BI~
	return readlen;                                                //~va1BI~
}//getinput                                                        //~va1BI~
//**********************************************************************//~va6bI~
//* get timezone value                                             //~va6bI~
//**********************************************************************//~va6bI~
void getTZparm(char *Pparm)                                        //~va6bR~
{                                                                  //~va6bI~
	FTIME ft;                                                      //~va6bI~
	int sign=0;                                                    //~va6bR~
	char *pc;                                                      //~va6bI~
//****************                                                 //~va6bI~
	pc=Pparm;                                                      //~va6bI~
	if (*pc=='-')                                                  //~va6bI~
    {                                                              //~va6bI~
//  	sign=CALC_TIME_MINUS;                                      //~va6bI~//~vaa0R~
    	sign=(int)CALC_TIME_MINUS;                                 //~vaa0I~
        pc++;                                                      //~va6bI~
    }                                                              //~va6bI~
    else                                                           //~va6bI~
	if (*pc=='+')                                                  //~va6bI~
        pc++;                                                      //~va6bI~
    if (ugettimeparm(pc,&ft)||ft.twosecs)                          //~va6bR~
    {                                                              //~va6bI~
    	printf("%s:%s:invalid TZ value(%s),TZ parm format is %cTZ[-]hh:mm\n",Spgm,Sver,Pparm,CMDFLAG_PREFIX);//~va6bR~
		exit(4);                                                   //~va6bI~
    }                                                              //~va6bI~
    Stzparm=(ft.hours<<16)|(ft.minutes<<8)|sign;                   //~va6bR~
}//getTZparm                                                       //~va6bR~
//**********************************************************************
//*parameter chk
//**********************************************************************
void parmchk(int parmc,char *parmp[])
{
	FILEFINDBUF3 fstat3;                                           //~v1.sI~
  unsigned char c;    //read char
  char *cptr;         //char ptr work
  char *pc;         //char ptr work                                //~v1.xI~
  int parmno; //parm count work
  int posparmno=0; //parm count work
//int lfnsw=0;                                                     //~va3wR~
  int dirsw1,dirsw2;                                               //~v1.sI~
  int notfsw1=0,notfsw2=0;                                         //~v23fI~
  int len;                                                         //~v252I~
//#ifndef UNX                                                      //~va1dR~
  char fpath[_MAX_PATH],*fprc;                                     //~va1dR~
	FILEFINDBUF3 ffb3;                                             //~va4uI~
//#endif                                                           //~va1dR~
#ifdef W32UNICODE                                                  //~va91I~
  	static char Sdir1x[_MAX_PATH],Sdir2x[_MAX_PATH];               //~va91I~
#endif                                                             //~va91I~
    static char Sfnmpathcopy1[_MAX_PATH];                          //~va9eI~
    static char Sfnmpathcopy2[_MAX_PATH];                          //~va9eI~
    int rcen;                                                      //~va9eI~
    int swfpathcopaypath=0,fecopt=0;                               //~va9hI~
    int swnocopypath=0;                                            //~va9kI~
//*************************
//if (parmc<2 || *parmp[1]=='?')                                   //~va3bR~
  if (parmc<2 || *parmp[1]=='?' || !strcmp(parmp[1],"--help"))     //~va3bR~
  {
    help();
    exit(0);                                                       //~v1.dR~
  }
//*******************************
//* parm process                *
//*******************************
for (parmno=1;parmno<parmc;parmno++)
{                                   
  cptr=parmp[parmno];               
#ifdef UNX                                                         //~v2.3I~
  		if(*cptr=='-')                                             //~v2.3I~
#else                                                              //~v2.3I~
  if(*cptr=='/'||*cptr=='-')        
#endif                                                             //~v2.3I~
  {//option                         
    c=*(++cptr);                      //first option byte
    if (USTRHEADIS_IC(cptr,"TZ"))                                  //~va6bI~
    {                                                              //~va6bI~
        getTZparm(cptr+2);                                         //~va6bI~
        continue;                                                  //~va6bI~
    }                                                              //~va6bI~
    switch(toupper(c))             //option        
    {                                              
//**************************
//* subdir option          *
//**************************
    case '?':                                                      //~v1.xI~
    case 'H':                                                      //~v2.3I~
	    help();                                                    //~v1.xI~
    	exit(0);                                                   //~v1.xI~
      	break;                                                     //~v1.xI~
    case 'A':           //alias                                    //~v1.mI~
//  	if (Slfnsw)                                                //~va3wR~
//      	lfnsw=1;	//previously on                            //~va3wR~
#if defined(W32) || defined(DPMI)                                  //~va3wI~
      	Slfnsw=0;                                                  //~v1.mI~
#endif                                                             //~va3wI~
      	break;                                                     //~v1.mI~
    case 'F':           //file bincomp                             //~va1BI~
    	UTRACEP("F parm %s\n",cptr);                               //~va4uI~
      switch(toupper(*(cptr+1)))                                   //~va43I~
      {                                                            //~va43I~
      case 0:                                                      //~va43I~
      	Sfilecompsw=1;                                             //~va1BI~
        break;                                                     //~va43I~
      case 'T':                                                    //~va43I~
      	Sfilecompsw=3;  //bin and text comp                        //~va43R~
        break;                                                     //~va43I~
      case 'C':                                                    //~va4uI~
      	Sfilecompsw=COMP_BY_XFC;  //using xfc                      //~va4uI~
        Scompcmd=cptr+2;                                           //~va4uR~
        break;                                                     //~va4uI~
      case '+':                                                    //~va9AI~
      	stackMask(&Sqhimask,cptr+2);                               //~va9AI~
      	Sswimask=1;                                                //~va9AI~
        break;                                                     //~va9AI~
      case 'R':                                                    //~va4uI~
      	Scompcmdredirect=cptr+2;                                   //~va4uR~
        if (ufstat(Scompcmdredirect,&ffb3) || !(ffb3.attrFile & FILE_DIRECTORY))//~va4uI~
        {                                                          //~va4uI~
	    	printf("%s:%s:%s is not directory\n",Spgm,Sver,Scompcmdredirect);//~va4uI~
			exit(4);                                               //~va4uI~
        }                                                          //~va4uI~
        break;                                                     //~va4uI~
      default:                                                     //~va43I~
    	printf("%s:%s:invalid option value(%s)\n",Spgm,Sver,parmp[parmno]);//~va43I~
		exit(4);                                                   //~va43I~
      }                                                            //~va43I~
      	break;                                                     //~va1BI~
    case 'L':           //use lfn;                                 //~v1.mI~
//  	Slfnsw=lfnsw;                                              //~va3wR~
        if (*(cptr+1))  //len parm exist                           //~v252I~
        {                                                          //~v252I~
            len=atoi(cptr+1);                                      //~v252I~
            if (!len)                                              //~v252I~
            {                                                      //~v252I~
    			printf("%s:%s:invalid option value(%s)\n",Spgm,Sver,parmp[parmno]);//~v252I~
				exit(4); \
            }                                                      //~v252I~
            if (len>MAX_FILENAMEFLDSZ)                             //~v252I~
            {                                                      //~v252I~
    			printf("%s:%s:filename field size max is %d\n",Spgm,Sver,MAX_FILENAMEFLDSZ);//~v252I~
				exit(4); \
            }                                                      //~v252I~
            Sfilenamefldsz=len;                                    //~v252I~
        }                                                          //~v252I~
      	break;                                                     //~v1.mI~
    case 'S':           //sub dir chk
      Subdirsw=1;
      break;                                
    case 'P':           //sub dir chk                              //~va1zI~
      if (Sinterpath)	                                           //~va1BI~
      	if (Sinterpath2)                                           //~va1BI~
        {                                                          //~va1BI~
            printf("%s:%s:toomany path parm\n",Spgm,Sver);         //~va1BI~
            exit(4); \
        }                                                          //~va1BI~
        else                                                       //~va1BI~
	      	Sinterpath2=cptr+1;                                    //~va1BI~
      else                                                         //~va1BI~
	    Sinterpath=cptr+1;                                         //~va1BR~
      break;                                                       //~va1zI~
    case 'I':           //intermediate fiel use                    //~v1.8I~
	    c=*(++cptr);    //intermediate file ussage                 //~v1.8I~
	    switch(toupper(c))                                         //~v1.8I~
	    {                                                          //~v1.8I~
	    case 'I':       //input                                    //~v1.8I~
			Sintfsw=1;                                             //~v1.8I~
			break;                                                 //~v1.8I~
	    case 'O':       //output                                   //~v1.8I~
			Sintfsw=3;                                             //~v1.8R~
			break;                                                 //~v1.8I~
	    case 'N':       //deny                                     //~v1.dI~
			Sintfsw=0;                                             //~v1.dI~
			break;                                                 //~v1.dI~
	    default:                           //not option            //~v1.8I~
    		printf("%s:%s:invalid option value(%s)\n",Spgm,Sver,parmp[parmno]);//~v1.9R~
			exit(4);                                               //~v1.8I~
		}                                                          //~v1.8I~
      break;                                                       //~v1.8I~
    case 'U':           //print unmatch only
      Uneqsw=1;
      Suneqopt=cptr;                                               //~v23gI~
      for (pc=cptr+1;*pc;pc++)                                     //~v23eI~
          switch (toupper(*pc))                                    //~v23eR~
          {                                                        //~v23eR~
          case 'S':                                                //~v23eR~
                Uneqsws=1;                                         //~v23eR~
                break;                                             //~v23eR~
          case 'T':                                                //~v23eR~
                Uneqswt=1;                                         //~v23eR~
                break;                                             //~v23eR~
          case 'L':                                                //~v23gI~
                Uneqswt=2;                                         //~v23gI~
                break;                                             //~v23gI~
          case 'H':                                                //~v23gI~
                Uneqswt=3;                                         //~v23gI~
                break;                                             //~v23gI~
          case 'O':                                                //~va9fI~
                Uneqswo=1;                                         //~va9fI~
                break;                                             //~va9fI~
#ifdef UNX                                                         //~va62I~
          case 'U':      //select uid/gid unmatch                  //~va62I~
                Uneqswu=1;                                         //~va62I~
                break;                                             //~va62I~
#endif                                                             //~va62I~
          default:                                                 //~v23eR~
                printf("%s:%s:invalid option value(%s)\n",Spgm,Sver,parmp[parmno]);//~v23eR~
                exit(4);                                           //~v23eR~
          }                                                        //~v23eR~
      break;                                
    case 'W':           //work area size                           //~v1.8I~
      tblsz=atoi(cptr+1);                                          //~v1.8I~
      break;                                                       //~v1.8I~
    case 'X':           //work area size                           //~va9gI~
      stackMask(&Sqhxmask,cptr+1);                                 //~va9gI~
      Sswxmask=1;                                                  //~va9gI~
      break;                                                       //~va9gI~
    case '=':           //print dir1 member only v1.3a             //~va9hI~
      switch(toupper(*(cptr+1)))                                   //~va9hI~
      {                                                            //~va9hI~
	  case 'F':           //print dir1 member only v1.3a           //~va9hI~
		swfpathcopaypath=1;                                        //~va9hI~
      	break;                                                     //~va9hI~
	  case 'N':                                                    //~va9kI~
		swnocopypath=1;                                            //~va9kI~
      	break;                                                     //~va9kI~
      default:                                                     //~va9hI~
      	printf("%s:%s:invalid option value(%s)\n",Spgm,Sver,parmp[parmno]);//~va9hI~
        exit(4);                                                   //~va9hI~
      }                                                            //~va9hI~
      break;			//v1.3a                                    //~va9hI~
    case '1':           //print dir1 member only v1.3a
      Dir1sw=1;			//v1.3a
      break;			//v1.3a
    case '2':           //print dir2 member only v1.3a
      Dir2sw=1;			//v1.3a
      break;			//v1.3a
    case 'Y':                                                      //~v1.xI~
        for (pc=cptr+1;*pc;pc++)                                   //~v1.xI~
        {                                                          //~v1.xI~
            switch(toupper(*pc))                                   //~v1.xI~
            {                                                      //~v1.xI~
            case '9':                                              //~v1.xI~
//              Sdbcssw=1;                                         //~va1BR~
                UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set//~v1.xI~
                UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs         //~v1.xI~
                break;                                             //~v231I~
            case 'C':                                              //~v231I~
  				Scaseoption=2;     //filename compare case option  //~v231I~
    			Swcopt|=UFWC_CASE;                                 //~v252I~
                break;                                             //~v231I~
//#ifdef UNX                                                       //~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
            case 'M':                                              //~v266I~
                Gufile_opt&=~GFILEOPT_NOSLINKERRMSG;               //~v266I~
                break;                                             //~v266I~
            case 'S':                                              //~v256I~
  				Sslinkchksw=1;     //chk symbolic link source      //~v256I~
                break;                                             //~v256I~
#endif                                                             //~v256I~
            }                                                      //~v1.xI~
        }                                                          //~v1.xI~
        break;                                                     //~v1.xI~
    case 'N':                                                      //~v1.xI~
        for (pc=cptr+1;*pc;pc++)                                   //~v1.xI~
        {                                                          //~v1.xI~
            switch(toupper(*pc))                                   //~v1.xI~
            {                                                      //~v1.xI~
            case '9':                                              //~v1.xI~
//              Sdbcssw=0;                                         //~va1BR~
                UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set//~v1.xI~
                UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs        //~v1.xI~
                break;                                             //~v233I~
            case 'C':                                              //~v231I~
  				Scaseoption=1;     //filename compare case option(insensitive)//~v231I~
		    	Swcopt&=~UFWC_CASE;                                //~v252I~
                break;                                             //~v231I~
//#ifdef UNX                                                       //~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
            case 'M':                                              //~v266I~
                Gufile_opt|= GFILEOPT_NOSLINKERRMSG;               //~v266I~
                break;                                             //~v266I~
            case 'S':                                              //~v256I~
  				Sslinkchksw=0;     //chk symbolic link source      //~v256I~
                break;                                             //~v256I~
#endif                                                             //~v256I~
            }                                                      //~v1.xI~
        }                                                          //~v1.xI~
        break;                                                     //~v1.xI~
    default:                           //not option
      printf("%s:%s:undefined option parm(%s)\n",Spgm,Sver,parmp[parmno]);//~v1.9R~
      exit(4);
    }//switch  by first option byte                
  }
  else
  {//positional parmno
    posparmno++;
    switch (posparmno)
    {
//**************************
//* dir 1                  *
//**************************
    case  1:          //first parm 
      Dir1=cptr;
      UTRACED("dir1",Dir1,(int)strlen(Dir1));                           //~va91I~//~vaa0R~
#ifdef W32UNICODE                                                  //~va91I~
#ifdef AAA  //UD2WC support UTF8X                                  //~va91I~
	  if (memchr(cptr,UD_UTF8X,strlen(cptr)))                      //~va91I~
	  {                                                            //~va91I~
    	ufilecvUDX2UD(UFCVO_STRZ,cptr,strlen(cptr),Sdir1x,sizeof(Sdir1x),NULL/*outlen*/);//~va91I~
        Dir1=Sdir1x;                                               //~va91I~
      }                                                            //~va91I~
#endif                                                             //~va91I~
#endif                                                             //~va91I~
      break;           
//**************************
//* dir 2                  *
//**************************
    case 2: // 2nd parm
      Dir2=cptr;
      UTRACED("dir2",Dir2,(int)strlen(Dir2));                           //~va91I~//~vaa0R~
#ifdef W32UNICODE                                                  //~va91I~
#ifdef AAA  //UD2WC support UTF8X                                  //~va91I~
	  if (memchr(cptr,UD_UTF8X,strlen(cptr)))                      //~va91I~
	  {                                                            //~va91I~
    	ufilecvUDX2UD(UFCVO_STRZ,cptr,strlen(cptr),Sdir2x,sizeof(Sdir2x),NULL/*outlen*/);//~va91I~
        Dir2=Sdir2x;                                               //~va91I~
      }                                                            //~va91I~
#endif                                                             //~va91I~
#endif                                                             //~va91I~
      break;           
//**************************
//* file mask              *
//**************************
    case 3: 
//    Mask=cptr;                                                   //~va9AR~
      stackMask(&Sqhimask,cptr);                                   //~va9AI~
      Sswimask=1;                                                  //~va9AI~
      break;           
//************************************
    default:
      printf("%s:%s:too many positional parameter(%s)\n",Spgm,Sver,cptr);//~v1.9R~
      exit(4);                                         
    }//switch by parmno
  }//option or posparm 
}//for all parm        

	Mask=getallmaskstring(0,&Sqhimask,&Sqhxmask);                            //~va9AR~//~va9BR~
  if (posparmno<2)
	{
      printf("%s:%s:specify 2 file name\n",Spgm,Sver);             //~v1.9R~
      exit(4);
	}
	if (WILDCARD(Dir1) || WILDCARD(Dir2))                          //~v1.9I~
    {                                                              //~v1.9I~
		printf("%s:%s:specify wild card as 3'rd(Mask) parameter\n",Spgm,Sver);//~v1.9R~
		exit(4);                                                   //~v1.9I~
	}                                                              //~v1.9I~
//    if (Sintfsw)                                                 //~v234R~
//    {                                                            //~v234R~
//        if (*Dir1==INTMFID && *Dir2==INTMFID)                    //~v234R~
//        {                                                        //~v234R~
//            printf("%s:%s:specify only one intermediate file(ex. @xxx)\n",//~v234R~
//                    Spgm,Sver);                                  //~v234R~
//            exit(4);                                             //~v234R~
//        }                                                        //~v234R~
//        if (*Dir1!=INTMFID && *Dir2!=INTMFID)                    //~v234R~
//        {                                                        //~v234R~
//  		printf("%s:%s:specify a intermediate file(ex. @xxx) for one of dir name\n",//~v1.sR~
//  				Spgm,Sver);                                    //~v1.sR~
//  		exit(4);                                               //~v1.sR~
//  	  rcen=fileeditname_copypath(0,Dir1,Dir2,Sfnmpathcopy1,Sfnmpathcopy2);//~va9eI~//~va9hR~
        if (swnocopypath)                                          //~va9kI~
          rcen=0;                                                  //~va9kI~
        else                                                       //~va9kI~
        {                                                          //~va9kI~
		  if (swfpathcopaypath)                                    //~va9hI~
          	fecopt=FECO_FULLPATH;                                  //~va9hR~
    	  rcen=fileeditname_copypath(fecopt,Dir1,Dir2,Sfnmpathcopy1,Sfnmpathcopy2);//~va9hI~
        }                                                          //~va9kI~
          UTRACEP("fileeditname_copypath rc=%d,path1=%s,path2=%s\n",rcen,Sfnmpathcopy1,Sfnmpathcopy2);//~va9eR~
          if (rcen==1)                                             //~va9eI~
          	Dir1=Sfnmpathcopy1;                                    //~va9eI~
          else                                                     //~va9eI~
          if (rcen==2)                                             //~va9eI~
          	Dir2=Sfnmpathcopy2;                                    //~va9eI~
          fprc=ufullpath(fpath,Dir1,sizeof(fpath));                //~va1dI~
          fprc=fprc;    //for compiler warning                     //~va52I~
#ifndef UNX                                                        //~v23cI~
//        if (ufullpath(fpath,Dir1,sizeof(fpath))                  //~va1dR~
          if (fprc                                                 //~va1dI~
          &&  ROOTDIR(fpath))                                      //~v23cR~
          {                                                        //~v23cR~
          	dirsw1=1;                                              //~v23cR~
            memset(&fstat3,0,sizeof(fstat3));                      //~v23cR~
			UCBITON(fstat3.attrFile,FILE_DIRECTORY);               //~v23cR~
          }                                                        //~v23cR~
          else                                                     //~v23cR~
#endif                                                             //~v23cI~
         {                                                         //~v23fI~
//  		dirsw1=(!ufstat(Dir1,&fstat3)                          //~v23fR~
//  		        && UCBITCHK(fstat3.attrFile,FILE_DIRECTORY));  //~v23fI~
//  		if (ufstat(Dir1,&fstat3))                              //~va1dR~
    		if (ufstat(fpath,&fstat3))                             //~va1dI~
            {                                                      //~v23fI~
                notfsw1=1;                                         //~v23fI~
                dirsw1=0;                                          //~v23fI~
            }                                                      //~v23fI~
            else                                                   //~v23fI~
				dirsw1=UCBITCHK(fstat3.attrFile,FILE_DIRECTORY);   //~v23fR~
         }                                                         //~v23fI~
            Sfstat31=fstat3;                                       //~v234I~
          fprc=ufullpath(fpath,Dir2,sizeof(fpath));                //~va1dI~
#ifndef UNX                                                        //~v23cI~
//        if (ufullpath(fpath,Dir2,sizeof(fpath))                  //~va1dR~
          if (fprc                                                 //~va1dI~
          &&  ROOTDIR(fpath))                                      //~v23cR~
          {                                                        //~v23cR~
          	dirsw2=1;                                              //~v23cR~
            memset(&fstat3,0,sizeof(fstat3));                      //~v23cR~
			UCBITON(fstat3.attrFile,FILE_DIRECTORY);               //~v23cR~
          }                                                        //~v23cR~
          else                                                     //~v23cR~
#endif                                                             //~v23cI~
          {                                                        //~v23fI~
//  		dirsw2=(!ufstat(Dir2,&fstat3)                          //~v23fR~
//  		        && UCBITCHK(fstat3.attrFile,FILE_DIRECTORY));  //~v23fR~
//  		if (ufstat(Dir2,&fstat3))                              //~va1dR~
    		if (ufstat(fpath,&fstat3))                             //~va1dI~
            {                                                      //~v23fI~
                notfsw2=1;                                         //~v23fI~
                dirsw2=0;                                          //~v23fI~
            }                                                      //~v23fI~
            else                                                   //~v23fI~
   	         	dirsw2=UCBITCHK(fstat3.attrFile,FILE_DIRECTORY);   //~v23fR~
          }                                                        //~v23fI~
            Sfstat32=fstat3;                                       //~v234I~
    if (Sintfsw)                                                   //~v234I~
    {                                                              //~v234I~
            if ((dirsw1 && dirsw2)                                 //~v1.sR~
//          ||  (!dirsw1 && !dirsw2))                              //~v234R~
               )  //both dir                                       //~v234I~
            {                                                      //~v1.sI~
//  			printf("%s:%s:%ci flag specified for both is directory or both is file case\n",//~v234R~
    			printf("%s:%s:%ci flag specified for both is directory case\n",//~v234I~
				  				Spgm,Sver,CMDFLAG_PREFIX);         //~v232R~
				exit(4);                                           //~v1.sI~
			}                                                      //~v1.sI~
            else                                                   //~v234I~
            if ((!dirsw1 && !dirsw2))  //both file                 //~v234I~
            {                                                      //~v234I~
                if (Sintfsw==3)                                    //~v234I~
                {                                                  //~v234I~
					printf("%s:%s:%cio flag specified for both is file case\n",//~v234I~
				  				Spgm,Sver,CMDFLAG_PREFIX);         //~v234I~
					exit(4);                                       //~v234I~
                }                                                  //~v234I~
			}                                                      //~v234I~
            if (!dirsw1)		//file1 treate as intermediate file//~v1.sR~
	    	{                                                      //~v1.sI~
    	    	Sinterfnm=Dir1;                                    //~v1.sI~
	            if (Sintfsw==1) //input                            //~v1.sI~
    	            Dir1=INTMFIDS;                                 //~v1.sI~
        	    else                                               //~v1.sI~
	        	    Dir1=0;                                        //~v1.sI~
			}                                                      //~v1.sI~
//          else                //file2 is treated as intermediate file//~v234R~
            if (!dirsw2)		//file2 is file                    //~v234I~
            {                                                      //~v1.sI~
              if (!dirsw1)      //both is file                     //~v234I~
              {                                                    //~v234I~
                Sinterfnm1=Dir2;                                   //~v234I~
                Sinterfnm2=Dir2;                                   //~v234I~
                Sintfsw=2;   //                                    //~v234I~
                Dir2=INTMFIDS;                                     //~v234I~
              }                                                    //~v234I~
              else                                                 //~v234I~
              {                                                    //~v234I~
                Sinterfnm=Dir2;                                    //~v1.sI~
                if (Sintfsw==1) //input                            //~v1.sI~
                {                                                  //~v1.sI~
                    Sintfsw=2;   //input as dir2                   //~v1.sI~
                    Dir2=INTMFIDS;                                 //~v1.sI~
                }                                                  //~v1.sI~
                else                                               //~v1.sI~
                    Dir2=0;                                        //~v1.sI~
              }                                                    //~v234I~
            }                                                      //~v1.sI~
                                                                   //~v1.sI~
//        }                                                        //~v234R~
//        else                                                     //~v234R~
//        {                                                        //~v234R~
//        if (*Dir1==INTMFID)                                      //~v234R~
//        {                                                        //~v234R~
//            Sinterfnm=Dir1+1;                                    //~v234R~
//            if (Sintfsw==1) //input                              //~v234R~
//                Dir1=INTMFIDS;                                   //~v234R~
//            else                                                 //~v234R~
//                Dir1=0;                                          //~v234R~
//            if (!ufstat(Sinterfnm,&fstat3)                       //~v234R~
//            &&  UCBITCHK(fstat3.attrFile,FILE_DIRECTORY))        //~v234R~
//            {                                                    //~v234R~
//                printf("%s:%s:@(intermediate fileID) is specified for directory",//~v234R~
//                                Spgm,Sver);                      //~v234R~
//                exit(4);                                         //~v234R~
//            }                                                    //~v234R~
//        }                                                        //~v234R~
//        else                                                     //~v234R~
//        {                                                        //~v234R~
//            Sinterfnm=Dir2+1;                                    //~v234R~
//            if (Sintfsw==1) //input                              //~v234R~
//            {                                                    //~v234R~
//                Sintfsw=2;   //input as dir2                     //~v234R~
//                Dir2=INTMFIDS;                                   //~v234R~
//            }                                                    //~v234R~
//            else                                                 //~v234R~
//                Dir2=0;                                          //~v234R~
//            if (!ufstat(Sinterfnm,&fstat3)                       //~v234R~
//            &&  UCBITCHK(fstat3.attrFile,FILE_DIRECTORY))        //~v234R~
//            {                                                    //~v234R~
//                printf("%s:%s:@(intermediate fileID) is specified for directory",//~v234R~
//                                Spgm,Sver);                      //~v234R~
//                exit(4);                                         //~v234R~
//            }                                                    //~v234R~
//        }                                                        //~v234R~
//        }//no @ on both file                                     //~v234R~
	}//Sintfsw                                                     //~v1.8I~
    else                                                           //~v234R~
//        if (*Dir1==INTMFID || *Dir2==INTMFID)                    //~v234R~
//            printf("%s:%s:warning:%ci option is needed to use intermediate file file\n",//~v234R~
//                    Spgm,Sver,CMDFLAG_PREFIX);                   //~v234R~
	if (!dirsw1 || !dirsw2)  //both file                           //~v234I~
    {                                                              //~v234I~
        if (notfsw1)                                               //~v23fI~
        {                                                          //~va9eI~
          	if (rcen==-1)                                          //~va9eR~
				fileeditname_copypath_err(0,Dir1,Dir2);            //~va9eI~
            ufilenotfound(Dir1,4);                                 //~v23fI~
        }                                                          //~va9eI~
        if (notfsw2)                                               //~v23fI~
        {                                                          //~va9eI~
          	if (rcen==-2)                                          //~va9eR~
				fileeditname_copypath_err(0,Dir1,Dir2);            //~va9eI~
            ufilenotfound(Dir2,4);                                 //~v23fI~
        }                                                          //~va9eI~
//  	printf("%s:%s:Both is not dir,%ci flag is required for intermediate file use\n",//+vad1R~
   		uerrmsg("%s:%s:Not both are directory,%ci flag is required for intermediate file use.",//+vad1I~
   		        "%s:%s:両方ともがディレクトリーではない、中間ファイルを使用するときは %ci オプションを指定してください",//+vad1I~
					Spgm,Sver,CMDFLAG_PREFIX);                     //~v234I~
		exit(4);                                                   //~v234I~
	}                                                              //~v234I~
    if (Dir1sw||Dir2sw) //sir1/2 only sw                           //~v1.9I~
        if (Sintfsw==3)                                            //~v1.9I~
        {                                                          //~v1.9I~
			printf("%s:%s:Intermediate file output and dir1/2 only switch is exclusive.\n",//~v1.9I~
					Spgm,Sver);                                    //~v1.9I~
			exit(4);                                               //~v1.9I~
		}                                                          //~v1.9I~
    if (Sinterpath)                                                //~va1zI~
    {                                                              //~va1BI~
    	if (Sintfsw==0||Sintfsw==3)	//not intermediate file as input case//~va1zI~
        {                                                          //~va1zI~
			printf("%s:%s:Path specification is valid with Intermediate file input.",//~va1zR~
					Spgm,Sver);                                    //~va1zI~
			exit(4);                                               //~va1zI~
		}                                                          //~va1zI~
        if (Sinterpath2)    //2 path parm                          //~va1BI~
        	if (!Sinterfnm2)	//both is file                     //~va1BI~
            {                                                      //~va1BI~
                printf("%s:%s:duplicated Path parm,but both is not intermediate file.",//~va1BR~
                        Spgm,Sver);                                //~va1BI~
                exit(4);                                           //~va1BI~
            }                                                      //~va1BI~
    }                                                              //~va1BI~
    if (Sfilecompsw)                                               //~va1BI~
		if (Sintfsw)	//intermideate input/output sw             //~va1BI~
        {                                                          //~va1BI~
            printf("%s:%s:FileCompare option is invalid when Intermediate file use.",//~va1BI~
                    Spgm,Sver);                                    //~va1BI~
            exit(4);                                               //~va1BI~
        }                                                          //~va1BI~
}//parmchk
//**********************************************************************//~v234I~
//* intermediate file disply                                       //~v234I~
//**********************************************************************//~v234I~
void interfmsg(int Pdirid)                                         //~v234I~
{                                                                  //~v234I~
    char *fnm,cdate[12],ctime2[12];                                 //~v234I~
    FILEFINDBUF3 *pfstat3;                                         //~v234I~
    char mask[_MAX_PATH];                                          //~v259I~
    char interpath[_MAX_PATH+16];                                  //~vazAI~
//*************************                                        //~v234I~
    if (Pdirid==1)                                                 //~v234I~
    {                                                              //~v234I~
    	fnm=Sinterfnm1;                                            //~v234I~
        pfstat3=&Sfstat31;                                         //~v234R~
    }                                                              //~v234I~
    else                                                           //~v234I~
    {                                                              //~v234I~
      if (Sinterfnm2)                                              //~v236I~
    	fnm=Sinterfnm2;                                            //~v234I~
      else                                                         //~v236I~
    	fnm=Sinterfnm1;                                            //~v236I~
        pfstat3=&Sfstat32;                                         //~v234R~
    }                                                              //~v234I~
    ufdateedit(pfstat3->fdateLastWrite,"YY/MM/DD",cdate);          //~v234I~
    uftimeedit(pfstat3->ftimeLastWrite,"HH:MM:SS",ctime2);          //~v234I~
    if (*Sintfmask[Pdirid])                                        //~v259I~
    	sprintf(mask,"\"%s\"",Sintfmask[Pdirid]);                  //~v259R~
    else                                                           //~v259I~
    	sprintf(mask,"None");                                      //~v259R~
    if (Sinterpath)                                                //~vazAI~
    	sprintf(interpath,"* Path : %s",Sinterpath);               //~vazAR~
    else                                                           //~vazAI~
    	sprintf(interpath,"* path=%s","None");                     //~vazAI~
//  printf("********** dir%d is by %s (%s %s) * Mask: %s *********\n",//~vazAR~
//  				Pdirid,fnm,cdate,ctime2,mask);                 //~vazAR~
    printf("********** dir%d is by %s (%s %s) * Mask: %s %s *********\n",//~vazAI~
    				Pdirid,fnm,cdate,ctime2,mask,interpath);       //~vazAI~
#ifdef LFSSUPP                                                     //~va30I~
    if (!Slfsintf[Pdirid])                                         //~va30I~
	    printf("!!! This file created under non LargeFileSystem support !!!\n");//~va30R~
#endif                                                             //~va30I~
    return;                                                        //~v234R~
}//interfmsg                                                       //~v234I~
//**********************************************************************//~va91I~
//* set ud fmt fnm to output line                                  //~va91I~
//* ret:write len                                                  //~va91I~
//**********************************************************************//~va91I~
int setlinefnm(char *Pline,char *Pfnm,char *Pfnameedit,int Pfldsz,char **Ppcontpos)//~va91R~
{                                                                  //~va91I~
    int len,resleno;                                               //~va91R~
    char *pc,*pco,*contpos,*pce;                                   //~va91R~
#ifdef UTF8UTF16                                                   //~va91I~
    int opt,swud;                                                  //~va91I~
    char wklc[8];                                                  //~va91M~
    int lclen,rc2,u8len,chklen,chwidth;                            //~va91I~
#endif                                                             //~va91I~
//*********************************                                //~va91I~
//    ufilecvUD2LC(0,Pfnm,strlen(Pfnm),wkfnm,sizeof(wkfnm),&len);  //~va91R~
//    len=sprintf(Pline,Pfnameedit,wkfnm);                         //~va91R~
//    if (len>Pfldsz)                                              //~va91R~
//    {                                                            //~va91R~
//        len=Pfldsz;                                              //~va91R~
//        *Ppcontpos=Pline+len;                                    //~va91R~
//    }                                                            //~va91R~
    UTRACED("inp",Pfnm,(int)strlen(Pfnm));                              //~va91I~//~vaa0R~
#ifdef UTF8UTF16                                                   //~va91I~
    opt=UTFCVO_ERRREP|('?'/*XEUTF_ERRREPCH*/<<8);                  //~vaucI~//~va91I~
#endif                                                             //~va91I~
#ifdef UTF8UTF16                                                   //~va91I~
    for (pc=Pfnm,pce=pc+strlen(pc),pco=Pline,swud=0,resleno=Pfldsz;pc<pce && resleno;)//~va91I~
#else                                                              //~va91I~
    for (pc=Pfnm,pce=pc+strlen(pc),pco=Pline       ,resleno=Pfldsz;pc<pce && resleno;)//~va91I~
#endif                                                             //~va91I~
    {                                                              //~va91I~
#ifdef UTF8UTF16                                                   //~va91I~
        if (*pc==UD_NOTLC)                                         //~va91I~
        {                                                          //~va91I~
        	if (swud)                                              //~va91I~
        		*pco++=*pc++;                                      //~va91I~
            else                                                   //~va91I~
            {                                                      //~va91I~
        		*pco++=*pc++;                                      //~va91I~
        		*pco++=*pc++;                                      //~va91I~
            }                                                      //~va91I~
            swud=!swud;                                            //~va91I~
            continue;                                              //~va91I~
        }                                                          //~va91I~
        if (swud)                                                  //~va91I~
        {                                                          //~va91I~
            u8len=UTF8CHARLEN(*pc);                                //~va91R~
            if (u8len)                                             //~va91I~
            {                                                      //~va91I~
				rc2=utfcvf2l(opt,wklc,pc,u8len,&chklen,&lclen,&chwidth);//chk output column//~vaucR~//~va91R~
    			UTRACEP("%s:rc2=%x,lclen=%d,chklen=%d,charwidth=%d\n",UTT,rc2,lclen,chklen,chwidth);//~va91R~
                if (rc2)                                           //~va91I~
                    lclen=1;                                       //~va91I~
                if (resleno>=lclen)                                //~va91R~
                {                                                  //~va91R~
                    memcpy(pco,pc,u8len);                          //~va91R~
                    pco+=chklen;                                   //~va91R~
                    resleno-=lclen;                                //~va91R~
                }                                                  //~va91R~
                else                                               //~va91R~
                    *pco++='.',resleno--;                          //~va91R~
            }                                                      //~va91I~
            else                                                   //~va91I~
            	*pco++='.',resleno--;                              //~va91I~
            pc+=u8len;                                             //~va91I~
        }                                                          //~va91I~
        else                                                       //~va91I~
#endif                                                             //~va91I~
        {                                                          //~va91I~
        	*pco++=*pc++,resleno--;                                //~va91R~
        }                                                          //~va91I~
    }                                                              //~va91I~
#ifdef UTF8UTF16                                                   //~va91I~
    if (swud)                                                      //~va91I~
    	*pco++=UD_NOTLC;                                           //~va91I~
#endif                                                             //~va91I~
    if (resleno)                                                   //~va91R~
    {                                                              //~va91I~
//  	memset(pco,' ',resleno);                                   //~va91R~//~vaa0R~
    	memset(pco,' ',(size_t)resleno);                           //~vaa0I~
        pco+=resleno;                                              //~va91R~
        contpos=NULL;                                              //~va91R~
    }                                                              //~va91I~
    else                                                           //~va91I~
    	contpos=pco;                                               //~va91I~
    *Ppcontpos=contpos;                                            //~va91I~
    len=PTRDIFF(pco,Pline);                                        //~va91I~
    UTRACED("out",Pline,len);                                      //~va91I~
    return len;                                                    //~va91I~
}//setlinefnm                                                      //~va91I~
//**********************************************************************//~va9gI~
void stackMask(UQUEH *Ppqh,char *Pmask)                            //~va9gI~
{                                                                  //~va9gI~
    int len;                                                       //~va9gI~
    PMASKLIST pfnl;                                                //~va9gI~
//*********************************                                //~va9gI~
//  len=strlen(Pmask);                                             //~va9gI~//~vaa0R~
    len=(int)strlen(Pmask);                                        //~vaa0I~
//  pfnl=ucalloc(MASKLISTSZ+len,1);                                //~va9gI~//~vaa0R~
    pfnl=ucalloc(MASKLISTSZ+(size_t)len,1);                        //~vaa0I~
//  memcpy(pfnl->MLname,Pmask,len);                                //~va9gR~//~vaa0R~
    memcpy(pfnl->MLname,Pmask,(size_t)len);                        //~vaa0I~
	UENQ(UQUE_END,Ppqh,pfnl);                                      //~va9gI~
}//stackMask                                                       //~va9gI~
//**********************************************************************//~va9gI~
//*rc=0:unmatch,1:match                                            //~va9CI~
//**********************************************************************//~va9CI~
int chkMask(int Popt,UQUEH *Ppqh,char *Pmask)                      //~va9gR~
{                                                                  //~va9gI~
    int rc=0,len;                                                  //~va9gR~
    PMASKLIST pfnl=0;                                              //~va9gI~
    char *pmask,*pfnm;                                             //~va9gR~
    char wkmask[_MAX_PATH];                                        //~va9gI~
    int opt;                                                       //~va9zI~
//*********************************                                //~va9gI~
	pfnm=Pmask;                                                    //~va9gI~
    if (Popt & CMO_NOEXPAND)	//mach with DIR_SEPC was followed case//~va9gI~
    {                                                              //~va9gI~
//      len=strlen(Pmask)-1;                                       //~va9gR~//~vaa0R~
        len=(int)strlen(Pmask)-1;                                  //~vaa0I~
        if (*(Pmask+len)=='/'                                      //~va9gR~
        ||  *(Pmask+len)=='\\')                                    //~va9gR~
        {                                                          //~va9gR~
//          UmemcpyZ(wkmask,Pmask,len);                            //~va9gR~//~vaa0R~
            UmemcpyZ(wkmask,Pmask,(size_t)len);                    //~vaa0I~
            pfnm=wkmask;                                           //~va9gR~
        }                                                          //~va9gR~
    }                                                              //~va9gI~
	for (pfnl=UGETQTOP(Ppqh);pfnl;pfnl=UGETQNEXT(pfnl))            //~va9gI~
    {                                                              //~va9gI~
    	pmask=pfnl->MLname;                                        //~va9gI~
        if (WILDCARD(pmask))                                       //~va9gI~
        {                                                          //~va9gI~
//			rc=ufilewildcomp(UFWC_CASE_DEFAULT|UFWC_DOS_DEFAULT,pfnm,pmask,0/*Pdbcsp*/);//~va9gR~//~va9zR~
//			opt=UFWC_CASE_DEFAULT|UFWC_DOS_DEFAULT|UFWC_0BYTE;     //~va9zI~//~va9AR~
  			opt=Swcopt|UFWC_0BYTE;                                 //~va9AI~
  			rc=ufilewildcomp(opt,pfnm,pmask,0/*Pdbcsp*/);          //~va9zI~
            UTRACEP("chkMask wildcomp rc=%d %s-%s\n",rc,Pmask,pmask);//~va9gR~
            if (!rc)                                               //~va9gI~
            	break;                                             //~va9gI~
        }                                                          //~va9gI~
        else                                                       //~va9gI~
        {                                                          //~va9gI~
        	rc=LFNM_STRCMP(pmask,pfnm);                            //~va9gR~
            UTRACEP("chkMask comp rc=%d %s-%s\n",rc,Pmask,pmask);  //~va9gR~
            if (!rc)                                               //~va9gR~
            	break;                                             //~va9gI~
        }                                                          //~va9gI~
    }                                                              //~va9gI~
    rc=pfnl!=0;                                                    //~va9gI~
    UTRACEP("chkMask rc=%d\n",rc);                                 //~va9gR~
    return rc;                                                     //~va9gI~
}//chkMask                                                         //~va9gR~
//**********************************************************************//~va9gI~
void printxmask()                                                  //~va9gI~
{                                                                  //~va9gI~
    PMASKLIST pfnl=0;                                              //~va9gI~
    char *pmask;                                                   //~va9gI~
	UQUEH *pqh;                                                    //~va9gR~
//*********************************                                //~va9gI~
	pqh=&Sqhxmask;                                                 //~va9gI~
	for (pfnl=UGETQTOP(pqh);pfnl;pfnl=UGETQNEXT(pfnl))             //~va9gI~
    {                                                              //~va9gI~
    	pmask=pfnl->MLname;                                        //~va9gI~
        printf("=== Xmask : %s\n",pmask);                          //~va9gR~
    }                                                              //~va9gI~
}//stackMask                                                       //~va9gI~
//**********************************************************************//~va9AI~
void printimask()                                                  //~va9AI~
{                                                                  //~va9AI~
    PMASKLIST pfnl=0;                                              //~va9AI~
    char *pmask;                                                   //~va9AI~
	UQUEH *pqh;                                                    //~va9AI~
//*********************************                                //~va9AI~
	pqh=&Sqhimask;                                                 //~va9AI~
	for (pfnl=UGETQTOP(pqh);pfnl;pfnl=UGETQNEXT(pfnl))             //~va9AI~
    {                                                              //~va9AI~
    	pmask=pfnl->MLname;                                        //~va9AI~
        printf("=== F+mask: %s\n",pmask);                          //~va9AR~
    }                                                              //~va9AI~
}//stackMask                                                       //~va9AI~
//**********************************************************************//~va9AI~
char *getallmaskstring(int Popt,UQUEH *Ppqh,UQUEH *Ppqhx)                       //~va9AR~//~va9BR~
{                                                                  //~va9AI~
    PMASKLIST pfnl=0;                                              //~va9AI~
    char *pmask,*pc0,*pc;                                          //~va9AI~
	UQUEH *pqh;                                                    //~va9AI~
    int len=0;                                                     //~va9AI~
//*********************************                                //~va9AI~
	pqh=Ppqh;                                                      //~va9BR~
	for (pfnl=UGETQTOP(pqh);pfnl;pfnl=UGETQNEXT(pfnl))             //~va9AI~
    {                                                              //~va9AI~
    	pmask=pfnl->MLname;                                        //~va9AI~
        len+=(int)strlen(pmask)+1;                                 //~va9AI~
    }                                                              //~va9AI~
	pqh=Ppqhx;                                                     //~va9BR~
	for (pfnl=UGETQTOP(pqh);pfnl;pfnl=UGETQNEXT(pfnl))             //~va9BI~
    {                                                              //~va9BI~
    	pmask=pfnl->MLname;                                        //~va9BI~
        len+=(int)strlen(pmask)+1;                                 //~va9BI~
    }                                                              //~va9BI~
    if (!len)                                                      //~va9AI~
    	return "";                                                 //~va9AI~
    pc0=pc=umalloc((size_t)len+8);                                   //~va9AI~//~va9BR~
	pqh=Ppqh;                                                      //~va9BI~
	for (pfnl=UGETQTOP(pqh);pfnl;pfnl=UGETQNEXT(pfnl))             //~va9AI~
    {                                                              //~va9AI~
    	pmask=pfnl->MLname;                                        //~va9AI~
        len=(int)strlen(pmask);                                    //~va9AI~
        memcpy(pc,pmask,(size_t)len);                              //~va9AI~
        pc+=len;                                                   //~va9AI~
        *pc++=',';                                                 //~va9AR~
    }                                                              //~va9AI~
	pqh=Ppqhx;                                                     //~va9BI~
	if (UGETQCTR(pqh))                                             //~va9BR~
    {                                                              //~va9BI~
        strcpy(pc,"-X:");                                          //~va9BI~
        pc+=3;                                                     //~va9BI~
        for (pfnl=UGETQTOP(pqh);pfnl;pfnl=UGETQNEXT(pfnl))         //~va9BI~
        {                                                          //~va9BI~
            pmask=pfnl->MLname;                                    //~va9BI~
            len=(int)strlen(pmask);                                //~va9BI~
            memcpy(pc,pmask,(size_t)len);                          //~va9BI~
            pc+=len;                                               //~va9BI~
            *pc++=',';                                             //~va9BI~
        }                                                          //~va9BI~
    }                                                              //~va9BI~
    *(pc-1)=0;                                                     //~va9AR~
    return pc0;                                                    //~va9AI~
}//getallmaskstring                                                //~va9AI~
//**********************************************************************
//* write help msg  
//**********************************************************************
void help(void)
{
#define HELPMSG uerrhelpmsg(stdout,stderr,                         //~v1.xI~
//***************************************                          //~v1.xI~
HELPMSG                                                            //~v1.xI~
"%s:%s(%c): directory compare utility program\n",                  //~v1.xR~
"%s:%s(%c): ディレクトリー比較ユーティリティー\n",                 //~v1.xI~
					Spgm,Sver,OSTYPE);                             //~v1.xI~
        HELPMSG                                                    //~va9eI~
"*******************************************************************************\n", //80 column limit indicator//~va9eI~
"*******************************************************************************\n");//~va9eI~
HELPMSG                                                            //~v1.xI~
//"format:  %s dir1 dir2 [mask] [%cS] [%cU[S][T]] [%c1] [%c2] [%cIx] [%cWsz]\n",//~va1zR~
//"形式  :  %s dir1 dir2 [mask] [%cS] [%cU[S][T]] [%c1] [%c2] [%cIx] [%cWsz]\n",//~va1zR~
//"format:  %s dir1 dir2 [mask] [%cPpath] [%cS] [%cU[S][T]] [%c1] [%c2] [%cix] [%cWsz]\n",//~va4uR~
//"形式  :  %s dir1 dir2 [mask] [%cPpath] [%cS] [%cU[S][T]] [%c1] [%c2] [%cix] [%cWsz]\n",//~va4uR~
"format:  %s dir1 dir2 [mask] [%cOptions]\n",                      //~va4uI~
"形式  :  %s dir1 dir2 [mask] [%cOptions]\n",                      //~va4uI~
					Spgm,                                          //~v2.3R~
                    CMDFLAG_PREFIX,                                //~va1zI~
                    CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX//~v2.3I~
					);//v1.3r                                      //~v2.3I~
HELPMSG                                                            //~v1.xI~
"         dir1/2:dir name\n",                                      //~v1.xR~
"         dir1/2:ディレクトリー名\n");                             //~v1.xI~
HELPMSG                                                            //~v1.xI~
"                or intermediate file name(use with %cI flag)\n",  //~v2.3R~
"                または 中間ワークファイル(%cI フラグが必要)\n",   //~v2.3R~
					CMDFLAG_PREFIX);                               //~v2.3I~
HELPMSG                                                            //~va9eI~
"               :cnveniently use the letter \"=\" which means same path.\n",//~va9eR~
"               :パス名に\"=\"を指定することで指定を簡略化できる\n");//~va9eR~
HELPMSG                                                            //~va9eI~
"                format n=[m] : n=skip count(0--9,default=0), m=copy count.\n",//~va9eR~
"                形式 n=[m] : n=スキップ数(0--9,省略値=0), m=コピー数\n");//~va9eR~
HELPMSG                                                            //~va9hI~
"                (See also %c=F option).\n",                       //~va9hI~
"                (%c=F オプションも参照)\n",                       //~va9hI~
					CMDFLAG_PREFIX);                               //~va9hI~
#ifdef UNX                                                         //~va9eI~
HELPMSG                                                            //~va9eI~
"                (ex) %s  a/b/c/d/e/f/g  x/=\n",                   //~va9eR~
"                (例) %s  a/b/c/d/e/f/g  x/=\n",                   //~va9eR~
		PGM);                                                      //~va9eI~
HELPMSG                                                            //~va9eI~
"                     ===> %s a/b/c/d/e/f/g  x/a/b/c/d/e/f/g\n",   //~va9eR~
"                     ===> %s a/b/c/d/e/f/g  x/a/b/c/d/e/f/g\n",   //~va9eR~
		PGM);                                                      //~va9eI~
#else                                                              //~va9eI~
HELPMSG                                                            //~va9eI~
"                (ex) %s  a\\b\\c\\d\\e\\f\\g  x\\=\n",            //~va9eR~
"                (例) %s  a\\b\\c\\d\\e\\f\\g  x\\=\n",            //~va9eR~
		PGM);                                                      //~va9eI~
HELPMSG                                                            //~va9eI~
"                     ===> %s a\\b\\c\\d\\e\\f\\g  x\\a\\b\\c\\d\\e\\f\\g\n",//~va9eR~
"                     ===> %s a\\b\\c\\d\\e\\f\\g  x\\a\\b\\c\\d\\e\\f\\g\n",//~va9eR~
		PGM);                                                      //~va9eI~
#endif                                                             //~va9eI~
#ifdef UNX                                                         //~va9eI~
HELPMSG                                                            //~va9eI~
"                     %s /a/b/c/d/e/f/g  /x/1=\n",                 //~va9eR~
"                     %s /a/b/c/d/e/f/g  /x/1=\n",                 //~va9eR~
		PGM);                                                      //~va9eI~
HELPMSG                                                            //~va9eI~
"                     ===> %s /a/b/c/d/e/f/g  /x/b/c/d/e/f/g\n",   //~va9eR~
"                     ===> %s /a/b/c/d/e/f/g  /x/b/c/d/e/f/g\n",   //~va9eR~
		PGM);                                                      //~va9eI~
#else                                                              //~va9eI~
HELPMSG                                                            //~va9eI~
"                     %s \\a\\b\\c\\d\\e\\f\\g  \\x\\1=\n",        //~va9eR~
"                     %s \\a\\b\\c\\d\\e\\f\\g  \\x\\1=\n",        //~va9eR~
		PGM);                                                      //~va9eI~
HELPMSG                                                            //~va9eI~
"                     ===> %s \\a\\b\\c\\d\\e\\f\\g  \\x\\b\\c\\d\\e\\f\\g\n",//~va9eR~
"                     ===> %s \\a\\b\\c\\d\\e\\f\\g  \\x\\b\\c\\d\\e\\f\\g\n",//~va9eR~
		PGM);                                                      //~va9eI~
#endif                                                             //~va9eI~
#ifdef UNX                                                         //~va9eI~
HELPMSG                                                            //~va9eI~
"                     %s /a/b/c/d/e/f/g  /x/2=3/z\n",              //~va9eR~
"                     %s /a/b/c/d/e/f/g  /x/2=3/z\n",              //~va9eR~
		PGM);                                                      //~va9eI~
HELPMSG                                                            //~va9eI~
"                     ===> %s /a/b/c/d/e/f/g  /x/c/d/e/z\n",       //~va9eR~
"                     ===> %s /a/b/c/d/e/f/g  /x/c/d/e/z\n",       //~va9eR~
		PGM);                                                      //~va9eI~
#else                                                              //~va9eI~
HELPMSG                                                            //~va9eI~
"                     %s \\a\\b\\c\\d\\e\\f\\g  2=3\\z\n",         //~va9eR~
"                     %s \\a\\b\\c\\d\\e\\f\\g  2=3\\z\n",         //~va9eR~
		PGM);                                                      //~va9eI~
HELPMSG                                                            //~va9eI~
"                     ===> %s \\a\\b\\c\\d\\e\\f\\g  c\\d\\e\\z\n",//~va9eR~
"                     ===> %s \\a\\b\\c\\d\\e\\f\\g  c\\d\\e\\z\n",//~va9eR~
		PGM);                                                      //~va9eI~
#endif                                                             //~va9eI~
HELPMSG                                                            //~v1.xI~
"         mask  :wild card spec to select member.\n",              //~v1.xR~
"         mask  :メンバーを選択するためのワイルドカード指定.\n");  //~v1.xI~
HELPMSG                                                            //~v1.xI~
"                It is not applied for sub-dir name itself\n",     //~v252R~
"                サブディレクトリー名には適用しません\n");         //~v252R~
HELPMSG                                                            //~v1.xI~
"         %cA    :use alias for long file name(WIN/GCC version only)\n",//~v2.3R~
"         %cA    :長いファイル名を別名で比較(WIN/GCCバージョンのみ有効)\n",//~v2.3R~
					CMDFLAG_PREFIX);                               //~v2.3I~
HELPMSG                                                            //~va1BI~
"         %cF    :compare file contents if size is same\n",        //~va1BI~
"         %cF    :サイズが等しいときファイル内容比較も実施\n",     //~va1BI~
					CMDFLAG_PREFIX);                               //~va1BI~
HELPMSG                                                            //~va69I~
"                display '!' if contents unmatch\n",               //~va69I~
"               :内容不一致は'!'で\x95\\示\n");                    //~va69R~
HELPMSG                                                            //~va43I~
"         %cFT   :execute text mode file compare(for diff of \\n and \\r\\n)\n",//~va43I~
"         %cFT   :テキストモードでファイル内容比較(行末の\\nと\\r\\nの相異無視)\n",//~va43I~
					CMDFLAG_PREFIX);                               //~va43I~
HELPMSG                                                            //~va4uI~
"         %cFCxxx:compare by other utility. xxx:command string.\n",//~va4uR~
"         %cFCxxx:他のユーティリティーで内容比較。xxx:コマンド文字列\n",//~va4uR~
					CMDFLAG_PREFIX);                               //~va4uI~
HELPMSG                                                            //~va4uI~
"               :ex) \"%cFCxfc %cc \\\"%%s\\\" \\\"%%s\\\"\"   this is  default\n",//~va4uR~
"               :例) \"%cFCxfc %cc \\\"%%s\\\" \\\"%%s\\\"\"   これが省略値\n",//~va4uR~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~va4uR~
HELPMSG                                                            //~va4uI~
//"         %cFRxxx:xxx:command output redirection directory. default:stdout\n",//~va4uR~//~va91R~
//"         %cFRxxx:xxx:コマンド出力のリダイレクト先ディレクトリー\n",//~va4uR~//~va91R~
//                    CMDFLAG_PREFIX);                             //~va91I~
"         %cFRxxx:With %cFC, directory of xfc output. default:stdout\n",//~va91R~
"         %cFRxxx:%cFC のときの xfc コマンド出力のディレクトリー,省略値=標準出力\n",//~va91R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~va91R~
HELPMSG                                                            //~va9AI~
"         %cF+mask:Additional member selection wildcard spec.\n",  //~va9AR~
"         %cF+mask:追加のメンバー選択ワイルドカード指定\n",        //~va9AR~
					CMDFLAG_PREFIX);                               //~va9AI~
HELPMSG                                                            //~v1.xI~
//"         %cL    :use long file name          (WIN/GCC version only;defalt)\n",//~v252R~
//"         %cL    :長いファイル名を使用      (WIN/GCCバージョンのみ有効;省略値)\n",//~v252R~
//                    CMDFLAG_PREFIX);                             //~v252R~
"         %cL[nn]:use long file name. nn:filename print width. default %d.\n",//~v252I~
"         %cL[nn]:長いファイル名を使用。nn:ファイル名\x95\\示幅。省略値=%d。\n",//~v252R~
                    CMDFLAG_PREFIX,FILENAMEFLDSZ);                 //~v252I~
HELPMSG                                                            //~va1zI~
"         %cPpath:subdir specification in the intermediate input file.\n",//~va1zI~
"         %cPpath:中間ワークファイル入力のときのサブディレクトリー指定。\n",//~va1zR~
                    CMDFLAG_PREFIX);                               //~va1zI~
HELPMSG                                                            //~v1.xI~
"         %cS    :search also all sub directory\n",                //~v2.3R~
"         %cS    :サブディレクトリー内もサーチ\n",                 //~v2.3R~
					CMDFLAG_PREFIX);                               //~v2.3I~
HELPMSG                                                            //~va6bI~
"         %cTZ[-]hh:mm :TimeZone applied to dir1\n",               //~va6bR~
"         %cTZ[-]hh:mm :ディレクトリー1に適用するタイムゾーン値\n",//~va6bR~
					CMDFLAG_PREFIX);                               //~va6bI~
HELPMSG                                                            //~va6bI~
"                      (ex) %cTZ-09:00, %cTZ03:15\n",              //~va6bR~
"                      (例) %cTZ-09:00, %cTZ03:15\n",              //~va6bR~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~va6bI~
HELPMSG                                                            //~v1.xI~
#ifdef UNX                                                         //~va62R~
//"         %cU[S][T][L|H][U]:output unmatch only\n",                //~va62I~//~va9fR~
//"         %cU[S][T][L|H][U]:不一致のみ出力\n",                     //~va62I~//~va9fR~
"         %cU[O][S][T][L|H][U]:output unmatch only\n",             //~va9fI~
"         %cU[O][S][T][L|H][U]:不一致のみ出力\n",                  //~va9fI~
					CMDFLAG_PREFIX);                               //~va62I~
#else                                                              //~va62I~
//"         %cU[S][T][L|H]:output unmatch only\n",                   //~v23gR~//~va9fR~
//"         %cU[S][T][L|H]:不一致のみ出力\n",                        //~v23gR~//~va9fR~
"         %cU[O][S][T][L|H]:output unmatch only\n",                //~va9fI~
"         %cU[O][S][T][L|H]:不一致のみ出力\n",                     //~va9fI~
					CMDFLAG_PREFIX);                               //~v2.3I~
#endif                                                             //~va62I~
HELPMSG                                                            //~va9fI~
"                O:means to list ONLY member\n",                   //~va9fI~
"                O:片方にのみ存在するメンバーをリストする\n");     //~va9fI~
HELPMSG                                                            //~v23dI~
"                S:means to list file size unmatch only\n",        //~v23gR~
"                S:ファイルサイズ不一致のみリストする\n");         //~v23dR~
HELPMSG                                                            //~v23eI~
"                T:means to list timestamp unmatch only\n",        //~v23gR~
"                T:タイムスタンプ不一致のみリストする\n");         //~v23eI~
HELPMSG                                                            //~v23gI~
"                L/H:means to list timestamp is Low/High only\n",  //~v23gR~
"                L/H:タイムスタンプが小さい(L)/大きい(H)ファイルのみリストする\n");//~v23gI~
#ifdef UNX                                                         //~va62R~
HELPMSG                                                            //~va62I~
"                U:means to uid/gid unmatch only(set \"%\" if attr is same)\n",//~va62R~
"                U:uid/gid不一致のみリストする(属性一致の時\"%\"で\x95\\示)\n");//~va62R~
#endif                                                             //~va62I~
HELPMSG                                                            //~va9gI~
"         %cXmask:file/directory name to be excluded. Allowed any number of parms.\n",//~va9gR~
"         %cXmask:比較から除外するファイル/ディレクトリ名。複数指定可\n",             //~va9gR~
					CMDFLAG_PREFIX);                               //~va9gI~
                                                                   //~va9gI~
#ifdef UNX                                                         //~va9gI~
HELPMSG                                                            //~va9gI~
"                (ex) %s  /home /tmp/bkuphome -xbin -x*.o\n",      //~va9gI~
"                (例) %s  /home /tmp/bkuphome -xbin -x*.o\n",      //~va9gI~
		PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~va9gI~
#else                                                              //~va9gI~
HELPMSG                                                            //~va9gI~
"                (ex) %s  d:\\workspace x:\\bkup-wksp /xbin /x*.obj\n",//~va9gR~
"                (例) %s  d:\\workspace x:\\bkup-wksp /xbin /x*.obj\n",//~va9gR~
		PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~va9gI~
#endif                                                             //~va9gI~
                                                                   //~va9gI~
HELPMSG                                                            //~va9hI~
//"         %c=F    :Apply \"=\"(copy filespec path) to fullpath name\n",//~va9hI~//~va9kR~
//"         %c=F    :\"=\"(ファイル名のパスのコピー)をフルパス名に適用する\n",//~va9hI~//~va9kR~
"         %c={F|N}:F:Apply \"=\"(copy filespec path) to fullpath name\n",//~va9kI~
"         %c={F|N}:F:\"=\"(ファイル名のパスのコピー)をフルパス名に適用する\n",//~va9kI~
					CMDFLAG_PREFIX);                               //~va9hI~
HELPMSG                                                            //~va9kI~
"                 N:ignores \"=\".\n",                             //~va9kI~
"                 N:\"=\"を無視する\n");                           //~va9kI~
#ifdef UNX                                                         //~va9hI~
HELPMSG                                                            //~va9hI~
"                (ex) %s  %c=F a/b/c  /tmp/1=  (cd=/home/you)\n",  //~va9hI~
"                (例) %s  %c=F a/b/c  /tmp/1=  (cd=/home/you)\n",  //~va9hI~
		PGM,CMDFLAG_PREFIX);                                       //~va9hI~
HELPMSG                                                            //~va9hI~
"                     ===> %s /home/you/a/b/c  /tmp/you/a/b/c\n",  //~va9hI~
"                     ===> %s /home/you/a/b/c  /tmp/you/a/b/c\n",  //~va9hI~
		PGM);                                                      //~va9hI~
#else                                                              //~va9hI~
HELPMSG                                                            //~va9hI~
"                (ex) %s  %c=F a\\b\\c  D:\\tmp\\2=  (cd=C:\\home\\you)\n",//~va9hI~
"                (例) %s  %c=F a\\b\\c  D:\\tmp\\2=  (cd=C:\\home\\you)\n",//~va9hI~
		PGM,CMDFLAG_PREFIX);                                       //~va9hI~
HELPMSG                                                            //~va9hI~
"                     ===> %s C:\\home\\you\\a\\b\\c  D:\\tmp\\you\\a\\b\\c\n",//~va9hI~
"                     ===> %s C:\\home\\you\\a\\b\\c  D:\\tmp\\you\\a\\b\\c\n",//~va9hI~
		PGM);                                                      //~va9hI~
#endif                                                             //~va9hI~
HELPMSG                                                            //~v1.xI~
"         %c1    :output dir1 member only\n",                      //~v2.3R~
"         %c1    :dir1 のメンバーからみた比較のみ実行\n",          //~v2.3R~
					CMDFLAG_PREFIX);                               //~v2.3I~
HELPMSG                                                            //~v1.xI~
"         %c2    :output dir2 member only\n",                      //~v2.3R~
"         %c2    :dir2 のメンバーからみた比較のみ実行\n",          //~v2.3R~
					CMDFLAG_PREFIX);                               //~v2.3I~
HELPMSG                                                            //~v1.xI~
"               :default is %c1 and %c2\n",                        //~v2.3R~
"               :省略値は %c1 と %c2 の両方を実行\n",              //~v2.3R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX); //~v2.3I~
HELPMSG                                                            //~v1.xI~
"         %cix   :use intermediate file for input or output\n",    //~va1zR~
"         %cix   :中間ワークファイルの使用\n",                     //~va1zR~
					CMDFLAG_PREFIX);                               //~v2.3I~
HELPMSG                                                            //~v1.xI~
"                x=o:write directory contents to intermediate file\n",//~v1.xR~
"                x=o:中間ワークファイルにディレクトリーの内容を出力\n");//~v1.xI~
HELPMSG                                                            //~v1.xI~
"                x=i:compare dir through intermediate file by %clo\n",//~v2.3R~
"                x=i:%cIoで出力した中間ワークファイルを介した比較\n",//~v2.3R~
					CMDFLAG_PREFIX);                               //~v2.3I~
HELPMSG                                                            //~v1.xI~
"                x=n:dir1/2 is not intermediate file(default)\n",  //~v1.xR~
"                x=n:dir1/2 は中間ワークファイルではない(省略値)\n");//~v1.xI~
HELPMSG                                                            //~v1.xI~
"         %cWsz  :work buff area size(default sz is %d)\n",        //~v2.3R~
"         %cWsz  :ワークバッファサイズ(省略値は %d)\n",            //~v2.3R~
					CMDFLAG_PREFIX,                                //~v2.3I~
						tblsz);                                    //~v1.xI~
HELPMSG                                                            //~v231I~
"         %cYx,%cNx:toggle type switch; x is as following.\n",     //~v231I~
"         %cYx,%cNx:オン/オフ タイプのフラグ; x はつぎのフラグを指定\n",//~v231I~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v231I~
HELPMSG                                                            //~v231I~
"              c   :case sensitive filename.\n",                   //~v231I~
"              c   :ファイル名の大文字小文字の区別\n");            //~v231I~
HELPMSG                                                            //~v231I~
//"                   Defult is sensitive only for between UNIX file(\"/\"seperater)\n",//~v261R~
//"                   省略値はUNIXファイル名(\"/\"で分離)同士の場合のみ区別あり\n");//~v261R~
"                   Defult is sensitive if one or the other is UNIX file system.\n",//~v261R~
"                   省略値はどちらかがUNIXファイルシステムの場合区別あり\n");//~v261R~
//#ifdef UNX                                                       //~va73R~
#if defined(W32)||defined(UNX)                                     //~va73I~
HELPMSG                                                            //~v266I~
"              m   :output symbolic link errmsg. default is /Ym.\n",//~v266R~
"              m   :シンボリックリンクエラーMsgの出力。省略値は /Ym。\n");//~v266R~
HELPMSG                                                            //~v256I~
"              s   :chk into symbolic link target. default is /Ys.\n",//~va71R~
//"              s   :シンボリックリンク先もCHKする。省略値は /Ys。\n");//~va73R~
"              s   :シンボリックリンク先もCHKする。省略値は /Ns。\n");//~va73I~
HELPMSG                                                            //~va71I~
"                   Display %c as attr unmatch when target unmatch.\n",//~va71I~
"                   シンボリックリンク先が異なるとき %c を attr 不一致欄に\x95\\示\n",//~va71I~
					SLINK_TARGET_UNMATCH);                         //~va71I~
#endif                                                             //~v256I~
HELPMSG                                                            //~v1.xI~
"sample result:\n",                                                //~v1.xR~
"出力例:\n");                                                      //~v1.xI~
#ifdef UNX                                                         //~v2.3I~
HELPMSG                                                            //~v2.3I~
"abc.d         (96-06-01 12:58 766dugt 48250) <*= (96-06-01 12:59 -----  148250)\n",0);//~v234R~
#else                                                              //~v2.3I~
HELPMSG                                                            //~v1.xI~
"abc.d         (96-06-01 12:58 ASHRD  148250) <*= (96-06-01 12:59 -----  148250)\n",0);//~v1.xR~
#endif                                                             //~v2.3I~
HELPMSG                                                            //~v1.xI~
"A~~~~~~~~~~~~  A~~~~~~~~~~~~~ A~~~~  A~~~~~  AAA  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",0);//~v1.xR~
HELPMSG                                                            //~v1.xI~
"|              |              |      |       |||       in Dir2\n",//~v1.xR~
"|              |              |      |       |||       Dir2 内での状況\n");//~v1.xR~
HELPMSG                                                            //~v1.xI~
"file/dir name  time stamp     attr   size    ||+--size compare result\n",//~va3nR~
"ファイル名     タイムスタンプ 属性   サイズ  ||+--サイズ比較結果\n");//~v1.xI~
HELPMSG                                                            //~v1.xI~
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |+---' ' if same attr\n",//~v1.xR~
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |+---属性が一致の時は' '\n");//~v1.xR~
#ifdef UNX                                                         //~va62I~
HELPMSG                                                            //~va62I~
"                                             |    '%':same attr,uid/gid NE\n",//~va62I~
"                                             |    '%':属性一致,uid/gid不一致\n");//~va62I~
#endif                                                             //~va62I~
HELPMSG                                                            //~v1.xI~
"        Status in Dir1                       +----timestamp compare result\n",//~v1.xR~
"        Dir1 内での状況                      +----タイムスタンプ比較結果\n");//~v1.xR~
HELPMSG                                                            //~va69I~
"                                                  '(' or ')':difference<=2 sec\n",//~va69R~
"                                                  '(' 又は ')':違いが2秒以内\n");//~va69R~
HELPMSG                                                            //~va3bI~
" --- %s  End Of Help ---\n",                                      //~va3bI~
" --- %s  End Of Help ---\n",                                      //~va3bI~
		PGM);                                                      //~va3bI~
    return;                                                        //~v1.xR~
}//help                                                            //~v1.dR~
