//CID://+v6h7R~: update#=      2                                   //~v6h7R~
//*************************************************************
//*ufuncmap.c                                                      //~v173R~
//***********************************************************
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v57v:030223 (WIN:BUG)for vc6 main offset is not 0;abend path info err//~v57vI~
//v206:981213 (OS2:BUG)DosQueryMem return only up to segment boudary(64k)//~v206I~
//            loop if size is over boundary                        //~v206I~
//v173:980501 (BUG)memchk should rc=1 when len changed.dump by commit len//~v173I~
//v167:980430 test eh bug                                          //~v167I~
//v165:980411 (BUG)DOS abmsg EBP-->BP                              //~v165I~
//v150:980119 need differrentiate codepage and dbcs tbl            //~v150I~
//            w95J codepdge 437 hase dbcs table and first half of DBCS on//~v150I~
//            rightmost column effect on first column of next line //~v150I~
//v118:971115 (DPMI:BUG)umemchk for DPMI,sslim chk "<" --> "<="    //~v118I~
//v108:971027 (BUG:GCC)addr must ulong(gcc may return ff______ addr for malloc)//~v108I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -stack accessible by external symbol(__djgpp...)     //~v053I~
//            -different map format                                //~v053I~
//v046:961109:chk Heap middle hole(decommitted page)               //~v046I~
//v034:961008:VC support(identify by (_MSC_VER>=800))              //~v034I~
//v027:960917:dos dump sub                                         //~v027I~
//v028:960920:line no display on map err msg                       //~v028I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//950930:malloc/calloc rc chk for dos                           //~5930I~
//*950826 map "read error",it may be by ferror not after fgets err//~5826I~
//*941127 display path parm
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*************************************************************
#ifdef DOS
        #include <dos.h>
    #ifdef DPMI                                 //DPMI version                     //~v053I~
        #include <errno.h>                                         //~v053I~
        #include <crt0.h>                     //v3.7a              //~v053I~
        #include <dpmi.h>                     //v3.7a              //~v053I~
        #include <sys/nearptr.h>              //v3.7a              //~v053I~
        #include <sys/segments.h>              //v3.7a             //~v053I~
    #else                       //not DPMI                         //~v053I~
    #endif                      //DPMI or not                      //~v053I~
#else
        #ifdef W32                                                     //~v022I~
                #include <windows.h>                                       //~v022I~
    #else                                                          //~v022I~
        #define INCL_BASE
        #include <os2.h>
        #endif                                                         //~v022I~
#endif
//*******************************************************
#define  GLOBAL
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <ufuncmap.h>
#include <udbcschk.h>
#include <utrace.h>                                                //~v167I~
#ifdef DOS                                                         //~v022I~
#else                                                              //~v022I~
#include <ueh.h>                                                   //~v022I~
#endif                                                             //~v022I~
//*******************************************************
#define MAPRECSZ                256
#define ERR81           81
#define ERR82           82
#define ERR83           83
#define ERR84           84
#define ERR85           85
#define ERR86           86
#define ERR87           87
#define ERR88           88
#define ERR89           89
//*******************************************************
#ifdef DOS
    #ifdef DPMI                                 //DPMI version                     //~v053I~
        #define NEXTEBP(pvoid,ebp) (*(ULONG*)ebp)                  //~v053I~
        #define NEXTPTR(pvoid,ebp) (*(ULONG*)ebp)                  //~v053I~
        #define MAKEREALADDR(addr)      ((ULONG)addr)                  //~v053I~
    #else                       //not DPMI                         //~v053I~
        #define NEXTEBP(pvoid,ebp) ((ULONG)*(UINT*)FP_SEGOFF(FP_SEG(pvoid),ebp))
        #define NEXTPTR(pvoid,ebp) ((ULONG)*(ULONG*)FP_SEGOFF(FP_SEG(pvoid),ebp))
        #define MAKEREALADDR(addr) ((ULONG)FP_SEG(addr)*16+(ULONG)FP_OFF(addr))
    #endif                      //DPMI or not                      //~v053I~
#else
//for also W32                                                     //~v022I~
        #define NEXTEBP(pvoid,ebp) (*(ULONG*)ebp)
        #define NEXTPTR(pvoid,ebp) (*(ULONG*)ebp)
        #define MAKEREALADDR(addr)      ((ULONG)addr)
#endif
//**************                                                   //~v027R~
        PEPATBL Gpepatbl;               //for uerrexit                         //~v027R~
//**************                                                   //~v027I~
#ifdef DOS
    #ifdef DPMI                                 //DPMI version                     //~v053I~
static  int data32seglen,data32segoff;                             //~v053I~
static  int bss32seglen,bss32segoff;                               //~v053I~
    #else                       //not DPMI                         //~v053I~
        static long  Sdosstacksz;
        static long  Sdosmainebp;       //main ebp value
    #endif                      //DPMI or not                      //~v053M~
#else                                                              //~v022I~
        #ifdef W32                                                     //~v022I~
                static ULONG Sdosmainebp;       //main ebp value               //~v034R~
    #endif                                                         //~v022I~
#endif

static int Sline;           //line no                              //~v028I~
static UCHAR constnaj[]="関数名不明";
static UCHAR constnae[]="Function name N/A";
static UCHAR msgprotstack[]
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI                                 //DPMI version                     //~v053I~
         ="at %08lX(EBP=%08lX) %-24.24s(EPA=%08lX) was called\n%n";//~v053I~
    #else                       //not DPMI                         //~v053I~
         ="at %08lX(BP=%04lX) %-24.24s(EPA=%08lX) was called\n%n"; //~v165R~
    #endif                      //DPMI or not                      //~v053I~
#else                                                              //~v027I~
         ="at %08lX(EBP=%08lX) %-24.24s(EPA=%08lX) was called\n%n";//~5128R~
