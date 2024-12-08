//*CID://+v6DiR~:                             update#=   15;       //~v6DiR~
//*************************************************************    //~v324I~
//*uehl.c                                                          //~v324R~
//*exception handler for linux                                     //~v324R~
//*************************************************************    //~v324I~
//v6Di:160625 for compiler warning,-Wformat-security(not literal printf format)//~v6DiI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v594:031004 (UNX)reset signal handler at entry to signal handler to protect loop//~v594I~
//v537:020319 (AIX)reset to SIG_DFL at entry to signal handler     //~v537I~
//v532:020311 (BUG AIX)no data segment dumped                      //~v532I~
//v409:001109 AIX support:malloc defined on stdlib.h               //~v532I~
//v409:001109 AIX support:malloc defined on stdlib.h               //~v409I~
//v408:001109 AIX support:SIGSTKFLT is linux only                  //~v409I~
//v359:000927 LINUX support(print uerrexit msg after uabend)       //~v359I~
//v357:000927 LINUX support(BUG:SIG_IGN,SIG_DFL,SIG_ERR is not addr)//~v357I~
//v356:000927 LINUX support(kill is uncatchable)                   //~v357I~
//v355:000927 LINUX support(BUG:exit function addr field is UERGuxfunc for xe.c)//~v355I~
//v324 000813:LINUX support                                        //~v324I~
//*************************************************************    //~v324I~
#include <stdio.h>                                                 //~v324I~
#include <stdlib.h>                                                //~v409I~
#include <ctype.h>                                                 //~v324I~
#include <string.h>                                                //~v324I~
#include <errno.h>                                                 //~v324I~
#include <signal.h>                                                //~v324I~
#include <malloc.h>                                                //~v324I~
                                                                   //~v324I~
#include <ulib.h>                                                  //~v324I~
#include <ueh.h>                                                   //~v324I~
#include <uehl.h>                                                  //~v324I~
#include <uerr.h>                                                  //~v324I~
//*********************************************************************//~v324I~
static int Ssigno[]={                                              //~v324I~
                        SIGBUS,   //*hardware err                  //~v324I~
                        SIGXCPU,  //*overflow cpu resource         //~v324I~
                        SIGXFSZ,  //*overflow filesize resource    //~v324I~
                        SIGVTALRM,//*settimer expiered             //~v324I~
//                      SIGHUP,   //closed  ctl tty                //~v324R~
                        SIGINT,   //user sent ctrl+C(interuption char)//~v324R~
                        SIGQUIT,  //*user sent ctrl+\(termination char)//~v324R~
                        SIGILL,   //*ileagal instruction           //~v324R~
//                      SIGTRAP,  //breakpoint                     //~v324R~
                        SIGABRT,  //*abort()                       //~v324R~
//                      SIGIOT,   //                               //~v324R~
                        SIGFPE,   //*floating point exception      //~v324R~
//                      SIGKILL,  //*kill process(un cathcable)    //~v357R~
                        SIGSEGV,  //*segment violation             //~v324R~
//                      SIGPIPE,  //write to pipe with no reader   //~v324R~
                        SIGTERM,  //*force term(cathable)          //~v324R~
#ifdef LNX                                                         //~v409I~
#ifndef MGW32                                                      //~v5ncI~
                        SIGSTKFLT,//stack fault?                   //~v324R~
#endif                                                             //~v5ncI~
#endif                                                             //~v409I~
//                      SIGCHLD,  //child process terminated       //~v324R~
//                      SIGCONT,  //resumed process after suspend  //~v324R~
//                      SIGSTOP,  //suspend process                //~v324R~
//                      SIGTSTP,  //user sent ctrl+z(suspend)      //~v324R~
//                      SIGTTIN,  //bg process read from ctl tty   //~v324R~
//                      SIGTTOU,  //bg process write to ctl tty    //~v324R~
                        SIGUSR1,  //user defined                   //~v324I~
                        SIGUSR2   //user defined                   //~v324I~
                        };                                         //~v324I~
