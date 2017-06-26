//*CID://+v6H2R~:                             update#=   56;       //~v6H2R~
//*************************************************************
//*uparse.c                                                        //~v098R~
//*  uparse/uparse2/uparsev/uparsein/uparseindir                   //~v5h5R~
//*************************************************************
//v6H2:170103 (BUG)uparsefname cut last 1 byte for len=259(_MAX_MATH-1)//~v6H2I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v690:100701 m62(LP64:: int:32, long,void*:64) support (__LP64_)  //~v690I~
//v5j4:060913 uparse no single quotation(') option(process double quote(") only)//~v5izI~
//v5iz:060910 (BUG)contdelm option is not functional(change #define name to conform currentry not used)//~v5izI~
//v5h5:060224 (BUG)grep:when space containing dir for *\ or ^*\,it should not enclose wildcard by unix shell standard.//~v5h5I~
//v5f2:041113 (BUG)uparse;space/tab after quotation is ignored when no enclosing quotation.//~v5f2I~
//v5f1:041113 uparse;option to treate quotation as delm.parse x"y"z to x,y,z//~v5f1I~
//v5ez:041111 parsecmd terminater option to search comment start position//~v5ezI~
//v5cx:040521 uparsegetopt support for other than unix             //~v5cxI~
//v5ca:040402 (BUG)upase abend by tc fmt -d'"'                     //~v5caI~
//v595:031012 uparse:support flag quatation like as -d" "          //~v595I~
//v574:021123 (BUG)parse ignore quate or dblquate only string(word count is -1)//~v574I~
//v40e:001109 (BUG) bit test missing                               //~v40eI~
//v374:000929 LINUX support(func to split flag and other parm;uparsegetopt)//~v374I~
//v328 000826:LINUX:gcc detected warning:uninitialized var         //~v328I~
//v289:991023 change dlm from space to next delm when space+delm case for not UPARSESETCONDELM//~v289I~
//v235:990501 option to support tab for parse, it is same meaning as space.//~v235I~
//v130:971217 uparsecmdin:enclose by quatation by cmd fmt          //~v130I~
//v128:971210 for func uparsecmd;\" mean " as data                 //~v128I~
//v127:971207 new func uparsecmd(parse like as shell)              //~v127I~
//v117:971109 new function uparsefname(drop quatation);use for also v116//~v117I~
//v098:970723 split uparse fro ustring to uparse.c                 //~v098I~
//v097:970720 umemspnc,umemrspnc                                   //~v097I~
//v094:970706 umemrspn(umemspn is same meaning as ustrnspn)        //~v094I~
//            ustrnrspn must trate parm1 as string                 //~v094I~
//v093:970706 (BUG)set null out of range may corrupt naboring area(ustrnchar2,ustrnrchr2)//~v093R~
//            and conbine to umemchar2,umemrchr2)                  //~v093I~
//v092:970705 umemmem/umemmemi/umemstr/umemstri/umemrmem/umemrmemi/umemrstr/umemrstri//~v092I~
//v091:970705 add ustrnlen(max n)                                  //~v091I~
//v088:970621 add umemrchr                                         //~v088I~
//v081:970503 (BUG)uparse rc=1 for case quate enclosed             //~v081I~
//v080:970503 add uparsein to enclabe string by quate for dlcmd to dcmd//~v080I~
//            ustring.c                                            //~v080I~
//v069:970330:uparsev(output by argv format)                       //~v069I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -warning if mixed &&,||                              //~v053I~
//v046:961123:uparse2 no malloc output area option(malloc at out of function)//~v046I~
//           :uparse:malloc only when long string                  //~v046I~
//           :uparse:delm lost when pre/post space exist.          //~6B23R~
//                   add option to set delm except for ","         //~6B23R~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//v017:960714:add ustrchr2(strchr protecting detect dbcs 2nd byte) //~v017I~
//            add ustrnchr2=(ustrchr2 with length)                 //~v017I~
//            add ustrrchr2(search last char protecting detect dbcs 2nd byte)//~v017I~
//            add ustrnrchr2=(ustrrchr2 with length)               //~v017I~
//960324:(BUG)delm after quate("abc",vvv) cannot drop quate.    //~6324I~
//960324:uparse2:with delm/qaute return function                //~6324R~
//950930:malloc/calloc rc chk for dos                           //~5930I~
//*950503 bug loop when all space(quate init value set)         //~5430R~
//*950430 uparse delm tbl support                               //~5430R~
//*950307 uparse "" null string support                         //~5430I~
//************************************************************* //~5307I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
#ifdef DOS
#else
    #ifdef W32                                                     //~v022I~
    #else                                                          //~v022I~
//  #define INCL_BASE                                              //~v022R~
//  #include <os2.h>                                               //~v022R~
    #endif                                                         //~v022I~
