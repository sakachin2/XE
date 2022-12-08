//*CID://+v70pR~:                             update#=   49;       //~v70pR~
//*************************************************************
//*ualloc/ucalloc/ufree/umalloc16/ucalloc16/ufree16/uallocsz
//*************************************************************    //~v366I~
//v70p:200919 (ARM)sjis msg was converted by androidstudio         //~v70pI~
//v707:200616 ARM:MALLOC fmt is unknown                            //~v707I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6B1:160114 trace,mtrace file no share mode                      //~v6B1I~
//v6q9:131203 (BUG)freesizeerr() for large dir(10,000 entry) by udirlist malloc size is over 24bit//~v6q9I~
//v6h9:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(copile optio -Ox is required also)//~v6h9I~
//v6de:120218 confirm MALLOCCHK depends TRACEOPT                   //~v6deI~
//v690:100701 m62(LP64:: int:32, long,void*:64) support (__LP64_)  //~v690I~
//v5mr:080427*(BUG)ufree allocation chk should ignore NON_MAIN_ARENA bit of size field//~v5miI~
//v5mi:080312 (LNX)no alloc bit chk when -DMALLOCHK not defined for other distribution//~v5miI~
//v5mg:080307 (DEBUG)ufree fail by "not alloc area";set debug trace//~v5mgI~
//v568:020706 new func:allocchk;msg and abend                      //~v568I~
//v567:020705 (AIX)repl temp logic of free size;it is  on the word before alloc addr//~v567I~
//v40k:001121 AIX support:(BUG)abend:ualloc size require for bufflen calc//~v40kI~
//v40i:001116 AIX support:drop size chk/alloc chk temporary        //~v40iI~
//v404:001109 AIX support:errno.h required                         //~v404I~
//v403:001109 AIX support:cast chk                                 //~v403I~
//v389:001009 LINUX support(BUG:alloc size may grater than MINSIZE //~v389I~
//            when split remains smaller than MINSIZE)             //~v389I~
//*************************************************************    //~v389I~
//*alignment         :8                                            //~v366I~
//*minimum alloc size:16                                           //~v366I~
//*overhead          :4 (size including overhead and status(lower 2 bit))//~v366I~
///*                                                               //~v366I~
                                                                   //~v366I~
//   malloc_chunk details:                                         //~v366I~
                                                                   //~v366I~
//    (The following includes lightly edited explanations by Colin Plumb.)//~v366I~
                                                                   //~v366I~
//    Chunks of memory are maintained using a `boundary tag' method as//~v366I~
//    described in e.g., Knuth or Standish.  (See the paper by Paul//~v366I~
//    Wilson ftp://ftp.cs.utexas.edu/pub/garbage/allocsrv.ps for a //~v366I~
//    survey of such techniques.)  Sizes of free chunks are stored both//~v366I~
//    in the front of each chunk and at the end.  This makes       //~v366I~
//    consolidating fragmented chunks into bigger chunks very fast.  The//~v366I~
//    size fields also hold bits representing whether chunks are free or//~v366I~
//    in use.                                                      //~v366I~
                                                                   //~v366I~
//    An allocated chunk looks like this:                          //~v366I~
                                                                   //~v366I~
                                                                   //~v366I~
//    chunk-> +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
//            |             Size of previous chunk, if allocated            | |//~v366I~
//            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
//            |             Size of chunk, in bytes                         |P|//~v366I~
//      mem-> +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
//            |             User data starts here...                          .//~v366I~
//            .                                                               .//~v366I~
//            .             (malloc_usable_space() bytes)                     .//~v366I~
//            .                                                               |//~v366I~
//nextchunk-> +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
//            |             Size of chunk                                     |//~v366I~
//            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
                                                                   //~v366I~
                                                                   //~v366I~
//    Where "chunk" is the front of the chunk for the purpose of most of//~v366I~
//    the malloc code, but "mem" is the pointer that is returned to the//~v366I~
//    user.  "Nextchunk" is the beginning of the next contiguous chunk.//~v366I~
                                                                   //~v366I~
//    Chunks always begin on even word boundaries, so the mem portion//~v366I~
//    (which is returned to the user) is also on an even word boundary, and//~v366I~
//    thus double-word aligned.                                    //~v366I~
                                                                   //~v366I~
//    Free chunks are stored in circular doubly-linked lists, and look like this://~v366I~
                                                                   //~v366I~
