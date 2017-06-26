//*CID://+v6G3R~:                              update#=  237;      //~v6G3R~
//*************************************************************
//*uerrexit/uerrmsg/uerrexit_init/uerrmsg_init                     //~v5nnR~
//*************************************************************
//v6G3:161212 (Win10) missing error.h , use winerror.h             //~v6G3I~
//v6m2:130725 (BUG)EBC2ASC_IBM(x20) and UCVEXTO_TOUTF8 conflict occured//~v6m2I~
//            xprint ucvebc3_b2m translate to utf8 when no cfg found(default IBM option)//~v6m2I~
//            IBM/NEC is for the case of using internal mapp       //~v6m2I~
//v6j0:121102 for xcifb; -DNOCURSES -DXSUB                         //~v6j0I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6hd:120616 for VC6:/W4 warning(C4189)                           //~v6hdI~
//v5nD:090329 S390 support                                         //~v5nDI~
//v5nx:081129 avoid redundant link; utrace:no MTTRACE; split to utils.c for independent usage(no ar to user.lib)//~v5nnI~
//*************************************************************
#include <time.h>
#include <sys/timeb.h>                                             //~v324I~
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
                                                                   //~v5j3I~
#include <errno.h>                                                 //~v5j3I~
#ifdef UNX                                                         //~v324M~
#else      //!UNX                                                  //~v324M~
                                                                   //~v324I~
#include <conio.h>                                                 //~v5nxI~
                                                                   //~v5nxI~
#ifdef DOS
#include <dos.h>        //for uvio.h                               //~v060M~
#else
  #ifdef W32                                                       //~v053I~
   #ifndef MGW32                                                   //~v5ncI~
#ifdef WIN10                                                   //+v6BkI//+v6G3M~
	#include <winerror.h>                                          //+v6G3M~
#else                                                              //+v6G3M~
    #include <error.h>                                             //~v5iyI~
#endif                                                             //+v6G3I~
   #endif //!MGW32                                                 //~v5ncI~
#define _WINERROR_      //protect winerror.h(partialy duplicated definie with error.h)//~v5iyR~
    #include <windows.h>                                           //~v175I~
  #else                                                            //~v053I~
    #define INCL_BASE                                              //~v060R~
    #include <os2.h>                                               //~v060R~
  #endif                                                           //~v053I~
#endif
#endif  //!UNX                                                     //~v324I~
//*******************************************************
#include <ulib.h>
                                                                   //~v060I~
#define GBL_UERR			//generate gbl variable at uerr.h      //~v060I~
#include <uerr.h>
                                                                   //~v060I~
//#include <udbcschk.h>                                            //~v5nxR~
#include <udbcschk.h>                                              //~v6j0I~
                                                                   //~v324I~
#ifdef UNX                                                         //~v324R~
#include <uviol.h>                                                 //~v324I~
#include <ukbdl.h>                                                 //~v39bR~
#include <uunxsub.h>                                               //~v363I~
#else                                                              //~v324I~
//#include <ufuncmap.h>                                            //~v5nxR~
#endif  //!UNX                                                     //~v324I~
                                                                   //~v324I~
//#include <upopup.h>                                              //~v5nxR~
//#include <uvio.h>                                                //~v5nxR~
#include <utrace.h>                                                //~v170I~
//#include <ualloc.h>                                              //~v5nxR~
#include <uedit.h>                                                 //~v5nxR~
//#ifdef LNX                                                       //~v5nxR~
//    #include <ucvucs.h>                                          //~v5nxR~
//#else                                                            //~v5nxR~
//    #include <ucvucs.h>                                          //~v5nxR~
//#endif                                                           //~v5nxR~
//#include <udos.h>       //udosiswinnt                            //~v5nxR~
//#ifdef DOS                                                       //~v5nxR~
//    #ifdef DPMI                 //DPMI version                   //~v5nxR~
//        #include <ueh.h>                                         //~v5nxR~
//        #include <udpmisub.h>                                    //~v5nxR~
//    #else                       //not DPMI                       //~v5nxR~
//    #endif                      //DPMI or not                    //~v5nxR~
//#include <uehdump.h>                                             //~v5nxR~
//#else                                                            //~v5nxR~
//    #ifdef W32                                                   //~v5nxR~
//        #include <ukbd.h>     //uget/setconsolemode              //~v5nxR~
//        #include <ukbdw.h>     //uget/setconsolemode             //~v5nxR~
//    #endif                                                       //~v5nxR~
//#endif                                                           //~v5nxR~
//#include <uproc2.h>                                              //~v5nxR~
//#include <utf.h>                                                 //~v5nxR~
//#include <ucvext.h>                                              //~v5nxR~
#include <ucvext.h>                                                //~v6j0I~
#include <ucvebc.h>                                                //~v6m2I~
#include <utils.h>                                                 //~v5nxI~
//*******************************************************
#define MAXPARM   10
#define MAXTITLE    64
#define MAXMSGLL  MAX_UERRMSGLL                                    //~v5j3R~
#define UERRMSG_MAXPARM   10                                       //~v5nDI~
//*******************************************************
//*errmsg and exit
//*******************************************************
//#ifdef DOS                                                       //~v5nxR~
//    #ifdef DPMI                 //DPMI version                   //~v5nxR~
//    #else                       //not DPMI                       //~v5nxR~
//#ifdef DOSDUMP                                                   //~v5nxR~
//extern  PEPATBL Gpepatbl;       //for uerrexit                   //~v5nxR~
//#endif                                                           //~v5nxR~
//    #endif                      //DPMI or not                    //~v5nxR~
//#endif                                                           //~v5nxR~
//*******************************************************          //~v027I~
static int  Sbellopt=1;                                            //~v293R~
//static int *Spbellctr;                                             //~v297I~//~v5nxR~
//static int  Sbellctr=0;                                            //~v50VR~//~v5nxR~
//static struct timeb Sbelltime;                                     //~v297R~//~v5nxR~
                                                                   //~v297I~
//static int  Smsgsetflag=0;                                       //~v5nxR~
static int  Smsgsetflag=0;                                         //~v6j0I~
static int 	Smsgcatsw=0;			//msg concat sw                //~v200I~
static int  Suerrexitopt=0;                                        //~v191I~
static char S_msgsave[MAXMSGLL];                                   //~v5mKR~
static char *Smsgsave=S_msgsave;                                   //~v5mKR~
static int Smaxmsgll=MAXMSGLL;                                     //~v5mKR~

