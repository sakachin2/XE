//*CID://+vbBwR~:                             update#=   17;       //~vbBwR~
//*************************************************************
//*xefile4.c*                                                   //~4C23R~
//**changeid,cid clear/shift                                       //~v0drR~
//*************************************************************
//vbBw:241127 label support for cid clear                          //~vbBwI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v73f:070112*(BUG)errmsg "4 line changed" is issued when rc=4 returned from filecidclear//~v43fI~
//v73e:070111*(BUG)cid shift override last cid override top cid    //~v43eI~
//v423:010918 cidpos=numfld                                        //~v423I~
//v0e9:970915 Also for mergin file with in-mergin cid like as spf file,//~v0e9I~
//            clear/shift cid in mergin.(see v06e)                 //~v0e9I~
//v0dx:970914 split fileclear from xefile4.c                       //~v0dxI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <uque.h>
#include <ustring.h>                                            //~4C19I~
#include <ufile.h>                                                 //~v0e9I~
#ifdef UTF8UCS2                                                    //~va20I~
#include <udbcschk.h>                                              //~va20R~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20I~
#include <ucvebc.h>                                                //~va50I~
#include <utrace.h>                                                //+vbBwI~
                                                                //~4C19I~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefile.h"
#include "xefile4.h"                                            //~5122I~
#include "xefile43.h"                                              //~v0dxI~
#include "xefile6.h"                                               //~v0dxI~
#include "xelcmd4.h"                                               //~v0dxI~
#include "xeundo.h"                                             //~5225I~
#include "xesub.h"                                                 //~v0bvI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xeutf2.h"                                                //~va20I~
#endif                                                             //~va20I~
//*******************************************************
//************************************************************  //~5225I~
// filecidclear                                                 //~5225I~
//*clear all line cid/shift cid in mergin                          //~v0c8R~
//*parm1:pcw                                                    //~5225R~
//*parm2:pfh                                                    //~5225I~
//*parm3:option 0:cid clear,1:cid shift                               //~v06rI~
//*return:cleared lineno or -1 if err                              //~v43fR~
//************************************************************  //~5225I~
//long filecidclear(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt)              //~v06rI~//~vbBwR~
long filecidclear(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt,PULINEH *Ppplh)//~vbBwI~
{                                                               //~5225I~
	int len,rc=0,gpos,rc2,newlen,oldpos;                           //~v0cmR~
    int lastpos;                                                   //~v0ccR~
    int errsw=0;                                                   //~v0ccI~
    int gpos0;                                                     //~v0dsR~
	int linecidlen;                                                //~v09FI~
	int cidlen;                                                    //~v0c8I~
    int len0;                                                      //~v0c8I~
    int merginsw;                                                  //~v0cjR~
    int cidinmerginsw;                                             //~v0dsI~
    int onnumcidsw;                                                //~v423I~
    int mergin;                                                    //~v0dnR~
    char *pc=0,*pcd=0;                                             //~vaf9R~
    long lineno=0;                                              //~5225I~
	PULINEH plh;                                                //~5225R~
	PULINEH plhx=0;                                                //~vaf8R~
	PULINEH plh1st=0;                                              //~v0cpI~
    UCHAR cidwk[LINECIDLENMAX];                                    //~v09FR~
    int multicidsw;                                                //~v43eI~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8file;                                                //~va20I~
    char *pcd2;                                                    //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************************                                 //~5225I~
	if (!*Ppfh->UFHcid)		//no cid defined at load time       //~5225R~
    	return 0;                                               //~5225I~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    UPCTRREQ(Ppfh);         //write at save                     //~5225I~
    merginsw=UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN);                 //~v0c8I~
    linecidlen=Ppfh->UFHcidlen;                                    //~v09FI~
    gpos0=Ppfh->UFHcidpos;                                         //~v0dsR~
    mergin=Ppfh->UFHmergin;                                        //~v0dnR~
    cidinmerginsw=(merginsw && gpos0<mergin);//cid in mergin       //~v0dsR~
    onnumcidsw=(UCBITCHK(Ppfh->UFHflag2,UFHF2MERGINCID)            //~v423I~
                  && Ppfh->UFHspfpos); //cid on numfld             //~v423I~
    if(onnumcidsw)                                                 //~v423I~
    	if (Popt!=CIDOPTCLEAR)                                     //~v423I~
        {                                                          //~v423I~
			uerrmsg("Cannot shift because cid position is fixed",  //~v423I~
					"CIDˆÊ’u‚ÍŒÅ’è‚È‚Ì‚ÅSHIFT‚Å‚«‚Ü‚¹‚ñ");         //~v423I~
//      	return 4;                                              //~v43fR~
        	return -1;                                             //~v43fR~
        }                                                          //~v423I~
    PULINEH plhs,plhe;    	                                       //+vbBwR~
    if (Ppplh[0])                                                               //~v423I~//~vbBwR~
    {                                                              //~vbBwI~
    	plhs=Ppplh[0]; plhe=Ppplh[1];                              //~vbBwI~
    }                                                              //~vbBwI~
    else                                                           //~vbBwI~
    {                                                              //~vbBwI~
		plhs=UGETQTOP(&Ppfh->UFHlineque); plhe=UGETQEND(&Ppfh->UFHlineque);//~vbBwI~
    }                                                              //~vbBwI~
    UTRACEP("%s:linenor start=%d,end=%d\n",UTT,plhs->ULHlinenor,plhe->ULHlinenor);//~vbBwI~
    int swEnd=0;                                                   //~vbBwI~
