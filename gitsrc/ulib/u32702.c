//*CID://+v6G3R~:                             update#=  546;       //~v6G3R~
//*************************************************************
//*u3270.c   :3270 FTP version
//*************************************************************
//v6G3:161212 (Win10) missing error.h , use winerror.h             //~v6G3I~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6he:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~v6heI~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5k0:061226 (LNX/WIN)largefile(>4GB) support                     //~v5k0I~
//v5jA:061203 (BUG:3270):no response msg for free cmd success      //~v5jyI~
//v5jy:061123 3270:SPF information update                          //~v5jyI~
//v5je:061013 3270 support:xcopy/xmove                             //~v5jeI~
//v5jd:061002 3270 support:rename/delete
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
   #endif                                                          //+v6G3I~
  #endif                                                           //~v5ncI~
#endif
//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <ufile.h>
#include <uftp.h>                                                  //~v5jdM~
#include <ufile1f.h>                                               //~v5jdI~
#include <ufile2.h>                                                //~v5jdI~
#include <uerr.h>
#include <ufemsg.h>
#include <uparse.h>
#include <ustring.h>
#include <utrace.h>
#include <ualloc.h>
#include <u3270.h>
#include <u32702.h>                                                //~v5jdI~
//*******************************************************
//*******************************************************          //~v5jdI~
static int Srenameopt=0;                                           //~v5jdI~
static int Sxdelopt=0;                                             //~v5jdI~
static int Sxdelfctr=0;       //process ctr                        //~v5jdI~
static int Sxdeldctr=0;       //deleted file/dir ctr               //~v5jdI~
//*******************************************************          //~v5jdI~
int u3270wildrename(PUFTPHOST Ppuftph,UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm);//~v5jdR~
int u3270renamesub(PUFTPHOST Ppuftph,UCHAR *Poldname,UCHAR *Pnewname);//~v5jdI~
int u3270errnotsupported(char *Pfunc);                             //~v5jdR~
int u3270wildxdel(PUFTPHOST Ppuftph,UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm);//~v5jdR~
int u3270xdelsub(PUFTPHOST Ppuftph,UCHAR *Pfile);                  //~v5jdI~
int u3270spfsetparm(int Popt,PPDSSPFINFO Ppspfi,char **Ppout);     //~v5jyR~
//****************************************************************
//*umkdir
//*  257:mkd command success
//*  550:file exist/not found/permisson denied
//*retrn:rc(=errno)
//****************************************************************
int u3270mkdir(PUFTPHOST Ppuftph,UCHAR *Pdirname,ULONG Pmode,ULONG *Pprmode)
{
	return u3270errnotsupported("mkdir");                          //~v5jdR~
}//u3270mkdir
//****************************************************************
//*urmdir
//* remove dir
//*  250:rmd command success
//*  550:file exist/not found/permisson denied
//*retrn:rc(=errno),-2:root dir,-3:current dir
//****************************************************************
int u3270rmdir(PUFTPHOST Ppuftph,UCHAR *Pdirname)
{
	return u3270errnotsupported("rmdir");                          //~v5jdR~
}//u3270rmdir
//******************************************************************//~v5jdI~
//*uxddsub                                                         //~v5jdI~
//*   delete one entry(DSN delete is no supported)                 //~v5jdI~
//*ret  :rc 0:ok,1:need confirm,2:read only,8:err                  //~v5jdI~
//******************************************************************//~v5jdI~
int u3270xddsub(PUFTPHOST Ppuftph,int Pxdelopt,int Pxddopt,char *Pfullpath)//~v5jdR~
{                                                                  //~v5jdI~
    int dirsw,delctr,filectr,rc;                                   //~v5jdR~
    int msgopt;                                                    //~v5jdI~
//***********************                                          //~v5jdI~
    if (MEMBOFDSN(Pfullpath)==0)	//spport wildcard member only  //~v5jdI~
        return u3270errnotsupported("Delete DataSet");             //~v5jdI~
    dirsw=DSNWILDCARD(Pfullpath)!=0;                               //~v5jdR~
    msgopt=Pxdelopt&UXDELMSG;    //msg output option               //~v5jdI~
    if  (Pxdelopt & UXDELRONLYCHK)  //chk only                     //~v5jdI~
    {                                                              //~v5jdI~
        if (u3270xdelete(Ppuftph,Pfullpath,msgopt|UXDELRONLYCHK|UXDELFORCE,//~v5jdR~
                    &filectr,0,&delctr))    //list read only file  //~v5jdR~
            return 8;                                              //~v5jdI~
        uerrmsg("%s has %d entries",                               //~v5jdI~
                "%s ‚Í‘S %d Œ",                                   //~v5jdI~
                Pfullpath,filectr);                                //~v5jdI~
       return 0;                                                   //~v5jdI~
    }                                                              //~v5jdI~
//delete req                                                       //~v5jdI~
    if (!dirsw)                                                    //~v5jdI~
        Pxdelopt|=UXDELMSG; //1 line msg for file                  //~v5jdI~
    rc=u3270xdelete(Ppuftph,Pfullpath,Pxdelopt,&filectr,0,&delctr);//~v5jdR~
                    //deldir,file deleted msg                      //~v5jdI~
    if (!rc)                                                       //~v5jdR~
        if (dirsw)                                                 //~v5jdI~
        {                                                          //~v5jdI~
            uerrmsg("%s is processed(total %d,deleted %d)",        //~v5jdI~
                    "%s, ‘S %d Œ’† %d Œíœ",                    //~v5jdI~
                    Pfullpath,filectr,delctr);                     //~v5jdR~
        }                                                          //~v5jdI~
    return rc;                                                     //~v5jdI~
}//u3270xddsub                                                     //~v5jdI~
//**************************************************************** //~v5jdI~
//u3270xdelete                                                     //~v5jdI~
//* del file,wild card member                                      //~v5jdI~
//*retrn:rc                                                        //~v5jdI~
//**************************************************************** //~v5jdI~
int u3270xdelete(PUFTPHOST Ppuftph,UCHAR *Pfile,int Popt,          //~v5jdI~
            int *Ppprocctr,int *Ppronlyctr,int *Ppdelctr)          //~v5jdI~
{                                                                  //~v5jdI~
    UCHAR fpath[DSN_MAXLEN];                                       //~v5jdI~
    int filectr,rc;                                                //~v5jdI~
    UINT parmwildf[2];  //parm to wild func                        //~v5jdI~
    int wildsw;                                                    //~v5jdI~
//********************                                             //~v5jdI~
    Sxdelopt=Popt;                                                 //~v5jdI~
  	if (Ppprocctr)                                                 //~v5jdI~
    	*Ppprocctr=0;       //processed err ctr                    //~v5jdI~
  	if (Ppdelctr)                                                  //~v5jdI~
    	*Ppdelctr=0;        //deleted ctr                          //~v5jdI~
  	if (Ppronlyctr)                                                //~v5jdI~
    	*Ppronlyctr=0;  //read only err ctr                        //~v5jdI~
    Sxdelfctr=Sxdeldctr=0;                                         //~v5jdR~
    if (!u3270fullpath(Ppuftph,fpath,Pfile,DSN_MAXLEN))            //~v5jdI~
        return -1;                                                 //~v5jdI~
    if (MEMBOFDSN(fpath)==0)	//support wildcard member only     //~v5jdR~
        return u3270errnotsupported("Delete DataSet");             //~v5jdI~
    wildsw=(WILDCARD(fpath)!=0);         //source wild card        //~v5jdI~
    if (wildsw)                     //source wild card             //~v5jdI~
    {                                                              //~v5jdI~
        parmwildf[0]=0;                                            //~v5jdI~
        parmwildf[1]=(UINT)(Popt & UXDELCONFEACH);  //each confirm in wildfunc//~v5jdI~
        rc=u3270wildfunc(Ppuftph,fpath,u3270wildxdel,parmwildf,&filectr,0);//~v5jeR~
        if (!filectr)                                              //~v5jdI~
        {                                                          //~v5jdI~
        	uerrmsg("No Member for %s",0,                          //~v5jdI~
            		fpath);                                        //~v5jdI~
        	rc=ERROR_FILE_NOT_FOUND;                               //~v5jdI~
        }                                                          //~v5jdI~
    }                                                              //~v5jdI~
    else                                                           //~v5jdI~
        rc=u3270xdelsub(Ppuftph,fpath);                            //~v5jdR~
  if (Ppprocctr)                                                   //~v5jdI~
    *Ppprocctr=Sxdelfctr;       //processed err ctr                //~v5jdI~
  if (Ppdelctr)                                                    //~v5jdI~
    *Ppdelctr=Sxdeldctr;        //deleted ctr                      //~v5jdI~
  if (Ppronlyctr)                                                  //~v5jdI~
    *Ppronlyctr=0;  //read only err ctr                            //~v5jdR~
    return rc;                                                     //~v5jdI~
}//u3270xdelete                                                    //~v5jdI~
                                                                   //~v5jdI~