//static char  Spopupsw;      //popup msg use sw                  //~5902I~//~v5nxR~
static int   Suerropt; 		 //uerrmsg option(english forc)     //~5B11I~
static int   Sinit1=0;		//init called sw
static FILE *Shandle1;
static char  Stitle1[MAXTITLE]="";
static int   Sinit2=0;		//init called sw
static FILE *Shandle2;
static char  Stitle2[MAXTITLE]="";
static UEXITFUNC *Sexitfunc;
//static UPOPUPMSG *Supopupmsg;   //upopupmsg func addr            //~v5nxR~
static void *Sexitparm;
//static UCHAR Sexitmapfile[_MAX_PATH];                              //~v101R~//~v5nxR~
//****************************
static unsigned char Sattr2='\x17';	//default:white char on blue back ground
//*******************************************************          //~v293I~
//*alarm option                                                    //~v293I~
//*parm1:beep option 0:off else on                                 //~v293I~
//*retrn:previous option value                                     //~v293I~
//*******************************************************          //~v293I~
int ubell_init(int Popt)                                           //~v293I~
{                                                                  //~v293I~
	int prev;                                                      //~v293I~
//****************	                                               //~v293I~
	prev=Sbellopt;                                                 //~v293I~
    Sbellopt=Popt;                                                 //~v293I~
    return prev;                                                   //~v293R~
}//ubell_init                                                      //~v293I~
//*******************************************************
//*alarm 
//*******************************************************
void ubell(void)
{
#if defined(DOS) && !defined(DPMI)                                 //~v297I~
	#define RET_ADDR_POS    6	//ret addr pos(size of ULONG+BP(2))//~v297I~
#else                                                              //~v297I~
	#define RET_ADDR_POS    8   //return addr pos(size of ULONG+BP(4))//~v297I~
#endif                                                             //~v297I~
                                                                   //~v297I~
#ifdef DPMI                                                        //~v176M~
	union REGS regs;                                               //~v176M~
#else                                                              //~v176I~
//    #ifdef W32                                                     //~v177I~//~v5nxR~
//        int mode;                                                  //~v177I~//~v5nxR~
//    #endif                                                         //~v177I~//~v5nxR~
#endif                                                             //~v176I~
#define UBELL_LIMIT 500     //ms                                   //~v530R~
//  int sec,ms;                                                    //~v530R~//~v5nxR~
//*****************
    if (!Sbellopt)                                                 //~v293I~
        return;                                                    //~v293I~
//    if (Spbellctr)      //bellctr chk required                   //~v5nxR~
//    {                                                            //~v5nxR~
//        int   oldctr;                                            //~v5nxR~
//        struct timeb oldtime;                                    //~v5nxR~
//                                                                 //~v5nxR~
//        oldctr=Sbellctr;                                         //~v5nxR~
//        Sbellctr=*Spbellctr;                                     //~v5nxR~
//        memcpy(&oldtime,&Sbelltime,sizeof(oldtime));             //~v5nxR~
//        ftime(&Sbelltime);                                       //~v5nxR~
//        if (Sbellctr==(oldctr+1)    //cont key down              //~v5nxR~
//           )                                                     //~v5nxR~
//        {                                                        //~v5nxR~
//            ms=Sbelltime.millitm-oldtime.millitm; //milisec      //~v5nxR~
//            sec=(int)(Sbelltime.time-oldtime.time);     //in a second//~v5nxR~
//            if (ms<0)                                            //~v5nxR~
//            {                                                    //~v5nxR~
//                sec--;                                           //~v5nxR~
//                ms+=1000;                                        //~v5nxR~
//            }                                                    //~v5nxR~
//            if (!sec && ms<UBELL_LIMIT)                          //~v5nxR~
//                return;                                          //~v5nxR~
//        }                                                        //~v5nxR~
//    }                                                            //~v5nxR~
#ifdef W32                                                         //~v175I~
//  if (udosiswinnt())                                             //~v5nxR~
//    Beep(400,100);  //for NT frequency and duration(ms),for W95 it is ignored//~v5nxR~
//  else                                                           //~v5nxR~
//  {                                                              //~v5nxR~
//    mode=ugetconsolemode(1);     //stdout console mode           //~v5nxR~
//    if (mode & ENABLE_PROCESSED_OUTPUT)//avail bell,cr,lf,bs     //~v5nxR~
      putch(7);                                                    //~v177I~
//    else                                                         //~v5nxR~
//    {                                                            //~v5nxR~
//        usetconsolemode(1,mode | ENABLE_PROCESSED_OUTPUT);     //stdout console mode//~v5nxR~
//        putch(7);                                                //~v5nxR~
//        usetconsolemode(1,mode);     //stdout console mode       //~v5nxR~
//    }                                                            //~v5nxR~
//  }//win95                                                       //~v5nxR~
#else                                                              //~v175I~
  #ifdef DPMI                                                      //~v176I~
    regs.h.ah = 0x0e;     /* teletype write */                     //~v176I~
    regs.h.al = 0x07;     /* bell,it is not displayed like as CR,LF,BS *///~v176I~
    udpmiint86(0x10,&regs,&regs);                                  //~v176I~
  #else                                                            //~v176I~
    #ifdef UNX	                                                   //~v324I~
//      uviol_beep();       //use ncurses                          //~v5nxR~
    	printf("\a\n");		//0x07                                 //~v5nnI~
    #else                                                          //~v324I~
    putch(7);                                                      //~v178I~
    #endif                                                         //~v324I~
  #endif                                                           //~v176I~
#endif                                                             //~v175I~
	return;
}
//******************************************************
void uerrexit_init(char *Ptitle,FILE *Poutput,char *Pmapfile,UEXITFUNC *Pexitfunc,void *Pexitparm)
{
//****************************
    Sinit1=1;		//init called sw
	if (Ptitle)
		strcpy(Stitle1,Ptitle);
	else
		*Stitle1=0;
	Shandle1=Poutput;
	Sexitfunc=Pexitfunc;
//    if (Pmapfile)                                                //~v5nxR~
//        strncpy(Sexitmapfile,Pmapfile,_MAX_PATH-1);                //~v101R~//~v5nxR~
//    else                                                         //~v5nxR~
//        *Sexitmapfile=0;                                         //~v5nxR~
	Sexitparm=Pexitparm;
	return;
}//errexit_init                                                 //~5826R~

//*********************************************************************//~v191I~
//*set uerrexit option                                             //~v191I~
//*********************************************************************//~v191I~
void uerrexit_optinit(int Popt)                                    //~v191I~
{                                                                  //~v191I~
//****************************                                     //~v191I~
    Suerrexitopt=Popt;                                             //~v191I~
	return;                                                        //~v191I~
}//uerrexit_optinit                                                //~v191I~
//*********************************************************************//~v60bI~
//*set uerrexit option                                             //~v60bI~
//*********************************************************************//~v60bI~
int uerrsetopt2(unsigned int Pon,unsigned int Poff)                //~v60bI~
{                                                                  //~v60bI~
//****************************                                     //~v60bI~
    Guerropt2|=Pon;                                                //~v60bR~
    Guerropt2&=~(Poff);                                            //~v60bR~
	return (int)Guerropt2;                                         //~v5nnR~
}//uerrsetopt2                                                     //~v60bI~
//******************************************************
//* msg and exit
//******************************************************
void uerrexit(char *Pemsg ,char *Pjmsg,... )
{
static char Sentrysw=0;                                            //~v50VR~
//  unsigned long *parm;                                           //~v5nDR~
//	unsigned long parm[UERRMSG_MAXPARM];                           //~v5nDI~//~v6hhR~
	ULPTR         parm[UERRMSG_MAXPARM];                           //~v6hhR~
	char *pmsg;                                                    //~v324R~
#ifndef UNX                                                        //~v324I~
  #ifndef MGW32                                                    //~v5ncI~
//	char *ppathmsg=0;                                              //~v324I~//~v6hdR~
  #endif                                                           //~v5ncI~
#endif //!UNX                                                      //~v324I~
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053I~
    #else                       //not DPMI                         //~v053I~
        USHORT segcs,segds,segss;                                  //~v070I~
    char *abinfmsg[2];                                             //~v027M~
	char dumpfnm[_MAX_PATH];                                       //~v027R~
    #endif                      //DPMI or not                      //~v053I~
#endif                                                             //~v027I~
//****************************
//get parm addr
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~v5nDR~
//	UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~v5nDI~//~v6hhR~
	UGETSTDARG(ULPTR,        parm,Pjmsg,UERRMSG_MAXPARM);          //~v6hhI~
	pmsg=uerrmsgedit(Stitle1,Pemsg,Pjmsg,parm);                    //~v060R~
    if (Sentrysw)                                                  //~v029I~
    {                                                              //~v029I~
	    if (Shandle1)  		//init not called                      //~v168I~
//#ifdef WCSUPP                                                    //~v5nxR~
//            uerrfprintfutf(UERRFPUO_NOEDIT,Shandle1,"%s\n",pmsg);//~v5nxR~
//#else                                                            //~v5nxR~
			fprintf(Shandle1,"%s\n",pmsg);                         //~v029I~
//#endif                                                           //~v5nxR~
        else                                                       //~v168I~
			printf("%s\n",pmsg);                                   //~v168I~
		printf("Error in error process,program terminate!!\n");    //~v168I~
	    if (Suerrexitopt & UERREXIT_BELL)                          //~v191I~
        {                                                          //~v293I~
        	Sbellopt=1;     //beep force on                        //~v293I~
    		ubell();                                               //~v191I~
		}                                                          //~v293I~
		exit(16);                                                  //~v029I~
	}                                                              //~v029I~
	Sentrysw++;                                                    //~v029I~
    if (!Sinit1)  		//init not called 
		Shandle1=stdout;
	if (Sexitfunc)                                              //~4C23I~
		Sexitfunc(pmsg,Sexitparm);                                 //~v027R~
	if (Shandle1)
	{	
//#ifdef WCSUPP                                                    //~v5nxR~
//        uerrfprintfutf(UERRFPUO_NOEDIT,Shandle1,"%s\n",pmsg);    //~v5nxR~
//#else                                                            //~v5nxR~
		fprintf(Shandle1,"%s\n",pmsg);                          //~5827M~
//#endif                                                           //~v5nxR~
//#ifndef UNX                                                      //~v5nxR~
//        if (*Sexitmapfile)                                       //~v5nxR~
//        {                                                        //~v5nxR~
//#if defined(DOS) && !defined(DPMI) && !defined(DOSDUMP)          //~v5nxR~
//#else                                                            //~v5nxR~
//        #ifndef MGW32                                            //~v5nxR~
//            ppathmsg=ufuncpathmsg(Sexitmapfile,(unsigned long)0,(unsigned long)0);//~v5nxR~
//            fprintf(Shandle1,ppathmsg);                          //~v5nxR~
//        #endif //!MINGW                                          //~v5nxR~
//#endif                                                           //~v5nxR~
//#ifdef DOS                                                       //~v5nxR~
//    #ifdef DPMI                 //DPMI version                   //~v5nxR~
//    #else                       //not DPMI                       //~v5nxR~
//            _asm mov segcs,cs                                    //~v5nxR~
//            _asm mov segds,ds                                    //~v5nxR~
//            _asm mov segss,ss                                    //~v5nxR~
//            fprintf(Shandle1,"CS=%04x,DS=%04x,SS=%04x\n",segcs,segds,segss);//~v5nxR~
//    #endif                      //DPMI or not                    //~v5nxR~
//#endif                                                           //~v5nxR~
//            fprintf(Shandle1,"\n");                              //~v5nxR~
//        }                                                        //~v5nxR~
//#endif //!UNX                                                    //~v5nxR~
	}
#ifdef DOS                                                      //~5827I~
    #ifdef DPMI					//DPMI version                     //~v053I~
        fcloseall();                                               //~v053I~
    #else                       //not DPMI                         //~v053I~
	if (Sexitfunc)                                                 //~v027I~
    {                                                              //~v027I~
		*dumpfnm=0;                                                //~v027I~
		Sexitfunc((char *)(ULONG)-1,dumpfnm);	//ger dumpfile name//~v027R~
    	if (*dumpfnm)                                              //~v027R~
        {                                                          //~v027I~
            abinfmsg[0]=pmsg;                                      //~v027R~
            abinfmsg[1]=ppathmsg;                                  //~v027R~
//#ifdef DOSDUMP                                                   //~v5nxR~
//            uehdump(dumpfnm,abinfmsg,Gpepatbl); //dos dump       //~v5nxR~
//#endif                                                           //~v5nxR~
        }                                                          //~v027I~
	}                                                              //~v027M~
    fcloseall();                                                //~5827I~
    #endif                      //DPMI or not                      //~v053I~
#endif                                                          //~5827R~
    if (Suerrexitopt & UERREXIT_BELL)                              //~v191I~
    {                                                              //~v293I~
        Sbellopt=1;     //beep force on                            //~v293I~
    	ubell();                                                   //~v191I~
    }                                                              //~v293I~
	exit(8);
	return;
}//errexit

