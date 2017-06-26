//CID://+vb2DR~:                                      Update#=  529//+vb2DR~
//*************************************************************
//*xefile15.c*                                                     //~v0baR~//~va6FR~
//**renum,spf                                                 //~v0duR~//~va6FR~
//*************************************************************
//vb2D:160221 LNX compiler warning                                 //+vb2DI~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //~vaz0I~
//vagm:120825 (BUG)binfile width change;UUHTWIDTH & UUHTREP is different undoctr(2step undo/redo)//~vagmI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va79:100809 cpeb converter parm support                          //~va79I~
//va6F:100719 split xefile15 from xefile12                         //~va6FR~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
    #ifdef DPMI					//DPMI version                     //~v095I~
        #include <errno.h>                                         //~v095I~
    #else                       //not DPMI                         //~v095I~
    #endif                      //DPMI or not                      //~v095I~
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <ualloc.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318I~
#include <ufile2.h>
#include <ufile3.h>                                                //~v57NI~
#include <uparse.h>                                                //~v0b2R~
#include <uedit.h>                                                 //~v0clI~
#include <ustring.h>                                               //~v40FI~
#include <uftp.h>                                                  //~v54pI~
#ifdef UTF8UCS2                                                    //~va20I~
#include <udbcschk.h>                                              //~va20I~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20I~
#include <ucvebc.h>                                                //~va50I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"                                                //~v53UI~
#include "xefile.h"
#include "xefile12.h"                                              //~v0clI~
#include "xefile14.h"                                              //~v54dI~
#include "xefile2.h"                                               //~v40hI~
#include "xefile22.h"                                              //~v445I~
#include "xefile4.h"                                            //~4C23R~
#include "xefile5.h"                                               //~v08qI~
#include "xefile6.h"                                               //~v0e7I~
#include "xefile7.h"    //filefksave                               //~v0ifI~
#include "xedir.h"    //filefksave                                 //~v716I~
#include "xefcmd.h"                                                //~v0iaI~
#include "xefsub.h"                                             //~5318I~
#include "xesub.h"                                              //~5318I~
#include "xeundo.h"                                                //~v0clI~
#include "xeopt.h"                                                 //~v506I~
#ifdef FTPSUPP                                                     //~v53UI~
	#include "xeftp.h"                                             //~v53UR~
	#include "xetso.h"                                             //~v716I~
#endif                                                             //~v53UI~
#ifdef UTF8SUPPH                                                   //~va1EI~
	#include "xeutf.h"                                             //~va1EI~
#endif                                                             //~va1EI~
#ifdef UTF8UCS2                                                    //~va20I~
	#include "xecap2.h"                                            //~va20I~
	#include "xesub2.h"                                            //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
void filespfseqerr(void);                                          //~v0clR~
void filespfvermaxerr(int Pver,int Plimit);                        //~v0clR~
int filenotspferr(void);                                           //~v0clI~
int filespfvererr(void);                                           //~v0clI~
int filespfver(int Pver);                                          //~v0clI~
int filespfneedforce(void);                                        //~v0ctI~
void filespfnumerr(void);                                          //~v0ctI~
void filespferrnotspace(void);                                     //~v42vI~
void filespflenerr(int Plen);                                      //~v0ctI~
void filespfcobnumerr(void);                                       //~v61gI~
//**************************************************************** //~v0ibI~
//**************************************************************** //~v074I~
// filerenum                                                       //~v074I~
//*renumber line number and free undo stack                        //~v074I~
//*parm1 :pcw                                                      //~v074I~
//*parm2 :pfh                                                      //~v074I~
//*parm3 :option 0:normal,1:force option                           //~v0ctI~
//*parm4 :num fld and delm char(0+col1+col2+delmchar)              //~v506I~
//*return:rc                                                       //~v0cnR~
//**************************************************************** //~v074I~
int filerenum(PUCLIENTWE Ppcw,UFILEH *Ppfh,int Popt,ULONG Pnumfld) //~v506R~
{                                                                  //~v074I~
	LONG  lineno=0;                                                //~v074I~
	PUQUEH qh;                                                     //~v074I~
	PULINEH plh;                                                   //~v074I~
	PULINEH plh1st=0;                                              //~v0cnR~
    int suffix=0;                                                  //~v0aiI~
    int spfsw,newlen,datasw;                                       //~v0cnR~
    int spferrsw;                                                  //~v0ctI~
    int lenerrsw;                                                  //~v0cnR~
    int clearsw,xlinenosw,cobsw;                                   //~v40TR~
    int rc;                                                        //~v0cnI~
    int cobclearsw;                                                //~v420I~
    int donectr=0;                                                 //~v412I~
    int nonumsw;                                                   //~v42uI~
    int spfpos;                                                    //~v413I~
    int cobkrenumsw=0,cobkclearsw=0;                               //~v47AR~
    int setrinorenumsw=0;		//seti/setr without renum          //~v53dI~
//  int numfldcol,numfldlen,numdelmfldlen,len,numfldcole,delmch,setrisw=0,maxfldsz;//~v506R~//~vaf9R~
    int numfldcol=0,numfldlen=0,numdelmfldlen=0,len,numfldcole=0,delmch=0,setrisw=0,maxfldsz;//~vaf9I~//~vafcR~
    UCHAR renumonlysw=0,svreason;  //to avoid version-no up by renum//~v71ZR~
    char *pdata,*pdbcs,*pc;                                        //~v506R~
//  ULONG offs;                                                    //~vaz0R~
    FILESZT offs;                                                  //~vaz0I~
//  char wkedit2[8];                                               //~vaz0R~
    char wkedit2[16];                                              //~vaz0I~
//  char wkedit3[16];                                              //~vaz0R~
    char wkedit3[32];                                              //~vaz0I~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	int cutctr=0,margin,fixlrecl,swmargincut;                      //~va53R~
//*********************************                                //~v074I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20R~
    handle=Ppfh->UFHhandle;                                        //~va79I~
#endif                                                             //~va20I~
    if (UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN))                      //~va53I~
		margin=Ppfh->UFHmergin;                                    //~va53R~
    else                                                           //~va53I~
    	margin=0;                                                  //~va53I~
    if (UCBITCHK(Ppfh->UFHflag7,UFHF7FIXLRECL))                    //~va53I~
    	fixlrecl=Ppfh->UFHlrecl;                                   //~va53R~
    else                                                           //~va53I~
    	fixlrecl=0;                                                //~va53R~
	qh=&(Ppfh->UFHlineque);                                        //~v074I~
	plh=(PULINEH)UGETQTOP(qh);                                     //~v074I~
  if (!(Popt & RENUMOPT_NOUPCTR))                                  //~vagmI~
    UPCTRREQ(Ppfh);         //write at save                        //~v0cnI~
    if (Popt & RENUMOPT_COBK)                                      //~v47AI~
    {                                                              //~v47AI~
        if (!UCBITCHK(Ppfh->UFHflag5,UFHF5COB2))                   //~v47AI~
        {                                                          //~v47AI~
        	uerrmsg("K option is valid only for COBK file",        //~v47AI~
        	        "K オプションは COBK ファイルにのみ有効");     //~v47AR~
            return 4;                                              //~v47AI~
        }                                                          //~v47AI~
		if (Popt & RENUMOPT_CLEAR)                                 //~v47AI~
 			cobkclearsw=SETSPFNUM_COB;		//clear cob fld        //~v47AI~
        else                                                       //~v47AI~
 			cobkrenumsw=SETSPFNUM_COBKRENUM;                       //~v47AR~
    }                                                              //~v47AI~
    if (Popt & (RENUMOPT_SETR|RENUMOPT_SETI))                      //~v506I~
    {                                                              //~v506I~
        if (UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR)) //~v506I~
        {                                                          //~v506M~
        	uerrmsg("This file is line-numbered file.",            //~v506M~
        	        "このファイルは行番号欄有りのファイルです。"); //~v506M~
            return 4;                                              //~v506M~
        }                                                          //~v506M~
    	if (Popt & RENUMOPT_SETR)                                  //~v506I~
        	setrisw='R';		//SETR id	                       //~v506I~
        else                                                       //~v506I~
        	setrisw='I';		//SETI id                          //~v506I~
        numfldcol=(int)(Pnumfld>>16)-1;        	//num fld start col//~v50tR~
        numfldlen=(int)((Pnumfld>>8)&255)-numfldcol;      //end col//~v50tR~
        delmch=(int)(Pnumfld&255);         //delm char             //~v50tR~
        numdelmfldlen=numfldlen+(delmch!=0);                       //~v506I~
        numfldcole=numfldcol+numdelmfldlen;	//next col pos         //~v506I~
        setrinorenumsw=!(Popt & RENUMOPT_RENUM);                   //~v53dI~
    }                                                              //~v506I~
//  clearsw=((Popt & RENUMOPT_CLEAR) ? SETSPFNUM_CLEAR : 0);       //~v42uR~
//  cobclearsw=((Popt & RENUMOPT_COB) ? SETSPFNUM_COB : 0);        //~v42uR~
	nonumsw=UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM);  //no use col72-80//~v42uR~
    clearsw=   (((Popt & RENUMOPT_CLEAR) && !nonumsw)              //~v42uR~
 				? SETSPFNUM_CLEAR : 0);//col72 clear option        //~v42uI~
    cobclearsw=(((Popt & RENUMOPT_CLEAR) && UCBITCHK(Ppfh->UFHflag5,UFHF5COB)//~v45vR~
                  && !UCBITCHK(Ppfh->UFHflag5,UFHF5COB2))          //~v45vI~
 				? SETSPFNUM_COB : 0);                              //~v42uI~
    spferrsw=UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMERR);              //~v0ctI~
    if (spferrsw)	//err at load                                  //~v0ctI~
//  	if (!Popt)	//force option                                 //~v40FR~
    	if (!(Popt & RENUMOPT_FORCE))	//force option             //~v40FI~
        	return filespfneedforce();                             //~v0ctI~
    spfsw=UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK);                  //~v0cnR~
    spfsw|=spferrsw;                                               //~v0ctR~
    cobsw=UCBITCHK(Ppfh->UFHflag5,UFHF5COB);  //cobol spf file     //~v45vI~
//  if (spfsw)                                                     //~v47AR~
//  	newlen=Ppfh->UFHlrecl;                                     //~v47AR~
//  else                                                           //~v47AR~
    if (!spfsw)                                                    //~v47AI~
//  	if (clearsw)                                               //~v45vR~
        if (Popt & RENUMOPT_CLEAR)                                 //~v45vI~
        {	                                                       //~v40FM~
          if (cobsw)                                               //~v45vI~
          {                                                        //~v47AI~
           if (!cobkclearsw)                                       //~v47AI~
           {                                                       //~v47AI~
            uerrmsg("No num fld defined COBOL file.Use K option to clear COB-SEQNO fld",//~v47AR~
                    "行番号欄無しのCOBOLファイルです。Kオプションで行番号クリアー。");//~v47AR~
            return 4;                                              //~v47AI~
           }                                                       //~v47AI~
          }                                                        //~v47AI~
          else                                                     //~v45vI~
          {                                                        //~v47AI~
        	uerrmsg("CLEAR option is valid for file with line number.",//~v40FM~
            		"CLEAR オプションは行番号付ファイルにのみ有効");//~v40FM~
            return 4;                                              //~v40FM~
          }                                                        //~v47AI~
        }                                                          //~v40FM~
