//CID://+vb30R~:                            Update#=  118          //~vafkR~//~vb2FR~//+vb30R~
//*************************************************************
//*xefile4.c*                                                      //~v50NR~
//**changeid                                                    //~4C23R~
//*************************************************************
//vb30:160411 (LNX)Compiler warning                                //+vb30I~
//vb2F:160229 W32 64 compiler warning                              //~vb2FI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va7J:100904 avoid topline cid option err("CID" was found on topline at tail of the line")//~va7JI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            file42.c:ddfmt margin chk                            //~va20I~
//v78u:080329 (BUG)ABEND at save for short line if the file is fixded lrecl and notabclear(by cid topline)//~v78uI~
//v75s:070427 option to specify fixed lrecl on top cid specification line//~v75sI~
//v74G:070324*(BUG of v74E)missing initial variable clrat          //~v74GI~
//v74E:070315 BOUNDS cmd support(find,shift-lcmd,paste-lcmd)       //~v74EI~
//v73g:070112 (BUG)margin chk is not correct when rep char by TAB using vhex mode//~v73gI~
//v71U:061112 (BUG)accept insert in short(<mergin) record of margined file//~v71UI~
//v53f:030925 (BUG)topline cid; "update#" is err when last is "..,cob) update#="//~v53fI~
//v50N:030208 (BUG)update ctr overflow msg when initialy top line updated//~v47yI~
//v47y:020317 (BUG)topline cid option is ignored when mergin is missing.//~v47yI~
//v47x:020317 (BUG)topline cid err when cobk is last option=(,,cobk)//~v47xI~
//v47v:020316 COBK w/o N is not spf(allow any char in col.1-6;any lrecl)//~v42vI~
//v42x:011010 col1-6=space cobol by /Mk(change option=cob2-->cobk) //~v42xI~
//v42v:011009 option to allow cob num fld is all space             //~v42vI~
//v42g:010929 spf join ignoreing num fld                           //~v42gI~
//v429:010924 allow clipos=>margin if not numbered                 //~v429I~
//v421:010918 set default cidpos to 63 for spf file                //~v421I~
//v41x:010910 (BUG)added numfld on col81- even if no "n" option for cobol//~v41xI~
//v41h:010806 option effective sequence:topline>cmd option>default //~v41hI~
//v414:010728 EC/ENC/BC/BNC/SC/SNC cmd add for cobol               //~v414I~
//v40V:010722 allow space for top cid option delm                  //~v40VI~
//v40D:010709 COB support:cid tobcob                               //~v40DI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v20P:001111 allow topline upctr init value when no line at load time//~v20PI~
//v20v:001022 topcid line option to tab clear when file output(option=(tc)//~v20vI~
//v20t:001022 Source update ctr support on CID line                //~v20tI~
//v10L:990424 EN/BN/SN edit/browse command for SPF file specific.(No cid,margin=72,P=1)//~v10LI~
//v10C:990411 errmsg modigy(valid cidpos)                          //~v10CI~
//v0eO:971005 (BUG)dropping N option leave NUMOK/NUMERR flag on pfh//~v0eOI~
//            with spfpos=0.it cause to write lineno at pos=0 when save.//~v0eOI~
//v0eJ:970927 accept protect option only if mergin specified       //~v0eJI~
//v0ey:970920 v0eq to change cmd                                   //~v0eyI~
//v0ex:970922 (BUG)filemerginchk;trailer space len must after cpos //~v0exI~
//v0ev:970922 abondan /v0ep/v0er/v0es/v0eu;                        //~v0evI~
//            use filetabexp2(expand in mergin only)               //~v0evI~
//v0er:970921 (BUG)shitback err when isrt if tab is on oom         //~v0erI~
//v0eq:970920 optionaize to update oom.default is prohibit(option=(p1))//~v0eqI~
//v0em:970919 topline cid;option Mnn instead of MERGIN=            //~v0emI~
//v0e3:970914 allow change cmd on out of mergin                    //~v0e3I~
//v0d4:970830 CID header spf file id by OPTION=(N) parm            //~v0d4R~
//v0cl:970811 spf NUM field support                                //~v0clI~
//v0cb:970802 split allow for long rec even if at out of mergin    //~v0cbI~
//            EOL   allow for long rec even if at out of mergin    //~v0cbI~
//            if mergin=cidpos=topcidpos remain cid                //~v0cbI~
//            else same as no mergin specified                     //~v0cbI~
//v0c8:970802 filecidlrecl return len in mergin if cidps<mergin    //~v0c8I~
//v0c6:970802 continue column before mergin is arbitaly            //~v0c6R~
//v0c2:970728 simple principle.do not touch/move out of mergin     //~v0c2I~
//            if mergin not specified,last space is not dropped    //~v0c2I~
//v0c1:970728 errornous cid shift when 2 continuous cid            //~v0c1I~
//v0bz:970728 if last is tab,expandlen over mergin cause expand err.//~v0bzI~
//            but it can be cut in mergin and set cid on normal pos.//~v0bzI~
//v0bw:970728 hdrline parameter change MAXREC-->MERGIN             //~v0bwI~
//            if cid pos is in the range of mergin,                //~v0bwI~
//            if cid pos is in the range meginchk dose not ignore cid//~v0bwI~
//            Cid set can be missed by long data                   //~v0bwI~
//v0bv:970728 split file4-->file42                                 //~v0bvI~
//v0be:970725 filemerginchk return lrecl witoutcid(change over v0b7)//~v0beI~
//v0bb:970726 limit tabctr max 12,and tab expand limit chk         //~v0bbI~
//v0b8:970725 keep cid pos when shift left if cid shift into mergin//~v0b8I~
//v0b7:970725 filemerginchk return avail space(last data to mergin)//~v0b7I~
//v0b3:970723 clear tab when shift,it is easy to expectate.        //~v0b3I~
//v0ax:970720 (BUG)cid pos remain after "#cidpos" clear(use ustrlen by strlen)//~v0axI~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//           -filetoplinecid return rc                             //~v0avI~
//           -charmaxovererr has maxlen parm                       //~v0avI~
//           -expand pre chk(split file2 to file6)                 //~v0avI~
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
#include <uedit.h>                                                 //~v0avI~
#include <ufile.h>                                              //~5318I~
#ifdef UTF8UCS2                                                    //~va20I~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20I~
#include <ucvebc.h>                                                //~va50I~
                                                                //~4C19I~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefile.h"
