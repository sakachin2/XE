//CID://+vba3R~:         update#     =1                            //~vba3R~
// ******************************************************************
// *: xedumpp.C                                         //~v1.4R~  //~vafcR~
// *: batch program:edit print attic dump file                     //~vafcR~
// *                    : main                                     //~vafcR~
// *              parm1 : input file spec                  
// *              parm2 : output file spec
// *              parm3 : form width option
// *               (default)"W"/"w":print 32 byte per line 48 line per page
// *                        "S"/"s":print 16 byte per line 58 line per page
// *                        "L"/"l":print 32 byte per line 58 line per page
// *              parm4 : max line no per page 
// *                      default 58 if wide mode
// *                      default 48 if single mode
// **********************************************/
// **********************************************/
//#define VER    "V1.h"        //version                           //~v10hR~
#define VER    "V2.2"        //version                             //~v10hI~//~van0R~
// **********************************************/                 //~v1.4I~
//vba3:170715 msvs2017 warning;(Windows:PTR:64bit,ULONG 32bit,HWND:64bit,size_t:64bit)//~vba3I~
//van0:131127 Assertion fails by %n on sprintf;                    //~van0I~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v10hI~
//v10h:990703 (BUG) virtual addr calc err of disas                 //~v10hI~
//v10g:981227 dump:caddr is another output parm(parm changed)      //~v10gI~
//v10f:v1.b:981223 dump virtual addr support                       //~v1.bI~
//v0i2:980501 skip dup data dump print v1.a                        //~v1.aR~
//*980411 v1.9 code disassemble                                    //~v1.7I~
// v1.8                                                            //~v1.7R~
//v0fu:971116 (BUG)sort sequence of dump addr for ff______(GCP);dumpp v1.8//~v1.7I~
// 	      970401:(DOS)print seg value                              //~v1.7I~
// 	 v093:970330:DPMI version                                      //~v1.7I~
// *961024 v1.6 W95 VC                                             //~v1.6I~
// *960930 (BUG)process terminate when datalen=0                   //~v1.5I~
// *960921 DOS dump support                                        //~v1.4I~
// *960814 win95 version                                           //~v1.3R~
// *941219 print continue even if read err
// *941218 dump dbcs chk
// *******************************************************************

#include <time.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <io.h>         //read
#include <fcntl.h>      //read

#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7I~
		#include <errno.h>      //read                             //~v1.7I~
    #else                       //not DPMI                         //~v1.7I~
    #endif                      //DPMI or not                      //~v1.7I~
	#include <stdarg.h>                                            //~v1.4I~
	#include <sys/types.h>                                         //~v1.4R~
	#include <sys/stat.h>                                          //~v1.4I~
	#include <dos.h>                                               //~v1.4I~
                                                                   //~v1.4I~
    #define FILE_BEGIN 		SEEK_SET                               //~v1.4I~
    #define FILE_CURRENT 	SEEK_CUR                               //~v1.4I~
    #define FILE_END	 	SEEK_END                               //~v1.4I~
#else                                                              //~v1.4I~
#ifdef W32                                                         //~v1.3R~
	#include <sys/stat.h>                                          //~v1.3R~
    #include <windows.h>                                           //~v1.3R~
#else                                                              //~v1.3R~
	#define __MIG_LIB__         //for read/fstat                   //~6817I~
    #define INCL_DOSFILEMGR     //Dos i/o                          //~6814I~
    #define INCL_DOSEXCEPTIONS  //c.b about exception handle       //~6814I~
    #define INCL_DOSSEMAPHORES//for DosCreate/Request/ReleaseMutexSem//~6814I~
    #include <os2.h>                                               //~6814I~
#endif                                                             //~v1.3R~
#endif  //ifdef DOS else                                           //~v1.4I~
                                                                   //~6817I~
                                                                   //~6814M~
#include <ulib.h>                                                  //~6814I~
#include <udbcschk.h>
                                                                   //~v1.4I~
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7I~
        #include <ueh.h>                                           //~v1.7I~
    #else                       //not DPMI                         //~v1.7I~
    #endif                      //DPMI or not                      //~v1.7I~
#else                                                              //~v1.4I~
#include <ueh.h>
#endif  //ifdef DOS else                                           //~v1.4I~
                                                                   //~v1.4I~
#include <ufuncmap.h>
#include <ufile.h>                                                 //~v1.3R~
#include <ufile2.h>                                                //~v1.3R~
#include <uehdump.h>                                               //~v1.3R~
#include <ustring.h>                                               //~v1.4I~
#include <ualloc.h>		//disas                                    //~v1.9R~
#include <uda.h>		//disas                                    //~v1.9I~
#include <uedit.h>  	//x2l                                      //~v1.bI~

//********************************************************************

#define PGMID  "XEDUMPP"      //program id                         //~v1.4R~
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI	    			//DPMI version                     //~v1.7R~
        #define IOBUFFSZ (0x00100000+sizeof(UDMPHDR))  //ioarea size 1MB//~v1.7I~
        #define MAXSORTREC (0x00010000/sizeof(SORTLIST)) //record count max//~v1.7I~
    #else                       //not DPMI                         //~v1.7R~
    #define IOBUFFSZ (0x8000+sizeof(UDMPHDR))  //ioarea size 1MB   //~v1.4I~
    #define MAXSORTREC (0x8000/sizeof(SORTLIST)) //record count max//~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4I~
#define IOBUFFSZ (0x00100000+sizeof(UDMPHDR))  //ioarea size 1MB
#define MAXSORTREC (0x00010000/sizeof(SORTLIST)) //record count max
#endif                                                             //~v1.4I~

#define MAXLINEW 48           //wide mode default line per page
#define MAXLINES 58           //single mode default line per page
#define OUTFILE  "PRN"        //default output file name
#define DEFAULTFORM 'W'       //default wide mode
#define LINEADDRPOS  0        //storage addr colomn
#define LINEHEXPOS   9        //hex dump start colomn
#define LINECHARPOSS 50       //single mode char dump start colomn
#define LINECHARPOSW 85       //wide   mode char dump start colomn
#define LINEWIDTHS   LINECHARPOSS+17 //single mode print line total colomn
#define LINEWIDTHW   LINECHARPOSW+33 //single mode print line total colomn
#define DUMPWIDTHS   16 //16 byte dump per line
#define DUMPWIDTHW   32 //32 byte dump per line

//*******************************************************************
typedef  struct _SORTLIST {
                             void*  sortaddr;//storage addr
                             UCHAR  sortdatetime[8];
                             long   sortpos ;//record offset
                          } SORTLIST;
typedef SORTLIST* PSORTLIST;

//***********

#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI		    		//DPMI version                     //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
void printdosctx(void);                                            //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#endif                                                             //~v1.4I~
                                                                   //~v1.9I~
#if  defined(DOS) && !defined(DPMI)	//native DOS                   //~v1.9I~
#else                                                              //~v1.9I~
	void printcode(void);                                          //~v1.9I~
#endif                                                             //~v1.9I~
                                                                   //~v1.4I~
int  addrcomp(const void*,const void*);
int  chkrtype(void);                                               //~v1.4R~
void putmsg(int,UCHAR*,...);         /*err msg display*/
long  readdmphdr(UINT origin,long offset);                         //~v1.4R~
long  readdata(void);
long  dumpio(UINT origin,long offset,long len,void* addr);         //~v1.4R~
void printdump(void*,ULONG,void*);
void printdmphdr(void);
void printabinf(void);
void putline(UCHAR*,UINT);                                         //~v1.4R~

