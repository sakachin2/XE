//*CID://+vas4R~:                            update#=  298;        //~vas4R~
//*************************************************************
//*xfmt.c
//* extract data from input by column or fieldno specification
//*************************************************************
//vas4:230701 (Bug) xfmt on UNX, issue specify input for /xxx      //~vas4I~
//vas3:230630 ARM;closeall for arm subthread execution             //~vas3I~
//va67:120628 VC10-32 compile(va66 for also 32bit)                 //~va67I~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va58:111217 compiler warning,uninitialized                       //~va58I~
//va4f:091103 xfmt:1.4 compile err at ubuntu9.10;getline conflict with stdio.h//~va4fI~
//va45:080901 xfmt:1.3 (BUG)use "'" if start/end string contains ":"//~va45R~
//va44:080901 xfmt:1.3 (BUG)alignment fail for the field of left align and point align//~va45R~
//va2e:051211 xfmt:1.2 v66v:051211 (BUG)tc fmt;delm drop when delm continued//~va2eI~
//va29:050516:xfmt:v1.1(BUG)include/exclude err dtermination after skipped//~va29I~
//va28:050425:xfmt:v1.1 dos compile err(too large stack)           //~va28I~
//*0035:0034-2                                                     //~0035I~
//*0034:keep num field at last for numonly field                   //~0034I~
//*0033:(BUG of 0030) /na 1-9 copy record,so reject because no /ys used//~0033I~
//*0032:/l[n]+str support for also start/end                       //~0032I~
//*0031:/l[n]+str support                                          //~0031R~
//*0030:simple copy when /na and /ns                               //~0030I~
//*0029:"C" and "N" is now independent                             //~0029R~
//*0028:(BUG)for "C" non numeric field has last delm               //~0028I~
//*0027:no confirm option  /nc                                     //~0027I~
//*0026:excluded line output option /xexceptionfile                //~0026I~
//*0025:/l[n]&str support                                          //~0025I~
//*0024:for binary file(strstr->memstr)                            //~0024I~
//*0023:option to split by fixed record length /Rnn                //~0023I~
//*0022:replace input delimiter option /SR"  "                     //~0022I~
//*0021:split nonfmt field when /na                                //~0021I~
//*0020:terminating fldstr support; fldno:[X]{[t|e][-]{a|b}string|column}[:{[t|e][-]{a|b}string|Llen|column}]//~0020I~
//*0019:support fld end by pos not by len                          //~0019I~
//*0018:reduce field width for fldstr specification aligned case   //~0018I~
//*0017:terminating fldstr support; fldno:[X]{[t|e][-]{a|b}string|column}[:{[t|e][-]{a|b}string|Llen|column}]//~0017I~
//*0016:reverse search option for fldstr search.                   //~0016I~
//*0015:option for the line fldstr not found; ignore or full line  //~0014I~
//*0014:field column specification by string; fldno:[{{a|b}string|column}][:len]//~0014I~
//*0013:chnge offset parm to cols                                  //~0013I~
//*0012:substring cut from intermediate area                       //~0012I~
//*0011:substring cut option by minus len                          //~0011I~
//*0010:field substring option not only for align option. fldno[:[-]offs[:len]]//~0010I~
//*0009:outputfile wildcard support(rename)                        //~0009I~
//*0008:ABEND when no delm when /q option                          //~0008I~
//*0007:fieldNo count err for non fmt field when delm is not space //~0007I~
//*0006:change space is not always delm,idelm parm override it     //~0006I~
//*0005:output override confirm                                    //~0004I~
//*0004:outputfilename support                                     //~0004I~
//*0003:output field max len support                               //~0003I~
//*input delm:always " \t",specify additional delimiter by -i parm
//*-q (nod or s) means both s and d
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef UNX                                                         //~0004I~
	#include <unistd.h>                                            //~0004I~
#else                                                              //~0004I~
#include <conio.h>                                                 //~0004I~
#endif                                                             //~0004I~
                                                                   //~0004I~
#if defined(DOS) || defined(W32)                                   //~0004I~
	#include <dos.h>                                               //~0004I~
    #ifdef DPMI                                                    //~0004I~
    	#include <errno.h>                                         //~0004I~
    #endif                                                         //~0004I~
#else                                                              //~0004I~
    #define INCL_DOSFILEMGR  //DCPY_EXISTING                       //~0004I~
    #include <os2.h>                                               //~0004I~
#endif                                                             //~0004I~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ualloc.h>
#include <uedit.h>
#include <ustring.h>
#include <uparse.h>
#include <ucalc.h>
#include <ucalc2.h>
#include <ufile5.h>                                                //~0009I~

//*******************************************************
#define VER "V1.5"   //version                                     //~va4fR~//~vas4R~
#define PGM "xfmt"

#define HELPMSG         uerrhelpmsg(stdout,stderr,
#ifdef DOSDOS                                                      //~va28I~
	#define    MAXBUFFSZ  16384		//16K                          //~va28I~
#else                                                              //~va28I~
#define    MAXBUFFSZ  65536
#endif                                                             //~va28I~
#define    MAXSTRINGPARM   100
#define MAXFIELD          99
#define MAXEXTRACT       199
#define TOPSPACELEN        1                                       //~v40RR~
#define DEFAULT_SPACELEN   2                                       //~v40RR~
#define FMTFLAG_FMT       0x80                                     //~v51xR~
#define FMTFLAG_NUMONLY   0x40                                     //~v51xI~
#define FMTFLAG_COMPRESS  0x20                                     //~v51xI~
#define FMTFLAG_LEFTALIGN 0x10                                     //~v51xI~
#define FMTFLAG_RIGHTALIGN 0x08                                    //~v51xI~
#define FMTFLAG_POINTALIGN 0x04 //right align ajusted by decimal pint//~v597I~
#define FMTFLAG_OVERFLOW   0x02 //no fmt                           //~v62gR~

#define PARM_NXSW          0
#define PARM_MAXFLDNO      1
//#define PARM_MAXDATALEN    2
#define PARM_SPACELEN      3
#define PARM_HDRSW         4                                       //~v40RI~
//#define PARM_TBLSZ         5                                     //~v5fwR~
#define PARM_SETHDR      0x01                                      //~v51oI~
#define PARM_DQUOTE      0x02    //chk double quotation            //~v580I~
#define PARM_SQUOTE      0x04    //chk single quotation            //~v580I~
#define PARM_NUMONLYFLD  0x08    //numonly fld exist               //~v5fwI~
//deefine PARM_DELM          5     //delimiter parm                  //~v5fwI~
#define PARM_TBLSZ         6                                       //~v5fwI~
//#define PARM_NUMONLY     0x02                                    //~v51xR~
//#define PARM_COMPRESS    0x04                                    //~v51xR~
                                                                   //~v51oI~
//*******************************************************
static char *Spgm=PGM,*Sver=VER;
static FILE *Sfh=0,*Sfho=0,*Sfho2=0;                               //~0026R~
static int  Sreadline=0,Swriteline=0,Sskipctr=0,Sshortlinectr=0;
static char *Spfnm=0,*Spfnmo=0,*Spfnmo2=0;                         //~0033R~
static char  Sfnmo[_MAX_PATH],Sfnmo2[_MAX_PATH];                   //~0026I~
static char Sstridelm[32]=" \t";
static char *Sstrodelm=" "; 	//default_spacelen=1                  //~0006R~
static char *Sstrxstart=0;
static char *Sstrxend=0;
static int   Sstrxstartcols=0,Sstrxstartlen=0;
static int   Sstrxendcols=0,Sstrxendlen=0;
static int   Sstrselectctr=0;
static char *Sstrselect[MAXSTRINGPARM];
static int   Sstrselectflag[MAXSTRINGPARM];
static int   Sstrselectcols[MAXSTRINGPARM];
static int   Sstrselectlen[MAXSTRINGPARM];
static int   Sfieldmaxlen[MAXFIELD]; //field max length parm       //~0003I~
static int   Sfieldcutoffs[MAXFIELD]; //substring startoffset      //~0010I~
static int   Sfieldendoffs[MAXFIELD]; //substring startoffset      //~0019I~
static int   Sfieldstrlen[MAXFIELD]; //fldstr parm strlen          //~0014I~
static int   Sfieldstrlen2[MAXFIELD]; //fldstr parm strlen         //~0020I~
static char *Sfieldstr[MAXFIELD]; //fldstr parm                    //~0014I~
static char *Sfieldstr2[MAXFIELD]; //end fldstr parm               //~0017I~
static int   Sfieldopt2[MAXFIELD]; //option flag 2                 //~0014I~
#define      SFO2_STARTAFTER   0x0001    //field start cols is ater fldstring//~0019R~
#define      SFO2_STARTTOP     0x0002    //field start cols is top of line if fldstr not found//~0019R~
#define      SFO2_STARTEND     0x0004    //field start cols is end of line if fldstr not found//~0019R~
#define      SFO2_REVSEARCH    0x0008    //substr reverse search   //~0020R~
#define      SFO2_EXCLUDE      0x0010    //substring exclude       //~0020R~
#define      SFO2_SUBSTRENDCOL 0x0020    //substring end cols by length parm//~0020R~
#define      SFO2_SUBSTRLEN    0x0040    //substring length parm   //~0020R~
#define      SFO2_STARTAFTER2  0x0080    //field start cols is ater fldstring//~0020I~
#define      SFO2_STARTTOP2    0x0100    //field start cols is top of line if fldstr not found//~0020I~
#define      SFO2_STARTEND2    0x0200    //field start cols is end of line if fldstr not found//~0020I~
#define      SFO2_REVSEARCH2   0x0400    //substr reverse search   //~0020I~
#define      SFO2_ENDSTR       0x0800    //end fldstr parm exist   //~0020I~
static int   Sextfieldtbl[MAXEXTRACT]; //field spec sequence
static int   Sextfieldtblindex=0; //field spec sequence
static int   Sextlastpos=0;	//extract shorlinectr up chk 
static int   Sswnoalign=0;
static int   Sskipxout=0;                                          //~0026I~
static int   Sswextract=0;	//extract(rearange selected field only)
static int   Sswnoconf=0;                                          //~0027I~
static int   Sswrepdelm=0;	//replace input delimiter              //~0022I~
static int   Slrecl=0;		//RECFM=F record length                //~0023I~
static int Sstartsw=0,Sendsw=0;                                    //~0032M~
//*******************************************************
void parmprechk(int parmc,char *parmp[]);
FILE *openoutfile(char **Pppfnmo,char *Prename);                   //~0026I~
int opdchk(int Popdno,char **Ppopd,int *Pparm,char *Pfmtfldtbl);
int help(void);
//int getline(int Pinitsw,char *Pbuff,int Pbuffsz,int *Pparm);     //~va4fR~
int xfmt_getline(int Pinitsw,char *Pbuff,int Pbuffsz,int *Pparm);  //~va4fI~
int writeout2(char *Pbuff,int Plen);                               //~0026I~
int fmtmain(int *Pparm,char *Pfmtfldtbl);                             //~v40MR~
int splitmain(int *Pparm);                                         //~0023R~
int fmtopdchk4(char *Popd);
int fmtopdchk3(char *Popd,int *Pparm);
int fmtfldstrparmchk(int Pstartcolsw,char *Popd,int *Ppopt,int *Ppfldstrlen,char **Pppfldstr);//~0020I~
int opderr(char *Pparm);
int tc_fmtopdchk2(int *Pparm,char *Popd,int *Plastpos,int *Pnextpos,char *Pfmtfldtbl,int *Ppfmtfldsw);//~v5fwI~
int tc_chkfieldwidth(int *Pparm,char *Plinedata,int Plinelen,int *Pfmttb,int Pparmmaxfldno,int *Pmaxfldno,//~v5fwR~
    					int *Pmaxlrecl,char *Pfmtfldtbl);          //~v5fwI~
char *tc_chknonfmtfieldwidth(int *Pparm,char *Prec,int Preclen,char *Pfmtfldtbl,int *Ppfldno,int *Ppfldlen,int *Ppnofmtsw);//~v580I~
char *tc_getfieldendaddr(int *Pparm,char *Prec,int Preclen,char *Ppcwdata,int *Ppcomplen,int Pfmtflag,LONG *Pnumval,int *Ppnumlen,char **Ppnumfld);//~0034R~
char *tc_getfieldendaddrquote(char *Prec,int Preclen,char *Pdelmstr,char *Pdelmaddr,int Popt);//~0006R~
int  tc_fmtdatasub(char *Plinedata,int Plinelen,int *Pnewlen,int *Pparm,//~v5fwI~
    		int *Pfmttb,char *Pfmtfldtbl,char *Pwdata,char *Ppcwdata,int *Pextoffstbl,int *Pextoffstblindex);//~v5fwI~
