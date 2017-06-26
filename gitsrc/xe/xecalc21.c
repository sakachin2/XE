//*CID://+vb2DR~:                                   update#=  117; //+vb2DR~
//*************************************************************
//*xecalc21.c                                                      //~va7aR~
//* table calc(TC cmd) ft1                                         //~va7aR~
//*************************************************************
//vb2D:160221 LNX compiler warning                                 //+vb2DI~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vauM:140319 (BUG)crash when tc fld+/keyfld with aft\bef option(access deleted sumline if exist)//~vauMR~
//vap0:131215 (ARM)warning strict aliasing                         //~vao0I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//va7a:100817 split xecalc2.c                                      //~va7aI~
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
#include <uque.h>
#include <ufile.h>
#include <ualloc.h>
#include <uedit.h>
#include <ustring.h>
#include <uparse.h>
#include <ucalc.h>                                                 //~v17iI~
#include <ucalc2.h>                                                //~v51mI~
#ifdef UTF8UCS2                                                    //~va20R~
#include <utf22.h>                                                 //~va20R~
#include <utrace.h>                                                //~va20R~
#endif                                                             //~va20R~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc.h>                                                //~va50I~
#include <ucvebc4.h>                                               //~va79I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xeundo.h"
#include "xecap.h"
#include "xecalc2.h"
#include "xecalc21.h"                                              //~va7aI~
#include "xeerr.h"
#include "xechar2.h"
#include "xelcmd.h"
#include "xelcmd2.h"
#include "xefcmd.h"	                                               //~v62tI~
#include "xesub.h"
#include "xesub2.h"                                                //~va50I~
#ifdef UTF8UCS2                                                    //~va20R~
#include "xeutf2.h"                                                //~va20R~
#endif                                                             //~va20R~
#include "xeebc.h"                                                 //~va50I~
#include "xefcmd6.h"                                               //~va79I~
//*******************************************************
int tc_updateprofile(int Popt,XECALCPARM *Pparm,PUFILEH Ppfh);     //~va79I~
//****************************************************************
// 1 table calc
//*rc   :0   or 1:data err or 4:env err or UALLOC_FAILED
//****************************************************************
//int tc_ft1(PUCLIENTWE Ppcw,int Pfunctype,int *Pparm,PULINEH *Plabplh)//~va70R~
int tc_ft1(PUCLIENTWE Ppcw,int Pfunctype,XECALCPARM *Pparm,PULINEH *Plabplh)//~va70I~
{
	PUFILEH pfht;
	PULINEH plh,plht1,plht2,plhtop,plhend;
	int     post1,post2,sw1strec,rc=0,width,datatype,datatype0,len6sw;
	int     convdatatype0,convdatatype;                            //~v51mR~
//  long    lvt[3],lvto[3],lvtt[3];                                //~v57JR~
//  long    lvt[4],lvto[4],lvtt[4];                                //~v57JI~//~vafkR~
    SLPTR   lvt[4],lvto[4],lvtt[4];                                //~vafkI~
    long    recno=0,skipno=0,dataovf=0,totcnt=0;
//  int     signsw=0;                                              //~v58aR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int opt;                                                       //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************
    pfht=UGETPFHFROMPCW(Ppcw);
	plhtop=UGETQTOP(&pfht->UFHlineque);
	plhend=UGETQEND(&pfht->UFHlineque);
    if (*Plabplh)
    {
		plht1=*Plabplh;
		plht2=*(Plabplh+1);
    }
    else
    {
		plht1=plhtop;
		plht2=plhend;
    }
//  post1=Pparm[PARM_OPD1POS1];                                    //~vaz8R~
    post1=(int)Pparm[PARM_OPD1POS1];                               //~vaz8I~
//  post2=Pparm[PARM_OPD1POS2];                                    //~vaz8R~
    post2=(int)Pparm[PARM_OPD1POS2];                               //~vaz8I~
    width=post2-post1;                                             //~v51mI~
    if (width>MAX_DATA_WIDTH)                                      //~v51mI~
    	return tcerrdatawidth();                                   //~v51mI~
//target
    if (Pfunctype==CALC_TARGET)
    {
		if (!Pparm[PARM_OPD1POS2])
        	plht1=plht2=0;		//block of f7
        return cap_savecalcinfo(Ppcw,plht1,plht2,post1,post2);
    }
//calc
	if (!Pparm[PARM_OPD1POS2])
    	if (cap_getcalccurinfo(Ppcw,&plht1,&plht2,&post1,&post2))
        	return 4;

//    if (plht1==plhtop)                                           //~v170R~
//    {                                                            //~v170R~
//        plht1=UGETQNEXT(plht1);                                  //~v170R~
//        if (plht1==plhend)                                       //~v170R~
//            return 4;                                            //~v170R~
//    }                                                            //~v170R~
//    if (plht2==plhend)                                           //~v170R~
//        plht2=UGETQPREV(plht2);                                  //~v170R~

//  width=post2-post1;                                             //~v51mR~
//  if (width>MAX_DATA_WIDTH)                                      //~v51mR~
//  	return tcerrdatawidth();                                   //~v51mR~
//  if (Pfunctype==CALC_TARGET)                                    //~v51mR~
//  	return 0;                                                  //~v51mR~
    if (Pfunctype==CALC_SUM)
		return tc_ft1sum(Ppcw,plht1,plht2,post1,post2,Pparm);

	UPCTRREQ(pfht);	//end of a shot
//  datatype0=Pparm[PARM_DATATYPE1];                               //~vaz8R~
    datatype0=(int)Pparm[PARM_DATATYPE1];                          //~vaz8I~
//  if (datatype0=='D')                                            //~v57JR~
//      signsw=CALC_SIGNED;                                        //~v57JR~
//  convdatatype0=Pparm[PARM_KEYDATATYPE];	//for datatype conversion//~vaz8R~
    convdatatype0=(int)Pparm[PARM_KEYDATATYPE];	//for datatype conversion//~vaz8I~
    len6sw=0;
    for (plh=plht1,sw1strec=1;;sw1strec=0)
    {
        datatype=datatype0;
//  	rc=tc_getplhdata(sw1strec,&datatype,&plh,plht2,post1,post2,lvt,Pparm);//~v57JR~
    	rc=tc_getplhdata(GDO_DWUP,sw1strec,&datatype,&plh,plht2,post1,post2,lvt,Pparm);//~v57JI~
        if (rc==-1)	//eof
        	break;
        recno++;
        if (rc==1)      //hhmmss fmt
            len6sw=CALC_TIME6;
        else
        if (rc==2)
        {
            skipno+=tc_setplherr(plh);
            continue;
        }
        else
        if (rc==4)
        {
            skipno++;
            continue;
        }
        else
		if (rc)
        	break;      //alloc  failed

		if (tc_ft1sumdatatype(totcnt,plh,&datatype0,datatype,&skipno))
            continue;
        convdatatype=datatype;                                     //~v51mR~
        switch(Pfunctype)
        {
        case CALC_DIF:      //differrence
        	if (!totcnt)
//          	memset(lvtt,0,DDECSZ);                             //~v57JR~
//          	ucalc_dwupinit(lvtt);	//set 0                    //~v57XR~
            	memset(lvtt,0,DDECSZ);                             //~v57XI~
            else
            {
//          	memcpy(lvtt,lvt,DDECSZ);                           //~v57JR~
//          	ucalc_dwupset(lvtt,lvt);                           //~v57JR~
//          	ucalc_dwupset(signsw,lvtt,lvt);                    //~v57XR~
            	memcpy(lvtt,lvt,DDECSZ);                           //~v57XI~
            	if (tc_calc(0,datatype,'-',lvtt,lvto)!=0)
		            skipno+=tc_setplherr(plh);
            }
//          memcpy(lvto,lvt,DDECSZ);                               //~v57JR~
//          ucalc_dwupset(lvto,lvt);                               //~v57JR~
//          ucalc_dwupset(signsw,lvto,lvt);                        //~v57XR~
            memcpy(lvto,lvt,DDECSZ);                               //~v57XI~
            break;
        case CALC_ACUM:     //accumulation
        	if (!totcnt)
//              memcpy(lvtt,lvt,DDECSZ);                           //~v57JR~
//              ucalc_dwupset(lvtt,lvt);                           //~v57JR~
//              ucalc_dwupset(signsw,lvtt,lvt);                    //~v57XR~
                memcpy(lvtt,lvt,DDECSZ);                           //~v57XI~
            else
            	if (tc_calc(0,datatype,'+',lvtt,lvt)!=0)
		            skipno+=tc_setplherr(plh);
            break;
        case CALC_CONV:     //data type conversion                 //~v51mI~
        	convdatatype=convdatatype0;                            //~v51mI~
            switch(convdatatype)                                   //~v51mI~
            {                                                      //~v51mI~
        	case 'L':	//conv to local time                       //~v51mR~
            	if (datatype=='T')	//line data is time stamp      //~v51mI~
		            skipno+=tc_setplherr(plh);                     //~v51mI~
                break;                                             //~v51mI~
        	case 'T':	//conv to local time                       //~v51mI~
            	if (datatype!='T')	//line data is time stamp      //~v51mI~
            		ucalc_time(CALC_TIME_CONV2HMS,'=',lvt,lvt);   //conv to sec//~v51mI~
                break;                                             //~v51mI~
            default:                                               //~v51mI~
            	if (datatype=='T')	//line data is time stamp      //~v51mI~
            		ucalc_time(CALC_TIME_CONV2SEC,'=',lvt,lvt);   //conv to sec//~v51mI~
                break;                                             //~v51mI~
            }                                                      //~v51mI~
//          memcpy(lvtt,lvt,DDECSZ);                               //~v57JR~
//          ucalc_dwupset(lvtt,lvt);                               //~v57JR~
//          ucalc_dwupset(signsw,lvtt,lvt);                        //~v57XR~
            memcpy(lvtt,lvt,DDECSZ);                               //~v57XI~
            break;                                                 //~v51mI~
        }//operation
        if (!(!totcnt && Pfunctype==CALC_DIF))
//          if ((rc=tc_setlinedata(Ppcw,plh,1,datatype|len6sw,post1,post2,lvtt,&dataovf))>1)//~v51mR~
//          if ((rc=tc_setlinedata(Ppcw,plh,1,convdatatype|len6sw,post1,post2,lvtt,&dataovf))>1)//~v58vR~
            if ((rc=tc_setlinedata(Ppcw,Pparm,plh,1,convdatatype|len6sw,post1,post2,lvtt,&dataovf))>1)//~v58vI~
		        	break;
        totcnt++;
	}//all plh
	if (rc==UALLOC_FAILED)
    	return rc;
    UPCTRREQ(pfht); //end of a shot
//  uerrmsg("%s:total %ld, err=%ld, outovf=%ld",0,                 //~v71UR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	opt=XEERMO_CAT;                                                //~va50I~
    xeerrmsg(opt,4,XEERMPTS_CMDSTR XEERMPTS_NOTSTR XEERMPTS_NOTSTR XEERMPTS_NOTSTR,//~va50R~
		"%s:total %ld, err=%ld, outovf=%ld",0,                     //~va50I~
        Ppcw->UCWparm,recno,skipno,dataovf);                       //~va50I~
#else                                                              //~va50I~
    uerrmsgcat("%s:total %ld, err=%ld, outovf=%ld",0,              //~v71UI~
        Ppcw->UCWparm,recno,skipno,dataovf);
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    return skipno||dataovf;
}//tc_ft1
//****************************************************************
// table summary
//*rc   :0   or 1:data err or 4:env err or 8:seq down, or UALLOC_FAILED
//****************************************************************
int tc_ft1sum(PUCLIENTWE Ppcw,
//				PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,int *Pparm)//~va70R~
				PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,XECALCPARM *Pparm)//~va70I~
{
	PUFILEC pfc;
	PUFILEH pfht;
	int rc,ctlbreak;
    char  *outfnm,fpath[_MAX_PATH];                                //~v62FI~
//*********************************
//  	if (outfnm=dcmdfullpath(Ppcw,fpath,outfnm),!outfnm)        //~v62FI~
//	outfnm=(char*)(ULONG)Pparm[PARM_OUTFNM];                       //~v62FI~//~vafkR~
	outfnm=(char*)(XECALCPARM)Pparm[PARM_OUTFNM];                  //~vafkI~
    if (outfnm)                                                    //~v62FI~
    {                                                              //~v62FI~
		if (fcmdoutfnmedit(Ppcw,outfnm,fpath))	//wildcard support //~v62FI~
        	return 4;                                              //~v62FI~
//		Pparm[PARM_OUTFPATH]=(int)fpath;                           //~v62LR~//~va70R~
  		Pparm[PARM_OUTFPATH]=(XECALCPARM)fpath;                    //~va70I~
    }                                                              //~v62FI~
    pfc=Ppcw->UCWpfc;
    pfht=pfc->UFCpfh;
//  ctlbreak=*(Pparm+PARM_BREAKTYPE);                              //~vaz8R~
    ctlbreak=(int)(*(Pparm+PARM_BREAKTYPE));                       //~vaz8I~
    if (!UCBITCHK(pfc->UFCflag,UFCFBROWSE))
    	UPCTRREQ(pfht); //end of a shot
    switch(ctlbreak)
    {
    case PARM_BREAK_COUNT:    //summary by count
    case PARM_BREAK_KEY:      //ctl break by key change
    case PARM_BREAK_KEYGRP:   //ctl break by key value distance
    case PARM_BREAK_KEY_EQ:      //ctl break by key change         //~v53DI~
    case PARM_BREAK_KEYGRP_EQ:   //ctl break by key value distance //~v53DI~
    case PARM_BREAK_KEY_LT:      //ctl break by key change         //~v53DI~
    case PARM_BREAK_KEYGRP_LT:   //ctl break by key value distance //~v53DI~
		rc=tc_ft1sumkey(Ppcw,Pplh1,Pplh2,Ppos1,Ppos2,Pparm);
        break;
    default:
		rc=tc_ft1sumnobreak(Ppcw,Pplh1,Pplh2,Ppos1,Ppos2,Pparm);
    }
    if (!UCBITCHK(pfc->UFCflag,UFCFBROWSE))
    	UPCTRREQ(pfht); //end of a shot
    if (Pparm[PARM_OUTFH]) 	//output file opend                    //~v58zI~
    {                                                              //~v62FI~
    	fclose((FILE*)Pparm[PARM_OUTFH]); 	//output file opend    //~v58zI~
        tc_updateprofile(0,Pparm,pfht);                            //~va79I~
        if (WILDCARD(outfnm))                                      //~v62FI~
        	uerrmsgcat(" (-->%s)",0,                               //~v62FR~
            			fpath);                                    //~v62FI~
    }                                                              //~v62FI~
	return rc;
}//tc_ft1sum
//****************************************************************
// set data type by fisrt line
//*rc   :0   or 1:err
//****************************************************************
int tc_ft1sumdatatype(long Pdatactr,PULINEH Pplh,int *Pdatatype,int Plinedatatype,long *Pskipno)
{
	int datatype;
//**************
	datatype=*Pdatatype;
    if (!Pdatactr)	//1st record
    	if (!datatype)
        	datatype=*Pdatatype=Plinedatatype;
    if ((datatype=='T' && Plinedatatype!='T')                      //~v40RR~
    ||  (datatype!='T' && Plinedatatype=='T'))                     //~v40RR~
    {
        *Pskipno=*Pskipno+tc_setplherr(Pplh);
        return 1;
	}
	return 0;
}//tc_ft1sumdatatype
//****************************************************************
// calc total
//*rc   :4
//****************************************************************
//int tc_ft1sumtotal(long *Plvt,int Pdatatype,                     //~vafkR~
int tc_ft1sumtotal(SLPTR *Plvt,int Pdatatype,                      //~vafkI~
//                  long Ptotctr,long *Ptotsum,long *Ptotmin,long *Ptotmax,//~vafkR~
                    long Ptotctr,SLPTR *Ptotsum,SLPTR *Ptotmin,SLPTR *Ptotmax,//~vafkI~
//                  long Psubctr,long *Psubsum,long *Psubmin,long *Psubmax)//~vafkR~
                    long Psubctr,SLPTR *Psubsum,SLPTR *Psubmin,SLPTR *Psubmax)//~vafkI~
{
	int rc=0;
//  int signsw=0;                                                  //~v58aR~
//**************
//grand total
//  if (Pdatatype=='D')                                            //~v57JR~
//  	signsw=CALC_SIGNED;                                        //~v57JR~
    if (!Ptotctr)
    {
//      memcpy(Ptotsum,Plvt,DDECSZ);                               //~v57JR~
//      memcpy(Ptotmin,Plvt,DDECSZ);                               //~v57JR~
//      memcpy(Ptotmax,Plvt,DDECSZ);                               //~v57JR~
//      ucalc_dwupset(Ptotsum,Plvt);                               //~v57JR~
//      ucalc_dwupset(Ptotmin,Plvt);                               //~v57JR~
//      ucalc_dwupset(Ptotmax,Plvt);                               //~v57JR~
//      ucalc_dwupset(signsw,Ptotsum,Plvt);                        //~v57XR~
//      ucalc_dwupset(signsw,Ptotmin,Plvt);                        //~v57XR~
//      ucalc_dwupset(signsw,Ptotmax,Plvt);                        //~v57XR~
        memcpy(Ptotsum,Plvt,DDECSZ);                               //~v57XI~
        memcpy(Ptotmin,Plvt,DDECSZ);                               //~v57XI~
        memcpy(Ptotmax,Plvt,DDECSZ);                               //~v57XI~
    }
    else
    {
        tc_calc(0,Pdatatype,'+',Ptotsum,Plvt);
        if (tc_calc(0,Pdatatype,'?',Ptotmin,Plvt)>0)
//          memcpy(Ptotmin,Plvt,DDECSZ);                           //~v57JR~
//          ucalc_dwupset(Ptotmin,Plvt);                           //~v57JR~
//          ucalc_dwupset(signsw,Ptotmin,Plvt);                    //~v57XR~
            memcpy(Ptotmin,Plvt,DDECSZ);                           //~v57XI~
        if (tc_calc(0,Pdatatype,'?',Ptotmax,Plvt)<0)
//          memcpy(Ptotmax,Plvt,DDECSZ);                           //~v57JR~
//          ucalc_dwupset(Ptotmax,Plvt);                           //~v57JR~
//          ucalc_dwupset(signsw,Ptotmax,Plvt);                    //~v57XR~
            memcpy(Ptotmax,Plvt,DDECSZ);                           //~v57XI~
    }
//sub   total
    if (!Psubctr)
    {
//      memcpy(Psubsum,Plvt,DDECSZ);                               //~v57JR~
//      memcpy(Psubmin,Plvt,DDECSZ);                               //~v57JR~
//      memcpy(Psubmax,Plvt,DDECSZ);                               //~v57JR~
//      ucalc_dwupset(Psubsum,Plvt);                               //~v57JR~
//      ucalc_dwupset(Psubmin,Plvt);                               //~v57JR~
//      ucalc_dwupset(Psubmax,Plvt);                               //~v57JR~
//      ucalc_dwupset(signsw,Psubsum,Plvt);                        //~v57XR~
//      ucalc_dwupset(signsw,Psubmin,Plvt);                        //~v57XR~
//      ucalc_dwupset(signsw,Psubmax,Plvt);                        //~v57XR~
        memcpy(Psubsum,Plvt,DDECSZ);                               //~v57XI~
        memcpy(Psubmin,Plvt,DDECSZ);                               //~v57XI~
        memcpy(Psubmax,Plvt,DDECSZ);                               //~v57XI~
    }
    else
    {
        if (tc_calc(0,Pdatatype,'+',Psubsum,Plvt)!=0)
            rc=4;
        if (tc_calc(0,Pdatatype,'?',Psubmin,Plvt)>0)
//          memcpy(Psubmin,Plvt,DDECSZ);                           //~v57JR~
//          ucalc_dwupset(Psubmin,Plvt);                           //~v57JR~
//          ucalc_dwupset(signsw,Psubmin,Plvt);                    //~v57XR~
            memcpy(Psubmin,Plvt,DDECSZ);                           //~v57XI~
        if (tc_calc(0,Pdatatype,'?',Psubmax,Plvt)<0)
//          memcpy(Psubmax,Plvt,DDECSZ);                           //~v57JR~
//          ucalc_dwupset(Psubmax,Plvt);                           //~v57JR~
//          ucalc_dwupset(signsw,Psubmax,Plvt);                    //~v57XR~
            memcpy(Psubmax,Plvt,DDECSZ);                           //~v57XI~
    }
	return rc;
}//tc_ft1sumtotal
//****************************************************************
// table summary (che = fld)
//*rc   :0   or 1:data err or 4:env err or 8:seq down, or UALLOC_FAILED
//****************************************************************
int tc_ft1sumnobreak(PUCLIENTWE Ppcw,
//				PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,int *Pparm)//~va70R~
				PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,XECALCPARM *Pparm)//~va70I~
{
	PUFILEC pfc;
	PULINEH plh,plhgsum=0,plhisrtafter,plhisrtbefore;              //~v170R~
	int     sw1strec,rc=0,datatype,datatype0,len6sw,browsesw,width;
//  long    lvt[3],lvtt[3],summin[3],summax[3];                    //~v57JR~
//  long    lvt[4],lvtt[4],summin[4],summax[4];                    //~v57JI~//~vafkR~
    SLPTR   lvt[4],lvtt[4],summin[4],summax[4];                    //~vafkI~
//  long    totsum[3],totmin[3],totmax[3];                         //~v57JR~
//  long    totsum[4],totmin[4],totmax[4];                         //~v57JI~//~vafkR~
    SLPTR   totsum[4],totmin[4],totmax[4];                         //~vafkI~
    long    recno=0,skipno=0,dataovf=0,subtot=0,totcnt=0;
    char    summline[128];
    void   *psumm;                                                 //~vao0I~
//*********************************
    pfc=Ppcw->UCWpfc;
//  datatype0=Pparm[PARM_DATATYPE1];                               //~vaz8R~
    datatype0=(int)Pparm[PARM_DATATYPE1];                          //~vaz8I~
    browsesw=UCBITCHK(pfc->UFCflag,UFCFBROWSE);
    width=Ppos2-Ppos1;

    len6sw=0;
    for (plh=Pplh1,sw1strec=1;;sw1strec=0)
    {
        datatype=datatype0;
//  	rc=tc_getplhdata(sw1strec,&datatype,&plh,Pplh2,Ppos1,Ppos2,lvt,Pparm);//~v57JR~
    	rc=tc_getplhdata(GDO_DWUP,sw1strec,&datatype,&plh,Pplh2,Ppos1,Ppos2,lvt,Pparm);//~v57JI~
        if (rc==-1)	//eof
        	break;
        recno++;
		if (rc>4)
        	break;      //alloc  failed
        if (rc==1)
        {
            len6sw=CALC_TIME6;
            rc=0;
        }
        else
        if (rc==2)
        {
			if (browsesw				//ignore =
            ||  !totcnt)				//on 1st line
            {
            	tc_setplherr(plh);
	            rc=4;
			}
            else
            if (plh==Pplh2 && !subtot)	//last total
            {
            	plhgsum=plh;
            	break;
            }
		}
        if (rc==4)		//data err
        {
		    skipno++;
            continue;
        }
//ctl break chk
        if (rc==2)		//summ line
        {
            psumm=(void*)summline;                                 //~vao0R~
            tc_editsumm(len6sw|datatype,width,lvtt,summin,summax,subtot,0,0,0,summline,Pparm);
//          if ((rc=tc_setlinedata(Ppcw,plh,1,CALC_SUMMLINE,Ppos1, //~v58vR~
            if ((rc=tc_setlinedata(Ppcw,Pparm,plh,1,CALC_SUMMLINE,Ppos1,//~v58vI~
//                      Ppos1+(int)strlen(summline),(long*)(void*)summline,&dataovf))>1)//~vafkR~
//                      Ppos1+(int)strlen(summline),(SLPTR*)(void*)summline,&dataovf))>1)//~vafkI~//~vao0R~
                        Ppos1+(int)strlen(summline),psumm,&dataovf))>1)//~vao0I~
            	break;      //UALLOC_FAILED
        	if (Pparm[PARM_OUTFNM])                                //~v58zI~
            {                                                      //~v62sI~
            	rc=                                                //~v62sI~
#ifdef UTF8UCS2                                                    //~va20R~
    			tc_ft1outsumline(Ppcw,Pparm,0,0,0,""/*key*/,""/*keydbcs*/,summline);//~va20R~
#else                                                              //~va20R~
    			tc_ft1outsumline(Ppcw,Pparm,0,0,0,"",summline);    //~v58zI~
#endif                                                             //~va20R~
                if (rc)                                            //~v62sI~
                	return rc;                                     //~v62sI~
            }                                                      //~v62sI~
            subtot=0;
            continue;
		}
		if (tc_ft1sumdatatype(totcnt,plh,&datatype0,datatype,&skipno))
            continue;

		if (tc_ft1sumtotal(lvt,datatype,totcnt,totsum,totmin,totmax,
							subtot,lvtt,summin,summax))
			skipno+=tc_setplherr(plh);
        else
        {
        	subtot++;
        	totcnt++;
        }
	}//all plh
	if (rc==UALLOC_FAILED)
    	return rc;

    if (!totcnt)
		return tcerrnorec(recno,skipno,0);

    tc_editsumm(len6sw|datatype,width,totsum,totmin,totmax,totcnt,skipno,dataovf,0,summline,Pparm);
    if (plhgsum)    //last is double line of =(not EOF line but .a .b line)
    {
        psumm=(void*)summline;                                     //~vao0I~
//      if ((rc=tc_setlinedata(Ppcw,plh,1,CALC_SUMMLINE,Ppos1,     //~v58vR~
        if ((rc=tc_setlinedata(Ppcw,Pparm,plh,1,CALC_SUMMLINE,Ppos1,//~v58vI~
//                    Ppos1+(int)strlen(summline),(long*)(void*)summline,&dataovf))>1)//~vafkR~
//                  Ppos1+(int)strlen(summline),(SLPTR*)(void*)summline,&dataovf))>1)//~vafkR~//~vao0R~
                    Ppos1+(int)strlen(summline),psumm,&dataovf))>1)//~vao0I~
         	return rc;      //UALLOC_FAILED
        if (Pparm[PARM_OUTFNM])    	                               //~v58zI~
        {                                                          //~v62sI~
        	rc=                                                    //~v62sI~
#ifdef UTF8UCS2                                                    //~va20R~
    		tc_ft1outsumline(Ppcw,Pparm,FT1_SUMTOT,0,0,""/*key*/,""/*keydbcs*/,summline);//~va20R~
#else                                                              //~va20R~
    		tc_ft1outsumline(Ppcw,Pparm,FT1_SUMTOT,0,0,"",summline);//~v58zR~
#endif                                                             //~va20R~
            if (rc)                                                //~v62sI~
                return rc;                                         //~v62sI~
        }                                                          //~v62sI~
    }
    else
    {
		if (tc_getisrtpos(Pplh1,Pplh2,Pparm,&plhisrtbefore,&plhisrtafter))//option used//~v170R~
        {
//          if ((rc=tc_ft1isrtsum(Ppcw,0,plh,plhisrtbefore,&plhisrtafter,0,Ppos1,Ppos1,0,0,"",summline,&dataovf))>1)//~v589R~
//          if ((rc=tc_ft1isrtsum(Ppcw,0,plh,plhisrtbefore,&plhisrtafter,0,Ppos1,Ppos1,0,0,"",0,summline,&dataovf))>1)//~v58zR~
#ifdef UTF8UCS2                                                    //~va20R~
            if ((rc=tc_ft1isrtsum(Ppcw,Pparm,0,plh,plhisrtbefore,&plhisrtafter,0/*plhisrtted*/,Ppos1/*inslen*/,Ppos1/*Ppos1*/,0/*cpos1*/,0/*cpos2*/,""/*key*/,""/*keydbcs*/,0,summline,&dataovf))>1)//~va20R~
#else                                                              //~va20R~
            if ((rc=tc_ft1isrtsum(Ppcw,Pparm,0,plh,plhisrtbefore,&plhisrtafter,0,Ppos1,Ppos1,0,0,"",0,summline,&dataovf))>1)//~v58zI~
#endif                                                             //~va20R~
                return rc;      //UALLOC_FAILED
        }
        else                                                       //~v58zI~
        {                                                          //~v58zI~
        	if (Pparm[PARM_OUTFNM])                                //~v58zI~
            {                                                      //~v62sI~
#ifdef UTF8UCS2                                                    //~va20R~
            	rc=tc_ft1outsumline(Ppcw,Pparm,FT1_SUMTOT,0,0,""/*key*/,""/*keydbcs*/,summline);//~va20R~
#else                                                              //~va20R~
            	rc=                                                //~v62sI~
    			tc_ft1outsumline(Ppcw,Pparm,FT1_SUMTOT,0,0,"",summline);//~v58zR~
#endif                                                             //~va20R~
                if (rc)                                            //~v62sI~
                	return rc;                                     //~v62sI~
            }                                                      //~v62sI~
        }                                                          //~v58zI~
	}
    uerrmsg("%s: %s",0,
        Ppcw->UCWparm,summline+1);
    return skipno||dataovf;
}//tc_ft1sumnobreak
//****************************************************************
// delete old summ line except block boundary line
//*rc   :0 continue process(may data err) or 2:last block boundary  or UALLOC_FAILED
//****************************************************************
int tc_ft1sumdelplh(PUCLIENTWE Ppcw,PULINEH *Ppplh,PULINEH Pplh1,PULINEH Pplh2,long *Pskipno)
{
	PULINEH plhp,plh;
    int rc;
//***********************
	plh=*Ppplh;
//    if (plh==Pplh1)                                              //~v170R~
//    {                                                            //~v170R~
//        tc_setplherr(plh);                                       //~v170R~
//        *Pskipno=*Pskipno+1;                                     //~v170R~
//        return 0;                                                //~v170R~
//    }                                                            //~v170R~
//    if (plh==Pplh2)                                              //~v170R~
//        return 2;                                                //~v170R~
	plhp=UGETQPREV(plh);	//prev of next line
    if ((rc=lcmddel(Ppcw,plh,plh,1,0,1))!=0)//1line del,no csr set to next line
    	return rc;                          //undo prepaired
	*Ppplh=plhp;
    return 0;
}//tc_ft1sumdelplh
//****************************************************************
// maint previous summ line to be replaced
// cdelsw:1 del current sumline unconditionaly because no isrt option//~v170I~
//*rc   :0:summ chked,so jump to read next, 1:reached to end of data, or  to be break
//****************************************************************
int tc_ft1sumchksumline(PUCLIENTWE Ppcw,PULINEH Pplh,int Pcdelsw,  //~v170R~
						PULINEH *Ppplhsum,PULINEH *Ppplhgsum,
						PULINEH Pplh1,PULINEH Pplh2,PULINEH Pplhisrt1st,long *Pskipno)//~v170R~
{
	PULINEH plhsum,plhgsum;
    int rc;
//***********************
    if (Pplh==Pplhisrt1st)     //reached to inseted line           //~v170I~
        return 1;				//loop break                       //~v170I~
	if (Pcdelsw)	//insert place is specified                    //~v170R~
    	plhgsum=plhsum=Pplh;	//to be deleted
    else
    {
		plhsum=*Ppplhsum;
		plhgsum=*Ppplhgsum;
    }
    if (plhgsum)	//2 sum line saved
    {
        rc=tc_ft1sumdelplh(Ppcw,&plhsum,Pplh1,Pplh2,Pskipno);
        if (rc>4)
            return rc;
        plhsum=plhgsum; 	//shift
        plhgsum=Pplh;       //shift
    }
    else
    	if (plhsum)
	        plhgsum=Pplh;       //2nd shift
        else
            plhsum=Pplh;        //1st
    if (Pplh==Pplh2)     //last line
        rc=1;			//loop break
    else
    	rc=0;

	if (Pcdelsw)	//insert place is specified                    //~v170R~
		plhsum=plhgsum=0;

	*Ppplhsum=plhsum;
	*Ppplhgsum=plhgsum;
    return rc;
}//tc_ft1sumchksumline
//****************************************************************
// determin sumline insert pos by parm
// rc 0:no option ,1 option used(after or before is set)           //~v170I~
//****************************************************************
//int tc_getisrtpos(PULINEH Pplh1,PULINEH Pplh2,int *Pparm,PULINEH *Pplhbef,PULINEH *Pplhaft)//~v170R~//~va70R~
int tc_getisrtpos(PULINEH Pplh1,PULINEH Pplh2,XECALCPARM *Pparm,PULINEH *Pplhbef,PULINEH *Pplhaft)//~va70I~
{
	PUFILEH pfh;
	PULINEH plhisrtafter=0,plhisrtbefore=0,plhtop,plhend;          //~v170R~
    int rc=1;                                                      //~v170I~
//******************
	pfh=UGETPFH(Pplh1);
	plhtop=UGETQTOP(&pfh->UFHlineque);                             //~v170I~
	plhend=UGETQEND(&pfh->UFHlineque);                             //~v170I~
    switch(Pparm[PARM_OPTION] & PARM_SUMISRT_MASK)
    {
    case PARM_SUMISRT_TOP:
		plhisrtafter=plhtop;                                       //~v170R~
        break;
    case PARM_SUMISRT_LAST:
		plhisrtbefore=plhend;                                      //~v170R~
        break;
    case PARM_SUMISRT_AFTER:
    	if (Pplh2==plhend)                                         //~v170I~
			plhisrtbefore=Pplh2;                                   //~v170I~
        else                                                       //~v170I~
			plhisrtbefore=UGETQNEXT(Pplh2);//to del all old        //~v170R~
        break;
    case PARM_SUMISRT_BEFORE:
    	if (Pplh1==plhtop)                                         //~v170R~
			plhisrtafter=Pplh1;                                    //~v170I~
        else                                                       //~v170I~
			plhisrtafter=UGETQPREV(Pplh1);                         //~v170R~
        break;
    default:
	    rc=0;                                                      //~v170R~
	}
    *Pplhbef=plhisrtbefore;                                        //~v170I~
    *Pplhaft=plhisrtafter;                                         //~v170I~
	return 	rc;                                                    //~v170R~
}//tc_getisrtpos
//****************************************************************
// table summary by record key
//*rc   :0   or 1:data err or 4:env err or 8:seq down, or UALLOC_FAILED
//****************************************************************
int tc_ft1sumkey(PUCLIENTWE Ppcw,
//				PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,int *Pparm)//~va70R~
				PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2,XECALCPARM *Pparm)//~va70I~
{
	PULINEH plh,plho=0,plhsum,plhgsum,plhisrtafter,plhisrtbefore,plhisrt1st=0;//~v52kR~
	PULINEH plhisrted;                                             //~v170I~
	int     sw1strec,rc=0,datatype,datatype0,len6sw,width;
	int     cpos1=0,cpos2=0,cwidth,cinslen,len,pos;                    //~v170R~//~va79R~
	int     ctlbreak,cdatatype,cdatatype0,breaksw,sumrepsw;
//  long    lvt[3],lvtt[3],summin[3],summax[3];                    //~v57JR~
//  long    lvt[4],lvtt[4],summin[4],summax[4];                    //~v57JI~//~vafkR~
    SLPTR   lvt[4],lvtt[4],summin[4],summax[4];                    //~vafkR~
//  long    totsum[3],totmin[3],totmax[3],cbreakcnt;               //~v57JR~
//  long    totsum[4],totmin[4],totmax[4],cbreakcnt=0;               //~v57JI~//~va79R~//~vafkR~
    SLPTR   totsum[4],totmin[4],totmax[4];                         //~vafkI~
    long                                  cbreakcnt=0;             //~vafkI~
    long    recno=0,skipno=0,dataovf=0,keyerrno=0,subtot=0,totcnt=0;
//  long    cdiff,numkeywk[3],newnumkey,oldnumkey;                 //~v53CR~
//  long    cdiff[3],numkeywk[3],newnumkey,oldnumkey;              //~v57JR~
//  long    cdiff[4],numkeywk[4],newnumkey=0,oldnumkey;              //~v57JI~//~va79R~//~vafkR~
    long                         newnumkey=0,oldnumkey;            //~vafkI~
    SLPTR   cdiff[4],numkeywk[4];                                  //~vafkI~
    char    summline[128],*pc;
    char    newkey[MAXKEYLEN+1],oldkey[MAXKEYLEN+1];
    int     newkeylen,oldkeylen;                                   //~v589I~
    char *outfnm;                                                  //~v58zI~
#ifdef UTF8UCS2                                                    //~va20R~
	PUFILEH pfh;                                                   //~va20R~
    int swutf8file;                                                //~va20R~
    char    newkeydbcs[MAXKEYLEN],oldkeydbcs[MAXKEYLEN];           //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile,optgd,swebcu8;                                   //~va50R~
	int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	PULINEH plhprev;                                               //~vauMR~
//*********************************
//  outfnm=(char*)(ULONG)Pparm[PARM_OUTFNM];                       //~v58zR~//~vafkR~
    outfnm=(char*)(ULPTR)Pparm[PARM_OUTFNM];                       //~vafkI~
  if (outfnm)                                                      //~v58zI~
    plhisrtbefore=plhisrtafter=0;                                  //~v58zI~
  else                                                             //~v58zI~
	tc_getisrtpos(Pplh1,Pplh2,Pparm,&plhisrtbefore,&plhisrtafter); //~v170R~

//  datatype0=Pparm[PARM_DATATYPE1];                               //~vaz8R~
	datatype0=(int)Pparm[PARM_DATATYPE1];                          //~vaz8I~
    width=Ppos2-Ppos1;
//  ctlbreak=Pparm[PARM_BREAKTYPE];                                //~vaz8R~
    ctlbreak=(int)Pparm[PARM_BREAKTYPE];                           //~vaz8I~
//  cdatatype0=Pparm[PARM_KEYDATATYPE];   //datatype of ctl break key//~vaz8R~
    cdatatype0=(int)Pparm[PARM_KEYDATATYPE];   //datatype of ctl break key//~vaz8I~
    if (ctlbreak==PARM_BREAK_COUNT)
    {
	    cinslen=Ppos1;      //sumline len added later
	    cbreakcnt=(long)*(Pparm+PARM_COUNT);
        *newkey=0;	//no print key
	    cwidth=0;	//key copy len                                 //~v54DI~
	}
    else
    {
//      cpos1=*(Pparm+PARM_KEYCOL1);                               //~vaz8R~
	    cpos1=(int)(*(Pparm+PARM_KEYCOL1));                        //~vaz8I~
//  	cpos2=*(Pparm+PARM_KEYCOL2);                               //~vaz8R~
    	cpos2=(int)(*(Pparm+PARM_KEYCOL2));                        //~vaz8I~
	    cwidth=cpos2-cpos1;
    	cinslen=max(Ppos1,cpos2);//min len,sumline len added leater
//  	cdiff=(long)*(Pparm+PARM_KEYBREAKVALUE);                   //~v53CR~
    	cdiff[0]=(long)*(Pparm+PARM_KEYBREAKVALUE);                //~v53CI~
    	cdiff[1]=0;		//no underpoint data                       //~v53CI~
	}
	memset(newkey,0,sizeof(newkey));//once full clear              //~v54DI~
	memset(oldkey,0,sizeof(oldkey));//once full clear              //~v54DI~
#ifdef UTF8UCS2                                                    //~va20R~
	pfh=UGETPFH(Pplh1);                                            //~va20R~
	swutf8file=FILEUTF8MODE(pfh);                                  //~va20R~
	memset(newkeydbcs,0,sizeof(newkeydbcs));//once full clear      //~va20R~
	memset(oldkeydbcs,0,sizeof(oldkeydbcs));//once full clear      //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
    handle=pfh->UFHhandle;                                         //~va79I~
    optgd=swebcfile*GDO_EBC;//for umeric data                      //~va50I~
    swebcu8=swebcfile|swutf8file;                                  //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    newkeylen=0;oldkeylen=0;                                       //~v589I~
    len6sw=0;
    plhsum=plhgsum=0;
    oldnumkey=0;		//for compiler warning
    for (plh=Pplh1,sw1strec=1,plhsum=0;;sw1strec=0,plho=plh)
    {
        datatype=datatype0;
//  	rc=tc_getplhdata(sw1strec,&datatype,&plh,Pplh2,Ppos1,Ppos2,lvt,Pparm);//~v57JR~
    	rc=tc_getplhdata(GDO_DWUP,sw1strec,&datatype,&plh,Pplh2,Ppos1,Ppos2,lvt,Pparm);//~v57JI~
        if (rc==-1)	//eof
        	break;
        recno++;
		if (rc>4)
        	break;      //alloc  failed
        if (rc==4)
        {
		    skipno++;
            continue;
        }
        if (rc==1)
        {
            len6sw=CALC_TIME6;
            rc=0;
        }
        else
        if (rc==2)
        {
          if (!outfnm)                                             //~v58zI~
          {                                                        //~v58zI~
          	plhprev=UGETQPREV(plh);                                //~vauMR~
			if (rc=tc_ft1sumchksumline(Ppcw,plh,plhisrtafter||plhisrtbefore,//~v170R~
                                       &plhsum,&plhgsum,Pplh1,Pplh2,plhisrt1st,&skipno),rc)//~v170R~
            		break;
            if (plhisrtafter||plhisrtbefore)    //plh was deleted  //~vauMR~
                 plh=plhprev;    //getplhdata do getnext           //~vauMR~
          }//not out to file                                       //~v58zI~
        	continue;
		}
//ctl break chk
		breaksw=0;
	    if (ctlbreak==PARM_BREAK_COUNT)
    	{
	        if (subtot>=cbreakcnt)
                breaksw=1;
    	}//count
        else
        {
//          memset(newkey,0,sizeof(newkey));                       //~v54DR~
            memset(newkey,0,(UINT)cwidth);	//clear compare length only//~v54DI~
            pc=plh->ULHdata;
            len=plh->ULHlen-cpos1;
//          if (len<=0)                                            //~v58aR~
            if (len<=0 && ctlbreak!=PARM_BREAK_KEY_EQ)             //~v58aI~
                rc=4;
            else
            {
            	if (len<=0)                                        //~v58aI~
                	len=0;                                         //~v58aI~
                if (len>cwidth)
                    len=cwidth;
                memcpy(newkey,pc+cpos1,(UINT)len);
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    			if (swebcu8)                                       //~va50I~
	#else                                                          //~va50I~
    			if (swutf8file)                                    //~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
                	memcpy(newkeydbcs,plh->ULHdbcs+cpos1,(UINT)len);//~va20R~
                UTRACED("newkey",newkey,len);                      //~va20R~
                UTRACED("newkeydbcs",newkeydbcs,len);              //~va20R~
#endif                                                             //~va20R~
	            newkeylen=len;                                     //~v589I~
//              if (ctlbreak==PARM_BREAK_KEYGRP)                   //~v53DR~
                if (ctlbreak==PARM_BREAK_KEYGRP                    //~v53DI~
                ||  ctlbreak==PARM_BREAK_KEYGRP_EQ                 //~v53DI~
                ||  ctlbreak==PARM_BREAK_KEYGRP_LT)                //~v53DI~
                {
                    cdatatype=cdatatype0;
                    if (tc_ft1sumdatatype(totcnt,plh,&cdatatype0,cdatatype,&skipno))
                        continue;

//                  rc=tc_getlinedata(&cdatatype,newkey,(int)strlen(newkey),numkeywk);//~v54DR~
//                  rc=tc_getlinedata(&cdatatype,newkey,len,numkeywk);//~v57JR~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//                  rc=tc_getlinedata(optgd,&cdatatype,newkey,newkeydbcs,len,numkeywk);//~va50I~//~va79R~
                    rc=tc_getlinedata(optgd,handle,&cdatatype,newkey,newkeydbcs,len,numkeywk);//~va79R~
	#else                                                          //~va50I~
                    rc=tc_getlinedata(0,&cdatatype,newkey,newkeydbcs,len,numkeywk);//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
                    rc=tc_getlinedata(0,&cdatatype,newkey,len,numkeywk);//~v57JI~
#endif                                                             //~va20R~
                    if (!rc||rc==1)	//ok or 6byte hhmmss
                    {
                        if (cdatatype=='T')
                            ucalc_time(CALC_TIME_CONV2SEC,'=',numkeywk,numkeywk);//~v17iR~
//                      rc=tc_calc(0,'D','/',numkeywk,&cdiff);     //~v53CR~
                        rc=tc_calc(0,'D','/',numkeywk,cdiff);      //~v53CI~
                        if (!rc)
                        {
//                      	newnumkey=numkeywk[0];                 //~vaz8R~
                        	newnumkey=(long)numkeywk[0];	//rc=0/1 means key is numeric value//~vaz8I~
	                        if (totcnt)
    	                    {
                                if (newnumkey>oldnumkey)
                                {                                  //~v53DI~
	    			              if (ctlbreak==PARM_BREAK_KEYGRP_LT)//discending key//~v53DI~
                                    rc=4;	//key seq err          //~v53DI~
                                  else                             //~v53DI~
                                    breaksw=1;
                                }                                  //~v53DI~
                                else
                                if (newnumkey<oldnumkey)
                                {                                  //~v53DI~
                                  if (ctlbreak==PARM_BREAK_KEYGRP)//ascending key//~v53DI~
                                	rc=4;	//key seq err
                                  else                             //~v53DI~
                                    breaksw=1;                     //~v53DI~
                                }                                  //~v53DI~
                        	}
                        }

                	}//linedata gotten
                }//keygrp
                else
                    if (totcnt)
                    {                                              //~v53DI~
                UTRACED("comp oldkey",oldkey,cwidth);              //~va20R~
                UTRACED("comp oldkeydbcs",oldkeydbcs,cwidth);      //~va20R~
//                      if ((rc=memcmp(oldkey,newkey,MAXKEYLEN))<0)//~v54DR~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//                      if ((rc=XESUB_memcmp_ebcdd(swebcfile,swutf8file,XESUBDDSCO_HIGHLOW,oldkey,oldkeydbcs,newkey,newkeydbcs,cwidth))<0)//~va50I~//~va79R~
                        if ((rc=XESUB_memcmp_ebcdd(swebcfile,swutf8file,handle,XESUBDDSCO_HIGHLOW,oldkey,oldkeydbcs,newkey,newkeydbcs,cwidth))<0)//~va79I~
    #else                                                          //~va50I~
                        if ((rc=XESUB_DDMEMCMP(swutf8file,XESUBDDSCO_HIGHLOW,oldkey,oldkeydbcs,newkey,newkeydbcs,cwidth))<0)//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
                        if ((rc=memcmp(oldkey,newkey,(UINT)cwidth))<0)//~v54DI~
#endif                                                             //~va20R~
                        {
	    			      if (ctlbreak==PARM_BREAK_KEY_LT)//discending key//~v53DI~
                            rc=4;	//key seq err                  //~v53DI~
                          else                                     //~v53DI~
                          {                                        //~v53DI~
                            rc=0;
                            breaksw=1;
                          }                                        //~v53DI~
                        }
                        else                                       //~v53DI~
                        if (rc>0)                                  //~v53DI~
                        {                                          //~v53DI~
                          if (ctlbreak==PARM_BREAK_KEY)//ascending key//~v53DI~
                            rc=4;	//key seq err                  //~v53DI~
                          else                                     //~v53DI~
                          {                                        //~v53DI~
                            rc=0;                                  //~v53DI~
                            breaksw=1;                             //~v53DI~
                          }                                        //~v53DI~
                        }                                          //~v53DI~
                		UTRACEP("comp rc=%d,breaksw=%d\n",rc,breaksw);//~va20R~
                    }                                              //~v53DI~
            }//by key data len
            if (rc)   //seq err
            {
                keyerrno+=tc_setplherr(plh);
                continue;
            }
        }//by count or key
        if (breaksw)       //ctl break
        {
            tc_editsumm(len6sw|datatype,width,lvtt,summin,summax,subtot,0,0,0,summline,Pparm);
            sumrepsw=(plhsum||plhgsum)*FT1_SUMREP;
//          if ((rc=tc_ft1isrtsum(Ppcw,sumrepsw,plho,plhisrtbefore,&plhisrtafter,&plhisrted,//~v58zR~
            if ((rc=tc_ft1isrtsum(Ppcw,Pparm,sumrepsw,plho,plhisrtbefore,&plhisrtafter,&plhisrted,//~v58zI~
//                                cinslen,Ppos1,cpos1,cpos2,oldkey,summline,&dataovf))>1)//~v589R~
#ifdef UTF8UCS2                                                    //~va20R~
                                  cinslen,Ppos1,cpos1,cpos2,oldkey,oldkeydbcs,oldkeylen,summline,&dataovf))>1)//~va20R~
#else                                                              //~va20R~
                                  cinslen,Ppos1,cpos1,cpos2,oldkey,oldkeylen,summline,&dataovf))>1)//~v589I~
