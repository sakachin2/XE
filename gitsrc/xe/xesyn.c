//*CID://+vb31R~:                             update#=  331;       //~vb31R~
//*************************************************************
//*xesyn.c
//*syntax highlight
//*************************************************************
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vb2J:160313 (W32) compier warning                                //~vabJI~
//vazz:150118 no uerrmsg when SyntacH cfg err                      //~vazzI~
//vaj7:130722 (BUG)syn cmd errmsg not issued                       //~vaj7I~
//vagn:120829 (BUG)syntaxhighlight pgm fail if 0x00 was contained  //~vagnI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va7i:100820 (BUG)syntax chk failed(external syntaxhighlight failed by null data)//~va7iI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            syn.c   :protect ucs2 is written from dd fmt to avoid to be treated as numeric//~va20I~
//v79J:081019 (BUG)SynH issue length err when line contains \n     //~v79JR~
//v79y:080915 (BUG)syntaxh position invalid when copy line between different tabctr//~v78EI~
//v78E:080503 (LNX:BUG)upd line bkgd color not full line(missing v78p for lnx)//~v78vI~
//v78v:080331 (BUG)scr not redrrawn at syn on after syn off        //~v78vI~
//v78r:080326 profile function                                     //~v78rI~
//v78p:080322 (SYN:BUG)redraw required even if update bg=0 to delete previouse bg//~v78pI~
//v78o:080322 (SYN:BUG)reverse is not able to distingush on browse screen//~v78oI~
//v786:080301 (SYNH)"ENTERU":update line only option               //~v786I~
//v780:080212 syntaxhighlight support
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef W32
	#include <windows.h>
	#include <io.h>
	#include <errno.h>
#endif
#ifdef LNX
    #include <unistd.h>
#endif

//*******************************************************
#include <ulib.h>
#include <ualloc.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ustring.h>
#include <uedit.h>
#include <uproc.h>
#include <utrace.h>
#include <uparse.h>
#include <ufemsg.h>

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile6.h"
#include "xefunc.h"
#include "xesub.h"
#include "xeerr.h"
#include "xepan.h"
#include "xeundo.h"
#include "xefcmd6.h"                                               //~v78rI~
#include "xeacb.h"

#define  XESYN_GLOBAL
#include "xesyn.h"
#include "xesyn2.h"

#ifdef WXE
	#include "wxedef.h"
#endif
#ifdef UTF8UCS2                                                    //~va20I~
	#include "xeutf.h"                                             //~va20I~
	#include "xeutf2.h"                                            //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
//****************************************************************
#define ENTERKEY_OPT_ALL       "ENTERA"    //option for all line   //~v786I~
#define ENTERKEY_OPT_ULO       "ENTER"     //option for update line only//~v786I~
#define LANG_OPT_ALL           "All-Line"  //for SYN cmd           //~v786R~
#define LANG_OPT_UPDONLY       "Upd-line"  //for SYN cmd           //~v786R~
//****************************************************************
//****************************************************************
//int synhelp(void);                                               //~v786R~
int synhelp(PUFILEH Ppfh);                                         //~v786I~
//int synwriteplh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pfnminput);//~v780R~
int synwriteplh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pfnminput,PULINEH *Ppplh1,PULINEH *Ppplh2);//~v780I~
#define SWPRC_NOUPDLINE    64    //no line found to write          //~v786I~
//int synexecsh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);            //~v780R~
int synexecsh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Pplh1,PULINEH *Pplh2);//~v780I~
int synall(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);
int synsetenter(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);
int synupdate(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);
int synsetoff(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);
int synseton(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pshtype);
int syngetstartplh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh1,PULINEH *Ppplh2);
int synupdateplh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2);
int syngetplhcolordata(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,int Phandle);
int synchkfiletype(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);
#define SCFTO_OPEN      0x01    //ch at open
#define SCFTO_ERRMSG    0x02    //errmsg issue
void synsetvalid(int Popt,PUFILEH Ppfh);                           //~v786I~
#ifdef UTF8UCS2                                                    //~va20I~
//int xesyn_fwrite(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,FILE *Pfh);//~va20R~//~va79R~
int xesyn_fwrite(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,FILE *Pfh);//~va79R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	#define XESYNFWO_UTF8       0x01                           //~va50I~
    	#define XESYNFWO_EBC        0x02                           //~va50I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
int xesyn_fwrite(UCHAR *Pdata,int Plen,FILE *Pfh);                 //~v79JR~
#endif                                                             //~va20I~
//****************************************************************
//xesyninit
//****************************************************************
int xesyninit(int Popt)
{
    int rc=0;                                                      //~v78pR~
#ifdef WXEXXE
    int len;
#endif
//*****************************::
#ifdef WXEXXE
	len=Gscrbuffwidth*Gscrbuffheight;
	Gsynstyletbl=UALLOCM((UINT)len);
    memset(Gsynstyletbl,0,(UINT)len);
#endif
#ifdef SYNSUPP                                                     //~v78pI~
	rc=syngetcfg(SGCO_INIT);
#endif                                                             //~v78pI~
	return rc;
}//xesyninit
//****************************************************************
//xesynterm
//****************************************************************
int xesynterm(int Popt)
{
//*****************************::
#ifdef SYNSUPP
	syncfgfree(SCFO_UNLINK);
#endif
#ifdef WXEXXE
    ufree(Gsynstyletbl);
#endif
	return 0;
}//xesynterm
//****************************************************************
// syntax highligh cmd
//*rc   :0
//****************************************************************
int func_syntax(PUCLIENTWE Ppcw)
{
#ifndef SYNSUPP
	return errnotsupported("SYN","except Win and Linux");
#else
static UCHAR *Swordtbl="?\0"
                       "ON\0" "OFF\0"
//                     "RESET\0" "ENTER\0" "ALL\0"                 //~v786R~
                       "RESET\0"                                   //~v786I~
 						ENTERKEY_OPT_ULO "\0"                      //~v786I~
						 "ALL\0"                                   //~v786I~
 						ENTERKEY_OPT_ALL "\0"                      //~v786R~
						;
	UCHAR *pc,*pcopt=0,*pshtype=0;
//  int rc,opdno,ii,opid,onoffsw=0,entersw=0,updatesw=0;           //~vaa7R~
    int rc=0,opdno,ii,opid,onoffsw=0,entersw=0,updatesw=0;         //~vaa7I~
    int allsw=0;                                                   //~v780R~
    PUFILEH pfh;
//*********************************
    if (Ppcw->UCWtype!=UCWTFILE                                    //~v786I~
    ||  Ppcw->UCWmenuopt==PANMOCMD)                                //~v786I~
        pfh=0;                                                     //~v786I~
    else                                                           //~v786I~
		pfh=UGETPFHFROMPCW(Ppcw);                                  //~v786I~
    opdno=Ppcw->UCWopdno;
    pc=Ppcw->UCWopdpot;
    if (!opdno						//no operand
	||  Ppcw->UCWkeytype!=UCWKTCMD)	//funckey
    {
    	updatesw=1;		//do update color inf
        pcopt="SYN key";
    }
    else
    {
        for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)    //next operand addr
        {
        	if (ii==0)
            	pcopt=pc;
            opid=wordtblisrch(pc,Swordtbl);
            switch(opid)
            {
            case 0: //err
            	if (onoffsw==1 && !pshtype)
                {
                	pshtype=pc;
                    break;
                }
                return errinvalid(pc);
            case 1: //?
//              return synhelp();                                  //~v786R~
                return synhelp(pfh);                               //~v786I~
//              return 0;                                          //~vafhR~
            case 2: //ON
                onoffsw=1;
                break;
            case 3: //OFF;
                onoffsw=-1;
                break;
            case 4: //RESET
                rc=syngetcfg(SGCO_RESET);
                if (!rc)
                    uerrmsg("SyntaxHL configuration was reset",0);
				scrfulldraw(Ppcw);                                 //~v780I~
                return rc;
            case 5: //ENTER
//              entersw=1;                                         //~v780R~
                entersw=SYNCPO_ENTERU;                             //~v786R~
                break;
            case 6: //ALL
                allsw=1;
                break;
            case 7: //ENTERA                                       //~v786R~
//              entersw=SYNCPO_ALL;                                //~v786R~//~vb30R~
                entersw=(int)SYNCPO_ALL;                           //~vb30I~
                break;                                             //~v780I~
            }
        }//loop by operand no
    }//opdno!=0
