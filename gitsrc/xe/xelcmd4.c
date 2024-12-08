//*CID://+vb2ER~:                             update#=  112;       //+vb2ER~
//*************************************************************
//*xelcmd4.c
//* each line cmd process
//* "//":comment out ,'S':split,'J':join, <,>,(,),[,]:shift        //~v41fR~
//*************************************************************
//vb2E:160229 LNX64 compiler warning                               //+vb2EI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va7j:100820 (BUG)non ascii char on lineno fld of ebc file is not show for lcmd "+".//~va7jI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va59:100430 shift lcmd cobol num fld(col 1-6) consideration      //~va59I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3S:100322 (BUG)"S" lcmd replace split dbcs to space,it should be avoid when split on vhex line//~va3SI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            lcmd4.c :memspn                                      //~va20I~
//v77j:080104*beep for "]" lcmd when no shift data even if space availabel//~v77jI~
//v74K:070325*left shift lcmd split dbcs.                          //~v74EI~
//v74E:070315 BOUNDS cmd support                                   //~v74EI~
//v74j:070216 (BUG)C&P del fail by join fail for margined file.    //~v74jI~
//            (by remaining oom of 1st line;delete oom for 1stline for region cut)//~v74jI~
//v74i:070216 (BUG)C&P paste to region fail by join fail for margined file.//~v74iI~
//            (ignore space before margin when join and keep oom(ignore oom for spf but)//~v74iI~
//v66f:051021 support standard mode cut & paste,assign Ctrl+v for stream insert.(split xecap.c to xecap2.c)//~v66fI~
//                     None   OpenBlock  ClosedBlock   OpenRegion ClosedRegion//~v66fI~
//            C+v    RgnIns   NoBlockErr BlockClearRep OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Ins  BlockIns NoBlockErr GetBlock+Ins  OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Rep  BlockRep NoBlockErr GetBlock+Rep  OpenRgnErr RgnDel+Ins//~v66fI~
//v57H:040612 (BUG)tc cmd;no err set if one of two opd is valid for 2 opd type//~v57HI~
//v53E:031018 TC cmd;reset previous err line                       //~v53EI~
//v531:030913 (BUG)del stopped at 7fff for large file              //~v431I~
//v47i:020302 join cmd support:"join nx/x .a .b"                   //~v47iI~
//v477:020203 lcmd "/","+" support insert to csr pos               //~v477I~
//v41w:010908 chng v41f; "]"<-->">"(keep same function as prev version)//~v41wI~
//v41f:010804 change lcmd spec;<,> reduce intermediate space to one space//~v41fI~
//            keep old <,> as [,]                                  //~v41fI~
//v419:010729 (BUG) abend when left shif on spf lineno fld         //~v419I~
//v417:010729 allow lineno fld when not protected for spf file     //~v417I~
//v17a:000501 for join linecmd,treate all split line as a line.    //~v17aI~
//v156:000403 join lcmd option to join n lines(jjl,m.n fmt(jj-jj only))//~v156I~
//v10b:981213 (BUG)charconcatline need set returncode;if return 0; //~v10bI~
//            area destroy because buff is not expanded            //~v10bI~
//v0i7:980520 line cmd split cmd('S')/join('J') support            //~v0i7I~
//v0i0:980429 lcmd skip/bandle support                             //~v0i0I~
//v0f2:971010 (BUG)"/" lcmd stop process if no shift occued at a line//~v0f2I~
//v0eM:970927 for w95 vc compile warning                           //~v0eMI~
//v0eq:970920 optionaize to update oom.default is prohibit(option=(p1))//~v0eqI~
//v0dz:970914 shift on out of mergin except spf valid line         //~v0dzI~
//v0c2:970728 simple principle.do not touch/move out of mergin     //~v0c2I~
//            if mergin not specified,last space is not dropped    //~v0c2I~
//v0bz:970728 if last is tab,expandlen over mergin cause expand err.//~v0bzI~
//            but it can be cut in mergin and set cid on normal pos.//~v0bzI~
//v0bv:970728 split file4-->file42                                 //~v0bvI~
//v0b8:970725 keep cid pos when shift left if cid shift into mergin//~v0b8I~
//v0b7:970725 filemerginchk return avail space(last data to mergin)//~v0b7I~
//v0b6:970725 do shift for excluded line when plh1 or plh2 is exclude type//~v0b6I~
//v0b5:970725 move lcmdshift to lcmd4.c                            //~v0b5I~
//v0az:970720 errline reverse display                              //~v0azI~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//           -charmaxovererr has maxlen parm                       //~v0avI~
//           -expand pre chk(split file2 to file6)                 //~v0avI~
//v0as:970719 general comment command(+)                           //~v0asI~
//v0aq:970719 add lcmd //(c comment out) --- NEW FILE              //~v0asR~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
#else
//  #define INCL_BASE
//  #include <os2.h>
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <uque.h>
#include <ustring.h>
#include <ufile.h>                                                 //~v0avI~
//#include <utrace.h>
#ifdef UTF8UCS2                                                    //~va20I~
#include <utf22.h>                                                 //~va20I~
#include <udbcschk.h>                                              //~va20I~
#endif                                                             //~va20I~
#include <ucvebc.h>                                                //~va50I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile12.h"                                              //~v0dzI~
#include "xefile2.h"                                               //~v0avR~
#include "xefile42.h"                                              //~v0bvR~
#include "xefile6.h"                                               //~v0avI~
#include "xelcmd.h"
#include "xelcmd2.h"
#define GBL_LCMD4      //for extern symbol in xelcmd4.h            //~v57HI~
#include "xelcmd4.h"
#include "xechar.h"                                                //~v0asM~
#include "xechar2.h"                                               //~v0i7I~
#include "xefcmd23.h"                                              //~v74EI~
#include "xeundo.h"
#include "xesub.h"
#include "xesub2.h"                                                //~va59I~
#include "xeerr.h"                                                 //~v0i7I~
#include "xefsub.h"                                                //~v0i7I~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xeutf2.h"                                                //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
//*******************************************************          //~v74EI~
int lcmdovfchk(PULINEH Pplh,int Ppos,int Prepeat,int Pmergin,int Poomlen,//~v0c2I~
            int *Pnewrepeat,int *Pmovelen);                        //~v0c2I~
int lcmdrshift(PULINEH Pplh,int Ppos,int Pshift,int Plen,int Poomlen);//~v0c2I~
int lcmdexcerr(void);                                              //~v0i7I~
int lcmdresetxlineno(PULINEH Pplh);                                //~v47iI~
int lcmdbndsadjust_l(PULINEH Pplh,int Pbndsoffs1,int Pbndsoffs2,int Pmergin,int Ppos,int *Ppoomlen);//~v74ER~
int lcmdbndsadjust_r(PULINEH Pplh,int Pbndsoffs1,int Pbndsoffs2,int *Ppmergin,int Ppos,int *Ppoomlen);//~v74EI~
//**************************************************************** //~v0i0I~
//!lcmdshiftbs                                                     //~v0i0I~
//*parm1:pcw                                                       //~v0i0I~
//*parm2:start ULINEH                                              //~v0i0I~
//*parm3:end   ULINEH                                              //~v0i0I~
//*parm4:repaet count                                              //~v0i0I~
//*parm5:plc                                                       //~v0i0I~
//*parm6:bandle                                                    //~v0i0I~
//*parm7:skip                                                      //~v0i0I~
//*rc   :0 or UALLOC_FAILED                                        //~v0i0I~
//**************************************************************** //~v0i0I~
int lcmdshiftbs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,UCHAR Pcmd,//~v0i0I~
				int Pbandle,int Pskip)                             //~v0i0I~
{                                                                  //~v0i0I~
	PULINEH plh,plh2,plh3=0,plhstop;                                 //~v0i0I~//~vaf9R~
	int ii,rc;                                                     //~v0i0R~
//*****************                                                //~v0i0I~
    plhstop=Pplh2;                                                 //~v0i0R~
    plh=Pplh1;                                                     //~v0i0I~
    for (ii=0;;ii++)	//repeat is not line count but shift count                                                       //~v0i0R~
    {                                                              //~v0i0I~
        if (lcmdgetplhrange2(&plh,&plh2,plhstop,Pbandle)==8)    //get next line after del//~v0i0I~
        {                                                          //~v57HI~
            if (ii)         //start line reached to eol            //~v0i0I~
                break;                                             //~v0i0I~
            else            //first time eol                       //~v0i0I~
                return 8;                                          //~v0i0I~
        }                                                          //~v57HI~
        if (plh2!=plhstop)                                         //~v0i0I~
	        lcmdgetplhrange2(&plh2,&plh3,plhstop,Pskip+1);//next del start//~v0i0R~
		rc=lcmdshift(Ppcw,plh,plh2,Prepeat,Pcmd);                  //~v0i0R~
        if (rc)                                                    //~v0i0I~
    	        return rc;                                         //~v0i0I~
        if (plh2==plhstop || plh3==plhstop)                        //~v0i0R~
            break;                                                 //~v0i0I~
	    lcmdgetplhrange2(&plh3,&plh,plhstop,2);//next del start    //~v0i0I~
    }                                                              //~v0i0I~
    return 0;                                                      //~v0i0I~
}//lcmdshiftbs                                                     //~v0i0I~
//****************************************************************
// lcmdshift
// line shift
//*rc   :0 or UALLOC_FAILED                                     //~v04dR~
//****************************************************************
int lcmdshift(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,UCHAR Pcmd)
{
    PUFILEH pfh;                                                   //~v0avI~
	PULINEH plh;                                                   //~v0b6R~
//	PULINEH plhx,plherr=0;                                         //~v0azR~//~vaf8R~
  	PULINEH plhx=0,plherr=0;                                       //~vaf8I~
//  int offset,len,i,bellsw=0,pos;                              //~5521R~//~vaf9R~
    int offset,len=0,i,bellsw=0,pos;                               //~vaf9I~
    int excludesw;                                                 //~v0b6I~
	UCHAR  *pc,*pc2;                                               //~v41fR~
	UCHAR  *pcd,*pcd2;                                             //~v41fR~
    int mergin;                                                    //~v0c2R~
    int oomlen,len2;                                               //~v0c2R~
    int repeat;                                                    //~v0c2I~
//  int spfsw2;                                                    //~v0dzI~
    int bndsoffs1,bndsoffs2;                                       //~v74EI~
#ifdef UTF8UCS2                                                    //~va20R~
	int swutf8file,dbcsid,ch;                                      //~va20R~
	UCHAR  *pc0,*pcd0;                                             //~va20I~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************
//#ifdef DOS                                                       //~v07vR~
//	dosdump("entry to lcmd shift");                                //~v07vR~
//#endif                                                           //~v07vR~
    pfh=UGETPFH(Pplh1);                                            //~v0avI~
#ifdef UTF8UCS2                                                    //~va20R~
	swutf8file=FILEUTF8MODE(pfh);                                  //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    mergin=pfh->UFHmergin;                                         //~v0avI~
    bndsoffs1=pfh->UFHbndscol1-1;                                  //~v74EI~
    bndsoffs2=pfh->UFHbndscol2;                                    //~v74EI~
	if (CSRONFILEDATA(Ppcw))			//csr on file data line //~5521I~
    	pos=Ppcw->UCWrcsrx-Ppcw->UCWlinenosz+((PUFILEC)Ppcw->UCWpfc)->UFCleft;//target pos//~v069R~
    else                                                        //~5521I~
    	pos=0;                                                  //~5521I~
    BNDS_ADJUSTPOS(bndsoffs1,bndsoffs2,pos);	//update pos by bnds parm//~v74EI~
	if (UCBITCHK(pfh->UFHflag5,UFHF5COB)  //cob including cob2(1-6 is not forced to be numeric)//~va59R~
    &&  bndsoffs1<0                                                //~va59R~
    &&  !pos                                                       //~va59I~
    )                                                              //~va59I~
        pos=SPFCOBNUMFLDLEN;                                       //~va59R~
    if (pos>=mergin)	//no data after cursor                     //~v0avI~
//    if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK)     //valid spf file//~v417R~
//    || !UCBITCHK(pfh->UFHflag3,UFHF3OOMNOPROT))   //valid spf file//~v417R~
      if (!UCBITCHK(pfh->UFHflag3,UFHF3OOMNOPROT))   //valid spf file//~v417I~
//      return charmerginerr(mergin);                              //~v417R~
  		return errprotected();                                     //~v417I~
//  spfsw2=UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR);   //~v0dzI~
//  plh2n=UGETQNEXT(Pplh2);                                        //~v0b6R~
	excludesw=0;                                                   //~v0b6I~
//	for (plh=Pplh1;plh!=plh2n;plh=UGETQNEXT(plh))                  //~v0b6R~
  	for (plh=Pplh1;plh;plh=UGETQNEXT(plh))                         //~v0b6I~
	{
		if (excludesw)                                             //~v0b6I~
			if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))            //~v0b6I~
				break;                                             //~v0b6I~
