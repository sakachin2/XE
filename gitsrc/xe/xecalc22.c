//*CID://+vb30R~:                                   update#=  112; //+vb30R~
//*************************************************************
//*xecalc2.c
//* table calc(TC cmd)                                             //~va50R~
//*************************************************************
//vb30:160411 (LNX)Compiler warning                                //+vb30I~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va8b:101001 dbcs consideration for C&P                           //~va8bI~
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
#include <udbcschk.h>                                              //~va8bI~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile6.h"
#include "xecap.h"
#include "xecalc2.h"
#include "xecalc21.h"                                              //~va7aI~
#include "xecalc3.h"                                               //~v168I~
#include "xeerr.h"
#include "xechar2.h"
#include "xelcmd.h"
#include "xelcmd4.h"
#include "xelcmd5.h"                                               //~v497I~
#include "xesub.h"
#include "xesub2.h"                                                //~va50I~
//*******************************************************
static int    Sft2insmode=0;                                       //~v56zI~
#ifndef DOSDOS                                                     //~v50EI~
//****************************************************************
// 1 table calc
//*rc   :0   or 1:data err or 4:env err or UALLOC_FAILED
//****************************************************************
//int tc_ft2(PUCLIENTWE Ppcw,int Pfunctype,int *Pparm,PULINEH *Plabplh)//~va70R~
int tc_ft2(PUCLIENTWE Ppcw,int Pfunctype,XECALCPARM *Pparm,PULINEH *Plabplh)//~va70I~
{
	PUCLIENTWE pcw;
	PUFILEH pfht;
	PULINEH plh,plht1,plht2,plhtop,plhend;
	PULINEH plhs,plhs1,plhs2;
	int     post1,post2,pos31,pos32,rc=0,skip1,skip2,len6sw,pos1,pos2;
	int     poss1,poss2,width,sw1st,datatype,datatype1,datatype2,datatype3;
	int     convopt;
	int     unmatchctr=0;                                          //~v497I~
    long    recno=0,skipno=0,dataovf=0;
//  long    lvtt[3],lvts[3];                                       //~v57JR~
//  long    lvtt[4],lvts[4];                                       //~v57JI~//~vafkR~
    SLPTR   lvtt[4],lvts[4];                                       //~vafkI~
//  long    lvtcmp[4];	//compare result                           //~v590I~//~vafkR~
    SLPTR   lvtcmp[4];	//compare result                           //~vafkI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    UCHAR wkebcconst[MAX_DATA_WIDTH+1];                            //~va50I~
    UCHAR wkebcconstdbcs[MAX_DATA_WIDTH+1];                        //~va50I~
    int opt;                                                       //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************
//opd1 line
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
//	post2=Pparm[PARM_OPD1POS2];                                    //~vaz8R~
	post2=(int)Pparm[PARM_OPD1POS2];                               //~vaz8I~
//  datatype1=Pparm[PARM_DATATYPE1];                               //~vaz8R~
    datatype1=(int)Pparm[PARM_DATATYPE1];                          //~vaz8I~
    pcw=Ppcw;       //target pcw                                   //~v533I~
  if (Pfunctype!=CALC_COPY 	//not opd3=opd2 fmt                    //~v56zI~
  &&  Pfunctype!=CALC_COPYCV)	//not opd3=opd2 fmt                //~v56zI~
  {                                                                //~v56zI~
	if (!post2)
	    if (cap_getcalcprevinfo(&pcw,&plht1,&plht2,&post1,&post2))
    	    return 4;

  }//not copy operation                                            //~v56zI~
//opd2 line
    if (*(Plabplh+2))                                              //~v17hI~
    {                                                              //~v17hI~
		plhs1=*(Plabplh+2);                                        //~v17hI~
		plhs2=*(Plabplh+3);                                        //~v17hI~
    }                                                              //~v17hI~
    else                                                           //~v17hI~
    if (*Plabplh)
    {
		plhs1=*Plabplh;
		plhs2=*(Plabplh+1);
    }
    else
    {
		plhs1=plhtop;
		plhs2=plhend;
    }
//	poss1=Pparm[PARM_OPD2POS1];                                    //~vaz8R~
	poss1=(int)Pparm[PARM_OPD2POS1];                               //~vaz8I~
//  poss2=Pparm[PARM_OPD2POS2];                                    //~vaz8R~
	poss2=(int)Pparm[PARM_OPD2POS2];                               //~vaz8I~
//  datatype2=Pparm[PARM_DATATYPE2];                               //~vaz8R~
    datatype2=(int)Pparm[PARM_DATATYPE2];                          //~vaz8I~
	if (poss2==TC_CONSTSPECID)                                     //~v53JR~
    {                                                              //~v59iI~
//  	memcpy(lvts,Sconstvalue,sizeof(lvts));                     //~v53JI~//~va7aR~
    	memcpy(lvts,(void*)Pparm[PARM_CONSTVALUE],sizeof(lvts));   //~va7aR~
//      datatype2=Sconstdatatype;                                  //~v59iI~//~va7aR~
//      datatype2=Pparm[PARM_CONSTDATATYPE];                       //~vaz8R~
        datatype2=(int)Pparm[PARM_CONSTDATATYPE];                  //~vaz8I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//      if (Sconstdatatype==CALC_STRINGDATA)                       //~va5bR~//~va7aR~
        if (datatype2==CALC_STRINGDATA)                            //~va7aI~
            calc_m2bconststr(0,Pparm,lvts,wkebcconst,wkebcconstdbcs,sizeof(wkebcconst));//~va5bR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    }                                                              //~v59iI~
	if (!poss2)
    	if (cap_getcalccurinfo(Ppcw,&plhs1,&plhs2,&poss1,&poss2))
        	return 4;
//opd3 line
//	pos31=Pparm[PARM_OPD3POS1];                                    //~vaz8R~
	pos31=(int)Pparm[PARM_OPD3POS1];                               //~vaz8R~
//	pos32=Pparm[PARM_OPD3POS2];                                    //~vaz8R~
	pos32=(int)Pparm[PARM_OPD3POS2];                               //~vaz8I~
//  datatype3=Pparm[PARM_DATATYPE3];                               //~vaz8R~
    datatype3=(int)Pparm[PARM_DATATYPE3];                          //~vaz8I~

  if (post2) //not opd3=opd2 fmt                                   //~v56zI~
	width=post2-post1;
  else       //opd1 exist                                          //~v56zR~
	width=pos32-pos31;                                             //~v56zI~
//if (Pfunctype==CALC_COMP                                         //~v605R~
  if ((Pfunctype==CALC_COMP && datatype2==CALC_STRINGDATA)         //~v605I~
  ||  Pfunctype==CALC_COPY)                                        //~v56zI~
  {                                                                //~v56zI~
    if (width>MAX_DATA_WIDTHS                                      //~v56zI~
	||  poss2-poss1>MAX_DATA_WIDTHS                                //~v56zI~
	||  pos32-pos31>MAX_DATA_WIDTHS)                               //~v56zI~
    	return tcerrdatawidth();                                   //~v56zI~
  }                                                                //~v56zI~
  else                                                             //~v56zI~
    if (width>MAX_DATA_WIDTH
	||  poss2-poss1>MAX_DATA_WIDTH
	||  pos32-pos31>MAX_DATA_WIDTH)
    	return tcerrdatawidth();
    if (pos32)      //3 opd
        width=pos32-pos31;

//    if (Pfunctype==CALC_COMP)                                    //~v605R~
//    {                                                            //~v605R~
////      if (!datatype1 && !datatype2)                            //~v605R~
////          datatype1=datatype2=CALC_STRINGDATA;                 //~v605R~
//        if (!datatype1)                                          //~v605R~
//            datatype1=CALC_STRINGDATA;                           //~v605R~
//        if (!datatype2)                                          //~v605R~
//            datatype2=CALC_STRINGDATA;                           //~v605R~
//    }                                                            //~v605R~
    UPCTRREQ(pfht);  //end of a shot
    sw1st=1;
    for (plh=plht1,plhs=plhs1;;sw1st=0)
    {
    	len6sw=0;
    	skip1=0;
//  	if ((rc=tc_getplhdata(sw1st,&datatype1,&plh,plht2,post1,post2,lvtt,Pparm))!=0)//~v56zR~
      	if (Pfunctype==CALC_COPY  	//not opd3=opd2 fmt            //~v56zI~
      	||  Pfunctype==CALC_COPYCV)	//not opd3=opd2 fmt            //~v56zI~
      	{                                                          //~v56zI~
//  		rc=tc_getplhdata(sw1st,&datatype1,&plh,plht2,post1,TC_CONSTSPECID,lvtt,Pparm);//plh search only//~v57JR~
//  		rc=tc_getplhdata(0,sw1st,&datatype1,&plh,plht2,post1,TC_CONSTSPECID,lvtt,Pparm);//plh search only//~v77iR~
    		rc=tc_getplhdata(GDO_IGNSUM,sw1st,&datatype1,&plh,plht2,post1,TC_CONSTSPECID,lvtt,Pparm);//plh search only//~v77iI~
        	datatype1=datatype2;                                   //~v56zI~
            memset(lvtt,0,sizeof(lvtt));                           //~v56zI~
      	}                                                          //~v56zI~
      	else                                                       //~v56zI~
//  		rc=tc_getplhdata(sw1st,&datatype1,&plh,plht2,post1,post2,lvtt,Pparm);//~v57JR~
//  		rc=tc_getplhdata(0,sw1st,&datatype1,&plh,plht2,post1,post2,lvtt,Pparm);//~v57YR~
    		rc=tc_getplhdata(GDO_DWUP,sw1st,&datatype1,&plh,plht2,post1,post2,lvtt,Pparm);//~v57YI~
    	if (rc!=0)                                                 //~v56zI~
        {
        	if (rc==-1)	//eof
        		break;
            if (rc==4||rc==2)	//err or summ line                 //~v17hR~
	            skip1=1;
            else
            if (rc==1)
            	len6sw=CALC_TIME6;
            else
        		break;	//UALLOC_FAILED
		}
    	skip2=0;
//  	if ((rc=tc_getplhdata(sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm))!=0)//~v53JR~
		if (poss2==TC_CONSTSPECID)                                 //~v53JR~
        {                                                          //~v53JI~
        	plhs=plh;		//for safety                           //~v53JR~
            rc=0;                                                  //~v53JI~
        }                                                          //~v53JI~
        else                                                       //~v53JI~
//  		rc=tc_getplhdata(sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm);//~v57JR~
//  		rc=tc_getplhdata(0,sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm);//~v57YR~
    		rc=tc_getplhdata(GDO_DWUP,sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm);//~v57YI~
    	if (rc!=0)                                                 //~v53JI~
        {
        	if (rc==-1)	//eof
        		break;
            if (rc==4||rc==2)	//err or summline                  //~v17hR~
            	skip2=1;
            else
            if (rc==1)
            {
            	if (datatype1!='T')
            		len6sw=CALC_TIME6;
			}
            else
        		break;	//UALLOC_FAILED
		}
        recno++;
        if (skip1||skip2)
        {
        	skipno++;
            continue;
		}
//output datatype
        if (pos32)      //3 opd
        {
            datatype=datatype3;
            if (!datatype)
                datatype=datatype1;
        	pos1=pos31;
        	pos2=pos32;
		}
        else
        {
            datatype=datatype1;
        	pos1=post1;
        	pos2=post2;
		}
        convopt=0;
    	if (datatype1=='T')
        {
			if (datatype2!='T')
	            convopt=CALC_TIME_2SEC;
		}
        else
    		if (datatype2=='T')
            	convopt=CALC_TIME_1SEC;	//conv to seconds
            else
        		if (datatype=='T')		//output is time
	            	convopt=CALC_TIME_1SEC|CALC_TIME_2SEC;	//conv to seconds
        if (datatype=='T')		//output is time
        {
        	if (datatype1!='T')
            	convopt|=CALC_TIME_CONV2HMS;
		}
        else
            if (convopt||datatype1=='T')	//one or both operand is time
            	convopt|=CALC_TIME_CONV2SEC;
//    if (Pfunctype==CALC_COPY||Pfunctype==CALC_COPYCV)            //~v59SR~
      if (Pfunctype==CALC_COPY)                                    //~v59SI~
      {                                                            //~v56zI~
      	rc=0;                                                      //~v56zI~
	    memcpy(lvtt,lvts,sizeof(lvtt));                            //~v56zI~
      }                                                            //~v56zI~
      else                                                         //~v56zI~
      if (Pfunctype==CALC_COPYCV)   //data type conversion         //~v59SI~
        rc=tc_calc(convopt,datatype,'+',lvtt,lvts);	//tgt(=0)+src  //~v59SI~
      else                                                         //~v59SI~
        rc=tc_calc(convopt,datatype,Pfunctype,lvtt,lvts);	//"ST",by dec value
      if (Pfunctype==CALC_COMP)                                    //~v497I~
      {                                                            //~v497I~
       if (pos32)      //3 opd;compare target specified            //~v590I~
       {                                                           //~v590I~
	    if (Pparm[PARM_OPTION] & (PARM_TRUEFALSE|PARM_FALSETRUE)) //bool option for ==(compare)//~v62uI~
        {                                                          //~v62uM~
	        if (Pparm[PARM_OPTION] & PARM_TRUEFALSE) //bool option for ==(compare)//~v62uI~
		        rc=(rc==0);	//true or false                        //~v62uM~
            else                                                   //~v62uM~
		        rc=(rc!=0);	//false or true                        //~v62uM~
        }                                                          //~v62uM~
        lvtcmp[0]=rc;                                              //~v590I~
        lvtcmp[1]=0;	//word value                               //~v590I~
        rc=tc_setlinedata3(pcw,Pparm,plh,1,'D',pos1,pos2,lvtcmp,&dataovf);//~v590R~
        if (rc>1)                                                  //~v590I~
            break;                                                 //~v590I~
       }                                                           //~v590I~
       else                                                        //~v590I~
       {                                                           //~v590I~
		if (rc)                                                    //~v497I~
        {                                                          //~v497I~
//          lcmdunmatch(ULHULFOUND,unmatchctr,plh,plh,pfht,pfht,1);//unmatch id on lineno fld//~v74PR~
            lcmdunmatch(ULHULFOUND,ULHULFOUND,unmatchctr,plh,plh,pfht,pfht,1);//unmatch id on lineno fld//~v74PI~
            unmatchctr++;                                          //~v497I~
            skipno++;                                              //~v497I~
        }                                                          //~v497I~
       }//compare result to lineerr                                //~v590I~
      }                                                            //~v497I~
      else                                                         //~v497I~
      if (Pfunctype==CALC_COPY)                                    //~v56zI~
      {                                                            //~v56zI~
        rc=tc_setlinedatacopy(pcw,Pparm,plh,pos1,pos2,lvtt,&dataovf);//~v56zI~
        if (rc>1)                                                  //~v56zI~
            break;                                                 //~v56zI~
      }                                                            //~v56zI~
      else                                                         //~v56zI~
      {                                                            //~v497I~
        if (rc)
			skipno+=tc_setplherr(plh);
        else                                                       //~v57JI~
        {                                                          //~v57JI~
//      rc=tc_setlinedata(pcw,plh,1,datatype|len6sw,pos1,pos2,lvtt,&dataovf);//~v56zR~
        rc=tc_setlinedata3(pcw,Pparm,plh,1,datatype|len6sw,pos1,pos2,lvtt,&dataovf);//~v56zI~
        if (rc>1)
            break;
        }                                                          //~v57JI~
      }                                                            //~v497I~
	}//all plh
	if (rc==UALLOC_FAILED)
    	return rc;
    UPCTRREQ(pfht);  //end of a shot
//  uerrmsg("%s:total %ld, err=%ld, dataovf=%d.",0,                //~v71UR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	opt=XEERMO_CAT;                                                //~va50I~
    xeerrmsg(opt,4,XEERMPTS_CMDSTR XEERMPTS_NOTSTR XEERMPTS_NOTSTR XEERMPTS_NOTSTR,//~va50I~
			"%s:total %ld, err=%ld, dataovf=%d.",0,                //~va50I~
    		Ppcw->UCWparm,recno,skipno,dataovf);                   //~va50I~
#else                                                              //~va50I~
    uerrmsgcat("%s:total %ld, err=%ld, dataovf=%d.",0,             //~v71UR~
    		Ppcw->UCWparm,recno,skipno,dataovf);
#endif                                                             //~va50I~
    return  (skipno||dataovf);
}//tc_ft2
//**************************************************************** //~v533I~
//  count alive record in the time span                            //~v533I~
//*rc   :0   or 1:data err or 4:env err or UALLOC_FAILED           //~v533I~
//**************************************************************** //~v533I~
//int tc_ft2count(PUCLIENTWE Ppcw,int Pfunctype,int *Pparm,PULINEH *Plabplh)//~v533I~//~va70R~
int tc_ft2count(PUCLIENTWE Ppcw,int Pfunctype,XECALCPARM *Pparm,PULINEH *Plabplh)//~va70I~
{                                                                  //~v533I~
	PUCLIENTWE pcw;                                                //~v533R~
	PUFILEH pfht;                                                  //~v533I~
	PULINEH plh,plht1,plht2,plhtop,plhend;                         //~v533I~
	PULINEH plhs,plhs1,plhs2;                                      //~v533I~
	int     post1,post2,pos31,pos32,rc=0,skipsw,pos1,pos2;         //~v533R~
	int     poss1,poss2,width,sw1st,datatype,datatype1,datatype2,datatype3;//~v533I~
	int     datatype1s,datatype2s;                                 //~v58wI~
	int     fldlen;                                                //~v533R~
	int     eqopt,comprc;                                          //~v587I~
    long    recno=0,skipno=0,dataovf=0;                            //~v533I~
//  long    lvtt[3],lvts[3];                                       //~v57JR~
//  long    lvtt[4],lvts[4];                                       //~v57JI~//~vafkR~
    SLPTR   lvtt[4],lvts[4];                                       //~vafkI~
//  long    oldlv[4],enddatalv[4];                                 //~v58wI~//~vafkR~
    SLPTR   oldlv[4],enddatalv[4];                                 //~vafkI~
    char *olddata,*enddata=NULL;                                        //~v533I~//~vafcR~
    PRCW    prcw,prcw0,prcwe,prcw2;                                //~v533R~
    int optgpd;                                                    //~va2bI~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8file;                                                //~va20R~
    char *olddbcs=NULL,*enddbcs=NULL;                                        //~va20I~//~vafcR~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************                                //~v533I~
//opd1 line                                                        //~v533I~
    pfht=UGETPFHFROMPCW(Ppcw);                                     //~v533I~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=FILEUTF8MODE(pfht);                                 //~va20I~
	handle=pfht->UFHhandle;                                        //~va79I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(pfht);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	plhtop=UGETQTOP(&pfht->UFHlineque);                            //~v533I~
	plhend=UGETQEND(&pfht->UFHlineque);                            //~v533I~
                                                                   //~v533I~
    if (*Plabplh)                                                  //~v533I~
    {                                                              //~v533I~
		plht1=*Plabplh;                                            //~v533I~
		plht2=*(Plabplh+1);                                        //~v533I~
    }                                                              //~v533I~
    else                                                           //~v533I~
    {                                                              //~v533I~
		plht1=plhtop;                                              //~v533I~
		plht2=plhend;                                              //~v533I~
    }                                                              //~v533I~
//	post1=Pparm[PARM_OPD1POS1];                                    //~vaz8R~
	post1=(int)Pparm[PARM_OPD1POS1];                               //~vaz8I~
//	post2=Pparm[PARM_OPD1POS2];                                    //~vaz8R~
	post2=(int)Pparm[PARM_OPD1POS2];                               //~vaz8I~
//  datatype1=Pparm[PARM_DATATYPE1];                               //~v533I~
//  datatype1=Pparm[PARM_DATATYPE1];                               //~vaz8R~
    datatype1=(int)Pparm[PARM_DATATYPE1];                          //~vaz8I~
  if (datatype1!='T')                                              //~v58wI~
  {                                                                //~v58zI~
   if (!datatype1)                                                 //~v58wI~
    datatype1=CALC_STRINGDATA;                                     //~v533I~
   else                                                            //~v58wI~
    return tcerrinvalidforcount();                                 //~v58wI~
  }                                                                //~v58zI~
    datatype1s=datatype1;                                          //~v58wI~
    pcw=Ppcw;                                                      //~v533I~
	if (!post2)                                                    //~v533I~
	    if (cap_getcalcprevinfo(&pcw,&plht1,&plht2,&post1,&post2)) //~v533I~
    	    return 4;                                              //~v533I~
//opd2 line                                                        //~v533I~
    if (*(Plabplh+2))                                              //~v533I~
    {                                                              //~v533I~
		plhs1=*(Plabplh+2);                                        //~v533I~
		plhs2=*(Plabplh+3);                                        //~v533I~
    }                                                              //~v533I~
    else                                                           //~v533I~
    if (*Plabplh)                                                  //~v533I~
    {                                                              //~v533I~
		plhs1=*Plabplh;                                            //~v533I~
		plhs2=*(Plabplh+1);                                        //~v533I~
    }                                                              //~v533I~
    else                                                           //~v533I~
    {                                                              //~v533I~
		plhs1=plhtop;                                              //~v533I~
		plhs2=plhend;                                              //~v533I~
    }                                                              //~v533I~
//	poss1=Pparm[PARM_OPD2POS1];                                    //~vaz8R~
	poss1=(int)Pparm[PARM_OPD2POS1];                               //~vaz8I~
//	poss2=Pparm[PARM_OPD2POS2];                                    //~vaz8R~
	poss2=(int)Pparm[PARM_OPD2POS2];                               //~vaz8I~
//  datatype2=Pparm[PARM_DATATYPE2];                               //~v533I~
//  datatype2=Pparm[PARM_DATATYPE2];                               //~vaz8R~
    datatype2=(int)Pparm[PARM_DATATYPE2];                          //~vaz8I~
  if (datatype1!='T')                                              //~v58wI~
  {                                                                //~v58wI~
   if (datatype2)                                                  //~v58wI~
    return tcerrinvalidforcount();                                 //~v58wI~
   else                                                            //~v58wI~
    datatype2=CALC_STRINGDATA;                                     //~v533I~
  }                                                                //~v58wI~
    datatype2s=datatype2;                                          //~v58wI~
	if (poss2==TC_CONSTSPECID)                                     //~v53JR~
    {                                                              //~v53JI~
//  	lvts[0]=(long)Sconstaddr;        //strng data fmt          //~v53JR~//~va7aR~
//    	lvts[0]=Pparm[PARM_CONSTADDR];        //strng data fmt     //~va7aI~//+vb30R~
      	lvts[0]=(SLPTR)Pparm[PARM_CONSTADDR];        //strng data fmt//+vb30I~
		lvts[1]=0;                                                 //~v53JI~
//  	lvts[2]=(long)Sconstlen;                                   //~v53JI~//~va7aR~
//  	lvts[2]=Pparm[PARM_CONSTLEN];                              //~va7aI~//+vb30R~
    	lvts[2]=(SLPTR)Pparm[PARM_CONSTLEN];                       //+vb30I~
    }                                                              //~v53JI~
	if (!poss2)                                                    //~v533I~
    	if (cap_getcalccurinfo(Ppcw,&plhs1,&plhs2,&poss1,&poss2))  //~v533I~
        	return 4;                                              //~v533I~
//opd3 line                                                        //~v533I~
//	pos31=Pparm[PARM_OPD3POS1];                                    //~vaz8R~
	pos31=(int)Pparm[PARM_OPD3POS1];                               //~vaz8I~
//  pos32=Pparm[PARM_OPD3POS2];                                    //~vaz8R~
    pos32=(int)Pparm[PARM_OPD3POS2];                               //~vaz8I~
//  datatype3=Pparm[PARM_DATATYPE3];                               //~vaz8R~
    datatype3=(int)Pparm[PARM_DATATYPE3];                          //~vaz8I~
                                                                   //~v533I~
  if (poss2==TC_CONSTSPECID)                                       //~v53JR~
//  fldlen=Sconstlen;                                              //~v53JI~//~va7aR~
//  fldlen=Pparm[PARM_CONSTLEN];                                   //~vaz8R~
    fldlen=(int)Pparm[PARM_CONSTLEN];                              //~vaz8I~
  else                                                             //~v53JI~
    fldlen=poss2-poss1;                                            //~v533I~
	width=post2-post1;                                             //~v533I~
    if (width>MAX_DATA_WIDTH                                       //~v533I~
	||  fldlen>MAX_DATA_WIDTH                                      //~v533R~
	||  pos32-pos31>MAX_DATA_WIDTH)                                //~v533I~
    	return tcerrdatawidth();                                   //~v533I~
  if (datatype1s==CALC_STRINGDATA)                                 //~v58wR~
  {                                                                //~v58wI~
	if (fldlen!=width)                                             //~v533I~
    {                                                              //~v533I~
  		if (!(fldlen<width && poss2==TC_CONSTSPECID))              //~v53JR~
        {                                                          //~v53JI~
//      uerrmsg("operand length is not same for ~(count alive record)",//~v53JR~
//              "~(存続カウント)操作のオペランド長が等しくない");  //~v53JR~
	    	uerrmsg("operand length is not same for ~(count alive record),%d and %d.",//~v53JI~
		            "~(存続カウント)操作のオペランド長が等しくない,%d != %d。",//~v53JI~
					width,fldlen);                                 //~v53JI~
        return 4;                                                  //~v533I~
        }                                                          //~v53JI~
    }                                                              //~v533I~
  }//datatype                                                      //~v58wI~
//  if (pos32)      //3 opd                                        //~v53JR~
//      width=pos32-pos31;                                         //~v53JR~
                                                                   //~v533I~
//  if (Pfunctype==CALC_COMP)                                      //~v533I~
//  	if (!datatype1 && !datatype2)                              //~v533I~
//      	datatype1=datatype2=CALC_STRINGDATA;                   //~v533I~
//count record                                                     //~v533I~
	optgpd=GDO_EXISTCTR;  //get field data for "~"(existing count calc) operation//~va2bI~
    optgpd|=(fldlen<<GDO_SHIFTCTR);                                //~va2bI~
    sw1st=1;                                                       //~v533I~
    for (plh=plht1,plhs=plhs1;;sw1st=0)                            //~v533I~
    {                                                              //~v533I~
    	datatype1=datatype1s;//may reset by getplhdata             //~v58wI~
    	datatype2=datatype2s;                                      //~v58wI~
//  	if ((rc=tc_getplhdata(sw1st,&datatype1,&plh,plht2,post1,post2,lvtt,Pparm))!=0)//~v57JR~
//  	if ((rc=tc_getplhdata(0,sw1st,&datatype1,&plh,plht2,post1,post2,lvtt,Pparm))!=0)//~va2bR~
    	if ((rc=tc_getplhdata(optgpd,sw1st,&datatype1,&plh,plht2,post1,post2,lvtt,Pparm))!=0)//~va2bI~
        {                                                          //~v533I~
        	if (rc==-1)	//eof                                      //~v533I~
        		break;                                             //~v533I~
            if (rc==UALLOC_FAILED)                                 //~v533I~
        		return rc;	//UALLOC_FAILED                        //~v533I~
		}                                                          //~v533I~
//  	if ((rc=tc_getplhdata(sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm))!=0)//~v53JI~
		if (poss2==TC_CONSTSPECID)                                 //~v53JR~
        {                                                          //~v53JI~
        	plhs=plh;		//for safety                           //~v53JR~
            rc=0;                                                  //~v53JI~
        }                                                          //~v53JI~
        else                                                       //~v53JI~
//  		rc=tc_getplhdata(sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm);//~v57JR~
//  		rc=tc_getplhdata(0,sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm);//~va2bR~
    		rc=tc_getplhdata(optgpd,sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm);//~va2bR~
    	if (rc!=0)                                                 //~v53JI~
        {                                                          //~v533I~
        	if (rc==-1)	//eof                                      //~v533I~
        		break;                                             //~v533I~
            if (rc==UALLOC_FAILED)                                 //~v533I~
        		return rc;	//UALLOC_FAILED                        //~v533I~
		}                                                          //~v533I~
        recno++;                                                   //~v533I~
	}//all plh                                                     //~v533I~
//alloc work                                                       //~v533I~
//  prcw0=umalloc((UINT)(RCWSZ*recno));                                    //~v533I~//+vb30R~
    prcw0=umalloc(RCWSZ*(size_t)recno);                            //+vb30I~
    UALLOCCHK(prcw0,UALLOC_FAILED);                                //~v533R~
//  memset(prcw0,0,(UINT)(RCWSZ*recno));                                   //~v533R~//+vb30R~
    memset(prcw0,0,RCWSZ*(size_t)recno);                           //+vb30I~
//fill work;                                                       //~v533I~
    sw1st=1;                                                       //~v533I~
    prcw=prcw0;                                                    //~v533I~
    olddata=0;                                                     //~v533I~
    for (plh=plht1,plhs=plhs1;;sw1st=0,prcw++)                     //~v533I~
    {                                                              //~v533I~
    	datatype1=datatype1s;                                      //~v58wI~
    	datatype2=datatype2s;                                      //~v58wI~
    	skipsw=0;                                                  //~v533R~
//  	if ((rc=tc_getplhdata(sw1st,&datatype1,&plh,plht2,post1,post2,lvtt,Pparm))!=0)//~v57JR~
//    	if ((rc=tc_getplhdata(0,sw1st,&datatype1,&plh,plht2,post1,post2,lvtt,Pparm))!=0)//~va2bR~
      	if ((rc=tc_getplhdata(optgpd,sw1st,&datatype1,&plh,plht2,post1,post2,lvtt,Pparm))!=0)//~va2bI~
        {                                                          //~v533I~
        	if (rc==-1)	//eof                                      //~v533I~
        		break;                                             //~v533I~
            if (rc==UALLOC_FAILED)                                 //~v533I~
            {                                                      //~v58wI~
    			ufree(prcw0);                                      //~v58wI~
        		return rc;	//UALLOC_FAILED                        //~v533I~
            }                                                      //~v58wI~
            if (rc==4||rc==2)	//err or summ line                 //~v533I~
	            skipsw=1;                                          //~v533R~
		}                                                          //~v533I~
//  	if ((rc=tc_getplhdata(sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm))!=0)//~v53JR~
		if (poss2==TC_CONSTSPECID)                                 //~v53JR~
        {                                                          //~v53JI~
        	plhs=plh;		//for safety                           //~v53JR~
            rc=0;                                                  //~v53JI~
        }                                                          //~v53JI~
        else                                                       //~v53JI~
//  		rc=tc_getplhdata(sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm);//~v57JR~
//   		rc=tc_getplhdata(0,sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm);//~va2bR~
     		rc=tc_getplhdata(optgpd,sw1st,&datatype2,&plhs,plhs2,poss1,poss2,lvts,Pparm);//~va2bR~
		if (rc!=0)                                                 //~v53JI~
        {                                                          //~v533I~
        	if (rc==-1)	//eof                                      //~v533I~
        		break;                                             //~v533I~
            if (rc==UALLOC_FAILED)                                 //~v533I~
            {                                                      //~v58wI~
    			ufree(prcw0);                                      //~v58wI~
        		return rc;	//UALLOC_FAILED                        //~v533I~
            }                                                      //~v58wI~
            if (rc==4||rc==2)	//err or summline                  //~v533I~
            	skipsw=1;                                          //~v533R~
		}                                                          //~v533I~
//seq chk                                                          //~v533I~
  	  if (datatype1s==CALC_STRINGDATA)                             //~v58wI~
      {                                                            //~v58wI~
        if (fldlen!=(int)lvtt[2]                                   //~v533R~
        ||  fldlen!=(int)lvts[2])                                  //~v533R~
        	skipsw=1;                                              //~v533I~
      }                                                            //~v58wI~
        if (!skipsw && olddata)	//1st valid record detected        //~v533R~
        {                                                          //~v533I~
  	      if (datatype1s==CALC_STRINGDATA)                         //~v58wI~
          {                                                        //~v58wI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//          if (XESUB_memcmp_ebcdd(swebcfile,swutf8file,XESUBDDSCO_HIGHLOW,(UCHAR*)lvtt[0],(UCHAR*)lvtt[1],olddata,olddbcs,fldlen)<0)//~va50I~//~va79R~
            if (XESUB_memcmp_ebcdd(swebcfile,swutf8file,handle,XESUBDDSCO_HIGHLOW,(UCHAR*)lvtt[0],(UCHAR*)lvtt[1],olddata,olddbcs,fldlen)<0)//~va79I~
    #else                                                          //~va50I~
            if (XESUB_DDMEMCMP(swutf8file,XESUBDDSCO_HIGHLOW,(UCHAR*)lvtt[0],(UCHAR*)lvtt[1],olddata,olddbcs,fldlen)<0)//~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
            if (memcmp((void*)lvtt[0],olddata,(UINT)fldlen)<0)  //seq down//~v535R~
#endif                                                             //~va20I~
            {                                                      //~v535I~
				tc_setplherr(plh);                                 //~v535I~
//          	uerrmsg("1st operand should be sorted for ~(count alive record)",//~v58wR~
//                  "~(存続カウント)操作の第一オペランドが整列されていません");//~v58wR~
            	uerrmsg("1st operand(string data) should be sorted for ~(count alive record)",//~v58wI~
                    "~(存続カウント)操作の第一オペランド(文字列)が整列されていません");//~v58wI~
    			ufree(prcw0);                                      //~v58wI~
            	return 4;                                          //~v535I~
            }                                                      //~v535I~
//          if (memcmp((void*)lvtt[0],(void*)lvts[0],(UINT)fldlen)>0)	//opd1>opd2//~v58wR~
//  	        skipsw=1;                                          //~v58wR~
          }//string data                                           //~v58wI~
          else                                                     //~v58wI~
          {                                                        //~v58wI~
            if (ucalc_time(0,'?',lvtt,oldlv)<0)  //time stamp compre//~v58wR~
            {                                                      //~v58wI~
				tc_setplherr(plh);                                 //~v58wI~
            	uerrmsg("1st operand(Timestamp data) should be sorted for ~(count alive record)",//~v58wI~
                    "~(存続カウント)操作の第一オペランド(時刻データ)が整列されていません");//~v58wI~
    			ufree(prcw0);                                      //~v58wI~
            	return 4;                                          //~v58wI~
            }                                                      //~v58wI~
          }//timestamp data                                        //~v58wI~
        }                                                          //~v533I~
        if (!skipsw)	//1st valid record detected                //~v58wI~
        {                                                          //~v58wI~
  	      	if (datatype1s==CALC_STRINGDATA)                       //~v58wI~
            {                                                      //~v58wI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//          	if (XESUB_memcmp_ebcdd(swebcfile,swutf8file,XESUBDDSCO_HIGHLOW,(UCHAR*)lvtt[0],(UCHAR*)lvtt[1],(UCHAR*)lvts[0],(UCHAR*)lvts[1],fldlen)>0)//~va50R~//~va79R~
            	if (XESUB_memcmp_ebcdd(swebcfile,swutf8file,handle,XESUBDDSCO_HIGHLOW,(UCHAR*)lvtt[0],(UCHAR*)lvtt[1],(UCHAR*)lvts[0],(UCHAR*)lvts[1],fldlen)>0)//~va79I~
    #else                                                          //~va50I~
            	if (XESUB_DDMEMCMP(swutf8file,XESUBDDSCO_HIGHLOW,(UCHAR*)lvtt[0],(UCHAR*)lvtt[1],(UCHAR*)lvts[0],(UCHAR*)lvts[1],fldlen)>0)//~va50I~
	#endif                                                         //~va50I~
#else                                                              //~va20I~
				if (memcmp((void*)lvtt[0],(void*)lvts[0],(UINT)fldlen)>0)	//opd1>opd2//~v58wI~
#endif                                                             //~va20I~
	  		        skipsw=1;                                      //~v58wI~
			}                                                      //~v58wI~
            else                                                   //~v58wI~
            {                                                      //~v58wI~
                if ( datatype2=='T')                               //~v58wI~
                {                                                  //~v58wI~
                    if (ucalc_time(0,'?',lvtt,lvts)>0) //opd1>opd2 //~v58wR~
                        skipsw=1;                                  //~v58wI~
                }                                                  //~v58wI~
                else                                               //~v58wI~
                {                                                  //~v58wI~
                    if (ucalc_binop(0,'?',0,lvts)>0) //0>opd2      //~v58wI~
                        skipsw=1;                                  //~v58wI~
                }                                                  //~v58wI~
            }                                                      //~v58wI~
        }//no err                                                  //~v58wI~
        prcw->RCWplh=plh;                                          //~v533I~
        if (skipsw)                                                //~v533R~
        {                                                          //~v533I~
        	skipno++;                                              //~v533I~
            prcw->RCWcount=-1;  //err id                           //~v533I~
			tc_setplherr(plh);                                     //~v533I~
		}                                                          //~v533I~
        else                                                       //~v533I~
        {                                                          //~v533I~
        	olddata=prcw->RCWdata1=(void*)lvtt[0];                 //~v533I~
#ifdef UTF8UCS2                                                    //~va20I~
        	olddbcs=prcw->RCWdbcs1=(void*)lvtt[1];                 //~va20I~
#endif                                                             //~va20I~
  	      if (datatype1s==CALC_STRINGDATA)                         //~v58wI~
          {                                                        //~va20I~
        	prcw->RCWdata2=(void*)lvts[0];                         //~v533I~
#ifdef UTF8UCS2                                                    //~va20I~
        	prcw->RCWdbcs2=(void*)lvts[1];                         //~va20I~
#endif                                                             //~va20I~
          }                                                        //~va20I~
          else                                                     //~v58wI~
          {                                                        //~v58wI~
        	memcpy(oldlv,lvtt,sizeof(oldlv));                      //~v58wR~
        	memcpy(prcw->RCWdata1lv,lvtt,sizeof(prcw->RCWdata1lv));//~v58wI~
        	memcpy(prcw->RCWdata2lv,lvts,sizeof(prcw->RCWdata2lv));//~v58wR~
          }                                                        //~v58wI~
          prcw->RCWdatatype1=(char)datatype1;                      //~v58wR~
          prcw->RCWdatatype2=(char)datatype2;                      //~v58wR~
        }                                                          //~v533I~
	}//all plh                                                     //~v533I~
//count record                                                     //~v533I~
    eqopt=(*(Pparm+PARM_OPTION) & PARM_COUNTEQ);	//counteq option//~v587R~
    prcw=prcw0;                                                    //~v533I~
    prcwe=prcw0+recno;                                             //~v533I~
    for (prcw=prcw0;prcw<prcwe;prcw++)                             //~v533I~
    {                                                              //~v533I~
    	if (prcw->RCWcount<0)	//err record                       //~v533I~
        	continue;                                              //~v533I~
  	  if (datatype1s==CALC_STRINGDATA)                             //~v58wI~
      {                                                            //~va20I~
        enddata=prcw->RCWdata2;	//2nd opd                          //~v533I~
#ifdef UTF8UCS2                                                    //~va20I~
        enddbcs=prcw->RCWdbcs2;	//2nd opd  dbcs                    //~va20I~
#endif                                                             //~va20I~
      }                                                            //~va20I~
      else                                                         //~v58wI~
      {                                                            //~v58wI~
        if (prcw->RCWdatatype2=='T')                               //~v58wR~
	        memcpy(enddatalv,prcw->RCWdata2lv,sizeof(enddatalv));	//2nd opd//~v58wR~
        else                                                       //~v58wI~
        {                                                          //~v58wI~
	        memcpy(enddatalv,prcw->RCWdata1lv,sizeof(enddatalv));	//2nd opd//~v58wR~
        	ucalc_time(CALC_TIME_2SEC,'+',enddatalv,prcw->RCWdata2lv);//~v58wR~
        }                                                          //~v58wI~
      }                                                            //~v58wI~
        for (prcw2=prcw+1,prcw->RCWcount++;prcw2<prcwe;prcw2++)    //~v533I~
        {                                                          //~v533I~
	    	if (prcw2->RCWcount<0)	//err record                   //~v533I~
    	    	continue;                                          //~v533I~
  	      if (datatype1s==CALC_STRINGDATA)                         //~v58wI~
          {                                                        //~v58wI~
//          if (memcmp(prcw2->RCWdata1,enddata,(UINT)fldlen)>=0)   //~v587R~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//          if ((comprc=XESUB_memcmp_ebcdd(swebcfile,swutf8file,XESUBDDSCO_HIGHLOW,prcw2->RCWdata1,prcw2->RCWdbcs1,enddata,enddbcs,fldlen))>0)//starttime of follower>endtime of me//~va50I~//~va79R~
            if ((comprc=XESUB_memcmp_ebcdd(swebcfile,swutf8file,handle,XESUBDDSCO_HIGHLOW,prcw2->RCWdata1,prcw2->RCWdbcs1,enddata,enddbcs,fldlen))>0)//starttime of follower>endtime of me//~va79I~
    #else                                                          //~va50I~
            if ((comprc=XESUB_DDMEMCMP(swutf8file,XESUBDDSCO_HIGHLOW,prcw2->RCWdata1,prcw2->RCWdbcs1,enddata,enddbcs,fldlen))>0)//starttime of follower>endtime of me//~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
            if ((comprc=memcmp(prcw2->RCWdata1,enddata,(UINT)fldlen))>0)//starttime of follower>endtime of me//~v587R~
#endif                                                             //~va20I~
            	break;                                             //~v533I~
          }                                                        //~v58wI~
          else                                                     //~v58wI~
          {                                                        //~v58wI~
            if ((comprc=ucalc_time(0,'?',prcw2->RCWdata1lv,enddatalv))>0)//starttime of follower>endtime of me//~v58wR~
            	break;                                             //~v58wI~
          }                                                        //~v58wI~
            if (!comprc)	//starttime==endtime                   //~v587I~
            	if (!eqopt) //option is not count eq               //~v587R~
	            	break;                                         //~v587I~
	    	prcw2->RCWcount++;	//err record                       //~v533I~
        }                                                          //~v533I~
	}//all plh                                                     //~v533I~
    UPCTRREQ(pfht);  //end of a shot                               //~v533I~
    sw1st=1;                                                       //~v533I~
    lvtt[1]=lvtt[2]=0;                                             //~v533I~
    for (prcw=prcw0;prcw<prcwe;prcw++)                             //~v533I~
    {                                                              //~v533I~
    	plh=prcw->RCWplh;                                          //~v533I~
    	if (prcw->RCWcount<0)	//err record                       //~v533I~
        	continue;                                              //~v533I~
//output datatype                                                  //~v533I~
        if (pos32)      //3 opd                                    //~v533I~
        {                                                          //~v533I~
            datatype=datatype3;                                    //~v533I~
            if (!datatype)                                         //~v533I~
                datatype='D';                                      //~v533I~
        	pos1=pos31;                                            //~v533I~
        	pos2=pos32;                                            //~v533I~
		}                                                          //~v533I~
        else                                                       //~v533I~
        {                                                          //~v533I~
            datatype='D';                                          //~v533I~
        	pos1=post1;                                            //~v533I~
        	pos2=post2;                                            //~v533I~
		}                                                          //~v533I~
        lvtt[0]=prcw->RCWcount;                                    //~v533I~
//      rc=tc_setlinedata(pcw,plh,1,datatype,pos1,pos2,lvtt,&dataovf);//~v56zR~
        rc=tc_setlinedata3(pcw,Pparm,plh,1,datatype,pos1,pos2,lvtt,&dataovf);//~v56zI~
		if (rc==UALLOC_FAILED)                                     //~v533I~
        {                                                          //~v533I~
        	ufree(prcw0);                                          //~v533I~
    		return rc;                                             //~v533I~
        }                                                          //~v533I~
        if (rc>1)                                                  //~v533I~
            break;                                                 //~v533I~
	}//all plh                                                     //~v533I~
    ufree(prcw0);                                                  //~v533I~
    UPCTRREQ(pfht);  //end of a shot                               //~v533I~
	uerrmsg("%s:total %ld, err=%ld, dataovf=%d.",0,                //~v533I~
    		Ppcw->UCWparm,recno,skipno,dataovf);                   //~v533I~
    return  (skipno||dataovf);                                     //~v533I~
}//tc_ft2count                                                     //~v533I~
//****************************************************************
// get valid plh
//*rc   :-1:eof or 4 err or UALLOC_FAILED  1:hhmmss(6byte data) 2:summary area detected
//****************************************************************
//int tc_getplhdata(int Psw1st,int *Pdatatype,PULINEH *Ppplh,PULINEH Pendplh,//~v57JR~
int tc_getplhdata(int Popt,int Psw1st,int *Pdatatype,PULINEH *Ppplh,PULINEH Pendplh,//~v57JI~
//				int Ppos1,int Ppos2,long *Pvalue,int *Pparm)       //~va70R~
//				int Ppos1,int Ppos2,long *Pvalue,XECALCPARM *Pparm)//~va70I~//~vafkR~
				int Ppos1,int Ppos2,SLPTR *Pvalue,XECALCPARM *Pparm)//~vafkI~
{
	PULINEH plh;
    int rc=0,len,ignsw,nxsw,span,errsw;                              //~v17hR~//~vaf9R~
    char *pc;
#ifdef UTF8UCS2                                                    //~va20R~
	PUFILEH pfh;                                                   //~va20R~
	int swutf8file;                                                //~va20R~
    char *pcd;                                                     //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile,optgd,len2;                                      //~va50R~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************
    plh=*Ppplh;
#ifdef UTF8UCS2                                                    //~va20R~
	pfh=UGETPFH(plh);                                              //~va20R~
	swutf8file=FILEUTF8MODE(pfh);                                  //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
    handle=pfh->UFHhandle;                                         //~va79I~
    optgd=swebcfile*GDO_EBC;//for umeric data                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (!Psw1st)
    {                                                              //~v533I~
    	if (plh==Pendplh)	
        	return -1;		//eof
        else
    		plh=UGETQNEXT(plh);
    }                                                              //~v533I~

	ignsw=(Pparm[PARM_OPTION] & PARM_SUMISRT_IGNORE);
	errsw=(Pparm[PARM_OPTION] & PARM_SUMISRT_SUMERR);              //~v17hI~
//  nxsw=Pparm[PARM_NXSW];                                         //~vaz8R~
    nxsw=(int)Pparm[PARM_NXSW];                                    //~vaz8I~
    for (;plh;plh=UGETQNEXT(plh))
    {
        if (plh->ULHtype==ULHTDATA)
        {
            if (!nxsw                                              //~v17fR~
            ||  !UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))
            {
                if (!plh->ULHdbcs)
                    if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len
                        return UALLOC_FAILED;
                len=plh->ULHlen;
              if (!(len>TCHDR_LINEID_TRAILERSZ                     //~v435I~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//              	  && UCVEBCUTF_eqascii_b2a(swebcfile,swutf8file,*(plh->ULHdata),*(plh->ULHdbcs),TCHDR_LINEID)//~va50I~//~va79R~
                	  && UCVEBCUTF_eqascii_b2a(swebcfile,swutf8file,handle,*(plh->ULHdata),*(plh->ULHdbcs),TCHDR_LINEID)//~va79I~
    #else                                                          //~va50I~
                	  && UTF_eq(swutf8file,*(plh->ULHdata),*(plh->ULHdbcs),TCHDR_LINEID)//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
                	  && *plh->ULHdata==TCHDR_LINEID               //~v435I~
#endif                                                             //~va20R~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50R~
                	  && (len2=len-UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,plh->ULHdata,plh->ULHdbcs,len),//~va50R~
              			 len2<TCHDR_LINEID_TRAILERSZ               //~va50R~
                         ||                                        //~va50I~
//                       !XESUB_EBCUTF8_memcmpeq_bandl(swebcfile,swutf8file,plh->ULHdata+len2-TCHDR_LINEID_TRAILERSZ,//~va50I~//~va79R~
                         !XESUB_EBCUTF8_memcmpeq_bandl(swebcfile,swutf8file,handle,plh->ULHdata+len2-TCHDR_LINEID_TRAILERSZ,//~va79I~
                	  			plh->ULHdbcs+len2-TCHDR_LINEID_TRAILERSZ,//~va50R~
                      			TCHDR_LINEID_TRAILER,0/*dbcs2*/,TCHDR_LINEID_TRAILERSZ)//~va50I~
                         )                                         //~va50I~
	#else                                                          //~va50R~
                	  && !XESUB_DDMEMCMP(swutf8file,XESUBDDSCO_EQCHKONLY,plh->ULHdata+len-TCHDR_LINEID_TRAILERSZ,//~va20I~
                	  			plh->ULHdbcs+len-TCHDR_LINEID_TRAILERSZ,//~va20I~
                      			TCHDR_LINEID_TRAILER,0/*dbcs2*/,TCHDR_LINEID_TRAILERSZ)//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50R~
#else                                                              //~va20I~
                	  && !memcmp(plh->ULHdata+len-TCHDR_LINEID_TRAILERSZ,//~v435I~
                      			TCHDR_LINEID_TRAILER,TCHDR_LINEID_TRAILERSZ)//~va20R~
#endif                                                             //~va20I~
                     ))                                            //~v435I~
              {	//not tc hdr                                       //~v435I~
               if (Ppos2==TC_CONSTSPECID)                          //~v54JI~
               {                                                   //~v54JI~
                    pc=plh->ULHdata;                               //~v57xI~
#ifdef UTF8UCS2                                                    //~va20R~
                    pcd=plh->ULHdbcs;                              //~va20R~
#endif                                                             //~va20R~
                  if (Popt & GDO_IGNSUM)                           //~v77iI~
                    span=len;   //continue getlinedata             //~v77iI~
                  else                                             //~v77iI~
//                if (Sconstdatatype==CALC_STRINGDATA)             //~v76CI~//~va7aR~
                  if (Pparm[PARM_CONSTDATATYPE]==CALC_STRINGDATA)  //~va7aI~
                    span=len;   //continue getlinedata             //~v76CI~
                  else                                             //~v76CI~
#ifdef UTF8UCS2                                                    //~va20R~
//*may have no path to this line                                   //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                    span=(int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,pc,plh->ULHdbcs,len);//~va50I~
	#else  //UTF8EBCD raw ebcdic file support                      //~va50I~
                    span=(int)UTF_umemspnc(swutf8file,pc,plh->ULHdbcs,' ',len);//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
                    span=(int)umemspnc(pc,' ',(UINT)len);          //~v57xI~
#endif                                                             //~va20R~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//                  if (span!=len && UCVEBCUTF_eqascii_b2a(swebcfile,swutf8file,*(pc+span),*(pcd+span),CALC_SUMMFLD))//~va50I~//~va79R~
                    if (span!=len && UCVEBCUTF_eqascii_b2a(swebcfile,swutf8file,handle,*(pc+span),*(pcd+span),CALC_SUMMFLD))//~va79I~
	#else  //UTF8EBCD raw ebcdic file support                      //~va50I~
                    if (span!=len && UTF_eq(swutf8file,*(pc+span),*(pcd+span),CALC_SUMMFLD))//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
                    if (span!=len && *(pc+span)==CALC_SUMMFLD)     //~v57xI~
#endif                                                             //~va20R~
                    {                                              //~v57xI~
                    	if (ignsw)                                 //~v57xI~
                        {                                          //~v57xI~
    						if (plh==Pendplh)                      //~v57xI~
        						return -1;	//eof                  //~v57xI~
                    		continue;                              //~v57xI~
                        }                                          //~v57xI~
                        else                                       //~v57xI~
                    	if (errsw)                                 //~v57xI~
                        	rc=4;                                  //~v57xI~
                        else                                       //~v57xI~
                    		rc=2;                                  //~v57xI~
                    }                                              //~v57xI~
                    else    //not summary line                     //~v57xI~
                    {                                              //~v57xI~
//  			memcpy(Pvalue,Sconstvalue,sizeof(Sconstvalue));    //~v54JI~//~va7aR~
    			memcpy(Pvalue,(void*)Pparm[PARM_CONSTVALUE],DDECSZ);//~va7aR~
//              *Pdatatype=Sconstdatatype;                         //~v54JI~//~va7aR~
//              *Pdatatype=Pparm[PARM_CONSTDATATYPE];              //~vaz8R~
                *Pdatatype=(int)Pparm[PARM_CONSTDATATYPE];         //~vaz8I~
                rc=0;                                              //~v54JI~
                    }                                              //~v57xI~
               }                                                   //~v54JI~
               else                                                //~v54JI~
               {//not const                                        //~v54JI~
                if (len<=Ppos1)
                	rc=4;
                else
                {
					len-=Ppos1;
                    if (len>Ppos2-Ppos1)                           //~v17hI~
                        len=Ppos2-Ppos1;                           //~v17hI~
                    pc=plh->ULHdata+Ppos1;
#ifdef UTF8UCS2                                                    //~va20R~
                    pcd=plh->ULHdbcs+Ppos1;                        //~va20R~
#endif                                                             //~va20R~
//                  if (*(pc+strspn(pc," "))==CALC_SUMMFLD)        //~v17hR~
                  if (*Pdatatype==CALC_STRINGDATA)                 //~v76CI~
                    span=len;   //continue getlinedata             //~v76CR~
                  else                                             //~v76CI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                    span=(int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,pc,pcd,len);//~va50I~
    #else                                                          //~va50I~
                    span=(int)UTF_umemspnc(swutf8file,pc,pcd,' ',len);//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                    span=(int)umemspnc(pc,' ',(UINT)len);          //~v17iR~
#endif                                                             //~va20I~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//                  if (span!=len && UCVEBCUTF_eqascii_b2a(swebcfile,swutf8file,*(pc+span),*(pcd+span),CALC_SUMMFLD))//~va50I~//~va79R~
                    if (span!=len && UCVEBCUTF_eqascii_b2a(swebcfile,swutf8file,handle,*(pc+span),*(pcd+span),CALC_SUMMFLD))//~va79I~
    #else                                                          //~va50I~
                    if (span!=len && UTF_eq(swutf8file,*(pc+span),*(pcd+span),CALC_SUMMFLD))//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
                    if (span!=len && *(pc+span)==CALC_SUMMFLD)     //~v17hI~
#endif                                                             //~va20R~
                    	if (ignsw)
                        {
    						if (plh==Pendplh)
        						return -1;	//eof
                    		continue;
                        }
                        else
                    	if (errsw)                                 //~v17hI~
                        	rc=4;                                  //~v17hI~
                        else                                       //~v17hI~
                    		rc=2;
                    else
                    {                                              //~v77iI~
//              		rc=tc_getlinedata(Pdatatype,plh->ULHdata+Ppos1,len,Pvalue);//~v57JR~
#ifdef UTF8UCS2                                                    //~va20R~
						pcd=plh->ULHdbcs+Ppos1;                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//              		rc=tc_getlinedata(Popt|optgd,Pdatatype,plh->ULHdata+Ppos1,pcd,len,Pvalue);//~va50I~//~va79R~
                		rc=tc_getlinedata(Popt|optgd,handle,Pdatatype,plh->ULHdata+Ppos1,pcd,len,Pvalue);//~va79R~
    #else                                                          //~va50I~
                		rc=tc_getlinedata(Popt,Pdatatype,plh->ULHdata+Ppos1,pcd,len,Pvalue);//~va20R~
    #endif                                                         //~va50I~
#else                                                              //~va20R~
                		rc=tc_getlinedata(Popt,Pdatatype,plh->ULHdata+Ppos1,len,Pvalue);//~v57JI~
#endif                                                             //~va20R~
                    }                                              //~v77iI~
                }
               }//not const                                        //~v54JI~
                break;
              }	//not tc hdr                                       //~v435I~
            }//target
        }//data
    	if (plh==Pendplh)
        	return -1;	//eof
	}
    if (!plh)
    	return -1;
    *Ppplh=plh;		//update for next call
    if (rc==4)
