//*CID://+va8wR~:                             update#= 1161;       //~va8wR~
//*************************************************************
//*xefcmd43.c*                                                     //~v74VR~//~va8kR~
//**file cmd:JOIN,split from fcmd42.c                        //~v74VR~//~va8kR~
//*************************************************************
//va8w:101209 SPLIT/TFLOW:delete so/si when join dbcs string       //~va8wI~
//va8k:101013 SPLit cmd;dbcs consideration for split ALL/OVER without SBCS option.(split to fcmd43)//~va8kI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <uerr.h>
#include <udbcschk.h>                                              //~va8kR~
#include <uparse.h>                                                //~va8kI~
#include <ufile.h>
#include <ualloc.h>
#include <uedit.h>
#include <ustring.h>                                               //~v45xI~
#include <utf22.h>                                                 //~va20I~
#include <ucvebc.h>                                                //~va50I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile12.h"        //filerenum                           //~v76aI~
#include "xefile22.h"        //filesetcsr                          //~va8kI~
#include "xefile6.h"		//tab
#include "xefcmd2.h"		                                       //~v47iR~//~va8kI~
#include "xefcmd23.h"		//bnds                                 //~v74WI~//~va8kI~
#include "xefcmd3.h"                                               //~v165I~//~va8kI~
#include "xefcmd4.h"                                               //~va8kI~
#define  GBL_FC43          //external symbol:Gswebcfile_fc43       //~va8kI~
#include "xefcmd43.h"                                              //~va8kR~
#include "xeerr.h"                                                 //~va8kI~
#include "xeebc.h"                                                 //~va50I~
#include "xelcmd.h"                                                //~va8kI~
#include "xelcmd2.h"                                               //~va8kI~
#include "xelcmd4.h"                                               //~va8kI~
#include "xeundo.h"                                                //~va8kI~
#include "xesub.h"                                                 //~v11NI~
#include "xesub2.h"                                                //~va8kI~
#include "xefsub.h"                                                //~v47iI~
#include "xechar12.h"                                              //~v74EI~
#include "xeutf2.h"                                                //~va20I~
//**************************************************************** //~va8kI~
#define Sswebcfile Gswebcfile_fc43                                 //~va8kI~
#define Sswutf8file Gswutf8file_fc43                               //~va8kI~
#define Schspace  Gchspace_fc43                                    //~va8kI~
#define Sotheropt  Gotheropt_fc43                                  //~va8wI~
#define Sopt2 Gopt2_fc43                                           //~va8wI~
//**************************************************************** //~va8kI~
int fcmdjoinnx(PUCLIENTWE Ppcw,UFILEH *Ppfh,PULINEH Pplh1,PULINEH Pplh2,int Popt);//~v47iI~//~va8kM~
int fcmdjoinx(PUCLIENTWE Ppcw,UFILEH *Ppfh,PULINEH Pplh1,PULINEH Pplh2,int Popt);//~v47iI~//~va8kM~
int fcmdsplitsplitbin(PUCLIENTWE Ppcw,PULINEH *Ppplh,int Pwidth,   //~v60sI~
					UCHAR *Pcontwk,int Popt);                      //~v60sM~
int fcmdsplitjoinbin(PUCLIENTWE Ppcw,PULINEH *Ppplh,PULINEH Pplh2,int Pwidth,//~v60sI~
					UCHAR *Pcontwk,int Popt);                      //~v60sI~
//**************************************************************** //~v75fI~
//**************************************************************** //~v45xI~
// fcmdsplitcut                                                    //~v45xI~
//*cuttail by delm(default space)                                  //~v45xI~
//*parm2 :pcw                                                      //~v45xI~
//*parm3 :pfh                                                      //~v45xI~
//*parm5 :start plh                                                //~v45xI~
//*parm6 :end plh                                                  //~v45xI~
//*parm7 :width parm value                                         //~v45xI~
//*return:rc                                                       //~v45xI~
//**************************************************************** //~v45xI~
//int fcmdsplitcut(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2,char *Ppdelmstr)//~v53NR~
//int fcmdsplitcut(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2,char *Ppdelmstr,int Pwidth)//~v74SR~
int fcmdsplitcut(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2,char *Ppdelmstr,int Pwidth)//~v74SI~
{                                                                  //~v45xI~
    PULINEH plh,plhn=0;                                            //~v45xI~
    char *pdata;                                                   //~v45xI~
    int  donectr=0,ulhlen,cutlen;                                  //~v45xI~
    int rc;                                                        //~v53NI~
    int bndsoffs1,bndsoffs2,cutoffs;                               //~v74WR~
    int contdelsw;                                                 //~v761I~
#ifdef UTF8UCS2                                                    //~va20I~
    char *pdbcs;                                                   //~va20I~
#endif                                                             //~va20I~
    int optdbcssplit,optobdbcs;                                    //~va8jR~
//*********************************                                //~v45xI~
	if (Popt & FCSPL_MARGIN)                                       //~v74WI~
		fcmdgetbnds(0,Ppfh,&bndsoffs1,&bndsoffs2);                 //~v74WR~
    for (plh=Pplh1;plh && plh!=Pplh2;plh=plhn)                     //~v45xI~
    {                                                              //~v45xI~
	    plhn=UGETQNEXT(plh);	//for consideration plh delete     //~v45xI~
        if (plh->ULHtype!=ULHTDATA)                                //~v45xI~
        	continue;                                              //~v45xI~
        if (!plh->ULHdbcs)  //not once displayed                   //~v53NR~
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand tab for width and tab is space//~v53NR~
                return rc;                                         //~v53NR~
    	if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))	//has next     //~v45xI~
        	continue;                                              //~v45xI~
        pdata=plh->ULHdata;                                        //~v45xI~
#ifdef UTF8UCS2                                                    //~va20I~
        pdbcs=plh->ULHdbcs;                                        //~va20I~