//******************************************************
//* uerrmsg static initialize
//* parm1:pre-fix string
//* parm2:output handle(if init not called output to stdout)
//*         0 :no output
//*       or upopupmsg function addr if Pattr!=0                //~5902R~
//* parm3: 2nd last byte:                                       //~5B11R~
//*             option, 01:force english                        //~5B11I~
//*        last byte:                                           //~5B11I~
//* 		 	0 for no upopupmsg function use                 //~5B11I~
//*        		attr byte for popup msg,if ff default is white on blue//~5B11R~
//******************************************************
void uerrmsg_init(char *Ptitle,FILE *Poutput,int Popt)          //~5B11R~
{
	int szpower,sz,ii;                                             //~v5mKR~
    char *pc;                                                      //~v5mKR~
//****************************
    Sinit2=1;		//init called sw
	if (Ptitle)
		strcpy(Stitle2,Ptitle);
	else
		*Stitle2=0;
	Suerropt=(Popt & UERR_OPTION);                              //~5B11R~
//    if (Popt & UERR_ATTR)   //upopupmsg use                      //~v5nxR~
//    {                                                            //~v5nxR~
//        Spopupsw=1;                                              //~v5nxR~
//        Supopupmsg=(UPOPUPMSG*)(ULONG)Poutput;  //upopupmsg func addr//~v5nxR~
//        if ((Popt&UERR_ATTR)!=UERR_ATTR)        //not default    //~v5nxR~
//            Sattr2=(UCHAR)(Popt&UERR_ATTR);                      //~v5nxR~
//    }                                                            //~v5nxR~
//    else                                                         //~v5nxR~
		Shandle2=Poutput;                                       //~5902I~
    if (Popt & UERR_FORCE_ENGLISH)                                 //~v5bzI~
    	UCBITON(Guerropt,GBL_UERR_FORCEENG);                       //~v5bzI~
    else                                                           //~v5bzI~
    	UCBITOFF(Guerropt,GBL_UERR_FORCEENG);                      //~v5bzI~
    szpower=UERR_GETSIZEPOWER(Popt);                               //~v5mKR~
    if (szpower)                                                   //~v5mKR~
    {                                                              //~v5mKR~
    	for (sz=MAXMSGLL,ii=0;ii<szpower;ii++)                     //~v5mKR~
    		sz*=2;                                                 //~v5mKR~
        if (sz)                                                    //~v5mKR~
        {                                                          //~v5mKR~
        	pc=malloc((UINT)sz);                                   //~v5mKR~
            if (!pc)                                               //~v5mKR~
            	uerrexit("malloc(len=%d) failed for errmsg",0,     //~v5mKR~
                			sz);                                   //~v5mKR~
            Smsgsave=pc;                                           //~v5mKR~
            Smaxmsgll=sz;                                          //~v5mKR~
        }                                                          //~v5mKR~
    }                                                              //~v5mKR~
	return;
}//errmsg_init                                                     //~v61jR~

//******************************************************
//* msg edit and output                                            //~v060R~
//******************************************************
char *uerrmsg(char *Pemsg ,char *Pjmsg,... )
{
//  unsigned long *parm;                                           //~v5nDR~
//	unsigned long parm[UERRMSG_MAXPARM];                           //~v5nDI~//~v6hhR~
	ULPTR         parm[UERRMSG_MAXPARM];                           //~v6hhI~
	char *pmsg;
//****************************
//get parm addr
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~v5nDR~
//	UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~v5nDI~//~v6hhR~
	UGETSTDARG(ULPTR        ,parm,Pjmsg,UERRMSG_MAXPARM);          //~v6hhI~
	pmsg=uerrmsgedit(Stitle2,Pemsg,Pjmsg,parm);                    //~v060R~
UTRACED("errmsg",pmsg,strlen(pmsg));                               //~v5i8R~


    if (!Sinit2) 		//init not called 
		Shandle2=stdout;
  if (!(Guerropt & GBL_UERR_NOMSGOUT)) //*edit only,no output to any//~v062I~
  {                                                                //~v062I~
//    if (Spopupsw)                                                //~v5nxR~
//        Supopupmsg(pmsg,Sattr2);                                 //~v5nxR~
//    else                                                         //~v5nxR~
		if (Shandle2)
        {                                                          //~v570I~
//    #ifdef WCSUPP                                                //~v5nxR~
//            uerrfprintfutf(UERRFPUO_NOEDIT,Shandle2,"%s\n",pmsg);//~v5nxR~
//    #else                                                        //~v5nxR~
			fprintf(Shandle2,"%s\n",pmsg);                     //~4C18R~
//    #endif                                                       //~v5nxR~
        }                                                          //~v570I~
  }	                                                               //~v062I~
	return pmsg;
}//uerrmsg                                                         //~v060R~

