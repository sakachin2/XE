//*CID://+vb31R~:                                    update#=  111;//~vb31R~
//*************************************************************
//*xefcmd23.c
//*  find sub                                                      //~v635R~
//****************************************************************
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vb2I:160308 (BUG)xeutfcvdd2lc parm err at fcmdsetupddsrch        //~vb2fI~
//vb2F:160229 W32 64 compiler warning                              //~vb2FR~
//vaw4:140528 (Win:UNICODE)escsrch by 3byte unicode                //~vaw4I~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vavw:140428 (BUG)find cmd fail on filename list for srch not ascii(ddsrch required)//~vavwI~
//vauF:140316 (Win)find on dirlist by ddstrsrch(LNX:vaui)          //~vauFI~
//vauk:140313 (BUG)for find word,codetbl recreate at int error(ut8 info lose for beyond first 8 byte)//~vaukI~
//vaui:140311 find on dirlist by ddstrsrch                         //~vauiI~
//vau6:140303 (BUG)Find cmd utf8 result msg "Not found";err msg utf8 corrupted//~vau6I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va7x:100825 (BUG)abend when find *ec for ebc file.               //~va7xI~
//va7r:100822 (BUG)b2m err at ini read for ebc search word;register ct for errmsg by utf8 code//~va7rI~
//va7q:100822 avoid errmsg "no EBCDIC data" when filed word translation err(search by errrep str)//~va7qI~
//va7h:100819 (BUG)splitsrch; fail when srch aaab for 2line of aaa-ab(chk 2nd line for b... only,should retry prevline aa-)//~va7hI~
//va7f:100819 (BUG) c aa "";--> errmsg "no EBCDIC data"            //~va7fI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va6j:000622 (BUG)Find *EC faile on EBCD file                     //~va6jI~
//va5x:100518 dbcstbl is not valid for f2l trans err(errmsg code tble position is not valid)//~va5xI~
//va5w:100517 panutil:keep utf8 codetype over session              //~va5wI~
//va5m:100510 (BUG)srchword is not strz(call searchon cmdbuff)     //~va5mI~
//va5k:100510 (BUG)errmsg display "?" when sbcs utf8               //~va5kI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3E:100313 (BUG)search on utf8 file(ddstr) fail near the line top//~va3EI~
//va3C:100310 (BUG)esc search fail for both size of word on the line//~va3CI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            fcmd23.c:search on dd str                            //~va20I~
//v78r:080326 profile function                                     //~v78rI~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v75x:070429 BND:set rc=0 for already that status                 //~v75xI~
//v74W:070407 split cmd bnds/margin support                        //~v74WI~
//v74N:070328 keep bnds parm for also filename                     //~v74EI~
//v74E:070315 BOUNDS cmd support                                   //~v74EI~
//v635:050428 move fcmdgetstartplhoffs from xefcmd2.c xefcmd23.c   //~v635I~
//v43g:011030 save each find word len for multiple word search case//~v43gI~
//            (spanded or *& case)                                 //~v43gI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//*******************************************************
#include <ulib.h>
#include <ualloc.h>
#include <uque.h>
#include <uerr.h>
#include <uparse.h>
#include <ustring.h>
#include <ufile.h>
#include <uedit.h>                                                 //~v74EI~
#include <uftp.h>                                                  //~v74ER~
#include <u3270.h>                                                 //~v74EI~
#ifdef UTF8UCS2                                                    //~va20I~
#include <udbcschk.h>                                              //~va20I~
#include <utf.h>                                                   //~va20R~
#include <utf22.h>                                                 //~va20I~
#include <utrace.h>                                                //~va20I~
#endif                                                             //~va20I~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc.h>                                                //~va50I~
#include <ucvebc4.h>                                               //~va79I~
#include <udbcschk.h>                                              //~vaukI~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile6.h"
#include "xefcmd2.h"
#include "xefcmd23.h"
#include "xeundo.h"
#include "xedir.h"                                                 //~v635I~
#include "xeerr.h"                                                 //~v74EI~
#include "xepan.h"                                                 //~v76mI~
#include "xepan22.h"                                               //~v76mI~
#include "xefcmd6.h"                                               //~v78rI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xefcmd2.h"                                               //~va20I~
#include "xefcmd22.h"                                              //~va20I~
#include "xeutf.h"                                                 //~va20I~
#include "xeutf2.h"                                                //~va20I~
#include "xesub2.h"                                                //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
//**************************************************
static  UQUEH Sbndstqh;	//bndstbl q-hdr for each filename extension//~v74EI~
//**************************************************               //~v74EI~
int fcmdtabcmp(char *Pdata,char *Psrch,int Psrchlen,char *Pdbcs);
int fcmdbndstgetcol(int Popt,char *Pfnm,int *Ppcol1,int *Ppcol2);  //~v74EI~
#define FCBNDGC_PATH       0x01 //parent chk                       //~v74EI~
//**************************************************
//!search on binary file
//*parm1:plh
//*parm2:search start offs
//*parm3:search word
//*parm4:search word len
//*parm5:search word containe tab sw
//*parm6:dest id(prev/next)
//*parm7:case sensitive sw
//*parm8:output match pos
//*parm9:optional output last plh
//*parm10:optional output word end addr
//*ret  :0:unmatch,1:match in the line,2:match by concatinated,UALLOC FAILED
//**************************************************
int fcmdsplitsrch(PULINEH Pplh,int Poffs,char *Psrch,int Psrchlen,
                    int Ptabsrchsw,int Pdirection,int Pcasesw,UCHAR **Ppos,//~v13pR~
					PULINEH *Pwordplh,UCHAR **Pwordend)            //~v13pR~
{
	PULINEH plh;
    char *pc=NULL,*pcl,*pc0,*pce,*srch1=NULL,*pcd,*pcd0,*wordtop=NULL,*wordend=NULL;//~vaf9R~
    char chru,chrl;
    int  srchlen1,reslen,linelen,complen,rc;
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile,opticmp=0;                                         //~va50R~//~vaf9R~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PLH_ISEBC(Pplh);                                     //~va50I~
    handle=UGETPFH(Pplh)->UFHhandle;                               //~va79I~
    if (swebcfile)                                                 //~va50I~
    {                                                              //~va50I~
    	Ptabsrchsw=0;                                              //~va50I~
        opticmp=UCVEBCO_NODBCS|UCVEBCO_NOCASE;                     //~va50R~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (!(pcd0=Pplh->ULHdbcs))
    {
    	if (filechktabdbcs(Pplh)==UALLOC_FAILED)//expand before compare
        	return UALLOC_FAILED;
		pcd0=Pplh->ULHdbcs;
	}
	pc0=Pplh->ULHdata;
    linelen=Pplh->ULHlen;
    srchlen1=Psrchlen-1;

	if (Pdirection==SUBCMD_PREV)
	    chru=*(Psrch+srchlen1);
    else
	    chru=*Psrch;
	if (Pcasesw)
    	chrl=0;				//no 2nd srch
    else
    {
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (swebcfile)                                               //~va50I~
      {                                                            //~va50I~
//  	chrl=(char)EBC_tolower(chru);                              //~va50I~//~va79R~
    	chrl=(char)UCVEBCH_tolower(handle,chru);                   //~va79I~
//  	chru=(char)EBC_toupper(chru);                              //~va50I~//~va79R~
    	chru=(char)UCVEBCH_toupper(handle,chru);                   //~va79I~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
      {                                                            //~va50I~
    	chrl=(char)tolower(chru);                                  //~v13pR~
    	chru=(char)toupper(chru);                                  //~v13pR~
      }                                                            //~va50I~
    	if (chru==chrl)
            chrl=0;         //id of no 2nd srch
	}
	if (Pdirection==SUBCMD_PREV)
    {
//****************
//* prev srch    *
//****************
        if (Poffs>linelen)
	        reslen=linelen;
        else
	        reslen=Poffs;
		if (!reslen)
        	return 0;
      for (;;)  //retry when failed to chk nextline                //~va7hI~
      {                                                            //~va7hI~
    	srchlen1=Psrchlen-1;                                       //~va7hI~
	    while(reslen)
    	{
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	if (chru==TABCHAR && !swebcfile)                       //~va50I~
#else                                                              //~va50I~
        	if (chru==TABCHAR)
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            {
//*search on pcd                                                   //~va50I~
                pc=umemrchr(pcd0,TABCHAR,(UINT)reslen); //srch by last char//~v13pR~
                if (pc)
//                	pc=pc0+((ULONG)pc-(ULONG)pcd0);                //~vafkR~
                	pc=pc0+((ULPTR)pc-(ULPTR)pcd0);                //~vafkI~
			}
            else
            {
//*raw utf8/ebc code for bin mode                                  //~va50I~
                pc=umemrchr(pc0,chru,(UINT)reslen); //srch by last char//~v13pR~
                if (chrl)
                {
//*raw utf8/ebc code for bin mode                                  //~va50I~
                    pcl=umemrchr(pc0,chrl,(UINT)reslen);           //~v13pR~
                    if (pcl>pc)
                    	pc=pcl;
                }
			}
            if (!pc)
                return 0;
            if (Psrchlen==1)
            {
                *Ppos=pc;
                return 1;
            }
            wordend=pc+1;
            srch1=Psrch+srchlen1;
//          reslen=(int)((ULONG)pc-(ULONG)pc0);                    //~v13pR~//~vafkR~
            reslen=(int)((ULPTR)pc-(ULPTR)pc0);                    //~vafkI~
            if (srchlen1<=reslen)
            	complen=srchlen1;
            else
            	complen=reslen;
            if (!complen)       //last byte matched to line top
                break;          //chk prev line
            srch1-=complen;
            pc-=complen;
            if (Ptabsrchsw)
//              rc=fcmdtabcmp(pc,srch1,complen,pcd0+((ULONG)pc-(ULONG)pc0));//~vafkR~
                rc=fcmdtabcmp(pc,srch1,complen,pcd0+((ULPTR)pc-(ULPTR)pc0));//~vafkI~
            else
//*for binfile                                                     //~va20I~
                if (Pcasesw)
                    rc=memcmp(pc,srch1,(UINT)complen);
                else
                {                                                  //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      			  if (swebcfile)                                   //~va50I~
//                  rc=ucvebc_memcmp(opticmp,pc,0/*dbcs1*/,srch1,0/*dbcs2*/,(UINT)complen);//~va50I~//~va79R~
//                  rc=ucvebc_memcmp(opticmp,handle,pc,0/*dbcs1*/,srch1,0/*dbcs2*/,(UINT)complen);//~va79I~//~vb30R~
                    rc=ucvebc_memcmp(opticmp,handle,pc,0/*dbcs1*/,srch1,0/*dbcs2*/,complen);//~vb30I~
                  else                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                    rc=memicmp(pc,srch1,(UINT)complen);
                }                                                  //~va50I~
            if (!rc)
            {
            	if (complen!=srchlen1)	//not fully compared
                {
                    srchlen1-=complen;
                	break;
                }
                *Ppos=pc;
                return 1;
			}
        }//until line end
//        concatsw=UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT2);//has prev
        plh=Pplh;
        rc=0;                                                      //~va7hI~
		while (srchlen1)
        {
            while(plh=UGETQPREV(plh),plh)
                if (plh->ULHtype==ULHTDATA)
                    break;
            if (!plh)
                return 0;
//            if (concatsw)
//                if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT1)) //not follower
//                    return 0;
    		if (!plh->ULHdbcs)
	            if (filechktabdbcs(plh)==UALLOC_FAILED)//expand before compare
    	            return UALLOC_FAILED;
            linelen=plh->ULHlen;
            if (srchlen1<linelen)
            	complen=srchlen1;
            else
            	complen=linelen;
            pc=plh->ULHdata+linelen-complen;
            srch1-=complen;
            srchlen1-=complen;
            if (Ptabsrchsw)
                rc=fcmdtabcmp(pc,srch1,complen,plh->ULHdbcs+linelen-complen);
            else
//*for binfile                                                     //~va20I~
                if (Pcasesw)
                    rc=memcmp(pc,srch1,(UINT)complen);
                else
                {                                                  //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      			  if (swebcfile)                                   //~va50I~
//                  rc=ucvebc_memcmp(opticmp,pc,0/*dbcs1*/,srch1,0/*dbcs2*/,(UINT)complen);//~va50I~//~va79R~
//                  rc=ucvebc_memcmp(opticmp,handle,pc,0/*dbcs1*/,srch1,0/*dbcs2*/,(UINT)complen);//~va79I~//~vb30R~
                    rc=ucvebc_memcmp(opticmp,handle,pc,0/*dbcs1*/,srch1,0/*dbcs2*/,complen);//~vb30I~
                  else                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                    rc=memicmp(pc,srch1,(UINT)complen);
                }                                                  //~va50I~
            if (rc)
//              return 0;       //unmatch                          //~va7hR~
                break;                                             //~va7hI~
        }
        if (!rc && !srchlen1)	//full match                       //~va7hI~
        	break;                                                 //~va7hI~
        if (!reslen)                                               //~va7hI~
        	return 0;                                              //~va7hI~
      }//for (;;)                                                  //~va7hI~
        wordtop=pc;         //return word top addr
	}//bwd
    else 	//forward search
	{
//****************
//* next srch    *
//****************
        if (Poffs>=linelen)
	        return 0;		//not found
        if (Poffs<0)
        	Poffs=0;
        pce=pc0+linelen;      //end addr
	    pcd0+=Poffs;
    	pc0+=Poffs;
      for (;;)  //retry when failed to chk nextline                //~va7hM~
      {                                                            //~va7hM~
        srch1=Psrch+1;
    	srchlen1=Psrchlen-1;                                       //~va7hI~
	    while(pc0<pce)
    	{
//          reslen=(int)((ULONG)pce-(ULONG)pc0);                   //~v13pR~//~vafkR~
	        reslen=(int)((ULPTR)pce-(ULPTR)pc0);                   //~vafkI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	if (chru==TABCHAR && !swebcfile)                       //~va50I~
#else                                                              //~va50I~
        	if (chru==TABCHAR)
#endif                                                             //~va50I~
            {
//*srch on pcd                                                     //~va50I~
                pcd=memchr(pcd0,TABCHAR,(UINT)reslen); //srch by last char//~v13pR~
            	if (!pcd)
                	return 0;
//              pc=pc0+((ULONG)pcd-(ULONG)pcd0);                   //~vafkR~
                pc=pc0+((ULPTR)pcd-(ULPTR)pcd0);                   //~vafkI~
			}
            else
            {
//*raw utf8/ebc code for bin mode                                  //~va50I~
            	pc=memchr(pc0,chru,(UINT)reslen);                  //~v13pR~
                if (chrl)
                {
//*raw utf8/ebc code for bin mode                                  //~va50I~
                    pcl=memchr(pc0,chrl,(UINT)reslen);             //~v13pR~
                    if (pcl && (!pc || pcl<pc))
                    	pc=pcl;
                }
	            if (!pc)
    	            return 0;
//              pcd=pcd0+((ULONG)pc-(ULONG)pc0);                   //~vafkR~
                pcd=pcd0+((ULPTR)pc-(ULPTR)pc0);                   //~vafkI~
            }
            if (Psrchlen==1)
            {
                *Ppos=pc;
                return 1;
            }
            wordtop=pc;
            pc0=pc+1;	//next srch start addr
            pcd0=pcd+1;	//next srch start addr
//          reslen=(int)((ULONG)pce-(ULONG)pc0);                   //~v13pR~//~vafkR~
            reslen=(int)((ULPTR)pce-(ULPTR)pc0);                   //~vafkI~
            if (srchlen1<=reslen)
            	complen=srchlen1;
            else
            	complen=reslen;
            if (!complen)
                break;          //chk next line
            if (Ptabsrchsw)
                rc=fcmdtabcmp(pc0,srch1,complen,pcd0);
            else
//*for binfile                                                     //~va20I~
                if (Pcasesw)
                    rc=memcmp(pc0,srch1,(UINT)complen);
                else
                {                                                  //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      			  if (swebcfile)                                   //~va50I~
//                  rc=ucvebc_memcmp(opticmp,pc0,0/*dbcs1*/,srch1,0/*dbcs2*/,(UINT)complen);//~va50I~//~va79R~
//                  rc=ucvebc_memcmp(opticmp,handle,pc0,0/*dbcs1*/,srch1,0/*dbcs2*/,(UINT)complen);//~va79I~//~vb30R~
                    rc=ucvebc_memcmp(opticmp,handle,pc0,0/*dbcs1*/,srch1,0/*dbcs2*/,complen);//~vb30I~
                  else                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                    rc=memicmp(pc0,srch1,(UINT)complen);
                }                                                  //~va50I~
            if (!rc)
            {
            	if (complen!=srchlen1)
                {
                    srchlen1-=complen;
                    srch1+=complen;
                	break;
                }
                *Ppos=pc;
                return 1;
            }
        }//until line end
//compare second half
//        concatsw=UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT1);//has next
        plh=Pplh;
		while (srchlen1)
        {
            while(plh=UGETQNEXT(plh),plh)
                if (plh->ULHtype==ULHTDATA)
                    break;
            if (!plh)
                return 0;
//            if (concatsw)
//                if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT2)) //not follower
//                    return 0;
    		if (!plh->ULHdbcs)
            	if (filechktabdbcs(plh)==UALLOC_FAILED)//expand before compare
                	return UALLOC_FAILED;
            linelen=plh->ULHlen;
            if (srchlen1<linelen)
            	complen=srchlen1;
            else
            	complen=linelen;
            pc=plh->ULHdata;
            if (Ptabsrchsw)
                rc=fcmdtabcmp(pc,srch1,complen,plh->ULHdbcs);
            else
//*for binfile                                                     //~va20I~
                if (Pcasesw)
                    rc=memcmp(pc,srch1,(UINT)complen);
                else
                {                                                  //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      			  if (swebcfile)                                   //~va50I~
//                  rc=ucvebc_memcmp(opticmp,pc,0/*dbcs1*/,srch1,0/*dbcs2*/,(UINT)complen);//~va50I~//~va79R~
//                  rc=ucvebc_memcmp(opticmp,handle,pc,0/*dbcs1*/,srch1,0/*dbcs2*/,(UINT)complen);//~va79I~//~vb30R~
                    rc=ucvebc_memcmp(opticmp,handle,pc,0/*dbcs1*/,srch1,0/*dbcs2*/,complen);//~vb30I~
                  else                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                    rc=memicmp(pc,srch1,(UINT)complen);
                }                                                  //~va50I~
            if (rc)
//          	return 0;                                          //~va7hR~
            	break;                                             //~va7hI~
            srchlen1-=complen;
            srch1+=complen;
            wordend=pc+complen;
        }//srchlen
		if (!srchlen1)	//all match                                //~va7hI~
        	break;                                                 //~va7hI~
        if (pc0>=pce)                                              //~va7hI~
          	return 0;   //unmatch                                  //~va7hI~
      }//for(;;)                                                   //~va7hI~
	}//fwd
    *Ppos=wordtop;
    if (Pwordplh)
	    *Pwordplh=plh;
    if (Pwordend)
	    *Pwordend=wordend;
    return 2;
}//fcmdsplitsrch                                                   //~v13pR~
//**************************************************
//!fcmdtabcmp
//* fromfcmdsplitsrch, bin file only                               //~va20I~
//*parm1:line data
//*parm2:srch string
//*parm3:compare len
//*parm4:line dbcs
//*ret  :rc 0 match,1:unmatch
//**************************************************
int fcmdtabcmp(char *Pdata,char *Pstring,int Psrchlen,char *Pdbcs)
{
    int    ii;
    UCHAR  ch2,*pc,*pc1,*pc2;
//*********************************
    for (pc1=Pdata,pc2=Pdbcs,pc=Pstring,ii=Psrchlen;ii;ii--,pc1++,pc2++,pc++)
    {
        ch2=*pc;
//*nevwe called for ebcfile,fcmdsplitsrch:Ptabsrchsw=Stabsrchsw is always off for ebcfile//~va50I~
        if (ch2==TABCHAR)
        {
            if (TABCHAR!=*pc2)
                return 1;		//unmatch
        }
        else
            if (ch2!=*pc1)
                return 1;		//unmatch
    }
    return 0;
}//fcmdtabcmp
//**************************************************
//!fcmdnextofspan
//*parm1:in/out current offset
//*parm2:in     advance step count
//*parm3:in/out current plh/wordend plh
//*ret  :rc 0 no plh updated,1:plh changed
//**************************************************
int fcmdnextofspan(int *Poffs,int Pstep,PULINEH *Ppplh)
{
	PULINEH plh;
    int     len,linelen,offs;
//*********************************
	plh=*Ppplh;
    offs=*Poffs;
	len=plh->ULHlen;
    if ((len-=offs)<=0)
    	return 0;
    if (len>=Pstep)	//in the first plh
    {
    	*Poffs=offs+Pstep;		//advance in the line
    	return 0;
	}
    linelen=0;		//for compiler warning                         //~v13pI~
    for (len=Pstep-len;len;len-=linelen)
    {
    	while (plh=UGETQNEXT(plh),plh)
        	if (plh->ULHtype==ULHTDATA)
            	break;
        if (!plh)
        	return 0;
		linelen=plh->ULHlen;
        if (len<=linelen)
        	break;
    }
    *Ppplh=plh;
    *Poffs=len;
    return 1;
}//fcmdnextofspan
//**************************************************               //~v13pI~
//!fcmdsplitdispaly                                                //~v13pI~
//*parm1:pfh                                                       //~v43gR~
//*parm2:plh of 1st line                                           //~v43gI~
//*parm3:plh of spaned last line                                   //~v43gR~
//*parm4:word offset                                               //~v43gR~
//*parm5:word len                                                  //~v43gR~
//*parm6:locatesw                                                  //~v43gR~
//*ret  :0                                                         //~v43gR~
//**************************************************               //~v13pI~
int fcmdsplitdisplay(PUFILEH Ppfh,PULINEH Pplh,PULINEH Plastplh,int Poffs,int Plen,int Plocatesw)//~v43gR~
{                                                                  //~v13pI~
	PULINEH plh;                                                   //~v13pI~
    int     reslen,spanlen,linelen,minlen;                         //~v43gR~
//*********************************                                //~v13pI~
	reslen=Pplh->ULHlen-Poffs;	//len on the 1st line              //~v13pI~
	spanlen=Plen-reslen;	//spaned len                           //~v13pI~
//  Pplh->ULHrevlen=(USHORT)reslen;                                //~v43gR~
    fcmdsetfindhighlight(Ppfh,Pplh,Plocatesw,0, //no linesrch      //~v43gI~
			Poffs,reslen,0);    //recursive with no spanplh        //~v43gI~
    linelen=0;                                                     //~v13pI~
    for (plh=Pplh;plh=UGETQNEXT(plh),plh;spanlen-=linelen)         //~v13pR~
    {                                                              //~v13pI~
		linelen=plh->ULHlen;                                       //~v13pI~
        if (spanlen<0)                                             //~v13pI~
        	spanlen=0;                                             //~v13pR~
//  	plh->ULHrevlen=(USHORT)min(spanlen,linelen);               //~v43gR~
//  	UCBITOFF(plh->ULHflag2,ULHF2MFOUND);//reset multiple       //~v43gR~
//  	plh->ULHrevctr=Pfindctr;//find cmd ctr for disply current; //~v43gR~
//  	UCBITON(plh->ULHflag,ULHFDRAW|ULHFCURFOUND);//draw word after wordrep//~v43gR~
//  	UCBITOFF(plh->ULHflag,ULHFCURCAP);//reset hilight reason cap//~v43gR~
    	minlen=min(spanlen,linelen);                               //~v43gI~
    	fcmdsetfindhighlight(Ppfh,plh,0,0, //no locate,no linesrch //~v43gR~
							0,minlen,0);    //offs=0,recursive with no spanplh//~v43gR~
        if (plh==Plastplh)                                         //~v13pI~
        	break;                                                 //~v13pI~
    }                                                              //~v13pI~
    return 0;                                                      //~v43gR~
}//fcmdsplitdisplay                                                //~v13pR~
//**************************************************
//!fcmdsplitrep
//* cut spaned area by wordrep(rep word is set to 1st line)
//*parm1:plh of 1st line
//*parm2:len on the following line
//*ret  :rc 4:err or UALLOC_FAILED
//**************************************************
int fcmdsplitrep(PUCLIENTWE Ppcw,PULINEH Pplh,int Pspanlen)
{
	PULINEH plh;
    int     len,linelen,spanlen;
    char   *pc,*pcd;
//*********************************
	len=0;                                                         //~v13pI~
    for (spanlen=Pspanlen,plh=Pplh;spanlen;spanlen-=len)
    {
    	while (plh=UGETQNEXT(plh),plh)
        	if (plh->ULHtype==ULHTDATA)
            	break;
        if (!plh)
        	return 4;
		linelen=plh->ULHlen;
        if (spanlen<=linelen)
        	len=spanlen;
        else
        	len=linelen;
        if (!len)
            continue;
    	if (undoupdate(Ppcw,plh,UUHTREP)==UALLOC_FAILED)
    		return UALLOC_FAILED;
        pc=plh->ULHdata;
        pcd=plh->ULHdbcs;                                          //~v13pR~
        linelen-=len;
        memcpy(pc, pc +len,(UINT)linelen);//left shift
        memcpy(pcd,pcd+len,(UINT)linelen);//left shift
        plh->ULHlen=linelen;                                       //~v13pR~
    }
    return 0;
}//fcmdsplitrep
//****************************************************************//~4C30I~
//!get start offset from current csr pos                        //~4C30I~
//* parm1 :pcw                                                  //~4C30I~
//* parm2 :output plh addr search start                         //~4C30I~
//* parm3 :output record pos search strat                       //~4C30I~
//* parm4 :0:line search sw                                        //~v47iR~
//* rc    :0:csr is  on client area, 4:csr is out of client area   //~v47iI~
//         1:cout of client area but line is on client area        //~v09eI~
//****************************************************************//~4C30I~
int fcmdgetstartplhoffs(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Popt)//~v47iR~
{                                                               //~4C30I~
	int offset,rc;                                              //~4C30I~
	PULINEH plh;                                                //~4C30I~
	PUFILEC pfc;                                                //~4C30I~
//*****************                                             //~4C30I~
    if (Gpanfindopt & PANFO_FNL)                                   //~v76mI~
        return panfnlgetstartplhoffs(Ppcw,Ppplh,Ppoffset,Popt);    //~v76mI~
	rc=4;                                                       //~4C30I~
	offset=0;                                                   //~4C30I~
	pfc=Ppcw->UCWpfc;                                           //~4C30I~
//  if (Ppcw->UCWrcsry<FILEHDRLINENO)                              //~v11NR~
    if (Ppcw->UCWrcsry<Ppcw->UCWfilehdrlineno)                     //~v11NI~
    {                                                              //~v09eI~
		plh=pfc->UFCcurtop;                                     //~4C30I~
//      if (Sulsrchsw)                                             //~v47iR~
        if (Popt)                                                  //~v47iI~
//      	offset=1;		//before client area                   //~v41rR~
        	offset=OFFS_TOP;		//before client area           //~v41rI~
	}                                                              //~v09eI~
	else                                                        //~4C30I~
		if (plh=(Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc,plh)    //~4C30I~
		{                                                       //~4C30I~
	        if (Ppcw->UCWtype==UCWTDIR)     //on dir list       //~v05wI~
            {                                                   //~v05wI~
				if (Ppcw->UCWrcsrx>=UDHLINENOSZ)                //~v05wI~
				{                                               //~v05wI~
					rc=0;                                       //~v05wI~
					offset=Ppcw->UCWrcsrx-UDHLINENOSZ;          //~v05wI~
				}                                               //~v05wI~
			}                                                   //~v05wI~
            else                                                //~v05wI~
			if (Ppcw->UCWrcsrx>=Ppcw->UCWlinenosz)              //~v069R~
			{                                                   //~4C30I~
				rc=0;                                           //~4C30I~
				offset=pfc->UFCleft+Ppcw->UCWrcsrx-Ppcw->UCWlinenosz;//~v069R~
			}                                                   //~4C30I~
            else                                                //~4C30I~
            {                                                      //~v09eI~
				offset=pfc->UFCleft;                            //~4C30I~
                rc=1;		//on lineno fld                        //~v09eI~
			}                                                      //~v09eI~
//          if (Sulsrchsw)                                         //~v47iR~
//		    if (Popt)                                              //~v62dR~
  		    if (Popt && Popt!=LINE_SAMEMATCH)	//column is meaning for matching//~v62dR~
            	offset=0;		//on client area                   //~v09eI~
		}                                                       //~4C30I~
		else	//out of end of file                            //~4C30I~
		{                                                       //~4C30I~
			plh=UGETQPREV(UGETQEND(&pfc->UFCpfh->UFHlineque));  //~4C30I~
			offset=plh->ULHlen;                                 //~4C30I~
//          if (Sulsrchsw)                                         //~v47iR~
  		    if (Popt)                                              //~v47iI~
//          	offset=2;		//after client area                //~v41rR~
            	offset=OFFS_LAST;		//after client area        //~v41rI~
		}                                                       //~4C30I~
	*Ppplh=plh;                                                 //~4C30I~
	*Ppoffset=offset;                                           //~4C30I~
	return rc;                                                  //~4C30I~
}//fcmdgetstartplhoffs                                             //~v47iR~
//**************************************************************** //~v74EI~
//get top entry                                                    //~v74EI~
//**************************************************************** //~v74EI~
int fcmdbndstgettop(PBNDSTBL *Ppbndst)                             //~v74EI~
{                                                                  //~v74EI~
	int ctr;                                                       //~v74EI~
//**********************	                                       //~v74EI~
//  ctr=UGETQCTR(&Sbndstqh);                                       //~v74EI~//~vb31R~
    ctr=(int)UGETQCTR(&Sbndstqh);                                  //~vb31I~
    if (Ppbndst)                                                   //~v74EI~
		*Ppbndst=UGETQTOP(&Sbndstqh);                              //~v74EI~
    return ctr;                                                    //~v74EI~
}//fcmdbndstgettop                                                 //~v74EI~
//**************************************************************** //~v74EI~
//serach bndstbl                                                   //~v74EI~
//extname:optional output extname ptr                              //~v74EI~
//**************************************************************** //~v74EI~
PBNDSTBL fcmdbndstsrch(int Popt,char *Pfnm,char **Ppextname)       //~v74ER~
{                                                                  //~v74EI~
	char *pc;                                                      //~v74EI~
    PBNDSTBL pbt;                                                  //~v74EI~
    char fpath[_MAX_PATH];                                         //~v74EI~
    int pathlen;                                                   //~v74EI~
#ifdef FTPSUPP                                                     //~v74EI~
    PUFTPHOST  puftph=0;                                           //~v74EI~
    UCHAR  lastname[DSN_MAXLEN];                                   //~v74EI~
#endif                                                             //~v74EI~
//*****************                                                //~v74EI~
    if (Ppextname)                                                 //~v74EI~
    	*Ppextname=0;                                              //~v74EI~
  if (Popt & FCBND_PATH) //parent chk                              //~v74ER~
  {                                                                //~v74EI~
#ifdef FTPSUPP                                                     //~v74EI~
   if (uftpisremote(Pfnm,&puftph)                                  //~v74ER~
   &&  UFTPHISTSO(puftph))                                         //~v74EI~
   {                                                               //~v74EI~
    u3270parsedsn(U3PL_DROPWILDORMEMBER,Pfnm,fpath,lastname);		//membername//~v74ER~
//  pathlen=strlen(fpath);                                         //~vafcI~//~vb30R~
    pathlen=(int)strlen(fpath);                                    //~vb30I~
   }                                                               //~v74EI~
   else                                                            //~v74EI~
#endif                                                             //~v74EI~
   {                                                               //~v74EI~
  	pathlen=PATHLEN(Pfnm);                                         //~v74EI~
    if (pathlen<0)                                                 //~v74EI~
    	return 0;                                                  //~v74EI~
    memcpy(fpath,Pfnm,(UINT)pathlen);	//with last DISR_SEPC      //~v74EI~
    *(fpath+pathlen)=0;                                            //~v74ER~
    if (!ROOTDIR(fpath))                                           //~v74EI~
	    *(fpath+pathlen-1)=0;                                      //~v74EI~
   }//!TSO                                                         //~v74EI~
  	pc=fpath;                                                      //~v74ER~
    if (Ppextname)                                                 //~v74EI~
    	*Ppextname=Pfnm+pathlen;                                   //~v74EI~
  }                                                                //~v74EI~
  else                                                             //~v74EI~
//if (Popt & FCBND_DIR) //dir itself                               //~v74NR~
  if (Popt & (FCBND_DIR|FCBND_FILE)) //dir/file itself             //~v74NI~
  {                                                                //~v74EI~
  	pc=Pfnm;                                                       //~v74EI~
    if (Ppextname)                                                 //~v74EI~
    	*Ppextname=Pfnm;                                           //~v74EI~
  }                                                                //~v74EI~
  else                                                             //~v74EI~
  {                                                                //~v74EI~
	pc=strrchr(Pfnm,'.');                                          //~v74ER~
    if (Popt & FCBND_ADD && !pc)                                   //~v74ER~
    	pc=Pfnm;                                                   //~v74EI~
    else                                                           //~v74EI~
    {                                                              //~v74EI~
        if (!pc)                                                   //~v74ER~
            return 0;                                              //~v74ER~
        pc++;                                                      //~v74ER~
        if (!*pc)                                                  //~v74ER~
            return 0;                                              //~v74ER~
    }                                                              //~v74EI~
    if (Ppextname)                                                 //~v74EI~
    	*Ppextname=pc;                                             //~v74EI~
  }                                                                //~v74EM~
	for (pbt=UGETQTOP(&Sbndstqh);pbt;pbt=UGETQNEXT(pbt))           //~v74ER~
    {                                                              //~v74EI~
#ifdef UNX                                                         //~v74EI~
    	if (!strcmp(pc,pbt->BNDSTextname))                         //~v74EI~
#else                                                              //~v74EI~
    	if (!stricmp(pc,pbt->BNDSTextname))                        //~v74ER~
#endif                                                             //~v74EI~
        {                                                          //~v74EI~
//        if ((pbt->BNDSTflag & BNDSTF_DIR))                       //~v74NR~
          if ((pbt->BNDSTflag & (BNDSTF_DIR|BNDSTF_FILE)))         //~v74NI~
          {                                                        //~v74EI~
//  	      if (Popt & (FCBND_DIR|FCBND_PATH))                   //~v74NR~
    	      if (Popt & (FCBND_DIR|FCBND_PATH|FCBND_FILE))        //~v74NI~
	        	return pbt;                                        //~v74ER~
          }                                                        //~v74EI~
          else                                                     //~v74EI~
//  	      if (!(Popt & (FCBND_DIR|FCBND_PATH)))                //~v74NR~
    	      if (!(Popt & (FCBND_DIR|FCBND_PATH|FCBND_FILE)))     //~v74NI~
	        	return pbt;                                        //~v74EI~
        }                                                          //~v74EI~
    }                                                              //~v74EI~
    return 0;                                                      //~v74EI~
}//fcmdbndstsrch                                                   //~v74EI~
//**************************************************************** //~v74EI~
//free   bndstbl                                                   //~v74EI~
//extname:optional output extname ptr                              //~v74EI~
//**************************************************************** //~v74EI~
void fcmdbndstfree()                                               //~v74EI~
{                                                                  //~v74EI~
    PBNDSTBL pbt;                                                  //~v74EI~
//*****************                                                //~v74EI~
	for (;pbt=UDEQ(UQUE_TOP,&Sbndstqh,0),pbt;)                     //~v74ER~
    {                                                              //~v74EI~
    	ufree(pbt->BNDSTextname);                                  //~v74EI~
        ufree(pbt);                                                //~v74EI~
    }                                                              //~v74EI~
    return;                                                        //~v74EI~
}//fcmdbndstfree                                                   //~v74EI~
//**************************************************************** //~v74EI~
//update bndstbl                                                   //~v74EI~
//col1:start from 1;0 mean no limit                                //~v74EI~
//rc:4:filename extension err,1:duplicated add,not found for del req//~v74EI~
//**************************************************************** //~v74EI~
int fcmdbndstupdate(int Popt,char *Pfnm,int Pcol1,int Pcol2)       //~v74EI~
{                                                                  //~v74EI~
	char *pext;                                                    //~v74EI~
    PBNDSTBL pbt;                                                  //~v74EI~
    int flag=0;                                                    //~v74ER~
    ULONG opt;                                                     //~v78rR~
//*****************                                                //~v74EI~
    if (Popt & FCBND_EXT)                                          //~v78rI~
    	opt=FPURO_EXT;                                             //~v78rR~
    else                                                           //~v78rI~
    	opt=0;                                                     //~v78rI~
    if (Popt & FCBND_DEL)   	//write profile record             //~v78rI~
		return fcmdprofupdaterecord(FPURO_BNDS|opt,Pfnm,0/*strval*/,-1,-1);//~v78rR~
    else                                                           //~v78rI~
    if (Popt & FCBND_UPD)   	//write profile record             //~v78rI~
		return fcmdprofupdaterecord(FPURO_BNDS|opt,Pfnm,0/*strval*/,Pcol1,Pcol2);//~v78rR~
                                                                   //~v78rI~
    if (Popt & FCBND_ADD)   	//called from ini2                 //~v74EI~
    	if (*Pfnm!='.')         //not ext definition               //~v74EI~
            Popt|=FCBND_DIR;                                       //~v74ER~
    if (Popt & FCBND_DIR)                                          //~v74EI~
      if (Popt & FCBND_ADD)   	//called from ini2                 //~v74NR~
        flag=BNDSTF_DIR|BNDSTF_FILE; //file or dir is unknown      //~v74NR~
      else                                                         //~v74NR~
	    flag=BNDSTF_DIR;                                           //~v74EI~
    else                                                           //~v74NR~
    if (Popt & FCBND_FILE)	//filename                             //~v74NR~
        flag=BNDSTF_FILE;                                          //~v74NR~
    pbt=fcmdbndstsrch(Popt,Pfnm,&pext);                            //~v74ER~
    if (!pext)   //etx err                                         //~v74EI~
    	return 4;                                                  //~v74EI~
    if (pbt && (pbt->BNDSTflag & flag)==flag)    //found           //~v74ER~
    {                                                              //~v74EI~
    	if (Popt & FCBND_ADD)                                      //~v74ER~
	    	return 1;                                              //~v74EI~
    	if (Popt & FCBND_DEL)                                      //~v74ER~
        {                                                          //~v74EI~
        	pbt->BNDSTcol1=BNDST_NOLIMIT;                          //~v74EI~
        	pbt->BNDSTcol2=BNDST_NOLIMIT;                          //~v74EI~
            return 0;                                              //~v74EI~
        }                                                          //~v74EI~
    }                                                              //~v74EI~
    else                                                           //~v74EI~
    {                                                              //~v74EI~
    	if (Popt & FCBND_DEL)                                      //~v74ER~
	    	return 1;                                              //~v74EI~
        pbt=umalloc(BNDSTSZ);                                      //~v74EI~
        memset(pbt,0,BNDSTSZ);                                     //~v74EI~
//    if (Popt & FCBND_DIR)                                        //~v74NR~
      if (Popt & (FCBND_DIR|FCBND_FILE))                           //~v74NI~
      {                                                            //~v74EI~
        pbt->BNDSTextname=umalloc(strlen(Pfnm)+1);                 //~v74ER~
        strcpy(pbt->BNDSTextname,Pfnm);                            //~v74ER~
      }                                                            //~v74EI~
      else                                                         //~v74EI~
      {                                                            //~v74EI~
        pbt->BNDSTextname=umalloc(strlen(pext)+1);                 //~v74ER~
        strcpy(pbt->BNDSTextname,pext);                            //~v74EI~
      }                                                            //~v74EI~
        pbt->BNDSTflag=flag;                                       //~v74EI~
        UENQ(UQUE_END,&Sbndstqh,pbt);                              //~v74EI~
    }                                                              //~v74EI~
    pbt->BNDSTcol1=Pcol1;                                          //~v74EI~
    pbt->BNDSTcol2=Pcol2;                                          //~v74EI~
    return 0;                                                      //~v74EI~
}//fcmdbndstupdate                                                 //~v74EI~
//**************************************************************** //~v74EI~
//add to bndstbl                                                   //~v74EI~
//col1:start from 1;0 mean no limit                                //~v74EI~
//rc:4 not defined                                                 //~v74EI~
//**************************************************************** //~v74EI~
int fcmdbndstgetcol(int Popt,char *Pfnm,int *Ppcol1,int *Ppcol2)   //~v74ER~
{                                                                  //~v74EI~
	char *pext;                                                    //~v74EI~
    PBNDSTBL pbt;                                                  //~v74EI~
//*****************                                                //~v74EI~
  if (!(Popt & FCBNDGC_PATH)                                       //~v74NI~
  ||  !(pbt=fcmdbndstsrch(FCBND_FILE,Pfnm,0)))	//at first search by filename//~v74NR~
  {                                                                //~v74NI~
    pbt=fcmdbndstsrch(0,Pfnm,&pext);                               //~v74ER~
    if (!pbt)    //not found                                       //~v74ER~
    {                                                              //~v74EI~
     if (Popt & FCBNDGC_PATH)                                      //~v74ER~
      pbt=fcmdbndstsrch(FCBND_PATH,Pfnm,&pext);//chk path defined  //~v74EI~
     else                                                          //~v74EI~
      pbt=fcmdbndstsrch(FCBND_DIR,Pfnm,&pext);//chk dirname itself //~v74ER~
      if (!pbt)                                                    //~v74EI~
    	return 4;                                                  //~v74EI~
    }                                                              //~v74EI~
  }                                                                //~v74NI~
    *Ppcol1=pbt->BNDSTcol1;                                        //~v74EI~
    *Ppcol2=pbt->BNDSTcol2;                                        //~v74EI~
    return 0;                                                      //~v74EI~
}//fcmdbndstgetcol                                                 //~v74EI~
//**************************************************************** //~v74EI~
//set bounds to pfh                                                //~v74EI~
//**************************************************************** //~v74EI~
int fcmdbndsset(PUFILEH Ppfh)                                      //~v74EI~
{                                                                  //~v74EI~
    int col1=0,col2=0,margin,opt;                                      //~v74ER~//~vaf9R~
//*****************                                                //~v74EI~
  	if (UCBITCHK(Ppfh->UFHprofile,FPURO_BNDS))   //set from profile record//~v78rR~
  	{                                                              //~v78rI~
		col1=Ppfh->UFHbndscol1;                                    //~v78rI~
		col2=Ppfh->UFHbndscol2;                                    //~v78rI~
    }                                                              //~v78rI~
    Ppfh->UFHbndscol1=0;                                           //~v74EI~
    Ppfh->UFHbndscol2=0;                                           //~v74EI~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))   //binary mode         //~v74EI~
    	return 4;                                                  //~v74EI~
  if (!UCBITCHK(Ppfh->UFHprofile,FPURO_BNDS))   //set from profile record//~v78rI~
  {                                                                //~v78rI~
    if (Ppfh->UFHtype==UFHTDIR)   //dir type pfh                   //~v74ER~
        opt=0;                                                     //~v74EI~
    else                                                           //~v74EI~
        opt=FCBNDGC_PATH;          //chk parent path               //~v74ER~
	if (fcmdbndstgetcol(opt,Ppfh->UFHfilename,&col1,&col2))        //~v74ER~
    	return 4;                                                  //~v74EI~
  }                                                                //~v78rI~
    margin=Ppfh->UFHmergin;                                        //~v74EI~
    if (!margin || col1<margin)                                    //~v74ER~
	    Ppfh->UFHbndscol1=col1;                                    //~v74ER~
    if (!margin || col2<margin)                                    //~v74ER~
	    Ppfh->UFHbndscol2=col2;                                    //~v74ER~
    return 0;                                                      //~v74EI~
}//fcmdbndsset                                                     //~v74ER~
//**************************************************************** //~v74EI~
// func_bnds                                                       //~v74EI~
//*rc   :0                                                         //~v74EI~
//**************************************************************** //~v74EI~
int func_bnds(PUCLIENTWE Ppcw)                                     //~v74EI~
{                                                                  //~v74EI~
    PUFILEC pfc;                                                   //~v74EI~
    PUFILEH pfh;                                                   //~v74EI~
    int ii,opdno,rc,len,col1=0,col2=0,extsw=0,margin;              //~v74ER~
    int delsw=0;                                                   //~v78rI~
    char *pc;                                                      //~v74EI~
#define SAME_EXTENSION_ID      "EXT"	//temporary set to extension tbl//~v74EI~
#define BNDS_RESET             "RESET"  //reset bnds,path,etx option may become effective//~v78rI~
//*********************************                                //~v74EI~
	pfc=Ppcw->UCWpfc;                                              //~v74EI~
	pfh=pfc->UFCpfh;                                               //~v74EI~
    opdno=Ppcw->UCWopdno;                                          //~v74EI~
    pc=Ppcw->UCWopdpot;                                            //~v74EM~
	if (opdno && *pc=='?')                                         //~v74ER~
    {                                                              //~v74EI~
//      uerrmsg("BND [* | 0 | col1] [* | 0 | col2] [%s]",0,        //~v78rR~
        uerrmsg("BND [ [* | 0 | col1] [* | 0 | col2] | %s ] [%s]",0,//~v78rI~
        		BNDS_RESET,                                        //~v78rI~
				SAME_EXTENSION_ID);                                //~v74EI~
        return 0;                                                  //~v74EI~
    }                                                              //~v74EI~
    if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))   //binary mode          //~v74EI~
    {                                                              //~v74EI~
        uerrmsg("command is for text file only",                   //~v74EI~
                "テキストファイルのみが対象です");                 //~v74EI~
        return 4;                                                  //~v74EI~
    }                                                              //~v74EI~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v74EI~
	{                                                              //~v74EI~
    	switch(ii)                                                 //~v74EI~
        {                                                          //~v74EI~
        case 0:		//first opd                                    //~v74EI~
            if (!stricmp(pc,BNDS_RESET))                           //~v78rR~
            	delsw=1;                                           //~v78rI~
            else                                                   //~v78rI~
            if (strcmp(pc,"*"))                                    //~v74EI~
            {                                                      //~v74EI~
            	len=(int)strlen(pc);                               //~v74ER~
                if (unumlen(pc,0,len)!=len)                        //~v74EI~
                	return errinvalid(pc);                         //~v74EI~
                col1=atoi(pc);                                     //~v74EI~
                if (col1<0)                                        //~v74ER~
                	return errinvalid(pc);                         //~v74EI~
            }                                                      //~v74EI~
            else                                                   //~v74EI~
                col1=pfh->UFHbndscol1;                             //~v74EI~
            break;                                                 //~v74EI~
        case 1:		//2nd opd                                      //~v74EI~
            if (!stricmp(pc,SAME_EXTENSION_ID))                    //~v78rI~
            	extsw=1;                                           //~v78rI~
            else                                                   //~v78rI~
            if (strcmp(pc,"*"))                                    //~v74EI~
            {                                                      //~v74EI~
            	len=(int)strlen(pc);                               //~v74ER~
                if (unumlen(pc,0,len)!=len)                        //~v74EI~
                	return errinvalid(pc);                         //~v74EI~
                col2=atoi(pc);                                     //~v74EI~
                if (col2<0)                                        //~v74ER~
                	return errinvalid(pc);                         //~v74EI~
            }                                                      //~v74EI~
            else                                                   //~v74EI~
                col2=pfh->UFHbndscol2;                             //~v74EI~
            break;                                                 //~v74EI~
        case 2:		//2nd opd                                      //~v74EI~
            if (!stricmp(pc,SAME_EXTENSION_ID))                    //~v74ER~
            	extsw=1;                                           //~v74ER~
            else                                                   //~v74EI~
                return errinvalid(pc);                             //~v74EI~
            break;                                                 //~v74EI~
        default:                                                   //~v74EI~
        	return errtoomany();                                   //~v74EI~
        }                                                          //~v74EI~
	}//loop by operand no                                          //~v74EI~
    if (col2 && col2<col1)                                         //~v74ER~
    {                                                              //~v74EI~
	    uerrmsg("column specication err(%d>=%d)",                  //~v74ER~
    			"カラム指定エラー(%d>=%d)",                        //~v74ER~
							col1,col2);                            //~v74EI~
        return 4;                                                  //~v74EI~
    }                                                              //~v74EI~
    if (extsw)                                                     //~v74EI~
    {                                                              //~v74EI~
      if (delsw)                                                   //~v78rI~
		rc=fcmdbndstupdate(FCBND_DEL|FCBND_EXT,pfh->UFHfilename,0,0);//~v78rR~
      else                                                         //~v78rI~
		rc=fcmdbndstupdate(FCBND_UPD|FCBND_EXT,pfh->UFHfilename,col1,col2);//~v78rR~
//  	if (rc)                                                    //~v78rR~
    	if (rc==1)                                                 //~v78rI~
        {                                                          //~v74EI~
	        uerrmsg("This filename has no extenstion name",        //~v74ER~
    	        		"このファイルは拡張子がありません");       //~v74ER~
            return 4;                                              //~v74EI~
        }                                                          //~v74EI~
//      uerrmsg("Default boundary for ext=%s is temporary set,use INI file for permanent setting.(Use INI cmd to output current status)",//~v78rR~
//              "拡張子=%sに対して一時的に境界を設定、恒久的にはINIファイルを使用のこと(現状況はINIコマンドで出力されます)",//~v78rR~
//              strrchr(pfh->UFHfilename,'.'));                    //~v78rR~
        if (delsw)                                                 //~v78rI~
        	uerrmsg("Default boundary for ext=%s is reset",        //~v78rI~
            	    "拡張子=%sの境界設定をリセット",               //~v78rI~
                	strrchr(pfh->UFHfilename,'.'));                //~v78rI~
        else                                                       //~v78rI~
        	uerrmsg("Default boundary for ext=%s is %d-%d",        //~v78rI~
            	    "拡張子=%sに対して境界を設定(%d-%d)",          //~v78rI~
                	strrchr(pfh->UFHfilename,'.'),col1,col2);      //~v78rI~
    }                                                              //~v74EI~
    else                                                           //~v74EI~
    if (pfh->UFHtype==UFHTDIR)   //dir type pfh                    //~v74EM~
    {                                                              //~v74EI~
      if (delsw)                                                   //~v78rI~
		rc=fcmdbndstupdate(FCBND_DEL|FCBND_DIR,pfh->UFHfilename,0,0);//~v78rI~
      else                                                         //~v78rI~
		rc=fcmdbndstupdate(FCBND_UPD|FCBND_DIR,pfh->UFHfilename,col1,col2);//~v74EI~
        if (!rc)                                                   //~v74EI~
        {                                                          //~v78rI~
          if (delsw)                                               //~v78rI~
	        uerrmsg("set default to all member of this directory", //~v78rI~
	                "このディレクトリーの省略値はリセットされました");//~v78rI~
          else                                                     //~v78rI~
	        uerrmsg("set default to all member of this directory", //~v74EI~
	                "このディレクトリーの省略値となります");       //~v74ER~
        }                                                          //~v78rI~
    }                                                              //~v74EI~
    else                                                           //~v74NR~
      if (delsw)                                                   //~v78rI~
    	fcmdbndstupdate(FCBND_DEL|FCBND_FILE,pfh->UFHfilename,col1,col2);//~v78rI~
      else                                                         //~v78rI~
    	fcmdbndstupdate(FCBND_UPD|FCBND_FILE,pfh->UFHfilename,col1,col2);//~v74NR~
    margin=pfh->UFHmergin;                                         //~v74ER~
    if (margin && col1>margin)                                     //~v74ER~
    {                                                              //~v74EI~
        uerrmsg("%d inconsistent with file margin %d",             //~v74EI~
                "%d はファイルのマージン指定(%d)と矛盾します",     //~v74ER~
                col1,margin);                                      //~v74EI~
        return 4;                                                  //~v74EI~
    }                                                              //~v74EI~
    if (margin && col2>margin)                                     //~v74ER~
    {                                                              //~v74EI~
        uerrmsg("%d inconsistent with file margin %d",             //~v74EI~
                "%d はファイルのマージン指定(%d)と矛盾します",     //~v74ER~
                col2,margin);                                      //~v74EI~
        return 4;                                                  //~v74EI~
    }                                                              //~v74EI~
  if (pfh->UFHtype!=UFHTDIR)   //dir type pfh                      //~v74NI~
  {                                                                //~v74NI~
    if (!extsw)                                                    //~v74ER~
        if (pfh->UFHbndscol1==col1                                 //~v74EI~
        &&  pfh->UFHbndscol2==col2)                                //~v74EI~
        {                                                          //~v75xI~
//  	    return erralready();                                   //~v75xR~
          if (!delsw)                                              //~v78rI~
    	    erralready();                                          //~v75xI~
            return 0;                                              //~v75xI~
        }                                                          //~v75xI~
    pfh->UFHbndscol1=col1;                                         //~v74EI~
    pfh->UFHbndscol2=col2;                                         //~v74EI~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);  //full redraw                //~v74EI~
  }                                                                //~v74NI~
	return 0;                                                      //~v74EI~
}//func_bnds                                                       //~v74EI~
//**************************************************************** //~v74WI~
//get bnds                                                         //~v74WI~
//**************************************************************** //~v74WI~
int fcmdgetbnds(int Popt,PUFILEH Ppfh,int *Ppbndsoffs1,int *Ppbndsoffs2)//~v74WI~
{                                                                  //~v74WI~
    int bndsoffs1,bndsoffs2,rc=0;                                  //~v74WR~
//*****************                                                //~v74WI~
	bndsoffs1=Ppfh->UFHbndscol1-1;                                 //~v74WI~
	bndsoffs2=Ppfh->UFHbndscol2;                                   //~v74WI~
    if (bndsoffs1>=0 || bndsoffs2>0)                               //~v74WI~
    	rc=FCBGRC_BNDS;	//by bnds set                              //~v74WR~
    bndsoffs1=max(0,bndsoffs1);                                    //~v74WI~
    if (UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN))    //mergin file     //~v74WI~
    {                                                              //~v74WI~
    	if (!bndsoffs2 || bndsoffs2>Ppfh->UFHmergin)               //~v74WR~
        {                                                          //~v74WI~
        	rc=FCBGRC_MARGIN; //by bnds set                        //~v74WR~
        	bndsoffs2=Ppfh->UFHmergin;                             //~v74WR~
        }                                                          //~v74WI~
    }                                                              //~v74WI~
    if (Ppbndsoffs1)                                               //~v74WI~
	    *Ppbndsoffs1=bndsoffs1;                                    //~v74WR~
    if (Ppbndsoffs2)                                               //~v74WI~
   	 	*Ppbndsoffs2=bndsoffs2;                                    //~v74WR~
    return rc;                                                     //~v74WI~
}//fcmdgetbnds                                                     //~v74WI~
#ifdef UTF8UCS2                                                    //~va20I~
//**************************************************               //~va20M~
//!searchby esc char on DD fmt                                     //~va20M~
//*matched at char boundary even when escchar srch                 //~va20I~
//*Pdata:left end pos                                              //~va20M~
//*Poffset:right end pos                                           //~va20M~
//*ret  :found pos,0 if not found                                  //~va20M~
//**************************************************               //~va20M~
char *fcmdddstrsrch(int Popt,PULINEH Pplh,UCHAR *Psrchstr,UCHAR *Psrchdbcs,int Psrchstrlen,char *Pdata,int Poffset,int *Ppwordlen)//~va20R~
{                                                                  //~va20M~
//  char *pc,*pcd,*pc0,*pcd0,*pce,*srchstr,*srchstr0,*pcn=0,contsw,*pcdn;//~va20M~//~vaf9R~
    char *pc,*pcd,*pc0,*pcd0,*pce,*srchstr,*srchstr0,*pcn=0,contsw,*pcdn=NULL;//~vaf9I~
    char *srchdbcs,*srchdbcs0;                                     //~va20I~
    int swnocase,swddsrch;                                         //~va20R~
    int offs0,srchlen,ucs,dbcsid,wordlen=0;                        //~va20M~
#ifdef BBB     //limit to match at char boundary only              //~va20R~
    int swesc;                                                     //~va20I~
#endif                                                             //~va20I~
//*********************************                                //~va20M~
#ifdef BBB                                                         //~va20I~
    swesc=Popt & FCMDDDSSO_ESC;                                    //~va20R~
#endif                                                             //~va20I~
    swddsrch=Popt & FCMDDDSSO_DDSTR;                               //~va20R~
    swnocase=(Popt & FCMDDDSSO_NOCASE);//case insensitive          //~va20R~
    pc0=Pplh->ULHdata;                                             //~va20M~
    pcd0=Pplh->ULHdbcs;                                            //~va20M~
    if (!pcd0)                                                     //~va20M~
    	return 0;	//for safety                                   //~va20M~
//  offs0=(int)((ULONG)Pdata-(ULONG)pc0);                          //~va20M~//~vafkR~
    offs0=(int)((ULPTR)Pdata-(ULPTR)pc0);                          //~vafkI~
	if (Popt & FCMDDDSSO_PREV)                                     //~va20R~
    {                                                              //~va20M~
	    srchstr0=srchstr=Psrchstr+Psrchstrlen-1;                   //~va20M~
	    srchdbcs0=srchdbcs=Psrchdbcs+Psrchstrlen-1;                //~va20I~
    	srchlen=Psrchstrlen;                                       //~va20M~
    	for (pce=Pdata,pc=Pdata+Poffset-1,pcd=pcd0+offs0+Poffset-1;//~va20M~
//  			pc-srchlen>=pce;                                   //~va20M~//~va3CR~
    			pc>=pce;                                           //~va3CI~
                pc--,pcd--                                         //~va20M~
			)                                                      //~va20M~
        {                                                          //~va20M~
        	dbcsid=*pcd;                                           //~va20M~
            contsw=0;                                              //~va20M~
    		if (UDBCSCHK_ISUCSSBCS(dbcsid))                        //~va20M~
            {                                                      //~va20M~
            	if (swddsrch)                                      //~va20I~
                {                                                  //~va20I~
                	if (dbcsid==*srchdbcs && *pc==*srchstr)        //~va20R~
                    {                                              //~va20I~
	                	srchstr--;                                 //~va20I~
	                	srchdbcs--;                                //~va20I~
    	                srchlen--;                                 //~va20I~
         	            contsw=1;                                  //~va20I~
                    }                                              //~va20I~
                }                                                  //~va20I~
                else                                               //~va20I~
                {                                                  //~va20I~
                    ucs=(int)UTF_GETUCSSBCS(pc,pcd);               //~va20R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
//*all is overflow for w32,but for unity                           //~vaw4R~
              	  if (ucs>>16)   //ucs4                            //~va3xI~
                  {                                                //~va3xI~
                    if ( ((ucs & 0xff)==*srchstr)                  //~va3xI~
                    &&   (srchlen>2 && ((ucs>>8)&0xff)==*(srchstr-1))//~va3xI~
                    &&   ( ((ucs>>16)&0xff)==*(srchstr-2))         //~va3xI~
                       )                                           //~va3xI~
                    {                                              //~va3xI~
                        srchstr-=3;                                //~va3xI~
                        srchlen-=3;                                //~va3xI~
                        contsw=3;                                  //~va3xI~
                    }                                              //~va3xI~
                  }                                                //~va3xI~
                  else                                             //~va3xI~
#endif                                                             //~va3xI~
                  {//ucs2                                          //~va3xI~
                    if ( ((ucs & 0xff)==*srchstr)                  //~va20R~
                    &&   (srchlen>1 && (ucs>>8)==*(srchstr-1))     //~va20R~
                       )                                           //~va20R~
                    {                                              //~va20R~
                        srchstr-=2;                                //~va20R~
                        srchlen-=2;                                //~va20R~
                        contsw=2;                                  //~va20R~
                    }                                              //~va20R~
                  }//ucs2                                          //~va3xI~
                }                                                  //~va20I~
            }                                                      //~va20M~
            else                                                   //~va20M~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
    		if (UDBCSCHK_ISUCSOVF2ND(dbcsid) && pc-1>=pce)         //~va3xR~
            {                                                      //~va3xI~
            	if (swddsrch)                                      //~va3xI~
                {                                                  //~va3xI~
                	if (dbcsid==*srchdbcs && *pc==*srchstr         //~va3xI~
                	&& (*(pcd-1)==*(srchdbcs-1) && *(pc-1)==*(srchstr-1))//~va3xR~
                    )                                              //~va3xI~
                    {                                              //~va3xI~
                        srchstr-=2;                                //~va3xI~
                        srchdbcs-=2;                               //~va3xI~
                        srchlen-=2;                                //~va3xI~
                        contsw=4;        //2 byte ucs4             //~va3xI~
                    }                                              //~va3xI~
                }                                                  //~va3xI~
                else                                               //~va3xI~
                {                                                  //~va3xI~
                    ucs=(int)UTF_GETUCSDBCSOVF((pc-1),(pcd-1));    //~va3xR~
                    if ( ((ucs & 0xff)==*srchstr)                  //~va3xR~
                    &&   (srchlen>2 && ((ucs>>8)&0xff)==*(srchstr-1))//~va3xR~
                    &&   ( ((ucs>>16)&0xff)==*(srchstr-2))         //~va3xR~
                       )                                           //~va3xR~
                    {                                              //~va3xR~
                        srchstr-=3;                                //~va3xR~
                        srchlen-=3;                                //~va3xR~
                        contsw=4; //2column ucs4 match             //~va3xR~
                    }                                              //~va3xR~
                }                                                  //~va3xI~
            }                                                      //~va3xI~
            else                                                   //~va3xI~
#endif                                                             //~va3xI~
            {                                                      //~va20M~
            	if ((*pc==*srchstr)                                //~va20M~
                ||  ( swnocase && !dbcsid && toupper(*pc)==toupper(*srchstr) )//~va20M~
                )                                                  //~va20M~
                {                                                  //~va20M~
                  if (!swddsrch || dbcsid==*srchdbcs)              //~va3xI~
                  {                                                //~va3xI~
                	if (wordlen	//2nd byte match                   //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
                    ||  !UDBCSCHK_DBCS1STU(dbcsid) //match should start by byte boundary//~va3xI~
#else                                                              //~va3xI~
                    ||  !UDBCSCHK_DBCS1STUCS2NWP(dbcsid) //match should start by byte boundary//~va20I~
#endif                                                             //~va3xI~
                    )                                              //~va20I~
                    {                                              //~va20I~
                        srchstr--;                                 //~va20R~
                        srchdbcs--;                                //~va20R~
                        srchlen--;                                 //~va20R~
                        contsw=1;                                  //~va20R~
                    }                                              //~va20I~
                  }//dbcs match                                    //~va3xI~
                }                                                  //~va20M~
            }                                                      //~va20M~
            if (contsw)                                            //~va20M~
            {                                                      //~va20M~
                if (!wordlen)	//1st match                        //~va20M~
                {                                                  //~va20M~
                    pcn=pc;  //next of restart point               //~va20M~
                    pcdn=pcd;                                      //~va20M~
                }                                                  //~va20M~
                wordlen++;                                         //~va20M~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
                if (contsw==4)	//UCS4 2 byte match                //~va3xI~
                {                                                  //~va3xI~
                	pc--,pcd--;                                    //~va3xI~
                    wordlen++;                                     //~va3xI~
                }                                                  //~va3xI~
#endif                                                             //~va3xI~
                if (!srchlen)   //full match                       //~va20I~
                {                                                  //~va20I~
#ifdef BBB                                                         //~va20I~
                    if (swesc)  //no char boundary consideration   //~va20I~
                        break;                                     //~va20I~
#endif                                                             //~va20I~
                    if (!UDBCSCHK_DBCS2NDUCS2NWP(dbcsid))//top byte match to dbcs2nd//~va20I~
//*break if OVF(2nd byte was compared)                             //~vaw4I~
                        break;                                     //~va20I~
                    contsw=0;   //split dbcs unmatch               //~va20I~
                }                                                  //~va20I~
                if (contsw)                                        //~va20I~
	                continue;                                      //~va20R~
            }                                                      //~va20M~
            if (!wordlen)                                          //~va20M~
                continue;                                          //~va20M~
            pc=pcn;                                                //~va20M~
            pcd=pcdn;                                              //~va20M~
            srchstr=srchstr0;                                      //~va20M~
            srchdbcs=srchdbcs0;                                    //~va20R~
            srchlen=Psrchstrlen;                                   //~va20M~
            wordlen=0;                                             //~va20M~
        }                                                          //~va20M~
	}                                                              //~va20M~
    else 	//forward search                                       //~va20M~
//********FWD**********************                                //~va3xI~
	{                                                              //~va20M~
	    srchstr=Psrchstr;                                          //~va20M~
	    srchdbcs=Psrchdbcs;                                        //~va20I~
    	srchlen=Psrchstrlen;                                       //~va20M~
    	for (pc=Pdata,pce=Pdata+Poffset,pcd=pcd0+offs0;            //~va20M~
//  			pc+srchlen<=pce;                                   //~va20M~//~va3CR~
    			pc<pce;                                            //~va3CI~
                pc++,pcd++                                         //~va20M~
			)                                                      //~va20M~
        {                                                          //~va20M~
        	dbcsid=*pcd;                                           //~va20M~
            contsw=0;                                              //~va20M~
    		if (UDBCSCHK_ISUCSSBCS(dbcsid))                        //~va20M~
            {                                                      //~va20M~
            	if (swddsrch)                                      //~va20I~
                {                                                  //~va20I~
                	if (dbcsid==*srchdbcs && *pc==*srchstr)        //~va20I~
                    {                                              //~va20I~
	                	srchstr++;                                 //~va20I~
	                	srchdbcs++;                                //~va20I~
    	                srchlen--;                                 //~va20I~
         	            contsw=1;                                  //~va20I~
                    }                                              //~va20I~
                }                                                  //~va20I~
                else                                               //~va20I~
                {                                                  //~va20I~
                    ucs=(int)UTF_GETUCSSBCS(pc,pcd);               //~va20R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
//*all is overflow for w32,but for unity                           //~vaw4I~
              	  if (ucs>>16)   //ucs4                            //~va3xI~
                  {                                                //~va3xI~
                    if ( ((ucs>>16)==*srchstr)                     //~va3xI~
                    &&   (srchlen>2 && ((ucs>>8) & 0xff)==*(srchstr+1))//~va3xI~
                    &&   (((ucs) & 0xff)==*(srchstr+2))            //~va3xI~
                       )                                           //~va3xI~
                    {                                              //~va3xI~
                        srchstr+=3;                                //~va3xI~
                        srchlen-=3;                                //~va3xI~
                        contsw=3;   //continue matching            //~va3xI~
                    }                                              //~va3xI~
                  }                                                //~va3xI~
                  else                                             //~va3xI~
#endif                                                             //~va3xI~
                  {//ucs2                                          //~va3xI~
                    if ( ((ucs>>8)==*srchstr)                      //~va20R~
                    &&   (srchlen>1 && (ucs & 0xff)==*(srchstr+1)) //~va20R~
                       )                                           //~va20R~
                    {                                              //~va20R~
                        srchstr+=2;                                //~va20R~
                        srchlen-=2;                                //~va20R~
                        contsw=2;   //continue matching            //~va20R~
                    }                                              //~va20R~
                  }//ucs2                                          //~va3xI~
                }                                                  //~va20I~
            }                                                      //~va20M~
            else                                                   //~va20M~
//#ifdef UTF8UCS4                                                    //~va3xM~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
    		if (UDBCSCHK_ISUCSOVF1ST(dbcsid) && pc+1<pce)          //~va3xR~
            {                                                      //~va3xM~
            	if (swddsrch)                                      //~va3xI~
                {                                                  //~va3xI~
                	if (dbcsid==*srchdbcs && *pc==*srchstr         //~va3xI~
                	&& (*(pcd+1)==*(srchdbcs+1) && *(pc+1)==*(srchstr+1))//~va3xR~
                    )                                              //~va3xI~
                    {                                              //~va3xI~
                        srchstr+=2;                                //~va3xI~
                        srchdbcs+=2;                               //~va3xI~
                        srchlen-=2;                                //~va3xI~
                        contsw=4;        //2 byte ucs4             //~va3xI~
                    }                                              //~va3xI~
                }                                                  //~va3xI~
                else                                               //~va3xI~
                {                                                  //~va3xI~
                    ucs=(int)UTF_GETUCSDBCSOVF(pc,pcd);            //~va3xR~
                    if ( ((ucs>>16)==*srchstr)                     //~va3xR~
                    &&   (srchlen>2 && ((ucs>>8) & 0xff)==*(srchstr+1))//~va3xR~
                    &&   (((ucs) & 0xff)==*(srchstr+2))            //~va3xR~
                       )                                           //~va3xR~
                    {                                              //~va3xR~
                        srchstr+=3;                                //~va3xR~
                        srchlen-=3;                                //~va3xR~
                        contsw=4;        //2 byte ucs4             //~va3xR~
                    }                                              //~va3xR~
                }                                                  //~va3xI~
            }                                                      //~va3xM~
            else                                                   //~va3xM~
#endif                                                             //~va3xM~
            {                                                      //~va20M~
            	if ((*pc==*srchstr)	                               //~va20M~
                ||  ( swnocase && !dbcsid && toupper(*pc)==toupper(*srchstr) )//~va20M~
                )                                                  //~va20M~
                {                                                  //~va20M~
                  if (!swddsrch || dbcsid==*srchdbcs)              //~va3xI~
                  {                                                //~va3xI~
                	if (wordlen	//2nd byte match                   //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
                    ||  !UDBCSCHK_DBCS2NDU(dbcsid) //match start by byte boundary//~va3xI~
#else                                                              //~va3xI~
                    ||  !UDBCSCHK_DBCS2NDUCS2NWP(dbcsid) //match start by byte boundary//~va20R~
#endif                                                             //~va3xI~
                    )                                              //~va20I~
                    {                                              //~va20I~
                        srchstr++;                                 //~va20R~
                        srchdbcs++;                                //~va20R~
                        srchlen--;                                 //~va20R~
                        contsw=1;   //continue matching            //~va20R~
                    }                                              //~va20I~
                  }//dbcs match                                    //~va3xI~
                }                                                  //~va20M~
            }                                                      //~va20M~
            if (contsw)                                            //~va20M~
            {                                                      //~va20M~
                if (!wordlen)	//1st match                        //~va20M~
                {                                                  //~va20M~
                    pcn=pc;  //prev of restart point               //~va20M~
                    pcdn=pcd;                                      //~va20M~
                }                                                  //~va20M~
                wordlen++;                                         //~va20I~
//#ifdef UTF8UCS4                                                    //~va1CI~//~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
                if (contsw==4)	//UCS4 2 byte match                //~va3xI~
                {                                                  //~va3xI~
                	pc++,pcd++;                                    //~va3xI~
                    wordlen++;                                     //~va3xI~
                }                                                  //~va3xI~
#endif                                                             //~va1CI~//~va3xI~
            	if (!srchlen)	//full match                       //~va20I~
	            {                                                  //~va20I~
#ifdef BBB                                                         //~va20I~
                	if (swesc)  //no char boundary consideration   //~va20I~
                    	break;                                     //~va20I~
#endif                                                             //~va20I~
//*no case of 1stovf                                               //~va3xI~
                	if (!UDBCSCHK_DBCS1STUCS2NWP(dbcsid))//last byte match to dbcs1st//~va20I~
//*break if OVF(2nd byte was compared)                             //~vaw4I~
                		break;                                     //~va20I~
                	contsw=0;	//split dbcs unmatch               //~va20I~
            	}                                                  //~va20I~
                if (contsw)                                        //~va20I~
                	continue;                                      //~va20R~
            }                                                      //~va20M~
            if (!wordlen)	//top byte unmatch,no need resey       //~va20R~
                continue;                                          //~va20M~
            pc=pcn;                                                //~va20M~
            pcd=pcdn;                                              //~va20M~
            srchstr=Psrchstr;                                      //~va20M~
            srchdbcs=Psrchdbcs;                                    //~va20I~
            srchlen=Psrchstrlen;                                   //~va20M~
            wordlen=0;                                             //~va20M~
        }                                                          //~va20M~
        pc=pcn; //match top pos                                    //~va20M~
	}	                                                           //~va20M~
    if (srchlen)                                                   //~va20M~
    	return 0;                                                  //~va20M~
    if (Ppwordlen)                                                 //~va20M~
    	*Ppwordlen=wordlen;	//highlight str width,not same as utf8strlen//~va20R~
    return pc;                                                     //~va20M~
}//*fcmdddstrsrch                                                  //~va20R~
//#ifdef AAA                                                         //~va20I~//~vaw1R~
////**************************************************               //~va20I~//~vaw1R~
////!esc replace                                                     //~va20I~//~vaw1R~
////**************************************************               //~va20I~//~vaw1R~
//int fcmdddescrep(int Popt,PULINEH Pplh,int Poffs,int Psrchlen,UCHAR *Prepword,int Prepwordlen,//~va20R~//~vaw1R~
//                UCHAR *Poutdd,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen)//~va20I~//~vaw1R~
//{                                                                  //~va20I~//~vaw1R~
//    char *pc,*pcd,*pc0,*pcd0,*pcd2,*pc2,*prw,*poutdd,*poutdbcs;    //~va20I~//~vaw1R~
//    int dbcsid,wordlen=0,rbddlen,ddlen,rc=0,ulhlen,reslenrw,reslensw,dellen,addlen;//~va20R~//~vaw1R~
//    UCHAR rbdd[2],rbdbcs[2];                                       //~va20I~//~vaw1R~
//    WUCS ucs;                                                      //~va20I~//~vaw1R~
////*********************************                                //~va20I~//~vaw1R~
//    ulhlen=Pplh->ULHlen;                                           //~va20I~//~vaw1R~
//    pc0=Pplh->ULHdata;                                             //~va20I~//~vaw1R~
//    pc=pc0+Poffs;                                                  //~va20I~//~vaw1R~
//    pc2=pc+Psrchlen;                                               //~va20R~//~vaw1R~
//    pcd0=Pplh->ULHdbcs;                                            //~va20I~//~vaw1R~
//    pcd=pcd0+Poffs;                                                //~va20I~//~vaw1R~
//    pcd2=pcd+Psrchlen;                                             //~va20R~//~vaw1R~
//    prw=Prepword;                                                  //~va20I~//~vaw1R~
//    poutdd=Poutdd;                                                 //~va20I~//~vaw1R~
//    poutdbcs=Poutdbcs;                                             //~va20R~//~vaw1R~
//    reslenrw=Prepwordlen;                                          //~va20I~//~vaw1R~
//    reslensw=Psrchlen;                                             //~va20I~//~vaw1R~
////left boundary                                                    //~va20I~//~vaw1R~
//    dbcsid=*pcd;                                                   //~va20I~//~vaw1R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
//    if (Poffs && UDBCSCHK_DBCS2NDU(dbcsid)) //split dbcs at right boundary//~va3xI~//~vaw1R~
//#else                                                              //~va3xI~//~vaw1R~
//    if (Poffs && UDBCSCHK_DBCS2NDUCS2NWP(dbcsid))   //split dbcs at right boundary//~va20I~//~vaw1R~
//#endif                                                             //~va3xI~//~vaw1R~
//    {                                                              //~va20I~//~vaw1R~
//        ucs=(*(pc-1)<<8)|*prw++;                                   //~va20I~//~vaw1R~
//        reslenrw--;                                                //~va20I~//~vaw1R~
//        reslensw--;                                                //~va20I~//~vaw1R~
//        pc++;                                                      //~va20I~//~vaw1R~
//        pcd++;                                                     //~va20I~//~vaw1R~
//        UTF_U2DD1(ucs,poutdd,poutdbcs,&ddlen);                     //~va20I~//~vaw1R~
//        poutdd+=ddlen;                                             //~va20I~//~vaw1R~
//        poutdbcs+=ddlen;                                           //~va20I~//~vaw1R~
//        rc|=FCERDDRC_LEFT;      //left boundary changed            //~va20I~//~vaw1R~
//    }                                                              //~va20I~//~vaw1R~
////right boundary                                                   //~va20I~//~vaw1R~
//    dbcsid=*(pcd2-1);                                              //~va20I~//~vaw1R~
//    if (Poffs+Psrchlen<ulhlen                                      //~va20I~//~vaw1R~
//#ifdef UTF8UCS4                                                    //~va3xR~//~vaw1R~
//    &&  UDBCSCHK_DBCS1STU(dbcsid)   //split dbcs at right boundary //~va3xI~//~vaw1R~
//#else                                                              //~va3xI~//~vaw1R~
//    &&  UDBCSCHK_DBCS1STUCS2NWP(dbcsid) //split dbcs at right boundary//~va20I~//~vaw1R~
//#endif                                                             //~va3xI~//~vaw1R~
//    &&  reslenrw                                                   //~va20I~//~vaw1R~
//    )                                                              //~va20I~//~vaw1R~
//    {                                                              //~va20I~//~vaw1R~
//        ucs=(*(prw+reslenrw-1)<<8)|*pc2;                           //~va20R~//~vaw1R~
//        reslenrw--;                                                //~va20I~//~vaw1R~
//        reslensw--;                                                //~va20I~//~vaw1R~
//        UTF_U2DD1(ucs,rbdd,rbdbcs,&rbddlen);                       //~va20I~//~vaw1R~
//        rc|=FCERDDRC_RIGHT;     //left boundary changed            //~va20I~//~vaw1R~
//    }                                                              //~va20I~//~vaw1R~
////middle                                                           //~va20I~//~vaw1R~
//    for (;reslensw>0 && reslenrw>0;                                //~va20I~//~vaw1R~
//        poutdd+=ddlen,poutdbcs+=ddlen,pc+=dellen,pcd+=dellen,reslensw-=dellen,reslenrw-=addlen,prw+=addlen//~va20R~//~vaw1R~
//    )                                                              //~va20I~//~vaw1R~
//    {                                                              //~va20I~//~vaw1R~
//        dbcsid=*pcd;                                               //~va20I~//~vaw1R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
//        if (UDBCSCHK_DBCS1STU(dbcsid))                             //~va3xI~//~vaw1R~
//#else                                                              //~va3xI~//~vaw1R~
//        if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid))                       //~va20I~//~vaw1R~
//#endif                                                             //~va3xI~//~vaw1R~
//        {                                                          //~va20I~//~vaw1R~
//            dellen=2;                                              //~va20I~//~vaw1R~
//            addlen=2;                                              //~va20I~//~vaw1R~
//        }                                                          //~va20I~//~vaw1R~
//        else                                                       //~va20I~//~vaw1R~
//        if (UDBCSCHK_ISUCSSBCS(dbcsid))                            //~va20I~//~vaw1R~
//        {                                                          //~va20I~//~vaw1R~
//            dellen=1;                                              //~va20I~//~vaw1R~
//            addlen=2;                                              //~va20I~//~vaw1R~
//        }                                                          //~va20I~//~vaw1R~
//        else                                                       //~va20I~//~vaw1R~
//            dellen=addlen=1;                                       //~va20I~//~vaw1R~
//        if (addlen==2)                                             //~va20I~//~vaw1R~
//        {                                                          //~va20I~//~vaw1R~
//            ucs=UTF_GETUCSDBCS(prw);                               //~va20I~//~vaw1R~
//            UTF_U2DD1(ucs,poutdd,poutdbcs,&ddlen);                 //~va20R~//~vaw1R~
//        }                                                          //~va20I~//~vaw1R~
//        else                                                       //~va20I~//~vaw1R~
//        {                                                          //~va20I~//~vaw1R~
//            *poutdd=*prw;                                          //~va20R~//~vaw1R~
//            if (UTF8ISASCII(*prw))                                 //~va20I~//~vaw1R~
//                *poutdbcs=0;                                       //~va20I~//~vaw1R~
//            else                                                   //~va20I~//~vaw1R~
//                *poutdbcs=UDBCSCHK_F2LERR;                         //~va20I~//~vaw1R~
//        }                                                          //~va20I~//~vaw1R~
//    }                                                              //~va20I~//~vaw1R~
//    if (reslenrw>0)  //expand                                      //~va20I~//~vaw1R~
//    {                                                              //~va20I~//~vaw1R~
//        for (;reslenrw>0;poutdd+=ddlen,poutdbcs+=ddlen,reslenrw-=2)//~va20R~//~vaw1R~
//        {                                                          //~va20I~//~vaw1R~
//            if (reslenrw>1)                                        //~va20I~//~vaw1R~
//            {                                                      //~va20I~//~vaw1R~
//                ucs=UTF_GETUCSDBCS(prw);                           //~va20I~//~vaw1R~
//                UTF_U2DD1(ucs,poutdd,poutdbcs,&ddlen);             //~va20R~//~vaw1R~
//            }                                                      //~va20I~//~vaw1R~
//            else                                                   //~va20I~//~vaw1R~
//            {                                                      //~va20I~//~vaw1R~
//                ddlen=1;                                           //~va20I~//~vaw1R~
//                *poutdd=*prw;                                      //~va20R~//~vaw1R~
//                if (UTF8ISASCII(*prw))                             //~va20I~//~vaw1R~
//                    *poutdbcs=0;                                   //~va20I~//~vaw1R~
//                else                                               //~va20I~//~vaw1R~
//                    *poutdbcs=UDBCSCHK_F2LERR;                     //~va20I~//~vaw1R~
//            }                                                      //~va20I~//~vaw1R~
//        }                                                          //~va20I~//~vaw1R~
//    }                                                              //~va20I~//~vaw1R~
//    if (rc & FCERDDRC_RIGHT)        //left boundary changed        //~va20I~//~vaw1R~
//    {                                                              //~va20I~//~vaw1R~
//        memcpy(poutdd,rbdd,(UINT)rbddlen);                         //~va20I~//~vaw1R~
//        memcpy(poutdbcs,rbdbcs,(UINT)rbddlen);                     //~va20I~//~vaw1R~
//        poutdd+=rbddlen;                                           //~va20I~//~vaw1R~
//    }                                                              //~va20I~//~vaw1R~
//    ddlen=(ULONG)poutdd-(ULONG)Poutdd;                             //~va20I~//~vaw1R~
//    *Ppoutlen=ddlen;                                               //~va20I~//~vaw1R~
//    return rc;                                                     //~va20I~//~vaw1R~
//}//*fcmdddescrep                                                   //~va20I~//~vaw1R~
//#endif //AAA                                                       //~va20I~//~vaw1R~
//**************************************************               //~va20I~
//!PLH ddstr compare                                               //~va20R~
//*Pdata:left end pos                                              //~va20I~
//*Poffset:right end pos                                           //~va20I~
//*ret  :0 match,4:unmatch                                         //~va20I~
//**************************************************               //~va20I~
int fcmdddstrcmp(int Popt,PULINEH Pplh1,int Ppos1,PULINEH Pplh2,int Ppos2,int Plen)//~va20I~
{                                                                  //~va20I~
    char *pc1,*pcd1,*pc2,*pcd2;                                    //~va20R~
    int len1,len2,rc,opt;                                          //~va20R~
//*********************************                                //~va20I~
    pc1=Pplh1->ULHdata;                                            //~va20I~
    pcd1=Pplh1->ULHdbcs;                                           //~va20I~
    len1=Pplh1->ULHlen-Ppos1;                                      //~va20I~
    pc2=Pplh2->ULHdata;                                            //~va20I~
    pcd2=Pplh2->ULHdbcs;                                           //~va20I~
    len2=Pplh2->ULHlen-Ppos2;                                      //~va20I~
    if (!pcd1                                                      //~va20I~
	||  !pcd2                                                      //~va20R~
    ||  len1<Plen                                                  //~va20I~
	||  len2<Plen)                                                 //~va20I~
    {                                                              //~va20I~
    	rc=4;                                                      //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    {                                                              //~va20I~
		opt=XESUBDDSCO_EQCHKONLY;                                  //~va20I~
	    if (Popt & FCMDDDSCO_NOCASE)                               //~va20R~
    		opt|=XESUBDDSCO_NOCASE;                                //~va20R~
    	rc=xesubddmemcmp(opt,pc1+Ppos1,pcd1+Ppos1,pc2+Ppos2,pcd2+Ppos2,Plen);//~va20R~
    }                                                              //~va20I~
    UTRACEP("fcmdddstrcmp rc=%d\n",rc);                            //~va20I~
    return rc;                                                     //~va20I~
}//*fcmdddstrcmp                                                   //~va20I~
//**************************************************               //~va20I~
//!get locale code/codetype tbl on Gcmdbuff                        //~va20I~
//*ret  :lclen                                                     //~va20I~
//**************************************************               //~va20I~
int fcmdsearchoncmdbuff(int Popt,UCHAR *Psrch,int Psrchlen,UCHAR **Pplc,UCHAR **Ppct,UCHAR **Ppdbcs)//~va20R~//~va5xR~
{                                                                  //~va20I~
    char *pc,*pct,*pct0,*pce;                                      //~va20R~
    char *pcd;                                                     //~va5kI~
    int offs,lclen,utf8chsz,lcchsz,ch,pos=0;                       //~va20R~
    ULONG ucs;                                                     //~va5xI~
//**************************************************               //~va20I~
//*search on Gcmdbuff                                              //~va20I~
UTRACED("fcmdsearchcmdbuff Gcmdbuff",Gcmdbuff,(int)strlen(Gcmdbuff));   //~va20R~//~vb30R~
UTRACED("fcmdsearchcmdbuff Gcmdbuffu8",Gcmdbuffu8,(int)strlen(Gcmdbuffu8));//~vafkI~//~vb30R~
UTRACED("fcmdsearchcmdbuff searchstr",Psrch,Psrchlen);             //~va20R~
//  pce=strstr(Gcmdbuffu8,Psrch);                                  //~va5mR~
//  lclen=strlen(Gcmdbuffu8);                                      //~va5mI~//~vb30R~
    lclen=(int)strlen(Gcmdbuffu8);                                 //~vb30I~
//  pce=umemmem(Gcmdbuffu8,Psrch,lclen,Psrchlen);                  //~va5mI~//~vb30R~
//  pce=umemmem(Gcmdbuffu8,Psrch,(size_t)lclen,(size_t)Psrchlen);  //~vb30I~//~vb31R~
    pce=umemmem(Gcmdbuffu8,Psrch,(unsigned)lclen,(unsigned)Psrchlen);//~vb31I~
    if (!pce)                                                      //~va20I~
    	return 0; //not found                                      //~va20I~
    pcd=Gcmdbuffdbcs;                                              //~va5kI~
//step on codetbl for srch string top                              //~va5xI~
    for (pc=Gcmdbuffu8,pct=Gcmdbuffct;pc<pce;pc+=utf8chsz,pct+=lcchsz)//~va20R~
    {                                                              //~va20I~
        if (*pct==XEUTFCT_UTF8)                                    //~va20I~
        {                                                          //~va20I~
	        ch=*pc;                                                //~va20I~
        	utf8chsz=UTF8CHARLEN(ch);                              //~va20R~
//          if (UDBCSCHK_DBCS1STLU(*pcd))                            //~va5kI~//~va5xR~
//            lcchsz=XESUB_DBCSSPLITCTR(Gcmdbuffdbcs,Gcmdbufflclen,pos);//~va20R~//~va5xR~
//          else                                                     //~va5kI~//~va5xR~
//            lcchsz=1;                                              //~va5kI~//~va5xR~
            if (!utf8chsz)                                         //~va20I~
            	return 0;	//logic err,unmatch                    //~va20R~
            utfgetwcw(0,pc,utf8chsz,&ucs,0/*chklen*/,&lcchsz);     //~va5xI~
        }                                                          //~va20I~
        else                                                       //~va20I~
        {                                                          //~va20I~
        	utf8chsz=1;                                            //~va20I~
        	lcchsz=1;                                              //~va20I~
        }                                                          //~va20I~
        pos+=lcchsz;                                               //~va20I~
        pcd+=lcchsz;                                               //~va5kI~
    }                                                              //~va20I~
//step on codetbl for srch string end                              //~va5xI~
//  offs=(int)((ULONG)pct-(ULONG)Gcmdbuffct);                      //~va20R~//~vafkR~
    offs=(int)((ULPTR)pct-(ULPTR)Gcmdbuffct);                      //~vafkI~
    pct0=pct;                                                      //~va20I~
    for (pce=pc+Psrchlen;pc<pce;pc+=utf8chsz,pct+=lcchsz)          //~va20R~
    {                                                              //~va20I~
        if (*pct==XEUTFCT_UTF8)                                    //~va20I~
        {                                                          //~va20I~
	        ch=*pc;                                                //~va20I~
        	utf8chsz=UTF8CHARLEN(ch);                              //~va20I~
//          if (UDBCSCHK_DBCS1STLU(*pcd))                            //~va5kI~//~va5xR~
//            lcchsz=XESUB_DBCSSPLITCTR(Gcmdbuffdbcs,Gcmdbufflclen,pos);//~va20R~//~va5xR~
//          else                                                     //~va5kI~//~va5xR~
//            lcchsz=1;                                              //~va5kI~//~va5xR~
            if (!utf8chsz)                                         //~va20I~
            	return 0;	//logic err,unmatch                    //~va20I~
            utfgetwcw(0,pc,utf8chsz,&ucs,0/*chklen*/,&lcchsz);     //~va5xI~
        }                                                          //~va20I~
        else                                                       //~va20I~
        {                                                          //~va20I~
        	utf8chsz=1;                                            //~va20I~
        	lcchsz=1;                                              //~va20I~
        }                                                          //~va20I~
        pos+=lcchsz;                                               //~va20I~
        pcd+=lcchsz;                                               //~va5kI~
    }                                                              //~va20I~
//  lclen=(int)((ULONG)pct-(ULONG)pct0);                           //~va20I~//~vafkR~
    lclen=(int)((ULPTR)pct-(ULPTR)pct0);                           //~vafkI~
UTRACEP("cmdbuff utf8str search last offs=%d,lclen=%d\n",offs,lclen);//~va20R~
UTRACED("cmdbuff utf8str search lc",Gcmdbufflc+offs,64);           //~vafkI~
UTRACED("cmdbuff utf8str search ct",Gcmdbuffct+offs,64);           //~vafkI~
UTRACED("cmdbuff utf8str search db",Gcmdbuffdbcs+offs,64);         //~vafkI~
    if (Pplc)                                                      //~va20I~
    	*Pplc=Gcmdbufflc+offs;                                     //~va20I~
    if (Ppct)                                                      //~va20I~
    	*Ppct=Gcmdbuffct+offs;                                     //~va20I~
    if (Ppdbcs)                                                    //~va20I~
    	*Ppdbcs=Gcmdbuffdbcs+offs;                                 //~va20I~
    return lclen;                                                  //~va20I~
}//*fcmdsearchoncmdbuff                                            //~va20R~
//**************************************************               //~va50I~
//save codetype for errmsg                                         //~va50I~
//rc:1:saved,0:not saved                                           //~va50I~
//**************************************************               //~va50I~
int fcmd_savelcctforerrmsg(int Popt,int Ptype,UCHAR *Psrch,int Psrchlen,UCHAR **Pppct,UCHAR **Pppcd,int Plenlc)//~va50R~
{                                                                  //~va50I~
    static UCHAR Ssvswmixed[3][MAXCOLUMN];                         //~va50R~
    static UCHAR Ssvswdbcs[3][MAXCOLUMN];                          //~va50I~
    static UCHAR Ssvswct[3][MAXCOLUMN];                            //~va50I~
    static int   Ssvswctlen[3];                                    //~va50I~
    UCHAR  wkct[32];  //(MAXCOLUMN+7)/8                            //~va50I~
    UCHAR  wkedit[MAXCOLUMN+4];                                    //~va50I~
	int idx,len,rc=0,swsetct;                                      //~va50R~
//  int ii,jj,ct,ctlen,byteoffs,bitoffs,ctbit;                     //~va5wR~
    int ctlen;                                                     //~va5wI~
//  UCHAR *pc,*pctw,*pct,*pcd;                                     //~va5wR~
    UCHAR *pc,*pct/*,*pcd*/;                                           //~va5wI~//~vaa7R~
//****************************                                     //~va50I~
    UTRACEP("fcmd_savelcctforerrmsg opt=%x,type=%x,srch=%s,len=%d\n",Popt,Ptype,Psrch,Psrchlen);//~vauiI~
    if (Ptype & SEARCH_CHANGE)                                     //~va50I~
        idx=2;                                                     //~va50I~
    else                                                           //~va50I~
    if (Ptype & SEARCH_AND)                                        //~va50I~
        idx=1;                                                     //~va50I~
    else                                                           //~va50I~
        idx=0;                                                     //~va50I~
	if (Popt & FCSCFEMO_SAVECT)                                    //~va50R~
    {                                                              //~va50I~
        len=min(Psrchlen,MAXCOLUMN-2);    	                       //~va50R~
        UmemcpyZ(Ssvswmixed[idx],Psrch,(UINT)len);                 //~va50R~
        UTRACED("fcmd_savelcctforerrmsg mixed",Ssvswmixed[idx],len);//~vaukM~
        len=min(Plenlc,MAXCOLUMN);                                 //~va50R~
        Ssvswctlen[idx]=len;                                       //~va50I~
        memcpy(Ssvswct[idx],*Pppct,(UINT)len);                     //~va50I~
        memcpy(Ssvswdbcs[idx],*Pppcd,(UINT)len);                   //~va50I~
        UTRACED("fcmd_savelcctforerrmsg ct",Ssvswct[idx],len);     //~vafkI~
        UTRACED("fcmd_savelcctforerrmsg dbcs",Ssvswdbcs[idx],len); //~vafkI~
    }                                                              //~va50I~
    else                                                           //~va50I~
	if (Popt & FCSCFEMO_GETCT)                                     //~va50R~
//*no user of GETCT,so dbcs is not used                            //~vaukI~
    {                                                              //~va50I~
        *Pppct=0;                                                  //~va50I~
        ctlen=Ssvswctlen[idx];                                     //~va50I~
        if (!strcmp(Psrch,Ssvswmixed[idx])                         //~va50R~
        &&  ctlen                                                  //~va50I~
		)                                                          //~va50I~
        {                                                          //~va50I~
        	*Pppct=Ssvswct[idx];                                   //~va50I~
            if (Pppcd)                                             //~va50I~
	        	*Pppcd=Ssvswdbcs[idx];                             //~va50R~
        }                                                          //~va50I~
        else                                                       //~va50I~
        	rc=4;                                                  //~va50I~
    }                                                              //~va50I~
    else                                                           //~va50I~
	if (Popt & FCSCFEMO_SETCTPREFIX)                               //~va50I~
    {                                                              //~va50I~
        ctlen=Ssvswctlen[idx];                                     //~va50I~
		if (strcmp(Psrch,Ssvswmixed[idx])                          //~va50R~
        ||  !ctlen                                                 //~va50I~
        )                                                          //~va50I~
        	rc=4;                                                  //~va50I~
        else                                                       //~va50I~
        {                                                          //~va50I~
			pct=Ssvswct[idx];                                      //~va50I~
//  		pcd=Ssvswdbcs[idx];                                    //~va50I~//~vaa7R~
			pc=Ssvswmixed[idx];                                    //~va50I~
//  		swsetct=xeerr_seterrmsgct(0,pc,strlen(pc),pct,0/*pcd,chk by getwcw,for the case trans err*/,ctlen,wkedit,MAXCOLUMN,&len);//~va5wR~//~vb30R~
    		swsetct=xeerr_seterrmsgct(0,pc,(int)strlen(pc),pct,0/*pcd,chk by getwcw,for the case trans err*/,ctlen,wkedit,MAXCOLUMN,&len);//~vb30I~
            if (swsetct)	//utf8 found                           //~va50I~
            {                                                      //~va50I~
            	len=min(MAXCOLUMN-2,len);                          //~va50R~
//          	UmemcpyZ(*Pppct,wkedit,len);                       //~va50R~//~vb30R~
            	UmemcpyZ(*Pppct,wkedit,(size_t)len);               //~vb30I~
	            UTRACED("SETPREFIX out ",wkedit,len);              //~va50R~
            }                                                      //~va50I~
            else                                                   //~va50I~
            	rc=5;	//no utf8 found                            //~va50I~
            UTRACED("SETPREFIX srch",Psrch,MAXCOLUMN);             //~va50I~
            UTRACED("SETPREFIX ct ",Ssvswct[idx],MAXCOLUMN);       //~va50R~
        }                                                          //~va50I~
    }                                                              //~va50I~
    else                                                           //~va50I~
	if (Popt & FCSCFEMO_CT2INI)                                    //~va50I~
    {                                                              //~va50I~
        ctlen=Ssvswctlen[idx];                                     //~va50I~
//  	if (Psrchlen+2+sizeof(wkct)>MAXCOLUMN                      //~va50R~//~vb30R~
    	if (Psrchlen+2+(int)sizeof(wkct)>MAXCOLUMN                 //~vb30I~
        ||  !ctlen                                                 //~va50I~
        ||  strcmp(Psrch,Ssvswmixed[idx])                          //~va50R~
        )                                                          //~va50I~
        	rc=4;                                                  //~va50I~
        else                                                       //~va50I~
        {                                                          //~va50I~
//            memset(wkct,0,sizeof(wkct));                         //~va5wR~
//            for (ii=0,pct=Ssvswct[idx];ii<ctlen;ii++)            //~va5wR~
//            {                                                    //~va5wR~
//                ct=*pct++;                                       //~va5wR~
//                if (ct==XEUTFCT_UTF8)                            //~va5wR~
//                {                                                //~va5wR~
//                    byteoffs=ii/8;                               //~va5wR~
//                    bitoffs=ii%8;                                //~va5wR~
//                    ctbit=(0x80>>bitoffs);                       //~va5wR~
//                    wkct[byteoffs]|=ctbit;                       //~va5wR~
//                }                                                //~va5wR~
//            }//for                                               //~va5wR~
			fcmd_bitcodetype(FCBCO_2BIT,Ssvswct[idx],wkct,ctlen,sizeof(wkct));//~va5wI~
            wkct[sizeof(wkct)-1]=FCSCFEMO_INICTID;  //ct concatinated id//~va50R~
    		if (Ptype & SEARCH_AND)                                //~va50I~
            	memcpy(Psrch+MAXCOLUMN-sizeof(wkct)-1,wkct,sizeof(wkct));//1 byte short for Ssrch2//~va50I~
            else                                                   //~va50R~
            	memcpy(Psrch+MAXCOLUMN-sizeof(wkct),wkct,sizeof(wkct));//~va50R~
            UTRACED("CT2INI ct ",Ssvswct[idx],MAXCOLUMN);          //~va50I~
            UTRACED("CT2INI pu8",Psrch,MAXCOLUMN);                 //~va50R~
            UTRACED("CT2INI wkct",wkct,sizeof(wkct));              //~vauiI~
        }                                                          //~va50I~
    }                                                              //~va50I~
    else                                                           //~va50I~
	if (Popt & FCSCFEMO_INI2CT)                                    //~va50I~
    {                                                              //~va50I~
//  	if (Psrchlen+2+sizeof(wkct)>MAXCOLUMN                      //~va50R~//~vb30R~
    	if (Psrchlen+2+(int)sizeof(wkct)>MAXCOLUMN                 //~vb30I~
        ||  (   *(Psrch+MAXCOLUMN-1)!=FCSCFEMO_INICTID  //ct concatinated id//~va50R~
             && *(Psrch+MAXCOLUMN-2)!=FCSCFEMO_INICTID  //ct concatinated id//~va50I~
            )                                                      //~va50I~
        )                                                          //~va50I~
        {                                                          //~va50I~
        	Ssvswctlen[idx]=0;                                     //~va50I~
        	rc=4;                                                  //~va50I~
        }                                                          //~va50I~
        else                                                       //~va50I~
        {                                                          //~va50I~
//      	UmemcpyZ(Ssvswmixed[idx],Psrch,Psrchlen);              //~va50I~//~vb30R~
        	UmemcpyZ(Ssvswmixed[idx],Psrch,(size_t)Psrchlen);      //~vb30I~
    		if (Ptype & SEARCH_AND)	//Ssrch2 top is 1 byte length  //~va50I~
            	memcpy(wkct,Psrch+MAXCOLUMN-1-sizeof(wkct),sizeof(wkct));//~va50I~
            else                                                   //~va50I~
            	memcpy(wkct,Psrch+MAXCOLUMN-sizeof(wkct),sizeof(wkct));//~va50R~
//            for (ii=0,pctw=wkct;ii<sizeof(wkct);ii++,pctw++)     //~va5wR~
//            {                                                    //~va5wR~
//                ct=*pctw++;                                      //~va5wR~
//                pct=Ssvswct[idx]+ii*8;                           //~va5wR~
//                for (jj=0;jj<8;jj++)                             //~va5wR~
//                {                                                //~va5wR~
//                    if (ct & (0x80>>jj))                         //~va5wR~
//                        *(pct+jj)=XEUTFCT_UTF8;                  //~va5wR~
//                }                                                //~va5wR~
//            }//for                                               //~va5wR~
			fcmd_bitcodetype(FCBCO_2CT,Ssvswct[idx],wkct,MAXCOLUMN,sizeof(wkct));//~va5wI~
            if (xeutf_setdbcstblbyct(0,Psrch,Psrchlen,Ssvswct[idx],Ssvswdbcs[idx],MAXCOLUMN,&ctlen)<4)//~va50R~
	            Ssvswctlen[idx]=ctlen;                             //~va50R~
            UTRACED("INI2CT wkct",wkct,sizeof(wkct));              //~vauiI~
            UTRACED("INI2CT mixed",Psrch,MAXCOLUMN);               //~va50R~
            UTRACED("INI2CT ct ",Ssvswct[idx],MAXCOLUMN);          //~va50I~
            UTRACED("INI2CT dbcs",Ssvswdbcs[idx],MAXCOLUMN);       //~va50I~
            UTRACEP("INI2CT ctlen=%d\n",ctlen);                    //~vauiI~
        }                                                          //~va50I~
    }                                                              //~va50I~
    return rc;                                                     //~va50I~
}//fcmd_savelcctforerrmsg                                          //~va50I~
//**************************************************               //~va5wI~
//!convert codetype tbl<-->bit areay                               //~va5wI~
//Pctlen codetype tbl len  when 2BIT, buffsz for 2CT               //~va5wI~
//*ret                                                             //~va5wI~
//**************************************************               //~va5wI~
int fcmd_bitcodetype(int Popt,char *Pcodetype,char *Pbitarray,int Pctlen,int Pbitarraysz)//~va5wI~
{                                                                  //~va5wI~
    int ii,jj,kk,ct,byteoffs,bitoffs,ctbit;                        //~va5wI~
    UCHAR *pctw,*pct;                                              //~va5wR~
//****************************                                     //~va5wI~
	if (Popt & FCBCO_2BIT)                                         //~va5wI~
    {                                                              //~va5wI~
    	memset(Pbitarray,0,(UINT)Pbitarraysz);                     //~va5wR~
        for (ii=0,pct=Pcodetype;ii<Pctlen;ii++)                    //~va5wI~
        {                                                          //~va5wI~
            ct=*pct++;                                             //~va5wI~
            if (ct==XEUTFCT_UTF8)                                  //~va5wI~
            {                                                      //~va5wI~
                byteoffs=ii/8;                                     //~va5wI~
                bitoffs=ii%8;                                      //~va5wI~
                ctbit=(0x80>>bitoffs);                             //~va5wI~
//              Pbitarray[byteoffs]|=ctbit;                        //~va5wR~//~vb30R~
//              Pbitarray[byteoffs]|=(char)ctbit;                  //+vb31R~
                Pbitarray[byteoffs]=(char)(Pbitarray[byteoffs]|ctbit);//+vb31I~
            }                                                      //~va5wI~
        }//for                                                     //~va5wI~
    }                                                              //~va5wI~
    else                                                           //~va5wI~
    {                                                              //~va5wI~
        for (ii=0,kk=0,pctw=Pbitarray,pct=Pcodetype;ii<Pbitarraysz && kk<Pctlen;ii++,pctw++)//~va5wR~
        {                                                          //~va5wI~
//          ct=*pctw++;                                            //~vaukR~
            ct=*pctw;                                              //~vaukI~
            for (jj=0;jj<8 && kk<Pctlen;jj++,kk++,pct++)           //~va5wR~
            {                                                      //~va5wI~
                if (ct & (0x80>>jj))                               //~va5wI~
                    *pct=XEUTFCT_UTF8;                             //~va5wR~
                else                                               //~va5wI~
                    *pct=0;                                        //~va5wR~
            }                                                      //~va5wI~
        }//for                                                     //~va5wI~
    }                                                              //~va5wI~
    return 0;                                                      //~va5wR~
}//fcmd_bitcodetype                                                //~va5wI~
//**************************************************               //~va20I~
//!get utf8 string for search on utf8 file                         //~va20R~
//*ret  :UALLOC_FAILED                                             //~va20R~
//**************************************************               //~va20I~
int fcmdcvl2fsrchstr(int Popt,PUCLIENTWE Ppcw,UCHAR *Psrch,int Psrchlen,UCHAR *Putf8str,int Putf8buffsz,int *Ppoutu8len)//~va20R~
{                                                                  //~va20I~
    UCHAR *plc,*pcd,*pct;                                           //~va20R~//~va5xR~
    int opt,lclen/*,codetype*/;                                        //~va20R~//~vaa7R~
    char wklc[MAXCOLUMN*UTF8_F2LMAXRATE];                          //~va20I~
    int handle;                                                    //~va79I~
//**************************************************               //~va20I~
	if (Ppcw->UCWtype==UCWTFILE)                                   //~va79I~
    	handle=UGETPFHFROMPCW(Ppcw)->UFHhandle;                    //~va79I~
    else                                                           //~va79I~
    	handle=0;                                                  //~va79I~
//*search on Gcmdbuff                                              //~va20I~
	lclen=fcmdsearchoncmdbuff(0,Psrch,Psrchlen,&plc,&pct,&pcd);    //~va20R~
    if (lclen)	//string remains on cmd buff                       //~va20I~
    {                                                              //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	    fcmd_savelcctforerrmsg(FCSCFEMO_SAVECT,Popt,Psrch,Psrchlen,&pct,&pcd,lclen);//~va50R~
#else                                                              //~va50I~
	    xeutf_savelcctforerrmsg(Ppcw->UCWsplitid|XEUTFSLCFEO_WORD2,Psrch,Psrchlen,plc,pct,lclen);//~va20I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		if (xeutf_cvl2fbyct(0,Psrch,Psrchlen,pcd,pct,lclen,Putf8str,Putf8buffsz,Ppoutu8len)==UALLOC_FAILED)//~va20R~
        	return UALLOC_FAILED;                                  //~va20I~
    }                                                              //~va20I~
    else    	                                                   //~va20I~
    {                                                              //~va20I~
        opt=0;                                                     //~va20I~
//      codetype=0;	//starting default of lc or u8 is A+u if valid by both//~va20I~//~vaa7R~
		if (xeutf_getmixedstr(opt,Psrch,Psrchlen,wklc,0/*pdbcs*/,0/*codetype*/,sizeof(wklc),0/*outlclen*/,Putf8str,Putf8buffsz,Ppoutu8len)==UALLOC_FAILED)//~va20R~
        	return UALLOC_FAILED;                                  //~va20I~
    }                                                              //~va20I~
//  fcmdsetupddsrch(Popt,Putf8str,*Ppoutu8len);                    //~va20R~//~va79R~
    fcmdsetupddsrch(Popt,handle,Putf8str,*Ppoutu8len);             //~va79I~
UTRACED("fcmdgetsrchstrucs inp",Psrch,Psrchlen);                   //~va20I~
UTRACED("fcmdgetsrchstrucs out",Putf8str,*Ppoutu8len);             //~va20R~
    return 0;                                                      //~va20R~
}//*fcmdcvl2fsrchstr                                               //~va20R~
//**************************************************               //~va20I~
//!setup ddstring to search in utf8file                            //~va20R~
//*ret  :UALLOC_FAILED                                             //~va20I~
//**************************************************               //~va20I~
//int fcmdsetupddsrch(int Popt,UCHAR *Psrchu8,int Psrchlenu8)        //~va20R~//~va79R~
int fcmdsetupddsrch(int Popt,int Phandle,UCHAR *Psrchu8,int Psrchlenu8)//~va79I~
{                                                                  //~va20I~
    int len,outlen,*pddstrlen,*pu8strlen;                          //~va20R~
    UCHAR *pdddbcs,*pddstr,*pddw,*pdbcsw;                           //~va20R~//~va5xR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int  *pebclen,ebclen,opt;                                      //~va50R~
    int *phandle;                                                  //~va79I~
    UCHAR *pebcdata,*pebcdbcs,*pwebcdata,*pwebcdbcs;                //~va50I~//~va5xR~
    int rc2;                                                       //~va7qI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	UCHAR wklc[MAXCOLUMN],wkct[MAXCOLUMN],*pwkct;                  //~va7rR~
    int lclen;                                                     //~va7rI~
//**************************************************               //~va20I~
	if (Popt & SEARCH_CHANGE)	//2nd word                         //~va20I~
    {                                                              //~va20I~
    	pddstr=Grepworddd;                                         //~va20I~
    	pdddbcs=Grepworddbcs;                                      //~va20I~
        pddstrlen=&Grepwordlendd;                                  //~va20I~
        pu8strlen=&Grepwordlenu8;                                  //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	pebcdata=Grepwordebcdata;                                  //~va50R~
    	pebcdbcs=Grepwordebcdbcs;                                  //~va50R~
        pebclen=&Grepwordebclen;                                   //~va50I~
        phandle=&Gebchandler;                                      //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    }                                                              //~va20I~
    else                                                           //~va20I~
	if (Popt & SEARCH_AND)	//2nd word                             //~va20R~
    {                                                              //~va20I~
    	pddstr=Gsrchdd2;                                           //~va20R~
    	pdddbcs=Gsrchdbcs2;                                        //~va20R~
        pddstrlen=&Gsrchlendd2;                                    //~va20R~
        pu8strlen=&Gsrchlenu82;                                    //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	pebcdata=Gsrchebcdata2;                                    //~va50R~
    	pebcdbcs=Gsrchebcdbcs2;                                    //~va50I~
        pebclen=&Gsrchebclen2;                                     //~va50I~
        phandle=&Gebchandle2;                                      //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    {                                                              //~va20I~
    	pddstr=Gsrchdd;                                            //~va20I~
    	pdddbcs=Gsrchdbcs;                                         //~va20R~
        pddstrlen=&Gsrchlendd;                                     //~va20I~
        pu8strlen=&Gsrchlenu82;                                    //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	pebcdata=Gsrchebcdata;                                     //~va50I~
    	pebcdbcs=Gsrchebcdbcs;                                     //~va50I~
        pebclen=&Gsrchebclen;                                      //~va50I~
        phandle=&Gebchandle;                                       //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    }                                                              //~va20I~
	if (xeutf_cvf2dd(0,Psrchu8,Psrchlenu8,&pddw,&pdbcsw,&outlen)>=4)//~va20R~
    	return 0;                                                  //~va20I~
    *pu8strlen=Psrchlenu8;                                         //~va20R~
//  len=min(sizeof(Gsrchdd),outlen);                               //~va20R~//~vb30R~
    len=min((int)sizeof(Gsrchdd),outlen);                          //~vb30I~
    memcpy(pddstr,pddw,(UINT)len);                                 //~va20R~
    memcpy(pdddbcs,pdbcsw,(UINT)len);                              //~va20R~
    *pddstrlen=len;                                                //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//save by ebcdic code                                              //~va50I~
	opt=XEEBCO_DD2B;           //dd2b                              //~va50R~
//  if (xeebc_m2bsetdbcs(opt,pddw,pdbcsw,outlen,&pwebcdata,&pwebcdbcs,&ebclen))//~va50R~//~va79R~
//  if (xeebc_m2bsetdbcs(opt,Phandle,pddw,pdbcsw,outlen,&pwebcdata,&pwebcdbcs,&ebclen))//~va79R~//~va7qR~
	ebclen=0;                                                      //~va7qI~
  if (Phandle<0)                                                   //~va79I~
  {                                                                //~va79I~
  	*phandle=Phandle;                                              //~va79I~
    *pebclen=0;                                                    //~va79I~
  }                                                                //~va79I~
  else                                                             //~va79I~
  {                                                                //~va79I~
    rc2=xeebc_m2bsetdbcs(opt,Phandle,pddw,pdbcsw,outlen,&pwebcdata,&pwebcdbcs,&ebclen);//~va7qI~
    if (!ebclen)                                                   //~va7qI~
    {                                                              //~va50I~
    	*pebclen=0;                                                //~va50I~
    }                                                              //~va50I~
    else                                                           //~va50I~
    {                                                              //~va50I~
        if (*(pwebcdata+ebclen-1)==CHAR_SI)	//end by SI            //~va50I~
            ebclen--;                                              //~va50I~
        if (*pwebcdata==CHAR_SO)                                   //~va50I~
        {                                                          //~va50I~
            pwebcdata++;                                           //~va50I~
            pwebcdbcs++;                                           //~va50I~
            ebclen--;                                              //~va50I~
        }                                                          //~va50I~
//  	*pebclen=ebclen;                                           //~va50I~//~va79R~
//  	len=min(sizeof(Gsrchebcdata),ebclen);                      //~va50I~//~va79R~
//  	ebclen=min(sizeof(Gsrchebcdata)-1,ebclen);                 //~va79I~//~vb30R~
    	ebclen=min((int)sizeof(Gsrchebcdata)-1,ebclen);            //~vb30I~
// 		memcpy(pebcdata,pwebcdata,(UINT)ebclen);                   //~va50I~//~va79R~
// 		UmemcpyZ(pebcdata,pwebcdata,ebclen);                       //~va79R~//~vb30R~
   		UmemcpyZ(pebcdata,pwebcdata,(size_t)ebclen);               //~vb30I~
   		memcpy(pebcdbcs,pwebcdbcs,(UINT)ebclen);                   //~va50I~
    	*pebclen=ebclen;                                           //~va79I~
   		*phandle=Phandle;                                          //~va79R~
    }                                                              //~va50I~
    if (rc2)    //translatio err                                   //~va7rI~
    {                                                              //~va7rI~
//		xeutfcvf2lc(XEUTFF2LCO_ERRREP/*until EOL*/,Psrchu8,Psrchlenu8,wklc,wkct,sizeof(wklc),&lclen,0/*chklen*/);//~vau6R~
//		xeutfcvdd2lc(0,Psrchu8,Psrchlenu8,pdbcsw,wklc,wkct,sizeof(wklc),&lclen);   //set ct considering ddfmt char width//~vau6I~//~vb2IR~
  		xeutfcvdd2lc(0,pddw,outlen,pdbcsw,wklc,wkct,sizeof(wklc),&lclen);   //set ct considering ddfmt char width//~vb2IR~
        pwkct=wkct;                                                //~va7rI~
	    fcmd_savelcctforerrmsg(FCSCFEMO_SAVECT,Popt,Psrchu8,Psrchlenu8,&pwkct,&pdbcsw,lclen);//~va7rR~
    }                                                              //~va7rI~
  }//not ini read                                                  //~va79I~
UTRACED("fcmdsetupddsrch out ebcdata",pebcdata,ebclen);            //~va50I~
UTRACED("fcmdsetupddsrch out ebcdbcs",pebcdbcs,ebclen);            //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
UTRACED("fcmdsetupddsrch inp utf8",Psrchu8,Psrchlenu8);            //~va20R~
UTRACED("fcmdsetupddsrch out dd",pddstr,len);                      //~va20R~
UTRACED("fcmdsetupddsrch out dbcs",pdddbcs,len);                   //~va20R~
UTRACEP("fcmdsetupddsrch out handle=%d\n",*phandle);               //~va79I~
    return 1;                                                      //~va20I~
}//*fcmdsetupddsrch                                                //~va20I~
//**************************************************               //~va20I~
//!setup ddstring to search in utf8file                            //~va20I~
//*ret  :ddstr len,0 if not utf8 file                              //~va20R~
//**************************************************               //~va20I~
int fcmdisddsrch(int Popt,PUCLIENTWE Ppcw,UCHAR **Ppddstr,UCHAR **Ppdddbcs)//~va20R~
{                                                                  //~va20I~
	PUFILEH pfh;                                                   //~va20R~
    int ddstrlen=0;                                                //~va3ER~
    UCHAR *pdddbcs,*pddstr;                                        //~va20R~
	PUPANELC ppc;                                                  //~vavwI~
//**************************************************               //~va20I~
	ppc=Ppcw->UCWppc;                                              //~vavwI~
	if (Ppcw->UCWtype!=UCWTFILE)                                   //~va20I~
    {                                                              //~vavwI~
      if (ppc->UPCid!=PANFNAME)                                    //~vavwI~
    	return 0;                                                  //~va20I~
    }                                                              //~vavwI~
    pfh=UGETPFHFROMPCW(Ppcw);                                      //~va20I~
    if (!FILEUTF8MODE(pfh))                                        //~va20I~
    	return 0;                                                  //~va20I~
	if (Popt &SEARCH_CHANGE)	//2nd word                         //~va20I~
    {                                                              //~va20I~
      	if (Sfindopt & FINDOPT_GREPPTARGET)   //change target is P'..' pattern//~va3EI~
        	return 0;                                              //~va3EI~
    	pddstr=Grepworddd;                                         //~va20I~
    	pdddbcs=Grepworddbcs;                                      //~va20I~
        ddstrlen=Grepwordlendd;                                    //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
	if (Popt &SEARCH_AND)	//2nd word                             //~va20I~
    {                                                              //~va20I~
		if (Sothopt & SEARCH_UTF8ECH2) //2nd word is *ec           //~va3EI~
        	return 0;                                              //~va3EI~
        if (Sescsrchlen2)                                          //~va3EI~
        	return 0;                                              //~va3EI~
        if (Sfindopt & FINDOPT_GREP)                               //~va3EI~
        	return 0;                                              //~va3EI~
        if (Stabsrchsw2)                                           //~va3EI~
        	return 0;                                              //~va3EI~
    	pddstr=Gsrchdd2;                                           //~va20I~
    	pdddbcs=Gsrchdbcs2;                                        //~va20I~
        ddstrlen=Gsrchlendd2;                                      //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    {                                                              //~va20I~
        if (Sothopt & SEARCH_UTF8ECH)	//1st word is *ec          //~va3EI~
        	return 0;                                              //~va3EI~
        if (Sescsrchlen)                                           //~va3EI~
        	return 0;                                              //~va3EI~
        if (Sfindopt & FINDOPT_GREP)                               //~va3EI~
        	return 0;                                              //~va3EI~
        if (Stabsrchsw)                                            //~va3EI~
        	return 0;                                              //~va3EI~
    	pddstr=Gsrchdd;                                            //~va20I~
    	pdddbcs=Gsrchdbcs;                                         //~va20I~
        ddstrlen=Gsrchlendd;                                       //~va20I~
    }                                                              //~va20I~
    *Ppddstr=pddstr;                                               //~va20I~
    *Ppdddbcs=pdddbcs;                                             //~va20I~
    return ddstrlen;                                               //~va20I~
}//*fcmdisddsrch                                                   //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//**************************************************               //~va50I~
//!setup ddstring to search in utf8file                            //~va50I~
//*ret  :4:esclen=0,1:escstr(hex input)                            //~va50R~
//**************************************************               //~va50I~
int fcmdgetebcsrchstr(int Popt,PUCLIENTWE Ppcw,UCHAR **Ppebcstr,UCHAR **Ppebcdbcs,int *Ppesclen)//~va50R~
{                                                                  //~va50I~
	PUFILEH pfh;                                                   //~va50I~
    int ebcstrlen=0,rc=0;                                          //~va50R~
    UCHAR *pebcdbcs=NULL,*pebcstr=NULL;                                      //~va50R~//~vaf9R~
//  UCHAR *pdddbcs,*pddstr;                                        //~va79R~//~vaa7R~
//  int handle=0,ddstrlen,oldhandle=0,*phandle,u8len;              //~va79R~//~vaf9R~
    int handle=0,ddstrlen=0,oldhandle=0,*phandle,u8len;            //~vaf9I~
    UCHAR *pu8=0;                                                  //~va79R~
//**************************************************               //~va50I~
	phandle=&oldhandle;                                            //~va79I~
    for (;;)                                                       //~va50I~
    {                                                              //~va50I~
		if (Ppcw->UCWtype!=UCWTFILE)                               //~va50I~
    		break;                                                 //~va50I~
    	pfh=UGETPFHFROMPCW(Ppcw);                                  //~va50I~
        if (!PFH_ISEBC(pfh))                                       //~va50R~
            break;                                                 //~va50R~
        handle=pfh->UFHhandle;                                     //~va79I~
        if (Popt & SEARCH_CHANGE)   //2nd word                     //~va50R~
        {                                                          //~va50R~
            if (Sfindopt & FINDOPT_GREPPTARGET)   //change target is P'..' pattern//~va50R~
	            break;                                             //~va50I~
            pebcstr=Grepwordebcdata;                               //~va50R~
            pebcdbcs=Grepwordebcdbcs;                              //~va50R~
//  		pddstr=Grepworddd;                                     //~va79I~//~vaa7R~
//  		pdddbcs=Grepworddbcs;                                  //~va79I~//~vaa7R~
        	ddstrlen=Grepwordlendd;                                //~va79I~
            phandle=&Gebchandler;                                  //~va79R~
            if (Sescreplen)                                        //~va50R~
            	rc=1;                                              //~va50I~
            else                                                   //~va50I~
            {                                                      //~va79I~
            	ebcstrlen=Grepwordebclen;                          //~va50I~
                pu8=Sescrepchar;	//contains utf8 str if not escsrch//~va79I~
            }                                                      //~va79I~
        }                                                          //~va50R~
        else                                                       //~va50R~
        if (Popt & SEARCH_AND)  //2nd word                         //~va50R~
        {                                                          //~va50R~
//          if (Sothopt & SEARCH_UTF8ECH2) //2nd word is *ec       //~va50R~//~va6jR~
//              break;                                             //~va50I~//~va6jR~
            if (Sfindopt & FINDOPT_GREP)                           //~va50R~
	            break;                                             //~va50I~
            if (Stabsrchsw2)                                       //~va50R~
	            break;                                             //~va50I~
            pebcstr=Gsrchebcdata2;                                 //~va50R~
            pebcdbcs=Gsrchebcdbcs2;                                //~va50R~
//  		pddstr=Gsrchdd2;                                       //~va79I~//~vaa7R~
//  		pdddbcs=Gsrchdbcs2;                                    //~va79I~//~vaa7R~
        	ddstrlen=Gsrchlendd2;                                  //~va79I~
            phandle=&Gebchandle2;                                  //~va79R~
            if (Sescsrchlen2)                                      //~va50M~
            	rc=1;                                              //~va50M~
            else                                                   //~va50I~
            {                                                      //~va79I~
            	ebcstrlen=Gsrchebclen2;                            //~va50R~
                pu8=Sescsrchchar2;	//contains utf8 str if not escsrch//~va79I~
            }                                                      //~va79I~
        }                                                          //~va50R~
        else                                                       //~va50R~
        {                                                          //~va50R~
//          if (Sothopt & SEARCH_UTF8ECH)   //1st word is *ec      //~va50R~//~va6jR~
//              break;                                             //~va50I~//~va6jR~
            if (Sothopt & SEARCH_UTF8ECH)   //1st word is *ec      //~va79I~
                break;                                             //~va79R~
            if (Sfindopt & FINDOPT_GREP)                           //~va50R~
	            break;                                             //~va50I~
            if (Stabsrchsw)                                        //~va50R~
	            break;                                             //~va50I~
            pebcstr=Gsrchebcdata;                                  //~va50R~
            pebcdbcs=Gsrchebcdbcs;                                 //~va50R~
//  		pddstr=Gsrchdd;                                        //~va79I~//~vaa7R~
//  		pdddbcs=Gsrchdbcs;                                     //~va79I~//~vaa7R~
        	ddstrlen=Gsrchlendd;                                   //~va79I~
            phandle=&Gebchandle;                                   //~va79R~
            if (Sescsrchlen)                                       //~va50I~
            	rc=1;                                              //~va50I~
            else                                                   //~va50I~
            {                                                      //~va79I~
	            ebcstrlen=Gsrchebclen;                             //~va50I~
                pu8=Sescsrchchar;	//contains utf8 str if not escsrch//~va79I~
            }                                                      //~va79I~
        }                                                          //~va50R~
	    break;                                                     //~va50I~
    }                                                              //~va50I~
//if (rc<=1)                                                       //~va6jI~//~va79R~
  if (rc==1 || pu8)     //not breaked                              //~va79R~
  {                                                                //~va6jI~
    *Ppebcstr=pebcstr;                                             //~va50R~
    *Ppebcdbcs=pebcdbcs;                                           //~va50R~
  }                                                                //~va6jI~
//  if (!rc)	//not esc                                          //~va50I~//~va79R~
    if (pu8)	//not esc                                          //~va79I~
    {                                                              //~va79I~
      	if (ddstrlen                                               //~va79R~
	  	&&  handle!=*phandle)                                      //~va79R~
        {                                                          //~va79I~
//      	u8len=strlen(pu8);                                     //~va79I~//~vb30R~
        	u8len=(int)strlen(pu8);                                //~vb30I~
			fcmdsetupddsrch(Popt,handle,pu8,u8len);                //~va79I~
//          ebcstrlen=strlen(pebcstr);                             //~va79I~//~vb30R~
            ebcstrlen=(int)strlen(pebcstr);                        //~vb30I~
        }                                                          //~va79I~
        if (!ebcstrlen)                                            //~va50R~
        {                                                          //~va50R~
          if (ddstrlen)                                            //~va7fI~
          {                                                        //~va7fI~
            uerrmsg("no EBCDIC data(conflict or not supported option or translation error)",0);//~va50R~
            rc=4;                                                  //~va50R~
          }                                                        //~va7fI~
        }                                                          //~va50R~
    }                                                              //~va79I~
    *Ppesclen=ebcstrlen;                                           //~va50R~
    UTRACED("getebcsrchstr data",pebcstr,ebcstrlen);               //~va50I~
    UTRACED("getebcsrchstr dbcs",pebcdbcs,ebcstrlen);              //~va50I~
    return rc;                                                     //~va50R~
}//*fcmdgetebcsrchstr                                              //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//**************************************************               //~va20M~
//!set dd string for escsrch of utf8 file                          //~va20M~
//rc:4:odd number byte                                             //~va20M~
//**************************************************               //~va20M~
int fcmdcvesc2dd(int Popt,UCHAR *Pescchar,int Plen,UCHAR *Pescdd,UCHAR *Pescdbcs,int Poutbuffsz,int *Pescddlen)//~va20M~
{                                                                  //~va20M~
	int ddlen,reslen,resleno;                                      //~va20R~
    UCHAR *pc,*pco,*pcdo;                                          //~va20M~
#ifdef UTF8UTF16                                                   //~vaw4I~
    UWUCS ucs;	//UINT4                                            //~vaw4R~
#else                                                              //~vaw4I~
    WUCS ucs;                                                      //~va20M~
#endif                                                             //~vaw4I~
//*********************************                                //~va20M~
	if (Plen==1)	//\a,\b etc.                                   //~va20M~
    {                                                              //~va20M~
    	*Pescdd=*Pescchar;                                         //~va20M~
        *Pescdbcs=0;	//sbcs                                     //~va20M~
        ddlen=1;                                                   //~va20M~
    }                                                              //~va20M~
    else                                                           //~va20M~
    {                                                              //~va20M~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
	  if (Sothopt & SEARCH_UCS4)                                   //~va3xI~
      {                                                            //~va3xI~
    	if (Plen%3)	//not multiple of 3 byte                       //~va3xI~
        {                                                          //~va3xI~
        	uerrmsg("%s : UCS4 Hex replacing string should be multiple of 3 byte",0,//~va3xI~
                    Srepword);                                     //~va3xI~
            return 4;                                              //~va3xI~
        }                                                          //~va3xI~
      }                                                            //~va3xI~
      else                                                         //~va3xI~
#endif                                                             //~va3xI~
      {                                                            //~va3xI~
    	if ((Plen & 0x01))	//odd number                           //~va20M~
        {                                                          //~va20M~
#ifdef UTF8UCS416                                                  //~vaw4I~
        	uerrmsg("%s : Hex replacing string should be ucs2 for UTF8 file(even number of bytes), OR specify \"U4\" option for UCS4.",//~vaw4I~
					"%s : UTF8ファイルのHEX指定置換文字列はUCS2形式HEX(偶数バイト)です。3バイトUCS4の場合は \"U4\"を指定する。",//~vaw4R~
                    Srepword);                                     //~vaw4I~
#else                                                              //~vaw4I~
        	uerrmsg("%s : Hex replacing string should be ucs2 for UTF8 file(even number of bytes)",//~va20R~
					"%s : UTF8ファイルのHEX指定置換文字列はUCS2形式HEX(偶数バイト)です。",//~va20R~
                    Srepword);                                     //~va20R~
#endif                                                             //~vaw4I~
            return 4;                                              //~va20M~
        }                                                          //~va20M~
      }                                                            //~va3xI~
        for (reslen=Plen,resleno=Poutbuffsz,pc=Pescchar,pco=Pescdd,pcdo=Pescdbcs;//~va20M~
        		reslen>0 && resleno>1;                             //~va20R~
                pc+=2,reslen-=2,pco+=ddlen,pcdo+=ddlen,resleno-=ddlen//~va20M~
        )                                                          //~va20M~
        {                                                          //~va20M~
                                                                   //~va3xI~
//#ifdef UTF8UCS4                                                    //~va1CI~//~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
		  if (Sothopt & SEARCH_UCS4)                               //~va3xI~
          {                                                        //~va3xI~
        	ucs=UTF_GETUCS4FROMBESTR(pc);                          //~va3xR~
            pc++,reslen--;  //3byte hex data                       //~va3xR~
          }                                                        //~va3xI~
          else                                                     //~va3xI~
#endif                                                             //~va1CI~//~va3xI~
        	ucs=UTF_GETUCSDBCS(pc);	//get big endian 2 byte ucs    //~va20M~
#ifdef UTF8UTF16                                                   //~vaw4I~
        	utfcvu2dd1wUCS4(0,ucs,pco,pcdo,&ddlen);                //~vaw4I~
#else                                                              //~vaw4I~
        	utfcvu2dd1(0,ucs,pco,pcdo,&ddlen);                     //~va20M~
#endif                                                             //~vaw4I~
                                                                   //~va20M~
        }                                                          //~va20M~
//      ddlen=(ULONG)pco-(ULONG)Pescdd;                            //~va20M~//~vafkR~
//      ddlen=(ULPTR)pco-(ULPTR)Pescdd;                            //~vafkI~//~vb2FR~
        ddlen=PTRDIFF(pco,Pescdd);                                 //~vb2FR~
    }                                                              //~va20M~
    *Pescddlen=ddlen;                                              //~va20M~
    return 0;                                                      //~va20M~
}//fcmdcvesc2dd                                                    //~va20M~
//**************************************************               //~va20M~
//!set dd string for escsrch of utf8 file                          //~va20M~
//**************************************************               //~va20M~
int fcmdescsrchinit(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)         //~va20M~
{                                                                  //~va20M~
	int rc=0;                                                      //~va20R~
//*********************************                                //~va20M~
//once clear                                                       //~va20M~
    if (Popt & FCESI_LOCATE)    //not following of "all" search    //~va20I~
    {                                                              //~va20I~
        Sothopt&=~SEARCH_ESCDDREP;                                 //~va20R~
        if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN) //bin file           //~va20R~
        || !FILEUTF8MODE(Ppfh)                                     //~va20R~
        )                                                          //~va20R~
            return 0;                                              //~va20R~
        rc=fcmdcvesc2dd(0,Sescrepchar,Sescreplen,Grepworddd,Grepworddbcs,sizeof(Grepworddd),&Grepwordlendd);//~va20R~
        if (!rc)                                                   //~va20R~
            Sothopt|=SEARCH_ESCDDREP;                              //~va20R~
    }                                                              //~va20M~
    return rc;                                                     //~va20M~
}//fcmdescsrchinit                                                 //~va20M~
#endif //UTF8UCS2                                                  //~va20I~
//#ifdef LNX                                                         //~vaukI~//~vauFR~
//**************************************************               //~vauiI~
//!FWD searchby esc char on DD fmt                                 //~vauiI~
//*matched at char boundary even when escchar srch                 //~vauiI~
//*Pdata:left end pos                                              //~vauiI~
//*Poffset:right end pos                                           //~vauiI~
//*ret  :found pos,0 if not found                                  //~vauiI~
//**************************************************               //~vauiI~
char *fcmdddstrsrch_dir(int Popt,UCHAR *Psrchstr,UCHAR *Psrchdbcs,int Psrchstrlen,char *Pdata,char *Pdbcs,int Pddlen,int *Ppoffs)//~vauiR~
{                                                                  //~vauiI~
    char *pc,*pcd,*pc0,*pcd0,*pce,*srchstr,*pcn=0,contsw,*pcdn=NULL;//~vauiR~
    char *srchdbcs;                                                //~vauiR~
    int swnocase,swddsrch,offs;                                    //~vauiR~
    int offs0,srchlen,ucs,dbcsid,wordlen=0;                        //~vauiI~
//*********************************                                //~vauiI~
    UTRACED("Psrchstr",Psrchstr,Psrchstrlen);                      //~vauiI~
    UTRACED("Psrchdbcs",Psrchdbcs,Psrchstrlen);                    //~vauiI~
    UTRACED("Pdata",Pdata,Pddlen);                                 //~vauiI~
    UTRACED("Pdbcs",Pdbcs,Pddlen);                                 //~vauiI~
    swnocase=(Popt & FCMDDDSSO_NOCASE);//case insensitive          //~vauiI~
    swddsrch=Popt & FCMDDDSSO_DDSTR;                               //~vauiI~
    pc0=Pdata;                                                     //~vauiI~
    pcd0=Pdbcs;                                                    //~vauiI~
    offs0=0;                                                       //~vauiI~
    srchstr=Psrchstr;                                              //~vauiI~
    srchdbcs=Psrchdbcs;                                            //~vauiI~
    srchlen=Psrchstrlen;                                           //~vauiI~
    	for (pc=Pdata,pce=Pdata+Pddlen,pcd=pcd0+offs0;             //~vauiR~
    			pc<pce;                                            //~vauiI~
                pc++,pcd++                                         //~vauiI~
			)                                                      //~vauiI~
        {                                                          //~vauiI~
        	dbcsid=*pcd;                                           //~vauiI~
            contsw=0;                                              //~vauiI~
    		if (UDBCSCHK_ISUCSSBCS(dbcsid)) //SBCS                 //~vauiI~
            {                                                      //~vauiI~
            	if (swddsrch)                                      //~vauiI~
                {                                                  //~vauiI~
                	if (dbcsid==*srchdbcs && *pc==*srchstr)        //~vauiI~
                    {                                              //~vauiI~
	                	srchstr++;                                 //~vauiI~
	                	srchdbcs++;                                //~vauiI~
    	                srchlen--;                                 //~vauiI~
         	            contsw=1;                                  //~vauiI~
                    }                                              //~vauiI~
                }                                                  //~vauiI~
                else                                               //~vauiI~
                {                                                  //~vauiI~
                    ucs=(int)UTF_GETUCSSBCS(pc,pcd);               //~vauiI~
              	  	if (ucs>>16)   //ucs4                          //~vauiI~
                  	{                                              //~vauiI~
                        if ( ((ucs>>16)==*srchstr)                 //~vauiI~
                        &&   (srchlen>2 && ((ucs>>8) & 0xff)==*(srchstr+1))//~vauiI~
                        &&   (((ucs) & 0xff)==*(srchstr+2))        //~vauiI~
                           )                                       //~vauiI~
                        {                                          //~vauiI~
                            srchstr+=3;                            //~vauiI~
                            srchlen-=3;                            //~vauiI~
                            contsw=3;   //continue matching        //~vauiI~
                        }                                          //~vauiI~
                  	}                                              //~vauiI~
                  	else                                           //~vauiI~
                  	{//ucs2                                        //~vauiI~
                        if ( ((ucs>>8)==*srchstr)                  //~vauiI~
                        &&   (srchlen>1 && (ucs & 0xff)==*(srchstr+1))//~vauiI~
                           )                                       //~vauiI~
                        {                                          //~vauiI~
                            srchstr+=2;                            //~vauiI~
                            srchlen-=2;                            //~vauiI~
                            contsw=2;   //continue matching        //~vauiI~
                        }                                          //~vauiI~
                  	}//ucs2                                        //~vauiI~
                }//ucssrch                                         //~vauiI~
            }                                                      //~vauiI~
            else                                                   //~vauiI~
//#ifdef UTF8UCS4                                                    //~vaukI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
    		if (UDBCSCHK_ISUCSOVF1ST(dbcsid) && pc+1<pce)          //~vauiI~
            {                                                      //~vauiI~
            	if (swddsrch)                                      //~vauiI~
                {                                                  //~vauiI~
                	if (dbcsid==*srchdbcs && *pc==*srchstr         //~vauiI~
                	&& (*(pcd+1)==*(srchdbcs+1) && *(pc+1)==*(srchstr+1))//~vauiI~
                    )                                              //~vauiI~
                    {                                              //~vauiI~
                        srchstr+=2;                                //~vauiI~
                        srchdbcs+=2;                               //~vauiI~
                        srchlen-=2;                                //~vauiI~
                        contsw=4;        //2 byte ucs4             //~vauiI~
                    }                                              //~vauiI~
                }                                                  //~vauiI~
                else                                               //~vauiI~
                {                                                  //~vauiI~
                    ucs=(int)UTF_GETUCSDBCSOVF(pc,pcd);            //~vauiI~
                    if ( ((ucs>>16)==*srchstr)                     //~vauiI~
                    &&   (srchlen>2 && ((ucs>>8) & 0xff)==*(srchstr+1))//~vauiI~
                    &&   (((ucs) & 0xff)==*(srchstr+2))            //~vauiI~
                       )                                           //~vauiI~
                    {                                              //~vauiI~
                        srchstr+=3;                                //~vauiI~
                        srchlen-=3;                                //~vauiI~
                        contsw=4;        //2 byte ucs4             //~vauiI~
                    }                                              //~vauiI~
                }                                                  //~vauiI~
            }                                                      //~vauiI~
            else	//dbcs                                         //~vauiI~
#endif                                                             //~vaukI~
            {                                                      //~vauiI~
            	if ((*pc==*srchstr)                                //~vauiI~
                ||  ( swnocase && !dbcsid && toupper(*pc)==toupper(*srchstr) )//~vauiI~
                )                                                  //~vauiI~
                {                                                  //~vauiI~
                  	if (!swddsrch || dbcsid==*srchdbcs)            //~vauiI~
                  	{                                              //~vauiI~
                        if (wordlen //2nd byte match               //~vauiI~
                        ||  !UDBCSCHK_DBCS2NDU(dbcsid) //match start by byte boundary//~vauiI~
                        )                                          //~vauiI~
                        {                                          //~vauiI~
                            srchstr++;                             //~vauiI~
                            srchdbcs++;                            //~vauiI~
                            srchlen--;                             //~vauiI~
                            contsw=1;   //continue matching        //~vauiI~
                        }                                          //~vauiI~
                  	}//dbcs match                                  //~vauiI~
                }                                                  //~vauiI~
            }//dbcs                                                //~vauiI~
            if (contsw)                                            //~vauiI~
            {                                                      //~vauiI~
                if (!wordlen)	//1st match                        //~vauiI~
                {                                                  //~vauiI~
                    pcn=pc;  //prev of restart point               //~vauiI~
                    pcdn=pcd;                                      //~vauiI~
                }                                                  //~vauiI~
                wordlen++;                                         //~vauiI~
                if (contsw==4)	//UCS4 2 byte match                //~vauiI~
                {                                                  //~vauiI~
                	pc++,pcd++;                                    //~vauiI~
                    wordlen++;                                     //~vauiI~
                }                                                  //~vauiI~
            	if (!srchlen)	//full match                       //~vauiI~
	            {                                                  //~vauiI~
                	if (!UDBCSCHK_DBCS1STUCS2NWP(dbcsid))//last byte match to dbcs1st//~vauiI~
                		break;                                     //~vauiI~
                	contsw=0;	//split dbcs unmatch               //~vauiI~
            	}                                                  //~vauiI~
                if (contsw)                                        //~vauiI~
                	continue;                                      //~vauiI~
            }                                                      //~vauiI~
            if (!wordlen)	//top byte unmatch,no need resey       //~vauiI~
                continue;                                          //~vauiI~
            pc=pcn;                                                //~vauiI~
            pcd=pcdn;                                              //~vauiI~
            srchstr=Psrchstr;                                      //~vauiI~
            srchdbcs=Psrchdbcs;                                    //~vauiI~
            srchlen=Psrchstrlen;                                   //~vauiI~
            wordlen=0;                                             //~vauiI~
        }                                                          //~vauiI~
        pc=pcn; //match top pos                                    //~vauiI~
    offs=PTRDIFF(pc,pc0);                                          //~vauiI~
    if (srchlen)                                                   //~vauiI~
    	pc=0;                                                      //~vauiI~
    if (Ppoffs)                                                    //~vauiR~
    	*Ppoffs=offs;                                              //~vauiI~
    UTRACEP("dcmdddstrsrch_dir offs=%d\n",offs);                   //~vauiI~
    return pc;                                                     //~vauiI~
}//fcmdddstrsrch_dir                                               //~vauiI~
//#endif //LNX                                                       //~vaukI~//~vauFR~
