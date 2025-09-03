//CID://+v7e2R~: update#=     69                                   //+v7e2R~
//*************************************************************
//*ualloc/ucalloc/ufree/umalloc16/ucalloc16/ufree16/uallocsz
//************************************************************* //~5A01R~
//v7e2:250626 (Win)flush when abend                                //+v7e2I~
//v6L6:170715 msvs2017 warning                                     //~v6L6I~
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6Hu:170126 expand max allocsz for udirlist 16M-->32M            //~v6huI~
//v6G6:161212 (Win10)compiler warning                              //~v6G6I~
//v6G5:161212 (Win10)_crtheap is no defined now                    //~v6G5I~
//v6F0:160830 W64 dose not set stack chain by EBP(/Oy- is for x86 only). try CaptureStackBackTrace api.//~v6F0I~
//v6B1:160114 trace,mtrace file no share mode                      //~v6B1I~
//v6q9:131203 (BUG)freesizeerr() for large dir(10,000 entry) by udirlist malloc size is over 24bit//~v6q9I~
//v6hB:120823 memory trace:print ret addr for also ufree           //~v6hBI~
//v6hi:120625 vc10x64 malloc chk                                   //~v6hiI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h5:120606 (WTL)Bug found by vs2010exp(used uninitialized variable)//~v6h5I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5jp:061029 (Vists)HeapAlloc changed(malloc bit and size pos changed or unknown)//~v5jpI~
//v5dn:040620 allow over 1MB malloc req up to 1GB(for sort wordk)  //~v5dnI~
//v593:030930 (WIN,WXE)add return addr to malloc trace for debug   //~v593I~
//v570:020824 wxe support                                          //~v570I~
//            (BUG) not malloc area at ufree                       //~v570I~
//            under wxe debug mode,malloc is dbg version but HeapAlloc is not debug version//~v570I~
//v568:020706 new func:allocchk;msg and abend                      //~v568I~
//v196:980922 (BUG:WIN)malloc logic changed for short block(<=x1e0) vc version 1020//~v196I~
//            use direct Heapalloc;heap handel is get from _crtheap same as _malloc//~v196I~
//            Healfree is not need,free search short block at first.//~v196I~
//v154:980123 (BUG:DOS)alloc size over 32k treated as minus for funcmap//~v154I~
//v136:980103 (W32)WINNT support                                   //~v136I~
//            -udosiswinnt func   udos.c/h ualloc.c                //~v136I~
//            -chk alloc bit at free ualloc.c                      //~v136I~
//v133:971221 for Win/NT;malloc logic                              //~v133I~
//v119:971115 (BUG:GCC)64k allocmem by 501h(in sblk or stub) dose not//~v106I~
//                     return 64k boundary addr(selector base may be not//~v106I~
//                     64k boundary).so use 4k page logic same as os2.//~v106I~
//                     and addr may from top(ff______).            //~v106I~
//v106:971027 (BUG:GCC)sbrk dosenot return continuous memory under win95.//~v106I~
//            Block addr is page boundary -4 at first by the logic in malloc.//~v106I~
//            (req to __sblk to set __what_size_dpmi_think_we_are to page boundary.)//~v106I~
//            Blk in another 64k may be on page boundary if __what_size_app_think_it_is//~v106I~
//            reached to it.                                       //~v106I~
//            Abandon -4 setup logic in malloc.It may return always page boundary.//~v106R~
//            And,dump page should also collect by alloc addr like as os/2.//~v106I~
//v102:971010 os2 new malloc dump logic                            //~v102I~
//            ualloc. c:set allocate page map                      //~v102I~
//v101:971009 long filename                                        //~v101I~
//            ualloc.c:matrace filename,up to maxpath              //~v101I~
//v100:970728 uerrexit when malloc req over 1mb                    //~v100I~
//v099:970726 free size chk to chk destroyed earlyer(except native DOS)//~v099I~
//v084:970511 (BUG)uallocsz when req over pagesize                 //~v084I~
//v076:970421 when storage shortage,display current water mark not max.//~v076I~
//v071:970412:(GCC-BUG)malloc size=2**n+pagesize if  reqsize+4>=pagesize.//~v071I~
//            (if reqsize+4<pagesize,2**n)                         //~v071I~
//v058:970131:DOS ufree,check malloced by length bit(0x01 on:free,off alloced)//~v058I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -malloc/free(4 byte overhead,alloc magif=0xef at -4) //~v053I~
//            -printf ptr parm to int format generates warning     //~v053I~
//            -size_t unsigned int-->long int,int 2-->4 byte       //~v053I~
//v034:961008:VisualC++ support(identify by (_MSC_VER>=800))       //~v034I~
//     961025:VisualC++ alloc size vary depending on the bounday   //~v034I~
//            (round up to page boundary)                          //~v034I~
//v030:960923:storage short msg by unsigned integer                //~v030I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//* 950930 alloc err return option                              //~5930I~
//* 950827 trace total of alloc and alloc16                     //~5827I~
//* 950813 close trace file when opt=0                          //~5813I~
//* 950528 net total alloc req amount
//* 950209 always amount size chk and set to gbl                //~5209R~
//* 941204 size debug option                                    //~5209I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
//*******************************************************
#ifdef W32                                                         //~v196I~
//#if (_MSC_VER >= 800)                                            //~v5ncR~
	#include <windows.h>                                           //~v196I~
//#endif                                                           //~v5ncR~
#endif                                                             //~v196I~
#define MAX_MALLOC 0x40000000     //1GB                            //~v5dnR~
//*******************************************************          //~v133I~
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <utrace.h>                                                //~v119R~
#include <udos.h>                                                  //~v133I~
#include <ufile.h>                                                 //~v6B1I~
#include <ufile2.h>                                                //~v6B1I~
//*******************************************************
#define         UALLOCTRCFILE "ualloc.trc"
#define STACK_TRACE_CTR   2                                        //~v6F0I~
//*******************************************************
#ifdef DOS
    #ifdef DPMI                                 //DPMI version                     //~v053I~
//*overhead from \djgpp\src\libc\ansi\stdlib\malloc.c **********   //~v053I~
//  union overhead {                                               //~v053I~
//    union     overhead *ov_next;      /* when free */                    //~v053I~
//    struct {                                                     //~v053I~
//      unsigned char   ovu_magic; /* magic number */              //~v053I~
//      unsigned char   ovu_index; /* bucket # */ n of 2**(n+3)    //~v053I~
//  #ifdef RCHECK                                                  //~v053I~
//      unsigned short  ovu_rmagic; /* range magic number */       //~v053I~
//      unsigned int    ovu_size; /* actual block size */          //~v053I~
//  #endif                                                         //~v053I~
//    } ovu;                                                       //~v053I~
        #define SIZEPOS      4          //over head size               //~v053R~
        #define BACKETNOPOS  3          //backet index pos             //~v053I~
        #define MAGICPOS     4          //malloc magic pos             //~v053I~
        #define MALLOCID     0xef       //allocated magic              //~v053I~
        #define PAGESIZE     4096       //additinaly get a page if over pagesize//~v071I~
    #else                       //not DPMI                         //~v053I~
        #define SIZEPOS      2          //alloc size position
    #endif                      //DPMI or not                      //~v053I~
#else
    #ifdef W32                                                     //~v022I~
    	int mscver=_MSC_VER;                                       //~v6hiI~
                #if (_MSC_VER >= 800)                                      //~v034I~
      #ifdef ULIB64X                                               //~v6hiM~
          #define DEBUGID   0xFDFDFDFD    //allocated id           //~v6hiM~
          #ifdef _DEBUG                                            //~v6hiM~
              #define DBGCHUNKHDRSZ        16     //size+0+ctr+fdfdfdfd//~v6hiM~
			  #define DBGTRAILERSZ          4                      //~v6hiM~
			  #define DBGALLOCSIGNFLD       4                      //~v6hiM~
              #define SIZEPOS              16              //alloc size position//~v6hiM~
              #define SIZEPOSNT            16                      //~v6hiM~
              #define SIZEPOSD             16                      //~v6hiI~
              #define SIZEPOSR             16                      //~v6hiI~
              #define MALLOCID     0xfdfdfdfd                      //~v6hiM~
              #define DBGALLOCED   0xfdfdfdfd                      //~v6hiI~
          #else                                                    //~v6hiM~
              #define DBGCHUNKHDRSZ        16     //size+0+ctr+fdfdfdfd//~v6hiI~
			  #define DBGTRAILERSZ          4                      //~v6hiI~
			  #define DBGALLOCSIGNFLD       4                      //~v6hiI~
              #define SIZEPOS              16              //alloc size position//~v6hiI~
              #define SIZEPOSNT            16                      //~v6hiI~
              #define SIZEPOSD             16                      //~v6hiI~
              #define SIZEPOSR             16                      //~v6hiI~
              #define MALLOCID     0xfdfdfdfd                      //~v6hiI~
              #define DBGALLOCED   0xfdfdfdfd                      //~v6hiI~
          #endif                                                   //~v6hiM~
      #else  //!ULIB64X                                            //~v6hiM~
//when debug version libraly used                                  //~v034I~
//-x24    a0...... blocklen(header=x24+traler=4+reqlen boundary up)//~v034M~
//-x10           request len                                       //~v034M~
//-x04    FDFDFDFD destroy chk                                     //~v034M~
//+reqlen FDFDFDFD destroy chk                                     //~v034M~
//...     4 byte boudary padding                                   //~v034M~
//when non debug version libraly used                              //~v034I~
//-x04    a0...... blocklen(header=4+reqlen boundary up)           //~v034M~
//+reqlen 4byte boundary padding                                   //~v034M~
                #define DEBUGID   0xFDFDFDFD    //allocated id     //~v034R~//~v034I~
                #define SIZEPOSD  0x24                  //alloc size position for debug version//~v034I~
                #define SIZEPOSR  4                             //alloc size position for non debug version //~v034I~//~v034I~
                #define SIZEPOSNT 8  //overhead for win NT         //~v133I~
                #define MALLOCID 0xA0                   //allocated id(assume max 16MB)//~v034I~//~v034I~