int extractdata(int *Pparm,char *Pfmtline,char *Pextdataline,int *Pextoffstbl,int Pextoffstblindex);
char confirm(char *Pmsg,char *Preply);                             //~0004I~
int getsubstrbyfldstr(int Pfldno,char *Pflddata,int Pnetlen,int *Ppfldstrlen);//~0020R~
int getsubstrbyfldstr2(int Pfldno,char *Pflddata,int Pnetlen,int *Ppfldstroffs);//~0020I~
int getsubstrfieldlen(int Pfldno,int Pnetlen,int Pstartoffs,char *Pflddata,int *Ppfldlen,int *Px1stlen);//~0020R~
int seandchk(int Ptyp,char *Pbuff,int Plen);                       //~0032I~
//****************************************************************
// calc body
//*rc   :0
//****************************************************************
int main(int parmc,char * parmp[])
{
    int rc;
    int parmtb[PARM_TBLSZ];
    char fmtfldtbl[MAXFIELD*4+1];                                  //~0034R~
               //fieldlen,up digit,over up digit count,numonly field last num fieldlen//~0034I~
	char pgmver[16];                                               //~0003I~
//*********************************
	Sfho=stdout;                                                   //~0021I~
	sprintf(pgmver,"%s:%s(%c): ",PGM,VER,OSTYPE);                  //~0003I~
	uerrmsg_init(pgmver,stderr,0);//msg to stderr                  //~0003I~
	uerrexit_init(pgmver,stderr,0,0,0);//stderr only,no pathmsg    //~0003I~
	uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit       //~0003I~
    memset(fmtfldtbl,0,sizeof(fmtfldtbl));    //right justify
	parmprechk(parmc,parmp);
    if (rc=opdchk(parmc,parmp,parmtb,fmtfldtbl),rc)
    	return rc;                      //err
    if (Spfnmo)                                                    //~0004I~
        Sfho=openoutfile(&Spfnmo,Sfnmo);                           //~0026R~
    else                                                           //~0009I~
    	Spfnmo="stdout";                                           //~0009R~
    if (Spfnmo2)                                                   //~0026I~
        Sfho2=openoutfile(&Spfnmo2,Sfnmo2);                        //~0026I~
    else                                                           //~0026I~
    	Spfnmo2="null";                                            //~0026I~
  if (Slrecl)                                                      //~0023I~
    rc=splitmain(parmtb);                                          //~0023R~
  else                                                             //~0023I~
    rc=fmtmain(parmtb,fmtfldtbl);
    if (Sstrxstart && !Sstartsw)                                   //~0032I~
        uerrmsg("No Start record found",0);                        //~0032I~
    else                                                           //~0032I~
        if (Sstrxend && !Sendsw)                                   //~0032R~
            uerrmsg("No End record found",0);                      //~0032R~
    if (!rc)
    {                                                              //~0004I~
    	uerrmsg("*** Done *** %s --> %s , %s  *** \n    read:%d, write:%d, excluded:%d, short-line:%d",0,//~0026R~
        		Spfnm,Spfnmo,Spfnmo2,Sreadline,Swriteline,Sskipctr,Sshortlinectr);//~0026R~
    }                                                              //~0004I~
//    IF_ARMXSUB_CLOSE(PGM,                                          //~vas3I~//~vas4R~
//    {                                                              //~vas3I~//~vas4R~
//        fclose(Sfh);                                               //~vas3I~//~vas4R~
//        if (Sfho!=stdout)                                          //~vas3I~//~vas4R~
//             fclose(Sfho);                                         //~vas3I~//~vas4R~
//        if (Sfho2)                                                 //~vas3I~//~vas4R~
//            fclose(Sfho2);                                              //~vas3I~//~vas4R~
//    },                                                           //~vas4R~
//                     {fclose(Sfh);});                                                            //~vas3I~//~vas4R~
//    IF_ARMXSUB_CLOSE(                                            //~vas4I~
//        fclose(Sfh);                                             //~vas4I~
//        if (Sfho!=stdout)                                        //~vas4I~
//             fclose(Sfho);                                       //~vas4I~
//        if (Sfho2)                                               //~vas4I~
//            fclose(Sfho2);                                       //~vas4I~
//    );                                                           //~vas4I~
    IF_ARMXSUB_CLOSE(PGM,                                          //~vas4R~
    {                                                              //~vas4I~
        fclose(Sfh);                                               //~vas4I~
        if (Sfho!=stdout)                                          //~vas4I~
             fclose(Sfho);                                         //~vas4I~
        if (Sfho2)                                                 //~vas4I~
            fclose(Sfho2);                                         //~vas4I~
    });                                                            //~vas4R~
    return rc;
}//main
//**********************************************************************//~0026I~
//*open outputfile                                                 //~0026I~
//**********************************************************************//~0026I~
FILE *openoutfile(char **Pppfnmo,char *Prename)                    //~0026I~
{                                                                  //~0026I~
    FILEFINDBUF3 fstat3;                                           //~0026M~
	char *pfnmo;                                                   //~0026I~
    FILE *fho;                                                     //~0026I~
    char confmsg[_MAX_PATH+128];                                   //~0026M~
    int rc;                                                        //~0026I~
//******************                                               //~0026I~
	pfnmo=*Pppfnmo;                                                //~0026I~
    if (WILDCARD(pfnmo))                                           //~0026I~
    {                                                              //~0026I~
        ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,Spfnm,pfnmo,Prename);    //src,patern,output//~0026I~
        pfnmo=Prename;                                             //~0026I~
        *Pppfnmo=pfnmo;                                            //~0026I~
    }                                                              //~0026I~
                                                                   //~0026I~
    if (!ufstat(pfnmo,&fstat3))                                    //~0026I~
    {                                                              //~0026I~
        if (fstat3.attrFile & FILE_DIRECTORY)                      //~0026I~
            uerrexit("%s is directory",0,                          //~0026I~
                        pfnmo);                                    //~0026I~
      if (!Sswnoconf)                                              //~0027I~
      {                                                            //~0027I~
        sprintf(confmsg,"%s exist,override? Yes/No?",pfnmo);       //~0026I~
        rc=confirm(confmsg,"YyNn");                                //~0026I~
        if (rc=='N'||rc=='n')                                      //~0026I~
            exit(1);                                               //~0026I~
      }                                                            //~0027I~
    }                                                              //~0026I~
    fho=fopen(pfnmo,"w");                                          //~0026I~
    if (!fho)                                                      //~0026I~
        uerrexit("%s open failed,rc=%d",0,                         //~0026I~
                    pfnmo,errno);                                  //~0026I~
    return fho;                                                    //~0026I~
}//openoutfile                                                     //~0026I~
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
int opdchk(int Popdno,char **Ppopd,int *Pparm,char *Pfmtfldtbl)
{
    char *pc;
    int  ii,rc,lastpos=0;
    int  nextpos=0,posparmno=0;                                                //~v57ZI~
    int  fmtfldsw=0;                                               //~v40MR~
//*********************************
    if (Popdno<=1)
        help();
    memset(Pparm,0,sizeof(int)*PARM_TBLSZ);
//  Pparm[PARM_DELM]=' ';                                          //~v62oI~
//  Pparm[PARM_SPACELEN]=DEFAULT_SPACELEN;
    Pparm[PARM_MAXFLDNO]=MAXFIELD;  	//default last fld         //~v40MR~
    for (ii=1;ii<Popdno;ii++)                                      //~0021R~
    {
    	pc=Ppopd[ii];                                              //~0021I~
//  	if (*pc==CMDFLAG_PREFIX || *pc==CMDFLAG_PREFIX2)	//flag parm//~vas4I~
    	if (*pc==CMDFLAG_PREFIX)    // unix:"-", else "/"          //~vas4R~
        {
			if (fmtopdchk3(pc+1,Pparm))
                return opderr(pc);
        }
        else
        {
        	if (!posparmno)	//1st postional parm
            	Spfnm=pc;		//filename
            else
            {
                if (rc=tc_fmtopdchk2(Pparm,pc,&lastpos,&nextpos,Pfmtfldtbl,&fmtfldsw),rc)//~v62oI~
                	return opderr(pc);
            }
            posparmno++;
        }
    }
	Pparm[PARM_SPACELEN]=(int)strlen(Sstrodelm);                   //~0022R~
    if (!posparmno)
    	uerrexit("specify input filename",0);
    if (!fmtfldsw)	//not "F" specified                            //~v40MR~
    {                                                              //~v51xI~
        for (ii=0,pc=Pfmtfldtbl;ii<MAXFIELD;ii++,pc++)             //~v51xI~
        	if (!*pc)                                              //~v51xI~
            	*pc=FMTFLAG_FMT;   //fmt all fld                   //~v51xI~
    }                                                              //~v51xI~
    else                                                           //~v40MR~
    	Pparm[PARM_MAXFLDNO]=lastpos;		//last fmt fld         //~v40MR~
    if (Sswnoalign)
    {
        for (ii=0,pc=Pfmtfldtbl;ii<MAXFIELD;ii++,pc++)             //~v51xI~
        	if (*pc & (FMTFLAG_NUMONLY|
						FMTFLAG_COMPRESS|
						FMTFLAG_LEFTALIGN|
						FMTFLAG_RIGHTALIGN|
						FMTFLAG_POINTALIGN))
            	uerrexit("No alignment option and fieldspec alignment option are conflict",0);//~0003R~
    	if (!Sswextract)	//no align and no select               //~0033I~
	        if (Sextfieldtblindex) //field spec sequence           //~0033I~
	        	uerrexit("field specification for no alignment and no select mode",0);//~0033I~
    }
    if (Sswextract)
        if (!Sextfieldtblindex) //no field spec sequence
        	uerrexit("no field specification for select mode",0);  //~0003R~
//  Sfh=fopen(Spfnm,"r");                                          //~0023R~
    Sfh=fopen(Spfnm,"rb");                                         //~0023I~
    if (!Sfh)
    	uerrexit("%s open failed",0,Spfnm);
    return 0;
}//opdchk
//****************************************************************
// calc fmt opd chk
//*rc   :0  ,4,-1(may other option)
//****************************************************************
//int tc_fmtopdchk2(char *Popd,char *Pfmt,int *Plastpos,char *Pfmtfldtbl,int *Ppfmtfldsw)
//int tc_fmtopdchk2(char *Popd,int *Plastpos,char *Pfmtfldtbl,int *Ppfmtfldsw)
//int tc_fmtopdchk2(char *Popd,int *Plastpos,int *Pnextpos,char *Pfmtfldtbl,int *Ppfmtfldsw)
int tc_fmtopdchk2(int *Pparm,char *Popd,int *Plastpos,int *Pnextpos,char *Pfmtfldtbl,int *Ppfmtfldsw)
{
    char *pc2;                                                     //~0021R~
    char *fldstr=0,*fldstr2=0;                                     //~0020R~
    int  ii,bytepos,numcnt,bit;
    int  pos1,pos2,ch,ch2;                                         //~0028R~
    int fmtbit;
    int fldmaxlen=0,fldcutoffs=0,fldendoffs=0;                     //~0019R~
    int fldstrlen=0,fldstrlen2=0,opt2=0,startcol,endcol,optwk,rc;  //~0022R~
    int resetnumsw=0,resetpasw=0;                                  //~0034R~
    char opdwk[32];                                                //~0003I~
//*********************************
    startcol=0;                                                    //~va58I~
    strncpy(opdwk,Popd,sizeof(opdwk)-1);                           //~0003I~
    *(opdwk+sizeof(opdwk)-1)=0;                                    //~0003I~
    pc2=strchr(opdwk,':');                                         //~0003I~
    if (pc2)                                                       //~0003I~
    {                                                              //~0003I~
    	*pc2++=0;                                                  //~0003I~
        ch=toupper(*pc2);                                          //~0014I~
        if (ch=='X')                                               //~0017I~
        {                                                          //~0017I~
        	opt2|=SFO2_EXCLUDE;                                    //~0017I~
    		pc2++;                                                 //~0017I~
        	ch=toupper(*pc2);                                      //~0017I~
        }                                                          //~0017I~
		rc=fmtfldstrparmchk(1,pc2,&optwk,&fldstrlen,&fldstr);      //~0020I~
        if (rc>=4)                                                 //~0020I~
        	return 4;                                              //~0020I~
        if (rc==2)	//enclosed by "'"                              //~va45R~
        {                                                          //~va45R~
            pc2=fldstr+fldstrlen+1;                                //~va45R~
//          fldstr=Popd+((ULONG)fldstr-(ULONG)opdwk);   //addr on stack//~va45R~//~va66R~
            fldstr=Popd+((ULPTR)fldstr-(ULPTR)opdwk);   //addr on stack//~va66I~
            opt2|=optwk;                                           //~va45R~
        }                                                          //~va45R~
        else                                                       //~va45R~
        if (rc==1)	//fldstr                                       //~0020I~
        {                                                          //~0020I~
            pc2=fldstr+fldstrlen;                                  //~0020M~
//          fldstr=Popd+((ULONG)fldstr-(ULONG)opdwk);   //addr on stack//~0020I~//~va66R~
            fldstr=Popd+((ULPTR)fldstr-(ULPTR)opdwk);   //addr on stack//~va66I~
            opt2|=optwk;                                           //~0020I~
        }                                                          //~0020I~
        else                                                       //~0020I~
        {                                                          //~0020I~
	        fldcutoffs=atoi(pc2);                                  //~0020R~
        	if (!fldcutoffs)                                       //~0020R~
        		return 4;                                          //~0020R~
        	startcol=fldcutoffs;                                   //~0020R~
        	if (fldcutoffs>0)                                      //~0020R~
        		fldcutoffs--;                                      //~0020R~
        	pc2+=unumlen(pc2,0,(int)strlen(pc2));                  //~0022R~
      	}                                                          //~0020R~
        if (*pc2==':')                                             //~0010I~
        {                                                          //~0010I~
        	pc2++;                                                 //~0017R~
        	if (*pc2)                                              //~0015I~
        	{                                                      //~0015I~
                rc=fmtfldstrparmchk(0,pc2,&optwk,&fldstrlen2,&fldstr2);//~0020I~
                if (rc>=4)                                         //~0020I~
                    return 4;                                      //~0020I~
              if (rc==2)  //fldstr                                 //~va45R~
              {                                                    //~va45R~
                    pc2=fldstr2+fldstrlen2+1;                      //~va45R~
//                  fldstr2=Popd+((ULONG)fldstr2-(ULONG)opdwk);   //addr on stack//~va45R~//~va66R~
                    fldstr2=Popd+((ULPTR)fldstr2-(ULPTR)opdwk);   //addr on stack//~va66I~
            		opt2|=optwk;                                   //~va45R~
                    opt2|=SFO2_ENDSTR;	//end col specified        //~va45R~
              }                                                    //~va45R~
              else                                                 //~va45R~
              if (rc==1)  //fldstr                                 //~0020I~
              {                                                    //~0020I~
                    pc2=fldstr2+fldstrlen2;                        //~0020M~
//                  fldstr2=Popd+((ULONG)fldstr2-(ULONG)opdwk);   //addr on stack//~0020I~//~va66R~
                    fldstr2=Popd+((ULPTR)fldstr2-(ULPTR)opdwk);   //addr on stack//~va66I~
            		opt2|=optwk;                                   //~0020I~
                    opt2|=SFO2_ENDSTR;	//end col specified        //~0020I~
              }                                                    //~0020I~
              else                                                 //~0020I~
              {                                                    //~0020I~
                if (toupper(*pc2)=='L') //length parm              //~0017I~
                {                                                  //~0017I~
                	pc2++;                                         //~0017R~
    	    		fldmaxlen=atoi(pc2);                           //~0019I~
        			if (fldmaxlen<=0)                              //~0019I~
	  	      			return 4;                                  //~0019I~
                    opt2|=SFO2_SUBSTRLEN;	//end col specified    //~0019I~
                }                                                  //~0017I~
                else	//end by cols                              //~0019I~
                {                                                  //~0019I~
	        		fldendoffs=atoi(pc2);                          //~0019R~
    	    		if (!fldendoffs)                               //~0019R~
  	    	  			return 4;                                  //~0019R~
                    opt2|=SFO2_SUBSTRENDCOL;	//end col specified//~0019I~
                    endcol=fldendoffs;                             //~0019R~
                    if (fldendoffs<0)                              //~0019R~
                        fldendoffs++;                              //~0019R~
					if (!fldstrlen && !fldstrlen2 //by fldstr      //~0020R~
                    &&  !(opt2 & SFO2_SUBSTRLEN))	//end col specified//~0020I~
                    	if (startcol>endcol && startcol*endcol>=0) //~0019R~
                        {                                          //~0019I~
                        	uerrmsg("substring start cols(%d) > end cols(%d)",0,//~0019R~
                            		startcol,endcol);              //~0019R~
                            return 4;                              //~0019I~
                        }                                          //~0019I~
                }                                                  //~0019I~
              }//not end str                                       //~0020I~
            }                                                      //~0015I~
        }                                                          //~0010I~
        else    //!=":"                                            //~0019I~
        	if (*pc2)                                              //~0019I~
            	return 4;                                          //~0019I~
    }                                                              //~0003I~
    Popd=opdwk;                                                    //~0003I~
    pos1=pos2=0;
    if (*Popd>='0' && *Popd<='9')	//fldno
    {
//      if ((numcnt=tc_getnumrange(Popd,&pos1,&pos2,&pc2))>1||!pos1)    //num err
        if ((numcnt=ugetnumrange3(Popd,&pos1,&pos2,&pc2))>1||!pos1)    //num err
            return 4;
        if (pos1>MAXFIELD||pos2>MAXFIELD)
        {
            uerrmsg("fieldno max is %d",0,MAXFIELD);
            return 4;
        }
        pos1--;
        if (numcnt)
            pos2=pos1+1;
    	if (*Plastpos<pos2)     //
        	*Plastpos=pos2;
        *Pnextpos=pos2;         //restart fldno from this
        if (pos2!=MAXFIELD)
            if (pos2>Sextlastpos)
            	Sextlastpos=pos2;  //to chk for shortlinectr up
	}
    else
        pc2=Popd;
//fmt tbl left align bit set
  fmtbit=FMTFLAG_FMT;
  for (;*pc2;pc2++)
  {
//	fmtbit=FMTFLAG_FMT;
	switch(toupper(*pc2))
    {
    case 'A':                                                      //~0034I~
    	resetnumsw=1;                                              //~0034I~
    	break;                                                     //~0034I~
    case 'F':
//  	*Ppfmtfldsw=1;
    	break;
    case 'O':  //overflow
		fmtbit|=FMTFLAG_OVERFLOW;
		fmtbit|=FMTFLAG_LEFTALIGN;
		fmtbit&=~FMTFLAG_RIGHTALIGN;
		fmtbit&=~FMTFLAG_POINTALIGN;
    	break;
    case 'N':
    	resetpasw=1;		//reset "P"                            //~0034I~
		fmtbit|=FMTFLAG_NUMONLY;
    	break;
    case 'C':
//  	fmtbit|=(FMTFLAG_NUMONLY|FMTFLAG_COMPRESS);                //~0029R~
    	fmtbit|=FMTFLAG_COMPRESS;                                  //~0029R~
//      Snumonlysw=1;
	    Pparm[PARM_HDRSW]|=PARM_NUMONLYFLD;
    	break;
	case 'R':
//  	leftbit=0;
		fmtbit|=FMTFLAG_RIGHTALIGN;
		fmtbit&=~FMTFLAG_LEFTALIGN;
		fmtbit&=~FMTFLAG_POINTALIGN;
    	break;
	case 'P':
        if (fldstr||fldstr2)                                       //~0020R~
        {                                                          //~0017I~
            uerrmsg("substring is not valid for point align field",0);//~0017R~
            return 4;                                              //~0017I~
        }                                                          //~0017I~
		fmtbit|=FMTFLAG_POINTALIGN;
		fmtbit&=~(FMTFLAG_LEFTALIGN|FMTFLAG_RIGHTALIGN);
    	break;
	case 'L':
//  	leftbit=1;
		fmtbit|=FMTFLAG_LEFTALIGN;
		fmtbit&=~FMTFLAG_RIGHTALIGN;
		fmtbit&=~FMTFLAG_POINTALIGN;
    	break;
	default:
    	if (pos2)	//after digit
			return 4;
        return -1;		//top byte,chk other option
    }
  }
//    if (*(pc2+1))
//        return 4;
  	*Ppfmtfldsw=1;
    if (!pos2)	//no fld no specified
    {
//  	pos1=*Plastpos;
    	pos1=*Pnextpos;
//  	*Plastpos=
//  	pos2=MAXFIELD;
	    if (fmtbit & FMTFLAG_OVERFLOW)
			pos2=pos1+1;      //treate as not overflow fld but last field
        else
			pos2=MAXFIELD;
    	*Plastpos=pos2;
        *Pnextpos=*Pnextpos+1;  // for "r r l r l" etc
	}
    else	//may be priviously set max
    {
	    if (fmtbit & FMTFLAG_OVERFLOW)
	    	*Plastpos=pos2;	//pos2 is next
    }
	if (fmtbit & FMTFLAG_POINTALIGN                                //~0034I~
	&&  fmtbit & FMTFLAG_NUMONLY)                                  //~0034I~
    {                                                              //~0034I~
        uerrmsg("\"P\" and \"N\" is mutualy exclusive.",0);        //~0034I~
        return 4;                                                  //~0034I~
    }                                                              //~0034I~
//  if (pos1||pos2!=MAXFIELD)
        for (ii=pos1;ii<pos2;ii++)
        {
//          bytepos=ii/8;
//          ch=*(Pfmt+bytepos);
//          bit=(0x80>>(ii%8));
//          if (leftbit)
//              ch=(UCHAR)(ch | bit);
//          else
//              ch=(UCHAR)(ch & ~bit);
//          *(Pfmt+bytepos)=ch;
            bytepos=ii;
            ch=*(Pfmtfldtbl+bytepos);
//          ch&=~(FMTFLAG_RIGHTALIGN|FMTFLAG_LEFTALIGN);//drop once align bit
//          ch=(char)(ch&~(FMTFLAG_RIGHTALIGN|FMTFLAG_LEFTALIGN));//drop once align bit
            ch2=ch&(FMTFLAG_RIGHTALIGN|FMTFLAG_LEFTALIGN);	//prev effect//~0029R~
            ch=(char)(ch&~(FMTFLAG_RIGHTALIGN|FMTFLAG_LEFTALIGN|FMTFLAG_POINTALIGN));//drop once align bit
            if (resetnumsw)                                        //~0034I~
                ch&=~(FMTFLAG_NUMONLY|FMTFLAG_COMPRESS);//now compress required if you want more//~0034I~
            if (resetpasw)                                         //~0034I~
                ch&=~(FMTFLAG_POINTALIGN);//reset point align      //~0034I~
            bit=fmtbit;
            if (!(bit &  (FMTFLAG_RIGHTALIGN|FMTFLAG_LEFTALIGN)))	//no align parm//~0029R~
            	bit|=ch2;                                          //~0029R~
            ch=(ch | bit);		//field used                       //~0021R~
            *(Pfmtfldtbl+bytepos)=(char)ch;                        //~0021R~
            Sfieldmaxlen[bytepos]=fldmaxlen;    //fieldno by specification sequence//~0003R~
            Sfieldcutoffs[bytepos]=fldcutoffs;  //substring offset //~0010I~
            Sfieldendoffs[bytepos]=fldendoffs;  //substring offset //~0019I~
            Sfieldstr[bytepos]=fldstr;  //substring offset         //~0014I~
            Sfieldstr2[bytepos]=fldstr2;  //substring offset       //~0020I~
            Sfieldopt2[bytepos]=opt2;  //substring offset          //~0014I~
            Sfieldstrlen[bytepos]=fldstrlen;  //substring offset   //~0014I~
            Sfieldstrlen2[bytepos]=fldstrlen2;  //substring offset //~0020I~
            if (ii<*Pnextpos)	//fieldno specified
            {
                if (Sextfieldtblindex>=MAXEXTRACT)
                    uerrexit("too many fieldno parm,max is %d",0,MAXEXTRACT);
                Sextfieldtbl[Sextfieldtblindex++]=bytepos+1;    //fieldno by specification sequence
            }
        }
//  else
//      if (leftbit)
//  		memset(Pfmt,0xff,MAXFIELD/8+1);
//      else
//  		memset(Pfmt,0,MAXFIELD/8+1);
	return 0;
}//tc_fmtopdchk2
//**************************************************************** //~0020I~
// fld string specification chk                                    //~0020I~
//*rc   :0:not fld str parm, 1:fld str parm  ,4 err                //~0020I~
//**************************************************************** //~0020I~
int fmtfldstrparmchk(int Pstartcolsw,char *Popd,int *Ppopt2,int *Ppfldstrlen,char **Pppfldstr)//~0020R~
{                                                                  //~0020I~
	char *pc2,*fldstr=NULL;                                             //~0020R~//~va64R~
    int  opt2=0,revsw,fldstrlen=0,ch;                                //~0020R~//~va64R~
    int squotesw=0;                                                //~va45R~
    char *pc3;                                                     //~va45R~
//*************************                                        //~0020I~
	pc2=Popd;                                                      //~0020R~
    ch=toupper(*pc2);                                              //~0020R~
    if (ch=='T'||ch=='E')   //field start specification str        //~0020I~
    {                                                              //~0020I~
    	if (Pstartcolsw)                                           //~0020I~
            if (ch=='T')                                           //~0020I~
                opt2|=SFO2_STARTTOP;     //top if str not found    //~0020I~
            else                                                   //~0020I~
                opt2|=SFO2_STARTEND;     //top if str not found    //~0020I~
        else                                                       //~0020I~
            if (ch=='T')                                           //~0020I~
                opt2|=SFO2_STARTTOP2;     //top if str not found   //~0020I~
            else                                                   //~0020I~
                opt2|=SFO2_STARTEND2;     //top if str not found   //~0020I~
      	pc2++;                                                     //~0022R~
    }                                                              //~0020I~
    if (*pc2=='-')                                                 //~0020I~
    {                                                              //~0020I~
      	revsw=1;                                                   //~0020I~
      	pc2++;                                                     //~0022R~
    }                                                              //~0020I~
    else                                                           //~0020I~
      	revsw=0;                                                   //~0020I~
    ch=toupper(*pc2);                                              //~0020I~
    if (ch=='A'||ch=='B')   //field start specification str        //~0020I~
    {                                                              //~0020I~
    	if (Pstartcolsw)                                           //~0020I~
        {                                                          //~0020I~
        	if (revsw)                                             //~0020I~
            	opt2|=SFO2_REVSEARCH;   //fldstr reverse serach    //~0020I~
        	if (ch=='A')                                           //~0020I~
            	opt2|=SFO2_STARTAFTER;   //field start cols is ater fldstring//~0020I~
        }                                                          //~0020I~
        else                                                       //~0020I~
        {                                                          //~0020I~
        	if (revsw)                                             //~0020I~
            	opt2|=SFO2_REVSEARCH2;   //fldstr reverse serach   //~0020I~
        	if (ch=='A')                                           //~0020I~
            	opt2|=SFO2_STARTAFTER2;   //field start cols is ater fldstring//~0020I~
        }                                                          //~0020I~
        pc2++;                                                     //~0020I~
      if (*pc2=='\'')                                              //~va45R~
      {                                                            //~va45R~
        fldstr=pc2+1;                                              //~va45R~
        pc3=strchr(fldstr,'\'');                                   //~va45R~
        if (pc3)                                                   //~va45R~
        {                                                          //~va45R~
        	squotesw=1;                                            //~va45R~
//          fldstrlen=(int)((ULONG)pc3-(ULONG)fldstr);             //~va45R~//~va66R~
            fldstrlen=(int)((ULPTR)pc3-(ULPTR)fldstr);             //~va66I~
        }                                                          //~va45R~
      }                                                            //~va45R~
      if (!squotesw)                                               //~va45R~
      {                                                            //~va45R~
        fldstr=pc2;                                                //~0020I~
        pc2=strchr(pc2,':');                                       //~0020I~
        if (pc2)                                                   //~0020I~
//          fldstrlen=(int)((ULONG)pc2-(ULONG)fldstr);             //~0020I~//~va66R~
            fldstrlen=(int)((ULPTR)pc2-(ULPTR)fldstr);             //~va66I~
        else                                                       //~0020I~
        {                                                          //~0020I~
            fldstrlen=(int)strlen(fldstr);                         //~0022R~
            pc2=fldstr+fldstrlen;                                  //~0020I~
        }                                                          //~0020I~
      }                                                            //~va45R~
        if (!fldstrlen)                                            //~0020I~
            return 4;                                              //~0020I~
    }                                                              //~0020I~
    else                                                           //~0020I~
    	return 0;	//not fldstr                                   //~0020I~
    *Ppopt2=opt2;                                                  //~0020I~
    *Ppfldstrlen=fldstrlen;                                        //~0020I~
    *Pppfldstr=fldstr;                                             //~0020I~
//  return 1;                                                      //~va45R~
    return 1+squotesw;                                             //~va45R~
}//fmtfldstrparmchk                                                //~0020I~
//****************************************************************
// calc fmt opd chk
//*rc   :0  ,4, -1 for help
//****************************************************************
int fmtopdchk3(char *Popd,int *Pparm)
{
    char *pc;
    char *pc2;                                                     //~v580I~
//*********************************
	pc=Popd;
	switch(toupper(*pc))
    {
//    case 'D':                                                      //~v51FI~
//      if (!*(pc+1))                                                //~v51pI~
//        Pparm[PARM_DELM]=',';                                      //~v62oI~
//      else                                                         //~v51pI~
//        Pparm[PARM_DELM]=*(pc+1);      //any seperator             //~v62oI~
//        break;                                                     //~v431I~
	case 'Q':                                                      //~v580I~
    	pc2=pc+1;                                                  //~v580R~
        if (!*pc2)                                                 //~v580R~
        {
		    Pparm[PARM_HDRSW]|=PARM_SQUOTE|PARM_DQUOTE;                    //~v580I~
            break;
        }
    	for (;*pc2;pc2++)                                          //~v580I~
        {                                                          //~v580I~
        	switch(toupper(*pc2))                                  //~v580I~
            {                                                      //~v580I~
            case 'D':                                              //~v580I~
		        Pparm[PARM_HDRSW]|=PARM_DQUOTE;                    //~v580I~
                break;	                                           //~v580I~
            case 'S':                                              //~v580I~
		        Pparm[PARM_HDRSW]|=PARM_SQUOTE;                    //~v580I~
                break;                                             //~v580I~
            default:                                               //~v580I~
                return 4;                                          //~v580I~
            }                                                      //~v580I~
        }                                                          //~v580I~
    	break;                                                     //~v580I~
//    case 'S':
//        intp=atoi(pc+1);
//        if (!intp)
//            return 4;
//        Pparm[PARM_SPACELEN]=intp;
//        break;
	default:
		return fmtopdchk4(pc);
    }
	return 0;
}//fmtopdchk3
//****************************************************************
// xfmt specific parm
//*rc   :0  ,4
//****************************************************************
int fmtopdchk4(char *Popd)
{
	char *pc,*str;                                                 //~0006R~
    int col,ii,jj,ltyp,ch,len;                                     //~0006R~
static int Sprevtyp=0;                                             //~0032I~
//***************************
    pc=Popd;
    switch(toupper(*pc))                                       //~5323I~
    {                                                          //~5323I~
    case 'D':		//input delm
    	len=(int)strlen(pc+1);                                     //~0022R~
        if (len>sizeof(Sstridelm)-2)                               //~0006R~
        	len=sizeof(Sstridelm)-2;                               //~0006R~
        for (ii=0,jj=0,pc++;jj<len;ii++,jj++,pc++)                 //~0006R~
        	if (*pc=='\\' && *(pc+1)=='t')                         //~0006I~
            {	                                                   //~0006I~
            	Sstridelm[ii]='\t';                                //~0006R~
                pc++;                                              //~0006I~
                jj++;                                              //~0006I~
            }                                                      //~0006I~
            else                                                   //~0006I~
            	Sstridelm[ii]=*pc;                                 //~0006R~
        Sstridelm[ii]=0;                                           //~0006I~
        break;
    case 'O':		//input delm                                   //~0004I~
        Spfnmo=pc+1;                                               //~0004I~
        break;                                                     //~0004I~
    case 'R':		//input delm                                   //~0023I~
        Slrecl=atoi(pc+1);                                         //~0023I~
        if (!Slrecl)                                               //~0023I~
        	return 4;                                              //~0023M~
        break;                                                     //~0023I~
    case 'S':		//output seperator
        if (toupper(*(pc+1))=='R')  //rep option                   //~0022I~
        {                                                          //~0022I~
            pc++;                                                  //~0022I~
            Sswrepdelm=1;                                          //~0022I~
        }                                                          //~0022I~
        Sstrodelm=pc+1;
        break;
    case 'X':		//input delm                                   //~0026I~
        Spfnmo2=pc+1;                                              //~0026I~
        break;                                                     //~0026I~
    case 'L':		//line selection parm
        pc++;
        if (*pc=='+')   //+ skipped bu unumlen                     //~0031I~
            col=0;                                                 //~0031I~
        else                                                       //~0031I~
        {                                                          //~0031I~
        col=atoi(pc);
        pc+=unumlen(pc,0,(int)strlen(pc));                         //~0022R~
        }                                                          //~0031I~
        ltyp=toupper(*pc);
        str=pc+1;
        switch(ltyp)
        {
        case 'S':	//extract start id
            if (*str)
    	        Sstrxstart=str;
            else
            	return opderr(Popd);                               //~0031R~
            Sstrxstartcols=col;
            Sstrxstartlen=(int)strlen(str);
            Sprevtyp=ltyp;                                         //~0032I~
            break;
        case 'E':	//extract start id
            if (*str)
    	        Sstrxend=str;
            else
            	return opderr(Popd);                               //~0031R~
            Sstrxendcols=col;
            Sstrxendlen=(int)strlen(str);
            Sprevtyp=ltyp;                                         //~0032I~
            break;
        case 'I':	//extract start id
        case 'X':	//extract start id
        case '+':	//extract start id                             //~0025I~
            if (!*str)                                             //~0031I~
            	return opderr(Popd);                               //~0031I~
            if (ltyp=='+')  //AND req                              //~0032I~
            {                                                      //~0032I~
                if (!Sprevtyp)                                     //~0032I~
	            	uerrexit("AND(+) should be after other condition parm",0);//~0032I~
                ltyp=(int)((UINT)Sprevtyp<<8)|ltyp;                //~va29R~
            }                                                      //~0032I~
        	else                                                   //~0032I~
            	Sprevtyp=ltyp;                                     //~0032I~
            if (Sstrselectctr>=MAXSTRINGPARM)
                uerrexit("too many string parm,max is %s",0,MAXSTRINGPARM);
            Sstrselect[Sstrselectctr]=str;
            Sstrselectcols[Sstrselectctr]=col;
            Sstrselectflag[Sstrselectctr]=ltyp;
            Sstrselectlen[Sstrselectctr]=(int)strlen(str);
            Sstrselectctr++;
            break;
        default:
            return opderr(Popd);                                   //~0031R~
        }
        break;
    case 'Y':                                                  //~5323I~
        while(ch=*(++pc),ch)
        {
            switch(toupper(ch))             //option
            {
            case '9':
                break;
            case 'A':       //align
                Sswnoalign=0;
                break;
            case 'C':       //output file override confirmation    //~0027I~
                Sswnoconf=0;                                       //~0027R~
                break;                                             //~0027I~
            case 'S':       //extract                              //~0003R~
                Sswextract=1;
                break;
            default:
	            return opderr(Popd);                               //~0031R~
            }
        }
        break;
    case 'N':                                                  //~5323I~
        while(ch=*(++pc),ch)
        {
            switch(toupper(ch))             //option
            {
            case '9':
                break;
            case 'A':       //align
                Sswnoalign=1;
                break;
            case 'C':       //output file override confirmation    //~0027I~
                Sswnoconf=1;                                       //~0027R~
                break;                                             //~0027I~
            case 'S':       //extract                              //~0003R~
                Sswextract=0;
                break;
            default:
	            return opderr(Popd);                               //~0031R~
            }
        }
        break;
    default:                                                   //~5323I~
        return 4;
    }                                                          //~5323I~
    return 0;
}//fmtopdchk4
//**************************************************************** //~0023I~
// record split by fixed length                                    //~0023I~
//**************************************************************** //~0023I~
int splitmain(int *Pparm)                                          //~0023R~
{                                                                  //~0023I~
	int     sw1strec,rc=0;                                         //~0023R~
    long    readlen;                                               //~0023R~
    char  *buff;                                                   //~0023I~
//*********************************                                //~0023I~
//chk field width                                                  //~0023I~
	buff=umalloc((UINT)(Slrecl+1));	//top is for ovf               //~va29R~
    UALLOCCHK(buff,UALLOC_FAILED);                                 //~0023I~
    for (sw1strec=1;;sw1strec=0)                                   //~0023I~
    {                                                              //~0023I~
//    	if ((readlen=getline(sw1strec,buff,Slrecl,Pparm))<0)       //~va4fR~
      	if ((readlen=xfmt_getline(sw1strec,buff,Slrecl,Pparm))<0)  //~va4fI~
        	break;                                                 //~0023I~
        fwrite(buff,1,(UINT)readlen,Sfho);                         //~0023I~
        fwrite("\n",1,1,Sfho);                                     //~0023I~
        Swriteline++;                                              //~0023I~
	}//all plh                                                     //~0023I~
    return rc;                                                     //~0023I~
}//splitmain                                                       //~0023I~
//****************************************************************
// format                                                          //~0023R~
//*rc   :0   or 1:data err or 4:env err or UALLOC_FAILED
//****************************************************************
int fmtmain(int *Pparm,char *Pfmtfldtbl)                              //~v40MR~
{
	int     parmmaxfldno,maxfldno=0,*pfldtb,sw1strec,rc=0,ii,len,maxlrecl=0;//~v40MR~
	int     upno;                                                  //~v58xI~
//  long   recno=0,readlen;                                        //~va28R~
    int    recno=0,readlen;                                        //~va28I~
    int    newlen;                                                 //~0021I~
    char   *pwdata;
    char   *pcwdata=0;	//compress work                //~v51tI~
//  char  buff[MAXBUFFSZ];                                         //~va28R~
//  char  outbuff[MAXBUFFSZ];                                      //~va28R~
    char  *buff,*outbuff;                                          //~va28I~
    int   extoffstbl[MAXFIELD+MAXFIELD];	//start offs and len
    int   extoffstblindex;
//*********************************
//chk field width 
    pfldtb=umalloc(sizeof(int)*(MAXFIELD+1));	//top is for ovf   //~v51xI~
    UALLOCCHK(pfldtb,UALLOC_FAILED);
    buff=umalloc(MAXBUFFSZ);                                       //~va28I~
    UALLOCCHK(buff,UALLOC_FAILED);                                 //~va28I~
    outbuff=umalloc(MAXBUFFSZ);                                    //~va28I~
    UALLOCCHK(outbuff,UALLOC_FAILED);                              //~va28I~
    memset(pfldtb,0,(sizeof(int)*(MAXFIELD+1)));


	parmmaxfldno=Pparm[PARM_MAXFLDNO];		//max for fmt fld only //~v40MR~
  if (Sswnoalign)
    maxfldno=parmmaxfldno;
  else
  {
    Sskipxout=1;    //skip exception record write at getline       //~0026I~
    for (sw1strec=1;;sw1strec=0)
    {
//  	if ((readlen=getline(sw1strec,buff,sizeof(buff),Pparm))<0) //~va28R~
//    	if ((readlen=getline(sw1strec,buff,MAXBUFFSZ,Pparm))<0)    //~va4fR~
      	if ((readlen=xfmt_getline(sw1strec,buff,MAXBUFFSZ,Pparm))<0)//~va4fI~
        	break;
    	tc_chkfieldwidth(Pparm,buff,readlen,pfldtb,parmmaxfldno,&maxfldno,&maxlrecl,Pfmtfldtbl);	//actual max fldno//~v62oR~
	}//all plh
	if (rc==UALLOC_FAILED)
    	return rc;
    Sskipxout=0;    //skip exception record write at getline       //~0026I~
  }
    Pparm[PARM_MAXFLDNO]=maxfldno;
//editwork
  if (!Sswnoalign)	//format req
  {
//  len=(maxfldno+1)*Pparm[PARM_SPACELEN]+TOPSPACELEN;             //~0034R~
    len=(maxfldno+maxfldno+1)*(Pparm[PARM_SPACELEN]+1)+TOPSPACELEN;//for numonly 2 fld//~0034R~
	for (ii=0;ii<=maxfldno;ii++)
    {                                                              //~v58xI~
        if (ii>0)                                                  //~v58xI~
        {                                                          //~v58xI~
        	upno=Pfmtfldtbl[ii-1+MAXFIELD];	//digit count from "." //~v58xR~
            if (upno)                                              //~v58xI~
            {                                                      //~v58xI~
	        	upno+=Pfmtfldtbl[ii-1+MAXFIELD+MAXFIELD];	//over up digit and "."//~v58xI~
                if (upno>pfldtb[ii])                               //~v58xI~
	 		   		pfldtb[ii]=upno;	//if up exist,pfldtbl is digit count of over digit//~v58xR~
            }                                                      //~v58xI~
        	len+=Pfmtfldtbl[ii-1+MAXFIELD+MAXFIELD+MAXFIELD]+Pparm[PARM_SPACELEN]+1;//numonly field numlen//~0034R~
        }                                                          //~v58xI~
	  	len+=pfldtb[ii];                                           //~0034R~
    }                                                              //~v58xI~
	if (len<maxlrecl)	
    	len=maxlrecl;   	//space padding
//  Pparm[PARM_MAXDATALEN]=len;
//  pwdata=umalloc((UINT)len);                                     //~v51xI~
//  UALLOCCHK(pwdata,UALLOC_FAILED);
	if (Pparm[PARM_HDRSW] & PARM_NUMONLYFLD)                       //~v62oI~
    {                                                              //~v51tI~
        pcwdata=umalloc((UINT)len);        //nonum fld compaction work//~v51xI~
        UALLOCCHK(pcwdata,UALLOC_FAILED);                          //~v51tI~
    }                                                              //~v51tI~
  }//fmt req
    pwdata=outbuff;

    fseek(Sfh,0,SEEK_SET);		//back to top of file                                                               //~v40RI~
    for (sw1strec=1;;sw1strec=0)
    {
//  	if ((readlen=getline(sw1strec,buff,sizeof(buff),Pparm))<0) //~va28R~
//    	if ((readlen=getline(sw1strec,buff,MAXBUFFSZ,Pparm))<0)    //~va4fR~
      	if ((readlen=xfmt_getline(sw1strec,buff,MAXBUFFSZ,Pparm))<0)//~va4fI~
        	break;
        recno++;
     	if (Sswnoalign && !Sswextract)	//no align and no select       //~0030I~
        	fwrite(buff,1,(UINT)readlen,Sfho);                         //~0030I~
     	else                                                          //~0030I~
     	{                                                             //~0030I~
      		memset(extoffstbl,0,sizeof(extoffstbl));	//0 for nonfmt field
    		if (rc=tc_fmtdatasub(buff,readlen,&newlen,Pparm,pfldtb,Pfmtfldtbl,pwdata,pcwdata,extoffstbl,&extoffstblindex),rc)//~v51xI~
        	{
        		if (rc>4)
            		break;
			}
      		if (Sswextract)
      		{
        		newlen=extractdata(Pparm,pwdata,buff,extoffstbl,extoffstblindex);
        		if (newlen)
					fwrite(buff,1,(UINT)newlen,Sfho);                      //~0022R~
      		}
      		else
        		fwrite(pwdata,1,(UINT)newlen,Sfho);                        //~0022R~
     	}//align or select                                            //~0030I~
        fwrite("\n",1,1,Sfho);                                     //~0004R~
        Swriteline++;
	}//all plh
    return rc;
}//fmtmain
//****************************************************************
// expand data by align specification
//Pwdata:output buff
//Ppcwdata:num field compress work
//Pextoffstbl:output extract tbl for rearange
//*ret :0, 4:over maxfld
//****************************************************************
int tc_fmtdatasub(char *Plinedata,int Plinelen,int *Pnewlen,int *Pparm,
    		int *Pfmttb,char *Pfmtfldtbl,char *Pwdata,char *Ppcwdata,int *Pextoffstbl,int *Pextoffstblindex)
{
    int len,rlen,fldno,leftalign,fldlen,newlen,spacelen;           //~0009R~
    char  *pc,*pcw,*wdata,*pnumfld;                                //~0034R~
    int   maxfldno,nofmtsw;                                        //~0022R~
    int   netlen,lastsw;
    int   upno,upno2;
    char *pflddata;                                                //~0014R~
    int complen;
    int ch;
    LONG wklv[4];
    int extoffstblindex=0,fldstrlen;                               //~0014R~
    int fldcutoffs,shiftlen,shiftoffs,netlenup,uplen;              //~0021R~
    int shiftlen1,shiftlen2=0,fldstrpos=0,excludesw,opt2,startoffs,uptoeolsw;//~0019R~//~va64R~
    char curdelm,prevdelm=0;                                       //~0034R~
    int maxnumonlynumlen,numonlynumlen,len2;                       //~0034R~
//****************************************
//  delm=Pparm[PARM_DELM];
	maxfldno=Pparm[PARM_MAXFLDNO];
//  wdatalen=Pparm[PARM_MAXDATALEN];
	spacelen=Pparm[PARM_SPACELEN];
//  memset(Pwdata,' ',(UINT)wdatalen);

	pc=Plinedata;                                                  //~0022R~
    rlen=Plinelen;                                                 //~0022R~
    memset(Pwdata,' ',TOPSPACELEN);
    wdata=Pwdata+TOPSPACELEN;
    for (fldno=0;;)
    {
        lastsw=0;
    	len=(int)umemspnc(pc,' ',(UINT)rlen);
        pc+=len;
        rlen-=len;
        if (rlen<=0)
          if (!fldno || prevdelm==' ')//all space or space after delm=' '//~0006R~
        	break;

        extoffstblindex=fldno*2;
      if (!Sswnoalign||Sswextract)    //all field split            //~0021R~
      {                                                            //~0021I~
        if (fldno>=maxfldno)
        {
        	lastsw=1;
        	break;
        }
      }                                                            //~0021I~

		fldcutoffs=Sfieldcutoffs[fldno];                           //~0010I~
		fldstrlen=Sfieldstrlen[fldno];	//determin substring pos   //~0014R~
        opt2=Sfieldopt2[fldno];  		//substring option         //~0017R~
      	excludesw=(opt2 & SFO2_EXCLUDE);	//exclude upto end of field//~0017I~
      	uptoeolsw=!(opt2 & (SFO2_SUBSTRLEN|SFO2_SUBSTRENDCOL|SFO2_ENDSTR));	//exclude upto end of field//~0020R~
        fldno++;
        fldlen=Pfmttb[fldno];
        ch=Pfmtfldtbl[fldno-1];
        if (ch & FMTFLAG_LEFTALIGN)
        	leftalign=1;
        else
        	leftalign=0;
		if (Sswnoalign)                                            //~0003I~
        	leftalign=1;	//cut tail when fldmaxlen specified    //~0003I~
        maxnumonlynumlen=Pfmtfldtbl[fldno-1+MAXFIELD+MAXFIELD+MAXFIELD];//~0034I~
//      pcw=tc_getfieldendaddr(Pparm,pc,rlen,Ppcwdata,&complen,ch,wklv);//~0034R~
        pcw=tc_getfieldendaddr(Pparm,pc,rlen,Ppcwdata,&complen,ch,wklv,&numonlynumlen,&pnumfld);//~0034R~
        nofmtsw=0;
        if (pcw)
        {
//          len=(int)((ULONG)pcw-(ULONG)pc);                       //~va66R~
            len=(int)((ULPTR)pcw-(ULPTR)pc);                       //~va66I~
          if (!Sswnoalign)                                         //~0021R~
          {                                                        //~0021R~
    		pcw=tc_chknonfmtfieldwidth(Pparm,pcw,rlen-len,Pfmtfldtbl,&fldno,&len,&nofmtsw);
            fldlen=Pfmttb[fldno];
            if (nofmtsw)    //  	no fmt field left align
            {
	        	leftalign=1;
                complen=len;
            }
          }                                                        //~0021R~
        }
        else
        	len=rlen;
        if (!(ch & FMTFLAG_COMPRESS))	//not compress mode
        	complen=len;
		if (pcw)                                                   //~0006I~
//        if (len)                                                 //~va2eR~
        	curdelm=*pcw;                                          //~0006I~
//        else          //numonly field has no preceding non-num fields//~va2eR~
//          curdelm=' ';                                           //~va2eR~
        else                                                       //~0006I~
        	curdelm=0;                                             //~0006I~
        if ((ch & FMTFLAG_COMPRESS))	//not compress mode        //~0027I~
        	netlen=complen;                                        //~0027I~
        else                                                       //~0027I~
        if (!nofmtsw && curdelm!=' ')                              //~0006R~
        	netlen=complen-(int)umemrspnc(pc,' ',(UINT)complen);//cut last space
        else
        	netlen=complen;
        if (fldno>1)
        {
//      	*wdata=delm;
        	memcpy(wdata,Sstrodelm,(UINT)spacelen);
        	wdata+=spacelen;		//next pos
        }
        if (Sswnoalign)    //fmt req(fldlen is valid)
        	fldlen=netlen;
//      else                                                       //~0010R~
//          memset(wdata,' ',(UINT)fldlen);	//for align ment       //~0010R~
        if (ch & FMTFLAG_COMPRESS)	//compress mode
        {
        	pflddata=Ppcwdata;
        }
        else
        {
        	pflddata=pc;
        }
//substring offset/len                                             //~0010I~
		if (fldstrlen)                                             //~0014I~
        	getsubstrbyfldstr(fldno-1,pflddata,netlen,&fldstrpos); //~0020R~
		netlenup=netlen;   //for not P field                       //~0010I~
        uplen=                                                     //~0010I~
        upno=Pfmtfldtbl[fldno-1+MAXFIELD];  //field has underpoint in some line//~0010I~
        if (upno)      //digit count of ".xxx"                     //~0010I~
        {                                                          //~0010I~
            upno2=(wklv[1]&UCALC_UPMASK);   //paddin space for underpoint digit count//~0010I~
            if (upno2)                                             //~0010I~
            {                                                      //~0010I~
                upno2++;                                           //~0010I~
                upno-=upno2;                                       //~0010I~
                if (upno<0)                                        //~0010I~
                    upno=0;     //for safety                       //~0010I~
            }                                                      //~0010I~
			netlenup=fldlen;   //substring from formated field     //~0010I~
        }                                                          //~0010I~
		if (fldstrlen)                                             //~0019I~
        	startoffs=fldstrpos;                                   //~0019R~
        else                                                       //~0019I~
        	startoffs=Sfieldcutoffs[fldno-1];                      //~0019I~
	    getsubstrfieldlen(fldno-1,netlenup,startoffs,pflddata,&shiftlen,&shiftlen1);//~0020R~
        if (Sswnoalign)    //fldlen not set bu chkwidth            //~0019I~
        	fldlen=shiftlen;                                       //~0019I~
      	if (excludesw)	//inter-region string cut                  //~0017R~
      	{                                                            //~0012I~
        	if (uptoeolsw)	//exclude	up to eol                  //~0019R~
            	shiftoffs=0;                                       //~0019R~
            else                                                   //~0019I~
            {                                                      //~0019I~
                shiftlen2=shiftlen-shiftlen1;   //exclude e2nd part len//~0019I~
                shiftoffs=netlenup-shiftlen2;   //2nd part offset  //~0019I~
            }                                                      //~0019I~
      	}                                                            //~0012I~
      	else	//not exclude                                      //~0017R~
      	{                                                            //~0011I~
            if (fldstrlen)                                         //~0017I~
                shiftoffs=fldstrpos;        //start pos by fldstr  //~0017I~
            else                                                   //~0017I~
                if (fldcutoffs<0)   //from rear                    //~0017R~
                    shiftoffs=max(0,netlenup+fldcutoffs);          //~0017R~
                else                            //from top         //~0017R~
                    shiftoffs=min(netlenup,fldcutoffs);            //~0017R~
      	}//not cut                                                   //~0011I~
      	if (excludesw && !uptoeolsw)	//intermediate cut         //~0019R~
      	{                                                            //~0012I~
        	if (leftalign)                                             //~0012I~
        	{                                                          //~0012I~
            	if (shiftlen1)                                         //~0012I~
	        		memcpy(wdata,pflddata,(UINT)shiftlen1);            //~0012I~
            	if (shiftlen2)                                         //~0012I~
	        		memcpy(wdata+shiftlen1,pflddata+shiftoffs,(UINT)shiftlen2);//~0012I~
            	if (fldlen>shiftlen)                                   //~0012I~
	            	memset(wdata+shiftlen,' ',(UINT)(fldlen-shiftlen));//~0022R~
			}                                                          //~0012I~
        	else                                                       //~0012I~
        	{                                                          //~0012I~
				if (uplen)	//P field                                  //~0012I~
            	{                                                      //~0012I~
                	memset(wdata,' ',(UINT)netlenup);  //for align ment//~0012I~
					memcpy(wdata+netlenup-netlen-upno,pflddata,(UINT)netlen);//~0012I~
                	memcpy(wdata+shiftlen1,wdata+shiftoffs,(UINT)shiftlen2);//~0012I~
                	if (fldlen>shiftlen)                               //~0012I~
	                	memset(wdata+shiftlen1+shiftlen2,' ',(UINT)(fldlen-shiftlen));//~0022R~
            	}                                                      //~0012I~
            	else	//R field                                      //~0012I~
            	{                                                      //~0012I~
	            	if (fldlen>shiftlen)                               //~0012I~
    	            	memset(wdata,' ',(UINT)(fldlen-shiftlen));  //for align ment//~0012I~
            		if (shiftlen1) //data contain                      //~0012I~
	        			memcpy(wdata+fldlen-shiftlen,pflddata,(UINT)shiftlen1);//~0012I~
            		if (shiftlen2) //data contain                      //~0012I~
	        			memcpy(wdata+fldlen-shiftlen+shiftlen1,pflddata+shiftoffs,(UINT)shiftlen2);//~0012I~
	            }                                                      //~0012I~
			}                                                          //~0012I~
      	}                                                            //~0012I~
      	else                                                         //~0012I~
      	{                                                            //~0012I~
//      	if (leftalign)                                         //~va45R~
        	if (leftalign && !uplen)                               //~va2eI~
        	{
//      		memcpy(wdata,pflddata,(UINT)netlen);                   //~0010R~
            	if (shiftlen)                                          //~0010I~
	        		memcpy(wdata,pflddata+shiftoffs,(UINT)shiftlen);   //~0010I~
            	if (fldlen>shiftlen)                                   //~0010I~
	            	memset(wdata+shiftlen,' ',(UINT)(fldlen-shiftlen));//~0022R~
//        		if (fldmaxlen && fldmaxlen<fldlen)                     //~0010R~
//              	fldlen=fldmaxlen;                                  //~0010R~
			}
        	else
        	{
//        		if (wklv[1]!=-1)	//fld is numeric                   //~0010R~
//        		{                                                      //~0010R~
//      			upno=Pfmtfldtbl[fldno-1+MAXFIELD];  //field has underpoint in some line//~0010R~
//          		if (upno)      //digit count of ".xxx"             //~0010R~
//          		{                                                  //~0010R~
//      				upno2=(wklv[1]&UCALC_UPMASK);	//paddin space for underpoint digit count//~0010R~
//          			if (upno2)                                     //~0010R~
//                  	{                                              //~0010R~
//                  		upno2++;                                   //~0010R~
//          				upno-=upno2;                               //~0010R~
//                      	if (upno<0)                                //~0010R~
//                      		upno=0;		//for safety               //~0010R~
//                  	}                                              //~0010R~
//              	}                                                  //~0010R~
//        		}                                                      //~0010R~
//        		else                                                   //~0010R~
//      			upno=0;                                            //~0010R~
//      		memcpy(wdata+fldlen-netlen-upno,pflddata,(UINT)netlen);//~0010R~
				if (uplen)	//P field                                  //~0010I~
            	{                                                      //~0010I~
                	memset(wdata,' ',(UINT)netlenup);  //for align ment//~0010R~
					memcpy(wdata+netlenup-netlen-upno,pflddata,(UINT)netlen);//~0010R~
                	memcpy(wdata,wdata+shiftoffs,(UINT)shiftlen);      //~0010R~
            	}                                                      //~0010I~
            	else	//R field                                      //~0010I~
            	{                                                      //~0010I~
	            	if (fldlen>shiftlen)                               //~0010R~
    	            	memset(wdata,' ',(UINT)(fldlen-shiftlen));  //for align ment//~0010R~
            		if (shiftlen) //data contain                       //~0010R~
	        			memcpy(wdata+fldlen-shiftlen,pflddata+shiftoffs,(UINT)shiftlen);//~0012R~
            	}                                                      //~0010I~
//        		if (fldmaxlen && fldmaxlen<fldlen)                     //~0010R~
//          	{                                                      //~0010R~
//          		memcpy(wdata,wdata+fldlen-fldmaxlen,(UINT)fldmaxlen);//~0010R~
//              	fldlen=fldmaxlen;                                  //~0010R~
//          	}                                                      //~0010R~
			}
      	}                                                            //~0012I~
//      Pextoffstbl[extoffstblindex++]=(int)((ULONG)wdata-(ULONG)Pwdata);//~va66R~
        Pextoffstbl[extoffstblindex++]=(int)((ULPTR)wdata-(ULPTR)Pwdata);//~va66I~
        Pextoffstbl[extoffstblindex++]=fldlen;
        wdata+=fldlen;		//next pos
        if (curdelm)	//data delm is not space                      //~0006R~
        {
         if (fldlen)                                               //~0035I~
          if (!Sswrepdelm)                                         //~0022I~
          {                                                        //~0022I~
        	*wdata++=curdelm;                                      //~0006R~
	        Pextoffstbl[extoffstblindex-1]++;                      //~0022R~
          }                                                        //~0022I~
        }
        if (ch & FMTFLAG_NUMONLY && maxnumonlynumlen	//num only field exist//~0035R~
        &&  numonlynumlen) //num search not reached to eol         //~0035R~
        {                                                          //~0034I~
            if (fldlen)                                            //~0035I~
            {                                                      //~0035I~
            	memcpy(wdata,Sstrodelm,(UINT)spacelen);            //~0035R~
            	wdata+=spacelen;                                   //~0035R~
            }                                                      //~0035I~
            len2=maxnumonlynumlen-numonlynumlen;                   //~0035R~
            if (len2>0)                                            //~0035R~
                memset(wdata,' ',(UINT)len2);  //right justified   //~0035R~
            memcpy(wdata+len2,pnumfld,(UINT)numonlynumlen);        //~0035R~
            wdata+=maxnumonlynumlen;                               //~0035R~
            Pextoffstbl[extoffstblindex-1]+=maxnumonlynumlen;      //~0035R~
            pcw=pnumfld+numonlynumlen;                             //~0035R~
//          len=(int)((ULONG)pcw-(ULONG)pc);                       //~0035R~//~va66R~
            len=(int)((ULPTR)pcw-(ULPTR)pc);                       //~va66I~
            if (len>=rlen)                                         //~0035R~
                pcw=0;                                             //~0035R~
            else                                                   //~0035R~
            {                                                      //~0035R~
                curdelm=*pcw;                                      //~0035R~
                if (!Sswrepdelm)                                   //~0035R~
                {                                                  //~0035R~
                    *wdata++=*pcw;                                 //~0035R~
                    Pextoffstbl[extoffstblindex-1]++;              //~0035R~
                }                                                  //~0035R~
            }                                                      //~0035R~
        }                                                          //~0034I~
        rlen-=len;
        if (!pcw)
        	break;
        prevdelm=curdelm;                                          //~0006I~
		pc=pcw;
        pc++;
        rlen--;
	}
    if (lastsw)             //remain data
    {
//      if (fldno>1)                                               //~0003R~
        if (fldno>=1)                                              //~0003I~
        {                                                          //~0003I~
//      	*wdata=delm;
//          if (prevdelm)                                          //~0010R~
//  			*wdata++=prevdelm;                                 //~0010R~
        	memcpy(wdata,Sstrodelm,(UINT)spacelen);
        wdata+=spacelen;		//next pos
        }                                                          //~0003I~
//      Pextoffstbl[extoffstblindex++]=(int)((ULONG)wdata-(ULONG)Pwdata);//~va66R~
        Pextoffstbl[extoffstblindex++]=(int)((ULPTR)wdata-(ULPTR)Pwdata);//~va66I~
        Pextoffstbl[extoffstblindex++]=rlen;
        memcpy(wdata,pc,(UINT)rlen);
        wdata+=rlen;
    }
//  newlen=(int)((ULONG)wdata-(ULONG)Pwdata);                      //~va66R~
    newlen=(int)((ULPTR)wdata-(ULPTR)Pwdata);                      //~va66I~
    *Pextoffstblindex=extoffstblindex;
    *Pnewlen=newlen;
	return 0;
}//tc_fmtdatasub
//**************************************************************** //~0014I~
// determin substr start pos by fldstr                             //~0014I~
//*ret :rc 0:str found                                             //~0020R~
//**************************************************************** //~0014I~
int getsubstrbyfldstr(int Pfldno,char *Pflddata,int Pnetlen,int *Ppfldstroffs)//~0020R~
{                                                                  //~0014I~
	int opt2,substroffs,fldstrlen,rc=0;                            //~0020R~
    char *fldstr,*pc;                                              //~0014I~
//**********************                                           //~0014I~
	opt2=Sfieldopt2[Pfldno];                                       //~0015I~
	fldstr=Sfieldstr[Pfldno];                                      //~0014R~
    fldstrlen=Sfieldstrlen[Pfldno];                                //~0014R~
  if (opt2 & SFO2_REVSEARCH)    //reverse search                   //~0016I~
    pc=umemrmem(Pflddata,fldstr,(UINT)Pnetlen,(UINT)fldstrlen);    //~0022R~
  else                                                             //~0016I~
    pc=umemmem(Pflddata,fldstr,(UINT)Pnetlen,(UINT)fldstrlen);     //~0022R~
    if (pc)                                                        //~0014I~
    {                                                              //~0014I~
//      substroffs=(int)((ULONG)pc-(ULONG)Pflddata);               //~0014I~//~va66R~
        substroffs=(int)((ULPTR)pc-(ULPTR)Pflddata);               //~va66I~
		if (opt2 & SFO2_STARTAFTER)	//determin substring pos       //~0015I~
        	substroffs+=fldstrlen;                                 //~0014R~
    }                                                              //~0014I~
    else                                                           //~0014I~
    {                                                              //~0015I~
		if (opt2 & SFO2_STARTTOP)   //assume top                   //~0015I~
        	substroffs=0;                                          //~0015I~
        else                                                       //~0015I~
		if (opt2 & SFO2_STARTEND)   //assume top                   //~0015I~
        	substroffs=Pnetlen;                                    //~0015I~
        else                                                       //~0015I~
        {		//set default                                      //~0020I~
            if (opt2 & SFO2_EXCLUDE)    //exclude upto end of field//~0020R~
                substroffs=Pnetlen;                                //~0020I~
            else                                                   //~0020I~
                substroffs=0;                                      //~0020I~
            rc=4;                                                  //~0020I~
        }                                                          //~0020I~
    }                                                              //~0015I~
    *Ppfldstroffs=substroffs;                                      //~0020I~
    return rc;                                                     //~0020R~
}//getsubstrbyfldstr                                               //~0020R~
//**************************************************************** //~0020I~
// determin substr start pos by fldstr                             //~0020I~
//*ret :rc 0:str found                                             //~0020I~
//**************************************************************** //~0020I~
int getsubstrbyfldstr2(int Pfldno,char *Pflddata,int Pnetlen,int *Ppfldstroffs)//~0020I~
{                                                                  //~0020I~
	int opt2,substroffs,fldstrlen,rc=0;                            //~0020I~
    char *fldstr,*pc;                                              //~0020I~
//**********************                                           //~0020I~
    substroffs=0;                                                  //~va58I~
	opt2=Sfieldopt2[Pfldno];                                       //~0020I~
	fldstr=Sfieldstr2[Pfldno];                                     //~0020I~
    fldstrlen=Sfieldstrlen2[Pfldno];                               //~0020I~
  if (opt2 & SFO2_REVSEARCH2)    //reverse search                  //~0020I~
    pc=umemrmem(Pflddata,fldstr,(UINT)Pnetlen,(UINT)fldstrlen);    //~0022R~
  else                                                             //~0020I~
    pc=umemmem(Pflddata,fldstr,(UINT)Pnetlen,(UINT)fldstrlen);     //~0022R~
    if (pc)                                                        //~0020I~
    {                                                              //~0020I~
//      substroffs=(int)((ULONG)pc-(ULONG)Pflddata);               //~0020I~//~va66R~
        substroffs=(int)((ULPTR)pc-(ULPTR)Pflddata);               //~va66I~
		if (opt2 & SFO2_STARTAFTER2)	//determin substring pos   //~0020I~
        	substroffs+=fldstrlen;                                 //~0020I~
    }                                                              //~0020I~
    else                                                           //~0020I~
    {                                                              //~0020I~
		if (opt2 & SFO2_STARTTOP2)   //assume top                  //~0020I~
        	substroffs=0;                                          //~0020I~
        else                                                       //~0020I~
		if (opt2 & SFO2_STARTEND2)   //assume top                  //~0020I~
        	substroffs=Pnetlen;                                    //~0020I~
        else                                                       //~0020I~
            rc=4;                                                  //~0020I~
    }                                                              //~0020I~
    *Ppfldstroffs=substroffs;                                      //~0020I~
    return rc;                                                     //~0020I~
}//getsubstrbyfldstr2                                              //~0020I~
//****************************************************************
// expand data by align specification
//Pextoffstbl:output extract tbl for rearange
//*ret :0, 4:over maxfld
//****************************************************************
int extractdata(int *Pparm,char *Pfmtdataline,char *Pextdataline,int *Pextoffstbl,int Pextoffstblindex)
{
    int len,fldno,*pint,ii,outfldseq,offs,spacelen,shortlinesw;
    char  *rdata,*wdata;
//****************************************
	spacelen=Pparm[PARM_SPACELEN];
    rdata=Pfmtdataline;
    wdata=Pextdataline;
    shortlinesw=0;
	for (ii=0,outfldseq=0;ii<Sextfieldtblindex;ii++)
    {
		fldno=Sextfieldtbl[ii]; //field spec sequence
        if (fldno>(Pextoffstblindex/2))	//data has no the field
        {
        	if (fldno<=Sextlastpos)
	            shortlinesw=1;
        	continue;
        }
        pint=Pextoffstbl+(fldno-1)*2;
        if (outfldseq++)	//2nd fld
        {
        	memcpy(wdata,Sstrodelm,(UINT)spacelen);
            wdata+=spacelen;
        }
        else    //1st field
        {
        	memset(wdata,' ',TOPSPACELEN);
            wdata+=TOPSPACELEN;
        }
        offs=*pint;
        len=*(pint+1);
        memcpy(wdata,rdata+offs,(UINT)len);
        wdata+=len;
    }
//  len=(int)((ULONG)wdata-(ULONG)Pextdataline);                   //~va66R~
    len=(int)((ULPTR)wdata-(ULPTR)Pextdataline);                   //~va66I~
    if (shortlinesw)
        Sshortlinectr++;
	return len;
}//extractdata
//****************************************************************
// check field width secperated by tab/space(tab is already expanded)
//*ret :0, 1:over maxfld
//****************************************************************
int tc_chkfieldwidth(int *Pparm,char *Plinedata,int Plinelen,int *Pfmttb,int Pparmmaxfldno,int *Pmaxfldno,
    					int *Pmaxlrecl,char *Pfmtfldtbl)
{
    int len,rc=0,fldno,ovflen=0,rlen;
    int nofmtsw,netlen;
    char  *pc,*pce,*pcw,*pcwnum;                                   //~0034R~
    int complen;
    int upno,fldstrpos,startoffs;                                  //~0020R~
    LONG wklv[4];
    char curdelm,prevdelm=0;                                       //~0034R~
	int numonlynumlen,fmtflag;                                     //~0034R~
//****************************************
//  maxfldno=*Pmaxfldno;
	pc=Plinedata;
    rlen=Plinelen;
//  delm=Pparm[PARM_DELM];
    if (rlen>*Pmaxlrecl)
    	*Pmaxlrecl=rlen;	//work len
    pce=pc+rlen;
//  for (fldno=0;pc<pce;)
    for (fldno=0;;)
    {
    	len=(int)umemspnc(pc,' ',(UINT)rlen);
        pc+=len;
        rlen-=len;
        if (rlen<=0)
//        if (!fldno || Sdelm==' ')//all space or space after delm=' '
          if (!fldno || prevdelm==' ')//all space or space after delm=' '//~0006R~
        	break;
        if (fldno>=Pparmmaxfldno)
		{
//       	ovflen=(int)((ULONG)pce-(ULONG)pc);                    //~va66R~
         	ovflen=(int)((ULPTR)pce-(ULPTR)pc);                    //~va66I~
            if (Pfmttb[0]<ovflen)
    			Pfmttb[0]=ovflen;		//update max len of the field
        	break;
		}
        fmtflag=Pfmtfldtbl[fldno];                                 //~0034I~
        fldno++;
//      pcw=tc_getfieldendaddr(Pparm,pc,rlen,0,&complen,(int)Pfmtfldtbl[fldno-1],wklv);//~0034R~
        pcw=tc_getfieldendaddr(Pparm,pc,rlen,0,&complen,(int)Pfmtfldtbl[fldno-1],wklv,&numonlynumlen,&pcwnum);//~0034R~
        nofmtsw=0;
        if (pcw)
        {
//      	len=(int)((ULONG)pcw-(ULONG)pc);                       //~va66R~
        	len=(int)((ULPTR)pcw-(ULPTR)pc);                       //~va66I~
//  		pcw=tc_chknonfmtfieldwidth(pcw,rlen-len,Pfmtfldtbl,&fldno,&len,&nofmtsw);
    		pcw=tc_chknonfmtfieldwidth(Pparm,pcw,rlen-len,Pfmtfldtbl,&fldno,&len,&nofmtsw);
            if (nofmtsw)	//no fmt fields
            	complen=len;	//no compress
        }
        else
        	len=rlen;
//      if (Snumonlysw>=0)	//not compress mode
        if (!(fmtflag & FMTFLAG_COMPRESS))	//not compress mode    //~0034R~
        	complen=len;

		if (pcw)                                                   //~0006I~
          if (len)                                                 //~0034I~
        	curdelm=*pcw;                                          //~0006I~
          else          //numonly field has no preceding non-num fields//~0034I~
            curdelm=' ';                                           //~0034I~
        else                                                       //~0006I~
        	curdelm=0;                                             //~0006I~
        if ((fmtflag & FMTFLAG_COMPRESS))	//not compress mode    //~0034R~
        	netlen=complen;                                        //~0027I~
        else                                                       //~0027I~
//      if (!nofmtsw && Sdelm!=' ')
        if (!nofmtsw && curdelm!=' ')                              //~0006R~
//      	netlen=len-(int)umemrspnc(pc,' ',(UINT)len);//cut last space
        	netlen=complen-(int)umemrspnc(pc,' ',(UINT)complen);//cut last space
        else
//      	netlen=len;
        	netlen=complen;
//      if (Pfmttb[fldno]<len)
//      	Pfmttb[fldno]=len;		//update max len of the field
        if (wklv[1]!=-1)	//fld is numeric
        {
          if (fmtflag & FMTFLAG_POINTALIGN)	//not compress mode    //~0034R~
          {
        	upno=(int)(wklv[1]&UCALC_UPMASK);	//underpoint digit count//~0022R~
            if (upno)
            {
            	upno++;		//for "."
        		if (Pfmtfldtbl[fldno+MAXFIELD-1]<upno)
        			Pfmtfldtbl[fldno+MAXFIELD-1]=(char)upno;
            }
           	upno=netlen-upno;	//digit over up
        	if (Pfmtfldtbl[fldno+MAXFIELD+MAXFIELD-1]<upno)
        		Pfmtfldtbl[fldno+MAXFIELD+MAXFIELD-1]=(char)upno;
          }//point align
        }
        if (!(fmtflag & FMTFLAG_POINTALIGN))	//not point align  //~0034R~
        {                                                          //~0020I~
            if (Sfieldstrlen[fldno-1])  //determin substring pos   //~0020R~
            {                                                      //~0020R~
                getsubstrbyfldstr(fldno-1,pc,netlen,&fldstrpos);   //~0020R~
                startoffs=fldstrpos;                               //~0020I~
            }                                                      //~0020R~
            else                                                   //~0020R~
                startoffs=Sfieldcutoffs[fldno-1];                  //~0020I~
            getsubstrfieldlen(fldno-1,netlen,startoffs,pc,&netlen,0);//~0020R~
        }                                                          //~0020I~
        if (Pfmttb[fldno]<netlen)
        	Pfmttb[fldno]=netlen;		//update max len of the field
        if ((fmtflag & FMTFLAG_NUMONLY))	//not compress mode    //~0034I~
        {                                                          //~0034I~
        	if (Pfmtfldtbl[fldno-1+MAXFIELD+MAXFIELD+MAXFIELD]<numonlynumlen)//~0034R~
        		Pfmtfldtbl[fldno-1+MAXFIELD+MAXFIELD+MAXFIELD]=(char)numonlynumlen;//~0034R~
            if (numonlynumlen)	//num field found                  //~0034I~
            {                                                      //~0034I~
            	pcw=pcwnum+numonlynumlen;                          //~0034I~
//      		len=(int)((ULONG)pcw-(ULONG)pc);                   //~0034R~//~va66R~
        		len=(int)((ULPTR)pcw-(ULPTR)pc);                   //~va66I~
                if (len>=rlen)                                     //~0034I~
                	pcw=0;                                         //~0034I~
                else                                               //~0034I~
	                curdelm=*pcw;                                  //~0034I~
            }                                                      //~0034I~
            else                                                   //~0034I~
            	pcw=0;	//eol break                                //~0034I~
        }                                                          //~0034I~
        rlen-=len;
        if (!pcw)
        	break;
        prevdelm=curdelm;                                          //~0006I~
		pc=pcw;
        pc++;           //skip seperator
        rlen--;
	}
    if (fldno>*Pmaxfldno)
    	*Pmaxfldno=fldno;
    return rc;
}//tc_chkfieldwidth
//**************************************************************** //~0019I~
// get substring field width                                       //~0019I~
//**************************************************************** //~0019I~
int getsubstrfieldlen(int Pfldno,int Pnetlen,int Pstartoffs,char *Pflddata,int *Ppfldlen,int *Ppshiftlen1)//~0020R~
{                                                                  //~0019I~
	int opt2,excludesw,fldmaxlen,fldlen,fldendoffs,pos1,pos2,shiftlen1=0,uptoeolsw;//~0019R~
    int pos1a,fldstrpos2;                                          //~0020R~
//************************************                             //~0019I~
	opt2=Sfieldopt2[Pfldno];                                       //~0019I~
	fldmaxlen=Sfieldmaxlen[Pfldno];                                //~0019I~
	fldendoffs=Sfieldendoffs[Pfldno];                              //~0019I~
    excludesw=(opt2 & SFO2_EXCLUDE);	//exclude upto end of field//~0019I~
    uptoeolsw=!(opt2 & (SFO2_SUBSTRLEN|SFO2_SUBSTRENDCOL));	//exclude upto end of field//~0019I~
    if (Pstartoffs<0)   //from rear                                //~0019R~
        pos1=Pnetlen+Pstartoffs;                                   //~0019I~
    else                                                           //~0019I~
        pos1=Pstartoffs;                                           //~0019I~
    pos1a=max(0,pos1);                                             //~0020I~
    pos1a=min(pos1a,Pnetlen);	//pos in the field                 //~0020I~
	if (Sfieldstrlen2[Pfldno])                                     //~0020I~
    {                                                              //~0020I~
        if (getsubstrbyfldstr2(Pfldno,Pflddata+pos1a,Pnetlen-pos1a,&fldstrpos2))//not found//~0020I~
        	if (excludesw)                                         //~0020R~
            	pos2=pos1;                                         //~0020I~
            else                                                   //~0020I~
            	pos2=Pnetlen;                                      //~0020I~
        else                                                       //~0020I~
        	pos2=pos1a+fldstrpos2;                                 //~0020R~
    }                                                              //~0020I~
    else                                                           //~0020I~
    {                                                              //~0020I~
        if (opt2 & SFO2_SUBSTRENDCOL)   //endpos by column         //~0020R~
            if (fldendoffs<0)                                      //~0020R~
                pos2=Pnetlen+fldendoffs;                           //~0020R~
            else                                                   //~0020R~
                pos2=fldendoffs;                                   //~0020R~
        else        //end col by len                               //~0020R~
            if (uptoeolsw)                                         //~0020R~
                pos2=Pnetlen;                                      //~0020R~
            else                                                   //~0020R~
                pos2=pos1+fldmaxlen;                               //~0020R~
    }                                                              //~0020I~
                                                                   //~0019I~
    pos1=pos1a;                                                    //~0020R~
    pos2=max(0,pos2);                                              //~0020I~
    pos2=min(Pnetlen,pos2);                                        //~0019I~
    if (pos2>=pos1)                                                //~0019I~
        if (excludesw)  //inter-region string cut                  //~0019I~
        {                                                          //~0019I~
        	shiftlen1=pos1;                                        //~0019I~
            fldlen=pos1+Pnetlen-pos2;                              //~0019I~
        }                                                          //~0019I~
        else    //not exclude                                      //~0019I~
            fldlen=pos2-pos1;                                      //~0019I~
    else                                                           //~0019I~
        if (excludesw)  //inter-region string cut                  //~0019I~
        {                                                          //~0019I~
        	shiftlen1=Pnetlen;                                     //~0019I~
            fldlen=Pnetlen;                                        //~0019I~
        }                                                          //~0019I~
        else    //not exclude                                      //~0019I~
            fldlen=0;                                              //~0019I~
    *Ppfldlen=fldlen;                                              //~0019I~
    if (Ppshiftlen1)                                               //~0019I~
    	*Ppshiftlen1=shiftlen1;                                    //~0019I~
    return 0;                                                      //~0019I~
}//getsubstrfieldlen                                               //~0019R~
//****************************************************************
// search end addr of a field
//        (zmax 2**64=18,446,744,073,709,551,616)
//p1:fld addr
//p2:record residual len
//*ret :fld end addr
//****************************************************************
char *tc_getfieldendaddr(int *Pparm,char *Prec,int Preclen,
//  					char *Ppcwdata,int *Ppcomplen,int Pfmtflag,LONG *Pnumval)//~0034R~
    					char *Ppcwdata,int *Ppcomplen,int Pfmtflag,LONG *Pnumval,int *Ppnumlen,char **Ppnumfld)//~0034R~
{
	char *pc,*pcw,*prevend=0,*pnumfld=0;                           //~0034R~
    int len,rlen;
    char numwk[64];
//  ULONG dwwk[2];
//  LONG dwwk[2];
    int totcomp=0,complen,taillen,numsw=0;                           //~0009R~//~va64R~
    int qchksw;
    char *pcwdata,*pcomp,*pcwdelm=0;
    int rc;
    char curdelm;                                                  //~0006I~
    int nonumcontsw=0;                                             //~0028I~
    int numchksw,numonlynumlen=0;                                  //~0034R~
//*****************************
//  delm=Pparm[PARM_DELM];
//  spacelen=Pparm[PARM_SPACELEN];                                 //~0009R~
	numchksw=!(Pfmtflag & FMTFLAG_COMPRESS) //no compress          //~0029R~
	  	   || (Pfmtflag & FMTFLAG_NUMONLY);	//search num field     //~0029R~
	Pnumval[1]=-1;	//id of not numeric
	pc=Prec;
    rlen=Preclen;
    pcwdata=Ppcwdata;
//  pcwdbcs=Ppcwdbcs;
    qchksw=Pparm[PARM_HDRSW]&(PARM_SQUOTE|PARM_DQUOTE);     //chk quotation
    for (;rlen>0;)
    {
        len=(int)umemspnc(pc,' ',(UINT)rlen);
        pc+=len;
        rlen-=len;
        pcwdelm=
//      pcw=memchr(pc,Sdelm,(UINT)rlen);
//      pcw=memchr(pc,delm,(UINT)rlen);
        pcw=umempbrk(pc,Sstridelm,(UINT)rlen);
//chk quotation
        if (qchksw)
//      	pcwdelm=pcw=tc_getfieldendaddrquote(pc,rlen,Sdelm,pcw,qchksw);
        	pcwdelm=pcw=tc_getfieldendaddrquote(pc,rlen,Sstridelm,pcw,qchksw);//~0006R~
        if (pcw)
        {                                                          //~0006I~
//      	len=(int)((ULONG)pcw-(ULONG)pc);   //fld len           //~va66R~
        	len=(int)((ULPTR)pcw-(ULPTR)pc);   //fld len           //~va66I~
            curdelm=*pcw;                                          //~0006I~
        }                                                          //~0006I~
        else
        {                                                          //~0006I~
            len=rlen;    //continue for remining prevend
            curdelm=0;                                             //~0006I~
        }                                                          //~0006I~
//      if (!Snumonlysw)	//not num only
//      if (!(Pfmtflag&FMTFLAG_NUMONLY))	//not num only
//      	break;
//      if (!pcw)
//          pcw=pc+rlen;    //continue for remining prevend
//      len=(ULONG)pcw-(ULONG)pc;   //fld len
        pcw=pc+len;
        rlen-=len+1;
//      if (Sdelm!=' ')
        if (curdelm!=' ')                                          //~0006R~
        {
//          len-=(int)umemrspnc(pc,' ',(UINT)len);
            taillen=(int)umemrspnc(pc,' ',(UINT)len);
            len-=taillen;
        }
        pcomp=pc;	//compress data top
        complen=len;
        numsw=0;
	  	if (!(Pfmtflag & FMTFLAG_OVERFLOW))	//not overflow fld specification
      	{
		  if (numchksw)                                            //~0029R~
          {                                                        //~0029R~
          	pnumfld=pc;                                            //~0034I~
        	if (*pc=='-'||*pc=='+')
        	{
        		pc++;
            	len--;
        	}
        	if (len<sizeof(numwk))
        	{
            	memcpy(numwk,pc,(UINT)len);
            	*(numwk+len)=0;
//          	if (ucalc_ld2dw(numwk,dwwk)<4)	//allow Z fmt and underpoint
            	rc=bc_getld(GETLD_DWUP,numwk,Pnumval);	//0:word,1:dword,else err
            	if (rc>=4)
		        	rc=ucalc_gettimevalue(numwk,0,Pnumval);   //by strlen
            	if (rc<4)
            	{
//                  if (prevend)    //prev iouly chked non numeric fld//~0034R~
//                  {                                              //~0034R~
//                      Pnumval[1]=-1;  //after non numeric        //~0034R~
////                    pcw=prevend;    //return prev nun numric fld end addr//~0034R~
//                      pcwdelm=prevend;    //return prev nun numric fld end addr//~0034R~
//                      numsw=-1;       //next is numfld           //~0034R~
//                      totcomp--;      //drop last delm           //~0034R~
//                  }                                              //~0034R~
////                    break;                                     //~0034R~
//                    else                                         //~0034R~
                		numsw=1; 	//first is num fld
            	}
        	}
          }//numchksw                                              //~0029R~
	  	}//not overflow fld specification
//      if (numsw>=0)   //not num or strat is num                  //~0034R~
//      {                                                          //~0034R~
//          if (pcwdata)	//compress req from tc_fmtdata
            if (pcwdata 	//after  malloc
            &&  Pfmtflag & FMTFLAG_COMPRESS)	//compress req from tc_fmtdata
            {
//              offs=(int)((ULONG)pcomp-(ULONG)Prec);              //~0009R~
                memcpy(pcwdata,pcomp,(UINT)(complen));
//              memcpy(pcwdbcs,Ppdbcs+offs,(UINT)(complen));
                pcwdata+=complen;
//              pcwdbcs+=complen;
            }
	        totcomp+=complen;
//      }//numsw>=0                                                //~0034R~
	  	if (!(Pfmtflag & FMTFLAG_OVERFLOW))	//not overflow fld specification
      	{
		  if (numchksw) //!compress or numonly                     //~0029R~
          {                                                        //~0029R~
        	if (!(Pfmtflag&FMTFLAG_NUMONLY))	//not num only
        		break;
        	if (numsw)
            {              //NUMONLY field detected num field      //~0034I~
                if (prevend)                                       //~0034I~
                {                                                  //~0034I~
                    pcwdelm=prevend;    //cut by non numeric field //~0034I~
                    totcomp--;          //for delm                 //~0034I~
                }                                                  //~0034I~
                else                                               //~0034I~
                    pcwdelm=Prec;       //cut by non numeric field,fldlen=0//~0034I~
                numonlynumlen=complen; //NUMONLY field numlen      //~0034R~
                totcomp-=complen;      //compressed len            //~0034R~
            	break;
            }                                                      //~0034I~
          }//numchksw                                              //~0029R~
	  	}//not overflow fld specification
        prevend=pcw;
        pc=pcw+1;
    	if (rlen>0)   	//not end of rec
        {
//      	if (pcwdata)	//compress req from tc_fmtdata
        	if (pcwdata 	//after malloc
            &&  Pfmtflag & FMTFLAG_COMPRESS)	//compress req from tc_fmtdata
            {
//          	*pcwdata++=Sdelm;
            	*pcwdata++=curdelm;                                //~0006R~
//              *pcwdbcs++=0;
			}
            totcomp++;  //for intermediate delm
    		nonumcontsw=1;                                         //~0028I~
        }
    }//until eol
    if (!numsw && nonumcontsw)//end by not numeric and intermediate delm space len added//~0028I~
    	totcomp--;                                                 //~0028R~
    if (Ppnumlen)                                                  //~0034R~
	    *Ppnumlen=numonlynumlen;   //numeric fld len for numonly field//~0034R~
    if (Ppnumfld)                                                  //~0034I~
    	*Ppnumfld=pnumfld;	//num fld addr                         //~0034I~
    if (Ppcomplen)
	    *Ppcomplen=totcomp;
//  return pcw; 	//next fld top addr
    return pcwdelm; 	//next fld top addr
}//tc_getfieldendaddr
//****************************************************************
// get field end addr with quotation consideration
//p1:fld start addr
//p2:record len
//p3:delm
//p4:addr of delm detected or 0 if no delm found
//p5:qchk option
//*ret :fld end addr or 0 if no delm found
//****************************************************************
char *tc_getfieldendaddrquote(char *Prec,int Preclen,char *Pdelmstr,char *Pdelmaddr,int Popt)//~0006R~
{
#define CHAR_DQ          '\"'    //double quote
#define CHAR_SQ          '\''    //single quote
	char *pcs,*pcdq,*pcsq,*pc,*pce;
    int chkdq,chksq,swinquote,fldlen,delm;
//*************************
    pce=Prec+Preclen;  	//record end addr
    if (Pdelmaddr)
//  	fldlen=(int)((ULONG)Pdelmaddr-(ULONG)Prec);   //fld len    //~va66R~
    	fldlen=(int)((ULPTR)Pdelmaddr-(ULPTR)Prec);   //fld len    //~va66I~
    else
    	fldlen=Preclen;
	if ((chkdq=Popt&PARM_DQUOTE),chkdq)     //'\"' chk
		pcdq=memchr(Prec,CHAR_DQ,(UINT)fldlen);
    else
    	pcdq=0;
	if ((chksq=Popt&PARM_SQUOTE),chksq)     //'\"' chk
		pcsq=memchr(Prec,CHAR_SQ,(UINT)fldlen);
    else
    	pcsq=0;
    if (!pcdq && !pcsq)
//  	return Prec+fldlen;	//no quote before delm                 //~0008R~
    	return Pdelmaddr;	//no delm addr changed                 //~0008I~
	if (pcdq && pcsq)
        if (pcdq<pcsq)
            delm=CHAR_DQ;
        else
            delm=CHAR_SQ;
    else
        if (pcdq)
            delm=CHAR_DQ;
        else
          	delm=CHAR_SQ;
    if (delm==CHAR_DQ)
    	pcs=pcdq;
    else
    	pcs=pcsq;
//search end of quatation
    swinquote=1;
    for (pc=pcs+1;pc<pce;pc++)
    {
    	if (*pc==delm)
        {
        	if (pc+1<pce && *(pc+1)==delm)	//""(cotinuous)
            {
            	pc++;
                continue;
            }
            swinquote^=1;
        }
        else
        if (*pc=='\\')
        {
        	if (pc+1<pce && *(pc+1)==delm)	//\"(escape)
            {
            	pc++;
                continue;
            }
        }
        else
        {                                                          //~0006I~
//      if (*pc==Pdelm)                                            //~0006R~
        	if (!swinquote)	//not in quote
              if (strchr(Pdelmstr,*pc))	//one of delm char         //~0006I~
	        	break;
        }                                                          //~0006I~
    }
    if (pc>=pce)
    	return 0;
    return pc;
}//tc_getfieldendaddrquote
//****************************************************************
// calc fld width of non fmt fld
//p1:fld end(' ') addr
//p2:record residual len(from fld end)
//p3:fmtfld tbl
//p4:input:current fldno, output:last fldno for non fmt fld
//p5:input:current fld len, output:concat len when non fmt fld
//*ret :fld end addr
//****************************************************************
//char *tc_chknonfmtfieldwidth(char *Prec,int Preclen,char *Pfmtfldtbl,
char *tc_chknonfmtfieldwidth(int *Pparm,char *Prec,int Preclen,char *Pfmtfldtbl,
							int *Ppfldno,int *Ppfldlen,int *Ppnofmtsw)
{
//  int ii,bytepos,ch,bit,fldno,rlen,len,idxlast,nofmtsw=0;        //~va64R~
    int ii,bytepos,ch,bit,fldno,rlen,len,idxlast=0,nofmtsw=0;      //~va64I~
    char  *pc,*rec,*pclast;
    LONG wklv[4];
//****************************************
//calc non fmt fld concatinated len
    fldno=*Ppfldno;
	rlen=Preclen;
    pc=Prec+1;          //for 1st loop                             //~0007R~
	rec=Prec;
    pclast=rec;			//last end of fld space addr          
    for (ii=fldno;;ii++)
    {
//      bytepos=(ii-1)/8;
        bytepos=(ii-1);
        ch=*(Pfmtfldtbl+bytepos);
//      bit=(0x80>>((ii-1)%8));
        bit=FMTFLAG_FMT;
        if ((ch & bit))     //use this fld
            break;
        nofmtsw=1;
        pclast=rec;                                           
        idxlast=ii;
        if (!rec)
        	break;
        rec=pc;     //2nd loop delm advanced
//        len=(int)umemspnc(rec,' ',(UINT)rlen);
//        rec+=len;
//        rlen-=len;
////      pc=memchr(rec,' ',(UINT)rlen);
//        pc=memchr(rec,Sdelm,(UINT)rlen);
//  	pc=tc_getfieldendaddr(Pparm,rec,rlen,0,0,ch,wklv);         //~0034R~
    	pc=tc_getfieldendaddr(Pparm,rec,rlen,0,0,ch,wklv,0,0);     //~0034R~
        if (pc)
//          len=(int)((ULONG)pc-(ULONG)rec);                       //~va66R~
            len=(int)((ULPTR)pc-(ULPTR)rec);                       //~va66I~
        else
        	len=rlen;
        rec=pc;
        rlen-=len;
        if (pc)
        {
        	pc++;           //skip seperator
        	rlen--;
        }
    }
    if (pclast!=Prec)
    {
        if (pclast)
//          *Ppfldlen+=(int)((ULONG)pclast-(ULONG)Prec);           //~va66R~
            *Ppfldlen+=(int)((ULPTR)pclast-(ULPTR)Prec);           //~va66I~
        else
        	*Ppfldlen+=Preclen;
    	*Ppfldno=idxlast;
    }
    if (Ppnofmtsw)
    	*Ppnofmtsw=nofmtsw;
    return pclast;
}//tc_chknonfmtfieldwidth
//****************************************************************
// get valid plh
//*rc   :-1:eof or readlen except last \n
//****************************************************************
//int getline(int Pinitsw,char *Pbuff,int Pbuffsz,int *Pparm)      //~va4fR~
int xfmt_getline(int Pinitsw,char *Pbuff,int Pbuffsz,int *Pparm)   //~va4fI~
{
//  int len,lens,ii,swselect,typ,col,prevtyp,sw1st=1;              //~va29R~
    int len,lens,ii,swselect,typ,col,prevtyp,sw1st;                //~va29I~
    int readlen;                                                   //~0026R~
	char *str,*pc;                                                 //~0024R~
//*********************************
	if (Pinitsw)
    {
    	Sreadline=0;
    	Sstartsw=0;
    	Sendsw=0;
        Sskipctr=0;
    }
    for (;;)
    {                                                              //~5323R~
      if (Slrecl)                                                  //~0023I~
      {                                                            //~0023I~
	    if ((readlen=(int)fread(Pbuff,1,(UINT)Pbuffsz,Sfh))<=0)    //~va29R~
        	return -1;                                             //~0023I~
      }                                                            //~0023I~
      else                                                         //~0023I~
      {                                                            //~0023I~
	    if (!fgets(Pbuff,Pbuffsz,Sfh))                             //~0024R~
        	return -1;
        pc=memchr(Pbuff,'\n',(UINT)Pbuffsz);                       //~0024I~
        if (pc)                                                    //~0024I~
        {                                                          //~0025I~
//        	readlen=(int)((ULONG)pc-(ULONG)Pbuff);                 //~0024R~//~va66R~
          	readlen=(int)((ULPTR)pc-(ULPTR)Pbuff);                 //~va66I~
#ifndef UNX                                                        //~0025I~
			if (readlen && *(pc-1)==0x0d)                          //~0025I~
            	readlen--;                                         //~0025I~
#endif                                                             //~0025I~
        }                                                          //~0025I~
        else                                                       //~0024I~
        {	                                                       //~0024I~
        	uerrmsg("line %d is too long",0,Sreadline+1);          //~0024I~
            readlen=Pbuffsz-1;                                     //~0024I~
        }                                                          //~0024I~
      }                                                            //~0023I~
    	Sreadline++;                                                //~5323I~
      	len=readlen;                                               //~0026M~
//debug if (umemstr(Pbuff,"15:21:11.525",(UINT)readlen))           //~va29R~
//code  {                                                          //~va29R~
//          readlen=readlen;                                       //~va29R~
//      }                                                          //~va29R~
    	if (Sstrxstart)                                              //~5323I~
        	if (!Sstartsw)                                          //~5323I~
            {
            	if (Sstrxstartcols)                         //~5323I~
                    if (Sstrxstartcols-1+Sstrxstartlen>readlen)    //~0032I~
                    	Sstartsw=0;                                //~0032I~
                    else                                           //~0032I~
                	Sstartsw=memcmp(Pbuff+Sstrxstartcols-1,Sstrxstart,(UINT)Sstrxstartlen)==0;
                else
            		Sstartsw=(umemstr(Pbuff,Sstrxstart,(UINT)readlen)!=0);//~0024R~
                if (Sstartsw)                                      //~0032I~
					Sstartsw=seandchk('S',Pbuff,readlen);          //~0032R~
                if (!Sstartsw)
                {
					writeout2(Pbuff,len);//not skip mode           //~0026I~
                	continue;
                }
            }
    	if (Sstrxend)                                                //~5323I~
        {                                                          //~0021I~
        	if (!Sendsw)                                            //~5323I~
            {
            	if (Sstrxendcols)                         //~5323I~
                    if (Sstrxendcols-1+Sstrxendlen>readlen)        //~0032I~
                    	Sendsw=0;                                  //~0032I~
                    else                                           //~0032I~
                	Sendsw=memcmp(Pbuff+Sstrxendcols-1,Sstrxend,(UINT)Sstrxendlen)==0;
                else
            		Sendsw=(umemstr(Pbuff,Sstrxend,(UINT)readlen)!=0);//~0024R~
                if (Sendsw)                                        //~0032I~
					Sendsw=seandchk('E',Pbuff,readlen);            //~0032R~
            }
            else
            {                                                      //~0026I~
				if (writeout2(Pbuff,len))//written,continue to eof //~0026I~
                	continue;                                      //~0026R~
            	return -1;
            }                                                      //~0026I~
        }                                                          //~0021I~
        swselect=1;
        sw1st=1;                                                   //~va29I~
        for (ii=0;ii<Sstrselectctr;ii++)                                  //~5323I~
        {                                                          //~5323I~
        	str=Sstrselect[ii];
            prevtyp=(int)((UINT)(Sstrselectflag[ii])>>8);          //~va29R~
        	typ=Sstrselectflag[ii]&255;                            //~0032R~
        	col=Sstrselectcols[ii];
        	lens=Sstrselectlen[ii];
            if (typ=='I')	//include
            {
                if (sw1st)            //start by I                 //~0032R~
                {                                                  //~0032I~
                    swselect=0;     //asume exclude all
                    sw1st=0;                                       //~0032I~
                }                                                  //~0032I~
            	if (!swselect)
                {
                    	if (col)
		                    if (col-1+lens>readlen)                //~0032I~
        	            		swselect=0;                        //~0032I~
            		        else                                   //~0032I~
	                        swselect=memcmp(Pbuff+col-1,str,(UINT)lens)==0;
                        else
	                        swselect=umemstr(Pbuff,str,(UINT)readlen)!=0;//~0024R~
                }
            }
            else            //exclude
            if (typ=='X')	//include                              //~0031I~
            {
                if (sw1st)            //start by X                 //~0032R~
                {                                                  //~0032I~
                    swselect=1;     //asume select  all
                    sw1st=0;                                       //~0032I~
                }                                                  //~0032I~
            	if (swselect)
                {
                    	if (col)
		                    if (col-1+lens>readlen)                //~0032I~
        	            		swselect=1;                        //~0032I~
                            else                                   //~0032I~
	                        swselect=memcmp(Pbuff+col-1,str,(UINT)lens)!=0;
                        else
	                        swselect=umemstr(Pbuff,str,(UINT)readlen)==0;//~0024R~
                }
            }
            else            //+ and                                //~0031I~
            {                                                      //~0031I~
            	if (prevtyp=='I')	//include and                  //~0031I~
                {                                                  //~0031I~
                	if (swselect)                                  //~0031I~
                    {                                              //~0031I~
                    	if (col)                                   //~0031I~
		                    if (col-1+lens>readlen)                //~0032I~
        	            		swselect=0;                        //~0032I~
                            else                                   //~0032I~
	                        swselect=memcmp(Pbuff+col-1,str,(UINT)lens)==0;//~0031I~
                        else                                       //~0031I~
	                        swselect=umemstr(Pbuff,str,(UINT)readlen)!=0;//~0031I~
                    }                                              //~0031I~
                }                                                  //~0031I~
                else				//exclude and                  //~0031I~
            	if (prevtyp=='X')	//include and                  //~0032I~
                {                                                  //~0031I~
                	if (!swselect)                                 //~0031I~
                    {                                              //~0031I~
                    	if (col)                                   //~0031I~
		                    if (col-1+lens>readlen)                //~0032I~
        	            		swselect=1;                        //~0032I~
                            else                                   //~0032I~
	                        swselect=memcmp(Pbuff+col-1,str,(UINT)lens)!=0;//~0031I~
                        else                                       //~0031I~
	                        swselect=umemstr(Pbuff,str,(UINT)readlen)==0;//~0031I~
                    }                                              //~0031I~
                }                                                  //~0031I~
            }                                                      //~0031I~
        }                                                          //~5323I~
        if (!swselect)
        {
			writeout2(Pbuff,len);                                  //~0026R~
        	continue;                                              //~5323I~
        }
        break;
    }//from startid to endid and not except specification
    *(Pbuff+len)=0;                                                //~0026I~
    return len;
}//xfmt_getline                                                    //~va4fR~
//**********************************************************************//~0032I~
//* start/end and condition chk                                    //~0032I~
//**********************************************************************//~0032I~
int seandchk(int Ptyp,char *Pbuff,int Plen)                        //~0032I~
{                                                                  //~0032I~
	int prevtyp,typ,col,lens,swselect=1,ii;                        //~0032R~
    char *str;                                                     //~0032I~
//************                                                     //~0032I~
    for (ii=0;ii<Sstrselectctr;ii++)                               //~0032I~
    {                                                              //~0032I~
        str=Sstrselect[ii];                                        //~0032I~
        prevtyp=(int)((UINT)(Sstrselectflag[ii])>>8);              //~va29R~
        typ=Sstrselectflag[ii]&255;                                //~0032I~
        col=Sstrselectcols[ii];                                    //~0032I~
        lens=Sstrselectlen[ii];                                    //~0032I~
        if (typ=='+' && prevtyp==Ptyp)  //and of parm typ(start/end)//~0032I~
        {                                                          //~0032I~
            if (col)                                               //~0032I~
		        if (col-1+lens>Plen)                               //~0032I~
        	    	swselect=0;                                    //~0032I~
                else                                               //~0032I~
	                swselect=memcmp(Pbuff+col-1,str,(UINT)lens)==0;//~0032R~
            else                                                   //~0032I~
                swselect=umemstr(Pbuff,str,(UINT)Plen)!=0;         //~0032R~
        }                                                          //~0032I~
        if (!swselect)	//false                                    //~0032I~
        	break;                                                 //~0032I~
    }                                                              //~0032I~
    return swselect;                                               //~0032I~
}//seandchk                                                        //~0032I~
//**********************************************************************//~0026I~
//* write exception file                                           //~0026I~
//**********************************************************************//~0026I~
int writeout2(char *Pbuff,int Plen)                                //~0026I~
{                                                                  //~0026I~
	int rc=0;                                                      //~0026I~
//****************                                                 //~0026I~
    Sskipctr++;                                                    //~0026I~
	if (Sfho2)                                                     //~0026I~
		if (!Sskipxout)                                            //~0026I~
        {                                                          //~0026I~
			fwrite(Pbuff,1,(UINT)Plen,Sfho2);                      //~va29R~
	        fwrite("\n",1,1,Sfho2);                                //~0026I~
            rc=1;                                                  //~0026I~
        }                                                          //~0026I~
	return rc;                                                     //~0026I~
}//writeout2                                                       //~0026I~
//****************************************************************
int opderr(char *Pparm)
{
    uerrexit("parm(%s) err",0,Pparm);
    return 4;
}//opderr
//**********************************************************************//~0004I~
//* confirm                                                        //~0004I~
//**********************************************************************//~0004I~
char confirm(char *Pmsg,char *Preply)                              //~0004I~
{                                                                  //~0004I~
    char  reply,*pc;                                               //~0004R~
//**********                                                       //~0004I~
    uerrmsg(Pmsg,Pmsg);                                            //~0004I~
	for (;;)                                                       //~0004I~
    {                                                              //~0004I~
#ifdef UNX                                                         //~0004I~
        while(kbhit())                                             //~0004I~
	    	getch_nc();  //getch not under curses                  //~0004I~
#else                                                              //~0004I~
#ifdef DOS                                                         //~0004I~
        while(kbhit())                                             //~0004I~
	    	getch();                                               //~0004I~
#else                                                              //~0004I~
	#ifdef W32                                                     //~0004I~
        while(_kbhit())                                            //~0004I~
	    	_getch();                                              //~0004I~
    #else                                                          //~0004I~
        while(_kbhit())                                            //~0004I~
	    	_getch();                                              //~0004I~
    #endif                                                         //~0004I~
#endif                                                             //~0004I~
#endif                                                             //~0004I~
        printf("===>");                                            //~0004I~
        fflush(stdout);                                            //~0004I~
#ifdef UNX                                                         //~0004I~
    	reply=(UCHAR)getch_nc();                                   //~0004I~
#else                                                              //~0004I~
#ifdef DOS                                                         //~0004I~
    	reply=(UCHAR)getch();                                      //~0004I~
#else                                                              //~0004I~
	#ifdef W32                                                     //~0004I~
    	reply=(UCHAR)_getch();                                     //~0004I~
    #else                                                          //~0004I~
    	reply=(UCHAR)_getch();                                     //~0004I~
    #endif                                                         //~0004I~
#endif                                                             //~0004I~
#endif                                                             //~0004I~
        if (!reply)         //pf-key etc                           //~0004I~
            reply=' ';                                             //~0004I~
        printf("%c\n",reply);                                      //~0004I~
    	pc=strchr(Preply,reply);                                   //~0004I~
        if (pc)                                                    //~0004I~
        	break;                                                 //~0004I~
    	uerrmsg("Invalid reply.",                                  //~0004I~
    	    	"無効な入力.");                                    //+vas4I~
	}                                                              //~0004I~
    return reply;                                                  //~0004I~
}//confirm                                                         //~0004I~
//****************************************************************
// hel for fmt
//*ret :0
//****************************************************************
int help(void)
{
        HELPMSG
"%s : %s=(%c)= file record formatting.\n",
"%s : %s=(%c)= ファイル行フォーマッティング。\n",                  //~vas4I~
                Spgm,Sver,OSTYPE);
        HELPMSG