#define SIG_SIZE ENTNOOF(Ssigno)                                  //~v324R~
#ifdef AIX                                                         //~v532I~
    struct sigaction Sprevsigh[SIG_SIZE];                          //~v532I~
#else                                                              //~v532I~
static SignalHandler Sprevsigh[SIG_SIZE];                          //~v324I~
#endif                                                             //~v532I~
#define MAX_SIGHNEST 10                                            //~v324I~
static PUEXREGREC   Spurr[MAX_SIGHNEST];       //exception handler sem//~v324I~
static int Ssighnest=0;                                            //~v532R~
//*********************************************************************//~v324I~
//*********************************************************************//~v324I~
//* setup sig handler thru UEXREGREC                               //~v324R~
//*********************************************************************//~v324I~
void useteh(PUEXREGREC Ppurr)                                      //~v324I~
{                                                                  //~v324I~
    int ii;
    void usighandler(int Psigno);                                  //~v324I~
#ifdef AIX                                                         //~v532I~
    struct sigaction sa1,sa2;  //16 byte,add,mask(2),flags         //~v532I~
#endif                                                             //~v532I~
//*******************************                                  //~v324I~
    if (!Ssighnest)                                                //~v324I~
        for (ii=0;ii<SIG_SIZE;ii++)                                //~v324I~
#ifdef AIX                                                         //~v532I~
        {                                                          //~v532I~
            memset(&sa1,0,sizeof(sa1));  //mask clear              //~v532R~
            sa1.sa_handler=usighandler;                            //~v532I~
            sa1.sa_flags=SA_FULLDUMP;                              //~v532I~
            sa1.sa_flags|=SA_RESETHAND;//reset to SIG_DFL at entry to sh//~v537I~
            sigaction(Ssigno[ii],&sa1,&sa2);                       //~v532I~
            Sprevsigh[ii]=sa2;                                     //~v532I~
        }                                                          //~v532I~
#else                                                              //~v532I~
            Sprevsigh[ii]=signal(Ssigno[ii],usighandler);          //~v324I~
#endif                                                             //~v532I~
    if (Ssighnest>=MAX_SIGHNEST)                                   //~v324I~
        return;                                                    //~v324I~
    Spurr[Ssighnest]=Ppurr;         //save                         //~v324I~
    Ssighnest++;                                                   //~v324I~
    return;                                                        //~v324I~
}//useteh                                                          //~v324I~
//*********************************************************************//~v324I~
//* setup sig handler thru SignalHandler                           //~v324I~
//*********************************************************************//~v324I~
void *uehl_setsh(SignalHandler *Psh)                                //~v324I~
{                                                                  //~v324I~
    void usighandler(int Psigno);                                  //~v324I~
	PUEXREGREC   purr;                                             //~v324I~
//*******************************                                  //~v324I~
	purr=(PUEXREGREC)malloc(sizeof(UEXREGREC));                    //~v324I~
	memset(purr,0,sizeof(UEXREGREC));                              //~v324I~
    purr->UERGsys.PPrevSignalHandler=Psh;                          //~v324I~
	useteh(purr);                                                //~v324I~
    return purr;                                                        //~v324I~
}//useteh                                                          //~v324I~
//************************************************************     //~v324I~
//* reseteh                                                        //~v324I~
//*     p1:user exception registration record addr                 //~v324I~
//* RETURN     : none                                              //~v324I~
//************************************************************     //~v324I~
void ureseteh(PUEXREGREC Ppurr)                                          //~v324R~
{                                                                  //~v324I~
    int ii;                                                        //~v324I~
#ifdef AIX                                                         //~v532I~
    struct sigaction sa1;  //16 byte,add,mask(2),flags             //~v532I~
#endif                                                             //~v532I~
//*****************************                                    //~v324I~
    if(!Ssighnest) // not activ                                    //~v324I~
    {
        fprintf(stderr,"reset eh request,but no preivious set eh req\n");//~v324I~
        return;
    }    
    Ssighnest--;                                                   //~v324I~
    if (!Ssighnest)                                                //~v324I~
        for (ii=0;ii<SIG_SIZE;ii++)                                //~v324R~
#ifdef AIX                                                         //~v532I~
        {                                                          //~v532I~
            sa1=Sprevsigh[ii];                                     //~v532I~
            sa1.sa_flags=SA_FULLDUMP;   //force fulldump           //~v532I~
            sigaction(Ssigno[ii],&sa1,0);                          //~v532I~
        }                                                          //~v532I~
#else                                                              //~v532I~
            signal(Ssigno[ii],Sprevsigh[ii]);                      //~v324R~
#endif                                                             //~v532I~
    return;                                                        //~v324I~
}//ureseteh                                                        //~v324I~
//************************************************************     //~v324I~
//* uehl_resetsh:reset signal handler                              //~v324I~
//************************************************************     //~v324I~
void uehl_resetsh(void *Puexregrec)
{                                                                  //~v324I~
//*****************************                                    //~v324I~
	ureseteh(Puexregrec);
    if (Puexregrec)
        free(Puexregrec);                                                     //~v324I~
    return;                                                        //~v324I~
}//ureseteh                                                        //~v324I~
//***********************************************************************//~v324I~
//* common signal handler                                          //~v324I~
//*     p1:signal no                                               //~v324I~
//***********************************************************************//~v324I~
void usighandler(int Psigno)                                       //~v324I~
{                                                                  //~v324I~
    int ii;
    PUEXREGREC purr;                                      //~v324I~
//  EXCEPTIONREPORTRECORD exreprec;                                //~v355R~
//  CONTEXTRECORD ctxrec;                                          //~v355R~
//	UEXCEPTIONHANDLER     pueh;                                    //~v355R~
    void (*pueh)(int,PUEXREGREC);//exit func                       //~v355I~
    UEXREGREC   uerr;                                              //~v355I~
	void (*psh)(int);                                     //~v324I~
    UCHAR *uerrexitmsg;                                            //~v359I~
//********                                                         //~v324I~
    ureseteh(&uerr);    //restore original sigh to protect abend loop//~v594R~
	for (ii=Ssighnest;ii>0;ii--)                                   //~v324I~
    {                                                              //~v324I~
    	purr=Spurr[ii-1];                                          //~v324R~
//  	pueh=purr->UERGsys.UExceptionHandler;                      //~v355R~
    	pueh=purr->UERGuxfunc;                                     //~v355R~
        if (pueh)                                                  //~v324I~
        {                                                          //~v355I~
//  		pueh(&exreprec,&purr->UERGsys,&ctxrec);                //~v355R~
            memset(&uerr,0,sizeof(uerr));                          //~v355R~
    		pueh(0,&uerr);	//at entry to ueh,req scrreset         //~v359R~
//*                                                                //~v359I~
			uerrexitmsg=ugeterrmsg();		//get msg before user exit//~v359I~
            if (uerrexitmsg)                                       //~v359I~
//            	printf(uerrexitmsg);                               //~v6DiR~
              	printf("%s",uerrexitmsg);                          //+v6DiR~
                                                                   //~v359I~
    		pueh(2,&uerr);   //at exit from eh                     //~v355R~
        }                                                          //~v355I~
    	psh=(void*)purr->UERGsys.PPrevSignalHandler;                      //~v324I~
        if (psh)                                                   //~v324I~
    		psh(Psigno);                                           //~v324I~
    }                                                              //~v324I~
    fflush(stdout);                                                //~v359I~
    fflush(stderr);                                                //~v359I~
////call original signal handler                                   //~v532R~
//    for (ii=0;ii<SIG_SIZE;ii++)                                  //~v532R~
//        if (Ssigno[ii]==Psigno)                                  //~v532R~
//            if (Sprevsigh[ii]!=SIG_IGN                           //~v532R~
//            &&  Sprevsigh[ii]!=SIG_DFL                           //~v532R~
//            &&  Sprevsigh[ii]!=SIG_ERR)                          //~v532R~
//                (Sprevsigh[ii])(Psigno);                         //~v532R~
//  ureseteh(&uerr);    //restore original sigh                    //~v594R~
    return;                                                        //~v324I~
}//usighandler                                                     //~v324I~
