//*CID://+v6BkR~:                             update#=   29;       //~v6BkR~
//*************************************************************
//*udos2.c
//*************************************************************
//*ugetdrivetype
//*************************************************************
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6n0:130816 compiler warning;set but not used                    //~v6n0I~
//v6c1:120120 udos_setenv:to append to $PATH,specify explicit option(duplicated fpr ICUDATA)//~v6c1I~
//v6bo:111214 putenv(dont free)/setenv(copyed, can be free)        //~v6boI~
//v5kp:070613 (BUG)repeated rctl is effective only once(need keyup)//~v5kpI~
//v5ay:040114 ugetdriveidlist:support all type get                 //~v5ayI~
//v566:020703 new function of drive id list for xff all            //~v566I~
//v561:020630 (UNX)ugetdrivetype support                           //~v561I~
//v180:980508 add ugetdrivetype
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef UNX                                                         //~v561I~
#else                                                              //~v561I~
	#include <direct.h>                                            //~v561R~
	#include <io.h>                                                //~v561I~
#endif                                                             //~v561I~
#include <errno.h>
//*******************************************************
#ifdef DOS
	#include <dos.h>
    #ifdef DPMI					//DPMI version
        #include <errno.h>                                         //~v180I~
        #include <sys/ioctl.h>                                     //~v180I~
    #else                       //not DPMI
    #endif                      //DPMI or not
#else
	#ifdef W32
    	#include <windows.h>    //GetVersion
	#else
    	#define INCL_BASE
   		#define INCL_DOSDEVIOCTL                                   //~v180I~
    	#define INCL_DOS                                           //~v180I~
    	#include <os2.h>
	#endif
#endif

//*******************************************************
#include <ulib.h>
#include <udos2.h>                                                 //~v180R~
#include <uerr.h>
#include <ufile.h>                                                 //~v180I~
#include <ualloc.h>                                                //~v6boR~
#include <utrace.h>                                                //~v6boI~
#ifdef DOS
    #ifdef DPMI					//DPMI version
    #else                       //not DPMI
    #endif                      //DPMI or not
#endif