//  	plht=UGETQNEXT(plh);			//@@@@                     //~v07vR~
//      if (!FP_OFF(plh))     //@@@@                               //~v07vR~
//      	break;		//@@@@                                     //~v07vR~
		if (plh->ULHtype==ULHTEXCLUDE)		//no delete when hdr line//~v0azI~
        	plhx=plh;                                              //~v0azI~
//  	if (plh->ULHtype!=ULHTDATA)                                //~v0b6R~
//  		continue;                                              //~v0b6R~
      if (plh->ULHtype==ULHTDATA)                                  //~v0b6I~
      {                                                            //~v0b6I~
		if (!plh->ULHdbcs)	//not once displayed                //~5103I~
			if (filechktabdbcs(plh)==UALLOC_FAILED)	//create dbcstbl//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
	    oomlen=filegetoomlen(pfh,plh);  //out of mergin len        //~v0c2I~
        if (oomlen)	//data on out of mergin for mergined file      //~v0dzI~
        	if (pos>=mergin)                                       //~v0dzI~
//          	if (!spfsw2 || !fileisvalidspfline(pfh,plh,0))     //~v419R~
                {                                                  //~v0dzI~
            		oomlen=0;	//normal left shift for oom        //~v0dzI~
                    mergin=MAXLINEDATA;         //shft right up to //~v0dzI~
                }                                                  //~v0dzI~
#ifdef UTF8UCS2                                                    //~va20I~
		pc0=plh->ULHdata;                                          //~va20I~
		pcd0=plh->ULHdbcs;                                         //~va20I~
#endif                                                             //~va20I~
		switch(Pcmd)
		{
		case '(':
//*shift and reduce full record(cut headding part) (move right of csr pos)//~v74ER~
//  		if ((len=plh->ULHlen-pos)<=0) 	//len after csr        //~v0c2R~
//  		if (oomlen)                                            //~v0c2I~,//~v74ER~
//              len=mergin-pos;                                    //~v0c2I~,//~v74ER~
//          else                                                   //~v0c2I~,//~v74ER~
//              len=plh->ULHlen-pos;                               //~v0c2I~,//~v74ER~
			len=lcmdbndsadjust_l(plh,bndsoffs1,bndsoffs2,mergin,pos,&oomlen);//~v74ER~
    		if (len<=0) 	//len after csr                        //~v0c2I~
				break;                      //csr is right of eol//~5521R~
			if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)//prep undo for data line rep//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
			pc=plh->ULHdata+pos;                                   //~v0c2M~
#ifdef UTF8UCS2                                                    //~va20I~
			pcd=plh->ULHdbcs+pos;                                  //~va20I~
#endif                                                             //~va20I~
			for (i=0;i<len && i<Prepeat;i++)
            {                                                      //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
               ch=*pc++;                                           //~va20I~
               dbcsid=*pcd++;                                      //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
               if (UCVEBCUTF_nespace(swebcfile,swutf8file,ch,dbcsid))//~va50I~
	#else                                                          //~va50I~
               if (UTF_nespace(swutf8file,ch,dbcsid))              //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
				if (*pc++!=' ')
#endif                                                             //~va20I~
					break;
            }                                                      //~va20I~
			if (i<Prepeat)
				bellsw=1;                                       //~5103R~
            filetabclear(plh);//tab clear                          //~v0b8I~
//        if (!filecidshiftleft(pfh,plh,pos,Prepeat))	//no cid shifted//~v0c2R~
//        {                                                        //~v0c2R~
//  		plh->ULHlen-=(offset=min(Prepeat,len));	//cut len      //~v0c2R~
    		offset=min(Prepeat,len);	//cut len                  //~v0c2I~
            if (!oomlen)                                           //~v0c2I~
				plh->ULHlen-=offset;	//new len                  //~v0c2I~
    		if ((len-=offset)>0)				//move len         //~v0b8R~
			{
            	                                                   //~v74EI~
		    	if (oomlen)                                        //~v74KR~
		    		lcmddbcssplit(plh,pos+offset+len);//"(",dbcs split clear after shift//~v74KR~
				memcpy(plh->ULHdata+pos,plh->ULHdata+pos+offset,(UINT)len);//~5521R~
				memcpy(plh->ULHdbcs+pos,plh->ULHdbcs+pos+offset,(UINT)len);//~5521R~
//  			if (filetabshift(1,plh))//expand tab,left cut      //~v0b3R~
//              	return UALLOC_FAILED;                          //~v0b3R~
			}
    		lcmddbcssplit(plh,pos);//"(",dbcs split clear after shift//~v0c2I~
            if (oomlen && offset)                                  //~v0c2I~
			{                                                      //~v0c2I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				UCVEBC_memset_space(swebcfile,plh->ULHdata+pos+len,(UINT)offset);//~va50I~
#else                                                              //~va50I~
				memset(plh->ULHdata+pos+len,' ',(UINT)offset);     //~v0c2I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
				memset(plh->ULHdbcs+pos+len,0,(UINT)offset);       //~v0c2I~
			}                                                      //~v0c2I~
//        }//no cid shift occured                                  //~v0c2R~
			break;
//  	case '<':                                                  //~v41fR~
//  	case '[':                                                  //~v41wR~
    	case '<':                                                  //~v41wI~
//*cut preceding space(length not change) and add trailing space
//          if ((len=plh->ULHlen-pos)<=0)//no data on the right of csr//~v0c2R~
//  		if (oomlen)                                            //~v74ER~
//              len=mergin-pos;                                    //~v0c2I~,//~v74ER~
//          else                                                   //~v0c2I~,//~v74ER~
//              len=plh->ULHlen-pos;                               //~v0c2I~,//~v74ER~
			len=lcmdbndsadjust_l(plh,bndsoffs1,bndsoffs2,mergin,pos,&oomlen);//~v74ER~
    		if (len<=0) 	//len after csr                        //~v0c2I~
            	break;                                          //~5521I~
			pc=plh->ULHdata+pos;                                //~5521R~
#ifdef UTF8UCS2                                                    //~va20I~
			pcd=plh->ULHdbcs+pos;                                  //~va20I~
#endif                                                             //~va20I~
			for (i=0;i<len && i<Prepeat;i++)
            {                                                      //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
               ch=*pc++;                                           //~va20I~
               dbcsid=*pcd++;                                      //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
               if (UCVEBCUTF_nespace(swebcfile,swutf8file,ch,dbcsid))//~va50I~
    #else                                                          //~va50I~
               if (UTF_nespace(swutf8file,ch,dbcsid))              //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
				if (*pc++!=' ')
#endif                                                             //~va20I~
					break;
            }                                                      //~va20I~
			if (i<Prepeat && i<len)	//non space data            //~5521R~
            {                                                      //~v0azI~
                if (!i)                                            //~v0b7I~
                {                                                  //~v0b7I~
	                lcmdshifterr(plh,plhx,&plherr);                //~v0b7R~
                    break;                                         //~v0b7I~
                }                                                  //~v0b7I~
            }                                                      //~v0azI~
//  		if (!(offset=i))	//preceding space len              //~v0b7R~
//  			break;                                             //~v0b7R~
    		offset=i;//preceding space len                         //~v0b7I~
//          if (!(len-=offset))	//len to move                      //~v08pR~
//          	break;          //right of csr is all space        //~v08pR~
            len-=offset; 	//len to move                          //~v08pI~
			if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)//prep for data line undo//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
   			filetabclear(plh);//tab clear                          //~v0b8M~
			if (i<Prepeat && i<len)	//non space data               //~v0b7I~
                lcmdshifterr(plh,plhx,&plherr);                    //~v0b7I~
//        if (!filecidshiftleft(pfh,plh,pos,offset))	//no cid shifted//~v0c2R~
//        {                                                        //~v0c2R~
//  		if ((plh->ULHlen-=offset)>0 && len)                    //~v0c2R~
            if (!oomlen)                                           //~v0c2I~
				plh->ULHlen-=offset;	//new len                  //~v0c2I~
			pc=plh->ULHdata+pos;                                   //~v0c2M~
			pcd=plh->ULHdbcs+pos;                                  //~v0c2I~
    		if (plh->ULHlen  && len)                               //~v0c2I~
            {                                                      //~v08pI~
			    if (oomlen)                                        //~v74KR~
		        	lcmddbcssplit(plh,pos+offset+len);//"(",dbcs split clear after shift//~v74KR~
			memcpy(pc,pc+offset,(UINT)len);
//  		memset(pc+len,' ',(UINT)offset);                       //~v08pR~
			memcpy(pcd,pcd+offset,(UINT)len);                      //~v0c2R~
//  		memset(pc+len,0,(UINT)offset);                         //~v08pR~
//  		if (filetabshift(1,plh))	//expand tab,left cut      //~v0b3R~
//           	return UALLOC_FAILED;                              //~v0b3R~
			}//plhlen>0                                            //~v08pI~
            if (oomlen && offset)                                  //~v0c2I~
			{                                                      //~v0c2I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				UCVEBC_memset_space(swebcfile,pc+len,(UINT)offset);//~va50I~
#else                                                              //~va50I~
				memset(pc+len,' ',(UINT)offset);                   //~v0c2I~
#endif                                                             //~va50I~
				memset(pcd+len,0,(UINT)offset);                    //~v0c2I~
			}                                                      //~v0c2I~
//        }//no cid shift occured                                  //~v0c2R~
			break;
//  	case '<':                                                  //~v41wR~
    	case '[':                                                  //~v41wI~
//*reduce continuous space to one space                            //~v41fI~
//  		if (oomlen)     //csr in margin                        //~v41fR~,//~v74ER~
//              len=mergin-pos;                                    //~v41fI~,//~v74ER~
//          else            //no margin or csr is on margin        //~v41fR~,//~v74ER~
//              len=plh->ULHlen-pos;                               //~v41fI~,//~v74ER~
			len=lcmdbndsadjust_l(plh,bndsoffs1,bndsoffs2,mergin,pos,&oomlen);//~v74ER~
    		if (len<=0) 	//len after csr                        //~v41fI~
            	break;                                             //~v41fI~
			pc=plh->ULHdata+pos;                                   //~v41fI~
//count deletable space                                            //~v41fI~
            for (offset=0,i=0;i<len;i++,pc++)                      //~v41fR~
            {                                                      //~v41fR~
#ifdef UTF8UCS2                                                    //~va20I~
				pcd=XEUTF_PC2PCD(pcd0,pc,pc0);                     //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                if (UCVEBCUTF_nespace(swebcfile,swutf8file,*pc,*pcd))//~va50I~
    #else                                                          //~va50I~
                if (UTF_nespace(swutf8file,*pc,*pcd))              //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                if (*pc!=' ')                                      //~v41fR~
#endif                                                             //~va20I~
                    continue;                                      //~v41fR~
                i++;                                               //~v41fR~
                pc++;                                              //~v41fR~
#ifdef UTF8UCS2                                                    //~va20I~
				pcd=XEUTF_PC2PCD(pcd0,pc,pc0);                     //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                if (i<len && UCVEBCUTF_eqspace(swebcfile,swutf8file,*pc,*pcd))//~va50I~
    #else                                                          //~va50I~
                if (i<len && UTF_eqspace(swutf8file,*pc,*pcd))     //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                if (i<len && *pc==' ')                             //~v41fI~
#endif                                                             //~va20I~
                {                                                  //~v41fI~
                    offset=1;   //drop space occur                 //~v41fR~
                    break;                                         //~v41fI~
                }                                                  //~v41fI~
            }                                                      //~v41fI~
            if (!offset)		//no space to be delete            //~v41fR~
            {                                                      //~v41fI~
                lcmdshifterr(plh,plhx,&plherr);                    //~v41fI~
            	break;                                             //~v41fR~
            }                                                      //~v41fI~
			if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)//prep for data line undo//~v41fI~
            	return UALLOC_FAILED;                              //~v41fI~
   			filetabclear(plh);//tab clear                          //~v41fI~