//******************************************************           //~v060I~
//* uerrhelpmsg:write errmsg and wait kbdhit if screen full        //~v060I~
//* no uerrmsg_init required(pgm and version edit is caller resp)  //~v060I~
//*  when emsg=0;for other msg after helpmsg allow scroll chk;     //~v335I~
//*       jmsg is line cnt after helpmsg                           //~v335I~
//* parm1:msg output handle                                        //~v060I~
//* parm2:screen overflow msg output handle                        //~v060I~
//* parm3:SBCS msg text                                            //~v060I~
//* parm4:DBCS msg text                                            //~v060I~
//* parm5...:sprintf parms                                         //~v060I~
//******************************************************           //~v060I~
char *uerrhelpmsg(FILE *Poutf,FILE *Pqueryf,char *Pemsg ,char *Pjmsg,... )//~v060R~
{                                                                  //~v060I~
static int Shlineno=0;                                             //~v060I~
static int Shlinemax;                   //screen maxline size      //~v060I~
static int Slastcrlfsw=0;                 //last written crlf      //~v50VR~
//  unsigned long *parm;                                           //~v060I~//~v5nDR~
//	unsigned long parm[UERRMSG_MAXPARM];                           //~v5nDI~//~v6hhR~
	ULPTR         parm[UERRMSG_MAXPARM];                           //~v6hhI~
	char *pmsg;                                                    //~v060I~
    int  ch,crlfsw;                                                //~v060R~
#ifdef UNX                                                         //~v50wR~
	char breakmsg[128];                                            //~v50wR~
#ifdef LNX                                                         //~v5i8I~
	char breakmsgutf8[128];                                        //~v5i8I~
    int chklen,outlen,errctr;                                      //~v5i8I~
#endif                                                             //~v5i8I~
#endif                                                             //~v50wR~
//****************************                                     //~v060I~
//get parm addr                                                    //~v060I~
  if (Pemsg)                                                       //~v335I~
  {                                                                //~v335I~
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~v060I~//~v5nDR~
//	UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~v5nDI~//~v6hhR~
	UGETSTDARG(ULPTR        ,parm,Pjmsg,UERRMSG_MAXPARM);          //~v6hhI~
	pmsg=uerrmsgedit("",Pemsg,Pjmsg,parm);	//no title             //~v060R~
  }                                                                //~v335I~
  else                                                             //~v335I~
  {                                                                //~v335I~
// 	Shlineno+=(int)Pjmsg;	//last helpmsg followes other msg line //~v335I~//~v6hhR~
  	Shlineno+=(int)(ULPTR)Pjmsg;	//last helpmsg followes other msg line//~v6hhI~
    pmsg="";                                                       //~v335I~
  }                                                                //~v335I~
                                                                   //~v335I~
//    if (!(Guerropt & GBL_UERR_BG))  //fore ground                  //~v060I~//~v5nxR~
//    {                                                              //~v060I~//~v5nxR~
//        if (!Shlineno)              //first time                   //~v060R~//~v5nxR~
//        {                                                          //~v5kuI~//~v5nxR~
//        if (uprocredirectchk(fileno(stdout))==1)    //stdout redirected//~v5nxR~
//            Shlinemax=0x7fff;//no limit                            //~v5kuI~//~v5nxR~
//        else                                                     //~v5nxR~
//  	    Shlinemax=uerrscrheight()-1;	//get screen size(-1 for query msg)//~v5nxR~
//        }                                                          //~v5kuI~//~v5nxR~
                                                                   //~v060R~
    	if (Poutf==Pqueryf                                         //~v060R~
        ||  (  (Poutf==stdout   || Poutf==stderr  )                //~v060R~
             &&(Pqueryf==stdout || Pqueryf==stderr) ))             //~v060R~
        	crlfsw=1;       //both same or both to screen          //~v060R~
        else                                                       //~v060R~
        	crlfsw=0;                                              //~v060R~
                                                                   //~v335I~
//        if (Shlineno++>=Shlinemax)                                 //~v060R~//~v5nxR~
//        {                                                          //~v060R~//~v5nxR~
//            fflush(Poutf);                                         //~v060R~//~v5nxR~
//            if (crlfsw && !Slastcrlfsw)                            //~v060R~//~v5nxR~
//                fprintf(Pqueryf,"\n");                             //~v060R~//~v5nxR~
//            if (UCBITCHK(Guerropt,GBL_UERR_DBCSMODE)               //~v5n8M~//~v5nxR~
//            &&  !(Suerropt & UERR_FORCE_ENGLISH))                  //~v50wR~//~v5nxR~
//            {                                                      //~v50wR~//~v5nxR~
//#ifdef UNX                                                         //~v50wR~//~v5nxR~
//                strcpy(breakmsg,"--続き-- キーをどれか押して下さい．．．");//~v50wR~//~v5nxR~
//                if (UCBITCHK(Guerropt,GBL_UERR_SJIS2EUC))   //conv sjis to euc//~v50wR~//~v5nxR~
//                    ushift2euc(breakmsg,0,strlen(breakmsg),breakmsg,0,0,0); //sjis-->euc//~v550I~//~v5nxR~
//#ifdef LNX                                                         //~v5i8I~//~v5nxR~
//                else                                               //~v5i8I~//~v5nxR~
//                if (UCBITCHK(Guerropt,GBL_UERR_SJIS2UTF8))  //conv sjis to euc//~v5i8I~//~v5nxR~
//                {                                                  //~v5i8I~//~v5nxR~
//                    strcat(breakmsg,"\n");                         //~v5i8I~//~v5nxR~
//                    ucvssjis2utf(0,0,breakmsg,strlen(breakmsg),breakmsgutf8,sizeof(breakmsgutf8),&chklen,&outlen,&errctr);  //sjis-->euc//~v5i8I~//~v5nxR~
//                    memcpy(breakmsg,breakmsgutf8,outlen);          //~v5i8I~//~v5nxR~
//                    *(breakmsg+outlen)=0;                          //~v5i8I~//~v5nxR~
//                }                                                  //~v5i8I~//~v5nxR~
//#endif                                                             //~v5i8I~//~v5nxR~
////#ifdef WCSUPP                                                  //~v5nxR~
////                uerrfprintfutf(UERRFPUO_NOEDIT,Pqueryf,"%s",breakmsg);//~v5nxR~
////#else                                                          //~v5nxR~
//                fprintf(Pqueryf,breakmsg);                         //~v50wR~//~v5nxR~
////#endif                                                         //~v5nxR~
//#else                                                              //~v50wR~//~v5nxR~
//                fprintf(Pqueryf,"--続き-- キーをどれか押して下さい．．．");//~v199R~//~v5nxR~
//#endif                                                             //~v50wR~//~v5nxR~
//            }                                                      //~v50uI~//~v5nxR~
//            else                                                   //~v060R~//~v5nxR~
//                fprintf(Pqueryf,"continue--   Press Any Key");     //~v060R~//~v5nxR~
//            fflush(Pqueryf);                                       //~v060R~//~v5nxR~
//#ifdef UNX                                                         //~v361I~//~v5nxR~
//            ch=ukbdl_getch(UKBDL_GETCH_ONCE);//fd close after get char//~v39bR~//~v5nxR~
//          if (!Pemsg)   //chk for titlemsg space                   //~v376I~//~v5nxR~
//            printf("\n");   //lf                                   //~v376R~//~v5nxR~
//#else                                                              //~v361I~//~v5nxR~
//            ch=getch();                                            //~v060R~//~v5nxR~
//#endif                                                             //~v361I~//~v5nxR~
//            Shlineno=1;                                            //~v060R~//~v5nxR~
//            if (ch=='q'||ch=='Q')                                  //~v5f3I~//~v5nxR~
//            {                                                      //~v5faI~//~v5nxR~
//#ifdef UNX                                                         //~v5faI~//~v5nxR~
//                printf("\n");   //lf                               //~v5faI~//~v5nxR~
//#endif                                                             //~v5faI~//~v5nxR~
//                exit(1);                                           //~v5f3I~//~v5nxR~
//            }                                                      //~v5faI~//~v5nxR~
//        }                                                          //~v060R~//~v5nxR~
//        else                                                       //~v060R~//~v5nxR~
        	ch='\n';    //skip insert \n                           //~v060R~
                                                                   //~v335I~
  	  if (Pemsg)                                                   //~v335I~
      {                                                            //~v335I~
    	if (crlfsw)                                                //~v060R~
    		if (*pmsg!='\n' && ch!='\n')                           //~v060R~
    			fprintf(Pqueryf,"\n");                             //~v060R~
//    #ifdef WCSUPP                                                //~v5nxR~
//        uerrfprintfutf(UERRFPUO_NOEDIT,Poutf,"%s",pmsg);         //~v5nxR~
//    #else                                                        //~v5nxR~
    	fprintf(Poutf,"%s",pmsg);                                  //~v060R~
//    #endif                                                       //~v5nxR~
    	if (*pmsg)                                                 //~v060R~
    		Slastcrlfsw=(*(pmsg+strlen(pmsg)-1)=='\n');            //~v060R~
      }                                                            //~v335I~
//    }//fore ground                                                 //~v060I~//~v5nxR~
    else                                                           //~v060I~
//    #ifdef WCSUPP                                                //~v5nxR~
//        uerrfprintfutf(UERRFPUO_NOEDIT,Poutf,"%s",pmsg);         //~v5nxR~
//    #else                                                        //~v5nxR~
    	fprintf(Poutf,"%s",pmsg);                                  //~v060I~
//    #endif                                                       //~v5nxR~
	return pmsg;                                                   //~v060I~
}//uerrhelpmsg                                                     //~v060I~
                                                                   //~v060I~
