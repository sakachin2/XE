//*CID://+vbBqR~:                             update#=  519;       //~vbBqR~
//*********************************************************************//~0423R~
//* xeebc.c
//*************************************************************
//vbBq:241108 display green when lcmd copy b2m/m2b when cv err     //~vbBqI~
//vbBn:241105 display green when b2dd err                          //~vbBnI~
//vbBm:241105 tabdisplay dbcs; when cv err and fffd(ambiguous) is sbcs width by /Gnn. output remains 0xcc(not set)  data and dbcs. clear it before call b2dddbcs1//~vbBmI~
//vbBk:241103 (BUG)cfg-SUCHAR was not work                         //~vbBkI~
//vbBj:241019 (BUG)cfg E2A(converter is not external) was ignored when ebc<0x40//~vbBjI~
//vbBc:240910 support ebcidic cfg file cmdline parameter           //~vbBcI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vb2C:160221 W32 compiler warning                                 //~vb2CI~
//vb2B:160221 (Win)UCS4 support                                    //~vb2BI~
//vap0:131215 (ARM)warning strict aliasing                         //~vap0I~
//vak5:130816 compiler warning;set but not used                    //~vak5I~
//vaj5:130722 delete xeebc_getchebc which is not used(ebc suould be multiple byte to call xeebc_m2b1)//~vaj5I~
//vaj4:130722 display converter name when conversion failed of kbd //~vaj4I~
//vagB:120918 (BUG)ebcfile copywordcmd_file cause buff overflow    //~vagBI~
//vag8:120821 (BUG)cv b2b cmd did not set errline flag             //~vag8I~
//vag6:120821 rep by subchar for b2b(now keep original value)      //~vag6I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafb:120608 (BUG)b2msetdbcs abend if ULHlen=0("rep ebc2mb cplc","copy ebc into lc file")//~vafbI~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaac:111211 CV cmd;add F2B/B2F because cpu8 file could not be conv at place by DBCS tbl fmt difference//~vaacI~
//            and M of M2B/B2M is current locale only              //~vaacI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va8w:101209 SPLIT/TFLOW:delete so/si when join dbcs string       //~va8wI~
//va8s:101026 (BUG)TFLow:head count for top dbcssplit              //~va8sI~
//va8p:101020 (BUG) could not override si+si bu dbcs kbdinput      //~va8pI~
//va8k:101013 SPLit cmd;dbcs consideration for split ALL/OVER without SBCS option .//~va8kI~
//va8j:101013 SPLit cmd;dbcs consideration for TAIL cut without SBCS option .//~va8jI~
//va8i:101011 bnds sort;add SBCS option for BNDS sort without dbcs consideration//~va8iI~
//va8h:101010 bnds sort;set space to split dbcs except dbcs continued case//~va8hI~
//va8b:101001 dbcs consideration for C&P                           //~va8bI~
//va80:100917 (WXEXXE)print ebcfile by ucs                         //~va80I~
//va7T:100909 cpeb converter parm support:for xprint               //~va7TI~
//va7y:100823 EBC:handle support for cap                           //~va7yI~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va7u:100825 accept sbcs->dbcs for ebc to utf8 copy               //~va7uR~
//va7t:100823 EBC:handle support to file output(save/rep/..)       //~va7tI~
//va7s:100823 (BUG)searchword recover fail for EBC file(u8str saved but recovery is by simple getmixword//~va7sI~
//va7p:100821 C+w(copy to cmdline):select utf8 if f2l conv err detected ebn when kbd is lc mode//~va7pI~
//va7i:100820 (BUG)syntax chk failed(external syntaxhighlight failed by null data)//~va7iI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va72:100801 LP64 wchar_t is 4byte on LP64                        //~va72I~
//va6w:000627 lcmd comp("=") support among locale,utf8 and ebc file//~va6wI~
//va6m:000622 b2m expand dbcstbl by EUC hankana,request set to ucvebc3 b2m//~va6mI~
//va6c:100619 add SOSI option -S{i|r|d} to REP/CRE/APP/SAV/COP/MOV cmd//~va6cI~
//va63:100614 (LNX)additional to va62;gb4 max is 4 byte            //~va63I~
//va62:100613 (LNX)EUC hankana<-EBC expand SBCS->DBCS(8exx)        //~va62I~
//va60:100602 allow binaly opend file translation;l2b              //~va60I~
//va5X:100529 cv control(ascii 0x<20) also                         //~va5XI~
//va5L:100523 (w)xpr cmd;print SO/SI by "?"                        //~va5LI~
//va5E:100521 DBCS errrep when b2f err for C&P                     //~va5EI~
//va5A:100519 Ctrl+W(copyword to cmdline);drop so/si               //~va5AI~
//va5q:100512 SPL/TFLOW cmd support sbcs utf8 delm char            //~va5qI~
//*************************************************************    //~va5qI~
#ifdef UTF8EBCD	  //raw ebcdic file support
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*************************************************************
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <udbcschk.h>
#include <ustring.h>
#include <ufile.h>
#include <ucvucs.h>
#include <ucvebc.h>
#include <ucvext.h>
#include <ucvebc4.h>                                               //~va79I~
#include <ualloc.h>
#include <utrace.h>
#include <ukbd.h>
#include <utf.h>                                                   //~vagBI~
#include <utf22.h>

#include "xe.h"
#include "xescr.h"
#include "xepan.h"
#include "xefile.h"
#include "xeutf.h"
#include "xefile6.h"
#include "xesub.h"
#define XEEBC_GLOBAL
#include "xeebc.h"
#include "xeopt.h"
#include "xesub2.h"
#include "xegbl.h"
#include "xechar.h"
#include "xeutf2.h"                                                //~0509I~
#include "xeerr.h"                                                 //~0511I~
//*******************************************************
//*******************************************************
int xeebc_m2b(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,char *Poutbuff,int Poutbuffsz,int *Ppoutlen);
int xeebc_setdbcstbltabkeep(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);
int xeebc_filesetsosistr(int Popt,UCHAR *Ptgtdata,UCHAR *Ptgtdbcs,int Ptgtlen,int Ppos,//~va80I~//~va8bR~
					UCHAR *Psrcdata,UCHAR *Psrcdbcs,int Psrclen,   //~va80I~
                    UCHAR *Poutsrcdata,UCHAR *Poutsrcdbcs,int *Ppoutsrclen);//~va80I~