"format:%s [%coptions] filename [fieldspec ...]\n",
"形式  :%s [%coptions] filename [fieldspec ...]\n",                //~vas4I~
                Spgm,CMDFLAG_PREFIX);
        HELPMSG
"  options    :\n",
"  options    :\n");
        HELPMSG
"    %cD\"delms\"  :additional input field delimiter. \n",
"    %cD\"delms\"  :追加の入力ファイルフィールド分離文字。\n",     //~vas4I~
				CMDFLAG_PREFIX);
        HELPMSG
"                  default is \" \\t\"(space and tab).\n",
"                  省略値は\" \\t\"(スペースとタブ)。\n");         //~vas4I~
        HELPMSG
"    %cL[n]x[str]:line selection string specification. n:column, x:S/E/I/X.\n",
"    %cL[n]x[str]:行選択文字列指定。n:カラム(行頭が 1)。x:S/E/I/X。\n",//~vas4I~
				CMDFLAG_PREFIX);
        HELPMSG
"                 S: line selection Start from the line containing this string.\n",//~0032R~
"                 S:この文字列を含む行から抽出開始。\n");          //~vas4I~
        HELPMSG
"                 E: line selection End with the line containing this string.\n",//~0032R~
"                 E:この文字列を含む行で抽出終了。\n");            //+vas4I~
        HELPMSG