#endif                                                             //~v027R~
//***************
static int maperr(int Prc,UCHAR *Pbuff);
static UCHAR *getfld(UCHAR *Pbuff,int Pfldno);
//*******************************************************
//*ufuncmap
//* create epa table from map file
//* parm1:map file path/name
//* parm2:base(main) addr
//* parm3:optional ptr of tbl ptr,0 if req only get seg addr/len   //~v053R~
//* return: rc
//*******************************************************
#ifdef DPMI                                     //DPMI version                         //~v053I~
int ufuncmap(UCHAR *Pfilename,PVOID Pbase,PEPATBL *Ppepatbl)       //~v053I~
{                                                                  //~v053I~
        static UCHAR codesegid[]=".text";                              //~v053I~
        static UCHAR codeendid[]="*fill*";                             //~v053I~
        static UCHAR datasegid[]=".data";                              //~v053I~
        static UCHAR bsssegid[]=".bss ";                               //~v053R~
//*******************                                              //~v053I~
int uaddrcomp(const void *ent1,const void *ent2);                  //~v053I~
        FILE *hfile;                                                   //~v053I~
        PEPATBL pepatbl,pepatblobj;                                    //~v053R~
        int ii;                                                        //~v053R~
        int objsw,code32sw=0;                                          //~v053R~
        int code32seglen,code32segoff;                                 //~v053R~
        int code32funcno=0,code32funcno2=0,lines=0,linee=0;            //~v053R~
        UCHAR *pc,*pc2,*getstring;                                     //~v053I~
        UCHAR objstart[8];      //objstart offset char                     //~v053R~
        UCHAR buff[MAPRECSZ+1];                                        //~v053I~
//**************************************************************** //~v053I~
        *Ppepatbl=0;                                                   //~v053I~
        if (hfile=fopen(Pfilename,"r"),!hfile)                         //~v053I~
        {                                                              //~v053I~
                uerrmsg("%s Open failed,errno=%d",                         //~v053I~
                            "%s オープンエラー,errno=%d",Pfilename,errno);     //~v053I~
                return 4;                                                  //~v053I~
        }                                                              //~v053I~
        Sline=0;                                                       //~v053I~
        while(getstring=fgets(buff,MAPRECSZ+1,hfile),getstring) //null return if error or eof//~v053I~
        {                                                              //~v053I~
                Sline++;                                                   //~v053I~
        if (*buff=='\n')                                           //~v053I~
                continue;       //skip null line                           //~v053I~
                if (!memcmp(buff,codesegid,sizeof(codesegid)-1))           //~v053R~
                {                               //format:".text   Origin  Length"//~v053R~
                        if (pc=getfld(buff,2),!pc)                             //~v053I~
                                return maperr(ERR81,buff);                         //~v053I~
                        code32segoff=strtol(pc+2,0,16);//conv 0Xxxxxxxxx       //~v053R~
                        if (pc=getfld(buff,3),!pc)                             //~v053I~
                                return maperr(ERR82,buff);                         //~v053I~
                        code32seglen=strtol(pc+2,0,16);//conv 0Xxxxxxxxx       //~v053R~
            continue;   //                                         //~v053I~
                }                                                          //~v053I~
                if (!memcmp(buff,datasegid,sizeof(datasegid)-1))           //~v053I~
                {                               //format:".text   Origin  Length"//~v053I~
                        if (pc=getfld(buff,2),!pc)                             //~v053I~
                                return maperr(ERR81,buff);                         //~v053I~
                        data32segoff=strtol(pc+2,0,16);//conv 0Xxxxxxxxx       //~v053I~
                        if (pc=getfld(buff,3),!pc)                             //~v053I~
                                return maperr(ERR82,buff);                         //~v053I~
                        data32seglen=strtol(pc+2,0,16);//conv 0Xxxxxxxxx       //~v053I~
            continue;   //                                         //~v053I~
                }                                                          //~v053I~
                if (!memcmp(buff,bsssegid,sizeof(bsssegid)-1))             //~v053I~
                {                               //format:".text   Origin  Length"//~v053I~
                        if (pc=getfld(buff,2),!pc)                             //~v053I~
                                return maperr(ERR81,buff);                         //~v053I~
                        bss32segoff=strtol(pc+2,0,16);//conv 0Xxxxxxxxx        //~v053I~
                        if (pc=getfld(buff,3),!pc)                             //~v053I~
                                return maperr(ERR82,buff);                         //~v053I~
                        bss32seglen=strtol(pc+2,0,16);//conv 0Xxxxxxxxx        //~v053I~
            continue;   //                                         //~v053I~
                }                                                          //~v053I~
                if (!memcmp(buff+1,codeendid,sizeof(codeendid)-1)) //*fill*//~v053M~
                if (!linee)     //first time                               //~v053M~
                                linee=Sline;    //end ptr                          //~v053M~
        if (linee)                                                 //~v053R~
                continue;       //no more need                             //~v053R~
        if (!memcmp(buff+1,codesegid,sizeof(codesegid)-1))         //~v053R~
        {                       //format " .text offset length object-name"    //~v053I~
            objsw=1;                                               //~v053I~
                if (!code32sw)          //first object                     //~v053I~
            {                                                      //~v053I~
                code32sw=1;                                        //~v053I~
                lines=Sline;                                       //~v053I~
            }                                                      //~v053I~
                }                                                          //~v053I~
        else                                                       //~v053I~
            objsw=0;                                               //~v053I~
                if (!code32sw)                                             //~v053R~
                continue;                                              //~v053I~
                if (objsw)                                                 //~v053R~
                {                                                          //~v053I~
                        if (pc=getfld(buff,2),!pc)      //offset                   //~v053I~
                                return maperr(ERR83,buff);                         //~v053I~
            memcpy(objstart,pc+2,8);            //save obje start addr //~v053I~
                        code32funcno++;                                        //~v053I~
                }                                                          //~v053I~
        else                                                       //~v053I~
                {                                                          //~v053I~
                        if (pc=getfld(buff,1),!pc)      //offset                   //~v053I~
                                return maperr(ERR84,buff);                         //~v053I~
            if (memcmp(objstart,pc+2,8))        //same start addr as obj//~v053R~
                        code32funcno++;                                    //~v053I~
                                                                   //~v053I~
                }                                                          //~v053R~
        }//fgets                                                       //~v053R~
//printf("text=(%08x,%08x)data=(%08x,%08x),bss=(%08x,%08x)\n",     //~v053R~
//code32segoff,code32seglen,data32segoff,data32seglen,bss32segoff,bss32seglen);//~v053R~
        if (!getstring && ferror(hfile))        //null return and          //~v053I~
        {                                                              //~v053I~
                uerrmsg("%s read error errno=%d",0,Pfilename,errno);       //~v053I~
                return 8;                                                  //~v053I~
        }                                                              //~v053I~
//end of line                                                      //~v053I~
        if (!code32sw)                                                 //~v053I~
                return maperr(ERR85,0);                                        //~v053I~
        if (!Ppepatbl)                                                 //~v053I~
    {                                                              //~v053I~
        if (fclose(hfile))                                         //~v053I~
        {                                                          //~v053I~
                uerrmsg("%s close error",0,Pfilename);                 //~v053I~
                return 24;                                             //~v053I~
        }                                                          //~v053I~
        return 0;                                                  //~v053I~
    }                                                              //~v053I~
        if (fseek(hfile,(long)0,SEEK_SET))//position to input start pos//~v053I~
        {                                                              //~v053I~
                uerrmsg("%s fseek error",0,Pfilename);                     //~v053I~
                return 16;                                                 //~v053I~
        }                                                              //~v053I~
        *Ppepatbl=pepatbl=UALLOCM((UINT)(sizeof(EPATBL)*(code32funcno+1)));//~v053R~
    UALLOCCHK(pepatbl,UALLOC_FAILED);                              //~v053I~
        Sline=0;                                                       //~v053I~
        while(getstring=fgets(buff,MAPRECSZ+1,hfile),getstring) //null return if error or eof//~v053I~
        {                                                              //~v053I~
                if (++Sline==linee)                                        //~v053I~
                        break;                                                 //~v053I~
                if (Sline<lines)                                           //~v053I~
                        continue;                                              //~v053I~
        if (*buff=='\n')                                           //~v053I~
                continue;       //skip null line                           //~v053I~
                if (!memcmp(buff+1,codesegid,sizeof(codesegid)-1))         //~v053R~
                {                                                          //~v053I~
                        if (pc=getfld(buff,2),!pc)      //offset                   //~v053I~
                                return maperr(ERR85,buff);                         //~v053I~
                        if (pc2=getfld(buff,4),!pc2)    //object name          //~v053R~
                                return maperr(ERR86,buff);                         //~v053I~
            pepatblobj=pepatbl;         //save for later addr compare  //~v053I~
                        objsw=1;                                               //~v053I~
                }                                                          //~v053I~
        else                                                       //~v053I~
                {                                                          //~v053I~
                        if (pc=getfld(buff,1),!pc)      //offset                   //~v053I~
                                return maperr(ERR87,buff);                         //~v053I~
                        if (pc2=getfld(buff,2),!pc2)    //func name            //~v053R~
                                return maperr(ERR88,buff);                         //~v053I~
                        objsw=0;                                               //~v053R~
                }                                                          //~v053I~
//printf("pc=%s,pc2=%s\n",pc,pc2);                                 //~v053R~
                pepatbl->addr=strtol(pc+2,0,16);        //offset               //~v053R~
                for(ii=0,pc=pc2;ii<MAPEPANAMESZ-1 && *pc!='\n';ii++,pc++)  //~v053R~
                        pepatbl->funcname[ii]=*pc;                             //~v053R~
                pepatbl->funcname[ii]=0;                                   //~v053R~
        if (!objsw)     //object offset                                //~v053R~
                if (pepatbl->addr==pepatblobj->addr)    //same as object start//~v053R~
            {                                                      //~v053I~
                *pepatblobj=*pepatbl;                              //~v053R~
                pepatbl--;                                         //~v053I~
                code32funcno2--;                                   //~v053I~
            }                                                      //~v053I~
//printf("lines=%d,linee=%d,Sline=%d,%s",lines,linee,Sline,buff);  //~v053R~
//printf("addr=%08x,name=%s\n",(UINT)pepatbl->addr,pepatbl->funcname);//~v053R~
                pepatbl++;                                                 //~v053I~
        code32funcno2++;                                           //~v053I~
        }//read loop                                                   //~v053I~
//printf("funcno=%d,%d\n",code32funcno,code32funcno2);             //~v053R~
    if (code32funcno2!=code32funcno)                               //~v053I~
    {                                                              //~v053I~
                uerrmsg("internal logic err %d and %d\n",0,code32funcno2,code32funcno);//~v053R~
                return 28;                                                 //~v053I~
    }                                                              //~v053I~
        if (fclose(hfile))                                             //~v053I~
        {                                                              //~v053I~
                uerrmsg("%s close error",0,Pfilename);                     //~v053I~
                return 24;                                                 //~v053I~
        }                                                              //~v053I~
//*sort by addr                                                    //~v053I~
        qsort(*Ppepatbl,(UINT)code32funcno,sizeof(EPATBL),uaddrcomp);  //~v053I~
    for (ii=0,pepatbl=*Ppepatbl;ii<code32funcno;ii++,pepatbl++)    //~v053I~
        pepatbl->len=(pepatbl+1)->addr-pepatbl->addr;              //~v053I~
        (pepatbl-1)->len=code32segoff+code32seglen-(pepatbl-1)->addr;  //~v053R~
        *pepatbl->funcname=0;                                          //~v053I~
        pepatbl->len=code32seglen;                                     //~v053I~
    Gpepatbl=*Ppepatbl;     //for uerrexit                         //~v053I~
        return 0;                                                      //~v053I~
}//ufuncmap                                                        //~v053I~
//**********************************************************************//~v053I~
int uaddrcomp(const void *ent1,const void *ent2)                   //~v053I~
{                                                                  //~v053I~
        PEPATBL pept1,pept2;                                           //~v053R~
//*****************                                                //~v053I~
        pept1=(PEPATBL)ent1;                                           //~v053R~
        pept2=(PEPATBL)ent2;                                           //~v053R~
        return pept1->addr - pept2->addr;                              //~v053I~
}//uaddrcomp                                                       //~v053I~
                                                                   //~v053I~
                                                                   //~v053I~