//  offs=(ULONG)Ppfh->UFHslinepos;	//start offset                 //~vaz0R~
    offs=Ppfh->UFHslinepos;	//start offset                         //~vaz0I~
  	xlinenosw=UCBITCHK(Ppfh->UFHflag4,UFHF4XLINENO);               //~v40TR~
    if (setrisw)                                                   //~v506I~
    {                                                              //~v506I~
        if (xlinenosw)                                             //~v506I~
	    	if (UCBITCHK(Goptopt,GOPT_HEX_UPPER))	//if alias on  //~v506I~
//  		    sprintf(wkedit2,"%%0%dlX%c",numfldlen,delmch);     //~vaz0R~
    		    sprintf(wkedit2,"%%0%d" FILESZ_EDIT "X%c",numfldlen,delmch);//~vaz0I~
            else                                                   //~v506I~
//  		    sprintf(wkedit2,"%%0%dlx%c",numfldlen,delmch);     //~vaz0R~
    		    sprintf(wkedit2,"%%0%d" FILESZ_EDIT "x%c",numfldlen,delmch);//~vaz0I~
        else                                                       //~v506I~
    	    sprintf(wkedit2,"%%0%dld%c",numfldlen,delmch);         //~v506R~
        maxfldsz=8;                                                //~v506I~
#ifdef LFSSUPP                                                     //~vaz0I~
        if (xlinenosw)                                             //~vaz0I~
        	maxfldsz=16;    //long long                            //~vaz0I~
#endif                                                             //~vaz0I~
        if (numfldlen<1||numfldlen>maxfldsz)                       //~v506R~
        {                                                          //~v506M~
        	uerrmsg("Number field size(%d) err(1-%d).",            //~v506R~
        	        "行番号フィールドサイズ(%d) エラー。(1-%d)",   //~v506R~
					numfldlen,maxfldsz);                           //~v506R~
            return 4;                                              //~v506M~
        }                                                          //~v506M~
        if (delmch=='%')                                           //~v506I~
            strcat(wkedit2,"%");                                   //~v506R~
    }                                                              //~v506I~
