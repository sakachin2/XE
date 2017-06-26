//*CID://+v6k1R~:                             update#=  417;       //~v6k1R~
//**************************************************               //~v6a0I~
//v6k1:130524 (Axe)sbcsmap tbl recreate option                     //~v6k1I~
//v6f9:120423 (Axe)default locale by locale.getDefault().toString()+"."+Charset.defaultCharset(="UTF-8")//~v6f9I~
//v6bq:111221 icu additional directory name should be icudtxxl     //~v6bqI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//**************************************************               //~v6a0I~
#ifdef ARM                                                         //~v6a0I~
	#ifdef GBL_ULIBARM                                             //~v6a0I~
	    char Gjnilocale[MAXLOCALESZ];	//at jni init              //~v6a0I~
	    int  Gjniopt;                                              //~v6k1I~
    #else                                                          //~v6a0I~
	    extern char Gjnilocale[MAXLOCALESZ];	//at jni init      //~v6a0I~
	    extern int  Gjniopt;                                       //~v6k1I~
    #endif                                                         //~v6a0I~
    #define GJNIO_RELOADSBCSMAP      0x0100//==AxeG.TRACEO_REMAP   //+v6k1R~
	#include <android/log.h>                                       //~v6a0I~
	#define ARM_DEFAULT_LOCALE  "en_US.UTF-8"                      //~v6a0I~
    #define LOG_TAG "ulib"                                         //~v6a0I~
	#define LOGPE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)//~v6a0I~
	#define LOGPD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)//~v6a0I~
                                                                   //~v6a0I~
    #define CODESET 0   //nl_langinfo is not supported ndk r5b     //~v6a0I~
//************************************************                 //~v6a0R~
	char *nl_langinfo(int Ptype);                                  //~v6a0I~
//************************************************                 //~v6a0I~
#ifndef ARMAPI9                                                    //~v6a0I~
	int mbtowc_api4(UWCHART *Ppucs,char *Pinp,int Pinplen);        //~v6a0I~
	int mbrtowc_api4(UWCHART *Ppucs,char *Pinp,int Pinplen,void *Pmbs);//~v6a0R~
	int wctomb_api4(char *Pout,UWCHART Pucs);                      //~v6a0I~
#endif //ARMAPI9                                                   //~v6a0I~
                                                                   //~v6a0I~
//************************************************                 //~v6a0I~
char *gettempnampath(char *Ppath);                                 //~v6a0R~
char *ulibarm_getlocale(void);                                     //~v6a0R~
int ulibarm_getdefaultcharset(int Popt,char *Plocale,char *Pcharset);//~v6f9R~
int ushellexec_xehelp(int Popt,char *Pfnm);	//for xehelp           //~v6a0I~
                                                                   //~v6a0I~
int isonsdpath(char *Ppath);    //jniu.c                           //~v6a0R~
int isonvfat(char *Ppath);     //jniu.c                       //~1A23I~//~v6a0I~
int jniu_geticudir(int Popt,char *Picudir,char *Pswfile);     //jniu.c//~v6bqI~
//************************************************                 //~v6a0I~
#else  //!ARM           //(...) is not supported for VC6           //~v6a0R~
//  #define LOGPE(...)                                             //~v6a0R~
//  #define LOGPD(...)                                             //~v6a0R~
#endif //ARM                                                            //~2818I~//~v6a0R~
