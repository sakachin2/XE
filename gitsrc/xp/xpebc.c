//*CID://+v9e7R~:                             update#=  365;       //~v9e7R~
//***********************************************************
//* xpebc.c : ebcdic print                                         //~v953R~
//***********************************************************
//v9e7:170826 compiler warning                                     //~v9e7I~
//v9e5:170826 get dll suffix by uconv --version                    //~v9e5I~
//v9e2:170809 compiler warning(duplicate define in local variable) //~v9e0I~
//v9e0:170807 v9.38 tabchar support(tabon:c/x__/u__)               //~v9e0I~
//v9a1:160418 v9.33 LNX64 Compiler warning                         //~v9a1I~
//v997:160309 v9.32 (LNX)compiler warning                          //~v997I~
//v996:160309 v9.32 (BUG)utfdd2u buffsize parm is not ctr but size //~v996I~
//v994:160308 v9.32 W32 compiler warning                           //~v994I~
//v97J:131118 (BUG)xpr ** for ebc,lineno/cmtline shows ? for ascii //~v97JI~
//v97E:131118 print "." for SO/SI when dumpmode                    //~v97EI~
//v97x:131115 (BUG)ebc text mode split;contline is invalid(recorddumpcopyoffs is set only dump mode)//~v97xI~
//v96B:130810 record mode line length err when line contains 0x15  //~v96BI~
//v96z:130809 (BUG:LNX not gxp)EBCFILE ucs2local1 output utf8 when LANG=UTF8,ucvext_b2mDbcsstr cut by 2 byte each//~v96zI~
//            set EBCBYUCS(set dd to buff) and convert to utf8 at write//~v96zI~
//v96w:130807 lineno field is by ascii from xe(xpr **/***) for english small letter translation//~v96wI~
//v96s:130804 (BUG)"xpr **" for ebcfile hhex; b2dd twice           //~v96sI~
//v96r:130804 (BUG)"xpr **" for ebcfile hhex+vhex; vhexline length is same as hhex line len//~v96rI~
//v96q:130804 (BUG)"xpr **" for ebcfile from xe;nor crlf is controled//~v96qI~
//v96p:130803 (BUG)v9.25 -mxe(ebc hexdump) with -ns(no same chk);all space in char part print//~v96pI~
//v96n:130803 v9.25 Test option /ntu for test !EBCBYUCS            //~v96nI~
//v96m:130801 v9.25 Recordmode vhexdump print dbcs split           //~v96mI~
//v96i:130726 v9.25 add -EOLPRINT: option to identify eol of vfmt  //~v96iI~
//v96h:130726 v9.25 new -ICU option to support for EBC file on Windows//~v96hI~
//v96e:130724 v9.25 recfm=V(-Vvfmt) support                        //~v96eI~
//120629 v968 VC2010:LP64 support                                  //~v958I~
//100923 v956 v9.20 (BUG) "too long line" err msg when from xe(xpr ** for ebc vhex mode. /Me oprion ignored)//~v956I~
//100909 v955 v9.19 print EBC file by TextOutW for avoid print "?" for trans err to locale code//~v955I~
//100908 v953 v9.19 EBC convertername support                      //~v953I~
//100428 v941 v9.16 ebcdic print support                           //~0428I~
//*************************************************************
#                                                                  //~0428I~
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add
//*************************************************************