//  cobsw=UCBITCHK(Ppfh->UFHflag5,UFHF5COB);  //cobol spf file     //~v45vR~
//  if (cobclearsw && !cobsw)                                      //~v42vR~
//  {                                                              //~v42vR~
//      uerrmsg("CLEAR C option is valid for COBOL file.",         //~v42vR~
//              "CLEAR C オプションはCOBOLファイルにのみ有効");    //~v42vR~
//      return 4;                                                  //~v42vR~
//  }                                                              //~v42vR~
//  if (cobsw)                                                     //~v45vR~
//    if (!(Popt & RENUMOPT_CLEAR))		//renum cmd                //~v45vR~
//    if (!(Popt & RENUMOPT_CLEAR)		//renum cmd                //~v45vR~
//    ||   (!clearsw && !cobclearsw))                              //~v45vR~
//  	if (nonumsw && UCBITCHK(Ppfh->UFHflag5,UFHF5COB2))  //cob has no num fld//~v45vR~
//  	{                                                          //~v45vR~
//      	uerrmsg("No num fld defined COBOL file.",              //~v45vR~
//              	"行番号欄が定義されていないCOBOLファイルです。");//~v45vR~
//      	return 4;                                              //~v45vR~
//  	}                                                          //~v45vR~
	spfpos=Ppfh->UFHspfpos;                                        //~v413I~
	while(plh)                                                     //~v074I~
	{                                                              //~v074I~
    	if (setrinorenumsw)		//seti/setr without renum          //~v53dI~
        {                                                          //~v53dI~
            lineno=plh->ULHlinenor; //use current value            //~v53dI~
            suffix=plh->ULHsuffix;                                 //~v53dI~
            offs=plh->ULHoffs;                                     //~v53dI~
        }                                                          //~v53dI~
		if (spfsw)                                                 //~v47AI~
			newlen=Ppfh->UFHlrecl;                                 //~v47AI~
        else                                                       //~v47AI~
			newlen=max(plh->ULHlen,SPFCOBNUMFLDLEN);               //~v47AR~
        if (plh->ULHtype==ULHTDATA)                                //~v074I~
        {                                                          //~v0cnI~
//          if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))               //~v0cnR~
//            suffix++;                                            //~v0cnR~
//          else                                                   //~v0cnR~
//          {                                                      //~v0cnR~
//            ++lineno;                                            //~v0cnR~
//            suffix=0;                                            //~v0cnR~
//          }                                                      //~v0cnR~
          datasw=1;                                                //~v0cnI~
//        if (spfsw && !clearsw)                                   //~v42uR~
          if (spfsw && !clearsw && !cobclearsw)                    //~v42uI~
//            lenerrsw=(newlen!=plh->ULHlen);                      //~v0e7R~
              lenerrsw=!fileisvalidspfline(Ppfh,plh,0);            //~v0e7I~
		  else	                                                   //~v0cnI~
	          lenerrsw=0;                                          //~v0cnI~
		}                                                          //~v0cnI~
        else                                                       //~v0cnI~
          lenerrsw=                                                //~v0cnR~
          datasw=0;                                                //~v0cnR~
      if (datasw)  //data line                                     //~v40FR~
      {//datasw                                                    //~v543I~
      	if (clearsw) //clear req                                   //~v40FI~
        {                                                          //~v40FI~
//          if (plh->ULHlen<spfpos+SPFNUMFLDLEN                    //~v430R~
            if (plh->ULHlen!=spfpos+SPFNUMFLDLEN                   //~v430I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	    ||  UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,plh->ULHdata+spfpos,plh->ULHdbcs+spfpos,SPFNUMFLDLEN)!=SPFNUMFLDLEN)//~va50I~
	#else                                                          //~va50I~
    	    ||  UTF_umemspnc(swutf8file,plh->ULHdata+spfpos,plh->ULHdbcs+spfpos,' ',SPFNUMFLDLEN)!=SPFNUMFLDLEN)//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
    	    ||  umemspnc(plh->ULHdata+spfpos,' ',SPFNUMFLDLEN)!=SPFNUMFLDLEN)//~v413R~
#endif                                                             //~va20I~
        	   lenerrsw=1;                                         //~v40FR~
            else                                                   //~v420I~
//          	if (cobclearsw)                                    //~v47AR~
            	if (cobclearsw||cobkclearsw)                       //~v47AI~
                	if (plh->ULHlen<SPFCOBNUMFLDLEN                //~v420I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
		    	    ||  UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,plh->ULHdata,plh->ULHdbcs,SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~va50I~
	#else                                                          //~va50I~
		    	    ||  UTF_umemspnc(swutf8file,plh->ULHdata,plh->ULHdbcs,' ',SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
		    	    ||  umemspnc(plh->ULHdata,' ',SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~v420I~
#endif                                                             //~va20I~
						lenerrsw=1;                                //~v420I~
        }                                                          //~v40FI~
        else                                                       //~v42uI~
        if (cobclearsw)                                            //~v42uI~
        {                                                          //~v42uI~
//          if (plh->ULHlen<SPFCOBNUMFLDLEN                        //~v430R~
            if (plh->ULHlen!=STDSPFLRECL                           //~v430I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
		    ||  UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,plh->ULHdata,plh->ULHdbcs,SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~va50I~
	#else                                                          //~va50I~
		    ||  UTF_umemspnc(swutf8file,plh->ULHdata,plh->ULHdbcs,' ',SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
		    ||  umemspnc(plh->ULHdata,' ',SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~v42uI~
#endif                                                             //~va20I~
				lenerrsw=1;                                        //~v42uI~
                                                                   //~v42uI~
		}                                                          //~v42uI~
        else                                                       //~v40FI~
        if (cobkclearsw)	//cobo seqno of cobk file              //~v47AI~
        {                                                          //~v47AI~
        	if (plh->ULHlen<SPFCOBNUMFLDLEN                        //~v47AI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
		    ||  UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,plh->ULHdata,plh->ULHdbcs,SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~va50I~
	#else                                                          //~va50I~
		    ||  UTF_umemspnc(swutf8file,plh->ULHdata,plh->ULHdbcs,' ',SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
		    ||  umemspnc(plh->ULHdata,' ',SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~v47AI~
#endif                                                             //~va20I~
				lenerrsw=1;                                        //~v47AI~
		}                                                          //~v47AI~
        else                                                       //~v47AI~
//      	if (spfsw)                                             //~v47AR~
        	if (spfsw||cobkrenumsw)                                //~v47AI~
        	{                                                      //~v413I~
				sprintf(wkedit2,"%04ld%02d",plh->ULHlinenor%10000,plh->ULHsuffix%100);//~v413I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  			UCVEBC_a2bfld(swebcfile,wkedit2,0/*len*/);         //~va50R~//~va79R~
    			UCVEBC_a2bfld(swebcfile,handle,wkedit2,0/*len*/);  //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
              if (spfsw)                                           //~v47AI~
				if (!UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM))	//prev is clear//~v413R~
                {                                                  //~v71ZI~
//  		        if (plh->ULHlen<spfpos+SPFNUMFLDLEN            //~v71ZR~
//                  ||  memcmp(plh->ULHdata+spfpos,wkedit2,SPFNUMVERPOS))//~v71ZR~
    		        if (plh->ULHlen<spfpos+SPFNUMFLDLEN)           //~v71ZI~
						lenerrsw=1;                                //~v413I~
                    else                                           //~v71ZI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//                  if (XESUB_memcmp_ebcdd(swebcfile,swutf8file,XESUBDDSCO_EQCHKONLY,plh->ULHdata+spfpos,plh->ULHdbcs+spfpos,wkedit2,0/*dbcs2*/,SPFNUMVERPOS))//~va50R~//~va79R~
                    if (XESUB_memcmp_ebcdd(swebcfile,swutf8file,handle,XESUBDDSCO_EQCHKONLY,plh->ULHdata+spfpos,plh->ULHdbcs+spfpos,wkedit2,0/*dbcs2*/,SPFNUMVERPOS))//~va79I~
	#else                                                          //~va50I~
                    if (XESUB_DDMEMCMP(swutf8file,XESUBDDSCO_EQCHKONLY,plh->ULHdata+spfpos,plh->ULHdbcs+spfpos,wkedit2,0/*dbcs2*/,SPFNUMVERPOS))//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                    if (memcmp(plh->ULHdata+spfpos,wkedit2,SPFNUMVERPOS))//~v71ZI~
#endif                                                             //~va20I~
                    {                                              //~v71ZI~
						lenerrsw=1;                                //~v71ZI~
	  					if (UCBITCHK(plh->ULHflag3,ULHF3SPFNUMOK))//already valid spf//~v71ZR~
							renumonlysw=1;	                       //~v71ZI~
                    }                                              //~v71ZI~
                }                                                  //~v71ZI~
            	if (cobsw)                                         //~v47AR~
                      if (plh->ULHlen<SPFCOBNUMFLDLEN              //~v413R~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//                    ||  XESUB_memcmp_ebcdd(swebcfile,swutf8file,XESUBDDSCO_EQCHKONLY,plh->ULHdata,plh->ULHdbcs,wkedit2,0/*dbcs2*/,SPFCOBNUMFLDLEN))//do REPRENUM//~va50R~//~va79R~
                      ||  XESUB_memcmp_ebcdd(swebcfile,swutf8file,handle,XESUBDDSCO_EQCHKONLY,plh->ULHdata,plh->ULHdbcs,wkedit2,0/*dbcs2*/,SPFCOBNUMFLDLEN))//do REPRENUM//~va79I~
	#else                                                          //~va50I~
                      ||  XESUB_DDMEMCMP(swutf8file,XESUBDDSCO_EQCHKONLY,plh->ULHdata,plh->ULHdbcs,wkedit2,0/*dbcs2*/,SPFCOBNUMFLDLEN))//do REPRENUM//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                      ||  memcmp(plh->ULHdata,wkedit2,SPFCOBNUMFLDLEN))//do REPRENUM//~v413R~
#endif                                                             //~va20I~
                      {                                            //~v71ZI~
						lenerrsw=1;                                //~v413I~
						renumonlysw=0; //cob num fld updated-->spf version-no up//~v71ZI~
                      }                                            //~v71ZI~
    		}//spfsw                                               //~v413I~
            else                                                   //~v506I~
            if (setrisw)        //SETR/SETI id                     //~v506I~
            {                                                      //~v506I~
                if (!plh->ULHdbcs)  //not once displayed           //~v506I~
                    if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v506I~
                        return UALLOC_FAILED;                      //~v506I~
		        if (xlinenosw)                                     //~v506I~
        	        len=sprintf(wkedit3,wkedit2,offs);             //~v506R~
                else                                               //~v506I~
        	        len=sprintf(wkedit3,wkedit2,lineno);           //~v506R~
                if (len>numdelmfldlen)	//overflow                 //~v506I~
                	strcpy(wkedit3,wkedit3+len-numdelmfldlen);     //~v506R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  			UCVEBC_a2bfld(swebcfile,wkedit3,0/*len*/);         //~va50R~//~va79R~
    			UCVEBC_a2bfld(swebcfile,handle,wkedit3,0/*len*/);  //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
				len=plh->ULHlen;                                   //~v506R~
                if (setrisw=='I')	//insert                       //~v506R~
                {                                                  //~v506I~
                    lenerrsw=1;		//undoprep                     //~v506I~
                    if (numfldcol<len)	//into record              //~v506I~
                    	newlen=len+numdelmfldlen;	//inserted len //~v506I~
                    else                                           //~v506I~
                    	newlen=numfldcole;	//after space padding  //~v506I~
                }                                                  //~v506I~
                else                                               //~v506I~
                {                                                  //~v506I~
                    if (numfldcole>len)	//over record              //~v506R~
                    {                                              //~v506I~
                        lenerrsw=1;     //num changed              //~v506I~
                        newlen=numfldcole;                         //~v506I~
                    }                                              //~v506I~
                    else			//	on the record              //~v506R~
                    {                                              //~v506I~
                        newlen=len;		//len not change           //~v506I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//                  	if (XESUB_memcmp_ebcdd(swebcfile,swutf8file,XESUBDDSCO_EQCHKONLY,plh->ULHdata+numfldcol,plh->ULHdbcs+numfldcol,wkedit3,0/*dbcs2*/,(UINT)numdelmfldlen))//~va50R~//~va79R~
//                    	if (XESUB_memcmp_ebcdd(swebcfile,swutf8file,handle,XESUBDDSCO_EQCHKONLY,plh->ULHdata+numfldcol,plh->ULHdbcs+numfldcol,wkedit3,0/*dbcs2*/,(UINT)numdelmfldlen))//~va79I~//+vb2DR~
                      	if (XESUB_memcmp_ebcdd(swebcfile,swutf8file,handle,XESUBDDSCO_EQCHKONLY,plh->ULHdata+numfldcol,plh->ULHdbcs+numfldcol,wkedit3,0/*dbcs2*/,numdelmfldlen))//+vb2DI~
	#else                                                          //~va50I~
                    	if (XESUB_DDMEMCMP(swutf8file,XESUBDDSCO_EQCHKONLY,plh->ULHdata+numfldcol,plh->ULHdbcs+numfldcol,wkedit3,0/*dbcs2*/,(UINT)numdelmfldlen))//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                    	if (memcmp(plh->ULHdata+numfldcol,wkedit3,(UINT)numdelmfldlen))//~v506R~
#endif                                                             //~va20I~
		                	lenerrsw=1;     //num changed          //~v506R~
                    }                                              //~v506I~
                }                                                  //~v506I~
            }//seti/setr                                           //~v506R~
      }//datasw                                                    //~v543I~
//    if (lineno!=plh->ULHlinenor || suffix!=plh->ULHsuffix        //~v47AR~
      if ( (!(Popt & RENUMOPT_CLEAR) && (lineno!=plh->ULHlinenor || suffix!=plh->ULHsuffix))//~v47AR~
//    ||  offs  !=plh->ULHoffs                                     //~v40SR~
      ||  (xlinenosw && offs  !=plh->ULHoffs)                      //~v40SI~
      ||  lenerrsw)                                                //~v0cnR~
      {                                                            //~v0cnI~
      	if (!plh1st)                                               //~v0cnI~
        	plh1st=plh;		//1st changed                          //~v0cnI~
//      if (spfsw && datasw)                                       //~v47AR~
        if (datasw                                                 //~v47AI~
        &&  (spfsw||cobkclearsw||cobkrenumsw))                     //~v47AR~
        {                                                          //~v0cnI~
			if (newlen>plh->ULHbufflen)                            //~v0cnR~
            {                                                      //~v0cnI~
				if (fileexpandbuff(plh,newlen)==UALLOC_FAILED)     //~v0cnR~
                    return UALLOC_FAILED;                          //~v0cnR~
			}                                                      //~v0cnI~
    		if (lenerrsw)                                          //~v40SR~
//            if (clearsw|cobclearsw)                              //~v47AR~
              if (clearsw|cobclearsw|cobkclearsw)                  //~v47AI~
//*ebc_setdbcstbl at filesetspfnum                                 //~va50I~
    	  		rc=undoupdate(Ppcw,plh,UUHTREPRENUMCLR);//no num set at save//~v42rI~
              else                                                 //~v42rI~
              {                                                    //~v71ZI~
                svreason=Ppcw->UCWreason;                          //~v71ZI~
                Ppcw->UCWreason=renumonlysw;   //parm to undo update//~v71ZI~
//*ebc_setdbcstbl at filesetspfnum                                 //~va50I~
    	  		rc=undoupdate(Ppcw,plh,UUHTREPRENUM);//recl change //~v0ctR~
                Ppcw->UCWreason=svreason;                          //~v71ZI~
              }                                                    //~v71ZI~
    		else            //lineno,suffix chnged                 //~v40SR~
//*ebc_setdbcstbl at filesetspfnum                                 //~va50I~
    			rc=undoupdate(Ppcw,plh,UUHTRENUM);//also upctr up for save//~v40SR~
            if (rc)                                                //~v0cnR~
                return rc;                                         //~v0cnI~
            donectr++;                                             //~v412I~
                                                                   //~v53dI~
          if (!setrinorenumsw)        //not SETR/SETI id           //~v53dI~
          {                                                        //~v53dI~
            plh->ULHlinenor=lineno;                                //~v0cnI~
            plh->ULHsuffix=suffix;                                 //~v0cnI~
            plh->ULHoffs=offs;		//update offset                //~v53dI~
          }                                                        //~v53dI~
//          filesetspfnum(Ppfh,plh,plh->ULHdata,plh->ULHdbcs,1);   //~v40FR~
            filesetspfnum(Ppfh,plh,plh->ULHdata,plh->ULHdbcs,      //~v40FR~
                            newlen,                                //~v73bI~
//  						SETSPFNUM_PLHVER+clearsw+SETSPFNUM_FORCE);//~v420R~
//  						SETSPFNUM_PLHVER+clearsw+cobclearsw+SETSPFNUM_FORCE);//~v47AR~
    						SETSPFNUM_PLHVER+clearsw+cobclearsw+cobkclearsw+cobkrenumsw+SETSPFNUM_FORCE);//~v47AR~
//          plh->ULHlen=newlen;                                    //~v73bR~
		}                                                          //~v0cnI~
        else                                                       //~v0cnI~
//      if (datasw && setrisw && lenerrsw && !suffix)	//SETI/SETR//~v53dR~
        if (datasw && setrisw && lenerrsw && !UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))//~v53dR~
        {                                                          //~v506I~
			if (newlen>plh->ULHbufflen)                            //~v506I~
            {                                                      //~v506I~
				if (fileexpandbuff(plh,newlen)==UALLOC_FAILED)     //~v506I~
                    return UALLOC_FAILED;                          //~v506I~
			}                                                      //~v506I~
//*ebc_setdbcstbl later                                            //~va50I~
    	  	rc=undoupdate(Ppcw,plh,UUHTREPRENUM);//recl change     //~v506I~
            if (rc)                                                //~v506I~
                return rc;                                         //~v506I~
            donectr++;                                             //~v506I~
          if (!setrinorenumsw)        //not SETR/SETI id           //~v53dI~
          {                                                        //~v53dI~
            plh->ULHlinenor=lineno;                                //~v506I~
            plh->ULHsuffix=suffix;                                 //~v506I~
            plh->ULHoffs=offs;		//update offset                //~v506I~
          }                                                        //~v53dI~
            len=plh->ULHlen;                                       //~v506I~
            pdata=plh->ULHdata;                                    //~v506R~
            pdbcs=plh->ULHdbcs;                                    //~v506I~
            swmargincut=0;                                         //~va53I~
            if (setrisw=='I')   //insert                           //~v506I~
            {                                                      //~v506I~
    		  	if (numfldcol<margin||numfldcol<fixlrecl)          //~va53R~
              	{                                                  //~va53R~
              		swmargincut=(xesub_imupdate(XESUBIMUO_INS,Ppcw,Ppfh,plh,numfldcol,wkedit3,0/*dbcs*/,numdelmfldlen,&newlen)==1);//~va53R~
              	}                                                  //~va53R~
              	else                                               //~va53R~
                if (numfldcol<len)  //into record                  //~v506I~
                {                                                  //~v506I~
                	pc=pdata+numfldcol;                            //~v506I~
                    memmove(pc+numdelmfldlen,pc,(UINT)(len-numfldcol));//~v506R~
                    memcpy(pc,wkedit3,(UINT)numdelmfldlen);        //~v50tR~
                	pc=pdbcs+numfldcol;                            //~v506I~
                    memmove(pc+numdelmfldlen,pc,(UINT)(len-numfldcol));//~v506R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                    setobtabdbcs(swebcfile,0,pdata,pdbcs,len,numfldcol,numdelmfldlen);//~va5eI~
#else                                                              //~va5eI~
                    setobtabdbcs(pdata,pdbcs,len,numfldcol,numdelmfldlen);//~v506M~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5eM~
                    memset(pc,0,(UINT)numdelmfldlen);              //~v50tR~
                                                                   //~va50I~
                }                                                  //~v506I~
                else                                               //~v506I~
                {                                                  //~v506I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                	UCVEBC_memset_space(swebcfile,pdata+len,(UINT)(numfldcol-len));//~va50I~
#else                                                              //~va50I~
                	memset(pdata+len,' ',(UINT)(numfldcol-len));   //~v506I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                	memcpy(pdata+numfldcol,wkedit3,(UINT)numdelmfldlen);//~v506R~
                	memset(pdbcs+len,0,(UINT)(numfldcole-len));    //~v506M~
                }                                                  //~v506I~
            }                                                      //~v506I~
            else	//repl                                         //~v506R~
            {                                                      //~v506I~
    		  	if (numfldcol<margin||numfldcol<fixlrecl)          //~va53I~
                {                                                  //~va53I~
	              	swmargincut=(xesub_imupdate(XESUBIMUO_REP,Ppcw,Ppfh,plh,numfldcol,wkedit3,0/*dbcs*/,numdelmfldlen,&newlen)==1);//~va53R~
                }                                                  //~va53I~
                else                                               //~va53I~
                if (numfldcol>len) //over record                   //~v506I~
                {                                                  //~v506I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                	UCVEBC_memset_space(swebcfile,pdata+len,(UINT)(numfldcol-len));//~va50I~
#else                                                              //~va50I~
                	memset(pdata+len,' ',(UINT)(numfldcol-len));   //~v506I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                	memcpy(pdata+numfldcol,wkedit3,(UINT)numdelmfldlen);//~v506R~
                	memset(pdbcs+len,0,(UINT)(numfldcole-len));    //~v506I~
                }                                                  //~v506I~
                else          //      on the record                //~v506R~
                {                                                  //~v506I~
                	memcpy(pdata+numfldcol,wkedit3,(UINT)numdelmfldlen);//~v506R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                    setobtabdbcs(swebcfile,0,pdata,pdbcs,len,numfldcol,numdelmfldlen);//~va5eI~
#else                                                              //~va5eI~
                    setobtabdbcs(pdata,pdbcs,len,numfldcol,numdelmfldlen);//~v506M~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5eM~
                	memset(pdbcs+numfldcol,0,(UINT)numdelmfldlen); //~v506I~
                }                                                  //~v506I~
            }                                                      //~v506I~
            if (swmargincut)                                       //~va53I~
            {                                                      //~va53I~
        		filesetlineerr(plh);                               //~va53I~
                cutctr++;                                          //~va53I~
            }                                                      //~va53I~
            plh->ULHlen=newlen;                                    //~v506I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          if (swebcfile)                                           //~va50I~
		  	xeebc_setdbcstblplh(0,Ppfh,plh,0);                     //~va50R~
		  else                                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            filechktabdbcs(plh);                                   //~v506I~
		}                                                          //~v506I~
        else                                                       //~v506I~
        {                                                          //~v0cnI~
//*plhrenum only                                                   //~va50I~
      		rc=undoprep(Ppcw,plh,UUHTRENUM);                       //~v0cnR~
            if (rc)                                                //~v0cnI~
                return rc;                                         //~v0cnI~
          if (!setrinorenumsw)        //not SETR/SETI id           //~v53dI~
          {                                                        //~v53dI~
            plh->ULHlinenor=lineno;                                //~v0cnI~
            plh->ULHsuffix=suffix;                                 //~v0cnI~
            plh->ULHoffs=offs;		//update offset                //~v178I~
          }                                                        //~v53dI~
        }                                                          //~v0cnI~
//      plh->ULHlinenor=lineno;                                    //~v0cnR~
//      plh->ULHsuffix=0;                                          //~v0aiR~
//      plh->ULHsuffix=suffix;                                     //~v0cnR~
      }//changed                                                   //~v0cnI~
//set next line count                                              //~v0cnI~
      if (!setrinorenumsw)        //not SETR/SETI id               //~v53dI~
      {                                                            //~v53dI~
        if (plh->ULHtype!=ULHTEXCLUDE)	//data or hdr              //~v0cnI~
        {                                                          //~v0cnI~
        	if (plh->ULHtype==ULHTDATA)                            //~v178I~
                offs+=plh->ULHlen+plh->ULHeolid;	//next line offset//~v50tR~
          	if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))               //~v0cnI~
          		suffix++;                                          //~v0cnI~
          	else                                                   //~v0cnI~
          	{                                                      //~v0cnI~
        		++lineno;                                          //~v0cnI~
          		suffix=0;                                          //~v0cnI~
		  	}                                                      //~v0cnI~
		}                                                          //~v0cnI~
      }//setri no renum                                            //~v53dI~
		plh=UGETQNEXT(plh);                                        //~v074I~
	}                                                              //~v074I~
//  undofreeuuh(Ppfh);			//free all undo data               //~v0cnR~
    if (spferrsw)                                                  //~v0ctI~
    {                                                              //~v0ctI~
		UCBITOFF(Ppfh->UFHflag2,UFHF2SPFNUMERR);                   //~v0ctI~
		UCBITON(Ppfh->UFHflag2,UFHF2SPFNUMOK);                     //~v0ctI~
		UCBITON(Ppcw->UCWflag,UCWFDRAW);//even if 0 line updated(plh1st=0)//~v412I~
	}                                                              //~v0ctI~
//if (cobsw)    //NOAUTONUM is effective only for cob              //~v42tR~
//{                                                                //~v42tR~
// if (cobclearsw)                                                 //~v42tR~
//      UCBITOFF(Ppfh->UFHflag5,UFHF5COB);	//no more cob          //~v42tR~
// else                                                            //~v42tR~
//  if (clearsw)                                                   //~v42sR~
//      UCBITON(Ppfh->UFHflag5,UFHF5NOAUTONUM);                    //~v42sR~
//  else                                                           //~v425R~
//      UCBITOFF(Ppfh->UFHflag5,UFHF5NOAUTONUM);	//do renum     //~v425R~
//}                                                                //~v42tR~
    UPCTRREQ(Ppfh);         //write at save                        //~v0cnI~
    if (plh1st)                                                    //~v0cnI~
    {                                                              //~v0ctI~
//  	undocsrmove(Ppcw,plh1st);                                  //~v104R~
		UCBITON(Ppcw->UCWflag,UCWFDRAW);                           //~v0ctI~
    }                                                              //~v0ctI~
    if (cutctr)                                                    //~va53I~
    {                                                              //~va53I~
        uerrmsg("%d Expanded line was cut by margin(%d) or Fixed LRECL(%d) option",//~va53R~
                "%d行がマージン(%d)あるいは固定長(%d)オプションによりカット",//~va53R~
                cutctr,margin,fixlrecl);                           //~va53R~
    }                                                              //~va53I~
    else                                                           //~va53I~
    if (nonumsw)                                                   //~v42uI~
    {                                                              //~v45vI~
      if (spfsw)    //not ek renum                                 //~v45vI~
    	uerrmsg("%d line(s) updated (COB num only)",               //~v42uI~
    			"%d 行更新｡(COB欄のみ)",                           //~v42uI~
            		donectr);                                      //~v42uI~
    }                                                              //~v45vI~
    else                                                           //~v42uI~
    uerrmsg("%d line(s) updated",                                  //~v412I~
    		"%d 行更新｡",                                          //~v412R~
            	donectr);                                          //~v412I~
	return 0;                                                      //~v0cnR~
}//filerenum                                                       //~v074I~
//**************************************************************** //~v0clI~
//!filespfchk                                                      //~v0clI~
//* spf file lrecl/numeric chk for all line(even if partial edit)  //~v0clI~
//*parm1:plh                                                       //~v0clI~
//*parm2:spf num fld offset                                        //~v0clI~
//*parm3:output max version field                                  //~v0clI~
//*retrn:UALLOC_FAILED                                             //~v0clI~
//**************************************************************** //~v0clI~
int filespfchk(PULINEH Pplh,int Pspfpos,int *Pmaxver)              //~v0clR~
{                                                                  //~v0clI~
	char *pc;                                                      //~v0clI~
    int spfver;                                                    //~v0clI~
    int cobsw,nonumsw;                                             //~v40UI~
    int nocobnumsw;                                                //~v42vI~
    PUFILEH pfh;                                                   //~v40UI~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
	char *pcd;                                                     //~va50I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//***************                                                  //~v0clI~
    pfh=UGETPFH(Pplh);                                             //~v40UI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(pfh);                                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(pfh);                                  //~va20I~
#endif                                                             //~va20I~
    cobsw=UCBITCHK(pfh->UFHflag5,UFHF5COB);  //cobol spf file      //~v40UI~
	nonumsw=UCBITCHK(pfh->UFHflag5,UFHF5NOAUTONUM);  //no use col72-80//~v413R~
	nocobnumsw=UCBITCHK(pfh->UFHflag5,UFHF5COB2);  //cob num fld is all space//~v42vR~
    if (!Pplh->ULHdbcs)  //not once displayed                      //~v0e7I~
        if (filechktabdbcs(Pplh)==UALLOC_FAILED)//expand data len  //~v0e7I~
            return UALLOC_FAILED;                                  //~v0e7I~
	if (Pplh->ULHlen!=Pspfpos+SPFNUMFLDLEN)                        //~v0clI~
    {                                                              //~v0clI~
		UCBITON(Pplh->ULHflag3,ULHF3SPFNUMERR);                    //~v0duR~
        filesetlineerr(Pplh);                                      //~v0clI~
        return SPFERRLEN;                                          //~v0clI~
    }                                                              //~v0clI~
    pc=Pplh->ULHdata+Pspfpos;                                      //~v0clI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    pcd=Pplh->ULHdbcs+Pspfpos;                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
  if (!nonumsw)		//not cobol num fld only                       //~v40UI~
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    if (UCVEBCUTF_unumlen(swebcfile,swutf8file,pc,pcd,0,SPFNUMFLDLEN)!=SPFNUMFLDLEN)//~va50R~
  #else                                                            //~va50I~
    if (UTF_unumlen(swutf8file,pc,Pplh->ULHdbcs+Pspfpos,0,SPFNUMFLDLEN)!=SPFNUMFLDLEN)//~va20I~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#else                                                              //~va20I~
    if (unumlen(pc,0,SPFNUMFLDLEN)!=SPFNUMFLDLEN)                  //~v0clI~
#endif                                                             //~va20I~
    {                                                              //~v0clI~
		UCBITON(Pplh->ULHflag3,ULHF3SPFNUMERR);                    //~v0duI~
        filesetlineerr(Pplh);                                      //~v0clR~
        return SPFERRNUM;                                          //~v0clI~
    }                                                              //~v0clI~
  	if (cobsw)		//to be chk cobol num fld(col 1-6)             //~v40UI~
//    if (nocobnumsw)	//col1-6 should be all space               //~v47vR~
//    {                                                            //~v47vR~
//  	if (umemspnc(Pplh->ULHdata,' ',SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~v47vR~
//  	{                                                          //~v47vR~
//  		UCBITON(Pplh->ULHflag3,ULHF3SPFNUMERR);                //~v47vR~
//      	filesetlineerr(Pplh);                                  //~v47vR~
//      	return SPFERRNOTSPC;                                   //~v47vR~
//  	}                                                          //~v47vR~
//    }                                                            //~v47vR~
//    else                                                         //~v47vR~
      if (!nocobnumsw)	//col1-6 should be all space               //~v47vI~
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	if (UCVEBCUTF_unumlen(swebcfile,swutf8file,Pplh->ULHdata,Pplh->ULHdbcs,0,SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~va50I~
  #else                                                            //~va50I~
    	if (UTF_unumlen(swutf8file,Pplh->ULHdata,Pplh->ULHdbcs,0,SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~va20I~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
#else                                                              //~va20I~
    	if (unumlen(Pplh->ULHdata,0,SPFCOBNUMFLDLEN)!=SPFCOBNUMFLDLEN)//~v40UR~
#endif                                                             //~va20I~
    	{                                                          //~v40UI~
			UCBITON(Pplh->ULHflag3,ULHF3SPFNUMERR);                //~v40UI~
        	filesetlineerr(Pplh);                                  //~v40UI~
//      	return SPFERRNUM;                                      //~v61gR~
        	return SPFERRCOBNUM;                                   //~v61gI~
    	}                                                          //~v40UI~
    UCBITON(Pplh->ULHflag3,ULHF3SPFNUMOK);                         //~v0duI~
  if (nonumsw)		//cobol num fld only                           //~v412I~
    spfver=0;                                                      //~v412I~
  else                                                             //~v412I~
//*retured if numlen err                                           //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    spfver=UCVEBCUTF_uatoin(swebcfile,swutf8file,pc+SPFNUMVERPOS,pcd+SPFNUMVERPOS,SPFNUMVERLEN);//~va50R~
#else                                                              //~va50R~
    spfver=uatoin(pc+SPFNUMVERPOS,SPFNUMVERLEN);                   //~v0clI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    Pplh->ULHspfver=(UCHAR)spfver;                                 //~v0clR~
    if (spfver>*Pmaxver)                                           //~v0clI~
        *Pmaxver=spfver;//for all even if partial file             //~v0clI~
	return 0;                                                      //~v0clI~
}//filespfchk                                                      //~v0clI~
                                                                   //~v0czI~
//**************************************************************** //~v0czI~
//!fileisvalidspfline                                              //~v0czI~
//* spf file lrecl/numeric chk for all line(even if partial edit)  //~v0czI~
//*parm1:pfh                                                       //~v0czI~
//*parm2:plh                                                       //~v0czI~
//*parm3:option 1:set flag3,0:bypass set flag3                     //~v0duI~
//*retrn:1:valid spfline,0:invalid spfline                         //~v0czI~
//**************************************************************** //~v0czI~
int fileisvalidspfline(PUFILEH Ppfh,PULINEH Pplh,int Popt)         //~v0duR~
{                                                                  //~v0czI~
    int rc;                                                        //~v0duI~
    int cobsw,nonumsw;                                             //~v40UI~
    int nocobnumsw;                                                //~v42vI~
    UCHAR *pc;                                                     //~v40UI~
    UCHAR flag;                                                    //~v0duI~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//***************                                                  //~v0czI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20I~
#endif                                                             //~va20I~
    flag=Pplh->ULHflag3;                                           //~v0duI~
    if (UCBITCHK(flag,ULHF3SPFNUMOK))                              //~v0duI~
        return 1;                           //already chked ok     //~v0duI~
    if (UCBITCHK(flag,ULHF3SPFNUMERR))                             //~v0duI~
        return 0;                           //already chked err    //~v0duI~
    if (!Pplh->ULHdbcs)  //not once displayed                      //~v0e7I~
        if (filechktabdbcs(Pplh)==UALLOC_FAILED)//expand data len  //~v0e7I~
            return 0;                                              //~v0e7I~
//  rc=    (Pplh->ULHlen==Ppfh->UFHlrecl                           //~v40UR~
//         && unumlen(Pplh->ULHdata+Ppfh->UFHspfpos,0,SPFNUMFLDLEN)==SPFNUMFLDLEN);//~v40UR~
    rc=Pplh->ULHlen==Ppfh->UFHlrecl;                               //~v40UI~
    if (rc)                                                        //~v40UI~
    {                                                              //~v40UI~
    	cobsw=UCBITCHK(Ppfh->UFHflag5,UFHF5COB);  //cobol spf file //~v40UR~
		nonumsw=UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM);  //no use col72-80//~v412R~
		nocobnumsw=UCBITCHK(Ppfh->UFHflag5,UFHF5COB2);  //cob num fld is all space//~v42vI~
		pc=Pplh->ULHdata+Ppfh->UFHspfpos;                          //~v40UI~
		if (!nonumsw)		//not cobol num fld only               //~v40UI~
#ifdef UTF8UCS2                                                    //~va20I~
  	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
			rc=UCVEBCUTF_unumlen(swebcfile,swutf8file,pc,Pplh->ULHdbcs+Ppfh->UFHspfpos,0,SPFNUMFLDLEN)==SPFNUMFLDLEN;//~va50I~
    #else                                                          //~va50I~
			rc=UTF_unumlen(swutf8file,pc,Pplh->ULHdbcs+Ppfh->UFHspfpos,0,SPFNUMFLDLEN)==SPFNUMFLDLEN;//~va20I~
  	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
			rc=unumlen(pc,0,SPFNUMFLDLEN)==SPFNUMFLDLEN;           //~v40UR~
#endif                                                             //~va20I~
        if (rc)                                                    //~v40UI~
  			if (cobsw)		//to be chk cobol num fld(col 1-6)     //~v40UI~
            {                                                      //~v53UI~
              if (nocobnumsw)                                      //~v42vI~
//  	        rc=umemspnc(Pplh->ULHdata,' ',SPFCOBNUMFLDLEN)==SPFCOBNUMFLDLEN;//~v47vR~
    	        rc=0;           //any string allowed               //~v47vI~
              else                                                 //~v42vI~
#ifdef UTF8UCS2                                                    //~va20I~
  	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    			rc=UCVEBCUTF_unumlen(swebcfile,swutf8file,Pplh->ULHdata,Pplh->ULHdbcs,0,SPFCOBNUMFLDLEN)==SPFCOBNUMFLDLEN;//~va50I~
    #else                                                          //~va50I~
    			rc=UTF_unumlen(swutf8file,Pplh->ULHdata,Pplh->ULHdbcs,0,SPFCOBNUMFLDLEN)==SPFCOBNUMFLDLEN;//~va20I~
  	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
    			rc=unumlen(Pplh->ULHdata,0,SPFCOBNUMFLDLEN)==SPFCOBNUMFLDLEN;//~v40UR~
#endif                                                             //~va20I~
            }//cobsw                                               //~v53UI~
    }                                                              //~v40UI~
  	if (Popt)	                                                   //~v0duI~
    {                                                              //~v53UI~
    	if (rc)                                                    //~v0duR~
        {                                                          //~v0duI~
			UCBITON(flag,ULHF3SPFNUMOK);                           //~v0duR~
			UCBITOFF(flag,ULHF3SPFNUMERR);                         //~v0duI~
        }                                                          //~v0duI~
		else                                                       //~v0duR~
        {                                                          //~v0duI~
			UCBITON(flag,ULHF3SPFNUMERR);                          //~v0duR~
			UCBITOFF(flag,ULHF3SPFNUMOK);                          //~v0duI~
        }                                                          //~v0duI~
    }//Popt                                                        //~v53UI~
	return rc;                                                     //~v0duI~
}//fileisvalidspfline                                              //~v0czI~
//**************************************************************** //~v0clI~
//!filespfloadnum                                                  //~v0clI~
//  get spf numver(num chk alrady end)                             //~v0clR~
//*parm1:pfh                                                       //~v0clI~
//*parm2:max version                                               //~v0clI~
//*parm3:errsw                                                     //~v0ctI~
//*rc   :none                                                      //~v0clI~
//**************************************************************** //~v0clI~
void filespfloadnum(PUFILEH Ppfh,int Pmaxver,int Perrsw)           //~v0ctR~
{                                                                  //~v0clI~
	PULINEH plh,plhlast=NULL;                                           //~v0clI~//~vafcR~
    char *pc;                                                      //~v0clI~
    int spfpos,spfseqerr=0;                                        //~v0clI~
    int lnoprev=0,lno;                                             //~v0clR~
    int snoprev=0,sno;                                             //~v0clR~
    int nonumsw;                                                   //~v412I~
    int nocobnumsw;                                                //~v42vI~
    long temp[2];                                                  //~v0clI~
#ifdef UTF8UCS2                                                    //~va50I~
    int swutf8file;                                                //~va50I~
    char *pcd;                                                     //~va50I~
#endif                                                             //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//********************                                             //~v0clI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef UTF8UCS2                                                    //~va50I~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va50I~
#endif                                                             //~va50I~
    spfpos=Ppfh->UFHspfpos;                                        //~v0clI~
	nonumsw=UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM);  //no use col72-80//~v412I~
	nocobnumsw=UCBITCHK(Ppfh->UFHflag5,UFHF5COB2);  //num fld is all space//~v42vI~
    if (Pmaxver>=SPFNUMMAXVER)                                     //~v0ctM~
    {                                                              //~v0ctM~
    	filespfvermaxerr(Pmaxver,SPFNUMMAXVER);                    //~v0ctM~
        Pmaxver=SPFNUMMAXVER;                                      //~v0ctM~
	}                                                              //~v0ctM~
    Ppfh->UFHspfver=(UCHAR)Pmaxver; //set even if err              //~v0ctM~
    if (Perrsw & SPFERRLEN)                                        //~v0ctM~
    {                                                              //~v0ctM~
     	filespflenerr(spfpos+SPFNUMFLDLEN);                        //~v0ctM~
        return;                                                    //~v0ctM~
	}                                                              //~v0ctM~
    if (Perrsw & SPFERRCOBNUM)                                     //~v61gI~
    {                                                              //~v61gI~
        filespfcobnumerr();                                        //~v61gI~
        return;                                                    //~v61gI~
	}                                                              //~v61gI~
    if (Perrsw & SPFERRNUM)                                        //~v0ctM~
    {                                                              //~v0ctM~
        filespfnumerr();                                           //~v0ctM~
        return;                                                    //~v0ctM~
	}                                                              //~v0ctM~
    if (Perrsw & SPFERRNOTSPC)                                     //~v42vR~
    {                                                              //~v42vI~
        filespferrnotspace();                                      //~v42vI~
        return;                                                    //~v42vI~
	}                                                              //~v42vI~
  if (!(nonumsw && nocobnumsw))		//spf but no seqno prepared    //~v42vI~
  {                                                                //~v42vI~
	for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))   //~v0clI~
	{                                                              //~v0clI~
		if (plh->ULHtype!=ULHTDATA)	//not file data                //~v0clI~
        	continue;                                              //~v0clI~
      if (nonumsw)                                                 //~v412I~
      {                                                            //~v412I~
		pc=plh->ULHdata;	//spf fld                              //~v412I~
//*retured if spfnumerr                                            //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		pcd=plh->ULHdbcs;	//spf fld                              //~va50I~
        lno=UCVEBCUTF_uatoin(swebcfile,swutf8file,pc,pcd,SPFNUMLNOLEN);//~va50I~
        sno=UCVEBCUTF_uatoin(swebcfile,swutf8file,pc+SPFNUMSNOPOS,pcd+SPFNUMSNOPOS,SPFNUMSNOLEN);//~va50I~
#else                                                              //~va50I~
        lno=uatoin(pc,SPFNUMLNOLEN);                               //~v412I~
        sno=uatoin(pc+SPFNUMSNOPOS,SPFNUMSNOLEN);                  //~v412I~
#endif                                                             //~va50I~
      }                                                            //~v412I~
      else                                                         //~v412I~
      {                                                            //~v412I~
		pc=plh->ULHdata+spfpos;	//spf fld                          //~v0clR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		pcd=plh->ULHdbcs+spfpos;	//spf fld                      //~va50I~
        lno=UCVEBCUTF_uatoin(swebcfile,swutf8file,pc,pcd,SPFNUMLNOLEN);//~va50I~
        sno=UCVEBCUTF_uatoin(swebcfile,swutf8file,pc+SPFNUMSNOPOS,pcd+SPFNUMSNOPOS,SPFNUMSNOLEN);//~va50I~
#else                                                              //~va50I~
        lno=uatoin(pc,SPFNUMLNOLEN);                               //~v0clI~
        sno=uatoin(pc+SPFNUMSNOPOS,SPFNUMSNOLEN);                  //~v0clR~
#endif                                                             //~va50I~
      }                                                            //~v412I~
        if (lno<lnoprev                                            //~v0clR~
        ||  (lno==lnoprev && sno<=snoprev))                        //~v0clR~
        {                                                          //~v0clI~
        	filesetlineerr(plh);                                   //~v0clR~
            spfseqerr=1;                                           //~v0clI~
        }                                                          //~v0clI~
        lnoprev=lno;                                               //~v0clR~
        snoprev=sno;                                               //~v0clR~
        temp[0]=(long)lno;                                         //~v0clR~
        temp[1]=(long)sno;                                         //~v0clR~
        memcpy(plh->ULHlineno,temp,ULHLINENOSZ);                   //~v0clR~
	}//all plh                                                     //~v0clI~
//                                                                 //~v0clI~
	for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plhlast=plh,plh=UGETQNEXT(plh))//~v0clI~
	{                                                              //~v0clI~
		if (plh->ULHtype!=ULHTDATA)	//not file data                //~v0clI~
        	continue;                                              //~v0clI~
	    if (!spfseqerr)                                            //~v0clI~
        {                                                          //~v0clI~
            memcpy(temp,plh->ULHlineno,sizeof(temp));              //~v0clR~
            plh->ULHlinenor=temp[0];                               //~v0clR~
            plh->ULHsuffix=(int)temp[1];                           //~v0clR~
        }                                                          //~v0clI~
        memset(plh->ULHlineno,0,ULHLINENOSZ);                      //~v0clI~
	}//all plh                                                     //~v0clI~
    plhlast->ULHlinenor=temp[0]+1;                                 //~v0clI~
  }//spf but no lineno on line                                     //~v42vI~
    if (spfseqerr)                                                 //~v0clM~
    {                                                              //~v0clI~
    	filespfseqerr();                                           //~v0clM~
        return;                                                    //~v0clI~
    }                                                              //~v0clI~
//  else                                                           //~v0cqR~
//      Pmaxver++;                                                 //~v0cqR~
    UCBITON(Ppfh->UFHflag2,UFHF2SPFNUMOK);	//write num a save     //~v0clR~
    UCBITOFF(Ppfh->UFHflag2,UFHF2SPFNUMERR);//write num a save     //~v0ctI~
	return;                                                        //~v0clI~
}//filespfloadnum                                                  //~v0clI~
                                                                   //~v0clI~
//************************************************************     //~v0clI~
// filesetspfnum                                                   //~v0clI~
//*spf num filed setup                                             //~v0clI~
//*parm1:pfh                                                       //~v0clI~
//*parm2:plh                                                       //~v0clI~
//*parm3:data                                                      //~v0clI~
//*parm4:dbcs                                                      //~v0clI~
//*parm5:opt 0:ver from pfh,1:ver from plh                         //~v0cnI~
//*return:addlen                                                   //~v0clI~
//************************************************************     //~v0clI~
//int  filesetspfnum(PUFILEH Ppfh,PULINEH Pplh,char * Pdata,char *Pdbcs,int Popt)//~v73bR~
int  filesetspfnum(PUFILEH Ppfh,PULINEH Pplh,char * Pdata,char *Pdbcs,int Pnewlen,int Popt)//~v73bR~
{                                                                  //~v0clI~
    int spfexplen,spfpos,lrecl,addlen;                             //~v0clI~
    int lineno,ovf;                                                //~v0clI~
    int ver;                                                       //~v0cqI~
//  int plhversw=0;                                                //+v71YR~,//~v71ZR~
    char wkedit[16];                                               //~v0clR~
    char wkedit2[8];                                               //~v40TI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
    int swupdate=0;                                                //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************                                                //~v0clI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
    handle=Ppfh->UFHhandle;                                        //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    spfpos=Ppfh->UFHspfpos;                                        //~v0clI~
    lrecl=Pplh->ULHlen;                                            //~v0clI~
    spfexplen=(spfpos+SPFNUMFLDLEN)-lrecl;                         //~v0clI~
    if (spfexplen>0)                                               //~v0clI~
        addlen=spfexplen;                                          //~v0clI~
	else                                                           //~v0clI~
    	addlen=0;                                                  //~v0clR~
                                                                   //~v0clI~
//  spfexplen-=SPFNUMFLDLEN;                                       //~v40FR~
//  if (spfexplen>0)                                               //~v40FR~
    if (addlen>0)       //clear also num fld for the case no col72-80 set//~v40FI~
    {                                                              //~v0clI~
//      memset(Pdata+lrecl,' ',(UINT)spfexplen);                   //~v40FR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        UCVEBC_memset_space(swebcfile,Pdata+lrecl,addlen);         //~va50I~
#else                                                              //~va50I~
        memset(Pdata+lrecl,' ',(UINT)addlen);                      //~v40FI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        if (Pdbcs)                                                 //~v0clI~
//     		 memset(Pdbcs+lrecl,0,(UINT)spfexplen);                //~v40FR~
       		 memset(Pdbcs+lrecl,0,(UINT)addlen);                   //~v40FI~
    }                                                              //~v0clI~
    lineno=(int)Pplh->ULHlinenor*10000+Pplh->ULHsuffix*100;        //~v0cnR~
//  if (Popt & SETSPFNUM_ATSAVE)//no dbcs set,ver from pfh         //+v71YM~,//~v71ZR~
//  	if (UCBITCHK(Pplh->ULHflag3,ULHF3SPFNUMOK)//num ok         //+v71YM~,//~v71ZR~
//      &&  memcmp(Pplh->ULHdata+spfpos+SPFNUMVERPOS,"00",SPFNUMVERLEN))//already ver set//+v71YM~,//~v71ZR~
//      	plhversw=1;                                            //+v71YI~,//~v71ZR~
                                                                   //~v0cqI~
//  if (Popt)                                                      //~v40FR~
    if (Popt & SETSPFNUM_PLHVER)                                   //~v40FI~
    	ver=Pplh->ULHspfver;                                       //~v0cqR~
	else                                                           //~v0cnI~
//  if (plhversw)                                                  //+v71YI~,//~v71ZR~
//  	ver=Pplh->ULHspfver;                                       //+v71YI~,//~v71ZR~
//  else                                                           //+v71YI~,//~v71ZR~
    	ver=Ppfh->UFHspfver+1;                                     //~v0cqR~
    if (ver>SPFNUMMAXVER)                                          //~v0cqI~
        ver=SPFNUMMAXVER;                                          //~v0cqR~
    lineno+=ver;                                                   //~v0cqR~
                                                                   //~v0cqI~
    sprintf(wkedit,"%08d",lineno);                                 //~v0clR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  UCVEBC_a2bfld(swebcfile,wkedit,0/*len*/);                      //~va50R~//~va79R~
    UCVEBC_a2bfld(swebcfile,handle,wkedit,0/*len*/);               //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
 if (Popt & SETSPFNUM_CLEAR)                                       //~v416R~
 {                                                                 //~v42uI~
 	if (Popt & SETSPFNUM_COB)                                      //~v420I~
    {                                                              //~v739I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	UCVEBC_memset_space(swebcfile,Pdata,SPFCOBNUMFLDLEN);      //~va50I~
#else                                                              //~va50I~
    	memset(Pdata,' ',SPFCOBNUMFLDLEN);                         //~v420I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	if (Pdbcs)                                                 //~v739I~
    	{                                                          //~v739I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5eI~
			swupdate=1;                                            //~va50I~
        	setobtabdbcs(swebcfile,0,Pdata,Pdbcs,lrecl,0,SPFCOBNUMFLDLEN);//outbound tab clear//~va5eI~//~va50R~
#else                                                              //~va5eI~
        	setobtabdbcs(Pdata,Pdbcs,lrecl,0,SPFCOBNUMFLDLEN);//outbound tab clear//~v739I~
#endif //UTF8EBCD raw ebcdic file support                          //~va5eI~
        	memset(Pdbcs,0,SPFCOBNUMFLDLEN);                       //~v739I~
    	}                                                          //~v739I~
    }                                                              //~v739I~
//  else                                                           //~v42uR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	UCVEBC_memset_space(swebcfile,Pdata+spfpos,SPFNUMFLDLEN);  //~va50I~
#else                                                              //~va50I~
    	memset(Pdata+spfpos,' ',SPFNUMFLDLEN);                     //~v416I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	if (Pdbcs)                                                 //~v739I~
    	{                                                          //~v739I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5eI~
			swupdate=1;                                            //~va50I~
        	setobtabdbcs(swebcfile,0,Pdata,Pdbcs,lrecl,spfpos,SPFNUMFLDLEN);//outbound tab clear//~va5eI~//~va50R~
#else                                                              //~va5eI~
        	setobtabdbcs(Pdata,Pdbcs,lrecl,spfpos,SPFNUMFLDLEN);//outbound tab clear//~v739I~
#endif                                                             //~va5eI~
//      	memset(Pdbcs,0,SPFNUMFLDLEN);                          //~v78AR~
        	memset(Pdbcs+spfpos,0,SPFNUMFLDLEN);                   //~v78AI~
    	}                                                          //~v739I~
 }                                                                 //~v42uI~
 else                                                              //~v42uI~
 if (Popt & SETSPFNUM_COB)                                         //~v42uI~
 {                                                                 //~v739I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    UCVEBC_memset_space(swebcfile,Pdata,SPFCOBNUMFLDLEN);          //~va50I~
#else                                                              //~va50I~
    memset(Pdata,' ',SPFCOBNUMFLDLEN);                             //~v42uI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (Pdbcs)                                                     //~v739I~
    {                                                              //~v739I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5eI~
		swupdate=1;                                                //~va50I~
        setobtabdbcs(swebcfile,0,Pdata,Pdbcs,lrecl,0,SPFCOBNUMFLDLEN);//outbound tab clear//~va5eI~//~va50R~
#else                                                              //~va5eI~
        setobtabdbcs(Pdata,Pdbcs,lrecl,0,SPFCOBNUMFLDLEN);//outbound tab clear//~v739I~
#endif //UTF8EBCD raw ebcdic file support                          //~va5eI~
        memset(Pdbcs,0,SPFCOBNUMFLDLEN);                           //~v739I~
    }                                                              //~v739I~
 }                                                                 //~v739I~
 else                                                              //~v416R~
 {                                                                 //~v416R~
                                                                   //~v42rI~
  if (Popt & SETSPFNUM_FORCE    //num cmd(renum or clear)          //~v42rI~
  ||  !UCBITCHK(Ppfh->UFHflag5,UFHF5NUMCLEARED)) //not once cleared//~v42rI~
  {                                                                //~v42rI~
  if (!UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM)	//already clear req//~v40FR~
//||  (Popt & SETSPFNUM_FORCE))                                    //~v412R~
     )                                                             //~v412I~
  {                                                                //~v40FM~
    ovf=(int)strlen(wkedit)-SPFNUMFLDLEN;                          //~v0clR~
//   if (Popt & SETSPFNUM_CLEAR)                                   //~v416R~
//    memset(Pdata+spfpos,' ',SPFNUMFLDLEN);                       //~v416R~
//   else                                                          //~v416R~
    memcpy(Pdata+spfpos,wkedit+ovf,SPFNUMFLDLEN);                  //~v0clR~
    if (Pdbcs)                                                     //~v0clI~
    {                                                              //~v0eLI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5eI~
		swupdate=1;                                                //~va50I~
        setobtabdbcs(swebcfile,0,Pdata,Pdbcs,spfpos+SPFNUMFLDLEN,spfpos,SPFNUMFLDLEN);//outbound tab clear//~va5eI~//~va50R~
#else                                                              //~va5eI~
        setobtabdbcs(Pdata,Pdbcs,spfpos+SPFNUMFLDLEN,spfpos,SPFNUMFLDLEN);//outbound tab clear//~v0eLM~
#endif //UTF8EBCD raw ebcdic file support                          //~va5eI~
    	memset(Pdbcs+spfpos,0,SPFNUMFLDLEN);                       //~v0clR~
    }                                                              //~v0eLI~
  }//auto renum                                                    //~v40FM~
    if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB)   //cobol spf file       //~v42vR~
//  &&  !UCBITCHK(Ppfh->UFHflag5,UFHF5COB2))  //no space cobnum    //~v47AR~
    &&  (!UCBITCHK(Ppfh->UFHflag5,UFHF5COB2)                       //~v47AI~
        ||(Popt & SETSPFNUM_COBKRENUM)))                           //~v47AI~
    {                                                              //~v40EI~
    	sprintf(wkedit2,"%04ld%02d",Pplh->ULHlinenor%10000,Pplh->ULHsuffix%100);//~v40WR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  	UCVEBC_a2bfld(swebcfile,wkedit2,0/*len*/);                 //~va50R~//~va79R~
    	UCVEBC_a2bfld(swebcfile,handle,wkedit2,0/*len*/);          //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        memcpy(Pdata,wkedit2,SPFCOBNUMFLDLEN);                     //~v40TR~
        if (Pdbcs)                                                 //~v40EI~
        {                                                          //~v40EI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5eI~
			swupdate=1;                                            //~va50I~
            setobtabdbcs(swebcfile,0,Pdata,Pdbcs,spfpos+SPFNUMFLDLEN,0,SPFCOBNUMFLDLEN);//outbound tab clear//~va5eI~//~va50R~
#else                                                              //~va5eI~
            setobtabdbcs(Pdata,Pdbcs,spfpos+SPFNUMFLDLEN,0,SPFCOBNUMFLDLEN);//outbound tab clear//~v40EI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5eI~
            memset(Pdbcs,0,SPFCOBNUMFLDLEN);                       //~v40EI~
        }                                                          //~v40EI~
    }                                                              //~v40EI~
  }//num cmd or not once cleared                                   //~v42rI~
 }//not clear option                                               //~v416I~
 	if (Pnewlen>0)                                                 //~v73bR~
    {                                                              //~v73bI~
    	if (Pdbcs)                                                 //~v73bI~
        {                                                          //~va50I~
//**not effective because setobtabdbcs already cleard for en       //~va20R~
//**but effective for ec(73-80 is any but length=80; dbcs split by 80 byte)//~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
          if (Pnewlen>0 && Pnewlen<Pplh->ULHlen && UDBCSCHK_DBCSNOTEND(*(Pdbcs+Pnewlen-1)))//~va20R~
#else                                                              //~va20I~
          if (Pnewlen>0 && Pnewlen<Pplh->ULHlen && *(Pdbcs+Pnewlen-1)==DBCS1STCHAR)//~v78zI~
#endif                                                             //~va20I~
          {                                                        //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5eI~
			swupdate=1;                                            //~va50I~
        	setobtabdbcs(swebcfile,0,Pdata,Pdbcs,Pplh->ULHlen,Pnewlen,0);//outbound tab clear//~va5eI~//~va50R~
#else                                                              //~va5eI~
        	setobtabdbcs(Pdata,Pdbcs,Pplh->ULHlen,Pnewlen,0);//outbound tab clear//~v73bI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5eI~
          }                                                        //~va50I~
        }//Pdbcs                                                   //~va50I~
        Pplh->ULHlen=Pnewlen;                                      //~v73bI~
    }                                                              //~v73bI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	if (swupdate)                                                  //~va50I~
        XEEBC_setdbcstblplh(swebcfile,Ppfh,Pplh);                  //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    return addlen;                                                 //~v0clI~
}//filesetspfnum                                                   //~v0clI~
                                                                   //~v0clI~