#endif
//*******************************************************
#include <ulib.h>
#include <ustring.h>
#include <ualloc.h>
#include <udbcschk.h>                                              //~v017I~
#include <uparse.h>                                                //~v098I~
#include <uerr.h>                                                  //~v374I~
//*******************************************************
#define DQUATE  '"'         //quatation                            //~v127R~
#define DELMSP  ' '         //space delimeter                      //~v127I~
#define BSLASH  '\\'        //treate " as data                     //~v128I~
//*******************************************************          //~v127I~
static PUPODELMTBL Spupodelmtbl;  //parm from uparse2 to uparse //~6324R~
//static UINT   Sparseoutlen;   //parm from uparse to uparse2      //~v046R~
//*******************************************************          //~v080I~
//!uparsein                                                        //~v098R~
//* enclose by quatation(quatation is reset by double quatation)   //~v080I~
//* parm1 :input string                                            //~v080I~
//* parm2 :output parse out (argv format,arg and pout,caller must free//~v080I~
//* parm3 :out area len                                            //~v080I~
//* parm4 :optional delimiter tbl," " is always delm as default    //~v080R~
//* parm5 :quatation to enclabe                                    //~v080I~
//* return:rc 0:no need to enclabe,copyed                          //~v080I~
//*           1:enclabed no doubled quatation                      //~v080I~
//*           2:enclabed doubled quatation                         //~v080I~
//*           4:out area shortage                                  //~v080I~
//******************************************************           //~v080I~
int uparsein(char *Pin,char *Pout,int Poutlen,char *Pdelmtbl,char Pquate)//~v080I~
{                                                                  //~v080I~
    char *pci,*pco,*pc;                                            //~v080R~
    int  leni,reslen,len;                                          //~v080I~
//******************                                               //~v080I~
    leni=(int)strlen(Pin);                                         //~v080I~
    if (Poutlen<=leni)                                             //~v080I~
        return 4;                                                  //~v080I~
    if (!(pc=strchr(Pin,' ')))          //no space                 //~v080R~
        if (Pdelmtbl)                                              //~v080I~
            pc=strpbrk(Pin,Pdelmtbl);       //search delm          //~v080R~
    if (!pc)                            //no delm                  //~v080I~
    {                                                              //~v080I~
        memcpy(Pout,Pin,(UINT)leni);                               //~v080I~
        *(Pout+leni)=0;                                            //~v080I~
        return 0;                       //copyed                   //~v080I~
    }                                                              //~v080I~
    if (Poutlen<=(leni+2))                  //add encloser         //~v080I~
        return 4;                                                  //~v080I~
    pco=Pout;                                                      //~v080I~
    pci=Pin;                                                       //~v080I~
    *pco++=Pquate;                                                 //~v080I~
    if (!(pc=strchr(pci,Pquate)))                                  //~v080I~
    {                                                              //~v080I~
        memcpy(pco,pci,(UINT)leni);                                //~v080I~
        *(pco+=leni)=Pquate;                                       //~v080I~
        *++pco=0;                                                  //~v080I~
        return 1;                   //simple enclosed              //~v080I~
    }                                                              //~v080I~
//repl quate to double quate                                       //~v080I~
    reslen=Poutlen-1;                                              //~v080I~
    while (pc)                                                     //~v080I~
    {                                                              //~v080I~
//      len=pc-pci+1;           //with matched quate               //~v080I~//~v6BxR~
        len=PTRDIFF(pc,pci)+1;           //with matched quate      //~v6BxI~
        if ((reslen-=len)<1)    //for quat added                   //~v080I~
            return 4;                                              //~v080I~
        memcpy(pco,pci,(UINT)len);                                 //~v080I~
        *(pco+=len)=Pquate;                                        //~v080I~
        pco++;                                                     //~v080I~
        reslen--;                                                  //~v080I~
        pci=pc+1;                                                  //~v080I~
        pc=strchr(pci,Pquate);                                     //~v080I~
    }                                                              //~v080I~
    len=(int)strlen(pci);                                          //~v080I~
    if (reslen<=(len+1))    //with last null                       //~v080I~
        return 4;                                                  //~v080I~
    memcpy(pco,pci,(UINT)len);                                     //~v080I~
    *(pco+=len)=Pquate;                                            //~v080I~
    *++pco=0;                                                      //~v080I~
    return 2;           //enclosed and expanded                    //~v080I~
}//uparsein                                                        //~v080I~
//*******************************************************          //~v5h5I~
//!uparseindir                                                     //~v5h5I~
//* enclose space containing dir by quatation                      //~v5h5I~
//* rc:0:no space,1:space detected,4:out area shortage             //~v5h5I~
//******************************************************           //~v5h5I~
int uparseindir(int Popt,char *Pin,char *Pout,int Poutlen)         //~v5h5R~
{                                                                  //~v5h5I~
    char *pci,*pco,*pcie,*pcoe;                                    //~v5h5R~
    int  rc=0;                                                     //~v5h5I~
//******************                                               //~v5h5I~
    pcie=Pin+strlen(Pin);                                          //~v5h5I~
    pcoe=Pout+Poutlen;                                             //~v5h5I~
    for (pci=Pin,pco=Pout;pci<pcie && pco<pcoe;)                   //~v5h5I~
    	if (*pci==' ')                                             //~v5h5I~
        {                                                          //~v5h5I~
        	*pco++='"';                                            //~v5h5I~
            while(*pci==' ' && pco<pcoe)                           //~v5h5I~
            	*pco++=*pci++;                                     //~v5h5I~
            if (pco>=pcoe)                                         //~v5h5I~
            	return 4;                                          //~v5h5I~
        	*pco++='"';                                            //~v5h5I~
            rc=1;                                                  //~v5h5I~
        }                                                          //~v5h5I~
        else                                                       //~v5h5I~
        	*pco++=*pci++;                                         //~v5h5R~
    if (pco>=pcoe)                                                 //~v5h5I~
        return 4;                                                  //~v5h5I~
    *pco=0;                                                        //~v5h5I~
    return rc;           //enclosed and expanded                   //~v5h5I~
}//uparseindir                                                     //~v5h5I~
//*******************************************************          //~v069I~
//!uparsev                                                         //~v098R~
//* uparse by argv format output                                   //~v069I~
//* parm1 :input string                                            //~v069I~
//* parm2 :output parse out (argv format,arg and pout,caller must free//~v069R~
//* parm3 :word count output                                       //~v069R~
//* parm4 :option                                                  //~v069R~
//        :0x01 ignore cr/lf(1:ignore,0:no ignore)                 //~v069I~
//* parm5 :optional delimiter tbl                                  //~v069R~
//* return:rc 0:ok, 1:quatation not enclosed, UALLOC_FAILED        //~v069I~
//******************************************************           //~v069I~
int uparsev(UCHAR *Pin,UCHAR ***Ppargv,int *Ppwordno,int Popt,UCHAR *Pdelmtbl)//~v069R~
{                                                                  //~v069I~
    UCHAR *pcout,**argv,*pc;                                       //~v069I~
    UINT  len;                                                     //~v069I~
    int   rc,ii;                                                   //~v069R~
//******************                                               //~v069I~
    *Ppargv=0;              //for err case                         //~v069I~
//  len=strlen(Pin);        //inp len                              //~v069I~//~v6BxR~
    len=(UINT)strlen(Pin);        //inp len                        //~v6BxI~
    pcout=UALLOCM((UINT)(len+1));       //out area                 //~v069I~
    UALLOCCHK(pcout,UALLOC_FAILED);                                //~v069I~
    if (rc=uparse(Pin,pcout,Ppwordno,Popt,Pdelmtbl),rc)            //~v069R~
    {                                                              //~v069I~
        ufree(pcout);                                              //~v069I~
        return rc;                                                 //~v069I~
    }                                                              //~v069I~
//  *Ppargv=argv=UALLOCM((UINT)(len+1+(*Ppwordno+1)*4));    //argv area and poarea//~v069I~//~v690R~
//  *Ppargv=argv=UALLOCM((UINT)(len+1+(*Ppwordno+1)*PTRSZ));    //argv area and poarea//~v690I~//~v6BkR~
    *Ppargv=argv=UALLOCM((size_t)((int)len+1+(*Ppwordno+1)*(int)PTRSZ));    //argv area and poarea//~v6BkR~
    if (!argv)                                                     //~v069I~
    {                                                              //~v069I~
        ufree(pcout);                                              //~v069I~
        return UALLOC_FAILED;                                      //~v069I~
    }                                                              //~v069I~
    pc=(char*)(void*)argv;                                         //~v069R~
//  memcpy(pc+(*Ppwordno+1)*4,pcout,(UINT)(len+1));                //~v069I~//~v690R~
    memcpy(pc+(*Ppwordno+1)*PTRSZ,pcout,(UINT)(len+1));            //~v690I~
    ufree(pcout);                                                  //~v069I~
//  pcout=pc+(*Ppwordno+1)*4;                                      //~v069I~//~v690R~
    pcout=pc+(*Ppwordno+1)*PTRSZ;                                  //~v690I~
    for (ii=0;ii<*Ppwordno;ii++,argv++)                            //~v069I~
    {                                                              //~v069I~
        *argv=pcout;                                               //~v069I~
        pcout+=strlen(pcout)+1;                                    //~v069I~
    }                                                              //~v069I~
    *argv=0;    //last                                             //~v069I~
    return 0;                                                      //~v069I~
}//uparsev                                                         //~v069I~
                                                                   //~v069I~
