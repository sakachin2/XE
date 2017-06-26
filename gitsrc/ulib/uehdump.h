//CID://+v5b4R~:                                                   //+v5b4R~
//**************************************************************
//* uehdump.h                                                      //~v172R~
//**************************************************************
//v5b4:040124 (WIN)new memory dump logic unsq VirtualQuery func    //+v5b4I~
//v172:980501 (BUG)memchk fail for process heap,use HeapWalk       //~v172I~
//                 because intermediate uncommitted space exist    //~v172I~
//v102:971010 os2 new malloc dump logic                            //~v102I~
//            uehdump.c:dump allocated page                        //~v102I~
//v070:970401:(DOS)print seg reg when dump                         //~v070I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -ehception handle by signal                          //~v053I~
//v034:961008:VisualC++ support(identify by (_MSC_VER>=800))       //~v034I~
//v032:960923:set title line(*) id for dump print pgm title        //~v032I~
//v027:960917:dos dump sub                                         //~v027I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//**************************************************************   //~v022I~
#ifdef W32                                                         //~v172I~
#define W32NEWDUMP      //win use new memory allocation chk        //+v5b4M~
#ifndef W32NEWDUMP      //win use new memory allocation chk        //+v5b4I~
//*** WindowsNT heap header for region *** inspected from HeapWalk logic//~v172I~
typedef  struct _UNTHEAPH {                                        //~v172R~
         UCHAR  UNTHHflg[4];            /*type??*/                 //~v172R~
#define UNTHHRGNHDR       0x07          /*region header id*/       //~v172I~
         ULONG  UNTHHrsv1;           /*??*/                        //~v172R~
         ULONG  UNTHHid;             /*vaid chk*/                  //~v172I~
#define UNTHHHDRID        0xffeeffee    /*region header id*/       //~v172R~
         ULONG  UNTHHrsv12[2];           /*??*/                    //~v172I~
         ULONG  UNTHHucsize;            /*uncommitted size*/       //~v172I~
         ULONG  UNTHHrsv2;              /*??*/                     //~v172I~
         int    UNTHHallocpage;         /*allocated page number*/  //~v172R~
         void  *UNTHHfirstblock;        /*first block in region*/  //~v172R~
         void  *UNTHHlastblock;         /*last block in region*/   //~v172R~
         int    UNTHHuncommittedpage;   /*uncommitted page number*///~v172R~
         ULONG  UNTHHrsv3[3];          /*??*/                      //~v172R~
				} UNTHEAPH,*PUNTHEAPH;                             //~v172R~
#endif //! W32NEWDUMP      //win use new memory allocation chk     //+v5b4I~
#endif                                                             //~v172I~
//**************************************************************   //~v172I~
#define DUMPTITLEID "*="		//dump title line                  //~v032R~
//* dump record format *****************************
//typedef  _Packed  struct _UDMPHDR {   //bcc has no _Packed       //~v022R~
typedef  struct _UDMPHDR {                                         //~v022I~
         ULONG  UDMPreclen;         /*record len*/
         UCHAR  UDMPreceyec[8];     /*eye catcher "++++++++"*/
#define  UDMPEYECID  "++++++++"     //
         ULONG  UDMPthreadid;       /*taskid*/
         ULONG  UDMPcurrentdate;    /*dump  time stamp yyyymmdd*/
         ULONG  UDMPcurrenttime;    /*dump  time stamp hhmmssth*/
         void  *UDMPaddrparm;       /*dump  data start addr     */
         ULONG  UDMPlenparm;        /*dump data len      */
         UCHAR  UDMPtitle[16];      /*title comment*/
#define  UDMPID_ABINFO "ABEND SIMPTON   "
#define  UDMPID_REPREC "ABEND REPORT    " 
#define  UDMPID_CTXREC "CONTEXT RECORD  " 
#define  UDMPID_REGREC "REGISTRATION REC" 
                                                                   //~v053I~
#ifdef DPMI					//DPMI version                         //~v053I~
#define  UDMPID_STACK   "STACK SEG       "                         //~v053R~
#define  UDMPID_DATA    "DATA SEG        "                         //~v053R~
#define  UDMPID_BSSDATA "BSS+COMMON      "                         //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32                                                         //~v034R~
#define  UDMPID_STACK  "STACK SEG       "                          //~v034I~
#define  UDMPID_DATA   "DATA SEG        "                          //~v034I~
#else                                                      //+v034I~//~v034I~
#define  UDMPID_STACK  "(DATA+)STACK SEG" 
#endif                                                     //+v034I~//~v034I~
#endif                      //DPMI or not                          //~v053I~
                                                                   //~v053I~
#define  UDMPID_UTRACE "UTRACE BUFFER   " 
                                                                   //~v053I~
#ifdef DPMI					//DPMI version                         //~v053I~
#define  UDMPID_HEAP   "MALLOC HEAP     "                          //~v053I~
#else                                                              //~v053I~
#ifdef W32                                                         //~v034I~
#define  UDMPID_HEAP   "HEAP            "                          //~v034I~
#else                                                      //+v034I~//~v034I~
#define  UDMPID_HEAP   "MALLOC HEAP     " 
#endif                                                     //+v034I~//~v034I~
#endif                                                             //~v053I~
                                                                   //~v053I~
#define  UDMPID_EPATBL "LINK EPA TABLE  " 
#define  UDMPID_OTHER  "OTHER           " 
#define  UDMPID_DOSMEM "DOS CONVENTIONAL"                          //~v027I~
} UDMPHDR;