#endif                                                             //~va20R~
                break;      //UALLOC_FAILED
			if (!plhisrt1st)                                       //~v170I~
            	plhisrt1st=plhisrted;                              //~v170I~
            if (plhgsum)
            	plhgsum=0;	//used 2nd,drop 1st
            else
            	plhsum=0;
        }
        if (plhsum)
        {
            if (rc=tc_ft1sumdelplh(Ppcw,&plhsum,Pplh1,Pplh2,&skipno),rc)
                break;      //UALLOC_FAILED
	        plhsum=0;
        }
        if (plhgsum)
        {
            if (rc=tc_ft1sumdelplh(Ppcw,&plhgsum,Pplh1,Pplh2,&skipno),rc)
                break;      //UALLOC_FAILED
	        plhgsum=0;
        }
        if (!totcnt || breaksw)
        {
//          memcpy(oldkey,newkey,sizeof(oldkey));                  //~v54DR~
            memcpy(oldkey,newkey,(UINT)cwidth);                    //~v54DI~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    		if (swebcu8)                                           //~va50I~
	#else                                                          //~va50I~
    		if (swutf8file)                                        //~va20R~
    #endif                                                         //~va50I~
            	memcpy(oldkeydbcs,newkeydbcs,(UINT)cwidth);        //~va20R~
            UTRACED("set oldkey",oldkey,cwidth);                   //~va20R~
            UTRACED("set oldkeydbcs",oldkeydbcs,cwidth);           //~va20R~
#endif                                                             //~va20R~
	        oldkeylen=newkeylen;                                   //~v589I~
            oldnumkey=newnumkey;
            subtot=0;
        }
		if (tc_ft1sumdatatype(totcnt,plh,&datatype0,datatype,&skipno))
            continue;

		if (tc_ft1sumtotal(lvt,datatype,totcnt,totsum,totmin,totmax,
							subtot,lvtt,summin,summax))
			skipno+=tc_setplherr(plh);
        else
        {
	        subtot++;
    	    totcnt++;
        }
	}//all plh
	if (rc==UALLOC_FAILED)
    	return rc;

    if (!totcnt)
		return tcerrnorec(recno,skipno,keyerrno);

    if (subtot)  //remaining line and insert mode
    {
        tc_editsumm(len6sw|datatype,width,lvtt,summin,summax,subtot,0,0,0,summline,Pparm);
        if (plhsum)
        {
        	plho=plhsum;
			sumrepsw=FT1_SUMREP;
        }
        else
			sumrepsw=0;
//      if ((rc=tc_ft1isrtsum(Ppcw,sumrepsw,plho,plhisrtbefore,&plhisrtafter,0,//~v58zR~
        if ((rc=tc_ft1isrtsum(Ppcw,Pparm,sumrepsw,plho,plhisrtbefore,&plhisrtafter,0,//~v58zI~
//                            cinslen,Ppos1,cpos1,cpos2,oldkey,summline,&dataovf))>1)//~v589R~
#ifdef UTF8UCS2                                                    //~va20R~
                              cinslen,Ppos1,cpos1,cpos2,oldkey,oldkeydbcs,oldkeylen,summline,&dataovf))>1)//~va20R~
#else                                                              //~va20R~
                              cinslen,Ppos1,cpos1,cpos2,oldkey,oldkeylen,summline,&dataovf))>1)//~v589I~