#include <ulib.h>
#include <ustring.h>
#include <uerr.h>
#include <ufile.h>
#include <udbcschk.h>                                              //~0428R~
#include <ucvebc.h>                                                //~0428I~
#include <ucvext.h>                                                //~v953I~
#include <ucvebc4.h>                                               //~v953I~
#include <ufile5.h>                                                //~v953I~
#include <utrace.h>                                                //~0428I~
#include <utf22.h>                                                 //~v955I~
#include <ualloc.h>                                                //~v96mI~
//*********************************************************************
#include  "xp.h"
#include  "xpebc.h"                                                //~0428I~
#include  "xpsub1.h"                                               //~v96eR~
#include  "xppf.h"                                                 //~v9e0I~
//*********************************************************************
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~0428M~
//*********************************************************************
extern int dbcsenv;           //dbcs environment sw v4.9a v7.23r   //~0428R~
extern int tabskip;                                                //~0429I~
extern int Gebcdictype;		//EBCDIC subtype 1:katakana,2:english small char//~0428R~
extern int recordsz;       	//input record length      	v6.7a      //~0429I~
extern int asciimode;        //char set id                     v2.5add//~0429I~
extern int dumpmode;         //dump mode default=text v2.8rep v6.7r//~0429I~
extern int prntyp;	//printer type(default ibm5577/ibm5575 etc) av4.5 v6.7r//~v955I~
extern int Gdatalinenosz;			//lineno data width in the file//~v956I~
extern int samechk;	      	//chk same as above      v6.7a         //~v827I~//~v96sI~
extern int hexdump;                                                //~v96kI~//~v97xI~
//*********************************************************************
static UCHAR Sebcbuff[MAX_EBC_TEXTINPLINESZ];                      //~0428R~
static UCHAR Sb2mbuff[MAX_EBC_TEXTINPLINESZ];                      //~0428R~
static UCHAR *Sb2ddrecordbuff;                                     //~v96mR~
static int Sb2ddrecordbuffsz;		                               //~v96mI~
//static int Sb2ddrecorducsctr;                                      //~v96mI~//~v96wR~
//static int Sb2ddrecordoffs;                                        //~v96mI~//~v96nR~
static UCHAR Sdddata[MAX_EBC_TEXTINPLINESZ];                       //~v955I~
static UCHAR Sb2mdbcstb[MAX_EBC_TEXTINPLINESZ];                    //~0428R~
static UCHAR Sb2mdbcstb2[MAX_EBC_TEXTINPLINESZ];                   //~0630I~
static int Scodepage[256];                                         //~0429I~
static char Sebccp[MAX_CSNAMESZ];      //ebcdic codepage           //~v953I~
static int Sprevoffs;                                              //~v955R~
static 	int Snextc;                                                //~v955I~
static 	int Soutddlen;	//xpebc_b2dd output                        //~v96mI~
static 	int Scopyedlen; //xpebc_b2dd output                        //~v97xI~
//*********************************************************************//~0428I~
int xpebc_b2m(int Popt,int Plen);                                  //~0428I~
#define XPEBCO_BIN       0x01                                      //~0428R~
#define XPEBCO_RECORD    0x02                                      //~v955I~
#define XPEBCO_ASCIILINENO   0x04                                  //~v96wR~
#define XPEBCO_ASCIICMTLINE  0x08                                  //~v96wI~
int xpebc_b2ddrecord(int Popt,UCHAR *Pebcbuff,int Pebclen); //full record translation//~v96mI~
int xpebc_b2ddrecord_copy(int Popt,UCHAR *Pebc,int Plen);          //~v96mI~
int xpebc_b2m_cmt(int Popt,char *Pbuff,int Plen);                  //~v96wI~
int xpebc_setdbcsspacealtch(int Popt,UCHAR *Ppdddata,UCHAR *Ppdddbcs,int Pddlen);//~v9e0I~
//**********************************************************************//~v953I~
//* get convertername parameter                                    //~v953I~
//**********************************************************************//~v953I~
int xpebc_getparmcvname(int Popt,char *Popd)                       //~v953I~
{                                                                  //~v953I~
	char *pc;                                                      //~v953I~
//*****************                                                //~v953I~
    if (!Popd)                                                     //~v953I~
    	*Sebccp=0;                                                 //~v953R~
    else                                                           //~v953I~
    {                                                              //~v953I~
        pc=Popd+sizeof(PARM_CPEB)-1;                               //~v953R~
        if (*pc==':'||*pc=='=')                                    //~v953R~
            pc++;                                                  //~v953R~
        if (*pc)                                                   //~v953R~
            UstrncpyZ(Sebccp,pc,sizeof(Sebccp));                   //~v953R~
    }                                                              //~v953I~
    return 0;                                                      //~v953I~
}//xpebc_getparmcvname                                             //~v953I~
//**********************************************************************
//* date parm get
//**********************************************************************
int xpebc_init(int Popt,char *Pcfgfnm)                                           //~0428R~//~0429R~//~v9e5R~
{
    int rc=0,opt;                                                      //~0428R~//~v953R~
//*****************                                                //~0428I~
    Gxpebchandle=0;                                                //~v953I~
	opt=UCVEBC3O_CFGFILE;                                          //~v953I~
    if (swsw5 & SW5USEICU)                                         //~v96hI~
    {                                                              //~v96hI~
        opt|=UCVEBC3O_USEICU;                                      //~v96hI~
      	Gucvebc_stat|=UCVEBCS_icutool;//from xprint                //~v96hI~
    }                                                              //~v96hI~
	if (!Pcfgfnm)                                                  //~0429I~
    {                                                              //~0429I~
    	if (Gebcdictype==3) //cfg file                                 //~0428I~//~0429R~
        {                                                          //~v9e5I~
		    if (swsw5 & SW5USEICU)    //use icu                    //+v9e7I~
      			Gucvebc_stat|=UCVEBCS_CONVERTERCFG;	//create cfg by uconv --version//~v9e5I~//+v9e7R~
//      	ucvebc3_init(opt,(ULONG*)(ULONG)Gebccfgfname);            //~0428R~//~0429R~//~0529R~//~v953R~
//        	ucvebc3_init(opt,(ULONG*)(ULONG)"");                   //~v953I~//~v958R~
        	ucvebc3_init(opt,(ULPTR*)(ULPTR)"");                   //~v958I~//~v9e7R~
        }                                                          //~v9e5I~
    }                                                              //~0429I~
    else                                                           //~0429I~
    {                                                              //~0429I~
    	if (!Gebccfgfname ||LFNM_STRCMP(Pcfgfnm,Gebccfgfname))     //~0429R~
        {                                                          //~0429I~
        	if (!Gebccfgfname)                                     //~0429I~
            	Gebccfgfname=malloc(strlen(Pcfgfnm)+1);            //~0429R~
	        strcpy(Gebccfgfname,Pcfgfnm);                          //~0429R~
		    if (*Gebccfgfname)                                     //~v953I~
    	    	opt|=UCVEBC3O_ERREXIT;                             //~v953R~
//	    	ucvebc3_init(opt,(ULONG*)(ULONG)Gebccfgfname);        //~0429I~//~0529R~//~v953R~//~v958R~
	    	ucvebc3_init(opt,(ULPTR*)(ULPTR)Gebccfgfname);         //~v958I~
        }                                                          //~0429I~
    }                                                              //~0429I~
    if (*Sebccp)                                                   //~v953I~
    {                                                              //~v953I~
    	if (Gebcdictype!=3)	                                       //~v953I~
        	uerrexit("%s option requires %cMec(EBCIDIC by external conveter) specification",0,//~v953R~
                      PARM_CPEB,CMDFLAG_PREFIX);                   //~v953I~
        if (ucvebc4_createhandle(0,Sebccp,&Gxpebchandle))          //~v953R~
            uerrexit("EBCDIC codepage error",0);                   //~v953I~
    }                                                              //~v953I~
	UCBITON(swsw4,SW4EBCCFG);                                      //~0428I~//~0429M~
#if defined(W32)||defined(GXP)                                     //~v955R~
  	if (!UCBITCHK(swsw3,SW3FORM2P))//not supported 2p              //~v955I~
    if (prntyp==PRINTER_WIN)                                       //~v955I~
      if (!(swsw5 & SW5NOBYUCS))                                   //~v96nI~
    	Gxpotheropt|=GOO_EBCBYUCS;                                 //~v955R~
#endif                                                             //~v955I~
#ifdef LNX                                                         //~v96zR~
	if (UDBCSCHK_ISUTF8())                                         //~v96zI~
    	if (!(Gxpotheropt & GOO_EBCBYUCS))	//not gxp              //~v96zI~
//    		if (!(swsw5 & SW5NOBYUCS))                             //~v96zR~
		    	Gxpotheropt|=GOO_EBCBYUCS|GOO_EBCBYUCS_UTF8;       //~v96zR~
#endif                                                             //~v96zI~
    return rc;                                                     //~0428R~
}//xpebc_init                                                      //~0428I~//~v953R~
//**********************************************************************//~0428I~
//*setup sbcs translation tbl and codetype tbl(2:dbcs leadbyte,1:printable)//~0428I~
//*rc:1:ebcdic or asciimode=0/3(codepage determined by this rtn)   //~0429I~//~v955R~
//**********************************************************************//~0428I~
int xpebc_setupcp(int Popt,int **Pcharset,int **Ppcodepage,UCHAR **Pptrt)          //~0428R~//~0429R~
{                                                                  //~0428I~
    int *pcodepage,rc=0,ii;                                        //~0429R~
//***************                                                  //~0428I~
	if (Gebcdictype==3) 	//cfg file                             //~0429I~
    {                                                              //~v955I~
//  	if (recordsz)                                              //~0429I~//~v955R~
        	if (!asciimode)                                        //~0429I~
//      		if (UDBCSCHK_DBCSCVEXT())                          //~0429I~//~v953R~
//          		asciimode=3;                                   //~0429R~//~v955R~
        		if (!UCVEBCH_HANDLE_ISDBCSCV(Gxpebchandle))         //~v953R~//~v955I~
            		asciimode=2;     	//SBCS                     //~v955I~
        *Pptrt=0;   //no sbcs mapping                              //~v955I~
    }                                                              //~v955I~
    pcodepage=Pcharset[asciimode];                   //v6.5a       //~0429I~
	UTRACED("ctype tbl in",pcodepage,256*4);                       //~0429I~
    if (asciimode==0||asciimode==3)                                //~0429I~
    {                                                              //~0429I~
//*adjust codetbl by result of udbcschk if DBCS or SJIS mode       //~v955I~
    	rc=1;                                                      //~0429I~
        for (ii=0;ii<256;ii++)                                     //~0429I~
        {                                                          //~0429I~
            if (Gpdbcstbl[ii] & UDBCSCHK_TYPEDBCS)                 //~0429I~
            		//used for dbcs chk after b2m                  //~v953I~
//              if (dumpmode && (Gebcdictype!=3 || !recordsz))     //~0429R~//~v96eR~
                if (dumpmode && (Gebcdictype!=3 || (!recordsz && !vfmt) ))//~v96eR~
                    Scodepage[ii]=0;                               //~0429I~
                else                                               //~0429I~
                    Scodepage[ii]=2;                               //~0429I~
            else                                                   //~0429I~
            if (Gpdbcstbl[ii] & UDBCSCHK_TYPEUNP)                  //~0429I~
                Scodepage[ii]=0; //unprintable;                    //~0429I~
            else                                                   //~0429I~
                Scodepage[ii]=1;     //printable                   //~0429I~
        }                                                          //~0429I~
        pcodepage=Scodepage;                                       //~0429I~
		if (Gebcdictype==3) 	//cfg file                         //~0429I~
        {                                                          //~0429I~
//      	if (UDBCSCHK_DBCSCVEXT())                              //~0429R~//~v953R~
        	if (!UCVEBCH_HANDLE_ISDBCSCV(Gxpebchandle))         //~v953R~//~v955R~
            {                                                      //~0429R~
                Scodepage[CHAR_SO]=0;                              //~0429R~
                Scodepage[CHAR_SI]=0;                              //~0429R~
            }                                                      //~0429R~
            Scodepage[UDBCSCHK_TABCHAR]=0;                         //~0429R~
            tabskip=1;                                             //~0429R~
//          *Pptrt=0;   //no sbcs mapping                                  //~0428R~//~0429R~//~v955R~
    	}                                                          //~0429I~
    }                                                              //~0429I~
    *Ppcodepage=pcodepage;                                         //~0429R~
	UTRACED("ctype tbl out",pcodepage,256*4);                               //~0428I~//~0429R~
    return rc;                                                      //~0428R~//~0429R~
}//xpebc_setupcp                                                   //~0428I~
//**********************************************************************//~v953I~
//*ebcfile opened                                                  //~v953I~
//**********************************************************************//~v953I~
int xpebc_open(int Popt)                                           //~v953I~
{                                                                  //~v953I~
	int opt;                                                       //~v953I~
//*****************                                                //~v953I~
    Gxpotheropt|=GOO_UFGETS;                                       //~v953R~
  if (!vfmt)	//openinput call sub1fredVinit(ufgetsinit)         //~v96eR~
  {                                                                //~v96eR~
    opt=UFGETS_EBC;                                                //~v955I~
	if (!(Gxpotheropt & GOO_ASCEOL))                                  //~v953R~//~v955I~
    	opt|=UFGETS_EBCEOL;                                        //~v955I~
    if (recordsz)                                                  //~v96BI~
    	opt|=UFGETS_RECORD;	//record mode,split by LRECL           //~v96BI~
    ufgetsinit(opt,0/*buffsz*/,0/*binrate*/,0/*optbinwidth*/);//  default buffsize default rate,width when binary//~v953I~
  }                                                                //~v96eR~
    Sprevoffs=0;                                                   //~v955I~
    return 1;                                                      //~v953I~
}//xpebc_open                                                      //~v953I~
//**********************************************************************//~v953I~
//*ebcdic text read by eolid=0x15                                  //~v953R~
//*rc:EOF,1:eolid exist                                            //~v953I~
//**********************************************************************//~v953I~
int xpebc_fgets(int Popt,FILE *Pfh,char *Pbuff,int Pbuffsz,int *Ppreadlen)//~v953I~
{                                                                  //~v953I~
    int rc,eolid,readlen;                                          //~v953I~
    int opt;                                                       //~v96sI~
    int optasciilineno=0;                                          //~v96wR~
//*****************                                                //~v953I~
//  rc=ufgets(Pbuff,Pbuffsz,Pfh,(UINT*)(&readlen),&eolid);                  //~v953I~//~v956R~//~v997R~
//  rc=ufgets(Pbuff,(size_t)Pbuffsz,Pfh,(UINT*)(&readlen),&eolid); //~v997I~//~v9a1R~
    rc=ufgets(Pbuff,(unsigned)Pbuffsz,Pfh,(UINT*)(&readlen),&eolid);//~v9a1I~
    UTRACEP("xpebc_fgets rc=%d,eolid=%02x\n",rc,eolid);            //~v956I~
    UTRACED("xpebc_fgets",Pbuff,readlen);                          //~v956I~
    switch (rc)        //0 or 4 is ok                              //~v953I~
    {                                                              //~v953I~
    case UFGETS_ERR:                                               //~v953I~
        uerrexit("EBCDIC file read err errno=%d",0,                //~v953I~
                errno);                                            //~v953I~
        break;                                                     //~v953I~
    case UFGETS_EOF:                                               //~v953I~
        if (!readlen)                                              //~v953I~
            return EOF;                                            //~v953I~
        break;                                                     //~v953I~
    default:    //normal                                           //~v953I~
        if (!recordsz)                                             //~v96BI~
        if (readlen>=Pbuffsz)                                      //~v953I~
        {                                                          //~v953I~
            uerrexit("Too long line(no EOL:0x15 in len=%d), specify %s if EOL is 0x0a.",0,//~v953I~//~v96BR~
                        sizeof(Sebcbuff),GOO_ASCEOLS);             //~v953I~
        }                                                          //~v953I~
    }                                                              //~v953I~
    if (readlen && (Popt & XPEBCFGSO_INPUTVHEXMODE))               //~v956I~
    {                                                              //~v956I~
        *vhexlinech=*Pbuff;                                        //~v956I~
        optasciilineno=(*vhexlinech==VHEXDATALINEID)*XPEBCO_ASCIILINENO//~v96wR~
        				|(*vhexlinech==VHEXDATALINEID_CMT_ASCII)*XPEBCO_ASCIICMTLINE;//~v96wI~
        readlen--;                                                 //~v956I~
//      memcpy(Pbuff,Pbuff+1,readlen);                             //~v956I~//~v997R~
        memcpy(Pbuff,Pbuff+1,(size_t)readlen);                     //~v997I~
    }                                                              //~v956I~
    else                                                           //~v97JI~
    {                                                              //~v97JI~
        optasciilineno=(*Pbuff==VHEXDATALINEID)*XPEBCO_ASCIILINENO //~v97JI~
        				|(*Pbuff==VHEXDATALINEID_CMT_ASCII)*XPEBCO_ASCIICMTLINE;//~v97JI~
    }                                                              //~v97JI~
    if (readlen)                                                   //~v97JI~
    if (readlen)                                                   //~v953I~
    {                                                              //~v956I~
      if (optasciilineno & XPEBCO_ASCIICMTLINE)                    //~v96wI~
    	xpebc_b2m_cmt(0,Pbuff,readlen);                            //~v96wR~
      else                                                         //~v96wI~
      if (Popt & XPEBCFGSO_VHEXLINE)                               //~v956I~
        ucvebc_b2afld(0,Gxpebchandle,Pbuff,Pbuff,readlen);         //~v956I~
      else                                                         //~v956I~
      {                                                            //~v96sI~
//  	xpebc_b2m(0,readlen);                                      //~v953I~//~v96sR~
		opt=0;                                                     //~v96sI~
//        if (swsw5 & SW5HHEXMODE)                                 //~v96sR~
//            opt=XPEBCO_BIN;                                      //~v96sR~
		opt|=optasciilineno;                                       //~v96wI~
    	xpebc_b2m(opt,readlen);                                    //~v96sI~
      }                                                            //~v96sI~
    }                                                              //~v956I~
    if (eolid)                                                     //~v953I~
    {                                                              //~v953I~
      if (Popt & XPEBCFGSO_VHEXLINE)                               //~v956R~
        *(Pbuff+readlen)=0x0a;  //vhexline;return mb data          //~v956R~
      else                                                         //~v956I~
      {                                                            //~v956I~
        *(Pbuff+readlen)=EBC_NL;                                   //~v955I~
        *(Sdddata+readlen)=0x0a;                                   //~v955I~
        *(Sb2mdbcstb2+readlen)=0;                                  //~v955I~
    	*(Sb2mbuff+readlen)=0x0a;                                  //~v953I~
      }                                                            //~v956I~
        readlen++;                                                 //~v953I~
    }                                                              //~v953I~
    *Ppreadlen=readlen;                                            //~v953I~
    UTRACED("xpebc_fgets mbdata",Sb2mbuff,readlen);                //~v955R~
    UTRACED("xpebc_fgets mbdbcs",Sb2mbuff,readlen);                //~v955I~
    UTRACED("xpebc_fgets dddata",Sdddata,readlen);                 //~v955I~
    UTRACED("xpebc_fgets dddbcs",Sb2mdbcstb2,readlen);             //~v955I~
    UTRACED("xpebc_fgets outbuf",Pbuff,readlen);                   //~v955I~
    return eolid!=0;                                               //~v953R~
}//xpebc_fgets                                                     //~v953I~
//**********************************************************************//~0428I~
//*text mode read ebcdic file input                                //~0428I~
//**********************************************************************//~0428I~
int xpebc_fgetc(int Popt,FILE *Pfh)                                //~0428I~
{                                                                  //~0428I~
//static 	int Sreadlen,Snextc,Seofsw;                                //~0428R~//~v955R~
static 	int Sreadlen,Seofsw;                                       //~v955I~
	int readc,crlflen,len,dbcsid;                                         //~0428R~//~0429R~
    int rc2;                                                       //~v953I~
  	int vhexlen,opt;                                               //~v956R~
    int reqlen;                                                    //~v96BI~
//*****************                                                //~0428I~
	Gxpotheropt&=~GOO_EBCFREAD;	//   	    0x00000008 //fread moed for record/hhex//~v955I~
	if (Snextc==Sreadlen)                                          //~0428I~
    {                                                              //~0428I~
    	Sreadlen=0;                                                //~0428I~
      if (Gxpotheropt & GOO_UFGETS)	//EOL=0x15                     //~v953M~
      {                                                            //~v953M~
        opt=0;                                                     //~v956I~
    	if (vhexlinech)  //input is vhex 3line mode                //~v956I~
        	opt|=XPEBCFGSO_INPUTVHEXMODE;                          //~v956I~
//  	rc2=xpebc_fgets(opt,Pfh,Sebcbuff,sizeof(Sebcbuff),&Sreadlen);//Sreadlen=0 if EOF//~v953M~//~v956R~//~v96BR~
		reqlen=sizeof(Sebcbuff);                                   //~v96BI~
        if (recordsz)                                              //~v96BR~
        	reqlen=min(reqlen,recordsz);                           //~v96BI~
    	rc2=xpebc_fgets(opt,Pfh,Sebcbuff,reqlen,&Sreadlen);//Sreadlen=0 if EOF//~v96BI~
        Sprevoffs=0;                                               //~v955I~
        Snextc=0;                                                  //~v953M~
        if (rc2==EOF)                                              //~v953M~
        	return EOF;                                            //~v953M~
    	if (vhexlinech)  //input is vhex 3line mode                //~v956I~
        {                                                          //~v956I~
            vhexreadline++;                                        //~v956I~
//      	if (*vhexlinech==VHEXDATALINEID_EBC)	//set by xpevbc_fgets//~v956R~//~v96wR~
        	if (*vhexlinech==VHEXDATALINEID_EBC	//set by xpevbc_fgets//~v96wI~
        	||  *vhexlinech==VHEXDATALINEID)	//ascii lineno fld //~v96wR~
        	{                                                      //~v956I~
                opt=XPEBCFGSO_VHEXLINE;                            //~v96wR~
            	vhexreadline++;                                    //~v956I~
//              if (xpebc_fgets(XPEBCFGSO_VHEXLINE,input,vhexlinex1,Sreadlen+2/*lineid+strz*/,&vhexlen)!=1) //read char line//~v956R~//~v96wR~
                if (xpebc_fgets(opt,input,vhexlinex1,Sreadlen+2/*lineid+strz*/,&vhexlen)!=1) //read char line//~v96wI~
                	uerrexit("\ninput fmt err for EBCDIC vhex mode at line %d",0,//~v956I~
                                    vhexreadline);                 //~v956I~
                Gvhexlinelenhhex=vhexlen;                          //~v96rR~
                vhexreadline++;                                    //~v956I~
//              if (xpebc_fgets(XPEBCFGSO_VHEXLINE,input,vhexlinex2,vhexlen+2,&vhexlen)!=1) //read char line//~v956R~//~v96wR~
                if (xpebc_fgets(opt,input,vhexlinex2,vhexlen+2,&vhexlen)!=1) //read char line//~v96wI~
                	uerrexit("\ninput fmt err for EBCDIC vhex mode at line %d",0,//~v956I~
                                    vhexreadline);                 //~v956I~
                vhexrcount=1;   //skip line id column              //~v956I~
                Gvhexlineoffs=vhexrcount;   //hex line offset      //~v956I~
            }                                                      //~v956I~
        }//vhex 3line input                                        //~v956I~
      }                                                            //~v953M~
      else                                                         //~v953M~
      {                                                            //~v953M~
        if (Seofsw)                                                //~0428I~
        {                                                          //~0428I~
        	Seofsw=0;	//for phase2                               //~0428I~
            Snextc=0;                                              //~0429I~
        	return EOF;                                            //~0428I~
        }                                                          //~0428I~
        for (;;)                                                   //~0428I~
        {                                                          //~0428I~
        	readc=fgetc(Pfh);                                      //~0428I~
            if (readc==EOF)                                        //~0428I~
            {                                                      //~0428I~
            	Seofsw=1;                                          //~0428I~
            	break;                                             //~0428I~
            }                                                      //~0428I~
            if (Sreadlen>=sizeof(Sebcbuff))                        //~0428I~
            {                                                      //~0428I~
//          	uerrexit("Too long line(over %d),specify record size if EOL missing",0,//~v953R~
            	uerrexit("Too long line(no EOL:0x0a in len=%d)",0, //~v953I~
							sizeof(Sebcbuff));                     //~v953I~
            }                                                      //~0428I~
//          Sebcbuff[Sreadlen++]=readc;                            //~0428I~//~v994R~
            Sebcbuff[Sreadlen++]=(UCHAR)readc;                     //~v994I~
            if (readc=='\n')                                       //~0428R~
            	break;                                             //~0428I~
        }                                                          //~0428I~
        Snextc=0;                                                  //~0428I~
        if (readc=='\n')                                           //~0429I~
        {                                                          //~0429I~
        	if (Sreadlen>1 && *(Sebcbuff+Sreadlen-2)=='\r') //cd0a     //~0428R~//~0429R~
        		crlflen=2;                                             //~0428I~//~0429R~
        	else                                                       //~0428I~//~0429R~
        		crlflen=1;                                             //~0428I~//~0429R~
        }                                                          //~0429I~
        else                                                       //~0428I~
            crlflen=0;                                             //~0428I~
        len=Sreadlen-crlflen;                                      //~0428I~
        if (len)                                                   //~0428I~
        	xpebc_b2m(0,len);                                      //~0428R~
//      memcpy(Sb2mbuff+len,Sebcbuff+len,crlflen);                 //~0428R~//~v997R~
        memcpy(Sb2mbuff+len,Sebcbuff+len,(size_t)crlflen);         //~v997I~
        if (!Sreadlen)                                             //~0428I~
        {                                                          //~0428I~
            Seofsw=0;                                              //~0428I~
            return EOF;                                            //~0428I~
        }                                                          //~0428I~
      }//ASCEOL                                                    //~v953M~
    }                                                              //~0428I~
    Gebcorgcode=Sebcbuff[Snextc];                                  //~0429I~
    dbcsid=Sb2mdbcstb[Snextc];	//textmode ctype                   //~0429I~
	readc=Sb2mbuff[Snextc++];                                      //~0428R~
  if (Gxpotheropt & GOO_EBCBYUCS)                                  //~v955M~
  {                                                                //~v955M~
    Gebcctype=1;		//sbcs, dbcssplit chk will be done atf utfdd2u//~v955M~
  }                                                                //~v955M~
  else                                                             //~v955M~
  {                                                                //~v955M~
    Gebcctype=Scodepage[readc];                                    //~0429R~
    if (dbcsid!=UDBCSCHK_DBCS1ST  //not between SO/SI              //~0429R~
    &&  Gpdbcstbl[readc] & UDBCSCHK_TYPEDBCS)  //dbcs starter in locale code//~0429R~
        Gebcctype=0;	//unprintable                              //~0429R~
  }                                                                //~v955I~
    if (readc==0x0a)                                               //~v953I~
    {                                                              //~v953I~
      	if (Gxpotheropt & GOO_UFGETS)	//EOL=0x15                 //~v953I~//~v955R~
        {                                                          //~v955I~
        	if (Snextc<Sreadlen)             //not at eol              //~v953R~//~v955R~
	        	Gebcctype=0;	//unprintable                          //~v953I~//~v955R~
            else                                                   //~v955I~
	        	Gebcctype=1;	//sbcs                             //~v955I~
        }                                                          //~v955I~
    }                                                              //~v953I~
    UTRACEP("xpebc_fgetc readc=%x,ctype=%x,dbcsid=%c,Snextc=%d\n",readc,Gebcctype,dbcsid,Snextc);//~0429R~//~v955R~
    return readc;                                                  //~0428I~
}//xpebc_fgetc                                                     //~0428I~
//**********************************************************************//~0428I~
//*binary mode read ebcdic file input by dumpmode!=0                              //~0428I~//~v955R~
//**********************************************************************//~0428I~
int xpebc_fread(int Popt,char *Pbuff,int Preqlen,FILE *Pfh)        //~0428I~
{                                                                  //~0428I~
//  int rmax;                                                      //~0428I~//~v9e2R~
    int rmx;                                                       //~v9e2R~
    int opt;                                                       //~0429I~
    int reslen,rcv;                                                //~v96eR~
    int vlensz,cvlen,opt2;                                         //~v96iR~
    char eolprint[32];                                             //~v96iR~
    int reqlen;                                                    //~v96mI~
//*****************                                                //~0428I~
	Gxpotheropt|=GOO_EBCFREAD;	//   	    0x00000008 //fread moed for record/hhex//~v955I~
  if (vfmt)	//openinput call sub1fredVinit(ufgetsinit)             //~v96eR~
  {                                                                //~v96eR~
//	rcv=sub1freadV(0,Sebcbuff,Preqlen,Pfh,&rmax,&reslen); //rmax<=RBUFFSZ//~v96eR~//~v9e2R~
  	rcv=sub1freadV(0,Sebcbuff,Preqlen,Pfh,&rmx,&reslen); //rmx<=RBUFFSZ//~v9e2R~
    if (rcv==EOF)                                                  //~v96eR~
    	return EOF;                                                //~v96eR~
//  recordszV=rmax+reslen;	//EOL pos                              //~v96eR~//~v9e2R~
    recordszV=rmx+reslen;	//EOL pos                              //~v9e2R~
    vlensz=0;                                                      //~v96iI~
    if (!reslen)                                                   //~v96iI~
    	if (eolprintfmt)                                           //~v96iR~
        {                                                          //~v96iI~
            vlensz=sprintf(eolprint,eolprintfmt,recordszV0);       //~v96iR~
            opt2=EBC2ASC_A2E;                                      //~v96iR~
//          ucvasc2ebc(opt2,eolprint,0/*pdbcs*/,Sebcbuff+rmax,vlensz,'?',&cvlen);//~v96iR~//~v9e2R~
            ucvasc2ebc(opt2,eolprint,0/*pdbcs*/,Sebcbuff+rmx,vlensz,'?',&cvlen);//~v9e2R~
            vlensz=cvlen;                                          //~v96iI~
            recordszV+=vlensz;                                     //~v96iI~
//          rmax+=vlensz;                                          //~v96iI~//~v9e2R~
            rmx+=vlensz;                                           //~v9e2R~
        }                                                          //~v96iI~
    recordszVEOL=recordszV0+vlensz;                                //~v96iI~
	UTRACEP("xpebc freadV recordszV=%d,rmx=%d,reslen=%d,recordszVEOL=%d\n",recordszV,rmx,reslen,recordszVEOL);//~v96iI~//~v9e2R~
    opt=0;                                                         //~v96eR~
  }                                                                //~v96eR~
  else                                                             //~v96eR~
  {                                                                //~v96eR~
//  rmax=(INT)fread(Sebcbuff,1,Preqlen,Pfh); //read 1 block        //~0428I~//~v96mR~
  	reqlen=Preqlen;                                                //~v96mI~
    if (recordsz && recordsz<Preqlen)                              //~v96mI~
    	reqlen=recordsz;                                           //~v96mI~
//  rmax=(INT)fread(Sebcbuff,1,reqlen,Pfh); //read 1 block         //~v96mI~//~v997R~
//  rmax=(INT)fread(Sebcbuff,1,(size_t)reqlen,Pfh); //read 1 block //~v997I~//~v9e2R~
    rmx=(INT)fread(Sebcbuff,1,(size_t)reqlen,Pfh); //read 1 block  //~v9e2R~
    if (recordsz)                                                  //~0429I~
        opt=0;                                                     //~0429I~
    else                                                           //~0429I~
        opt=XPEBCO_BIN;                                            //~0429I~
  }                                                                //~v96eR~
//if (rmax)                                                         //~v96eR~//~v9e2R~
 if (rmx)                                                          //~v9e2R~
 {                                                                 //~v96eR~
  if (Gxpotheropt & GOO_EBCBYUCS)                                  //~v955I~
  {                                                                //~v96mI~
//  memcpy(Pbuff,Sebcbuff,(UINT)rmax);	//b2m will be done at print//~v955I~//~v9e2R~
    memcpy(Pbuff,Sebcbuff,(UINT)rmx);	//b2m will be done at print//~v9e2R~
    if (recordsz || vfmt)   //no EOL concept for text mode,no dbcschk over 16/32 line width//~v96mI~
  	  if (!samechk)  //not delayed print                           //~v96sI~
//  	xpebc_b2ddrecord(opt,Sebcbuff,rmax); //full record translation to Sb2urecordbuff//~v96mR//~v9e2R~
    	xpebc_b2ddrecord(opt,Sebcbuff,rmx); //full record translation to Sb2urecordbuff//~v9e2R~
  }                                                                //~v96mI~
  else                                                             //~v955I~
  {                                                                //~v955I~
//  xpebc_b2m(opt,rmax);                                    //~0428R~//~0429R~//~v9e2R~
    xpebc_b2m(opt,rmx);                                            //~v9e2R~
//  memcpy(Pbuff,Sb2mbuff,(UINT)rmax);                             //~0428I~//~v9e2R~
    memcpy(Pbuff,Sb2mbuff,(UINT)rmx);                              //~v9e2R~
  }                                                                //~v955I~
 }                                                                 //~v96eR~
 else                                                              //~v96eR~
 {                                                                 //~v96eR~
  if (!vfmt)	//openinput call sub1fredVinit(ufgetsinit)         //~v96eR~
//	rmax=EOF;	//to getinput()                                    //~v96eR~//~v9e2R~
  	rmx=EOF;	//to getinput()                                    //~v9e2R~
 }                                                                 //~v96eR~
	UTRACED("fread",Pbuff,rmx);                                   //~0429R~//~v9e2R~
//  return rmax;                                                   //~0428I~//~v9e2R~
    return rmx;                                                    //~v9e2R~
}//xpebc_fread                                                     //~0428I~//~v96eR~
//**********************************************************************//~0429I~
//*binary mode read ebcdic file input                              //~0429I~
//**********************************************************************//~0429I~
int xpebc_freadnext(int Popt,int Poffs)                            //~0429I~
{                                                                  //~0429I~
	int readc;                                                     //~0429R~
//*****************                                                //~0429I~
    Gebcorgcode=Sebcbuff[Poffs];                                   //~0429I~
  if (Gxpotheropt & GOO_EBCBYUCS)                                  //~v955I~
  {                                                                //~v955M~
    Gebcctype=1;		//always sbcs, dbcssplit chk will be done atf utfdd2u//~v955M~
    readc=Gebcorgcode;                                             //~v955R~
  }                                                                //~v955M~
  else                                                             //~v955M~
  {                                                                //~v955M~
	readc=Sb2mbuff[Poffs];                                         //~0429I~
    Gebcctype=Scodepage[readc];                                    //~0429I~
    if (Gebcctype==2)	//dbcs starter                             //~0429R~
//    	if (!recordsz	//not record mode                          //~0429I~//~v96eR~
      	if ((!recordsz && !vfmt)	//not record mode              //~v96eR~
    	||  Sb2mdbcstb[Poffs]!=UDBCSCHK_DBCS1ST)  //not between SO/SI//~0429R~
        	Gebcctype=0;    //unprintable                          //~0429R~
  }                                                                //~v955I~
	UTRACEP("freadnext readc=%x,ctype=%x\n",readc,Gebcctype);      //~0429R~
    return readc;                                                  //~0429R~
}//xpebc_freadnext                                                 //~0429R~
//**********************************************************************//~v955I~
//*ebc->locale translation                                         //~v955I~
//**********************************************************************//~v955I~
int xpebc_b2dd(int Popt,UCHAR *Pebc,int Plen)                      //~v955R~
{                                                                  //~v955I~
	int opt,rc,ddlen,buffsz;                                       //~v955R~
    char *pdddata,*pdddbcs,*pmbdata,*pmbdbcs;                      //~v955R~
    int offs=0,len=0;                                              //~v96wI~
    char *pebc;                                                    //~v96wI~
//*****************                                                //~v955I~
	UTRACEP("xpebc_b2dd opt=%x,Gxpotheropt=%x\n",Popt,Gxpotheropt);//~v96BR~
	UTRACED("xpebc_b2dd inp",Pebc,Plen);                           //~v96BI~
  	if (Gxpotheropt & GOO_EBCBYUCSRECORD)                          //~v96mI~
	    if (!(Popt & XPEBCO_RECORD))                               //~v96mI~
	    	return xpebc_b2ddrecord_copy(Popt,Pebc,Plen);          //~v96mR~
  	if (Popt & XPEBCO_ASCIILINENO)                                 //~v96wI~
  	{                                                              //~v96wI~
    	offs=Gdatalinenosz;                                        //~v96wI~
    	len=Plen-offs;                                             //~v96wI~
    }                                                              //~v96wI~
    else                                                           //~v96wI~
    	offs=0,len=Plen;                                           //~v96wR~
    pdddata=Sdddata;                                               //~v955I~
    pdddbcs=Sb2mdbcstb2;                                           //~v955I~
    buffsz=sizeof(Sb2mbuff);                                       //~v955I~
    pdddata+=offs,pdddbcs+=offs,buffsz-=offs;                      //~v96wI~
    pebc=Pebc+offs;                                                //~v96wI~
    opt=UCVEBC3O_ERRREP2/*for sbcs*/|UCVEBC3O_ERRREP/*for dbcs*/;	//rep ebc err code//~v955R~
	if (Popt & XPEBCO_BIN)                                         //~v955I~
    	opt|=UCVEBC3O_BIN;                                         //~v955I~
    if (!UCVEBCH_HANDLE_ISDBCSCV(Gxpebchandle))                    //~v955R~
    	opt|=UCVEBC3O_SOSIREP;	//rep to "."                       //~v955I~
    else                                                           //~v955I~
    if (textmodevhexsw||dumpmode)                                  //~v97EI~
    	opt|=UCVEBC3O_SOSIREP;	//rep to "."                       //~v97EI~
    else                                                           //~v97EI~
	    opt|=UCVEBC3O_SOSI2SPACE;                                  //~v955I~
//  rc=ucvebc3_b2dd(opt,Gxpebchandle,Pebc,Plen,pdddata,pdddbcs,buffsz,&ddlen);//~v955R~//~v96wR~
    rc=ucvebc3_b2dd(opt,Gxpebchandle,pebc,len,pdddata,pdddbcs,buffsz,&ddlen);//~v96wI~
	if (UCBITCHK(swsw5,SW5TABONPRM))  //0x10	//tabon parameter specified//~v9e0I~
        xpebc_setdbcsspacealtch(0,pdddata,pdddbcs,ddlen);          //~v9e0I~
	UTRACED("xpebc_b2dd dddata",pdddata,ddlen);                    //~v955R~
	UTRACED("xpebc_b2dd dddbcs",pdddbcs,ddlen);                    //~v955R~
    if (offs)                                                      //~v96wI~
    {                                                              //~v96wI~
//  	memcpy(pdddata-offs,pebc-offs,offs);                       //~v96wI~//~v997R~
    	memcpy(pdddata-offs,pebc-offs,(size_t)offs);               //~v997I~
//  	memset(pdddbcs-offs,0,offs);                               //~v96wR~//~v997R~
    	memset(pdddbcs-offs,0,(size_t)offs);                       //~v997I~
    }                                                              //~v96wI~
    pmbdata=Sb2mbuff;                                              //~v955I~
    pmbdbcs=Sb2mdbcstb;                                            //~v955I~
    pmbdata+=offs,pmbdbcs+=offs;                                   //~v96wI~
//  opt=UCVEBC3O_SOSIREP;                                          //~v955R~
//  rc=ucvebc3_dd2b(opt,Gxpebchandle,pdddata,pdddbcs,ddlen,pmbdata,pmbdbcs,buffsz,&outlen)//~v69cI~//~v955R~
    opt=0;                                                         //~v955I~
//  ucvebc3_setdbcstbl(opt,Gxpebchandle,Pebc,Sb2mdbcstb,Plen);	//setup dbcstbl by SO/SI//~v955R~//~v96wR~
    ucvebc3_setdbcstbl(opt,Gxpebchandle,pebc,pmbdbcs,len);	//setup dbcstbl by SO/SI//~v96wI~
//  memcpy(pmbdata,pdddata,ddlen);                                 //~v955I~//~v997R~
    memcpy(pmbdata,pdddata,(size_t)ddlen);                         //~v997I~
    if (offs)                                                      //~v96wI~
    {                                                              //~v96wI~
    	pmbdata-=offs,pmbdbcs-=offs,pebc-=offs;                    //~v96wI~
//  	memcpy(pmbdata,pebc,offs);                                 //~v96wI~//~v997R~
    	memcpy(pmbdata,pebc,(size_t)offs);                         //~v997I~
//  	memset(pmbdbcs,0,offs);                                    //~v96wR~//~v997R~
    	memset(pmbdbcs,0,(size_t)offs);                            //~v997I~
        ddlen+=offs;                                               //~v96wI~
    }                                                              //~v96wI~
    Soutddlen=ddlen;                                               //~v96mI~
    if (ddlen<Plen)	//is there                                     //~v955I~
    {                                                              //~v955I~
//  	memset(pmbdata+ddlen,' ',Plen-ddlen);                      //~v955I~//~v997R~
    	memset(pmbdata+ddlen,' ',(size_t)(Plen-ddlen));            //~v997I~
//  	memset(pmbdbcs+ddlen,0,Plen-ddlen);                        //~v955I~//~v997R~
    	memset(pmbdbcs+ddlen,0,(size_t)(Plen-ddlen));              //~v997I~
    }                                                              //~v955I~
    UTRACED("xpebc_b2dd mbdata",pmbdata,Plen);                     //~v955R~
    UTRACED("xpebc_b2dd mbdbcs",pmbdbcs,Plen);                     //~v955R~
    return rc;                                                     //~v955I~
}//xpebc_b2dd                                                      //~v955R~
//**********************************************************************//~v96wI~
//*ascii cmtline ucs                                               //~v96wI~
//**********************************************************************//~v96wI~
int xpebc_b2m_cmt(int Popt,char *Pbuff,int Plen)                   //~v96wI~
{                                                                  //~v96wI~
//*****************                                                //~v96wI~
	UTRACED("b2m_cmt inp",Pbuff,Plen);                             //~v96wI~
//  memcpy(Sb2mbuff,Pbuff,Plen);    //all ascii                    //~v96wR~//~v997R~
    memcpy(Sb2mbuff,Pbuff,(size_t)Plen);    //all ascii            //~v997I~
//  memcpy(Sdddata,Pbuff,Plen);                                    //~v96wI~//~v997R~
    memcpy(Sdddata,Pbuff,(size_t)Plen);                            //~v997I~
//  memset(Sb2mdbcstb2,0,Plen);                                    //~v96wI~//~v997R~
    memset(Sb2mdbcstb2,0,(size_t)Plen);                            //~v997I~
//  memset(Sb2mdbcstb,0,Plen);                                     //~v96wR~//~v997R~
    memset(Sb2mdbcstb,0,(size_t)Plen);                             //~v997I~
	UTRACED("b2m_cmt out",Sb2mbuff,Plen);                          //~v96wI~
    return 0;                                                      //~v96wR~
}//xpebc_b2m                                                       //~v96wI~
//**********************************************************************//~0428I~
//*ebc->locale translation                                         //~0428I~
//**********************************************************************//~0428I~
int xpebc_b2m(int Popt,int Plen)                                   //~0428I~
{                                                                  //~0428I~
	int opt=0,rc,outlen,repch='.';                                 //~0428R~
    int len,offs;                                                  //~v96wI~
//*****************                                                //~0428I~
	UTRACED("b2m inp",Sebcbuff,Plen);                              //~0428I~
    if (Gxpotheropt & GOO_EBCBYUCS)                                //~v955I~
    {                                                              //~v955I~
		return xpebc_b2dd(Popt,Sebcbuff,Plen);                     //~v955R~
    }                                                              //~v955I~
//  if ((Popt & XPEBCO_BIN)||!UDBCSCHK_ISDBCSCV())                 //~0428R~//~v96sR~
    if ((Popt & XPEBCO_BIN))  //dbcs handle is chked at ucvebc3_b2m//~v96sI~
    {                                                              //~0428I~
    	opt|=UCVEBC3O_BIN|UCVEBC3O_SOSIREP;                                         //~0428I~//~0429R~
//      memset(Sb2mdbcstb,0,Plen);                                 //~0428I~//~v997R~
        memset(Sb2mdbcstb,0,(size_t)Plen);                         //~v997I~
    }                                                              //~0428I~
    else                                                           //~0428I~
    {                                                              //~0428I~
	    opt|=UCVEBC3O_SOSI2SPACE;                                  //~0429I~
//  	ucvebc3_setdbcstbl(opt,Sebcbuff,Sb2mdbcstb,Plen);	//setup dbcstbl by SO/SI//~0428I~//~v953R~
    	ucvebc3_setdbcstbl(opt,Gxpebchandle,Sebcbuff,Sb2mdbcstb,Plen);	//setup dbcstbl by SO/SI//~v953R~
    }                                                              //~0428I~
//  rc=ucvebc3_b2m(opt,Sebcbuff,Sb2mdbcstb,Plen,Sb2mbuff,sizeof(Sb2mbuff),repch,&outlen);//~0428R~//~0630R~
//  rc=ucvebc3_b2m(opt,Sebcbuff,Sb2mdbcstb,Plen,Sb2mbuff,Sb2mdbcstb2,sizeof(Sb2mbuff),repch,&outlen);//~0630I~//~v953R~
  if (Popt & XPEBCO_ASCIILINENO)                                   //~v96wI~
  {                                                                //~v96wI~
    offs=Gdatalinenosz;                                            //~v96wI~
    len=Plen-offs;                                                 //~v96wI~
    if (len>0)                                                     //~v96wI~
//  	rc=ucvebc3_b2m(opt,Gxpebchandle,Sebcbuff+offs,Sb2mdbcstb+offs,len,Sb2mbuff+offs,Sb2mdbcstb2+offs,sizeof(Sb2mbuff)-offs,repch,&outlen);//~v96wR~//~v997R~
    	rc=ucvebc3_b2m(opt,Gxpebchandle,Sebcbuff+offs,Sb2mdbcstb+offs,len,Sb2mbuff+offs,Sb2mdbcstb2+offs,(int)sizeof(Sb2mbuff)-offs,repch,&outlen);//~v997I~
    else                                                           //~v96wI~
    {                                                              //~v96wI~
    	rc=0;                                                      //~v96wI~
        outlen=0;                                                  //~v96wI~
    }                                                              //~v96wI~
//  memcpy(Sb2mbuff,Sebcbuff,offs);	//ascii lineno                 //~v96wI~//~v997R~
    memcpy(Sb2mbuff,Sebcbuff,(size_t)offs);	//ascii lineno         //~v997I~
//  memset(Sb2mdbcstb2,0,offs);                                    //~v96wI~//~v997R~
    memset(Sb2mdbcstb2,0,(size_t)offs);                            //~v997I~
    memcpy(Sb2mdbcstb,Sb2mdbcstb2,(UINT)(outlen+offs));            //~v96wI~
  }                                                                //~v96wI~
  else                                                             //~v96wI~
  {                                                                //~v96wI~
    rc=ucvebc3_b2m(opt,Gxpebchandle,Sebcbuff,Sb2mdbcstb,Plen,Sb2mbuff,Sb2mdbcstb2,sizeof(Sb2mbuff),repch,&outlen);//~v953R~
    memcpy(Sb2mdbcstb,Sb2mdbcstb2,(UINT)outlen);                   //~0630I~
  }                                                                //~v96wI~
	UTRACED("b2m out",Sb2mbuff,Plen);                              //~0428I~
    return rc;                                                     //~0428I~
}//xpebc_b2m                                                       //~0428I~//~0522R~
//**********************************************************************//~0428I~
//*setup UCS linedata                                              //~v955I~
//**********************************************************************//~v955I~
//int xpebc_setucsline(int Popt,UCHAR *Pmbdata,WUCS *Ppucs,int Plen,int *Ppucsctr)//~v955R~//~v996R~
int xpebc_setucsline(int Popt,UCHAR *Pmbdata,WUCS *Ppucs,int Plen,int *Ppucsctr,int Pbuffsz)//~v996I~
{                                                                  //~v955I~
    WUCS *pucs;                                                    //~v955I~
    UCHAR *pdddata,*pdddbcs,*pebc,*pmb;                            //~v955R~
    int offs,len,ucsctr,opt,contcrlf=0,swchardelm=0;               //~v955R~
    int swfread;                                                   //~v955I~
    int ii;                                                        //~v956I~
    int opt2;                                                      //~v96iR~
//***********************                                          //~v955I~
    *Ppucsctr=0;                                                   //~v955I~
    if (!Plen)                                                     //~v955I~
        return 0;                                                  //~v955I~
//  UTRACEP("pebc_setucsline Snextc=%d,len=%d,hexdump=%d\n",Snextc,Plen,hexdump);//~v955R~
    UTRACED("xpebc_setucsline mbdata",Pmbdata,Plen);               //~v955I~
    pucs=Ppucs;                                                    //~v956I~
    len=Plen;                                                      //~v956I~
    if (Sprevoffs>0)		//contline                             //~v956R~
    {                                                              //~v956M~
        if (swsw4 & SW4VHEXMODE)                                   //~v956M~
            for (pmb=Pmbdata,ii=Gdatalinenosz;ii>0;ii--)           //~v956R~
            {                                                      //~v956M~
                *pucs++=(WUCS)(*pmb++);                            //~v956M~
                len--;                                             //~v956R~
            }                                                      //~v956M~
    }                                                              //~v956M~
	swfread=Gxpotheropt & GOO_EBCFREAD;	//   	    0x00000008 //fread moed for record/hhex//~v955I~
//  len=Plen;                                                      //~v955I~//~v956R~
	offs=Sprevoffs;                                                //~v955R~
    pebc=Sebcbuff+offs+len-1;                                     //~v955I~//~v956R~
    UTRACED("xpebc_setucsline ebcdata",Sebcbuff+offs,len);         //~v956R~
    pmb=Pmbdata+Plen-1;                                            //~v955I~
//  if (recordsz)   //recordmode                                   //~v955I~//~v96eR~
    if (recordsz||vfmt)   //recordmode                             //~v96eR~
    {                                                              //~v955I~
        if (*pmb==CRLF)                                            //~v955I~
        {                                                          //~v955I~
            contcrlf=1;                                            //~v955I~
            len--;                                                 //~v955I~
        }                                                          //~v955I~
      if (len>0)  //not recfm=v and lrecl=0                        //~v96iI~
        if (Popt & XPEBCSULO_HEX)                                  //~v955I~
        	if (*(pmb-1)==CHARDELM)                                //~v955I~
            {                                                      //~v955I~
            	swchardelm=1;                                      //~v955I~
            	len--;                                             //~v955I~
            }                                                      //~v955I~
		if (swfread)                                               //~v955I~
        {                                                          //~v955I~
        	pebc=Pmbdata;                                          //~v955R~
            opt2=0;                                                //~v96iR~
          if (len>0)  //not recfm=v and lrecl=0                    //~v96iI~
//  		xpebc_b2dd(Popt,pebc,len);                             //~v955I~//~v96iR~
    		xpebc_b2dd(opt2,pebc,len);   //XPEBCSULO_HEX=not bin   //~v96iR~
            offs=0;                                                //~v955I~
        }                                                          //~v955I~
    }                                                              //~v955I~
    else                                                           //~v955I~
//  if (*pebc!=EBC_NL)                                             //~v955I~//~v96pR~
//  if (*pebc!=EBC_NL && (swsw4 & SW4VHEXMODE))                    //~v96pI~//~v96qR~
//  if (swsw4 & SW4VHEXMODE)                                       //~v96sR~
    if (swsw4 & SW4VHEXMODE                                        //~v96sR~
    ||  swsw5 & SW5HHEXMODE                                        //~v96sR~
    )                                                              //~v96sR~
//3linedump from xe                                                //~v96sI~
    {                                                              //~v955I~
        for (;len>=0 && *pmb==CRLF;pmb--)                          //~v955R~
        {                                                          //~v955I~
        	contcrlf++;                                            //~v955I~
            len--;                                                 //~v955I~
        }                                                          //~v955I~
    }                                                              //~v955I~
    else                                                           //~v96pI~
    {                                                              //~v96pI~
        for (;len>=0 && *pmb==CRLF;pmb--)                          //~v96pI~
        {                                                          //~v96pI~
        	contcrlf++;                                            //~v96pI~
            len--;                                                 //~v96pI~
        }                                                          //~v96pI~
        if (Popt & XPEBCSULO_HEX)                                  //~v96pI~
        	if (len>0 && *pmb==CHARDELM)                           //~v96pI~
            {                                                      //~v96pI~
            	swchardelm=1;                                      //~v96pI~
            	len--;                                             //~v96pI~
            }                                                      //~v96pI~
	  if (swfread)                                                 //~v96sI~
      {                                                            //~v96sI~
        opt2=0;                                                    //~v96pI~
        pebc=Pmbdata;                                              //~v96pI~
        if (len>0)                                                 //~v96pI~
	    	xpebc_b2dd(opt2,pebc,len);   //XPEBCSULO_HEX=not bin   //~v96pI~
        offs=0;                                                    //~v96pI~
      }                                                            //~v96sI~
    }                                                              //~v96pI~
//  pucs=Ppucs;                                                    //~v955M~//~v956R~
	pdddata=Sdddata+offs;                                          //~v955I~
	pdddbcs=Sb2mdbcstb2+offs;                                      //~v955I~
    opt='.';	//errrep                                           //~v955I~
  if (len>0)                                                       //~v96iI~
//  utfdd2u(opt,pdddata,pdddbcs,len,pucs,MAXLINEWIDTH,&ucsctr,0/*pucsdbcsctr*/,0/*pucssbcsctr*/);//~v955I~//~v996R~
    utfdd2u(opt,pdddata,pdddbcs,len,pucs,Pbuffsz-PTRDIFF(pucs,Ppucs),&ucsctr,0/*pucsdbcsctr*/,0/*pucssbcsctr*/);//~v996R~
  else                                                             //~v96iI~
    ucsctr=0;                                                      //~v96iI~
    pucs+=ucsctr;                                                  //~v955I~
    if (swchardelm)                                                //~v955I~
    {                                                              //~v955I~
    	*pucs++=CHARDELM;                                          //~v955I~
//      ucsctr++;                                                  //~v955I~//~v956R~
    }                                                              //~v955I~
    for (;contcrlf>0;contcrlf--,pucs++,ucsctr++)                   //~v955R~
    	*pucs=CRLF;                                                //~v955I~
//  ucsctr=((ULONG)pucs-(ULONG)Ppucs)/WUCSSZ;                      //~v956I~//~v958R~
//  ucsctr=((ULPTR)pucs-(ULPTR)Ppucs)/WUCSSZ;                      //~v958I~//~v997R~
    ucsctr=(int)((ULPTR)pucs-(ULPTR)Ppucs)/WUCSSZ;                 //~v997I~
    *Ppucsctr=ucsctr;                                              //~v955I~
    Sprevoffs+=len;                                                //~v955R~
    UTRACED("xpebc_setucsline",Ppucs,ucsctr*WUCSSZ);               //~v955I~
    UTRACEP("xpebc_setucsline prev=%d,crlfctr=%d\n",Sprevoffs,Plen-len);//~v955I~
    return 0;                                                      //~v955I~
}//xpebc_setucsline                                                //~v955I~
//**********************************************************************//~v955I~
//*setup UCS linedata for the case samechk=Y                       //~v955I~
//**********************************************************************//~v955I~
int xpebc_b2u(int Popt,UCHAR *Pebc,int Pebclen,WUCS *Ppucs,int Pbuffsz,int *Ppucsctr)//~v955I~
{                                                                  //~v955I~
    UCHAR *pdddata,*pdddbcs;                                       //~v955R~
    int ucsctr,opt,buffsz,ddlen;                                   //~v955R~
//***********************                                          //~v955I~
    UTRACED("xpebc_b2u ebcdata",Pebc,Pebclen);                     //~v955I~
    pdddata=Sdddata;                                               //~v955I~
    pdddbcs=Sb2mdbcstb2;                                           //~v955I~
    buffsz=sizeof(Sb2mbuff);                                       //~v955I~
  if (Gxpotheropt & GOO_EBCBYUCSRECORD)    //R or V                //~v96mI~
  {                                                                //~v96mI~
	xpebc_b2ddrecord_copy(0,Pebc,Pebclen);                         //~v96mI~
    ddlen=Pebclen;                                                 //~v96mI~
  }                                                                //~v96mI~
  else                                                             //~v96mI~
  {                                                                //~v96mI~
    opt=UCVEBC3O_ERRREP2/*for sbcs*/|UCVEBC3O_ERRREP/*for dbcs*/;	//rep ebc err code//~v955I~
    if (!UCVEBCH_HANDLE_ISDBCSCV(Gxpebchandle))                    //~v955I~
    	opt|=UCVEBC3O_SOSIREP;	//rep to "."                       //~v955I~
    else                                                           //~v955I~
    if (textmodevhexsw||dumpmode)                                  //~v97EI~
    	opt|=UCVEBC3O_SOSIREP;	//rep to "."                       //~v97EI~
    else                                                           //~v97EI~
	    opt|=UCVEBC3O_SOSI2SPACE;                                  //~v955I~
	ucvebc3_b2dd(opt,Gxpebchandle,Pebc,Pebclen,pdddata,pdddbcs,buffsz,&ddlen);//~v955I~
  }                                                                //~v96mI~
    opt='.';	//errrep                                           //~v955I~
	utfdd2u(opt,pdddata,pdddbcs,ddlen,Ppucs,Pbuffsz,&ucsctr,0/*pucsdbcsctr*/,0/*pucssbcsctr*/);//~v955R~
    *Ppucsctr=ucsctr;                                              //~v955I~
    UTRACED("xpebc_b2u outucs",Ppucs,ucsctr*WUCSSZ);               //~v955I~
    return 0;                                                      //~v955I~
}//xpebc_b2u                                                       //~v955I~
//**********************************************************************//~v955I~
//*setup UCS linedata for the case samechk=Y                       //~v955R~
//**********************************************************************//~v955I~
//int xpebc_setucslinesamechk(int Popt,UCHAR *Pmbdata,int Plen,UCHAR *Pebcorg,int Pebclen,WUCS *Ppucs,int *Ppucsctr)//~v955R~//~v996R~
int xpebc_setucslinesamechk(int Popt,UCHAR *Pmbdata,int Plen,UCHAR *Pebcorg,int Pebclen,WUCS *Ppucs,int *Ppucsctr,int Pbuffsz)//~v996I~
{                                                                  //~v955I~
    WUCS *pucs;                                                    //~v955I~
    UCHAR *pmb;                                                    //~v955R~
    int ii,len,ucsctr,contcrlf=0,ebclen;                           //~v955R~
//***********************                                          //~v955I~
    *Ppucsctr=0;                                                   //~v955I~
    if (!Plen)                                                     //~v955I~
        return 0;                                                  //~v955I~
    UTRACED("xpebc_setucslinesamechk mbdata",Pmbdata,Plen);        //~v955I~
    UTRACED("xpebc_setucslinesamechk ebcdata",Pebcorg,Plen);       //~v955I~
    len=Plen;                                                      //~v955I~
    ebclen=Pebclen;                                                //~v955R~
    pmb=Pmbdata+Plen-1;                                            //~v955I~
    for (;len>=0 && *pmb==CRLF;pmb--)                              //~v955I~
    {                                                              //~v955I~
        contcrlf++;                                                //~v955I~
        len--;                                                     //~v955I~
    }                                                              //~v955I~
    pucs=Ppucs;                                                    //~v955I~
//  xpebc_b2u(0,Pebcorg,ebclen,pucs,MAXLINEWIDTH,&ucsctr);         //~v955R~//~v996R~
    xpebc_b2u(0,Pebcorg,ebclen,pucs,Pbuffsz,&ucsctr);              //~v996I~
    pmb=Pmbdata+ebclen;                                            //~v955I~
    pucs=pucs+ucsctr;                                              //~v955I~
    for (ii=len-ebclen;ii>0;ii--,ucsctr++)                         //~v955I~
    	*pucs++=*pmb++;           //copy delimiter                 //~v955I~
    for (;contcrlf>0;contcrlf--,ucsctr++)                          //~v955R~
    	*pucs++=CRLF;                                              //~v955R~
    *Ppucsctr=ucsctr;                                              //~v955I~
    UTRACED("xpebc_setucslinesamechk outucs",Ppucs,ucsctr*WUCSSZ); //~v955R~
    return 0;                                                      //~v955I~
}//xpebc_setucslinesamechk                                         //~v955I~
//******************************************************************************//~v96mI~
//*full record b2dd for recordmode and recfm=V to Sv2urecordbuff   //~v96mI~
//******************************************************************************//~v96mI~
int xpebc_b2ddrecord(int Popt,UCHAR *Pebcbuff,int Pebclen) //full record translation//~v96mR~
{	                                                               //~v96mI~
	int ucssz,opt;                                                 //~v96mR~
    UCHAR *pdbcs;                                                  //~v96mI~
//*************************************                            //~v96mI~
  	Gxpotheropt|=GOO_EBCBYUCSRECORD;                               //~v96mI~
//  ucssz=Pebclen*sizeof(WUCS)*2;                                  //~v96mI~//~v997R~
    ucssz=Pebclen*(int)sizeof(WUCS)*2;                             //~v997I~
    if (Sb2ddrecordbuffsz<ucssz)                                   //~v96mI~
    {                                                              //~v96mI~
    	if (Sb2ddrecordbuff)                                       //~v96mI~
        	ufree(Sb2ddrecordbuff);                                //~v96mI~
//  	Sb2ddrecordbuff=umalloc(ucssz);                            //~v96mI~//~v997R~
    	Sb2ddrecordbuff=umalloc((size_t)ucssz);                    //~v997I~
        Sb2ddrecordbuffsz=ucssz;                                   //~v96mI~
    }                                                              //~v96mI~
    opt=XPEBCO_RECORD;                                            //~v955I~//~v96mI~
    xpebc_b2dd(opt,Pebcbuff,Pebclen);   //XPEBCSULO_HEX=not bin    //~v96mI~
    pdbcs=Sb2ddrecordbuff+Sb2ddrecordbuffsz/2;                     //~v96mR~
//  memcpy(Sb2ddrecordbuff,Sdddata,Soutddlen);	//save full record b2dd data//~v96mI~//~v997R~
    memcpy(Sb2ddrecordbuff,Sdddata,(size_t)Soutddlen);	//save full record b2dd data//~v997I~
//  memcpy(pdbcs,Sb2mdbcstb2,Soutddlen);                           //~v96mI~//~v997R~
    memcpy(pdbcs,Sb2mdbcstb2,(size_t)Soutddlen);                   //~v997I~
//  Sb2ddrecordoffs=0;                                             //~v96mI~//~v96nR~
    Scopyedlen=0;                                                  //~v97xI~
    UTRACED("xpebc_b2ddrecord DD",Sb2ddrecordbuff,Soutddlen);      //~v96mR~
    UTRACED("xpebc_b2ddrecord dbcs",pdbcs,Soutddlen);              //~v96mR~
    return 0;                                                      //~v96nI~
}//xpebc_b2ddrecord                                                //~v96mI~
//******************************************************************************//~v96mI~
//*full record b2dd for recordmode and recfm=V to Sv2urecordbuff   //~v96mI~
//******************************************************************************//~v96mI~
int xpebc_b2ddrecord_copy(int Popt,UCHAR *Pebc,int Plen)           //~v96mI~
{                                                                  //~v96mI~
	int offs;                                                      //~v96mI~
    UCHAR *pdbcs;                                                  //~v96mI~
//***********************                                          //~v96mI~
  if (hexdump||vhexdump>1)		//hhex or vhex(recordmode or recfm=V)//~v97xI~
	offs=recorddumpcopyoffs;//set at xphex:printdump//Sb2ddrecordoffs;                                          //~v96mR~//~v96nR~
  else                                                             //~v97xI~
	offs=Scopyedlen;                                               //~v97xI~
    pdbcs=Sb2ddrecordbuff+Sb2ddrecordbuffsz/2;                     //~v96mR~
//  memcpy(Sdddata,Sb2ddrecordbuff+offs,Plen);	//save full record b2dd data//~v96mI~//~v997R~
    memcpy(Sdddata,Sb2ddrecordbuff+offs,(size_t)Plen);	//save full record b2dd data//~v997I~
//  memcpy(Sb2mdbcstb2,pdbcs+offs,Plen);	//save full record b2dd data//~v96mI~//~v997R~
    memcpy(Sb2mdbcstb2,pdbcs+offs,(size_t)Plen);	//save full record b2dd data//~v997I~
    Scopyedlen+=Plen;                                              //~v97xI~
//  Sb2ddrecordoffs+=Plen;                                         //~v96mR~//~v96nR~
    UTRACEP("xpebc_b2ddrecord_copy offs=%d,len=%d\n",offs,Plen);   //~v96mR~
    UTRACED("xpebc_b2ddrecord_copy DD",Sdddata,Plen);              //~v96mR~
    UTRACED("xpebc_b2ddrecord_copy dbcs",Sb2mdbcstb2,Plen);        //~v96mR~
    return 0;                                                      //~v96nI~
}                                                                  //~v96mI~
//******************************************************************************//~v9e0I~
//*replace dbcs space by /tabon: parm                              //~v9e0I~
//*return replace count                                            //~v9e0I~
//******************************************************************************//~v9e0I~
int xpebc_setdbcsspacealtch(int Popt,UCHAR *Ppdddata,UCHAR *Ppdddbcs,int Pddlen)//~v9e0I~
{                                                                  //~v9e0I~
    UCHAR *pdddata,*pdddbcs,*pc;                                   //~v9e0I~
    int reslen,rc=0,len,pos,altch;                                 //~v9e0I~
//************************                                         //~v9e0I~
	for (pdddata=Ppdddata,reslen=Pddlen;;)                         //~v9e0I~
    {                                                              //~v9e0I~
//  	pc=memchr(pdddata,0x30,reslen);                            //~v9e0R~//~v9e7R~
    	pc=memchr(pdddata,0x30,(size_t)reslen);                    //~v9e7I~
        if (!pc)                                                   //~v9e0I~
        	break;                                                 //~v9e0I~
        len=PTRDIFF(pc,pdddata);                                   //~v9e0I~
        pos=PTRDIFF(pc,Ppdddata);	//from top                     //~v9e0I~
        reslen-=len+1;                                             //~v9e0I~
        pdddata=pc+1;        //next of x30                         //~v9e0I~
        if (reslen<=0)                                             //~v9e0I~
        	break;                                                 //~v9e0I~
        if (*pdddata!=0x00)  //u-3000 dbcs space                   //~v9e0I~
        	continue;                                              //~v9e0I~
        pdddbcs=Ppdddbcs+pos;                                      //~v9e0I~
        if (*pdddbcs!=UDBCSCHK_DBCS1STUCS)                         //~v9e0R~
        	continue;                                              //~v9e0I~
        altch=getTabonAltch(0,0);     //get dbcsspace altch        //~v9e0I~
        *(pdddata-1)=(UCHAR)(altch>>8);                            //~v9e0I~
        *pdddata=(UCHAR)(altch&255);                               //~v9e0I~
        pdddata++;                                                 //~v9e0I~
        reslen--;                                                  //~v9e0I~
        rc++;                                                      //~v9e0I~
    }                                                              //~v9e0I~
    return rc;                                                     //~v9e0I~
}//xpebc_setdbcsspacealtch                                         //~v9e0I~
#endif          //EBCDIC dbcs support                              //~0428I~