#endif                                                             //~va20I~
        ulhlen=plh->ULHlen;                                        //~v45xI~
        contdelsw=0;                                               //~v761I~
	  if ((Popt & FCSPL_MARGIN)                                    //~v74WI~
      &&  (bndsoffs2 && bndsoffs2<ulhlen))	//right margin data exist//~v74WR~
      {                                                            //~v74WI~
		if (Ppdelmstr)                                             //~v74WI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//* Pdelmstr is already translated to codepage of the file         //~va79I~
            cutlen=(int)UCVEBCUTF_umemrspn(Sswebcfile,Sswutf8file,pdata,pdbcs,Ppdelmstr,bndsoffs2);//~va50I~
	#else                                                          //~va50I~
            cutlen=(int)UTF_umemrspn(Sswutf8file,pdata,pdbcs,Ppdelmstr,bndsoffs2);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
            cutlen=(int)umemrspn(pdata,Ppdelmstr,(UINT)bndsoffs2); //~v74WI~
#endif                                                             //~va20I~
        else                                                       //~v74WI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
            cutlen=(int)UCVEBCUTF_umemrspnc_space(Sswebcfile,Sswutf8file,pdata,pdbcs,bndsoffs2);//~va50I~
	#else                                                          //~va50I~
            cutlen=(int)UTF_umemrspnc(Sswutf8file,pdata,pdbcs,' ',bndsoffs2);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
            cutlen=(int)umemrspnc(pdata,' ',(UINT)bndsoffs2);      //~v74WI~
#endif                                                             //~va20I~
        cutoffs=bndsoffs2-cutlen;                                  //~v74WI~
        if (cutoffs<bndsoffs1)                                     //~v74WI~
        	cutoffs=bndsoffs1;                                     //~v74WI~
        if (Pwidth)                                                //~v74WI~
        {                                                          //~v74WI~
        	if (Pwidth<cutoffs)                                    //~v74WI~
            {                                                      //~v74WI~
            	cutlen=bndsoffs2-Pwidth;                           //~v74WI~
		        cutoffs=Pwidth;                                    //~v74WI~
            }                                                      //~v74WI~
        }                                                          //~v74WI~
        if (cutlen)                                                //~v74WI~
//*confirmed also dbcs                                             //~va20I~
#ifdef UTF8EBCD   //raw ebcdic file support                        //~va50R~
            if ((int)umemspnc(pdata+cutoffs,(char)Schspace,(UINT)cutlen)==cutlen//~va50R~
#else                                                              //~va50R~
            if ((int)umemspnc(pdata+cutoffs,' ',(UINT)cutlen)==cutlen    //~v74WR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50R~
            &&  (int)umemspnc(plh->ULHdbcs+cutoffs,0,(UINT)cutlen)==cutlen)	//not tab//~v74WR~
                cutlen=0;   //avoid plh update                     //~v74WI~
      }                                                            //~v74WI~
      else                                                         //~v74WI~
      {                                                            //~v74WI~
		if (Ppdelmstr)                                             //~v45xI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//* Pdelmstr is already translated to codepage of the file         //~va79I~
            cutlen=(int)UCVEBCUTF_umemrspn(Sswebcfile,Sswutf8file,pdata,pdbcs,Ppdelmstr,ulhlen);//~va50I~
    #else                                                          //~va50I~
            cutlen=(int)UTF_umemrspn(Sswutf8file,pdata,pdbcs,Ppdelmstr,ulhlen);//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
            cutlen=(int)umemrspn(pdata,Ppdelmstr,(UINT)ulhlen);    //~v47iR~
#endif                                                             //~va20I~
        else                                                       //~v45xI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
            cutlen=(int)UCVEBCUTF_umemrspnc_space(Sswebcfile,Sswutf8file,pdata,pdbcs,ulhlen);//~va50I~
    #else                                                          //~va50I~
            cutlen=(int)UTF_umemrspnc(Sswutf8file,pdata,pdbcs,' ',ulhlen);//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
            cutlen=(int)umemrspnc(pdata,' ',(UINT)ulhlen);         //~v47iR~
#endif                                                             //~va20I~
        if (Pwidth)                                                //~v53NI~
        {                                                          //~v76ER~
        	if (Pwidth<ulhlen-cutlen)                              //~v53NI~
            	cutlen=ulhlen-Pwidth;                              //~v53NI~
        }                                                          //~v76ER~
        cutoffs=-1;                                                //~v74WI~
        if (cutlen==ulhlen)                                        //~v761I~
    		if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))	//last line//~v761I~
	            contdelsw=1;                                       //~v761I~
      }                                                            //~v74WI~
        if (!cutlen)                                               //~v45xI~
        	continue;                                              //~v45xI~
     if (contdelsw)   //last of cont line all cleared              //~v761I~
     {                                                             //~v761I~
	    plhn=UGETQPREV(plh);	//try prev of cont line            //~v761I~
        if (rc=lcmddel(Ppcw,plh,plh,1,0,1),rc)//1 line,no csr set,not from lcmd main//~v761I~
            return rc;                                             //~v761I~
     }                                                             //~v761I~
     else                                                          //~v761I~
     {                                                             //~v761I~
//      if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process//~v761R~
//*ebc setdbcstbl later                                            //~va50I~
        if (undoupdate(Ppcw,plh,UUHTREP|UNDO_FORCE_PREP)==UALLOC_FAILED)    //force prepare undo,it may be save by UUHTCUTOFF//~v761R~
            return UALLOC_FAILED;                                  //~v45xI~
      if (cutoffs>=0)                                              //~v74WI~
      {                                                            //~v74WI~
        if (!(Popt & FCSPL_SBCS))                                  //~v74WM~
        {                                                          //~va8jI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5qI~
		//  setobtabdbcs(Sswebcfile,0,pdata,plh->ULHdbcs,plh->ULHlen,cutoffs,cutlen);//~va5qI~//~va8jR~
            optobdbcs=Sswebcfile|SOTDO_NOSBCSIFEBC;   //no SBCS option for EBC file//~va8jI~
		    setobtabdbcs(optobdbcs,0/*plh*/,pdata,plh->ULHdbcs,plh->ULHlen,cutoffs,cutlen);//~va8jI~
#else                                                              //~va5qI~
			setobtabdbcs(pdata,plh->ULHdbcs,plh->ULHlen,cutoffs,cutlen);//~v74WM~
#endif //UTF8EBCD raw ebcdic file support                          //~va5qI~
        }                                                          //~va8jI~
        else                                                       //~v74WI~
    		setobtabclear(0,pdata,plh->ULHdbcs,plh->ULHlen,cutoffs,cutlen);   //clear outboutd tab//~v74WI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        memset(pdata+cutoffs,Schspace,(UINT)cutlen);               //~va50I~
#else                                                              //~va50R~
        memset(pdata+cutoffs,' ',(UINT)cutlen);                          //~v74WI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        memset(plh->ULHdbcs+cutoffs,0,(UINT)cutlen);                     //~v74WI~
      }                                                            //~v74WI~
      else                                                         //~v74WI~
      {                                                            //~v74WI~
        plh->ULHlen=ulhlen-cutlen;                                 //~v45xI~
        if (!(Popt & FCSPL_SBCS))                                  //~v74SI~
        {                                                          //~va8kI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//          xesub_setdbcssplit(Sswebcfile,0/*plh*/,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,' ');//~va5qI~//~va8jR~
            optdbcssplit=Sswebcfile|XESUBSDSO_NOSBCSIFEBC;   //no SBCS option for EBC file//~va8jI~
            xesub_setdbcssplit(optdbcssplit,0/*plh*/,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,' ');//~va8jI~
#else                                                              //~va5qI~
            setdbcssplit(plh->ULHdata,plh->ULHdbcs,plh->ULHlen,' ');//~v74SR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5qM~
        }                                                          //~va8kI~
      }                                                            //~v74WI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  		if (Sswebcfile)                                            //~va50I~
  		{                                                          //~va50I~
			xeebc_setdbcstblplh(0,Ppfh,plh,0/*ULHlen*/);           //~va50I~
  		}                                                          //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
     }//not cont line cleared                                      //~v761I~
            donectr++;                                             //~v45xI~
    }//plh loop                                                    //~v45xI~
    uerrmsg("%d line(s) cutted",                                   //~v45xI~
            "%d 行を短縮｡",                                        //~v45xI~
                donectr);                                          //~v45xI~
    return 0;                                                      //~v45xI~
}//filesplitcut                                                    //~v74SR~
//**************************************************************** //~v45xR~
// fcmdcutoff                                                      //~v45xR~
//*split continued line                                            //~v45xR~
//*parm1 :pcw                                                      //~v45xR~
//*parm2 :pfh                                                      //~v45xR~
//*parm3 :range plh1                                               //~v45xI~
//*parm4 :range plh2                                               //~v45xI~
//*return:rc                                                       //~v45xR~
//**************************************************************** //~v45xR~
int fcmdcutoff(PUCLIENTWE Ppcw,UFILEH *Ppfh,PULINEH Pplh1,PULINEH Pplh2)//~v45xR~
{                                                                  //~v45xR~
    PULINEH plh1st=0,plh;                                          //~v45xR~
    int donectr=0,cutctr=0;                                        //~v45xR~
    int   rc;                                                      //~v45xR~
//*********************************                                //~v45xR~
    for (plh=Pplh1;plh && plh!=Pplh2;plh=UGETQNEXT(plh))           //~v45xR~
    {                                                              //~v45xR~
        if (!UCBITCHK(plh->ULHflag2,(ULHF2SPLIT1|ULHF2SPLIT2)))    //~v45xR~
        	continue;                                              //~v45xI~
        if (!plh1st)                                               //~v45xR~
            plh1st=plh;     //1st changed                          //~v45xR~
        if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))                   //~v45xR~
            cutctr++;                                              //~v45xR~
        donectr++;                                                 //~v45xR~
