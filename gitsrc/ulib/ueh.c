//CID://+v6K2R~:       update#=  22                                //+v6K2R~
// *******************************************************************
//v6K2:170311 (Win)take windows process dump when exception(requires regedit setting)//+v6K2I~
//v6F1:160831 W64 try Exception msg                                //~v6F1I~
//v6hi:120628 VC10x64 no exception handling                        //~v6hiI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v5m2:080131 drop dbcs comment                                    //~v304I~
//v304 000408:(BUG)eh loop.more protection but it may not effective.//~v304I~
//v288:991023 (BUG)map not found msg override previous uerrexit msg//~v288I~
//v286:991023 abend in eh when map is not found;allow double entry to eh//~v286I~
//v169:980501 fcloseall when return from ueh double entry          //~v169I~
//v167:980430 test eh bug                                          //~v167I~
//v102:971010 os2 new malloc dump logic                            //~v102I~
//            uehdump.c:dump allocated page                        //~v102I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -ehception handle by signal                          //~v053I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
// 950827:save uerrexit msg for the case map open err           //~5827I~
// 950826:map call only once                                    //~5826R~
// 950813:close all file at return                              //~5826I~
// *******************************************************************//~5813I~
// * uexcepth.c
// * exception handler set/unset,exception handler itself          //~v304R~
// *******************************************************************
#include <string.h>
#include <stdlib.h>       //malloc,free
#include <stdio.h>
#include <stddef.h>

#ifdef DPMI					//DPMI version                         //~v053I~
    #include <signal.h>                                            //~v053I~
    #include <setjmp.h>                                            //~v053I~
    #include <sys/exceptn.h>                                       //~v053I~
    #include <sys/segments.h>                                      //~v053R~
#else                       //not DPMI                             //~v053I~
#ifdef W32  //copy from f:\toolkt21\c\os2h\bsexcpt.h               //~v022I~
    #include <windows.h>                                           //~v022I~
#else                                                              //~v022I~
    #define INCL_DOSSEMAPHORES//for DosCreate/Request/ReleaseMutexSem//~v022I~
    #define INCL_DOSEXCEPTIONS  //c.b about exception handle       //~v022I~
    #define INCL_DOSPROCESS     //c.b about tib/pib                //~v022I~
    #define INCL_DOSERRORS      //for r.c                          //~v022I~
    #include <os2.h>                                               //~v022I~
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
                                                                   //~v022I~
#include <ulib.h>                                                  //~v022I~
#include <uerr.h>
#include <ufuncmap.h>
#include <ueh.h>
#include <uehmsg.h>
#include <uehdump.h>
#include <utrace.h>                                                //~v167I~
//********************************************************************

#define WAIT_TIME   1000      //wait child thread term by milisec
#define MAXEHENTRY 1   //loop detection,2 times per thread         //~v022R~

//***************************************************************
static PUEXREGREC 	Spurr;       //exception handler sem 
#ifdef DPMI					//DPMI version                         //~v053I~
    static int Ssigno[]={SIGFPE,SIGILL,SIGINT,SIGSEGV,SIGUSR1,SIGUSR2,0};//~v053I~
    static SignalHandler Sprevsigh[(sizeof(Ssigno)/sizeof(int))];  //~v053R~
#else                       //not DPMI                             //~v053I~
#ifdef W32  //copy from f:\toolkt21\c\os2h\bsexcpt.h               //~v022I~
#else                                                              //~v022I~
static ULONG 	 	Shmtx;       //exception handler sem 
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
//********************************************************************
#ifdef DPMI					//DPMI version                         //~v053I~
//  SignalHandler  udpmisigh;                                      //~v053R~
    void udpmisigh(int Psigno);                                    //~v053I~
	ULONG          uexhdlr(PEXCEPTIONREPORTRECORD,                 //~v053I~
				           	PEXCEPTIONREGISTRATIONRECORD,          //~v053I~
							PCONTEXTRECORD);                       //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32  //copy from f:\toolkt21\c\os2h\bsexcpt.h               //~v022I~
	LONG WINAPI uw95exh(LPEXCEPTION_POINTERS Pw95exptrs);          //~v022I~
	ULONG          uexhdlr(PEXCEPTIONREPORTRECORD,                 //~v022I~
				           	PEXCEPTIONREGISTRATIONRECORD,          //~v022I~
							PCONTEXTRECORD);                       //~v022R~
#else                                                              //~v022I~
	ULONG APIENTRY uexhdlr(PEXCEPTIONREPORTRECORD,                 //~v022R~
				           	PEXCEPTIONREGISTRATIONRECORD,          //~v022I~
							PCONTEXTRECORD,                        //~v022I~
							PVOID);                                //~v022I~
