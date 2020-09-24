//*CID://+v6R1R~:                             update#=  251;       //~v6R1R~
//*************************************************************
//*ufile5.c                                                        //~v205R~
//*  ufgets,ufgetsinit udoseditname ufileeditname                  //~v340R~
//*************************************************************
//v6R1:180123 set Buffsz=recordsize if recordmode for performance  //~v6R1I~
//v6R0:180123 (BUG)Sbinsw=2(optionally bin mode by 1st 4096 byte) should be cleared;read until eof and crash if oveflow Gfilebuff(32760*4)//~v6R0I~
//v6J7:170217 add filetouch for dummy record write for ::xehosts etc if not found//~v6J7I~
//v6H1:161231 filename >_MAX_PATH occurse when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v6H1I~
//            and it cause fpath area overflow then 0c4            //~v6H1I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6A0:150614 (BUG)doseditname for UD string,copying stops at starting UD_NOTLC(0x01)//~v6A0I~
//v6y1:150303 add fullpath option to fileeditname_copypath         //~v6y1I~
//v6y0:150227 add fileeditname_copypath                            //~v6y1I~
//v6xf:150114 reset remaining data on read buff when seeked        //~v6xfI~
//v6xe:150113 add ufseek and uftell for common to 32 and 64 bit    //~v6xeI~
//v6xc:150113 (BUG)RECFM=V partial edit corrupts file(Scurpos was not set)//~v6xcI~
//v6x2:150106 add ufgets_seek for large binfile seek to start pos  //~v6x2I~
//v6x0:150105 BUG:offset value is long long for fseek error msg    //~v6x0I~
//v6uE:140529 (W32)request explicit option UCVUCS_UCS4 for UCS4 for also Win//~v6uEI~
//v6u9:140408 (Win)use UNICODE Api using special filename UD fmt.  //~v6u9I~
//v6q8:131202 (BUG)Vfmt=mfh read;header line was split,cont line disappean//~v6q8I~
//v6q7:131202 (BUG)Vfmt=mfh read err after update(not mfrecord type(System, record) was not set)//~v6q7I~
//v6m4:130802 option to output vfmt hader                          //~v6m4I~
//v6m0:130710 local file recfm=V support                           //~v6m0I~
//v6hF:120906 add ufreads(read lines containing null char)         //~v6hFI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6h5:120606 (WTL)Bug found by vs2010exp(used uninitialized variable)//~v6h5I~
//v6d8:120211 "invalid name" err msg when UNC path is share root such as \\192.168.8.44\p//~v6d8I~
//v69r:100903 bin file chk;determined bin file for ss3             //~v69rI~
//v691:100730 LP64 wchar_t is 4byte on LP64                        //~v691I~
//v68k:100719 ufgets rc;notify by rc that bin file by the reason of long line//~v68kI~
//v68h:100715 EOLID 0x15 support for ebcdic file                   //~v68hI~
//v684:100618 (BUG) Record mode file is determined as bin file by the reason of NO eolid in the 1024 range//~v684I~
//v66L:100610 update ctl char trans table(and EBC_LF is 0x25<-->u-000a)//~v66LI~
//v661:100415 record mode                                          //~v661I~
//v660:100325 local EBCDIC translation support                     //~v660I~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v62Z:091113 (UTF8:BUG)_binchk by utf is optional                 //~v62ZI~
//            if not bin by utf8 it is text,else chk by locale code//~v62ZI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62S:091015_(BUG)udoseditname;dbcstbl is not advancing           //~v62SI~
//v62n:090915!binchk for utf8file                                  //~v62nI~
//v5nA:081208 (BUG)fileeditname output invalid path for UNC name   //~v5nAI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5kg:070530 (3270)accept long line split by fixed lrecl at put confiramtion chk//~v5kjI~
//v5jt:061113 (3270)new filecomapre option;binary null append allows//~v5jtI~
//v5js:061111 (3270)new filecomapre option;text mode and ignore trailing space//~v5jsI~
//v5jd:061002 3270 support:rename/delete                           //~v5jdI~
//v5j8:060915 add ufile6.c ufilecomp for 3270 update chk           //~v5j8I~
//v5fk:050226 (BUG)unumlen abend by overrun end of string          //~v5fkI~
//v5cr:040509 (FTP:BUG)no consideration for wildcard rename edit   //~v5crI~
//v577:021202 binfilechk:set weight 30 for null char               //~v577R~
//v56y:020807 (BUG)add ufilewildcomp func;wildcomp DBCS support    //~v56yI~
//v56x:020805 (BUG)editfilename DBCS support                       //~v56xI~
//v55h:020429 (UNX:BUG)wildcard conversion err for mdos disk       //~v55hI~
//v552:020413 mac eol(0x0d) support                                //~v552I~
//v50U:010930 udoseditnameopt used for xdc even if not unix        //~v50UI~
//v50b:010324 LINUX:ajust after merge                              //~v50bI~
//v39h:001125 LINUX support:EOFID is one of data                   //~v39hI~
//v388:001009 LINUX support(option of unox like wildcard process   //~v388I~
//            (no special meaning of "." as seperator))            //~v388I~
//v340:000923 (BUG) udoseditname "a" and "*.*" -->"a."; "a" is good//~v327I~
//            ufile5.c                                             //~v327I~
//v327 000820:LINUX support                                        //~v327I~
//v296:991112 add to bin file determination chk logic              //~v296I~
//            (chk up to 1024 byte;if no LF it is bin;dbcs chk;rate change 50->30)//~v296I~
//v290:991024 (BUG)doseditname x.c by aa* result to aac.it should be aa.c//~v290I~
//v279:990813 ufileeditname:udoseditname interface by fullpath parm//~v279I~
//v272:990718 add udoseditname:conv filename by wild card patern   //~v272I~
//v240:990509 >=0xfd is also one of binary data to chk binary file //~v240I~
//v237:990502 record split width support for optbin case           //~v237I~
//v205:981213 add option to ufgets;ignore crlf,chk bin by first block//~v205I~
//v114:971104 option for ugetvfatalias                             //~v114I~
//v110:971103 (GCC)for wild card,chk max len                       //~v110I~
//v105:971026 (GCC)lfn support                                     //~v105I~
//           -use int21 ah=60/7160 for ugetvfatshortname           //~v105I~
//v103:971017 W95 and GCC;ugetalias                                //~v103I~
//v095:970712 maint current pos for ufgets                         //~v095I~
//v090:970629 add ufgets function(pc/unix both support,0x1a chk support)
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

//*******************************************************
#ifdef DOS
    #ifdef DPMI
                #include <dos.h>                                           //~v105I~
    #endif
#else
        #ifdef W32
			#include <io.h>                                        //~v5j8I~
        #include <windows.h>         //GetShortPathName            //~v103I~
        #else
        #endif
#endif

//*******************************************************
#include <ulib.h>
#include <uque.h>                                                  //~v5crI~
#include <ufile.h>
#include <ufile4.h>       //ufileisvfat                            //~v105I~
#include <ufile5.h>
#include <ufemsg.h>                                                //~v103I~
#include <ualloc.h>
#include <uerr.h>
#include <utrace.h>
#include <ustring.h>                                               //~v110I~
#include <udbcschk.h>                                              //~v114I~
#ifdef DPMI                                                        //~v105I~
        #include <udpmisub.h>       //ufileisvfat                      //~v105I~
#endif                                                             //~v105I~
#ifdef FTPSUPP                                                     //~v5crI~
        #include <uftp.h>                                          //~v5crI~
        #include <u3270.h>                                         //~v5jdI~
#endif                                                             //~v5crI~
#ifdef UTF8SUPPH                                                   //~v62nI~
        #include <ucvucs.h>                                        //~v62nI~
#endif                                                             //~v62nI~
#ifdef UTF8EBCD                                                    //~v660I~
        #include <ucvebc.h>                                        //~v660I~
#endif                                                             //~v660I~
#include <ufilew.h>                                                //~v6u9I~
#include <utf2.h>                                                  //~v6A0I~
//**********************************************************************
#define IOBSZ           4096
#define IOBSZV          65536 //max for recfm=V                    //~v6m0R~
#define IOBSZRMAX       32768 //max recordmode                     //~v6R1I~
#define LFID            0x0a
#define CRID            0x0d
#define EOFID           0x1a
                                                                   //~v205I~
//#define DEFBINRATE      50    //default binary chk rate          //~v296R~
#define DEFBINRATE      30    //default binary chk rate            //~v296I~
#define NULLWEIGHT      30    //default weight of null char        //~v577I~
#define MFH_HALFMASK  0x0fff                                       //~v6m0I~
#define MFH_FULLMASK  0x0fffffff                                   //~v6m0I~
#define MFH_HALF      0x307e0000                                   //~v6m0I~
#define MFH_FULL      0x3000007c                                   //~v6m0I~
//**********************************************************************
static UINT Sreadreslen;                //residual len to be move to caller buff
static int  Ssubeofsw;                  //sub eofsw
static int  Seofsw;                             //main eofsw
static UINT Siobreslen;                 //iobuff res data len
static int  Slastbytesw;        //pass to next call sw
//static UINT Scurpos;            //returned total length(contain eol)//~v6x0R~
static FILESZT Scurpos;            //returned total length(contain eol)//~v6x0I~

static int   Smode;               //PC/UNIX type
static int   Sbinrate;            //binary file determination rate //~v205I~
static int   Soptbinwidth;        //when determind binary,use as record width//~v237I~
static int   Sbinsw;             //binary more                     //~v205I~
static int   Sbinswnoeol;             //binary more by no eol found//~v68kI~
static int   Srecordmodesw;      //record mode fixed lrecl         //~v661R~
static int   Svhdrsz;			//recfm=V rdw size                 //~v6m0I~
static int   Svlennet;			//to calc net size                 //~v6m0I~
static int   Svfmt; 			//recfm=V hdr fmt                  //~v6m0I~
static UINT  Siobsz=0;              //fread buff size              //~v56yR~
static UCHAR *Siob=0;             //fread buff size                //~v56yR~
static UCHAR *Siobpos;          //fread buff size
static UCHAR *Sreadpos;         //next move data pos on a read line
#ifdef DPMI                                                        //~v105I~
static int   Sdoserr;           //rc of udpmiintdos                //~v105I~
#endif                                                             //~v105I~
                                                                   //~v388I~
//#ifdef UNX                                                       //~v50UR~
//static int   Sdenopt;           //udoseditname option            //~v56xR~
//#endif //UNX                                                     //~v50UR~
//*******************************************************
int ufgetssub(FILE *Pfh,unsigned char **Pdatapos,unsigned int *Pdatalen,int *Peolid);
int ufilefnameconv(char *Plongname,char *Pshortname,int Plen,int Popt);//~v114I~
UCHAR *ufilewildcompsub(int Popt,int Pcomplen,                     //~v56yI~
					UCHAR *Pin,UCHAR *Ppat,UCHAR *Pdbcsi,UCHAR *Pdbcsp);//~v56yM~
int ufilecomptextmode(int Popt,char *Pfnm1,char *Pfnm2,char *Pbuff);//~v5jsI~
int ufilecomptextmodefixed(int Popt,char *Pfnm1,char *Pfnm2,FILE *Pfh1,FILE* Pfh2,char *Pbuff1,char *Pbuff2);//~v5kgR~
int ufilecomptextmodesub(int Popt,char *Pdata1,char *Pdata2,int Plen1,int Plen2);//~v5kgR~
int ufgetsV(char *Pbuff,unsigned int Pbuffsz,FILE *Pfh,            //~v6m0I~
           unsigned int *Preadlen,int *Peolid);                    //~v6m0I~
                                                                   //~v6A0I~
int udoseditnameUD(int Pudopt,int Popt,UCHAR *Pin,int Pleni,UCHAR *Ppat,int Plenp,UCHAR *Pout);//~v6A0I~
#define UDENUDO_UDI  0x01         //data contains UDstr            //~v6A0I~
#define UDENUDO_UDP  0x02         //pattern contains UD str        //~v6A0I~
//*******************************************************
//*dummy for lib(same name as file)                                             *
//*******************************************************
void ufile5(void)
{
        return;
}

//*******************************************************
//*ufgetsinit
//*   init ufgets
//*parm 1:mode 1:PC file(0d0a)=default,2:unix file(0a),3:both is eol
//*            x10:binary,x20:optionary binary,x80:term req        //~v205R~
//*parm 2:fread buff size(if 0 use default)
//*parm 3:binary file determination rate at first block            //~v205I~
//*parm 4:binary file record width used when binary for opt-bin case//~v237I~
//*ret   :0:ok,0x1001:malloc failed
//*******************************************************
int ufgetsinit(int Pmode,unsigned int Pbuffsz,int Pbinrate,int Poptbinwidth)//~v237R~
{
//*****************
    if (Pmode & UFGETS_TERM)                                       //~v090R~
    {                                                              //~v090I~
        if (Siob)                                                  //~v090I~
        {                                                          //~v090I~
                ufree(Siob);                                           //~v090I~
            Siob=0;                                                //~v090I~
        }                                                          //~v090I~
        return 0;                                                  //~v090I~
    }                                                              //~v090I~
        Smode=Pmode;                                                   //~v090M~
        Sbinrate=0;                                                //~v205I~
        Soptbinwidth=0;                                            //~v237I~
        if (Smode & UFGETS_OPTBIN)                                 //~v205I~
        {                                                          //~v205I~
            Sbinrate=Pbinrate;                                     //~v205R~
            if (!Sbinrate)                                         //~v205I~
                Sbinrate=DEFBINRATE;                               //~v205I~
            Soptbinwidth=Poptbinwidth;                             //~v237I~
        }                                                          //~v205I~
        Sbinswnoeol=0;                                             //~v68kI~
        if (Smode & UFGETS_BIN)                                    //~v205I~
            Sbinsw=1;                                              //~v205I~
        else                                                       //~v205I~
            Sbinsw=0;                                              //~v205I~
        if (Smode & UFGETS_RECORD)                                 //~v661R~
            Srecordmodesw=1;                                       //~v661I~
        else                                                       //~v661I~
            Srecordmodesw=0;                                       //~v661I~
  if (!(Smode & UFGETS_RV))          //recfm!=V                    //~v6m0I~
  if (!(Smode & UFGETS_EBCEOL))          //not ebcdic eol 0x15     //~v68hR~
  if (!(Smode & UFGETS_MAC))            //not mac eol specified,use default as mix//~v552I~
    if (!(Smode & (UFGETS_PC|UFGETS_UNIX)))
        Smode|=(UFGETS_PC | UFGETS_UNIX);                          //~v090R~
    if (!Pbuffsz)
    {                                                              //~v6m0I~
	  if (Smode & UFGETS_RV)          //recfm=V                    //~v6m0I~
        Pbuffsz=(IOBSZV+4);           //65536+4                    //~v6m0R~
      else                                                         //~v6m0I~
      {                                                            //~v6R1I~
        if ((Smode & UFGETS_RECORD) && Poptbinwidth>IOBSZ && Poptbinwidth<IOBSZRMAX)//~v6R1I~
        Pbuffsz=(UINT)Poptbinwidth;                                //~v6R1R~
        else                                                       //~v6R1I~
        Pbuffsz=IOBSZ;
      }                                                            //~v6R1I~
    }                                                              //~v6m0I~
    if (Pbuffsz!=Siobsz)                                           //~v090R~
    {                                                              //~v090I~
        if (Siob)
        {
                ufree(Siob);
            Siob=0;
        }
        Siobsz=Pbuffsz;                                            //~v090R~
        Siob=UALLOCM(Siobsz);                                      //~v090R~
        UALLOCCHK(Siob,UALLOC_FAILED);                             //~v090R~
    }                                                              //~v090I~
//*
	if (Smode & UFGETS_RV)          //recfm=V                      //~v6m0I~
    {                                                              //~v6m0I~
		Svfmt=(Smode & UFGETS_VFMTMASK)>>UFGETS_VFMTSHIFT;         //~v6m0R~
        Svhdrsz=0;              //reset later                      //~v6m0I~
        Svlennet=0;             //for net data size                //~v6m0I~
        switch(Svfmt)                                              //~v6m0R~
        {                                                          //~v6m0I~
        case UFGETS_VFMT_HWDATA:                                   //~v6m0I~
        	Svhdrsz=2;             //2byte llll big endian         //~v6m0I~
        	break;                                                 //~v6m0I~
        case UFGETS_VFMT_HW:                                       //~v6m0I~
        	Svhdrsz=2;             //2byte llll big endian         //~v6m0I~
	        Svlennet=2;             //for net data size            //~v6m0I~
        	break;                                                 //~v6m0I~
        case UFGETS_VFMT_FWDATA:                                   //~v6m0I~
        	Svhdrsz=4;            //4byte 0000llll big endian      //~v6m0I~
        	break;                                                 //~v6m0I~
        case UFGETS_VFMT_FW:                                       //~v6m0I~
        	Svhdrsz=4;            //4byte 0000llll big endian      //~v6m0I~
	        Svlennet=4;             //for net data size            //~v6m0I~
        	break;                                                 //~v6m0I~
        case UFGETS_VFMT_RDW:                                      //~v6m0I~
        	Svhdrsz=4;            //4byte llll0000 Bigendian RDW(ll=len+4)//~v6m0I~
	        Svlennet=4;             //for net data size            //~v6m0I~
        	break;                                                 //~v6m0I~
        case UFGETS_VFMT_MFH:     //not yet determined 2 or 4      //~v6m0R~
        	break;                //Svhdrsz=0                      //~v6m0R~
        }                                                          //~v6m0I~
    }//RV                                                          //~v6m0R~
        Seofsw=0;
        Ssubeofsw=0;
        Siobreslen=0;
        Slastbytesw=0;
        Sreadreslen=0;
        Scurpos=0;              //current pos                          //~v095I~
    return 0;
}//ufgetsinit