//*******************************************************       //~6324I~
//!uparse2                                                         //~v098R~
//* string parse by space                                       //~6324I~
//*    drop quatation if enclosing(\'  or \")                   //~6324I~
//*    (enclosing quate must follow space or comma)             //~6324I~
//*    double quatation is trated as single data if same as enclosing//~6324I~
//* parm1 :input string                                         //~6324I~
//* parm2 :output delm tbl ptr(need free)                          //~v046I~
//* parm3 :output parse out area(do not free)                      //~v046I~
//* parm4 :word count output                                       //~v046I~
//* parm5 :option                                                  //~v046I~
//        :0x01 ignore cr/lf(1:ignore,0:no ignore)                 //~v046I~
//        :0x02 output delm tbl area is also input(caller malloced)//~v046I~
//* parm6 :optional delimiter tbl                                  //~v046I~
//* return:rc 0:ok, 1:quatation not enclosed, UALLOC_FAILED        //~v046I~
//******************************************************           //~v046I~
int uparse2(UCHAR *Pin,PUPODELMTBL *Ppupodelmtbl,UCHAR **Ppupotbl, //~v046R~
            int *Ppwordno,int Popt,UCHAR *Pdelmtbl)                //~v046R~
{                                                               //~6324I~
    UCHAR *pcout;                                               //~6324R~
    UINT  len;                                                  //~6324I~
    int   rc;                                                      //~v022R~
    int   useopt;                                                  //~v046R~
//******************                                            //~6324I~
//  len=strlen(Pin);        //inp len                           //~6324R~//~v6BxR~
    len=(UINT)strlen(Pin);        //inp len                        //~v6BxI~
    if (useopt=(Popt & UPARSE2USEAREAPARM),useopt)                 //~6B23R~
    {                                                              //~v046M~
        Popt &=~UPARSE2USEAREAPARM; //drop it for parm to uparse   //~6B23R~
        Spupodelmtbl=*Ppupodelmtbl; //use input parm               //~v046M~
        pcout=*Ppupotbl;                //use input parm           //~v046R~
    }                                                              //~v046M~
    else                                                           //~v046M~
    {                                                              //~v046M~
    pcout=UALLOCM((UINT)((UPODELMTBLSZ+1)*len+1));      //out area and delm/qute tbl//~6324R~
    UALLOCCHK(pcout,UALLOC_FAILED);                             //~6324R~
//  Spupodelmtbl=(PUPODELMTBL)(ULONG)pcout;        //implicit parm to uparse//~v5caR~//~v6hhR~
    Spupodelmtbl=(PUPODELMTBL)(ULPTR)pcout;        //implicit parm to uparse//~v6hhI~
      pcout+=UPODELMTBLSZ*len;          //out area                 //~v046I~
      *Ppupotbl=pcout;              //use input parm               //~v046I~
      *Ppupodelmtbl=Spupodelmtbl;   //return output,caller must free//~v046I~
    }                                                              //~v046R~
    memset(Spupodelmtbl,0,(UINT)(UPODELMTBLSZ*len));   //for last delm//~6324R~
//  pcout+=UPODELMTBLSZ*len;            //out area                 //~v046R~
    rc=uparse(Pin,pcout,Ppwordno,Popt,Pdelmtbl);                //~6324R~
//  if (rc<=1)                                                     //~v046R~
//      memcpy(Spupodelmtbl+*Ppwordno,pcout,Sparseoutlen);         //~v046R~
//  *Ppupodelmtbl=Spupodelmtbl; //return output,caller must free   //~v046R~
    Spupodelmtbl=0;     //parm return output,caller must free   //~6324R~
    return rc;                                                  //~6324I~
}//uparse2                                                      //~6324I~
                                                                //~6324I~