#else                       //not DPMI                             //~v053I~
                                                                   //~v053I~
int ufuncmap(UCHAR *Pfilename,PVOID Pbase,PEPATBL *Ppepatbl)
{
#ifdef DOS
        static UCHAR *mainid=" _main\n";
        static UCHAR *codesegid=" BEGDATA\n";
        static UCHAR *stackid=" STACK ";
                        int  dosstacksw=0;
#else
        #ifdef W32                                                     //~v022I~
                #if (_MSC_VER >= 800)                                      //~v034I~
                static UCHAR *mainid=" _main ";                        //~v034I~
                static UCHAR *codesegid=" .text ";      //vc link          //~v034R~
        #else                                                      //~v034I~
                static UCHAR *mainid=" _main\n";                           //~v022I~
                static UCHAR *codesegid=" _TEXT ";      //borland c v452       //~v022I~
        #endif                                                     //~v034I~
    #else                                                          //~v022I~
        static UCHAR *mainid=" main\n";
        static UCHAR *codesegid=" CODE32 ";
        #endif                                                         //~v022I~
#endif
//*******************
        FILE *hfile;
        PEPATBL pepatbl,prevpepatbl=0;
        int i;                                                      //~5826R~
        int mainctr=0,code32sw=0;
        long code32seglen=0,base;                                  //~v6h7R~
        int code32funcno=0,lines=0,linee;                              //~v028R~
        UCHAR *pc,*pc2,*getstring;                                  //~5826R~
#if (_MSC_VER >= 800)                                              //~v57vI~
        UCHAR *pc3;                                                //~v57vI~
#endif                                                             //~v57vI~
        UCHAR code32segno[5];
        UCHAR buff[MAPRECSZ+1];
//****************************************************************
        *Ppepatbl=0;
        if (hfile=fopen(Pfilename,"r"),!hfile)                         //~v022R~
        {
                uerrmsg("%s Open failed,errno=%d",
                            "%s オープンエラー,errno=%d",Pfilename,errno);
                return 4;
        }
        base=(long)MAKEREALADDR(Pbase);
        Sline=0;                                                       //~v028R~
        while(getstring=fgets(buff,MAPRECSZ+1,hfile),getstring) //null return if error or eof//~5826R~
        {
                Sline++;                                                   //~v028R~
        if (*buff=='\n')                                               //~v028R~
                continue;       //skip null line                           //~v028I~
                if (strstr(buff,codesegid))
                        if (!code32sw)  //first time
                        {
                                code32sw=1;
                                if (pc=getfld(buff,1),!pc)                         //~v022R~
                                        return maperr(ERR81,buff);
#ifdef DOS
                                code32seglen=strtol(pc,&pc2,16);//conv 0Xxxxxxxxx
                                sprintf(code32segno,"%04lX",code32seglen/16);
#else
//for also W32                                                     //~v022I~
                                memcpy(code32segno,pc,5);               //segment no
                                if (pc=getfld(buff,2),!pc)                         //~v022R~
                                        return maperr(ERR82,buff);
                                code32seglen=strtol(pc,&pc2,16);//conv xxxxxxxxH
#endif
                        }
#ifdef DOS
                if (!dosstacksw)        //first time
                        if (strstr(buff,stackid))
                        {
                                dosstacksw=1;
                                if (!(pc=getfld(buff,3)))
                                        return maperr(ERR88,buff);
                                Sdosstacksz=strtol(pc,&pc2,16);//conv xxxxxxxH
                        }
#else
#endif
                if (pc=strstr(buff,mainid),pc)
                        ++mainctr;
        #if (_MSC_VER >= 800)                                      //+v034I~//~v034I~
                if (mainctr==1)                                            //~v034I~
    #else                                                      //+v034I~//~v034I~
                if (mainctr==2)
    #endif                                                     //+v034I~//~v034I~
                {
                        if (!lines)
                                lines=Sline;                                       //~v028R~
                        if (pc=getfld(buff,1),!pc)      //segno:addr               //~v022R~
                                return maperr(ERR83,buff);
        				#if (_MSC_VER >= 800)                      //~v57vI~
                            if (lines==Sline)	//_main line       //~v57vI~
                            {                                      //~v57vI~
                            	base=strtol(pc+5,&pc2,16);//vc6 main offset is not 0//~v57vR~
		                        if (pc3=getfld(buff,3),!pc3)      //segno:addr//~v57vI~
                                	return maperr(ERR83,buff);     //~v57vI~
                            	base=strtol(pc3,&pc2,16)-base;//vc6 main offset is not 0//~v57vI~
                            }                                      //~v57vI~
					    #endif                                     //~v57vI~
#ifdef DOS
                        if (memcmp(pc,code32segno,4)>=0)        //data segment
                                break;
                        if (!(pc=getfld(buff,2)))       //funcname
                                return maperr(ERR84,buff);
                        if (!memcmp(pc,"Abs",3))
                                continue;
#else
//for also W32                                                     //~v022I~
                        if (memcmp(pc,code32segno,5))   //code32 segment
                                break;
#endif
                        code32funcno++;
                }//after second main
        }
        if (!getstring && ferror(hfile))        //null return and       //~5826R~
        {
                uerrmsg("%s read error errno=%d",0,Pfilename,errno);    //~5826R~
                return 8;
        }
        linee=Sline;    //end ptr                                      //~v028R~
//end of line
        if (!code32sw)
                return maperr(ERR85,0);
        if (fseek(hfile,(long)0,SEEK_SET))//position to input start pos
        {
                uerrmsg("%s fseek error",0,Pfilename);
                return 16;
        }
        code32funcno++;         //for stopper entry
        *Ppepatbl=pepatbl=UALLOCM((UINT)(sizeof(EPATBL)*code32funcno));//~5930R~
    UALLOCCHK(pepatbl,UALLOC_FAILED);                           //~5930R~
UTRACEP("malloc pepatbl=%08x\n",pepatbl);                          //~v167I~
//UTRACED("malloc pepatbl=",pepatbl-8,32);                         //~v167R~
        Sline=0;                                                       //~v028R~
        while(getstring=fgets(buff,MAPRECSZ+1,hfile),getstring) //null return if error or eof//~5826R~
        {
                if (++Sline==linee)                                        //~v028R~
                        break;
                if (Sline<lines)                                           //~v028R~
                        continue;
        if (*buff=='\n')                                               //~v028R~
                continue;       //skip null line                           //~v028I~
//printf("lines=%d,linee=%d,Sline=%d,%s",lines,linee,Sline,buff);//@@@@//~v028R~
                if (pc=getfld(buff,1),!pc)      //segno:addr                   //~v022R~
                        return maperr(ERR86,buff);
#ifdef DOS
                pepatbl->addr=strtol(pc,&pc2,16)*16;
                pepatbl->addr+=(strtol(pc+5,&pc2,16)+base);
#else
//for also W32                                                     //~v022I~
                pepatbl->addr=strtol(pc+5,&pc2,16)+base;
#endif
                if (pc=getfld(buff,2),!pc)      //func name;                   //~v022R~
                        return maperr(ERR87,buff);
                if (!memcmp(pc,"Abs",3))
                        continue;
                for(i=0;i<MAPEPANAMESZ-1 && *pc!='\n';i++,pc++)
                        pepatbl->funcname[i]=*pc;
                pepatbl->funcname[i]=0;
                if (pepatbl!=*Ppepatbl) //not firstentry
                        prevpepatbl->len=pepatbl->addr-prevpepatbl->addr;
                prevpepatbl=pepatbl++;
        }//read loop
        if (!getstring && ferror(hfile))                            //~5826R~
        {
                uerrmsg("%s read error errno=%d",0,Pfilename,errno);    //~5826I~
                return 20;
        }

        if (fclose(hfile))
        {
                uerrmsg("%s close error",0,Pfilename);
                return 24;
        }
        *pepatbl->funcname=0;
        pepatbl->len=code32seglen;
        prevpepatbl->len=base+code32seglen-prevpepatbl->addr;
    Gpepatbl=*Ppepatbl;     //for uerrexit                         //~v027I~
        return 0;
}//ufuncmap                                                        //~v022R~
#endif                      //DPMI or not                          //~v053I~

