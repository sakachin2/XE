//*CID://+dateR~:                             update#=   53;
//*************************************************************
//*xms
//* C source selection by #ifdef for xfc(source compare)
//*************************************************************
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef UNX
	#include <unistd.h>
#else
#include <conio.h>
#endif

#if defined(DOS) || defined(W32)
	#include <dos.h>
    #ifdef DPMI
    	#include <errno.h>
    #endif
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ualloc.h>
#include <uedit.h>
#include <ufile5.h>
#include <ustring.h>
#include <utrace.h>

//*******************************************************
#define VER "V1.0"   //version
#define PGM "xms"

#define HELPMSG         uerrhelpmsg(stdout,stderr,

#define MAX_NEST           30
#define MAX_LINESZ  	4096
#define MAX_LINESZ_MIN   64
#define MAX_LINESZ_MAX  32768
#define MAX_MACROPARM      50
#define CH_MACRO          '#'
#define CH_LF             '\n'
#define TABSPACE " \t"
#define DEFAULT_LINENOSZ  5                                        //~4126I~

//*******************************************************
static  	char *Slinedata;
static  	int   Sdatalen;
static  	int   Slinebuffsz;
static  	int   Slineno;
static  	int   Serrlineno;
static  	int   Soutlineno;
static  	int   SoutlinenoDropped;
static  	int   SoutlinenoChecklist;

static int Sswselect;
#define LINE_SELECT     		0
#define LINE_NOTSELECT   		1

static int Snestsw[MAX_NEST];
static int Snestlevel;
#define LINE_IF_SELECT  		1	//target #if and selected if part
#define LINE_IF_SELECT_ELSE   	2   //target #if and selected else part
#define LINE_IF_NONE          	3   //not target #if
#define LINE_ELSE_SELECT    	4   //target #else #if selected else part
#define LINE_ELSE_SELECT_IF 	5   //target #else #if selected if   part
#define LINE_ENDIF_SELECT   	6   //#endif of tartget #if
#define LINE_ENDIF_NONE         7   //#endif of not target #if

static char *Spgm=PGM,*Sver=VER;
static FILE *Sfh=0,*Sfho=0,*SfhoDropped,*SfhoChecklist;
static char *Spfnm=0,*Spfnmo=0,*SpfnmoDropped,*SpfnmParm,*SpfnmoChecklist;
static char  Sfnmo[_MAX_PATH];                                     //~4125I~
static char  SfnmoDropped[_MAX_PATH];                              //~4125I~
static char  SfnmoChecklist[_MAX_PATH];                            //~4125I~
static long Sfilesz;
static int Sdebugmode;
static int Smaxlinesz=MAX_LINESZ;
static char *Smacroparm[MAX_MACROPARM];
static int  SmacroparmLen[MAX_MACROPARM];
static int  SmacroparmUndef[MAX_MACROPARM];
static int  Smacroparmctr;
static char Slinenoprefixstr[12];                                  //~4125I~
//**************
static char *SmacroStmt[]={0,"if","else","elif","ifdef","ifndef","endif",0};
static int SmacroStmtLen[]={0,2,4,4,5,6,5};
#define MST_NONE   0      //
#define MST_IF     1      //index of if
#define MST_ELSE   2      //
#define MST_ELIF   3      //
#define MST_IFDEF  4      //
#define MST_IFNDEF 5      //
#define MST_ENDIF  6      //
//********************************************************
void parmprechk(int parmc,char *parmp[]);
int opdchk(int Popdno,char **Ppopd);
FILE *openoutfile(char **Pppfnmo,char *Prename);                   //~4125I~
int fmtmain();
int help(int Popt);
int fmtopdchk4(char *Popd);
int opderr(char *Pparm);
int formatDataSub();
int scanData();
int chkMacroStmt(char *Pdata,int Plen,int *Ppstmttypeindex,int *Ppparmsw);
int macroProcess(char *Pdata,int Plen);
int chkMacroText(int Pstmttype,char *Pdata,int Plen);
int srchMacroParm(char *Pdata,int Plen,int *Ppundef);
int funcRead();
int funcWrite();
int funcWriteDropped();
int funcWriteChecklist(int Pstmt);                                 //~4125R~
void errnotsupported();
void printmacrodefinition();
void macroparmfile(char *Pfnm);
                                                                   //~4125I~
