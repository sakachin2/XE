//CID://+v6F0R~:                      update#=4                    //+v6F0R~
//*******************************************************
//*ualloc.h
//*******************************************************
//v6F0:160830 W64 dose not set stack chain by EBP(/Oy- is for x86 only). try CaptureStackBackTrace api.//+v6F0I~
//v6B1:160114 trace,mtrace file no share mode                      //~v6B1I~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v62X:091107_compchkm                                             //~v62XI~
//v62K:091009_chane UALLOC_FAILED 0x1001->0x1100 to avoid bit chk of rc//~v62KI~
//v5mc:080223 (BUG)not used but macro definition err of UALLOCC16  //~v5mcI~
//v60r:071026 (UTF)utf8mode for each file                          //~v60rI~
//v593:030930 (WIN,WXE)add return addr to malloc trace for debug   //~v593I~
//v568:020706 new func:allocchk;msg and abend                      //~v568I~
//v327 000820:LINUX support                                        //~v327I~
//v119:971115 (BUG:GCC)64k allocmem by 501h(in sblk or stub) dose not//~v106I~
//                     return 64k boundary addr(selector base may be not//~v106I~
//                     64k boundary).so use 4k page logic same as os2.//~v106I~
//                     and addr may from top(ff______).            //~v106I~
//v106:971027 (BUG:GCC)sbrk dosenot return continuous memory under win95.//~v106I~
//            Block addr is page boundary -4 at first by the logic in malloc.//~v106I~
//            (req to __sblk to set __what_size_dpmi_think_we_are to page boundary.)//~v106I~
//            Blk in another 64k may be on page boundary if __what_size_app_think_it_is//~v106I~
//            reached to it.                                       //~v106I~
//            Abandon -4 setup logicin malloc.It may return always page boundary.//~v106I~
//            And,dump page should also collect by alloc addr like as os/2.//~v106I~
//v102:971010 os2 new malloc dump logic(save page at malloc)       //~v102I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//*******************************************************          //~v022I~
#ifdef DPMI                                                        //~v106I~
//  #define UALLOC_PAGEMAPRANGE    0xffffffff  //4GM full          //~v119R~
//  #define UALLOC_PAGEMAPSZ       (0xffff>>3)//1bit 64k           //~v119R~
    #define UALLOC_PAGEMAPRANGE_L  0x10000000   //dump up to +256 mb//~v119R~
    #define UALLOC_PAGEMAPRANGE_H  0xf0000000   //dump up to -256 mb//~v119R~
    #define UALLOC_PAGEMAPSZ_H     (-UALLOC_PAGEMAPRANGE_H>>(12+3))//~v119R~
    #define UALLOC_PAGEMAPSZ_L     ( UALLOC_PAGEMAPRANGE_L>>(12+3))//~v119I~
    #define UALLOC_PAGEMAPSZ       (UALLOC_PAGEMAPSZ_L+UALLOC_PAGEMAPSZ_H)//~v119I~
#else                                                              //~v106I~
#define UALLOC_PAGEMAPRANGE    0x10000000	//dump up to 256 mb    //~v102I~
#define UALLOC_PAGEMAPSZ (UALLOC_PAGEMAPRANGE>>(12+3))//page alloc tbl 1bit per page//~v102I~
#endif                                                             //~v106I~
                                                                //~5930I~
//#define UALLOC_FAILED    0x1001                                 //~5930R~//~v62KR~
//#define UALLOC_FAILED    0x1100                                    //~v62KI~//~v62XR~
#define UALLOC_FAILED    0x1001                                    //~v62XI~
#define UALLOCCHK(addr,rc)  if (!(addr)) return rc              //~5930R~
#ifdef UTF8UCS2                                                    //~v640I~
#define UALLOCCHKRC(rc)  if ((rc)==UALLOC_FAILED) return UALLOC_FAILED//~v640I~
#endif                                                             //~v640I~
                                                                //~5930I~
#define UALLOC(type,len) U ##type## ALLOC(len)                  //~5930I~
#define UmALLOC(size)     umalloc((size))                       //~5930I~
#define UcALLOC(size)     ucalloc(1,(size))                     //~5930I~
#define UALLOCM(size)     umalloc((size))                       //~5930I~
#define UALLOCC(n,size)   ucalloc((n),(size))                   //~5930I~
#define UALLOCM16(size)   umalloc16((size))                     //~5930I~
#define UALLOCC16(n,size) ucalloc16((n),(size))                 //~5930I~
                                                                //~5930I~
#define UFREEIFNZ(addr) if (addr) ufree(addr);                  //~5930R~
#define UFREECLEARIFNZ(addr) if (addr) {ufree(addr);addr=0;}       //~v60rI~
//*******************************************************       //~5930I~
//*alloc debug data
typedef struct _UALLOCD {
						long allocctr;
						long alloclen;
						long netreqlen;
						long freectr;
						long freelen;
						long maxlen;
						long alloc16ctr;	//for seg16
						long alloc16len;
						long netreq16len;
						long free16ctr;
						long free16len;
						long max16len;
						char *pagemap;   //for os2 only            //~v102R~
						int  pagemapsz; //for os2 only             //~v102I~
					  	}	UALLOCD;

//*******************************************************
//*ugetallocdata
UALLOCD *ugetallocdata(void);

//*******************************************************
//*ualloc_init
void ualloc_init(int Popt,unsigned char *Pfilename);
#define UALLOC_CLOSE     0         //reset debug and close tracefile//~5930R~
#define UALLOC_DEBUG     1         //accum req count and size   //~5930I~
#define UALLOC_TRACE     2         //write trace                //~5930R~
#define UALLOC_ERRRETURN 4         //return to caller when alloc err//~5930R~
#define UALLOC_ERREXIT   8         //exit prog when alloc err(default)//~5930I~
#define UALLOC_TRACE2  0x10        //write trace with 2 level return addr//~v593R~
#define UALLOC_NOSHARE 0x20        //exclusive write mode          //~v6B1I~

//*******************************************************          //~v568I~
int ualloc_chk(int Popt);                                          //~v568I~
#define UAC_EXIT     0x01                                          //~v568I~
#define UAC_MSG      0x02                                          //~v568I~
                                                                   //~v568I~
//*******************************************************
//*uallocsz
int uallocsz(size_t Plen);

//*******************************************************
void *umalloc(size_t Psize);

//*******************************************************
void ufree(void *Paddr);

//*******************************************************
void *ucalloc(size_t Pno,size_t Psize);

#if defined(DOS) || defined(W32) || defined(UNX)                   //~v327R~
	#define umalloc16(p) umalloc(p)
//  #define ucalloc16(p) ucalloc(p)                                //~v5mcR~
    #define ucalloc16(n,p) ucalloc(n,p)                            //~v5mcI~
	#define ufree16(p)   ufree(p)
#else

//*******************************************************
void *umalloc16(size_t Psize);

//*******************************************************
void *ucalloc16(size_t Pno,size_t Psize);

//*******************************************************
void ufree16(void * pvoid);

#endif
//*******************************************************
int ufreesz(void *Ppvoid);
//*******************************************************          //+v6F0I~
#ifdef W32                                                         //+v6F0I~
int ubacktrace(int Popt,int Pskipctr,int Pgetctr,void **Pout);     //+v6F0I~
#endif                                                             //+v6F0I~
