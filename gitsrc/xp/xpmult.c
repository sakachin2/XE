//*CID://+v9a1R~:                             update#=  119;       //+v9a1R~
//***********************************************************   //~v742I~
//* XPSUB1 : xprint sub1                                        //~v743R~
//***********************************************************   //~v742I~
//v9a1:160418 v9.33 LNX64 Compiler warning                         //+v9a1I~
//v9a0:160418 v9.33 LNX compiler warning                           //~v9a0I~
//v998:160404 v9.32 W64 compiler warning                           //~v998I~
//v990:140506 v9.30 (W32UNICODE) filename by UD fmt                //~v990I~
//v96z:130809 (BUG:LNX not gxp)EBCFILE ucs2local1 output utf8 when LANG=UTF8,ucvext_b2mDbcsstr cut by 2 byte each//~v96zI~
//            set EBCBYUCS(set dd to buff) and convert to utf8 at write//~v96zI~
//v96y:130808 (BUG)indirect file print;tabskip have to be saved    //~v96yI~
//v96e:130724 v9.25 recfm=V(-Vvfmt) support                        //~v96eI~
//120629 v968 VC2010:LP64 support                                  //~v968I~
//120611 v965 avoid C4701 warning(variable may not be uninitialized)//~v965I~
//101025 v961 (BUG of V942)from V125F;"Invalid name format" err for indirect print//~v961I~
//100908 v954 v9.19 allow tab as indirect file seperator           //~v954I~
//100908 v953 v9.19 EBC convertername support /CPEB:               //~v953I~
//100429 v942 option support for each file on filename list        //~v942I~
//040605 v91m :additional to 90b,allow dir without wildcard        //~v91mI~
//				for also indirect file if not remote dir.          //~v91mI~
//040531 v91k (FTP)remote file print support;"<orgfname>LocalTempFile" fmt//~v91kI~
//                 on parm and indirect file.                      //~v91kI~
//011209 v90m :support stdout output                               //~v90mI~
//010521 v90e :(BUG)at uexit,free not yet malloced                 //~v90eI~
//010520 v90b :LINUX support(allow dirname without wild card because shell expand wild card)//~v90bI~
//010520 v90a :LINUX support(multifile seperater change from "/" to ":")//~v90aI~
//010519 v907 :LINUX support                                       //~v907I~
//971130 v837 :(BUG)access area after free(abend when w95)         //~v837I~
//970928 v826 :w95 version                                         //~v826I~
//970214 v807:use FINDBUF3 by ufile.h                              //~v807I~
//950822 v743 :indirect option                                  //~v743I~
//950821 v742 :input file stdin support                         //~v742I~
//**********************************************************************//~v742I~
#include <stdio.h>                                              //~v742I~
#include <stdlib.h>                                             //~v742I~
#include <ctype.h>                                              //~v742R~
#include <string.h>                                             //~v742R~
//#include <sys\types.h>                                           //~v907R~
//#include <sys\stat.h>                                            //~v907R~
#include <sys/types.h>                                             //~v907I~
#include <sys/stat.h>                                              //~v907I~
                                                                   //~v90bI~
#ifdef UNX                                                         //~v90bR~
#else   //!UNX                                                     //~v90bI~
                                                                   //~v90bI~
#include <io.h>                                                    //~v90bI~
                                                                   //~v90bI~
#ifdef DOS                                                      //~v742R~
#include <errno.h>                                              //~v742R~
#else                                                           //~v742I~
  #ifdef W32                                                       //~v826I~
  #else                                                            //~v826I~
#define INCL_BASE                                               //~v742R~
#include <os2.h>                                                //~v742R~
  #endif                                                           //~v826I~
#endif                                                          //~v742I~
#endif                                                             //~v90bI~
                                                                //~v742I~
#include <ulib.h>                                               //~v742R~
#include <ufile.h>                                                 //~v807I~
#include <uerr.h>                                                  //~v90bI~
#include <ustring.h>                                               //~v942I~
#include <utrace.h>                                                //~v96eI~
                                                                //~v743I~
#include "xp.h"                                                 //~v743I~
#include "xpinp.h"                                                 //~v91kI~
#include "xpebc.h"                                                 //~v942I~
#include "xputf.h"                                                 //~v942I~
#include "xpsub1.h"                                                //~v96eI~
                                                                //~v742I~