int xeebc_filesetsosibnds(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Ppos,int Plen);//~va8hI~
int getebc3opt(int Pebcopt);                                       //~vaacI~
//****************************************************************
//*******************************************************
//*ebc-->locale code
//rc:1:dbcs data detected
//*******************************************************
int xeebc_init(int Popt,void *Pcfg)
{
    char fpath[_MAX_PATH],*pfnm;
    int rc=0;
    int opt;                                                       //~va7TI~
    PUCVEXTCFG pcfg;                                               //~va7TI~
    void *pvoid;                                                   //~vap0I~
//*****************
	UTRACEP("%s:Popt=0x%04x,Gebcstat=0x%04x\n",UTT,Popt,Gebcstat); //~vb2DR~
#ifndef AAA
    Gebcstat|=GES_DDFMTPSD;
#endif
	if (Popt & XEEBCIO_CFGFILE)
    {
		UTRACEP("%s:XEEBCIO_CFGFILE fnm=%s\n",UTT,Pcfg);           //~vb2DI~
        pfnm=Pcfg;
        if (!*pfnm) //nullified                                    //~vbBcI~
            *fpath=0;                                              //~vbBcI~
//  	if (!filefullpath(fpath,pfnm,_MAX_PATH))                   //~vbBcR~
    	if (*pfnm && !filefullpath(fpath,pfnm,_MAX_PATH))          //~vbBcI~
        	rc=8;
        else
        {                                                          //~0501I~
        	Gebcstat|=GES_INIPARM;     //inifile parameter specified//~0501I~
        	opt=UCVEBC3O_CFGFILE;                                  //~va7TI~
        	if (pfnm && strcmp(pfnm,XEEBC_DEFAULTCFGFILE))         //~va7TI~
            	opt|=UCVEBC3O_ERRMSG;                              //~va7TR~
//      	rc=ucvebc3_init(UCVEBC3O_CFGFILE,(ULONG*)(ULONG)fpath);//~va5LR~//~va7TR~
//      	rc=ucvebc3_init(opt,(ULONG*)(ULONG)fpath);             //~va7TI~//~vafkR~
//      	rc=ucvebc3_init(opt,(ULPTR*)(ULPTR)fpath);             //~vafkI~//~vap0R~
        	pvoid=fpath;                                           //~vap0I~
        	rc=ucvebc3_init(opt,(ULPTR*)pvoid);                    //~vap0I~
//      	ucvebc3_init(UCVEBC3O_GETCFG,(ULONG*)(ULONG)(&pcfg));  //~va7TI~//~vafkR~
//      	ucvebc3_init(UCVEBC3O_GETCFG,(ULPTR*)(ULPTR)(&pcfg));  //~vafkI~//~vap0R~
        	pvoid=&pcfg;                                           //~vap0I~
        	ucvebc3_init(UCVEBC3O_GETCFG,(ULPTR*)pvoid);           //~vap0I~
            if (pcfg->UCECflag & UCECF_OPENERR)                    //~va7TI~
            	Gebcstat|=GES_CFGOPENERR;                          //~va7TI~
        }                                                          //~0501I~
        UFREEIFNZ(Gebccfgfnm);                                     //~0429I~
        Gebccfgfnm=umalloc(strlen(fpath)+1);                       //~0429I~
        strcpy(Gebccfgfnm,fpath);                                  //~0429I~
        return rc;
    }
	if (Popt & XEEBCIO_INIT)
    {
		UTRACEP("%s:XEEBCIO_INIT Gebcstat=0x%04x\n",UTT,Gebcstat); //~vb2DI~
        if (Gebcstat & GES_CLPCFG)      //cmdline parm /ebccfg specified//~vbBcI~
        {                                                          //~vbBcI~
			UTRACEP("%s:cmdline parm specified fnm=%s\n",UTT,Pcfg);//~vbBcI~
        	rc=xeebc_init(XEEBCIO_CFGFILE,Pcfg/*cfg fnm*/);        //~vbBcR~
        }                                                          //~vbBcI~
        else                                                       //~vbBcI~
        if (!(Gebcstat & GES_INIPARM))      //inifile not parameter specified
        	rc=xeebc_init(XEEBCIO_CFGFILE,XEEBC_DEFAULTCFGFILE);
        return rc;
    }
	if (Popt & (XEEBCIO_CHKCFG))
    {
        if (Gebcstat & GES_CFGERR)      //inifile not parameter specified
        {
//      	if (Popt & (XEEBCIO_CHKCFG))                           //~va7TR~
        		if (!(Popt & XEEBCIO_NOMSG))
                {
                    uerrmsg("%s option is not available(check default file\"%s\" or inifile parameter \"%s\")",
                            "%s オプションは使用できません(\"%s\"(default)ファイル または INIファイルの \"%s\" を調べる)",
                            MODE_EBC,XEEBC_DEFAULTCFGFILE,XEEBC_INIFILEPARM);
                }
            rc=4;
        }
        return rc;
    }
	if (Popt & (XEEBCIO_GETDEFAULT))                               //~va5LI~
    {                                                              //~va5LI~
		if (xeebc_init(XEEBCIO_CHKCFG,0))                          //~va5LR~
        	return 4;                                              //~va5LI~
//      ucvebc3_init(UCVEBC3O_GETCFG,(ULONG*)(ULONG)Pcfg);         //~va5LR~//~vafkR~
        ucvebc3_init(UCVEBC3O_GETCFG,(ULPTR*)(ULPTR)Pcfg);         //~vafkI~
        return 0;                                                  //~va5LI~
    }                                                              //~va5LI~
    return 4;
}//xeebc_init
//*******************************************************
//*ebc-->locale code
//rc:1:dbcs data detected
//*******************************************************
void xeebc_term(int Popt)
{
//*****************
    UFREEIFNZ(Gebccfgfnm);                                         //~0429I~
    return;
}//xeebc_term
//*******************************************************
//*ebc-->locale code
//rc:1:dbcs data detected,4:err
//*******************************************************
//int xeebc_ucs2ebc1(int Popt,ULONG Pucs,UCHAR *Poutbuff,int *Ppoutlen)//~va79R~
int xeebc_ucs2ebc1(int Popt,int Phandle,ULONG Pucs,UCHAR *Poutbuff,int *Ppoutlen)//~va79I~
{
	int opt,rc=0,outlen;
    WUCS wucs;
//*****************
    opt=0;
    wucs=(WUCS)Pucs;
//  rc=ucvebc3_u2b1(opt,wucs,Poutbuff,&outlen);                    //~va79R~
    rc=ucvebc3_u2b1(opt,Phandle,wucs,Poutbuff,&outlen);            //~va79I~
    if (Ppoutlen)
    	*Ppoutlen=outlen;
    UTRACEP("xeutf_ucs2ebc1 ucs=%x,rc=%d\n",Pucs,rc);
    UTRACED("xeutf_ucs2ebc1 ebc",Poutbuff,outlen);
    return rc;
}//xeebc_ucs2ebc1
//*******************************************************
//*ebc<---locale code  1 char
//rc:4 err;
//*******************************************************
//int xeebc_m2b1(int Popt,UCHAR *Pdata,int Plen,UCHAR *Poutbuff,int *Ppoutlen)//~va79R~
int xeebc_m2b1(int Popt,int Phandle,UCHAR *Pdata,int Plen,UCHAR *Poutbuff,int *Ppoutlen)//~va79I~
{
	int opt=0,rc=0,rc3,outlen;
//*****************
    UTRACED("xeebc_m2b1 inp mbstr",Pdata,Plen);
//  rc3=ucvebc3_m2b1(opt,Pdata,Plen,Poutbuff,&outlen);             //~va79R~
    rc3=ucvebc3_m2b1(opt,Phandle,Pdata,Plen,Poutbuff,&outlen);     //~va79I~
    if (rc3>=4)
    	rc=4;
    if (Ppoutlen)
    	*Ppoutlen=outlen;
    UTRACEP("xeebc_m2b1 rc3=%d,rc=%d\n",rc3,rc);
    UTRACED("xeutf_m2b1 out ebcstr",Poutbuff,outlen);
    return rc;
}//xeebc_m2b1
////****************************************************************//~vaj5R~
////xeebc_getebcrepch                                              //~vaj5R~
////****************************************************************//~vaj5R~
////int xeebc_getchebc(int Popt,int Pasciich)                        //~va79R~//~vaj5R~
//int xeebc_getchebc(int Popt,int Phandle,int Pasciich)              //~va79R~//~vaj5R~
//{                                                                //~vaj5R~
//    UCHAR ascii,ebc;                                             //~vaj5R~
////***********                                                    //~vaj5R~
//    ascii=Pasciich;                                              //~vaj5R~
////  xeebc_m2b1(0,&ascii,1/*inplen*/,&ebc,0/*outlen*/);             //~va79R~//~vaj5R~
//    xeebc_m2b1(0,Phandle,&ascii,1/*inplen*/,&ebc,0/*outlen*/);     //~va79I~//~vaj5R~
//    return (int)ebc;                                             //~vaj5R~
//}//xeebc_getchebc                                                //~vaj5R~
//*******************************************************          //~0506I~
//*ebc<--ascii locale code                                         //~0506I~
//*******************************************************          //~0506I~
int xeebc_ascii2b(int Popt,int Phandle,UCHAR *Pdata,int Plen,UCHAR **Ppoutdata) //~0506I~//~va5qR~//~va79R~
{                                                                  //~0506I~
	int ch,cho,buffsz;                                             //~0506I~
    UCHAR *pc,*pco,*pce,*pbuff;                                    //~0506I~
//*****************                                                //~0506I~
    buffsz=Plen;                                                   //~0506I~
    pbuff=xeutf_buffget(XEUTF_BUFEBC,buffsz);                      //~0506I~
	UALLOCCHK(pbuff,UALLOC_FAILED);                                //~0506I~
	for(pc=Pdata,pce=pc+Plen,pco=pbuff;pc<pce;)                    //~0506I~
    {                                                              //~0506I~
    	ch=*pc++;                                                  //~0506I~
//  	cho=EBC_A2B(ch);                                           //~0506R~//~va79R~
    	cho=UCVEBCH_A2B(Phandle,ch);                               //~va79I~
        if (!cho && ch)                                            //~0506I~
        	cho=CHAR_EBC_ERR;                                      //~0506R~
//      *pco++=cho;                                                //~0506I~//~vb2CR~
        *pco++=(UCHAR)cho;                                         //~vb2CI~
    }                                                              //~0506I~
    *Ppoutdata=pbuff;                                              //~0506I~
    return 0;                                                      //~0506R~
}//xeebc_ascii2b                                                   //~0506I~
//*******************************************************          //~0509I~
//*cmd string-->dd fmt or ebcdic                                   //~0509I~
//*******************************************************          //~0509I~
int xeebc_m2ddebc(int Popt,PUFILEH Ppfh,UCHAR *Pdata,int Plen,char *Poutdata,char *Poutdbcs,int Poutbuffsz,int *Ppoutlen)//~0509I~
{                                                                  //~0509I~
//  int rc,opt=0,len,ddlen;                                        //~0512R~//~vaf9R~
    int rc,opt=0,len=0,ddlen;                                      //~vaf9I~
    int handle;                                                    //~va79I~
    UCHAR wkdddata[MAXCOLUMN];	//for psd                          //~0511I~
    UCHAR wkdddbcs[MAXCOLUMN];	//for psd                          //~0511I~
//******************                                               //~0509I~
	if (Popt & XEEBCM2DEO_SAVECT)                                  //~0511I~
    	opt|=XEUTFGDDS_SAVECT;//save utf8 str for errmsg           //~0511I~
    rc=xeutfgetddstr(opt,Pdata,Plen,Poutdata,Poutbuffsz,Ppoutlen,Poutdbcs);//~0511R~
    if (!rc && PFH_ISEBC(Ppfh))                                    //~0511R~
    {                                                              //~0511I~
        ddlen=*Ppoutlen;                                           //~0512I~
    	if (Popt & XEEBCM2DEO_ERRMSG)                              //~0511I~
        {                                                          //~0511I~
//    		len=min(ddlen,sizeof(wkdddata));                       //~0512R~//~vb2DR~
      		len=min(ddlen,(int)sizeof(wkdddata));                  //~vb2DI~
//      	memcpy(wkdddata,Poutdata,len);  //for errmsg           //~0511I~//~vb2DR~
        	memcpy(wkdddata,Poutdata,(size_t)len);  //for errmsg   //~vb2DI~
//      	memcpy(wkdddbcs,Poutdbcs,len);                         //~0511I~//~vb2DR~
        	memcpy(wkdddbcs,Poutdbcs,(size_t)len);                 //~vb2DI~
        }                                                          //~0511I~
        handle=Ppfh->UFHhandle;                                    //~va79I~
    	opt=XEEBCO_DD2B;                                           //~0511I~
//  	rc=xeebc_m2bsrchstr(opt,Poutdata,Poutdbcs,ddlen,Poutdata,Poutdbcs,Poutbuffsz,Ppoutlen);//~0512R~//~va79R~
    	rc=xeebc_m2bsrchstr(opt,handle,Poutdata,Poutdbcs,ddlen,Poutdata,Poutdbcs,Poutbuffsz,Ppoutlen);//~va79R~
        if (rc                                                     //~0511I~
    	&& Popt & XEEBCM2DEO_ERRMSG)                               //~0511I~
			xeerrmsg(0,3,XEERMPTS_DDFMT,                           //~0511R~
					"translation err to EBCDIC(%s)",0,             //~0511I~
                    wkdddata,wkdddbcs,len);	                       //~0511R~
    }                                                              //~0511I~
    return rc;                                                     //~0509I~
}//xeebc_m2ddebc                                                   //~0509I~
//*******************************************************          //~0507I~
//*ebc<--locale for search string(drop top/end so/si)              //~0507I~
//rc:1:cv err,8 buff ovf,ualloc_failed                             //~0507I~
//*******************************************************          //~0507I~
//int xeebc_m2bsrchstr(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,char *Poutdata,char *Poutdbcs,int Poutbuffsz,int *Ppoutlen)//~0511R~//~va79R~
int xeebc_m2bsrchstr(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,char *Poutdata,char *Poutdbcs,int Poutbuffsz,int *Ppoutlen)//~va79I~
{                                                                  //~0507I~
	int ebclen,len,rc2,rc=0,opt;                                   //~0507R~
    UCHAR *pebc,*pdbcs;                                            //~0507I~
    int swdbcsenv;                                                 //~va5XI~
//******************                                               //~0507I~
//  swdbcsenv=UDBCSCHK_ISDBCSCV();                                 //~va5XI~//~va79R~
    swdbcsenv=UCVEBCH_HANDLE_ISDBCSCV(Phandle);                    //~va79I~
    opt=Popt;	//DD2B                                             //~0511R~
//  rc2=xeebc_m2bsetdbcs(opt,Pdata,Pdbcs,Plen,&pebc,&pdbcs,&ebclen);//~0511R~//~va79R~
    rc2=xeebc_m2bsetdbcs(opt,Phandle,Pdata,Pdbcs,Plen,&pebc,&pdbcs,&ebclen);//~va79I~
    UALLOCCHKRC(rc2);                                              //~0507I~
    if (rc2)                                                       //~0507I~
    	rc=1;	//cverr                                            //~0507I~
  if (swdbcsenv)                                                   //~va5XI~
    if (ebclen>2 && *pebc==CHAR_SO && *(pebc+ebclen-1)==CHAR_SI)   //~0507R~
    {                                                              //~0507I~
        pebc++;                                                    //~0507I~
        pdbcs++;                                                   //~0507I~
        ebclen-=2;                                                 //~0507I~
    }                                                              //~0507I~
    len=min(Poutbuffsz,ebclen);                                    //~0507I~
    memcpy(Poutdata,pebc,(UINT)len);                               //~0507I~
    memcpy(Poutdbcs,pdbcs,(UINT)len);                              //~0507I~
    *Ppoutlen=len;                                                 //~0507I~
    if (len<ebclen)                                                //~0507I~
    	rc|=8;                                                     //~0507I~
    return rc;                                                     //~0507I~
}//xeebc_m2bsrchstr                                                //~0507I~
//*******************************************************          //~va7sI~
//*drop boundary so/si                                             //~va7sI~
//*rc:1 dropped                                                    //~va7sI~
//*******************************************************          //~va7sI~
int xeebc_dropsosi(int Popt,UCHAR *Pebcdata,UCHAR *Pebcdbcs,int Pebclen,int *Ppoutlen)//~va7sI~
{                                                                  //~va7sI~
	UCHAR *pc,*pcd,*pce,*pcde;                                     //~va7sR~
    int len,rc;                                                    //~va7sR~
//*********                                                        //~va7sI~
	len=Pebclen;                                                   //~va7sI~
    pc=Pebcdata;                                                   //~va7sR~
    pcd=Pebcdbcs;                                                  //~va7sI~
	if (len>=2                                                     //~va7sI~
    && *pc==CHAR_SO                                                //~va7sI~
    && *(pcd+1)==UDBCSCHK_DBCS1ST                                  //~va7sI~
    )                                                              //~va7sI~
    {                                                              //~va7sI~
    	pc++;                                                      //~va7sI~
        pcd++;                                                     //~va7sI~
        len--;                                                     //~va7sI~
    }                                                              //~va7sI~
    pce=Pebcdata+Pebclen-1;                                        //~va7sI~
    pcde=Pebcdbcs+Pebclen-2;                                       //~va7sR~
    if (len>=2                                                     //~va7sI~
    && *pce==CHAR_SI                                               //~va7sI~
    && *pcde==UDBCSCHK_DBCS2ND                                     //~va7sR~
    )                                                              //~va7sI~
        len--;                                                     //~va7sI~
    *Ppoutlen=len;                                                 //~va7sI~
    if (len!=Pebclen && len)                                       //~va7sI~
    {                                                              //~va7sI~
        memcpy(Pebcdata,pc,(UINT)len);                             //~va7sI~
        memcpy(Pebcdbcs,pcd,(UINT)len);                            //~va7sI~
        rc=1;                                                      //~va7sI~
    }                                                              //~va7sI~
    else                                                           //~va7sI~
    	rc=0;                                                      //~va7sI~
    return rc;                                                     //~va7sI~
}//xeebc_dropsosi                                                  //~va7sI~
//*******************************************************          //~va7sI~
//*ebc<--utf8                                                      //~va7sI~
//*rc:UALLOC_FAILED                                                //~va7sI~
//*******************************************************          //~va7sI~
int xeebc_f2bsetdbcs(int Popt,int Phandle,UCHAR *Putf8,int Putf8len,UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen)//~va7sI~
{                                                                  //~va7sI~
	int opt,ddlen,ebclen,rc;                                       //~va7sI~
    UCHAR *pddw,*pdbcsw,*pwebcdata,*pwebcdbcs;                     //~va7sR~
//*****************                                                //~va7sI~
    UTRACED("xeutf_f2b inp utf8data",Putf8,Putf8len);              //~va7sI~
	rc=xeutf_cvf2dd(0,Putf8,Putf8len,&pddw,&pdbcsw,&ddlen);        //~va7sI~
	if (rc>=4)                                                     //~va7sI~
    	return rc;                                                 //~va7sI~
	opt=Popt|XEEBCO_DD2B;           //dd2b                         //~va7sI~
    rc=xeebc_m2bsetdbcs(opt,Phandle,pddw,pdbcsw,ddlen,&pwebcdata,&pwebcdbcs,&ebclen);//~va7sI~
	if (rc>=4)                                                     //~va7sI~
    	return rc;                                                 //~va7sI~
    if (Popt & XEEBCO_DROPSOSI)                                    //~va7sI~
    {                                                              //~va7sI~
    	if (UCVEBCH_HANDLE_ISDBCSCV(Phandle))                      //~va7sI~
			xeebc_dropsosi(0,pwebcdata,pwebcdbcs,ebclen,&ebclen);  //~va7sR~
    }                                                              //~va7sI~
    *Ppoutdata=pwebcdata;                                          //~va7sI~
    *Ppoutdbcs=pwebcdbcs;                                          //~va7sI~
    *Ppoutlen=ebclen;                                              //~va7sI~
    UTRACED("xeutf_f2b out ebc data",pwebcdata,ebclen);            //~va7sI~
    UTRACED("xeutf_f2b out ebc dbcs",pwebcdbcs,ebclen);            //~va7sI~
    return 0;                                                      //~va7sI~
}//xeebc_f2bsetdbcs                                                //~va7tR~
//*******************************************************
//*ebc<--locale code/ddfmt                                         //~0423R~
//UALLOC_FAILED,rc of ucvebc3_dd2b,m2b                             //~va7sI~
//*******************************************************
//int xeebc_m2bsetdbcs(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen)//~va5qR~//~va79R~
int xeebc_m2bsetdbcs(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen)//~va79I~
{
	int outlen,opt=0,buffsz,mblen,ebclen,rc;                         //~0424R~//~va5XR~
    UCHAR *pdata,*pdbcs,*pbuff,*poutdata,*poutdbcs;
//*****************
    UTRACEP("xeebc m2bsetdbcs opt=%x\n",Popt);                     //~va5XI~
	if (Popt & XEEBCO_CVCTL) //dd fmt to ebc                       //~va5XI~
		opt|=UCVEBC3O_CVCTL;                                       //~va5XI~
	buffsz=0;
    if (Popt & XEEBCO_SOSICMDI)                                    //~va6cR~
        opt|=UCVEBC3O_SOSIINS|UCVEBC3O_SOSICMDO;  //force insert   //~va6cR~
    else                                                           //~va6cI~
    if (Popt & XEEBCO_SOSICMDR)                                    //~va6cR~
        opt|=UCVEBC3O_SOSIREP|UCVEBC3O_SOSICMDO;  //force rep(replace boundary space)//~va6cR~
    if (Popt & XEEBCO_SETF2LERR)                                   //~va7uI~
        opt|=UCVEBC3O_SETF2LERR;                                   //~va7uI~
	if (Popt & XEEBCO_DD2B) //dd fmt to ebc                         //~0424R~//~0503R~
    {
        pdata=Pdata;                                               //~0423I~
        pdbcs=Pdbcs;                                               //~0423I~
        mblen=Plen;                                                //~0423I~
    	ebclen=mblen*2;
    	buffsz=ebclen*2;
    	pbuff=xeutf_buffget(XEUTF_BUFEBC,buffsz);
		UALLOCCHK(pbuff,UALLOC_FAILED);                            //~va7sI~
    	poutdata=pbuff;
    	poutdbcs=poutdata+ebclen;
//  	rc=ucvebc3_dd2b(opt,pdata,pdbcs,mblen,poutdata,poutdbcs,ebclen,&outlen);//~0423R~//~va5XR~//~va79R~
    	rc=ucvebc3_dd2b(opt,Phandle,pdata,pdbcs,mblen,poutdata,poutdbcs,ebclen,&outlen);//~va79I~
    }
    else	//locale to ebc                                        //~0423R~
    {
    	if (Popt & XEEBCO_BIN)                                     //~va60I~
        	opt|=UCVEBC3O_BIN;                                     //~va60I~
        pdata=Pdata;
        mblen=Plen;
    	ebclen=mblen*2;
    	buffsz=ebclen*2;
        if (!Pdbcs)
        	buffsz+=mblen;
    	pbuff=xeutf_buffget(XEUTF_BUFEBC,buffsz);
		UALLOCCHK(pbuff,UALLOC_FAILED);                            //~va7sI~
        if (!Pdbcs)
        {
        	pdbcs=pbuff,poutdata=pbuff+mblen;
    	  if (!(Popt & XEEBCO_BIN))                                //~va60I~
			filesetdbcstbl(pdata,pdbcs,mblen,0/*opt*/);
        }
        else
        {                                                          //~0424I~
        	pdbcs=Pdbcs,poutdata=pbuff;
	        if (Popt & XEEBCO_INITDBCST)                           //~0424I~
    	      if (!(Popt & XEEBCO_BIN))                            //~va60I~
				filesetdbcstbl(pdata,pdbcs,mblen,0/*opt*/);        //~0424I~
        }                                                          //~0424I~
    	poutdbcs=poutdata+ebclen;                                  //~0423R~
//  	rc=ucvebc3_m2b(opt,pdata,pdbcs,mblen,poutdata,poutdbcs,ebclen,&outlen);//~0423R~//~va5XR~//~va79R~
    	rc=ucvebc3_m2b(opt,Phandle,pdata,pdbcs,mblen,poutdata,poutdbcs,ebclen,&outlen);//~va79I~
    }
    *Ppoutdata=poutdata;
    if (Ppoutdbcs)                                                 //~0425I~
	    *Ppoutdbcs=poutdbcs;                                       //~0425R~
    *Ppoutlen=outlen;
    UTRACED("xeutf_m2b out data",poutdata,outlen);
    UTRACED("xeutf_m2b out dbcs",poutdbcs,outlen);
    UTRACEP("xeutf_m2b rc=%d\n",rc);                               //~0423I~
    return rc;                                                     //~0423R~
}//xeebc_m2bsetdbcs
#ifdef AAA                                                         //~va6mI~
//*******************************************************
//*ebc-->locale code
//rc:1:dbcs data detected
//*******************************************************
int xeebc_b2mtab(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)
{
	int rc=0,opt=0,outlen,dbcsid,repch=XEUTF_ERRREPCH_F2LFILE,reslen,resleno,ch,cvlen,cvsw;
    UCHAR *pco,*pc,*pcd,*pcv,*pcvd;
    int swdbcsenv;                                                 //~va5XI~
//*****************
    UTRACED("xeutf_b2mtab inp data",Pdata,Plen);
    UTRACED("xeutf_b2mtab inp dbcs",Pdbcs,Plen);
	swdbcsenv=UDBCSCHK_ISDBCSCV();                                 //~v66mI~//~va5XI~
    if (Popt & XEEBCO_BIN)
    	opt|=UCVEBC3O_BIN;
	pcv=Pdata;
	for(pc=Pdata,pcd=Pdbcs,reslen=Plen,pco=Poutbuff,resleno=Pbuffsz;reslen>=0;reslen--,pc++,pcd++)
    {
    	if (reslen)
        {
    		ch=*pc;
    		dbcsid=*pcd;
        }
        else
        {
        	ch=0;
            dbcsid=0;
        }
        cvsw=0;
#ifdef AAA //no tab consideration
        if (dbcsid==TABCHAR || dbcsid==TABPADCHAR)
        	cvsw=1;
        else
#endif //AAA
		if (swdbcsenv && (ch==CHAR_SO||ch==CHAR_SI))               //~va5XR~
        	cvsw=2;
        else
        if (!reslen)
        	cvsw=3;
        if (cvsw)
        {
            outlen=0;
        	if (pcv && (cvlen=(ULONG)pc-(ULONG)pcv)>0)
            {
            	pcvd=UTF_PC2PCD(Pdbcs,pcv,Pdata);
		        ucvebc3_b2m(opt,pcv,pcvd,cvlen,pco,resleno,repch,&outlen);
            }
            pco+=outlen;
            resleno-=outlen;
            if (resleno<=0)
            {
            	rc=8;
                break;
            }
#ifdef AAA //no tab consideration
            if (cvsw==1)    //TAB
            {
        		*pco++=ch;
                resleno--;
            }
            else
#endif //AAA
            if (cvsw==2)    //SOSI
            {
        		*pco++=ch;
    	        *pcd=UDBCSCHK_F2LERR;
                resleno--;
            }
            pcv=0;
        	continue;
        }
        if (!pcv)
        	pcv=pc;
    }
    outlen=(ULONG)pco-(ULONG)Poutbuff;
    if (Ppoutlen)
        *Ppoutlen=outlen;
    UTRACED("xeutf_b2mtab out mbstr",Poutbuff,outlen);
    UTRACED("xeutf_b2mtab out dbcs",Pdbcs,outlen);
    return rc;
}//xeebc_b2mtab
#endif                                                             //~va6mI~
//*******************************************************
//*ebc-->locale code for screen display only(dd fmt is not valid by F2LERR setting)//~va7tR~
//*******************************************************
//int xeebc_b2ddtab(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,char *Poutbuff,char *Poutdbcs,int Pbuffsz,int *Ppoutlen)//~va79R~
int xeebc_b2ddtab(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,char *Poutbuff,char *Poutdbcs,int Pbuffsz,int *Ppoutlen)//~va79I~
{
	int rc=0,opt=0,rc2,outlen,dbcsid,reslen,resleno,ch;
    UCHAR *pco,*pc,*pcd,*pcdo;
    int swdbcsenv;                                                 //~va5XI~
//*****************
//  swdbcsenv=UDBCSCHK_ISDBCSCV();                                 //~va5XI~//~va79R~
    swdbcsenv=UCVEBCH_HANDLE_ISDBCSCV(Phandle);                    //~va79I~
    UTRACEP("%s:swdbcsenv=%d,handle=%d\n",UTT,swdbcsenv,Phandle);  //~vbBcR~
    UTRACED("xeutf_b2ddtab inp data",Pdata,Plen);
    UTRACED("xeutf_b2ddtab inp dbcs",Pdbcs,Plen);
    if (Popt & XEEBCO_BIN)
    	opt|=UCVEBC3O_BIN;
    int optsbcs=opt|UCVEBC3O_CVCTL;                                //~vbBjI~
	for(pc=Pdata,pcd=Pdbcs,reslen=Plen,pco=Poutbuff,pcdo=Poutdbcs,resleno=Pbuffsz;
			reslen>=0;
			reslen--,pc++,pcd++,pco++,pcdo++)
    {
        ch=*pc;
    	dbcsid=*pcd;
//		if (ch==CHAR_SO||ch==CHAR_SI)                              //~va5XR~
  		if (swdbcsenv && (ch==CHAR_SO||ch==CHAR_SI))               //~va5XI~
        {
//      	*pco=ch;                                               //~vb2CR~
        	*pco=(UCHAR)ch;                                        //~vb2CI~
        	*pcdo=UDBCSCHK_F2LERR;  //display by "?"               //~0508R~
            continue;
        }
  		if (dbcsid==UDBCSCHK_F2LERR     //'f'                      //+vbBqR~
        &&  ch==CHAR_EBC_SUB)                                      //~vbBqI~
        {                                                          //~vbBqI~
        	*pco=(UCHAR)CHAR_UCS_SUB;   //x1a                      //~vbBqI~
        	*pcdo=DISPLINEATTRID;		//'l'     //display by lineno field attr,USDdbcs only//~vbBqI~
            continue;                                              //~vbBqI~
        }                                                          //~vbBqI~
        switch(dbcsid)
        {
		case 0:		//SBCS
//          rc2=ucvebc3_b2ddSbcs1(opt,pc,0/*repch*/,pco,pcdo,0/*out ucs*/,0/*outlen*/);//~0425R~//~0428R~//~va79R~
//          rc2=ucvebc3_b2ddSbcs1(opt,Phandle,pc,0/*repch*/,pco,pcdo,0/*out ucs*/,0/*outlen*/);//~va79I~//~vbBjR~
            rc2=ucvebc3_b2ddSbcs1(optsbcs,Phandle,pc,0/*repch*/,pco,pcdo,0/*out ucs*/,0/*outlen*/);//~vbBjI~
//          if (rc2)	//errrep                                   //~vbBkR~
//          if (rc2 && !(rc2 & UCVE3B2DDS1RC_SUBCHAR))     // 0x100:set subcharsbcs//~vbBkI~//~vbBnR~
            if (rc2)	//errrep                                   //~vbBnI~
            {
              if ((rc2 & UCVE3B2DDS1RC_SUBCHAR) && !*pcdo)     // 0x100:set subcharsbcs and ascii//~vbBnI~
              {                                                    //~vbBnI~
        		*pcdo=DISPLINEATTRID;		//'l'     //display by lineno field attr,USDdbcs only//~vbBnR~
                UTRACEP("%s:set ascii subchar *pc=%02x, set green sbcs\n",UTT,*pco);//~vbBnR~//~vbBmR~
              }                                                    //~vbBnI~
              else                                                 //~vbBnI~
              {                                                    //~vbBnI~
//	        	*pco=ch;                                           //~vb2CR~
	        	*pco=(UCHAR)ch;                                    //~vb2CI~
        		*pcdo=UDBCSCHK_HKDBCSERR; //display by unprintable char//~0508R~
              }                                                    //~vbBnI~
            }
        	break;
        case UDBCSCHK_DBCS1ST:
            *(pco+1)=' ';                                          //~vbBmR~
            *(pcdo+1)=0;                                           //~vbBmI~
//          rc2=ucvebc3_b2ddDbcs1(opt,pc,0/*repch*/,pco,pcdo,0/*out ucs*/,0/*outlen*/);//~0425R~//~0428R~//~va79R~
//          rc2=ucvebc3_b2ddDbcs1(opt,Phandle,pc,0/*repch*/,pco,pcdo,0/*out ucs*/,0/*outlen*/);//~va79I~//~vb2BR~
            rc2=ucvebc3_b2ddDbcs1(opt,Phandle,pc,0/*repch*/,pco,pcdo,0/*outlen*/);//~vb2BI~
        	pc++;
        	pcd++;
            reslen--;
//          if (rc2)	//errrep                                   //~vbBkR~
            if (rc2 && !(rc2 & UCVE3B2DDD1RC_SUBCHAR))     // 0x100:set subchardbcs//~vbBkI~
            {
#ifdef AAA
	        	*pco++=ch;
	        	*pco=*pc;
        		*pcdo++=UDBCSCHK_NPUCS1;
        		*pcdo=UDBCSCHK_NPUCS2;
#else
	        	*pco++=XEUTF_ERRREPCH_NPUCS;
	        	*pco=XEUTF_ERRREPCH_NPUCSW;
				*pcdo++=DISPLINEATTRID;//display as sbcs
				*pcdo=DISPLINEATTRID;//display as sbcs
#endif
            }
            else
            {
	            pco++;
    	        pcdo++;
            }
            resleno--;
        	break;
        default:	//TAB,TABPAD,HKDBCSERR,F2LERR
//      	*pco=ch;                                               //~vb2CR~
        	*pco=(UCHAR)ch;                                        //~vb2CI~
//      	*pcdo=dbcsid;                                          //~vb2CR~
        	*pcdo=(UCHAR)dbcsid;                                   //~vb2CI~
        }
    }
//  outlen=(ULONG)pco-(ULONG)Poutbuff;                             //~vafkR~
//  outlen=(ULPTR)pco-(ULPTR)Poutbuff;                             //~vafkI~//~vb2DR~
    outlen=PTRDIFF(pco,Poutbuff);                                  //~vb2DI~
    if (Ppoutlen)
        *Ppoutlen=outlen;
    UTRACED("xeutf_b2ddtab out mbstr",Poutbuff,outlen);            //~va62R~
    UTRACED("xeutf_b2ddtab out dbcs",Poutdbcs,outlen);             //~va62R~
    return rc;
}//xeebc_b2ddtab
//*******************************************************
//*ebc<--locale code
//enuff outbuffsz should be prepared for SO/SI insertion by caller
//*******************************************************
int xeebc_b2mgetiblen(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int *Ppoffs,int *Pplen)
{
	int offs=0,len,pos,splitsw=0,dbcsid;
//*****************
    dbcsid=*Pdbcs;
    if (UDBCSCHK_DBCSNOT1ST(dbcsid))
    {
    	splitsw=1;
    	offs=XESUB_DBCSSPLITCTR_R(Pdbcs,Plen);
		if (offs && XEEBC_ISDDFMTPSD())
        	memset(Pdbcs,UDBCSCHK_HKDBCSERR,(UINT)offs);
    }
    dbcsid=*(Pdbcs+Plen-1);
    if (UDBCSCHK_DBCSNOTEND(dbcsid))
    {
    	pos=Plen-XESUB_DBCSSPLITCTR_L(Pdbcs,Plen);
    	splitsw=1;
		if (pos<Plen && XEEBC_ISDDFMTPSD())
        	memset(Pdbcs+pos,UDBCSCHK_HKDBCSERR,(UINT)(Plen-pos));
    }
    else
    	pos=Plen;
    len=pos-offs;
    *Ppoffs=offs;
    *Pplen=len;
    UTRACEP("xeutf_m2b getiblen ilen=%d,offs=%d,len=%d\n",Plen,offs,len);
    return splitsw;
}//xeebc_b2mgetiblen
//****************************************************************
//xeebc_b2mdbcschk
//*to keep display column,set err for dbcs1st byte by locale code for SBCD in ebcdic
//rc:4:nodbcs env,1:set hkdbcserr
//****************************************************************
int xeebc_b2mdbcschk(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)
{
	int reslen,rc=0;
	UCHAR *pc,*pcd,*pcde;
//*****************
UTRACED("xeebc_b2mdbcschk in data",Pdata,Plen);
UTRACED("xeebc_b2mdbcschk in dbcs",Pdbcs,Plen);
	if (!XE_ISDBCSKON())
    	return 4;
	pcd=Pdbcs;
    pcde=pcd+Plen;
	for (;;)
	{
//      reslen=(ULONG)pcde-(ULONG)pcd;                             //~vafkR~
//      reslen=(ULPTR)pcde-(ULPTR)pcd;                             //~vafkI~//~vb2DR~
        reslen=PTRDIFF(pcde,pcd);                                  //~vb2DI~
		if (!(pcd=memchr(pcd,0,(UINT)reslen)))
        	break;
        for (pc=UTF_PCD2PC(Pdata,pcd,Pdbcs);pcd<pcde && !*pcd;pc++,pcd++)
        {
            if (UDBCSCHK_ISDBCS1ST(*pc))
            {
            	*pcd=UDBCSCHK_HKDBCSERR;
                rc=1;
            }
        }
    }
UTRACED("xeebc_b2mdbcschk out",Pdbcs,Plen);
	return rc;
}//xeebc_b2mdbcschk
//****************************************************************
//xeebc_b2mpsd
//*translate psd data/dbcs(dd fmt) from ebc to mb                  //~0429R~
//TAB 0x09 data is not tab, fldedit tab insert set space and dbcstbl as usual
//*parm1:psd data
//*parm2:psd dbcs
//*parm3:len
//*rc   :1:tab replaced
//****************************************************************
int xeebc_b2mpsd(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Pbinsw)
{
	int rc=0,opt,offs,iblen;
	UCHAR *pc,*pcd;
    UCHAR mbdata[MAXCOLUMN];	//for psd
    UCHAR mbdbcs[MAXCOLUMN];	//for psd
    int handle;                                                    //~va79I~
//*****************
UTRACED("xeebc_b2mpsd inp data",Pdata,Plen);
UTRACED("xeebc_b2mpsd inp dbcs",Pdbcs,Plen);
	xeebc_b2mgetiblen(0,Pdata,Pdbcs,Plen,&offs,&iblen);
	pc=Pdata+offs;
	pcd=Pdbcs+offs;
    opt=0;
    if (Pbinsw & FILETDO_BINSWMASK)
    	opt|=XEEBCO_BIN;
#ifdef AAA                                                         //~va6mI~
	if (XEEBC_ISDDFMTPSD())
#endif                                                             //~va6mI~
    {
    	handle=UGETPFH(Pplh)->UFHhandle;                           //~va79I~
//  	xeebc_b2ddtab(opt,pc,pcd,iblen,mbdata,mbdbcs,sizeof(mbdata),0/*outlen*/);//~va79R~
    	xeebc_b2ddtab(opt,handle,pc,pcd,iblen,mbdata,mbdbcs,sizeof(mbdata),0/*outlen*/);//~va79I~
//      memcpy(pc,mbdata,iblen);                                   //~vb2DR~
        memcpy(pc,mbdata,(size_t)iblen);                           //~vb2DI~
//      memcpy(pcd,mbdbcs,iblen);                                  //~vb2DR~
        memcpy(pcd,mbdbcs,(size_t)iblen);                          //~vb2DI~
    }
#ifdef AAA                                                         //~va6mI~
    else
    {
		xeebc_b2mtab(opt,pc,pcd,iblen,mbdata,sizeof(mbdata),0/*outlen*/);
	    memcpy(pc,mbdata,iblen);
		xeebc_b2mdbcschk(opt,pc,pcd,iblen);
    }
#endif                                                             //~va6mI~
UTRACED("xeebc_b2mpsd out data",Pdata,Plen);
UTRACED("xeebc_b2mpsd out dbcs",Pdbcs,Plen);
	return rc;
}//xeebc_b2mpsd                                                    //~0507R~
//****************************************************************
//xeebc_b2msetdbcs
//*translate ebc->local/dd                                         //~va50R~
//* input dbcstbl contains dbcsid                                  //~0508I~
//*!!caller should set &outdbcs=0 if request malloc              //~va6wI~//~va7tR~//~va7TR~
//*  called from toplinecid,copy (l)cmd                            //~va50I~
//rc:UALLOC_FAILED
//****************************************************************
//int xeebc_b2msetdbcs(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen)//~0425R~//~va79R~
int xeebc_b2msetdbcs(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen)//~va79I~
{
	int rc,opt,buffsz,outlen,swb2f,pdatasz;                        //~0426R~
	UCHAR *pdbcs,*poutdata,*poutdbcs,*pbuff;
//*****************
	UTRACEP("%s:opt=%04x,handle=%d\n",UTT,Popt,Phandle);           //~vbBjI~
    swb2f=Popt & XEEBCO_B2F;                                       //~0425I~
	buffsz=0;
//  if (!(pdbcs=Pdbcs)) //avoid Pdbcs updated                      //~0508R~
    	buffsz+=Plen;
	if (swb2f)                                                     //~0426R~
        buffsz+=(pdatasz=Plen*UTF8_MAXCHARSZ);                     //~0426R~
    else                                                           //~0426R~
    {                                                              //~va62I~
//    	buffsz+=(pdatasz=Plen);                                    //~va6wR~
      	buffsz+=(pdatasz=Plen*4);   //pdatasz is parm to b2m       //~va6wI~
//      buffsz+=Plen;     //out data double for S2D expansion      //~va63R~
//      buffsz+=Plen*3;   //out data double for S2D expansion by GB4//~va6wR~
    }                                                              //~va62I~
    if (!swb2f)                                                //~0425I~//~0505I~
    	if (!Ppoutdbcs || !(poutdbcs=*Ppoutdbcs))                  //~0505R~
    	{                                                              //~0425I~//~0505R~
//  		buffsz+=Plen;                                          //~va63R~
//      	buffsz+=Plen;     //out dbcs double for S2D expansion  //~va63R~
        	buffsz+=Plen*4;   //out dbcs double for S2D expansion  //~va63I~
    	}                                                              //~0425I~//~0505R~
    buffsz+=4;  //alloc buff even when ULHlen=0                    //~vafbI~
//  if (buffsz)                                                    //~vaf8R~//~vafbR~
//  {                                                              //~vaa7I~//~vafbR~
//      pbuff=xeutf_buffget(XEUTF_BUFEBC,buffsz);                  //~va7tR~
        pbuff=xeutf_buffget(XEUTF_BUFEBC2,buffsz);                 //~va7tI~
        if (!pbuff)                                                //~vaa7I~
            return UALLOC_FAILED;                                  //~vaa7I~
//  }                                                              //~vaa7I~//~vafbR~
//  if (!pdbcs)                                                    //~0508R~
        pdbcs=pbuff,pbuff+=Plen;
    poutdata=pbuff;                                                //~0426R~
    *Ppoutdata=poutdata;                                           //~0426R~
    if (swb2f)                                                     //~0426R~
        pbuff+=Plen*UTF8_MAXCHARSZ;                                //~0426R~
    else                                                           //~0426R~
    {                                                              //~va62I~
//      pbuff+=Plen;                                               //~va63R~
//      pbuff+=Plen;                                               //~va63R~
        pbuff+=Plen*4;                                             //~va63I~
    }                                                              //~va62I~
    poutdbcs=0;                                                    //~0425I~//~0505M~
    if (swb2f)                                                     //~0505R~
    {                                                              //~0505I~
    	if (Popt & XEEBCO_CHKDBCSTB)                               //~0505I~
		    poutdbcs=*Ppoutdbcs;                                   //~0505I~
    }                                                              //~0505I~
    else                                                           //~0505I~
    	if (!Ppoutdbcs || !(poutdbcs=*Ppoutdbcs))                  //~0505I~
    	{                                                          //~0505R~
       		poutdbcs=pbuff;                                        //~0425R~
            if (Ppoutdbcs)                                         //~0505R~
	        	*Ppoutdbcs=poutdbcs;                                   //~0425R~//~0505R~
    	}                                                          //~0505R~
    opt=0;
    if (Popt & XEEBCO_SOSI2SPACE)                                  //~0423I~
        opt|=UCVEBC3O_SOSI2SPACE;                                  //~0423I~
    if (Popt & XEEBCO_ERRREP)                                      //~0426R~
        opt|=UCVEBC3O_ERRREP;                                      //~0426R~
    if (Popt & XEEBCO_ERRREP2)                                     //~va80I~
        opt|=UCVEBC3O_ERRREP2;                                     //~va80I~
    if (Popt & XEEBCO_ERRREP3)                                     //~vag6I~
        opt|=UCVEBC3O_ERRREP3;  //leave subchar                    //~vag6I~
    if (Popt & XEEBCO_SOSIREP)                                     //~0501R~
        opt|=UCVEBC3O_SOSIREP;                                     //~0501I~
    if (Popt & XEEBCO_SOSIREPQ)                                    //~0501I~
        opt|=UCVEBC3O_SOSIREPQ;                                    //~0501I~
    if (Popt & XEEBCO_SOSIREPQP)                                   //~va5LI~
        opt|=UCVEBC3O_SOSIREPQP;                                   //~va5LI~
    if (Popt & XEEBCO_B2F)                                         //~0425I~
    {                                                              //~va7yI~
        opt|=UCVEBC3O_B2F;                                         //~0425I~
	    if (Popt & XEEBCO_CHKDBCSTB)                               //~va7yI~
    	    opt|=UCVEBC3O_CHKDBCSTB;                               //~va7yI~
    }                                                              //~va7yI~
    if (Popt & XEEBCO_BIN)                                         //~0428I~
        opt|=UCVEBC3O_BIN;                                         //~0428I~
//  if (Popt & XEEBCO_CHKDBCSTB)                                   //~0505I~//~va7yR~
//      opt|=UCVEBC3O_CHKDBCSTB;                                   //~0505I~//~va7yR~
    if (Popt & XEEBCO_SETF2LERR)                                   //~0508I~
        opt|=UCVEBC3O_SETF2LERR;                                   //~0508I~
    if (Popt & XEEBCO_DROPSOSI)                                    //~va5AI~
//      opt|=UCVEBC3O_DROPSOSI;                                    //~va6mR~
        opt|=UCVEBC3O_DROPSOSI|UCVEBC3O_SOSICMDO;//cmdo required for ucvebc3//~va6mI~
    if (Popt & XEEBCO_CVCTL)                                       //~va5XI~
        opt|=UCVEBC3O_CVCTL;                                       //~va5XI~
    if (Popt & XEEBCO_DBCSUCSOK)                                   //~va7tR~
        opt|=UCVEBC3O_DBCSUCSOK;                                   //~va7tI~
    if (Popt & (XEEBCO_SOSICMDR|XEEBCO_SOSICMDD))    //cmd optio specified//~va6cI~
    {                                                              //~va6cI~
        opt&=~(UCVEBC3O_SOSI2SPACE|UCVEBC3O_SOSIREP|UCVEBC3O_SOSIREPQ|UCVEBC3O_SOSIREPQP|UCVEBC3O_DROPSOSI);//~va6cI~
        opt|=UCVEBC3O_SOSICMDO;                                    //~va6cI~
    	if (Popt & XEEBCO_SOSICMDR)                                //~va6cI~
	        opt|=UCVEBC3O_SOSI2SPACE;                              //~va6cI~
        else                                                       //~va6cI~
	        opt|=UCVEBC3O_DROPSOSI;                                //~va6cI~
    }                                                              //~va6cI~
    if (Popt & (XEEBCO_B2DD|XEEBCO_B2F))                           //~0425R~
    {                                                              //~0501I~
    	if (Popt & XEEBCO_DBCSUCSOK)                               //~va7vI~
	        opt|=UCVEBC3O_DBCSUCSOK;                               //~va7vI~
//  	rc=ucvebc3_b2dd(opt,Pdata,Plen,poutdata,poutdbcs,pdatasz,&outlen);//~0426R~//~va79R~
    	rc=ucvebc3_b2dd(opt,Phandle,Pdata,Plen,poutdata,poutdbcs,pdatasz,&outlen);//~va79I~
    }                                                              //~0501I~
    else
    {                                                              //~va50I~
	    if (!Pdbcs)                                                //~va50I~
//  		xeebc_setdbcstbl(Popt,Pdata,pdbcs,Plen);//chk so/si    //~va50I~//~va79R~
    		xeebc_setdbcstbl(Popt,Phandle,Pdata,pdbcs,Plen);//chk so/si//~va79I~
    	else                                                       //~va50I~
//  		pdbcs=Pdbcs;                                           //~0508I~
        	memcpy(pdbcs,Pdbcs,(UINT)Plen); //input to ucvebc3_b2m //~0508I~
//  	rc=ucvebc3_b2m(opt,Pdata,pdbcs,Plen,poutdata,pdatasz,0/*repch*/,&outlen);//~va6mR~
// 		rc=ucvebc3_b2m(opt,Pdata,pdbcs,Plen,poutdata,poutdbcs,pdatasz,0/*repch*/,&outlen);//~va6mR~//~va79R~
   		rc=ucvebc3_b2m(opt,Phandle,Pdata,pdbcs,Plen,poutdata,poutdbcs,pdatasz,0/*repch*/,&outlen);//~va79I~
//      if (poutdbcs)                                              //~va6mR~
//      	memcpy(poutdbcs,pdbcs,outlen);                         //~va6mR~
    }                                                              //~va50I~
    if (Ppoutlen)                                                  //~0425I~
    	*Ppoutlen=outlen;                                          //~0425I~
UTRACED("xeebc_b2msetdbcs inp data",Pdata,Plen);                   //~0423R~
UTRACED("xeebc_b2msetdbcs inp dbcs",pdbcs,Plen);                   //~0423R~
UTRACED("xeebc_b2msetdbcs out data",poutdata,outlen);              //~va6wR~
UTRACEDIFNZ("xeebc_b2mpsetdbcs out dbcs",poutdbcs,outlen);              //~va6wR~//~va7TR~
	return rc;
}//xeebc_b2msetdbcs
//**************************************************************** //~va7tI~
//xeebc_b2b                                                        //~va7tI~
//rc:UALLOC_FAILED,rc of xeebc_m2bsetdbcs                                        //~va7tI~//~va7yR~
//**************************************************************** //~va7tI~
int xeebc_b2b(int Popt,int Poldhandle,int Pnewhandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen)//~va7tR~
{                                                                  //~va7tI~
	int rc,opt,ddlen,ebclen;                                       //~va7tR~
    int rc2;                                                       //~vag8I~
	UCHAR *pdddata,*pdddbcs,*pebcdata,*pebcdbcs;                   //~va7tR~
//**********************                                           //~va7tI~
UTRACEP("xeebc_b2b handle=%d->%d len=%d\n",Poldhandle,Pnewhandle,Plen);//~va7tR~
UTRACED("xeebc_b2b inp data",Pdata,Plen);                          //~va7tI~
UTRACED("xeebc_b2b inp dbcs",Pdbcs,Plen);                          //~va7tI~
                                                                   //~va7tI~
	opt=Popt;                                                      //~va7tR~
    opt|=XEEBCO_B2DD;                                              //~va7tR~
    opt|=XEEBCO_DBCSUCSOK;  //accept ucs defined as dbcs(ucs width=2 depends env)//~va7tI~
    opt&=~XEEBCO_SETF2LERR; //dont set to dd fmt                   //~va7uI~
    if (UCVEBCH_HANDLE_ISDBCSCV(Poldhandle)                       //~v69uR~//~va7yI~
    &&  UCVEBCH_HANDLE_ISDBCSCV(Pnewhandle)                        //~v69uR~//~va7yI~
    )                                                              //~va7yI~
    	opt|=XEEBCO_DROPSOSI;                                      //~va7yI~
    pdddbcs=0;                                                     //~va7tI~
  rc2=                                                             //~vag8I~
	rc=xeebc_b2msetdbcs(opt,Poldhandle,Pdata,Pdbcs,Plen,&pdddata,&pdddbcs,&ddlen);//~va7tI~
    UALLOCCHKRC(rc);                                               //~va7tI~
	opt=Popt;                                                      //~va7tR~
	opt|=XEEBCO_DD2B;                                              //~va7tR~
	rc=xeebc_m2bsetdbcs(opt,Pnewhandle,pdddata,pdddbcs,ddlen,&pebcdata,&pebcdbcs,&ebclen);//~va7tR~
    UALLOCCHKRC(rc);                                               //~va7tI~
  	rc|=rc2;                                                       //~vag8I~
    *Ppoutdata=pebcdata;                                           //~va7tR~
    if (Ppoutdbcs)                                                 //~va7tI~
    	*Ppoutdbcs=pebcdbcs;                                       //~va7tR~
    *Ppoutlen=ebclen;                                              //~va7tI~
UTRACEP("xeebc_b2b rc=%d,outlen=%d\n",rc,ebclen);                  //~va7tR~
UTRACED("xeebc_b2b out data",pebcdata,ebclen);                     //~va7tR~
UTRACED("xeebc_b2b out dbcs",pebcdbcs,ebclen);                     //~va7tR~
    return rc;                                                     //~va7tI~
}//xeebc_b2b                                                       //~va7tI~
//**************************************************************** //~0503I~
//xeebc_b2fl                                                       //~0503I~
//*translate ebc->utf8 and locale                                  //~0503I~
//rc:UALLOC_FAILED,1:f2l trans err,4:other err                                                 //~0503I~//~va5AR~
//**************************************************************** //~0503I~
//int xeebc_b2fl(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutu8,int Pu8buffsz,int *Ppu8len,//~0503I~//~va79R~
int xeebc_b2fl(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR *Poutu8,int Pu8buffsz,int *Ppu8len,//~va79I~
				UCHAR *Poutlc,UCHAR *Poutdbcs,UCHAR *Poutct,int Plcbuffsz,int *Pplclen)//~0503I~
{                                                                  //~0503I~
	int rc,opt,len,lclen,u8len;                                    //~0503R~
	UCHAR *pdbcs,*pu8;                                             //~0503R~
//*****************                                                //~0503I~
	opt=Popt|XEEBCO_B2F;	//ebcdic->utf8                         //~0503I~
    pdbcs=0;                                                       //~0503I~
//  rc=xeebc_b2msetdbcs(opt,Pdata,Pdbcs,Plen,&pu8,&pdbcs,&u8len);  //~0503I~//~va79R~
    rc=xeebc_b2msetdbcs(opt,Phandle,Pdata,Pdbcs,Plen,&pu8,&pdbcs,&u8len);//~va79I~
    if (rc==UALLOC_FAILED)                                         //~0503I~
    	return rc;                                                 //~0503I~
//  len=min(u8len,Pu8buffsz);                                      //~0503I~//~vagBR~
    if (u8len>=Pu8buffsz)                                          //~vagBI~
    {                                                              //~vagBI~
    	opt=0;                                                     //~vagBI~
		len=utfgetutf8strlen(opt,pu8,Pu8buffsz-1/*for last null*/,0/*out chrcnt*/);//~vagBI~
    }                                                              //~vagBI~
    else                                                           //~vagBI~
        len=u8len;                                                 //~vagBI~
    *Ppu8len=len;                                                  //~0503I~
//  UmemcpyZ(Poutu8,pu8,len);                                      //~0503R~//~vb2DR~
    UmemcpyZ(Poutu8,pu8,(size_t)len);                              //~vb2DI~
    opt=XEUTFF2LCO_ERRREP;                                         //~0503I~
//  rc=xeutfcvf2lc(opt,pu8,u8len,Poutlc,Poutct,Plcbuffsz,&lclen,0/*chklen*/);//~0503I~//~va5AR~//~vagBR~
    rc=xeutfcvf2lc(opt,pu8,len,Poutlc,Poutct,Plcbuffsz,&lclen,0/*chklen*/);//~vagBI~
//  if (rc==XEUTFF2LCRC_UTF8ERR)     //2:cverr,1:utf8 code detected//~va5AR~//~va7pR~
    if (rc & XEUTFF2LCRC_UTF8ERR)     //2:cverr,1:utf8 code detected, if cverr 3 is returned//~va7pI~
    	rc=1;                                                      //~va5AI~
    else                                                           //~va5AI~
    if (rc>=XEUTFF2LCRC_ERR)                                       //~va5AR~
    	rc=4;                                                      //~va5AI~
    else                                                           //~va5AI~
        rc=0;       //1:utf8 detected                              //~va5AI~
    setdbcstbl(Poutlc,Poutdbcs,lclen);                             //~va5AI~
    *Pplclen=lclen;                                                //~0503I~
UTRACED("xeebc_b2fl inp data",Pdata,Plen);                         //~0503I~
UTRACED("xeebc_b2fl inp dbcs",Pdbcs,Plen);                         //~0503I~
UTRACED("xeebc_b2fl out u8",Poutu8,u8len);                         //~0503I~
UTRACED("xeebc_b2fl out lc",Poutlc,lclen);                         //~0503I~
UTRACED("xeebc_b2fl out dbcs",pdbcs,Plen);                         //~0503I~
	return rc;                                                     //~0503I~
}//xeebc_b2fl                                                      //~va5AR~
//**************************************************************** //~vaacI~
//xeebc_b2f                                                        //~vaacI~
//*translate ebc->utf8                                             //~vaacI~
//rc:UALLOC_FAILED,4:other err                                     //~vaacI~
//**************************************************************** //~vaacI~
int xeebc_b2f(int Popt,int Pebcopt,int Phandle,UCHAR *Pdata,int Plen,UCHAR **Ppoutu8,int *Ppu8len)//~vaacR~
{                                                                  //~vaacI~
	int rc,opt,buffsz,u8len;                                       //~vaacR~
	UCHAR *poutdata,*pbuff,*poutdbcs;                              //~vaacR~
//*****************                                                //~vaacI~
	UTRACEP("%s:Popt=%04x,Pebcopt=0x%08x,handle=%d\n",UTT,Popt,Pebcopt,Phandle);//~vbBjI~
    buffsz=Plen*UTF8_MAXCHARSZ;                                    //~vaacI~
    pbuff=xeutf_buffget(XEUTF_BUFEBC2,buffsz);                     //~vaacI~
    if (!pbuff)                                                    //~vaacI~
    	return UALLOC_FAILED;                                      //~vaacI~
    poutdata=pbuff;                                                //~vaacI~
    poutdbcs=0;                                                    //~vaacR~
    opt=0;                                                         //~vaacR~
    if (Popt & XEEBCO_BIN)                                         //~vaacR~
        opt|=UCVEBC3O_BIN;                                         //~vaacR~
    rc=ucvebc3_b2f(opt,Pebcopt,Phandle,Pdata,Plen,poutdata,poutdbcs,buffsz,&u8len);//~vaacR~
//    opt=Pebcopt|EBC2ASC_EXT_TOUTF8;                              //~vaacR~
//    rc=ucvext_icuebc2mbs_handle(opt,Phandle,Pdata,0/*dbcs*/,Plen,poutdata,&u8len,0/*Perrrep*/);//~v69pI~//~vaacR~
    *Ppoutu8=poutdata;                                             //~vaacR~
    if (Ppu8len)                                                   //~vaacR~
        *Ppu8len=u8len;                                            //~vaacR~
UTRACED("xeebc_b2f inp data",Pdata,Plen);                          //~vaacI~
UTRACED("xeebc_b2fl out u8",poutdata,u8len);                       //~vaacR~
	return rc;                                                     //~vaacI~
}//xeebc_b2f                                                       //~vaacI~
//**************************************************************** //~vaacI~
//xeebc_f2b                                                        //~vaacI~
//*translate ebc<-utf8                                             //~vaacI~
//rc:UALLOC_FAILED,4:other err                                     //~vaacI~
//**************************************************************** //~vaacI~
int xeebc_f2b(int Popt,int Pebcopt,int Phandle,UCHAR *Pdata,int Plen,UCHAR **Ppoutebc,int *Ppebclen)//~vaacI~
{                                                                  //~vaacI~
	int rc,opt,outlen,ebclen,buffsz,mblen;                         //~vaacR~
//	UCHAR *pdata,*pdbcs,*poutdata,*poutdbcs,*pbuff;                //~vak5R~
  	UCHAR               *poutdata,*poutdbcs,*pbuff;                //~vak5I~
//*****************                                                //~vaacI~
//  pdbcs=0;                                                       //~vak5R~
//  pdata=Pdata                                                    //~vak5R~
    mblen=Plen;                                                    //~vaacI~
    ebclen=mblen*2;                                                //~vaacI~
    buffsz=ebclen*2;                                               //~vaacI~
    pbuff=xeutf_buffget(XEUTF_BUFEBC,buffsz);                      //~vaacI~
	UALLOCCHK(pbuff,UALLOC_FAILED);                                //~vaacI~
    poutdata=pbuff;                                                //~vaacI~
    poutdbcs=pbuff+ebclen;                                         //~vaacI~
    opt=0;                                                         //~vaacI~
    rc=ucvebc3_f2bcmd(opt,Pebcopt,Phandle,Pdata,Plen,poutdata,poutdbcs,ebclen/*outbuffsz*/,&outlen);//~vaacR~
    *Ppebclen=outlen;                                              //~vaacI~
    *Ppoutebc=poutdata;                                            //~vaacI~
UTRACED("xeebc_f2b inp data",Pdata,Plen);                          //~vaacI~
UTRACED("xeebc_f2b out ebc",poutdata,outlen);                      //~vaacI~
	return rc;                                                     //~vaacI~
}//xeebc_f2b                                                       //~vaacI~
//****************************************************************
//!xeebc_linechk
//* allocate dbcstbl at load  time
//*retrn:UALLOC_FAILED
//****************************************************************
int xeebc_linechk(int Popt,PULINEH Pplh)
{
//***************
    if (!Pplh->ULHdbcs)  //not once displayed
        if (filechktabdbcs(Pplh)==UALLOC_FAILED)//expand data len
            return UALLOC_FAILED;
    return 0;
}//xeebc_linechk
//****************************************************************
//xeebc_setdbcstbl
//*setdbcstbl by SO/SI at init
//TAB 0x09 data is not tab, fldedit tab insert set spacr and dbcstbl as usual
//rc:1:dbcs detected
//****************************************************************
int xeebc_setdbcstblplh(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Plen)
{
	UCHAR *pc,*pcd;
    PUFILEH pfh;
	int rc,len,opt;
    int handle;                                                    //~va79I~
//*****************
    opt=Popt;
    if (!(pfh=Ppfh))
        pfh=UGETPFH(Pplh);
	if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))
    	opt|=XEEBCO_BIN;
    handle=pfh->UFHhandle;                                         //~va79I~
	pc=Pplh->ULHdata;
	pcd=Pplh->ULHdbcs;
    if (Plen<=0)
    	len=Pplh->ULHlen;
    else
    	len=Plen;
