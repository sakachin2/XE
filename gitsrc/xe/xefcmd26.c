//*CID://+vbr1R~:                             update#=  847;       //~vbc1R~//+vbr1R~
//*************************************************************
//*xefcmd2.c                                                       //~v53FR~
//*  find/change/exclude                                           //~v11kR~
//****************************************************************////~v438R~
//vbr1:200615 ARM compiler warning                                 //+vbr1I~
//vbc2:170821 add TS   option for find cmd on dirlist              //~vbc2I~
//vbc1:170820 add ATTR option for find cmd on dirlist              //~vbc1I~
//vb5c:160917 (Bug)"find all" loop when not lomg name mode and match with overriden part by attr fld.//~vb5cI~
//vb40:160717 when LFN=OFF,invalid find position on dirlist        //~vb40I~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2p:160203 LNX compiler warning                                 //~vb2pI~
//vb2o:160203 try to malloc UDHname for performance(#ifndef MMM)   //~vb2oI~
//vauF:140316 (Win)find on dirlist by ddstrsrch(LNX:vaui)          //~vauFI~
//vaui:140311 find on dirlist by ddstrsrch                         //~vauiI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va7w:100825 (BUG)abend when find -g for ebc file.                //~va7wI~
//va7g:100819 (BUG:EBC) c \x0d " " ;--> insert rep string(wordlen replaced is set to 0)//~va7gI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va6f:100621 F *EC support for not utf8 file (result of cmd copy ebc to lc file)//~va6fI~
//va5R:100524 (BUG)c *= aaa cmd;code conversion required           //~va5RI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va40:100324 allow grep search for utf8 it may not be valid but,it may be effective for ascii data//~va40I~
//va3Q:100321 IFind invalid match for DBCS(ex 8f63 and 8f43)       //~va3QI~
//va3E:100313 (BUG)search on utf8 file(ddstr) fail near the line top//~va3EI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            fcmd26.c:search on dd str                            //~va20I~
//va1G:091118 (UTF8)add UTF8 trans err char Find/Change function   //~va1GI~
//va00:090711 Unicode find option  U[B|L] (Big/Little Endian,default is OS endian)//~va00R~
//          find by locale code                                    //~va00I~
//v79L:081020 change cmd support P'..' fmt as target string specification(=(same),<(lower),>(upper) is special char)//~v79LI~
//v78q:080322 REGEXSUPP for win/lnx                                //~v78qI~
//v78d:080308 screen grep support                                  //~v78dI~
//v74E:070315 BOUNDS cmd support                                   //~v74EI~
//v73s:070125 (BUG)change cmd:tab padding remain after tab is replace as matched as space//~v73sI~
//v73r:070124 (BUG)change cmd:for marging file string near margin is dropped when expand replace is absorbed by tab//~v73rI~
//v73d:070111*split fcmd2 to fcmd25 fcmd26                         //~v73dI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ualloc.h>                                             //~5318I~
#ifdef W32                                                         //~vbc1I~
    #include <dos.h>                                               //~vbc1I~
#endif                                                             //~vbc1I~
#ifdef UNX                                                         //~vbc1I~
	#include <sys/stat.h>                                          //~vbc1I~
#endif                                                             //~vbc1I~

//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <uerr.h>
#include <uparse.h>                                                //~v0b2R~
#include <ustring.h>                                               //~v0b2I~
#include <ufile.h>                                              //~5318R~
#include <uedit.h>                                                 //~v09LI~
#include <utrace.h>                                                //~v11nI~
#ifdef UTF8SUPPH                                                   //~va1GI~
#include <udbcschk.h>                                              //~va1GI~
#endif                                                             //~va1GI~
#include <ucvebc.h>                                                //~va50I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefile.h"
#include "xefile2.h"                                               //~v0avI~
#include "xefile3.h"                                            //~v013I~
#include "xefile42.h"                                              //~v0bvR~
#include "xefile6.h"                                               //~v0avI~
#include "xedir.h"                                              //~v05wI~
#include "xedir2.h"                                                //~v481I~
#include "xedir3.h"                                                //~v182R~
#include "xechar.h"                                             //~5124I~
#include "xechar12.h"                                              //~v0dvI~
#include "xelcmd.h"
#include "xelcmd2.h"
#include "xelcmd4.h"       //join                                  //~v539I~
#include "xefcmd2.h"
#include "xefcmd22.h"                                              //~v0ewI~
#include "xefcmd23.h"                                              //~v13pI~
#include "xefcmd24.h"	//x =all                                   //~v40pI~
#include "xefcmd27.h"	//x =all                                   //~v78dI~
#include "xefcmd5.h"	//x =all                                   //~v50vI~
#include "xefunc.h"
#include "xefunc2.h"  	//funccmdstack                             //~v0hdI~
#include "xefunct.h"                                               //~v09dI~
#include "xeundo.h"                                             //~5106I~
#include "xesub.h"                                              //~5318R~
#include "xefsub.h"                                             //~5318I~
#include "xeerr.h"                                              //~v033I~
#include "xegbl.h"                                                 //~va3QI~
#ifdef UTF8SUPPH                                                   //~va1GR~
#include "xeopt.h"                                                 //~va1GR~
#include "xeutf2.h"                                                //~va3QI~
#endif                                                             //~va1GR~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
#ifdef UTF8SUPPH                                                   //~va1GR~
	static int Sutf8echsrchsw;                                     //~va1GR~
#endif                                                             //~va1GR~
#ifdef UTF8UCS2                                                    //~va20I~
	static int Sddstrlen,Sucswordlen;                              //~va20R~
    static UCHAR *Spddstr,*Spdddbcs;                                      //~va20R~//~va50R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	static int Sebcstrlen;                                         //~va50R~
    static UCHAR *Spebcstr,*Spebcdbcs;                             //~va50I~
    static int Srcsosi;                                            //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//#ifdef LNX                                                         //~vauiI~//~vauFR~
	int Sdirsrchlen;                                               //~vauiI~
//#endif                                                             //~vauiI~//~vauFR~
static int Sdirattr;                                               //~vbc1I~
static int Sdirts;                                                 //~vbc2I~
//****************************************************************
int linesrchstringsub(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Plocatesw,//~v73dI~
					int Pchangeopt,int Psubcmdid);                 //~v73dI~
int wordrep(PUCLIENTWE Ppcw,PULINEH Pplh,int Poffset);             //~v73dI~
int wordrepp(UCHAR *Ptgt,UCHAR *Ppattern,int Ptgtlen,int Ppatternlen);//~v79LI~
int fcmdallxchk(PULINEH Pplh,PULINEH Pspanplh,PULINEH Psamelastplh,PULINEH Psnaplh1,int Plinebefore,int Plineafter);//~v73dI~
int fcmdaroundline(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh,PULINEH Psamelastplh,//~v73dI~
                    int Plinebefore,int Plineafter,int Pexcludesw2,int *Ppoffs);//~v73dI~
int fcmdaroundlinesub(PULINEH Pplh,PULINEH Psamelastplh,           //~v73dI~
					int Plinebefore,int Plineafter,PULINEH *Pplh1,PULINEH *Pplh2);//~v73dI~
int fcmdspannedline(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PULINEH Pspannedplh,//~v73dI~
					PULINEH Psamelastplh,int Psubcmdid,            //~v73dI~
					int Pexcludesw2,int Plocatesw);                //~v73dI~
char *fcmdstrnstri(int Popt,char *Pdata,char *Pkey,int Pmaxlen);   //~va3QI~
#define FCSIO_MEMLEN   0x01     //memstri                          //~va3QR~
#define FCSIO_REV      0x02     //reverse search                   //~va3QR~
//#ifdef LNX                                                         //~vauiI~//~vauFR~
	char *fcmdddstrsrch_dirfnm(int Popt,PUDIRLH Ppdh,int Pboundary2,int *Ppoffs);//~vauiR~
	#define  FCMDDDSSDO_NEXT   0x01                                //~vauiI~
	#define  FCMDDDSSDO_PREV   0x02                                //~vauiI~