//	for (plh=UGETQTOP(&Ppfh->UFHlineque),lineno=0;plh;plh=UGETQNEXT(plh))//~5225I~//~vbBwR~
  	for (plh=plhs,lineno=0;plh;plh=UGETQNEXT(plh))                 //~vbBwI~
	{                                                           //~5225I~
    	if (swEnd)                                                 //~vbBwI~
        	break;                                                 //~vbBwI~
    	if (plh==plhe)                                             //~vbBwI~
        	swEnd=1;                                               //~vbBwI~
		if (plh->ULHtype==ULHTEXCLUDE)	//file data                //~v0ccI~
        {                                                          //~v0ccI~
        	plhx=plh;				//for err set                  //~v0ccI~
        	continue;                                              //~v0ccI~
		}                                                          //~v0ccI~
		if (plh->ULHtype!=ULHTDATA)	//file data                 //~5225I~
        	continue;                                           //~5225I~
        if (merginsw  //mergin specified,need dbcs for light mergin size//~v0c8R~
        ||  Popt!=CIDOPTCLEAR)  //shift req                        //~v0c8I~
        {                                                          //~v0c8I~
            pc=plh->ULHdata;                                       //~v0c8I~
            pcd=plh->ULHdbcs;                                      //~v0c8I~
            if (!pcd)   //not once displayed                       //~v0c8I~
            {                                                      //~v0c8I~
                rc2=filechktabdbcs(plh);//expand data len          //~v0c8I~
                if (rc2==UALLOC_FAILED)                            //~v0c8I~
                {                                                  //~v43fR~
//                  return UALLOC_FAILED;                          //~v43fR~
                    rc=4;                                          //~v43fR~
                    break;                                         //~v43fR~
                }                                                  //~v43fR~
	            pc=plh->ULHdata;                                   //~v0c8I~
                pcd=plh->ULHdbcs;                                  //~v0c8I~
            }                                                      //~v0c8I~
        }                                                          //~v0c8I~
//      len=filecidlrecl(plh,Ppfh);	//net len                      //~v0c8R~
        len0=plh->ULHlen;                                          //~v0c8I~
//      cidlen=filegetcidlen2(plh,Ppfh,&len,&oldpos,&lastpos);//topcidpos//~v0e9R~
        cidlen=filegetcidlen(plh,Ppfh,&len,&oldpos,&lastpos);//topcidpos//~v0e9I~
//        if (merginsw)                                            //~v0ckR~
//            if (Popt!=CIDOPTCLEAR)  //shift                      //~v0ckR~
//                if (mergin==filecidpos)                          //~v0ckR~
//                    if (len0>mergin)    //out of mergin exist    //~v0ckR~
//                        if (oldpos)                              //~v0ckR~
//                        {                                        //~v0ckR~
//                            lcmdshifterr(plh,plhx,0);            //~v0ckR~
//                            oldpos=0;       //cannot update out of mergin//~v0ckR~
//                            errsw=1;                             //~v0ckR~
//                        }                                        //~v0ckR~
//  	if (len!=plh->ULHlen)	//contain cid                      //~v0c8R~
    	if (oldpos)         //contain cid                          //~v0c8R~
        {                                                       //~5225I~
//          upctr=plh->ULHupctr;    //updatectr before update      //~v0cmR~
            if (Popt==CIDOPTCLEAR)                                    //~v06rI~
            {                                                         //~v06rI~
                if (!plh1st)                                       //~v0cpI~
                    plh1st=plh;                                    //~v0cpI~
//				if (rc=undoupdate(Ppcw,plh,UUHTREP),rc)	//prepare undo and update process//~v0cmR~
  				if (rc=undoupdate(Ppcw,plh,UUHTCIDCLEAR),rc)	//prepare undo and update process//~v0cmI~
    	        	break;                                            //~v06rR~
//      	    if (!upctr)	//status before undoupdate set to ULHupctr//~v0cmR~
//          		UCBITON(plh->ULHflag,ULHFCIDCLEAR);	//avoid set cid//~v0cmR~
				++lineno;                                             //~v06rR~
              if (merginsw)	//mergin specified                     //~v0c8I~
              {                                                    //~v0c8I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                UCVEBC_memset_space(swebcfile,pc+oldpos,(UINT)cidlen);//~va50I~
#else                                                              //~va50I~
                memset(pc+oldpos,' ',(UINT)cidlen);                //~v0c8R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                memset(pcd+oldpos,0,(UINT)cidlen);                 //~v0c8R~
              }                                                    //~v0c8I~
              else                                                 //~v0c8I~
				plh->ULHlen=len;	//len update undo not avail       //~v06rR~
			}                                                         //~v06rI~
            else		//shift req                                   //~v06rI~
			{                                                         //~v06rI~
//  			if (!plh->ULHdbcs)	//not once displayed           //~v0c8R~
//              {                                                  //~v0c8R~
//  				rc2=filechktabdbcs(plh);//expand data len      //~v0c8R~
//  				if (rc2==UALLOC_FAILED)                        //~v0c8R~
//      				return UALLOC_FAILED;                      //~v0c8R~
//  				if (!rc2)	//expanded	                       //~v0c8R~
//  			        len=filecidlrecl(plh,Ppfh);	//after expand tab//~v0c8R~
//  			}                                                  //~v0c8R~
//  			gpos=Scidtbl[Ppfh->UFHcidtype-1].CIDTpos;          //~v09rR~
				multicidsw=oldpos!=lastpos;                        //~v43eI~
                oldpos=lastpos; //shift last only                  //~v0ccI~
    			gpos=gpos0;                                        //~v0dsR~
//chk movable when mergin specified                                //~v0ccI~
              	if (cidinmerginsw)//cid in mergin                  //~v0dsR~
                {                                                  //~v0ccI~
                	pc=plh->ULHdata+oldpos-1;                      //~v0ccI~
                    for (len=oldpos;len>0;len--,pc--)              //~v0ccR~
                    {                                              //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
						if (len<=gpos)  //reached to shift limit   //~va20I~
                        	break;                                 //~va20I~
                		pcd2=XEUTF_PLHPC2PCD(plh,pc);              //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                    	if (UCVEBCUTF_nespace(swebcfile,swutf8file,*pc,*pcd2))//~va50I~
    #else                                                          //~va50I~
                    	if (UTF_nespace(swutf8file,*pc,*pcd2))     //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                    	if (*pc!=' ')                              //~v0ccI~
#endif                                                             //~va20I~
                        	break;                                 //~v0ccI~
                    }                                              //~va20I~
					if (len>gpos)                                  //~v0ccI~
                    {                                              //~v0ccI~
                    	lcmdshifterr(plh,plhx,0);                  //~v0ccR~
                        errsw=1;                                   //~v0ccI~
                        continue;                                  //~v0ccI~
                    }                                              //~v0ccI~
                }                                                  //~v0ccI~
                else //drop intermediate space                     //~v43eI~
                {                                                  //~v43eI~
                	if (multicidsw)                                //~v43eI~
                    {                                              //~v43eI~
//*not set multicidsw when having intermediate not space char      //~v43fI~
                		pc=plh->ULHdata+oldpos-1;                  //~v43eI~
                        for (len=oldpos;len>0;len--,pc--)          //~v43eI~
                        {                                          //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                			pcd2=XEUTF_PLHPC2PCD(plh,pc);          //~va50I~
                    	    if (UCVEBCUTF_nespace(swebcfile,swutf8file,*pc,*pcd2))//~va50I~
#else                                                              //~va50I~
                    	    if (*pc!=' ')                          //~v43eI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                        	    break;                             //~v43eI~
                        }                                          //~va50I~
                    }                                              //~v43eI~
                }                                                  //~v43eI~
				if (len>gpos)                                         //~v06rI~
					gpos=len;                                         //~v06rI~
              	if (cidinmerginsw)//cid in mergin                  //~v0dsR~
                	if (len0>gpos0+linecidlen) //data after cid    //~v0dtR~
                    	newlen=len0;                               //~v0dnR~
                    else                                           //~v0dnR~
                        newlen=gpos+linecidlen;                    //~v0dnR~
    			else                                               //~v0dnR~
                	newlen=gpos+linecidlen;                        //~v0c8I~
//  		    if (gpos+linecidlen<=MAXLINEDATA)	//not overflow //~v0bbR~
//  		    if (gpos+linecidlen<=GFILEBUFFSZ)	//not overflow //~v0c8R~
    		    if (newlen<=GFILEBUFFSZ)	//not overflow         //~v0c8I~
				{                                                     //~v06rI~
//  			    if ((newlen=gpos+linecidlen)>plh->ULHlen)	//overflow//~v0c8R~
    			    if (newlen>len0)	//overflow                 //~v0c8R~
						if (fileexpandbuff(plh,newlen)==UALLOC_FAILED)//~v06rI~
                        {                                          //~v43fR~
//  						return UALLOC_FAILED;                  //~v43fR~
		                    rc=4;                                  //~v43fR~
        		            break;                                 //~v43fR~
                		}                                          //~v43fR~
//  	            oldpos=plh->ULHlen-linecidlen;                 //~v0c8R~
                    pc=plh->ULHdata;                                  //~v06rI~
                    pcd=plh->ULHdbcs;                                 //~v06rI~
                    if (gpos!=oldpos)                                 //~v06rI~
                    {                                                 //~v06rI~
                        if (!plh1st)                               //~v0cpI~
                        	plh1st=plh;                            //~v0cpI~
//  					if (rc=undoupdate(Ppcw,plh,UUHTREP),rc)	//prepare undo and update process//~v0cmR~
    					if (rc=undoupdate(Ppcw,plh,UUHTCIDCLEAR),rc)	//prepare undo and update process//~v0cmI~
    			        	break;                                    //~v06rI~
//  	        	    if (!upctr)	//status before undoupdate set to ULHupctr//~v0cmR~
//      		    		UCBITON(plh->ULHflag,ULHFCIDCLEAR);	//avoid set cid//~v0cmR~
						++lineno;                                     //~v06rI~
	                    if (gpos<oldpos)                              //~v06rI~
                        {                                             //~v06rI~
        	            	memcpy(pc+gpos,pc+oldpos,(UINT)linecidlen);//~v09FR~
        	            	memset(pcd+gpos,0,(UINT)linecidlen);   //~v09FR~
                            if (newlen==len0)   //left shift with same len//~v0drI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	        	            	UCVEBC_memset_space(swebcfile,pc+gpos+linecidlen,(UINT)(oldpos-gpos));//~va50I~
#else                                                              //~va50I~
	        	            	memset(pc+gpos+linecidlen,' ',(UINT)(oldpos-gpos));//~v0drI~
#endif                                                             //~va50R~
						}                                             //~v06rI~
                    	else  //gpos>oldpos                           //~v06rR~
    	                {                                             //~v06rI~
        	            	memcpy(cidwk,pc+oldpos,(UINT)linecidlen);//~v09FR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//      	            	UCVEBC_memset_space(swebcfile,pc+oldpos,(UINT)gpos-oldpos);//~va50I~//~vb2DR~
        	            	UCVEBC_memset_space(swebcfile,pc+oldpos,gpos-oldpos);//~vb2DI~
#else                                                              //~va50I~
        	            	memset(pc+oldpos,' ',(UINT)gpos-oldpos);  //~v06rR~
#endif                                                             //~va50R~
//            	        	memset(pcd+oldpos,0,(UINT)gpos-oldpos);   //~v06rR~//~vb2DR~
              	        	memset(pcd+oldpos,0,(size_t)(gpos-oldpos));//~vb2DR~
        	            	memcpy(pc+gpos,cidwk,(UINT)linecidlen);//~v09FR~
            	        	memset(pcd+gpos,0,(UINT)linecidlen);   //~v09FR~
						}                                             //~v06rI~
	                	plh->ULHlen=newlen;                           //~v06rI~
                  	}//pos change                                     //~v06rI~
				}//not ocer max                                       //~v06rI~
            }//clear or shift                                         //~v06rI~
		}//cid contain                                                //~v06rR~
        if (rc)                                                 //~v04dI~
        	break;                                              //~v04dI~
	}//all line	                                                //~5225R~
    UPCTRREQ(Ppfh);         //write at save                     //~5225I~
    if (rc)                                                     //~v04dI~
        return -1;          //storage shortage                  //~v04dI~
    if (errsw)                                                     //~v0ccI~
        ubell();                                                   //~v0ccI~
    if (plh1st)                                                    //~v0cpI~
    	undocsrmove(Ppcw,plh1st);                                  //~v0cpI~
    return lineno;                                              //~5225I~
}//filecidclear                                                 //~5225I~
