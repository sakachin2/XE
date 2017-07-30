//CID://+va66R~:             update#=    2                         //~va66R~
//***********************************************************
//* XLIBH.c : print ordinal and imported name                      //~v122R~
//*           for MS-OMF and MS !<arch> LIB                        //~v122I~
//***********************************************************
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//xlibh.c*v123 *050515 allow /s option as 1st parm                 //~v123I~
//xlibh.c*v122 *000529 bug of OMF object lib                       //~v122I~
//xlibh.c*v121 *000520 format option for xda parm file(/Fm____)    //~v121I~
//xlibh.c*v1.2 *000520 vc++v4 support(get ordno from vc6 lib)      //~v1.2R~
//xlibh.c*v1.1 *000429 windows archived import lib support (!<arch> file)//~v1.1I~
//              (from MFC v6.0 dumpbin & link logic)               //~v1.1I~
//**********************************************/
//*
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#if defined(DOS) || defined(W32)
	#include <dos.h>
    #ifdef DPMI
    	#include <errno.h>
    #endif
    #ifdef W32                                                     //~v123I~
    	#include <windows.h>                                       //~v123R~
    #endif                                                         //~v123I~
#else
    #define INCL_DOSFILEMGR  //DCPY_EXISTING
    #include <os2.h>
#endif

//*********************************************************************
#include <ulib.h>
#include <uque.h>
#include <ufile.h>
#include <uerr.h>
#include <udbcschk.h>
#include <uedit.h>
#include <udaimage.h>                                              //~v1.2R~
#include <ustring.h>                                               //~v121I~
//*********************************************************************
#define VER "V1.2"   //version                                     //~v1.2R~
#define PGM "XLIBH"                                                //~v1.1I~
#define IFHSZ      IMAGE_SIZEOF_FILE_HEADER                        //~v1.2I~
#define DBLKSZ   	512           //directory block size           //~v122M~
#define DBLKMAXENT  36           	//max entryno in directory block//~v122M~
//*********************************************************************//~v1.1I~
#pragma pack(1)    /* Force byte alignment */
typedef struct _LIBHDR {
							UCHAR  LHrectype;
#define LHRT_LIB	 0xf0
							USHORT LHreclen;                       //~9801R~
							ULONG  LHdiroffset;
							USHORT LHdirpageno;                    //~9801R~
							UCHAR  LHflag;
#define LHF_CASE	 0x01						//case sensitive
						} LIBHDR,*PLIBHDR;
#define LIBHDRSZ sizeof(LIBHDR)
                                                                   //~9801I~
typedef union  _LIBDIR {                                           //~9801I~
							UCHAR  LDoffs[DBLKMAXENT];             //~v122R~
							UCHAR  LDnospaceid;                    //~v122I~
                            union  _LDNP    {                      //~9801I~
                        						struct _LDN {      //~9801I~
                            								UCHAR	LDNlen;//~v122R~
                            								UCHAR 	LDNname;//~9801I~
                                                			} ldn; //~9801I~
                                                USHORT LDNpageno;  //~9801I~
                                            }	ldnp;              //~9801I~
						} LIBDIR,*PLIBDIR;                         //~9801I~
//objrec                                                           //~9801I~
typedef struct _LIBREC {                                           //~9801R~
							UCHAR  LRtype;                         //~9801I~
#define LRT_MODHDR    0x80                                         //~9801I~
#define LRT_MODEND    0x8a                                         //~9801I~
#define LRT_MODEND2   0x8b                                         //~v122I~
#define LRT_COMMENT   0x88                                         //~9801I~
                            USHORT LRlen;                          //~9801I~
                        	UCHAR  LRdata[1];                      //~9801I~
#define LRT_COM_CLASS_IMPORT_EXPORT 0xa0    //class                //~v122R~
#define LRT_COM_SUBTYPE_IMPORT 0x01   //subtype                    //~v122R~
#define LRT_COM_CLASS_LIBMOD   0xa3                                //~v122R~
						} LIBREC,*PLIBREC;                         //~9801I~
                                                                   //~v1.1I~
//import name table                                                //~v121I~
typedef struct _ORDLIST {                                          //~v121I~
							struct _ORDLIST *OLnext;               //~v121I~
							ULONG            OLordno;              //~v121I~
							UCHAR            OLnmlen;              //~v121I~
							UCHAR            OLname[1];            //~v121I~
                        } ORDLIST,*PORDLIST;                       //~v121I~
#define ORDLISTSZ     sizeof(ORDLIST)                              //~v121I~
#pragma pack()
//*********************************************************************
#define BUFFSZ   	256         //directory block size             //~v122R~
                                                                   //~9801I~
