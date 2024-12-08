//*CID://+vbzuR~:                             update#=   73;       //~v778R~//~vbzuR~
//**********************************************************************
//vbzu:240302 add test option to notrace while mapinit for performance. (del prev option /Yn/Nn to winNT option)//~vbzuI~
//v778:230405 add flush function to utrace for arm                 //~v778I~
//v750:221120 warning ftime deprecated for UTSSTART/UTSEND when TRACE=YES//~v750I~
//v70q:200919 (ARM)add gettraceopt                                 //~v70qI~
//v706:200616 ARM:redirect UTRACE to LOGPD                         //~v706I~
//v6X9:180821 snprintf is from msvs2015(err at xp:2010)            //~v6V9I~
//v6Vu:180622 UTRACE;support force option off                      //~v6VuI~
//v6Vi:180617 support __LINE__ for UTRACEP                         //~v6ViI~
//v6B1:160114 trace,mtrace file no share mode                      //~v6B1I~
//v6w2:141201 (Axe:BUG)undef UTSSTART/UTSEND for amm because eclipse release build(android tool build signed apk) dose not set -DNOTRACE.//~v6wqI~
//            NDEBUG macro is not applicaple because eclipse set it also normal build//~v6wqI~
//v6uS:140606 add UTRACEDCOND                                      //~v6uSI~
//v6u9:140408 (Win)use UNICODE Api using special filename fmt.     //~v6u9I~
//v6t1:140316 macro:__FUNCTION__ is avail                          //~v6t1I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v5mq:080427*gcc suport variable number of argument               //~v5mqI~
//v619:071205 (UTF)add UTRACEDIFNZ                                 //~v619I~
//v60g:071102 UTRACEP skip code generation when NOTRACE            //~v60gI~
//v5j0:060911 (WIN)utrace multi thread support                     //~v5j0I~
//v5ik:060719*elapsted time calc macro                             //~v5ikI~
//v5ie:060620 (LNX:UTF)avoid compile warning (UTRACED etc for __FUNCTION__)//~v5ikI~
//v570:020824 wxe support                                          //~v570I~
//v324 000813:LINUX support(CRLF)                                  //~v324R~
//v322:000223:EBCIDIC code dump function                           //~v322R~
//v041:961027:UTRACEP NOTRACE option                               //~v041I~
//v034:961008:VisualC++ support(identify by (_MSC_VER>=800))       //~v034I~
//v014:960203:printf format UTRACEP                             //~v014I~
//**********************************************************************
// UTRCAEI/UTRACED/UTRACES/UTRACEOPT macro process              //~v014M~
//**********************************************************************//~6203I~
// FORMAT(changed 019)
//   UTRACEI(comment,int)		//integer or char trace
//     -->   utrace(__FILE__,__LINE__,'i',comment,int,0);
//   UTRACES(comment,string,len)	//string trace
//     -->   utrace(__FILE__,__LINE__,'s',comment,string,len);//len parm may be 0(use strlen)
//   UTRACED(comment,addr,len)	//area dump trace
//     -->   utrace(__FILE__,__LINE__,'d',comment,addr,len);
//   UTRACED_EBC(comment,addr,len)	//area dump trace              //~v322R~
//     -->   utrace_ebc(__FILE__,__LINE__,'d',comment,addr,len);   //~v322R~
//   UTRACEP(...printf format ...)                              //~v014R~
//      ex UTRACE("%s\n",fname);                                //~v014R~
//   rc=UTRACE_INIT(trace_file_name,option)	//trace option set  //~5829I~
//       (option==>0:inactive, 1:active, 2:ignore open err,3 inact and close)//~5829I~
//       (rc    ==>0:open ok,  else:errno for option=2)         //~5829I~
//     -->rc=utrace_init(__FILE__,__LINE__,'d',trace_file_name,option);//~5829R~
//**********************************************************************
//#ifdef ARM                                                       //~v6wqR~
//    #ifdef NDEBUG //release build                                //~v6wqR~
//        #ifdef TRACE                                             //~v6wqR~
//            #undef TRACE                                         //~v6wqR~
//        #endif                                                   //~v6wqR~
//        #ifndef NOTRACE                                          //~v6wqR~
//            #define NOTRACE                                      //~v6wqR~
//        #endif                                                   //~v6wqR~
//    #endif                                                       //~v6wqR~
//#endif                                                           //~v6wqR~
                                                                   //~v6wqI~
