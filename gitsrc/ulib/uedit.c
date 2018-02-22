//*CID://+v6T1R~:                             update#=   82;       //~v6T1R~
//*************************************************************
//*uedit.c                                                         //~v022R~
//*  unumedit,utimeedit,uitoa10,ucmdparmedit,uwordrep              //~v066R~
//*  ugethex,ux2l,ux2s,ugetnumrange,ugetxnumrange,unumlen,uatoin   //~v244R~
//*  ugetnumrange2 ugetnumrange3                                   //~v5fxR~
//*************************************************************
//v6T1:180210 add ueditKMG(edit Kiro,mega,Giga value)              //~v6T1I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6xk:150115 (BUG:W32)spwanxx deplicated,use _spawnxx(return intptr_t, Linux returns int pid)//~v6xkI~
//v6x3:150106 add editFILESZ                                       //~v6x3I~
//v6x1:150105 BUG:ux2ll return 4 for null str. change to return 0 and value 0//~v6x1I~
//v6x0:150105 BUG:offset value is long long for fseek error msg    //~v6x0I~
//v6qg:131209 support addtional parm;%*,%^ for filename,%@ all remaining//~v6qgI~
//v6q3:131129 (LNX)compiler warning;dereferencing type-punned pointer//~v6q3I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v5h7I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v5h6I~
//v5k2:061227*(LNX/WIN)bc_dweditnum64(long long int edit func) add //~v5k2I~
//v5iu:060903 ucmdparmedit:accept opd=null,trate as ""             //~v5iuI~
//v5fx:050325 ugetnumrange3 for v5fw(copy from tc_getnumrange)     //~v5fxI~
//v5fk:050226 (BUG)unumlen abend by overrun end of string          //~v5fkI~
//v5f4:041121 replace $abc,${abc},%abc% by env variable for xe set cmd//~v5f4I~
//v5e7:041003 unumedit:"-" for edit as minus value, "z" is for unsigned.//~v5e7I~
//v5bh:040208 0x prefixed hexnum support                           //~v5bhI~
//v5a3:040102 getnumrange2:support last option for getnumrange,getxnumrange//~v5a3I~
//v59k:031108 uedittime mili-sec support(string output only)       //~v59kI~
//v59h:031104 (AIX:BUG)aix time over 2000 is 1xx                   //~v59hI~
//v57W:030727 hexdump conv to bin                                  //~v57WI~
//v526:020203 Octal support of unumlen                             //~v526I~
//v40m:001128 AIX support:Big endian                               //~v40mI~
//v345:000925 LINUX support(month:tm_mon start from 0)             //~v345I~
//v328 000826:LINUX:gcc detected warning:uninitialized var         //~v328I~
//v321 000729:UNIX support                                         //~v321R~
//v303 000325:(BUG)unumlen allof minus sign on top                 //~v303I~
//v302 000324:(BUG)unumedit - sign dropped when 1 digit(on '9')    //~v302I~
//v301 000323:unumlen preceding space option                       //~v301I~
//v244:990606 add ugetxnumrange func                               //~v244I~
//v232:990404 (BUG)unumedit -123 -->"-,123"                        //~v232I~
//v129:971210 use uparsecd for the uparsev in ucmdparmedit         //~v129I~
//            padding not used opd by option                       //~v129I~
//v126:971203 (BUG)of v125;ufree missing when not v fmt            //~v126I~
//v125:971130 ucmdparmedit new option(vfmt)                        //~v125I~
//v098:970723 split uparse fro ustring to uparse.c                 //~v098I~
//v096:970720 uatoin(uatoi with maxlen)                            //~v096I~
//v095:970720 unumlen(count digit string len)                      //~v095I~
//v066:970215:new function uwirdrep                                //~v066I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -size_t unsigned int-->long int,int 2-->4 byte       //~v053I~
//v047:961124:ugetnumrange (get value from nnn-mmmm format)        //~v047I~
//v025:960901:add ugethex                                          //~v025I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//*950820 add uitoa10                                           //~5820R~
//*950702 add utimeedit                                         //~5820I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
#ifdef UNX                                                         //~v321R~
    #include <sys/timeb.h>                                         //~v321R~
#else                                                              //~v321R~
#ifdef DOS
    #include <dos.h>
#else
    #ifdef W32                                                     //~v022I~
        #include <windows.h>                                       //~v022I~
    #else                                                          //~v022I~
    #define INCL_DOSDATETIME    //for DosSleep,DosGetDateTime
    #define INCL_BASE
    #include <os2.h>
    #endif                                                         //~v022I~
#endif
#endif  //!UNX                                                     //~v321R~
//*******************************************************
#include <ulib.h>
#include <uedit.h>
#include <ualloc.h>                                             //~5A14I~
#include <uparse.h>                                                //~v098I~
#include <ustring.h>                                               //~v6x3I~
#ifdef UNX                                                         //~v321R~
    #include <ugcclib.h>                                           //~v321I~
#endif  //!UNX                                                     //~v321R~
//*******************************************************
static char Sgetnumpostfix=0;                                      //~v5a3I~
static char Sgetnumpostfix2=0;                                     //~v5a3I~
#define CMDPARM_REMAINING   '@'                                    //~v6qgI~
#define CMDPARM_CURFNM      '*'                                    //~v6qgI~
#define CMDPARM_SPLITFNM    '^'                                    //~v6qgI~
//*******************************************************
//*uedit
//* dummy for LIB
//******************************************************
void uedit(void)
{
    return;
}//uedit

//*******************************************************
//*unumedit
//* numeric patern edit
//* parm1 :int
//* parm2 :patern string(z,Z,9 for numeric)
//* parm3 :output area addr
//* return:0:ok,4:efective digit cut occuerd
//******************************************************
int unumedit(unsigned long Pnum,unsigned char *Ppatern,unsigned char *Pout)
{
    UCHAR work[12],*pcd,*pcs;
    int lens,lend,ii,jj,rc,digitsw;
    int signsw;                                                    //~v232I~
//******************
  if (*Ppatern=='-')                                               //~v5e7I~
    sprintf(work,"%ld",Pnum);
  else                                                             //~v5e7I~
    sprintf(work,"%lu",Pnum);   //unsigned                         //~v5e7I~
    lens=(int)strlen(work);         //source len
    lend=(int)strlen(Ppatern);      //dest len;
    for (ii=0,jj=0,pcd=Ppatern;ii<lend;ii++,pcd++)
//      if (*pcd=='z' || *pcd=='Z' || *pcd=='9')                   //~v5e7R~
        if (*pcd=='z' || *pcd=='Z' || *pcd=='9'|| *pcd=='-')       //~v5e7I~
            jj++;
    if (jj<lens)    //digit cut
    {
        rc=4;
        pcs=work+lens-jj;
        jj=0;       //start edit from first
    }
    else            //
    {
        rc=0;
        pcs=work;
        jj=jj-lens; //set 0 jj times
    }
//output
    strcpy(Pout,Ppatern);
    digitsw=0;
    signsw=0;                                                      //~v232I~
    for (ii=0,pcd=Pout;ii<lend;ii++,pcd++)
    {
        switch(*pcd)
        {
        case 'z':
        case 'Z':
        case '-':                                                  //~v5e7I~
            if (jj) //over efective digit
            {
                jj--;
                *pcd=' ';
            }
            else
            {
              if (*pcs=='-')    //sign                             //~v232I~
              {                                                    //~v232I~
                signsw=1;                                          //~v232I~
                *pcd=' ';                                          //~v232I~
                pcs++;                                             //~v232I~
              }                                                    //~v232I~
              else                                                 //~v232I~
              {                                                    //~v232I~
                if (signsw) //prev is sign                         //~v232I~
                {                                                  //~v232I~
                    *(pcd-1)='-';                                  //~v232I~
                    signsw=0;      //processed                     //~v232I~
                }                                                  //~v232I~
                *pcd=*pcs++;
                digitsw=1;
              }                                                    //~v232I~
            }
            break;
        case '9':
            if (jj) //over efective digit
            {
                jj--;
                *pcd='0';
            }
            else
            {                                                      //~v302I~
                if (signsw) //prev is sign,not yet set by Z        //~v302I~
                {                                                  //~v302I~
                    *(pcd-1)='-';                                  //~v302I~
                    signsw=0;      //processed                     //~v302I~
                }                                                  //~v302I~
                *pcd=*pcs++;
            }                                                      //~v302I~
            digitsw=1;
            break;
        default :
            if (!digitsw) //over efective digit
                *pcd=' ';
            break;
        }
    }
    return rc;
}//unumedit