#endif                                                             //~va20R~
            return rc;      //UALLOC_FAILED
        if (!sumrepsw)
        	plho=UGETQNEXT(plho);   //inserted
    }//last group
    tc_editsumm(len6sw|datatype,width,totsum,totmin,totmax,totcnt,skipno,dataovf,keyerrno,summline+1,Pparm);//~v170R~
    if (plhgsum)
    {
        plho=plhgsum;
        sumrepsw=FT1_SUMREP|FT1_SUMTOT;
    }
    else
        sumrepsw=FT1_SUMTOT;
	if (Ppos1)                                                     //~v170I~
    {                                                              //~v170I~
    	pc=summline;     //print '*'                               //~v170R~
        *pc='*';		//id of total                              //~v170I~
        pos=Ppos1-1;                                               //~v170I~
	}                                                              //~v170I~
    else                                                           //~v170I~
    {                                                              //~v170I~
    	pc=summline+1;   //bypass '*'                              //~v170R~
        pos=Ppos1;                                                 //~v170I~
	}                                                              //~v170I~
	if (ctlbreak!=PARM_BREAK_COUNT)
    {                                                              //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  	memset(oldkey,UCVEBC_CONSTC(swebcfile,'*'),(UINT)cwidth);  //~va50I~//~va79R~
    	memset(oldkey,UCVEBC_CONSTC(swebcfile,handle,'*'),(UINT)cwidth);//~va79I~
#else                                                              //~va50I~
    	memset(oldkey,'*',(UINT)cwidth);
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	if (swebcu8)                                               //~va50I~
	#else                                                          //~va50I~
    	if (swutf8file)                                            //~va20R~
    #endif                                                         //~va50I~
    		memset(oldkeydbcs,0,(UINT)cwidth);                     //~va20R~
#endif                                                             //~va20R~
    }                                                              //~va20R~
