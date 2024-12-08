//CID://+v6hhR~:	update#=      2 1                              //~v6hhR~
//*******************************************************
//*ufuncmap.h
//*******************************************************
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -stack accessible by external symbol(__djgpp...)     //~v053I~
//v046:961109:chk Heap middle hole(decommitted page)               //~v046I~
//v034:961008:VisualC++ support(identify by (_MSC_VER>=800))       //~v034I~
//*******************************************************          //~v034I~
#ifdef DPMI					//DPMI version                         //~v053I~
    #define PAG_COMMIT          0x00000001   //dpmi v1.0 ax=0506h defined//~v053R~
#else                       //not DPMI                             //~v053I~
    #ifdef W32  //copy from f:\toolkt21\c\os2h\bsexcpt.h           //~v053I~
        #define PAG_COMMIT          0x00000010   //no corresponding in w95//~v053I~
    #else                       //not DPMI                         //~v053I~
    #endif                      //DPMI or not                      //~v053I~
#endif                      //DPMI or not                          //~v053I~
#define MAPEPANAMESZ 	32
#define MAXPATHPARM 	8		//parm word count to be set
//********************************************************************
//#define  VALIDDATA(addr)                                         //+v6hhR~
//			((ULONG)(addr) >= pstacktop  && (ULONG)(addr) < pstackend)//+v6hhR~
#define  VALIDDATA(addr)                            \
			((ULPTR)(addr) >= pstacktop  && (ULPTR)(addr) < pstackend)//+v6hhI~
//*******************************************************
typedef struct _EPATBL	{
						long  addr;		//atorage addr
						long  len;		//function len
						UCHAR funcname[MAPEPANAMESZ];//null for stopper
						} EPATBL;
typedef EPATBL *PEPATBL;

//* call path table
typedef struct _PATHTBL{
						ULONG 	ebp;
						ULONG   epa;
						UCHAR   funcname[32];
						ULONG	ebpp;
						ULONG	ret;
						ULONG	parm[MAXPATHPARM];
						} PATHTBL;
typedef PATHTBL*  PPATHTBL;
#define PATHTBLSZ (sizeof(PATHTBL))
//*******************************************************
//*ufuncmap
//* create epa table from map file
//* parm1:map file path/name
//* parm2:base(main) addr
//* parm3:ptr of tbl ptr
//* return: rc
//*******************************************************
int ufuncmap(UCHAR *Pfilename,PVOID Pbase,PEPATBL *Ppepatbl);

//*******************************************************
//*ugetepa
//* search epa table entry containing parm addr
//* parm1:map tbl addr gotten by ufuncmap
//* parm2:instruction addr
//* return:epa tbl entry addr or 0 if not found
//*******************************************************
PEPATBL ugetepa(PEPATBL Ppepatbl,PVOID Paddr);

//****************************************************************
//*ufuncpathmsg
//*create function call path table *
//*parm1: map filename
//*parm2: first EBP value if 0,uehpathmsg call point is assumed
//*parm3: first EIP value
//*return:msg buff addr
//****************************************************************
UCHAR *ufuncpathmsg(UCHAR *Pmapfilename,ULONG Pebp,ULONG Paddr);

//***************************************************
//* ufuncpathmsgsub         
//* setup call path function name 
//*   parm1:pathtbl
//*   parm2:output buff;
//*  return:msg length
//****************************************************
int ufuncpathmsgsub(PPATHTBL Pppathtbl,UCHAR *Pbuff);

//****************************************************************
//*get function call path table *
//*parm1: epatbl ptr
//*parm2: first EBP value
//*parm3: first EIP value(abend instruction)
//*return:path table addr(0 if err)
//****************************************************************
PPATHTBL ufuncpathtbl(PEPATBL Ppepatbl,ULONG Pebp,ULONG Paddr);

//********************************************************************
//********************************************************************
void ugetstackaddr(ULONG *pstacktop,ULONG *pstackend);

#ifdef DPMI                                                        //~v053I~
//********************************************************************//~v053I~
void ugetdataseg(ULONG *Ppdatasegtop,ULONG *Ppdatasegend,          //~v053I~
                 ULONG *Ppbsssegtop,ULONG *Ppbsssegend,            //~v053I~
                 ULONG *Ppdsbase,ULONG *Ppdsend);                  //~v053R~
#else           //no DPMI                                          //~v053I~
//********************************************************************
//void usetmainebp(ULONG Pebp);                                    //~v6hhR~
void usetmainebp(ULPTR Pebp);                                      //~v6hhI~
#endif      //no DPMI                                              //~v053I~

//**********************************************
//*memory accessible test
//*parm 1:addr to be chk
//*parm 2:storage len
//*parm 3:storage attr
//**********************************************
UINT umemchk(ULONG Paddr,ULONG *Ppsize,ULONG *Ppattr);
                                                                   //~v034I~
#if (_MSC_VER >= 800)                                      //+v034I~//~v034I~
//********************************************************************//~v034I~
int ugettopheap(void **Ppheaph,int *Ppnextoff);                    //~v034R~
                                                                   //~v034I~
//********************************************************************//~v034I~
int ugetmoduledata(ULONG *Ptexttop,ULONG *Ptextend,ULONG *Pdatatop,ULONG* Pdataend);//~v034I~
                                                                   //~v034I~
#else 	//not vc                                                     //+v034I~//~v034I~
#endif                                                     //+v034I~//~v034I~
                                                                   //~v034I~
#ifdef DOS                                                         //~v046I~
#else                                                              //~v046I~
//**********************************************                   //~v046I~
//*search commit page                                              //~v046I~
//*parm 1:addr to be chk start                                     //~v046I~
//*parm 2:chk len                                                  //~v046I~
//*retern:output first commit page addr                            //~v046I~
//**********************************************                   //~v046I~
void *umemsrch(void *Paddr,ULONG Ppsize);                          //~v046I~
#endif                                                             //~v046I~