//debug version malloc                                             //~v5jpI~
#define	DBGCHUNKHDRSZ        16                                    //~v5jpI~
#define	DBGALLOCSIGNFLD      12                                    //~v5jpI~
#define	DBGALLOCED           0x00000001                            //~v5jpI~
#define	DBGTRAILERSZ         4                                     //~v5jpI~
                                                                   //~v034I~
                                                                   //~v6hiI~
      #endif  //!ULIB64X                                           //~v6hiI~
                        void uallocvcinit(void);                               //~v034I~
            static int Sinitsw,Sdebugsw;                           //~v034I~
            static int Ssizepos;                                   //~v034I~
            static int Sntsw;  //windows/NT sw                     //~v133I~
        #else                                                      //~v034I~
                #define SIZEPOS  4              //alloc size position              //~v022R~
        #endif                                                     //~v034I~
    #else                                                          //~v022I~
        #define SIZEPOS      16         //alloc size position
        #define MALLOCID         0xA5D5
        #define MALLOC16ID       0xFDDF
//  #define USHORT       unsigned short                            //~v022R~
//copyed from malloc.h for defined __TILE__
         void * _Optlink _tcalloc( size_t, size_t );
         void   _Optlink _tfree( void * );
         void * _Optlink _tmalloc( size_t );
        #endif                                                         //~v022I~
#endif
//*******************************************************
#if !defined(DOS) || defined(DPMI)                                 //~v100I~
void ufreesizeerr(void *Paddr);                                    //~v099I~
void umallocsizeerr(size_t Psize);                                 //~v100I~
#endif                                                             //~v100I~
//#ifdef OS2                                                       //~v106R~
#if defined(OS2) || defined(DPMI)                                  //~v106I~
    void uallocmapset(char* Paddr,int Psize);                      //~v102I~
#endif                                                             //~v102I~
//*******************************************************          //~v099I~
        long Gualloc_amount;                                        //~5209R~
        long Gualloc16_amount;                                      //~5209I~
//*******************************************************       //~5209I~
#if (_MSC_VER >=1020)     //vc++ enterprize version                //~v196I~
  #ifdef WIN10                                                     //~v6G5I~
    static HANDLE  ucrtheap;    //malloc lib rtn use               //~v6G5I~
  #else                                                            //~v6G5I~
    extern HANDLE  _crtheap;    //malloc lib rtn use               //~v196I~
  #endif                                                           //~v6G5I~
#endif                                                             //~v196I~
static int  Sallocopt;
static int  Sallocret;                                          //~5930I~
static long Salloclen;
static unsigned long Snetreqlen;        //request len
static long Sallocctr;
static long Sfreelen;
static long Sfreectr;
static long Salloc16len;
static unsigned long Snetreq16len;      //request len
static long Salloc16ctr;
static long Sfree16len;
static long Sfree16ctr;
static long Ssizewk;
static long Smaxlenwk;
static long Smaxlenwk16;                                        //~5827I~
static UALLOCD Sallocdata;
static FILE* Shfile;
static char *Spagemap;          //os2 only                         //~v102I~
static HANDLE Slockhandle;                                         //~v6B1R~
//*******************************************************
static unsigned char Smatrcfile[_MAX_PATH]=UALLOCTRCFILE;          //~v101R~
//*******************************************************
//*ualloc
//* dummy for LIB
//******************************************************
void ualloc(void)
{
        return;
}//ualloc
#ifdef WIN10                                                       //~v6G5I~
//******************************************************           //~v6G5I~
static HANDLE getHandle()                                          //~v6G5I~
{                                                                  //~v6G5I~
	if (!ucrtheap)                                                 //~v6G5I~
    	ucrtheap=GetProcessHeap();                                 //~v6G5I~
    return ucrtheap;                                               //~v6G5I~
}//ualloc                                                          //~v6G5I~
#endif                                                             //~v6G5R~
//*******************************************************
//*ualloc_init
//* parm1:ualloc option
//*        0:reset debug mode(close opened trace file)          //~5930I~
//*        1:alloc size debug                                   //~5930I~
//*        2:wrtite to file                                     //~5930I~
//*        4:return even if alloc failed(not needed other flag) //~5930I~
//*        8:exit        if alloc failed(not needed other flag) //~5930I~
//* parm2:trace file name
//******************************************************
void ualloc_init(int Popt,unsigned char *Pfilename)
{
        Sallocret=(Popt & (UALLOC_ERRRETURN | UALLOC_ERREXIT));     //~5930R~
//  Popt=(Popt & (UALLOC_DEBUG|UALLOC_TRACE));                     //~v593R~
    Popt=(Popt & (UALLOC_DEBUG|UALLOC_TRACE|UALLOC_TRACE2));       //~v593I~
    if (Sallocret && !Popt)  //return req only                  //~5930I~
    {                                                           //~5930I~
                Sallocret=((Sallocret & UALLOC_ERRRETURN)               //~5930R~
                   && !(Sallocret & UALLOC_ERREXIT));           //~5930R~
        return;                                                 //~5930I~
        }                                                           //~5930I~
        if (!(Sallocopt=Popt))                                      //~5813R~
                if (Shfile)                                             //~5813I~
        {                                                       //~5813I~
                        fclose(Shfile);                                     //~5813I~
            Shfile=0;                                           //~5813I~
        }                                                       //~5813I~
        if (Popt & UALLOC_TRACE)                                    //~5930R~
        {
                if (Pfilename)
//              strcpy(Smatrcfile,Pfilename);                          //~v101R~
                strncpy(Smatrcfile,Pfilename,_MAX_PATH-1);             //~v101R~
                if (!Shfile)    //not yet opened                        //~5930I~
                {                                                  //~v6B1I~
              if (Popt & UALLOC_NOSHARE)                           //~v6B1I~
                Shfile=ufileopenexclusivewrite(0,Smatrcfile,&Slockhandle);//~v6B1M~
              else                                                 //~v6B1I~
                Shfile=fopen(Smatrcfile,"w");        
                }                                                  //~v6B1I~
        }
//#ifdef OS2                                                       //~v106R~
#if defined(OS2) || defined(DPMI)                                  //~v106I~
//  Spagemap=malloc(UALLOC_PAGEMAPSZ+16);//page alloc tbl 1bit per page//~v106R~
        Spagemap=calloc(1,UALLOC_PAGEMAPSZ+16);//page alloc tbl 1bit per page//~v106I~
    strncpy(Spagemap,"PAGEMAP",16);                                //~v102I~
    Spagemap+=16;                                                  //~v102I~
        uallocmapset(Spagemap,UALLOC_PAGEMAPSZ);                       //~v102R~
#endif                                                             //~v102I~
        return;
}//ualloc

//*******************************************************
//*ugetallocdata
//* parm  :none
//* return:ptr to alloc data
//******************************************************
UALLOCD *ugetallocdata(void)
{
        Sallocdata.allocctr  =Sallocctr;
        Sallocdata.alloclen  =Salloclen;
        Sallocdata.netreqlen  =(long)Snetreqlen;                    //~5528R~
        Sallocdata.freectr   =Sfreectr;
        Sallocdata.freelen   =Sfreelen;
        Sallocdata.maxlen    =Gualloc_amount;                       //~5209R~
        Sallocdata.alloc16ctr=Salloc16ctr;
        Sallocdata.alloc16len=Salloc16len;
        Sallocdata.netreq16len=(long)Snetreq16len;                  //~5528R~
        Sallocdata.free16ctr =Sfree16ctr;
        Sallocdata.free16len =Sfree16len;
        Sallocdata.max16len  =Gualloc16_amount;                     //~5209R~
        Sallocdata.pagemap   =Spagemap;                                //~v102I~
        Sallocdata.pagemapsz =UALLOC_PAGEMAPSZ;//page alloc tbl 1bit per page//~v102I~
        return &Sallocdata;
}//ualloc
//*******************************************************          //~v568I~
//*ualloc_chk                                                      //~v568I~
//* parm  :option                                                  //~v568I~
//* return:rc:0 ok,1:not freed exist                               //~v568I~
//******************************************************           //~v568I~
int ualloc_chk(int Popt)                                           //~v568I~
{                                                                  //~v568I~
    UALLOCD *puad;                                                 //~v568I~
    int rc;                                                        //~v568I~
    long reslen,resctr;                                            //~v568I~
    char *uatrcopt="Inactive";                                     //~v568I~
//***************************                                      //~v568I~
    if (Sallocopt)                                                 //~v568I~
    	uatrcopt="Active";                                         //~v568I~
    puad=ugetallocdata();                                          //~v568I~
    if (Popt & UAC_MSG)                                            //~v568I~
        printf("malloc statistic data (trace is %s)\n"             //~v568I~
"           alloc   req: %8ld times  total %8ld byte(net %8ld)\n"  //~v568I~
"           free    req: %8ld times  total %8ld byte\n"            //~v568I~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v568I~
#else                                                              //~v568I~
"           alloc16 req: %8ld times  total %8ld byte(net %8ld)\n"  //~v568I~
"           free16  req: %8ld times  total %8ld byte\n"            //~v568I~
#endif                                                             //~v568I~
"           %8ld times,%8ld byte free more required\n"             //~v568I~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v568I~
"           allocated maximum is %8ld\n",                          //~v568I~
#else                                                              //~v568I~
"           allocated maximum is %8ld ,for seg16 %8ld\n",          //~v568I~
#endif                                                             //~v568I~
                uatrcopt,                                          //~v568I~
                puad->allocctr,                                    //~v568I~
                puad->alloclen,                                    //~v568I~
                puad->netreqlen,                                   //~v568I~
                puad->freectr,                                     //~v568I~
                puad->freelen,                                     //~v568I~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v568I~
#else                                                              //~v568I~
                puad->alloc16ctr,                                  //~v568I~
                puad->alloc16len,                                  //~v568I~
                puad->netreq16len,                                 //~v568I~
                puad->free16ctr,                                   //~v568I~
                puad->free16len,                                   //~v568I~
#endif                                                             //~v568I~
    (resctr=puad->allocctr+puad->alloc16ctr-puad->freectr-puad->free16ctr),//~v568I~
    (reslen=puad->alloclen+puad->alloc16len-puad->freelen-puad->free16len),//~v568I~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v568I~
                puad->maxlen                                       //~v568I~
#else                                                              //~v568I~
                puad->maxlen,                                      //~v568I~
                puad->max16len                                     //~v568I~
#endif                                                             //~v568I~
                );                                                 //~v568I~
    else                                                           //~v6h5I~
    {                                                              //~v6h5I~
	    resctr=puad->allocctr+puad->alloc16ctr-puad->freectr-puad->free16ctr;//~v6h5I~
    	reslen=puad->alloclen+puad->alloc16len-puad->freelen-puad->free16len;//~v6h5I~
    }                                                              //~v6h5I~
#if defined(ULIB64X)&&!defined(_DEBUG)  //free size is not available//~v6hiI~
    rc=resctr!=0;                                                  //~v6hiI~
#else                                                              //~v6hiI~
    rc=(resctr || reslen);                                         //~v568R~
#endif                                                             //~v6hiI~
    if (Popt & UAC_EXIT)                                           //~v568I~
        if (rc)                                                    //~v568I~
        {                                                          //~v568I~
            if (Shfile)                                            //~v568I~
            {                                                      //~v568I~
            	fclose(Shfile);                                    //~v568I~
                Shfile=0;                                          //~v568I~
            }                                                      //~v568I~
#if defined(ULIB64X)&&!defined(_DEBUG)  //free size is not available//~v6hiI~
            uerrexit("==========MORE %ld times free required ===\n",0,//~v6hiR~
                        resctr);                                   //~v6hiI~
#else                                                              //~v6hiI~
            uerrexit("==========MORE %ld byete(%ld times) free required ===\n",0,//~v568I~
                        reslen,resctr);                            //~v568I~
#endif                                                             //~v6hiI~
        }                                                          //~v568I~
    return rc;                                                     //~v568I~
}//ualloc_chk                                                      //~v568I~