//drop space                                                       //~v41fI~
	    	if (oomlen)                                            //~v74KR~
	        	lcmddbcssplit(plh,plh->ULHlen-oomlen);//"(",dbcs split clear after shift//~v74KR~
			pc2=pc=plh->ULHdata+pos;                               //~v41fR~
			pcd2=pcd=plh->ULHdbcs+pos;                             //~v41fR~
            for (offset=0,i=0;i<len;)                              //~v41fR~
            {                                                      //~v41fI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                if (UCVEBCUTF_nespace(swebcfile,swutf8file,*pc,*pcd))//~va50I~
    #else                                                          //~va50I~
                if (UTF_nespace(swutf8file,*pc,*pcd))              //~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
                if (*pc!=' ')                                      //~v41fI~
#endif                                                             //~va20I~
                {                                                  //~v41fI~
                	*pc2++=*pc++;                                  //~v41fR~
                	*pcd2++=*pcd++;                                //~v41fR~
                    i++;                                           //~v41fR~
                	continue;                                      //~v41fI~
                }                                                  //~v41fI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                *pc2++=UCVEBC_CHAR_SPACE(swebcfile);               //~va50R~
#else                                                              //~va50I~
                *pc2++=' ';                                        //~v41fR~
#endif                                                             //~va50I~
                *pcd2++=0;                                         //~v41fI~
                pc++;                                              //~v41fI~
                pcd++;                                             //~v41fI~
                i++;                                               //~v41fM~
                for (;i<len && offset<Prepeat;i++,pc++,pcd++)      //~v41fR~
                {                                                  //~v41fI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                	if (UCVEBCUTF_nespace(swebcfile,swutf8file,*pc,*pcd))//~va50I~
    #else                                                          //~va50I~
                	if (UTF_nespace(swutf8file,*pc,*pcd))          //~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
                    if (*pc!=' ')                                  //~v41fI~
#endif                                                             //~va20I~
                        break;                                     //~v41fI~
                    offset++;                                      //~v41fR~
                }                                                  //~v41fI~
                if (offset>=Prepeat)                               //~v41fR~
                    break;                                         //~v41fI~
            }                                                      //~v41fI~
			if (offset<Prepeat)	//non space data                   //~v41fI~
                lcmdshifterr(plh,plhx,&plherr);                    //~v41fM~
            len-=i;                                                //~v41fR~
            if (len)                                               //~v41fI~
            {                                                      //~v41fI~
				memcpy(pc2,pc,(UINT)len);                          //~v41fR~
				memcpy(pcd2,pcd,(UINT)len);                        //~v41fR~
			}//plhlen>0                                            //~v41fI~
            if (oomlen)	//cut len                                  //~v41fR~
			{                                                      //~v41fI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				UCVEBC_memset_space(swebcfile,pc2+len,(UINT)offset);//~va50I~
#else                                                              //~va50I~
				memset(pc2+len,' ',(UINT)offset);                  //~v41fR~
#endif                                                             //~va50I~
				memset(pcd2+len,0,(UINT)offset);                   //~v41fR~
			}                                                      //~v41fI~
            else                                                   //~v41fI~
				plh->ULHlen-=offset;	//new len                  //~v41fM~
          	break;                                                 //~v41fR~
		case ')':
//*shift and expand full record and cut when over max record size(move right of csr pos)//~v74ER~
            if (pos>=plh->ULHlen)	//no data after cursor         //~v0avR~
               	break;                                             //~v0avR~
			lcmdbndsadjust_r(plh,bndsoffs1,bndsoffs2,&mergin,pos,&oomlen);//~v74EI~
//  		if ((len=plh->ULHlen+Prepeat)>MAXLINEDATA)             //~v0avR~
//  		{                                                      //~v0avR~
//  			bellsw=1;                                          //~v0avR~
//  			len=MAXLINEDATA;                                   //~v0avR~
//  		}                                                      //~v0avR~
			if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)//prep und for data line//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
   			filetabclear(plh);//tab clear                          //~v0c2M~
		  if (!oomlen)                                             //~v0c2R~
          {                                                        //~v0c2I~
  		  	len=min(plh->ULHlen+Prepeat,mergin);//expandlen        //~v0c2I~
			if (len>plh->ULHbufflen)	//len expand
				if (fileexpandbuff(plh,len)==UALLOC_FAILED)		//buff expand//~v04dR~
		         	return UALLOC_FAILED;                       //~v04dI~
          }                                                        //~v0c2I~
//  		offset=min(MAXLINEDATA-pos,Prepeat);                   //~v0avR~
//  		offset=Prepeat;                                        //~v0c2R~
    		offset=min(mergin-pos,Prepeat);                        //~v0c2R~
//  		len=min(plh->ULHlen,MAXLINEDATA-offset)-pos;//move len //~v0avR~
			pc=plh->ULHdata;                                       //~v0c2I~
            if (oomlen)                                            //~v0c2I~
            {                                                      //~v0c2I~
                len=mergin-offset-pos;  //movelen                  //~v0c2R~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                bellsw=((int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,pc+mergin-offset,plh->ULHdbcs+mergin-offset,offset)!=offset);//~va50I~
    #else                                                          //~va50I~
                bellsw=((int)UTF_umemspnc(swutf8file,pc+mergin-offset,plh->ULHdbcs+mergin-offset,' ',offset)!=offset);//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
                bellsw=((int)umemspnc(pc+mergin-offset,' ',(UINT)offset)!=offset);//~v0eMR~
#endif                                                             //~va20R~
            }                                                      //~v0c2I~
            else                                                   //~v0c2I~
            {                                                      //~v0c2I~
    			len2=plh->ULHlen+offset-len;//cutlen               //~v0c2I~
                len=plh->ULHlen-pos;	//move len                 //~v0c2I~
                if (len2>0)                                        //~v0c2I~
                {                                                  //~v0c2I~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//                	bellsw=((int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,pc+plh->ULHlen-len2,plh->ULHdbcs+plh->ULHlen-len2,(UINT)len2)!=len2);//~va50R~//~vb2DR~
                  	bellsw=((int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,pc+plh->ULHlen-len2,plh->ULHdbcs+plh->ULHlen-len2,len2)!=len2);//~vb2DI~
    #else                                                          //~va50I~
                	bellsw=((int)UTF_umemspnc(swutf8file,pc+plh->ULHlen-len2,plh->ULHdbcs+plh->ULHlen-len2,' ',(UINT)len2)!=len2);//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
                	bellsw=((int)umemspnc(pc+plh->ULHlen-len2,' ',(UINT)len2)!=len2);//~v0eMR~
#endif                                                             //~va20R~
                    len-=len2;                                     //~v0c2I~
				}                                                  //~v0c2I~
            }                                                      //~v0c2I~
            lcmddbcssplit(plh,pos);//dbcs split clear befor shift  //~v0c2M~
			pc=plh->ULHdata+pos;                                //~5521R~
			memmove(pc+offset,pc,(UINT)len);
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
			UCVEBC_memset_space(swebcfile,pc,(UINT)offset);        //~va50R~
#else                                                              //~va50I~
			memset(pc,' ',(UINT)offset);
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                                                                   //~v0c2I~
    	  if (!oomlen)                                             //~v0c2I~
			plh->ULHlen=pos+offset+len;		//new len           //~5521R~
                                                                   //~v0c2I~
			pcd=plh->ULHdbcs+pos;                                  //~v0c2R~
			memmove(pcd+offset,pcd,(UINT)len);                     //~v0c2R~
			memset(pcd,0,(UINT)offset);                            //~v0c2R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            xesub_setdbcssplit(swebcfile,0/*plh*/,pc,pcd,offset+len,' ');	//righr end//~va59I~
#else                                                              //~va59I~
            setdbcssplit(pc,pcd,offset+len,' ');	//righr end    //~v0c2I~
#endif                                                             //~va50I~//~va59M~
//  		rc=filecidshift(pfh,plh,1); //back cid pos unconditional//~v0c2R~
//  		if (lcmdtabshift(0,plh))	//expand tab,right cut     //~v0avR~
//           	return UALLOC_FAILED;                              //~v0b3R~
//          if (rc)        		//cid shift back occued            //~v0c2R~
//  			bellsw=1;                                          //~v0c2R~
			break;
//  	case '>':                                                  //~v41fR~
//  	case ']':                                                  //~v41wR~
    	case '>':                                                  //~v41wI~
//  		if ((len=plh->ULHlen-pos)<=0)	//data on the right of csr//~v0c2R~
//*overflow chk                                                    //~v0c2M~
//            if (oomlen)                                            //~v0c2//~v0c2R~
//                len=mergin-pos;                                    //~v0c2//~v0c2R~
//            else                                                   //~v0c2//~v0c2R~
//                len=plh->ULHlen-pos;                               //~v0c2//~v0c2R~
//            if (len<=0) //data on the right of csr                 //~v0c2//~v0c2R~
//                break;                  //no data on the right of csr//~5521//~v0c2R~
//            pc=plh->ULHdata+pos+len-1;                          //~5521//~v0c2R~
//            for (i=0;i<Prepeat && i<len;i+                       //~v0c2R~
//                if (*pc--!='                                     //~v0c2R~
//                    brea                                         //~v0c2R~
//            if (i==len) //all space                             //~5521//~v0c2R~
//                break;                                          //~5521//~v0c2R~
//            len-=i;     //move len                                 //+v0c2//~v0c2R~
//            len2=0      //missed len                               //+v0c2//~v0c2R~
//            if (i<Prepeat)                                         //+v0c2//~v0c2R~
//            {                                                      //+v0c2//~v0c2R~
//                if (oomlen)                                        //+v0c2//~v0c2R~
//                {                                                  //+v0c2//~v0c2R~
//                    bellsw=1;                                      //+v0c2//~v0c2R~
//                    len2=Prepeat-i;     //missed len               //+v0c2//~v0c2R~
//                    Prepeat=i;                                     //+v0c2//~v0c2R~
//                }                                                  //+v0c2//~v0c2R~
//                else                                               //+v0c2//~v0c2R~
//                {                                                  //+v0c2//~v0c2R~
//                    len2=Prepeat-(mergin-(pos+len));               //+v0c2//~v0c2R~
//                    if (len2>0)                                    //+v0c2//~v0c2R~
//                    {                                              //+v0c2//~v0c2R~
//                        Prepeat-=len2;                             //+v0c2//~v0c2R~
//                        bellsw=1;                                  //+v0c2//~v0c2R~
//                    }                                              //+v0c2//~v0c2R~
//                    else                                           //+v0c2//~v0c2R~
//                        len2=0;                                    //+v0c2//~v0c2R~
//                 }                                                 //+v0c2//~v0c2R~
//            }                                                      //+v0c2//~v0c2R~
			lcmdbndsadjust_r(plh,bndsoffs1,bndsoffs2,&mergin,pos,&oomlen);//~v74EI~
			if (lcmdovfchk(plh,pos,Prepeat,mergin,oomlen,&repeat,&len))//~v0c2I~
            	break;                                             //~v0c2I~
            if (!repeat)     //no space to move                   //+v0c2//~v0c2R~
            {                                                      //+v0c2//~v0c2R~
                lcmdshifterr(plh,plhx,&plherr);                    //+v0c2//~v0c2R~
                break;      //skip process                         //+v0c2//~v0c2R~
            }                                                      //+v0c2//~v0c2R~
			if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)       //~v07vR~
            	return UALLOC_FAILED;                           //~v04dI~
            if (repeat!=Prepeat)	//overflow                     //~v0c2R~
                lcmdshifterr(plh,plhx,&plherr);	//after undoupdate //~v0b7I~
