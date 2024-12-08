//*CID://+vbkcR~:                             update#=261;         //~vbkcR~
//*************************************************************
//* xefsubw.c                                                      //~vav0R~
//*************************************************************
//vbke:180619 add msg to display utf8 code filename                //~vbkcI~
//vbi4:180217 set dbcs '?' when f2l err of dbcs(if sbcs '?' err at funcsetlongcmdfromstack xeutf_setbyu8lc->xeutfcvf2dd)//~vbi4I~
//vb4b:160729 (BUG) err msg "Invalid FileNAme Format" when saved cmd stack contains UD format char(0x01 etc)//~vb4bI~
//vaww:140611 (W32UNICODE:BUG)retrive of 2 opd cmd,2nd displayed as dbcs//~vawvI~
//vawv:140610 (W32UNICODE)for ftp,enclose utf8 membname on UDHname //~vaw1I~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vavQ:140405 set parsed cmdlc(for xprint dcmd u8filename)         //~vavQI~
//vavF:140401 (W32UNICODE)green pos on renamefld(utf ascii mix)    //~vavFI~
//vavp:140426 (vaub for Win)maintain ddfmt for pan fnmlist and util panel//~vavpI~
//vavn:140425 (BUG of vavj)setdbcstbl required for cmdline char edit for surrogae pair 4 dbcs//~vavnI~
//vavk:140425 (BUG)cmd retrieve miss to recovery utf8 encoding     //~vavkI~
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavcI~
//vav0:140325 (Win)unicode support                                 //~vav0I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>                                                //~v66fI~
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>                                              //~5503M~
                                                                   //~vav0I~
#include <windows.h>                                               //~vav0I~
                                                                   //~vav0I~
#include <ulib.h>
#include <ualloc.h>                                                //~v50eI~
#include <uerr.h>
#include <uque.h>
#include <utrace.h>                                                //~vav0I~
#include <ufile.h>                                                 //~vav0I~
#include <uftp.h>                                                  //~vav0I~
#include <ufile1f.h>                                               //~vav0I~
#include <ufilew.h>                                                //~vav0I~
#include <utf.h>                                                   //~vav0I~
#include <utf22.h>                                                 //~vav0I~
#include <ustring.h>                                               //~vav0I~
#include <ucvucs.h>                                                //~vav0R~
#include <ucvext.h>                                                //~vav0I~
#include <ucvext2.h>                                               //~vav0I~
#include <udbcschk.h>                                              //~vavnI~
//*******************************************************
#include <xe.h>                                                    //~vav0I~
#include <xescr.h>                                                 //~vav0I~
#include <xefile.h>                                                //~vav0I~
#include <xeutf.h>                                                 //~vav0I~
#include <xeopt.h>                                                 //~vav0I~
#include <xedir.h>                                                 //~vav0M~
#include <xefsubw.h>                                               //~vav0I~
#include <xeutf.h>                                                 //~vav0I~
#include <xepan.h>                                                 //~vav0I~
#include <xepan22.h>                                               //~vav0I~
#include <xesub.h>                                                 //~vavpI~
#include <xefunc.h>                                                //~vavFI~
//**************************************************************** //~vav0I~
//**************************************************************** //~va1BM~
// setcodetype from cmdbuff codetype(save as filenamelist registration)//~va1BM~
// rc:0 no utf8 coe contained,1 contains utf8 coed                 //~vavcR~
//**************************************************************** //~va1BM~
//int fileutf8setfilenamecodetype(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)//~va1BI~//~vav0R~
int fsubw_fileutf8setfilenamecodetype(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pfnm,int Plen,char *Pdddata,char *Pdddbcs,char *Pddct,int Pbuffsz,int *Ppddlen)//~vav0R~
{                                                                  //~va1BM~
	char *pu8;                                       //~va1BI~     //~vav0R~
    int lenlc=0,rc=0;                                      //~vaf9I~//~vav0R~
    int lenu8;                                                     //~va1BI~
    char wkfpathlc[_MAX_PATHF2L];                                  //~vav9I~
    char wkfpathct[_MAX_PATHF2L];                                  //~vav9I~
    int opt;                                                       //~vagEI~//~vav0R~
    int rc2;                                                       //~vavcI~
//*****************                                                //~va1BM~
//  if (UCBITCHK(Ppfh->UFHflag,UFHFWORKDIRFILE))                     //~va5sR~//~vav0R~
//    pu8=Ppfh->UFHalias;                                            //~va5sR~//~vav0R~
//  else                                                             //~va5sI~//~vav0R~
//    pu8=Ppfh->UFHfilename;                                         //~va1BI~//~vav0R~
//    lenu8=strlen(pu8);                                             //~va1BI~//~vav0R~
    pu8=Pfnm;                                                      //~vav0I~
    lenu8=Plen;                                                    //~vav0I~
//  if (!pan300stackchkcmdbuff(0,pu8))	//locale name remains on cmd buff//~va1BI~//~vav0R~
//  opt=P3SCCBO_CHKFULLPARMFNAME; //no preceding ascii chk         //~vav0I~//~vavcR~
    opt=P3SCCBO_CHKFULLPARMFNAME|P3SCCBO_RCIFLC; //set rc=3 if U8=LC & no preceding ascii chk//~vavcI~
//  if (!pan300stackchkcmdbuff(opt,pu8))	//locale name remains on cmd buff//~vav0I~//~vavcR~
    rc2=pan300stackchkcmdbuff(opt,pu8);	//locale name remains on cmd buff//~vavcI~
    if (!rc2)                               //locale name remains on cmd buff//~vavcI~
    	rc=1;                                                      //~va1CR~
    else                                                           //~vavcI~
    if (rc2==3)     //fnm remains on cmd buff but dose not contains utf8 code//~vavcI~
        return 0;	//no utf8 code                                 //~vavcI~
    else                                                           //~va1CI~
    {                                                              //~va1CI~
    	if (!memchr(Gcmdbuffct,XEUTFCT_UTF8,Gcmdbufflclen))        //~vav0I~
        	return 0;	//no utf8 code                             //~vav0I~
//  	lenlc=pan300stacksetctfromcmdbuffsub(0,pu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),wkdddata,wkdddbcs,wkddct,sizeof(wkdddata),&lendd);//~vaubR~//~vav0R~
		opt=0;                                                     //~vav0R~
    	lenlc=pan300stacksetctfromcmdbuffsub(opt,pu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),Pdddata,Pdddbcs,Pddct,Pbuffsz,Ppddlen);//~vav0R~
    	if (!lenlc)                                                //~va1CR~
        	rc=1;                                                  //~va1CI~
    }                                                              //~va1CI~