//*undoprep cutoff,set contflag only                               //~va50I~
        rc=undoupdate(Ppcw,plh,UUHTCUTOFF);//prepare and flag clear//~v45xR~
        if (rc)                                                    //~v45xR~
            return rc;                                             //~v45xR~
        UCBITOFF(plh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2);           //~v45xI~
    }                                                              //~v45xR~
    if (plh1st)                                                    //~v45xR~
    {                                                              //~v45xR~
        UPCTRREQ(Ppfh);         //write at save                    //~v45xR~
        undocsrmove(Ppcw,plh1st);                                  //~v45xR~
    }                                                              //~v45xR~
    if (donectr)                                                   //~v45xI~
        uerrmsg("%d line(s) cutted then added %d line",            //~v45xR~
                "分割行は %d行, %d 行追加｡",                       //~v45xR~
                    donectr-cutctr,cutctr);                        //~v45xR~
    else                                                           //~v45xI~
        uerrmsg("No split line exist",                             //~v45xI~
                "分割行は有りません｡");                            //~v45xI~
    return 0;                                                      //~v45xR~
}//fcmdcutoff                                                      //~v45xR~
//**************************************************************** //~v60sI~
// fcmdsplitbin                                                    //~v60sI~
//*split bin file(change display width)                            //~v60sI~
//*parm1 :option all or cont or exp only                           //~v60sI~
//*parm2 :pcw                                                      //~v60sI~
//*parm3 :pfh                                                      //~v60sI~
//*parm4 :del char tbl                                             //~v60sI~
//*parm5 :start plh                                                //~v60sI~
//*parm6 :end plh                                                  //~v60sI~
//*parm7 :width parm value                                         //~v60sI~
//*return:rc                                                       //~v60sI~
//**************************************************************** //~v60sI~
int fcmdsplitbin(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,char *Ppdelmstr,//~v60sI~
						PULINEH Pplh1,PULINEH Pplh2,int Pwidth)    //~v60sI~
{                                                                  //~v60sI~
    PULINEH plh1st=0,plh,plhn=0,plh2;                              //~v60sI~
    int   splittype,rc=0,width,widthold,ulhlen,swallline;          //~v60sR~
    UCHAR *pcontwk;                                                //~v60sI~
//*********************************                                //~v60sI~
	if (Ppdelmstr)                                                 //~v60sI~
    {                                                              //~v60sI~
    	uerrmsg("delimiter is not supported for binary file",      //~v60sI~
        	    "分離文字はバイナリーファイルでは使用できません"); //~v60sI~
        return 4;                                                  //~v60sI~
    }                                                              //~v60sI~
	splittype=Popt & FCSPL_TYPEMASK;                               //~v60sI~
    if (splittype!=1)	//ALL                                      //~v60sI~
    {                                                              //~v60sI~
    	uerrmsg("only support \"ALL\" for binary file",            //~v60sI~
        	    "バイナリーファイルは\"ALL\"のみ使用できます");    //~v60sR~
        return 4;                                                  //~v60sI~
    }                                                              //~v60sI~
    if (Pplh1==UGETQTOP(&Ppfh->UFHlineque)                         //~v60sI~
    &&  Pplh2==UGETQEND(&Ppfh->UFHlineque))                        //~v60sR~
    	swallline=1;                                               //~v60sI~
    else                                                           //~v60sI~
    	swallline=0;                                               //~v60sI~
	widthold=Ppfh->UFHwidth;                                       //~v60sI~
	if (Pwidth)                                                    //~v60sI~
    {                                                              //~v60sI~
	    if (UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))                     //~v60sI~
        {                                                          //~v60sI~
        	if (Pwidth>MAX_HEXBIN_WIDTH)                           //~v60sI~
            {                                                      //~v60sI~
                uerrmsg("Hex mode max width is %d",                //~v60sI~
                        "ヘキサ\x95\\示モードの最大幅は %d。",     //~v60tR~
                        MAX_HEXBIN_WIDTH);                         //~v60sR~
                return 4;                                          //~v60sI~
            }                                                      //~v60sI~
        }                                                          //~v60sI~
    }                                                              //~v60sI~
    else                                                           //~v60sI~
    {                                                              //~v60sI~
        uerrmsg("width parm is missing",                           //~v60sI~
                "width パラメータを指定してください。");           //~v60sI~
        return 4;                                                  //~v60sI~
    }                                                              //~v60sI~
	width=Pwidth;                                                  //~v60sR~
    if (widthold)                                                  //~v60sI~
    {                                                              //~v60sI~
//  	Ppfh->UFHwidth=(USHORT)(max(width,widthold));              //~v617R~
        if (swallline)                                             //~v60sI~
        {   //no label range specified                             //~v617I~
//*bin file,no dbcs tbl                                            //~va50I~
			if (undoprep(Ppcw,Pplh1,UUHTWIDTH)==UALLOC_FAILED)     //~v617I~
    			return UALLOC_FAILED;                              //~v617I~
	        if (UCBITCHK(Ppfh->UFHflag4,UFHF4WIDTH)	//width parm specified at open//~v617I~
    	    &&  Ppfh->UFHwidth==Ppfh->UFHmergin)	//-P option specified//~v617I~
				Ppfh->UFHmergin=(USHORT)width; //bin file mergin   //~v617I~
        	UCBITON(Ppfh->UFHflag4,UFHF4WIDTH);	//restored by "xe *"//~v60sI~
	    	Ppfh->UFHwidth=(USHORT)width;                          //~v617I~
        }                                                          //~v617I~
    }                                                              //~v60sI~
//  pcontwk=malloc((UINT)((width+1)<<1));	//data and dbcs,and read next 1 byte//~v76ER~
    pcontwk=umalloc((UINT)((width+1)<<1));	//data and dbcs,and read next 1 byte//~v76ER~
    for (plh=Pplh1;plh && plh!=Pplh2;plh=plhn)                     //~v60sI~
    {                                                              //~v60sI~
	    plhn=UGETQNEXT(plh);	//for consideration plh delete     //~v60sI~
        if (plh->ULHtype!=ULHTDATA)                                //~v60sI~
        	continue;                                              //~v60sI~
        if (!plh->ULHdbcs)  //not once displayed                   //~v60sI~
        {                                                          //~v60sI~
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v60sI~
                break;                                             //~v60sI~
            else                                                   //~v60sI~
                rc=0;   //ignore TAB found rc                      //~v60sI~
        }//dbcs                                                    //~v60sI~
	    ulhlen=plh->ULHlen;                                        //~v60sI~
        plh2=plh;		//for 1st updated                          //~v60sI~
        if (ulhlen>width)                                          //~v60sI~
        {                                                          //~v60sI~
            rc=fcmdsplitsplitbin(Ppcw,&plh,width,pcontwk,Popt);//plh:last inserted//~v60sI~
            if (rc)                                                //~v60sI~
                break;                                             //~v60sI~
            rc=1;		//modified                                 //~v60sI~
            plhn=plh;     //last short of split or next            //~v60sI~
        }                                                          //~v60sI~
        else                                                       //~v60sI~
        {                                                          //~v60sI~
            rc=fcmdsplitjoinbin(Ppcw,&plh,Pplh2,width,pcontwk,Popt);//~v60sI~
            if (rc>1)                                              //~v60sI~
                break;                                             //~v60sI~
            plhn=plh;                                              //~v60sI~
        }                                                          //~v60sI~
        if (rc==1)                                                 //~v60sI~
        {                                                          //~v60sI~
            rc=0;                                                  //~v60sI~
        	if (!plh1st)                                           //~v60sI~
            	plh1st=plh2;     //1st changed                     //~v60sI~
    	}                                                          //~v60sI~
    }//plh loop                                                    //~v60sI~
    ufree(pcontwk);                                                //~v76ER~
    if (rc)                                                        //~v60sI~
        return rc;                                                 //~v60sI~
    if (plh1st)                                                    //~v60sI~
    {                                                              //~v60sI~
	  	if (UCBITCHK(Ppfh->UFHflag4,UFHF4XLINENO))	//hex-lineno   //~v76aM~
	        filerenum(Ppcw,Ppfh,RENUMOPT_RENUM,0);	//0:numfld for seti,upctrreq in this func//~v76aI~
        UPCTRREQ(Ppfh);         //write at save                    //~v60sI~
        undocsrmove(Ppcw,plh1st);                                  //~v60sI~
    }                                                              //~v60sI~
    uerrmsg("Width cahnged from %d to %d",                         //~v60sI~
            "バイナリーファイルの\x95\\示幅変更 %d-->%d｡",         //~v60tR~
                widthold,Pwidth);                                  //~v60sI~
    return 0;                                                      //~v60sI~
}//filesplitbin                                                    //~v74TR~
//**************************************************************** //~v60sI~
// fcmdsplitsplitbin                                               //~v60sI~
//*long line split by width for bin file                           //~v60sI~
//* split line or long line for OVER/ALL case.                     //~v60sI~
//*parm1 :pcw                                                      //~v60sI~
//*parm2 :&plh cause overflow(len>width),output:last inserted      //~v60sI~
//*parm3 :split width                                              //~v60sI~
//*parm4 :expandwk                                                 //~v60sI~
//*parm5 :opt                                                      //~v60sI~
//*return:rc:0:no err, 4:err                                       //~v60sI~
//**************************************************************** //~v60sI~
int fcmdsplitsplitbin(PUCLIENTWE Ppcw,PULINEH *Ppplh,int Pwidth,   //~v60sR~
					UCHAR *Pcontwk,int Popt)                       //~v60sI~
{                                                                  //~v60sI~
    PULINEH plh;                                                   //~v60sI~
    int   rlen,newlen,ulhlen,rc=0,insertsw=0;                      //~v60sR~
    UCHAR *pdata,*pdbcs;                                           //~v60sI~
//*********************************                                //~v60sI~
    plh=*Ppplh;                                                    //~v60sI~
    ulhlen=plh->ULHlen;                                            //~v60sI~
    pdata=plh->ULHdata;                                            //~v60sI~
    pdbcs=plh->ULHdbcs;                                            //~v60sI~
//*bin fine has no dbcstbl                                         //~va50I~
	if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)	//prepare undo and update process//~v60sI~
    	return UALLOC_FAILED;                                      //~v60sI~
    if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//excluded line    //~v60sI~
    	if (rc=lcmdincm(Ppcw,plh),rc)                              //~v60sI~
        	return rc;                                             //~v60sI~
    newlen=min(ulhlen,Pwidth);                                     //~v60sI~
    plh->ULHlen=newlen;                                            //~v60sI~