"                 I: select the line Including this string.\n",    //~0032R~
"                 I:(Include)この文字列を含む行は抽出。\n");       //~vas4I~
        HELPMSG
"                 X: eXclude the line containing this string.\n",  //~0032R~
"                 X:(eXclude)この文字列を含む行は抽出しない。\n"); //~vas4I~
        HELPMSG                                                    //~0025I~
"                 +: AND condition of previous condition.\n",      //~0032R~
"                 +:前の 条件の AND 連結条件。\n");                //~vas4I~
        HELPMSG
"                I and X is checked sequencialy as specified. \n",
"                I と X は指定された順にチェックされる。\n");      //~vas4I~
        HELPMSG
"                assume full select if first is X. exclude all if start by I.\n",
"                最初が X なら全行抽出、最初が I なら全行非選択が仮定される。\n");//~vas4I~
        HELPMSG                                                    //~va45R~
"                ex) %cL8S\"12:00:00\" %cL8E\"13:00:00\"\n",       //~va45R~
"                例) %cL8S\"12:00:00\" %cL8E\"13:00:00\"\n",       //~vas4I~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);                    //~va45R~
        HELPMSG                                                    //~va45R~
"                    (line select start from the lines with \"12:00:00\"\n" ,//~va45R~
"                    (８桁目が\"12:00:00\"の行から\n");            //~vas4I~
        HELPMSG                                                    //~va45R~