//*******************************************************
//*field serach (delimitted by space)
//*******************************************************
UCHAR *getfld(UCHAR *Pbuff,int Pfldno)
{
        int fldno=0,offset=0;
//*********************:
        while(Pbuff)
        {
                if (*Pbuff==' ')
                        offset=(int)strspn(Pbuff," ");  //search non space
                Pbuff+=offset;
                if (!*Pbuff)
                        return 0;
                if (++fldno==Pfldno)
                        return Pbuff;
                Pbuff=strpbrk(Pbuff," ");       //advance to space
        }
        return 0;
}//getfld

//*******************************************************
//*maperr(map line search err)
//*******************************************************
int maperr(int Prc,UCHAR *Ppbuff)
{
//*********************:
        if (Ppbuff)
                uerrmsg("map line format err detected at line# %d,rc=%d\n--->%s",0,//~v028R~
                        Sline,Prc,Ppbuff);                                     //~v028I~
        else
                uerrmsg("map line format err detected at line# %d,rc=%d\n",0,//~v028R~
                        Sline,Prc);                                            //~v028I~
        return Prc;
}//maperr
//*******************************************************
//*ugetepa
//* search epa table entry containing parm addr
//* parm1:map tbl addr gotten by ufuncmap
//* parm2:instruction addr(for dos seg+off format)
//* return:epa tbl entry addr or 0 if not found
//*******************************************************
PEPATBL ugetepa(PEPATBL Ppepatbl,PVOID Paddr)
{
        PEPATBL pepatbl;
        ULONG   epa,addr;
//*******************:
        addr=MAKEREALADDR(Paddr);
        for(pepatbl=Ppepatbl;*pepatbl->funcname;pepatbl++)
        {
                epa=(ULONG)(pepatbl->addr+pepatbl->len);
                if (addr < epa) //before end addr
                        if (addr>=epa-pepatbl->len)     //after start addr
                                return pepatbl;
                        else
                                return 0;
        }
        return 0;
}//ugetepa