//************************************************************     //~v0cnI~
// filesetspfnumedit                                               //~v0cnI~
//  called from ando and cidtopc isrt                              //~v40WI~
//*spf num filed setup(asumption:lrecl is right)                   //~v0cnI~
//*parm1:pfh                                                       //~v0cnI~
//*parm2:plh                                                       //~v0cnI~
//*parm3:opt  0:ver from pfh,1:ver from plh                        //~v0cnI~
//*return:none                                                     //~v0cnI~
//************************************************************     //~v0cnI~
void filespfnumedit(PUFILEH Ppfh,PULINEH Pplh,int Popt)            //~v0cnI~
{                                                                  //~v0cnI~
    int spfpos;                                                    //~v40WR~
    int ver;                                                       //~v0cqI~
    int cobsw=0;                                                   //~v40WI~
    char wkedit[16];                                               //~v0cnI~
    int handle;                                                    //~va79I~
//*****************                                                //~v0cnI~
	if (Popt & SPFNUMEDIT_COB)                                     //~v40WI~
    {                                                              //~v40WI~
		Popt &=~SPFNUMEDIT_COB;                                    //~v40WI~
        cobsw=1;                                                   //~v40WI~
    }                                                              //~v40WI~
  if (Popt & SPFNUMEDIT_CIDTOP)                                    //~v40WI~
  {                                                                //~v40WI~
	Popt &=~SPFNUMEDIT_CIDTOP;                                     //~v40WI~
  	spfpos=STDSPFLRECL-SPFNUMFLDLEN;                               //~v40WI~
  }                                                                //~v40WI~
  else                                                             //~v40WI~
    spfpos=Ppfh->UFHspfpos;                                        //~v0cnI~
//  lineno=(int)Pplh->ULHlinenor*10000+Pplh->ULHsuffix*100;        //~v40WR~
                                                                   //~v0cqI~
    if (Popt)                                                      //~v0cqI~
    	ver=Pplh->ULHspfver;                                       //~v0cqI~
	else                                                           //~v0cqI~
    	ver=Ppfh->UFHspfver+1;                                     //~v0cqI~
    if (ver>SPFNUMMAXVER)                                          //~v0cqI~
        ver=SPFNUMMAXVER;                                          //~v0cqR~
//  lineno+=ver;                                                   //~v40WR~
                                                                   //~v0cqI~
//  sprintf(wkedit,"%08d",lineno);                                 //~v40WR~
//  ovf=(int)strlen(wkedit)-SPFNUMFLDLEN;                          //~v40WR~
//  memcpy(Pplh->ULHdata+spfpos,wkedit+ovf,SPFNUMFLDLEN);          //~v40WR~
    sprintf(wkedit,"%04ld%02d%02d",Pplh->ULHlinenor%10000,Pplh->ULHsuffix%100,ver%100);//~v40WR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	handle=Ppfh->UFHhandle;                                        //~va79I~
//  UCVEBC_a2bfld(PFH_ISEBC(Ppfh),wkedit,0/*len*/);                //~va50R~//~va79R~
    UCVEBC_a2bfld(PFH_ISEBC(Ppfh),handle,wkedit,0/*len*/);         //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    memcpy(Pplh->ULHdata+spfpos,wkedit,SPFNUMFLDLEN);              //~v40WI~
    if (cobsw)                                                     //~v40WI~
	    memcpy(Pplh->ULHdata,wkedit,SPFCOBNUMFLDLEN);              //~v40WR~
    return;                                                        //~v0cnI~
}//filespfnumedit                                                  //~v0cnI~
                                                                   //~v0cnI~