//for edit cmd normally rc=0(remains ct in cmd buff)               //~vavcI~
    if (rc==1)                                                     //~va1CI~
    {                                                              //~vagEI~
    	opt=0;                                                     //~vagEI~
//        if (UCBITCHK(Ppfh->UFHflag13,UFHF13SELECTFNU8)) //utf8 filename on dirlist//~vauAR~//~vav0R~
//            opt|=XEUTFGLPNO_FNU8MEMB;   //select utf8 for member encoding if both utf8 and locale is valid//~vauJI~//~vav0R~
//        else                                                       //~vauAI~//~vav0R~
//        if (UCBITCHK(Ppfh->UFHflag13,UFHF13SELECTFNLC))            //~vauAR~//~vav0R~
//            opt|=XEUTFGLPNO_FNLCMEMB;   //select utf8 for membername encoding if both utf8 and locale is valid//~vauJI~//~vav0R~
    	if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNU8))                  //~vagER~
        	opt|=XEUTFGLPNO_FNU8;	//select utf8 for filename encoding if both utf8 and locale is valid//~vagEI~
        else                                                       //~vagEI~
    	if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNLC))                  //~vagER~
        	opt|=XEUTFGLPNO_FNLC;	//select localecode for filename encoding if both utf8 and locale is valid//~vagEI~
        opt|=XEUTFGLPNO_LCWIDTHBYDDWIDTH;	//rep by "?" when lcwidth!=ddwidth for ddfmt field//~vaubI~
//  	xeutf_getlocalepathname(opt,pu8,lenu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),&lenlc,wkdddata,wkdddbcs,wkddct,sizeof(wkdddata),&lendd);//~vauaI~//~vav0R~
#ifdef W32UNICODE                                                  //~vavcI~
//*FIXME flag was set?:NOT FIXED                                   //~vavcI~//~vaw1R~
		if (FILEISREMOTE(Ppfh))                                    //~vavcI~
	        opt|=XEUTFGLPNO_REMOTE;	//rep by "?" when lcwidth!=ddwidth for ddfmt field//~vavcI~
#endif                                                             //~vavcI~
    	xeutf_getlocalepathname(opt,pu8,lenu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),&lenlc,Pdddata,Pdddbcs,Pddct,Pbuffsz,Ppddlen);//~vav0R~
    	if (!memchr(wkfpathct,XEUTFCT_UTF8,lenlc))                 //~vav0I~
        	return 0;                                              //~vav0I~
    }                                                              //~vagEI~
