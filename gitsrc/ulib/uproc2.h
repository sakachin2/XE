//*CID://+v6XaR~:                              update#=  117;      //+v6XaR~
//************************************************************* //~5825I~
//*proc2.h                                                         //~v5ebR~
//************************************************************* //~5825I~
//v6Xa:180821 enumproc show fullpath(xp was shoing)                //+v6XaI~
//v6X6:180819 (W32)enumproc optionally output fullpath exe name    //~v6X6I~
//v6xr:150118 (BUG of v6xm) 6xm is for W7 only;back to old logic when XP//~v6xrI~
//v6xp:150116 (BUG:LNX)kill parm is not thread_t but pid_t         //~v6xpI~
//v6xn:150116 (BUG:W64)ugetpidfromhandle() fails on Windows7.use GetProcessId()//~v6xnI~
//v6xj:150115 (BUG:W64)uintptr_t is 8byte                          //~v6xjI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5kv:070709 for xkp to display parent pid                        //~v5kvI~
//v5ku:070705 helpmsg wait should be avoid when redirected         //~v5kuI~
//v5ja:060921 (LNX)3270 support                                    //~v5jaI~
//v5iv:060906 3270server support(2nd cmdserver)                    //~v5ivI~
//v5it:060826 gcc:submit abend by bat file is not .bat by getpid is not done(gcc support getpid)//~v5itI~
//v5is:060826 stdin support for uprocparseredirect                 //~v5isI~
//v5g1:050428 ugetpid function add                                 //~v5g1I~
//v5ev:041031 ftp chmod:try rsh after setmod failed                //~v5evI~
//v5eu:041031 rsh support                                          //~v5euI~
//v5eb:041011 uproc2:parseredirect function for xedcmd             //~v5ebI~
//************************************************************* //~5A10I~
#ifdef UNX                                                         //~v5isI~
	#define NULLDEVICE  "/dev/null"                                //~v5isI~
#else                                                              //~v5isI~
	#define NULLDEVICE  "NUL"                                      //~v5isI~
#endif                                                             //~v5isI~
//*************************************************************    //~v5jaI~
#ifndef NOMT                                                       //~v5ncI~
//*********************************************                    //~v5jaM~
#ifdef LNX                                                         //~v5jaM~
    typedef struct _UEVENTCB {                                     //~v5jaM~
                int               UECBflag;         //ecb type     //~v5jaM~
    #define UECBF_MANUAL          0x01              //manual reset //~v5jaM~
    #define UECBF_ECBLIST         0x02              //ecb of ecblist//~v5jaM~
    #define UECBF_WAITALL         0x04              //wait  all ecb posted//~v5jaM~
    #define UECBF_POSTED          0x10              //once posted  //~v5jaM~
    #define UECBF_WAITING         0x20              //waiting      //~v5jaM~
                pthread_cond_t    UECBcond;         //condition variable of this ECB//~v5jaM~
                void             *UECBpecblist;     //ECB:ptr to UEVENTCB of ecblist, ECBLIST:ptr to UEVENTLIST//~v5jaM~
                        } UEVENTCB,*PUEVENTCB;                     //~v5jaM~
    #define UEVENTCBSZ sizeof(UEVENTCB)                            //~v5jaM~
#endif                                                             //~v5jaM~
#endif //!NOMT                                                     //~v5ncI~
//*************************************************************    //~v5isI~
//int uprocparseredirect(char *Pcmd,char *Pstdofnm,char *Pstdefnm,int *Ppflag,int *Ppcmdlen);//~v5isR~
int uprocparseredirect(char *Pcmd,char *Pstdifnm,char *Pstdofnm,char *Pstdefnm,int *Ppflag,int *Ppcmdlen);//~v5isI~
#define PRERC_STDOAPPEND 0x01                                      //~v5ebI~
#define PRERC_STDEAPPEND 0x02                                      //~v5ebI~
//*************************************************************    //~v5euI~
int uproc_rsh(ULONG Popt,void *Pphost,char *Ppuser,char *Ppcmd,char *Ppstdofnm,char *Ppstdefnm,//~v5evR~
			char ***Pppstdo,int *Ppstdoctr,char ***Pppstde,int *Ppstdectr);//~v5euM~
//*************************************************************    //~v5g1I~
//#ifndef DOS                                                      //~v5itR~
ULONG ugetpid(void);                                               //~v5g1I~
//#endif                                                           //~v5itR~
                                                                   //~v5ivI~
//#ifdef W32                                                       //~v5jaR~
#if defined(W32)||defined(LNX)                                     //~v5jaI~
                                                                   //~v5ivI~
//*************************************************************    //~v5ivI~
//int ukillph(ULONG Ppid,int Pexitcode);                             //~v5ivI~//~v6hhR~
int ukillph(ULPTR Ppid,int Pexitcode);                             //~v6hhR~
//*************************************************************    //~v5ivI~
//int ukillpid(ULONG Ppid,int Pexitcode);                          //~v5jaR~
//int ukillpid(void *Pppid,int Psignal);                             //~v5jaI~//~v6xpR~
int ukillpid(ULONG *Pppid,int Psignal);                            //~v6xpI~
//*************************************************************    //~v5ivI~
//ULONG ugetpidfromhandle(ULONG Php);                                //~v5ivI~//~v6hhR~
ULONG ugetpidfromhandle(ULPTR Php);                                //~v6hhR~
//*************************************************************    //~v6xnI~
#ifdef W32                                                         //~v6xnI~
    #define UGETPROCESSID(opt,handle) ugetprocessid(opt,handle);   //~v6xnI~
	DWORD ugetprocessid(int Popt,ULPTR Pprocesshandle);            //~v6xnR~
    #define UGPIO_ERRMSG 0x01                                      //~v6xnI~