//    chunk-> +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
//            |             Size of previous chunk                            |//~v366I~
//            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
//    `head:' |             Size of chunk, in bytes                         |P|//~v366I~
//      mem-> +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
//            |             Forward pointer to next chunk in list             |//~v366I~
//            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
//            |             Back pointer to previous chunk in list            |//~v366I~
//            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
//            |             Unused space (may be 0 bytes long)                .//~v366I~
//            .                                                               .//~v366I~
//            .                                                               |//~v366I~
//nextchunk-> +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
//    `foot:' |             Size of chunk, in bytes                           |//~v366I~
//            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//~v366I~
                                                                   //~v366I~
//    The P (PREV_INUSE) bit, stored in the unused low-order bit of the//~v366I~
//    chunk size (which is always a multiple of two words), is an in-use//~v366I~
//    bit for the *previous* chunk.  If that bit is *clear*, then the//~v366I~
//    word before the current chunk size contains the previous chunk//~v366I~
//    size, and can be used to find the front of the previous chunk.//~v366I~
//    (The very first chunk allocated always has this bit set,     //~v366I~
//    preventing access to non-existent (or non-owned) memory.)    //~v366I~
                                                                   //~v366I~
//    Note that the `foot' of the current chunk is actually represented//~v366I~
//    as the prev_size of the NEXT chunk. (This makes it easier to //~v366I~
//    deal with alignments etc).                                   //~v366I~
                                                                   //~v366I~
//    The two exceptions to all this are                           //~v366I~
                                                                   //~v366I~
//     1. The special chunk `top', which doesn't bother using the  //~v366I~
//        trailing size field since there is no                    //~v366I~
//        next contiguous chunk that would have to index off it. (After//~v366I~
//        initialization, `top' is forced to always exist.  If it would//~v366I~
//        become less than MINSIZE bytes long, it is replenished via//~v366I~
//        malloc_extend_top.)                                      //~v366I~
                                                                   //~v366I~
//     2. Chunks allocated via mmap, which have the second-lowest-order//~v366I~
//        bit (IS_MMAPPED) set in their size fields.  Because they are//~v366I~
//        never merged or traversed from any other chunk, they have no//~v366I~
//        foot size or inuse information.                          //~v366I~
                                                                   //~v366I~
//    Available chunks are kept in any of several places (all declared below)://~v366I~
                                                                   //~v366I~
//    * `av': An array of chunks serving as bin headers for consolidated//~v366I~
//       chunks. Each bin is doubly linked.  The bins are approximately//~v366I~
//       proportionally (log) spaced.  There are a lot of these bins//~v366I~
//       (128). This may look excessive, but works very well in    //~v366I~
//       practice.  All procedures maintain the invariant that no  //~v366I~
//       consolidated chunk physically borders another one. Chunks in//~v366I~
//       bins are kept in size order, with ties going to the       //~v366I~
//       approximately least recently used chunk.                  //~v366I~
                                                                   //~v366I~
//       The chunks in each bin are maintained in decreasing sorted order by//~v366I~
//       size.  This is irrelevant for the small bins, which all contain//~v366I~
//       the same-sized chunks, but facilitates best-fit allocation for//~v366I~
//       larger chunks. (These lists are just sequential. Keeping them in//~v366I~
//       order almost never requires enough traversal to warrant using//~v366I~
//       fancier ordered data structures.)  Chunks of the same size are//~v366I~
//       linked with the most recently freed at the front, and allocations//~v366I~
//       are taken from the back.  This results in LRU or FIFO allocation//~v366I~
//       order, which tends to give each chunk an equal opportunity to be//~v366I~
//       consolidated with adjacent freed chunks, resulting in larger free//~v366I~
//       chunks and less fragmentation.                            //~v366I~
                                                                   //~v366I~
//    * `top': The top-most available chunk (i.e., the one bordering the//~v366I~
//       end of available memory) is treated specially. It is never//~v366I~
//       included in any bin, is used only if no other chunk is    //~v366I~
//       available, and is released back to the system if it is very//~v366I~
//       large (see M_TRIM_THRESHOLD).                             //~v366I~
                                                                   //~v366I~
//    * `last_remainder': A bin holding only the remainder of the  //~v366I~
//       most recently split (non-top) chunk. This bin is checked  //~v366I~
//       before other non-fitting chunks, so as to provide better  //~v366I~
//       locality for runs of sequentially allocated chunks.       //~v366I~
                                                                   //~v366I~