//  if ((rc=tc_ft1isrtsum(Ppcw,sumrepsw,plho,plhisrtbefore,&plhisrtafter,0,//~v58zR~
    if ((rc=tc_ft1isrtsum(Ppcw,Pparm,sumrepsw,plho,plhisrtbefore,&plhisrtafter,0,//~v58zI~
//                        cinslen,pos,cpos1,cpos2,oldkey,pc,&dataovf))>1)//~v589R~
#ifdef UTF8UCS2                                                    //~va20R~
                          cinslen,pos,cpos1,cpos2,oldkey,oldkeydbcs,cwidth,pc,&dataovf))>1)//~va20R~
#else                                                              //~va20R~
                          cinslen,pos,cpos1,cpos2,oldkey,cwidth,pc,&dataovf))>1)//~v589I~
#endif                                                             //~va20R~
        return rc;      //UALLOC_FAILED
    uerrmsg("%s: %s",0,
        Ppcw->UCWparm,summline+1);
    return skipno||dataovf||keyerrno;
}//tc_ft1sumkey
//****************************************************************
// insert summary line
//*rc   :0  1:ovfcut or UALLOC_FAILED
//****************************************************************
//int tc_ft1isrtsum(PUCLIENTWE Ppcw,int Psumrepsw,PULINEH Pplhprev,PULINEH Pplhisrtbefore,//~v58zR~
//int tc_ft1isrtsum(PUCLIENTWE Ppcw,int *Pparm,int Psumrepsw,PULINEH Pplhprev,PULINEH Pplhisrtbefore,//~v58zR~//~va70R~
int tc_ft1isrtsum(PUCLIENTWE Ppcw,XECALCPARM *Pparm,int Psumrepsw,PULINEH Pplhprev,PULINEH Pplhisrtbefore,//~va70I~
					PULINEH *Ppplhisrtafter,PULINEH *Ppplhisrted,int Pinslen,int Ppos1,//~v170R~
//  				int Pcpos1,int Pcpos2,char *Pkey,char *Psumline,long *Pdataovfcnt)//~v589R~
#ifdef UTF8UCS2                                                    //~va20R~
    				int Pcpos1,int Pcpos2,char *Pkey,char *Pkeydbcs,int Pkeylen,char *Psumline,long *Pdataovfcnt)//~va20R~
