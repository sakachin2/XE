//*CID://+v6BxR~:                             update#=   29;       //~v6BxR~
//*************************************************************
//*ugcclib.c support function which is not on libc                 //~v134R~
//*  stricmp,memicmp,strupr,strlwr,itoa,spawnv,spawnvp,getche,getch//~v50zR~
//*************************************************************    //~v053I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v50z:010521 LINUX support:support getch                          //~v50zI~
//v50a:010323 LINUX:ukbdl.h require termios.h                      //~v40hI~
//v40h:001116 AIX support:term.h require curses.h (type def for bool etc)//~v40hI~
//v402:001027 AIX support:some func in ugcclib not required        //~v402I~
//v39b:001113 LINUX support:move posix logic(common to linux and aix) to ukbdl from ukbdlnxc//~v39bI~
//v362:000927 LINUX support(support getch where out of curses)     //~v362I~
//*************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>                                                 //~v053I~
#include <ctype.h>                                                 //~v053I~
#include <string.h>                                                //~v053M~
#include <unistd.h>                                                //~v134I~
#include <sys/types.h>                                             //~v134I~
#include <sys/wait.h>                                              //~v134I~
#ifdef UNX                                                         //~v39bI~
    #include <termios.h>                                           //~v40hI~
    #include <ucurses.h>                                           //~v40hR~
#else  //!UNX                                                      //~v39bI~
#endif //!UNX                                                      //~v39bI~
//*******************************************************
#include <ulib.h>                                                  //~v022R~
#include <ugcclib.h>                                               //~v134R~
#include <ukbdl.h>                                                 //~v39bR~
//*******************************************************
#ifndef MGW32  //cygwin has strcasecmp and stricmp is defained as alias//~v5ncI~
static int Spsw;	//spawnvp sw                                   //~v134I~
#endif //MGW32                                                     //~v5ncI~
//*******************************************************          //~v134I~
//*strupr                                                          //~v134I~
//*parm1:str                                                       //~v134I~
//*ret  :str addr                                                  //~v134I~
//*******************************************************          //~v134I~
char *strupr(char *Pstr)                                           //~v134I~
{                                                                  //~v134I~
    unsigned char *pc;                                             //~v134I~
//*******************                                              //~v134I~
	for (pc=Pstr;*pc;pc++)                                         //~v134I~
    	*pc=(unsigned char)toupper(*pc);                           //~v134R~
    return Pstr;                                                   //~v134I~
}//strupr                                                          //~v134I~
//*******************************************************          //~v134I~
//*strupr                                                          //~v134I~
//*parm1:str                                                       //~v134I~
//*ret  :str addr                                                  //~v134I~
//*******************************************************          //~v134I~
char *strlwr(char *Pstr)                                           //~v134I~
{                                                                  //~v134I~
    unsigned char *pc;                                             //~v134I~
//*******************                                              //~v134I~
	for (pc=Pstr;*pc;pc++)                                         //~v134I~
    	*pc=(unsigned char)tolower(*pc);                           //~v134I~
    return Pstr;                                                   //~v134I~
}//strlwr                                                          //~v134I~
//*******************************************************          //~v053I~
//*memicmp                                                         //~v053R~
//*parm1:source1                                                   //~v053R~
//*parm2:source2                                                   //~v053R~
//*parm3:len                                                       //~v053R~
//*ret  :result  0:match,<0,or >0-                                 //~v053R~
//*******************************************************          //~v053I~
//int memicmp(void *Psrc1,void *Psrc2,unsigned int Plen)             //~v053R~//~v6BxR~
int memicmp(void *Psrc1,void *Psrc2,size_t Plen)                   //+v6BxR~
{                                                                  //~v053I~
    char *pc1,*pc2;                                                //~v053I~
//*******************                                              //~v053I~
    for(pc1=Psrc1,pc2=Psrc2;Plen>0;Plen--,pc1++,pc2++)             //~v053I~
        if (tolower(*pc1)!=tolower(*pc2))                          //~v134R~
            return (int)tolower(*pc1)-(int)tolower(*pc2);          //~v134R~
    return 0;                                                      //~v134R~
}//memicmp                                                         //~v053R~
#ifndef MGW32  //cygwin has strcasecmp and stricmp is defained as alias//~v5ncI~
//*******************************************************          //~v134I~
//*stricmp                                                         //~v134I~
//*parm1:source1                                                   //~v134I~
//*parm2:source2                                                   //~v134I~
//*ret  :result  0:match,<0,or >0-                                 //~v134I~
//*******************************************************          //~v134I~
#ifdef LNX                                                         //~v40hI~
    #ifdef ARM                                                     //~v6a0I~