//  if (Ppcw->UCWtype!=UCWTFILE                                    //~v786R~
//  ||  Ppcw->UCWmenuopt==PANMOCMD)                                //~v786R~
    if (!pfh)                                                      //~v786I~
        return errscrtype(pcopt);
//  pfh=UGETPFHFROMPCW(Ppcw);                                      //~v786R~
    if (entersw)
    {                                                              //~v780I~
//      rc=synsetenter(0,Ppcw,pfh);                                //~v780R~
        if (onoffsw==-1)                                           //~v78rI~
        	entersw=0;                                             //~v78rI~
        rc=synsetenter(entersw,Ppcw,pfh);                          //~v780I~
    }                                                              //~v780I~
    else
    if (onoffsw>0)
        rc=synseton(0,Ppcw,pfh,pshtype);
    else
    if (onoffsw<0)
        rc=synsetoff(0,Ppcw,pfh);
    else
    if (updatesw)
//      rc=synupdate(0,Ppcw,pfh);                                  //~v780R~
//      rc=synupdate(SYNCPO_ALL,Ppcw,pfh);                         //~v780I~//~vb30R~
        rc=synupdate((int)SYNCPO_ALL,Ppcw,pfh);                    //~vb30I~
    else
    if (allsw)
        rc=synall(0,Ppcw,pfh);
    if (rc)                                                        //~vazzI~
		if (!(Gsyncfg.SYNCflag & SYNCF_OK))                        //~vazzI~
            if (!ugeterrmsg2())                                    //~vazzI~
        		uerrmsg("SyntaxHighligt cfg file(%s) may have error",0,//~vazzR~
            		SHFNM_CONFIG);                                 //~vazzR~
    return rc;