#else                                                              //~va20R~
    				int Pcpos1,int Pcpos2,char *Pkey,int Pkeylen,char *Psumline,long *Pdataovfcnt)//~v589I~
#endif                                                             //~va20R~
{
	PULINEH plh,plhisrtafter;
    char    *pc,*pcd;
//  int   rc,keylen,pos,srclen,ovfcutsw=0,incmsw;                  //~va79R~
    int   rc,keylen=0,pos=0,srclen,ovfcutsw=0,incmsw;              //~va79I~
    char  keydata[MAXKEYLEN+1];
    char  keydbcs[MAXKEYLEN+1];
    char  sumdbcs[512];
#ifdef UTF8UCS2                                                    //~va20R~
	PUFILEH pfh;                                                   //~va20R~
	int swutf8file;                                                //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile,opt;                                             //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*******************************
	if (Pparm[PARM_OUTFNM])                                        //~v58zI~
#ifdef UTF8UCS2                                                    //~va20R~
    	return tc_ft1outsumline(Ppcw,Pparm,Psumrepsw,Pcpos1,Pcpos2,Pkey,Pkeydbcs,Psumline);//~va20R~
#else                                                              //~va20R~
    	return tc_ft1outsumline(Ppcw,Pparm,Psumrepsw,Pcpos1,Pcpos2,Pkey,Psumline);//~v58zR~
#endif                                                             //~va20R~
	srclen=(int)strlen(Psumline);
//select line to be updated or inserted after
	plhisrtafter=*Ppplhisrtafter;
    if (!plhisrtafter && !Pplhisrtbefore && (Psumrepsw & FT1_SUMREP))//~v170R~
    {
        plh=Pplhprev;                                              //~v170R~
        if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)   //prepare undo and update process
            return UALLOC_FAILED;
		incmsw=UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED);//include required
    }
    else
    {
        if (plhisrtafter)
            plh=plhisrtafter;
        else
        	if (Pplhisrtbefore)                                    //~v170I~
            	plh=UGETQPREV(Pplhisrtbefore);                     //~v170I~
            else                                                   //~v170I~
            	plh=Pplhprev;                                      //~v170R~
		incmsw=UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED);//include required
        if ((rc=lcmdisrt(Ppcw,plh,1,0))!=0)  //1line,req no indentation
            return rc;      //UALLOC_FAILED
        plh=UGETQNEXT(plh);      //inserted
        if (incmsw)
			UCBITON(plh->ULHflag2,ULHF2EXCLUDED);//for incm logic
        if (plhisrtafter)
            *Ppplhisrtafter=plh;    //next after
    }