typedef UDMPHDR* PUDMPHDR;
                                                                   //~v027I~
#ifdef DOS                                                         //~v027M~
                                                                   //~v027I~
#ifdef DPMI					//DPMI version                         //~v053I~
//*************************************************************    //~v053I~
void uehdump(PEXCEPTIONREPORTRECORD pexreprec,                     //~v053I~
               PUEXREGREC Ppurr,                                   //~v053I~
               PCONTEXTRECORD pctxrec,                             //~v053I~
               UCHAR* msgwk,                                       //~v053I~
               PEPATBL Ppepatbl);                                  //~v053I~
                                                                   //~v053I~
#else                       //not DPMI                             //~v053I~
typedef  struct _UDOSCON {                                         //~v027I~
         void  *UDCNepamain;        //main epa                     //~v027I~
         void  *UDCNbpsavearea;     //last BP save area            //~v027R~
         void  *UDCNenddata;	    //end of DATA seg              //~v070R~
         USHORT UDCNds0;            //first DS segment             //~v070R~
         USHORT UDCNds;             //DS segment at uehdump        //~v070I~
         USHORT UDCNss;             //SS segment at uehdump        //~v070R~
         USHORT UDCNcs;             //CS segment at uehdump        //~v070I~
} UDOSCON;                                                         //~v027I~
                                                                   //~v027I~
typedef UDOSCON* PUDOSCON;                                         //~v027I~
                                                                   //~v027I~
//**************************************************************** //~v027I~
void uehdump(char *Pfile,char **Pabinfmsg,PEPATBL Ppepatbl);       //~v027R~
#endif                      //DPMI or not                          //~v053I~
                                                                   //~v027I~
#else   //else DOS                                                 //~v027M~
                                                                   //~v027M~
//*************************************************************
void uehdump(PEXCEPTIONREPORTRECORD pexreprec,
               PUEXREGREC Ppurr,
               PCONTEXTRECORD pctxrec,
               UCHAR* msgwk,
               PEPATBL Ppepatbl);

//********************************************************************
ULONG uaddpblock(PUEXREGREC Ppurr,PSZ title,PVOID addr,ULONG len);

#ifdef W32                                                         //~v022R~
#else                                                              //~v022I~
                                                                   //~v022I~
////********************************                               //~v102R~
////* inital malloc area addr get  *                               //~v102R~
////*parm Ppurr                                                    //~v102R~
////********************************                               //~v102R~
//void rsvmalloc(PUEXREGREC Ppurr);                                //~v102R~

#endif                                                             //~v022I~
                                                                   //~v022I~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
                                                                   //~v022I~
//********************************************************************
#define MTX_CREATE    0         //semaphore create reqid
#define MTX_REQUEST   1         //semaphore request reqid
#define MTX_RELEASE   2         //semaphore release reqid
#define MTX_RELEASEUT 3         //utrace semaphore release reqid
void   uehsem(ULONG reqid,HMTX *Pphmtx);
                                                                   //~v022I~
#endif                                                             //~v022I~

//********************************************************************
void uehdumpterm(void);
#endif      //else DOS                                             //~v027I~