int stricmp(const char *Psrc1,const char *Psrc2)                   //~v6a0R~
    #else                                                          //~v6a0I~
int stricmp(void *Psrc1,void *Psrc2)                               //~v134R~
    #endif                                                         //~v6a0I~
#else                                                              //~v40hI~
int stricmp(const char *Psrc1,const char *Psrc2)                   //~v40hI~
#endif                                                             //~v40hI~
{                                                                  //~v134I~
    int len1,len2,minlen,rc;                                       //~v134I~
//*******************                                              //~v134I~
//  len1=strlen(Psrc1);                                            //~v134I~//~v6BkR~
    len1=(int)strlen(Psrc1);                                       //~v6BkI~
//  len2=strlen(Psrc2);                                            //~v134I~//~v6BkR~
    len2=(int)strlen(Psrc2);                                       //~v6BkI~
    minlen=min(len1,len2);                                         //~v134I~
#ifdef ARM                                                         //~v6a0I~
    if (rc=memicmp((void*)Psrc1,(void*)Psrc2,minlen),rc)           //~v6a0I~
#else                                                              //~v6a0I~
//  if (rc=memicmp(Psrc1,Psrc2,minlen),rc)                         //~v134I~//~v6BkR~
    if (rc=memicmp(Psrc1,Psrc2,(size_t)minlen),rc)                 //~v6BkI~
#endif                                                             //~v6a0I~
        return rc;                                                 //~v134R~
    return len1-len2;                                              //~v134I~
}//stricmp                                                         //~v134I~
#endif //MGW32                                                     //~v5ncR~
//*******************************************************          //~v134I~
//*itoa                                                            //~v134I~
//* parm1 :int value                                               //~v134I~
//* parm2 :output string                                           //~v134I~
//* parm3 :radix(support only 8,10,16)                             //~v134I~
//* return:psz(top is "-" if minus value) max 18 for dos max 34 for os2//~v134I~
//******************************************************           //~v134I~
char *itoa(int Pvalue,char *Pstring,int Pradix)                    //~v134I~
{                                                                  //~v134I~
    char *conv;                                                    //~v134R~
//******************                                               //~v134I~
    switch(Pradix)                                                 //~v134R~
    {                                                              //~v134I~
    case 8:                                                        //~v134I~
        conv="%o";                                                 //~v134R~
        break;                                                     //~v134I~
    case 10:                                                       //~v134I~
        conv="%d";                                                 //~v134R~
        break;                                                     //~v134I~
    case 16:                                                       //~v134I~
        conv="%x";                                                 //~v134R~
        break;                                                     //~v134R~
    default:                                                       //~v134I~
        return 0;                                                  //~v134R~
    }                                                              //~v134I~
    sprintf(Pstring,conv,Pvalue);                                  //~v134R~
    return Pstring;                                                //~v134I~
}//itoa                                                            //~v134I~
#if !(defined(ARM) && defined(XXE))                                //~v6a0I~
//*******************************************************          //~v50zI~
//*kbhit                                                           //~v50zI~
//ret : 0:no kbd input exist,else exist                            //~v50zI~
//******************************************************           //~v50zI~
int  kbhit(void)                                                   //~v50zI~
{                                                                  //~v50zI~
//******************                                               //~v50zI~
    return ukbdl_kbhit();	//once raw and no wait mode            //~v50zR~
}//kbhit                                                           //~v50zI~
//*******************************************************          //~v50zI~
//*getch not under curses                                          //~v50zR~
//******************************************************           //~v50zI~
int  getch_nc(void)                                                //~v50zR~
{                                                                  //~v50zI~
//******************                                               //~v50zI~
    ukbdl_getch_init();     //init by echo on                      //~v50zI~
    return ukbdl_getch(UKBDL_GETCH_ONCE);	//close row mode       //~v50zI~
}//getch                                                           //~v50zI~
//*******************************************************          //~v134I~
//*getche                                                          //~v134I~
//******************************************************           //~v134I~
int  getche(void)                                                  //~v134I~
{                                                                  //~v134I~
//******************                                               //~v134I~
    ukbdl_getche_init();     //init by echo on                     //~v39bR~
    return ukbdl_getche(UKBDL_GETCHE_ONCE);	//close row mode       //~v50zR~
}//getche                                                          //~v134I~
#endif //ARMXXE                                                    //~v6a0I~
#ifndef MGW32  //cygwin has spawn definition in process.h          //~v5ncI~
//**************************************************************** //~v134I~
//* spawnvp (path search)                                          //~v134I~
//* create child process and exec                                  //~v134I~
//*parm1 :mode flag (P_WAIT / P_NOWAIT)                            //~v134I~
//*parm2 :pathname                                                 //~v134I~
//*parm3 :argv                                                     //~v134I~
//*retrn:pid(if NOWAIT),stop status(if WAIT),-1(child not started or execv failed)//~v134I~
//**************************************************************** //~v134I~
int spawnvp(int Pmodeflag,char *Ppathname,char *Pargv[])           //~v134I~
{                                                                  //~v134I~
	int rc;                                                        //~v134I~
//*********************                                            //~v134I~
	Spsw=1;                                                        //~v134I~
	rc=spawnv(Pmodeflag,Ppathname,Pargv);                          //~v134R~
	Spsw=0;                                                        //~v134I~
    return rc;                                                     //~v134I~
}//spawnvp(int Pmodeflag,char *Ppathname,char *Pargv[])            //~v134I~
//**************************************************************** //~v134I~
//* spawnv (no path search)                                        //~v134I~
//* create child process and exec                                  //~v134I~
//*parm1 :mode flag (P_WAIT / P_NOWAIT)                            //~v134I~
//*parm2 :pathname                                                 //~v134I~
//*parm3 :argv                                                     //~v134I~
//*retrn:pid(if NOWAIT),stop status(if WAIT),-1(child not started or execv failed)//~v134I~
//**************************************************************** //~v134I~
int spawnv(int Pmodeflag,char *Ppathname,char *Pargv[])            //~v134I~
{                                                                  //~v134I~
	pid_t pid;                                                     //~v134I~
    int   status;     // exitcode(1byte,0 if signal())+signal(1byte,0 if exit())//~v134I~
    int   rc;                                                      //~v134I~
//*********************                                            //~v134I~
	pid=fork();                                                    //~v134I~
    if (pid==-1)	//err                                          //~v134I~
    	return -1;	//leave errno                                  //~v134I~
    else                                                           //~v134I~
    if (pid)		//parent                                       //~v134I~
    {                                                              //~v134I~
    	if (Pmodeflag==P_NOWAIT)                                   //~v134I~
        	return pid;                                            //~v134I~
        if (wait(&status)==-1)                                     //~v134I~
        	return -1;                                             //~v134I~
        if (WIFSIGNALED(status))	//stop by signal               //~v134I~
        	return status;                                         //~v134I~
        rc=WEXITSTATUS(status);		//exitcode                     //~v134I~
        if (rc>0x80)	//may execv failed                         //~v134R~
        {                                                          //~v134I~
        	errno=rc-0x80;                                         //~v134R~
        	return -1;                                             //~v134I~
        }                                                          //~v134I~
        return status;                                             //~v134I~
    }                                                              //~v134I~
//child process                                                    //~v134I~
	if (Spsw)                                                      //~v134I~
		execvp(Ppathname,Pargv);                                   //~v134I~
    else                                                           //~v134I~
		execv(Ppathname,Pargv);                                    //~v134I~
//execv failed                                                     //~v134I~
    exit(0x80+errno);                                              //~v134R~
}//spawnv                                                          //~v134I~
#endif //MGW32                                                     //~v5ncI~
