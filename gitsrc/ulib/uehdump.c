//CID://+v6hhR~:        update#=      1     1                      //+v6hhR~
// *******************************************************************
// * uehdump.c                                                     //~v027R~
// * 機能概要   : exception handler set/unset,exception handler itself
// *******************************************************************
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//+v6hhI~
//v5b4:040124 (WIN)new memory dump logic unsq VirtualQuery func    //~v5b4I~
//v287:991023 UTRACEP is not nop; IF epatbl!=0 range terminate at UTRACEP//~v287I~
//v234:990417 (BUG)uerrmsg parm count chk by xuerpck               //~v234I~
//v174:980501 (WinNT)dump also in the range of residual.it may be used befre.//~v172R~
//            (i tested once.it is filled by old err msg)          //~v174I~
//v173:980501 (BUG)memchk should rc=1 when len changed.dump by commit len//~v173I~
//v172:980501 (BUG)memchk fail for process heap,use HeapWalk       //~v172I~
//                 because intermediate uncommitted space exist    //~v172I~
//v167:980430 test eh bug                                          //~v167I~
//v136:980103 (W32)WINNT support                                   //~v136I~
//            -udosiswinnt func   udos.c/h ualloc.c                //~v136I~
//            -dump heap          uehdump.c                        //~v136I~
//v119:971115 (BUG:GCC)64k allocmem by 501h(in sblk or stub) dose not//~v119I~
//                     return 64k boundary addr(selector base may be not//~v119I~
//                     64k boundary).so use 4k page logic same as os2.//~v119I~
//                     and addr may from top(ff______).            //~v119I~
//v107:971027 (BUG:GCC)errno==0 when writedump err if too large(minus) len//~v107I~
//v106:971027 (BUG:GCC)sbrk dosenot return continuous memory under win95.//~v106I~
//            Block addr is page boundary -4 at first by the logic in malloc.//~v106I~
//            (req to __sblk to set __what_size_dpmi_think_we_are to page boundary.)//~v106I~
//            Blk in another 64k may be on page boundary if __what_size_app_think_it_is//~v106I~
//            reached to it.                                       //~v106I~
//            Abandon -4 setup logicin malloc.It may return always page boundary.//~v106I~
//            And,dump page should also collect by alloc addr like as os/2.//~v106I~
//v102:971010 os2 new malloc dump logic                            //~v102I~
//            uehdump.c:dump allocated page,shorten epa tbl        //~v102I~
//v070:970401:(DOS)print seg reg when dump                         //~v070I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -ehception handle by signal                          //~v053I~
//v046:961109:chk Heap middle hole(decommitted page)               //~v046I~
//v037:961017:(BUG for DOS)addr set miss for dump write residual write of 64K boundary//~v037I~
//v034:961008:VisualC++ support(identify by (_MSC_VER>=800))       //~v034I~
//v033:960930:(BUG)dump write lenchk bug cause write err for DOS   //~v033I~
//v027:960917:dos dump sub                                         //~v027I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
// *950111 pblock by calloc not by ucalloc(out of free chk)     //~5111R~
// *941120 heap size by 64k                                     //~5111I~
// *******************************************************************


#include <string.h>
#include <stdlib.h>       //malloc,free
#include <stdio.h>

#ifdef DOS                                                         //~v027I~
    #include <dos.h>                                               //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053I~
	    #include <errno.h>                                         //~v053I~
//      #include <dpmi.h>       //@@@@test                         //~v119R~
    #else                       //not DPMI                         //~v053I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v027I~
#ifdef W32                                                         //~v022R~
    #include <windows.h>                                           //~v022R~
#else                                                              //~v022I~
    #define INCL_DOSSEMAPHORES  //for DosCreate/Request/ReleaseMutexSem//~v027R~
    #define INCL_DOSEXCEPTIONS  //c.b about exception handle       //~v022I~
    #define INCL_DOSDATETIME    //for DosSleep,DosGetDateTime      //~v022I~
    #define INCL_DOSPROCESS     //c.b about tib/pib                //~v022I~
    #define INCL_DOSERRORS      //for r.c                          //~v022I~
    #include <os2.h>                                               //~v027R~
#endif                                                             //~v022I~
#endif                                                             //~v027I~
                                                                   //~v022I~
#include <ulib.h>                                                  //~v022I~
#include <uerr.h>
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053I~
        #include <ueh.h>                                           //~v053I~
    #else                       //not DPMI                         //~v053I~
	#include <ufile.h>                                             //~v027I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v027I~
	#ifdef W32                                                     //~v136I~
	    #include <udos.h> 		//udosiswinnt                      //~v136I~
    #endif                      //DPMI or not                      //~v136I~
    #include <ueh.h>                                               //~v027I~
#endif                                                             //~v027I~
#include <ualloc.h>                                            //~v027R~//~v027I~
#include <uedit.h>                                             //~v027R~//~v027I~
#include <ufuncmap.h>                                          //~v027R~//~v027I~
#include <uehdump.h>                                               //~v027M~
#include <utrace.h>                                                //~v167I~
//********************************************************************
#define DMP_OPEN    0         //open dump file                     //~v027M~
#define DMP_WRITE   1         //write dump file                    //~v027M~
                                                                   //~v5b4I~
//********************************************************************//~v027I~
//#ifdef OS2                                                       //~v106R~
#if defined(OS2) || defined(DPMI)                                  //~v106I~
	int uehdumpmapage(PUEXREGREC Ppurr);                           //~v102R~
	int uehdumpmapagesub(PUEXREGREC Ppurr,char *Psaddr,char *Peaddr);//~v102I~
#endif                                                             //~v102I~
#ifdef DOS                                                         //~v027I~
#ifdef DPMI					//DPMI version                         //~v053I~
//***************************************************************  //~v053I~
//********************************************************************//~v053I~
APIRET wdumprec(PUEXREGREC Ppurr,PVOID Paddr,int Plen);            //~v053I~
APIRET uehio(ULONG,PUEXREGREC,PVOID,PVOID,ULONG);                  //~v053I~
//*************************************************************    //~v053I~
//* 関数名     : uehdump for DPMI                                  //~v053I~
//* INPUT      :                                                   //~v053I~
//*     p1:exception report                                        //~v053I~
//*     p2:exception registration record addr                      //~v053I~
//*     p3:context record                                          //~v053I~
//*     p4:abend info msg area addr                                //~v053I~
//*     p5:epa tbl                                                 //~v053I~
//* RETURN     : void                                              //~v053I~
//* 機能概要   : write dump to file                                //~v053I~
//*************************************************************    //~v053I~
void uehdump(PEXCEPTIONREPORTRECORD pexreprec,                     //~v053I~
               PUEXREGREC Ppurr,                                   //~v053I~
               PCONTEXTRECORD pctxrec,                             //~v053I~
               UCHAR* msgwk,                                       //~v053I~
               PEPATBL Ppepatbl)                                   //~v053I~
{                                                                  //~v053I~
  ULONG  len;                                                      //~v053I~
  ULONG  addr;                                                     //~v053I~
  ULONG  stacktop,stackend;     //commiYtted stack start/end       //~v053R~
ULONG datasegtop,datasegend,bsssegtop,bsssegend,dsbase,dsend;      //~v053R~
                                                                   //~v053I~
//****************************                                     //~v053I~
                                                                   //~v053I~
                                                                   //~v053I~
//****************************                                     //~v053I~
//* open dump file           *                                     //~v053I~
//****************************                                     //~v053I~
  if (!(Ppurr->UERGdumpfh))                                        //~v053I~
    if (uehio(DMP_OPEN,Ppurr,NULL,NULL,0)) return;                 //~v053I~
                                                                   //~v053I~
//****************************                                     //~v053I~
//* write dump file          *                                     //~v053I~
//****************************                                     //~v053I~
                                                                   //~v053I~
//*abend simpton                                                   //~v053I~
  if (msgwk) //uehabinf was called                                 //~v053I~
    if (uehio(DMP_WRITE,Ppurr,UDMPID_ABINFO,                       //~v053I~
              msgwk,strlen(msgwk))                                 //~v053I~
       ) return;                                                   //~v053I~
                                                                   //~v053I~
//*report record                                                   //~v053I~
  if (uehio(DMP_WRITE,Ppurr,UDMPID_REPREC,                         //~v053I~
            pexreprec,sizeof(EXCEPTIONREPORTRECORD))               //~v053I~
     ) return;                                                     //~v053I~
                                                                   //~v053I~
//*context record                                                  //~v053I~
  if (uehio(DMP_WRITE,Ppurr,UDMPID_CTXREC,                         //~v053I~
            pctxrec,sizeof(CONTEXTRECORD))                         //~v053I~
     ) return;                                                     //~v053I~
                                                                   //~v053I~
//*registration record                                             //~v053I~
  if (uehio(DMP_WRITE,Ppurr,UDMPID_REGREC,                         //~v053I~
            Ppurr,sizeof(UEXREGREC))                               //~v053I~
     ) return;                                                     //~v053I~
                                                                   //~v053I~
//*epa tbl                                                         //~v053I~
	if (Ppepatbl)                                                  //~v053I~
 		 if (uehio(DMP_WRITE,Ppurr,UDMPID_EPATBL,                  //~v053I~
//      	    Ppepatbl,(UINT)ufreesz(Ppepatbl))                  //~v106R~
        	    Ppepatbl,16)    //dup area,shorten area            //~v106I~
     ) return;                                                     //~v053I~
                                                                   //~v053I~
//*stack seg                                                       //~v053I~
	ugetstackaddr(&stacktop,&stackend);//get stack top,end         //~v053I~
	addr=stacktop;                                                 //~v053R~
    len=stackend-stacktop;                                         //~v053R~
    if (uehio(DMP_WRITE,Ppurr,UDMPID_STACK,(PVOID)addr,len))       //~v053R~
    	return;                                                    //~v053R~
//*data seg                                                        //~v053I~
    ugetdataseg(&datasegtop,&datasegend,                           //~v053I~
                 &bsssegtop,&bsssegend,                            //~v053I~
                 &dsbase,&dsend);                                  //~v053I~
	addr=datasegtop;                                               //~v053I~
	len=datasegend-datasegtop;                                     //~v053R~
    if (uehio(DMP_WRITE,Ppurr,UDMPID_DATA,(PVOID)addr,len))        //~v053R~
    	return;                                                    //~v053R~
//*bss seg                                                         //~v053I~
	addr=bsssegtop;                                                //~v053I~
    if (stacktop<bsssegend)  //bss seg x200 boundary override stack seg//~v053R~
		len=stacktop-bsssegtop;                                    //~v053R~
    else                                                           //~v053I~
		len=bsssegend-bsssegtop;                                   //~v053I~
    if (uehio(DMP_WRITE,Ppurr,UDMPID_BSSDATA,(PVOID)addr,len))     //~v053I~
    	return;                                                    //~v053I~
//*heap                                                            //~v053I~
//    addr=bsssegend;                                              //~v106R~
//    len=dsend-dsbase-bsssegend;                                  //~v106R~
//    if (uehio(DMP_WRITE,Ppurr,UDMPID_HEAP,(PVOID)addr,len))      //~v106R~
//        return;                                                  //~v106R~
    uehdumpmapage(Ppurr);        //malloc page dump                //~v106I~
}//uehdump                                                         //~v053I~
                                                                   //~v053I~
