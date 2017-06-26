//*CID://+v9a1R~:                             update#=  119;       //+v9a1R~
//**********************************************************************
//* xp2p.c                                                         //~v915R~
//**********************************************************************
//v9a1:160418 v9.33 LNX64 Compiler warning                         //+v9a1I~
//v9a0:160418 v9.33 LNX compiler warning                           //~v9a0I~
//v96z:130809 (BUG:LNX not gxp)EBCFILE ucs2local1 output utf8 when LANG=UTF8,ucvext_b2mDbcsstr cut by 2 byte each//~v96zI~
//            set EBCBYUCS(set dd to buff) and convert to utf8 at write//~v96zI~
//120611 v965 avoid C4701 warning(variable may not be uninitialized)//~v965I~
//071024 v92n (LNX)support utf8 file(conv to locale)               //~v92nI~
//071006 v92d (Lnx)UTF8 support                                    //~v92dI~
//050606 v91x add /Nu option to bypass set 0x0c(form feed) for linux convenience//~v91xI~
//020802 v91c (BUG)for dbcs split;1 byte long required for 2p save area//~v91cI~
//020727 v91b (BUG)1st page drop when /y2 mode start page is even number//~v91bI~
//020727 v919 chng inter-space 2-->0(/yn),left margin 2-->4(/nn)   //~v919R~
//020727 v918 (BUG)line overflow whe form2p and /nn(no number fld) //~v918I~
//020719 v915 support FORM2P/WIN2P for prntyp OS2                  //~v915I~
//020719 v914 support FORM2P for prntyp WIN                        //~v914I~
//020718 v911 form2p support(ex a42,b4l2). /y2 max col is of a4,b4l2 max col is of b5//~v911I~
//010527 v90m :2 page support(line may 1 byte long for dbcs split) //~v90mI~
//010527 v90k :2 page support for also not unx version             //~v90kI~
//010521 v90g :LINUX support:double pageing                        //~v90gI~
//**********************************************************************
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add

//**********************************************************************

#include <ulib.h>                                                  //~v844R~
#include <ufile.h>                                                 //~v844R~
#include <ustring.h>                                               //~v844I~
                                                                   //~v90gI~
#include "xp.h"
#include "xp2p.h"                                                  //~v90kR~
#ifdef W32                                                         //~v915I~
	#include "xpwinp.h"                                            //~v915R~
#endif                                                             //~v915I~
#ifdef OS2                                                         //~v915R~
	#include "xpjob.h"                                             //~v915I~
#endif                                                             //~v915I~
#ifdef GXP                                                         //~v92dI~
	#include "xplnxp.h"                                            //~v92dI~
#else                                                              //~v92nI~
    #ifdef UTF8SUPP                                                //~v92nI~
		#include "xputf.h"                                         //~v92nI~
    #endif                                                         //~v92nI~
