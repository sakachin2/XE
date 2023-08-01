//*CID://+v77TR~:                             update#=  496;       //~v77TR~
//**************************************************               //~v6a0I~
//v77T:230708 ARM;locale was not set for xsub tool(pass Gjnilocale by putenv)//~v77TI~
//v77Q:230630 (BUG)utempnam returns /sdcard, it cause permission err. use private for also XSUB//~v77QI~
//v771:230323 sys/timeb.h is not found on ARM                      //~v771I~
//v770:230322 for Axe Api33                                        //~v770I~
//v711:201022 ftime deprecated(ftime is obsoleted POSIX2008)       //~v711I~
//vc1c 2020/06/19 ARM;/proc/version access denied, use Build.VERSION.SDK_INT R RELEASE//~vc1cI~
//v6K1:170225 (ARM)ftime obsoleted at POSIX2008; linker fail by undefined reference by this reason?//~v6K1I~
//v6z0:150529 by xuerpck(uerrmsg parmchk)                          //~v6z0I~
//v6hc:120613 (ARM)avoid uninitialized variable warning by gcc 4.4.3 on FC12(copile optio -Ox is required also)//~v6hcI~
//v6f9:120423 (Axe)default locale by locale.getDefault().toString()+"."+Charset.defaultCharset(="UTF-8")//~v6f9I~
//v6dg:120220 (Axe)ftp downloaded file attr is 075(sdcard is read only and FAT); change to private dir//~v6dgI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//**************************************************               //~v6a0I~
#ifdef ARM                                                         //~v6a0R~
//*********************************************************        //~v6a0I~
#include <stdlib.h>                                                //~v6a0R~
#include <stdio.h>                                                 //~v6a0I~
#include <string.h>                                                //~v6a0I~
#include <wchar.h>                                                 //~v6a0I~
#include <locale.h>                                                //~v6a0I~
#include <unistd.h>                                                //~v6a0I~
#include <sys/types.h>                                             //~v6K1I~
//#include <sys/timeb.h>                                             //~v6K1I~//~v771R~
//****************                                                 //~v6a0I~
#define GBL_ULIBARM		//for ulibarm.h                            //~v6a0I~
#include <ulib.h>                                                  //~v6a0I~
                                                                   //~v6a0I~
#include <udbcschk.h>                                              //~v6a0I~
#include <uque.h>                                                  //~v6dgR~
#include <ufile.h>                                                 //~v6a0R~
#include <ufile2.h>                                                //~v6a0I~
#include <uerr.h>                                                  //~v6a0I~
#include <uviol.h>                                                 //~v6a0I~
#include <uproc.h>                                                 //~v6a0R~
#include <uproc4.h>                                                //~v6a0I~
#include <utf.h>                                                   //~v6a0I~
#include <utrace.h>                                                //~v6a0I~
#include <uftp.h>                                                  //~v6dgI~
#include <ustring.h>                                               //~v6f9I~
                                                                   //~v6dgI~