//***********

static PUDMPHDR Pudmphdr;      //record i/o area
static long  Currpos=0;         //file current pos  
static long  Rechpos=0;         //file record header pos
static long  Reslen;            //record residula length
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI	    			//DPMI version                     //~v1.7R~
static UCHAR* Samestart;         //Same line start addr value      //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
static ULONG  Samestart;         //Same line start addr value      //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4I~
static UCHAR* Samestart;         //Same line start addr value
#endif                                                             //~v1.4I~
static int    Lineno;            //lineno in page                  //~v1.4R~
static int    Maxline=0;         //maxline per page                //~v1.4R~
static UINT   Pageno=0;          //pageno                          //~v1.4R~
static UINT   Pagepos;           //pageno offset in header line    //~v1.4R~
static UINT   Dumpwidth;        //16 byte or 32 byte per line      //~v1.4R~
static UINT   Linewidth;        //colomn per line                  //~v1.4R~
static UINT   Linecharpos;       //char dump colomn in line        //~v1.4R~
static long   Inputfsize;        //input file size                 //~v1.4R~
static UINT   Inputno=0;         //input header record count       //~v1.4R~
                                                                   //~v1.4I~
#if defined(DOS) || defined(W32)                                   //~v1.4R~
static FILE  *Inputfh;                                             //~v1.3R~
#else                                                              //~v1.3R~
static HFILE  Inputfh;           //input file handle
#endif                                                             //~v1.3R~
                                                                   //~v1.4I~
//atic int    Inputfh;           //input file handle
static FILE* Outputfh=NULL;      //output file handle

static UCHAR Inputfname[FILENAME_MAX]; //input filename
static UCHAR Outputfname[FILENAME_MAX]={OUTFILE}; //output filename//~v1.4R~
static UCHAR Samesave[DUMPWIDTHW];     //same chk dump data save
static UCHAR Rectitle[sizeof(Pudmphdr->UDMPtitle)+1];//record title
static UCHAR Recthreadid[2+1];//threadid
static UCHAR Header1 [133];      //page title
static UCHAR Header2 [133];      //page title
static UCHAR Line    [133];      //print line
static UCHAR Sameline[133];      //same as above line
//*******************************************************************