//*******************************************************
//!uparse                                                          //~v098R~
//* string parse by space
//*    drop quatation if enclosing(\'  or \") 
//*    (enclosing quate must follow space or comma)             //~5307I~
//*    double quatation is trated as single data if same as enclosing
//* parm1 :input string                                         //~5307R~
//* parm2 :output string                                        //~5307I~
//* parm3 :word count output                                    //~5307I~
//* parm4 :option                                               //~6324R~
//        :0x01 ignore cr/lf(1:ignore,0:no ignore)              //~6324I~
//* parm5 :optional delimiter tbl                               //~5430I~
//* return:rc 0:ok, 1:quatation not enclosed, UALLOC_FAILED     //~5930I~
//******************************************************
int uparse(UCHAR *Pin,UCHAR *Pout,int *Ppwordno,int Popt,UCHAR *Pdelmtbl)//~5430R~
{
    UCHAR *pc,*pcout,*quatestarto=0,*quatestarti=0,*umallocsv;     //~v328R~
    UCHAR quate=0;
    UINT  len,offs,quatestartl=0;                                  //~v328R~
    int spacedelm,quatestartc=0,rc=0;                              //~v328R~
//  int contdelmopt;                                               //~v5izR~
    int sepdelmsw;                                                 //~v5izR~
    int contdelmopt2;                                              //~v289I~
    int tabspaceopt;                                               //~v235I~
    int swallowflag,swflagstring;                                  //~v595R~
    int swquotedelm;                                               //~v5f1I~
    int swretry=0;                                                 //~v5f2I~
    UCHAR *skipchr;                                                //~v235I~
#define MAXWKSZ     128                                            //~v046R~
    UCHAR wkbuff[MAXWKSZ+1];                                       //~v046I~
    UCHAR quote1,quote2;                                           //~v5j4R~
//******************
    pcout=Pout;                                                 //~5307I~
    *Ppwordno=0;                                                //~5307I~
//  len=strlen(Pin);                                            //~5307R~//~v6BxR~
    len=(UINT)strlen(Pin);                                         //~v6BxI~
    if (Popt & UPARSEIGNRCRLF)                                     //~6B23R~
    {                                                           //~5307I~
        if (len && *(Pin+len-1)=='\n')                          //~5307R~
            len--;                                              //~5307I~
        if (len && *(Pin+len-1)=='\r')                          //~5307R~
            len--;                                              //~5307R~
    }                                                           //~5307I~
//  contdelmopt=(Popt & UPARSESETCONDELM);                         //~v5izR~
    sepdelmsw=(Popt & UPARSESEPCONTDELM);   //each entry for continued delm//~v5izR~
    contdelmopt2=(Popt & UPARSESETCONDLM2);                        //~v289I~
    swallowflag=(Popt & UPARSEALLOWFLAG);                          //~v595I~
    swquotedelm=(Popt & UPARSEQUOTEDELM);                          //~v5f1I~
    if (Popt & UPARSENOSQUOTE)	//single quote is a data           //~v5j4R~
    {                                                              //~v5j4R~
    	quote1='\"';                                               //~v5j4R~
    	quote2='\"';                                               //~v5j4R~
    }                                                              //~v5j4R~
    else                                                           //~v5j4R~
    {                                                              //~v5j4R~
    	quote1='\'';                                               //~v5j4R~
    	quote2='\"';                                               //~v5j4R~
    }                                                              //~v5j4R~
    if (!(tabspaceopt=(Popt & UPARSETABISSPACE)))  //tab is same effect as space//~v235I~
        skipchr=" ";    //skip space only                          //~v235I~
    else                                                           //~v235I~
        skipchr=" \t";  //skip space and tab                       //~v235I~
    if (!len)                                                   //~5307I~
        return 0;                                               //~5307I~
    if (len>MAXWKSZ)    //long string                              //~v046I~
    {                                                              //~v046I~
    pc=umallocsv=UALLOCM((UINT)(len+1));                        //~5930R~
    UALLOCCHK(pc,UALLOC_FAILED);                                //~5930I~
    }                                                              //~v046I~
    else    //can be use wkbuff                                    //~v046I~
        pc=umallocsv=wkbuff;                                       //~v046I~
    memcpy(pc,Pin,len);                                         //~5307I~
    *(pc+len)=0;                                                //~5307I~
    spacedelm=0;    //accept first comma                        //~5307R~
    for (;;)        //retry loop                                //~5307I~
    {                                                           //~5307I~
//      while(offs=strspn(pc," "),  //offset of non space          //~v235R~
//      while(offs=strspn(pc,skipchr),  //offset of non space      //~v5f2R~
//              len-=offs,                                         //~v5f2R~
//              pc+=offs,                                          //~v5f2R~
//              len)                                               //~v5f2R~
        for (;;)                                                   //~v5f2I~
        {                                                       //~5307R~
    		if (!swretry)                                          //~v5f2I~
            {                                                      //~v5f2I~
//          	offs=strspn(pc,skipchr);  //offset of non space    //~v5f2I~//~v6BxR~
            	offs=(UINT)strspn(pc,skipchr);  //offset of non space//~v6BxI~
                len-=offs;                                         //~v5f2I~
                pc+=offs;                                          //~v5f2I~
            }                                                      //~v5f2I~
            swretry=0;                                             //~v5f2I~
            if (!len)                                              //~v5f2I~
            	break;                                             //~v5f2I~
//          if (*pc==',')                                         //~5430R~
            if (Pdelmtbl && strchr(Pdelmtbl,*pc))                 //~5430I~
            {                                                   //~5307R~
                pc++;                                           //~5307R~
                len--;                                          //~5307R~
//              if (spacedelm)                                     //~v046R~
//              if (spacedelm && (*(pc-1)==',' || !contdelmopt))    //space and comma//~v5izR~
                if (spacedelm && !sepdelmsw)  //efective also for space+comma//~v5izR~
                {                                                  //~v289I~
                    spacedelm=0;                                //~5307R~
                    if (contdelmopt2)   //chnage delm              //~v289I~
                        if (Spupodelmtbl)   //called from uparse2  //~v289I~
                            if (*Ppwordno)                         //~v289I~
                                if ((Spupodelmtbl+(*Ppwordno-1))->upodelm==' ')//~v289R~
                                {                                  //~v289I~
                                    (Spupodelmtbl+(*Ppwordno-1))->upodelm=*(pc-1);//~v289R~
//                                  (Spupodelmtbl+(*Ppwordno-1))->upodelmoffs=(USHORT)((ULONG)(pc-1)-(ULONG)umallocsv);//~v289I~//~v6hhR~
                                    (Spupodelmtbl+(*Ppwordno-1))->upodelmoffs=(USHORT)((ULPTR)(pc-1)-(ULPTR)umallocsv);//~v6hhI~
                                }                                  //~v289I~
                }                                                  //~v289I~
                else                                            //~5307R~
                {                                               //~5307R~
                    if (Spupodelmtbl)   //called from uparse2   //~6324R~
                    {                                           //~6324I~
                        (Spupodelmtbl+*Ppwordno)->upodelm=*(pc-1);//~6324R~
                        (Spupodelmtbl+*Ppwordno)->upoquate=0;   //~6324R~
                        (Spupodelmtbl+*Ppwordno)->upodelmoffs   //~6324R~
//                          =(USHORT)((ULONG)(pc-1)-(ULONG)umallocsv);//~6324R~//~v6hhR~
                            =(USHORT)((ULPTR)(pc-1)-(ULPTR)umallocsv);//~v6hhI~
                    }                                           //~6324I~
                    *pcout++=0; //delm field                    //~5307R~
                    (*Ppwordno)++;                              //~5307R~
                }                                               //~5307R~
                continue;                                       //~5307R~
            }                                                   //~5307R~
            swflagstring=0;     // d"hh" fmt sw                    //~v595I~
//          if (  (*pc=='\"' || *pc=='\'')                         //~v5j4R~
            if (  (*pc==quote2 || *pc==quote1)                     //~v5j4R~
               && (  pc==umallocsv          //offset 0          //~6324R~
                  || *(pc-1)==' '            //default delm     //~6324R~
                  || (Pdelmtbl && strchr(Pdelmtbl,*(pc-1))) //after delm//~v053R~
                  )                                             //~6324I~
               )                                                //~6324I~
            {                                                   //~5307R~
                quate=*pc;                                              //~5430R~
                quatestarto=pcout;      //save for retry        //~5430R~
                quatestarti=pc;         // :                    //~5430R~
                quatestartl=len;        // :                    //~5430R~
                quatestartc=*Ppwordno;  // :                    //~5430R~
                pc++;                                           //~5307R~
                len--;                                          //~5307R~
//              rc=1;                                              //~v081R~
            }                                                   //~5307R~
            else                                                //~5307R~
//          if (swallowflag &&  (*pc=='\"' || *pc=='\''))          //~v5j4R~
            if (swallowflag &&  (*pc==quote2 || *pc==quote1))      //~v5j4R~
            {                                                      //~v595I~
	            swflagstring=1;     // d"hh" fmt sw                //~v595I~
                quate=*pc++;                                       //~v595I~
                quatestarto=pcout;      //save for retry           //~v5caI~
                quatestarti=pc;         // :                       //~v5caI~
                quatestartl=len;        // :                       //~v5caI~
                quatestartc=*Ppwordno;  // :                       //~v5caI~
                *pcout++=quate;                                    //~v595I~
                len--;                                             //~v595I~
            }                                                      //~v595I~
            else                                                   //~v595I~
                quate=0;                                        //~5307R~
//* move one by one
            while(len)                                          //~5307R~
            {                                                   //~5307R~
                if (*pc==quate) //same as quatation             //~5307R~
                {                                               //~5307R~
                    if (len==1                                  //~5430R~
                    ||  *(pc+1)==' '                            //~5430I~
//                  ||  Pdelmtbl && strchr(Pdelmtbl,*pc))//enclosed//~6324R~
                    ||  (Pdelmtbl && strchr(Pdelmtbl,*(pc+1))))//enclosed//~v053R~
                    {                                           //~5307R~
                        if (Spupodelmtbl)   //called from uparse2//~6324R~
                        {                                       //~6324I~
                            (Spupodelmtbl+*Ppwordno)->upodelm=*(pc+1);//~6324R~
                            (Spupodelmtbl+*Ppwordno)->upoquate=quate;//~6324R~
                            (Spupodelmtbl+*Ppwordno)->upodelmoffs//~6324R~
//                              =(USHORT)((ULONG)(pc+1)-(ULONG)umallocsv);//~6324R~//~v6hhR~
                                =(USHORT)((ULPTR)(pc+1)-(ULPTR)umallocsv);//~v6hhI~
                        }                                       //~6324I~
                        spacedelm=(*(pc+1)==' ');   //end by space//~5307R~
                        if (tabspaceopt && *(pc+1)=='\t')   //end by space//~v235I~
                            spacedelm=1;                           //~v235I~
                        if (swflagstring)                          //~v595I~
                        	*pcout++=quate;	//set last quate as data//~v595R~
                        if (len==1)                             //~5307R~
                        {                                       //~5307R~
                            pc++;      //drop quate             //~5307R~
                            len--;                              //~5307R~
                        }                                       //~5307R~
                        else                                    //~5307R~
                        {                                       //~5307R~
                            pc+=2;      //drop quate,ignore delm//~5307R~
                            len-=2;     //for in=out case       //~5307R~
                        }                                       //~5307R~
                        quate=0;    //enclosed                  //~5307R~
                        break;      //'xxxx'                    //~5430R~
                    }//quate enclosed                           //~5430R~
                    if (*(pc+1)==quate) //double                //~5307R~
                    {                                           //~5307R~
                        pc++;       //ignore first of double    //~5307R~
                        len--;                                  //~5307R~
                    }//double                                   //~5430R~
                    else        //"xxx"y  format                //~5307R~
		            if (swquotedelm)	//quatation is delm;parse "xxx"y to xxx,y//~v5f1I~
                    {                                              //~v5f1I~
                        if (Spupodelmtbl)   //called from uparse2  //~v5f1I~
                        {                                          //~v5f1I~
                            (Spupodelmtbl+*Ppwordno)->upodelm=quate;//~v5f1R~
                            (Spupodelmtbl+*Ppwordno)->upoquate=quate;//~v5f1I~
                            (Spupodelmtbl+*Ppwordno)->upodelmoffs  //~v5f1I~
//                              =(USHORT)((ULONG)(pc+1)-(ULONG)umallocsv);//~v5f1I~//~v6hhR~
                                =(USHORT)((ULPTR)(pc+1)-(ULPTR)umallocsv);//~v6hhI~
                        }                                          //~v5f1I~
                        pc++;      //drop quate                    //~v5f1I~
                        len--;                                     //~v5f1I~
                        quate=0;    //enclosed                     //~v5f1I~
                        break;      //'xxxx'                       //~v5f1I~
                    }                                              //~v5f1I~
                    else                                           //~v5f1I~
                    {                                           //~5307R~
                        pc=quatestarti+1;                       //~5307R~
                        pcout=quatestarto;                      //~5307I~
                        *pcout++=quate;                         //~5307R~
                        len=quatestartl-1;                      //~5307R~
                        *Ppwordno=quatestartc;                  //~5307I~
                        quate=0;    //and not encloser          //~5307R~
                    }//"xxx"y format                            //~5430R~
                }                   //same quatation            //~5430R~
                else                //not same quate            //~5430R~
                    if (!quate  //not in quatation              //~5307R~
                    &&  (*pc==' '                               //~5430R~
                         || (Pdelmtbl && strchr(Pdelmtbl,*pc))))    //delimeter//~v053R~
                    {                                           //~5307R~
                        if (Spupodelmtbl)   //called from uparse2//~6324R~
                        {                                       //~6324I~
                            (Spupodelmtbl+*Ppwordno)->upodelm=*pc;//~6324R~
                            (Spupodelmtbl+*Ppwordno)->upoquate=0;//~6324R~
                            (Spupodelmtbl+*Ppwordno)->upodelmoffs//~6324R~
//                              =(USHORT)((ULONG)pc-(ULONG)umallocsv);//~6324R~//~v6hhR~
                                =(USHORT)((ULPTR)pc-(ULPTR)umallocsv);//~v6hhI~
                        }                                       //~6324I~
                        spacedelm=(*pc==' ');   //end by space  //~5307R~
                        if (tabspaceopt && *pc=='\t')   //end by space//~v235R~
                            spacedelm=1;                           //~v235I~
                        pc++;   //for in==out case              //~5307R~
                        len--;                                  //~5307R~
                        break;  //next field                    //~5307R~
                    }                                           //~5307R~
                    else                                           //~v5caR~
//                  if (swallowflag &&  (*pc=='\"' || *pc=='\''))  //~v5j4R~
                    if (swallowflag &&  (*pc==quote2 || *pc==quote1))//~v5j4R~
                    {                                              //~v5caR~
                      if (!quate)                                  //~v5caI~
                      {                                            //~v5caI~
                        swflagstring=1;     // d"hh" fmt sw        //~v5caR~
                        quate=*pc;                                 //~v5caR~
                        quatestarto=pcout;      //save for retry   //~v5caI~
                        quatestarti=pc;         // :               //~v5caI~
                        quatestartl=len;        // :               //~v5caI~
                        quatestartc=*Ppwordno;  // :               //~v5caI~
                      }                                            //~v5caI~
                    }                                              //~v5caR~
                    else                                           //~v5f1I~
//                  if (swquotedelm &&  (*pc=='\"' || *pc=='\'')) //delm start//~v5j4R~
                    if (swquotedelm &&  (*pc==quote2 || *pc==quote1)) //delm start//~v5j4R~
                    {                                              //~v5f1I~
                      	if (!quate)                                //~v5f1I~
                      	{                                          //~v5f1I~
                            if (Spupodelmtbl)   //called from uparse2//~v5f1I~
                            {                                      //~v5f1I~
                                (Spupodelmtbl+*Ppwordno)->upodelm=*pc;//~v5f1I~
                                (Spupodelmtbl+*Ppwordno)->upoquate=0;//~v5f1I~
                                (Spupodelmtbl+*Ppwordno)->upodelmoffs//~v5f1I~
//                                  =(USHORT)((ULONG)(pc-1)-(ULONG)umallocsv);//~v5f1I~//~v6hhR~
                                    =(USHORT)((ULPTR)(pc-1)-(ULPTR)umallocsv);//~v6hhI~
                            }                                      //~v5f1I~
           					 *pcout++=0; //delm field              //~v5f1I~
            				(*Ppwordno)++;                         //~v5f1I~
                            quate=*pc;                             //~v5f1I~
                            quatestarto=pcout;      //save for retry//~v5f1I~
                            quatestarti=pc;         // :           //~v5f1I~
                            quatestartl=len;        // :           //~v5f1I~
                            quatestartc=*Ppwordno;  // :           //~v5f1I~
                            pc++;                                  //~v5f1I~
                            len--;                                 //~v5f1I~
                            continue;		//serch encloser       //~v5f1I~
                      	}                                          //~v5f1I~
                    }                                              //~v5f1I~
                *pcout++=*pc++;                                 //~5307R~
                len--;                                          //~5307R~
            }//len loop                                         //~5430R~
            *pcout++=0; //delm field                            //~5307R~
            (*Ppwordno)++;                                      //~5307R~
        }//word loop                                            //~5307R~
        if (!quate) //not enclosed                              //~5307R~
            break;                                              //~5307I~
        pc=quatestarti+1;                                       //~5307R~
        pcout=quatestarto;                                      //~5307I~
     if (!swquotedelm)                                             //~v5f1I~
        *pcout++=quate;                                         //~5307I~
        len=quatestartl-1;                                      //~5307R~
      if (len)     //not last is quate                             //~v574I~
        *Ppwordno=quatestartc;                                  //~5307I~
      else           // started quate but no char following (simple " or ' case)//~v574I~
        *pcout++=0; //set string end                               //~v574I~
        quate=0;    //and not encloser                          //~5307I~
        spacedelm=0;                                               //~v5f2I~
     if (!swquotedelm)  //skip space if quate is trated as delm    //~v5f1I~
        swretry=1;                                                 //~v5f2I~
        rc=1;                                                   //~5307I~
    }//quate not enclose retry loop                             //~5307R~
//last delm pos                                                 //~6324I~
    if (Spupodelmtbl)   //called from uparse2                   //~6324I~
        if (*Ppwordno)                                          //~6324R~
            if (!((Spupodelmtbl+(*Ppwordno-1))->upodelmoffs))   //~6324R~
                (Spupodelmtbl+(*Ppwordno-1))->upodelmoffs       //~6324I~
//                  =(USHORT)((ULONG)pc-(ULONG)umallocsv);      //~6324I~//~v6hhR~
                    =(USHORT)((ULPTR)pc-(ULPTR)umallocsv);         //~v6hhI~
    if (umallocsv!=wkbuff)  //not stack                            //~v046I~
    ufree(umallocsv);                                           //~5307I~
//  Sparseoutlen=(UINT)((ULONG)pcout-(ULONG)Pout);  //parm to uparse2//~v046R~
    return rc;                                                  //~5307R~
}//uparse