//**************************************************************** //~v0cmR~
// fileresetver                                                    //~v0cmR~
//*renumber line number and free undo stack                        //~v0cmR~
//*parm1 :pcw                                                      //~v0cmR~
//*parm2 :pfh                                                      //~v0cmR~
//*parm3 :operand version no                                       //~v0cmR~
//*return:rc                                                       //~v0cmR~
//**************************************************************** //~v0cmR~
int fileresetver(PUCLIENTWE Ppcw,UFILEH *Ppfh,int Pver)            //~v0cmR~
{                                                                  //~v0cmR~
	PUQUEH qh;                                                     //~v0cmR~
	PULINEH plh;                                                   //~v0cmR~
	PULINEH plhlastdata=0;                                         //~v0coI~
	PULINEH plh1st=0;                                              //~v0coI~
    int ver,maxver,downno;                                         //~v0cmR~
    int upno;                                                      //~v0cmR~
//*********************************                                //~v0cmR~
    if (!UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR))    //~v0ctR~
    	return filenotspferr();                                    //~v0cmR~
	maxver=Ppfh->UFHspfver;                                        //~v0cmR~
	if (Pver==-1)                                                  //~v0cmR~
    	return filespfver(maxver);                                 //~v0cmR~
    if (!UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK))                   //~v0ctR~
    	return filenotspferr();                                    //~v0ctI~
	if (Pver>SPFNUMMAXVER)                                         //~v0cqR~
    	return filespfvererr();                                    //~v0cmR~
    UPCTRREQ(Ppfh);         //write at save                        //~v0coM~
                                                                   //~v0coI~
	qh=&(Ppfh->UFHlineque);                                        //~v0cmR~
	plh=(PULINEH)UGETQTOP(qh);                                     //~v0cmR~
    upno=0;                                                        //~v0cmR~
    downno=maxver-Pver;	//down level                               //~v0cmR~
	while(plh)                                                     //~v0cmR~
	{                                                              //~v0cmR~
        if (plh->ULHtype==ULHTDATA)                                //~v0cmR~
        {                                                          //~v0cmR~
            plhlastdata=plh;                                       //~v0coI~
            if (downno<=0)	//version up                           //~v0coI~
            	break;      //no need to line change,pfh change only//~v0coI~
          	ver=(int)plh->ULHspfver;                               //~v0cmR~
            if (ver)                                               //~v0cmR~
            {                                                      //~v0cmR~
                if (Pver)                                          //~v0cmR~
                {                                                  //~v0cmR~
            		ver-=downno;                                   //~v0cmR~
                	if (ver<=0)                                    //~v0cmR~
	                	ver=1;                                     //~v0cmR~
				}                                                  //~v0cmR~
				else                                               //~v0cmR~
	               	ver=0;                                         //~v0cmR~
				upno++;                                            //~v0cmR~
                if (!plh1st)	                                   //~v0coI~
                	plh1st=plh;                                    //~v0coI~
//*spfver,no dbcstbl chng                                          //~va50I~
      			if (undoupdate(Ppcw,plh,UUHTSPFVER)==UALLOC_FAILED)//~v0cmR~
    	        	return UALLOC_FAILED;                          //~v0cmR~
                plh->ULHspfver=(UCHAR)ver;                         //~v0cmR~
                filesetvernum(Ppfh,plh);                           //~v0cmR~
            }	                                                   //~v0cmR~
		}                                                          //~v0cmR~
		plh=UGETQNEXT(plh);                                        //~v0cmR~
	}                                                              //~v0cmR~
	if (!plhlastdata)	//no data line                             //~v0coI~
    {                                                              //~v0coI~
	    uerrmsg("No data line",                                    //~v0coI~
    	        "データ行がありません");                           //~v0coI~
    	return 4;                                                  //~v0coI~
	}                                                              //~v0coI~
    uerrmsg("Version changed(%d-->%d),%d line changed",            //~v0cnR~
            "バージョン番号変更(%d-->%d),%d行の変更",              //~v0cnR~
            maxver,Pver,upno);                                     //~v0cnR~
