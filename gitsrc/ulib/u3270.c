//*CID://+v6J0R~:                             update#=  627;       //~v6J0R~
//*************************************************************
//*u3270.c   :3270 FTP version                                     //~v5j4R~
//*************************************************************
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6G3:161212 (Win10) missing error.h , use winerror.h             //~v6G3I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6Bi:160212 (W32)compiler warning                                //~v6BiI~
//v6r0:131215 (ARM)warning strict aliasing                         //~v6r0I~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6hk:120630 (BUG of V6hh) ((int*)(ULPTR)parm)[2] should be ((ULPTR*)(ULPTR)parm)[2] or (int)(ULPTR)(parm[2])//~v6hkI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v63a:091119 (BUG)AIX122 comilation err                           //~v63aI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5mx:080602 pass hostid to identify logon cmd hostid             //~v5mxI~
//v5ma:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v5maI~
//v5kr:070701 (BUG:3270)widcard replace loss quatation when wildcard is top//~v5krI~
//v5jA:061203 (BUG:3270):no response msg for free cmd success      //~v5jAI~
//v5jy:061123 3270:SPF information update                          //~v5jvI~
//v5jv:061116 3270:spf info support by xe4s001z                    //~v5jvI~
//v5ju:061116 3270:listds fail by 'sys1.*' because sys1.duplex has no dsorg recfm(VSAM)//~v5juI~
//v5jr:061103 (3270) return D/S info weven when member not found   //~v5jrI~
//v5jg:061015 3270 CurDir utilize for the case no path specified   //~v5jgI~
//v5jd:061002 3270 support:rename/delete                           //~v5jdI~
//v5jc:061002 3270 support:dsn wildcard support                    //~v5jcI~
//v5jb:061002 3270 support:udirlist support                        //~v5j4I~
//v5j4:060914 ftp:3270 support (xehost TSO=portno operand)         //~v5j4I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#ifdef UNX
	#include <unistd.h>
#else
	#include <dos.h>
  #ifdef MGW32                                                     //~v5ncI~
	#include <winerror.h>                                          //~v5ncI~
  #else                                                            //~v5ncI~
   #ifdef WIN10                                                   //+v6BkI//~v6G3I~
	#include <winerror.h>                                          //~v6G3I~
   #else                                                           //~v6G3I~
	#include <error.h>
   #endif                                                         //+v6BkI//~v6G3I~
  #endif                                                           //~v5ncI~
#endif
//*******************************************************
#include <ulib.h>
#include <uque.h>                                                  //~v5afM~
#include <ufile.h>
#include <uftp.h>                                                  //~v5jgM~
#include <ufile1f.h>                                               //~v5jgI~
#include <ufile5.h>                                                //~v5j4I~
#include <uerr.h>
#include <ufemsg.h>
#include <uparse.h>
#include <ustring.h>
#include <utrace.h>
#include <ualloc.h>
#include <uproc.h>                                                 //~v5jbM~
#include <u3270.h>                                                 //~v5j4I~
//*******************************************************          //~v5jdI~
static char *Sserverstartcmd;                                      //~v5j4R~
static char *Spipename;                                            //~v5j4I~
static int  Snopmode;                                              //~v5j4I~
static char *Svalidname="@$#";                                     //~v5jdR~
//*******************************************************          //~v5j4I~
int u3270editrespmsg(char *Pin,char *Pout,int Poutbuffsz);         //~v5j4I~
int u3270setdirlist(PPDSMEMBLIST Pppml,char *Pfpath,int *Ppentno,PUDIRLIST *Pppudl);//~v5j4I~
int u3270setdirlistdsn(int Plevel,char *Pwild,PDSNLIST Ppdsnl,char *Pfpath,int *Ppentno,PUDIRLIST *Pppudl);//~v5jgR~
//*******************************************************          //~v5j4I~
//*param from xe                                                   //~v5j4I~
//*1:start server cmd                                              //~v5j4I~
//*2:pipename between server                                       //~v5j4I~
//*******************************************************          //~v5j4I~
int u3270init(void **Poptions)                                     //~v5j4R~
{                                                                  //~v5j4I~
//*******************************************:                     //~v5j4I~
//	Sserverstartcmd=((char**)(ULONG)Poptions)[0];                  //~v5j4R~//~v6hhR~
	Sserverstartcmd=((char**)(ULPTR)Poptions)[0];                  //~v6hhI~
//	Spipename=((char**)(ULONG)Poptions)[1];                        //~v5j4R~//~v6hhR~
	Spipename=((char**)(ULPTR)Poptions)[1];                        //~v6hhI~
//	Snopmode=((int*)(ULONG)Poptions)[2];                           //~v5j4R~//~v6hhR~
//	Snopmode=((int*)(ULPTR)Poptions)[2];                           //~v6hkR~
 	Snopmode=(int)(ULPTR)Poptions[2];                              //~v6hkR~
    return 0;                                                      //~v5j4I~
}//u3270init                                                       //~v5j4I~
//*******************************************************
//*fstat                                                           //~v5j4I~
//* assume alway exist at normal file                              //~v5j4I~
//* set member if specified                                        //~v5j4I~
//*******************************************************          //~v5j4I~
unsigned int u3270fstat(PUFTPHOST Ppuftph,char *Pfpath,FILEFINDBUF3 *Ppffb3)//~v5j4I~
{                                                                  //~v5j4I~
    FILEFINDBUF3 ft;                                               //~v5jgI~
    char cmd[MAX_CMDSZ],*pc;                                       //~v5j4R~
//  PPDSMEMBLIST ppml=0;                                           //~v5jcR~//~v6b9R~
    PDSNLIST     pdsnl=0;                                          //~v5jcI~
    PPDSSPFINFO  pspfi;                                            //~v5jvI~
    PPIPERESPDATA phdr;                                            //~v5jcI~
    PDSNDATA pdsd;                                                 //~v5jcI~
    int rc,datalen,chkmembrc=0,entno;                              //~v5jdR~
    char membname[DSN_MAXMEMBERNAMELEN+1];                         //~v5jdR~
//*******************************************:                     //~v5j4I~
    if (!Ppffb3)  //optional parm                                  //~v5jgR~
        Ppffb3=&ft;                        //use internal work     //~v5jgI~
	memset(Ppffb3,0,sizeof(FILEFINDBUF3));                         //~v5j4R~
    if (u3270getmembname(U3GM_RETLENERR,Pfpath,membname)<0     //length err//~v5jdI~
    ||  (*membname && (chkmembrc=u3270chkmembname(U3CM_CHKWILD,membname))>1))//~v5jdR~
    {                                                              //~v5jgI~
		uerrmsg("%s is invalid as membername",0,                   //~v5jgI~
        		    		membname);                             //~v5jgI~
	    return U3CR_RC_INVALIDNAME;	//membername err               //~v5jdR~
    }                                                              //~v5jgI~
    if (chkmembrc==1)	//valid but contain wildcard               //~v5jdR~
//  	return u3270findfile(0,Ppuftph,Pfpath,Ppffb3,&entno);      //~v5jdI~//~v6D0R~
    	return (unsigned)u3270findfile(0,Ppuftph,Pfpath,Ppffb3,&entno);//~v6D0I~
	pc=cmd+u3270sethostuser(Ppuftph,"listds",cmd);                 //~v5j4R~
    *pc++=' ';                                                     //~v5j4I~
    strcpy(pc,Pfpath+Ppuftph->UFTPHhostnmlen+1);                   //~v5j4I~
//  rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULONG)(&phdr),&datalen);//~v5jcR~//~v6hhR~
    rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULPTR)(&phdr),&datalen);//~v6hhI~
    if (phdr)                                                      //~v5jcI~
    {                                                              //~v5jcI~
        if (phdr->PRDtype==PRDT_MEMBL)  //response data is memberlist(dsn contains member specification)//~v5jcR~
            ;//ppml=(PPDSMEMBLIST)(ULONG)phdr;                        //~v5jcR~//~v6b9R~
        else                                                       //~v5jcR~
//          pdsnl=(PDSNLIST)(ULONG)phdr;                           //~v5jcR~//~v6hhR~
            pdsnl=(PDSNLIST)(ULPTR)phdr;                           //~v6hhI~
    }                                                              //~v5jcI~
    if (!rc)                                                       //~v5jcR~
    {                                                              //~v5jcI~
        if (pdsnl)                                                 //~v5jcI~
        {                                                          //~v5jcI~
UTRACED("dsnlist",phdr,phdr->PRDlen);                              //~v5jcI~
			pdsd=pdsnl->DSLentry;                                  //~v5jcI~
			pspfi=&pdsnl->DSLspfi;                                 //~v5jvI~
	        u3270setattr(pdsd->DSDflag,&Ppffb3->attrFile);         //~v5jcI~
            if (Ppffb3->attrFile & FILE_PO                         //~v5jyR~
            &&  Ppffb3->attrFile & FILE_RECFMF                     //~v5jyR~
	        &&  pdsd->DSDlrecl==80)                                //~v5jyI~
            	Ppffb3->attrFile|=FILE_SPFDS;   //may contain spf info//~v5jyI~
            if (Ppffb3->attrFile & FILE_PDSMEMB)                   //~v5jcI~
	            u3270getmembname(0,Pfpath,Ppffb3->achName);//0:no dummy set//~v5jcI~
//          Ppffb3->srcattr=pdsd->DSDlrecl<<16|pdsd->DSDblksize;   //~v5jcR~//~v6D0R~
            Ppffb3->srcattr=((ULONG)pdsd->DSDlrecl<<16)|(ULONG)(pdsd->DSDblksize);//~v6D0R~
            if (pdsd->DSDflag & DSDFMEMBNOTFOUND)                  //~v5jrI~
		    	rc=U3CR_RC_NOTFOUND;                               //~v5jrI~
            else                                                   //~v5jvI~
            if (pdsd->DSDflag & DSDFMEMB)   //member specified     //~v5jvI~
            {                                                      //~v5jvI~
                Ppffb3->fdateLastWrite=                            //~v5jvR~
                Ppffb3->slinkfdate=pspfi->SPFIudate;               //~v5jvI~
                Ppffb3->ftimeLastWrite=                            //~v5jvI~
                Ppffb3->slinkftime=pspfi->SPFIutime;               //~v5jvI~
                Ppffb3->slinksize=pspfi->SPFIlinecnt;              //~v5jvI~
                Ppffb3->cbFile=pspfi->SPFIlinecnt*pdsd->DSDlrecl;  //~v5jvI~
                strcpy(Ppffb3->uname,pspfi->SPFIuserid);           //~v5jvI~
                TSO_SETINITLINE(Ppffb3,pspfi->SPFIinitcnt);        //~v5jyR~
                TSO_SETVV(Ppffb3,pspfi->SPFIver);                  //~v5jyR~
                TSO_SETMM(Ppffb3,pspfi->SPFImod);                  //~v5jyR~
                TSO_SETCDATE(Ppffb3,pspfi->SPFIcdate);             //~v5jyR~
                if (pspfi->SPFIflag & SPFIFALIAS)                  //~v5jvI~
                    Ppffb3->attrFile|=FILE_ALIAS|FILE_SPECIAL;     //~v5jvI~
                if (pspfi->SPFIflag & SPFIFSPF)                    //~v5jvI~
                    Ppffb3->attrFile|=FILE_SPF;                    //~v5jvI~
            }                                                      //~v5jvI~
        }                                                          //~v5jcM~
        else                                                       //~v5jcI~
	    	rc=U3CR_RC_OTHER;                                      //~v5jcI~
    }                                                              //~v5j4I~
    if (phdr)	//DSORG=PS                                         //~v5jcR~
    	ufree(phdr);                                               //~v5jcR~
