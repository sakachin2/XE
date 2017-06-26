//CID://+v6BkR~:      update#=     1                               //+v6BkR~
//*************************************************************
//*uunxsub.c
//*************************************************************
//v6Bk:160220 (LNX)compiler warning                                //+v6BkI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v5ib:060607 (BUG)uninitialized variable used compiler warning    //~v5ibI~
//v50P:010908 gethostname function                                 //~v50PI~
//v40d:001109 AIX support:header file difference                   //~v401I~
//v401:001027 AIX support:ncurses.h should be curses.h             //~v401I~
//v39s:010107 LINUX support:lock file support for ::so             //~v39sI~
//v385:001001 LINUX support(add username/groupename search func)   //~v385I~
//v363:000927 LINUX support(term info by setupterm not scrinit/endwin)//~v363I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//#include <term.h>                                                //~v40dR~
#include <ucurses.h>                                               //~v401R~
#if !(defined(ARM) && defined(XXE))                                //~v6a0I~
#ifndef NOCURSES                                                   //~v6a0I~
#include <term.h>                                                  //~v40dI~
#endif //NOCURSES                                                  //~v6a0I~
#endif //ARMXXE                                                    //~v6a0I~
#include <unistd.h>                                                //~v363I~
#include <sys/types.h>
#include <pwd.h>                                                   //~v385I~
#include <grp.h>                                                   //~v385I~
#include <fcntl.h>                                                 //~v39sI~
#include <errno.h>                                                 //~v40dI~
//*******************************************************
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uunxsub.h>

//*******************************************************          //~v385I~
typedef  struct _NAMECHAIN	{                                      //~v385I~
    						struct _NAMECHAIN *NCnext;             //~v385I~
    						int                NCid;               //~v385I~
                            unsigned char      NCname[1];          //~v385I~
                        } NAMECHAIN,*PNAMECHAIN;                   //~v385I~
