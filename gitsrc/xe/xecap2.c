//CID://+vaf9R~:          update#= 11                              //~vaf9R~
//*************************************************************
//*xecap.c
//* cut and paste
//************************************************************* //~v069I~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//va7y:100823 EBC:handle support for cap                           //~va7yI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va2n:100104 (BUG)stdpaste abend when target rgn contains hdr line//~va2nI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            cap2.c  :save ::cb status to ::cbstat file           //~va20I~
//v760:070529 avoid err join failed by margin chk by pre-chk for the case one line(No-EOL) stdpaste//~v760I~
//v74v:070222 (BUG of v74n)when target region is start at col=0;C+v override prev line//~v74vI~
//v74q:070218 (BUG)cob margin consideration for ETOL(by C+b)       //~v74qI~
//v74p:070217 (BUG)C&P:if target rgn is multiple cobol,last line cob margin lost at join//~v74pI~
//v74n:070217 (BUG)join fail by oom if paste target region is one line because ETOL is done before split//~v74nI~
//v74j:070216 (BUG)C&P del fail by join fail for margined file.    //~v74jI~
//            (by remaining oom of 1st line;delete oom for 1stline for region cut)//~v74jI~
//v74i:070216 (BUG)C&P paste to region fail by join fail for margined file.//~v74iI~
//            (ignore space before margin when join and keep oom(ignore oom for spf but)//~v74iI~
//v74h:070216 (BUG)C&P paste to region fail by join fail for margined file.//~v74hI~
//            (because if target is region,once cut region(join top and last) then split)//~v74hI~
//            delay join till after insert source line)            //~v74hI~
//v74e:070215 (BUG)C&P ceare regin clear oom only for margined file//~v74eI~
//v70x:060903 (BUG)caut&paste;clear abend when last line is the hdr line(end-of-file).//~v70xI~
//v676:051226 cut & paste;margined file(COBOL etc) consideration(ignore space cut by margin)//~v676I~
//v673:051226 cut & paste;margined file(COBOL etc) consideration(use OPBREP and chk rc=1:overflow cut)//~v673I~
//v66u:051121 cap:accept hdr/end line as region specification start/end point//~v66uI~
//v66n:051026 assume eol at end of line if cursor is on lineno fld when Ctrl+v//~v66nI~
//v66f:051021 support standard mode cut & paste,assign Ctrl+v for stream insert//~v66fI~
//                     None   OpenBlock  ClosedBlock   OpenRegion ClosedRegion//~v66fI~
//            C+v    RgnIns   NoBlockErr BlockClearRep OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Ins  BlockIns NoBlockErr GetBlock+Ins  OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Rep  BlockRep NoBlockErr GetBlock+Rep  OpenRgnErr RgnDel+Ins//~v66fI~
//v66f:051021 (BUG)A+F9 abend when A+F7 on same excludeline and pos1>pos2//~v66fI~
//v66e:051020 support standard mode cut & paste;                   //~v66eI~
//            A+F6/A+v:range specification, A+F9:copy, A+Ins:paste Ins, A+F8:paste Rep, C+v:paste Del then Ins//~v66eR~
//            Del/BackSpace:delete range, A+Del:del+copy to clipboard//~v66eI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
	#ifdef W32                                                     //~v085I~
//  	#include <windows.h>                                       //~v085I~
	#else                                                          //~v085I~
	#define INCL_BASE
	#include <os2.h>
	#endif                                                         //~v085I~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318R~