//  rc=xeebc_setdbcstbl(opt,pc,pcd,len);                           //~va79R~
    rc=xeebc_setdbcstbl(opt,handle,pc,pcd,len);                    //~va79I~
	return rc;
}//xeebc_setdbcstblplh
//**************************************************
//cv to syntax chk data
//(keep same column as screen display)
//**************************************************
//int xeebc_b2syn(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,UCHAR **Ppsyndata)//~va79R~
int xeebc_b2syn(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,UCHAR **Ppsyndata)//~va79R~
{
    int buffsz,reslen,dbcsid,ch,asc;
    char *psyn,*pc,*pcd,chstr=0xc0/*one of non punctuation char*/;
//**************************************************
    UTRACED("xeebc_b2syn data",Pdata,Pdatalen);
    UTRACED("xeebc_b2syn dbcs",Pdbcs,Pdatalen);
    buffsz=Pdatalen;
	psyn=xeutf_buffget(XEUTF_BUFFDATA,buffsz+1);      //BUFF2 used by xeutf_cvf2dd
	UALLOCCHK(psyn,UALLOC_FAILED);
    *Ppsyndata=psyn;
    for (pc=Pdata,pcd=Pdbcs,reslen=Pdatalen;reslen>0;reslen--)
    {
    	dbcsid=*pcd++;
    	ch=*pc++;
        if (!dbcsid)	//sbcs
        {
        	if (ch==CHAR_SO||ch==CHAR_SI)
        		*psyn++=chstr;
            else
            {
            	if (ch<CHAR_EBC_SPACE)	//ctl char
                	asc=chstr;	//assume some char
                else
                {
//      			asc=EBC_B2A(ch);                               //~va79R~
//      			asc=UCVEBCH_B2A(Phandle,ch);                   //~va79I~//~vb2DR~
        			asc=(int)UCVEBCH_B2A(Phandle,ch);              //~vb2DI~
                    if (asc<' ')   //trans err or 1b is esc for syntax chk//~va7iR~
                    	asc=chstr;                                 //~va7iI~
                    else                                           //~va7iI~
                    if (!UTF8ISASCII(asc))
                    	asc=chstr;
                }
//      		*psyn++=asc;                                       //~vb2CR~
        		*psyn++=(char)asc;                                 //~vb2CI~
            }
        }
        else
        	*psyn++=chstr;	//one of not punctuation,like as xeutf_dd2dyn
    }
    UTRACED("xeebc_b2syn out",*Ppsyndata,Pdatalen);
    return 0;
}//*xeebc_b2syn
//****************************************************************
//xeebc_setdbcstbl
//*setdbcstbl by SO/SI at init
//TAB 0x09 data is not tab, fldedit tab insert set spacr and dbcstbl as usual
//rc:1:dbcs detected
//****************************************************************
//int xeebc_setdbcstbl(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)//~va79R~
int xeebc_setdbcstbl(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)//~va79I~
{
	int rc,opt;
//*****************
UTRACEP("%s:opt=0x%04x,handle=%p\n",UTT,Popt,Phandle);             //~vb2DI~
UTRACED("xeebc_setdbcstbl inp data",Pdata,Plen);
	opt=0;
    if ((Popt & XEEBCO_BIN)
//  ||  !UDBCSCHK_ISDBCSCV()                                       //~va79R~
    ||  !UCVEBCH_HANDLE_ISDBCSCV(Phandle)                          //~va79I~
    )
    {
//  	if (Popt & XEEBCSW_INITBIN)                                //~va7xR~
    	if (!(Popt & XEEBCO_CALLOC))                               //~va7xR~
	    	memset(Pdbcs,0,(UINT)Plen); //filechktabdbc/expandbuff initial clear dbcst
        rc=0;
    }
    else
//  	rc=ucvebc3_setdbcstbl(opt,Pdata,Pdbcs,Plen);               //~va79R~
    	rc=ucvebc3_setdbcstbl(opt,Phandle,Pdata,Pdbcs,Plen);       //~va79I~
UTRACED("xeebc_setdbcstbl out dbcs",Pdbcs,Plen);
	return rc;
}//xeebc_setdbcstbl
#ifdef AAA  //not used ,no TAB use                                 //~va5LI~
//****************************************************************
//xeebc_setdbcstbltabkeep
//*setdbcstbl by SO/SI after b2m,keep inserted tab
//****************************************************************
int xeebc_setdbcstbltabkeep(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)
{
#ifdef AAA
	int len,offs,reslen;
	UCHAR *pc,*pcd,*pcdo;
//*****************
UTRACED("xeebc_setdbcstbltabkeep inp data",Pdata,Plen);
UTRACED("xeebc_setdbcstbltabkeep inp dbcs",Pdbcs,Plen);
    pc=Pdata;
	pcd=Pdbcs;
	reslen=Plen;
//first tab pad char caused by scroll
	while(reslen && *pcd==TABPADCHAR)//tab advance char
	{
    	pcd++;
		reslen--;
	}
//repl tabs start from tab char
	while(reslen)
	{
        offs=(ULONG)pcd-(ULONG)Pdbcs;
        pcdo=pcd;
		if (!(pcd=memchr(pcd,TABCHAR,(UINT)reslen)))
        {
            setdbcstbl(Pdata+offs,pcdo,reslen);
			break;
        }
		len=(int)((ULONG)pcd-(ULONG)pcdo);
        if (len)	//non tab len
            setdbcstbl(Pdata+offs,pcdo,len);
        reslen-=len;
    	pcd++;				//skip tab char
        reslen--;
		while(reslen && *pcd==TABPADCHAR)//tab advance char
		{
    		pcd++;
			reslen--;
		}
	}//end of string
#else		//no tab maintenace on dbcstbl
	setdbcstbl(Pdata,Pdbcs,Plen);
#endif
UTRACED("xeebc_setdbcstbltabkeep out dbcs",Pdbcs,Plen);
	return 1;
}//xeebc_setdbcstbltabkeep
#endif                                                             //~va5LI~
//****************************************************************
//xeebc_chargetkbd
//*translate kbdinput to ebcdic
//****************************************************************
int xeebc_chargetkbd(int Popt,PUCLIENTWE Ppcw)
{
	UCHAR *keyindata,mbstr[MAX_MBCSLEN],ebcstr[MAX_MBCSLEN],*pu8;
//	int keyindatalen,chklen,rc=0,datatype,u8len,ebclen,rc3;        //~vaf9R~
  	int keyindatalen,chklen,rc=0,datatype,u8len,ebclen=0,rc3;      //~vaf9I~
//  ULONG ucs;                                                     //~va72R~
    UWUCS ucs=0;                                                     //~va72I~//~vaf9R~
    int handle;                                                    //~va79I~
//*******************************
	keyindata=Ppcw->UCWkeydata;
	keyindatalen=Ppcw->UCWkeytype;
    UTRACEP("getkbd input localecode len=%d,%02x%02x\n",keyindatalen,*keyindata,*(keyindata+1));
    datatype=1; //locale code
    handle=0;                                                      //~va79I~
    if (Ppcw->UCWtype==UCWTFILE)                                   //~va79I~
    	handle=UGETPFHFROMPCW(Ppcw)->UFHhandle;                    //~va79I~
//#ifdef UTF8UCS4                                                  //~vap0R~
#ifdef UTF8UCS416                                                  //~vap0I~
//*func_char reject UCS4 for not utf8 file by "err,trans to locale code" but for unity//~vap0I~
    if (UCBITCHK(Ppcw->UCWflag3,UCWF3HEXKBDUCS4)) //3byte ucs
    {
    	ucs=UTF_GETUCS4FROMBESTR(keyindata);
        datatype=-3;
    }
    else
#endif
    if (UCBITCHK(Ppcw->UCWflag3,UCWF3HEXKBDUCS2)) //2 bye ucs
    {
    	ucs=UTF_GETUCSBESTR(keyindata);
        datatype=-2;
    }
    else
    if (UCBITCHK(Ppcw->UCWflag3,UCWF3HEXKBD))
    {
    	datatype=2; //ebc code
    }
    else
    if (UCBITCHK(Ppcw->UCWflag2,UCWF2UTF8STR))  //kbdinput by utf8 str
    {
        pu8=Ppcw->UCWkeydata_utf8str;
//      u8len=strlen(pu8);                                         //~vb2DR~
        u8len=(int)strlen(pu8);                                    //~vb2DI~
		uccvutf2ucs(UCVUCS_UCS4,pu8,u8len,&ucs,&chklen);
//#ifdef UTF8UCS4                                                  //~vap0R~
#ifdef UTF8UCS416                                                  //~vap0I~
//*func_char reject UCS4 for not utf8 file by "err,trans to locale code" but for unity//~vap0I~
		if (UTF_ISUCS4(ucs))
        datatype=-3;	//ucs4
        else
#endif
        datatype=-2;
        UTRACEP("getkbddd input is utf8str %s\n",keyindata);
    }
    if (datatype<0 && UTF8ISASCII(ucs))
    {
    	*keyindata=(UCHAR)ucs;
        keyindatalen=1;
    	datatype=1;	//mb str,may use map
    }
    switch (datatype)
    {
    case 1:
//        if (*keyindata==TABCHAR)
//        {
//            ebclen=1;
//            *ebcstr=TABCHAR;
//            break;
//        }
    	if (Ppcw->UCWnls & KBDNLS_SS3)
        	keyindatalen=UDBCSCHK_SS3SZ;
    	else
    	if (Ppcw->UCWnls & KBDNLS_GB4)
        	keyindatalen=UDBCSCHK_GB4SZ;
//      UmemcpyZ(mbstr,keyindata,keyindatalen);                    //~vb2DR~
        UmemcpyZ(mbstr,keyindata,(size_t)keyindatalen);            //~vb2DI~
//  	rc3=xeebc_m2b1(0,mbstr,keyindatalen,ebcstr,&ebclen);//may use map//~va79R~
    	rc3=xeebc_m2b1(0,handle,mbstr,keyindatalen,ebcstr,&ebclen);//may use map//~va79I~
        if (rc3>=4)
        {
//          uerrmsg("Kbd char translation to EBCDIC failed for \"%s\"",//~vaj4R~
//                  "Kbd:\"%s\" EBCDICへの変換エラー",             //~vaj4R~
//                      mbstr);                                    //~vaj4R~
            uerrmsg("Kbd char translation to EBCDIC failed for \"%s\" by %s",//~vaj4I~
                    "Kbd:\"%s\" EBCDICへの変換エラー(%s)",         //~vaj4I~
                        mbstr,ucvebc4_getcvname(0,handle));        //~vaj4R~
            return 4;
        }
    	break;
    case 2:		//ebc code	by hex input,len should be 1
    	break;
    default:
//  	rc3=xeebc_ucs2ebc1(0,ucs,ebcstr,&ebclen);                  //~va79R~
//  	rc3=xeebc_ucs2ebc1(0,handle,ucs,ebcstr,&ebclen);           //~va79I~//~vb2DR~
    	rc3=xeebc_ucs2ebc1(0,handle,(ULONG)ucs,ebcstr,&ebclen);    //~vb2DI~
        if (rc3>=4)
        {
//          uerrmsg("Kbd char translation to EBCDIC failed for u-%x",//~vaj4R~
//                  "Kbd:u-%x EBCDICへの変換エラー",               //~vaj4R~
//                      ucs);                                      //~vaj4R~
            uerrmsg("Kbd char translation to EBCDIC failed for u-%x by %s",//~vaj4I~
                    "Kbd:u-%x EBCDICへの変換エラー(%s)",           //~vaj4I~
                        ucs,ucvebc4_getcvname(0,handle));          //~vaj4R~
            return 4;
        }
    }
    if (datatype!=2)	//hex ebc input
    {
        *keyindata=*ebcstr;	//expecting all dbcs is 2 byte on EBC
        Ppcw->UCWkeytype=1;
        if (ebclen>1)
        {
            *(keyindata+1)=*(ebcstr+1);
            Ppcw->UCWkeytype=2;
        }
    }
    UTRACEP("xeebc getkbddd rc=%d,len=%d,data=%02x%02x\n",rc,keyindatalen,*keyindata,*(keyindata+1));
    return rc;
}//xeebc_chargetkbd
//**************************************************
//*xeebc_filesetsosi
//*insert so/si for CHAROPREP/CHAROPINS                            //~va5XR~
//**************************************************
int xeebc_filesetsosi(int Popt,int Pmode,PUFILEH Ppfh,PULINEH Pplh,int Ppos,
					UCHAR *Pkeyindata,int Pkeyindatalen,UCHAR *Pkeyindata_ebc,UCHAR *Pkeyindata_ebcdbcs,int *Ppkeyindatalen_ebc)
{
    UCHAR   *pdata0,*pdbcs0,*pc,*pcd,*pcr,*pcdr,*pc2,*pcd2;
    int ulhlen,swdbcsinput,sosiopt=0,posr,newlen;                  //~va5qR~
    int olddbcsid=0;
    int handle;                                                    //~va79I~
//*************
	ulhlen=Pplh->ULHlen;		//old len
    pdata0=Pplh->ULHdata;
    pdbcs0=Pplh->ULHdbcs;
    handle=UGETPFH(Pplh)->UFHhandle;                               //~va79I~
    pc=pdata0+Ppos;
    pcd=pdbcs0+Ppos;
    if ((Popt & XEEBCSO_EXPANDCHK))
    {
    	swdbcsinput=Pkeyindatalen>1;
        if (swdbcsinput)
        	sosiopt|=XEEBCSW_KEYINDBCS;
    	if ((Popt & XEEBCSO_BIN)) //bin file or converter is dbcs
        	sosiopt|=XEEBCSW_BIN;    //for update call
        newlen=Pkeyindatalen;
    	if ((Popt & XEEBCSO_BIN)  //bin file or converter is dbcs
//  	||  !UDBCSCHK_ISDBCSCV()                                   //~va5XI~//~va79R~
        ||  !UCVEBCH_HANDLE_ISDBCSCV(handle)                       //~va79I~
        ||  UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))
        {
//      	memcpy(Pkeyindata_ebc,Pkeyindata,Pkeyindatalen);       //~vb2DR~
        	memcpy(Pkeyindata_ebc,Pkeyindata,(size_t)Pkeyindatalen);//~vb2DI~
            pcd2=Pkeyindata_ebcdbcs;
            *pcd2++=0;
            if (swdbcsinput)
            	*pcd2++=0;
        }//HHEX
        else
        {
            if (swdbcsinput)         //DBCS input
            {
                for (;;)
                {
                    if (Ppos>=ulhlen)   //out of record
                    {
                        sosiopt|=XEEBCSW_INSSO|XEEBCSW_INSSI; //insert SO,add SI
                        break;
                    }
                    if (*pcd==UDBCSCHK_DBCS2ND)// 1(2) split dbcs
                    {
                        sosiopt|=XEEBCSW_SETDBCSTBL;
                        break;
                    }
                    if (*pcd==UDBCSCHK_DBCS1ST)
                        break;                  //no SO/SI insert
    //**
                    if (Pmode==CHAROPREP)
                    {
                    	if (Ppos && *pc==CHAR_SI && *(pcd-1)==UDBCSCHK_DBCS2ND)//12(i)
                        {
                    		if (Ppos+2<ulhlen                      //~va8pI~
                            &&  *(pc+1)==CHAR_SO                   //~va8pI~
                            &&  *(pcd+2)==UDBCSCHK_DBCS1ST         //~va8pI~
                            )                       //2+SI+SO+1    //~va8pI~
                            	break;                             //~va8pI~
                            sosiopt|=XEEBCSW_INSSI;      //set SI only
                            break;
                        }
                        posr=Ppos+4;//SO+keyindata+SI
                        if (posr>=ulhlen)
                        {
                            sosiopt|=XEEBCSW_INSSO|XEEBCSW_INSSI; //insert SO,add SI
                            break;
                        }
                        pcr=pc+3;      //chk validity to set SI
                        pcdr=pcd+3;
                        if (*pcdr==UDBCSCHK_DBCS1ST) //(o12)1   no need si
                        {
                            sosiopt|=XEEBCSW_INSSO;      //set SO only
                            break;
                        }
                        if (*pcdr==UDBCSCHK_DBCS2ND //(o12)2
                        ||  (*pcr==CHAR_SO||*pcr==CHAR_SI)  //(o12)o
                        )
	                        sosiopt|=XEEBCSW_SETDBCSTBL;
                        sosiopt|=XEEBCSW_INSSO|XEEBCSW_INSSI; //inser BOTH
                    }
                    else    //OPINS
                    {
                    	if (Ppos && *pc==CHAR_SI && *(pcd-1)==UDBCSCHK_DBCS2ND)//12(i)
                            break;      //inser data only
                        sosiopt|=XEEBCSW_INSSO|XEEBCSW_INSSI; //insert both
                    }
                    break;
                }//for
            }//
            else    //SBCS
            {
                for (;;)
                {
                    if (*Pkeyindata==CHAR_SO||*Pkeyindata==CHAR_SI)   //SO/SI input
                    {
                        sosiopt|=XEEBCSW_SETDBCSTBL;
                        break;
                    }
                    if (Ppos>=ulhlen)   //out of record
                        break;
                    if ((*pc==CHAR_SO||*pc==CHAR_SI)  //SO/SI replaced
                    )
                    {
                        sosiopt|=XEEBCSW_SETDBCSTBL;
                        break;
                    }
                    olddbcsid=*pcd; //keep dbcs1st/2nd
                    sosiopt|=XEEBCSW_KEEPDBCSTB;
                    break;
                }
            }//SBCS
            pc2=Pkeyindata_ebc;
            pcd2=Pkeyindata_ebcdbcs;
            if (sosiopt & XEEBCSW_INSSO)
                *pc2++=CHAR_SO,*pcd2++=0;
//          memcpy(pc2,Pkeyindata,Pkeyindatalen);                  //~vb2DR~
            memcpy(pc2,Pkeyindata,(size_t)Pkeyindatalen);          //~vb2DI~
            pc2+=Pkeyindatalen;
            if (swdbcsinput)
                *pcd2++=UDBCSCHK_DBCS1ST,*pcd2++=UDBCSCHK_DBCS2ND;
            else
//              *pcd2++=olddbcsid;                                 //~vb2CR~
                *pcd2++=(UCHAR)olddbcsid;                          //~vb2CI~
            if (sosiopt & XEEBCSW_INSSI)
                *pc2++=CHAR_SI,*pcd2++=0;
            if (sosiopt & XEEBCSW_INSSO2)
                *pc2++=CHAR_SO,*pcd2++=0;
//          newlen=(ULONG)pc2-(ULONG)Pkeyindata_ebc;               //~vafkR~
//          newlen=(ULPTR)pc2-(ULPTR)Pkeyindata_ebc;               //~vafkI~//~vb2DR~
            newlen=PTRDIFF(pc2,Pkeyindata_ebc);                    //~vb2DI~
        }//not HHEX
        *Ppkeyindatalen_ebc=newlen;
    }//CHKADDLEN
    else    //update record
    {
        sosiopt=Popt & XEEBCSO_OPTMASK;
    	memcpy(pc,Pkeyindata,(UINT)Pkeyindatalen);
    	memcpy(pcd,Pkeyindata_ebcdbcs,(UINT)Pkeyindatalen);
        if (sosiopt & XEEBCSW_SETDBCSTBL	//for OPREP
        ||  (Pmode==CHAROPINS && !(sosiopt&XEEBCSW_BIN))
        )
//  	  if (UDBCSCHK_ISDBCSCV())                                 //~va5XI~//~va79R~
          if (UCVEBCH_HANDLE_ISDBCSCV(handle))                     //~va79I~
//			xeebc_setdbcstbl(0,pdata0,pdbcs0,ulhlen);              //~va79R~
  			xeebc_setdbcstbl(0,handle,pdata0,pdbcs0,ulhlen);       //~va79I~
    }
    return sosiopt;
}//xeebc_filesetsosi
//**************************************************
//*xeebc_getdbcssplitctr
//*get delete dbcs byte ctr
//**************************************************
int xeebc_getdbcssplitctr(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Ppos,int *Ppdelctr,int *Ppbackctr)
{
    UCHAR   *pdata0,*pdbcs0,*pc,*pcd;
    int ulhlen,sosiopt=0,delctr,backctr;                           //~va5qR~
    int handle;                                                    //~va79I~
//*************
	*Ppdelctr=0;
	*Ppbackctr=0;
	ulhlen=Pplh->ULHlen;		//old len
    if (Ppos>=ulhlen)
    	return 0;
    pdata0=Pplh->ULHdata;
    pdbcs0=Pplh->ULHdbcs;
    handle=UGETPFH(Pplh)->UFHhandle;                               //~va79I~
    pc=pdata0+Ppos;
    pcd=pdbcs0+Ppos;
    delctr=1;
    backctr=0;
//if (UDBCSCHK_ISDBCSCV())                                         //~va5XI~//~va79R~
  if (UCVEBCH_HANDLE_ISDBCSCV(handle))                             //~va79I~
    if (!UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))
    {
    	if (*pcd==UDBCSCHK_DBCS1ST)
        {
	        delctr=2;
        	if (Ppos>0 && *(pc-1)==CHAR_SO)       //o(1)
            {
                if (Ppos+2<ulhlen && *(pc+2)==CHAR_SI)  //o(1)2i
                {
	            	backctr++;
                    delctr=4;
                }
                //else                              //o(1)21
            }
            //else    //not TOP dbcs      2(1)2
        }
        else
    	if (*pcd==UDBCSCHK_DBCS2ND)
        {
	        delctr=2;
        	if (Ppos>1 && *(pc-2)==CHAR_SO)      //o1(2)
            {
                if (Ppos+1<ulhlen && *(pc+1)==CHAR_SI)   //o1(2)i
                {
	            	backctr+=2;	//delete SO  2byte before
                    delctr=4;
                }
                //else                                     //o1(2)1
            }
            //else    //not TOP dbcs               //21(2)
        }
        else
        if (*pc==CHAR_SO||*pc==CHAR_SI)
        	sosiopt|=XEEBCSW_SETDBCSTBL;
    }
	*Ppdelctr=delctr;
	*Ppbackctr=backctr;
    return sosiopt;
}//xeebc_getdbcssplitctr
//**************************************************************** //~0425I~
//!xeebc_cvdatawb                                                  //~0425I~
//ebc<-->local/utf8 translation at write to file                   //~0425I~
//handle is  new+old whe b2b                                       //~va7tI~
//rc:0,UALLOC_FAILED                                               //~0425I~
//**************************************************************** //~0425I~
//int xeebc_cvdatawb(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,int *Ppoutlen,UCHAR *Pdbcs,int Pdbcstblen)//~0425I~//~va5qR~//~va79R~
int xeebc_cvdatawb(int Popt,int Phandle,char *Pinp,int Pinplen,UCHAR **Ppout,int *Ppoutlen,UCHAR *Pdbcs,int Pdbcstblen)//~va79I~
{                                                                  //~0425I~
	int opt,outlen,rc=0,rc2,eolsz=0,cvlen;                         //~0426R~
    UCHAR *poutdata;                                               //~0425I~
    int oldhandle,newhandle;                                       //~va7tI~
//****************************                                     //~0425I~
	UTRACED("xeebc_cvdatawb inp data",Pinp,Pinplen);               //~0425I~
	UTRACED("xeebc_cvdatawb inp dbcs",Pdbcs,Pdbcstblen);           //~0425I~
    if (Popt & XEEBCO_EOL2)                                        //~0426R~
        eolsz=2;                                                   //~0426I~
    else                                                           //~0426I~
    if (Popt & XEEBCO_EOL1)                                        //~0426R~
        eolsz=1;                                                   //~0426I~
    cvlen=Pinplen-eolsz;                                           //~0426I~
 	if (Popt & (XEEBCO_B2B))   //ebc->ebc                          //~va7tI~
 	{                                                              //~va7tI~
    	oldhandle=Phandle & 0xff;                                  //~va7tI~
    	newhandle=Phandle >>8;                                     //~va7tI~
    	opt=Popt;                                                  //~va7tI~
    	opt|=XEEBCO_CVCTL;                                         //~va7tI~
    	rc2=xeebc_b2b(opt,oldhandle,newhandle,Pinp,Pdbcs,cvlen,&poutdata,0/*outdbcs*/,&outlen);//~va7tI~
    }                                                              //~va7tI~
    else    //F2B(dd2b),L2B                                        //~va7tI~
 	if (Popt & (XEEBCO_B2L|XEEBCO_B2F))   //ebc->locale            //~0425I~
 	{                                                              //~0425I~
    	opt=Popt;                                                  //~0425I~
    	opt|=XEEBCO_SOSI2SPACE;                                    //~0425I~
    	opt|=XEEBCO_CVCTL;                                         //~va5XI~
//  	rc2=xeebc_b2msetdbcs(opt,Pinp,Pdbcs,cvlen,&poutdata,0/*outdbcs*/,&outlen);//~0426R~//~va79R~
    	rc2=xeebc_b2msetdbcs(opt,Phandle,Pinp,Pdbcs,cvlen,&poutdata,0/*outdbcs*/,&outlen);//~va79I~
    }                                                              //~0425I~
    else    //F2B(dd2b),L2B                                        //~0425R~
 	{                                                              //~0425I~
    	opt=Popt;                                                  //~0425I~
    	opt|=XEEBCO_CVCTL;                                         //~va5XI~
//  	rc2=xeebc_m2bsetdbcs(opt,Pinp,Pdbcs,cvlen,&poutdata,0/*outdbcs*/,&outlen);//~0426R~//~va79R~
    	rc2=xeebc_m2bsetdbcs(opt,Phandle,Pinp,Pdbcs,cvlen,&poutdata,0/*outdbcs*/,&outlen);//~va79I~
 	}                                                              //~0425R~
    if (eolsz)   //crlf data                                       //~0426R~
    {                                                              //~0425I~
        memcpy(poutdata+outlen,Pinp+cvlen,(UINT)eolsz);  //append crlf//~0426R~
        outlen+=eolsz;                                             //~0426I~
    }                                                              //~0425I~
    rc=rc2;                                                        //~0426I~
    *Ppoutlen=outlen;                                              //~0426R~
    *Ppout=poutdata;                                               //~0425I~
	UTRACED("xeebc_cvdatawb",poutdata,outlen);                     //~0425I~
	UTRACEP("xeebc_cvdatawb rc=%d\n",rc);                          //~0425I~
    return rc;                                                     //~0425I~
}//xeebc_cvdatawb                                                  //~0425I~
//**************************************************************** //~0503I~
//!xeebc_modechng                                                  //~0503I~
//one of src/tgt is ebc                                            //~0503I~
//rc:UALLOC_FAILED,1:mode changed                                  //~0503R~
//**************************************************************** //~0503I~
//int xeebc_modechng(int Popt,PUFILEH Ppfhd,PUFILEH Ppfhs,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~0503R~//~va7yR~
int xeebc_modechng(int Popt,PUFILEH Ppfhd,PUFILEH Ppfhs,int Psrchandle,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~va7yI~
					UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen)//~0503I~
{                                                                  //~0503I~
    int rc2,outlen,swebcfile,opt;                                  //~0503R~
    UCHAR *poutdata,*poutdbcs=0;                                   //~0503I~
    int handle;                                                    //~va79I~
    int srchandle;                                                 //~va7yI~
//****************************                                     //~0503I~
    if (Ppfhs)                                                     //~va7yI~
    	srchandle=Ppfhs->UFHhandle;                                //~va7yI~
    else                                                           //~va7yI~
    	srchandle=Psrchandle;                                      //~va7yI~
    swebcfile=PFH_ISEBC(Ppfhd);                                    //~0503R~
  	if (swebcfile)		//tgt ebcfile                              //~va50I~//~0503I~
    {                                                              //~0503I~
    	handle=Ppfhd->UFHhandle;                                   //~va79I~
      if (Popt & XEEBCO_B2B)    //src is diffrent ebc codepage     //~va7yI~
		rc2=xeebc_b2b(Popt,srchandle,handle,Pdata,Pdbcs,Pdatalen,&poutdata,&poutdbcs,&outlen);//~va7yI~
      else                                                         //~va7yI~
//  	rc2=xeebc_m2bsetdbcs(Popt,Pdata,Pdbcs,Pdatalen,&poutdata,&poutdbcs,&outlen);//~0503R~//~va79R~
    	rc2=xeebc_m2bsetdbcs(Popt,handle,Pdata,Pdbcs,Pdatalen,&poutdata,&poutdbcs,&outlen);//~va79I~
    }                                                              //~0503I~
    else	//src ebc                                              //~0503I~
    {                                                              //~0503I~
//  	handle=Ppfhs->UFHhandle;                                   //~va79I~//~va7yR~
    	handle=srchandle;                                          //~va7yI~
        opt=Popt|XEEBCO_SOSI2SPACE;                                //~0503I~
    	if (Popt & XEEBCO_ERRREP)                                  //~va5EI~
	        opt|=UCVEBC3O_ERRREP;                                  //~va5EI~
//  	rc2=xeebc_b2msetdbcs(opt,Pdata,Pdbcs,Pdatalen,&poutdata,&poutdbcs,&outlen);//~0503R~//~va79R~
    	rc2=xeebc_b2msetdbcs(opt,handle,Pdata,Pdbcs,Pdatalen,&poutdata,&poutdbcs,&outlen);//~va79I~
    }                                                              //~va50I~//~0503I~
    UALLOCCHKRC(rc2);                                              //~0503I~
    *Ppoutdata=poutdata;                                           //~0503I~
    *Ppoutdbcs=poutdbcs;                                           //~0503I~
    *Ppoutlen=outlen;                                              //~0503I~
    return 1;                                                      //~0503R~
}//xeebc_modechng                                                  //~0503R~
//**************************************************************** //~0507I~
//!memmem ascii str                                                //~0507I~
//rc:UALLOC_FAILED                                                 //~0507I~
//**************************************************************** //~0507I~
//UCHAR *xeebc_umemmem_bandl(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,UCHAR *Pmbstr,int Plen,int Plenmb)//~0507I~//~va79R~
UCHAR *xeebc_umemmem_bandl(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,UCHAR *Pmbstr,int Plen,int Plenmb)//~va79R~
{                                                                  //~0507I~
	UCHAR *pbuff,*pdbcs,*pc;                                       //~0507I~
    int buffsz;                                                    //~0507I~
//************************                                         //~0507I~
    buffsz=Plenmb*2;                                               //~0507I~
	pbuff=xeutf_buffget(XEUTF_BUFFDATA,buffsz+1);                  //~0507I~
	UALLOCCHK(pbuff,0);                                            //~0507R~
    pdbcs=pbuff+Plenmb;                                            //~0507I~
//  ucvebc_a2bfld(0,Pmbstr,pbuff,Plenmb);                          //~0507R~//~va79R~
    ucvebc_a2bfld(0,Phandle,Pmbstr,pbuff,Plenmb);                  //~va79I~
//  memset(pdbcs,0,Plenmb);                                        //~0507I~//~vb2DR~
    memset(pdbcs,0,(size_t)Plenmb);                                //~vb2DI~
    pc=ucvebc_umemmem(0,Pdata,Pdbcs,Plen,pbuff,pdbcs,Plenmb);      //~0507I~
    return pc;                                                     //~0507I~
}//xeebc_umemmembandl                                              //~va6wR~//~va79R~
//**************************************************               //~va6wI~
//compare ebc and dd fmt/locale string(after b2dd/b2m)             //~va6wI~
//rc 0:match,1 unmatch                                             //~va6wI~
//**************************************************               //~va6wI~
//int xeebc_cvmemcmp(int Popt,UCHAR *Pebcdata,UCHAR *Pebcdbcs,int Pebclen,//~va6wR~//~va79R~
int xeebc_cvmemcmp(int Popt,int Phandle,UCHAR *Pebcdata,UCHAR *Pebcdbcs,int Pebclen,//~va79I~
						UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int *Pppos1,int *Pppos2)//~va6wR~
{                                                                  //~va6wI~
    UCHAR *poutdata,*poutdbcs,*pc1,*pc2,*pcd1,*pcd2,*pc3,*pcd3;    //~va6wR~
    int len,opt,rc,dbcsid,reslen,reslen3,pos1,pos2=0,outlen;         //~va6wR~//~vaf9R~
    int chsz1,chsz3,reslen1,pos3=0;                                  //~va6wI~//~vaf9R~
//****************************                                     //~va6wI~
    if (Pppos1) //ebc                                              //~va6wI~
        *Pppos1=Pebclen;                                           //~va6wR~
    if (Pppos2)                                                    //~va6wI~
        *Pppos2=Plen;                                              //~va6wI~
	poutdbcs=0;	//request malloc                                   //~va6wI~
	if (Popt & 	XEEBCMC_UTF8)                                      //~va6wI~
    	opt=XEEBCO_B2DD|XEEBCO_SOSI2SPACE|XEEBCO_SETF2LERR;        //~va6wR~
    else                                                           //~va6wI~
        opt=XEEBCO_B2L|XEEBCO_SOSI2SPACE|XEEBCO_SETF2LERR;         //~va6wR~
//  rc=xeebc_b2msetdbcs(opt,Pebcdata,Pebcdbcs,Pebclen,&poutdata,&poutdbcs,&outlen);//~va6wR~//~va79R~
    rc=xeebc_b2msetdbcs(opt,Phandle,Pebcdata,Pebcdbcs,Pebclen,&poutdata,&poutdbcs,&outlen);//~va79I~
	UALLOCCHKRC(rc);                                               //~va6wI~
    if (!Pppos1 && !Pppos2)	//no request to return unmatch pos     //~va6wR~
    {                                                              //~va6wI~
    	if (outlen!=Plen                                           //~va6wI~
    	||  memcmp(Pebcdata,poutdata,(UINT)Plen)                   //~va6wI~
    	||  memcmp(Pebcdbcs,poutdbcs,(UINT)Plen)                   //~va6wI~
        )                                                          //~va6wI~
        	rc=1;	//unmatch                                      //~va6wI~
        else                                                       //~va6wI~
        	rc=0;                                                  //~va6wI~
    }                                                              //~va6wI~
    else                                                           //~va6wI~
    {                                                              //~va6wI~
    	rc=0;                                                      //~va6wI~
    	len=min(Plen,outlen);                                      //~va6wI~
        for (pc1=poutdata,pcd1=poutdbcs,pc2=Pdata,pcd2=Pdbcs,reslen=len;//~va6wI~
                reslen>0;                                          //~va6wR~
				reslen--,pc1++,pc2++,pcd1++,pcd2++)                //~va6wR~
        {                                                          //~va6wI~
            if (*pc1==*pc2 && *pcd1==*pcd2)                        //~va6wR~
            	continue;                                          //~va6wI~
            rc=1;	//unmatch                                      //~va6wI~
            break;                                                 //~va6wI~
        }                                                          //~va6wI~
        if (!rc)                                                   //~va6wI~
        	if (outlen>Plen)                                       //~va6wI~
            	rc=1;	//search in b2x data                       //~va6wI~
        if (rc)	//unmatch                                          //~va6wI~
        {                                                          //~va6wI~
//        	pos1=(ULONG)pc1-(ULONG)poutdata;                       //~va6wI~//~vafkR~
//      	pos1=(ULPTR)pc1-(ULPTR)poutdata;                       //~vafkI~//~vb2DR~
        	pos1=PTRDIFF(pc1,poutdata);                            //~vb2DI~
            dbcsid=*pcd1;                                          //~va6wI~
            if (pos1>0 && UDBCSCHK_DBCSNOT1ST(dbcsid))             //~va6wI~
            	pos1-=XESUB_DBCSSPLITCTR_L(poutdbcs,pos1);         //~va6wI~
//        	pos2=(ULONG)pc2-(ULONG)Pdata;  //dd or lc              //~va6wR~//~vafkR~
//      	pos2=(ULPTR)pc2-(ULPTR)Pdata;  //dd or lc              //~vafkI~//~vb2DR~
        	pos2=PTRDIFF(pc2,Pdata);  //dd or lc                   //~vb2DI~
            dbcsid=*pcd2;                                          //~va6wI~
            if (pos2>0 && UDBCSCHK_DBCSNOT1ST(dbcsid))             //~va6wI~
            	pos2-=XESUB_DBCSSPLITCTR_L(Pdbcs,pos2);            //~va6wI~
        	for (pc3=Pebcdata,pcd3=Pebcdbcs,pc1=poutdata,pcd1=poutdbcs,reslen1=pos1,reslen3=Plen;//~va6wI~
					reslen1>0;                                     //~va6wI~
					reslen1-=chsz1,reslen3-=chsz3,pc1+=chsz1,pcd1+=chsz1,pc3+=chsz3,pcd3+=chsz3)//~va6wI~
            {                                                      //~va6wI~
	            dbcsid=*pcd1;             //u8/lc                  //~va6wR~
            	if (UDBCSCHK_DBCS1STLU(dbcsid))                    //~va6wI~
                	chsz1=XESUB_DBCSSPLITCTR(poutdbcs,outlen,pos2-reslen1);//~va6wR~
                else                                               //~va6wI~
                	chsz1=1;                                       //~va6wR~
                dbcsid=*pcd3;             //b2u/b2l                //~va6wR~
            	if (UDBCSCHK_DBCS1STLU(dbcsid))                    //~va6wI~
                	chsz3=XESUB_DBCSSPLITCTR(Pebcdbcs,Plen,Plen-reslen3);//~va6wR~
                else                                               //~va6wI~
                	chsz3=1;                                       //~va6wI~
                if (chsz3>reslen3)                                 //~va6wI~
                	break;                                         //~va6wI~
            }                                                      //~va6wI~
            pos3=Plen-reslen3;                                     //~va6wI~
        }//unmatch                                                 //~va6wI~
        else		//match                                        //~va6wI~
        if (outlen<Plen)		                                   //~va6wI~
        {                                                          //~va6wI~
            rc=1;                                                  //~va6wI~
        	pos3=Pebclen;                                          //~va6wI~
//        	pos2=(ULONG)pc2-(ULONG)Pdata;  //dd or lc              //~va6wI~//~vafkR~
//      	pos2=(ULPTR)pc2-(ULPTR)Pdata;  //dd or lc              //~vafkI~//~vb2DR~
        	pos2=PTRDIFF(pc2,Pdata);  //dd or lc                   //~vb2DI~
            dbcsid=*pcd2;                                          //~va6wI~
            if (pos2>0 && UDBCSCHK_DBCSNOT1ST(dbcsid))             //~va6wI~
            	pos2-=XESUB_DBCSSPLITCTR_L(Pdbcs,pos2);            //~va6wI~
        }                                                          //~va6wI~
        if (rc)                                                    //~va6wI~
        {                                                          //~va6wI~
        	if (Pppos1) //ebc                                      //~va6wR~
            	*Pppos1=pos3;                                      //~va6wR~
        	if (Pppos2)                                            //~va6wR~
            	*Pppos2=pos2;                                      //~va6wR~
        }                                                          //~va6wI~
	}                                                              //~va6wI~
//UTRACEP("xeebc_cvmemcmp rc=%d,pos1=%d(ebc),pos2(dd/lc)=%d,pos3(ebc)=%d\n",rc,pos1,pos2,pos3);//~va6wR~//~vaf9R~
UTRACED("inp ebc data",Pebcdata,Pebclen);                          //~va6wR~
UTRACED("inp ebc dbcs",Pebcdbcs,Pebclen);                          //~va6wR~
UTRACED("inp lc/dd data",Pdata,Plen);                              //~va6wR~
UTRACED("inp lc/dd dbcs",Pdbcs,Plen);                              //~va6wR~
UTRACED("inp cv    data",poutdata,outlen);                         //~va6wI~
UTRACED("inp cv    dbcs",poutdbcs,outlen);                         //~va6wR~
	return rc;                                                     //~va6wI~
}//xeebc_cvmemcmp                                                  //~va6wI~
//**************************************************               //~va7xI~
//compare ebc and ebc different handle case                        //~va7xI~
//rc 0:match,1 unmatch                                             //~va7xI~
//**************************************************               //~va7xI~
int xeebc_cvmemcmpb2b(int Popt,int Phandle1,UCHAR *Pdata1,UCHAR *Pdbcs1,int Plen1,//~va7xI~
                            int Phandle2,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen2,//~va7xI~
						int *Pppos1,int *Pppos2)                   //~va7xI~
{                                                                  //~va7xI~
    UCHAR *poutdata,*poutdbcs,*pc1,*pc2,*pcd1,*pcd2;               //~va7xR~
    int len,opt,rc,reslen,outlen;                                  //~va7xR~
//****************************                                     //~va7xI~
    opt=XEEBCO_CVCTL;                                              //~va7xI~
	rc=xeebc_b2b(opt,Phandle1,Phandle2,Pdata1,Pdbcs1,Plen1,&poutdata,&poutdbcs,&outlen);//~va7xI~
	UALLOCCHKRC(rc);                                               //~va7xI~
    rc=0;                                                          //~va7xI~
    len=min(Plen2,outlen);                                         //~va7xI~
    for (pc1=poutdata,pcd1=poutdbcs,pc2=Pdata2,pcd2=Pdbcs2,reslen=len;//~va7xI~
        	reslen>0;                                              //~va7xI~
			reslen--,pc1++,pc2++,pcd1++,pcd2++)                    //~va7xI~
    {                                                              //~va7xI~
    	if (*pc1==*pc2 && *pcd1==*pcd2)                            //~va7xI~
            continue;                                              //~va7xI~
        rc=1;	//unmatch                                          //~va7xI~
        break;                                                     //~va7xI~
    }                                                              //~va7xI~
    if (!rc)                                                       //~va7xI~
        if (Plen1!=Plen2)                                          //~va7xI~
            rc=1;	//search in b2x data                           //~va7xI~
//  *Pppos1=(ULONG)pc1-(ULONG)poutdata;                            //~va7xR~//~vafkR~
//  *Pppos1=(ULPTR)pc1-(ULPTR)poutdata;                            //~vafkI~//~vb2DR~
    *Pppos1=PTRDIFF(pc1,poutdata);                                 //~vb2DI~
//  *Pppos2=(ULONG)pc2-(ULONG)Pdata2;                              //~va7xI~//~vafkR~
//  *Pppos2=(ULPTR)pc2-(ULPTR)Pdata2;                              //~vafkI~//~vb2DR~
    *Pppos2=PTRDIFF(pc2,Pdata2);                                   //~vb2DI~
UTRACEP("xeebc_cvmemcmp rc=%d,pos1=%d,pos2=%d%d\n",rc,*Pppos1,*Pppos2);//~va7xI~
	return rc;                                                     //~va7xI~
}//xeebc_cvmemcmpb2b                                               //~va7xI~
//**************************************************               //~va79I~
//ebc converter name check                                         //~va79I~
//**************************************************               //~va79I~
int xeebc_createhandle(int Popt,PUFILEH Ppfh,char *Pcvname,int *Pphandle)//~va79I~
{                                                                  //~va79I~
	int rc,handle,opt;                                             //~va79I~
//****************************                                     //~va79I~
UTRACEP("%s:Pcvname=%s\n",UTT,Pcvname);                            //~vbBcI~
	opt=0;                                                         //~va79I~
    rc=ucvebc4_createhandle(opt,Pcvname,&handle);                  //~va79I~
    if (!rc)                                                       //~va79I~
    {                                                              //~va79I~
    	if (Ppfh)                                                  //~va79I~
    		Ppfh->UFHhandle=handle;                                //~va79I~
        if (Pphandle)                                              //~va79I~
        	*Pphandle=handle;                                      //~va79I~
    }                                                              //~va79I~
UTRACEP("xeebc_createhandle rc=%d,cv=%s,handle=%d\n",rc,Pcvname,handle);//~va79I~
	return rc;                                                     //~va79I~
}//xeebc_createhandle                                              //~va79I~
//**************************************************               //~va8bI~
//*xeebc_filesetsosistr                                            //~va8bI~
//*insert so/si for charcap rep/ins                                //~va8bI~
//*rc:UALLOC_FAILED                                                //~va8bI~
//**************************************************               //~va8bI~
int xeebc_filesetsosiplhupdate(int Popt,int Psosiopt,PUFILEH Ppfh,PULINEH Pplh,int Ppos,int Pdestlen,//~va8bR~
					UCHAR *Psrcdata,UCHAR *Psrcdbcs,int Psrclen)   //~va8bI~
{                                                                  //~va8bI~
    int lenr;                                                      //~va8bR~
    UCHAR *pc,*pcd;                                                //~va8bR~
//***************************                                      //~va8bI~
    pc=Pplh->ULHdata+Ppos;                                         //~va8bR~
    pcd=Pplh->ULHdbcs+Ppos;                                        //~va8bR~
	if (Psosiopt & XEEBCSW_PREV2SPACE)                             //~va8bI~
    	*(pc-1)=CHAR_EBC_SPACE,*(pcd-1)=0;                         //~va8bR~
    if (Popt & XEEBCSO_CAPINS)                                     //~va8bI~
    {                                                              //~va8bI~
    	lenr=Pdestlen-Ppos;                                        //~va8bR~
        if (lenr>0)                                                //~va8bI~
        {                                                          //~va8bI~
        	memmove(pc+Psrclen,pc,(UINT)lenr);                     //~va8bI~
        	memmove(pcd+Psrclen,pcd,(UINT)lenr);                   //~va8bI~
        }                                                          //~va8bI~
    }                                                              //~va8bI~
    memcpy(pc,Psrcdata,(UINT)Psrclen);                             //~va8bI~
    memcpy(pcd,Psrcdbcs,(UINT)Psrclen);                            //~va8bI~
    pc+=Psrclen;                                                   //~va8bI~
    pcd+=Psrclen;                                                  //~va8bI~
	if (Psosiopt & XEEBCSW_NEXT2SPACE)                             //~va8bI~
    	*(pc)=CHAR_EBC_SPACE,*(pcd)=0;                             //~va8bR~
    if (Popt & XEEBCSO_BNDSSORT)                                   //~va8hI~
    {                                                              //~va8iI~
      if (Popt & XEEBCSO_SBCS) //no dbcs consideration for bnds    //~va8iR~
		xeebc_setdbcstblplh(0,Ppfh,Pplh,0);                        //~va8iI~
      else                                                         //~va8iI~
		xeebc_filesetsosibnds(0,Ppfh,Pplh,Ppos,Psrclen);           //~va8hI~
    }                                                              //~va8iI~
    else                                                           //~va8hI~
    if (Popt & XEEBCSO_SETDBCSTBL)                                 //~va8bI~
		xeebc_setdbcstblplh(0,Ppfh,Pplh,0);                        //~va8bR~
    return 0;                                                      //~va8bI~
}//xeebc_filesetsosiplhupdate                                       //~va8bI~//~va8hR~
//**************************************************               //~va8bI~
//*xeebc_filesetsosistr                                            //~va8bI~
//*insert so/si for charcap rep/ins                                //~va8bI~
//*rc:UALLOC_FAILED                                                //~va8bI~
//**************************************************               //~va8bI~
int xeebc_filesetsosiplh(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Ppos,//~va8bR~
					UCHAR *Psrcdata,UCHAR *Psrcdbcs,int Psrclen,   //~va8bI~
                    UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen)//~va8bI~
{                                                                  //~va8bI~
    int handle,plhlen,srclen,buffsz,rc=0;                          //~va8bR~
    UCHAR *plhdata,*plhdbcs,*pbuff,*psrcdata,*psrcdbcs;            //~va8bI~
//***************************                                      //~va8bI~
    handle=Ppfh->UFHhandle;                                        //~va8bI~
	plhdata=Pplh->ULHdata;                                         //~va8bI~
	plhdbcs=Pplh->ULHdbcs;                                         //~va8bI~
	plhlen=Pplh->ULHlen;                                           //~va8bI~
    if ((Popt & XEEBCSO_BIN)  //bin file or converter is dbcs      //~va8bI~
    ||  (Popt & XEEBCSO_BNDSSORT)  //cap2 for bnds sort            //~va8hI~
    ||  (Popt & XEEBCSO_SBCS)  //cap2 for bnds sort                //~va8iI~
    ||  !UCVEBCH_HANDLE_ISDBCSCV(handle)                           //~va8bI~
    ||  UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))                         //~va8bI~
    {                                                              //~va8bI~
    	psrcdata=Psrcdata;                                         //~va8bI~
    	psrcdbcs=Psrcdbcs;                                         //~va8bI~
        srclen=Psrclen;                                            //~va8bI~
    }                                                              //~va8bI~
    else                                                           //~va8bI~
    {                                                              //~va8bI~
		buffsz=(Psrclen+4);	//data and dbcs,may expand by sosi insertion at both size//~va8bI~
    	pbuff=xeutf_buffget(XEUTF_BUFEBCCAP,buffsz*2);             //~va8bR~
		UALLOCCHK(pbuff,UALLOC_FAILED);                            //~va8bI~
    	psrcdata=pbuff;                                            //~va8bI~
    	psrcdbcs=pbuff+buffsz;                                     //~va8bI~
		rc=xeebc_filesetsosistr(Popt,plhdata,plhdbcs,plhlen,Ppos,  //~va8bR~
								Psrcdata,Psrcdbcs,Psrclen,         //~va8bI~
                    			psrcdata,psrcdbcs,&srclen);        //~va8bI~
        UALLOCCHKRC(rc);                                           //~va8bI~
    }                                                              //~va8bI~
    if (Ppoutdata)                                                 //~va8bI~
        *Ppoutdata=psrcdata;                                       //~va8bI~
    if (Ppoutdbcs)                                                 //~va8bI~
        *Ppoutdbcs=psrcdbcs;                                       //~va8bI~
    if (Ppoutlen)                                                  //~va8bI~
        *Ppoutlen=srclen;                                          //~va8bI~
    return rc;                                                     //~va8bR~
}//xeebc_filesetsosiplh                                             //~va8bI~//~va8hR~
//**************************************************               //~va8hI~
//*xeebc_filesetsosibnds                                           //~va8hI~
//*rc:1:sosi rep,2:dbcs continued                                  //~va8hI~
//**************************************************               //~va8hI~
int xeebc_filesetsosibnds(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Ppos,int Plen)//~va8hI~
{                                                                  //~va8hI~
    int handle,plhlen,rc=0,dbcsid,dbcsidp,dbcsidn,pos;             //~va8hR~
    UCHAR *plhdata,*plhdbcs,*pc,*pcd;                              //~va8hR~
//***************************                                      //~va8hI~
    handle=Ppfh->UFHhandle;                                        //~va8hI~
	plhdata=Pplh->ULHdata;                                         //~va8hI~
	plhdbcs=Pplh->ULHdbcs;                                         //~va8hI~
	plhlen=Pplh->ULHlen;                                           //~va8hI~
    if ((Popt & XEEBCSO_BIN)  //bin file or converter is dbcs      //~va8hI~
    ||  !UCVEBCH_HANDLE_ISDBCSCV(handle)                           //~va8hI~
    ||  UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))                         //~va8hI~
    	return 0;                                                  //~va8hI~
