//*CID://+vb2ER~:                             update#=   63;       //+vb2ER~
//*************************************************************
//*xelcmd5.c
//* lcmd "="(compare) "!"(exec cmd)                                //~v62JR~
//*************************************************************
//vb2E:160229 LNX64 compiler warning                               //+vb2EI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vb2C:160221 W32 compiler warning                                 //~vb2CI~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va70:000701 LP64 option support                                  //~va70I~
//va6w:000627 lcmd comp("=") support among locale,utf8 and ebc file//~va6wI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            lcmd5.c :dd2f for # lcmd from utf8 file              //~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va04:090606 expand cmdbuff to include edit cmd for the file with _max_path//~va04I~
//v77K:080205 EXE cmd support parameter file EXE ___ [< { wildcard[{[p][f]}] | @filename} ]//~v77KI~
//v762:070529 (BUG)lcmd compare,in correct errmsg(not compared line exist) when reached to eof.//~v762I~
//v74Q:070328 (BUG)should reverse 2 column by lcmd comp for DBCS 2nd byte unmatch//~v74QI~
//v74P:070325*BNDS support for "=" lcmd                            //~v74PI~
//v74M:070328 lcmd lower support                                   //~v74MI~
//v74L:070325 BNDS support for upper lcmd                          //~v74LI~
//v745:070209 (BUG)lcmd matching err csr postion err when UFCleft!=0//~v745R~
//v729:061120 (BUG)line compair unmatch when compare margined an not margined file//~v729I~
//v69L:060713 cap(CAPS LOCK On) support;add "U" lcmd(uppercase translation)//~v69LI~
//v62J:050413 new lcmd(!):execute cmd on the line                  //~v62JI~
//v497:020617 TC cmd new operation "=="(sting compare)             //~v497I~
//v0k3:981011 "=" lcmd(compare line)
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <uque.h>
#include <ustring.h>
#include <ufile.h>
#ifdef UTF8SUPPH                                                   //~va1qI~
#include <udbcschk.h>                                              //~va04I~
#endif                                                             //~va1qI~
#ifdef UTF8UCS2                                                    //~va20I~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20I~
#include <ucvext.h>                                                //~va70I~
#include <ucvebc.h>                                                //~va50I~
#include <ucvebc4.h>                                               //~va70I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile2.h"
#include "xefile42.h"                                              //~v69LI~
#include "xefile6.h"
#include "xeundo.h"
#include "xelcmd.h"
#include "xelcmd2.h"                                               //~v62JI~
#include "xelcmd4.h"                                               //~v62JI~
#include "xelcmd5.h"
#include "xeerr.h"
#include "xefunc2.h"                                               //~v62JI~
#include "xefsub.h"                                                //~v69LI~
#include "xefcmd23.h"                                              //~v74LI~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xesub.h"                                                 //~va04I~
#include "xesub2.h"                                                //~va04R~
#endif                                                             //~va1qI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xeutf2.h"                                                //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
#include "xeutf.h"                                                 //~va6wI~
//*******************************************************
static int Slowersw=0;                                             //~v74MI~
//*******************************************************
//int lcmdcomp(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,PULINEH Pplh1stop,PULINEH Pplh2stop,//~va7xR~
int lcmdcomp(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,PULINEH Pplh1stop,PULINEH Pplh2stop,//~va7xI~
             int Prepeat1,int Prepeat2,int Pbandle1,int Pbandle2,int Pskip1,int Pskip2);
