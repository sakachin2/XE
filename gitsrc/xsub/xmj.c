//CID://+vas3R~:     update#=     8                                //+vas3R~
//*************************************************************
//*xmj.c
//* merge join 2 file
//*************************************************************
//vas3:230630 ARM;closeall for arm subthread execution             //+vas3I~
//vaa0:160417 Lnx compiler warning                                 //~vaa0I~
//va67:120628 VC10-32 compile(va66 for also 32bit)                 //~va67I~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va58:111217 compiler warning,uninitialized                       //~va58I~
//va4g:091103 xmj:1.2 compile err at ubuntu9.10;getline conflict with stdio.h//~va4gI~
//*va27:050425 xmj:v1.1 dos compile err(shorten buffsz)            //~va27I~
//*0003:-ooutfnm;outfile parm for override chk                     //~0002I~
//*0002:set expand to max record size for file1 to optional(/Yf)   //~0002I~
//*0001:/Ym option for master(file1) is uniq key and conbine to all//~5414R~
//      same key transaction(file2)                                //~5414I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef UNX                                                         //~0002I~
	#include <unistd.h>                                            //~0002I~
#else                                                              //~0002I~
#include <conio.h>                                                 //~0002I~
#endif                                                             //~0002I~
                                                                   //~0002I~
#if defined(DOS) || defined(W32)                                   //~0002I~
	#include <dos.h>                                               //~0002I~
    #ifdef DPMI                                                    //~0002I~
    	#include <errno.h>                                         //~0002I~
    #endif                                                         //~0002I~
#else                                                              //~0002I~
    #define INCL_DOSFILEMGR  //DCPY_EXISTING                       //~0002I~
    #include <os2.h>                                               //~0002I~
#endif                                                             //~0002I~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ufile5.h>                                                //~0002I~
#include <ualloc.h>
#include <uedit.h>
#include <ustring.h>
#include <uparse.h>
#include <ucalc.h>
#include <ucalc2.h>

//*******************************************************
#define VER "V1.3"   //version                                     //~va4gR~//~vaa0R~
#define PGM "xmj"

#define HELPMSG         uerrhelpmsg(stdout,stderr,
#ifdef DOSDOS                                                      //~va27I~
	#define    MAXBUFFSZ  12288     //12k                          //~va27I~