//*******************************************************
//*umalloc
//* malloc and check failed
//******************************************************
void *umalloc(size_t Psize)
{
        void *pvoid;
#ifdef W32      //win or wxe                                       //~v593I~
//  	ULONG retaddr,retaddr2;                                    //~v593R~//~v6hhR~
    	ULPTR retaddr,retaddr2;                                    //~v6hhI~
//    #if defined(ULIB64)||defined ULIB64X                         //~v6F0R~
        void* stacktrace[STACK_TRACE_CTR];                         //~v6F0R~
        int stctr;                                                 //~v6F0I~
//    #endif                                                       //~v6F0R~
#endif                                                             //~v593R~
//****************************
    if (!Psize)                                                 //~5213I~
                uerrexit("umalloc:request length is 0",                 //~5213I~
                                 "umalloc:要求長が 0");                         //~5213I~
#if !defined(DOS) || defined(DPMI)                                 //~v100I~
//  if (Psize>>24)                                                 //~v5dnR~
    if (Psize>MAX_MALLOC)                                          //~v5dnI~
        umallocsizeerr(Psize);                                     //~v100I~
#endif                                                             //~v100I~
// #ifdef WXE                                                      //~v570R~
//    pvoid=malloc(Psize);    //debug and rel                      //~v570R~
// #else                                                           //~v570R~
 #ifdef ULIB64X                                                    //~v6hiI~
    pvoid=malloc(Psize);                                           //~v6hiI~
 #else                                                             //~v6hiI~
  #if (_MSC_VER >=1020)     //vc++ enterprize version              //~v196I~
   #ifdef _DEBUG   //vcc6(wxe) DEBUG version                       //~v5jpI~
    pvoid=malloc(Psize);                                           //~v5jpI~
   #else                                                           //~v5jpI~
#ifdef WIN10                                                       //~v6G5I~
    pvoid=HeapAlloc(getHandle(),0,Psize);                          //~v6G5I~
#else                                                              //~v6G5I~
    pvoid=HeapAlloc(_crtheap,0,Psize);                             //~v196I~
#endif                                                             //~v6G5I~
   #endif                                                          //~v5jpI~
  #else                                                            //~v196I~
    pvoid=malloc(Psize);                                           //~v022R~
  #endif                                                           //~v196I~
 #endif                                                            //~v6hiI~
// #endif                                                          //~v570R~
    if (!pvoid)                                                    //~v022I~
    {                                                           //~5209I~
        ubell();                                                //~5930I~
                if (Sallocret)                                          //~5930I~
        {                                                       //~5930I~
                uerrmsg("!! storage shortage(reqsize=%d,current total=%ld) !!",//~5930I~
                        "!! 記憶域不足(要求長=%u,割り当済み合計長=%ld) !!",//~v030R~
//                      Psize,Gualloc_amount+Gualloc16_amount);            //~v076R~
                        Psize,Salloclen-Sfreelen+Salloc16len-Sfree16len);  //~v076I~
            return 0;                                               //~5930R~
                                                                //~5930I~
        }                                                       //~5930I~
                printf("\n!! storage shortage,malloc failed(reqsize=%u,current total=%ld) !!\n",//~v030R~
                                (unsigned)Psize,Gualloc_amount+Gualloc16_amount);  //~v053R~
                exit(UALLOC_FAILED);                                    //~5930R~
    }                                                           //~5209I~
        Sallocctr++;                                                //~5209R~
        #if (_MSC_VER >= 800)                                          //~v034I~
        if (!Sinitsw)                                              //~v034I~
                uallocvcinit();                                        //~v034I~
//      Salloclen+=(Ssizewk=uallocsz(Psize)+Ssizepos);             //~v034R~
	if (Sntsw)                                                     //~v133I~
     #if defined(ULIB64)||defined(ULIB64X)                         //~v6hiI~
     {                                                             //~v6hiI~
        Ssizewk=Psize;      //put request size on mtrace           //~v6hiR~
//      UTRACEP("malloc addr=%p,size=%d\n",pvoid,Psize);           //~v6L6R~
     }                                                             //~v6hiI~
     #else                                                         //~v6hiI~
      #ifdef _DEBUG   //vcc6(wxe) DEBUG version                    //~v5jpI~
        Ssizewk=uallocsz(Psize+DBGTRAILERSZ)+DBGCHUNKHDRSZ;        //~v5jpR~
      #else                                                        //~v5jpI~
        Ssizewk=( ( *(USHORT*)(void*) ((unsigned char*)pvoid-Ssizepos) ) <<3 );//by 8 byte with overhead//~v136R~
      #endif                                                       //~v5jpI~
     #endif                                                        //~v6hiI~
    else                                                           //~v133I~
        Ssizewk=( *(int *)(void*) ((unsigned char*)pvoid-Ssizepos) ) & 0x00fffffc;//~v154R~
        Salloclen+=Ssizewk;                                        //~v034I~
//      UTRACEP("addr=%08x,Psize=%08x,Ssizewk=%08x",pvoid,Psize,Ssizewk);//~v034R~
//      UTRACED("malloc",(char*)pvoid-Ssizepos,12);                //~v034R~
    #else                                                          //~v034I~
//      Salloclen+=(Ssizewk=uallocsz(Psize)+SIZEPOS);              //~v154R~
        Salloclen+=(Ssizewk=(long)(ULONG)(UINT)uallocsz(Psize)+SIZEPOS);//~v154R~
//      #ifdef OS2                                                 //~v106R~
                #if defined(OS2) || defined(DPMI)                          //~v106I~
            uallocmapset((char*)pvoid-SIZEPOS,Ssizewk);            //~v102R~
        #endif                                                     //~v102I~
    #endif                                                         //~v034I~
        Snetreqlen+=Psize;      //reqlen
        Smaxlenwk=Salloclen-Sfreelen;                               //~5209R~
        if (Gualloc_amount<Smaxlenwk)                               //~5209R~
                Gualloc_amount=Smaxlenwk;                               //~5209R~
        if (Sallocopt)                                              //~5209M~
        {                                                           //~5209M~
                if (Shfile)
#ifdef W32      //win or wxe                                       //~v593I~
                {                                                  //~v593I~
//    #if defined(ULIB64)||defined ULIB64X                         //~v6F0R~
//                  retaddr=((ULPTR)*(ULPTR*)((ULPTR)(&Psize)-PTRSZ));//caller ebp s.a//~v6hiR~//~v6F0R~
					stctr=ubacktrace(0,0/*skipctr*/,STACK_TRACE_CTR,stacktrace);//~v6F0I~
                    if (stctr>0)                                   //~v6F0I~
                    	retaddr=(ULPTR)stacktrace[0];              //~v6F0I~
                    else                                           //~v6F0I~
                    	retaddr=0;                                 //~v6F0I~
//    #else                                                        //~v6F0R~
//                    retaddr=((ULONG)*(ULONG*)((ULONG)&Psize-4));//caller ret addr//~v6F0R~
//    #endif                                                       //~v6F0R~
        			if (Sallocopt & UALLOC_TRACE2)	//2 level ret addr//~v593I~
                    {                                              //~v593I~
//    #if defined(ULIB64)||defined ULIB64X                         //~v6F0R~
//        #if defined(ULIB64X)&&!defined(_DEBUG)                   //~v6F0R~
//                        retaddr2=0;     //AMD64, frame ptr is not available//~v6F0R~
//        #else                                                    //~v6F0R~
//                        retaddr2=((ULPTR)*(ULPTR*)((ULPTR)&Psize-PTRSZ*2));//caller ebp s.a//~v6hiI~//~v6F0R~
//                        retaddr2=((ULPTR)*(ULPTR*)(retaddr2+PTRSZ));//caller ebp s.a//~v6hiI~//~v6F0R~
//        #endif                                                   //~v6F0R~
                    	if (stctr>1)                               //~v6F0I~
                    		retaddr2=(ULPTR)stacktrace[1];         //~v6F0I~
                    	else                                       //~v6F0I~
                    		retaddr2=0;                            //~v6F0I~
//    #else                                                        //~v6F0R~
//                        retaddr2=((ULONG)*(ULONG*)((ULONG)&Psize-8));//caller ebp s.a//~v6F0R~
//                        retaddr2=((ULONG)*(ULONG*)(retaddr2+4));//caller ebp s.a//~v6F0R~
//    #endif                                                       //~v6F0R~
                    }                                              //~v593I~
                    else                                           //~v593I~
                    	retaddr2=0;                                //~v593I~
//    #if defined(ULIB64)||defined ULIB64X                         //~v6F0R~
//        #if defined(ULIB64X)&&!defined(_DEBUG)                   //~v6F0R~
//                    fprintf(Shfile,"malloc  :addr=%p,len=%08lX,cur-tot=%08lX,retaddr=%p,hra=N/A\n",//~v6F0R~
//                                           pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16,retaddr);//~v6F0R~
//        #else                                                    //~v6F0R~
                    fprintf(Shfile,"malloc  :addr=%p,len=%08lX,cur-tot=%08lX,retaddr=%p,hra=%p\n",//~v6hhI~
//                                         pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16,retaddr,retaddr2);//~v6G6R~
                                           pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16,(void*)retaddr,(void*)retaddr2);//~v6G6I~
//         #endif                                                  //~v6F0R~
//    #else                                                        //~v6F0R~
//                    fprintf(Shfile,"malloc  :addr=%08lX,len=%08lX,cur-tot=%08lX,retaddr=%08lX,hra=%08lX\n",//~v6F0R~
//                            (unsigned long)pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16,retaddr,retaddr2);//~v6F0R~
//    #endif                                                       //~v6F0R~
                }                                                  //~v593I~
#else                                                              //~v593I~
                        fprintf(Shfile,"malloc  :addr=%08lX,len=%08lX,cur-tot=%08lX\n",//~5827R~
                                (unsigned long)pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16);//~v053R~
#endif                                                             //~v593I~
        }
        return pvoid;
}//umalloc