#endif //SYNSUPP
}//func_syntax
#ifdef SYNSUPP
//****************************************************************
//help
//****************************************************************
//int synhelp(void)                                                //~v786R~
int synhelp(PUFILEH Ppfh)                                          //~v786I~
{
	UCHAR *pc2;
//***********************
//  uerrmsg("SYN [ ALL | RESET | ENTER | ON [lang-type] | OFF]",0);//~v786R~
    uerrmsg("SYN [ ALL | RESET | %s | %s | ON [lang-type] | OFF]",0,//~v786R~
				ENTERKEY_OPT_ULO,ENTERKEY_OPT_ALL);                //~v786I~
    if (Ppfh)                                                      //~v786R~
    {                                                              //~v786I~
    	pc2=((Ppfh->UFHsynflag & UFHSF_ENTERON)                    //~v786I~
             ?LANG_OPT_ALL                                         //~v786R~
             :((Ppfh->UFHsynflag & UFHSF_ENTERONUPDATELINEONLY)    //~v786R~
               ?LANG_OPT_UPDONLY                                   //~v786R~
               :"NoUse"                                            //~v786I~
              )                                                    //~v786I~
            );                                                     //~v786R~
    	uerrmsgcat(" ; Enter-key:%s",0,                            //~v786M~
                		pc2);                                      //~v786I~
    	pc2=((Ppfh->UFHsynflag & UFHSF_UPDATELINEONLYLANG)         //~v786R~
             ?LANG_OPT_UPDONLY                                     //~v786R~
             :LANG_OPT_ALL                                         //~v786I~
            );                                                     //~v786I~
    	uerrmsgcat(" ; Lang:%s",0,                                 //~v786M~
                		pc2);                                      //~v786I~
    }                                                              //~v786I~
    pc2=((Gsyncfg.SYNCflag & SYNCF_OPEN)?"Y":"N");
    uerrmsgcat(" ; cfg: LineNoTH=%d, OPEN=%s",0,                   //~v786R~
                Gsyncfg.SYNCenter,pc2);
    return 0;
}//synhelp
//****************************************************************
//set enter key as trigger
//****************************************************************
int synsetenter(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)
{
//  int swall,swon=1;                                              //~vaa7R~
    int swall=0,swon=1;                                            //~vaa7I~
//********************
	if (synchkfiletype(SCFTO_ERRMSG,Ppcw,Ppfh))
    	return 4;
  if (Popt & SYNCPO_ENTERU)  //ENTERU                              //~v780R~
  {                                                                //~v780I~
	if (Ppfh->UFHsynflag & UFHSF_ENTERONUPDATELINEONLY)            //~v786R~
    	return erralready();                                       //~v780I~
    swall=0;                                                       //~v78rI~
	Ppfh->UFHsynflag|=UFHSF_ENTERONUPDATELINEONLY;                 //~v786R~
//  Ppfh->UFHsynflag&=~UFHSF_ENTERON;                              //~v780I~//~vb30R~
    Ppfh->UFHsynflag&=~(ULONG)UFHSF_ENTERON;                       //~vb30I~
    uerrmsg("Next ENTER key will re-evaluate syntax for update line only",0);//~v780I~
  }                                                                //~v780I~
  else                                                             //~v780R~
//if (Popt & SYNCPO_ALL)  //ENTERA                                 //~v78rI~//~vb30R~
  if ((unsigned)Popt & SYNCPO_ALL)  //ENTERA                       //~vb30I~
  {                                                                //~v780I~
	if (Ppfh->UFHsynflag & UFHSF_ENTERON)
    	return erralready();
    swall=1;                                                       //~v78rI~
	Ppfh->UFHsynflag|=UFHSF_ENTERON;
//  Ppfh->UFHsynflag&=~UFHSF_ENTERONUPDATELINEONLY;                //~v786R~//~vb30R~
    Ppfh->UFHsynflag&=~(ULONG)UFHSF_ENTERONUPDATELINEONLY;         //~vb30I~
//  uerrmsg("Next ENTER key will re-evaluate SyntaxHL",0);         //~v780R~
    uerrmsg("Next ENTER key will re-evaluate all line",0);         //~v780I~
  }                                                                //~v780I~
  else                                                             //~v78rI~
  {                                                                //~v78rI~
//  Ppfh->UFHsynflag&=~(UFHSF_ENTERON|UFHSF_ENTERONUPDATELINEONLY);//~v78rI~//~vb30R~
    Ppfh->UFHsynflag&=~(ULONG)(UFHSF_ENTERON|UFHSF_ENTERONUPDATELINEONLY);//~vb30I~
  	swon=0;                                                        //~v78rI~
  }                                                                //~v78rI~
	fcmdprofupdaterecord(FPURO_SYNENTER,Ppfh->UFHfilename,0/*no strparm*/,swon,swall);//~v78rI~
    return 0;
}//synsetenter
//****************************************************************
//set file to syntax on
//****************************************************************
int synseton(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Plangtype)
{
	int rc;
//********************
	if (synchkfiletype(SCFTO_ERRMSG,Ppcw,Ppfh))
    	return 4;
    if (Plangtype)
    {
    	if (strlen(Plangtype)>MAX_SYNTYPE)
        {
        	uerrmsg("Invalid(len>%d) langtype(%s) parameter.",
            		"長すぎる(>%d) 言語タイプパラメータ(%s)",
                    	MAX_SYNTYPE,Plangtype);
            return 4;
        }
        strcpy(Ppfh->UFHsyntype,Plangtype);
    }
    fcmdprofupdaterecord(FPURO_SYNOPEN,Ppfh->UFHfilename,Plangtype,1/*on*/,0/*num2 not used*/);//~v78rI~
//  rc=synupdate(Popt,Ppcw,Ppfh);                                  //~v780R~
//  rc=synupdate(SYNCPO_ALL,Ppcw,Ppfh);                            //~v780I~//~vb30R~
    rc=synupdate((int)SYNCPO_ALL,Ppcw,Ppfh);                       //~vb30I~
    return rc;
}//synseton
//****************************************************************
//set file to syntax off
//****************************************************************
int synsetoff(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)
{
//********************
	if (synchkfiletype(SCFTO_ERRMSG,Ppcw,Ppfh))
    	return 4;
	if (!(Ppfh->UFHsynflag & UFHSF_ON))
    	return erralready();
//  Ppfh->UFHsynflag&=~UFHSF_ON;                                   //~vb30R~
    Ppfh->UFHsynflag&=~(ULONG)UFHSF_ON;                            //~vb30I~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);    //redraw
	fcmdprofupdaterecord(FPURO_SYNOPEN,Ppfh->UFHfilename,0,0/*off*/,0/*num2 not used*/);//~v78rR~
    return 0;
}//synsetoff
//****************************************************************
//do for updated line
//opt:update by enter key                                          //~v780I~
//****************************************************************
int synupdate(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)
{
	int rc;
	PULINEH plh1,plh2;
    int flag,nothingtodosw=0;                                      //~v786R~
//********************
//  flag=Ppfh->UFHsynflag;                                         //~v786I~//~vb30R~
    flag=(int)Ppfh->UFHsynflag;                                    //~vb30I~
    if (!(flag & UFHSF_ON))                                        //~v786R~
		return synall(Popt,Ppcw,Ppfh);
    if (flag & UFHSF_VALID)                                        //~v786I~
    {                                                              //~v786I~
    	if (flag & UFHSF_VALIDUPDATELINEONLY)	//validated updated line only//~v786I~
        {                                                          //~v786I~
        	if ((Popt & SYNCPO_ENTER))                             //~v786I~
            {                                                      //~v786I~
				if (flag & UFHSF_ENTERONUPDATELINEONLY)            //~v786R~
            		nothingtodosw=1;                               //~v786I~
            }                                                      //~v786I~
            else                                                   //~v786I~
            {                                                      //~v786I~
				if (flag & UFHSF_UPDATELINEONLYLANG)               //~v786I~
            		nothingtodosw=1;                               //~v786I~
            }                                                      //~v786I~
        }                                                          //~v786I~
        else                                                       //~v786I~
            nothingtodosw=1;                                       //~v786I~
	}                                                              //~v786I~
    rc=syngetstartplh(0,Ppcw,Ppfh,&plh1,&plh2); 	//get update start/end plh
//  if ( rc || (Ppfh->UFHsynflag & UFHSF_VALID) )                  //~v786R~
    if ( rc || nothingtodosw)                                      //~v786R~
    {
//      if (!(Popt & SUO_ENTER))	//not auto req by enterky      //~v786R~
        if (!(Popt & SYNCPO_ENTER))	//not auto req by enterky      //~v786R~
            uerrmsg("No data update, use \"SYN ALL\" to force.",
                		"変更データ無し、\"SYN ALL\"で強制実施");
        return 4;
    }
//  if (rc=synexecsh(0,Ppcw,Ppfh),rc)	//call source-highlight    //~v786R~
    if (rc=synexecsh(Popt,Ppcw,Ppfh,&plh1,&plh2),rc)	//call source-highlight//~v786R~
    {                                                              //~v786I~
		if (rc==SWPRC_NOUPDLINE)   //no line found to write(all is deleted line)//~v786I~
			synsetvalid(Popt,Ppfh);	//set valid or valid updatelineonly//~v786I~
    	return rc;
    }                                                              //~v786I~
    if (rc=synupdateplh(Popt,Ppcw,Ppfh,plh1,plh2),rc)	//call source-highlight
    	return rc;
    return 0;
}//synupdate
//****************************************************************
//do from top line
//****************************************************************
int synall(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)
{
	int rc;
	PULINEH plh1,plh2;
//********************
	if (synchkfiletype(SCFTO_ERRMSG,Ppcw,Ppfh))
    	return 4;
//  Ppfh->UFHsynflag|=(UFHSF_ON);                                  //~v78vR~
    if (UGETQCTR(&Ppfh->UFHlineque)<3)
    {                                                              //~v78vI~
		Ppfh->UFHsynflag|=(UFHSF_ON);                              //~v78vI~
    	return 0;
    }                                                              //~v78vI~
    plh1=UGETQTOP(&Ppfh->UFHlineque);
    plh1=UGETQNEXT(plh1);
    plh2=UGETQEND(&Ppfh->UFHlineque);
    plh2=UGETQPREV(plh2);
//  if (rc=synexecsh(0,Ppcw,Ppfh),rc)	//call source-highlight    //~v780R~
//  if (rc=synexecsh(SYNCPO_ALL|SYNCPO_ALLALL,Ppcw,Ppfh,&plh1,&plh2),rc)	//call source-highlight//~v786R~//~vb30R~
    if (rc=synexecsh((int)(SYNCPO_ALL|SYNCPO_ALLALL),Ppcw,Ppfh,&plh1,&plh2),rc)	//call source-highlight//~vb30I~
    	return rc;
//  if (rc=synupdateplh(0,Ppcw,Ppfh,plh1,plh2),rc)	//call source-highlight//~v780R~
//  if (rc=synupdateplh(SYNCPO_ALL|SYNCPO_ALLALL,Ppcw,Ppfh,plh1,plh2),rc)	//call source-highlight//~v78oR~
//  if (rc=synupdateplh(Popt|SYNCPO_ALL|SYNCPO_ALLALL,Ppcw,Ppfh,plh1,plh2),rc)	//call source-highlight//~v78oI~//~vb30R~
    if (rc=synupdateplh(Popt|(int)(SYNCPO_ALL|SYNCPO_ALLALL),Ppcw,Ppfh,plh1,plh2),rc)	//call source-highlight//~vb30I~
    	return rc;
    Ppfh->UFHsynflag|=(UFHSF_ON);                                  //~v78vI~
    if (!(Popt & SYNCPO_OPEN))                                     //~v786I~
	    uerrmsg("SyntaxHL:done ALL",0);                            //~v786R~
    return 0;
}//synall
//****************************************************************
//spawn source-highlight
//rc:64 :no line to evaluate                                       //~v786I~
//****************************************************************
//int synexecsh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)             //~v780R~
int synexecsh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh1,PULINEH *Ppplh2)//~v786R~
{
	int rc;
    char *pfnmprefix;
    char fpathinp[_MAX_PATH];
//********************
	if (!(pfnmprefix=syngetwkfnm(0,Ppcw,Ppfh)))
    	return 4;
	if (synsetinpfnm(0,Ppcw,Ppfh,fpathinp))
    	return 4;
//  if (rc=synwriteplh(0,Ppcw,Ppfh,fpathinp),rc)                   //~v780R~
    if (rc=synwriteplh(Popt,Ppcw,Ppfh,fpathinp,Ppplh1,Ppplh2),rc)  //~v780R~
    	return rc;
	rc=synkicksh(0,Ppcw,Ppfh,pfnmprefix,fpathinp,Ppfh->UFHsyntype);
    unlink(fpathinp);
	return rc;
}//synexecsh
//****************************************************************
//write input to source-highlight
//ret:rc
//****************************************************************
//int synwriteplh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pfnminput)//~v780R~
int synwriteplh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pfnminput,PULINEH *Ppplh1,PULINEH *Ppplh2)//~v786R~
{
    FILE *fh;
    PULINEH plh;
//  PULINEH plh1,/*plh2,*/plhcs,plh1st=0,plhlast;                      //~v780R~//~vaa7R~
    PULINEH plh1,/*plh2,*/plhcs,plh1st=0,plhlast=0;                //~vaa7I~
    int wlineno;
    int updatesw,allsw=0;                                          //~v786R~
    int pfhtabskip;                                                //~v79yR~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile,opt;                                             //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//********************
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
    handle=Ppfh->UFHhandle;                                        //~va79I~
    opt=swutf8file*XESYNFWO_UTF8+swebcfile*XESYNFWO_EBC;           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (!(fh=fileopen(Pfnminput,"wb")))
    	return 4;
	wlineno=0;
    if (Popt & SYNCPO_ALLALL)                                      //~v786I~
    	allsw=1;                                                   //~v786I~
    else                                                           //~v786I~
  	if (Popt & SYNCPO_ENTER)	//by enterkey                      //~v786R~
  		if (Ppfh->UFHsynflag & UFHSF_ENTERONUPDATELINEONLY)	//updateline only dor enter key//~v786R~
        	allsw=0;                                               //~v786I~
        else                                                       //~v786I~
        	allsw=1;                                               //~v786I~
    else                                                           //~v786I~
  		if (Ppfh->UFHsynflag & UFHSF_UPDATELINEONLYLANG)	//updateline only dor enter key//~v786R~
        	allsw=0;                                               //~v786I~
        else                                                       //~v786I~
        	allsw=1;                                               //~v786I~
    pfhtabskip=Ppfh->UFHtabskip;                                   //~v79yR~
  if (allsw)                                                       //~v786R~
  {                                                                //~v786R~
    for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))
    {
        if (plh->ULHtype!=ULHTDATA)
//      	plh->ULHlinenow=wlineno;                               //~v786R~
        	plh->ULHsynlineno=0;                                   //~v786R~
        else
        {
            FILECHKDBCSTB(plh);
            FILECHKTABCHNG(plh,pfhtabskip);                        //~v79yR~
//          fwrite(plh->ULHdata,1,(UINT)(plh->ULHlen),fh);	//may contains tab//~v79JR~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//          xesyn_fwrite(opt,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,fh);	//may contains tab//~va50I~//~va79R~
            xesyn_fwrite(opt,handle,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,fh);	//may contains tab//~va79I~
    #else                                                          //~va50I~
            xesyn_fwrite(swutf8file,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,fh);	//may contains tab//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
            xesyn_fwrite(plh->ULHdata,plh->ULHlen,fh);	//may contains tab//~v79JR~
#endif                                                             //~va20I~
            if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))	//has no following
		        fwrite("\n",1,1,fh);	//write EOL
            if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))	//not follower
                wlineno++;