int main(int parmc,UCHAR *parmp[])                                 //~v1.4R~
{
#if defined(DOS) || defined(W32)                                   //~v1.4I~
 	FDATE fdate;                                                   //~v1.3R~
 	FTIME ftime;                                                   //~v1.3R~
    struct stat statbuf;                                           //~v1.3R~
	#ifdef W32                                                     //~v1.6I~
	#else                                                          //~v1.6I~
    #ifdef DPMI					//DPMI version                     //~v1.7I~
    #else                       //not DPMI                         //~v1.7I~
    ULONG flataddr;                                                //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7I~
	#endif                                                         //~v1.6I~
#else                                                              //~v1.3R~
  	FILESTATUS3 fstatus;         //file status by DosQueryFileInfo v1.3 add//~6814I~
	ULONG  openact;              //DosOpen parm                    //~6814I~
#endif                                                             //~v1.3R~
    UCHAR *prevendaddr=0;                                          //~v1.aR~
  ULONG  i,j,k;                //work                              //~v1.4R~
  int    form=DEFAULTFORM;     //form option                       //~6814R~
  APIRET apiret;               //Dos call r.c
//ULONG  sortno=0;             //sortlist entryno                  //~v1.4R~
  UINT   sortno=0;             //sortlist entryno                  //~v1.4I~
  long   readlen;              //data read length
  UCHAR  *pch1;                //char ptr work
  UCHAR  *pch2;                //char ptr work                     //~v1.4I~
  UCHAR  ch1;                                                      //~v1.4I~
  struct tm* plocaltime;       //local time       
  time_t stck;                 //stck value del
  PSORTLIST psortlist;         //sortlist ptr

//*******************************************************************
	udbcschkcp();	//set udbcschk_flag                            //~v10hI~
//**************************
//* initialize             *
//**************************
  Pudmphdr=(PUDMPHDR)malloc(IOBUFFSZ); //64kb ,32K for DOS         //~v1.4R~
  psortlist=(PSORTLIST)malloc(MAXSORTREC*sizeof(SORTLIST));
//**************************
//* parameter chk          *
//**************************

//**************************
//* parm1:input file name  *
//**************************
  if (parmc<2||*parmp[1]=='?')
  {
    putmsg(4,"IN-file [OUT-file(%s)] [W/L/S(%c)] [LINE per page(%2d)] \n\
                       W:32 byte dump per line,%d line per page\n\
                       L:32 byte dump per line,%d line per page\n\
                       S:16 byte dump per line,%d line per page\n",//~6814R~
	       OUTFILE,DEFAULTFORM,MAXLINEW,MAXLINEW,MAXLINES,MAXLINES);
  }
  strcpy(Inputfname,parmp[1]);

#if defined(DOS) || defined(W32)                                   //~v1.4I~
    Inputfh=fopen(Inputfname,"rb");                                //~v1.3R~
    if (!Inputfh)                                                  //~v1.3R~
        apiret=errno;                                              //~v1.3R~
    else                                                           //~v1.3R~
        apiret=0;                                                  //~v1.3R~
#else                                                              //~v1.3R~
  apiret=DosOpen(Inputfname,&Inputfh,&openact,0L,FILE_NORMAL,
           OPEN_ACTION_FAIL_IF_NEW|OPEN_ACTION_OPEN_IF_EXISTS,
           OPEN_SHARE_DENYWRITE|OPEN_ACCESS_READONLY,0L);
#endif                                                             //~v1.3R~
  if(apiret)
//if ((Inputfh=open(Inputfname,O_RDONLY|O_BINARY,0))==-1)  //open input fail
  {
    putmsg(4,"input file:\"%s\" open err,rc=%d\n",Inputfname,apiret);
//  putmsg(4,"input file:\"%s\" open err,rc=%d\n",Inputfname,errno);
  }

//**************************
//* parm2 output file name *
//**************************
  if (parmc>2 && strcmp(parmp[2],","))           //2nd parm
    strcpy(Outputfname,parmp[2]);

  if (strcmp(Outputfname,"stdout"))
  {
    if (Outputfh=fopen(Outputfname,"w"),!Outputfh)                 //~v1.3R~
      putmsg(4,"outputfile:\"%s\" open error\n",Outputfname);
  }
  else
    Outputfh=stdout;

//**************************
//* form option            *
//**************************
  if (parmc>3)                          // 2nd parm
  {
    form=toupper(*parmp[3]);            //form option
    switch (form)                       //form option
    {
	case 'W':
	case 'S':
	case 'L':
      break;
	case ',':
      form=DEFAULTFORM;
      break;
    default:
      putmsg(4,"3rd parm(form option) \"%s\" is invalid,specify W or L or S\n",
              parmp[3]);
	}
  }

  switch (form)                       //form option
  {
  case 'W':
    Dumpwidth=DUMPWIDTHW;
    Linewidth=LINEWIDTHW;
    Linecharpos=LINECHARPOSW;
    Maxline=MAXLINEW;
    break;
  case 'L':
    Dumpwidth=DUMPWIDTHW;
    Linewidth=LINEWIDTHW;
    Linecharpos=LINECHARPOSW;
    Maxline=MAXLINES;
    break;
  case 'S':
    Dumpwidth=DUMPWIDTHS;
    Linewidth=LINEWIDTHS;
    Linecharpos=LINECHARPOSS;
    Maxline=MAXLINES;
    break;
  }

//**************************
//* line per page          *
//**************************
  if (parmc>4 && *parmp[4]!=',')                    //3rd parm
  {
    for (i=0;i<strlen(parmp[4]);i++)
      if ( !isdigit( *(parmp[4]+i) ) )
        putmsg(4,"4th parm(line per page) \"%s\" is not numeric\n",parmp[4]);
    Maxline=atoi(parmp[4]); 
  }
  if (!Maxline) Maxline=0x0fffffff;
  Lineno=Maxline+1;             //first time hdr print

//*************************************
//* header line edit                  *
//*************************************

//*from file status****

#if defined(DOS) || defined(W32)                                   //~v1.4I~
    apiret=stat(Inputfname,&statbuf);                              //~v1.3R~
    if (apiret)                                                    //~v1.3R~
    {                                                              //~v1.3R~
    	apiret=errno;                                              //~v1.3R~
	    putmsg(4,"input file:\"%s\" status get failed,rc=%d\n",    //~v1.3R~
             Inputfname,apiret);                                   //~v1.3R~
	}                                                              //~v1.3R~
//printf("stat time=%08x,%08x,%08x\n",                             //~v1.3R~
//		statbuf.st_atime,                                          //~v1.3R~
//		statbuf.st_mtime,                                          //~v1.3R~
//		statbuf.st_ctime);                                         //~v1.3R~
	Inputfsize=(long)statbuf.st_size;                              //~v1.3R~
    ugetftime(Inputfname,&fdate,&ftime);                           //~v1.3R~
#ifdef W32                                                         //~van0I~
    _set_printf_count_output(1);   //enable %n parameter           //~van0I~
#endif                                                             //~van0I~
  	sprintf(Header2,                                               //~v1.3R~
          "%50.50s (%02d-%02d-%02d %02d:%02d) PAGE=%n%05d \n\n",   //~v1.3R~
          Inputfname,                                              //~v1.3R~
          (fdate.year+80)%100,                                     //~v10hR~
          fdate.month,                                             //~v1.3R~
          fdate.day,                                               //~v1.3R~
          ftime.hours,                                             //~v1.3R~
          ftime.minutes,                                           //~v1.3R~
          &Pagepos,                                                //~v1.3R~
          0);                                                      //~v1.3R~
#else                                                              //~v1.3R~
  apiret=DosQueryFileInfo(Inputfh,FIL_STANDARD,&fstatus,sizeof fstatus);
  if(apiret)
//if(fstat(Inputfh,&fstatus))
    putmsg(4,"input file:\"%s\" status get failed,rc=%d\n",
             Inputfname,apiret);
  
  Inputfsize=(long)fstatus.cbFile;

  sprintf(Header2,
          "%50.50s (%02d-%02d-%02d %02d:%02d) PAGE=%n%05d \n\n",
          Inputfname,
          (fstatus.fdateLastWrite.year+80)%100,                    //~v10hR~
          fstatus.fdateLastWrite.month,
          fstatus.fdateLastWrite.day,  
          fstatus.ftimeLastWrite.hours,
          fstatus.ftimeLastWrite.minutes,
          &Pagepos,
          0);
#endif                                                             //~v1.3R~
  for (i=0;i<sizeof(Header2);i++)
    if (Header2[i]!=' ') 
      break;
  for (j=0;j<i-1;j++)
    Header2[j]='*'; 
  

//*from abinf record ****

  if (!(readlen=readdmphdr(FILE_BEGIN,(long)0))) //eof             //~v1.4R~
    putmsg(4,"input file:\"%s\" is empty\n",Inputfname);
  if (readlen<0) //*read err
    return 4;

  if ( chkrtype()          //not abinfo record
     || readdata()<=0 )    //read err
    putmsg(4,"input file:\"%s\" first record is not valid simpton record\n",
              Inputfname);

//*(pch1=strchr((UCHAR*)(void*)(Pudmphdr+1),'\n'))=0;//temporary set null terminator;//~v1.4R~
	pch1=(UCHAR*)(void*)(Pudmphdr+1);                              //~v1.4I~
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI	    			//DPMI version                     //~v1.7R~
    	pch2=ustrnstr(pch1,DUMPTITLEID,Pudmphdr->UDMPlenparm);     //~v1.7R~
    	if (pch2)    //search second line for OS2                  //~v1.7R~
        	pch1=pch2;                                             //~v1.7R~
    	i=(ULONG)(Pudmphdr+1)+Pudmphdr->UDMPlenparm-(ULONG)pch1;   //~v1.7R~
    	pch2=ustrnchr2(pch1,'\n',(int)i);                          //~v1.7R~
       	if (!pch2)                                                 //~v1.7R~
    		pch2=pch1+i;                                           //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
	pch2=ustrnchr2(pch1,'\n',(int)Pudmphdr->UDMPlenparm);          //~v1.4M~
	if (!pch2)                                                     //~v1.4I~
	  	pch2=pch1+Pudmphdr->UDMPlenparm;                           //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4I~
	pch2=ustrnstr(pch1,DUMPTITLEID,Pudmphdr->UDMPlenparm);         //~v1.4R~
	if (pch2)    //search second line for OS2                      //~v1.4R~
    	pch1=pch2;                                                 //~v1.4I~
	i=(ULONG)(Pudmphdr+1)+Pudmphdr->UDMPlenparm-(ULONG)pch1;       //~v1.4I~
	pch2=ustrnchr2(pch1,'\n',(UINT)i);                             //~v1.7R~
   	if (!pch2)                                                     //~v1.4R~
		pch2=pch1+i;                                               //~v1.4R~
#endif                                                             //~v1.4I~
  ch1=*pch2;                                                       //~v1.4R~
  *pch2=0;  //temporary null term                                  //~v1.4R~
//  sprintf(Header1,"\f*** %-90.90s ***\n",Pudmphdr+1);            //~v1.4R~
  	sprintf(Header1,"\f*** %s ***\n",pch1);                        //~v1.4R~
  *pch2=ch1; //restore                                             //~v1.4R~

  putmsg(0,"++++++++++ process start ; Input=%s(%ld byte),\n\
                       Output=%s,%d byte dump,%d line per page\n", //~v1.3R~
          Inputfname,Inputfsize,Outputfname,Dumpwidth,Maxline);
  printf("%s",Header1+1);                                          //~v1.4I~
                                                                   //~v1.4M~
//*****************************
//* edit simpton record       *
//*****************************

  printdmphdr();
  printabinf();
#if  defined(DOS) && !defined(DPMI)	//native DOS                   //~v1.9I~
#else                                                              //~v1.9I~
  	printcode();          //code disas                             //~v1.9I~
#endif                                                             //~v1.9I~

//*****************************
//* edit all header record    *
//*****************************
  while ((readlen=readdmphdr(FILE_CURRENT,Reslen))>0)//until eof or err;
  {
    printdmphdr(); 
	if (!Pudmphdr->UDMPlenparm)	//no data                          //~v1.5I~
    	continue;               //read next hdr                    //~v1.5I~

    switch  (chkrtype()) //chk record type 
    {
    case 0:    //abinf record
      if ((readlen=readdata())<=0) break;
      printabinf();
      break;
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
    case 2:    //DOS CPNTEXT record                                //~v1.4I~
      if ((readlen=readdata())<=0) break;                          //~v1.4I~
      printdosctx();                                               //~v1.4I~
      break;                                                       //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#endif                                                             //~v1.4I~
    case -1:
//***add to sort list
      if (sortno>=MAXSORTREC)
      {
        putmsg(0,"record count overflow(MAX=%d),detail print bypassed\
 for this entry\n",MAXSORTREC);
        break;
      }
      (psortlist+sortno)->sortaddr=Pudmphdr->UDMPaddrparm;
      memcpy((psortlist+sortno)->sortdatetime,
             &Pudmphdr->UDMPcurrentdate,
             sizeof(psortlist->sortdatetime)); 
      (psortlist+sortno)->sortpos=Rechpos;
      sortno++;
      break;
    default:
      if ((readlen=readdata())<=0)
        break;
      printdump(Pudmphdr->UDMPaddrparm,Pudmphdr->UDMPlenparm,
                Pudmphdr+1);
    }//end of switch

    if (readlen<=0) //readdata err
      break;

  }//readdmphdr loop

  putmsg(0,"++++++++++ end of summary; total %d records read\n",   //~v1.3R~
          Inputno);
  Inputno=0;
  Lineno=Maxline+1;     //req page eject;
//****************************************
//* sort addr list                       *
//****************************************

  qsort(psortlist,sortno,sizeof(SORTLIST),addrcomp);               //~v1.4R~

//****************************************
//* edit storage data by addr seq        *
//****************************************
  
  for (k=0;k<sortno;k++) //all sort list entry
  {
    if ((readlen=readdmphdr(FILE_BEGIN,(psortlist+k)->sortpos))<=0)
      break;

    i=(ULONG)Pudmphdr->UDMPlenparm;
    pch1=Pudmphdr->UDMPaddrparm;
    if (pch1+i<prevendaddr)		//cuurentend is in prev range      //~v1.aR~
    	continue;               //skip dump                        //~v1.aR~
	prevendaddr=pch1+i;			//end addr of cuurent dump         //~v1.aR~
    while(Reslen)
    {
      readlen=readdata();
		if (!readlen || readlen==-1)
			break;
      	if (readlen<0)
		{
	      	printdump(pch1,(UINT)(-readlen),Pudmphdr+1);
			break;
		}
		else
	    	printdump(pch1,min(i,(ULONG)readlen),Pudmphdr+1);      //~v1.6R~
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7R~
      pch1+=readlen;                                               //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
		flataddr=FLATADDR(pch1)+readlen;                           //~v1.4I~
      	FP_SEG(pch1)=(flataddr>>4);                                //~v1.4I~
      	FP_OFF(pch1)=(flataddr & 0x0f);                            //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4I~
      pch1+=readlen;
#endif                                                             //~v1.4I~
      i-=readlen;
    }
    if (readlen<=0) break;
  }

//****************************************
//* termination                          *
//****************************************
#if defined(DOS) || defined(W32)                                   //~v1.4I~
	fclose(Inputfh);                 //close input                 //~v1.3R~
#else                                                              //~v1.3R~
  apiret=DosClose(Inputfh);
#endif                                                             //~v1.3R~
//close(Inputfh);                 //close input
//if (Outputfh!=stdout)
//  fclose(Outputfh);
  
  time(&stck);
  plocaltime=localtime(&stck);
  putmsg(0,"++++++++++ dump file:\"%s\" print completed;\n\
                       %d pages output at %s\n",
          Inputfname,Pageno,asctime(plocaltime));
  return 0;
}   //end main