//*******************************************************          //~v117I~
//*parse out filename                                              //~v117I~
//*  drop quatation,atop at ' ' or ','                             //~v117I~
//*parm 1:option; 0:no opearnd,1:operand(cut by filename)          //~v117R~
//*parm 2:input string                                             //~v117I~
//*parm 3:output string                                            //~v117R~
//*parm 4:optional output, delm pos on input string                //~v117R~
//*parm 5:optional output, output string len                       //~v117R~
//*return:rc:0:no quatation,4:quatation detected,8 input too long  //~v117R~
//*******************************************************          //~v117I~
//int uparsefname(int Popt,char *Pifname,char *Pofname,int *Pdelmpos,int *Poutlen)//+v6H2R~
int uparsefname(int Popt,char *Pifname,char *Pofname,int *Pdelmpos,int Pbuffsz,int *Poutlen)//+v6H2I~
{                                                                  //~v117I~
    int ii,qsw,rc=0;                                               //~v117R~
    char *pci,*pco;                                                //~v117I~
//*********************************                                //~v117I~
    pci=Pifname;                                                   //~v117I~
    while (*pci==' ')                                              //~v117I~
        pci++;                                                     //~v117I~
    for (pco=Pofname,ii=0,qsw=0;*pci;pci++)                        //~v117I~
    {                                                              //~v117I~
        if (*pci=='"')                                             //~v117I~
        {                                                          //~v117I~
            rc=4;                                                  //~v117I~
            qsw=!qsw;                                              //~v117I~
        }                                                          //~v117I~
        else                                                       //~v117I~
            if (Popt && (!qsw) && (*pci==' ' || *pci==','))        //~v117R~
                break;                                             //~v117I~
            else                                                   //~v117I~
            {                                                      //~v117I~
//              if (++ii>=_MAX_PATH-1)                             //~v6H2R~
                if (++ii>=Pbuffsz)     //comp after ii             //+v6H2R~
                {                                                  //~v117I~
                    rc=8;                                          //~v117I~
                    break;                                         //~v117I~
                }                                                  //~v117I~
                *pco++=*pci;                                       //~v117I~
            }                                                      //~v117I~
    }                                                              //~v117I~
    *pco=0;                                                        //~v117I~
    if (Poutlen)                                                   //~v117I~
        *Poutlen=ii;                                               //~v117R~
    if (Pdelmpos)                                                  //~v117I~
//      *Pdelmpos=(int)((ULONG)pci-(ULONG)Pifname);                //~v117R~//~v6hhR~
        *Pdelmpos=(int)((ULPTR)pci-(ULPTR)Pifname);                //~v6hhI~
    return rc;                                                     //~v117I~
}//uparsefname                                                     //~v117I~
                                                                   //~v127I~