//insert remaining data                                            //~v60sI~
    for (rlen=ulhlen-newlen,pdata+=newlen,pdbcs+=newlen;rlen>0;)   //~v60sI~
    {                                                              //~v60sI~
	    newlen=min(rlen,Pwidth);                                   //~v60sI~
//  	rc=fcmdisrtline(Ppcw,plh,pdata,newlen);                    //~v69tR~
    	rc=fcmdisrtlinedbcs(Ppcw,plh,pdata,pdbcs,newlen);          //~v69tI~
        if (rc)                                                    //~v60sI~
        	return rc;                                             //~v60sI~
        insertsw=1;                                                //~v60sI~
        plh=UGETQNEXT(plh);	//inserted                             //~v60sI~
        rlen-=newlen;                                              //~v60sI~
        pdata+=newlen;                                             //~v60sI~
        pdbcs+=newlen;                                             //~v60sI~
    }//split long line                                             //~v60sI~
    if (!insertsw)                                                 //~v60sI~
    	plh=UGETQNEXT(plh);     //process next                     //~v60sI~
    *Ppplh=plh;                                                    //~v60sI~
    return 0;                                                      //~v60sI~
}//filesplitsplitbin                                               //~v60sI~
//**************************************************************** //~v60sI~
// fcmdsplitjoinbin                                                //~v60sI~
//*join short line with next up to width for bin file              //~v60sI~
//*parm1 :pcw                                                      //~v60sI~
//*parm2 :&plh short line(len<=width);output:next plh to be chked  //~v60sI~
//*parm3 :next of end plh                                          //~v60sI~
//*parm4 :split width                                              //~v60sI~
//*parm5 :join work area                                           //~v60sI~
//*parm6 :opt                                                      //~v60sI~
//*return:rc: 0:no update,1:update occuered,4:err                  //~v60sI~
//**************************************************************** //~v60sI~
int fcmdsplitjoinbin(PUCLIENTWE Ppcw,PULINEH *Ppplh,PULINEH Pplh2,int Pwidth,//~v60sR~
					UCHAR *Pcontwk,int Popt)                       //~v60sI~
{                                                                  //~v60sI~
    PULINEH plh,plh0,plhn;                                         //~v60sI~
    int   rc=0,rlen,newlen,len,ulhlen,offs,contlen,addlen;         //~v60sR~
    UCHAR *pdata,*pdbcs;                                           //~v60sI~
    int tabsw;                                                     //~v69BI~
//*********************************                                //~v60sI~
    plh0=plh=*Ppplh;                                               //~v60sI~
    plhn=UGETQNEXT(plh);                                           //~v60sI~
    pdata=Pcontwk;                                                 //~v60sI~
    pdbcs=Pcontwk+Pwidth+1;                                        //~v60sI~
    ulhlen=plh->ULHlen;                                            //~v60sI~
//gather data upto width                                           //~v60sI~
    tabsw=0;                                                       //~v69BI~
    for (contlen=0,rlen=0;plh && plh!=Pplh2;plh=plhn)              //~v60sR~
    {                                                              //~v60sI~
		plhn=UGETQNEXT(plh);                                       //~v60sI~
        if (plh->ULHtype!=ULHTDATA)                                //~v60sI~
        	continue;                                              //~v60sI~
        if (!plh->ULHdbcs)  //not once displayed                   //~v60sI~
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v60sI~
                return rc;                                         //~v60sI~
	    if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//excluded line//~v60sI~
    		if (rc=lcmdincm(Ppcw,plh),rc)                          //~v60sI~
        		return rc;                                         //~v60sI~
    	if (UCBITCHK(plh->ULHflag2,ULHF2TABFOUND))                 //~v69BI~
        	tabsw=1;    //set TABFOUND to keep tab at save         //~v69BI~
        len=Pwidth-contlen;                                        //~v60sI~
        ulhlen=plh->ULHlen;                                        //~v60sI~
        if (ulhlen<len)                                            //~v60sI~
        	len=ulhlen;                                            //~v60sI~
        memcpy(pdata+contlen,plh->ULHdata,(UINT)len);              //~v60sI~
        memcpy(pdbcs+contlen,plh->ULHdbcs,(UINT)len);              //~v60sI~
        contlen+=len;                                              //~v60sI~
        rlen=ulhlen-len;	//last line remaining                  //~v60sI~
        if (contlen==Pwidth)                                       //~v60sI~
        	break;                                                 //~v60sI~
		plh=UGETQNEXT(plh);                                        //~v60sI~
    }                                                              //~v60sI~
    plh=plh0;                                                      //~v60sI~
    pdata=Pcontwk;                                                 //~v60sI~
    pdbcs=Pcontwk+Pwidth+1;                                        //~v60sI~
	newlen=min(contlen,Pwidth);                                    //~v60sI~
//update 1st line                                                  //~v60sI~
	offs=plh->ULHlen;                                              //~v60sI~
    addlen=newlen-offs;                                            //~v60sI~
    if (addlen==0)	//no change                                    //~v60sI~
    {                                                              //~v60sI~
    	*Ppplh=plhn;                                               //~v60sI~
    	return 0;                                                  //~v60sI~
    }                                                              //~v60sI~
    if (addlen<0)	//to be shorten by delm                        //~v60sI~
    {                                                              //~v60sI~
//*bin file has no dbcstbl                                         //~va50I~
        if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process//~v60sI~
            return UALLOC_FAILED;                                  //~v60sI~
        plh->ULHlen=newlen;		//cut line                         //~v60sI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	  if (Sswebcfile)                                              //~va50I~
        rc=fcmdisrtlinedbcs(Ppcw,plh,pdata+newlen,pdbcs+newlen,-addlen);//~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        rc=fcmdisrtline(Ppcw,plh,pdata+newlen,-addlen);            //~v60sI~
        if (rc)                                                    //~v60sI~
            return rc;                                             //~v60sI~
        plh=UGETQNEXT(plh);	//inserted                             //~v60sI~
    	*Ppplh=plh;                                                //~v60sI~
    	return 1;                                                  //~v60sI~
    }                                                              //~v60sI~
    if (fileexpandbuff(plh,newlen)==UALLOC_FAILED)      //expand buff//~v60sI~
        return 4;                                                  //~v60sI~
//*bin file has no dbcstbl                                         //~va50I~
    if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process//~v60sI~
        return UALLOC_FAILED;                                      //~v60sI~
    plh->ULHlen=newlen;                                            //~v60sI~
    memcpy(plh->ULHdata+offs,pdata+offs,(UINT)addlen);             //~v60sI~
    memcpy(plh->ULHdbcs+offs,pdbcs+offs,(UINT)addlen);             //~v60sI~
    len=addlen;                                                    //~v69BI~
    if (tabsw)    //tab found in joined line                       //~v69BI~
        if (filetabexp(1,plh,offs,&len)==UALLOC_FAILED)  //tab re-expand(len update)//~v69BI~
            return UALLOC_FAILED;                                  //~v69BI~
    len=addlen;   //for next line filetabexp                       //~v60sI~
//delete joind line                                                //~v60sI~
    for (plh=UGETQNEXT(plh0),rlen=addlen;rlen;plh=plhn)            //~v60sI~
    {                                                              //~v60sI~
        plhn=UGETQNEXT(plh);                                       //~v60sI~
        if (plh->ULHtype!=ULHTDATA)                                //~v60sI~
            continue;                                              //~v60sI~
        ulhlen=plh->ULHlen;                                        //~v60sI~
        if (rlen<ulhlen)	//partialy used                        //~v60sI~
        	break;			//not used data plh                    //~v60sI~
        if (rc=lcmddel(Ppcw,plh,plh,1,0,1),rc)//1 line,no csr set,not from lcmd main//~v60sI~
            return rc;                                             //~v60sI~
        rlen-=ulhlen;                                              //~v60sI~
    }                                                              //~v60sI~
//update last plh having not joind remaining data                  //~v60sI~
    if (!rlen)	//last is fully concatinated                       //~v60sI~
    {                                                              //~v60sI~
    	*Ppplh=plhn;                                               //~v60sI~
    	return 1;                                                  //~v60sI~
    }                                                              //~v60sI~
//*bin file has no dbcstbl                                         //~va50I~
    if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process//~v60sI~
        return UALLOC_FAILED;                                      //~v60sI~
    len=ulhlen-rlen;                                               //~v60sI~
    plh->ULHlen=len;                                               //~v60sI~
    memcpy(plh->ULHdata,plh->ULHdata+rlen,(UINT)len);              //~v60sI~
    memcpy(plh->ULHdbcs,plh->ULHdbcs+rlen,(UINT)len);              //~v60sI~
    if (tabsw)    //tab found in joined line                       //~v69BI~
//      if (filetabexp(1,plh,offs,&len)==UALLOC_FAILED)  //tab re-expand(len update)//~v769R~
        if (filetabexp(1,plh,0,&len)==UALLOC_FAILED)  //tab re-expand(len update)//~v769I~
            return UALLOC_FAILED;                                  //~v69BI~
    *Ppplh=plh;                                                    //~v60sI~
    return 1;                                                      //~v60sI~
}//filesplitjoinbin                                                //~v60sI~
//**************************************************************** //~v74YI~
// fcmdsplitspace1data                                             //~v74YR~
// continued space to 1 space                                      //~v74YI~
//return:rc:UALLOC_FAILED                                          //~v74YI~
//**************************************************************** //~v74YI~
int fcmdsplitspace1data(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int *Ppdelctr)//~v74YR~
{                                                                  //~v74YI~
    int   rlen,delctr,totctr,ulhlen;                               //~v74YI~
    UCHAR *pdata,*pdata0,*pdbcs0;                                  //~v74YI~
#ifdef UTF8UCS2                                                    //~va20I~
    UCHAR *pdbcs;                                                  //~va20I~
#endif                                                             //~va20I~
//*********************************                                //~v74YI~
    ulhlen=Plen;                                                   //~v74YI~
    pdata=pdata0=Pdata;                                            //~v74YI~
    pdbcs0=Pdbcs;                                                  //~v74YI~
    for (totctr=0;;)                                               //~v74YR~
    {                                                              //~v74YI~
        rlen=ulhlen-(int)((ULONG)pdata-(ULONG)pdata0);                  //~v74YI~
        if (rlen<=0)                                               //~v74YI~
        	break;                                                 //~v74YI~
#ifdef UTF8UCS2                                                    //~va20I~
		pdbcs=XEUTF_PC2PCD(pdbcs0,pdata,pdata0);                   //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	pdata=UCVEBCUTF_umemchr_space(Sswebcfile,Sswutf8file,pdata,pdbcs,rlen);//~va50I~
    #else                                                          //~va50I~
    	pdata=UTF_memchr(Sswutf8file,pdata,pdbcs,' ',rlen);        //~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
    	pdata=memchr(pdata,' ',(UINT)rlen);                        //~v74YI~
#endif                                                             //~va20I~
        if (!pdata)                                                //~v74YI~
        	break;                                                 //~v74YI~
        pdata++;                                                   //~v74YI~
        rlen=ulhlen-(int)((ULONG)pdata-(ULONG)pdata0);                  //~v74YI~
#ifdef UTF8UCS2                                                    //~va20I~
		pdbcs=XEUTF_PC2PCD(pdbcs0,pdata,pdata0);                   //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        delctr=(int)UCVEBCUTF_umemspnc_space(Sswebcfile,Sswutf8file,pdata,pdbcs,rlen);//~va50I~
    #else                                                          //~va50I~
        delctr=(int)UTF_umemspnc(Sswutf8file,pdata,pdbcs,' ',rlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        delctr=(int)umemspnc(pdata,' ',(UINT)rlen);                           //~v74YI~
#endif                                                             //~va20I~
        if (delctr)                                                //~v74YI~
        {                                                          //~v74YI~
        	totctr+=delctr;                                        //~v74YI~
            memcpy(pdata,pdata+delctr,(UINT)(rlen-delctr));        //~v74YI~
            memcpy(pdbcs0+ulhlen-rlen,pdbcs0+ulhlen-rlen+delctr,(UINT)(rlen-delctr));//~v74YI~
            ulhlen-=delctr;                                        //~v74YI~
        }                                                          //~v74YI~
    }                                                              //~v74YI~
    if (Ppdelctr)                                                  //~v74YI~
    	*Ppdelctr=totctr;                                          //~v74YI~
    return 0;                                                      //~v74YI~
}//fcmdsplitspace1data                                             //~va50R~
//**************************************************************** //~v758I~
// expand plh to the width                                         //~v758I~
//*rc   :UALLOC_FAILED,1:expanded                                  //~v758I~
//**************************************************************** //~v758I~
int fcmdplhpadspace(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Plen)//~v758I~
{                                                                  //~v758I~
	int ulhlen,len;                                                //~v758I~
//*******************                                              //~v758I~
	if ((len=Plen-(ulhlen=Pplh->ULHlen))<=0)                       //~v758R~
    	return 0;                                                  //~v758I~
//*ebc_setdbcstbl by caller                                        //~va50I~
	if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process//~v758I~
    	return UALLOC_FAILED;                                      //~v758I~
    if (fileexpandbuff(Pplh,Plen)==UALLOC_FAILED)      //expand buff//~v758I~
        return UALLOC_FAILED;                                      //~v758I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    memset(Pplh->ULHdata+ulhlen,Schspace,(UINT)len);               //~va50I~
#else                                                              //~va50I~
    memset(Pplh->ULHdata+ulhlen,' ',(UINT)len);                    //~v758R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    memset(Pplh->ULHdbcs+ulhlen,0  ,(UINT)len);                    //~v758R~
    Pplh->ULHlen=Plen;                                             //~v758I~
    return 1;                                                      //~v758I~
}//fcmdplhpadspace                                                 //~v758I~
//**************************************************************** //~v75fI~
// fcmdresettemperr                                                //~v75fI~
//*count temperr flag and reset all                                //~v75fI~
//*return:errctr                                                   //~v75fI~
//**************************************************************** //~v75fI~
int fcmdresettemperr(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int *Pperrctr)//~v75fI~
{                                                                  //~v75fI~
    int   errctr=0;                                                //~v75fI~
    PULINEH plh;                                                   //~v75fI~
//*********************************                                //~v75fI~
    for (plh=Pplh1;plh && plh!=Pplh2;plh=UGETQNEXT(plh))           //~v75fI~
    {                                                              //~v75fI~
    	if (UCBITCHK(plh->ULHflag4,ULHF4TEMPERR))                  //~v75fR~
        {                                                          //~v75fI~
	    	UCBITOFF(plh->ULHflag4,ULHF4TEMPERR);                  //~v75fR~
    	    lcmdshifterr(plh,0,0);  //set reverse                  //~v75fI~
            errctr++;                                              //~v75fI~
        }                                                          //~v75fI~
    }                                                              //~v75fI~
    *Pperrctr+=errctr;                                             //~v75fI~
    return errctr;                                                 //~v75fI~
}//fcmdresettemperr                                                //~v75fI~
//**************************************************************** //~v75fI~
// fcmdsettemperr                                                  //~v75fI~
//*set temperr flag                                                //~v75fI~
//*return:1:dup                                                    //~v75fI~
//**************************************************************** //~v75fI~
int fcmdsettemperr(int Popt,PULINEH Pplh)                          //~v75fI~
{                                                                  //~v75fI~
    if (UCBITCHK(Pplh->ULHflag4,ULHF4TEMPERR))                     //~v75fI~
    	return 1;                                                  //~v75fI~
	UCBITON(Pplh->ULHflag4,ULHF4TEMPERR);   //set temp err         //~v75fI~
    return 0;                                                      //~v75fI~
}//fcmdsettemperr                                                  //~v75fI~
//**************************************************************** //~v47iI~
// func_join_file                                                  //~v47iI~
// join  cmd                                                       //~v47iI~
// JOIN  {X|NX} [ALL] [.label]                                     //~v47iI~
//   X     :excluded line                                          //~v47iI~
//   NX    :not excluded line                                      //~v47iI~
//   ALL   :All x or nx                                            //~v47iI~
//*rc   :0                                                         //~v47iI~
//**************************************************************** //~v47iI~
int func_join_file(PUCLIENTWE Ppcw)                                //~v47iI~
{                                                                  //~v47iI~
#ifdef DOSDOS                                                      //~v50JI~
    return errnotsupported("JOIn","DOS version");                  //~v50JR~
#else                                                              //~v50JI~
static UCHAR *Swordtbl="X\0" "NX\0" "ALL\0";                       //~v47iI~
    PUFILEC pfc;                                                   //~v47iI~
    PUFILEH pfh;                                                   //~v47iI~
    PULINEH plh1,plh2,plhc;                                        //~v47iR~
    UPODELMTBL *podt;                                              //~v47iI~
    int ii,opdno,opid,rc,jointype,allsw=0,seq1,seq2,labsw=0,offs;  //~v47iR~
    int bandlesw=0;                                                //~v55JI~
    LONG lbandle=0,lskip=0,repeat;                                 //~v55JR~
	UCHAR *pc;                                                     //~v47iR~
	UCHAR *pc2;                                                    //~v55JI~
//*********************************                                //~v47iI~
    if (!(Ppcw->UCWparm))       //operand                          //~v47iI~
    {                                                              //~v47iI~
//      uerrmsg("JOI { X | NX } [ ALL ] [.lab1 .lab2]",0);         //~v55JR~
        uerrmsg("JOI { X | NX | n[-b-s] } [ ALL ] [.lab1 .lab2]",0);//~v55JR~
        return 0;                                                  //~v47iR~
    }                                                              //~v47iI~
	pfc=Ppcw->UCWpfc;                                              //~v47iI~
    if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                         //~v47iI~
		return errbrowsemode();                                    //~v47iI~
    pfh=pfc->UFCpfh;                                               //~v47iI~
    if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))  //bin file              //~v47iI~
        return fcmdinvalidbinfile();                               //~v47iI~