#endif                                                             //~v022M~
#endif                      //DPMI or not                          //~v053I~
//************************************************************
//*
//*            : useteh                                            //~v5m2R~
//*
//* INPUT      :
//*     p1:user exception registration record addr
//*
//* RETURN     : none
//*
///*             set exception handler
//*
//************************************************************
void useteh(PUEXREGREC Ppurr)
{
//#ifdef ULIB64X                                                     //~v6hiR~//~v6F1R~
//#else                                                              //~v6hiR~//~v6F1R~
#ifdef DPMI					//DPMI version                         //~v053I~
    int ii;                                                        //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32  //copy from f:\toolkt21\c\os2h\bsexcpt.h               //~v022I~
#else                                                              //~v022I~
	PTIB ptib;          //os/2 tib                                 //~v022I~
	PPIB ppib;          //os/2 pib                                 //~v022I~
	APIRET apiret;                                                 //~v022I~
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
//****************************

	memset(&Ppurr->UERGflag,0,
			(UINT)(UEXREGRECSZ-offsetof(UEXREGREC,UERGflag)));

#ifdef DPMI					//DPMI version                         //~v053I~
    Spurr=Ppurr; 		//save                                     //~v053I~
	for (ii=0;Ssigno[ii];ii++)	                                   //~v053R~
    	Sprevsigh[ii]=signal(Ssigno[ii],udpmisigh);                //~v053I~
    Sprevsigh[ii]=0;	//last                                     //~v053I~
	Ppurr->UERGsys.UExceptionHandler=uexhdlr;                      //~v053I~
	Ppurr->UERGsys.PPrevSignalHandler=Sprevsigh;                   //~v053R~
#else                       //not DPMI                             //~v053I~
#ifdef W32                                                         //~v022R~
#ifdef ULIB64X                                                     //~v6F1I~
//* ebp has no meening on X64                                      //~v6F1I~
#else                                                              //~v6F1I~
	usetmainebp((ULONG)*(UINT*)((ULONG)&Ppurr-8));//caller ebp s.a //~v022I~
#endif                                                             //~v6F1I~
	Spurr=Ppurr;				//main                             //~v022I~
	Ppurr->UERGsys.UExceptionHandler=uexhdlr;                      //~v022R~
	Ppurr->UERGsys.PrevWinExceptionHandler=SetUnhandledExceptionFilter(uw95exh);//~v022I~
#else                                                              //~v022I~
    DosGetInfoBlocks(&ptib,&ppib);
    Ppurr->UERGthreadid=ptib->tib_ptib2->tib2_ultid;
    if (Ppurr->UERGthreadid==1)     //main thread
    {
		Spurr=Ppurr;				//main 
     	uehsem(MTX_CREATE,&Shmtx);       //create semaphore
//        rsvmalloc(Ppurr);                                        //~v102R~
    }

    Ppurr->UERGsys.prev_structure=0;  /*chain*/
    Ppurr->UERGsys.ExceptionHandler=&uexhdlr;
    apiret=DosSetExceptionHandler
              ( (PEXCEPTIONREGISTRATIONRECORD)((void*)Ppurr) );
    if(apiret)
		uerrexit("DosSetExceptionHandler failed,rc=%d",
					0,apiret);
#endif                                                             //~v022M~
#endif                      //DPMI or not                          //~v053I~
	Ppurr->UERGflag |= UERGFEHACT; //activ

//#endif  //!ULIB64X                                                 //~v6hiR~//~v6F1R~
	return;
}//useteh

//************************************************************
//*            : ureseteh                                          //~v304R~
//* INPUT      :
//*     p1:user exception registration record addr
//* RETURN     : none
//*            :reset exception handler                            //~v304R~
//************************************************************

void ureseteh(PUEXREGREC Ppurr)
{
//#ifdef ULIB64X                                                     //~v6hiR~//~v6F1R~
//#else                                                              //~v6hiR~//~v6F1R~
#ifdef DPMI					//DPMI version                         //~v053I~
	int ii;                                                        //~v053I~
    SignalHandler *psigh;                                          //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
 APIRET apiret;
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
//*****************************
    if(!(Ppurr->UERGflag & UERGFEHACT)) // not activ
		uerrexit("Duplicated call(Not yet E.H set)",0);

#ifdef DPMI					//DPMI version                         //~v053I~
	for (psigh=Ppurr->UERGsys.PPrevSignalHandler,ii=0;!Ssigno[ii];ii++)//~v053R~
    	signal(Ssigno[ii],psigh[ii]);                              //~v053R~
#else                       //not DPMI                             //~v053I~
#ifdef W32                                                         //~v022R~
	SetUnhandledExceptionFilter(Spurr->UERGsys.PrevWinExceptionHandler);//~v022I~
    Ppurr->UERGflag &=~UERGFEHACT; 	//inactive                     //~v022I~
#else                                                              //~v022I~
    apiret=DosUnsetExceptionHandler
                  ( (PEXCEPTIONREGISTRATIONRECORD)((void*)Ppurr) );
    if(apiret)
		uerrexit("DosUnsetExceptionHandler failed,rc=%d",
					0,apiret);
    Ppurr->UERGflag &=~UERGFEHACT; 	//inactive
    if (Ppurr->UERGthreadid==1)     //main thread
     	uehdumpterm();	//free upblock
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
//#endif  //!ULIB64X                                                 //~v6hiR~//~v6F1R~
	return;
}//ureseteh