//****************************************************************
//*ufuncpathmsg
//*create function call path table *
//*parm1: map filename
//*parm2: first EBP value if 0,uehpathmsg call point is assumed
//*parm3: first EIP value(for DOS seg+offset format)
//*return:msg buff addr
//****************************************************************
UCHAR *ufuncpathmsg(UCHAR *Pmapfilename,ULONG Pebp,ULONG Paddr)
{
        int msglen;
        UINT *pint;
        PPATHTBL ppathtbl;
        PEPATBL  pepatbl;
static UCHAR *Smsgbuff;
extern int main(int,char*[]);
//******************
        if (!Pebp)
        {
#ifdef  DOS
    #ifdef DPMI                                 //DPMI version                     //~v053I~
                pint=(UINT*)(void*)&Pmapfilename-2;             //addr of pushed ebp//~v053I~
                Pebp=*pint;                             //ebp value        //~v053I~
                Paddr=*(pint+1);                        //near ret addr    //~v053R~
    #else                       //not DPMI                         //~v053I~
                pint=(UINT*)(void*)&Pmapfilename-3;             //addr of pushed ebp
                Pebp=(ULONG)*pint;
                Paddr=(ULONG)*(pint+1)+(((ULONG)*(pint+2))<<16);
    #endif                      //DPMI or not                      //~v053I~
#else
//for also W32, EBP and near RETURN addr                           //~v022I~
                pint=(UINT*)(void*)&Pmapfilename-2;             //addr of pushed ebp
                Pebp=*pint;
                Paddr=*(pint+1);
#endif
        }
        ufuncmap(Pmapfilename,(PVOID)(ULONG)main,&pepatbl);
        ppathtbl=ufuncpathtbl(pepatbl,Pebp,Paddr);
        if (!Smsgbuff)
    {                                                           //~5930I~
                Smsgbuff=UALLOCM(4080);                                 //~5930R~
        UALLOCCHK(Smsgbuff,"");                                 //~5930I~
    }                                                           //~5930I~
        msglen=ufuncpathmsgsub(ppathtbl,Smsgbuff);
        *(Smsgbuff+msglen)=0;
        return Smsgbuff;
}//ufuncpathmsg

//***************************************************
//* ufuncpathmsgsub
//* setup call path function name
//*   parm1:pathtbl
//*   parm2:output buff;
//*  return:msg length
//****************************************************
int ufuncpathmsgsub(PPATHTBL Pppathtbl,UCHAR *Pbuff)
{
        UCHAR *pcurfunc,*msgbuff;
        int   offset=0,ii;               //sprintf %n offset
        UCHAR *constna;
        int dbcssw;
        PPATHTBL ppathtbl;
//*******************
        if (!Pppathtbl)
                return 0;

//      if (dbcssw=udbcschk(0x81),dbcssw)                          //~v150R~
        if (dbcssw=udbcschkcp(),dbcssw)//dbcsenv or cp!=932        //~v150I~
                constna=constnaj;
        else
                constna=constnae;

        for (ppathtbl=Pppathtbl;ppathtbl->ebp;)
                ppathtbl++;
        msgbuff=Pbuff;
        for (ppathtbl--;ppathtbl>=Pppathtbl;ppathtbl--)
        {
                if (!*(pcurfunc=ppathtbl->funcname))
                    pcurfunc=constna;   //if not avail
                sprintf((msgbuff+=offset),msgprotstack,
            ppathtbl->ret,                              //return addr
            ppathtbl->ebp,                              //ebp
            pcurfunc,                             //func name called
            ppathtbl->epa,                              //epa
            &offset);                     //%n output(current offset)
                strcpy((msgbuff+=offset),"  parm=");
                offset=7;
                for (ii=0;ii<MAXPATHPARM;ii++)         //by 4 byte
                {
                        sprintf((msgbuff+=offset)," %08lX%n",               //~5128R~
//                     USTRLOAD(&ppathtbl->parm[ii]),  //4 byte dump   //~v022R~
                       (ULONG)USTRLOAD(&ppathtbl->parm[ii]),  //4 byte dump//~v022I~
                   &offset);             //%n output(current offset)
                }
                *(msgbuff+offset++)='\n';
        }//maxpath to be print
        return (int)((ULONG)msgbuff-(ULONG)Pbuff+offset);
}//ufuncpathmsgsub

//****************************************************************
//*get function call path table *
//*parm1: map filename
//*parm2: first EBP value
//*parm3: first EIP value(abend instruction,for DOS seg+off format)
//*return:path table addr(0 if err)
//****************************************************************
PPATHTBL ufuncpathtbl(PEPATBL Ppepatbl,ULONG Pebp,ULONG Paddr)
{
        ULONG  addr;
        PVOID  pvoid;
        ULONG   ebp,ebpp,pstacktop,pstackend;
        int pathctr,ii,jj;
        PPATHTBL ppathtbl,ppathtbl0;
        PEPATBL  pepatbl;
//***************************
        if (!Ppepatbl)
                return 0;

        ugetstackaddr(&pstacktop,&pstackend);//get stack top,end
        pvoid=&pvoid;
//***********************
//* count avail path depth
//***********************
        for(ebp=Pebp,pathctr=0;VALIDDATA(ebp);ebp=NEXTEBP(pvoid,ebp))
                pathctr++;
        if (!pathctr)
                return 0;

        ppathtbl0=ppathtbl=UALLOCC(1,(UINT)(PATHTBLSZ*(pathctr+1)));//last is stopper//~5930R~
    UALLOCCHK(ppathtbl,0);      //return 0 if alloc failed          //~5930I~
//***********************
//* search func name    *
//***********************
        for(ebp=Pebp,addr=Paddr,ii=0;
                ii<pathctr;
                ii++,ppathtbl++)
        {
                ppathtbl->ebp=ebp;
                if (pepatbl=ugetepa(Ppepatbl,(PVOID)addr),pepatbl)
                {
                        ppathtbl->epa=(ULONG)pepatbl->addr;
                        strncpy(ppathtbl->funcname,pepatbl->funcname,
                                        sizeof(ppathtbl->funcname));
                }
                ebpp=ppathtbl->ebpp=NEXTEBP(pvoid,ebp); //caller ebp
                ebp+=sizeof(UINT);
                if (VALIDDATA(ebp))
                {
                        addr=NEXTPTR(pvoid,ebp);        //seg+offs format
                        ppathtbl->ret=MAKEREALADDR(addr);       //real addr
                        for (jj=0,ebp+=4;jj<MAXPATHPARM;jj++,ebp+=4)
                                if (VALIDDATA(ebp))
                                        ppathtbl->parm[jj]=NEXTPTR(pvoid,ebp);
                                else
                                        break;
                }
                ebp=ebpp;
        }//ii
        return ppathtbl0;
}//ufuncpathtbl

#if defined(DOS) || defined(W32)                                   //~v022R~
#ifdef DPMI                                                        //~v053I~
#else           //no DPMI                                          //~v053I~
//********************************************************************
//*      : usetmainebp                                       *     //+v6h7R~
//* INPUT      :                                                     *
//*     p1         :mai ebp valu
//* OUTPUT     : Sdosmainebp
//* RETURN     : none                                                *
//*    : save main rtn ebp value for ugetstackaddr                 //+v6h7R~
//********************************************************************
void usetmainebp(ULONG Pebp)
{
    if (!Sdosmainebp                                               //~v022I~
    ||   Sdosmainebp>Pebp)                                         //~v022I~
                Sdosmainebp=Pebp;                                          //~v022R~
}//usetmainebp

#endif      //no DPMI                                              //~v053I~
#endif