#define GTRACEHDRSZ 256                                            //~v6ViI~
                                                                   //~v6ViI~
#ifdef __cplusplus                                                 //~v440I~//~v6ViM~
extern  "C"                                                        //~v6ViR~
{                                                                  //~v6ViI~
#endif                                                             //~v6ViI~
                                                                   //~v6ViI~
#ifdef GBL_UTRACE	                                               //~v6ViM~
	char Gtracehdr[GTRACEHDRSZ];                                   //~v6ViM~
#else                                                              //~v6ViM~
	extern char Gtracehdr[GTRACEHDRSZ];                            //~v6ViI~
#endif                                                             //~v6ViR~
                                                                   //~v6ViI~
#ifdef __cplusplus                                                 //~v6ViI~
} // cpp extern C                                                  //~v6ViI~
#endif //cpp                                                       //~v6ViI~
                                                                   //~v6ViI~
#ifdef NOTRACE
	#define UTRACEP_(printfparm)                                   //~v60gM~
  #ifdef LNX                                                       //~v5mqI~
	#define UTRACEP(p1,p2...)                                      //~v5mqR~
	#define UTRACEPF(p1,p2...)                                     //~v6a0I~
	#define UTRACEPF2(...)                                         //~v6VuI~
	#define UTRACEP_FLUSH(fmt,...)                                 //~v778I~
  #else                                                            //~v5mqI~
	#define UTRACEP      utracepnop                                //~v041I~
	#define UTRACEPF     utracepnop                                //~v6a0I~
	#define UTRACEPF2    utracepnop                                //~v6VuI~
	#define UTRACEP_FLUSH utracepnop                               //~v778I~
  #endif                                                           //~v5mqI~
	#define UTRACEI(comment,int)                                //~v014I~
	#define UTRACES(comment,string,len)                         //~v014I~
	#define UTRACED(comment,addr,len)                           //~6203I~
	#define UTRACEDCOND(cond,comment,addr,len)                     //~v6uSI~
	#define UTRACEDIFNZ(comment,addr,len)                          //~v619I~
	#define UTRACED_EBC(comment,addr,len)                          //~v322R~
	#define UTRACE_INIT(filename,opt)                           //~v014I~
    #define UTSSTART(currtime)                                     //~v5ikI~
    #define UTSEND(starttime,accum)                                //~v5ikI~
    #define PRINTUWCH(prefix,pwucs,postfix)                        //~v6u9I~
    #define UTRACETIT      "UTRACETIT"                             //~v6u9R~
    #define UTT UTRACETIT   //abridgement                          //~v6u9I~
#else
                                                                   //~v6ViI~
	#ifdef DOS
		#define UTRACETIT __FILE__
	#else
    	#ifdef W32                                                 //~v034I~
#ifdef AAA                                                         //~v6t1I~
    		#define UTRACETIT __FILE__                             //~v034I~
#else                                                              //~v6t1I~
    		#define UTRACETIT (char *)__FUNCTION__                 //~v6t1I~
#endif                                                             //~v6t1I~
    	#else                                                      //~v034I~
//  	#define UTRACETIT __FUNCTION__                             //~v5ieR~
    		#define UTRACETIT (char *)__FUNCTION__                 //~v5ieI~
    	#endif                                                     //~v034I~
	#endif
                                                                   //~v6u9I~
    #ifdef W32UNICODE                                              //~v6u9R~
    	#define PRINTUWCH(prefix,pwucs,postfix)  printUWCH(0,prefix,pwucs,postfix)//~v6u9I~
    #else                                                          //~v6u9I~
	    #define PRINTUWCH(prefix,pwucs,postfix)                    //~v6u9I~
    #endif                                                         //~v6u9R~
                                                                   //~v6u9I~