#include "xefile12.h"                                              //~v0e3I~
#include "xefile4.h"                                            //~5122I~
#include "xefile42.h"                                              //~v0bvI~
#include "xefile6.h"                                               //~v0avI~
#include "xelcmd4.h"                                               //~v0b8R~
#include "xechar.h"                                                //~v0avI~
#include "xesub.h"                                              //~5318I~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xesub2.h"                                                //~va20I~
#include "xeutf2.h"                                                //~va20R~
#endif                                                             //~va20I~
//*******************************************************
#define CIDNUMFLDID   'N'                                          //~v0avI~
#define SPFLRECL 80                                                //~v10LI~
//*******************************************************          //~v20tI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int filetoplineuctr(PUFILEH Ppfh,PULINEH Pplh,int *Ppupctrposlen); //~va50I~
#else                                                              //~va50I~
int filetoplineuctr(PUFILEH Ppfh,PULINEH Pplh);                    //~v20tI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//************************************************************     //~v0avI~
// filetoplinelrecl                                                //~v0avI~
//   set lrecl,mergin,numfldpos                                    //~v0avI~
//   for ebc file,data is translated to mb string by filetoplinecid//~va50I~
//*parm1:pfh                                                       //~v0avI~
//*parm2:plh                                                       //~v0avR~
//*parm3:no cid pos parm sw                                        //~v421I~
//*return:0 :gotten ,4 no specification 8:err ignored              //~v0avI~
//************************************************************     //~v0avI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int filetoplinelrecl(PUFILEH Ppfh,PULINEH Pplh,int Pdefaultcidpossw,int *Ppupctrposlen)//~va50I~
#else                                                              //~va50I~
int filetoplinelrecl(PUFILEH Ppfh,PULINEH Pplh,int Pdefaultcidpossw)//~v421R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
{                                                                  //~v0avI~
//static UCHAR Smaxrecid[]="MERGIN=";                              //~v0emR~
static UCHAR Soptionid[]="OPTION=(";                               //~v0d4I~
    UCHAR *pc;                                                     //~v0avI~
    int lrecl,numfsz=0;                                            //~v0d4R~
    int len,len2;                                                  //~v0axR~
    int cidpos;                                                    //~v0avI~
    int cidlen,mergin=0;                                           //~v0emR~
    int ii,jj;                                                     //~v40DR~
    int len3;                                                      //~v0emI~
    int plevel;                                                    //~v0eqI~
    int nopdsw=0;                                                  //~v40DI~
    int fixedlrecl=0;                                              //~v75sI~
    char erropt[12];                                               //~v40DI~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
    UCHAR *pcd0,*pcd=NULL;                                              //~va20R~//~vaf9R~
#endif                                                             //~va20I~
//*****************************                                    //~v0avI~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20I~
    pcd0=Pplh->ULHdbcs;                                            //~va20I~
    if (!pcd0)                                                     //~va20I~
        swutf8file=0;   //in load process                          //~va20I~
#endif                                                             //~va20I~
	UCBITOFF(Ppfh->UFHflag5,UFHF5DROPTAB);	//once reset           //~v20vI~
    plevel=!UCBITCHK(Gopt3,GOPT3OOMNOPROT);//if NOPROT pl=0;       //~v0eqI~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4SPFCMD))   // /Mn option      //~v414R~
    {                                                              //~v10LI~
    	mergin=SPFLRECL-SPFNUMFLDLEN;                              //~v10LR~
        numfsz=SPFNUMFLDLEN;                                       //~v10LI~
        plevel=1;                                                  //~v10LI~
//    if (!UCBITCHK(Ppfh->UFHflag5,UFHF5COB))  // /mc cmd cobol option//~v47yR~
  	  if (!UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM))  //col.72-80 is seqno.//~v47yI~
        nopdsw=1;                                                  //~v40DI~
	}                                                              //~v10LI~
    if (Pdefaultcidpossw)                                          //~v47vR~
        if (*Ppfh->UFHcid)                                         //~v47vR~
  		  if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB2)  	//cobk(col.1-6 is not seqno)//~v47yR~
  		  && UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM))  //col.72-80 is not seqno.//~v47vR~
    		Ppfh->UFHcidpos=(SPFLRECL-SPFNUMFLDLEN);               //~v47vR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (filetoplineuctr(Ppfh,Pplh,Ppupctrposlen)) //topline update ctr process//~va50I~
#else                                                              //~va50I~
    if (filetoplineuctr(Ppfh,Pplh)) //topline update ctr process   //~v20tR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	return 8;		//protect save                             //~v20tI~
    len=Pplh->ULHlen;                                              //~v0axR~
#ifdef UTF8UCS2                                                    //~va20I~
    if (pc=UTF_umemstri(swutf8file,Pplh->ULHdata,pcd0,Soptionid,0/*Soptionid dbcs*/,len),!pc)//case insense//~va20R~
#else                                                              //~va20I~
    if (pc=umemstri(Pplh->ULHdata,Soptionid,(UINT)len),!pc)//case insense//~v0emI~
#endif                                                             //~va20I~
    	return 4;                                                  //~v0emI~
//  if (((ULONG)pc-(ULONG)Pplh->ULHdata)>=MAX_CIDOPTPOS)           //~va7JI~//~vafkR~
    if (((ULPTR)pc-(ULPTR)Pplh->ULHdata)>=MAX_CIDOPTPOS)           //~vafkI~
    	return 4;                                                  //~va7JI~
    pc+=sizeof(Soptionid)-1;                                   //~v0d4R~