//********************************************************************
//* qsort sub(dump storage addr compare)
//*   input:
//*     p1:sort list entry addr1
//*     p2:sort list entry addr2
//*   output:
//*     compare result : <0 : element1<element2
//*                    : =0 : element1=element2
//*                    : => : element1>element2
//********************************************************************

int  addrcomp(const void* entry1,const void* entry2)
{
  PSORTLIST psl1,psl2;
//int  rc;         //compare result                                //~v1.7R~
//*************************
  psl1=(PSORTLIST)entry1;
  psl2=(PSORTLIST)entry2;
//rc= (int)(((ULONG)psl1->sortaddr-(ULONG)psl2->sortaddr));        //~v1.7R~
//if (rc) return  rc;      //addr not eq                           //~v1.7I~
  if (psl1->sortaddr > psl2->sortaddr)                             //~v1.7I~
  	return 1;	                                                   //~v1.7I~
  if (psl1->sortaddr < psl2->sortaddr)                             //~v1.7I~
  	return -1;                                                     //~v1.7I~
  return memcmp(psl1->sortdatetime,psl2->sortdatetime,
                sizeof(psl1->sortdatetime));

}//end of addromp

//********************************************************************
//* check record type
//*   input:
//*     none(static Rectitle)
//*   output:
//*     record type : 0 if abinf record
//*                 :>0 if control record 
//*                 :-1 if not control record 
//********************************************************************

int chkrtype(void)                                                 //~v1.4R~
{
  static UCHAR Rtype[][sizeof(Rectitle)]
              ={UDMPID_ABINFO,
                UDMPID_REPREC,
                UDMPID_CTXREC,
                UDMPID_REGREC};
  int i;                                                           //~v1.4R~
//*************************
  for (i=0;i<sizeof(Rtype)/sizeof(Rectitle);i++)
    if (!strcmp(Rectitle,Rtype[i]))
      return i;
  return -1;    
}//end of chkrtype

//********************************************************************
//* dump record header read sub                                                    *
//*   input:
//*     p1:origin :FILE_BEGIN  : from start of file
//*                FILE_CURRENT: from current position
//*                FILE_END    : from end pos
//*     p2:offset :offset from origin
//*   output:
//*     read length,0 if EOF,-1 if err
//********************************************************************

long  readdmphdr(UINT origin,long offset)                          //~v1.4R~
{
  long  readlen;
//*************************
  readlen=dumpio(origin,offset,(long)sizeof(UDMPHDR),Pudmphdr);    //~v1.4R~

  if (readlen<=0)
    Reslen=0;//no more residula
  else
  {
    Rechpos=Currpos-sizeof(UDMPHDR);
    if ( strncmp(Pudmphdr->UDMPreceyec,UDMPEYECID,sizeof(Pudmphdr->UDMPreceyec)) )
    {
      putmsg(0,"input file:\"%s\" may not valid dump file(current pos=%08x:\
header acronym chk err)\n",
              Inputfname,Rechpos);
      readlen=-1;         
    }
    else
    {
      Inputno++;
      Reslen=(long)Pudmphdr->UDMPreclen-sizeof(UDMPHDR);//residual length
      strncpy(Rectitle,Pudmphdr->UDMPtitle,sizeof(Rectitle)-1);
      sprintf(Recthreadid,"%02ld",Pudmphdr->UDMPthreadid);         //~v1.4R~
    }  
  }
  return readlen;

}//end of readdmphdr

//********************************************************************
//* dump record header read sub                                                    *
//*   input:
//*     none
//*   output:
//*     read length , 0 if eof, -1 if err
//********************************************************************

long  readdata(void)
{
  long  readlen;
//*************************
  readlen=dumpio(FILE_CURRENT,(long)0,                             //~v1.4R~
                 min(Reslen,(long)(IOBUFFSZ-sizeof(UDMPHDR))),     //~v1.4R~
                 Pudmphdr+1);
  if (readlen>0)
    Reslen-=readlen;//update residula

  return readlen;
}//end of dumpread