#ifdef ARMXXE
#include <jnic2ju.h>	//getprivatepath                           //~v6dgR~
#endif
#define UFTIME                                                     //~v770I~
#include <umiscf.h>                                                //~v770I~
//*********************************************************        //~v6a0I~
//*********************************************************        //~v6a0I~
//*  ARM Environment                                               //~v6a0I~
//*********************************************************        //~v6a0I~
char *getsdcarddir()                                               //~v6a0I~
{                                                                  //~v6a0I~
	char *pc;                                                      //~v6a0I~
//**************                                                   //~v6a0I~
    pc=getenv("EXTERNAL_STORAGE");	//reff:os/Environment.java     //~v6a0I~
    if (!pc)                                                       //~v6a0I~
        pc="/sdcard";                                              //~v6a0I~
    return pc;                                                     //~v6a0I~
}                                                                  //~v6a0I~
char *getenvtmp(char *Pout)                                        //~v77QI~
{                                                                  //~v77QI~
	char *pc,*pc2;                                                      //~v77QI~
//**************                                                   //~v77QI~
    pc=getenv(ENV_TMPDIR);	//TMPDIR                               //~v77QR~
    UTRACEP("%s:key=%s,getenv=%s\n",UTT,ENV_TMPDIR,pc);            //~v77QR~
    if (!pc)                                                       //~v77QI~
        strcpy(Pout,"/tmp");                                       //~v77QI~
    else                                                           //~v77QI~
    {                                                              //~v77QI~
    	pc2=strchr(pc,':');	                                       //~v77QR~
        if (!pc2)            //PREPEND option at setenv            //~v77QI~
        	strcpy(Pout,pc);                                       //~v77QI~
        else                                                       //~v77QI~
        {                                                          //~v77QI~
        	int len=PTRDIFF(pc2,pc);                              //~v77QI~
        	UmemcpyZ(Pout,pc,(UINT)len);                           //~v77QI~
        }                                                          //~v77QI~
    }                                                              //~v77QI~
    pc=Pout;                                                       //~v77QI~
    UTRACEP("%s:return %s\n",UTT,pc);                              //~v77QI~
    return pc;                                                     //~v77QI~
}                                                                  //~v77QI~
char *getdatadir()                                                 //~v6a0I~
{                                                                  //~v6a0I~
	char *pc;                                                      //~v6a0I~
//**************                                                   //~v6a0I~
    pc=getenv("ANDROID_DATA");	//reff:os/Environment.java         //~v6a0I~
    if (!pc)                                                       //~v6a0I~
        pc="/data";                                                //~v6a0I~
    return pc;                                                     //~v6a0I~
}                                                                  //~v6a0I~
char *gettempdir()                                                 //~v6a0I~
{                                                                  //~v6a0I~
static char Sfnm[_MAX_PATH];                                       //~v6a0R~
	char *pc1,*pc2;                                                //~v6a0I~
	FILEFINDBUF3 ffb3;                                             //~v6a0I~
    int rc;                                                        //~v6a0I~
    char *pc3="Private";                                           //~v6hcR~
    char tmpdir[_MAX_PATH];                                        //~v77QI~
//**************                                                   //~v6a0I~
#ifdef ARMXXE                                                      //~v6dgI~
//data/data/app/files                                              //~v6dgI~
    pc3=jniu_getPrivatePath(0);                                    //~v6dgI~
    sprintf(Sfnm,"%s/tmp",pc3);                                    //~v6dgI~
    UTRACEP("%S:Sfnm=%s\n",UTT,Sfnm);                              //~v77QI~
    rc=ufstat(Sfnm,&ffb3);                                         //~v6dgI~
    if (!rc)                                                       //~v6dgI~
        return Sfnm;                                               //~v6dgI~
    if (!umkdir(Sfnm))                                             //~v6dgI~
        return Sfnm;                                               //~v6dgI~
#endif                                                             //~v6dgI~
//try private data                                                 //~v77QI~
    pc1=getenvtmp(tmpdir);                                         //~v77QI~
    strcpy(Sfnm,pc1);                                         //~v77QI~
    rc=ufstat(Sfnm,&ffb3);                                         //~v77QI~
    if (!rc)                                                       //~v77QI~
        return Sfnm;                                               //~v77QI~
    if (!umkdir(Sfnm))                                             //~v77QI~
        return Sfnm;                                               //~v77QI~
//try sdcard                                                       //~v6dgI~
    pc1=getsdcarddir();                                            //~v6a0I~
    sprintf(Sfnm,"%s/tmp",pc1);                                    //~v6a0I~
    rc=ufstat(Sfnm,&ffb3);                                         //~v6a0I~
    if (!rc)                                                       //~v6a0I~
        return Sfnm;                                               //~v6a0I~
    if (!umkdir(Sfnm))                                             //~v6a0I~
        return Sfnm;                                               //~v6a0I~
//**                                                               //~v6a0I~
    pc2=getdatadir();                                             //~v6a0I~
    sprintf(Sfnm,"%s/tmp",pc2);                                    //~v6a0I~
    rc=ufstat(Sfnm,&ffb3);                                         //~v6a0I~
    if (!rc)                                                       //~v6a0I~
        return Sfnm;                                               //~v6a0I~
    if (!umkdir(Sfnm))                                             //~v6a0I~
        return Sfnm;                                               //~v6a0I~
//  uerrmsg("mkdir tmp on %s nor %s",pc1,pc2);                     //~v6a0I~//~v6dgR~
//  uerrmsg("mkdir tmp failed on %s,%s and %s",pc3,pc1,pc2);       //~v6z0R~
    uerrmsg("mkdir tmp failed on %s,%s and %s",0,                  //~v6z0I~
			pc3,pc1,pc2);                                          //~v6z0I~
    return "";                                                     //~v6a0I~
}                                                                  //~v6a0I~
char *gettempnampath(char *Ppath)                                  //~v6a0I~
{                                                                  //~v6a0I~
static char Sfnm[_MAX_PATH];                                       //~v6a0R~
	char *pc;                                                      //~v6a0I~
//**************                                                   //~v6a0I~
    UTRACEP("%s:Ppath=%s\n",UTT,Ppath);                            //+v77TI~
	if (!Ppath || !*Ppath)                                         //~v6a0I~
    	return gettempdir();                                       //~v6a0I~
	if (strlen(Ppath)>=4 && !memcmp(Ppath,"/tmp",4))               //~v6a0R~
    {                                                              //~v6a0I~
    	pc=gettempdir();                                           //~v6a0I~
        sprintf(Sfnm,"%s%s",pc,Ppath+4);                           //~v6a0I~
        return Sfnm;                                               //~v6a0I~
    }                                                              //~v6a0I~
    return Ppath;                                                  //~v6a0I~
}                                                                  //~v6a0I~
#ifdef ARMAPI9                                                     //~v6a0M~
//*********************************************************        //~v6a0I~
//*  missing on libc                                               //~v6a0I~
//*********************************************************        //~v6a0I~
int mbtowc(UWCHART *Ppucs,const char *Pinp,size_t Pinplen)         //~v6a0R~
{                                                                  //~v6a0I~
    int chklen;                                                    //~v6a0I~
    mbstate_t mbs;                                                 //~v6a0I~
//*************                                                    //~v6a0I~
    memset(&mbs,0,sizeof(mbs));                                    //~v6a0I~
    chklen=mbrtowc(Ppucs,(const char *)Pinp,(size_t)Pinplen,&mbs); //~v6a0I~
    return chklen;                                                 //~v6a0I~
}                                                                  //~v6a0I~
//*********************************************************        //~v6a0I~
int wctomb(char *Pout,UWCHART Pucs)                                //~v6a0I~
{                                                                  //~v6a0I~
    int outlen;                                                    //~v6a0I~
    mbstate_t mbs;                                                 //~v6a0I~
//*************                                                    //~v6a0I~
    memset(&mbs,0,sizeof(mbs));                                    //~v6a0I~
    outlen=wcrtomb(Pout,Pucs,&mbs);                                //~v6a0I~
    return outlen;                                                 //~v6a0I~
}                                                                  //~v6a0I~
#else                                                              //~v6a0I~
//*********************************************************        //~v6a0I~
//*called from umb2wc if Spconverter==null                         //~v6a0I~
//*  APIlevel<4:mbtowc (wchar_t is 1 byte)                         //~v6a0I~
//*  support only 1byte ucs                                        //~v6a0I~
//*********************************************************        //~v6a0I~
int mbtowc_api4(UWCHART *Ppucs,char *Pinp,int Pinplen)             //~v6a0R~
{                                                                  //~v6a0R~
    int chklen;                                                    //~v6a0R~
    mbstate_t mbs;                                                 //~v6a0R~
    wchar_t   wct;                                                 //~v6a0I~
//*************                                                    //~v6a0R~
    memset(&mbs,0,sizeof(mbs));                                    //~v6a0R~
    chklen=mbrtowc(&wct,(const char *)Pinp,(size_t)Pinplen,&mbs);  //~v6a0R~
    *Ppucs=(UWCHART)wct;                                           //~v6a0I~
    return chklen;                                                 //~v6a0R~
}                                                                  //~v6a0R~
//*********************************************************        //~v6a0I~
int mbrtowc_api4(UWCHART *Ppucs,char *Pinp,int Pinplen,void *Pmbs) //~v6a0R~
{                                                                  //~v6a0I~
    int chklen,ii;                                                 //~v6a0I~
    wchar_t *pwct;                                                 //~v6a0I~
    mbstate_t *pmbs;                                               //~v6a0R~
//*************                                                    //~v6a0I~
    pmbs=(mbstate_t*)(ULONG)Pmbs;                                  //~v6a0I~
    memset(pmbs,0,sizeof(mbstate_t));                              //~v6a0R~
    pwct=(wchar_t*)(ULONG)Ppucs;                                   //~v6a0R~
    chklen=mbrtowc(pwct,(const char *)Pinp,(size_t)Pinplen,pmbs);  //~v6a0R~
    if (chklen<0)                                                  //~v6a0I~
    	return chklen;                                             //~v6a0I~
    if (!(ii=chklen))                                              //~v6a0I~
    	ii=chklen=strlen(Pinp);                                    //~v6a0I~
    for (ii--;ii>=0;ii--)                                          //~v6a0I~
    	Ppucs[ii]=(UWCHART)pwct[ii];                               //~v6a0I~
    return chklen;                                                 //~v6a0I~
}                                                                  //~v6a0I~
//*********************************************************        //~v6a0I~
int wctomb_api4(char *Pout,UWCHART Pucs)                           //~v6a0R~
{                                                                  //~v6a0I~
    int outlen;                                                    //~v6a0I~
    mbstate_t mbs;                                                 //~v6a0I~
//*************                                                    //~v6a0I~
    memset(&mbs,0,sizeof(mbs));                                    //~v6a0I~
    outlen=wcrtomb(Pout,Pucs,&mbs);                                //~v6a0R~
    return outlen;                                                 //~v6a0I~
}                                                                  //~v6a0I~
#endif //ARMAPI9                                                   //~v6a0I~
//*********************************************************        //~v77TI~
char *ulibarm_getJniLocale(void)                                   //~v77TR~
{                                                                  //~v77TI~
#ifndef XXE  //from jni                                            //~v77TI~
	#ifdef XSUB                                                    //~v77TI~
        if (!*Gjnilocale)                                           //~v77TI~
        {                                                          //~v77TI~
    		char *env=getenv(ENV_AXELOCALE);                       //~v77TR~
	    	UTRACEP("%s:env=%s,key=\n",UTT,env,ENV_AXELOCALE);     //~v77TR~
        	if (env)                                               //~v77TR~
        		strcpy(Gjnilocale,env);                            //~v77TR~
        }                                                          //~v77TI~
    #endif                                                         //~v77TI~
#endif                                                             //~v77TI~
    UTRACEP("%s:rc=%s\n",UTT,Gjnilocale);                          //~v77TR~
	return Gjnilocale;                                             //~v77TI~
}                                                                  //~v77TI~
//*********************************************************        //~v6a0M~
//*setlocale returns null                                          //~v6a0I~
//*********************************************************        //~v6a0I~
char *ulibarm_getlocale(void)                                      //~v6a0M~
{                                                                  //~v6a0M~
//  char *pc,*pc2;                                                 //~v6a0M~//~v6K1R~
    char *pc;                                                      //~v6K1I~
//*********                                                        //~v6a0M~
	pc=ARM_DEFAULT_LOCALE;                                         //~v6a0M~
    UTRACEP("ulibarm_getlocale Gjnilocale=%s\n",Gjnilocale);       //~v6a0M~
    ulibarm_getJniLocale();                                        //~v77TR~
	if (*Gjnilocale)                                               //~v6a0M~
    {                                                              //~v6a0M~
    	pc=Gjnilocale;                                             //~v6a0M~
        if (!strchr(pc,'.'))                                       //~v6a0M~
        	strcat(pc,"." LOCALEID_UTF_8);	//if no charset specified//~v6a0I~
    }                                                              //~v6a0M~
    UTRACEP("ulibarm_getlocale out=%s\n",pc);                      //~v6a0M~
	return pc;                                                     //~v6a0M~
}                                                                  //~v6a0M~
//*********************************************************        //~v6f9I~
//*get locale and charset                                          //~v6f9R~
//*rc:2:Gjnilocale contains charset,1:charset is UTF8,4:err        //~v6f9I~
//*********************************************************        //~v6f9I~
int ulibarm_getdefaultcharset(int Popt,char *Plocale,char *Pcharset)//~v6f9R~
{                                                                  //~v6f9I~
//  char *pc,*pc2,*cs;                                             //~v6f9R~//~v6K1R~
    char *pc,*pc2;                                                 //~v6K1I~
    int rc=0;                                                      //~v6f9I~
//*********                                                        //~v6f9I~
	*Plocale=0;                                                    //~v6f9I~
	*Pcharset=0;                                                   //~v6f9I~
    ulibarm_getJniLocale();                                                //~v77TI~
	pc=Gjnilocale;                                                 //~v6f9I~
    if (!pc)                                                       //~v6f9I~
    	return 4;                                                  //~v6f9R~
    pc2=strchr(pc,'.');                                            //~v6f9I~
    if (pc2)                                                       //~v6f9I~
    {                                                              //~v6f9I~
    	UmemcpyZ(Plocale,pc,(ULONG)pc2-(ULONG)pc);                 //~v6f9I~
    	strcpy(Pcharset,pc2+1);                                    //~v6f9I~
        rc=2;                                                      //~v6f9I~
    	if (USTRHEADIS(Pcharset,"UTF"))	//                         //~v6f9I~
        	rc=1;                                                  //~v6f9I~
    }                                                              //~v6f9I~
    else                                                           //~v6f9I~
    	strcpy(Plocale,pc);                                        //~v6f9I~
    UTRACEP("ulibarm_getdefaultcharset Gjnilocale=%s,loc=%s,cs=%s\n",Gjnilocale,Plocale,Pcharset);//~v6f9R~
	return rc;                                                     //~v6f9R~
}//ulibarm_getdefaultcharset                                       //~v6f9R~
//*********************************************************        //~v6a0I~
//*ndk r6 not did not support                                      //~v6a0R~
//*use type=CODESET only                                           //~v6a0I~
//*********************************************************        //~v6a0I~
char *nl_langinfo(int Ptype)                                       //~v6a0I~
{                                                                  //~v6a0I~
	char *pc,*plocale;                                             //~v6a0R~
//************                                                     //~v6a0R~
	plocale=udbcschk_setlocale(0,LC_ALL,NULL);                     //~v6a0R~
    pc=strchr(plocale,'.');                                        //~v6a0R~
    if (!pc)                                                       //~v6a0I~
        return LOCALEID_UTF_8;	//if no charset specified          //~v6a0I~
    return pc+1;                                                   //~v6a0R~
}                                                                  //~v6a0I~
#endif                                                             //~2818I~//~v6a0I~
#ifdef NOCURSES                                                    //~v6a0I~
//**************************************************               //~v6a0I~
//*uviom is not used                                               //~v6a0I~
//**************************************************               //~v6a0I~
int uvio_wcinit(int Popt,ULONG Pcodepage)                          //~v6a0I~
{                                                                  //~v6a0I~
    return 0;                                                      //~v6a0I~
}                                                                  //~v6a0I~
//**************************************************               //~v6a0I~
//*uviol not used                                                  //~v6a0I~
//**************************************************               //~v6a0I~
int Guviol_flag;                                                   //~v6a0I~
int uviol_beep(void)                                               //~v6a0I~
{                                                                  //~v6a0I~
    printf("\a\n");		//0x07                                     //~v6a0I~
    return 0;                                                      //~v6a0I~
}//uviol_beep                                                      //~v6a0I~
//************************                                         //~v6a0I~
int uviol_konchk(void)                                             //~v6a0I~
{                                                                  //~v6a0I~
    static int S1stsw,Skonswsv;                                    //~v6a0I~
//  char *ttyn;                                                    //~v6a0I~//~v6K1R~
    int  rc=0;                                                     //~v6a0I~
//************************                                         //~v6a0I~
	if (S1stsw)			//2nd time                                 //~v6a0I~
    	return Skonswsv;                                           //~v6a0I~
    Guviol_flag|=UVIOL_KONCHKS;	//until KONCHKE,bypass call konchk from uerrmsg//~v6a0I~
    S1stsw=1;                                                      //~v6a0I~
    Skonswsv=0;                                                    //~v6a0I~
    Guviol_flag|=UVIOL_KON;                                        //~v6a0I~
    Skonswsv=1;                                                    //~v6a0I~
    rc=1;                                                          //~v6a0I~
    Guviol_flag|=UVIOL_KONCHKE;                                    //~v6a0I~
    return rc;                                                     //~v6a0I~
}//uviol_konchk                                                    //~v6a0I~
//*******************************************************          //~v6a0I~
int uviol_konchk2(void)                                            //~v6a0I~
{                                                                  //~v6a0I~
    return 1;                                                      //~v6a0I~
}//uviol_konchk2                                                   //~v6a0I~
#endif  //NOCURSES                                                 //~v6a0R~
#ifdef ARM                                                         //~v6K1I~
//*******************************************************          //~v6K1I~
//*ftime is obsoleted POSIX2008                                    //~v6K1I~
//*******************************************************          //~v6K1I~
int ftime(struct timeb * Ptb)                                      //~v6K1R~
{                                                                  //~v6K1I~
//    struct timezone tz;                                            //~v6K1I~//~v711R~
//    struct timeval  tv;                                            //~v6K1I~//~v711R~
////*********************                                            //~v6K1I~//~v711R~
//    if (gettimeofday(&tv,&tz)<0)                                   //~v6K1I~//~v711R~
//        return -1;                                                 //~v6K1I~//~v711R~
//        Ptb->millitm=tv.tv_usec/1000;                              //~v6K1R~//~v711R~
//        Ptb->time=tv.tv_sec;                                       //~v6K1R~//~v711R~
//        Ptb->timezone=tz.tz_minuteswest;                           //~v6K1R~//~v711R~
//        Ptb->dstflag=tz.tz_dsttime;                                //~v6K1R~//~v711R~
//    return 0;                                                      //~v6K1I~//~v711R~
	return uftime(Ptb);                                            //~v711I~
}//ftime                                                           //~v6K1I~
//*******************************************************          //~vc1cI~
void setArmOSVersion(int Popt,int PapiLevel,int PapiRelease)       //~vc1cR~
{                                                                  //~vc1cI~
//*********************                                            //~vc1cI~
	GarmApiLevel=PapiLevel;                                        //~vc1cR~
	GarmApiRelease=PapiRelease;                                    //~vc1cI~
    UTRACEP("%s:api=%d,rel=%d\n",UTT,PapiLevel,PapiRelease);       //~vc1cI~
}                                                                  //~vc1cI~
#endif //ARM                                                       //~v6K1I~