//#endif                                                             //~vauiI~//~vauFR~
int fcmdfind_dirattr(int Popt,int Psubcmdid,PUCLIENTWE Ppcw,PUDIRLH Ppdh,PUDIRLD Ppdd,int Pnameoffs,int Pexpandlen,char *Psrch,int *Ppoffset,int *Ppdirstep,int *Ppdirstepr);//~vbc1R~
int fcmdfind_dirts(int Popt,int Psubcmdid,PUCLIENTWE Ppcw,PUDIRLH Ppdh,PUDIRLD Ppdd,int Pexpandlen,char *Psrch,int *Ppoffset,int *Ppdirstep,int *Ppdirstepr);//~vbc2I~
//**************************************************************** //~va3QI~
//!strnstri for dbcs                                               //~va3QI~
//**************************************************************** //~va3QI~
char *fcmdstrnstri(int Popt,char *Pdata,char *Pkey,int Pmaxlen)    //~va3QR~
{                                                                  //~va3QI~
	int len,lendbcs,lenkey;                                        //~va3QR~
    char *pc;                                                      //~va3QI~
    char wkdbcs[MAXCOLUMN]; //max key len                          //~va3QR~
//**********************                                           //~va3QI~
	if (Popt & FCSIO_MEMLEN)    //memstri                          //~va3QI~
		if (Popt & FCSIO_REV)    //memstri                         //~va3QI~
//  		pc=umemrstri(Pdata,Pkey,Pmaxlen);                      //~va3QI~//~vb2pR~
    		pc=umemrstri(Pdata,Pkey,(UINT)Pmaxlen);                //~vb2pI~
        else                                                       //~va3QI~
//			pc=umemstri(Pdata,Pkey,Pmaxlen);                       //~va3QI~//~vb2pR~
  			pc=umemstri(Pdata,Pkey,(UINT)Pmaxlen);                 //~vb2pI~
    else                                                           //~va3QI~
		if (Popt & FCSIO_REV)    //memstri                         //~va3QI~
//  		pc=ustrnrstri(Pdata,Pkey,Pmaxlen);                     //~va3QI~//~vb2pR~
    		pc=ustrnrstri(Pdata,Pkey,(UINT)Pmaxlen);               //~vb2pI~
        else                                                       //~va3QI~
//  		pc=ustrnstri(Pdata,Pkey,Pmaxlen);                      //~va3QR~//~vb2pR~
    		pc=ustrnstri(Pdata,Pkey,(UINT)Pmaxlen);                //~vb2pI~
    if (!pc || !XE_ISDBCSKON())                                    //~va3QI~
        return pc;                                                 //~va3QI~
	if (Popt & FCSIO_MEMLEN)    //memstri                          //~va3QI~
    	len=Pmaxlen;                                               //~va3QI~
    else                                                           //~va3QI~
//  	len=strlen(Pdata);                                         //~va3QR~//~vb2pR~
    	len=(int)strlen(Pdata);                                    //~vb2pI~
//  lenkey=strlen(Pkey);                                           //~va3QI~//~vb2pR~
    lenkey=(int)strlen(Pkey);                                      //~vb2pI~
//  lendbcs=min(lenkey,sizeof(wkdbcs));                            //~va3QR~//~vb2pR~
    lendbcs=min(lenkey,(int)sizeof(wkdbcs));                       //~vb2pI~
    setdbcstbl(Pkey,wkdbcs,lendbcs);                               //~va3QR~
	if (Popt & FCSIO_REV)    //memstri                             //~va3QI~
		pc=umemrstridbcs(UMRSIDO_KEYDBCS,Pdata,wkdbcs,Pkey,len);   //~va3QR~
    else                                                           //~va3QI~
		pc=umemstridbcs(UMSIDO_KEYDBCS,Pdata,wkdbcs,Pkey,len);     //~va3QR~
    return pc;                                                     //~va3QI~
}//fcmdstrnstri                                                    //~va3QI~
//****************************************************************
//!linesrchstring
//search string                                                    //~v43cR~
//* parm1 :pcw
//* parm2 :plh search start,at return found plh
//* parm3 :record offset to search start,at return found offset
//* parm4 :advance step byte count before search(for next srch only)//~4C30R~
//* parm5 :all sw(1:1st time,move csr  0:2nd call)              //~4C30I~
//* parm6 :subcmdid                                             //~5302R~
//*rc   :0:found,4:not found,8:rep err                          //~5107R~
//****************************************************************
int linesrchstring(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Plocatesw,//~5114R~
					int Pchangeopt,int Psubcmdid)               //~5302R~
{
	int rc,offset,svoffset;                                        //~v43eR~
    PULINEH plh,svplh;                                             //~v43eR~
    PUFILEH pfh;                                                   //~va00I~
    int ii,svsrchlen,nextplhsw,stepline;                           //~v43sR~
	int  rangeerr2,notfound1;    //2nd word not found in the distance//~v49eR~
	int  notfound2;              //2nd word search reached to eof  //~v53FI~
    char svtabsrchsw,svescsrchlen,svulsrchsw;                      //~v43qR~
    char svnotsrchsw;                                              //~v43wI~
    char sveolsrchsw;                                              //~v47BI~
	char svsrch[MAXCOLUMN],svescsrchchar[MAXCOLUMN];               //~v43eR~
    int  svdirstep,svdirstepr;                                     //~v51sI~
    SHORT svrange1,svrange2;                                       //~v532I~
    SHORT svrangeid1,svrangeid2;                                   //~v54zI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile=0;                                               //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************                                //~v43cI~
#ifdef UTF8SUPPH                                                   //~va1GR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	if (Ppcw->UCWtype==UCWTFILE)                                   //~va50I~
    {                                                              //~va50I~
       	pfh=UGETPFHFROMPCW(Ppcw);                                  //~va50I~
        swebcfile=PFH_ISEBC(pfh);                                  //~va50I~
    }                                                              //~va50I~
    else                                                           //~va50I~
    	pfh=0;                                                     //~va50I~
    if (swebcfile)  //ebc file has no TAB                          //~va7wI~
    {                                                              //~va7wI~
        if (Sfindopt & (FINDOPT_GREP|FINDOPT_GREPPTARGET))         //~va7wI~
            return errnotsupported("Grep search","EBCDIC file");   //~va7wI~
    }                                                              //~va7wI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (Sothopt & (SEARCH_UTF8ECH|SEARCH_UTF8ECH2))                //~va1GR~
    {                                                              //~va1GR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
#else                                                              //~va50I~
	  	if (Ppcw->UCWtype==UCWTFILE)                               //~va1GR~
        	pfh=UGETPFHFROMPCW(Ppcw);                              //~va1GR~
        else                                                       //~va1GR~
        	pfh=0;                                                 //~va1GR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef AAA                                                         //~va6fI~
        if (!pfh                                                   //~va1GR~
      	||  UCBITCHK(pfh->UFHflag4,UFHF4BIN)                       //~va1GR~
      	||  !UCBITCHK(pfh->UFHflag8,UFHF8UTF8)   //not utf8 file   //~va1GR~
      	)                                                          //~va1GR~
        {                                                          //~va1GR~
			uerrmsg("%s option is for %s text file only.",         //~va1GR~
					"%s オプションは %s テキストファイル用です。", //~va1GR~
					SRCHIDS_UTF8ECH,MODE_UTF8);                    //~va1GR~
			return 4;					//no client space          //~va1GR~
        }                                                          //~va1GR~
#endif //AAA                                                       //~va6fI~
    }                                                              //~va1GR~
#endif                                                             //~va1GR~
	Sfindcmdinpctr=Gkbdinpctr;                                     //~v62dI~
	Splhafter=0;                                                   //~v54VI~
    Sandplh1=0;                                                    //~v54VI~
	for (;;)                                                       //~v43cI~
	{                                                              //~v43cI~
	    Sscrollpendsw=0;	//set when 1st word found              //~v54WI~
		Sallxfound=0;   //retry req                                //~v43cI~
		Srangeplhe2=0;	//search in  the distance line             //~v43eI~
        nextplhsw=0;                                               //~v43eI~
#ifdef UTF8SUPPH                                                   //~va1GR~
        Sutf8echsrchsw=Sothopt & SEARCH_UTF8ECH;	//1st word is *ec//~va1GR~
#endif                                                             //~va1GR~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	  Sebcstrlen=0;                                                //~va50I~
      if (swebcfile)                                               //~va50I~
      {                                                            //~va50I~
		if (fcmdgetebcsrchstr(0,Ppcw,&Spebcstr,&Spebcdbcs,&Sebcstrlen)>1)//~va50R~
        	return 4;                                              //~va50I~
        Sddstrlen=0;                                               //~va50I~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		Sddstrlen=fcmdisddsrch(0,Ppcw,&Spddstr,&Spdddbcs);         //~va20R~
#endif                                                             //~va20I~
//    if (Ssrchlen2)             //*&                              //~v54zR~
      if (Ssrchlen2||Seolsrchsw2)//*&                              //~v54zI~
      {                                                            //~v43eI~S
            Sdirattr=Sfindopt & FINDOPT_DIRATTR;                   //~vbc1I~
            Sdirts=Sfindopt & FINDOPT_DIRTS;                       //~vbc2I~
      		Sandplh1=0;                                            //~v43eI~
            Sphasesw=1;                                            //~v43eI~
            notfound2=0;                                           //~v53FI~
            notfound1=                                             //~v49eI~
            rc=linesrchstringsub(Ppcw,Ppplh,Ppoffset,Plocatesw,Pchangeopt,Psubcmdid);//~v43eI~
            if (rc==UALLOC_FAILED)                                 //~v54BI~
                return UALLOC_FAILED;                              //~v54BI~
            if (rc==RC_STOP_SRCH)                                  //~v612R~
                return RC_STOP_SRCH;                               //~v612R~
            if (!rc)    //1st word found                           //~v43eI~
            {                                                      //~v43eI~
	      		Sandplh1=*Ppplh;                                   //~v43eI~
                memcpy(svsrch,Ssrch,sizeof(svsrch));               //~v43eI~
                memcpy(svescsrchchar,Sescsrchchar,sizeof(svescsrchchar));//~v43eR~
                svsrchlen=Ssrchlen;                                //~v43eI~
                svescsrchlen=Sescsrchlen;                          //~v43eI~
                svtabsrchsw=Stabsrchsw;                            //~v43eI~
                svnotsrchsw=Snotsrchsw;                            //~v43wR~
                sveolsrchsw=Seolsrchsw;                            //~v47BI~
                svrange1=Srange1;                                  //~v532I~
                svrange2=Srange2;                                  //~v532I~
                svrangeid1=Srangeid1;                              //~v54zI~
                svrangeid2=Srangeid2;                              //~v54zI~
                svdirstep=Sdirstep;    //step count for dir fwdsrch//~v51sI~
                svdirstepr=Sdirstepr;  //step count for dir bwdsrch//~v51sI~
                                                                   //~v43eI~
                memcpy(Ssrch,Ssrch2,sizeof(svsrch));               //~v43eI~
                memcpy(Sescsrchchar,Sescsrchchar2,sizeof(svescsrchchar));//~v43eR~
                Ssrchlen=Ssrchlen2;                                //~v43eI~
                Sescsrchlen=Sescsrchlen2;                          //~v43eI~
                Stabsrchsw=Stabsrchsw2;                            //~v43eI~
#ifdef UTF8SUPPH                                                   //~va1GR~
		        Sutf8echsrchsw=Sothopt & SEARCH_UTF8ECH2; //2nd word is *ec//~va1GR~
#endif                                                             //~va1GR~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      		  if (swebcfile)                                       //~va50I~
              {                                                    //~va50I~
				if (fcmdgetebcsrchstr(SEARCH_AND,Ppcw,&Spebcstr,&Spebcdbcs,&Sebcstrlen)>1)//~va50R~
                	return 4;                                      //~va50I~
                Sddstrlen=0;                                       //~va50I~
              }                                                    //~va50I~
      		  else                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
				Sddstrlen=fcmdisddsrch(SEARCH_AND,Ppcw,&Spddstr,&Spdddbcs);//~va20I~
#endif                                                             //~va20I~
                Snotsrchsw=Snotsrchsw2;                            //~v43wR~
                Seolsrchsw=Seolsrchsw2;                            //~v47BI~
                Srange1=Srange1and;                                //~v532I~
                Srange2=Srange2and;                                //~v532I~
                Srangeid1=Srangeid1and;                            //~v54zI~
                Srangeid2=Srangeid2and;                            //~v54zI~
                                                                   //~v43eI~
          		if (Sfindopt & FINDOPT_DISTOUT)                    //~v43iI~
                	stepline=Slinedist+1;	//stop plh is next line//~v43iI~
                else                                               //~v43iI~
                	stepline=Slinedist;		//start plh is the count line//~v43iI~
                for (ii=0,plh=Sandplh1;ii<stepline;)	//search range by /dn option//~v43iI~
                {	//endplh is not searched(next of label plh)    //~v43eR~
                	plh=UGETQNEXT(plh);                            //~v43eR~
                    if (!plh)                                      //~v43eI~
                    	break;                                     //~v43eI~
    				if (plh->ULHtype==ULHTDATA)                    //~v43eI~
                    	ii++;                                      //~v43eI~
                }                                                  //~v43eI~
//              Srangeerr2=0;       //clear out of range of 2nd word//~v49eR~
                rangeerr2=0;       //clear out of range of 2nd word//~v49eI~
                svplh=*Ppplh;                                      //~v43eI~
                svoffset=*Ppoffset;	//for the case 2nd word not found//~v43eI~
                if (Sfindopt & FINDOPT_DISTIN)                         //~v43iI~
                    Srangeplhe2=plh;    //search in  the distance line //~v43iM~
                else                                                   //~v43iI~
                {                                                      //~v43iI~
                    if (plh)//reached to eof                           //~v43iI~
                    {                                                  //~v43iI~
                        *Ppplh=plh;                                    //~v43iI~
                      if (Sulsrchsw2)                              //~v634I~
                        *Ppoffset=OFFS_ULNEXT;  //avoid step 1 line//~v634I~
                      else                                         //~v634I~
                        *Ppoffset=0;                                   //~v43iI~
                        if (!(Sfindopt & FINDOPT_DISTOUT))             //~v43iI~
                            Srangeplhe2=UGETQNEXT(plh); //search in  the distance line//~v43iI~
                    }                                                  //~v43iI~
                    else                                               //~v43iI~
//                      Srangeerr2=1;       //search start line is not found in dist//~v49eR~
                        rangeerr2=1;       //search start line is not found in dist//~v49eI~
                }//DISTIN                                                      //~v43iI~
//              if (Srangeerr2) //not dist line count err          //~v49eR~
                if (rangeerr2) //not dist line count err           //~v49eI~
                    rc=4;                                              //~v43iI~
                else                                                   //~v43iI~
                {                                                      //~v43iI~
            		Sdirattr=Sfindopt & FINDOPT_DIRATTRAND;        //~vbc1I~
            		Sdirts=Sfindopt & FINDOPT_DIRTSAND;            //~vbc2I~
                    Sphasesw=2;                                        //~v43iI~
                    svulsrchsw=Sulsrchsw;                              //~v43qI~
//                  Sulsrchsw=0;           //2nd word should not be *u/*e//~v634R~
                    Sulsrchsw=Sulsrchsw2;  //support for *G & *G case//~v634I~
                    notfound2=                                     //~v53FI~
                    rc=linesrchstringsub(Ppcw,Ppplh,Ppoffset,0,0,SUBCMD_NEXT);//no locatesw,no chng//~v43eR~
                    if (rc==UALLOC_FAILED)                         //~v54BI~
                        return UALLOC_FAILED;                      //~v54BI~
                    if (rc==RC_STOP_SRCH)                          //~v612R~
                        return RC_STOP_SRCH;                       //~v612R~
                    Sulsrchsw=svulsrchsw;                              //~v43qI~
                    if (rc) //not found                            //~v49eI~
      				if (Srangeplhe2 && Ssrcherrplh==Srangeplhe2)   //~v49eI~
        				rangeerr2=1;                               //~v49eI~
                }                                                      //~v43iI~
                memcpy(Ssrch,svsrch,sizeof(svsrch));               //~v43eI~
                memcpy(Sescsrchchar,svescsrchchar,sizeof(svescsrchchar));//~v43eR~
                Ssrchlen=svsrchlen;                                //~v43eI~
                Sescsrchlen=svescsrchlen;                          //~v43eI~
                Stabsrchsw=svtabsrchsw;                            //~v43eI~
#ifdef UTF8SUPPH                                                   //~va1GR~
		        Sutf8echsrchsw=Sothopt & SEARCH_UTF8ECH; //restore 1st word is *ec//~va1GR~
#endif                                                             //~va1GR~
                Snotsrchsw=svnotsrchsw;                            //~v43wI~
                Seolsrchsw=sveolsrchsw;                            //~v47BI~
                Srange1=svrange1;                                  //~v532I~
                Srange2=svrange2;                                  //~v532R~
                Srangeid1=svrangeid1;                              //~v54zI~
                Srangeid2=svrangeid2;                              //~v54zI~
                Sdirstep=svdirstep;    //step count for dir fwdsrch//~v51sI~
                Sdirstepr=svdirstepr;  //step count for dir bwdsrch//~v51sI~
//              if (Srangeerr2)                                    //~v49eR~
                if (rangeerr2)                                     //~v49eI~
                {                                                  //~v43eI~
                	nextplhsw=1;	//serach 1st word from next plh//~v43eI~
                    *Ppplh=svplh;                                  //~v43eI~
                    *Ppoffset=svoffset;                            //~v43eI~
                }                                                  //~v43eI~
            	if (!rc)	//2nd word found                       //~v54WR~
                	if (Sscrollpendsw)                             //~v54WI~
//              		fcmdscrollpagemid(Ppcw,Sandplh1);          //~v59ZR~
                		fcmdfindscroll(Ppcw,Sandplh1,Sfindopt2);   //~v59ZI~
            }//1st word found                                                      //~v43eI~
            Sphasesw=0;                                            //~v43eI~
            if (notfound1)                                         //~v49eR~
	    		fcmdsrcherr(Pchangeopt,Plocatesw,Psubcmdid,Ssrcherrplh);//msg after Ssrch recovery//~v49eR~
            else                                                   //~v53FR~
            if (notfound2)                                         //~v53FR~
	    		fcmdsrcherr(Pchangeopt,0,Psubcmdid,Ssrcherrplh);//0:avoid set notfound ctr//~v53FI~
      }                                                            //~v43eI~
      else                                                         //~v43eI~
      {                                                            //~v54BI~
            Sdirattr=Sfindopt & FINDOPT_DIRATTR;                   //~vbc1I~
            Sdirts=Sfindopt & FINDOPT_DIRTS;                       //~vbc2I~
		rc=linesrchstringsub(Ppcw,Ppplh,Ppoffset,Plocatesw,Pchangeopt,Psubcmdid);//~v43cI~
        if (rc==UALLOC_FAILED)                                     //~v54BI~
            return UALLOC_FAILED;                                  //~v54BI~
        if (rc==RC_STOP_SRCH)                                      //~v612R~
            return RC_STOP_SRCH;                                   //~v612R~
      }                                                            //~v54BI~
                                                                   //~v43eI~
      if (!nextplhsw)    //not 2nd word search err                 //~v43eI~
		if (!Sallxfound)                                           //~v43cM~
        	break;                                                 //~v43cM~
//search next when all line is excluded for x cmd                  //~v43eI~
        plh=*Ppplh;                                                //~v43cI~
        offset=*Ppoffset;                                          //~v43cI~
//      if (Snotsrchsw)  //not srch                                //~v43sR~
//      if (Snotsrchsw||Ssrchlen2)  //not srch                     //~v54zR~
        if (Snotsrchsw||Ssrchlen2||Seolsrchsw2)  //not srch        //~v54zI~
        {                                                          //~v43cI~
            if (Ssubcmdid==SUBCMD_PREV) //backword                 //~v43cI~
            {                                                      //~v43cI~
                plh=UGETQPREV(plh);                                //~v43cI~
                offset=plh->ULHlen;                                //~v43cI~
            }                                                      //~v43cI~
            else                                                   //~v43cI~
            {                                                      //~v43cI~
                plh=UGETQNEXT(plh);                                //~v43cI~
                offset=0;                                          //~v43cI~
            }                                                      //~v43cI~
        }//*!                                                      //~v43cI~
        else                                                       //~v43cI~
            if (Ssubcmdid!=SUBCMD_PREV) //backword                 //~v43cI~
				offset+=Ssrchlen;   //find word len or rep word len//~v43cR~
        *Ppplh=plh;                                                //~v43cI~
        *Ppoffset=offset;                                          //~v43cI~
	}                                                              //~v43cI~
    if (Plocatesw) //1st time                                      //~v614R~
    	fcmdothererrmsgcat(0);                                     //~v614R~
    return rc;                                                     //~v43cI~
}//linesrchstring                                                  //~v43cI~
//**************************************************************** //~v43cI~
int linesrchstringsub(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Plocatesw,//~v43cI~
					int Pchangeopt,int Psubcmdid)                  //~v43cI~
{                                                                  //~v43cI~
//#define DIRRMSTART (offsetof(UDIRLD,UDDattrflag))                //~v182R~
    int fnmboundary;                                               //~v182R~
	int offset,wordlen;                                         //~5106R~
	int width,rc,scrollsz;                                      //~v013R~
    int level;                                                     //~v0fhR~
    int linenosz;                                                  //~v09eI~
    int offset0,srchlen;                                           //~v0eBI~
    int dirindentsw=0;                                               //~v0fhR~//~vaf9R~
    int dirskipsw;                                                 //~v10oI~
    int fatsw=0;                                                     //~v0f7I~//~vaf9R~
    int boundary1,boundary2;                                       //~v0fhI~
    int len;                                                       //~v0fhI~
    int skipxsw;                                                   //~v10oI~
    int multlinexsw;                                               //~v43cI~
    int leftpos;                                                   //~v43dI~
    int spacesw=0,binfsw;                                            //~v13oR~//~vaf9R~
    int splitsrchlen;                                              //~v13pI~
    int linesrchsw;                                                //~v41rI~
    int eoloffset;                                                 //~v47BI~
    int llfoundsw;                                                 //~v496I~
    int samesrchrc;                                                //~v49bI~
    int joineofsw=0;                                               //~v58rI~
    int samepartctr;                                               //~v58ZI~
    int expandlen;                                                 //~v59TI~
    int csrpos;                                                    //~v59ZI~
//  int grepsw,matchlen=0;                                         //~v78dR~//~vaf9R~
    int grepsw=0,matchlen=0;                                       //~vaf9I~
	UCHAR *splitsrch=NULL;                                              //~v13pI~//~vaf9R~
	UCHAR *pc,*pc0;                                                //~v0hxR~
    UCHAR *pc2;                                                    //~v083I~
    UCHAR *pcd;                                                    //~v0eBI~
    UCHAR *wordend;		//spaned word next addr                    //~v13pI~
	PUFILEH pfh;
	PULINEH plh;                                                //~5104R~
	PULINEH plhw;                                                  //~v0hzI~
	PULINEH plhsames,plhsamee,plhsamerep;                          //~v49bR~
	PULINEH wordplh;		//next/prev of spaned line             //~v13pI~
	PUFILEC pfc;
	PUDIRLH pdh;                                                //~v05wI~
	PUDIRLD pdd;                                                //~v05wI~
#ifdef UTF8UCS2                                                    //~va20R~
    int swutf8file,ucswordlen=0,optdds;                            //~va20R~
    int optescdd;                                                  //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50R~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef MMM                                                         //~vb2oI~
#else                                                              //~vb2oI~
	int udhnamelen;                                                //~vb2oI~
#endif                                                             //~vb2oI~
//*****************
#ifdef UTF8SUPPH                                                   //~va1GR~
	if (Sutf8echsrchsw) //search utf8 trans err char               //~va1GR~
        Ssrchlen=1;                                                //~va1GR~
#endif                                                             //~va1GR~
//#ifdef LNX                                                         //~vauiI~//~vauFR~
    Sdirsrchlen=0;	//for highlight word length                    //~vauiI~
//#endif                                                             //~vauiI~//~vauFR~
    linesrchsw=Sulsrchsw||Snotsrchsw;  //not word but line search  //~v41rI~
    Sspanplh=0;                                                    //~v13pR~
    Ssamelastplh=0;                                                //~v49bI~
//	Sdirstep=0;                                                    //~v084R~
	pfc=Ppcw->UCWpfc;                                              //~v0f7M~
    expandlen=pfc->UFCexpandlen;                                   //~v59TR~
	pfh=pfc->UFCpfh;                                               //~v0f7M~
	binfsw=UCBITCHK(pfh->UFHflag4,UFHF4BIN);                       //~v13oI~
#ifdef UTF8UCS2                                                    //~va20R~
    swutf8file=FILEUTF8MODE(pfh);                                  //~va20R~
    handle=pfh->UFHhandle;                                         //~va79I~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    linenosz=Ppcw->UCWlinenosz;                                    //~v09eI~
//    if (!Gfilemfwtbl)                                            //~v43hR~
//    {                                                            //~v43hR~
////      Gfilemfwtbl=UALLOCM((MAXMFWTENTRY+3)*sizeof(USHORT));    //~v43hR~
//        Gfilemfwtbl=UALLOCM((MAXMFWTENTRY*2+2)*sizeof(USHORT));  //~v43hR~
//        UALLOCCHK(Gfilemfwtbl,8);    //return if malloc err      //~v43hR~
//    }                                                            //~v43hR~
//  if (Ppcw->UCWheight<=FILEHDRLINENO                             //~v11NR~
    if (Ppcw->UCWheight<=Ppcw->UCWfilehdrlineno                    //~v11NI~
	||  Ppcw->UCWwidth<=Ppcw->UCWlinenosz)                      //~v069R~
		return 4;					//no client space
	Sexcludesw2=Sexcludesw;			//deny exclude,but same by search word//~v0hzI~
    if (Ppcw->UCWtype==UCWTDIR)     //on dir list                  //~v09LR~
    {                                                              //~v0f7I~
	    Sexcludesw2=0;				//deny exclude,but same by search word//~v0hzR~
	    if (Sescsrchlen)                                           //~v09OR~
        {                                                          //~v09LI~
#ifdef UTF8SUPPH   //utfstr cvdata is on Sescsrchchar              //~va00R~
			if (Sothopt & (SEARCH_UCS|SEARCH_UCS2))                //~va00R~
            {                                                      //~va00R~
				uerrmsg("search by unicode is not avail on this panel.",0);//~va00R~
				return 4;                                          //~va00R~
            }                                                      //~va00R~
#else                                                              //~va00R~
			uerrmsg("*\\ search not avail on this panel.",         //~v09LR~
					"この画面で *\\ 探索は出来ません");            //~v09LR~
			return 4;                                              //~v09LI~
#endif                                                             //~va00R~
        }                                                          //~v09LI~
    	dirindentsw=UCBITCHK(Gopt3,GOPT3DIRLISTINDENT);            //~v0f7R~
		fatsw=!UCBITCHK(pfh->UFHflag4,UFHF4LFN);    //long file name//~v0fcR~
        dirskipsw=1;                                               //~v10oI~
//  	if (!fatsw && UCBITCHK(Gdir3status,GDIR3SLFN))  //display long//~v183R~
//  		fnmboundary=(int)offsetof(UDIRLD,UDDrsv2);             //~v183R~
//      else                                                       //~v183R~
//  		fnmboundary=(int)offsetof(UDIRLD,UDDattrflag);         //~v183R~
    }                                                              //~v0f7I~
    else                                                           //~v10oI~
    {       //not dir srch                                         //~v13oI~
        dirskipsw=0;                                               //~v10oI~
        spacesw=0;          //search word has no space             //~v13oI~
        grepsw=Sfindopt & FINDOPT_GREP;                            //~v78dI~
#ifdef UTF8UCS2                                                    //~va20I~
        if (grepsw)                                                //~va20I~
        {                                                          //~va20I~
//          if (swutf8file||binfsw)                                //~va20R~//~va40R~
            if (binfsw)                                            //~va40I~
//      		return errnotsupported("Grep search","Binary or UTF8 file");//~va20I~//~va40R~
        		return errnotsupported("Grep search","Binary file");//~va40I~
        }                                                          //~va20I~
#endif                                                             //~va20I~
        if (!Sulsrchsw     //not update line search                //~v13oR~
#ifdef UTF8SUPPH                                                   //~va1GR~
		&& !Sutf8echsrchsw //word is not *ec                       //~va1GR~
#endif                                                             //~va1GR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        && !swebcfile   //ebc file has no TAB                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        &&  !Stabsrchsw)                                           //~v13oR~
        {                                                          //~v54aI~
//*memchr may over estimate for spacesw,but no effest. it dose only cause filechktabdbcs//~va20I~
            if (Sescsrchlen)                                       //~v13oR~
                spacesw=(memchr(Sescsrchchar,' ',Sescsrchlen)!=0); //~v13oR~
            else                                                   //~v13oR~
                if (Ssrchlen)                                      //~v13oR~
                    spacesw=(memchr(Ssrch,' ',(UINT)Ssrchlen)!=0); //~v13pR~
        }//ulsrch tabsrch                                          //~v54aI~
#ifdef UTF8UCS2                                                    //~va20I~
        if (Pchangeopt && Sescreplen)    //esc search on file scr  //~va20I~
        {                                                          //~va20I~
            optescdd=FCESI_CHANGE;                                 //~va20I~
            if (Plocatesw)                                         //~va20I~
                optescdd|=FCESI_LOCATE;                            //~va20I~
            if (fcmdescsrchinit(optescdd,Ppcw,pfh))                //~va20I~
                return RC_STOP_SRCH;                               //~va20I~
        }                                                          //~va20I~
#endif                                                             //~va20I~
    }                                                              //~v13oI~
	if (Sexcludesw2 			//exclude/iexclude                 //~v0hBR~
//  ||  Sulsrchsw)                                                 //~v41rR~
    ||  linesrchsw)                                                //~v41rR~
    {                                                              //~v0hzI~
      if (!Pchangeopt)                                             //~v49bI~
    	*Srepword=0;Srepnull=0;	//reject rchange after exclude cmd //~v0hzI~
    }                                                              //~v0hzI~
    splitsrchlen=0;                                                //~v43bI~
	if (binfsw                                                     //~v43bI~
    &&  ((int)Srangeid2==RANGENOPARM))                             //~v43bI~
    {                                                              //~v54aI~
      if (Sescsrchlen)                                             //~v43bI~
      {                                                            //~v43bI~
          splitsrchlen=Sescsrchlen;                                //~v43bI~
          splitsrch=Sescsrchchar;                                  //~v43bI~
      }                                                            //~v43bI~
      else                                                         //~v43bI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (Sebcstrlen)                                              //~va50I~
      {                                                            //~va50I~
          splitsrchlen=Sebcstrlen;                                 //~va50I~
          splitsrch=Spebcstr;                                      //~va50I~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
          if (Ssrchlen)     //exclude case                         //~v43bI~
          {                                                        //~v43bI~
              splitsrchlen=Ssrchlen;                               //~v43bI~
              splitsrch=Ssrch;                                     //~v43bI~
          }                                                        //~v43bI~
    }//binfsw                                                      //~v54aI~
//  skipxsw=Sexcludesw2||Snxsw; //skip excluded line if EXC cmd or FNX cmd//~v43cR~
    multlinexsw=Sexcludesw2 && (splitsrchlen || Slinebefore || Slineafter);//~v43cR~
                                   //need multiline consideration  //~v43cI~
//  multlinexsw|=(Sexcludesw2 && Ssamelastplh);                    //~v49dR~
//  skipxsw=Snxsw || (Sexcludesw2 && !multlinexsw);                //~v73dR~
    skipxsw=Gnxsw || (Sexcludesw2 && !multlinexsw);                //~v73dI~
							//x cmd without multiple line consideration//~v43cI~
	plh=*Ppplh;
	offset=*Ppoffset;
//*****************                                                //~va50I~
//*Prev     *******                                                //~va50I~
//*****************                                                //~va50I~
	if (Psubcmdid==SUBCMD_PREV)                                 //~5302R~
	{
      	if (Sulsrchsw)					//update line search       //~v09eI~
      	{                                                            //~v09eI~
          if (Sulsrchsw!=LINE_SAMESRCH)		//*=                   //~v49bR~
//  		if (offset!=2 && plh)			//csr is  not after client area//~v41rR~
    		if (offset!=OFFS_LAST && plh)			//csr is  not after client area//~v41rI~
				plh=UGETQPREV(plh);         //serach from prev line    //~v09eI~
          if (!Slinerangesw)                //already out of range //~v0hxR~
			for (;plh;plh=UGETQPREV(plh))                              //~v09eI~
            {                                                      //~v0hxR~
                if (plh==Srangeplhe)        //reached to end range //~v0hxR~
                    break;                                         //~v0hxR~
                if (plh==Srangeplhe2)        //reached to end range//~v43eI~
                    break;                                         //~v43eI~
//  			if (Sexcludesw2)                                   //~v10oR~
    			if (skipxsw || dirskipsw)                          //~v10oR~
					if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))     //~v0hzI~
                 		continue;                                  //~v0hzI~
          		if (Sulsrchsw==1)		//*u                               //~v0bqR~
          		{                                                        //~v0bqR~
				  if (plh->ULHupctr)                               //~v41rR~
                  {                                                //~v41rI~
                    if (!Snotsrchsw)  //normal search              //~v41rI~
					break;                                             //~v09eI~
                  }                                                //~v41rI~
                  else                                             //~v41rI~
                    if (Snotsrchsw)   //*! search                  //~v41rI~
    					if (plh->ULHtype==ULHTDATA)                //~v41rR~
							break;        //not updated detected   //~v41rR~
		  		}                                                        //~v0bqR~
          		else                  //*e                         //~v62dI~
          		if (Sulsrchsw==LINE_SAMEMATCH)  	//*= & ^* (matching)//~v62dI~
          		{                                                  //~v62dI~
					samesrchrc=fcmdsamematch(Ppcw,pfh,Spfhmatching,plh,Srangeplhe,//~v62dR~
    								  Scasesensesw,Sexcludesw2,Srange1,Srange2,Sminsame);//~v62fR~
                    if (samesrchrc==UALLOC_FAILED)                 //~v62dI~
                    	return samesrchrc;                         //~v62dI~
                    offset=Srange1;                                //~v62dI~
                    if (samesrchrc!=1)	//data line                //~v62dI~
                    {                                              //~v62dI~
                    	if (samesrchrc)	//not found                //~v62dI~
	                  	{                                          //~v62dI~
    	                	if (Snotsrchsw)  //normal search       //~v62dI~
								break;                             //~v62dI~
                	  	}                                          //~v62dI~
                  		else                                       //~v62dI~
                        {                                          //~v62dI~
                    		if (!Snotsrchsw)   //*! search         //~v62dI~
								break;        //not research linwe //~v62dI~
                        }                                          //~v62dI~
                    }//data line                                   //~v62dI~
		  		}                                                  //~v62dI~
          		else                  //*e                         //~v496I~
          		if (Sulsrchsw==LINE_SAMESRCH)		//*=           //~v49bI~
          		{                                                  //~v49bI~
                	Ssamelinectr=0;	//if not 0,stop search when reached to the count//~v61bI~
					samesrchrc=fcmdsamesrch(Ppcw,pfh,plh,Srangeplhe,&plhsames,&plhsamee,//~v49bR~
//    								  Scasesensesw,Srange1,Srange2,Sminsame,Psubcmdid,0,Sexcludesw2);//~v61bR~
    								  Scasesensesw,Srange1,Srange2,Sminsame,Psubcmdid,&Ssamelinectr,Sexcludesw2);//~v61bI~
				  	if (samesrchrc)       //not found              //~v49bR~
                    {                                              //~v49bI~
                    	plh=0;                                     //~v49bR~
	                    Ssamelastplh=0;                            //~v49bI~
                    }                                              //~v49bI~
                  	else       //found                             //~v49bR~
                    {                                              //~v49bI~
                    	plh=plhsamee;   //endplh is before startplh//~v49bR~
	                    Ssamelastplh=plhsames;//                   //~v49bR~
                        offset=Srange1;                            //~v49bI~
                    }                                              //~v49bI~
                    break;                                         //~v49bI~
		  		}                                                  //~v49bI~
          		else                  //*e                         //~v49bI~
          		if (Sulsrchsw==LINE_RESEARCH)		//*L           //~v496I~
          		{                                                  //~v496I~
                	llfoundsw=( (plh->ULHrevoffs==ULHULFOUND)      //~v496R~
							  & (pfh->UFHfindctr==plh->ULHrevctr));//~v496I~
				  	if (llfoundsw)                                 //~v496I~
                  	{                                              //~v496I~
                    	if (!Snotsrchsw)  //normal search          //~v496I~
							break;                                 //~v496I~
                  	}                                              //~v496I~
                  	else                                           //~v496I~
                    	if (Snotsrchsw)   //*! search              //~v496I~
    						if (plh->ULHtype==ULHTDATA)            //~v496I~
								break;        //not research linwe //~v496I~
		  		}                                                  //~v496I~
          		else                  //*e                               //~v0bqR~
          		if (Sulsrchsw==LINE_GREPSEARCH)		//*G           //~v632I~
          		{                                                  //~v632I~
    				if (plh->ULHtype==ULHTDATA)                    //~v632I~
                    {                                              //~v632I~
                        llfoundsw=( UCBITCHK(plh->ULHflag4,ULHF4GREP)//~v632R~
                                  && (pfh->UFHupctrgrep>=plh->ULHupctr));//not updated after grep//~v632R~
                        if ((llfoundsw^Snotsrchsw)) //exclusive or //~v632R~
                            break;                                 //~v632R~
                    }                                              //~v632I~
		  		}                                                  //~v632I~
          		else                  //*e                         //~v632I~
					if (UCBITCHK(plh->ULHflag,ULHFLCMDERR)                 //~v0bqR~
					||  UCBITCHK(plh->ULHflag3,ULHF3ERRLINE))              //~v0bqR~
                    {                                              //~v41rI~
                      if (!Snotsrchsw)   //normal search           //~v41rI~
						break;                                             //~v0bqR~
                    }                                              //~v41rI~
                    else                                           //~v41rI~
                      if (Snotsrchsw)  //*! search                 //~v41rI~
						break;         //not err,detected          //~v41rI~
            }                                                      //~v0hxR~
      	}                                                            //~v09eI~
      	else                                                         //~v09eI~
//*****************                                                //~va3QI~
//*Prev Dir *******                                                //~va3QI~
//*****************                                                //~va3QI~
      		if (Ppcw->UCWtype==UCWTDIR)     //on dir list           //~v05wI~
        	{                                                       //~v05wI~
    			for (;plh;(plh=UGETQPREV(plh))?offset=plh->ULHlen:0)//~v05wI~
    			{                                                   //~v05wI~
	                if (plh==Srangeplhe2) //reached to end range of & search//~v51sI~
                    	break;                                     //~v51sI~
    				if (plh->ULHtype!=ULHTDATA)                     //~v05wI~
    					continue;                                   //~v05wI~
    				if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))     //~v10oR~
                 		continue;   //on dlilist,search on displayed line only//~v10oR~
   	        		pdh=UGETPDH(plh);                               //~v05wI~
					if (!UCBITCHK(pdh->UDHflag,UDHFDDSETUP))	//already setup//~v481I~
			            dirddsetup2(Ppcw,plh);     //dir data line setup//~v481I~
   	        		pdd=UGETPDD(plh);                               //~v05wI~
                    width=plh->ULHlen;                             //~v0fhI~
                    if (Sdirts)   //timestamp srch                 //~vbc2I~
                    {                                              //~vbc2I~
                        if (fcmdfind_dirts(0,Psubcmdid,Ppcw,pdh,pdd,expandlen,Ssrch,&offset,&Sdirstep,&Sdirstepr))//~vbc2I~
                        	continue;	//not found                //~vbc2I~
                        break;                                     //~vbc2I~
                    }                                              //~vbc2I~
                  	if (dirindentsw)                               //~v0fhI~
                  	{                                              //~v0fhI~
						if ((level=pdh->UDHlevel)>UDDMAXLEVEL)	//over max//~v0fhI~
							level=UDDMAXLEVEL;                     //~v0fhI~
                        boundary1=level+2;                         //~v0fhI~
                  	}                                              //~v0fhI~
                  	else                                           //~v0fhI~
                        boundary1=offsetof(UDIRLD,UDDname[0]);     //~v0fhI~
                    pc=pdd->UDDlvl+boundary1;                      //~v0fhI~
                    if (Sdirattr)   //attr srch                    //~vbc1M~
                    {                                              //~vbc1M~
                        if (fcmdfind_dirattr(0,Psubcmdid,Ppcw,pdh,pdd,boundary1,expandlen,Ssrch,&offset,&Sdirstep,&Sdirstepr))//~vbc1I~
                        	continue;	//not found                //~vbc1M~
                        break;                                     //~vbc1M~
                    }                                              //~vbc1M~
//#ifdef LNX                                                         //~vauiI~//~vauFR~
                    if (pdh->UDHfnmlen)                            //~vauiR~
                    	boundary2=boundary1+pdh->UDHfnmlen;        //~vauiR~
                    else                                           //~vauiI~
//#endif                                                             //~vauiI~//~vauFR~
                    if (fatsw                                      //~v0fhI~
                    &&  *(pc+MAXFILENAMEZ_FAT-4))                  //~v0fhI~
                    	boundary2=boundary1+MAXFILENAMEZ_FAT-4     //~v0fhI~
									+(int)strlen(pc+MAXFILENAMEZ_FAT-4);  //search on UDHname//~v0fhI~
                    else                                           //~v0fhI~
                    	boundary2=boundary1+(int)strlen(pc);  //search on UDHname//~v0fhR~
//filename limit                                                   //~v183R~
				    if (UCBITCHK(pdh->UDHflag3,UDHF3SETDESC))	//edscription displayed//~v692I~
				    	fnmboundary=(int)offsetof(UDIRLD,UDDattrflag);//fnm is up to before attrflag//~v692I~
                    else                                           //~v692I~
				    if (UCBITCHK(pdh->UDHflag2,UDHF2SETATTR))	//attr setupped//~v183R~
				    	fnmboundary=(int)offsetof(UDIRLD,UDDattrflag);//fnm is up to before attrflag//~v183R~
                    else                                           //~v183R~
				    if (UCBITCHK(pdh->UDHflag2,UDHF2SETRENAME))	//rename setupped//~v183R~
				    	fnmboundary=(int)offsetof(UDIRLD,UDDrsv2); //~v183R~
                    else                                           //~v183R~
				    if (UCBITCHK(pdh->UDHflag2,UDHF2SETTSSZ))	//time stamp is set//~v54aI~
				    	fnmboundary=(int)offsetof(UDIRLD,UDDrsv3); //~v183R~
                    else                                           //~v54aI~
				    	fnmboundary=(int)sizeof(UDIRLD);           //~v54aI~
				    fnmboundary+=expandlen;                        //~v59TI~
                                                                   //~v182I~
//      			if (pdh->UDHrenamesv	//renamed or moved     //~v0fhR~
//          		&&  offset>=(int)offsetof(UDIRLD,UDDrname[0]))	//search on UDHname//~v0fhR~
            		if (offset>=boundary2) //right margin          //~v0fhI~
                	{                                               //~v05wI~
//  					pc=pdd->UDDrname;                          //~v0fhR~
//  					pc=pdd->UDDlvl+DIRRMSTART;                 //~v182R~
    					pc=pdd->UDDlvl+fnmboundary;                //~v182R~
//  					len=(int)strlen(pc);                       //~v0fhR~
//  					len=offset-DIRRMSTART;  //right of offset  //~v182R~
    					len=offset-fnmboundary; //right of offset  //~v182R~
//                  	if (offset-(int)offsetof(UDIRLD,UDDrname[0])>len)//~v0fhR~
//                  		offset=offsetof(UDIRLD,UDDrname[0])+len;//~v0fhR~
//  					pc=ustrnrstri(pc,Ssrch,                    //~v0fhR~
//  						(UINT)(offset-offsetof(UDIRLD,UDDrname[0])));//~v0fhR~
                      if (len>=Ssrchlen)                           //~v0fhI~
                      {                                            //~v0fhI~
                      	pc0=pc;                                    //~v0fiI~
#ifdef UTF8SUPPH   //utfstr cvdata is on Sescsrchchar              //~va00R~
                 	   if (Sescsrchlen)                            //~va00R~
                       {                                           //~va00R~
                         if (Scasesensesw)                         //~va00R~
//*on dirlist                                                      //~va20I~
		  					pc=umemrstr(pc,Sescsrchchar,(UINT)len);//~va00R~
                         else                                      //~va00R~
		  					pc=umemrstri(pc,Sescsrchchar,(UINT)len);//~va00R~
                       }                                           //~va00R~
                       else                                        //~va00R~
                       {                                           //~va00R~
#endif                                                             //~va00R~
                        if (Scasesensesw)                          //~v0fhI~
		  					pc=umemrstr(pc,Ssrch,(UINT)len);       //~v0fhR~
                        else                                       //~v0fhI~
//  	  					pc=umemrstri(pc,Ssrch,(UINT)len);      //~va3QR~
        			        pc=fcmdstrnstri(FCSIO_MEMLEN|FCSIO_REV,pc,Ssrch,len);//search on rename fld//~va3QR~
#ifdef UTF8SUPPH   //utfstr cvdata is on Sescsrchchar              //~va00R~
                       }                                           //~va00R~
#endif                                                             //~va00R~
    					if (pc)	//found last                        //~v05wI~
	    				{                                           //~v05wI~
//backward serch match on rename field                             //~v084I~
//    						offset=(int)((ULONG)pc-(ULONG)pdd);     //~v05wR~//~vafkR~
    						offset=(int)((ULPTR)pc-(ULPTR)pdd);    //~vafkI~
//      					Sdirstep=offsetof(UDIRLD,UDDrname)-offset-1;//in UDDname//~v084R~
//      					Sdirstepr=(int)offsetof(UDIRLD,UDDrname[0])+len-offset;//~v084R~
								//search on next line if changed direction//~v084R~
//      					Sdirstep=-Ssrchlen;                    //~v0fiR~
//        					Sdirstep=-(int)((ULONG)pc-(ULONG)umemrchr(pc0,0,(UINT)((ULONG)pc-(ULONG)pc0)));//~v0fiR~//~vafkR~
        					Sdirstep=-(int)((ULPTR)pc-(ULPTR)umemrchr(pc0,0,(UINT)((ULPTR)pc-(ULPTR)pc0)));//~vafkI~
//      					Sdirstepr=Ssrchlen;                    //~v0fiR~
        					Sdirstepr=(int)strlen(pc);             //~v0fiI~
    						break;                                  //~v05wI~
    					}//pc                                       //~v05wI~
                      }//in right margin                           //~v0fhI~
					}//renamesv                                               //~v05wI~
//                if (dirindentsw)                                 //~v0fhR~
//                {                                                //~v0fhR~
//  				if ((level=pdh->UDHlevel)>UDDMAXLEVEL)	//over max//~v0fhR~
//  					level=UDDMAXLEVEL;                         //~v0fhR~
//          		if (offset<level+2)	//search prev plh          //~v0fhR~
//              		continue;                                  //~v0fhR~
//                }                                                //~v0fhR~
//                else                                             //~v0fhR~
//          		if (offset<(int)offsetof(UDIRLD,UDDname[0]))	//search prev plh//~v0fhR~
            		if (offset<boundary1)                          //~v0fhI~
                		continue;                                  //~v0f6I~
//#ifdef LNX                                                         //~vauiI~//~vauFR~
				  if (pdh->UDHfnmlen||pdh->UDHslinkoffs)  //support "&" searc on member and slink//~vauiR~
                  {                                                //~vauiI~
                  	int optdddir;                                  //~vauiI~
                    optdddir=FCMDDDSSDO_PREV;                      //~vauiI~
                    if (pc=fcmdddstrsrch_dirfnm(optdddir,pdh,boundary2,&offset),pc) //PREV found//~vauiR~
                    	break;                                     //~vauiI~
                  }                                                //~vauiI~
                  else                                             //~vauiI~
//#endif                                                             //~vauiI~//~vauFR~
                  {//!ddsrch                                       //~vauiI~
#ifdef UTF8SUPPH                                                   //~va00R~
				  	pc0=PDH_UDHname(pdh);	//by locale code       //~va00R~
	#ifdef MMM                                                     //~vb2oI~
	#else                                                          //~vb2oI~
                    udhnamelen=PDH_UDHnamestrsrchlen(pdh);         //~vb2oR~
	#endif                                                         //~vb2oI~
#else                                                              //~va00R~
        			pc0=pdh->UDHname;	//member file name          //~v05wR~
#endif                                                             //~va00R~
#if defined(W32) || defined(DPMI)                                  //~v0fhI~
                    if (fatsw)                                     //~v0fhI~
        				pc0=pdh->UDHalias;	//member file name     //~v0fhI~
#endif                                                             //~v0fhI~
#ifdef UTF8SUPPH   //utfstr cvdata is on Sescsrchchar              //~va00R~
                 if (Sescsrchlen)                                  //~va00R~
                 {                                                 //~va00R~
//*on dirlist                                                      //~va20I~
                  if (Scasesensesw)                                //~va00R~
	#ifdef MMM                                                     //~vb2oI~
        			pc=ustrnstr(pc0,Sescsrchchar,MAXFILENAME);     //~va00R~
	#else                                                          //~vb2oI~
        			pc=ustrnstr(pc0,Sescsrchchar,(UINT)udhnamelen);//~vb2oR~
	#endif                                                         //~vb2oI~
                  else                                             //~va00R~
	#ifdef MMM                                                     //~vb2oI~
        			pc=ustrnstri(pc0,Sescsrchchar,MAXFILENAME);    //~va00R~
	#else                                                          //~vb2oI~
        			pc=ustrnstri(pc0,Sescsrchchar,(UINT)udhnamelen);//~vb2oR~
	#endif                                                         //~vb2oI~
                 }                                                 //~va00R~
                 else                                              //~va00R~
                 {                                                 //~va00R~
#endif                                                             //~va00R~
                  if (Scasesensesw)                                //~v0fhI~
	#ifdef MMM                                                     //~vb2oI~
        			pc=ustrnstr(pc0,Ssrch,MAXFILENAME);            //~v0fhI~
	#else                                                          //~vb2oI~
        			pc=ustrnstr(pc0,Ssrch,(UINT)udhnamelen);       //~vb2oR~
	#endif                                                         //~vb2oI~
                  else                                             //~v0fhI~
//      			pc=ustrnstri(pc0,Ssrch,MAXFILENAME);           //~va3QR~
	#ifdef MMM                                                     //~vb2oI~
        			pc=fcmdstrnstri(0,pc0,Ssrch,MAXFILENAME);//search on filename//~va3QR~
	#else                                                          //~vb2oI~
        			pc=fcmdstrnstri(0,pc0,Ssrch,udhnamelen);//search on filename//~vb2oI~
	#endif                                                         //~vb2oI~
#ifdef UTF8SUPPH   //utfstr cvdata is on Sescsrchchar              //~va00R~
                 }                                                 //~va00R~
#endif                                                             //~va00R~
    				if (pc)	//found last                            //~v05wI~
    				{                                               //~v05wI~
//backward serch match on name field                               //~v084I~
//  					offset=(int)((ULONG)pc-(ULONG)pc0+level+2);//~v0fhR~
//    					offset=(int)((ULONG)pc-(ULONG)pc0+boundary1);//~v0fhI~//~vafkR~
//  					offset=(int)((ULPTR)pc-(ULPTR)pc0+boundary1);//~vafkI~//~vb2pR~
    					offset=(int)((int)((ULPTR)pc-(ULPTR)pc0)+boundary1);//~vb2pI~
                      if (fatsw)                                   //~v0f7I~
                      {                                            //~v0f7I~
                    	pc2=strchr(pc0,'.');//to get '.' offset        //~v083M~
                    	if (pc2 && (pc2<pc))	//match after '.'      //~v083M~
//                    		offset+=(int)(8-((ULONG)pc2-(ULONG)pc0));  //~v083I~//~vafkR~
                    		offset+=(int)(8-((ULPTR)pc2-(ULPTR)pc0));//~vafkI~
								//expand len for dir2 highlighten  //~v083M~
                      }                                            //~v0f7I~
                      else                                         //~v0f7I~
//                      if (offset>(int)(offsetof(UDIRLD,UDDname[0])+sizeof(pdd->UDDname)))//hidden//~v182R~
//                          offset=offsetof(UDIRLD,UDDname[0])+sizeof(pdd->UDDname);//hidden//~v182R~
                        if (offset>fnmboundary)                    //~v182R~
                            offset=fnmboundary;//hidden            //~v182R~
    					Sdirstep=-offset+1;	//next find to prev plh //~v05wR~
                    					//avoid null            //~v05wI~
//  					Sdirstepr=offsetof(UDIRLD,UDDrname[0])-offset;//~v0fhR~
    					Sdirstepr=boundary2-offset;                //~v0fhI~
								//search on UDHrname when changed direction//~v084I~
    					break;                                      //~v05wI~
                	}//pc                                           //~v05wI~
                  }//!ddsrch                                       //~vauiI~
    			}//all plh                                          //~v05wI~
        	}//dir                                                  //~v05wI~
        	else							//edit/browse           //~v05wI~
        	{                                                       //~v05wI~
//*******************                                              //~v13oI~
//*Prev:Edit/Browsw *                                              //~v13oI~
//*******************                                              //~v13oI~
              if (binfsw                                           //~v13pR~
              &&  ((int)Srangeid2==RANGENOPARM))                   //~v437R~
//              offset=offset;                                     //~v13pI~//+vbr1R~
                ;                                                  //+vbr1I~
              else                                                 //~v13pI~
				if (offset>plh->ULHlen)                             //~5107I~
					offset=plh->ULHlen;                             //~5107I~
          	  if (!Slinerangesw)                //already out of range//~v0hxR~
    			for (;plh;(plh=UGETQPREV(plh))?offset=plh->ULHlen:0)
    			{
	                if (plh==Srangeplhe)        //reached to end range//~v0hxR~
                    	break;                                     //~v0hxR~
	                if (plh==Srangeplhe2)        //reached to end range//~v43eI~
                    	break;                                     //~v43eI~
//  				if (Sexcludesw2)                               //~v10oR~
	    			if (skipxsw)                                   //~v10oI~
						if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED)) //~v0hzI~
                 			continue;                              //~v0hzR~
    				if (plh->ULHtype!=ULHTDATA)
    					continue;
//                if (binfsw                                       //~v43bR~
//                &&  ((int)Srangeid2==RANGENOPARM))               //~v43bR~
//                {                                                //~v43bR~
                    rc=0;           //not found                    //~v13pI~
//                  if (Sescsrchlen)                               //~v43bR~
//                  {                                              //~v43bR~
//                      splitsrchlen=Sescsrchlen;                  //~v43bR~
//                      splitsrch=Sescsrchchar;                    //~v43bR~
//                  }                                              //~v43bR~
//                  else                                           //~v43bR~
//                      if (Ssrchlen)     //exclude case           //~v43bR~
//      	            {                                          //~v43bR~
//          	            splitsrchlen=Ssrchlen;                 //~v43bR~
//              	        splitsrch=Ssrch;                       //~v43bR~
//                  	}                                          //~v43bR~
                    pc=0;                                          //~v13pI~
                    if (splitsrchlen)                              //~v13pI~
                    {                                              //~v13pI~
                        rc=fcmdsplitsrch(plh,offset,splitsrch,splitsrchlen,//~v13pR~
                                         Stabsrchsw,SUBCMD_PREV,   //~v13pR~
//  									Sescsrchlen||Scasesensesw||Pchangeopt,//~v13pI~,//~v72PR~
    									Sescsrchlen||Scasesensesw, //~v72PI~
										&pc,&wordplh,&wordend);//-1:prev//~v13pI~
                    	if (rc==UALLOC_FAILED)                     //~v13pI~
                        	return UALLOC_FAILED;                  //~v13pI~
                        if (rc==2)  //spaned                       //~v13pI~
                        {                                          //~v13pI~
                        	Sspanplh=wordplh;                      //~v13pR~
                            plh=wordplh;                           //~v13pI~
                        }                                          //~v13pI~
                    }                                              //~v13pI~
//                }                                                //~v43bR~
                  else	//no split consideration                   //~v13pI~
                  {                                                //~v13pI~
    				if (offset<Ssrchlen)	//may not match             //~5107I~
                    {                                              //~v54aI~
                     if (!grepsw)                                  //~v78dI~
                     {                                             //~v78dI~
                      if (!(                                       //~va3EI~
                               Sddstrlen	//ddstr search         //~va3EI~
//*ddlen set to 0 when tabsrch, Sescsrchlen,esclen at fcmdisddsrch //~va3ER~
                           &&  offset>=Sddstrlen                   //~va3EI~
                           )                                       //~va3EI~
                      )                                            //~va3EI~
                      {                                            //~va3EI~
                      if (Snotsrchsw)  //*! search                 //~v41rI~
                        break;                                     //~v41rI~
                      else                                         //~v41rI~
    					continue;                                       //~5107I~
                      }                                            //~va3EI~
                     }//!grep                                      //~v78dI~
                    }//offset                                      //~v54aI~
			  		if (Stabsrchsw)                                      //~v09II~
              		{	                                                   //~v09II~
//                		rc=fcmdtabsrch(plh,SUBCMD_PREV,offset,&pc);	//backward search//~v0eBR~
//                		rc=fcmdtabsrch(plh,SUBCMD_PREV,offset,&pc,Srange1,Srange2);	//backward search//~v11sR~
                  		rc=fcmdtabsrch(plh,SUBCMD_PREV,offset,&pc,Srange1,Srange2,Sescsrchchar,Sescsrchlen);	//backward search//~v11sI~
                		if (rc)	                                           //~v09II~
                  			return rc;                                     //~v09II~
              		}                                                    //~v09II~
              		else//not tabsrch                                                 //~v09II~
#ifdef UTF8SUPPH                                                   //~va1GR~
					if (Sutf8echsrchsw) //search utf8 trans err char//~va1GR~
              		{                                              //~va1GR~
                  		rc=fcmdutf8echsrch(plh,SUBCMD_PREV,offset,&pc,Srange1,Srange2);	//backward search//~va1GR~
                		if (rc)                                    //~va1GR~
                  			return rc;                             //~va1GR~
              		}                                              //~va1GR~
              		else//not err ch search                        //~va1GR~
#endif                                                             //~va1GR~
              		{                                                    //~v09II~
//                  	if (spacesw && !plh->ULHdbcs)	//if space contained//~v78dR~
                    	if ((spacesw||grepsw)                      //~v78dI~
						&&  !plh->ULHdbcs)	//if space contained   //~v78dI~
                        	if (filechktabdbcs(plh)==UALLOC_FAILED)//expand before compare//~v13oI~
                            	return UALLOC_FAILED;              //~v13oI~
                                                                   //~v13oI~
                		offset0=offset;	//save for each loop           //~v0eBI~
    					for (;;)                                            //~4C30I~
    					{                                                   //~4C30I~
    						pc=plh->ULHdata;                                //~4C30R~
    						pcd=plh->ULHdbcs;                          //~v0eBI~
                        	offset=offset0;                            //~v0eBI~
                            if (Seolsrchsw)	//word on eol search   //~v47BI~
                            {                                      //~v47BI~
                            	eoloffset=plh->ULHlen-Ssrchlen;    //~v47BI~
                            	if (offset!=plh->ULHlen)	//before eol pos//~v47BR~
                                {                                  //~v47BI~
                                    pc=0;       //not found        //~v47BI~
                                    break;                         //~v47BI~
                                }                                  //~v47BI~
	                            pc+=eoloffset;	//before eol pos   //~v47BI~
                                offset=Ssrchlen;                   //~v47BI~
                        		if (pcd)                           //~v47BI~
                                {                                  //~v54zI~
                                  if (Ssrchlen)                    //~v54zI~
                                  {                                //~v54zI~
                                	if (eoloffset<Srange1          //~v47BI~
//                              	||  (Srange2 && Srange2<plh->ULHlen))//~v54zR~
                                	||  (Srange2<plh->ULHlen))//srange2 may be 0 when range=(1-1)//~v54zI~
	                                {                              //~v47BI~
    	                                pc=0;       //not found    //~v47BI~
        	                            break;                     //~v47BI~
            	                    }                              //~v47BI~
                                  }                                //~v54zI~
                                  else  //*\n srch                 //~v54zI~
                                  {                                //~v54zI~
//                                  if (Srangeid2==RANGE1ONLY)//Srange1==Srange2//~v54RR~
                                    if (Srangeid2==RANGE1ONLY //Srange1==Srange2//~v54RI~
                                    ||  Srangeid2==RANGEMAX)  //Srange1==maxlrecl//~v54RI~
                                    {                              //~v54zI~
                                    	if (eoloffset!=Srange1)    //~v54zI~
                                        {                          //~v54zI~
	    	                                pc=0;       //not found//~v54zI~
	        	                            break;                 //~v54zI~
                                        }                          //~v54zI~
                                    }                              //~v54zI~
                                    else                           //~v54zI~
                                        if (!(eoloffset>=Srange1   //~v54zR~
                                              && eoloffset<Srange2))//range2 is next of specified col//~v54zR~
                                        {                          //~v54zR~
                                            pc=0;       //not found//~v54zR~
                                            break;                 //~v54zR~
                                        }                          //~v54zR~
                                  }                                //~v54zI~
                                }//pcd                             //~v54zI~
                            }                                      //~v47BI~
                            else	//not eol srch                 //~v47BI~
                        	if (pcd)                                   //~v0eBI~
                        	{	                                       //~v0eBI~
                            	if (offset>Srange2)	//out of range     //~v0eBI~
                            		offset=Srange2;                    //~v0eBI~
                        		pc+=Srange1;		                   //~v0eBI~
                            	offset-=Srange1;                       //~v0eBI~
                                if (offset<=0)//out of range       //~v0eBI~
                                {                                  //~v0eBI~
                                    pc=0;       //not found        //~v0eBI~
                                    break;                         //~v0eBI~
                                }                                  //~v0eBI~
                        	}                                          //~v0eBI~
#ifdef REGEXSUPP                                                   //~v78qR~
                         if (grepsw)                               //~v78dR~
                         {                                         //~v78dR~
                         	fcmdgrepplh(FCGPO_BWD,Ppcw,plh,pc,offset,Scasesensesw,&pc,&matchlen);//~v78dR~
                         }                                         //~v78dR~
                         else                                      //~v78dR~
                         {                                         //~v78dR~
#endif                                                             //~v78qR~
				  			if (Sescsrchlen)                                 //~v09OR~
                            {                                      //~va20R~
#ifdef UTF8UCS2                                                    //~va20R~
							  if (swutf8file)                      //~va20R~
                              {                                    //~va20I~
                  				optdds=FCMDDDSSO_ESC|FCMDDDSSO_PREV;//~va20R~
                  				pc=fcmdddstrsrch(optdds,plh,Sescsrchchar,Spdddbcs/*dummy*/,Sescsrchlen,pc,offset,&ucswordlen);//~va20R~
                              }                                    //~va20I~
                              else                                 //~va20R~
#endif                                                             //~va20R~
                  				pc=fcmdescsrch(pc,SUBCMD_PREV,offset);         //~v09LR~
                            }                                      //~va20R~
                  			else                                             //~v09LI~
                              if (Ssrchlen)     //exclude case     //~v10TI~
                              {                                    //~v54aI~
#ifdef UTF8UCS2                                                    //~va20I~
							   if (Sddstrlen)                      //~va20R~
                               {                                   //~va20I~
                  				optdds=FCMDDDSSO_PREV|FCMDDDSSO_DDSTR;//~va20R~
    							if (!Scasesensesw)	//case sensitive//~va20R~
                  					optdds|=FCMDDDSSO_NOCASE;      //~va20R~
                  				pc=fcmdddstrsrch(optdds,plh,Spddstr,Spdddbcs,Sddstrlen,pc,offset,&ucswordlen);//~va20R~
                               }                                   //~va20I~
                               else                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
							   if (Sebcstrlen)                     //~va50I~
                               {                                   //~va50I~
    							if (Scasesensesw)	//case sensitive//~va50I~
    								pc=ucvebc_umemrmem(0,pc,XEUTF_PLHPC2PCD(plh,pc),offset,Spebcstr,Spebcdbcs,Sebcstrlen);//~va50R~
    							else				//case insensitive//~va50I~
//  								pc=ucvebc_umemrmemi(0,pc,XEUTF_PLHPC2PCD(plh,pc),offset,Spebcstr,Spebcdbcs,Sebcstrlen);//~va50R~//~va79R~
    								pc=ucvebc_umemrmemi(0,handle,pc,XEUTF_PLHPC2PCD(plh,pc),offset,Spebcstr,Spebcdbcs,Sebcstrlen);//~va79I~
                               }                                   //~va50I~
                               else                                //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                               {                                   //~va20I~
//  							if (Scasesensesw)	//case sensitive//~v10QR~
//  							if (Scasesensesw||Pchangeopt)	//case sensitive//~v10QI~,//~v72PR~
    							if (Scasesensesw)	//case sensitive//~v72PI~
//  								pc=ustrnrstr(pc,Ssrch,(UINT)offset);       //~v0a1R~
//*on locale file                                                  //~va20I~
    								pc=umemrstr(pc,Ssrch,(UINT)offset);        //~v0a1I~
    							else				//case insensitive          //~4C30R~
                                {                                  //~va3QI~
//  								pc=ustrnrstri(pc,Ssrch,(UINT)offset);      //~v0a1R~
                                  if (plh->ULHdbcs)                //~va3QI~
//                                	pc=umemrstridbcs(0,pc,XEUTF_PLHPC2PCD(plh,pc),Ssrch,(UINT)offset);//~va3QI~//~vb2pR~
                                  	pc=umemrstridbcs(0,pc,XEUTF_PLHPC2PCD(plh,pc),Ssrch,offset);//~vb2pI~
                                  else                             //~va3QI~
                                	pc=umemrstri(pc,Ssrch,(UINT)offset);       //~v0a1I~
                                }                                  //~va3QI~
                               }                                   //~va20I~
                              }//srchlen                           //~v54aI~
                              else                                 //~v54zI~
                              {                                    //~v54zI~
                               	if (Seolsrchsw)	//word on eol search//~v54zI~
                                	pc=plh->ULHdata+plh->ULHlen;   //~v54zI~
                              }//srchlen==0                        //~v54zI~
#ifdef REGEXSUPP                                                   //~v78qI~
                         }//!grep                                  //~v78dI~
#endif                                                             //~v78qR~
                    		rc=0;                                           //~v04dI~
//                        	if (!pc                                  //~v0eBR~
//                        	||  (rc=filechktabdbcs(plh),rc))    //no tab or tab processed//~v0eBR~
//                        	{                                        //~v0eBR~
//                            	if (rc==UALLOC_FAILED)               //~v0eBR~
//                              	return UALLOC_FAILED;            //~v0eBR~
//                            	break;                               //~v0eBR~
//                        	}                                        //~v0eBR~
                        	if (!pc)                                   //~v0eBI~
                          		break;                                   //~v0eBI~
                        	rc=filechktabdbcs(plh);    //no tab or tab processed//~v0eBI~
                        	if (rc==UALLOC_FAILED)                     //~v0eBI~
                            	return UALLOC_FAILED;                  //~v0eBI~
                        	if (rc)                   //no tab or tab processed//~v0eBI~
                            {                                      //~v54aI~
                            	if ((int)Srangeid2==RANGENOPARM) //old fashion//~v437R~
                                {                                  //~v74ER~
                            		if (pcd)	//range chked      //~v74ER~
                                		break;                     //~v74ER~
                                  if (pfh->UFHbndscol1==0 && pfh->UFHbndscol2==0)//no bound specified//~v74ER~
                            		break;                             //~v0eBI~
                                }                                  //~v74ER~
                            	else                                   //~v0eBI~
                            		if (pcd)	//range chked          //~v0eBI~
                                		break;                         //~v0eBI~
                            }//rc                                  //~v54aI~
//  						offset=plh->ULHlen;	//after tab expand //~v13hR~
    						offset0=plh->ULHlen;	//after tab expand//~v13hI~
    					}//for                                                   //~4C30I~
              		}//tab search or else                                //~v09II~
                  }//no split consideration                        //~v13pI~
                  if (Snotsrchsw)    //search lines dose not contain the word//~v41rI~
                  {                                                //~v41rI~
    				if (!pc)	//found last                       //~v41rI~
    				{                                              //~v41rI~
    					offset=0;                                  //~v41rI~
    					break;                                     //~v41rI~
    				}                                              //~v41rI~
                  }                                                //~v41rI~
                  else                                             //~v41rI~
    				if (pc)	//found last                                //~4C30R~
    				{
//    					offset=(int)((ULONG)pc-(ULONG)plh->ULHdata);    //~4C30R~//~vafkR~
    					offset=(int)((ULPTR)pc-(ULPTR)plh->ULHdata);//~vafkI~
    					break;
    				}
    			}//all plh
        	}							//edit/browse               //~v05wI~