//    allocsz=lenlc+lenlc+1;                                         //~va1BI~//~vav0R~
//    pc=umalloc(allocsz);                                           //~va1BM~//~vav0R~
//    UALLOCCHK(pc,UALLOC_FAILED);                                   //~va1BM~//~vav0R~
//    pct=pc;                                                        //~va1BM~//~vav0R~
//    plc=pc+lenlc;                                                  //~va1BR~//~vav0R~
//    memcpy(pct,wkfpathct,(UINT)lenlc);                             //~va1BR~//~vav0R~
//    UmemcpyZ(plc,wkfpathlc,(UINT)lenlc);                           //~va1BR~//~vav0R~
//    Ppfh->UFHfilenamecodetype=pct; // free addr                    //~va1BM~//~vav0R~
//    Ppfh->UFHfilenamebylc=plc;                                     //~va1BM~//~vav0R~
//    Ppfh->UFHfilenamebylclen=lenlc;                                //~va1BR~//~vav0R~
//    Ppfh->UFHfilenameddlen=lendd;                                  //~vau7I~//~vav0R~
//  if (lendd)                                                       //~vauaM~//~vav0R~
//  {                                                                //~vauaM~//~vav0R~
//    allocsz=lendd*3+1;                                             //~vau7I~//~vav0R~
//    pc=umalloc(allocsz);                                           //~vau7I~//~vav0R~
//    UALLOCCHK(pc,UALLOC_FAILED);                                   //~vau7I~//~vav0R~
//    Ppfh->UFHfilenamedddata=pc; // free addr                       //~vau7I~//~vav0R~
//    memcpy(pc,wkdddata,lendd);                                     //~vau7I~//~vav0R~
//    UTRACED("xeutf8setfilenamecodetype data",pc,lendd);            //~vau7I~//~vav0R~
//    pc+=lendd;                                                     //~vau7I~//~vav0R~
//    Ppfh->UFHfilenamedddbcs=pc;                                    //~vau7I~//~vav0R~
//    memcpy(pc,wkdddbcs,lendd);                                     //~vau7I~//~vav0R~
//    UTRACED("xeutf8setfilenamecodetype dbcs",pc,lendd);            //~vau7I~//~vav0R~
//    pc+=lendd;                                                     //~vau7I~//~vav0R~
//    Ppfh->UFHfilenameddct=pc;                                      //~vau7I~//~vav0R~
//    memcpy(pc,wkddct,lendd);                                       //~vau7I~//~vav0R~
//    UTRACED("xeutf8setfilenamecodetype ct",pc,lendd);              //~vau7I~//~vav0R~
//  }                                                                //~vauaI~//~vav0R~
//  return rc;                                                     //~va1CR~//~vav0R~
    return 1;                                                      //~vav0I~
}//fsubw_fileutf8setfilenamecodetype                                     //~va1BM~//~vav0R~
//**************************************************************** //~vav0I~
//enclose u8 string to UD string                                   //~vav0R~
//2:enclosing done,1:already UD fmt,0:no utf8 data                 //~vav0R~
//**************************************************************** //~vav0I~
int fsubw_U82UD(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pfnm,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~vav0R~
{                                                                  //~vav0I~
    int opt=0,rc=0,rc2,lenB,offs,wrtlen,inplen,reslen,resleno,lenu8,outlen,lendd;//~vav0R~
    int dd2u8len,swsubc;                                           //~vavcR~
    char *pc,*pco,*pcd,*pct,*pct2,*pcBsep,*pcAsep;                 //~vav0R~
    char wkdddata[_MAX_PATH*2];                                    //~vav0I~
    char wkdddbcs[_MAX_PATH*2];                                    //~vav0I~
    char wkddct[_MAX_PATH*2];                                      //~vav0I~
    char wku8[_MAX_PATHU8];                                        //~vavcI~
//*****************                                                //~vav0I~
	if (!(inplen=Plen))                                            //~vav0R~
    	inplen=strlen(Pfnm);                                       //~vav0R~
    UTRACED("inp",Pfnm,inplen);                                    //~vav0R~
    if (inplen<Pbuffsz-1 && isPrintableASCIImem(Pfnm,inplen))      //~vav0I~
    {                                                              //~vav0I~
    	memcpy(Poutbuff,Pfnm,inplen+1);                            //~vav0I~
        *Ppoutlen=inplen;                                          //~vav0I~
        return 0;                                                  //~vav0I~
    }                                                              //~vav0I~
    if (memchr(Pfnm,UD_NOTLC,inplen))	//already UD fmt           //~vav0I~
    {                                                              //~vav0I~
    	outlen=min(inplen,Pbuffsz-1);                              //~vav0I~
    	UmemcpyZ(Poutbuff,Pfnm,outlen);                            //~vav0I~
        *Ppoutlen=outlen;                                          //~vav0I~
        return 1;                                                  //~vav0I~
    }                                                              //~vav0I~
	rc2=fsubw_fileutf8setfilenamecodetype(0,Ppcw,Ppfh,Pfnm,inplen,wkdddata,wkdddbcs,wkddct,sizeof(wkdddata),&lendd);//~vav0R~//~vavcR~
    if (!rc2)	//no utf8 code                                     //~vavcI~
    {                                                              //~vavcI~
    	if (Pbuffsz<inplen+1)                                      //~vavcI~
        	return 4;                                              //~vavcI~
    	memcpy(Poutbuff,Pfnm,inplen+1);                            //~vavcI~
        *Ppoutlen=inplen;                                          //~vavcI~
        return 0;                                                  //~vavcI~
    }                                                              //~vavcI~
    for (pct=wkddct,reslen=lendd,pco=Poutbuff,resleno=Pbuffsz;reslen;)//~vav0R~
    {                                                              //~vav0I~
        offs=lendd-reslen;                                         //~vav0R~
        pc=wkdddata+offs;                                          //~vav0I~
        pcd=wkdddbcs+offs;                                         //~vav0I~
    	pct2=memchr(pct,XEUTFCT_UTF8,reslen);                      //~vav0I~
        if (!pct2)         //no utf8 data                          //~vav0I~
        {                                                          //~vav0I~
        	rc2=utfcvdd2f(opt,pc,reslen,pcd,pco,resleno,&wrtlen,NULL);//~vav0R~
            if (rc2 & UTFDD2FRC_BUFFOVERFLOW)                      //~vav0I~
            	break;                                             //~vav0I~
            pco+=wrtlen;                                           //~vav0R~
            reslen=0;                                              //~vav0I~
            break;                                                 //~vav0I~
        }                                                          //~vav0I~
        lenB=PTRDIFF(pct2,pct);	//len up to utf char               //~vav0R~
		pcBsep=utfmemrchrDD(pc,pcd,lenB,DIR_SEPC);                 //~vav0R~
        if (pcBsep)                                                //~vav0I~
        {                                                          //~vav0I~
        	lenB=PTRDIFF(pcBsep,pc)+1;  //len before starting SEPC //~vav0R~
        	rc2=utfcvdd2f(opt,pc,lenB,pcd,pco,resleno,&wrtlen,NULL/*outdbcs*/);//~vav0R~
            if (rc2 & UTFDD2FRC_BUFFOVERFLOW)                      //~vav0I~
            	break;                                             //~vav0I~
            pc+=lenB;                                              //~vav0I~
            pcd+=lenB;                                             //~vav0I~
            reslen-=lenB;                                          //~vav0I~
            pco+=wrtlen;                                           //~vav0I~
            resleno-=wrtlen;                                       //~vav0I~
        }                                                          //~vav0I~
		pcAsep=utfmemchrDD(pc,pcd,reslen,DIR_SEPC);                //~vav0R~
        if (pcAsep)                                                //~vav0I~
        	lenu8=PTRDIFF(pcAsep,pc);                              //~vav0I~
        else                                                       //~vav0I~
        	lenu8=reslen;                                          //~vav0I~
//*                                                                //~vavcI~
		rc2=ufilecvDD2U8(UFCVO_SETSUBCHRC,pc,pcd,lenu8,wku8,sizeof(wku8),pco,resleno,&dd2u8len,&wrtlen);//~vaucR~//~vavcR~
        if (rc2 && rc2!=UCVEXTRC_SUBCH)                            //~vavcI~
        	break;                                                 //~vavcI~
        swsubc=0;                                                  //~vavcI~
      if (rc2==UCVEXTRC_SUBCH)                                     //~vavcI~
      {                                                            //~vavcI~
        swsubc=1;                                                  //~vavcI~
//        if (resleno<3)                                             //~vav0R~//~vavcR~
		if (resleno<dd2u8len+3)                                    //~vavcI~
        	break;                                                 //~vav0I~
        *pco++=UD_NOTLC;                                           //~vav0I~
//        if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNU8))                  //~vav0I~//~vavcR~
//            *pco++=UD_UTF8FN;                                      //~vav0I~//~vavcR~
//        else                                                       //~vav0I~//~vavcR~
//        if (utfmemchrDD(pc,pcd,lenu8,XEUTFDD2LC_REPERR))           //~vav0R~//~vavcR~
//        if (rc2 & XEUTFF2LCRC_UTF8ERR)                           //~vavcR~
        	*pco++=UD_UTF8WCSUBC;                                  //~vav0R~
//        else                                                       //~vav0I~//~vavcR~
//            *pco++=UD_UTF8WC;                                      //~vav0R~//~vavcR~
        resleno-=2;                                                //~vav0I~//~vavcR~
//        rc2=utfcvdd2f(opt,pc,lenu8,pcd,pco,resleno,&wrtlen,NULL);  //~vav0R~//~vavcR~
//        if (rc2 & UTFDD2FRC_BUFFOVERFLOW)                          //~vav0I~//~vavcR~
//            break;                                                 //~vav0I~//~vavcR~
//        if (rc2 & XEUTFF2LCRC_UTF8ERR)                           //~vavcR~
//        {                                                        //~vavcR~
//            if (resleno<dd2u8len)                                //~vavcR~
//                break;                                           //~vavcR~
	        memcpy(pco,wku8,dd2u8len);                             //~vavcI~
    	    wrtlen=dd2u8len;                                       //~vavcI~
//        }                                                        //~vavcR~
      }                                                            //~vavcI~
        pco+=wrtlen;                                               //~vav0R~
        resleno-=wrtlen;                                           //~vav0I~
        pc+=lenu8;                                                 //~vav0M~
        reslen-=lenu8;                                             //~vav0M~
//        if (!resleno)                                              //~vav0I~//~vavcR~
//            break;                                                 //~vav0I~//~vavcR~
      if (swsubc)                                                  //~vavcI~
      {                                                            //~vavcI~
        *pco++=UD_NOTLC;                                           //~vav0I~
        resleno--;                                                 //~vav0R~
      }                                                            //~vavcI~
        rc=2;                                                      //~vav0I~
    }                                                              //~vav0I~
    outlen=PTRDIFF(pco,Poutbuff);                                  //~vav0R~
    *Ppoutlen=outlen;                                              //~vav0I~
    if (outlen<Pbuffsz)                                            //~vav0I~
        *pco=0;                                                    //~vav0I~
    if (reslen)                                                    //~vavcI~
        rc=4;                                                      //~vavcI~
    UTRACED("out",Poutbuff,outlen);                                //~vav0R~
    UTRACEP("%s:rc=%d,resleno=%d\n",UTT,rc,resleno);               //~vavcI~
    return rc;                                                     //~vav0I~
}//fsubw_U82UD                                                     //~vav0R~
#ifdef AAA                                                         //~vawwR~
//**************************************************************** //~vav0I~
//enclose u8 string to UD string using ct                          //~vavkR~
//!!! under the condition CT corresponding to U8 string            //~vaw1I~
//rc:0/4:buffovf                                                   //~vaw1I~
//**************************************************************** //~vav0I~
int fsubw_U8CT2UD(int Popt,char *Pu8,char *Pct,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~vavkR~
{                                                                  //~vav0I~
    int rc=0,len,inplen,reslen,resleno,outlen,tail,offs=0,spacectr;//~vavkR~
    char *pc,*pco,*pct,*pct2,*pc3,*pc2;                            //~vavkR~
//*****************                                                //~vav0I~
	if (!(inplen=Plen))                                            //~vav0R~
    	inplen=strlen(Pu8);                                        //~vavkR~
    UTRACED("inp u8",Pu8,inplen);                                  //~vavkR~
    UTRACED("inp ct",Pct,inplen);                                  //~vavkI~
    pc=Pu8,reslen=inplen,pco=Poutbuff,resleno=Pbuffsz-1;           //~vavkR~
    pc3=memchr(pc,' ',reslen);                                     //~vavkI~
    if (pc3)                                                       //~vavkI~
    {                                                              //~vavkI~
        offs=PTRDIFF(pc3,pc);                                      //~vavkI~
        reslen-=offs;                                              //~vavkI~
        spacectr=umemspnc(pc3,' ',reslen);                         //~vavkI~
        offs+=spacectr;                                            //~vavkI~
        pc3+=spacectr;                                             //~vavkI~
        reslen-=spacectr;                                          //~vavkI~
        pc=pc3;                                                    //~vavkI~
    }                                                              //~vavkI~
    if (*pc=='\"')                                                 //~vavkI~
    {                                                              //~vavkI~
        offs++;                                                    //~vavkI~
        pc++;                                                      //~vavkI~
        reslen--;                                                  //~vavkI~
	    pc3=memchr(pc,'\"',reslen);                                //~vavkR~
    }                                                              //~vavkI~
    else                                                           //~vavkI~
	    pc3=memchr(pc,' ',reslen);                                 //~vavkR~
    if (pc3)                                                       //~vavkI~
    	tail=PTRDIFF(Pu8+Plen,pc3);                                //~vavkI~
    else                                                           //~vavkI~
    	tail=0;                                                    //~vavkI~
    reslen-=tail;                                                  //~vavkI~
    resleno-=tail;                                                 //~vavkI~
    if (offs)                                                      //~vavkI~
    {                                                              //~vavkI~
    	memcpy(pco,Pu8,offs);                                      //~vavkI~
        resleno-=offs;                                             //~vavkI~
        pco+=offs;                                                 //~vavkI~
    }                                                              //~vavkI~
    for (;reslen;)                                                 //~vavkI~
    {                                                              //~vav0I~
    	pc2=umempbrk(pc,"\\/",reslen);                             //~vavkI~
        if (pc2)                                                   //~vavkR~
        	len=PTRDIFF(pc2,pc);	//1 path                       //~vavkI~
        else                                                       //~vavkI~
        	len=reslen;                                            //~vavkI~
        pct=Pct+PTRDIFF(pc,Pu8);                                   //~vavkR~
    	pct2=memchr(pct,XEUTFCT_UTF8,len);                         //~vavkI~
        if (pct2)                                                  //~vavkI~
        {                                                          //~vav0I~
        	if (resleno<len+3)                                     //~vavkI~
            	break;                                             //~vavkI~
            *pco++=UD_NOTLC;                                       //~vavkI~
            *pco++=UD_UTF8WC;                                      //~vavkI~
            memcpy(pco,pc,len);                                    //~vavkI~
            pco+=len;                                              //~vavkI~
            *pco++=UD_NOTLC;                                       //~vavkI~
            resleno-=len+3;                                        //~vavkI~
        }                                                          //~vavkI~
        else                                                       //~vavkI~
        {                                                          //~vavkI~
        	if (resleno<len)                                       //~vavkI~
            	break;                                             //~vavkI~
            memcpy(pco,pc,len);                                    //~vavkI~
            pco+=len;                                              //~vavkI~
            resleno-=len;                                          //~vavkI~
        }                                                          //~vavkI~
        reslen-=len;                                               //~vaw1I~
        if (!pc2)                                                  //~vavkR~
        	break;                                                 //~vavkI~
        if (!resleno)                                              //~vavkI~
        	break;                                                 //~vavkI~
        *pco++=DIR_SEPC;                                           //~vavkI~
        resleno--;                                                 //~vavkI~
        pc=pc2+1;                                                  //~vavkI~
//      reslen-=len+1;                                             //~vavkI~//~vaw1R~
        reslen--;                                                  //~vaw1I~
    }                                                              //~vav0I~
    if (tail)                                                      //~vavkI~
    {                                                              //~vavkI~
	    memcpy(pco,Pu8+Plen-tail,tail);                            //~vavkI~
        pco+=tail;                                                 //~vavkI~
    }                                                              //~vavkI~
    *pco=0;                                                        //~vavkI~
    outlen=PTRDIFF(pco,Poutbuff);                                  //~vav0R~
    *Ppoutlen=outlen;                                              //~vav0I~
    if (reslen)                                                    //~vavcI~
        rc=4;                                                      //~vavcI~
    UTRACED("out",Poutbuff,outlen);                                //~vav0R~
    UTRACEP("%s:rc=%d,resleno=%d\n",UTT,rc,resleno);               //~vavcI~
    return rc;                                                     //~vav0I~
}//fsubw_U8CT2UD                                                   //~vavkR~
#else   //AAA                                                      //~vawvI~//~vawwR~
//**************************************************************** //~vawvI~//~vawwR~
//enclose u8 string to UD string using ct                          //~vawvI~//~vawwR~
//from funccmdstack_utf8 only                                      //~vawvI~//~vawwR~//~vbi4R~
//rc:0/4:buffovf                                                   //~vawvI~//~vawwR~
//**************************************************************** //~vawvI~//~vawwR~
int fsubw_U8CT2UD(int Popt,char *Pu8,char *Pct,int Plen,int Pctlen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~vawvI~//~vawwR~
{                                                                  //~vawvI~//~vawwR~
    int rc,inplen,outlen,opt;                                      //~vawvI~//~vawwR~
//*****************                                                //~vawvI~//~vawwR~
    if (!(inplen=Plen))                                            //~vawvI~//~vawwR~
        inplen=strlen(Pu8);                                        //~vawvI~//~vawwR~
    UTRACED("inp u8",Pu8,inplen);                                  //~vawvI~//~vawwR~
    UTRACED("inp ct",Pct,Pctlen);                                  //~vawvI~//~vawwR~
    if (memchr(Pu8,UD_NOTLC,inplen))	//already UD fmt           //~vawwI~
    {                                                              //~vawwI~
        outlen=min(Pbuffsz,inplen);                                //~vawwI~
        UmemcpyZ(Poutbuff,Pu8,outlen);                             //~vawwI~
        rc=1;                                                      //~vawwI~
    }                                                              //~vawwI~
    else                                                           //~vawwI~
    {                                                              //~vawwI~
    	opt=UFCVO_ENCUTF8WC;       //not enclose f2l err only          //~vawvI~//~vawwR~
    	opt|=UFCVO_ERRREPDBCS;     //set dbcs subchar for f2l err  //~vbi4I~
    	rc=ufilecvU8CT2UD(opt,Pu8,Pct,Pctlen,Poutbuff,Pbuffsz,&outlen);//~vawvI~//~vawwR~
    	if (rc>=4)                                                    //~vawvI~//~vawwR~
        	UmemcpyZ(Poutbuff,Pu8,min(Pbuffsz,inplen));                   //~vawvI~//~vawwR~
    }                                                              //~vawwI~
    if (Ppoutlen)                                                  //~vawvI~//~vawwR~
        *Ppoutlen=outlen;                                          //~vawvI~//~vawwR~
    UTRACED("out",Poutbuff,outlen);                                //~vawvI~//~vawwR~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~vawvI~//~vawwR~
    return rc;                                                     //~vawvI~//~vawwR~
}//fsubw_U8CT2UD                                                   //~vawvI~//~vawwR~
#endif //!AAA                                                      //~vawvI~//~vawwR~
//**************************************************************** //~vavQR~
//enclose u8 string to UD string using ct                          //~vavQR~
//opdno:0 start                                                    //~vavQR~
//**************************************************************** //~vavQR~
int fsubw_cmdopdU8CT2UD(int Popt,PUCLIENTWE Ppcw,int Popdno,char *Popd,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~vavQR~
{                                                                  //~vavQR~
    int rc,opdlclen,outlen,ii,opt;                                 //~vavQR~
    char *plc,*pct,*pu8,*pc,*outbuff;                                           //~vavQR~//~vaw1R~
    int buffsz;                                                    //~vaw1I~
//*****************                                                //~vavQR~
	rc=funcgetOpdLCCT(0,Ppcw,Popdno,&plc,&pct,&opdlclen);          //~vavQR~
    if (rc)                                                        //~vavQR~
    	return 4;                                                  //~vavQR~
    if (!memchr(pct,XEUTFCT_UTF8,opdlclen))                        //~vavQR~
    	return 4;                                                  //~vavQR~
    if (!(pu8=Popd))                                               //~vavQR~
    {                                                              //~vavQR~
    	pu8=Ppcw->UCWopdpot;                                       //~vavQR~
		for (ii=0;ii<Popdno;ii++)	//next operand addr            //~vavQR~
			pu8+=strlen(pu8)+1;	//next operand addr                //~vavQR~
    }                                                              //~vavQR~
    if (!pu8)                                                      //~vawvR~
    	return 4;                                                  //~vawvR~
    if (Popt & FSWCOU8CT2UDO_PARTIAL)       //opd is partial of fpath//~vawvR~
    {                                                              //~vawvR~
//*this may fail when full path is from *\xx (*\ dose not containd in fullpath)z//~vawvR~
    	pc=strstr(Poutbuff,Popd);                                  //~vawvR~
                                                                   //~vawvR~
        if (!pc)                                                   //~vawvR~
        	return 4;                                              //~vawvR~
         outbuff=pc;                                               //~vawvR~
         buffsz=Pbuffsz-PTRDIFF(pc,Poutbuff);                      //~vawvR~
    }                                                              //~vawvR~
    else                                                           //~vawvR~
    	outbuff=Poutbuff,buffsz=Pbuffsz;                           //~vawvR~
    opt=0;                                                         //~vavQI~
	if (Popt & FSWCOU8CT2UDO_UTF8WC)  //enclose all utf8(not f2l err only)//~vavQI~
    	opt|=UFCVO_ENCUTF8WC;			//  0x8000       //enclose all utf8//~vavQI~
//  rc=ufilecvU8CT2UD(opt,pu8,pct,opdlclen,Poutbuff,Pbuffsz,&outlen);//~vavQR~//~vawvR~
    rc=ufilecvU8CT2UD(opt,pu8,pct,opdlclen,outbuff,buffsz,&outlen);//~vawvR~
    if (rc>=4)                                                     //~vavQR~
    	return 4;                                                  //~vavQR~
    if (Ppoutlen)                                                  //~vavQR~
    	*Ppoutlen=outlen;                                          //~vavQR~
    return rc;                                                     //~vavQR~
}//fsubw_cmdopdU8CT2UD                                             //~vavQR~
//**************************************************************** //~vavQR~
//enclose u8 string to UD string using ct                          //~vavQR~
//rc:1:UD found                                                    //~vavQR~
//**************************************************************** //~vavQR~
int fsubw_cmdopdU8CT2UDX(int Popt,PUCLIENTWE Ppcw,int Popdno,char *Popd,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~vavQR~
{                                                                  //~vavQR~
    char wkud[_MAX_PATH];                                          //~vavQR~
    int outlen,rc,udlen;                                           //~vavQR~
//*****************                                                //~vavQR~
	rc=fsubw_cmdopdU8CT2UD(Popt,Ppcw,Popdno,Popd,wkud,sizeof(wkud),&udlen);//~vavQR~
    if (rc!=1)  //not enclosed                                     //~vavQR~
    	return rc;                                                 //~vavQR~
	rc=ufilecvUD2UDX(UFCVO_STRZ,wkud,udlen,Poutbuff,Pbuffsz,&outlen);//~vavQR~
    if (Ppoutlen)                                                  //~vavQR~
    	*Ppoutlen=outlen;                                          //~vavQR~
    UTRACED("out udx",Poutbuff,outlen);                            //~vavQR~
    return rc;                                                     //~vavQR~
}//fsubw_cmdopdU8CT2UD                                             //~vavQR~
//**************************************************************** //~vavkI~
//from funcsetlongcmdfromstack/fileutf8setfilenamecodetype         //~vavkR~
//strip UD string                                                  //~vavkI~
//outct is optional,set XEUTFCT_UTF8 to UTF8 char only                                                //~vavkI~//~vavpR~
//rc:1 input is ud string                                          //~vavkI~
//**************************************************************** //~vavkI~
int fsubw_stripUDCT(int Popt,char *Pud,int Plen,char *Pu8,int Pbuffsz,char *Poutct,int Poutctsz,int *Ppoutlen)//~vavkR~
{                                                                  //~vavkI~
	int outlen,rc;                                                 //~vavkR~
//********************                                             //~vavkI~
    UTRACED("inp ud",Pud,Plen);                                    //~vavkI~
	if (!(memchr(Pud,UD_NOTLC, Plen)))                             //~vavkR~
    	return 0;                                                  //~vavkI~
	rc=ufilecvstripUD(UFCVO_STRZ,Pud,Plen,Pu8,Pbuffsz,&outlen,Poutct,Poutct);//~vavkR~//~vavpR~
  if (Ppoutlen)                                                    //~vaw1I~
    *Ppoutlen=outlen;                                              //~vavkR~
    UTRACED("out u8",Pu8,outlen);                                  //~vavkR~
    UTRACED("out dd",Poutct,outlen);                               //~vavkI~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~vavkI~
    return rc;                                                     //~vavkI~
}//fsubw_stripUDCT                                                 //~vavkR~
//**************************************************************** //~vavkI~
//get lc to Gcmdbufflc from UD,from funcrcmdstack                  //~vavkI~
//rc:1 input is ud string,strp and cv2lc                           //~vavkR~
//**************************************************************** //~vavkI~
int fsubw_UD2LC(int Popt,char *Pud,int Plen,char *Plc,int Pbuffsz,int *Ppoutlen)//~vavkI~
{                                                                  //~vavkI~
	int outlen,rc2;                                                //~vavkR~
    int opt=0;                                                     //~vb4bI~
    int buffsz,ddlen;                                              //~vbi4I~
    char *pdata,*pdbcs,*pct;                                       //~vbi4R~
//********************                                             //~vavkI~
    UTRACED("inp ud",Pud,Plen);                                    //~vavkI~
	if (!(memchr(Pud,UD_NOTLC, Plen)))                             //~vavkI~
    {                                                              //~vavkI~
    	return 0;                                                  //~vavkI~
    }                                                              //~vavkI~
#ifdef AAA                                                         //~vbi4I~
//  rc2=ufilecvUD2LC(0,Pud,Plen,Plc,Pbuffsz,&outlen);              //~vavkR~//~vb4bR~
	if (Popt & FSWUD2LCO_NOMSG)   //    0x01                       //~vb4bI~
    	opt|=UFCUD2LCO_NOMSG;	//  0x01                           //~vb4bI~
    rc2=ufilecvUD2LC(opt,Pud,Plen,Plc,Pbuffsz,&outlen);            //~vb4bI~
    if (rc2>=UDRC_ERR)                                             //~vavkR~
    	return 0;                                                  //~vavkI~
#else                                                              //~vbi4I~
    buffsz=Plen;                                                   //~vbi4R~
    pdata=xeutf_buffget(XEUTF_BUFF3,buffsz*3);                     //~vbi4I~
    UALLOCCHK(pdata,UALLOC_FAILED);                                //~vbi4R~
    pdbcs=pdata+buffsz;                                            //~vbi4I~
    pct=pdbcs+buffsz;                                              //~vbi4I~
    rc2=fsubw_UD2DD(opt,Pud,Plen,pdata,pdbcs,Pbuffsz,&ddlen);      //~vbi4R~
    if (rc2)                                                       //~vbi4I~
    	return 0;                                                  //~vbi4I~
	xeutfcvdd2lc(opt,pdata,ddlen,pdbcs,Plc,pct,Pbuffsz,&outlen);   //~vbi4R~
#endif                                                             //~vbi4I~
    if (Ppoutlen)                                                  //~vavkI~
	    *Ppoutlen=outlen;                                          //~vavkR~
    UTRACED("out lc",Plc,outlen);                                  //~vavkR~
    return 1;                                                      //~vavkR~
}//fsubw_UD2LC                                                     //~vavkR~
//**************************************************************** //~vavQR~
//get lc to Gcmdbufflc from UD,from funcrcmdstack                  //~vavFI~
//**************************************************************** //~vavFI~
int fsubw_UD2DD(int Popt,char *Pud,int Plen,char *Pdddata,char *Pdddbcs,int Pbuffsz,int *Ppoutlen)//~vavFI~
{                                                                  //~vavFI~
	int outlen,rc2,ucsctr;                                         //~vavFI~
    UWCH wkwc[_MAX_PATHWC];                                        //~vavFI~
//********************                                             //~vavFI~
    UTRACED("inp ud",Pud,Plen);                                    //~vavFI~
	rc2=ufilecvUD2WCnopath(0,Pud,wkwc,sizeof(wkwc),&ucsctr);       //~vavFI~
    if (rc2>=UDRC_ERR)                                             //~vavFR~
    	return rc2;                                                //~vavFI~
    utf162dd(0,wkwc,ucsctr,Pdddata,Pdddbcs,Pbuffsz,&outlen);       //~vavFI~
    if (Ppoutlen)                                                  //~vavFI~
    	*Ppoutlen=outlen;                                          //~vavFI~
    UTRACED("out dddata",Pdddata,outlen);                          //~vavFI~
    UTRACED("out dddbcs",Pdddbcs,outlen);                          //~vavFI~
    return 0;                                                      //~vavFR~
}//fsubw_UD2DD                                                     //~vavFI~//~vawwR~
//*******************************************************          //~v09YI~//~vavnI~
//*dbcs tbl output for ddfmt                                       //~vavnI~
//*******************************************************          //~v09YI~//~vavnI~
int fsubw_setdbcstblDD(int Popt,UCHAR *Pdddata,UCHAR *Pdddbcs,int Pddlen,char *Poutbuff,int Pbuffsz)//~vavnI~
{                                                                  //~v09YI~//~vavnI~
    UCHAR *pc,*pcd,*pcdo;                                              //~v74xI~//~vavnR~
	int dbcsid,reslen,resleno,chsz;                                                  //~va1cR~//~vavnR~
//  WUCS ucs2;                                                     //~vavnR~//~vaw1R~
    UWUCS ucs2;                                                    //~vaw1I~
//***************                                                  //~v09YI~//~vavnI~
UTRACED("inp dddata",Pdddata,Pddlen);                              //~vavnI~
UTRACED("inp dddbcs",Pdddbcs,Pddlen);                              //~vavnI~
	for (pc=Pdddata,pcd=Pdddbcs,pcdo=Poutbuff,resleno=Pbuffsz,reslen=Pddlen;reslen && resleno;pc++,pcd++,pcdo++,reslen--,resleno--)//~vavnI~
    {                                                              //~vavnI~
    	*pcdo=0;	//default sbcs                                 //~vavnI~
    	dbcsid=*pcd;                                               //~vavnI~
    	if (!dbcsid)	//ascii                                    //~vavnI~
        	continue;	                                           //~vavnI~
        ucs2=utfdd2u1chsz(0,pc,pcd,reslen,&chsz);	//if split chsz=-1;//~vavnI~
        if (chsz<0)	//unprintable                                  //~vavnR~
        	chsz=-chsz;                                            //~vavnR~
        if (chsz==1)                                               //~vavnR~
        	continue;                                              //~vavnI~
//        if (!IS_UTF16_HIGH(ucs2)||reslen<4) //surrogate pair     //~vavnR~
        {                                                          //~vavnI~
        	*pcdo++=UDBCSCHK_DBCS1ST;                              //~vavnI~
        	*pcdo=UDBCSCHK_DBCS2ND;                                //~vavnI~
            pc++;                                                  //~vavnI~
            pcd++;                                                 //~vavnI~
            reslen--;                                              //~vavnI~
            resleno--;                                             //~vavnI~
        }                                                          //~vavnI~
//        *pcdo++=UDBCSCHK_DBCS1ST;                                //~vavnR~
//        *pcdo++=UDBCSCHK_DBCSPAD;                                //~vavnR~
//        *pcdo++=UDBCSCHK_DBCSPAD;                                //~vavnR~
//        *pcdo=UDBCSCHK_DBCS2ND;                                  //~vavnR~
//        pc+=3;                                                   //~vavnR~
//        pcd+=3;                                                  //~vavnR~
//        reslen-=3;                                               //~vavnR~
//        resleno-=3;                                              //~vavnR~
    }                                                              //~vavnI~
UTRACED("out dbcstbl",Poutbuff,PTRDIFF(pcdo,Poutbuff));                 //~va1cR~//~vavnI~
    return 0;                                                      //~v44aR~//~vavnI~
}//fsubw_setdbcstblDD                                              //~vavnI~
//*******************************************************          //~vavpI~
//*set field by dd fmt data(except cmdline)                        //~vavpI~
//*from pan300updatelist ,drop UD id                               //~vavpR~
//*******************************************************          //~vavpI~
int fsubw_setflddatadd(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)//~vavpR~
{                                                                  //~vavpI~
    char wkdddata[_MAX_PATH],*pdddata;                             //~vavpR~
    char wkdddbcs[_MAX_PATH],*pdddbcs;                             //~vavpR~
    int ddlen,wrtlen,rc;                                           //~vavpR~
//************************                                         //~vavpI~
	UTRACED("inp dddata",Pdata,Plen);                              //~vavpI~
	UTRACED("inp dddbcs",Pdbcs,Plen);                              //~vavpI~
    pdddata=Pdata;                                                 //~vavpI~
    pdddbcs=Pdbcs;                                                 //~vavpI~
    ddlen=Plen;                                                    //~vavpI~
	if (utfddmemchr(0,Pdata,Pdbcs,UD_NOTLC,Plen))	//UD fmt       //~vavpI~
    {                                                              //~vavpI~
		rc=ufilecvUDD2DD(0,Pdata,Pdbcs,NULL/*ct*/,Plen,wkdddata,wkdddbcs,NULL,sizeof(wkdddata),&wrtlen);//~vavpR~
        if (rc==1)	//detected ud fmt                              //~vavpI~
        {                                                          //~vavpI~
        	ddlen=wrtlen;                                          //~vavpI~
            pdddata=wkdddata;                                      //~vavpI~
            pdddbcs=wkdddbcs;                                      //~vavpI~
			UTRACED("strip dddata",pdddata,ddlen);                 //~vavpI~
			UTRACED("strip dddbcs",pdddbcs,ddlen);                 //~vavpI~
        }                                                          //~vavpI~
    }                                                              //~vavpI~
	rc=setflddatadd(Popt,Ppcw,Prow,Pfldno,pdddata,pdddbcs,ddlen);  //~vavpI~
    return rc;                                                     //~vavpI~
}//fsubw_setflddatadd                                              //~vavpR~
//**************************************************************** //~vbkcI~
//get lc to Gcmdbufflc from UD,from funcrcmdstack                  //~vbkcI~
//**************************************************************** //~vbkcI~
int fsubw_UD2U8(int Popt,char *Ppud,int Plen,char *Ppu8,int Pbuffsz,int *Ppoutlen)//~vbkcR~
{                                                                  //~vbkcI~
	int outlen,rc2,buffsz,ddlen,opt;                               //~vbkcR~
    char *pdata,*pdbcs;                                            //~vbkcI~
//********************                                             //~vbkcI~
    UTRACED("inp ud",Ppud,Plen);                                   //~vbkcR~
    buffsz=Plen;                                                   //~vbkcI~
    pdata=xeutf_buffget(XEUTF_BUFF3,buffsz*2);                     //~vbkcI~
    UALLOCCHK(pdata,UALLOC_FAILED);                                //~vbkcI~
    pdbcs=pdata+buffsz;                                            //~vbkcI~
    rc2=fsubw_UD2DD(0,Ppud,Plen,pdata,pdbcs,buffsz,&ddlen);        //~vbkcI~
    if (rc2)                                                       //~vbkcR~
    	return rc2;                                                //~vbkcI~
    opt=UTFDD2FO_OUTSTRZ;                                          //~vbkcR~
	rc2=utfcvdd2f(opt,pdata,ddlen,pdbcs,Ppu8,Pbuffsz,&outlen,0/*Ppoutdbcs*/);//~v640R~//~vbkcI~
    if (rc2>=UTFDD2FRC_ERR)                                        //~va20I~//+vbkcI~
    	return rc2;                                                //~vbkcI~
    if (Ppoutlen)                                                  //~vbkcI~
    	*Ppoutlen=outlen;                                          //~vbkcI~
    UTRACED("out u8",Ppu8,outlen);                                 //~vbkcR~
    return 0;                                                      //~vbkcI~
}//fsubw_UD2DD                                                     //~vbkcI~