//****************************************************************
//*rc   :0
//****************************************************************
int main(int parmc,char * parmp[])
{
    int rc,buffsz1;
	char pgmver[16];
    char *buff1;
//*********************************
	Sfho=stdout;
	SfhoDropped=stderr;
	sprintf(pgmver,"%s:%s(%c): ",PGM,VER,OSTYPE);
	uerrmsg_init(pgmver,stderr,0);//msg to stderr
	uerrexit_init(pgmver,stderr,0,0,0);//stderr only,no pathmsg
	uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit
	parmprechk(parmc,parmp);
    if (rc=opdchk(parmc,parmp),rc)
    	return rc;                      //err
    if (Spfnmo)
        Sfho=openoutfile(&Spfnmo,Sfnmo);                           //~4125I~
    else
    	Spfnmo="stdout";
    if (SpfnmoDropped)
        SfhoDropped=openoutfile(&SpfnmoDropped,SfnmoDropped);      //~4125I~
    if (SpfnmoChecklist)
        SfhoChecklist=openoutfile(&SpfnmoChecklist,SfnmoChecklist);//~4125I~
    buffsz1=Smaxlinesz+2;	//redundancy for ufreads(1 for crlf split,1 for optionally last null)
    buff1=umalloc(buffsz1);
    UALLOCCHK(buff1,UALLOC_FAILED);
    Slinedata=buff1;
    Slinebuffsz=buffsz1;
    rc=fmtmain();
    if (!rc)
    {
		uerrmsg("*** Done ***\n I:%s\n M:%s \n O:%s\n C:%s\n Q:%s\n read:% 4d, selected=% 4d, dropped=% 4d, checklist=%d, warning=% 4d.",0,
       			Spfnm,SpfnmParm,Spfnmo,SpfnmoChecklist,SpfnmoDropped,Slineno,Soutlineno,SoutlinenoDropped,SoutlinenoChecklist,Serrlineno);
        printmacrodefinition();
		if (Serrlineno)
			rc=4;
    }
	if (rc)
		ubell();
    fclose(Sfh);
    fclose(Sfho);
    return rc;
}//main
//****************************************************************
// format
//*rc   :0   or 1:data err or 4:env err or UALLOC_FAILED
//****************************************************************
int fmtmain()
{
	int    rc=0;
//*********************************
//chk field width
    for (;;)
    {
      	if (funcRead()<0)
        	break;
        if (rc=formatDataSub(),rc)
        {
            if (rc>4)
                break;
        }
	}//all line
    return rc;
}//fmtmain
//****************************************************************
//****************************************************************
int formatDataSub()
{
    int rc;
//****************************************
    rc=scanData();	//flag comment and quotation data
    if (!rc)
    	funcWrite();
    else
       	funcWriteDropped();
	return 0;
}//formatDataSub
//****************************************************************
void endifnestup()
{
    int swselect;
//*************************
    swselect=Snestsw[Snestlevel];
    UTRACEP("selectnestup level=%d,select=%d",Snestlevel,Snestsw[Snestlevel]);
    switch(swselect)
    {
    case LINE_IF_SELECT:    //this is #if and select if part
        Sswselect=LINE_SELECT;
        break;
    case LINE_IF_SELECT_ELSE:  //this is #if and select else part
        Sswselect=LINE_NOTSELECT;
        break;
    case LINE_ELSE_SELECT:  //this is #else and select else part
        Sswselect=LINE_SELECT;
        break;
    case LINE_ELSE_SELECT_IF:  //this is #else and selected if part
        Sswselect=LINE_NOTSELECT;
        break;
    default:
        Sswselect=LINE_SELECT;
    }
    UTRACEP("endifnestup selectsw=%d\n",Sswselect);
}//scanData
//****************************************************************
int scanData()
{
	char *pc;
    int rc=0,swselect,rlen;
//*************************
    UTRACED("scandata inp",Slinedata,Sdatalen);
    pc=Slinedata;
    rlen=Sdatalen;
    UTRACEP("scandata inp lineno=%d,Sswselect=%d\n",Slineno,Sswselect);
	USKIP_SPACETAB(pc,rlen);
    if (*pc!=CH_MACRO                                              //~4125R~
    ||macroProcess(pc+1,rlen-1))	//#include etc                 //~4125I~
    {
    	rc=(Sswselect==LINE_NOTSELECT);
    }
    else
    {
        swselect=Snestsw[Snestlevel];
        UTRACEP("scanData level=%d,select=%d,current sw=%d\n",Snestlevel,swselect,Sswselect);
        switch(swselect)
        {
        case LINE_IF_SELECT:    //this is #if and select if part
            rc=1;
            Sswselect=LINE_SELECT;
            break;
        case LINE_IF_SELECT_ELSE:  //this is #if and select else part
            rc=1;
            Sswselect=LINE_NOTSELECT;
            break;
        case LINE_ELSE_SELECT:  //this is #else and select else part
            rc=1;
            Sswselect=LINE_SELECT;
            break;
        case LINE_ELSE_SELECT_IF:  //this is #else and selected if part
            rc=1;
            Sswselect=LINE_NOTSELECT;
            break;
        case LINE_ENDIF_SELECT:  //this is #endif of target if
            rc=1;
            Snestlevel--;
            endifnestup();
            break;
        case LINE_ENDIF_NONE:  //this is #endif of not target
            Snestlevel--;
        case LINE_IF_NONE:       //this is #if and not parm selection
        default:
            if (Sswselect==LINE_NOTSELECT)
                rc=1;
        }
    }
    UTRACEP("scanData rc=%d\n",rc);
    return rc;
}//scanData
//*****************************************************************
//*****************************************************************
int macroProcess(char *Pdata,int Plen)
{
    int stmttype,rc=0,parmdefined,swselect;
//********************************
	if (!chkMacroStmt(Pdata,Plen,&stmttype,&parmdefined))
    	return 4;       //#define etc                              //~4125R~
    switch(stmttype)
    {
	case MST_IFDEF:
	case MST_IFNDEF:
    	if (parmdefined>0)     //select if part
        	swselect=LINE_IF_SELECT;
        else
    	if (parmdefined<0)     //select else part
        	swselect=LINE_IF_SELECT_ELSE;
        else
        	swselect=LINE_IF_NONE;
    	Snestlevel++;
    	Snestsw[Snestlevel]=swselect;
        break;
	case MST_ELSE:
    	swselect=Snestsw[Snestlevel];
    	if (swselect==LINE_IF_SELECT_ELSE)
        	swselect=LINE_ELSE_SELECT; //start elese part selection
        else
    	if (swselect==LINE_IF_SELECT)
        	swselect=LINE_ELSE_SELECT_IF; //start elese part selection
    	Snestsw[Snestlevel]=swselect;
        break;
	case MST_ENDIF:
    	swselect=Snestsw[Snestlevel];
    	if (swselect!=LINE_IF_NONE)	//selection target
	    	Snestsw[Snestlevel]=LINE_ENDIF_SELECT;
        else
	    	Snestsw[Snestlevel]=LINE_ENDIF_NONE;
        break;	//continue
	case MST_IF:
    	Snestlevel++;
    	Snestsw[Snestlevel]=LINE_IF_NONE;
        break;	//continue
	case MST_ELIF:
    	Snestsw[Snestlevel]=LINE_IF_NONE;
        break;	//continue
    default:    //#include etc                                     //~4125I~
        rc=4;                                                      //~4125I~
    }
    UTRACEP("macroProcess level=%d,select=%d\n",Snestlevel,Snestsw[Snestlevel]);
    return rc;
}//macroProcess
//*****************************************************************
//*chk Macro statement if/else/...
//*return stmt len
//*****************************************************************
int chkMacroStmt(char *Pdata,int Plen,int *Ppstmttypeindex,int *Ppparmdefined)
{
    int ii,len=0,ch,len0,rc;
    char *pc,*pdata;
//********************************
    pdata=Pdata;
    len0=Plen;
	USKIP_SPACETAB(pdata,len0);
    for (ii=1;(pc=SmacroStmt[ii])!=0;ii++)
    {
    	len=SmacroStmtLen[ii];
        if (len<=len0 && !memcmp(pdata,pc,len))
        {
        	if (len==len0)
            	break;
            else
            {
		        ch=*(pdata+len);
                if (!isalnum(ch))
	            	break;
            }
        }
    }
    if (pc)
    {
		funcWriteChecklist(ii);
    	*Ppstmttypeindex=ii;
    	rc=len;
	    if (Smacroparmctr)
			*Ppparmdefined=chkMacroText(ii,Pdata+len,Plen-len);
    }
    else
    {
    	*Ppstmttypeindex=MST_NONE;
    	rc=0;
    }
UTRACEP("chkMacroStmt curtype=%d,len=%d,def=%d,data=%s\n",*Ppstmttypeindex,rc,*Ppparmdefined,pdata);
	return rc;
}//chkMacroStmt
//*****************************************************************
//rc:1:if part,-1:else part,0:not specified
//*****************************************************************
int chkMacroText(int Pstmttype,char *Pdata,int Plen)
{
    int len,idx,rc=0,textlen,swundef;
    char *pc,*pdata;
//********************************
UTRACEP("chkMacroText stmt=%d,text=%s\n",Pstmttype,Pdata);
	pdata=Pdata;
    len=Plen;
	USKIP_SPACETAB(pdata,len);
    switch(Pstmttype)
    {
	case MST_IF:
	case MST_ELIF:
		errnotsupported();
    	break;
	case MST_IFDEF:
	case MST_IFNDEF:
        pc=umempbrk(pdata,TABSPACE,len);
        if (pc)
        	textlen=PTRDIFF(pc,pdata);
        else
        	textlen=len;
        idx=srchMacroParm(pdata,textlen,&swundef);
        if (idx<0)
        	break;
        if (Pstmttype==MST_IFDEF)
        	rc=1;	//if part
        else
        	rc=-1;  //else part
        if (swundef)
			rc=-rc;
    	break;
    }
UTRACEP("chkMacroText rc=%d\n",rc);
	return rc;
}//chkMacroText
//*****************************************************************
//*search in cmd line parameter
//*****************************************************************
int srchMacroParm(char *Pdata,int Plen,int *Ppswundef)
{
    int ii,len,rc;
//********************************
    *Ppswundef=0;
    for (ii=0;ii<Smacroparmctr;ii++)
    {
    	len=SmacroparmLen[ii];
    	if (Plen>=len && !memcmp(Smacroparm[ii],Pdata,len))
        	break;
    }
    if (ii<Smacroparmctr)
    {
        *Ppswundef=SmacroparmUndef[ii];
    	rc=ii;
    }
    else
    	rc=-1;
UTRACEP("srchMacroParm len=%d,rc=%d,data=%s\n",Plen,rc,Pdata);
	return rc;
}//srchMacroParm
//****************************************************************
// get valid plh
//*rc   :-1:eof or readlen except
//****************************************************************
int funcRead()
{
    int readlen,buffsz;
	char *buff;
//*********************************
    buff=Slinedata;
    buffsz=Slinebuffsz;
    if (!fgets(buff,buffsz,Sfh))
    	return -1;
    Slineno++;
    UTRACEP("funcRead line=%d\n",Slineno);
    readlen=strlen(buff);
    if (*(buff+readlen-1)==CH_LF)
    	readlen--;
    Sdatalen=readlen;
UTRACED("funcRead",buff,readlen);
    return readlen;
}//funcRead
//**********************************************************************
//* write exception file
//**********************************************************************
int funcWrite()
{
	int rc=0;                                                      //~4125R~
//****************
	Soutlineno++;
    if (*Slinenoprefixstr)                                         //~4125I~
    	fprintf(Sfho,Slinenoprefixstr,Slineno,Slinedata);          //~4125I~
    else                                                           //~4125I~
    	fprintf(Sfho,"%s",Slinedata);                              //~4125I~
	return rc;
}//funcWrite
//**********************************************************************
//* write exception file
//**********************************************************************
int funcWriteDropped()
{
	int rc=0;
//****************
    if (!SfhoDropped)
    	return 4;
	SoutlinenoDropped++;
	fprintf(SfhoDropped,"% 4d %s",Slineno,Slinedata);
	return rc;
}//funcWriteDropped
//**********************************************************************
//* write exception file
//**********************************************************************
int funcWriteChecklist(int Pmactype)
{
	int rc=0;
//****************
    if (!SfhoChecklist)
    	return 4;
    switch(Pmactype)
    {
	case MST_IFDEF:
	case MST_IFNDEF:
	case MST_IF:
	case MST_ELIF:
    	break;
    default:
    	return 4;
    }
	SoutlinenoChecklist++;
	fprintf(SfhoChecklist,"% 4d %s",Slineno,Slinedata);
	return rc;
}//funcWrite
//**********************************************************************
//*open outputfile
//**********************************************************************
FILE *openoutfile(char **Pppfnmo,char *Prename)                    //~4125I~
{
    FILEFINDBUF3 fstat3;
	char *pfnmo;                                                   //~4125I~
    FILE *fho;
//******************
	pfnmo=*Pppfnmo;                                                //~4125I~
    if (WILDCARD(pfnmo))                                           //~4125I~
    {                                                              //~4125I~
        ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,(UCHAR*)Spfnm,(UCHAR*)pfnmo,(UCHAR*)Prename);    //src,patern,output//~4125I~
        pfnmo=Prename;                                             //~4125I~
        *Pppfnmo=pfnmo;                                            //~4125I~
    }                                                              //~4125I~
    if (!ufstat(pfnmo,&fstat3))                                    //~4125R~
    {
        if (fstat3.attrFile & FILE_DIRECTORY)
            uerrexit("%s is directory",0,
                        pfnmo);                                    //~4125R~
    }
    fho=fopen(pfnmo,"w");                                          //~4125R~
    if (!fho)
        uerrexit("%s open failed,rc=%d",0,
                    pfnmo,errno);                                  //~4125R~
    return fho;
}//openoutfile
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
    		case 'H':                                              //+4126I~
        		if (toupper(*(cptr+1))=='H'
        		||  toupper(*(cptr+1))=='?')
					help(1);
        		else
        			help(0);
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
int opdchk(int Popdno,char **Ppopd)
{
    char *pc;
    int  ii,posparmno=0,rc2;
	FILEFINDBUF3 ffb3;
//*********************************
    if (Popdno<=1)
        help(0);
    for (ii=1;ii<Popdno;ii++)
    {
    	pc=Ppopd[ii];
    	if (*pc==CMDFLAG_PREFIX || *pc==CMDFLAG_PREFIX2)	//flag parm
        {
			rc2=fmtopdchk4(pc+1);
            if (rc2)
            {
            	if (rc2==16)
                	return rc2;
                else
                	return opderr(pc);
            }
        }
        else
        {
        	if (!posparmno)	//1st postional parm
            	Spfnm=pc;		//filename
            else
            {
            	return opderr(pc);
            }
            posparmno++;
        }
    }
    if (!posparmno)
    	uerrexit("specify input filename",0);
    rc2=ufstat(Spfnm,&ffb3);
    if (rc2)
    	uerrexit("%s not found",0,Spfnm);
    Sfilesz=(long)ffb3.cbFile;
    Sfh=fopen(Spfnm,"r");
    if (!Sfh)
    	uerrexit("%s open failed",0,Spfnm);
    UTRACEP("%s size is %ld\n",Spfnm,Sfilesz);
    return 0;
}//opdchk
//****************************************************************
//****************************************************************
void addmacrovariable(char *Pvar,int Plen,int Pdefine)
{
	if (Smacroparmctr<MAX_MACROPARM)
    {
    	if (!Pdefine)
	    	SmacroparmUndef[Smacroparmctr]=1;
        SmacroparmLen[Smacroparmctr]=Plen;
        Smacroparm[Smacroparmctr++]=Pvar;
    }
    else
    	uerrexit("macro parameter count overflow max is %d(%s)",0,
            		MAX_MACROPARM,Pvar);
}//addmacrovariable
//****************************************************************
// xfmt specific parm
//*rc   :0  ,4
//****************************************************************
void macroparmfile(char *Pfnm)
{
	char *pc,*pc2;
    int len,len2,swdefined=0;
    char buff[128];
    FILE *fh;
//***************************
    fh=fopen(Pfnm,"r");
    if (!fh)
    	uerrexit("%s open failed",0,Pfnm);
    for (;;)
    {
    	if (!fgets(buff,sizeof(buff),fh))
        	break;
        pc=buff;
        len=strlen(pc);
		USKIP_SPACETAB(pc,len);
        if (*pc=='*'||*pc=='#')
        	continue;
        swdefined=1;
        if (*pc=='!'||*pc=='-')                                    //~4125R~
        {
        	pc++;
            len--;
            swdefined=0;
        }
		USKIP_SPACETAB(pc,len);
        pc2=umempbrk(pc,TABSPACE,len);
        if (pc2)
        	len2=PTRDIFF(pc2,pc);
        else
        	len2=len;
        if (len)
			addmacrovariable(strdup(pc),len2,swdefined);           //~4125R~
    }
}//addmacrovariable
//****************************************************************
// xfmt specific parm
//*rc   :0  ,4
//****************************************************************
void printmacrodefinition()
{
    int ii;
//***************************
	fprintf(stderr,"\nMacro parametr ctr=%d\n",Smacroparmctr);
    for (ii=0;ii<Smacroparmctr;ii++)
    {
    	fprintf(stderr,"%c%s\n",(SmacroparmUndef[ii]?'!':' '),Smacroparm[ii]);
    }
}//addmacrovariable
//****************************************************************
// xfmt specific parm
//*rc   :0  ,4
//****************************************************************
int fmtopdchk4(char *Popd)
{
	char *pc,*pc2;
    int ch,len,swdefined=0;
//***************************
    pc=Popd;
    switch(toupper(*pc))
    {
    case 'H':
    case '?':
        break;
    case 'B':
        pc2=pc+1;
        Smaxlinesz=atoi(pc2);
        if (Smaxlinesz<MAX_LINESZ_MIN||Smaxlinesz>MAX_LINESZ_MAX)
        {
        	uerrmsg("Input Buffser size err(%s), It shoud be >=%d && <=%d",0,
            		pc,MAX_LINESZ_MIN,MAX_LINESZ_MAX);
	        return 16;  //no parm err
        }
        break;
    case 'C':		//macro line checklist
        SpfnmoChecklist=pc+1;
        break;
    case 'D':
        pc2=pc+1;
        if (*pc2=='!'||*pc2=='-')                                  //~4125R~
        	pc2++;
        else
        	swdefined=1;
        if (len=strlen(pc2),len)
			addmacrovariable(pc2,len,swdefined);
        break;
    case 'L':		//parm file                                    //~4125I~
        {                                                          //~4125I~
        	int lndigit;                                           //~4125I~
    		lndigit=atoi(pc+1);                                    //~4125R~
            if (!lndigit)                                          //~4125R~
                lndigit=DEFAULT_LINENOSZ;                          //~4126R~
            sprintf(Slinenoprefixstr,"%% %dd:%%s",lndigit);        //~4125R~
        }                                                          //~4125I~
        break;                                                     //~4125I~
    case 'M':		//parm file
    	SpfnmParm=pc+1;
        macroparmfile(SpfnmParm);
        break;
    case 'O':		//outputfnm
        Spfnmo=pc+1;
        break;
    case 'Q':		//parm file
    	SpfnmoDropped=pc+1;
        break;
    case 'Y':
        while(ch=*(++pc),ch)
        {
            switch(toupper(ch))             //option
            {
            case '9':
                break;
            case 'D':
                Sdebugmode=1;
                break;
            default:
	            return opderr(Popd);
            }
        }
        break;
    case 'N':
        while(ch=*(++pc),ch)
        {
            switch(toupper(ch))             //option
            {
            case '9':
                break;
            case 'D':
                Sdebugmode=0;
                break;
            default:
	            return opderr(Popd);
            }
        }
        break;
    default:
        return 4;
    }
    return 0;
}//fmtopdchk4
//****************************************************************
int opderr(char *Pparm)
{
    uerrexit("parm(%s) err",0,Pparm);
    return 4;
}//opderr
//****************************************************************
void errnotsupported()
{
	if (SfhoChecklist)
    	fprintf(SfhoChecklist,"(===Not Supported Macro line===)\n");
    else
		uerrmsg("not supported macro at line %d(%s)\n",0,
    				Slineno,Slinedata);
	Serrlineno++;
}
//****************************************************************
// hel for fmt
//*ret :0
//****************************************************************
int help(int Popt)
{
        HELPMSG
"%s : %s=(%c)= Line selection of C source file by #ifdef/#ifndef.\n",
"%s : %s=(%c)= C \x83\\ーステキストの #ifdef/#ifndef による行選択\n",
                Spgm,Sver,OSTYPE);
        HELPMSG
