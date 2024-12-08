//*CID://+v6xiR~:                             update#=   46;       //+v6xiR~
//*******************************************************
//v6xi:150115 conversion warning                                   //+v6xiI~
//v6xh:150115 (BUG)invalid dword calc;on 64bit linux long/ulong is 64bit,so DWADD dose not overflow//~v6xhI~
//v5k2:061227 (LNX/WIN)bc_dweditnum64(long long int edit func) add //~v5k2I~
//v5dx:040815 BC cmd:support dw/up                                 //~v5dxI~
//v5dr:040627 BC cmd:accept minus value                            //~v5drI~
//v5dj:040612 support dword underpoint "+"(add)/"-" operation      //~v5djI~
//v5ag:040106 prevday support for calc nextday                     //~v5agI~
//v59s:031221 calc next day                                        //~v59sI~
//v50k:010407 host time support                                    //~v50kM~
//v50g:010402 calc:long decimal support                            //~v50gI~
//v50f:010402 TOD conversion                                       //~v50fI~
//v50e:010402 double word calc support                             //~v50eI~
//*******************************************************
typedef struct _UCALC_TIME                                         //~v50eI~
        {int year,month,day,hour,min,sec,milsec;} UCALC_TIME,*PUCALC_TIME;//~v50eI~
//*******************************************************          //~v50eI~
#ifdef ULIB64 //lnx 64bit:long is 64 bit                           //~v6xhI~
#define DWORD_LSHIFT(high,low)         \
          (high=(UINT4)(((UINT4)high<<1)+((low & HIGHBIT)!=0)),\
           low=(UINT4)((UINT4)low<<1))                             //~v6xhR~
#else                                                              //~v6xhI~
//#define DWORD_LSHIFT(high,low)                                   //+v6xiR~
//          (high=(LONG)(((ULONG)high<<1)+((low & HIGHBIT)!=0)),   //+v6xiR~
//           low=(LONG)((ULONG)low<<1))                            //+v6xiR~
////        (high=(high<<1)+((low & HIGHBIT)!=0),low<<=1)          //+v6xiR~
#define DWORD_LSHIFT(high,low)         \
          (high=(LONG)(((ULONG)high<<1)+(((ULONG)low & HIGHBIT)!=0)),\
           low=(LONG)((ULONG)low<<1))                              //+v6xiI~
#endif                                                             //~v6xhI~
#ifdef ULIB64 //lnx 64bit:long is 64 bit                           //~v6xhI~
#define DWORD_RSHIFT(high,low)         \
        (low=(UINT4)(((UINT4)low>>1)|((high & 1)?HIGHBIT:0)),\
        high=(UINT4)(((UINT4)high)>>1))                            //~v6xhR~
#else                                                              //~v6xhI~
//#define DWORD_RSHIFT(high,low)                                   //+v6xiR~
//        (low=(LONG)(((ULONG)low>>1)|((high & 1)?HIGHBIT:0)),     //+v6xiR~
//        high=(LONG)(((ULONG)high)>>1))                           //+v6xiR~
////      (low=(low>>1)|((high & 1)?HIGHBIT:0),high>>=1)           //+v6xiR~
#define DWORD_RSHIFT(high,low)         \
        (low=(LONG)(((ULONG)low>>1)|(((ULONG)high & 1)?HIGHBIT:0)),\
        high=(LONG)(((ULONG)high)>>1))                             //+v6xiI~
#endif                                                             //~v6xhI~
#ifdef ULIB64 //lnx 64bit:long is 64 bit                           //~v6xhI~
#define DWORD_COMP(high1,low1,high2,low2)         \
        (((INT4)(high1)>(INT4)(high2))?1:(((INT4)(high1)<(INT4)high2)?-1:\
        (((UINT4)(low1)>(UINT4)(low2))?1:(((UINT4)(low1)<(UINT4)(low2))?-1:0))))//~v6xhM~
#else                                                              //~v6xhI~
#define DWORD_COMP(high1,low1,high2,low2)         \
        (((long)(high1)>(long)(high2))?1:(((long)(high1)<(long)high2)?-1:\
        (((unsigned long)(low1)>(unsigned long)(low2))?1:(((unsigned long)(low1)<(unsigned long)(low2))?-1:0))))//~v6xhI~
//      ((high1>high2)?1:((high1<high2)?-1:((low1>low2)?1:((low1<low2)?-1:0))))//~v6xhI~
#endif                                                             //~v6xhI~
#ifdef ULIB64 //lnx 64bit:long is 64 bit                           //~v6xhI~
	#define DWORD_SUB(high1,low1,high2,low2)         \
        ( high1=(UINT4)((UINT4)high1-(UINT4)high2     \
                       -((UINT4)(low1)<(UINT4)low2)),\
          low1=(UINT4)((UINT4)low1-(UINT4)low2) )                  //~v6xhR~
#else                                                              //~v6xhI~
#define DWORD_SUB(high1,low1,high2,low2)         \
        (high1-=(LONG)(high2+((ULONG)(low1)<(ULONG)(low2))),\
		low1-=(LONG)low2)                                          //+v6xiR~