//*******************************************************          //~v095I~
//*ufgetscurpos                                                    //~v095I~
//*   get current position(returned total length)                  //~v095I~
//*ret   :total length                                             //~v095I~
//*******************************************************          //~v095I~
//unsigned int ufgetscurpos(void)                                  //~v6x0R~
FILESZT ufgetscurpos(void)                                         //~v6x0I~
{                                                                  //~v095I~
        return Scurpos;                                                //~v095I~
}//ufgetscurpos                                                    //~v095I~
//**************************************************************** //~v6x2I~
void ufgets_setcurpos(int Popt,FILESZT Ppos)                       //~v6x2I~
{                                                                  //~v6x2I~
//    if (Ppos)                                                    //~v6xfR~
    {                                                              //~v6xfI~
        Seofsw=0;                                                  //~v6xfI~
        Ssubeofsw=0;                                               //~v6xfI~
        Siobreslen=0;                                              //~v6xfI~
        Slastbytesw=0;                                             //~v6xfI~
        Sreadreslen=0;                                             //~v6xfI~
    }                                                              //~v6xfI~
	Scurpos=Ppos;                                                  //~v6x2I~
}//ufgets_setcurpos                                                //~v6x2I~
//*******************************************************
//*ufgets
//*     read a line binary mode and drop eol/eof sign
//*parm 1:buff
//*parm 2:buffsz(UINT)
//*parm 3:fh(must be opened by "rb")
//*parm 4:&read len(UINT)
//*parm 5:optional &eol tyep                                       //~v090R~
//          0:no eol data,1:0x0a,2:0d0a,4:0d(Mac) when rc==0       //~v552R~
//*         0                            when rc==more/err         //~v095R~
//*         0:no 0x1a,1:0x1a             when rc==eof              //~v090R~
//*       for recfm=V return reslen                                //~v6m0I~
//*ret   :-1:io err,1:eof ,4:more data ,                           //~v205R~
//*        2:for OPTBIN only;determind to binary by optbin req     //~v205I~
//*******************************************************
int ufgets(char *Pbuff,unsigned int Pbuffsz,FILE *Pfh,
           unsigned int *Preadlen,int *Peolid)
{
static int Seolid;                                                 //~v090R~
static int Ssubrc=0;                                               //~v56yR~
    char *buffpos;
    int  rc,eolid;                                                 //~v090R~
    UINT buffreslen,copylen;
    int sw1st=1;                                                   //~v6R0R~
//*******************
	if (Smode & UFGETS_RV)          //recfm=V                      //~v6m0I~
    	return ufgetsV(Pbuff,Pbuffsz,Pfh,Preadlen,Peolid);	       //~v6m0I~
        buffpos=Pbuff;
    buffreslen=Pbuffsz;
    for (;;)
    {
        if (Sreadreslen)                                           //~v090R~
                rc=Ssubrc;                              //restore previos sub rc       //~v090I~
        else                                                       //~v090I~
        {
            if (Seofsw)
                rc=UFGETS_EOF;
            else
            {
                rc=Ssubrc=ufgetssub(Pfh,&Sreadpos,&Sreadreslen,&Seolid);//~v090R~
                if (rc==UFGETS_ERR)
                        break;
                if (rc==UFGETS_EOF)
                        Seofsw=1;
                if (Sbinsw==2)  //binary of optbin case;RCBIN      //~v237I~
                {                                                  //~v6R0I~
                    if (Soptbinwidth)   //opt bin width specified  //~v237I~
                    {                                              //~v6R0I~
                      if (sw1st)                                   //~v6R0I~
                        buffreslen=Pbuffsz=(UINT)Soptbinwidth;  //shorted read size//~v237R~
                    }                                              //~v6R0I~
                }                                                  //~v6R0I~
            }
        }
        copylen=min(Sreadreslen,buffreslen);
        memcpy(buffpos,Sreadpos,copylen);
        Sreadpos+=copylen;
        Sreadreslen-=copylen;
        buffpos+=copylen;
        buffreslen-=copylen;
        if (!buffreslen && Sreadreslen)
        {
                rc=UFGETS_MORE;
            break;
        }
        if (!rc || rc==UFGETS_EOF)                      //a line moved
                break;
        sw1st=0;                                                   //~v6R0R~
    }
    *Preadlen=Pbuffsz-buffreslen;
        eolid=Seolid;                                                  //~v090R~
  if (rc==UFGETS_MORE)                                             //~v095I~
  {                                                                //~v205I~
    eolid=0;                                                       //~v095I~
    if (Sbinsw)     //ufgets always return more if bin mode        //~v205I~
    {                                                              //~v205I~
        if (Sbinsw==2)                                             //~v205M~
        {                                                          //~v205M~
            Sbinsw=1;       //only 1st time                        //~v205M~
          if (Sbinswnoeol)                                         //~v68kI~
            rc=UFGETS_RCBIN_NOEOL;//notify determind binary        //~v68kI~
          else                                                     //~v68kI~
            rc=UFGETS_RCBIN;//notify determind binary              //~v205I~
        }                                                          //~v205M~
        else                                                       //~v205I~
            rc=0;           //split record                         //~v205I~
    }                                                              //~v205I~
    if (Srecordmodesw)                                             //~v661I~
    {                                                              //~v661I~
//      if (rc!=UFGETS_RCBIN)//notify determind binary             //~v661I~//~v68kR~
        if (rc!=UFGETS_RCBIN && rc!=UFGETS_RCBIN_NOEOL)//notify determind binary//~v68kI~
            rc=0;           //split record                         //~v661I~
    }                                                              //~v661I~
  }                                                                //~v205I~
  else                                                             //~v095I~
    if (rc==UFGETS_EOF)
        if (*Preadlen)
        {
            if (Sbinsw==2)                                         //~v205I~
            {                                                      //~v205I~
                Sbinsw=1;       //only 1st time                    //~v205I~
              if (Sbinswnoeol)                                     //~v68kI~
                rc=UFGETS_RCBIN_NOEOL;//notify determind binary    //~v68kI~
              else                                                 //~v68kI~
                rc=UFGETS_RCBIN;//notify determind binary          //~v205I~
            }                                                      //~v205I~
            else                                                   //~v205I~
                rc=0;
            eolid=0;                                               //~v090R~
        }
    if (Peolid)                                                    //~v090I~
            *Peolid=eolid;                                             //~v090I~
//  Scurpos+=(*Preadlen+eolid); //last position                    //~v6A0R~
    Scurpos+=(*Preadlen+(unsigned int)eolid); //last position      //~v6A0R~
    return rc;
}//ufgets

//*******************************************************
//*ufgetssub
//*  read binary mode and process 0d,0d0a,1a
//*parm 1:fh(must be opened by "rb")
//*parm 2:&read data ptr on io buff
//*parm 3:&read len(UINT)
//*parm 4:&eol tyep(0:no eol data,1:0x0a,2:0d0a 4:0d when rc==0    //~v552R~
//*                 0                            when rc==more/err //~v095R~
//*                 0:no 0x1a,1:0x1a             when rc==eof
//*ret   :-1:io err,1:eof 4:more data,                             //~v205R~
//*                 for bin mode always return more                //~v205I~
//*******************************************************
int ufgetssub(FILE *Pfh,unsigned char **Pdatapos,unsigned int *Pdatalen,int *Peolid)//~v090R~
{
static UCHAR Slastbyte=0;                                          //~v56yR~
        UINT readlen,datalen;
    int rc;
    int rc2;                                                       //~v68kI~
    char *pc;
//*******************
        *Peolid=0;                              //for more/err case                    //~v095I~
    if (!Siobreslen)        //no data on fread buff
    {
        *Siob=Slastbyte;
        if (Ssubeofsw)
            readlen=0;
        else
        {
//          readlen=fread(Siob+Slastbytesw,1,(UINT)(Siobsz-Slastbytesw),Pfh);//~v6A0R~
//          readlen=fread(Siob+Slastbytesw,1,(UINT)(Siobsz-(UINT)Slastbytesw),Pfh);//~v6A0I~//~v6BxR~
            readlen=(UINT)fread(Siob+Slastbytesw,1,(UINT)(Siobsz-(UINT)Slastbytesw),Pfh);//~v6BxI~
//          if (readlen!=Siobsz-Slastbytesw)    //err or eof       //~v6A0R~
            if (readlen!=Siobsz-(UINT)Slastbytesw)    //err or eof //~v6A0I~
            {
                if (ferror(Pfh))
                        return UFGETS_ERR;
                Ssubeofsw=1;
            }
            if (Sbinrate)   //OPTBIN first time                    //~v205R~
            {                                                      //~v205I~
//              if (ufgetsbinchk(Siob,readlen,Sbinrate))//bynary   //~v205R~//~v68kR~
                rc2=ufgetsbinchk(Siob,readlen,Sbinrate);//bynary   //~v68kI~
                if (rc2)                                           //~v68kI~
                {                                                  //~v68kI~
                    Sbinsw=2;   //bin mode by chk                  //~v205R~
                  	if (rc2==2)	                                   //~v68kI~
                    	Sbinswnoeol=1;   //bin mode by chk(no eol) //~v68kI~
                }                                                  //~v68kI~
                Sbinrate=0;     //1st time only                    //~v205I~
            }//bin chk required                                    //~v205I~
        }
//      Siobreslen=(UINT)(readlen+Slastbytesw);                    //~v6A0R~
        Siobreslen=(UINT)(readlen+(UINT)Slastbytesw);              //~v6A0I~
        Siobpos=Siob;
        Slastbytesw=0;
    }
//*
//if (Sbinsw)       //bynary mode                                  //~v205R~//~v661R~
  if (Sbinsw||Srecordmodesw)    //bynary mode or Fixed LRECL       //~v661I~
  {                                                                //~v205I~
    rc=UFGETS_MORE;              //req re-call                     //~v205I~
    Slastbyte=0;                    //except 0d or 1a              //~v205I~
    datalen=Siobreslen;                                            //~v205I~
    Siobreslen=0;                           //next is fread        //~v205I~
    *Pdatapos=Siobpos;                      //path all data        //~v205I~
    if (Ssubeofsw)                                  //eof reached  //~v205I~
        rc=UFGETS_EOF;          //ufgets return eof only when readlen=0//~v205I~
  }                                                                //~v205I~
  else                                                             //~v205I~
  {                                                                //~v205I~
//*text mode                                                       //~v205R~
   if (Smode & UFGETS_EBCEOL) //0x15 is EOLDID                     //~v68hI~
   {                                                               //~v68hI~
    	pc=memchr(Siobpos,EBC_NL,Siobreslen);                      //~v68hI~
        *Pdatapos=Siobpos;                      //path all data    //~v68hI~
    	if (!pc)                    //no cr                        //~v68hI~
    	{                                                          //~v68hI~
        	rc=UFGETS_MORE;              //req re-call             //~v68hI~
            datalen=Siobreslen;                                    //~v68hI~
            Siobreslen=0;                           //next is fread//~v68hI~
        	if (Ssubeofsw)                                  //eof reached//~v68hI~
            	rc=UFGETS_EOF;                                     //~v68hI~
    	}//cr not found                                            //~v68hI~
    	else    //cr found                                         //~v68hI~
    	{                                                          //~v68hI~
        	rc=0;                                                  //~v68hI~
        	*Peolid=UFGETS_EOLID_EBC;   		//EBC_NL:0x15      //~v68hR~
//        	datalen=(ULONG)pc-(ULONG)Siobpos;                      //~v68hI~//~v6hhR~
//        	datalen=(ULPTR)pc-(ULPTR)Siobpos;                      //~v6hhI~//~v6BxR~
          	datalen=(UINT)PTRDIFF(pc,Siobpos);                     //~v6BxI~
            Siobreslen-=(datalen+1);                               //~v68hI~
        	Siobpos=pc+1;                                          //~v68hI~
    	}//cr found                                                //~v68hI~
   }//EBCEOL                                                       //~v68hR~
   else                                                            //~v68hI~
   if (Smode & UFGETS_MAC) //cr only                               //~v552I~
   {                                                               //~v552I~
    	pc=memchr(Siobpos,CRID,Siobreslen);                        //~v552I~
        *Pdatapos=Siobpos;                      //path all data    //~v552I~
    	if (!pc)                    //no cr                        //~v552I~
    	{                                                          //~v552I~
        	rc=UFGETS_MORE;              //req re-call             //~v552I~
            datalen=Siobreslen;                                    //~v552I~
            Siobreslen=0;                           //next is fread//~v552I~
        	if (Ssubeofsw)                                  //eof reached//~v552I~
            	rc=UFGETS_EOF;                                     //~v552I~
    	}//cr not found                                            //~v552I~
    	else    //cr found                                         //~v552I~
    	{                                                          //~v552I~
        	rc=0;                                                  //~v552I~
        	*Peolid=4;   		//cr:mac type                      //~v552I~
//        	datalen=(ULONG)pc-(ULONG)Siobpos;                      //~v552I~//~v6hhR~
//      	datalen=(ULPTR)pc-(ULPTR)Siobpos;                      //~v6hhI~//~v6BxR~
        	datalen=(UINT)PTRDIFF(pc,Siobpos);                     //~v6BxI~
            Siobreslen-=(datalen+1);                               //~v552I~
        	Siobpos=pc+1;                                          //~v552I~
    	}//cr found                                                //~v552I~
   }//mac eol process                                              //~v552I~
   else                                                            //~v552I~
   {//nor mac(!0d)                                                 //~v552I~
    pc=memchr(Siobpos,LFID,Siobreslen);
        *Pdatapos=Siobpos;                      //path all data
    if (!pc)                    //no lf
    {
        rc=UFGETS_MORE;              //req re-call
        if (Siobreslen)
            Slastbyte=*(Siobpos+Siobreslen-1);      //to chk last byte
        else
            Slastbyte=0;                    //except 0d or 1a
                datalen=Siobreslen;
                Siobreslen=0;                           //next is fread
        if (Ssubeofsw)                                  //eof reached
        {
            rc=UFGETS_EOF;
#ifdef UNX            //no EOFID process,return 0x1a as data       //~v39hI~
#else  //!UNX                                                      //~v39hI~
            if (Slastbyte==EOFID)
            {
                        datalen--;                      //chk last byte at next call
                *Peolid=1;
            }
//          else                                                   //~v095R~
//              *Peolid=0;                              //no  crlf                 //~v095R~
#endif //!UNX                                                      //~v39hI~
        }
        else                    //not eof
            if (Slastbyte==CRID || Slastbyte==EOFID)
            {
                        datalen--;                      //chk last byte at next call
                        Slastbytesw=1;
            }
    }//lf not found
    else    //lf found
    {
        rc=0;
        *Peolid=1;
//      datalen=(ULONG)pc-(ULONG)Siobpos;                          //~v6hhR~
//      datalen=(ULPTR)pc-(ULPTR)Siobpos;                          //~v6hhI~//~v6BxR~
        datalen=(UINT)PTRDIFF(pc,Siobpos);                         //~v6BxI~
                Siobreslen-=(datalen+1);
        Siobpos=pc+1;
        if (datalen && *(pc-1)==CRID)   //cr+lf
        {
            if (Smode & UFGETS_PC)
            {
                datalen--;
                *Peolid=2;
            }
        }
        else                                                            //lf only
            if (!(Smode & UFGETS_UNIX)) //cf+lf only
            {
                datalen++;
                rc=UFGETS_MORE;
                        *Peolid=0;              //no eol                           //~v095I~
            }
    }
   }//not mac(!0d)                                                 //~v552I~
  }                                                                //~v205I~
        *Pdatalen=datalen;
    return rc;
}//ufgetssub
                                                                   //~v205I~