//      	plh->ULHlinenow=wlineno;                               //~v786R~
        	plh->ULHsynlineno=wlineno;                             //~v786R~
        }
    }
//  if (!wlineno)                                                  //~v780R~
//  	return 4;                                                  //~v780R~
  }                                                                //~v786R~
  else                                                             //~v786R~
  {                                                                //~v786R~
    plh1=*Ppplh1;                                                  //~v786R~
//  plh2=*Ppplh2;                                                  //~v786R~//~vaa7R~
    for (plh=plh1;plh;plh=UGETQNEXT(plh))                          //~v786R~
    {                                                              //~v786R~
        if (plh->ULHtype!=ULHTDATA)                                //~v786R~
            plh->ULHsynlineno=0;                                   //~v786R~
        else                                                       //~v786R~
        {                                                          //~v786R~
            if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))    //has no following//~v786R~
            {                                                      //~v786R~
                updatesw=0;                                        //~v786R~
                for (plhcs=plh;plh;plh=UGETQNEXT(plh))             //~v786R~
                {                                                  //~v786R~
                    if (plh->ULHtype!=ULHTDATA)                    //~v786R~
                        continue;                                  //~v786R~
                    FILECHKDBCSTB(plh);                            //~v786R~
		            FILECHKTABCHNG(plh,pfhtabskip);                //~v79yR~
                    if (!UCBITCHK(plh->ULHsynflag,ULHSF_VALID))    //~v786R~
                        updatesw=1;                                //~v786R~
                    if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))   //last//~v786R~
                        break;                                     //~v786R~
                }                                                  //~v786R~
                if (updatesw)                                      //~v786R~
                {                                                  //~v786R~
                    wlineno++;                                     //~v786R~
                    for (plh=plhcs;plh;plh=UGETQNEXT(plh))         //~v786R~
                    {                                              //~v786R~
                        if (plh->ULHtype!=ULHTDATA)                //~v786R~
                            continue;                              //~v786R~
                        if (!plh1st)                               //~v786R~
                            plh1st=plhcs;                          //~v786R~
                        plhlast=plhcs;                             //~v786R~
//                      fwrite(plh->ULHdata,1,(UINT)(plh->ULHlen),fh);  //may contains tab//~v79JR~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//                      xesyn_fwrite(opt,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,fh);  //may contains tab//~va50I~//~va79R~
                        xesyn_fwrite(opt,handle,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,fh);  //may contains tab//~va79I~
    #else                                                          //~va50I~
                        xesyn_fwrite(swutf8file,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,fh);  //may contains tab//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                        xesyn_fwrite(plh->ULHdata,plh->ULHlen,fh);  //may contains tab//~v79JR~
#endif                                                             //~va20I~
                        plh->ULHsynlineno=wlineno;                 //~v786R~
                        if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))   //last//~v786R~
                            break;                                 //~v786R~
                    }                                              //~v786R~
                    fwrite("\n",1,1,fh);    //write EOL            //~v786R~
                }                                                  //~v786R~
                else                                               //~v786R~
                {                                                  //~v786R~
                    for (plh=plhcs;plh;plh=UGETQNEXT(plh))         //~v786R~
                    {                                              //~v786R~
                        if (plh->ULHtype!=ULHTDATA)                //~v786R~
                            continue;                              //~v786R~
                        plh->ULHsynlineno=0;                       //~v786R~
                        if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))   //last//~v786R~
                            break;                                 //~v786R~
                    }                                              //~v786R~
                }                                                  //~v786R~
            }                                                      //~v786R~
            else                                                   //~v786R~
            {                                                      //~v786R~
                FILECHKDBCSTB(plh);                                //~v786R~
		        FILECHKTABCHNG(plh,pfhtabskip);                    //~v79yR~
                if (!UCBITCHK(plh->ULHsynflag,ULHSF_VALID))        //~v786R~
                {                                                  //~v786R~
                    wlineno++;                                     //~v786R~
                    if (!plh1st)                                   //~v786R~
                        plh1st=plh;                                //~v786R~
                    plhlast=plh;                                   //~v786R~
//                  fwrite(plh->ULHdata,1,(UINT)(plh->ULHlen),fh);  //may contains tab//~v79JR~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//                  xesyn_fwrite(opt,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,fh);  //may contains tab//~va50I~//~va79R~
                    xesyn_fwrite(opt,handle,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,fh);  //may contains tab//~va79I~
    #else                                                          //~va50I~
                    xesyn_fwrite(swutf8file,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,fh);  //may contains tab//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                    xesyn_fwrite(plh->ULHdata,plh->ULHlen,fh);  //may contains tab//~v79JR~
#endif                                                             //~va20I~
                    plh->ULHsynlineno=wlineno;                     //~v786R~
                    fwrite("\n",1,1,fh);    //write EOL            //~v786R~
                }                                                  //~v786R~
                else                                               //~v786R~
                    plh->ULHsynlineno=0;    //not written id       //~v786R~
            }                                                      //~v786R~
        }//dataline                                                //~v786R~
    }//for                                                         //~v786R~
    *Ppplh1=plh1st;                                                //~v786I~
    *Ppplh2=plhlast;                                               //~v786I~
  }//updateonly                                                    //~v786I~
    fclose(fh);
    if (!wlineno)                                                  //~v780I~