//left boundary                                                    //~va8hM~
    pc=plhdata+Ppos;                                               //~va8hI~
    pcd=plhdbcs+Ppos;                                              //~va8hI~
    if (Plen)                                                      //~va8hI~
	    dbcsid=*pcd;                                               //~va8hI~
    else                                                           //~va8hI~
    	dbcsid=0;                                                  //~va8hI~
    if (Ppos>0)                                                    //~va8hI~
    	dbcsidp=*(pcd-1);	//left boundary                        //~va8hI~
    else                                                           //~va8hI~
    	dbcsidp=0;                                                 //~va8hI~
    switch(dbcsidp)   //prev of left boundary                      //~va8hI~
    {                                                              //~va8hI~
    case 0:				//SBCS                                     //~va8hR~
    	switch(dbcsid)                                             //~va8hI~
        {                                                          //~va8hI~
        case 0:                                                    //~va8hI~
        	break;                                                 //~va8hI~
        case UDBCSCHK_DBCS1ST:      //12-->_SO                     //~va8hI~
        	if (Ppos>0 && *(pc-1)==CHAR_SO)                        //~va8hI~
            	break;                                             //~va8hI~
        	if (Plen>=2)                                           //~va8hI~
            {                                                      //~va8hI~
            	*pc=' ',*(pc+1)=CHAR_SO;                           //~va8hI~
                *pcd=0,*(pcd+1)=0;                                 //~va8hI~
                rc=1;                                              //~va8hI~
            }                                                      //~va8hI~
        	break;                                                 //~va8hI~
        default:	//UDBCSCHK_DBCS2ND:    2-->SO                  //~va8hI~
            *pc=CHAR_SO;                                           //~va8hR~
            *pcd=0;                                                //~va8hR~
            rc=1;                                                  //~va8hR~
        }                                                          //~va8hI~
    	break;                                                     //~va8hI~
    case UDBCSCHK_DBCS1ST:                                         //~va8hI~
    	*(pc-1)=CHAR_SI;                                           //~va8hR~
        *(pcd-1)=0;                                                //~va8hI~
        rc=1;                                                      //~va8hI~
    	switch(dbcsid)                                             //~va8hI~
        {                                                          //~va8hI~
        case 0:                                                    //~va8hI~
        	break;                                                 //~va8hI~
        case UDBCSCHK_DBCS1ST:                                     //~va8hI~
        	if (Plen>=2)                                           //~va8hI~
            {                                                      //~va8hI~
            	*pc=' ',*(pc+1)=CHAR_SO;                           //~va8hI~
                *pcd=0,*(pcd+1)=0;                                 //~va8hI~
            }                                                      //~va8hI~
        	break;                                                 //~va8hI~
        default:	//UDBCSCHK_DBCS2ND:                            //~va8hI~
            *pc=CHAR_SO;                                           //~va8hR~
            *pcd=0;                                                //~va8hR~
        }                                                          //~va8hI~
    	break;                                                     //~va8hI~
    default:	//DBCS2ND                                          //~va8hI~
    	switch(dbcsid)                                             //~va8hI~
        {                                                          //~va8hI~
        case 0:                                                    //~va8hI~
        	if (*pc==CHAR_SI)                                      //~va8hI~
            	break;                                             //~va8hI~
        	if (Ppos>=2)                                           //~va8hI~
            {                                                      //~va8hI~
            	*(pc-2)=CHAR_SI,*(pc-1)=' ';                       //~va8hI~
            	*(pcd-2)=0,*(pcd-1)=0;                             //~va8hI~
                rc=1;                                              //~va8hI~
            }                                                      //~va8hI~
        	break;                                                 //~va8hI~
        case UDBCSCHK_DBCS1ST:	//dbcs continued case              //~va8hI~
            rc=2;                                                  //~va8hI~
        	break;                                                 //~va8hI~
        default:	//UDBCSCHK_DBCS2ND:                            //~va8hI~
        	if (Ppos>=2)                                           //~va8hI~
            {                                                      //~va8hI~
            	*(pc-2)=CHAR_SI,*(pc-1)=' ';                       //~va8hI~
            	*(pcd-2)=0,*(pcd-1)=0;                             //~va8hI~
            }                                                      //~va8hI~
            *pc=CHAR_SO;                                           //~va8hR~
            *pcd=0;                                                //~va8hR~
            rc=1;                                                  //~va8hR~
        }                                                          //~va8hI~
    	break;                                                     //~va8hI~
    }//left boundary                                               //~va8hI~