//*******************************************************
//*utimeedit
//* edit current date/time
//* parm1 :edit patern(output format)
//*        0:(int)YYyymmddhhmmssth  1:(int)ddmmyyYYthssmmhh  0a for ten
//*        2:(hex)YYyymmddhhmmssth  3:(hex)ddmmyyYYthssmmhh  10 for ten
//*          YY=year/100,yy=year%100,mm=minute if after hh else month
//         else edit patern "YY/MM/DD hh:mm:ss"(0 suppress if lower shift)
//         mil:milisecond                                          //~v59kI~
//* parm2 :out put area addr(if 0,use static,but must lower than 31 byte)
//* return:same addr as parm2
//*         0 if no outbuff and patern string too long
//******************************************************
void *utimeedit(unsigned char *Ppatern,void *Pout)
{
#ifdef UNX                                                         //~v321R~
    struct    timeb tb;      //time_t and milisec                  //~v321R~
    struct    tm* ptm;       //date and time                       //~v321R~
#else                                                              //~v321R~
#ifdef DOS
    struct dosdate_t date;                                      //~5702R~
    struct dostime_t time;                                      //~5702R~
#else
    #ifdef W32                                                     //~v022I~
        SYSTEMTIME      datetime;   //*hh,mm,ss,th,day,month,year,tz,dayofweek//~v022I~
    #else                                                          //~v022I~
    DATETIME datetime;   //*hh,mm,ss,th,day,month,year,tz,dayofweek
    #endif                                                         //~v022I~
#endif
#endif      //!UNX                                                 //~v321R~
static UCHAR Swk[32];
    UINT  swcase;   //dos need int but not long                 //~5702I~
    UCHAR *pc,*pc0,*pch;
    ULONG *pul;
    ULONG YY,yy,mo,dd,hh,mi,ss,th;                              //~5702R~
    int   milisec;                                                 //~v59kI~
//  UCHAR editwk1[9],editwk2[9];                                   //~v59kR~
    UCHAR editwk1[13],editwk2[13];                                 //~v59kI~
//******************
    if (pc0=Pout,!pc0)  //no out buff                              //~v022R~
        pc0=Swk;
    pul=(ULONG*)(PVOID)pc0;

#ifdef UNX                                                         //~v321R~
    ftime(&tb);                 //time_t and milisec               //~v321R~
    ptm=localtime(&tb.time);    //date and time                    //~v321R~
//  yy=ptm->tm_year;                                               //~v321R~//~v6BkR~
    yy=(ULONG)ptm->tm_year;                                        //~v6BkI~
    yy+=1900;                                                      //~v59hR~
//  mo=ptm->tm_mon;                                                //~v345R~
//  mo=ptm->tm_mon+1;                                              //~v345I~//~v6BkR~
    mo=(ULONG)ptm->tm_mon+1;                                       //~v6BkI~
//  dd=ptm->tm_mday;                                               //~v321R~//~v6BkR~
    dd=(ULONG)ptm->tm_mday;                                        //~v6BkI~
//  hh=ptm->tm_hour;                                               //~v321R~//~v6BkR~
    hh=(ULONG)ptm->tm_hour;                                        //~v6BkI~
//  mi=ptm->tm_min;                                                //~v321R~//~v6BkR~
    mi=(ULONG)ptm->tm_min;                                         //~v6BkI~
//  ss=ptm->tm_sec;                                                //~v321R~//~v6BkR~
    ss=(ULONG)ptm->tm_sec;                                         //~v6BkI~
    th=tb.millitm/10;                                              //~v321R~
    milisec=tb.millitm;                                            //~v59kR~
//  swcase=(ULONG)Ppatern;                                         //~v321I~//~v6BxR~
    swcase=(UINT)(ULPTR)Ppatern;                                   //~v6BxR~
#else                                                              //~v321R~
#ifdef DOS
    _dos_getdate(&date);
    _dos_gettime(&time);
    yy=date.year;                                               //~5702R~
    mo=(int)date.month;
    dd=(int)date.day;
    hh=time.hour;
    mi=time.minute;                                             //~5702R~
    ss=time.second;
    th=time.hsecond;
    milisec=th*10;                                                 //~v59kI~
                                                                //~5702I~
    if ((ULONG)Ppatern<UET_MAXID)                               //~5702R~
        swcase=(UINT)(ULONG)Ppatern;                            //~5702I~
    else                                                        //~5702I~
        swcase=-1;  //default proc                              //~5702I~
#else
    #ifdef W32                                                     //~v022I~
        GetLocalTime(&datetime);                                   //~v022I~
        yy=datetime.wYear;                                         //~v022I~
        mo=datetime.wMonth;                                        //~v022I~
        dd=datetime.wDay;                                          //~v022I~
        hh=datetime.wHour;                                         //~v022I~
        mi=datetime.wMinute;                                       //~v022I~
        ss=datetime.wSecond;                                       //~v022I~
        th=datetime.wMilliseconds/10,                              //~v022I~
    	milisec=datetime.wMilliseconds;                            //~v59kI~
    #else                                                          //~v022I~
    DosGetDateTime(&datetime);
    yy=datetime.year;
    mo=datetime.month;
    dd=datetime.day;
    hh=datetime.hours;
    mi=datetime.minutes;
    ss=datetime.seconds;
    th=datetime.hundredths;
    milisec=(int)th*10;                                            //~v5f4R~
    #endif                                                         //~v022I~
                                                                //~5702I~
//  swcase=(ULONG)Ppatern;                                      //~5702I~//~v6hhR~
    swcase=(UINT)(ULPTR)Ppatern;                                   //~v6hhI~
#endif
#endif  //!UNX                                                     //~v321R~
    YY=yy/100;
    yy=yy%100;

    switch(swcase)                                              //~5702R~
    {
    case UET_ISTRING:                                           //~5702R~
        *(pul++)=YY     | (yy<< 8) | (mo<<16) | (dd<<24);          //~v022R~
        *(pul  )=hh     | (mi<< 8) | (ss<<16) | (th<<24);          //~v022R~
        break;
    case UET_ILONG:                                             //~5702R~
        *(pul++)=(YY<<24) | (yy<<16) | (mo<< 8) | dd;              //~v022R~
        *(pul  )=(hh<<24) | (mi<<16) | (ss<< 8) | th;              //~v022R~
        break;
    case UET_XSTRING:                                           //~5702R~
        *(pul++)=((YY/10)<< 4) | (YY%10)                           //~v022R~
                |((yy/10)<<12) | ((yy%10)<<8)                      //~v022R~
                |((mo/10)<<20) | ((mo%10)<<16)                     //~v022R~
                |((dd/10)<<28) | ((dd%10)<<24);                    //~v022R~
        *(pul  )=((hh/10)<< 4) | (hh%10)                           //~v022R~
                |((mi/10)<<12) | ((mi%10)<<8)                      //~v022R~
                |((ss/10)<<20) | ((ss%10)<<16)                     //~v022R~
                |((th/10)<<28) | ((th%10)<<24);                    //~v022R~
        break;
    case UET_XLONG:                                             //~5702R~
        *(pul++)=((YY/10)<<28) | ((YY%10)<<24)                     //~v022R~
                |((yy/10)<<20) | ((yy%10)<<16)                     //~v022R~
                |((mo/10)<<12) | ((mo%10)<< 8)                     //~v022R~
                |((dd/10)<< 4) | (dd%10)    ;                      //~v022R~
        *(pul  )=((hh/10)<<28) | ((hh%10)<<24)                     //~v022R~
                |((mi/10)<<20) | ((mi%10)<<16)                     //~v022R~
                |((ss/10)<<12) | ((ss%10)<< 8)                     //~v022R~
                |((th/10)<< 4) | (th%10)    ;                      //~v022R~
        break;
    default:        //patern
        if (!Pout)  //no out buff
            if (strlen(Ppatern)>=sizeof(Swk)-1)
                return 0;   //patern err
        strcpy(pc0,Ppatern);                                    //~5702I~
//time**
//      sprintf(editwk1,"%02ld%02ld%02ld%02ld",hh,mi,ss,th);       //~v59kR~
//      sprintf(editwk2,"%2ld%2ld%2ld%2ld",hh,mi,ss,th);           //~v59kR~
        sprintf(editwk1,"%02ld%02ld%02ld%02ld%03d",hh,mi,ss,th,milisec);//~v59kI~
        sprintf(editwk2,"%2ld%2ld%2ld%2ld%3d",hh,mi,ss,th,milisec);//~v59kR~
//hour
        if (pch=strstr(pc0,"HH"),pch)
            memcpy(pch,editwk1,2);
        else
            if (pch=strstr(pc0,"hh"),pch)
                memcpy(pch,editwk2,2);
//minutes(MM after hour)
        if (pch)
        {                                                          //~v59kI~
            if (pc=strstr(pch,"MM"),pc)
                memcpy(pc,editwk1+2,2);
            else
                if (pc=strstr(pch,"mm"),pc)
                    memcpy(pc,editwk2+2,2);
    	}//Hour detected                                           //~v59kI~
//seconds
        if (pc=strstr(pc0,"SS"),pc)
            memcpy(pc,editwk1+4,2);
        else
            if (pc=strstr(pc0,"ss"),pc)
                memcpy(pc,editwk2+4,2);
//hndred seconds
        if (pc=strstr(pc0,"TH"),pc)
            memcpy(pc,editwk1+6,2);
        else
            if (pc=strstr(pc0,"th"),pc)
                memcpy(pc,editwk2+6,2);
        if (pc=strstr(pc0,"MIL"),pc)                               //~v59kI~
            memcpy(pc,editwk1+8,3);                                //~v59kI~
        else                                                       //~v59kI~
            if (pc=strstr(pc0,"mil"),pc)                           //~v59kI~
                memcpy(pc,editwk2+8,3);                            //~v59kI~
//date**
        sprintf(editwk1,"%02ld%02ld%02ld%02ld",YY,yy,mo,dd);    //~5702R~
        sprintf(editwk2,"%2ld%2ld%2ld%2ld",YY,yy,mo,dd);        //~5702R~
//year
        if (pc=strstr(pc0,"YYYY"),pc)
            memcpy(pc,editwk1,4);
        else
            if (pc=strstr(pc0,"yyyy"),pc)
                memcpy(pc,editwk2,4);
            else
                if (pc=strstr(pc0,"YY"),pc)
                    memcpy(pc,editwk1+2,2);
                else
                    if (pc=strstr(pc0,"yy"),pc)
                        memcpy(pc,editwk2+2,2);
//month
        if (pc=strstr(pc0,"MM"),pc)
            memcpy(pc,editwk1+4,2);
        else
            if (pc=strstr(pc0,"mm"),pc)
                memcpy(pc,editwk2+4,2);
//day
        if (pc=strstr(pc0,"DD"),pc)
            memcpy(pc,editwk1+6,2);
        else
            if (pc=strstr(pc0,"dd"),pc)
                memcpy(pc,editwk2+6,2);
    }//switch by patern
    return (void*)pc0;
}//utimeedit
                                                                //~5820I~
//*******************************************************       //~5820I~
//*uitoa10                                                      //~5820I~
//* itoa by radix 10                                            //~5820I~
//* parm1 :int value                                            //~5820I~
//* return:psz(top is "-" if minus value) max 18 for dos max 34 for os2//~5820I~
//******************************************************        //~5820I~
unsigned char *uitoa10(int Pvalue)                              //~5820I~
{                                                               //~5820I~
#ifdef UNX                                                         //~v321R~
    static unsigned char Ssz[34];                                  //~v321R~
#else                                                              //~v321R~
#ifdef DOS                                                      //~5820I~
    #ifdef DPMI                 //DPMI version                     //~v053I~
static unsigned char Ssz[34];                                      //~v053I~
    #else                       //not DPMI                         //~v053I~
static unsigned char Ssz[18];                                   //~5820I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                           //~5820I~
static unsigned char Ssz[34];                                   //~5820I~
#endif                                                          //~5820I~
#endif //!UNX                                                      //~v321R~
//******************                                            //~5820I~
#ifdef UNX                                                         //~v321R~
    return itoa(Pvalue,Ssz,10);                                    //~v321R~
#else                                                              //~v321R~
#ifdef DOS                                                      //~5820I~
    return itoa(Pvalue,Ssz,10);                                 //~5820I~
#else                                                           //~5820I~
    #ifdef W32                                                     //~v022I~
        return itoa(Pvalue,Ssz,10);                                //~v022I~
    #else                                                          //~v022I~
    return _itoa(Pvalue,Ssz,10);                                //~5820I~
    #endif                                                         //~v022I~
#endif                                                          //~5820I~
#endif  //!UNX                                                     //~v321R~
}//uitoa10                                                      //~5820I~
                                                                //~5A14I~