//********************************************************************
//* dump read sub                                                    *
//*   input:
//*     p1:origin :FILE_BEGIN  : from start of file
//*                FILE_CURRENT: from current position
//*                FILE_END    : from end pos
//*     p2:offset :offset from origin
//*     p3:length :read request length
//*     p4:io aera:read area addr
//*   output:
//*     read length,
//*     0 if eof,
//*     -1 if seek err,read err
//*     -read length if read length<requested length
//********************************************************************
//********************************************************************

long  dumpio(UINT origin,long offset,long len,void* addr)          //~v1.4R~
{
  APIRET apiret;
#if defined(DOS) || defined(W32)                                   //~v1.4I~
#else                                                              //~v1.3R~
  ULONG  newpos;                                                   //~v1.3R~
#endif                                                             //~v1.3R~
  ULONG  retlen;
  long  readlen;
//*******************************************************
  if (origin!=FILE_CURRENT || offset) //not current pos
  {
#if defined(DOS) || defined(W32)                                   //~v1.4I~
	if(fseek(Inputfh,offset,origin))                               //~v1.3R~
    	apiret=errno;                                              //~v1.3R~
	else                                                           //~v1.3R~
    	apiret=0;                                                  //~v1.3R~
#else                                                              //~v1.3R~
    apiret=DosSetFilePtr(Inputfh,offset,origin,&newpos);    
#endif                                                             //~v1.3R~
    if(apiret)
//  if(lseek(Inputfh,offset,origin)==-1)
    {
      putmsg(0,"input file:\"%s\" seek failed,rc=%d(origin=%d,offset=%08x)\n",
  	          Inputfname,apiret,origin,offset);
      return -1;
    }
  }
//*****************  
  switch (origin)
  {
  case FILE_BEGIN: 
    Currpos=offset;
	break;
  case FILE_CURRENT: 
    Currpos+=offset;
	break;
  case FILE_END: 
    Currpos=Inputfsize+offset;
	break;
  }

#if defined(DOS) || defined(W32)                                   //~v1.4I~
  	retlen=fread(addr,1,(size_t)len,Inputfh);                      //~v1.4R~
  	if (retlen && retlen!=(ULONG)len)                              //~v1.6R~
  		apiret=errno;                                              //~v1.3R~
	else	                                                       //~v1.3R~
  		apiret=0;                                                  //~v1.3R~
                                                                   //~v1.3R~
#else                                                              //~v1.3R~
  retlen=0;                                                        //~6814R~
  apiret=DosRead(Inputfh,addr,(ULONG)len,&retlen);
#endif                                                             //~v1.3R~
  readlen=(long)retlen;
//readlen=read(Inputfh,addr,(ULONG)len);

  if(apiret||readlen)//not eof
  {
    if(apiret||readlen!=len)
      putmsg(0,"input file:\"%s\" read failed,rc=%d(current pos=%08x,\
reqlen=%08x,readlen=%08x)\n",
  	        Inputfname,apiret,Currpos,len,readlen);
    if (apiret)
      readlen=-1;
    else
    {
      Currpos+=readlen;
      if (readlen!=len)
        readlen=0-readlen; //err id
    }
  }
  return readlen;
}//end of dumpread

//********************************************************************
//* print abend information record
//*   input:
//*     record area
//*   output:
//*     print record
//********************************************************************
void printabinf(void)
{
  UCHAR *pc1,*pc2,*pc3;
//*******************
  pc1=(UCHAR*)(Pudmphdr+1);
  pc2=pc1+Pudmphdr->UDMPlenparm;
  while (pc1<pc2)
  {
    pc3=strchr(pc1,'\n');
    if (!pc3 || pc3>=pc2)                                          //~v1.4R~
    	pc3=pc2-1;	//add 1 next                                   //~v1.4I~
    putline(pc1,(UINT)((ULONG)pc3-(ULONG)pc1+1));                  //~v1.4R~
    pc1=pc3+1;
  }
}//end of printabinf
                                                                   //~v1.4I~
#if  defined(DOS) && !defined(DPMI)	//native DOS                   //~v1.9I~
#else                                                              //~v1.9I~
//********************************************************************//~v1.9I~
//* print code disassemble                                         //~v1.9I~
//********************************************************************//~v1.9I~
void printcode(void)                                               //~v1.9I~
{                                                                  //~v1.9I~
static  UCHAR *Secodetitle="Code Seg Dump";                        //~v1.9I~
static  UCHAR *Sjcodetitle="コードダンプ";                         //~v1.9I~
static  DAPARM Sdap;                                               //~v1.9I~
  	UCHAR *pc1,*pc2,*buff;                                         //~v1.9R~
    UCHAR *pc3;                                                    //~v1.bR~
  	int len,len2,rc,ii;                                            //~v1.9R~
	UINT  hex[8];                                                  //~v1.9R~
	ULONG  base,svsaddr;                                           //~v1.bI~
	UCHAR  *saddr;                                                 //~v10gI~
//*******************                                              //~v1.9I~
  	pc1=(UCHAR*)(Pudmphdr+1);                                      //~v1.9I~
  	len=(int)Pudmphdr->UDMPlenparm;                                //~v1.9R~
  	pc2=ustrnstr(pc1,Secodetitle,(UINT)len);	//english          //~v1.9I~
  	if (!pc2)                                                      //~v1.9I~
	  	pc2=ustrnstr(pc1,Sjcodetitle,(UINT)len);	//japanese     //~v1.9I~
  	if (!pc2)                                                      //~v1.9I~
		return;                                                    //~v1.9I~
	if (!(pc3=strchr(pc2,':')))                                    //~v1.bR~
    	return;                                                    //~v1.bI~
	base=0;                                                        //~v1.bI~
	ux2l(pc3+1,&base);                                             //~v1.bR~
	len-=(int)((UINT)pc2-(UINT)pc1);                               //~v1.9I~
	pc2=ustrnchr2(pc2,'\n',(UINT)len);	//search next line         //~v1.9R~
  	if (!pc2)                                                      //~v1.9I~
		return;                                                    //~v1.9I~
	pc2++;                                                         //~v1.9I~
    rc=sscanf(pc2," %x %x %x %x %x %x %x %x",                      //~v1.9I~
				&hex[0],&hex[1],&hex[2],&hex[3],&hex[4],&hex[5],&hex[6],&hex[7]);//~v1.9R~
	if (rc!=8)                                                     //~v1.9I~
		return;                                                    //~v1.9I~
//*reverse int to char(scanf return int value)                     //~v1.9I~
	for (ii=0;ii<8;ii++)                                           //~v1.9I~
    	hex[ii]=USTRLOAD(hex+ii);                                  //~v1.9I~
//disas                                                            //~v1.9I~
	Sdap.DAPitype=DAPITFULL+DAPITFPU;                              //~v1.9I~
	Sdap.DAPmode=DAPM32;                                           //~v1.9I~
	Sdap.DAPsaddr=(PVOID)(&hex[0]);		//temporaly start addr     //~v1.9R~
	Sdap.DAPbase =(PVOID)base;                 //virtual base addr //~v1.bR~
	Sdap.DAPeaddr=(PVOID)(&hex[4]);                                //~v1.9R~
	Sdap.DAPbase=(PVOID)(&hex[0]);		//temporaly start addr     //~v1.bI~
    svsaddr=(ULONG)Sdap.DAPsaddr;                                  //~v10hI~
//once try chk reverse disas                                       //~v1.9I~
//    rc=udisasrevchk(&Sdap);     //try reverse                    //~v10gR~
    rc=udisasrevchk(&Sdap,&saddr);     //try reverse               //~v10gI~
//    svsaddr=(ULONG)Sdap.DAPsaddr;                                //~v10gR~
//  svsaddr=(ULONG)saddr;                                          //~v10hR~
	if (rc)                                                        //~v1.9I~
		Sdap.DAPsaddr=(PVOID)(&hex[4]);                            //~v1.9I~
	else                                                           //~v1.9I~
//        Sdap.DAPsaddr=Sdap.DAPcaddr;    //reverse point          //~v10gR~
        Sdap.DAPsaddr=saddr;    //reverse point                    //~v10gI~
	Sdap.DAPbase=(PVOID)((ULONG)Sdap.DAPsaddr-svsaddr+base);       //~v1.bI~
	Sdap.DAPeaddr=(PVOID)(&hex[8]);               //end addr       //~v1.9I~
	len=4096;                                                      //~v1.9M~
	buff=umalloc((UINT)len);                                       //~v1.9M~
	Sdap.DAPopt=DAPOPSTART|DAPOPFCONT;                             //~v1.9I~
	Sdap.DAPitype=DAPITFULL+DAPITFPU;                              //~v1.9I~
	Sdap.DAPfh=0;                                                  //~v1.9I~
	Sdap.DAPoutbuff=buff;                                          //~v1.9I~
	Sdap.DAPoutbufflen=len;                                        //~v1.9I~
//  Sdap.DAPaddrpos=-1;		//no addr print                        //~v1.bR~
	rc=udisas(&Sdap);		//try reverse                          //~v1.9R~
	if (rc)                                                        //~v1.9I~
    	return;                                                    //~v1.9I~
    putline("\n*** CODE DISASSEMBLE ***\n",0);                     //~v1.9R~
    len=Sdap.DAPoutlen;                                            //~v1.9I~
    for (pc1=buff;len>0;)                                          //~v1.9I~
    {                                                              //~v1.9I~
		pc2=ustrnchr2(pc1,'\n',(UINT)len);	//search next line     //~v1.9R~
        if (pc2)                                                   //~v1.9I~
        	len2=(int)((ULONG)pc2-(ULONG)pc1)+1;                   //~v1.9I~
		else                                                       //~v1.9I~
        	len2=len;                                              //~v1.9I~
	    putline(pc1,(UINT)len2);                                   //~v1.9R~
        len-=len2;                                                 //~v1.9I~
        pc1=pc2+1;                                                 //~v1.9I~
    }                                                              //~v1.9I~
    return;                                                        //~v1.9I~
}//printcode                                                       //~v1.9I~
                                                                   //~v1.9I~