#if (_MSC_VER >= 800)                                      //+v034I~//~v034I~
//********************************************************************//~v034I~
//*      : ugetmoduledata                                    //~v034I~//+v6h7R~
//* INPUT      :                                                     *//~v034I~
//*     p1:addr of pointer to set text start addr                  //~v034I~
//*     p2:addr of pointer to set text end   addr                  //~v034I~
//*     p3:addr of pointer to set data start addr                  //~v034I~
//*     p4:addr of pointer to set data end   addr                  //~v034I~
//* OUTPUT     : set of pointer                                    //~v034I~
//* RETURN     : rc                                                //~v034I~
//*    : code/data segment data get                        //~v034I~//+v6h7R~
//********************************************************************//~v034I~
int ugetmoduledata(ULONG *Ptexttop,ULONG *Ptextend,ULONG *Pdatatop,ULONG* Pdataend)//~v034I~
{                                                                  //~v034I~
    HMODULE hm;                                                    //~v034I~
    PIMAGE_DOS_HEADER pidh;                                        //~v034I~
    PIMAGE_NT_HEADERS pinh;                                        //~v034I~
    PIMAGE_OPTIONAL_HEADER pioh;                                   //~v034I~
    ULONG base;                                                    //~v034I~
//*********************                                            //~v034I~
    hm=GetModuleHandle(NULL);           //current module               //~v034I~
    if (hm==NULL)                                                  //~v034I~
                return  uerrapi1("GetModuleHandle","NULL",GetLastError()); //~v034I~
        pidh=(PIMAGE_DOS_HEADER)(void*)hm;                             //~v034I~
    pinh=(PIMAGE_NT_HEADERS)((ULONG)pidh+pidh->e_lfanew);       //offset of nt headers//~v034I~
    pioh=&pinh->OptionalHeader;                                    //~v034I~
        base=pioh->ImageBase;                                          //~v034I~
    *Ptexttop=base+pioh->BaseOfCode;                               //~v034I~
    *Ptextend=*Ptexttop+pioh->SizeOfCode;                          //~v034I~
    *Pdatatop=base+pioh->BaseOfData;                               //~v034I~
    *Pdataend=*Pdatatop+pioh->SizeOfInitializedData+pioh->SizeOfUninitializedData;//~v034I~
    return 0;                                                      //~v034I~
}//ugetmoduledata                                                  //~v034I~
                                                                   //~v034I~
//********************************************************************//~v034I~
//*      : ugettopheap                                       //~v034I~//+v6h7R~
//* INPUT      :                                                     *//~v034I~
//*     p1:addr of area to set heap handle                         //~v034I~
//*     p1:addr of area to set offset of next ptr field            //~v034I~
//* OUTPUT     : heap handle                                       //~v034I~
//* RETURN     : rc                                                //~v034I~
//*    : get top heap handle                               //~v034I~//+v6h7R~
//********************************************************************//~v034I~
int ugettopheap(void **Ppheaph,int *Ppnextoff)                     //~v034R~
{                                                                  //~v034I~
#define HEAPHSIGN  0x4948   //Heap header signature[HI]            //~v034M~
#define SIGNWORDR  0x72     //not debug version Heap header signature offset//~v034M~
#define NEXTHEAPR  0x48     //not debug version nextHeap offset    //~v034I~
#define NEXTHEAPD  0x68     //    debug version nextHeap offset    //~v034I~
        HANDLE heaph;                                                  //~v034I~
//*********************                                            //~v034I~
        heaph=HeapCreate(0,0x1000,0x1000);      //a 4k page                //~v034I~
    if (heaph==NULL)                                               //~v034I~
                return  uerrapi1("HeapCreate","ugettopheap",GetLastError());//~v034I~
    if ((*(USHORT*)((ULONG)heaph+SIGNWORDR))==HEAPHSIGN)           //~v034R~
        *Ppnextoff=NEXTHEAPR;                                      //~v034I~
        else                                                           //~v034I~
        *Ppnextoff=NEXTHEAPD;                                      //~v034I~
        *Ppheaph=(void*)(*(ULONG*)((ULONG)heaph+*Ppnextoff));          //~v034I~
    if (HeapDestroy(heaph)==FALSE)                                 //~v034I~
                return  uerrapi1("HeapDestroy","ugettopheap",GetLastError());//~v034I~
    return 0;                                                      //~v034I~
}//ugettopheap                                                     //~v034I~
                                                                   //~v034I~
#else                                                      //+v034I~//~v034I~
#endif                                                     //+v034I~//~v034I~
                                                                   //~v034I~