"                     at column 8 to the line with \"13:00:00\" at column 8)\n",//~va45R~
"                     ８桁目が\"13:00:00\"までを抽出する)\n");     //~vas4I~
        HELPMSG                                                    //~va45R~
"                    %cLX\"Normal\" %cL20I\"Overridden\"\n",       //~va45R~
"                    %cLX\"Normal\" %cL20I\"Overridden\"\n",       //~va45R~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);                    //~va45R~
        HELPMSG                                                    //~va45R~
"                    (exclude the line with \"Normal\" at col.1\n",//~va45R~
"                    (1桁目が\"Normal\"で20桁目が\"Overridden\"でない行は\n");//~vas4I~
        HELPMSG                                                    //~va45R~
"                     except col.20 is \"Overridden\")\n",         //~va45R~
"                     選択しない)\n");                             //~vas4I~
        HELPMSG                                                    //~va45R~
"                    %cL5I\"RC\" %cL9+\"Ok\"\n",                   //~va45R~
"                    %cL5I\"RC\" %cL9+\"Ok\"\n",                   //~va45R~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);                    //~va45R~
        HELPMSG                                                    //~va45R~
"                    (select the lines with \"RC\" at col.5 and \"Ok\" at col.9)\n",//~va45R~
"                    (5桁目が\"RC\"で9桁目が\"Ok\"のを抽出)\n");   //~vas4I~
        HELPMSG                                                    //~0004I~