//*******************************************************          //~v127M~
//*parse out cmd line                                              //~v127M~
//*  cut string by ' ',drop " in word and enclose by " optionaly   //~v127M~
//*  \" is treated as data ". \\ is single if followed by \"       //~v128I~
//*parm 1:option; 0:drop enclosing quatation                       //~v128R~
//*               1:as is base(no drop any quate)                  //~v128R~
//*parm 2:input string                                             //~v127M~
//*parm 3:output operand number                                    //~v127M~
//*parm 4:output string addr,if 0 malloc-ed and caller must free   //~v127M~
//*parm 5:optional output,vfmt operand ptr list(in the area of out area)//~v127M~
//*parm 6:optional output,delmtbl(in the area of out area)         //~v128R~
//*return:rc:0 or UALLOC_FAILED                                    //~v127M~
//*******************************************************          //~v127M~
int uparsecmd(int Popt,char *Pcmd,int *Popdno,char **Ppout,char ***Ppopdv,//~v128R~
                PUPODELMTBL*Ppdelmt)                               //~v128I~
{                                                                  //~v127M~
    int opdno,qsw,qdatasw,wordlen,len,delmtoffs,opdvoffs;          //~v128R~
    int wordlenprev,datalen,asissw;                                //~v127R~
    char ch,*pci,*pci0,*pco,*pco0;                                 //~v128R~
    int bsctr;                                                     //~v128I~
    PUPODELMTBL pdelmt=0,pdelmt0;                                  //~v328R~
    char **popdv;                                                  //~v128I~
    int  termch;                                                   //~v5ezI~
//*********************************                                //~v127M~
//    dropsw=!(Popt & UPCMD_ENCLOSEQ);                             //~v128R~
	termch=(int)((UINT)(Popt & UPCMD_TERMCHMASK)>>8);              //~v5f1R~
    asissw=(Popt & UPCMD_ASIS);                                    //~v127R~
    pci=Pcmd;                                                      //~v127M~
    while (*pci==' ')                                              //~v127M~
        pci++;                                                     //~v127M~
    pci0=pci;           //save top                                 //~v127M~
    len=0;                                                         //~v127M~
    datalen=0;                                                     //~v127M~
    bsctr=0;            //continuous \ count                       //~v128I~
    for (opdno=qsw=wordlen=0;;pci++)                               //~v127M~
    {                                                              //~v127M~
        switch(ch=*pci,ch)                                         //~v127M~
        {                                                          //~v127M~
        case DQUATE:                                               //~v127M~
          if (!(bsctr & 1))//even number                           //~v128R~
            qsw=!qsw;                                              //~v127M~
            datalen++;                                             //~v127M~
            if (asissw)                                            //~v127I~
                wordlen++;                                         //~v127I~
            break;                                                 //~v127M~
        case 0:                                                    //~v127M~
        case DELMSP:                                               //~v127M~
            if (qsw && ch)  //in qautation                         //~v127M~
            {                                                      //~v127M~
                wordlen++;                                         //~v127M~
                datalen++;                                         //~v127M~
            }                                                      //~v127M~
            else                                                   //~v127M~
            {                                                      //~v127M~
                if (datalen)    //first time                       //~v127M~
                {                                                  //~v127M~
                    len+=wordlen;   //drop delm space              //~v127M~
//printf("wordlen=%d,word=%s;\n",wordlen,pci);                     //~v127I~
                    opdno++;                                       //~v127M~
                    wordlen=0;                                     //~v127M~
                    datalen=0;                                     //~v127M~
                }                                                  //~v127M~
            }                                                      //~v127M~
            break;                                                 //~v127M~
        default:                                                   //~v127M~
        	if (ch==termch)	//end of line specified                //~v5ezI~
            {                                                      //~v5ezI~
	            if (!qsw)  //not in qautation                      //~v5ezI~
                {                                                  //~v5ezI~
                    if (datalen)    //first time                   //~v5ezI~
                    {                                              //~v5ezI~
                        len+=wordlen;   //drop delm space          //~v5ezI~
	                    opdno++;                                   //~v5ezI~
                    }                                              //~v5ezI~
                    ch=0;	//break loop                           //~v5ezI~
                    break;                                         //~v5ezI~
                }                                                  //~v5ezI~
            }                                                      //~v5ezI~
            wordlen++;                                             //~v127M~
            datalen++;                                             //~v127M~
        }//sw by char                                              //~v127M~
        if (!ch)                                                   //~v127M~
            break;                                                 //~v127M~
        if (ch==BSLASH)                                            //~v128I~
            bsctr++;        //continued ctr                        //~v128I~
        else                                                       //~v128I~
            bsctr=0;                                               //~v128I~
    }//search delm ' '                                             //~v127M~
    if (Popt & UPCMD_GETENDOFFS)	//req oly get terminater offset//~v5ezI~
    {                                                              //~v5ezI~
//      *Popdno=(int)((ULONG)pci-(ULONG)Pcmd);                     //~v5ezR~//~v6hhR~
        *Popdno=(int)((ULPTR)pci-(ULPTR)Pcmd);                     //~v6hhI~
    	if (*pci)                                                  //~v5ezR~
        	return 0;                                              //~v5ezI~
        else                                                       //~v5ezI~
        	return 4;	//not found                                //~v5ezR~
    }                                                              //~v5ezI~
//malloc                                                           //~v127M~
//printf("datalen=%d\n",len);                                      //~v127I~
    len+=opdno;     //null delm for each opd                       //~v127M~
//    if (!asissw)                                                 //~v128R~
//        if (!dropsw)                                             //~v128R~
//            len+=(opdno<<1);    //encloser                       //~v128R~
    len=(int)(((UINT)(len+3)>>2)<<2);  //word boundary                  //~v5caR~
    if (Ppopdv)                                                    //~v127M~
    {                                                              //~v127M~
        opdvoffs=len;                                              //~v127M~
//      len+=(opdno+1)*4;   //last null ptr                        //~v127M~//~v690R~
        len+=(opdno+1)*PTRSZ;   //last null ptr                    //~v690I~
    }                                                              //~v127M~
    else                                                           //~v127M~
        opdvoffs=0;                                                //~v127M~
    if (Ppdelmt)        //requested delm tbl output,for each opd   //~v127M~
    {                                                              //~v127M~
        delmtoffs=len;                                             //~v127M~
//      len+=UPODELMTBLSZ*opdno;     //delmtbl for each opd and null term//~v128R~//~v6BkR~
        len+=(int)UPODELMTBLSZ*opdno;     //delmtbl for each opd and null term//~v6BkI~
    }                                                              //~v127M~
    else                                                           //~v127M~
        delmtoffs=0;                                               //~v127M~
    pco=*Ppout;                                                    //~v127M~
    if (!pco)                                                      //~v127M~
    {                                                              //~v127M~
        pco=umalloc((UINT)len);                                    //~v127R~
        *Ppout=pco;                                                //~v127I~
        UALLOCCHK(pco,UALLOC_FAILED);                              //~v127M~
    }                                                              //~v127M~
//printf("wordno=%d,totlen=%d,opdvoff=%d,delmtoff=%d\n",opdno,len,opdvoffs,delmtoffs);//~v127I~
    pco0=pco;   //save top                                         //~v127M~
//  pdelmt0=(PUPODELMTBL)(ULONG)(pco0+delmtoffs);                  //~v128R~//~v6hhR~
    pdelmt0=(PUPODELMTBL)(ULPTR)(pco0+delmtoffs);                  //~v6hhI~
//  popdv=(char **)(ULONG)(pco0+opdvoffs);                         //~v127M~//~v6hhR~
    popdv=(char **)(ULPTR)(pco0+opdvoffs);                         //~v6hhI~
    wordlenprev=0;                                                 //~v127M~
//paese out                                                        //~v127M~
    pci=pci0;           //saved top                                //~v127M~
//    pcs=0;                                                       //~v128R~
    datalen=0;                                                     //~v127M~
    for (opdno=qsw=qdatasw=wordlen=0;;pci++)                       //~v127M~
    {                                                              //~v127M~
        switch(ch=*pci,ch)                                         //~v127M~
        {                                                          //~v127M~
        case DQUATE:                                               //~v127M~
          if (!(bsctr & 1))//even number                           //~v128I~
            qsw=!qsw;                                              //~v127M~
            datalen++;                                             //~v127M~
            if (asissw)                                            //~v127I~
                wordlen++;                                         //~v127I~
            else                                                   //~v128I~
                if (bsctr)//even number                            //~v128I~
                {                                                  //~v5caI~
                    if (bsctr & 1)//odd number                     //~v128I~
                    {                                              //~v128I~
//                      bsctr>>=1;  //                             //~v5caR~
                        bsctr=(int)((UINT)bsctr>>1);               //~v5caI~
                        pco-=(bsctr+1); //set quatation as data    //~v128I~
                        wordlen-=bsctr;                            //~v128I~
                        wordlenprev=0;  //force set current " as data//~v128I~
                    }                                              //~v128I~
                    else                                           //~v128I~
                    {                                              //~v128I~
//                      bsctr>>=1;  //                             //~v5caR~
                        bsctr=(int)((UINT)bsctr>>1);               //~v5caI~
                        pco-=bsctr; //drop to half                 //~v128R~
                        wordlen-=bsctr;                            //~v128R~
                        wordlenprev=wordlen;    //bypass output    //~v128R~
                    }                                              //~v128I~
                }//bsctr                                           //~v5caI~
            break;                                                 //~v127M~
        case 0:                                                    //~v127M~
        case DELMSP:                                               //~v127M~
            if (qsw && ch)  //space in qautation                   //~v127M~
            {                                                      //~v127M~
                wordlen++;                                         //~v127M~
                datalen++;                                         //~v127M~
            }                                                      //~v127M~
            else                                                   //~v127M~
            {                                                      //~v127M~
                if (datalen)    //first time                       //~v127M~
                {                                                  //~v127M~
                    if (delmtoffs)                                 //~v127M~
                    {                                              //~v128I~
                        pdelmt=pdelmt0+opdno;                      //~v128I~
                        pdelmt->upodelm=ch; //space or null        //~v128R~
//                      pdelmt->upodelmoffs=(USHORT)((ULONG)pci-(ULONG)Pcmd);   //space or null//~v128R~//~v6hhR~
                        pdelmt->upodelmoffs=(USHORT)((ULPTR)pci-(ULPTR)Pcmd);   //space or null//~v6hhI~
                        if (qdatasw)                               //~v127M~
                            pdelmt->upoquate=DQUATE;               //~v128R~
                        else                                       //~v127M~
                            pdelmt->upoquate=DELMSP;               //~v128R~
                    }                                              //~v128I~
//                    if (!asissw)                                 //~v128R~
//                        if (!dropsw)        //start by quate     //~v128R~
//                            if (qdatasw)    //data need quate    //~v128R~
//                                *pco++=DQUATE;                   //~v128R~
//                            else                                 //~v128R~
//                            {                                    //~v128R~
//                                memcpy(pcs,pcs+1,(UINT)wordlen);    //drop assumed qute//~v128R~
//                                pco--;                           //~v128R~
//                            }                                    //~v128R~
                    *pco++=0;                                      //~v127M~
                    opdno++;                                       //~v127M~
                    wordlen=0;                                     //~v127M~
                    datalen=0;//space delm                         //~v127M~
                    qdatasw=0;                                     //~v127M~
                }                                                  //~v127M~
            }                                                      //~v127M~
            break;                                                 //~v127M~
        default:                                                   //~v127M~
        	if (ch==termch)	//end of line specified                //~v5ezI~
            {                                                      //~v5ezI~
	            if (!qsw)  //not in qautation                      //~v5ezI~
                {                                                  //~v5ezI~
                    if (datalen)    //first time                   //~v5ezI~
                    {                                              //~v5ezI~
                        len+=wordlen;   //drop delm space          //~v5ezI~
	                    opdno++;                                   //~v5ezI~
                    }                                              //~v5ezI~
                    ch=0;	//break loop                           //~v5ezI~
                    break;                                         //~v5ezI~
                }                                                  //~v5ezI~
            }                                                      //~v5ezI~
            wordlen++;                                             //~v127M~
            datalen++;                                             //~v127M~
        }//sw by char                                              //~v127M~
        if (!ch)                                                   //~v127M~
            break;                                                 //~v127M~
        if (ch==BSLASH)                                            //~v128I~
            bsctr++;        //continued ctr                        //~v128I~
        else                                                       //~v128I~
            bsctr=0;                                               //~v128I~
        if (datalen==1) //for len=0 data ("")                      //~v127M~
        {                                                          //~v127M~
//            pcs=pco;                                             //~v128R~
            if (opdvoffs)                                          //~v127M~
                popdv[opdno]=pco;                                  //~v127M~
//            if (!asissw)                                         //~v128R~
//                if (!dropsw)                                     //~v128R~
//                    *pco++=DQUATE;  //once assume                //~v128R~
            if (qsw)                                               //~v127M~
                qdatasw=1;                                         //~v127M~
        }                                                          //~v127M~
        if (wordlen && (wordlen!=wordlenprev))  //changed          //~v127R~
        {                                                          //~v127M~
            *pco++=ch;                                             //~v127M~
            if (qsw)                                               //~v127M~
                qdatasw=1;                                         //~v127M~
        }//wordlen changed                                         //~v127M~
        wordlenprev=wordlen;                                       //~v127I~
    }//search delm ' '                                             //~v127M~
//return value                                                     //~v127M~
    if (opdvoffs)                                                  //~v127M~
    {                                                              //~v127M~
        popdv[opdno]=0; //last null ptr                            //~v127M~
        *Ppopdv=popdv;                                             //~v127M~
    }                                                              //~v127M~
    if (delmtoffs)                                                 //~v127M~
        *Ppdelmt=pdelmt;                                           //~v127M~
    *Popdno=opdno;                                                 //~v127M~
    return 0;                                                      //~v127M~
}//uparsecmd                                                       //~v127M~
                                                                   //~v130I~