#else                                                              //~va27I~
#define    MAXBUFFSZ  65536
#endif                                                             //~va27I~
#define    MAXKEYSZ   4096
#define    MAXKEYNO   10                                           //~5328I~
#define    MAXSEPSZ   32                                           //~5328R~
//*******************************************************
static char *Spgm=PGM,*Sver=VER;
static FILE *Sfh1=0,*Sfh2=0,*Sfho=0;                               //~0002R~
static char *Sfnm[2]={0,0};
static int Skeypos[2][MAXKEYNO];                                   //~5328R~
static int Ssubkeylen[MAXKEYNO];                                   //~5328I~
static int Skeyno=0;                                               //~5328I~
static int Sreadctr[2]={0,0},Sshortkeyctr[2]={0,0},Sdupkeyctr[2]={0,0};//~5327R~
static int Sf1onlyctr=0,Sf2onlyctr=0,Swritectr=0,Sjoinctr=0;
static int Skeylen=0;                                              //~5328R~
static int Sfile2sw=1;	//output file2 line also                   //~5328I~
static int Sswkeyout=0; //output file2 line also                   //~5328I~
static int Sswnoconf=0;                                            //~0002I~
static int Sswmaster=0; //master/transaction matching              //~5414I~
static int Sswfixlen=1; //expand file1 record size to max file     //~0002I~
static char Sseps[MAXSEPSZ]=" : ";                                 //~5328R~
static int  Sseplen=0;                                             //~5328I~
static char *Spoutfnm=0,Soutfnm[_MAX_PATH]="";                     //~0002R~
//*******************************************************
void parmprechk(int parmc,char *parmp[]);
int parmchk(int Popdno,char **Ppopd);
int parmflagchk(char *Popd);                                       //~5327I~
int mjmain(void);
int help(void);
int opderr(char *Pparm);                                           //~5327I~
int getmaxlrecl(char *Pfnm,FILE *Pfh,char *Pbuff,int Pbuffsz);     //~5327I~
//int getline(int Pfileid,FILE *Pfh,char *Pbuff,int Pbuffsz,char *Pkey);//~va4gR~
int xmj_getline(int Pfileid,FILE *Pfh,char *Pbuff,int Pbuffsz,char *Pkey);//~va4gI~
int getkey1parm(char *Popd);                                       //~5328I~
int getkey2parm(char *Popd);                                       //~5328I~
FILE *openoutfile(char **Pppfnmo,char *Prename);                   //~0002I~
char confirm(char *Pmsg,char *Preply);                             //~0002I~
//****************************************************************
// calc body
//*rc   :0
//****************************************************************
int main(int parmc,char * parmp[])
{
    int rc;
	char pgmver[16];                                               //~5330I~
//*********************************
	sprintf(pgmver,"%s:%s(%c): ",PGM,VER,OSTYPE);                  //~5330I~
	uerrmsg_init(pgmver,stderr,0);//msg to stderr                  //~5330I~
	uerrexit_init(pgmver,stderr,0,0,0);//stderr only,no pathmsg    //~5330I~
	uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit       //~5330I~
	parmprechk(parmc,parmp);
	if (parmchk(parmc,parmp))
    	return 4;
    rc=mjmain();
    fprintf(stderr,"%s: %d read, %d dupkey, %d shortkey\n", 
    				Sfnm[0],Sreadctr[0],Sdupkeyctr[0],Sshortkeyctr[0]);
    fprintf(stderr,"%s: %d read, %d dupkey, %d shortkey\n", 
    				Sfnm[1],Sreadctr[1],Sdupkeyctr[1],Sshortkeyctr[1]);
    fprintf(stderr,"%d joind,%d file1 only,%d file2 only, total %d written\n",
    				Sjoinctr,Sf1onlyctr,Sf2onlyctr,Swritectr);
	ARMXSUB_CLOSE(PGM);	//close for Arm subthread execution                                          //~v6B1I~//~vas2I~//+vas3I~
    return rc;
}//main
//**********************************************************************
//*parameter chk
//**********************************************************************
void parmprechk(int parmc,char *parmp[])
{
    int parmno;
  	char ch,*cptr; 
//************************************************
	for (parmno=1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
#ifdef UNX
  		if(*cptr=='-')
#else
  		if(*cptr=='/'||*cptr=='-')
#endif
  		{//option
    		ch=*(++cptr);                      //first option byte
    		switch(toupper(ch))             //option
    		{
    		case '?':
        		help();
                break;
    		case 'Y':
        	  	while(ch=*(++cptr),ch)
              	{
    				switch(toupper(ch))             //option
                	{
                	case '9':
                    	UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                    	UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs
                		break;
                	}
              	}
                break;
    		case 'N':
        	  	while(ch=*(++cptr),ch)
              	{
    				switch(toupper(ch))             //option
                	{
                	case '9':
                    	UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                   		UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs
                		break;
                    }
              	}	
                break;
            }//sw
    	}//flag
	}//for all parm
}//parmprechk
//****************************************************************
// calc fmt opd chk
//*rc   :0
//****************************************************************
int parmchk(int Popdno,char **Ppopd)
{
    char *pc;
    int  ii;                                                       //~5405R~
    int  posparmno=0;                                              //~5405R~
//*********************************
    if (Popdno<=1)
        help();
    for (ii=1;ii<Popdno;ii++)                                      //~5411R~
    {
    	pc=Ppopd[ii];                                              //~5411I~
    	if (*pc==CMDFLAG_PREFIX || *pc==CMDFLAG_PREFIX2)	//flag parm               //~v19DI~
        {
			if (parmflagchk(pc+1))
                return opderr(pc);
        }
        else
        {
        	switch (posparmno)
            {
            case 0:
            	Sfnm[0]=pc;
                break;
            case 1:
            	Sfnm[1]=pc;
                break;
            default:
            	uerrexit("too many positinal parameter(%s)",0,pc);
            }
            posparmno++;
        }
    }
    if (posparmno!=2)
    	uerrexit("specify 2 input filename",0);
    if (!Skeylen)                                                  //~5329I~
    	uerrexit("missing key parameter",0);                       //~5329I~
    Sfh1=fopen(Sfnm[0],"r");
    if (!Sfh1)
    	uerrexit("%s open failed",0,Sfnm[0]);                      //~5327R~
    Sfh2=fopen(Sfnm[1],"r");
    if (!Sfh2)
    	uerrexit("%s open failed",0,Sfnm[1]);                      //~5327R~
    if (Spoutfnm)                                                  //~0002I~
        Sfho=openoutfile(&Spoutfnm,Soutfnm);                       //~0002I~
    else                                                           //~0002I~
    	Sfho=stdout;                                               //~0002I~
    return 0;
}//parmchk                                                         //~5329R~
//**********************************************************************//~0002I~
//*open outputfile                                                 //~0002I~
//**********************************************************************//~0002I~
FILE *openoutfile(char **Pppfnmo,char *Prename)                    //~0002I~
{                                                                  //~0002I~
    FILEFINDBUF3 fstat3;                                           //~0002I~
	char *pfnmo;                                                   //~0002I~
    FILE *fho;                                                     //~0002I~
    char confmsg[_MAX_PATH+128];                                   //~0002I~
    int rc;                                                        //~0002I~
//******************                                               //~0002I~
	pfnmo=*Pppfnmo;                                                //~0002I~
    if (WILDCARD(pfnmo))                                           //~0002I~
    {                                                              //~0002I~
        ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,Sfnm[0],pfnmo,Prename);    //src,patern,output//~0002R~
   		fprintf(stderr,"*** output : %s --> %s ***\n",             //~0002I~
    					pfnmo,Prename);                            //~0002R~
        pfnmo=Prename;                                             //~0002I~
        *Pppfnmo=pfnmo;                                            //~0002I~
    }                                                              //~0002I~
                                                                   //~0002I~
    if (!ufstat(pfnmo,&fstat3))                                    //~0002I~
    {                                                              //~0002I~
        if (fstat3.attrFile & FILE_DIRECTORY)                      //~0002I~
            uerrexit("%s is directory",0,                          //~0002I~
                        pfnmo);                                    //~0002I~
      if (!Sswnoconf)                                              //~0002I~
      {                                                            //~0002I~
        sprintf(confmsg,"%s exist,override? Yes/No?",pfnmo);       //~0002I~
        rc=confirm(confmsg,"YyNn");                                //~0002I~
        if (rc=='N'||rc=='n')                                      //~0002I~
            exit(1);                                               //~0002I~
      }                                                            //~0002I~
    }                                                              //~0002I~
    fho=fopen(pfnmo,"w");                                          //~0002I~
    if (!fho)                                                      //~0002I~
        uerrexit("%s open failed,rc=%d",0,                         //~0002I~
                    pfnmo,errno);                                  //~0002I~
    return fho;                                                    //~0002I~
}//openoutfile                                                     //~0002I~
//****************************************************************
// flag parm chk
//*rc   :0  ,4
//****************************************************************
int parmflagchk(char *Popd)
{
static int Skeyctr=0;                                              //~5327I~
	char *pc;                                                      //~5328R~
    int ch,rc=0;                                                   //~5328R~
//***************************
    pc=Popd;
    switch(toupper(*pc))                                       //~5323I~
    {                                                          //~5323I~
    case 'K':		//matching key
    	pc++;
        Skeyctr++;
    	switch(Skeyctr)
        {
        case 1:
            rc=getkey1parm(pc);                                    //~5328R~
        	break;
        case 2:
            rc=getkey2parm(pc);                                    //~5328R~
        	break;
        default:
        	uerrexit("too many key parameter",0);
        }
        break;
    case 'O':		//matching key                                 //~0002I~
    	Spoutfnm=pc+1;                                             //~0002R~
        break;                                                     //~0002I~
    case 'S':		//matching key
    	strncpy(Sseps,pc+1,MAXSEPSZ);                              //~5328R~
        break;
    case 'Y':                                                  //~5323I~
        while(ch=*(++pc),ch)
        {
            switch(toupper(ch))             //option
            {
            case '2':                                              //~5328R~
                Sfile2sw=1;                                        //~5328R~
                break;                                             //~5328I~
            case '9':                                              //~5328I~
                break;                                             //~5328I~
            case 'C':                                              //~0002I~
            	Sswnoconf=0;                                       //~0002I~
                break;                                             //~0002I~
            case 'F':                                              //~0002I~
                Sswfixlen=1;                                       //~0002I~
                break;                                             //~0002I~
            case 'K':                                              //~5328I~
                Sswkeyout=1;                                       //~5328I~
                break;                                             //~5328I~
            case 'M':                                              //~5414I~
                Sswmaster=1;                                       //~5414I~
                break;                                             //~5414I~
            default:
	            opderr(Popd);
            }
        }
        break;
    case 'N':                                                  //~5323I~
        while(ch=*(++pc),ch)
        {
            switch(toupper(ch))             //option
            {
            case '2':                                              //~5328I~
                Sfile2sw=0;                                        //~5328I~
                break;                                             //~5328I~
            case '9':
                break;
            case 'C':                                              //~0002I~
            	Sswnoconf=1;                                       //~0002I~
                break;                                             //~0002I~
            case 'F':                                              //~0002I~
                Sswfixlen=0;                                       //~0002I~
                break;                                             //~0002I~
            case 'K':                                              //~5328I~
                Sswkeyout=0;                                       //~5328I~
                break;                                             //~5328I~
            case 'M':                                              //~5414I~
                Sswmaster=0;                                       //~5414I~
                break;                                             //~5414I~
            default:
	            opderr(Popd);
            }
        }
        break;
    default:                                                   //~5323I~
        return 4;
    }                                                          //~5323I~
    return rc;                                                     //~5328R~
}//fmtopdchk4
//**************************************************************** //~5328I~
// get multiple key parm of file1                                  //~5328I~
//*rc   :0                                                         //~5328I~
//**************************************************************** //~5328I~
int getkey1parm(char *Popd)                                        //~5328I~
{                                                                  //~5328I~
	char chsv=0,*pc,*pc2,*pcn;                                       //~5328R~//~va64R~
    int  pos1,pos2;                                                //~5411R~
    int keyno=0,keylen=0;                                          //~0002R~
//******************                                               //~5328I~
	for (pc=Popd;;)                                                //~5328I~
    {                                                              //~5328I~
    	pcn=strchr(pc,':');                                        //~5328I~
        if (pcn)                                                   //~5328I~
        {                                                          //~5328I~
        	chsv=*pcn;                                             //~5328I~
            *pcn=0;                                                //~5328I~
        }                                                          //~5328I~
    	if (ugetnumrange3(pc,&pos1,&pos2,&pc2)>1)    //num err     //~0002R~
        	return 4;                                              //~5328I~
        if (keyno>=MAXKEYNO)                                       //~5328I~
        {                                                          //~5328I~
	        uerrmsg("too many key parm,max is %d",0,MAXKEYNO);     //~5328I~
    	    return 4;                                              //~5328I~
        }                                                          //~5328I~
    	Skeypos[0][keyno]=pos1-1;                                  //~5328I~
    	Skeypos[1][keyno]=pos1-1;	//file2 default                //~5328I~
    	Ssubkeylen[keyno]=pos2-Skeypos[0][keyno];                  //~5328R~
        keylen+=Ssubkeylen[keyno];                                 //~5328R~
        keyno++;                                                   //~5328M~
        if (!pcn)                                                  //~5328I~
        	break;                                                 //~5328I~
        *pcn++=chsv;                                               //~5328I~
    	pc=pcn;                                                    //~5328I~
    }                                                              //~5328I~
    if (keylen>MAXKEYSZ)                                           //~5328I~
    {                                                              //~5328I~
        uerrmsg("max total key length is %d",0,MAXKEYSZ);          //~5328I~
        return 4;                                                  //~5328I~
    }                                                              //~5328I~
    Skeyno=keyno;                                                  //~5328I~
    Skeylen=keylen;                                                //~5328I~
    return 0;                                                      //~5328I~
}//getkey1parm                                                     //~5328I~
//**************************************************************** //~5328I~
// get multiple key parm of file2                                  //~5328I~
//*rc   :0                                                         //~5328I~
//**************************************************************** //~5328I~
int getkey2parm(char *Popd)                                        //~5328I~
{                                                                  //~5328I~
	char chsv=0,*pc,*pc2,*pcn;                                       //~5328R~//~va64R~
    int pos1,pos2;                                                 //~5411R~
    int keyno=0;                                                   //~0002R~
//******************                                               //~5328I~
	for (pc=Popd;;)                                                //~5328I~
    {                                                              //~5328I~
    	pcn=strchr(pc,':');                                        //~5328I~
        if (pcn)                                                   //~5328I~
        {                                                          //~5328I~
        	chsv=*pcn;                                             //~5328I~
            *pcn=0;                                                //~5328I~
        }                                                          //~5328I~
        if (ugetnumrange3(pc,&pos1,&pos2,&pc2)!=1)    //num err    //~0002R~
            return 4;                                              //~5328I~
        Skeypos[1][keyno]=pos1-1;                                  //~5328I~
        if (keyno>=MAXKEYNO)                                       //~5328I~
        {                                                          //~5328I~
	        uerrmsg("too many key parm,max is %d",0,MAXKEYNO);     //~5328I~
    	    return 4;                                              //~5328I~
        }                                                          //~5328I~
        if (keyno>Skeyno)                                          //~5328I~
        {                                                          //~5328I~
	        uerrmsg("too many file2 key over file1 key count(%d)",0,Skeyno);//~5328R~
    	    return 4;                                              //~5328I~
        }                                                          //~5328I~
    	Skeypos[1][keyno]=pos1-1;	//file2 default                //~5328I~
        keyno++;                                                   //~5328I~
        if (!pcn)                                                  //~5328I~
        	break;                                                 //~5328I~
        *pcn++=chsv;                                               //~5328I~
    	pc=pcn;                                                    //~5328I~
    }                                                              //~5328I~
    return 0;                                                      //~5328I~
}//getkey2parm                                                     //~0002R~
//****************************************************************
// 1 table calc
//*rc   :0   or 1:data err or 4:env err or UALLOC_FAILED
//****************************************************************
int mjmain(void)
{
	int    maxlrecl1,len,len1,len2,compsw;                         //~0002R~
    char   *pc;                                                    //~5327R~
    char  key1[MAXKEYSZ+MAXSEPSZ],key2[MAXKEYSZ+MAXSEPSZ];         //~5328R~
    char *buff1,*buff2,*buff3;                                     //~5327I~
    int swmatched=0;                                               //~5414I~
//*********************************
    maxlrecl1=0;                                                   //~va58R~
    Sseplen=(int)strlen(Sseps);                                    //~0002R~
    memset(key1,0,sizeof(key1));                                   //~5327I~
    memset(key2,0,sizeof(key2));                                   //~5327I~
    buff1=umalloc((MAXBUFFSZ+MAXSEPSZ)*4);                         //~5328R~
    buff2=buff1+MAXBUFFSZ+MAXSEPSZ;                                //~5328R~
    buff3=buff2+MAXBUFFSZ+MAXSEPSZ;                                //~5328R~
                                                                   //~0002I~
  if (Sswfixlen) //expand file1 record size to max file            //~0002I~
	maxlrecl1=getmaxlrecl(Sfnm[0],Sfh1,buff1,MAXBUFFSZ);           //~5327R~
    fseek(Sfh1,0,SEEK_SET);		//back to top of file                                                               //~v40RI~
//  len1=getline(1,Sfh1,buff1,MAXBUFFSZ,key1);                     //~va4gR~
    len1=xmj_getline(1,Sfh1,buff1,MAXBUFFSZ,key1);                 //~va4gI~
//  len2=getline(2,Sfh2,buff2,MAXBUFFSZ,key2);                     //~va4gR~
    len2=xmj_getline(2,Sfh2,buff2,MAXBUFFSZ,key2);                 //~va4gI~
    for (;;)
    {
    	compsw=memcmp(key1,key2,(UINT)Skeylen);	                   //~0002R~
        switch(compsw)
        {
        case 0:	//match
        	if (len1<0)	//eof
            	break;
//key output                                                       //~5328I~
			if (Sswkeyout)                                         //~5328I~
            {                                                      //~5328I~
	            memcpy(key1+Skeylen,Sseps,(UINT)Sseplen);          //~0002R~
				fwrite(key1,1,(UINT)(Skeylen+Sseplen),Sfho);       //~0002R~
            }                                                      //~5328I~
            memcpy(buff3,buff1,(UINT)len1);                        //~0002R~
            pc=buff3+len1;
  		  	if (!Sswfixlen) //expand file1 record size to max file //~0002R~
	          	maxlrecl1=len1;                                    //~0002I~
            if (maxlrecl1>len1)
//          	memset(pc,' ',(UINT)maxlrecl1-len1);               //~5327R~//~vaa0R~
            	memset(pc,' ',(size_t)(maxlrecl1-len1));           //~vaa0I~
            pc=buff3+maxlrecl1;
            memcpy(pc,Sseps,(UINT)Sseplen);                        //~0002R~
            pc+=Sseplen;                                           //~5328R~
            memcpy(pc,buff2,(UINT)len2);                           //~0002R~
            pc+=len2;
            *pc++='\n';
//          len=(int)((ULONG)pc-(ULONG)buff3);                     //~va66R~
            len=(int)((ULPTR)pc-(ULPTR)buff3);                     //~va66I~
			fwrite(buff3,1,(UINT)len,Sfho);                        //~0002R~
            Sjoinctr++;                                            //~5327R~
            Swritectr++;
          if (Sswmaster)                                           //~5414R~
          {                                                        //~5414I~
            swmatched=1;                                           //~5414R~
//  		len2=getline(2,Sfh2,buff2,MAXBUFFSZ,key2);             //~va4gR~
    		len2=xmj_getline(2,Sfh2,buff2,MAXBUFFSZ,key2);         //~va4gI~
          }                                                        //~5414I~
          else                                                     //~5414I~
          {                                                        //~5414I~
//  	    len1=getline(1,Sfh1,buff1,MAXBUFFSZ,key1);             //~va4gR~
    	    len1=xmj_getline(1,Sfh1,buff1,MAXBUFFSZ,key1);         //~va4gI~
//  		len2=getline(2,Sfh2,buff2,MAXBUFFSZ,key2);             //~va4gR~
    		len2=xmj_getline(2,Sfh2,buff2,MAXBUFFSZ,key2);         //~va4gI~
          }                                                        //~5414I~
            break;
        case 1:	//key1>key2                                        //~5327I~
            if (Sfile2sw)                                          //~5328I~
            {                                                      //~5328I~
                if (Sswkeyout)                                     //~5328I~
                {                                                  //~5328I~
                    memcpy(key2+Skeylen,Sseps,(UINT)Sseplen);      //~0002R~
                    fwrite(key2,1,(UINT)(Skeylen+Sseplen),Sfho);   //~0002R~
                }                                                  //~5328I~
  		     if (Sswfixlen) //expand file1 record size to max file //~0002I~
                memset(buff3,' ',(UINT)maxlrecl1);                 //~5328R~
             else                                                  //~0002I~
             	maxlrecl1=0;                                       //~0002I~
                pc=buff3+maxlrecl1;                                //~5328R~
                memcpy(pc,Sseps,(UINT)Sseplen);                    //~0002R~
                pc+=Sseplen;                                       //~5328R~
                memcpy(pc,buff2,(UINT)len2);                       //~0002R~
                pc+=len2;                                          //~5328R~
                *pc++='\n';                                        //~5328R~
//              len=(int)((ULONG)pc-(ULONG)buff3);                 //~5328R~//~va66R~
                len=(int)((ULPTR)pc-(ULPTR)buff3);                 //~va66I~
                fwrite(buff3,1,(UINT)len,Sfho);                    //~0002R~
                Sf2onlyctr++;                                      //~5328R~
                Swritectr++;                                       //~5328R~
            }                                                      //~5328I~
                                                                   //~5327M~
//  		len2=getline(2,Sfh2,buff2,MAXBUFFSZ,key2);             //~va4gR~
    		len2=xmj_getline(2,Sfh2,buff2,MAXBUFFSZ,key2);         //~va4gI~
            break;                                                 //~5327M~
        default:	//key1<key2                                    //~5327R~
            if (swmatched)  //after read trx after matched         //~5414I~
            {                                                      //~5414I~
//  			len1=getline(1,Sfh1,buff1,MAXBUFFSZ,key1);         //~va4gR~
    			len1=xmj_getline(1,Sfh1,buff1,MAXBUFFSZ,key1);     //~va4gI~
                swmatched=0;                                       //~5414I~
                break;                                             //~5414I~
            }                                                      //~5414I~
            if (Sswkeyout)                                         //~5328I~
            {                                                      //~5328I~
                memcpy(key1+Skeylen,Sseps,(UINT)Sseplen);          //~0002R~
                fwrite(key1,1,(UINT)(Skeylen+Sseplen),Sfho);       //~0002R~
            }                                                      //~5328I~
  	        pc=buff1+len1;                                         //~5327R~
  		  	if (!Sswfixlen) //expand file1 record size to max file //~0002R~
	          	maxlrecl1=len1;                                    //~0002I~
            if (maxlrecl1>len1)                                    //~5327R~
//          	memset(pc,' ',(UINT)maxlrecl1-len1);               //~5327R~//~vaa0R~
            	memset(pc,' ',(size_t)(maxlrecl1-len1));           //~vaa0I~
            pc=buff1+maxlrecl1;
            memcpy(pc,Sseps,(UINT)Sseplen);                        //~0002R~
            pc+=Sseplen;                                           //~5328R~
            *pc++='\n';
//          len=(int)((ULONG)pc-(ULONG)buff1);                     //~va66R~
            len=(int)((ULPTR)pc-(ULPTR)buff1);                     //~va66I~
			fwrite(buff1,1,(UINT)len,Sfho);                        //~0002R~
            Sf1onlyctr++;                                          //~5327R~
            Swritectr++;

//  		len1=getline(1,Sfh1,buff1,MAXBUFFSZ,key1);             //~va4gR~
    		len1=xmj_getline(1,Sfh1,buff1,MAXBUFFSZ,key1);         //~va4gI~
            break;
        }//sw                                                      //~5327R~
        if (len1<0 && len2<0)   //both eof                         //~5327I~
            break;                                                 //~5327I~
    }
    return 0;
}//fmtmain
//****************************************************************
// get valid plh
//*rc   :-1:eof or readlen except last \n
//****************************************************************
int getmaxlrecl(char *Pfnm,FILE *Pfh,char *Pbuff,int Pbuffsz)
{
	int len,maxlen=0;
//*********************************
	*(Pbuff+Pbuffsz-1)=0;
    for (;;)
    {                                                              //~5323R~
	    if (!fgets(Pbuff,Pbuffsz-1,Pfh))                             //~5323R~
        	break;
    	len=(int)strlen(Pbuff);                                    //~0002R~
        len--;		//for \n                                       //~5323I~
        if (len>maxlen)
        	maxlen=len;
    }
    return maxlen;
}//getmaxlrecl
//****************************************************************
// get valid plh
//*rc   :-1:eof or readlen except last \n
//****************************************************************
//int getline(int Pfileid,FILE *Pfh,char *Pbuff,int Pbuffsz,char *Pkey)//~va4gR~
int xmj_getline(int Pfileid,FILE *Pfh,char *Pbuff,int Pbuffsz,char *Pkey)//~va4gI~
{
static char Soldkey[2][MAXKEYSZ];                                  //~5327R~
	char *poldkey;
	int fileindex,keypos,keylen,len,rc,ii,keyoffs,subkeylen;       //~5328R~
//*********************************
	fileindex=Pfileid-1;
	*(Pbuff+Pbuffsz-1)=0;
	if (!fgets(Pbuff,Pbuffsz-1,Pfh))                               //~5327R~
    {
    	memset(Pkey,0xff,(UINT)Skeylen);                           //~0002R~
    	return -1;
    }
    Sreadctr[fileindex]++;
    poldkey=Soldkey[fileindex];
    len=(int)strlen(Pbuff);                                        //~0002R~
    len--;		//for \n                                       //~5323I~
    memset(Pkey,0,(UINT)Skeylen);                                  //~0002R~
    for (ii=0,keyoffs=0;ii<Skeyno;ii++)                            //~5328I~
    {                                                              //~5328I~
	    keypos=Skeypos[fileindex][ii];                             //~5328I~
	    subkeylen=Ssubkeylen[ii];                                  //~5328R~
        if (keypos<len) //key contains                             //~5328R~
        {                                                          //~5328R~
            keylen=len-keypos;                                     //~5328R~
            if (keylen<subkeylen)                                  //~5328R~
                Sshortkeyctr[fileindex]++;                         //~5328R~
            else                                                   //~5328R~
                keylen=subkeylen;                                  //~5328R~
            memcpy(Pkey+keyoffs,Pbuff+keypos,(UINT)keylen);        //~0002R~
        }                                                          //~5328R~
        keyoffs+=subkeylen;                                        //~5328R~
    }                                                              //~5328I~
    rc=memcmp(Pkey,poldkey,(UINT)Skeylen);
    if (!rc)
    {                                                              //~5414I~
        if (Sswmaster && !fileindex)                               //~5414I~
            uerrexit("%s key not unique err at line %d under master/transaction matching mode.",0,//~5414I~
                    Sfnm[fileindex],Sreadctr[fileindex]);          //~5414I~
    	Sdupkeyctr[fileindex]++;
    }                                                              //~5414I~
    else
    	if (rc<0)		//seqdown
		{
        	uerrexit("%s key sequence down detected at line %d.",0,//~5327R~
					Sfnm[fileindex],Sreadctr[fileindex]);
        }
    memcpy(poldkey,Pkey,(UINT)Skeylen);                            //~5327I~
    return len;
}//xmj_getline                                                     //~va4gR~
//****************************************************************
int opderr(char *Pparm)
{
    uerrexit("parm(%s) err",0,Pparm);
    return 4;
}//opderr
//**********************************************************************//~0002I~
//* confirm                                                        //~0002I~
//**********************************************************************//~0002I~
char confirm(char *Pmsg,char *Preply)                              //~0002I~
{                                                                  //~0002I~
    char  reply,*pc;                                               //~0002I~
//**********                                                       //~0002I~
    uerrmsg(Pmsg,Pmsg);                                            //~0002I~
	for (;;)                                                       //~0002I~
    {                                                              //~0002I~
#ifdef UNX                                                         //~0002I~
        while(kbhit())                                             //~0002I~
	    	getch_nc();  //getch not under curses                  //~0002I~
#else                                                              //~0002I~
#ifdef DOS                                                         //~0002I~
        while(kbhit())                                             //~0002I~
	    	getch();                                               //~0002I~
#else                                                              //~0002I~
	#ifdef W32                                                     //~0002I~
        while(_kbhit())                                            //~0002I~
	    	_getch();                                              //~0002I~
    #else                                                          //~0002I~
        while(_kbhit())                                            //~0002I~
	    	_getch();                                              //~0002I~
    #endif                                                         //~0002I~
#endif                                                             //~0002I~
#endif                                                             //~0002I~
        printf("===>");                                            //~0002I~
        fflush(stdout);                                            //~0002I~
#ifdef UNX                                                         //~0002I~
    	reply=(UCHAR)getch_nc();                                   //~0002I~
#else                                                              //~0002I~
#ifdef DOS                                                         //~0002I~
    	reply=(UCHAR)getch();                                      //~0002I~
#else                                                              //~0002I~
	#ifdef W32                                                     //~0002I~
    	reply=(UCHAR)_getch();                                     //~0002I~
    #else                                                          //~0002I~
    	reply=(UCHAR)_getch();                                     //~0002I~
    #endif                                                         //~0002I~
#endif                                                             //~0002I~
#endif                                                             //~0002I~
        if (!reply)         //pf-key etc                           //~0002I~
            reply=' ';                                             //~0002I~
        printf("%c\n",reply);                                      //~0002I~
    	pc=strchr(Preply,reply);                                   //~0002I~
        if (pc)                                                    //~0002I~
        	break;                                                 //~0002I~
    	uerrmsg("Invalid reply.",                                  //~0002I~
    	    	"無効な入力.");                                    //~0002I~
	}                                                              //~0002I~
    return reply;                                                  //~0002I~
}//confirm                                                         //~0002I~
//****************************************************************
// hel for fmt
//*ret :0
//****************************************************************
int help(void)
{
        HELPMSG
"%s : %s=(%c)= 2 file matching and join matching line.\n",
"%s : %s=(%c)= ２つのファイルを照合し行を連結する。\n",
                Spgm,Sver,OSTYPE);
        HELPMSG