#ifdef UTF8UCS2                                                    //~va20R~
	pfh=UGETPFH(plh);                                              //~va20R~
	swutf8file=FILEUTF8MODE(pfh);                                  //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(pfh);                                      //~va50R~
    handle=pfh->UFHhandle;                                         //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//set line data
    if (Psumrepsw & FT1_SUMTOT)
        *keydata='*';   //use as work
    else
        *keydata=CALC_SUMMFLD;  //use as work
    *keydbcs=0; //use as work
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    opt=CHAROPBREP|CHARCAP2_UNDO|CHARCAP2_OVFCUT;                  //~va50I~
    if (swebcfile)                                                 //~va50I~
    {                                                              //~va50I~
//  	*keydata=EBC_A2B(*keydata);                                //~va50I~//~va79R~
    	*keydata=UCVEBCH_A2B(handle,*keydata);                     //~va79I~
    	opt|=CHARCAP2_SRCEB;	//already translated               //~va50I~
    }                                                              //~va50I~
    if ((rc=charcap2(Ppcw,opt,keydata,keydbcs,1,plh,0))>1) //block replace//~va50I~
#else                                                              //~va50I~
    if ((rc=charcap2(Ppcw,CHAROPBREP|CHARCAP2_UNDO|CHARCAP2_OVFCUT,keydata,keydbcs,1,plh,0))>1) //block replace
#endif                                                             //~va50I~
        return rc;      //top 1 byte
    if (rc==1)
        ovfcutsw=1;
    if (*Pkey)
    {
        keylen=Pcpos2-Pcpos1;
        memcpy(keydata+1,Pkey,(UINT)keylen);
        if (Pkeylen<keylen)                                        //~v589I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            UCVEBC_memset_space(swebcfile,keydata+1+Pkeylen,(UINT)(keylen-Pkeylen));//~va50I~
#else                                                              //~va50I~
            memset(keydata+1+Pkeylen,' ',(UINT)(keylen-Pkeylen));  //~v589I~
#endif                                                             //~va50I~
#ifdef UTF8UCS2                                                    //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	  if (swutf8file||swebcfile)                                   //~va50I~
#else                                                              //~va50I~
	  if (swutf8file)                                              //~va20R~
#endif                                                             //~va50I~
      {                                                            //~va20R~
        memcpy(keydbcs+1,Pkeydbcs,(UINT)keylen);                   //~va20R~
        if (Pkeylen<keylen)                                        //~va20R~
            memset(keydbcs+1+Pkeylen,0,(UINT)(keylen-Pkeylen));    //~va20R~
      }                                                            //~va20R~
      else                                                         //~va20R~
#endif                                                             //~va20R~
        setdbcstbl(keydata+1,keydbcs+1,keylen);
        if (Pcpos1)
        {
            pc=keydata;
            pcd=keydbcs;
            pos=Pcpos1-1;
            keylen++;
        }
        else
        {
//          pc=keydata+1;                                          //~v57QR~
//          pcd=keydbcs+1;                                         //~v57QR~
            pc=keydata;                                            //~v57QI~
            pcd=keydbcs;                                           //~v57QI~
            pos=Pcpos1;
            keylen++;                                              //~v57QI~
        }
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	    opt=CHAROPBREP|CHARCAP2_OVFCUT;                            //~va50I~
    	if (swebcfile)                                             //~va50I~
    		opt|=CHARCAP2_SRCEB;	//already translated           //~va50I~
        if ((rc=charcap2(Ppcw,opt,pc,pcd,keylen,plh,pos))>1) //block replace//~va50I~
#else                                                              //~va50I~
        if ((rc=charcap2(Ppcw,CHAROPBREP|CHARCAP2_OVFCUT,pc,pcd,keylen,plh,pos))>1) //block replace
#endif                                                             //~va50I~
            return rc;
        if (rc==1)
            ovfcutsw=1;
    }
    memset(sumdbcs,0,sizeof(sumdbcs));