//  	if (plh)                                                   //~v0hxR~
    	if (plh && plh!=Srangeplhe                                 //~v0hxR~
        &&  plh!=Srangeplhe2                                       //~v43eR~
        &&  !Slinerangesw)			//not initialy out of range    //~v0hxR~
        {                                                          //~v0hEI~
          if (Plocatesw)  //not 2nd of all                         //~v0hEI~
          {                                                        //~v54aI~
			if (Pchangeopt)                                     //~5106I~
				uerrmsg("Forward Change",                       //~5106I~
						"上置換");                                 //~v11gR~
			else                                                //~5106I~
	  	  		if (Swrapsw)	//wrap search                          //~v09cI~
					uerrmsg("Backward Re-search from last",            //~v09cI~
						"最後からの再-上探索");                    //~v11gR~
   		  		else                                                 //~v09cI~
					uerrmsg("Backward Search",                      //~5106R~
						"上探索");                                 //~v11gR~
          }//locatesw                                              //~v54aI~
        }                                                          //~v0hEI~
		else
		{
//            if (Plocatesw)  //not 2nd of all                     //~v0hxR~
//                Snotfinpctr=Gkbdinpctr; //save kbd input ctr to chk continuous ope//~v0hxR~
//            if (Pchangeopt)                                      //~v0hxR~
//                caseid="C";                                      //~v0hxR~
//            else                                                 //~v0hxR~
//                if (Scasesensesw)                                //~v0hxR~
//                    caseid="F";                                  //~v0hxR~
//                else                                             //~v0hxR~
//                    caseid="I";                                  //~v0hxR~
//            if (Swrapsw)    //wrap search                        //~v0hxR~
//                uerrmsg("%s:None in this file(%s)",              //~v0hxR~
//                        "%s:一つも見つかりません(%s)",           //~v0hxR~
//                        caseid,Ssrch);                           //~v0hxR~
//            else                                                 //~v0hxR~
//                uerrmsg("%s:Reached to Top of file(%s)",         //~v0hxR~
//                        "%s:ファイルの先頭に達しました(%s)",     //~v0hxR~
//                        caseid,Ssrch);                           //~v0hxR~
//            return 4;                                            //~v0hxR~
		    return fcmdsrcherr(Pchangeopt,Plocatesw,Psubcmdid,plh);//~v0hxR~
		}//plh==0
	}//prev
	else			//not prev
	{				//next
//*************************                                        //~v41rI~
//*Next                   *                                        //~v41rI~
//*************************                                        //~v41rI~
      	if (Sulsrchsw)					//update line search       //~v09eI~
      	{                                                            //~v09eI~
		 if (offset==OFFS_ULNEXT)//avoid step next line for "all" search//~v633I~
         	offset=0;                                              //~v633I~
         else                                                      //~v633I~
         {                                                         //~v633I~
          if (Sulsrchsw!=LINE_SAMESRCH)		//*=                   //~v49bR~
//  		if (offset!=1 && plh)			//csr is not before client area//~v41rR~
    		if (offset!=OFFS_TOP && plh)			//csr is not before client area//~v41rI~
				plh=UGETQNEXT(plh);         //serach from prev line    //~v09eI~
         }//OFFS_ULNEXT                                            //~v633I~
          if (!Slinerangesw)                //already out of range //~v0hxR~
			for (;plh;plh=UGETQNEXT(plh))                              //~v09eI~
            {                                                      //~v0hkI~
                if (plh==Srangeplhe)    //reached next of 'B' lcmd //~v0hkI~
                {                                                  //~v0hkI~
//                  if (!fcmdsetabrange(Ppcw,pfh,0))//no next range//~v0hxR~
                        break;                                     //~v0hkI~
//                  plh=Srangeplhs; //new start range              //~v0hxR~
                }                                                  //~v0hkI~
                if (plh==Srangeplhe2)    //reached next of 'B' lcmd//~v43eI~
                        break;                                     //~v43eI~
//              if (Sexcludesw2)                                   //~v10oR~
                if (skipxsw || dirskipsw)                          //~v10oR~
                    if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))     //~v0hzI~
                    	continue;                                  //~v0hzI~
          		if (Sulsrchsw==1)		//*u                               //~v0bqR~
          		{                                                        //~v0bqR~
					if (plh->ULHupctr)                                     //~v09eI~
                    {                                              //~v41rI~
                    if (!Snotsrchsw)  //normal search              //~v41rI~
					break;                                             //~v09eI~
                    }                                              //~v41rI~
                    else                                           //~v41rI~
                    	if (Snotsrchsw)   //*! search              //~v41rI~
    						if (plh->ULHtype==ULHTDATA)            //~v41rI~
								break;        //not updated detected//~v41rI~
		  		}                                                        //~v0bqR~
          		else                                               //~v62dI~
          		if (Sulsrchsw==LINE_SAMEMATCH)		//*= & ^* (matching)//~v62dI~
          		{                                                  //~v62dI~
					samesrchrc=fcmdsamematch(Ppcw,pfh,Spfhmatching,plh,Srangeplhe,//~v62dR~
    								  Scasesensesw,Sexcludesw2,Srange1,Srange2,Sminsame);//~v62fR~
                    if (samesrchrc==UALLOC_FAILED)                 //~v62dI~
                    	return samesrchrc;                         //~v62dI~
                    offset=Srange1;                                //~v62dI~
                    if (samesrchrc!=1)	//data line                //~v62dI~
                    {                                              //~v62dI~
                    	if (samesrchrc)	//not found                //~v62dI~
	                  	{                                          //~v62dI~
    	                	if (Snotsrchsw)  //normal search       //~v62dI~
								break;                             //~v62dI~
                	  	}                                          //~v62dI~
                  		else                                       //~v62dI~
                        {                                          //~v62dI~
                    		if (!Snotsrchsw)   //*! search         //~v62dI~
								break;        //not research linwe //~v62dI~
                        }                                          //~v62dI~
                    }//data line                                   //~v62dI~
		  		}                                                  //~v62dI~
          		else                                               //~v496I~
          		if (Sulsrchsw==LINE_SAMESRCH)		//*=           //~v49bI~
          		{                                                  //~v49bI~
                	Ssamelinectr=0;	//if not 0,stop search when reached to the count//~v61bI~
					samesrchrc=fcmdsamesrch(Ppcw,pfh,plh,Srangeplhe,&plhsames,&plhsamee,//~v49bR~
//  								  Scasesensesw,Srange1,Srange2,Sminsame,Psubcmdid,0,Sexcludesw2);//~v61bR~
    								  Scasesensesw,Srange1,Srange2,Sminsame,Psubcmdid,&Ssamelinectr,Sexcludesw2);//~v61bI~
				  	if (samesrchrc)       //not found              //~v49bI~
                    {                                              //~v49bI~
                    	plh=0;                                     //~v49bI~
	                    Ssamelastplh=0;                            //~v49bI~
                    }                                              //~v49bI~
                  	else       //found                             //~v49bI~
                    {                                              //~v49bI~
                    	plh=plhsames;                              //~v49bI~
	                    Ssamelastplh=plhsamee;                     //~v49bI~
                        offset=Srange1;                            //~v49bI~
                    }                                              //~v49bI~
                    break;                                         //~v49bI~
		  		}                                                  //~v49bI~
          		else                  //*e                         //~v49bI~
          		if (Sulsrchsw==LINE_RESEARCH)		//*L           //~v496I~
          		{                                                  //~v496I~
                	llfoundsw=( (plh->ULHrevoffs==ULHULFOUND)      //~v496R~
							  & (pfh->UFHfindctr==plh->ULHrevctr));//~v496I~
				  	if (llfoundsw)                                 //~v496I~
                  	{                                              //~v496I~
                    	if (!Snotsrchsw)  //normal search          //~v496I~
							break;                                 //~v496I~
                  	}                                              //~v496I~
                  	else                                           //~v496I~
                    	if (Snotsrchsw)   //*! search              //~v496I~
    						if (plh->ULHtype==ULHTDATA)            //~v496I~
								break;        //not research linwe //~v496I~
		  		}                                                  //~v496I~
          		else                  //*e                               //~v0bqR~
          		if (Sulsrchsw==LINE_GREPSEARCH)		//*G           //~v632I~
          		{                                                  //~v632I~
    				if (plh->ULHtype==ULHTDATA)                    //~v632I~
                    {                                              //~v632I~
                        llfoundsw=( UCBITCHK(plh->ULHflag4,ULHF4GREP)//~v632R~
                                  && (pfh->UFHupctrgrep>=plh->ULHupctr));//not updated after grep//~v632R~
                        if ((llfoundsw^Snotsrchsw)) //exclusive or //~v632R~
                            break;                                 //~v632R~
                    }                                              //~v632I~
		  		}                                                  //~v632I~
          		else                  //*e                         //~v632I~
					if (UCBITCHK(plh->ULHflag,ULHFLCMDERR)                 //~v0bqR~
					||  UCBITCHK(plh->ULHflag3,ULHF3ERRLINE))              //~v0bqR~
                    {                                              //~v41rI~
                      if (!Snotsrchsw)   //normal search           //~v41rI~
						break;                                             //~v0bqR~
                    }                                              //~v41rI~
                    else                                           //~v41rI~
                      if (Snotsrchsw)  //*! search                 //~v41rI~
						break;         //not err,detected          //~v41rI~
            }//plh loop                                            //~v0hkI~
      	}//ulsrch                                                            //~v09eI~
      	else                                                         //~v09eI~
      	  	if (Ppcw->UCWtype==UCWTDIR)     //on dir list           //~v05wI~
        	{                                                       //~v05wI~
//********************                                             //~vbc1I~
//*Next:Dir          *                                             //~vbc1I~
//********************                                             //~vbc1I~
    			for (;plh;plh=UGETQNEXT(plh),offset=0)              //~v05wI~
    			{                                                   //~v05wI~
	                if (plh==Srangeplhe2) //reached to end range of & search//~v51sI~
                    	break;                                     //~v51sI~
        			if (plh->ULHtype!=ULHTDATA)                     //~v05wI~
        				continue;                                   //~v05wI~
    				if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))     //~v10oR~
                 		continue;   //on dlilist,search on displayed line only//~v10oR~
   	        		pdh=UGETPDH(plh);                               //~v05wI~
					if (!UCBITCHK(pdh->UDHflag,UDHFDDSETUP))	//already setup//~v481I~
			            dirddsetup2(Ppcw,plh);     //dir data line setup//~v481R~
   	        		pdd=UGETPDD(plh);                               //~v05wI~
                    width=plh->ULHlen;                             //~v0fhI~
                    if (Sdirts)   //timestamp srch                 //~vbc2I~
                    {                                              //~vbc2I~
                        if (fcmdfind_dirts(0,Psubcmdid,Ppcw,pdh,pdd,expandlen,Ssrch,&offset,&Sdirstep,&Sdirstepr))//~vbc2I~
                        	continue;	//not found                //~vbc2I~
                        break;                                     //~vbc2I~
                    }                                              //~vbc2I~
                  if (dirindentsw)                                 //~v0f6I~
                  {                                                //~v0f6I~
					if ((level=pdh->UDHlevel)>UDDMAXLEVEL)	//over max//~v05wI~
						level=UDDMAXLEVEL;                          //~v05wI~
            		boundary1=level+2;                             //~v0fhI~
//          		ddsrchsw=(offset<=level+2+(int)sizeof(pdd->UDDname));	//search on UDHname//~v0fhR~
//          		ddsrchsw=(offset<=level+2+(int)strlen(pdd->UDDname));	//search on UDHname//~v0fhR~
                  }                                                //~v0f6I~
                  else                                             //~v0f6I~
            		boundary1=offsetof(UDIRLD,UDDname[0]);         //~v0fhI~
//          		ddsrchsw=(offset<=(int)(offsetof(UDIRLD,UDDname[0])+sizeof(pdd->UDDname)));	//search prev plh//~v0fhR~
//          		ddsrchsw=(offset<=(int)(offsetof(UDIRLD,UDDname[0])+strlen(pdd->UDDname)));	//search prev plh//~v0fhR~
                    pc=pdd->UDDlvl+boundary1;                      //~v0fhI~
                    if (Sdirattr)   //attr srch                    //~vbc1M~
                    {                                              //~vbc1M~
                        if (fcmdfind_dirattr(0,Psubcmdid,Ppcw,pdh,pdd,boundary1,expandlen,Ssrch,&offset,&Sdirstep,&Sdirstepr))//~vbc1I~
                        	continue;	//not found                //~vbc1M~
                        break;	                                   //~vbc1M~
                    }                                              //~vbc1M~
//#ifdef LNX                                                         //~vauiI~//~vauFR~
                    if (pdh->UDHfnmlen)                            //~vauiR~
                    {                                              //~vb40I~
                      if (fatsw)                                   //~vb40I~
                        boundary2=boundary1+MAXFILENAMEZ_FAT-1+(int)strlen(pc+MAXFILENAMEZ_FAT-1);  //search on UDHname//~vb40I~
                      else                                         //~vb40I~
                    	boundary2=boundary1+pdh->UDHfnmlen;        //~vauiR~
                        UTRACED("fcmd26 dir next slink",plh->ULHdata,plh->ULHlen);//~vb40I~
                        UTRACEP("fcmd26 dir next slink boundary1=%d,boundary2=%d\n",boundary1,boundary2);//~vb40I~
                    }                                              //~vb40I~
                    else                                           //~vauiI~
//#endif                                                             //~vauiI~//~vauFR~
                    if (fatsw                                      //~v0fhI~
                    &&  *(pc+MAXFILENAMEZ_FAT-4))                  //~v0fhI~
                    	boundary2=boundary1+MAXFILENAMEZ_FAT-4     //~v0fhI~
									+(int)strlen(pc+MAXFILENAMEZ_FAT-4);  //search on UDHname//~v0fhI~
                    else                                           //~v0fhI~
                    	boundary2=boundary1+(int)strlen(pc);  //search on UDHname//~v0fhI~
//filename limit                                                   //~v183R~
				    if (UCBITCHK(pdh->UDHflag3,UDHF3SETDESC))	//edscription displayed//~v692I~
				    	fnmboundary=(int)offsetof(UDIRLD,UDDattrflag);//fnm is up to before attrflag//~v692I~
                    else                                           //~v692I~
				    if (UCBITCHK(pdh->UDHflag2,UDHF2SETATTR))	//attr setupped//~v183R~
				    	fnmboundary=(int)offsetof(UDIRLD,UDDattrflag);//fnm is up to before attrflag//~v183R~
                    else                                           //~v183R~
				    if (UCBITCHK(pdh->UDHflag2,UDHF2SETRENAME))	//rename setupped//~v183R~
				    	fnmboundary=(int)offsetof(UDIRLD,UDDrsv2); //~v183R~
                    else                                           //~v183R~
				    if (UCBITCHK(pdh->UDHflag2,UDHF2SETTSSZ))	//time stamp is set//~v54aI~
				    	fnmboundary=(int)offsetof(UDIRLD,UDDrsv3); //~v183R~
                    else                                           //~v54aI~
				    	fnmboundary=(int)sizeof(UDIRLD);           //~v54aI~
				    fnmboundary+=expandlen;                        //~v59TI~
                                                                   //~v183R~
//          		if (offset<=level+2+MAXFILENAME)	//search on UDHname//~v0f6R~
//          		if (ddsrchsw)                   	//search on UDHname//~v0fhR~
            		if (offset<boundary2)           	//search on UDHname//~v0fhI~
                	{                                               //~v05wI~
//#ifdef LNX                                                         //~vauiI~//~vauFR~
					  if (pdh->UDHfnmlen||pdh->UDHslinkoffs)  //support "&" searc on member and slink//~vauiR~
                      {                                            //~vauiI~
                      	int optdddir;                              //~vauiI~
                        optdddir=FCMDDDSSDO_NEXT;                  //~vauiI~
                        if (pc=fcmdddstrsrch_dirfnm(optdddir,pdh,boundary2,&offset),pc) //found//~vauiR~
                        	break;                                 //~vauiI~
                      }                                            //~vauiI~
                      else                                         //~vauiI~
//#endif                                                             //~vauiI~//~vauFR~
                      { //not ddsrch                               //~vauiI~
#ifdef UTF8SUPPH                                                   //~va00R~
				  		pc0=PDH_UDHname(pdh);	//by locale code   //~va00R~
	#ifdef MMM                                                     //~vb2oI~
	#else                                                          //~vb2oI~
                    	udhnamelen=PDH_UDHnamestrsrchlen(pdh);     //~vb2oR~
	#endif                                                         //~vb2oI~
#else                                                              //~va00R~
        				pc0=pdh->UDHname;	//member file name      //~v05wR~
#endif                                                             //~va00R~
#if defined(W32) || defined(DPMI)                                  //~v0fhI~
                        if (fatsw)                                 //~v0fhI~
                            pc0=pdh->UDHalias;  //member file name //~v0fhI~
#endif                                                             //~v0fhI~
#ifdef UTF8SUPPH   //utfstr cvdata is on Sescsrchchar              //~va00R~
                 	if (Sescsrchlen)                               //~va00R~
                    {                                              //~va00R~
//*on dirlist                                                      //~va20I~
	                  if (Scasesensesw)                            //~va00R~
	#ifdef MMM                                                     //~vb2oI~
        				pc=ustrnstr(pc0,Sescsrchchar,MAXFILENAME); //~va00R~
	#else                                                          //~vb2oI~
        				pc=ustrnstr(pc0,Sescsrchchar,(UINT)udhnamelen);//~vb2oR~
	#endif                                                         //~vb2oI~
                      else                                         //~va00R~
	#ifdef MMM                                                     //~vb2oI~
        				pc=ustrnstri(pc0,Sescsrchchar,MAXFILENAME);//~va00R~
	#else                                                          //~vb2oI~
        				pc=ustrnstri(pc0,Sescsrchchar,(UINT)udhnamelen);//~vb2oR~
	#endif                                                         //~vb2oI~
                    }                                              //~va00R~
                 	else                                           //~va00R~
                    {                                              //~va00R~
#endif                                                             //~va00R~
	                  if (Scasesensesw)                            //~v0fhI~
	#ifdef MMM                                                     //~vb2oI~
        				pc=ustrnstr(pc0,Ssrch,MAXFILENAME);        //~v0fhI~
	#else                                                          //~vb2oI~
        				pc=ustrnstr(pc0,Ssrch,(UINT)udhnamelen);   //~vb2oR~
	#endif                                                         //~vb2oI~
                      else                                         //~v0fhI~
//      				pc=ustrnstri(pc0,Ssrch,MAXFILENAME);       //~va3QR~
	#ifdef MMM                                                     //~vb2oI~
        				pc=fcmdstrnstri(0,pc0,Ssrch,MAXFILENAME);//search on filename//~va3QR~
	#else                                                          //~vb2oI~
        				pc=fcmdstrnstri(0,pc0,Ssrch,udhnamelen);//search on filename//~vb2oI~
	#endif                                                         //~vb2oI~
#ifdef UTF8SUPPH   //utfstr cvdata is on Sescsrchchar              //~va00R~
                    }                                              //~va00R~
#endif                                                             //~va00R~
        				if (pc)                                     //~v05wI~
        				{                                           //~v05wI~
//forward serch match on name field                                //~v084I~
//      					offset=(int)((ULONG)pc-(ULONG)pc0)+level+2;//~v0fhR~
//        					offset=(int)((ULONG)pc-(ULONG)pc0)+boundary1;//~v0fhI~//~vafkR~
        					offset=(int)((ULPTR)pc-(ULPTR)pc0)+boundary1;//~vafkI~
                          if (fatsw)                               //~v0f7I~
                          {                                        //~v0f7I~
                        	pc2=strchr(pc0,'.');//to get '.' offset    //~v083I~
                        	if (pc2 && (pc2<pc))	//match after '.'  //~v083I~
//                        		offset+=(int)(8-((ULONG)pc2-(ULONG)pc0));//expand len for dir2 highlighten//~v083R~//~vafkR~
                        		offset+=(int)(8-((ULPTR)pc2-(ULPTR)pc0));//expand len for dir2 highlighten//~vafkI~
                          }                                        //~v0f7I~
                          else                                     //~v0f7I~
//                          if (offset>(int)(offsetof(UDIRLD,UDDname[0])+sizeof(pdd->UDDname)))//hidden//~v182R~
//                              offset=offsetof(UDIRLD,UDDname[0])+sizeof(pdd->UDDname);//hidden//~v182R~
                            if (offset>fnmboundary)//hidden        //~v182R~
                                offset=fnmboundary;//hidden        //~v182R~
//                      	Sdirstep=offsetof(UDIRLD,UDDrname[0])-offset;//no more search//~v0fhR~
                        	Sdirstep=boundary2-offset;//no more search//~v0fhI~
	    					Sdirstepr=-offset+1;	//search on UDHname when changed direction//~v084I~
        					break;                                  //~v05wI~
        				}//pc                                           //~v05wI~
//              		offset=offsetof(UDIRLD,UDDrname[0]);//for srch rename fld//~v084R~
                      }//!ddsrch on dhname                         //~vauiI~
                	}//udhname                                               //~v05wI~