"format:%s [%coptions] inputfile [outputfile]\n",
"形式  :%s [%coptions] inputfile [outputfile]\n",
                Spgm,CMDFLAG_PREFIX);
        HELPMSG
"*******************************************************************************\n", //80 column limit indicator
"*******************************************************************************\n");
        HELPMSG
"  options\n",
"  options\n");
        HELPMSG
"    %cBn         :Input Buffer size. Default is n=%d\n",
"    %cBn         :入力バッファーサイズ。省略値は n=%d\n",
				CMDFLAG_PREFIX,MAX_LINESZ);
        HELPMSG
"    %cCxxx       :Checklist of Macro Statement.\n",
"    %cCxxx       :マクロ行のチェックリスト出力ファイル\n",
				CMDFLAG_PREFIX);
        HELPMSG
"    %cDxxx       :Macro parameter for #ifdef/#else path selection.\n",
"    %cDxxx       :#ifdef/#elseの経路を選択するためのマクロパラメータ\n",
				CMDFLAG_PREFIX);
        HELPMSG
"                 up to number of %d. ex) %cDWIN32 '%cD!_UNICODE' %cD-_UNICODE.\n",//~4125R~
"                 最大 %d 個まで指定. 例) %cDWIN32 '%cD!_UNICODE' %CD-_UNICODE.\n",//~4125R~
				MAX_MACROPARM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~4125R~
        HELPMSG                                                    //~4125I~