//*spfver,no dbcstbl chng                                          //~va50I~
	if (undoprep(Ppcw,plhlastdata,UUHTSPFVERMAX)==UALLOC_FAILED)   //~v0coI~
    	return UALLOC_FAILED;                                      //~v0coI~
    Ppfh->UFHspfver=(UCHAR)Pver;                                   //~v0cmI~
    UPCTRREQ(Ppfh);         //write at save                        //~v0cmR~
    if (plh1st)                                                    //~v0coI~
    	undocsrmove(Ppcw,plh1st);                                  //~v0coI~
    return 0;                                                      //~v0cmR~
}//fileresetver                                                    //~v0cmR~
                                                                   //~v0cmR~
//**************************************************************** //~v0cmR~
// filesetvernum                                                   //~v0cmR~
//*set version on lineno fld                                       //~v0cmR~
//*parm1:pfh                                                       //~v0cmR~
//*parm2:plh                                                       //~v0cmR~
//*int  :0 set,4:short record bypassed                             //~v0cmR~
//**************************************************************** //~v0cmR~
int filesetvernum(PUFILEH Ppfh,PULINEH Pplh)                       //~v0cmR~
{                                                                  //~v0cmR~
    int pos;                                                       //~v0cmR~
    char editwk[16];                                               //~v0cmR~
    int handle;                                                    //~va79I~
//************************                                         //~v0cmR~
	pos=Ppfh->UFHlrecl;                                            //~v0cmR~
    if (pos>Pplh->ULHlen)                                          //~v0cmR~
    	return 4;                                                  //~v0cmR~
    sprintf(editwk,"%02d",(int)Pplh->ULHspfver);                   //~v0cmR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	handle=Ppfh->UFHhandle;                                        //~va79I~
//  UCVEBC_a2bfld(PFH_ISEBC(Ppfh),editwk,0/*len*/);                //~va50R~//~va79R~
    UCVEBC_a2bfld(PFH_ISEBC(Ppfh),handle,editwk,0/*len*/);         //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	memcpy(Pplh->ULHdata+pos-SPFNUMVERLEN,editwk,SPFNUMVERLEN);    //~v0cmR~
	return 0;                                                      //~v0cmR~
}//filesetvernum                                                   //~v0cmR~
                                                                   //~v0cmR~