#include <ualloc.h>                                             //~v04dI~
#include <ukbd.h>                                               //~v06lI~
#include <ucvebc.h>                                                //~va50I~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc4.h>                                               //~va79I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile2.h"                                               //~v66fI~
#include "xefile42.h"                                              //~v673I~
#include "xefile6.h"                                               //~v66fI~
#include "xefunc.h"
#include "xechar.h"
#include "xechar2.h"                                               //~v66fI~
#include "xelcmd.h"
#include "xelcmd2.h"                                               //~v66fR~
#include "xelcmd3.h"                                               //~v66fI~
#include "xefsub.h"                                             //~5318I~
#include "xefcmd.h"                                             //~v06iI~
#include "xeerr.h"                                                 //~v098I~
#include "xecap.h"                                                    //~v06tI~
#include "xecap2.h"                                                //~v66fI~
#include "xepan.h"                                                 //~v10MI~
#include "xesub.h"                                                 //~v10MI~
#include "xesub2.h"                                                //~va50I~
#include "xeundo.h"                                                //~v66fI~
//*******************************************************
int capstdpasteblockline(PUCLIENTWE Ppcw,PULINEH Pplht,PULINEH Pplhs,int Ppos1,int Ppos2,char *Pwork);//~v66fR~
//*******************************************************          //~v66eI~
//!capcut   assumption:top and last is data line                   //~v66eR~
//* del region                                                     //~v66eI~
//* out:joinrc:1:join bypassed by skipjoin req                     //~v74hI~
//* retrn:rc                                                       //~v66eI~
//*******************************************************          //~v66eI~
//int capcutregion(PUCLIENTWE Ppcw,PULINEH *Ppplh1,PULINEH *Ppplh2,int Ppos1,int Ppos2)//~v74hR~
int capcutregion(int Popt,PUCLIENTWE Ppcw,PULINEH *Ppplh1,PULINEH *Ppplh2,int Ppos1,int Ppos2,int *Ppjoinrc)//~v74hI~
{                                                                  //~v66eI~
	PULINEH  plh,Pplh1,Pplh2,delplh1,delplh2,nextplh,sortplh1,sortplh2;//~v66fR~
	int rc=0,spos,ulhlen,joinsw=1;                                 //~v66fR~
//  PUFILEH pfh;                                                   //~v760R~
//*******************                                              //~v66eI~
	if (Ppjoinrc)                                                  //~v74hI~
    	*Ppjoinrc=0;                                               //~v74hI~
	Pplh1=sortplh1=*Ppplh1;                                        //~v66fR~
	Pplh2=sortplh2=*Ppplh2;                                        //~v66fR~
//  pfh=UGETPFH(Pplh1);                                            //~v760R~
//top line process                                                 //~v66fI~
    plh=Pplh1;                                                     //~v66fI~
    ulhlen=plh->ULHlen;                                            //~v66fR~
    if (Pplh1==Pplh2         //single line                         //~v66fR~
    &&  Ppos1<ulhlen       //line replace                          //~v66fI~
    &&  Ppos2<=ulhlen)     //leave eol and cut intermediate        //~v66fI~
    {                                                              //~v66fI~
        if (Ppos1<0)                                               //~v66fI~
            spos=0;                                                //~v66fI~
        else                                                       //~v66fI~
            spos=Ppos1;                                            //~v66fI~
        if (Popt & CCR_SPLIT && Ppos2<ulhlen)   //requested split for paste//~v74nI~
        {                                                          //~v74nI~
    		if (rc=charlcmdsplit(CLS_IGM,Ppcw,plh,Ppos2),rc) 	//split top line//~v74nI~
            	return rc;                                         //~v74nI~
			if (Ppjoinrc)                                          //~v74nI~
    			*Ppjoinrc=1; 		//join bypassed                //~v74nI~
        	return charfldedit(CHAROPEEOLIGM,//erase oom           //~v74nR~
               plh->ULHdata,        //buffer                       //~v74nI~
               plh->ULHdbcs,        //buffer                       //~v74nI~
               Ppos1,           //current col                      //~v74nI~
               0,               //start col                        //~v74nI~
               plh->ULHlen,         //end col                      //~v74nI~
               plh->ULHbufflen,     //buff len last                //~v74nI~
               Ppcw,                    //pcw                      //~v74nI~
               plh);                                               //~v74nI~
        }                                                          //~v74nI~
        return charfldedit(CHAROPETOL,//erase top of line up to start col//~v66fI~
               plh->ULHdata,        //buffer                       //~v66fI~
               plh->ULHdbcs,        //buffer                       //~v66fI~
               Ppos2,           //current col                      //~v66fI~
               spos,         //start col                           //~v66fI~
               ulhlen,          //end col                          //~v66fI~
               plh->ULHbufflen,     //buff len last                //~v66fI~
               Ppcw,                    //pcw                      //~v66fI~
               plh);            //update ctr etc                   //~v66fI~
    }//one line                                                    //~v66fI~
    if (Ppos1>0                                                    //~v66fI~
    && 	Ppos1<ulhlen)			//top line cut                     //~v66fI~
    {                                                              //~v66fI~
//      if (rc=charfldedit(CHAROPEEOL,//erase top of line up to start col//~v74jR~
        if (rc=charfldedit(CHAROPEEOLIGM,//erase top of line up to start col(also oom)//~v74jI~
               plh->ULHdata,        //buffer                       //~v66fI~
               plh->ULHdbcs,        //buffer                       //~v66fI~
               Ppos1,           //current col                      //~v66fI~
               0,               //start col                        //~v66fI~
               ulhlen,         //end col                           //~v66fI~
               plh->ULHbufflen,     //buff len last                //~v66fI~
               Ppcw,                    //pcw                      //~v66fI~
               plh),rc)             //update ctr etc               //~v66fI~
            return rc;                                             //~v66fI~
    }                                                              //~v66fI~
    else                                                           //~v66fI~
    	if (Ppos1>ulhlen)                                          //~v66fI~
        	joinsw=0;                                              //~v66fI~
//midlle line process                                              //~v66fI~
    plh=Pplh2;                                                     //~v66fI~
    ulhlen=plh->ULHlen;                                            //~v66fR~
    if (Ppos1<=0)                                                  //~v66fI~
    {                                                              //~v66fI~
    	delplh1=Pplh1;                                             //~v66fI~
        sortplh1=0;  //capreset restore the fld when lcmddel called//~v66fR~
    }                                                              //~v66fI~
    else                                                           //~v66fI~
    	delplh1=UGETQNEXT(Pplh1);                                  //~v66fI~
    delplh2=0;  //when delplh1=0                                   //~vaf8I~
    if (Pplh1==Pplh2)   //single                                   //~v66fI~
    {                                                              //~v66fI~
	    if (Ppos1<=0)                                              //~v66fI~
    	    delplh2=delplh1;                                       //~v66fI~
        else                                                       //~v66fI~
        	delplh1=0;                                             //~v66fI~
    }                                                              //~v66fI~
	else	//multiline                                            //~v66fI~
    {                                                              //~v66fI~
    	if (Ppos2>ulhlen)	//eol delete                           //~v66fI~
        	delplh2=Pplh2;	//del last line                        //~v66fI~
        else                                                       //~v66fI~
            if (delplh1==Pplh2) //2 line                           //~v66fI~
            	delplh1=0;	//no line delete                       //~v66fI~
            else                                                   //~v66fI~
	        	delplh2=UGETQPREV(Pplh2);                          //~v66fR~
    }                                                              //~v66fI~
    if (delplh1)                                                   //~v66fI~
    {                                                              //~v66fI~
        nextplh=UGETQNEXT(delplh2);                                //~v66fM~
		if (lcmddel(Ppcw,delplh1,delplh2,1,1,1),rc)                //~v66fI~
                 //repeat=1,csr set req for all line delete case,UFHcmdline clear//~v66fI~
	        return rc;                                             //~v66fI~
        if (delplh2==Pplh2)                                        //~v66fI~
        	sortplh2=nextplh;                                      //~v66fR~
        *Ppplh1=sortplh1;                                          //~v66fI~
        *Ppplh2=sortplh2;                                          //~v66fI~
    }                                                              //~v66fI~
//last line process                                                //~v66fI~
	if (Pplh2!=Pplh1 && delplh2!=Pplh2)	//last not deleted         //~v66fR~
    {                                                              //~v66fI~
    	if (Ppos2>0)                                               //~v66fI~
        {                                                          //~v74pI~
//            spos=0;                                              //~v74qR~
//            if (UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file   //~v74qR~
//                if (Ppos2>SPFCOBNUMFLDLEN)                       //~v74qR~
//                    spos=SPFCOBNUMFLDLEN;                        //~v74qR~
//                else                                             //~v74qR~
//                    spos=-1;    //bypass ETOL                    //~v74qR~
//          if (spos>=0)                                           //~v74qR~
//  		if (rc=charfldedit(CHAROPETOL,//erase top of line up to start col//~v74qR~
    		if (rc=charfldedit(CHAROPETOLCOB,//erase top of line up to start col//~v74qI~
					   plh->ULHdata,		//buffer               //~v66fI~
					   plh->ULHdbcs,		//buffer               //~v66fI~
					   Ppos2,			//current col              //~v66fI~
//  				   0,         //start col                      //~v74pR~
//  				   spos,   //start col                         //~v74qR~
    				   0,         //start col                      //~v74qI~
					   ulhlen,			//end col                  //~v66fI~
					   plh->ULHbufflen,		//buff len last        //~v66fI~
					   Ppcw,		    		//pcw              //~v66fI~
					   plh),rc) 			//update ctr etc       //~v66fR~
            	return rc;                                         //~v66fI~
        }                                                          //~v74pI~
    }                                                              //~v66fI~
    if (delplh1!=Pplh1)                                            //~v66fI~
    	if (joinsw)	//eol deleted                                  //~v66fI~
          if (Pplh2->ULHtype==ULHTDATA) //if hdr pos=0;dont join to hdr line//~v66uI~
          {                                                        //~v74hI~
           if (Popt & CCR_SKIPJOIN)	//join bypass req
           {                                                       //~v74hI~
				if (Ppjoinrc)                                      //~v74hI~
    				*Ppjoinrc=1; 		//join bypassed            //~v74hI~
           }                                                       //~v74hI~
           else                                                    //~v74hI~
//      	rc=charlcmdjoin(Ppcw,Pplh1,UGETQNEXT(Pplh1));	//plh2!=0 requred for one undo//~v74iR~
        	rc=charlcmdjoin(CLJ_IGM,Ppcw,Pplh1,UGETQNEXT(Pplh1));	//ignore margin err plh2!=0 requred for one undo//~v74iR~
           }                                                       //~v74h~
	return rc;                                                     //~v66eI~
}//capcutregion                                                    //~v66eI~
//*******************************************************          //~v66eI~
//!capclear                                                        //~v66eI~
//* space clear block;   assumption:top and last is data line      //~v66eR~
//* parm1:pcw                                                      //~v66eI~
//* retrn:rc                                                       //~v66eI~
//*******************************************************          //~v66eI~
int capclearregion(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2)//~v66eI~
{                                                                  //~v66eI~
	PULINEH  plh,endplh;                                           //~v66eI~
	int rc,stepline,endpos,pos1;                                   //~v66eR~
//*******************                                              //~v66eI~
    endplh=getdisplayline(Pplh2,1,&stepline);                      //~v66eR~
  if (endplh)                                                      //~v70xI~
    endplh=UGETQPREV(endplh);                                      //~v66eI~
  else                                                             //~v70xI~
    endplh=Pplh2;                                                  //~v70xR~
    rc=0;                                                          //~v66eI~
	for (plh=Pplh1,pos1=Ppos1;plh;plh=UGETQNEXT(plh))              //~v66eR~
	{                                                              //~v66eI~
    	if (plh->ULHtype==ULHTDATA)                                //~v66eI~
        {                                                          //~v66eI~
            if (!plh->ULHdbcs)                                     //~v66eI~
                if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v66eI~
                    return UALLOC_FAILED;                          //~v66eI~
            endpos=plh->ULHlen;                                    //~v66eI~
            if (plh==endplh)    //last line                        //~v66eM~
    	        endpos=min(Ppos2,endpos);                          //~v66eI~
            if (endpos>0 && endpos>pos1)                           //~v66eR~
            {                                                      //~v66eI~
//              rc=charfldedit(CHAROPCTOL,//erase top of line up to start col//~v74eR~
                rc=charfldedit(CHAROPCTOLIM,//erase top of line up to start col//~v74eI~
                               plh->ULHdata,        //buffer       //~v66eI~
                               plh->ULHdbcs,        //buffer       //~v66eI~
                               endpos,              //current col  //~v66eI~
                               pos1,         //start col           //~v66eI~
                               plh->ULHlen,         //end col      //~v66eI~
                               plh->ULHbufflen,     //buff len last//~v66eI~
                               Ppcw,                    //pcw      //~v66eI~
                               plh);                //update ctr etc//~v66eI~
                if (rc)               	                           //~v66eI~
                	break;                                         //~v66eI~
            }                                                      //~v66eI~
        }//data line                                               //~v66eI~
        pos1=0;	//from top for 2nd line                            //~v66eI~
        if (plh==endplh)                                           //~v66eI~
        	break;                                                 //~v66eI~
	}//all plh                                                     //~v66eI~
	return rc;                                                     //~v66eI~
}//capclearregion                                                  //~v66eI~
//*******************************************************          //~v66fI~
//!capstdpaste                                                     //~v66fR~
//* standard paste; if target is block,copy cb in the block        //~v66fR~
//*                 if target is region,del regin and insert cb    //~v66fI~
//* parm1:pcw                                                      //~v66fI~
//* parm2:insert option 0- rep 1:insert                            //~v66fI~
//* retrn:rc                                                       //~v66fI~
//*******************************************************          //~v66fI~
int capstdpaste(PUCLIENTWE Ppcw,PULINEH Psortplh1,PULINEH Psortplh2,int Ppos1,int Ppos2,char Pstat1,char Pstat2)//~v66fI~
{                                                                  //~v66fI~
	PULINEH plhs1,plhs2,plht,plht1,plht2,plhs,endplh,plhlast,plhprev,plhcsr=0;//~v66fR~
//	int rc=0,stepline,mode,csrpos,linemodesw,swdelregion,cpos;     //~v66fR~//~vaf9R~
  	int rc=0,stepline,mode,csrpos=0,linemodesw,swdelregion,cpos;   //~vaf9I~
    int isrteolsw=0;                                               //~v66nI~
    int ovfcutctr=0;                                               //~v673I~
    char *pdata=NULL;                                                   //~v66fI~//~vaf9R~
    int swskipjoin=0,joinrc,opt;                                   //~v74hI~
    int pasteinsertdatasw=0;                                       //~v760I~
    PUFILEH pfh;                                                   //~v74qI~
#ifdef UTF8UCS2                                                    //~va20I~
    PUFILEH pfhcb;                                                 //~va20I~
    int optcap2;                                                   //~va20I~
#endif                                                             //~va20I~
    int handle;                                                    //~va7yI~
//*******************                                              //~v66fI~
#ifdef UTF8UCS2                                                    //~va2nI~
    if (Psortplh1)  //tgt rgn exist                                //~va2nI~
    {                                                              //~va2nI~
        plhprev=UGETQPREV(Psortplh1);   //for the case plht1 deleted//~va2nR~
        if (!plhprev)   //top hdr                                  //~va2nR~
        {                                                          //~va2nR~
            plhprev=Psortplh1;                                     //~va2nR~
            Psortplh1=UGETQNEXT(Psortplh1);                        //~va2nR~
        }                                                          //~va2nR~
    }                                                              //~va2nI~
#endif                                                             //~va2nI~
    swdelregion=0;     //delete rgn and paste,no target block/region//~v66fI~
    if (Gcappcw)                                                   //~v66fI~
    {                                                              //~v66fI~
		if (!UCBITCHK(Pstat1,SBLOCKCLOSED))	//block not closed     //~v66fI~
			return capnoblockerr();                                //~v66fM~
        if (Gcappcw==Ppcw)                                         //~v66fI~
        {                                                          //~v66fI~
			if (!UCBITCHK(Pstat1,SBLOCKSAVED))	//block/rgn saved,that is not target//~v66fI~
        		if (UCBITCHK(Pstat2,SBLOCK2STDREGION))	//after regin saved or at first//~v66fI~
        			swdelregion=1;	//parm to captstdpaste, target is region//~v66fR~
            	else                                               //~v66fI~
        			swdelregion=2;	//parm to captstdpaste, target is block//~v66fR~
            else                                                   //~v66fI~
		        capreset(1);	//clear reverse of copy source block//~v66fI~
        }                                                          //~v66fI~
    }                                                              //~v66fI~
	if (!capgetdata(Ppcw,&plhs1,&plhs2))	//get data plh         //~v66fR~
	{                                                              //~v66fI~
		uerrmsg("No clip board data",                              //~v66fI~
    			"\x93\\付データがありません");                     //~v66fI~
		return 4;                                                  //~v66fI~
	}                                                              //~v66fI~
#ifdef UTF8UCS2                                                    //~va20I~
	pfhcb=UGETPFH(plhs1);                                          //~va20I~
    if (FILEUTF8MODE(pfhcb))                                       //~va20I~
    	optcap2=CHARCAP2_SRCU8;                                    //~va20I~
    else                                                           //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (PFH_ISEBC(pfhcb))                                          //~va50I~
    {                                                              //~va7yI~
    	optcap2=CHARCAP2_SRCEB;                                    //~va50I~
        handle=pfhcb->UFHhandle;                                   //~va7yI~
        optcap2|=CHARCAP2_EBCHANDLEP|CHARCAP2_SETHANDLE(handle);   //~va7yI~
    }                                                              //~va7yI~
    else                                                           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	optcap2=CHARCAP2_SRCLC;                                    //~va20I~
#endif                                                             //~va20I~
	if (swdelregion==2)	//target is block                          //~v66fR~
    {                                                              //~v66fM~
		linemodesw=Ppos1<=0 && Ppos2<=0;                           //~v66fR~
        if (!linemodesw)                                           //~v66fI~
	        pdata=umalloc((UINT)((Ppos2-Ppos1)*2));                //~v66fR~
    	mode=CHAROPBREP;                                           //~v66fI~
	    endplh=getdisplayline(Psortplh2,1,&stepline); //next csr line//~v66fM~
	    for (plht=Psortplh1,plhs=plhs1;plht;plht=UGETQNEXT(plht))  //~v66fM~
        {                                                          //~v66fM~
        	if (plht==endplh)                                      //~v66fM~
            	break;                                             //~v66fM~
        	if (plht->ULHtype!=ULHTDATA)                           //~v66fM~
            	continue;                                          //~v66fM~
            if (linemodesw)                                        //~v66fI~
            {                                                      //~v66fI~
            	if (plhs->ULHlen||plht->ULHlen)                    //~v66fR~
                {                                                  //~v66fI~
		        	if (charcap(Ppcw,mode,plhs,plht,0)==UALLOC_FAILED)//~v66fR~
    	        		return UALLOC_FAILED;                      //~v66fR~
                	if (plhs->ULHlen<plht->ULHlen)                 //~v66fR~
                		plht->ULHlen=plhs->ULHlen;                 //~v66fR~
                }                                                  //~v66fI~
            }                                                      //~v66fI~
            else                                                   //~v66fI~
		        if (capstdpasteblockline(Ppcw,plht,plhs,Ppos1,Ppos2,pdata)==UALLOC_FAILED)//~v66fR~
    	        	return UALLOC_FAILED;                          //~v66fR~
            if (plhs==plhs2) 	//source plh exausted              //~v66fM~
            	break;                                             //~v66fM~
            plhs=UGETQNEXT(plhs);                                  //~v66fM~
        }                                                          //~v66fM~
        if (!linemodesw)                                           //~v66fI~
	        ufree(pdata);                                          //~v66fR~
		filesetcsr(Ppcw,Psortplh1,1,Ppos1);	//Ssortplh1 point prev line//~v66fI~
        uerrmsg("Std paste in Block",                              //~v66fI~
					"ブロック内への標準\x93\\付");                 //~v66fI~
        return 0;                                                  //~v66fI~
    }                                                              //~v66fM~
//target is region                                                 //~v66fI~
    plht1=Psortplh1;                                               //~v66fI~
    plht2=Psortplh2;                                               //~v66fI~
    if (swdelregion==1)    //not null rgn                          //~v66fR~
    {                                                              //~v66fI~
	    plhprev=UGETQPREV(plht1);	//for the case plht1 deleted   //~v66fI~
//      if (rc=capcutregion(Ppcw,&plht1,&plht2,Ppos1,Ppos2),rc)    //~v74hR~
//      opt=CCR_SKIPJOIN;//leave last line not to join             //~v74nR~
        opt=CCR_SKIPJOIN | CCR_SPLIT;//leave last line not to join,split if targetrgin is one line//~v74nR~
        if (rc=capcutregion(opt,Ppcw,&plht1,&plht2,Ppos1,Ppos2,&joinrc),rc)//~v74hI~
            return rc;                                             //~v66fR~
		swskipjoin=(joinrc==1);		//join bypassed by request     //~v74hI~
        cpos=Ppos1;                                                //~v66fI~
    }                                                              //~v66fI~
	else					//no target region to delete           //~v66fI~
    {                                                              //~v66fI~
    	if (capgetpoint(Ppcw,&plht1,&cpos))                        //~v66fR~
	  		return errcsrpos();                                    //~v66fI~
        if (cpos<0) //on lineno fld                                //~v66fI~
        {                                                          //~v66nI~
            cpos=0;                                                //~v66fI~
            isrteolsw=1;                                           //~v66nI~
        }                                                          //~v66nI~
        else                                                       //~v760I~
        {                                                          //~v760I~
    		if ((plhs1==plhs2)                                     //~v760I~
			&& !plhs2->ULHeolid	//1line with no eol                //~v760I~
	    	&& plhs1->ULHlen                                       //~v760I~
            )                                                      //~v760I~
	    		pasteinsertdatasw=1;		//call insert paste    //~v760I~
        }                                                          //~v760I~
        if (!plht1 || plht1->ULHtype!=ULHTDATA)	//on hdr or EXCLUDE line//~v66fI~
	  		return errcsrpos();                                    //~v66fI~
	    plhprev=UGETQPREV(plht1);	//for the case plht1 deleted   //~v66fI~
        if (!plhprev)				//Ctl+v on top hdr line        //~v66fI~
	  		return errcsrpos();                                    //~v66fI~
    	pfh=UGETPFH(plht1);                                        //~v74qR~
	    if (UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file         //~v74qI~
        {                                                          //~v74qI~
        	if (cpos>0 && cpos<SPFCOBNUMFLDLEN)                    //~v74qI~
            	return errcsrpos();                                //~v74qI~
        }                                                          //~v74qI~
    }                                                              //~v66fI~
    if (plht1 && cpos<=plht1->ULHlen)	//top not deleted and may split//~v66fR~
    {                                                              //~v66fI~
	 if (pasteinsertdatasw)		//1 line insert w/o eol into the target line//~v760I~
     {                                                             //~v760I~
    	mode=CHAROPBINS|CHARCAP2_UNDO|CHARCAP2_OVFCUT|CHARCAP2_IGNOVFSPC;	//no rc=1 if overflow cut is all space//~v760I~
#ifdef UTF8UCS2                                                    //~va20I~
		mode|=optcap2;                                             //~va20I~
#endif                                                             //~va20I~
    	if (rc=charcap2(Ppcw,mode,plhs1->ULHdata,plhs1->ULHdbcs,plhs1->ULHlen,plht1,cpos),rc)//~v760R~
        {                                                          //~v760I~
    		pfh=UGETPFH(plht1);                                    //+vaf9I~
        	if (rc>1)     //rc==1:over flow is tab and space only  //~v760I~
	        	return charmaxovererr(pfh->UFHmergin);             //~v760R~
            ovfcutctr++;                                           //~v760I~
	        rc=0;                                                  //~v760I~
        }                                                          //~v760I~
        plhlast=0;  //no join last                                 //~v760I~
        plhcsr=plht1;                                              //~v760I~
        csrpos=cpos;                                               //~v760I~
     }                                                             //~v760I~
     else                                                          //~v760I~
     {                                                             //~v760I~
      if (!swskipjoin)	//target is region and                     //~v74hI~
      {                                                            //~v74hI~
//  	if (rc=charlcmdsplit(Ppcw,plht1,cpos),rc) 	//split top line//~v74jR~
//  	if (rc=charlcmdsplit(CLS_IGM,Ppcw,plht1,cpos),rc) 	//split top line//~v74jR~
    	if (rc=charlcmdsplit(CLS_IGM,Ppcw,plht1,cpos),rc) 	//split top line//~v74jI~
        	return rc;                                             //~v66fM~
      }                                                            //~v74hI~
//      if (cpos)                                                  //~v74vR~
        if (cpos||swskipjoin)   //not splitted topline(capcut split at pos2-->topline is plht1)//~v74vI~
        {                                                          //~v66fI~
	        plhlast=plht1;	//join plh                             //~v66fR~
			csrpos=cpos;                                           //~v66fR~
        }                                                          //~v66fI~
        else                    //if pos=0 len=0 line is inserted after prev line//~v66fI~
        {                                                          //~v66fI~
        	plhlast=UGETQPREV(plht1);                              //~v66fR~
            csrpos=0;                                              //~v66fI~
        }                                                          //~v66fI~
        plhcsr=plhlast;                                            //~v66fI~
	    if (plhs1->ULHlen)                                         //~v66fI~
    	{                                                          //~v66fI~
//  		mode=CHAROPBINS|CHARCAP2_UNDO|CHARCAP2_OVFCUT;         //~v673R~
    	    mode=CHAROPBREP|CHARCAP2_UNDO|CHARCAP2_OVFCUT;         //~v673I~
    	    mode|=CHARCAP2_IGNOVFSPC;	//no rc=1 if overflow cut is all space//~v676R~
#ifdef UTF8UCS2                                                    //~va20I~
			mode|=optcap2;                                         //~va20I~
#endif                                                             //~va20I~
    		if (rc=charcap2(Ppcw,mode,plhs1->ULHdata,plhs1->ULHdbcs,plhs1->ULHlen,plhlast,cpos),rc)//~v66fR~
            {                                                      //~v673I~
              if (rc>1)                                            //~v673I~
	        	return rc;                                         //~v66fI~
              ovfcutctr++;                                         //~v673I~
	          rc=0;                                                //~v673I~
            }                                                      //~v673I~
    	}                                                          //~v66fI~
     }//!pasteinsertdatasw                                         //~v760I~
        if (plhs2==plhs1)                                          //~v66fI~
            plhs=0; //no more source line                          //~v66fI~
        else                                                       //~v66fI~
	        plhs=UGETQNEXT(plhs1);	//get next sourceline          //~v66fR~
    }                                                              //~v66fI~
    else                                                           //~v66fI~
    {                                                              //~v66fI~
    	if (plht1)                                                 //~v66fI~
	    	plhlast=plht1;                                         //~v66fR~
        else                //top deleted                          //~v66fI~
        	plhlast=plhprev;                                       //~v66fI~
    	plhs=plhs1;                                                //~v66fI~
    }                                                              //~v66fI~
    for (plht=plhlast;plhs;plhs=UGETQNEXT(plhs))                   //~v66fR~
    {                                                              //~v66fR~
    	if (!plhcsr)                                               //~v66fI~
        {                                                          //~v66fI~
        	plhcsr=plht;                                           //~v66fI~
            csrpos=0;                                              //~v66fI~
        }                                                          //~v66fI~
        if (rc=lcmdisrt(Ppcw,plht,1,0),rc) //repeat=1,indent=0     //~v66fR~
            return rc;                                             //~v66fR~
        plht=UGETQNEXT(plht);   //inserted line                    //~v66fR~
        plhlast=plht;			//join plh                         //~v66fI~
        mode=CHAROPBREP|CHARCAP2_UNDO|CHARCAP2_OVFCUT;             //~v66fR~
    	mode|=CHARCAP2_IGNOVFSPC;	//no rc=1 if overflow cut is all space//~v676I~
#ifdef UTF8UCS2                                                    //~va20I~
		mode|=optcap2;                                             //~va20I~
#endif                                                             //~va20I~
        if (rc=charcap2(Ppcw,mode,plhs->ULHdata,plhs->ULHdbcs,plhs->ULHlen,plht,0),rc)//~v66fR~
        {                                                          //~v673I~
          if (rc>1)                                                //~v673I~
            return rc;                                             //~v66fR~
          ovfcutctr++;                                             //~v673I~
          rc=0;                                                    //~v673I~
        }                                                          //~v673I~
        if (plhs==plhs2)                                           //~v66fI~
        	break;                                                 //~v66fI~
    }                                                              //~v66fR~
    if (plhlast)	//join plh                                     //~v66fI~
    {                                                              //~v66nI~
      if (!isrteolsw)	//csr not on lineno fld                    //~v66nI~
	    if (!plhs2->ULHeolid)	//last has no eol                  //~v66fI~
        {                                                          //~v66fI~
//			rc=charlcmdjoin(Ppcw,plhlast,UGETQNEXT(plhlast));      //~v74iR~
    		rc=charlcmdjoin(CLJ_IGM,Ppcw,plhlast,UGETQNEXT(plhlast));//~v74iR~
            if (!rc)                                               //~v66fI~
            	UCBITON(plhlast->ULHflag,ULHFCURCAP);	//recover paste reverse//~v66fI~
            else                                                   //~v673I~
              	if (ovfcutctr)                                     //~v673I~
                	uerrmsg("Last line left splitted by margin limit(intermediate %d lines are are cut)",//~v673I~
                    	    "最後の行がマージン制限のため分割されました。(途中 %d 行がマージン溢れでカット)",//~v673R~
                        	ovfcutctr);                            //~v673I~
              	else                                               //~v673I~
                	uerrmsg("Last line left splitted by margin limit.",//~v673I~
                    	    "最後の行がマージン制限のため分割されました。");//~v673I~
        }                                                          //~v66fI~
    }                                                              //~v66nI~
    if (plhcsr)                                                    //~v66fI~
		filesetcsr(Ppcw,plhcsr,1,csrpos);	//Ssortplh1 point prev line//~v66fI~
    if (!rc)                                                       //~v66fI~
    {                                                              //~v676I~
      if (ovfcutctr)                                               //~v673I~
      {                                                            //~v673I~
		uerrmsg("%d margin overflow lines are cut",                //~v673I~
				"%d 行がマージン溢れでカットされました",           //~v673R~
				ovfcutctr);                                        //~v673I~
        rc=1;                                                      //~v673I~
      }                                                            //~v673I~
      else                                                         //~v673I~
		uerrmsg("Std Paste",                                       //~v66fI~
				"標準\x93\\付");                                   //~v66fI~
    }                                                              //~v676I~
	return rc;                                                     //~v66fI~
}//capstdpaste                                                     //~v66fI~
//*******************************************************          //~v66fI~
//!capstdpasteblockline                                            //~v66fI~
//* std paste one block line                                       //~v66fI~
//* retrn:rc                                                       //~v66fI~
//*******************************************************          //~v66fI~
int capstdpasteblockline(PUCLIENTWE Ppcw,PULINEH Pplht,PULINEH Pplhs,int Ppos1,int Ppos2,char *Pwork)//~v66fR~
{                                                                  //~v66fI~
	char *pdbcs,*pdata,*pc,*pcd;                                   //~v66fR~
    int boxw,lens,lent,addlen,mode,rc,ii,lens0;                    //~v66fR~
#ifdef UTF8UCS2                                                    //~va20I~
    PUFILEH pfhcb;                                                 //~va20I~
    int optcap2;                                                   //~va20I~
#endif                                                             //~va20I~
    int handle;                                                    //~va7yI~
//**************************                                       //~v66fI~
#ifdef UTF8UCS2                                                    //~va20I~
	pfhcb=UGETPFH(Pplhs);                                          //~va20I~
    if (FILEUTF8MODE(pfhcb))                                       //~va20I~
    	optcap2=CHARCAP2_SRCU8;                                    //~va20I~
    else                                                           //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (PFH_ISEBC(pfhcb))                                          //~va50I~
    {                                                              //~va7yI~
    	optcap2=CHARCAP2_SRCEB;                                    //~va50I~
        handle=pfhcb->UFHhandle;                                   //~va7yI~
        optcap2|=CHARCAP2_EBCHANDLEP|CHARCAP2_SETHANDLE(handle);   //~va7yI~
    }                                                              //~va7yI~
    else                                                           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	optcap2=CHARCAP2_SRCLC;                                    //~va20I~
#endif                                                             //~va20I~
	boxw=Ppos2-Ppos1;                                              //~v66fM~
    pdata=Pwork;                                                   //~v66fI~
    pdbcs=Pwork+boxw;                                              //~v66fI~
    lent=Pplht->ULHlen;                                            //~v66fR~
    lens=lens0=Pplhs->ULHlen;                                      //~v66fR~
    lens=min(boxw,lens);                                           //~v66fI~
    if (lens)                                                      //~v66fI~
    {                                                              //~v66fI~
    	memcpy(pdata,Pplhs->ULHdata,(UINT)lens);                   //~v66fI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (PFH_ISEBC(pfhcb))                                        //~va50I~
    	memcpy(pdbcs,Pplhs->ULHdbcs,(UINT)lens);                   //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
      {                                                            //~va50I~
        for (ii=0,pc=Pplhs->ULHdbcs,pcd=pdbcs;ii<lens;ii++,pc++,pcd++)//~v66uR~
        	if (*pc==TABCHAR||*pc==TABPADCHAR)                     //~v66fI~
		   	 	*pcd=0;		//tab clear to keep line width         //~v66fI~
            else                                                   //~v66fI~
		   	 	*pcd=*pc;                                          //~v66fR~
        if (boxw<lens0)  //source is cut                           //~v66fR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	        xesub_setdbcssplit(0,0,pdata,pdbcs,lens,' '); //set space for dbcs split//~va50R~
#else                                                              //~va50I~
	        setdbcssplit(pdata,pdbcs,lens,' '); //set space for dbcs split//~v66fR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
      }                                                            //~va50I~
    }                                                              //~v66fI~
    if (lens<boxw)  //padd space required                          //~v66fR~
    {                                                              //~v66fI~
        if (lent>=Ppos2)                                           //~v66fI~
            addlen=boxw-lens;                                      //~v66fI~
        else                                                       //~v66fI~
        	addlen=lent-Ppos1-lens;                                //~v66fI~
        if (addlen>0)                                              //~v66fI~
        {                                                          //~v66fI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	    	UCVEBC_memset_space((optcap2 & CHARCAP2_SRCEB),pdata+lens,(UINT)addlen);//~va50I~
#else                                                              //~va50I~
	    	memset(pdata+lens,' ',(UINT)addlen);                   //~v66fR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	    	memset(pdbcs+lens,0  ,(UINT)addlen);                   //~v66fR~
	        lens+=addlen;                                          //~v66fI~
        }                                                          //~v66fI~
    }                                                              //~v66fI~
    if (lens)                                                      //~v66fI~
    {                                                              //~v66fI~
    	mode=CHAROPBREP|CHARCAP2_UNDO|CHARCAP2_OVFCUT;             //~v66fI~
#ifdef UTF8UCS2                                                    //~va20I~
		mode|=optcap2;                                             //~va20I~
#endif                                                             //~va20I~
    	if (rc=charcap2(Ppcw,mode,pdata,pdbcs,lens,Pplht,Ppos1),rc)//~v66fI~
        	return rc;                                             //~v66fI~
    }                                                              //~v66fI~
    return 0;                                                      //~v66fI~
}//capstdpasteblockline                                            //~v66fI~
#ifdef UTF8UCS2                                                    //~va2nI~
//*******************************************************          //~va20I~
//!capcbstat                                                       //~va20I~
//* ctl ::cb file status                                           //~va20I~
//* retrn:rc                                                       //~va20I~
//*******************************************************          //~va20I~
//ULONG capcbstatr(int Popt,PUCLIENTWE Ppcw)                         //~va20R~//~va79R~
ULONG capcbstatr(int Popt,PUCLIENTWE Ppcw,PCBSTAT Pcbsrec)         //~va79I~
{                                                                  //~va20I~
	ULONG cbstat=0;                                                //~va20R~
    char cbsfnm[32];                                               //~va20R~
    char fpath[_MAX_PATH];                                         //~va20I~
    FILE *fh;                                                      //~va20I~
//**************************                                       //~va20I~
    sprintf(cbsfnm,"%s",CLIPBOARDID "_stat");                      //~va20R~
    filefullpath(fpath,cbsfnm,_MAX_PATH);                          //~va20I~
	if (fh=fopen(fpath,"rb"),!fh)                                  //~va20R~
    {                                                              //~va20R~
        uerrmsg("::cb status file(%s) not found",0,                //~va20R~
                    fpath);                                        //~va20R~
    }                                                              //~va20R~
    else                                                           //~va20R~
    {                                                              //~va20R~
//      fread(&cbstat,1,sizeof(cbstat),fh);                        //~va20R~//~va79R~
		memset(Pcbsrec,0,CBSTATSZ);                                //~va79I~
        fread(Pcbsrec,1,CBSTATSZ,fh);                              //~va79R~
        cbstat=Pcbsrec->CBSTstat;                                  //~va79I~
        fclose(fh);                                                //~va20R~
    }                                                              //~va20R~
    return cbstat;                                                 //~va20R~
}//capcbstatr                                                      //~va20R~
//*******************************************************          //~va20I~
//!capcbstat                                                       //~va20I~
//* ctl ::cb file status                                           //~va20I~
//* retrn:rc                                                       //~va20I~
//*******************************************************          //~va20I~
int capcbstatw(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)              //~va20R~
{                                                                  //~va20I~
	ULONG cbstat=0;                                                //~va20I~
    CBSTAT cbsrec;                                                 //~va79I~
    char cbsfnm[32];                                               //~va20I~
    char fpath[_MAX_PATH];                                         //~va20I~
    FILE *fh;                                                      //~va20I~
    int rc=0;                                                      //~va20I~
    int handle;                                                    //~va79I~
    char *pcvname;                                                 //~va79I~
//**************************                                       //~va20I~
    sprintf(cbsfnm,"%s",CLIPBOARDID "_stat");                      //~va20R~
    filefullpath(fpath,cbsfnm,_MAX_PATH);                          //~va20I~
    if (fh=fopen(fpath,"wb"),!fh)                                  //~va20I~
    {                                                              //~va20I~
        uerrmsg("::cb status file(%s) output open failed",0,       //~va20I~
                    fpath);                                        //~va20I~
        rc=4;                                                      //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    {                                                              //~va20I~
        handle=0;                                                  //~va79R~
    	if (FILEUTF8MODE(Ppfh))                                    //~va20I~
        	cbstat|=CCBSTF_CPU8;//        //::cb status cpu8       //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        else                                                       //~va50I~
    	if (PFH_ISEBC(Ppfh))                                       //~va50I~
        {                                                          //~va79I~
        	cbstat|=CCBSTF_CPEB;//        //::cb status cpu8       //~va50I~
            handle=Ppfh->UFHhandle;                                //~va79I~
            cbstat|=CCBSTF_SETHANDLE(handle);                      //~va79I~
        }                                                          //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//      fwrite(&cbstat,1,sizeof(cbstat),fh);                       //~va20R~//~va79R~
        memset(&cbsrec,0,sizeof(cbsrec));                          //~va79R~
        cbsrec.CBSTstat=cbstat;                                    //~va79I~
        if (handle)                                                //~va79I~
        {                                                          //~va79I~
            pcvname=ucvebc4_getcvname(0,handle);                   //~va79I~
            if (pcvname)                                           //~va79I~
                memcpy(cbsrec.CBSTcvname,pcvname,strlen(pcvname)); //~va79I~
        }                                                          //~va79I~
//      fwrite(&cbstat,1,sizeof(cbstat),fh);                       //~va79R~
        fwrite(&cbsrec,1,sizeof(cbsrec),fh);                       //~va79I~
        fclose(fh);                                                //~va20I~
    }                                                              //~va20I~
    return rc;                                                     //~va20I~
}//capcbstatw                                                      //~va20R~
#endif                                                             //~va2nI~
//*******************************************************          //~v66eI~
int caperrregionmode(void)                                         //~v66eI~
{                                                                  //~v66eI~
//*******************                                              //~v66eI~
    uerrmsg("Not Avail for Region specified Cut & Paste",          //~v66eI~
            "領域指定のときはできません");                         //~v66eI~
    return 4;                                                      //~v66eI~
}//caperrregionmode                                                //~v66fR~