//  len2=len-(int)((ULONG)pc-(ULONG)Pplh->ULHdata);            //~v0d4I~//~vafkR~
    len2=len-(int)((ULPTR)pc-(ULPTR)Pplh->ULHdata);                //~vafkI~
    for (ii=0;ii<len2 && *pc!=')';ii++,pc++)                   //~v0d4R~
    {                                                          //~v0d4I~
#ifdef UTF8UCS2                                                    //~va20I~
        if (swutf8file)                                            //~va20I~
        {                                                          //~va20I~
            pcd=XEUTF_PC2PCD(pcd0,pc,Pplh->ULHdata);               //~va20I~
            if (*pcd)   //not ascii                                //~va20R~
                continue;                                          //~va20I~
        }                                                          //~va20I~
#endif                                                             //~va20I~
        switch (toupper(*pc))                                  //~v0d4I~
        {                                                      //~v0d4I~
        case 'C':       //mergin                                   //~v40DI~
#ifdef UTF8UCS2                                                    //~va20I~
            if (len2>3 && !XESUB_memicmp(swutf8file,pc,pcd,"cobk",0,4))//~va20I~
#else                                                              //~va20I~
            if (len2>3 && !memicmp(pc,"cobk",4))                   //~v42xR~
#endif                                                             //~va20I~
            {                                                      //~v42vI~
//          	pc+=4;                                             //~v47xR~
//          	len2-=4;                                           //~v47xR~
            	pc+=3;                                             //~v47xI~
            	len2-=3;                                           //~v47xI~
            	UCBITON(Ppfh->UFHflag5,UFHF5COB|UFHF5COB2);  //cobol option//~v42vR~
            	numfsz=8;							//also spf     //~v42vI~
            	break;                                             //~v42vI~
            }                                                      //~v42vI~
#ifdef UTF8UCS2                                                    //~va20I~
            if (len2<3 || XESUB_memicmp(swutf8file,pc,pcd,"cob",0,3))//~va20I~
#else                                                              //~va20I~
            if (len2<3 || memicmp(pc,"cob",3))                     //~v40DI~
#endif                                                             //~va20I~
            {                                                      //~v40DI~
	            uerrmsg("Option value(%.*s) err",                  //~v40DI~
                    "オプション値(%.*s)エラー",                    //~v40DI~
                    min(len2,3),pc);                               //~v40DI~
    	        return 8;                                          //~v40DI~
            }                                                      //~v40DI~
//          pc+=3;                                                 //~v53fR~
//          len2-=3;                                               //~v53fR~
            pc+=2;      //2:to chk ")" after pc++                  //~v53fI~
            len2-=2;                                               //~v53fI~
            UCBITON(Ppfh->UFHflag5,UFHF5COB);  //cobol option      //~v40DI~
            numfsz=8;							//also spf         //~v40DI~
            break;                                                 //~v40DI~
        case 'F':       //fixed lrecl                              //~v75sI~
//*errmsg at when plhdbcs=0                                        //~va20I~
            len3=unumlen(pc+1,0,len); //digit len                  //~v75sI~
            fixedlrecl=uatoin(pc+1,len3);                          //~v75sI~
            pc+=len3;                                              //~v75sI~
            len2-=len3;                                            //~v75sI~
            break;                                                 //~v75sI~
        case 'M':       //mergin                               //~v0emI~
//*errmsg at when plhdbcs=0                                        //~va20I~
            len3=unumlen(pc+1,0,len); //digit len                  //~v0emR~
            mergin=uatoin(pc+1,len3);                              //~v0emR~
            if (!mergin)                                       //~v0emI~
            {                                                  //~v0emI~
                uerrmsg("Margin value(%d) err",                    //~v41xR~
                        "マージン値(%d)エラー",                //~v0emI~
                        mergin);                               //~v0emI~
                return 8;                                      //~v0emI~
            }                                                  //~v0emI~
                                                               //~v0emI~
            pc+=len3;                                          //~v0emI~
            len2-=len3;                                        //~v0emI~
            break;                                             //~v0emI~
        case 'N':                                              //~v0d4I~
            numfsz=8;                                          //~v0d4I~
    	    nopdsw=1;		//'N' opd specified                    //~v40DI~
            break;                                             //~v0d4I~
        case 'P':       //protect level                            //~v0eqI~
        	plevel=*(pc+1)-'0';                                    //~v0eqR~
            if (plevel<0 || plevel>1)                              //~v0eqI~
            {                                                      //~v0eqI~
                uerrmsg("Out of Margin Protect level(%c) err",     //~v41xR~
                        "マージン外保護レベル値(%c)エラー",        //~v0eqR~
                        *(pc+1));                                  //~v0eqI~
                return 8;                                          //~v0eqI~
            }                                                      //~v0eqI~
            pc++;                                                  //~v0eqI~
            len2--;                                                //~v0eqI~
            break;                                                 //~v0eqI~
        case 'T':                                                  //~v20vI~
#ifdef UTF8UCS2                                                    //~va20I~
            if (len2<8 || XESUB_memicmp(swutf8file,pc,pcd,"tabclear",0,8))//~va20I~
#else                                                              //~va20I~
            if (len2<8 || memicmp(pc,"tabclear",8))                //~v20vR~
#endif                                                             //~va20I~
            {                                                      //~v20vI~
	            uerrmsg("Option value(%.*s) err",                  //~v20vR~
                    "オプション値(%.*s)エラー",                    //~v20vR~
                    min(len2,8),pc);                               //~v20vR~
    	        return 8;                                          //~v20vI~
            }                                                      //~v20vI~
            pc+=7;                                                 //~v20vI~
            len2-=7;                                               //~v20vI~
            UCBITON(Ppfh->UFHflag5,UFHF5DROPTAB);  //drop tab at save//~v20vI~
            break;                                                 //~v20vI~
        case ',':                                              //~v0d4I~
        case ' ':                                                  //~v40VI~
            continue;                                          //~v0d4I~
        default:                                               //~v0d4I~
        	for (jj=0;jj<8;jj++,pc++)                              //~v40DI~
            	if (*pc==' '||*pc==','||*pc==')')                  //~v40DI~
                	break;                                         //~v40DI~
                else                                               //~v40DI~
                	erropt[jj]=*pc;                                //~v40DI~
            erropt[jj]=0;                                          //~v40DR~
            uerrmsg("Option value(%s) err",                        //~v40DR~
                    "オプション値(%s)エラー",                      //~v40DR~
                    erropt);                                       //~v40DR~
            return 8;                                          //~v0d4I~
        }                                                      //~v0d4I~
    }                                                          //~v0d4I~
                                                                   //~v0eqI~
//    if (!(pc=umemstri(Pplh->ULHdata,Smaxrecid,(UINT)len)))//case insense//~v0emR~
//        return 4;                                                //~v0emR~
    if (numfsz)		//Mc /Mn SPFCMD                                //~v47yI~
    {                                                              //~v47yI~
        if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB))  //cobol option     //~v47yI~
    		if (!nopdsw)		//'N' opd specified                //~v47yI~
            {                                                      //~v47yI~
		        UCBITON(Ppfh->UFHflag5,UFHF5NOAUTONUM);  //no use col72-80//~v47yI~
		        if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB2))  //cobol option//~v47yI~
	                numfsz=0;			//cobk w/o num             //~v47yI~
            }                                                      //~v47yI~
	    if (!mergin)                                               //~v47yI~
    		mergin=(UCHAR)(SPFLRECL-SPFNUMFLDLEN);                 //~v47yI~
    }                                                              //~v47yI~
    else                                                           //~v47yI~
    	UCBITOFF(Ppfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR);//no more spf file//~v47yI~
    if (fixedlrecl)                                                //~v75sR~
    {                                                              //~v75sI~
        if (fixedlrecl<mergin)                                     //~v75sR~
        {                                                          //~v75sI~
            uerrmsg("Fixed-LRECL value(%d) err,lower than margin(%d)",//~v75sR~
                    "固定長 LRECL 値(%d)エラー,マージンより小さい(%d)",//~v75sR~
                    fixedlrecl,mergin);                            //~v75sR~
            return 8;       //err line ignored                     //~v75sI~
        }                                                          //~v75sI~
        if (!mergin)                                               //~v75sI~
        	mergin=fixedlrecl;                                     //~v75sR~
    }                                                              //~v75sI~
    if (!mergin)	//no mergin specified                          //~v0emI~
        return 4;                                                  //~v0emI~
                                                                   //~v75sI~