//**************************************************************** //~v0clI~
//!filelineerr                                                     //~v0clI~
//   reverse err line                                              //~v0clI~
//*parm1:plh                                                       //~v0clI~
//*rc   :none                                                      //~v0clI~
//**************************************************************** //~v0clI~
void filesetlineerr(PULINEH Pplh)                                  //~v0clI~
{                                                                  //~v0clI~
//********************                                             //~v0clI~
    UCBITON(Pplh->ULHflag,ULHFDRAW); //reverse                     //~v0clI~
    UCBITON(Pplh->ULHflag3,ULHF3ERRLINE);    //reverse             //~v0clI~
	return;                                                        //~v0clI~
}//filesetlineerr                                                  //~v0clI~
                                                                   //~v0clI~
//**************************************************************** //~v0clI~
// filespfnumerr                                                   //~v0clI~
//*spf lineno numeric err                                          //~v0clI~
//*parm:none                                                       //~v0clI~
//*rc  :none;                                                      //~v0clI~
//**************************************************************** //~v0clI~
void filespfnumerr(void)                                           //~v0clR~
{                                                                  //~v0clI~
//*******************                                              //~v0clI~
    uerrmsg("Line-No field numeric err of Numbered-Line-File",     //~v0clR~
            "行番号付きファイルの行番号欄数値エラー");             //~v0clR~
    ubell();                                                       //~v0clI~
    return;                                                        //~v0clI~
}//filespfnumerr                                                   //~v0clI~
//**************************************************************** //~v61gI~
// filespfcobnumerr                                                //~v61gI~
//*rc  :none;                                                      //~v61gI~
//**************************************************************** //~v61gI~
void filespfcobnumerr(void)                                        //~v61gI~
{                                                                  //~v61gI~
//*******************                                              //~v61gI~
    uerrmsg("COBOL Line-No field numeric err",                     //~v61gI~
            "COBOL行番号欄数値エラー");                            //~v61gI~
    ubell();                                                       //~v61gI~
    return;                                                        //~v61gI~
}//filespfcobnumerr                                                //~v61gI~
                                                                   //~v0clI~
