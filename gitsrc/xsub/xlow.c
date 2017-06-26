//*CID://+va70R~:                             update#=   55;       //+va70R~
//*************************************************************
//*xlower
//* rename filename to lower
//*************************************************************
//va70:121022 udosfindnext was changed by symlink support          //+va70I~
//va58:111217 compiler warning,uninitialized                       //~va58I~
//va2i:060821 xlow:1.4 add uppercase translation option            //~va2iI~
//*031021 xlow v1.3 (BUG) 2nd wild card file is not processed      //~v1.3I~
//*020908 xlow v1.2 dbcs name consideration                        //~v1.2I~
//*020504 xlow v1.1 add list option                                //~v1.1I~
//*************************************************************
#define VERSION  "v1.5"                                            //~va2iR~//+va70R~
#define PGMID    "xlow"
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
	#ifdef W32
		#include <dos.h>
	#else
	#endif
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ufile2.h>
#include <ualloc.h>
#include <udbcschk.h>
//****************************************************************
static	char *Spgm=PGMID;
static	char *Sver=VERSION;
static	int   Srenamefilectr=0;
static	int   Srenamedirctr=0;
static  int   Sopt=0;
#define  XLOPT_DIR  0x01		//rename dir
#define  XLOPT_LIST 0x02		//list only                        //~v1.1I~
#define  XLOPT_UPPER 0x04   	//uppercase                        //~va2iI~
//****************************************************************
void help(void);
int parmchk(int parmc,char *parmp[]);
int getpfnm(int parmc,char *parmp[]);
int renlower(char *Pfnm);
int renwc(char *Pfnm,int Ppathlen,FILEFINDBUF3 *Ppfstat3);
int rensub(char *Pfnm,FILEFINDBUF3 *Ppfstat3);
//****************************************************************
// calc body
//*rc   :0
//****************************************************************
int main(int parmc,char *parmp[])
{
	int ii,rc;
//*********************************
    uerrmsg_init("",stdout,0);//msg to stdout
    uerrexit_init("",stdout,0,0,0);//stdout only,no pathmsg
  	parmchk(parmc,parmp);
	for (rc=0;!rc;)
    {
    	ii=getpfnm(parmc,parmp);
        if (!ii)
        	break;
        rc=renlower(parmp[ii]);
        rc=0;   //continue even if not found                       //~v1.3I~
	}
  if (Sopt & XLOPT_LIST)	//list only                            //~v1.1I~
    uerrmsg("Uppercase entry: %d file(s), %d dir(s).",             //~v1.1I~
            "大文字は %d ファイル,  %d ディレクトリー 。",         //~v1.1I~
			Srenamefilectr,Srenamedirctr);                         //~v1.1I~
  else                                                             //~v1.1I~
    uerrmsg("Renamed   %d file(s), %d dir(s).",
            "%d ファイル,  %d ディレクトリー を改名。",
			Srenamefilectr,Srenamedirctr);
    return rc;
}//main
//**********************************************************************
//*parameter chk
//**********************************************************************
int parmchk(int parmc,char *parmp[])
{
  	unsigned char c;    //read char
  	char *cptr;         //char ptr work
  	char *pc;         //char ptr work
  	int parmno; //parm count work
  	int posparmno=0; //parm count work
//*************************
  	if (parmc<2 || *parmp[1]=='?')
  	{
    	help();
    	exit(0);
  	}
//*******************************
//* parm process                *
//*******************************
	for (parmno=1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
#ifdef UNX
  		if(*cptr=='-')
#else
  		if(*cptr=='/'||*cptr=='-')
#endif
  		{//option
    		c=*(++cptr);                      //first option byte
    		switch(toupper(c))             //option
    		{
//**************************
//* subdir option          *
//**************************
    		case '?':
    		case 'H':
	    		help();
    			exit(0);
      			break;
    		case 'D':
                Sopt|=XLOPT_DIR;
      			break;
    		case 'L':                                              //~v1.1I~
                Sopt|=XLOPT_LIST;                                  //~v1.1I~
      			break;                                             //~v1.1I~
    		case 'U':                                              //~va2iI~
                Sopt|=XLOPT_UPPER;                                 //~va2iI~
      			break;                                             //~va2iI~
    		case 'Y':
        		for (pc=cptr+1;*pc;pc++)
        		{
            		switch(toupper(*pc))
            		{
            		case '9':
               			break;
            		}
        		}
        		break;
            case 'N':
                for (pc=cptr+1;*pc;pc++)
                {
                    switch(toupper(*pc))
                    {
                    case '9':
						uerrmsg_init("",stdout,UERR_FORCE_ENGLISH);
                        break;
                    }
                }
                break;
            default:                           //not option
              	uerrexit("parm(%s) err\n",0,
						 parmp[parmno]);
            }//switch  by first option byte
  		}
  		else
  		{//positional parmno
    		posparmno++;
    	}//switch by parmno
	}//for all parm
  	if (!posparmno)
	{
      	help();
    	exit(0);
	}
    return 0;
}//parmchk
//**********************************************************************
//*get parameter filename
//**********************************************************************
int getpfnm(int parmc,char *parmp[])
{
  	char *cptr;         //char ptr work
  	int parmno; //parm count work
static int Slastno=0;
//*******************************
	for (parmno=Slastno+1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
#ifdef UNX
  		if(*cptr=='-')
#else
  		if(*cptr=='/'||*cptr=='-')
#endif
			continue;
        Slastno=parmno;
        return Slastno;
	}//for all parm
    return 0;
}//getpfnm
//**********************************************************************
//*file process
//**********************************************************************
int renlower(char *Pfnm)
{
	FILEFINDBUF3 fstat3;
    HDIR hdir;  //dir handle  //v1.4r
    int rc,pathlen;
//*******************************
	if (WILDCARD(Pfnm))
    {
    	pathlen=PATHLEN(Pfnm);
        if (pathlen<0)
        	pathlen=0;
	    rc=(int)udosfindfirst(Pfnm,&hdir,FILE_ALL,&fstat3);
     if (!rc)                                                      //~v1.3I~
     {                                                             //~v1.3I~
        while (!rc)
        {
		    if (strcmp(fstat3.achName,".")                         //~1603R~
    		&&  strcmp(fstat3.achName,".."))                       //~1603R~
 		       	renwc(Pfnm,pathlen,&fstat3);                       //~1603R~
//    		rc=(int)udosfindnext(hdir,&fstat3);                    //+va70R~
      		rc=(int)udosfindnext(Pfnm,hdir,&fstat3);               //+va70I~
        }
        rc=0;                                                      //~v1.3I~
      }                                                            //~v1.3I~
    }
    else
    {
    	rc=(int)ufstat(Pfnm,&fstat3);                              //~1930R~
        if (rc)
            uerrmsg("%s not found",
                    "%s が見つかりません",
					Pfnm);
        else
    		rc=rensub(Pfnm,&fstat3);
    }
    return rc;
}//renlower
//**********************************************************************
//*wild card process
//**********************************************************************
int renwc(char *Pfnm,int Ppathlen,FILEFINDBUF3 *Ppfstat3)
{
	char fnm[_MAX_PATH];
//*******************************
	memcpy(fnm,Pfnm,(UINT)Ppathlen);
    if (Ppathlen>0)
        if (*(fnm+Ppathlen-1)!=DIR_SEPC)
            *(fnm+Ppathlen++)=DIR_SEPC;
#ifdef W32
    strcpy(fnm+Ppathlen,Ppfstat3->cFileName);  //winname
#else
    strcpy(fnm+Ppathlen,Ppfstat3->achName);    //filename only
#endif                                                             //~1603R~
    return rensub(fnm,Ppfstat3);
}//renwc
//**********************************************************************
//*wild card process
//**********************************************************************
int rensub(char *Pfnm,FILEFINDBUF3 *Ppfstat3)
{
	char newfnm[_MAX_PATH];
	char dbcsid[_MAX_PATH];                                        //~v1.2I~
    int len,rc;
    int len2,ii;                                                   //~v1.2I~
    char *pc,*pcd;                                                 //~v1.2I~
    char renmsg[_MAX_PATH*2+32];
//*******************************
    rc=0;                                                          //~va58I~
    if (Ppfstat3->attrFile & FILE_DIRECTORY)
    	if (!(Sopt & XLOPT_DIR))
        		return 0;
	len=PATHLEN(Pfnm);
    if (len<0)
    	len=0;
	strcpy(newfnm,Pfnm);
//  strlwr(newfnm+len);                                            //~v1.2R~
    len2=(int)strlen(newfnm);                                      //~v1.2I~
    usetdbcstbl(USDT_CODE_DEFAULT,newfnm,dbcsid,len2);             //~v1.2I~
    for (ii=0,pc=newfnm,pcd=dbcsid;ii<len2;ii++,pc++,pcd++)        //~v1.2R~
    	if (*pcd!=UDBCSCHK_DBCS1ST && *pcd!=UDBCSCHK_DBCS2ND)      //~v1.2I~
        {                                                          //~va2iI~
          if (Sopt & XLOPT_UPPER)                                  //~va2iI~
        	*pc=(char)toupper(*pc);                                //~va2iI~
          else                                                     //~va2iI~
        	*pc=(char)tolower(*pc);                                //~v1.2I~
        }                                                          //~va2iI~
	if (!strcmp(Pfnm+len,newfnm+len))
    	return 0;
  if (Sopt & XLOPT_LIST)	//list only                            //~v1.1I~
  {	                                                               //~v1.1I~
	    if (Ppfstat3->attrFile & FILE_DIRECTORY)                   //~v1.1I~
        {                                                          //~v1.1I~
            uerrmsg("(D):%s",0,                                    //~v1.1I~
            		Pfnm);                                         //~v1.1I~
    		Srenamedirctr++;                                       //~v1.1I~
        }                                                          //~v1.1I~
        else                                                       //~v1.1I~
        {                                                          //~v1.1I~
            uerrmsg("(F):%s",0,                                    //~v1.1I~
            		Pfnm);                                         //~v1.1I~
    		Srenamefilectr++;                                      //~v1.1I~
        }                                                          //~v1.1I~
  }                                                                //~v1.1I~
  else                                                             //~v1.1I~
  {                                                                //~v1.1I~
    rc=urename(Pfnm,newfnm,0);
    if (!rc)
    {
        sprintf(renmsg,"%-32s==> %s",Pfnm,newfnm+len);             //~1603R~
	    if (Ppfstat3->attrFile & FILE_DIRECTORY)
        {
            uerrmsg("(D):%s",0,
            		renmsg);
    		Srenamedirctr++;
        }
        else
        {
            uerrmsg("(F):%s",0,
            		renmsg);
    		Srenamefilectr++;
        }
    }
  }//list or rename                                                //~v1.1I~
    return rc;
}//rensub
//****************************************************************
// help msg
//*rc   :0
//****************************************************************
void help(void)
{
#define HELPMSG uerrhelpmsg(stdout,stderr,
//************
HELPMSG
"%s:%s:==(%c)== Rename filename to Lower or Upper case (%s) ========\n",//~va2iR~
"%s:%s:==(%c)== ファイル名を小文字または大文字に改名 (%s) ==========\n",//~va2iR~
            Spgm,Sver,OSTYPE,__DATE__);
HELPMSG
"Format: %s [%cd] filespec [ filespec ... ]\n",
"形式: %s [%cd] filespec [ filespec ... ]\n",
			Spgm,CMDFLAG_PREFIX);
HELPMSG
"             filespec:file,dir or wildcard\n",
"           filespec:ファイル名、Dir名、ワイルドカード\n");
HELPMSG
"             %cd      :rename also dirname.\n",
"           %cd      :Dir名 も改名\n",
			CMDFLAG_PREFIX);
HELPMSG                                                            //~v1.1I~
"             %cL      :list only.\n",                             //~v1.1I~
"           %cL      :\x95\\示のみ。\n",                           //~v1.1R~
			CMDFLAG_PREFIX);                                       //~v1.1I~
HELPMSG                                                            //~va2iI~
"             %cU      :rename to Uppercase.\n",                   //~va2iI~
"           %cU      :大文字に改名。\n",                           //~va2iI~
			CMDFLAG_PREFIX);                                       //~va2iI~
	return;
}//help