//******************************************************
//* msg edit
//* parm1 :title(PGM,VER etc)                                      //~v060I~
//* parm2 :format by englist                                       //~v060I~
//* parm3 :format by japanese                                      //~v060I~
//* parm4-:parms                                                   //~v060I~
//******************************************************
//char *uerrmsgedit(char *Ptitle,char *Pemsg ,char *Pjmsg,unsigned long *Pparg)//~v060R~//~v6hhR~
char *uerrmsgedit(char *Ptitle,char *Pemsg ,char *Pjmsg,ULPTR *Pparg)//~v6hhI~
{
	int i,j;
	char *patern;           //eng or jap
    int lenw;                                                      //~v170I~
    char *pc;                                                      //~v170I~
//static int Sdoubleentry=0;                                       //~v5nxR~
//#ifdef UNX                                                         //~v50uI~//~v5nxR~
//    static int Skonsw=0;                                           //~v50uI~//~v5nxR~
//#endif                                                             //~v607I~//~v5nxR~
//  #ifdef LNX                                                       //~v607R~//~v5nxR~
//    int euclen;                                                    //~v5f8I~//~v5nxR~
//  #endif                                                           //~v607I~//~v5nxR~
#ifdef WCSUPP                                                      //~v5n8I~
//  int chklen,outlen,errctr;                                      //~v5i8I~//~v5nxR~
//  char eucmsg[MAXMSGLL*UTF8_MAXCHARSZ+2];                        //~v609M~//~v5nxR~
#else                                                              //~v609M~
  #ifdef LNX                                                       //~v5nnI~
//  char eucmsg[MAXMSGLL+1];                                       //~v5f8I~//~v5nxR~
  #endif                                                           //~v5nnI~
#endif                                                             //~v609I~
	int prevlen=0;                                                 //~v200I~
#ifdef LNX                                                         //~v5nnI~
	int prevdbcssetsw;                                             //~v5nnI~
#endif                                                             //~v5nnI~
//****************************
//    if(Sdoubleentry)                                             //~v5nxR~
//    {                                                              //~v5g8I~//~v5nxR~
//#ifdef UNX                                                         //~v50uI~//~v5nxR~
//        if (!(Guviol_flag & UVIOL_KONCHKS) || (Guviol_flag & UVIOL_KONCHKE))//~v50uI~//~v5nxR~
//#endif                                                             //~v50uI~//~v5nxR~
//            exit(16);                                              //~v50uR~//~v5nxR~
//    }                                                              //~v5g8I~//~v5nxR~
//    Sdoubleentry=1;                 //entry sw                   //~v5nxR~
//#ifdef LNX                                                         //~v5nnI~//~v5nxR~
//    prevdbcssetsw=UCBITCHK(Guerropt,GBL_UERR_DBCSSET);             //~v5nnI~//~v5nxR~
//#endif                                                             //~v5nnI~//~v5nxR~
//    if (!UCBITCHK(Guerropt,GBL_UERR_DBCSSET))   //not yet chked    //~v060I~//~v5nxR~
//    {                                                              //~v060I~//~v5nxR~
//        if (udbcschkcp())       //dbcstbl or cp!=932               //~v150I~//~v5nxR~
//            UCBITON(Guerropt,GBL_UERR_DBCSMODE);    //not yet chked//~v060I~//~v5nxR~
//        else                                                       //~v060I~//~v5nxR~
//            UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);   //not yet chked//~v060I~//~v5nxR~
//        UCBITON(Guerropt,GBL_UERR_DBCSSET); //not yet chked        //~v060I~//~v5nxR~
//    }                                                              //~v060I~//~v5nxR~
//#ifdef UNX                                                         //~v50uI~//~v5nxR~
//    if (Gudbcschk_flag & (UDBCSCHK_EUC|UDBCSCHK_UTF8J))    //euc or utf8//~v5i9R~//~v5nxR~
//    {                                                              //~v591I~//~v5nxR~
//        if (!Skonsw)        //not yet kon chked                    //~v50uI~//~v5nxR~
//        {                                                          //~v50uI~//~v5nxR~
//            if (!(Guviol_flag & (UVIOL_KONCHKS|UVIOL_KONCHKE))) //no one yet called//~v50uR~//~v5nxR~
//            {                                                      //~v50uI~//~v5nxR~
//                Skonsw=1;       //kon chked                        //~v50uI~//~v5nxR~
//                uviol_konchk();                                    //~v5n8R~//~v5nnR~//~v5nxR~
//            }                                                      //~v50uI~//~v5nxR~
//            else                                                   //~v50uI~//~v5nxR~
//                if (Guviol_flag & UVIOL_KONCHKE)    //chk ended    //~v50uI~//~v5nxR~
//                    Skonsw=1;       //kon chked                    //~v50uI~//~v5nxR~
//            if (Guviol_flag & UVIOL_KON        //under kon         //~v5nnI~//~v5nxR~
//            ||  uviol_konchk2())               //dbcs term     //~v5n8R~//~v5nnI~//~v5nxR~
//            {                                                      //~v50uR~//~v5nxR~
//              if (!prevdbcssetsw)   //xsub not set _UERR_DBCSSET   //~v5nnI~//~v5nxR~
//                UCBITON(Guerropt,GBL_UERR_DBCSMODE);    //conv sjis to euc//~v50uR~//~v5nxR~
//            }                                                      //~v50uR~//~v5nxR~
//        }                                                          //~v50uI~//~v5nxR~
//    #ifdef LNX                                                     //~v5n8I~//~v5nxR~
//      if (Gudbcschk_flag & (UDBCSCHK_UTF8J))    //euc-utf8         //~v5n8I~//~v5nxR~
//        UCBITON(Guerropt,GBL_UERR_SJIS2EUC);    //conv sjis to euc //~v5n8I~//~v5nxR~
//      else                                                         //~v5n8I~//~v5nxR~
//    #endif                                                         //~v5n8I~//~v5nxR~
//        if (UCBITCHK(Guerropt,GBL_UERR_DBCSMODE))   //kon or kterm etc//~v591I~//~v5nxR~
//        {                                                          //~v5i8I~//~v5nxR~
//          if (Gudbcschk_flag & UDBCSCHK_EUC)   //euc               //~v5i8I~//~v5nxR~
//            UCBITON(Guerropt,GBL_UERR_SJIS2EUC);    //conv sjis to euc//~v591I~//~v5nxR~
//          else                                                     //~v5i8I~//~v5nxR~
//            UCBITON(Guerropt,GBL_UERR_SJIS2UTF8);    //conv sjis to utf8//~v5i8I~//~v5nxR~
//        }                                                          //~v5i8I~//~v5nxR~
//    }//EUC                                                         //~v591I~//~v5nxR~
//#else     //!UNX                                                   //~v607I~//~v5nxR~
//    #ifdef WCSUPP                                                  //~v5n8I~//~v5nxR~
//        if (Gudbcschk_flag & UDBCSCHK_UTF8J)    //utf8             //~v607I~//~v5nxR~
//            UCBITON(Guerropt,GBL_UERR_SJIS2UTF8);    //conv sjis to utf8//~v607I~//~v5nxR~
//        else                                                       //~v607I~//~v5nxR~
//        if (Gudbcschk_flag & UDBCSCHK_UTF8)    //utf8              //~v607I~//~v5nxR~
//            Suerropt|=UERR_FORCE_ENGLISH;                          //~v607R~//~v5nxR~
//    #endif                                                         //~v607I~//~v5nxR~
//#endif                                                             //~v50uI~//~v5nxR~
        	                                                       //~v060I~
//    if (Pjmsg && *Pjmsg && UCBITCHK(Guerropt,GBL_UERR_DBCSMODE))        //japanese msg and DBCS mode//~v060I~//~v5nxR~
//        if (Suerropt & UERR_FORCE_ENGLISH)                      //~5B11R~//~v5nxR~
//            patern=Pemsg;                                       //~5B11I~//~v5nxR~
//        else                                                    //~5B11I~//~v5nxR~
//        {                                                          //~v5f8I~//~v5nxR~
//#ifdef LNX                                                         //~v5f8I~//~v5nxR~
//          if (UCBITCHK(Guerropt,GBL_UERR_SJIS2EUC)    //conv sjis to euc//~v60bI~//~v5nxR~
//          &&  !(Guerropt2 & (GBL_UERR2_NOCONV|GBL_UERR2_NOCONV1))  //~v60bR~//~v5nxR~
//             )                                                     //~v60bI~//~v5nxR~
//          {                                                        //~v5f8I~//~v5nxR~
//            lenw=(int)strlen(Pjmsg);                               //~v5f8I~//~v5nxR~
//            if (lenw>(sizeof(eucmsg)>>1))                          //~v5f8I~//~v5nxR~
//                lenw=(sizeof(eucmsg)>>1);                          //~v5f8I~//~v5nxR~
//            ushift2euc(Pjmsg,0,lenw,eucmsg,0,&euclen,0);  //sjis-->euc//~v5f8I~//~v5nxR~
//            *(eucmsg+euclen)=0;   //strz                           //~v5f8I~//~v5nxR~
//            patern=eucmsg;                                         //~v5f8I~//~v5nxR~
//          }                                                        //~v5f8I~//~v5nxR~
//          else                                                     //~v5f8I~//~v5nxR~
//#endif                                                             //~v607I~//~v5nxR~
//#ifdef WCSUPP                                                      //~v5n8I~//~v5nxR~
//          if (UCBITCHK(Guerropt,GBL_UERR_SJIS2UTF8)    //conv sjis to euc//~v60bI~//~v5nxR~
//          &&  !(Guerropt2 & (GBL_UERR2_NOCONV|GBL_UERR2_NOCONV1))  //~v60bR~//~v5nxR~
//             )                                                     //~v60bI~//~v5nxR~
//          {                                                        //~v5i8I~//~v5nxR~
//            ucvssjis2utf(0,0,Pjmsg,strlen(Pjmsg),eucmsg,sizeof(eucmsg),&chklen,&outlen,&errctr);    //sjis-->utf8//~v5i8I~//~v5nxR~
//            *(eucmsg+outlen)=0;   //strz                           //~v609I~//~v5nxR~
//            patern=eucmsg;                                         //~v5i8I~//~v5nxR~
//          }                                                        //~v5i8I~//~v5nxR~
//          else                                                     //~v5i8I~//~v5nxR~
//#endif                                                             //~v5f8I~//~v5nxR~
//            patern=Pjmsg;                                       //~5B11R~//~v5nxR~
//        }                                                          //~v5f8I~//~v5nxR~
//    else                                                         //~v5nxR~
		patern=Pemsg;
//    Guerropt2&=~GBL_UERR2_NOCONV1;  //effective only once          //~v60bR~//~v5nxR~
    lenw=(int)strlen(patern);                                      //~v170I~
    if (lenw>(Smaxmsgll>>1))		//may overflow                 //~v5mKR~
    {                                                              //~v170I~
    	if (strchr(patern,'%'))	//may expand                       //~v170I~
        {                                                          //~v170I~
        	lenw<<=1;	//alloc double                             //~v170I~
//      	pc=umalloc((UINT)lenw);	//alloc double                 //~v5nxR~
        	pc=malloc((UINT)lenw);	//alloc double                 //~v5nnI~
        }                                                          //~v170I~
        else                                                       //~v170I~
        {                                                          //~v170I~
        	lenw+=(int)strlen(Ptitle)+2;	//total en             //~v170I~
        	if (lenw>=Smaxmsgll)    //overflow                     //~v5mKR~
//          	pc=umalloc((UINT)lenw);	//alloc double             //~v5nxR~
	        	pc=malloc((UINT)lenw);	//alloc double             //~v5nnI~
            else                                                   //~v170I~
            	pc=Smsgsave;		//use fiexed                   //~v170R~
		}                                                          //~v170I~
        if (!pc)	//maclloc failed                               //~v170I~
            pc=Smsgsave;		//use fiexed                       //~v170I~
    }                                                              //~v170I~
    else                                                           //~v170I~
    	pc=Smsgsave;                                               //~v170I~
    if (pc==Smsgsave)                                              //~v170I~
    {                                                              //~v200I~
        lenw=Smaxmsgll;                                            //~v5mKR~
        if (Smsgcatsw)                                             //~v200I~
        	prevlen=(int)strlen(Smsgsave);                         //~v200R~
	}                                                              //~v200I~
//edit                                                             //~v170I~
                                                                   //~v170I~
  if (prevlen)		//cat msg                                      //~v200I~
  {                                                                //~v200I~
  	i=prevlen;                                                     //~v200I~
    j=0;                                                           //~v200I~
  }                                                                //~v200I~
  else                                                             //~v200I~
  {                                                                //~v200I~
	for(i=0;;i++)
	{
		if (*(patern+i)!='\n')
			break;
    	*(pc+i)='\n';                                              //~v170I~
	}
	j=i;
	if (Suerropt & UERR_TIMESTAMP)                                 //~v5iwI~
    {                                                              //~v5iwI~
//  	memcpy(pc+i,utimeedit("HH:MM:SS.MIL ",0),13);              //~v5iwR~
    	memcpy(pc+i,utils_timeedit("HH:MM:SS.MIL ",0),13);
        i+=13;                                                     //~v5iwR~
    }                                                              //~v5iwI~
    i+=sprintf(pc+i,"%s",Ptitle);                                  //~v5iwI~
  }	                                                               //~v200I~
    i+=sprintf(pc+i,patern+j,                                      //~v170I~
	        *(Pparg+0),*(Pparg+1),*(Pparg+2),*(Pparg+3),*(Pparg+4),
            *(Pparg+5),*(Pparg+6),*(Pparg+7),*(Pparg+8),*(Pparg+9));
    if (i>=lenw)                                                   //~v170R~
    {                                                              //~v170I~
        ubell();                                                   //~v170I~
		printf("\nToo long errmsg(%d>%d),memory may destroy!! \n",i,lenw);//~v170R~
    }                                                              //~v170I~
	if (pc!=Smsgsave)                                              //~v170I~
    {                                                              //~v170I~
    	if (i>=Smaxmsgll)                                          //~v5mKR~
        	i=Smaxmsgll-1;                                         //~v5mKR~
        memcpy(Smsgsave,pc,(UINT)i);                               //~v170I~
        *(Smsgsave+i)=0;                                           //~v170I~
//      ufree(pc);	                                               //~v170I~//~v5nxR~
        free(pc);                                                  //~v5nxI~
    }                                                              //~v170I~
                                                                   //~v50uI~
        	                                                       //~v50uI~
//    Smsgsetflag=1;  //can get by ugeterrmsg                      //~v5nxR~
//    Sdoubleentry=0;     //exitsw                                 //~v5nxR~
	return Smsgsave;
}//uerrmsgedit                                                     //~v50uR~
                                                                //~5A10I~