#define LCCMPO_BIN  0x01   //binary mode compare                   //~va7xR~
int lcmduppersub(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,int Ppos);//~v69LR~
//void lcmdunmatch(int Poffs,int P1stsw,PULINEH Pplh1,PULINEH Pplh2,//~v497R~
//                    PUFILEH Ppfh1,PUFILEH Ppfh2,int Punmathlen); //~v497R~
//****************************************************************
// paircmd
// process pair cmd(copy/move)
//*rc   :0
//****************************************************************
int lcmdpairs(PUCLIENTWE Ppcw,ULCMD *Pplcc,ULCMD *Pplcd)
{
	ULCMD   *plcr1,*plcr2;
	PULINEH plh1,plh2,plh1stop,plh2stop;
	int rc;                                                        //~v0k3R~
    int bandle1,bandle2,skip1,skip2,repeat1,repeat2,bssw1=0,bssw2=0;
    int optcmp;                                                    //~va7xI~
//*******************
	plh1=Pplcc->ULCplh;
	plcr1=Pplcc->ULCplcrange;	//range pair
	plh2=Pplcd->ULCplh;
	plcr2=Pplcd->ULCplcrange;	//range pair
    optcmp=0;                                                      //~va7xI~
    if (UCBITCHK(Pplcc->ULCflag3,ULCF3BIN)	//binmode copy         //~va7xI~
    ||  UCBITCHK(Pplcd->ULCflag3,ULCF3BIN)    //binmode copy       //~va7xI~
    ||  (plcr1 && UCBITCHK(plcr1->ULCflag3,ULCF3BIN))    //binmode copy//~va7xR~
    ||  (plcr2 && UCBITCHK(plcr2->ULCflag3,ULCF3BIN))   //binmode copy//~va7xR~
    )                                                              //~va7xI~
    	optcmp|=LCCMPO_BIN;                                        //~va7xI~
//default repeat
    repeat1=Pplcc->ULCrepeat;
    repeat2=Pplcd->ULCrepeat;
    bandle1=Pplcc->ULCband;                                        //~v0k3M~
    bandle2=Pplcd->ULCband;                                        //~v0k3M~
    skip1  =Pplcc->ULCskip;                                        //~v0k3M~
    skip2  =Pplcd->ULCskip;                                        //~v0k3M~
    if (plcr1)
    {                                                              //~v0k3I~
        plh1stop=plh1;                                             //~v0k3I~
        plh1    =plcr1->ULCplh;                                    //~v0k3I~
    	repeat1=max(repeat1,plcr1->ULCrepeat);
		bandle1=max(bandle1,plcr1->ULCband);                       //~v0k3M~
		skip1  =max(skip1  ,plcr1->ULCskip);                       //~v0k3M~
    }                                                              //~v0k3I~
	else                                                           //~v0k3M~
        plh1stop=0;                                                //~v0k3M~
    if (plcr2)
    {                                                              //~v0k3I~
        plh2stop=plh2;                                             //~v0k3I~
        plh2    =plcr2->ULCplh;                                    //~v0k3I~
    	repeat2=max(repeat2,plcr2->ULCrepeat);
		bandle2=max(bandle2,plcr2->ULCband);                       //~v0k3M~
		skip2  =max(skip2  ,plcr2->ULCskip);                       //~v0k3M~
    }                                                              //~v0k3I~
	else                                                           //~v0k3M~
        plh2stop=0;                                                //~v0k3M~
//if repaet=0,do infinite except both is ctr and 0                 //~v0k3R~
    if (!repeat1)                                                  //~v0k3I~
        repeat1=-1;     //infinite id                              //~v0k3I~
    if (!repeat2)                                                  //~v0k3I~
        repeat2=-1;     //infinite id                              //~v0k3R~
    if (!plcr1 && !plcr2)     //ctr1+ctr2                          //~v0k3I~
	    if (repeat1==-1 && repeat2==-1)	//both ctr=0               //~v0k3R~
	        repeat1=repeat2=1;                                     //~v0k3R~
//if no parm,copy bandle and skip                                  //~v0k3I~
	if (repeat1<=0 && !bandle1 && !skip1)                          //~v0k3R~
    {                                                              //~v0k3I~
    	bandle1=bandle2;                                           //~v0k3I~
    	skip1  =skip2;                                             //~v0k3I~
    }                                                              //~v0k3I~
	if (repeat2<=0 && !bandle2 && !skip2)                          //~v0k3R~
    {                                                              //~v0k3I~
    	bandle2=bandle1;                                           //~v0k3I~
    	skip2  =skip1;                                             //~v0k3I~
    }                                                              //~v0k3I~
//*default bandle/skip
    if (skip1 || bandle1)
    {
    	bssw1=1;
		if (!bandle1)
        	bandle1=1;		//default for source
		if (!skip1)
        	skip1=1;     	//default for source
	}
    if (skip2 || bandle2)
    {
    	bssw2=1;
		if (!bandle2)
        	bandle2=1;		//default for source
		if (!skip2)
        	skip2=1;     	//default for source
	}
    if (bssw1||bssw2)
    	uerrmsg("%d,%d.%d%c%d,%d.%d; ",0,                          //~v0k3R~
                repeat1,bandle1,skip1,                             //~v0k3R~
                Pplcd->ULCcmd,repeat2,bandle2,skip2);
    else                                                           //~v0k3I~
        ugeterrmsg();//clear pending meg                           //~v0k3R~

//  rc=lcmdcomp(Ppcw,plh1,plh2,plh1stop,plh2stop,                  //~va7xR~
    rc=lcmdcomp(optcmp,Ppcw,plh1,plh2,plh1stop,plh2stop,           //~va7xI~
				repeat1,repeat2,bandle1,bandle2,skip1,skip2);

	return rc;
}//lcmdpairs
//****************************************************************
// lcmdcomp
// line compair
//  parm1:PUCLIENTWE
//  parm2:range1 plc
//  parm3:range2 plc
//  parm4:range count1
//  parm5:range count2
//  parm6:bandle1
//  parm7:bandle2
//  parm8:skip1
//  parm9:skip2
//*rc   :0
//****************************************************************
//int lcmdcomp(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,PULINEH Pplh1stop,PULINEH Pplh2stop,//~va7xR~
int lcmdcomp(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,PULINEH Pplh1stop,PULINEH Pplh2stop,//~va7xI~
             int Prepeat1,int Prepeat2,int Pbandle1,int Pbandle2,int Pskip1,int Pskip2)
{
    PULINEH plh1,plh2,plh1err=0,plh2err=0;                         //~v0k3R~
	PUFILEH pfh1,pfh2,pfhc;                                        //~v0k3R~
	PUFILEC pfc;                                                   //~v745R~
	UCHAR *pc1,*pc2,*pcd1,*pcd2;
	UCHAR *pc1e,*pc2e;                                             //~va6wI~
	int bssw1,bssw2;		//bandle used sw
    int mergin1,mergin2,repeat1,repeat2;
    int len1,len2,eof1,eof2;                                       //~v0k3R~
    int rc,ii,jj,compctr,nextsw=0,unmatchctr;                        //~v0k3R~//~vaf9R~
    int skip1,skip2,bandle1,bandle2;
    int mrginfsw,complen,unmatchsw;                                //~v0k3R~
    int ii2,f1bndsoffs1,f1bndsoffs2,f2bndsoffs1,f2bndsoffs2,shortreccompsw=0;//~v74PR~
    int swutf8file1,swutf8file2,swebcfile1,swebcfile2,ii2cvcomp,opt,pos1,pos2;//~va6wR~
    int handle;                                                    //~va79I~
    int swbinmode,handle1,handle2;                                 //~va7xR~
//****************
	swbinmode=Popt & LCCMPO_BIN;                                   //~va7xI~
//  pfhc=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;	//current pfh          //~v745R~
    pfc=Ppcw->UCWpfc;	//current pfh                              //~v745I~
	pfhc=pfc->UFCpfh;	//current pfh                              //~v745I~
	bssw1=Pbandle1||Pskip1;
	bssw2=Pbandle2||Pskip2;
	plh1=Pplh1;
    pfh1=UGETPFH(plh1);
	plh2=Pplh2;
    pfh2=UGETPFH(plh2);
    swutf8file1=FILEUTF8MODE(pfh1);                                //~va6wI~
    swutf8file2=FILEUTF8MODE(pfh2);                                //~va6wI~
    swebcfile1=PFH_ISEBC(pfh1);                                    //~va6wI~
    swebcfile2=PFH_ISEBC(pfh2);                                    //~va6wI~
    handle1=pfh1->UFHhandle;                                       //~va7xI~
    handle2=pfh2->UFHhandle;                                       //~va7xI~
    if (swbinmode)                                                 //~va7xI~
    	if (swutf8file1||swutf8file2)                              //~va7xR~
        {                                                          //~va7xI~
        	errnotsupported("Binary mode compare","UTF8 file");    //~va7xI~
            return 1;   //treate as pendig to keep alive           //~va7xI~
        }                                                          //~va7xI~
//*comp len
    mrginfsw=0;                                                    //~v0k3R~
    if (UCBITCHK(pfh1->UFHflag2,UFHF2MERGIN))	//sof ok           //~v0k3R~
    {                                                              //~v0k3I~
        mrginfsw++;                                                //~v0k3R~
	    mergin1=pfh1->UFHmergin;		//chk inmargin
    }                                                              //~v0k3I~
    else
    	mergin1=0;						//full lrecl chk
//*
    if (UCBITCHK(pfh2->UFHflag2,UFHF2MERGIN))	//sof ok           //~v0k3I~
    {                                                              //~v0k3I~
        mrginfsw++;                                                //~v0k3R~
	    mergin2=pfh2->UFHmergin;		//chk inmargin
    }                                                              //~v0k3I~
    else
    	mergin2=0;						//full lrecl chk
//  if (mrginfsw!=2)                                               //~v74PR~
//      mrginfsw=0;                                                //~v74PR~
    if (mrginfsw==2)                                               //~v74PI~
        shortreccompsw=1; //if both is marged,shortrec match with space in margin//~v74PR~
    if ((f1bndsoffs1=pfh1->UFHbndscol1-1)<0)                       //~v74PR~
    	f1bndsoffs1=0;                                             //~v74PI~
    if ((f1bndsoffs2=pfh1->UFHbndscol2)>0)                         //~v74PI~
    {                                                              //~v74PI~
    	mergin1=f1bndsoffs2;						//full lrecl chk//~v74PI~
        mrginfsw++;                                                //~v74PI~
    }                                                              //~v74PI~
    if ((f2bndsoffs1=pfh2->UFHbndscol1-1)<0)                       //~v74PR~
    	f2bndsoffs1=0;                                             //~v74PI~
    if ((f2bndsoffs2=pfh2->UFHbndscol2)>0)                         //~v74PI~
    {                                                              //~v74PI~
    	mergin2=f2bndsoffs2;						//full lrecl chk//~v74PI~
        mrginfsw++;                                                //~v74PI~
    }                                                              //~v74PI~
//*all line loop
	eof1=0; eof2=0;
    repeat1=Prepeat1;                                              //~v0k3R~
	repeat2=Prepeat2;                                              //~v0k3I~
    bandle1=Pbandle1;                                              //~v0k3R~
    bandle2=Pbandle2;                                              //~v0k3R~
    skip1=0;                                                       //~v0k3I~
    skip2=0;                                                       //~v0k3I~
    compctr=0;
    unmatchctr=0;
	for (;;)
	{
		for (;;)
        {						//continue loop for main loop
        	rc=0;
//*skip not concerned line
	        if (plh1->ULHtype!=ULHTDATA
    	    ||  UCBITCHK(plh1->ULHflag2,ULHF2EXCLUDED))
            {
                if (plh2->ULHtype!=ULHTDATA                        //~v762I~
                ||  UCBITCHK(plh2->ULHflag2,ULHF2EXCLUDED))        //~v762I~
                {                                                  //~v762I~
                    nextsw=0;   //both skip line                   //~v762I~
                    break;                                         //~v762I~
                }                                                  //~v762I~
                nextsw=-1;   //next plh1 line
                break;
            }
	        if (plh2->ULHtype!=ULHTDATA                            //~v0k3R~
    	    ||  UCBITCHK(plh2->ULHflag2,ULHF2EXCLUDED))            //~v0k3R~
            {
                nextsw=1;   //next plh2 line
                break;
            }
//*bypass skip range                                               //~v0k3R~
            if (bssw1)                                             //~v0k3I~
                if (skip1)                                         //~v0k3I~
                {                                                  //~v0k3I~
                    if (!(--skip1))                                //~v0k3I~
                        bandle1=Pbandle1;                          //~v0k3I~
                    nextsw=-1;      //next of plh1                 //~v0k3I~
                    break;      //skip process                     //~v0k3I~
                }                                                  //~v0k3I~
            if (bssw2)                                             //~v0k3I~
                if (skip2)                                         //~v0k3I~
                {                                                  //~v0k3I~
                    if (!(--skip2))                                //~v0k3I~
                        bandle2=Pbandle2;                          //~v0k3I~
                    nextsw=1;      //next of plh1                  //~v0k3I~
                    break;      //skip process                     //~v0k3I~
                }                                                  //~v0k3I~
//*both is objective                                               //~v0k3I~
            if (bssw1)
            {
                if (!(--bandle1))                                  //~v0k3R~
                {                                                  //~v0k3R~
                    skip1=Pskip1;                                  //~v0k3R~
                    if (repeat1>0)  //not infinite                 //~v0k3R~
                        repeat1--;                                 //~v0k3R~
                }                                                  //~v0k3R~
			}
            else
                if (repeat1>0)
            		repeat1--;
                                                                   //~v0k3I~
            if (bssw2)
            {
                if (!(--bandle2))                                  //~v0k3R~
                {                                                  //~v0k3R~
                    skip2=Pskip2;                                  //~v0k3R~
                    if (repeat2>0)                                 //~v0k3R~
                        repeat2--;                                 //~v0k3R~
                }                                                  //~v0k3R~
			}
            else
                if (repeat2>0)
	            	repeat2--;
//datasetup
            if (!plh1->ULHdbcs)  //not once displayed
            	if ((rc=filechktabdbcs(plh1))==UALLOC_FAILED)//expand data len
                	break;
			rc=0;                                                  //~v0k3M~
            pc1=plh1->ULHdata;
            pcd1=plh1->ULHdbcs;                                    //~v0k3R~
            len1=plh1->ULHlen;
          if (mrginfsw)	//margin file compare                      //~v729I~
          {                                                        //~v729I~
            if (mergin1)
                len1=min(len1,mergin1);
          }                                                        //~v729I~
            pc1+=f1bndsoffs1;                                      //~v74PI~
            pcd1+=f1bndsoffs1;                                     //~v74PI~
          	len1=max(0,len1-f1bndsoffs1);                          //~v74PI~
            pc1e=pc1+len1;                                         //~va6wI~
//*
            if (!plh2->ULHdbcs)  //not once displayed
            	if ((rc=filechktabdbcs(plh2))==UALLOC_FAILED)//expand data len
                	break;
			rc=0;                                                  //~v0k3I~
            pc2=plh2->ULHdata;
            pcd2=plh2->ULHdbcs;                                    //~v0k3R~
            len2=plh2->ULHlen;
          if (mrginfsw)	//margin file compare                      //~v729I~
          {                                                        //~v729I~
            if (mergin2)
                len2=min(len2,mergin2);
          }                                                        //~v729I~
            pc2+=f2bndsoffs1;                                      //~v74PI~
            pcd2+=f2bndsoffs1;                                     //~v74PI~
          	len2=max(0,len2-f2bndsoffs1);                          //~v74PI~
            pc2e=pc2+len2;                                         //~va6wI~
//comp
			unmatchsw=0;                                           //~v0k3I~
            complen=min(len1,len2);                                //~v0k3I~
            ii2cvcomp=-1;                                          //~va6wI~
          if (swbinmode)                                           //~va7xR~
          {                                                        //~va7xI~
            opt=0;                                                 //~va7xI~
    		unmatchsw=xesub_memcmpbin(opt,pc1,pcd1,len1,pc2,pcd2,len2,&pos1,&pos2);//~va7xI~
            ii=pos1;                                               //~va7xI~
            ii2cvcomp=pos2;                                        //~va7xI~
            pc1+=pos1;                                             //~va7xI~
            pcd1+=pos1;                                            //~va7xI~
            pc2+=pos2;                                             //~va7xI~
            pcd2+=pos2;                                            //~va7xI~
          }                                                        //~va7xI~
          else                                                     //~va7xI~
          if (swebcfile1 && swebcfile1==swebcfile2 && handle1!=handle2)//~va7xR~
          {                                                        //~va7xI~
          	opt=0;                                                 //~va7xI~
    		unmatchsw=xeebc_cvmemcmpb2b(opt,handle1,pc1,pcd1,len1,handle2,pc2,pcd2,len2,&pos1,&pos2);//~va7xI~
            ii=pos1;                                               //~va7xI~
            ii2cvcomp=pos2;                                        //~va7xI~
            pc1+=pos1;                                             //~va7xI~
            pcd1+=pos1;                                            //~va7xI~
            pc2+=pos2;                                             //~va7xI~
            pcd2+=pos2;                                            //~va7xI~
          }                                                        //~va7xI~
          else                                                     //~va7xI~
          if (swebcfile1!=swebcfile2)                              //~va6wR~
          {                                                        //~va6wI~
          	opt=0;                                                 //~va6wI~
          	if (swebcfile1)                                        //~va6wI~
            {                                                      //~va6wI~
            	if (swutf8file2)                                   //~va6wI~
                	opt|=XEEBCMC_UTF8;                             //~va6wI~
                handle=pfh1->UFHhandle;                            //~va79I~
//  			unmatchsw=xeebc_cvmemcmp(opt,pc1,pcd1,len1,pc2,pcd2,len2,&pos1,&pos2);//~va6wR~//~va79R~
    			unmatchsw=xeebc_cvmemcmp(opt,handle,pc1,pcd1,len1,pc2,pcd2,len2,&pos1,&pos2);//~va79I~
            }                                                      //~va6wI~
            else                                                   //~va6wI~
            {                                                      //~va6wI~
            	if (swutf8file1)                                   //~va6wI~
                	opt|=XEEBCMC_UTF8;                             //~va6wI~
                handle=pfh2->UFHhandle;                            //~va79I~
//  			unmatchsw=xeebc_cvmemcmp(opt,pc2,pcd2,len2,pc1,pcd1,len1,&pos2,&pos1);//~va6wR~//~va79R~
    			unmatchsw=xeebc_cvmemcmp(opt,handle,pc2,pcd2,len2,pc1,pcd1,len1,&pos2,&pos1);//~va79I~
            }                                                      //~va6wI~
            ii=pos1;                                               //~va6wI~
            ii2cvcomp=pos2;                                        //~va6wI~
            pc1+=pos1;                                             //~va6wI~
            pcd1+=pos1;                                            //~va6wI~
            pc2+=pos2;                                             //~va6wI~
            pcd2+=pos2;                                            //~va6wI~
          }                                                        //~va6wI~
          else                                                     //~va6wI~
          if (swutf8file1!=swutf8file2)                            //~va6wI~
          {                                                        //~va6wI~
          	if (swutf8file1)                                       //~va6wR~
				unmatchsw=xeutf_memcmpddlc(0,pc1,pcd1,len1,pc2,pcd2,len2,&pos1,&pos2);//~va6wR~
            else                                                   //~va6wI~
				unmatchsw=xeutf_memcmpddlc(0,pc2,pcd2,len2,pc1,pcd1,len1,&pos2,&pos1);//~va6wR~
            ii=pos1;                                               //~va6wI~
            ii2cvcomp=pos2;                                        //~va6wI~
            pc1+=pos1;                                             //~va6wI~
            pcd1+=pos1;                                            //~va6wI~
            pc2+=pos2;                                             //~va6wI~
            pcd2+=pos2;                                            //~va6wI~
          }                                                        //~va6wI~
          else                                                     //~va6wI~
          {                                                        //~va6wI~
            for (ii=0;ii<complen;ii++,pc1++,pc2++,pcd1++,pcd2++)   //~v0k3I~
//*pc and pcd chk;effective for dd fmt                             //~va20I~
                if (*pc1!=*pc2                                     //~v0k3I~
                ||  *pcd1!=*pcd2)                                  //~v0k3I~
                {                                                  //~v0k3I~
                    unmatchsw=1; 	//ii is the pos                //~v0k3I~
                    break;                                         //~v0k3I~
                }                                                  //~v0k3I~
          }                                                        //~va6wI~
			if (!unmatchsw                                         //~v0k3I~
	        &&  len1!=len2)	//match but len not same               //~v0k3R~
            {                                                      //~v62JI~
//              if (!mrginfsw)         //not spf short rec         //~v74PR~
                if (!shortreccompsw)   //not spf short rec         //~v74PI~
                {                                                  //~va6wI~
                  if (pc1<pc1e||pc2<pc2e)   //remaining not compared cv data//~va6wI~
                    unmatchsw=1;    //ii=min(len1,len2)            //~v0k3I~
                }                                                  //~va6wI~
                else                //both is spf                  //~v0k3I~
                    if (len1<len2)                                 //~v0k3R~
                    {                                              //~v0k3I~
                      if (pc2<pc2e)                                //~va6wI~
                        for (jj=0,complen=len2-len1;jj<complen;jj++,pc2++,pcd2++)//~v0k3R~
//*pc and pcd chk;effective for dd fmt                             //~va20I~
                            if (*pc2!=' '                          //~v0k3R~
                            ||  *pcd2!=0)   //may tab              //~v0k3R~
                            {                                      //~v0k3I~
                                unmatchsw=-(jj+1);                 //~v0k3R~
                                break;                             //~v0k3R~
                            }                                      //~v0k3I~
                    }                                              //~v0k3I~
                    else                //len1>len2                //~v0k3I~
                    {                                              //~v0k3I~
                      if (pc1<pc1e)                                //~va6wI~
                        for (jj=0,complen=len1-len2;jj<complen;jj++,pc1++,pcd1++)//~v0k3R~
//*pc and pcd chk;effective for dd fmt                             //~va20I~
                            if (*pc1!=' '                          //~v0k3I~
                            ||  *pcd1!=0)   //may tab              //~v0k3I~
                            {                                      //~v0k3I~
                                unmatchsw=(jj+1);                  //~v0k3R~
                                break;                             //~v0k3I~
                            }                                      //~v0k3I~
                    }                                              //~v0k3I~
            }//unmatchsw len1 len2                                 //~v62JI~
            if (unmatchsw)                                         //~v0k3R~
            {                                                      //~v0k3I~
                if (!unmatchctr++)                                 //~v0k3R~
	            {                                                  //~v0k3I~
					plh1err=plh1;  //csr line                      //~v0k3I~
					plh2err=plh2;  //csr line                      //~v0k3I~
				}                                                  //~v0k3I~
              if (ii2cvcomp>=0)                                    //~va6wI~
                ii2=ii2cvcomp+f2bndsoffs1;                         //~va6wI~
              else                                                 //~va6wI~
                ii2=ii+f2bndsoffs1;                                //~v74PI~
                ii+=f1bndsoffs1;                                   //~v74PI~
            }                                                      //~v0k3I~
            else                    //match                        //~v0k3R~
            {                                                      //~v74PI~
            	ii2=                                               //~v74PI~
                ii=ULHULFOUND;      //reverse delimeter pos        //~v0k3M~
            }                                                      //~v74PI~
//          lcmdunmatch(ii,compctr,plh1,plh2,pfh1,pfh2,unmatchsw);//unmatch//~v74PR~
            lcmdunmatch(ii,ii2,compctr,plh1,plh2,pfh1,pfh2,unmatchsw);//unmatch//~v74PI~
            compctr++;       //1st time                            //~v0k3I~
            nextsw=0;           //advance both line
            break;
        }//internal loop
//*******************
		if (rc)
        	break;
        if (nextsw<=0)                                             //~v0k3I~
        {                                                          //~v62JI~
            if (plh1==Pplh1stop                                    //~v0k3R~
            ||  !repeat1)                                          //~v0k3R~
                eof1=1;                                            //~v0k3R~
            else                                                   //~v0k3R~
    	    	if (!(plh1=UGETQNEXT(plh1)))
        	    	eof1=1;
        }                                                          //~v62JI~
        if (nextsw>=0)                                             //~v0k3I~
        {                                                          //~v62JI~
            if (plh2==Pplh2stop                                    //~v0k3R~
            ||  !repeat2)                                          //~v0k3R~
                eof2=1;                                            //~v0k3R~
            else                                                   //~v0k3R~
    	        if (!(plh2=UGETQNEXT(plh2)))
        	    	eof2=1;
        }                                                          //~v62JI~
        if (eof1 || eof2)
            break;
	}//loop until 2 range reached to stopplh
//*
    if (rc)
    	return rc;

	if (!compctr)
    {                                                              //~v0k3I~
        uerrmsgcat("0 line compared",                              //~v0k3R~
				"0 çsî‰är");                                       //~v0k3I~
    	return 4;                                                  //~v0k3R~
    }                                                              //~v0k3I~
    if (unmatchctr)                                                //~v0k3I~
    {                                                              //~v62JI~
        if (pfhc==pfh1)      //err on current pcw                  //~v0k3R~
        {                                                          //~v745I~
          if (plh1err->ULHrevoffs>ULHOFFSLINEID)                   //~v745I~
            filesetcsr(Ppcw,plh1err,1,plh1err->ULHrevoffs); //set csr//~v745R~
          else                                                     //~v745I~
            filesetcsr(Ppcw,plh1err,1,max(0,(int)(plh1err->ULHrevoffs)-pfc->UFCleft)); //set csr//~v762R~
        }                                                          //~v745I~
        else                                                       //~v0k3R~
            if (pfhc==pfh2)      //err on current pcw              //~v0k3R~
            {                                                      //~v745I~
              if (plh2err->ULHrevoffs>ULHOFFSLINEID)               //~v745I~
                filesetcsr(Ppcw,plh2err,1,plh2err->ULHrevoffs); //set csr//~v745R~
              else                                                 //~v745I~
                filesetcsr(Ppcw,plh2err,1,max(0,(int)(plh2err->ULHrevoffs)-pfc->UFCleft)); //set csr//~v762R~
            }                                                      //~v745I~
    }                                                              //~v62JI~
    if (pfh1!=pfh2)                                                //~v0k3R~
		scrfulldraw(Ppcw);
                                                                   //~v0k3I~
    if (unmatchctr)                                                //~v0k3R~
    {
        uerrmsgcat("%d of %d unmatch",                             //~v0k3R~
        		"%d çs(%d çsíÜ)ïsàÍív",                            //~v0k3I~
				unmatchctr,compctr);
        ubell();                                                   //~v0k3I~
    }
    else
        if ((eof1 && (eof2 || repeat2<0))                          //~v0k3R~
        ||  (eof2 && repeat1<0))                                   //~v0k3R~
	        uerrmsgcat("all %d lines same",                        //~v0k3R~
					"ëS %d çsàÍív",                                //~v0k3I~
					compctr);                                      //~v0k3I~
        else
        {                                                          //~v0k3I~
            uerrmsgcat("%d lines same,more unchecked lines exist", //~v0k3R~
					"%d çsàÍív(íAÇµçsêîïsàÍív)",                   //~v0k3I~
					compctr);
	        ubell();                                               //~v0k3M~
		}                                                          //~v0k3I~
	return rc;
}//lcmdcomp

