//CID://+va79R~:        update#=      6                            //~va79R~
//*******************************************************          //~v66fI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v74n:070217 (BUG)join fail by oom if paste target region is one line because ETOL is done before split//~v74nI~
//v74h:070216 (BUG)C&P paste to region fail by join fail for margined file.//~v74hI~
//            (because if target is region,once cut region(join top and last) then split)//~v74hI~
//            delay join till after insert source line)            //~v74hI~
//v66f:051021 support standard mode cut & paste,assign Ctrl+v for stream insert//~v66fI~
//                     None   OpenBlock  ClosedBlock   OpenRegion ClosedRegion//~v66fI~
//            C+v    RgnIns   NoBlockErr BlockClearRep OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Ins  BlockIns NoBlockErr GetBlock+Ins  OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Rep  BlockRep NoBlockErr GetBlock+Rep  OpenRgnErr RgnDel+Ins//~v66fI~
//*******************************************************          //~va79I~
typedef struct _CBSTAT  {                                          //~va79I~
                            ULONG  CBSTstat;                       //~va79I~
#define CBST_V1SZ  sizeof(ULONG)                                   //~va79I~
                            UCHAR  CBSTcvname[MAX_CSNAMESZ];       //+va79R~
                            UCHAR  CBSTrsv[128];                   //~va79I~
                        } CBSTAT,*PCBSTAT;                         //~va79I~
#define CBSTATSZ sizeof(CBSTAT)                                    //~va79I~
//*******************************************************          //~v66fI~
int caperrregionmode(void);                                        //~v66fM~
//*******************************************************          //~v74hI~
//int capcutregion(PUCLIENTWE Ppcw,PULINEH *Ppplh1,PULINEH *Ppplh2,int Ppos1,int Ppos2);//~v74hR~
int capcutregion(int Popt,PUCLIENTWE Ppcw,PULINEH *Ppplh1,PULINEH *Ppplh2,int Ppos1,int Ppos2,int *Ppjoinrc);//~v74hI~
#define CCR_SKIPJOIN    0x01  //bypass join 1st and last plh after intermediate cut//~v74hI~
#define CCR_SPLIT       0x02  //dos split for later join for the one line region case//~v74nI~
//*******************************************************          //~v74hI~
int capclearregion(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2);//~v66fM~
//*******************************************************          //~v74hI~
int capstdpaste(PUCLIENTWE Ppcw,PULINEH Psortplh1,PULINEH Psortplh2,int Ppos1,int Ppos2,char Pstat1,char Pstat2);//~v66fR~
//*******************************************************          //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
//*******************************************************          //~va20I~
//ULONG capcbstatr(int Popt,PUCLIENTWE Ppcw);                        //~va20R~//~va79R~
ULONG capcbstatr(int Popt,PUCLIENTWE Ppcw,PCBSTAT Pcbsrec);        //~va79I~
#define CCBSTF_CPU8          0x01        //::cb status cpu8        //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
#define CCBSTF_CPEB          0x02        //::cb status cpeb        //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#define CCBSTF_HANDLEMASK    0x0700   //ebc converter handle(00->07)//~va79I~
#define CCBSTF_HANDLEMASK_SHIFT  8      //handle shift count       //~va79I~
#define CCBSTF_GETHANDLE(opt)  ((((opt) & CCBSTF_HANDLEMASK))>>CCBSTF_HANDLEMASK_SHIFT)//~va79I~
#define CCBSTF_SETHANDLE(handle)  (((handle)<<CCBSTF_HANDLEMASK_SHIFT) & CCBSTF_HANDLEMASK)//~va79I~
                                                                   //~va79I~
//*******************************************************          //~va20I~
int capcbstatw(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);             //~va20R~
//*******************************************************          //~va20I~
#endif                                                             //~va20I~