//*******************************************************
//*ucalloc
//* calloc and check failed
//******************************************************
void *ucalloc(size_t Pno,size_t Psize)
{
        void *pvoid;
    size_t total;                                                  //~v100I~
#ifdef W32      //win or wxe                                       //~v593I~
//  	ULONG retaddr,retaddr2;                                    //~v593I~//~v6hhR~
    	ULPTR retaddr,retaddr2;                                    //~v6hhI~
//    #if defined(ULIB64)||defined ULIB64X                         //~v6F0R~
        void* stacktrace[STACK_TRACE_CTR];                         //~v6F0R~
        int stctr;                                                 //~v6F0I~
//    #endif                                                       //~v6F0R~
#endif                                                             //~v593I~
//****************************
    if (!(total=Psize*Pno))                                        //~v100R~
                uerrexit("ucalloc:request length is 0",                 //~5213I~
                                 "ucalloc:要求長が 0");                         //~5213I~
#if !defined(DOS) || defined(DPMI)                                 //~v100I~
//  if (total>>24)                                                 //~v5dnR~
    if (total>MAX_MALLOC)                                          //~v5dnI~
        umallocsizeerr(total);                                     //~v100I~
#endif                                                             //~v100I~
// #ifdef WXE                                                      //~v570R~
//    pvoid=calloc(Pno,Psize);                                     //~v570R~
// #else                                                           //~v570R~
 #ifdef ULIB64X                                                    //~v6hiI~
    pvoid=calloc(Pno,Psize);                                       //~v6hiI~
 #else                                                             //~v6hiI~
  #if (_MSC_VER >=1020)     //vc++ enterprize version              //~v196I~
   #ifdef _DEBUG   //vcc6(wxe) DEBUG version                       //~v5jpI~
    pvoid=calloc(Pno,Psize);                                       //~v5jpI~
   #else                                                           //~v5jpI~
#ifdef WIN10                                                       //~v6G5I~
    pvoid=HeapAlloc(getHandle(),0,Psize*Pno);                      //~v6G5I~
#else                                                              //~v6G5I~
    pvoid=HeapAlloc(_crtheap,0,Psize*Pno);                         //~v196I~
#endif                                                             //~v6G5I~
    if (pvoid)                                                     //~v196I~
    	memset(pvoid,0,Psize*Pno);                                 //~v196I~
   #endif                                                          //~v5jpI~
  #else                                                            //~v196I~
    pvoid=calloc(Pno,Psize);                                       //~v022I~
  #endif                                                           //~v196I~
 #endif                                                            //~v6hiI~
// #endif                                                          //~v570R~
    if (!pvoid)                                                    //~v022R~
    {                                                           //~5209I~
        ubell();                                                //~5930I~
                if (Sallocret)                                          //~5930I~
        {                                                       //~5930I~
                uerrmsg("!! storage shortage(reqsize=%u,current total=%ld) !!",//~v030R~
                        "!! 記憶域不足(要求長=%d,割り当済み合計長=%ld) !!",//~5930I~
//                              Pno*Psize,Gualloc_amount+Gualloc16_amount);        //~v076R~
                        Pno*Psize,Salloclen-Sfreelen+Salloc16len-Sfree16len);//~v076I~
            return 0;                                               //~5930R~
                                                                //~5930I~
        }                                                       //~5930I~
                printf("\n!! storage shortage,calloc failed(req no=%u,size=%u,current amount=%ld)!!\n",//~v053R~
                                (unsigned)Pno,(unsigned)Psize,Gualloc_amount+Gualloc16_amount);//~v053R~
                exit(UALLOC_FAILED);                                    //~5930R~
        }                                                           //~5209I~
        Sallocctr++;                                                //~5209R~
        #if (_MSC_VER >= 800)                                          //~v034I~
        if (!Sinitsw)                                              //~v034I~
                uallocvcinit();                                        //~v034I~
//      Salloclen+=(Ssizewk=uallocsz(Pno*Psize)+Ssizepos);         //~v034R~
	if (Sntsw)                                                     //~v133I~
     #if defined(ULIB64)||defined(ULIB64X)                         //~v6hiI~
        Ssizewk=Psize*Pno;        //request size                   //~v6hiR~
     #else                                                         //~v6hiI~
      #ifdef _DEBUG   //vcc6(wxe) DEBUG version                    //~v5jpI~
        Ssizewk=uallocsz(Psize*Pno+DBGTRAILERSZ)+DBGCHUNKHDRSZ;    //~v5jpR~
      #else                                                        //~v5jpI~
        Ssizewk=( ( *(USHORT*)(void*) ((unsigned char*)pvoid-Ssizepos) ) <<3);//~v133I~
      #endif                                                       //~v5jpI~
     #endif                                                        //~v6hiI~
    else                                                           //~v133I~
        Ssizewk=( *(int *)(void*) ((unsigned char*)pvoid-Ssizepos) ) & 0x00fffffc;//~v034R~
        Salloclen+=Ssizewk;                                        //~v034I~
//      UTRACEP("addr=%08x,Pno=%08x,Psize=%08x,Ssizewk=%08x",pvoid,Pno,Psize,Ssizewk);//~v034R~
//      UTRACED("malloc",(char*)pvoid-Ssizepos,12);                //~v034R~
    #else                                                          //~v034I~
//      Salloclen+=(Ssizewk=uallocsz(Pno*Psize)+SIZEPOS);          //~v154R~
        Salloclen+=(Ssizewk=(long)(ULONG)(UINT)uallocsz(Pno*Psize)+SIZEPOS);//~v154R~
//      #ifdef OS2                                                 //~v106R~
                #if defined(OS2) || defined(DPMI)                          //~v106I~
            uallocmapset((char*)pvoid-SIZEPOS,Ssizewk);            //~v102I~
        #endif                                                     //~v102I~
    #endif                                                         //~v034I~
        Snetreqlen+=Pno*Psize;
        Smaxlenwk=Salloclen-Sfreelen;                               //~5209R~
        if (Gualloc_amount<Smaxlenwk)                               //~5209R~
                Gualloc_amount=Smaxlenwk;                               //~5209R~
        if (Sallocopt)                                              //~5209M~
        {                                                           //~5209M~
                if (Shfile)
#ifdef W32      //win or wxe                                       //~v593I~
                {                                                  //~v593I~
//    #if defined(ULIB64)||defined ULIB64X                         //~v6F0R~
//                  retaddr=((ULPTR)*(ULPTR*)((ULPTR)&Pno-PTRSZ));//caller RIP//~v6hiI~//~v6F0R~
					stctr=ubacktrace(0,0/*skipctr*/,STACK_TRACE_CTR,stacktrace);//~v6F0I~
                    if (stctr>0)                                   //~v6F0I~
                    	retaddr=(ULPTR)stacktrace[0];              //~v6F0I~
                    else                                           //~v6F0I~
                    	retaddr=0;                                 //~v6F0I~
//    #else                                                        //~v6F0R~
//                    retaddr=((ULONG)*(ULONG*)((ULONG)&Pno-4));//caller ebp s.a//~v6F0R~
//    #endif                                                       //~v6F0R~
        			if (Sallocopt & UALLOC_TRACE2)	//2 level ret addr//~v593I~
                    {                                              //~v593I~
//    #if defined(ULIB64)||defined ULIB64X                         //~v6F0R~
//        #if defined(ULIB64X)&&!defined(_DEBUG)                   //~v6F0R~
//                        retaddr2=0;     //AMD64, frame ptr is not available//~v6F0R~
//        #else                                                    //~v6F0R~
//                        retaddr2=((ULPTR)*(ULPTR*)((ULPTR)&Pno-PTRSZ*2));//caller ebp s.a//~v6hiI~//~v6F0R~
//                        retaddr2=((ULPTR)*(ULPTR*)(retaddr2+PTRSZ));//caller ebp s.a//~v6hiI~//~v6F0R~
//        #endif                                                   //~v6F0R~
                    	if (stctr>1)                               //~v6F0I~
                    		retaddr2=(ULPTR)stacktrace[1];         //~v6F0I~
                    	else                                       //~v6F0I~
                    		retaddr2=0;                            //~v6F0I~
//    #else                                                        //~v6F0R~
////                      retaddr2=((ULONG)*(ULONG*)((ULONG)&Psize-8));//caller ebp s.a//~v593I~//~v6F0R~
//                        retaddr2=((ULONG)*(ULONG*)((ULONG)&Pno-8));//caller ebp s.a//~v6F0R~
//                        retaddr2=((ULONG)*(ULONG*)(retaddr2+4));//caller ebp s.a//~v6F0R~
//    #endif                                                       //~v6F0R~
                    }                                              //~v593I~
                    else                                           //~v593I~
                    	retaddr2=0;                                //~v593I~
//    #if defined(ULIB64)||defined ULIB64X                         //~v6F0R~
//        #if defined(ULIB64X)&&!defined(_DEBUG)                   //~v6F0R~
//                    fprintf(Shfile,"calloc  :addr=%p,len=%08lX,cur-tot=%08lX,retaddr=%p,hra=N/A\n",//~v6F0R~
//                                           pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16,retaddr);//~v6F0R~
//        #else                                                    //~v6F0R~
                    fprintf(Shfile,"calloc  :addr=%p,len=%08lX,cur-tot=%08lX,retaddr=%p,hra=%p\n",//~v6hhI~
//                                         pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16,retaddr,retaddr2);//~v6G6R~
                                           pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16,(void*)retaddr,(void*)retaddr2);//~v6G6I~
//        #endif                                                   //~v6F0R~
//    #else                                                        //~v6F0R~
//                    fprintf(Shfile,"calloc  :addr=%08lX,len=%08lX,cur-tot=%08lX,retaddr=%08lX,hra=%08lX\n",//~v6F0R~
//                            (unsigned long)pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16,retaddr,retaddr2);//~v6F0R~
//    #endif                                                       //~v6F0R~
                }                                                  //~v593I~
#else                                                              //~v593I~
                        fprintf(Shfile,"calloc  :addr=%08lX,len=%08lX,cur-tot=%08lX\n",//~5827R~
                                (unsigned long)pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16);//~v053R~
#endif                                                             //~v593I~
        }
        return pvoid;
}//ucalloc