//  #define UTT UTRACETIT   //abridgement                          //~v6u0R~//~v6u9M~//~v6ViR~
#if defined(_MSC_VER) && _MSC_VER <1900                            //~v6V9I~
    #define UTT UTRACETIT   //abridgement                          //~v6V9I~
#else                                                              //~v6V9I~
    #define UTT (snprintf(Gtracehdr,GTRACEHDRSZ,"%s-%d",UTRACETIT,__LINE__),Gtracehdr)   //abridgement//~v6ViI~
#endif                                                             //~v6V9I~
	#define UTRACEP      utracepop                                 //~v041I~
	#define UTRACEPF     utracepopf  //write regardless trace option//~v6a0I~
	#define UTRACEPF2(fmt,...) (UTRACEP(fmt,__VA_ARGS__),UTRACEPF(fmt,__VA_ARGS__))//~v6VuI~
	#define UTRACEP_FLUSH(fmt,...) UTRACEP(fmt,__VA_ARGS__),UTRACE_FLUSH("")//~v778I~
	#ifdef LNX                                                     //~v60gI~
		#define UTRACEP_(printfparm) utracepop printfparm; //linux compile err invalid preprocessor token//~v60gI~
	#else                                                          //~v60gI~
		#define UTRACEP_(printfparm) utracepop##printfparm; //usage:UTRACEP_(("...",a,b,c))//~v60gR~
	#endif                                                         //~v60gI~
	#define UTRACEI(comment,int)        utrace(UTRACETIT,__LINE__,'i',(comment),0,(int))
	#define UTRACES(comment,string,len) utrace(UTRACETIT,__LINE__,'s',(comment),(void*)(string),(len))
	#define UTRACED(comment,addr,len)   utrace(UTRACETIT,__LINE__,'d',(comment),(void*)(addr),(len))
	#define UTRACEDCOND(cond,comment,addr,len)   do { if ((cond)) utrace(UTRACETIT,__LINE__,'d',(comment),(void*)(addr),(len));}while(0)//~v6uSR~
	#define UTRACEDIFNZ(comment,addr,len)   if ((addr)) utrace(UTRACETIT,__LINE__,'d',(comment),(void*)(addr),(len))//~v619I~
	#define UTRACED_EBC(comment,addr,len)   utrace_ebc(UTRACETIT,__LINE__,'d',(comment),(void*)(addr),(len))//~v322R~
	#define UTRACE_INIT(filename,opt)   utrace_init((filename),(opt))
#ifdef UNX                                                         //~v5ikI~
  #ifdef ARM                                                       //~v6wqR~
    #define UTSSTART(currtime)                                     //~v6wqM~
    #define UTSEND(starttime,accum)                                //~v6wqM~
  #else                                                            //~v6wqM~
	#define UTRACE_TIME_SUB(high1,low1,high2,low2)         \
        (low1<low2 ? (high1-=high2+1,low1+=1000-low2) :    \
		             (high1-=high2,low1-=low2))                    //~v5ikI~
//  #define UTSSTART(starttime) ftime(&starttime)	/*struct timeb*///~v5ikI~//~v750R~
//  #define UTSEND(starttime,accum)                                //~v750R~
//    	{                                                          //~v750R~
//			struct    timeb ct;                                    //~v750R~
//          ftime(&ct);	/*current*/		                           //~v750R~
//          UTRACE_TIME_SUB(ct.time,ct.millitm,starttime.time,starttime.millitm);//~v750R~
//          accum+=ct.time*1000+ct.millitm;                        //~v750R~
//      }                                                          //~v5ikI~//~v750R~
    #define UTSSTART(currtime)                                     //~v750I~
    #define UTSEND(starttime,accum)                                //~v750I~
  #endif //NOTSTRACE                                               //~v6wqI~