"    %cOoutfile  :output filename. default is stdout.\n",          //~0026R~
"    %cOoutfile  :出力ファイル名。省略値は標準出力。\n",           //~vas4I~
				CMDFLAG_PREFIX);                                   //~0004I~
        HELPMSG
"    %cQ[s][d]   :quotation consideration. ignore delmiter in quotationn.\n",
"    %cQ[s][d]   :引用符の考慮。引用符内の分離文字は無視。\n",     //~vas4I~
				CMDFLAG_PREFIX);
        HELPMSG
"                 s:single quotation, d:double quotation. %cQ means both.\n",
"                 s:一重引用符、d:二重引用符。%cQ のみは両方考慮。\n",//~vas4I~
				CMDFLAG_PREFIX);
        HELPMSG                                                    //~0023I~
"    %cRnn       :insert (CR)LF for each nn byte(for file with no EOL id).\n",//~0023I~
"    %cRnn       :改行文字を持たないファイルにnnバイトごとに改行文字を挿入。\n",//~vas4I~
				CMDFLAG_PREFIX);                                   //~0023I~
        HELPMSG
"    %cS[R]\"seps\":output field seperator. default is \" \"(1 space).\n",//~0022R~
"    %cS[R]\"seps\":出力用フィールド分離挿入文字列。省略値は\" \"(1桁スペース)。\n",//~vas4I~
				CMDFLAG_PREFIX);                                   //~0004M~
        HELPMSG                                                    //~0022I~
