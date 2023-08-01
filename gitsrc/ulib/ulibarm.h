//*CID://+v77TR~:                             update#=  458;       //~v77TR~
//**************************************************               //~v6a0I~
//v77T:230708 ARM;locale was not set for xsub tool(pass Gjnilocale by putenv)//~v77TI~
//vas3:230630 ARM;closeall for arm subthread execution             //~vas3I~
//v77D:230618 ARM;v77c on subthread to avoid exit() kill whole process//~v77CI~
//v77C:230617 ARM;try dlopen to execute xe tool for >=Android10:api29//~v77iI~
//v77i:230427 ARM;opendir/readdir by fd(parcelFileDescriptor.detachFd)//~v77iI~
//v77d:230423 ARM;delete                                           //~v77dI~
//v77b:230415 ARM;edit file                                        //~v77bI~
//v771:230323 sys/timeb.h is not found on ARM                      //~v771I~
//vc1p 2020/06/24 display path env                                 //~vc1pI~
//vc1i 2020/06/22 display not /emulated/.. but /sdcard to header CWD=//~vc1iI~
//vc1c 2020/06/19 ARM;/proc/version access denied, use Build.VERSION.SDK_INT R RELEASE//~vc1cI~
//v6k1:130524 (Axe)sbcsmap tbl recreate option                     //~v6k1I~
//v6f9:120423 (Axe)default locale by locale.getDefault().toString()+"."+Charset.defaultCharset(="UTF-8")//~v6f9I~
//v6bq:111221 icu additional directory name should be icudtxxl     //~v6bqI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//**************************************************               //~v6a0I~
#ifdef ARM                                                         //~v6a0I~
#ifndef DEF_ULIBARMH                                               //~v771I~
#define DEF_ULIBARMH                                               //~v771I~
	#ifdef GBL_ULIBARM                                             //~v6a0I~
	    char Gjnilocale[MAXLOCALESZ];	//at jni init              //~v6a0I~
	    char *GjniNativeLibraryPath;	//at jni init              //~v77CR~
	    int  Gjniopt;                                              //~v6k1I~
	    int  GarmApiLevel,GarmApiRelease;                          //~vc1cR~
    #else                                                          //~v6a0I~
	    extern char Gjnilocale[MAXLOCALESZ];	//at jni init      //~v6a0I~
	    extern char *GjniNativeLibraryPath;	//at jni init          //~v77CR~
	    extern int  Gjniopt;                                       //~v6k1I~
	    extern int  GarmApiLevel,GarmApiRelease;                   //~vc1cR~
    #endif                                                         //~v6a0I~
    #define GJNIO_RELOADSBCSMAP      0x0100//==AxeG.TRACEO_REMAP   //~v6k1R~
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
int ufullpathAltSD(int Popt,char *Ppath,char *Pout);               //~vc1iR~
#define UFPASDO_SETRC_CHANGED     0x01                             //~vc1iI~
#define UFPASDRC_RC_SDPATH        0x01                             //~vc1iR~
#define UFPASDRC_RC_BOTGRANTED    0x02                             //~vc1iR~
#define UFPASDRC_RC_CHANGED       0x04                             //~vc1iR~
int isonvfat(char *Ppath);     //jniu.c                       //~1A23I~//~v6a0I~
int jniu_geticudir(int Popt,char *Picudir,char *Pswfile);     //jniu.c//~v6bqI~
void setArmOSVersion(int Popt,int Papilevel,int PapiRelease);      //~vc1cI~
void setArmEnvPATH();                                              //~vc1pR~
                                                                   //~vc2LI~//~vc1pI~
#define ENV_TMPDIR    "TMPDIR"                                     //~vc2LI~//~vc1pI~
#define ARM_TMPID     "$tmp"                                       //~vc2LI~//~vc1pI~
#define ENV_AXELOCALE  "AXE_LOCALE"  	//for xsub wcinit          //~v77TI~
//************************************************                 //~v6a0I~
#ifndef _TIMEB_DEFINED                                             //~v771I~
struct timeb {                                                     //~v771R~
        time_t time;                                               //~v771I~
        unsigned short millitm;                                    //~v771I~
        short timezone;                                            //~v771I~
        short dstflag;                                             //~v771I~
        };                                                         //~v771I~