//    pc+=sizeof(Smaxrecid)-1;                                     //~v0emR~
//    len-=(int)((ULONG)pc-(ULONG)Pplh->ULHdata);                  //~v0emR~
//    mergin=uatoin(pc,len);                                       //~v0emR~
//    if (!mergin)                                                 //~v0emR~
//    {                                                            //~v0emR~
//        uerrmsg("Mergin value(%d) err",                          //~v0emR~
//                "マージン値(%d)エラー",                          //~v0emR~
//                mergin);                                         //~v0emR~
//        return 8;                                                //~v0emR~
//    }                                                            //~v0emR~
//    len2=unumlen(pc,0,len); //digit len                          //~v0emR~
//    pc+=len2;                                                    //~v0emR~
//    len-=len2;                                                   //~v0emR~
//  if (len && toupper(*pc)==CIDNUMFLDID) //numfield contain       //~v0d4R~
//  	numfsz=8;                                                  //~v0d4R~
//  else                                                           //~v0d4R~
//  	numfsz=0;                                                  //~v0d4R~
    if (Pdefaultcidpossw)                                          //~v421I~
        if (*Ppfh->UFHcid)                                         //~v421I~
        {                                                          //~v71UI~
  		  if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB2)  	//cobk(col.1-6 is not seqno)//~v47vR~
  		  && UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM))  //col.72-80 is not seqno.//~v47vR~
    		Ppfh->UFHcidpos=(UCHAR)mergin;                         //~v47yR~
          else                                                     //~v47vR~
//        	Ppfh->UFHcidpos=(UCHAR)(mergin-strlen(Ppfh->UFHcid)-1);//last space//~v421R~//+vb30R~
          	Ppfh->UFHcidpos=(UCHAR)(mergin-(int)strlen(Ppfh->UFHcid)-1);//last space//+vb30I~
        }                                                          //~v71UI~
    cidpos=Ppfh->UFHcidpos;                                        //~v0avR~
    cidlen=Ppfh->UFHcidlen;                                        //~v0bwI~
//  if (lrecl<cidpos+Ppfh->UFHcidlen+numfsz                        //~v0bwR~
//  ||  lrecl>MAXLINEDATA)                                         //~v0bwR~
    if (mergin+cidlen>MAXLINEDATA)                                 //~v0bwI~
    {                                                              //~v0bwI~
//  	uerrmsg("Max record length(%d) is not enough for CID or over max(%d)",//~v0bwI~
//  			"最大レコード長(%d)がCIDエリア用に不十分か制限長(%d)以上です",//~v0bwI~
//  			lrecl,MAXLINEDATA);                                //~v0bwI~
    	uerrmsg("Margin(%d) + CID size(%d) is over max(%d)",       //~v41xR~
    			"マージン(%d) + CID長(%d)が制限長(%d)以上です",    //~v0c6R~
    			mergin,cidlen+1,MAXLINEDATA);                      //~v0bwR~
		return 8;                                                  //~v0bwI~
	}                                                              //~v0bwI~
    if (cidlen)                                                    //~v0bwI~
        if (cidpos==mergin)                                        //~v0bwI~
        {                                                          //~v41xI~
          if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB))  //cobol option   //~v41xI~
          {                                                        //~v41xI~
           if (numfsz)                                             //~v47yI~
           {                                                       //~v47yI~
          	if (cidlen!=SPFNUMFLDLEN)                              //~v41xI~
            {                                                      //~v41xI~
    			uerrmsg("use 8 byte CID format(without last \"~\") for CID col=73 of COBOL",//~v41xR~
    					"COBOLでCID位置=73の時は8桁CID形式(最後の\"~\"無し)を使用。");//~v41xR~
				return 8;                                          //~v41xI~
        	}                                                      //~v41xI~
    		if (!nopdsw)		//'N' opd specified                //~v41xI~
        		lrecl=mergin+cidlen;                               //~v41xI~
            else                                                   //~v41xI~
            {                                                      //~v41xI~
    			uerrmsg("CID position conflict with Numbered(\"n\") option for COB file",//~v429R~
    					"COBファイルの CID位置が 行番号オプション(\"n\")と矛盾します。");//~v429R~
				return 8;                                          //~v41xI~
        	}                                                      //~v41xI~
           }//not cobk w/o num fld                                 //~v47yI~
           else                                                    //~vafcI~
        	lrecl=mergin+cidlen; //thetre may be no path to this line but for safety//~vafcI~
          }                                                        //~v41xI~
          else                                                     //~v41xI~
          {                                                        //~v429I~
            if (numfsz)                                            //~v429I~
            {                                                      //~v429I~
                uerrmsg("Invalid CID pos(%d).Up to margin(<%d) for numbered file.",//~v429I~
                          "CID位置エラー(%d)。行番号ファイルではマージンまで(<%d)。",//~v429I~
                          cidpos+1,mergin+1);                      //~v429I~
                return 8;                                          //~v429I~
            }                                                      //~v429I~
        	lrecl=mergin+cidlen+numfsz;                            //~v0bwI~
          }                                                        //~v429I~
        }                                                          //~v41xI~
		else                                                       //~v0bwI~
	        if (cidpos+cidlen<=mergin)                             //~v0c6R~
	        	lrecl=mergin+numfsz;                               //~v0bwI~
            else                                                   //~v0bwI~
            {                                                      //~v0bwR~
//              uerrmsg("CID pos(%d) must be same as mergin(%d) or fully in the mergin",//~v10CR~
//                      "CID位置(%d)はマージン位置(%d)かマージン内に収まること",//~v10CR~
//                      cidpos+1,mergin);                          //~v10CI~
//              uerrmsg("CID pos(%d) must be just out of margin(=%d) or fully in the mergin(<=%d)",//~v429R~
//                      "CID位置(%d)はマージンの直後(=%d)かマージン内に収まること(<=%d)",//~v429R~
//                      cidpos+1,mergin+1,mergin-cidlen+1);        //~v429I~
//              return 8;                                          //~v429I~
               	if (cidpos<mergin) //cross margin line             //~v429I~
               	{                                                  //~v429I~
               		uerrmsg("Invalid CID pos(%d).crossing margin(=%d).",//~v429R~
                    	    "CID位置エラー(%d)。マージン(=%d)を跨げません。",//~v429R~
                        	cidpos+1,mergin+1);                    //~v429R~
                	return 8;                                      //~v429R~
              	}                                                  //~v429I~
              	else                                               //~v429I~
              	if (numfsz && cidpos>mergin)                       //~v429I~
              	{                                                  //~v429I~
                  	uerrmsg("Invalid CID pos(%d).Up to margin(<%d) for numbered file.",//~v429R~
                    	      "CID位置エラー(%d)。行番号ファイルではマージンまで(<%d)。",//~v429R~
                        	  cidpos+1,mergin+1);                  //~v429I~
                  	return 8;                                      //~v429I~
              	}                                                  //~v429I~
	        	lrecl=cidpos+cidlen+numfsz;                        //~v429I~
            }                                                      //~v0bwR~
	else	//no cid                                               //~v0bwI~
    	lrecl=mergin+numfsz;                                       //~v0bwI~
                                                                   //~v0bwI~
  if (!(UCBITCHK(Ppfh->UFHflag5,UFHF5COB2)  	//cobk(col.1-6 is not seqno)//~v47yI~
        && UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM)))  //col.72-80 is not seqno.//~v47yI~
  {                                                                //~v75sI~
    if (fixedlrecl)                                                //~v75sR~
    {                                                              //~v75sI~
        if (fixedlrecl<lrecl)                                      //~v75sR~
        {                                                          //~v75sI~
            uerrmsg("Fixed-LRECL value(%d) err,conflict with CID position(%d)/margin(%d)/lineno field width(%d)",//~v75sR~
                    "固定長 LRECL 値(%d)エラー,CID位置(%d)/マージン(%d)/行番号幅(%d)と矛盾",//~v75sR~
                    fixedlrecl,cidpos,mergin,numfsz);              //~v75sR~
            return 8;       //err line ignored                     //~v75sI~
        }                                                          //~v75sI~
		UCBITON(Ppfh->UFHflag7,UFHF7FIXLRECL);                     //~v75sI~
		Ppfh->UFHlrecl=(USHORT)fixedlrecl;                         //~v75sI~
        UCBITON(Ppfh->UFHflag5,UFHF5DROPTAB);  //drop tab at save  //~v78uR~
    }                                                              //~v75sI~
    else                                                           //~v75sI~
	Ppfh->UFHlrecl=(USHORT)lrecl;                                  //~v0avR~
  }                                                                //~v75sI~
  else                                                             //~v75sI~
    if (fixedlrecl)                                                //~v75sI~
    {                                                              //~v75sI~
		Ppfh->UFHlrecl=(USHORT)fixedlrecl;                         //~v75sR~
		UCBITON(Ppfh->UFHflag7,UFHF7FIXLRECL);                     //~v75sI~
        UCBITON(Ppfh->UFHflag5,UFHF5DROPTAB);  //drop tab at save  //~v78uR~
    }                                                              //~v75sI~