#else                                                              //~v5ikI~
#ifdef DOS                                                         //~v5ikI~
    #define UTSSTART(starttime)  /*long*/                  \
    {                                                      \
	    union REGS reg;                                     \
    	reg.h.ah=0x2c;                                      \
    	intdos(&reg,&reg);  /*ch:hh,cl:mm,dh:ss,dl:1/100sec*/ \
        strattime=reg.cx;                                    \
        strattime=(starttime<<16)+reg.dx;                     \
    }                                                              //~v5ikI~
#else                                                              //~v5ikI~
    #ifdef W32                                                     //~v5ikI~
	    #define UTSSTART(starttime) GetLocalTime(&starttime) /*SYSTEMTIME*///~v5ikI~
    #else                                                          //~v5ikI~
	    #define UTSSTART(starttime) DosGetDateTime(&datetime)       /*DATETIME*///~v5j0I~
    #endif                                                         //~v5ikI~
#endif                                                             //~v5ikI~
#endif  //!UNX                                                     //~v5ikI~
#endif
    #ifdef W32UNICODE                                              //~v6u9M~
    	void printUWCH(int Popt,char *Pprefix,UWCH *Ppwucs,char *Ppostfix);//~v6u9M~
    	#define PUWCHO_OPEN     0x01                               //~v6u9M~
    #endif                                                                   //~v5ikI~//~v6u9M~
#define UTRACE_FLUSH utrace_flush                                  //~v778I~
//*********************************************************************
#ifdef __cplusplus                                                 //~v570I~
	extern "C" {                                                   //~v570I~
#endif                                                             //~v570I~
//****************************************************************//~5807I~
int  utrace_init(char *Putracefile,int Popt);                   //~5829R~
#define UTRACEO_ON              0x01     //trace on                //~v5j0I~
#define UTRACEO_IGNOREOPENERR   0x02                               //~v5j0I~
#define UTRACEO_MT              0x04     //multi thread            //~v5j0I~
#ifdef ARM                                                         //~v6a0I~
	#define UTRACEO_LOGCAT      0x08     //additionaly write to logcat//~v6a0I~
#endif //ARM                                                       //+vbzuM~
	#define UTRACEO_REOPEN      0x10                               //~v6a0I~
	#define UTRACEO_TEMPCLOSE   0x20                               //~v6a0I~
//#endif //ARM                                                       //~v6a0I~//~vbzuR~
#define UTRACEO_NOSHARE         0x40     //exclusive write open    //~v6B1I~
#define UTRACEO_NOFORCE       0x0080     //ignore UTRACEPF(put trace regardless trace option)//~v6VuR~
#define UTRACEO_FORCEFNM      0x0100     //notify UTRACEPF output filename//~v6VuI~
#ifdef ARM                                                         //~v70qI~
#define UTRACEO_NOTREMAP      0x0200     //no sdcard permission    //~v70qI~
#endif //ARM                                                       //~v70qI~
                                                                   //~v5j0I~
//**************************************************************** //~v5j0I~
int  utrace_initmt(void *Psem);                                    //~v5j0R~
//**************************************************************** //~v70qI~
#ifdef ARM                                                         //~v70qI~
int utrace_getopt();                                               //~v70qI~
#endif //ARM                                                       //~v70qI~
                                                                //~v014I~
//****************************************************************//~v014I~
void utracepop(char *Pfmt,...);                                    //~v041R~
void utracepopf(char *Pfmt,...);                                   //~v6a0I~
void utrace_flush(char *Pcmt);                                     //~v778R~
                                                                //~v014I~
//**************************************************************** //~v041I~
void utracepnop(char *Pfmt,...);                                   //~v041I~
                                                                   //~v041I~
//****************************************************************//~5807I~
void utrace (char * Pfile,int Pline,int Ptype,char *Pcomment,void *Paddr,int Plen);//~5807I~
//***************************************************************  //~v322R~
void utrace_ebc(char * Pfile,int Pline,int Ptype,char *Pcomment,void *Paddr,int Plen);//~v322R~
//**************************************************************** //~v6B1M~
int  utrace_term(int Popt);                                        //~v6B1I~
#ifdef __cplusplus                                                 //~v570I~
	}                                                              //~v570I~
#endif                                                             //~v570I~