#else                       //not DPMI                             //~v053I~
//***                                                              //~v027I~
extern int main(int,char*[]);                                      //~v027I~
extern USHORT _EmDataSeg;		//DS save area?                    //~v027I~
extern USHORT end;				//end of DSEG,start of stack       //~v027I~
static	FILE *Sfh;                                                 //~v027I~
//***                                                              //~v027I~
int  	wdumprec(char *Pfile,PVOID Paddr,ULONG Plen);              //~v027I~
int 	uehio(int reqid,char *Pfile,PVOID title,PVOID addr,ULONG len);//~v027I~
//**************************************************************** //~v027M~
// uehdump     for DOS                                             //~v027R~
//   dump for dos                                                  //~v027R~
//*parm1:file name                                                 //~v027R~
//*parm2:abinf msg array(uerrexit msg,path msg)                    //~v027I~
//*parm3:epa table addr(option)                                    //~v027I~
//*retrn:0:ok, else:failed                                         //~v027M~
//**************************************************************** //~v027M~
void uehdump(char *Pfile,char **Pabinfmsg,PEPATBL Ppepatbl)        //~v027R~
{                                                                  //~v027M~
	UDOSCON	udcn;                                                  //~v027I~
    void    *ptr;                                                  //~v027R~
//**********************                                           //~v027M~
	if (uehio(DMP_OPEN,Pfile,(ULONG)0,(ULONG)0,(ULONG)0))    	//open dump file//~v027I~
    	return;                                                    //~v027I~
	ptr=Pabinfmsg[0];       //uerrexit msg                         //~v027I~
	if (!ptr)                                                      //~v027R~
    	ptr="\n";                                                  //~v027R~
  	if (uehio(DMP_WRITE,Pfile,UDMPID_ABINFO,ptr,(ULONG)strlen(ptr)))//~v027R~
       	return;                                                    //~v027R~
	ptr=Pabinfmsg[1];		//path msg                             //~v027I~
	if (ptr)                                                       //~v027I~
	  	if (uehio(DMP_WRITE,Pfile,UDMPID_ABINFO,ptr,(ULONG)strlen(ptr)))//~v027I~
    	   	return;                                                //~v027I~
//*dos context                                                     //~v027I~
	udcn.UDCNepamain=(void*)main;                                  //~v027R~
	udcn.UDCNbpsavearea=(char*)&Pfile-6;	//BP,ret IP,ret CS,first parm//~v027R~
	udcn.UDCNenddata=(void*)&end;			//end of DATA,start of STACK//~v027R~
  	udcn.UDCNds0=*(USHORT*)(&_EmDataSeg);	//one on var on data segment//~v070R~
  	_asm mov udcn.UDCNds,ds                 //current              //~v070R~
  	_asm mov udcn.UDCNss,ss                                        //~v070I~
  	_asm mov udcn.UDCNcs,cs                                        //~v070I~
	if (uehio(DMP_WRITE,Pfile,UDMPID_CTXREC,&udcn,(ULONG)sizeof(udcn)))//~v027R~
    	return;                                                    //~v027I~
//*epa tbl                                                         //~v027I~
	if (Ppepatbl)                                                  //~v027I~
 		 if (uehio(DMP_WRITE,Pfile,UDMPID_EPATBL,Ppepatbl,(ULONG)(UINT)ufreesz(Ppepatbl)))//~v027R~
     		return;                                                //~v027I~
//dump conventional memory                                         //~v027R~
 	if (uehio(DMP_WRITE,Pfile,UDMPID_DOSMEM,(ULONG)0,(ULONG)0xa0000))//~v027I~
    	return;                                                    //~v027I~
	printf("===== Dump Taken,%s\n",Pfile);                         //~v027I~
    return;                                                        //~v027R~
}//uehdump                                                         //~v027R~
#endif                      //DPMI or not                          //~v053I~
                                                                   //~v027I~
#else           //ifdef DOS                                        //~v027R~
                                                                   //~v027I~
//***************************************************************
#define MAXUPBLENTRY   100    //defined entry count