//    if (numfsz)                                                  //~v47yR~
//    {                                                            //~v47yR~
//        Ppfh->UFHspfpos=(UCHAR)(lrecl-SPFNUMFLDLEN);             //~v47yR~
//        if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB))  //cobol option   //~v47yR~
//            if (!nopdsw)        //'N' opd specified              //~v47yR~
//                UCBITON(Ppfh->UFHflag5,UFHF5NOAUTONUM);  //no use col72-80//~v47yR~
//    }                                                            //~v47yR~
//    else                                                         //~v47yR~
//        UCBITOFF(Ppfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR);//no more spf file//~v47yR~
      if (numfsz)                                                  //~v47yI~
	  	Ppfh->UFHspfpos=(UCHAR)(lrecl-SPFNUMFLDLEN);               //~v47yR~
//    if (cidpos)                                                  //~v0bwR~
//        Ppfh->UFHmergin=(USHORT)cidpos;                          //~v0bwR~
//    else                                                         //~v0bwR~
//        Ppfh->UFHmergin=(USHORT)(lrecl-numfsz-Ppfh->UFHcidlen);  //~v0bwR~
    Ppfh->UFHmergin=(USHORT)mergin;                                //~v0bwI~
    UCBITON(Ppfh->UFHflag2,UFHF2MERGIN); 	//no drop last space   //~v0c2R~
    if (plevel)			//plevel=1;protect                         //~v0eJM~
    	UCBITOFF(Ppfh->UFHflag3,UFHF3OOMNOPROT);	//reset no prot//~v0eJM~
	else                                            //plevel=0     //~v0eJM~
    	UCBITON(Ppfh->UFHflag3,UFHF3OOMNOPROT);	//set no prot      //~v0eJM~
                                                                   //~v0eJM~
    if (cidpos==mergin)                                            //~v0cbI~
    	UCBITON(Ppfh->UFHflag2,UFHF2MERGINCID); 	//no drop last space//~v0cbR~
    return 0;                                                      //~v0avI~
}//filetoplinelrecl                                                //~v0avI~
//************************************************************     //~v10LI~
// filedefaultspf                                                  //~v10LI~
//   set lrecl,mergin,numfldpos for /Mn specification              //~v10LI~
//*parm1:pfh                                                       //~v10LI~
//*return:0 :                                                      //~v10LI~
//************************************************************     //~v10LI~
int filedefaultspf(PUFILEH Ppfh)                                   //~v10LI~
{                                                                  //~v10LI~
//*****************************                                    //~v10LI~
  if (!(UCBITCHK(Ppfh->UFHflag5,UFHF5COB2)  	//cobk(col.1-6 is not seqno)//~v47vR~
        && UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM)))  //col.72-80 is not seqno.//~v47vR~
  {                                                                //~v47vR~
	Ppfh->UFHlrecl=SPFLRECL;                                       //~v10LI~
    Ppfh->UFHspfpos=(UCHAR)(SPFLRECL-SPFNUMFLDLEN);                //~v10LI~
  }                                                                //~v47vR~
    Ppfh->UFHmergin=(UCHAR)(SPFLRECL-SPFNUMFLDLEN);                //~v10LI~
    UCBITON(Ppfh->UFHflag2,UFHF2MERGIN); 	//no drop last space   //~v10LI~
    UCBITOFF(Ppfh->UFHflag3,UFHF3OOMNOPROT);	//reset no prot    //~v10LI~
    Ppfh->UFHcidtype=UFHCIDTYPEERR;                                //~v41hI~
    Ppfh->UFHcidlen=0;                                             //~v41hI~
    Ppfh->UFHcidpos=0;                                             //~v42vR~
    *Ppfh->UFHcid=0;                                               //~v41hI~
    return 0;                                                      //~v10LI~
}//filedefaultspf                                                  //~v10LI~
//************************************************************     //~v0avI~
// filemerginchk                                                   //~v0avI~
//   chk mergin when update data(pcd must be expanded)             //~v0avI~
//   if update mode,allow change in mergin if addlen >0            //~v0beI~
//*parm1:plh                                                       //~v0avI~
//*parm2:current pos                                               //~v0avR~
//*parm3:adddata                                                   //~v0avR~
//*parm4:addlen                                                    //~v0avI~
//*parm5:dellen                                                    //~v0c2I~
//*parm6:option                    2:update mode by change cmd     //~v0c2I~
//*             4:bypass errmsg    8:ignore tab effect             //~v0c2M~
//*parm7:optional output addlen                                    //~v0c2R~
//*parm8:optional new data len                                     //~v0c2R~
//*parm9:optional out of mergin len(-1:if short rec overflow but tab/space only(rc=0))//~v71UR~
//*return:0:ok,4:overflow                                          //~v0bzR~
//************************************************************     //~v0avI~
#ifdef UTF8UCS2                                                    //~va20R~
int filemerginchk(PULINEH Pplh,int Pcpos,char *Padddata,           //~va20R~
					char *Padddbcs,//always not null*              //~va20R~
#else                                                              //~va20I~
int filemerginchk(PULINEH Pplh,int Pcpos,char *Padddata,           //~v0avR~
#endif                                                             //~va20I~
					int Paddlen,int Pdellen,int Popt,              //~v0c2R~
					int *Ppaddlen,int *Pnewlen,int *Poomlen)       //~v0c2I~
{                                                                  //~v0avI~
	PUFILEH pfh;                                                   //~v0avI~
    int mergin,len,addlen=0;                                         //~v0bzR~//~vaf9R~
    int rc=0;                                                        //~v0bzR~//~vaf9R~
//  int cidlen,cidpos;                                             //~v0c2R~
    int endpos;                                                    //~v0bzR~
    int oomlen;                                                    //~v0c2I~
//  int droplen;                                                   //~v71UR~
    int explenchk=0;                                               //~v71UR~
//  int bndsoffs2;                                                 //~v74GR~
    int bndsoffs2=0;                                               //~v74GI~
//*****************************                                    //~v0avI~
	pfh=UGETPFH(Pplh);                                             //~v0avI~
	mergin=(int)pfh->UFHmergin;                                    //~v0bwR~
    if (Popt & MERGIN_BNDS) //ignore num fld                       //~v74ER~
    {                                                              //~v74ER~
    	bndsoffs2=pfh->UFHbndscol2;                                //~v74ER~
    	if (bndsoffs2 && bndsoffs2<mergin)                         //~v74ER~
        	mergin=bndsoffs2;                                      //~v74ER~
//      else                                                       //~v74GR~
//      	bndsoffs2=0;	//ignore bnds                          //~v74GR~
    }                                                              //~v74ER~
//  cidlen=(int)pfh->UFHcidlen;                                    //~v0c2R~
//  cidpos=(int)pfh->UFHcidpos;                                    //~v0c2R~
  if (Popt & MERGIN_JOINSPF) //ignore num fld                      //~v42gR~
    len=Pcpos;					//chk full data                    //~v42gI~
  else                                                             //~v42gI~
    len=Pplh->ULHlen;					//chk full data            //~v0c2R~
//chk len last space(it may be by tab)                             //~v0bzI~
//  if ((Popt & MERGIN_WITHOUTCID)     //requested chk without cid //~v0c2R~
//  &&  (cidlen && cidpos==mergin))   //cid pos is out of mergin   //~v0c2R~
//     	len=filecidlrecl(Pplh,pfh); //len without last cid         //~v0c2R~
//  else //cid is data,no cid or cid pos in mergin(treate cid as data)//~v0c2R~
//      len-=(int)umemrspnc(Pplh->ULHdata,' ',(UINT)len);   //len to last non space//~v0c2R~
//get net data len                                                 //~v0c2I~
    oomlen=0;                                                      //~v0c2I~
//  if (UCBITCHK(pfh->UFHflag2,UFHF2MERGIN))   //mergin specified  //~v74ER~
    if (UCBITCHK(pfh->UFHflag2,UFHF2MERGIN)    //mergin specified  //~v74ER~
    ||  bndsoffs2>0)                           //bounds right      //~v74ER~
    {                                                              //~v0c2I~
    	if (len>mergin)                                            //~v0c2I~
        {                                                          //~v0c2I~
          if (Pcpos>=mergin                                        //~v0e3M~
          &&  Popt & MERGIN_OOMOK 	//allow oom input              //~v0e3R~
          && (!UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR)//~v0e3I~
        	||!fileisvalidspfline(pfh,Pplh,0)))//not valid spf file//~v0e3I~
           	mergin=MAXLINEDATA;	//up to max                        //~v0e3M~
          else                                                     //~v0e3M~
          {                                                        //~v0e3M~
            oomlen=len-mergin;                                     //~v0c2I~
//          if ((droplen=Pcpos+Pdellen)<mergin)                    //~v71UR~
//          {                                                      //~v71UR~
//      	len=mergin;			//chk mergin only		           //~v71UR~
//      	len-=(int)umemrspnc(Pplh->ULHdata,' ',(UINT)len); //len to last non space//~v0exR~
//      	len-=(int)umemrspnc(Pplh->ULHdata+droplen,' ',(UINT)(mergin-droplen)); //len to last non space//~v71UR~
//          }                                                      //~v71UR~
            explenchk=1;                                           //~v71UI~
//  		rc=filegettabexplenofmargined(0,mergin,Pplh,Pcpos,Padddata,Paddlen,Pdellen,len,&addlen);//no nonspace overflow//~v73gR~
#ifdef UTF8UCS2                                                    //~va20I~
    		rc=filegettabexplenofmargined(Popt,mergin,Pplh,Pcpos,Padddata,Padddbcs,Paddlen,Pdellen,len,&addlen);//no nonspace overflow//~va20I~
#else                                                              //~va20I~
    		rc=filegettabexplenofmargined(Popt,mergin,Pplh,Pcpos,Padddata,Paddlen,Pdellen,len,&addlen);//no nonspace overflow//~v73gI~
#endif                                                             //~va20I~
            if (rc==1)          //overflow but tab/space only      //~v71UI~
                explenchk=3;	//ignore overflow                  //~v71UI~
		  }                                                        //~v0e3I~
        }                                                          //~v0e3I~
        else                                                       //~v71UI~
        {                                                          //~v71UI~
			if (                                                   //~v71UR~
			      (Popt & MERGIN_SHORTRECOK) //requested chk short record//~v71UI~
				&&(!(Popt & MERGIN_JOINSPF)) //not join call(len<==ULHlen)//~v71UI~
		        &&(Pcpos<len)                //ins in rec          //~v71UI~
                &&(Pplh->ULHdbcs!=0)   //tab expanded              //~v71UR~
               )                                                   //~v71UI~
            {                                                      //~v71UI~
            	explenchk=1;                                       //~v71UI~
#ifdef UTF8UCS2                                                    //~va20I~
				rc=filegettabexplenofmargined(0,mergin,Pplh,Pcpos,Padddata,Padddbcs,Paddlen,Pdellen,len,&addlen);//no nonspace overflow//~va20I~
#else                                                              //~va20I~
				rc=filegettabexplenofmargined(0,mergin,Pplh,Pcpos,Padddata,Paddlen,Pdellen,len,&addlen);//no nonspace overflow//~v71UI~
#endif                                                             //~va20I~
                if (rc==1)          //overflow but tab/space only  //~v71UI~
                	explenchk=2;	//ignore overflow              //~v71UI~
            }                                                      //~v71UI~
        }//shortter than margin                                    //~v71UR~
	}                                                              //~v0c2I~
    if (Poomlen)                                                   //~v0c2I~
        *Poomlen=oomlen;                                           //~v0c2I~
                                                                   //~v0bzI~
    if (Popt & MERGIN_NOTAB)    //not requested chk without cid    //~v0b3I~
        addlen=Paddlen-Pdellen;                                    //~v0avR~
    else                                                           //~v0b3I~
      if (!explenchk)	//allready addlen calculated               //~v71UI~
#ifdef UTF8UCS2                                                    //~va20I~
//*filegettabexple returns addle-dellen for ebc file               //~va50I~
		addlen=filegettabexplen(Pplh,Pcpos,Padddata,Padddbcs,Paddlen,Pdellen,len);	//expand len//~va20I~
#else                                                              //~va20I~
		addlen=filegettabexplen(Pplh,Pcpos,Padddata,Paddlen,Pdellen,len);	//expand len//~v0bzR~
#endif                                                             //~va20I~
                                                                   //~v0bzI~
    if (Pcpos>len)                                                 //~v0avI~
    	addlen+=Pcpos-len;                                         //~v0avI~
    if (Ppaddlen)                                                  //~v0beI~
        *Ppaddlen=addlen;                                          //~v0beR~
                                                                   //~v0c2I~
    endpos=len+addlen;                                             //~v0bzR~
    if (Pnewlen)                                                   //~v0bzI~
        *Pnewlen=endpos;                                           //~v0bzI~
  	if (explenchk==2)                                              //~v71UI~
    {                                                              //~v71UI~
	    if (Poomlen)                                               //~v71UI~
    	    *Poomlen=-1;                                           //~v71UI~
    	return 0; //overflow space is cut to margin by request     //~v71UR~
    }                                                              //~v71UI~
  	if (explenchk==3)                                              //~v71UI~
    	return 0; //overflow space is cut by margin shiftback      //~v71UI~
  	if (explenchk==1)                                              //~v73gI~
        if (!rc)                                                   //~v73gI~
    		return 0; //overflow space is cut by margin shiftback  //~v73gI~
	if (endpos>mergin)                                             //~v0bzR~
    {                                                              //~v0avI~
    	rc=0;                                                      //~v0bzI~
        if (Popt & MERGIN_REPMODE)  //replace mode from change cmd //~v0bzI~
        {                                                          //~v0bzI~
//            if (addlen>0)            //expand                    //~v0eyR~
//                rc=4;                                            //~v0eyR~
//            else                                                 //~v0eyR~
//                if (addlen==0 && (Pcpos+Paddlen>mergin))         //~v0eyR~
//                    rc=8;   //cannot change out of mergin        //~v0eyR~
            if (Pcpos>mergin)                                      //~v0eyI~
                rc=8;       //out of mergin                        //~v0eyI~
            else                                                   //~v0eyI~
                rc=4;       //mergin overflow                      //~v0eyI~
        }                                                          //~v0bzI~
        else                                                       //~v0bzI~
            rc=4;                                                  //~v0bzI~
        if (rc)                                                    //~v0bzI~
        {                                                          //~v0bzI~
            if (!(Popt & MERGIN_NOMSG)) //overflow msg issue       //~v0bzI~
            {                                                      //~v71UI~
            	if (rc==4)                                         //~v0bzI~
	                charmaxovererr(mergin);                        //~v0bzI~
                else                                               //~v0bzI~
	                charmerginerr(mergin);                         //~v0bzI~
            }                                                      //~v71UI~
            return 4;                                              //~v0bzI~
        }                                                          //~v0bzI~
    }                                                              //~v0bzR~
    return 0;	                                                   //~v0bzR~
}//filemerginchk                                                   //~v0avI~
//************************************************************     //~v0c2I~
// filegetoomlen                                                   //~v0c2I~
//   get out of mergin length                                      //~v0c2I~
//*parm1:pfh                                                       //~v0c2I~
//*parm2:plh                                                       //~v0c2I~
//*return:len                                                      //~v0c2I~
//************************************************************     //~v0c2I~
int filegetoomlen(PUFILEH Ppfh,PULINEH Pplh)                       //~v0c2R~
{                                                                  //~v0c2I~
    int mergin,len,oomlen;                                         //~v0c2I~
//*****************************                                    //~v0c2I~
    len=Pplh->ULHlen;	                                           //~v0c2I~
	mergin=(int)Ppfh->UFHmergin;                                   //~v0c2R~
    oomlen=0;                                                      //~v0c2I~
    if (UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN))   //mergin specified //~v0c2I~
    	if (len>mergin)                                            //~v0c2I~
            oomlen=len-mergin;                                     //~v0c2I~
	return oomlen;                                                 //~v0c2I~
}//filegetoomlen                                                   //~v0c2I~
                                                                   //~v0emI~