//  rc=fcmdgetlabparm(Ppcw,&plh1,&plh2,FCGLP_NEXTPLH|FCGLP_SPLITCHK); 	//get next display line of endplh//~v62HR~
    rc=fcmdgetlabparm(Ppcw,0,&plh1,&plh2,FCGLP_NEXTPLH|FCGLP_SPLITCHK); 	//get next display line of endplh//~v62HI~
    if (rc)                                                        //~v47iI~
    	return rc;                                                 //~v47iI~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v47iI~
    pc=Ppcw->UCWopdpot;                                            //~v47iI~
    podt=Ppcw->UCWopddelmt;                                        //~v47iI~
    jointype=-1;               //no default                        //~v47iR~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1,podt++)	//next operand addr//~v47iI~
	{                                                              //~v47iI~
      	if ((*pc==ULCCMDLABEL && !podt->upoquate))  //start by . but not in quate//~v47iI~
        {                                                          //~v47iI~
        	labsw=1;		//label found                          //~v47iI~
    		continue;                                              //~v47iI~
        }                                                          //~v47iI~
        if (*pc>='0' && *pc<='9')	//numeric                      //~v55JI~
        {                                                          //~v55JI~
            bandlesw=1;                                            //~v55JM~
        	repeat=atoi(pc);                                       //~v55JI~
            if (repeat==1)                                         //~v55JI~
            {                                                      //~v55JI~
                uerrmsg("concatination line count(%d) should be >=2",0,//~v55JI~
                            repeat);                               //~v55JI~
		        return 4;                                          //~v55JI~
            }                                                      //~v55JI~
            pc2=pc+unumlen(pc,0,(int)strlen(pc));                  //~v55JR~
            if (*pc2)                                              //~v55JR~
            {                                                      //~v55JI~
            	if (*pc2++!='-')                                   //~v55JR~
		            return errinvalid(pc);                         //~v55JI~
            	rc=ugetnumrange(pc2,&lbandle,&lskip);              //~v55JR~
	            if (!rc==1)                                        //~v55JR~
		            return errinvalid(pc);                         //~v55JR~
            }                                                      //~v55JI~
    		continue;                                              //~v55JI~
        }                                                          //~v55JI~
        opid=wordtblisrch(pc,Swordtbl);                            //~v47iI~
        switch(opid)                                               //~v47iI~
        {                                                          //~v47iI~
        case 0: //err                                              //~v47iI~
            return errinvalid(pc);                                 //~v47iR~
        case 1: //X                                                //~v47iR~
            jointype=0;                                            //~v47iR~
            break;                                                 //~v47iI~
        case 2: //NX                                               //~v47iI~
            jointype=1;                                            //~v47iI~
            break;                                                 //~v47iI~
        case 3: //ALL                                              //~v47iR~
        	allsw=1;                                               //~v47iI~
            break;                                                 //~v47iI~
        }                                                          //~v47iI~
	}//loop by operand no                                          //~v47iI~