//**************************************************************** //~v5iyI~
//*convert errorno to string                                       //~v5iyI~
//**************************************************************** //~v5iyI~
char *uerrornomsg(int Perrorno)                                    //~v5iyI~
{                                                                  //~v5iyI~
    return strerror(Perrorno);                                     //~v5iyR~
}                                                                  //~v5iyI~
#ifdef W32                                                         //~v5iyI~
//**************************************************************** //~v5iyI~
//*ugetlasterror                                                   //~v5iyI~
//*convert windows errcode to string                               //~v5iyI~
//*if parm==NULL;issue GetLastError                                //~v5iyI~
//*if *parm<0;return also GetLastError value                       //~v5iyI~
//*ret string:call shuld use ufree or null if faied                //~v5iyR~
//**************************************************************** //~v5iyI~
char *ugetlasterror(int *Pprc)                                     //~v5iyI~
{                                                                  //~v5iyI~
	int rc,len,apirc;                                              //~v5iyR~
    ULONG langid;                                                  //~v5iyI~
    void *buff;                                                    //~v5iyI~
	char *ret;                                                     //~v5iyI~
//*******************************                                  //~v5iyI~
	if (Pprc)                                                      //~v5iyI~
    {                                                              //~v5iyI~
        rc=*Pprc;                                                  //~v5iyI~
        if (rc<0)                                                  //~v5iyI~
        {                                                          //~v5iyI~
            rc=GetLastError();                                     //~v5iyI~
            *Pprc=rc;                                              //~v5iyI~
        }                                                          //~v5iyI~
    }                                                              //~v5iyI~
    else                                                           //~v5iyI~
    	rc=GetLastError();                                         //~v5iyI~
	if (Suerropt & UERR_FORCE_ENGLISH)                             //~v5iyI~
    	langid=MAKELANGID(LANG_ENGLISH,SUBLANG_DEFAULT);           //~v5iyI~
    else                                                           //~v5iyI~
    	langid=MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT);           //~v5iyI~
                                                                   //~v5iyI~
	apirc=FormatMessage(  FORMAT_MESSAGE_ALLOCATE_BUFFER	//get output buffsz//~v5iyR~
				  | FORMAT_MESSAGE_FROM_SYSTEM      //search in system msg table//~v5iyI~
				  | FORMAT_MESSAGE_IGNORE_INSERTS,  //ignore insert seq(get raw text),arg parm ignored//~v5iyI~
    				NULL,							//format input //~v5iyI~
				    rc, 							//msgid,       //~v5iyR~
    				langid,                                        //~v5iyI~
    				(LPTSTR)&buff,					//output buff addr//~v5iyR~
				    0,								//buffsz       //~v5iyI~
				    NULL);							//arg to format//~v5iyI~
    if (!apirc)  	//failed                                       //~v5iyI~
    	return 0;                                                  //~v5iyI~
    len=strlen(buff);                                              //~v5iyI~
//  ret=umalloc(len+1);                                            //~v5nxR~
    ret=malloc(len+1);                                             //~v5nnI~
    memcpy(ret,buff,(UINT)(len+1));                                //~v5iyM~
	LocalFree(buff);                                               //~v5iyM~
    if (len>1 && *(ret+len-1)=='\n')                               //~v5iyR~
    {                                                              //~v5iyI~
        len--;                                                     //~v5iyI~
        *(ret+len)=0;  //drop last lf                              //~v5iyR~
    	if (len>1 && *(ret+len-1)=='\r')                           //~v5iyR~
    	{                                                          //~v5iyI~
        	len--;                                                 //~v5iyI~
        	*(ret+len)=0;  //drop last cr                          //~v5iyR~
	    }                                                          //~v5iyI~
    }                                                              //~v5iyI~
    return ret;                                                    //~v5iyI~
}//ugetlasterror                                                   //~v5iyI~
#endif	//W32                                                      //~v5iyI~
//**************************************************************** //~v5j3I~
//ugeterrdescription                                               //~v5j3I~
//*conv errno/GetLastError to text                                 //~v5j3I~
//*if parm==NULL;issue GetLastError                                //~v5j3I~
//*if *parm<0;return also GetLastError value                       //~v5j3I~
//**************************************************************** //~v5j3I~
char *ugeterrdescription(int Pgetlasterrsw,int *Pprc)              //~v5j3R~
{                                                                  //~v5j3I~
	int errcd;                                                     //~v5j3I~
#ifdef W32                                                         //~v5j3I~
    char *pdesc;                                                   //~v5j3I~
#endif                                                             //~v5j3I~
//**************************                                       //~v5j3I~
#ifdef W32                                                         //~v5j3M~
	if (Pgetlasterrsw)                                             //~v5j3I~
    {                                                              //~v5j3I~
		pdesc=ugetlasterror(Pprc);	//0:issue GetLastError         //~v5j3R~
        if (!pdesc)                                                //~v5j3I~
        	return "";                                             //~v5j3I~
		return pdesc;                                              //~v5j3I~
	}                                                              //~v5j3I~
#endif                                                             //~v5j3M~
    if (Pprc)                                                      //~v5j3I~
    {                                                              //~v5j3I~
    	if (*Pprc<0)                                               //~v5j3I~
        	*Pprc=errcd=errno;                                     //~v5j3I~
        else                                                       //~v5j3I~
        	errcd=*Pprc;                                           //~v5j3I~
    }                                                              //~v5j3I~
    else                                                           //~v5j3I~
        errcd=*Pprc;                                               //~v5j3I~
    return strerror(errcd);                                        //~v5j3R~
}//ugeterrdescription                                              //~v5j3I~
//****************************************************************//~5A10I~
//uerrapi1                                                      //~5A10I~
//* api err msg with 1 parm                                     //~5A10I~
//*parm1:apiname                                                //~5A10I~
//*parm2:parm 1                                                 //~5A10I~
//*parm3:rc for display                                         //~5A10I~
//*retrn:rc same as input                                       //~5A10I~
//****************************************************************//~5A10I~
int uerrapi1(char  *Papiname,char  *Pparm1,int Papirc)          //~5A10I~
{                                                               //~5A10I~
//********************                                          //~5A10I~
	uerrmsg("%s failed for %s,rc=%d",0,                         //~5A10I~
			Papiname,Pparm1,Papirc);                            //~5A10I~
	return Papirc;                                              //~5A10I~
}//uerrapi1                                                     //~5A10I~
                                                                //~5A10I~
//**************************************************************** //~v022I~
//uerrapi1x                                                        //~v022I~
//* api err msg with 1 parm and exit                               //~v022I~
//*parm1:apiname                                                   //~v022I~
//*parm2:parm 1                                                    //~v022I~
//*parm3:rc for display                                            //~v022I~
//*retrn:exit                                                      //~v022I~
//**************************************************************** //~v022I~
void uerrapi1x(char  *Papiname,char  *Pparm1,int Papirc)           //~v022R~
{                                                                  //~v022I~
//********************                                             //~v022I~
	uerrexit("%s failed for %s,rc=%d",0,                           //~v022I~
			Papiname,Pparm1,Papirc);                               //~v022I~
}//uerrapi1x                                                       //~v022I~
                                                                   //~v022I~
//**************************************************************** //~v040I~
//uerrapi0                                                         //~v040I~
//* api err msg with 0 parm                                        //~v040I~
//*parm1:apiname                                                   //~v040I~
//*parm2:rc for display                                            //~v040I~
//*retrn:rc same as input                                          //~v040I~
//**************************************************************** //~v040I~
int uerrapi0(char  *Papiname,int Papirc)                           //~v040I~
{                                                                  //~v040I~
//********************                                             //~v040I~
	uerrmsg("%s failed,rc=%d",0,Papiname,Papirc);                  //~v040I~
	return Papirc;                                                 //~v040I~
}//uerrapi0                                                        //~v040I~
                                                                   //~v040I~