#endif                                                             //~v1.9I~
                                                                   //~v1.9I~
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
//********************************************************************//~v1.4I~
//* print dos context                                              //~v1.4I~
//*   input:                                                       //~v1.4I~
//*     record area                                                //~v1.4I~
//*   output:                                                      //~v1.4I~
//*     print record                                               //~v1.4I~
//********************************************************************//~v1.4I~
void printdosctx(void)                                             //~v1.4I~
{                                                                  //~v1.4I~
	PUDOSCON pudcn;                                                //~v1.4I~
    UCHAR ctxmsg[128];                                             //~v1.4I~
  	void *ptr;                                                     //~v1.4I~
    int pos;                                                       //~v1.4I~
//*******************                                              //~v1.4I~
	pudcn=(PVOID)(Pudmphdr+1);                                     //~v1.4I~
    ptr=pudcn->UDCNepamain;                                        //~v1.4I~
  	pos=sprintf(ctxmsg,"main=%04X:%04X(%08lX) ",                   //~v1.4R~
 				FP_SEG(ptr),FP_OFF(ptr),FLATADDR(ptr));            //~v1.4I~
    ptr=pudcn->UDCNenddata;                                        //~v1.4M~
  	pos+=sprintf(ctxmsg+pos,"DATA=%04X-->%04X:%04X(%08lX) ",       //~v1.4R~
				pudcn->UDCNds0,FP_SEG(ptr),FP_OFF(ptr),FLATADDR(ptr));//~v1.7R~
    ptr=pudcn->UDCNbpsavearea;                                     //~v1.4M~
  	pos+=sprintf(ctxmsg+pos,"last BP=%04X:%04X(%08lX)\n",          //~v1.4R~
 				FP_SEG(ptr),FP_OFF(ptr),FLATADDR(ptr));            //~v1.4M~
  	pos+=sprintf(ctxmsg+pos,"current CS=%04x,DS=%04x,SS=%04x\n",   //~v1.7I~
 				pudcn->UDCNcs,pudcn->UDCNds,pudcn->UDCNss);        //~v1.7I~
    putline(ctxmsg,0);	//by strlen                                //~v1.4I~
}//printdosctx                                                     //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#endif //DOS                                                       //~v1.4I~
                                                                   //~v1.4I~