//*********************************************************************//~v742I~
//* global to share with xpsub                                  //~v742I~
//*********************************************************************//~v742I~
extern char pgmid[];                                            //~v742I~
extern char ver[];                                              //~v742I~
extern int  dbcsenv;           //dbcs environment sw            //~v742I~
extern FILE *Gmsgfile;       //for print start msg                 //~v90mI~
extern int Gebcdictype;		//EBCDIC subtype 1:katakana,2:english small char//~v942I~
extern int asciimode;        //char set id                     v2.5add//~v942I~
extern int recordsz;       	//input record length      	v6.7a      //~v942I~
extern int dumpmode;         //dump mode default=text v2.8rep v6.7r//~v942I~
extern int nocrlfsw; 	      	//ignore crlf for dump mode v6.7a  //~v942I~
extern int maxcol;      //colomn no per line v1.4rep v1.7rep v7.23r//~v942R~
extern int tabskip;                                                //~0429I~//~v96yI~
//*************************************                         //~v742I~
//int findfile(char *);			//v5.8a findfirst/findnext         //~v91kR~
void xpmultdir(char **Ppfname,int *Ppappendsw);                    //~v90bR~
char *xpsrchsepc(char *Pparmstring);                               //~v91kI~
char *xpmult_indirectopt(int Popt,char *Precbuff,int Plen);        //~v942R~
//**********************************************************************//~v742I~
//*get file name from indirect file                             //~v743R~
//*parm1:indirect file name (if 0,stdin)                        //~v743R~
//*ret  :string concatinated by /                               //~v742I~
//**********************************************************************//~v742I~
char *uindirect(char *Pfnm)                                     //~v743R~
{                                                               //~v742I~
typedef struct _FNMCHAIN{struct _FNMCHAIN *pnext;char fnm[1];} FNMCHAIN;//~v742R~
	struct stat statbuff;                                       //~v742R~
	int redirectsw,len,tlen=0;                                  //~v742R~
	char *pc,*parmfname;                                        //~v742R~
    int handle=0;                                               //~v742R~
    int rc;                                                        //~v91mR~
    char recbuff[_MAX_PATH+1];                                  //~v742I~
    FNMCHAIN  *fnmchaino=0,*fnmchain,*fnmchaintop=NULL;              //~v742R~//~v965R~
    FILE *fh;                                                   //~v743I~
    char *poptstr;                                                 //~v942R~
    int topspacectr;                                               //~v954I~
//***********************                                       //~v742I~
    if (Pfnm)                                                   //~v743I~
    {                                                           //~v743I~
        if (!(fh=fopen(Pfnm,"r")))                              //~v743I~
        {                                                       //~v743I~
			if (dbcsenv)	//DBCS mode                         //~v743I~
				printf("%s:%s:%s のオープン失敗,rc=%d\n",pgmid,ver,Pfnm,errno);//~v743I~
        	else                                                //~v743I~
				printf("%s:%s:%s open failed,rc=%d\n",pgmid,ver,Pfnm,errno);//~v743I~
			uexit(8);                                           //~v743R~
		}                                                       //~v743I~
        handle=fileno(fh);                                      //~v743I~
    }                                                           //~v743I~
    else                                                        //~v743I~
    {                                                           //~v743I~
        handle=0;                                               //~v743I~
        fh=stdin;                                               //~v743I~
    }                                                           //~v743I~
	if (fstat(handle,&statbuff))                                //~v743R~
		printf("%s:%s:fstat failed for handle %d\n",pgmid,ver,handle);//~v743I~
    if (!(redirectsw=(statbuff.st_size!=0)))                    //~v742R~
    {                                                              //~v91mI~
		if (dbcsenv)	//DBCS mode                             //~v742I~
			printf("%s:%s:ファイル名を入力して下さい\n",pgmid,ver);//~v742I~
        else	                                                //~v742I~
			printf("%s:%s:enter file name\n",pgmid,ver);        //~v742R~
    }                                                              //~v91mI~
	while(fgets(recbuff,sizeof(recbuff),fh))	//null return if error or eof//~v743R~
	{                                                           //~v742I~
		len=(int)strlen(recbuff);                               //~v742R~
        if (*(recbuff+len-1)!='\n')  //too long                 //~v742I~
        {                                                       //~v742I~
			if (dbcsenv)	//DBCS mode                         //~v742I~
			 	printf("%s:%s:長過ぎる入力(%s)\n",pgmid,ver,recbuff);//~v742I~
    	    else	                                            //~v742I~
			 	printf("%s:%s:too long input(%s)\n",pgmid,ver,recbuff);//~v742R~
        	if (redirectsw)                                     //~v742I~
            	uexit(8);                                       //~v742R~
	        continue;                                           //~v742R~
        }                                                       //~v742I~
        if (len==1)                                             //~v742I~
        {                                                       //~v742I~
        	if (!redirectsw)                                    //~v742I~
            {                                                      //~v91mI~
				if (dbcsenv)	//DBCS mode                     //~v742I~
					printf("%s:%s:入力完了なら Ctrl+Z を押して下さい\n",pgmid,ver);//~v742I~
    		    else	                                        //~v742I~
					printf("%s:%s:enter Ctrl+Z if end of input\n",pgmid,ver);//~v742R~
            }                                                      //~v91mI~
            continue;                                           //~v742I~
		}                                                       //~v742I~
        *(recbuff+len-1)=0;                                     //~v742I~
//      if (findfile(recbuff))                                     //~v91kR~
//      if (findfile(xpparsehdrfnm(recbuff)))                      //~v91mR~
//      topspacectr=strspn(recbuff," \t");                         //~v954I~//~v9a0R~
        topspacectr=(int)strspn(recbuff," \t");                    //~v9a0I~
        pc=recbuff+topspacectr;                                    //~v954I~
        len-=topspacectr;                                          //~v954I~
        if (*pc=='#')                                              //~v954I~
            continue;                                              //~v954I~
//      poptstr=xpmult_indirectopt(0,recbuff,len-1);               //~v942I~//~v954R~
        poptstr=xpmult_indirectopt(0,pc,len-1);                    //~v954R~
        if (poptstr)                                               //~v942I~
        	*poptstr=0;	//for finedfile                            //~v942I~
 //     pc=xpparsehdrfnm(recbuff);//real filename start pos        //~v91mI~//~v953R~
        pc=xpparsehdrfnm(pc);//real filename start pos             //~v953I~
        rc=findfile2(FF2OPT_DIR,pc);//accept dir                   //~v91mI~
        if (poptstr)                                               //~v942I~
        	*poptstr=MULTI_SEPCINDIRECT1;	//new delimiter        //~v942R~
        if (rc==1)	//dir                                          //~v91mI~
        {                                                          //~v91mI~
        	strcat(pc,DIR_SEPS DIR_ALLMEMB);	//append wildcard  //~v91mI~
            len=(int)strlen(recbuff);                              //~v91mR~
        	rc=0;                                                  //~v91mI~
        }                                                          //~v91mI~
        if (rc)                                                    //~v91mI~
        {                                                       //~v742I~
        	if (redirectsw)                                     //~v742I~
            	uexit(8);                                       //~v742R~
	        continue;                                           //~v742R~
        }                                                       //~v742I~
//      fnmchain=malloc((UINT)(sizeof(FNMCHAIN)-1+len));        //~v742R~//~v9a0R~
        fnmchain=malloc((sizeof(FNMCHAIN)-1+(size_t)len));         //~v9a0I~
	    if (!fnmchain)                                          //~v742I~
    	{                                                       //~v742I~
	 		printf("%s:%s:malloc for indirect input file name area failed\n",pgmid,ver);//~v743R~
    		uexit(16);                                          //~v742I~
		}                                                       //~v742I~
        if (fnmchaino)                                          //~v742I~
	        fnmchaino->pnext=fnmchain;                          //~v742R~
		else                                                    //~v742I~
        	fnmchaintop=fnmchain;                               //~v742I~
        fnmchain->pnext=0;                                      //~v742I~
        fnmchaino=fnmchain;                                     //~v742I~
//      memcpy(fnmchain->fnm,recbuff,(UINT)len);                //~v742R~//~v954R~
        memcpy(fnmchain->fnm,pc,(UINT)len);                        //~v954I~
        tlen+=len;                                              //~v742I~
	}//until eof                                                //~v742I~
                                                                //~v742I~
    if (!tlen)                                                  //~v742I~
   	{                                                           //~v742I~
		if (dbcsenv)	//DBCS mode                             //~v742I~
 			printf("%s:%s:入力 0 件",pgmid,ver);                //~v742R~
    	else	                                                //~v742I~
 			printf("%s:%s:no input file specified\n",pgmid,ver);//~v742I~
   		uexit(16);                                              //~v742I~
	}                                                           //~v742I~
    if (Pfnm)                                                   //~v743I~
        fclose(fh);                                             //~v743I~
	pc=parmfname=malloc((UINT)tlen);                            //~v742I~
	if (!parmfname)                                             //~v742I~
   	{                                                           //~v742I~
	 	printf("%s:%s:malloc for indirect file name area failed\n",pgmid,ver);//~v743R~
   		uexit(16);                                              //~v742I~
	}                                                           //~v742I~
//  for (fnmchain=fnmchaintop;fnmchain;fnmchain=fnmchain->pnext)   //~v837R~
    for (fnmchain=fnmchaintop;fnmchain;)                           //~v837I~
	{                                                           //~v742I~
		len=(int)strlen(fnmchain->fnm);                         //~v742R~
        memcpy(pc,fnmchain->fnm,(UINT)len);                     //~v742I~
//      *(pc+len)='/';                                             //~v90aR~
//      *(pc+len)=MULTI_SEPC;   //multi file seperater             //~v90aI~//~v942R~
        *(pc+len)=MULTI_SEPCINDIRECT2;  //multi file seperater for indirect file parm//~v942I~
        pc+=len+1;                                              //~v742R~
        fnmchaino=fnmchain->pnext;   //next entry before free      //~v837R~
        free(fnmchain);                                         //~v742I~
        fnmchain=fnmchaino;   //next entry before free             //~v837I~
	}                                                           //~v742I~
    *(pc-1)=0;  //drop last "/" and set null term               //~v743I~
    UCBITON(swsw3,SW3FNMMALLOC);                                   //~v90eI~
	return parmfname;                                           //~v742R~
}//uindirect                                                    //~v743R~
                                                                //~v742I~
