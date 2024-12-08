//CID://+vb30R~:                 update#=  26;                     //~vb30R~
//*************************************************************
//* xeerr.c
//*************************************************************
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vb2F:160229 W32 64 compiler warning                              //~vb2FI~
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavcI~
//vav1:140401 (BUG)crash for 64bit errmsg                          //~vav1I~
//vap0:131215 (ARM)warning strict aliasing                         //~vap0I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va79:100809 cpeb converter parm support                          //~va79I~
//va70:000701 LP64 option support                                  //~va70I~
//va5n:100510 (BUG)cvl2fbyct return rc=4                           //~va5nI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va0m:090811 reject CPU8/CPLC for bin file                        //~va0mI~
//v77v:080117*xuerpchk(uerrmsg parameter chk)                      //~v77vI~
//v77b:071219 accept numeric only for color panel                  //~v77bI~
//v62Q:050419 errmsg for split width is over MAXLINEDATA           //~v62QI~
//v62f:050314 change matching specification "*= & n "-->"*=Mn"     //~v62fI~
//v60y:050202 exe cmd *2 option(use other split screen file)       //~v60yI~
//v60v:050201 virtual hex display option(/Mx,HEX on/off,prev HEX is XIN)//~v60vI~
//v50E:030126 (DOS)no TC cmd support for memory                    //~v50EI~
//v50m:030102 accept tab cmd on any screen                         //~v50mI~
//v43m:011101 conflict err msg                                     //~v43mI~
//v417:010729 allow lineno fld when not protected for spf file     //~v417I~
//v155:000318 numeric calc func                                    //~v155I~
//v10v:990326 chng browse binary mode:"2" -->"1",and add "2" as edit binary mode//~v10vI~
//v0i8:980522 move csrposerr to xeerr                              //~v0i8I~
//v098:970413:(BUG)avail update on browse line(but its is not saved)//~v098I~
//            by Shift+Ins/Del/F10(rep)/Enter(Split).              //~v098I~
//            (move errmsg to xeerr.c from xecap.c)                //~v098I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v03b:950730:zenkaku err msg for lineno,scroll fld etc         //~v03bI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>                                                //~va20I~
//*************************************************************
#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>                                                  //~v60yI~
#include <ufile.h>                                                 //~va20I~
#include <ucvebc.h>                                                //~va20I~
#include <utf.h>                                                   //~va20I~
#include <utf22.h>                                                 //~va50I~
#include <udbcschk.h>                                              //~va5nI~
#include <utrace.h>                                                //~vap0I~
                                                                   //~v60yI~