//  return rc;                                                     //~v5j4R~//~v6D0R~
    return (unsigned)rc;                                           //~v6D0I~
}//u3270fstat                                                      //~v5j4I~
//*******************************************************          //~v5jdI~
//*findfile                                                        //~v5jdI~
//* find file(accept wildcard)                                     //~v5jdI~
//* p5:optional entry count:for wildcard 0 means DS exist even if rc=notfound//~v5jdI~
//*******************************************************          //~v5jdI~
int u3270findfile(int Popt,PUFTPHOST Ppuftph,char *Pfpath,FILEFINDBUF3 *Ppffb3,int *Ppentno)//~v5jdI~
{                                                                  //~v5jdI~
    PUDIRLIST pudirlist0,pudirlist,pudirlistm=0;                   //~v5jdR~
    int rc,filectr,membctr,ii;                                     //~v5jdR~
//*******************************************:                     //~v5jdI~
    if (Ppentno)                                                   //~v5jdI~
        *Ppentno=-1;                                               //~v5jdI~
	if (DSNWILDCARD(Pfpath)==0)                                    //~v5jdR~
//  	rc=u3270fstat(Ppuftph,Pfpath,Ppffb3);                      //~v5jdI~//~v6D0R~
    	rc=(int)u3270fstat(Ppuftph,Pfpath,Ppffb3);                 //~v6D0I~
    else                                                           //~v5jdI~
    {                                                              //~v5jdI~
        rc=u3270dirlistsub(Ppuftph,0,&filectr,Pfpath,0,&pudirlist0);//~v5jdR~
        if (!rc)                                                   //~v5jdI~
        {                                                          //~v5jdI~
            for (ii=0,membctr=0,pudirlist=pudirlist0;ii<filectr;ii++,pudirlist++)//~v5jdI~
            {                                                      //~v5jdI~
                if (strcmp(pudirlist->name,".")                    //~v5jdI~
                &&  strcmp(pudirlist->name,".."))                  //~v5jdI~
                {                                                  //~v5jdI~
                	if (!pudirlistm)                               //~v5jdI~
	                    pudirlistm=pudirlist;   //save 1st member  //~v5jdR~
	                membctr++;                                     //~v5jdI~
                }                                                  //~v5jdI~
            }                                                      //~v5jdI~
	        if (Ppentno)                                           //~v5jdI~
    	    	*Ppentno=membctr;	//no wildcard id               //~v5jdI~
            if (!membctr)                                          //~v5jdI~
            	rc=U3CR_RC_NOTFOUND;                               //~v5jdI~
            else                                                   //~v5jdI~
            {                                                      //~v5jdI~
		        memset(Ppffb3,0,sizeof(FILEFINDBUF3));             //~v5jdI~
                Ppffb3->attrFile=pudirlistm->attr;                 //~v5jdR~
                Ppffb3->srcattr=pudirlistm->srcattr;	//lrecl/blksize//~v5jdR~
                strcpy(Ppffb3->achName,pudirlistm->name);//member name//~v5jdI~
            }                                                      //~v5jdI~
//          ufree(pudirlist0);                                     //~v5jdI~//~v6qaR~
            UDIRLIST_FREE(pudirlist0);                             //~v6qaI~
        }                                                          //~v5jdI~
    }                                                              //~v5jdI~
    if (!(Popt & U3FF_NONOTFOUNDMSG))                              //~v5jdI~
    {                                                              //~v5jgI~
        if (rc==U3CR_RC_NOTFOUND)                                  //~v5jdI~
            ufilenotfound(Pfpath,rc);                              //~v5jdR~
        else                                                       //~v5jdI~
        if (rc==U3CR_RC_PATHERR)                                   //~v5jdI~
            ufilepatherr(Pfpath,rc);                               //~v5jdR~
    }                                                              //~v5jgI~
    return rc;                                                     //~v5jdI~
}//u3270findfile                                                   //~v5jdI~
//*******************************************************          //~v5jdI~
//*chk TSO filename convention                                     //~v5jdI~
// 0:local or ftp remote ,1:TSO file, 2:TSO PDS member specification//~v5jdI~
//*******************************************************          //~v5jdI~
int u3270fullpathistso(char *Pfullpath)                            //~v5jdR~
{                                                                  //~v5jdI~
	PUFTPHOST puftph;                                              //~v5jdR~
//********************************                                 //~v5jdI~
	if (!uftpisremote(Pfullpath,&puftph))                          //~v5jdI~
    	return 0;                                                  //~v5jdI~
    if (!UFTPHISTSO(puftph))                                       //~v5jdI~
    	return 0;                                                  //~v5jdI~
    if (MEMBOFDSN(Pfullpath))                                      //~v5jdI~
    	return 2;                                                  //~v5jdI~
    return 1;                                                      //~v5jdI~
}//u3270fullpathistso                                              //~v5jdI~
//*******************************************************          //~v5jgI~
//*return current path set by uchdir                               //~v5jgI~
//*******************************************************          //~v5jgI~
char *u3270getcwd(PUFTPHOST Ppuftph,char *Poutbuff)                //~v5jgR~
{                                                                  //~v5jgI~
//******************************                                   //~v5jgI~
    if (!*Ppuftph->UFTPHcwd)		//not yet set                  //~v5jgI~
        strcpy(Ppuftph->UFTPHcwd,Ppuftph->UFTPHhome);	//copy home//~v5jgI~
    strcpy(Poutbuff,Ppuftph->UFTPHcwd);                            //~v5jgI~
    if (!*Poutbuff)                                                //~v5jgI~
    	return 0;                                                  //~v5jgI~
    return Poutbuff;                                               //~v5jgI~
}//u3270getcwd                                                     //~v5jgI~
//*******************************************************          //~v5jgI~
//*change current directory                                        //~v5jgI~
//*return:0:ok else err                                            //~v5jgI~
//*******************************************************          //~v5jgI~
int u3270chdir(PUFTPHOST Ppuftph,int Popt,unsigned char *Ppath)    //~v5jgI~
{                                                                  //~v5jgI~
    int hostnmlen;                                                 //~v5jgR~
    char *pdirnm;                                                  //~v5jgR~
//*********************************                                //~v5jgI~
	hostnmlen=Ppuftph->UFTPHhostnmlen;                             //~v5jgI~
    pdirnm=Ppath+hostnmlen+1;                                      //~v5jgI~
    if (*pdirnm==DSN_QUOTE&&*(pdirnm+1)==DSN_QUOTE)                //~v5jgI~
    	*(Ppuftph->UFTPHcwd)=0;                                    //~v5jgI~
    else                                                           //~v5jgI~
	    strncpy(Ppuftph->UFTPHcwd,pdirnm,sizeof(Ppuftph->UFTPHcwd));//~v5jgR~
    return 0;                                                      //~v5jgI~
}//u3270chdir                                                      //~v5jgI~
//*******************************************************
//*return fullpath                                                 //~v5jbR~
// insert userid if not enclosed by"'"                             //~v5jbI~
//*******************************************************          //~v5j4I~
char *u3270fullpath(PUFTPHOST Ppuftph,char *Pfullpath,char *Pfname,size_t Plen)//~v5j4R~
{
    int     len,pos,offs,cwdsw;                                    //~v5jgR~
    char *pc;                                                      //~v5jcI~
    char cwd[DSN_MAXLEN];                                          //~v5jgI~
//********************************
//  len=strlen(Pfname);                                            //~v5j4I~//~v6D0R~
    len=(int)strlen(Pfname);                                       //~v6D0I~
    if ((UINT)len>=Plen)                                           //~v5j4R~
    	return 0;		//err                                      //~v5j4I~
    pos=Ppuftph->UFTPHhostnmlen+1;                                 //~v5jcI~
    pc=strchr(Pfname,FTP_REMOTEID);                                //~v5jcI~
    if (!pc)	//no remoteid specified                            //~v5jcI~
    {                                                              //~v5jcI~
    	pc=Pfullpath;                                              //~v5jcI~
    	strcpy(pc,Ppuftph->UFTPHhost);                             //~v5jcI~
        pc+=pos-1;                                                 //~v5jcI~
        *pc++=FTP_REMOTEID;                                        //~v5jcI~
        offs=0;      //src copy offset                             //~v5jcI~
    }                                                              //~v5jcI~
    else                                                           //~v5jcI~
    {                                                              //~v5jcI~
        memcpy(Pfullpath,Pfname,(UINT)pos);                        //~v5jcM~
	    offs=pos;                                                  //~v5jcR~
    }                                                              //~v5jcI~
    if (*(Pfname+offs)==DSN_QUOTE)                                 //~v5jcR~
    	strcpy(Pfullpath+pos,Pfname+offs);                         //~v5jcR~
    else                                                           //~v5jbI~
    {                                                              //~v5jgI~
		u3270getcwd(Ppuftph,cwd);	//cwd set                      //~v5jgI~
	    pc=Pfname+offs;                                            //~v5jgI~
        cwdsw=!*pc||(*pc==DSN_SEPC && !*(pc+1));                   //~v5jgR~
		if (*cwd &&  (cwdsw || DSNSIMPLENAME(pc)))                 //~v5jgR~
        {                                                          //~v5jgI~
        	if (cwdsw)                                             //~v5jgI~
            	strcpy(Pfullpath+pos,cwd);                         //~v5jgI~
            else                                                   //~v5jgI~
            {                                                      //~v5jgI~
        		*(cwd+strlen(cwd)-1)=0;                            //~v5jgR~
	    		sprintf(Pfullpath+pos,"%s(%s)%c",cwd,pc,DSN_QUOTE);//~v5jgR~
            }                                                      //~v5jgI~
        }                                                          //~v5jgI~
        else                                                       //~v5jgI~
	      if (*(Pfname+offs))                                      //~v5mxI~
	    	sprintf(Pfullpath+pos,"%c%s.%s%c",DSN_QUOTE,Ppuftph->UFTPHuser,Pfname+offs,DSN_QUOTE);//~v5jgR~
          else    //avoid invalid dsn                              //~v5mxI~
	    	sprintf(Pfullpath+pos,"%c%s%c",DSN_QUOTE,Ppuftph->UFTPHuser,DSN_QUOTE);//~v5mxI~
    }                                                              //~v5jgI~
    strupr(Pfullpath+pos);                                         //~v5jcR~
    return Pfullpath;
}//u3270fullpath                                                   //~v5j4R~
//*******************************************************          //~v5jcI~
//*get file fullpath name(expand wildcard path/member)             //~v5jcI~
//*return:0:no wildcard,1:wildcard changed,                        //~v5jcI~
//*       2:last path wild card but not changed                    //~v5jcI~
//*       3:intermediate path wild card but not changed            //~v5jcI~
//*       4:err                                                    //~v5jcI~
//*******************************************************          //~v5jcI~
int u3270fullpathwildexp(int Popt,PUFTPHOST Ppuftph,char *Pfullpath,char *Pfilename,size_t Plen)//~v5jcI~
{                                                                  //~v5jcI~
    char *pc,*pcwild;                                              //~v5jcR~
    char dsn[DSN_MAXLEN+2],dsn2[DSN_MAXLEN+2],membname[DSN_MAXMEMBERNAMELEN+1],quotestr[2];//~v5jcR~
    PUDIRLIST pudirlist,pudirlist0,pudirlistm=NULL;                     //~v5jcI~//~v6h7R~
    int ii,filectr,rc,membctr,quote,lastwildsw;                    //~v5jcR~
//*********************************                                //~v5jcI~
    if ((pcwild=DSNWILDCARD(Pfilename))==0)                        //~v5jcI~
    {                                                              //~v5jcI~
    	strcpy(Pfullpath,Pfilename);                               //~v5jcI~
    	return 0;	//no wildcard                                  //~v5jcI~
    }                                                              //~v5jcI~
    lastwildsw=0;                                                  //~v5jcR~
    if (!strpbrk(pcwild,DSN_SEPS))	//"." or "(" not found         //~v5jcI~
    {                                                              //~v5jcI~
		if (!(Popt & FPOPT_MEMBEXP))    //not requested last memb expand//~v5jcI~
        {                                                          //~v5jcI~
	    	strcpy(Pfullpath,Pfilename);                           //~v5jcI~
            return 2;		//wild is last but not requested expand//~v5jcI~
        }                                                          //~v5jcI~
        else                                                       //~v5jcI~
        	lastwildsw=1;                                          //~v5jcI~
    }                                                              //~v5jcI~
    pc=Pfilename+Ppuftph->UFTPHhostnmlen+1;                        //~v5jcR~
	u3270getmembname(0,pc,membname);                               //~v5jcR~
    if (*pc==DSN_QUOTE)                                            //~v5jcR~
    	quote=DSN_QUOTE;                                           //~v5jcI~
    else                                                           //~v5jcI~
    	quote=0;                                                   //~v5jcI~
//  quotestr[0]=quote;                                             //~v6BiI~
    quotestr[0]=(char)quote;                                             //~v5jcI~//~v6BiR~
    quotestr[1]=0;                                                 //~v5jcI~
    *(dsn+DSN_MAXLEN)=0;                                           //~v5jcI~
    *(dsn2+DSN_MAXLEN)=0;                                          //~v5jcI~
                                                                   //~v5jcI~
    strncpy(dsn,Pfilename,DSN_MAXLEN);                             //~v5jcR~
    pc=MEMBOFDSN(dsn);                                             //~v5jcI~
    if (pc)       //drom membname to dirlist                       //~v5jcI~
    {                                                              //~v5jcI~
    	if (quote)                                                 //~v5jcI~
//      	*pc++=quote;                                           //~v5jcI~//~v6BiR~
        	*pc++=(char)quote;                                     //~v6BiI~
        *pc=0;                                                     //~v5jcI~
    }                                                              //~v5jcI~
    if (DSNWILDCARD(dsn))	//dsn contain wildcard                 //~v5jcI~
    {                                                              //~v5jcI~
        rc=u3270dirlistsub(Ppuftph,0,&filectr,dsn,0,&pudirlist0);  //~v5jcI~
        if (rc)                                                    //~v5jcI~
            return 4;                                              //~v5jcI~
        for (ii=0,membctr=0,pudirlist=pudirlist0;ii<filectr;ii++,pudirlist++)//~v5jcI~
        {                                                          //~v5jcI~
            if (strcmp(pudirlist->name,".")                        //~v5jcI~
            &&  strcmp(pudirlist->name,".."))                      //~v5jcI~
            {                                                      //~v5jcI~
                pudirlistm=pudirlist;   //save member              //~v5jcI~
                break;                                             //~v5jcI~
            }                                                      //~v5jcI~
            membctr++;                                             //~v5jcI~
        }                                                          //~v5jcI~
        if (filectr!=membctr+1)	//not 1 entry                      //~v5jcI~
        {                                                          //~v5jcI~
//      	ufree(pudirlist0);                                     //~v5jcI~//~v6qaR~
        	UDIRLIST_FREE(pudirlist0);                             //~v6qaI~
            if (lastwildsw)                                        //~v5jcI~
            	return 2;                                          //~v5jcI~
	        return 3;                                              //~v5jcI~
        }                                                          //~v5jcI~
//        if (*membname)  //with membername                        //~v5jgR~
//            sprintf(dsn2,"%s:%s%s(%s)%s",Ppuftph->UFTPHhost,quotestr,pudirlistm->name,membname,quotestr);//~v5jgR~
//        else                                                     //~v5jgR~
////          sprintf(dsn2,"%s:%s%s%s",Ppuftph->UFTPHhost,quotestr,pudirlistm->name,quotestr);//~v5jgR~
//            u3270concatfilename(0,Pfilename,pudirlistm->name,dsn2);//~v5jgR~
//  	u3270getsetdsnwild(U3DW_SET,Pfilename,dsn2,pudirlistm->name,0);//~v5jgR~//~v6J0R~
	 	{                                                          //~v6J0I~
			UDIRLIST_NAMECOPY2WK(pudirlistm,wkudlname);            //+v6J0R~
    		u3270getsetdsnwild(U3DW_SET,Pfilename,dsn2,wkudlname,0);//~v6J0R~
        	udirlist_setname(0,pudirlistm,wkudlname,0);	//@@@@FIXME test//~v6J0R~
        }                                                          //~v6J0I~
//      ufree(pudirlist0);                                         //~v5jcI~//~v6qaR~
        UDIRLIST_FREE(pudirlist0);                                 //~v6qaI~
        if (DSNWILDCARD(membname)==0)	//not wildcard membername  //~v5jcI~
        {                                                          //~v5jcI~
	    	strcpy(Pfullpath,dsn2);                                //~v5jcI~
        	return 1;		//wildcard filled                      //~v5jcI~
        }                                                          //~v5jcI~
    }                                                              //~v5jcI~
    else                                                           //~v5jcI~
        strncpy(dsn2,Pfilename,DSN_MAXLEN);	//membname wildcard    //~v5jcR~
                                                                   //~v5jcI~
    rc=u3270dirlistsub(Ppuftph,0,&filectr,dsn2,0,&pudirlist0);     //~v5jcI~
    if (rc)                                                        //~v5jcI~
        return 4;                                                  //~v5jcI~
    for (ii=0,membctr=0,pudirlist=pudirlist0;ii<filectr;ii++,pudirlist++)//~v5jcI~
    {                                                              //~v5jcI~
        if (strcmp(pudirlist->name,".")                            //~v5jcI~
        &&  strcmp(pudirlist->name,".."))                          //~v5jcI~
        {                                                          //~v5jcI~
            pudirlistm=pudirlist;   //save member                  //~v5jcI~
            break;                                                 //~v5jcI~
        }                                                          //~v5jcI~
        membctr++;                                                 //~v5jcI~
    }                                                              //~v5jcI~
    if (filectr!=membctr+1) //not 1 entry                          //~v5jcI~
    {                                                              //~v5jcI~
//      ufree(pudirlist0);                                         //~v5jcI~//~v6qaR~
        UDIRLIST_FREE(pudirlist0);                                 //~v6qaI~
        return 2;                                                  //~v5jcI~
    }                                                              //~v5jcI~
	sprintf(Pfullpath,"%s:%s%s(%s)%s",Ppuftph->UFTPHhost,quotestr,dsn,pudirlist->name,quotestr);//~v5jcR~
    return 1;                                                      //~v5jcI~
}//u3270fullpathwildexp                                            //~v5jcI~
//*******************************************************
//*get file membername                                             //~v5j4R~
//*parm opt 1:fill dummy membername if not PDS and repl wildcard to '.'//~v5jcR~
//*return:length, =0 if no membername,-1:membname err              //~v5jdR~
//*******************************************************
int u3270getmembname(int Popt,char *Pfilename,char *Pmembname)     //~v5j4R~
{
    char *pc,*pc2;                                                 //~v5j4R~
    int len,ii;                                                    //~v5jcR~
//*********************************
    if (Popt & U3GM_DUMMYREP)                                      //~v5jdR~
    {                                                              //~v5j4I~
        strcpy(Pmembname,DUMMYMEMBER);   //if membername specified //~v5j4I~
        len=DUMMYMEMBERSZ;                                         //~v5j4I~
    }                                                              //~v5j4I~
    else                                                           //~v5j4I~
    {                                                              //~v5j4I~
        *Pmembname=0;                                              //~v5j4I~
        len=0;                                                     //~v5j4I~
    }                                                              //~v5j4I~
    pc=strchr(Pfilename,DSN_SEPCMEMB);                             //~v5j4R~
    if (pc && (pc2=strchr(pc,DSN_SEPCMEMB2)))                      //~v5j4R~
    {                                                              //~v5j4I~
    	pc++;                                                      //~v5j4I~
//    	len=(ULONG)pc2-(ULONG)pc;                                  //~v5j4I~//~v6hhR~
//  	len=(ULPTR)pc2-(ULPTR)pc;                                  //~v6hhI~//~v6D0R~
    	len=PTRDIFF(pc2,pc);                                       //~v6D0I~
        if (len>DSN_MAXMEMBERNAMELEN)                              //~v5j4R~
        {                                                          //~v5jdI~
			if (Popt & U3GM_RETLENERR)                             //~v5jdI~
            {                                                      //~v5jdI~
                strncpy(Pmembname,pc,DSN_MAXMEMBERNAMELEN);        //~v5jdI~
                *(Pmembname+DSN_MAXMEMBERNAMELEN)=0;               //~v5jdI~
            	return -1;                                         //~v5jdR~
            }                                                      //~v5jdI~
        	len=DSN_MAXMEMBERNAMELEN;                              //~v5j4R~
        }                                                          //~v5jdI~
        memcpy(Pmembname,pc,(UINT)len);                            //~v5j4I~
        *(Pmembname+len)=0;                                        //~v5j4I~
        if (Popt & U3GM_WILDREP)                                   //~v5jdI~
	        for (ii=len,pc=Pmembname;ii>0;ii--,pc++)               //~v5jcR~
    	        if (*pc=='*'||*pc=='?')                            //~v5jcI~
        	        *pc='@';                                       //~v5jdR~
    }                                                              //~v5j4I~
    return len;                                                    //~v5j4I~
}//u3270getmembname                                                //~v5j4R~
//*******************************************************          //~v5jdI~
//*get file membername                                             //~v5jdI~
//*parm opt 1:fill dummy membername if not PDS and repl wildcard to '.'//~v5jdI~
//*return:rc U3CR_RC_INVALIDNAME:err,1:valid as wildcard,0 valid   //~v5jdR~
//*******************************************************          //~v5jdI~
int u3270chkmembname(int Popt,char *Pmembname)                     //~v5jdR~
{                                                                  //~v5jdI~
	char *pc;                                                      //~v5jdI~
    int len,ch,wildsw=0;                                           //~v5jdR~
//*********************************                                //~v5jdI~
//  if ((len=strlen(Pmembname))>DSN_MAXMEMBERNAMELEN)              //~v5jdI~//~v6D0R~
    if ((len=(int)strlen(Pmembname))>DSN_MAXMEMBERNAMELEN)         //~v6D0I~
    	return U3CR_RC_INVALIDNAME;                                //~v5jdR~
    for (pc=Pmembname;*pc;pc++)                                    //~v5jdI~
    {	                                                           //~v5jdI~
    	ch=toupper(*pc);                                           //~v5jdI~
        if (ch>='A' && ch<='Z')                                    //~v5jdI~
        	continue;                                              //~v5jdI~
        if (ch>='0' && ch<='9' && pc!=Pmembname)                   //~v5jdR~
        	continue;                                              //~v5jdI~
        if (ch==DSN_WILD)                                          //~v5jdI~
        {                                                          //~v5jgI~
        	if (Popt & U3CM_CHKWILD)  //chk "*" as valid(return minus)//~v5jdI~
            {                                                      //~v5jdI~
            	wildsw=1;                                          //~v5jdI~
                continue;                                          //~v5jdI~
            }                                                      //~v5jdI~
            else                                                   //~v5jdI~
	        	return U3CR_RC_INVALIDNAME;                        //~v5jdI~
        }                                                          //~v5jgI~
        if (!strchr(Svalidname,ch))                                //~v5jdI~
        	return U3CR_RC_INVALIDNAME;                            //~v5jdR~
    }                                                              //~v5jdI~
    if (wildsw)                                                    //~v5jdI~
        return 1;                                                  //~v5jdI~
    return 0;                                                      //~v5jdI~
}//u3270chkmembname                                                //~v5jdI~
//*******************************************************          //~v5jcI~
//*get file membername or last path name                           //~v5jcR~
//*opt :not used                                                   //~v5jcI~
//*return:length                                                   //~v5jdR~
//*******************************************************          //~v5jcI~
int u3270getlastname(int Popt,char *Pfilename,char *Plastname)     //~v5jcI~
{                                                                  //~v5jcI~
    char *pc;                                                      //~v5jcI~
    int len;                                                       //~v5jcI~
//*********************************                                //~v5jcI~
	len=u3270pathlen(U3PL_PARENTORDROPMEMBER,Pfilename);	//last is "." or "(")//~v5jgR~
  if (!len)	//no parent                                            //~v5jgR~
    strcpy(Plastname,Pfilename);                                   //~v5jdR~
  else                                                             //~v5jdI~
    strcpy(Plastname,Pfilename+len);                               //~v5jcI~
    pc=Plastname+strlen(Plastname)-1;                              //~v5jcI~
    if (*pc==DSN_QUOTE)                                            //~v5jcI~
    	*pc--=0;                                                   //~v5jcI~
    if (*pc==DSN_SEPCMEMB2)                                        //~v5jcI~
    	*pc--=0;                                                   //~v5jcI~
//  return strlen(Plastname);                                      //~v5jcI~//~v6D0R~
    return (int)strlen(Plastname);                                 //~v6D0I~
}//u3270getlastname                                                //~v5jcI~
//*******************************************************          //~v5jgI~
//*get nth dsn level name                                          //~v5jgI~
//*return:length                                                   //~v5jgI~
//*******************************************************          //~v5jgI~
int u3270getnthname(char *Pfilename,int Plevel,char *Pnthname)     //~v5jgI~
{                                                                  //~v5jgI~
    char *pc,*pco;                                                 //~v5jgI~
    int len,level;                                                 //~v5jgR~
//*********************************                                //~v5jgI~
	*Pnthname=0;                                                   //~v5jgI~
	pco=pc=Pfilename;                                              //~v5jgI~
	for (level=0;;pc++)                                            //~v5jgR~
    	if (*pc==DSN_SEPC||*pc==DSN_SEPCMEMB||!*pc)                //~v5jgI~
        {	                                                       //~v5jgI~
        	level++;                                               //~v5jgI~
            if (level==Plevel)                                     //~v5jgI~
            	break;                                             //~v5jgI~
            pco=pc+1;                                              //~v5jgI~
        }                                                          //~v5jgI~
    if (level!=Plevel)                                             //~v5jgI~
    	return 0;                                                  //~v5jgI~
//  len=(ULONG)pc-(ULONG)pco;                                      //~v5jgI~//~v6hhR~
//  len=(ULPTR)pc-(ULPTR)pco;                                      //~v6hhI~//~v6D0R~
    len=PTRDIFF(pc,pco);                                           //~v6D0I~
//  memcpy(Pnthname,pco,len);                                      //~v5jgR~//~v6D0R~
    memcpy(Pnthname,pco,(size_t)len);                              //~v6D0I~
    *(Pnthname+len)=0;                                             //~v5jgI~
    return len;                                                    //~v5jgI~
}//u3270getnthname                                                 //~v5jgI~
//*******************************************************          //~v5jcI~
//*concat filename(wildcard is replaces if exist)                  //~v5jcI~
//*opt :1 force appendname is membername when not wildcard         //~v5jcI~
//*******************************************************          //~v5jcI~
int u3270concatfilename(int Popt,char *Psrc,char *Pappendname,char *Pout)//~v5jcI~
{                                                                  //~v5jcI~
    char *pc,*pmemb;                                               //~v5jcR~
    int len,quotesw,membsw=0;                                      //~v5jcI~
//*********************************                                //~v5jcI~
//  len=strlen(Psrc);                                              //~v5jcI~//~v6D0R~
    len=(int)strlen(Psrc);                                         //~v6D0I~
    if (Pout!=Psrc)                                                //~v5jcI~
//      memcpy(Pout,Psrc,len);                                     //~v5jcR~//~v6D0R~
        memcpy(Pout,Psrc,(size_t)len);                             //~v6D0I~
    if (!*Pappendname)                                             //~v5jcI~
    {                                                              //~v5jcI~
        *(Pout+len)=0;                                             //~v5jcI~
        return len;                                                //~v5jcI~
    }                                                              //~v5jcI~
    pc=Pout;                                                       //~v5jcI~
    quotesw=(*(pc+len-1)==DSN_QUOTE);                              //~v5jcI~
    if (quotesw)                                                   //~v5jcI~
        len--;                                                     //~v5jcI~
    if (Popt & U3CF_REPMEMBER && (pmemb=MEMBOFDSN(pc)))	//existing member replace req//~v5jcR~
    {                                                              //~v5jcI~
//    	len=(ULONG)pmemb-(ULONG)pc+1;                              //~v5jcR~//~v6hhR~
//  	len=(ULPTR)pmemb-(ULPTR)pc+1;                              //~v6hhI~//~v6D0R~
    	len=PTRDIFF(pmemb,pc)+1;                                   //~v6D0I~
        membsw=1;                                                  //~v5jcI~
    }                                                              //~v5jcI~
    else                                                           //~v5jcI~
    if (Popt & U3CF_REPLAST)                                       //~v5jdI~
    {                                                              //~v5jdI~
		len=u3270pathlen(U3PL_PARENT,pc);                          //~v5jdI~
    }                                                              //~v5jdI~
    else                                                           //~v5jdI~
    if (WILDCARD(pc))                                              //~v5jcI~
    {                                                              //~v5jcI~
        len=u3270pathlen(2,pc); 	//drop member or last path     //~v5jcI~
        if (len==0)  //err                                         //~v5jgR~
            return -1;                                             //~v5jcI~
        membsw=(*(pc+len-1)==DSN_SEPCMEMB);                        //~v5jcI~
    }                                                              //~v5jcI~
    else                                                           //~v5jcI~
    if (*Pappendname==DSN_SEPCMEMB)                                //~v5jcR~
        membsw=0;   //already enclosed by "()"                     //~v5jcI~
	else                                                           //~v5jcI~
    if (*(pc+len-1)!=FTP_REMOTEID)                                 //~v5jcI~
    {                                                              //~v5jcI~
    	if ((membsw=(Popt & U3CF_FORCEASMEMBERIFNOTWILD)))         //~v5jcR~
	        *(pc+len)=DSN_SEPCMEMB;                                //~v5jcI~
        else                                                       //~v5jcI~
	        *(pc+len)=DSN_SEPC;                                    //~v5jcI~
        len++;                                                     //~v5jcI~
    }                                                              //~v5jcI~
    pc+=len;                                                       //~v5jcI~
//  len=strlen(Pappendname);                                       //~v5jcI~//~v6D0R~
    len=(int)strlen(Pappendname);                                  //~v6D0I~
//  memcpy(pc,Pappendname,len);                                    //~v5jcI~//~v6D0R~
    memcpy(pc,Pappendname,(size_t)len);                            //~v6D0I~
    pmemb=pc;                                                      //~v5jcI~
    pc+=len;                                                       //~v5jcI~
    if (membsw)                                                    //~v5jcI~
    	*pc++=DSN_SEPCMEMB2;                                       //~v5jcI~
    if (quotesw)                                                   //~v5jcI~
    	*pc++=DSN_QUOTE;                                           //~v5jcI~
    *pc=0;                                                         //~v5jcI~
    strupr(pmemb);                                                 //~v5jcI~
//  return strlen(Pout);                                           //~v5jcI~//~v6D0R~
    return (int)strlen(Pout);                                      //~v6D0I~
}//u3270concatfilename                                             //~v5jcI~
//*******************************************************          //~v5jcI~
//*u3270editname                                                   //~v5jcI~
//*   covert last filename by patern(source may contain path)      //~v5jcI~
//*parm 1:puh of Psource or 0 if Psoource is local                 //~v5jdR~
//*parm 2:option:ON:wildcard is in source                          //~v5jdI~
//*parm 2:source pathname                                          //~v5jcI~
//*parm 3:patern pathname                                          //~v5jdR~
//*parm 4:out area addr                                            //~v5jcI~
//*       if patern is fullpath format output is of patern path,   //~v5jcI~
//        else patern path is concatinate to source path           //~v5jcI~
//*ret   :rc                                                       //~v5jdR~
//*******************************************************          //~v5jcI~
int u3270editname(PUFTPHOST Ppuftph,int Popt,UCHAR *Psource,UCHAR *Ppatern,UCHAR *Ptarget)//~v5jcR~
{                                                                  //~v5jcI~
    int opt,pathlen;                                               //~v5jdR~
    UCHAR wks[_MAX_PATH],wkp[_MAX_PATH],wkt[_MAX_PATH];            //~v5jdR~
    PUFTPHOST puftph;                                              //~v5jgI~
//*****************                                                //~v5jcI~
 if (Popt & U3EN_SRCLOCAL)	//source is LOCAL                      //~v5jdI~
 {                                                                 //~v5jdI~
    if ((pathlen=PATHLEN(Psource))<=0)                             //~v5jdR~
	    strcpy(wks,Psource);                                       //~v5jgI~
    else                                                           //~v5jgR~
	    strcpy(wks,Psource+pathlen);                               //~v5jgR~
    u3270getlastname(0,Ppatern,wkp);                               //~v5jdI~
  	if (Popt & U3EN_WILDSOURCE)	//src:wildcard,patern:source membername//~v5jdI~
    	udoseditname(0,wkp,wks,wkt);                               //~v5jdI~
  	else                                                           //~v5jdI~
    	udoseditname(0,wks,wkp,wkt);                               //~v5jdI~
    strcpy(Ptarget,Psource);                                       //~v5jdI~
    strcpy(Ptarget+pathlen,wkt);                                   //~v5jdI~
 }                                                                 //~v5jdI~
 else//source is local                                             //~v5jdI~
 {                                                                 //~v5jdI~
    u3270getlastname(0,Psource,wks);                               //~v5jdR~
    if (uftpisremote(Ppatern,&puftph) && UFTPHISTSO(puftph))       //~v5jgI~
    	u3270getlastname(0,Ppatern,wkp);                           //~v5jgR~
    else                                                           //~v5jgI~
    {                                                              //~v5jgI~
	    if ((pathlen=PATHLEN(Ppatern))<=0)                         //~v5jgI~
		    strcpy(wkp,Ppatern);                                   //~v5jgI~
	    else                                                       //~v5jgR~
	    	strcpy(wkp,Ppatern+pathlen);                           //~v5jgR~
    }                                                              //~v5jgI~
  if (Popt & U3EN_WILDSOURCE)	//src:wildcard,patern:source membername//~v5jdI~
    udoseditname(0,wkp,wks,wkt);                                   //~v5jdI~
  else                                                             //~v5jdI~
    udoseditname(0,wks,wkp,wkt);                                   //~v5jdR~
    if (MEMBOFDSN(Psource))                                        //~v5jdI~
    	opt=U3CF_REPMEMBER;                                        //~v5jdR~
    else                                                           //~v5jdI~
    	opt=U3CF_REPLAST;                                          //~v5jdI~
    u3270concatfilename(opt,Psource,wkt,Ptarget);                  //~v5jdI~
  }                                                                //~v5jdI~
    return 0;                                                      //~v5jcI~
}//u3270editname                                                   //~v5jcI~
//*******************************************************          //~v5jgI~
//*get dsn and lastname(member                                     //~v5jgI~
//*opt:same as u3270parentdsn                                      //~v5jgR~
//*ret 1:lastname is member,2:last name is wildcard,3:lastname is wildmemb//~v5jgI~
//*******************************************************          //~v5jgI~
int u3270parsedsn(int Popt,char *Psrc,char *Pdsn,char *Plastname)  //~v5jgI~
{                                                                  //~v5jgI~
	int rc;                                                        //~v5jgI~
//*********************************                                //~v5jgI~
	rc=MEMBOFDSN(Psrc)!=0;	                                       //~v5jgI~
	u3270getlastname(0,Psrc,Plastname);                            //~v5jgI~
    if (strchr(Plastname,DSN_WILD))                                //~v5jgI~
    	rc|=2;                                                     //~v5jgI~
	u3270parentdsn(U3PL_PARENTORDROPMEMBER|Popt,Psrc,Pdsn);        //~v5jgR~
    return rc;                                                     //~v5jgI~
}//u3270parsedsn                                                   //~v5jgI~
//*******************************************************          //~v5jcI~
//*get path dsname                                                 //~v5jcI~
//*******************************************************          //~v5jcI~
int u3270parentdsn(int Popt,char *Psrc,char *Pout)                 //~v5jcI~
{                                                                  //~v5jcI~
    char *pc;                                                      //~v5jcI~
    int len,quotesw;                                               //~v5jcI~
//*********************************                                //~v5jcI~
//  len=strlen(Psrc);                                              //~v5jcI~//~v6D0R~
    len=(int)strlen(Psrc);                                         //~v6D0I~
	if (Pout!=Psrc)                                                //~v5jcI~
//      memcpy(Pout,Psrc,len+1);                                   //~v5jcI~//~v6D0R~
        memcpy(Pout,Psrc,(size_t)len+1);                           //~v6D0I~
    pc=Pout;                                                       //~v5jcI~
    quotesw=(*(pc+len-1)==DSN_QUOTE);                              //~v5jcI~
	len=u3270pathlen(Popt & U3PD_PATHLENMASK,pc);                  //~v5jdR~
    if (len==0)                                                    //~v5jgR~
    	return len;                                                //~v5jcR~
    pc+=len-1;                                                     //~v5jcI~
    if (quotesw)                                                   //~v5jcI~
    	*pc++=DSN_QUOTE;                                           //~v5jcI~
    *pc=0;                                                         //~v5jcI~
    if (quotesw && Popt & U3PD_DROPQUOTE)                          //~v5jdI~
    {                                                              //~v5jdI~
    	*(pc-1)=0;                                                 //~v5jdI~
    	pc=strchr(Pout,DSN_QUOTE);                                 //~v5jdI~
        if (pc)                                                    //~v5jdI~
    	    strcpy(pc,pc+1);                                       //~v5jdI~
    }                                                              //~v5jdI~
    if (Popt & U3PD_DROPHOSTID)                                    //~v5jgI~
    {                                                              //~v5jgI~
    	pc=strchr(Pout,FTP_REMOTEID);                              //~v5jgI~
        if (pc)                                                    //~v5jgI~
    	    strcpy(Pout,pc+1);                                     //~v5jgR~
    }                                                              //~v5jgI~
//  return strlen(Pout);                                           //~v5jcI~//~v6D0R~
    return (int)strlen(Pout);                                      //~v6D0I~
}//u3270parentdsn                                                  //~v5jcI~
//*******************************************************          //~v5jdI~
//*get wildcard of dsn and replace by "*"                          //~v5jdI~
//*replace wildcard of dsn by parameter                            //~v5jgI~
//*input :wildcard if "" get wildcard,else replace wildcard by this parm//~v5jgI~
//*output:optional dsn                                             //~v5jgI~
//*       optional dsn level of wildcard part                      //~v5jgR~
//*rc:wildcard part length                                         //~v5jdI~
//*******************************************************          //~v5jdI~
int u3270getsetdsnwild(int Popt,char *Psrc,char *Pout,char *Pwild,int *Pplevel)//~v5jgR~
{                                                                  //~v5jdI~
	int lenw,lenp,level=1,setsw;                                   //~v5jgR~
	char *pco,*pcw,*pcp,*pcn,*pc;                                  //~v5jgR~
    char wk[DSN_MAXLEN];                                           //~v5jdI~
    char parmwild[DSN_MAXLEN];                                     //~v5jgI~
//*********************************                                //~v5jdI~
	setsw=Popt & U3DW_SET;                                         //~v5jgR~
    if (setsw)                                                     //~v5jgI~
    	strncpy(parmwild,Pwild,DSN_MAXLEN);                        //~v5jgI~
	pcw=strchr(Psrc,DSN_WILD);                                     //~v5jdI~
    if (!pcw)                                                      //~v5jdI~
    {                                                              //~v5jdI~
		*Pwild=0;                                                  //~v5jdI~
    	if (Pplevel)                                               //~v5jgI~
			*Pplevel=0;                                            //~v5jgI~
	    if (Pout)                                                  //~v5jgI~
    	    strcpy(Pout,Psrc);                                     //~v5jgR~
    	return 0;                                                  //~v5jdI~
    }                                                              //~v5jdI~
    pcn=strpbrk(pcw,".)'");	//next sepc                            //~v5jgR~
    if (!pcn)                                                      //~v5jdI~
    	pcn=pcw+strlen(pcw);                                       //~v5jdI~
//  lenp=(ULONG)pcw-(ULONG)Psrc;	//prev part                    //~v5jdR~//~v6hhR~
//  lenp=(ULPTR)pcw-(ULPTR)Psrc;	//prev part                    //~v6hhI~//~v6D0R~
    lenp=PTRDIFF(pcw,Psrc);	//prev part                            //~v6D0I~
    if (*pcn==DSN_SEPCMEMB2)                                       //~v5jgI~
//  	pcp=umemrchr(Psrc,DSN_SEPCMEMB,lenp);                      //~v5jgI~//~v6D0R~
    	pcp=umemrchr(Psrc,DSN_SEPCMEMB,(size_t)lenp);              //~v6D0I~
    else                                                           //~v5jgI~
//  	pcp=umemrchr(Psrc,DSN_SEPC,lenp);                          //~v5jgR~//~v6D0R~
    	pcp=umemrchr(Psrc,DSN_SEPC,(size_t)lenp);                  //~v6D0I~
    if (pcp)	//prev sepc                                        //~v5jdI~
    	pcp++;                                                     //~v5jdI~
    else                                                           //~v5jdI~
      if (*Psrc=='\'')                                             //~v5krI~
    	pcp=Psrc+1;                                                //~v5krI~
      else                                                         //~v5krI~
    	pcp=Psrc;                                                  //~v5jdI~
    pco=wk;                                                        //~v5jdR~
//  lenp=(ULONG)pcp-(ULONG)Psrc;                                   //~v5jdI~//~v6hhR~
//  lenp=(ULPTR)pcp-(ULPTR)Psrc;                                   //~v6hhI~//~v6D0R~
    lenp=PTRDIFF(pcp,Psrc);                                        //~v6D0I~
    if (lenp)                                                      //~v5jdI~
    {                                                              //~v5jdI~
    	if (Pplevel)                                               //~v5jgI~
	        for (pc=Psrc;pc<pcp;pc++)                              //~v5jgI~
	        	if (*pc==DSN_SEPC||*pc==DSN_SEPCMEMB)              //~v5jgR~
    	        	level++;                                       //~v5jgI~
//  	memcpy(pco,Psrc,lenp);                                     //~v5jdR~//~v6D0R~
    	memcpy(pco,Psrc,(size_t)lenp);                             //~v6D0I~
        pco+=lenp;                                                 //~v5jdR~
    }                                                              //~v5jdI~
//  lenw=(ULONG)pcn-(ULONG)pcp;                                    //~v5jdI~//~v6hhR~
//  lenw=(ULPTR)pcn-(ULPTR)pcp;                                    //~v6hhI~//~v6D0R~
    lenw=PTRDIFF(pcn,pcp);                                         //~v6D0I~
//  memcpy(Pwild,pcp,lenw);                                        //~v5jdI~//~v6D0R~
    memcpy(Pwild,pcp,(size_t)lenw);                                //~v6D0I~
    *(Pwild+lenw)=0;                                               //~v5jdI~
    if (setsw)                                                     //~v5jgI~
    {                                                              //~v5jgI~
	    strcpy(pco,parmwild);                                      //~v5jgI~
        pco+=strlen(parmwild);                                     //~v5jgI~
    }                                                              //~v5jgI~
    else                                                           //~v5jgI~
	    *pco++=DSN_WILD;                                           //~v5jgR~
    if (*pcn)                                                      //~v5jdI~
    	strcpy(pco,pcn);                                           //~v5jdR~
    else                                                           //~v5jgI~
        *pco=0;                                                    //~v5jgI~
    if (Pout)                                                      //~v5jgI~
	    strcpy(Pout,wk);                                           //~v5jgR~
    if (Pplevel)                                                   //~v5jgI~
    	*Pplevel=level;                                            //~v5jgI~
    return lenw;                                                   //~v5jdI~
}//u3270getsetdsnwild                                              //~v5jgR~
//*******************************************************          //~v5j4I~
//*u3270pathlen                                                    //~v5j4I~
//*parm 1:1:current dsnname(without member specification)          //~v5jcR~
//        0:parent path                                            //~v5jcI~
//        2:drop member if exist else parent                       //~v5jcI~
//*return:len(contain seperator "." or "("  or 0 if err            //~v5jgR~
//*******************************************************          //~v5j4I~
int u3270pathlen(int Psamedirsw,char *Pdsn)                        //~v5j4I~
{                                                                  //~v5j4I~
	char *pc;                                                      //~v5j4I~
    int len;                                                       //~v5j4I~
//********************************	                               //~v5j4I~
    pc=strchr(Pdsn,DSN_SEPCMEMB);   //search "("                   //~v5j4I~
    if (pc)                                                        //~v5j4I~
//  	len=((ULONG)pc-(ULONG)Pdsn)+1;     //up to before "("      //~v5jcR~//~v6hhR~
//    	len=((ULPTR)pc-(ULPTR)Pdsn)+1;     //up to before "("      //~v6hhI~//~v6D0R~
      	len=PTRDIFF(pc,Pdsn)+1;     //up to before "("             //~v6D0I~
    else                                                           //~v5j4I~
//    	len=strlen(Pdsn);                                          //~v5j4R~//~v6D0R~
      	len=(int)strlen(Pdsn);                                     //~v6D0I~
  if (Psamedirsw==U3PL_PARENTORDROPMEMBER)    //parent if no member specified//~v5jcR~
  {                                                                //~v5jcI~
    if (pc) //member specified                                     //~v5jcI~
    	return len;     //up to before "("                         //~v5jcI~
  }                                                                //~v5jcI~
  else                                                             //~v5jgI~
  if (Psamedirsw==U3PL_DROPWILDORMEMBER)    //parent if no member specified//~v5jgI~
  {                                                                //~v5jgI~
    if (pc) //member specified                                     //~v5jgI~
    	return len;     //up to before "("                         //~v5jgI~
  }                                                                //~v5jgI~
  else                                                             //~v5jcI~
  {                                                                //~v5jcI~
    if (Psamedirsw==U3PL_DROPMEMBER)                               //~v5jcR~
        return len;                                                //~v5j4I~
  }                                                                //~v5jcI~
    for (pc=Pdsn+len;--pc;)                                        //~v5jgR~
    {                                                              //~v5jgI~
    	if (pc<=Pdsn)                                              //~v5jgR~
        	return 0;                                              //~v5jgI~
        if (*pc==DSN_SEPC)          //"." found                    //~v5j4I~
            break;                                                 //~v5j4I~
    }                                                              //~v5jgI~
  	if (Psamedirsw==U3PL_DROPWILDORMEMBER)    //parent if no member specified//~v5jgI~
    	if (!strchr(pc,DSN_WILD))                                  //~v5jgI~
        	return len;                                            //~v5jgI~
//  return (int)((ULONG)pc-(ULONG)Pdsn+1);	//up to "."            //~v5j4I~//~v6hhR~
    return (int)((ULPTR)pc-(ULPTR)Pdsn+1);	//up to "."            //~v6hhI~
}//u3270pathlen                                                    //~v5j4I~
////*******************************************************        //~v5jcR~
////*u3270membsrch                                                 //~v5jcR~
////*search member in member list                                  //~v5jcR~
////*return:rc 0 found                                             //~v5jcR~
////*******************************************************        //~v5jcR~
//int u3270membsrch(PPDSMEMBLIST Pppml,char *Ppmember)             //~v5jcR~
//{                                                                //~v5jcR~
//    int len,ii;                                                  //~v5jcR~
////********************************                               //~v5jcR~
//    len=ustrnlen(Ppmember,DSN_MAXMEMBERNAMELEN)+1;               //~v5jcR~
//    for (ii=0;ii<Pppml->PMLhdr.PRDcount;ii++)                    //~v5jcR~
//    {                                                            //~v5jcR~
//        if (!memicmp(Pppml->PMLmember[ii],Ppmember,len))         //~v5jcR~
//            return 0;                                            //~v5jcR~
//    }                                                            //~v5jcR~
//    return 4;                                                    //~v5jcR~
//}//u3270membsrch                                                 //~v5jcR~
//**************************************************************** //~v5j4I~
//* set cmd string hdr:hostid,uid,pswd                             //~v5j4R~
//* return stringlen                                               //~v5j4I~
//**************************************************************** //~v5j4I~
int u3270sethostuser(PUFTPHOST Ppuftph,char *Ppcmdverb,char *Ppcmdstr)//~v5j4I~
{                                                                  //~v5j4I~
    char pswd[FTP_PSWDNAMELEN+2];                                  //~v5j4I~
//********************                                             //~v5j4I~
    if (*Ppuftph->UFTPHpswd)                                       //~v5j4R~
    {                                                              //~v5j4I~
        *pswd='/';                                                 //~v5j4I~
        uftphostscrypt(1,Ppuftph->UFTPHpswd,pswd+1);               //~v5j4I~
    }                                                              //~v5j4I~
    else                                                           //~v5j4I~
        *pswd=0;                                                   //~v5j4I~
//  return sprintf(Ppcmdstr,"%s %s:%d %s%s",                       //~v5mxR~
    return sprintf(Ppcmdstr,"%s %s:%d(%s) %s%s",                   //~v5mxI~
                        Ppcmdverb,                                 //~v5j4I~
                        Ppuftph->UFTPHipad,  //hostname            //~v5j4I~
                        Ppuftph->UFTPHport,  //portno              //~v5j4I~
        			    Ppuftph->UFTPHhost,	//hostname             //~v5mxI~
                        Ppuftph->UFTPHuser,  //username            //~v5j4I~
                        pswd);              //password             //~v5j4I~
}//u3270sethostuser                                                //~v5j4I~
//**************************************************************** //~v5j4M~
//* send request using named pipe                                  //~v5j4M~
//**************************************************************** //~v5j4M~
int u3270cmdrequest(int Popt,char *Pcmd,void **Pppvoid,int *Ppdatalen)//~v5j4R~
{                                                                  //~v5j4M~
#if defined(W32) || defined(LNX)                                   //~v63aI~
    int rc,readlen;                                                //~v5j4R~
#ifdef LNX                                                         //~v5j4M~
//  ULONG hpipe[2];     //write and read                           //~v5j4M~//~v6hhR~
    ULPTR hpipe[2];                                                //~v6hhI~
#else                                                              //~v5j4M~
//  ULONG hpipe[1];                                                //~v5j4M~//~v6hhR~
    ULPTR hpipe[1];                                                //~v6hhI~
#endif                                                             //~v5j4M~
    char respbuff[MAX_RESPSZ];                                     //~v5j4M~
    char respbuff2[MAX_RESPSZ];                                    //~v5j4M~
    PPIPERESPMSG prespmsg;                                         //~v5j4R~
    char **ppdata;                                                 //~v5j4I~
    int opt=0;                                                     //~v5maI~
    ULPTR ulp;                                                     //~v6r0I~
//*****************                                                //~v5j4M~
    if (Pppvoid)                                                   //~v5j4I~
		*Pppvoid=0;                                                //~v5j4R~
    if (Snopmode)	//nop mode                                     //~v5j4I~
    {                                                              //~v5j4M~
    	uerrmsg("FTP is NOP by option or xehosts file err",0);     //~v5j4M~
    	return 16;                                                 //~v5j4M~
    }                                                              //~v5j4M~
    IFDEF_WINCON(opt|=UPROC_KEEPMODE);                             //~v5maI~
//  if (uprocconnect(0,Sserverstartcmd,Spipename,hpipe))           //~v5maR~
    if (uprocconnect(opt,Sserverstartcmd,Spipename,hpipe))         //~v5maI~
    	return 4;                                                  //~v5j4M~
//  ppdata=(char**)(ULONG)Pppvoid;                                 //~v5j4R~//~v6hhR~
    ppdata=(char**)(ULPTR)Pppvoid;                                 //~v6hhI~
    rc=uprocpipeio(hpipe,Spipename,Pcmd,respbuff,sizeof(respbuff),&readlen,ppdata,Ppdatalen);//~v5j4R~
    if (!rc && readlen)                                            //~v5j4M~
    {                                                              //~v5j4M~
    	                                                           //~v5j4I~
//		prespmsg=(PPIPERESPMSG)(ULONG)respbuff;                    //~v5j4R~//~v6hhR~
//		prespmsg=(PPIPERESPMSG)(ULPTR)respbuff;                    //~v6hhI~//~v6r0R~
		ulp=(ULPTR)respbuff;                                       //~v6r0I~
		prespmsg=(PPIPERESPMSG)ulp;                                //~v6r0I~
        rc=prespmsg->rc;                                           //~v5j4I~
//      if (rc && readlen)	//msglen                               //~v5jAR~
        if (readlen 	//msglen                                   //~v5jAI~
        &&  (rc || (Popt & U3CRO_UERRMSG)))// err or err even if no err//~v5jAI~
        {                                                          //~v5jcI~
			u3270editrespmsg(prespmsg->respmsg,respbuff2,sizeof(respbuff2));//~v5jcR~
        	if (Popt & U3CRO_UERRMSG                               //~v5jdR~
//      	|| (Popt & U3CRO_UERRMSGIFERR && rc!=U3CR_RC_NOTFOUND && rc!=U3CR_RC_PATHERR && rc!=U3CR_RC_DUPNAME))//~v5jAR~
        	|| (Popt & U3CRO_UERRMSGIFERR && rc!=U3CR_RC_NOTFOUND && rc!=U3CR_RC_DUPNAME))//~v5jAR~
		    	uerrmsg("%s",0,                                    //~v5jcR~
						respbuff2); 	//protect % conversion     //~v5jcR~
        }                                                          //~v5jcI~
        if (rc&U3CR_RC_WARNING)                                    //~v5jAR~
        {                                                          //~v5jAI~
            ubell();                                               //~v5jAI~
            ubell();                                               //~v5jAI~
        	rc=0;                                                  //~v5jAI~
        }                                                          //~v5jAI~
    }                                                              //~v5j4M~
    uprocdisconnect(hpipe,Spipename);                              //~v5j4I~
    return rc;                                                     //~v5j4M~
#else                                                              //~v63aI~
    return 4;   //supported WIN and LNX only                       //~v63aI~
#endif                                                             //~v63aI~
}//cmdrequest                                                      //~v5j4M~
//**************************************************************** //~v5j4M~
//*drop crlf and eol space                                         //~v5j4M~
//**************************************************************** //~v5j4M~
int u3270editrespmsg(char *Pin,char *Pout,int Poutbuffsz)          //~v5j4I~
{                                                                  //~v5j4M~
	char *pc,*pc2,*pce;                                            //~v5j4M~
//********************************                                 //~v5j4M~
    pc=Pout;                                                       //~v5j4M~
    pce=Pout+Poutbuffsz-1;                                         //~v5j4M~
//drop space of end of line                                        //~v5j4M~
    pc2=Pin;                                                       //~v5j4M~
    for (;*pc2;)                                                   //~v5j4M~
    {                                                              //~v5j4M~
        if (pc>pce)                                                //~v5j4M~
            break;                                                 //~v5j4M~
        if (*pc2=='\n')                                            //~v5j4M~
        {                                                          //~v5j4M~
            pc--;                                                  //~v5j4M~
            while(*pc==' ')                                        //~v5j4M~
                pc--;                                              //~v5j4M~
            pc++;                                                  //~v5j4M~
            *pc++=';';                                             //~v5j4M~
            pc2++;                                                 //~v5j4M~
        }                                                          //~v5j4M~
        else                                                       //~v5j4M~
            *pc++=*pc2++;                                          //~v5j4M~
    }                                                              //~v5j4M~
    *pc=0;                                                         //~v5j4M~
//  return strlen(Pout);                                           //~v5j4M~//~v6D0R~
    return (int)strlen(Pout);                                      //~v6D0I~
}//u3270editrespmsg                                                //~v5j4I~
//**********************************************************************//~v5j4R~
// return :r.c                                                     //~v5j4R~
//**********************************************************************//~v5j4R~
int u3270dirlistsub(PUFTPHOST Ppuftph,int Popt,int *Ppentno,char *Pfpath,ULONG Pattr,PUDIRLIST *Pppudl)//~v5j4R~
{                                                                  //~v5j4R~
    int rc,datalen,/*wildlen,*/level=0;                                  //~v5jgR~//~v6b9R~//~v6h7R~
    char cmd[MAX_CMDSZ],*pc,*pmemb,*phostfile,*pc2;                //~v5jdR~
    PPDSMEMBLIST ppml=0;                                           //~v5jcR~
    PDSNLIST     pdsnl=0;                                          //~v5jcI~
    PPIPERESPDATA phdr;                                            //~v5jcI~
    char dsnwild[DSN_MAXLEN];                                      //~v5jdI~
//*******************************************:                     //~v5j4R~
    phostfile=Pfpath+Ppuftph->UFTPHhostnmlen+1;                    //~v5jcR~
    pc=cmd+u3270sethostuser(Ppuftph,"listds",cmd);                 //~v5j4R~
    *pc++=' ';                                                     //~v5jbI~
    strcpy(pc,phostfile);                                          //~v5jcI~
    pmemb=MEMBOFDSN(pc);                                           //~v5jbR~
    if (pmemb)	//membname spacified                               //~v5jbI~
    {                                                              //~v5jbI~
    	if (*pc==DSN_QUOTE)                                        //~v5jbI~
	        *pmemb++=DSN_QUOTE;	//drop wildcard                    //~v5jbI~
	 	*pmemb=0;                                                  //~v5jbI~
    }                                                              //~v5jbI~
    if (!(pc2=strchr(pc,'*')))		//path wild card               //~v5jdR~
	    strcat(pc," MEMBERS");                                     //~v5jcR~
    else            //path wildcard                                //~v5jdI~
    {                                                              //~v5jdI~
        if (pmemb)                                                 //~v5jdI~
        {                                                          //~v5jdI~
            uerrmsg("invalid wildcard(Wildcard DSN and MEMBER)",0);//~v5jdI~
            return U3CR_RC_OTHER;                                  //~v5jdI~
        }                                                          //~v5jdI~
		/*wildlen=*/u3270getsetdsnwild(U3DW_GET,pc,pc,dsnwild,&level); //~v5jgR~//~v6b9R~
    }                                                              //~v5jdI~
//  rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULONG)(&phdr),&datalen);//~v5jcR~//~v6hhR~
    rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULPTR)(&phdr),&datalen);//~v6hhI~
    if (phdr)                                                      //~v5jcI~
    {                                                              //~v5jcI~
        if (phdr->PRDtype==PRDT_MEMBL)  //response data is memberlist(dsn contains member specification)//~v5jcI~
//          ppml=(PPDSMEMBLIST)(ULONG)phdr;                        //~v5jcI~//~v6hhR~
            ppml=(PPDSMEMBLIST)(ULPTR)phdr;                        //~v6hhI~
        else                                                       //~v5jcI~
//          pdsnl=(PDSNLIST)(ULONG)phdr;                           //~v5jcI~//~v6hhR~
            pdsnl=(PDSNLIST)(ULPTR)phdr;                           //~v6hhI~
    }                                                              //~v5jcI~
    if (!rc)                                                       //~v5jcR~
    {                                                              //~v5j4R~
        if (ppml)   //DSORG=PS                                     //~v5j4R~
            rc=u3270setdirlist(ppml,phostfile,Ppentno,Pppudl);     //~v5jcR~
        else                                                       //~v5j4R~
        if (pdsnl)                                                 //~v5jcI~
            rc=u3270setdirlistdsn(level,dsnwild,pdsnl,phostfile,Ppentno,Pppudl);//~v5jgR~
        else                                                       //~v5jcI~
            rc=U3CR_RC_NOTFOUND;                                   //~v5jcR~
    }                                                              //~v5j4R~
    if (rc==U3CR_RC_NOTFOUND)                                      //~v5jgI~
        if (!(Popt & FTP_DLSNONFMSG)) 	//hdir id  for FTP         //~v5jgI~
            ufilenotfound(Pfpath,rc);                              //~v5jgI~
    if (phdr)   //DSORG=PS                                         //~v5jcR~
        ufree(phdr);                                               //~v5jcR~
    return rc;                                                     //~v5j4R~
}//u3270ditlistsub                                                 //~v5j4R~
//**********************************************************************//~v5j4R~
// set dirlist of PDS member                                       //~v5jcR~
//**********************************************************************//~v5j4R~
int u3270setdirlist(PPDSMEMBLIST Pppml,char *Pfpath,int *Ppentno,PUDIRLIST *Pppudl)//~v5j4R~
{                                                                  //~v5j4R~
    PUDIRLIST pudl,pudl0;                                          //~v5j4R~
    PDSNDATA pdsnd;                                                //~v5jcI~
    PPDSSPFINFO pspfi;                                             //~v5jvI~
    ULONG attr;                                                    //~v5jcI~
    int entno,membnamelen,wildsw,ii,lrecl;                         //~v5jcR~
    char membname[DSN_MAXMEMBERNAMELEN+1],*pc;                     //~v5j4R~
//*******************************************:                     //~v5j4R~
    UTRACED("pdsmemberlist",Pppml,Pppml->PMLhdr.PRDlen);           //~v5jcR~
    membnamelen=u3270getmembname(0,Pfpath,membname);//0:no dummy set//~v5j4R~
    if (membnamelen)                                               //~v5j4R~
    {                                                              //~v5j4R~
        wildsw=WILDCARD(membname)!=0;                              //~v5j4R~
//      for (entno=0,ii=Pppml->PMLhdr.PRDcount,pc=Pppml->PMLmember[0];ii>0;ii--,pc+=PMLMEMBNAMEFLDSZ)//~v5jvR~
        for (entno=0,ii=Pppml->PMLhdr.PRDcount,pspfi=Pppml->PMLmember;ii>0;ii--,pspfi++)//~v5jvI~
        {                                                          //~v5j4R~
        	pc=pspfi->SPFImember;                                  //~v5jvI~
            if (wildsw)                                            //~v5j4R~
            {                                                      //~v5j4R~
                if (ufilewildcomp(UFWC_0BYTE,pc,membname,0))//0:mmdossw; not match//~v5j4R~
                {                                                  //~v5j4R~
                    *pc=0;                                         //~v5j4R~
                    continue;                                      //~v5j4R~
                }                                                  //~v5j4R~
            }                                                      //~v5j4R~
            else                                                   //~v5j4R~
                if (stricmp(pc,membname))//unmatch                 //~v5j4R~
                {                                                  //~v5j4R~
                    *pc=0;                                         //~v5j4R~
                    continue;                                      //~v5j4R~
                }                                                  //~v5j4R~
            entno++;                                               //~v5j4R~
        }                                                          //~v5j4R~
    }                                                              //~v5j4R~
    else                                                           //~v5j4R~
        entno=Pppml->PMLhdr.PRDcount+2;	//add "."(cur dir entry) like as FindFirst//~v5jbR~
//  pudl0=ucalloc(1,(UINT)((entno+1)*UDIRLISTSZ));                 //~v5j4R~//~v6D0R~
    pudl0=ucalloc(1,((size_t)entno+1)*UDIRLISTSZ);                 //~v6D0I~
    UALLOCCHK(pudl0,UALLOC_FAILED);                                //~v5j4R~
    *Ppentno=entno;                                                //~v5j4R~
    *Pppudl=pudl0;                                                 //~v5j4R~
	pudl=pudl0;                                                    //~v5jbI~
    pdsnd=&Pppml->PMLdsnd;                                         //~v5jcI~
    u3270setattr(pdsnd->DSDflag,&attr);                            //~v5jcR~
//  attr&=~FILE_DIRECTORY;                                         //~v5jcI~//~v6D0R~
    attr&=~(ULONG)FILE_DIRECTORY;                                  //~v6D0I~
    if (attr & FILE_PO                                             //~v5jyI~
    &&  attr & FILE_RECFMF                                         //~v5jyI~
	&&  pdsnd->DSDlrecl==80)                                       //~v5jyR~
    	attr|=FILE_SPFDS;   //may contain spf info                 //~v5jyI~
    lrecl=pdsnd->DSDlrecl<<16|pdsnd->DSDblksize;	//LRECL & BLKSZ//~v5jcR~
    if (!membnamelen)                                              //~v5jbI~
    {                                                              //~v5jbI~
//  	strcpy(pudl->name,"..");                                   //~v5jbR~//~v6J0R~
    	udirlist_setname(0,pudl,"..",0/*use strlen*/);             //~v6J0I~
        pudl->attr=attr|FILE_DSNPATH;                              //~v5jcR~
//      pudl->attr&=~FILE_SPFDS;	//path entry                   //~v5jyR~//~v6D0R~
        pudl->attr&=~(ULONG)FILE_SPFDS;	//path entry               //~v6D0I~
        pudl++;                                                    //~v5jbR~
//  	strcpy(pudl->name,".");                                    //~v5jbI~//~v6J0R~
    	udirlist_setname(0,pudl,".",0/*use strlen*/);              //~v6J0I~
        pudl->attr=attr|FILE_DIRECTORY;                            //~v5jcR~
//      pudl->srcattr=lrecl;                                       //~v5jcI~//~v6D0R~
        pudl->srcattr=(ULONG)lrecl;                                //~v6D0I~
        pudl++;                                                    //~v5jbI~
    }                                                              //~v5jbI~
    attr|=FILE_PDSMEMB;                                            //~v5jcI~
//  for (ii=Pppml->PMLhdr.PRDcount,pc=Pppml->PMLmember[0];ii>0;ii--,pc+=PMLMEMBNAMEFLDSZ)//~v5jvR~
    for (ii=Pppml->PMLhdr.PRDcount,pspfi=Pppml->PMLmember;ii>0;ii--,pspfi++)//~v5jvI~
    {                                                              //~v5j4R~
        pc=pspfi->SPFImember;                                      //~v5jvI~
        if (!*pc)                                                  //~v5j4R~
            continue;                                              //~v5j4R~
//      strcpy(pudl->name,pc);                                     //~v5j4R~//~v6J0R~
        udirlist_setname(0,pudl,pc,0/*use strlen*/);               //~v6J0I~
        pudl->slinkfdate=                                          //~v5jvI~
        pudl->date=pspfi->SPFIudate;                               //~v5jvI~
        pudl->slinkftime=                                          //~v5jvI~
        pudl->time=pspfi->SPFIutime;                               //~v5jvI~
        pudl->size=pspfi->SPFIlinecnt*pdsnd->DSDlrecl;             //~v5jvR~
        pudl->slinksize=pspfi->SPFIlinecnt;                        //~v5jvI~
        strcpy(pudl->uname,pspfi->SPFIuserid);  //borrow the field //~v5jvR~
        pudl->attr=attr;                                           //~v5jcR~
//      pudl->srcattr=lrecl;                                       //~v5jcI~//~v6D0R~
        pudl->srcattr=(ULONG)lrecl;                                //~v6D0I~
        TSO_SETINITLINE(pudl,pspfi->SPFIinitcnt);                  //~v5jyR~
        TSO_SETVV(pudl,pspfi->SPFIver);                            //~v5jyR~
        TSO_SETMM(pudl,pspfi->SPFImod);                            //~v5jyR~
        TSO_SETCDATE(pudl,pspfi->SPFIcdate);                       //~v5jyR~
        if (pspfi->SPFIflag & SPFIFALIAS)                          //~v5jvR~
	        pudl->attr|=FILE_ALIAS|FILE_SPECIAL;                   //~v5jvI~
        if (pspfi->SPFIflag & SPFIFSPF)                            //~v5jvR~
	        pudl->attr|=FILE_SPF;                                  //~v5jvI~
        pudl++;                                                    //~v5j4R~
    }                                                              //~v5j4R~
    return 0;                                                      //~v5j4R~
}//u3270setdirlist                                                 //~v5j4R~
//**********************************************************************//~v5jdI~
// search pudl member                                              //~v5jdI~
//**********************************************************************//~v5jdI~
PUDIRLIST u3270srchdirlist(int Popt,int Pentno,PUDIRLIST Ppudl,char *Pmember)//~v5jdI~
{                                                                  //~v5jdI~
    PUDIRLIST pudl;                                                //~v5jdI~
    int ii;                                                        //~v5jdI~
//*******************************************:                     //~v5jdI~
    for (pudl=Ppudl,ii=0;ii<Pentno;pudl++,ii++)                    //~v5jdR~
    {                                                              //~v5jdI~
        if (Popt & U3SD_WILD)                                      //~v5jdR~
        {                                                          //~v5jdI~
            if (!ufilewildcomp(UFWC_0BYTE,pudl->name,Pmember,0))//0:mmdossw; not match//~v5jdR~
            	return pudl;                                       //~v5jdI~
        }                                                          //~v5jdI~
        else                                                       //~v5jdI~
            if (!stricmp(pudl->name,Pmember))//match               //~v5jdR~
            	return pudl;                                       //~v5jdI~
    }                                                              //~v5jdI~
    return 0;                                                      //~v5jdI~
}//u3270srchdirlist                                                //~v5jdI~
//**********************************************************************//~v5jcI~
// set dirlist from DSN list(wildcard DSN)                         //~v5jcI~
//**********************************************************************//~v5jcI~
int u3270setdirlistdsn(int Plevel,char *Pwild,PDSNLIST Ppdsnl,char *Phostfile,int *Ppentno,PUDIRLIST *Pppudl)//~v5jgR~
{                                                                  //~v5jcI~
    PUDIRLIST pudl,pudl0;                                          //~v5jcI~
    PDSNDATA pdsnd;                                                //~v5jcI~
    ULONG attr;                                                    //~v5jcI~
    int entno,ii,selectctr,wildlen;                                //~v5jgR~
//*******************************************:                     //~v5jcI~
    UTRACED("dsnlist",Ppdsnl,Ppdsnl->DSLhdr.PRDlen);               //~v5jcR~
//  wildlen=strlen(Pwild);                                         //~v5jgI~//~v6D0R~
    wildlen=(int)strlen(Pwild);                                    //~v6D0I~
    entno=Ppdsnl->DSLhdr.PRDcount;                                 //~v5jcR~
    if (!wildlen)   //no wildcard specified                        //~v5jgR~
    	entno+=2;   //add entry for ".." and "." like as windows uddirlist//~v5jgR~
//  pudl0=ucalloc(1,(UINT)((entno+1)*UDIRLISTSZ));                 //~v5jcI~//~v6D0R~
    pudl0=ucalloc(1,((size_t)entno+1)*UDIRLISTSZ);                 //~v6D0I~
    UALLOCCHK(pudl0,UALLOC_FAILED);                                //~v5jcI~
    *Ppentno=entno;                                                //~v5jcI~
    *Pppudl=pudl0;                                                 //~v5jcI~
	pudl=pudl0;                                                    //~v5jcI~
    if (!wildlen)	//not wildcard                                 //~v5jgR~
    {                                                              //~v5jcR~
//      strcpy(pudl->name,"..");                                   //~v5jcR~//~v6J0R~
    	udirlist_setname(0,pudl,"..",0/*use strlen*/);             //~v6J0I~
        pudl->attr=FILE_DSNPATH;                                   //~v5jcR~
        pudl++;                                                    //~v5jcR~
                                                                   //~v5jcR~
//      strcpy(pudl->name,".");                                    //~v5jcR~//~v6J0R~
    	udirlist_setname(0,pudl,".",0/*use strlen*/);              //~v6J0I~
        pudl->attr=FILE_DSNPATH;                                   //~v5jcR~
        pudl++;                                                    //~v5jcR~
        entno-=2;                                                  //~v5jcI~
    }                                                              //~v5jcR~
    for (ii=entno,selectctr=0,pdsnd=Ppdsnl->DSLentry;ii>0;ii--,pdsnd++)//~v5jdR~
    {                                                              //~v5jcI~
//      u3270getnthname(pdsnd->DSDdsn,Plevel,pudl->name);          //~v5jgI~//~v6J0R~
	 	{                                                          //~v6J0I~
			UDIRLIST_NAMECOPY2WK(pudl,wkudlname);                  //+v6J0R~
			u3270getnthname(pdsnd->DSDdsn,Plevel,wkudlname);       //~v6J0I~
        	udirlist_setname(0,pudl,wkudlname,0);	//@@@@FIXME test//~v6J0I~
        }                                                          //~v6J0I~
		if (wildlen>1)	//except "*"                               //~v5jgR~
        {                                                          //~v5jdI~
        	if (ufilewildcomp(UFWC_0BYTE,pudl->name,Pwild,0))//0:mmdossw; not match//~v5jgR~
                    continue;                                      //~v5jdI~
        }                                                          //~v5jdI~
        u3270setattr(pdsnd->DSDflag,&attr);                        //~v5jcI~
        pudl->attr=attr;                                           //~v5jcI~
//      pudl->srcattr=pdsnd->DSDlrecl<<16|pdsnd->DSDblksize;    //LRECL & BLKSZ//~v5jcI~//~v6D0R~
        pudl->srcattr=((ULONG)pdsnd->DSDlrecl<<16)|(ULONG)(pdsnd->DSDblksize);    //LRECL & BLKSZ//~v6D0R~
    	pudl++;                                                    //~v5jdI~
        selectctr++;                                               //~v5jdI~
    }                                                              //~v5jcI~
	if (wildlen>1)                                                 //~v5jgR~
	    *Ppentno=selectctr;                                        //~v5jdI~
    return 0;                                                      //~v5jcI~
}//u3270setdirlistdsn                                              //~v5jcR~
//**********************************************************************//~v5jcI~
// return :r.c                                                     //~v5jcI~
//**********************************************************************//~v5jcI~
void u3270setattr(int Precfm,ULONG *Ppattr)                        //~v5jcI~
{                                                                  //~v5jcI~
	ULONG attr;                                                    //~v5jcI~
//*******************************************:                     //~v5jcI~
	attr=FILE_REMOTE|FILE_TSO;                                     //~v5jcI~
    if (Precfm & DSDFPO)        //DSORG=PO                         //~v5jcI~
    {                                                              //~v5jcI~
    	attr|=FILE_PO;                                             //~v5jcI~
    	if (!(Precfm & DSDFMEMB)) //not member                     //~v5jcI~
	    	attr|=FILE_DIRECTORY;                                  //~v5jcI~
    }                                                              //~v5jcI~
    if (Precfm & DSDFPS)        //DSORG=PS                         //~v5jcI~
    	attr|=FILE_PS;                                             //~v5jcI~
    if (Precfm & DSDFF)         //RECFM=F                          //~v5jcI~
    	attr|=FILE_RECFMF;                                         //~v5jcI~
    if (Precfm & DSDFV)         //RECFM=V                          //~v5jcI~
    	attr|=FILE_RECFMV;                                         //~v5jcI~
    if (Precfm & DSDFB)         //RECFM=B                          //~v5jcI~
    	attr|=FILE_RECFMB;                                         //~v5jcI~
    if (Precfm & DSDFMEMB)      //fstat specified membername and that found//~v5jcI~
    	attr|=FILE_PDSMEMB;                                        //~v5jcI~
    if (Precfm & DSDFVS)        //VSAM etc                         //~v5juI~
    	attr|=FILE_SPECIAL;                                        //~v5juI~
    *Ppattr=attr;                                                  //~v5jcI~
    return;                                                        //~v5jcI~
}//u3270setattr                                                    //~v5jcI~
//**********************************************************************//~v5jcI~
// set attr acronym for TSO file                                   //~v5jcR~
// parm2:string contains initcnt/vv/mm/creation date               //~v5jyI~
//**********************************************************************//~v5jcI~
//void u3270getattrstr(ULONG Pattr,char *Pattrstr)                 //~v5jyR~
void u3270getattrstr(ULONG Pattr,char *Pgname,char *Pattrstr)      //~v5jyI~
{                                                                  //~v5jcI~
	char *pc;                                                      //~v5jcI~
    char vv,mm;                                                    //~v5jyI~
//*******************************************:                     //~v5jcI~
	pc=Pattrstr;                                                   //~v5jcI~
    if (Pattr & FILE_SPECIAL)                 //VSAM               //~v5juI~
    {                                                              //~v5juI~
      if (Pattr & FILE_ALIAS)                 //VSAM               //~v5jvI~
    	strcpy(pc,"ALIS");                                         //~v5jvI~
      else                                                         //~v5jvI~
    	strcpy(pc,"????");                                         //~v5juI~
        return;                                                    //~v5juI~
    }                                                              //~v5juI~
    if (Pattr & (FILE_DSNPATH|FILE_PDSMEMB))   //path entry or PDS member//~v5jcR~
    {                                                              //~v5jcI~
      if (Pattr & (FILE_SPF))   //SPF information gotten           //~v5jyI~
      {                                                            //~v5jyI~
      	vv=TSOGN_GETVV(Pgname);                                    //~v5jyR~
      	mm=TSOGN_GETMM(Pgname);                                    //~v5jyR~
        vv=vv%100;                                                 //~v5jyI~
        mm=mm%100;                                                 //~v5jyI~
        sprintf(pc,"%02d%02d",vv,mm);                              //~v5jyI~
      }                                                            //~v5jyI~
      else                                                         //~v5jyI~
    	strcpy(pc,"----");                                         //~v5jcI~
        return;                                                    //~v5jcI~
    }                                                              //~v5jcI~
    if (Pattr & FILE_PO)                                           //~v5jcR~
    	*pc++='P',*pc++='O';                                       //~v5jcI~
    else                                                           //~v5jcI~
    if (Pattr & FILE_PS)                                           //~v5jcR~
    	*pc++='P',*pc++='S';                                       //~v5jcI~
    else                                                           //~v5jcI~
    	*pc++='-',*pc++='-';                                       //~v5jcI~
                                                                   //~v5jcI~
    if (Pattr & FILE_RECFMF)                                       //~v5jcR~
    	*pc++='F';                                                 //~v5jcI~
    else                                                           //~v5jcI~
    if (Pattr & FILE_RECFMV)                                       //~v5jcR~
    	*pc++='V';                                                 //~v5jcI~
    else                                                           //~v5jcI~
    	*pc++='U';                                                 //~v5jcI~
                                                                   //~v5jcI~
    if (Pattr & FILE_RECFMB)                                       //~v5jcR~
    	*pc++='B';                                                 //~v5jcI~
    else                                                           //~v5jcI~
    	*pc++='-';                                                 //~v5jcI~
    *pc=0;                                                         //~v5jcI~
    return;                                                        //~v5jcI~
}//u3270getattrstr                                                 //~v5jyR~
//**************************************************************** //~v5jcI~
//u3270errdsnpath                                                  //~v5jcI~
//dsn path is not processed                                        //~v5jcI~
//*rc    :4                                                        //~v5jcI~
//**************************************************************** //~v5jcI~
int u3270errdsnpath(char *Pdsn)                                    //~v5jcI~
{                                                                  //~v5jcI~
	uerrmsg("%s is PATH name,is not processed",                    //~v5jcI~
    		"%s ÇÕ DSN ÇÃàÍïîÇ≈Ç∑ÅAèàóùÇ≈Ç´Ç‹ÇπÇÒ",                //~v5jcI~
            	Pdsn);                                             //~v5jcI~
    return 4;                                                      //~v5jcI~
}//u3270errdsnpath                                                 //~v5jcI~