//**************************************************************** //~v040I~
//uerrapi0x                                                        //~v040I~
//* api err msg with 0 parm and exit                               //~v040I~
//*parm1:apiname                                                   //~v040I~
//*parm2:rc for display                                            //~v040I~
//*retrn:exit                                                      //~v040I~
//**************************************************************** //~v040I~
void uerrapi0x(char  *Papiname,int Papirc)                         //~v040I~
{                                                                  //~v040I~
//********************                                             //~v040I~
	uerrexit("%s failed,rc=%d",0,Papiname,Papirc);                 //~v040I~
}//uerrapi0x                                                       //~v040I~
//**************************************************************** //~v5j3I~
//uerrapi1t                                                        //~v5j3I~
//display errcode and errdescription(if apirc<0 use current value) //~v5j3I~
//**************************************************************** //~v5j3I~
int uerrapi1t(int Pgetlasterrsw,char  *Papiname,char  *Pparm1,int Papirc)//~v5j3R~
{                                                                  //~v5j3I~
	int errcd;                                                     //~v5j3I~
    char *perrdesc;                                                //~v5j3I~
//********************                                             //~v5j3I~
	errcd=Papirc;	//use current value if -1                      //~v5j3I~
	perrdesc=ugeterrdescription(Pgetlasterrsw,&errcd);             //~v5j3I~
	uerrmsg("%s failed for %s,rc=%d(%s)",0,                        //~v5j3I~
			Papiname,Pparm1,errcd,perrdesc);                       //~v5j3R~
#ifdef W32                                                         //~v5j3I~
	if (Pgetlasterrsw && *perrdesc)                                //~v5j3I~
//  	ufree(perrdesc);                                           //~v5j3I~//~v5nxR~
    	free(perrdesc);                                            //~v5nxI~
#endif                                                             //~v5j3I~
	return errcd;                                                  //~v5j3R~
}//uerrapi1t                                                       //~v5j3I~
//**************************************************************** //~v5j3I~
//uerrapi1x                                                        //~v5j3I~
//* api err msg with 1 parm and exit                               //~v5j3I~
//display errcode and errdescription(if apirc<0 use current value) //~v5j3I~
//**************************************************************** //~v5j3I~
void uerrapi1tx(int Pgetlasterrsw,char  *Papiname,char  *Pparm1,int Papirc)//~v5j3I~
{                                                                  //~v5j3I~
	int errcd;                                                     //~v5j3I~
    char *perrdesc;                                                //~v5j3I~
//********************                                             //~v5j3I~
	errcd=Papirc;	//use current value if -1                      //~v5j3I~
	perrdesc=ugeterrdescription(Pgetlasterrsw,&errcd);             //~v5j3I~
	uerrexit("%s failed for %s,rc=%d(%s)",0,                       //~v5j3I~
			Papiname,Pparm1,errcd,perrdesc);                       //~v5j3R~
}//uerrapi1tx                                                      //~v5j3I~
                                                                   //~v5j3I~
//**************************************************************** //~v5j3I~
//uerrapi0                                                         //~v5j3I~
//* api err msg with 0 parm                                        //~v5j3I~
//display errcode and errdescription(if apirc<0 use current value) //~v5j3I~
//**************************************************************** //~v5j3I~
int uerrapi0t(int Pgetlasterrsw,char  *Papiname,int Papirc)        //~v5j3I~
{                                                                  //~v5j3I~
	int errcd;                                                     //~v5j3I~
    char *perrdesc;                                                //~v5j3I~
//********************                                             //~v5j3I~
	errcd=Papirc;	//use current value if -1                      //~v5j3I~
	perrdesc=ugeterrdescription(Pgetlasterrsw,&errcd);             //~v5j3I~
	uerrmsg("%s failed,rc=%d(%s)",0,                               //~v5j3R~
				Papiname,errcd,perrdesc);                          //~v5j3R~
#ifdef W32                                                         //~v5j3I~
	if (Pgetlasterrsw && *perrdesc)                                //~v5j3I~
//  	ufree(perrdesc);                                           //~v5j3I~//~v5nxR~
    	free(perrdesc);                                            //~v5nxI~
#endif                                                             //~v5j3I~
	return errcd;                                                  //~v5j3R~
}//uerrapi0t                                                       //~v5j3I~
                                                                   //~v5j3I~
//**************************************************************** //~v5j3I~
//uerrapi0x                                                        //~v5j3I~
//* api err msg with 0 parm and exit                               //~v5j3I~
//display errcode and errdescription(if apirc<0 use current value) //~v5j3I~
//**************************************************************** //~v5j3I~
void uerrapi0tx(int Pgetlasterrsw,char  *Papiname,int Papirc)      //~v5j3I~
{                                                                  //~v5j3I~
	int errcd;                                                     //~v5j3I~
    char *perrdesc;                                                //~v5j3I~
//********************                                             //~v5j3I~
	errcd=Papirc;	//use current value if -1                      //~v5j3I~
	perrdesc=ugeterrdescription(Pgetlasterrsw,&errcd);             //~v5j3I~
	uerrexit("%s failed,rc=%d(%s)",0,                              //~v5j3R~
				Papiname,errcd,perrdesc);                          //~v5j3R~
}//uerrapi0tx                                                      //~v5j3I~
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
void *utils_timeedit(unsigned char *Ppatern,void *Pout)            //~v5nxR~
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
    yy=ptm->tm_year;                                               //~v321R~
    yy+=1900;                                                      //~v59hR~