//right boundary                                                   //~va8hI~
	pos=Ppos+Plen;                                                 //~va8hI~
    pc=plhdata+pos;                                                //~va8hI~
    pcd=plhdbcs+pos;                                               //~va8hR~
    if (pos<plhlen)                                                //~va8hR~
    	dbcsidn=*pcd;                                              //~va8hI~
    else                                                           //~va8hI~
    	dbcsidn=0;                                                 //~va8hI~
    if (pos>0)                                                     //~va8hI~
    	dbcsid=*(pcd-1);                                           //~va8hI~
    else                                                           //~va8hI~
    	dbcsid=0;                                                  //~va8hI~
    switch(dbcsidn)   //next of right boundary                     //~va8hI~
    {                                                              //~va8hI~
    case 0:                                                        //~va8hI~
    	switch(dbcsid)                                             //~va8hI~
        {                                                          //~va8hI~
        case 0:                                                    //~va8hI~
        	break;                                                 //~va8hI~
        case UDBCSCHK_DBCS1ST:      //1-->SI                       //~va8hI~
            *(pc-1)=CHAR_SI;                                       //~va8hR~
            *(pcd-1)=0;                                            //~va8hR~
            rc=1;                                                  //~va8hI~
        	break;                                                 //~va8hI~
        default:	//UDBCSCHK_DBCS2ND:    12-->SI_                //~va8hI~
        	if (*pc==CHAR_SI)                                      //~va8hI~
            	break;                                             //~va8hI~
        	if (Plen>=2)                                           //~va8hI~
            {                                                      //~va8hI~
            	*(pc-2)=CHAR_SI,*(pc-1)=' ';                       //~va8hI~
                *(pcd-2)=0,*(pcd-1)=0;                             //~va8hI~
	            rc=1;                                              //~va8hI~
            }                                                      //~va8hI~
        }                                                          //~va8hI~
    	break;                                                     //~va8hI~
    case UDBCSCHK_DBCS1ST:                                         //~va8hI~
    	switch(dbcsid)                                             //~va8hI~
        {                                                          //~va8hI~
        case 0:                                                    //~va8hI~
        	if (pos>0 && *(pc-1)==CHAR_SO)                         //~va8hR~
            	break;                                             //~va8hI~
        	if (Plen>=2)                                           //~va8hI~
            {                                                      //~va8hI~
            	*pc=' ',*(pc+1)=CHAR_SO;                           //~va8hI~
                *pcd=0,*(pcd+1)=0;                                 //~va8hI~
                rc=1;                                              //~va8hI~
            }                                                      //~va8hI~
        	break;                                                 //~va8hI~
        case UDBCSCHK_DBCS1ST:                                     //~va8hI~
        	*(pc-1)=CHAR_SI;                                       //~va8hI~
        	*(pcd-1)=0;                                            //~va8hI~
            rc=1;                                                  //~va8hI~
        	if (Plen>=2)                                           //~va8hI~
            {                                                      //~va8hI~
            	*pc=' ',*(pc+1)=CHAR_SO;                           //~va8hI~
                *pcd=0,*(pcd+1)=0;                                 //~va8hI~
            }                                                      //~va8hI~
        	break;                                                 //~va8hI~
        default:	//UDBCSCHK_DBCS2ND:	continued dbcs case        //~va8hI~
            rc=2;                                                  //~va8hI~
        }                                                          //~va8hI~
    	break;                                                     //~va8hI~
    default:	//DBCS2ND                                          //~va8hI~
    	*pc=CHAR_SO;                                               //~va8hI~
    	*pcd=0;                                                    //~va8hI~
        rc=1;                                                      //~va8hI~
    	switch(dbcsid)                                             //~va8hI~
        {                                                          //~va8hI~
        case 0:                                                    //~va8hI~
        	break;                                                 //~va8hI~
        case UDBCSCHK_DBCS1ST:	                                   //~va8hI~
        	*(pc-1)=CHAR_SI;                                       //~va8hI~
        	*(pcd-1)=0;                                            //~va8hI~
        	break;                                                 //~va8hI~
        default:	//UDBCSCHK_DBCS2ND:                            //~va8hI~
        	if (pos>=2)                                            //~va8hI~
            {                                                      //~va8hI~
            	*(pc-2)=CHAR_SI,*(pc-1)=' ';                       //~va8hI~
            	*(pcd-2)=0,*(pcd-1)=0;                             //~va8hI~
            }                                                      //~va8hI~
        }                                                          //~va8hI~
    	break;                                                     //~va8hI~
    }//left boundary                                               //~va8hI~
    return rc;                                                     //~va8hI~
}//xeebc_filesetsosibnds                                           //~va8hI~
//**************************************************               //~va8jI~
//*set SI for split dbcs at right inner boundary                         //~va8jI~//~va8wR~
//*rc:1 split detected                                             //~va8jI~
//**************************************************               //~va8jI~
int xeebc_setdbcssplitsetsosiR(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Prepch)//~va8jI~
{                                                                  //~va8jI~
	UCHAR *pc,*pcd;                                                //~va8jI~
    int rc=0;                                                      //~va8jI~
//*************                                                    //~va8jI~
	if (Plen<=0)                                                   //~va8jI~
    	return 0;                                                  //~va8jI~
    pc=Pdata+Plen-1;                                               //~va8jI~
    pcd=Pdbcs+Plen-1;                                              //~va8jI~
    switch(*pcd)                                                   //~va8jI~
    {                                                              //~va8jI~
    case UDBCSCHK_DBCS1ST:                                         //~va8jI~
        rc=1;                                                      //~va8jI~//~va8kM~
        if (Plen>1)                                                //~va8kR~
        {                                                          //~va8kI~
        	if (*(pc-1)==CHAR_SO)                                  //~va8kI~
            {                                                      //~va8kI~
//          	*pc--=Prepch,*pc=Prepch;                           //~va8kI~//~vb2CR~
            	*pc--=(UCHAR)Prepch,*pc=(UCHAR)Prepch;             //~vb2CI~
            	*pcd=0;                                            //~va8kI~
                break;                                             //~va8kI~
            }                                                      //~va8kI~
        }                                                          //~va8kI~
        rc|=XEEBCSDSRC_REPSI;    //DBCS1ST replaced to SI at right inner boundary//~va8wI~
        *pc=CHAR_SI;                                               //~va8jI~
        *pcd=0;                                                    //~va8jI~
    	break;                                                     //~va8jI~
    case UDBCSCHK_DBCS2ND:                                         //~va8jI~
	    if (Popt & XEEBCSDSO_HALFCUTONLY)  //rep half cut only     //~va8kI~
        	break;                                                 //~va8kI~
	    if (Popt & XEEBCSDSO_HALFCUTONLYR)  //rep half cut only    //~va8wI~
        	break;                                                 //~va8wI~
        if (Popt & XEEBCSDSO_NEXT1ST)     //right ob is dbcs1st    //~va8wR~
        	break;                                                 //~va8wI~
        if (Popt & XEEBCSDSO_NEXTSI)                               //~va8wI~
        	break;                                                 //~va8wI~
        rc=1;                                                  //~va8jI~//~va8kI~
        if (Plen>2)                                               //~va8jI~//~va8kR~
        {                                                          //~va8jI~
        	if (*(pc-2)==CHAR_SO)                                  //~va8kI~
            {                                                      //~va8kI~
//          	*pc--=Prepch,*pc--=Prepch,*pc=Prepch;	//rep 3 char//~va8kI~//~vb2CR~
            	*pc--=(UCHAR)Prepch,*pc--=(UCHAR)Prepch,*pc=(UCHAR)Prepch;	//rep 3 char//~vb2CI~
            	*pcd--=0,*pcd=0;                                   //~va8kI~
                break;                                             //~va8kI~
            }                                                      //~va8kI~
        }                                                          //~va8kI~
//      *pc--=Prepch,*pc=CHAR_SI;                            //~va8jI~//~va8kR~//~vb2CR~
        *pc--=(UCHAR)Prepch,*pc=CHAR_SI;                           //~vb2CI~
        *pcd--=0,*pcd=0;                                     //~va8jI~//~va8kR~
    	break;                                                     //~va8jI~
    default:                                                       //~va8kR~
	    if (Popt & XEEBCSDSO_HALFCUTONLY)  //rep half cut only     //~va8kI~
        	break;                                                 //~va8kI~
	    if (Popt & XEEBCSDSO_HALFCUTONLYR)  //rep half cut only    //~va8wI~
        	break;                                                 //~va8wI~
        if (*pc==CHAR_SO)                                          //~va8kR~
        {                                                          //~va8kR~
	    	if (!(Popt & XEEBCSDSO_NEXT1ST))  //next is dbcs1st(so is start of dbcs)//~va8wI~
            	break;                                             //~va8wI~
            rc=1;       //shrinked                                 //~va8kR~
//          *pc=Prepch;                                            //~va8kR~//~vb2CR~
            *pc=(UCHAR)Prepch;                                     //~vb2CI~
        }                                                          //~va8kR~
    }//right inner boundary                                               //~va8jI~//~va8kR~
    return rc;                                                     //~va8jI~
}//xeebc_setdbcssplitsetsosiR                                      //~va8jI~
//**************************************************               //~va8kI~
//*set SI for split dbcs at left innser boundary                         //~va8kI~//~va8wR~
//*rc:0x01 split detected,0x02:rep ("21"-->"SO1") occured                                           //~va8kI~//~va8wR~
//**************************************************               //~va8kI~
int xeebc_setdbcssplitsetsosiL(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos,int Prepch)//~va8kR~
{                                                                  //~va8kI~
	UCHAR *pc,*pcd;                                                //~va8kI~
    int rc=0,len;                                                  //~va8kR~
//*************                                                    //~va8kI~
    len=Plen-Ppos;                                                 //~va8kI~
	if (len<=0)                                                    //~va8kR~
    	return 0;                                                  //~va8kI~
    pc=Pdata+Ppos;                                                 //~va8kR~
    pcd=Pdbcs+Ppos;                                                //~va8kR~
    switch(*pcd)                                                   //~va8kI~
    {                                                              //~va8kI~
    case UDBCSCHK_DBCS1ST:                                         //~va8kI~
	    if (Popt & XEEBCSDSO_HALFCUTONLY)  //rep half cut only     //~va8kI~
        	break;                                                 //~va8kI~
	    if (Popt & XEEBCSDSO_HALFCUTONLYL) //rep half cut only     //~va8wI~
        	break;                                                 //~va8wI~
        if (Popt & XEEBCSDSO_PREV2ND)     //left ob is dbcs2nd     //~va8wR~
        	break;                                                 //~va8wI~
        if (Popt & XEEBCSDSO_PREVSO)     //left ob is dbcs2nd      //~va8wI~
        	break;                                                 //~va8wI~
        rc=1;                                                      //~va8kI~
        if (Ppos && *(pcd-1)==UDBCSCHK_DBCS2ND)                    //~va8kI~
        	*pc++=CHAR_SI;                                         //~va8kR~
        else                                                       //~va8kI~
//      	*pc++=Prepch;                                          //~va8kI~//~vb2CR~
        	*pc++=(UCHAR)Prepch;                                   //~vb2CI~
        *pcd++=0;                                                  //~va8kI~
        if (len<=1)                                                //~va8kR~
            break;                                                 //~va8kI~
//      *pc=Prepch;                                                //~va8kI~//~vb2CR~
        *pc=(UCHAR)Prepch;                                         //~vb2CI~
        *pcd=0;                                                    //~va8kI~
    	if (len<=2)                                                //~va8kR~
            break;                                                 //~va8kI~
        if (*(pcd+1)==UDBCSCHK_DBCS1ST)                            //~va8kI~
            *pc=CHAR_SO;                                           //~va8kI~
        else                                                       //~va8kI~
        if (*(pc+1)==CHAR_SI)                                      //~va8kI~
//          *(pc+1)=Prepch;                                        //~va8kI~//~vb2CR~
            *(pc+1)=(UCHAR)Prepch;                                 //~vb2CI~
    	break;                                                     //~va8kI~
    case UDBCSCHK_DBCS2ND:                                         //~va8kI~
        rc=1;                                                      //~va8kI~
//      *pc=Prepch;                                                //~va8kI~//~vb2CR~
        *pc=(UCHAR)Prepch;                                         //~vb2CI~
        *pcd=0;                                                    //~va8kI~
        if (len<=1)                                                //~va8kR~
            break;                                                 //~va8kI~
        if (*(pcd+1)==UDBCSCHK_DBCS1ST)                            //~va8kI~
        {                                                          //~va8wI~
            rc|=XEEBCSDSRC_REPSO;                                  //~va8wR~
            *pc=CHAR_SO;                                           //~va8kI~
        }                                                          //~va8wI~
        else                                                       //~va8kI~
        if (*(pc+1)==CHAR_SI)                                      //~va8kI~
//          *(pc+1)=Prepch;                                        //~va8kI~//~vb2CR~
            *(pc+1)=(UCHAR)Prepch;                                 //~vb2CI~
    	break;                                                     //~va8kI~
    default:                                                     //~va8kI~//~va8wR~
	    if (Popt & XEEBCSDSO_HALFCUTONLY)  //rep half cut only     //~va8wI~
        	break;                                                 //~va8wI~
	    if (Popt & XEEBCSDSO_HALFCUTONLYL) //rep half cut only     //~va8wI~
        	break;                                                 //~va8wI~
        if (*pc==CHAR_SI)                                        //~va8kI~//~va8wR~
        {                                                        //~va8kI~//~va8wR~
	    	if (!(Popt & XEEBCSDSO_PREV2ND))  //prev is dbcs2nd    //~va8wI~
            	break;                                             //~va8wI~
            rc=1;       //shrinked                               //~va8kI~//~va8wR~
//          *pc=Prepch;                                          //~va8kI~//~va8wR~//~vb2CR~
            *pc=(UCHAR)Prepch;                                     //~vb2CI~
        }                                                        //~va8kI~//~va8wR~
    }//left inner boundary                                         //~va8kI~
    return rc;                                                     //~va8kI~
}//xeebc_setdbcssplitsetsosiL                                      //~va8kI~
//**************************************************               //~va8sR~
//*get replace count at left inner boundary                        //~va8wR~
//*rc:replace count                                                //~va8wR~
//**************************************************               //~va8sR~
int xeebc_getdbcssplitctrL(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos)//~va8sR~
{                                                                  //~va8sR~
	UCHAR *pc,*pcd;                                                //~va8sR~
    int rc=0,len;                                                  //~va8sR~
    int sosictr=0;                                                 //~va8wR~
//*************                                                    //~va8sR~
    len=Plen-Ppos;                                                 //~va8sR~
	if (len<=0)                                                    //~va8sR~
    	return 0;                                                  //~va8sR~
    pc=Pdata+Ppos;                                                 //~va8sR~
    pcd=Pdbcs+Ppos;                                                //~va8sR~
    switch(*pcd)                                                   //~va8sR~
    {                                                              //~va8sR~
    case UDBCSCHK_DBCS1ST:                                         //~va8sR~
        if (Popt & XEEBCSDSO_HALFCUTONLY)  //rep half cut only     //~va8sR~//~va8wR~
        	break;                                                 //~va8sR~//~va8wR~
//      if ((Ppos && *(pcd-1)==UDBCSCHK_DBCS2ND)                    //~va8sR~//~va8wR~
//      ||   (Popt & XEEBCSDSO_PREV2ND)  //prev is dbcs2nd         //~va8wR~
//      )                                                          //~va8wR~
//        if (Popt & XEEBCSDSO_HALFCUTONLY)  //rep half cut only   //~va8wR~
//      	break;        //set SO                                 //~va8sR~//~va8wR~
        rc++;                                                      //~va8sR~
        if (len<=1)                                                //~va8sR~
            break;                                                 //~va8sR~
        rc++;             //rep 1 & 2                              //~va8sR~
    	if (len<=2)                                                //~va8sR~
            break;                                                 //~va8sR~
//      if (*(pcd+1)==UDBCSCHK_DBCS1ST)                            //~va8sR~//~va8wR~
        if (*(pcd+2)==UDBCSCHK_DBCS1ST)                            //~va8wI~
        {                                                          //~va8wI~
            sosictr++;                                             //~va8wI~
            rc--;         //set SO                                 //~va8sR~//~va8wR~
        }                                                          //~va8wI~
        else                                                       //~va8sR~
//      if (*(pc+1)==CHAR_SI)                                      //~va8sR~//~va8wR~
        if (*(pc+2)==CHAR_SI)                                      //~va8wI~
            rc++;                                                  //~va8sR~
    	break;                                                     //~va8sR~
    case UDBCSCHK_DBCS2ND:                                         //~va8sR~
        rc++;                                                      //~va8sR~
        if (len<=1)                                                //~va8sR~
            break;                                                 //~va8sR~
        if (*(pcd+1)==UDBCSCHK_DBCS1ST)                            //~va8sR~
        {                                                          //~va8wI~
            rc--;       //set SI                                   //~va8sR~//~va8wR~
            sosictr++;                                             //~va8wI~
        }                                                          //~va8wI~
        else                                                       //~va8sR~
        if (*(pc+1)==CHAR_SI)                                      //~va8sR~
            rc++;                                                  //~va8sR~
    	break;                                                     //~va8sR~
    default:                                                       //~va8wI~
        if (*pc==CHAR_SI)                                          //~va8wI~
        {                                                          //~va8wI~
	        if ((Ppos && *(pcd-1)==UDBCSCHK_DBCS2ND)               //~va8wI~
    	    ||   (Popt & XEEBCSDSO_PREV2ND)  //prev is dbcs2nd     //~va8wI~
            )                                                      //~va8wI~
            	rc++;                                              //~va8wI~
        }                                                          //~va8wI~
    }//left inner boundary                                         //~va8sR~
//  return rc;                                                     //~va8sR~//~va8wR~
    return rc+sosictr;                                             //~va8wR~
}//xeebc_getdbcssplitctrL                                          //~va8sR~
//**************************************************               //~va8kI~
//*set sio/si for inner boundary for dbcssplit                     //~va8kI~
//*rc:1 split detected                                             //~va8kI~
//**************************************************               //~va8kI~
int xeebc_setdbcssplitsetsosi(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Prepch)//~va8kI~
{                                                                  //~va8kI~
    int rc=0;                                                      //~va8kI~
//*************                                                    //~va8kI~
	if (Popt & XEEBCSDSO_GETSPLITCTR)                              //~va8sR~
    {                                                              //~va8sR~
		rc=xeebc_getdbcssplitctrL(Popt,Pdata,Pdbcs,Plen,0/*pos*/); //~va8sR~
        return rc;                                                 //~va8sR~
    }                                                              //~va8sR~
	rc|=xeebc_setdbcssplitsetsosiL(Popt,Pdata,Pdbcs,Plen,0/*pos*/,Prepch);//~va8kR~
	rc|=xeebc_setdbcssplitsetsosiR(Popt,Pdata,Pdbcs,Plen,Prepch);  //~va8kI~
    return rc;                                                     //~va8kI~
}//xeebc_setdbcssplitsetsosi                                       //~va8kI~
//**************************************************               //~va8kI~
//*set sio/si for inner boundary for dbcssplit                     //~va8kI~
//*rc:1 split detected                                             //~va8kI~
//**************************************************               //~va8kI~
int xeebc_setdbcssplitsetsosiOB(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos,int Prangelen,int Prepch)//~va8kR~
{                                                                  //~va8kI~
    int rc=0,pos2,optR=0,optL=0;                                                      //~va8kR~//~va8wR~
//*************                                                    //~va8kI~
    pos2=Ppos+Prangelen;                                           //~va8wI~
    if (Popt & XEEBCSDSOBO_NOSOSIDBCSCONCAT)                       //~va8wI~
    {                                                              //~va8wI~
        if (Ppos<Plen)                                             //~va8wR~
        {                                                          //~va8wI~
        	if (*(Pdbcs+Ppos)==UDBCSCHK_DBCS1ST)                   //~va8wR~
	            optR|=XEEBCSDSO_NEXT1ST;    //right ob is dbcs1st  //~va8wR~
        	if (*(Pdata+Ppos)==CHAR_SI)                            //~va8wI~
	            optR|=XEEBCSDSO_NEXTSI;    //right ob is dbcs1st   //~va8wI~
        }                                                          //~va8wI~
        if (pos2<Plen                                              //~va8wI~
        &&  pos2>0                                                 //~va8wI~
        )                                                          //~va8wI~
        {                                                          //~va8wI~
        	if (*(Pdbcs+pos2-1)==UDBCSCHK_DBCS2ND)                 //~va8wR~
            	optL|=XEEBCSDSO_PREV2ND;    //left ob is dbcs2nd   //~va8wR~
        	if (*(Pdata+pos2-1)==CHAR_SO)                          //~va8wI~
            	optL|=XEEBCSDSO_PREVSO;    //left ob is dbcs2nd    //~va8wI~
        }                                                          //~va8wI~
    }                                                              //~va8wI~
	rc|=xeebc_setdbcssplitsetsosiR(optR,Pdata,Pdbcs,Ppos,Prepch);   //change before left boundary//~va8kI~//~va8wR~
	rc|=xeebc_setdbcssplitsetsosiL(optL,Pdata,Pdbcs,Plen,pos2,Prepch);//~va8kR~//~va8wR~
    return rc;                                                     //~va8kI~
}//xeebc_setdbcssplitsetsosiOB                                     //~va8kI~
//**************************************************               //~va8kI~
//*length for dbcssplit                                            //~va8kI~
//*rc:1 shrink,2:append SI,3:SI overwrap to next dbcs1st           //~va8wR~
//**************************************************               //~va8kI~
int xeebc_dbcssplitlen(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Ppos,int *Ppsplitlen)//~va8kR~
{                                                                  //~va8kI~
	UCHAR *pc,*pcd;                                                //~va8kI~
    int rc=0,cutlen=0,splitlen/*,explen=0*/;                           //~va8kR~//~vaa7R~
//*************                                                    //~va8kI~
	if (Ppos<=0)                                                   //~va8kR~
    	return 0;                                                  //~va8kI~
    pc=Pdata+Ppos-1;                                               //~va8kR~
    pcd=Pdbcs+Ppos-1;                                              //~va8kR~
    switch(*pcd)                                                   //~va8kI~
    {                                                              //~va8kI~
    case UDBCSCHK_DBCS1ST:                                         //~va8kI~
        if (pc>Pdata && *(pc-1)==CHAR_SO)                          //~va8kI~
        {                                                          //~va8kI~
        	rc=1; 	//shrink                                       //~va8kI~
        	cutlen=2;                                              //~va8kR~
        }                                                          //~va8kI~
        else                                                       //~va8kI~
        {                                                          //~va8kI~
    		rc=2;        	//append SI                            //~va8kR~
    		cutlen=1;                                              //~va8kR~
        }                                                          //~va8kI~
//    	explen=1;                                                  //~va8kR~//~vaa7R~
    	break;                                                     //~va8kI~
    case UDBCSCHK_DBCS2ND:                                         //~va8kI~
    	if (Popt & XEEBCDSLO_EXPANDABLE)                           //~va8kR~
        {                                                          //~va8kI~
        	rc=2;	//appendSI;                                    //~va8kI~
            break;                                                 //~va8kI~
        }                                                          //~va8kI~
    	if (Popt & XEEBCDSLO_IRB2NDOK)                             //~va8wM~
        {                                                          //~va8wM~
	    	if (Popt & XEEBCDSLO_SIFOLLOWS)                        //~va8wM~
            	rc=3;                                              //~va8wM~
            break;                                                 //~va8wM~
        }                                                          //~va8wM~
        if (pc-1>Pdata && *(pc-2)==CHAR_SO)                        //~va8kI~
        {                                                          //~va8kI~
            cutlen=3;                                              //~va8kI~
            rc=1;   //shrink                                       //~va8kI~
        }                                                          //~va8kI~
        else                                                       //~va8kI~
        {                                                          //~va8kI~
            cutlen=2;                                              //~va8kI~
            rc=2;   //appendSI;                                    //~va8kR~
        }                                                          //~va8kI~
    	break;                                                     //~va8kI~
    default:                                                       //~va8kI~
    	if (*pc==CHAR_SO)                                          //~va8kI~
        {                                                          //~va8kI~
        	cutlen=1;                                              //~va8kR~
            rc=1;       //shrinked                                 //~va8kR~
        }                                                          //~va8kI~
    }//left of boundary                                            //~va8kR~
    splitlen=max(Ppos-cutlen,0);                                   //~va8kR~
    if (splitlen>0 && *(Pdbcs+splitlen-1)==CHAR_SO)                //~va8kI~
    {                                                              //~va8kI~
    	splitlen--;                                                //~va8kR~
    	rc=1;	     //no append SI                                //~va8kI~
    }                                                              //~va8kI~
    if (splitlen==1)                                               //~va8kI~
	    if (*Pdbcs||*Pdata==CHAR_SO||*Pdata==CHAR_SI)              //~va8kI~
        {	                                                       //~va8kI~
	    	splitlen--;  //0                                       //~va8kI~
    		rc=1;	     //no append SI                            //~va8kI~
        }                                                          //~va8kI~
    *Ppsplitlen=splitlen;                                          //~va8kR~
    UTRACEP("xeebc_dbcssplitlen inplen=%d,splitlen=%d,rc=%d\n",Ppos,splitlen,rc);//~va8kR~
    return rc;                                                     //~va8kI~
}//xeebc_dbcssplitlen                                              //~va8kI~
//**************************************************               //~va8bI~
//*xeebc_filesetsosistr                                            //~va8bI~
//*insert so/si for charcap rep/ins                                //~va8bI~
//*rc:UALLOC_FAILED                                                //~va8bI~
//**************************************************               //~va8bI~
int xeebc_filesetsosistr(int Popt,UCHAR *Ptgtdata,UCHAR *Ptgtdbcs,int Ptgtlen,int Ppos,//~va8bR~
					UCHAR *Psrcdata,UCHAR *Psrcdbcs,int Psrclen,   //~va8bI~
                    UCHAR *Poutsrcdata,UCHAR *Poutsrcdbcs,int *Ppoutsrclen)//~va8bI~
{                                                                  //~va8bI~
    UCHAR   *pcs,*pcsd,*pcse,*pcsde,*pct,*pctd,*poutsrcdata,*poutsrcdbcs;//~va8bI~
    int sosiopt=0,srclen,swtopdbcs,swenddbcs,addlen,tailpos;       //~va8bI~
//*************                                                    //~va8bI~
    pct=Ptgtdata+Ppos;                                             //~va8bI~
    pctd=Ptgtdbcs+Ppos;                                            //~va8bI~
                                                                   //~va8bI~
    srclen=Psrclen;                                                //~va8bI~
    if (srclen<=0)                                                 //~va8bI~
    	return 0;                                                  //~va8bI~
    pcs=Psrcdata;                                                  //~va8bI~
    pcsd=Psrcdbcs;                                                 //~va8bI~
    pcse=pcs+srclen-1;                                             //~va8bI~
    pcsde=pcsd+srclen-1;                                           //~va8bI~
                                                                   //~va8bI~
    swtopdbcs=0;                                                   //~va8bI~
    swenddbcs=0;                                                   //~va8bI~
//chk src top                                                      //~va8bI~
    if (*pcsd==UDBCSCHK_DBCS1ST)                                   //~va8bI~
        swtopdbcs=1;                                               //~va8bI~
    else                                                           //~va8bI~
    if (*pcs==CHAR_SO                                              //~va8bI~
    &&   srclen>1                                                  //~va8bI~
    &&  *(pcsd+1)==UDBCSCHK_DBCS1ST                                //~va8bI~
    )                                                              //~va8bI~
    {                                                              //~va8bI~
        pcs++;                                                     //~va8bI~
        pcsd++;                                                    //~va8bI~
        srclen--;                                                  //~va8bI~
        swtopdbcs=2;                                               //~va8bI~
    }                                                              //~va8bI~
//chk src end                                                      //~va8bI~
    if (*pcsde==UDBCSCHK_DBCS2ND)                                  //~va8bI~
        swenddbcs=1;                                               //~va8bR~
    else                                                           //~va8bI~
    if (*pcse==CHAR_SI                                             //~va8bI~
    &&   srclen>1                                                  //~va8bI~
    &&  *(pcsde-1)==UDBCSCHK_DBCS2ND                               //~va8bI~
    )                                                              //~va8bI~
    {                                                              //~va8bI~
        pcse--;                                                    //~va8bI~
        pcsde--;                                                   //~va8bI~
        srclen--;                                                  //~va8bI~
        swenddbcs=2;                                               //~va8bI~
    }                                                              //~va8bI~
UTRACED("dropsosi src",pcs,srclen);                                //~va8bI~
    addlen=0;                                                      //~va8bI~
//*head                                                            //~va8bI~
    if (swtopdbcs)  //isrt top is dbcs                             //~va8bI~
    {                                                              //~va8bI~
        if (!Ppos                          //to top                //~va8bI~
        ||  Ppos>=Ptgtlen                  //after tail            //~va8bI~
        ||  *(pct-1)==CHAR_SI              //after SI              //~va8bI~
        ||  (*(pctd-1)==0 && *(pct-1)!=CHAR_SO)  //after sbcs(not SO)//~va8bI~
        )                                                          //~va8bI~
        {                                                          //~va8bI~
            sosiopt|=XEEBCSW_INSSO; //insert SO                    //~va8bI~
            addlen++;				//to calc rep endpos           //~va8bI~
        }                                                          //~va8bI~
    }                                                              //~va8bI~
    else    //isrt head is sbcs                                    //~va8bI~
    {                                                              //~va8bI~
        if  (Ppos && Ppos<Ptgtlen)  //into tgt str                 //~va8bI~
        {                                                          //~va8bI~
            if (*(pct-1)==CHAR_SO)                                 //~va8bI~
                sosiopt|=XEEBCSW_PREV2SPACE;  //rep previous SO to space//~va8bI~
            else                                                   //~va8bI~
            if (*(pctd-1)==UDBCSCHK_DBCS2ND)     //prev is DBCS    //~va8bI~
            {                                                      //~va8bI~
                if (*pcs!=CHAR_SI)                                 //~va8bI~
                {                                                  //~va8bI~
                    sosiopt|=XEEBCSW_INSSIHEAD; //insert SI        //~va8bI~
		            addlen++;				//to calc rep endpos   //~va8bI~
                }                                                  //~va8bI~
            }                                                      //~va8bI~
        }                                                          //~va8bI~
    }                                                              //~va8bI~
//*tail                                                            //~va8bI~
    if (Popt & XEEBCSO_CAPINS)                                     //~va8bR~
    {                                                              //~va8bI~
//*INS tail                                                        //~va8bI~
        if (swenddbcs)  //isrt tail is dbcs                        //~va8bI~
        {                                                          //~va8bI~
            if (Ppos>=Ptgtlen)                                     //~va8bR~
            {                                                      //~va8bI~
                sosiopt|=XEEBCSW_INSSI; //insert SI                //~va8bR~
            }                                                      //~va8bI~
            else                                                   //~va8bI~
            if (*(pctd)==0)          //next is sbcs including SO/SI//~va8bI~
            {                                                      //~va8bI~
            	if (*pct!=CHAR_SI)                                 //~va8bI~
                	sosiopt|=XEEBCSW_INSSI; //insert SI            //~va8bI~
            }                                                      //~va8bI~
        }                                                          //~va8bI~
        else    //isrt tail is sbcs                                //~va8bI~
        {                                                          //~va8bI~
            if  (Ppos<Ptgtlen)                                     //~va8bI~
            {                                                      //~va8bI~
            	if (*pct==CHAR_SI)                                 //~va8bI~
                	sosiopt|=XEEBCSW_NEXT2SPACE; //rep next SI to space//~va8bI~
				else                                               //~va8bI~
				if (*(pctd)==UDBCSCHK_DBCS1ST)     //next is DBCS  //~va8bI~
                {                                                  //~va8bI~
                	if (*pcse!=CHAR_SO)                            //~va8bI~
                		sosiopt|=XEEBCSW_INSSOTAIL; //insert SO at tail//~va8bI~
                }                                                  //~va8bI~
            }                                                      //~va8bI~
        }                                                          //~va8bI~
	}//ins                                                         //~va8bI~
    else                                                           //~va8bI~
    {                                                              //~va8bI~
//*REP tail                                                        //~va8bI~
        pct+=srclen+addlen;    //addlen:top SO,1:tail SI           //~va8bI~
        pctd+=srclen+addlen;                                       //~va8bI~
        tailpos=Ppos+srclen+addlen;                                //~va8bI~
        if (swenddbcs)  //isrt tail is dbcs                        //~va8bI~
        {                                                          //~va8bI~
            if (tailpos>=Ptgtlen                                   //~va8bI~
            ||  *pctd!=UDBCSCHK_DBCS1ST                            //~va8bI~
            )                                                      //~va8bI~
                sosiopt|=XEEBCSW_INSSI; //insert SI                //~va8bI~
        }                                                          //~va8bI~
        else    //isrt tail is sbcs                                //~va8bI~
        {                                                          //~va8bI~
            if (*pcse!=CHAR_SO)                                    //~va8bI~
            {                                                      //~va8bI~
	        	pct++;                                             //~va8bI~
        		pctd++;                                            //~va8bI~
        		tailpos++;                                         //~va8bI~
            	if (tailpos<Ptgtlen)                               //~va8bI~
					if (*(pctd)==UDBCSCHK_DBCS1ST)     //next is DBCS//~va8bI~
                		sosiopt|=XEEBCSW_INSSOTAIL; //insert SO ater src//~va8bI~
            }                                                      //~va8bI~
        }                                                          //~va8bI~
    }//rep                                                         //~va8bI~
UTRACEP("dropsosi pos=%d,sosiopt=%x,swtopdbcs=%d,swenddbcs=%d\n",Ppos,sosiopt,swtopdbcs,swenddbcs);//~va8bI~
    addlen=0;                                                      //~va8bI~
    poutsrcdata=Poutsrcdata;                                       //~va8bI~
    poutsrcdbcs=Poutsrcdbcs;                                       //~va8bI~
    if (sosiopt & XEEBCSW_INSSO)                                   //~va8bI~
    {                                                              //~va8bI~
    	*poutsrcdata++=CHAR_SO;                                    //~va8bI~
    	*poutsrcdbcs++=0;                                          //~va8bI~
        addlen++;                                                  //~va8bI~
    }                                                              //~va8bI~
    if (sosiopt & XEEBCSW_INSSIHEAD)                               //~va8bI~
    {                                                              //~va8bI~
    	*poutsrcdata++=CHAR_SI;                                    //~va8bI~
    	*poutsrcdbcs++=0;                                          //~va8bI~
        addlen++;                                                  //~va8bI~
    }                                                              //~va8bI~
//  memcpy(poutsrcdata,pcs,srclen);                                //~va8bI~//~vb2DR~
    memcpy(poutsrcdata,pcs,(size_t)srclen);                        //~vb2DI~
//  memcpy(poutsrcdbcs,pcsd,srclen);                               //~va8bI~//~vb2DR~
    memcpy(poutsrcdbcs,pcsd,(size_t)srclen);                       //~vb2DI~
    poutsrcdata+=srclen;                                           //~va8bI~
    poutsrcdbcs+=srclen;                                           //~va8bI~
    if (sosiopt & XEEBCSW_INSSI)                                   //~va8bI~
    {                                                              //~va8bI~
    	*poutsrcdata++=CHAR_SI;                                    //~va8bI~
    	*poutsrcdbcs++=0;                                          //~va8bI~
        addlen++;                                                  //~va8bI~
    }                                                              //~va8bI~
    if (sosiopt & XEEBCSW_INSSOTAIL)                               //~va8bI~
    {                                                              //~va8bI~
    	*poutsrcdata++=CHAR_SO;                                    //~va8bI~
    	*poutsrcdbcs++=0;                                          //~va8bI~
        addlen++;                                                  //~va8bI~
    }                                                              //~va8bI~
    *Ppoutsrclen=srclen+addlen;                                    //~va8bI~
    return sosiopt;                                                //~va8bI~
}//xeebc_filesetsosi                                               //~va8bI~
#endif //UTF8EBCS raw ebcdic file support
