// ******************************************************************
// *ｿ-ｽ･ﾌｧｲﾙ名 : DLLHDR.C
// * 機能概要   : batch program:extract ordinary# and api from DLL file
// * 関数       : main
// *              parm1 : input file spec
// *              option: /S:x sort option
// *                         x=O ordinary#(default)
// *                         x=A object# and offset
// *                         x=N API name
// *                      /L:n max line per page(default 58 lines)
// *                      /W:n dll header size by KB(enough read size which
// *                           contain object table,resident name table,
// *                           no resident name table,entry table)
// *                           default is 32KB.
// **********************************************/
// * 変更履歴   :
// *     日付       担当者        変更内容
#define VER    "V1.2"           //version
// *v1.2 93/11/12 : a.s         : treate 286callgate af 16bit offset
// *v1.1 93/11/12 : a.s         : bug when group name not found on bseord.h
// *v1.0 93/08/23 : a.s         : first virsion
// *******************************************************************

#define INCL_DOSFILEMGR     //Dos i/o
#define INCL_DOSEXCEPTIONS  //c.b about exception handle
#include <os2.h>

#define  DWORD long         //for exe386.h,newexe.h
#define  WORD  short        //for exe386.h,newexe.h
#define  EXE386 1           //avoid duplicated symbol define for newexe.h
#include <newexe.h>         //load module hdr ZM....
#include <exe386.h>         //load module hdr LX....

//#define __MIG_LIB__         //for read/fstat
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//********************************************************************

#define PGMID  "DLLHDR"      //program id

#define IOBUFFSZ  32          //default ioarea size 32kb
#define MAXLINE   60           //default line per page
#define SORTTYPE  'O'          //default sort type
#define SORTTYPE2 'O'          //default sub sort type when main is name order
#define HEADERFILE "f:\\toolkt21\\c\\os2h\\bseord.h" /*default header file*///~9117R~
#define OUTPUTFILE "PRN"                             /*default output file*/
#define RECSIZE  256  

//*******************************************************************
typedef struct _APITBL {
                          short  APIordno;//ordinary no
                          UCHAR  APInameflag;//resident/nores/else
                          UCHAR  APInamelen ;//name string length
                          UCHAR  APIname[33];//name
                   struct b32_bundle APIbundle;//type,objectno
                   struct e32_entry  APIentry; //flag,offset
                        } APITBL;
typedef APITBL* PAPITBL;

typedef  struct _RETENT {
                          short       RETordno;   //ordinaryno
                  struct  b32_bundle* RETpbundle; //bundle entry ptr
                  struct  e32_entry * RETpentry;  //entry ptr
                        } RETENT;
typedef RETENT* PRETENT;

//***********

int  compare(const void*,const void*);
RETENT  getentry(short);          //get entry table information from DLL
UCHAR*  getname(PVOID,short);     //search (non)resident name table
long    fileio(ULONG,long,long,PVOID);//file read
void    putline(UCHAR*,ULONG);          //write to stdout
void    putmsg(int,UCHAR*,...);         //1 line print   
UCHAR*  nametbl_fromh(UCHAR*);//create name tbl from BSEORD.H etc

//***********

static int    Maxline=MAXLINE;   //maxline per page
static UCHAR  Sorttype=SORTTYPE;   //data read length
static UCHAR  Sorttype2=SORTTYPE2;   //data read length
static UCHAR*Headerfname=HEADERFILE; 
static UCHAR*Outputfname=OUTPUTFILE; 
static UCHAR*Bufferend;          //to chk buffer overflow
static FILE*  Outputfh;           //output file handle

static long   Currpos=0;         //file current pos
static int    Lineno;            //lineno in page
static int    Pageno=0;          //pageno
static int    Pagepos;           //page edit position on header line
static int    Inputfsize;        //input file size
static HFILE  Inputfh;           //input file handle
static struct e32_exe* Pe32_exe;        //32 bit exe hdr ptr
static struct exe_hdr* Pexe_hdr;        //exe hdr ptr

static UCHAR *Inputfname;        //input filename
static UCHAR Header1 [133]=" ";  //page title
static UCHAR Header2[]="ORD#(HEX )  APINAME                         -RES \
EXP SHR PARM#  OBJ#-ADDRESS       TYPE\n";