#ifdef UTF8SUPPH                                                   //~v62nI~
//*******************************************************          //~v62nI~
//*chk binary file to be translated from utf8 encode               //~v62nI~
//*return:1:bin,0:txt                                              //~v62nI~
//*******************************************************          //~v62nI~
int ufgetsbinchk_utf8(int Popt,UCHAR *Pbuff,UINT Plen,int Prate)   //~v62nI~
{                                                                  //~v62nI~
    int  ctlctr,chsz,chklen,rc2,reslen;                            //~v62nR~
    int  nullctr=0;                                                //~v62nI~
    UINT len,ch;                                                   //~v62nI~
    UCHAR *pc;                                                     //~v62nR~
//  ULONG ucs;                                                     //~v62nI~//~v691R~
    UWUCS ucs;                                                     //~v691I~
    int   eol;                                                     //~v68kI~
//***************************                                      //~v62nI~
//  len=min(1024,Plen);                                            //~v62nI~//~v68kR~
    len=min(UFGETS_MAX1ST,Plen);                                   //~v68kI~
  if (!Srecordmodesw)      //record mode fixed lrecl               //~v684I~
  {                                                                //~v684I~
   	  	if (Smode & UFGETS_MAC)                                    //~v68kI~
        	eol='\r';                                              //~v68kI~
        else                                                       //~v68kI~
        	eol='\n';                                              //~v68kI~
//  if (!memchr(Pbuff,'\n',len))                                   //~v62nI~//~v68kR~
    if (!memchr(Pbuff,eol,len))                                    //~v68kI~
//      if (Plen>=1024) //Plen>=1024                               //~v62nI~//~v68kR~
//          return 1;                                              //~v62nI~//~v68kR~
        if (Plen>=UFGETS_MAX1ST) //Plen>=1024                      //~v68kI~
            return 2;                                              //~v68kI~
  }                                                                //~v684I~
    ctlctr=0;                                                      //~v62nI~
//  for (pc=Pbuff,reslen=len;reslen>0;pc+=chsz,reslen-=chsz)       //~v6A0R~
    for (pc=Pbuff,reslen=(int)len;reslen>0;pc+=chsz,reslen-=chsz)  //~v6A0I~
    {                                                              //~v62nI~
        ch=(UINT)*pc;                                              //~v62nI~
        chsz=UTF8CHARLEN(ch);                                      //~v62nI~
        if (chsz>1) //utf8 code                                    //~v62nI~
        {                                                          //~v62nI~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uER~
#ifdef UTF8UCS416                                                  //~v6uER~
			rc2=uccvutf2ucs(UCVUCS_UCS4,pc,reslen,&ucs,&chklen);   //~v65cI~
#else                                                              //~v65cI~
			rc2=uccvutf2ucs(0,pc,reslen,&ucs,&chklen);             //~v62nR~
#endif                                                             //~v65cI~
            if (rc2==UCVUCS_LENERR)	//split at boundary            //~v62nI~
            	break;                                             //~v62nI~
            if (!rc2)                                              //~v62nI~
            	continue;                                          //~v62nR~
            chsz=1;		                                           //~v62nI~
        }                                                          //~v62nI~
        else                                                       //~v62nI~
        if (chsz==1) //ascii                                       //~v62nI~
        {                                                          //~v62nI~
            if (ch>=0x20                                           //~v62nI~
            ||   ch==0x0d || ch=='\n' || ch=='\t')                 //~v62nI~
                continue;                                          //~v62nI~
        	if (!ch)                                               //~v62nI~
            	nullctr++;                                         //~v62nI~
        }                                                          //~v62nI~
        else	//chsz=0                                           //~v62nI~
	        chsz=1;		//for invalid utf8 start byte              //~v62nR~
        ctlctr++;                                                  //~v62nI~
    }                                                              //~v62nI~
    ctlctr+=nullctr*NULLWEIGHT;                                    //~v62nI~
    if (ctlctr*100>Prate*(int)len)                                 //~v62nI~
        return 1;                                                  //~v62nI~
    return 0;                                                      //~v62nI~
}//ufgetbinchk_utf8                                                //~v62nI~
#endif                                                             //~v62nI~
#ifdef UTF8EBCD                                                    //~v660I~
//*******************************************************          //~v660I~
//*chk binary file to be translated from ebcdic encode             //~v660I~
//*return:1:bin,0:txt                                              //~v660I~
//*******************************************************          //~v660I~
int ufgetsbinchk_ebc(int Popt,UCHAR *Pbuff,UINT Plen,int Prate)    //~v660I~
{                                                                  //~v660I~
    int  ctlctr=0;                                                 //~v660I~
    int  nullctr=0;                                                //~v660I~
    UINT len,ch;                                                   //~v660I~
    UCHAR *pc,*pce;                                                //~v660I~
    int   eol=0;                                                     //~v68hR~//~v68kR~//~v6h5R~
//***************************                                      //~v660I~
//  len=min(1024,Plen);                                            //~v660I~//~v68kR~
    len=min(UFGETS_MAX1ST,Plen);                                   //~v68kI~
  	if (!Srecordmodesw)      //record mode fixed lrecl             //~v68hM~
  	{                                                              //~v68hM~
   	  	if (Smode & UFGETS_EBCEOL) //0x15 is EOLDID                //~v68hI~
        	eol=EBC_NL;                                            //~v68hI~
        else                                                       //~v68hI~
   	  	if (Smode & UFGETS_MAC)                                    //~v68hR~
        	eol='\r';                                              //~v68hI~
        else                                                       //~v68hI~
        	eol='\n';                                              //~v68hI~
		if (!memchr(Pbuff,eol,len))                                //~v68hR~
//      	if (Plen>=1024) //Plen>=1024                           //~v68hM~//~v68kR~
//          	return 1;                                          //~v68hM~//~v68kR~
        	if (Plen>=UFGETS_MAX1ST) //Plen>=1024                  //~v68kI~
                return 2;                                          //~v68kI~
  	}                                                              //~v68hM~
    for (pc=Pbuff,pce=Pbuff+len;pc<pce;pc++)                       //~v660I~
    {                                                              //~v660I~
        ch=(UINT)*pc;                                              //~v660I~
        if ((ch>=CHAR_EBC_SPACE && ch<0xff)                        //~v660I~
        ||   ch==CHAR_SO || ch==CHAR_SI                            //~v660I~
//      ||   ch==EBC_CR/*0d*/ || ch==EBC_NL/*15*/ ||ch=='\n'/*0a*/	//EOL id//~v660R~//~v66LR~
//      ||   ch==EBC_CR/*0d*/ || (int)ch==eol/*15 or 0a or 0d*/ ||ch==EBC_LF/*25*/	//EOL id//~v66LR~//~v68hR~//~v68kR~//~v6h5R~
        ||   ch==EBC_CR/*0d*/ || (!Srecordmodesw && (int)ch==eol/*15 or 0a or 0d*/) ||ch==EBC_LF/*25*/	//EOL id//~v6h5I~
        )                                                          //~v660I~
            continue;                                              //~v660I~
        ctlctr++;                                                  //~v660I~
        if (!ch)                                                   //~v660I~
            nullctr++;                                             //~v660I~
    }                                                              //~v660I~
    ctlctr+=nullctr*NULLWEIGHT;                                    //~v660I~
    if (ctlctr*100>Prate*(int)len)                                 //~v660I~
        return 1;                                                  //~v660I~
    return 0;                                                      //~v660I~
}//ufgetbinchk_ebc                                                 //~v660I~
#endif                                                             //~v660I~
//*******************************************************          //~v205I~
//*chk binary file                                                 //~v205R~
//* bin if 50 char <x20 except x0d,x0a exist in the range specified len//~v205I~
//* (len max is 100 char)                                          //~v205I~
//*parm1 :io area                                                  //~v205I~
//*parm2 :io area len                                              //~v205I~
//*parm3 :rate                                                     //~v205I~
//*return:1:bin,0:txt,2:bin by long record(no eol)                                //~v205I~//~v68kR~
//*******************************************************          //~v205I~
int ufgetsbinchk(UCHAR *Pbuff,UINT Plen,int Prate)                 //~v205I~
{                                                                  //~v205I~
    int  ctlctr;                                                   //~v205R~
    int  nullctr=0;                                                //~v577I~
    UINT len,ch;                                                   //~v205I~
    UCHAR *pc,*pce;                                                //~v205R~
    int   eol;                                                     //~v68kI~
//***************************                                      //~v205I~
#ifdef UTF8SUPPH                                                   //~v62nI~
  	if (Smode & UFGETS_UTF8)     //utf8 file                       //~v62nI~
    {                                                              //~v62ZI~
//  	return ufgetsbinchk_utf8(0,Pbuff,Plen,Prate);              //~v62nR~//~v62ZR~
    	if (!ufgetsbinchk_utf8(0,Pbuff,Plen,Prate)) //text by utf8 //~v62ZI~
            return 0;                                              //~v62ZI~
    }                                                              //~v62ZI~
#endif                                                             //~v62nI~
#ifdef UTF8EBCD                                                    //~v660I~
  	if (Smode & UFGETS_EBC)     //ebcdic file                      //~v660R~
    {                                                              //~v660I~
    	return ufgetsbinchk_ebc(0,Pbuff,Plen,Prate);               //~v660I~
    }                                                              //~v660I~
#endif                                                             //~v660I~
//  len=min(100,Plen);                                             //~v296R~
//  len=min(1024,Plen);                                            //~v296I~//~v68kR~
    len=min(UFGETS_MAX1ST,Plen);                                   //~v68kI~
  if (!Srecordmodesw)      //record mode fixed lrecl               //~v684I~
  {                                                                //~v684I~
   	  	if (Smode & UFGETS_MAC)                                    //~v68kI~
        	eol='\r';                                              //~v68kI~
        else                                                       //~v68kI~
        	eol='\n';                                              //~v68kI~
//  if (!memchr(Pbuff,'\n',len))                                   //~v296R~//~v68kR~
    if (!memchr(Pbuff,eol,len))                                    //~v68kI~
//      if (Plen>=1024) //Plen>=1024                               //~v296I~//~v68kR~
//          return 1;                                              //~v296R~//~v68kR~
        if (Plen>=UFGETS_MAX1ST) //Plen>=1024                      //~v68kI~
            return 2;                                              //~v68kI~
  }                                                                //~v684I~
    ctlctr=0;                                                      //~v205I~
    for (pc=Pbuff,pce=Pbuff+len;pc<pce;pc++)                       //~v205R~
    {                                                              //~v205I~
        ch=(UINT)*pc;                                              //~v205R~
//      if ((ch<0x20 && ch!=0x0d && ch!=0x0a)                      //~v296R~
//      ||   ch>=0xfd)                                             //~v296I~
        if (udbcschk((UCHAR)ch))    //dbcs 1st byte                //~v296R~
        {                                                          //~v296I~
        	if (MAYBESS3(ch)                                       //~v69rI~
            &&  pc+3<=pce                                          //~v69rI~
            &&  ISSS3STR(pc,3)                                     //~v69rI~
            )                                                      //~v69rI~
            {                                                      //~v69rI~
                pc+=2;                                             //~v69rI~
                continue;                                          //~v69rI~
            }                                                      //~v69rI~
            if (pc+4<=pce                                          //~v69rI~
        	&&  UDBCSCHK_ISGB42ND(*(pc+1))                         //~v69rI~
            &&  UDBCSCHK_ISGB4STR(pc,4)                            //~v69rR~
            )                                                      //~v69rI~
            {                                                      //~v69rI~
                pc+=3;                                             //~v69rI~
                continue;                                          //~v69rI~
            }                                                      //~v69rI~
#ifdef WCSUPP                                                      //~v5n8R~
            if ((pc+1<pce) && WCMB2ND(0,(pc+1)))                   //~v5n8R~
#else                                                              //~v5n8R~
            if (pc+1<pce && *(pc+1)>=0x40 && *(pc+1)<=0xfc)        //~v296I~
#endif                                                             //~v5n8R~
            {                                                      //~v296I~
                pc++;                                              //~v296I~
                continue;                                          //~v296I~
            }                                                      //~v296I~
        }                                                          //~v296I~
        else                                                       //~v296I~
            if ((ch>=0x20 && ch<0xff)                              //~v296I~
            ||   ch==0x06         //keisen yokobo                  //~v296I~
            ||   ch==0x0d || ch=='\n' || ch=='\t')                 //~v296I~
                continue;                                          //~v296I~
            ctlctr++;                                              //~v205I~
        if (!ch)                                                   //~v577I~
            nullctr++;                                             //~v577I~
//          if (ctlctr>Prate)                                      //~v296R~
//              return 1;                                          //~v296R~
    }                                                              //~v205I~
    ctlctr+=nullctr*NULLWEIGHT;                                    //~v577R~
    if (ctlctr*100>Prate*(int)len)                                 //~v296R~
        return 1;                                                  //~v296I~
    return 0;                                                      //~v205R~
}//ufgetbinchk                                                     //~v205I~
#if defined(W32) || defined(DPMI)                                  //~v103I~
//*******************************************************          //~v103I~
//*ugetvfatalias                                                   //~v103R~
//*  get short path name                                           //~v103I~//~v6m4R~
//*parm 1:option                                                   //~v114I~
//*parm 2:input long name                                          //~v114I~
//*parm 3:output short name                                        //~v114I~
//*parm 4:output bufflen(contain last null)                        //~v114I~
//*ret   :short name strlen                                        //~v103R~
//*******************************************************          //~v103I~
int ugetvfatalias(int Popt,unsigned char *Plongname,unsigned char *Pshortname,int Plen)//~v114R~
{                                                                  //~v103I~
        UINT len;                                                      //~v103I~
    int rc;                                                        //~v103I~
    int pathlen;                                                   //~v103R~
    char fatname[MAXFILENAMEZ_FAT];                                //~v114I~
    char *fnm=NULL;                                                     //~v114I~//~v6h6R~
//*******************                                              //~v103I~
    if (!ufileisvfat(0))                                           //~v110I~
    {                                                              //~v110I~
        ustrncpyz(Pshortname,Plongname,(UINT)Plen);                //~v110R~
        return strlen(Pshortname);                                 //~v110R~
    }                                                              //~v110I~
        pathlen=-1;             //pass filename to api as is           //~v114I~
  if (Popt & UGVFA_WILDCARD)                                       //~v114I~
        if (WILDCARD(Plongname))                                       //~v103I~
    {                                                              //~v103I~
        pathlen=PATHLEN(Plongname);                                //~v103R~
        if (pathlen>=0)                                            //~v103I~
                pathlen--;                                             //~v103I~
    }                                                              //~v103I~
//  else                                                           //~v114R~
//      pathlen=-1;                                                //~v114R~
        if (pathlen>0)                                                 //~v103I~
    {                                                              //~v114I~
        fnm=Plongname+pathlen;                                     //~v114I~
        *fnm=0;                                                    //~v114I~
    }                                                              //~v114I~
//      len=GetShortPathName(Plongname,Pshortname,(UINT)Plen);         //~v105R~
        len=ugetshortpathname(Plongname,Pshortname,(UINT)Plen);        //~v105R~
        if (pathlen>0)                                                 //~v103I~
        *fnm='\\';                                                 //~v114R~
    if (!len || len>=(UINT)Plen)//err or buff shortage             //~v103R~
    {                                                              //~v103I~
#ifdef DPMI                                                        //~v105I~
        rc=Sdoserr;                                                //~v105I~
        if (rc==ENOENT)                                            //~v105I~
#else                                                              //~v105I~
        rc=GetLastError();                                         //~v103R~
        if (rc==ERROR_PATH_NOT_FOUND                               //~v114R~
        ||  rc==ERROR_FILE_NOT_FOUND)                              //~v114R~
#endif                                                             //~v105M~
        {                                                          //~v114I~
            if (pathlen<0 && (Popt & UGVFA_NEW))    //not wild card,allow new file//~v114I~
            {                                                      //~v114I~
                pathlen=PATHLEN(Plongname);                        //~v114I~
                if (pathlen>=0)                                    //~v114I~
                    pathlen--;                                     //~v114I~
                if (pathlen>0)                                     //~v114I~
                {                                                  //~v114I~
                                fnm=Plongname+pathlen;                         //~v114R~
                                *fnm=0;                                        //~v114I~
                                len=ugetvfatalias(Popt&~UGVFA_NEW,Plongname,Pshortname,Plen);//~v114I~
                                *fnm='\\';                                     //~v114R~
                }                                                  //~v114I~
            }                                                      //~v114I~
          if (!len && (Popt & UGVFA_MSG))       //path faile and msg opt//~v114R~
            ufilenotfound(Plongname,rc);                           //~v103I~
        }                                                          //~v114I~
        else                                                       //~v103I~
        {                                                          //~v6d8I~
#ifdef DPMI                                                        //~v105I~
            ufileapierr("udpmiintdos(get short path name)",Plongname,Sdoserr);//~v105I~
#else                                                              //~v105I~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v6d8I~
          if(rc==ERROR_INVALID_NAME)//for err case of top folder   //~v6d8R~
            uerrmsg("Invalid Name Format(%s)",0,                   //~v6d8I~
            		Plongname);                                    //~v6d8I~
          else                                                     //~v6d8I~
#endif                                                             //~v6d8I~
            ufileapierr("GetShortPathName",Plongname,rc);          //~v103I~
#endif                                                             //~v105I~
        }                                                          //~v6d8I~
    }                                                                  //~v103I~
    if (pathlen>0)                                                 //~v103I~
    {                                                              //~v103I~
        ufilegenshortfname(fnm+1,fatname);                             //~v114R~
        *(Pshortname+len)='\\';                                    //~v114R~
        ustrncpyz(Pshortname+len+1,fatname,Plen-len-1);            //~v114I~
        len=strlen(Pshortname);                                    //~v110R~
        }                                                              //~v103I~
    return (int)len;                                               //~v103R~
}//ugetvfatalias                                                   //~v103R~
                                                                   //~v105I~
//*******************************************************          //~v114I~
//*ufilegenshortfname                                              //~v114I~
//*  conversion lfn to fat name                                    //~v114I~
//*parm 1:input long filename                                      //~v114I~
//*parm 2:output fatname                                           //~v114I~
//*ret   :sufixpos                                                 //~v114R~
//*******************************************************          //~v114I~
int ufilegenshortfname(char *Plongname,char *Pshortname)           //~v114R~
{                                                                  //~v114I~
        char *pc,*pc2,*pc3;                                            //~v114R~
    int len,convsw=0,pos;                                          //~v114R~
//*******************                                              //~v114I~
    pc=strchr(Plongname,'.');                                      //~v114I~
    if (pc)                                                        //~v114I~
    {                                                              //~v114I~
//      len=(int)((ULONG)pc-(ULONG)Plongname);                     //~v114I~//~v6hhR~
        len=(int)((ULPTR)pc-(ULPTR)Plongname);                     //~v6hhI~
        pc++;                                                      //~v114I~
        if (strlen(pc)>3)                                          //~v114I~
            convsw=1;                                              //~v114I~
        else                                                       //~v114I~
            if (strchr(pc,'.'))                                    //~v114I~
                convsw=1;                                          //~v114I~
    }                                                              //~v114I~
    else                                                           //~v114I~
        len=(int)strlen(Plongname);                                //~v114I~
    if (len>8)                                                     //~v114I~
        convsw=1;                                                  //~v114I~
    if (!convsw)                                                   //~v114I~
        if (strchr(Plongname,' '))                                 //~v114R~
            convsw=1;                                              //~v114R~
        if (!convsw)                                                   //~v114I~
    {                                                              //~v114I~
                ufilefnameconv(Plongname,Pshortname,MAXFILENAMEZ_FAT-1,0);//base max is 6,stop at '.'//~v114I~
        return 0;               //no change                                //~v114R~
    }                                                              //~v114I~
//shorten   to   xxxxxx~1.yyy                                      //~v114I~
        pos=ufilefnameconv(Plongname,Pshortname,6,1);//base max is 6,stop at '.'//~v114R~
    pc2=Pshortname+pos;                                            //~v114I~
    *pc2++='~';                                                    //~v114R~
    *pc2++='1';                                                    //~v114R~
    *pc2=0;                                                        //~v114R~
        if (pc) //extention                                            //~v114R~
    {                                                              //~v114I~
        *pc2++='.';                                                //~v114M~
        pc3=strrchr(pc,'.');    //last period                      //~v114R~
                if (pc3)                                                       //~v114I~
                pc=pc3+1;                                              //~v114I~
                ufilefnameconv(pc,pc2,3,0);//ext max is 3                  //~v114R~
    }                                                              //~v114I~
    return pos+1;       //sufix pos                                    //~v114R~
}//ufilegenshortfname                                              //~v114I~
//*******************************************************          //~v114I~
//*ufilefnameconv                                                  //~v114I~
//*  shorten file base name/ext name(drop space,drop boundary dbcs)//~v114I~
//*parm 1:input long filename                                      //~v114I~
//*parm 2:output fatname                                           //~v114I~
//*parm 3:maxlen                                                   //~v114I~
//*parm 4:opton 1:stop before '.'                                  //~v114I~
//*ret   :outlen                                                   //~v114I~
//*******************************************************          //~v114I~
int ufilefnameconv(char *Plongname,char *Pshortname,int Plen,int Popt)//~v114R~
{                                                                  //~v114I~
        char *pcs,*pcl,*pcend;                                         //~v114I~
//*******************                                              //~v114I~
    pcs=Pshortname;                                                //~v114R~
        pcl=Plongname;                                                 //~v114I~
        pcend=Pshortname+Plen;                                         //~v114I~
    for (;*pcl && pcs<pcend;)                                      //~v114I~
    {                                                              //~v114I~
        if (Popt)                                                  //~v114I~
                if (*pcl=='.')                                         //~v114R~
                break;                                             //~v114R~
        if (*pcl==' ')                                             //~v114R~
                pcl++;                                                 //~v114I~
                else                                                       //~v114I~
        {                                                          //~v114I~
            if (udbcschk(*pcl))                                    //~v114I~
            {                                                      //~v114I~
                    *pcs++=*pcl++;                                     //~v114I~
                    *pcs++=*pcl++;                                     //~v114I~
                        }                                                      //~v114I~
            else                                                   //~v114I~
                if (*pcl>='a' && *pcl<='z')                        //~v114R~
                {                                                  //~v114I~
                        *pcs++=(UCHAR)toupper(*pcl);                   //~v114R~
                    pcl++;                                         //~v114I~
                }                                                  //~v114I~
                else                                               //~v114I~
                        *pcs++=*pcl++;                                 //~v114R~
        }                                                          //~v114I~
    }                                                              //~v114I~
    if (pcs>pcend)      //last is dbcs                                 //~v114I~
        pcs-=2;                                                    //~v114I~
        *pcs=0;                                                        //~v114I~
//      return (int)((ULONG)pcs-(ULONG)Pshortname);                    //~v114I~//~v6hhR~
        return (int)((ULPTR)pcs-(ULPTR)Pshortname);                //~v6hhI~
}//ufilefnameconv                                                  //~v114I~
//*******************************************************          //~v105I~
//*ugetshortpathname W32 and DPMI                                  //~v105I~
//*  get shprt path name                                           //~v105I~
//*parm 1:input long name                                          //~v105I~
//*parm 2:output short name                                        //~v105I~
//*parm 3:output bufflen(contain last null)                        //~v105I~
//*ret   :short name strlen                                        //~v105I~
//*******************************************************          //~v105I~
int ugetshortpathname(unsigned char *Plongname,unsigned char *Pshortname,int Plen)//~v105I~
{                                                                  //~v105I~
#ifdef DPMI                                                        //~v105I~
        union REGS   reg;                                              //~v105I~
    char wk[_MAX_PATH];                                            //~v105R~
//***************                                                  //~v105I~
    memset(&reg,0,sizeof(reg));                                    //~v105I~
        if (ufileisvfat(0))                                            //~v105I~
    {                                                              //~v105I~
                reg.h.ah=0x71;                                  //lfn func                 //~v105I~
                reg.h.al=0x60;                                  //get curr dir             //~v105I~
                reg.x.cx=1;                                             //short pathname get       //~v105I~
        }                                                              //~v105I~
    else                                                           //~v105I~
                reg.h.ah=0x60;                                  //get curr dir             //~v105I~
                                                                   //~v105I~
    reg.d.esi=(int)Plongname; //input dir name ptr                 //~v105I~
    reg.d.edi=(int)wk; //output dir name ptr                       //~v105I~
    udpmiintdos(&reg,&reg);     //get cur dir                      //~v105I~
    Sdoserr=0;                                                     //~v105I~
        if (reg.x.cflag)                                               //~v105I~
    {                                                              //~v105I~
        Sdoserr=errno;                                             //~v105I~
        return 0;                                                  //~v105I~
        }                                                              //~v105I~
    strncpy(Pshortname,wk,Plen-1);                                 //~v105I~
    *(Pshortname+Plen-1)=0;                                        //~v105I~
    return (int)strlen(wk);                                        //~v105I~
#else                                                              //~v105I~
        return GetShortPathName(Plongname,Pshortname,(UINT)Plen);      //~v105I~
#endif                                                             //~v105I~
}//ugetshortpathname                                               //~v105I~
#endif                                                             //~v103I~
                                                                   //~v272I~