//*******************************************************
//*ufree
//* parm chk and free
//******************************************************
void ufree(void *Paddr)
{
#ifdef DOS                                                         //~v022I~
static int Sfreeerr;                                               //~v053I~
#else                                                              //~v022I~
#ifdef W32                                                         //~v022I~
static int Sfreeerr;                                               //~v022I~
#else                   //os/2                                             //~v022I~
static int Sfreeerr;
#endif                                                             //~v022I~
#endif                                                             //~v022I~
#ifdef W32      //win or wxe                                       //~v6hBI~
    ULPTR retaddr,retaddr2;                                        //~v6hBI~
        void* stacktrace[STACK_TRACE_CTR];                         //~v6F0I~
        int stctr;                                                 //~v6F0I~
#endif                                                             //~v6hBI~
//****************************
    if (!Paddr)
                uerrexit("ufree:Null addr parm",
                                 "ufree:NULL アドレスパラメータ");
#ifdef DOS
  #ifdef DPMI                                   //DPMI version                     //~v053I~
        if (*((char*)Paddr-MAGICPOS)!=MALLOCID)                        //~v053M~
  #else                       //not DPMI                           //~v053I~
        if (*((char*)Paddr-SIZEPOS) & 0x01)                            //~v058I~
  #endif                      //DPMI or not                        //~v053I~
                if (!Sfreeerr)                                             //~v053I~
                {                                                          //~v053I~
                        Sfreeerr=1;                                            //~v053I~
                        uerrexit("ufree:%p is not malloc area",                //~v053I~
                                         "ufree:%p は malloc されていません",          //~v053I~
                                          Paddr);                                      //~v053I~
                }                                                          //~v053I~
#else
#ifdef W32                                                         //~v022I~
        #if (_MSC_VER >= 800)                                          //~v034I~
        if (!Sinitsw)                                              //~v034I~
                uallocvcinit();                                        //~v034I~
	if (!Sntsw)                                                    //~v133I~
    {                                                              //~v136I~
        if ((*((char*)Paddr-Ssizepos) & 0x01)   //freed        //~v034R~//~v034R~
        ||  *((char*)Paddr-Ssizepos+3)!=MALLOCID)       //freed    //~v034R~//~v034R~
                if (!Sfreeerr)                                     //~v034I~//~v034R~
                {                                                  //~v034I~//~v034R~
                        Sfreeerr=1;                                    //~v034I~//~v034R~
                        uerrexit("ufree:%08lX is not malloc area",     //~v034I~//~v034R~
                                         "ufree:%08lX は malloc されていません",//~v034I~//~v034R~
                                          Paddr);                              //~v034I~//~v034R~
                }                                                  //~v034I~//~v034R~
	}                                                              //~v136I~
    else                                                           //~v136I~
    {                                                              //~v136I~
     #ifdef ULIB64X                                                //~v6hiI~
       #ifdef _DEBUG                                               //~v6hiI~
        if (((ULPTR)Paddr & 0x0f)   						//not DWORD boundary//~v6hiR~//~v6hhR~
        ||  (*(long *)((ULPTR)Paddr-DBGALLOCSIGNFLD)!=DBGALLOCED)   //not alloced//~v6hiR~//~v6hhR~
        )    //I dont know allocation bit of Vista                 //~v6hiI~
       #else                                                       //~v6hiI~
        if (0)  //i do not know alloc flag etc                     //~v6hiR~
       #endif                                                      //~v6hiI~
     #else                                                         //~v6hiI~
        if (((ULONG)Paddr & 0x07)   						//not DWORD boundary//~v136R~
      #ifdef _DEBUG   //vcc6(wxe) DEBUG version                    //~v5jpI~
        ||  !(*(ULONG*)((ULONG)Paddr-DBGALLOCSIGNFLD)==DBGALLOCED))   //not alloced//~v5jpI~
      #else                                                        //~v5jpI~
//      ||  !(*((char*)Paddr-SIZEPOSNT+5) & 0x01))   //not alloced //~v5jpR~
        )    //I dont know allocation bit of Vista                 //~v5jpI~
      #endif                                                       //~v5jpI~
     #endif  //!ULIB64X                                            //~v6hiI~
            if (!Sfreeerr)                                         //~v136I~
            {                                                      //~v136I~
                Sfreeerr=1;                                        //~v136I~
//              uerrexit("ufree:%08lX is not malloc area",         //+v7e2R~
//                               "ufree:%08lX は malloc されていません",//+v7e2I~
                uerrexit("ufree:%p is not malloc area",            //+v7e2I~
                                 "ufree:%p は malloc されていません",//+v7e2I~
                                  Paddr);                          //~v136I~
            }                                                      //~v136I~
	}                                                              //~v136I~
    #else                                                          //~v034I~
        if (!(*((char*)Paddr-SIZEPOS) & 0x01))  //freed                //~v022R~
                if (!Sfreeerr)                                             //~v022I~
                {                                                          //~v022I~
                        Sfreeerr=1;                                            //~v022I~
                        uerrexit("ufree:%08lX is not malloc area",             //~v022I~
                                         "ufree:%08lX は malloc されていません",       //~v022I~
                                          Paddr);                                      //~v022I~
                }                                                          //~v022I~
    #endif                                                         //~v034I~
#else                   //os/2                                             //~v022I~
        if (*((USHORT*)Paddr-1)!=MALLOCID)
                if (!Sfreeerr)
                {
                        Sfreeerr=1;
                        uerrexit("ufree:%08lX is not malloc area",
                                         "ufree:%08lX は malloc されていません",
                                          Paddr);
                }
#endif                                                             //~v022I~
#endif
        Sfreectr++;                                                 //~5209R~
  #if defined(ULIB64)||defined(ULIB64X)                            //~v6hiI~
        Sfreelen+=(Ssizewk=ufreesz(Paddr));                        //~v6hiR~
  #else                                                            //~v6hiI~
        #if (_MSC_VER >= 800)                                          //~v034I~
      #ifdef _DEBUG   //vcc6(wxe) DEBUG version                    //~v5jpI~
        Sfreelen+=(Ssizewk=ufreesz(Paddr)+DBGCHUNKHDRSZ);          //~v5jpR~
      #else                                                        //~v5jpI~
        Sfreelen+=(Ssizewk=ufreesz(Paddr)+Ssizepos);               //~v034I~
      #endif                                                       //~v5jpI~
//      UTRACEP("free addr=%08x,Ssizewk=%08x",Paddr,Ssizewk);      //~v034R~
//      UTRACED("free",(char*)Paddr-Ssizepos*4,32);                //~v034R~
    #else                                                          //~v034I~