//********************************************************************
//* print record header
//*   input:
//*     record area
//*   output:
//*     print record
//********************************************************************
void printdmphdr(void)
{
//*******************
#ifdef DOS                                                         //~v1.4M~
    #ifdef DPMI					//DPMI version                     //~v1.7R~
      sprintf(Line,                                                //~v1.7R~
              "\n%08x==\"%-16.16s\"  %02x-%02x-%02x %02x:%02x:%02x.%02x\
 A=%08x L=%08lX\n",                                                //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
  sprintf(Line,                                                    //~v1.4I~
          "\n%08lX==\"%-16.16s\"  %02x-%02x-%02x %02x:%02x:%02x.%02x\
 A=%04X:%04X(%08lX) L=%08lX\n",                                    //~v1.4R~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4M~
  sprintf(Line,
          "\n%08X==TID=%s:\"%-16.16s\"  %02x-%02x-%02x %02x:%02x:%02x.%02x\
 A=%08p L=%08X\n",                                                 //~vba3I~
//A=%08X L=%08X\n",                                                //+vba3M~
#endif                                                             //~v1.4I~
#ifdef DPMI					//DPMI version                         //~v1.7I~
          (UINT)Rechpos,                                           //~v1.7R~
#else                       //not DPMI                             //~v1.7I~
          Rechpos,                                                 //~v1.4R~
#endif                      //DPMI or not                          //~v1.7I~
#ifdef DOS                                                         //~v1.4I~
#else                                                              //~v1.4I~
			Recthreadid,                                           //~v1.4I~
#endif                                                             //~v1.4I~
			Rectitle,                                              //~v1.4I~
    (int)((Pudmphdr->UDMPcurrentdate & 0x0000ff00)>>8),   //ddmmYYyy//~v1.4R~
    (int)((Pudmphdr->UDMPcurrentdate & 0x00ff0000)>>16),  //ddMMyyyy//~v1.4R~
    (int)(Pudmphdr->UDMPcurrentdate >>24),                //DDmmyyyy//~v1.4R~
    (int)(Pudmphdr->UDMPcurrenttime & 0x000000ff),        //thssmmHH//~v1.4R~
    (int)((Pudmphdr->UDMPcurrenttime & 0x0000ff00)>>8),   //thssMMhh//~v1.4R~
    (int)((Pudmphdr->UDMPcurrenttime & 0x00ff0000)>>16),  //thSSmmhh//~v1.4R~
    (int)(Pudmphdr->UDMPcurrenttime >>24),                //THssmmhh//~v1.4R~
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7R~
    	(UINT)Pudmphdr->UDMPaddrparm,                              //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
    	FP_SEG(Pudmphdr->UDMPaddrparm),                            //~v1.4R~
    	FP_OFF(Pudmphdr->UDMPaddrparm),                            //~v1.4I~
        FLATADDR(Pudmphdr->UDMPaddrparm),                          //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4I~
    	Pudmphdr->UDMPaddrparm,                                    //~v1.4I~
#endif                                                             //~v1.4I~
          Pudmphdr->UDMPlenparm);                                  //~v1.4R~
  putline(Line,0);

}//end of printdmphdr

//********************************************************************
//* dump edit
//*   input:
//*     addd  :dump storage addr
//*     length:dump data length
//*     area  :actual data area addr
//*   output:
//*     none
//********************************************************************

void printdump(void* addr,ULONG len,void* area)
{

  UINT   ii,jj;                /*work*/                            //~v1.4R~
  int dbcssw;	
  int     comp;               /*same line compare sw*/
  UINT  maxbyte;            /*source range*/                       //~v1.4R~
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7R~
		UCHAR *pc1,*pc2,*pc;      /*source  addr*/                 //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
	ULONG pc,pc1,pc2;                                              //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4I~
  UCHAR *pc1,*pc2,*pc;      /*source  addr*/  
#endif                                                             //~v1.4I~
  UCHAR *pcdata;            /*actual source  addr*/  
  UCHAR *ln1,*ln2;          /*line ptr*/        
//static UCHAR trt[16]="0123456789ABCDEF";/*hex cnv tbl*/          //~van0R~
  static UCHAR trt[17]="0123456789ABCDEF";/*hex cnv tbl*/ //avoid compiler warning "could not include null terminator"//~van0I~
//*********************                   
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7R~
      pc1=(UCHAR*)addr;         /*start addr*/                     //~v1.7R~
      pc2=pc1+len;              /*end addr*/                       //~v1.7R~
      pc =(UCHAR*)((ULONG)pc1 & (0-Dumpwidth));                    //~v1.7R~
      maxbyte=(UINT)(((ULONG)(pc2+Dumpwidth-1) & (long)(0-Dumpwidth))-(ULONG)pc); /*end   boundary*///~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
  pc1=FLATADDR(addr);         /*start addr*/                       //~v1.4I~
  pc2=pc1+len;              /*end addr*/                           //~v1.4I~
  pc =(pc1 & (long)(0-(int)Dumpwidth));                            //~v1.4R~
  maxbyte=(UINT)(((ULONG)(pc2+(long)(Dumpwidth-1)) & (long)(0-(int)Dumpwidth))-(ULONG)pc); /*end   boundary*///~v1.4R~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4I~
  pc1=(UCHAR*)addr;         /*start addr*/
  pc2=pc1+len;              /*end addr*/
  pc =(UCHAR*)((ULONG)pc1 & (0-Dumpwidth));
  maxbyte=(UINT)(((ULONG)(pc2+Dumpwidth-1) & (long)(0-Dumpwidth))-(ULONG)pc); /*end   boundary*///~v1.4R~
#endif                                                             //~v1.4M~
                                                                    
  if (addr==(void*)Pudmphdr->UDMPaddrparm)
  {
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7R~
        sprintf(Line,"\n--------  \"%-16.16s\"   ADDR=%08x LEN=%08lX ----\n",//~v1.7R~
                Rectitle,                                          //~v1.7R~
                (UINT)Pudmphdr->UDMPaddrparm,                      //~v1.7R~
                Pudmphdr->UDMPlenparm);                            //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
    sprintf(Line,"\n--------  %s:\"%-16.16s\"   ADDR=%04X:%04X(%08lX) LEN=%08lX ----\n",//~v1.7R~
            Rectitle,                                              //~v1.7R~
            FP_SEG(Pudmphdr->UDMPaddrparm),                        //~v1.4I~
            FP_OFF(Pudmphdr->UDMPaddrparm),                        //~v1.4I~
            FLATADDR(Pudmphdr->UDMPaddrparm),                      //~v1.4R~
            Pudmphdr->UDMPlenparm);                                //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4I~
//  sprintf(Line,"\n--------  TID=%s:\"%-16.16s\"   ADDR=%08X LEN=%08X ----\n",//~vba3R~
    sprintf(Line,"\n--------  TID=%s:\"%-16.16s\"   ADDR=%08p LEN=%08X ----\n",//~vba3I~
            Recthreadid,Rectitle,
            Pudmphdr->UDMPaddrparm,
            Pudmphdr->UDMPlenparm);
#endif                                                             //~v1.4I~
    putline(Line,0);
    Samestart=0;   //initial switch for chk same as above
  }          

  memset(Line,' ',Linewidth);                  /*print line clear*/  
  Line[Linecharpos-1]='*';                     /*char part start*/   
  Line[Linecharpos+Dumpwidth]='*';                     /*char part end*/     
  Line[Linewidth]='\n';                    /*end of string*/     
                                                                    
	dbcssw=0;
  for (ii=0;ii<=maxbyte;ii+=Dumpwidth)        /*full area*/        //~v1.4R~
  {                                 /*max byte*/            
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7R~
        pcdata    =(UCHAR*)area+(ULONG)pc-(ULONG)addr;             //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
    pcdata    =(UCHAR*)area+(UINT)(pc-FLATADDR(addr));             //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4I~
    pcdata    =(UCHAR*)area+(ULONG)pc-(ULONG)addr;
#endif                                                             //~v1.4I~
    comp=1;                            //unmatch id
    if (pc>=pc1 && pc+Dumpwidth<=pc2)   //full dumpwidth data
    {                                                     
      if (Samestart) //not first time
        comp=memcmp(Samesave,pcdata,Dumpwidth);

      if (comp)      //unmatch or first line
        comp=2;      //full new line id  
    }//full 1 dump line

    if (  comp                    //unmatch
       && Samestart               //save line exist
       && pc!=Samestart+Dumpwidth)// not single line
    {
      memset(Sameline,' ',LINEHEXPOS+1);  /*print line clear*/  
      sprintf(Sameline+LINEHEXPOS+1,
#ifdef DPMI					//DPMI version                         //~v1.7I~
              "%08x to %08x is same as above\n",                   //~v1.7R~
              (UINT)(Samestart+Dumpwidth),(UINT)(pc-1));           //~v1.7I~
#else                       //not DPMI                             //~v1.7I~
//            "%08lX to %08lX is same as above\n",                 //~v1.4R~//~vba3R~
              "%08p to %08p is same as above\n",                   //~vba3I~
              Samestart+Dumpwidth,pc-1);
#endif                      //DPMI or not                          //~v1.7M~
      putline(Sameline,0);
    }

    if (ii==maxbyte)       // last line                            //~v1.4R~
      break;

    if (!comp) //match case
      pc+=Dumpwidth;//next line data
    else
    {//unmatch case
      if (comp==2)   //full dumpwidth data unmatch
      {
        memcpy(Samesave,pcdata,Dumpwidth);
        Samestart=pc;
      } 
      else
        Samestart=0;   //clear for last line chk                   //~v1.4R~
//*edit addr value
      ln1=Line+LINEADDRPOS;     //addr edit start pos
      ln2=(UCHAR*)&pc+4;        //source field
      for (jj=0;jj<4;jj++)         //edit 4 byte hex               //~v1.4R~
      {
        *(ln1++)=*(trt+(*(--ln2)>>4));       //first 4 bit
        *(ln1++)=*(trt+(*ln2 & 0x0000000f)); //last 4 bit
      }
                                                                    
      ln1=Line+LINEHEXPOS-1;                     /*hex start*/    
      ln2=Line+Linecharpos;                       /*char start*/   
                                                                    
      for (jj=0;jj<Dumpwidth;jj++)           /* 1 line setup*/     //~v1.4R~
      {                                                       
        if (!(jj & 0x03)) ln1++;  /*' ' each 4 byte*/              //~v1.4R~
        if (!(jj & 0x0F)) ln1++;  /*' ' each 16 byte*/             //~v1.4R~
                                                                    
        if (pc<pc1 || pc>=pc2)   /*by boundary align*/
        {
          *ln2    =' ';                /*char part*/        
//        *((unsigned short*)ln1)='  '; /*dump part,2byte*/        //~v1.4R~
          *ln1=*(ln1+1)=' ';			 /*dump part,2byte*/       //~v1.4I~
        }
        else                             /*net area*/         
        {
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7R~
          pcdata    =(UCHAR*)area+(ULONG)pc-(ULONG)addr;           //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
			pcdata    =(UCHAR*)area+(UINT)(pc-FLATADDR(addr));     //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4I~
          pcdata    =(UCHAR*)area+(ULONG)pc-(ULONG)addr;
#endif                                                             //~v1.4I~
          *ln2=*pcdata;			         /*char part*/  
			if (dbcssw)
			{
				dbcssw=0;
				if (!jj)                                           //~v1.4R~
					*ln2='.';
			}
			else
          		if (*ln2<' ')			         //ctl char
				{
					dbcssw=0;
					*ln2='.';
				}
				else	// >=' '
				{
					if (*ln2<0x7f)	//7f is unprintable	
						dbcssw=0;
					else	//over 7f
					{
						if (!(dbcssw=udbcschk(*ln2)))
						{
							*ln2='.';
						}
						else	//dbcs first byte
#ifdef WCSUPP                                                      //~v10hI~
							if (pc>=pc2 || !WCMB2ND(0,(pcdata+1))) //~v10hI~
#else                                                              //~v10hI~
							if (pc>=pc2 || *(pcdata+1)<' ' || *(pcdata+1)>0xfc)
#endif                                                             //~v10hI~
							{
								dbcssw=0;
								*ln2='.';
							}
					}
				}
          *ln1    =*(trt+(*pcdata>>4));      /*first 4 bit*/
          *(ln1+1)=*(trt+(*pcdata & 0x0000000F));/*last 4*/ 
        }

        ln1+=2;                          /*hex part */      
        ln2++;                           /*char part*/      
        pc++;                          /*next source byte*/ 
      }                                  /*dumpwidth loop*/
		if (dbcssw)
		{
#ifdef DOS                                                         //~v1.4I~
    #ifdef DPMI					//DPMI version                     //~v1.7R~
	 		pcdata=(UCHAR*)area+(ULONG)pc-(ULONG)addr;             //~v1.7R~
    #else                       //not DPMI                         //~v1.7R~
			pcdata    =(UCHAR*)area+(UINT)(pc-FLATADDR(addr));     //~v1.4I~
    #endif                      //DPMI or not                      //~v1.7R~
#else                                                              //~v1.4I~
	 		pcdata=(UCHAR*)area+(ULONG)pc-(ULONG)addr;
#endif                                                             //~v1.4I~
			*ln2=*pcdata;
		}
		else
			*ln2='*';
      putline(Line,Linewidth+1);        //print not same line with crlf
    }//not same line
  }                                   /*loop by max*/       
}//end of printdump

//********************************************************************
//* print line output
//*   input:
//*     p1 : line buffer
//*     p2 : output length,if 0 p1 is null terminating string
//*   output:
//*     print output
//********************************************************************

void putline(UCHAR* line,UINT len)                                 //~v1.4R~
{
  UINT  skipno;  //preceding cr count                              //~v1.4R~
  UINT  count;   //real write length                               //~v1.4R~
  UINT  leno;    //original length                                 //~v1.4R~
  UINT  i;                                                         //~v1.4R~
  UCHAR *start;
  UCHAR endchar;   //terminating char save
//*************************
  if (!Outputfh) return;
//*************************************
//* chk preceding cr when page change *
//*************************************
  start=line;
  if (!(count=len))
    count=strlen(start);
  leno=count;  //save original len

  for (skipno=0;skipno<count;(skipno++,Lineno++,start++))
    if (*start!='\n')
      break;
//******      
  if (Lineno>Maxline)
  {
    Lineno=1;
    count-=skipno;
    Pageno++;          
    sprintf(Header2+Pagepos,"%05d%n \n\n",Pageno,&i); 
    *(Header2+Pagepos+i)=' ';                
    fputs(Header1,Outputfh);
    fputs(Header2,Outputfh);
  }
  else
    start=line;//full line print
//***************************************    
//* ignore trailinf cr when page change *
//***************************************    
	i=count;                                                       //~vafcI~
  if (skipno!=leno) //not all cr
    for (i=count;i>0;(i--,Lineno++))
      if (*(start+i-1)!='\n')
        break;
  if (Lineno>Maxline)
    count=i;      

  if (count)
  {
    endchar=*(start+count);  //save end char;
    *(start+count)=0;        //set terminater
    fputs(start,Outputfh);
    *(start+count)=endchar;  //recov end char
  }

}//end of putline

//********************************************************************
//* error msg output and exit
//*   input:
//*     p1    :exit code,exit program if not 0
//*     p2    :printf patern
//*     p3-p12:edit parameter(max 10 edit parm)
//*   output:
//*     standard error output
//********************************************************************

void putmsg(int exitcode,UCHAR *patern,...)
{
  ULONG i;            //work                                       //~v1.4R~
  UCHAR *pc;         //work
  UCHAR errmsg[1024];      //for lineput                           //~v1.3R~
#if defined(DOS) || defined(W32)                                   //~v1.4I~
    ULONG arg[10];                                                 //~v1.3R~
    va_list ap;                                                    //~v1.3R~
#endif                                                             //~v1.3R~
//**************
  sprintf(errmsg,"\n%s-%s:",PGMID,VER);
#if defined(DOS) || defined(W32)                                   //~v1.4I~
    va_start(ap,patern);                                           //~v1.3R~
    for (i=0;i<10;i++)                                             //~v1.3R~
    	arg[i]=va_arg(ap,ULONG);                                   //~v1.3R~
    va_end(ap);                                                    //~v1.3R~
	sprintf(errmsg+strlen(errmsg),patern,                          //~v1.3R~
          	arg[0],arg[1],arg[2],arg[3],arg[4],                    //~v1.3R~
			arg[5],arg[6],arg[7],arg[8],arg[9]);                   //~v1.3R~
#else                                                              //~v1.3R~
  sprintf(errmsg+strlen(errmsg),patern,
          *(&patern+1), //edit parm 1
          *(&patern+2), //edit parm 2
          *(&patern+3), //edit parm 3
          *(&patern+4), //edit parm 4
          *(&patern+5), //edit parm 5
          *(&patern+6), //edit parm 6
          *(&patern+7), //edit parm 7
          *(&patern+8), //edit parm 8
          *(&patern+9), //edit parm 9
          *(&patern+10));//edit parm 10
#endif                                                             //~v1.3R~
  fprintf(stderr,"%s",errmsg);
//*output to outfile also
  for (pc=errmsg,i=1;i;pc+=i)
  {
    i=(ULONG)strchr(pc,'\n');                                      //~v1.4R~
    putline(pc,(UINT)(i=(i)?(i-(ULONG)pc+1):(strlen(pc))));        //~v1.4R~
  }

  if (exitcode)
    exit(exitcode);//terminate
}//endof putmsg
/******************************************************************/