"                R:replace all delimiter of input file by this parameter.\n",//~0022I~
"                R:入力ファイルの分離文字は残さずにこの指定文字列で置換する。\n",//~vas4I~
				CMDFLAG_PREFIX);                                   //~0022I~
        HELPMSG                                                    //~0026I~
"    %cXoutfile2 :excluded line output filename. default is no output.\n",//~0026I~
"    %cXoutfile2 :選択されなかった行の出力先ファイル名。省略値は出力なし。\n",//~vas4I~
				CMDFLAG_PREFIX);                                   //~0026I~
        HELPMSG                                                    //~0004M~
"    %cYx,%cNx    :other flag option.\n",
"    %cYx,%cNx    :その他のフラグオプション。\n",                  //~vas4I~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);
        HELPMSG
"                Na:no field alignment as default. Without Ys,copy write.\n",//~0030R~
"                Na:フィールド整列をしない。Ys 指定がなければコピー出力。\n");//+vas4I~
        HELPMSG                                                    //~0030I~
"                   With Ys,output space compressed.\n",           //~0030I~
"                   Ys 指定があればスペース圧縮出力。\n");         //~vas4I~
        HELPMSG                                                    //~0027I~
"                Nc:no confirmation msg when output file override.\n",//~0027I~
"                Nc:出力ファイル上書きのとき確認Msgを出さない。\n");//~vas4I~
        HELPMSG
