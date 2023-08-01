//*CID://+vas3R~:                             update#=  442;       //~vas3R~
//************************************************************* //~5825I~
//*uprocExit.c                                                     //~v5anR~//~v77FR~
//* for xsub.so redirect exit() to pthread_exit()                  //~v065R~//~v77FR~
//*************************************************************    //~v022I~
//vas3:230630 ARM;closeall for arm subthread execution             //~vas3I~
//*************************************************************    //~vas3I~
#include <stdio.h>                                              //~5825I~
#include <stdlib.h>                                             //~5825I~
#include <string.h>                                             //~5825I~
#include <pthread.h>                                           //~v77DI~//~v77FR~
#include <android/api-level.h>                                     //~v77DI~//~v77FM~
                                                                   //~v022I~
#include <ulib.h>   //ulibarm.h defines armXsubExit                //~v77FR~
#include <utrace.h>                                              //~v77FR~//~vas3R~
//*********************************************************************//~v77DI~
void uprocExit(void)                                               //~v77FI~
{                                                                  //~v77FI~
    return;                                                        //~v77FI~
}                                                                  //~v77FI~
//*********************************************************************//~v77FI~
//*for exit() of xsub tool executed for >Android10(dlopen,dlsym,call)//~v77DI~
//*redirect by #define on ulibarm.h                                //~v77DI~
//*********************************************************************//~v77DI~
#ifdef ARM                                                         //~v77FR~
#ifdef XSUB                                                        //~v77FI~
void armXsubExit(int PexitCode)                                    //~v77DR~
{                                                                  //~v77DI~
    static int SexitCode;                                              //~v77DI~
//**************                                                   //~v77DI~
#undef exit                                                        //~v77DI~
    int apilevel=android_get_device_api_level();                   //~v77DI~
//  UTRACEP("%s:exitcode=%d,device_api_level=%d,&SexitCode=%p\n",UTT,PexitCode,apilevel,&SexitCode);//~v77DR~//~v77FR~
    if (apilevel>=__ANDROID_API_Q__)	//android10(Q)=29	       //~v77DI~
    {                                                              //~v77DI~
//  	UTRACEP("%s:pthread_exit\n",UTT);                          //~v77DI~//~v77FR~
		utrace_term(0);                                            //+vas3I~
        SexitCode=PexitCode;                                       //~v77DR~
		pthread_exit(&SexitCode);                                  //~v77DR~
    }                                                              //~v77DI~
    else                                                           //~v77DI~
    {                                                              //~v77DI~
//  	UTRACEP("%s:exit\n",UTT);                                  //~v77DI~//~v77FR~
	    exit(PexitCode);                                           //~v77DI~
    }                                                              //~v77DI~
}                                                                  //~v77DI~
//*********************************************************************//~vas3I~
int armXsubClose(char *Ppgm)                                       //~vas3I~
{                                                                  //~vas3I~
    int apilevel=android_get_device_api_level();                   //~vas3I~
    if (apilevel>=__ANDROID_API_Q__)	//android10(Q)=29, executing on subthrea//~vas3I~
    {                                                              //~vas3I~
		utrace_term(0);		                                       //~vas3R~
    	return 1;                                                  //~vas3R~
    }                                                              //~vas3I~
    return 0;                                                      //~vas3I~
}                                                                  //~vas3I~
#endif //XSUB                                                      //~v77DI~
#endif //ARM                                                       //~v77FI~
