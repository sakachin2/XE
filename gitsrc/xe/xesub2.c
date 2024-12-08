//*CID://+vb28R~:                             update#=  565;       //~vb28R~
//*************************************************************
//* xesub2.c
//*************************************************************    //~va20I~
//vb28:160116 (BUG)display spilit utf8 by lineattr                 //~vb28I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//va8w:101209 SPLIT/TFLOW:delete so/si when join dbcs string       //~va8wI~
//va8s:101026 (BUG)TFLow:head count for top dbcssplit              //~va8sI~
//va8j:101013 SPLit cmd;dbcs consideration for TAIL cut without SBCS option .//~va8jI~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va53:100419 num setr/seti should chk margin/lrecl overflow       //~va53I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3P:100320 utf8 file sort dbcs split option;D[S|I|X] space/include/exclude//~va3PI~
//va27:091211 (BUG)splitctr when used on not dbcspoint             //~va27I~
//                 sub2.c                                          //~va27I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1c:091030_merge GB18030 support                                //~va1cI~
//* 091024:split from xesub,because xeacb ld err(dup object parmproc,csrwrite etc)
//*************************************************************
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>                                                //~va50I~
#include <ctype.h>
#include <string.h>
//*************************************************************
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <udbcschk.h>
#include <ustring.h>
#include <ufile.h>
#include <utrace.h>
#ifdef UTF8UCS2                                                    //~va20I~
#include <ualloc.h>                                                //~va20I~
#include <utf22.h>                                                 //~va27I~
#endif                                                             //~va20I~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc.h>                                                //~va3PI~
#include <ucvebc4.h>                                               //~va79I~