#ifdef DPMI					//DPMI version                         //~v053I~
//***********************************************************************//~v053I~
//*                                                                //~v053I~
//*            : udpmisigh                                         //~v304R~
//* INPUT      :                                                   //~v053I~
//*     p1:signal no                                               //~v053I~
//***********************************************************************//~v053I~
void udpmisigh(int Psigno)                                         //~v053I~
{                                                                  //~v053I~
	jmp_buf jb;                                                    //~v053R~
//os2 format                                                       //~v053I~
	EXCEPTIONREPORTRECORD exreprec;                                //~v053I~
    CONTEXTRECORD ctxrec;                                          //~v053I~
    ULONG rc;                                                      //~v053I~
    UINT ptr,ptr2;                                                 //~v053R~
//********                                                         //~v053I~
    memcpy(jb,__djgpp_exception_state_ptr,sizeof(jb));	//for short coding//~v053I~
    memset(&exreprec,0,sizeof(exreprec));                          //~v053R~
    memset(&ctxrec,0,sizeof(ctxrec));                              //~v053R~
    if (Psigno==SIGUSR1)	//uabend                               //~v053I~
    {                                                              //~v053I~
        ctxrec.ContextFlags|=CONTEXT_CONTROL;                      //~v053I~
    	exreprec.ExceptionNum=EXCEPTION_UABEND;                    //~v053R~
    	exreprec.cParameters=4;                                    //~v053I~
        ptr=*((UINT*)((UINT)(&Psigno)-8));//function raise ebp     //~v053R~
        ptr2=*((UINT*)ptr);                //function uabend ebp   //~v053R~
    	memcpy(exreprec.ExceptionInfo,(void*)(ptr2+8),16);	//abend code,p1,p2,p3//~v053R~
       	exreprec.ExceptionAddress=(void*)(*((UINT*)(ptr+4)));//next of call raise//~v053R~
//context_control                                                  //~v053I~
        ctxrec.ctx_SegCs =_my_cs();                                //~v053R~
        ctxrec.ctx_RegEip=(UINT)exreprec.ExceptionAddress;         //~v053R~
        ctxrec.ctx_SegSs =_my_ss();                                //~v053R~
        ctxrec.ctx_RegEsp=(ULONG)(&Psigno);  //lowest              //~v053R~
        ctxrec.ctx_RegEbp=*((UINT*)ptr);	//raise caller ebp     //~v053R~
    }                                                              //~v053I~
    else                                                           //~v053I~
    {                                                              //~v053I~
        ctxrec.ContextFlags|=(CONTEXT_CONTROL|CONTEXT_INTEGER|CONTEXT_SEGMENTS);//~v053R~
//report rec setup                                                 //~v053I~
    	exreprec.ExceptionNum=jb->__signum;                        //~v053R~
    	exreprec.cParameters=1;                                    //~v053R~
    	exreprec.ExceptionInfo[0]=jb->__sigmask;                   //~v053R~
       	exreprec.NestedExceptionReportRecord=(PVOID)jb->__exception_ptr;//~v053R~
       	exreprec.ExceptionAddress=(PVOID)jb->__eip;                //~v053R~
//context rec setup                                                //~v053I~
        ctxrec.ctx_SegGs=jb->__gs;                                 //~v053R~
        ctxrec.ctx_SegFs=jb->__fs;                                 //~v053R~
        ctxrec.ctx_SegEs=jb->__es;                                 //~v053R~
        ctxrec.ctx_SegDs=jb->__ds;                                 //~v053R~
        ctxrec.ctx_RegEdi=jb->__edi;                               //~v053R~
        ctxrec.ctx_RegEsi=jb->__esi;                               //~v053R~
        ctxrec.ctx_RegEax=jb->__eax;                               //~v053R~
        ctxrec.ctx_RegEbx=jb->__ebx;                               //~v053R~
        ctxrec.ctx_RegEcx=jb->__ecx;                               //~v053R~
        ctxrec.ctx_RegEdx=jb->__edx;                               //~v053R~
        ctxrec.ctx_RegEbp=jb->__ebp;                               //~v053R~
        ctxrec.ctx_RegEip=jb->__eip;                               //~v053R~
        ctxrec.ctx_SegCs =jb->__cs;                                //~v053R~
        ctxrec.ctx_EFlags=jb->__eflags;                            //~v053R~
        ctxrec.ctx_RegEsp=jb->__esp;                               //~v053R~
        ctxrec.ctx_SegSs =jb->__ss;                                //~v053R~
    }                                                              //~v053I~
	rc=uexhdlr(&exreprec,&Spurr->UERGsys,&ctxrec);                 //~v053I~
    if (rc==XCPT_CONTINUE_SEARCH)	//popup msg                    //~v053I~
    {                                                              //~v053I~
    	signal(Psigno,(SignalHandler)SIG_DFL);  //default action   //~v053I~
        raise(Psigno);                                             //~v053I~
    }                                                              //~v053I~
    return;                                                        //~v053I~
}//udpmisigh                                                       //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32  //copy from f:\toolkt21\c\os2h\bsexcpt.h               //~v022I~
/***********************************************************************///~v022I~
/*                                                                     *///~v022I~
/*            : uw95exh                                                *///~v304R~
/*                                                                     *///~v022I~
/* INPUT      :                                                        *///~v022I~
//*     p1:_EXCEPTION_POINTERS                                     //~v022I~
//*     call OS/2,WIN95 common rtn                                 //~v022I~
/***********************************************************************///~v022I~
LONG WINAPI uw95exh(LPEXCEPTION_POINTERS Pw95exptrs)               //~v022I~
{                                                                  //~v022I~
//#ifdef ULIB64X                                                     //~v6hiR~//~v6F1R~
//    int rc=0;                                                      //~v6hiR~//~v6F1R~
//#else                                                              //~v6hiR~//~v6F1R~
	PEXCEPTION_RECORD pw95reprec;                                  //~v022I~
	PCONTEXT          pw95ctxrec;                                  //~v022I~
//os2 format                                                       //~v022I~
	EXCEPTIONREPORTRECORD exreprec;                                //~v022I~
    CONTEXTRECORD ctxrec;                                          //~v022I~
    ULONG rc;                                                      //~v022I~
//  static callctr=0;                                              //~v022R~
//********                                                         //~v022I~
 	pw95reprec=Pw95exptrs->ExceptionRecord;                        //~v022R~
 	pw95ctxrec=Pw95exptrs->ContextRecord;                          //~v022R~
    UTRACED("ExceptionRecord",pw95reprec,(int)sizeof(EXCEPTION_RECORD));//~v6F1R~
    UTRACED("ContextRecord",pw95ctxrec,(int)sizeof(CONTEXT));      //~v6F1I~
//	printf("ueh:call=%d,code=%08x\n",++callctr,pw95reprec->ExceptionCode);//~v022R~
//report rec setup                                                 //~v022I~
	exreprec.ExceptionNum=pw95reprec->ExceptionCode; /* exception number *///~v022I~
   	exreprec.fHandlerFlags=pw95reprec->ExceptionFlags;             //~v022I~
   	exreprec.NestedExceptionReportRecord=pw95reprec->ExceptionRecord;//~v022I~
   	exreprec.ExceptionAddress=pw95reprec->ExceptionAddress;        //~v022I~
   	exreprec.cParameters=pw95reprec->NumberParameters; /* Size of Exception Specific Info *///~v022I~
   	memcpy(exreprec.ExceptionInfo,pw95reprec->ExceptionInformation,//~v022I~
//  		EXCEPTION_MAXIMUM_PARAMETERS*4); /* Exception Specfic Info *///~v022I~//~v6F1R~
    		EXCEPTION_MAXIMUM_PARAMETERS*sizeof(exreprec.ExceptionInfo[0])); /* Exception Specfic Info *///~v6F1I~
//context rec setup                                                //~v022I~
   ctxrec.ContextFlags=pw95ctxrec->ContextFlags;                   //~v022I~
#ifdef ULIB64X                                                     //~v6F1R~
#else                                                              //~v6F1I~
   memcpy(ctxrec.ctx_env,&pw95ctxrec->FloatSave,sizeof(ctxrec.ctx_env));//maybe same//~v022R~
   memcpy(ctxrec.ctx_stack,pw95ctxrec->FloatSave.RegisterArea,sizeof(ctxrec.ctx_stack));//~v022R~
                                                                   //~v022I~
   ctxrec.ctx_SegGs=pw95ctxrec->SegGs;                             //~v022I~
   ctxrec.ctx_SegFs=pw95ctxrec->SegFs;                             //~v022I~
   ctxrec.ctx_SegEs=pw95ctxrec->SegEs;                             //~v022I~
   ctxrec.ctx_SegDs=pw95ctxrec->SegDs;                             //~v022I~
                                                                   //~v022I~
   ctxrec.ctx_RegEdi=pw95ctxrec->Edi;      //1, seq in w95 context //~v022I~
   ctxrec.ctx_RegEsi=pw95ctxrec->Esi;      //2                     //~v022I~
   ctxrec.ctx_RegEax=pw95ctxrec->Eax;      //6                     //~v022I~
   ctxrec.ctx_RegEbx=pw95ctxrec->Ebx;      //3                     //~v022I~
   ctxrec.ctx_RegEcx=pw95ctxrec->Ecx;      //5                     //~v022I~
   ctxrec.ctx_RegEdx=pw95ctxrec->Edx;      //4                     //~v022I~
                                                                   //~v022I~
   ctxrec.ctx_RegEbp=pw95ctxrec->Ebp;                              //~v022I~
   ctxrec.ctx_RegEip=pw95ctxrec->Eip;                              //~v022I~
   ctxrec.ctx_SegCs =pw95ctxrec->SegCs;                            //~v022I~
   ctxrec.ctx_EFlags=pw95ctxrec->EFlags;                           //~v022R~
   ctxrec.ctx_RegEsp=pw95ctxrec->Esp;                              //~v022I~
   ctxrec.ctx_SegSs =pw95ctxrec->SegSs;                            //~v022I~
#endif  //!ULIB64X                                                 //~v6F1R~
	rc=uexhdlr(&exreprec,&Spurr->UERGsys,&ctxrec);                 //~v022R~
    printf("%s:uexhdlr rc=%d\n",UTT,rc);                           //~v6F1R~
//  printf("\nreturn ueh callctr=%d,rc=%08x\n",callctr,rc);        //~v022R~
    if (rc==XCPT_CONTINUE_SEARCH)	//popup msg                    //~v022I~
#ifdef TRACE                                                       //+v6K2R~
    	rc=EXCEPTION_CONTINUE_SEARCH;  //popup msg and take dump   //~v6F1I~//+v6K2I~
#else                                                              //~v6F1I~//+v6K2M~
    	rc=EXCEPTION_EXECUTE_HANDLER;  //no popup msg              //~v022I~
#endif                                                             //~v6F1I~
//#endif //!ULIB64X                                                  //~v6hiR~//~v6F1R~
    printf("%s:rc=%d\n",UTT,rc);                                   //~v6F1R~
    return rc;                                                     //~v022R~
}//uw95exh                                                         //~v022I~
#else                                                              //~v022I~
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
//***********************************************************************//~v304I~
                                                                   //~v6hhI~