//  if (jointype<0)                                                //~v55JR~
    if ((bandlesw && jointype>=0)	//both                         //~v55JR~
    ||  (!bandlesw && jointype<0))//none                           //~v55JR~
    {                                                              //~v47iI~
//    	uerrmsg("specify join type X or NX",                       //~v55JR~
//        		"連結タイプ（ X か NX）を指定してください");       //~v55JR~
      	uerrmsg("missing join type parm; X, NX or linectr-repeat-skip",//~v55JR~
          		"連結タイプ（ X か NX か 連結行数-繰返し数-飛越し行数）の指定なし");//~v55JR~
        return 4;                                                  //~v47iI~
    }                                                              //~v47iI~
//set start line                                                   //~v47iI~
  if (!bandlesw)                                                   //~v55JI~
  {                                                                //~v55JI~
	if (!allsw)	//from current line                                //~v47iI~
    {                                                              //~v47iI~
		fcmdgetstartplhoffs(Ppcw,&plhc,&offs,1);                   //~v47iI~
        if (labsw)                                                 //~v47iI~
        {                                                          //~v47iI~
            seq1=lineseqchk(plhc,plh1);                            //~v47iI~
            seq2=lineseqchk(plhc,plh2);                            //~v47iI~
            if (seq2>=0)            //plhc>=plh2                   //~v47iI~
            {                                                      //~v47iI~
                uerrmsg("Cursor is out of label range",            //~v47iR~
                "カー\x83\\ルが行範囲指定の範囲外");               //~v47iR~
                return 4;                                          //~v47iI~
            }                                                      //~v47iI~
            if (seq1>0)         //plhc<plh1                        //~v47iR~
                plh1=plhc;          //start from label             //~v47iI~
        }                                                          //~v47iI~
        else                                                       //~v47iI~
        	plh1=plhc;                                             //~v47iI~
    }                                                              //~v47iI~
  }//not bandle                                                    //~v55JI~
    UPCTRREQ(pfh);         //write at save                         //~v47iI~
  if (bandlesw)                                                    //~v55JI~
  {                                                                //~v55JI~
    if (!plh1)                                                     //~v55JI~
    {                                                              //~v55JI~
		plh1=UGETQTOP(&pfh->UFHlineque);                           //~v55JI~
		plh2=UGETQEND(&pfh->UFHlineque);                           //~v55JI~
    }                                                              //~v55JI~
  	rc=lcmdjoin(Ppcw,plh1,plh2,repeat,(int)lbandle,(int)lskip);    //~v55JR~
  }                                                                //~v55JI~
  else                                                             //~v55JI~
  {                                                                //~v55JI~
    if (jointype)                                                  //~v47iI~
    	rc=fcmdjoinnx(Ppcw,pfh,plh1,plh2,allsw);                   //~v47iR~
    else                                                           //~v47iI~
    	rc=fcmdjoinx(Ppcw,pfh,plh1,plh2,allsw);                    //~v47iI~
  }//not bandle                                                    //~v55JI~
    UPCTRREQ(pfh);         //write at save                         //~v47iI~
    return rc;                                                     //~v47iI~