"                Ys:select only the fields of fieldspec.\n",       //~0003R~
"                Ys:fieldspec指定のフィールドだけを出力する。\n"); //~vas4I~
        HELPMSG
"  fieldspec: fieldno[-fieldno]][O][R|L|P][N|A][C][:col-spec]\n",  //~0034R~
"  fieldspec: fieldno[-fieldno]][O][R|L|P][N|A][C][:col-spec]\n"); //~0034R~
        HELPMSG                                                    //~0014I~
"            col-spec: [X]{start-substr|[-]cols}[:{end-substr|[-]cols|Llength}]\n",//~0017R~
"            col-spec: [X]{start-substr|[-]cols}[:{end-substr|[-]cols|Llength}]\n");//~0017R~
        HELPMSG                                                    //~0017I~
"            start/end-substr: [T|E][-]{A|B}fldstr\n",             //~0034R~
"            start/end-substr: [T|E][-]{A|B}fldstr\n");            //~0034R~
        HELPMSG
"        fieldno:field-No separated by delimiter(default:space and tab). max=%d.\n",
"        filedno:分離文字(省略値はスペースとタブ)によるフィールド番号。max=%d。\n",//~vas4I~
					MAXFIELD);
        HELPMSG
"        O      :OutOfRange,followings are one field as whole.\n", //~0034R~
"        O      :このフィールド番号以降は１フィールドとみなす。\n");//~vas4I~
        HELPMSG
"        R      :Right justify the field. Default unless %cNa is specified.\n",
"        R      :右詰整列。%cNa指定がないときの省略値\n",          //~vas4I~
				CMDFLAG_PREFIX);
        HELPMSG
"        L      :Left justify the field.\n",
"        L      :左詰整列。\n");                                   //~vas4I~
        HELPMSG
"        P      :align by decimal point.\n",
"        P      :小数点をあわせて右詰整列。\n");                   //~vas4I~
        HELPMSG
"        N      :search numeric field and right hsutify at the point.\n",//~0034R~
"        N      :数値フィールドを探してそこで右詰整列。\n");       //~vas4I~
        HELPMSG                                                    //~0034I~
"        A      :reset once effect of N & C for following fields.\n",//~0034R~
"        A      :N と C の効果を後続フィールドに対し一旦リセットする。\n");//~vas4I~
        HELPMSG
"        C      :compress interfield spaces of all following to a space.\n",//~0029R~
"        C      :以降の全フィールドのその間のスペースを１スペースに圧縮。\n");//~vas4I~
        HELPMSG                                                    //~0034I~
"                with N,compress until numeric field found.\n",    //~0034I~
"                Nと一緒に指定すると数値フィールドが見つかるまでを圧縮。\n");//~vas4I~
        HELPMSG                                                    //~va45R~
"                ex) l 5r  (Left justify except fieldNo 5)\n",     //~va45R~
"                例) l 5r  (第５項以外は左寄せ)\n");               //~vas4I~
        HELPMSG                                                    //~va45R~
"                    1-5p (apply \"P\" for field 1 to 5 if decimal point numeric)\n",//~va45R~
"                    1-5p (第1項から第５項まで小数点数値には\"P\"を適用)\n");//~vas4I~
        HELPMSG                                                    //~va45R~
"                    r l 4c (Right,Left,Left then compress all after fieldNo 4)\n",//~va45R~
"                    r l 4c (右,左,左 第4項以降はすべて圧縮して左詰)\n");//~vas4I~
        HELPMSG                                                    //~0017M~
"        X      :option to exclude sustring.\n",                   //~0017M~
"        X      :部分文字列を削除の意味。\n");                     //~vas4I~
        HELPMSG                                                    //~0014I~
"        T|E    :start/end position for the line with no fldstr. Top or End ?\n",//~0034R~
"        T|E    :fldstrを含まない行の部分文字列開始/終了位置、T:行頭,E:行末。\n");//~vas4I~
        HELPMSG                                                    //~0014I~
"                For start-str,defaut is \"e\" with X(exclude substr) option,\n",//~0017R~
"                開始文字列指定では省略値は X指定(文字列削除)の場合 \"e\"、\n");//~vas4I~
        HELPMSG                                                    //~0017I~
"                else \"t\". For end-str,defaut is \"e\" for both with and w/o X.\n",//~0017R~
"                以外は \"t\"。終了文字列指定では Xに関係なく\"e\"。\n");//~vas4I~
        HELPMSG                                                    //~0014I~
"        [-]A|B :substring start/end at A(After) or B(Before) the fldstr.\n",//~0034R~
"        [-]A|B :開始/終了位置はfldstr指定の文字列の後(A)か前(B)かを指定。\n");//~vas4I~
        HELPMSG                                                    //~0016I~
"                \"-\" means backword string search.\n",           //~0016I~
"                \"-\" はfldstr文字列を後ろから探す。\n");         //~vas4I~
        HELPMSG                                                    //~0014I~
"        fldstr :string to determin substring position.\n",        //~0014I~
"        fldstr :部分文字列取出し開始/終了位置を決めるための文字列。\n");//~vas4I~
        HELPMSG                                                    //~va45R~
"                Enclose by single quotation(') if it contains \":\".\n",//~va45R~
"                \":\"を含む時は１重引用符(')で囲む。\n");         //~vas4I~
        HELPMSG                                                    //~va45R~
"                ex) 3:xb\"time out\"\n",                          //~va45R~
"                例) 3:xb\"time out\"\n");                         //~vas4I~
        HELPMSG                                                    //~va45R~
"                    (drop substring before \"time out\" if fieldNo 3 has it)\n",//~va45R~
"                    (第3項が\"time out\"を含むならその前を削除)\n");//~vas4I~
        HELPMSG                                                    //~va45R~
"                    4:a'Time:':bElapsed\n",                       //~va45R~
"                    4:a'Time:':bElapsed\n");                      //~va45R~
        HELPMSG                                                    //~va45R~
"                    (pickup substring after \"Time:\" to before \"Elapsed\")\n",//~va45R~
"                    (\"Time\"の後から\"Elapsed\"の前まで取り出す)\n");//~vas4I~
        HELPMSG
"        [-]cols:substring start/end column. \"-\" means cols from end.\n",//~0017R~
"        [-]cols:入力フィールド部分文字列開始/終了位置.\"-\"は後からの位置。\n");//~vas4I~
        HELPMSG                                                    //~va45R~
"                ex) 3:3:5    (pickup col3-5 of field-No 3)\n",    //~va45R~
"                例) 3:3:5    (第3項からは 3-5 桁を取り出す)\n");  //~vas4I~
        HELPMSG                                                    //~va45R~
"                    6:x-5:-2 (cut first 4 byte and last 1 byte of field-No6)\n",//~va45R~
"                    6:x-5:-2 (第6項からは 後ろから 5桁目から2桁目を取り除く)\n");//~vas4I~
        HELPMSG                                                    //~0010I~
"        Llength:substring len. means up to end-of-field if missing.\n",//~va45R~
"        Llength:部分文字列の長さ。指定なしは項末まで。\n");       //~vas4I~
        HELPMSG                                                    //~va45R~
"                ex) 3:3:L5   (pickup 5 byte from col3 of field-No 3)\n",//~va45R~
"                例) 3:3:L5   (第3項からは 3桁目から5 桁を取り出す)\n");//~vas4I~
        HELPMSG                                                    //~0017I~
"        (Note)  substring position is for the string after aligned for P type.\n",//~va45R~
"        (注)    Pタイプの場合の桁位置は整列後のイメージを想定すること。\n");//~vas4I~
        HELPMSG
"      w/o fieldspec param,all fields are put right aligned if no %cYs,%cNa parm.\n",//~0003R~
"      fieldspec指定がないと%cYs,%cNa指定がなければ全フィールドを右詰で出力。\n",//~vas4I~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);
        HELPMSG
"      alignment specification only(without field-no) is effective on the field\n",
"      フィールド番号なしの整列指定オプションはその指定位置に対応する\n");//~vas4I~
        HELPMSG
"      correspond to the specification and followings upto end of line.\n",
"      フィールド以降の全フィールドに適用される。\n");             //~vas4I~
        HELPMSG
"sample) %s %cL5S\"10:00:00\" %cL5E\"11:59:59\" %cLIexcept %cLXNullPo file1 r 5l\n",
"    例) %s %cL5S\"10:00:00\" %cL5E\"11:59:59\" %cLIexcept %cLXNullPo file1 r 5l\n",//~vas4I~
                Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);
        HELPMSG
"        %s %cQ %cS\",\" %cNa %cYs file2 5:x4 6:-3:L2 1 3:t-a?:4 7:b\"x y\":a\"x z\"\n",//~0017R~
"        %s %cQ %cS\",\" %cNa %cYs file2 5:x4 6:-3:L2 1 3:t-a?:4 7:b\"x y\":a\"x z\"\n",//~0017R~
                Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);
        HELPMSG                                                    //~0035I~
"        %s file3 nc:999:l1\n",                                    //~0035R~
"        %s file3 nc:999:l1\n",                                    //~0035R~
                Spgm);                                             //~0035I~
    exit(1);
//#ifndef ULIB64X	//C4702 unreachable warning                        //~va66I~//~va67R~
#ifndef VC10EXP	//C4702 unreachable warning                        //~va67I~
    return 0;
#endif                                                             //~va66I~
}//help
