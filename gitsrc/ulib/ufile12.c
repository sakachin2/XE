//*CID://+v6BkR~:                             update#=  182;       //+v6BkR~
//*************************************************************
//*ufile.c
//*************************************************************
//v6Bk:160220 (LNX)compiler warning                                //+v6BkI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v5kq:070630 remote file compare support                          //~v5kqI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#ifdef UNX  //!!!!!!!!!!!!!!!!!!
    #include <unistd.h>
#else                                                              //~v5kqI~
  #ifndef OS2                                                      //~v5kqI~
    #include <dos.h>                                               //~v5kqI~
  #endif                                                           //~v5kqI~
#endif       //!!!!!!!!!!!!!!!!!!                                  //~v5kqR~
//*******************************************************
#include <ulib.h>                                                  //~v5kqI~
#include <ufile.h>                                                 //~v5kqI~
#include <ufemsg.h>                                                //~v5kqI~
#include <uerr.h>                                                  //~v5kqI~
#include <ualloc.h>                                                //~v5kqI~
#include <ustring.h>                                               //~v5kqI~
#include <utrace.h>                                                //~v5kqI~
#include <uque.h>                                                  //~v5kqI~
#include <uftp.h>                                                  //~v5kqI~
#include <u3270.h>                                                 //~v5kqI~
#include <uedit.h>                                                 //~v5kqI~
#include <ufile1f.h>                                               //~v5kqM~
//*******************************************************          //~v5kqI~
//*******************************************************          //~v5kqI~
//*get file lastname                                               //~v5kqI~
//*opt :not used                                                   //~v5kqI~
//*return:length                                                   //~v5kqI~
//*******************************************************          //~v5kqI~
int ufilegetlastname(int Popt,void * Ppuftph,char *Pfilename,char *Plastname)//~v5kqI~
{                                                                  //~v5kqI~
    int pathlen,len;                                               //~v5kqI~
    char *pc;                                                      //~v5kqI~
#ifdef FTPSUPP                                                     //~v5kqI~
	PUFTPHOST puftph;                                              //~v5kqI~
#endif                                                             //~v5kqI~
//*********************************                                //~v5kqI~
#ifdef FTPSUPP                                                     //~v5kqI~
	if (!(puftph=(PUFTPHOST)Ppuftph))                              //~v5kqI~
    	uftpisremote(Pfilename,&puftph);                           //~v5kqI~
    if (puftph && UFTPHISTSO(puftph))	//3270                     //~v5kqI~
		return u3270getlastname(0,Pfilename,Plastname);	//quatation drop//~v5kqR~
    if (puftph)                                                    //~v5kqI~
	    pathlen=FTP_PATHLEN(Pfilename);                            //~v5kqI~
    else                                                           //~v5kqI~
#endif                                                             //~v5kqI~
        pathlen=PATHLEN(Pfilename);                                //~v5kqR~
    if (pathlen<0)                                                 //~v5kqI~
        return 0;                                                  //~v5kqI~
    pc=Pfilename+pathlen;                                          //~v5kqI~
    len=(int)strlen(pc);                                           //~v5kqR~
    memcpy(Plastname,pc,(UINT)len);                                //~v5kqI~
    *(Plastname+len)=0;                                            //~v5kqI~
    if (len && *(Plastname+len-1)=='"')                            //~v5kqI~
        *(Plastname+len-1)=0;                                      //~v5kqI~
    return len;                                                    //~v5kqI~
}//ufilegetlastname                                                //~v5kqI~
//*******************************************************          //~v5kqI~
//*concat path and member name                                     //~v5kqI~
//*return:output length                                            //~v5kqI~
//*******************************************************          //~v5kqI~
int ufileconcatlastname(int Popt,void * Ppuftph,char *Pfilename,char *Plastname,char *Pout)//~v5kqI~
{                                                                  //~v5kqI~
    int len,sepc;                                                  //~v5kqR~
    char *pc;                                                      //~v5kqI~
#ifdef FTPSUPP                                                     //~v5kqI~
	PUFTPHOST puftph;                                              //~v5kqI~
    int opt;                                                       //~v5kqI~
#endif                                                             //~v5kqI~
//*********************************                                //~v5kqI~
#ifdef FTPSUPP                                                     //~v5kqI~
	if (!(puftph=(PUFTPHOST)Ppuftph))                              //~v5kqI~
    	uftpisremote(Pfilename,&puftph);                           //~v5kqI~
    if (puftph && UFTPHISTSO(puftph))	//3270                     //~v5kqI~
    {                                                              //~v5kqI~
    	opt=U3CF_FORCEASMEMBERIFNOTWILD;                           //~v5kqI~
		return u3270concatfilename(opt,Pfilename,Plastname,Pout);  //~v5kqR~
    }                                                              //~v5kqI~
    if (puftph)                                                    //~v5kqI~
    	sepc=FTP_DIR_SEPC;                                         //~v5kqI~
    else                                                           //~v5kqI~
#endif                                                             //~v5kqI~
		sepc=DIR_SEPC;                                             //~v5kqI~
	len=(int)strlen(Pfilename);                                    //~v5kqR~
    pc=Pout;                                                       //~v5kqI~
    memcpy(pc,Pfilename,(UINT)len);                                //~v5kqI~
    pc+=len;                                                       //~v5kqI~
    if (len && *(pc-1)!=sepc)                                      //~v5kqI~
    	*(pc++)=(char)sepc;                                        //~v5kqR~
    len=(int)strlen(Plastname);                                    //~v5kqR~
    memcpy(pc,Plastname,(UINT)len);                                //~v5kqI~
    pc+=len;                                                       //~v5kqI~
    if (*Pfilename=='"' && *(pc-1)!='"')                           //~v5kqI~
    	*pc++='"';                                                 //~v5kqI~
    *pc++=0;                                                       //~v5kqI~
//  len=(int)((ULONG)pc-(ULONG)Pout);                              //~v5kqR~//~v6hhR~
    len=(int)((ULPTR)pc-(ULPTR)Pout);                              //~v6hhI~
    return len;                                                    //~v5kqR~
}//ufileconcatlastname                                             //~v5kqI~
//*******************************************************          //~v5kqI~
//*chk file is normal file                                         //~v5kqI~
//*return:0:normal fil,1:dir,2:special,dsnpath, 4:err              //~v5kqR~
//*******************************************************          //~v5kqI~
int ufileisnormalfile(int Popt,void * Ppuftph,char *Pfilename)     //~v5kqI~
{                                                                  //~v5kqI~
	int rc;                                                        //~v5kqI~
	FILEFINDBUF3 ffb3;                                             //~v5kqM~
#ifdef FTPSUPP                                                     //~v5kqI~
    char fpath[_MAX_PATH];                                         //~v5kqI~
	PUFTPHOST puftph;                                              //~v5kqI~
#endif                                                             //~v5kqI~
//*********************************                                //~v5kqI~
#ifdef FTPSUPP                                                     //~v5kqI~
	if (!(puftph=(PUFTPHOST)Ppuftph))                              //~v5kqI~
    	uftpisremote(Pfilename,&puftph);                           //~v5kqI~
    if (puftph)                                                    //~v5kqI~
    {                                                              //~v5kqI~
    	if (!uftpfullpath(puftph,fpath,Pfilename,_MAX_PATH))       //~v5kqI~
       		return 4;                                              //~v5kqI~
//  	rc=uftpfstat(puftph,Pfilename,&ffb3);                      //~v5kqR~//+v6BkR~
    	rc=(int)uftpfstat(puftph,Pfilename,&ffb3);                 //+v6BkI~
    }                                                              //~v5kqI~
    else                           //local file                    //~v5kqI~
#endif                                                             //~v5kqI~
		rc=(int)ufstat(Pfilename,&ffb3);                           //~v5kqR~
    if (rc)                                                        //~v5kqI~
    {                                                              //~v5kqI~
		if (Popt & FINF_ERRMSGSNOTF)    //issue errmsg not found   //~v5kqI~
        	ufilenotfound(Pfilename,4);                            //~v5kqI~
        return 4;                                                  //~v5kqI~
    }                                                              //~v5kqI~
#ifdef UNX                                                         //~v5kqI~
    if (ffb3.attrFile & FILE_SPECIAL)                              //~v5kqR~
    {                                                              //~v5kqI~
		if (Popt & FINF_ERRMSGSPECIAL)    //issue errmsg not found //~v5kqR~
        	ufileerrspecialfile(Pfilename,4);                      //~v5kqI~
    	return 2;                                                  //~v5kqR~
    }                                                              //~v5kqI~
#endif                                                             //~v5kqM~
#ifdef FTPSUPP                                                     //~v5kqI~
    if (ffb3.attrFile & FILE_DSNPATH)                              //~v5kqI~
    {                                                              //~v5kqI~
		if (Popt & FINF_ERRMSGSPECIAL)    //issue errmsg not found //~v5kqR~
        	ufileerrnotnormal(Pfilename,4);                        //~v5kqI~
    	return 2;                                                  //~v5kqI~
    }                                                              //~v5kqI~
#endif                                                             //~v5kqI~
    if (ffb3.attrFile & FILE_DIRECTORY)                            //~v5kqR~
    {                                                              //~v5kqI~
		if (Popt & FINF_ERRMSGDIR)    //issue errmsg not found     //~v5kqR~
        	ufileerrdir(Pfilename,4);                              //~v5kqR~
    	return 1;                                                  //~v5kqI~
    }                                                              //~v5kqI~
    return 0;                                                      //~v5kqI~
}//ufileisnormalfile                                               //~v5kqI~
//*******************************************************          //~v5kqI~
//*create local copy filename by fullpath                          //~v5kqI~
//*return:output length                                            //~v5kqI~
//*******************************************************          //~v5kqI~
int ufilefullpathtemp(int Popt,char *Pfname,char *Pout)            //~v5kqI~
{                                                                  //~v5kqI~
    char *pci,*pco;                                                //~v5kqR~
    int ch,ii;                                                     //~v5kqR~
//*********************************                                //~v5kqI~
    pci=Pfname;                                                    //~v5kqR~
    pco=Pout;                                                      //~v5kqR~
    for (ii=0;;ii++)                                               //~v5kqR~
    {                                                              //~v5kqI~
        ch=*pci++;                                                 //~v5kqI~
        if (ch==':'||ch=='/'||ch=='\\'||ch=='\''||ch=='('||ch==')')//~v5kqR~
        	ch='.';                                                //~v5kqR~
        *pco++=(char)ch;                                           //~v5kqR~
        if (!ch)                                                   //~v5kqI~
        	break;                                                 //~v5kqI~
    }                                                              //~v5kqI~
    return ii;                                                     //~v5kqR~
}//ufilefullpathtemp                                               //~v5kqI~
//*******************************************************          //~v5kqI~
//*create local copy filename by fullpath                          //~v5kqI~
//*return:1:enclosed,0:not changed                                 //~v5kqI~
//*******************************************************          //~v5kqI~
int ufilenameenclose(int Popt,char *Pfname,char *Pout)             //~v5kqI~
{                                                                  //~v5kqI~
	char wk[_MAX_PATH];                                            //~v5kqR~
    int len;                                                       //~v5kqI~
//*********************************                                //~v5kqI~
	if (*Pfname=='"'||!strchr(Pfname,' '))                         //~v5kqI~
    {                                                              //~v5kqI~
    	if (Pout!=Pfname)                                          //~v5kqI~
	    	strcpy(Pout,Pfname);                                   //~v5kqI~
    	return 0;                                                  //~v5kqR~
    }                                                              //~v5kqI~
    len=(int)strlen(Pfname);                                       //~v5kqI~
    wk[0]='"';                                                     //~v5kqR~
    memcpy(wk+1,Pfname,(UINT)len);                                 //~v5kqI~
    len++;                                                         //~v5kqI~
    wk[len++]='"';                                                 //~v5kqR~
    wk[len]=0;                                                     //~v5kqR~
    strcpy(Pout,wk);                                               //~v5kqI~
    return 1;                                                      //~v5kqI~
}//ufilenameenclose                                                //~v5kqI~