//  	return 4;                                                  //~v786R~
		return SWPRC_NOUPDLINE;   //no line found to write         //~v786I~
    return 0;
}//synwriteplh
//****************************************************************
// synspfupdate
// attrib dlcmd for syn
//*rc   :0
//****************************************************************
int syngetstartplh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh1,PULINEH *Ppplh2)
{
	PULINEH plh1,plh2;                                             //~v786R~
//*******************
    plh1=UGETQNEXT(UGETQTOP(&Ppfh->UFHlineque));
    plh2=UGETQPREV(UGETQEND(&Ppfh->UFHlineque));
#ifdef AAA	 //determin at write plh                               //~v786R~
    if (Ppfh->UFHsynflag & UFHSF_ALLFOLLOWING)
    {
        for (plh=plh1;plh;plh=UGETQNEXT(plh))
        {
            if (plh->ULHtype==ULHTDATA)                            //~v780R~
            {
                if (!UCBITCHK(plh->ULHsynflag,ULHSF_VALID)
                ||   UCBITCHK(plh->ULHsynflag,ULHSF_REQUIRED))
	                break;
            }
        }
        if (plh)
        	plh1=plh;
    }
    else
    if (Ppfh->UFHsynflag & UFHSF_ENTERONUPDATELINEONLY)            //~v786R~
    {
        for (plh=plh1,plh1st=0;plh;plh=UGETQNEXT(plh))
        {
            if (plh->ULHtype==ULHTDATA)                            //~v780R~
            {
                if (!UCBITCHK(plh->ULHsynflag,ULHSF_VALID))
                {
                	if (!plh1st)
                    	plh1st=plh;
	                plhlast=plh;
                }
            }
        }
        if (plh1st)
        {
        	plh1=plh1st;
            plh2=plhlast;
        }
    }
    if (!plh1)
    	return 4;
#endif                                                             //~v786R~
    *Ppplh1=plh1;
    *Ppplh2=plh2;
    return 0;
}//syngetstartplh
//****************************************************************
// synspfupdate
// attrib dlcmd for syn
//*rc   :0 or 4/8
//****************************************************************
int synupdateplh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2)
{
	PULINEH plh;
    int  cfhandle,rc=0,updatesw=0;
//*******************
	if (rc=synopencf(Popt,Ppcw,Ppfh,&cfhandle),rc)
    	return rc;
UTRACEP("xesyn.synupdateplh\n");                                            //~v780I~//~vb31R~
    for (plh=Pplh1;plh;plh=UGETQNEXT(plh))
    {
        if (plh->ULHtype!=ULHTDATA)
        	continue;
                                                                   //~v780I~
	  if (plh->ULHsynlineno)                                       //~v780R~
      {                                                            //~v780I~
		if (rc=syngetplhcolordata(Popt,Ppcw,Ppfh,plh,cfhandle),rc>1)
	    	break;
        updatesw=1;
      }                                                            //~v780I~
        rc=0;
    }
    if (rc)
    {
//  	Ppfh->UFHsynflag&=~(UFHSF_VALID);                          //~vb30R~
    	Ppfh->UFHsynflag&=~(ULONG)(UFHSF_VALID);                   //~vb30I~
    }
    else
    {
//  	Ppfh->UFHsynflag|=(UFHSF_VALID);                           //~v786R~
		synsetvalid(Popt,Ppfh);                                    //~v786R~
    }
    if (updatesw)
    {
    	Ppfh->UFHsynflag|=(UFHSF_HASCOLORDATA);
//      UCBITON(Ppcw->UCWflag,UCWFDRAW);    //full redraw
    }
    UPCTRREQ(Ppfh);	//start new upctr level
	rc+=synclosecf(Popt);
    return rc;
}//synupdateplh
//**************************************************************** //~v786I~
//synsetvalid                                                      //~v786I~
//  set vaid or validupdatedlineonly                               //~v786I~
//**************************************************************** //~v786I~
void synsetvalid(int Popt,PUFILEH Ppfh)                            //~v786I~
{                                                                  //~v786I~
	int flag;                                                      //~v786I~
//*****************	                                               //~v786I~
//  flag=Ppfh->UFHsynflag|(UFHSF_VALID);                           //~v786I~//~vb30R~
    flag=(int)(Ppfh->UFHsynflag|(UFHSF_VALID));                    //~vb30I~
    if (Popt & SYNCPO_ENTER)                                       //~v786I~
		if (flag & UFHSF_ENTERONUPDATELINEONLY)                    //~v786I~
        	flag|=(UFHSF_VALIDUPDATELINEONLY);                     //~v786I~
        else                                                       //~v786I~
        	flag&=~(UFHSF_VALIDUPDATELINEONLY);                    //~v786I~
    else	//cmd                                                  //~v786I~
		if (flag & UFHSF_UPDATELINEONLYLANG)	//eval upd only by cmd//~v786I~
        	flag|=(UFHSF_VALIDUPDATELINEONLY);                     //~v786I~
        else                                                       //~v786I~
        	flag&=~(UFHSF_VALIDUPDATELINEONLY);                    //~v786I~
//  Ppfh->UFHsynflag=flag;                                         //~v786I~//~vb30R~
    Ppfh->UFHsynflag=(ULONG)flag;                                  //~vb30I~
    return;                                                        //~v786I~
}//synsetvalid                                                     //~v786I~
//****************************************************************
//syngetcf
//  get color data
//   rc: 4,8
//****************************************************************
int syngetplhcolordata(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,int Phandle)
{
    LONG lineno;
//  int rc,ulhlen,opt=0,drawonsw=0,left,rlen,oldlen,newlen;        //~vaa7R~
    int rc,ulhlen,opt=0,drawonsw=0,left=0,rlen=0,oldlen=0,newlen;  //~vaa7I~
    UCHAR oldsc[MAXCOLUMN+MAXCOLUMN],*psc; //style+color           //~v780R~
    PULHCI puci;
    PUFILEC pfc;
//*****************************
UTRACEP("before draw synlineno=%d,draw=%x,valid=%x\n",Pplh->ULHsynlineno,UCBITCHK(Pplh->ULHflag,ULHFDRAW),UCBITCHK(Pplh->ULHsynflag,ULHSF_VALID));        //valid changed to invalid//~v780R~
UTRACED("xesyn.syngetplhcolordata ULHdata",Pplh->ULHdata,Pplh->ULHlen);//~vb31I~
    ulhlen=Pplh->ULHlen;
//  lineno=Pplh->ULHlinenow;                                       //~v780R~
    lineno=Pplh->ULHsynlineno;                                     //~v780R~
    if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT1))
    	opt|=SGCDO_SPLIT1;
    if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT2))
    	opt|=SGCDO_SPLIT2;
    if (!UCBITCHK(Ppcw->UCWflag,UCWFDRAW) && !UCBITCHK(Pplh->ULHflag,ULHFDRAW))//~v780R~
    {
    	if (!UCBITCHK(Pplh->ULHsynflag,ULHSF_VALID))
        	drawonsw=1;     //invalid may change to valid
        else          //valid
        {
            pfc=Ppcw->UCWpfc;
            left=pfc->UFCleft;
            rlen=Pplh->ULHlen-left;
            rlen=min(rlen,Ppcw->UCWwidth);
	        puci=Pplh->ULHci;
//          oldlen=(puci->ULHcidatalen-ULHCI_EOLDATASZ)/2;         //~vb30R~
            oldlen=(puci->ULHcidatalen-(int)ULHCI_EOLDATASZ)/2;    //~vb30I~
            oldlen-=left;
            oldlen=min(rlen,oldlen);
            if (oldlen>0)
            {
            	psc=puci->ULHcidata+left+left;                     //~v780R~
            	memcpy(oldsc,psc,(UINT)(oldlen+oldlen));	//save for compare//~v780I~
                drawonsw=2;	//to be chk changed after read
UTRACED("old sc",psc,oldlen*2);                                    //~v780I~
            }
        }
    }
//  rc=syngetcfdata(opt,Phandle,lineno,&Pplh->ULHci,ulhlen);       //~vb31R~
    rc=syngetcfdata(opt,Phandle,(int)lineno,&Pplh->ULHci,ulhlen);  //~vb31I~
    if (!rc)
    {
    	UCBITON(Pplh->ULHsynflag,ULHSF_VALID);
    	UCBITOFF(Pplh->ULHsynflag,ULHSF_REQUIRED);
	  if (Ppfh->UFHsynflag & (UFHSF_ON))	//not from syn off     //~v78vI~
      {                                                            //~v78vI~
        if (drawonsw==2)
        {
	        puci=Pplh->ULHci;
//          newlen=(puci->ULHcidatalen-ULHCI_EOLDATASZ)/2;         //~vb30R~
            newlen=(puci->ULHcidatalen-(int)ULHCI_EOLDATASZ)/2;    //~vb30I~
            newlen-=left;
            newlen=min(rlen,newlen);
            psc=puci->ULHcidata+left+left;                         //~v780I~
            if (newlen==oldlen
            &&	!memcmp(oldsc,psc,(UINT)(oldlen+oldlen)))          //~v780R~
                drawonsw=0;
UTRACED("new sc",psc,oldlen*2);                                    //~v780R~
        }
      }                                                            //~v78vI~
        if (drawonsw)                       //color/style changed
    		UCBITON(Pplh->ULHflag,ULHFDRAW);
    }
    else
    {
    	if (UCBITCHK(Pplh->ULHsynflag,ULHSF_VALID))
        {
    		UCBITOFF(Pplh->ULHsynflag,ULHSF_VALID);
    		UCBITON(Pplh->ULHflag,ULHFDRAW);        //valid changed to invalid
        }
    }