void tempdump(int Pdumpno,void *Parea1,int Plen1,void *Parea2,int Plen2)//~v304I~
{                                                                  //~v304I~
#ifdef ULIB64X                                                     //~v6hiR~
#else                                                              //~v6hiR~
	FILE *fh;                                                      //~v304I~
    char fnm[16];                                                  //~v304I~
    char stacka[32];                                               //~v304I~
//	ULONG  addr,len,stacktop,stackend;     //commiYtted stack start/end//~v304I~//~v6hhR~
  	ULPTR  addr,    stacktop,stackend;     //commiYtted stack start/end//~v6hhI~
  	ULONG       len                  ;     //commiYtted stack start/end//~v6hhI~
//**************                                                   //~v304I~
	sprintf(fnm,"xetmpdmp.%d",Pdumpno);                            //~v304R~
    fh=fopen(fnm,"wb");                                            //~v304I~
    if (!fh)                                                       //~v304I~
    	return;                                                    //~v304R~
	fwrite("** report rec **",1,16,fh);                            //~v304I~
	fwrite(Parea1,1,(UINT)Plen1,fh);                               //~v304R~
	fwrite("** context    **",1,16,fh);                            //~v304R~
	fwrite(Parea2,1,(UINT)Plen2,fh);                               //~v304R~
	ugetstackaddr(&stacktop,&stackend);//get stack top,end         //~v304I~
	addr=stacktop;                                                 //~v304I~
    len=stackend-stacktop;                                         //~v304I~
	sprintf(stacka,"** stk=%08lX*",addr);                          //~v304I~
	fwrite(stacka,1,16,fh);                                        //~v304I~
	fwrite((void*)addr,1,(UINT)len,fh);                            //~v304R~
	fclose(fh);                                                    //~v304R~
#endif //!ULIB64X                                                  //~v6hiR~
    return;                                                        //~v304I~
}                                                                  //~v304I~
#ifndef ULIB64X                                                    //~v6F1R~
/***********************************************************************/
/*                                                                     */
/*            : uexhdlr                                                *///~v304R~
/*                                                                     */
/* INPUT      :                                                        */
//*     p1:exception reprt record addr
//*     p2:(user)exception registration record addr
//*     p3:context record
//*     p4:none
/*                                                                     */
/* OUTPUT     : exception information/dump file                        */
/*                                                                     */
/* RETURN     : continue search only								   *///~v053R~
/*                                                                     */
//*             display exception information by msgbox
//*             write storage to task dump file
/*                                                                     */
/***********************************************************************/