//****************************************************************//~5A14M~
//!ucmdparmedit                                                 //~5A14I~
//*edit cmd line replacing %                                    //~5A14M~
//*simply concatinate if no % exist                             //~5A15I~
//*parm1:option:1:strcat not used parm,0:ignore not used opd       //~v129R~
//*parm2:cmd line patern                                           //~v129I~
//*parm3:cmd parm (quatation dropped if used)                      //~v129R~
//*parm4:cmd parm  v-fmt(quatation used as specified)              //~v129R~
//*parm5:result area pointer(umalloc area)                         //~v129R~
//*ret  :rc                                                     //~5A14M~
//****************************************************************//~5A14M~
int ucmdparmedit(int Popt,char *Pcmd,char *Popd,char **Popdv,char **Presult)//~v129R~
{                                                               //~5A14M~
    UCHAR *pc,*pc2,*pout;                                       //~5A14I~
    int    len,offs,opdno,copno,rlen;                              //~v129R~
    char  *selsw,**parsev;                                         //~v129R~
    char   *parseopd=NULL;                                              //~v129R~//~v5h6R~
    char *pfnm,*pfnm2;                                             //~v6qgR~
    int swremainingused=0;                                         //~v6qgI~
//*******************                                           //~5A14M~
    if (!Popd)                                                     //~v5iuR~
        Popd="";                                                   //~v5iuR~
    if (Popt & CPEO_FNMPARM)    //Presult point filename for %0 as input parm//~v6qgI~
    {                                                              //~v6qgI~
        pfnm=*Presult;                                             //~v6qgI~
        pfnm2=pfnm+strlen(pfnm)+1;                                 //~v6qgI~
    }                                                              //~v6qgI~
    else                                                           //~v6qgI~
        pfnm=pfnm2=0;                                              //~v6qgR~
//  pout=UALLOCM((UINT)(rlen=(int)(strlen(Pcmd)+strlen(Popd)+2))); //~v125I~
    if (Popdv)  //v fmt                                            //~v125I~
    {                                                              //~v125I~
        rlen=0;                                                    //~v125I~
        for (opdno=0;Popdv[opdno];opdno++)                         //~v125I~
            rlen+=(int)strlen(Popdv[opdno]);                       //~v125R~
        parsev=(char**)Popdv;                                      //~v129R~
    }                                                              //~v125I~
    else                                                           //~v125I~
    {                                                              //~v125I~
        rlen=(int)strlen(Popd);                                    //~v125I~
//      if (rc=uparsev(Popd,&parsev,&opdno,0,","),rc)   //parse out string(accept cr/lf)//~v129R~
//          return rc;                                             //~v129R~
        parseopd=0;     //request umalloc for out area             //~v129I~
        UPARSECMDRC(UPCMD_ASIS,Popd,&opdno,&parseopd,&parsev,0);//no drop ",no delmt//~v129R~
    }                                                              //~v125I~
//  rlen+=(int)strlen(Pcmd)+2+80;//80 is for dup parm(%2 %2 etc)   //~v125I~//~v6qgR~
    rlen+=(int)strlen(Pcmd)+2+rlen*2+_MAX_PATH;//rlen*2 is for dup parm(%2 %2 etc),_MAX_PATH for %0//~v6qgI~
    len=rlen+opdno;                                                //~v125I~
    pout=UALLOCM((UINT)len);                                       //~v125I~
    UALLOCCHK(pout,UALLOC_FAILED);                              //~5A14I~
    selsw=pout+rlen;            //selected sw                      //~v125I~
    memset(selsw,0,(UINT)opdno);                                   //~v125I~
                                                                   //~v125I~
    pc=Pcmd;                                                    //~5A15M~
//    if (!strchr(pc,'%'))    //no %                               //~v125R~
//    {                                                            //~v125R~
//        strcpy(pout,pc);                                         //~v125R~
//        strcat(pout," ");                                        //~v125R~
//        strcat(pout,Popd);                                       //~v125R~
//        *Presult=pout;                                           //~v125R~
//        return 0;                                                //~v125R~
//    }                                                            //~v125R~
//  UPARSERC(Popd,Popd,&opdno,0,",");   //parse out string(accept cr/lf)//~v125R~
    pc+=strspn(pc," "); //search first no space                 //~5A14M~
    rlen--;             //for last 0                            //~5A14I~
    offs=0;                                                     //~5A14M~
    for (;rlen;)                                                //~5A14M~
    {                                                           //~5A14M~
        if ((pc2=strchr(pc,'%'),!pc2)                              //~v022R~
//      ||  (len=(int)((ULONG)pc2-(ULONG)pc))>=rlen)            //~5A14M~//~v6hhR~
        ||  (len=(int)((ULPTR)pc2-(ULPTR)pc))>=rlen)               //~v6hhI~
        {                                                       //~5A14M~
            len=(int)strlen(pc);                                //~5A14M~
            len=min(rlen,len);                                  //~5A14M~
            memcpy(pout+offs,pc,(UINT)len);                     //~5A14I~
            offs+=len;                                          //~5A14M~
            rlen-=len;                                             //~v125I~
            break;                                              //~5A14M~
        }                                                       //~5A14M~
        memcpy(pout+offs,pc,(UINT)len);                         //~5A14I~
        rlen-=len;                                              //~5A14M~
        offs+=len;                                              //~5A14M~
        pc=pc2+1;                                               //~5A14M~
      if (*pc==CMDPARM_CURFNM && pfnm)    //Presult point filename for %* as input parm//~v6qgR~
      {                                                            //~v6qgM~
        pc++;                                                      //~v6qgI~
        pc2=pfnm;                                                  //~v6qgM~
      }                                                            //~v6qgM~
      else                                                         //~v6qgM~
      if (*pc==CMDPARM_SPLITFNM && pfnm2)    //Presult point 2nd filename for %^ as input parm//~v6qgR~
      {                                                            //~v6qgI~
        pc++;                                                      //~v6qgI~
        pc2=pfnm2;                                                 //~v6qgI~
      }                                                            //~v6qgI~
      else                                                         //~v6qgI~
      if (*pc==CMDPARM_REMAINING)	//all remaining parm           //~v6qgI~
      {                                                            //~v6qgI~
    	swremainingused=1;                                         //~v6qgI~
        pc++;                                                      //~v6qgI~
        for (copno=0;copno<opdno;copno++)                          //~v6qgI~
            if (!selsw[copno])  //not set                          //~v6qgI~
            {                                                      //~v6qgI~
                pc2=parsev[copno];                                 //~v6qgI~
                len=(int)strlen(pc2);                              //~v6qgI~
                if (rlen<=len)                                     //~v6qgI~
                    break;                                         //~v6qgI~
                *(pout+offs)=' ';                                  //~v6qgI~
                memcpy(pout+offs+1,pc2,(UINT)len);                 //~v6qgI~
                len++;                                             //~v6qgI~
                offs+=len;                                         //~v6qgI~
                rlen-=len;                                         //~v6qgI~
            }//not used                                            //~v6qgI~
        continue;                                                  //~v6qgI~
      }                                                            //~v6qgI~
      else                                                         //~v6qgI~
      {                                                            //~v6qgM~
        if (*pc=='%'                                            //~5A14M~
        ||  *pc<'0'                                             //~5A14M~
        ||  *pc>'9')                                            //~5A14M~
        {                                                       //~5A14M~
            if (*pc=='%')                                       //~5A14M~
                pc++;                                           //~5A14M~
            *(pout+offs++)='%';                                 //~5A14I~
            rlen--;                                             //~5A14M~
            continue;                                           //~5A14M~
        }                                                       //~5A14M~
        copno=*pc-'1';                                          //~5A14M~
        pc++;                                                   //~5A14M~
        if (copno<0 || copno >=opdno)                           //~5A14M~
            continue;                                           //~5A14M~
//        for (ii=0,pc2=Popd;ii<copno;ii++)                        //~v125R~
//            pc2+=((int)strlen(pc2)+1);                           //~v125R~
        pc2=parsev[copno];                                         //~v125I~
        selsw[copno]=1;         //once used                        //~v125I~
      }                                                            //~v6qgI~
        len=(int)strlen(pc2);                                   //~5A14M~
        len=min(len,rlen);                                      //~5A14M~
        memcpy(pout+offs,pc2,(UINT)len);                        //~5A14I~
        rlen-=len;                                              //~5A14M~
        offs+=len;                                              //~5A14M~
    }//%serach                                                  //~5A14M~
//if (Popt)             //padd not used opd                        //~v129I~//~v6qgR~
  if (Popt & CPEO_APPEND)             //padd not used opd          //~v6qgI~
   if (!swremainingused)                                           //~v6qgI~
    for (copno=0;copno<opdno;copno++)                              //~v125I~
        if (!selsw[copno])  //not set                              //~v125I~
        {                                                          //~v125I~
            pc2=parsev[copno];                                     //~v125I~
            len=(int)strlen(pc2);                                  //~v125R~
            if (rlen<=len)                                         //~v125R~
                break;                                             //~v125I~
            *(pout+offs)=' ';                                      //~v125R~
            memcpy(pout+offs+1,pc2,(UINT)len);                     //~v125R~
            len++;                                                 //~v125I~
            offs+=len;                                             //~v125I~
            rlen-=len;                                             //~v125I~
        }//not used                                                //~v125I~
    if (!Popdv) //not v fmt                                        //~v126I~
//      ufree(parsev);                                             //~v129R~
        ufree(parseopd);                                           //~v129I~
    *(pout+offs)=0;                                             //~5A14I~
    *Presult=pout;                                              //~5A14I~
    return 0;                                                   //~5A14M~
}//ucmdparmedit                                                 //~5A14I~
                                                                   //~v066I~