UTRACEP("after draw=%x\n",UCBITCHK(Pplh->ULHflag,ULHFDRAW));        //valid changed to invalid//~v780I~
    if (rc==-1)	//EOF
    {                                                              //~va7iI~
        uerrmsg("SyntaxHighligh external tool was intercepted(output reached to unpredictable EOF)",0);//~va7iI~
    	rc=8;
    }                                                              //~va7iI~
    return rc;
}//syngetplhcolordata
//****************************************************************
//xesynsetlineattr                                                 //~v780R~
//  get color data
//  (called for data line of the file SYNON and HASCOLORDATA (USDF3SYNTAX:on))//~v780I~
//   rc: 1: len=0, 4,8
//****************************************************************
int xesynsetlineattr(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,
					UCHAR *Ppsddata,UCHAR *Ppsddbcs,UCHAR *Ppsdcell,PUSCRD Ppsd,int Pscrwidth/*after lineno*/,int Plinenosz)//~v780R~
{
    PUFILEC pfc;
    int plhlen,left,sclen,ii,bgeol,bgupd,style;                    //~v780R~
    UCHAR  *plhsc,*plhsc0;
    int opt=0;                                                     //~v78oI~
#ifdef W32
	USHORT *pattr;
#else
	UCHAR  *pattr;
#endif
#ifdef WXEXXE
    UCHAR  *pstyle;
#endif
//*****************************
UTRACED("xesynsetlineattr ULHdata",Pplh->ULHdata,Pplh->ULHlen);      //~v780R~//~vb31R~
	pfc=Ppcw->UCWpfc;
    if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                         //~v78oI~
        opt|=SYNCPO_BROWSE;                                        //~v78oR~
    left=pfc->UFCleft;
    plhlen=Pplh->ULHlen;
    sclen=max(plhlen-left,0);
    sclen=min(sclen,Pscrwidth);
	plhsc0=Pplh->ULHci->ULHcidata+left+left;    //style and color
UTRACED("xesynsetlineattr plhsc0",plhsc0,sclen);                   //+vb31R~
#ifdef WXEXXE
//style
    plhsc=plhsc0;
    pstyle=Ppsd->USDstyle;
    memset(pstyle,SYNC_STYLE_NOSYNTAX,(UINT)Plinenosz);            //~v780R~
    pstyle+=Plinenosz;
//    if (Popt & SSLAO_VHEX||!(Pplh->ULHsynflag & ULHSF_VALID))   //vhex line or updated line//~v780R~
//        memset(pstyle,SYNC_STYLE_NORMAL,Pscrwidth);              //~v780R~
//    else                                                         //~v780R~
//    {                                                            //~v780R~
//        for (ii=0;ii<sclen;ii++,plhsc+=2)                        //~v780R~
//        {                                                        //~v780R~
//            style=*plhsc;                                        //~v780R~
//            *pstyle++=SYN_STYLE_MAP(style);                      //~v780R~
//        }                                                        //~v780R~
//        memset(pstyle,SYNC_STYLE_NORMAL,Pscrwidth-ii);           //~v780R~
//    }                                                            //~v780R~
#endif
//color
    plhsc=plhsc0;                                                  //~v780R~
//  bgeol=syngetbgeol(Popt);                                       //~v78oR~
    bgeol=syngetbgeol(Popt|opt);	//browseopt                    //~v78oI~
#ifdef W32
//	pattr=(USHORT*)(ULONG)Ppsdcell;                                //~vafkR~
	pattr=(USHORT*)(ULPTR)Ppsdcell;                                //~vafkI~
    if (Popt & SSLAO_VHEX||!(Pplh->ULHsynflag & ULHSF_VALID))	//vhex line or updated line
    {
		bgupd=syngetbgupd(Popt);
    	if (bgupd>=0)
    	{
        	for (ii=0;ii<sclen;ii++)
        	{
            	*pattr++=(USHORT)(SYN_PAL_FGCOLOR(*pattr &0x0f)|bgupd);
        	}
        }
        else
        {                                                          //~v78pI~
//          ii=sclen;                                              //~v78pR~
        	for (ii=0;ii<sclen;ii++)                               //~v78pI~
        	{                                                      //~v78pI~
            	*pattr++=(USHORT)(SYN_PAL_FGCOLOR(*pattr &0x0f));  //~v78pI~
        	}                                                      //~v78pI~
        }                                                          //~v78pI~
#ifdef WXEXXE                                                      //~v780I~
        memset(pstyle,SYNC_STYLE_NORMAL,Pscrwidth);                //~v780I~
#endif                                                             //~v780I~
    }
    else
    {
        for (ii=0;ii<sclen;ii++,plhsc+=2)
        {
//          *pattr++=(USHORT)syngetstylecolor(0,plhsc,&style);     //~v78oR~
            *pattr++=(USHORT)syngetstylecolor(opt,plhsc,&style);   //~v78oI~
#ifdef WXEXXE                                                      //~v780I~
//  		*pstyle++=style;                                       //~v780R~//~vabJR~
    		*pstyle++=(UCHAR)style;                                //~vabJI~
#endif                                                             //~v780I~
        }
#ifdef WXEXXE                                                      //~v780I~
	    memset(pstyle,SYNC_STYLE_NORMAL,Pscrwidth-sclen);          //~v780R~
#endif                                                             //~v780I~
    }
    if (bgeol>=0)	//config request
    {
        for (;ii<Pscrwidth;ii++)
        {
            *pattr++=(USHORT)bgeol;
        }
    }
UTRACED("synsetlineattr Ppsdcell",Ppsdcell,Pscrwidth);             //~vb31I~
#else     //LNX                                                    //~v780R~
	pattr=Ppsdcell+1;
    if (Popt & SSLAO_VHEX||!(Pplh->ULHsynflag & ULHSF_VALID))	//vhex line or updated line
    {
		bgupd=syngetbgupd(Popt);
    	if (bgupd>=0)
    	{
        	for (ii=0;ii<sclen;ii++)
        	{
            	*pattr=(UCHAR)(SYN_PAL_FGCOLOR((*pattr) & 0x0f)|bgupd);//~v780I~
	        	pattr+=2;   //skip data position of data+attr      //~v780R~
        	}
        }
        else
//           ii=sclen;                                             //~v78ER~
         	for (ii=0;ii<sclen;ii++)                               //~v78ER~
         	{                                                      //~v78ER~
             	*pattr=(UCHAR)(SYN_PAL_FGCOLOR(*pattr &0x0f));     //~v78ER~
	         	pattr+=2;   //skip data position of data+attr      //~v78ER~
         	}                                                      //~v78ER~
#ifdef WXEXXE                                                      //~v780I~
//      memset(pstyle,SYNC_STYLE_NORMAL,Pscrwidth);                //~v780I~//~vb30R~
        memset(pstyle,SYNC_STYLE_NORMAL,(size_t)Pscrwidth);        //~vb30I~
#endif                                                             //~v780I~
    }
    else
    {
        for (ii=0;ii<sclen;ii++,plhsc+=2)
        {
//          *pattr++=(UCHAR)syngetstylecolor(0,plhsc,&style);      //~v78oR~
            *pattr++=(UCHAR)syngetstylecolor(opt,plhsc,&style);    //~v78oI~
            pattr++;    //skip data position of data+attr
#ifdef WXEXXE                                                      //~v780I~
//  		*pstyle++=style;                                       //~v780R~//~vb30R~
    		*pstyle++=(UCHAR)style;                                //~vb30I~
#endif                                                             //~v780I~
        }
#ifdef WXEXXE                                                      //~v780I~
//      memset(pstyle,SYNC_STYLE_NORMAL,Pscrwidth-sclen);          //~v780R~//~vb30R~
        memset(pstyle,SYNC_STYLE_NORMAL,(size_t)(Pscrwidth-sclen));//~vb30I~
#endif                                                             //~v780I~
    }
    if (bgeol>=0)
    {
        for (;ii<Pscrwidth;ii++)
        {
            *pattr++=(UCHAR)bgeol;
	        pattr++;	//skip data position of data+attr
        }
    }
UTRACED("synsetlineattr Ppsdcell",Ppsdcell,Pscrwidth);              //~v780I~//~vb31R~
#endif //LNX                                                       //~v780R~
    return 0;
}//xesynsetlineattr
//****************************************************************
// synundoprep
// 	set invalid flag by line update
//****************************************************************
int xesynundoprep(int Popt,int Pundotype,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,void *Ppuh)
{
    int rc=0;
    PULINEH plh;
	PUUNDOH puh;
//*******************
    if (Pplh->ULHtype!=ULHTDATA)	//X-line isrt etc              //~v780I~
    	return 0;                                                  //~v780I~
	puh=(PUUNDOH)Ppuh;
    SYN_INVALIDATE_PFH(Ppfh);
	switch(Pundotype)
    {
    case UUHTISRT:	//plh is of inserted after UENQ
    	break;
    case UUHTDEL:   //before DEQ the plh
    	if (Ppfh->UFHsynflag & UFHSF_ALLFOLLOWING)
        {
        	for (plh=Pplh;plh=UGETQNEXT(plh),plh;)
            	if (plh->ULHtype==ULHTDATA)                        //~v780R~
                {
                	SYN_INVALIDATE_PLH_REQUIRED(plh);
                    break;
                }
        }
    	break;
    case UUHTCUTOFF:   //before split flag reset
        if (UCBITCHK(Pplh->ULHsynflag,ULHSF_VALID))
        {
        	UCBITON(puh->UUHflag2,UUHF2SYNVALID);
        	SYN_INVALIDATE_PLH(Pplh);
        }
    	break;
    default:      //IDCLEAR,REPRENUM,REPRENUMCLEAR,REP,CUTOFF,after data saved
		Pplh->ULHci=0;	//color infor move to undo buff,avoid dup free
        SYN_INVALIDATE_PLH(Pplh);
    }
    return rc;
}//xesynundoprep
//****************************************************************
// synundo
// 	set invalid flag by line update by UNDO
//****************************************************************
int xesynundo(int Popt,int Pundotype,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,void *Ppuh)
{
    int rc=0;
    PULINEH plh;
	PUUNDOH puh;
//*******************
	puh=(PUUNDOH)Ppuh;
    SYN_INVALIDATE_PFH(Ppfh);
	switch(Pundotype)
    {
    case UUHTISRT:	//plh is of inserted before delete
    	if (Ppfh->UFHsynflag & UFHSF_ALLFOLLOWING)
        {
        	for (plh=Pplh;plh=UGETQNEXT(plh),plh;)
            	if (plh->ULHtype==ULHTDATA)                        //~v780R~
                {
                	SYN_INVALIDATE_PLH_REQUIRED(plh);
                    break;
                }
        }
    	break;
    case UUHTDEL:   //plh after re-inserted
        SYN_INVALIDATE_PLH_REQUIRED(Pplh);
    	break;
    case UUHTCUTOFF:   //plh after split flag restored
        if (UCBITCHK(puh->UUHflag2,UUHF2SYNVALID))
        {
        	UCBITON(Pplh->ULHsynflag,ULHSF_VALID);
	        SYN_INVALIDATE_PLH_REQUIRED(Pplh);
        }
        else
	        SYN_INVALIDATE_PLH(Pplh);
    	break;
    default:       //IDCLEAR,REPRENUM,REPRENUMCLEAR,REP after undo
    	plh=puh->UUHplhsave;
    	plh->ULHci=0;		//avoid free(restored to plh)
        SYN_INVALIDATE_PLH_REQUIRED(Pplh);
    }
    return rc;
}//xesynundo
//****************************************************************
// synchkopen
// 	chk file type and initial open opt
//****************************************************************
int xesynchkopen(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)
{
    int rc=0,pathlen;                                              //~v780R~
    int opt;                                                       //~v78oI~
    char *pfnm;
    PUQUEE pqe;                                                    //~v780R~
    PSYNQE psqe;                                                   //~v780I~
    char fpath[_MAX_PATH];                                         //~v780I~
//*******************
	if (synchkfiletype(SCFTO_OPEN,Ppcw,Ppfh))
    	return 4;
    if (!(Gsyncfg.SYNCflag & SYNCF_OPEN))
    	return 1;
    opt=SYNCPO_OPEN;                                               //~v78oR~
    if (Popt & UFCFBROWSE)                                         //~v78oR~
    	opt|=SYNCPO_BROWSE;                                        //~v78oR~
    pfnm=Ppfh->UFHfilename;                                        //~v78rI~
    strcpy(fpath,pfnm);                                            //~v78rI~
    pathlen=PATHLEN(fpath);                                        //~v78rI~
    if (pathlen>0)                                                 //~v78rI~
        *(fpath+pathlen-1)=0;   //del last "\\"                    //~v78rI~
    if (!Ppfh->UFHsyntype[0])	//profile has no lang type         //~v78rI~
        if (!synqeproc(SYNQEPO_SCAN|SYNQEPO_LANGTYPE,&Gsyncfg.SYNCqhlangpathlist,fpath,&pqe))//~v78rI~
        {                                                          //~v78rI~
//          psqe=(PSYNQE)(ULONG)pqe;                               //~v78rI~//~vafkR~
            psqe=(PSYNQE)(ULPTR)pqe;                               //~vafkI~
            strcpy(Ppfh->UFHsyntype,psqe->SYNQEstr);               //~v78rI~
        }                                                          //~v78rI~
  if (!(Ppfh->UFHprofile & FPURO_SYNOFF))                          //~v78vI~
  {                                                                //~v78vI~
    if (Ppfh->UFHsynflag & UFHSF_ON)	//profile is set           //~v78rI~
    	rc=synall(opt,Ppcw,Ppfh);                                  //~v78rI~
    else                                                           //~v78rI~
    if (Gsyncfg.SYNCflag & SYNCF_OPENALL)
//  	rc=synall(0,Ppcw,Ppfh);                                    //~v786R~
//  	rc=synall(SYNCPO_OPEN,Ppcw,Ppfh);                          //~v78oR~
    	rc=synall(opt,Ppcw,Ppfh);                                  //~v78oI~
    else
    {
//        pfnm=Ppfh->UFHfilename;                                  //~v78rR~
//        strcpy(fpath,pfnm);                                      //~v78rR~
//        pathlen=PATHLEN(fpath);                                  //~v78rR~
//        if (pathlen>0)                                           //~v78rR~
//            *(fpath+pathlen-1)=0;   //del last "\\"              //~v78rR~
//        if (!synqeproc(SYNQEPO_SCAN|SYNQEPO_LANGTYPE,&Gsyncfg.SYNCqhlangpathlist,fpath,&pqe))//~v78rR~
//        {                                                        //~v78rR~
//            psqe=(PSYNQE)(ULONG)pqe;                             //~v78rR~
//            strcpy(Ppfh->UFHsyntype,psqe->SYNQEstr);             //~v78rR~
//        }                                                        //~v78rR~
    	pfnm=strrchr(pfnm,'.');
    	if (pfnm && !synqeproc(SYNQEPO_SCAN,&Gsyncfg.SYNCqhopenextlist,pfnm+1,0))//~v780R~
//  		rc=synall(0,Ppcw,Ppfh);                                //~v786R~
//  		rc=synall(SYNCPO_OPEN,Ppcw,Ppfh);                      //~v78oR~
    		rc=synall(opt,Ppcw,Ppfh);                              //~v78oI~
    }
  }//syn off by profile                                            //~v78vI~
  if (!rc)                                                         //~v786I~
  {                                                                //~v786I~
   if (!(Ppfh->UFHsynflag & UFHSF_ENTERON))	//profile set no ENTER all//~v78rI~
   {                                                               //~v78rI~
    if (Gsyncfg.SYNCflag & SYNCF_DEFAULT_UPDONLY)                  //~v786I~
		Ppfh->UFHsynflag|=UFHSF_UPDATELINEONLYLANG;                //~v786I~
    else                                                           //~v786I~
    if (pfnm && !synqeproc(SYNQEPO_SCAN,&Gsyncfg.SYNCqhupdonlyextlist,pfnm+1,0))//~v786R~
		Ppfh->UFHsynflag|=UFHSF_UPDATELINEONLYLANG;                //~v786I~
    if (
        ((ULONG)(UGETQCTR(&Ppfh->UFHlineque)-2)<(ULONG)Gsyncfg.SYNCenter)
//  &&  (Ppfh->UFHsynflag & (UFHSF_ON))                            //~v786R~
    )
//      Ppfh->UFHsynflag|=UFHSF_ENTERON;                           //~v786R~
        Ppfh->UFHsynflag|=UFHSF_ENTERONUPDATELINEONLY;             //~v786I~
   }                                                               //~v78rI~
  } //success                                                      //~v786R~
    return rc;
}//xesynchkopen
//****************************************************************
// synchkopen
// 	chk file type and initial open opt
//****************************************************************
int synchkfiletype(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)
{
	int rc=0;
//*******************
    if (UCBITCHK(Ppfh->UFHflag13,UFHF13CB2))                       //~vaj7I~
        rc=4;                                                      //~vaj7I~
    else                                                           //~vaj7I~
	if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))  //bynary file
        rc=4;
    else
    if (UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))  //hex display
        rc=4;
    else
    if (Ppfh->UFHtype)	//PANMO,clipboard,KFI etc special file
        rc=4;