"format:%s [%cYx %cNx] %cKl-m[:l-m] [%cKn[:n]] [%cSseps] file1 file2\n",//~5328R~
"形式  :%s [%cYx %cNx] %cKl-m[:l-m] [%cKn[:n]] [%cSseps] file1 file2\n",//~5328R~
                Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,                //~5328R~
                CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);     //~5328I~
        HELPMSG
" %cK     :matcing key column. l-m: file1 key start end end col. n:file2 key pos.\n",//~5328R~
" %cK     :照合キー位置指定。l-m:file1のキー開始終了桁位置。n:file2の開始桁位置。\n",//~5328R~
				CMDFLAG_PREFIX);
        HELPMSG                                                    //~5328I~
"         concatinate by \":\" when multiple ky.\n",               //~5328R~
"         キーが複数あるときは\":\"でつないで指定する。\n");       //~5328R~
        HELPMSG
" %cOoutfn:output filename. default is stdout.\n",                 //~0002I~
" %cOoutfn:出力ファイル名。省略値は 標準出力。\n",                 //~0002I~
				CMDFLAG_PREFIX);                                   //~0002I~
        HELPMSG                                                    //~0002I~
" %cS     :seperator of joined matched line. default is \"%s\".\n",//~5328R~
" %cS     :キーが一致した行を連結するときのセパレータ。省略値は\"%s\"。\n",//~5328R~
				CMDFLAG_PREFIX,Sseps);
        HELPMSG                                                    //~5328I~