//      Sfreelen+=(Ssizewk=ufreesz(Paddr)+SIZEPOS);                //~v154R~
        Sfreelen+=(Ssizewk=(long)(ULONG)(UINT)ufreesz(Paddr)+SIZEPOS);//~v154R~
    #endif                                                         //~v034I~
  #endif  //!ULIB64X                                               //~v6hiI~
        if (Sallocopt)                                              //~5209M~
        {                                                           //~5209M~
                if (Shfile)
                {                                                  //~v5ncI~
                        if (Ssizewk)
                        {                                                   //~4C24I~
#ifdef W32                                                         //~v6hBI~
//    #if defined(ULIB64)||defined ULIB64X                         //~v6F0R~
//                            retaddr=((ULPTR)*(ULPTR*)((ULPTR)(&Paddr)-PTRSZ));//caller ebp s.a//~v6F0R~
//    #else                                                        //~v6F0R~
//                            retaddr=((ULONG)*(ULONG*)((ULONG)&Paddr-4));//caller ret addr//~v6F0R~
//    #endif                                                       //~v6F0R~
							stctr=ubacktrace(0,0/*skipctr*/,STACK_TRACE_CTR,stacktrace);//~v6F0I~
                    		if (stctr>0)                           //~v6F0I~
                    			retaddr=(ULPTR)stacktrace[0];      //~v6F0I~
                   			else                                   //~v6F0I~
                    			retaddr=0;                         //~v6F0I~
        					if (Sallocopt & UALLOC_TRACE2)	//2 level ret addr//~v6hBI~
                    		{                                      //~v6hBI~
//    #if defined(ULIB64)||defined ULIB64X                         //~v6F0R~
//        #if defined(ULIB64X)&&!defined(_DEBUG)                   //~v6F0R~
//                                retaddr2=0;     //AMD64, frame ptr is not available//~v6F0R~
//        #else                                                    //~v6F0R~
//                                retaddr2=((ULPTR)*(ULPTR*)((ULPTR)&Paddr-PTRSZ*2));//caller ebp s.a//~v6F0R~
//                                retaddr2=((ULPTR)*(ULPTR*)(retaddr2+PTRSZ));//caller ebp s.a//~v6F0R~
//        #endif                                                   //~v6F0R~
                    			if (stctr>1)                       //~v6F0I~
                    				retaddr2=(ULPTR)stacktrace[1]; //~v6F0I~
                    			else                               //~v6F0I~
                    				retaddr2=0;                    //~v6F0I~
//    #else                                                        //~v6F0R~
//                                retaddr2=((ULONG)*(ULONG*)((ULONG)&Paddr-8));//caller ebp s.a//~v6F0R~
//                                retaddr2=((ULONG)*(ULONG*)(retaddr2+4));//caller ebp s.a//~v6F0R~
//    #endif                                                       //~v6F0R~
                    		}                                      //~v6hBI~
                    		else                                   //~v6hBI~
                    			retaddr2=0;                        //~v6hBI~
#endif	//W32                                                      //~v6hBI~
                                Smaxlenwk=Salloclen-Sfreelen;                   //~4C24I~
    #ifdef ULIB64X                                                 //~v6hhI~
//                              fprintf(Shfile,"free    :addr=%p,len=%08lX,cur-tot=%08lX\n",//~v6hhI~//~v6hBR~
//                                                            Paddr,Ssizewk,Smaxlenwk+Smaxlenwk16);//~v6hhI~//~v6hBR~
                                fprintf(Shfile,"free    :addr=%p,len=%08lX,cur-tot=%08lX,retaddr=%p,hra=%p\n",//~v6hBI~
//                                                            Paddr,Ssizewk,Smaxlenwk+Smaxlenwk16,retaddr,retaddr2);//~v6G6R~
                                                              Paddr,Ssizewk,Smaxlenwk+Smaxlenwk16,(void*)retaddr,(void*)retaddr2);//~v6G6I~
    #else                                                          //~v6hhI~
//                              fprintf(Shfile,"free    :addr=%08lX,len=%08lX,cur-tot=%08lX\n",//~5827R~//~v6hBR~
//                                             (unsigned long)Paddr,Ssizewk,Smaxlenwk+Smaxlenwk16);//~v053R~//~v6hBR~
//                              fprintf(Shfile,"free    :addr=%08lX,len=%08lX,cur-tot=%08lX,retaddr=%p,hra=%p\n",//~v6hBI~//~v6L6R~
                                fprintf(Shfile,"free    :addr=%08lX,len=%08lX,cur-tot=%08lX,retaddr=%p,hra=%p\n",//~v6L6I~
                                               (unsigned long)Paddr,Ssizewk,Smaxlenwk+Smaxlenwk16,(void*)retaddr,(void*)retaddr2);//~v6hBI~//~v6L6R~
    #endif                                                         //~v6hhI~
                        }                                                   //~4C24I~
                        else
                                uerrexit("ufree:%08lX is length 0 at free",
                                                 "ufree:%08lX は フリー時の長さが 0",
                                                  Paddr);
                }                                                  //~v5ncI~
        }
   #ifdef ULIB64X                                                  //~v6hiI~
        free(Paddr);                                               //~v6hiI~
   #else                                                           //~v6hiI~
  	#if (_MSC_VER >=1020)     //vc++ enterprize version            //~v570I~
      #ifdef _DEBUG   //vcc6(wxe) DEBUG version                    //~v5jpI~
        free(Paddr);                                               //~v5jpI~
      #else                                                        //~v5jpI~
#ifdef WIN10                                                       //~v6G5I~
        HeapFree(getHandle(),0,Paddr);                             //~v6G5I~
#else                                                              //~v6G5I~
        HeapFree(_crtheap,0,Paddr);                                //~v570I~
#endif                                                             //~v6G5I~
      #endif                                                       //~v5jpI~
  	#else                                                          //~v570I~
        free(Paddr);
    #endif                                                         //~v570I~
   #endif //!ULIB64X                                               //~v6hiI~
        return;
}//ufree

#ifdef DOS
#else
#ifdef W32                                                         //~v022I~
#else                                                              //~v022R~
//*******************************************************
//*umalloc16
//* malloc 16bit storage(max 64k and tile memory) and check failed
//******************************************************
void *umalloc16(size_t Psize)
{
        void *pvoid;
//****************************
    if (!(pvoid=_tmalloc(Psize)))
    {                                                           //~5930I~
        ubell();                                                //~5930I~
                if (Sallocret)                                          //~5930I~
        {                                                       //~5930I~
                        uerrmsg("umalloc16:_tmalloc failed(size=%d)",       //~5930R~
                                        "umalloc16:_tmalloc の失敗(長さ=%d)",       //~5930I~
                                        Psize);                                     //~5930I~
            return 0;                                               //~5930R~
                }                                                       //~5930I~
                printf("\n!! umalloc16:_tmalloc failed(size=%d)\n",     //~5930R~
                                 Psize);                                        //~5930M~
                exit(UALLOC_FAILED);                                    //~5930I~
        }                                                           //~5930I~
//  if (Sallocopt)                                                 //~v102R~
//  {                                                              //~v102R~
                Salloc16ctr++;
                Salloc16len+=(Ssizewk=uallocsz(Psize)+SIZEPOS);         //~5827R~
        uallocmapset((char*)pvoid-SIZEPOS,Ssizewk);                //~v102I~
                Snetreq16len+=Psize;
                Smaxlenwk16=Salloc16len-Sfree16len;                     //~5827R~
                if (Gualloc16_amount<Smaxlenwk16)                       //~5827R~
                        Gualloc16_amount=Smaxlenwk16;                       //~5827R~
    if (Sallocopt)                                                 //~v102I~
    {                                                              //~v102I~
                if (Shfile)                                             //~5827I~
                        fprintf(Shfile,"malloc16:addr=%08lX,len=%08lX,cur-tot=%08lX\n",//~5827I~
                                pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16);       //~5827I~
        }
        return pvoid;
}//umalloc16

//*******************************************************
//*ucalloc16
//* calloc 16bit storage(max 64k and tile memory) and check failed
//******************************************************
void *ucalloc16(size_t Pno,size_t Psize)
{
        void *pvoid;
//****************************
    if (!(pvoid=_tcalloc(Pno,Psize)))
    {                                                           //~5930I~
        ubell();                                                //~5930I~
                if (Sallocret)                                          //~5930I~
        {                                                       //~5930I~
                        uerrmsg("ucalloc16:_tcalloc failed(no=%d,size=%d)", //~5930I~
                                         "ucalloc16:_tcalloc の失敗(数=%d,長さ=%d)",//~5930I~
                                         Pno,Psize);                                //~5930I~
            return 0;                                               //~5930R~
                }                                                       //~5930I~
                printf("\n!! ucalloc16:_tcalloc failed(no=%d,size=%d) !!\n",//~5930R~
                                 Pno,Psize);
                exit(UALLOC_FAILED);                                    //~5930I~
        }                                                           //~5930I~
//  if (Sallocopt)                                                 //~v102R~
//  {                                                              //~v102R~
                Salloc16ctr++;
                Salloc16len+=(Ssizewk=uallocsz(Pno*Psize)+SIZEPOS);     //~5827R~
        uallocmapset((char*)pvoid-SIZEPOS,Ssizewk);                //~v102I~
                Snetreq16len+=Pno*Psize;
                Smaxlenwk16=Salloc16len-Sfree16len;                     //~5827R~
                if (Gualloc16_amount<Smaxlenwk16)                       //~5827R~
                        Gualloc16_amount=Smaxlenwk16;                       //~5827R~
    if (Sallocopt)                                                 //~v102I~
    {                                                              //~v102I~
                if (Shfile)                                             //~5827I~
                        fprintf(Shfile,"calloc16:addr=%08lX,len=%08lX,cur-tot=%08lX\n",//~5827I~
                                pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16);       //~5827I~
        }
        return pvoid;
}//ucalloc16