//                  if (offset<DIRRMSTART)                         //~v182R~
//              		offset=DIRRMSTART;   //search right margin //~v182R~
                    if (offset<fnmboundary)                        //~v182R~
                		offset=fnmboundary;  //search right margin //~v182R~
//      			if (!pdh->UDHrenamesv)	//not renamed nor moved//~v0fhR~
//      				continue;               //search next plh  //~v0fhR~
//      			len=(int)strlen(pdd->UDDrname);                //~v0fhR~
                    len=width-offset;                              //~v0fhI~
                  if (len>=Ssrchlen)                               //~v0fhI~
                  {                                                //~v0fhI~
//              	if (offset>=(int)offsetof(UDIRLD,UDDrname[0])+len)//~v0fhR~
//      				continue;               //search next plh  //~v0fhR~
//              	if (offset<(int)offsetof(UDIRLD,UDDrname[0]))  //~v0fhR~
//              		offset=offsetof(UDIRLD,UDDrname[0]);       //~v0fhR~
    				pc=pdd->UDDlvl+offset;                         //~v0fhR~
                    pc0=pc;                                        //~v0fiI~
//      			pc=ustrnstri(pc+offset,Ssrch,                  //~v0fhR~
//  						(UINT)(len-(offset-offsetof(UDIRLD,UDDrname[0]))));//~v0fhR~
#ifdef UTF8SUPPH   //utfstr cvdata is on Sescsrchchar              //~va00R~
//*dirlist                                                         //~va20I~
                   if (Sescsrchlen)                                //~va00R~
                   {                                               //~va00R~
	                if (Scasesensesw)                              //~va00R~
        				pc=umemstr(pc,Sescsrchchar,(UINT)len);     //~va00R~
                    else                                           //~va00R~
        				pc=umemstri(pc,Sescsrchchar,(UINT)len);    //~va00R~
                   }                                               //~va00R~
                   else                                            //~va00R~
                   {                                               //~va00R~
#endif                                                             //~va00R~
	                if (Scasesensesw)                              //~v0fhI~
        				pc=umemstr(pc,Ssrch,(UINT)len);            //~v0fhR~
                    else                                           //~v0fhI~
//      				pc=umemstri(pc,Ssrch,(UINT)len);           //~va3QR~
        				pc=fcmdstrnstri(FCSIO_MEMLEN,pc,Ssrch,len);//search on rename fld//~va3QI~
#ifdef UTF8SUPPH   //utfstr cvdata is on Sescsrchchar              //~va00R~
                   }                                               //~va00R~
#endif                                                             //~va00R~
        			if (pc)                                         //~v05wI~
        			{                                               //~v05wI~
//forward serch match on rename field                              //~v084I~
//        				offset=(int)((ULONG)pc-(ULONG)pdd);         //~v05wR~//~vafkR~
        				offset=(int)((ULPTR)pc-(ULPTR)pdd);        //~vafkI~
//                  	Sdirstep=len+offsetof(UDIRLD,UDDrname[0])-offset;//no more search//~v084R~
//                 	 	Sdirstepr=-offset+offsetof(UDIRLD,UDDrname[0])-1;//no more search//~v084R~
//                  	Sdirstep=Ssrchlen;                         //~v0fiR~
        				Sdirstep=(int)strlen(pc);                  //~v0fiI~
//                  	Sdirstepr=-Ssrchlen;                       //~v0fiR~
//        				Sdirstepr=-(int)((ULONG)pc-(ULONG)umemrchr(pc0,0,(UINT)((ULONG)pc-(ULONG)pc0)));//~v0fiR~//~vafkR~
        				Sdirstepr=-(int)((ULPTR)pc-(ULPTR)umemrchr(pc0,0,(UINT)((ULPTR)pc-(ULPTR)pc0)));//~vafkI~
        				break;                                      //~v05wI~
        			}//pc                                               //~v05wI~
                  }//in right margin                               //~v0fhI~
    			}//all plh                                          //~v05wI~
        	}                                                       //~v05wI~
        	else							//edit/browse           //~v05wI~
        	{                                                       //~v05wI~
//********************                                             //~v13oI~
//*Next:Edit/Browse  *                                             //~v13oI~
//********************                                             //~v13oI~
	          if (!Slinerangesw)                //already out of range//~v0hxR~
    			for (;plh;plh=UGETQNEXT(plh),offset=0)
    			{
                    if (plh==Srangeplhe)	//reached next of 'B' lcmd//~v0hkI~
                    {                                              //~v0hkI~
//  					if (!fcmdsetabrange(Ppcw,pfh,0))//no next range//~v0hxR~
                        	break;                                 //~v0hkI~
//                      plh=Srangeplhs;	//new start range          //~v0hxR~
					}                                              //~v0hkI~
                    if (plh==Srangeplhe2)	//reached next of 'B' lcmd//~v43eI~
                        	break;                                 //~v43eI~
//                  if (Sexcludesw2)                               //~v10oR~
	                if (skipxsw)                                   //~v10oI~
                        if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED)) //~v0hzI~
	                    	continue;                              //~v0hzI~
    				if (plh->ULHtype!=ULHTDATA)
    					continue;
//                if (binfsw                                       //~v43bR~
//                &&  ((int)Srangeid2==RANGENOPARM))               //~v43bR~
//                {                                                //~v43bR~
                    rc=0;           //not found                    //~v13pI~
//                  if (Sescsrchlen)                               //~v43bR~
//                  {                                              //~v43bR~
//                      splitsrchlen=Sescsrchlen;                  //~v43bR~
//                      splitsrch=Sescsrchchar;                    //~v43bR~
//                  }                                              //~v43bR~
//                  else                                           //~v43bR~
//                      if (Ssrchlen)     //exclude case           //~v43bR~
//      	            {                                          //~v43bR~
//          	            splitsrchlen=Ssrchlen;                 //~v43bR~
//              	        splitsrch=Ssrch;                       //~v43bR~
//                  	}                                          //~v43bR~
                    pc=0;                                          //~v13pI~
                    if (splitsrchlen)                              //~v13pI~
                    {                                              //~v13pI~
                        rc=fcmdsplitsrch(plh,offset,splitsrch,splitsrchlen,//~v13pR~
										 Stabsrchsw,SUBCMD_NEXT,   //~v13pR~
//  										Sescsrchlen||Scasesensesw||Pchangeopt,//~v13pI~,//~v72PR~
    										Sescsrchlen||Scasesensesw,//~v72PR~
											&pc,&wordplh,&wordend);//~v13pI~
                    	if (rc==UALLOC_FAILED)                     //~v13pI~
                        	return UALLOC_FAILED;                  //~v13pI~
                        if (rc==2)                                 //~v13pI~
                        	Sspanplh=wordplh;                      //~v13pR~
                    }                                              //~v13pI~
//                }                                                //~v43bR~
                  else	//no split consideration                   //~v13pI~
                  {                                                //~v13pI~
//before ULHlen chk                                                //~v41rI~
//                	if (spacesw && !plh->ULHdbcs)	//if space contained//~v78dR~
                  	if ((spacesw||grepsw)                          //~v78dI~
                  	&&  !plh->ULHdbcs)	//if space contained       //~v78dI~
                      	if (filechktabdbcs(plh)==UALLOC_FAILED)//expand before compare//~v41rI~
                          	return UALLOC_FAILED;                  //~v41rI~
UTRACEP("Sddstrlen=%d,Ssrchlen=%d,Sescsrchlen=%d,Sutf8echrchsw=%d\n",Sddstrlen,Ssrchlen,Sescsrchlen,Sutf8echsrchsw);//~va3ER~
    				if (plh->ULHlen-offset<Ssrchlen)	//may not match //~5107I~
                    {                                              //~v54aI~
                     if (!grepsw)                                  //~v78dI~
                     {                                             //~v78dI~
                      if (!(                                       //~va3EI~
                               Sddstrlen	//ddstr search         //~va3EI~
//*ddlen set to 0 when tabsrch, Sescsrchlen,esclen at fcmdisddsrch //~va3EI~
    				       &&  (plh->ULHlen-offset>=Sddstrlen)	//may not match//~va3EI~
                           )                                       //~va3EI~
                      )                                            //~va3EI~
                      {                                            //~va3EI~
                      if (Snotsrchsw)  //*! search                 //~v41rM~
                        break;                                     //~v41rM~
                      else                                         //~v41rM~
    					continue;                                       //~5107I~
                      }                                            //~va3EI~
                     }//!grep                                      //~v78dI~
                    }//offset                                      //~v54aI~
			  		if (Stabsrchsw)                                      //~v09II~
              		{	                                                   //~v09II~
//              		rc=fcmdtabsrch(plh,SUBCMD_NEXT,offset,&pc);	//forward search//~v0eBR~
//              		rc=fcmdtabsrch(plh,SUBCMD_NEXT,offset,&pc,Srange1,Srange2);	//forward search//~v11sR~
                		rc=fcmdtabsrch(plh,SUBCMD_NEXT,offset,&pc,Srange1,Srange2,Sescsrchchar,Sescsrchlen);	//forward search//~v11sI~
                		if (rc)	                                           //~v09II~
                  			return rc;                                     //~v09II~
              		}                                                    //~v09II~
              		else                                                 //~v09II~
#ifdef UTF8SUPPH                                                   //~va1GR~
					if (Sutf8echsrchsw) //search utf8 trans err char//~va1GR~
              		{                                              //~va1GR~
                		rc=fcmdutf8echsrch(plh,SUBCMD_NEXT,offset,&pc,Srange1,Srange2);	//forward search//~va1GR~
                		if (rc)                                    //~va1GR~
                  			return rc;                             //~va1GR~
              		}                                              //~va1GR~
              		else//not err ch search                        //~va1GR~
#endif                                                             //~va1GR~
              		{                                                    //~v09II~
//                  	if (spacesw && !plh->ULHdbcs)	//if space contained//~v41rR~
//                      	if (filechktabdbcs(plh)==UALLOC_FAILED)//expand before compare//~v41rR~
//                          	return UALLOC_FAILED;              //~v41rR~
                                                                   //~v13oI~
                        offset0=offset; //save for each loop       //~v0eBI~
    					for (;;)                                            //~4C30I~
    					{                                                   //~4C30I~
    						pc=plh->ULHdata;                                //~4C30R~
                            pcd=plh->ULHdbcs;                      //~v0eBI~
                            offset=offset0;                        //~v0eBI~
                            srchlen=plh->ULHlen;                   //~v0eBI~
                            if (Seolsrchsw)	//word on eol search   //~v47BI~
                            {                                      //~v47BI~
                            	eoloffset=plh->ULHlen-Ssrchlen;    //~v47BI~
                            	if (offset<eoloffset)              //~v47BI~
                                	offset=eoloffset;              //~v47BI~
                                if (!Ssrchlen)	//wothout preceding string//~v54zI~
                        			if (pcd)  //tab expanded       //~v54zI~
                                    {                              //~v54zI~
//                                      if (Srangeid2==RANGE1ONLY)//Srange1==Srange2//~v54RR~
                                        if (Srangeid2==RANGE1ONLY //Srange1==Srange2//~v54RI~
                                        ||  Srangeid2==RANGEMAX)  //Srange1==Srange2//~v54RI~
                                        {                          //~v54zI~
                                            if (eoloffset!=Srange1)//~v54zI~
                                            {                      //~v54zI~
                                                pc=0;       //not found//~v54zI~
                                                break;             //~v54zI~
                                            }                      //~v54zI~
                                        }                          //~v54zI~
                                        else                       //~v54zI~
                                            if (!(eoloffset>=Srange1//~v54zI~
                                                  && eoloffset<Srange2))//range2 is next of specified col//~v54zI~
                                            {                      //~v54zI~
                                                pc=0;       //not found//~v54zI~
                                                break;             //~v54zI~
                                            }                      //~v54zI~
                                    }//pcd                         //~v54zI~
                            }                                      //~v47BI~
                            if (pcd)                               //~v0eBI~
                            {                                      //~v0eBI~
                                if (offset<Srange1) //out of range //~v0eBI~
                                    offset=Srange1;                //~v0eBI~
                                if (srchlen>Srange2) //out of range//~v0eBI~
                                    srchlen=Srange2;               //~v0eBI~
                            }                                      //~v0eBI~
                            pc+=offset;                            //~v0eBI~
                            srchlen-=offset;                       //~v0eBI~
                          if (!(Seolsrchsw && Ssrchlen==0))	//with len=0//~v54zR~
                            if (srchlen<=0)                        //~v0eBI~
                            if (srchlen<0 || !Sexcludesw2)   //not exclude cmd//~v10TR~
                            {                                      //~v0eBI~
                            	pc=0;                              //~v0eBI~
                                break;                             //~v0eBI~
                            }                                      //~v0eBI~
#ifdef REGEXSUPP                                                   //~v78qI~
                         if (grepsw)                               //~v78dM~
                         {                                         //~v78dM~
                         	fcmdgrepplh(FCGPO_FWD,Ppcw,plh,pc,srchlen,Scasesensesw,&pc,&matchlen);//~v78dM~
                         }                                         //~v78dM~
                         else                                      //~v78dM~
                         {                                         //~v78dM~
#endif                                                             //~v78qR~
				  			if (Sescsrchlen)                                 //~v09OR~
                            {                                      //~va20R~
#ifdef UTF8UCS2                                                    //~va20R~
							  if (swutf8file)                      //~va20I~
                              {                                    //~va20I~
                  				optdds=FCMDDDSSO_ESC|FCMDDDSSO_NEXT;//~va20R~
                  				pc=fcmdddstrsrch(optdds,plh,Sescsrchchar,Spdddbcs/*dummy*/,Sescsrchlen,pc,srchlen,&ucswordlen);//~va20R~
                              }                                    //~va20I~
                              else                                 //~va20R~
#endif                                                             //~va20R~
//                				pc=fcmdescsrch(pc+offset,SUBCMD_NEXT,plh->ULHlen-offset);//~v0eBR~
                  				pc=fcmdescsrch(pc,SUBCMD_NEXT,srchlen);//~v0eBI~
                            }                                      //~va20I~
				  			else	                                           //~v09LI~
                              if (Ssrchlen)     //exclude case     //~v10TI~
                              {                                    //~v54aI~
#ifdef UTF8UCS2                                                    //~va20I~
							   if (Sddstrlen)                      //~va20R~
                               {                                   //~va20I~
                  				optdds=FCMDDDSSO_NEXT|FCMDDDSSO_DDSTR;//~va20R~
    							if (!Scasesensesw)	//case sensitive//~va20R~
                  					optdds|=FCMDDDSSO_NOCASE;      //~va20R~
                  				pc=fcmdddstrsrch(optdds,plh,Spddstr,Spdddbcs,Sddstrlen,pc,srchlen,&ucswordlen);//~va20R~
                               }                                   //~va20I~
                               else                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
							   if (Sebcstrlen)                     //~va50I~
                               {                                   //~va50I~
      							if (Scasesensesw)	//case sensitive//~va50I~
    								pc=ucvebc_umemmem(0,pc,XEUTF_PLHPC2PCD(plh,pc),srchlen,Spebcstr,Spebcdbcs,Sebcstrlen);//~va50R~
    							else				//case insensitive//~va50I~
//  								pc=ucvebc_umemmemi(0,pc,XEUTF_PLHPC2PCD(plh,pc),srchlen,Spebcstr,Spebcdbcs,Sebcstrlen);//~va50R~//~va79R~
    								pc=ucvebc_umemmemi(0,handle,pc,XEUTF_PLHPC2PCD(plh,pc),srchlen,Spebcstr,Spebcdbcs,Sebcstrlen);//~va79I~
                               }                                   //~va50I~
                               else                                //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                               {                                   //~va20I~
//    							if (Scasesensesw)	//case sensitive//~v10QR~
//    							if (Scasesensesw||Pchangeopt)	//case sensitive//~v10QI~,//~v72PR~
      							if (Scasesensesw)	//case sensitive//~v72PI~
//  								pc=ustrnstr(pc+offset,Ssrch,(UINT)(plh->ULHlen-offset));//~v0a1R~
//  								pc=umemstr(pc+offset,Ssrch,(UINT)(plh->ULHlen-offset));//~v0eBR~
//*not on dd fmt utf8 file                                         //~va20I~
    								pc=umemstr(pc,Ssrch,(UINT)srchlen);//~v0eBI~
    							else				//case insensitive          //~4C30R~
                                {                                  //~va3QI~
//  								pc=ustrnstri(pc+offset,Ssrch,(UINT)(plh->ULHlen-offset));//~v0a1R~
//                                  pc=umemstri(pc+offset,Ssrch,(UINT)(plh->ULHlen-offset));//~v0eBR~
                                  if (plh->ULHdbcs)                //~va3QI~
//                                  pc=umemstridbcs(0,pc,XEUTF_PLHPC2PCD(plh,pc),Ssrch,(UINT)srchlen);//~va3QR~//~vb2pR~
                                    pc=umemstridbcs(0,pc,XEUTF_PLHPC2PCD(plh,pc),Ssrch,srchlen);//~vb2pI~
                                  else                             //~va3QI~
    								pc=umemstri(pc,Ssrch,(UINT)srchlen);//~v0eBI~
                                }//case insensitive                //~va3QI~
                               }                                   //~va20I~
                              }//srchlen                           //~v54aI~
                              else                                 //~v54zI~
                              {                                    //~v54zI~
                               	if (Seolsrchsw)	//word on eol search//~v54zI~
                                	pc=plh->ULHdata+plh->ULHlen;   //~v54zI~
                              }//srchlen==0                        //~v54zI~
#ifdef REGEXSUPP                                                   //~v78qI~
                         }//!grep                                  //~v78dI~
#endif                                                             //~v78qR~
                    		rc=0;                                           //~v04dI~
//                            if (!pc                              //~v0eBR~
//                            ||  (rc=filechktabdbcs(plh),rc))    //no tab or tab processed//~v0eBR~
//                            {                                    //~v0eBR~
//                                if (rc==UALLOC_FAILED)           //~v0eBR~
//                                    return UALLOC_FAILED;        //~v0eBR~
//                                break;                           //~v0eBR~
//                            }//!pc                               //~v0eBR~
                            if (!pc)                               //~v0eBI~
                                break;                             //~v0eBI~
                            rc=filechktabdbcs(plh);                //~v0eBI~
                            if (rc==UALLOC_FAILED)                 //~v0eBI~
                                return UALLOC_FAILED;              //~v0eBI~
                            if (rc)    //no tab or tab processed   //~v0eBI~
                            {                                      //~v54aI~
                                if ((int)Srangeid2==RANGENOPARM) //old fashion//~v437R~
                                {                                  //~v74ER~
                            		if (pcd)	//range chked      //~v74ER~
                                		break;                     //~v74ER~
                                  if (pfh->UFHbndscol1==0 && pfh->UFHbndscol2==0)//no bound specified//~v74ER~
                                    break;                         //~v0eBI~
                                }                                  //~v74ER~
                                else                               //~v0eBI~
                                    if (pcd)    //range chked      //~v0eBI~
                                        break;                     //~v0eBI~
                            }//rc                                  //~v54aI~
    					}//for                                                   //~4C30I~
              		}//tab search or not                                 //~v09II~
                  }//split consideration                           //~v13pI~
                  if (Snotsrchsw)    //search lines dose not contain the word//~v41rI~
                  {                                                //~v41rI~
    				if (!pc)	//found last                       //~v41rI~
    				{                                              //~v41rI~
    					offset=0;  //always 0 when notsrch         //~v41rR~
    					break;                                     //~v41rI~
    				}                                              //~v41rI~
                  }                                                //~v41rI~
                  else                                             //~v41rI~
    				if (pc)
    				{
//    					offset=(int)((ULONG)pc-(ULONG)plh->ULHdata);//~vafkR~
    					offset=(int)((ULPTR)pc-(ULPTR)plh->ULHdata);//~vafkI~
    					break;
    				}
    			}//all plh
        	}							//edit/browse               //~v05wI~
//  	if (plh)                                                   //~v0hkR~
//  	if (plh && plh!=Srangeplhe)//not eached to 'B'             //~v0hxR~
    	if (plh && plh!=Srangeplhe                                 //~v0hxR~
    	&&  plh!=Srangeplhe2                                       //~v43eI~
        &&  !Slinerangesw)			//not initialy out of range    //~v0hxR~
        {                                                          //~v0hEI~
          if (Plocatesw)  //not 2nd of all                         //~v0hEI~
          {                                                        //~v54aI~
			if (Pchangeopt)                                     //~5106I~
				uerrmsg("Forward Change",                       //~5106I~
						"下置換");                                 //~v11gR~
			else                                                //~5106I~
		  	  	if (Swrapsw)	//wrap search                          //~v09cI~
					uerrmsg("Forward Re-search from top",              //~v09cI~
							"最初からの再-下探索");                //~v11gR~
    		  	else                                                 //~v09cI~
					uerrmsg("Forward Search",                       //~5106R~
							"下探索");                             //~v11gR~
          }//locatesw                                              //~v54aI~
        }                                                          //~v0hEI~
		else
        {                                                          //~v0hxR~
//            if (Plocatesw)  //not 2nd of all                     //~v0hxR~
//                Snotfinpctr=Gkbdinpctr; //save kbd input ctr to chk continuous ope//~v0hxR~
//            if (Pchangeopt)                                      //~v0hxR~
//                caseid="C";                                      //~v0hxR~
//            else                                                 //~v0hxR~
//                if (Scasesensesw)                                //~v0hxR~
//                    caseid="F";                                  //~v0hxR~
//                else                                             //~v0hxR~
//                    caseid="I";                                  //~v0hxR~
//            if (Swrapsw)    //wrap search                        //~v0hxR~
//                uerrmsg("%s:None in this file(%s)",              //~v0hxR~
//                        "%s:一つも見つかりません(%s)",           //~v0hxR~
//                        caseid,Ssrch);                           //~v0hxR~
//            else                                                 //~v0hxR~
//              if (Srangeplhe && plh==Srangeplhe)                 //~v0hxR~
//                uerrmsg("%s:Reached to End of Specified line range(%s)",//~v0hxR~
//                        "%s:行範囲指定の限界に達しました(%s)",   //~v0hxR~
//                        caseid,Ssrch);                           //~v0hxR~
//              else                                               //~v0hxR~
//                uerrmsg("%s:Reached to End of file(%s)",         //~v0hxR~
//                        "%s:ファイルの終りに達しました(%s)",     //~v0hxR~
//                        caseid,Ssrch);                           //~v0hxR~
//            return 4;                                            //~v0hxR~
			if (Sfindopt & FINDOPT_JOINEOF)    //join to eof if 2nd word is not found//~v58rI~
          		if (Sphasesw==2)  //2nd of & search                //~v58rI~
          		{                                                  //~v58rI~
                	if (!plh)	//reached to eof                   //~v58rI~
                    {                                              //~v58rI~
//  					plh=UGETQPREV(UGETQEND(&pfh->UFHlineque)); //~v58rR~
    					plh=UGETQEND(&pfh->UFHlineque);            //~v58rI~
                        joineofsw=1;	//join to EOF              //~v58rR~
                	}                                              //~v58rI~
                    else                                           //~v58rI~
			    		if (plh==Srangeplhe)	//label range      //~v58rI~
                        {                                          //~v58rI~
//  						plh=UGETQPREV(plh);                    //~v58rR~
	                        joineofsw=1;	//join to EOF          //~v58rI~
                        }                                          //~v58rI~
	        	}                                                  //~v58rI~
          if (!joineofsw)                                          //~v58rR~
	    	return fcmdsrcherr(Pchangeopt,Plocatesw,Psubcmdid,plh);//~v0hxR~
		}//plh==0
	}//by subcmd
//*replace if change cmd                                        //~5106R~
    if (matchlen)                                                  //~v78dI~
		Ssrchlen=matchlen;       //reverse display len             //~v78dI~
	if (Pchangeopt)                                             //~5106I~
		wordlen=Srepwordlen;	//reverse display length        //~5106I~
    else                                                        //~5106I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
	if (Sebcstrlen)                                                //~va50R~
        wordlen=Sebcstrlen;                                        //~va50M~
    else                                                           //~va50M~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
//#ifdef LNX                                                         //~vauiI~//~vauFR~
    if (Ppcw->UCWtype==UCWTDIR && Sdirsrchlen)     //on dir list   //~vauiR~
		wordlen=Sdirsrchlen;                                       //~vauiR~
    else                                                           //~vauiI~
//#endif                                                             //~vauiI~//~vauFR~
		wordlen=Ssrchlen;       //reverse display len           //~5106I~
#ifdef UTF8UCS2                                                    //~va20I~
	if (swutf8file)                                                //~va20I~
    {                                                              //~va20I~
        Sucswordlen=ucswordlen; //parm to wordrep                  //~va20I~
        if (ucswordlen)                                            //~va20I~
        {                                                          //~va20I~
            wordlen=ucswordlen;                                    //~va20R~
        	ucswordlen=0;                                          //~va20R~
        }                                                          //~va20I~
    }                                                              //~va20I~
#endif                                                             //~va20I~
//*replace if change cmd                                        //~5107I~
    rc=0;                                                       //~5107I~
	if (Pchangeopt)                                             //~5107I~
    {                                                              //~v49bI~
      if (Sulsrchsw==LINE_SAMESRCH)       //*=                     //~v49bI~
      {                                                            //~v49bI~
          for (plhsamerep=UGETQNEXT(plh);plhsamerep;)              //~v49bR~
          {                                                        //~v49bI~
              if (wordrep(Ppcw,plhsamerep,offset))    //replace word,must before ULHFCURFOUND on//~v49bI~
                  rc=8;                       //need draw/curfound flag on//~v49bI~
              if (plhsamerep==Ssamelastplh)                        //~v49bI~
                  break;                                           //~v49bI~
              plhsamerep=UGETQNEXT(plhsamerep);                    //~v49bI~
          }                                                        //~v49bI~
      }                                                            //~v49bI~
      else                                                         //~v49bI~
      {                                                            //~va50I~
     	if (wordrep(Ppcw,plh,offset))	//replace word,must before ULHFCURFOUND on//~5107I~
        {                                                       //~5107I~
			rc=8;                       //need draw/curfound flag on//~5107I~
			wordlen=Ssrchlen;       //reverse findlen           //~5107I~
        }                                                       //~5107I~
#ifdef UTF8UCS2                                                    //~va20I~
        else                                                       //~va20I~
			wordlen=Srepwordlen;	//may changed at wordrep for utf8 file//~va20I~
        if (rc)                                                    //~va5RI~
        	return rc;                                             //~va5RI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (Srcsosi)	//ebc SO replaced                          //~va50I~
        	offset--;                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
      }                                                            //~va50I~
#endif                                                             //~va20I~
    }                                                              //~v49bI~
//*excluded line chk for x cmd                                     //~v43cI~
    multlinexsw|=(Sexcludesw2 && Ssamelastplh);                    //~v49dI~
    if (multlinexsw)//x cmd need multiline consideration           //~v43cI~
    {                                                              //~v49bI~
//      if (!fcmdallxchk(plh,Sspanplh,Sandplh1,Slinebefore,Slineafter))//all excluded//~v49bR~
        if (!fcmdallxchk(plh,Sspanplh,Ssamelastplh,Sandplh1,Slinebefore,Slineafter))//all excluded//~v49bI~
        {                                                          //~v43cI~
            Sallxfound=1;   //retry req                            //~v43cI~
            if (Sulsrchsw==LINE_SAMESRCH)                          //~v49bI~
            {                                                      //~v49bI~
                if (Ssubcmdid==SUBCMD_PREV) //backword             //~v49bI~
                {                                                  //~v49bI~
                    plh=UGETQPREV(plh);                            //~v49bI~
                    offset=plh->ULHlen;                            //~v49bI~
                }                                                  //~v49bI~
                else //forward                                     //~v49bI~
                {                                                  //~v49bI~
                    plh=UGETQNEXT(Ssamelastplh);                   //~v49bI~
                    offset=0;                                      //~v49bI~
                }                                                  //~v49bI~
            }                                                      //~v49bI~
            *Ppplh=plh;         //retry point                      //~v43cI~
            *Ppoffset=offset;                                      //~v43cI~
            return 4;   //not found                                //~v43cI~
        }                                                          //~v43cI~
    }                                                              //~v49bI~