#include "xe.h"
#include "xeerr.h"
#include "xescr.h"
#include "xefile.h"
#include "xesub.h"
#include "xesub2.h"
#include "xechar12.h"                                              //~va3PI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xefcmd23.h"                                              //~va20I~
#include "xeutf.h"                                                 //~va20R~
#include "xeutf2.h"                                                //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
//*******************************************************
#ifdef UTF8SUPPH
//**************************************************
//*xesub_cleardbcssplit
//LEFT :clear from top to dbcs2nd until Plen exaust
//RIGHT:clear up  to dbcs1st from Plen-1 possition until Plen exaust
//*return cleared len
//**************************************************
int xesub_cleardbcssplit(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepch)
{
    int ii,seterrsw,getctrsw,dbcsclearsw,ctr=0,reseterrsw;
    UCHAR *pc,*pcd,dbcsid;
    UCHAR repdbcs;                                                 //~vb28R~
//*************
	dbcsclearsw=!(Popt & XESUBCDSO_REPDATAONLY)
	            && (Prepch==' ' || !(Popt & XESUBCDSO_IFREPBYSPACE));
	getctrsw=(Popt & XESUBCDSO_GETCTR);
	seterrsw=(Popt & XESUBCDSO_SETERR);
	reseterrsw=(Popt & XESUBCDSO_RESETERR);
	repdbcs=(UCHAR)((Popt & XESUBCDSO_REPDBCS)>>XESUBCDSO_REPDBCSSHIFT);//~vb28R~
	if (Popt & XESUBCDSO_LEFT)
    {
//clear from top to dbcs2nd until Plen exaust
        for (ii=0,pc=Pdata,pcd=Pdbcs;ii<MAX_MBCSLENLC && ii<Plen;ii++,pc++,pcd++)
        {
UTRACEP("cleardbcssplit left ii=%d,dbcs=%x\n",ii,*pcd);
			if (reseterrsw)
            {
            	if (*pcd!=UDBCSCHK_HKDBCSERR
                )
                	break;
            }
            if (!UDBCSCHK_DBCSNOT1ST(*pcd))
            	break;
            ctr++;
            dbcsid=*pcd;
            if (!getctrsw)
            {
                if (Pdata)
                    *pc=Prepch;
                if (repdbcs)                                       //~vb28I~
                    *pcd=repdbcs;                                  //~vb28I~
                else                                               //~vb28I~
                if (seterrsw)
                        *pcd=UDBCSCHK_HKDBCSERR;
                else
                if (dbcsclearsw)
                    *pcd=0;
            }
#ifdef UTF8UCS2                                                    //~va20I~
            if (UDBCSCHK_DBCS2NDLU(dbcsid))//reached to dbcs end   //~va20R~
#else                                                              //~va20I~
            if (dbcsid==UDBCSCHK_DBCS2ND)//reached to dbcs end
#endif                                                             //~va20I~
                break;
        }
    }
	else // XESUBCDSO_RIGHT)
    {
//clear up  to dbcs1st from Plen-1 possition until Plen exaust
        for (ii=min(MAX_MBCSLENLC,Plen-1),pc=Pdata+Plen-1,pcd=Pdbcs+Plen-1;ii>=0;ii--,pc--,pcd--)
        {
UTRACEP("cleardbcssplit right ii=%d,dbcs=%x\n",ii,*pcd);
			if (reseterrsw)
            {
            	if (*pcd!=UDBCSCHK_HKDBCSERR
                )
                	break;
            }
            if (!UDBCSCHK_DBCSNOTEND(*pcd))
                break;
            ctr++;
            dbcsid=*pcd;
            if (!getctrsw)
            {
                if (Pdata)
                    *pc=Prepch;
                if (repdbcs)                                       //~vb28R~
                    *pcd=repdbcs;                                  //~vb28R~
                else                                               //~vb28R~
                if (seterrsw)
                        *pcd=UDBCSCHK_HKDBCSERR;
                else
                if (dbcsclearsw)
                    *pcd=0;
            }
#ifdef UTF8UCS2                                                    //~va20I~
            if (UDBCSCHK_DBCS1STLU(dbcsid))//reached to dbcs end   //~va20R~
#else                                                              //~va20I~
            if (dbcsid==UDBCSCHK_DBCS1ST)	//reached to dbcs top
#endif                                                             //~va20I~
                break;
        }
    }
    return ctr;	//cleared len
}//xesub_cleardbcssplit
//**************************************************
//*xesub_cleardbcs1
//*clear dbcstbl of dbcs replaced
//*return cleared ctr
//**************************************************
int xesub_cleardbcs1(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos,UCHAR Prepch)
{
    int ii,fullsw=0,ctr=0,reslen,getctrsw;
    UCHAR *pc,*pcd,dbcsid;
//*************
	getctrsw=Popt & XESUBCD1O_GETCTR;
	pc=Pdata+Ppos;
	pcd=Pdbcs+Ppos;
    reslen=Plen-Ppos;
#ifdef UTF8UCS2                                                    //~va20I~
    if (UDBCSCHK_DBCS1STLU(*pcd))//reached to dbcs end             //~va20R~
#else                                                              //~va20I~
    if (*pcd==UDBCSCHK_DBCS1ST)
#endif                                                             //~va20I~
    {
    	ctr++;
        if (!getctrsw)
        {
        	*pc=Prepch;
        	*pcd=0;
        }
        pc++;
        pcd++;
        reslen--;
        fullsw=1;
    }
	for (ii=0;ii<MAX_MBCSLENLC && ii<reslen;ii++,pc++,pcd++)
    {
        if (UDBCSCHK_DBCSNOT1ST(*pcd))
        {
	        ctr++;
            dbcsid=*pcd;
	        if (!getctrsw)
            {
	        	*pc=Prepch;
    	    	*pcd=0;
            }
#ifdef UTF8UCS2                                                    //~va20I~
    		if (UDBCSCHK_DBCS2NDLU(dbcsid))//reached to dbcs end   //~va20R~
#else                                                              //~va20I~
            if (dbcsid==UDBCSCHK_DBCS2ND)//reached to dbcs end
#endif                                                             //~va20I~
                break;
        }
        else                                                       //~va27I~
            break;                                                 //~va27I~
    }
    if (!fullsw)
    {
//      for (ii=min(MAX_MBCSLENLC,Ppos-1),pc=Pdata+ii,pcd=Pdbcs+ii;ii>=0;ii--,pc--,pcd--)//~va27R~
        for (ii=min(MAX_MBCSLENLC,Ppos)-1,pc=Pdata+Ppos-1,pcd=Pdbcs+Ppos-1;ii>=0;ii--,pc--,pcd--)//~va27I~
        {
            if (!UDBCSCHK_DBCSNOTEND(*pcd))
                break;
            ctr++;
            dbcsid=*pcd;
	        if (!getctrsw)
            {
	        	*pc=Prepch;
    	    	*pcd=0;
            }
#ifdef UTF8UCS2                                                    //~va20I~
    		if (UDBCSCHK_DBCS1STLU(dbcsid))//reached to dbcs end   //~va20R~
#else                                                              //~va20I~
            if (dbcsid==UDBCSCHK_DBCS1ST)	//reached to dbcs top
#endif                                                             //~va20I~
                break;
        }
    }
    return ctr;	//cleared len
}//xesub_cleardbcs1                                                //~va20R~
//**************************************************               //~va20I~
//*xesub_getspan                                                   //~va20I~
//*ajust span by dbcs split                                        //~va20I~
//*rc:0x04:leftout of rabge,0x08:right out of range 0x01:left split,0x02:right split//~va20R~
//**************************************************               //~va20I~
int xesub_adjustspan(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos1,int Ppos2,int *Pppos1,int *Pppos2)//~va20I~
{                                                                  //~va20I~
    int splitctrl,splitctrl1,splitctrl2,splitctrr,splitctrr1,splitctrr2,pos1,pos2,rc=0;//~va20I~
//*************                                                    //~va20I~
    pos1=Ppos1;                                                    //~va20I~
    pos2=Ppos2;                                                    //~va20I~
	if (Ppos1>=0 && Ppos1<Plen)                                    //~va20R~
    {                                                              //~va20I~
    	splitctrl=XESUB_DBCSSPLITCTR(Pdbcs,Plen,Ppos1);            //~va20I~
        if (splitctrl)                                             //~va20I~
        {                                                          //~va20I~
	    	splitctrl2=XESUB_DBCSSPLITCTR_R(Pdbcs+Ppos1,Plen-Ppos1);//~va20R~
            splitctrl1=splitctrl-splitctrl2;                       //~va20I~
            if (Popt & XESUBCDSO_INCLEFT)                          //~va20I~
            	pos1-=splitctrl1;                                  //~va20I~
            else                                                   //~va20I~
            if (Popt & XESUBCDSO_EXCLEFT)                          //~va20I~
            	pos1+=splitctrl2;                                  //~va20I~
            rc|=1;	//split detected                               //~va20I~
        }                                                          //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    if (Ppos1>Plen)                                                //~va20I~
        rc|=4;                                                     //~va20R~
	if (Ppos2>=0 && Ppos2<Plen)                                    //~va20R~
    {                                                              //~va20I~
    	splitctrr=XESUB_DBCSSPLITCTR(Pdbcs,Plen,Ppos2);            //~va20I~
        if (splitctrr)                                             //~va20I~
        {                                                          //~va20I~
	    	splitctrr2=XESUB_DBCSSPLITCTR_L(Pdbcs,Ppos2);          //~va20R~
            splitctrr1=splitctrr-splitctrr2;                       //~va20I~
            if (Popt & XESUBCDSO_INCRIGHT)                         //~va20I~
            	pos2+=splitctrr2;                                  //~va20I~
            else                                                   //~va20I~
            if (Popt & XESUBCDSO_EXCRIGHT)                         //~va20I~
            	pos2-=splitctrr1;                                  //~va20I~
            rc|=2;	//split detected                               //~va27M~
        }                                                          //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    if (Ppos2>Plen)                                                //~va20I~
        rc|=8;                                                     //~va20R~
    *Pppos1=pos1;                                                  //~va20I~
    *Pppos2=pos2;                                                  //~va20I~
    return rc;                                                     //~va20I~
}//xesub_adjustspan                                                //~va20I~
#endif
//**************************************************               //~va20I~
//*xesub_imupdate                                                  //~va20I~//~va53R~
//*update plh of margined file                                     //~va20I~//~va53R~
//*rc:1:overflow,8:out of condition                                //~va53R~
//**************************************************               //~va20I~
int xesub_imupdate(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,int Ppos,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int *Ppnewlen)//~va53I~
{                                                                  //~va53I~
    int lenl,margin,lenr,lenv,lenm,swovf=0,ulhlen,offse,cutlen,newlen,chkspacelen,fixlrecl;//~va53R~
    UCHAR *pc,*pcd,*pdata,*pdbcs;                                  //~va53I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************                                //~va53I~
#ifdef UTF8EBCD                                                    //~va50I~
    swebcfile=PFH_ISEBC(Ppfh);                                     //~va50R~
#endif                                                             //~va50I~
    if (UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN))                      //~va53I~
        margin=Ppfh->UFHmergin;                                    //~va53I~
    else                                                           //~va53I~
    	margin=0;                                                  //~va53R~
    if (UCBITCHK(Ppfh->UFHflag7,UFHF7FIXLRECL))                    //~va53I~
        fixlrecl=Ppfh->UFHlrecl;                                   //~va53R~
    else                                                           //~va53I~
        fixlrecl=0;                                                //~va53I~
    if (Ppos>=margin)                                              //~va53R~
    {                                                              //~va50I~
    	if (Ppos<fixlrecl)                                         //~va53I~
        	margin=fixlrecl;                                       //~va53R~
    	else                                                       //~va53I~
        	return 8;                                              //~va53R~
    }                                                              //~va50I~
    pdata=Pplh->ULHdata;                                           //~va53I~
    pdbcs=Pplh->ULHdbcs;                                           //~va53I~
    ulhlen=Pplh->ULHlen;                                           //~va53I~
    if ((lenl=Ppos-ulhlen)>0)                                      //~va53I~
        ulhlen=Ppos;                                               //~va53I~
    if (Popt & XESUBIMUO_INS)                                      //~va53I~
    {                                                              //~va53I~
        offse=min(ulhlen,margin);  //right end data in matrgin     //~va53R~
        lenv=margin-offse; //availeable space                      //~va53I~
        if (Plen>lenv)		//no space to insert                   //~va53R~
        {                                                          //~va53I~
        	chkspacelen=Plen-lenv;                                 //~va53I~
//          if (offse>chkspacelen && umemspnc(pdata+offse-chkspacelen,' ',chkspacelen)!=(UINT)chkspacelen)//non space is shiftout//~va53R~//+vb28R~
            if (offse>chkspacelen && umemspnc(pdata+offse-chkspacelen,' ',(UINT)chkspacelen)!=(UINT)chkspacelen)//non space is shiftout//+vb28I~
                swovf=1;                                           //~va53I~
        }                                                          //~va53I~
        if (Ppos+Plen>margin)  //no space for data insert          //~va53R~
        {                                                          //~va53I~
            lenm=margin-Ppos;  //copy data len                     //~va53R~
            lenr=0;     //right half shift len                     //~va53I~
        }                                                          //~va53I~
        else                                                       //~va53I~
        {                                                          //~va53I~
            lenm=Plen;   //data full copy                          //~va53I~
            lenr=offse-Ppos;                                       //~va53I~
            cutlen=offse+Plen-margin;	//shift len                //~va53I~
            if (cutlen>0)                                          //~va53I~
                lenr-=cutlen;                                      //~va53R~
        }                                                          //~va53I~
        if (offse>=margin)  //data shift at margin                 //~va53R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	        setobtabdbcs(swebcfile,0/*plh*/,pdata,pdbcs,ulhlen,margin,0);	//split dbcs clear at start point//~va50I~
#else                                                              //~va50I~
	        setobtabdbcs(pdata,pdbcs,ulhlen,margin,0);	//split dbcs clear at start point//~va53I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	    setobtabdbcs(swebcfile,0/*plh*/,pdata,pdbcs,ulhlen,Ppos,0);	//split clear at insert point//~va50I~
#else                                                              //~va50I~
	    setobtabdbcs(pdata,pdbcs,ulhlen,Ppos,0);	//split clear at insert point//~va53I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    }                                                              //~va53I~
    else    //rep                                                  //~va53I~
    {                                                              //~va53I~
        lenr=0;     //no shift len                                 //~va53I~
        lenv=margin-Ppos;                                          //~va53I~
        if (Plen>lenv)  //no space for data insert                 //~va53I~
        {                                                          //~va53I~
            lenm=lenv;  //copy data len                            //~va53I~
            swovf=1;                                               //~va53I~
        }                                                          //~va53I~
        else                                                       //~va53I~
            lenm=Plen;   //data full copy                          //~va53I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	    setobtabdbcs(swebcfile,0/*plh*/,pdata,pdbcs,ulhlen,Ppos,lenm);	//split clear ob of rep data//~va50I~
#else                                                              //~va50I~
	    setobtabdbcs(pdata,pdbcs,ulhlen,Ppos,lenm);	//split clear ob of rep data//~va53I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
    }                                                              //~va53I~
    pc=Pplh->ULHdata+Ppos;                                         //~va53I~
    pcd=Pplh->ULHdbcs+Ppos;                                        //~va53I~
    if (lenl>0)     //pos is out of record                         //~va53R~
    {                                                              //~va53I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        UCVEBC_memset_space(swebcfile,pc-lenl,lenl);               //~va50I~
#else                                                              //~va50I~
        memset(pc-lenl,' ',lenl);                                  //~va53I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//      memset(pcd-lenl,0,lenl);                                   //~va53I~//+vb28R~
        memset(pcd-lenl,0,(size_t)lenl);                           //+vb28I~
    }                                                              //~va53I~
    if (Popt & XESUBIMUO_INS)                                      //~va53I~
    {                                                              //~va53I~
        if (lenr)                                                  //~va53I~
        {                                                          //~va53I~
            chartabclear(pcd,lenr);                                //~va53M~
//          memmove(pc+lenm,pc,lenr);                              //~va53I~//+vb28R~
            memmove(pc+lenm,pc,(size_t)lenr);                      //+vb28I~
//          memmove(pcd+lenm,pcd,lenr);                            //~va53I~//+vb28R~
            memmove(pcd+lenm,pcd,(size_t)lenr);                    //+vb28I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		    setobtabdbcs(swebcfile,0/*plh*/,pdata,pdbcs,ulhlen,Ppos+lenm+lenr,0);	//at margin after inserted//~va50I~
#else                                                              //~va50I~
		    setobtabdbcs(pdata,pdbcs,ulhlen,Ppos+lenm+lenr,0);	//at margin after inserted//~va53R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
        }                                                          //~va53I~
    }                                                              //~va53I~
//  memcpy(pc,Pdata,lenm);                                         //~va53I~//+vb28R~
    memcpy(pc,Pdata,(size_t)lenm);                                 //+vb28I~
    if (Pdbcs)	//source dbcs                                      //~va53R~
//      memcpy(pcd,Pdbcs,lenm);                                    //~va53I~//+vb28R~
        memcpy(pcd,Pdbcs,(size_t)lenm);                            //+vb28I~
    else                                                           //~va53I~
//      memset(pcd,0,lenm);                                        //~va53I~//+vb28R~
        memset(pcd,0,(size_t)lenm);                                //+vb28I~
    if (ulhlen>margin)                                             //~va53I~
        newlen=ulhlen;  //no change                                //~va53R~
    else                                                           //~va53I~
    	if (Popt & XESUBIMUO_INS)                                  //~va53I~
        	newlen=min(Ppos+lenm+lenr,margin);                     //~va53R~
        else                                                       //~va53I~
        	newlen=max(Ppos+lenm,ulhlen);                          //~va53I~
    *Ppnewlen=newlen;                                              //~va53R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (Popt & XESUBIMUO_SETNEWLEN)                                //~va50R~
    	Pplh->ULHlen=newlen;                                       //~va50I~
    if (Popt & XESUBIMUO_SETDBCSTBL)                               //~va50R~
    	if (swebcfile)                                             //~va50I~
		  	xeebc_setdbcstblplh(0,Ppfh,Pplh,newlen);               //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    return swovf;                                                  //~va53I~
}//xesub_imupdate                                                  //~va53I~
#ifdef UTF8UCS2                                                    //~va20I~
//**************************************************               //~va20I~
//!ddmemcmp                                                        //~va20R~
//*compare dd string                                               //~va20R~
//*if Pdbcs2==0, Pdata2 is ascii                                   //~va20R~
//*ret  :0 match,4:unmatch if eqchkonly, -1:0,+1 if highloow       //~va20R~
//**************************************************               //~va20I~
int xesubddmemcmp(int Popt,UCHAR *Pdata1,UCHAR *Pdbcs1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen)//~va20R~
{                                                                  //~va20I~
    char *pc1,*pcd1,*pc2;                                          //~va20R~
    int reslen,rc=0,opt;                                           //~va20R~
//*********************************                                //~va20I~
    UTRACED("xesubddstrcmp data1",Pdata1,Plen);                    //~va20I~
    UTRACED("xesubddstrcmp data2",Pdata2,Plen);                    //~va20I~
    UTRACED("xesubddstrcmp dbcs1",Pdbcs1,Plen);                    //~va20I~
    UTRACEDIFNZ("xesubddstrcmp dbcs2",Pdbcs2,Plen);                //~va20R~
    if (Popt & XESUBDDSCO_HIGHLOW)                                 //~va20R~
    {                                                              //~va20R~
//  	opt=0;                                                     //~va3PR~
    	opt=Popt & XESUBDDSCO_SPLITMASK;                           //~va3PI~
        if (Popt & XESUBDDSCO_NOCASE)                              //~va20R~
        	opt|=UTFDDCMPO_NOCASE;                                 //~va20R~
    	rc=utfddcmp(opt,Pdata1,Pdbcs1,Pdata2,Pdbcs2,Plen);         //~va20R~
    }                                                              //~va20R~
    else	//chk NOTEQ only                                       //~va20R~
    {                                                              //~va20R~
      	for (;;)                                                   //~va20I~
      	{                                                          //~va20I~
            if (!Pdbcs2)    //asccii                               //~va20I~
            {                                                      //~va20I~
                if (!utfddisasciistr(0,Pdata1,Pdbcs1,Plen)) //compare ascii//~va20R~
                {                                                  //~va20I~
                    rc=4;                                          //~va20I~
                    break;                                         //~va20I~
                }                                                  //~va20I~
            }                                                      //~va20I~
            else                                                   //~va20I~
            {                                                      //~va20I~
                if (utfddcmpdbcstab(0,Pdbcs1,Pdbcs2,Plen))//x09 on dbcstbl corresponding chk//~va20R~
                {                                                  //~va20R~
                    rc=4;                                          //~va20R~
                    break;                                         //~va20R~
                }                                                  //~va20R~
            }                                                      //~va20I~
            if (!memcmp(Pdata1,Pdata2,(UINT)Plen))                 //~va20I~
                break;                                             //~va20I~
            if (!(Popt & XESUBDDSCO_NOCASE))                       //~va20R~
            {                                                      //~va20I~
                rc=4;                                              //~va20R~
                break;                                             //~va20I~
            }                                                      //~va20I~
            for (reslen=Plen,pc1=Pdata1,pc2=Pdata2,pcd1=Pdbcs1;    //~va20R~
                    reslen>0;//dbcs is chked already               //~va20R~
                    pc1++,pc2++,pcd1++,reslen--)    //under dbcs matched//~va20R~
            {                                                      //~va20R~
                if (!*pcd1) //both ascii                           //~va20R~
                {                                                  //~va20R~
                    if (toupper(*pc1)!=toupper(*pc2))              //~va20R~
                        break;                                     //~va20R~
                }                                                  //~va20R~
                else                                               //~va20R~
                {                                                  //~va20R~
                    if (*pc1!=*pc2)                                //~va20R~
                        break;                                     //~va20R~
                }                                                  //~va20R~
            }                                                      //~va20R~
            if (reslen)                                            //~va20R~
                rc=4;                                              //~va20R~
            break;                                                 //~va20I~
      	}//for                                                     //~va20I~
    }                                                              //~va20R~
    UTRACEP("xesubddstrcmp rc=%d\n",rc);                           //~va20I~
    return rc;                                                     //~va20I~
}//*xesubddmemcmp                                                  //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va3PI~
//**************************************************               //~va3PI~
//!ebcmemcmp                                                       //~va3PI~
//*compare ebc string                                              //~va3PI~
//*if Pdbcs2==0, Pdata2 is ascii                                   //~va3PI~
//*ret  :0 match,4:unmatch if eqchkonly, -1:0,+1 if highloow       //~va3PI~
//**************************************************               //~va3PI~
//int xesubebcmemcmp(int Popt,UCHAR *Pdata1,UCHAR *Pdbcs1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen)//~va3PI~//~va79R~
int xesubebcmemcmp(int Popt,int Phandle,UCHAR *Pdata1,UCHAR *Pdbcs1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen)//~va79R~
{                                                                  //~va3PI~
    UCHAR *pc1,*pcd1,*pc2,*pebc,*pdbcs;                            //~va50R~
    int reslen,rc=0,opt,ebclen,rc2;                                //~va50R~
//*********************************                                //~va3PI~
    UTRACED("xesubebcmemcmp data1",Pdata1,Plen);                   //~va3PI~
    UTRACED("xesubebcmemcmp data2",Pdata2,Plen);                   //~va3PI~
    UTRACED("xesubebcmemcmp dbcs1",Pdbcs1,Plen);                   //~va3PI~
    UTRACEDIFNZ("xesubebcmemcmp dbcs2",Pdbcs2,Plen);               //~va3PI~
    if (Popt & XESUBDDSCO_BANDL)	//2nd operand is locale code   //~va50R~
    {                                                              //~va50I~
    	opt=0;                                                     //~va50I~
//  	rc2=xeebc_m2bsetdbcs(opt,Pdata2,Pdbcs2,Plen,&pebc,&pdbcs,&ebclen);//~va50I~//~va79R~
    	rc2=xeebc_m2bsetdbcs(opt,Phandle,Pdata2,Pdbcs2,Plen,&pebc,&pdbcs,&ebclen);//~va79I~
    	UALLOCCHKRC(rc2);                                          //~va50I~
        Pdata2=pebc;                                               //~va50I~
        Pdbcs2=pdbcs;                                              //~va50I~
        Plen=ebclen;                                               //~va50I~
    }                                                              //~va50I~
    if (Popt & XESUBDDSCO_HIGHLOW)                                 //~va50I~
    {                                                              //~va3PI~
        if (Popt & XESUBDDSCO_NOCASE)                              //~va50I~
        	opt=UCVEBCO_NOCASE;                                    //~va50I~
        else                                                       //~va50I~
        	opt=0;                                                 //~va50I~
//      rc=ucvebc_memcmp(opt,Pdata1,Pdbcs1,Pdata2,Pdbcs2,Plen);    //~va50R~//~va79R~
        rc=ucvebc_memcmp(opt,Phandle,Pdata1,Pdbcs1,Pdata2,Pdbcs2,Plen);//~va79I~
    }                                                              //~va3PI~
    else	//chk NOTEQ only                                       //~va3PI~
    {                                                              //~va3PI~
      	for (;;)                                                   //~va3PI~
      	{                                                          //~va3PI~
            if (!Pdbcs2)    //asccii                               //~va3PI~
            {                                                      //~va3PI~
                if (!ucvebc_issbcsstr(0,Pdbcs1,Plen)) //compare ascii//~va3PR~
                {                                                  //~va3PI~
                    rc=4;                                          //~va3PI~
                    break;                                         //~va3PI~
                }                                                  //~va3PI~
            }                                                      //~va3PI~
            else                                                   //~va3PI~
            {                                                      //~va3PI~
//              if (memcmp(Pdbcs1,Pdbcs2,Plen))	//dbcstbl unmatch  //~va3PR~//+vb28R~
                if (memcmp(Pdbcs1,Pdbcs2,(size_t)Plen))	//dbcstbl unmatch//+vb28I~
                {                                                  //~va3PI~
                    rc=4;                                          //~va3PI~
                    break;                                         //~va3PI~
                }                                                  //~va3PI~
            }                                                      //~va3PI~
            if (!memcmp(Pdata1,Pdata2,(UINT)Plen))                 //~va3PI~
                break;                                             //~va3PI~
            if (!(Popt & XESUBDDSCO_NOCASE))                       //~va3PI~
            {                                                      //~va3PI~
                rc=4;                                              //~va3PI~
                break;                                             //~va3PI~
            }                                                      //~va3PI~
//*case insensitive compare                                        //~va3PI~
            for (reslen=Plen,pc1=Pdata1,pc2=Pdata2,pcd1=Pdbcs1;    //~va3PI~
                    reslen>0;//dbcs is chked already               //~va3PI~
                    pc1++,pc2++,pcd1++,reslen--)    //under dbcs matched//~va3PI~
            {                                                      //~va3PI~
                if (!*pcd1) //both ascii                           //~va3PI~
                {                                                  //~va3PI~
//                  if (EBC_toupper(*pc1)!=EBC_toupper(*pc2))      //~va3PR~//~va79R~
                    if (UCVEBCH_toupper(Phandle,*pc1)!=UCVEBCH_toupper(Phandle,*pc2))//~va79R~
                        break;                                     //~va3PI~
                }                                                  //~va3PI~
                else                                               //~va3PI~
                {                                                  //~va3PI~
                    if (*pc1!=*pc2)                                //~va3PI~
                        break;                                     //~va3PI~
                }                                                  //~va3PI~
            }                                                      //~va3PI~
            if (reslen)                                            //~va3PI~
                rc=4;                                              //~va3PI~
            break;                                                 //~va3PI~
      	}//for                                                     //~va3PI~
    }                                                              //~va3PI~
    UTRACEP("xesubebcstrcmp rc=%d\n",rc);                          //~va3PR~
    return rc;                                                     //~va3PI~
}//xesubebcmemcmp                                                  //~va3PI~
//**************************************************               //~va8wI~
//*inbound                                                         //~va8wI~
//**************************************************               //~va8wI~
int xesub_setdbcssplitib(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos,char Prepch)//~va8wI~
{                                                                  //~va8wI~
    UCHAR *pc,*pcd;                                                //~va8wI~
    int swebcfile,len,opt;                                         //~va8wI~
//*********************************                                //~va8wI~
	opt=Popt;                                                      //~va8wI~
    swebcfile=(Popt & XESUBSDSO_EBCMASK);                          //~va8wI~
    pc=Pdata+Ppos;                                                 //~va8wI~
    pcd=Pdbcs+Ppos;                                                //~va8wI~
    len=Plen-Ppos;                                                 //~va8wI~
    opt=Popt;                                                      //~va8wI~
    if (swebcfile)                                                 //~va8wI~
	    if (Ppos>0 && *(pcd-1)==UDBCSCHK_DBCS2ND)                  //~va8wR~
    		opt|=XESUBSDSO_PREV2ND;                                //~va8wR~
	return xesub_setdbcssplit(opt,Pplh,pc,pcd,len,Prepch);         //~va8wI~
}//xesub_setdbcssplitib                                            //~va8wI~
//**************************************************               //~va50I~
//!dbcssplit for ebc file                                          //~va50I~
//*re-evaluate dbcstbl after update plh,no split dbcs rep          //~va50R~
//*re-Pdata should be on plhdata                                   //~va50I~
//*rc:split ctr                                                    //~va50R~
//**************************************************               //~va50I~
int xesub_setdbcssplit(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,char Prepch)//~va50I~
{                                                                  //~va50I~
    int swebcfile,len,offs;                                        //~va50R~
    PUFILEH pfh;                                                   //~va50R~
    UCHAR *pdata0,*pdbcs0;                                         //~va50I~
    int handle=0;                                                  //~va79I~
    int repchebc;                                                  //~va8jI~
    int opt;                                                       //~va8jI~
    int splitctrl;                                                 //~va8sI~
//*********************************                                //~va50I~
    swebcfile=(Popt & XESUBSDSO_EBCMASK);                          //~va50R~
    if (Pplh)                                                      //~va50I~
    {                                                              //~va50I~
        pfh=UGETPFH(Pplh);                                         //~va50I~
		if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                      //~va50I~
        	return 0;                                              //~va50I~
	    swebcfile|=PFH_ISEBC(pfh);                                 //~va50R~
        handle=pfh->UFHhandle;                                     //~va79I~
    }                                                              //~va50I~
    if (!swebcfile)                                                //~va50I~
    {                                                              //~va8sI~
		if (Popt & XESUBSDSO_GETSPLITCTR)      //get counter replaced to space//~va8sI~
        {                                                          //~va8sI~
        	splitctrl=XESUB_DBCSSPLITCTR_R(Pdbcs,Plen);	//right half of left boundary//~va8sI~
        	return  splitctrl;                                     //~va8sI~
        }                                                          //~va8sI~
    	return setdbcssplit(0,Pdata,Pdbcs,Plen,Prepch);            //~va50R~
    }                                                              //~va8sI~
    if (Popt & XESUBSDSO_NOSBCSIFEBC)       //no SBCS option for EBC file//~va8jI~
    {                                                              //~va8jI~
        repchebc=UCVEBCH_A2B(handle,Prepch);                       //~va8jI~
        opt=0;                                                     //~va8jI~
	    if (Popt & XESUBSDSO_HALFCUTONLY)       //no SBCS option for EBC file//~va8jI~
	    	opt|=XEEBCSDSO_HALFCUTONLY;  //rep half cut only       //~va8jI~
	    if (Popt & XESUBSDSO_HALFCUTONLYL)       //no SBCS option for EBC file//~va8wI~
	    	opt|=XEEBCSDSO_HALFCUTONLYL;  //rep half cut only      //~va8wI~
	    if (Popt & XESUBSDSO_HALFCUTONLYR)       //no SBCS option for EBC file//~va8wI~
	    	opt|=XEEBCSDSO_HALFCUTONLYR;  //rep half cut only      //~va8wI~
		if (Popt & XESUBSDSO_GETSPLITCTR)      //get counter replaced to space//~va8sI~
	    	opt|=XEEBCSDSO_GETSPLITCTR;  //get space ctr replaced  //~va8sR~
		if (Popt & XESUBSDSO_PREV2ND)                              //~va8wI~
    		opt|=XEEBCSDSO_PREV2ND;                                //~va8wI~
		if (Popt & XESUBSDSO_NEXT1ST)                              //~va8wI~
    		opt|=XEEBCSDSO_NEXT1ST;                                //~va8wI~
    	return xeebc_setdbcssplitsetsosi(opt,Pdata,Pdbcs,Plen,repchebc);//~va8jR~
    }                                                              //~va8jI~
    if (!Pplh)	//no setdbcstbl                                    //~va50I~
    	return 0;                                                  //~va50I~
    if (!(Popt & XESUBSDSO_SETDBCSTBL))	//no re-evaluate dbcstbl requested//~va50I~
    	return 0;                                                  //~va50I~
//for ebc file,re- evalluate dbcstbl                               //~va50I~
	UTRACED("xeebc_asetdbcssplit plhdata",Pplh->ULHdata,Pplh->ULHlen);//~va50I~
	UTRACED("xeebc_asetdbcssplit plhdbcs",Pplh->ULHdbcs,Pplh->ULHlen);//~va50I~
	UTRACEDIFNZ("xeebc_asetdbcssplit   data ",Pdata,Plen);         //~va50R~
	UTRACEDIFNZ("xeebc_asetdbcssplit   dbcs ",Pdbcs,Plen);         //~va50R~
//  if (UDBCSCHK_ISDBCSCV())                                       //~va50I~//~va79R~
    if (UCVEBCH_HANDLE_ISDBCSCV(handle))                           //~va79I~
    {                                                              //~va50I~
                                                                   //~va50I~
        len=Pplh->ULHlen;                                          //~va50I~
        pdata0=Pplh->ULHdata;                                      //~va50I~
        pdbcs0=Pplh->ULHdbcs;                                      //~va50R~
        if (Pdata)                                                 //~va50I~
        {                                                          //~va50I~
//        	offs=(ULONG)Pdata-(ULONG)pdata0;                       //~va50R~//~vafkR~
//      	offs=(ULPTR)Pdata-(ULPTR)pdata0;                       //~vafkI~//+vb28R~
        	offs=(int)((ULPTR)Pdata-(ULPTR)pdata0);                //+vb28I~
        	len=max(len,offs+Plen);                                //~va50R~
        }                                                          //~va50I~
//  	xeebc_setdbcstbl(0,pdata0,pdbcs0,len);                     //~va50R~//~va79R~
    	xeebc_setdbcstbl(0,handle,pdata0,pdbcs0,len);              //~va79I~
    }                                                              //~va50I~
    return 0;                                                      //~va50R~
}//xesub_setdbcssplit                                              //~va50R~
//**************************************************               //~va7xI~
//!bin mode comapore except for utf8                               //~va7xR~
// tabexpand is ignored,dbcs is not considered                     //~va7xI~
//**************************************************               //~va7xI~
int xesub_memcmpbin(int Popt,UCHAR *Pdata1,UCHAR *Pdbcs1,int Plen1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen2,//~va7xR~
					int *Pppos1,int *Pppos2)                       //~va7xI~
{                                                                  //~va7xI~
	UCHAR *pc1,*pc2,*pcd1,*pcd2,*pc1e,*pc2e;                       //~va7xI~
    int ch1,ch2;                                                   //~va7xI~
    int unmatchsw;                                                 //~va7xR~
//******************                                               //~va7xI~
	unmatchsw=0;                                                   //~va7xI~
	for (pc1=Pdata1,pcd1=Pdbcs1,pc2=Pdata2,pcd2=Pdbcs2,pc1e=pc1+Plen1,pc2e=pc2+Plen2;//~va7xR~
			pc1<pc1e && pc2<pc2e;                                  //~va7xI~
			pc1++,pc2++,pcd1++,pcd2++)                             //~va7xI~
    {                                                              //~va7xI~
    	while (pc1<pc1e && *pcd1==UDBCSCHK_TABPADCHAR)             //~va7xR~
        	pc1++,pcd1++;                                          //~va7xI~
    	while (pc2<pc2e && *pcd2==UDBCSCHK_TABPADCHAR)             //~va7xR~
        	pc2++,pcd2++;                                          //~va7xI~
		if (pc1>=pc1e || pc2>=pc2e)                                //~va7xI~
        {                                                          //~va7xI~
        	if (pc1<pc1e||pc2<pc2e)                                //~va7xI~
            	unmatchsw=1;                                       //~va7xI~
        	break;                                                 //~va7xI~
        }                                                          //~va7xI~
        ch1=*pc1;                                                  //~va7xI~
        ch2=*pc2;                                                  //~va7xI~
        if (*pcd1==UDBCSCHK_TABCHAR)                               //~va7xI~
            ch1=UDBCSCHK_TABCHAR;                                  //~va7xI~
        if (*pcd2==UDBCSCHK_TABCHAR)                               //~va7xI~
            ch2=UDBCSCHK_TABCHAR;                                  //~va7xI~
        if (ch1!=ch2)	//no dbcs chk                              //~va7xR~
        {                                                          //~va7xI~
        	unmatchsw=1;                                           //~va7xI~
        	break;                                                 //~va7xI~
        }                                                          //~va7xI~
    }                                                              //~va7xI~
//  *Pppos1=(ULONG)pc1-(ULONG)Pdata1;                              //~va7xI~//~vafkR~
//  *Pppos1=(ULPTR)pc1-(ULPTR)Pdata1;                              //~vafkI~//+vb28R~
    *Pppos1=(int)((ULPTR)pc1-(ULPTR)Pdata1);                       //+vb28I~
//  *Pppos2=(ULONG)pc2-(ULONG)Pdata2;                              //~va7xI~//~vafkR~
//  *Pppos2=(ULPTR)pc2-(ULPTR)Pdata2;                              //~vafkI~//+vb28R~
    *Pppos2=(int)((ULPTR)pc2-(ULPTR)Pdata2);                       //+vb28I~
    return unmatchsw;                                              //~va7xI~
}                                                                  //~va7xI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va3PI~