//    *  Implicitly, through the host system's memory mapping tables.//~v366I~
//       If supported, requests greater than a threshold are usually//~v366I~
//       serviced via calls to mmap, and then later released via munmap.//~v366I~
                                                                   //~v366I~
//*/                                                               //~v366I~
//*************************************************************
//v366:000927 LINUX support(display operation on permission errmsg)//~v366I~
//v360:000927 LINUX support(malloc size)                           //~v360I~
//v352:000926 LINUX support(permission err msg)                    //~v352I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#ifdef LNX                                                         //~v404I~
#else                                                              //~v404R~
	#include <errno.h>                                             //~v404I~
#endif                                                             //~v404I~
//*******************************************************
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <utrace.h>
#include <udos.h>
#include <ufemsg.h>                                                //~v352I~
#include <ufile.h>                                                 //~v6B1I~
#include <ufile2.h>                                                //~v6B1I~
#define MAX_MALLOC 0x40000000     //1GB                            //~v6BxI~
//*******************************************************
#define         UALLOCTRCFILE "ualloc.trc"
#ifdef MALLOCCHK                                                   //~v6deI~
	#if defined(NOTRACE) || ! defined(TRACE)                       //~v6deI~
		#undef MALLOCCHK                                           //~v6deI~
	#endif                                                         //~v6deI~
#else                                                              //~v6deI~
	#if defined(TRACE)                                             //~v6deI~
		#define MALLOCCHK                                          //~v6deI~
	#endif                                                         //~v6deI~
#endif                                                             //~v6deI~
//*******************************************************
#ifdef ULIB64                                                      //~v690I~
	#define SIZEPOS  sizeof(long) //over head size                 //~v690I~
#else                                                              //~v690I~
#define SIZEPOS      4          //over head size
#endif                                                             //~v690I~
#define PREV_INUSE  0x01		//in size word,prev chunc is in use//~v366I~
#define IS_MMAPPED     0x02 	//mmap memory                      //~v5miI~
#define NON_MAIN_ARENA 0x04 	//not main areana                  //~v5miI~
#define SIZE_MASK      0x07		//size is DWORD boundary,3 bit ignored//~v5miI~
//*******************************************************
void ufreesizeerr(void *Paddr);
void umallocsizeerr(size_t Psize);
void uallocmapset(char* Paddr,int Psize);
//*******************************************************
        long Gualloc_amount;
        long Gualloc16_amount;