//**********************************************************************//~v742I~
//*get file name from stdin                                     //~v742I~
//      when LINUX:add wild card when dir name                     //~v90bI~
//*parm1:file name parameter                                    //~v742I~
//*ret  :multi file name list ptr                               //~v742I~
//**********************************************************************//~v742I~
char **umultifnlist(char *parmfname,int Pswreverse,int *Ppappendsw)//~v90bR~
{                                                               //~v742I~
	char *pc,**fntbl;                                           //~v743R~
    int ii,fcnt;                                                //~v742R~
//********                                                      //~v742I~
	*Ppappendsw=0;                                                 //~v90bI~
  	pc=parmfname;						//top addr v5.7a        //~v742R~
  	for (ii=0;*pc;pc++,ii++)                                    //~v742R~
//  	if (!(pc=strpbrk(pc,"/")))                                 //~v90aR~
//  	if (!(pc=strpbrk(pc,MULTI_SEPS)))                          //~v91kR~
    	if (!(pc=xpsrchsepc(pc)))                                  //~v91kI~
        	break;                                              //~v742I~
	if (!pc)		//last is not "/"                           //~v742I~
	    fcnt=ii+1;  //add last last                             //~v742I~
    else                                                        //~v742I~
	    fcnt=ii;                                                //~v742I~
//  fntbl=malloc((UINT)(sizeof(pc)*(fcnt+1)));                  //~v743R~//~v9a0R~
    fntbl=malloc((sizeof(pc)*((size_t)fcnt+1)));                   //~v9a0I~
    if (!fntbl)                                                 //~v743R~
    {                                                           //~v742I~
		printf("%s:%s:malloc for input file name list failed\n",pgmid,ver);//~v742R~
    	uexit(16);                                              //~v742R~
	}                                                           //~v742I~
  	pc=parmfname;						//top addr v5.7a        //~v742I~
    if (Pswreverse)                                             //~v742R~
	  	for (ii=fcnt-1;ii>=0;pc++,ii--)                         //~v742I~
    	{                                                       //~v742I~
			fntbl[ii]=pc;				//single file name ptr v5.7a//~v743R~
//  		if (pc=strpbrk(pc,"/"),pc)                             //~v90aR~
//  		if (pc=strpbrk(pc,MULTI_SEPS),pc)                      //~v91kR~
    		if (pc=xpsrchsepc(pc),pc)                              //~v91kI~
        		*pc=0;                                          //~v742I~
			xpmultdir(fntbl+ii,Ppappendsw);	//padd * for dir       //~v90bR~
    	}                                                       //~v742I~
    else                                                        //~v742I~
	  	for (ii=0;ii<fcnt;pc++,ii++)                            //~v742R~
    	{                                                       //~v742R~
			fntbl[ii]=pc;				//single file name ptr v5.7a//~v743R~
//  		if (pc=strpbrk(pc,"/"),pc)                             //~v90aR~
//    		if (pc=strpbrk(pc,MULTI_SEPS),pc)                      //~v91kR~
     		if (pc=xpsrchsepc(pc),pc)                              //~v91kI~
        		*pc=0;                                          //~v742R~
			xpmultdir(fntbl+ii,Ppappendsw);	//padd * for dir       //~v90bR~
    	}                                                       //~v742I~
  	fntbl[fcnt]=0;					//terminator v5.7a          //~v743R~
    return fntbl;                                               //~v743R~
}//umultifnlist                                                 //~v742I~
//**********************************************************************//~v91kI~
//*cut off one parm filename                                       //~v91kI~
//*ret  :none                                                      //~v91kI~
//**********************************************************************//~v91kI~
char *xpsrchsepc(char *Pparmstring)                                //~v91kR~
{                                                                  //~v91kI~
	char *pc,*pc2;                                                 //~v91kI~
//*******************                                              //~v91kI~
  if ((pc=strchr(Pparmstring,MULTI_SEPCINDIRECT1)))                //~v942R~
  {                                                                //~v942I~
    if (!(pc=strchr(Pparmstring,MULTI_SEPCINDIRECT2)))             //~v942I~
    	return 0;                                                  //~v942I~
  }                                                                //~v942I~
  else                                                             //~v942I~
  if (!(pc=strchr(Pparmstring,MULTI_SEPCINDIRECT2)))               //~v961I~
  {                                                                //~v961I~
    if (!(pc=strchr(Pparmstring,MULTI_SEPC)))                      //~v91kR~
    	return 0;                                                  //~v91kI~
  }                                                                //~v961I~
    pc2=strchr(Pparmstring,HDRFNM_PREFIX);                         //~v91kI~
    if (!pc2 || pc2>pc)		//    /...<                            //~v91kI~
    	return pc;                                                 //~v91kI~
// <.../                                                           //~v91kI~
    pc2=strchr(Pparmstring,HDRFNM_POSTFIX);  //serch end of <..>   //~v91kR~
    if (!pc2)		//no pair < and >                              //~v91kI~
    	uerrexit("invalid filename patern(%s)",0,                  //~v91kI~
        			Pparmstring);                                  //~v91kI~
    if (pc2<pc)		//    >../                                     //~v91kR~
    	return pc;                                                 //~v91kI~
// <.../.. >                                                       //~v91kI~
	return strchr(pc2,MULTI_SEPC);                                 //~v91kR~
}//xpsrchsepc                                                      //~v91kR~
//**********************************************************************//~v90bI~
//*for dirname,padd "*" to dirname when no wild card               //~v90bI~
//*parm1:file name parameter                                       //~v90bI~
//*ret  :none                                                      //~v90bI~
//**********************************************************************//~v90bI~
void xpmultdir(char **Ppfname,int *Ppappendsw)                     //~v90bR~
{                                                                  //~v90bI~
	char *pc,*pc2;                                                 //~v90bI~
	char *prealfn;  //filename specification dropped hdrfnm        //~v91kR~
    FILEFINDBUF3 ffstat3;                                          //~v90mR~
    int len;                                                       //~v90bI~
//*******************                                              //~v90bI~
	pc=*Ppfname;                                                   //~v90bI~
    if ((pc2=strchr(pc,MULTI_SEPCINDIRECT1)))                      //~v942R~
    	*pc2=0;                                                    //~v942I~
    prealfn=xpparsehdrfnm(pc);                                     //~v91kR~
    if (pc2)                                                       //~v942I~
        *pc2=MULTI_SEPCINDIRECT1;                                  //~v942I~
    if (WILDCARD(pc))                                              //~v90bI~
    	return;			//already with wildcard                    //~v90bI~
    if (pc2)                                                       //~v942I~
        *pc2=0;                                                    //~v942I~
//  if (ufstat(pc,&ffstat3))                                       //~v91kR~
    if (ufstat(prealfn,&ffstat3))                                  //~v91kR~
//  	uerrexit("%s notfound",0,                                  //~v90mR~
    {                                                              //~v90mI~
#ifdef W32UNICODE                                                  //~v990I~
    	uerrfprintfutf(0,Gmsgfile,"%s is not found\n",0,           //~v990I~
        		pc);                                               //~v990I~
#else                                                              //~v990I~
    	fprintf(Gmsgfile,"%s is not found\n",                      //~v90mR~
        		pc);                                               //~v90bI~
#endif                                                             //~v990I~
        exit(8);                                                   //~v90mI~
    }                                                              //~v90mI~
    if (pc2)                                                       //~v942I~
        *pc2=MULTI_SEPCINDIRECT1;                                  //~v942I~
    if (!(ffstat3.attrFile & FILE_DIRECTORY))	//not dir          //~v90mR~
    	return;                                                    //~v90bI~
    len=(int)strlen(pc);                                           //~v90mR~
//  pc2=malloc((UINT)(len+1+sizeof(DIR_ALLMEMB)+1));               //~v90mR~//~v9a0R~
    pc2=malloc(((size_t)len+1+sizeof(DIR_ALLMEMB)+1));             //~v9a0I~
    memcpy(pc2,pc,(UINT)len);                                      //~v90mR~
    if (*(pc2+len-1)!=DIR_SEPC)                                    //~v90bI~
    	*(pc2+len++)=DIR_SEPC;                                     //~v90bI~
    strcpy(pc2+len,DIR_ALLMEMB);                                   //~v90bI~
	*Ppfname=pc2;                                                  //~v90bI~
    *Ppappendsw=1;      //multiple input(include wildcard) v5.7r   //~v90bR~
    return;                                                        //~v90bI~
}//xpmultdir                                                       //~v90bI~
//**********************************************************************//~v942I~
//*get indirect file opt of each line                              //~v942I~
//*return end of filename addr                                     //~v942I~
//**********************************************************************//~v942I~
char *xpmult_indirectopt(int Popt,char *Precbuff,int Plen)         //~v942I~
{                                                                  //~v942I~
	char *pc,*pc2;                                                 //~v942I~
    int len;                                                       //~v942I~
    char *pc3;                                                     //~v954I~
//*******************                                              //~v942I~
//  pc3=memchr(Precbuff,'\t',Plen);                                //~v954R~//~v9a0R~
    pc3=memchr(Precbuff,'\t',(size_t)Plen);                        //~v9a0I~
//  pc=umemstr(Precbuff," /",Plen);                                //~v942I~//~v9a0R~
//  pc=umemstr(Precbuff," /",(size_t)Plen);                        //~v9a0I~//+v9a1R~
    pc=umemstr(Precbuff," /",(unsigned)Plen);                      //+v9a1I~
//  pc2=umemstr(Precbuff," -",Plen);                               //~v942I~//~v9a0R~
//  pc2=umemstr(Precbuff," -",(size_t)Plen);                       //~v9a0I~//+v9a1R~
    pc2=umemstr(Precbuff," -",(unsigned)Plen);                     //+v9a1I~
    if (!pc)                                                       //~v942I~
    	if (!pc2)                                                  //~v942I~
        {                                                          //~v954I~
           if (!pc3)                                               //~v954I~
        	return 0;                                              //~v942I~
           pc=pc3;                                                 //~v954I~
        }                                                          //~v954I~
        else                                                       //~v942I~
        	pc=pc2;                                                //~v942I~
    else                                                           //~v942I~
    	if (pc2 && pc2<pc)                                         //~v942I~
        	pc=pc2;                                                //~v942I~
    if (pc3 && pc3<pc)                                             //~v954I~
        pc=pc3;                                                    //~v954I~
//    len=(ULONG)pc-(ULONG)Precbuff;                                 //~v942I~//~v968R~
//    len=(ULPTR)pc-(ULPTR)Precbuff;                               //~v968I~//~v998R~
      len=(int)((ULPTR)pc-(ULPTR)Precbuff);                        //~v998I~
//  pc-=umemrspnc(Precbuff,' ',len);                               //~v942I~//~v9a0R~
//  pc-=umemrspnc(Precbuff,' ',(size_t)len);                       //~v9a0I~//+v9a1R~
    pc-=umemrspnc(Precbuff,' ',(unsigned)len);                     //+v9a1I~
    return pc;                                                     //~v942I~
}//xpmult_indirectopt                                              //~v942I~
//**********************************************************************//~v942I~
//*get indirect file opt of each line                              //~v942I~
//*return end of filename addr                                     //~v942I~
//**********************************************************************//~v942I~
char *xpmult_chkindirectopt(int Popt,char *Pfnm,int *Ppmaxcol)     //~v942R~
{                                                                  //~v942I~
	char *pc,*pce;                                            //~v942R~//~v953R~
	char *pmapfnm=0;                                               //~v953I~
static int Ssvasciimode=-1;                                        //~v942R~
static int Ssvebcdictype;                                          //~v942R~
static int Ssvrecordsz;                                            //~v942I~
static int Svfmt;                                                  //~v96eI~
static int Ssvdumpmode;                                            //~v942I~
static int Ssvnocrlfsw;                                            //~v942I~
static int Ssvmaxcol;                                              //~v942R~
static int Ssvtabskip;                                             //~v96yI~
static char *Ssvrecordszparm,*Ssvvfmtparm,*Ssvmodeparm;            //~v96eR~
    int swusecfg=0;                                                //~v953I~
//*******************                                              //~v942I~
    if (!UCBITCHK(swsw1,SW1INDIRECT))                              //~v942I~
        return 0;                                                  //~v942I~
	if (Ssvasciimode<0)                                            //~v942R~
    {                                                              //~v942I~
    	Ssvasciimode=asciimode;                                    //~v942R~
		Ssvebcdictype=Gebcdictype;                                 //~v942R~
		Ssvrecordsz=recordsz;                                      //~v942R~
		Svfmt=vfmt;                                                //~v96eI~
		Ssvdumpmode=dumpmode;                                      //~v942I~
		Ssvmaxcol=maxcol;                                          //~v942R~
		Ssvnocrlfsw=nocrlfsw;                                      //~v942I~
		Ssvrecordszparm=recordszparm;                              //~v96eI~
		Ssvvfmtparm=vfmtparm;                                      //~v96eI~
		Ssvmodeparm=modeparm;                                      //~v96eI~
		Ssvtabskip=tabskip;                                        //~v96yI~
    }                                                              //~v942I~
    else                                                           //~v942I~
    {                                                              //~v942I~
		Gebcdictype=Ssvebcdictype;                                 //~v942R~
        asciimode=Ssvasciimode;                                    //~v942R~
        recordsz=Ssvrecordsz;                                      //~v942R~
        vfmt=Svfmt;                                                //~v96eI~
		dumpmode=Ssvdumpmode;                                      //~v942I~
		maxcol=Ssvmaxcol;                                          //~v942R~
		nocrlfsw=Ssvnocrlfsw;                                      //~v942I~
		recordszparm=Ssvrecordszparm;                              //~v96eI~
		vfmtparm=Ssvvfmtparm;                                      //~v96eI~
		modeparm=Ssvmodeparm;                                      //~v96eI~
		tabskip=Ssvtabskip;                                        //~v96yI~
    }                                                              //~v942I~
	UCBITOFF(swsw4,SW4EBCCFG);                                     //~v942I~
    Gxpotheropt=0;                                                 //~v953R~
    Gxputfstat=0;                                                  //~v942R~
	Gebcdictype=0;                                                 //~v953I~
    UTRACEP("xpmult indirect parm=%s\n",Pfnm);                     //~v96eI~
    xpebc_getparmcvname(0,0);   //clear static codepage            //~v953I~
//*                                                                //~v942I~
	pc=strchr(Pfnm,MULTI_SEPCINDIRECT1);                           //~v942M~
    if (!pc)	//no option                                        //~v942M~
    	return 0;                                                  //~v942M~
    *pc++=0;                                                       //~v942M~
    for (;;)                                                       //~v942I~
    {                                                              //~v942I~
//      pc+=strspn(pc," ");                                        //~v942R~//~v954R~
        pc+=strspn(pc," \t");                                      //~v954R~
        if (!*pc)                                                  //~v942R~
            break;                                                 //~v942I~
        pc++;   //skip "/"                                         //~v942R~
//      pce=strchr(pc,' ');                                        //~v942I~//~v954R~
        pce=strpbrk(pc," \t");                                     //~v954R~
      if (USTRHEADIS_IC(pc,PARM_CPEB))    //icase CP=              //~v953R~
      {                                                            //~v953R~
          if (pce)                                                 //~v953M~
          	*pce=0;                                                //~v953M~
          xpebc_getparmcvname(0,pc);                               //~v953R~
          swusecfg=1;                                              //~v953I~
      }                                                            //~v953R~
      else                                                         //~v953I~
      if (USTRHEADIS_IC(pc,GOO_ASCEOLS))    //icase CP=            //~v953R~
      {                                                            //~v953R~
          if (pce)                                                 //~v953M~
          	*pce=0;                                                //~v953M~
          Gxpotheropt|=GOO_ASCEOL;                                 //~v953R~
      }                                                            //~v953R~
      else                                                         //~v953I~
      if (USTRHEADIS_IC(pc,GOO_EBCEOLS))    //icase CP=            //~v953I~
      {                                                            //~v953I~
          if (pce)                                                 //~v953I~
          	*pce=0;                                                //~v953I~
          Gxpotheropt&=~GOO_ASCEOL;                                //~v953I~
      }                                                            //~v953I~
      else                                                         //~v953I~
      if (USTRHEADIS_IC(pc,GOO_BC))    //icase CP=                 //~v953M~
      {                                                            //~v953M~
          if (pce)                                                 //~v953M~
          	*pce=0;                                                //~v953M~
          swusecfg|=2;                                             //~v953M~
          pmapfnm=pc+sizeof(GOO_BC)-1;                             //~v953M~
      }                                                            //~v953M~
      else                                                         //~v953M~
      {                                                            //~v953I~
        switch(*pc++)                                              //~v942R~
        {                                                          //~v942R~
        case 'M':                                                  //~v942R~
        case 'm':                                                  //~v942R~
        	modeparm=pc;                                           //~v96eI~
    	    if (pce)                                               //~v96eI~
          		*pce=0;                                            //~v96eI~
            switch(*pc++)                                          //~v942R~
            {                                                      //~v942R~
            case 'U':                                              //~v942R~
            case 'u':                                              //~v942R~
                Gxputfstat|=GXPUS_UTF8ON;                          //~v942R~
                break;                                             //~v942R~
            case 'E':                                              //~v942R~
            case 'e':                                              //~v942R~
//                pc2=ustrstri(pc,"BC");                             //~v942R~//~v953R~
//                if (!pc2)                                          //~v942R~//~v953R~
//                    uerrexit("indirect file option err, missing BC option for EBCDIC file",0);//~v942R~//~v953R~
////              pce=strchr(pc2,' ');                               //~v942R~//~v954R~//~v953R~
//                pce=strpbrk(pc2," \t");                            //~v954I~//~v953R~
//                if (pce)                                           //~v942I~//~v953R~
//                    *pce=0;                                        //~v942I~//~v953R~
////              xpebc_init(0,pc2+2);                               //~v942R~//~v953R~
////              Gebcdictype=3;                                     //~v942R~//~v953R~
//                pmapfnm=pc2+2;                                   //~v953R~
                swusecfg|=1;                                       //~v953I~
                break;                                             //~v942R~
            default:                                               //~v942R~
                uerrexit("indirect file option err(%s)",0,         //~v942R~
                        pc-2);                                     //~v942R~
            }                                                      //~v942R~
                                                                   //~v942R~
            break;                                                 //~v942R~
        case 'R':                                                  //~v942I~
        case 'r':                                                  //~v942I~
        	if (pce)                                               //~v96eI~
    	      	*pce=0;                                            //~v96eI~
      		recordsz=atoi(pc); //conv to integer                   //~v942R~
            if (!recordsz)                                         //~v942I~
	            uerrexit("indirect file option err(%s)",0,         //~v942I~
                    pc-1);                                         //~v942I~
            recordszparm=pc-1;                                     //~v96eI~
            maxcol=recordsz;                                       //~v942R~
            *Ppmaxcol=recordsz;                                    //~v942I~
			nocrlfsw=1;		//ignore crlf                          //~v942I~
            dumpmode=1;                                            //~v942I~
            break;                                                 //~v942I~
        case 'V':                                                  //~v96eI~
        case 'v':                                                  //~v96eI~
        	if (pce)                                               //~v96eI~
    	      	*pce=0;                                            //~v96eI~
	        vfmtparm=pc-1;                                         //~v96eI~
    		chkvfmtparm(pc);                                       //~v96eR~
			nocrlfsw=1;		//ignore crlf                          //~v96eI~
            dumpmode=1;                                            //~v96eI~
            break;                                                 //~v96eI~
        default:                                                   //~v942R~
            uerrexit("indirect file option err(%s)",0,             //~v942R~
                    pc-1);                                         //~v942R~
        }                                                          //~v942R~
      }//hdr_is                                                    //~v953I~
        if (!pce)                                                  //~v942R~
            break;                                                 //~v942I~
        pc=pce+1;                                                  //~v942R~
    }                                                              //~v942I~
//  if (pmapfnm)                                                   //~v953R~
    Gxpotheropt&=~(GOO_EBCBYUCS|GOO_EBCBYUCS_UTF8);                //~v96zI~
    if (swusecfg)                                                  //~v953I~
    {                                                              //~v953I~
		Gebcdictype=3;                                             //~v953I~//~v954M~
		xpebc_init(0,pmapfnm);                                     //~v953I~
    }                                                              //~v953I~
    return pc;                                                     //~v942I~
}//xpmult_indirectopt                                              //~v942I~