static UCHAR Sfnm[_MAX_PATH];                                      //~9801R~
static	FILE *Sfh;                                                 //~9801R~
static  int Spgsz;                                                 //~9801I~
static char *Spgm=PGM,*Sver=VER;                                   //~v1.1I~
static int Ssortopt;                                               //~v121I~
static PORDLIST Spol;                                              //~v121I~
//*********************************
FILE *openfile(char *Pfile,char *Popt,int Pmsgsw);                 //~9801M~
ULONG seekread(int Pseekopt,void *Pbuff,ULONG Poffs,ULONG Plen,UCHAR *Perrmsg);//~9801I~
void objproc(UCHAR *Pllname,ULONG Poffs);                          //~9801I~
int  winarchproc(UCHAR *Pdllnm,int *Ppver);                        //~v121R~
DWORD winarchvc4(IMAGE_ARCHIVE_MEMBER_HEADER *Ppamh,               //~v1.2I~
				IMPORT_OBJECT_HEADER *Ppafh,                       //~v1.2I~
				UCHAR *Poutbuff,int Poutbufflen);                  //~v121R~
int winarchsortout(int Pentno,UCHAR *Pdllnm,int Pver);             //~v121R~
//*********************************************************************
int main(int parmc,char *parmp[])
{
int mainproc(void);
	int rc;
    struct tm* plocaltime;       //local time  940609a             //~v121I~
  	time_t stck;                 //stck value del 940609a          //~v121I~
//**********************
    if (parmc<2)
    {
	    printf("%s:%s:==%c==  Print LIB Import Info ==\n",Spgm,Sver,OSTYPE);//~v121R~
	    printf("       %s Filename [/S] \n",Spgm);                 //~v122R~
	    printf("          /S:Sort by ordinal number (window !<arch> file only)\n");//~v121I~
        exit(4);
    }
    strcpy(Sfnm,parmp[1]);                                         //~9801R~
	if (parmc==3)                                                  //~v121I~
    {                                                              //~v121I~
    	if (!stricmp(parmp[2],"/S"))                               //~v121I~
        	Ssortopt=1;                                            //~v121I~
        else                                                       //~v121I~
    	if (!stricmp(parmp[1],"/S"))                               //~v123I~
        {                                                          //~v123I~
    		strcpy(Sfnm,parmp[2]);                                 //~v123I~
        	Ssortopt=1;                                            //~v123I~
        }                                                          //~v123I~
        else                                                       //~v123I~
        	uerrexit("Option err(%s)",0,                           //~v121I~
            			parmp[2]);                                 //~v121I~
    }                                                              //~v121I~
    rc=mainproc();
    time(&stck);					                               //~v121I~
    plocaltime=localtime(&stck);	                               //~v121R~
	printf("#%s:%s:==%c== End of process = %04d/%02d/%02d ==\n",Spgm,Sver,OSTYPE,//~v121R~
            plocaltime->tm_year+1900,plocaltime->tm_mon+1,plocaltime->tm_mday);//~v121I~
	return rc;
}//main