//**************************************************************** //~v5f4I~
//!ueditenv                                                        //~v5f4I~
// replace $abc,${abc},%abc% by env variable for xe set cmd        //~v5f4I~
// $ or % is escaped by $$,%%                                      //~v5f4I~
//*parm1:input string                                              //~v5f4I~
//*parm2:output buff,if 0 return length                            //~v5f4I~
//*ret  :output length,or -1 if fmt err                            //~v5f4I~
//**************************************************************** //~v5f4I~
int ueditenv(int Popt,char *Pinp,char *Pout)                       //~v5f4R~
{                                                                  //~v5f4I~
#define MAXVARNAME  32                                             //~v5f4I~
#ifdef UNX                                                         //~v5f4I~
	char envid='$';                                                //~v5f4R~
#else                                                              //~v5f4I~
	char envid='%';                                                //~v5f4I~
#endif                                                             //~v5f4I~
    UCHAR *pc,*pc2,*pc3,*pout,varname[MAXVARNAME+1];               //~v5f4R~
    int   tlen=0,rlen,len,ch;                                      //~v5f4R~
//*******************                                              //~v5f4I~
#ifdef UNX                                                         //~v5f4I~
	if (Popt & UEE_PCTYPE)                                         //~v5f4I~
    	envid='%';                                                 //~v5f4I~
#else                                                              //~v5f4I~
	if (Popt & UEE_UNIXTYPE)                                       //~v5f4I~
    	envid='$';                                                 //~v5f4I~
#endif                                                             //~v5f4I~
    rlen=(int)strlen(Pinp);                                        //~v5f4I~
    pc=Pinp;                                                       //~v5f4I~
    pout=Pout;                                                     //~v5f4I~
    for (;rlen;)                                                   //~v5f4I~
    {                                                              //~v5f4I~
        if (pc2=strchr(pc,envid),pc2)                              //~v5f4I~
//        	len=(int)((ULONG)pc2-(ULONG)pc);                       //~v5f4I~//~v6hhR~
        	len=(int)((ULPTR)pc2-(ULPTR)pc);                       //~v6hhI~
        else                                                       //~v5f4I~
            len=rlen;                                              //~v5f4I~
        if (pout)	//output requested                             //~v5f4I~
        {                                                          //~v5f4I~
            memcpy(pout,pc,(UINT)len);                             //~v5f4I~
	        pout+=len;                                             //~v5f4I~
        }                                                          //~v5f4I~
        tlen+=len;                                                 //~v5f4I~
        rlen-=len; pc+=len;                                        //~v5f4I~
        if (!pc2)                                                  //~v5f4I~
        	break;                                                 //~v5f4I~
        pc++;  rlen--;                                             //~v5f4I~
        if (*pc==envid)	//dup                                      //~v5f4R~
        {                                                          //~v5f4I~
        	if (pout)                                              //~v5f4I~
        		*pout++=envid;                                     //~v5f4R~
            tlen++;                                                //~v5f4I~
            rlen--; pc++;                                          //~v5f4I~
            continue;                                              //~v5f4I~
        }                                                          //~v5f4I~
		if (envid=='$')                                            //~v5f4R~
        {                                                          //~v5f4I~
            if (*pc=='{')	//${abc}                               //~v5f4R~
            {                                                      //~v5f4R~
                pc++;                                              //~v5f4R~
                pc2=strchr(pc,'}');                                //~v5f4R~
                if (!pc2)                                          //~v5f4R~
                    return -1;                                     //~v5f4R~
//              len=(int)((ULONG)pc2-(ULONG)pc);                   //~v5f4R~//~v6hhR~
                len=(int)((ULPTR)pc2-(ULPTR)pc);                   //~v6hhI~
                pc3=pc;                                            //~v5f4I~
	        	rlen-=len+1; pc+=len+1;                            //~v5f4I~
            }                                                      //~v5f4R~
            else            //$abc                                 //~v5f4R~
            {                                                      //~v5f4R~
                for (len=0,pc2=pc;len<rlen;pc2++,len++)            //~v5f4R~
                {                                                  //~v5f4R~
                    ch=*pc2;                                       //~v5f4R~
                    if (isalpha(ch)                                //~v5f4R~
                    ||   ch=='_'                                   //~v5f4R~
                    ||   ch=='#')                                  //~v5f4R~
                        continue;                                  //~v5f4R~
                    break;                                         //~v5f4R~
                }                                                  //~v5f4R~
                pc3=pc;                                            //~v5f4I~
	        	rlen-=len; pc+=len;                                //~v5f4I~
            }                                                      //~v5f4R~
        }                                                          //~v5f4I~
		else                                                       //~v5f4R~
        {                                                          //~v5f4I~
            pc2=strchr(pc,envid);                                  //~v5f4R~
            if (!pc2)                                              //~v5f4R~
                return -1;                                         //~v5f4R~
//          len=(int)((ULONG)pc2-(ULONG)pc);                       //~v5f4R~//~v6hhR~
            len=(int)((ULPTR)pc2-(ULPTR)pc);                       //~v6hhI~
            pc3=pc;                                                //~v5f4I~
	        rlen-=len+1; pc+=len+1;                                //~v5f4I~
        }                                                          //~v5f4I~
		if (len>MAXVARNAME)                                        //~v5f4I~
        	return -1;                                             //~v5f4I~
        memcpy(varname,pc3,(UINT)len);                             //~v5f4R~
        *(varname+len)=0;                                          //~v5f4I~
        pc2=getenv(varname);                                       //~v5f4I~
        if (pc2)                                                   //~v5f4I~
        	len=(int)strlen(pc2);                                  //~v5f4R~
        else                                                       //~v5f4I~
        	len=0;                                                 //~v5f4I~
        if (pout)                                                  //~v5f4I~
        {                                                          //~v5f4I~
        	memcpy(pout,pc2,(UINT)len);                            //~v5f4I~
            pout+=len;                                             //~v5f4I~
        }                                                          //~v5f4I~
        tlen+=len;                                                 //~v5f4I~
    }//%serach                                                     //~v5f4I~
    if (pout)                                                      //~v5f4I~
	    *pout++=0;                                                 //~v5f4I~
    return tlen;                                                   //~v5f4I~
}//ueditenv                                                        //~v5f4I~
//**********************************************************************//~v066I~
//*uwordrep                                                        //~v066I~
//*replace keyword(%...%) on string,                               //~v066I~
//         first %% is ignored,"% " or "%," is ignore              //~v066I~
//*p1:case option,0x01:ignore case                                 //~v066I~
//                0x02:rep by null if unmatch                      //~v066I~
//                0x04:rep by null if data is NULL ptr             //~v066I~
//*p2:source string containing keyword                             //~v066I~
//*p3:keyword table,last must be NULL ptr or ""                    //~v066I~
//*p4:replace data table corresponding to keyword                  //~v066I~
//*   to replcae null specify "",to leave specify NULL             //~v066I~
//*p5:replace count out area(optional)                             //~v066I~
//*p6:not replaced %data ctr out area(optional)                    //~v066I~
//*rc:replaced string,free when no more needed,NULL if malloc failed//~v066I~
//**********************************************************************//~v066I~
#define WORDREP_IC              0x01    //ignore case              //~v066I~
#define WORDREP_UNMATCHNULL     0x02    //rep by null if unmatch kwd(%...%)//~v066I~
#define WORDREP_NODATANULL      0x04    //rep by null if no data ptr//~v066I~
char *uwordrep(int Popt,char *Pinp,char **Pkwd,char **Pdata,int *Prepctr,int *Pnorepctr)//~v066I~
{                                                                  //~v066I~
    int rc,ii,tlen,len,kwdno,kwdlen,datalen;                       //~v066I~
    char *pc,*pcs,*pcso,*pcd,*kwd,*data,*pout;                     //~v066I~
    char ch;                                                       //~v066I~
    int repctr=0,norepctr=0;                                       //~v066I~
//************                                                     //~v066I~
    if (Prepctr)                                                   //~v066I~
        *Prepctr=0;                                                //~v066I~
    if (Pnorepctr)                                                 //~v066I~
        *Pnorepctr=0;                                              //~v066I~
//count kwd                                                        //~v066I~
    for (ii=0;kwd=Pkwd[ii],kwd;)                                   //~v066I~
        ii++;                                                      //~v066I~
    if (kwdno=ii,!kwdno)                                           //~v066I~
        return 0;                                                  //~v066I~
//count result len                                                 //~v066I~
    pcs=Pinp;   //src                                              //~v066I~
    tlen=0;                                                        //~v066I~
    for (;;)                                                       //~v066I~
    {                                                              //~v066I~
        if (!(pc=strchr(pcs,'%')))                                 //~v066I~
            break;                                                 //~v066I~
        ch=*(pc+1);                                                //~v066I~
        if (ch=='%')    //ignore %%                                //~v066I~
        {                                                          //~v066I~
            pcs=pc+2;                                              //~v066I~
            continue;                                              //~v066I~
        }                                                          //~v066I~
        if (ch==' '||ch==',')                                      //~v066I~
        {                                                          //~v066I~
            pcs=pc+1;                                              //~v066I~
            continue;                                              //~v066I~
        }                                                          //~v066I~
        rc=4;kwdlen=0;//unmatch when kwdno=0                       //~v328I~
        for (ii=0;ii<kwdno;ii++)                                   //~v066I~
        {                                                          //~v066I~
            kwd=Pkwd[ii];                                          //~v066I~
            kwdlen=(int)strlen(kwd);                               //~v066I~
            if (Popt&WORDREP_IC)        //ignore case              //~v066I~
                rc=memicmp(pc,kwd,(UINT)kwdlen);                   //~v066I~
            else                                                   //~v066I~
                rc=memcmp(pc,kwd,(UINT)kwdlen);                    //~v066I~
            if (!rc)        //match                                //~v066I~
                break;                                             //~v066I~
        }//all kwd                                                 //~v066I~
        if (!rc)        //match                                    //~v066I~
        {                                                          //~v066I~
            pcs=pc+kwdlen;  //next search                          //~v066I~
            data=Pdata[ii];                                        //~v066I~
            if (data)                                              //~v066I~
                tlen+=(int)strlen(data)-kwdlen;                    //~v066I~
            else    //null ptr                                     //~v066I~
                if (Popt & WORDREP_NODATANULL)      //null rep     //~v066I~
                    tlen-=kwdlen;                                  //~v066I~
        }                                                          //~v066I~
        else    //unmatch kwd                                      //~v066I~
        {                                                          //~v066I~
            pcs=pc+1;                                              //~v066I~
            if (pc=strchr(pcs,'%'),pc)                             //~v066I~
            {                                                      //~v066I~
//              len=(int)((ULONG)pc-(ULONG)pcs)+1;                 //~v066I~//~v6hhR~
                len=(int)((ULPTR)pc-(ULPTR)pcs)+1;                 //~v6hhI~
                if (Popt & WORDREP_UNMATCHNULL)     //null rep     //~v066I~
                    tlen-=len;                                     //~v066I~
            }                                                      //~v066I~
            else                                                   //~v066I~
                len=(int)strlen(pcs);                              //~v066I~
            pcs+=len;                                              //~v066I~
        }//unmatc                                                  //~v066I~
    }//through source string                                       //~v066I~
    tlen+=(int)strlen(Pinp);                                       //~v066I~
//printf("tlen=%d\n",tlen);                                        //~v066R~
    pout=umalloc((UINT)(tlen+1));                                  //~v066I~
    if (!pout)                                                     //~v066I~
        return 0;                                                  //~v066I~
//repl word                                                        //~v066I~
    pcso=pcs=Pinp;  //src                                          //~v066I~
    pcd=pout;     //dest                                           //~v066I~
    for (;;)                                                       //~v066I~
    {                                                              //~v066I~
        if (pc=strchr(pcs,'%'),pc)                                 //~v066I~
        {                                                          //~v066I~
            ch=*(pc+1);                                            //~v066I~
            if (ch=='%')    //ignore %%                            //~v066I~
            {                                                      //~v066I~
                pcs=pc+2;                                          //~v066I~
                continue;                                          //~v066I~
            }                                                      //~v066I~
            if (ch==' '||ch==',')                                  //~v066I~
            {                                                      //~v066I~
                pcs=pc+1;                                          //~v066I~
                continue;                                          //~v066I~
            }                                                      //~v066I~
//          len=(int)((ULONG)pc-(ULONG)pcso);                      //~v066I~//~v6hhR~
            len=(int)((ULPTR)pc-(ULPTR)pcso);                      //~v6hhI~
        }                                                          //~v066I~
        else                                                       //~v066I~
            len=(int)strlen(pcso);                                 //~v066I~
        memcpy(pcd,pcso,(UINT)len);                                //~v066I~
        pcs=pcso=pcso+len;                                         //~v066I~
        pcd+=len;     //next set                                   //~v066I~
        if (!pc)                                                   //~v066I~
        {                                                          //~v066I~
            *pcd=0;                                                //~v066I~
            break;                                                 //~v066I~
        }                                                          //~v066I~
        rc=4;kwdlen=0;//unmatch when kwdno=0                       //~v328I~
        for (ii=0;ii<kwdno;ii++)                                   //~v066I~
        {                                                          //~v066I~
            kwd=Pkwd[ii];                                          //~v066I~
            kwdlen=(int)strlen(kwd);                               //~v066I~
            if (Popt&WORDREP_IC)        //ignore case              //~v066I~
                rc=memicmp(pc,kwd,(UINT)kwdlen);                   //~v066I~
            else                                                   //~v066I~
                rc=memcmp(pc,kwd,(UINT)kwdlen);                    //~v066I~
            if (!rc)        //match                                //~v066I~
                break;                                             //~v066I~
        }//all kwd                                                 //~v066I~
        if (!rc)        //match                                    //~v066I~
        {                                                          //~v066I~
            pcs=pc+kwdlen;     //next search start                 //~v066I~
            data=Pdata[ii];                                        //~v066I~
            if (data)                                              //~v066I~
            {                                                      //~v066I~
                datalen=(int)strlen(data);                         //~v066I~
                memcpy(pcd,data,(UINT)datalen);                    //~v066I~
                pcd+=datalen;                                      //~v066I~
                pcso=pcs;                                          //~v066I~
                repctr++;                                          //~v066I~
            }                                                      //~v066I~
            else                                                   //~v066I~
                if (Popt & WORDREP_NODATANULL)      //null rep     //~v066I~
                {                                                  //~v066I~
                    pcso=pcs;                                      //~v066I~
                    repctr++;                                      //~v066I~
                }                                                  //~v066I~
                else                                               //~v066I~
                    norepctr++;                                    //~v066I~
        }                                                          //~v066I~
        else    //unmatch                                          //~v066I~
        {                                                          //~v066I~
            pcs=pc+1;                                              //~v066I~
            if (pc=strchr(pcs,'%'),pc)                             //~v066I~
            {                                                      //~v066I~
//              len=(int)((ULONG)pc-(ULONG)pcs)+1;                 //~v066I~//~v6hhR~
                len=(int)((ULPTR)pc-(ULPTR)pcs)+1;                 //~v6hhI~
                if (Popt & WORDREP_UNMATCHNULL)     //null rep     //~v066I~
                {                                                  //~v066I~
                    pcso=pcs+len;   //skip source                  //~v066I~
                    repctr++;                                      //~v066I~
                }                                                  //~v066I~
                else                                               //~v066I~
                    norepctr++;                                    //~v066I~
            }                                                      //~v066I~
            else    //no ending %                                  //~v066I~
            {                                                      //~v066I~
                len=(int)strlen(pcs);                              //~v066I~
                norepctr++;                                        //~v066I~
            }                                                      //~v066I~
            pcs+=len;                                              //~v066I~
        }//unmatch                                                 //~v066I~
    }//through source string                                       //~v066I~
    if (Prepctr)                                                   //~v066I~
        *Prepctr=repctr;                                           //~v066I~
    if (Pnorepctr)                                                 //~v066I~
        *Pnorepctr=norepctr;                                       //~v066I~
    return pout;                                                   //~v066I~
}//uwordrep                                                        //~v066I~
                                                                   //~v025I~