//**************************************************************** //~v5jdI~
//!u3270wildxdel                                                   //~v5jdR~
//* delete by wild card                                            //~v5jdI~
//*parm1:filename thru wildfunc                                    //~v5jdI~
//*parm2:dirlist ptr thru wildfunc                                 //~v5jdI~
//*parm3:parm thru uwildfunc(Pattrmask parm of xdelete)            //~v5jdI~
//*retrn:rc                                                        //~v5jdI~
//**************************************************************** //~v5jdI~
int u3270wildxdel(PUFTPHOST Ppuftph,UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm)//~v5jdR~
{                                                                  //~v5jdI~
//********************                                             //~v5jdI~
    return u3270xdelsub(Ppuftph,Pfullpath);                        //~v5jdR~
}//u3270wildxdel                                                   //~v5jdR~
                                                                   //~v5jdI~
//**************************************************************** //~v5jdI~
//uxdelsub                                                         //~v5jdI~
//* del file                                                       //~v5jdI~
//*retrn:rc                                                        //~v5jdI~
//**************************************************************** //~v5jdI~
int u3270xdelsub(PUFTPHOST Ppuftph,UCHAR *Pfile)                   //~v5jdR~
{                                                                  //~v5jdI~
    int rc,skipsw;                                                 //~v5jdR~
    int msgsw;                                                     //~v5jdI~
//********************                                             //~v5jdI~
//read only process                                                //~v5jdI~
    Sxdelfctr++;        //processed ctr(contain skip ctr)          //~v5jdI~
    skipsw=(Sxdelopt & UXDELRONLYCHK); //readonly chk only         //~v5jdI~
    if (skipsw)         //bypass                                   //~v5jdI~
        return 0;                                                  //~v5jdI~
    else                                                           //~v5jdI~
    {                                                              //~v5jdI~
        msgsw=(Sxdelopt & UXDELMSG); //msg put option save         //~v5jdI~
        Sxdelopt&=~UXDELMSG; //msg put option clear                //~v5jdI~
        rc=u3270remove(Ppuftph,Sxdelopt,Pfile);                    //~v5jdR~
        Sxdelopt|=msgsw; //msg put option restore                  //~v5jdI~
        if (!rc)                                                   //~v5jdI~
        {                                                          //~v5jdI~
            Sxdeldctr++;    //deleted ctr                          //~v5jdI~
            if (msgsw) //msg put option                            //~v5jdI~
//              ufiledeleted(Pfile,'F',-1,0);//size=-1  mean no display size/attr//~v5k0R~
                ufiledeleted(Pfile,'F',(FILESZT)(-1),0);//size=-1  mean no display size/attr//~v5k0I~
        }                                                          //~v5jdI~
//      return rc;                                                 //~v5jdI~//~v6heR~
    }                                                              //~v5jdI~
    return rc;                                                     //~v5jdI~
}//u3270xdelsub                                                    //~v5jdR~
//****************************************************************
//*uremove
//* delete file,cannot del dir
//*parm1:file name
//*retrn:rc(=errno)
//****************************************************************
int u3270remove(PUFTPHOST Ppuftph,int Popt,UCHAR *Pfilename)
{
    UCHAR cmd[MAX_CMDSZ];                                          //~v5jdI~
    PPIPERESPDATA phdr;                                            //~v5jdI~
    char *pc;                                                      //~v5jdR~
    int datalen,rc;                                                //~v5jdR~
//*********************************
	if (MEMBOFDSN(Pfilename)==0)	//DSNAME                       //~v5jdI~
		return u3270errnotsupported("DataSet delete");             //~v5jeR~
    pc=cmd+u3270sethostuser(Ppuftph,"DELETE",cmd);                 //~v5jdR~
    *pc++=' ';                                                     //~v5jdI~
    strcpy(pc,Pfilename+Ppuftph->UFTPHhostnmlen+1);                //~v5jdI~
//  rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULONG)(&phdr),&datalen);//~v5jdI~//~v6hhR~
    rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULPTR)(&phdr),&datalen);//~v6hhI~
    if (!rc)
    {
    	if (Popt & UXDELMSG) //msg put option                      //~v5jdR~
//      	ufiledeleted(Pfilename,'F',-1,0);//size=-1  mean no display size/attr//~v5k0R~
        	ufiledeleted(Pfilename,'F',(FILESZT)(-1),0);//size=-1  mean no display size/attr//~v5k0I~
    }                                                              //~v5jdI~
    else                                                           //~v5jdI~
    {                                                              //~v5jdI~
		if (!Gufile_nomsg)   //nomsg option                        //~v5jdR~
        	if (rc!=U3CR_RC_OTHER)	//                             //~v5jdI~
	        	uerrmsg("%s remove failed.",0,                     //~v5jdR~
							Pfilename);	//already exist or path not found//~v5jdR~
    }
    return rc;
}//u3270remove                                                     //~v5jdR~
//****************************************************************
//urename
//*retrn:rc(=errno)
//****************************************************************
int u3270rename(PUFTPHOST Ppuftph,int Popt,UCHAR *Poldname,UCHAR *Pnewname,UCHAR *Pnewspec)
{
    int rc;
    int pathlen1/*,pathlen2*/;                                     //~v6b9R~
    int renamectr,membsrcsw;                                       //~v5jdR~
    UCHAR *pc;
    UCHAR realname[DSN_MAXLEN];                                    //~v5jdR~
//********************
	Srenameopt=Popt;
    pathlen1=u3270pathlen(U3PL_PARENTORDROPMEMBER,Poldname);       //~v5jdR~
//  pathlen2=u3270pathlen(U3PL_PARENTORDROPMEMBER,Pnewname);       //~v5jdR~//~v6b9R~
    membsrcsw=pathlen1 && *(Poldname+pathlen1-1)==DSN_SEPCMEMB;	//membername specification//~v5jdR~
    if (pc=DSNWILDCARD(Poldname),pc)   //wild char pos             //~v5jdR~
    {
//      if (pathlen1 && (ULONG)pc-(ULONG)Poldname<(ULONG)pathlen1) //~v6hhR~
        if (pathlen1 && (ULPTR)pc-(ULPTR)Poldname<(ULPTR)pathlen1) //~v6hhI~
            return ufilewildpatherr(-1);
        rc=u3270wildfunc(Ppuftph,Poldname,u3270wildrename,Pnewname,&renamectr,0);//~v5jeR~
        if (rc)
            return rc;
        uerrmsg("%d object renamed",
                "%d Œ‰ü–¼",
                renamectr);
        return 0;
    }
    if (DSNWILDCARD(Pnewname))                                     //~v5jdR~
    {
        u3270editname(Ppuftph,0,Poldname,Pnewname,realname);       //~v5jdR~
        if (Pnewspec)   //no output  parm
            strcpy(Pnewspec,realname);
        Pnewname=realname;
        if (DSNWILDCARD(Pnewname))     //path has wild card        //~v5jdR~
            return ufilewildpatherr(-1);
    }
    else
        if (Pnewspec)   //no output  parm
            *Pnewspec=0;        //return id of no wild card
    rc=u3270renamesub(Ppuftph,Poldname,Pnewname);                  //~v5jdI~
    if (rc==U3CR_RC_DUPNAME)                                       //~v5jdR~
    {                                                              //~v5jdI~
		if (!Popt||!membsrcsw)		//not override existing option or not member rename//~v5jdR~
            return ufileexist(Pnewname,EEXIST);                    //~v5jdM~
		if (rc=u3270remove(Ppuftph,0,Pnewname),!rc)                //~v5jdI~
		    rc=u3270renamesub(Ppuftph,Poldname,Pnewname);          //~v5jdI~
    }                                                              //~v5jdI~
    return rc;                                                     //~v5jdI~
}//u3270rename
//****************************************************************
//uftprenamesub
//*retrn:rc(=errno)
//****************************************************************
int u3270renamesub(PUFTPHOST Ppuftph,UCHAR *Poldname,UCHAR *Pnewname)
{
    UCHAR cmd[MAX_CMDSZ];                                          //~v5jdR~
    char *poldname,*pnewname,*pc;                                  //~v5jdR~
    int rc,datalen;                                                //~v5jdR~
    PPIPERESPDATA phdr;                                            //~v5jdI~
//*********************************
    poldname=Poldname+Ppuftph->UFTPHhostnmlen+1;
    pnewname=Pnewname+Ppuftph->UFTPHhostnmlen+1;
    pc=cmd+u3270sethostuser(Ppuftph,"RENAME",cmd);                 //~v5jdI~
    sprintf(pc," %s %s",poldname,pnewname);                        //~v5jdR~
//  rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULONG)(&phdr),&datalen);//~v5jdI~//~v6hhR~
    rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULPTR)(&phdr),&datalen);//~v6hhI~
    return rc;
}//u3270renamesub
//****************************************************************
//!u3270wildrename                                                 //~v5jdR~
//* rename by wild card                                            //~v5jdR~
//*parm1:filename thru wildfunc
//*parm2:dirlist ptr thru wildfunc
//*parm3:parm thru uwildfunc(Pnewname parm of urename)
//*retrn:rc
//****************************************************************
int u3270wildrename(PUFTPHOST Ppuftph,UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm)//~v5jdR~
{
    return u3270rename(Ppuftph,Srenameopt,Pfullpath,Pparm,0);//no real name
}//u3270wildrename
//**************************************************************** //~v5jyI~
//*spf info update                                                 //~v5jyI~
//**************************************************************** //~v5jyI~
int u3270spfupdate(int Popt,PUFTPHOST Ppuftph,char *Pfilename,PPDSSPFINFO Ppspfi,PPDSSPFINFO Ppspfinew)//~v5jyR~
{                                                                  //~v5jyI~
    UCHAR cmd[MAX_CMDSZ];                                          //~v5jyI~
    PPIPERESPDATA phdr;                                            //~v5jyI~
    PDSNLIST     pdsnl=0;                                          //~v5jyI~
    char *pc;                                                      //~v5jyR~
    int datalen,rc;                                                //~v5jyI~
//*********************************                                //~v5jyI~
	if (MEMBOFDSN(Pfilename)==0)	//DSNAME                       //~v5jyI~
		return u3270errnotsupported("Set SPF Info to DataSet");    //~v5jyI~
    pc=cmd+u3270sethostuser(Ppuftph,"SPF",cmd);                    //~v5jyI~
    *pc++=' ';                                                     //~v5jyI~
    strcpy(pc,Pfilename+Ppuftph->UFTPHhostnmlen+1);                //~v5jyI~
    pc+=strlen(pc);                                                //~v5jyI~
    *pc++=' ';                                                     //~v5jyI~
    *pc++='\"';                                                    //~v5jyI~
    u3270spfsetparm(Popt,Ppspfi,&pc);                              //~v5jyI~
    *pc++='\"';                                                    //~v5jyR~
    *pc=0;                                                         //~v5jyI~
//  rc=u3270cmdrequest(U3CRO_UERRMSG,cmd,(void**)(ULONG)(&phdr),&datalen);//~v5jAR~
//  rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULONG)(&phdr),&datalen);//~v5jAR~//~v6hhR~
    rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,(void**)(ULPTR)(&phdr),&datalen);//~v6hhI~
    if (phdr)                                                      //~v5jyI~
    {                                                              //~v5jyI~
    	if (!rc)                                                   //~v5jyR~
        {                                                          //~v5jyI~
//    		pdsnl=(PDSNLIST)(ULONG)phdr;                           //~v5jyI~//~v6hhR~
     		pdsnl=(PDSNLIST)(ULPTR)phdr;                           //~v6hhI~
        	if (Ppspfinew)	//nequested get new                    //~v5jyI~
	        	memcpy(Ppspfinew,&pdsnl->DSLspfi,PDSSPFINFOSZ);    //~v5jyR~
        }                                                          //~v5jyI~
    	ufree(phdr);                                               //~v5jyI~
    }                                                              //~v5jyI~
    return rc;                                                     //~v5jyI~
}//u3270spfupdate                                                  //~v5jyI~
//**************************************************************** //~v5jyI~
//*spf info update parm setup                                      //~v5jyI~
//**************************************************************** //~v5jyI~
int u3270spfsetparm(int Popt,PPDSSPFINFO Ppspfi,char **Ppout)      //~v5jyR~
{                                                                  //~v5jyI~
    char *pc;                                                      //~v5jyI~
    long long0=0;                                                  //~v5jyI~
//*********************************                                //~v5jyI~
	pc=*Ppout;                                                     //~v5jyR~
    if (Popt & U3270SPFO_VER)	//version update                   //~v5jyI~
    	pc+=sprintf(pc,"%02d",Ppspfi->SPFIver%100);                //~v5jyI~
    *pc++=',';                                                     //~v5jyR~
    if (Popt & U3270SPFO_MOD)	//mod update                       //~v5jyI~
    	pc+=sprintf(pc,"%02d",Ppspfi->SPFImod%100);                //~v5jyI~
    *pc++=',';                                                     //~v5jyR~
    if (Popt & U3270SPFO_CDATE)	//creation date update             //~v5jyI~
    {                                                              //~v5jyI~
        if (Popt & U3270SPFO_NOWCDATE) //set today                 //~v5jyI~
        {	                                                       //~v5jyI~
        	strcpy(pc,U3270SPFNOW);                                //~v5jyI~
            pc+=3;                                                 //~v5jyI~
        }                                                          //~v5jyI~
        else                                                       //~v5jyI~
        {                                                          //~v5jyI~
        	if (memcmp(&Ppspfi->SPFIcdate,&long0,sizeof(FDATE)))   //~v5jyR~
    		 	pc+=sprintf(pc,"%02d%02d%02d",(Ppspfi->SPFIcdate.year+1980)%100,Ppspfi->SPFIcdate.month,Ppspfi->SPFIcdate.day);//~v5jyR~
        }                                                          //~v5jyI~
    }                                                              //~v5jyI~
    *pc++=',';                                                     //~v5jyR~
    if (Popt & U3270SPFO_UPDATE)	//update date/time             //~v5jyI~
    {                                                              //~v5jyI~
        if (Popt & U3270SPFO_NOWUPDATE)  //set current             //~v5jyI~
        {                                                          //~v5jyI~
        	strcpy(pc,U3270SPFNOW);     //update date              //~v5jyI~
            pc+=3;                                                 //~v5jyI~
		    *pc++=',';                                             //~v5jyI~
        	strcpy(pc,U3270SPFNOW);     //update time              //~v5jyI~
            pc+=3;                                                 //~v5jyI~
        }                                                          //~v5jyI~
        else                                                       //~v5jyI~
        {                                                          //~v5jyI~
        	if (memcmp(&Ppspfi->SPFIudate,&long0,sizeof(FDATE)))   //~v5jyR~
            {                                                      //~v5jyI~
    			pc+=sprintf(pc,"%02d%02d%02d",(Ppspfi->SPFIudate.year+1980)%100,Ppspfi->SPFIudate.month,Ppspfi->SPFIudate.day);//~v5jyR~
			    *pc++=',';                                         //~v5jyI~
    			pc+=sprintf(pc,"%02d%02d",Ppspfi->SPFIutime.hours,Ppspfi->SPFIutime.minutes);//~v5jyR~
            }                                                      //~v5jyI~
        }                                                          //~v5jyI~
    }                                                              //~v5jyI~
    *pc++=',';                                                     //~v5jyR~
    if (Popt & U3270SPFO_CLINE)	        //current line             //~v5jyI~
    {                                                              //~v5jyI~
        if (Popt & U3270SPFO_NOWCLINE)                             //~v5jyI~
        {                                                          //~v5jyI~
        	strcpy(pc,U3270SPFNOW);     //update date              //~v5jyI~
            pc+=3;                                                 //~v5jyI~
        }                                                          //~v5jyI~
        else                                                       //~v5jyI~
    		pc+=sprintf(pc,"%d",Ppspfi->SPFIlinecnt);              //~v5jyI~
    }                                                              //~v5jyI~
    *pc++=',';                                                     //~v5jyR~
    if (Popt & U3270SPFO_ILINE)	        //current line             //~v5jyI~
    {                                                              //~v5jyI~
        if (Popt & U3270SPFO_NOWILINE)                             //~v5jyI~
        {                                                          //~v5jyI~
        	strcpy(pc,U3270SPFNOW);     //update date              //~v5jyI~
            pc+=3;                                                 //~v5jyI~
        }                                                          //~v5jyI~
        else                                                       //~v5jyI~
    		pc+=sprintf(pc,"%d",Ppspfi->SPFIinitcnt);              //~v5jyI~
    }                                                              //~v5jyI~
    *pc++=',';                                                     //~v5jyR~
    if (Popt & U3270SPFO_USERID)        //current line             //~v5jyI~
    {                                                              //~v5jyI~
    	strcpy(pc,Ppspfi->SPFIuserid);                             //~v5jyR~
        pc+=strlen(pc);                                            //~v5jyI~
    }                                                              //~v5jyI~
    *Ppout=pc;                                                     //~v5jyI~
    return 0;                                                      //~v5jyI~
}//u3270spfsetparm                                                 //~v5jyI~
//****************************************************************
//uattrib
//* set file attribute(read/hidden/system/archive)
//* return file attribute when p2==0 and p3==0
//*parm1:filename
//*parm2:attribute to set on   mode+attr
//*parm3:attribute to set off  mode+attr   if on=0,off=0:query
//*parm4:result attribute      mode+attr
//*retrn:rc
//****************************************************************
int u3270attrib(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Pattron,ULONG  Pattroff,ULONG  *Poutattr)
{
	return u3270errnotsupported("attrib");                         //~v5jdR~
}//u3270attrib
//****************************************************************
//uattrxchk
//* chk x bit(USER)
//*parm1:filename
//*parm2:opt to issue errmsg
//*retrn:rc:0 not executable,1:executable
//****************************************************************
int u3270attrxchk(PUFTPHOST Ppuftph,UCHAR *Pfname,int Popt)
{
	return u3270errnotsupported("attrib");                         //~v5jdR~
}//u3270attrxchk
//****************************************************************
//uftpgetftime
//* get file time stamp
//* (W)modtime fail  for dir(not plain file),fmt IS GMT but not JST
//*retrn:rc
//****************************************************************
int u3270getftime(PUFTPHOST Ppuftph,UCHAR *Pfname,FDATE *Ppdate,FTIME *Pptime)
{
	return u3270errnotsupported("get filetime");                   //~v5jdR~
}//u3270getftime
//****************************************************************
//uftpsetftime
//* no method to set time
//*retrn:rc
//****************************************************************
int u3270setftime(PUFTPHOST Ppuftph,UCHAR *Pfname,FDATE Pdate,FTIME Ptime)
{
//********************
	return u3270errnotsupported("set filetime");                   //~v5jdR~
}//u3270setftime
//****************************************************************
//usetftime2
//* no method to set time
//* set file time stamp; unit=second
//****************************************************************
int u3270setftime2(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Patime,ULONG Pmtime)
{
	return u3270errnotsupported("set filetime2");                  //~v5jdR~
}//u3270setftime2
//****************************************************************
//uftpcopypathinfo
//  called when one of sorce and target is remote
//* local<-->remote,remote<-->remote
//* no method to set time
//*retrn:rc
//****************************************************************
int u3270copypathinfo(PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,UCHAR *Psource,UCHAR *Ptarget)
{
	return u3270errnotsupported("copy pathinf");                   //~v5jdR~
}//u3270copypathinfo
//****************************************************************
//uftpsetown
//* set uid/gid
//*parm1:target name
//*parm2:uid
//*parm3:gid
//*retrn:rc
//****************************************************************
int u3270setown(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Puid,ULONG Pgid)
{
	return u3270errnotsupported("setown");                         //~v5jdR~
}//u3270setown
//****************************************************************
//ufilesetmod
//* set modifier
//*parm1:target name
//*parm2:mode  or attr fpr MDOS file
//*retrn:rc
//****************************************************************
int u3270setmod(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Pmode)
{
	return u3270errnotsupported("chmod");                          //~v5jdR~
}//u3270setmod
//****************************************************************
//u3270wildfunc                                                    //~v5jdR~
//* apply function for wild card
//*parm1:option for apply to ea data(1:apply)
//*parm2:wild card filename
//*parm3:file selection attribute mask
//*parm4:apply function(int func(char *filename,void *parm))
//*parm5:apply function parm
//*parm5:output applied count
//*retrn:rc
//****************************************************************
int u3270wildfunc(PUFTPHOST Ppuftph,UCHAR *Psource,                //~v5jdR~
                TSO_WILDAPPLYFUNC *Pfunc,void *Pparm,int *Pfilectr,PUDIRLIST *Pppudl)//~v5jeR~
{
    int rc=0,filectr,ii;                                           //~v5jdR~
    PUDIRLIST pudirlist,pudirlist0;
    UCHAR fpath[FTP_MAXPATH];
//********************
	rc=u3270dirlistsub(Ppuftph,0,&filectr,Psource,0,&pudirlist0);  //~v5jdR~
    if (rc)  //err                                                 //~v5jdR~
        return 4;
    pudirlist=pudirlist0;
    if (Pppudl)            	//optionaly output list                //~v5jeI~
    	*Pppudl=pudirlist0;                                        //~v5jeI~
    *Pfilectr=0;
    for (ii=0;ii<filectr;ii++,pudirlist++)  //until eof/err
    {
        if (!strcmp(pudirlist->name,".")        //curr
        ||  !strcmp(pudirlist->name,".."))      //parent
            continue;
        *Pfilectr=*Pfilectr+1;
        u3270concatfilename(U3CF_REPMEMBER,Psource,pudirlist->name,fpath);//~v5jdR~
        if (rc=Pfunc(Ppuftph,fpath,pudirlist,Pparm),rc)
            break;
    }//dir list
    if (!Pppudl)            	//not output                       //~v5jeI~
//  	ufree(pudirlist0);                                         //~v5jeR~//~v6qaR~
    	UDIRLIST_FREE(pudirlist0);                                 //~v6qaI~
    return rc;
}//u3270wildfunc
//**************************************************************** //~v5jdI~
//u3270errnotsupported                                             //~v5jdI~
//  write get/put statement                                        //~v5jdI~
//**************************************************************** //~v5jdI~
int u3270errnotsupported(char *Pfunc)                              //~v5jdR~
{                                                                  //~v5jdI~
	errno=U3CR_RC_NOTSUPPORT;                                      //~v5jdI~
	return uerrnotsupported(Pfunc,"TSO file",errno);               //~v5jdI~
}//u3270errnotsupported                                            //~v5jdI~
