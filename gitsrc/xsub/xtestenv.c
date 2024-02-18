//CID://+v108R~:                                                   //~v108R~
//*************************************************************    //~v100I~
//*xtestenv                                                        //~v108R~
//*show exe path and env                                           //~v108R~
//*************************************************************    //~v100I~
//*************************************************************    //~v100I~
#define VERSION  "v1.00"                                           //~v108R~
#define PGMID    "XTEXTENV"                                        //~v100I~//~v108R~
//*************************************************************    //~v100I~
#ifdef LNX                                                         //~v108I~
	#include <sys/stat.h>                                          //~v108I~
#else                                                              //~v108I~
	#include <windows.h>                                           //~v108I~
#endif                                                             //~v108I~
#include <time.h>                                                  //~v100I~
#include <stdio.h>                                                 //~v100I~
#include <stdlib.h>                                                //~v100I~
#include <string.h>                                                //~v100I~
#include <memory.h>                                                //~v108I~
                                                                   //~v105I~
#include <ctype.h>                                                 //~v106R~
#include <pthread.h>
                                                                   //~v108I~
#include <ulib.h>   //ulibarm.h                                    //~v108I~
#include <utrace.h>                                                //~v108I~

#define AAA                                                                   //~v105I~//~v108R~
//********************                                             //~v100I~
#ifdef AAA                                                         //~v108I~
static  char Spgmver[64];                                          //~v100I~//~v108R~
#endif                                                             //~v108I~
//********************                                             //~v100I~
//*************************************************************    //~v100I~
int main(int parmc,char *parmp[], char *penv[])                   //~v100I~//~v108R~
//int main(int parmc,char *parmp[])                                //~v108R~
{                                                                  //~v100I~
#ifdef AAA                                                         //~v108I~
    char *parm0,*pc,*pc2,paths[4096],path[1024],fpath[4096];       //~v108R~
    int ii=0,len;                                                  //~v108R~
#define PLINE printf                                               //~v108I~
#define PATH  "PATH="                                              //~v108I~
#ifdef LNX                                                         //~v108I~
	#define DELM ':'                                               //~v108I~
	#define SEP '/'                                                //~v108I~
	#define EXT ""                                                 //~v108I~
#else                                                              //~v108I~
	#define DELM ';'                                               //~v108I~
	#define SEP '\\'                                               //~v108I~
	#define EXT ".exe"                                             //~v108I~
#endif                                                             //~v108I~
#ifdef LNX                                                         //~v108I~
    struct stat statbuff;   //output file information              //~v108I~
#else                                                              //~v108I~
    void* hdir;                                                    //~v108I~
	WIN32_FIND_DATA w32fd;                                         //~v108I~
#endif                                                             //~v108I~
    char *outfnm="/sdcard/xtestenv.out";                           //~v108R~
    FILE *fh;                                                      //~v108I~
    char *fault=0;                                                 //~v108I~
    char swcase='0';                                               //~v108R~
//  char *penv[20];                                                //~v108R~
    int exitcode=1;                                                //~v108R~
#ifdef ARM                                                         //~v108I~
#else                                                              //~v108I~
	char *fnmtrc="/data/user/0/com.xe.AxeA9.debug/files/tmp/xcv.trc";//~v108I~
#endif                                                             //~v108I~
#define macTest(sw,code) if (sw) {code}                            //~v108R~
#define macTest2(code) code                                        //~v108R~
#define macTest3(sw,codes,elsecodes) if (sw) {codes} else {elsecodes}//~v108I~
//**********************                                           //~v100I~
    PLINE("entry v1.1 %c\n",swcase);                               //+v108R~
    macTest(1,                                                     //~v108I~
    		PLINE("mactest1\n");                                     //~v108I~
    		PLINE("mactest2\n");                                     //~v108I~
           );                                                      //~v108I~
    macTest2(                                                       //~v108I~
    		PLINE("mactest11\n");                                    //~v108I~
    		PLINE("mactest21\n");                                    //~v108I~
           );                                                      //~v108I~
    macTest2(                                                      //~v108I~
    		PLINE("mactest31\n");                                    //~v108I~
           );                                                      //~v108I~
    macTest2(                                                      //~v108I~
    		PLINE("mactest41\n")                                     //~v108I~
           );                                                      //~v108I~
    macTest2(PLINE("mactest51\n"));                                  //~v108I~
    macTest3(1,                                                     //~v108I~
    		PLINE("mactest then 1\n");                             //~v108I~
    		PLINE("mactest then 2\n");                             //~v108I~
            ,                                                      //~v108I~
    		PLINE("mactest else 1\n");                             //~v108I~
    		PLINE("mactest else 2\n");                             //~v108I~
           );                                                      //~v108I~
    macTest3(0,                                                     //~v108I~
    		PLINE("mactest then 1\n");                             //~v108I~
    		PLINE("mactest then 2\n");                             //~v108I~
            ,                                                      //~v108I~
    		PLINE("mactest else 1\n");                             //~v108I~
    		PLINE("mactest else 2\n");                             //~v108I~
           );                                                      //~v108I~
    macTest(1,                                                    //~v108I~
    		{                                                      //~v108I~
				PLINE("mactest1 then 11\n");                       //~v108I~
    			PLINE("mactest1 then 21\n");                       //~v108I~
            });                                                    //~v108I~
    fflush(stdout);                                                //~v108I~
#ifdef ARM                                                         //~v108I~
    utrace_init("",UTRACEO_LOGCAT);                                //~v108I~
#else                                                               //~v108I~
    utrace_init(fnmtrc,1);                                         //~v108R~
#endif                                                             //~v108I~
    for (int ii=0;ii<parmc;ii++)                                   //~v108I~
    {                                                              //~v108I~
        PLINE("parm=ii=%d=%s\n",ii,parmp[ii]);                     //~v108I~
    }                                                              //~v108I~
    if (parmc>1)                                                   //~v108R~
    {                                                              //~v108I~
        swcase=*parmp[1];                                          //~v108I~
    }                                                              //~v108I~
    PLINE("swcase=%c\n",swcase);                                   //~v108I~
    UTRACEP("%s:case=%d\n",UTT,swcase);                            //~v108I~
    if (swcase=='1')                                               //~v108I~
    {                                                              //~v108I~
	    PLINE("fault\n");                                          //~v108I~
    	*fault=1;                                                  //~v108I~
    }                                                              //~v108I~
    else                                                           //~v108I~
    if (swcase=='2')                                               //~v108I~
    {                                                              //~v108I~
	    PLINE("exit(2)\n");                                        //~v108I~
#ifdef XSUB                                                        //~v108I~
        exitcode=3;                                                //~v108I~
#endif                                                             //~v108I~
#ifdef ARM                                                         //~v108I~
        exitcode=4;                                                //~v108I~
#endif                                                             //~v108I~
	    PLINE("exit()=%p\n",exit);                                 //~v108I~
    	exit(exitcode);                                            //~v108R~
    }                                                              //~v108I~
    else                                                           //~v108I~
    if (swcase=='3')                                               //~v108I~
    {                                                              //~v108I~
	    PLINE("pthread_exit(3)\n");                                //~v108I~
    	pthread_exit(&swcase);                                     //~v108R~
    }                                                              //~v108I~
    fh=fopen(outfnm,"w");                                          //~v108I~
    UTRACEP("%s:fopen %s,fh=%p\n",UTT,outfnm,fh);                  //~v108I~
    if (!fh)                                                       //~v108I~
    	return 5;                                                  //~v108I~
    fprintf(fh,"%s\n","xtestenv.fprintf");                         //~v108I~
    fclose(fh);                                                    //~v108I~
    sprintf(Spgmver,"%s:%s: ",PGMID,VERSION);                      //~v100I~//~v108R~
    PLINE("%s:%s-%s\n",Spgmver,__DATE__,__TIME__);                 //~v108I~
    PLINE("path=%s\n",parmp[0]);                                   //~v108I~
    PLINE("parm=%s\n",parmp[1]);                                   //~v108I~
if (1)                                                             //~v108R~
{                                                                  //~v108I~
    parm0=parmp[0];                                                //~v108I~
    paths[0]=0;                                                    //~v108I~
    for (;;)                                                       //~v108R~
    {                                                              //~v108I~
        pc=penv[ii++];                                             //~v108I~
        if (!pc)                                                   //~v108I~
            break;                                                 //~v108I~
#ifdef UNX                                                         //~v108I~
        if (strlen(pc)>5 && !memcmp(pc,PATH,5))                    //~v108I~
#else                                                              //~v108I~
        if (strlen(pc)>5 && !memicmp(pc,PATH,5))                   //~v108R~
#endif                                                             //~v108I~
        	strcpy(paths,pc+5);                                    //~v108R~
    	PLINE("env[%d]=%s\n",ii,pc);                               //~v108R~
    }                                                          //~v100I~//~v108R~
    if (paths[0])                                                  //~v108I~
    {                                                              //~v108I~
		PLINE("check paths=%s\n",paths);                           //~v108I~
    	pc=paths;                                                  //~v108I~
        int swlast=0;                                              //~v108I~
    	for(;;)                                                    //~v108I~
        {                                                          //~v108I~
        	pc2=strchr(pc,DELM);                                   //~v108I~
            if (pc2)                                               //~v108I~
            	len=(int)(pc2-pc);                                 //~v108R~
            else                                                   //~v108I~
            {                                                      //~v108I~
            	len=strlen(pc);                                    //~v108I~
                swlast=1;                                          //~v108I~
            }                                                      //~v108I~
            memcpy(path,pc,(unsigned int)len);                     //~v108R~
            *(path+len)=0;                                         //~v108I~
            sprintf(fpath,"%s%c%s%s",path,SEP,parm0,EXT);          //~v108I~
		    PLINE("check fpath=%s\n",fpath);                       //~v108I~
#ifdef LNX                                                         //~v108I~
		    if (!lstat(fpath,&statbuff))                           //~v108R~
                                                                   //~v108I~
#else                                                              //~v108I~
            hdir=FindFirstFile(fpath,&w32fd);                      //~v108I~
            if (hdir!=INVALID_HANDLE_VALUE)                        //~v108I~
#endif                                                             //~v108I~
            {                                                      //~v108I~
		    	PLINE("\n!!Found fpath=%s\n",fpath);               //~v108I~
            	break;                                             //~v108I~
            }                                                      //~v108I~
            if (swlast)                                            //~v108I~
            	break;                                             //~v108I~
            pc=pc2+1;                                              //~v108I~
        }                                                          //~v108I~
    }                                                              //~v108I~
}                                                                  //~v108R~
    UTRACEP("%s:return",UTT);                                      //~v108I~
    utrace_term(0);                                                //~v108I~
    return 9;                                                      //~v108I~
#else      //AAA                                                   //~v108R~
    return 6;                                                      //~v108R~
#endif                                                             //~v108I~
}                                                                  //~v108R~