"                 D-XXX is alternative of D!XXX.\n",               //~4125I~
"                 D-XXX は D!XXX のかわりに使えます\n");           //~4125I~
        HELPMSG                                                    //~4125I~
"    %cL[n]       :Set n-digit original lineNo prefix to outputfile. default n=%d.\n",//~4126R~
"    %cL[n]       :出力ファイルの各行に元の n 桁 行番号をセット. 省略値 n=%d\n",//~4126R~
				CMDFLAG_PREFIX,DEFAULT_LINENOSZ);                  //~4126R~
        HELPMSG
"    %cMxxx       :Macro parameter file name as alternative of %cD.\n",
"    %cMxxx       :%cD パラメータをファイルで指定する場合のファイル名\n",
				CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);
        HELPMSG
"                 Sample line format of the file.\n",
"                 このファイルは以下のように指定する\n");
        HELPMSG
"                   *comment\n",
"                   *comment\n");
        HELPMSG
"                   #comment\n",
"                   #comment\n");
        HELPMSG
"                   UNICODE    	 //for #ifdef\n",
"                   UNICODE    	 //for #ifdef\n");
        HELPMSG
"                   !WIDECHAR  	//for #ifndef\n",
"                   !WIDECHAR  	//for #ifndef\n");
        HELPMSG