//            Prepeat=repeat;                                        //+v0c2//~v0c2R~
//            filetabclear(plh);//tab clear                          //~v0c2//~v0c2R~
//            lcmddbcssplit(plh,pos);//dbcs split clear befor shift  //~v0av//~v0c2R~
////          if (i==Prepeat)                                        //~v0c2//~v0c2R~
////          {                                                      //~v0c2//~v0c2R~
////              offset=Prepeat;                                    //~v0c2//~v0c2R~
////              if ((len-=offset)<0)                               //~v0c2//~v0c2R~
////                  len=0;                                         //~v0c2//~v0c2R~
////          }                                                      //~v0c2//~v0c2R~
////          else                                                   //~v0c2//~v0c2R~
////          {                                                      //~v0c2//~v0c2R~
////              len-=i;             //len except trailing space    //~v0c2//~v0c2R~
////              if (Prepeat>MAXLINEDATA-len-pos)    //no shift space//~v0av//~v0c2R~
////              {                                                  //~v0av//~v0c2R~
////                  bellsw=1;                                      //~v0av//~v0c2R~
////                  if (!(offset=MAXLINEDATA-len-pos))             //~v0av//~v0c2R~
////                      break;      //no movement                  //~v0av//~v0c2R~
////              }                                                  //~v0av//~v0c2R~
////              else                                               //~v0av//~v0c2R~
//                    offset=Prepeat; //full shift                //~5521//~v0c2R~
//              if (!oomlen)  //no mergin                            //~v0c2//~v0c2R~
//              {                                                    //~v0c2//~v0c2R~
//                len2=len;   //move len save                        //~v0c2//~v0c2R~
//                len=offset+len+pos;                             //~5521//~v0c2R~
//                if (len>plh->ULHbufflen)                           //~v0be//~v0c2R~
//                {                                                  //~v0be//~v0c2R~
//                    if (fileexpandbuff(plh,len)==UALLOC_FAILED)    //~v0be//~v0c2R~
//                        return UALLOC_FAILED;                      //~v0be//~v0c2R~
//                }                                                  //~v0be//~v0c2R~
//                plh->ULHlen=le                                   //~v0c2R~
////              len-=(pos+offset);  //move len                     //~v0c2//~v0c2R~
//                len=len2;                                          //~v0c2//~v0c2R~
//              }                                                    //~v0c2//~v0c2R~
////          }                                                      //+v0c2//~v0c2R~
//            pc=plh->ULHdata+pos;                                //~5521//~v0c2R~
//            memmove(pc+offset,pc,(UINT)len                       //~v0c2R~
//            memset(pc,' ',(UINT)offset                           //~v0c2R~
//            pc=plh->ULHdbcs+pos;    //once displayed            //~5521//~v0c2R~
//            memmove(pc+offset,pc,(UINT)len);                    //~5103//~v0c2R~
//            memset(pc,0,(UINT)offset);                          //~5103//~v0c2R~
////          if (filetabshift(0,plh))    //expand tab,right cut     //~v0b3//~v0c2R~
////              return UALLOC_FAILED;                              //~v0b3//~v0c2R~
////          filecidshift(pfh,plh,0); //drop space before cid       //~v0c2//~v0c2R~
			if (lcmdrshift(plh,pos,repeat,len,oomlen)==UALLOC_FAILED)//~v0c2I~
            	return UALLOC_FAILED;                              //~v0c2I~
			break;
//*********                                                        //~v41fI~
//  	case '>':                                                  //~v41wR~
    	case ']':                                                  //~v41wI~
//*reduce continuous space to one space                            //~v41fI~
//          if (oomlen)                                            //~v0c2//~v74ER~
//              len=mergin-pos;  //right of csr up to margin       //~v74ER~
//          else                                                   //~v0c2//~v74ER~
//              len=plh->ULHlen-pos;  //up to eol                  //~v0c2//~v74ER~
			len=lcmdbndsadjust_r(plh,bndsoffs1,bndsoffs2,&mergin,pos,&oomlen);//~v74EI~
            if (len<=0) //data on the right of csr                 //~v0c2//~v41fI~
                break;                  //no data on the right of csr//~5521//~v41fI~
            pc=plh->ULHdata+pos+len-1;  //end of line data pos  //~5521//~v41fI~
//count deletable space                                            //~v41fI~
            for (offset=0,i=0;i<len;i++,pc--)                      //~v41fI~
            {                                                      //~v41fI~
#ifdef UTF8UCS2                                                    //~va20I~
				pcd=XEUTF_PC2PCD(pcd0,pc,pc0);                     //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                if (UCVEBCUTF_nespace(swebcfile,swutf8file,*pc,*pcd))//~va50I~
    #else                                                          //~va50I~
                if (UTF_nespace(swutf8file,*pc,*pcd))              //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                if (*pc!=' ')                                      //~v41fI~
#endif                                                             //~va20I~
                {                                                  //~v77jR~
                    if (offset)                                    //~v77jR~
                    {                                              //~v77jR~
                    	offset=2;	//data before double space     //~v77jR~
                        break;                                     //~v77jR~
                    }                                              //~v77jR~
                    continue;                                      //~v41fI~
                }                                                  //~v77jR~
                i++;                                               //~v41fI~
                pc--;                                              //~v41fI~
#ifdef UTF8UCS2                                                    //~va20I~
				pcd=XEUTF_PC2PCD(pcd0,pc,pc0);                     //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                if (i<len && UCVEBCUTF_eqspace(swebcfile,swutf8file,*pc,*pcd))//~va50I~
    #else                                                          //~va50I~
                if (i<len && UTF_eqspace(swutf8file,*pc,*pcd))     //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                if (i<len && *pc==' ')                             //~v41fI~
#endif                                                             //~va20I~
                {                                                  //~v41fI~
                    offset=1;   //drop space occur                 //~v41fI~
//                  break;                                         //~v77jR~
                }                                                  //~v41fI~
            }                                                      //~v41fI~
//          if (!offset)		//no space to be delete            //~v74KR~
            if (offset<2)		//no space to be delete            //~v74KI~
            {                                                      //~v41fI~
                lcmdshifterr(plh,plhx,&plherr);                    //~v41fI~
            	break;                                             //~v41fI~
            }                                                      //~v41fI~
			if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)       //~v41fI~
            	return UALLOC_FAILED;                              //~v41fI~
   			filetabclear(plh);//tab clear                          //~v41fI~
//drop space                                                       //~v41fI~
            lcmddbcssplit(plh,pos);//dbcs split clear befor shift  //~v74KI~
            pc2=pc=plh->ULHdata+pos+len-1;  //end of line data pos  //~5521//~v41fI~
            pcd2=pcd=plh->ULHdbcs+pos+len-1;  //end of line data pos  //~5521//~v41fI~
            for (offset=0,i=0;i<len;)                              //~v41fI~
            {                                                      //~v41fI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                if (UCVEBCUTF_nespace(swebcfile,swutf8file,*pc,*pcd))//~va50I~
    #else                                                          //~va50I~
                if (UTF_nespace(swutf8file,*pc,*pcd))              //~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
                if (*pc!=' ')                                      //~v41fI~
#endif                                                             //~va20I~
                {                                                  //~v41fI~
                	*pc2--=*pc--;                                  //~v41fI~
                	*pcd2--=*pcd--;                                //~v41fI~
                    i++;                                           //~v41fI~
                	continue;                                      //~v41fI~
                }                                                  //~v41fI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                *pc2--=UCVEBC_CHAR_SPACE(swebcfile);               //~va50I~
#else                                                              //~va50I~
                *pc2--=' ';                                        //~v41fI~
#endif                                                             //~va50I~
                *pcd2--=0;                                         //~v41fI~
                pc--;                                              //~v41fI~
                pcd--;                                             //~v41fI~
                i++;                                               //~v41fI~
                for (;i<len && offset<Prepeat;i++,pc--,pcd--)      //~v41fI~
                {                                                  //~v41fI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                    if (UCVEBCUTF_nespace(swebcfile,swutf8file,*pc,*pcd))//~va50I~
    #else                                                          //~va50I~
                    if (UTF_nespace(swutf8file,*pc,*pcd))          //~va20I~
    #endif                                                         //~va50I~
#else                                                              //~va20I~
                    if (*pc!=' ')                                  //~v41fI~
#endif                                                             //~va20I~
                        break;                                     //~v41fI~
                    offset++;                                      //~v41fI~
                }                                                  //~v41fI~
                if (offset>=Prepeat)                               //~v41fI~
                    break;                                         //~v41fI~
            }                                                      //~v41fI~
			if (offset<Prepeat)	//non space data                   //~v41fI~
                lcmdshifterr(plh,plhx,&plherr);                    //~v41fI~
            len-=i; 	//i:len from next of pc                    //~v41fR~
            pc-=(len-1);                                           //~v41fI~
            pcd-=(len-1);                                          //~v41fI~
            pc2-=(len-1);                                          //~v41fI~
            pcd2-=(len-1);                                         //~v41fI~
            if (len)                                               //~v41fI~
            {                                                      //~v41fI~
				memmove(pc2,pc,(UINT)len);                         //~v41fR~
				memmove(pcd2,pcd,(UINT)len);                       //~v41fR~
			}//plhlen>0                                            //~v41fI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
			UCVEBC_memset_space(swebcfile,pc,(UINT)offset);        //~va50I~
#else                                                              //~va50I~
			memset(pc,' ',(UINT)offset);                           //~v41fR~