//**************************************************************** //~v0c2I~
//!fileoomshiftback                                                //~v0c2I~
//   cid restore from rigt to left                                 //~v0c2I~
//*parm1:pfh                                                       //~v0c2I~
//*parm2:plh                                                       //~v0c2I~
//*parm3:oomlen                                                    //~v0c2I~
//*rc   :0                                                         //~v0evR~
//**************************************************************** //~v0c2I~
//int fileoomshiftback(PUFILEH Ppfh,PULINEH Pplh,int Poomlen)      //~v74ER~
int fileoomshiftback(PUFILEH Ppfh,PULINEH Pplh,int Poomlen,int Pmergin)//~v74EI~
{                                                                  //~v0c2I~
    int len,mergin,len2;                                           //~v0c2R~
    char *pc,*pcd;                                                 //~v0c2I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//********************                                             //~v0c2I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (!Poomlen)                                                  //~v0c2I~
    	return 0;                                                  //~v0c2I~
  if (Pmergin)                                                     //~v74EI~
    mergin=Pmergin;                                                //~v74EI~
  else                                                             //~v74EI~
    mergin=Ppfh->UFHmergin;                                        //~v0c2I~
    pc=Pplh->ULHdata;                                              //~v0c2I~
    pcd=Pplh->ULHdbcs;                                             //~v0c2I~
    len=Pplh->ULHlen;                                              //~v0c2I~
    len2=(len-Poomlen)-mergin;	//over mergin	                   //~v0c2I~
    if (len2>0)		//to shift to left                             //~v0c2I~
    {                                                              //~v0c2I~
//      setobtabdbcs(pc,pcd,len,mergin,Poomlen);//outbound tab clear//~v0evR~
	    memcpy(pc+mergin,pc+len-Poomlen,(UINT)Poomlen);            //~v0c2R~
    	memcpy(pcd+mergin,pcd+len-Poomlen,(UINT)Poomlen);          //~v0c2R~
	    Pplh->ULHlen=len-len2;                                     //~v0c2I~
    }                                                              //~v0c2I~
    else                                                           //~v0c2I~
    if (len2<0)		//to be shift to right(buff not reduced)       //~v0c2I~
    {                                                              //~v0c2I~
    	len2=-len2;                                                //~v0c2R~
	    memmove(pc+mergin,pc+mergin-len2,(UINT)Poomlen);           //~v0c2R~
    	memmove(pcd+mergin,pcd+mergin-len2,(UINT)Poomlen);         //~v0c2R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        UCVEBC_memset_space(swebcfile,pc+mergin-len2,(UINT)len2);  //~va50I~
#else                                                              //~va50I~
        memset(pc+mergin-len2,' ',(UINT)len2);                     //~v0c2R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        memset(pcd+mergin-len2,0,(UINT)len2);                      //~v0c2R~
	    Pplh->ULHlen=len+len2;                                     //~v0c2R~
    }                                                              //~v0c2I~
    return 0;                                                      //~v0c2I~
}//fileoomshiftback                                                //~v0c2I~
//************************************************************     //~v20tI~
// filetoplineupctr                                                //~v20tI~
//   read/write update ctr on top cid line                         //~v20tI~
//*parm1:pfh                                                       //~v20tI~
//*parm2:plh                                                       //~v20tI~
//*return:0 :gotten ,4 not enough space on cid line                //~v20tI~
//************************************************************     //~v20tI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int filetoplineuctr(PUFILEH Ppfh,PULINEH Pplh,int *Ppupctrposlen)  //~va50I~
#else                                                              //~va50I~
int filetoplineuctr(PUFILEH Ppfh,PULINEH Pplh)                     //~v20tI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
{                                                                  //~v20tI~
static UCHAR Suctrid[]="UPDATE#=";                                 //~v20tI~
    UCHAR *pc,*pc2;                                                //~v20tI~
    int len,len2,prevctr,uctr;                                     //~v20PR~
    int len3;                                                      //~v50NR~
    long  lupc;                                                    //~v50NR~
    UCHAR wk[8];                                                   //~v20tR~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
    UCHAR *pdbcs;                                                  //~va20I~
#endif                                                             //~va20I~
//*****************************                                    //~v20tI~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20I~
    pdbcs=Pplh->ULHdbcs;                                           //~va20I~
    if (!pdbcs)         //1stcall before filechktabdbcs            //~va20I~
        swutf8file=0;                                              //~va20I~
#endif                                                             //~va20I~
    len=Pplh->ULHlen;                                              //~v20tI~
//  uctrsw=UCBITCHK(Ppfh->UFHflag5,UFHF5TLUCTR);	//prev status  //~v20PR~
//  UCBITOFF(Ppfh->UFHflag5,UFHF5TLUCTR);	//reset once           //~v20PR~
#ifdef UTF8UCS2                                                    //~va20I~
    if (pc=UTF_umemstri(swutf8file,Pplh->ULHdata,pdbcs,Suctrid,0/*ctrid dbcs*/,len),!pc)//case insense//~va20R~
#else                                                              //~va20I~
    if (pc=umemstri(Pplh->ULHdata,Suctrid,(UINT)len),!pc)//case insense//~v20tI~
#endif                                                             //~va20I~
    	return 0;	//not required                                 //~v20tI~
//  UCBITON(Ppfh->UFHflag5,UFHF5TLUCTR);	//update requested     //~v20PR~
    pc+=sizeof(Suctrid)-1;                                         //~v20tI~
    pc2=pc;					//pos to set counter                   //~v20tI~
//  len-=(int)((ULONG)pc-(ULONG)Pplh->ULHdata);                    //~v20tI~//~vafkR~
    len-=(int)((ULPTR)pc-(ULPTR)Pplh->ULHdata);                    //~vafkI~
#ifdef UTF8UCS2                                                    //~va20I~
//  len2=(int)UTF_umemspnc(swutf8file,pc,XEUTF_PC2PCD(pdbcs,pc,Pplh->ULHdata),' ',(UINT)len);	//preceding space len//~va20R~//+vb30R~
    len2=(int)UTF_umemspnc(swutf8file,pc,XEUTF_PC2PCD(pdbcs,pc,Pplh->ULHdata),' ',len);	//preceding space len//+vb30I~
#else                                                              //~va20I~
    len2=(int)umemspnc(pc,' ',(UINT)len);	//preceding space len  //~v20tI~
#endif                                                             //~va20I~
    len-=len2;		//residual                                     //~v20tI~
    pc+=len2;                                                      //~v20tI~
//  len2+=unumlen(pc,0,len);                                       //~v50NR~
#ifdef UTF8UCS2                                                    //~va20I~
    len3=UTF_unumlen(swutf8file,pc,XEUTF_PC2PCD(pdbcs,pc,Pplh->ULHdata),0,len);//~va20I~
#else                                                              //~va20I~
    len3=unumlen(pc,0,len);                                        //~v50NR~
#endif                                                             //~va20I~
    len2+=len3;                                                    //~v50NR~
//  if (!uctrsw && !UCBITCHK(Ppfh->UFHflag,UFHFNEW))	//first time//~v20PR~
	prevctr=Ppfh->UFHtluctr;                                       //~v20PI~
	if (!prevctr)		//accept value 1st time(load time) only    //~v20PR~
    {                                                              //~v20tI~
//      lupc=atol(pc);                                             //~v50NR~
//+after unumlen done                                              //~va20I~
        lupc=(long)uatoin(pc,len3);                                //~v50NR~
        if (!lupc)                                                 //~v20PI~
        	lupc=1;                                                //~v20PI~
        else                                                       //~v20PI~
        if (lupc<0 || lupc>=0xffff)                                //~v20tI~
        {                                                          //~v20tI~
            uerrmsg("update counter overflow(%ld)",                //~v20tI~
                    "更新回数(%ld)オーバーフロー",                 //~v20tI~
                    lupc);                                         //~v20tI~
            return 0;                                              //~v20tI~
        }                                                          //~v20tI~
    	Ppfh->UFHtluctr=(USHORT)lupc;                              //~v20tR~
//      return 0;                                                  //~v20PR~
    }                                                              //~v20tI~
    if (!UCBITCHK(Ppfh->UFHflag5,UFHF5TLUCTR))	//not save req     //~v20PI~
		return 0;                                                  //~v20PI~
//set for output                                                   //~v20tI~
//  if (!Ppfh->UFHupctr)//file load duplicated call,at save time only//~v20PR~
//  	return 0;                                                  //~v20PR~
//	len2=min(len2,sizeof(wk)-1);                                   //~v20tI~//+vb30R~
  	len2=min(len2,(int)sizeof(wk)-1);                              //+vb30I~
	uctr=Ppfh->UFHtluctr;                                          //~v20tR~
//  if (!UCBITCHK(Ppfh->UFHflag,UFHFNEW))	//first time           //~v20PR~
    if (prevctr)	//value before save time(at load)              //~v20PR~
    	uctr++;                                                    //~v20tI~
	sprintf(wk,"%*d",len2,uctr);                                   //~v20tR~
    if ((int)strlen(wk)>len2)                                      //~v20tR~
    {                                                              //~v20tI~
    	uerrmsg("Expand space to insert update counter %s",        //~v20tR~
        		"更新回数(%s)を設定するスペースを空けてください",  //~v20tR~
				wk);                                               //~v20tI~
        return 4;                                                  //~v20tR~
    }                                                              //~v20tI~
    memcpy(pc2,wk,(UINT)len2);                                     //~v40bR~
//  *Ppupctrposlen=(((ULONG)pc2-(ULONG)(Pplh->ULHdata))<<8)|len2;	//output to filetoplinecid//~va50I~//~vafkR~
//  *Ppupctrposlen=(((ULPTR)pc2-(ULPTR)(Pplh->ULHdata))<<8)|len2;	//output to filetoplinecid//~vafkI~//~vb2FR~
    *Ppupctrposlen=(int)(((ULPTR)pc2-(ULPTR)(Pplh->ULHdata))<<8)|len2;	//output to filetoplinecid//~vb2FI~
    return 0;                                                      //~v20tI~
}//filetoplineuctr                                                 //~v20tI~