//*******************************************************
static int  Sallocopt;
static int  Sallocret;
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
static long Smaxlenwk16;
static UALLOCD Sallocdata;
static FILE* Shfile;
static char *Spagemap;          //os2 only
static int Slockhandle;                                            //~v6B1R~
//*******************************************************
static unsigned char Smatrcfile[_MAX_PATH]=UALLOCTRCFILE;
//*******************************************************
//*ualloc_init
//* parm1:ualloc option
//*        0:reset debug mode(close opened trace file)
//*        1:alloc size debug
//*        2:wrtite to file
//*        4:return even if alloc failed(not needed other flag)
//*        8:exit        if alloc failed(not needed other flag)
//* parm2:trace file name
//******************************************************
void ualloc_init(int Popt,unsigned char *Pfilename)
{
    int swnoshare;                                                 //~v6B1I~
//*****************************                                    //~v6B1I~
        Sallocret=(Popt & (UALLOC_ERRRETURN | UALLOC_ERREXIT));
    swnoshare=Popt & UALLOC_NOSHARE;                               //~v6B1R~
    Popt=(Popt & (UALLOC_DEBUG|UALLOC_TRACE));
    if (Sallocret && !Popt)  //return req only
    {
                Sallocret=((Sallocret & UALLOC_ERRRETURN)
                   && !(Sallocret & UALLOC_ERREXIT));
        return;
        }
        if (!(Sallocopt=Popt))
                if (Shfile)
        {
                        fclose(Shfile);
            Shfile=0;
        }
        if (Popt & UALLOC_TRACE)
        {
                if (Pfilename)
//              strcpy(Smatrcfile,Pfilename);
                strncpy((char*)Smatrcfile,(void *)Pfilename,_MAX_PATH-1);//~v403R~
                if (!Shfile)    //not yet opened
                {                                                  //~v352I~
              if (swnoshare)                                       //~v6B1R~
                Shfile=ufileopenexclusivewrite(0,Smatrcfile,&Slockhandle);//~v6B1I~
              else                                                 //~v6B1I~
                Shfile=fopen((char *)Smatrcfile,"w");              //~v403R~
                if (!Shfile)                                       //~v352I~
                  {                                                //~v568I~
      				if (errno==EACCES)                             //~v352R~
        				ufilenopermission((void*)"fopen",Smatrcfile,errno);//~v403R~
      				else                                           //~v352I~
        				ufileapierr((void*)"fopen",Smatrcfile,errno);//~v403R~
                  }                                                //~v568I~
                }                                                  //~v352I~
        }
    Spagemap=calloc(1,UALLOC_PAGEMAPSZ+16);//page alloc tbl 1bit per page
    strncpy(Spagemap,"PAGEMAP",16);
    Spagemap+=16;
    uallocmapset(Spagemap,UALLOC_PAGEMAPSZ);
    return;
}//ualloc_init                                                     //~v352R~
//*******************************************************
//*ugetallocdata
//* parm  :none
//* return:ptr to alloc data
//******************************************************
UALLOCD *ugetallocdata(void)
{
        Sallocdata.allocctr  =Sallocctr;
        Sallocdata.alloclen  =Salloclen;
        Sallocdata.netreqlen  =(long)Snetreqlen;
        Sallocdata.freectr   =Sfreectr;
        Sallocdata.freelen   =Sfreelen;
        Sallocdata.maxlen    =Gualloc_amount;
        Sallocdata.alloc16ctr=Salloc16ctr;
        Sallocdata.alloc16len=Salloc16len;
        Sallocdata.netreq16len=(long)Snetreq16len;
        Sallocdata.free16ctr =Sfree16ctr;
        Sallocdata.free16len =Sfree16len;
        Sallocdata.max16len  =Gualloc16_amount;
        Sallocdata.pagemap   =Spagemap;
        Sallocdata.pagemapsz =UALLOC_PAGEMAPSZ;//page alloc tbl 1bit per page
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
    long reslen=0,resctr=0;                                        //~v6h9R~
    char *uatrcopt="Inactive";                                     //~v568I~
//***************************                                      //~v568I~
    if (Sallocopt)                                                 //~v568I~
    	uatrcopt="Active";                                         //~v568I~
    puad=ugetallocdata();                                          //~v568I~
    if (Popt & UAC_MSG)                                            //~v568I~
        printf("malloc statistic data (trace is %s)\n"             //~v568I~
"           alloc   req: %8ld times  total %8ld byte(net %8ld)\n"  //~v568I~
"           free    req: %8ld times  total %8ld byte\n"            //~v568I~
"           %8ld times,%8ld byte free more required\n"             //~v568I~
"           allocated maximum is %8ld\n",                          //~v568I~
                uatrcopt,                                          //~v568I~
                puad->allocctr,                                    //~v568I~
                puad->alloclen,                                    //~v568I~
                puad->netreqlen,                                   //~v568I~
                puad->freectr,                                     //~v568I~
                puad->freelen,                                     //~v568I~
    (resctr=puad->allocctr+puad->alloc16ctr-puad->freectr-puad->free16ctr),//~v568I~
    (reslen=puad->alloclen+puad->alloc16len-puad->freelen-puad->free16len),//~v568I~
                puad->maxlen                                       //~v568I~
                );                                                 //~v568I~
    rc=(resctr || reslen);                                         //~v568I~
    if (Popt & UAC_EXIT)                                           //~v568I~
        if (rc)                                                    //~v568I~
        {                                                          //~v568I~
            if (Shfile)                                            //~v568I~
            {                                                      //~v568I~
            	fclose(Shfile);                                    //~v568I~
                Shfile=0;                                          //~v568I~
            }                                                      //~v568I~
            uerrexit("==========MORE %ld byete(%ld times) free required ===\n",0,//~v568I~
                        reslen,resctr);                            //~v568I~
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
//****************************
    if (!Psize)
                uerrexit("umalloc:request length is 0",
//                               "umalloc:ÔøΩvÔøΩÔøΩÔøΩÔøΩÔøΩÔøΩ 0");//~v70pR~
                                 "umalloc:óvãÅí∑Ç™ 0");            //~v70pI~
    pvoid=malloc(Psize);
    if (!pvoid)
    {
        ubell();
                if (Sallocret)
        {
                uerrmsg("!! storage shortage(reqsize=%d,current total=%ld) !!",
//                      "!! ÔøΩLÔøΩÔøΩÔøΩÔøΩsÔøΩÔøΩ(ÔøΩvÔøΩÔøΩÔøΩÔøΩ=%u,ÔøΩÔøΩÔøΩËìñÔøΩœÇ›çÔøΩÔøΩvÔøΩÔøΩ=%ld) !!",//~v70pR~
                        "!! ãLâØàÊïsë´(óvãÅí∑=%u,äÑÇËìñçœÇ›çáåví∑=%ld) !!",//~v70pI~
                        Psize,Salloclen-Sfreelen+Salloc16len-Sfree16len);
            return 0;

        }
                printf("\n!! storage shortage,malloc failed(reqsize=%u,current total=%ld) !!\n",
                                (unsigned)Psize,Gualloc_amount+Gualloc16_amount);
                exit(UALLOC_FAILED);
    }
        Sallocctr++;
//      UTRACED("uallocl.umalloc padd-64",pvoid-64,64+Psize);      //~v6BxR~//~v707R~
//      Salloclen+=(Ssizewk=(long)(ULONG)(UINT)uallocsz(Psize));   //~v389R~
        Salloclen+=(Ssizewk=(long)(ULONG)(UINT)ufreesz(pvoid));    //~v389I~
//      uallocmapset((char*)pvoid-SIZEPOS,Ssizewk);                //~v6B1R~
        uallocmapset((char*)pvoid-SIZEPOS,(int)Ssizewk);           //~v6B1I~
        Snetreqlen+=Psize;      //reqlen
        Smaxlenwk=Salloclen-Sfreelen;
        if (Gualloc_amount<Smaxlenwk)
                Gualloc_amount=Smaxlenwk;
        if (Sallocopt)
        {
                if (Shfile)
                        fprintf(Shfile,"malloc  :addr=%08lX,len=%08lX,cur-tot=%08lX\n",
                                (unsigned long)pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16);
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
    size_t total;
//****************************
    if (!(total=Psize*Pno))
                uerrexit("ucalloc:request length is 0",
//                               "ucalloc:ÔøΩvÔøΩÔøΩÔøΩÔøΩÔøΩÔøΩ 0");//~v70pR~
                                 "ucalloc:óvãÅí∑Ç™ 0");            //~v70pI~
    pvoid=calloc(Pno,Psize);
    if (!pvoid)
    {
        ubell();
                if (Sallocret)
        {
                uerrmsg("!! storage shortage(reqsize=%u,current total=%ld) !!",
//                      "!! ÔøΩLÔøΩÔøΩÔøΩÔøΩsÔøΩÔøΩ(ÔøΩvÔøΩÔøΩÔøΩÔøΩ=%d,ÔøΩÔøΩÔøΩËìñÔøΩœÇ›çÔøΩÔøΩvÔøΩÔøΩ=%ld) !!",//~v70pR~
                        "!! ãLâØàÊïsë´(óvãÅí∑=%d,äÑÇËìñçœÇ›çáåví∑=%ld) !!",//~v70pI~
//                              Pno*Psize,Gualloc_amount+Gualloc16_amount);
                        Pno*Psize,Salloclen-Sfreelen+Salloc16len-Sfree16len);
            return 0;

        }
                printf("\n!! storage shortage,calloc failed(req no=%u,size=%u,current amount=%ld)!!\n",
                                (unsigned)Pno,(unsigned)Psize,Gualloc_amount+Gualloc16_amount);
                exit(UALLOC_FAILED);
        }
        Sallocctr++;
//      Salloclen+=(Ssizewk=(long)(ULONG)(UINT)uallocsz(Pno*Psize));//~v389R~
        Salloclen+=(Ssizewk=(long)(ULONG)(UINT)ufreesz(pvoid));    //~v389I~
//      uallocmapset((char*)pvoid-SIZEPOS,Ssizewk);                //~v6B1R~
        uallocmapset((char*)pvoid-SIZEPOS,(int)Ssizewk);           //~v6B1I~
        Snetreqlen+=Pno*Psize;
        Smaxlenwk=Salloclen-Sfreelen;
        if (Gualloc_amount<Smaxlenwk)
                Gualloc_amount=Smaxlenwk;
        if (Sallocopt)
        {
                if (Shfile)
                        fprintf(Shfile,"calloc  :addr=%08lX,len=%08lX,cur-tot=%08lX\n",
                                (unsigned long)pvoid,Ssizewk,Smaxlenwk+Smaxlenwk16);
        }
        return pvoid;
}//ucalloc

//*******************************************************
//*ufree
//* parm chk and free
//******************************************************
#ifdef ARM                                                         //~v707I~
void ufree(void *Paddr)                                            //~v707I~
{                                                                  //~v707I~
static int Sfreeerr;                                               //~v707I~
//****************************                                     //~v707I~
    if (!Paddr)                                                    //~v707I~
                uerrexit("ufree:Null addr parm",                   //~v707I~
//                               "ufree:NULL ÔøΩAÔøΩhÔøΩÔøΩÔøΩXÔøΩpÔøΩÔøΩÔøΩÔøΩÔøΩ[ÔøΩ^");//~v707I~//~v70pR~
                                 "ufree:NULL ÉAÉhÉåÉXÉpÉâÉÅÅ[É^"); //~v70pI~
    if (	(                                                      //~v707I~
				(ULONG)Paddr & 0x07	//boundary err                 //~v707I~
         	)                                                      //~v707I~
	   )                                                           //~v707I~
                if (!Sfreeerr)                                     //~v707I~
                {                                                  //~v707I~
                        Sfreeerr=1;                                //~v707I~
                        uerrexit("ufree:%08lX is not malloc area",0,//~v707I~
                                          Paddr);                  //~v707I~
                }                                                  //~v707I~
        Sfreectr++;                                                //~v707I~
        Sfreelen+=(Ssizewk=(long)(ULONG)(UINT)ufreesz(Paddr));     //~v707I~
        if (Sallocopt)                                             //~v707I~
        {                                                          //~v707I~
                if (Shfile)                                        //~v707I~
                {                                                  //~v707I~
                                Smaxlenwk=Salloclen-Sfreelen;      //~v707I~
                                fprintf(Shfile,"free    :addr=%08lX,len=%08lX,cur-tot=%08lX\n",//~v707I~
                                               (unsigned long)Paddr,Ssizewk,Smaxlenwk+Smaxlenwk16);//~v707I~
                }                                                  //~v707I~
        }                                                          //~v707I~
        free(Paddr);                                               //~v707I~
        return;                                                    //~v707I~
}//ufree                                                           //~v707I~
#else                                                              //~v707I~
void ufree(void *Paddr)
{
static int Sfreeerr;
	ULONG *pnext,*pcurr;                                           //~v366I~
	ULONG nextv1=0,nextv2,curv1,curv2;                             //~v6h9R~
//****************************
    if (!Paddr)
                uerrexit("ufree:Null addr parm",
//                               "ufree:NULL ÔøΩAÔøΩhÔøΩÔøΩÔøΩXÔøΩpÔøΩÔøΩÔøΩÔøΩÔøΩ[ÔøΩ^");//~v70pR~
                                 "ufree:NULL ÉAÉhÉåÉXÉpÉâÉÅÅ[É^"); //~v70pI~
#ifdef LNX                                                         //~v40iI~
//  UTRACED("uallocl.ufree   padd-64",Paddr-64,96);                //~v6BxR~//~v707R~
    pcurr=(ULONG*)(void*)((char*)Paddr-SIZEPOS);                   //~v366R~
//  pnext=(ULONG*)(void*)((ULONG)pcurr+(*pcurr & ~PREV_INUSE));    //~v5miR~
//  pnext=(ULONG*)(void*)((ULONG)pcurr+(*pcurr & ~SIZE_MASK));     //~v6B1R~
    pnext=(ULONG*)(void*)((ULONG)pcurr+(*pcurr & ~(ULONG)SIZE_MASK));//~v6B1I~
	if (((ULONG)pcurr>>12)==((ULONG)pnext>>12))//chk same page only//~v5mgI~
    	nextv1=*pnext;                                             //~v5mgR~
// 	UTRACEP("%s:uallocl.ufree addr=%p,pcurr=%p,pnext=%p\n",UTT,Paddr,pcurr,pnext);//~v6BxI~//~v707R~
    curv1=*pcurr;                                                  //~v5mgI~
    if (	(                                                      //~v366R~
				(ULONG)Paddr & 0x07	//boundary err                 //~v366R~
         	)                                                      //~v366I~
#ifdef MALLOCCHK    //not release version,no chk alloc bit for release version//~v5miI~
         	||                                                     //~v366R~
         	(                                                      //~v366I~
				(                                                  //~v366I~
					((ULONG)pcurr>>12)==((ULONG)pnext>>12)//chk same page only//~v366I~
                )                                                  //~v366I~
		     	&&                                                 //~v366R~
                (                                                  //~v366I~
					!(*pnext & PREV_INUSE)	//next chunk flag      //~v366I~
                )                                                  //~v366I~
         	)                                                      //~v366R~
#endif                                                             //~v5miI~
	   )                                                           //~v366I~
                if (!Sfreeerr)
                {
				    	nextv2=*pnext;                             //~v5mgI~
					    curv2=*pcurr;                              //~v5mgI~
                        Sfreeerr=1;
                        uerrexit("ufree:%08lX is not malloc area(next=%p,nextv1=%08lx,nextv2=%08lx,curv1=%08lx,curv2=%08lx)",//~v5mgR~
//                                       "ufree:%08lX ÔøΩÔøΩ malloc ÔøΩÔøΩÔøΩÔøΩƒÇÔøΩÔøΩ‹ÇÔøΩÔøΩÔøΩ(next=%p,nextv1=%08lx,nextv2=%08lx,curv1=%08lx,curv2=%08lx)",//~v5mgR~//~v70pR~
                                         "ufree:%08lX ÇÕ malloc Ç≥ÇÍÇƒÇ¢Ç‹ÇπÇÒ(next=%p,nextv1=%08lx,nextv2=%08lx,curv1=%08lx,curv2=%08lx)",//~v70pI~
                                          Paddr,pnext,nextv1,nextv2,curv1,curv2);//~v5mgR~
                }
#else   //!LNX                                                     //~v40iI~
#endif  //!LNX                                                     //~v40iI~
        Sfreectr++;
        Sfreelen+=(Ssizewk=(long)(ULONG)(UINT)ufreesz(Paddr));     //~v360R~
        if (Sallocopt)
        {
                if (Shfile)
                {                                                  //~v568I~
                        if (Ssizewk)
                        {
                                Smaxlenwk=Salloclen-Sfreelen;
                                fprintf(Shfile,"free    :addr=%08lX,len=%08lX,cur-tot=%08lX\n",
                                               (unsigned long)Paddr,Ssizewk,Smaxlenwk+Smaxlenwk16);
                        }
                        else
                                uerrexit("ufree:%08lX is length 0 at free",
//                                               "ufree:%08lX ÔøΩÔøΩ ÔøΩtÔøΩÔøΩÔøΩ[ÔøΩÔøΩÔøΩÃíÔøΩÔøΩÔøΩÔøΩÔøΩ 0",//~v70pR~
                                                 "ufree:%08lX ÇÕ ÉtÉäÅ[éûÇÃí∑Ç≥Ç™ 0",//~v70pI~
                                                  Paddr);
                }                                                  //~v568I~
        }
        free(Paddr);
// 		UTRACED("uallocl.ufree  after free padd-64",Paddr-64,96);  //~v6BxR~//~v707R~
        return;
}//ufree
#endif	//!ARM                                                     //~v707I~

//*******************************************************
//*uallocsz
//* get shift up size of malloc
//*    size by power of 2 containing 16 malloc byte hdr size
//* parm1 :request len
//* return:shift up len(overhead len is not contained)
//******************************************************
int uallocsz(size_t Plen)
{
#ifdef LNX                                                         //~v40iI~
    int len;                                                       //~v360I~
//************************************                             //~v360I~
//  if ((len=Plen+SIZEPOS)<16)                                     //~v6B1R~
//  if ((len=(int)Plen+SIZEPOS)<16)                                //~v6B1I~//~v6BxR~
    if ((len=(int)Plen+(int)SIZEPOS)<16)                           //~v6BxI~
        return 16;                                                 //~v360I~
    return ((len+7)>>3)<<3;                                        //~v366R~
#else                                                              //~v40iI~
//  return 4;                                                      //~v40kR~
    return Plen;                                                   //~v40kI~
#endif                                                             //~v40iI~
}//uallocsz

//*******************************************************
//*ufreesz
//* get buff size from malloc hdr
//* parm1 :malloc area
//* return:buffsize
//******************************************************
int ufreesz(void *Ppvoid)
{
#ifdef ARM                                                         //~v707I~
	return 0;                                                      //~v707I~
#else                                                              //~v707I~
#ifdef LNX                                                         //~v40iI~
    int freesz;
//***********************
//  freesz=*(unsigned int *)(void*)((unsigned char*)Ppvoid-SIZEPOS);//~v6B1R~
    freesz=(int)(*(unsigned int *)(void*)((unsigned char*)Ppvoid-SIZEPOS));//~v6B1I~
//  freesz&=0xfffffffc;		//drop 0x03(mmap and prev-inuse)       //~v6B1R~
    freesz=(int)((UINT)freesz & 0xfffffffc);		//drop 0x03(mmap and prev-inuse)//~v6B1I~
#ifndef ULIB64                                                     //~v6q9R~
//  if (freesz>>24)                                                //~v6BxR~
    if (freesz>MAX_MALLOC)                                         //~v6BxI~
        ufreesizeerr(Ppvoid);
#endif                                                             //~v6q9R~
//  UTRACEP("%s:uallocl.ufreesz=%d\n",UTT,freesz);                 //~v6BxR~//+v70pR~
    return freesz;
#else                                                              //~v40iI~
    int freesz;                                                    //~v567R~
//***********************                                          //~v567R~
//  return 4;                                                      //~v567R~
    freesz=*(unsigned int *)(void*)((unsigned char*)Ppvoid-SIZEPOS);//~v567R~
    return freesz;                                                 //~v567R~
#endif                                                             //~v40iI~
#endif	//!ARM                                                     //~v707I~
}//ufreesz

//*******************************************************
//*uallocmapset
//* set page allocation map to dump at abend
//* parm  :addr
//* return:none
//******************************************************
void uallocmapset(char* Paddr,int Psize)
{
        char *mapbyte;
        UINT  biton;
        int pagectr,spageno;
//***********************
//  if (Spagemap && ((UINT)Paddr<UALLOC_PAGEMAPRANGE))    //16mb below//~v690R~
    if (Spagemap && ((ULONG)Paddr<UALLOC_PAGEMAPRANGE))    //16mb below//~v690I~
    {
//      spageno=(int)(((UINT)(Paddr))>>12);   //start page no      //~v690R~
        spageno=(int)(((ULONG)(Paddr))>>12);   //start page no     //~v690I~
//      pagectr=(int)(((UINT)(Paddr+Psize-1))>>12)-spageno+1;//bit ctr//~v690R~
        pagectr=(int)(((ULONG)(Paddr+Psize-1))>>12)-spageno+1;//bit ctr//~v690I~
        mapbyte=Spagemap+(spageno>>3);
        biton=(UINT)(0x80>>(spageno & 0x07));    //dev by 8,start bit offset
        for (;;)
        {
            *mapbyte=(char)(*mapbyte|(char)biton);
            if (!(--pagectr))
                break;
            if (!(biton>>=1))
            {
                biton=0x80;
                mapbyte++;
            }
        }
    }
//UTRACEP("addr=%08x,Psize=%08x",Paddr,Psize);
//UTRACED("map",Spagemap,UALLOC_PAGEMAPSZ);
    return;
}//uallocmapset

//*******************************************************
//*ufreesizeerr
//* errexit when area destroy
//* parm  :free addr
//* return:none
//******************************************************
void ufreesizeerr(void *Paddr)
{
//***********************
    uerrexit("ufree:%08lX is destroyed",
//               "ufree:%08lX ÔøΩÔøΩÔøΩÔøΩÔøΩƒÇÔøΩÔøΩ‹ÇÔøΩ",       //~v70pR~
                 "ufree:%08lX Ç™âÛÇÍÇƒÇ¢Ç‹Ç∑",                     //~v70pI~
              Paddr);
        return;
}//ufreesizeerr
//*******************************************************
//*umallocsizeerr
//* uerrexit when req size  over 1mb
//* parm  :size
//* return:none
//******************************************************
void umallocsizeerr(size_t Psize)
{
//***********************
    uerrexit("umalloc:%08X is over 1MB limit for a request",
//               "umalloc:%08X ÔøΩÔøΩ1ÔøΩÔøΩÃêÔøΩÔøΩÔøΩÔøΩÔøΩ(1MB)ÔøΩÔøΩÔøΩ≈ÇÔøΩ",//~v70pR~
                 "umalloc:%08X ÇÕ1âÒÇÃêßå¿í∑(1MB)í¥Ç≈Ç∑",          //~v70pI~
              Psize);
        return;
}//umallocsizeerr