#endif                                                             //~va50I~
			memset(pcd,0,(UINT)offset);                            //~v41fR~
			break;                                                 //~v41fI~
		}//switch by cmd
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		XEEBC_setdbcstblplh(swebcfile,pfh,plh);//re-evaluate dbcstbl//~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
      }//data line                                                 //~v0b6I~
		if (plh==Pplh2)                                            //~v0b6I~
			if (!(excludesw=(Pplh2->ULHtype==ULHTEXCLUDE)))        //~v0b6I~
				break;                                             //~v0b6I~
	}//by range
  if (plherr)                                                      //~v0b6I~
  {                                                                //~v0c2I~
  	bellsw=1;                                                      //~v0c2I~
    filesetcsr(Ppcw,plherr,0,0);	//on cmd line                  //~v0b6I~
  }	                                                               //~v0c2I~
  else                                                             //~v0b6I~
    if (pos)    //pos on file data                              //~5521I~
       filesetcsr(Ppcw,Pplh1,1,Ppcw->UCWrcsrx-Ppcw->UCWlinenosz);//on data line//~v069R~
    else                                                        //~5521I~
       filesetcsr(Ppcw,Pplh1,0,0);	//on cmd line               //~5521R~
    if (bellsw)                                                 //~5103I~
    {                                                              //~v0avI~
    	if (Pcmd=='>')                                             //~v0avI~
	    	charmaxovererr(mergin);                                //~v0avI~
        ubell();                                                //~5103I~
	}                                                              //~v0avI~
	return 0;	//cmd complete                                  //~5103R~
}//lcmdshift                                                    //~5103R~
//**************************************************************** //~v74EI~
//adjust oomlen for left shift                                     //~v74ER~
//return shift length                                              //~v74EI~
//**************************************************************** //~v74EI~
int lcmdbndsadjust_l(PULINEH Pplh,int Pbndsoffs1,int Pbndsoffs2,int Pmergin,int Ppos,int *Ppoomlen)//~v74ER~
{                                                                  //~v74EI~
	int len,oomlen;                                                //~v74ER~
//**************************                                       //~v74EI~
	oomlen=*Ppoomlen;                                              //~v74EI~
    if (Pbndsoffs2>0)                                              //~v74ER~
    {                                                              //~v74ER~
        if (Pbndsoffs2<Pplh->ULHlen)                               //~v74ER~
        {                                                          //~v74ER~
            oomlen=Pplh->ULHlen-Pbndsoffs2;                        //~v74ER~
            len=Pbndsoffs2-Ppos;                                   //~v74ER~
        }                                                          //~v74ER~
        else                                                       //~v74ER~
            len=Pplh->ULHlen-Ppos;                                 //~v74ER~
    }                                                              //~v74ER~
    else                                                           //~v74ER~
    if (oomlen)                                                    //~v74ER~
        len=Pmergin-Ppos;                                          //~v74ER~
    else                                                           //~v74ER~
        len=Pplh->ULHlen-Ppos;                                     //~v74ER~
    *Ppoomlen=oomlen;                                              //~v74EI~
	return len;                                                    //~v74EI~
}//lcmdbndsadjust_l                                                //~v74ER~
//**************************************************************** //~v74EI~
//adjust oomlen for right shift                                    //~v74EI~
//**************************************************************** //~v74EI~
int lcmdbndsadjust_r(PULINEH Pplh,int Pbndsoffs1,int Pbndsoffs2,int *Ppmergin,int Ppos,int *Ppoomlen)//~v74EI~
{                                                                  //~v74EI~
	int mergin,oomlen,len;                                         //~v74EI~
//**************************                                       //~v74EI~
	oomlen=*Ppoomlen;                                              //~v74EI~
	mergin=*Ppmergin;                                              //~v74EI~
    if (Pbndsoffs2>0)                                              //~v74EI~
    {                                                              //~v74EI~
        mergin=Pbndsoffs2;                                         //~v74EI~
        if (Pbndsoffs2<Pplh->ULHlen)                               //~v74EI~
            oomlen=Pplh->ULHlen-Pbndsoffs2;                        //~v74EI~
    }                                                              //~v74EI~
    if (oomlen)                                            //~v0c2 //~v74EI~
    	len=mergin-Ppos;  //right of csr up to margin              //~v74ER~
    else                                                   //~v0c2 //~v74EI~
        len=Pplh->ULHlen-Ppos;  //up to eol                  //~v0c2//~v74ER~
	*Ppoomlen=oomlen;                                              //~v74EI~
	*Ppmergin=mergin;                                              //~v74EI~
    return len;                                                    //~v74EI~
}//lcmdbndsadjust_r                                                //~v74EI~
//**************************************************************** //~v0i0I~
//!lcmdcom                                                         //~v0i0I~
// 	c // comment out                                               //~v0i0I~//~va50R~
//*parm1:pcw                                                       //~v0i0I~
//*parm2:start ULINEH                                              //~v0i0I~
//*parm3:end   ULINEH                                              //~v0i0I~
//*parm4:repaet count                                              //~v0i0I~
//*parm5:bandle                                                    //~v0i0I~
//*parm6:skip                                                      //~v0i0I~
//*rc   :0 or UALLOC_FAILED                                        //~v0i0I~
//**************************************************************** //~v0i0I~
int lcmdcombs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,//~v0i0I~
				int Pbandle,int Pskip)                             //~v0i0I~
{                                                                  //~v0i0I~
	PULINEH plh,plh2,plh3,plhstop;                                 //~v0i0I~
	int ii,rc,repeat;                                              //~v0i0I~
//*****************                                                //~v0i0I~
	if (Pplh1==Pplh2)	//count type dn/l.m                        //~v0i0I~
    {                                                              //~v0i0I~
    	repeat=Prepeat;                                            //~v0i0I~
    	plhstop=0;                                                 //~v0i0I~
	}                                                              //~v0i0I~
    else                                                           //~v0i0I~
    {                                                              //~v0i0I~
//  	repeat=0x7fff;                                             //~v431R~
    	repeat=MAX_INT_VAL;                                        //~v431R~
    	plhstop=Pplh2;                                             //~v0i0I~
	}                                                              //~v0i0I~
    plh=Pplh1;                                                     //~v0i0I~
    for (ii=0;ii<repeat;ii++)                                      //~v0i0I~
    {                                                              //~v0i0I~
        if (lcmdgetplhrange2(&plh,&plh2,plhstop,Pbandle)==8)    //get next line after del//~v0i0I~
        {                                                          //~v57HI~
            if (ii)         //start line reached to eol            //~v0i0I~
                break;                                             //~v0i0I~
            else            //first time eol                       //~v0i0I~
                return 8;                                          //~v0i0I~
        }                                                          //~v57HI~
        if (plh2!=plhstop)                                         //~v0i0I~
	        lcmdgetplhrange2(&plh2,&plh3,plhstop,Pskip+1);//next del start//~v0i0R~
		rc=lcmdcom(Ppcw,plh,plh2,1,"//");                          //~v0i0I~
        if (rc)                                                    //~v0i0I~
    	        return rc;                                         //~v0i0I~
        if (plh2==plhstop || plh2==plhstop)                        //~v0i0R~
            break;                                                 //~v0i0I~
	    lcmdgetplhrange2(&plh3,&plh,plhstop,2);//next del start    //~v0i0I~
    }                                                              //~v0i0I~
    return 0;                                                      //~v0i0I~
}//lcmdcombs                                                       //~v0i0I~
//****************************************************************
//!lcmdcom                                                         //~v0c2R~
// 	c // comment cou
//*parm1:pcw
//*parm2:start ULINEH
//*parm3:end   ULINEH
//*parm4:repaet count
//*parm5:comment string
//*rc   :0 or UALLOC_FAILED
//****************************************************************
int lcmdcom(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,char *Pcomment)
{
	PULINEH plh,plhn,plherr=0,plhx=0;                              //~v0avR~
	PUFILEH pfh;                                                   //~v0avI~
	int excludesw,len;                                             //~v0c2R~
	int addlen;
    UCHAR *pc,*pcd;
    int oomlen,repeat,mergin;	                                   //~v0c2R~
    int rc;                                                        //~v0f2I~
    int pos;                                                       //~v477I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************
	if (CSRONFILEDATA(Ppcw))			//csr on file data line    //~v477I~
    	pos=Ppcw->UCWrcsrx-Ppcw->UCWlinenosz+((PUFILEC)Ppcw->UCWpfc)->UFCleft;//target pos//~v477I~
    else                                                           //~v477I~
    	pos=0;                                                     //~v477I~
    pfh=UGETPFH(Pplh1);                                            //~v0avI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    mergin=pfh->UFHmergin;                                         //~v0c2I~
    addlen=(int)strlen(Pcomment);
//*convert cont type to range type
	if (Pplh1==Pplh2)	//Dnn count type
        if (lcmdgetplhrange(&Pplh1,&Pplh2,Prepeat)==8)	//on end of file
        	return 4;
//*insert comment range
	excludesw=0;
	for (plh=Pplh1;plh;)
	{
		if (excludesw)
			if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))
				break;
		plhn=UGETQNEXT(plh);
		if (plh->ULHtype==ULHTEXCLUDE)		//no delete when hdr line//~v0avI~
        	plhx=plh;                                              //~v0avI~
		if (plh->ULHtype==ULHTDATA)		//no delete when hdr line  //~v0asR~
		{
			pcd=plh->ULHdbcs;	//once displayed                   //~v0avI~
            if (!pcd)                                              //~v0avI~
            	if (filechktabdbcs(plh)==UALLOC_FAILED)            //~v0avI~
                	return UALLOC_FAILED;                          //~v0avI~
		    oomlen=filegetoomlen(pfh,plh);  //out of mergin len    //~v0c2I~
//          if (oomlen)                                              //~v0c2//~v0c2R~
//            len=mergin;                                            //~v0c2//~v0c2R~
//          else                                                     //~v0c2//~v0c2R~
//            len=plh->ULHle                                       //~v0c2R~
//                                                                   //~v0c2//~v0c2R~
//            pc=plh->ULHdata+len-1;          //end of li          //~v0c2R~
//            for (ii=0;len && ii<addlen;ii++,len--,pc-            //~v0c2R~
//                if (*pc!='                                       //~v0c2R~
//                    brea                                         //~v0c2R~
//                                                                   //~v0c2//~v0c2R~
//            len-=ii;                                               //~v0av//~v0c2R~
//  		if (lcmdovfchk(plh,0,addlen,mergin,oomlen,&repeat,&len))//~v0f2R~
//          	break;                                             //~v0f2R~
//  		if ((rc=lcmdovfchk(plh,0,addlen,mergin,oomlen,&repeat,&len))>4)//~v477R~
    		if ((rc=lcmdovfchk(plh,pos,addlen,mergin,oomlen,&repeat,&len))>4)//~v477I~
				lcmdshifterr(plh,plhx,&plherr);                    //~v0f2I~
            if (addlen!=repeat)     //no space to move             //~v0c2R~
				lcmdshifterr(plh,plhx,&plherr);                    //~v0azR~
			else
            if (!rc)		//ovf chk ok                           //~v0f2I~
            {
    			if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)
                	return UALLOC_FAILED;
//                filetabclear(plh);                                 //~v0c2//~v0c2R~
//              if (!oomlen)                                          //~v0c2//~v0c2R~
//              {                                                    //~v0c2//~v0c2R~
//                len2=le                                          //~v0c2I~
//                len=offset+len+po                                //~v0c2I~
//                if (len>plh->ULHbuffle                           //~v0c2R~
//                    if (fileexpandbuff(plh,len)==UALLOC_FAILE    //~v0c2R~
//                        return UALLOC_FAILE                      //~v0c2R~
//                plh->ULHlen=le                                   //~v0c2R~
//                len=len                                          //~v0c2I~
//              }                                                    //~v0c2//~v0c2R~
//                pc=plh->ULHdat                                   //~v0c2R~
//                pcd=plh->ULHdbcs;                                  //~v0av//~v0c2R~
//                memmove(pc+addlen,pc,(UINT)len                   //~v0c2R~
//                memcpy(pc,Pcomment,(UINT)addlen                  //~v0c2R~
//                memmove(pcd+addlen,pcd,(UINT)len);                 //~v0av//~v0c2R~
//                memset(pcd,0,(UINT)addlen);                        //~v0av//~v0c2R~
////              filecidshift(pfh,plh,0);                           //~v0c2//~v0c2R~
//  			if (lcmdrshift(plh,0,repeat,len,oomlen)==UALLOC_FAILED)//~v477R~
    			if (lcmdrshift(plh,pos,repeat,len,oomlen)==UALLOC_FAILED)//~v477I~
        	    	return UALLOC_FAILED;                          //~v0c2I~
//                pc=plh->ULHdata;                                 //~v477R~
//                pcd=plh->ULHdbcs;                                  //~v0av//~v477R~
//                memcpy(pc,Pcomment,(UINT)addlen);                //~v477R~
//                memset(pcd,0,(UINT)addlen);                        //~v0av//~v477R~
                  pc=plh->ULHdata+pos;                             //~v477I~
                  pcd=plh->ULHdbcs+pos;                            //~va7jI~
//                memcpy(pc,Pcomment,(UINT)addlen);                //~v477R~//~va7jR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//                UCVEBC_a2bfld(swebcfile,pc,addlen);              //~va50I~//~va79R~
//                UCVEBC_a2bfld(swebcfile,handle,pc,addlen);       //~va79I~//~va7jR~
				  filecvlcmd(FCLCO_2FILE,pfh,pc,pcd/*pdbcs*/,Pcomment,addlen);//~va7jR~
		 		  XEEBC_setdbcstblplh(swebcfile,pfh,plh);//re-evaluate dbcstbl//~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            }
		}//data line                                               //~v0asR~
		if (plh==Pplh2)
			if (!(excludesw=(Pplh2->ULHtype==ULHTEXCLUDE)))
				break;
		plh=plhn;
	}//by range

    if (!plherr)                                                   //~v0avR~
    	plherr=Pplh1;                                              //~v0avI~
    else                                                           //~v0avI~
        ubell();                                                   //~v0avR~
	filesetcsr(Ppcw,plherr,0,0);	//on cmd line                  //~v0avR~
	return 0;                                                      //~v0avR~
}//lcmcom
                                                                   //~v0asI~