//#ifdef UNX                                                       //~v50UR~
////*******************************************************        //~v56xR~
////*udoseditnameopt                                               //~v56xR~
////*   set option for udoseditname                                //~v56xR~
////*******************************************************        //~v56xR~
//void udoseditnameopt(int Popt)                                   //~v56xR~
//{                                                                //~v56xR~
//    Sdenopt=Popt;                                                //~v56xR~
//    return;                                                      //~v56xR~
//}                                                                //~v56xR~
////udoseditnameopt                                                //~v56xR~
//#endif                                                           //~v50UR~
//*******************************************************          //~v6A0I~
//*isSameU8c                                                       //~v6A0I~
//*ret   :1 u8 mach                                                //~v6A0R~
//*       *Ppu8csz:u8 chsz of Pin if valid utf8 char               //~v6A0I~
//*******************************************************          //~v6A0I~
int isSameU8c(int Popt,UCHAR *Pin,int Plen,UCHAR *Ppat,int *Ppu8csz)//~v6A0I~
{                                                                  //~v6A0I~
    ULONG ulucs1,ulucs2;                                           //~v6A0I~
    int rc=0,u8csz1,u8csz2,u8csz;                                  //~v6A0R~
//*****************                                                //~v6A0I~
	*Ppu8csz=0;                                                    //~v6A0I~
	for (;;)                                                       //~v6A0I~
    {                                                              //~v6A0I~
		u8csz=UTF8CHARLEN(*Pin);                                   //~v6A0I~
        if (u8csz<2)                                               //~v6A0I~
            break;  //u8err or ascii                               //~v6A0I~
	    if (utfgetwc(Pin,Plen,&ulucs1,&u8csz1))                    //~v6A0I~
    		break;//u8err                                          //~v6A0I~
        *Ppu8csz=u8csz1;                                           //~v6A0R~
		u8csz2=UTF8CHARLEN(*Ppat);                                 //~v6A0I~
		if (u8csz1!=u8csz2)                                        //~v6A0I~
    		break;//unmatch                                        //~v6A0I~
	    if (utfgetwc(Ppat,u8csz2,&ulucs2,&u8csz))                  //~v6A0R~
    		break;//u8 err                                         //~v6A0R~
		if (ulucs1!=ulucs2)                                        //~v6A0I~
    		break;//unmatch                                        //~v6A0I~
        rc=1;                                                      //~v6A0I~
        break;                                                     //~v6A0I~
    }                                                              //~v6A0I~
    UTRACED("Pin",Pin,Plen);                                       //~v6A0R~
    UTRACED("Ppat",Ppat,(int)strlen(Ppat));                        //~v6A0R~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v6A0I~
    return rc;                                                     //~v6A0I~
}//isSameU8c                                                       //~v6A0I~
#ifdef W32UNICODE                                                  //~v6A0I~
//*******************************************************          //~v6A0I~
//*udoseditnameUD                                                  //~v6A0I~
//*   covert filename by patern of UD fmt                          //~v6A0I~
//*  rc:0 ok,else UD fmt err                                       //~v6A0I~
//*******************************************************          //~v6A0I~
int udoseditnameUD(int Pudopt,int Popt,UCHAR *Pin,int Pleni,UCHAR *Ppat,int Plenp,UCHAR *Pout)//~v6A0I~
{                                                                  //~v6A0I~
	UWCH wkpci[_MAX_PATH],wkpcp[_MAX_PATH],wkpco[_MAX_PATH];       //~v6A0I~
	UWCH *pci,*pcie,*pcp,*pco,chp;                                 //~v6A0I~
    UCHAR  wkuds[_MAX_PATH*2];                                     //~v6A0I~
    int    leni,lenp;                                              //~v6A0I~
    int    msw;                                                    //~v6A0I~
	int ucsctri,ucsctrp,rc,opt,outlen;                             //~v6A0R~
//*****************                                                //~v6A0I~
	rc=ufilecvUD2WCnopath(0,Pin,wkpci,sizeof(wkpci),&ucsctri);     //~v6A0I~
    UTRACED("wkpci",wkpci,ctr2szW(ucsctri));                       //~v6A0I~
    if (rc==UDRC_FMTERR)                                           //~v6A0I~
    	return UDRC_FMTERR;                                        //~v6A0I~
	rc=ufilecvUD2WCnopath(0,Ppat,wkpcp,sizeof(wkpcp),&ucsctrp);    //~v6A0I~
    UTRACED("wkpcp",wkpcp,ctr2szW(ucsctrp));                       //~v6A0I~
    if (rc==UDRC_FMTERR)                                           //~v6A0I~
    	return UDRC_FMTERR;                                        //~v6A0I~
    pcie=wkpci+ucsctri;                                            //~v6A0I~
    pcp=wkpcp; pci=wkpci; pco=wkpco;                               //~v6A0I~
    leni=ucsctri;                                                  //~v6A0I~
    lenp=ucsctrp;                                                  //~v6A0I~
    chp=*pcp;             //for compiler warning                   //~v6A0I~
    while(pci<pcie)                                                //~v6A0I~
    {                                                              //~v6A0I~
        chp=*pcp++;             //patern                           //~v6A0I~
        switch(chp)                                                //~v6A0I~
        {                                                          //~v6A0I~
        case '*':                                                  //~v6A0I~
            chp=*pcp;       //next of '*'                          //~v6A0I~
            while (chp=='*')    //ignore double '*'                //~v6A0I~
                chp=*++pcp;                                        //~v6A0I~
            while (pci<pcie)                                       //~v6A0I~
            {                                                      //~v6A0I~
                msw=0;                      //match sw             //~v6A0I~
UTRACEP("chk input=%x,pat=%x\n",(int)*pci,(int)*pcp);              //~v6A0I~
                if (chp==*pci)                                     //~v6A0I~
                {                                                  //~v6A0I~
                	msw=1;                                         //~v6A0I~
                }                                                  //~v6A0I~
                else        //char unmatch                         //~v6A0I~
                    if (UTF8ISASCII(chp))	//sbcs                 //~v6A0I~
              			if (!(Popt & DEN_CASE)) 	//case insensitive//~v6A0I~
                			if (toupper(chp)==toupper(*pci))       //~v6A0I~
                                msw=1;                             //~v6A0I~
                if (msw)                                           //~v6A0I~
                    break;                                         //~v6A0I~
UTRACEP("copy input=%x\n",*pci);                                   //~v6A0I~
                *pco++=*pci++;                                     //~v6A0I~
            }                                                      //~v6A0I~
            break;                                                 //~v6A0I~
        case '?':                                                  //~v6A0I~
            if (*pci=='.')        //nop when '.'                   //~v6A0I~
                break;                                             //~v6A0I~
            *pco++=*pci++;  //copy from patern                     //~v6A0I~
            break;                                                 //~v6A0I~
        case '.':                                                  //~v6A0I~
          if (Popt & DEN_UNIX)                                     //~v6A0I~
          {                      //same as default                 //~v6A0I~
            *pco++=chp; //copy from patern                         //~v6A0I~
	        pci++;      //pass input char                          //~v6A0I~
            break;                                                 //~v6A0I~
          }                                                        //~v6A0I~
            while(pci<pcie) //all base                             //~v6A0I~
                if (*pci++=='.')                                   //~v6A0I~
                    break;                                         //~v6A0I~
            *pco++='.';                                            //~v6A0I~
            break;                                                 //~v6A0I~
        case  0:                                                   //~v6A0I~
            break;                                                 //~v6A0I~
        default:                                                   //~v6A0I~
            *pco++=chp; //copy from patern                         //~v6A0I~
          if (Popt & DEN_UNIX)                                     //~v6A0I~
	            pci++;      //pass input char                      //~v6A0I~
          else                                                     //~v6A0I~
          if (*pci!='.')                                           //~v6A0I~
            pci++;      //pass input char                          //~v6A0I~
        }                                                          //~v6A0I~
        if (!chp)                                                  //~v6A0I~
            break;                                                 //~v6A0I~
    }//while input exist                                           //~v6A0I~
//copy residual of patern                                          //~v6A0I~
//  do                                                             //~v6A0I~
    while(chp)                                                     //~v6A0I~
    {                                                              //~v6A0I~
        chp=*pcp++;                                                //~v6A0I~
        if (!chp)                                                  //~v6A0I~
            break;                                                 //~v6A0I~
        if (chp!='*' && chp!='?')                                  //~v6A0I~
        {                                                          //~v6A0I~
          if (!(Popt & DEN_UNIX))                                  //~v6A0I~
            if (chp=='.')                                          //~v6A0I~
        		if (strctrW(pcp)==(int)strspnW(pcp,L"*?."))	//no other char than */?/.//~v6A0R~
                    break;                                         //~v6A0I~
            *pco++=chp;                                            //~v6A0I~
        }                                                          //~v6A0I~
                                                                   //~v6A0I~
    }                                                              //~v6A0I~
    *pco=0;                                                        //~v6A0I~
    opt=UFCVO_NEW; //chk valid ucs                                 //~v6A0R~
	rc=ufilecvWC2UD(opt,wkpco,wkuds,sizeof(wkuds),&outlen,NULL/*Ppathtbl*/,0/*Ppathctr*/);//~v6A0R~
    strcpy(Pout,wkuds);                                            //~v6A0I~
    UTRACEP("%s:in=%s,pattern=%s,out=%s\n",UTT,Pin,Ppat,Pout);     //~v6A0I~
    UTRACED("out",Pout,outlen);                                    //~v6A0R~
    return 0;                                                      //~v6A0I~
}//udoseditnameUD                                                  //~v6A0I~
#endif  //W32UNICODE                                               //~v6A0I~
//*******************************************************          //~v272M~
//*udoseditname                                                    //~v272M~
//*   covert filename by patern(no path support)                   //~v272R~
//*DEN_UNIX is for uftprename                                      //~v6u9I~
//*parm 1:source filename                                          //~v272M~
//*parm 2:patern string                                            //~v272M~
//*parm 3:sout area addr                                           //~v272M~
//*ret   :0 or ENAMETOOLONG                                        //~v272R~//~v6H1R~
//*******************************************************          //~v272M~
int udoseditname(int Popt,UCHAR *Pin,UCHAR *Ppat,UCHAR *Pout)      //~v56xR~
{                                                                  //~v272M~
    UCHAR  chp,*pci,*pco,*pcp,*pcie,wk[_MAX_PATH];                 //~v272R~
//  UCHAR  dbcsi[_MAX_PATH],dbcsp[_MAX_PATH],*pdbcsi,*pdbcsp;      //~v56xI~//~v6H1R~
    UCHAR  dbcsi[_MAX_PATH2],dbcsp[_MAX_PATH2],*pdbcsi,*pdbcsp;    //~v6H1I~
    int    leni,lenp;                                              //~v56xI~
    int    msw;                                                    //~v56xI~
#ifdef W32UNICODE                                                  //~v6u9I~
//    int swud=0;                                                    //~v6u9I~//~v6A0R~
    int udopt=0;                                                   //~v6A0R~
#endif                                                             //~v6u9I~
#ifdef LNX                                                         //~v6A0I~
	int u8csz;                                                     //~v6A0R~
	ULONG ulucs;                                                   //~v6A0I~
#endif                                                             //~v6A0I~
	int dbcssz,reslen,ii;                                          //~v6A0R~
//*****************                                                //~v272M~
    pcie=Pin+strlen(Pin);                                          //~v272M~
    pcp=Ppat; pci=Pin; pco=wk;                                     //~v272R~
//  leni=(int)((ULONG)pcie-(ULONG)Pin);                            //~v56xI~//~v6hhR~
    leni=(int)((ULPTR)pcie-(ULPTR)Pin);                            //~v6hhI~
    lenp=(int)strlen(Ppat);                                        //~v56xI~
#ifdef W32UNICODE                                                  //~v6A0I~
    udopt|=(memchr(Pin,UD_NOTLC,leni)!=0)*UDENUDO_UDI;             //~v6A0I~
    udopt|=(memchr(Ppat,UD_NOTLC,lenp)!=0)*UDENUDO_UDP;            //~v6A0I~
    if (udopt)                                                     //~v6A0I~
        if (!udoseditnameUD(udopt,Popt,Pin,leni,Ppat,lenp,Pout))   //~v6A0I~
        	return 0;                                              //~v6A0I~
#endif                                                             //~v6A0I~
    usetdbcstbl(USDT_CODE_DEFAULT,Pin,dbcsi,leni);                 //~v56xR~
    UTRACED("dbcsi",dbcsi,leni);                                   //~v6A0I~
    usetdbcstbl(USDT_CODE_DEFAULT,Ppat,dbcsp,lenp);                //~v56xR~
    chp=*pcp;             //for compiler warning                   //~v327I~
    while(pci<pcie)                                                //~v272M~
    {                                                              //~v272M~
        chp=*pcp++;             //patern                           //~v272M~
        switch(chp)                                                //~v272M~
        {                                                          //~v272M~
        case '*':                                                  //~v272M~
            chp=*pcp;       //next of '*'                          //~v272M~
            while (chp=='*')    //ignore double '*'                //~v272M~
                chp=*++pcp;                                        //~v272M~
//          pdbcsp=dbcsp+((ULONG)pcp-(ULONG)Ppat);                 //~v56xI~//~v6hhR~
            pdbcsp=dbcsp+((ULPTR)pcp-(ULPTR)Ppat);                 //~v6hhI~
//          pdbcsi=dbcsi+((ULONG)pci-(ULONG)Pin);                  //~v56xI~//~v6hhR~
            pdbcsi=dbcsi+((ULPTR)pci-(ULPTR)Pin);                  //~v6hhI~
            while (pci<pcie)                                       //~v272M~
            {                                                      //~v272M~
//              if (toupper(chp)==toupper(*pci))                   //~v56xR~
//                  break;                                         //~v56xI~
                msw=0;                      //match sw             //~v56xI~
UTRACEP("chk input=%x,pat=%x,dbcsi=%x,dbcsp=%x\n",*pci,*pcp,*pdbcsi,*pdbcsp);//~v62UR~
                if (*pdbcsi==*pdbcsp)   //same dbcs type           //~v56xI~
//#ifdef W32UNICODE                                                //~v6A0R~
//                if (chp!=UD_NOTLC) //not match of UD string id   //~v6A0R~
//#endif                                                           //~v6A0R~
                {                                                  //~v5crI~
                    if (chp==*pci)                                 //~v56xI~
                    {                                              //~v56xI~
                        if (*pdbcsi==UDBCSCHK_DBCS1ST)             //~v56xI~
                        {                                          //~v56xI~
							if (*(pci+1)==*(pcp+1))                //~v56xI~
                            {                                      //~v62UR~
#ifdef UTF8SUPPH                                                   //~v62UI~
							  if (UDBCSCHK_ISGB42ND(*(pci+1)))	//GB4 2nd byte//~v62UR~
                              {                                    //~v62UR~
								if (*(pci+2)==*(pcp+2)             //~v62UR~
								&&  *(pci+3)==*(pcp+3)             //~v62UR~
                                )                                  //~v62UR~
                                msw=1;                             //~v62UR~
                              }                                    //~v62UR~
                              else                                 //~v62UR~
#endif                                                             //~v62UI~
                                msw=1;                             //~v56xI~
                            }                                      //~v62UR~
                        }                                          //~v56xI~
                        else      //sbcs or 2nd byte               //~v56xI~
                        	msw=1;                                 //~v56xI~
                    }                                              //~v56xI~
                    else        //char unmatch                     //~v56xI~
                    	if (!*pdbcsi)	//sbcs                     //~v56xR~
              				if (!(Popt & DEN_CASE)) 	//case insensitive//~v56xR~
                				if (toupper(chp)==toupper(*pci))   //~v56xI~
                                	msw=1;                         //~v56xI~
                }//dbcs type                                       //~v5crI~
                if (msw)                                           //~v56xI~
                {                                                  //~v6u9I~
//#ifdef W32UNICODE                                                  //~v6u9I~//~v6A0R~
//                    if (swud)                                      //~v6u9I~//~v6A0R~
//                    {                                              //~v6u9I~//~v6A0R~
//                        int offs;                                  //~v6u9I~//~v6A0R~
//                        offs=PTRDIFF(pco,wk);                      //~v6u9R~//~v6A0R~
//                        if (offs>=2 && *(pco-2)==UD_NOTLC) //ud strlen=0//~v6u9I~//~v6A0R~
//                            pco-=2;                                //~v6u9I~//~v6A0R~
//                        else                                       //~v6u9I~//~v6A0R~
//                            *pco++=UD_NOTLC;                       //~v6u9R~//~v6A0R~
//                        swud=0;                                    //~v6u9I~//~v6A0R~
//                    }                                              //~v6u9I~//~v6A0R~
//#endif                                                             //~v6u9I~//~v6A0R~
#ifdef LNX                                                         //~v6A0I~
                    if (!isSameU8c(0,pci,(int)PTRDIFF(pcie,pci),pcp,&u8csz)//~v6A0R~
                    && u8csz>1)	//unmatch and start of utf char    //~v6A0I~
                    {                                              //~v6A0I~
                    	msw=0;                                     //~v6A0I~
                        for (ii=1;ii<u8csz;ii++) //copy except last char//~v6A0R~
				            *pco++=*pci++;                         //~v6A0R~
            			pdbcsi+=u8csz-1;                           //~v6A0R~
                    }                                              //~v6A0I~
                  if (msw)                                         //~v6A0I~
#endif                                                             //~v6A0I~
                    break;                                         //~v56xI~
                }                                                  //~v6u9I~
UTRACEP("copy input=%x\n",*pci);                                   //~v62UR~
//#ifdef W32UNICODE                                                  //~v6u9I~//~v6A0R~
//                if (*pci==UD_NOTLC)                                //~v6u9I~//~v6A0R~
//                    swud=~swud;                                    //~v6u9I~//~v6A0R~
//#endif                                                             //~v6u9I~//~v6A0R~
                *pco++=*pci++;                                     //~v272M~
            	pdbcsi++;                                          //~v62SR~
            }                                                      //~v272M~
            break;                                                 //~v272M~
        case '?':                                                  //~v272M~
            if (*pci=='.')        //nop when '.'                   //~v290R~
                break;                                             //~v290I~
//#ifdef W32UNICODE                                                  //~v6u9I~//~v6A0R~
//            if (*pci==UD_NOTLC)                                    //~v6u9I~//~v6A0R~
//            {                                                      //~v6u9I~//~v6A0R~
//                *pco++=*pci++;                                     //~v6u9I~//~v6A0R~
//                swud=~swud;                                        //~v6u9I~//~v6A0R~
//            }                                                      //~v6u9I~//~v6A0R~
//#endif                                                             //~v6u9I~//~v6A0R~
            pdbcsi=dbcsi+((ULPTR)pci-(ULPTR)Pin);                  //~v6A0M~
            reslen=(int)PTRDIFF(pcie,pci);                         //~v6A0I~
#ifdef LNX                                                         //~v6A0I~
	    	if (!utfgetwc(pci,reslen,&ulucs,&u8csz)                //~v6A0R~
            && u8csz>1)	//ut8 char                                 //~v6A0I~
            {                                                      //~v6A0I~
            	for (ii=1;ii<u8csz;ii++) //copy except last char   //~v6A0I~
					*pco++=*pci++;                                 //~v6A0I~
            }                                                      //~v6A0I~
            else                                                   //~v6A0I~
#endif                                                             //~v6A0I~
	    	if (*pdbcsi==UDBCSCHK_DBCS1ST)                         //~v6A0I~
        	{                                                      //~v6A0I~
	            dbcssz=UDBCSCHK_PCD_MBCHSZ(pdbcsi,reslen);         //~v6A0R~
                for (ii=1;ii<dbcssz;ii++) //copy except last char  //~v6A0I~
					*pco++=*pci++;                                 //~v6A0I~
            }                                                      //~v6A0I~
            *pco++=*pci++;  //copy from patern                     //~v272M~
            break;                                                 //~v272M~
        case '.':                                                  //~v272M~
//#ifdef UNX                                                       //~v50UR~
//        if (Sdenopt & DEN_UNIX)                                  //~v56xR~
          if (Popt & DEN_UNIX)                                     //~v56xI~
          {                      //same as default                 //~v388I~
            *pco++=chp; //copy from patern                         //~v388I~
	        pci++;      //pass input char                          //~v388I~
            break;                                                 //~v388I~
          }                                                        //~v388I~
//#endif //UNX                                                     //~v50UR~
            while(pci<pcie) //all base                             //~v272M~
                if (*pci++=='.')                                   //~v272M~
                    break;                                         //~v272M~
            *pco++='.';                                            //~v272M~
            break;                                                 //~v272M~
        case  0:                                                   //~v290I~
            break;                                                 //~v290I~
        default:                                                   //~v272M~
            *pco++=chp; //copy from patern                         //~v272M~
//#ifdef UNX                                                       //~v50UR~
//        if (Sdenopt & DEN_UNIX)                                  //~v56xR~
          if (Popt & DEN_UNIX)                                     //~v56xI~
	            pci++;      //pass input char                      //~v388I~
          else                                                     //~v388I~
//#endif //UNX                                                     //~v50UR~
          if (*pci!='.')                                           //~v290I~
            pci++;      //pass input char                          //~v272M~
        }                                                          //~v272M~
        if (!chp)                                                  //~v290I~
            break;                                                 //~v290I~
    }//while input exist                                           //~v272M~
//copy residual of patern                                          //~v272M~
//  do                                                             //~v290R~
    while(chp)                                                     //~v290I~
    {                                                              //~v272M~
        chp=*pcp++;                                                //~v272M~
        if (!chp)                                                  //~v290I~
            break;                                                 //~v290I~
        if (chp!='*' && chp!='?')                                  //~v272M~
        {                                                          //~v340R~
//#ifdef UNX                                                       //~v50UR~
//        if (!(Sdenopt & DEN_UNIX))                               //~v56xR~
          if (!(Popt & DEN_UNIX))                                  //~v56xI~
//#endif //UNX                                                     //~v50UR~
            if (chp=='.')                                          //~v340R~
        		if (strlen(pcp)==strspn(pcp,"*?."))	//no other char than */?/.//~v340R~
                    break;                                         //~v340R~
            *pco++=chp;                                            //~v272M~
        }                                                          //~v340R~
                                                                   //~v272M~
//  }while(chp);                                                   //~v290R~
    }                                                              //~v290I~
//#ifdef W32UNICODE                                                //~v6u9R~
//    {                                                            //~v6u9R~
//        int udctr=0,ii,outlen;                                   //~v6u9R~
//        outlen=PTRDIFF(pco,wk);                                  //~v6u9R~
//        for (ii=0,pco=wk;ii<outlen;ii++)                         //~v6u9R~
//            if (*pco++==UD_NOTLC)                                //~v6u9R~
//                udctr++;                                         //~v6u9R~
//        if (udctr%2)                                             //~v6u9R~
//            *pco++=UD_NOTLC;                                     //~v6u9R~
//    }                                                            //~v6u9R~
//#endif                                                           //~v6u9R~
    *pco=0;                                                        //~v272I~
//  strcpy(Pout,wk);                                               //~v272I~//~v6H1R~
    UstrncpyZ(Pout,wk,_MAX_PATH);                                  //~v6H1R~
    UTRACEP("%s:in=%s,pattern=%s,out=%s\n",UTT,Pin,Ppat,Pout);     //~v6u9I~
	UMAXPATHCHK(wk,_MAX_PATH,ENAMETOOLONG,1/*msgsw*/);             //~v6H1I~
    return 0;                                                      //~v272M~
}//udoseditname                                                    //~v272M~
                                                                   //~v279I~