//*******************************************************          //~v130I~
//!uparsecmdin                                                     //~v130I~
//* enclose by quatation if space embedding                        //~v130I~
//  (\ followed " is set to doubled \;" is set to \")              //~v130I~
//* parm1 :input string                                            //~v130I~
//* parm2 :output area                                             //~v130I~
//* parm3 :out area len                                            //~v130I~
//* parm4 :optional;out len                                        //~v130I~
//* return:rc 0:no need to enclabe,copyed                          //~v130I~
//*           1:enclabed no doubled quatation                      //~v130I~
//*           4:out area shortage                                  //~v130I~
//******************************************************           //~v130I~
int uparsecmdin(char *Pin,char *Pout,int Poutarealen,int *Poutlen) //~v130I~
{                                                                  //~v130I~
    char *pci,*pco,*pcoend,ch,ch0;                                 //~v130R~
    int  leni,bsctr;                                               //~v130R~
//******************                                               //~v130I~
    leni=(int)strlen(Pin);                                         //~v130I~
    if (Poutarealen<=leni)                                         //~v130I~
        return 4;                                                  //~v130I~
    if (!strchr(Pin,' '))           //no space                     //~v130I~
    {                                                              //~v130I~
        memcpy(Pout,Pin,(UINT)leni);                               //~v130I~
        *(Pout+leni)=0;                                            //~v130I~
        if (Poutlen)                                               //~v130I~
            *Poutlen=leni;                                         //~v130I~
        return 0;                       //copyed                   //~v130I~
    }                                                              //~v130I~
    if (Poutarealen<=(leni+2))                  //add encloser     //~v130I~
        return 4;                                                  //~v130I~
    pco=Pout;                                                      //~v130I~
    pci=Pin;                                                       //~v130I~
    *pco++=DQUATE;                                                 //~v130I~
    pcoend=pco+Poutarealen-2;       //last quate and terminator null//~v130I~
    bsctr=0;                                                       //~v130I~
    do  //until ch==0                                              //~v130I~
    {                                                              //~v130I~
        ch=ch0=*pci++;                                             //~v130I~
        if (!ch)                                                   //~v130I~
            ch=DQUATE;  //last quatation                           //~v130I~
        if (ch==BSLASH)                                            //~v130I~
            bsctr++;                                               //~v130I~
        else                                                       //~v130I~
        {                                                          //~v130I~
            if (bsctr)                                             //~v130I~
            {                                                      //~v130I~
                if (ch==DQUATE)                                    //~v130I~
                    bsctr<<=1;                                     //~v130R~
                if (pco+bsctr>=pcoend)                             //~v130I~
                    return 4;                                      //~v130I~
                memset(pco,BSLASH,(UINT)bsctr);                    //~v130I~
                pco+=bsctr;                                        //~v130I~
                bsctr=0;                                           //~v130I~
            }//previous BSLASh                                     //~v130I~
            else    //no BSLASH                                    //~v130I~
                if (ch0==DQUATE)                                   //~v130I~
                    *pco++=BSLASH;                                 //~v130I~
            *pco++=ch;                                             //~v130I~
            if (pco>pcoend)                                        //~v130I~
                return 4;                                          //~v130I~
        }//not BSLASH                                              //~v130I~
    } while(ch0);                                                  //~v130R~
    *pco=0;                                                        //~v130I~
    if (Poutlen)                                                   //~v130I~
//      *Poutlen=(int)((ULONG)pco-(ULONG)Pout);                    //~v130I~//~v6hhR~
        *Poutlen=(int)((ULPTR)pco-(ULPTR)Pout);                    //~v6hhI~
    return 1;           //enclosed and expanded                    //~v130I~
}//uparsecmdin                                                     //~v130I~
//#ifdef UNX                                                       //~v5cxR~
//*******************************************************          //~v374I~
//!uparsegetopt                                                    //~v374I~
//* get flag operand and construct new parsed string by others     //~v374I~
//* parm1 :option,ignore case etc                                  //~v374I~
//* parm2 :input parm seperated by null char                       //~v374I~
//* parm3 :input/output parm ctr                                   //~v374I~
//* parm4 :flag char's                                             //~v374I~
//* parm5 :output to set reconstructed parsed string addr          //~v374I~
//* parm6 :output to set flag value addr array                     //~v374I~
//* return:rc 0:ok,4:too long parm,8:parm err                      //~v374I~
//******************************************************           //~v374I~
int uparsegetopt(int Popt,char *Pinp,int *Pctr,char *Pflag,char **Poutp,char **Pflagparm)//~v374I~
{                                                                  //~v374I~
#define MAXPLEN 512                                                //~v374I~
static  char Snewparm[MAXPLEN+1];                                  //~v374I~
    char *pci,*pco,*pv,*pcf;                                       //~v374R~
    int  ii,jj,len,tlen=0,pctr,newctr=0,flaglen,flag,uflag;        //~v374I~
    int flagsw1=0,flagsw2=0;                                       //~v5cxI~
//******************                                               //~v374I~
    *Snewparm=0;                                                   //~v5cxI~
	flaglen=(int)strlen(Pflag);                                    //~v374I~
//  memset(Pflagparm,0,(UINT)flaglen*4);	//id of no flag        //~v374I~//~v690R~
    memset(Pflagparm,0,(UINT)flaglen*PTRSZ);	//id of no flag    //~v690I~
#ifdef UNX                                                         //~v5cxI~
	flagsw2='-';                                                   //~v5cxI~
#else                                                              //~v5cxI~
	flagsw1='/';                                                   //~v5cxI~
#endif                                                             //~v5cxI~
    if (Popt & UPGO_FLAGDOS)                                       //~v5cxI~
    	flagsw1='/';                                               //~v5cxI~
    if (Popt & UPGO_FLAGUNIX)                                      //~v5cxI~
    	flagsw2='-';                                               //~v5cxI~
    for (ii=0,pci=Pinp,pco=Snewparm,pctr=*Pctr;ii<pctr;ii++)       //~v374I~
    {                                                              //~v374I~
        len=(int)strlen(pci)+1;                                    //~v374I~
//  	if (*pci=='-') //flagparm                                  //~v5cxR~
        if (*pci&&(*pci==flagsw1||*pci==flagsw2))                  //~v5cxR~
        {                                                          //~v374I~
        	flag=(int)*(pci+1);                                    //~v374I~
        	uflag=toupper(flag);                                   //~v374I~
        	for (jj=0,pcf=Pflag;jj<flaglen;jj++,pcf++)             //~v374I~
            	if (flag==*pcf                                     //~v374I~
                ||  ((Popt & UPGO_NOCASE) && uflag==toupper(*pcf)))//~v374I~
                	break;                                         //~v374I~
            if (jj==flaglen)//unmatch                              //~v374I~
            {                                                      //~v374I~
//          	if (UPGO_ERRMSG)                                   //~v40eR~
            	if (Popt & UPGO_ERRMSG)                            //~v40eI~
                	uerrmsg("flag err(%s)",0,                      //~v374I~
							pci);                                  //~v374I~
                return 8;                                          //~v374I~
            }                                                      //~v374I~
            if (*(pci+2))	//flag value splitted                  //~v374I~
            	pv=pci+2;                                          //~v374I~
            else                                                   //~v374I~
            {                                                      //~v374I~
        		pci+=len;   //next operand addr                    //~v374I~
                ii++;       //1 parm used                          //~v374I~
		        len=(int)strlen(pci)+1;                            //~v374I~
              if (Popt & UPGO_NOSPLIT)                             //~v5cxI~
                pv="";                                             //~v5cxI~
              else                                                 //~v5cxI~
                pv=pci;                                            //~v374I~
            }                                                      //~v374I~
            *(Pflagparm+jj)=pv;                                    //~v374I~
        }                                                          //~v374I~
        else                                                       //~v374I~
        {                                                          //~v374I~
        	newctr++;                                              //~v374I~
        	tlen+=len;                                             //~v374I~
        	if (tlen>MAXPLEN)	                                   //~v374I~
            {                                                      //~v374I~
//            	if (UPGO_ERRMSG)                                   //~v40eR~
            	if (Popt & UPGO_ERRMSG)                            //~v40eI~
                	uerrmsg("parm is too long",0);                 //~v374I~
            	return 4;                                          //~v374I~
            }                                                      //~v374I~
            memcpy(pco,pci,(UINT)len);    	                       //~v374R~
            pco+=len;                                              //~v374I~
        }                                                          //~v374I~
        pci+=len;   //next operand addr                            //~v374I~
    }                                                              //~v374I~
    *Pctr=newctr;                                                  //~v374I~
    *Poutp=Snewparm;                                               //~v374I~
    return 0;                                                      //~v374I~
}//uparsegetopt                                                    //~v374I~
//#endif //UNX                                                     //~v5cxR~