//**************************************************************** //~v0asI~
//!lcmgcom                                                         //~v0asI~
// 	general comment out                                            //~v0asI~
//*parm1:pcw                                                       //~v0asI~
//*parm2:start ULINEH                                              //~v0asI~
//*parm3:end   ULINEH                                              //~v0asI~
//*rc   :0 or UALLOC_FAILED                                        //~v0asI~
//**************************************************************** //~v0asI~
int lcmdgcom(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2)          //~v0asI~
{                                                                  //~v0asI~
    UCHAR icstr[ULHLINENOSZ],*pc1,*pc2;                            //~v0asR~
    int len1,len2;                                                 //~v0asI~
//*****************                                                //~v0asI~
	if (Pplh1!=Pplh2)                                              //~v0asI~
    {                                                              //~v0asI~
		pc1=Pplh1->ULHlinecmd+2;                                   //~v0asI~
		len1=(int)strlen(pc1);                                     //~v0asI~
    	pc2=Pplh2->ULHlinecmd+2;                                   //~v0asI~
    	len2=(int)strlen(pc2);                                     //~v0asI~
        if (len1)		//has string after ++                      //~v0asI~
        {                                                          //~v0asI~
        	if (len2 && strcmp(pc1,pc2))//not same                 //~v0asI~
               	return 4;		//err                              //~v0asI~
		}                                                          //~v0asI~
        else                                                       //~v0asI~
        {                                                          //~v0asI~
        	len1=len2;                                             //~v0asI~
    		pc1=pc2;	//use 2nd plh                              //~v0asI~
		}                                                          //~v0asI~
	}                                                              //~v0asI~
    else                                                           //~v0asI~
		pc1=Pplh1->ULHlinecmd+1;                                   //~v0asI~
		len1=(int)strlen(pc1);                                     //~v0asI~
    if (!len1)                                                     //~v0asI~
    	return 4;                                                  //~v0asI~
	strcpy(icstr,pc1);                                             //~v0asR~
    return lcmdcom(Ppcw,Pplh1,Pplh2,1,icstr);//repaet=1 is dummy   //~v0asR~
}//lcmgcom                                                         //~v0asI~
                                                                   //~v0avI~
//**************************************************************** //~v0i7I~
//!lcmdsplit                                                       //~v0i7R~
//*parm1:pcw                                                       //~v0i7I~
//*parm2:start ULINEH                                              //~v0i7I~
//*parm3:end   ULINEH                                              //~v0i7I~
//*parm4:repaet count                                              //~v0i7I~
//*parm5:plc                                                       //~v0i7I~
//*parm6:bandle                                                    //~v0i7I~
//*parm7:skip                                                      //~v0i7I~
//*rc   :0 or UALLOC_FAILED                                        //~v0i7I~
//**************************************************************** //~v0i7I~
int lcmdsplit(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,//~v0i7R~
				int Pbandle,int Pskip)                             //~v0i7R~
{                                                                  //~v0i7I~
    PUFILEC pfc;                                                   //~va3SI~
	PUSCRD psd;                                                    //~va3SI~
	PULINEH plh,plhx,plhn,plhstop,plhcsr=0,plhe=0;                 //~v0i7R~
	int ii,jj,kk,stopsw=0,rc,bandle,skip;                          //~v0i7R~
    int opt=0;                                                     //~va3SR~
//*****************                                                //~v0i7I~
	if (!CSRONFILEDATA(Ppcw))	//csr on line data except lineno   //~v0i7I~
   		return errcsrpos();                                        //~v0i7I~
	pfc=Ppcw->UCWpfc;                                              //~va3SI~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                               //~va3SI~
	if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))                         //~va3SI~
    {                                                              //~va3SI~
	    if (psd->USDflag2 & (USDF2VHEXLINE1|USDF2VHEXLINE2))       //~va3SI~
            opt=CLS_LCSPLITVX; //from "S" lcmd on vhexline         //~va3SI~
    }                                                              //~va3SI~
	if (Pplh1==Pplh2)	//count type                               //~v0i7I~
    {                                                              //~v0i7I~
    	ii=Prepeat;                                                //~v0i7I~
        plhstop=0;                                                 //~v0i7I~
	}        	                                                   //~v0i7I~
	else                                                           //~v0i7I~
    {                                                              //~v0i7I~
    	ii=-1;                                                     //~v0i7I~
        plhstop=Pplh2;                                             //~v0i7I~
	}                                                              //~v0i7I~
//split                                                            //~v0i7I~
	if (Pbandle)                                                   //~v0i7I~
    	bandle=Pbandle;                                            //~v0i7R~
    else                                                           //~v0i7I~
    	bandle=1;                                                  //~v0i7I~
//loop by count or stop                                            //~v0i7I~
	stopsw=0;                                                      //~v0i7I~
    plhn=0;
    for (plh=Pplh1;ii && plh;plh=plhn,ii--)                        //~v0i7R~
    {                                                              //~v0i7I~
    	for (jj=bandle;jj && plh;plh=plhn)                         //~v0i7R~
        {                                                          //~v0i7I~
        	if (plh==plhstop)                                      //~v0i7I~
            	stopsw=1;                                          //~v0i7I~
		    plhn=getdisplayline(plh,1,0);                          //~v0i7R~
        	if (plh->ULHtype==ULHTHDR)                             //~v0i7R~
        		continue;                                          //~v0i7R~
            jj--;                                                  //~v0i7I~
//******                                                           //~v0i7I~
            if (plh->ULHtype==ULHTEXCLUDE)                         //~v0i7R~
            {                                                      //~v0i7R~
            	plhx=plh;                                          //~v0i7I~
                if (undoprep(Ppcw,plh,UUHTXLINENO)==UALLOC_FAILED)//prepare for excluded lineno//~v0i7R~
                    return UALLOC_FAILED;                          //~v0i7R~
//              kk=plh->ULHlinenow;                                //~v0i7R~//+vb2ER~
                kk=(int)plh->ULHlinenow;                           //+vb2EI~
                plh->ULHlinenow<<=1;                               //~v0i7I~
                lcmdeditxline(plh);                                //~v0i7R~
                if (!plhcsr)                                       //~v0i7R~
                    plhcsr=plh;                                    //~v0i7R~
                plh=UGETQNEXT(plh);                                //~v0i7I~
            }                                                      //~v0i7R~
            else                                                   //~v0i7I~
            {                                                      //~v0i7I~
            	plhx=0;                                            //~v0i7I~
            	kk=1;                                              //~v0i7I~
			}                                                      //~v0i7I~
            for (;plh && kk;kk--,plh=plhn)                         //~v0i7I~
            {                                                      //~v0i7R~
                plhn=UGETQNEXT(plh);                               //~v0i7I~
	            if (plh->ULHtype==ULHTHDR)                         //~v0i7I~
                	break;                                         //~v0i7I~
//              if (rc=charlcmdsplit(Ppcw,plh),rc)    //get next line after del//~v66fR~
//              if (rc=charlcmdsplit(Ppcw,plh,-1),rc) //get next line after del,-1:split at csr pos//~v74jR~
//                if (rc=charlcmdsplit(0,Ppcw,plh,-1),rc) //get next line after del,-1:split at csr pos//~v74jI~//~va3SR~
                if (rc=charlcmdsplit(opt,Ppcw,plh,-1),rc) //get next line after del,-1:split at csr pos//~va3SI~
                {                                                  //~v0i7R~
                    lcmdshifterr(plh,plhx,0);                      //~v0i7R~
                    plhe=UGETQNEXT(plh);                           //~v0i7R~
                    if (plhe!=plhn)	//isrted                       //~v0i7I~
	                    lcmdshifterr(plhe,0,0);                    //~v0i7I~
                    else                                           //~v0i7I~
                    	plhe=plh;                                  //~v0i7I~
					filesetcsr(Ppcw,plhe,0,0);	//on cmd line      //~v0i7I~
                    return rc;                                     //~v0i7R~
                }                                                  //~v0i7R~
                if (!plhcsr)                                       //~v0i7R~
                    plhcsr=plh;                                    //~v0i7R~
            }                                                      //~v0i7R~
//******                                                           //~v0i7I~
            if (stopsw)                                            //~v0i7I~
            	break;                                             //~v0i7I~
		}                                                          //~v0i7I~
        if (stopsw)                                                //~v0i7I~
            break;                                                 //~v0i7I~
		if (Pbandle)                                               //~v0i7I~
        {                                                          //~v0i7I~
		    plhn=getdisplayline2(plhn,Pskip,plhstop,&skip);        //~v0i7R~
        	if (skip!=Pskip)	//reached in the skip range        //~v0i7R~
            	break;                                             //~v0i7I~
        }                                                          //~v0i7I~
    }//count or reached to end plh                                 //~v0i7I~
//*                                                                //~v0i7I~
    if (plhcsr)                                                    //~v0i7I~
		filesetcsr(Ppcw,plhcsr,0,0);	//on cmd line              //~v0i7R~
    return 0;                                                      //~v0i7I~
}//lcmdsplit                                                       //~v0i7R~
                                                                   //~v0i7I~