//  if (rc & Popt & SCFTO_ERRMSG)                                  //~vaj7R~
    if (rc && (Popt & SCFTO_ERRMSG))                               //~vaj7I~
    	uerrmsg("Invalid file type for SyntaxHL",
        		"このファイル/画面ではSyntaxHLは使用できません");
    return rc;
}//synchkfiletype
//****************************************************************
// xesynexecenter
// 	re-evaluate by enter key
//rc: 0:not done,1:done
//****************************************************************
int xesynexecenter(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)
{
//*******************
  if ((Ppfh->UFHsynflag & (UFHSF_ENTERONUPDATELINEONLY|UFHSF_ON))!=(UFHSF_ENTERONUPDATELINEONLY|UFHSF_ON))	//no auto//~v786R~
	if ((Ppfh->UFHsynflag & (UFHSF_ENTERON|UFHSF_ON))!=(UFHSF_ENTERON|UFHSF_ON))	//no auto
        return 0;
	if ((Ppfh->UFHsynflag & UFHSF_VALID))	//no update
        return 0;
//  if (synupdate(SUO_ENTER,Ppcw,Ppfh))                            //~v780R~
    if (synupdate(SYNCPO_ENTER,Ppcw,Ppfh))                         //~v780I~
    	return 0;
    return 1;
}//xesynexecenter
//**************************************************************** //~v78oI~
// xesyngetbgreverse                                               //~v78oI~
// get reverse color                                               //~v78oI~
//**************************************************************** //~v78oI~
int xesyngetbgreverse(int Popt)                                    //~v78oI~
{                                                                  //~v78oI~
	int bg;                                                        //~v78oI~
//*******************                                              //~v78oI~
	if (Popt) 	//edit                                             //~v78oI~
    	bg=Gsyncfg.SYNCbgrevedit;                                  //~v78oI~
    else                                                           //~v78oI~
    	bg=Gsyncfg.SYNCbgrevbrowse;                                //~v78oI~
    return (bg<<4); //fg=0                                         //~v78oR~
}//xesyngetbgreverse                                               //~v78oI~
#ifdef WXEXXE
//****************************************************************
// xesynsetgblstyletbl
// 	set style table for whole screen
//****************************************************************
int xesynsetgblstyletbl(int Popt,PUCLIENTWE Ppcw,void *Ppsd,int Pinactsw,int Prow,int Pvsplitinact1stsw)
{
	PUSCRD psd;
	UCHAR *ptbl;
	int len,pos,row;
//*******************
	psd=(PUSCRD)Ppsd;
	row=Ppcw->UCWorgy+Prow;
	ptbl=Gsynstyletbl+Gscrbuffwidth*row;
    len=Ppcw->UCWwidth;
    pos=Ppcw->UCWorgx;
UTRACEP("setgblstyletbl entry  row=(%d,%d),col=%d synflag=%x\n",Prow,row,pos,psd->USDflag3);//~v780I~
    if (UCBITCHK(psd->USDflag3,USDF3SYNTAX))    //set syntax
    {
UTRACED("setgblstyletbl",psd->USDstyle,len);                       //~v780I~
        memcpy(ptbl+pos,psd->USDstyle,(UINT)len);
    	UCBITOFF(psd->USDflag3,USDF3SYNTAX);	//for reuse by pan //~v780R~
	    if (Pvsplitinact1stsw)  //pcw is left of vsplit and inactive//~v780I~
    		*(ptbl+len-1)=SYNC_STYLE_NORMAL;                       //~v780R~
    }
    else
#ifdef BBB                                                         //~v780I~
        memset(ptbl+pos,SYNC_STYLE_NORMAL,(UINT)len);              //~v780R~
#else                                                              //~v780I~
        memset(ptbl+pos,SYNC_STYLE_NOSYNTAX,(UINT)len);            //~v780R~
#endif                                                             //~v780I~
UTRACEP("setgblstyletbl exit synflag=%x\n",psd->USDflag3);         //~v780R~
	return 0;
}//xesynsetgblstyletbl
#endif //WXEXXE
//**************************************************************** //~v79JR~
// xesyn_fwrite                                                    //~v79JR~
// 	replace EOL by space to keep line length                       //~v79JR~
//**************************************************************** //~v79JR~
#ifdef UTF8UCS2                                                    //~va20I~
//int xesyn_fwrite(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,FILE *Pfh)//~va20R~//~va79R~
int xesyn_fwrite(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,FILE *Pfh)//~va79I~
#else                                                              //~va20I~
int xesyn_fwrite(UCHAR *Pdata,int Plen,FILE *Pfh)                  //~v79JR~
#endif                                                             //~va20I~
{                                                                  //~v79JR~
	int len,rlen;                                                  //~v79JR~
    UCHAR *pc,*pcn;                                                //~v79JR~
#ifdef UTF8UCS2                                                    //~va20I~
    UCHAR *plc;                                                    //~va20R~
#endif                                                             //~va20I~
	UCHAR *pcn2;                                                   //~vagnI~
    int swnull;                                                    //~vagnI~
//***********************                                          //~v79JR~
#ifdef UTF8UCS2	                                                   //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	if (Popt & XESYNFWO_EBC)	//ebcfile                          //~va50I~
    {                                                              //~va50I~
//  	if (!xeebc_b2syn(0,Pdata,Pdbcs,Plen,&plc))	//cv to syntax chk data fmt keeping column width)//~va50I~//~va79R~
    	if (!xeebc_b2syn(0,Phandle,Pdata,Pdbcs,Plen,&plc))	//cv to syntax chk data fmt keeping column width)//~va79R~
        	Pdata=plc;                                             //~va50I~
    }                                                              //~va50I~
    else                                                           //~va50I~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
	if (Popt)	//utf8 file                                        //~va20R~
    {                                                              //~va20I~
    	if (!xeutf_dd2syn(0,Pdata,Pdbcs,Plen,&plc))	//cv to syntax chk data fmt keeping column width)//~va20R~
        	Pdata=plc;                                             //~va20R~
    }                                                              //~va20I~
#endif                                                             //~va20I~
	for (pc=Pdata,rlen=Plen;rlen>0;)                               //~v79JR~
    {                                                              //~v79JR~
//  	pcn2=memchr(pc,0x00,rlen);                                 //~vagnI~//~vb30R~
    	pcn2=memchr(pc,0x00,(size_t)rlen);                         //~vb30I~
//  	pcn=memchr(pc,'\n',rlen);                                  //~v79JR~//~vb30R~
    	pcn=memchr(pc,'\n',(size_t)rlen);                          //~vb30I~
        if (pcn2 && (!pcn || pcn2<pcn))                            //~vagnR~
        {                                                          //~vagnI~
        	swnull=1;                                              //~vagnI~
        	pcn=pcn2;                                              //~vagnI~
        }                                                          //~vagnI~
        else                                                       //~vagnI~
        	swnull=0;                                              //~vagnI~
        if (pcn)                                                   //~v79JR~
//        	len=(int)((ULONG)pcn-(ULONG)pc);                       //~v79JR~//~vafkR~
        	len=(int)((ULPTR)pcn-(ULPTR)pc);                       //~vafkI~
        else                                                       //~v79JR~
        	len=rlen;                                              //~v79JR~
		fwrite(pc,1,(UINT)len,Pfh);                                //~v79JR~
        if (!pcn)                                                  //~v79JR~
        	break;                                                 //~v79JR~
      if (swnull)                                                  //~vagnI~
		fwrite("\x01",1,1,Pfh);                                    //~vagnI~
      else                                                         //~vagnI~
		fwrite(" ",1,1,Pfh);                                       //~v79JR~
        rlen-=len+1;                                               //~v79JR~
        pc=pcn+1;                                                  //~v79JR~
    }                                                              //~v79JR~
    return 0;                                                      //~v79JR~
}//xesyn_fwrite                                                    //~v79JR~
#endif //SYNSUPP