//*excluded line display                                        //~5106R~
//    if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))                   //~v43cR~
//    {                                                            //~v43cR~
////    if (Ppcw->UCWtype==UCWTDIR)     //on dir list              //~v43cR~
////      UCBITOFF(plh->ULHflag2,ULHF2EXCLUDED);                   //~v43cR~
////    else                                                       //~v43cR~
//      if (Ppcw->UCWtype!=UCWTDIR)     //on dir list              //~v43cR~
//      {                                                          //~v43cR~
//        if (!Supctrsw)      //first time                         //~v43cR~
//        {                                                        //~v43cR~
//            Supctrsw=1;     //req upctrreq at end                //~v43cR~
//            UPCTRREQ(pfh);                                       //~v43cR~
//        }                                                        //~v43cR~
//        if (lcmdincm(Ppcw,plh)==UALLOC_FAILED)  //display excluded line//~v43cR~
//            return UALLOC_FAILED;                                //~v43cR~
//                                                                 //~v43cR~
//        if (Sspanplh)                                            //~v43cR~
//            for (plhw=plh;plhw=UGETQNEXT(plhw),plhw;)            //~v43cR~
//            {                                                    //~v43cR~
//                if (plhw->ULHtype==ULHTDATA)                     //~v43cR~
//                  if (UCBITCHK(plhw->ULHflag2,ULHF2EXCLUDED))    //~v43cR~
//                    if (lcmdincm(Ppcw,plhw)==UALLOC_FAILED) //display excluded line//~v43cR~
//                        return UALLOC_FAILED;                    //~v43cR~
//                if (plhw==Sspanplh)                              //~v43cR~
//                    break;                                       //~v43cR~
//            }                                                    //~v43cR~
//                                                                 //~v43cR~
//      }//edit/browse                                             //~v43cR~
//    }                                                            //~v43cR~
//    else                                                         //~v43cR~
//        if (Sexcludesw2)    //exclude on edit/browse             //~v43cR~
//        {                                                        //~v43cR~
//            if (!Supctrsw)                                       //~v43cR~
//            {                                                    //~v43cR~
//                Supctrsw=1;     //req upctrreq at end            //~v43cR~
//                UPCTRREQ(pfh);                                   //~v43cR~
//            }                                                    //~v43cR~
//            lcmdclearlcmd(pfh,plh); //clear pending cmd          //~v43cR~
//            if (lcmdexc(Ppcw,plh,plh,(Plocatesw!=0))==UALLOC_FAILED)    //excluded one line//~v43cR~
//                return UALLOC_FAILED;                            //~v43cR~
//            if (Sspanplh)                                        //~v43cR~
//                for (plhw=plh;plhw=UGETQNEXT(plhw),plhw;)        //~v43cR~
//                {                                                //~v43cR~
//                    if (plhw->ULHtype==ULHTDATA)                 //~v43cR~
//                        if (!UCBITCHK(plhw->ULHflag2,ULHF2EXCLUDED))//~v43cR~
//                            if (lcmdexc(Ppcw,plhw,plhw,(Plocatesw!=0))==UALLOC_FAILED)  //excluded one line//~v43cR~
//                                return UALLOC_FAILED;            //~v43cR~
//                    if (plhw==Sspanplh)                          //~v43cR~
//                        break;                                   //~v43cR~
//                }                                                //~v43cR~
//        }                                                        //~v43cR~
//        else //found line not excluded                           //~v43cR~
//        {                                                        //~v43cR~
//            if (Sspanplh)                                        //~v43cR~
//                for (plhw=plh;plhw=UGETQNEXT(plhw),plhw;)        //~v43cR~
//                {                                                //~v43cR~
//                    if (plhw->ULHtype==ULHTDATA)                 //~v43cR~
//                        if (UCBITCHK(plhw->ULHflag2,ULHF2EXCLUDED))//~v43cR~
//                            if (lcmdincm(Ppcw,plhw)==UALLOC_FAILED) //display excluded line//~v43cR~
//                                return UALLOC_FAILED;            //~v43cR~
//                    if (plhw==Sspanplh)                          //~v43cR~
//                        break;                                   //~v43cR~
//                }                                                //~v43cR~
//        }                                                        //~v43cR~
 if (Sallkxinpctr!=Gkbdinpctr)	//effective only at once           //~v537I~
 {                                                                 //~v537I~
    if (Ppcw->UCWtype!=UCWTDIR)     //on dir list                  //~v43cI~
  {                                                                //~v54aI~
//  	fcmdspannedline(Ppcw,pfh,plh,Sspanplh,Sexcludesw2,Plocatesw);//~v47tR~
    if (Slinebefore||Slineafter)	//display before/after line    //~v437I~
    {                                                              //~v547I~
//  	fcmdaroundline(Ppcw,pfh,plh,Slinebefore,Slineafter,Sexcludesw2);//~v49bR~
//  	fcmdaroundline(Ppcw,pfh,plh,Ssamelastplh,Slinebefore,Slineafter,Sexcludesw2);//~v547R~
//  	if (fcmdaroundline(Ppcw,pfh,&plh,Ssamelastplh,Slinebefore,Slineafter,Sexcludesw2))//~v548R~
//  	if (fcmdaroundline(Ppcw,pfh,&plh,Ssamelastplh,Slinebefore,Slineafter,Sexcludesw2,&offset))//~v612R~
    	rc=fcmdaroundline(Ppcw,pfh,&plh,Ssamelastplh,Slinebefore,Slineafter,Sexcludesw2,&offset);//~v612R~
        if (rc)                                                    //~v612R~
        {                                                          //~v612R~
//      	if (rc==RC_STOP_SRCH)                                  //~v613R~
//          	return rc;                                         //~v613R~
//          return 4;   //lcmdjoin failed                          //~v613R~
            return rc;  //lcmdjoin failed                          //~v613I~
        }                                                          //~v612R~
    }                                                              //~v547I~
    else                                                           //~v47tI~
    {                                                              //~v54BI~
//  	fcmdspannedline(Ppcw,pfh,plh,Sspanplh,Sexcludesw2,Plocatesw);//~v49bR~
		rc=                                                        //~v54BI~
    	fcmdspannedline(Ppcw,pfh,plh,Sspanplh,Ssamelastplh,Psubcmdid,Sexcludesw2,Plocatesw);//~v49bR~
        if (rc)                                                    //~v54BI~
        	return rc;                                             //~v54BI~
    }                                                              //~v54BI~
  }//tdir                                                          //~v54aI~
 }//not allkx                                                      //~v537I~
//*page scroll                                                  //~5106R~
	if (Plocatesw)	//locate to found word
	{
//  	pfh->UFHfindctr++;		//find cmd ctr;                    //~v43gR~
      if (Sexcludesw2)	//on edit/browse                           //~v0hzR~
      {                                                            //~v0hzM~
       if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))                  //~v47tI~
	    plhw=getdisplayline(plh,-1,0);	//back to EXCLUDE line     //~v0hzI~
       else                       //1st line is not range of -a -b //~v47tR~
	    plhw=plh;                                                  //~v47tI~
        if (plh==pfc->UFCcurtop)                                   //~v0hzI~
            pfc->UFCcurtop=plhw;    //keep cur top                 //~v0hzI~
//		fcmdscrollpage(Ppcw,plhw);                                 //~v11gR~
//		fcmdscrollpagemid(Ppcw,plhw);                              //~v59ZR~
        fcmdfindscroll(Ppcw,plhw,Sfindopt2);                       //~v59ZI~
    	filesetcsr(Ppcw,plhw,0,0);		//csr set by lcmdexc       //~v0hzR~
	  }                                                            //~v0hzM~
      else                                                         //~v0hzM~
      {				//not exclude                                  //~v0hzI~
//*move page to the line if not on current page                 //~5104R~
//  	fcmdscrollpage(Ppcw,plh);                                  //~v11gR~
	   if (Sphasesw==1)                                            //~v54WI~
		Sscrollpendsw=1;	//scroll when 2nd word found           //~v54WI~
       else                                                        //~v54WI~
//  	fcmdscrollpagemid(Ppcw,plh);                               //~v59ZR~
        fcmdfindscroll(Ppcw,plh,Sfindopt2);                        //~v59ZI~
                                                                //~5104I~
//    	if (Sulsrchsw)            //update line search             //~v41rR~
//    	if (linesrchsw)          //*u,*e,*!                        //~v49bR~
      	if (linesrchsw           //*u,*e,*!                        //~v49bI~
      	&&  Sulsrchsw!=LINE_SAMEMATCH  //*= matching               //~v62dI~
      	&&  Sulsrchsw!=LINE_SAMESRCH)  //*=                        //~v49bI~
        	if (linenosz)                                              //~v09eI~
				filesetcsr(Ppcw,plh,0,linenosz-1);//csr set on update sign//~v09eI~
			else                                                       //~v09eI~
				filesetcsr(Ppcw,plh,1,0);		//csr set on col 1     //~v09eI~
      	else                                                         //~v09eI~
      	{                                                            //~v09eI~
			width=Ppcw->UCWwidth-Ppcw->UCWlinenosz;                 //~v069R~
//        if (Sfindopt & FINDOPT_CSRTOP)                           //~v59ZR~
          if (Ppcw->UCWtype!=UCWTDIR    //not on dir list          //~v59ZI~
          &&  Sfindopt2 & FINDOPT2_CSRCENTER)	//csr left/right option specified//~v59ZR~
          {                                                        //~v43dI~
           if (Sfindopt2 & FINDOPT2_CSRRIGHT) //display at leftmost//~v59ZI~
           {                                                       //~v59ZI~
            csrpos=(int)((Sfindopt2&FINDOPT2_CSRCOLMASK)>>8)+1;    //~v59ZR~
    		if (csrpos>=width) //righ display width over scr width //~v59ZR~
            	csrpos=0;                                          //~v59ZR~
            else                                                   //~v59ZI~
	            csrpos=width-csrpos;	//dirsplay right with parm width//~v59ZR~
//  		if (offset>=width)                                     //~v59ZR~
    		if (offset>csrpos)                                     //~v59ZI~
//          	leftpos=offset-width+1; 	//display word top byte//~v59ZR~
            	leftpos=offset-csrpos; 	//display word top byte    //~v59ZR~
            else                                                   //~v43dI~
            {                                                      //~v59ZI~
                csrpos=offset;                                     //~v59ZI~
            	leftpos=0;                                         //~v43dI~
            }                                                      //~v59ZI~
            if (leftpos!=pfc->UFCleft)                             //~v43dI~
            {                                                      //~v43dI~
				pfc->UFCleft=leftpos;                              //~v43dR~
				UCBITON(Ppcw->UCWflag,UCWFDRAW);                   //~v43dI~
            }                                                      //~v43dI~
//  		filesetcsr(Ppcw,plh,1,offset-leftpos);                 //~v59ZR~
    		filesetcsr(Ppcw,plh,1,csrpos);                         //~v59ZR~
          }//right                                                 //~v59ZI~
          else                                                     //~v59ZI~
          	if (Sfindopt2 & FINDOPT2_CSRLEFT) //display at leftmost//~v59ZI~
          	{                                                      //~v59ZI~
            	csrpos=(int)((Sfindopt2&FINDOPT2_CSRCOLMASK)>>8);  //~v59ZI~
                csrpos=min(csrpos,width-1);	//display word always  //~v59ZR~
                if (offset<csrpos)                                 //~v59ZI~
                {                                                  //~v59ZI~
                    leftpos=0;      //from col0                    //~v59ZI~
                    csrpos=offset;  //csr on word                  //~v59ZI~
                }                                                  //~v59ZI~
                else                                               //~v59ZI~
                	leftpos=offset-csrpos;                         //~v59ZR~
                if (leftpos!=pfc->UFCleft)                         //~v59ZR~
                {                                                  //~v59ZI~
                    pfc->UFCleft=leftpos;                          //~v59ZR~
                    UCBITON(Ppcw->UCWflag,UCWFDRAW);               //~v59ZI~
                }                                                  //~v59ZI~
                filesetcsr(Ppcw,plh,1,csrpos);                     //~v59ZR~
            }                                                      //~v59ZI~
          }//csr option for edit area                              //~v59ZR~
          else                                                     //~v43dI~
//dirlist or no csr option                                         //~v59ZI~
          {                                                        //~v43dI~
			if (offset<pfc->UFCleft
//			||  pfc->UFCleft				//not left most        //~v0huR~
			|| 	offset>=pfc->UFCleft+width)
			{
	    		if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK))             //~v0dvR~
            	{                                                      //~v0dvI~
            		if (offset>=pfc->UFCleft+width)                    //~v0dvR~
            			filepgrighthalf(Ppcw);                         //~v0dvR~
            	}                                                      //~v0dvI~
            	else                                                   //~v0dvI~
            	{                                                      //~v0dvI~
            		scrollsz=filehalfhscrollsz(Ppcw);//half scroll size //~v013R~
					pfc->UFCleft=max(0,(offset/scrollsz)*scrollsz-scrollsz);//~v013R~
					UCBITON(Ppcw->UCWflag,UCWFDRAW);
            	}                                                      //~v0dvI~
			}
        	if (Ppcw->UCWtype==UCWTDIR)    //on dir list            //~v05wI~
				filesetcsr(Ppcw,plh,FROMLEFT,offset);//csr set on rename fld//~v05wI~
        	else                                                    //~v05wI~
				filesetcsr(Ppcw,plh,1,offset-pfc->UFCleft);//csr set    //~5223R~
          }//by csr option                                         //~v43dI~
      	}//update line search or not                                 //~v09eI~
      }				//not exclude                                  //~v0hzI~
//  	Spfhfindctr=pfh->UFHfindctr;                               //~v43gR~
		Sfoundplh=plh;	
		Sfoundoffs=offset;	            //to chk continuas rfind//~5107R~
		Schangeopt=Pchangeopt;			//for next rchange      //~5107I~
//  	Sfoundctr=0;					//count up at return       //~v43fR~
//		Smfwtovf=0;						//overflow point           //~v43fR~
//		*Gfilemfwtbl=(USHORT)wordlen;	//len to first entry       //~v43fR~
//		Smfwtindex=1;					//offset to second entry   //~v43fR~
//    	if (Sulsrchsw)            //update line search             //~v41rR~
//        if (linesrchsw)            //update line search          //~v43fR~
//            plh->ULHrevoffs=ULHULFOUND;     //ipdate line search result id//~v43fR~
//        else                                                     //~v43fR~
//            plh->ULHrevoffs=(USHORT)offset;                      //~v43fR~
//        Sstep=plh->ULHrevlen=(USHORT)wordlen;//reverse len,next rfind step//~v43fR~
//        UCBITOFF(plh->ULHflag2,ULHF2MFOUND);//reset multiple     //~v43fR~
//        if (Sspanplh)                       //spaned word        //~v43fR~
//            fcmdsplitdisplay(plh,Sspanplh,offset,Sstep,Spfhfindctr);//set on 2nd line also//~v43fR~
        Sstep=(USHORT)wordlen;//reverse len,next rfind step        //~v43fI~
	}//first time
    else    //2nd of ALL                                           //~v78dI~
    {                                                              //~v78dI~
      if (matchlen)     //wordlen changes each time                //~v78dI~
        Sstep=(USHORT)wordlen;//reverse len,next rfind step        //~v78dI~
    }                                                              //~v78dI~
                                                                   //~v78dI~
//    else        //second call for "all"                          //~v43fR~
//    {                                                            //~v43fR~
//        if (plh->ULHrevctr==pfh->UFHfindctr)    //               //~v43fR~
//        {                                                        //~v43fR~
//            if (UCBITCHK(plh->ULHflag2,ULHF2MFOUND))//already multiple//~v43fR~
//            {                                                    //~v43fR~
//                if (Smfwtindex<=MAXMFWTENTRY)                    //~v43fR~
//                {                                                //~v43fR~
//                    plh->ULHrevlen++;   //wordcount              //~v43fR~
//                    *(Gfilemfwtbl+Smfwtindex++)=(USHORT)offset;  //~v43fR~
//                }                                                //~v43fR~
//                else                                             //~v43fR~
//                    if (!Smfwtovf)                               //~v43fR~
////                  {                                            //~v43fR~
////                      UCBITON(plh->ULHflag,ULHFDRAW|ULHFCURFOUND);//~v43fR~
//                        Smfwtovf=Sfoundctr;                      //~v43fR~
////                  }                                            //~v43fR~
//            }                                                    //~v43fR~
//            else    //first multiple                             //~v43fR~
//            {                                                    //~v43fR~
//                if (Smfwtindex<MAXMFWTENTRY)                     //~v43fR~
//                {                                                //~v43fR~
//                    UCBITON(plh->ULHflag2,ULHF2MFOUND);//multiple//~v43fR~
//                    *(Gfilemfwtbl+Smfwtindex)=plh->ULHrevoffs;   //~v43fR~
//                    plh->ULHrevoffs=(USHORT)Smfwtindex++;//strat pos//~v43fR~
//                    *(Gfilemfwtbl+Smfwtindex++)=(USHORT)offset;  //~v43fR~
//                    plh->ULHrevlen=2;           //wordcount      //~v43fR~
//                }                                                //~v43fR~
//                else                                             //~v43fR~
//                    if (!Smfwtovf)                               //~v43fR~
////                  {                                            //~v43fR~
////                      UCBITON(plh->ULHflag,ULHFDRAW|ULHFCURFOUND);//~v43fR~
//                        Smfwtovf=Sfoundctr;                      //~v43fR~
////                  }                                            //~v43fR~
//            }                                                    //~v43fR~
//        }                                                        //~v43fR~
//        else    //first found on the line                        //~v43fR~
//        {                                                        //~v43fR~
////          if (Sulsrchsw)            //update line search       //~v43fR~
//            if (linesrchsw)            //update line search      //~v43fR~
//                plh->ULHrevoffs=ULHULFOUND; //ipdate line search result id//~v43fR~
//            else                                                 //~v43fR~
//                plh->ULHrevoffs=(USHORT)offset;                  //~v43fR~
//            plh->ULHrevlen=(USHORT)wordlen;                      //~v43fR~
//            UCBITOFF(plh->ULHflag2,ULHF2MFOUND);//reset multiple //~v43fR~
//        }                                                        //~v43fR~
//    }                                                            //~v43fR~
//  Sfoundctr++;                                                   //~v43sR~
	fcmdsetfindhighlight(pfh,plh,Plocatesw,linesrchsw,offset,wordlen,Sspanplh);//~v43fI~
	*Ppplh=plh;	
	*Ppoffset=offset;	
    if (Sulsrchsw==LINE_SAMESRCH)  //*=                            //~v49bI~
    {                                                              //~v58ZI~
    	samepartctr=Sfoundctr;                                     //~v58ZI~
        for (plh=UGETQNEXT(plh);plh;)                              //~v49bR~
        {                                                          //~v49bI~
          if (plh->ULHtype==ULHTDATA)   //skip count hdr           //~v58ZI~
            fcmdsetfindhighlight(pfh,plh,0,linesrchsw,offset,wordlen,Sspanplh);//locatesw=0//~v49bI~
            if (plh==Ssamelastplh)                                 //~v49bI~
                break;                                             //~v49bI~
            plh=UGETQNEXT(plh);                                    //~v49bR~
        }                                                          //~v49bI~
    	Sfoundctr=samepartctr;//recover from fcmdsetfindhighlight update Sfoundctr//~v58ZI~
    }                                                              //~v58ZI~
//  plh->ULHrevctr=pfh->UFHfindctr;//find cmd ctr for disply current;//~v0a6R~
//    if (!Smfwtovf)  //before overflow                            //~v43gR~
//    {                                                            //~v43gR~
//        plh->ULHrevctr=pfh->UFHfindctr;//find cmd ctr for disply current;//~v43gR~
//        UCBITON(plh->ULHflag,ULHFDRAW|ULHFCURFOUND);//draw word after wordrep//~v43gR~
//        UCBITOFF(plh->ULHflag,ULHFCURCAP);//reset hilight reason cap//~v43gR~
//    }                                                            //~v43gR~
	if (joineofsw)                                                 //~v58rI~
    	rc=4;                                                      //~v58rI~
	return rc;                                                  //~5107R~
}//linesrchstringsub                                               //~v61hR~
//**************************************************************** //~v43fI~
//!fcmdsetfindhighlight                                            //~v43fI~
//! set highlight on found word                                    //~v43fI~
//* parm1 :pfh                                                     //~v43fI~
//* parm2 :plh                                                     //~v43fI~
//* parm3 :1st call sw                                             //~v43fI~
//* parm4 :linesearch sw                                           //~v43fI~
//* parm5 :word offset                                             //~v43fI~
//* parm6 :word len                                                //~v43fI~
//* parm7 :spanplh                                                 //~v43fI~
//* rc    :0                                                       //~v43fI~
//**************************************************************** //~v43fI~
int fcmdsetfindhighlight(PUFILEH Ppfh,PULINEH Pplh,int Plocatesw,int Plinesrchsw,//~v43fI~
			int Poffset,int Pwordlen,PULINEH Pspanplh)             //~v43fI~
{                                                                  //~v43fI~
	static PULINEH Splh1=0,Sspanplh1;                              //~v47zR~
	static int  Slocatesw1=0,Slinesrchsw1=0,Soffset1=0,Swordlen1=0;//~v47zR~
    int samelen;                                                   //~v49bI~
    int ii;                                                        //~v61hI~
	USHORT *pusoffs;                                               //~v61hI~
	USHORT *filemfwtbl;                                            //~v62bI~
    int multirevsw=0;                                              //~v62aI~
    int mfwtindex,rc;                                              //~v62bR~
    int ulsrchsw;                                                  //~v62cI~
    int wordlen;                                                   //~v62dI~
//*****************                                                //~v43fI~
	if (!Ppfh->UFHmfwtbl)                                          //~v62cR~
		if (rc=fcmdallocmfwt(Ppfh),rc)                             //~v62bI~
        	return rc;                                             //~v62bI~
	filemfwtbl=Ppfh->UFHmfwtbl;                                    //~v62bI~
    ulsrchsw=Sulsrchsw;                                            //~v62cI~
	if (Plocatesw & FCMDSFHOPT_NOMULTIREV) //reset multiple reverse//~v62aR~
    {                                                              //~v62aI~
        ulsrchsw=0; //called from ppsrch                           //~v62cI~
		Plocatesw &= ~FCMDSFHOPT_NOMULTIREV;//chked                //~v62aR~
		if (Sfindopt & FINDOPT_MULTIREV) //in multimode            //~v62aI~
        {                                                          //~v62aI~
			Sfindopt |= FINDOPT_MULTIREVRESTA; //                  //~v62aR~
			Sfindopt &= ~(FINDOPT_MULTIREV|FINDOPT_MULTIREVNEXT); //in multimode//~v62aI~
        }                                                          //~v62aI~
    }                                                              //~v62aI~
    else                                                           //~v62aI~
    {                                                              //~v62aI~
        if (Sfindopt & FINDOPT_MULTIREVRESTA) //previously interrupted//~v62aR~
        {                                                          //~v62aI~
			Sfindopt |= (FINDOPT_MULTIREV|FINDOPT_MULTIREVNEXT); //in multimode//~v62aR~
            Sfindopt &= ~FINDOPT_MULTIREVRESTA; //                 //~v62aR~
        }                                                          //~v62aI~
    }                                                              //~v62aI~
//  if (Sulsrchsw==LINE_SAMESRCH)  //*=                            //~v62cR~
//  if (ulsrchsw==LINE_SAMESRCH)  //*=                             //~v62dR~
    if (ulsrchsw==LINE_SAMESRCH   //*=                             //~v62dI~
    ||  ulsrchsw==LINE_SAMEMATCH) //*=                             //~v62dI~
    {                                                              //~v49bI~
        samelen=min(Srange2,Pplh->ULHlen);                         //~v49bI~
    	if (Srange1)                                               //~v49bI~
	    	samelen-=Srange1;//reverse len of *=                   //~v49bI~
        wordlen=samelen;                                           //~v62dI~
    }                                                              //~v49bI~
    else                                                           //~v62dI~
        wordlen=Pwordlen;                                          //~v62dI~
                                                                   //~v49bI~
	if (Sphasesw==1)	//1st of & search                          //~v47zR~
    {                                                              //~v47zR~
    	Splh1=Pplh;                                                //~v47zR~
        Slinesrchsw1=Plinesrchsw;                                  //~v47zR~
        Slocatesw1=Plocatesw;                                      //~v47zR~
        Soffset1=Poffset;                                          //~v47zR~
        Swordlen1=Pwordlen;                                        //~v47zR~
    	Sspanplh1=Pspanplh;                                        //~v47zR~
        return 0;                                                  //~v47zR~
    }                                                              //~v47zR~
	if (Sphasesw==2)	//2nd of & search                          //~v47zR~
    {                                                              //~v47zR~
    	Sphasesw=0;                                                //~v47zR~
		fcmdsetfindhighlight(Ppfh,Splh1,Slocatesw1,Slinesrchsw1,   //~v47zR~
				Soffset1,Swordlen1,Sspanplh1);                     //~v47zR~
    	Sphasesw=2;                                                //~v47zR~
    }                                                              //~v47zR~
    if (Pspanplh)                       //spaned word              //~v43gI~
        return fcmdsplitdisplay(Ppfh,Pplh,Pspanplh,Poffset,Pwordlen,Plocatesw);//set on 2nd line also//~v43gI~
	mfwtindex=Ppfh->UFHmfwtindex;//fcmdtabdisplay update ufhmfwtindex//~v62cI~
	if (Plocatesw)                                                 //~v43fI~
    {                                                              //~v43fI~
//    if (Sulsrchsw==LINE_RESEARCH)		//*L                       //~v62cR~
      if (ulsrchsw==LINE_RESEARCH)		//*L                       //~v62cI~
      {                                                            //~v496I~
    	Sfoundctr=0;					//count up at return       //~v496I~
		Sfindopt &= ~(FINDOPT_MULTIREV|FINDOPT_MULTIREVNEXT); //ignore multi rev//~v62cI~
      }                                                            //~v496I~
      else                                                         //~v496I~
      {                                                            //~v496I~
		if (Sfindopt & FINDOPT_MULTIREV)                           //~v62aI~
        {                                                          //~v62aI~
//          Ppfh->UFHfindctrme=Ppfh->UFHfindctr+1;//reverse to current//~v62cR~
            if (Sfindopt & FINDOPT_MULTIREVNEXT) //reverse multiple level requested//~v62aI~
            {                                                      //~v62aI~
//              Ppfh->UFHfindctrms=Ppfh->UFHfindctr+1;//continue from now//~v62cR~
	            Sfindopt &= ~FINDOPT_MULTIREVNEXT; //reverse multiple level requested//~v62aI~
            }                                                      //~v62aI~
            else                                                   //~v62aI~
            {                                                      //~v62aI~
//  	    	if (!Ppfh->UFHfindctrms)	//1st time -m option   //~v62cR~
//  		    	Ppfh->UFHfindctrms=Ppfh->UFHfindctr;//continue from prev//~v62cR~
   			  if (Ppfh->UFHfindctr)	//1st -m should be ignored     //~v62cI~
                multirevsw=1;                                      //~v62aI~
            }                                                      //~v62aI~
        }                                                          //~v62aI~
//      else                                                       //~v62cR~
//      	Ppfh->UFHfindctrms=0;		//reverse this time only   //~v62cR~
//  	Spfhfindctr=++Ppfh->UFHfindctr;                            //~v62cR~
    	Sfoundctr=0;					//count up at return       //~v43fI~
//  	Smfwtovf=0;						//overflow point           //~v73dR~
    	Gmfwtovf=0;						//overflow point           //~v73dI~
//  	*Gfilemfwtbl=(USHORT)Pwordlen;	//len to first entry       //~v43gR~
//  	Smfwtindex=1;					//offset to second entry   //~v43gR~
//     if (multirevsw)                                             //~v62bR~
//  	Smfwtindex=fcmdcpymfwtback(Ppfh,(char*)(ULONG)Gfilemfwtbl);//~v62bR~
//     else                                                        //~v62bR~
//  	Smfwtindex=0;					//clear used entry         //~v62bR~
       	if (!multirevsw)                                           //~v62bI~
        {                                                          //~v62cI~
   			Ppfh->UFHfindctr++;                                    //~v62cI~
			mfwtindex=0;					//clear used entry     //~v62bI~
        }                                                          //~v62cI~
   		Spfhfindctr=Ppfh->UFHfindctr;                              //~v62cI~
      }                                                            //~v496I~
	}                                                              //~v43fI~
    Sfoundctr++;                                                   //~v43sI~
//  if (Plocatesw || Pplh->ULHrevctr!=Ppfh->UFHfindctr)    //new find//~v496R~
//  if (Plocatesw || Pplh->ULHrevctr!=Ppfh->UFHfindctr     //new find//~v62cR~
    if (  (Plocatesw && !multirevsw)                               //~v62cI~
       || Pplh->ULHrevctr!=Ppfh->UFHfindctr     //new find         //~v62cI~
//     || Sulsrchsw==LINE_RESEARCH)		//*L                       //~v62cR~
       || ulsrchsw==LINE_RESEARCH)		//*L                       //~v62cI~
    {                                                              //~v43fI~
      	if (Plinesrchsw)            //update line search           //~v43fI~
        {                                                          //~v496I~
//    	  if (Sulsrchsw==LINE_SAMESRCH)  //*=                      //~v62cR~
//    	  if (ulsrchsw==LINE_SAMESRCH)  //*=                       //~v62dR~
      	  if (ulsrchsw==LINE_SAMESRCH  //*=                        //~v62dI~
      	  ||  ulsrchsw==LINE_SAMEMATCH)//*=                        //~v62dI~
			Pplh->ULHrevoffs=(USHORT)Poffset;                      //~v49bI~
          else                                                     //~v49bI~
//        if (Sulsrchsw==LINE_RESEARCH)		//*L                   //~v62cR~
          if (ulsrchsw==LINE_RESEARCH)		//*L                   //~v62cI~
          {                                                        //~v496I~
			if (Pplh->ULHrevoffs!=ULHULFOUND)		//not previously line search result//~v496I~
				Pplh->ULHrevoffs=ULHULFOUNDL;		//ipdate line search result id//~v496I~
          }                                                        //~v496I~
          else                                                     //~v496I~
			Pplh->ULHrevoffs=ULHULFOUND;		//ipdate line search result id//~v43fI~
        }                                                          //~v496I~
      	else                                                       //~v43fI~
			Pplh->ULHrevoffs=(USHORT)Poffset;                      //~v43fI~
      if (Sdirattr)                                                //~vbc1I~
    	Pplh->ULHrevlen=1;		//highlight eolid                  //~vbc1I~
      else                                                         //~vbc1I~
      if (Seolsrchsw&&!Pwordlen)                                   //~v54zI~
    	Pplh->ULHrevlen=1;		//highlight eolid                  //~v54zI~
      else                                                         //~v54zI~
      {                                                            //~v62dI~
//    if (Sulsrchsw==LINE_SAMESRCH)  //*=                          //~v62cR~
//    if (ulsrchsw==LINE_SAMESRCH)  //*=                           //~v62dR~
//        Pplh->ULHrevlen=(USHORT)samelen;//reverse len of *=      //~v62dR~
//    else                                                         //~v62dR~
//        Pplh->ULHrevlen=(USHORT)Pwordlen;//reverse len,next rfind step//~v62dR~
          Pplh->ULHrevlen=(USHORT)wordlen;//reverse len,next rfind step//~v62dI~
      }                                                            //~v62dI~
		UCBITOFF(Pplh->ULHflag2,ULHF2MFOUND);//reset multiple      //~v43fI~
//      if (Pspanplh)                       //spaned word          //~v43gR~
//          fcmdsplitdisplay(Pplh,Pspanplh,Poffset,Pwordlen,Ppfh->UFHfindctr);//set on 2nd line also//~v43gR~
	}                                                              //~v43fI~
    else        //second call for "all"                            //~v43fI~
    {                                                              //~v43fI~
        if (UCBITCHK(Pplh->ULHflag2,ULHF2MFOUND))//already multiple//~v43fI~
        {                                                          //~v43fI~
//          if (Smfwtindex<=MAXMFWTENTRY)                          //~v50vR~
//          if (Smfwtindex<=(MAXMFWTENTRY+MAXMFWTENTRY))           //~v61hR~
//          if (Smfwtindex<=MFWTBLSZ)                              //~v62bR~
            if (mfwtindex<MFWTBLSZ)                                //~v62cR~
            {                                                      //~v43fI~
//              for (ii=Pplh->ULHrevlen-1,pusoffs=Gfilemfwtbl+Pplh->ULHrevoffs;//~v62bR~
                for (ii=Pplh->ULHrevlen-1,pusoffs=filemfwtbl+Pplh->ULHrevoffs;//~v62bI~
					ii>0;ii--)  //search last entry addr           //~v61hI~
                    pusoffs+=*(pusoffs+2);	//3rd entry is ushort count to next 3 ushort entry//~v61hI~
//              *(pusoffs+2)=(USHORT)(Smfwtindex-((ULONG)pusoffs-(ULONG)Gfilemfwtbl)/sizeof(USHORT));//~v62bR~
//                *(pusoffs+2)=(USHORT)(mfwtindex-((ULONG)pusoffs-(ULONG)filemfwtbl)/sizeof(USHORT));//~v62bI~//~vafkR~
//                *(pusoffs+2)=(USHORT)(mfwtindex-((ULPTR)pusoffs-(ULPTR)filemfwtbl)/sizeof(USHORT));//~vafkI~//~vb2pR~
                  *(pusoffs+2)=(USHORT)(mfwtindex-(int)((ULPTR)pusoffs-(ULPTR)filemfwtbl)/(int)sizeof(USHORT));//~vb2pI~
                Pplh->ULHrevlen++;   //wordcount                   //~v43fI~
//    	      if (Sulsrchsw==LINE_SAMESRCH)  //*=                  //~v62cR~
//    	      if (ulsrchsw==LINE_SAMESRCH)  //*=                   //~v62dR~
      	      if (ulsrchsw==LINE_SAMESRCH   //*=                   //~v62dI~
      	      ||  ulsrchsw==LINE_SAMEMATCH) //*=                   //~v62dI~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)Poffset;       //~v62bR~
                *(filemfwtbl+mfwtindex++)=(USHORT)Poffset;         //~v62bI~
              else                                                 //~v49bI~
      	      if (Plinesrchsw)            //update line search     //~v43wI~
//              *(Gfilemfwtbl+Smfwtindex++)=ULHULFOUND;		//ipdate line search result id//~v62bR~
                *(filemfwtbl+mfwtindex++)=ULHULFOUND;		//ipdate line search result id//~v62bI~
      	      else                                                 //~v43wI~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)Poffset;       //~v62bR~
                *(filemfwtbl+mfwtindex++)=(USHORT)Poffset;         //~v62bI~
                                                                   //~v61hI~
      		  if (Seolsrchsw&&!Pwordlen)                           //~v54zI~
//              *(Gfilemfwtbl+Smfwtindex++)=1;                     //~v62bR~
                *(filemfwtbl+mfwtindex++)=1;                       //~v62bI~
              else                                                 //~v54zI~
              {                                                    //~v62dI~
//  	      if (Sulsrchsw==LINE_SAMESRCH)  //*=                  //~v62cR~
//  	      if (ulsrchsw==LINE_SAMESRCH)  //*=                   //~v62dR~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)samelen;//reverse len of *=//~v62bR~
//              *(filemfwtbl+mfwtindex++)=(USHORT)samelen;//reverse len of *=//~v62dR~
//            else                                                 //~v62dR~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)Pwordlen;      //~v62bR~
//              *(filemfwtbl+mfwtindex++)=(USHORT)Pwordlen;        //~v62dR~
                *(filemfwtbl+mfwtindex++)=(USHORT)wordlen;         //~v62dI~
              }                                                    //~v62dI~
//            	*(Gfilemfwtbl+Smfwtindex++)=0;	//offset to next entry//~v62bR~
              	*(filemfwtbl+mfwtindex++)=0;	//offset to next entry//~v62bI~
            }                                                      //~v43fI~
            else                                                   //~v43fI~
//              if (!Smfwtovf)			//first overflow           //~v73dR~
                if (!Gmfwtovf)			//first overflow           //~v73dI~
                {                                                  //~v50vI~
//                  Smfwtovf=Sfoundctr;                            //~v61hR~
//                  Smfwtovf=Sfoundctr-1;                          //~v73dR~
                    Gmfwtovf=Sfoundctr-1;                          //~v73dI~
//                  if (!Smfwtovf) 	//multi rev case rfind may ovf  at first found//~v73dR~
                    if (!Gmfwtovf) 	//multi rev case rfind may ovf  at first found//~v73dI~
                    	uerrmsgcat(",word reverse table overflow",0);//~v62cR~
                    Sovflineno=Pplh->ULHlinenor;                   //~v50vI~
                    Sovfsuffix=Pplh->ULHsuffix;                    //~v50vR~
                    Sovfoffset=Pplh->ULHoffs;                      //~v50vI~
                }                                                  //~v50vI~
        }                                                          //~v43fI~
        else    //first multiple                                   //~v43fI~
        {                                                          //~v43fI~
//          if (Smfwtindex<MAXMFWTENTRY)                           //~v50vR~
//          if (Smfwtindex<(MAXMFWTENTRY+MAXMFWTENTRY))            //~v61hR~
//          if (Smfwtindex<MFWTBLSZ)                               //~v62bR~
            if (mfwtindex<MFWTBLSZ)                                //~v62bI~
            {                                                      //~v43fI~
                UCBITON(Pplh->ULHflag2,ULHF2MFOUND);//multiple     //~v43fI~
//              *(Gfilemfwtbl+Smfwtindex)=Pplh->ULHrevoffs;        //~v62bR~
//              Pplh->ULHrevoffs=(USHORT)Smfwtindex++;//strat pos  //~v62bR~
//              *(Gfilemfwtbl+Smfwtindex++)=Pplh->ULHrevlen;//1st word length//~v62bR~
//              *(Gfilemfwtbl+Smfwtindex++)=MFWTENTSZ;	//next entry is after 3 ushort//~v62bR~
                *(filemfwtbl+mfwtindex)=Pplh->ULHrevoffs;          //~v62bI~
                Pplh->ULHrevoffs=(USHORT)mfwtindex++;//strat pos   //~v62bI~
                *(filemfwtbl+mfwtindex++)=Pplh->ULHrevlen;//1st word length//~v62bI~
                *(filemfwtbl+mfwtindex++)=MFWTENTSZ;	//next entry is after 3 ushort//~v62bI~
//    	      if (Sulsrchsw==LINE_SAMESRCH)  //*=                  //~v62cR~
//    	      if (ulsrchsw==LINE_SAMESRCH)  //*=                   //~v62dR~
      	      if (ulsrchsw==LINE_SAMESRCH   //*=                   //~v62dI~
      	      ||  ulsrchsw==LINE_SAMEMATCH) //*=                   //~v62dI~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)Poffset;       //~v62bR~
                *(filemfwtbl+mfwtindex++)=(USHORT)Poffset;         //~v62bI~
              else                                                 //~v49bI~
      	      if (Plinesrchsw)            //update line search     //~v43wI~
//              *(Gfilemfwtbl+Smfwtindex++)=ULHULFOUND;		//ipdate line search result id//~v62bR~
                *(filemfwtbl+mfwtindex++)=ULHULFOUND;		//ipdate line search result id//~v62bI~
      	      else                                                 //~v43wI~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)Poffset;       //~v62bR~
                *(filemfwtbl+mfwtindex++)=(USHORT)Poffset;         //~v62bI~
      		  if (Seolsrchsw&&!Pwordlen)                           //~v54zI~
//              *(Gfilemfwtbl+Smfwtindex++)=1;//reverse len of *=  //~v62bR~
                *(filemfwtbl+mfwtindex++)=1;//reverse len of *=    //~v62bI~
      		  else                                                 //~v54zI~
              {                                                    //~v62dI~
//  	      if (Sulsrchsw==LINE_SAMESRCH)  //*=                  //~v62cR~
//  	      if (ulsrchsw==LINE_SAMESRCH)  //*=                   //~v62dR~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)samelen;//reverse len of *=//~v62bR~
//              *(filemfwtbl+mfwtindex++)=(USHORT)samelen;//reverse len of *=//~v62dR~
//            else                                                 //~v62dR~
//              *(Gfilemfwtbl+Smfwtindex++)=(USHORT)Pwordlen;      //~v62bR~
//              *(filemfwtbl+mfwtindex++)=(USHORT)Pwordlen;        //~v62dR~
                *(filemfwtbl+mfwtindex++)=(USHORT)wordlen;         //~v62dI~
              }                                                    //~v62dI~
//              *(Gfilemfwtbl+Smfwtindex++)=0;	//offset to enxt entry//~v62bR~
                *(filemfwtbl+mfwtindex++)=0;	//offset to enxt entry//~v62bI~
                Pplh->ULHrevlen=2;           //wordcount           //~v43fI~
            }                                                      //~v43fI~
            else                                                   //~v43fI~
//              if (!Smfwtovf)			//first overflow           //~v73dR~
                if (!Gmfwtovf)			//first overflow           //~v73dI~
                {                                                  //~v50vI~
//                  Smfwtovf=Sfoundctr;                            //~v61hR~
//                  Smfwtovf=Sfoundctr-1;                          //~v73dR~
                    Gmfwtovf=Sfoundctr-1;                          //~v73dI~
//                  if (!Smfwtovf) 	//multi rev case rfind may ovf  at first found//~v73dR~
                    if (!Gmfwtovf) 	//multi rev case rfind may ovf  at first found//~v73dI~
                    	uerrmsgcat(",word reverse table overflow",0);//~v62cR~
                    Sovflineno=Pplh->ULHlinenor;                   //~v50vI~
                    Sovfsuffix=Pplh->ULHsuffix;                    //~v50vR~
                    Sovfoffset=Pplh->ULHoffs;                      //~v50vI~
                }                                                  //~v50vI~
        }                                                          //~v43fI~
    }                                                              //~v43fI~
//  if (!Smfwtovf)  //before overflow                              //~v73dR~
    if (!Gmfwtovf)  //before overflow                              //~v73dI~
    {                                                              //~v43gI~
        Pplh->ULHrevctr=Ppfh->UFHfindctr;//find cmd ctr for disply current;//~v43gR~
        UCBITON(Pplh->ULHflag,ULHFDRAW|ULHFCURFOUND);//draw word after wordrep//~v43gR~
        UCBITOFF(Pplh->ULHflag,ULHFCURCAP);//reset hilight reason cap//~v43gR~
    }                                                              //~v43gI~
	Ppfh->UFHmfwtindex=mfwtindex;                                  //~v62bR~
    return 0;                                                      //~v43fI~
}//fcmdsetfindhighlight                                            //~v43fI~
//**************************************************************** //~v43cI~
//!chk not excludedline exist for spaned or around line for x cmd  //~v43cI~
//* parm1 :found line plh                                          //~v43cI~
//* parm2 :spanned plh                                             //~v43cI~
//* parm3 :last plh of *= search                                   //~v49bI~
//* parm3 :1st word plh of *&                                      //~v43eI~
//* parm4 :before line                                             //~v43eI~
//* parm5 :after line count                                        //~v43eR~
//* rc    :1:not bexcluded line exist,0:all excluded               //~v43cI~
//**************************************************************** //~v43cI~
//int fcmdallxchk(PULINEH Pplh,PULINEH Pspanplh,PULINEH Pandplh1,  //~v49bR~
int fcmdallxchk(PULINEH Pplh,PULINEH Pspanplh,PULINEH Psamelastplh,PULINEH Pandplh1,//~v49bI~
					int Plinebefore,int Plineafter)                //~v43eI~
{                                                                  //~v43cI~
    PULINEH plh,plh1,plh2;                                         //~v47tR~
    int rc;                                                        //~v613I~
    int svctr;                                                     //~v61bI~
//*********************                                            //~v43cI~
//chk sameline plh                                                 //~v61bI~
	if (Psamelastplh)                                              //~v61bI~
    {                                                              //~v61bI~
		svctr=Sothererr_abrange;	//save for restore             //~v61bR~
    	rc=fcmdaroundlinesub(Pplh,Psamelastplh,Plinebefore,Plineafter,&plh1,&plh2);//~v61bI~
        if (rc)//skip not found err msg                            //~v61bI~
        {                                                          //~v61hI~
          if (Sexcludesw2) // "x *=" cmd//chk not excluded to set reverse//~v61bR~
			Sothererr_abrange=svctr;	//to avoid double count by call from aroundline//~v61bI~
          else                                                     //~v61bI~
    		return 0;	//no line to be excluded                   //~v61bI~
        }                                                          //~v61hI~
        for (plh=plh1;plh;plh=UGETQNEXT(plh))                      //~v61bR~
        {                                                          //~v61bI~
            if (plh->ULHtype==ULHTDATA)                            //~v61bI~
                if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))        //~v61bI~
                    return 1;	//found line to be excluded        //~v61bI~
            if (plh==plh2)                                         //~v61bM~
                break;                                             //~v61bM~
        }                                                          //~v61bI~
    	return 0;	//all line excluded                            //~v61bI~
    }//x *= cmd                                                    //~v61bI~
    if (!UCBITCHK(Pplh->ULHflag2,ULHF2EXCLUDED))                   //~v43cI~
    	return 1;                                                  //~v43cI~