#endif                                                             //~v92dI~
//*********************************************************************//~v90gI~
//*********************************************************************
extern char pgmid[];
extern char ver[];
extern int  dbcsenv;           //dbcs environment sw v4.9a v7.23r
extern int hdr0linesw;       //in xppf,header0 print req           //~v844I~
extern int lineprefixsw;     //print lineno fld                    //~v911I~
//extern int breakpage;           //current page count from last for despage print//~v911R~
extern int Gpage2p;           //current page count from last for despage print//~v911I~
extern int Gtrailersw;   //parm to putline2p from xppf             //~v911I~
extern int despageno;           //total page of despage print      //~v904R~
extern int maxcol;      //colomn no per line v1.4rep v1.7rep v7.23r//~v90gI~
extern int maxline;    //line   no per page v7.23r                 //~v90gI~
extern int skip1stff2;       //1st formfeed skip option            //~v90gI~
extern int esccmdlen;          //esccmd lenngth     ..v2.9add v3.6rep//~v90gI~
extern int header1outsw;		//header1 output v7.12a            //~v911I~
extern int header0outsw;		//header0 output v7.12a            //~v911I~
extern int prntyp;	//printer type(default ibm5577/ibm5575 etc) av4.5 v6.7r//~v914I~
extern int docnamesw;				//document name set functio v7.11a//~v915I~
//**********************************************************************
static char Shdrcmd[MAXESCCMD];          //v2.9add esc command string v2.9add v5.5r//~v90gR~
static int Shdrcmdlen=0;                                           //~v91bR~
static FILE *Sfh=0;                                                //~v91bR~
static  int Sposx,Sposy,Sposylast,Sopenpagesw,S2width=0,S2pagewksz;//~v91bR~
//static  int Sprintwidth=0,Sleftmarginnn=0,Slrspaceyn=0,Shalfprintwidth=0;      //margin between left and right page//~v91cR~
static  int Sprintwidth=0,Sleftmarginnn=0,Slrspaceyn=1,Shalfprintwidth=0;      //margin between left and right page//~v91cI~
//static	int Slrspace=4;      //margin between left and right page//~v91cR~
static	int Slrspace=3;      //margin between left and right page  //~v91cI~
static  int Sleftpagesw=1;                                         //~v911R~
static  int Spageheight=0;                                         //~v911I~
static  char *S2pagewk=0;                                          //~v91bR~
static  char *S2pagewk2=0;     //for win,restruct hdr line         //~v91bR~
static  int  *S2pagewk3=0;     //line length tbl                   //~v91cR~
//**********************************************************************
void closepage2p(void);                                            //~v90kR~
//****************************************************************************//~v844I~
//*get2pwidth                                                      //~v914I~
//*ret:header0 line width                                          //~v914I~
//****************************************************************************//~v911I~
int get2pwidth(int Pprintwidth)                                    //~v911R~
{                                                                  //~v911I~
	int rc;	//hdr0 edit length                                     //~v911I~
//**********************                                           //~v911I~
  	if (UCBITCHK(swsw3,SW3FORM2P))	//form 2p                      //~v911R~
    {                                                              //~v911I~
        if (lineprefixsw)       //line prefix output               //~v911R~
        {                                                          //~v911R~
            Shalfprintwidth=maxcol;                                //~v911R~
            Sprintwidth=Shalfprintwidth+Slrspaceyn+Shalfprintwidth;//~v919R~
  	  		rc=Sprintwidth;		//hdr line length                  //~v918I~
        }                                                          //~v911R~
        else                                                       //~v911R~
        {                                                          //~v911R~
//          Shalfprintwidth=maxcol-LINENOSZ;                       //~v918R~
            Shalfprintwidth=maxcol-LINENOSZ-1;                     //~v918I~
            Sprintwidth=Sleftmarginnn+Shalfprintwidth+Slrspace+Shalfprintwidth;//~v919R~
		  	rc=Sprintwidth-Sleftmarginnn;		//hdr line length  //~v919R~
        }                                                          //~v911R~
//  	rc=Sprintwidth;		//hdr line length                      //~v918R~
    }                                                              //~v911I~
    else						// /y2                             //~v911R~
    {                                                              //~v911I~
        Shalfprintwidth=Pprintwidth;                               //~v911R~
		Sprintwidth=Shalfprintwidth+Slrspace+Shalfprintwidth;      //~v911R~
        rc=Shalfprintwidth;	//hdr on each left and right           //~v911R~
    }                                                              //~v911I~
    Spageheight=maxline+header0outsw+header1outsw+header1outsw;    //~v911I~
    return rc;                                                     //~v911R~
}//get2pwidth                                                      //~v911I~
//********************************                                 //~v911I~
//****************************************************************************
//start new page
//****************************************************************************
//int newpage2p(void)                                              //~v911R~
int newpage2p(int Ppageno)                                         //~v911I~
{
    int leftpagesw,newpagesw;                                      //~v904R~
//********************************
//  if (despageno)      //reverse page print                       //~v911R~
//  {                                                              //~v911R~
//      leftpagesw=((despageno-breakpage)%2==0); //left when residual page is even//~v911R~
//      newpagesw=!leftpagesw || (breakpage==1);                   //~v911R~
//  }                                                              //~v911R~
//  else                                                           //~v911R~
//      newpagesw=leftpagesw=(breakpage%2!=0);                     //~v911R~
  	newpagesw=leftpagesw=(Ppageno%2!=0);                           //~v911R~
//printf("\nnewpage2p Gpage2p=%d\n",Ppageno);                      //~v914R~
    Sleftpagesw=leftpagesw; //parm to putline2p                    //~v911I~
    if (newpagesw)    //before new page start                      //~v90gR~
        closepage2p();                                             //~v90kR~
    Sopenpagesw=1;                                                 //~v844R~
    Sposy=0;                                                       //~v90gR~
  	if (leftpagesw)                                                //~v90gR~
    {                                                              //~v90gI~
    	Sposylast=0;                                               //~v90gI~
     if (UCBITCHK(swsw3,SW3FORM2P))                                //~v911I~
      if (lineprefixsw)		//line prefix output                   //~v911I~
    	Sposx=0;                                                   //~v911I~
      else                                                         //~v911I~
    	Sposx=Sleftmarginnn;                                       //~v919R~
     else                                                          //~v911I~
    	Sposx=0;                                                   //~v90gR~
    }                                                              //~v90gI~
  	else                                                           //~v90gR~
    {                                                              //~v911I~
     if (UCBITCHK(swsw3,SW3FORM2P))                                //~v911I~
      if (lineprefixsw)		//line prefix output                   //~v911I~
    	Sposx=Shalfprintwidth+Slrspaceyn;                          //~v919R~
      else                                                         //~v911I~
    	Sposx=Sleftmarginnn+Shalfprintwidth+Slrspace;              //~v919R~
     else                                                          //~v911I~
    	Sposx=Shalfprintwidth+Slrspace;                            //~v911R~
    }                                                              //~v911I~
//  if (S2width<maxcol+maxcol+Slrspace)                            //~v911R~
//  if (S2width<Sprintwidth+1)                                     //~v91cR~
    if (S2width<Sprintwidth+10) //dbcs ovf+\n+rsv(8)               //~v91cI~
    {                                                              //~v90gI~
    	if (S2pagewk)                                              //~v914R~
        	free(S2pagewk);                                        //~v90gI~
    	if (S2pagewk2)                                             //~v914I~
        	free(S2pagewk2);                                       //~v914I~
    	if (S2pagewk3)                                             //~v91cI~
        	free(S2pagewk3);                                       //~v91cI~
//      S2width=maxcol+maxcol+Slrspace+1;                          //~v911R~
//      S2width=Sprintwidth+1;                                     //~v91cR~
        S2width=Sprintwidth+10;                                    //~v91cI~
        S2pagewksz=S2width*(maxline+5);                            //~v90gR~
        S2pagewk=malloc((UINT)S2pagewksz);                         //~v90mR~
    	memset(S2pagewk,' ',(UINT)S2pagewksz);                     //~v90mR~
        S2pagewk2=malloc((UINT)(S2width+MAXESCCMD));               //~v914R~
//      S2pagewk3=malloc((UINT)(sizeof(int)*(maxline+5)));         //~v91cR~//~v9a0R~
        S2pagewk3=malloc((sizeof(int)*((size_t)maxline+5)));       //~v9a0I~
    }                                                              //~v90gI~
    return newpagesw;                                              //~v90gR~
}//newpage2p                                                       //~v90kR~
//****************************************************************************
//close page
//****************************************************************************
void closepage2p(void)                                             //~v90kR~
{
	int ii;                                                        //~v90gI~
	int printwidth;                                                //~v91cI~
    char *pc;                                                      //~v90gI~
//********************************
	if (!Sopenpagesw)
        return;
    Sopenpagesw=0;                                                 //~v914M~
//#if  defined(W32) || defined(OS2)                                //~v92dR~
#if  defined(W32) || defined(OS2) ||defined(GXP)                   //~v92dI~
//#ifdef W32                                                       //~v92dR~
#if defined(W32)||defined(GXP)                                     //~v92dI~
  if (prntyp==PRINTER_WIN)                                         //~v914I~
#endif                                                             //~v915I~
#ifdef OS2                                                         //~v915I~
  if (docnamesw)                                                   //~v915I~
#endif                                                             //~v915I~
  {                                                                //~v914I~
  	memcpy(S2pagewk2,Shdrcmd,(UINT)Shdrcmdlen);                    //~v915R~
//  memcpy(S2pagewk2+Shdrcmdlen,S2pagewk,(UINT)Sprintwidth);       //~v91cR~
    printwidth=S2pagewk3[0];                                       //~v91cI~
    memcpy(S2pagewk2+Shdrcmdlen,S2pagewk,(UINT)printwidth);        //~v91cI~
//  *(S2pagewk2+Shdrcmdlen+Sprintwidth)='\n';                      //~v91cR~
    *(S2pagewk2+Shdrcmdlen+printwidth++)='\n';                     //~v91cI~
    hdr0linesw=1;		//hdr line                                 //~v914I~
#ifdef W32                                                         //~v915I~
//  win_putline(S2pagewk2,(UINT)(Shdrcmdlen+Sprintwidth+1));       //~v91cR~
    win_putline(S2pagewk2,(UINT)(Shdrcmdlen+printwidth));          //~v91cI~
#else                                                              //~v915I~
  #ifdef GXP                                                       //~v91xI~
    lnx_putline(S2pagewk2,(UINT)(Shdrcmdlen+printwidth));          //~v91xI~
  #else                                                            //~v91xI~
//  os2_putline(S2pagewk2,(UINT)(Shdrcmdlen+Sprintwidth+1));       //~v91cR~
    os2_putline(S2pagewk2,(UINT)(Shdrcmdlen+printwidth));          //~v91cI~
  #endif                                                           //~v91xI~
#endif                                                             //~v915I~
//printf("S2pagewk=%.*s\n",Shdrcmdlen+Sprintwidth,S2pagewk2);      //~v915R~
    hdr0linesw=0;		//hdr line                                 //~v914I~
    for (ii=1;ii<Sposylast;ii++)                                   //~v914I~
    {                                                              //~v914I~
//    	memcpy(S2pagewk2,S2pagewk+ii*S2width,(UINT)Sprintwidth);   //~v91cR~
//  	*(S2pagewk2+Sprintwidth)='\n';                             //~v91cR~
      	printwidth=S2pagewk3[ii];                                  //~v91cI~
        pc=S2pagewk+ii*S2width;                                    //~v91cI~
    	*(pc+printwidth++)='\n';                                   //~v91cI~
#ifdef W32                                                         //~v915I~
//  	win_putline(S2pagewk2,(UINT)(Sprintwidth+1));              //~v91cR~
    	win_putline(pc,(UINT)printwidth);                          //~v91cI~
#else                                                              //~v915I~
  #ifdef GXP                                                       //~v92dI~
    	lnx_putline(pc,(UINT)printwidth);                          //~v92dI~
  #else                                                            //~v92dI~
//  	os2_putline(S2pagewk2,(UINT)(Sprintwidth+1));              //~v91cR~
    	os2_putline(pc,(UINT)printwidth);                          //~v91cI~
  #endif                                                           //~v92dI~
#endif                                                             //~v915I~
//printf("S2pagewk=%.*s\n",Sprintwidth,S2pagewk2);                 //~v915R~
    }                                                              //~v914I~
  }                                                                //~v914I~
  else                                                             //~v914I~
  {                                                                //~v914I~
#endif                                                             //~v915I~
    if (Shdrcmdlen)                                                //~v90gI~
    {                                                              //~v91xI~
  		if (UCBITCHK(swsw4,SW4NOFFCMD)  //skip ff insert           //~v91xI~
        &&  *Shdrcmd==FORMFEED)                                    //~v91xI~
        {                                                          //~v91xI~
        	if (Shdrcmdlen>1)                                      //~v91xI~
		    	fwrite(Shdrcmd+1,1,(UINT)(Shdrcmdlen-1),Sfh);      //~v91xI~
		}                                                          //~v91xI~
        else                                                       //~v91xI~
    	fwrite(Shdrcmd,1,(UINT)Shdrcmdlen,Sfh);                    //~v90mR~
    }                                                              //~v91xI~
    for (ii=0;ii<Sposylast;ii++)                                   //~v90gI~
    {                                                              //~v90gI~
      	printwidth=S2pagewk3[ii];                                  //~v91cI~
		pc=S2pagewk+ii*S2width;                                    //~v90gI~
//  	fwrite(pc,1,(UINT)S2width,Sfh);                            //~v911R~
//  	fwrite(pc,1,(UINT)Sprintwidth,Sfh);                        //~v918R~
//  	fwrite("\n",1,1,Sfh);                                      //~v918R~
//  	*(pc+Sprintwidth)='\n';                                    //~v91cR~
    	*(pc+printwidth++)='\n';                                   //~v91cI~
//  	fwrite(pc,1,(UINT)Sprintwidth+1,Sfh);                      //~v91cR~
    	fwrite(pc,1,(UINT)printwidth,Sfh);                         //~v91cI~
//printf("fwrite %.*s\n",30,pc);                                   //~v918M~
    }                                                              //~v90gI~
//#if  defined(W32) || defined(OS2)                                //~v92dR~
#if  defined(W32) || defined(OS2) || defined(GXP)                  //~v92dI~
  }                                                                //~v914I~
#endif                                                             //~v915I~
    memset(S2pagewk,' ',(UINT)S2pagewksz);                         //~v90mR~
    return;
}//closepage2p                                                     //~v90kR~
//****************************************************************************//~v90gI~
//close doc                                                        //~v90gI~
//****************************************************************************//~v90gI~
void closedoc2p(void)                                              //~v90kR~
{                                                                  //~v90gI~
//********************************                                 //~v90gI~
	closepage2p();                                                 //~v90kR~
}//closedoc2p                                                      //~v90kR~
//****************************************************************************
//write line dest                                                  //~v90gR~
//parm1:text addr
//parm2:hdr0cmd len                                                //~v90gR~
//parm3:text len                                                   //~v90gI~
//****************************************************************************
int putline2p(char *Pbuff,int Phdrcmdlen,unsigned long Plen,FILE *Pfh)//~v90kR~
{
static int Spageno=0;                                              //~v91bI~
    char *ptext,*pc;                                               //~v844R~
    long len;	                                                   //~v90gR~
    long len2;                                                     //~v911I~
    int  lastcr,leftpagesw=0;                                        //~v90gR~//~v965R~
    int  longtrailerlen=0,trailerlinectr=0;                        //~v911R~
#if defined(UTF8SUPP) && defined(LNX) && !defined(GXP)  	//linux console//~v92nI~
	int lnxutfconsw=0;                                             //~v92nI~
#endif                                                             //~v92nI~
//********************************
#if defined(UTF8SUPP) && defined(LNX) && !defined(GXP)  	//linux console//~v92nI~
  		if (Gxputfstat & GXPUS_UCSLINE	//data is unicode          //~v92nI~
		&&  (!UCBITCHK(swsw4,SW4OUTFILE) || UCBITCHK(swsw4,SW4OUTSTDO))//~v92nR~
           )                                                       //~v92nI~
            lnxutfconsw=1;              //linux console version, utf file print//~v92nI~
#endif                                                             //~v92nI~
//  if (!UCBITCHK(swsw3,SW3WIN2P))                                 //~v911R~
    if (!UCBITCHK(swsw3,SW3WIN2P|SW3FORM2P))                       //~v911I~
    {                                                              //~v91xI~
	    if (hdr0linesw 		//form feed                            //~v91xI~
  		&&  UCBITCHK(swsw4,SW4NOFFCMD)  //skip ff insert           //~v91xI~
        &&  *Pbuff==FORMFEED)                                      //~v91xR~
        {                                                          //~v91xI~
        	if (Plen>1)                                            //~v91xI~
    			return (int)fwrite(Pbuff+1,1,(UINT)(Plen-1),Pfh)+1;//~v91xR~
            return 1;                                              //~v91xI~
        }                                                          //~v91xI~
        else                                                       //~v91xI~
#if defined(UTF8SUPP) && defined(LNX) && !defined(GXP)  	//linux console//~v92nI~
  		if (Gxpotheropt & GOO_EBCBYUCS_UTF8		//locale is utf8   //~v96zR~
  		&&  Gxputfstat & GXPUS_UCSLINE_EBC)	//data is unicode from ebc//~v96zR~
    		return (int)utf_fwrite(Pbuff,(UINT)Plen,Pfh);          //~v96zR~
        else                                                       //~v96zR~
        if (lnxutfconsw)              //linux console version, utf file print//~v92nI~
    	return (int)utf_fwrite(Pbuff,(UINT)Plen,Pfh);              //~v92nR~
        else                                                       //~v92nI~
#endif                                                             //~v92nI~
    	return (int)fwrite(Pbuff,1,(UINT)Plen,Pfh);                //~v90mR~
    }                                                              //~v91xI~
//double paging                                                    //~v90gM~
    Sfh=Pfh;                                                       //~v90gI~
    len=(int)Plen;                                                 //~v90mR~
    ptext=Pbuff;                                                   //~v844I~
    if (hdr0linesw)		//form feed                                //~v844R~
    {                                                              //~v844I~
    	Spageno++;                                                 //~v91bI~
//      leftpagesw=newpage2p();                                    //~v911R~
        leftpagesw=newpage2p(Gpage2p);                             //~v911I~
//      if (leftpagesw)                                            //~v91bR~
        if (leftpagesw||Spageno==1) //left or 1st page of when /p parm//~v91bI~
        {                                                          //~v90gI~
			memcpy(Shdrcmd,ptext,(UINT)Phdrcmdlen);                //~v90mR~
        	Shdrcmdlen=Phdrcmdlen;                                 //~v90gR~
        }                                                          //~v90gI~
    	ptext+=Phdrcmdlen;                                         //~v90gR~
        len-=Phdrcmdlen;                                           //~v90gI~
	}                                                              //~v844I~
    if (Gtrailersw) //trailer outsw                                //~v911I~
    {                                                              //~v911I~
        pc=ptext;                                                  //~v911M~
//printf("\ntrailer 1stline=%.*s\n",60,ptext);                     //~v914R~
        len2=len;                                                  //~v911M~
        trailerlinectr=0;                                          //~v911I~
    	while(len2 && *pc=='\n')                                   //~v911M~
    	{                                                          //~v911M~
        	pc++;                                                  //~v911M~
        	len2--;                                                //~v911M~
            trailerlinectr++;                                      //~v911M~
    	}                                                          //~v911M~
        if (Shalfprintwidth<len2)                                  //~v911R~
        {                                                          //~v911I~
            longtrailerlen=(int)len2-Shalfprintwidth;                   //~v911R~//+v9a1R~
            len=Shalfprintwidth+trailerlinectr;    //save and print at closedoc2p//~v911R~
        }                                                          //~v911I~
        trailerlinectr+=1+(longtrailerlen!=0);                     //~v911R~
//printf("trailer 2ndline=%d,Sleftpagesw=%d,Sposy=%d,Sposylast=%d\n",longtrailerlen,Sleftpagesw,Sposy,Sposylast);//~v914R~
//printf("Spageheight=%d,Sposy=%d,trailerctr=%d\n",Spageheight,Sposy,trailerlinectr); //no spec//~v914R~
        if (Spageheight-Sposy<trailerlinectr)  //no spec           //~v911I~
        {                                                          //~v91xI~
        	if (Sleftpagesw)                                       //~v911I~
		        leftpagesw=newpage2p(Gpage2p+1);                   //~v911R~
            else                                                   //~v911I~
            	return (int)Plen;                                  //~v915R~
        }                                                          //~v91xI~
    }                                                              //~v911I~
    while(len && *ptext=='\n')                                     //~v844I~
    {                                                              //~v844I~
        ptext++;                                                   //~v844I~
        len--;                                                     //~v844I~
		Sposy++;                                                   //~v90gR~
    }                                                              //~v844I~
    pc=ptext+len-1;                                                //~v844I~
    lastcr=0;                                                      //~v844I~
    while(len && *pc=='\n')                                        //~v844I~
    {                                                              //~v844I~
    	len--;                                                     //~v844I~
        lastcr++;                                                  //~v844I~
        pc--;                                                      //~v844I~
    }                                                              //~v844I~
  if (!(   hdr0linesw		//form feed                            //~v911I~
        && !leftpagesw		//right page                           //~v911I~
        &&  UCBITCHK(swsw3,SW3FORM2P)                              //~v911I~
        ))	//hdd line/form                                        //~v911I~
  {                                                                //~v91cI~
	memcpy(S2pagewk+Sposy*S2width+Sposx,ptext,(UINT)len);          //~v90mR~
//  S2pagewk3[Sposy]=Sposx+len;                                    //~v91cI~//+v9a1R~
    S2pagewk3[Sposy]=Sposx+(int)len;                               //+v9a1I~
  }                                                                //~v91cI~
//printf("posy=%d,posx=%d\n",Sposy,Sposx);                         //~v914R~
//printf("ptext=%.*s\n",120,ptext);                                //~v914R~
 if (lastcr)                                                       //~v911R~
    while(lastcr)                                                  //~v844I~
    {                                                              //~v844I~
    	lastcr--;                                                  //~v844I~
		Sposy++;                                                   //~v90gR~
    }                                                              //~v844I~
 else                                                              //~v911I~
    if (longtrailerlen)                                            //~v911I~
    	Sposy++;                                                   //~v911R~
//if (Sleftpagesw)      //left page                                //~v91bR~
  if (Sleftpagesw||Spageno==1)  //left page                        //~v91bI~
    if (Sposy>Sposylast)                                           //~v90gM~
    	Sposylast=Sposy;	//max line in page                     //~v90gM~
//if (Gtrailersw)                                                  //~v911R~
//printf("Sposylast=%d\n",Sposylast);                              //~v911R~
    if (longtrailerlen)                                            //~v911R~
    	putline2p(ptext+len,Phdrcmdlen,(UINT)longtrailerlen,Pfh);  //~v915R~
//if (Gtrailersw)                                                  //~v911R~
//printf("Sposylast=%d\n",Sposylast);                              //~v911R~
    return (int)Plen;                                              //~v90mR~
}//putline2p                                                       //~v92dR~