static UCHAR Line_format[]="%4d(%4.4X)  %-32.32s-%c   \
%c   %c   %5d  %4d-%-13.13s %s\n";

static UCHAR Line    [133];      //print line
//*******************************************************************

int main(ULONG parmc,UCHAR *parmp[])
{
  int    iobuffsz=IOBUFFSZ;   //data read length
  int    readlen;
  int      i,j,k;              //work
  APIRET apiret;               //Dos call r.c
  ULONG  openact;              //DosOpen parm
  int    maxapitbl;            //max apitbl entry#
  int    posparmno=0;          //positional parmno
  short  maxordno;             //maximum ordinaryno
  UCHAR  *pch;                 //char ptr work
  UCHAR  *nametbl_h;           //name table from header file
  struct tm* plocaltime;       //local time
  time_t stck;                 //stck value del
  FILESTATUS3 fstatus;         //file status by DosQueryFileInfo v1.3 add
  PAPITBL papitbl,papitbltop;  //APITBL entry ptr
  struct o32_obj* po32_obj;    //object table entry addr
  PVOID  piobuff;
  RETENT retent;               //getentry output
  UCHAR dllname[33];           //dllname from dll entry
  UCHAR line_res[4];           //name source edit
  UCHAR line_offset[14];       //offset edit
  UCHAR line_type  [10];       //entry type edit
  UCHAR line_exported  ;       //exported id edit
  UCHAR line_shared    ;       //shared data id edit

//*******************************************************************
  Lineno=Maxline+1;             //first time hdr print
//**************************
//* parameter chk          *
//**************************

  if (parmc<2||*parmp[1]=='?')
  {
    putmsg(4,"IN-file [OUT-file(%s)] [HEADER-file(%s)]\n\
                    [/S:sort-type(%c)] [/L:lines/page(%d)] [/W:worksz(%d)]\n\
                    sort-type O-by ordinal number\n\
                              A-by address(objectno and offset)\n\
                              NO-by API name+ordinal number\n\
                              NA-by API name+address\n",
               OUTPUTFILE,HEADERFILE,SORTTYPE,MAXLINE,IOBUFFSZ);
  }
  for (k=1;k<parmc;k++)
  {
    pch=parmp[k];
    if( (*pch=='/'||*pch=='-') && (*(pch+2)==':') )
    {//option
      switch( *(pch+1) )    //
      {
//**************************
//* sort type              *
//**************************
      case 's':
      case 'S':
        switch( *(pch+3) )    //
        {
        case 'o':
        case 'O':
          Sorttype=Sorttype2=(UCHAR)toupper(*(pch+3));
          break;
        case 'a':
        case 'A':
          Sorttype=Sorttype2=(UCHAR)toupper(*(pch+3));
          break;
        case 'n':
        case 'N':
          Sorttype=(UCHAR)toupper(*(pch+3));
          switch( *(pch+4) )    //second sort key
          {
          case 'o':
          case 'O':
          case 'a':
          case 'A':
            Sorttype2=(UCHAR)toupper(*(pch+4));
            break;
          default:
            putmsg(4,"invalid sub sort type option \"%s\"\n",pch);
          }//switch by sort type
          break;
        default:
          putmsg(4,"invalid sort type option \"%s\"\n",pch);
        }//switch by sort type
        break;
//**************************
//* line per page          *
//**************************
      case 'l':
      case 'L':
        for (i=0;i<strlen(pch+3);i++)
        {
		  if ( !isdigit( *(pch+i+3) ) )
   		    putmsg(4,"option L(line per page) \"%s\" is not numeric\n",pch);
        }
		Maxline=atoi(pch+3);
        if (!Maxline) Maxline=0x0fffffff;
          break;
//**************************
//* work size              *
//**************************
      case 'w':
      case 'W':
        for (i=0;i<strlen(pch+3);i++)
        {
		  if ( !isdigit( *(pch+i+3) ) )
            putmsg(4,"option W(worksz) \"%s\" is not numeric\n",pch);
        }
		if (atoi(pch+3))//number
          iobuffsz=atoi(pch+3);//by KB
        break;

      default:
        putmsg(4,"invalid option keyword \"%s\"\n",pch);
      }//switch by option
	}//option
    else//positional aprm
    {
//**************************
//* parm1:input file name  *
//**************************
      ++posparmno;
      switch (posparmno)
      {
      case  1:
        Inputfname=pch;      //input file name ptr
        break;
      case  2:
        if (*pch!=',')
          Outputfname=pch;   //output file name ptr
        break;
      case  3:
        if (*pch!=',')
          Headerfname=pch;   //header file name ptr
        break;
      default:
        putmsg(4,"too many positional parameter(other than IN,OUT,HEADER)");
        break;
      }
    }//pos parm
  }//loop by parm count

//**************************
//* initialize             *
//**************************
//********
//* file *
//********
  apiret=DosOpen(Inputfname,&Inputfh,&openact,0L,FILE_NORMAL,
           OPEN_ACTION_FAIL_IF_NEW|OPEN_ACTION_OPEN_IF_EXISTS,
           OPEN_SHARE_DENYWRITE|OPEN_ACCESS_READONLY,0L);
  if(apiret)
  {
    putmsg(4,"input file:\"%s\" open err,rc=%d\n",Inputfname,apiret);
  }
//***file status
  apiret=DosQueryFileInfo(Inputfh,FIL_STANDARD,&fstatus,sizeof fstatus);
  if(apiret)
    putmsg(4,"input file:\"%s\" status get failed,rc=%d\n",
             Inputfname,apiret);

  Outputfh=fopen(Outputfname,"w");
  if(!Outputfh)
    putmsg(4,"output file:\"%s\" openfailed\n",Outputfname);
//********
//* work *
//********

  Inputfsize=(long)fstatus.cbFile;

  readlen=min(max(iobuffsz,1)*1024,Inputfsize);
  piobuff=malloc((ULONG)readlen);
//**hdr line
  sprintf(Header1,
          "\f%50.50s (%02d-%02d-%02d %02d:%02d) PAGE=%n%05d \n",
          Inputfname,
          (fstatus.fdateLastWrite.year+80)%100,                    //+0213R~
          fstatus.fdateLastWrite.month,
          fstatus.fdateLastWrite.day,
          fstatus.ftimeLastWrite.hours,
          fstatus.ftimeLastWrite.minutes,
          &Pagepos,
          0);
  for (i=1;i<sizeof(Header1);i++)
    if (Header1[i]!=' ')
      break;
  for (j=1;j<i-1;j++)
    Header1[j]='*';

//**************************
//* process start          *
//**************************

  putmsg(0,"++++++++++ process start ; Input=%s,\n\
                         %d line per page,\n\
                         Sorttype=%c(%c),Worksize=%d KB\n",
          Inputfname,Maxline,Sorttype,Sorttype2,iobuffsz);

//**************
//* read dll   *
//**************

  for (;;)
  {
    if (fileio(FILE_BEGIN,0,readlen,piobuff)<=0)
      putmsg(4,"input file:\"%s\" read err\n",
                Inputfname);

    Pexe_hdr=piobuff;
    if (Pexe_hdr->e_magic!=EMAGIC)
      putmsg(4,"input file:\"%s\" invalid hdr record id(not %c%c)\n",
                Inputfname,EMAGIC%256,EMAGIC/256);

    Pe32_exe=(struct e32_exe*)(PVOID)((ULONG)Pexe_hdr+Pexe_hdr->e_lfanew);
    if (*(ULONG*)(PVOID)&Pe32_exe->e32_magic!=E32MAGIC)
      putmsg(4,"input file:\"%s\" invalid 386hdr record id(not %c%c)\n",
                Inputfname,E32MAGIC%256,E32MAGIC/256);

    if (!Pe32_exe->e32_nrestab)//no resident name tbl exist
      break;
    if (Pe32_exe->e32_nrestab+Pe32_exe->e32_cbnrestab<=readlen)
      break;            //e32_nrestab is offset from file top
    readlen=(int)(Pe32_exe->e32_nrestab+Pe32_exe->e32_cbnrestab);
    free(piobuff);
    piobuff=malloc((ULONG)readlen);
  }//until buff ok

  Bufferend=(PVOID)((ULONG)piobuff+readlen);//overflow addr
   
//****************
//* get dll name *
//****************
  memset(dllname,0,sizeof(dllname));
  pch=(PVOID)((ULONG)Pe32_exe+Pe32_exe->e32_restab);//res name top
  if (*pch>=sizeof(dllname))//string len
    memcpy(dllname,pch+1,sizeof(dllname)-1);
  else
    memcpy(dllname,pch+1,*pch);

  nametbl_h=nametbl_fromh(dllname);//create api name table from header file

//*****************************
//* get number of ordno entry *
//*****************************
  for (k=0;;k++)//until all ordno
  {
    retent=getentry(0);      //request next ordno entry
    if(!(retent.RETordno))   //end of table
      break;
    maxordno=retent.RETordno;
  }//get max entryno
  maxapitbl=k;
  papitbltop=malloc((ULONG)maxapitbl*sizeof(APITBL));

//*****************************
//* create APITBL            **
//*****************************
  for (k=0,papitbl=papitbltop;k<maxapitbl;k++,papitbl++)//all ordno
  {
    retent=getentry(0); //request next ordno entry
    papitbl->APIordno=retent.RETordno;
    papitbl->APIbundle=*(retent.RETpbundle);//cnt,type,objectno
    papitbl->APIentry=*(retent.RETpentry);//flag,offset

    papitbl->APInameflag=' ';  
    papitbl->APInamelen=0;//string len
    memset(papitbl->APIname,sizeof(papitbl->APIname),0);

    pch=NULL;
    if (Pe32_exe->e32_restab) //resident name table exist
      pch=getname((PVOID)((ULONG)Pe32_exe+Pe32_exe->e32_restab),
                  papitbl->APIordno);//resident name tbl search
    if (pch)
    {
      papitbl->APInameflag='R';
      papitbl->APInamelen=*pch;//string len
    }//on resident name table

    if (!pch) //not on resname tbl
    {
      if (Pe32_exe->e32_nrestab) //non-resident name table exist
        pch=getname((PVOID)((ULONG)piobuff+Pe32_exe->e32_nrestab),
                    papitbl->APIordno);//non-resident name tbl search
      if (pch)
      {
        papitbl->APInameflag='N';
        papitbl->APInamelen=*pch;//string len
      }//on resident name table
    }//not on resname tbl

    if (nametbl_h)            //fond on bseord.h a931112
      if (!pch) //not on resname/non-resname 
      {
        pch=getname(nametbl_h,papitbl->APIordno);//header file name search
        if (pch)
        {
          papitbl->APInameflag='h';
          papitbl->APInamelen=*pch;//string len
        }
      }

    if (papitbl->APInamelen>=sizeof(papitbl->APIname))//string len
      papitbl->APInamelen=sizeof(papitbl->APIname)-1;//cut name string

    memcpy(papitbl->APIname,pch+1,papitbl->APInamelen);
    
  }//all ordno

  putmsg(0,"++++++++++ \"%s\" has %d entries(max ord-no is %d)\n",
           dllname,maxapitbl,maxordno);

//*****************************
//* sort APITBL              **
//*****************************
  qsort(papitbltop,(ULONG)maxapitbl,sizeof(APITBL),compare);
//*****************************
//* print APITBL             **
//*****************************
  for (k=0,papitbl=papitbltop;k<maxapitbl;k++,papitbl++)//all ordno
  {
    po32_obj=(struct o32_obj*)(PVOID)
              ((ULONG)Pe32_exe+Pe32_exe->e32_objtab);//objtab top addr
    po32_obj+=(B32_OBJ(papitbl->APIbundle)-1);//that objno entry
    switch (B32_TYPE(papitbl->APIbundle)&(~TYPEINFO))
    {
    case ENTRY16:
      sprintf(line_offset,"%08X",
              po32_obj->o32_base+E32_OFFSET16(papitbl->APIentry));
      strcpy(line_type,"offset16");
      break;
    case GATE16:
//    sprintf(line_offset,"%04X:%04X",                 v1.2del
//            E32_GATE(papitbl->APIentry),//selector   v1.2del
//            E32_GATEOFF(papitbl->APIentry));//offset v1.2del
      sprintf(line_offset,"%08X:%04X",                          //v1.2add
              po32_obj->o32_base+E32_GATEOFF(papitbl->APIentry),//v1.2add
              E32_GATE(papitbl->APIentry));//selector            v1.2add
      strcpy(line_type,"callgate");
      break;
    case ENTRY32:
      sprintf(line_offset,"%08X",
              po32_obj->o32_base+E32_OFFSET32(papitbl->APIentry));
      strcpy(line_type,"offset32");
      break;
    case ENTRYFWD:
      sprintf(line_offset,"%04X:%08X",
              E32_MODORD(papitbl->APIentry),E32_VALUE(papitbl->APIentry));
      strcpy(line_type,"fowarder");
      break;
    }//endswitch by type

    if (E32_EFLAGS(papitbl->APIentry) & E32EXPORT)
	  line_exported='Y';
	else  
	  line_exported=' ';

    if (E32_EFLAGS(papitbl->APIentry) & E32SHARED)
	  line_shared='Y';
	else  
	  line_shared=' ';

    line_res[0]=papitbl->APInameflag;
    line_res[1]=0;

    sprintf(Line,Line_format,
            papitbl->APIordno, //decimal
            papitbl->APIordno, //hex
            papitbl->APIname,  //APIname
            papitbl->APInameflag, //res/nores/header
            line_exported,
            line_shared,
            E32_EFLAGS(papitbl->APIentry)/8,
            B32_OBJ(papitbl->APIbundle),
            line_offset,
            line_type);
    putline(Line,0);

  }//all ordno

//****************************************
//* termination                          *
//****************************************
  apiret=DosClose(Inputfh);

  time(&stck);
  plocaltime=localtime(&stck);
  putmsg(-1,"++++++++++ Input file:\"%s\" process completed;\n\
                       %d pages output at %s\n",
          Inputfname,Pageno,asctime(plocaltime));
  putline("\f",0);//form feed
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

int  compare(const void* entry1,const void* entry2)
{
  PAPITBL   p1,p2;
  UCHAR     save_sort_type;
  int  rc;         //compare result
//*************************
  p1=(PAPITBL)entry1;
  p2=(PAPITBL)entry2;
  switch(Sorttype)    //
  {
  case 'O':  //by ordno
    rc=p1->APIordno - p2->APIordno;
    break;
  case 'A':  //by object#+offset
    rc=B32_OBJ(p1->APIbundle) - B32_OBJ(p2->APIbundle);
    if (!rc)
    {
      rc=(B32_TYPE(p1->APIbundle)&(~TYPEINFO))
         -(B32_TYPE(p1->APIbundle)&(~TYPEINFO));
      if (!rc)//not same type
      {
        switch (B32_TYPE(p1->APIbundle)&(~TYPEINFO))
        {
        case ENTRY16:
          rc=E32_OFFSET16(p1->APIentry) - E32_OFFSET16(p2->APIentry);
          break;
        case GATE16:
          rc=E32_GATE(p1->APIentry) - E32_GATE(p2->APIentry);
          if (!rc)
            rc=E32_GATEOFF(p1->APIentry) - E32_GATEOFF(p2->APIentry);
          break;
        case ENTRY32:
          rc=(int)(E32_OFFSET32(p1->APIentry) - E32_OFFSET32(p2->APIentry));
          break;
        case ENTRYFWD:
          rc=E32_MODORD(p1->APIentry) - E32_MODORD(p2->APIentry);
          if (!rc)
          rc=(int)(E32_VALUE(p1->APIentry) - E32_VALUE(p2->APIentry));
          break;
        }//endswitch by type
      }//type equal
    }//objectno equal
    break;
  case 'N':  //by name
    rc=memcmp(p1->APIname,p2->APIname,sizeof(p1->APIname));
    if (!rc) //null name
    {
      save_sort_type=Sorttype;
      Sorttype=Sorttype2;
      rc=compare(entry1,entry2);//compare by sub sort key
      Sorttype=save_sort_type;
    }
    break;
  }//switch by sort type

  return rc;

}//end of compare

//********************************************************************
//* entry table search sub                                           *
//*   input:
//*     p1:request ordinary no
//*          if 0,sequential access
//*   output:
//*     retent structure(ordno,bundle ptr,entry ptr)
//*     if not found, ordno=0
//********************************************************************

RETENT getentry(short parm_ordno)
{
static struct b32_bundle* Cpbundle;//current bundle addr
static short       Cbundle_ordno=0;//curent bundle start ordno
static short       Centry_ordno=0; //curent entry ordno

  short   ordno;
  short   entrylen;                //entry size by bundle type
  RETENT retent;
//*******************************************************
  if (!(ordno=parm_ordno))         //sequential access
    ordno=(short)(Centry_ordno+1); //previous+1

  if (  !Cbundle_ordno            //first time
      ||ordno<Cbundle_ordno)      //direct before current bundle entry
  {
    Cpbundle=(struct b32_bundle*)(PVOID)
              ((ULONG)Pe32_exe+Pe32_exe->e32_enttab);
    Cbundle_ordno=Centry_ordno=1;
  }

  retent.RETordno=0;              //initialize by not found
  while(Cpbundle->b32_cnt)        //until end of table
  {
//*****************
//* entry size    *
//*****************
    switch (Cpbundle->b32_type & ~TYPEINFO)
    {
    case EMPTY:
      entrylen=0;
      break;
    case ENTRY16:
      entrylen=FIXENT16;
      break;
    case GATE16:
      entrylen=GATEENT16;
      break;
    case ENTRY32:
      entrylen=FIXENT32;
      break;
    case ENTRYFWD:
      entrylen=FWDENT;
      break;
    default:
      putmsg(4,"input file:\"%s\" invalid bundle type(file offset=+%08X)\n",
               Inputfname,
                 (ULONG)Cpbundle-(ULONG)Pexe_hdr);
    }//endswitch by type

    if (ordno<(Cbundle_ordno+Cpbundle->b32_cnt)) //in the current bundle
    {
      if (!entrylen)                 //dummy bundle(un-used ordno)
        if (parm_ordno)              //direct access
          break;                     //not found
        else                         //seq access
          ordno=(short)(Cbundle_ordno+Cpbundle->b32_cnt);//next bundle start ordno
      else                           //not dummy entry
      {
        retent.RETordno=ordno;       //founded ordno for found id
        break;
      }//current bundle is empty or else
    }//in the current bundle

    Centry_ordno=Cbundle_ordno=(short)(Cbundle_ordno+Cpbundle->b32_cnt);
    if (!entrylen)                   //dummy bundle(un-used ordno)
      Cpbundle=(struct b32_bundle*)(PVOID)
	           ((ULONG)Cpbundle+sizeof(struct b32_bundle)
			    -sizeof(Cpbundle->b32_obj));
    else                             //not dummy bundle
      Cpbundle=(struct b32_bundle*)(PVOID)
	           ((ULONG)Cpbundle+sizeof(struct b32_bundle)
	            +Cpbundle->b32_cnt*entrylen);
    if ((ULONG)Cpbundle+sizeof(struct b32_bundle)>=(ULONG)Bufferend)
      putmsg(4,"specify more Work size to contain entry table");
    
  }//while all bundle entry
  if (!Cpbundle->b32_cnt && !parm_ordno)//seq,end of table
    Cbundle_ordno=Centry_ordno=0;       //next start from top

  if (retent.RETordno)//found
  {
    Centry_ordno=ordno;
    retent.RETpbundle=Cpbundle;
    retent.RETpentry=(struct e32_entry*)((ULONG)Cpbundle+sizeof(struct b32_bundle)
                                         +entrylen*(ordno-Cbundle_ordno));
    if ((ULONG)retent.RETpentry+sizeof(struct e32_entry)>=(ULONG)Bufferend)
      putmsg(4,"specify more Work size to contain entry table");
  }//found
  return retent;
}//end of getentry

//********************************************************************
//* resident/non-resident name table search                          *
//*   input:
//*     p1:table top addr(following format)
//*               UCHAR  stringlen
//*               UCHAR  string[stringlen]
//*               short  ordno
//*     p2:request ordno
//*   output:
//*     name table entry ptr
//*     if not found,return null
//********************************************************************

UCHAR* getname(PVOID parm_nametbl,short parm_ordno)
{
  UCHAR*  pc;
//*******************************************************
  pc=parm_nametbl;
  while(*pc)                         //until end of table
  {
    if (*(short*)(PVOID)(pc+*pc+1)==parm_ordno)//found
      return pc;
    pc+=*pc+3;
  }//all name tbl
  return NULL;                       //not found

}//end of getentry

//********************************************************************
//* file read sub                                                    *
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

long  fileio(ULONG origin,long offset,long len,void* addr)
{
  APIRET apiret;
  ULONG  newpos;
  ULONG  retlen;
  long  readlen;
//*******************************************************
  if (origin!=FILE_CURRENT || offset) //not current pos
  {
    apiret=DosSetFilePtr(Inputfh,offset,origin,&newpos);
    if(apiret)
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

  retlen=0;
  apiret=DosRead(Inputfh,addr,(ULONG)len,&retlen);
  readlen=(long)retlen;

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
}//end of fileread

//********************************************************************
//* print line output
//*   input:
//*     p1 : line buffer
//*     p2 : output length,if 0 p1 is null terminating string
//*   output:
//*     print output
//********************************************************************

void putline(UCHAR* line,ULONG len)
{
  ULONG skipno;  //preceding cr count
  ULONG count;   //real write length
  ULONG leno;    //original length
  ULONG i;
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
    sprintf(Header1+Pagepos,"%05d%n \n",Pageno,&i);
    *(Header1+Pagepos+i)=' ';
    fputs(Header1,Outputfh);
    fputs(Header2,Outputfh);
  }
  else
    start=line;//full line print
//***************************************
//* ignore trailinf cr when page change *
//***************************************
  if (skipno!=leno) //not all cr
    for (i=count;i>0;(i--,Lineno++))
      if (*(start+i-1)!='\n')
        break;
  if (Lineno>Maxline)
    count=i+1;               //only 1 cr

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
//*     p1    :exit code,exit program if not 0,-1
//*     p2    :printf patern
//*     p3-p12:edit parameter(max 10 edit parm)
//*   output:
//*     standard error output
//*     standard output if exitcode<0
//********************************************************************

void putmsg(int exitcode,UCHAR *patern,...)
{
  ULONG i;            //work
  UCHAR *pc;         //work
  UCHAR errmsg[512];      //for lineput
//**************
  sprintf(errmsg,"\n%s-%s:",PGMID,VER);
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
  fprintf(stderr,"%s",errmsg);
//*output to outfile also
  if (exitcode<0) 
    for (pc=errmsg,i=1;i;pc+=i)
    {
      i=(ULONG)strchr(pc,'\n');
      putline(pc,i=(i)?(i-(LONG)pc+1):(strlen(pc)));
    }

  if (exitcode && exitcode!=-1)
    exit(exitcode);//terminate

}//endof putmsg

//********************************************************************
//* create name table from os2 header file                           *
//*   input:
//*     p1:dll file name
//*   output
//*     name table(following format) ptr
//*               UCHAR  stringlen
//*               UCHAR  string[stringlen]
//*               short  ordno
//*     if not found,return null
//********************************************************************

UCHAR* nametbl_fromh(UCHAR* parm_dllname)
{
 
UCHAR* dllcardchk(UCHAR*);
UCHAR* defcardchk(UCHAR*,short*);
int    readrec(FILE*,UCHAR*);


 struct _alias_list{
		    UCHAR dllname[33]; //key coresponding to parm_dllname
		    UCHAR aliasid[33]; //alias id string on header file
		    };
  static struct _alias_list    
      alias_list[]={
		    "DOSCALL1","DOSCALLS"
		   };
  UCHAR   *pc;
  UCHAR   *nametbl,*nametbltop;
  UCHAR   *dllname;
  int     aliasmax;
  int     tblsz=0;
  int     reclen;          //header file read record length
  int     startrec=0,endrec; //card position 
  FILE*   headerfh;       //header file handle 
  int     i,k;
  short   ordno;
  UCHAR   ioarea[RECSIZE];
//*******************************************************
  aliasmax=sizeof(alias_list)/sizeof(struct _alias_list);
  dllname=parm_dllname;
  for (i=0;i<aliasmax;i++)  //search alias table
    if (!strcmp(dllname,alias_list[i].dllname))
    {
      dllname=alias_list[i].aliasid;
      break;
    }

  headerfh=fopen(Headerfname,"r");  //default \toolkt20\c\os2h\bseord.h
  if (!headerfh)
    putmsg(4,"header file \"%s\" open failed",Headerfname);
//********************
//* count entry      *
//********************

  for (k=0;;k++)                     //until eof or next alias id found
  {
    reclen=readrec(headerfh,ioarea);   //read ascii record
    if (reclen<0)                    //eof
      break;                         
      
    pc=dllcardchk(ioarea);           //alias card chk
    if (pc)
      if (!strcmp(pc,dllname))
        startrec=k+1;                //#define card chec start position
      else
     	if (startrec)                //already dll card found
	      break;
    if (startrec)
    {
      pc=defcardchk(ioarea,&ordno);
      if (pc)
    	tblsz+=(int)strlen(pc)+3;         //table size
    }
  }//loop by k

  if (!startrec)                    //not found    a931112
    return NULL;                    //not found    a931112

  endrec=k-1;                       //last record no of the dll

//*****************
//* create tbl    *
//*****************
  nametbltop=nametbl=malloc((ULONG)(++tblsz)); 

  fseek(headerfh,0,SEEK_SET);         //file position to file start
  for (k=0;k<startrec;k++)
    readrec(headerfh,ioarea);

  for (;k<=endrec;k++)               //until eof or next alias id found
  {
    reclen=readrec(headerfh,ioarea);
    pc=defcardchk(ioarea,&ordno);
    if (pc)
    {
      *(nametbl++)=(UCHAR)strlen(pc);
      strcpy(nametbl,pc);            //save api name
      nametbl+=strlen(pc);
      *(short*)(PVOID)nametbl=ordno;
      nametbl+=sizeof(short);
    }
  }//loop by k
  *nametbl=0;                        //end of table id
  return nametbltop;

}//name table from header

//********************************************************************
//* check alias card
//*   input:
//*     p1:ascii record area
//*   output
//*     alias name string pointer
//*        ex /* xxxxxx */ ,return ptr to xxxxxx\0
//*     if not such format,return null
//********************************************************************

UCHAR* dllcardchk(UCHAR* ioarea)
{
  int     i;
//*******************************************************
  if (memcmp(ioarea,"/* ",3))
    return NULL;

  i=(int)strcspn(ioarea+3," ");      //blank search
  if (!i)                            // "/*  " not "/* x"
    return NULL;

  if (memcmp(ioarea+3+i," */",4))    //compair including \n
    return NULL;

  *(ioarea+3+i)=0; //null terminater
  return ioarea+3;
} //end of dllcardchk

//********************************************************************
//* define ordno record chk
//*   input:
//*     p1:ascii record area
//*     p2:ordno return area
//*   output
//*     API name string pointer
//*        ex #define ORD_XXXXXX  NN 
//*            return ptr to XXXXXX\0
//*                   ordno NN
//*     if not such format,return null
//********************************************************************

UCHAR* defcardchk(UCHAR* ioarea,short* pordno)
{
  UCHAR   *pc,*pc0;
//*******************************************************
  if (memcmp(ioarea,"#define ",3))
    return NULL;

  pc=ioarea+8;                 //non blank search
  pc+=strspn(pc," ");          //non blank search

  if (memcmp(pc,"ORD_",4))
    return NULL;

  pc0=(pc+=4);

  pc+=strcspn(pc," ");         //balnk search
  *(pc++)=0;

  if (!(*pordno=(short)atoi(pc)))
  {
    putmsg(-1,"#define card chk failed\n\
                       %s",ioarea);
    return NULL;
  }
    
  return pc0;
} //end of defordchk

//********************************************************************
//* ascii record read
//*   input:
//*     p1:FILE* (file handle)
//*     p2:ioarea
//*   output
//*     record length
//*     if eof return -1
//********************************************************************

int readrec(FILE* fh,UCHAR* ioarea)
{
  int     ch;
  int     i;
//*******************************************************
  for (i=0;i<RECSIZE-1;i++)
  {
    ch=fgetc(fh);             //1 byte read
    if (ch==EOF)
//    break;                            //d931112
      return -1;              //eof       a931112
    if (ch=='\n')             //cr(x'0d0a') 
      break;
    *(ioarea+i)=(UCHAR)ch;
  }
  
  *(ioarea+i)=0;              //null terminater 
  return i;
} //end of readrec