#endif                                                             //~v50JI~
}//func_join_file                                                  //~v47iI~
#ifdef DOSDOS                                                      //~v50JI~
#else                                                              //~v50JI~
//**************************************************************** //~v47iI~
// fcmdjoinx                                                       //~v47iR~
//*join excluded line                                              //~v47iR~
//*parm1 :pcw                                                      //~v47iI~
//*parm2 :pfh                                                      //~v47iI~
//*parm3 :start plh                                                //~v47iI~
//*parm4 :end plh                                                  //~v47iI~
//*parm5 :opt (all)                                                //~v47iR~
//*return:rc                                                       //~v47iI~
//**************************************************************** //~v47iI~
int fcmdjoinx(PUCLIENTWE Ppcw,UFILEH *Ppfh,PULINEH Pplh1,PULINEH Pplh2,int Popt)//~v47iI~
{                                                                  //~v47iI~
    PULINEH plh,plhc,plhn;                                         //~v47iR~
    int   rc,csrsw=0,joinctr=0;                                    //~v47iR~
    long  xctr;                                                    //~v47iI~
//*********************************                                //~v47iI~
    for (plh=Pplh1;plh && plh!=Pplh2;plh=UGETQNEXT(plh))           //~v47iR~
    {                                                              //~v47iI~
        if (plh->ULHtype!=ULHTEXCLUDE)                             //~v47iR~
        	continue;                                              //~v47iM~
        plhc=plh;                                                  //~v47iI~
//chk splitline partialy excluded                                  //~v47iI~
        for (xctr=0;plh=UGETQNEXT(plh),plh;)                       //~v47iR~
        {                                                          //~v47iI~
	    	if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//excluded line//~v47iI~
            	break;                                             //~v47iI~
		    if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))   //2nd line  //~v47iI~
            {                                                      //~v47iI~
            	if (!xctr)	//exclude start from 2nd line          //~v47iI~
                	xctr=1;                                        //~v47iR~
            }                                                      //~v47iI~
            else                                                   //~v47iI~
	            xctr++;		//top of concat line                   //~v47iR~
        }                                                          //~v47iI~
        plhn=plh;                                                  //~v47iI~