" %cYx,%cNx:other flag option. default is in parethesis.\n",       //~5328R~
" %cYx,%cNx:その他のフラグオプション。括弧内が省略値。\n",         //~5328R~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);                    //~5328I~
        HELPMSG                                                    //~5328I~
"         x=2:output also unmatched file2 lines.(%cY2).\n",        //~5328R~
"         x=2:照合しないfile2の行も出力する。(%cY2)。\n",          //~5328R~
				CMDFLAG_PREFIX);                                   //~5328I~
        HELPMSG                                                    //~0002I~
"         x=f:expand file1 part on output line to max line size of file1(%cYf).\n",//~0002I~
"         x=f:出力のfile1部をfile1の最大行サイズに広げる。(%cYf)。\n",//~0002I~
				CMDFLAG_PREFIX);                                   //~0002I~
        HELPMSG                                                    //~5328I~
"         x=k:output (agregated) key at col1.(%cNk).\n",           //~5328R~
"         x=k:(連結)照合キーをカラム１に出力する。(%cNk)。\n",     //~5328R~
				CMDFLAG_PREFIX);                                   //~5328I~
        HELPMSG                                                    //~5414I~
"         x=m:Do master/transaction matching.(%cNm).\n",           //~5414I~
"         x=m:マスター/トランザクション照合をする。(%cNm)。\n",    //~5414I~
				CMDFLAG_PREFIX);                                   //~5414I~
        HELPMSG                                                    //~5414I~