"    %cOxxx       :Output filename. default is stdout.\n",
"    %cOxxx       :出力ファイル。省略値はstdout\n",
				CMDFLAG_PREFIX);
        HELPMSG                                                    //~4125I~
"                 Use wildcard(*) to edit from input filename\n",  //~4125I~
"                 ワイルドカードで入力ファイルから編集することも可\n");//~4125I~
        HELPMSG
"    %cQxxx       :Output filename for deleted lines. default:stderr\n",//~4125R~
"    %cQxxx       :削除行の出力ファイル。省略値:stderr\n",         //~4125I~
				CMDFLAG_PREFIX);
        HELPMSG
"\n",
"\n");
    if (Popt & 1)
    {
        HELPMSG
"    %cYd         :Debug Mode.\n",
"    %cYd         :デバッグモード\n",
				CMDFLAG_PREFIX);
    }
        HELPMSG
"  ex) %s file3 %cDUNICODE %cUWIDECHAR,   %s file2.c %cOfile2.ind %cMmacrofile\n",
"  例) %s file3 %cDUNICODE %cUWIDECHAR,   %s file2.c %cOfile2.ind %cMmacrofile\n",
               Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX);
        HELPMSG
"      %s file3 %cD-XXX %co*.out %cq*.deleted %cc*.chklst\n",      //~4125R~
"      %s file3 %cD-XXX %co*.out %cq*.deleted %cc*.chklst\n",      //~4125R~
               Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX); //~4125I~
    exit(1);
}//help