//******************************************************************//~v025R~
//* convert hex digit to binary data until null or specified length//~v025R~
//* parm1 :input hex notation string(must be even number)          //~v025R~
//* parm2 :output hex value string                                 //~v025I~
//* parm3 :input max length to be checked                          //~v025R~
//* return:data len,-1 if err                                      //~v025I~
//******************************************************************//~v025I~
int ugethex(char *Phex,char *Pbin,int Plen)                        //~v025I~
{                                                                  //~v025I~
    int i;                                                         //~v025I~
    char *in;                                                      //~v025I~
    char *out;                                                     //~v025I~
    int  c,co=0;            //v7.0r                                //~v025I~
//********************                                             //~v025I~
    in=Phex;                                                       //~v025I~
    out=Pbin;                                                      //~v025I~
//  for (i=0;*in && i<Plen;in++,i++)                               //~v5fkR~
    for (i=0;i<Plen && *in;in++,i++)                               //~v5fkI~
    {                                                              //~v025I~
        c=toupper(*in);                                            //~v025I~
        if (!isxdigit(c))                                          //~v025I~
            return -1;                                             //~v025I~
        if (c>='A')                                                //~v025I~
            c-='A'-10;                                             //~v025I~
        else                                                       //~v025I~
            c-='0';                                                //~v025I~
        if (i%2)                                                   //~v025I~
            *out++=(unsigned char)((co<<4)+c);                     //~v025I~
        else                                                       //~v025I~
            co=c;                                                  //~v025I~
    }                                                              //~v025I~
    if (i%2)                                                       //~v025I~
        return -1;                                                 //~v066R~
    return i/2;                                                    //~v025I~
}//ugethex                                                         //~v025I~
                                                                   //~v57WI~
//******************************************************************//~v57WI~
//* convert hex digit to binary data until null or specified length//~v57WI~
//*         and return checked valid input hex data length         //~v57WI~
//* parm1 :option to skip space/tab                                //~v57WI~
//* parm2 :input hex notation string                               //~v57WI~
//* parm3 :output addr                                             //~v57WI~
//* parm4 :input len(0 for strz)                                   //~v57WI~
//* parm5 :output:valid input len                                  //~v57WI~
//* return:output data len,minus if stop by oddnumber hex digit    //~v57WI~
//******************************************************************//~v57WI~
int ugethexdump(int Popt,char *Phex,char *Pbin,int Plen,int *Pchklen)//~v57WI~
{                                                                  //~v57WI~
    int i,spacesw,halfsw=0,outlen,len;                             //~v57WR~
    char *in;                                                      //~v57WI~
    char *out;                                                     //~v57WI~
    int  c,co=0;            //v7.0r                                //~v57WI~
//********************                                             //~v57WI~
	spacesw=Popt & UGHD_SPACESKIP;                                 //~v57WI~
    in=Phex;                                                       //~v57WI~
    out=Pbin;                                                      //~v57WI~
    if (!(len=Plen))                                               //~v57WI~
    	len=(int)strlen(Phex);                                     //~v5f4R~
    for (i=0;i<len;in++,i++)                                       //~v57WR~
    {                                                              //~v57WI~
        c=toupper(*in);                                            //~v57WI~
        if (c==' ' || c=='\t')                                     //~v57WI~
        {                                                          //~v59kI~
        	if (spacesw)                                           //~v57WI~
            {                                                      //~v57WI~
            	if (halfsw)                                        //~v57WI~
                	break;                                         //~v57WI~
            	continue;                                          //~v57WI~
            }                                                      //~v57WI~
            else                                                   //~v57WI~
            	break;                                             //~v57WI~
        }                                                          //~v59kI~
        if (c>='A' && c<='F')                                      //~v57WI~
            c-='A'-10;                                             //~v57WI~
        else                                                       //~v57WI~
        if (c>='0' && c<='9')                                      //~v57WI~
            c-='0';                                                //~v57WI~
        else                                                       //~v57WI~
        	break;                                                 //~v57WI~
        if (halfsw)                                                //~v57WI~
        {                                                          //~v57WI~
        	halfsw=0;                                              //~v57WI~
            *out++=(unsigned char)((co<<4)+c);                     //~v57WI~
        }                                                          //~v57WI~
        else                                                       //~v57WI~
        {                                                          //~v57WI~
        	halfsw=1;                                              //~v57WI~
            co=c;                                                  //~v57WI~
        }                                                          //~v57WI~
    }                                                              //~v57WI~
	*Pchklen=i;                                                    //~v57WI~
//  outlen=(int)((ULONG)out-(ULONG)Pbin);                          //~v5f4R~//~v6hhR~
    outlen=(int)((ULPTR)out-(ULPTR)Pbin);                          //~v6hhI~
    if (halfsw)                                                    //~v57WI~
    	outlen=-outlen;                                            //~v57WI~
    return outlen;                                                 //~v57WI~
}//ugethex                                                         //~v57WI~
                                                                   //~v025I~
//******************************************************************//~v6x0I~
int ux2FILESZ(char *Phex,FILESZT *Ppulong)                         //~v6x0I~
{                                                                  //~v6x0I~
#ifdef LFSSUPP                                                     //~v6x0I~
	return ux2ll(Phex,Ppulong);                                    //~v6x0R~
#else                                                              //~v6x0I~
    ULONG ul;                                                      //~v6x0I~
    int rc;                                                        //~v6x0I~
	rc=ux2l(Phex,&ul);                                             //~v6x0R~
    *Ppulong=(FILESZT)ul;                                          //~v6x0I~
	return rc;                                                     //~v6x0I~
#endif                                                             //~v6x0I~
}                                                                  //~v6x0I~
//******************************************************************//~v025I~
//* convert hex digit to binary long                               //~v025I~
//* parm1 :input hex notation string(chk up to 8 byte,odd number ok)//~v025I~
//* parm2 :output ulong addr                                       //~v025I~
//* return:0:ok,4 hex value err                                    //~v025I~
//******************************************************************//~v025I~
int ux2l(char *Phex,ULONG *Ppulong)                                //~v025R~
{                                                                  //~v025I~
    int  len,ii;                                                   //~v025I~
    char wk4[4];                                                   //~v025I~
    char wk10[10];                                                 //~v025I~
    char *pc;                                                      //~v025I~
//********************                                             //~v025I~
    strncpy(wk10+1,Phex,8);                                        //~v025I~
    wk10[9]=0;                                                     //~v025I~
    len=(int)strlen(wk10+1);                                       //~v025R~
    if (len%2)  //odd number                                       //~v025I~
    {                                                              //~v025I~
        pc=wk10;                                                   //~v025I~
        *pc='0';                                                   //~v025I~
    }                                                              //~v025I~
    else                                                           //~v025I~
        pc=wk10+1;                                                 //~v025I~
    if ((len=ugethex(pc,wk4,8))<0)                                 //~v025I~
        return 4;                                                  //~v025I~
    memset(wk10,0,4);                                              //~v025I~
    for (ii=0;ii<len;ii++)                                         //~v025I~
#ifdef BIGENDIAN                                                   //~v40mI~
        wk10[3-ii]=wk4[len-ii-1];                                  //~v40mI~
#else                                                              //~v40mI~
        wk10[ii]=wk4[len-ii-1];                                    //~v025R~
#endif                                                             //~v40mI~
//  *Ppulong=*(ULONG*)(void *)wk10;                                //~v025R~//~v6q3R~
    *Ppulong=USTR2UL(wk10);                                        //~v6q3I~
    return 0;                                                      //~v025I~
}//ux2l                                                            //~v025I~
#ifdef INT64SUPP                                                   //~v5k2I~
//******************************************************************//~v5k2I~
//* convert hex digit to binary long long                          //~v5k2I~
//* return:0:ok,4:no hex value                                     //~v5k2I~
//******************************************************************//~v5k2I~
int ux2ll(char *Phex,INT64 *Ppll)                                  //~v5k2I~
{                                                                  //~v5k2I~
    char *pc;                                                      //~v5k2I~
    int ch;                                                        //~v5k2I~
//********************                                             //~v5k2I~
	for (pc=Phex;*pc;pc++)                                         //~v5k2I~
    	if (*pc!=' ')                                              //~v5k2I~
        	break;                                                 //~v5k2I~
    ch=toupper(*pc);                                               //~v5k2I~
    if (!ch)                                                       //~v6x1I~
    {                                                              //~v6x1I~
        *Ppll=0;                                                   //~v6x1I~
        return 0;                                                  //~v6x1I~
    }                                                              //~v6x1I~
    if ((ch>='0' && ch<='9') || (ch>='A' && ch<='F'))              //~v5k2I~
    {                                                              //~v5k2I~
		sscanf(Phex,"%" FILESZ_EDIT "x",Ppll);                     //~v5k2R~
    	return 0;                                                  //~v5k2I~
    }                                                              //~v5k2I~
    return 4;                                                      //~v5k2I~
}//ux2ll                                                           //~v5k2I~
//******************************************************************//~v5k2I~
//* convert hex digit to binary long long                          //~v5k2I~
//* return:0:ok,4:no hex value                                     //~v5k2I~
//******************************************************************//~v5k2I~
INT64 ua2ll(char *Pdec)                                            //~v5k2I~
{                                                                  //~v5k2I~
//********************                                             //~v5k2I~
#ifdef LNX                                                         //~v5k2I~
	return atoll(Pdec);                                            //~v5k2I~
#endif                                                             //~v5k2I~
#ifdef W32                                                         //~v5k2I~
	return _atoi64(Pdec);                                          //~v5k2I~
#endif                                                             //~v5k2I~
}//ua2ll                                                           //~v6x0R~
#endif                                                             //~v5k2I~
//******************************************************************//~v025I~
//* convert hex digit to binary short                              //~v025I~
//* parm1 :input hex notation string(chk up to 4 byte,odd number digit ok)//~v025I~
//* parm2 :output ulong addr                                       //~v025I~
//* return:0:ok,4 hex value err                                    //~v025I~
//******************************************************************//~v025I~
int ux2s(char *Phex,USHORT *Ppuint)                                //~v025R~
{                                                                  //~v025I~
    int  len,ii;                                                   //~v025I~
    char wk2[2];                                                   //~v025R~
    char wk6[6];                                                   //~v025I~
    char *pc;                                                      //~v025I~
//********************                                             //~v025I~
    strncpy(wk6+1,Phex,4);                                         //~v025R~
    wk6[5]=0;                                                      //~v025I~
    len=(int)strlen(wk6+1);                                        //~v025R~
    if (len%2)  //odd number                                       //~v025I~
    {                                                              //~v025I~
        pc=wk6;                                                    //~v025I~
        *pc='0';                                                   //~v025I~
    }                                                              //~v025I~
    else                                                           //~v025I~
        pc=wk6+1;                                                  //~v025I~
    if ((len=ugethex(pc,wk2,4))<0)                                 //~v025I~
        return 4;                                                  //~v025I~
    memset(wk6,0,4);                                               //~v025I~
    for (ii=0;ii<len;ii++)                                         //~v025I~
#ifdef BIGENDIAN                                                   //~v40mI~
        wk6[1-ii]=wk2[len-ii-1];                                   //~v40mI~
#else                                                              //~v40mI~
        wk6[ii]=wk2[len-ii-1];                                     //~v025I~
#endif                                                             //~v40mI~
//  *Ppuint=*(USHORT*)(PVOID)wk6;                                  //~v025R~//~v6q3R~
    *Ppuint=USTR2US(wk6);                                          //~v6q3I~
    return 0;                                                      //~v025I~
}//ux2s                                                            //~v025I~
                                                                   //~v025I~