//**************************************************************** //~v0i7I~
//!lcmdjoin                                                        //~v0i7I~
//*parm1:pcw                                                       //~v0i7I~
//*parm2:start ULINEH                                              //~v0i7I~
//*parm3:end   ULINEH                                              //~v0i7I~
//*parm4:repaet count                                              //~v0i7I~
//*parm5:plc                                                       //~v0i7I~
//*parm6:bandle                                                    //~v0i7I~
//*parm7:skip                                                      //~v0i7I~
//*rc   :0 or UALLOC_FAILED                                        //~v0i7I~
//**************************************************************** //~v0i7I~
int lcmdjoin(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,//~v0i7I~
				int Pbandle,int Pskip)                             //~v0i7I~
{                                                                  //~v0i7I~
	PULINEH plh,plh1,plhn,plhstop,plhx=0,plhcsr=0;                 //~v0i7I~
	int ii,jj,rc,bandle,lastexcsw,stopsw=0;                        //~v17aR~
    int kk,joinlinecnt;                                            //~v156I~
//*****************                                                //~v0i7I~
	if (Pplh1==Pplh2)	//count type                               //~v0i7I~
    {                                                              //~v0i7I~
    	ii=Prepeat;                                                //~v0i7I~
        plhstop=0;                                                 //~v0i7I~
        joinlinecnt=1;                                             //~v156I~
	}                                                              //~v0i7I~
	else                                                           //~v0i7I~
    {                                                              //~v0i7I~
    	ii=-1;                                                     //~v0i7I~
        plhstop=Pplh2;                                             //~v0i7I~
        if ((joinlinecnt=Prepeat-1)<1)                             //~v156R~
        	joinlinecnt=1;                                         //~v156I~
	}                                                              //~v0i7I~
    if (UCBITCHK(Pplh1->ULHflag2,ULHF2SPLIT2)//has prev            //~v17aI~
    ||  UCBITCHK(Pplh2->ULHflag2,ULHF2SPLIT2))//has prev           //~v47jR~
    {                                                              //~v17aI~
    	uerrmsg("In the middle of splitted line",                  //~v17aI~
        		"分割行の途中");                                   //~v17aI~
		return 4;                                                  //~v17aI~
    }                                                              //~v17aI~
                                                                   //~v17aI~
//join                                                             //~v0i7I~
	if (!(bandle=Pbandle))                                         //~v0i7I~
    {                                                              //~v0i7I~
    	bandle=ii;                                                 //~v0i7R~
        ii=1;                                                      //~v0i7I~
	}                                                              //~v0i7I~
    plh1=0;                                                        //~v0i7I~
    plhn=0;
    kk=joinlinecnt;                                                //~v156I~
    for (plh=Pplh1;plh && ii;plh=plhn,ii--)                        //~v0i7I~
    {                                                              //~v0i7I~
	    lastexcsw=0;                                               //~v0i7I~
    	for (jj=bandle;plh;plh=plhn)                               //~v0i7I~
        {                                                          //~v0i7I~
        	if (plh==plhstop)                                      //~v0i7I~
            	stopsw=1;                                          //~v0i7I~
//          plhn=UGETQNEXT(plh);                                   //~v17aR~
    		plhn=fsubnextlineoversplit(0,plh,1,0);	//next line over split//~v47jR~
            if (plh->ULHtype==ULHTHDR)                             //~v0i7I~
                continue;                                          //~v0i7I~
            if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))            //~v0i7R~
            {                                                      //~v0i7I~
	            if (lastexcsw)                                     //~v0i7I~
    	        {                                                  //~v0i7I~
                	plhn=plh;                                      //~v0i7I~
                	break;                                         //~v0i7I~
                }                                                  //~v0i7I~
//                if (!plh1)                                       //~v156R~
//                    jj--;                                        //~v156R~
                if (plh->ULHtype==ULHTEXCLUDE)                     //~v0i7I~
                {                                                  //~v0i7I~
//                  if (!jj)                                       //~v156R~
                    if (jj==1 && kk==1) //to be include all excluded of last EXC line//~v156I~
	                    if (!plh1)      //searching first          //~v0i7R~
                            lastexcsw=1;                           //~v0i7I~
                    if (plh==plhstop )  //last line                //~v0i7I~
                    	lastexcsw=1;                               //~v0i7I~
                    if (undoprep(Ppcw,plh,UUHTXLINENO)==UALLOC_FAILED)//prepare for excluded lineno//~v0i7I~
                        return UALLOC_FAILED;                      //~v0i7I~
                    if (!plhcsr)                                   //~v0i7I~
                        plhcsr=plh;                                //~v0i7I~
                    plhx=plh;                                      //~v0i7I~
                    plh=plhn;                                      //~v0i7I~
                    plhn=UGETQNEXT(plh);                           //~v0i7I~
                }//exclude hdr                                     //~v0i7I~
                else                                               //~v0i7I~
	                plhx=0;                                        //~v0i7I~
            }//display line                                        //~v0i7I~
//******                                                           //~v0i7I~
            if (!plh1)                                             //~v0i7I~
            {                                                      //~v0i7I~
                plh1=plh;                                          //~v0i7M~
            	if (plh==plhstop)                                  //~v0i7M~
		            if (!lastexcsw)                                //~v0i7M~
    	                break;                                     //~v0i7M~
                continue;                                          //~v0i7I~
            }                                                      //~v0i7I~
//ajust excluded lineno                                            //~v0i7I~
            if (plhx)                                              //~v0i7I~
            {                                                      //~v0i7I~
                plhx->ULHlinenow--;                                //~v0i7I~
                lcmdeditxline(plhx);                               //~v0i7I~
            }                                                      //~v0i7I~
//join                                                             //~v0i7I~
//          if (rc=charlcmdjoin(Ppcw,plh1,plh),rc)                 //~v74iR~
            if (rc=charlcmdjoin(0,Ppcw,plh1,plh),rc)               //~v74iI~
            {                                                      //~v0i7I~
                lcmdshifterr(plh1,plhx,0);                         //~v0i7I~
                lcmdshifterr(plh,0,0);                             //~v0i7I~
                if (plhx)                                          //~v0i7I~
                    plhcsr=plhx;                                   //~v0i7I~
                else                                               //~v0i7I~
                    plhcsr=plh1;                                   //~v0i7I~
                filesetcsr(Ppcw,plhcsr,0,0);    //on cmd line      //~v0i7I~
                if (rc==1)	//split created                        //~v10bI~
                	rc=0;                                          //~v10bI~
                else                                               //~v10bI~
                return rc;                                         //~v0i7I~
            }                                                      //~v0i7I~
            if (!plhcsr)                                           //~v0i7I~
                plhcsr=plh1;                                       //~v0i7R~
          if (!(--kk))	//all line concatinated                    //~v156R~
          {                                                        //~v156I~
            jj--;                                                  //~v156I~
    		kk=joinlinecnt;                                        //~v156I~
            plh1=0;                                                //~v0i7I~
          }                                                        //~v156I~
//******                                                           //~v0i7I~
            if (!jj || plh==plhstop)                               //~v0i7R~
	            if (!lastexcsw)                                    //~v0i7I~
                    break;                                         //~v0i7I~
		}//loop by bandle                                          //~v0i7I~
        if (!plh || stopsw)			//reached to stopplh           //~v0i7I~
        	break;                                                 //~v0i7I~
		if (Pbandle)                                               //~v0i7I~
        {                                                          //~v0i7I~
//  	    plhn=getdisplayline2(plhn,Pskip,plhstop,&skip);        //~v17aR~
//      	if (skip!=Pskip)	//reached in the skip range        //~v17aR~
			if (!(plhn=fsubnextlineoversplit(0,plhn,Pskip,plhstop)))//overed stopline//~v17aR~
            	break;                                             //~v0i7I~
        }                                                          //~v0i7I~
    }//count or reached to end plh                                 //~v0i7I~
    if (plh1)                                                      //~v156R~
    {                                                              //~v0i7I~
//      uerrmsg("Spaecified range is odd line number",             //~v156R~
//              "指定の範囲は行数が奇数です");                     //~v156R~
        uerrmsg("Last line is not completely joined",              //~v156I~
                "最後の行が未完成です");                           //~v156I~
		lcmdshifterr(plh1,plhx,0);                                 //~v0i7I~
        if (plhx)                                                  //~v0i7I~
	        plhcsr=plhx;                                           //~v0i7I~
        else                                                       //~v0i7I~
	        plhcsr=plh1;                                           //~v0i7R~
        ubell();                                                   //~v0i7I~
    }                                                              //~v0i7I~
//*                                                                //~v0i7I~
    if (plhcsr)                                                    //~v0i7I~
		filesetcsr(Ppcw,plhcsr,0,0);	//on cmd line              //~v0i7I~
    return 0;                                                      //~v0i7I~
}//lcmdjoin                                                        //~v0i7I~
//**************************************************************** //~v47iI~
//!lcmdjoinx                                                       //~v47iI~
//*parm1:pcw                                                       //~v47iI~
//*parm2:exclude line hdr plh;next is tof of concat                //~v47iR~
//*rc   :0 or UALLOC_FAILED                                        //~v47iI~
//**************************************************************** //~v47iI~
int lcmdjoinx(PUCLIENTWE Ppcw,PULINEH Pplh)                        //~v47iI~
{                                                                  //~v47iI~
	PULINEH plh,plhtop,plhn=0;                                     //~v47iR~
//  int rc,donesw=0;                                               //~v47iI~//~vaf9R~
    int rc=0,donesw=0;                                             //~vaf9R~
//*****************                                                //~v47iI~
    plhtop=UGETQNEXT(Pplh);                                        //~v47iR~
    for (plh=plhtop;plh;plh=plhn)                                  //~v47iR~
    {                                                              //~v47iI~
    	plhn=fsubnextlineoversplit(0,plh,1,0);	//next line over split//~v47iI~
        if (!plhn)                                                 //~v47iI~
        	break;                                                 //~v47iI~
	    if (!UCBITCHK(plhn->ULHflag2,ULHF2EXCLUDED))	//excluded line//~v47iR~
        	break;                                                 //~v47iI~
//      if (rc=charlcmdjoin(Ppcw,plhtop,plhn),rc>1)                //~v74iR~
        if (rc=charlcmdjoin(0,Ppcw,plhtop,plhn),rc>1)              //~v74iI~
        {                                                          //~v47iI~
            lcmdshifterr(plhn,Pplh,0);                             //~v47iR~
            filesetcsr(Ppcw,Pplh,0,0);    //on cmd line            //~v47iR~
            break;                                                 //~v47iR~
        }                                                          //~v47iI~
        rc=0;                                                      //~v47iI~
        if (!donesw)	//1st time                                 //~v47iI~
        {                                                          //~v47iI~
	    	if (undoprep(Ppcw,Pplh,UUHTXLINENO)==UALLOC_FAILED)//prepare for excluded lineno//~v47iR~
    			return UALLOC_FAILED;                              //~v47iI~
        }                                                          //~v47iI~
        donesw=1;                                                  //~v47iI~
    }//count or reached to end plh                                 //~v47iI~
    if (donesw)                                                    //~v47iI~
    {                                                              //~v47iI~
		lcmdresetxlineno(Pplh);                                    //~v47iI~
    	lcmdeditxline(Pplh);                                       //~v47iR~
    }                                                              //~v47iI~
    return rc;                                                     //~v47iI~
}//lcmdjoinx                                                       //~v47iR~
//**************************************************************** //~v47iI~
//!lcmdresetxlineno                                                //~v47iI~
//*parm1:x-hdr line                                                //~v47iI~
//*rc   :0                                                         //~v47iI~
//**************************************************************** //~v47iI~
int lcmdresetxlineno(PULINEH Pplh)                                 //~v47iI~
{                                                                  //~v47iI~
	PULINEH plh;                                                   //~v47iR~
//***************************:                                     //~v47iI~
    Pplh->ULHlinenow=0;                                            //~v47iI~
    for (plh=Pplh;plh=UGETQNEXT(plh),plh;)                         //~v47iI~
    {                                                              //~v47iI~
        if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED)) //excluded line//~v47iI~
            break;                                                 //~v47iI~
        Pplh->ULHlinenow++;                                        //~v47iI~
    }                                                              //~v47iI~
    return 0;                                                      //~v47iI~
}//lcmdresetxlineno(PULINEH Pplh)                                  //~v47iI~
//**************************************************************** //~v0avI~
//!lcmddbcssplit                                                   //~v0avI~
//   clear dbcs when split                                         //~v0avI~
//*parm1:PULINEH                                                   //~v0avI~
//*parm2:split pos                                                 //~v0avI~
//*rc   :none                                                      //~v0avI~
//**************************************************************** //~v0avI~
void lcmddbcssplit(PULINEH Pplh,int Ppos)                          //~v0avI~
{                                                                  //~v0avI~
	UCHAR *pc,*pcd;                                                //~v0avI~
	int len;                                                       //~v0avI~
//********************                                             //~v0avI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (PLH_ISEBC(Pplh))                                           //~va50I~
        return;                                                    //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	pc=Pplh->ULHdata;                                              //~v0avI~
	pcd=Pplh->ULHdbcs;                                             //~v0avI~
	len=Pplh->ULHlen;                                              //~v0avI~
    if (len>Ppos)                                                  //~v0avI~
  {                                                                //~va59I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va59I~
		xesub_setdbcssplit(0,0/*plh*/,pc+Ppos,pcd+Ppos,len-Ppos,' ');	//right half//~va59I~
#else                                                              //~va59I~
		setdbcssplit(pc+Ppos,pcd+Ppos,len-Ppos,' ');	//right half//~v0avI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va59I~
	if (Ppos)                                                      //~v0avI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va59I~
		xesub_setdbcssplit(0,0,pc,pcd,Ppos,' ');	//left half    //~va59I~
#else                                                              //~va59I~
		setdbcssplit(pc,pcd,Ppos,' ');	//left half                //~v0avI~
#endif //UTF8EBCD raw ebcdic file support                          //~va59I~
  }//Ppos chk for safety,currentry oveflow chk is done             //~va59I~
    return;                                                        //~v0avI~
}//lcmddbcssplit                                                   //~v0avI~
                                                                   //~v0avI~