//****************************************************************
// set unmatch err
//*parm 1:unmatch offset                                           //~v0k3I~
//*parm 2:1st time sw                                              //~v0k3I~
//*parm 3:plh1                                                     //~v0k3R~
//*parm 4:plh2                                                     //~v0k3I~
//*parm 5:pfh1                                                     //~v0k3R~
//*parm 6:pfh2                                                     //~v0k3R~
//*return:none
//****************************************************************
//void lcmdunmatch(int Poffs,int P1stsw,PULINEH Pplh1,PULINEH Pplh2,//~v74PR~
void lcmdunmatch(int Poffs,int Poffs2,int P1stsw,PULINEH Pplh1,PULINEH Pplh2,//~v74PI~
					PUFILEH Ppfh1,PUFILEH Ppfh2,int Punmatchlen)   //~v0k3R~
{
    UCHAR *pdbcs;                                                  //~v74QI~
#ifdef UTF8SUPPH                                                   //~va04I~
	int splitctr;                                                  //~va04I~
#endif                                                             //~va04I~
//**************
    if (!P1stsw)			//first time                           //~v0k3R~
    {
		Ppfh1->UFHfindctr++;		//find cmd ctr;                //~v0k3R~
        if (Ppfh1!=Ppfh2)                                          //~v0k3R~
			Ppfh2->UFHfindctr++;		//find cmd ctr;            //~v0k3R~
    }
	Pplh1->ULHrevctr=Ppfh1->UFHfindctr;//find cmd ctr for disply current;//~v0k3R~
	Pplh1->ULHrevoffs=(USHORT)Poffs;                               //~v0k3R~
	Pplh1->ULHrevlen=1;				//reverse len                  //~v0k3R~
	Pplh2->ULHrevctr=Ppfh2->UFHfindctr;//find cmd ctr for disply current;//~v0k3I~
//  Pplh2->ULHrevoffs=(USHORT)Poffs;                               //~v74PR~
    Pplh2->ULHrevoffs=(USHORT)Poffs2;                              //~v74PI~
	Pplh2->ULHrevlen=1;				//reverse len                  //~v0k3I~
//for margin file                                                  //~v0k3I~
    if (Punmatchlen>1)      //plh1 is long                         //~v0k3R~
		Pplh1->ULHrevlen=(USHORT)Punmatchlen;				//reverse len//~v0k3R~
	else                                                           //~v0k3I~
	    if (Punmatchlen<0)  //plh2 is long                         //~v0k3R~
			Pplh2->ULHrevlen=(USHORT)(-Punmatchlen);				//reverse len//~v0k3R~
                                                                   //~v0k3I~
    pdbcs=Pplh1->ULHdbcs;                                          //~v74QI~
    if (pdbcs && !(Poffs & 0x8000))                                //~v74QR~
    {                                                              //~v74QI~
    	pdbcs+=Poffs;                                              //~v74QI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416            //FIXME test surrogate:FIXED          //~vaw1R~
        switch(UDBCSCHK_TEMPDBCSID(*pdbcs))                        //~va3xI~
#else                                                              //~va3xI~
    	switch (*pdbcs)                                            //~v74QI~
#endif                                                             //~va3xI~
        {                                                          //~v74QI~
        case DBCS1STCHAR:                                          //~v74QI~
#ifdef UTF8UCS2                                                    //~va20R~
        case UDBCSCHK_DBCS1STUCS_CASE():                           //~va20R~
#endif                                                             //~va20R~
        	if (Pplh1->ULHrevlen==1)                               //~v74QI~
            {                                                      //~va04I~
#ifdef UTF8SUPPH                                                   //~va04I~
//          	Pplh1->ULHrevlen=XESUB_DBCSSPLITCTR(Pplh1->ULHdbcs,Pplh1->ULHlen,Poffs);//~va04I~//~vb2CR~
            	Pplh1->ULHrevlen=(USHORT)XESUB_DBCSSPLITCTR(Pplh1->ULHdbcs,Pplh1->ULHlen,Poffs);//~vb2CI~
#else                                                              //~va04I~
            	Pplh1->ULHrevlen=2;                                //~v74QI~
#endif                                                             //~va04I~
            }                                                      //~va04I~
        	break;                                                 //~v74QI~
        case DBCS2NDCHAR:                                          //~v74QI~
#ifdef UTF8SUPPH                                                   //~va04I~
        case UDBCSCHK_DBCSPAD:                                     //~va04I~
#endif                                                             //~va04I~
#ifdef UTF8UCS2                                                    //~va20R~
        case UDBCSCHK_DBCS2NDUCS_CASE():                           //~va20R~
#endif                                                             //~va20R~
        	if (Poffs)                                             //~v74QI~
            {                                                      //~v74QI~
#ifdef UTF8SUPPH                                                   //~va04I~
            	splitctr=XESUB_DBCSSPLITCTR_L(Pplh1->ULHdbcs,Poffs);//~va04I~
//  			Pplh1->ULHrevoffs-=splitctr;                       //~va04I~//~vb2CR~
//    			Pplh1->ULHrevoffs-=(USHORT)splitctr;               //~vb2CI~//~vb2DR~
      			Pplh1->ULHrevoffs=(USHORT)(Pplh1->ULHrevoffs-(USHORT)splitctr);//~vb2DI~
//          	Pplh1->ULHrevlen+=splitctr;                        //~va04I~//~vb2CR~
//          	Pplh1->ULHrevlen+=(USHORT)splitctr;                //~vb2CI~//~vb2DR~
            	Pplh1->ULHrevlen=(USHORT)(Pplh1->ULHrevlen+(USHORT)splitctr);//~vb2DR~
#else                                                              //~va04I~
				Pplh1->ULHrevoffs--;                               //~v74QI~
            	Pplh1->ULHrevlen++;                                //~v74QI~
#endif                                                             //~va04I~
            }                                                      //~v74QI~
        	break;                                                 //~v74QI~
        }                                                          //~v74QI~
    }                                                              //~v74QI~
                                                                   //~v74QI~
    pdbcs=Pplh2->ULHdbcs;                                          //~v74QI~
    if (Pplh2!=Pplh1 && pdbcs && !(Poffs2 & 0x8000))               //~v74QR~
    {                                                              //~v74QI~
    	pdbcs+=Poffs2;                                             //~v74QI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416            //FIXME test surrogate:FIXED          //~vaw1R~
        switch(UDBCSCHK_TEMPDBCSID(*pdbcs))                        //~va3xI~
#else                                                              //~va3xI~
    	switch (*pdbcs)                                            //~v74QI~
#endif                                                             //~va3xI~
        {                                                          //~v74QI~
        case DBCS1STCHAR:                                          //~v74QI~
#ifdef UTF8UCS2                                                    //~va20R~
        case UDBCSCHK_DBCS1STUCS_CASE():                           //~va20R~
#endif                                                             //~va20R~
        	if (Pplh2->ULHrevlen==1)                               //~v74QI~
#ifdef UTF8SUPPH                                                   //~va04I~
//          	Pplh2->ULHrevlen=XESUB_DBCSSPLITCTR(Pplh2->ULHdbcs,Pplh2->ULHlen,Poffs2);//~va04R~//~vb2CR~
            	Pplh2->ULHrevlen=(USHORT)XESUB_DBCSSPLITCTR(Pplh2->ULHdbcs,Pplh2->ULHlen,Poffs2);//~vb2CI~
#else                                                              //~va04I~
            	Pplh2->ULHrevlen=2;                                //~v74QI~
#endif                                                             //~va04I~
        	break;                                                 //~v74QI~
        case DBCS2NDCHAR:                                          //~v74QI~
#ifdef UTF8SUPPH                                                   //~va04I~
        case UDBCSCHK_DBCSPAD:                                     //~va04I~
#endif                                                             //~va04I~
#ifdef UTF8UCS2                                                    //~va20R~
        case UDBCSCHK_DBCS2NDUCS_CASE():                           //~va20R~
#endif                                                             //~va20R~
        	if (Poffs2)                                            //~v74QI~
            {                                                      //~v74QI~
#ifdef UTF8SUPPH                                                   //~va04I~
            	splitctr=XESUB_DBCSSPLITCTR_L(Pplh2->ULHdbcs,Poffs2);//~va04I~
//  			Pplh2->ULHrevoffs-=splitctr;                       //~va04I~//~vb2CR~
//    			Pplh2->ULHrevoffs-=(USHORT)splitctr;               //~vb2CI~//~vb2DR~
      			Pplh2->ULHrevoffs=(USHORT)(Pplh2->ULHrevoffs-(USHORT)splitctr);//~vb2DI~
//          	Pplh2->ULHrevlen+=splitctr;                        //~va04I~//~vb2CR~
//          	Pplh2->ULHrevlen+=(USHORT)splitctr;                //~vb2CI~//~vb2DR~
            	Pplh2->ULHrevlen=(USHORT)(Pplh2->ULHrevlen+(USHORT)splitctr);//~vb2DR~
#else                                                              //~va04I~
				Pplh2->ULHrevoffs--;                               //~v74QI~
            	Pplh2->ULHrevlen++;                                //~v74QI~
#endif                                                             //~va04I~
            }                                                      //~v74QI~
        	break;                                                 //~v74QI~
        }                                                          //~v74QI~
    }                                                              //~v74QI~
	UCBITON(Pplh1->ULHflag,ULHFDRAW|ULHFCURFOUND);//draw word after wordrep//~v0k3R~
	UCBITON(Pplh2->ULHflag,ULHFDRAW|ULHFCURFOUND);//draw word after wordrep//~v0k3I~
    UCBITOFF(Pplh1->ULHflag2,ULHF2MFOUND);//reset multiple         //~v0k3R~
    UCBITOFF(Pplh2->ULHflag2,ULHF2MFOUND);//reset multiple         //~v0k3I~
	return;
}//lcmdunmatch
//**************************************************************** //~v62JI~
//!lcmdexec                                                        //~v62JI~
// 	execute line                                                   //~v62JI~
//*parm1:start ULINEH                                              //~v62JI~
//*parm2:end   ULINEH                                              //~v62JI~
//*parm3:repaet count                                              //~v62JI~
//*rc   :0 or UALLOC_FAILED                                        //~v62JI~
//**************************************************************** //~v62JI~
int lcmdexec(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Popt) //~v62JR~
{                                                                  //~v62JI~
	PULINEH plh,plhlast=0;                                         //~v62JR~
	int sw2ndf=0,swerrcont=0,rc,cmd2ndsw=0,ignorercsw,errctr=0,len,len2;//~v62JR~
    UCHAR icstr[ULHLINENOSZ*2],*pc,*pcmd;                          //~v62JR~
    char **vfmtparm,*parmaddr=0;                                   //~v62JR~
//  char buff[MAXCOLUMN+8];                                        //~v62JR~//~va04R~
    char buff[MAXPARMSZ+8];                                        //~va04I~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file,u8len;                                          //~va20R~
    UCHAR *pu8,*pcd;                                               //~va20R~
#endif                                                             //~va20I~
//*****************                                                //~v62JI~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=PLHUTF8MODE(Pplh1);                                 //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (PLH_ISEBC(Pplh1))                                          //~va50R~
        return errnotsupported("Execule line cmd","EBCDIC file");  //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*convert cont type to range type                                 //~v62JI~
	if (Pplh1==Pplh2)	//single cmd                               //~v62JR~
		strcpy(icstr,Pplh1->ULHlinecmd+1);                         //~v62JR~
    else                                                           //~v62JI~
    {                                                              //~v62JI~
		strcpy(icstr,Pplh1->ULHlinecmd+2);                         //~v62JI~
		strcat(icstr,Pplh2->ULHlinecmd+2);                         //~v62JI~
    }                                                              //~v62JI~
    for (pc=icstr;*pc;pc++)                                        //~v62JI~
    {                                                              //~v62JI~
        if (*pc=='!')                                              //~v62JI~
            swerrcont=1;                                           //~v62JI~
        else                                                       //~v62JI~
        if (*pc=='^')                                              //~v62JI~
            sw2ndf=1;                                              //~v62JI~
        else                                                       //~v62JI~
        {                                                          //~v62JI~
            uerrmsg("! or ^ is only valid option for %c lcmd",0,   //~v62JI~
                    ULCCMDEXEC);                                   //~v62JR~
            return 4;                                              //~v62JI~
        }                                                          //~v62JI~
    }                                                              //~v62JI~
    if (sw2ndf)                                                    //~v62JI~
    {                                                              //~v62JI~
    	if (!scrgetcw(-1))  //another screen                       //~v62JI~
        {                                                          //~v62JI~
            errscrnotsplited("^");                                 //~v62JR~
            return 4;                                              //~v62JI~
        }                                                          //~v62JI~
    }                                                              //~v62JI~
    rc=0;                                                          //~v62JI~
	for (plh=Pplh1;plh;plh=UGETQNEXT(plh))                         //~v62JR~
	{                                                              //~v62JI~
		if (plh->ULHtype==ULHTDATA		//no delete when hdr line  //~v62JR~
		&&  !UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))                //~v62JR~
		{                                                          //~v62JI~
            if (!plh->ULHdbcs)  //not once displayed               //~v62JI~
            {                                                      //~v62JI~
                if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v62JI~
                    return UALLOC_FAILED;                          //~v62JI~
                rc=0;   //make sure for rc=4 from filechktabdbcs   //~v62JI~
            }                                                      //~v62JI~
            plhlast=plh;                                           //~v62JM~
            pcmd=plh->ULHdata;                                     //~v62JI~
            len=plh->ULHlen;                                       //~v62JI~
            if (len)                                               //~v62JI~
            {                                                      //~v62JI~
#ifdef UTF8UCS2                                                    //~va20I~
            	if (UTF_eq(swutf8file,*pcmd,*plh->ULHdbcs,FCMDLOG_TIMESTAMPID))//~va20R~
#else                                                              //~va20I~
            	if (*pcmd==FCMDLOG_TIMESTAMPID)                    //~v62JI~
#endif                                                             //~va20I~
                {                                                  //~v62JI~
#ifdef UTF8UCS2                                                    //~va20I~
            		pc=UTF_memchr(swutf8file,pcmd+1,plh->ULHdbcs+1,FCMDLOG_TIMESTAMPID,len-1);//~va20R~
#else                                                              //~va20I~
            		pc=memchr(pcmd+1,FCMDLOG_TIMESTAMPID,(UINT)(len-1));//~v62JI~
#endif                                                             //~va20I~
                    if (pc)                                        //~v62JI~
                    {                                              //~v62JI~
//                  	len2=(int)((UINT)pc-(UINT)pcmd)+1;         //~v62JR~//~va70R~
//                    	len2=(int)((ULONG)pc-(ULONG)pcmd)+1;       //~va70I~//~vafkR~
                    	len2=(int)((ULPTR)pc-(ULPTR)pcmd)+1;       //~vafkI~
                        len-=len2;                                 //~v62JI~
                        pcmd+=len2;                                //~v62JI~
                    }                                              //~v62JI~
                }                                                  //~v62JI~
            }                                                      //~v62JI~
            if (len>0)                                             //~v62JI~
            {                                                      //~v62JI~
            	if (!cmd2ndsw && sw2ndf)	//1st call and exec other scr file//~v62JI~
                {                                                  //~v62JI~
                	strcpy(buff,"SWA ;");                          //~v62JI~
                    len2=5;                                        //~v62JI~
                }                                                  //~v62JI~
                else                                               //~v62JI~
                	len2=0;                                        //~v62JI~
#ifdef UTF8UCS2                                                    //~va20I~
	  			pcd=XEUTF_PC2PCD(plh->ULHdbcs,pcmd,plh->ULHdata);  //~va20I~
	  			if (swutf8file                                     //~va20I~
	  			&&  (xeutfcvdd2f(0,pcmd,pcd,len,&pu8,&u8len,0/*outdbcs*/)!=UALLOC_FAILED)//~va20R~
      			)                                                  //~va20I~
      			{                                                  //~va20I~
        			pcmd=pu8;                                      //~va20I~
                    len=u8len;                                     //~va20I~
      			}                                                  //~va20I~
#endif                                                             //~va20I~
//              len=min(len,MAXCOLUMN);                            //~v62JR~//~va04R~
                len=min(len,MAXPARMSZ);                            //~va04I~
                memcpy(buff+len2,pcmd,(UINT)len);                  //~v62JR~
                *(buff+len2+len)=0;                                //~v62JR~
            	vfmtparm=&parmaddr;                                //~v62JM~
//  			rc=execmdsub(Ppcw,buff,vfmtparm,&cmd2ndsw,&ignorercsw);//~v77KR~
    			rc=execmdsub(0,Ppcw,buff,vfmtparm,&cmd2ndsw,&ignorercsw,0/*fhlog*/);//~v77KI~
                if (rc>=4)                                         //~v62JI~
                {                                                  //~v62JI~
                    lcmdshifterr(plh,0,0);//no exclude line highlight,no output 1st err line//~v62JI~
                  	if (!swerrcont&&!ignorercsw)                   //~v62JI~
                    	break;                                     //~v62JI~
                  	else                                           //~v62JI~
                    	errctr++;                                  //~v62JI~
                }                                                  //~v62JI~
                else                                               //~v62JI~
                    lcmdresetshifterr(plh,0);//no reset excluded   //~v62JI~
            }                                                      //~v62JI~
		}                                                          //~v62JI~
		if (plh==Pplh2)                                            //~v62JI~
			break;                                                 //~v62JI~
	}//by range                                                    //~v62JI~
    if(rc)                                                         //~v62JI~
        return rc;                                                 //~v62JI~
    if (plhlast)                                                   //~v62JR~
        filesetcsr(Ppcw,plhlast,0,0);   //csr set to data fld,fldtop//~v62JR~
    if (errctr)                                                    //~v62JI~
    	return 4;                                                  //~v62JI~
	return 0;                                                      //~v62JI~
}//lcmdexec                                                        //~v62JI~
//**************************************************************** //~v74MI~
//!lcmdlower                                                       //~v74MI~
//**************************************************************** //~v74MI~
int lcmdlower(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,//~v74MI~
				int Pbandle,int Pskip)                             //~v74MI~
{                                                                  //~v74MI~
	int rc;                                                        //~v74MI~
//**************************                                       //~v74MI~
    Slowersw=1;                                                    //~v74MI~
	rc=lcmdupper(Ppcw,Pplh1,Pplh2,Prepeat,Pbandle,Pskip);          //~v74MI~
    Slowersw=0;                                                    //~v74MI~
    return rc;                                                     //~v74MI~
}//lcmdlower                                                       //~v74MI~
//**************************************************************** //~v69LI~
//!lcmdupper                                                       //~v69LI~
//* format:Un,b.s / UU-UU,b.s                                      //~v69LI~
//*excluded linres are processed as one line                       //~v69LI~
//*rc   :0 or UALLOC_FAILED                                        //~v69LI~
//**************************************************************** //~v69LI~
int lcmdupper(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,//~v69LI~
				int Pbandle,int Pskip)                             //~v69LI~
{                                                                  //~v69LI~
    PUFILEH pfh;                                                   //~v69LR~
	PULINEH plh,plhn,plhstop,plhcsr=0;                             //~v69LR~
	int ii,jj,kk,stopsw=0,rc,bandle,skip,mergin,pos;               //~v69LR~
    int bndsoffs1,bndsoffs2;                                       //~v74LI~
    int updatelinecnt=0;                                           //~v74MI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************                                                //~v69LI~
    pfh=UGETPFH(Pplh1);                                            //~v69LI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    mergin=pfh->UFHmergin;                                         //~v69LI~
    bndsoffs1=pfh->UFHbndscol1-1;                                  //~v74LI~
    bndsoffs2=pfh->UFHbndscol2;                                    //~v74LI~
	if (CSRONFILEDATA(Ppcw))			//csr on file data line    //~v69LI~
    	pos=Ppcw->UCWrcsrx-Ppcw->UCWlinenosz+((PUFILEC)Ppcw->UCWpfc)->UFCleft;//target pos//~v69LI~
    else                                                           //~v69LI~
    	pos=0;                                                     //~v69LI~
    BNDS_ADJUSTPOS(bndsoffs1,bndsoffs2,pos);	//update pos by bnds parm//~v74LI~
    if (pos>=mergin)	//no data after cursor                     //~v69LI~
      	if (!UCBITCHK(pfh->UFHflag3,UFHF3OOMNOPROT))   //valid spf file//~v69LI~
  			return errprotected();                                 //~v69LI~
                                                                   //~v69LI~
	if (Pplh1==Pplh2)	//count type                               //~v69LI~
    {                                                              //~v69LI~
    	ii=Prepeat;                                                //~v69LI~
        plhstop=0;                                                 //~v69LI~
	}                                                              //~v69LI~
	else                                                           //~v69LI~
    {                                                              //~v69LI~
    	ii=-1;                                                     //~v69LI~
        plhstop=Pplh2;                                             //~v69LI~
	}                                                              //~v69LI~
	if (Pbandle)                                                   //~v69LI~
    	bandle=Pbandle;                                            //~v69LI~
    else                                                           //~v69LI~
    	bandle=1;                                                  //~v69LI~
//loop by count or stop                                            //~v69LI~
	stopsw=0;                                                      //~v69LI~
    plhn=0;                                                        //~v69LI~
    for (plh=Pplh1;ii && plh;plh=plhn,ii--)                        //~v69LI~
    {                                                              //~v69LI~
    	for (jj=bandle;jj && plh;plh=plhn)                         //~v69LI~
        {                                                          //~v69LI~
        	if (plh==plhstop)                                      //~v69LI~
            	stopsw=1;                                          //~v69LI~
		    plhn=getdisplayline(plh,1,0);                          //~v69LI~
        	if (plh->ULHtype==ULHTHDR)                             //~v69LI~
        		continue;                                          //~v69LI~
            jj--;                                                  //~v69LI~
//******                                                           //~v69LI~
            if (plh->ULHtype==ULHTEXCLUDE)                         //~v69LI~
            {                                                      //~v69LI~
//              kk=plh->ULHlinenow;                                //~v69LI~//+vb2ER~
                kk=(int)plh->ULHlinenow;                           //+vb2EI~
                plh=UGETQNEXT(plh);                                //~v69LI~
            }                                                      //~v69LI~
            else                                                   //~v69LI~
            	kk=1;                                              //~v69LI~
            for (;plh && kk;kk--,plh=plhn)                         //~v69LI~
            {                                                      //~v69LI~
                plhn=UGETQNEXT(plh);                               //~v69LI~
	            if (plh->ULHtype==ULHTHDR)                         //~v69LI~
                	break;                                         //~v69LI~
                rc=lcmduppersub(Ppcw,pfh,plh,pos);                 //~v69LR~
                if (rc==UALLOC_FAILED)                             //~v69LI~
                	return rc;                                     //~v69LI~
                if (rc==1)	//replaced                             //~v69LI~
                {                                                  //~v74MI~
	                if (!plhcsr)                                   //~v69LI~
	                    plhcsr=plh;                                //~v69LI~
                    updatelinecnt++;                               //~v74MI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
					XEEBC_setdbcstblplh(swebcfile,pfh,plh);        //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                }                                                  //~v74MI~
            }                                                      //~v69LI~
//******                                                           //~v69LI~
            if (stopsw)                                            //~v69LI~
            	break;                                             //~v69LI~
		}                                                          //~v69LI~
        if (stopsw)                                                //~v69LI~
            break;                                                 //~v69LI~
		if (Pbandle)                                               //~v69LI~
        {                                                          //~v69LI~
		    plhn=getdisplayline2(plhn,Pskip,plhstop,&skip);        //~v69LI~
        	if (skip!=Pskip)	//reached in the skip range        //~v69LI~
            	break;                                             //~v69LI~
        }                                                          //~v69LI~
    }//count or reached to end plh                                 //~v69LI~
//*                                                                //~v69LI~
    if (plhcsr)                                                    //~v69LI~
		filesetcsr(Ppcw,plhcsr,0,0);	//on cmd line              //~v69LI~
    if (Slowersw)                                                  //~v74MI~
	    uerrmsg("%d lines translated to LowerCase",0,              //~v74MR~
                updatelinecnt);                                    //~v74MI~
    else                                                           //~v74MI~
	    uerrmsg("%d lines translated to UpperCase",0,              //~v74MR~
                updatelinecnt);                                    //~v74MI~
    return 0;                                                      //~v69LI~
}//lcmdupper                                                       //~v69LI~
//**************************************************************** //~v69LI~
// lcmduppersub                                                    //~v69LI~//~va50R~
//*rc   :0 or UALLOC_FAILED                                        //~v69LI~
//**************************************************************** //~v69LI~
int lcmduppersub(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,int Ppos)//~v69LR~
{                                                                  //~v69LI~
	UCHAR  uc,*pc,*pcd;                                            //~v69LI~
    int mergin;                                                    //~v69LI~
    int oomlen,len,ii,repsw;                                       //~v69LR~
    int bndsoffs2;                                                 //~v74LI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
    int handle;                                                    //~va70I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************                                                //~v69LI~
	if (!Pplh->ULHdbcs)	//not once displayed                       //~v69LR~
		if (filechktabdbcs(Pplh)==UALLOC_FAILED)	//create dbcstbl//~v69LI~
            	return UALLOC_FAILED;                              //~v69LI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(Ppfh);                                     //~va50R~
	handle=Ppfh->UFHhandle;                                        //~va70I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    mergin=Ppfh->UFHmergin;                                        //~v69LI~
    bndsoffs2=Ppfh->UFHbndscol2;                                   //~v74LR~
	oomlen=filegetoomlen(Ppfh,Pplh);  //out of mergin len          //~v69LI~
    if (oomlen)	//data on out of mergin for mergined file          //~v69LI~
        if (Ppos>=mergin)                                          //~v69LI~
        {                                                          //~v69LI~
            oomlen=0;   //normal left shift for oom                //~v69LI~
            mergin=MAXLINEDATA;         //shft right up to         //~v69LI~
        }                                                          //~v69LI~
    if (bndsoffs2>0)                                               //~v74LI~
    {                                                              //~v74LI~
        if (bndsoffs2<Pplh->ULHlen)                                //~v74LI~
        {                                                          //~v74LI~
            oomlen=Pplh->ULHlen-bndsoffs2;                         //~v74LI~
            len=bndsoffs2-Ppos;                                    //~v74LI~
        }                                                          //~v74LI~
        else                                                       //~v74LI~
            len=Pplh->ULHlen-Ppos;                                 //~v74LI~
    }                                                              //~v74LI~
    else                                                           //~v74LI~
    if (oomlen)                                                    //~v69LI~
        len=mergin-Ppos;                                           //~v69LR~
    else                                                           //~v69LI~
        len=Pplh->ULHlen-Ppos;                                     //~v69LR~
    if (len<=0)     //len after csr                                //~v69LI~
        return 0;                                                  //~v69LI~
    pc=Pplh->ULHdata+Ppos;                                         //~v69LR~
    pcd=Pplh->ULHdbcs+Ppos;                                        //~v69LR~
    for (ii=0,repsw=0;ii<len;ii++,pcd++,pc++)                      //~v69LI~
    {                                                              //~v69LI~
        if (*pcd)   //dbcs or tab                                  //~v69LI~
            continue;                                              //~v69LI~
//*ucs is skipped                                                  //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
     if (swebcfile)                                                //~va50I~
     {                                                             //~va50I~
      if (Slowersw)                                                //~va50I~
//      uc=(UCHAR)EBC_tolower(*pc);                                //~va50I~//~va70R~
        uc=(UCHAR)UCVEBCH_tolower(handle,*pc);                     //~va70I~
      else                                                         //~va50I~
//      uc=(UCHAR)EBC_toupper(*pc);                                //~va50I~//~va70R~
        uc=(UCHAR)UCVEBCH_toupper(handle,*pc);                     //~va70I~
     }                                                             //~va50I~
     else                                                          //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
     {                                                             //~va50I~
      if (Slowersw)                                                //~v74MI~
        uc=(UCHAR)tolower(*pc);                                    //~v74MI~
      else                                                         //~v74MI~
        uc=(UCHAR)toupper(*pc);                                    //~v69LI~
     }                                                             //~va50I~
        if (uc!=*pc)                                               //~v69LR~
        {                                                          //~v69LI~
            if (!repsw)                                            //~v69LI~
            {                                                      //~v69LI~
//chan ascii only,no dbcstbl change                                //~va50I~
                if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)//prep undo for data line rep//~v69LR~
                    return UALLOC_FAILED;                          //~v69LI~
                repsw=1;                                           //~v69LI~
            }                                                      //~v69LI~
            *pc=uc;                                                //~v69LI~
        }                                                          //~v69LI~
    }                                                              //~v69LI~
    return repsw;                                                  //~v69LI~
}//lcmduppersub                                                    //~v69LI~