//*********************************************************************
//* process LIB file
//*********************************************************************
int mainproc(void)
{
    LIBHDR  libh;                                                  //~9801I~
    int     ii,outctr,dblkno,ordcnt,linkver;                       //~v121R~
    UCHAR   *pc,*pce,*pc0,*pllname;                                //~9801R~
    UCHAR   drec[DBLKSZ];                                          //~9801I~
    UCHAR   dllnm[20];                                             //~v121I~
    ULONG   diroffs,objoffs;                                       //~9801I~
    UCHAR   archid[IMAGE_ARCHIVE_START_SIZE];                      //~v1.1R~
//*****************************
	Sfh=openfile(Sfnm,"rb",0);	//exit when open fail              //~9801R~
                                                                   //~v1.1I~
    seekread(SEEK_SET,archid,0,sizeof(archid),"Arch Hdr ID Record");//~v1.1R~
    if (!memcmp(archid,IMAGE_ARCHIVE_START,sizeof(archid)))//? !<arch>\n//~v1.1R~
    {                                                              //~v121I~
    	ordcnt=winarchproc(dllnm,&linkver);                        //~v121R~
        if (!ordcnt)                                               //~v121I~
        	return 4;                                              //~v121I~
    	return winarchsortout(ordcnt,dllnm,linkver);               //~v121R~
    }                                                              //~v121I~
//**process MS OMF format                                          //~v122R~
    seekread(SEEK_SET,(void*)&libh,0,sizeof(libh),"LIB Hdr Record");//~9801R~
    if (libh.LHrectype!=LHRT_LIB)                                  //~9801R~
    	uerrexit("%s is not valid LIB file",0,
					Sfnm);                                         //~9801R~
	Spgsz=libh.LHreclen+3;                                         //~9801R~
	dblkno=libh.LHdirpageno;                                       //~9801I~
	diroffs=libh.LHdiroffset;                                      //~9801R~
//                                                                 //~9801R~
	outctr=0;                                                      //~9801I~
    for (ii=0;ii<dblkno;ii++,diroffs+=DBLKSZ)                      //~9801R~
    {
	    seekread(SEEK_SET,drec,diroffs,DBLKSZ,"LIB Dictionary Block");//~9801R~
    	for (pc0=pc=drec,pce=pc+DBLKMAXENT;pc<pce;pc++)            //~v122R~
        {                                                          //~9801I~
        	if (!*pc)                                              //~v122I~
            	continue;                                          //~v122I~
        	pllname=pc0+(*pc<<1);	//name entry addr              //~9801R~
            objoffs=(ULONG)(*(USHORT*)(void*)(pllname+*pllname+1))*Spgsz;//~v122R~
            objproc(pllname,objoffs);                              //~9801I~
            outctr++;                                              //~9801I~
        }                                                          //~9801I~
    }
    printf ("total %d\n",outctr);                                  //~9801R~
    return 0;
}//mainproc
//**********************************************************************//~9801I~
//* opject proce                                                   //~9801I~
//* parm1:ll+name                                                  //~9801I~
//* parm2:object offset                                            //~9801I~
//* return:none                                                    //~9801I~
//**********************************************************************//~9801I~
void objproc(UCHAR *Ppllname,ULONG Poffs)                          //~9801I~
{                                                                  //~9801I~
    PLIBREC  plibr;                                                //~9801R~
    ULONG    offs;                                                 //~9801I~
    UINT     reclen,readlen,ordno;                                 //~v122R~
    UCHAR    *pc,*pchk;                                            //~v122R~
    int      rtype,ordflag,importsw;                               //~v122R~
    UCHAR    buff[BUFFSZ];                                         //~v122I~
    UCHAR    pllfunc[BUFFSZ],pllxfunc[BUFFSZ],plldll[BUFFSZ],plllib[BUFFSZ];//~v122I~
//****************                                                 //~9801I~
    plibr=(PLIBREC)(void*)buff;                                    //~v122R~
	seekread(SEEK_SET,buff,Poffs,(ULONG)Spgsz,"Object 1st Page");  //~v122R~
    rtype=(int)plibr->LRtype;                                      //~9801I~
    reclen=(UINT)(plibr->LRlen+3);      //record len               //~v122I~
    if (rtype!=LRT_MODHDR)                                         //~9801I~
        uerrexit("Object hdr record type err,offset=%08lx for %.*s",0,//~9801R~
        			Poffs,*Ppllname,Ppllname+1);                   //~9801R~
	offs=Poffs+reclen;                                             //~v122R~
    strcpy(pllfunc,"\x07Unknown");                                 //~v122R~
    strcpy(pllxfunc,pllfunc);                                      //~v122I~
    strcpy(plllib,pllfunc);                                        //~v122I~
    strcpy(plldll,pllfunc);                                        //~v122I~
    for(ordno=0,importsw=0;;)                                      //~v122R~
    {                                                              //~9801I~
		seekread(SEEK_SET,buff,offs,(ULONG)Spgsz,"record hdr-1");  //~v122I~
	    rtype=(int)plibr->LRtype;                                  //~v122M~
	    if (rtype==LRT_MODEND||rtype==LRT_MODEND2)                 //~v122M~
        	break;                                                 //~v122M~
                                                                   //~v122I~
    	reclen=(UINT)(plibr->LRlen+3);		//record len           //~9A03R~
        readlen=min(reclen,BUFFSZ);                                //~v122I~
		seekread(SEEK_SET,buff,offs,(ULONG)readlen,"record hdr-2");//~v122I~
        offs+=reclen;                                              //~v122I~
        	                                                       //~9801I~
        pc=plibr->LRdata;                                          //~9801I~
        switch (rtype)                                             //~9801I~
        {                                                          //~9801I~
	    case LRT_COMMENT:                                          //~9801I~
        	pc++;			//skip class                           //~v122R~
        	switch(*pc)		//class                                //~v122R~
            {                                                      //~9801I~
            case LRT_COM_CLASS_IMPORT_EXPORT:                      //~v122R~
                pc++;                                              //~v122I~
            	if (*pc++!=LRT_COM_SUBTYPE_IMPORT)//subtype        //~v122R~
                	break;                                         //~v122I~
//import record ord-flag,internal-name,module-name,entry-id        //~v122I~
				importsw=1;                                        //~v122I~
				ordflag=*pc++;                                     //~v122I~
                memcpy(pllfunc,pc,(UINT)(*pc+1));                  //~v122R~
                pc+=*pc+1;                                         //~v122I~
                memcpy(plldll,pc,(UINT)(*pc+1));                   //~v122R~
                pc+=*pc+1;                                         //~v122I~
                if (ordflag)	//import by ordinal                //~v122I~
                	ordno=(UINT)*(USHORT*)(void*)pc;               //~v122R~
                else                                               //~v122I~
                	if (*pc)	//exported name by dll mod         //~v122I~
		                memcpy(pllxfunc,pc,(UINT)(*pc+1));         //~v122R~
                    else                                           //~v122I~
		                memcpy(pllxfunc,pllfunc,(UINT)(*pllfunc+1));//~v122R~
                break;                                             //~9801I~
            case LRT_COM_CLASS_LIBMOD:	//class                    //~v122R~
            	pc++;                                              //~v122I~
            	memcpy(plllib,pc,(UINT)(*pc+1));			//skip class//~v122R~
                break;                                             //~9801I~
            }//comment class                                       //~v122R~
        	break;                                                 //~9801I~
        }//rtype                                                   //~v122I~
	}//all record                                                  //~9801I~
//print risult                                                     //~v122I~
	if (!importsw)                                                 //~v122I~
	    printf ("Offset=%08x;Not Imported API :%.*s\n",Poffs,*Ppllname,Ppllname+1);//~v122R~
    else                                                           //~v122I~
    {                                                              //~v122I~
    	if (ordno)                                                 //~v122R~
        	printf ("    %-8.*s.%5d=%.*s\n",                       //~v122R~
            	    *plldll,plldll+1,ordno,*pllfunc,pllfunc+1);    //~v122R~
    	else                                                       //~v122R~
    	{                                                          //~v122R~
			if (memcmp(pllfunc,pllxfunc,*pllfunc))                 //~v122I~
    			pchk="!=";                                         //~v122I~
            else                                                   //~v122I~
            	pchk="==";                                         //~v122I~
        	printf ("    %-8.*s:%.*s %s\n",                        //~v122R~
                	*plldll,plldll+1,*pllfunc,pllfunc+1,pchk);//~v122R~//+va66R~
	    }                                                          //~v122I~
    }                                                              //~v122I~
}//objproc                                                         //~9801I~
//**********************************************************************//~v1.1I~
//* windows !<arch> file process                                   //~v1.1I~
//*   list ordno and symbol                                        //~v1.1I~
//* return:ordno count                                             //~v121R~
//**********************************************************************//~v1.1I~
int winarchproc(UCHAR *Pdllnm,int *Ppver)                          //~v121R~
{                                                                  //~v1.1I~
    IMAGE_ARCHIVE_MEMBER_HEADER amh,amh2;                          //~v121R~
    IMPORT_OBJECT_HEADER afh;                                      //~v1.1R~
    IMAGE_FILE_HEADER afh2;                                        //~v121I~
	IMAGE_OPTIONAL_HEADER ioh;                                     //~v121I~
    int		  symlen,len;		                                   //~v121R~
    long      amhptsz,amhno,ii,ordcount=0,maxord=0;                //~v1.1R~
    ULONG     *pamhpt,*pamhpt0; 	    	//memh ptr tbl         //~v1.1I~
    ULONG     offs;                                                //~v1.1I~
#define MAXDATASZ    512                                           //~v1.1I~
    UCHAR     data[MAXDATASZ],*psym,*psymo,*pc;                    //~v121R~
    UCHAR     dlln[32];                                            //~v121I~
    PORDLIST pol;                                                  //~v121I~
//****************                                                 //~v1.1I~
    printf ("# !<arch> file ordinal number listing --- %s\n",Sfnm);//~v121R~
//Top reccord:data is cont and ptr to memb record entry            //~v1.1R~
//    data is count and ptr to memb record entry                   //~v1.1I~
//    then symbol string is followed                               //~v1.1I~
	seekread(-1,&amh,0,sizeof(amh),"Top Member Hdr");//top record is memb hdr ptr tbl//~v1.1R~
    if (memcmp(amh.Name,IMAGE_ARCHIVE_LINKER_MEMBER,sizeof(amh.Name)))// "/    "//~v1.1R~
		uerrexit("!<arch> file top header err;name is not /",0);   //~v1.1I~
    amhptsz=atol(amh.Size);      //data size                       //~v1.1R~
    if (!amhptsz)                                                  //~v1.1I~
		uerrexit("!<arch> File Top Header;data size=0",0);         //~v1.1I~
    if (!(pamhpt0=malloc((UINT)amhptsz)))	//memb hdr ptr tbl     //~v121R~
		uerrexit("!<arch> File Top Header;malloc failed(szie=%ld)",0,//~v1.1I~
				amhptsz);                                          //~v1.1I~
	seekread(-1,pamhpt0,0,(ULONG)amhptsz,"Top Member Data");//top record is memb hdr ptr tbl//~v121R~
	amhno=(LONG)USTRLOAD(pamhpt0);		//count is big endian      //~v121R~
    if (!amhno)						//count is big endian          //~v1.1R~
		uerrexit("!<arch> File Top Header err;member count=0",0);  //~v1.1R~
	psym=(UCHAR*)(void*)(pamhpt0+amhno+1);	//followed string tbl  //~v1.1R~
//*get version from 3rd member                                     //~v121R~
	seekread(SEEK_CUR,&amh2,(ULONG)(amhptsz%2),sizeof(amh),"2nd Member Hdr");//2 byte boundary//~v121R~
    amhptsz=atol(amh2.Size);      //data size                      //~v121I~
	seekread(SEEK_CUR,&amh2,(ULONG)amhptsz,sizeof(amh),"3rd Member Hdr");//top record is memb hdr ptr tbl//~v121R~
	seekread(SEEK_CUR,&afh2,(ULONG)(amhptsz%2),sizeof(afh),"File Hdr of 3rd");//2 byte boundary//~v121R~
	if (afh2.SizeOfOptionalHeader)                                 //~v121R~
    {                                                              //~v121M~
		seekread(-1,&ioh,0,sizeof(ioh),"Optional Hdr of 3rd");	//after member hdr//~v121R~
        *Ppver=(ioh.MajorLinkerVersion<<8)+ioh.MinorLinkerVersion; //~v121R~
    }                                                              //~v121M~
    else                                                           //~v121I~
    	*Ppver=0;                                                  //~v121I~
//chk other member                                                 //~v121R~
	ordcount=0;                                                    //~v1.1I~
    for(ii=0,pamhpt=pamhpt0+1;ii<amhno;ii++,pamhpt++)              //~v1.1R~
    {                                                              //~v1.1I~
//  	printf("======%s\n",psym);                                 //~v1.1R~
    	symlen=(int)strlen(psym);                                  //~v1.1I~
        psymo=psym;	                                               //~v1.1I~
        psym+=symlen+1;                                            //~v1.1I~
        if (memcmp(psymo,"__imp_",6))   //not imp record           //~v121R~
            continue;                                              //~v121R~
    	offs=USTRLOAD(pamhpt);		//offset is big endian         //~v1.1R~
		seekread(SEEK_SET,&amh,offs,sizeof(amh),"Member Hdr");     //~v1.1R~
		seekread(-1,&afh,0,sizeof(afh),"File Hdr");	//after member hdr//~v1.1R~
        if (afh.Sig1==IMAGE_FILE_MACHINE_UNKNOWN                   //~v1.2R~
        &&  afh.Sig2==IMPORT_OBJECT_HDR_SIG2)   //import object hdr//~v1.2R~
        {                                                          //~v1.2I~
    //      if (afh.Type!=IMPORT_OBJECT_CODE)                      //~v1.2R~
    //          continue;                                          //~v1.2R~
//          if (afh.NameType!=IMPORT_OBJECT_ORDINAL)               //~v121R~
#ifdef OS2     //see udaimage and winnt.h ;diff in IMPORT_OBJECT_HEADER//~v123R~
            if (NameType(afh.NameType_Type)!=IMPORT_OBJECT_ORDINAL)//~v121I~
#else                                                              //~v123I~
            if (afh.NameType!=IMPORT_OBJECT_ORDINAL)               //~v123I~
#endif                                                             //~v123I~
                continue;                                          //~v1.2R~
            if (afh.SizeOfData>MAXDATASZ)                          //~v1.2R~
                continue;                                          //~v1.2R~
            seekread(-1,data,0,afh.SizeOfData,"File Data"); //after member hdr//~v1.2R~
        }                                                          //~v1.2I~
        else        //chk for vc4                                  //~v1.2I~
        {                                                          //~v1.2I~
            if (!(afh.Ordinal=(USHORT)winarchvc4(&amh,&afh,data,sizeof(data))))//~v121R~
                continue;                                          //~v1.2R~
        }                                                          //~v1.2I~
        if (Ssortopt)                                              //~v121I~
        {                                                          //~v121I~
        	len=(int)strlen(data);                                 //~v121R~
            if (pc=umemmem(data,"@@",(UINT)len,2),pc)              //~v121R~
//              len=(int)((ULONG)pc-(ULONG)data);                  //~va66R~
                len=(int)((ULPTR)pc-(ULPTR)data);                  //~va66I~
            pol=(PORDLIST)malloc(ORDLISTSZ+(UINT)len);             //~v121R~
            pol->OLnmlen=(UCHAR)len;                               //~v121I~
            pol->OLordno=afh.Ordinal;                              //~v121I~
            pol->OLnext=Spol;       //chain previous               //~v121I~
            memcpy(pol->OLname,data,(UINT)len);                    //~v121R~
            Spol=pol;                                              //~v121I~
        }                                                          //~v121I~
        else                                                       //~v121I~
			printf(" %5d  : %s\n",afh.Ordinal,data);               //~v121R~
   		memcpy(dlln,amh.Name,16);                                  //~v121I~
    	*(dlln+16)=0;                                              //~v121I~
    	if ((pc=strpbrk(dlln,"./")),pc)                            //~v121R~
    		*pc=0;                                                 //~v121R~
    	strcpy(Pdllnm,dlln);                                       //~v121I~
		if (maxord<afh.Ordinal)                                    //~v1.1R~
			maxord=afh.Ordinal;                                    //~v1.1R~
        ordcount++;                                                //~v1.1I~
	}//all record                                                  //~v1.1I~
    if (!Ssortopt||!ordcount)                                      //~v121R~
	    printf ("\n#Total %ld ordinal, max ordinal=%ld\n",ordcount,maxord);//~v121R~
    return ordcount;                                               //~v121R~
}//winarchproc                                                     //~v1.1R~
//**********************************************************************//~v1.2I~
//* windows !<arch> file process for linker version 4              //~v1.2I~
//* file position is after filehdr                                 //~v1.2I~
//* return:ordno                                                   //~v1.2I~
//**********************************************************************//~v1.2I~
DWORD winarchvc4(IMAGE_ARCHIVE_MEMBER_HEADER *Ppamh,               //~v1.2I~
				IMPORT_OBJECT_HEADER *Ppafh,                       //~v1.2I~
				UCHAR *Poutbuff,int Poutbufflen)                   //~v121R~
{                                                                  //~v1.2I~
	IMAGE_FILE_HEADER *pifh;                                       //~v1.2I~
	IMAGE_SECTION_HEADER *pish;                                    //~v1.2I~
	IMAGE_SYMBOL *pisym;                                           //~v1.2R~
	IMAGE_RELOCATION   *pir;                                       //~v1.2I~
#define MAXMEMBDATALEN 4096                                        //~v1.2I~
	UCHAR     membdata[MAXMEMBDATALEN];                            //~v1.2R~
	UCHAR     *pistrt;                                             //~v121R~
    ULONG     ordno,thunkordno;                                    //~v1.2I~
    int ii,sectno,symindex,membdatalen,len;                        //~v121R~
//****************                                                 //~v1.2I~
	if ((membdatalen=atoi(Ppamh->Size))>sizeof(membdata))          //~v1.2I~
    {                                                              //~v1.2I~
    	uerrmsg("Too large member(%s)",0,                          //~v1.2I~
        		Ppamh);                                            //~v1.2I~
		return 0;                                                  //~v1.2I~
    }                                                              //~v1.2I~
	pifh=(IMAGE_FILE_HEADER*)(void*)membdata;                      //~v1.2R~
	*pifh=*(IMAGE_FILE_HEADER*)(void*)Ppafh;	//copy already read file hdr//~v1.2I~
	seekread(-1,membdata+IFHSZ,0,(ULONG)(membdatalen-IFHSZ),"Member data");//top record is memb hdr ptr tbl//~v121R~
//  pish=(IMAGE_SECTION_HEADER*)(ULONG)(membdata+IFHSZ+pifh->SizeOfOptionalHeader);//~va66R~
    pish=(IMAGE_SECTION_HEADER*)(ULPTR)(membdata+IFHSZ+pifh->SizeOfOptionalHeader);//~va66I~
    sectno=(int)pifh->NumberOfSections;                            //~v1.2I~
    symindex=0;                                                    //~v121R~
    ordno=0;                                                       //~v121I~
    for (ii=0;ii<sectno;ii++,pish++)                               //~v1.2I~
    {                                                              //~v1.2I~
    	if (!strcmp(pish->Name,".text"))                           //~v1.2I~
        {                                                          //~v1.2I~
        	if (!pish->NumberOfRelocations                         //~v1.2R~
        	||  pish->NumberOfRelocations>1)                       //~v1.2I~
            {                                                      //~v1.2I~
            	uerrmsg("reloc cnt!=1 for %s of %s",0,             //~v1.2I~
                		pish->Name,Ppamh);                         //~v1.2I~
            	break;                                             //~v1.2I~
			}                                                      //~v1.2I~
//          pir=(IMAGE_RELOCATION*)((ULONG)pifh+pish->PointerToRelocations);//~va66R~
            pir=(IMAGE_RELOCATION*)((ULPTR)pifh+pish->PointerToRelocations);//~va66I~
            symindex=(int)pir->SymbolTableIndex;   //smbol tbl index(1 base)//~v121R~
        }                                                          //~v1.2I~
    	if (!memcmp(pish->Name,".idata",6))	                       //~v1.2I~
        {                                                          //~v1.2I~
        	if (!symindex)                                         //~v1.2R~
            	break;                                             //~v1.2I~
            if (pish->SizeOfRawData!=4)                            //~v1.2I~
            {                                                      //~v1.2I~
            	uerrmsg("rawdata size!=4 for %s of %s",0,          //~v1.2I~
                		pish->Name,Ppamh);                         //~v1.2I~
            	break;                                             //~v1.2I~
			}                                                      //~v1.2I~
//          thunkordno=*(ULONG*)(void*)((ULONG)pifh+pish->PointerToRawData);//~va66R~
            thunkordno=*(ULONG*)(void*)((ULPTR)pifh+pish->PointerToRawData);//~va66I~
            if (!thunkordno & 0x80000000)	//not thunk chain      //~v1.2R~
            {                                                      //~v1.2I~
            	uerrmsg("import by funcname for %s",0,             //~v1.2I~
                		Ppamh);                                    //~v1.2I~
            	break;                                             //~v1.2I~
			}                                                      //~v1.2I~
            ordno=thunkordno & 0x7fffffff;                         //~v1.2R~
            break;                                                 //~v1.2I~
        }                                                          //~v1.2I~
    }                                                              //~v1.2I~
    if (!ordno)                                                    //~v1.2I~
    	return 0;                                                  //~v1.2I~
//search funcname                                                  //~v1.2I~
//  pisym=(IMAGE_SYMBOL*)((ULONG)pifh+pifh->PointerToSymbolTable); //~va66R~
    pisym=(IMAGE_SYMBOL*)((ULPTR)pifh+pifh->PointerToSymbolTable); //~va66I~
//  pistrt=(UCHAR*)(ULONG)(pisym+pifh->NumberOfSymbols);//to is len fld//~va66R~
    pistrt=(UCHAR*)(ULPTR)(pisym+pifh->NumberOfSymbols);//to is len fld//~va66I~
	pisym+=symindex;                                               //~v1.2R~
    if (pisym->N.Name.Short)	//top DWORD=0 means offset in string table//~v1.2R~
    {                                                              //~v1.2I~
        uerrmsg("ordno import string seach err for %s of %s",0,    //~v1.2I~
                pish->Name,Ppamh);                                 //~v1.2I~
        return 0;                                                  //~v1.2I~
    }                                                              //~v1.2I~
    pistrt+=pisym->N.Name.Long;  //offset in string table          //~v1.2R~
    if (!memcmp(pistrt,"__imp_",6))                                //~v1.2I~
    	pistrt+=6;		//drop __imp_                              //~v1.2I~
    len=(int)strlen(pistrt);                                       //~v121R~
    if (len>=Poutbufflen)                                          //~v121R~
    {                                                              //~v1.2I~
        uerrmsg("Too long string(%s) of %s",0,                     //~v1.2I~
                pistrt,Ppamh);                                     //~v1.2I~
        return 0;                                                  //~v1.2I~
    }                                                              //~v1.2I~
    memcpy(Poutbuff,pistrt,(UINT)len);                             //~v121R~
    *(Poutbuff+len)=0;                                             //~v1.2I~
    return ordno;                                                  //~v1.2I~
}//winarchvc4                                                      //~v1.2I~
//**********************************************************************//~v121I~
//* sort ordno list                                                //~v121I~
//*  return code: -1: ent1<ent2                                    //~v121I~
//*                0: ent1=ent2                                    //~v121I~
//*                1: ent1>ent2                                    //~v121I~
//**********************************************************************//~v121I~
int winarchsortbyord(const void *Pent1,const void *Pent2)          //~v121I~
{                                                                  //~v121I~
//*****************                                                //~v121I~
	return  (int)((*(PORDLIST*)Pent1)->OLordno-(*(PORDLIST*)Pent2)->OLordno);//~v121R~
}//winarchsortbyord                                                //~v121I~
//**********************************************************************//~v121I~
//* sortout arch file function by ordno                            //~v121I~
//* return:rc                                                      //~v121I~
//**********************************************************************//~v121I~
int winarchsortout(int Pentno,UCHAR *Pdllnm,int Pver)              //~v121R~
{                                                                  //~v121I~
	PORDLIST pol,*ppol,*ppol0;                                     //~v121I~
    int ii;                                                        //~v121I~
//****************                                                 //~v121I~
	if (!Ssortopt||!Pentno)                                        //~v121R~
    	return 0;                                                  //~v121I~
//create ptr list                                                  //~v121I~
	ppol0=(PORDLIST*)malloc((UINT)Pentno*4);                       //~v121R~
    pol=Spol;                                                      //~v121I~
    for (ppol=ppol0,ii=0;ii<Pentno;ii++,ppol++)                    //~v121I~
    {                                                              //~v121I~
		*ppol=pol;                                                 //~v121I~
        pol=pol->OLnext;                                           //~v121I~
    }                                                              //~v121I~
//sort                                                             //~v121I~
    qsort(ppol0,(UINT)Pentno,4,winarchsortbyord);                  //~v121I~
//output                                                           //~v121I~
    printf("#############################################################\n");//~v121I~
    printf("DLL=%-12s     ##   total-entry=%3d linker-version=%d.%d #\n\n",//~v121R~
            Pdllnm,Pentno,Pver>>8,Pver & 255);                     //~v121R~
    for (ppol=ppol0,ii=0;ii<Pentno;ii++,ppol++)                    //~v121I~
    {                                                              //~v121I~
		pol=*ppol;                                                 //~v121I~
		printf("  %5d=%.*s\n",pol->OLordno,(int)pol->OLnmlen,pol->OLname);//~v121I~
    }//all dlln tbl                                                //~v121I~
    printf("##### end of DLL(%-12s) total %d  #####\n",            //~v121R~
            Pdllnm,Pentno);                                        //~v121R~
    return 0;                                                      //~v121I~
}//winarchsortout                                                  //~v121I~
//**********************************************************************
//* open file name
//* parm1:open file name
//* parm2:open option
//* parm3:msg sw 0:no opened msg,1:display opened msg,-1:return if open err
//**********************************************************************
FILE *openfile(char *Pfile,char *Popt,int Pmsgsw)
{
	FILE *file;
//****************
	if (!(file=fopen(Pfile,Popt)))
    	if (Pmsgsw==-1)
        	return 0;
        else
			uerrexit("%s open failed rc=%d",0,
					Pfile,errno);
	if (Pmsgsw==1)
    	printf("%s opened.",Pfile);
	return file;
}//openfile
//**********************************************************************//~9801I~
//*read input file                                                 //~9801I~
//* parm1:seek opt -1:no seek                                      //~v1.1R~
//* parm2:out area                                                 //~9801I~
//* parm3:offset                                                   //~9801I~
//* parm4:len                                                      //~9801I~
//* parm5:err msg when short len,if 0 return short len             //~9801I~
//* ret  :read len                                                 //~9801I~
//**********************************************************************//~9801I~
ULONG seekread(int Pseekopt,void *Pbuff,ULONG Poffs,ULONG Plen,UCHAR *Perrmsg)//~9801I~
{                                                                  //~9801I~
	ULONG readlen;                                                 //~9801I~
    UCHAR *errmsg;                                                 //~9801I~
static ULONG Scpos;                                                //~v121I~
//****************                                                 //~9801I~
//printf("seekread before %08x\n",Scpos);                          //~v121R~
	if (!(errmsg=Perrmsg))                                         //~9801I~
    	errmsg="";                                                 //~9801I~
//  if (Pseekopt)                                                  //~v1.1R~
	if (Pseekopt>=0)                                               //~v1.1I~
    {                                                              //~v121I~
        if (fseek(Sfh,(LONG)Poffs,Pseekopt))                       //~9A03R~
            uerrexit("%s seek failed rc=%d,offset=%08lx,opt=%d(%s)\n",0,//~9801I~
                            Sfnm,errno,Poffs,Pseekopt,errmsg);     //~9801I~
        if (Pseekopt==SEEK_SET)                                    //~v121I~
        	Scpos=Poffs+Plen;                                      //~v121I~
        else                                                       //~v121I~
        if (Pseekopt==SEEK_CUR)                                    //~v121I~
        	Scpos+=Poffs+Plen;                                     //~v121I~
    }                                                              //~v121I~
    else                                                           //~v121I~
        Scpos+=Plen;                                               //~v121I~
    readlen=fread(Pbuff,1,Plen,Sfh);	//read 1 block             //~9801I~
//printf("read=%08x,req=%08x\n",readlen,Preqsz);                   //~9801I~
    if (readlen<Plen)                                              //~9801I~
    {                                                              //~9801I~
		if (ferror(Sfh))                                           //~9801R~
        	uerrexit("\n%s read failed rc=%d,pos=%08lx(seekopt=%d),reqlen=%08lx,read=%08lx(%s)",0,//~9801I~
						Sfnm,errno,Poffs,Pseekopt,Plen,readlen,errmsg);//~9801I~
        if (Perrmsg)                                               //~9801I~
        	uerrexit("%s's size is too short for %s;reqlen=%08lx from +%08lx(seekopt=%d),readlen=%08lx",0,//~9801I~
    					Sfnm,Perrmsg,Plen,Poffs,Pseekopt,readlen); //~9801I~
    }                                                              //~9801I~
//printf("seekread after  %08x\n",Scpos);                          //~v121R~
	return readlen;                                                //~9801I~
}//seekread                                                        //~9801I~