#ifdef DPMI					//DPMI version                         //~v053I~
ULONG          uexhdlr( PEXCEPTIONREPORTRECORD pexreprec,          //~v053I~
                      PEXCEPTIONREGISTRATIONRECORD pexregrec,      //~v053I~
                      PCONTEXTRECORD pctxrec)                      //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32  //copy from f:\toolkt21\c\os2h\bsexcpt.h               //~v022I~
ULONG          uexhdlr( PEXCEPTIONREPORTRECORD pexreprec,          //~v022I~
                      PEXCEPTIONREGISTRATIONRECORD pexregrec,      //~v022I~
                      PCONTEXTRECORD pctxrec)                      //~v022R~
#else                                                              //~v022I~
ULONG APIENTRY uexhdlr( PEXCEPTIONREPORTRECORD pexreprec,
                      PEXCEPTIONREGISTRATIONRECORD pexregrec,
                      PCONTEXTRECORD pctxrec,
                      PVOID pvoid)
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
{
   PUEXREGREC purr;
   ULONG      exnum; //exception number
   APIRET     apiret;//r.c
   UCHAR     *msgwk; //abend msg work area                      //~5827R~
   PVOID     exitmsg; //uerrexit msg                            //~5827R~
   int       len;                                               //~5827I~
static	PEPATBL  Spepatbl;                                      //~5826R~
static  int      Smapreadcall;                                  //~5826I~
static  int Sloopentry;                                            //~v304I~
extern int main(int,char*[]);
//********
#ifdef DPMI					//DPMI version                         //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32                                                         //~v022R~
#else                                                              //~v022I~
   apiret=(APIRET)pvoid; //avoid compile warning                   //~v022R~
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
   purr=(PUEXREGREC)(void*)pexregrec;
   exnum =pexreprec->ExceptionNum; //exception number

//**********************************************
//* ignore gurad page exception                *
//**********************************************

#ifdef DPMI					//DPMI version                         //~v053I~
#else                       //not DPMI                             //~v053I~
   if (  exnum==XCPT_GUARD_PAGE_VIOLATION     //just guard page
      || exnum==XCPT_UNABLE_TO_GROW_STACK     //unable to expand guard page
      )
     return (XCPT_CONTINUE_SEARCH);     //req system process(stack expand)
#endif                      //DPMI or not                          //~v053I~

//**********************************************
   purr->UERGflag |= UERGFENTRY;    //once enterd
//**********************************************
//* for the case main thread ended without killing sub thread
//**********************************************
   if (purr->UERGthreadid != 1                    //sub  thread
      && !( Spurr->UERGflag & UERGFEHACT ) //main normal end
      )
     return (XCPT_CONTINUE_SEARCH);     //req system process(stack expand)

#ifdef DPMI					//DPMI version                         //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32	                                                       //~v022I~
#else                                                              //~v022I~
//**********************************************
//*clear semaphore                             *
//**********************************************
   if (purr->UERGflag & UERGFENQ)//abend at eh
	{
     uehsem(MTX_RELEASE,&Shmtx);    //relesse semaphore
     purr->UERGflag &= ~UERGFENQ ; //e.h in progress
	}	
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~

//**********************************************
//*ignore related entry after once abend entry *
//**********************************************

#ifdef DPMI					//DPMI version                         //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
   if (  exnum==XCPT_PROCESS_TERMINATE       //myself thread termination
      || exnum==XCPT_UNWIND                  //system req at thread term
      )
     return (XCPT_CONTINUE_SEARCH);     //req system process(stack expand)
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~

//**********************************************                   //~v022I~
#ifdef DPMI					//DPMI version                         //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32     //no definition for ASYNC_PR...,PROCESS_TER..,UNWIND//~v022M~
#else                                                              //~v022M~
	if (exnum!=XCPT_ASYNC_PROCESS_TERMINATE) //other thread term   //~v022I~
#endif                                                             //~v022M~
#endif                      //DPMI or not                          //~v053I~
	if (purr->UERGflag & UERGFEHINP)	 //abend in eh             //~v022I~
    {                                                              //~v022I~
    	printf("==== ABEND at Exception Handler ====\n");          //~v022I~
        if (Sloopentry++==0)                                       //~v304R~
        {                                                          //~v304I~
			tempdump(Sloopentry,pexreprec,sizeof(EXCEPTIONREPORTRECORD),pctxrec,sizeof(CONTEXTRECORD));//~v304I~
        	msgwk="***ABEND AT Exception Handler***";              //~v304I~
        	uehdump(pexreprec,purr,pctxrec,msgwk,Spepatbl); //try dump after tempdump//~v304I~
        }                                                          //~v304I~
#ifdef DPMI					//DPMI version                         //~v169I~
   fcloseall();                                                    //~v169I~
#else                       //not DPMI                             //~v169I~
	#ifdef W32                                                     //~v169I~
    	fcloseall();                                               //~v169I~
	#else                                                          //~v169I~
    	_fcloseall();                                              //~v169I~
	#endif                                                         //~v169I~
#endif                      //DPMI or not                          //~v169I~
//     	return (XCPT_CONTINUE_SEARCH); //req system process        //~v286R~
    }                                                              //~v022I~
	tempdump(0,pexreprec,sizeof(EXCEPTIONREPORTRECORD),pctxrec,sizeof(CONTEXTRECORD));//~v304R~
			//for the case of double abend                         //~v304I~
    if (++purr->UERGentryctr>MAXEHENTRY)   //loop detection        //~v022I~
    {                                                              //~v286I~
       	if (purr->UERGentryctr>MAXEHENTRY+1)   //loop detection    //~v304R~
         	return (XCPT_CONTINUE_SEARCH); //req system process    //~v304R~
     	msgwk=uehmsg(pexreprec,&purr->UERGsys,pctxrec,Spepatbl,0); //~v286I~
       return (XCPT_CONTINUE_SEARCH); //req system process         //~v022M~
    }                                                              //~v286I~
                                                                   //~v022M~
//**********************************************
//*msg/dump process start                      *
//**********************************************

   purr->UERGflag |= UERGFEHINP; //in progress
	exitmsg=ugeterrmsg();		//get msg before user exit         //~v288I~
	if (purr->UERGuxfunc)
		purr->UERGuxfunc(0,purr);			//user exit
//*uerrexit msg save for new uerrmsg on e.h                     //~5827I~
//  if (exitmsg=ugeterrmsg(),exitmsg)                              //~v288R~
    if (exitmsg)                                                   //~v288I~
    {                                                           //~5827I~
    	len=(int)strlen(exitmsg)+1;                             //~5827R~
        msgwk=exitmsg;	//save for pvoid* use                   //~5827I~
#ifdef DPMI					//DPMI version                         //~v053I~
		exitmsg=malloc(len);                                       //~v053I~
		if (!exitmsg)                                              //~v053I~
        	apiret=16;                                             //~v053I~
		else                                                       //~v053I~
			apiret=0;                                              //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32                                                         //~v022R~
		exitmsg=HeapAlloc(GetProcessHeap(),                        //~v022R~
							HEAP_ZERO_MEMORY,//flag=clear,return NULL,serialize//~v022R~
	                    	len);        //req len                 //~v022R~
		if (!exitmsg)                                              //~v022R~
        	apiret=GetLastError();                                 //~v022R~
		else                                                       //~v022I~
			apiret=0;                                              //~v022I~
#else                                                              //~v022I~
		apiret=DosAllocMem(&exitmsg,             //output:addr  //~5827R~
                       (UINT)len,             //len             //~5827R~
                       PAG_COMMIT      //input attr,commit page //~5827I~
                        | PAG_WRITE    //writable               //~5827I~
                     );                                   //    //~5827I~
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
   		if(apiret)                                              //~5827I~
			exitmsg=0;                                          //~5827I~
		else                                                    //~5827I~
        	memcpy(exitmsg,msgwk,(UINT)len);                    //~5827R~
	}                                                           //~5827I~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
   msgwk=NULL; //clear for the case uehabinf not called
#endif                                                             //~v022I~

	if (!Smapreadcall)                                          //~5826R~
    {                                                           //~5826I~
		Smapreadcall=1;                                         //~5826I~
//  	ufuncmap(purr->UERGmapfn,(PVOID)(ULONG)main,&Spepatbl); //~5826R~//~v6hhR~
    	ufuncmap(purr->UERGmapfn,(PVOID)(ULPTR)main,&Spepatbl);    //~v6hhI~
UTRACEP("after ufuncmap,Spepatbl=%08x\n",Spepatbl);                //~v167I~
	}                                                           //~5826R~
                                                                //~5826I~
#ifdef DPMI					//DPMI version                         //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
   if ( exnum!=XCPT_ASYNC_PROCESS_TERMINATE )//another thread termination
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
//  printf("before uehmsg\n");                                     //~v022R~
UTRACEP("befoe uehmsg,Spepatbl=%08x\n",Spepatbl);                  //~v167I~
purr->UERGparm=&Spepatbl;       //for debug memory leak//@@@@      //~v167I~
     	msgwk=uehmsg(pexreprec,&purr->UERGsys,pctxrec,Spepatbl,exitmsg);//~5827R~
                            //abend information msgbox
//  printf("after uehmsg\n");                                      //~v022R~
UTRACEP("after uehmsg,Spepatbl=%08x\n",Spepatbl);                  //~v167R~

   if (purr->UERGdumpfn)
   {
#ifdef DPMI					//DPMI version                         //~v053I~
	 if (!(purr->UERGflag & UERGFDUMPED))//not once dump taken     //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32                                                         //~v022I~
	 if (!(purr->UERGflag & UERGFDUMPED))//not once dump taken     //~v022I~
#else                                                              //~v022I~
     if (  exnum!=XCPT_ASYNC_PROCESS_TERMINATE //another thread term
	    || !(purr->UERGflag & UERGFDUMPED) //not once dump taken
		)
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
	 {	
#ifdef DPMI					//DPMI version                         //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32	                                                       //~v022I~
#else                                                              //~v022I~
       uehsem(MTX_REQUEST,&Shmtx);    //request semaphore
       purr->UERGflag|= UERGFENQ ; //e.h in progress
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
//  printf("befoer uehdump\n");                                    //~v022R~
UTRACEP("before uehdump,Spepatbl=%08x\n",Spepatbl);                //~v167R~
       uehdump(pexreprec,purr,pctxrec,msgwk,Spepatbl); //dump   //~5826R~
   		printf("===== Dump Taken,%s\n",purr->UERGdumpfn);          //~v022R~
   
	   purr->UERGflag |= UERGFDUMPED; //once dump taken
#ifdef DPMI					//DPMI version                         //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32	                                                       //~v022I~
#else                                                              //~v022I~
       uehsem(MTX_RELEASE,&Shmtx);    //relesse semaphore
       purr->UERGflag &= ~UERGFENQ ; //e.h in progress
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
     }
   }

//****************************
//* free allocated msg work  * 
//****************************
   if(msgwk)//uehabend called         
   {
#ifdef DPMI					//DPMI version                         //~v053I~
    free(msgwk);                                                   //~v053I~
#else                       //not DPMI                             //~v053I~
#ifdef W32                                                         //~v022M~
//  printf("free heep %08x\n",msgwk);                              //~v022R~
	apiret=HeapFree(GetProcessHeap(),                              //~v022I~
					0,//flag=serialize                             //~v022I~
                    msgwk);        //req len                       //~v022I~
	if (!apiret)                                                   //~v022I~
    {                                                              //~v022I~
    	apiret=GetLastError();                                     //~v022I~
    	uerrexit("HeapFree failed,rc=%d,addr=%08x",0,apiret,msgwk);//~v022I~
    }                                                              //~v022I~
#else                                                              //~v022M~
     apiret=DosFreeMem(msgwk);         //input:,addr
     if(apiret)
       uerrexit("DosFreeMem failed,rc=%d,addr=%08x",0,apiret,msgwk);
#endif                                                             //~v022M~
#endif                      //DPMI or not                          //~v053I~
   }
//**********************************************
//* return(continue termination only)          *
//**********************************************
	if (purr->UERGuxfunc)
		purr->UERGuxfunc(2,purr);			//user exit
   purr->UERGflag &=~UERGFEHINP ; //in progress reset
#ifdef DPMI					//DPMI version                         //~v053M~
   fcloseall();                                                    //~v053M~
#else                       //not DPMI                             //~v053M~
   pexreprec->fHandlerFlags|=EH_NONCONTINUABLE;//request dont retry
#ifdef W32                                                         //~v022R~
   fcloseall();                                                    //~v022I~
#else                                                              //~v022I~
   _fcloseall();                                                //~5813I~
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v053I~
   return (XCPT_CONTINUE_SEARCH);

}//uexhdlr
#else                                                              //~v6F1I~
/***********************************************************************///~v6F1I~
ULONG          uexhdlr( PEXCEPTIONREPORTRECORD pexreprec,          //~v6F1I~
                      PEXCEPTIONREGISTRATIONRECORD pexregrec,      //~v6F1I~
                      PCONTEXTRECORD pctxrec)                      //~v6F1I~
{                                                                  //~v6F1I~
   PUEXREGREC purr;                                                //~v6F1I~
   ULONG      exnum; //exception number                            //~v6F1I~
   APIRET     apiret;//r.c                                         //~v6F1I~
   UCHAR     *msgwk; //abend msg work area                         //~v6F1I~
   PVOID     exitmsg; //uerrexit msg                               //~v6F1I~
   int       len;                                                  //~v6F1I~
static	PEPATBL  Spepatbl;                                         //~v6F1I~
static  int      Smapreadcall;                                     //~v6F1I~
static  int Sloopentry;                                            //~v6F1I~
extern int main(int,char*[]);                                      //~v6F1I~
//********                                                         //~v6F1I~
   purr=(PUEXREGREC)(void*)pexregrec;                              //~v6F1I~
   exnum =pexreprec->ExceptionNum; //exception number              //~v6F1I~
                                                                   //~v6F1I~
//**********************************************                   //~v6F1I~
//* ignore gurad page exception                *                   //~v6F1I~
//**********************************************                   //~v6F1I~
                                                                   //~v6F1I~
   if (  exnum==XCPT_GUARD_PAGE_VIOLATION     //just guard page    //~v6F1I~
      || exnum==XCPT_UNABLE_TO_GROW_STACK     //unable to expand guard page//~v6F1I~
      )                                                            //~v6F1I~
     return (XCPT_CONTINUE_SEARCH);     //req system process(stack expand)//~v6F1I~
                                                                   //~v6F1I~
//**********************************************                   //~v6F1I~
   purr->UERGflag |= UERGFENTRY;    //once enterd                  //~v6F1I~
//**********************************************                   //~v6F1I~
//* for the case main thread ended without killing sub thread      //~v6F1I~
//**********************************************                   //~v6F1I~
   if (purr->UERGthreadid != 1                    //sub  thread    //~v6F1I~
      && !( Spurr->UERGflag & UERGFEHACT ) //main normal end       //~v6F1I~
      )                                                            //~v6F1I~
     return (XCPT_CONTINUE_SEARCH);     //req system process(stack expand)//~v6F1I~
                                                                   //~v6F1I~
                                                                   //~v6F1I~
//**********************************************                   //~v6F1I~
	if (purr->UERGflag & UERGFEHINP)	 //abend in eh             //~v6F1I~
    {                                                              //~v6F1I~
    	printf("==== ABEND at Exception Handler ====\n");          //~v6F1I~
        if (Sloopentry++==0)                                       //~v6F1I~
        {                                                          //~v6F1I~
//  		tempdump(Sloopentry,pexreprec,sizeof(EXCEPTIONREPORTRECORD),pctxrec,sizeof(CONTEXTRECORD));//~v6F1R~
        	msgwk="***ABEND AT Exception Handler***";              //~v6F1I~
#ifdef AAA //@@@@test                                              //~v6F1I~
        	uehdump(pexreprec,purr,pctxrec,msgwk,Spepatbl); //try dump after tempdump//~v6F1I~
#endif                                                             //~v6F1I~
        }                                                          //~v6F1I~
    	fcloseall();                                               //~v6F1I~
    }                                                              //~v6F1I~
//  tempdump(0,pexreprec,sizeof(EXCEPTIONREPORTRECORD),pctxrec,sizeof(CONTEXTRECORD));//~v6F1R~
			//for the case of double abend                         //~v6F1I~
    if (++purr->UERGentryctr>MAXEHENTRY)   //loop detection        //~v6F1I~
    {                                                              //~v6F1I~
       	if (purr->UERGentryctr>MAXEHENTRY+1)   //loop detection    //~v6F1I~
         	return (XCPT_CONTINUE_SEARCH); //req system process    //~v6F1I~
     	msgwk=uehmsg(pexreprec,&purr->UERGsys,pctxrec,Spepatbl,0); //~v6F1I~
       return (XCPT_CONTINUE_SEARCH); //req system process         //~v6F1I~
    }                                                              //~v6F1I~
                                                                   //~v6F1I~
//**********************************************                   //~v6F1I~
//*msg/dump process start                      *                   //~v6F1I~
//**********************************************                   //~v6F1I~
                                                                   //~v6F1I~
   purr->UERGflag |= UERGFEHINP; //in progress                     //~v6F1I~
	exitmsg=ugeterrmsg();		//get msg before user exit         //~v6F1I~
	if (purr->UERGuxfunc)                                          //~v6F1I~
		purr->UERGuxfunc(0,purr);			//user exit            //~v6F1I~
//*uerrexit msg save for new uerrmsg on e.h                        //~v6F1I~
    if (exitmsg)                                                   //~v6F1I~
    {                                                              //~v6F1I~
    	len=(int)strlen(exitmsg)+1;                                //~v6F1I~
        msgwk=exitmsg;	//save for pvoid* use                      //~v6F1I~
		exitmsg=HeapAlloc(GetProcessHeap(),                        //~v6F1I~
							HEAP_ZERO_MEMORY,//flag=clear,return NULL,serialize//~v6F1I~
	                    	len);        //req len                 //~v6F1I~
		if (!exitmsg)                                              //~v6F1I~
        	apiret=GetLastError();                                 //~v6F1I~
		else                                                       //~v6F1I~
			apiret=0;                                              //~v6F1I~
   		if(apiret)                                                 //~v6F1I~
			exitmsg=0;                                             //~v6F1I~
		else                                                       //~v6F1I~
        	memcpy(exitmsg,msgwk,(UINT)len);                       //~v6F1I~
	}                                                              //~v6F1I~
                                                                   //~v6F1I~
//    if (!Smapreadcall)                                           //~v6F1R~
//    {                                                            //~v6F1R~
//        Smapreadcall=1;                                          //~v6F1R~
//        ufuncmap(purr->UERGmapfn,(PVOID)(ULPTR)main,&Spepatbl);  //~v6F1R~
//UTRACEP("after ufuncmap,Spepatbl=%08x\n",Spepatbl);              //~v6F1R~
//    }                                                            //~v6F1R~
                                                                   //~v6F1I~
UTRACEP("befoe uehmsg,Spepatbl=%08x\n",Spepatbl);                  //~v6F1I~
//purr->UERGparm=&Spepatbl;       //for debug memory leak//@@@@    //~v6F1R~
     	msgwk=uehmsg(pexreprec,&purr->UERGsys,pctxrec,Spepatbl,exitmsg);//~v6F1I~
                            //abend information msgbox             //~v6F1I~
UTRACEP("after uehmsg,Spepatbl=%08x\n",Spepatbl);                  //~v6F1I~
#ifdef AAA //@@@@test                                              //~v6F1R~
   if (purr->UERGdumpfn)                                           //~v6F1I~
   {                                                               //~v6F1I~
	 if (!(purr->UERGflag & UERGFDUMPED))//not once dump taken     //~v6F1I~
	 if (!(purr->UERGflag & UERGFDUMPED))//not once dump taken     //~v6F1I~
	 {                                                             //~v6F1I~
UTRACEP("before uehdump,Spepatbl=%08x\n",Spepatbl);                //~v6F1I~
       uehdump(pexreprec,purr,pctxrec,msgwk,Spepatbl); //dump      //~v6F1I~
   		printf("===== Dump Taken,%s\n",purr->UERGdumpfn);          //~v6F1I~
                                                                   //~v6F1I~
	   purr->UERGflag |= UERGFDUMPED; //once dump taken            //~v6F1I~
     }                                                             //~v6F1I~
   }                                                               //~v6F1I~
#endif                                                             //~v6F1R~
//****************************                                     //~v6F1I~
//* free allocated msg work  *                                     //~v6F1I~
//****************************                                     //~v6F1I~
   if(msgwk)//uehabend called                                      //~v6F1I~
   {                                                               //~v6F1I~
	apiret=HeapFree(GetProcessHeap(),                              //~v6F1I~
					0,//flag=serialize                             //~v6F1I~
                    msgwk);        //req len                       //~v6F1I~
	if (!apiret)                                                   //~v6F1I~
    {                                                              //~v6F1I~
    	apiret=GetLastError();                                     //~v6F1I~
    	uerrexit("HeapFree failed,rc=%d,addr=%08x",0,apiret,msgwk);//~v6F1I~
    }                                                              //~v6F1I~
   }                                                               //~v6F1I~
//**********************************************                   //~v6F1I~
//* return(continue termination only)          *                   //~v6F1I~
//**********************************************                   //~v6F1I~
	if (purr->UERGuxfunc)                                          //~v6F1I~
		purr->UERGuxfunc(2,purr);			//user exit            //~v6F1I~
   purr->UERGflag &=~UERGFEHINP ; //in progress reset              //~v6F1I~
   pexreprec->fHandlerFlags|=EH_NONCONTINUABLE;//request dont retry//~v6F1I~
   fcloseall();                                                    //~v6F1I~
   return (XCPT_CONTINUE_SEARCH);                                  //~v6F1I~
                                                                   //~v6F1I~
}//uexhdlr                                                         //~v6F1I~
#endif  //ULIB64X                                                  //~v6F1R~