//*******************************************************          //~v5fxI~
//*ugetnumrange3                                                   //~v5fxI~
//* get start/end value from nnn-mmm format (nnn<mmm)              //~v5fxI~
//* err when num=0,num1>num2 and return num end addr               //~v5fxI~
//* parm1 :string                                                  //~v5fxI~
//* parm2 :start                                                   //~v5fxI~
//* parm3 :end                                                     //~v5fxI~
//* parm3 :stopped addr                                            //~v5fxI~
//* return:0, 1(delmctr=1) 2(end<start) or 4                       //~v5fxI~
//******************************************************           //~v5fxI~
int ugetnumrange3(char *Pstr,int *Pstart,int *Pend,char **Ppcend)  //~v5fxI~
{                                                                  //~v5fxI~
	int delmctr,value[2],rc;                                       //~v5fxI~
    char *pc0,*pc;                                                 //~v5fxI~
//******************                                               //~v5fxI~
	pc0=pc=Pstr;                                                   //~v5fxI~
	for (delmctr=0;;pc++)                                          //~v5fxI~
    {                                                              //~v5fxI~
	    if (*pc<'0'||*pc>'9')                                      //~v5fxI~
        {                                                          //~v5fxI~
            if (!(value[delmctr]=atoi(pc0)))	//0 is err         //~v5fxI~
            	return 4;                                          //~v5fxI~
            delmctr++;                                             //~v5fxI~
            if (!*pc)                                              //~v5fxI~
                break;                                             //~v5fxI~
        	if (delmctr==2)	//1st delm                             //~v5fxI~
                break;                                             //~v5fxI~
            if (*pc!='-')    //must be "-"                         //~v5fxI~
                break;                                             //~v5fxI~
            pc0=pc+1;                                              //~v5fxI~
		}                                                          //~v5fxI~
    }                                                              //~v5fxI~
                                                                   //~v5fxI~
    *Ppcend=pc;		//next parm addr                               //~v5fxI~
    *Pstart=value[0];                                              //~v5fxI~
    if (delmctr==1)                                                //~v5fxI~
    {                                                              //~v5fxI~
	    *Pend=value[0];                                            //~v5fxI~
        rc=1;                                                      //~v5fxI~
    }                                                              //~v5fxI~
    else                                                           //~v5fxI~
    {                                                              //~v5fxI~
    	*Pend=value[1];                                            //~v5fxI~
    	if (value[0]>value[1])                                     //~v5fxI~
    		return 2;                                              //~v5fxI~
        rc=0;                                                      //~v5fxI~
    }                                                              //~v5fxI~
    return rc;                                                     //~v5fxI~
}//ugetnumrange3                                                   //~v5fxI~
//*******************************************************          //~v5a3I~
//*ugetnumrange2                                                   //~v5a3I~
//* get start/end value from (x)nnn(L)-(x)mmm(L) format            //~v5a3I~
//* (support postfix for number to set minus value                 //~v5a3I~
//* return:delm ctr(0 or 1,4 if err)                               //~v5a3I~
//******************************************************           //~v5a3I~
int ugetnumrange2(int Popt,char *Pstr,long *Pstart,long *Pend)     //~v5a3I~
{                                                                  //~v5a3I~
    int rc;                                                        //~v5a3I~
//******************                                               //~v5a3I~
    Sgetnumpostfix2=Sgetnumpostfix=(char)(Popt & UGNR2_MASK);      //~v5e7R~
    if (Popt & UGNR2_NOCASE)                                       //~v5a3I~
    {                                                              //~v5a3I~
    	Sgetnumpostfix=(char)tolower(Sgetnumpostfix);              //~v5e7R~
    	Sgetnumpostfix2=(char)toupper(Sgetnumpostfix);             //~v5e7R~
    }                                                              //~v5a3I~
    if (Popt & UGNR2_HEX)                                          //~v5a3I~
		rc=ugetxnumrange(Pstr,Pstart,Pend);                        //~v5a3I~
    else                                                           //~v5a3I~
		rc=ugetnumrange(Pstr,Pstart,Pend);                         //~v5a3I~
    Sgetnumpostfix2=Sgetnumpostfix=0;                              //~v5a3R~
    return rc;                                                     //~v5a3I~
}//ugetnumrange2                                                   //~v5a3I~
//*******************************************************          //~v6x0R~
//*ugetnumrange2XFILESZ                                            //~v6x0R~
//*support x value only                                            //~v6x0R~
//* get start/end value from (x)nnn(L)-(x)mmm(L) format            //~v6x0R~
//* (support postfix for number to set minus value                 //~v6x0R~
//* return:delm ctr(0 or 1,4 if err)                               //~v6x0R~
//******************************************************           //~v6x0R~
int ugetnumrange2XFILESZ(int Popt,char *Pstr,FILESZT *Pstart,FILESZT *Pend)//~v6x0R~
{                                                                  //~v6x0R~
    int rc;                                                        //~v6x0R~
//******************                                               //~v6x0R~
    Sgetnumpostfix2=Sgetnumpostfix=(char)(Popt & UGNR2_MASK);      //~v6x0R~
    if (Popt & UGNR2_NOCASE)                                       //~v6x0R~
    {                                                              //~v6x0R~
    	Sgetnumpostfix=(char)tolower(Sgetnumpostfix);              //~v6x0R~
    	Sgetnumpostfix2=(char)toupper(Sgetnumpostfix);             //~v6x0R~
    }                                                              //~v6x0R~
//  if (Popt & UGNR2_HEX)                                          //~v6x0R~
#ifdef LFSSUPP                                                     //~v6x0R~
		rc=ugetxnumrangeLL(Pstr,Pstart,Pend);                      //~v6x0R~
#else                                                              //~v6x0R~
		rc=ugetxnumrange(Pstr,Pstart,Pend);                        //~v6x0R~
#endif                                                             //~v6x0R~
//  else                                                           //~v6x0R~
//  	rc=ugetnumrange(Pstr,Pstart,Pend);                         //~v6x0R~
    Sgetnumpostfix2=Sgetnumpostfix=0;                              //~v6x0R~
    return rc;                                                     //~v6x0R~
}//ugetnumrange2XFILESZ                                            //~v6x0R~
//*******************************************************          //~v047I~
//*ugetnumrange                                                    //~v047I~
//* get start/end value from nnn-mmm format                        //~v047I~
//* parm1 :string                                                  //~v047I~
//* parm2 :long:start                                              //~v047I~
//* parm3 :long:end                                                //~v047I~
//* return:delm ctr(0 or 1,4 if err)                               //~v047R~
//******************************************************           //~v047I~
int ugetnumrange(char *Pstr,long *Pstart,long *Pend)               //~v047R~
{                                                                  //~v047I~
    int delmctr=0;                                                 //~v047R~
    long value[2]={0,0};                                           //~v047R~
    int  minussign[2]={0,0};                                       //~v5a3I~
    char *pc0,*pc;                                                 //~v047R~
//******************                                               //~v047I~
    pc0=pc=Pstr;                                                   //~v047I~
    for (;;pc++)                                                   //~v047I~
    {                                                              //~v047I~
        if (!*pc || *pc=='-')   //delm                             //~v047I~
        {                                                          //~v047I~
            if (delmctr>1)                                         //~v047R~
                return 4;                                          //~v047I~
            if (pc!=pc0)                                           //~v047I~
            {                                                      //~v5a3I~
              if (minussign[delmctr])                              //~v5a3I~
                value[delmctr]=-atol(pc0);                         //~v5a3I~
              else                                                 //~v5a3I~
                value[delmctr]=atol(pc0);                          //~v047R~
            }//pc                                                  //~v5a3I~
            if (!*pc)                                              //~v047I~
                break;                                             //~v047I~
            delmctr++;                                             //~v047I~
            pc0=pc+1;                                              //~v047I~
        }                                                          //~v047I~
        else                                                       //~v047I~
            if (*pc==Sgetnumpostfix||*pc==Sgetnumpostfix2)         //~v5a3R~
            {                                                      //~v5a3I~
              	if (*(pc+1) && *(pc+1)!='-')	//next is not delm //~v5a3I~
                	return 4;                                      //~v5a3I~
                minussign[delmctr]=1;                              //~v5a3I~
            }                                                      //~v5a3I~
            else                                                   //~v5a3I~
            if (*pc<'0'||*pc>'9')                                  //~v047I~
                return 4;                                          //~v047I~
    }                                                              //~v047I~
    *Pstart=value[0];                                              //~v047I~
    *Pend=value[1];                                                //~v047I~
    return delmctr;                                                //~v047R~
}//ugetnumrange                                                    //~v047I~
                                                                   //~v047I~