typedef struct _UPBLOCK{
        UCHAR    UPBLeyec[8]; //eyecatcher 
        ULONG    UPBLmaxcount;//entry size
        ULONG    UPBLusecount;//used entry
        ULONG    UPBLmtxsem  ;//semaphore for multi thread process
        ULONG    UPBLflag    ;//flag     
#define UPBLFCRESEM 0x00000080 //semaphore created
        struct {  
                 UCHAR UPBLtitle[16]; //comment
                 PVOID UPBLaddr; //storage addr
                 ULONG UPBLlen ; //storage length
                 PVOID UPBLpurr; //UEXREGREC
               } UPBLentry[MAXUPBLENTRY]; //storage addr and length
} UPBLOCK;
typedef UPBLOCK*  PUPBLOCK;
#define UPBLOCKSZ (sizeof(UPBLOCK))
//***************************************************************
static PUPBLOCK     Spupblock;
//********************************************************************
APIRET wdumprec(PUEXREGREC Ppurr,PVOID Paddr,int Plen);            //~v022R~
APIRET uehio(ULONG,PUEXREGREC,PVOID,PVOID,ULONG);                  //~v022R~
//*************************************************************
//* 関数名     : uehdump for OS/2                                  //~v027R~
//* INPUT      :
//*     p1:exception report
//*     p2:exception registration record addr
//*     p3:context record
//*     p4:abend info msg area addr
//*     p5:epa tbl
//* RETURN     : void
//* 機能概要   :
//*             write thread dump to file(one for all thread)
//*************************************************************
void uehdump(PEXCEPTIONREPORTRECORD pexreprec,
               PUEXREGREC Ppurr,
               PCONTEXTRECORD pctxrec,
               UCHAR* msgwk,
               PEPATBL Ppepatbl)
{ 
#ifdef ULIB64X                                                     //+v6hhI~
#else                                                              //+v6hhI~
#ifdef W32                                                         //~v022R~
                                                                   //~v5b4I~
  #ifdef  W32NEWDUMP                                               //~v5b4R~
	void w32newmemchk(PUEXREGREC Ppurr,ULONG Pstackend,ULONG Pdatatop,ULONG Pdataend);//~v5b4R~
	ULONG  datatop,dataend;                                        //~v5b4I~
  #else   //not W32NEWDUMP                                         //~v5b4I~
	#if (_MSC_VER >= 800)                                      //+v034I~//~v034I~
    	#define MAXHANDLE 100                                      //~v136R~
    	#define HEAPH_RESIDUAL_DWCOUNT 0x28  //hephdr,residula dword count pos//~v136I~
    	#define HEAPH_ENDADDR          0x4cc //hephdr,block end addr field pos//~v136I~
    	HANDLE heapht[MAXHANDLE];                                  //~v136R~
        PROCESS_HEAP_ENTRY heape;                                  //~v172R~
        PUNTHEAPH    phrgnhdr;//region header block ptr            //~v172I~
        int ii;                                                    //~v172I~
        int heapno;                                                //~v136R~
    	APIRET apiret;                                             //~v136R~
//      ULONG *ulp;                                                //~v172R~
        ULONG ulrcnt;	                                           //~v172R~
        int rc,nextoff;                                            //~v034I~
        void *heaph,*sheaph;                                       //~v034I~
		ULONG  attr;		//memchk                               //~v034I~
		ULONG  datatop,dataend;                                    //~v034R~
        char  *commit,*commit2;                                    //~v046R~
        int   heapmaxlen;                                          //~v046R~
    #else                                                          //~v022I~
    	extern ULONG _stkbase;                                     //~v034I~
		extern ULONG _heaps[];                                     //~v022R~
		extern ULONG _nheaps;                                      //~v022I~
	#endif                                                         //~v022I~
  #endif  //not W32NEWDUMP                                         //~v5b4I~
#else                                                              //~v022R~
	ULONG  attr;//dosquerymem attribute                            //~v022I~
	APIRET apiret;               //                                //~v022I~
#endif                                                             //~v022R~

  ULONG  i;                    //work index 
  PUPBLOCK pupblock;           //pblock base
  ULONG  len;
  ULONG  addr;
  ULONG  pstacktop,pstackend;     //commiYtted stack start/end

//****************************
  
  ugetstackaddr(&pstacktop,&pstackend);//get stack top,end
  
//****************************
//* open dump file           *
//****************************
  if (!(Ppurr->UERGdumpfh))
    if (uehio(DMP_OPEN,Ppurr,NULL,NULL,0)) return;

//****************************
//* write dump file          *
//****************************

//*abend simpton
  if (msgwk) //uehabinf was called          
    if (uehio(DMP_WRITE,Ppurr,UDMPID_ABINFO,
              msgwk,strlen(msgwk))          
       ) return;                            

//*report record
  if (uehio(DMP_WRITE,Ppurr,UDMPID_REPREC,
            pexreprec,sizeof(EXCEPTIONREPORTRECORD))
     ) return;

//*context record
  if (uehio(DMP_WRITE,Ppurr,UDMPID_CTXREC,
            pctxrec,sizeof(CONTEXTRECORD))
     ) return;

//*registration record
  if (uehio(DMP_WRITE,Ppurr,UDMPID_REGREC,
            Ppurr,sizeof(UEXREGREC))
     ) return;

//*epa tbl
	if (Ppepatbl)
#ifdef OS2                                                         //~v102I~
 		 if (uehio(DMP_WRITE,Ppurr,UDMPID_EPATBL,                  //~v102I~
        	    Ppepatbl,16)    //duplicate with page map tbl      //~v102I~
#else                                                              //~v102I~
//UTRACEP("before uehdump,pepatbl=%08x\n",Ppepatbl);               //~v287R~
//UTRACED("ehdump,pepatbl",(char*)(void*)Ppepatbl-8,256);          //~v287R~
//UTRACEP("before uehdump,size=%08x\n",ufreesz(Ppepatbl));         //~v287R~
//UTRACEP("before uehdump call uehio\n");                          //~v287R~
 		 if (uehio(DMP_WRITE,Ppurr,UDMPID_EPATBL,
        	    Ppepatbl,(UINT)ufreesz(Ppepatbl))
#endif                                                             //~v102I~
     ) return;

#ifdef W32                                                         //~v022I~
  #ifndef W32NEWDUMP    //old logic deleted                        //~v5b4I~
	#if (_MSC_VER >= 800)   //vc                               //+v034I~//~v034I~
//*stack seg                                                       //~v034R~
        addr=pstacktop;                                            //~v034I~
        len=pstackend - pstacktop;                                 //~v034I~
UTRACEP("before uehdump,stack=%08x,len=%08x\n",addr,len);          //~v167I~
        if (uehio(DMP_WRITE,Ppurr,UDMPID_STACK,(PVOID)addr,len)    //~v034I~
           ) return;                                               //~v034I~
//*data seg                                                        //~v034I~
		if (!ugetmoduledata(&addr,&addr,&datatop,&dataend))        //~v034I~
        {                                                          //~v034I~
UTRACEP("ugetmoduledata ok addr=%08x,datatop=%08x,dataend=%08x\n",addr,datatop,dataend);//~v167I~
	        len=dataend-datatop;                                   //~v034I~
            if (uehio(DMP_WRITE,Ppurr,UDMPID_DATA,(PVOID)datatop,len)//~v034I~
               ) return;                                           //~v034I~
		}                                                          //~v034I~
UTRACEP("after uehio datatop uehiox\n");                           //~v167I~
    #else                                                      //+v034I~//~v034I~
//*data seg		W95 dose not follow continuous stack               //~v022I~
	addr=(ULONG)&Spupblock & 0xffff0000;	//64k boundary of any static data//~v022I~
  	len=(((ULONG)&_stkbase+4095) & 0xfffff000)-(ULONG)addr;	//4k boundary//~v022I~
//  printf("before data io addr=%08x,len=%08x\n",addr,len);        //~v022R~
  	if (uehio(DMP_WRITE,Ppurr,UDMPID_STACK,(PVOID)addr,len))       //~v022I~
		return;                                                    //~v022I~
//  printf("after  data io end\n");                                //~v022R~
	addr=pstacktop;                  	//4k boundary              //~v022I~
  	len=((pstackend+4095)&0xfffff000) - pstacktop;                 //~v022I~
//  printf("before stack io addr=%08x,end=%08x,len=%08x\n",addr,pstackend,len);//~v022R~
  	if (uehio(DMP_WRITE,Ppurr,UDMPID_STACK,(PVOID)addr,len)        //~v022I~
     ) return;                                                     //~v022I~
//  printf("after  stack io end =%08x,\n",pstackend);              //~v022R~
    #endif  //bc                                               //+v034I~//~v034I~
  #endif //W32NEWDUMP    //old logic deleted                       //~v5b4I~
#else                                                              //~v022R~
//*data/stack seg
  addr=pstacktop;
  len=pstackend - pstacktop;
  if (uehio(DMP_WRITE,Ppurr,UDMPID_STACK,(PVOID)addr,len)
     ) return;
#endif                                                             //~v022I~

//*******************************
//* area registered on upblock   *
//*******************************
#ifdef W32                                                         //~v022I~
#ifndef W32NEWDUMP    //old logic deleted                          //~v5b4I~
#if (_MSC_VER >= 800)                                      //+v034I~//~v034I~
//GetProcessHeaps fail with rc=120(not implemented)                //~v034I~
//  heapno=GetProcessHeaps(MAXHANDLE,heapht);                      //~v034R~
//  if (!heapno)                                                   //~v034R~
//  {                                                              //~v034R~
//  	apiret=GetLastError();                                     //~v034R~
//  	uerrexit("GetProcessHeaps failed,rc=%d",                   //~v034R~
//  			0,                                                 //~v034R~
//  			apiret);                                           //~v034R~
//  }                                                              //~v034R~
//  for(;heapno;heapno--)                                          //~v034R~
//  {                                                              //~v034R~
//  	heaph=heapht[heapno-1];                                    //~v034R~
//      memset(&heape,0,sizeof(heape));                            //~v034R~
//      for (;;)                                                   //~v034R~
//      {                                                          //~v034R~
//      	if (!HeapWalk(heaph,&heape))                           //~v034R~
//          {                                                      //~v034R~
//  	    	apiret=GetLastError();                             //~v034R~
//              if (apiret==ERROR_NO_MORE_ITEMS)                   //~v034R~
//              	break;                                         //~v034R~
//  			uerrexit("HeapWalk failed for heap handle %08d,rc=%d",//~v034R~
//  						0,                                     //~v034R~
//  						heaph,apiret);                         //~v034R~
//  		}                                                      //~v034R~
//  		if (heape.wFlags & PROCESS_HEAP_REGION)                //~v034R~
//          {                                                      //~v034R~
//  			len=uaddpblock(Ppurr,                              //~v034R~
//  						UDMPID_HEAP,                           //~v034R~
//  						(PVOID)((ULONG)heape.lpData-heape.cbOverhead),//~v034R~
//  						heape.cbData+heape.cbOverhead);        //~v034R~
//      		break;                                             //~v034R~
//          }                                                      //~v034R~
//  	}//HeapWalk                                                //~v034R~
//      if (len==(UINT)-1)	//pblk tbl overflow                    //~v034R~
//      	break;                                                 //~v034R~
//  }//all heap                                                    //~v034R~
  if (udosiswinnt())		//windows/NT                           //~v136I~
  {                                                                //~v136I~
    heapno=GetProcessHeaps(MAXHANDLE,heapht);                      //~v136I~
UTRACEP("nt heapno=%d\n",heapno);                                  //~v167I~
    if (!heapno)                                                   //~v136I~
    {                                                              //~v136I~
    	apiret=GetLastError();                                     //~v136I~
    	uerrmsg("GetProcessHeaps failed,rc=%d",                    //~v136R~
    			0,                                                 //~v136I~
    			apiret);                                           //~v136I~
    }                                                              //~v136I~
    for(;heapno;heapno--)                                          //~v136I~
    {                                                              //~v136I~
    	heaph=heapht[heapno-1];                                    //~v136I~
//*get commit size                                                 //~v172I~
        memset(&heape,0,sizeof(heape)); //start id for HeapWalk    //~v172I~
        if (!HeapWalk(heaph,&heape))                               //~v172R~
        {                                                          //~v172R~
    	    apiret=GetLastError();                                 //~v172R~
            if (apiret!=ERROR_NO_MORE_ITEMS)                       //~v172R~
    			printf("HeapWalk failed for heap handle %08d,rc=%d",//~v172R~
    					heaph,apiret);                             //~v172R~
UTRACEP("heap exausted");                                          //~v174I~
    	}                                                          //~v172R~
        else                                                       //~v172I~
        {                                                          //~v172I~
UTRACED("heap entry",&heape,sizeof(heape));                        //~v172R~
    		if (heape.wFlags & PROCESS_HEAP_REGION)                //~v172I~
            {                                                      //~v172I~
UTRACEP("heapwalk data=%08x,len=%08x,overhead=%d,rgnindex=%d,flag=%04x\n",//~v172I~
    heape.lpData,heape.cbData,(int)heape.cbOverhead,(int)heape.iRegionIndex,(int)heape.wFlags);//~v172I~
UTRACEP("heapwalk comm=%08x,uncomm=%08x,fst=%08x,lst=%08x\n",      //~v172I~
    heape.Region.dwCommittedSize,                                  //~v172I~
    heape.Region.dwUnCommittedSize,                                //~v172I~
    heape.Region.lpFirstBlock,                                     //~v172I~
    heape.Region.lpLastBlock);                                     //~v172I~
        		ulrcnt=heape.Region.dwCommittedSize,               //~v172I~
UTRACEP("nt heap addblock addr=%08x,len=%08x\n",heaph,ulrcnt);     //~v172I~
				uaddpblock(Ppurr,                                  //~v172I~
							UDMPID_HEAP,                           //~v172I~
							(PVOID)heaph,                          //~v172I~
							ulrcnt);                               //~v172I~
 				phrgnhdr=heape.Region.lpLastBlock;                 //~v172R~
            	for (ii=0;ii<8;ii++)	//protect loop             //~v172R~
                {                                                  //~v172R~
UTRACEP("rgnhdr %08x\n",phrgnhdr);                                 //~v172I~
                	if (!phrgnhdr)                                 //~v172R~
                    	break;                                     //~v172R~
UTRACEP("before IsBadReadPtr %08x\n",phrgnhdr);                    //~v172I~
					if (IsBadReadPtr(phrgnhdr,sizeof(UNTHEAPH)))   //~v172R~
                    	break;			//cannot read              //~v172I~
UTRACED("heap entry",phrgnhdr,sizeof(UNTHEAPH));                   //~v172M~
                    if (phrgnhdr->UNTHHid!=UNTHHHDRID)  //cb validity chk//~v172I~
                        break;                                     //~v172I~
                    if (phrgnhdr->UNTHHflg[0]!=UNTHHRGNHDR)        //~v172I~
                        break;                                     //~v172I~
UTRACEP("rgnhdr data=%08x,alloc=%08x,uncommit=%08x,1stblk=%08x,last=%08x\n",//~v172I~
		phrgnhdr,                                                  //~v172I~
		phrgnhdr->UNTHHallocpage,                                  //~v172I~
		phrgnhdr->UNTHHuncommittedpage,                            //~v172I~
		phrgnhdr->UNTHHfirstblock,                                 //~v172I~
		phrgnhdr->UNTHHlastblock);                                 //~v172I~
        			ulrcnt=((phrgnhdr->UNTHHallocpage              //~v172R~
							- phrgnhdr->UNTHHuncommittedpage)<<12);//~v172R~
UTRACEP("nt heap addblock addr=%08x,len=%08x\n",phrgnhdr,ulrcnt);  //~v172I~
					uaddpblock(Ppurr,                              //~v172R~
								UDMPID_HEAP,                       //~v172R~
								(PVOID)phrgnhdr,                   //~v172R~
								ulrcnt);                           //~v172R~
                    phrgnhdr=phrgnhdr->UNTHHlastblock;             //~v172R~
                }//max 8 times                                     //~v172R~
            }//first is rgn hdr                                    //~v172R~
    	}//HeapWalk success                                        //~v172R~
                                                                   //~v172I~
//UTRACED("nt heap",heaph,4096);                                   //~v172R~
//      ulp=(void*)(ULONG)heaph;       //heap header               //~v172R~
//      ulrcnt=*(ulp+(HEAPH_RESIDUAL_DWCOUNT>>2));	//dw count     //~v174R~
//      ulrcnt<<=3;	                                //byte count   //~v174R~
//      ulenda=*(ulp+(HEAPH_ENDADDR>>2));                          //~v172R~
//printf ("heap=%08x,reslen=%08x,endaddr=%08x\n",heaph,ulrcnt,ulenda);//@@@@//~v136R~
//UTRACEP("nt heap addblock reslen=%08x,endaddr=%08x\n",ulrcnt,ulenda);//~v172R~
//      ulenda-=(ulrcnt&0xfffff000);	//used page boundary       //~v174R~
//      ulrcnt=ulenda-(ULONG)heaph;                                //~v172R~
//UTRACEP("nt heap addblock addr=%08x,len=%08x\n",heaph,ulrcnt);   //~v172R~
//  	uaddpblock(Ppurr,                                          //~v172R~
//  				UDMPID_HEAP,                                   //~v172R~
//  				(PVOID)heaph,                                  //~v172R~
//  				ulrcnt);                                       //~v172R~
    }//heapno                                                      //~v136I~
  }                                                                //~v136I~
  else	//not NT                                                   //~v136I~
  {                                                                //~v136I~
	if (!(rc=ugettopheap(&heaph,&nextoff)))                        //~v034R~
    {                                                              //~v034I~
		while(heaph)                                               //~v034I~
        {                                                          //~v034I~
//  	    printf("created heap addr=%08x,len=%08x\n",heaph,*(ULONG*)heaph);//~v034I~
            heapmaxlen=                                            //~v046R~
  			len=*(ULONG*)heaph;                                    //~v034I~
			umemchk((ULONG)heaph,&len,&attr); //alocated chk(return commit len)//~v034R~
  			uaddpblock(Ppurr,UDMPID_HEAP,heaph,len);               //~v034R~
//hole chk start                                                   //~v046R~
            for(commit=(char*)heaph+len,heapmaxlen-=len;heapmaxlen;)//~v046R~
            {                                                      //~v046R~
    			if (!(commit2=umemsrch(commit,heapmaxlen)))        //~v046R~
                	break;                                         //~v046R~
    			heapmaxlen-=((ULONG)commit2-(ULONG)commit);        //~v046R~
                len=heapmaxlen;                                    //~v046R~
    			umemchk((ULONG)commit2,&len,&attr); //alocated chk(return commit len)//~v046R~
  				uaddpblock(Ppurr,UDMPID_HEAP,commit2,len);         //~v046R~
                commit=commit2+len;                                //~v046R~
                heapmaxlen-=len;                                   //~v046R~
            }                                                      //~v046R~
//hole chk end                                                     //~v046R~
            sheaph=heaph;                                          //~v034I~
    		while(sheaph=(void*)(*(ULONG*)((ULONG)sheaph+4)),sheaph)//~v034I~
            {                                                      //~v034I~
//  		    printf("sub heap addr=%08x,len=%08x\n",sheaph,*(ULONG*)sheaph);//~v034I~
	  			len=*(ULONG*)sheaph;                               //~v034I~
				umemchk((ULONG)sheaph,&len,&attr); //alocated chk(return commit len)//~v034R~
	  			uaddpblock(Ppurr,UDMPID_HEAP,sheaph,len);          //~v034R~
			}                                                      //~v034I~
    		heaph=(void*)(*(ULONG*)((ULONG)heaph+nextoff));        //~v034I~
    	}                                                          //~v034I~
    }                                                              //~v034I~
  }	//not NT                                                       //~v136I~
#else                                                              //~v022I~
//malloc heap                                                      //~v022I~
//  printf("before addblock heaps =%08x,len=%08x\n",_heaps[0],_heaps[1]);//~v022R~
	for (i=0;i<_nheaps;i++)                                        //~v022I~
		uaddpblock(Ppurr,                                          //~v022R~
					UDMPID_HEAP,                                   //~v022R~
					(PVOID)_heaps[i*2],                            //~v022R~
					_heaps[i*2+1]);                                //~v022R~
                                                                   //~v022I~
//  printf("after add block\n");                                   //~v022R~
#endif	//VC                                                       //~v034R~
#else //W32NEWDUMP    //new logic                                  //~v5b4I~
	if (ugetmoduledata(&addr,&addr,&datatop,&dataend))	//either of top/end//~v5b4R~
    	datatop=0;                                                 //~v5b4I~
    UTRACEP("stack=%x-%x,data=%x-%x\n",pstacktop,pstackend,datatop,dataend);//~v5b4R~
	w32newmemchk(Ppurr,pstackend,datatop,dataend);                 //~v5b4R~
#endif	//W32NEWDUMP                                               //~v5b4I~
#else	//os2                                                      //~v022R~
#endif                                                             //~v022I~
  if (pupblock=Spupblock,pupblock) 
	for (i=0;i<pupblock->UPBLusecount;i++)
  	{
//  printf("pblk %d,purr=%08x,pupblock=%08x\n",i,Ppurr,pupblock);  //~v034R~
   	 	if ( Ppurr==pupblock->UPBLentry[i].UPBLpurr) //same as regist
    	{
			addr=(ULONG)pupblock->UPBLentry[i].UPBLaddr;  //addr
			len =pupblock->UPBLentry[i].UPBLlen ;  //len  
#ifdef W32		//no need alloc chk                                //~v022I~
#else                                                              //~v022I~
			apiret=umemchk(addr,&len,&attr); //alocated chk
			if ( !apiret )            //valid addr                 //~v102R~
//  		&& (attr&PAG_BASE) )   //start addr                    //~v102R~
#endif                                                             //~v022I~
//  printf("before pblock io addr =%08x,len=%08x\n",addr,len);     //~v022R~
UTRACEP("uehio before addr=%08x,len=%08x\n",addr,len);             //~v167I~
        	if (uehio(DMP_WRITE,Ppurr,  //option
            	(PVOID)(pupblock->UPBLentry[i].UPBLtitle),//title
            	(PVOID)addr,len)                   //addr,len
           		) return;
//  printf("after pblock io addr =%08x,len=%08x\n",addr,len);      //~v022R~
    	}//same thread as when registered
  	}//all pointer block
#ifdef OS2		//os2                                              //~v102I~
    uehdumpmapage(Ppurr);        //malloc page dump                //~v102R~
#endif          //os2                                              //~v102I~
#endif          //!ULIB64X                                         //+v6hhI~
}//uehdump                                                         //~v053R~

#endif  //ifdef DOS,else                                           //~v027I~
                                                                   //~v027I~
#ifdef W32                                                         //~v5b4I~
//*************************************************************    //~v5b4I~
//*new memory chk using virtualQuery func                          //~v5b4I~
//*************************************************************    //~v5b4I~
void w32newmemchk(PUEXREGREC Ppurr,ULONG Pstackend,ULONG Pdatatop,ULONG Pdataend)//~v5b4R~
{                                                                  //~v5b4I~
	SYSTEM_INFO si;                                                //~v5b4I~
//  ULONG paddr,pmax,pmin,sz,base;                                 //~v5b4R~//+v6hhR~
    ULPTR paddr,pmax,pmin,   base;                                 //+v6hhI~
    ULONG                 sz     ;                                 //+v6hhI~
    MEMORY_BASIC_INFORMATION mbi;                                  //~v5b4I~
    int rc;                                                        //~v5b4I~
    char *pid;                                                     //~v5b4I~
//********************                                             //~v5b4I~
    UTRACEP("stack=%x,data=%x-%x\n",Pstackend,Pdatatop,Pdataend);  //~v5b4R~
    GetSystemInfo(&si);                                            //~v5b4I~
//  pmin=(ULONG)si.lpMinimumApplicationAddress;                    //~v5b4R~//+v6hhR~
    pmin=(ULPTR)si.lpMinimumApplicationAddress;                    //+v6hhI~
//  pmax=(ULONG)si.lpMaximumApplicationAddress;                    //~v5b4R~//+v6hhR~
    pmax=(ULPTR)si.lpMaximumApplicationAddress;                    //+v6hhI~
    UTRACEP("systeminfo min=%x,max=%x\n",pmin,pmax);               //~v5b4I~
	for (paddr=pmin;paddr<pmax;)                                   //~v5b4I~
    {                                                              //~v5b4I~
    	rc=VirtualQuery((void*)paddr,&mbi,sizeof(mbi));            //~v5b4I~
	    UTRACEP("virtual query rc=%d,lasterr=%d\n",rc,GetLastError());//~v5b4R~
        if (!rc)                                                   //~v5b4I~
        	break;                                                 //~v5b4I~
	    UTRACEP("base=%x,alloc=%x,aprot=%x,sz=%x,state=%x,prot=%x,type=%x\n",//~v5b4I~
                mbi.BaseAddress,                                   //~v5b4I~
                mbi.AllocationBase,                                //~v5b4I~
                mbi.AllocationProtect,                             //~v5b4I~
                mbi.RegionSize,                                    //~v5b4I~
                mbi.State,                                         //~v5b4I~
                mbi.Protect,                                       //~v5b4I~
                mbi.Type);                                         //~v5b4I~
//      base=(ULONG)mbi.BaseAddress;                               //~v5b4R~//+v6hhR~
        base=(ULPTR)mbi.BaseAddress;                               //+v6hhI~
        sz=mbi.RegionSize;                                         //~v5b4I~
        if (mbi.Type & (MEM_PRIVATE|MEM_IMAGE) 	//image bit:winnt:on w98 off//~v5b4R~
        &&  mbi.State & MEM_COMMIT                                 //~v5b4I~
        &&  mbi.Protect & PAGE_READWRITE)                          //~v5b4I~
        {                                                          //~v5b4I~
        	if (Pstackend>base && Pstackend<=base+sz)              //~v5b4R~
            	pid=UDMPID_STACK;                                  //~v5b4I~
            else                                                   //~v5b4I~
        	if (!(Pdataend<=base || Pdatatop>=base+sz))            //~v5b4R~
            	pid=UDMPID_DATA;                                   //~v5b4I~
            else                                                   //~v5b4I~
				pid=UDMPID_HEAP;                                   //~v5b4R~
			uaddpblock(Ppurr,pid,(PVOID)base,sz);                  //~v5b4R~
        	UTRACEP("private commit readwrite a=%x,l=%x ,id=%s\n",paddr,sz,pid);//~v5b4R~
//      	UTRACED("private commit readwrite",paddr,min(4096,sz));//~v5b4R~
        }                                                          //~v5b4I~
  		paddr+=sz;                                                 //~v5b4I~
	}//up to max mem                                               //~v5b4I~
    return;                                                        //~v5b4I~
}//w32newmemchk(void)                                              //~v5b4I~
#endif                                                             //~v5b4I~
//*************************************************************
//* 関数名     : uehio
//* INPUT      :
//*     p1:req id(open/write)
//*     p2:purr for OS/2,filename for DOS                          //~v027R~
//*     p3:title comment addr
//*     p4:write addr
//*     p5:write len
//*
//* RETURN     : api r.c
//* 機能概要   :
//*             write thread dump to file(one for all thread)
//*************************************************************

#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053R~
        APIRET uehio(ULONG reqid,PUEXREGREC Ppurr,PVOID title,PVOID addr,ULONG len)//~v053R~
    #else                       //not DPMI                         //~v053R~
int	   uehio(int reqid,char *Pfile,PVOID title,PVOID addr,ULONG len)//~v027R~
    #endif                      //DPMI or not                      //~v053R~
#else                                                              //~v027I~
APIRET uehio(ULONG reqid,PUEXREGREC Ppurr,PVOID title,PVOID addr,ULONG len)
#endif                                                             //~v027I~
{ 

//static UCHAR trailer[16]="****************";                     //+v6hhR~
static UCHAR trailer[17]="****************";	//C4295 warning    //+v6hhI~

	APIRET apiret;
  UDMPHDR udmphdr;                //dump record hdr
#ifdef DOS                                                         //~v027I~
#else                                                              //~v027I~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
  LONG   i,j;                                                      //~v022M~
  ULONG  action;                  //dosopen                        //~v022M~
  DATETIME datetime;   //*hh,mm,ss,th,day,month,year,tz,dayofweek
#endif                                                             //~v022I~
#endif	//ifdef DOS else                                           //~v027I~

//****************************

  switch (reqid)
  {
  case DMP_OPEN   :                //create
//****************************
//* open dump file           *
//****************************
//*open

#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053R~
        Ppurr->UERGdumpfh=fopen(Ppurr->UERGdumpfn,"wb");           //~v053R~
        if (!Ppurr->UERGdumpfh)                                    //~v053R~
    #else                       //not DPMI                         //~v053R~
	if (!(Sfh=fopen(Pfile,"wb")))                                  //~v027I~
    #endif                      //DPMI or not                      //~v053R~
    	apiret=errno;                                              //~v027I~
	else                                                           //~v027I~
    	apiret=0;                                                  //~v027I~
#else                                                              //~v027I~
#ifdef W32                                                         //~v022R~
    Ppurr->UERGdumpfh=fopen(Ppurr->UERGdumpfn,"wb");               //~v022R~
    if (!Ppurr->UERGdumpfh)                                        //~v022I~
    	apiret=errno;                                              //~v022I~
	else                                                           //~v022I~
    	apiret=0;                                                  //~v022I~
#else                                                              //~v022I~
    apiret=DosOpen(Ppurr->UERGdumpfn,             //input file name
                   (PHFILE)(&Ppurr->UERGdumpfh),
                   &action,                  //output action taken
                   0L,             //input file size by Kbyte a921222
                   FILE_NORMAL,               //input attribute
                   OPEN_ACTION_CREATE_IF_NEW | //input open flag
                   OPEN_ACTION_REPLACE_IF_EXISTS,
                   OPEN_FLAGS_WRITE_THROUGH | //input open mode
                   OPEN_FLAGS_FAIL_ON_ERROR | //no system err process
                   OPEN_FLAGS_SEQUENTIAL |    //seq process
                   OPEN_FLAGS_NOINHERIT |     //curr proces only
                   OPEN_SHARE_DENYWRITE | //reject other proc write
                   OPEN_ACCESS_WRITEONLY, //operation mode
                   0L);                    //input/output,no eabuff
#endif                                                             //~v022I~
#endif	//ifdef DOS else                                           //~v027I~
    if (apiret)
    {  //open err
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053R~
          Ppurr->UERGflag |= UERGFDUMPERR;                         //~v053R~
    #else                       //not DPMI                         //~v053R~
    #endif                      //DPMI or not                      //~v053R~
#else                                                              //~v027I~
      Ppurr->UERGflag |= UERGFDUMPERR;
#endif	//ifdef DOS else                                           //~v027I~
      uerrmsg("Dump file(%s) Open err,rc=%d",                      //~v234R~
				"ダンプ ファイル(%s) オープンエラー,rc=%d\n",
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053R~
				Ppurr->UERGdumpfn,apiret);                         //~v053I~
    #else                       //not DPMI                         //~v053R~
				Pfile,apiret);                                     //~v027I~
    #endif                      //DPMI or not                      //~v053R~
#else                                                              //~v027I~
				Ppurr->UERGdumpfn,apiret);
#endif	//ifdef DOS else                                           //~v027I~
		return 4;
    }  //open err

    break;

  case DMP_WRITE  :                //create
//****************************                                     //~v027I~
//* write dump file          *
//****************************
//printf("$s,addr=%08lx,len=%08lx\n",title,addr,len);//@@@@        //~v027R~
//****************
//*hdr setup     *
//****************
    udmphdr.UDMPreclen=(sizeof(udmphdr)+len+15)&0xfffffff0;//up to 16 byte
    memcpy(udmphdr.UDMPreceyec,UDMPEYECID,
           sizeof(udmphdr.UDMPreceyec));
#ifdef DOS                                                         //~v027I~
    udmphdr.UDMPthreadid=0;//                                      //~v027I~
#else                                                              //~v027I~
    udmphdr.UDMPthreadid=Ppurr->UERGthreadid;//
#endif	//ifdef DOS else                                           //~v027I~

//*current time stamp
#ifdef DOS                                                         //~v027I~
	utimeedit((UCHAR *)2,				//return YYyymmddhhmmssth(hex)//~v027I~
    		  (PVOID)&udmphdr.UDMPcurrentdate);                    //~v027I~
#else                                                              //~v027I~
#ifdef W32                                                         //~v022I~
//	utimeedit((UCHAR *)2,				//return YYyymmddhhmmssth(hex)//~v022R~//+v6hhR~
	utimeedit((UCHAR *)(ULPTR)2,		//return YYyymmddhhmmssth(hex)//+v6hhI~
    		  (PVOID)&udmphdr.UDMPcurrentdate);                    //~v022R~
#else                                                              //~v022I~
    DosGetDateTime(&datetime);
    i=datetime.year /100;           //100  year
    j=datetime.year %100;           //100  year
    udmphdr.UDMPcurrentdate     //921025
       =(ULONG)(
          ((     i                 /10 )<<4 ) //1000 year
         +((     i                 %10 )    ) // 100 year
         +((     j                 /10 )<<12) //  10 year
         +((     j                 %10 )<<8 ) //   1 year
         +((    datetime.month     /10 )<<20) //  10 month
         +((    datetime.month     %10 )<<16) //   1 month
         +((    datetime.day       /10 )<<28) //  10 day
         +((    datetime.day       %10 )<<24) //   1 day
              );
    udmphdr.UDMPcurrenttime
       =(ULONG)(
          ((    datetime.hours     /10 )<< 4) //  10 hours
         +((    datetime.hours     %10 )    ) //   1 hours
         +((    datetime.minutes   /10 )<<12) //  10 minutes
         +((    datetime.minutes   %10 )<< 8) //   1 minutes
         +((    datetime.seconds   /10 )<<20) //  10 seconds
         +((    datetime.seconds   %10 )<<16) //   1 seconds
         +((    datetime.hundredths/10 )<<28) //  1/10 seconds
         +((    datetime.hundredths%10 )<<24) //  1/100 seconds
              );
#endif                                                             //~v022I~
#endif	//ifdef DOS else                                           //~v027I~
//*called status
   udmphdr.UDMPaddrparm=addr;
   udmphdr.UDMPlenparm=len;
//* copy title
   strncpy(udmphdr.UDMPtitle,title,sizeof(udmphdr.UDMPtitle));
//****************
//*hdr write     *
//****************
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053R~
        if (wdumprec(Ppurr,&udmphdr,sizeof(udmphdr)))              //~v053I~
    #else                       //not DPMI                         //~v053R~
    if (wdumprec(Pfile,&udmphdr,(ULONG)sizeof(udmphdr)))           //~v027I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v027I~
    if (wdumprec(Ppurr,&udmphdr,sizeof(udmphdr)))
#endif	//ifdef DOS else                                           //~v027I~
		return 8;
//****************
//*data write    *
//****************
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053I~
        if (wdumprec(Ppurr,addr,(int)len))                         //~v053I~
    #else                       //not DPMI                         //~v053I~
    if (wdumprec(Pfile,addr,len))                                  //~v027I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v027I~
    if (wdumprec(Ppurr,addr,(int)len))
#endif	//ifdef DOS else                                           //~v027I~
		return 8;
//****************
//*trailer write *
//****************
    if (udmphdr.UDMPreclen!=(sizeof(udmphdr)+len)) //up to boundary
    #ifdef DOS                                                     //~v053R~
    #ifdef DPMI					//DPMI version                     //~v053I~
          if (wdumprec(Ppurr,trailer,(int)(udmphdr.UDMPreclen-(sizeof(udmphdr)+len))))//~v053I~
    #else                       //not DPMI                         //~v053I~
      if (wdumprec(Pfile,trailer,(ULONG)(udmphdr.UDMPreclen-(sizeof(udmphdr)+len))))//~v027I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v027I~
      if (wdumprec(Ppurr,trailer,(int)(udmphdr.UDMPreclen-(sizeof(udmphdr)+len))))
#endif	//ifdef DOS else                                           //~v027I~
		return 8;

  } // endswitch by reqid

  return 0;

}//uehio