//  mo=ptm->tm_mon;                                                //~v345R~
    mo=ptm->tm_mon+1;                                              //~v345I~
    dd=ptm->tm_mday;                                               //~v321R~
    hh=ptm->tm_hour;                                               //~v321R~
    mi=ptm->tm_min;                                                //~v321R~
    ss=ptm->tm_sec;                                                //~v321R~
    th=tb.millitm/10;                                              //~v321R~
    milisec=tb.millitm;                                            //~v59kR~
    swcase=(ULONG)Ppatern;                                         //~v321I~
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
    swcase=(ULONG)(ULPTR)Ppatern;                                  //~v6hhI~
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
#ifdef WCSUPP                                                      //~v6j0I~
//******************************************************           //~v6j0I~
//* msg edit only with no title                                    //~v6j0I~
//* NOEDIT option: uerrfprintfutf(opt,fh,pattern,msg);             //~v6j0I~
//*   EDIT option: uerrfprintfutf(opt,fh,patterne,patternj,parm1,...);//~v6j0I~
//******************************************************           //~v6j0I~
int uerrfprintfutf(int Popt,FILE *Pfh,char *Pemsg ,char *Pjmsg,... )//~v6j0I~
{                                                                  //~v6j0I~
//  unsigned long *parm;                                           //~v6j0I~
//  unsigned long parm[UERRMSG_MAXPARM];                           //~v6j0I~
	ULPTR         parm[UERRMSG_MAXPARM];                           //~v6j0I~
	UCHAR *pmsg,*pdbcstbl;                                         //~v6j0I~
    int timestampsw,len,outlen,rc;                                 //~v6j0I~
    FILE *fh;                                                      //~v6j0I~
    char wk[MAXMSGLL*UTF8_MAXCHARSZ+2];                            //~v6j0I~
//  ULONG pl2uconverters;                                          //~v6j0I~
    ULPTR pl2uconverters;                                          //~v6j0I~
//  ULONG a2aconverters[3];                                        //~v6j0I~
//  ULONG a2aconverters[7];                                        //~v6j0I~
    ULPTR a2aconverters[7];                                        //~v6j0I~
//****************************                                     //~v6j0I~
	if (!(fh=Pfh))                                                 //~v6j0I~
    	fh=stdout;                                                 //~v6j0I~
	if (Popt & UERRFPUO_NOEDIT)	//msg by uerrmsgedit               //~v6j0I~
    	pmsg=Pjmsg;                                                //~v6j0I~
    else                                                           //~v6j0I~
    {                                                              //~v6j0I~
        timestampsw=(Suerropt & UERR_TIMESTAMP);                   //~v6j0I~
        if (timestampsw)                                           //~v6j0I~
            Suerropt &=~UERR_TIMESTAMP;                            //~v6j0I~
//      parm=(unsigned long*)(void*)((&Pjmsg)+1);                  //~v6j0I~
//  	UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);      //~v6j0I~
		UGETSTDARG(ULPTR,        parm,Pjmsg,UERRMSG_MAXPARM);      //~v6j0I~
        pmsg=uerrmsgedit("",Pemsg,Pjmsg,parm);                     //~v6j0I~
        if (timestampsw)                                           //~v6j0I~
            Suerropt|=UERR_TIMESTAMP;                              //~v6j0I~
    }                                                              //~v6j0I~
    if (Gudbcschk_flag & UDBCSCHK_UTF8)    //euc or utf8//~v5i8I~, //~v6j0I~
    {                                                              //~v6j0I~
      if (!(Guerropt2 & (GBL_UERR2_NOCONV|GBL_UERR2_NOCONV1)))     //~v6j0I~
      {                                                            //~v6j0I~
    	if (!udbcschk_getbaseconverter(0,&pl2uconverters,&pdbcstbl))//~v6j0I~
        {                                                          //~v6j0I~
		  if (UDBCSCHK_IS_LOCALICU())                              //~v6j0I~
          {                                                        //~v6j0I~
        	a2aconverters[0]=*(ULONG*)pl2uconverters;              //~v6j0I~
//        	a2aconverters[1]=(ULONG)pdbcstbl;                      //~v6j0I~
        	a2aconverters[1]=(ULPTR)pdbcstbl;                      //~v6j0I~
    		len=strlen(pmsg);                                      //~v6j0I~
        	len=min(len,MAXMSGLL);                                 //~v6j0I~
			rc=ucvext_icumb2utf(0,a2aconverters,pmsg,len,wk,sizeof(wk),0/*repch*/,0/*chklen*/,&outlen,0/*repctr out*/);//~v6j0I~
          }                                                        //~v6j0I~
          else                                                     //~v6j0I~
          {                                                        //~v6j0I~
        	a2aconverters[HICONV_CPTO]=0; //ucs2locale=0 means to utf8//~v6j0I~
        	a2aconverters[HICONV_CPFROM]=pl2uconverters;           //~v6j0I~
//        	a2aconverters[HICONV_DBCSSTARTER]=(ULONG)pdbcstbl;     //~v6j0I~
        	a2aconverters[HICONV_DBCSSTARTER]=(ULPTR)pdbcstbl;     //~v6j0I~
    		len=strlen(pmsg);                                      //~v6j0I~
        	len=min(len,MAXMSGLL);                                 //~v6j0I~
//			rc=ucvext_iconva2as(UCVEXTO_TOUTF8,a2aconverters,pmsg,0/*dbcs*/,len,wk,sizeof(wk),0/*chklen*/,&outlen,'?',0/*repctr out*/);//~v6j0I~//~v6m2R~
            UCVEXT_TOUTF8_ON();                                    //~v6m2I~
  			rc=ucvext_iconva2as(0,a2aconverters,pmsg,0/*dbcs*/,len,wk,sizeof(wk),0/*chklen*/,&outlen,'?',0/*repctr out*/);//~v6m2I~
            UCVEXT_TOUTF8_OFF();                                   //~v6m2I~
          }                                                        //~v6j0I~
        	if (!rc)                                               //~v6j0I~
            {                                                      //~v6j0I~
            	wk[outlen]=0;                                      //~v6j0I~
        		pmsg=wk;                                           //~v6j0I~
            }                                                      //~v6j0I~
        }                                                          //~v6j0I~
      }                                                            //~v6j0I~
	}                                                              //~v6j0I~
	if (Popt & UERRFPUO_NOEDIT)	//msg by uerrmsgedit               //~v6j0I~
		rc=fprintf(fh,Pemsg,pmsg);                                 //~v6j0I~
    else                                                           //~v6j0I~
		rc=fprintf(fh,"%s",pmsg);                                  //~v6j0I~
    return rc;                                                     //~v6j0I~
}//uerrfprintfutf                                                  //~v6j0I~
#endif //WCSUPP                                                    //~v6j0I~
//******************************************************           //~v6j0I~
//* msg edit and output                                            //~v6j0I~
//*  only when previous msg is not pending                         //~v6j0I~
//*rc :msg text or 0 if already set                                //~v6j0I~
//******************************************************           //~v6j0I~
char *uerrmsg2(char *Pemsg ,char *Pjmsg,... )                      //~v6j0I~
{                                                                  //~v6j0I~
//  unsigned long *parm;                                           //~v6j0I~
//  unsigned long parm[UERRMSG_MAXPARM];                           //~v6j0I~
	ULPTR         parm[UERRMSG_MAXPARM];                           //~v6j0I~
	char *pmsg;                                                    //~v6j0I~
//****************************                                     //~v6j0I~
//get parm addr                                                    //~v6j0I~
	if (Smsgsetflag)		//already set errmsg                   //~v6j0I~
    	return 0;                                                  //~v6j0I~
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~v6j0I~
//  UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~v6j0I~
	UGETSTDARG(ULPTR,        parm,Pjmsg,UERRMSG_MAXPARM);          //~v6j0I~
	pmsg=uerrmsgedit(Stitle2,Pemsg,Pjmsg,parm);                    //~v6j0I~
    if (!Sinit2) 		//init not called                          //~v6j0I~
		Shandle2=stdout;                                           //~v6j0I~
  if (!(Guerropt & GBL_UERR_NOMSGOUT)) //*edit only,no output to any//~v6j0I~
  {                                                                //~v6j0I~
//  if (Spopupsw)                                                  //~v6j0R~
//  	Supopupmsg(pmsg,Sattr2);                                   //~v6j0R~
//  else                                                           //~v6j0R~
		if (Shandle2)                                              //~v6j0I~
        {                                                          //~v6j0I~
#ifdef WXE                                                         //~v6j0I~
    		wxe_uerrmsgstdo(pmsg);                                 //~v6j0I~
#else                                                              //~v6j0I~
	#ifdef WCSUPP                                                  //~v6j0I~
			uerrfprintfutf(UERRFPUO_NOEDIT,Shandle2,"%s\n",pmsg);  //~v6j0I~
	#else                                                          //~v6j0I~
			fprintf(Shandle2,"%s\n",pmsg);                         //~v6j0I~
    #endif                                                         //~v6j0I~
#endif                                                             //~v6j0I~
        }//Shandle2                                                //~v6j0I~
  }                                                                //~v6j0I~
	return pmsg;                                                   //~v6j0I~
}//uerrmsg2                                                        //~v6j0I~
//******************************************************           //~v6j0I~
//* msg edit and output conatinationg prev msg                     //~v6j0I~
//*rc :msg top(may be of previous)                                 //~v6j0I~
//******************************************************           //~v6j0I~
char *uerrmsgcat(char *Pemsg ,char *Pjmsg,... )                    //~v6j0I~
{                                                                  //~v6j0I~
//  unsigned long **parm;                                          //~v6j0I~
//  unsigned long *parm[UERRMSG_MAXPARM];                          //~v6j0I~
	ULPTR parm[UERRMSG_MAXPARM];                                   //~v6j0I~
	char *pmsg;                                                    //~v6j0I~
//****************************                                     //~v6j0I~
//get parm addr                                                    //~v6j0I~
	if (Smsgsetflag)		//already set errmsg                   //~v6j0I~
		Smsgcatsw=1;		//parm yo uerrmsgedit                  //~v6j0I~
//  parm=(unsigned long**)(ULONG)((&Pjmsg)+1);                     //~v6j0I~
//  UGETSTDARG(unsigned long*,parm,Pjmsg,UERRMSG_MAXPARM);         //~v6j0I~
	UGETSTDARG(ULPTR,         parm,Pjmsg,UERRMSG_MAXPARM);         //~v6j0I~
	pmsg=uerrmsg(Pemsg,Pjmsg,parm[0],parm[1],parm[2],parm[3],parm[4],//~v6j0I~
	             parm[5],parm[6],parm[7],parm[8],parm[9]);         //~v6j0I~
	Smsgcatsw=0;                                                   //~v6j0I~
	return pmsg;                                                   //~v6j0I~
}//uerrmsgcat                                                      //~v6j0I~
//******************************************************           //~v6j0I~
//* get previous err msg text & clear it                           //~v6j0I~
//******************************************************           //~v6j0I~
char *useterrmsg(char *Perrmsg)                                    //~v6j0I~
{                                                                  //~v6j0I~
                                                                   //~v6j0I~
	if (Perrmsg)	//saved msg                                    //~v6j0I~
    {                                                              //~v6j0I~
//  	strncpy(Smsgsave,Perrmsg,sizeof(Smsgsave));                //~v6j0I~
    	strncpy(Smsgsave,Perrmsg,(UINT)Smaxmsgll);                 //~v6j0I~
    	Smsgsetflag=1;		//clear gotten msg                     //~v6j0I~
    }                                                              //~v6j0I~
    else                                                           //~v6j0I~
    	Smsgsetflag=0;		//clear gotten msg                     //~v6j0I~
	return Smsgsave;                                               //~v6j0I~
}//useterrmsg                                                      //~v6j0I~
//******************************************************           //~v6j0I~
//* get previous err msg text & clear it                           //~v6j0I~
//******************************************************           //~v6j0I~
char *ugeterrmsg(void)                                             //~v6j0I~
{                                                                  //~v6j0I~
    if (!Smsgsetflag)	//not set by umsgedit                      //~v6j0I~
		return 0;                                                  //~v6j0I~
                                                                   //~v6j0I~
    Smsgsetflag=0;		//clear gotten msg                         //~v6j0I~
	return Smsgsave;                                               //~v6j0I~
}//ugeterrmsg                                                      //~v6j0I~
                                                                   //~v6j0I~
//******************************************************           //~v6j0I~
//* get previous err msg text,but dont clear it                    //~v6j0I~
//******************************************************           //~v6j0I~
char *ugeterrmsg2(void)                                            //~v6j0I~
{                                                                  //~v6j0I~
    if (!Smsgsetflag)	//not set by umsgedit                      //~v6j0I~
		return 0;                                                  //~v6j0I~
	return Smsgsave;                                               //~v6j0I~
}//ugeterrmsg2                                                     //~v6j0I~
                                                                   //~v6j0I~
//**************************************************************** //~v6j0I~
// errnotsupported                                                 //~v6j0I~
//*parm1 :cmd string                                               //~v6j0I~
//*rc    :4                                                        //~v6j0I~
//**************************************************************** //~v6j0I~
int uerrnotsupported(char  *Pcmd,char  *Pcond,int Prc)             //~v6j0I~
{                                                                  //~v6j0I~
	uerrmsg("\"%s\" is not supported for %s.",                     //~v6j0I~
			"\"%s\" は %s ではサポ－トされません。",               //~v6j0I~
			Pcmd,Pcond);                                           //~v6j0I~
    return Prc;                                                    //~v6j0I~
}//uerrnotsupported                                                //~v6j0I~