#else                                                              //~v6xnI~
    #define UGETPROCESSID(opt,handle) (handle)                     //~v6xnI~
#endif                                                             //~v6xnI~
//*************************************************************    //~v5ivI~
#ifdef LNX                                                         //~v5jaI~
	typedef void *(UTHFUNC)(void *Pparm);                          //~v5jaI~
#else                                                              //~v5jaI~
typedef void (UTHFUNC)(void *Pparm);                               //~v5ivM~
#endif                                                             //~v5jaI~
                                                                   //~v5ncI~
#ifndef NOMT                                                       //~v5ncI~
                                                                   //~v5ncI~
//ULONG uthread(int Popt,UTHFUNC Pfunc,int Pstacksz,ULONG Pparm,ULONG *Ppthid);//~v5ivI~//~v6hhR~
//ULONG uthread(int Popt,UTHFUNC Pfunc,int Pstacksz,ULPTR Pparm,ULONG *Ppthid);//~v6xjR~
ULPTR uthread(int Popt,UTHFUNC Pfunc,int Pstacksz,ULPTR Pparm,ULONG *Ppthid);//~v6xjI~
#define UTHO_SUSPEND     0x01                                      //~v5ivM~
#define UTHO_INHERIT     0x02                                      //~v5ivM~
//*************************************************************    //~v5ivI~
//int uevent(int Popt,int Peventcnt,ULONG *Peventcb,int Ptimeout,int *Ppindex);//~v5ivI~//~v6hhR~
int uevent(int Popt,int Peventcnt,ULPTR *Peventcb,int Ptimeout,int *Ppindex);//~v6hhR~
#define UEVENTO_INIT        0x01                                   //~v5ivM~
#define UEVENTO_WAIT        0x02                                   //~v5ivM~
#define UEVENTO_WAITALL     0x04                                   //~v5ivM~
#define UEVENTO_POST        0x08                                   //~v5ivM~
#define UEVENTO_RESET       0x10 //even if auto event,leave  posted when timeout//~v5ivI~
#define UEVENTO_MANUALRESET 0x0100 //ecb option;manual reset       //~v5ivI~
#define UEVENTO_INITSIGNAL  0x0200 //ecb option;initialy signaled  //~v5ivI~
                                                                   //~v5ivM~
#define UEVENTRC_POSTED     0x00                                   //~v5ivM~
#define UEVENTRC_TIMEOUT    0x01000000                             //~v5ivR~
#define UEVENTRC_ABANDONED  0x02000000    //thred ended            //~v5ivR~
#define UEVENTRC_DUPWAIT    0x04000000    //duplicated wait on the ecb//~v5jaI~
#define UEVENTRC_ERR        0x10000000    //other err              //~v5jaI~
#define UEVENTRC_APIERR     0x00ffffff    //api err mask           //~v5ivI~
//*************************************************************    //~v5ivI~
//void ucriticalsection(int Popc,ULONG Ppsem);                     //~v5jaR~
//int ucriticalsection(int Popc,ULONG Ppsem);                        //~v5jaI~//~v6hhR~
int ucriticalsection(int Popc,ULPTR Ppsem);                        //~v6hhR~
#define CRITSEC_INIT     0                                         //~v5ivM~
#define CRITSEC_ENTER    1                                         //~v5ivM~
#define CRITSEC_LEAVE    2                                         //~v5ivM~
#define CRITSEC_DELETE   3                                         //~v5ivM~
#ifdef LNX                                                         //~v5jaI~
    #define CRITSEC_REQIDMASK   0xff                               //~v5jaI~
    #define CRITSEC_PRIVATE   0x0100  //use private semaphore      //~v5jaR~
    #define CRITSEC_MUTEX     0x0200  //use pthread mutex          //~v5jaI~
#endif                                                             //~v5jaI~
                                                                   //~v5ncI~
#endif //!NOMT                                                     //~v5ncI~
                                                                   //~v5ncI~
//*************************************************************    //~v5ivI~
//typedef int (CB_ENUMPID)(ULONG Ppid,USHORT Ppid16,char *Pcmd,void *Pparm);//~v5ivR~//~v6xrR~
typedef int (CB_ENUMPID)(int Popt,ULONG Ppid,USHORT Ppid16,char *Pcmd,void *Pparm);//~v6xrI~
#define CBEPIO_KERNEL_LOGIC     0x01	//enum by kernel logic     //~v6xrI~
//*ret true:continue enum,false:stop enum                          //~v5ivI~
//int uenumpid(CB_ENUMPID Pcbfunc,void *Pparm);                    //~v5kvR~
int uenumpid(int Popt,CB_ENUMPID Pcbfunc,void *Pparm);             //~v5kvI~
#define UEPI_HELPER 0x01                                           //~v5kvI~
//#define UEPI_VERBOSE  0x02  //output fullpath exe name             //~v6X6R~//+v6XaR~
//*************************************************************    //~v5ivI~
int getprocstatus(ULONG Phandle);                                  //~v5ivI~
#endif  //W32||LNX                                                 //~v5jaR~
//*************************************************************    //~v5kuI~
int uprocredirectchk(int Pfileno);                                 //~v5kuI~