//*******************************************************
//*ufree16
//* free 16bit storage
//******************************************************
void ufree16(void * Ppvoid)
{
static int Sfreeerr;
//****************************
    if (!Ppvoid)
                uerrexit("ufree16:Null addr parm",
                                 "ufree16:NULL アドレスパラメータ");
        if (*((USHORT*)Ppvoid-1)!=MALLOC16ID)
                if (!Sfreeerr)
                {
                        Sfreeerr=1;
                        uerrexit("ufree16:%08lX is not malloc(SEG16) area",
                                         "ufree16:%08lX は malloc(SEG16) されていません",
                                          Ppvoid);
                }
        if (Sallocopt)
        {
                Sfree16ctr++;
                Sfree16len+=(Ssizewk=ufreesz(Ppvoid)+SIZEPOS);          //~5827R~
                if (Shfile)                                             //~5827I~
                        if (Ssizewk)                                        //~5827I~
                        {                                                   //~5827I~
                                Smaxlenwk=Salloclen-Sfreelen;                   //~5827I~
                                fprintf(Shfile,"free16  :addr=%08lX,len=%08lX,cur-tot=%08lX\n",//~5827I~
                                               Ppvoid,Ssizewk,Smaxlenwk+Smaxlenwk16);//~5827I~
                        }                                                   //~5827I~
                        else                                                //~5827I~
                                uerrexit("ufree16:%08lX is length 0 at free",   //~5827I~
                                                 "ufree16:%08lX は フリー時の長さが 0", //~5827I~
                                                  Ppvoid);                              //~5827I~
        }
    _tfree(Ppvoid);
        return;
}//ufree16

#endif   //not W32                                                 //~v022R~
#endif

//*******************************************************
//*uallocsz
//* get shift up size of malloc
//*    size by power of 2 containing 16 malloc byte hdr size
//* parm1 :request len
//* return:shift up len(overhead len is not contained)             //~v136R~
//******************************************************
int uallocsz(size_t Plen)
{
#ifdef DOS
    #ifdef DPMI                                 //DPMI version                     //~v053I~
//      size_t len=8;                                              //~v084R~
        size_t len,n;                                              //~v084I~
//      for (Plen+=SIZEPOS;len<Plen;)                              //~v071R~
//              len<<=1;                                               //~v071R~
        Plen+=SIZEPOS;                                             //~v071I~
        if (Plen>=PAGESIZE)                                        //~v071I~
//              Plen-=PAGESIZE;     //unsigned,so chk by plus value    //~v084R~
            n=len=PAGESIZE;     //start from 4k                    //~v084I~
        else                                                       //~v084I~
        {                                                          //~v084I~
            n=0;                                                   //~v084I~
            len=8;              //start from 4                     //~v084I~
                }                                                          //~v084I~
//      while(len<Plen)                                            //~v084R~
        while(len+n<Plen)                                          //~v084I~
                len<<=1;                                               //~v071I~
        if (len>=PAGESIZE)  //bucket no>=9                         //~v071R~
                len+=PAGESIZE;                                         //~v071I~
//                      fprintf(Shfile,"uallocsz:         reqen=%08lX,getlen =%08lX\n",//~v071R~
//                                            Plen   ,len                  );//@@@@//~v071R~
        return (len-SIZEPOS);                                      //~v053R~
    #else                       //not DPMI                         //~v053I~
        return (int)((Plen+1)&0xfffe);                                 //~v022R~
    #endif                      //DPMI or not                      //~v053I~
#else
        #ifdef W32                                                     //~v022I~
                #if (_MSC_VER >= 800)                                      //~v034I~
                if (!Sinitsw)                                          //~v034I~
                uallocvcinit();                                    //~v034I~
        if (Sinitsw)                                               //~v136I~
          #if defined(ULIB64)||defined(ULIB64X)   //uallocsz is not called//~v6hiR~
            return (int)((Plen+0x0f)&0xfffffff0);//8 byte boundary //~v6hiI~
          #else                                                    //~v6hiI~
            return (int)((Plen+7)&0xfffffff8);//8 byte boundary    //~v136I~
          #endif                                                   //~v6hiI~
        else                                                       //~v136I~
            if (Sdebugsw)                                          //~v034R~
                        return (int)((Plen+7)&0xfffffffc);//4 byte boundary up //~v034I~//~v034R~
            else                                                   //~v034R~
            {                                                      //~v034I~
                if (Plen<=8)                                       //~v034I~
                        return 12;                                     //~v034I~
                        return (int)((Plen+3)&0xfffffffc);//4 byte boundary up //~v034I~//~v034I~
            }                                                      //~v034R~
        #else                                                      //~v034I~
        if (Plen<8)                                                //~v022I~
                return 8+8-SIZEPOS;                                    //~v022I~
                return (int)(((Plen+3)&0xfffffffc)+8-SIZEPOS);//add SIZEPOS later//~v022R~
        #endif                                                     //~v034I~
    #else                                                          //~v022I~
        int power;
        size_t len;
        len=Plen+16-1;  //16 byte malloc hdr size and for just size
        for (power=0;len;power++)
                len>>=1;
        return ((1<<power)-16);
        #endif                                                         //~v022I~
#endif
}//uallocsz

//*******************************************************
//*ufreesz
//* get buff size from malloc hdr
//* parm1 :malloc area
//* return:buffsize
//******************************************************
int ufreesz(void *Ppvoid)
{
#ifdef DOS                                                         //~v071I~
    #ifdef DPMI                                 //DPMI version                     //~v071I~
        int freesz;                                                //~v071I~
    #else                       //not DPMI                         //~v071I~
    #endif                      //DPMI or not                      //~v071I~
#else                                                              //~v071I~
    int freesz;                                                    //~v099I~
#endif                                                             //~v071I~
//***********************
#ifdef DOS                                                         //~v022I~
    #ifdef DPMI                                 //DPMI version                     //~v053I~
//      return (8<<(int)(*((unsigned char*)Ppvoid-BACKETNOPOS)))-SIZEPOS;//~v071R~
        freesz=(8<<(int)(*((unsigned char*)Ppvoid-BACKETNOPOS)));  //~v071I~
        if (freesz>=PAGESIZE)                                      //~v071I~
                freesz+=PAGESIZE;                                      //~v071I~
//                      fprintf(Shfile,"ufreesz :         overh=%08lX,freesz =%08lX\n",//~v071R~
//                       *((int*)Ppvoid-1),                        //~v071R~
//                                                    freesz               );  //@@@@//~v071R~
        if (freesz>>24)                                            //~v099I~
            ufreesizeerr(Ppvoid);                                  //~v099I~
        return freesz-SIZEPOS;                                     //~v071I~
    #else                       //not DPMI                         //~v053I~
        return uallocsz(*(unsigned int *)(void*)((unsigned char*)Ppvoid-SIZEPOS));//~v022I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v022I~
        #ifdef W32                                                     //~v022I~
                #if (_MSC_VER >= 800)                                      //~v034I~
                if (!Sinitsw)                                          //~v034I~
                uallocvcinit();                                    //~v034I~
//                      return ((*(int *)(void*)((unsigned char*)Ppvoid-Ssizepos))&0x00fffffc)-Ssizepos;//~v099R~
         #if defined(ULIB64)||defined(ULIB64X)                     //~v6hiI~
           #ifdef _DEBUG                                           //~v6hiR~
            freesz=*(long*)(ULPTR)((unsigned char*)Ppvoid-SIZEPOS);//~v6hiR~//~v6hhR~
           #else                                                   //~v6hiI~
            freesz=4;     //not 0   for uerrexit(freesz==0)        //~v6hiR~
           #endif                                                  //~v6hiI~
         #else                                                     //~v6hiM~
		  if (Sntsw)	                                           //~v133I~
           #ifdef _DEBUG   //vcc6(wxe) DEBUG version               //~v5jpI~
          {                                                        //~v5jpI~
            freesz=*(ULONG*)(ULONG)((unsigned char*)Ppvoid-DBGCHUNKHDRSZ)+DBGTRAILERSZ;//~v5jpR~
            freesz=(int)((freesz+7)&0xfffffff8);//8 byte boundary  //~v5jpI~
          }                                                        //~v5jpI~
           #else                                                   //~v5jpI~
            freesz=((*(USHORT*)(void*)((unsigned char*)Ppvoid-Ssizepos))<<3)-Ssizepos;//~v133I~
           #endif                                                  //~v5jpI~
          else                                                     //~v133I~
            freesz=((*(int *)(void*)((unsigned char*)Ppvoid-Ssizepos))&0x00fffffc)-Ssizepos;//~v099I~
         #endif   //!ULIB64X                                       //~v6hiM~
        #else                                                      //~v034I~
//      return (int)(*(unsigned int *)(void*)((unsigned char*)Ppvoid-SIZEPOS)&0xfffffffe);//~v099R~
            freesz=(int)(*(unsigned int *)(void*)((unsigned char*)Ppvoid-SIZEPOS)&0xfffffffe);//~v099I~
        #endif                                                     //~v034I~
    #else                                                          //~v022I~
//  return uallocsz(*(unsigned int *)(void*)((unsigned char*)Ppvoid-SIZEPOS));//~v099R~
        freesz=uallocsz(*(unsigned int *)(void*)((unsigned char*)Ppvoid-SIZEPOS));//~v099I~
    #endif                                                         //~v022I~
  #if !(defined(ULIB64)||defined(ULIB64X))                         //~v6q9R~
//  if (freesz>>24)                                                //~v099I~//~v6huR~
//  if (freesz>>25)                                                //~v6huI~//~v6J0R~
    if (freesz>MAX_MALLOC)                                         //~v6J0R~
        ufreesizeerr(Ppvoid);                                      //~v099I~
  #endif                                                           //~v6q9M~
    return freesz;                                                 //~v099I~
#endif                                                             //~v022I~
}//ufreesz