//*******************************************************
//*dummy for lib(same name as file)						*
//*******************************************************
void udos2(void)
{
	return;
}
//*****************************************************************//~v566I~
//*get drive id list                                               //~v566I~
//*ugetdrivelist                                                   //~v566I~
//*parm1: request drive type; 0:removable,1:fixed,2:cdrom(DOS),3:cdrom(win)//~v566I~
//*                           -1:all type                          //~v5ayI~
//*parm2: output driveid list                                      //~v566I~
//*ret:driveid count                                               //~v566I~
//*****************************************************************//~v566I~
int ugetdriveidlist(int Ptype,char *Pdriveidlist)                  //~v566I~
{                                                                  //~v566I~
    int ii,dtype,didctr=0;                                         //~v566I~
//***********************                                          //~v566I~
    for (ii=0;ii<26;ii++)         //3=c:                           //~v566I~
    {                                                              //~v566I~
    	dtype=ugetdrivetype((char)('A'+ii),0);                     //~v566I~
      if (Ptype==-1)  //list all type                              //~v5ayI~
      {                                                            //~v5ayI~
        if (dtype>=0)                                              //~v5ayI~
        	*(Pdriveidlist+didctr++)=(char)('A'+ii);               //~v5ayI~
      }                                                            //~v5ayI~
      else                                                         //~v5ayI~
      {                                                            //~v5ayI~
        if (dtype==Ptype)                                          //~v566I~
        	*(Pdriveidlist+didctr++)=(char)('A'+ii);               //~v566R~
      }                                                            //~v5ayI~
    }                                                              //~v566I~
    return didctr;                                                 //~v566I~
}//ugetdriveidlist                                                 //~v566I~
//*****************************************************************//~v566I~
//*get drive id list                                               //~v566I~
//*ugetdrivelist                                                   //~v566I~
//*parm1: request drive type; 0:removable,1:fixed,2:cdrom(DOS),3:cdrom(win)//~v566I~
//*ret:ULONG corresponding bit on if drive defined;                //~v566I~
//           A=0x00000001,B=00000002,... Z=0x02000000              //~v566I~
//*****************************************************************//~v566I~
ULONG ugetdrivelist(int Ptype)                                     //~v566I~
{                                                                  //~v566I~
    int ii,dtype;                                                  //~v566R~
    ULONG dlist,biton;                                             //~v566I~
//***********************                                          //~v566I~
	biton=0x01;	//a:                                               //~v566I~
    dlist=0;                                                       //~v566I~
    for (ii=0;ii<26;ii++)         //3=c:                           //~v566I~
    {                                                              //~v566I~
    	dtype=ugetdrivetype((char)('A'+ii),0);                     //~v566I~
        if (dtype==Ptype)                                          //~v566I~
        	dlist |= biton;                                        //~v566I~
        biton<<=1;                                                 //~v566I~
    }                                                              //~v566I~
    return dlist;                                                  //~v566I~
}//ugetdrivelist                                                   //~v566I~
//*****************************************************************
//*ugetdrivetype  **************************************************
//*parm1:drive letter  a,b etc ,x00 for current
//*ret  :drive type
//*****************************************************************
int ugetdrivetype(char Pdriveid,int Pmsgopt)
{
#ifdef UNX                                                         //~v561M~
    char path[4];                                                  //~v561M~
	int rc,msgrc;                                                  //~v561I~
#else                                                              //~v561M~
    int drvid;
	int rc,msgrc;
#ifdef DOS
	#ifdef DPMI
	#else
		union 	REGS	reg;
    #endif
#else
    #ifdef W32
        char *prootdir;
        char  rootdir[4];
    #else
		char parmpacket[2];	//cmd info and drive unit
        char datapacket;
		ULONG outl1=sizeof(parmpacket);
		ULONG outl2=sizeof(datapacket);
    #endif
#endif
#endif                                                             //~v561I~
//*************************
#ifdef UNX                                                         //~v561I~
    path[0]=Pdriveid;                                              //~v561I~
    path[1]=':';                                                   //~v561I~
    if (MDOSDISK(path))                                            //~v561I~
    	if (MDOSDISKOK(path))                                      //~v561I~
        	rc=0;		//removable                                //~v561I~
        else                                                       //~v561I~
        	rc=UDDC_ERR;      //not removable                      //~v566R~
    else                                                           //~v561I~
    	rc=UDDC_INVDRVID;//err                                     //~v566R~
    msgrc=rc;                                                      //~v561I~
#else                                                              //~v561I~
    if (Pdriveid)
        drvid=toupper(Pdriveid)-'A'+1;
    else
        drvid=0;        //current

#ifdef DOS
	#ifdef DPMI
    	rc=ioctl(drvid,DOS_ISCHANGEABLE);
        if (rc==-1)
        {                   //__doserr_toerrno change 1-->14,15-->21
            msgrc=rc=errno;      //14:invalid func  EINVAL
            switch(rc)
            {
            case EINVAL:    //network,cdrom
                rc=UDDC_REMOTE;
                break;
            case ENODEV:    //invalid drive
                rc=UDDC_INVDRVID;
                break;
            default:
                rc=UDDC_ERR;
            }
        }
    #else
		reg.x.bx=drvid;
		reg.x.ax=0x4408;	//ioctl/removable chk
		intdos(&reg,&reg);				//set cursor pos
        rc=reg.x.ax;
        if (reg.x.cflag)	//err
            switch(msgrc=rc,rc)
            {
            case 1:         //network,cdrom
                rc=UDDC_REMOTE;
                break;
            case 15:        //invalid drive
                rc=UDDC_INVDRVID;
                break;
            default:
                rc=UDDC_ERR;
            }
    #endif
#else
	#ifdef W32
    	if (Pdriveid)
        {
        	rootdir[0]=Pdriveid;
            rootdir[1]=':';
            rootdir[2]='\\';
            rootdir[3]=0;
            prootdir=rootdir;
        }
        else
            prootdir=0;
        rc=GetDriveType(prootdir);
//      printf("rc=%08x\n",rc);
        switch(msgrc=rc,rc)
        {
        case DRIVE_UNKNOWN:         //0
        case DRIVE_NO_ROOT_DIR:     //1
            rc=UDDC_INVDRVID;
            break;
        case DRIVE_REMOVABLE:       //2
            rc=UDDC_REMOVABLE;
            break;
        case DRIVE_CDROM:           //5
            rc=UDDC_CDROM;
            break;
        case DRIVE_FIXED:           //3
            rc=UDDC_FIXED;
            break;
        case DRIVE_RAMDISK:         //6
            rc=UDDC_RAMDISK;
            break;
        case DRIVE_REMOTE:          //4
            rc=UDDC_REMOTE;
            break;
        default:
            rc=UDDC_ERR;
        }
    #else
    	if (drvid)
        	drvid--;		//A:0,B:1...
		else
        	drvid=ugetdrive()-'A';
		parmpacket[0]=0;	//cmd info and drive unit
		parmpacket[1]=(char)drvid;	//cmd info and drive unit
		rc=(int)DosDevIOCtl((ULONG)(-1),
					(ULONG)IOCTL_DISK,	//categoly 8
					(ULONG)DSK_BLOCKREMOVABLE,	//func  x20
					&parmpacket,	//	packet
					sizeof(parmpacket),
					&outl1,
					&datapacket,
					sizeof(datapacket),
					&outl2);
		msgrc=rc;
		if (rc)
            switch(msgrc=rc,rc)
            {
            case 1:         //network,cdrom
                rc=UDDC_REMOTE;
                break;
            case 15:        //invalid drive
                rc=UDDC_INVDRVID;
                break;
            default:
                rc=UDDC_ERR;
            }
		else
        	rc=(int)datapacket;
    #endif
#endif
#endif                                                             //~v561I~
    if (rc<0)
	    if (Pmsgopt & UDDC_ERRMSG)
    	    uerrmsg("Invalid drive id - %c(rc=%d)",
        	        "–³Œø‚Èƒhƒ‰ƒCƒu‚Å‚· - %c(rc=%d)",
            	    Pdriveid,msgrc);
	return rc;
}//ugetdrivetype
#ifdef DOS                                                         //~v5ayI~
//**************************************************               //~v5ayI~
//*udossleephs                                                     //~v5ayI~
//*sllep by 1/100 sec max 60.00 sec 1min                           //~v5kpR~
//**************************************************               //~v5ayI~
int udossleephs(int Phs)                                           //~v5ayI~
{                                                                  //~v5ayI~
	union 	REGS	reg;                                           //~v5ayI~
    int     mm0,mm,stop,now,maxhs=5999;                            //~v5kpR~
//*********************                                            //~v5ayI~
	if (Phs>=maxhs||Phs<0)                                         //~v5kpI~
    	Phs=maxhs;                                                 //~v5kpI~
    reg.h.ah=0x2c;                  //get curr disk                //~v5kpI~
    intdos(&reg,&reg);              //set cursor pos               //~v5kpI~
//printf("start hh=%d,mm=%d,ss=%d,hs=%d\n",reg.h.ch,reg.h.cl,reg.h.dh,reg.h.dl);//~v5kpR~
    mm0=reg.h.cl;                   //mm                           //~v5kpI~
    stop=reg.h.dh*100+reg.h.dl+Phs; //ss*100+hs+sleeptime          //~v5kpI~
//printf("start mm=%d,stop=%d,req=%d\n",mm0,stop,Phs);             //~v5kpR~
    for (;;)                                                       //~v5kpI~
    {                                                              //~v5kpI~
	    reg.h.ah=0x2c;                  //get curr disk            //~v5kpI~
    	intdos(&reg,&reg);              //set cursor pos           //~v5kpI~
	    mm=reg.h.cl;                                               //~v5kpI~
	    now=reg.h.dh*100+reg.h.dl; //ss*100+hs                     //~v5kpR~
        if (mm!=mm0)	//min changed                              //~v5kpI~
		    now+=6000;                                             //~v5kpI~
        if (now>stop)                                              //~v5kpI~
        	break;                                                 //~v5kpI~
    }                                                              //~v5kpI~
//printf("exit hh=%d,mm=%d,ss=%d,hs=%d\n",reg.h.ch,reg.h.cl,reg.h.dh,reg.h.dl);//~v5kpR~
	return 0;                                                      //~v5kpR~
}//udossleephs                                                     //~v5kpI~
#endif                                                             //~v5ayI~
//**************************************************               //~v6boI~
//*udos_setenv                                                     //~v6boI~
//*windows dose not support setenv(copy to env)                    //~v6boI~
//*windows supports putenv(save parm pointer)                      //~v6boI~
//**************************************************               //~v6boI~
int udos_setenv(int Popt,char *Pkey,char *Pvalue)                  //~v6boI~
{                                                                  //~v6boI~
	char *old,*new;                                                //~v6boI~
//  int oldlen,addlen,keylen,rc;                                   //~v6n0R~
    int oldlen,addlen,       rc;                                   //~v6n0I~
#ifdef W32                                                         //~v6n0I~
    int keylen;                                                    //~v6n0I~
#endif                                                             //~v6n0I~
//#ifdef W32                                                       //~v6boR~
//    char buff[1024];    //for test                               //~v6boR~
//#endif                                                           //~v6boR~
//*******************                                              //~v6boI~
#ifdef W32                                                         //~v6n0I~
	keylen=(int)strlen(Pkey);                                      //~v6boI~
#endif                                                             //~v6n0I~
    addlen=(int)strlen(Pvalue);                                    //~v6boI~
	old=getenv(Pkey);                                              //~v6boI~
	UTRACEP("udos_setenv old=%p=%s\n",old,old);                    //~v6boR~
    if (!old)                                                      //~v6boI~
    	oldlen=0;                                                  //~v6boI~
    else                                                           //~v6boI~
//    	oldlen=strlen(old);                                        //~v6boI~//~v6BkR~
      	oldlen=(int)strlen(old);                                   //~v6BkI~
#ifdef W32                                                         //~v6boI~
    new=malloc(oldlen+addlen+keylen+4);    //dont free for pputenv until exit//~v6boI~
    if (!old)                                                      //~v6boI~
    	sprintf(new,"%s=%s",Pkey,Pvalue);                          //~v6boR~
    else                                                           //~v6boI~
      if (Popt & UDSE_PREPEND)                                     //~v6c1I~
    	sprintf(new,"%s=%s%c%s",Pkey,Pvalue,';',old);              //~v6boR~
      else                                                         //~v6c1I~
    	sprintf(new,"%s=%s",Pkey,Pvalue);                          //~v6c1I~
#else                                                              //~v6boI~
    if (!old)                                                      //~v6boI~
    	new=Pvalue;                                                //~v6boI~
    else                                                           //~v6boI~
    {                                                              //~v6boI~
//  	new=umalloc(oldlen+addlen+4);    //dont free for pputenv until exit//~v6boI~//~v6BkR~
    	new=umalloc((size_t)(oldlen+addlen+4));    //dont free for pputenv until exit//~v6BkI~
      if (Popt & UDSE_PREPEND)                                     //~v6c1I~
      {                                                            //~v6c1I~
#ifdef UNX                                                         //~v6boI~
    	sprintf(new,"%s%c%s",Pvalue,':',old);                      //~v6boR~
#else                                                              //~v6boI~
    	sprintf(new,"%s%c%s",Pvalue,';',old);                      //~v6boR~
#endif                                                             //~v6boI~
      }                                                            //~v6c1I~
      else                                                         //~v6c1I~
    	new=Pvalue;                                                //~v6c1I~
    }                                                              //~v6boI~
#endif                                                             //~v6boI~
#ifdef W32                                                         //~v6boI~
//  SetEnvironmentVariable(Pkey,Pvalue);                           //~v6boR~
//    GetEnvironmentVariable(Pkey,buff,sizeof(buff));              //~v6boR~
//    UTRACEP("GetEnvironmentValiable before=%s\n",buff);          //~v6boR~
	rc=putenv(new);    //putenv should not free source string, setenv(not in Windows) copyed to env//~v6boI~
    UTRACEP("after putenv rc=%d,errno=%d,new=%p=%s,getenv=%p=%s\n",rc,errno,new,new,getenv(Pkey),getenv(Pkey));//~v6boR~
//    GetEnvironmentVariable(Pkey,buff,sizeof(buff));              //~v6boR~
//    UTRACEP("GetEnvironmentValiable after =%s\n",buff);          //~v6boR~
#else                                                              //~v6boI~
	rc=setenv(Pkey,new,1/*override*/);                             //~v6boR~
    if (new!=Pvalue)                                               //~v6boI~
    	ufree(new);	//copyed to env                                //~v6boI~
    UTRACEP("after setenv rc=%d,errno=%d,new=%p,Pvalue=%p,key=%s,getenv=%s\n",rc,errno,new,Pvalue,Pkey,getenv(Pkey));//~v6boI~//+v6BkR~
#endif                                                             //~v6boI~
    return rc;                                                     //~v6boI~
}//udos_setenv                                                     //~v6boI~