//  	lcmdshifterr(plh,0,0);//no exclude line highlight,no output 1st err line//~v57HR~
    	tc_setplherr(plh);//no exclude line highlight,no output 1st err line//~v57HI~
    else                                                           //~v53EI~
    {                                                              //~v53EI~
    	if (UCBITCHK(plh->ULHflag3,ULHF3ERRLINE))    //reverse     //~v53ER~
          if (plh->ULHerrctr!=Glcmd4errctr)//this time duperr(both opd err)//~v57HR~
			lcmdresetshifterr(plh,0);   	//no exclude line reset req//~v53ER~
    }                                                              //~v53EI~
    return rc;
}//tc_getplhdata
#endif                                                             //~v52hR~
#ifndef DOSDOS                                                     //~v52hR~
//****************************************************************
// get data from line
//parm2:max data len
//*ret :rc    1:time value by hhmmss(6byte) fmt
//****************************************************************
//int tc_getlinedata(int *Pdatatype,char *Pdata,int Plen,long *Pvalue)//~v57JR~
#ifdef UTF8UCS2                                                    //~va20R~
//int tc_getlinedata(int Popt,int *Pdatatype,char *Pdata,char *Pdbcs,int Plen,long *Pvalue)//~va20R~//~va70R~//~va79R~
//int tc_getlinedata(int Popt,int Phandle,int *Pdatatype,char *Pdata,char *Pdbcs,int Plen,long *Pvalue)//~va79R~//~vafkR~
int tc_getlinedata(int Popt,int Phandle,int *Pdatatype,char *Pdata,char *Pdbcs,int Plen,SLPTR *Pvalue)//~vafkI~
#else                                                              //~va20R~
int tc_getlinedata(int Popt,int *Pdatatype,char *Pdata,int Plen,long *Pvalue)//~v57JI~
#endif                                                             //~va20R~
{
    int len,rc;
    char  numwork[MAX_DATA_WIDTH+1];
    int datatype,len6sw;
    int fldlen,svlen;                                              //~va2bR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
    char  numworkebc[MAX_DATA_WIDTH+1];                            //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//****************************************
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=(Popt &GDO_EBC)!=0;                                  //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va20R~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	len=(int)UCVEBCUTF_ustrnspnc_space(swebcfile,Pdbcs!=0,Pdata,Pdbcs,Plen);//~va50I~
  #else                                                            //~va50I~
	len=(int)UTF_ustrnspn(Pdbcs!=0,Pdata,Pdbcs," ",Plen);          //~va20R~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#else                                                              //~va20R~
	len=(int)ustrnspn(Pdata," ",(UINT)Plen);
#endif                                                             //~va20R~
	Pdata+=len;
#ifdef UTF8UCS2                                                    //~va20R~
	if (Pdbcs)                                                     //~va20R~
    	Pdbcs+=len;                                                //~va20R~
#endif                                                             //~va20R~
	Plen-=len;
    svlen=Plen;                                                    //~va2bI~
#ifdef UTF8UCS2                                                    //~va20R~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    Plen-=(int)UCVEBCUTF_umemrspnc_space(swebcfile,Pdbcs!=0,Pdata,Pdbcs,Plen);	//ignore following space//~va50I~
  #else                                                            //~va50I~
    Plen-=(int)UTF_umemrspnc(Pdbcs!=0,Pdata,Pdbcs,' ',Plen);	//ignore following space//~va20R~
  #endif                                                           //~va50I~
#else                                                              //~va20R~
    Plen-=(int)umemrspnc(Pdata,' ',(UINT)Plen);	//ignore following space
#endif                                                             //~va20R~
    datatype=*Pdatatype;
  	if (Popt & GDO_EXISTCTR  //get field data for "~"(existing count calc) operation//~va2bI~
  	&&  datatype==CALC_STRINGDATA)		//'S'                      //~va2bI~
  	{                                                              //~va2bI~
    	fldlen=(Popt>>GDO_SHIFTCTR)&0xff;                          //~va2bI~
    	if (svlen>=fldlen && fldlen>Plen)                          //~va2bR~
    		Plen=fldlen;                                           //~va2bI~
  	}                                                              //~va2bI~
	Pvalue[1]=0;		//id of no under point
#ifdef UTF8UCS2                                                    //~va20R~
	if (Pdbcs                                                      //~va20R~
	&&  datatype!=CALC_STRINGDATA		//'S'                      //~va20R~
    )                                                              //~va20R~
    {                                                              //~va20R~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
  	  if (swebcfile)                                               //~va50I~
//      Plen=UCVEBC_asciilen(Pdata,Pdbcs,Plen);                    //~va50I~//~va79R~
        Plen=UCVEBC_asciilen(Phandle,Pdata,Pdbcs,Plen);            //~va79R~
      else                                                         //~va50I~
  #endif                                                           //~va50I~
        Plen=utfddasciilen(0,Pdata,Pdbcs,Plen);                    //~va20R~
        if (!Plen)                                                 //~va20R~
        	return 4;                                              //~va20R~
    }                                                              //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  	if (swebcfile)                                                 //~va50I~
        if (datatype!=CALC_STRINGDATA)      //'S'                  //~va50R~
        {                                                          //~va50R~
            len=min(Plen,MAX_DATA_WIDTH);                          //~va50R~
//          UmemcpyZ(numworkebc,Pdata,len);                        //~va50R~//+vb30R~
            UmemcpyZ(numworkebc,Pdata,(size_t)len);                //+vb30I~
//          ucvebc_b2afld(0,numworkebc,numworkebc,len); //confirmed all ascii if not "S"//~va50R~//~va79R~
            ucvebc_b2afld(0,Phandle,numworkebc,numworkebc,len); //confirmed all ascii if not "S"//~va79R~
            Pdata=numworkebc;                                      //~va50R~
        }                                                          //~va50R~
#endif                                                             //~va50I~
    switch(datatype)
    {
    case 'X':
    	len=min(Plen,MAX_DATA_WIDTH);                              //~v51nI~
    	memcpy(numwork,Pdata,(UINT)len);                           //~v51nI~
        *(numwork+len)=0;	//for getxdw(strz)                     //~v51nR~
//*confirmed string is ascii at tc_getlinedata                     //~va20R~
        if (bc_getxdw(numwork,Pvalue)==1) //valid dword fmt        //~v51nR~
            break;                                                 //~v51nI~
//*after ascii chk done                                            //~va20R~
	    len=unumlen(Pdata,UNUMLEN_HEX,Plen);
//      if (!len)                                                  //~v475R~
//      if (len!=Plen)                                             //~v51nR~
        if (len!=Plen||len>8)                                      //~v51nI~
        	return 4;
//  	len=min(len,MAX_DATA_WIDTH);                               //~v51nR~
//  	memcpy(numwork,Pdata,(UINT)len);                           //~v51nR~
//  	numwork[len]=0;                                            //~v51nR~
//      sscanf(Pdata,"%lx",Pvalue);                                //~v476R~
        sscanf(numwork,"%lx",Pvalue);                              //~v476R~
        break;
    case 'O':
//*after ascii chk done                                            //~va20R~
	    len=unumlen(Pdata,UNUMLEN_OCT,Plen);                       //~v475I~
        if (len!=Plen)                                             //~v475I~
        	return 4;                                              //~v475I~
        if (ucalc_o2l(Pdata,Pvalue,Plen))                          //~v475R~
        	return 4;
        break;
    case 'T':
    	len6sw=0;
//*after ascii chk done                                            //~va20R~
		if ((rc=ucalc_gettimevalue(Pdata,Plen,Pvalue))>1)	//up to non numeric//~v17iR~
			return 4;
        len6sw=(rc==1);
        return len6sw;
    case CALC_STRINGDATA:		//'S'                              //~v497R~
//  	Pvalue[0]=(long)Pdata;		//addr                         //~v497R~//~vafkR~
    	Pvalue[0]=(SLPTR)Pdata;		//addr                         //~vafkI~
//  	Pvalue[2]=(long)Plen; 		//len                          //~v497R~//~vafkR~
    	Pvalue[2]=(SLPTR)Plen; 		//len                          //~vafkI~
#ifdef UTF8UCS2                                                    //~va20R~
        if (Pdbcs)                                                 //~va20R~
//  		Pvalue[TC_PDBCS]=(ULONG)Pdbcs;		//idbcstbl addr of utf8 file//~va20R~//~vafkR~
    		Pvalue[TC_PDBCS]=(SLPTR)Pdbcs;		//idbcstbl addr of utf8 file//~vafkI~
#endif                                                             //~va20R~
    	break;                                                     //~v497I~
    default:        //chk num D/Z/U
//		if (!tc_getlinedatanum(Pdata,Plen,Pvalue,datatype))        //~v57JR~
		if (!tc_getlinedatanum(Popt,Pdata,Plen,Pvalue,datatype))   //~v57JI~
        {
          if (!datatype)                                           //~v474I~
        	*Pdatatype='D';
            return 0;
		}
//*after ascii chk done                                            //~va20R~
		if ((rc=ucalc_gettimevalue(Pdata,Plen,Pvalue))<=1)	//up to non numeric//~v17iR~
        {
        	*Pdatatype='T';
        	return (rc==1);
        }
        return 4;
    }//top byte
    return 0;
}//tc_getlinedata
//****************************************************************
// get decimal data from line
//*confirmed string is ascii at tc_getlinedata                     //~va20R~
//parm2:max data len
//*ret :rc
//****************************************************************
//int tc_getlinedatanum(char *Pdata,int Plen,long *Pvalue,int Pdatatype)//~v57JR~
//int tc_getlinedatanum(int Popt,char *Pdata,int Plen,long *Pvalue,int Pdatatype)//~v57JI~//~va70R~//~vafkR~
int tc_getlinedatanum(int Popt,char *Pdata,int Plen,SLPTR *Pvalue,int Pdatatype)//~vafkI~
{
    long  value;
    int len,ppos,sign;
    int ii;                                                        //~v474I~
    int rc;                                                        //~v57JI~
    int opt;                                                       //~v57JI~
    char  numwork[MAX_DATA_WIDTH+1];
    char  numwork2[MAX_DATA_WIDTH+1];                              //~v47JR~
//  char  numwork3[12];     //word max value chk work              //~v57JR~
    char *pc;
//****************************************
//ignore ","                                                       //~v474I~
//	if (Pdatatype=='Z'||Pdatatype=='z')                            //~v47KR~
  	if (Pdatatype!='X' && Pdatatype!='O' && Pdatatype!='T')        //~v47KR~
  	{                                                              //~v474I~
    	ppos=0;                                                    //~v474I~
        ii=0;                                                      //~v47JI~
    	for (len=0,pc=Pdata;len<Plen;len++,pc++)                   //~v47JR~
        {                                                          //~v474I~
        	if (!ppos && *pc==',')                                 //~v474I~
            	continue;                                          //~v474I~
        	if (*pc=='.')                                          //~v474I~
            	ppos=ii;                                           //~v474I~
            numwork2[ii++]=*pc;                                    //~v474I~
        }                                                          //~v474I~
        Pdata=numwork2;                                            //~v474I~
        Plen=ii;                                                   //~v474I~
        numwork2[ii]=0;                                            //~v51nI~
//long decimal                                                     //~v51nI~
//      if (bc_getld(numwork2,Pvalue)==1)  //valid long decimal data//~v57JR~
//      if (bc_getld(0,numwork2,Pvalue)==1)  //valid long decimal data//~v57JR~
//      rc=bc_getld(0,numwork2,Pvalue);     //valid long decimal data//~v57JI~
		if (Popt & GDO_DWUP)                                       //~v57JI~
        	opt=GETLD_DWUP;                                        //~v57JI~
        else                                                       //~v57JI~
        	opt=0;                                                 //~v57JI~
//*confirmed string is ascii at tc_getlinedata                     //~va20R~
        rc=bc_getld(opt,numwork2,Pvalue);     //valid long decimal data//~v57JI~
        if (rc==1)    //dword with or without underpoint           //~v57JR~
        	return 0;	//valid decimal                            //~v51nI~
        return rc;                                                 //~v57JR~
  	}                                                              //~v474I~
//*after ascii chk done                                            //~va20R~
    len=unumlen(Pdata,UNUMLEN_DEC|UNUMLEN_MINUS,Plen);//ret minus len if minus
    if (len<0)
    {
        len=-len;
        sign=CALC_UPMINUS;
    }
    else
        sign=0;
    if (len && len<Plen-1 && *(Pdata+len)=='.')
        ppos=len+1;
    else
    {
        if (len!=Plen)
            return 4;
        ppos=0;
    }
    len=min(Plen,MAX_DATA_WIDTH);
    if (!len)
        return 4;
    memcpy(numwork,Pdata,(UINT)len);
    numwork[len]=0;
    value=atol(numwork);
//  if (len>=10)    //may overflow                                 //~v57JR~
//  {                                                              //~v57JR~
//      sprintf(numwork3,"%ld",value);                             //~v57JR~
//      if (strcmp(numwork,numwork3))//overflow word               //~v57JR~
//      	return 4;                                              //~v57JR~
//  }                                                              //~v57JR~
//low  DWORD
    if (ppos)  //under point,+/- only
    {
        pc=numwork+ppos;
        len=(int)strlen(pc);
        if (ucalc_getunderpointdata(sign,pc,len,Pvalue))           //~v17iR~
                return 4;
    }
    Pvalue[0]=value;
    return 0;
}//tc_getlinedatanum
//**************************************************************** //~v56zI~
// update line data for ft2                                        //~v56zI~
//*rc   :0 or UALLOC_FAILED, 1 output area ovflow                  //~v56zI~
//**************************************************************** //~v56zI~
//int tc_setlinedata3(PUCLIENTWE Ppcw,int *Pparm,PULINEH Pplh,int Pundopsw,int Pdatatype,//~v56zI~//~va70R~
int tc_setlinedata3(PUCLIENTWE Ppcw,XECALCPARM *Pparm,PULINEH Pplh,int Pundopsw,int Pdatatype,//~va70I~
//					int Ppos1,int Ppos2,long *Pvalue,long *Pdataovfcnt)//~v56zI~//~vafkR~
					int Ppos1,int Ppos2,SLPTR *Pvalue,long *Pdataovfcnt)//~vafkI~
{                                                                  //~v56zI~
	int opt,rc;                                                    //~v56zI~
//****************************************                         //~v56zI~
//  opt=Pparm[PARM_OPTION];                                        //~vaz8R~
	opt=(int)Pparm[PARM_OPTION];                                   //~vaz8I~
	Sft2insmode=(opt & PARM_INS);                                  //~v56zR~
//  rc=tc_setlinedata(Ppcw,Pplh,Pundopsw,Pdatatype,Ppos1,Ppos2,Pvalue,Pdataovfcnt);//~v58vR~
    rc=tc_setlinedata(Ppcw,Pparm,Pplh,Pundopsw,Pdatatype,Ppos1,Ppos2,Pvalue,Pdataovfcnt);//~v58vI~
	Sft2insmode=0;                                                 //~v56zI~
    return rc;                                                     //~v56zI~
}//tc_setlinedata3                                                 //~v56zI~
//****************************************************************
// update line data
//   line is expanded when box width is short
//   set line err when fld ovf
//parm1:pcw may be 0 for SUM edit to work
//parm2:plh or edit out work area if pcw=0
//parm3:do undoprep
//parm4:datatype or ':' for edit summary line
//parm5:output field pos1
//parm6:output field pos2
//parm7:long value[3] or summary line when datatype=':'
//parm8:optional dataoverflow count ptr
//*rc   :0 or UALLOC_FAILED, 1 output area ovflow
//****************************************************************
//int tc_setlinedata(PUCLIENTWE Ppcw,PULINEH Pplh,int Pundopsw,int Pdatatype,//~v58vR~
//int tc_setlinedata(PUCLIENTWE Ppcw,int *Pparm,PULINEH Pplh,int Pundopsw,int Pdatatype,//~v58vI~//~va70R~
int tc_setlinedata(PUCLIENTWE Ppcw,XECALCPARM *Pparm,PULINEH Pplh,int Pundopsw,int Pdatatype,//~va70I~
//					int Ppos1,int Ppos2,long *Pvalue,long *Pdataovfcnt)//~vafkR~
					int Ppos1,int Ppos2,SLPTR *Pvalue,long *Pdataovfcnt)//~vafkI~
{
    int   width,tlen,elen,slen,len6sw,opt,rc;
    char  rval[64],*pc,*pout;
//  char  numdata[MAX_DATA_WIDTH+1],numdbcs[MAX_DATA_WIDTH+1];     //~v52fR~
    char  numdata[MAXCOLUMN+1],numdbcs[MAXCOLUMN+1];               //~v52fR~
    LONG  lv;
//  LONG  wklv[4];                                                 //~v58vI~//~vafkR~
    SLPTR wklv[4];                                                 //~vafkI~
    int   vropt,vprec;                                             //~v58vR~
    int handle;                                                    //~va79I~
//****************************************
    width=Ppos2-Ppos1;
	if (Pdatatype & CALC_TIME6)
    {
    	Pdatatype&=~CALC_TIME6;
        len6sw=CALC_TIME6;
    }
    else
        len6sw=0;
    if (Pdatatype!=CALC_SUMMLINE)
    {
    	memcpy(wklv,Pvalue,sizeof(wklv));                          //~v58vI~
        if (Pparm[PARM_OPTION] & (PARM_VPREC|PARM_ROUND))          //~v58vI~
        {                                                          //~v58vI~
            if (Pdatatype=='T'                                     //~v58vI~
            ||  Pdatatype=='U'                                     //~v58vI~
            ||  Pdatatype=='D'                                     //~v58vI~
            ||  Pdatatype=='Y'                                     //~v58vI~
            ||  Pdatatype=='Z'                                     //~v58vI~
            ||  Pdatatype=='z')                                    //~v58vI~
            {                                                      //~v58vI~
                vropt=((Pparm[PARM_OPTION] & PARM_ROUND) ? UCVRA_ROUNDUP:0);//~v58vI~
            	if (Pdatatype=='T')                                //~v58vI~
	                vropt|=UCVRA_TIME;                             //~v58vI~
//              vprec=Pparm[PARM_PRECNO];                          //~vaz8R~
                vprec=(int)Pparm[PARM_PRECNO];                     //~vaz8I~
                ucalc_vrajust(vropt|UCVRA_PRECDOWN,wklv,vprec);    //~v58vI~
            }                                                      //~v58vI~
        }                                                          //~v58vI~
//  	if (Pvalue[1]==UCALC_DWORDID)                              //~v57JR~
//  	if (Pvalue[1]>=UCALC_DWORDID)                              //~v57WR~
//  		bc_dweditnum('=',Pdatatype,Pvalue,rval);               //~v57WR~
//      else                                                       //~v57WR~
        if (Pdatatype=='T') //time value 00hhmmss calc
//          ucalc_timeedit(len6sw,rval,Pvalue);                    //~v58vR~
            ucalc_timeedit(len6sw,rval,wklv);                      //~v58vI~
        else        //not time
        if (Pdatatype=='L') //local time                           //~v51mI~
        {                                                          //~v51mI~
            bc_edittod(rval,Pvalue);                               //~v51mI~
            if (*(Pvalue+1))	//milisec or host time stamp       //~v51mR~
            	if (*(Pvalue+1)!=UCALC_DWORDID)	//!host time stamp //~v51mI~
                {                                                  //~v51mI~
                	sprintf(numdata,".%03ld",*(Pvalue+2));         //~v51mR~
                    strcat(rval,numdata);                          //~v51mI~
                }                                                  //~v51mI~
        }                                                          //~v51mI~
        else        //not time                                     //~v51mI~
        {                                                          //~v58vI~
    	if (Pvalue[1]>=UCALC_DWORDID)                              //~v57WI~
//  		bc_dweditnum('=',Pdatatype,Pvalue,rval);               //~v58vR~
    		bc_dweditnum('=',Pdatatype,wklv,rval);                 //~v58vI~
        else                                                       //~v57WI~
        {
//          lv=Pvalue[0];                                          //~vaz8R~
            lv=(LONG)Pvalue[0];	//not ptr if !CALC_SUMLINE         //~vaz8I~
            switch(Pdatatype)
            {
            case 'X':     //convert to HEX value
//              sprintf(rval,"%0*lX",min((width+1)/2*2,8),lv);     //~v473R~
                sprintf(rval,"%lX",lv);                            //~v473I~
                break;
            case 'O':     //convert to OCT value
                sprintf(rval,"%lo",lv);
                break;
            case 'U':     //convert to DEC value
//              ucalc_editnum(0,rval,Pvalue);                      //~v58vR~
                ucalc_editnum(0,rval,wklv);                        //~v58vI~
                break;
            case 'D':     //convert to DEC value
//              ucalc_editnum(CALC_ENSIGNED,rval,Pvalue);          //~v58vR~
                ucalc_editnum(CALC_ENSIGNED,rval,wklv);            //~v58vI~
                break;
            case 'Y':     //convert to DEC value                   //~v529I~
//              ucalc_editnum(CALC_ENZ,rval,Pvalue);               //~v58vR~
                ucalc_editnum(CALC_ENZ,rval,wklv);                 //~v58vI~
                break;                                             //~v529I~
            case 'Z':     //convert to DEC value
            case 'z':     //drop pre-space
                if (Pdatatype=='z')
//                  ucalc_editnum(CALC_ENSIGNED|CALC_ENZ,rval,Pvalue);//~v58vR~
                    ucalc_editnum(CALC_ENSIGNED|CALC_ENZ,rval,wklv);//~v58vI~
                else
//                  ucalc_editnum(CALC_ENSIGNED|CALC_ENSPACEZ,rval,Pvalue);//~v58vR~
                    ucalc_editnum(CALC_ENSIGNED|CALC_ENSPACEZ,rval,wklv);//~v58vI~
                tlen=(int)strlen(rval);
//*num data only                                                   //~va20R~
                elen=tlen-(int)strspn(rval," ");
                if (tlen>width && elen<=width)
                    strcpy(rval,rval+tlen-width);
                break;
            }
        }
        }//nottime                                                 //~v58vI~
		pc=rval;
    }
    else		//sub summary line
        pc=(char*)(void*)Pvalue;	//summary line data
    slen=(int)strlen(pc);

	if (!Ppcw)		//work area edit
    {
    	pout=(char*)(void*)Pplh;
    	memcpy(pout,pc,(UINT)slen);
        *(pout+slen)=0;
	}
    else			//line edit
    {
    	if (slen>width)
	    	memcpy(numdata,pc+slen-width,(UINT)width);//cut higher
        else
        {
//        if (Spadd0sw)                                            //~v473I~//~va7aR~
		  if (Pparm[PARM_OPTION]&PARM_PADD0)	//0 padding option //~va7aI~
    		memset(numdata,'0',(UINT)(width-slen));                //~v473I~
          else                                                     //~v473I~
//*a2b later                                                       //~va5cI~
    		memset(numdata,' ',(UINT)(width-slen));
	    	memcpy(numdata+width-slen,pc,(UINT)slen);//padd space
        }
      if (Sft2insmode)                                             //~v56zI~
        if (Pundopsw)                                              //~v56zI~
			opt=CHAROPBINS|CHARCAP2_UNDO|CHARCAP2_OVFCUT;          //~v56zI~
        else                                                       //~v56zI~
			opt=CHAROPBINS|CHARCAP2_OVFCUT;                        //~v56zI~
      else                                                         //~v56zI~
        if (Pundopsw)
			opt=CHAROPBREP|CHARCAP2_UNDO|CHARCAP2_OVFCUT;
        else
			opt=CHAROPBREP|CHARCAP2_OVFCUT;
    	memset(numdbcs,0,(UINT)width);                             //~v40qI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (PLH_ISEBC(Pplh))                                       //~va50I~
        {                                                          //~va50I~
        	handle=UGETPFH(Pplh)->UFHhandle;                       //~va79I~
            opt|=CHARCAP2_SRCEB;                                   //~va50I~
//          ucvebc_a2bfld(0,numdata,numdata,width);                //~va50R~//~va79R~
            ucvebc_a2bfld(0,handle,numdata,numdata,width);         //~va79I~
        }                                                          //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		if ((rc=charcap2(Ppcw,opt,numdata,numdbcs,width,Pplh,Ppos1))>1)	//block replace
        {                                                          //~v71UI~
        	if (rc==16)                                            //~v71UI~
            	uerrmsg("margin overflow by INS option;",0);       //~v71UR~
			tc_setplherr(Pplh);                                    //~v71UI~
        	return rc;
        }                                                          //~v71UI~
		if (rc==1 || slen>width)
        {
			tc_setplherr(Pplh);
            if (Pdataovfcnt)
                *Pdataovfcnt=*Pdataovfcnt+1;
    		return 1;
        }
    }
    return 0;
}//tc_setlinedata
//**************************************************************** //~v56zI~
// update line data;copy operation                                 //~v56zI~
//*rc   :0 or UALLOC_FAILED, 1 output area ovflow                  //~v56zI~
//**************************************************************** //~v56zI~
//int tc_setlinedatacopy(PUCLIENTWE Ppcw,int *Pparm,PULINEH Pplh,    //~v56zR~//~va70R~
int tc_setlinedatacopy(PUCLIENTWE Ppcw,XECALCPARM *Pparm,PULINEH Pplh,//~va70I~
//					int Ppos1,int Ppos2,long *Pvalue,long *Pdataovfcnt)//~v56zI~//~vafkR~
					int Ppos1,int Ppos2,SLPTR *Pvalue,long *Pdataovfcnt)//~vafkI~
{                                                                  //~v56zI~
    int   swidth,twidth,len,opt,popt,rc,ovfsw=0/*,repsw=0*/;       //~v56zR~
    char  *saddr;                                                  //~v56zR~
    char  strdata[MAX_DATA_WIDTHS];                                //~v56zI~
    char  strdbcs[MAX_DATA_WIDTHS];                                //~v56zI~
#ifdef UTF8UCS2                                                    //~va20R~
	PUFILEH pfh;                                                   //~va20R~
	int swutf8file;                                                //~va20R~
    char *sdbcs;                                                   //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    int addlen;                                                    //~va8bR~
//****************************************                         //~v56zI~
//  popt=Pparm[PARM_OPTION];                                       //~vaz8R~
	popt=(int)Pparm[PARM_OPTION];                                  //~vaz8I~
    twidth=Ppos2-Ppos1;                                            //~v56zI~
    saddr=(char*)Pvalue[0];                                        //~v56zI~
#ifdef UTF8UCS2                                                    //~va20R~
	pfh=UGETPFH(Pplh);                                             //~va20R~
    swutf8file=FILEUTF8MODE(pfh);                                  //~va20R~
    sdbcs=(char*)Pvalue[TC_PDBCS];                                 //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(pfh);                                      //~va50R~
    if (swutf8file||swebcfile)                                     //~va50I~
#else                                                              //~va50I~
    if (swutf8file)                                                //~va20I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	    memset(strdbcs,0,sizeof(strdbcs));                         //~va20I~
#endif                                                             //~va20R~
    swidth=(int)Pvalue[2];                                         //~v56zI~
    len=twidth-swidth;//cut higher                                 //~v56zI~
    if (len>0)//target is wide                                     //~v56zR~
    {                                                              //~v56zI~
//  	if (popt & PARM_COPYRREP)                                  //~v56zR~
//      {                                                          //~v56zR~
//          memcpy(strdata,saddr,(UINT)swidth);                    //~v56zR~
//          memset(strdata+swidth,0,(UINT)len);//clear tail        //~v56zR~
//          repsw=1;                                               //~v56zR~
//      }                                                          //~v56zR~
//      else                                                       //~v56zR~
    	if (popt & PARM_COPYRJUST)                                 //~v56zI~
        {                                                          //~v56zI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	        UCVEBC_memset_space(swebcfile,strdata,(UINT)len);//top space//~va50I~
#else                                                              //~va50I~
	        memset(strdata,' ',(UINT)len);//top space              //~v56zR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	        memcpy(strdata+len,saddr,(UINT)swidth);                //~v56zI~
#ifdef UTF8UCS2                                                    //~va20R~
  			if (sdbcs)                                             //~va20R~
            {                                                      //~va20R~
  				memcpy(strdbcs+len,sdbcs,(UINT)swidth);            //~va20R~
                if (swebcfile)                                     //~va8bI~
                {                                                  //~va8bI~
                    addlen=0;                                      //~va8bI~
                	if (*(strdbcs+len)==UDBCSCHK_DBCS1ST)          //~va8bI~
                    {                                              //~va8bI~
                    	*(strdata+len-1)=CHAR_SO;	//for charcap2,split from space prepended//~va8bI~
                        addlen=1;                                  //~va8bI~
                    }                                              //~va8bI~
                    if (len-addlen>0 && *(sdbcs+swidth-1)==UDBCSCHK_DBCS2ND)//~va8bI~
                    {                                              //~va8bI~
//                      memcpy(strdata+len-addlen-1,strdata+len-addlen,swidth+addlen);//~va8bR~//+vb30R~
                        memcpy(strdata+len-addlen-1,strdata+len-addlen,(size_t)(swidth+addlen));//+vb30I~
//                      memcpy(strdbcs+len-addlen-1,strdbcs+len-addlen,swidth+addlen);//~va8bR~//+vb30R~
                        memcpy(strdbcs+len-addlen-1,strdbcs+len-addlen,(size_t)(swidth+addlen));//+vb30I~
                        *(strdata+len+swidth-1)=CHAR_SI;           //~va8bI~
                        *(strdbcs+len+swidth-1)=0;                 //~va8bI~
                    }                                              //~va8bI~
                }                                                  //~va8bI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				XESUB_setdbcssplit_reset(swebcfile,0/*plh*/,strdata+len,strdbcs+len,swidth,' ');//~va50R~
#else                                                              //~va50I~
				setdbcssplit(strdata+len,strdbcs+len,swidth,' ');  //~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
            }                                                      //~va20R~
#endif                                                             //~va20R~
        }                                                          //~v56zI~
        else                                                       //~v56zI~
        {                                                          //~v56zI~
	        memcpy(strdata,saddr,(UINT)swidth);//cut higher        //~v56zI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	        UCVEBC_memset_space(swebcfile,strdata+swidth,(UINT)len);//tail space//~va50I~
#else                                                              //~va50I~
	        memset(strdata+swidth,' ',(UINT)len);//tail space      //~v56zR~
#endif                                                             //~va50I~
#ifdef UTF8UCS2                                                    //~va20R~
  			if (sdbcs)                                             //~va20R~
            {                                                      //~va20R~
  				memcpy(strdbcs,sdbcs,(UINT)swidth);                //~va20R~
                if (swebcfile)                                     //~va8bI~
                {                                                  //~va8bI~
                    addlen=0;                                      //~va8bI~
                	if (*(strdbcs+swidth-1)==UDBCSCHK_DBCS2ND)     //~va8bI~
                    {                                              //~va8bI~
                    	*(strdata+swidth)=CHAR_SI;	//for charcap2,split from space appended//~va8bI~
                        addlen=1;                                  //~va8bI~
                    }                                              //~va8bI~
                    if (len-addlen>0 && *sdbcs==UDBCSCHK_DBCS1ST)  //~va8bI~
                    {                                              //~va8bI~
//                      memmove(strdata+1,strdata,swidth+addlen);  //~va8bI~//+vb30R~
                        memmove(strdata+1,strdata,(size_t)(swidth+addlen));//+vb30I~
//                      memmove(strdbcs+1,strdbcs,swidth+addlen);  //~va8bI~//+vb30R~
                        memmove(strdbcs+1,strdbcs,(size_t)(swidth+addlen));//+vb30I~
                        *strdata=CHAR_SO;                          //~va8bI~
                        *strdbcs=0;                                //~va8bI~
                    }                                              //~va8bI~
                }                                                  //~va8bM~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				XESUB_setdbcssplit_reset(swebcfile,0/*plh*/,strdata,strdbcs,swidth,' ');//~va50R~
#else                                                              //~va50I~
				setdbcssplit(strdata,strdbcs,swidth,' ');          //~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
            }                                                      //~va20R~
#endif                                                             //~va20R~
        }                                                          //~v56zI~
    }                                                              //~v56zI~
    else	//cut long                                             //~v56zR~
    {                                                              //~v56zI~
    	len=-len;                                                  //~v56zI~
    	if (popt & PARM_COPYRJUST)                                 //~v56zR~
        {                                                          //~v77iI~
	        memcpy(strdata,saddr+len,(UINT)twidth);//cut head      //~v56zI~
#ifdef UTF8UCS2                                                    //~va20R~
  			if (sdbcs)                                             //~va20R~
        	{                                                      //~va20R~
  				memcpy(strdbcs,sdbcs+len,(UINT)twidth);            //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				XESUB_setdbcssplit_reset(swebcfile,0/*plh*/,strdata,strdbcs,twidth,' ');//~va50R~
#else                                                              //~va50I~
				setdbcssplit(strdata,strdbcs,twidth,' ');          //~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
        	}                                                      //~va20R~
#endif                                                             //~va20R~
        }                                                          //~va20R~
        else                                                       //~v56zI~
        {                                                          //~va20R~
	        memcpy(strdata,saddr,(UINT)twidth);//cut tail          //~v56zI~
#ifdef UTF8UCS2                                                    //~va20R~
  			if (sdbcs)                                             //~va20R~
        	{                                                      //~va20R~
  				memcpy(strdbcs,sdbcs,(UINT)twidth);                //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				XESUB_setdbcssplit_reset(swebcfile,0/*plh*/,strdata,strdbcs,twidth,' ');//~va50R~
#else                                                              //~va50I~
				setdbcssplit(strdata,strdbcs,twidth,' ');          //~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
        	}                                                      //~va20R~
#endif                                                             //~va20R~
        }                                                          //~va20R~
        if (len)                                                   //~v56zI~
			ovfsw=1;                                               //~v56zI~
    }                                                              //~v56zI~
    opt=CHARCAP2_UNDO|CHARCAP2_OVFCUT;                             //~v56zI~
//  if (repsw)                                                     //~v56zR~
//      opt|=CHAROPBREPLEN;                                        //~v56zR~
//  else                                                           //~v56zR~
    if (popt & PARM_INS)                                           //~v56zR~
        opt|=CHAROPBINS;                                           //~v56zR~
    else                                                           //~v56zI~
        opt|=CHAROPBREP;                                           //~v56zI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
 if (swebcfile)                                                    //~va50I~
    opt|=CHARCAP2_SRCEB;                                           //~va50I~
 else                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
 {                                                                 //~va50I~
#ifdef UTF8UCS2                                                    //~va20R~
//    if (sdbcs)                                                   //~va20R~
//        opt|=CHARCAP2_SRCU8;                                     //~va20R~
//    else                                                         //~va20R~
//        opt|=CHARCAP2_SRCLC;                                     //~va20R~
//*no srcu8 opt required for CALC_COPY; CALC_COPY dose not allow cap_getcalcprevinfo//~va20I~
  if (!swutf8file)                                                 //~va20R~
#endif                                                             //~va20R~
    setdbcstbl(strdata,strdbcs,twidth);                            //~v56zR~
 }//!ebc                                                           //~va50I~
    if ((rc=charcap2(Ppcw,opt,strdata,strdbcs,twidth,Pplh,Ppos1))>1) //block replace//~v56zR~
    {                                                              //~va5NI~
      if (rc==16)   //margin overflow                              //~va5NI~
        rc=1;                                                      //~va5NI~
      else                                                         //~va5NI~
        return rc;                                                 //~v56zI~
    }                                                              //~va5NI~
    if (rc==1 || ovfsw)                                            //~v56zR~
    {                                                              //~v56zI~
        tc_setplherr(Pplh);                                        //~v56zI~
        if (Pdataovfcnt)                                           //~v56zI~
            *Pdataovfcnt=*Pdataovfcnt+1;                           //~v56zI~
        return 1;                                                  //~v56zI~
    }                                                              //~v56zI~
    return 0;                                                      //~v56zI~
}//tc_setlinedatacopy                                              //~v56zI~
#endif                                                             //~v50EI~