#define NAMECHAINSZ (sizeof(NAMECHAIN))                            //~v385I~
//*******************************************************
//*******************************************************          //~v385I~
char *usrchugname(int Pid,PNAMECHAIN Ptop);                        //~v385I~
char *uaddugname(int Pid,char *Pname,PNAMECHAIN *Pptop,PNAMECHAIN *Ppend);//~v385I~
//*******************************************************
//*******************************************************
//*get userid/groupid
//*******************************************************
void ugetugid(uid_t *Ppuid,gid_t *Ppgid)
{
static uid_t Suid;                                                 //~v385M~
static gid_t Sgid;                                                 //~v385M~
    static int Sinitsw;                                            //~v188R~
//**************************************
    if (!Sinitsw)                                                  //~v188R~
    {
        Sinitsw=1;                                                 //~v188R~
        Suid=getuid();                                             //~v188R~
        Sgid=getgid();                                             //~v188R~
    }
    if (Ppuid)
        *Ppuid=Suid;                                               //~v188R~
    if (Ppgid)
        *Ppgid=Sgid;                                               //~v188R~
    return;
}//ugetugid
//*******************************************************          //~v385I~
//*get username                                                    //~v385I~
//*******************************************************          //~v385I~
char *ugetusername(uid_t Puid)                                     //~v385I~
{                                                                  //~v385I~
static PNAMECHAIN Sunametop,Sunameend;                             //~v385I~
    struct passwd *ppw;                                            //~v385I~
    int            id;                                             //~v385R~
    char          *pname;                                          //~v385I~
//**************************************                           //~v385I~
	id=(int)Puid;                                                  //~v385I~
	if (pname=usrchugname(id,Sunametop),pname)	//search already gooten//~v385I~
    	return pname;	//already registerd                        //~v385I~
	if (!(ppw=getpwuid(Puid)))                                     //~v385R~
    	return "Unkown";                                           //~v385I~
    return uaddugname(id,ppw->pw_name,&Sunametop,&Sunameend);      //~v385I~
}//ugetusername                                                    //~v385I~
//*******************************************************          //~v385I~
//*get username                                                    //~v385I~
//*******************************************************          //~v385I~
char *ugetgroupname(gid_t Pgid)                                    //~v385I~
{                                                                  //~v385I~
static PNAMECHAIN Sgnametop,Sgnameend;                             //~v385I~
    struct group  *pgr;                                            //~v385I~
    int            id;                                             //~v385R~
    char          *pname;                                          //~v385I~
//**************************************                           //~v385I~
	id=(int)Pgid;                                                  //~v385I~
	if (pname=usrchugname(id,Sgnametop),pname)	//search already gooten//~v385I~
    	return pname;	//already registerd                        //~v385I~
	if (!(pgr=getgrgid(Pgid)))                                     //~v385R~
    	return "Unkown";                                           //~v385I~
    return uaddugname(id,pgr->gr_name,&Sgnametop,&Sgnameend);      //~v385I~
}//ugetgroupname                                                   //~v385I~
//*******************************************************          //~v385I~
//*search name previously saved                                    //~v385I~
//*return name ptr in chain                                        //~v385I~
//*******************************************************          //~v385I~
char *usrchugname(int Pid,PNAMECHAIN Ptop)                         //~v385I~
{                                                                  //~v385I~
	PNAMECHAIN     pnc;                                            //~v385I~
//**************************************                           //~v385I~
	for (pnc=Ptop;pnc;pnc=pnc->NCnext)                             //~v385R~
    	if (Pid==pnc->NCid)                                        //~v385I~
        	return pnc->NCname;                                    //~v385R~
    return 0;	//not found                                        //~v385I~
}//usrchugname                                                     //~v385I~
//*******************************************************          //~v385I~
//*add username/groupname entery                                   //~v385I~
//*return name ptr in chain                                        //~v385I~
//*******************************************************          //~v385I~
char *uaddugname(int Pid,char *Pname,PNAMECHAIN *Pptop,PNAMECHAIN *Ppend)//~v385I~
{                                                                  //~v385I~
	PNAMECHAIN     pnc,pnctop,pncend;                              //~v385I~
    int            len/*,id*/;                                     //~v5ibR~
    char          *pname;                                          //~v385I~
//**************************************                           //~v385I~
	len=(int)strlen(Pname);                                        //~v385I~
//  pnc=(PNAMECHAIN)malloc(NAMECHAINSZ+len);//with last null       //~v385R~//+v6BkR~
    pnc=(PNAMECHAIN)malloc(NAMECHAINSZ+(size_t)len);//with last null//+v6BkI~
    pnc->NCnext=0;                                                 //~v385I~
//  pnc->NCid=id;                                                  //~v5ibR~
    pnc->NCid=Pid;                                                 //~v5ibI~
    pname=pnc->NCname;                                             //~v385I~
//  memcpy(pname,Pname,len+1);//with last 0                        //~v385R~//+v6BkR~
    memcpy(pname,Pname,(size_t)len+1);//with last 0                //+v6BkI~
//chain                                                            //~v385I~
	pnctop=*Pptop;                                                 //~v385I~
	pncend=*Ppend;                                                 //~v385I~
	if (pnctop)                                                    //~v385I~
    {                                                              //~v385I~
    	pncend->NCnext=pnc;                                        //~v385I~
    	pncend=pnc;		//new last                                 //~v385R~
    }                                                              //~v385I~
    else                                                           //~v385I~
    	pnctop=pncend=pnc;                                         //~v385I~
    *Pptop=pnctop;                                                 //~v385I~
    *Ppend=pncend;                                                 //~v385I~
    return pname;                                                  //~v385I~
}//uaddugname                                                      //~v385I~
#if !(defined(ARM) && defined(XXE))                                //~v6a0I~
#ifndef NOCURSES                                                   //~v6a0I~
//*******************************************************          //~v363I~
//*get setup ncurses terminfo                                      //~v363I~
//*******************************************************          //~v363I~
int unc_setupterm(int Popt)                                        //~v363I~
{                                                                  //~v363I~
    static int Sncinitsw;                                          //~v363I~
    int rc;;                                                       //~v363R~
//**************************************                           //~v363I~
    if (Sncinitsw)                                                 //~v363I~
    	return 0;                                                  //~v363I~
    Sncinitsw=1;                                                   //~v363I~
    rc=setupterm(NULL,fileno(stdout),0);//curses; //termname=NULL,no out code req//~v363R~
    return rc;                                                     //~v363I~
}//unc_setupterm                                                   //~v363I~
#endif //NOCURSES                                                  //~v6a0I~
#endif //ARMXXE                                                    //~v6a0I~
//*********************************************************************//~v39sI~
//* setlock                                                        //~v39sI~
//* rc:0:lock gotten,4:lock already gotten,>=8:other error         //~v39sI~
//*********************************************************************//~v39sI~
int unx_fsetlock(char *Pfnm)                                       //~v39sI~
{                                                                  //~v39sI~
    int fd;                                                        //~v39sI~
//******************************                                   //~v39sI~
	if ((fd=open(Pfnm,O_WRONLY|O_CREAT|O_EXCL,0666))<=0)           //~v39sI~
    {                                                              //~v39sI~
    	if (errno==EEXIST)                                         //~v39sI~
        	return 4;			//lock failed                      //~v39sI~
        uerrmsg("%s lock file create-open failed,rc=%d\n",0,       //~v39sI~
				Pfnm,errno);                                       //~v39sI~
        return 8;                                                  //~v39sI~
    }                                                              //~v39sI~
    if (close(fd))//force write                                    //~v39sI~
    {                                                              //~v39sI~
        uerrmsg("%s lockfile close failed,rc=%d\n",0,              //~v39sI~
				Pfnm,errno);                                       //~v39sI~
        return 12;                                                 //~v39sI~
    }                                                              //~v39sI~
	return 0;                                                      //~v39sI~
}//unx_fsetflock                                                   //~v39sI~
//*********************************************************************//~v39sI~
//* resetlock                                                      //~v39sI~
//* rc:0:lock reset,4:err                                          //~v39sI~
//*********************************************************************//~v39sI~
int unx_fresetlock(char *Pfnm)                                     //~v39sI~
{                                                                  //~v39sI~
//******************************                                   //~v39sI~
	if (unlink(Pfnm))                                              //~v39sI~
    {                                                              //~v39sI~
        uerrmsg("%s lock file unlink failed,rc=%d\n",0,            //~v39sI~
				Pfnm,errno);                                       //~v39sI~
        return 4;			//restore                              //~v39sI~
    }                                                              //~v39sI~
	return 0;                                                      //~v39sI~
}//unx_fresetlock                                                  //~v39sI~
//*********************************************************************//~v39sI~
//* chklock                                                        //~v39sI~
//* rc:0:free,1:hold by other                                      //~v39sI~
//*********************************************************************//~v39sI~
int unx_fchklock(char *Pfnm)                                       //~v39sR~
{                                                                  //~v39sI~
    int fd;                                                        //~v39sI~
//******************************                                   //~v39sI~
	if ((fd=open(Pfnm,O_RDONLY))<=0)                               //~v39sI~
    {                                                              //~v39sI~
    	if (errno==ENOENT)                                         //~v39sI~
        	return 0;			//no lock exist                    //~v39sI~
        uerrmsg("%s lock file chk-open failed,rc=%d\n",0,          //~v39sI~
				Pfnm,errno);                                       //~v39sI~
        return 8;                                                  //~v39sI~
    }                                                              //~v39sI~
    if (close(fd))//force write                                    //~v39sI~
    {                                                              //~v39sI~
        uerrmsg("%s lockfile close failed,rc=%d\n",0,              //~v39sI~
				Pfnm,errno);                                       //~v39sI~
        return 12;                                                 //~v39sI~
    }                                                              //~v39sI~
	return 1;                                                      //~v39sI~
}//unx_fchklock                                                    //~v39sR~
//*********************************************************************//~v50PI~
//* chklock                                                        //~v50PI~
//* rc:0:free,1:hold by other                                      //~v50PI~
//*********************************************************************//~v50PI~
int ugethostname(char *Phnm,int len)                               //~v50PI~
{                                                                  //~v50PI~
//******************************                                   //~v50PI~
//  return gethostname(Phnm,len);                                  //~v50PR~//+v6BkR~
    return gethostname(Phnm,(size_t)len);                          //+v6BkI~
}//ugethostname                                                    //~v50PI~