//**********************************************
//*write dump record
//*parm 1:PUEXREGREC for OS/2,file name for DOS                    //~v027R~
//**********************************************
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053I~
        APIRET wdumprec(PUEXREGREC Ppurr,PVOID Paddr,int Plen)     //~v053I~
    #else                       //not DPMI                         //~v053I~
int    wdumprec(char *Pfile,PVOID Paddr,ULONG Plen)                //~v027R~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v027I~
APIRET wdumprec(PUEXREGREC Ppurr,PVOID Paddr,int Plen)
#endif                                                             //~v027I~
{
	APIRET apiret;
#ifdef DOS                                                         //~v027M~
    #ifdef DPMI					//DPMI version                     //~v053I~
    	ULONG writelen;                                            //~v053I~
    #else                       //not DPMI                         //~v053I~
#define WRTSZ 	       0x8000                                      //~v027M~
    char *pc;                                                      //~v027M~
    size_t reqctr,outctr;                                          //~v027M~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v027M~
	ULONG writelen;	
#endif                                                             //~v027I~
//***************:
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053I~
        writelen=fwrite(Paddr,           /*input:output area*/     //~v053I~
        				1,					//size                 //~v053I~
                        (ULONG)Plen,       /*input:reclen */       //~v053I~
        				Ppurr->UERGdumpfh);/*input:file handle*/   //~v053I~
    	if (writelen!=(ULONG)Plen)                                 //~v053I~
        {                                                          //~v107I~
        	apiret=errno;                                          //~v053I~
            if (!apiret)                                           //~v107I~
                apiret=-1;                                         //~v107I~
        }                                                          //~v107I~
    	else                                                       //~v053I~
        	apiret=0;                                              //~v053I~
    #else                       //not DPMI                         //~v053I~
//printf("addr=%08lx,len=%08lx\n",Paddr,Plen);//@@@@               //~v027R~
    if (Plen>>20)       //dos is 20 bit addr                       //~v027I~
        uerrexit("dos dump:too large request length(x'%08lx' from x'%04x:%04x')",0,//~v027R~
			Plen,FP_SEG(Paddr),FP_OFF(Paddr));                     //~v027R~
    reqctr=(size_t)(Plen>>16);    	//by 64k                       //~v027I~
    reqctr<<=1;          	//by 32k                               //~v027I~
    if (reqctr)                                                    //~v027I~
	    outctr=fwrite(Paddr,WRTSZ,reqctr,Sfh);                     //~v027R~
	else                                                           //~v027I~
    	outctr=0;                                                  //~v027I~
    if (outctr==reqctr)                                            //~v027I~
    {                                                              //~v027I~
	    reqctr>>=1;          	//by 64k                           //~v027I~
    	pc=Paddr;                                                  //~v027I~
    	FP_SEG(pc)=FP_SEG(pc)+(size_t)(reqctr<<(16-4));            //~v027I~
	    reqctr=(size_t)(Plen&0x0000ffff);	//in 64k segment       //~v027I~
        outctr=fwrite(pc,1,reqctr,Sfh);                            //~v037R~
    }                                                              //~v027I~
    if (outctr!=reqctr)                                            //~v027R~
    	apiret=errno;                                              //~v027I~
	else                                                           //~v027I~
    	apiret=0;                                                  //~v027I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v027I~
#ifdef W32                                                         //~v022I~
//  printf("wdumprec addr=%08x,len=%08x\n",Paddr,Plen);            //~v034R~
    writelen=fwrite(Paddr,           /*input:output area*/         //~v034R~
    				1,					//size                     //~v034R~
                    (ULONG)Plen,       /*input:reclen */           //~v034R~
    				Ppurr->UERGdumpfh);/*input:file handle*/       //~v034R~
//  printf("wdumprec after write,writelen=%08x\n",writelen);       //~v034R~
	if (writelen!=(ULONG)Plen)                                     //~v033R~
    	apiret=errno;                                              //~v022I~
	else                                                           //~v022I~
    	apiret=0;                                                  //~v022I~
#else                                                              //~v022I~
	apiret=DosWrite((HFILE)Ppurr->UERGdumpfh,/*input:file handle*/
                     Paddr,           /*input:output area*/
                     (ULONG)Plen,            /*input:reclen */   
                     &writelen) ;             /*output:written len*/
#endif                                                             //~v022I~
#endif	//ifdef DOS else                                           //~v027I~
    if (apiret)
    {          
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053I~
    	Ppurr->UERGflag|= UERGFDUMPERR;                            //~v053I~
    #else                       //not DPMI                         //~v053I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v027I~
      Ppurr->UERGflag|= UERGFDUMPERR;
#endif	//ifdef DOS else                                           //~v027I~
      uerrmsg("dumpfile(%s) write err,rc=%d",                      //~v234R~
				"ダンプ(%s)出力エラー,rc=%d",
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053I~
				Ppurr->UERGdumpfn,apiret);                         //~v053I~
    #else                       //not DPMI                         //~v053I~
				Pfile,apiret);                                     //~v027I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v027I~
				Ppurr->UERGdumpfn,apiret);