//*******************************************************          //~v244I~
//*ugetxnumrange                                                   //~v244I~
//* get start/end value from nnn-mmm format                        //~v244I~
//* parm1 :string                                                  //~v244I~
//* parm2 :long:start                                              //~v244I~
//* parm3 :long:end                                                //~v244I~
//* return:delm ctr(0 or 1,-1 if err)                              //~v244I~
//******************************************************           //~v244I~
int ugetxnumrange(char *Pstr,long *Pstart,long *Pend)              //~v244I~
{                                                                  //~v244I~
    int delmctr=0,rc;                                              //~v244R~
    ULONG value[2]={0,0};                                          //~v244R~
    int minussign[2]={0,0};                                        //~v5a3I~
    char *pc,*pc2,chsv=0;                                            //~v244I~//~v5h7R~
    char *pc3;                                                     //~v5a3I~
//******************                                               //~v244I~
    pc=Pstr;                                                       //~v244I~
    if (*pc=='0')                                                  //~v5bhI~
        pc++;                                                      //~v5bhI~
    if (*pc=='x' || *pc=='X')                                      //~v244I~
        pc++;                                                      //~v244I~
    if (*pc=='-')                                                  //~v244I~
    {                                                              //~v244I~
        delmctr=1;                                                 //~v244I~
        pc++;                                                      //~v244I~
    	if (*pc=='0')                                              //~v5bhI~
	        pc++;                                                  //~v5bhI~
        if (*pc=='x' || *pc=='X')                                  //~v244I~
            pc++;                                                  //~v244I~
    }                                                              //~v244I~
    if (!delmctr && (pc2=strchr(pc,'-'))!=0)                       //~v244I~
    {                                                              //~v244I~
        delmctr=1;                                                 //~v244I~
        if (*(pc2-1)==Sgetnumpostfix||*(pc2-1)==Sgetnumpostfix2)   //~v5a3R~
        {                                                          //~v5a3I~
        	minussign[0]=1;                                        //~v5a3I~
            pc2--;                                                 //~v5a3I~
        }                                                          //~v5a3I~
        chsv=*pc2;                                                 //~v244I~
        *pc2=0;                                                    //~v244I~
        rc=ux2l(pc,value);                                         //~v244I~
        *pc2++=chsv;                                               //~v244I~
        if (minussign[0])                                          //~v5a3I~
        	pc2++;                                                 //~v5a3I~
        if (!rc)                                                   //~v244I~
        {                                                          //~v244I~
	    	if (*pc2=='0')                                         //~v5bhI~
		        pc2++;                                             //~v5bhI~
            if (*pc2=='x' || *pc2=='X')                            //~v244I~
                pc2++;                                             //~v244I~
            pc3=pc2+strlen(pc2)-1;                                 //~v5a3I~
            if (*pc3==Sgetnumpostfix||*pc3==Sgetnumpostfix2)       //~v5a3R~
            {                                                      //~v5a3I~
	        	minussign[1]=1;                                    //~v5a3I~
        		chsv=*pc3;                                         //~v5a3I~
        		*pc3=0;                                            //~v5a3I~
            }                                                      //~v5a3I~
            rc=ux2l(pc2,value+1);                                  //~v244I~
            if (minussign[1])                                      //~v5a3I~
        		*pc3=chsv;                                         //~v5a3R~
        }                                                          //~v244I~
    }                                                              //~v244I~
    else                                                           //~v244I~
    {                                                              //~v5a3I~
        pc3=pc+strlen(pc)-1;                                       //~v5a3I~
        if (*pc3==Sgetnumpostfix||*pc3==Sgetnumpostfix2)           //~v5a3R~
        {                                                          //~v5a3I~
            minussign[delmctr]=1;                                  //~v5a3I~
        	chsv=*pc3;                                             //~v5a3I~
            *pc3=0;                                                //~v5a3I~
        }                                                          //~v5a3I~
        rc=ux2l(pc,value+delmctr);                                 //~v244I~
        if (minussign[delmctr])                                    //~v5a3I~
            *pc3=chsv;                                             //~v5a3R~
    }                                                              //~v5a3I~
    if (rc)                                                        //~v244I~
        return -1;                                                 //~v244I~
  if (minussign[0])                                                //~v5a3I~
    *Pstart=-(long)value[0];                                       //~v5a3I~
  else                                                             //~v5a3I~
    *Pstart=(long)value[0];                                        //~v244R~
  if (minussign[1])                                                //~v5a3I~
    *Pend=-(long)value[1];                                         //~v5a3I~
  else                                                             //~v5a3I~
    *Pend=(long)value[1];                                          //~v244R~
    return delmctr;                                                //~v244I~
}//ugetxnumrange                                                   //~v244I~
//*******************************************************          //~v6x0R~
//*ugetxnumrangeLL                                                 //~v6x0R~
//* get start/end value from nnn-mmm format                        //~v6x0R~
//* parm1 :string                                                  //~v6x0R~
//* parm2 :long:start                                              //~v6x0R~
//* parm3 :long:end                                                //~v6x0R~
//* return:delm ctr(0 or 1,-1 if err)                              //~v6x0R~
//******************************************************           //~v6x0R~
int ugetxnumrangeLL(char *Pstr,INT64 *Pstart,INT64 *Pend)          //~v6x0R~
{                                                                  //~v6x0R~
    int delmctr=0,rc;                                              //~v6x0R~
    INT64 value[2]={0,0};                                          //~v6x0R~
    int minussign[2]={0,0};                                        //~v6x0R~
    char *pc,*pc2,chsv=0;                                          //~v6x0R~
    char *pc3;                                                     //~v6x0R~
//******************                                               //~v6x0R~
    pc=Pstr;                                                       //~v6x0R~
    if (*pc=='0')                                                  //~v6x0R~
        pc++;                                                      //~v6x0R~
    if (*pc=='x' || *pc=='X')                                      //~v6x0R~
        pc++;                                                      //~v6x0R~
    if (*pc=='-')                                                  //~v6x0R~
    {                                                              //~v6x0R~
        delmctr=1;                                                 //~v6x0R~
        pc++;                                                      //~v6x0R~
    	if (*pc=='0')                                              //~v6x0R~
	        pc++;                                                  //~v6x0R~
        if (*pc=='x' || *pc=='X')                                  //~v6x0R~
            pc++;                                                  //~v6x0R~
    }                                                              //~v6x0R~
    if (!delmctr && (pc2=strchr(pc,'-'))!=0)                       //~v6x0R~
    {                                                              //~v6x0R~
        delmctr=1;                                                 //~v6x0R~
        if (*(pc2-1)==Sgetnumpostfix||*(pc2-1)==Sgetnumpostfix2)   //~v6x0R~
        {                                                          //~v6x0R~
        	minussign[0]=1;                                        //~v6x0R~
            pc2--;                                                 //~v6x0R~
        }                                                          //~v6x0R~
        chsv=*pc2;                                                 //~v6x0R~
        *pc2=0;                                                    //~v6x0R~
//      rc=ux2l(pc,value);                                         //~v6x0R~
        rc=ux2ll(pc,value);                                        //~v6x0R~
        *pc2++=chsv;                                               //~v6x0R~
        if (minussign[0])                                          //~v6x0R~
        	pc2++;                                                 //~v6x0R~
        if (!rc)                                                   //~v6x0R~
        {                                                          //~v6x0R~
	    	if (*pc2=='0')                                         //~v6x0R~
		        pc2++;                                             //~v6x0R~
            if (*pc2=='x' || *pc2=='X')                            //~v6x0R~
                pc2++;                                             //~v6x0R~
            pc3=pc2+strlen(pc2)-1;                                 //~v6x0R~
            if (*pc3==Sgetnumpostfix||*pc3==Sgetnumpostfix2)       //~v6x0R~
            {                                                      //~v6x0R~
	        	minussign[1]=1;                                    //~v6x0R~
        		chsv=*pc3;                                         //~v6x0R~
        		*pc3=0;                                            //~v6x0R~
            }                                                      //~v6x0R~
//          rc=ux2l(pc2,value+1);                                  //~v6x0R~
            rc=ux2ll(pc2,value+1);                                 //~v6x0R~
            if (minussign[1])                                      //~v6x0R~
        		*pc3=chsv;                                         //~v6x0R~
        }                                                          //~v6x0R~
    }                                                              //~v6x0R~
    else                                                           //~v6x0R~
    {                                                              //~v6x0R~
        pc3=pc+strlen(pc)-1;                                       //~v6x0R~
        if (*pc3==Sgetnumpostfix||*pc3==Sgetnumpostfix2)           //~v6x0R~
        {                                                          //~v6x0R~
            minussign[delmctr]=1;                                  //~v6x0R~
        	chsv=*pc3;                                             //~v6x0R~
            *pc3=0;                                                //~v6x0R~
        }                                                          //~v6x0R~
//      rc=ux2l(pc,value+delmctr);                                 //~v6x0R~
        rc=ux2ll(pc,value+delmctr);                                //~v6x0R~
        if (minussign[delmctr])                                    //~v6x0R~
            *pc3=chsv;                                             //~v6x0R~
    }                                                              //~v6x0R~
    if (rc)                                                        //~v6x0R~
        return -1;                                                 //~v6x0R~
  if (minussign[0])                                                //~v6x0R~
//  *Pstart=-(long)value[0];                                       //~v6x0R~
    *Pstart=-value[0];                                             //~v6x0R~
  else                                                             //~v6x0R~
//  *Pstart=(long)value[0];                                        //~v6x0R~
    *Pstart=value[0];                                              //~v6x0R~
  if (minussign[1])                                                //~v6x0R~
//  *Pend=-(long)value[1];                                         //~v6x0R~
    *Pend=-value[1];                                               //~v6x0R~
  else                                                             //~v6x0R~
//  *Pend=(long)value[1];                                          //~v6x0R~
    *Pend=value[1];                                                //~v6x0R~
    return delmctr;                                                //~v6x0R~
}//ugetxnumrangeLL                                                 //~v6x0R~
                                                                   //~v244I~
//*******************************************************          //~v095I~
//*unumlen                                                         //~v095I~
//* count numeric digit                                            //~v095I~
//* parm1 :string                                                  //~v095I~
//* parm2 :option :0:digit,1:hex digit                             //~v095I~
//* parm3 :max len                                                 //~v095I~
//* return:length                                                  //~v095I~
//******************************************************           //~v095I~
int unumlen(unsigned char *Pstr,int Popt,int Plen)                 //~v095R~
{                                                                  //~v095I~
    int ii,hexopt,minusopt=0;                                      //~v303R~
    int octopt;                                                    //~v526R~
//******************                                               //~v095I~
    hexopt=(Popt & UNUMLEN_HEX);                                   //~v301R~
    octopt=(Popt & UNUMLEN_OCT);                                   //~v526I~
    ii=0;                                                          //~v301I~
    if (Popt & UNUMLEN_SPACE)                                      //~v301I~
//      for (;*Pstr && ii<Plen;ii++,Pstr++)                        //~v5fkR~
        for (;ii<Plen && *Pstr;ii++,Pstr++)                        //~v5fkI~
            if (*Pstr!=' ')                                        //~v301I~
                break;                                             //~v301I~
    if (*Pstr=='+')                                                //~v303I~
    {                                                              //~v303I~
        Pstr++;                                                    //~v303I~
        ii++;                                                      //~v303I~
    }                                                              //~v303I~
    else                                                           //~v303I~
    if (*Pstr=='-')                                                //~v303I~
    {                                                              //~v303I~
        Pstr++;                                                    //~v303I~
        ii++;                                                      //~v303I~
        if (ii>=Plen)                                              //~v303I~
            return 0;                                              //~v303I~
        minusopt=(Popt & UNUMLEN_MINUS);                           //~v303R~
    }                                                              //~v303I~
//  for (;*Pstr && ii<Plen;ii++,Pstr++)                            //~v5fkR~
    for (;ii<Plen && *Pstr;ii++,Pstr++)                            //~v5fkI~
    {                                                              //~v095I~
        if (octopt)                                                //~v526I~
        {                                                          //~v59kI~
        	if (*Pstr>='0' && *Pstr <='7')                         //~v526I~
            	continue;                                          //~v526I~
            else                                                   //~v526I~
            	break;                                             //~v526I~
        }                                                          //~v59kI~
        if (*Pstr>='0' && *Pstr <='9')                             //~v095I~
            continue;                                              //~v095I~
        if (!hexopt)                                               //~v095I~
            break;                                                 //~v095I~
        if (*Pstr>='a' && *Pstr <='f')                             //~v095I~
            continue;                                              //~v095I~
        if (*Pstr>='A' && *Pstr <='F')                             //~v095I~
            continue;                                              //~v095I~
        break;                                                     //~v095I~
    }                                                              //~v095I~
    if (minusopt)                                                  //~v303I~
        return -ii;                                                //~v303I~
    return ii;                                                     //~v095I~
}//unumlen                                                         //~v095I~
                                                                   //~v095I~