//      (high1-=high2+(low1<low2),low1-=low2)                      //~v6xhI~
#endif                                                             //~v6xhI~
#ifdef ULIB64 //lnx 64bit:long is 64 bit                           //~v6xhI~
	#define DWORD_ADD(high1,low1,high2,low2)         \
        ( high1=(UINT4)((UINT4)high1+(UINT4)high2   \
                       +((UINT4)low1>((UINT4)low1+(UINT4)low2))),\
          low1=(UINT4)((UINT4)low1+(UINT4)low2)  )                 //~v6xhR~
#else                                                              //~v6xhI~
//#define DWORD_ADD(high1,low1,high2,low2)                         //+v6xiR~
//        (high1+=(LONG)(high2+((ULONG)(low1)>(ULONG)(low1+low2))) //+v6xiR~
//        low1+=(LONG)low2)             /*//~v50eI~*/              //+v6xiR~
////      (high1+=high2+(low1>(low1+low2)),low1+=low2)             //+v6xiR~
#define DWORD_ADD(high1,low1,high2,low2)         \
        (high1+=(LONG)(high2+(LONG)((ULONG)low1>(ULONG)low1+(ULONG)low2)),\
        low1+=(LONG)low2)             /*//~v50eI~*/                //+v6xiI~
#endif                                                             //~v6xhI~
#ifdef ULIB64 //lnx 64bit:long is 64 bit                           //~v6xhI~
	#define DWORD_MINUS(high,low)         \
        (high=(INT4)(-(INT4)high-(low!=0)),\
        low=(INT4)(-(INT4)low))                                    //~v6xhI~
#else                                                              //~v6xhI~
#define DWORD_MINUS(high,low)         \
        (high=(LONG)(-high-(low!=0)),\
		low=-(LONG)low)                                            //~v6xhI~
#endif                                                             //~v6xhI~
//***************************************************************  //~v50eI~
int bc_getxdw(char *Pdata,long *Pvalue);                           //~v50eM~
//***************************************************************  //~v50eI~
//int bc_getld(char *Pdata,long *Pvalue);                          //~v5djR~
int bc_getld(int Popt,char *Pdata,long *Pvalue);                   //~v5djI~
#define GETLD_DWUP		0x01 //accept Dword underpoint             //~v5djI~
//***************************************************************  //~v50gI~
int bc_dwbinop(int Popt,int Pope,long *Popd1,long *Popd2);         //~v50eI~
//***************************************************************  //~v50eI~
int bc_edittod(UCHAR *Pout,long *Pvalue);                          //~v50fI~
//***************************************************************  //~v50fI~
#ifdef INT64SUPP                                                   //~v5k2I~
	int bc_dweditnum64(int Pfunctype,int Pconvtype,INT64 Pvalue,UCHAR *Pout);//~v5k2I~
#endif                                                             //~v5k2I~
//***************************************************************  //~v5k2I~
int bc_dweditnum(int Pfunctype,int Pconvtype,long *Pvalue,UCHAR *Pout);//~v50eI~
//***************************************************************  //~v50eI~
//int ucalc_dwmult(ULONG *Ppopd1,ULONG Popd2);                     //~v5drR~
int ucalc_dwmult(LONG *Ppopd1,LONG Popd2);                         //~v5drI~
//***************************************************************  //~v50eI~
//int ucalc_dwdiv(ULONG *Ppopd1,ULONG Popd2);                      //~v5drR~
int ucalc_dwdiv(LONG *Ppopd1,LONG Popd2);                          //~v5drI~
//***************************************************************  //~v50eI~
int ucalc_ltime(int Ptmtype,ULONG *Ptime,PUCALC_TIME Ppuct);       //~v50eI~
#define LTIME_PC      1                                            //~v50eI~
#define LTIME_UNIX    2                                            //~v50eI~
#define LTIME_HOST    3                                            //~v50eI~
//***************************************************************  //~v50gI~
//int ucalc_ld2dw(char *Pdecs,ULONG *Pdword);                      //~v5drR~
int ucalc_ld2dw(char *Pdecs,LONG *Pdword);                         //~v5drI~
//***************************************************************  //~v50gI~
//int ucalc_dw2ld(ULONG Pdwh,ULONG Pdwl,char *Pnumstr);            //+v6xiR~
int ucalc_dw2ld(LONG Pdwh,LONG Pdwl,char *Pnumstr);                //+v6xiI~
//***************************************************************  //~v50gI~
int ucalc_nsadd(char *Pnumstr1,char *Pnumstr2);                    //~v50gI~
//*******************************************************          //~v50kM~
int ucalc_ltime(int Ptmtype,ULONG *Ptime,PUCALC_TIME Ppuct);       //~v50kM~
//*******************************************************          //~v50kI~
int ucalc_getdate(int Pdays,int *Pdate);                           //~v50kI~
//*******************************************************          //~v59sR~
int ucalc_nextday(int Pdiff,int *Ppyear,int *Ppmonth,int *Ppday);  //~v5agR~
//*******************************************************          //~v5djI~
void ucalc_dwupinit(long *Pdwup);                                  //~v5djI~
//*******************************************************          //~v5djI~
//void ucalc_dwupset(long *Pdwup,long *Plv);                       //~v5drR~
void ucalc_dwupset(int Popt,long *Pdwup,long *Plv);                //~v5drI~
//*******************************************************          //~v5drI~
int bc_dword2word(int Popt,long *Pnumfmt,long *Poutnumfmt);        //~v5drM~
//*******************************************************          //~v5dxI~
int ucalcerrdwordovf(void);                                        //~v5dxI~