#endif	//ifdef DOS else                                           //~v027I~
      return apiret;
    } /*r.c err*/   
	return 0;
}//wdumprec
                                                                   //~v027I~
//#ifdef DOS                                                       //~v106R~
//#else                                                            //~v106R~
//                                                                 //~v106R~
//#ifdef W32                                                       //~v106R~
//#else                                                            //~v106R~
#if defined(OS2) || defined(DPMI)                                  //~v106I~
//*****************************************************************//~v102I~
//* dump malloc page from alloc map tbl                            //~v102I~
//*parm:none                                                       //~v102I~
//*ret :rc 4 if ioerr                                              //~v102I~
//*****************************************************************//~v102I~
int uehdumpmapage(PUEXREGREC Ppurr)                                //~v102R~
{                                                                  //~v102I~
	UALLOCD *puad;                                                 //~v102I~
    int ii;                                                        //~v102I~
    UCHAR *pagemap,*pagemapend;                                    //~v102I~
    UCHAR *pageaddr,*saddr;                                        //~v102R~
    UINT ubyte;                                                    //~v102I~
#ifdef DPMI                                                        //~v106I~
//  #define HEAPUNITSZ 0x10000	//64k                              //~v119R~
    #define HEAPUNITSZ 0x1000	//4k                               //~v119I~
    int jj;                                                        //~v119I~
#else                                                              //~v106I~
    #define HEAPUNITSZ 0x1000	//4k                               //~v106I~
#endif                                                             //~v106I~
//***********************                                          //~v102I~
  	puad=ugetallocdata();                                          //~v102I~
  	pagemap=puad->pagemap;                                         //~v102I~
#ifdef DPMI                                                        //~v119I~
  	pagemapend=pagemap+UALLOC_PAGEMAPSZ_L;                         //~v119I~
#else                                                              //~v119I~
  	pagemapend=pagemap+puad->pagemapsz;                            //~v102I~
#endif                                                             //~v119I~
UTRACEP("pagemap=%08x,end=%08x\n",pagemap,pagemapend);             //~v167I~
UTRACED("pagemap",pagemap,puad->pagemapsz);                        //~v167I~
    if (!pagemap)                                                  //~v102I~
    	return 0;                                                  //~v102R~
#ifdef DPMI                                                        //~v119I~
	pageaddr=0;                                                    //~v119I~
  for (jj=0;jj<2;jj++)                                             //~v119I~
  {                                                                //~v119I~
	for (saddr=0;                                                  //~v119I~
#else                                                              //~v119I~
	for (saddr=0,pageaddr=0;                                       //~v102R~
#endif                                                             //~v119I~
			pagemap<pagemapend;                                    //~v102I~
//  			pagemap++,pageaddr+=(4096*8))                      //~v106R~
    			pagemap++,pageaddr+=(HEAPUNITSZ*8))                //~v106I~
  	{                                                              //~v102I~
    	ubyte=(UINT)*pagemap;                                      //~v102I~
    	if (!ubyte)	//no alloc data continuing                     //~v102I~
        	if (!saddr)                                            //~v102I~
        		continue;                                          //~v102R~
			else                                                   //~v102I~
            {                                                      //~v102I~
                if (uehdumpmapagesub(Ppurr,saddr,pageaddr))        //~v102R~
            		return 4;                                      //~v102I~
                saddr=0;	                                       //~v102I~
			}                                                      //~v102I~
		else	//alloc page in 32k                                //~v102I~
            for (ii=0;ii<8;ii++)                                   //~v102I~
            {                                                      //~v102I~
                ubyte<<=1;                                         //~v102I~
                if (ubyte&0x100)    //alloc page                   //~v102I~
                {                                                  //~v102I~
                    if (!saddr)     //first alloc page             //~v102I~
//                      saddr=pageaddr+ii*4096;                    //~v106R~
                        saddr=pageaddr+ii*HEAPUNITSZ;              //~v106I~
                }                                                  //~v102I~
                else                //not alloc page               //~v102I~
                    if (saddr)                                     //~v102I~
                    {                                              //~v102I~
//  	                if (uehdumpmapagesub(Ppurr,saddr,pageaddr+ii*4096))//~v106R~
    	                if (uehdumpmapagesub(Ppurr,saddr,pageaddr+ii*HEAPUNITSZ))//~v106I~
		            		return 4;                              //~v102I~
                        saddr=0;                                   //~v102R~
					}                                              //~v102I~
            }//8 bit                                               //~v102I~
	}//pagemaptbl                                                  //~v102I~
#ifdef DPMI                                                        //~v119I~
	pageaddr=(UCHAR*)UALLOC_PAGEMAPRANGE_H;	//above this line      //~v119R~
  	pagemapend=pagemap+UALLOC_PAGEMAPSZ_H;                         //~v119R~
  }//jj                                                            //~v119I~
#endif                                                             //~v119I~
	return 0;                                                      //~v102R~
}//uehdumpmapage        //malloc page dump                         //~v102I~
//*****************************************************************//~v102I~
//* dump malloc page sub                                           //~v102I~
//*parm1:purr                                                      //~v102R~
//*parm2:start addr                                                //~v102I~
//*parm3:next  addr                                                //~v102R~
//*retrn:4 if ioerr                                                //~v102I~
//*****************************************************************//~v102I~
int  uehdumpmapagesub(PUEXREGREC Ppurr,char *Psaddr,char *Peaddr)  //~v102R~
{                                                                  //~v102I~
	ULONG len;                                                     //~v102I~
    ULONG attr;                                                    //~v102R~
    APIRET apiret;                                                 //~v102I~
#ifdef DPMI                                                        //~v106I~
//        long cslim,dslim,sslim,dsbase;//@@@@test                 //~v119R~
//        __dpmi_meminfo _info;         //@@@@test                 //~v119R~
#endif                                                             //~v106I~
//***********************                                          //~v102I~
//#ifdef DPMI                                                      //~v119R~
//        cslim=__dpmi_get_segment_limit(_my_cs())+1; //@@@@test   //~v119R~
//        dslim=__dpmi_get_segment_limit(_my_ds())+1; //@@@@test   //~v119R~
//        sslim=__dpmi_get_segment_limit(_my_ss())+1; //@@@@test   //~v119R~
//        __dpmi_get_segment_base_address(_my_ds(),&dsbase);//@@@@test//~v119R~
//    _info.size=(int)Peaddr-(int)Psaddr;                          //~v119R~
//    _info.address=dsbase+Psaddr;                                 //~v119R~
//    apiret=__dpmi_lock_linear_region(&_info);                    //~v119R~
//    _info.address=Psaddr;                                        //~v119R~
//    apiret=__dpmi_lock_linear_region(&_info);                    //~v119R~
//#endif                                                           //~v119R~
	len=(UINT)Peaddr-(UINT)Psaddr;                                 //~v102R~
UTRACEP("before memchk addr=%08x,len=%08x \n",Psaddr,len);         //~v167I~
	apiret=umemchk((ULONG)Psaddr,&len,&attr); //alocated chk       //~v102R~
UTRACEP("after memchk,len=%08x rc=%d\n",len,apiret);               //~v167I~
#ifdef DPMI                                                        //~v106I~
	if (apiret<4)           //fully or partialy ok                 //~v106I~
#else                                                              //~v106I~
    #ifdef W32                                                     //~v173I~
	if (apiret<4)           //fully or partialy ok                 //~v173I~
    #else                                                          //~v173I~
	if (!apiret)            //valid addr                           //~v102R~
	#endif                                                         //~v173I~
#endif                                                             //~v106I~
UTRACEP("pagemapsub addr=%08x,len=%08x\n",Psaddr,len);             //~v167I~
       	if (uehio(DMP_WRITE,Ppurr,(PVOID)UDMPID_HEAP,(PVOID)Psaddr,len))//~v102R~
           	return 4;                                              //~v102R~
UTRACEP("pagemapsub ret\n");                                       //~v167I~
	return 0;                                                      //~v102I~
}//uehdumpmapagesub                                                //~v102R~
#endif                                                             //~v106I~
                                                                   //~v102I~
#ifdef DOS                                                         //~v106I~
#else                                                              //~v106I~
                                                                   //~v106I~
#ifdef W32                                                         //~v106I~
#else                                                              //~v106I~
////********************************                               //~v102R~
////* inital malloc area addr get  *                               //~v102R~
////*parm Ppurr                                                    //~v102R~
////********************************                               //~v102R~
//void rsvmalloc(PUEXREGREC Ppurr)                                 //~v102R~
//{                                                                //~v102R~
//static  ULONG allocunit=0x000ffff0; //alloc unit is 1mb          //~v102R~
//    ULONG i,j,k,l,totalheap;                                     //~v102R~
//    APIRET apiret;                                               //~v102R~
////***********************                                        //~v102R~
//      if ((i=(ULONG)malloc(1))!=0)  //try malloc                 //~v102R~
//      {                                                          //~v102R~
//        free((void*)i);                                          //~v102R~
//        i&=0xfffff000;    //page boundary                        //~v102R~
//        for (j=0;j<16;j++) //until 64kb                          //~v102R~
//        {                                                        //~v102R~
//          l=1; //chk length                                      //~v102R~
//          apiret=umemchk(i,&l,&k); //alocated chk                //~v102R~
//          if (apiret)                                            //~v102R~
//            break; //invalid addr                                //~v102R~
//          if ( !(k&PAG_COMMIT) || (k&PAG_GUARD) )//not commited or guard//~v102R~
//            break;                                               //~v102R~
//          if ( k&PAG_BASE ) //first page of allocated            //~v102R~
//            break;                                               //~v102R~
//          i-=4096; //previous page                               //~v102R~
//        }//64kb                                                  //~v102R~
//        if ( !apiret && k&PAG_BASE ) //base addr found           //~v102R~
//        {                                                        //~v102R~
//          l=0x00010000;//64k                                     //~v102R~
//          umemchk(i,&l,&k); //confirm len=64k                    //~v102R~
//          uaddpblock(Ppurr,UDMPID_HEAP,(PVOID)i,l);              //~v102R~
//        }                                                        //~v102R~
//      }//malloc ok                                               //~v102R~
////********************************                               //~v102R~
////* inital heap allocation       *                               //~v102R~
////********************************                               //~v102R~
//    totalheap=(ULONG)Ppurr->UERGheapsize*0xfff0;//parm unit is 64kb//~v102R~
//    while(totalheap)                                             //~v102R~
//    {                                                            //~v102R~
//        k=min(totalheap,allocunit);                              //~v102R~
//        j=(ULONG)malloc(k);  //1024k size malloc                 //~v102R~
//        if (!j)                                                  //~v102R~
//          break;  //alloc failed                                 //~v102R~
//                                                                 //~v102R~
//        uaddpblock(Ppurr,UDMPID_HEAP,(PVOID)(j-16),k+16); //1024kb//~v102R~
//        totalheap-=k;                                            //~v102R~
//        free((PVOID)j);                                          //~v102R~
//      }                                                          //~v102R~
//    return;                                                      //~v102R~
//}//rsvmalloc                                                     //~v102R~
                                                                   //~v022I~
#endif                                                             //~v022I~
                                                                   //~v022I~
//********************************************************************
//* 関数名     : uaddpblock
//* INPUT      :                                                     *
//*     p1:memory title comment                                      *
//*     p2:memory addr                                               *
//*     p3:memory length                                             *
//* OUTPUT     : UPBLOCK
//* RETURN     : registered length                                   *
//*              if -1 ,UPBLOCK overflow                             *
//* 機能概要   : registerate memory on dump memory table             *
//********************************************************************
ULONG uaddpblock(PUEXREGREC Ppurr,PSZ title,PVOID addr,ULONG len)

{
	ULONG  i;    //work index
	ULONG  size; //return length
	ULONG  attr; //for memchk 
	APIRET apiret;
	PUPBLOCK pupblock;
//  PTIB   ptib;       /*tib ptr*/                                 //~v022R~
//  PPIB   ppib;       /*pib ptr*/                                 //~v022R~
//***********************
UTRACEP("uaddblock re addr=%08x,len=%08x\n",addr,len);             //~v173I~
	if (!Spupblock)
	{
		Spupblock=calloc(1,UPBLOCKSZ);                          //~5111R~
		Spupblock->UPBLmaxcount=MAXUPBLENTRY;
	}
	pupblock=Spupblock;

//***************************
//* get lock                *
//***************************
#ifdef W32		//no need alloc chk                                //~v022I~
#else                                                              //~v022I~
	if (!(pupblock->UPBLflag & UPBLFCRESEM)) //firsttime
	{
		uehsem(MTX_CREATE,&pupblock->UPBLmtxsem);
		pupblock->UPBLflag |= UPBLFCRESEM; //created
	}
	uehsem(MTX_REQUEST,&pupblock->UPBLmtxsem);
#endif                                                             //~v022I~


//***************************
//* add entry                *
//***************************
  if ( pupblock->UPBLusecount<pupblock->UPBLmaxcount )
  {
//***************************
//* parm validity chk       *
//***************************
    size=len; //updated by memchk
//  apiret=umemchk((ULONG)addr,&size,&attr); //alocated chk        //+v6hhR~
    apiret=umemchk((ULPTR)addr,&size,&attr); //alocated chk        //+v6hhI~
    if ( apiret              //invalid addr
#ifdef W32		//no need alloc chk                                //~v022I~
       && apiret>=4                                                //~v173I~
#else                                                              //~v022I~
       || !(attr&PAG_BASE)                                         //~v022R~
#endif                                                             //~v022I~
	)  //not start addr                                            //~v022I~
    uerrexit("memchk failed,rc=%d",0,apiret);
     
UTRACEP("uaddblock addr=%08x,len=%08x\n",addr,size);               //~v173I~
//***************************
//* register memory block   *
//***************************
    i=pupblock->UPBLusecount;//next entry index
    strncpy((UCHAR*)(pupblock->UPBLentry[i].UPBLtitle),title,
            sizeof(pupblock->UPBLentry[i].UPBLtitle));
    pupblock->UPBLentry[i].UPBLaddr =addr; //memoryaddr
    pupblock->UPBLentry[i].UPBLlen  =size; //memoryaddr
//  DosGetInfoBlocks(&ptib,&ppib);         //get tib addr          //~v022R~
    pupblock->UPBLentry[i].UPBLpurr=(PVOID)Ppurr;
    pupblock->UPBLusecount=i+1;           //entry used
  }
  else
    size=0xffffffff;

//***************************
//* free lock               *
//***************************
#ifdef W32		//no need alloc chk                                //~v022I~
#else                                                              //~v022I~
	uehsem(MTX_RELEASE,&pupblock->UPBLmtxsem);
#endif                                                             //~v022I~

//***************************
//* return                  *
//***************************
  return size;
}

//********************************************************************
//*uehdumpterm
//* free pblock
//* parm :none
//* retrn:none
//********************************************************************
void uehdumpterm(void)
{
	if (Spupblock)
	{
		free(Spupblock);                                        //~5111R~
		Spupblock=0;
	}
	return;
}//uehdumpterm

#ifdef W32		//no need alloc chk                                //~v022I~
#else                                                              //~v022I~
                                                                   //~v022I~
//********************************************************************
//* 関数名     : uehsem                                              *
//* INPUT      :                                                     *
//*     p1:requestid  MXT_CREATE/MTX_REQUEST/MTX_RELEASE             *
//*     p2:Purr
//* OUTPUT     : none
//* RETURN     : none                                                *
//* 機能概要   : semapho handle                                      *
//********************************************************************
void   uehsem(ULONG reqid,HMTX *Pphmtx)

{  
   APIRET apiret;

   switch (reqid)
   {
   case MTX_CREATE :                //create
     apiret=DosCreateMutexSem(NULL,           //unnamed semaphore
                              Pphmtx,			//output:hmtx
                              0L,             //flag,private sem
                              FALSE);         //initialy unown
	   if (apiret)
    	 uerrexit("DosCreateMutexSem failed,rc=%d",0,apiret);
     break;
   case MTX_REQUEST:                //request
     apiret=DosRequestMutexSem(*Pphmtx,//input:hmtx
                               (ULONG)SEM_INDEFINITE_WAIT); //wait until free
	   if (apiret)
    	 uerrexit("DosRequestMutexSem failed,rc=%d",0,apiret);
     break;
   case MTX_RELEASE:                //release
     apiret=DosReleaseMutexSem(*Pphmtx);//input:hmtx
     if (apiret && apiret!=ERROR_NOT_OWNER)//ok or already freeed
    	 uerrexit("DosReleaseMutexSem failed,rc=%d",0,apiret);
     break;
   } // endswitch by reqid
	return;
}
#endif                                                             //~v022I~
#endif      //else DOS                                             //~v027I~
