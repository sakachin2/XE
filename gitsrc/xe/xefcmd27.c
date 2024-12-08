//*CID://+vb45R~:                             update#=  629;       //~vb45R~
//*************************************************************
//*xefcmd27.c                                                      //~v78iR~
//*  grep/P'..'                                                    //~v78iR~
//****************************************************************//
//vb45:160720 isalpha() returns true for other than A-Z,a-z. use isupper and islower.//~vb45I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//v78x:080407 F'$' dose not match to ctl and space under mainframe TSO//~v78xI~
//v78i:080312*P'.' by [:cntrl:] (00-1f,7f,80) not by ^[:print:] which match with dbcs/utf//~v78iI~
//v78h:080312*Not sign for P'..' search,accept 0xac additional to ^//~v78hI~
//v78f:080310 Use \ for escape char for P'...' pattern             //~v78dI~
//v78d:070111*split fcmd2 to fcmd25 fcmd26                         //~v78dR~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ualloc.h>

//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <uerr.h>
#include <uparse.h>
#include <ustring.h>
#include <ufile.h>
#include <uedit.h>
#include <utrace.h>
#include <uregex.h>
#include <udbcschk.h>                                              //~vb45I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefcmd2.h"
#include "xefcmd22.h"                                              //~v78dI~
#include "xefcmd27.h"
#include "xefunc.h"
#include "xeerr.h"
//*******************************************************
//****************************************************************
static regex_t Sregcomp[2];
static int Sregcompsw[2];                                          //~v78dR~
static int Ssubstrstart,Ssubstrend;                                //~v78dI~
static  struct re_registers Sregs={1,&Ssubstrstart,&Ssubstrend};   //~v78dR~
//**************************************************************** //~v78dI~
int fcmdcvpicture(UCHAR *Pppatp,UCHAR *Pppatg,int Pbufflen);       //~v78dI~
//****************************************************************
//!fcmdgrepcomp
//compile regex pattern
//****************************************************************
int fcmdgrepcomp(int Popt,PUCLIENTWE Ppcw,UCHAR *Ppattern,int Pcasesw)
{
    regex_t *pre;
	const char *perr;                                              //~v78dR~
	int idx;                                                       //~v78dR~
	reg_syntax_t resyntax;                                         //~v78dI~
    UCHAR  ppattern[MAXCOLUMN],*ppat;                              //~v78dR~
//*******************
	resyntax=FCMD_REGEX_SYNTAX;                                    //~v78dR~
	if (Popt & FCGCO_AND)
    	idx=1;
    else
    	idx=0;
    pre=Sregcomp+idx;
    if (Sregcompsw[idx])
		regfree(pre);
    memset(pre,0,sizeof(regex_t));                                 //~v78dI~
    if (!Pcasesw)
    	resyntax|=RE_ICASE;                                        //~v78dR~
    re_set_syntax(resyntax);                                       //~v78dR~
    if (Sfindopt & FINDOPT_GREPP) //P'.' patern                    //~v78dI~
    {                                                              //~v78dI~
        if (fcmdcvpicture(Ppattern,ppattern,sizeof(ppattern)))     //~v78dR~
        	return 4;                                              //~v78dI~
        ppat=ppattern;                                             //~v78dI~
    }                                                              //~v78dI~
    else                                                           //~v78dI~
        ppat=Ppattern;                                             //~v78dI~
//  rc=regcomp(pre,(char*)Ppattern,opt);  //POSIX interface
    perr=re_compile_pattern(ppat,strlen(ppat),pre);  //POSIX interface//~v78dR~
	if (perr)
	{
//  	regerror(rc,pre,buf,sizeof(buf));
        if (ppat==Ppattern)                                        //~v78dI~
			uerrmsg("grep expression(%s) err: %s",0,               //~v78dR~
						ppat,perr);                                //~v78dR~
        else                                                       //~v78dI~
			uerrmsg("grep expression(%s --> %s) err: %s",0,        //~v78dI~
						Ppattern,ppat,perr);                       //~v78dI~
        return 4;
    }
    pre->regs_allocated=REGS_FIXED;    //use only 1 entry(not for each group)//~v78dR~
    Sregcompsw[idx]=1;	//free next
	return 0;
}//fcmdgrepcomp                                                    //~v78dR~
//****************************************************************
//!fcmdgrepplh                                                     //~v78dR~
//Pdata:(FWD)search start addr on plhdata
//     :(BWD)search end addr(left boundary) on plhdata
//srchlen:range from left to right boundary(always >0)             //~v78dR~
//****************************************************************
int fcmdgrepplh(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,UCHAR *Pdata,int Psrchlen,int Pcasesw,UCHAR **Pmatchstr,int *Pmatchlen)
{
	UCHAR *pc0,*pc;
    regex_t *pre;
    int rc,srchrc,substrlen,substrstart,substrend,startoffs,range,len,idx,dataoffs;//~v78dR~
//*******************
	if (Sphasesw==2)
    	idx=1;
    else
    	idx=0;
    if (!Sregcompsw[idx])   //1st RFIND after session restart      //~v78dR~
    {                                                              //~v78dI~
        if (idx==1)                                                //~v78dR~
        {                                                          //~v78dI~
			rc=fcmdgrepcomp(FCGCO_AND,Ppcw,Ssrch2,Scasesensesw);   //~v78dI~
        }                                                          //~v78dI~
        else                                                       //~v78dI~
			rc=fcmdgrepcomp(0,Ppcw,Ssrch,Scasesensesw);            //~v78dI~
        if (rc)                                                    //~v78dI~
        {                                                          //~v78dI~
			*Pmatchstr=0;                                          //~v78dI~
            return 4;                                              //~v78dI~
        }                                                          //~v78dI~
    }                                                              //~v78dI~
    pre=Sregcomp+idx;
//  rc=regexec(pre,pc,20,match,0);	//POSIX
	pc0=Pplh->ULHdata;
	len=Pplh->ULHlen;
//	dataoffs=(int)((ULONG)Pdata-(ULONG)pc0);                       //~v78dI~//~vafkR~
	dataoffs=(int)((ULPTR)Pdata-(ULPTR)pc0);                       //~vafkI~
    if (dataoffs+Psrchlen<len)//right boundary cut the plh         //~v78dI~
    {                                                              //~v78dI~
        len=dataoffs+Psrchlen;                                     //~v78dI~
        pre->not_eol=1;          //$ dose not match with Srange2   //~v78dI~
    }                                                              //~v78dI~
    else                                                           //~v78dI~
	    pre->not_eol=0; //ANCHOR "$" effective match               //~v78dI~
    if (Popt & FCGPO_BWD)
    {                                                              //~v78dI~
		startoffs=dataoffs+Psrchlen-1;	//from left of right boundary//~v78dR~
        range=-(Psrchlen-1);  			//repeat count after fail  //~v78dR~
    }                                                              //~v78dI~
    else
    {                                                              //~v78dI~
		startoffs=dataoffs;                                        //~v78dR~
        range=Psrchlen-1;                                          //~v78dR~
    }                                                              //~v78dI~
    srchrc=re_search(pre,pc0,len,startoffs,range,&Sregs);          //~v78dR~
    pc=0;                                                          //~v78dI~
    substrlen=0;                                                   //~v78dI~
    rc=4;                                                          //~v78dI~
    if (srchrc>=0)	//match len;-1:unmatch,-2:internal err         //~v78dR~
    {
    	substrstart=Sregs.start[0];                                //~v78dR~
    	substrend=Sregs.end[0];                                    //~v78dR~
//      if (substrend<=dataoffs+Psrchlen)	//tail is in the range //~v78dR~
//      {                                                          //~v78dR~
        	substrlen=substrend-substrstart;                       //~v78dM~
            if (substrlen>0)                                       //~v78dI~
            {                                                      //~v78dI~
        		pc=pc0+substrstart;                                //~v78dR~
        		rc=0;                                              //~v78dR~
            }                                                      //~v78dI~
//      }                                                          //~v78dR~
    }
	*Pmatchstr=pc;
	*Pmatchlen=substrlen;
	return rc;
}//fcmdgrepplh                                                     //~v78dR~
//**************************************************************** //~v78dI~
//!fcmdgrepp                                                       //~v78dI~
//convert P'.' pattern to grep pattern                             //~v78dI~
//**************************************************************** //~v78dI~
int fcmdcvpicture(UCHAR *Pppatp,UCHAR *Pppatg,int Pbufflen)        //~v78dI~
{                                                                  //~v78dI~
	UCHAR *pci,*pce,*pco,*pcp;                                     //~v78dR~
    int tlen,len,tlenmax,ch,nextch;                                //~v78dR~
//#define REP_NONPRINT       "[^[:print:]]"                        //~v78iR~
#define REP_NONPRINT       "[[:cntrl:]]"                           //~v78iI~
#define REP_ALPHA          "[[:alpha:]]"                           //~v78dI~
#define REP_ALPHA_JP       "[A-Za-z]"                              //~vb45I~
#define REP_NONNUMERIC     "[^[:digit:]]"                          //~v78dI~
#define REP_NUMERIC        "[[:digit:]]"                           //~v78dI~
#define REP_LOWER          "[[:lower:]]"                           //~v78dI~
//#define REP_SPECIAL        "[^[:alpha:][:digit:]]"               //~v78fR~
#define REP_SPECIAL        "[[:punct:]]"                           //~v78xR~
#define REP_UPPER          "[[:upper:]]"                           //~v78dI~
#define REP_NONBLANK       "[^[:space:]]"                          //~v78dI~
#define REP_BLANK          "[[:space:]]"                           //~v78dI~
#define REP_PICALL        "=.@-#<$>^\\"                            //~v78dI~
//*******************                                              //~v78dI~
	tlenmax=Pbufflen-1;                                            //~v78dR~
	for (pci=Pppatp+2,pce=pci+strlen(pci)-1,pco=Pppatg,tlen=0;pci<pce;pci++)//~v78dI~
    {                                                              //~v78dI~
        len=1;                                                     //~v78dI~
        pcp=pci;                                                   //~v78dI~
    	switch(*pci)                                               //~v78dI~
        {                                                          //~v78dI~
        case '=':	//any                                          //~v78dI~
        	pcp=".";                                               //~v78dI~
            break;                                                 //~v78dI~
        case '.':	//non displayable                              //~v78dI~
        	pcp=REP_NONPRINT;                                      //~v78dR~
            len=sizeof(REP_NONPRINT)-1;                            //~v78dR~
            break;                                                 //~v78dI~
        case '@':	//alpha                                        //~v78dI~
          if (Gudbcschk_flag & (UDBCSCHK_DBCSJ | UDBCSCHK_UTF8J))   //utf-8 of japanese for linux or Japanese special(SJIS/EUC)//+vb45R~
          {                                                        //~vb45I~
        	pcp=REP_ALPHA_JP;                                      //~vb45I~
            len=sizeof(REP_ALPHA_JP)-1;                            //~vb45I~
          }                                                        //~vb45I~
          else                                                     //~vb45I~
          {                                                        //~vb45I~
        	pcp=REP_ALPHA;                                         //~v78dR~
            len=sizeof(REP_ALPHA)-1;                               //~v78dR~
          }                                                        //~vb45I~
            break;                                                 //~v78dI~
        case '-':	//non numeric                                  //~v78dI~
        	pcp=REP_NONNUMERIC;                                    //~v78dI~
            len=sizeof(REP_NONNUMERIC)-1;                          //~v78dI~
            break;                                                 //~v78dI~
        case '#':	//numeric                                      //~v78dI~
        	pcp=REP_NUMERIC;                                       //~v78dI~
            len=sizeof(REP_NUMERIC)-1;                             //~v78dI~
            break;                                                 //~v78dI~
        case '<':	//lower                                        //~v78dI~
        	pcp=REP_LOWER;                                         //~v78dI~
            len=sizeof(REP_LOWER)-1;                               //~v78dI~
            break;                                                 //~v78dI~
        case '$':	//special(not numeric and not alpha            //~v78dR~
        	pcp=REP_SPECIAL;                                       //~v78dI~
            len=sizeof(REP_SPECIAL)-1;                             //~v78dI~
            break;                                                 //~v78dI~
        case '>':	//upper                                        //~v78dI~
        	pcp=REP_UPPER;                                         //~v78dI~
            len=sizeof(REP_UPPER)-1;                               //~v78dI~
            break;                                                 //~v78dI~
        case 0xac:     //ISO Latin1-supplement                     //~v78hI~
        case '^':	//non blank                                    //~v78dI~
        	pcp=REP_NONBLANK;                                      //~v78dR~
            len=sizeof(REP_NONBLANK)-1;                            //~v78dI~
            break;                                                 //~v78dI~
        case ' ':	//space                                        //~v78dI~
        	pcp=REP_BLANK;                                         //~v78dI~
            len=sizeof(REP_BLANK)-1;                               //~v78dI~
            break;                                                 //~v78dI~
        default:                                                   //~v78dI~
	        tlen+=3;                                               //~v78dI~
            if (tlen<tlenmax)                                      //~v78dR~
            {                                                      //~v78dI~
            	*pco++='[';                                        //~v78dI~
            	ch=*pci;                                           //~v78fR~
            	if (ch=='\\') //may be escape                      //~v78fR~
            	{                                                  //~v78fR~
                	nextch=*(pci+1);                               //~v78fR~
                	if (strchr(REP_PICALL,nextch))                 //~v78fR~
                    {                                              //~v78fR~
                    	ch=nextch;                                 //~v78fR~
                        pci++;                                     //~v78fR~
                    }                                              //~v78fR~
            	}                                                  //~v78fR~
            	*pco++=(UCHAR)ch;                                  //~v78iR~
            	*pco++=']';                                        //~v78dI~
            }                                                      //~v78dI~
            continue;                                              //~v78dI~
        }                                                          //~v78dI~
        tlen+=len;                                                 //~v78dI~
        if (tlen>=tlenmax)                                         //~v78dI~
        	return errtoolong();                                   //~v78dI~
        memcpy(pco,pcp,(UINT)len);                                 //~v78dI~
        pco+=len;                                                  //~v78dI~
                                                                   //~v78dI~
    }                                                              //~v78dI~
    *pco=0;                                                        //~v78dI~
	return 0;                                                      //~v78dI~
}//fcmdcvpicture                                                   //~v78dI~