//**************************************************************** //~v42vI~
// filespferrnotspace                                              //~v42vI~
//*spf lineno numeric err                                          //~v42vI~
//*parm:none                                                       //~v42vI~
//*rc  :none;                                                      //~v42vI~
//**************************************************************** //~v42vI~
void filespferrnotspace(void)                                      //~v42vI~
{                                                                  //~v42vI~
//*******************                                              //~v42vI~
    uerrmsg("COBOL lineno(coil1-6) is not space;option=(..,cobk,..)",//~v44iR~
            "COBOL 行番号がスペースでない;option=(..,cobk,..)");   //~v44iR~
    ubell();                                                       //~v42vI~
    return;                                                        //~v42vI~
}//filespferrnotspace                                              //~v42vI~
                                                                   //~v42vI~
//**************************************************************** //~v0clI~
// filespflenerr                                                   //~v0clI~
//*spf lineno length err                                           //~v0clI~
//*parm:none                                                       //~v0clI~
//*rc  :none;                                                      //~v0clI~
//**************************************************************** //~v0clI~
void filespflenerr(int Plen)                                       //~v0clR~
{                                                                  //~v0clI~
//*******************                                              //~v0clI~
    uerrmsg("Line length err(!=%d) of Numbered-Line-File",         //~v0clR~
            "行番号付きファイルの行長エラー(!=%d)",                //~v0clI~
            Plen);                                                 //~v0clI~
    ubell();                                                       //~v0clI~
    return;                                                        //~v0clI~
}//filespflenerr                                                   //~v0clI~
                                                                   //~v0clI~
//**************************************************************** //~v0clI~
// filespfseqerr                                                   //~v0clI~
//*spf lineno sequence err                                         //~v0clI~
//*parm:none                                                       //~v0clI~
//*rc  :none;                                                      //~v0clI~
//**************************************************************** //~v0clI~
void filespfseqerr(void)                                           //~v0clR~
{                                                                  //~v0clI~
//*******************                                              //~v0clI~
    uerrmsg("Line-No sequence err of Numbered-Line-File",          //~v0clR~
            "行番号付きファイルの行番号順序エラー");               //~v0clR~
    ubell();                                                       //~v0clI~
    return;                                                        //~v0clI~
}//filespfseqerr                                                   //~v0clI~
                                                                   //~v0clI~
//**************************************************************** //~v0clI~
// filespfvermaxerr                                                //~v0clI~
//*spf version max over                                            //~v0clI~
//*parm1:cur version no                                            //~v0clI~
//*parm2:limit                                                     //~v0clI~
//*rc  :none;                                                      //~v0clI~
//**************************************************************** //~v0clI~
void filespfvermaxerr(int Pver,int Plimit)                         //~v0clR~
{                                                                  //~v0clI~
//*******************                                              //~v0clI~
    uerrmsg("Vesion-No on Line-No(%d) column reached to limit(%d)",//~v0clR~
            "行番号欄のバージョン番号(%d)が制限値(%d)に達しています",//~v0clR~
            Pver,Plimit);                                          //~v0clI~
    ubell();                                                       //~v0clI~
    return;                                                        //~v0clI~
}//filespfseqerr                                                   //~v0clI~
                                                                   //~v0clI~
//**************************************************************** //~v0clI~
// filespfpfeerr                                                   //~v0clI~
//*partial edit not allowed for spf file                           //~v0clI~
//*parm:none                                                       //~v0clI~
//*rc  :none;                                                      //~v0clI~
//**************************************************************** //~v0clI~
void filespfpfeerr(void)                                           //~v0clI~
{                                                                  //~v0clI~
//*******************                                              //~v0clI~
    uerrmsg("Partial edit not allowed for Numbered-Line-File",     //~v0clI~
            "行番号付きファイルは部分編集出来ません");             //~v0clI~
    return;                                                        //~v0clI~
}//filespfpfeerr                                                   //~v0clI~
                                                                   //~v0clI~
//**************************************************************** //~v0clI~
// filenotspferr                                                   //~v0clI~
//*not spf file                                                    //~v0clI~
//*parm:none                                                       //~v0clI~
//*rc  :4                                                          //~v0clI~
//**************************************************************** //~v0clI~
int filenotspferr(void)                                            //~v0clI~
{                                                                  //~v0clI~
//*******************                                              //~v0clI~
    uerrmsg("This is not valid Numbered-Line-File",                //~v0ctR~
            "これは正しい行番号付きファイルではありません");       //~v0ctR~
    return 4;                                                      //~v0clI~
}//filespfpfeerr                                                   //~v0clI~
                                                                   //~v0clI~
//**************************************************************** //~v0clI~
// filespfvererr                                                   //~v0clI~
//*not spf file                                                    //~v0clI~
//*parm:none                                                       //~v0clI~
//*rc  :4                                                          //~v0clI~
//**************************************************************** //~v0clI~
int filespfvererr(void)                                            //~v0cqR~
{                                                                  //~v0clI~
//*******************                                              //~v0clI~
    uerrmsg("Max version is %d",                                   //~v0cqR~
            "バージョン番号は最大 %d",                             //~v0cqR~
			SPFNUMMAXVER);                                         //~v0cqR~
    return 4;                                                      //~v0clI~
}//filespfpfeerr                                                   //~v0clI~
                                                                   //~v0clI~
//**************************************************************** //~v0clM~
// postfix err                                                     //~v0clM~
//*parm :version                                                   //~v0clM~
//*rc   :4                                                         //~v0clM~
//**************************************************************** //~v0clM~
int filespfver(int Pver)                                           //~v0clI~
{                                                                  //~v0clM~
	uerrmsg("Current Version is %d",                               //~v0clM~
			"現バージョンは %d",                                   //~v0clM~
			Pver);                                                 //~v0clM~
	return 0;                                                      //~v0clM~
}//filespfver                                                      //~v0clI~
                                                                   //~v0ctI~
//**************************************************************** //~v0ctI~
// postfix err                                                     //~v0ctI~
//*parm :version                                                   //~v0ctI~
//*rc   :4                                                         //~v0ctI~
//**************************************************************** //~v0ctI~
int filespfneedforce(void)                                         //~v0ctI~
{                                                                  //~v0ctI~
    uerrmsg("Numbered-Line-File has err lines,Use Force option",   //~v0ctI~
            "エラー行のある行番号付きファイル,Forceオプションが必要です");//~v0ctI~
	return 4;                                                      //~v0ctI~
}//filespfver                                                      //~v0ctI~