//**************************************************************** //~v0azI~
//!lcmdshifterr                                                    //~v0azI~
//   reverse shift err line,or EXCLUDE if excluded                 //~v0azI~
//*parm1:plh                                                       //~v0azI~
//*parm2:plhx(type EXCLUDE)                                        //~v0azI~
//*parm3:optional output plherr(first err line)                    //~v0beR~
//*rc   :none                                                      //~v0azI~
//**************************************************************** //~v0azI~
void lcmdshifterr(PULINEH Pplh,PULINEH Pplhx,PULINEH *Ppplherr)    //~v0azI~
{                                                                  //~v0azI~
    PULINEH plherr;                                                //~v0azI~
//********************                                             //~v0azI~
    UCBITON(Pplh->ULHflag,ULHFDRAW); //reverse                     //~v0azI~
    UCBITON(Pplh->ULHflag3,ULHF3ERRLINE);    //reverse             //~v0azI~
    Pplh->ULHerrctr=Glcmd4errctr;           //reset ctl by tc cmd  //~v57HI~
    plherr=Pplh;                                                   //~v0azI~
    if (UCBITCHK(Pplh->ULHflag2,ULHF2EXCLUDED))//set also EXCLUDE line//~v0azI~
        if (Pplhx)                                                 //~v0azI~
        {                                                          //~v0azI~
            UCBITON(Pplhx->ULHflag,ULHFDRAW);    //reverse         //~v0azI~
            UCBITON(Pplhx->ULHflag3,ULHF3ERRLINE);   //reverse     //~v0azI~
		    plherr=Pplhx;                                          //~v0azI~
        }                                                          //~v0azI~
	if (Ppplherr)                                                  //~v0beR~
		if (!*Ppplherr)                                            //~v0beI~
    		*Ppplherr=plherr;                                      //~v0beR~
	return;                                                        //~v0azI~
}//lcmdshifterr                                                    //~v0azI~
//**************************************************************** //~v53EI~
//!lcmdreseterr                                                    //~v53EI~
//   reset  shift err line,or EXCLUDE line if excluded             //~v53EI~
//*parm1:plh                                                       //~v53EI~
//*rc   :0:not err line,1:err reset not excluded,                  //~v53EI~
//*     :2:excluded but other err line,3:also reset exclude hdr    //~v53EI~
//**************************************************************** //~v53EI~
int lcmdresetshifterr(PULINEH Pplh,int Pchkexsw)                   //~v53ER~
{                                                                  //~v53EI~
	PULINEH plh,plhx;                                              //~v53ER~
//********************                                             //~v53EI~
    if (!UCBITCHK(Pplh->ULHflag3,ULHF3ERRLINE))                    //~v53ER~
    	return 0;                                                  //~v53EI~
    UCBITON(Pplh->ULHflag,ULHFDRAW); //reverse                     //~v53EI~
    UCBITOFF(Pplh->ULHflag3,ULHF3ERRLINE);                         //~v53EI~
    if (!Pchkexsw) 	//exclude hdr reset req                        //~v53ER~
    	return 1;                                                  //~v53EI~
    if (!UCBITCHK(Pplh->ULHflag2,ULHF2EXCLUDED))//not required set also EXCLUDE line//~v53EI~
    	return 1;		//reset not excluded lien                  //~v53EI~
//chk before                                                       //~v53EI~
    for (plhx=0;plh=UGETQPREV(Pplh),plh;)                          //~v53EI~
    {                                                              //~v53EI~
    	if (plh->ULHtype==ULHTEXCLUDE)	//exclude hdr              //~v53EI~
        {                                                          //~v53EI~
        	plhx=plh;                                              //~v53EI~
            break;                                                 //~v53EI~
        }                                                          //~v53EI~
	    if (UCBITCHK(plh->ULHflag3,ULHF3ERRLINE))//other excluded err exist//~v53EI~
        	return 2;                                              //~v53EI~
    }                                                              //~v53EI~
//chk after                                                        //~v53EI~
	if (!UCBITCHK(plhx->ULHflag3,ULHF3ERRLINE))//other excluded err exist//~v53EI~
        return 3;		//all no err                               //~v53EI~
    for (;plh=UGETQNEXT(Pplh),plh;)                                //~v53EI~
    {                                                              //~v53EI~
	    if (!UCBITCHK(Pplh->ULHflag2,ULHF2EXCLUDED))//reached to next bundle//~v53EI~
        	break;                                                 //~v53EI~
	    if (UCBITCHK(Pplh->ULHflag3,ULHF3ERRLINE))//other excluded err exist//~v53EI~
        	return 2;                                              //~v53EI~
    }                                                              //~v53EI~
    UCBITON(plhx->ULHflag,ULHFDRAW); //reverse                     //~v53EI~
    UCBITOFF(plhx->ULHflag3,ULHF3ERRLINE);                         //~v53EI~
    return 3;                                                      //~v53EI~
}//lcmdresetshifterr                                               //~v53EI~
//**************************************************************** //~v0c2M~
//!lcmdovfchk                                                      //~v0c2M~
// 	overflowchk                                                    //~v0c2M~
//*parm1:plh                                                       //~v0c2M~
//*parm3:pos                                                       //~v0c2M~
//*parm4:repeat                                                    //~v0c2M~
//*parm5:mergin                                                    //~v0c2M~
//*parm6:oomlen                                                    //~v0c2M~
//*parm7:out repeat                                                //~v0c2M~
//*parm8:out movelen                                               //~v0c2M~
//*rc   :0, 4 bypass process,8 overflow                            //~v0f2R~
//**************************************************************** //~v0c2M~
int lcmdovfchk(PULINEH Pplh,int Ppos,int Prepeat,int Pmergin,int Poomlen,//~v0c2M~
            int *Pnewrepeat,int *Pmovelen)                         //~v0c2M~
{                                                                  //~v0c2M~
	int len,len2,ii,repeat;                                        //~v0c2M~
    UCHAR *pc;                                                     //~v0c2M~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file,ch,dbcsid;                                      //~va20I~
    UCHAR *pcd;                                                    //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************                                                //~v0c2M~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=PLHUTF8MODE(Pplh);                                  //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PLH_ISEBC(Pplh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (Poomlen)                                                   //~v0c2M~
		len=Pmergin-Ppos;		//len after csr                    //~v0c2M~
  	else                                                           //~v0c2M~
    	len=Pplh->ULHlen-Ppos;                                     //~v0c2M~
	if (len<=0)	//data on the right of csr                         //~v0c2M~
    	return 4;                                                  //~v0c2M~
	pc=Pplh->ULHdata+Ppos+len-1;                                   //~v0c2M~
#ifdef UTF8UCS2                                                    //~va20I~
	pcd=Pplh->ULHdbcs+Ppos+len-1;                                  //~va20I~
#endif                                                             //~va20I~
	for (ii=0;ii<Prepeat && ii<len;ii++)                           //~v0c2M~
    {                                                              //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
		ch=*pc--;                                                  //~va20I~
		dbcsid=*pcd--;                                             //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        if (UCVEBCUTF_nespace(swebcfile,swutf8file,ch,dbcsid))     //~va50I~
    #else                                                          //~va50I~
        if (UTF_nespace(swutf8file,ch,dbcsid))                     //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
		if (*pc--!=' ')                                            //~v0c2M~
#endif                                                             //~va20I~
			break;                                                 //~v0c2M~
    }                                                              //~va20I~
    if (ii==len)	//all space after csr,no move                  //~v0c2M~
    	return 4;                                                  //~v0c2M~
//*overflow chk                                                    //~v0c2M~
    len-=ii;     //move len                                        //~v0c2M~
    repeat=Prepeat;                                                //~v0c2M~
    if (ii<Prepeat)                                                //~v0c2M~
    {                                                              //~v57HI~
    	if (Poomlen)                                               //~v0c2M~
            repeat=ii;                                             //~v0c2M~
        else                                                       //~v0c2M~
        {                                                          //~v0dzI~
//         	if (Prepeat>(len2=(Pmergin-(Ppos+len))))               //~v0dzR~
           	len2=Pmergin-(Ppos+len);    //space on right to mergin //~v0dzI~
            if (len2<0)                 //no shift space           //~v0dzI~
//              return 4;                                          //~v0f2R~
                return 8;                                          //~v0f2I~
           	if (Prepeat>len2)           //not max shift space      //~v0dzI~
               	repeat=len2;            //up to the max            //~v0dzR~
        }                                                          //~v0dzI~
    }                                                              //~v57HI~
	*Pnewrepeat=repeat;                                            //~v0c2M~
	*Pmovelen=len;                                                 //~v0c2M~
    return 0;                                                      //~v0c2M~
}//lcmdovfchk                                                      //~v0c2M~
                                                                   //~v0c2M~
//**************************************************************** //~v0c2M~
//!lcmdrshift                                                      //~v0c2M~
// 	shift right                                                    //~v0c2M~
//*parm1:plh                                                       //~v0c2M~
//*parm2:pos                                                       //~v0c2M~
//*parm3:shift count                                               //~v0c2M~
//*parm4:move len                                                  //~v0c2M~
//*parm5:oomlen                                                    //~v0c2M~
//*rc   :0, 4 bypass process                                       //~v0c2M~
//**************************************************************** //~v0c2M~
int lcmdrshift(PULINEH Pplh,int Ppos,int Pshift,int Plen,int Poomlen)//~v0c2M~
{                                                                  //~v0c2M~
	int len;                                                       //~v0c2M~
    UCHAR *pc,*pcd;                                                //~v0c2M~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************                                                //~v0c2M~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PLH_ISEBC(Pplh);                                     //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
   	filetabclear(Pplh);//tab clear                                 //~v0c2M~
    lcmddbcssplit(Pplh,Ppos);//dbcs split clear befor shift        //~v0c2M~
	if (!Poomlen)	//no mergin                                    //~v0c2M~
    {                                                              //~v0c2M~
		len=Pshift+Plen+Ppos;                                      //~v0c2M~
    	if (len>Pplh->ULHbufflen)                                  //~v0c2M~
        {                                                          //~v0c2M~
    		if (fileexpandbuff(Pplh,len)==UALLOC_FAILED)           //~v0c2M~
    		 	return UALLOC_FAILED;                              //~v0c2M~
    	}                                                          //~v0c2M~
		Pplh->ULHlen=len;                                          //~v0c2M~
	}                                                              //~v0c2M~
	pc=Pplh->ULHdata+Ppos;                                         //~v0c2M~
	memmove(pc+Pshift,pc,(UINT)Plen);                              //~v0c2M~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	UCVEBC_memset_space(swebcfile,pc,(UINT)Pshift);                //~va50I~
#else                                                              //~va50I~
	memset(pc,' ',(UINT)Pshift);                                   //~v0c2M~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	pcd=Pplh->ULHdbcs+Ppos;	//once displayed                       //~v0c2M~
	memmove(pcd+Pshift,pcd,(UINT)Plen);                            //~v0c2M~
	memset(pcd,0,(UINT)Pshift);                                    //~v0c2I~
    return 0;                                                      //~v0c2M~
}//lcmdrshift                                                      //~v0c2M~
//*****************************************************************//~va7jM~
//*set dd fmt for ebc/utf8 file for non ascii lcmd ("+" lcmd       //~va7jM~
//*rc:1 traslation donw                                            //~va7jM~
//*****************************************************************//~va7jM~
int filecvlcmd(int Popt,PUFILEH Ppfh,UCHAR *Pdddata,UCHAR *Pdddbcs,UCHAR *Plcmd,int Plen)//~va7jM~
{                                                                  //~va7jM~
	int handle,opt,ddlen,swutf8file,swebcfile,outlen;              //~va7jR~
    UCHAR *pdddata,*pdddbcs;                                       //~va7jM~
//************************                                         //~va7jM~
    memcpy(Pdddata,Plcmd,(UINT)Plen);                              //~va7jM~
	swebcfile=PFH_ISEBC(Ppfh);                                     //~va7jM~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va7jM~
    handle=Ppfh->UFHhandle;                                        //~va7jI~
    if (!swebcfile && !swutf8file)                                 //~va7jM~
    	return 0;                                                  //~va7jM~
    if (utfddisasciistr(0,Plcmd,0/*dbcs*/,Plen)==Plen)//no dbcs input allowed//~va7jI~
    {                                                              //~va7jI~
    	if (Popt & FCLCO_2FILE)	//from lcmdcom ;set to plhdata     //~va7jI~
        {                                                          //~va7jI~
			UCVEBC_a2bfld(swebcfile,handle,Pdddata,Plen);	//cv a2b if ebcfile//~va7jI~
        }                                                          //~va7jI~
    	return 0;                                                  //~va7jI~
    }                                                              //~va7jI~
//not ascii                                                        //~va7jI~
    opt=0;                                                         //~va7jM~
	xeutfcvl2dd(opt,Plcmd,Plen,&pdddata,&pdddbcs,&ddlen);          //~va7jM~
    if (!ddlen)                                                    //~va7jM~
    	return 0;                                                  //~va7jM~
    if (Popt & FCLCO_2FILE)	//from lcmdcom ;set to plhdata         //~va7jI~
    {                                                              //~va7jI~
		if (swebcfile)                                             //~va7jI~
        {                                                          //~va7jI~
        	opt=XEEBCO_DD2B;                                       //~va7jI~
			xeebc_m2bsrchstr(opt,handle,pdddata,pdddbcs,ddlen,Pdddata,Pdddbcs,Plen,&outlen);//~va7jR~
        }                                                          //~va7jI~
        else    //utf8 file                                        //~va7jI~
        {                                                          //~va7jI~
    		memcpy(Pdddata,pdddata,(UINT)ddlen);                   //~va7jI~
    		memcpy(Pdddbcs,pdddbcs,(UINT)ddlen);                   //~va7jI~
        }                                                          //~va7jI~
    }                                                              //~va7jI~
    else    //from file23, set to psd                              //~va7jI~
    {                                                              //~va7jI~
    	memcpy(Pdddata,pdddata,(UINT)ddlen);                       //~va7jR~
    	memcpy(Pdddbcs,pdddbcs,(UINT)ddlen);                       //~va7jR~
    }                                                              //~va7jI~
    return 1;                                                      //~va7jM~
}                                                                  //~va7jM~