//*******************************************************          //~v096I~
//*uatoin                                                          //~v096I~
//* atoi with max len                                              //~v096I~
//* parm1 :string                                                  //~v096I~
//* parm2 :strlen                                                  //~v096I~
//* return:int                                                     //~v096I~
//******************************************************           //~v096I~
int uatoin(char *Pstr,int Plen)                                    //~v096I~
{                                                                  //~v096I~
    int len ;                                                      //~v096I~
    char wk[12];                                                   //~v096I~
//******************                                               //~v096I~
    if (Plen<=0)                                                   //~v096I~
        return 0;                                                  //~v096I~
//  len=min(Plen,sizeof(wk)-1);                                    //~v096I~//~v6BkR~
    len=min(Plen,(int)sizeof(wk)-1);                               //~v6BkI~
    strncpy(wk,Pstr,(UINT)len);                                    //~v096R~
    wk[len]=0;                                                     //~v095I~
    return atoi(wk);                                               //~v096I~
}//uatoin                                                          //~v096I~
//******************************************************************//~v6x3I~
char *getKMGTB(int Popt,FILESZT Psz,ULONG *Pulsz)                  //~v6x3I~
{                                                                  //~v6x3I~
	char *pkmgt=0;                                                 //~v6x3R~
    FILESZT sz;                                                    //~v6x3I~
//***********************                                          //~v6x3I~
    sz=Psz;                                                        //~v6x3I~
    if (!(sz & 0x3ff)) //available by KB                           //~v6x3I~
    {                                                              //~v6x3I~
	    pkmgt="KB";                                                //~v6x3R~
	    sz>>=10;                                                   //~v6x3I~
	    if (!(sz & 0x3ff)) //available by MB                       //~v6x3I~
        {                                                          //~v6x3I~
	    	pkmgt="MB";                                            //~v6x3R~
	    	sz>>=10;                                               //~v6x3I~
		    if (!(sz & 0x3ff)) //available by MB                   //~v6x3I~
    	    {                                                      //~v6x3I~
		    	pkmgt="GB";                                        //~v6x3R~
		    	sz>>=10;                                           //~v6x3I~
			    if (!(sz & 0x3ff)) //available by MB               //~v6x3I~
    		    {                                                  //~v6x3I~
			    	pkmgt="TB";                                    //~v6x3R~
			    	sz>>=10;                                       //~v6x3I~
                }                                                  //~v6x3I~
            }                                                      //~v6x3I~
        }                                                          //~v6x3I~
    }                                                              //~v6x3I~
    if (sz>(FILESZT)0xffffffff)	//over 4byte                       //~v6x3I~
    	pkmgt=0;                                                   //~v6x3R~
    else                                                           //~v6x3I~
      	*Pulsz=(ULONG)sz;                                          //~v6x3I~
    return pkmgt;                                                  //~v6x3R~
}//getKMGTB                                                        //~v6x3I~
//******************************************************************//~v6x3I~
//*Pfmt ex) "%12$x" (rep $ by I64/ll/l)                            //~v6x3I~
//******************************************************************//~v6x3I~
char *ueditFILESZ(int Popt,char *Pout,int Pbuffsz,char *Pfmt,FILESZT Psz)//~v6x3R~
{                                                                  //~v6x3I~
	char *pc,*ptype,*pout,*psrc=0;                                 //~v6x3R~
    int outlen=0,swok=0,buffsz,len1,len2,len3;                     //~v6x3R~
    char wk[32];                                                   //~v6x3I~
    char wkuledit[16];                                             //~v6x3I~
static char Swk[64];                                               //~v6x3I~
	ULONG ulsz=0;                                                  //~v6x3R~
    char *pkmgt=0;                                                 //~v6x3I~
//************************                                         //~v6x3I~
	buffsz=Pbuffsz;                                                //~v6x3I~
    pout=Pout;                                                     //~v6x3I~
    if (!pout)                                                     //~v6x3I~
    {                                                              //~v6x3I~
    	pout=Swk;                                                  //~v6x3I~
        buffsz=sizeof(Swk);                                        //~v6x3I~
    }                                                              //~v6x3I~
	pc=strchr(Pfmt,'$');                                           //~v6x3R~
    if (pc)                                                        //~v6x3I~
    {                                                              //~v6x3I~
      		if (Popt & UEFS_KMGT)                                  //~v6x3R~
      			pkmgt=getKMGTB(Popt,Psz,&ulsz);                    //~v6x3R~
            if (pkmgt)                                             //~v6x3R~
            {                                                      //~v6x3R~
             	 swok=1;                                           //~v6x3R~
              	outlen=sprintf(wkuledit,"%ld%s",ulsz,pkmgt);       //~v6x3R~
              	psrc=wkuledit;                                     //~v6x3R~
            }                                                      //~v6x3R~
            else                                                   //~v6x3R~
            {                                                      //~v6x3R~
                len1=PTRDIFF(pc,Pfmt);                             //~v6x3R~
                ptype=FILESZ_EDIT;                                 //~v6x3R~
//              len2=strlen(ptype);                                //~v6x3R~//~v6BkR~
                len2=(int)strlen(ptype);                           //~v6BkI~
//              len3=strlen(pc+1);                                 //~v6x3R~//~v6BkR~
                len3=(int)strlen(pc+1);                            //~v6BkI~
                outlen=len1+len2+len3;                             //~v6x3R~
                if (outlen<sizeof(wk)-1)                           //~v6x3R~
                {                                                  //~v6x3R~
//                  memcpy(wk,Pfmt,len1);                          //~v6x3R~//~v6BkR~
                    memcpy(wk,Pfmt,(size_t)len1);                  //~v6BkI~
//                  memcpy(wk+len1,ptype,len2);                    //~v6x3R~//~v6BkR~
                    memcpy(wk+len1,ptype,(size_t)len2);            //~v6BkI~
//                  memcpy(wk+len1+len2,pc+1,len3);                //~v6x3R~//~v6BkR~
                    memcpy(wk+len1+len2,pc+1,(size_t)len3);        //~v6BkI~
                    *(wk+outlen)=0;                                //~v6x3R~
                    outlen=sprintf(Swk,wk,Psz);                    //~v6x3R~
                    psrc=Swk;                                      //~v6x3R~
                    swok=1;                                        //~v6x3R~
                }                                                  //~v6x3R~
            }                                                      //~v6x3R~
    }                                                              //~v6x3I~
    if (!swok)                                                     //~v6x3I~
    {                                                              //~v6x3I~
//      outlen=strlen(Pfmt);                                       //~v6x3I~//~v6BkR~
        outlen=(int)strlen(Pfmt);                                  //~v6BkI~
        psrc=Pfmt;                                                 //~v6x3I~
    }                                                              //~v6x3I~
    outlen=min(outlen,buffsz-1);                                   //~v6x3I~
    if (psrc!=pout)                                                //~v6x3I~
//  	UmemcpyZ(pout,psrc,outlen);                                //~v6x3I~//~v6BkR~
    	UmemcpyZ(pout,psrc,(size_t)outlen);                        //~v6BkI~
    return pout;                                                   //~v6x3I~
}//ueditFILESZ                                                     //~v6x3I~
//******************************************************************//~v6xkI~
//*Pfmt ex) "%12$x" (rep $ by I64/ll/l)                            //~v6xkI~
//******************************************************************//~v6xkI~
char *ueditLONGHANDLE(int Popt,char *Pout,int Pbuffsz,char *Pfmt,LONGHANDLE Phandle)//~v6xkI~
{                                                                  //~v6xkI~
	char *pc,*ptype,*pout,*psrc=0;                                 //~v6xkI~
    int outlen=0,swok=0,buffsz,len1,len2,len3;                     //~v6xkI~
    char wk[32];                                                   //~v6xkI~
static char Swk[64];                                               //~v6xkI~
//************************                                         //~v6xkI~
	buffsz=Pbuffsz;                                                //~v6xkI~
    pout=Pout;                                                     //~v6xkI~
    if (!pout)                                                     //~v6xkI~
    {                                                              //~v6xkI~
    	pout=Swk;                                                  //~v6xkI~
        buffsz=sizeof(Swk);                                        //~v6xkI~
    }                                                              //~v6xkI~
	pc=strchr(Pfmt,'$');                                           //~v6xkI~
    if (pc)                                                        //~v6xkI~
    {                                                              //~v6xkI~
                len1=PTRDIFF(pc,Pfmt);                             //~v6xkI~
#ifdef ULIB64X                                                     //~v6xkI~
                ptype=FILESZ_EDIT;                                 //~v6xkI~
                len2=strlen(ptype);                                //~v6xkI~
#else                                                              //~v6xkI~
                ptype="";                                          //~v6xkI~
                len2=0;                                            //~v6xkI~
#endif                                                             //~v6xkI~
//              len3=strlen(pc+1);                                 //~v6xkI~//~v6BkR~
                len3=(int)strlen(pc+1);                            //~v6BkI~
                outlen=len1+len2+len3;                             //~v6xkI~
                if (outlen<sizeof(wk)-1)                           //~v6xkI~
                {                                                  //~v6xkI~
//                  memcpy(wk,Pfmt,len1);                          //~v6xkI~//~v6BkR~
                    memcpy(wk,Pfmt,(size_t)len1);                  //~v6BkI~
                    if (len2)                                      //~v6xkI~
//                  	memcpy(wk+len1,ptype,len2);                //~v6xkI~//~v6BkR~
                    	memcpy(wk+len1,ptype,(size_t)len2);        //~v6BkI~
//                  memcpy(wk+len1+len2,pc+1,len3);                //~v6xkI~//~v6BkR~
                    memcpy(wk+len1+len2,pc+1,(size_t)len3);        //~v6BkI~
                    *(wk+outlen)=0;                                //~v6xkI~
                    outlen=sprintf(Swk,wk,Phandle);                //~v6xkI~
                    psrc=Swk;                                      //~v6xkI~
                    swok=1;                                        //~v6xkI~
                }                                                  //~v6xkI~
    }                                                              //~v6xkI~
    if (!swok)                                                     //~v6xkI~
    {                                                              //~v6xkI~
//      outlen=strlen(Pfmt);                                       //~v6xkI~//~v6BkR~
        outlen=(int)strlen(Pfmt);                                  //~v6BkI~
        psrc=Pfmt;                                                 //~v6xkI~
    }                                                              //~v6xkI~
    outlen=min(outlen,buffsz-1);                                   //~v6xkI~
    if (psrc!=pout)                                                //~v6xkI~
//  	UmemcpyZ(pout,psrc,outlen);                                //~v6xkI~//~v6BkR~
    	UmemcpyZ(pout,psrc,(size_t)outlen);                        //~v6BkI~
    return pout;                                                   //~v6xkI~
}//ueditLONGHANDLE                                                 //~v6xkI~
//******************************************************************//~v6T1I~
//*edit memorisize by K/M/G                                        //~v6T1I~
//******************************************************************//~v6T1I~
char *ueditKMG(int Popt,size_t Psz)                                //~v6T1I~
{                                                                  //~v6T1I~
static char Swk[16];                                               //~v6T1I~
	size_t szK,szM,szG,res;                                        //~v6T1I~
//************************                                         //~v6T1I~
	res=Psz%1024;                                                  //~v6T1I~
    if (res)                                                       //~v6T1I~
    {                                                              //~v6T1I~
    	sprintf(Swk,"%ld",(long)Psz);                              //+v6T1R~
    }                                                              //~v6T1I~
    else                                                           //~v6T1I~
    {                                                              //~v6T1I~
		szK=Psz/1024;                                              //~v6T1I~
        res=szK%1024;                                              //~v6T1I~
        if (res)                                                   //~v6T1I~
        {                                                          //~v6T1I~
	    	sprintf(Swk,"%ldK",(long)szK);                         //+v6T1R~
        }                                                          //~v6T1I~
        else                                                       //~v6T1I~
        {                                                          //~v6T1I~
			szM=szK/1024;                                          //~v6T1I~
	        res=szM%1024;                                          //~v6T1I~
            if (res)                                               //~v6T1I~
            {                                                      //~v6T1I~
		    	sprintf(Swk,"%ldM",(long)szM);                     //+v6T1R~
            }                                                      //~v6T1I~
            else                                                   //~v6T1I~
            {                                                      //~v6T1I~
				szG=szM/1024;                                      //~v6T1I~
		    	sprintf(Swk,"%ldG",(long)szG);                     //+v6T1R~
            }                                                      //~v6T1I~
        }                                                          //~v6T1I~
    }                                                              //~v6T1I~
	return Swk;                                                    //~v6T1I~
}//ueditKMG                                                        //~v6T1I~