#if (_MSC_VER >= 800)                                              //~v034I~
//*******************************************************          //~v034I~
//*uallocvcinit                                                    //~v034I~
//* debug sw init for visual c++                                   //~v034I~
//* parm  :none                                                    //~v034I~
//* return:none                                                    //~v034I~
//******************************************************           //~v034I~
void uallocvcinit(void)                                            //~v034I~
{                                                                  //~v034I~
        ULONG *mallocid;                                               //~v034I~
//***********************                                          //~v034I~
        Sinitsw=1;                      //protect second call                      //~v034I~
//  udos_version(&vno,&vno,&vno);	//3rd parm(dword info) is set last;//~v136R~
//  Sntsw=(vno>0);	//bit 0 on for win32s/win95 off for nt         //~v136R~
    Sntsw=udosiswinnt();                                           //~v136I~
  if (Sntsw)                                                       //~v133I~
    	Ssizepos=SIZEPOSNT;                                        //~v133I~
  else                                                             //~v133I~
  {                                                                //~v133I~
// #ifdef WXE                                                      //~v570R~
//        mallocid=malloc(1);                                      //~v570R~
// #else                                                           //~v570R~
 #ifdef ULIB64X                                                    //~v6hiI~
        mallocid=malloc(1);                                        //~v6hiI~
 #else                                                             //~v6hiI~
  #if (_MSC_VER >=1020)     //vc++ enterprize version              //~v570I~
#ifdef WIN10                                                       //~v6G5I~
        mallocid=HeapAlloc(getHandle(),0,1);                       //~v6G5I~
#else                                                              //~v6G5I~
        mallocid=HeapAlloc(_crtheap,0,1);                          //~v570I~
#endif                                                             //~v6G5I~
  #else                                                            //~v570I~
        mallocid=malloc(1);                                                        //~v034I~
  #endif                                                           //~v570I~
 #endif                                                            //~v6hiI~
// #endif                                                          //~v570R~
#ifdef ULIB64X                                                     //~v6hiI~
  #ifdef _DEBUG                                                    //~v6hiI~
    if (*(long *)((ULPTR)mallocid-DBGALLOCSIGNFLD)!=DEBUGID)   //not alloced//~v6hiR~//~v6hhI~
  #else                                                            //~v6hiI~
    if (0)                                                         //~v6hiI~//~v6hhM~
  #endif                                                           //~v6hiI~
#else                                                              //~v6hiI~
    if (*(mallocid-1)==DEBUGID)                                    //~v034I~
#endif                                                             //~v6hiI~
    {                                                              //~v034I~
        Sdebugsw=1;                                                //~v034I~
        Ssizepos=SIZEPOSD;                                         //~v034I~
        }                                                              //~v034I~
        else                                                           //~v034I~
    {                                                              //~v034I~
        Sdebugsw=0;                                                //~v034I~
        Ssizepos=SIZEPOSR;                                         //~v034I~
        }                                                              //~v034I~
  #if (_MSC_VER >=1020)     //vc++ enterprize version              //~v570I~
#ifdef WIN10                                                       //~v6G5I~
        HeapFree(getHandle(),0,mallocid);                          //~v6G5I~
#else                                                              //~v6G5I~
        HeapFree(_crtheap,0,mallocid);                             //~v570I~
#endif                                                             //~v6G5I~
  #else                                                            //~v570I~
        free(mallocid);                                                //~v034I~
  #endif                                                           //~v570I~
  }                                                                //~v133I~
    return;                                                        //~v034I~
}//uallocvcinit                                                    //~v034I~
#endif                                                             //~v034I~
//#ifdef OS2                                                       //~v106R~
#if defined(OS2) || defined(DPMI)                                  //~v106I~
//*******************************************************          //~v102I~
//*uallocmapset                                                    //~v102I~
//* set page allocation map to dump at abend                       //~v102I~
//* parm  :addr                                                    //~v102I~
//* return:none                                                    //~v102I~
//******************************************************           //~v102I~
void uallocmapset(char* Paddr,int Psize)                           //~v102I~
{                                                                  //~v102I~
        char *mapbyte;                                                 //~v102R~
        UINT  biton;                                                   //~v102I~
        int pagectr,spageno;                                           //~v102I~
//***********************                                          //~v102I~
    #ifdef DPMI                                                    //~v119R~
    if (Spagemap                                                   //~v119R~
    && ((UINT)Paddr<UALLOC_PAGEMAPRANGE_L               //256mb below      //~v119R~
       ||(UINT)Paddr>UALLOC_PAGEMAPRANGE_H))    //256mb under from top//~v119R~
    {                                                              //~v119R~
        if ((UINT)Paddr>UALLOC_PAGEMAPRANGE_H)    //256mb under from top//~v119R~
        {                                                          //~v119R~
                spageno=(int)(((UINT)(Paddr)-UALLOC_PAGEMAPRANGE_H)>>12);   //start page no//~v119R~
                pagectr=(int)(((UINT)(Paddr+Psize-1-UALLOC_PAGEMAPRANGE_H))>>12)-spageno+1;//bit ctr//~v119R~
                mapbyte=Spagemap+(spageno>>3)+UALLOC_PAGEMAPSZ_L;      //~v119R~
        }                                                          //~v119R~
        else                                                       //~v119R~
        {                                                          //~v119R~
                spageno=(int)(((UINT)(Paddr))>>12);   //start page no  //~v119R~
                pagectr=(int)(((UINT)(Paddr+Psize-1))>>12)-spageno+1;//bit ctr//~v119R~
                mapbyte=Spagemap+(spageno>>3);                         //~v119R~
        }                                                          //~v119R~
    #else                                                          //~v106I~
    if (Spagemap && ((UINT)Paddr<UALLOC_PAGEMAPRANGE))    //16mb below//~v102R~
    {                                                              //~v102I~
//  #ifdef DPMI                                                    //~v119R~
//      spageno=(int)(((UINT)(Paddr))>>16);   //start 64k segmentno//~v119R~
//      pagectr=(int)(((UINT)(Paddr+Psize-1))>>16)-spageno+1;//bit ctr//~v119R~
//  #else                                                          //~v119R~
        spageno=(int)(((UINT)(Paddr))>>12);   //start page no      //~v102R~
        pagectr=(int)(((UINT)(Paddr+Psize-1))>>12)-spageno+1;//bit ctr//~v102R~
        mapbyte=Spagemap+(spageno>>3);                             //~v106I~
    #endif                                                         //~v119R~
        biton=(UINT)(0x80>>(spageno & 0x07));    //dev by 8,start bit offset//~v102R~
//      mapbyte=Spagemap+(spageno>>3);                             //~v119R~
        for (;;)                                                   //~v102I~
        {                                                          //~v102I~
            *mapbyte=(char)(*mapbyte|(char)biton);                 //~v102R~
            if (!(--pagectr))                                      //~v102R~
                break;                                             //~v102I~
            if (!(biton>>=1))                                      //~v102R~
            {                                                      //~v102I~
                biton=0x80;                                        //~v102I~
                mapbyte++;                                         //~v102I~
            }                                                      //~v102I~
        }                                                          //~v102I~
    }                                                              //~v102I~
UTRACEP("addr=%08x,Psize=%08x",Paddr,Psize);                       //~v119I~
UTRACED("map",Spagemap,UALLOC_PAGEMAPSZ);                          //~v119I~
    return;                                                        //~v102I~
}//uallocmapset                                                    //~v102I~
#endif          //os2                                                  //~v102I~
                                                                   //~v102I~
#if !defined(DOS) || defined(DPMI)                                 //~v100I~
//*******************************************************          //~v099I~
//*ufreesizeerr                                                    //~v099I~
//* errexit when area destroy                                      //~v100R~
//* parm  :free addr                                               //~v099I~
//* return:none                                                    //~v099I~
//******************************************************           //~v099I~
void ufreesizeerr(void *Paddr)                                     //~v099I~
{                                                                  //~v099I~
//***********************                                          //~v099I~
//  uerrexit("ufree:%08lX is destroyed",                           //~v099I~//~v6hiR~
    uerrexit("ufree:%08lX is corrupted",                           //~v6hiI~
                 "ufree:%08lX が壊れています",                         //~v099I~
              Paddr);                                              //~v099I~
        return;                                                        //~v099I~
}//ufreesizeerr                                                    //~v099I~
//*******************************************************          //~v100I~
//*umallocsizeerr                                                  //~v100I~
//* uerrexit when req size  over 1mb                               //~v100I~
//* parm  :size                                                    //~v100I~
//* return:none                                                    //~v100I~
//******************************************************           //~v100I~
void umallocsizeerr(size_t Psize)                                  //~v100I~
{                                                                  //~v100I~
//***********************                                          //~v100I~
//  uerrexit("umalloc:%08X is over 1MB limit for a request",       //~v5dnR~
//               "umalloc:%08X は1回の制限長(1MB)超です",          //~v5dnR~
//            Psize);                                              //~v5dnR~
    uerrexit("umalloc:%ld is over limit(%ld) for a request",0,     //~v5dnR~
              Psize,MAX_MALLOC);                                   //~v5dnI~
        return;                                                        //~v100I~
}//umallocsizeerr                                                  //~v100I~
#endif                                                             //~v100I~
                                                                   //~v6F0I~
#ifdef W32                                                         //~v6F0I~
//******************************************************           //~v6F0I~
int ubacktrace(int Popt,int Pskipctr,int Pgetctr,void **Pout)      //~v6F0I~
{                                                                  //~v6F0I~
    int outctr,skipctr;                                            //~v6F0I~
//***********************                                          //~v6F0I~
	skipctr=Pskipctr+2;	//api and this func                        //~v6F0I~
    outctr=CaptureStackBackTrace(skipctr,Pgetctr,Pout,NULL/*hash*/);//~v6F0R~
    return outctr;                                                 //~v6F0I~
}//ubacktrace                                                      //~v6F0I~
#endif                                                             //~v6F0I~