//*******************************************************          //~v279I~
//*ufileeditname                                                   //~v279I~
//*   covert last filename by patern(source may contain path)      //~v279I~
//*parm 1:option  for udoseditname                                 //~v56xR~
//*parm 2:source pathname                                          //~v56xI~
//*parm 3:patern pathname(only last is wild card)                  //~v56xR~
//*parm 4:out area addr                                            //~v56xR~
//*       if patern is fullpath format output is of patern path,   //~v279I~
//        else patern path is concatinate to source path           //~v279I~
//*ret   :always 0                                                 //~v279I~
//*******************************************************          //~v279I~
int ufileeditname(int Popt,UCHAR *Psource,UCHAR *Ppatern,UCHAR *Ptarget)//~v56xR~
{                                                                  //~v279I~
    int pathlens,pathlenp,pathlent;                                //~v279I~
    int fpathsw=0;                                                 //~v5crI~
//  UCHAR wk[_MAX_PATH];                                           //~v279I~//~v6H1R~
    UCHAR wk[_MAX_PATH2];                                          //~v6H1I~
#ifdef FTPSUPP                                                     //~v5crI~
    PUFTPHOST puftph;                                              //~v5crI~
#endif                                                             //~v5crI~
	int rc;                                                        //~v6H1I~
//*****************                                                //~v279I~
#ifdef FTPSUPP                                                     //~v5jdI~
  	if (uftpisremote(Ppatern,&puftph))		//ftp filename         //~v5jdI~
  	{                                                              //~v5jdI~
    	if (UFTPHISTSO(puftph))                                    //~v5jdI~
        	return u3270editname(puftph,U3EN_WILDSOURCE,Ppatern,Psource,Ptarget);//~v5jdI~
  	}                                                              //~v5jdI~
  	if (uftpisremote(Psource,&puftph))		//ftp filename         //~v5jdI~
  	{                                                              //~v5jdI~
    	if (UFTPHISTSO(puftph))                                    //~v5jdI~
        	return u3270editname(puftph,U3EN_WILDSOURCE|U3EN_SRCLOCAL,Ppatern,Psource,Ptarget);//~v5jdR~
  	}                                                              //~v5jdI~
#endif                                                             //~v5jdI~
    if ((pathlens=PATHLEN(Psource))<0)                             //~v279R~
        pathlens=0;     //no path                                  //~v279I~
                                                                   //~v279I~
    if ((pathlenp=PATHLEN(Ppatern))<0)                             //~v279R~
        pathlenp=0;                                                //~v279I~
                                                                   //~v279I~
#ifdef FTPSUPP                                                     //~v5crI~
  if (uftpisremote(Ppatern,&puftph))		//ftp filename         //~v5crI~
  {                                                                //~v5crI~
    	if (Ppatern[puftph->UFTPHhostnmlen+1]==FTP_DIR_SEPC)       //~v5crI~
        	fpathsw=1;                                             //~v5crI~
  }                                                                //~v5crI~
  else//local                                                      //~v5crI~
  {                                                                //~v5crI~
#endif                                                             //~v5crI~
#ifdef UNX                                                         //~v327I~
//  if (Ppatern[0]==DIR_SEPC)    //fullpath                        //~v55hR~
    if (Ppatern[0]==DIR_SEPC     //fullpath                        //~v55hI~
    ||    (MDOSDISKOK(Ppatern)                                     //~v55hI~
        && Ppatern[2]==DIR_SEPC))                                  //~v55hI~
        fpathsw=1;                                                 //~v5crI~
#else                                                              //~v327I~
    if (Ppatern[1]==':' && Ppatern[2]=='\\')    //fullpath         //~v279I~
        fpathsw=1;                                                 //~v5crI~
  #ifdef WINREMOTESUPP     //\\xxx\yy support                      //~v5nAI~
    if (WIN_ISREMOTEPATH(Ppatern))                                 //~v5nAR~
        fpathsw=1;                                                 //~v5nAI~
  #endif                                                           //~v5nAI~
#endif                                                             //~v327I~
#ifdef FTPSUPP                                                     //~v5crI~
  }//local                                                         //~v5crI~
#endif                                                             //~v5crI~
	if (fpathsw)                                                   //~v5crI~
    {                                                              //~v279I~
        memcpy(wk,Ppatern,(UINT)pathlenp);   //repl by patern      //~v279R~
        pathlent=pathlenp;                                         //~v279I~
    }                                                              //~v279I~
    else                                                           //~v279I~
    {                                                              //~v279I~
        memcpy(wk,Psource,(UINT)pathlens);                         //~v279R~
        memcpy(wk+pathlens,Ppatern,(UINT)pathlenp);   //add to source//~v279R~
        pathlent=pathlens+pathlenp;                                //~v279I~
    }                                                              //~v279I~
//  udoseditname(Psource+pathlens,Ppatern+pathlenp,wk+pathlent);   //~v56xR~
  rc=                                                              //~v6H1I~
    udoseditname(Popt,Psource+pathlens,Ppatern+pathlenp,wk+pathlent);//~v56xR~
//  strcpy(Ptarget,wk);                                            //~v279I~//~v6H1R~
    UstrncpyZ(Ptarget,wk,_MAX_PATH);                               //~v6H1R~
    UTRACEP("%s:in=%s,pattern=%s,out=%s\n",UTT,Psource,Ppatern,Ptarget);//~v6H1I~
  	if (!rc)                                                       //~v6H1I~
  	{                                                              //~v6H1I~
		UMAXPATHCHK(wk,_MAX_PATH,ENAMETOOLONG,1/*msgsw*/);         //~v6H1I~
  	}                                                              //~v6H1I~
//  return 0;                                                      //~v279I~//~v6H1R~
    return rc;                                                     //~v6H1I~
}//ufileeditname                                                   //~v279I~
//*******************************************************          //~v56yI~
//*ufilewildcomp                                                   //~v56yI~
//*   wildcard matching                                            //~v56yI~
//*parm 1:option   dos type "." usage,case sense,"*" is for 0-byte //~v56yI~
//*parm 2:source filename                                          //~v56yI~
//*parm 3:patern string                                            //~v56yI~
//*ret   :0:match,4:unmatch                                        //~v56yI~
//*******************************************************          //~v56yI~
int ufilewildcomp(int Popt,UCHAR *Pin,UCHAR *Ppat,UCHAR *Pdbcsp)   //~v56yI~
{                                                                  //~v56yI~
#define UNMATCH 4                                                  //~v56yI~
    UCHAR  *pci,*pcp,*pcp0,*pcie,*pcpe,*pc;                        //~v56yR~
    UCHAR  dbcsp[_MAX_PATH],dbcsi[_MAX_PATH],*pdbcsp;              //~v56yI~
    int ii,leni,lenp,complen,topsw;                                //~v56yI~
//*****************                                                //~v56yI~
//printf("entry opt=%x,in=%s,pat=%s\n",Popt,Pin,Ppat);             //~v56yR~
    leni=(int)strlen(Pin);                                         //~v56yI~
    lenp=(int)strlen(Ppat);                                        //~v56yI~
    if (pdbcsp=Pdbcsp,!pdbcsp)                                     //~v56yI~
    {                                                              //~v56yI~
    	pdbcsp=dbcsp;                                              //~v56yI~
        usetdbcstbl(USDT_CODE_DEFAULT,Ppat,dbcsp,lenp);            //~v56xR~
    }                                                              //~v56yI~
    usetdbcstbl(USDT_CODE_DEFAULT,Pin,dbcsi,leni);                 //~v56xR~
    pcie=Pin+leni;                                                 //~v56yI~
    pcpe=Ppat+lenp;                                                //~v56yI~
    pcp=Ppat;                                                      //~v56yI~
    pci=Pin;                                                       //~v56yI~
    while(pcp<pcpe)                                                //~v56yI~
    {                                                              //~v56yI~
    	for (pcp0=pcp;*pcp=='*';pcp++)                             //~v56yI~
        	if (!(Popt & UFWC_0BYTE))                              //~v56yI~
            	pci++;                                             //~v56yI~
        if (pci>pcie)                                              //~v56yI~
            return UNMATCH;                                        //~v56yI~
        if (pcp>=pcpe)                                             //~v56yI~
        {                                                          //~v56yI~
            pci=pcie;                                              //~v56yI~
        	break;		//match                                    //~v56yI~
        }                                                          //~v56yI~
        if (pcp==pcp0)	//no preceding '*'                         //~v56yI~
        	topsw=1;	//chk head string only                     //~v56yI~
        else                                                       //~v56yI~
        	topsw=0;	//                                         //~v56yI~
        if (pc=strchr(pcp,'*'),pc)	//followed by more '*'         //~v56yI~
//        	complen=(int)((ULONG)pc-(ULONG)pcp);                   //~v56yI~//~v6hhR~
        	complen=(int)((ULPTR)pc-(ULPTR)pcp);                   //~v6hhI~
        else                                                       //~v56yI~
        	complen=(int)strlen(pcp);                              //~v56yI~
        if (pci+complen>pcie)                                      //~v56yI~
            return UNMATCH;                                        //~v56yI~
//      for (ii=(int)((ULONG)pcie-(ULONG)pci)-complen;ii>=0;ii--,pci++) //~v56yI~//~v6hhR~
        for (ii=(int)((ULPTR)pcie-(ULPTR)pci)-complen;ii>=0;ii--,pci++)//~v6hhI~
        {                                                          //~v56yI~
        	pc=ufilewildcompsub(Popt,complen,pci,pcp,              //~v56yI~
//							dbcsi+((ULONG)pci-(ULONG)Pin),         //~v56yI~//~v6hhR~
							dbcsi+((ULPTR)pci-(ULPTR)Pin),         //~v6hhI~
//							pdbcsp+((ULONG)pcp-(ULONG)Ppat));//match//~v56yI~//~v6hhR~
							pdbcsp+((ULPTR)pcp-(ULPTR)Ppat));//match//~v6hhI~
UTRACEP("ufilewildcompsub ret %p=%s,complen=%d,topsw=%d,in=%s,pat=%s\n",pc,pc,complen,topsw,pci,pcp);//~v6hFR~
        	if (pc)	//matched,next chk source string               //~v56yI~
            	break;                                             //~v56yI~
            if (topsw)       //match should be head                //~v56yI~
            	return UNMATCH;                                    //~v56yI~
        }                                                          //~v56yI~
        if (!pc)                                                   //~v56yI~
            return UNMATCH;                                        //~v56yI~
        pci=pc;                                                    //~v56yI~
        pcp+=complen;                                              //~v56yI~
    }                                                              //~v56yI~
    if (pci<pcie)   //remain input                                 //~v56yI~
        return UNMATCH;                                            //~v56yI~
    return 0;                                                      //~v56yI~
}//ufilewildcomp                                                   //~v56yI~
//*******************************************************          //~v56yI~
//*ufilewildcompsub                                                //~v56yI~
//*   wildcard matching                                            //~v56yI~
//*parm 1:option                                                   //~v56yI~
//*parm 2:compare position sw; 1:top,2:last;0:in the full string   //~v56yI~
//*parm 3:compare patern string length                             //~v56yI~
//*parm 4:source filename                                          //~v56yI~
//*parm 5:patern string                                            //~v56yI~
//*parm 6:dbcs tbl of source filename                              //~v56yI~
//*parm 7:dbcs tbl of patern string                                //~v56yI~
//*ret   :next of source string                                    //~v56yI~
//*******************************************************          //~v56yI~
UCHAR *ufilewildcompsub(int Popt,int Pcomplen,                     //~v56yI~
					UCHAR *Pin,UCHAR *Ppat,UCHAR *Pdbcsi,UCHAR *Pdbcsp)//~v56yI~
{                                                                  //~v56yI~
    UCHAR  *pci,*pcp,*pcdi,*pcdp;                                  //~v56yI~
    int ii;                                                        //~v56yR~
//*****************                                                //~v56yI~
	for (ii=0,pci=Pin,pcp=Ppat,pcdi=Pdbcsi,pcdp=Pdbcsp;            //~v56yI~
//  			*pci && ii<Pcomplen;                               //~v5fkR~
    			ii<Pcomplen && *pci;                               //~v5fkI~
					ii++,pcp++,pcdp++,pci++,pcdi++)                //~v56yI~
    {                                                              //~v56yI~
    	switch(*pcp)                                               //~v56yI~
        {                                                          //~v56yI~
        case '?':                                                  //~v56yI~
            if (Popt & UFWC_DOS)                                   //~v56yI~
  		      	if (*pci=='.')                                     //~v56yI~
                	return 0;                                      //~v56yI~
        	break;                                                 //~v56yI~
        default:                                                   //~v56yI~
//printf("pcdi=%p=%c ;pcdp=%p=%c\n",pcdi,*pcdi,pcdp,*pcdp);        //~v56yR~
        	if (*pcdi!=*pcdp)	//dbcs type unmatch                //~v56yI~
                return 0;                                          //~v56yI~
            if (*pci!=*pcp)                                        //~v56yI~
            {                                                      //~v5crI~
            	if (Popt & UFWC_CASE)                              //~v56yI~
	                return 0;                                      //~v56yI~
                else                                               //~v56yI~
            	if (*pcdi)		//dbcs char                        //~v56yI~
	                return 0;                                      //~v56yI~
                else			//sbcs                             //~v56yI~
            	if (toupper(*pci)!=toupper(*pcp))                  //~v56yI~
	                return 0;                                      //~v56yI~
            }//!=                                                  //~v5crI~
        }//sw                                                      //~v56yI~
    }                                                              //~v56yI~
    if (ii<Pcomplen)                                               //~v56yI~
    	return 0;	//remain patern string                         //~v56yI~
    if (!*pcp && *pci)	//remain source string                     //~v56yI~
    	return 0;                                                  //~v56yI~
	return pci;                                                    //~v56yI~
}//ufilewildcompsub                                                //~v56yI~
//*********************************************************************//~v5j8I~
//#define COMP_BUFFSZ  	32760   //32k                              //~v5kgR~
#ifdef DOSDOS                                                      //~v5kgI~
#define COMP_BUFFSZ  	8192 //8k                                  //~v5kgI~
#else                                                              //~v5kgI~
#define COMP_BUFFSZ  	32768   //32k                              //~v5kgR~
#endif                                                             //~v5kgI~
//*********************************************************************//~v5j8I~
//* binary compare 2 local file                                    //~v5j8I~
//* return 0:fully equall                                          //~v5j8I~
//*        1:file1 not exist or dir                                //~v5j8I~
//*        2:file2 not exist or dir                                //~v5j8I~
//*        3:both not exist or dir                                 //~v5j8I~
//*        4:size unmatch                                          //~v5j8I~
//*        5:contents unmatch(size is same)                        //~v5j8I~
//*        6:null appended                                         //~v5jtI~
//*        8:other err                                             //~v5j8I~
//*       -n:increased line count by long line split               //~v5kjI~
//*        UALLOC_FAILED                                           //~v5j8I~
//*********************************************************************//~v5j8I~
int ufilecomp(int Popt,char *Pfnm1,char *Pfnm2)                    //~v5j8R~
{                                                                  //~v5j8I~
	FILE *fh1,*fh2;                                                //~v5j8I~
    UINT readlen1,readlen2;                                        //~v5j8I~
    int rc;                                                        //~v5j8I~
    FILEFINDBUF3 fstat31,fstat32;                                  //~v5j8I~
    char *buff1,*buff2;                                            //~v5j8R~
    int eof1=0,eof2=0,nullappend=0;                                //~v5jtR~
    UINT complen,applen;                                           //~v5jtI~
    char *papp;                                                    //~v5jtI~
//*****************************                                    //~v5j8I~
	rc=0;                                                          //~v5j8I~
    if (ufstat(Pfnm1,&fstat31)||(fstat31.attrFile & FILE_DIRECTORY))//~v5j8I~
    	rc|=1;                                                     //~v5j8I~
    if (ufstat(Pfnm2,&fstat32)||(fstat32.attrFile & FILE_DIRECTORY))//~v5j8R~
    	rc|=2;                                                     //~v5j8I~
    if (rc)                                                        //~v5j8I~
    	return rc;                                                 //~v5j8I~
    if (!(buff1=umalloc(COMP_BUFFSZ*2)))                           //~v5j8I~
        return UALLOC_FAILED;                                      //~v5j8I~
    if (Popt & UFCO_TEXT)	//text mode                            //~v5jsI~
    {                                                              //~v5jsI~
		rc=ufilecomptextmode(Popt,Pfnm1,Pfnm2,buff1);              //~v5jsR~
    	ufree(buff1);                                              //~v5jsI~
        return rc;                                                 //~v5jsI~
    }                                                              //~v5jsI~
    buff2=buff1+COMP_BUFFSZ;                                       //~v5j8I~
	if (fstat31.cbFile!=fstat32.cbFile)                            //~v5j8I~
    {                                                              //~v5jsI~
//  	return 4;	//size unmatch                                 //~v5jsR~
      if (!(Popt & UFCO_NULLAPP)) //allow binary mode compare null append for RECFM=Fx//~v5jtR~
      {                                                            //~v5jtI~
    	ufree(buff1);                                              //~v5jsI~
        return UFCRC_SIZE;// 4    //bin compare size unmatch       //~v5jsR~
      }                                                            //~v5jtI~
    }                                                              //~v5jsI~
	if (!(fh1=fopen(Pfnm1,"rb")))                                  //~v5j8I~
    	uerrapi1("fopen",Pfnm1,errno);                             //~v5j8I~
	if (!(fh2=fopen(Pfnm2,"rb")))                                  //~v5j8I~
    	uerrapi1("fopen",Pfnm2,errno);                             //~v5j8I~
    if (fh1 && fh2)                                                //~v5j8I~
    {                                                              //~v5j8I~
//compare                                                          //~v5j8I~
        for (;;)                                                   //~v5j8I~
        {                                                          //~v5j8I~
          if (eof1)                                                //~v5jtI~
          	readlen1=0;                                            //~v5jtI~
          else                                                     //~v5jtI~
          {                                                        //~v5jtI~
//  	    readlen1=fread(buff1,1,COMP_BUFFSZ,fh1);	//read 1 block//~v5j8I~//~v6BxR~
    	    readlen1=(UINT)fread(buff1,1,COMP_BUFFSZ,fh1);	//read 1 block//~v6BxI~
            if (!readlen1)                                         //~v5jtI~
            	eof1=1;                                            //~v5jtI~
          }                                                        //~v5jtI~
          if (eof2)                                                //~v5jtI~
          	readlen2=0;                                            //~v5jtI~
          else                                                     //~v5jtI~
          {                                                        //~v5jtI~
//  	    readlen2=fread(buff2,1,COMP_BUFFSZ,fh2);	//read 1 block//~v5j8I~//~v6BxR~
    	    readlen2=(UINT)fread(buff2,1,COMP_BUFFSZ,fh2);	//read 1 block//~v6BxI~
            if (!readlen2)                                         //~v5jtI~
            	eof2=1;                                            //~v5jtI~
          }                                                        //~v5jtI~
            if (readlen1!=readlen2)                                //~v5j8I~
            {                                                      //~v5jtI~
		      if (!(Popt & UFCO_NULLAPP)) //allow binary mode compare null append for RECFM=Fx//~v5jtI~
            	break;                                             //~v5j8I~
            	if (readlen1<readlen2)                             //~v5jtI~
                {                                                  //~v5jtI~
                	papp=buff2+readlen1;                           //~v5jtI~
                    applen=readlen2-readlen1;                      //~v5jtI~
                    complen=readlen1;                              //~v5jtI~
                }                                                  //~v5jtI~
                else         //readlen1>readlen2                   //~v5jtI~
                {                                                  //~v5jtI~
                	papp=buff1+readlen2;                           //~v5jtI~
                    applen=readlen1-readlen2;                      //~v5jtI~
                    complen=readlen2;                              //~v5jtI~
                }                                                  //~v5jtI~
                if (complen)                                       //~v5jtI~
		            if (memcmp(buff1,buff2,complen))               //~v5jtI~
                    	break;                                     //~v5jtI~
                if (applen)                                        //~v5jtI~
                {                                                  //~v5jtI~
                	if ((UINT)applen!=umemspnc(papp,0,(UINT)applen))	//not all null//~v5jtR~
                    	break;                                     //~v5jtI~
                    else                                           //~v5jtI~
                    	nullappend=1;//null append detected        //~v5jtI~
                }                                                  //~v5jtI~
                continue;                                          //~v5jtI~
            }                                                      //~v5jtI~
            if (!readlen1)                                         //~v5j8I~
            	break;                                             //~v5j8I~
            if (memcmp(buff1,buff2,readlen1))                      //~v5j8R~
                break;                                             //~v5j8I~
        }                                                          //~v5j8I~
        if (readlen1)                                              //~v5j8I~
        	rc=5;		//unmatch                                  //~v5j8I~
        if (nullappend)                                            //~v5jtI~
        	rc=UFCRC_NULLAPP;                                      //~v5jtI~
    }                                                              //~v5j8I~
    else                                                           //~v5jsI~
    	rc=8;                                                      //~v5jsI~
    ufree(buff1);                                                  //~v5j8I~
    if (fh1)                                                       //~v5j8I~
	    fclose(fh1);                                               //~v5j8I~
    if (fh2)                                                       //~v5j8I~
	    fclose(fh2);                                               //~v5j8I~
    return rc;                                                     //~v5j8I~
}//ufilecomp                                                       //~v5j8I~
//*********************************************************************//~v5jsI~
//* text modecompare 2 local file                                  //~v5jsI~
//*        5:contents unmatch(size is same)                        //~v5jsI~
//*        8:other err                                             //~v5jsI~
//*       -n:increased line count by long line split               //~v5kgR~
//*********************************************************************//~v5jsI~
int ufilecomptextmode(int Popt,char *Pfnm1,char *Pfnm2,char *Pbuff)//~v5jsI~
{                                                                  //~v5jsI~
	FILE *fh1,*fh2;                                                //~v5jsI~
    UINT len1,len2,lenc,lenr;                                      //~v5jsR~
    int rc;                                                        //~v5jsI~
    char *buff1,*buff2,*pc1,*pc2,*pc=NULL;                              //~v5jsR~//~v6h6R~
//*****************************                                    //~v5jsI~
	rc=0;                                                          //~v5jsI~
    buff1=Pbuff;                                                   //~v5jsI~
    buff2=buff1+COMP_BUFFSZ;                                       //~v5jsI~
	if (!(fh1=fopen(Pfnm1,"r")))                                   //~v5jsI~
    	uerrapi1("fopen",Pfnm1,errno);                             //~v5jsI~
	if (!(fh2=fopen(Pfnm2,"r")))                                   //~v5jsI~
    	uerrapi1("fopen",Pfnm2,errno);                             //~v5jsI~
    if (fh1 && fh2)                                                //~v5jsI~
    {                                                              //~v5jsI~
//compare                                                          //~v5jsI~
      if (Popt & UFCO_F1FIXED)                                     //~v5kgR~
    	rc=ufilecomptextmodefixed(Popt,Pfnm2,Pfnm1,fh2,fh1,buff2,buff1);//~v5kgR~
      else                                                         //~v5kgR~
      if (Popt & UFCO_F2FIXED)                                     //~v5kgR~
    	rc=ufilecomptextmodefixed(Popt,Pfnm1,Pfnm2,fh1,fh2,buff1,buff2);//~v5kgR~
      else                                                         //~v5kgR~
      {                                                            //~v5kgR~
        for (;;)                                                   //~v5jsI~
        {                                                          //~v5jsI~
		    pc1=fgets(buff1,COMP_BUFFSZ,fh1);	//read 1 block     //~v5jsI~
		    pc2=fgets(buff2,COMP_BUFFSZ,fh2);	//read 1 block     //~v5jsI~
            if (!pc1 && !pc2)    //both eof                        //~v5jsI~
            	break;                                             //~v5jsI~
            if (!pc1 || !pc2)    //one is eof                      //~v5jsI~
            	break;                                             //~v5jsI~
            if (!(Popt & UFCO_TSPACE))	//no trailing space chk    //~v5jsI~
            {                                                      //~v5jsI~
            	if (strcmp(pc1,pc2)) //unmatch                     //~v5jsI~
                {                                                  //~v5jsI~
//                  printf("txt unmatch %s!=%s",pc1,pc2);          //~v5jsR~
                	break;                                         //~v5jsI~
                }                                                  //~v5jsI~
                continue;                                          //~v5jsI~
            }                                                      //~v5jsI~
//          len1=strlen(pc1);                                      //~v5jsI~//~v6BxR~
            len1=(UINT)strlen(pc1);                                //~v6BxI~
//          len2=strlen(pc2);                                      //~v5jsI~//~v6BxR~
            len2=(UINT)strlen(pc2);                                //~v6BxI~
            if (len1>len2)                                         //~v5jsI~
            {                                                      //~v5jsI~
                lenc=len2;         //comaprelen                    //~v5jsR~
                if (*(pc2+lenc-1)=='\n')                           //~v5jsI~
                	lenc--;                                        //~v5jsI~
                lenr=len1-lenc;    //spacechk len                  //~v5jsR~
            	pc=pc1+lenc;                                       //~v5jsR~
            }                                                      //~v5jsI~
            else                                                   //~v5jsI~
            if (len1<len2)                                         //~v5jsI~
            {                                                      //~v5jsI~
                lenc=len1;                                         //~v5jsR~
                if (*(pc1+lenc-1)=='\n')                           //~v5jsI~
                	lenc--;                                        //~v5jsI~
                lenr=len2-lenc;                                    //~v5jsR~
            	pc=pc2+lenc;                                       //~v5jsR~
            }                                                      //~v5jsI~
            else  //same len                                       //~v5jsI~
            {                                                      //~v5jsI~
                lenc=len1;                                         //~v5jsI~
                lenr=0;                                            //~v5jsI~
            }                                                      //~v5jsI~
            if (memcmp(pc1,pc2,(UINT)lenc)) //unmatch              //~v5jsI~
            {                                                      //~v5jsI~
//              printf("txt unmatch len=%d %s!=%s",lenc,pc1,pc2);  //~v5jsR~
            	break;                                             //~v5jsI~
            }                                                      //~v5jsI~
            if (!lenr)		//match same len                       //~v5jsI~
                continue;                                          //~v5jsI~
            if (strspn(pc," \n")!=lenr)	//residual is not all space//~v5jsI~
            {                                                      //~v5jsI~
//              printf("txt trailer unmatch lenc=%d lenr=%d,%s!=%s,trailer=%s",lenc,lenr,pc1,pc2,pc);//~v5jsR~
            	break;                                             //~v5jsI~
            }                                                      //~v5jsI~
        }                                                          //~v5jsI~
        if (pc1 || pc2)   //not both eof                           //~v5jsI~
        	rc=5;		//unmatch                                  //~v5jsI~
      }//not fixed chk                                             //~v5kgR~
    }                                                              //~v5jsI~
    else                                                           //~v5jsI~
    	rc=8;                                                      //~v5jsI~
    if (fh1)                                                       //~v5jsI~
	    fclose(fh1);                                               //~v5jsI~
    if (fh2)                                                       //~v5jsI~
	    fclose(fh2);                                               //~v5jsI~
    return rc;                                                     //~v5jsI~
}//ufilecomptextmode                                               //~v5kgR~
//*********************************************************************//~v5kgR~
//* text mode compare 2 local file to confirm upload pc file to host fixed LRECL//~v5kgR~
//* (allow long file split by fixed LRECL)                         //~v5kgR~
//* file1:pc not fiex,file2 fixed                                  //~v5kgR~
//*        5:contents unmatch(size is same)                        //~v5kgR~
//*       -n:increased line count by long line split               //~v5kgR~
//*        8:other err                                             //~v5kgR~
//*********************************************************************//~v5kgR~
int ufilecomptextmodefixed(int Popt,char *Pfnm1,char *Pfnm2,FILE *Pfh1,FILE* Pfh2,char *Pbuff1,char *Pbuff2)//~v5kgR~
{                                                                  //~v5kgR~
    UINT len1,len2;                                                //~v5kgR~
    int rc,lrecl,rlen,rc2,splitcnt=0;                              //~v5kgR~
    char *pc1,*pc2,*pc;                                            //~v5kgR~
//*****************************                                    //~v5kgR~
    lrecl=(int)((UINT)Popt>>16);                                   //~v5kgR~
    rc=0;                                                          //~v5kgR~
    for (;;)                                                       //~v5kgR~
    {                                                              //~v5kgR~
        pc1=fgets(Pbuff1,COMP_BUFFSZ,Pfh1);   //read 1 block       //~v5kgR~
        pc2=fgets(Pbuff2,COMP_BUFFSZ,Pfh2);   //read 1 block       //~v5kgR~
        if (!pc1 && !pc2)    //both eof                            //~v5kgR~
            break;                                                 //~v5kgR~
        if (!pc1 || !pc2)    //one is eof                          //~v5kgR~
            break;                                                 //~v5kgR~
//      len1=strlen(pc1);                                          //~v5kgR~//~v6BxR~
        len1=(UINT)strlen(pc1);                                    //~v6BxI~
//      len2=strlen(pc2);                                          //~v5kgR~//~v6BxR~
        len2=(UINT)strlen(pc2);                                    //~v6BxI~
        if (len1 && *(pc1+len1-1)=='\n')                           //~v5kgR~
            len1--;                                                //~v5kgR~
        for (rlen=(int)len1,pc=Pbuff1;;)                           //~v5kgR~
        {                                                          //~v5kgR~
            if (len2 && *(pc2+len2-1)=='\n')                       //~v5kgR~
                len2--;                                            //~v5kgR~
            len1=(UINT)(min(rlen,lrecl));                          //~v5kgR~
            rc2=ufilecomptextmodesub(Popt,pc,Pbuff2,(int)len1,(int)len2);//~v5kgR~
            if (rc2)    //unmatch                                  //~v5kgR~
                break;                                             //~v5kgR~
            rlen-=(int)len1;                                       //~v5kgR~
            pc+=len1;                                              //~v5kgR~
            if (!rlen)                                             //~v5kgR~
                break;                                             //~v5kgR~
            if ((Popt & UFCO_TSPACE))   //no trailing space chk    //~v5kgR~
                if (umemspnc(pc,' ',(UINT)rlen)==(UINT)rlen) //residual is all space//~v5kgR~
                    break;      //chk new record                   //~v5kgR~
            pc2=fgets(Pbuff2,COMP_BUFFSZ,Pfh2);   //read 1 block   //~v5kgR~
            splitcnt++;                                            //~v5kgR~
            if (!pc2)                                              //~v5kgR~
                break;                                             //~v5kgR~
//          len2=strlen(pc2);                                      //~v5kgR~//~v6BxR~
            len2=(UINT)strlen(pc2);                                //~v6BxI~
        }                                                          //~v5kgR~
        if (rc2||!pc2)  //unmatch or file2 eof                     //~v5kgR~
            break;                                                 //~v5kgR~
    }//for by file1                                                //~v5kgR~
    if (pc1 || pc2)   //not both eof                               //~v5kgR~
        rc=5;       //unmatch                                      //~v5kgR~
    else                                                           //~v5kgR~
        if (splitcnt)                                              //~v5kgR~
            rc=-splitcnt;                                          //~v5kgR~
    return rc;                                                     //~v5kgR~
}//ufilecomptextmodefixed                                          //~v5kgR~
//*********************************************************************//~v5kgR~
//* text mode compare sub                                          //~v5kgR~
//* 4:unmatch                                                      //~v5kgR~
//*********************************************************************//~v5kgR~
int ufilecomptextmodesub(int Popt,char *Pdata1,char *Pdata2,int Plen1,int Plen2)//~v5kgR~
{                                                                  //~v5kgR~
    UINT len1,len2,lenc,lenr;                                      //~v5kgR~
    char *pc=NULL;                                                      //~v5kgR~//~v6h6R~
//**************************                                       //~v5kgR~
    len1=(UINT)Plen1;                                              //~v5kgR~
    len2=(UINT)Plen2;                                              //~v5kgR~
    if (len1>len2)                                                 //~v5kgR~
    {                                                              //~v5kgR~
        lenc=len2;         //comaprelen                            //~v5kgR~
        lenr=len1-lenc;    //spacechk len                          //~v5kgR~
        pc=Pdata1+lenc;                                            //~v5kgR~
    }                                                              //~v5kgR~
    else                                                           //~v5kgR~
    if (len1<len2)                                                 //~v5kgR~
    {                                                              //~v5kgR~
        lenc=len1;                                                 //~v5kgR~
        lenr=len2-lenc;                                            //~v5kgR~
        pc=Pdata2+lenc;                                            //~v5kgR~
    }                                                              //~v5kgR~
    else  //same len                                               //~v5kgR~
    {                                                              //~v5kgR~
        lenc=len1;                                                 //~v5kgR~
        lenr=0;                                                    //~v5kgR~
    }                                                              //~v5kgR~
    if (memcmp(Pdata1,Pdata2,(UINT)lenc)) //unmatch                //~v5kgR~
        return 4;                                                  //~v5kgR~
    if (!lenr)      //match same len                               //~v5kgR~
        return 0;                                                  //~v5kgR~
    if (!(Popt & UFCO_TSPACE))  //no trailing space chk            //~v5kgR~
        return 4;                                                  //~v5kgR~
    if (umemspnc(pc,' ',(UINT)lenr)!=lenr) //residual is not all space//~v5kgR~
        return 4;                                                  //~v5kgR~
    return 0;                                                      //~v5kgR~
}//ufilecomptextmodesub                                            //~v5kgR~
//**************************************************************** //~2908I~//~v6hFM~
// read until LF for the line containing null                      //~2908I~//~v6hFM~
// optionally last null is appended                                //~2908R~//~v6hFM~
// split may occurs at buffsz-1 or buffsz-2 with LASTNULL option   //~2908R~//~v6hFM~
//*rc   :eol length,-1:EOF, -4:err,4:last line with no EOL         //~2908I~//~v6hFR~
//**************************************************************** //~2908I~//~v6hFM~
int ufreads(int Popt,FILE *Pfh,FILESZT Pfilesz,char *Pbuff,int Pbuffsz,int *Ppreadlen)//~2908R~//~v6hFM~
{                                                                  //~2908I~//~v6hFM~
#define UFR_LF       0x0a                                          //~2908I~//~v6hFM~
#define UFR_CR       0x0d                                          //~2908I~//~v6hFM~
#define UFR_EOF      0x1a                                          //~2908I~//~v6hFM~
    int rc,readlen,reqsz,eofsw=0,eolsz=0;                       //~@@@3R~//~2908I~//~v6hFR~
	char *pc,buff2[4];                                             //~2908R~//~v6hFM~
//    long pos1,pos2;                                                //~2908R~//~v6uER~
    FILESZT pos1,pos2;                                             //~v6uEI~
//*********************************                                //~2908I~//~v6hFM~
	reqsz=Pbuffsz;                                                 //~2908R~//~v6hFM~
    if (Popt & UFRO_LASTNULL)                                      //~2908I~//~v6hFM~
        reqsz--;                                                   //~2908I~//~v6hFM~
    if (reqsz<=0)                                                  //~2908I~//~v6hFM~
    {                                                              //~2908I~//~v6hFM~
        uerrmsg("ufreads:buff size parameter err",0);              //~2908I~//~v6hFM~
    	return -4;                                                 //~2908I~//~v6hFM~
    }                                                              //~2908I~//~v6hFM~
//  pos1=ftell(Pfh);    //                                         //~2908I~//~v6xeR~
    pos1=uftell(Pfh);    //                                        //~v6xeI~
    if (!fgets(Pbuff,reqsz,Pfh))                                   //~2908I~//~v6hFM~
        return -1;                                                 //~2908I~//~v6hFM~
//  pos2=ftell(Pfh);    //                                         //~2908I~//~v6xeR~
    pos2=uftell(Pfh);    //                                        //~v6xeI~
	readlen=(int)(pos2-pos1);                                      //~2908I~//~v6hFM~
	UTRACED("ufreads read",Pbuff,readlen);                         //~2908I~//~v6hFM~
    pc=Pbuff+readlen;                                              //~2908I~//~v6hFM~
    if (readlen && *(pc-1)==UFR_LF)                                //~2908R~//~v6hFM~
    {                                                              //~2908I~//~v6hFM~
        eolsz++;                                                   //~2908I~//~v6hFM~
    }                                                              //~2908I~//~v6hFM~
    else    //missing EOL                                          //~2908I~//~v6hFM~
    {                                                              //~2908I~//~v6hFM~
        if (pos2==Pfilesz)    //EOF line missing CRLF              //~2908R~//~v6hFM~
        {                                                          //~2908I~//~v6hFM~
            eofsw=1;                                               //~2908I~//~v6hFM~
			if (Popt & UFRO_DROPEOF)		//drop DOS EOF(last 0x1a)//~2908I~//~v6hFM~
            {                                                      //~2908I~//~v6hFM~
            	if (readlen>0 && *(Pbuff+readlen-1)==UFR_EOF)  //DOS EOF char//~2908I~//~v6hFM~
                {                                                  //~2908I~//~v6hFM~
                	readlen--;                                     //~2908R~//~v6hFM~
                    if (!readlen)                                  //~2908I~//~v6hFM~
                		return -1;                                 //~2908I~//~v6hFM~
                }                                                  //~2908R~//~v6hFM~
            }                                                      //~2908I~//~v6hFM~
        }                                                          //~2908I~//~v6hFM~
    }                                                              //~2908I~//~v6hFM~
    if (eolsz)    //0x0a                                           //~2908I~//~v6hFM~
    {                                                              //~2908I~//~v6hFM~
        if (readlen>=2 && *(pc-2)==UFR_CR)                         //~2908I~//~v6hFM~
            eolsz++;                                               //~2908I~//~v6hFM~
    }                                                              //~2908I~//~v6hFM~
    if (!eofsw && !eolsz)   //no LF found                          //~2908I~//~v6hFM~
    {                                                              //~2908I~//~v6hFM~
UTRACED("NOLF  pc-1",pc-1,1);                                      //~2908I~//~v6hFM~
        if (*(pc-1)==UFR_CR)    //may split CR-LF                  //~2908I~//~v6hFM~
        {                                                          //~2908I~//~v6hFM~
            if (!fgets(buff2,2,Pfh)) //try read LF                 //~2908R~//~v6hFM~
                return -1;                                         //~2908I~//~v6hFM~
UTRACED("lastCR buff2",buff2,2);                                   //~2908I~//~v6hFM~
            if (*buff2==UFR_LF)                                    //~2908R~//~v6hFM~
                eolsz=2;                                           //~2908I~//~v6hFM~
            *pc++=*buff2;                                          //~2908I~//~v6hFM~
            readlen++;                                             //~2908I~//~v6hFM~
        }                                                          //~2908I~//~v6hFM~
    }                                                              //~2908I~//~v6hFM~
	if (Popt & UFRO_DROPLF)		//drop eol(0x0a)                   //~2908I~//~v6hFM~
    {                                                              //~2908I~//~v6hFM~
    	if (eolsz)                                                 //~2908I~//~v6hFM~
        	readlen--;                                             //~2908I~//~v6hFM~
		if (Popt & UFRO_DROPCR)		//drop eol(0x0a)               //~2908I~//~v6hFM~
    	{                                                          //~2908I~//~v6hFM~
    		if (eolsz>1)                                           //~2908I~//~v6hFM~
        		readlen--;                                         //~2908I~//~v6hFM~
    	}                                                          //~2908I~//~v6hFM~
    }                                                              //~2908I~//~v6hFM~
    if (Popt & UFRO_LASTNULL)                                      //~2908I~//~v6hFM~
    	*(Pbuff+readlen)=0;                                        //~2908R~//~v6hFM~
    *Ppreadlen=readlen;                                            //~2908I~//~v6hFM~
    rc=eolsz;                                                      //~2908I~//~v6hFM~
    if (eofsw)                                                     //~v6hFI~
    	rc|=UFRRC_EOFLINE;        //last line with no EOL          //~v6hFI~
    return rc;                                                     //~2908I~//~v6hFM~
}//ufreads                                                         //~2908I~//~v6hFM~
//**************************************************************   //~v6m0I~
//*read recfm=V fileheader record if microfocus dataset            //~v6m0R~
//*recordheader is 3xxx when max lrecl<=4095 else 30xxxxxx         //~v6m0I~
//**************************************************************   //~v6m0I~
int ufgetsVHeader(char *Pbuff,FILE *Pfh,int *Preadlen,int *Pprecordtype)//~v6m0R~
{                                                                  //~v6m0I~
	int readlen,len,rc,offs;                                       //~v6m0R~
//***************************                                      //~v6m0I~
//	readlen=fread(Pbuff,1,4,Pfh);                                  //~v6A0R~
  	readlen=(int)fread(Pbuff,1,4,Pfh);                             //~v6A0I~
    UTRACED("ufgetsVHeader",Pbuff,readlen);                        //~v6m0I~
    if (readlen!=4)    //err or eof                                //~v6m0I~
    	return UFGETS_ERRV;                                        //~v6m0R~
    Scurpos+=4;                                                    //~v6xcI~
	len=UBESTR2UL(Pbuff);                                          //~v6m0I~
    *Pprecordtype=len>>(24+4);	//top 4 bit                        //~v6m0I~
    if (len==MFH_HALF)                                             //~v6m0I~
    {                                                              //~v6m0I~
    	Svhdrsz=2;                                                 //~v6m0I~
	    len=(len>>16) & MFH_HALFMASK;                              //~v6m0R~
   	  if (Smode & UFGETS_RVHDR)	//output also vhdr                 //~v6m4I~
      {                                                            //~v6m4I~
        len-=2;     //already read more 2 byte                     //~v6m4I~
        offs=4;                                                    //~v6m4I~
      }                                                            //~v6m4I~
      else                                                         //~v6m4I~
      {                                                            //~v6m4I~
        *Pbuff=0;     //0000 after 307e                            //~v6m0R~
        *(Pbuff+1)=0;                                              //~v6m0R~
        len-=2;     //already read more 2 byte                     //~v6m0M~
        offs=2;                                                    //~v6m0M~
      }                                                            //~v6m4I~
    }                                                              //~v6m0I~
    else                                                           //~v6m0I~
    if (len==MFH_FULL)                                             //~v6m0I~
    {                                                              //~v6m0I~
    	Svhdrsz=4;                                                 //~v6m0I~
	    len &=MFH_FULLMASK;                                        //~v6m0R~
   	  if (Smode & UFGETS_RVHDR)	//output also vhdr                 //~v6m4I~
        offs=4;                                                    //~v6m4I~
      else                                                         //~v6m4I~
        offs=0;                                                    //~v6m0I~
    }                                                              //~v6m0I~
    else                                                           //~v6m0I~
    	return UFGETS_ERRV;                                        //~v6m0R~
    Svlennet=0;                                                    //~v6m0I~
    if (!len)                                                      //~v6m0I~
    	return UFGETS_ERRV;                                        //~v6m0R~
//  readlen=fread(Pbuff+offs,1,len,Pfh);                           //~v6A0R~
    readlen=(int)fread(Pbuff+offs,1,(size_t)len,Pfh);              //~v6A0I~
    UTRACED("ufgetsVHeader",Pbuff,readlen);                        //~v6m0I~
    *Preadlen=readlen+offs;                                        //~v6m0R~
    if (readlen!=len)  //err or eof                                //~v6m0I~
    	return UFGETS_ERRV;                                        //~v6m0R~
    Scurpos+=readlen;                                              //~v6xcI~
    UTRACEP("ufgetsVHeader rc=0 hdrsz=%d\n",Svhdrsz);              //~v6m0I~
    if (Svhdrsz==4)                                                //~v6m0I~
        rc=UFGETS_RCMFH4;                                          //~v6m0R~
    else                                                           //~v6m0I~
        rc=UFGETS_RCMFH2;                                          //~v6m0R~
    return rc;                                                     //~v6m0R~
}//ufgetsVHeader                                                   //~v6m0I~//~v6q7R~
//**************************************************************   //~v6m0I~
//*read recfm=V record                                             //~v6m0I~
//**************************************************************   //~v6m0I~
int ufgetsVRecord(char *Pbuff,FILE *Pfh,unsigned int *Preadlen,int *Pprecordtype)//~v6m0R~
{                                                                  //~v6m0I~
	int len,readlen;                                               //~v6m0R~
//*****************************                                    //~v6m0I~
//  readlen=fread(Pbuff,1,Svhdrsz,Pfh);                            //~v6A0R~
    readlen=(int)fread(Pbuff,1,(size_t)Svhdrsz,Pfh);               //~v6A0I~
    if (readlen!=Svhdrsz)    //err or eof                          //~v6m0I~
    {                                                              //~v6m0I~
        *Preadlen=0;                                               //~v6m0I~
    	if (ferror(Pfh))                                           //~v6m0I~
        	return UFGETS_ERR;                                     //~v6m0I~
        else                                                       //~v6m0I~
    		return UFGETS_EOF;                                     //~v6m0I~
    }                                                              //~v6m0I~
    Scurpos+=readlen;                                              //~v6xcI~
    if (Svhdrsz==2)                                                //~v6m0I~
	    len=UBESTR2US(Pbuff);                                      //~v6m0R~
    else                                                           //~v6m0I~
	    len=UBESTR2UL(Pbuff);                                      //~v6m0R~
	if (Svfmt==UFGETS_VFMT_MFH)                                    //~v6m0R~
    {                                                              //~v6m0I~
    	if (Svhdrsz==2)                                            //~v6m0I~
	    	len &=MFH_HALFMASK;                                    //~v6m0R~
    	else                                                       //~v6m0I~
	    	len &=MFH_FULLMASK;                                    //~v6m0R~
    	*Pprecordtype=*Pbuff>>4;	//top 4 bit                    //~v6m0I~
    }                                                              //~v6m0I~
    else                                                           //~v6m0I~
    {                                                              //~v6m0I~
    	if (Svfmt==UFGETS_VFMT_RDW)	//llllzzzz                     //~v6m0I~
        	len>>=16;               //llll                         //~v6m0I~
		len-=Svlennet;		//net data size                        //~v6m0R~
    	*Pprecordtype=0;                                           //~v6m0I~
    }                                                              //~v6m0I~
    if (len<0||len>IOBSZV)                                         //~v6m0R~
    	return UFGETS_ERRV;                                        //~v6m0R~
    if (len)                                                       //~v6m0I~
    {                                                              //~v6m4I~
   	  if (Smode & UFGETS_RVHDR)	//output also vhdr                 //~v6m4I~
//  	readlen=fread(Pbuff+Svhdrsz,1,len,Pfh);                    //~v6A0R~
    	readlen=(int)fread(Pbuff+Svhdrsz,1,(size_t)len,Pfh);       //~v6A0I~
      else                                                         //~v6m4I~
//  	readlen=fread(Pbuff,1,len,Pfh);                            //~v6A0R~
    	readlen=(int)fread(Pbuff,1,(size_t)len,Pfh);               //~v6A0I~
    }                                                              //~v6m4I~
    else                                                           //~v6m0I~
    	readlen=0;                                                 //~v6m0I~
  if (Smode & UFGETS_RVHDR)	//output also vhdr                     //~v6m4I~
//  *Preadlen=readlen+Svhdrsz;                                     //~v6A0R~
    *Preadlen=(unsigned int)(readlen+Svhdrsz);                     //~v6A0I~
  else                                                             //~v6m4I~
//  *Preadlen=readlen;                                             //~v6A0R~
    *Preadlen=(unsigned int)readlen;                               //~v6A0I~
    UTRACED("ufgetsV",Pbuff,readlen);                              //~v6m0I~
    if (readlen!=len)    //err or eof                              //~v6m0I~
    	return UFGETS_ERRV;                                        //~v6m0R~
    Scurpos+=readlen;                                              //~v6xcI~
    UTRACEP("ufgetsVRecord rc=0 readlen=%d\n",readlen);            //~v6m0I~
    return 0;                                                      //~v6m0I~
}//ufgetsVRecord                                                   //~v6m0I~
//**************************************************************   //~v6m0I~
//*read recfm=V record;split by xe maxline                         //~v6m0R~
//*eolid:recordtype for mf fmt,0 for cont line by RVTYPE option    //~v6q7R~
//*      else reslen(xprint use)                                   //~v6q7I~
//**************************************************************   //~v6m0I~
int ufgetsV(char *Pbuff,unsigned int Pbuffsz,FILE *Pfh,            //~v6m0I~
           unsigned int *Preadlen,int *Peolid)                     //~v6m0I~
{                                                                  //~v6m0I~
	int rc=0,copylen,recordtype=0;                                   //~v6m0R~//~v6q7R~
//*****************************                                    //~v6m0I~
	if (!Svhdrsz)                                                  //~v6m0I~
    {                                                              //~v6m0I~
        rc=ufgetsVHeader(Siob,Pfh,Preadlen,&recordtype);           //~v6m0R~
        if (rc==UFGETS_RCMFH2||rc==UFGETS_RCMFH4)                  //~v6m0R~
        {                                                          //~v6m0I~
//            copylen=min(*Preadlen,Pbuffsz);                        //~v6m0R~//~v6q8R~
//            memcpy(Pbuff,Siob,copylen);                            //~v6m0R~//~v6q8R~
//            *Preadlen=copylen;                                     //~v6m0R~//~v6q8R~
            Siobreslen=*Preadlen;                                  //~v6q8I~
        	Sreadpos=Siob;                                         //~v6q8I~
        }                                                          //~v6m0I~
        else                                                       //~v6m0I~
        {                                                          //~v6m0I~
            uerrmsg("First line is not a valid Microfocus variable length file header record.",//~v6m0R~
                    "最初の行が不正なMicrofocus可変長ファイルヘッダーレコード");//~v6m0I~
        }                                                          //~v6m0I~
//          if (Peolid)                                                //~v6m0R~//~v6q8R~
////          *Peolid=0;                                             //~v6m0R~//~v6q7R~//~v6q8R~
//            *Peolid=recordtype;                                    //~v6q7I~//~v6q8R~
//        return rc;                                                 //~v6m0I~//~v6q8R~
    }                                                              //~v6m0I~
    else                                                           //~v6q8I~
    if (!Siobreslen)        //no data on fread buff                //~v6m0I~
    {                                                              //~v6m0I~
		rc=ufgetsVRecord(Siob,Pfh,Preadlen,&recordtype);           //~v6m0R~
        if (rc)	//err/eof                                          //~v6m0R~
        {                                                          //~v6m0I~
        	if (rc==UFGETS_ERRV)                                   //~v6m0R~
	            uerrmsg("Header format err of variable length record",//~v6m0I~
	                    "可変長レコードのレコードヘッダー形式エラー");//~v6m0I~
    		if (Peolid)                                            //~v6m0I~
        		*Peolid=0;                                         //~v6m0I~
        	return rc;                                             //~v6m0I~
        }                                                          //~v6m0I~
        Siobreslen=*Preadlen;                                      //~v6m0R~
        Sreadpos=Siob;                                             //~v6m0R~
    }                                                              //~v6m0I~
    if (Siobreslen<=Pbuffsz)                                       //~v6m0R~
    {                                                              //~v6m0I~
//      copylen=Siobreslen;                                        //~v6A0R~
        copylen=(int)Siobreslen;                                   //~v6A0I~
//  	memcpy(Pbuff,Sreadpos,copylen);                            //~v6A0R~
    	memcpy(Pbuff,Sreadpos,(size_t)copylen);                    //~v6A0I~
        Siobreslen=0;                                              //~v6m0I~
    }                                                              //~v6m0I~
    else                                                           //~v6m0I~
    {                                                              //~v6m0I~
//      copylen=Pbuffsz;                                           //~v6A0R~
        copylen=(int)Pbuffsz;                                      //~v6A0I~
//  	memcpy(Pbuff,Sreadpos,copylen);                            //~v6A0R~
    	memcpy(Pbuff,Sreadpos,(size_t)copylen);                    //~v6A0I~
//      Siobreslen-=copylen;                                       //~v6A0R~
        Siobreslen-=(UINT)copylen;                                 //~v6A0I~
    	Sreadpos+=copylen;                                         //~v6m0I~
      if (rc==UFGETS_RCMFH2||rc==UFGETS_RCMFH4)                    //~v6q8I~
	    rc|=UFGETS_MORE;                                           //~v6q8I~
      else                                                         //~v6q8I~
	    rc=UFGETS_MORE;              //req re-call                 //~v6m0I~
    }                                                              //~v6m0I~
    if (Peolid)                                                    //~v6m0R~
    {                                                              //~v6q7I~
  	  if (Smode & UFGETS_RVTYPE)          //recfm!=V               //~v6q7I~
        *Peolid=recordtype;                                        //~v6q7M~
      else                                                         //~v6q7I~
//      *Peolid=Siobreslen;                                        //~v6A0R~
        *Peolid=(int)Siobreslen;                                   //~v6A0I~
    }                                                              //~v6q7I~
//  *Preadlen=copylen;                                             //~v6A0R~
    *Preadlen=(unsigned int)copylen;                               //~v6A0I~
    UTRACEP("ufgetsV rc=%d readlen=%d,reslen=%d\n",rc,copylen,Siobreslen);//~v6m0R~
    return rc;                                                     //~v6m0R~
}//ufgetsV                                                         //~v6m0I~
//**************************************************************** //~v6m0I~
// lrecl parm chk for recfm=V                                      //~v6m0I~
//**************************************************************** //~v6m0I~
int ufile5chkvfmt(int Popt,char *Pparm,int *Pplrecl)               //~v6m0R~
{                                                                  //~v6m0I~
	int fmttype=0,rc=0;                                            //~v6m0R~
    char *pc;                                                      //~v6m0R~
//***********************                                          //~v6m0I~
    pc=Pparm;                                                      //~v6m0I~
	if (!stricmp(pc,VFMT_MFH))                                     //~v6m0I~
    	fmttype|=UFGETS_VFMT_MFH;                                  //~v6m0I~
    else                                                           //~v6m0I~
	if (!stricmp(pc,VFMT_RDW))                                     //~v6m0I~
    	fmttype|=UFGETS_VFMT_RDW;                                  //~v6m0I~
    else                                                           //~v6m0I~
	if (!stricmp(pc,VFMT_FWDATA))    //4 byte net data length      //~v6m0I~
    	fmttype=UFGETS_VFMT_FWDATA;                                //~v6m0I~
    else                                                           //~v6m0I~
	if (!stricmp(pc,VFMT_HWDATA))    //2 byte                      //~v6m0I~
    	fmttype=UFGETS_VFMT_HWDATA;                                //~v6m0I~
    else                                                           //~v6m0I~
	if (!stricmp(pc,VFMT_FW))    //4 byte                          //~v6m0I~
    	fmttype|=UFGETS_VFMT_FW;                                   //~v6m0I~
    else                                                           //~v6m0I~
	if (!stricmp(pc,VFMT_HW))    //4 byte                          //~v6m0I~
    	fmttype|=UFGETS_VFMT_HW;                                   //~v6m0I~
    else                                                           //~v6m0I~
    	rc=4;                                                      //~v6m0I~
    if (!rc)              //don't clear default:RDW                //~v6m0I~
	    *Pplrecl=fmttype;                                          //~v6m0I~
	UTRACEP("ufile5chkvfmt parm=%s,rc=%d,fmttype=%d\n",Pparm,rc,fmttype);//~v6m0R~
    return rc;                                                     //~v6m0I~
}//ufile5chkvfmt                                                   //~v6m0R~
//**************************************************************** //~v6m0I~
char *ufile5getVfmtstr(int Popt,int Pfmttype)                     //~vaj0R~//~v6m0I~
{                                                                  //~vaj0I~//~v6m0I~
    char *pc;                                                      //~vaj0I~//~v6m0I~
//***********************                                          //~vaj0I~//~v6m0I~
	switch(Pfmttype)                                               //~vaj0I~//~v6m0I~
    {                                                              //~vaj0I~//~v6m0I~
    case UFGETS_VFMT_MFH:                                          //~vaj0R~//~v6m0I~
    case UFGETS_VFMT_MFH4:                                         //~vaj0I~//~v6m0I~
    	pc=VFMT_MFH;                                               //~vaj0I~//~v6m0I~
        break;                                                     //~vaj0I~//~v6m0I~
    case UFGETS_VFMT_RDW:                                          //~vaj0I~//~v6m0I~
    	pc=VFMT_RDW;                                               //~vaj0I~//~v6m0I~
        break;                                                     //~vaj0I~//~v6m0I~
    case UFGETS_VFMT_FW:                                           //~vaj0I~//~v6m0I~
    	pc=VFMT_FW;                                                //~vaj0I~//~v6m0I~
        break;                                                     //~vaj0I~//~v6m0I~
    case UFGETS_VFMT_HW:                                           //~vaj0I~//~v6m0I~
    	pc=VFMT_HW;                                                //~vaj0I~//~v6m0I~
        break;                                                     //~vaj0I~//~v6m0I~
    case UFGETS_VFMT_FWDATA:                                       //~vaj0I~//~v6m0I~
    	pc=VFMT_FWDATA;                                            //~vaj0I~//~v6m0I~
        break;                                                     //~vaj0I~//~v6m0I~
    case UFGETS_VFMT_HWDATA:                                       //~vaj0I~//~v6m0I~
    	pc=VFMT_HWDATA;                                            //~vaj0I~//~v6m0I~
        break;                                                     //~vaj0I~//~v6m0I~
    default:                                                       //~vaj0I~//~v6m0I~
    	pc=" ";                                                    //~vaj0I~//~v6m0I~
    }                                                              //~vaj0I~//~v6m0I~
	UTRACEP("ufile5getVfmtstr fmt=%d,pc=%s\n",Pfmttype,pc);       //~vaj0I~//~v6m0I~
    return pc;                                                     //~vaj0I~//~v6m0I~
}//ufile5getVfmtstr                                               //~vaj0I~//~v6m0I~
//*********************************************************        //~v6xeI~
int ufseek(FILE *Pfh,FILESZT Ppos,int Pbase)                       //~v6xeI~
{                                                                  //~v6xeI~
	int rc;                                                        //~v6xeI~
//**********************                                           //~v6xeI~
#ifdef W32                                                         //~v6xeI~
  #ifdef LFSSUPP                                                   //~v6xeI~
	rc=_fseeki64(Pfh,Ppos,Pbase);                                  //~v6xeR~
  #else                                                            //~v6xeI~
	rc=fseek(Pfh,Ppos,Pbase);                                      //~v6xeI~
  #endif                                                           //~v6xeI~
#else                                                              //~v6xeI~
  #ifdef LFSSUPP                                                   //~v6xeI~
	rc=fseeko(Pfh,Ppos,Pbase);                                     //~v6xeI~
  #else                                                            //~v6xeI~
	rc=fseek(Pfh,Ppos,Pbase);                                      //~v6xeI~
  #endif                                                           //~v6xeI~
#endif                                                             //~v6xeI~
	return rc;                                                     //~v6xeI~
}//ufseek                                                          //~v6xeI~//+v6R1R~
//*********************************************************        //~v6xeI~
FILESZT uftell(FILE *Pfh)                                          //~v6xeI~
{                                                                  //~v6xeI~
	FILESZT pos;                                                   //~v6xeI~
//**********************                                           //~v6xeI~
#ifdef W32                                                         //~v6xeI~
  #ifdef LFSSUPP                                                   //~v6xeI~
	pos=_ftelli64(Pfh);                                            //~v6xeR~
  #else                                                            //~v6xeI~
	pos=ftell(Pfh);                                                //~v6xeI~
  #endif                                                           //~v6xeI~
#else                                                              //~v6xeI~
  #ifdef LFSSUPP                                                   //~v6xeI~
	pos=ftello(Pfh);                                               //~v6xeI~
  #else                                                            //~v6xeI~
	pos=ftell(Pfh);                                                //~v6xeI~
  #endif                                                           //~v6xeI~
#endif                                                             //~v6xeI~
	return pos;                                                    //~v6xeI~
}                                                                  //~v6xeI~
//**************************************************************************//~5227I~//~v6y0I~
//*set same path by indication .../n=[m]                           //~5227I~//~v6y0I~
//* n skip n(0-9) path,default=0;                                  //~v6y0R~
//* m:set same m(1-9) path, without m up to last                   //~v6y0I~
//*rc 0:no "=" detected,1:set to out1,2:set to out2,               //~v6y0R~
//*   -1:file1 contains "=" but formt err                          //~v6y0I~
//*   -2:file2 contains "=" but formt err                          //~v6y0I~
//*   -3:both contains "="                                         //~v6y0I~
//*ex  /a/b/c/d/e/f/g  x/2=3/z  --> /x/c/d/e/z                                   //~5227I~//~v6y0I~
//*                    x/=/y/=  --> /x/b/y/d/e/f/g                 //~v6y0I~
//**************************************************************************//~5227I~//~v6y0I~
int fileeditname_copypath(int Popt,char *Pfnm1,char *Pfnm2,char *Pout1,char *Pout2)//~5227I~//~v6y0I~
{                                                                  //~5227I~//~v6y0I~
	int copyctr,skip,rc,pathctr;                                   //~5227R~//~v6y0I~
    char *pc1,*pc2,*psrc,*ptgt,*pco,*pcs,*pct,*pcoe;               //~5227R~//~v6y0I~
    char cht,chto,chtoo,chtn,chtnn,chs,chso;                             //~5227I~//~v6y0R~
    char wkout[_MAX_PATH];                                         //~5227I~//~v6y0I~
    char fpath[_MAX_PATH];                                         //~v6y1I~
//*****************************	                                   //~5227I~//~v6y0I~
	pc1=strchr(Pfnm1,ID_SAMEPATH);                                 //~5227I~//~v6y0I~
	pc2=strchr(Pfnm2,ID_SAMEPATH);                                 //~5227I~//~v6y0I~
    if (pc1 && pc2)                                                //~5227I~//~v6y0I~
    	return -3;                                                 //~5227I~//~v6y0R~
    if (!pc1 && !pc2)                                              //~5227I~//~v6y0I~
    	return 0;                                                  //~5227I~//~v6y0I~
    if (pc1)                                                       //~5227I~//~v6y0I~
    {                                                              //~5227I~//~v6y0I~
    	rc=1;                                                      //~5227I~//~v6y0I~
        ptgt=Pfnm1;                                                //~5227I~//~v6y0I~
        psrc=Pfnm2;                                                //~5227I~//~v6y0I~
    }                                                              //~5227I~//~v6y0I~
    else                                                           //~5227I~//~v6y0I~
    {                                                              //~5227I~//~v6y0I~
    	rc=2;                                                      //~5227I~//~v6y0I~
        ptgt=Pfnm2;                                                //~5227I~//~v6y0I~
        psrc=Pfnm1;                                                //~5227I~//~v6y0I~
    }                                                              //~5227I~//~v6y0I~
    if (Popt & FECO_FULLPATH)                                      //~v6y1I~
        psrc=ufullpath(fpath,psrc,sizeof(fpath));                  //~v6y1I~
    pcs=psrc;                                                      //~5227I~//~v6y0I~
    pct=ptgt;                                                      //~5227I~//~v6y0I~
    pco=wkout;                                                     //~5227I~//~v6y0I~
    *pco=0;                                                        //~5227I~//~v6y0I~
    pcoe=wkout+sizeof(wkout)-1;                                    //~5227I~//~v6y0I~
    for (cht=0,chto=0;;)                                           //~5227I~//~v6y0I~
    {                                                              //~5227I~//~v6y0I~
        chtoo=chto;                                                //~5227I~//~v6y0I~
        chto=cht;                                                  //~5227I~//~v6y0I~
		cht=*pct++;                                                //~5227I~//~v6y0I~
        if (!((cht=='/'||cht=='\\')&&(*(pco-1)=='/'||*(pco-1)=='\\')))//~5227R~//~v6y0I~
	        *pco++=cht;                                            //~5227I~//~v6y0I~
        if (!cht)                                                  //~5227I~//~v6y0I~
        	break;                                                 //~5227I~//~v6y0I~
        if (pco>=pcoe)                                             //~5227I~//~v6y0I~
        {                                                          //~5227I~//~v6y0I~
            rc=-rc;                                                 //~5227I~//~v6y0R~
            break;                                                 //~5227I~//~v6y0I~
        }                                                          //~5227I~//~v6y0I~
        if (cht!=ID_SAMEPATH)                                      //~5227I~//~v6y0I~
        {                                                          //~5227I~//~v6y0I~
            continue;	                                           //~5227I~//~v6y0I~
        }                                                          //~5227I~//~v6y0I~
        pco--;                                                     //~5227I~//~v6y0I~
        if (!chto)	 // "=..."                                     //~5227I~//~v6y0I~
            skip=0;                                                //~5227I~//~v6y0I~
        else                                                       //~5227I~//~v6y0I~
        if (chto=='/'||chto=='\\')  // "/=..."                     //~5227R~//~v6y0I~
        {                                                          //~5227I~//~v6y0I~
            skip=0; //default skip                                 //~5227I~//~v6y0R~
        }                                                          //~5227I~//~v6y0I~
        else                                                       //~v6y0I~
        if (chto>='0' && chto<='9'                                 //~5227I~//~v6y0I~
        &&  (chtoo==0||chtoo=='/'||chtoo=='\\')  // "/9=..."       //~5227R~//~v6y0I~
        )	                                                       //~5227I~//~v6y0I~
        {                                                          //~5227I~//~v6y0I~
        	pco--;                                                 //~5227I~//~v6y0I~
            skip=chto-'0';                                         //~5227R~//~v6y0I~
        }                                                          //~5227I~//~v6y0I~
        else                                                       //~5227I~//~v6y0I~
        {                                                          //~5227I~//~v6y0I~
            rc=-rc;                                                 //~5227I~//~v6y0R~
            break;                                                 //~5227I~//~v6y0I~
        }                                                          //~5227I~//~v6y0I~
//      printf("skipctr=%d\n",skip);                               //~5227I~//~v6y0I~
        chtn=*pct;	//next of =                                    //~5227R~//~v6y0I~
        if (chtn=='/'||chtn=='\\')                                 //~5227R~//~v6y0I~
        	copyctr=1;                                             //~5227I~//~v6y0I~
        else                                                       //~5227I~//~v6y0I~
        if (chtn>='1' && chtn<'9')                                 //~5227R~//~v6y0I~
        {                                                          //~5227I~//~v6y0I~
            chtnn=*(pct+1);                                        //~v6y0I~
            if (chtnn && chtnn!='/' && chtnn!='\\')                //~v6y0I~
            {                                                      //~v6y0I~
	            rc=-rc;        //fmt err                           //~v6y0I~
    	        break;                                             //~v6y0I~
            }                                                      //~v6y0I~
        	copyctr=chtn-'0';                                      //~5227I~//~v6y0I~
            pct++;                                                 //~5227I~//~v6y0I~
        }                                                          //~5227I~//~v6y0I~
        else                                                       //~5227I~//~v6y0I~
        if (!chtn)                                                 //~5227I~//~v6y0I~
        	copyctr=0;	//unlimit                                  //~5227I~//~v6y0I~
        else                                                       //~5227I~//~v6y0I~
        {                                                          //~5227I~//~v6y0I~
            rc=-rc;        //fmt err                                //~5227I~//~v6y0R~
            break;                                                 //~5227I~//~v6y0I~
        }                                                          //~5227I~//~v6y0I~
//      printf("copyctr=%d\n",copyctr);                            //~5227I~//~v6y0I~
	//*skip path n times                                           //~5227I~//~v6y0I~
        for (chs=0,pathctr=0;pathctr<skip;)	//skip path n times    //~5227R~//~v6y0I~
        {                                                          //~5227I~//~v6y0I~
        	chso=chs;                                              //~5227I~//~v6y0I~
        	chs=*pcs++;                                            //~5227I~//~v6y0I~
            if (!chs)                                              //~5227I~//~v6y0I~
            	break;                                             //~5227I~//~v6y0I~
        	if (chs=='/'||chs=='\\')                               //~5227I~//~v6y0I~
            {                                                      //~5227I~//~v6y0I~
            	if (!chso)	//from root,skip 1 level               //~5227I~//~v6y0I~
                	continue;                                      //~5227I~//~v6y0I~
            	pathctr++;                                         //~5227I~//~v6y0I~
            }                                                      //~5227I~//~v6y0I~
        }                                                          //~5227I~//~v6y0I~
        if (pathctr!=skip)                                         //~5227I~//~v6y0I~
        {	                                                       //~5227I~//~v6y0I~
        	rc=-rc;                                                 //~5227I~//~v6y0R~
            break;                                                 //~5227I~//~v6y0I~
        }                                                          //~5227I~//~v6y0I~
	//*copy m path                                                 //~5227R~//~v6y0I~
        for (chs=0,pathctr=0;!copyctr || pathctr<copyctr;)	//skip path n times//~5227R~//~v6y0I~
        {                                                          //~5227I~//~v6y0I~
        	chso=chs;                                              //~5227I~//~v6y0I~
        	chs=*pcs++;                                            //~5227I~//~v6y0I~
            if (!chs)                                              //~v6y0M~
            {                                                      //~v6y0M~
            	pathctr++;                                         //~v6y0M~
            	break;                                             //~5227I~//~v6y0M~
            }                                                      //~v6y0M~
            if (!((chs=='/'||chs=='\\')&&(*(pco-1)=='/'||*(pco-1)=='\\')))//~5227R~//~v6y0I~
	            *pco++=chs;                                        //~5227R~//~v6y0I~
            if (pco>=pcoe)                                         //~5227I~//~v6y0I~
            {                                                      //~5227I~//~v6y0I~
            	rc=-rc;                                             //~5227I~//~v6y0R~
                break;                                             //~5227I~//~v6y0I~
			}                                                      //~5227I~//~v6y0I~
        	if (chs=='/'||chs=='\\')                               //~5227I~//~v6y0R~
            {                                                      //~5227I~//~v6y0I~
            	if (!chso)	//from root,skip 1 level               //~5227I~//~v6y0I~
                	continue;                                      //~5227I~//~v6y0I~
            	pathctr++;                                         //~5227I~//~v6y0I~
            }                                                      //~5227I~//~v6y0I~
        }                                                          //~5227I~//~v6y0I~
        if (copyctr && pathctr!=copyctr)                           //~5227I~//~v6y0I~
        {                                                          //~5227I~//~v6y0I~
        	rc=-rc;                                                 //~5227I~//~v6y0R~
            break;                                                 //~5227I~//~v6y0I~
        }                                                          //~5227I~//~v6y0I~
    }                                                              //~5227I~//~v6y0I~
//  printf("out=%s\n",wkout);                                      //~5227I~//~v6y0I~
    if (rc==1)                                                     //~5227I~//~v6y0I~
    	strcpy(Pout1,wkout);                                       //~5227I~//~v6y0I~
    else                                                           //~5227I~//~v6y0I~
    if (rc==2)                                                     //~5227I~//~v6y0I~
    	strcpy(Pout2,wkout);                                       //~5227I~//~v6y0I~
    return rc;                                                     //~5227I~//~v6y0I~
}//fileeditname_copypath                                                 //~5227R~//~v6y0I~
//**************************************************************************//~v6y0I~
void fileeditname_copypath_err(int Popt,char *Pfnm1,char *Pfnm2)   //~v6y0R~
{                                                                  //~v6y0I~
	if (Popt & FCEO_UERREXIT)                                      //~v6y0I~
        uerrexit("copy path specification(\"=\") format error:\"%s\" and \"%s\".",//~v6y0I~
                "パス名のコピー指定(\"=\")の形式の誤り:\"%s\" vs \"%s\"",//~v6y0I~
                Pfnm1,Pfnm2);                                      //~v6y0I~
	uerrmsg("copy path specification(\"=\") format error:\"%s\" and \"%s\".",//~v6y0I~
			"パス名のコピー指定(\"=\")の形式の誤り:\"%s\" vs \"%s\"",//~v6y0I~
            Pfnm1,Pfnm2);                                          //~v6y0I~
}                                                                  //~v6y0I~
//**************************************************************************//~v6J7I~
int filetouch(int Popt,char *Pfnm,char *Precord)                   //~v6J7I~
{                                                                  //~v6J7I~
	int rc;                                                        //~v6J7I~
    FILE* fh;                                                      //~v6J7I~
//**********************                                           //~v6J7I~
	fh=fopen(Pfnm,"w");                                            //~v6J7R~
    rc=errno;                                                      //~v6J7I~
    UTRACEP("%s:errno=%d,fnm=%s,record=%s\n",UTT,rc,Pfnm,Precord?Precord:"null");//~v6J7R~
    if (fh)                                                        //~v6J7I~
    {                                                              //~v6J7I~
    	if (Precord)                                               //~v6J7I~
	    	fputs(Precord,fh);                                     //~v6J7I~
		fclose(fh);                                                //~v6J7I~
    	rc=0;                                                      //~v6J7I~
    }                                                              //~v6J7I~
    return rc;                                                     //~v6J7I~
}//filetouch                                                       //~v6J7I~