#ifdef DPMI                                     //DPMI version                         //~v053I~
//********************************************************************//~v053I~
//*      : ugetdataseg                                         *//~v053R~//+v6h7R~
//* INPUT      :                                                     *//~v053I~
//*     p1:addr of pointer to set data seg top addr                           *//~v053R~
//*     p2:addr of pointer to set data seg end addr                           *//~v053R~
//*     p3:addr of pointer to set bss  seg top addr                //~v053I~
//*     p4:addr of pointer to set bss  seg end addr                //~v053I~
//*     p5:addr of pointer to set ds base                          //~v053I~
//*     p6:addr of pointer to set ds base+limit                    //~v053I~
//* OUTPUT     : set of pointer                                    //~v053I~
//* RETURN     : none                                                *//~v053I~
//*    : data seg addr get(data,bss,ds limit)              //~v053R~//+v6h7R~
//********************************************************************//~v053I~
void ugetdataseg(ULONG *Ppdatasegtop,ULONG *Ppdatasegend,          //~v053R~
                 ULONG *Ppbsssegtop,ULONG *Ppbsssegend,            //~v053I~
                 ULONG *Ppdsbase,ULONG *Ppdsend)                   //~v053R~
{                                                                  //~v053I~
//***********************                                          //~v053I~
        *Ppdatasegtop=data32segoff;                                    //~v053I~
        *Ppdatasegend=data32segoff+data32seglen;                       //~v053R~
        *Ppbsssegtop=bss32segoff;                                      //~v053R~
        *Ppbsssegend=bss32segoff+bss32seglen;                          //~v053R~
    __dpmi_get_segment_base_address((int)_my_ds(),Ppdsbase);       //~v053R~
        *Ppdsend=*Ppdsbase+__dpmi_get_segment_limit(_my_ds())+1;       //~v053R~
    return;                                                        //~v053I~
}//ugetdataseg                                                     //~v053R~
#else                       //not DPMI                             //~v053I~
#endif                      //DPMI or not                          //~v053I~
#ifndef MGW32                                                      //~v5ncI~
//********************************************************************
//*      : ugetstackaddr                                       *   //+v6h7R~
//* INPUT      :                                                     *
//*     p1:addr of pointer to set top addr                           *
//*     p2:addr of pointer to set end addr                           *
//* OUTPUT     : set of pointer
//* RETURN     : none                                                *
//*    : stack addr get(start/end)                                 //+v6h7R~
//********************************************************************
void ugetstackaddr(ULONG *pstacktop,ULONG *pstackend)
{
#ifdef DOS
    #ifdef DPMI                                 //DPMI version                     //~v053I~
        extern int _stklen;                                        //~v053I~
        extern int __djgpp_stack_limit;                            //~v053I~
//*********************                                            //~v053I~
        *pstacktop=__djgpp_stack_limit;                            //~v053I~
        *pstackend=__djgpp_stack_limit+_stklen;                    //~v053I~
    #else                       //not DPMI                         //~v053I~
        ULONG *stackptr;
        ULONG addr;
//*********************
        stackptr=&addr;
        *pstacktop=FP_OFF(stackptr);
        *pstackend=Sdosmainebp+2+4+4+4+4+4;     //ebp,ret,argctr,argptr,envptr
    #endif                      //DPMI or not                      //~v053I~
        return;
#else
        #ifdef W32      //data and stack is not continued area         //~v022R~
                #if (_MSC_VER >= 800)                                      //~v034I~
                        ULONG stackhigh,stacklow;                              //~v034I~
//*********************                                            //~v034I~
                _asm {                                                 //~v034I~
                mov eax,fs:[4]                                     //~v034I~
                mov stackhigh,eax                                  //~v034I~
                mov eax,fs:[8]                                     //~v034I~
                mov stacklow,eax                                   //~v034I~
            }                                                      //~v034I~
            *pstacktop=stacklow;                                   //~v034I~
            *pstackend=stackhigh;                                  //~v034I~
        #else                                                      //~v034I~
    //*********************                                        //~v022I~
//  printf("ugetstackaddr curr top=%08x,end=%08x\n",&pstacktop,Sdosmainebp);//~v022R~
        *pstacktop=(ULONG)(&pstacktop) & 0xfffff000;    //4k boundary//~v022R~
                *pstackend=Sdosmainebp+4+4+4+4+4+4;     //ebp,ret,argctr,argptr,envptr//~v022I~
//  printf("ugetstackaddr boundary top=%08x,end=%08x\n",*pstacktop,*pstackend);//~v022R~
        return;                                                    //~v022I~
        #endif                                                     //~v034I~
    #else                                                          //~v022R~
  PTIB       ptib;  //system c.b tib
  PPIB       ppib;  //system c.b tib
  APIRET apiret;
  ULONG  len,memallocflg,scanlen; //for stack chk
//***********************
  DosGetInfoBlocks(&ptib,&ppib);
  *pstacktop=(ULONG)ptib->tib_pstack;
  len=(*pstackend=(ULONG)ptib->tib_pstacklimit)-(ULONG)ptib->tib_pstack;
  while(len)                              //until zero
  {
    scanlen=len;
    apiret=umemchk(*pstacktop,        //in:base addr
                        &scanlen,           //in:size,out:scaned size
                    &memallocflg);      //out:attr of scaned range page
    if (apiret)   //=ERROR_INVALID_ADDRESS)
        uerrexit("ugetstackaddr:umemchk failed,rc=%d",0,apiret);

    if (  (memallocflg & PAG_COMMIT)    //commited
       && !(memallocflg & PAG_GUARD)     //not gurad page
       )
      break;

    *pstacktop=*pstacktop + scanlen;     //next scan page addr
    len-=scanlen;

  } //until len=0
        return;

        #endif                                                         //~v022I~
#endif
}//ugetstackaddr
#endif //MINGW                                                     //~v5ncR~
#ifdef DOS
#ifdef DPMI					//DPMI version                         //~v053I~
//**********************************************                   //~v053I~
//*memory accessible test                                          //~v053I~
//*parm 1:addr to be chk                                           //~v053I~
//*parm 2:storage len                                              //~v053I~
//*parm 3:storage attr                                             //~v053I~
//ret   0:fully ok,1:len changed,4 all out of range                //~v108I~
//**********************************************                   //~v053I~
UINT umemchk(ULONG Paddr,ULONG *Ppsize,ULONG *Ppattr)              //~v053I~
{                                                                  //~v053I~
        unsigned long cslim,dslim,sslim;                           //~v108R~
        unsigned long enda,lowest;                                 //~v108R~
//      long csbase,dsbase,ssbase;                                 //~v053I~
        UINT apiret;                                               //~v053I~
//******************                                               //~v053I~
//  __dpmi_get_segment_base_address((int)_my_cs(),&csbase);        //~v053I~
        cslim=__dpmi_get_segment_limit(_my_cs())+1;                //~v053R~
//  __dpmi_get_segment_base_address((int)_my_ds(),&dsbase);        //~v053I~
        dslim=__dpmi_get_segment_limit(_my_ds())+1;                //~v053R~
//  __dpmi_get_segment_base_address((int)_my_ss(),&ssbase);        //~v053I~
        sslim=__dpmi_get_segment_limit(_my_ss())+1;                //~v053R~
    enda=Paddr+*Ppsize;                                            //~v053I~
//  if (Paddr>=csbase && enda<=cslim                               //~v053I~
//  ||  Paddr>=dsbase && enda<=dslim                               //~v053I~
//  ||  Paddr>=ssbase && enda<=sslim)                              //~v053I~
    if (enda<=dslim && enda<=cslim && enda<=sslim)                 //~v118R~
    {                                                              //~v053I~
        apiret=0;                                                  //~v053I~
        *Ppattr=PAG_COMMIT;                                        //~v053I~
    }                                                              //~v053I~
    else                                                           //~v053I~
      if (Paddr<=dslim && Paddr<=cslim && Paddr<=sslim)            //~v118R~
      {                                                            //~v108I~
      	lowest=dslim;                                              //~v108I~
        if (lowest>cslim)                                          //~v108I~
        	lowest=cslim;                                          //~v108I~
        if (lowest>sslim)                                          //~v108I~
        	lowest=sslim;                                          //~v108I~
		*Ppsize=lowest-Paddr;                                      //~v108I~
        apiret=1;                                                  //~v108I~
      }                                                            //~v108I~
      else                                                         //~v108I~
        apiret=4;                                                  //~v053I~
    return apiret;                                                 //~v053I~
}//umemchk                                                         //~v053I~
#else                       //not DPMI                             //~v053M~
#endif                      //DPMI or not                          //~v053I~
                                                                   //~v053I~
#else