//chk spanned                                                      //~v43cI~
	if (Pspanplh)                                                  //~v43cI~
        for (plh=Pplh;plh=UGETQNEXT(plh),plh;)                     //~v43cI~
        {                                                          //~v43cI~
            if (plh->ULHtype==ULHTDATA)                            //~v43cI~
                if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))        //~v43cI~
                    return 1;                                      //~v43cI~
            if (plh==Pspanplh)                                     //~v43cI~
                break;                                             //~v43cI~
        }                                                          //~v43cI~
//chk sameline plh                                                 //~v49bI~
//    if (Psamelastplh)                                            //~v61bR~
//        for (plh=Pplh;plh=UGETQNEXT(plh),plh;)                   //~v61bR~
//        {                                                        //~v61bR~
//            if (plh->ULHtype==ULHTDATA)                          //~v61bR~
//                if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))      //~v61bR~
//                    return 1;                                    //~v61bR~
//            if (plh==Psamelastplh)                               //~v61bR~
//                break;                                           //~v61bR~
//        }                                                        //~v61bR~
//chk intermediate of 2 word                                       //~v43eI~
	if (Pandplh1 && Pandplh1!=Pplh)                                //~v43eI~
    {                                                              //~v43eI~
        plh=Pandplh1;                                              //~v43eI~
        for (;plh=UGETQNEXT(plh),plh;)                             //~v43eI~
        {                                                          //~v43eI~
            if (plh==Pplh)                                         //~v43eI~
                break;                                             //~v43eI~
            if (plh->ULHtype==ULHTDATA)                            //~v43eI~
                if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))        //~v43eI~
                    return 1;                                      //~v43eI~
        }                                                          //~v43eI~
    }                                                              //~v43eI~
//chk after before                                                 //~v43cI~
//  if (fcmdaroundlinesub(Pplh,Plinebefore,Plineafter,&plh1,&plh2))//~v49bR~
//  if (fcmdaroundlinesub(Pplh,Psamelastplh,Plinebefore,Plineafter,&plh1,&plh2))//~v613R~
//      return 4;                                                  //~v613R~
    if (rc=fcmdaroundlinesub(Pplh,Psamelastplh,Plinebefore,Plineafter,&plh1,&plh2),rc)//~v613I~
        return rc;                                                 //~v613I~
//    linemax=Plinebefore;                                         //~v47tR~
//    for (jj=0;jj<2;jj++)    //before and after                   //~v47tR~
//    {                                                            //~v47tR~
//      for (ii=0,plh=Pplh;ii<linemax;)                            //~v47tR~
        for (plh=plh1;plh;plh=UGETQNEXT(plh))                      //~v47tI~
        {                                                          //~v43cI~
//      	if (jj)                                                //~v47tR~
//          	plh=UGETQNEXT(plh);                                //~v47tR~
//          else                                                   //~v47tR~
//          	plh=UGETQPREV(plh);                                //~v47tR~
//          if (!plh)                                              //~v47tR~
//              break;                                             //~v47tR~
    		if (plh->ULHtype!=ULHTDATA)                            //~v43cI~
                continue;                                          //~v43cI~
//          ii++;                                                  //~v47tR~
            if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))            //~v43cI~
            	return 1;                                          //~v43cI~
            if (plh==plh2)                                         //~v47tI~
            	break;                                             //~v47tI~
        }//before loop                                             //~v43cI~
//        linemax=Plineafter;                                      //~v47tR~
//    }//before and after                                          //~v47tR~
    return 0;                                                      //~v43cI~
}//fcmdallxchk                                                     //~v43cI~
//**************************************************************** //~v43cI~
//!display/exclude the line and spaned                             //~v43cI~
//* parm1 :pcw                                                     //~v43cI~
//* parm2 :pfh                                                     //~v43cI~
//* parm3 :plh found                                               //~v43cI~
//* parm4 :plh spanned or 0                                        //~v43cI~
//* parm5 :plh last plh of *=                                      //~v49bI~
//* parm6 :subcmd id                                               //~v49bI~
//* parm7 :cmd id find/exclude                                     //~v49bR~
//* parm8 :fisrttime sw of SUBCMD_ALL                              //~v49bI~
//* rc    :0                                                       //~v43cI~
//**************************************************************** //~v43cI~
int fcmdspannedline(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PULINEH Pspanplh,//~v43cR~
					PULINEH Psamelastplh,int Psubcmdid,            //~v49bR~
					int Pexcludesw2,int Plocatesw)                 //~v43cI~
{                                                                  //~v43cI~
    PULINEH plh;                                                   //~v43cI~
    PULINEH plhj1,plhj2;	//join line start/end                  //~v539I~
    int joinctr,rc;                                                //~v539R~
//*********************                                            //~v43cI~
	if (Sphasesw==1)		//1st word search of *&                //~v43eI~
    	return 0;                                                  //~v43eI~
  if (Sphasesw==2)                                                 //~v43eI~
  {                                                                //~v43eI~
    plh=Sandplh1;                                                  //~v43eI~
    if (!Pspanplh)    		//no span of 2nd word                  //~v43eI~
    	Pspanplh=Pplh;      //up to 2nd word line                  //~v43eI~
  }                                                                //~v43eI~
  else                                                             //~v43eI~
    plh=Pplh;                                                      //~v43cI~
    if (!Pexcludesw2)  //un exclude cmd                            //~v43cI~
    {                                                              //~v43cI~
    	plhj1=plhj2=plh;                                           //~v539R~
        joinctr=0;                                                 //~v539I~
    	for (;;)	                                               //~v43cI~
        {                                                          //~v43cI~
            if (plh->ULHtype==ULHTDATA)                            //~v539I~
            {                                                      //~v539I~
        		joinctr++;                                         //~v539R~
        		plhj2=plh;                                         //~v539R~
            }                                                      //~v539I~
            if (plh->ULHtype==ULHTDATA                             //~v43cI~
            &&  UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))             //~v43cI~
            {                                                      //~v43cI~
                if (!Supctrsw)      //first time                   //~v43cI~
                {                                                  //~v43cI~
                    Supctrsw=1;     //req upctrreq at end          //~v43cI~
                    UPCTRREQ(Ppfh);                                //~v43cI~
                }                                                  //~v43cI~
                if (lcmdincm(Ppcw,plh)==UALLOC_FAILED)  //display excluded line//~v43cI~
                    return UALLOC_FAILED;                          //~v43cI~
            }//excluded                                            //~v43cI~
            if (Psamelastplh)                                      //~v49bI~
            {                                                      //~v49bI~
				if (plh==Psamelastplh)                             //~v49bI~
                	break;                                         //~v49bI~
            }                                                      //~v49bI~
            else                                                   //~v49bI~
            if (!Pspanplh || plh==Pspanplh)                        //~v43cI~
            	break;                                             //~v43cI~
            plh=UGETQNEXT(plh);                                    //~v43cI~
            if (!plh)                                              //~v43cI~
            	break;                                             //~v43cI~
        }//until spanned plh                                       //~v43cI~
        if (Sfindopt & FINDOPT_JOIN     //join option              //~v539I~
//      &&  joinctr>1)                                             //~v614R~
           )                                                       //~v614I~
        {                                                          //~v539I~
          if (joinctr>1)                                           //~v614I~
          {                                                        //~v614I~
            if (!Supctrsw)      //first time                       //~v539I~
            {                                                      //~v539I~
                Supctrsw=1;     //req upctrreq at end              //~v539I~
                UPCTRREQ(Ppfh);                                    //~v539I~
            }                                                      //~v539I~
            rc=lcmdjoin(Ppcw,plhj1,plhj2,joinctr,0,0);             //~v539I~
//          if (!rc)                                               //~v547R~
            if (rc)                                                //~v547I~
//              return rc;                                         //~v612R~
                return RC_STOP_SRCH;                               //~v612R~
          }                                                        //~v614I~
          else                                                     //~v614I~
          	if (joinctr==1)                                        //~v614I~
				Sothererr_selfjoin++;   //not notfound err count:join myself case//~v614I~
        }                                                          //~v539I~
        else                                                       //~v61hI~
        if (Sfindopt & FINDOPT_SETLABEL)//label set req            //~v61hI~
        {                                                          //~v61hI~
            if (fcmdsetfoundlinelabel(plhj1,Ssetlabel))            //~v61hI~
                return RC_STOP_SRCH;                               //~v61hI~
        }                                                          //~v61hI~
	}                                                              //~v43cI~
    else		//exclude cmd                                      //~v43cI~
    {                                                              //~v43cI~
      if (Psamelastplh)                                            //~v49dR~
      {                                                            //~v49bI~
        if (!Supctrsw)      //first time                           //~v49bI~
        {                                                          //~v49bI~
            Supctrsw=1;     //req upctrreq at end                  //~v49bI~
            UPCTRREQ(Ppfh);                                        //~v49bI~
        }                                                          //~v49bI~
       if (Sfindopt & FINDOPT_BEFORE0)                             //~v49dI~
       {                                                           //~v49dI~
			if (lcmdexc(Ppcw,plh,Psamelastplh,(Plocatesw!=0))==UALLOC_FAILED)	//excluded one line//~v49dI~
        		return UALLOC_FAILED;                              //~v49dI~
       }                                                           //~v49dI~
       else                                                        //~v49dI~
       {                                                           //~v49dI~
        plh=UGETQNEXT(plh);                                        //~v49bR~
        if (lcmdexcsame(Ppcw,plh,Psamelastplh)==UALLOC_FAILED)  //excluded one line//~v49bR~
            return UALLOC_FAILED;                                  //~v49bR~
       }                                                           //~v49dI~
      }                                                            //~v49bI~
      else                                                         //~v49bI~
    	for (;;)                                                   //~v43cI~
        {                                                          //~v43cI~
            if (plh->ULHtype==ULHTDATA                             //~v43cI~
			&&  !UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))            //~v43cR~
            {                                                      //~v43cI~
        		if (!Supctrsw)                                     //~v43cI~
	        	{                                                  //~v43cI~
	        		Supctrsw=1;     //req upctrreq at end          //~v43cI~
            		UPCTRREQ(Ppfh);                                //~v43cI~
				}                                                  //~v43cI~
            	lcmdclearlcmd(Ppfh,plh);	//clear pending cmd    //~v43cI~
			  if (S2ndofallsw)  //2nd search of all                //~v54BI~
              {                                                    //~v54BI~
				S2ndofallsw=2;  //ned updated exclude ctr at last  //~v54BI~
				if (lcmdexcfromxall2(Ppcw,plh,plh)==UALLOC_FAILED)	//excluded one line//~v54BR~
        			return UALLOC_FAILED;                          //~v54BI~
			  }                                                    //~v54BI~
              else                                                 //~v54BI~
              {                                                    //~v54BI~
				if (lcmdexc(Ppcw,plh,plh,(Plocatesw!=0))==UALLOC_FAILED)	//excluded one line//~v43cI~
        			return UALLOC_FAILED;                          //~v43cI~
              }                                                    //~v54BI~
            }//displayed                                           //~v43cI~
            if (!Pspanplh || plh==Pspanplh)                        //~v43cI~
            	break;                                             //~v43cI~
            plh=UGETQNEXT(plh);                                    //~v43cI~
            if (!plh)                                              //~v43cI~
            	break;                                             //~v43cI~
        }//until spanned plh                                       //~v43cI~
	}//x cmd                                                       //~v43cI~
    return 0;                                                      //~v43cI~
}//fcmdspannedline                                                 //~v43cI~
//**************************************************************** //~v437I~
//!display/exclude around of found word line(first line of spanned)//~v437I~
//* parm1 :pcw                                                     //~v437I~
//* parm2 :pfh                                                     //~v437I~
//* parm3 :plh found                                               //~v437I~
//* parm4 :2nd plh of *= search                                    //~v49bI~
//* parm5 :line count before to be displayed                       //~v49bR~
//* parm6 :line count after  to be displayed                       //~v49bR~
//* parm7 :word spaned to the line                                 //~v49bR~
//* parm8 :cmd id find/exclude                                     //~v49bR~
//* rc    :0                                                       //~v437I~
//**************************************************************** //~v437I~
//int fcmdaroundline(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,int Plinebefore,int Plineafter,//~v49bR~
//int fcmdaroundline(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PULINEH Psamelastplh,//~v547R~
int fcmdaroundline(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh,PULINEH Psamelastplh,//~v547I~
					int Plinebefore,int Plineafter,int Pexcludesw2,int *Ppoffs)//~v548R~
{                                                                  //~v437I~
    PULINEH plh;	                                               //~v437I~
    PULINEH pplh;                                                  //~v547I~
    PULINEH plh1,plh2;                                             //~v47tI~
//  PULINEH plhx1=0,plhx2;	//x line start/end                     //~v536I~//~vaf9R~
    PULINEH plhx1=0,plhx2=0;	//x line start/end                 //~vaf9I~
    PULINEH plhj1,plhj2;	//join line start/end                  //~v539R~
    int     breaksw;                                               //~v536I~
    int joinctr=0,rc;                                              //~v539R~
    int beforelen=0,aftersw=0;                                     //~v548I~
    int andplh1delsw=0;                                            //~v57eI~
//*********************                                            //~v437I~
	if (Sphasesw==1)		//1st word search of *&                //~v43eI~
    	return 0;                                                  //~v43eI~
    pplh=*Ppplh;                                                   //~v547I~
//  if (fcmdaroundlinesub(Pplh,Plinebefore,Plineafter,&plh1,&plh2))//~v49bR~
//  if (fcmdaroundlinesub(Pplh,Psamelastplh,Plinebefore,Plineafter,&plh1,&plh2))//~v547R~
//  if (fcmdaroundlinesub(pplh,Psamelastplh,Plinebefore,Plineafter,&plh1,&plh2))//~v613R~
//      return 4;                                                  //~v613R~
    if (rc=fcmdaroundlinesub(pplh,Psamelastplh,Plinebefore,Plineafter,&plh1,&plh2),rc)//~v613I~
    {                                                              //~v61bI~
        if (rc==RC_ERR_NOTNF)//skip not found err msg              //~v61bI~
//  		if (!(Pexcludesw2 && Psamelastplh)) // "x *=" cmd      //~v61bR~
				return 0;                                          //~v61bR~
        return rc;                                                 //~v613I~
    }                                                              //~v61bI~
    if (Pexcludesw2 && Psamelastplh) // "x *=" cmd                 //~v61bR~
    {                                                              //~v61bR~
        if (rc!=RC_ERR_NOTNF)//remain to be excluded line          //~v61bR~
        {                                                          //~v61bR~
            if (!Supctrsw)      //first time                       //~v61bR~
            {                                                      //~v61bR~
                Supctrsw=1;     //req upctrreq at end              //~v61bR~
                UPCTRREQ(Ppfh);                                    //~v61bR~
            }                                                      //~v61bR~
            if ((Plinebefore<0 || !(Sfindopt & FINDOPT_BEFORE0))    //not -b0:exclude 1st line//~v61bR~
            &&   Plineafter<=0) //exclude only same line           //~v61bR~
            {                                                      //~v61bR~
                if (lcmdexcsame(Ppcw,plh1,plh2)==UALLOC_FAILED)  //excluded one line//~v61bR~
                    return UALLOC_FAILED;                          //~v61bR~
            }                                                      //~v61bR~
            else                                                   //~v61bR~
            {                                                      //~v61bR~
                if (lcmdexc(Ppcw,plh1,plh2,0)==UALLOC_FAILED)   //0:no set csr//~v61bR~
                    return UALLOC_FAILED;                          //~v61bR~
            }                                                      //~v61bR~
        }                                                          //~v61bR~
        return 0;                                                  //~v61bR~
    }// x *=                                                       //~v61bR~
//    linemax=Plinebefore;                                         //~v47tR~
//    if (Sphasesw==2)    //after 2nd word search                  //~v47tR~
//        plh=Sandplh1;   //before 2st word line                   //~v47tR~
//    else                                                         //~v47tR~
//        plh=Pplh;                                                //~v47tR~
//    for (jj=0;jj<2;jj++)    //before and after                   //~v47tR~
//    {                                                            //~v47tR~
//      for (ii=0;ii<linemax;)                                     //~v47tR~
		plhj1=plhj2=plh1;                                          //~v539I~
        for (plh=plh1;plh;plh=UGETQNEXT(plh))                      //~v47tI~
        {                                                          //~v437I~
//      	if (jj)                                                //~v47tR~
//          	plh=UGETQNEXT(plh);                                //~v47tR~
//          else                                                   //~v47tR~
//          	plh=UGETQPREV(plh);                                //~v47tR~
//          if (!plh)                                              //~v47tR~
//              break;                                             //~v47tR~
    		if (plh->ULHtype!=ULHTDATA)                            //~v437R~
                continue;                                          //~v437I~
//          ii++;                                                  //~v47tR~
			breaksw=1;	//do exclude                               //~v536I~
            if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))             //~v437I~
            {                                                      //~v437I~
                if (!Pexcludesw2)   //find cmd                     //~v437I~
                {                                                  //~v437I~
                    if (!Supctrsw)      //first time               //~v437I~
                    {                                              //~v437I~
                        Supctrsw=1;     //req upctrreq at end      //~v437I~
                        UPCTRREQ(Ppfh);                            //~v437I~
                    }                                              //~v437I~
                    if (lcmdincm(Ppcw,plh)==UALLOC_FAILED)  //display excluded line//~v437I~
                        return UALLOC_FAILED;                      //~v437I~
                }                                                  //~v437I~
            }//excluded line                                       //~v437I~
            else                                                   //~v437I~
            {                                                      //~v437I~
                if (Pexcludesw2)    //exclude cmd                  //~v437I~
                {                                                  //~v437I~
                    if (!Supctrsw)      //first time               //~v437I~
                    {                                              //~v437I~
                        Supctrsw=1;     //req upctrreq at end      //~v437I~
                        UPCTRREQ(Ppfh);                            //~v437I~
                    }                                              //~v437I~
                    if (!plhx1)                                    //~v536I~
                        plhx1=plh;	//x start                      //~v536R~
                    plhx2=plh;      //x end                        //~v536I~
					breaksw=0;	//do exclude later                 //~v536M~
                    lcmdclearlcmd(Ppfh,plh);    //clear pending cmd//~v437I~
//                  if (lcmdexc(Ppcw,plh,plh,0)==UALLOC_FAILED)  //excluded one line,skip csr set//~v536R~
//                      return UALLOC_FAILED;                      //~v536R~
                }                                                  //~v437I~
            }//excluded line                                       //~v437I~
            if (plhx1 && breaksw)	//continued displayed line     //~v536I~
            {                                                      //~v536I~
			  if (S2ndofallsw)  //2nd search of all                //~v54BI~
              {                                                    //~v54BI~
				S2ndofallsw=2;  //ned updated exclude ctr at last  //~v54BI~
            	if (lcmdexcfromxall2(Ppcw,plhx1,plhx2)==UALLOC_FAILED)  //excluded one line,skip csr set//~v54BR~
        			return UALLOC_FAILED;                          //~v54BI~
			  }                                                    //~v54BI~
              else                                                 //~v54BI~
              {                                                    //~v54BI~
            	if (lcmdexc(Ppcw,plhx1,plhx2,0)==UALLOC_FAILED)  //excluded one line,skip csr set//~v536I~
                	return UALLOC_FAILED;                          //~v536I~
              }                                                    //~v54BI~
                plhx1=0;	//done                                 //~v536I~
            }                                                      //~v536I~
            if (plh==pplh)	//found line                           //~v548R~
            {                                                      //~v548I~
            	beforelen+=*Ppoffs;                                //~v548I~
            	aftersw=1;                                         //~v548I~
            }                                                      //~v548I~
            else                                                   //~v548I~
            {                                                      //~v548I~
            	if (!aftersw)                                      //~v548I~
                	beforelen+=plh->ULHlen;                        //~v548I~
            }                                                      //~v548I~
            joinctr++;                                             //~v539I~
            plhj2=plh;		//last to be joined                    //~v539I~
            if (plh==Sandplh1 && plh!=plhj1)                       //~v57eR~
                andplh1delsw=1;	//plh1 not remains as 1st line after join//~v57eI~
            if (plh==plh2)                                         //~v47tI~
            	break;                                             //~v47tI~
        }//before loop                                             //~v437I~
        if (plhx1)   //continued displayed line                    //~v536I~
        {                                                          //~v536I~
		  if (S2ndofallsw)  //2nd search of all                    //~v54BI~
          {                                                        //~v54BI~
                                                                   //~v54BI~
			S2ndofallsw=2;  //ned updated exclude ctr at last      //~v54BI~
            if (lcmdexcfromxall2(Ppcw,plhx1,plhx2)==UALLOC_FAILED)  //excluded one line,skip csr set//~v54BR~
                return UALLOC_FAILED;                              //~v54BI~
          }                                                        //~v54BI~
          else                                                     //~v54BI~
          {                                                        //~v54BI~
            if (lcmdexc(Ppcw,plhx1,plhx2,0)==UALLOC_FAILED)  //excluded one line,skip csr set//~v536I~
                return UALLOC_FAILED;                              //~v536I~
          }                                                        //~v54BI~
        }                                                          //~v536I~
        if (!Pexcludesw2     //not exclude cmd                     //~v539R~
        &&  Sfindopt & FINDOPT_JOIN     //join option              //~v539I~
//      &&  joinctr>1)                                             //~v614R~
           )                                                       //~v614I~
        {                                                          //~v539I~
          if (joinctr>1)                                           //~v614I~
          {                                                        //~v614I~
            if (!Supctrsw)      //first time                       //~v539I~
            {                                                      //~v539I~
                Supctrsw=1;     //req upctrreq at end              //~v539I~
                UPCTRREQ(Ppfh);                                    //~v539I~
            }                                                      //~v539I~
            rc=lcmdjoin(Ppcw,plhj1,plhj2,joinctr,0,0);             //~v539I~
//          if (!rc)                                               //~v547R~
            if (rc)                                                //~v547I~
//              return rc;                                         //~v612R~
                return RC_STOP_SRCH;                               //~v612R~
            *Ppplh=plhj1;   //parm plh may deleted if -b option specified by lcmdjoin//~v547I~
            *Ppoffs=beforelen;   //parm plh may deleted if -b option specified by lcmdjoin//~v548I~
        	Splhafter=0;	//serach after found line              //~v54VI~
            if (andplh1delsw)	//plh1 not remains as 1st line after join//~v57eI~
            	Sandplh1=plhj1;	//found plh1 deleted               //~v57eI~
          }//joinctr>1                                             //~v614I~
          else                                                     //~v614I~
          	if (joinctr==1)                                        //~v614I~
				Sothererr_selfjoin++;   //not notfound err count:join myself case//~v614I~
        }                                                          //~v539I~
        else                                                       //~v61hI~
        if (Sfindopt & FINDOPT_SETLABEL)//label set req            //~v61hI~
        {                                                          //~v61hI~
            if (Plinebefore)                                       //~v61hI~
            {                                                      //~v61hI~
    	        if (fcmdsetfoundlinelabel(plhj1,Ssetlabel))        //~v61hR~
    	            return RC_STOP_SRCH;                           //~v61hI~
            }                                                      //~v61hI~
            if (Plineafter)                                        //~v61hI~
            {                                                      //~v61hI~
    	        if (fcmdsetfoundlinelabel(plhj2,Ssetlabel))        //~v61hI~
    	            return RC_STOP_SRCH;                           //~v61hI~
            }                                                      //~v61hI~
        }                                                          //~v61hI~