//        if (!xctr       //start by 2nd line                      //~v47iR~
//        ||  plh && UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))   //2nd line//~v47iR~
//        {                                                        //~v47iR~
//            uerrmsg("split line is partialy excluded",           //~v47iR~
//                    "分割行が部分的に非\x95\\示になっている");   //~v47iR~
//            undocsrmove(Ppcw,plh);                               //~v47iR~
//            return 4;                                            //~v47iR~
//        }                                                        //~v47iR~
        csrsw=1;                                                   //~v47iI~
        if (xctr>1)                                                //~v47iI~
        {                                                          //~v47iI~
        	rc=lcmdjoinx(Ppcw,plhc);                               //~v47iR~
        	if (rc)                                                //~v47iR~
        		return rc;                                         //~v47iR~
            joinctr++;                                             //~v47iI~
            if (!Popt)                                             //~v47iR~
                break;                                             //~v47iR~
        }                                                          //~v47iM~
    }                                                              //~v47iI~
    if (csrsw)                                                     //~v47iR~
        if (plhn)                                                  //~v47iR~
	        undocsrmove(Ppcw,plhn);                                //~v47iR~
    uerrmsg("%d x-line-group processed",0,                         //~v47iR~
            joinctr);                                              //~v47iI~
    return 0;                                                      //~v47iI~
}//fcmdjoinx                                                       //~v47iR~
//**************************************************************** //~v47iI~
// fcmdjoin                                                        //~v47iI~
//*split continued line                                            //~v47iI~
//*parm1 :pcw                                                      //~v47iI~
//*parm2 :pfh                                                      //~v47iI~
//*parm3 :start plh                                                //~v47iI~
//*parm4 :end plh                                                  //~v47iI~
//*parm5 :opt (all)                                                //~v47iI~
//*return:rc                                                       //~v47iI~
//**************************************************************** //~v47iI~
int fcmdjoinnx(PUCLIENTWE Ppcw,UFILEH *Ppfh,PULINEH Pplh1,PULINEH Pplh2,int Popt)//~v47iI~
{                                                                  //~v47iI~
    PULINEH plh,plhs=0,plhe,plhp;                                  //~v47iR~
    int   rc=0,linectr=0,donesw=0,joinctr=0;                       //~v47iR~
//*********************************                                //~v47iI~
    for (plhp=plh=Pplh1;plh && plh!=Pplh2;plhp=plh,plh=UGETQNEXT(plh))//~v47iR~
    {                                                              //~v47iI~
        if (plh->ULHtype==ULHTDATA)	//not before eof line          //~v47iI~
        {                                                          //~v47iI~
	    	if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//excluded line//~v47iI~
        		continue;                                          //~v47iI~
        	if (!plhs)                                             //~v47iI~
        		plhs=plh;                                          //~v47iI~
        	plhe=plh;                                              //~v47iI~
			if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))   //not 2nd line//~v47iI~
	        	linectr++;                                         //~v47iI~
        }                                                          //~v47iI~
        else                                                       //~v47iI~
        if (plh->ULHtype==ULHTEXCLUDE)	//not before eof line      //~v47iR~
        {                                                          //~v47iI~
        	if (!plhs)                                             //~v47iI~
            	continue;                                          //~v47iI~
            donesw=1;                                              //~v47iI~
            if (linectr>1)                                         //~v47iR~
            {                                                      //~v47iI~
            	rc=lcmdjoin(Ppcw,plhs,plhe,linectr,0,0);//repeat,bandle,skip//~v47iR~
            	if (rc)                                            //~v47iR~
                	break;                                         //~v47iR~
                joinctr++;                                         //~v47iR~
		        if (!Popt)                                         //~v47iI~
                {                                                  //~v47iI~
                	plhs=0;                                        //~v47iI~
    	            break;                                         //~v47iI~
                }                                                  //~v47iI~
            }                                                      //~v47iI~
            plhs=0;     //start new bandle                         //~v47iI~
            linectr=0;                                             //~v47iI~
        }                                                          //~v47iI~
    }//plh loop                                                    //~v47iI~
    if (rc)                                                        //~v47iI~
        return rc;                                                 //~v47iI~
    if (plhs)		//at end of range                              //~v47iR~
    {                                                              //~v47iI~
        donesw=1;                                                  //~v47iM~
		if (linectr>1)                                             //~v47iI~
        {                                                          //~v47iR~
            rc=lcmdjoin(Ppcw,plhs,plhe,linectr,0,0);               //~v47iR~
            if (!rc)                                               //~v47iR~
                return rc;                                         //~v47iR~
        }                                                          //~v47iI~
    }                                                              //~v47iI~
    if (donesw)                                                    //~v47iI~
    {                                                              //~v47iI~
    	if (!plh)                                                  //~v47iI~
    		plh=plhp;                                              //~v47iI~
    	undocsrmove(Ppcw,plh);                                     //~v47iR~
    }                                                              //~v47iI~
    uerrmsg("%d nx-line-group processed",0,                        //~v47iI~
            joinctr);                                              //~v47iI~
    return 0;                                                      //~v47iI~
}//fcmdjoinnx                                                      //~v47iI~
#endif                                                             //~v50JI~
#ifdef DOSDOS                                                      //~va8kI~
#else                                                              //~va8kI~
//**************************************************************** //~va8kI~
// fcmdsplitbydelmbndseach                                         //~va8kM~
//*process tflow paragraph one by one                              //~va8kM~
//*return:rc 4:dbcs shrinked to len=0,2:dbcs split under SBCSoption//~va8kR~
//**************************************************************** //~va8kM~
int fcmdebcsplitlen(int Pfuncopt,int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Pdatalen,int Pwidth,char *Pdelmstr,int *Ppsplitlen)//~va8kR~
{                                                                  //~va8kM~
	int newlen,splitlen,rc=0,rc2,swappendso=0,opt=0,swnotsbcs;     //~va8kR~
//*********************************                                //~va8kM~
	newlen=*Ppsplitlen;                                            //~va8kR~
    swnotsbcs=!(Popt & FCSPL_SBCS);                                //~va8kI~
    if (swnotsbcs)                                                 //~va8kI~
    {                                                              //~va8kI~
    	if ( (Pfuncopt & FCEBSLO_EXPAND)      //expandable within bnds range//~va8kR~
		&&   (!Pwidth || newlen<Pwidth)                            //~va8kR~
        )                                                          //~va8kI~
    		opt|=XEEBCDSLO_EXPANDABLE;	//add SI if len is after dbcs2nd//~va8kI~
    }                                                              //~va8kI~
	rc2=xeebc_dbcssplitlen(opt,Ppdata,Ppdbcs,newlen,&splitlen);    //~va8kR~
    if (swnotsbcs)                                                 //~va8kI~
    {                                                              //~va8kI~
    	if (!splitlen)                                             //~va8kI~
        {                                                          //~va8kI~
		  if (Pfuncopt & FCEBSLO_MIN0)                             //~va8kI~
          {                                                        //~va8kI~
          	newlen=0;                                              //~va8kI~
            rc=2;   //shift to nextline                            //~va8kI~
          }                                                        //~va8kI~
          else                                                     //~va8kI~
        	rc=4;   	//no change length                         //~va8kI~
        }                                                          //~va8kI~
        else                                                       //~va8kI~
        if (rc2)    //                                             //~va8kI~
        {                                                          //~va8kI~
//            if (newlen<Pdatalen)   //dbcs split by concat(not by bnds)//~va8kR~
//                if ((Popt & FCSPL_MARGIN))  //keep max width     //~va8kR~
//                    rc=2;   //notify shift to next line          //~va8kR~
            if (rc2==2) //append SI                                //~va8kR~
            {                                                      //~va8kR~
                newlen=splitlen;                                   //~va8kR~
                if (newlen<Pdatalen                                //~va8kR~
                &&  *(Ppdata+newlen)==CHAR_SI    //dbcs mach at eol//~va8kR~
                )                                                  //~va8kR~
                    newlen++;                                      //~va8kR~
                else                                               //~va8kR~
                    swappendso=1;                                  //~va8kR~
            }                                                      //~va8kR~
            else                                                   //~va8kR~
                newlen=splitlen;                                   //~va8kR~
        }                                                          //~va8kI~
    }                                                              //~va8kI~
    else	//sbcs                                                 //~va8kI~
    {                                                              //~va8kI~
    	if (rc2)                                                   //~va8kI~
        	rc=2;	//dbcs split by sbcs option                    //~va8kR~
    }                                                              //~va8kI~
    *Ppsplitlen=newlen;                                            //~va8kM~
    if (swappendso)                                                //~va8kI~
        rc|=FCSPLRC_APPENDSO;        //append so so ebc dbcs string split//~va8kR~
    return rc;                                                     //~va8kM~
}//fcmdebcsplitlen                                                 //~va8kM~
//**************************************************************** //~va8kI~
// fcmdebcappendsoeol                                              //~va8kI~
//*append so at EOL                                                //~va8kI~
//*rc:UALLOC_FAILED                                                //~va8kI~
//**************************************************************** //~va8kI~
int fcmdebcappendsoeol(int Popt,PULINEH Pplh)                      //~va8kI~
{                                                                  //~va8kI~
	int newlen,oldlen;                                             //~va8kI~
//*********************************                                //~va8kI~
    oldlen=Pplh->ULHlen;                                           //~va8kR~
    newlen=oldlen+1;                                               //~va8kR~
    if (newlen>Pplh->ULHbufflen)                                   //~va8kR~
        if (fileexpandbuff(Pplh,newlen)==UALLOC_FAILED)      //expand buff//~va8kR~
            return UALLOC_FAILED;                                  //~va8kR~
    *(Pplh->ULHdata+oldlen)=CHAR_SI;                               //~va8kR~
    if (Pplh->ULHdbcs)                                             //~va8kR~
        *(Pplh->ULHdbcs+oldlen)=0;                                 //~va8kR~
    Pplh->ULHlen=newlen;                                           //~va8kI~
    return 0;                                                      //~va8kI~
}//fcmdebcappendsoeol                                              //~va8kI~
//**************************************************************** //~va8wI~
// dbcs string concatination chk to delete intermediate so/si      //~va8wI~
// return 0:not avail,1:so/si deletable                            //~va8wR~
//**************************************************************** //~va8wI~
int fcmdebcchkdbcsconcat(int Popt,UCHAR *Pdata1,UCHAR *Pdbcs1,int Plen1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen2)//~va8wR~
{                                                                  //~va8wI~
//*********************************                                //~va8wI~
	if (!Sswebcfile                                                //~va8wI~
    ||  (Popt & FCSPL_SBCS))                                       //~va8wR~
        return 0;                                                  //~va8wI~
  	if (Sopt2 & SOPT2_SPLCRLF)	//display width change             //~va8wI~
    	return 0;                                                  //~va8wI~
    if (Plen1<3||Plen2<3)                                          //~va8wI~
    	return 0;                                                  //~va8wI~
    if (*(Pdata1+Plen1-1)!=CHAR_SI||*Pdata2!=CHAR_SO)              //~va8wI~
    	return 0;                                                  //~va8wI~
    if (*(Pdbcs1+Plen1-2)!=UDBCSCHK_DBCS2ND||*(Pdbcs2+1)!=UDBCSCHK_DBCS1ST)//~va8wR~
    	return 0;                                                  //~va8wI~
    return 1;                                                      //~va8wR~
}//fcmdebcchkdbcsconcat                                            //~va8wI~
//**************************************************************** //~va8wI~
// dbcs string concatination chk to delete intermediate so/si      //~va8wI~
//  12+SO12-->1212                                                 //~va8wI~
// return 0:not avail,1:so/si deletable                            //~va8wI~
//**************************************************************** //~va8wI~
int fcmdebcchkdbcsconcatbndsupdateL(int Popt,UCHAR *Pdata1,UCHAR *Pdbcs1,int Plen1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen2)//~va8wI~
{                                                                  //~va8wI~
//*********************************                                //~va8wI~
	if (!Sswebcfile                                                //~va8wI~
    ||  (Popt & FCSPL_SBCS))                                       //~va8wI~
        return 0;                                                  //~va8wI~
  	if (Sopt2 & SOPT2_SPLCRLF)	//display width change             //~va8wI~
    	return 0;                                                  //~va8wI~
    if (Plen1<2||Plen2<3)                                          //~va8wI~
    	return 0;                                                  //~va8wI~
    if (*Pdata2!=CHAR_SO)                                          //~va8wI~
    	return 0;                                                  //~va8wI~
    if (*(Pdbcs1+Plen1-1)!=UDBCSCHK_DBCS2ND||*(Pdbcs2+1)!=UDBCSCHK_DBCS1ST)//~va8wI~
    	return 0;                                                  //~va8wI~
    return 1;                                                      //~va8wI~
}//fcmdebcchkdbcsconcatbndsupdateL                                 //~va8wI~
//**************************************************************** //~va8wI~
// dbcs string concatination chk to delete intermediate so/si      //~va8wI~
// return 0:not avail,1:so/si deletable                            //~va8wI~
//**************************************************************** //~va8wI~
int fcmdebcchkdbcsconcatbnds(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Pswdbcssplitr,PSPLITWK Ppspw,int Psrcoffs,int Pwidth)//~va8wR~
{                                                                  //~va8wI~
	UCHAR *pdata1,*pdbcs1,*pdata2,*pdbcs2;                         //~va8wR~
    int len1,len2;                                                 //~va8wI~
//*********************************                                //~va8wI~
	if (!Sswebcfile                                                //~va8wI~
    ||  (Popt & (FCSPL_TFLOW|FCSPL_SBCS|FCSPL_ALLWIDTH0))          //~va8wR~
    )                                                              //~va8wI~
        return 0;                                                  //~va8wI~
  	if (Sopt2 & SOPT2_SPLCRLF)	//display width change             //~va8wI~
    	return 0;                                                  //~va8wI~
    if (Plen>=Pwidth)       //concat not avail                     //~va8wI~
    	return 0;                                                  //~va8wI~
    if (Pswdbcssplitr)                                             //~va8wI~
    	return 0;                                                  //~va8wI~
    pdata1=Pdata+Plen;                                             //~va8wI~
    pdbcs1=Pdbcs+Plen;                                             //~va8wI~
    len1=Plen;                                                     //~va8wI~
    if (len1<3)                                                    //~va8wR~
    	return 0;                                                  //~va8wR~
    if (*(pdata1-1)!=CHAR_SI || *(pdbcs1-2)!=UDBCSCHK_DBCS2ND)     //~va8wI~
    	return 0;                                                  //~va8wI~
    pdata2=Ppspw->SPWdatadbcs+Psrcoffs;                            //~va8wR~
    pdbcs2=Ppspw->SPWdatadbcs+Ppspw->SPWlen+Psrcoffs;              //~va8wR~
    len2=Ppspw->SPWlen-Psrcoffs;                                   //~va8wR~
    if (!Psrcoffs && Ppspw->SPWflag & SPWF_DBCSSPLITL)             //~va8wR~
    	return 0;                                                  //~va8wI~
    if (len2<3)                                                    //~va8wR~
    	return 0;                                                  //~va8wI~
    if (*pdata2!=CHAR_SO || *(pdbcs2+1)!=UDBCSCHK_DBCS1ST)         //~va8wI~
    	return 0;                                                  //~va8wI~
    if (Pwidth-len1-1<3)	//no space to concat 1 dbcs            //~va8wI~
    	return 0;                                                  //~va8wM~
    return 1;                                                      //~va8wI~
}//fcmdebcchkdbcsconcat                                            //~va8wI~
#endif    //!DOSDOS                                                //~va8kI~