//**********************************************
//*memory accessible test
//*parm 1:addr to be chk
//*parm 2:storage len
//*parm 3:storage attr
//ret   0:fully ok,1:(w95)len changed,4 all out of range           //~v173I~
//**********************************************
UINT umemchk(ULONG Paddr,ULONG *Ppsize,ULONG *Ppattr)
{
        #ifdef W32                                                     //~v022I~
//      #ifdef NT                                                      //~v034R~
        #if (_MSC_VER >= 800)                                      //~v034R~
            #define PAGESZ 4096                                    //~v034I~
            ULONG len,chklen,maxlen;                               //~v034I~
            char *pc;                                              //~v034I~
        #else                                                      //~v034R~
            ULONG wpul,stackbase;                                  //~v034I~
                extern int main(int,char*[]);                              //~v022M~
                extern int _terminate(void);                               //~v022M~
                extern ULONG _stkbase;                                     //~v022I~
                extern ULONG _heaps[2];                                    //~v022R~
                                                                   //~v022I~
        static ULONG Stextbase;                                    //~v022I~
        static ULONG Stextend;                                     //~v022I~
        static ULONG Sdatabase;                                    //~v022I~
        static ULONG Sdataend;                                     //~v022I~
        static ULONG Sstackend;                                    //~v022I~
        #endif                                                     //~v034M~
        #else                                                          //~v022I~
            ULONG reslen,reqlen,reqleni,seglen,validlen,addr;      //~v206I~
        #endif                                                         //~v022I~
        UINT apiret;
//******************
        #ifdef W32                                                     //~v022M~
//  #ifdef NT                                                      //~v034R~
        #if (_MSC_VER >= 800)                                          //~v034I~
        maxlen=*Ppsize;                                            //~v034I~
UTRACEP("umemchk start addr=%08x,len=%08x\n",Paddr,maxlen);        //~v167R~
        for (pc=(char*)Paddr,len=0;len<maxlen;len+=chklen,pc+=chklen)//~v034R~
        {                                                          //~v034I~
                if (!len)       //firsttime                                //~v034I~
            {                                                      //~v034I~
                        chklen=PAGESZ-((ULONG)pc&0xfff);        //on first page//~v034I~
                if (chklen>maxlen)                                 //~v034I~
                        chklen=maxlen;                                 //~v034I~
                }                                                      //~v034I~
            else                                                   //~v034I~
            {                                                      //~v034I~
                chklen=maxlen-len;                                 //~v034I~
                    if (chklen>PAGESZ)                                 //~v034I~
                        chklen=PAGESZ;                                 //~v034I~
                }                                                      //~v034I~
UTRACEP("before IsBadReadPtr %08x\n\n",pc);                        //~v167R~
                if (IsBadReadPtr(pc,1)==TRUE)   //bad ptr              //~v034I~
                break;                                             //~v034I~
UTRACEP("after IsBadReadPtr %08x\n\n",pc);                         //~v167R~
        }                                                          //~v034I~
UTRACEP("after all len=%08x,maxlen=%08x\n\n",len,maxlen);          //~v167R~
        *Ppsize=len;                                               //~v034I~
        if (len==maxlen)                                           //~v034I~
        {                                                          //~v034I~
                apiret=0;                                              //~v034I~
            *Ppattr=PAG_COMMIT;                                    //~v034I~
                }                                                          //~v034I~
        else                                                       //~v034I~
            if (len)                                               //~v173I~
                apiret=1;                                          //~v173R~
            else                                                   //~v173I~
                apiret=4;                                              //~v034R~
        #else                                                          //~v022I~
        if (!Stextbase) //first time                               //~v022I~
        {                                                          //~v022I~
                        ugetstackaddr(&wpul,&Sstackend);                       //~v022R~
                Stextbase =(ULONG)main & 0xffff0000;    //64k boundary //~v022R~
                Stextend  =((ULONG)_terminate+4095) & 0xfffff000;       //4k boundary//~v022R~
                Sdatabase =(ULONG)&Stextbase & 0xffff0000;      //64k boundary//~v022R~
                Sdataend  =((ULONG)&_stkbase+4095) & 0xfffff000;        //4k boundary//~v022I~
                Sstackend =(Sdosmainebp+4095) & 0xfffff000;             //4k boundary//~v022I~
        }                                                          //~v022I~
        wpul=Paddr+*Ppsize;                                        //~v022I~
        stackbase=(ULONG)&Paddr & 0xfffff000;   //4k boundary of stack//~v022I~
        if (Paddr>=Stextbase  && wpul<=Stextend                    //~v022R~
        ||  Paddr>=Sdatabase  && wpul<=Sdataend                    //~v022R~
        ||  Paddr>=stackbase  && wpul<=Sstackend                   //~v022R~
        ||  Paddr>=_heaps[0]  && wpul<=_heaps[0]+_heaps[1])        //~v022R~
        {                                                          //~v022I~
                apiret=0;                                              //~v022R~
            *Ppattr=PAG_COMMIT;                                    //~v022I~
                }                                                          //~v022I~
                else                                                       //~v022I~
                apiret=4;                                              //~v022I~
//      printf("memchk addr=%08x,len=%08x,rc=%d\n",Paddr,*Ppsize,apiret);//~v022R~
        #endif                                                         //~v022I~
        #else                                                          //~v022M~
        validlen=0;                                                //~v206I~
      for (reslen=*Ppsize,addr=Paddr;reslen;)                      //~v206I~
      {                                                            //~v206I~
      	seglen=((addr+0x10000) & 0xffff0000)-addr;		           //~v206R~
        if (seglen>reslen)                                         //~v206I~
        	reqlen=reslen;       //in the segment                  //~v206I~
        else                                                       //~v206I~
        	reqlen=seglen;       //up to segnment                  //~v206I~
        reqleni=reqlen;			//save input value                 //~v206R~
//      apiret=DosQueryMem((PVOID)Paddr,    /*chk start addr*/     //~v206R~
        apiret=DosQueryMem((PVOID)addr,    /*chk start addr*/      //~v206I~
//                      Ppsize,  /*in:size,out:scaned size*/       //~v206R~
                        &reqlen, /*in:size,out:scaned size*/       //~v206I~
                        Ppattr); /*out:attr of scaned range page*/
    if (apiret && apiret!=ERROR_INVALID_ADDRESS)/*api failed*/
                uerrexit("DosQueryMem failed,rc=%d,addr=%08X,len=%08X", //~5128R~
                                0,
                                apiret,Paddr,*Ppsize);
        validlen+=reqlen;                                          //~v206I~
        reslen-=reqlen;                                            //~v206I~
        addr+=reqlen;                                              //~v206I~
        if (reqleni!=reqlen)                                       //~v206I~
            break;                                                 //~v206I~
                                                                   //~v206I~
      }                                                            //~v206I~
      	*Ppsize=validlen;	//return continuous page over seg boundary//~v206R~
        #endif          //OS/2                                             //~v022M~
        return apiret;
}//umemchk

//**********************************************                   //~v046I~
//*search commit page                                              //~v046I~
//*parm 1:addr to be chk start                                     //~v046I~
//*parm 2:chk len                                                  //~v046I~
//*retern:output first commit page addr                            //~v046R~
//**********************************************                   //~v046I~
void *umemsrch(void *Paddr,ULONG Ppsize)                           //~v046R~
{                                                                  //~v046I~
        #ifdef W32                                                     //~v046I~
        #else                                                          //~v046I~
                ULONG apiret,attr,len;                                     //~v046R~
    #endif                                                         //~v046I~
    char *pc,*pce;                                                 //~v046I~
//******************                                               //~v046I~
        pc=(char*)(((ULONG)Paddr>>12)<<12);                            //~v046R~
    if (Ppsize)                                                    //~v046I~
            pce=(char*)Paddr+Ppsize;                                   //~v046I~
        else                                                           //~v046I~
        pce=(char*)-1;                                             //~v046I~
    while(pc<pce)                                                  //~v046I~
    {                                                              //~v046I~
        #ifdef W32                                                     //~v046I~
                if (IsBadReadPtr(pc,1)==FALSE)  //ok ptr                   //~v046I~
                return pc;                                             //~v046R~
        #else                                                          //~v046I~
        len=1;                                                     //~v046I~
                apiret=DosQueryMem((PVOID)Paddr,    /*chk start addr*/     //~v046I~
                        &len,  /*in:size,out:scaned size*/         //~v046I~
                        &attr); /*out:attr of scaned range page*/  //~v046I~
        if (apiret && apiret!=ERROR_INVALID_ADDRESS)/*api failed*/ //~v046I~
                uerrexit("DosQueryMem failed,rc=%d,addr=%08X,len=%08X",//~v046I~
                                0,                                             //~v046I~
                                        apiret,Paddr,len);                             //~v046I~
        if (attr&PAG_COMMIT)                                       //~v046I~
                return pc;                                             //~v046R~
        #endif          //OS/2                                             //~v046I~
        pc+=4096;                                                  //~v046I~
    }                                                              //~v046I~
    return 0;                                                      //~v046I~
}//umemsrch                                                        //~v046I~
                                                                   //~v046I~
#endif