//        linemax=Plineafter;                                      //~v47tR~
//        plh=Pplh;       //after 2nd word search                  //~v47tR~
//    }//before and after                                          //~v47tR~
    return 0;                                                      //~v437I~
}//fcmdaroundline                                                  //~v49bR~
//**************************************************************** //~v47tI~
//search start/end plh for -a,-b parm                              //~v47tI~
//* parm1 :plh found                                               //~v47tI~
//* parm2 :2nd plh of *= search                                    //~v49bI~
//* parm3 :line count before to be displayed                       //~v49bR~
//* parm4 :line count after  to be displayed                       //~v49bR~
//* parm5 :start plh                                               //~v49bR~
//* parm6 :end plh                                                 //~v49bR~
//* rc    :0                                                       //~v47tI~
//**************************************************************** //~v47tI~
//int fcmdaroundlinesub(PULINEH Pplh,int Plinebefore,int Plineafter,//~v49bR~
int fcmdaroundlinesub(PULINEH Pplh,PULINEH Psamelastplh,           //~v49bI~
					int Plinebefore,int Plineafter,PULINEH *Pplh1,PULINEH *Pplh2)//~v49bI~
{                                                                  //~v47tI~
	int ii,linemax;                                                //~v47tR~
    PULINEH plh,plho=NULL;                                              //~v47tI~//~vaf9R~
    PULINEH plh2s,plh1s;                                           //~v61bR~
//*********************                                            //~v47tI~
    if (Sexcludesw2 && Psamelastplh) // "x *=" cmd                 //~v61bI~
    	if (!Plinebefore && !(Sfindopt & FINDOPT_BEFORE0))	//not -b0:exclude 1st line//~v61bM~
        	Plinebefore=-1;	//exclude after 1 line skip            //~v61bM~
//-bnn                                                             //~v47tI~
    if (Sphasesw==2)    //after 2nd word search                    //~v47tI~
        plh=Sandplh1;   //base of -b                               //~v47tI~
    else                                                           //~v47tI~
        plh=Pplh;		                                           //~v47tI~
    plh1s=plh;                                                     //~v61bR~
    linemax=Plinebefore;                                           //~v47tI~
    if (linemax<0)          		//-b-n:after found 1st line    //~v47tI~
        for (ii=linemax;ii<0;)                                     //~v47tI~
        {                                                          //~v47tI~
        	plho=plh;                                              //~v47tI~
            plh=UGETQNEXT(plh);                                    //~v47tI~
            if (!plh)                                              //~v47tI~
                break;                                             //~v47tI~
    		if (plh->ULHtype!=ULHTDATA)                            //~v47tI~
                continue;                                          //~v47tI~
            ii++;                                                  //~v47tI~
        }//before loop                                             //~v47tI~
    else                                                           //~v47tI~
        for (ii=linemax;ii>0;)                                     //~v47tI~
        {                                                          //~v47tI~
        	plho=plh;                                              //~v47tI~
            plh=UGETQPREV(plh);                                    //~v47tI~
            if (!plh)                                              //~v47tI~
                break;                                             //~v47tI~
    		if (plh->ULHtype!=ULHTDATA)                            //~v47tI~
                continue;                                          //~v47tI~
            ii--;                                                  //~v47tI~
        }//before loop                                             //~v47tI~
    if (!plh)                                                      //~v47tI~
    	plh=plho;                                                  //~v47tI~
    *Pplh1=plh;                                                    //~v47tI~
//*-ann                                                            //~v47tI~
  if (Psamelastplh)                                                //~v49bI~
    plh=Psamelastplh;                                              //~v49bI~
  else                                                             //~v49bI~
    plh=Pplh;                                                      //~v47tI~
  	plh2s=plh;	//save to restore when range err                   //~v61bI~
    linemax=Plineafter;                                            //~v47tI~
    if (linemax<0)          		//-a-n:after found 2nd line    //~v47tI~
        for (ii=linemax;ii<0;)                                     //~v47tI~
        {                                                          //~v47tI~
        	plho=plh;                                              //~v47tI~
            plh=UGETQPREV(plh);                                    //~v47tI~
            if (!plh)                                              //~v47tI~
                break;                                             //~v47tI~
    		if (plh->ULHtype!=ULHTDATA)                            //~v47tI~
                continue;                                          //~v47tI~
            ii++;                                                  //~v47tI~
        }//before loop                                             //~v47tI~
    else                                                           //~v47tI~
        for (ii=linemax;ii>0;)                                     //~v47tI~
        {                                                          //~v47tI~
        	plho=plh;                                              //~v47tI~
            plh=UGETQNEXT(plh);                                    //~v47tI~
            if (!plh)                                              //~v47tI~
                break;                                             //~v47tI~
    		if (plh->ULHtype!=ULHTDATA)                            //~v47tI~
                continue;                                          //~v47tI~
            ii--;                                                  //~v47tI~
        }//before loop                                             //~v47tI~
    if (!plh)                                                      //~v47tI~
    	plh=plho;                                                  //~v47tI~
    *Pplh2=plh;                                                    //~v47tI~
    if (Plineafter)                                                //~v54VI~
	    Splhafter=plh;	//use to determin next plh to search all   //~v54VI~
//intersection chk                                                 //~v47tI~
    if (Plinebefore<0||Plineafter<0)                               //~v47tI~
    {                                                              //~v47tI~
        if (Sphasesw==2)    //and search                           //~v47tI~
            for (plh=Sandplh1,ii=0;plh;plh=UGETQNEXT(plh))         //~v47tI~
            {                                                      //~v47tI~
                if (plh==Pplh)                                     //~v47tI~
                    break;                                         //~v47tI~
                ii++;                                              //~v47tM~
            }                                                      //~v47tI~
        else                                                       //~v47tI~
  		  if (Psamelastplh)                                        //~v61bI~
//  		ii=Ssamelinectr;	//top and samectr;                 //~v61bR~//~vb2ER~
    		ii=(int)Ssamelinectr;	//top and samectr;             //~vb2EI~
          else                                                     //~v61bI~
			ii=0;                                                  //~v47tI~
        if (ii+Plineafter<0)	//after line is before the found line//~v54VI~
        	Splhafter=0;	//serach after found line              //~v54VI~
        ii+=Plinebefore+Plineafter;                                //~v47tI~
        if (ii<0)                                                  //~v61bR~
        {                                                          //~v47tI~
//      	uerrmsg("range err of -a and -b parm",0);              //~v613R~
//      	return 4;                                              //~v613R~
			Sothererr_abrange++;	//not notfound err count:ab range err//~v613I~
		    *Pplh1=plh1s;                                          //~v61bR~
		    *Pplh2=plh2s;                                          //~v61bI~
        	return RC_ERR_NOTNF;//skip not found err msg           //~v613R~
        }                                                          //~v47tI~
    }                                                              //~v47tI~
    return 0;                                                      //~v47tI~
}//fcmdaroundlinesub                                               //~v47tI~
//**************************************************               //~va5RI~
//*insert so/si to repword                                         //~va5RI~
//*rc:1 offset changed                                             //~va50I~
//**************************************************               //~va5RI~
int wordrep_setsosi(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int *Pppos,int *Ppsrchlen,//~va5RI~//~va50R~
					UCHAR *Prepword,UCHAR *Prepworddbcs,int Prepwordlen,int *Ppoutlen)//~va5RR~
{                                                                  //~va5RI~
	PUFILEH pfh;                                                   //~va5RI~
	UCHAR wkdata[MAXCOLUMN+4],wkdbcs[MAXCOLUMN+4];                 //~va5RI~
    UCHAR   *pci,*pcdi,*pco,*pcdo,*plhdata,*plhdbcs,nextch,*plhdataprev;               //~va5RR~//~va50R~
    int ulhlen,swtopdbcs,swenddbcs,outlen,binsw,rc=0,srchlen,pos;              //~va5RR~//~va50R~
//*************                                                    //~va5RI~
	srchlen=*Ppsrchlen;	//update may occurs when replace si of tail//~va50R~
	pos=*Pppos;		//update may occurs when replace si of head    //~va50I~
    UTRACED("wordrepebc inp data",Prepword,Prepwordlen);           //~va5RI~
    UTRACED("wordrepebc inp dbcs",Prepworddbcs,Prepwordlen);       //~va5RI~
	pfh=UGETPFH(Pplh);                                             //~va5RI~
	ulhlen=Pplh->ULHlen;                                           //~va5RI~
    plhdata=Pplh->ULHdata+pos;                                    //~va5RR~//~va50R~
    plhdbcs=Pplh->ULHdbcs+pos;                                    //~va5RR~//~va50R~
    pci=Prepword;                                                  //~va5RI~
    pcdi=Prepworddbcs;                                             //~va5RI~
    pco=wkdata;                                                    //~va5RI~
    pcdo=wkdbcs;                                                   //~va5RI~
    outlen=0;                                                      //~va5RI~
    binsw=Sescreplen||Sescreplen;                                  //~va5RR~
    if (binsw   //esc search/escrep                                //~va5RR~
    ||  UCBITCHK(pfh->UFHflag5,UFHF5HEX))                          //~va5RI~
    {                                                              //~va5RI~
//      memcpy(pco,pci,Prepwordlen);                               //~va5RI~//~vb2pR~
        memcpy(pco,pci,(size_t)Prepwordlen);                       //~vb2pI~
//      memcpy(pcdo,pcdi,Prepwordlen);                             //~va5RI~//~vb2pR~
        memcpy(pcdo,pcdi,(size_t)Prepwordlen);                     //~vb2pI~
        outlen=Prepwordlen;                                        //~va5RI~
    }//HHEX                                                        //~va5RI~
    else   //text to text nd not bin file                          //~va5RI~
    {                                                              //~va5RI~
//head                                                             //~va5RI~
    	swtopdbcs=UDBCSCHK_DBCSCOLS(*pcdi);	//repword head byte    //~va5RI~
    	if (!pos||pos>=ulhlen||!UDBCSCHK_DBCSCOLS(*plhdbcs))	//not into dbcs//~va5RR~//~va50R~
        {                                                          //~va5RI~
        	if (swtopdbcs)                                         //~va5RI~
            	*pco++=CHAR_SO,*pcdo++=0,outlen++;                 //~va5RI~
        }                                                          //~va5RI~
        else 	//into dbcs                                        //~va5RI~
        {                                                          //~va5RI~
        	if (!swtopdbcs)                                        //~va5RI~
            {                                                      //~va50I~
                plhdataprev=plhdata-1;                             //~va50I~
                if (*plhdataprev==CHAR_SO)                         //~va50R~
                {                                                  //~va50I~
			    	if (Sulsrchsw!=LINE_SAMESRCH)  //*=            //~va50I~
                		rc=1,pos--,srchlen++,plhdata--,plhdbcs--;  //~va50R~
                }                                                  //~va50I~
                else                                               //~va50I~
            		*pco++=CHAR_SI,*pcdo++=0,outlen++;                 //~va5RI~//~va50R~
            }                                                      //~va50I~
        }                                                          //~va5RI~
//      memcpy(pco,pci,Prepwordlen);                               //~va5RI~//~vb2pR~
        memcpy(pco,pci,(size_t)Prepwordlen);                       //~vb2pI~
//      memcpy(pcdo,pcdi,Prepwordlen);                             //~va5RI~//~vb2pR~
        memcpy(pcdo,pcdi,(size_t)Prepwordlen);                     //~vb2pI~
        pco+=Prepwordlen;                                          //~va5RI~
        pcdo+=Prepwordlen;                                         //~va5RI~
        outlen+=Prepwordlen;                                       //~va5RI~
//tail                                                             //~va5RI~
    	if (Sulsrchsw==LINE_SAMESRCH  //*=                         //~va5RI~
        &&  outlen>srchlen)	//overflow target column           //~va5RI~//~va50R~
        {                                                          //~va5RI~
        	outlen=srchlen;                                       //~va5RI~//~va50R~
        	pco=wkdata+outlen;                                     //~va5RI~
        	pcdo=wkdbcs+outlen;                                    //~va5RI~
        }                                                          //~va5RI~
	    swenddbcs=UDBCSCHK_DBCSCOLS(*(pcdo-1));      //repword tail byte//~va5RI~
    	if (pos+srchlen>=ulhlen||!UDBCSCHK_DBCSCOLS(*(plhdbcs+srchlen)))	//not into dbcs//~va5RR~//~va50R~
        {                                                          //~va5RI~
            if (pos+srchlen>=ulhlen)                               //~va50I~
                nextch=0;                                          //~va50I~
            else                                                   //~va50I~
                nextch=*(plhdata+srchlen);                         //~va50I~
        	if (swenddbcs)  //repword is end by DBCS               //~va5RI~//~va50R~
            {                                                      //~va50I~
            	if (nextch!=CHAR_SI)                               //~va50R~
            		*pco++=CHAR_SI,*pcdo++=0,outlen++;                 //~va5RI~//~va50R~
            }                                                      //~va50I~
            else                                                   //~va50I~
            {                                                      //~va50I~
            	if (nextch==CHAR_SI)   //rep dbcs by sbcs          //~va50R~
			    	if (Sulsrchsw!=LINE_SAMESRCH)  //*=            //~va50R~
             		   srchlen++;	//drop SI                      //~va50I~
            }                                                      //~va50I~
        }                                                          //~va5RI~
        else 	//into dbcs                                        //~va5RI~
        {                                                          //~va5RI~
        	if (!swenddbcs)                                        //~va5RI~
            	*pco++=CHAR_SO,*pcdo++=0,outlen++;                 //~va5RI~
        }                                                          //~va5RI~
    }                                                              //~va5RI~
    outlen=min(outlen,MAXCOLUMN);                                  //~va5RI~
    memcpy(Prepword,wkdata,(UINT)outlen);                          //~va5RR~
    memcpy(Prepworddbcs,wkdbcs,(UINT)outlen);                      //~va5RR~
    *Ppoutlen=outlen;                                              //~va5RI~
    *Ppsrchlen=srchlen;                                            //~va50I~
    *Pppos=pos;                                                    //~va50I~
    UTRACED("wordrepebc out data",Prepword,outlen);                //~va5RI~
    UTRACED("wordrepebc out dbcs",Prepworddbcs,outlen);            //~va5RI~
    UTRACEP("pos=%d<--%d,srchlen=%d<--%d\n",pos,*Pppos,srchlen,*Ppsrchlen);//~va50I~
    return rc;                                                     //~va5RR~
}//xeebc_filesetsosi                                               //~va5RI~
//****************************************************************//~5106I~
//!wordrep                                                      //~v04dR~
// replace word                                                 //~5106I~
//* parm1 :plh                                                  //~5106I~
//* parm2 :offset                                               //~5106I~
//* ret   :0:ok 4:reclev over max or UALLOC_FAILED              //~v04dR~
//****************************************************************//~5106I~
int wordrep(PUCLIENTWE Ppcw,PULINEH Pplh,int Poffset)           //~5107R~
{                                                               //~5106I~
	int reslen,addlen,reclen;                                   //~5106R~
    int reclen0;                                                   //~v0euI~
	UCHAR *pc,*pcd;                                             //~5106I~
	UCHAR *pc0,*pcd0;                                              //~v0euI~
	UCHAR *pct,*pcdt;                                              //~v0apI~
    int ii;                                                        //~v0apI~
    char *repword;                                                 //~v09OI~
    PUFILEH pfh;                                                   //~v0btI~
    int mergin;                                                    //~v0btI~
    int oomlen;                                                    //~v0c2I~
    int mode;                                                      //~v0eyI~
    int rc,spanlen;                                                //~v13pI~
    int srchlen,repwordlen,samereplen;                             //~v49bI~
    int rcmc=0;                                                    //~v71UR~
    int imlen;                                                     //~v73rI~
#ifdef UTF8UCS2                                                    //~va20I~
    int ddlen=0/*,swutf8file*/;                                    //~va20R~
	UCHAR rwdbcs[MAXCOLUMN];                                       //~va20I~
    UCHAR *prwdd,*prwdbcs=rwdbcs;                                  //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile,ebclen=0,imshiftlen;                               //~va50R~//~vafcR~
	UCHAR rwebc[MAXCOLUMN+1];                                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************                                             //~5106I~
	pfh=UGETPFH(Pplh);                                             //~v0btI~
//#ifdef UTF8UCS2                                                  //~va20R~
//    swutf8file=FILEUTF8MODE(pfh);                                //~va20R~
//#endif                                                           //~va20R~
    mergin=pfh->UFHmergin;                                         //~v0btI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
	Srcsosi=0;	//rc to caller                                     //~va50I~
	swebcfile=PFH_ISEBC(pfh);                                      //~va50M~
    if (swebcfile && !Sescreplen)                                  //~va50R~
    {                                                              //~va50I~
        if (fcmdgetebcsrchstr(SEARCH_CHANGE,Ppcw,&prwdd,&prwdbcs,&ebclen)>1)//~va50I~
            return 4;                                              //~va50I~
//      UmemcpyZ(rwebc,prwdd,ebclen);                              //~va50I~//~vb2pR~
        UmemcpyZ(rwebc,prwdd,(size_t)ebclen);                      //~vb2pI~
//      memcpy(rwdbcs,prwdbcs,ebclen);                             //~va50I~//~vb2pR~
        memcpy(rwdbcs,prwdbcs,(size_t)ebclen);                     //~vb2pI~
    }//ebcfile                                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
    if (Sulsrchsw==LINE_SAMESRCH)  //*=                            //~v49bI~
    {                                                              //~v49bI~
        srchlen=min(Srange2,Pplh->ULHlen);                         //~v49bI~
        if (Srange1)                                               //~v49bI~
            srchlen-=Srange1;//reverse len of *=                   //~v49bI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (swebcfile && !Sescreplen)                                //~va50R~
      {                                                            //~va50I~
        prwdd=rwebc;                                               //~va50I~
        prwdbcs=rwdbcs;                                            //~va50I~
  		wordrep_setsosi(0,Ppcw,Pplh,&Poffset,&srchlen,prwdd,prwdbcs,ebclen,&repwordlen);//~va50R~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif                                                             //~va50I~
      {                                                            //~va50I~
        repwordlen=srchlen;     //rep same length                  //~v49bI~
#ifdef UTF8UCS2                                                    //~va5RI~
			ddlen=fcmdisddsrch(SEARCH_CHANGE,Ppcw,&prwdd,&prwdbcs);//~va5RI~
        	if (ddlen)                                             //~va5RR~
            	;                                                  //~va5RR~
        	else                                                   //~va5RI~
				memset(rwdbcs,0,sizeof(rwdbcs));	//pointed by prwdbcs//~va5RI~
        if (ddlen && ddlen>srchlen)	//utf8 or ebc rep str          //~va5RR~
        {                                                          //~va5RI~
            ddlen=srchlen;                                         //~va5RR~
            if (UDBCSCHK_DBCS2NDU(*(prwdbcs+srchlen)))             //~va5RR~
            	ddlen--;                                           //~va5RI~
            if (ddlen<=0)                                          //~va5RI~
            {                                                      //~va5RI~
                uerrmsg("target field is too small to set UTF8 DBCS char",0);//~va5RI~
            	return 4;                                          //~va5RI~
            }                                                      //~va5RI~
        }                                                          //~va5RI~
#endif                                                             //~va5RI~
      }//!ebc                                                      //~va50I~
    }                                                              //~v49bI~
    else                                                           //~v49bI~
    {                                                              //~v49bI~
        srchlen=Ssrchlen;                                          //~v49bI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (swebcfile && !Sescreplen)                                //~va50I~
      {                                                            //~va50I~
        prwdd=rwebc;                                               //~va50I~
        prwdbcs=rwdbcs;                                            //~va50I~
       if (Sebcstrlen)		//Sescsrchlen(=>Ssrchlen) >0 if Sebcstrlen=0//~va7gI~
        srchlen=Sebcstrlen;                                        //~va50I~
  		Srcsosi=wordrep_setsosi(0,Ppcw,Pplh,&Poffset,&srchlen,prwdd,prwdbcs,ebclen,&repwordlen);//~va50R~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif                                                             //~va50I~
      {                                                            //~va50I~
        repwordlen=Srepwordlen;                                    //~v49bI~
#ifdef UTF8UCS2                                                    //~va20I~
		ddlen=fcmdisddsrch(SEARCH_CHANGE,Ppcw,&prwdd,&prwdbcs);    //~va20I~
        if (ddlen)                                                 //~va20I~
            srchlen=Sucswordlen;                                   //~va20I~
        else                                                       //~va20I~
			memset(rwdbcs,0,sizeof(rwdbcs));	//pointed by prwdbcs//~va20I~
#endif                                                             //~va20I~
      }//!ebc                                                      //~va50I~
    }                                                              //~v49bI~
    if (Sescreplen)                                                //~v0avI~
    {                                                              //~va20I~
        repword=Sescrepchar;                                       //~v0avI~
      if (swebcfile)                                               //~va50I~
      {                                                            //~va50I~
        prwdd=repword;                                             //~va50I~
        memset(rwdbcs,0,sizeof(rwdbcs));                           //~va50I~
      }                                                            //~va50I~
      else                                                         //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
      {                                                            //~va50I~
       	if ((Sothopt & SEARCH_ESCDDREP))	//not repword for utf8file//~va20I~
       	{                                                          //~va20I~
        	repword=prwdd;                                         //~va20I~
        	Srepwordlen=repwordlen=ddlen;                          //~va20I~
       	}                                                          //~va20I~
       	else                                                       //~va20I~
        	ddlen=0;                                               //~va20I~
      }                                                            //~va50I~
#endif                                                             //~va20I~
    }                                                              //~va20I~
    else                                                           //~v0avI~
    {                                                              //~va20I~
        repword=Srepword;                                          //~v0avI~
#ifdef UTF8UCS2                                                    //~va20M~
//  	Srepwordlen=strlen(Srepword);	//for not utf8 file        //~va20M~//~vb2pR~
    	Srepwordlen=(int)strlen(Srepword);	//for not utf8 file    //~vb2pI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      	if (swebcfile)                                             //~va50I~
      	{                                                          //~va50I~
        	repword=prwdd;                                         //~va50I~
        	Srepwordlen=repwordlen;                                //~va50I~
      	}                                                          //~va50I~
      	else                                                       //~va50I~
#endif                                                             //~va50I~
	  	if (ddlen)                                                 //~va20I~
      	{                                                          //~va20I~
        	repword=prwdd;                                         //~va20I~
          if (Sulsrchsw!=LINE_SAMESRCH)  //*=                      //~va5RI~
        	Srepwordlen=repwordlen=ddlen;                          //~va20I~
      	}                                                          //~va20I~
#endif                                                             //~va20M~
    }                                                              //~va20I~
    pc0 =Pplh->ULHdata;                                            //~v0euI~
    pcd0=Pplh->ULHdbcs;                                            //~v0euI~
    reclen0=Pplh->ULHlen;                                          //~v0euI~
    pc =pc0+Poffset;                                               //~v0euR~
    pcd=pcd0+Poffset;                                              //~v0euR~
//  reslen=reclen0-Poffset-Ssrchlen;	//len after word           //~v49bR~
    reslen=reclen0-Poffset- srchlen;	//len after word           //~v49bI~
//  addlen=Srepwordlen-Ssrchlen;                                   //~v49bR~
    addlen= repwordlen- srchlen;                                   //~v49bI~
    reclen=reclen0+addlen;                                         //~v0euR~
    if (reslen<0)       //spaned match,repword set to 1st line     //~v13pI~
    {                                                              //~v13pI~
        spanlen=-reslen;//len in followed line,to be dropped       //~v13pI~
        addlen+=spanlen;//repword fully set to 1st line            //~v13pI~
        reclen+=spanlen;                                           //~v13pI~
        reslen=0;                                                  //~v13pI~
    }                                                              //~v13pI~
    else                                                           //~v13pI~
    	spanlen=0;                                                 //~v13pI~
//  if (reclen>MAXLINEDATA)                                        //~v0avR~
//  	return charmaxovererr();                                   //~v0avR~
//  if (Poffset>=mergin)                                           //~v0e3R~
    if (Poffset<mergin                                             //~v0e3I~
//  &&  Poffset+Ssrchlen>mergin)                                   //~v49bR~
    &&  Poffset+ srchlen>mergin)                                   //~v49bI~
//  	return charmerginerr(mergin);                              //~v0dvR~
    	return charmaxovererr(mergin);                             //~v0dvI~
    mode=MERGIN_REPMODE;                                           //~v0eyI~
    if (UCBITCHK(pfh->UFHflag3,UFHF3OOMNOPROT))	//no protected     //~v0eyI~
	    mode|=MERGIN_OOMOK;						//oom update ok    //~v0eyI~
    mode|=MERGIN_SHORTRECOK; //accept merginover flow is space only for short record//~v71UR~
//  if (filemerginchk(Pplh,Poffset,repword,Srepwordlen,Ssrchlen,   //~v49bR~
#ifdef UTF8UCS2                                                    //~va20I~
    if (filemerginchk(Pplh,Poffset,repword,prwdbcs,repwordlen,srchlen,//~va20I~
#else                                                              //~va20I~
    if (filemerginchk(Pplh,Poffset,repword, repwordlen, srchlen,   //~v49bI~
#endif                                                             //~va20I~
//						MERGIN_REPMODE,0,0,&oomlen))//addlen=netlen=0//~v0e3R~
//		   MERGIN_OOMOK|MERGIN_REPMODE,0,0,&oomlen))//addlen=netlen=0//~v0eyR~
  		   mode,0,0,&oomlen))//addlen=netlen=0                     //~v0eyI~
    	return 4;                                                  //~v0btR~
    if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)           //~v04dR~
    	return UALLOC_FAILED;                                   //~v04dI~
                                                                   //~v09II~
//drop tab and dbcs half                                           //~v09MI~
	if (oomlen && addlen)		//len changed                      //~v0euI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		setobtabdbcs(swebcfile,0,pc0,pcd0,reclen0,mergin,0);       //~va50I~
#else                                                              //~va50I~
		setobtabdbcs(pc0,pcd0,reclen0,mergin,0);                   //~v0ewR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (oomlen==-1)                                                //~v71UR~
    {                                                              //~v71UR~
        oomlen=0;                                                  //~v71UR~
        rcmc=1; //shortrec ovf is space only                       //~v71UR~
    }                                                              //~v71UR~
	if (Stabsrchsw)                                                //~v09II~
    	charcleartabdbcs(pcd);//clear tab and tab padding          //~v09IR~
    else                                                           //~v73sI~
    {                                                              //~v73sI~
        btabclear(pc0,pcd0,reclen0,Poffset,0);//0:no clear right boundary//~v73sI~
        btabclear(pc0,pcd0,reclen0,Poffset+srchlen,1);//0:no clear right boundary//~v73sI~
    }                                                              //~v73sI~
//  if (Sescreplen)                                                //~v0avR~
//      repword=Sescrepchar;                                       //~v0avR~
//  else                                                           //~v0avR~
//      repword=Srepword;                                          //~v0avR~
	if (addlen>0)		//to be expand                          //~5106I~
	{                                                           //~5106I~
		if (reclen>Pplh->ULHbufflen)	//expandbuff            //~5106R~
        {                                                       //~5209I~
			if (fileexpandbuff(Pplh,reclen)==UALLOC_FAILED)	//for new word//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
    		pc =Pplh->ULHdata+Poffset;                          //~5209I~
    		pcd=Pplh->ULHdbcs+Poffset;                          //~5209I~
        }                                                       //~5209I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
     if (swebcfile)                                                //~va50I~
     {                                                             //~va50I~
    	if (oomlen) //Pcurcol is inmargin                          //~va50I~
        {                                                          //~va50I~
        	imshiftlen=mergin-Poffset-repwordlen;                  //~va50R~
            reclen=reclen0;                                        //~va50I~
        }                                                          //~va50I~
        else                                                       //~va50I~
        	imshiftlen=reslen;                                     //~va50I~
		if (imshiftlen>0)                                          //~va50I~
		{                                                          //~va50I~
			memmove(pc+repwordlen,pc+srchlen,(UINT)imshiftlen);//shift to right//~va50I~//~va5RR~
			memmove(pcd+repwordlen,pcd+srchlen,(UINT)imshiftlen);//shift to right//~va50I~//~va5RR~
		}                                                          //~va50I~
		memcpy (pc ,prwdd,(UINT)repwordlen);                       //~va5RI~
		memcpy (pcd,prwdbcs,(UINT)repwordlen);                     //~va5RI~
    	Pplh->ULHlen=reclen;                                       //~va50I~
		xeebc_setdbcstblplh(0,0/*pfh*/,Pplh,0/*len*/);             //~va50I~
     }                                                             //~va50I~
     else                                                          //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
     {//!ebc                                                       //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
		memmove(pc +Srepwordlen,pc +srchlen,(UINT)reslen);//right shift//~va20I~
		memmove(pcd+Srepwordlen,pcd+srchlen,(UINT)reslen);//right shift//~va20I~
#else                                                              //~va20I~
		memmove(pc +Srepwordlen,pc +Ssrchlen,(UINT)reslen);//right shift//~5106R~
		memmove(pcd+Srepwordlen,pcd+Ssrchlen,(UINT)reslen);//right shift//~5106R~
#endif                                                             //~va20I~
      if (Sfindopt & FINDOPT_GREPPTARGET)   //change target is P'..' pattern//~v79LI~
		wordrepp(pc,repword,Ssrchlen,repwordlen);                  //~v79LI~
      else                                                         //~v79LI~
      {                                                            //~va20I~
		memcpy (pc ,repword,(UINT)Srepwordlen);                    //~v09OR~
#ifdef UTF8UCS2                                                    //~va20I~
        if (ddlen)                                                 //~va20I~
			memcpy (pcd,prwdbcs,(UINT)Srepwordlen);                //~va20I~
#endif                                                             //~va20I~
      }                                                            //~va20I~
//  	setdbcstbl(pc,pcd,Srepwordlen);	//has no hab,dbcs chk      //~v09YR~
//  	filesetdbcstbl(pc,pcd,Srepwordlen);	//has no hab,dbcs chk  //~v21nR~
#ifdef UTF8UCS2                                                    //~va20I~
      if (!ddlen)                                                  //~va20I~
#endif                                                             //~va20I~
    	filerepwordsetdbcstbl(Pplh,pc,pcd,Ssrchlen,Srepwordlen);	//update dbcstbl//~v21nI~
    	Pplh->ULHlen=reclen;                                       //~v0euI~
//      if (oomlen)                                                //~v73rR~
//          fileoomshiftback(pfh,Pplh,oomlen);                     //~v73rR~
     }//!ebc                                                       //~va50I~
	}                                                           //~5106I~
    else	//same or short replace                             //~5106I~
    {                                                           //~5106I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
     if (swebcfile)                                                //~va50I~
     {                                                             //~va50I~
      if (Sulsrchsw==LINE_SAMESRCH)  //*=                          //~va50I~
      {                                                            //~va50I~
		UCVEBC_memset_space(swebcfile,pc,(UINT)srchlen);           //~va50I~
		memset(pcd,0,(UINT)srchlen);                               //~va50I~
        samereplen=min(srchlen,repwordlen);                        //~va50I~
		memcpy (pc ,prwdd,(UINT)samereplen);                       //~va50I~
		memcpy (pcd,prwdbcs,(UINT)samereplen);                     //~va50I~
      }                                                            //~va50I~
      else                                                         //~va50I~
      {                                                            //~va50I~
		memcpy (pc ,prwdd,(UINT)repwordlen);                       //~va50I~
		memcpy (pcd,prwdbcs,(UINT)repwordlen);                     //~va50I~
		if (addlen)	//shorten                                      //~va50I~
		{                                                          //~va50I~
	    	if (oomlen) //Pcurcol is inmargin                      //~va50I~
    	    	imshiftlen=mergin-Poffset-srchlen;                 //~va50I~
        	else                                                   //~va50I~
        		imshiftlen=reslen;                                 //~va50I~
			memcpy(pc +repwordlen,pc +srchlen,(UINT)imshiftlen);//left shift//~va50I~
			memcpy(pcd+repwordlen,pcd+srchlen,(UINT)imshiftlen);//left shift//~va50I~
	    	if (oomlen) //Pcurcol is inmargin                      //~va50I~
            {                                                      //~va50I~
				UCVEBC_memset_space(swebcfile,pc+repwordlen+imshiftlen,(UINT)-addlen);//~va50R~
				memset(pcd+repwordlen+imshiftlen,0,(UINT)-addlen); //~va50R~
                reclen=reclen0;                                    //~va50I~
            }                                                      //~va50I~
            else                                                   //~va50I~
				Pplh->ULHlen=reclen;                               //~va50R~
        }//shorten                                                 //~va50I~
      }                                                            //~va50I~
		xeebc_setdbcstblplh(0,0/*pfh*/,Pplh,0/*len*/);             //~va50I~
     }//ebc                                                        //~va50I~
     else                                                          //~va50I~
#endif                                                             //~va50I~
     {//!ebc                                                       //~va50I~
      if (Sulsrchsw==LINE_SAMESRCH)  //*=                          //~v49bI~
      {                                                            //~v49bI~
		memset (pc ,' ',(UINT)repwordlen);                         //~v49bI~
#ifdef UTF8UCS2                                                    //~va5RI~
       if (ddlen)                                                  //~va5RI~
        samereplen=min(ddlen,repwordlen);                          //~va5RI~
       else                                                        //~va5RI~
#endif                                                             //~va5RI~
        samereplen=min(Srepwordlen,repwordlen);                    //~v49bI~
		memcpy (pc ,repword,(UINT)samereplen);                     //~v49bI~
#ifdef UTF8UCS2                                                    //~va5RI~
      	if (ddlen)                                                 //~va5RI~
			memcpy (pcd,prwdbcs,(UINT)samereplen);                 //~va5RR~
#endif                                                             //~va5RI~
      }                                                            //~v49bI~
      else                                                         //~v49bI~
      if (Sfindopt & FINDOPT_GREPPTARGET)   //change target is P'..' pattern//~v79LI~
		wordrepp(pc,repword,Ssrchlen,repwordlen);                  //~v79LI~
      else                                                         //~v79LI~
#ifdef UTF8SUPPH                                                   //~va1GI~
	  if (Sothopt & SEARCH_UTF8ECHR) //cmd "change *ec *"          //~va1GI~
		*pcd=UDBCSCHK_HKDBCSERR;	//reset UDBCSCHK_F2LERR,re-evaluate by setdbcstbl//~va1GR~
      else                                                         //~va1GI~
#endif                                                             //~va1GI~
      {                                                            //~va20I~
		memcpy (pc ,repword,(UINT)Srepwordlen);                    //~v09OR~
#ifdef UTF8UCS2                                                    //~va20I~
      	if (ddlen)                                                 //~va20I~
			memcpy (pcd,prwdbcs,(UINT)Srepwordlen);                //~va20I~
#endif                                                             //~va20I~
      }                                                            //~va20I~
//    if (*repword==TABCHAR)                                       //~v0apR~
//  	*pcd=TABCHAR;	//Srepword is changed to space already     //~v0apR~
//    else	                                                       //~v0apR~
//		setdbcstbl(pc,pcd,Srepwordlen);	//has no hab,dbcs chk      //~v09YR~
//		filesetdbcstbl(pc,pcd,Srepwordlen);	//has no hab,dbcs chk  //~v21nR~
		if (addlen)	//shorten                                   //~5106I~
		{                                                       //~5106I~
#ifdef UTF8UCS2                                                    //~va20I~
			memcpy(pc +Srepwordlen,pc +srchlen,(UINT)reslen);//left shift//~va20I~
			memcpy(pcd+Srepwordlen,pcd+srchlen,(UINT)reslen);//left shift//~va20I~
#else                                                              //~va20I~
			memcpy(pc +Srepwordlen,pc +Ssrchlen,(UINT)reslen);//left shift//~5106R~
			memcpy(pcd+Srepwordlen,pcd+Ssrchlen,(UINT)reslen);//left shift//~5106R~
#endif                                                             //~va20I~
			Pplh->ULHlen=reclen;                                   //~v0euI~
	        if (oomlen)                                            //~v0euI~
//	            fileoomshiftback(pfh,Pplh,oomlen);                 //~v74ER~
  	            fileoomshiftback(pfh,Pplh,oomlen,0);               //~v74EI~
        }//shorten                                              //~5106I~
//  	filerepwordsetdbcstbl(Pplh,pc,pcd,Ssrchlen,Srepwordlen);	//update dbcstbl//~v49bR~
#ifdef UTF8UCS2                                                    //~va20I~
      if (!ddlen)                                                  //~va20I~
#endif                                                             //~va20I~
    	filerepwordsetdbcstbl(Pplh,pc,pcd, srchlen, repwordlen);	//update dbcstbl//~v49bI~
     }//!ebc                                                       //~va50I~
    }//shorten                                                  //~5106I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (!swebcfile)                                                  //~va50I~
#endif                                                             //~va50I~
  {                                                                //~va50I~
//  Pplh->ULHlen=reclen;                                           //~v0euR~
	if (addlen                                                     //~v09IR~
//  ||  *repword==TABCHAR)	//changed to tab                       //~v0apR~
    ||  Stabrepsw)        	//changed to tab                       //~v0apI~
    	if (UCBITCHK(Pplh->ULHflag2,ULHF2TABFOUND)                 //~v09IR~
//  	||  *repword==TABCHAR)	//changed to tab                   //~v0apR~
    	||  Stabrepsw)        	//changed to tab                   //~v0apI~
		{                                                       //~5106I~
          	if (Stabrepsw)                                         //~v0apI~
    			for (ii=0,pct=pc,pcdt=pcd;ii<Srepwordlen;ii++,pct++,pcdt++)//~v0apI~
            		if (*pct==TABCHAR)                             //~v0apI~
                	{                                              //~v0apI~
//*for ebcdic Stabrepsw is always off                              //~va50I~
                		*pct=' ';                                  //~v0apI~
                		*pcdt=TABCHAR;                             //~v0apI~
                	}                                              //~v0apI~
			reslen+=Srepwordlen;	//len after repled pos      //~5106I~
          if (oomlen)                                              //~v0euI~
          {                                                        //~v73rI~
//  		fileimtabexp(Pplh,Poffset,0,mergin);//len=mergin;expand in mergin//~v73rR~
    		imlen=Pplh->ULHlen-Poffset-oomlen;		//process temporary in margin part//~v73rI~
    		fileimtabexp(Pplh,Poffset,&imlen,mergin);//len=mergin;expand in mergin//~v73rI~
          }                                                        //~v73rI~
          else                                                     //~v71UR~
          if (rcmc)                                                //~v71UR~
          {                                                        //~v73rI~
//  		fileimtabexp(Pplh,Poffset,0,mergin);//len=mergin;expand in mergin//~v73rR~
    		imlen=Pplh->ULHlen-Poffset;		//process in margin part//~v73rI~
    		fileimtabexp(Pplh,Poffset,&imlen,mergin);//len=mergin;expand in mergin//~v73rI~
          }                                                        //~v73rI~
          else                                                     //~v0euI~
 			if (filetabexp(1,Pplh,Poffset,&reslen)==UALLOC_FAILED)	//tab re-expand(len update)//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
		}                                                       //~5106I~
    if (addlen>0)                                                  //~v73rI~
        if (oomlen) //after imtabexp                               //~v73rI~
//          fileoomshiftback(pfh,Pplh,oomlen);                     //~v74ER~
            fileoomshiftback(pfh,Pplh,oomlen,0);                   //~v74EI~
    if (rcmc)                                                      //~v71UR~
    	Pplh->ULHlen=mergin;    //cut overflowed space             //~v71UR~
  }//!ebc                                                          //~va50I~
//  fileoomshiftback(pfh,Pplh,oomlen);                             //~v0euR~
	if (spanlen)	//rep of spaned word                           //~v13pI~
    	if (rc=fcmdsplitrep(Ppcw,Pplh,spanlen),rc)                 //~v13pI~
	    	return rc;                                             //~v13pI~
    return 0;                                                   //~5107R~
}//wordrep                                                      //~5106R~
//**************************************************************** //~v79LI~
//!wordrepp                                                        //~v79LI~
// replace word according target pattern of  <(lower), >(uuper),= (no replace)//~v79LI~
//**************************************************************** //~v79LI~
int wordrepp(UCHAR *Ptgt,UCHAR *Ppattern,int Ptgtlen,int Ppatternlen)//~v79LI~
{                                                                  //~v79LI~
	UCHAR *pct,*pcp,cht,chp;                                       //~v79LI~
    int rplen,rtlen;                                               //~v79LI~
//****************************                                     //~v79LI~
  	for (pct=Ptgt,pcp=Ppattern+2,rtlen=Ptgtlen,rplen=Ppatternlen;rplen>0;rtlen--,rplen--)//~v79LI~
    {                                                              //~v79LI~
        chp=*pcp++;	//pattern char                                 //~v79LI~
        if (rtlen>0)	//target len>pattern len                   //~v79LI~
        {                                                          //~v79LI~
            cht=*pct;                                              //~v79LI~
            switch(chp)                                            //~v79LI~
            {                                                      //~v79LI~
            case '=':                                              //~v79LI~
                break;                                             //~v79LI~
            case '<':                                              //~v79LI~
                cht=(UCHAR)tolower((int)cht);                      //~v79LI~
                break;                                             //~v79LI~
            case '>':                                              //~v79LI~
                cht=(UCHAR)toupper((int)cht);                      //~v79LI~
                break;                                             //~v79LI~
            default:                                               //~v79LI~
                cht=chp;                                           //~v79LI~
            }                                                      //~v79LI~
        }                                                          //~v79LI~
        else                                                       //~v79LI~
        	cht=chp;                                               //~v79LI~
        *pct++=cht;                                                //~v79LI~
    }                                                              //~v79LI~
    return 0;                                                      //~v79LI~
}//wordrepp                                                        //~v79LI~
//#ifdef LNX                                                         //~vauiM~//~vauFR~
//**************************************************************** //~vauiI~
//ascii search                                                     //~vauiI~
//**************************************************************** //~vauiI~
char *fcmdddstrsrch_dirfnm_ascii(int Popt,char *Pascii,int *Ppoffs)//~vauiI~
{                                                                  //~vauiI~
	char *pc=NULL,*pc0;                                            //~vauiR~
    int offs;                                                      //~vauiR~
//**********************                                           //~vauiI~
    UTRACED("tgt",Pascii,(int)strlen(Pascii));                          //~vauiI~//~vb2pR~
	pc0=Pascii;                                                    //~vauiI~
	if (Sescsrchlen)                                               //~vauiI~
    {                                                              //~vauiI~
	    UTRACED("srch",Sescsrchchar,Sescsrchlen);                  //~vauiM~
        if (Sescsrchlen!=strlen(Sescsrchchar))                     //~vauiR~
        {                                                          //~vauiI~
	    	if (Scasesensesw)                                      //~vauiR~
    	    	pc=strstr(pc0,Sescsrchchar);                       //~vauiR~
        	else                                                   //~vauiR~
        		pc=ustrstri(pc0,Sescsrchchar);                     //~vauiR~
        }                                                          //~vauiI~
    }                                                              //~vauiI~
    else                                                           //~vauiI~
    {                                                              //~vauiI~
	    UTRACEP("srch=%s\n",Ssrch);                                //~vauiI~
    	if (Scasesensesw)                                          //~vauiI~
        	pc=strstr(pc0,Ssrch);                                  //~vauiR~
        else                                                       //~vauiI~
        	pc=ustrstri(pc0,Ssrch);                                //~vauiI~
    }                                                              //~vauiI~
    if (pc)                                                        //~vauiI~
    	offs=PTRDIFF(pc,pc0);                                      //~vauiI~
    else                                                           //~vauiI~
    	offs=-1;                                                   //~vauiI~
    *Ppoffs=offs;                                                  //~vauiI~
    UTRACEP("fcmdddstrsrch_dirfnm_ascii offs=%d,pc=%s\n",offs,pc); //~vauiI~
    return pc;                                                     //~vauiI~
}//fcmdddstrsrch_dirfnm_ascii                                      //~vauiI~
//**************************************************************** //~vauiI~
//ddsrch on dirlist                                                //~vauiI~
//**************************************************************** //~vauiI~
char *fcmdddstrsrch_dirfnm(int Popt,PUDIRLH Ppdh,int Pboundary2,int *Ppoffs)//~vauiR~
{                                                                  //~vauiI~
	int ddlenf,ddlens,boundary1,boundary2,slinkoffs,offset,opt,srchlen;//~vauiR~
    int slinkoffsinfnm,ddoffs;                                     //~vauiR~
	UCHAR *pc0f,*pcd0f,*pc0s,*pcd0s,*pc,*srchstr,*srchdbcs;        //~vauiR~
	UCHAR *pc0f_ascii,*pc0s_ascii;                                 //~vauiR~
//***********************                                          //~vauiI~
    offset=*Ppoffs;                                                //~vauiI~
    boundary1=Ppdh->UDHnameoffs;                    //fnm fld offset//~vauiI~
    boundary2=Pboundary2;  //fnm field max(contains slink)         //~vauiR~
    ddlenf=Ppdh->UDHnameddfmtlen;                                  //~vauiR~
    pc0f=Ppdh->UDHnameddfmt;                                       //~vauiR~
    pc0f_ascii=Ppdh->UDHname;	//ascii                            //~vauiI~
    pcd0f=pc0f+ddlenf;                                             //~vauiR~
    ddlens=Ppdh->UDHslinkddfmtlen;                                 //~vauiI~
    pc0s=Ppdh->UDHslinkddfmt;                                      //~vauiI~
    pc0s_ascii=Ppdh->UDHslink;	//ascii                            //~vauiR~
    pcd0s=pc0s+ddlens;                                             //~vauiR~
    slinkoffsinfnm=Ppdh->UDHslinkoffs;                   //slink offset from boundary1//~vauiR~
    slinkoffs=boundary1+slinkoffsinfnm;                            //~vauiI~
    UTRACEP("fcmdddsrch_dir start opt=%x,offs=%d,endoffs=%d,slinkoffs=%d,slinkinfnm=%d,Sescsrchlen=%d\n",Popt,boundary1,boundary2,slinkoffs,slinkoffsinfnm,Sescsrchlen);//~vauiR~
    opt=0;                                                         //~vauiI~
    if (!Scasesensesw)                                             //~vauiI~
	    opt|=FCMDDDSSO_NOCASE;//case insensitive                   //~vauiI~
    if (Sescsrchlen)                                               //~vauiR~
    {                                                              //~vauiI~
        srchstr=Sescsrchchar;                                      //~vauiR~
        srchdbcs=NULL;                                             //~vauiI~
        srchlen=Sescsrchlen;                                       //~vauiI~
    }                                                              //~vauiI~
    else                                                           //~vauiI~
    {                                                              //~vauiI~
    	opt|=FCMDDDSSO_DDSTR;                                      //~vauiM~
		if (Sphasesw==2)		//2nd of and search                //~vauiI~
        {                                                          //~vauiI~
        	srchstr=Gsrchdd2;                                      //~vauiI~
        	srchdbcs=Gsrchdbcs2;                                   //~vauiI~
        	srchlen=Gsrchlendd2;                                   //~vauiI~
        }                                                          //~vauiI~
        else                                                       //~vauiI~
        {                                                          //~vauiI~
        	srchstr=Gsrchdd;                                       //~vauiR~
        	srchdbcs=Gsrchdbcs;                                    //~vauiR~
        	srchlen=Gsrchlendd;                                    //~vauiR~
        }                                                          //~vauiI~
    }                                                              //~vauiI~
    Sdirsrchlen=srchlen;	//for highlight word length            //~vauiI~
    pc=NULL;                                                       //~vauiI~
    for (;;)                                                       //~vauiI~
    {                                                              //~vauiI~
        if (Popt & FCMDDDSSDO_PREV)                                //~vauiI~
        {                                                          //~vauiI~
            if (slinkoffsinfnm && offset>=slinkoffs)   //search in displayed slink//~vauiR~
            {                                                      //~vauiI~
            	if (ddlens)	//not ascii slink                      //~vauiI~
	                pc=fcmdddstrsrch_dir(opt,srchstr,srchdbcs,srchlen,pc0s,pcd0s,ddlens,&ddoffs);//~vauiI~
                else                                               //~vauiI~
	                pc=fcmdddstrsrch_dirfnm_ascii(opt,pc0s_ascii,&ddoffs);//~vauiI~
                if (pc)                                            //~vauiI~
                {                                                  //~vauiI~
                    offset=slinkoffs+ddoffs;                       //~vauiR~
                	Sdirstep=boundary1-offset; //next find to prev plh,avoid null//~vauiI~
                	Sdirstepr=boundary2-offset; //go to boundary1  //~vauiI~
                    if (Sdirstepr<0)                               //~vb5cI~
                        Sdirstepr=offset;                          //~vb5cI~
                    break;                                         //~vauiI~
                }                                                  //~vauiI~
            }                                                      //~vauiI~
            if (!pc)                                               //~vauiR~
            {                                                      //~vauiI~
            	if (ddlenf)	//not ascii membername                 //~vauiI~
                	pc=fcmdddstrsrch_dir(opt,srchstr,srchdbcs,srchlen,pc0f,pcd0f,ddlenf,&ddoffs);//~vauiI~
                else                                               //~vauiI~
	                pc=fcmdddstrsrch_dirfnm_ascii(opt,pc0f_ascii,&ddoffs);//~vauiI~
                if (pc)                                            //~vauiI~
                {                                                  //~vauiR~
                    offset=boundary1+ddoffs;                       //~vauiR~
                	Sdirstep=1-offset; //UDHlevel                  //~vauiI~
                    if (slinkoffsinfnm)                            //~vauiR~
                		Sdirstepr=slinkoffs-offset; //go to boundary1//~vauiI~
                    else                                           //~vauiI~
                		Sdirstepr=boundary2-offset; //go to boundary1//~vauiI~
                    if (Sdirstepr<0)                               //~vb5cI~
                        Sdirstepr=offset;                          //~vb5cI~
                    break;                                         //~vauiR~
                }                                                  //~vauiR~
            }                                                      //~vauiI~
        }                                                          //~vauiI~
        else  //next                                               //~vauiI~
        {                                                          //~vauiI~
            if (!slinkoffsinfnm || offset<boundary1+ddlenf) //search in membername//~vauiR~
            {                                                      //~vauiI~
            	                                                   //~vauiI~
            	if (ddlenf)	//not ascii                            //~vauiI~
                	pc=fcmdddstrsrch_dir(opt,srchstr,srchdbcs,srchlen,pc0f,pcd0f,ddlenf,&ddoffs);//~vauiI~
                else                                               //~vauiI~
	                pc=fcmdddstrsrch_dirfnm_ascii(opt,pc0f_ascii,&ddoffs);//~vauiI~
                if (pc)                                            //~vauiI~
                {                                                  //~vauiR~
                    offset=boundary1+ddoffs;                       //~vauiR~
                    if (slinkoffsinfnm)                            //~vauiR~
                		Sdirstep=slinkoffs-offset; //next find to prev plh,avoid null//~vauiI~
                    else                                           //~vauiI~
                		Sdirstep=boundary2-offset;//go to boundary2//~vauiI~
                    if (Sdirstep<0)                                //~vb5cI~
                        Sdirstep=offset;                           //~vb5cI~
                	Sdirstepr=1-offset;    //go to UDHlevel        //~vauiI~
                    break;                                         //~vauiR~
                }                                                  //~vauiR~
            }                                                      //~vauiI~
            if (!pc && slinkoffsinfnm) //unmatch on filename,slink exist//~vauiR~
            {                                                      //~vauiI~
            	if (ddlens)	//not ascii slink                      //~vauiI~
                	pc=fcmdddstrsrch_dir(opt,srchstr,srchdbcs,srchlen,pc0s,pcd0s,ddlens,&ddoffs);//~vauiI~
                else                                               //~vauiI~
	                pc=fcmdddstrsrch_dirfnm_ascii(opt,pc0s_ascii,&ddoffs);//~vauiI~
                if (pc)                                            //~vauiR~
                {                                                  //~vauiI~
                    offset=slinkoffs+ddoffs;                       //~vauiR~
                	Sdirstep=boundary2-offset;//go to boundary2    //~vauiI~
                	Sdirstepr=boundary1-offset; //go to fnm        //~vauiI~
                    if (Sdirstep<0)                                //~vb5cI~
                        Sdirstep=offset;                           //~vb5cI~
                    break;                                         //~vauiI~
                }                                                  //~vauiI~
            }                                                      //~vauiI~
        }                                                          //~vauiI~
        break;                                                     //~vauiI~
    }                                                              //~vauiI~
    if (pc)                                                        //~vauiI~
    {                                                              //~vauiI~
        if (offset>boundary2)                                      //~vauiI~
            offset=boundary2;//hidden                              //~vauiI~
    }	                                                           //~vauiI~
    *Ppoffs=offset;                                                //~vauiR~
    UTRACEP("fcmdddsrch_dir offs=%d,pc=%s,dirstep=%d,dirstepR=%d\n",offset,pc,Sdirstep,Sdirstepr);//~vauiR~
	return pc;                                                     //~vauiI~
}//fcmdddstrsrch_dirfnm                                            //~vauiR~
//#endif //LNX                                                       //~vauiI~//~vauFR~
//**************************************************************** //~vbc1I~
//dir list attr matching                                           //~vbc1I~
//match if including all attr of Ssrch                             //~vbc1R~
//**************************************************************** //~vbc1I~
int fcmdfind_dirattr(int Popt,int Psubcmdid,PUCLIENTWE Ppcw,PUDIRLH Ppdh,PUDIRLD Ppdd,int Pnameoffs,int Pexpandlen,char *Psrch,int *Ppoffset,int *Ppdirstep,int *Ppdirstepr)//~vbc1R~
{                                                                  //~vbc1I~
	int rc=0,ii,len,step,offset,boundary1,boundary2;               //~vbc1R~
    char *pcs,*pct;                                                //~vbc1I~
//****************************                                     //~vbc1I~
	offset=*Ppoffset;                                              //~vbc1I~
    pcs=Psrch;                                                     //~vbc1I~
    if (toupper(*pcs)=='L')                                        //~vbc1I~
    {                                                              //~vbc1I~
        if (!Ppdh->UDHslink)        //slink defined                //~vbc1I~
        	return 4;                                              //~vbc1I~
        if (Psubcmdid==SUBCMD_PREV)                                //~vbc1I~
        {                                                          //~vbc1I~
            if (offset<Pnameoffs-1)                                //~vbc1I~
                return 4;                                          //~vbc1I~
        }                                                          //~vbc1I~
        else                                                       //~vbc1I~
        {                                                          //~vbc1I~
            if (offset>=Pnameoffs)                                 //~vbc1I~
                return 4;                                          //~vbc1I~
        }                                                          //~vbc1I~
        *Ppoffset=Pnameoffs-1;                                     //~vbc1R~
        if (Psubcmdid==SUBCMD_PREV)                                //~vbc1I~
        {                                                          //~vbc1I~
        	*Ppdirstep=-1;                                         //~vbc1I~
        	*Ppdirstepr=1;                                         //~vbc1I~
        }                                                          //~vbc1I~
        else                                                       //~vbc1I~
        {                                                          //~vbc1I~
        	*Ppdirstep=1;                                          //~vbc1I~
        	*Ppdirstepr=-1;                                        //~vbc1I~
        }                                                          //~vbc1I~
        return 0;                                                  //~vbc1I~
    }                                                              //~vbc1I~
    if (toupper(*pcs)=='D')                                        //~vbc1I~
    {                                                              //~vbc1I~
        if (!(Ppdh->UDHattr & FILE_DIRECTORY))                     //~vbc1I~
        	return 4;                                              //~vbc1I~
        if (Ppdh->UDHtype==UDHTPARENT)                             //~vbc1I~
        	return 4;                                              //~vbc1I~
        if (Psubcmdid==SUBCMD_PREV)                                //~vbc1I~
        {                                                          //~vbc1I~
            if (offset<Pnameoffs-2)                                //~vbc1I~
                return 4;                                          //~vbc1I~
        }                                                          //~vbc1I~
        else                                                       //~vbc1I~
        {                                                          //~vbc1I~
            if (offset>=Pnameoffs-1)                               //~vbc1I~
                return 4;                                          //~vbc1I~
        }                                                          //~vbc1I~
        *Ppoffset=Pnameoffs-2;                                     //~vbc1R~
        if (Psubcmdid==SUBCMD_PREV)                                //~vbc1I~
        {                                                          //~vbc1I~
        	*Ppdirstep=-1;                                         //~vbc1I~
        	*Ppdirstepr=1;                                         //~vbc1I~
        }                                                          //~vbc1I~
        else                                                       //~vbc1I~
        {                                                          //~vbc1I~
        	*Ppdirstep=1;                                          //~vbc1I~
        	*Ppdirstepr=-1;                                        //~vbc1I~
        }                                                          //~vbc1I~
        return 0;                                                  //~vbc1I~
    }                                                              //~vbc1I~
    boundary1=(int)offsetof(UDIRLD,UDDattrflag)+Pexpandlen;        //~vbc1R~
    boundary2=boundary1+UDDATTRSZ;                                 //~vbc1I~
    if (Psubcmdid==SUBCMD_PREV)                                    //~vbc1I~
    {                                                              //~vbc1I~
    	if (offset<boundary1)                                      //~vbc1I~
        	return 4;                                              //~vbc1I~
    }                                                              //~vbc1I~
    else                                                           //~vbc1I~
    {                                                              //~vbc1I~
    	if (offset>=boundary2)                                     //~vbc1I~
        	return 4;                                              //~vbc1I~
    }                                                              //~vbc1I~
	pct=&(Ppdd->UDDattrflag)+Pexpandlen;                           //~vbc1R~
    if (*pct)       //attr was overrided by filename               //~vbc1I~
    {                                                              //~vbc1I~
    	return 4;	//not found                                    //~vbc1I~
    }                                                              //~vbc1I~
    pct++;                                                         //~vbc1R~
    for (ii=0,pcs=Psrch,len=(int)strlen(Psrch);ii<len;ii++,pcs++)  //~vbc1R~
    {                                                              //~vbc1I~
                                                                   //~vbc1I~
#ifdef UNX                                                         //~vbc1I~
    	if (!strstr(pct,pcs) //found if contains all               //~vbc1R~
        &&  !ustrstri(pct,pcs))                                    //~vbc1R~
        {                                                          //~vbc1I~
        	rc=4;                                                  //~vbc1I~
        	break;                                                 //~vbc1I~
        }                                                          //~vbc1I~
        else                                                       //~vbc1I~
            break;  //rc=0                                         //~vbc1I~
#else                                                              //~vbc1I~
    	if (!strchr(pct,*pcs)) //found if contains all             //~vbc1I~
        {                                                          //~vbc1I~
    		if (!strchr(pct,toupper(*pcs))) //found if contains all//~vbc1I~
            {                                                      //~vbc1I~
        		rc=4;                                              //~vbc1R~
        		break;                                             //~vbc1R~
            }                                                      //~vbc1I~
        }                                                          //~vbc1I~
#endif                                                             //~vbc1I~
    }                                                              //~vbc1I~
    if (!rc)                                                       //~vbc1I~
    {                                                              //~vbc1I~
        *Ppoffset=boundary1;                                       //~vbc1I~
        step=boundary2-boundary1;                                  //~vbc1I~
        if (Psubcmdid==SUBCMD_PREV)                                //~vbc1I~
        {                                                          //~vbc1I~
        	*Ppdirstep=-1;                                         //~vbc1R~
        	*Ppdirstepr=step;                                      //~vbc1R~
        }                                                          //~vbc1I~
        else                                                       //~vbc1I~
        {                                                          //~vbc1I~
        	*Ppdirstep=step;                                       //~vbc1R~
        	*Ppdirstepr=-1;                                        //~vbc1R~
        }                                                          //~vbc1I~
    }                                                              //~vbc1I~
    UTRACEP("%s:subcmd=%d,uddattr=%s,srch=%s,rc=%d,offset=%d->%d,step=%d,stepr=%d\n",UTT,Psubcmdid,pct,Psrch,rc,offset,*Ppoffset,*Ppdirstep,*Ppdirstepr);//~vbc1R~//~vbc2R~
    return rc;                                                     //~vbc1I~
}//fcmdfind_dirattr                                                //~vbc1I~
//**************************************************************** //~vbc2I~
//dir list timestamp matching                                      //~vbc2I~
//**************************************************************** //~vbc2I~
int fcmdfind_dirts(int Popt,int Psubcmdid,PUCLIENTWE Ppcw,PUDIRLH Ppdh,PUDIRLD Ppdd,int Pexpandlen,char *Psrch,int *Ppoffset,int *Ppdirstep,int *Ppdirstepr)//~vbc2I~
{                                                                  //~vbc2I~
	int rc=0,offset,boundary1,boundary2;                           //~vbc2R~
    char *pct,*pc;                                                 //~vbc2R~
//****************************                                     //~vbc2I~
	offset=*Ppoffset;                                              //~vbc2I~
    boundary1=(int)offsetof(UDIRLD,UDDdate)+Pexpandlen;            //~vbc2R~
    boundary2=(int)offsetof(UDIRLD,UDDsize)+Pexpandlen;            //~vbc2R~
    if (Psubcmdid==SUBCMD_PREV)                                    //~vbc2I~
    {                                                              //~vbc2I~
    	if (offset<boundary1)                                      //~vbc2I~
        	return 4;                                              //~vbc2I~
    }                                                              //~vbc2I~
    else                                                           //~vbc2I~
    {                                                              //~vbc2I~
    	if (offset>=boundary2)                                     //~vbc2I~
        	return 4;                                              //~vbc2I~
    }                                                              //~vbc2I~
	pct=Ppdd->UDDdate+Pexpandlen-1;                                //~vbc2R~
    if (*pct)       //attr was overrided by filename               //~vbc2I~
    {                                                              //~vbc2I~
    	return 4;	//not found                                    //~vbc2I~
    }                                                              //~vbc2I~
    pct++;                                                         //~vbc2R~
    pc=umemstr(pct,Psrch,(UINT)(boundary2-boundary1));             //~vbc2R~
    if (!pc)                                                       //~vbc2I~
    	return 4;	//not found                                    //~vbc2I~
                                                                   //~vbc2I~
    *Ppoffset=PTRDIFF(pc,Ppdd);                                    //~vbc2R~
    if (Psubcmdid==SUBCMD_PREV)                                    //~vbc2R~
    {                                                              //~vbc2R~
        *Ppdirstep=boundary1-*Ppoffset;                            //~vbc2R~
        *Ppdirstepr=boundary2-*Ppoffset;                           //~vbc2R~
    }                                                              //~vbc2R~
    else                                                           //~vbc2R~
    {                                                              //~vbc2R~
        *Ppdirstep=boundary2-*Ppoffset;                            //~vbc2R~
        *Ppdirstepr=boundary1-*Ppoffset;                           //~vbc2R~
    }                                                              //~vbc2R~
    UTRACEP("%s:subcmd=%d,udddate=%s,srch=%s,rc=%d,offset=%d->%d,step=%d,stepr=%d\n",UTT,Psubcmdid,pct,Psrch,rc,offset,*Ppoffset,*Ppdirstep,*Ppdirstepr);//~vbc2R~
    return rc;                                                     //~vbc2I~
}//fcmdfind_dirattr                                                //~vbc2I~