#include "xe.h"                                                    //~v60yI~
#include "xescr.h"                                                 //~va20I~
#include "xefile.h"                                                //~va20I~
#include "xeerr.h"                                                 //~va20I~
#include "xeutf.h"                                                 //~va20I~
#include "xeutf2.h"                                                //~va20I~
#include "xeebc.h"                                                 //~va20I~
#include "xefcmd23.h"                                              //~va20I~
#include "xesub2.h"                                                //~va20I~
//*******************************************************
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va20I~
//**************************************************************** //~va50I~
// insert codetype for errmsg                                      //~va50I~
//rc:1 utf8 code found                                             //~va50I~
//**************************************************************** //~va50I~
int xeerr_seterrmsgct(int Popt,char *Pmixed,int Pmixlen,char *Pcodetype,char *Pdbcs,int Plclen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~va50I~
{                                                                  //~va50I~
    int outlen;                                                    //~va50R~
    UCHAR *pc,*pcw,*pdbcs;                                         //~va50R~
    int swu8,utf8chsz,lcchsz,reslen,swu8found=0;                   //~va50R~
    UCHAR *pce,*pcti,*pcwe,ch,*pctie;                              //~va50I~
    ULONG ucs;                                                     //~va50I~
//********************                                             //~va50I~
	pc=Pmixed;                                                     //~va50I~
    pce=pc+Pmixlen;                                                //~va50I~
    pdbcs=Pdbcs;                                                   //~va50I~
    pcti=Pcodetype;                                                //~va50I~
    pctie=pcti+Plclen;                                             //~va50R~
    pcw=Poutbuff;                                                  //~va50I~
    pcwe=Poutbuff+Pbuffsz;                                         //~va50R~
    for (swu8=0;pc<pce;pc+=utf8chsz,pcti+=lcchsz,pdbcs+=lcchsz)    //~va50I~
    {                                                              //~va50I~
        ch=*pc;                                                    //~va50I~
        if (*pcti==XEUTFCT_UTF8)                                   //~va50I~
        {                                                          //~va50I~
            utf8chsz=UTF8CHARLEN(ch);                              //~va50I~
            if (!utf8chsz)                                         //~va50I~
                break;  //logic err,unmatch                        //~va50I~
            swu8found=1;                                           //~va50I~
            if (!swu8)                                             //~va50I~
            {                                                      //~va50I~
                swu8=1;                                            //~va50I~
                if (pcw+2>=pcwe)                                   //~va50I~
                    break;                                         //~va50I~
                *pcw++=XEERMCT_NOTLC;                              //~va50I~
//              *pcw++=XEERMCT_UTF8;                               //~va50I~//~vavcR~
//              *pcw++=XEERMCT_UTF8CODE;                           //~vavcR~
                *pcw++=XEERMCT_UTF8WC;                             //~vavcI~
            }                                                      //~va50I~
            if (pcw+utf8chsz>=pcwe)                                //~va50I~
                break;                                             //~va50I~
//          memcpy(pcw,pc,utf8chsz);                               //~va50I~//~vb30R~
            memcpy(pcw,pc,(size_t)utf8chsz);                       //~vb30I~
            pcw+=utf8chsz;                                         //~va50I~
//          reslen=(ULONG)pctie-(ULONG)pcti;                       //~va50I~//~vafkR~
//          reslen=(ULPTR)pctie-(ULPTR)pcti;                       //~vafkI~//~vb2FR~
            reslen=PTRDIFF(pctie,pcti);                            //~vb2FI~
          if (Pdbcs)                                               //~va50I~
          	if (UDBCSCHK_DBCS1STLU(*pdbcs))                        //~va50I~
            	lcchsz=XESUB_DBCSSPLITCTR(pdbcs,reslen,0/*pos*/);  //~va50I~
          	else                                                   //~va50I~
            	lcchsz=1;                                          //~va50I~
          else                                                     //~va50I~
         	utfgetwcw(0,pc,utf8chsz,&ucs,0/*chklen*/,&lcchsz);     //~va50R~
        }                                                          //~va50I~
        else                                                       //~va50I~
        {                                                          //~va50I~
            if (swu8)                                              //~va50I~
                *pcw++=XEERMCT_NOTLC;                              //~va50I~
            swu8=0;                                                //~va50I~
            if (pcw+1>pcwe)                                        //~va50I~
                break;                                             //~va50I~
            *pcw++=ch;                                             //~va50I~
            utf8chsz=1;                                            //~va50I~
            lcchsz=1;                                              //~va50I~
        }                                                          //~va50I~
    }//for                                                         //~va50I~
    if (swu8)                                                      //~va50I~
        *pcw++=XEERMCT_NOTLC;//close pending u8 string             //~va50I~
//  outlen=(ULONG)pcw-(ULONG)Poutbuff;                             //~va50I~//~vafkR~
//  outlen=(ULPTR)pcw-(ULPTR)Poutbuff;                             //~vafkI~//~vb2FR~
    outlen=PTRDIFF(pcw,Poutbuff);                                  //~vb2FI~
    *pcw++=0;                                                      //~va50I~
    if (Ppoutlen)                                                  //~va50I~
	    *Ppoutlen=outlen;                                          //~va50I~
    UTRACEP("xeerr_seterrmsgct rc=%d\n",swu8found);                //~vap0I~
    UTRACED("xeerr_seterrmsgct out",Poutbuff,outlen);              //~vap0I~
    return swu8found;                                              //~va50R~
}//xeerr_seterrmsgct                                               //~va50I~
//**************************************************************** //~va20I~
// edit errmsg according codetype of each parameter                //~va20I~
//*for ebc dbcs parm ,specify data and dbcs,total max is 5         //~va20I~
//*rc    :4                                                        //~va20I~
//**************************************************************** //~va20I~
int xeerrmsg(int Popt,int Pparmctr,char *Pcodetype,char *Pemsg ,char *Pjmsg,... )//~va20I~
{                                                                  //~va20I~
//	unsigned long parm[XEERRMSG_MAXPARM];                          //~va20I~//~vafkR~
	ULPTR parm[XEERRMSG_MAXPARM];                                  //~vafkI~
//	unsigned long parmo[XEERRMSG_MAXPARM];                         //~va20I~//~vafkR~
  	ULPTR parmo[XEERRMSG_MAXPARM];                                 //~vafkI~
	char wkedit[XEERRMSG_MAXPARM][XEERRMSG_MAXPARMLEN+4];          //~va20R~
	char wkdbcst[XEERRMSG_MAXPARMLEN+2];                           //~va20I~
	char wkdata[XEERRMSG_MAXPARMLEN+2];                            //~va20I~
    int ii,jj,outlen,parmctr,len,opt,ct;                           //~va20R~
    UCHAR *pc,*pct,*pcw,*plc,**ppc,*pdbcs,*pc2;                     //~va20R~//~va50R~
    int lclen;                                                     //~va50R~
    UCHAR *pcti;                                                   //~va50R~
    int handle;                                                    //~va79I~
    void *pvoid;                                                   //~vap0I~
//************************                                         //~va20I~
    handle=XEERMO_GETHANDLE(Popt);                                 //~va79R~
	parmctr=min(Pparmctr,XEERRMSG_MAXPARM);                        //~va20I~
//  UGETSTDARG(unsigned long,parm,Pjmsg,Pparmctr);                 //~vav1R~
    UGETSTDARG(ULPTR,parm,Pjmsg,parmctr);                          //~vav1R~
//  for (ii=0,jj=0,pct=Pcodetype,ppc=(UCHAR**)(ULONG)parm;ii<parmctr;ii++)//~va20R~//~va50R~//~vafkR~
//  for (ii=0,jj=0,pct=Pcodetype,ppc=(UCHAR**)(ULPTR)parm;ii<parmctr;ii++)//~vafkI~//~vap0R~
    pvoid=parm;                                                    //~vap0I~
    for (ii=0,jj=0,pct=Pcodetype,ppc=(UCHAR**)pvoid;ii<parmctr;ii++)//~vap0I~
    {                                                              //~va20I~
    	pc=*ppc++;                                                 //~va20I~
    	pcw=wkedit[ii];                                            //~va20I~
        ct=*pct++;                                                 //~va20I~
    	switch(ct)                                                 //~va20R~
        {                                                          //~va20I~
        case XEERMPT_UTF8:                                         //~va20R~
//      	len=strlen(pc);                                        //~va20I~//~vb30R~
        	len=(int)strlen(pc);                                   //~vb30I~
            len=min(len,XEERRMSG_MAXPARMLEN);                      //~va20I~
#ifdef BBB                                                         //~va20I~
            opt=XEUTFCVO_CPLC|XEUTFCVO_ERRREPQM|XEUTFCVO_STRZ;     //~va20I~
            xeutf_cvdata(opt,pc,len,&plc,&outlen);                 //~va20R~
            len=min(outlen,XEERRMSG_MAXPARMLEN-1);                 //~va20I~
#else		//set utf8 code,later it is converted to dd fmt at xeutf_seterrmsgct_forxeerrmsg//~va20I~
			plc=pc;                                                //~va20I~
#endif                                                             //~va20I~
//          parmo[jj++]=(ULONG)pcw;                                //~va20M~//~vafkR~
            parmo[jj++]=(ULPTR)pcw;                                //~vafkI~
            *pcw++=XEERMCT_NOTLC;                                  //~va20R~
//          *pcw++=XEERMCT_UTF8;                                   //~va20I~//~vavcR~
//          *pcw++=XEERMCT_UTF8CODE;                               //~vavcR~
            *pcw++=XEERMCT_UTF8WC;                                 //~vavcI~
//          memcpy(pcw,plc,len);                                   //~va20R~//~vb30R~
            memcpy(pcw,plc,(size_t)len);                           //~vb30I~
            pcw+=len;                                              //~va20I~
            *pcw++=XEERMCT_NOTLC;                                  //~va20R~
            *pcw++=0;                                              //~va20R~
        	break;                                                 //~va20I~
        case XEERMPT_DDFMT:                                        //~va20I~
            pdbcs=*ppc++;                                          //~va20I~
//          len=(int)(ULONG)*ppc++;                                //~va20R~//~vafkR~
            len=(int)(ULPTR)*ppc++;                                //~vafkI~
            ii+=2;                                                 //~va20I~
            len=min(len,XEERRMSG_MAXPARMLEN);                      //~va20I~
            opt=0;                                                 //~va20R~
#ifdef BBB                                                         //~va20I~
            xeutfcvdd2l(opt,pc,pdbcs,len,&plc,&outlen);            //~va20I~
#else                                                              //~va20I~
            xeutfcvdd2f(opt,pc,pdbcs,len,&plc/*utf8*/,&outlen,0/*outdbcs*/);//~va20I~
#endif                                                             //~va20I~
            len=min(outlen,XEERRMSG_MAXPARMLEN-1);                 //~va20I~
//          parmo[jj++]=(ULONG)pcw;                                //~va20M~//~vafkR~
            parmo[jj++]=(ULPTR)pcw;                                //~vafkI~
            *pcw++=XEERMCT_NOTLC;                                  //~va20I~
//          *pcw++=XEERMCT_UTF8;                                   //~va20R~//~vavcR~
//          *pcw++=XEERMCT_UTF8CODE;                               //~vavcR~
            *pcw++=XEERMCT_UTF8WC;                                 //~vavcI~
//          memcpy(pcw,plc,len);                                   //~va20R~//~vb30R~
            memcpy(pcw,plc,(size_t)len);                           //~vb30I~
            pcw+=len;                                              //~va20I~
            *pcw++=XEERMCT_NOTLC;                                  //~va20R~
            *pcw++=0;                                              //~va20R~
        	break;                                                 //~va20I~
        case XEERMPT_EBC:                                          //~va20R~
        case XEERMPT_EBCDBCSPARM:                                  //~va20R~
        case XEERMPT_EBCDBCSALL:                                   //~va20R~
//      	len=strlen(pc);                                        //~va20I~//~vb30R~
        	len=(int)strlen(pc);                                   //~vb30I~
            len=min(len,XEERRMSG_MAXPARMLEN);                      //~va20I~
            opt=0;                                                 //~va20I~
    		if (ct==XEERMPT_EBCDBCSALL)                            //~va20R~
            {                                                      //~va20I~
            	pc2=wkdata;                                        //~va20I~
            	*pc2++=CHAR_SO;                                    //~va20R~
//              memcpy(pc2,pc,len);                                //~va20I~//~vb30R~
                memcpy(pc2,pc,(size_t)len);                        //~vb30I~
                pc2+=len;                                          //~va20R~
                *pc2++=CHAR_SI;                                    //~va20I~
                pc=wkdata;                                         //~va20I~
                pdbcs=0;                                           //~va20R~
            }                                                      //~va20I~
            else                                                   //~va20I~
    		if (ct==XEERMPT_EBCDBCSPARM)                           //~va20R~
            {                                                      //~va20I~
	            opt|=XEEBCO_CHKDBCSTB;                             //~va20I~
                pdbcs=*ppc++;                                      //~va20I~
                ii++;                                              //~va20I~
            }                                                      //~va20I~
            else                                                   //~va20I~
            {                                                      //~va20I~
//          	memset(wkdbcst,0,len);                             //~va20I~//~vb30R~
            	memset(wkdbcst,0,(size_t)len);                     //~vb30I~
                pdbcs=wkdbcst;                                     //~va20I~
            }                                                      //~va20I~
#ifdef BBB                                                         //~va20I~
            opt|=XEEBCO_ERRREP|XEEBCO_SOSIREPQ;                    //~va20R~
            xeebc_b2msetdbcs(opt,pc,pdbcs,len,&plc,0/*outdbcs*/,&outlen);//~va20R~
#else                                                              //~va20I~
            opt|=XEEBCO_ERRREP|XEEBCO_SOSIREPQ|XEEBCO_B2F;         //~va20R~
//          xeebc_b2msetdbcs(opt,pc,pdbcs,len,&plc/*pu8*/,&pdbcs/*input when CHKDBCSTB*/,&outlen);//~va20R~//~va79R~
            xeebc_b2msetdbcs(opt,handle,pc,pdbcs,len,&plc/*pu8*/,&pdbcs/*input when CHKDBCSTB*/,&outlen);//~va79R~
#endif                                                             //~va20I~
            len=min(outlen,XEERRMSG_MAXPARMLEN-1);                 //~va20I~
//          parmo[jj++]=(ULONG)pcw;                                //~va20M~//~vafkR~
            parmo[jj++]=(ULPTR)pcw;                                //~vafkI~
            *pcw++=XEERMCT_NOTLC;                                  //~va20I~
            *pcw++=XEERMCT_EBC;                                    //~va20R~
//          memcpy(pcw,plc,len);                                   //~va20R~//~vb30R~
            memcpy(pcw,plc,(size_t)len);                           //~vb30I~
            pcw+=len;                                              //~va20I~
            *pcw++=XEERMCT_NOTLC;                                  //~va20I~
            *pcw++=0;                                              //~va20I~
        	break;                                                 //~va20I~
        case XEERMPT_WITHCT:                                       //~va20I~
            pcti=*ppc++;    //parameter codetype ytbl              //~va20I~
            pdbcs=*ppc++;    //parameter codetype ytbl             //~va20I~
//          lclen=(int)*ppc++;    //parameter codetype ytbl        //~va20R~//~va70R~
            lclen=(int)(*(ULONG*)ppc++);    //parameter codetype ytbl//~va70I~
            ii+=3;                                                 //~va20R~
//          parmo[jj++]=(ULONG)pcw;                                //~va20I~//~vafkR~
            parmo[jj++]=(ULPTR)pcw;                                //~vafkI~
//      	len=strlen(pc);	//mixed strlen                         //~va20I~//~vb30R~
        	len=(int)strlen(pc);	//mixed strlen                 //~vb30I~
			xeerr_seterrmsgct(0,pc,len,pcti,pdbcs,lclen,pcw,XEERRMSG_MAXPARMLEN,0/*outlen*/);//~va50I~
        	break;                                                 //~va20I~
        case XEERMPT_CMDSTR:                                       //~va50I~
//      	len=strlen(pc);                                        //~va50I~//~vb30R~
        	len=(int)strlen(pc);                                   //~vb30I~
			lclen=fcmdsearchoncmdbuff(0,pc,len,&plc,&pcti,&pdbcs);//search Gcvmdbuffu8//~va50I~
            if (lclen)	//found on cmd buff                        //~va50I~
            {                                                      //~va50I~
				xeerr_seterrmsgct(0,pc,len,pcti,pdbcs,lclen,pcw,XEERRMSG_MAXPARMLEN,0/*outlen*/);//~va50I~
//              parmo[jj++]=(ULONG)pcw;                            //~va50I~//~vafkR~
                parmo[jj++]=(ULPTR)pcw;                            //~vafkI~
            }                                                      //~va50I~
            else                                                   //~va50I~
//      		parmo[jj++]=(ULONG)pc;                             //~va50I~//~vafkR~
        		parmo[jj++]=(ULPTR)pc;                             //~vafkI~
        	break;                                                 //~va50I~
        default:                                                   //~va20R~
//        	parmo[jj++]=(ULONG)pc;                                 //~va20R~//~vafkR~
        	parmo[jj++]=(ULPTR)pc;                                 //~vafkI~
        }                                                          //~va20I~
    }                                                              //~va20I~
    if (Popt & XEERMO_EXIT)                                        //~va20I~
    	uerrexit(Pemsg,Pjmsg,parmo[0],parmo[1],parmo[2],parmo[3],parmo[4]);//~va20I~
    if (Popt & XEERMO_CAT)                                         //~va20I~
    	uerrmsgcat(Pemsg,Pjmsg,parmo[0],parmo[1],parmo[2],parmo[3],parmo[4]);//~va20I~
    else                                                           //~va20I~
    	uerrmsg(Pemsg,Pjmsg,parmo[0],parmo[1],parmo[2],parmo[3],parmo[4]);//~va20I~
    return 0;                                                      //~va20I~
}//xeerrmsg                                                        //~va20I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va20I~
//****************************************************************
// errmissing
//*parm  :none
//*rc    :4
//****************************************************************
int errmissing(void)
{
	uerrmsg("Missing operand",
			"オペランドが足りません");                          //~v03bR~
	return 4;
}
//****************************************************************
// errtoomany
//*parm  :none
//*rc    :4
//****************************************************************
int errtoomany(void)
{
	uerrmsg("Too many operand",
    		"オペランドが多過ぎます");
	return 4;
}
//****************************************************************
// errinvalid
//*parm1 :operand string
//*rc    :4
//****************************************************************
int errinvalid(UCHAR *Popd)
{
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va20I~
	int lclen,len;                                                 //~va20R~
    UCHAR *plc,*pct,*pcd;                                          //~va20I~
#endif //UTF8EBCD raw ebcdic file support                          //~va20I~
//**********************                                           //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va20I~
//	len=strlen(Popd);                                              //~va20I~//+vb30R~
  	len=(int)strlen(Popd);                                         //+vb30I~
  if (len                                                          //~va20I~
  && (lclen=fcmdsearchoncmdbuff(0,Popd,len,&plc,&pct,&pcd))>0      //~va20I~
  &&  lclen<len//contains utf8                                     //~va20R~
  )                                                                //~va20I~
  {                                                                //~va20I~
	xeerrmsg(0,4/*u8,ct,dbcstb,lclen*/,XEERMPTS_WITHCT,            //~va20R~
			"Invalid operand value(%s)",                           //~va20I~
			"オペランドの誤り(%s)",                                //~va20I~
			Popd,pct,pcd,lclen);                                   //~va20R~
  }                                                                //~va20I~
  else                                                             //~va20I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va20I~
	uerrmsg("Invalid operand value(%s)",
			"オペランドの誤り(%s)",                             //~5715R~
			Popd);                                              //~5715I~
	return 4;
}
//****************************************************************//~v03bI~
// errdbcsinput                                                 //~v03bI~
//*parm1 :none                                                  //~v03bI~
//*rc    :4                                                     //~v03bI~
//****************************************************************//~v03bI~
int errdbcsinput(void)                                          //~v03bI~
{                                                               //~v03bI~
	uerrmsg("DBCS not avail",                                   //~v03bI~
			"全角入力不可");                                    //~v03bI~
	return 4;                                                   //~v03bI~
}                                                               //~v03bI~
//**************************************************************** //~v77bI~
// errnotnumeric                                                   //~v77bI~
//*rc    :4                                                        //~v77bI~
//**************************************************************** //~v77bI~
int errnotnumeric(void)                                            //~v77bI~
{                                                                  //~v77bI~
	uerrmsg("Numeric only",                                        //~v77bI~
			"数字のみ入力可");                                     //~v77bI~
	return 4;                                                      //~v77bI~
}                                                                  //~v77bI~
//**************************************************************** //~v77bI~
// errutf8charinput                                                //~v77bI~
//*rc    :4                                                        //~v77bI~
//**************************************************************** //~v77bI~
int errnotascii(void)                                              //~v77bI~
{                                                                  //~v77bI~
	uerrmsg("ASCII only",                                          //~v77bI~
			"ASCII文字のみ入力可");                                //~v77bI~
	return 4;                                                      //~v77bI~
}                                                                  //~v77bI~
//****************************************************************//~v03bI~
// errtoolong                                                   //~v03bI~
//*parm1 :none                                                  //~v03bI~
//*rc    :4                                                     //~v03bI~
//****************************************************************//~v03bI~
int errtoolong(void)                                            //~v03bI~
{                                                               //~v03bI~
	uerrmsg("Too long input",                                   //~v03bI~
			"長過ぎる入力");                                    //~v03bI~
	return 4;                                                   //~v03bI~
}                                                               //~v03bI~
//****************************************************************//~v03bI~
// errlcmd (lcmd format err)                                    //~v03bI~
//*parm1 :none                                                  //~v03bI~
//*rc    :4                                                     //~v03bI~
//****************************************************************//~v03bI~
int errlcmd(void)                                               //~v03bI~
{                                                               //~v03bI~
	uerrmsg("Invalid line cmd",                                 //~v03bI~
			"行コマンド形式エラー");                            //~v03bI~
	return 4;				//cmd err                           //~v03bI~
}                                                               //~v03bI~
//****************************************************************//~v03bI~
// erralready (already requested status)                        //~v03bI~
//*parm1 :none                                                  //~v03bI~
//*rc    :4                                                     //~v03bI~
//****************************************************************//~v03bI~
int erralready(void)                                            //~v03bI~
{                                                               //~v03bI~
	uerrmsg("Already in the status",                            //~v03bI~
			"既に要求された状況にあります");                    //~v03bI~
	return 4;				//cmd err                           //~v03bI~
}                                                               //~v03bI~
                                                                   //~v098I~
//*******************************************************          //~v098I~
//* errbrowsemode                                                  //~v098I~
//* parm:none                                                      //~v098I~
//* retrn:4                                                        //~v098I~
//*******************************************************          //~v098I~
int errbrowsemode(void)                                            //~v098I~
{                                                                  //~v098I~
//*******************                                              //~v098I~
	uerrmsg("The panel is browse mode",                            //~v098I~
//			"画面は表示モードです");                               //~v095R~,//~v098I~
  			"画面は\x95\\示モードです");                           //~v095I~,//~v098I~
	return 4;                                                      //~v098I~
}//errbrowsemode                                                   //~v098I~
                                                                   //~v0i8I~
//*******************************************************          //~v0i8I~
//!errcsrpos                                                       //~v60yR~
//* capcsrposerr                                                   //~v0i8I~
//* parm:none                                                      //~v0i8I~
//* retrn:4                                                        //~v0i8I~
//*******************************************************          //~v0i8I~
int errcsrpos(void)                                                //~v0i8I~
{                                                                  //~v0i8I~
//*******************                                              //~v0i8I~
	uerrmsg("Invalid cursor position",                             //~v0i8I~
//  		"カーソル位置の誤り");                                 //~v0i8I~
    		"カー\x83\\ル位置の誤り");                             //~v0i8I~
	return 4;                                                      //~v0i8I~
}//errcsrpos                                                       //~v0i8I~
//*******************************************************          //~v10vI~
//!errdir(void)                                                    //~v10vI~
//* parm:none                                                      //~v10vI~
//* retrn:4                                                        //~v10vI~
//*******************************************************          //~v10vI~
int errdir(UCHAR *Pfnm)                                            //~v10vI~
{                                                                  //~v10vI~
//*******************                                              //~v10vI~
	uerrmsg("%s is directory",                                     //~v10vI~
			"%s はディレクトリーです",Pfnm);                       //~v10vI~
	return 4;                                                      //~v10vI~
}//errdir                                                          //~v10vI~
                                                                   //~v155I~
//*******************************************************          //~v155I~
//!errdir(void)                                                    //~v155I~
//* parm:none                                                      //~v155I~
//* retrn:4                                                        //~v155I~
//*******************************************************          //~v155I~
int errformat(UCHAR *Pdata)                                        //~v155I~
{                                                                  //~v155I~
//*******************                                              //~v155I~
	uerrmsg("Format error:%s",                                     //~v155I~
			"形式エラー:%s",                                       //~v155I~
			Pdata);                                                //~v155I~
	return 4;                                                      //~v155I~
}//errdir                                                          //~v155I~
//*******************************************************          //~v62QI~
//!errovermax                                                      //~v62QI~
//* retrn:4                                                        //~v62QI~
//*******************************************************          //~v62QI~
int errovermax(UCHAR *Pdataname,char *Pparm,char *Pcomp,LONG Pmax) //~v62QR~
{                                                                  //~v62QI~
//*******************                                              //~v62QI~
	uerrmsg("%s parm (%s) is limitted.(%s%ld)",                    //~v62QR~
			"%s パラメータ(%s)の制限値違反(%s%ld)",                //~v62QR~
			Pdataname,Pparm,Pcomp,Pmax);                           //~v62QR~
	return 4;                                                      //~v62QI~
}//errovermax                                                      //~v62QI~
//*******************************************************          //~v417I~
//!errdir(void)                                                    //~v417I~
//* parm:none                                                      //~v417I~
//* retrn:4                                                        //~v417I~
//*******************************************************          //~v417I~
int errprotected(void)                                                 //~v417I~
{                                                                  //~v417I~
//*******************                                              //~v417I~
	uerrmsg("Field Protected",                                     //~v417I~
			"書き込み保護欄");                                     //~v417R~
	return 4;                                                      //~v417I~
}//errdir                                                          //~v417I~
//*******************************************************          //~v417M~
//!errmarginboundary                                               //~v417I~
//* errmsg issue                                                   //~v417M~
//* parm:none                                                      //~v417M~
//* retrn:4                                                        //~v417M~
//*******************************************************          //~v417M~
int errmarginboundary(void)                                        //~v417I~
{                                                                  //~v417M~
//*******************                                              //~v417M~
    uerrmsg("Margin boundary",                                     //~v417M~
            "マージン境界");                                       //~v417M~
    return 4;                                                      //~v417M~
}//errmarginboundary                                               //~v417I~
//**************************************************************** //~v43mI~
// errinvalid                                                      //~v43mI~
//*parm1 :operand string                                           //~v43mI~
//*rc    :4                                                        //~v43mI~
//**************************************************************** //~v43mI~
int errconflict(UCHAR *Popd1,UCHAR *Popd2)                         //~v43mI~
{                                                                  //~v43mI~
//**************                                                   //~v43mI~
	if (Popd2)                                                     //~v43mR~
		uerrmsg("%s is in conflict with %s",                       //~v43mR~
				"%s は %s と矛盾します",                           //~v43mR~
				Popd1,Popd2);                                      //~v43mR~
    else                                                           //~v43mI~
		uerrmsg("%s is in conflict with other parm or status",     //~v43mR~
				"%s は 他の指定,状況と矛盾します",                 //~v43mR~
//  			Popd1,Popd2);                                      //~v77vR~
    			Popd1);                                            //~v77vI~
	return 4;                                                      //~v43mI~
}                                                                  //~v43mI~
//**************************************************************** //~v50mI~
// errscrtype                                                      //~v50mI~
//*parm1 :cmd string                                               //~v50mI~
//*rc    :4                                                        //~v50mI~
//**************************************************************** //~v50mI~
int errscrtype(UCHAR *Pcmd)                                        //~v50mI~
{                                                                  //~v50mI~
	uerrmsg("\"%s\" is not a valid command for this panel",        //~v50mI~
			"\"%s\" はこの画面では使用できません",                 //~v50mI~
			Pcmd);                                                 //~v50mI~
    return 4;                                                      //~v50mI~
}//errscrtype                                                      //~v50mI~
//**************************************************************** //~v50EI~
// errnotsupported                                                 //~v50EI~
//*parm1 :cmd string                                               //~v50EI~
//*rc    :4                                                        //~v50EI~
//**************************************************************** //~v50EI~
int errnotsupported(UCHAR *Pcmd,UCHAR *Pcond)                      //~v50EI~
{                                                                  //~v50EI~
	uerrmsg("\"%s\" is not supported for %s.",                     //~v50EI~
			"\"%s\" は %s ではサポ－トされません。",               //~v50EI~
			Pcmd,Pcond);                                           //~v50EI~
    return 4;                                                      //~v50EI~
}//errnotsupported                                                 //~v50EI~
//**************************************************************** //~v60yI~
// errscrnotsplited                                                //~v60yI~
//*rc    :4                                                        //~v60yI~
//**************************************************************** //~v60yI~
//int errscrnotsplited(void)                                       //~v62fR~
int errscrnotsplited(char *Pparm)                                  //~v62fI~
{                                                                  //~v60yI~
 	uerrmsg("parm(%s) err,screen is not splitted",                 //~v60yI~
            "パラメータ(%s)エラー。画面は分割されていません。",    //~v60yI~
//          FNMOF2NDSCR);                                          //~v62fR~
            Pparm);                                                //~v62fI~
    return 4;                                                      //~v60yI~
}                                                                  //~v60yI~
//**************************************************************** //~v60yI~
// err2ndscrisnotfile                                              //~v60yI~
//*rc    :4                                                        //~v60yI~
//**************************************************************** //~v60yI~
//int err2ndscrisnotfile(void)                                     //~v62fR~
int err2ndscrisnotfile(char *Pparm)                                //~v62fI~
{                                                                  //~v60yI~
    uerrmsg("parm(%s) err,another screen is not file ones",        //~v60yI~
            "パラメータ(%s)エラー。もう一方の画面がファイル画面でない。",//~v60yI~
//                  	FNMOF2NDSCR);                              //~v62fR~
	                  	Pparm);                                    //~v62fI~
    return 4;                                                      //~v60yI~
}                                                                  //~v60yI~
//**************************************************************** //~v60vI~
//errnotvalidhexchar                                               //~v60vI~
//invalid hex digit input                                          //~v60vI~
//*rc    :4                                                        //~v60vI~
//**************************************************************** //~v60vI~
int errnotvalidhexchar(void)                                       //~v60vI~
{                                                                  //~v60vI~
	uerrmsg("Invalid Hex digit input",                             //~v60vI~
    		"HEX文字入力の誤り");                                  //~v60vI~
    return 4;                                                      //~v60vI~
}//errnotvalidhexchar                                              //~v60vI~
#ifdef UTF8SUPPH                                                   //~va0mR~
//**************************************************************** //~va0mI~
//erroptionforbinfile                                              //~va0mI~
//**************************************************************** //~va0mI~
int erroptionforbinfile(char *Poption,int Prc)                     //~va0mR~
{                                                                  //~va0mI~
	uerrmsg("%s is invalid option for binary file",                //~va0mI~
    		"%s オプションはバイナリーファイルでは無効です",       //~va0mI~
            	Poption);                                          //~va0mI~
    return Prc;                                                    //~va0mI~
}//erroptionforbinfile                                             //~va0mI~
#endif                                                             //~va0mI~
#ifdef UTF8UCS2                                                    //~va20I~
//**************************************************************** //~va20I~
//errutf8andnonutf8                                                //~va20R~
//**************************************************************** //~va20I~
int errutf8andnonutf8(char *Poption,int Prc)                       //~va20I~
{                                                                  //~va20I~
	uerrmsg("%s is invalid between Locale file and UTF8 file",     //~va20I~
    		"ロケールコードとUTF8ファイル間では %s 出来ません",    //~va20I~
            	Poption);                                          //~va20I~
    return Prc;                                                    //~va20I~
}//errutf8andnonutf8                                               //~va20R~
#endif                                                             //~va20I~
#ifdef UNX                                                         //~vaa0I~
//**************************************************************** //~vaa0I~
int errwildnamemultiple(int Popt,char *Pfname)                     //~vaa0R~
{                                                                  //~vaa0I~
	uerrmsg("request(except \"R\"ename)rejected because there are mutiple entry displayed as %s",//~vaa0R~
            "%s で表\示の無効ファイル名は複数あります(\"R\"ename のみ可)",//~vaa0R~
			Pfname);                                               //~vaa0R~
    return FILE_WILDNAME_MULTIPLE;                                 //~vaa0M~
}//errwildnamemultiple                                             //~vaa0I~
#endif                                                             //~vaa0I~