"             Master(file1) key should be unique,and multiple transaction(file2)\n",//~5414I~
"             マスター(file1)のキーはユニークでなければならず,トランザクション\n",//~5414R~
				CMDFLAG_PREFIX);                                   //~5414I~
        HELPMSG                                                    //~5414I~
"             generate each combined with unique master record.\n",//~5414I~
"             (file2)は対応するマスターと連結されて出力される。\n",//~5414R~
				CMDFLAG_PREFIX);                                   //~5414I~
        HELPMSG                                                    //~5414I~
"             (When /Nm,next record of each file is read after key matched)\n",//~5414I~
"             (/Nmの場合キーが一致iすると両方のファイルの次の行が照合される。)\n",//~5414R~
				CMDFLAG_PREFIX);                                   //~5414I~
        HELPMSG                                                    //~5328I~
"sample) %s %cYk %cN2 %cK5-9:20-22 %cK5:30 %cS\" ++ \" file1 file2\n",//~5328R~
"    例) %s %cYk %cN2 %cK5-9:20-22 %cK5:30 %cS\" ++ \" file1 file2\n",//~5328R~
                Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,                //~5328I~
                CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);     //~5328I~
    exit(1);
//#ifndef ULIB64X	//C4702 unreachable warning                        //~va66I~//~va67R~
#ifndef VC10EXP	//C4702 unreachable warning                        //~va67I~
    return 0;
#endif                                                             //~va66I~
}//help