//  if ((rc=charcap2(Ppcw,CHAROPBREP|CHARCAP2_OVFCUT,Psumline,sumdbcs,srclen,plh,Ppos1))>1) //block replace//~v57QR~
//  if (!*Pkey || ((Ppos1>=pos+keylen)||(Ppos1+srclen<pos)))	//no overwrap//~v58yR~
    if (!*Pkey || ((Ppos1>=pos+keylen)||(Ppos1+srclen<=pos)))	//no overwrap//~v58yI~
    	pos=Ppos1;                                                 //~v57QI~
    else                                                           //~v57QI~
    	pos=pos+keylen+1;                                          //~v57QI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	opt=CHAROPBREP|CHARCAP2_OVFCUT;                                //~va50I~
    if (swebcfile)                                                 //~va50I~
    	opt|=CHARCAP2_SRCLC;	//need l2b translation             //~va50I~
    if ((rc=charcap2(Ppcw,opt,Psumline,sumdbcs,srclen,plh,pos))>1) //block replace//~va50I~
#else                                                              //~va50I~
    if ((rc=charcap2(Ppcw,CHAROPBREP|CHARCAP2_OVFCUT,Psumline,sumdbcs,srclen,plh,pos))>1) //block replace//~v57QI~
#endif                                                             //~va50I~
        return rc;
    if (rc==1)
        ovfcutsw=1;
    if (ovfcutsw)
    {
		tc_setplherr(plh);
    	if (Pdataovfcnt)
        	*Pdataovfcnt=*Pdataovfcnt+1;
    }
    if (incmsw)		//to be included
		if (lcmdincm(Ppcw,plh)==UALLOC_FAILED)	//display excluded line
        	return UALLOC_FAILED;
	if (Ppplhisrted)                                               //~v170I~
    	*Ppplhisrted=plh;		//return inserted plh              //~v170R~
    return ovfcutsw;
}//tc_ft1isrtsum
//**************************************************************** //~v58zI~
// summary line output to file                                     //~v58zI~
//*rc   :0  1:ovfcut or UALLOC_FAILED                              //~v58zI~
//**************************************************************** //~v58zI~
#ifdef UTF8UCS2                                                    //~va20R~
//int tc_ft1outsumline(PUCLIENTWE Ppcw,int *Pparm,int Popt,int Pkeypos1,int Pkeypos2,char *Pkey,char *Pkeydbcs,char *Psumline)//~va20R~//~va70R~
int tc_ft1outsumline(PUCLIENTWE Ppcw,XECALCPARM *Pparm,int Popt,int Pkeypos1,int Pkeypos2,char *Pkey,char *Pkeydbcs,char *Psumline)//~va70I~
#else                                                              //~va20R~
int tc_ft1outsumline(PUCLIENTWE Ppcw,int *Pparm,int Popt,int Pkeypos1,int Pkeypos2,char *Pkey,char *Psumline)//~v58zR~
#endif                                                             //~va20R~
{                                                                  //~v58zI~
	FILE *fh;                                                      //~v58zI~
    char  *fpath,*oopt,*sumdata,sumopt;                            //~v62FR~
    int   keylen,sumlen,posopt,keyopt;                             //~v58zR~
    char  keydata[MAXKEYLEN+1];                                    //~v58zI~
//  char  fpath[_MAX_PATH];                                        //~v62FR~
#ifdef UTF8UCS2                                                    //~va20R~
	PUFILEH pfh;                                                   //~va20R~
	int swutf8file,u8len;                                          //~va20R~
    UCHAR *pu8;                                                    //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile,len;                                             //~va50R~
    int handle;                                                    //~va79I~
    char  sumwk[256];                                              //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*******************************                                  //~v58zI~
#ifdef UTF8UCS2                                                    //~va20R~
	pfh=UGETPFHFROMPCW(Ppcw);                                      //~va20R~
	swutf8file=FILEUTF8MODE(pfh);                                  //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
    handle=pfh->UFHhandle;                                         //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//open                                                             //~v58zI~
//  fh=(FILE*)(ULONG)Pparm[PARM_OUTFH];                            //~v58zR~//~vafkR~
    fh=(FILE*)(ULPTR)Pparm[PARM_OUTFH];                            //~vafkI~
//  outfnm=(char*)(ULONG)Pparm[PARM_OUTFNM];                       //~v62FR~
//  fpath=(char*)(ULONG)Pparm[PARM_OUTFPATH];                      //~v62FI~//~vafkR~
    fpath=(char*)(ULPTR)Pparm[PARM_OUTFPATH];                      //~vafkI~
    if (!fh)                                                       //~v58zI~
    {                                                              //~v58zI~
//  	if (outfnm=dcmdfullpath(Ppcw,fpath,outfnm),!outfnm)	       //~v62tR~
//  	if (fcmdoutfnmedit(Ppcw,outfnm,fpath))	//wildcard support //~v62FR~
//      	return 4;                                              //~v62FR~
    	posopt=(Pparm[PARM_OPTION] & PARM_SUMISRT_MASK);           //~v58zI~
    	if (posopt==PARM_SUMISRT_AFTER||posopt==PARM_SUMISRT_LAST) //~v58zR~
        	oopt="a";	//append mode                              //~v58zR~
        else                                                       //~v58zI~
        	oopt="w";	//write mode                               //~v58zR~
//      fh=fileopen(outfnm,oopt);                                  //~v62tR~
        fh=fileopen(fpath,oopt);                                   //~v62tI~
        if (!fh)                                                   //~v58zI~
        	return 4;                                              //~v58zI~
//  	Pparm[PARM_OUTFH]=(int)(ULONG)fh;	//to close             //~v58zR~//~vafkR~
    	Pparm[PARM_OUTFH]=(ULPTR)fh;	//to close                 //~vafkI~
    }                                                              //~v58zI~
//fprintf                                                          //~v58zI~
//  sumlen=Pparm[PARM_OPD1POS2]-Pparm[PARM_OPD1POS1];              //~vaz8R~
    sumlen=(int)(Pparm[PARM_OPD1POS2]-Pparm[PARM_OPD1POS1]);       //~vaz8I~
    sumdata=Psumline;                                              //~v58zI~
//*sumline is ascii only                                           //~va20R~
    sumdata+=strspn(sumdata," *=");                                //~v58zR~
//  keyopt=Pparm[PARM_BREAKTYPE];                                  //~vaz8R~
	keyopt=(int)Pparm[PARM_BREAKTYPE];                             //~vaz8I~
	if (keyopt==PARM_BREAK_COUNT)                                  //~v58zI~
    	keyopt=0;                                                  //~v58zI~
    if (keyopt && *Pkey)                                           //~v58zR~
    {                                                              //~v58zI~
        keylen=Pkeypos2-Pkeypos1;                                  //~v58zR~
        memcpy(keydata,Pkey,(UINT)keylen);                         //~v58zI~
        *(keydata+keylen)=0;                                       //~v58zI~
#ifdef UTF8UCS2                                                    //~va20R~
	  if (swutf8file                                               //~va20R~
	  &&  (xeutfcvdd2f(0,Pkey,Pkeydbcs,keylen,&pu8,&u8len,0/*outdbcs*/)!=UALLOC_FAILED)//~va20R~
      )                                                            //~va20R~
      {                                                            //~va20R~
        *(pu8+u8len)=0;                                            //~va20R~
        fprintf(fh," %-*.*s = %*s\n",u8len,u8len,pu8,sumlen,sumdata);//~va20R~
      }                                                            //~va20R~
      else                                                         //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	  if (swebcfile)                                               //~va50I~
      {                                                            //~va50I~
//      fprintf(fh,"%c%s%c%c%c",CHAR_EBC_SPACE,Pkey,CHAR_EBC_SPACE,EBC_A2B('='),CHAR_EBC_SPACE);//~va50R~//~va79R~
        fprintf(fh,"%c%s%c%c%c",CHAR_EBC_SPACE,Pkey,CHAR_EBC_SPACE,UCVEBCH_A2B(handle,'='),CHAR_EBC_SPACE);//~va79I~
      	sprintf(sumwk,"%*s",sumlen,sumdata);                       //~va50I~
//      len=strlen(sumwk);                                         //~va50I~//+vb2DR~
        len=(int)strlen(sumwk);                                    //+vb2DI~
//      xeebc_ascii2b(0,sumwk,len,&pu8);                           //~va50R~//~va79R~
        xeebc_ascii2b(0,handle,sumwk,len,&pu8);                    //~va79I~
        *(pu8+len)=0;                                              //~va50R~
//      fprintf(fh,"%s\n",pu8);                                    //~va50R~//~va79R~
        fprintf(fh,"%s%c",pu8,EBC_NL);                             //~va79I~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        fprintf(fh," %s = %*s\n",keydata,sumlen,sumdata);          //~v58zR~
    }                                                              //~v58zI~
    else                                                           //~v58zI~
    {                                                              //~v58zI~
    	if (Popt & FT1_SUMTOT)	//grand total line                 //~v58zI~
        	sumopt='*';                                            //~v58zI~
        else                                                       //~v58zI~
        	sumopt=CALC_SUMMFLD;                                   //~v58zI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	  if (swebcfile)                                               //~va50I~
      {                                                            //~va50I~
//      fprintf(fh,"%c%c",EBC_A2B(sumopt),CHAR_EBC_SPACE);         //~va50I~//~va79R~
        fprintf(fh,"%c%c",UCVEBCH_A2B(handle,sumopt),CHAR_EBC_SPACE);//~va79R~
      	sprintf(sumwk,"%*s",sumlen,sumdata);                       //~va50I~
//      len=strlen(sumwk);                                         //~va50I~//+vb2DR~
        len=(int)strlen(sumwk);                                    //+vb2DI~
//      xeebc_ascii2b(0,sumwk,len,&pu8);                           //~va50I~//~va79R~
        xeebc_ascii2b(0,handle,sumwk,len,&pu8);                    //~va79I~
        *(pu8+len)=0;                                              //~va50I~
//      fprintf(fh,"%s\n",pu8);                                    //~va50R~//~va79R~
        fprintf(fh,"%s%c",pu8,EBC_NL);                             //~va79I~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        fprintf(fh,"%c %*s\n",sumopt,sumlen,sumdata);              //~v58zR~
    }                                                              //~v58zI~
    return 0;                                                      //~v58zI~
}//tc_ft1outsumline                                                //~v58zI~
//**************************************************************** //~va79I~
// update profile for the file of -O option                        //~va79I~
//**************************************************************** //~va79I~
int tc_updateprofile(int Popt,XECALCPARM *Pparm,PUFILEH Ppfh)      //~va79I~
{                                                                  //~va79I~
    char  *fpath;                                                  //~va79I~
	int intval,handle;                                             //~va79R~
//*******************************                                  //~va79I~
//  fpath=(char*)(ULONG)Pparm[PARM_OUTFPATH];                      //~va79I~//~vafkR~
    fpath=(char*)(ULPTR)Pparm[PARM_OUTFPATH];                      //~vafkI~
    handle=Ppfh->UFHhandle;                                        //~va79I~
	if (FILEUTF8MODE(Ppfh))                                        //~va79I~
    	intval=1;   //set CPU8                                     //~va79I~
    else                                                           //~va79I~
	if (PFH_ISEBC(Ppfh))                                           //~va79I~
    	intval=-2;  //set EBCDIC                                   //~va79I~
    else                                                           //~va79I~
    	intval=-1;  //set CPLC                                     //~va79I~
    fcmdprofupdaterecord(FPURO_CP,fpath,0/*strval*/,intval,handle);//~va79I~
    return 0;                                                      //~va79I~
}//tc_updateprofile                                                //~va79I~
//****************************************************************
// edit summary line
//*rc   :0  4:recno=0
//****************************************************************
//int tc_editsumm(int Pdatatype,int Pwidth,long *Psumm,long *Pmin,long *Pmax,//~vafkR~
int tc_editsumm(int Pdatatype,int Pwidth,SLPTR *Psumm,SLPTR *Pmin,SLPTR *Pmax,//~vafkI~
//				long Pokno,long Pskipno,long Pdataovf,long Pkeyerr,char *Pout,int *Pparm)//~va70R~
				long Pokno,long Pskipno,long Pdataovf,long Pkeyerr,char *Pout,XECALCPARM *Pparm)//~va70I~
{
	int datatype,rc,totlen,len6sw,timeconvopt;
    char    sumwork[MAX_DATA_WIDTH+1];
    char    sumworkmin[MAX_DATA_WIDTH+1];
    char    sumworkmax[MAX_DATA_WIDTH+1];
    char    sumworkave[MAX_DATA_WIDTH+1];
    char   *pc;
//  long    lventno[3];                                            //~v57JR~
//  long    lventno[4];                                            //~v57JI~//~vafkR~
    SLPTR   lventno[4];                                            //~vafkI~
    void   *pvoid;                                                 //~vao0I~
//*******************
	if (Pdatatype & CALC_TIME6)
    {
    	Pdatatype&=~CALC_TIME6;
        len6sw=CALC_TIME6;
    }
    else
        len6sw=0;

//  if (!Pokno)                                                    //~v52gR~
//  {                                                              //~v52gR~
//      strcpy(Pout,"No valid record;");                           //~v52gR~
//  	rc=4;                                                      //~v52gR~
//  }                                                              //~v52gR~
//  else                                                           //~v52gR~
//  {                                                              //~v52gR~
        datatype=Pdatatype;
        if (datatype=='Z')
            datatype='z';   //drop pre-space
//      tc_setlinedata(0,(PULINEH)(void*)sumwork,1,len6sw|datatype,0,MAX_DATA_WIDTH,Psumm,0);//~v58vR~
//      tc_setlinedata(0,(PULINEH)(void*)sumworkmin,1,len6sw|datatype,0,MAX_DATA_WIDTH,Pmin,0);//~v58vR~
//      tc_setlinedata(0,(PULINEH)(void*)sumworkmax,1,len6sw|datatype,0,MAX_DATA_WIDTH,Pmax,0);//~v58vR~
//*Ppcw=0:output to workarea                                       //~va50I~
//      tc_setlinedata(0,Pparm,(PULINEH)(void*)sumwork,1,len6sw|datatype,0,MAX_DATA_WIDTH,Psumm,0);//~v58vI~//~vao0R~
        pvoid=sumwork;                                             //~vao0M~
        tc_setlinedata(0,Pparm,(PULINEH)pvoid,1,len6sw|datatype,0,MAX_DATA_WIDTH,Psumm,0);//~vao0I~
//      tc_setlinedata(0,Pparm,(PULINEH)(void*)sumworkmin,1,len6sw|datatype,0,MAX_DATA_WIDTH,Pmin,0);//~v58vI~//~vao0R~
        pvoid=sumworkmin;                                          //~vao0R~
        tc_setlinedata(0,Pparm,(PULINEH)pvoid,1,len6sw|datatype,0,MAX_DATA_WIDTH,Pmin,0);//~vao0I~
//      tc_setlinedata(0,Pparm,(PULINEH)(void*)sumworkmax,1,len6sw|datatype,0,MAX_DATA_WIDTH,Pmax,0);//~v58vI~//~vao0R~
        pvoid=sumworkmax;                                          //~vao0R~
        tc_setlinedata(0,Pparm,(PULINEH)pvoid,1,len6sw|datatype,0,MAX_DATA_WIDTH,Pmax,0);//~vao0I~
        if (Pdatatype=='T')  //sum by sec
        	timeconvopt=CALC_TIME_2SEC;
		else
        	timeconvopt=0;
//      tc_calc(timeconvopt,datatype,'/',Psumm,&Pokno);            //~v57AR~
        lventno[0]=Pokno;                                          //~v57AR~
        lventno[1]=0;                                              //~v57AR~
        lventno[2]=0;                                              //~v57AR~
        tc_calc(timeconvopt,datatype,'/',Psumm,lventno);           //~v57AR~
//      tc_setlinedata(0,(PULINEH)(void*)sumworkave,1,len6sw|datatype,0,MAX_DATA_WIDTH,Psumm,0);//~v58vR~
//*Ppcw=0:output to workarea                                       //~va50I~
//      tc_setlinedata(0,Pparm,(PULINEH)(void*)sumworkave,1,len6sw|datatype,0,MAX_DATA_WIDTH,Psumm,0);//~v58vI~//~vao0R~
        pvoid=sumworkave;                                          //~vao0I~
        tc_setlinedata(0,Pparm,(PULINEH)pvoid,1,len6sw|datatype,0,MAX_DATA_WIDTH,Psumm,0);//~vao0I~
        pc=Pout;
      if (*(Pparm+PARM_BREAKTYPE))                                 //~v53MI~
      {                                                            //~v53MI~
        if ((totlen=(int)strlen(sumwork))<Pwidth-2)                //~v53MI~
        	totlen=Pwidth-2;                                       //~v53MI~
        pc+=sprintf(pc,"= %*s",totlen,sumwork);                    //~v53MI~
        if (Pparm[PARM_OPTION] & PARM_SUMISRT_AVE)                 //~v53MI~
        	pc+=sprintf(pc," / %ld = %s",Pokno,sumworkave);        //~v53MI~
        if (Pparm[PARM_OPTION] & PARM_SUMISRT_MM)                  //~v53MI~
        	pc+=sprintf(pc," ( %s << %s )",sumworkmin,sumworkmax); //~v53MI~
        if (Pskipno)                                               //~v53MI~
        	pc+=sprintf(pc," er = %ld",Pskipno);                   //~v53MI~
        if (Pdataovf)                                              //~v53MI~
        	pc+=sprintf(pc," ovf = %ld",Pdataovf);                 //~v53MI~
        if (Pkeyerr)                                               //~v53MI~
        	pc+=sprintf(pc," keyer = %ld",Pkeyerr);                //~v53MI~
      }                                                            //~v53MI~
      else                                                         //~v53MI~
      {                                                            //~v53MI~
        if ((totlen=(int)strlen(sumwork))<Pwidth-1)
        	totlen=Pwidth-1;
//      pc+=sprintf(pc,"=%*s;",totlen,sumwork);                    //~v58zR~
        pc+=sprintf(pc,"=%*s",totlen,sumwork);                     //~v58zI~
        if (Pparm[PARM_OPTION] & PARM_SUMISRT_AVE)
//      	pc+=sprintf(pc," /%ld=%s;",Pokno,sumworkave);          //~v58zR~
        	pc+=sprintf(pc," /%ld = %s",Pokno,sumworkave);         //~v58zI~
        if (Pparm[PARM_OPTION] & PARM_SUMISRT_MM)
//      	pc+=sprintf(pc," (%s<<%s);",sumworkmin,sumworkmax);    //~v58zR~
        	pc+=sprintf(pc," ( %s << %s )",sumworkmin,sumworkmax); //~v58zI~
        if (Pskipno)
//      	pc+=sprintf(pc," er=%ld;",Pskipno);                    //~v58zR~
        	pc+=sprintf(pc," er= %ld",Pskipno);                    //~v58zI~
        if (Pdataovf)
//      	pc+=sprintf(pc," ovf=%ld;",Pdataovf);                  //~v58zR~
        	pc+=sprintf(pc," ovf= %ld",Pdataovf);                  //~v58zI~
        if (Pkeyerr)
//      	pc+=sprintf(pc," keyer=%ld;",Pkeyerr);                 //~v58zR~
        	pc+=sprintf(pc," keyer= %ld",Pkeyerr);                 //~v58zI~
      }//break type ?                                              //~v53MI~
//      memset(Psumm,0,DDECSZ);                                    //~v57JR~
//      memset(Pmin,0,DDECSZ);                                     //~v57JR~
//      memset(Pmax,0,DDECSZ);                                     //~v57JR~
//      ucalc_dwupinit(Psumm);	//set 0                            //~v57XR~
//      ucalc_dwupinit(Pmin);	//set 0                            //~v57XR~
//      ucalc_dwupinit(Pmax);	//set 0                            //~v57XR~
        memset(Psumm,0,DDECSZ);                                    //~v57XI~
        memset(Pmin,0,DDECSZ);                                     //~v57XI~
        memset(Pmax,0,DDECSZ);                                     //~v57XI~
        rc=0;
//  }//record count!=0                                             //~v52gR~
	return rc;
}//tc_editsumm