#define _TIMEB_DEFINED                                             //~v771I~
#endif                                                             //~v771I~
                                                                   //~v771I~
#endif //DEF_ULIBARMH                                              //~v771I~
	#ifdef XSUB   //ulibnc compile                                 //~v77DI~
    	#define exit(code) armXsubExit(code)                       //~v77DI~
		void armXsubExit(int PexitCode);	//in uproc.c           //~v77DR~
	#endif                                                         //~v77DI~
#else  //!ARM           //(...) is not supported for VC6           //~v6a0R~
//  #define LOGPE(...)                                             //~v6a0R~
//  #define LOGPD(...)                                             //~v6a0R~
#endif //ARM                                                            //~2818I~//~v6a0R~
#ifdef ARMXXE                                                      //~v77bI~
	#define fclose(Pfh) ufiledoc_fclose(Pfh)                       //~v77bR~
		int     ufiledoc_fclose(FILE *Pfh);                        //~v77bI~
	#define ferror(Pfh) ufiledoc_ferror(Pfh)                       //~v77bR~
		int     ufiledoc_ferror(FILE *Pfh);                        //~v77bI~
	#define fread(Pbuff,Psize,Pctr,Pfh)  ufiledoc_fread((Pbuff),(Psize),(Pctr),Pfh)//~v77bR~
		size_t  ufiledoc_fread(void *Pbuff,size_t Psize,size_t Pctr,FILE *Pfh);//~v77bI~
	#define fgets(Pbuff,Plen,Pfh)  ufiledoc_fgets((Pbuff),(Plen),Pfh)//~v77bR~
		char   *ufiledoc_fgets(char *Pbuff,int Plen,FILE *Pfh);    //~v77bR~
	#define closedir(phdir)  ufiledoc_closedir(phdir)              //~v77dI~
		int     ufiledoc_closedir(void *Phdir);                    //~v77dR~
	#define readdir(phdir)  ufiledoc_readdir(phdir)                //~v77iI~
		struct dirent* ufiledoc_readdir(void *Phdir);              //~v77iR~
#endif                                                             //~v77bI~
#ifdef ARM                                                         //~vas3I~
	char *ulibarm_getJniLocale(void);                              //+v77TR~
	int armXsubClose(char *Ppgm);	//in uprocExit.c               //~vas3R~
//	#define IF_ARMXSUB_CLOSE(PGM) if (armXsubClose(PGM))	//in uprocExit.c//~vas3R~
//  	#define IF_ARMXSUB_CLOSE(PGM,codes,codeelse) if (armXsubClose(PGM))	{codes} else {codeelse}//in uprocExit.c//~vas3R~
//  #define IF_ARMXSUB_CLOSE(codes) {codes}                        //~vas3R~
// 	#define IF_ARMXSUB_CLOSE(PGM) if (armXsubClose(PGM))	//in uprocExit.c//~vas3R~
// 	#define IF_ARMXSUB_CLOSE(PGM,...) if (armXsubClose(PGM)) {__VA_ARGS__}	codes //in uprocExit.c//~vas3R~
	#define IF_ARMXSUB_CLOSE(PGM,codes) if (armXsubClose(PGM)) {codes}		//in uprocExit.c//~vas3I~
	#define ARMXSUB_CLOSE(PGM)    armXsubClose(PGM)	//close for Arm subthread execution                                          //~v6B1I~//~vas2I~//~vas3I~
#else                                                              //~vas3I~
//	#define IF_ARMXSUB_CLOSE(PGM) if (0)	//close for Arm subthread execution//~vas3R~
// 	#define IF_ARMXSUB_CLOSE(PGM,codes,codeelse) 	//close for Arm subthread execution//~vas3R~
// 	#define IF_ARMXSUB_CLOSE(PGM) if (0)	//close for Arm subthread execution//~vas3R~
	#define IF_ARMXSUB_CLOSE(PGM,codes)                            //~vas3I~
	#define ARMXSUB_CLOSE(PGM)  	//close for Arm subthread execution//~vas3I~
#endif                                                             //~vas3I~
