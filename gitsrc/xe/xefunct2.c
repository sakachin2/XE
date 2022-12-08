//*CID://+vbvxR~:                             update#=  516;       //+vbvxR~
//*************************************************************
//*xefunct2.c
//* graphic char setup
//*************************************************************
//vbvx:221203 =0.2;not err but "No file" when xelinechxx is not found//+vbvxI~
//vbvt:221202 =0.2/=0.3 display code itself for default box char for japanese//~vbvtI~
//vbvi:221130 (BUG)FTFLINECHSET:x20 is duplicated with DTUDUPACMD  //~vbviI~
//vbve:221126 change Default SJIS linechar from old(<0x20) to DBCS //~vbveI~
//vbvd:221125 on 0.2/0.3 display hex/sjis string by utf8 avoiding line err(lineno green)//~vbvdI~
//vbvc:221125 functbl search miss to search english linechar because same funcid//~vbvcI~
//vbvb:221125 opt 0.2/0.3 as utf8 file for utf8 graphic char display//~vbvbI~
//vbv7:221123 set default line char by utf8 when Shift+            //~vbv7I~
//vb7r:170127 (Bug)crush by bug of ulib:v6Hv(Slocale was corrupted)//~vb7rI~
//vb47:160722 treate col1="#" as comment line of linech.ini        //~vb47I~
//vb46:160722 issue warning linech.ini was used                    //~vb46I~
//vb2D:160221 LNX compiler warning                                 //~vb2uI~
//vb2A:160212 fkt;protect buff overflow                            //~vb2AI~
//vb2y:160212 save xelch utf8 for errmsg                           //~vb2yI~
//vb2x:160212 xelchxxx:chk "//" as end of line                     //~vb2xI~
//vb2u:160207 support utf8 input by xelchxxx(LineDrawChar file) by prefix uxxyy,xxyyzz u//~vb2uI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//va16:091024_setlocale should not used to avoid reset to system default//~va16I~
//va0B:090721_(LNX:BUG) "OPT LINECH ON" warning dose not sto at 3 times//~va0BI~
//v79W:081029 no dbcs chk required for 1 byte acs because setdbcs will be done later if hex notation by v79R//~v79SI~
//v79S:081027 (BUG)missing "linech parameter dbcs chk" for 2nd word//~v79SI~
//v79R:081027 (BUG)dbcs evaluation required when graphic char input specification is by hex notation//~v79RI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v70m:060811 (Win)change graph key input by Shift key not by opt linech on/off//~v70mI~
//v70g:060801*(BUG:XXE)lnx use acs console is version only         //~v70gI~
//v70d:060731 change "OPT LINECH RELOAD" function to reload default file not current file//~v70dI~
//v705:060727 NEW:graphic char setup by external file(2 string for opt linech on/off)//~v70dR~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//**************************************************************
#ifdef LNX
	#include <locale.h>
#endif
#ifdef OS2                                                         //~v70mI~
	#define INCL_BASE                                              //~v70mI~
	#include <os2.h>                                               //~v70mI~
#endif                                                             //~v70mI~
//*******************************************************
#include <uque.h>
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <udbcschk.h>
#include <ustring.h>
#include <ufile.h>
#include <uedit.h>
#include <uedit2.h>
#include <uparse.h>
#include <ukbd.h>                                                  //~v70mI~
#include <utrace.h>                                                //~v79RI~
#include <ucvucs.h>                                                //~vb2uI~
#include <ucvext.h>                                                //~vb2uI~
#include <utf.h>                                                   //~vb2uI~

#include "xe.h"
#include "xescr.h"
#include "xefunc.h"
#include "xefunct.h"
#include "xefile.h"                                                //~v74xI~
#include "xesub.h"
#include "xesub2.h"                                                //~va16I~
#include "xeutf.h"                                                 //~vb2uI~
#include "xeutf2.h"                                                //~vb2uI~
//**************************************************
#define LINECHFILE   "xelch"
//#define GRAPH_ENGLISH "(E)"                                      //~vbveR~

//**************************************************
//**************************************************
#ifdef XXEACS
#ifdef XXE
	int funct2utf8init(void);
#endif
#endif
int funct2setuplinech(char *Pbuff);
int funct2fmterr(char *Ppc);
int funct2getnextinputgcUTF8(PUCLIENTWE Ppcw,char *Pinput,void *Ppkeyinf);//~vb2uI~
int funct2kbdsimutf8(int Popt,char *Putf8,int Plen,PKBDKEYINFO Ppkinfo);//~vb2uI~
int funct2saveforerrmsg(int Popt,PUCLIENTWE Ppcw,char *Ppu8,int Pu8len);//~vb2uI~
int funct2utf8init_DefaultShift(void);                             //~vbv7I~
//static	char Sdefaultfnm[32]=WORKDIRPATHID LINECHFILE;         //~vb7rR~
static	char Sdefaultfnm[64]=WORKDIRPATHID LINECHFILE;             //~vb7rI~
static	char Slinechfnm[_MAX_PATH];
static  int  Slinechferr;
static  int  Sstrinputbyhexsw;                                     //~v79RI~
static  int  Sstrinputbyu8sw;                                      //~vb2uI~
static  LINECHTB Slchtb[GRAPHKEYENTNO];
//**************************************************
//*init
//  inifile naming  xelch__.ini[.locale] :locale is for lineux
//        xxx: gxe/wxe
//        us: when /N9
//*parm: none
//*return:none
//**************************************************
int funct2init(int Popt,char *Pinifnm)
{
	char fpath[_MAX_PATH];
	char fnm[_MAX_PATH];
    FILE *fh;
    int errline,lno,len;
    char buff[1024];
#ifdef LNX                                                         //~va16I~
    #ifdef UTF8SUPPH                                               //~va16I~
	    char *pc,*pc2;                                             //~va16I~
    #endif                                                         //~va16I~
#endif                                                             //~va16I~
//************************************
	Slinechferr=1;
    if (Popt)
    {
        if (stricmp(Pinifnm,FUNCT_RELOAD))
        	strcpy(fnm,Pinifnm);
        else
//      	strcpy(fnm,Slinechfnm);                                //~v70dR~
        	strcpy(fnm,Sdefaultfnm);                               //~v70dI~
    }
    else        //initial
    {
#ifdef LNX
    #ifdef UTF8SUPPH                                               //~va16I~
        pc=udbcschk_setlocale(UDCSLO_GETENV,LC_ALL,"");            //~va16I~
        pc2=strchr(pc,'.');	//get locale code                      //~va16I~
        if (pc2)                                                   //~va16I~
        	len=(int)((ULONG)pc2-(ULONG)pc);                       //~va16I~
        else                                                       //~va16I~
//        	len=strlen(pc);                                        //~va16R~//~vb2uR~
          	len=(int)strlen(pc);                                   //~vb2uI~
    	sprintf(fnm,"%s%s.ini.%*.*s",Sdefaultfnm,Pinifnm,len,len,pc);//~va16R~
    #else                                                          //~va16I~
    	sprintf(fnm,"%s%s.ini.%s",Sdefaultfnm,Pinifnm,setlocale(LC_ALL,""));
    #endif                                                         //~va16I~
#else
    	sprintf(fnm,"%s%s.ini",Sdefaultfnm,Pinifnm);//fnm:ostype
#endif
//      strcpy(Sdefaultfnm,fnm);                                   //~vb7rR~
//  	strcpy(Slinechfnm,fnm);	//selected file                    //~vb7rR~
        UstrncpyZ(Sdefaultfnm,fnm,sizeof(Sdefaultfnm));            //~vb7rR~
    	UstrncpyZ(Slinechfnm,fnm,sizeof(Slinechfnm));	           //~vb7rI~
    }
	if (!Popt)	//initial start
    {
#ifdef XXEACS
#ifdef XXE
    	funct2utf8init();
#endif
#endif
        ;                                                          //~v70mI~
    	funct2utf8init_DefaultShift();                             //~vbv7I~
	}
//*open parm file
    filefullpath(fpath,fnm,sizeof(fpath));
    if (!(fh=fopen(fpath,"r")))
    {
        if (Popt)	//not init
    		uerrmsg("LINECH file(%s) not found",0,
    					fnm);
		Slinechferr=2;                                             //+vbvxI~
        return 0;
    }
	strcpy(Slinechfnm,fnm);	//selected file
//*get linech parm
	for (lno=1,errline=0;;lno++)
    {
		if (!fgets(buff,sizeof(buff),fh))
        	break;
        if (*buff=='/' && *(buff+1)=='/')	// "//" is stopper
        	break;
        len=(int)strlen(buff);                                     //~v70mR~
        if (len && *(buff+len-1)=='\n')   //drop crlf
        	*(buff+--len)=0;
        if (len && *(buff+len-1)=='\r')   //drop crlf
        	*(buff+--len)=0;
        if (funct2setuplinech(buff))
            errline=lno;                //last err line

    }
    fclose(fh);
    if (errline)
    {
        uerrmsgcat(";err at line %d on %s",0,
                    errline,fnm);
        return 4;
    }
    else
    {
	    if (Popt)
        	uerrmsgcat("%s processed;to see result re-open =0.2 list",
        	           "%s を処理しました。結果は =0.2 を再オープンして確認してください",
                    	fnm);
    }
	Slinechferr=0;
    UTRACED("funct2init Slchtb",Slchtb,sizeof(Slchtb));            //~vbv7I~
    return 1;
}//funct2init
//**************************************************
//*set filename to end of file line of 0.2 list
//**************************************************
int funct2getfnm(char *Pout,int Plen)
{
	char *pout,*pc;
	int len,rlen;
//************************
	pout=Pout;
	rlen=Plen;
    pc=" * linech-file = ";
    len=(int)strlen(pc);
    if (len>=rlen)
    	return 4;
    memcpy(pout,pc,(UINT)len);
    pout+=len; rlen-=len;
    pc=Slinechfnm;
    len=(int)strlen(pc);                                           //~v70mR~
    if (len<=rlen)
    {
    	memcpy(pout,pc,(UINT)len);
	    pout+=len; rlen-=len;
        if (Slinechferr==2)	//err                                  //+vbvxI~
        	pc=" * NoFile ";                                       //+vbvxI~
        else                                                       //+vbvxI~
        if (Slinechferr)	//err
        	pc=" * ERR ";
        else
        	pc=" * OK  ";
    	len=(int)strlen(pc);                                       //~v70mR~
	    if (len<=rlen)
    	{
        	memcpy(pout,pc,(UINT)len);                             //~v70mR~
   		}
        return 0;
    }
    memcpy(pout,pc+len-rlen,(UINT)rlen);
    return 1;		//cut
}//funct2getfnm
#ifdef XXEACS
#ifdef XXE
//**************************************************
//*setup default utf8 display code for GXE               *         //~vbv7R~
//**************************************************
int funct2utf8init(void)
{
	UCHAR *graphchutfcode[GRAPHKEYENTNO]={
    			"\xe2\x94\x94", 	//1 :LLC low,left ,corner
    			"\xe2\x94\xb4", 	//2 :LHS low,horz ,stopper
    			"\xe2\x94\x98", 	//3 :LRC low,right,corner
    			"\xe2\x94\x9c", 	//4 :LVS low,vert ,stopper
    			"\xe2\x94\xbc", 	//5 :CX  center
    			"\xe2\x94\xa4", 	//6 :RVS rig,vert ,stopper
    			"\xe2\x94\x8c", 	//7 :ULC up ,left ,corner
    			"\xe2\x94\xac", 	//8 :UHS up ,horz ,stopper
    			"\xe2\x94\x90", 	//9 :URC up ,right,corner
    			"\xe2\x94\x80", 	//10:HL      horz ,line
    			"\xe2\x94\x82"}; 	//11:VL      vert ,line
	int funcid,ii,len;
    PLINECHTB plcht;
    FUNCTBL *pft;
//****************
	plcht=Slchtb;
	for (ii=0,funcid=FUNCID_GRAPHCHAR+1;funcid<=FUNCID_GRAPHCHAR_VL;funcid++,ii++,plcht++)
    {
  		pft=functblsrch(funcid);
    	if (!pft)
			continue;
//      if (UCBITCHK(pft->FTflag,FTFLINECHSET))                    //~vbviR~
        if (UCBITCHK(pft->FTflag2,FTF2LINECHSET))                  //~vbviR~
            continue;
//      UCBITON(pft->FTflag,FTFLINECHSET);                         //~vbviR~
        UCBITON(pft->FTflag2,FTF2LINECHSET);                       //~vbviR~
        UTRACEP("%s:set FTF2LINECHSET namee=%s\n",UTT,pft->FTnamee);//~vbvcR~//~vbviR~
        len=strlen(graphchutfcode[ii]);
	    plcht->LCTonoff[0].LCSflag|=LCSFHEXDATA;
        plcht->LCTonoff[0].LCSlen=len;
        memcpy(plcht->LCTonoff[0].LCSdata,graphchutfcode[ii],(UINT)len);
                                                                   //~vbvcI~
  		pft=functblsrch2nd(funcid,pft);                            //~vbvcI~
    	if (!pft)                                                  //~vbvcI~
			continue;                                              //~vbvcI~
//      if (UCBITCHK(pft->FTflag,FTFLINECHSET))                    //~vbvcI~//~vbviR~
        if (UCBITCHK(pft->FTflag2,FTF2LINECHSET))                  //~vbviI~
            continue;                                              //~vbvcI~
//      UCBITON(pft->FTflag,FTFLINECHSET);                         //~vbvcI~//~vbviR~
        UCBITON(pft->FTflag2,FTF2LINECHSET);                       //~vbviI~
        UTRACEP("%s:set FTF2LINECHSET namee=%s\n",UTT,pft->FTnamee);//~vbvcR~//~vbviR~
    }
    return 0;
}//funct2utf8init
#endif
#endif
//**************************************************               //~vbveI~
//*setup default utf8 display code   //doble line char             *//~vbveI~
//**************************************************               //~vbveI~
int funct2utf8init_DefaultShiftDBCS(void)                          //~vbveI~
{                                                                  //~vbveI~
	UCHAR *graphchutfcodeDBCS[GRAPHKEYENTNO]={                     //~vbveR~
#ifdef LNX               //by EUCJP                                //~vbveI~
    			"\xa8\xb1", 	//1 :LLC low,left ,corner          //~vbveR~
    			"\xa8\xb5", 	//2 :LHS low,horz ,stopper         //~vbveI~
    			"\xa8\xb0", 	//3 :LRC low,right,corner          //~vbveI~
    			"\xa8\xb2", 	//4 :LVS low,vert ,stopper         //~vbveI~
    			"\xa8\xb6", 	//5 :CX  center                    //~vbveI~
    			"\xa8\xb4", 	//6 :RVS rig,vert ,stopper         //~vbveI~
    			"\xa8\xae", 	//7 :ULC up ,left ,corner          //~vbveI~
    			"\xa8\xb3", 	//8 :UHS up ,horz ,stopper         //~vbveI~
    			"\xa8\xaf", 	//9 :URC up ,right,corner          //~vbveI~
    			"\xa8\xac", 	//10:HL      horz ,line            //~vbveI~
    			"\xa8\xad"}; 	//11:VL      vert ,line            //~vbveI~
#else                                                              //~vbveI~
    			"\x84\xaf", 	//1 :LLC low,left ,corner          //~vbveI~
    			"\x84\xb3", 	//2 :LHS low,horz ,stopper         //~vbveI~
    			"\x84\xae", 	//3 :LRC low,right,corner          //~vbveI~
    			"\x84\xb0", 	//4 :LVS low,vert ,stopper         //~vbveI~
    			"\x84\xb4", 	//5 :CX  center                    //~vbveI~
    			"\x84\xb2", 	//6 :RVS rig,vert ,stopper         //~vbveI~
    			"\x84\xac", 	//7 :ULC up ,left ,corner          //~vbveI~
    			"\x84\xb1", 	//8 :UHS up ,horz ,stopper         //~vbveI~
    			"\x84\xad", 	//9 :URC up ,right,corner          //~vbveI~
    			"\x84\xaa", 	//10:HL      horz ,line            //~vbveI~
    			"\x84\xab"}; 	//11:VL      vert ,line            //~vbveI~
#endif                                                             //~vbveI~
	int funcid,ii,len;                                             //~vbveI~
    PLINECHTB plcht;                                               //~vbveI~
    FUNCTBL *pft;                                                  //~vbveI~
//****************                                                 //~vbveI~
	plcht=Slchtb;                                                  //~vbveI~
	for (ii=0,funcid=FUNCID_GRAPHCHAR+1;funcid<=FUNCID_GRAPHCHAR_VL;funcid++,ii++,plcht++)//~vbveI~
    {                                                              //~vbveI~
  		pft=functblsrch(funcid);                                   //~vbveI~
    	if (!pft)                                                  //~vbveI~
			continue;                                              //~vbveI~
//      if (UCBITCHK(pft->FTflag2,FTF2LINECHSET))                    //~vbveR~//~vbviR~
//          continue;                                              //~vbveR~
//      UCBITON(pft->FTflag,FTFLINECHSET);                         //~vbveI~//~vbviR~
        UCBITON(pft->FTflag2,FTF2LINECHSET);                       //~vbviI~
        UCBITON(pft->FTflag3,FTF3LINECHSETJP);                     //~vbvtI~
        UTRACEP("%s:set FTF2LINECHSET namee=%s\n",UTT,pft->FTnamee);//~vbveI~//~vbviR~
        len=2;                                                     //~vbveR~
	    plcht->LCTonoff[0].LCSflag|=LCSFHEXDATA|LCSFSJIS;          //~vbveR~
        plcht->LCTonoff[0].LCSlen=len;                             //~vbveI~
        memcpy(plcht->LCTonoff[0].LCSdata,graphchutfcodeDBCS[ii],(size_t)len);//~vbveR~
		setdbcstbl(plcht->LCTonoff[0].LCSdata,plcht->LCTonoff[0].LCSdbcs,len);//~vbveR~
    }                                                              //~vbveI~
    UTRACED("fuct2utf8init_DefaultShiftDBCS Slchtb",Slchtb,sizeof(Slchtb));//~vbveI~
    return 0;                                                      //~vbveI~
}//funct2utf8init                                                  //~vbveI~
//**************************************************               //~vbv7M~
//*setup default utf8 display code   //doble line char             *//~vbv7M~
//**************************************************               //~vbv7M~
int funct2utf8init_DefaultShift(void)                              //~vbv7M~
{                                                                  //~vbv7M~
	UCHAR *graphchutfcodeU8[GRAPHKEYENTNO]={                       //~vbv7M~
    			"\xe2\x95\x9a", 	//1 :LLC low,left ,corner   u255a//~vbv7M~
    			"\xe2\x95\xa9", 	//2 :LHS low,horz ,stopper  u2569//~vbv7M~
    			"\xe2\x95\x9d", 	//3 :LRC low,right,corner   u255d//~vbv7M~
    			"\xe2\x95\xa0", 	//4 :LVS low,vert ,stopper  u2560//~vbv7M~
    			"\xe2\x95\xac", 	//5 :CX  center             u256c//~vbv7M~
    			"\xe2\x95\xa3", 	//6 :RVS rig,vert ,stopper  u2563//~vbv7M~
    			"\xe2\x95\x94", 	//7 :ULC up ,left ,corner   u2554//~vbv7M~
    			"\xe2\x95\xa6", 	//8 :UHS up ,horz ,stopper  u2566//~vbv7M~
    			"\xe2\x95\x97", 	//9 :URC up ,right,corner   u2557//~vbv7M~
    			"\xe2\x95\x90", 	//10:HL      horz ,line     u2550//~vbv7M~
    			"\xe2\x95\x91"}; 	//11:VL      vert ,line     u2551//~vbv7M~
	int funcid,ii,len;                                             //~vbv7M~
    PLINECHTB plcht;                                               //~vbv7M~
    FUNCTBL *pft;                                                  //~vbv7M~
//****************                                                 //~vbv7M~
	plcht=Slchtb;                                                  //~vbv7M~
	for (ii=0,funcid=FUNCID_GRAPHCHAR+1;funcid<=FUNCID_GRAPHCHAR_VL;funcid++,ii++,plcht++)//~vbv7M~
    {                                                              //~vbv7M~
  		pft=functblsrch(funcid);                                   //~vbv7M~
    	if (!pft)                                                  //~vbv7M~
			continue;                                              //~vbv7M~
//      if (UCBITCHK(pft->FTflag,FTFLINECHSET))                    //~vbv7M~//~vbviR~
        if (UCBITCHK(pft->FTflag2,FTF2LINECHSET))                  //~vbviI~
            continue;                                              //~vbv7M~
//      UCBITON(pft->FTflag,FTFLINECHSET);                         //~vbv7M~//~vbviR~
        UCBITON(pft->FTflag2,FTF2LINECHSET);                       //~vbviI~
        UTRACEP("%s:set FTF2LINECHSET namee=%s\n",UTT,pft->FTnamee);//~vbvcR~//~vbviR~
        len=(int)strlen(graphchutfcodeU8[ii]);                     //~vbv7R~
	    plcht->LCTonoff[1].LCSflag|=LCSFU8DATA;  //1:with +Shift   //~vbv7R~
        len=(int)strlen(graphchutfcodeU8[ii]);                     //~vbv7R~
        plcht->LCTonoff[1].LCSlen=len;                             //~vbv7I~
        memcpy(plcht->LCTonoff[1].LCSdata,graphchutfcodeU8[ii],(size_t)len);//~vbv7R~
		setdbcstbl(plcht->LCTonoff[1].LCSdata,plcht->LCTonoff[1].LCSdbcs,len);//~vbv7R~
        UTRACEP("%s:set FTF2LINECHSET 1st  namee=%s\n",UTT,pft->FTnamee);//~vbveI~//~vbviR~
                                                                   //~vbvcI~
  		pft=functblsrch2nd(funcid,pft);                            //~vbvcI~
    	if (!pft)                                                  //~vbvcI~
			continue;                                              //~vbvcI~
//      if (UCBITCHK(pft->FTflag,FTFLINECHSET))                    //~vbvcI~//~vbviR~
        if (UCBITCHK(pft->FTflag2,FTF2LINECHSET))                  //~vbviI~
            continue;                                              //~vbvcI~
//      UCBITON(pft->FTflag,FTFLINECHSET);                         //~vbvcI~//~vbviR~
        UCBITON(pft->FTflag2,FTF2LINECHSET);                       //~vbviI~
        UTRACEP("%s:set FTF2LINECHSET 2nd namee=%s\n",UTT,pft->FTnamee);//~vbvcR~//~vbveR~//~vbviR~
    }                                                              //~vbv7M~
    funct2utf8init_DefaultShiftDBCS();                             //~vbveR~
    UTRACED("fuct2utf8init_DefaultShift Slchtb",Slchtb,sizeof(Slchtb));//~vbv7I~
    return 0;                                                      //~vbv7M~
}//funct2utf8init                                                  //~vbv7M~
//**************************************************               //~vbv7M~
//*get utf display string by ll+strz fmt tbl                       //~vbv7M~
//**************************************************               //~vbv7M~
int funct2getdisplaystrtb(int *Pplentb,char **Ppaddrtb)            //~vbv7M~
{                                                                  //~vbv7M~
    int ii;                                                        //~vbv7M~
//****************                                                 //~vbv7M~
	for (ii=0;ii<GRAPHKEYENTNO;ii++)                               //~vbv7M~
    {                                                              //~vbv7M~
        *Ppaddrtb++=Slchtb[ii].LCTonoff[0].LCSdata;                //~vbv7M~
        *Pplentb++=Slchtb[ii].LCTonoff[0].LCSlen;                  //~vbv7M~
    }                                                              //~vbv7M~
    return 0;                                                      //~vbv7M~
}//funct2getdisplaystrtb                                           //~vbv7M~
#ifdef LNX
//**************************************************
//*get utf display string by ll+strz fmt tbl
//**************************************************
int funct2getacsch(int Pfuncid)
{
    int idx,len;
    FUNCTBL *pft;
//****************
    idx=Pfuncid-FUNCID_GRAPHCHAR-1;
    if (idx<0||idx>=GRAPHKEYENTNO)
    	return 0;
    len=Slchtb[idx].LCTonoff[0].LCSlen;
    if (len==1)
    	return *(Slchtb[idx].LCTonoff[0].LCSdata);
    if (len>1)
    	return 0;
  	pft=functblsrch(Pfuncid);
    if (!pft)
		return 0;
	return pft->FTchar;
}//funct2getacsch
#endif
//***********************************************************************
//*get linech parameter
//*fmt n=xxxx[=yyyyyy] n=1,2,..,9,h,v
//*    xx:str when OPT LINECH ON   for linex console version:use acs(single byte)
//*    yy:str when OPT LINECH OFF
//*ex) 1=c0 2=c1 3=d9 4=c3 5=c5 6=b4 7=da 8=c2 9=bf h=c4 v=b3  (eng)
//*    1=03 2=15 3=04 4=19 5=10 6=17 7=01 8=16 9=02 h=06 v=05  (jpn)
//*    1=84af 2=84b3 3=84ae 4=84b0 5=84b4 6=84b2 7=84ac 8=84b1 9=84ad h=84aa v=84ab  (jpn dbcs)
//*    1=e29494 2=e294b4 3=e29498 4=e2949c 5=e294bc 6=e294a4 7=e2948c 8=e294ac 9=e29490 h=e29480 v=e29482 (utf)
//*    1=c0=e29494 2=c1=e294b4 3=d9=e29498 4=c3=e2949c 5=c5=e294bc 6=b4=e294a4 7=da=e2948c 8=c2=e294ac 9=bf=e29490 h=c4=e29480 v=b3=e29482 (eng+utf)
//************************************************************************
int funct2setuplinech(char *Pbuff)
{
    int rc=0,opdno;
    int ii;                                                        //~vb2xI~
    UCHAR **pargc,*pc;
	int funct2setuplinechsub(int Popdno,char **Ppargc);
//************************************
    pc=Pbuff+strspn(Pbuff," \t");
    if (!*pc)
        return 0;
    if (*pc=='#')	//comment                                      //~vb47I~
        return 0;                                                  //~vb47I~
    uparsev(pc,&pargc,&opdno,0," =,\t;");//no ignore crlf,no delmstr
    if (opdno)
    {                                                              //~vb2xI~
        for (ii=0;ii<opdno;ii++)                                   //~vb2xI~
        {                                                          //~vb2xI~
            pc=pargc[ii];                                          //~vb2xI~
            if (pc && *pc=='/' && *(pc+1)=='/')                    //~vb2xR~
            {                                                      //~vb2xI~
    		    opdno=ii;                                          //~vb2xI~
                break;                                             //~vb2xI~
            }                                                      //~vb2xI~
        }                                                          //~vb2xI~
		rc=funct2setuplinechsub(opdno,(char**)pargc);
    }                                                              //~vb2xI~
    if (pargc)
	    ufree(pargc);
    return rc;
}//funct2setuplinech
//************************************
//*get utf8 by uxxxx fmt                                           //~vb2uI~
//*return used parse entry                                         //~vb2uI~
//************************************                             //~vb2uI~
int funct2lchgetucs(int Popt,int Popdno,char **Pparg,int Psw2nd,char *Pout,int *Ppoutlen)//~vb2uR~
{                                                                  //~vb2uI~
	int ii,chklen,outlen,errctr,rc2,ucsctr=0,opt,swprefix=0;       //~vb2uR~
	char *pc=0,**pparg;                                            //~vb2uI~
    int wkucs[MAXSTRINPUT];                                        //~vb2uR~
    ULONG ulucs;                                                   //~vb2uI~
//***********************                                          //~vb2uI~
    *Ppoutlen=0;	//when err                                     //~vb2uI~
    for (ii=0,pparg=Pparg;ii<Popdno;ii++,pparg++)                  //~vb2uI~
    {                                                              //~vb2uI~
    	pc=*pparg;                                                 //~vb2uI~
    	UTRACEP("%s:input=%s\n",UTT,pc);                           //~vb2uR~
        if (*pc=='0' && toupper(*(pc+1))=='X')                     //~vb2uI~
        {                                                          //~vb2uI~
            break;                                                 //~vb2uI~
        }                                                          //~vb2uI~
        if (toupper(*pc)=='U')                                     //~vb2uI~
        {                                                          //~vb2uI~
            if (swprefix)  //2nd part                              //~vb2uR~
            	break;                                             //~vb2uR~
            swprefix=1;                                            //~vb2uR~
            pc++;                                                  //~vb2uI~
            if (*pc=='-')                                          //~vb2uI~
                pc++;                                              //~vb2uI~
        }                                                          //~vb2uI~
        if (ux2l(pc,&ulucs))                                       //~vb2uI~
	    	return funct2fmterr(pc);                               //~vb2uI~
        if (ucsctr>=MAXSTRINPUT)                                   //~vb2uR~
	    	return funct2fmterr(pc);                               //~vb2uI~
        if (*pc)                                                   //~vb2uI~
        	wkucs[ucsctr++]=(int)ulucs;                            //~vb2uR~
    }                                                              //~vb2uI~
    if (!ucsctr)                                                   //~vb2uR~
	    return funct2fmterr(pc);                                   //~vb2uI~
    opt=UCVUCS_UCS4;                                               //~vb2uR~
#ifdef BIGENDIAN                                                   //~vb2uI~
#else                                                              //~vb2uI~
    opt|=UCVUCS_LE;                                                //~vb2uI~
#endif                                                             //~vb2uI~
	rc2=ucvsucs2utf(NULL/*Pferr*/,(ULONG)opt,(UCHAR*)wkucs,ucsctr*(int)sizeof(int),Pout,MAXSTRINPUT,&chklen,&outlen,&errctr);//~vb2uR~
    if (rc2)                                                       //~vb2uI~
	    return funct2fmterr(pc);                                   //~vb2uI~
    *(Pout+outlen)=0;	//strz                                     //~vb2uI~
    *Ppoutlen=outlen;                                              //~vb2uI~
    UTRACEP("%s:rc=%d,outlen=%d\n",UTT,ucsctr,outlen);             //~vb2uR~
    UTRACED("outu8",Pout,outlen);                                  //~vb2uI~
    return ucsctr;                                                 //~vb2uI~
}//funct2lchgetucs                                                 //~vb2uI~
//************************************
int funct2setuplinechsub(int Popdno,char **Ppargc)
{
    FUNCTBL *pft;
	LINECHTB lcht;
    char **pargc,*pc/*,editwk[4]*/;                                //~v79SR~
    int jj,idx,ch,len,opdno,len1,len2;
    int readctr;                                                   //~vb2uI~
//************************************
	pargc=Ppargc;
    opdno=Popdno;
    memset(&lcht,0,sizeof(lcht));
//* n=
    pc=*pargc;
    ch=toupper(*pc);
    if (ch=='H')
        idx=9;
    else
    if (ch=='V')
        idx=10;
    else
    {
        idx=atoi(pc)-1;
        if (idx<0||idx>8)
            return funct2fmterr(pc);
    }
//* n=xx=yyyy
    for (jj=0;jj<2;jj++)
    {
        opdno--;pargc++;
        if (!opdno)                                    
            break;
        pc=*pargc;
        if (*pc=='0' && toupper(*(pc+1))=='X')
        {
        	pc+=2;                                                 //~v70mR~
            len=(int)strlen(pc);                                   //~v70mR~
            if (len<=MAXSTRINPUT+MAXSTRINPUT)
            {
            	len=ugethex(pc,lcht.LCTonoff[jj].LCSdata,len);
	            if (len<0)
	            	return funct2fmterr(pc);
	            lcht.LCTonoff[jj].LCSflag|=LCSFHEXDATA;
            }
        }
        else
        if (toupper(*pc)=='U')                                     //~vb2uI~
        {                                                          //~vb2uI~
            readctr=funct2lchgetucs(0,opdno,pargc,jj,lcht.LCTonoff[jj].LCSdata,&len);//~vb2uR~
            if (!len)                                              //~vb2uR~
            	return 4;                                          //~vb2uI~
            readctr--; //decrement at for loop top                 //~vb2uR~
            opdno-=readctr;                                        //~vb2uI~
            pargc+=readctr;                                        //~vb2uR~
	        lcht.LCTonoff[jj].LCSflag|=LCSFU8DATA;                 //~vb2uI~
        }                                                          //~vb2uI~
        else                                                       //~vb2uI~
        {
            len=(int)strlen(pc);                                   //~v70mR~
            if (len<=MAXSTRINPUT)
                strcpy(lcht.LCTonoff[jj].LCSdata,pc);
        }
        if (len>MAXSTRINPUT)
        {
            uerrmsg("LINECH char string is max %d byte",
                    "LINECH文字列は最大 %d",
					MAXSTRINPUT);
            return 4;
        }
	    lcht.LCTonoff[jj].LCSlen=len;
    }
//#if defined(LNX) && !defined(XXE)   //lnx console
//    if (lcht.LCTonoff[0].LCSlen>1)
//    {
//        uerrmsg("Line drawing char have to be single byte for Linux Console version",
//                "Linux コン\x83\\ール版では 罫線文字は１桁でなければなりません");
//        return 4;
//    }
//#endif
//	if (UCBITCHK(Gscrstatus,GSCRSDBCS)	//japanese                 //~v79zR~
//  for (jj=0;jj<2;jj++)                                           //~v79WR~
//  {                                                              //~v79WR~
//    if (XE_ISDBCS()     //all CJK dbcs                             //~v79zR~//~v79WR~
////  &&  lcht.LCTonoff[0].LCSlen==1)                              //~v79WR~
//    &&  lcht.LCTonoff[jj].LCSlen==1)                             //~v79WR~
//    {                                                            //~v79WR~
////      ch=*(lcht.LCTonoff[0].LCSdata);                          //~v79WR~
//        ch=*(lcht.LCTonoff[jj].LCSdata);                         //~v79WR~
////#ifdef LNX                                                       //~v79zR~//~v79WR~
////      if (ISEUC(ch))                                             //~v79zR~//~v79WR~
////#else                                                            //~v79zR~//~v79WR~
////      if (SJIS1(ch))  //dbcs 1st byte                            //~v79zR~//~v79WR~
////#endif                                                           //~v79zR~//~v79WR~
//        if (WCMB1ST_J(ch))                                         //~v79zI~//~v79WR~
//        {                                                        //~v79WR~
//            CH2HEXU(ch,editwk);                                  //~v79WR~
//            editwk[3]=0;                                         //~v79WR~
//            uerrmsg("(%s) may be DBCS 1st byte",                 //~v79WR~
//                     "(%s) DBCS第1バイト文字は1文字では使えません",//~v79WR~
//                     editwk);                                    //~v79WR~
////          return 4;                                            //~v79WR~
//            lcht.LCTonoff[jj].LCSlen=0;                          //~v79WR~
//        }                                                        //~v79WR~
//    }                                                            //~v79WR~
//  }//jj                                                          //~v79WR~
    len1=lcht.LCTonoff[0].LCSlen;
    len2=lcht.LCTonoff[1].LCSlen;
    if (len1)
		setdbcstbl(lcht.LCTonoff[0].LCSdata,lcht.LCTonoff[0].LCSdbcs,len1);
    if (len2)
		setdbcstbl(lcht.LCTonoff[1].LCSdata,lcht.LCTonoff[1].LCSdbcs,len2);
    UTRACED("lcht",&lcht,sizeof(lcht));
	memcpy(Slchtb+idx,&lcht,sizeof(lcht));
    pft=functblsrch(idx+FUNCID_GRAPHCHAR+1);
    if (pft)
    {
        if (len1||len2)
        {                                                          //~vbvcI~
//      	UCBITON(pft->FTflag,FTFLINECHSET);                     //~vbviR~
        	UCBITON(pft->FTflag2,FTF2LINECHSET);                   //~vbviI~
	        UTRACEP("%s:set FTF2LINECHSET namee=%s\n",UTT,pft->FTnamee);//~vbvcR~//~vbviR~
        }                                                          //~vbvcI~
        else
        {                                                          //~vbvcI~
//      	UCBITOFF(pft->FTflag,FTFLINECHSET);                    //~vbviR~
        	UCBITOFF(pft->FTflag2,FTF2LINECHSET);                  //~vbviI~
	        UTRACEP("%s:reset FTF2LINECHSET namee%s=\n",UTT,pft->FTnamee);//~vbvcR~//~vbviR~
        }                                                          //~vbvcI~
        pft=functblsrch2nd(idx+FUNCID_GRAPHCHAR+1,pft);            //~vbvcI~
        if (pft)                                                   //~vbvcI~
        {                                                          //~vbvcI~
            if (len1||len2)                                        //~vbvcI~
            {                                                      //~vbvcI~
//              UCBITON(pft->FTflag,FTFLINECHSET);                 //~vbvcI~//~vbviR~
                UCBITON(pft->FTflag2,FTF2LINECHSET);               //~vbviI~
	        	UTRACEP("%s:set FTF2LINECHSET namee=%s\n",UTT,pft->FTnamee);//~vbvcR~//~vbviR~
            }                                                      //~vbvcI~
            else                                                   //~vbvcI~
            {                                                      //~vbvcI~
//              UCBITOFF(pft->FTflag,FTFLINECHSET);                //~vbvcI~//~vbviR~
                UCBITOFF(pft->FTflag2,FTF2LINECHSET);              //~vbviI~
	        	UTRACEP("%s:reset FTF2LINECHSET namee=%s\n",UTT,pft->FTnamee);//~vbvcR~//~vbviR~
            }                                                      //~vbvcI~
        }                                                          //~vbvcI~
    }
    UTRACED("Slchtb",Slchtb,sizeof(Slchtb));
	return 0;
}//funct2setuplinech
//***********************************************************************//~vb2uI~
//*print ucs data for file7:fkt                                    //~vb2uI~
//************************************************************************//~vb2uI~
int funct2printu8data(int Popt,char *Pu8,int Pu8len,char *Pout)    //~vb2uI~
{                                                                  //~vb2uI~
	char *pco,*pc;                                                 //~vb2uR~
    int outlen,chklen,opt,len,ii,u8chlen;                          //~vb2uR~
    UWUCS uwucs;                                                   //~vb2uI~
    char wknum[20];                                                //~vb2uR~
//**********************                                           //~vb2uI~
	pco=Pout;                                                      //~vb2uI~
    memcpy(pco,"u-",2);                                            //~vb2uI~
    pco+=2;                                                        //~vb2uI~
    outlen=2;                                                      //~vb2uI~
    opt=UCVUCS_UCS4;                                               //~vb2uI~
    for (ii=Pu8len,pc=Pu8;ii>0;)                                   //~vb2uR~
    {                                                              //~vb2uI~
    	u8chlen=UTF8CHARLEN(*pc);                                  //~vb2uR~
    	uccvutf2ucs((ULONG)opt,pc,u8chlen,&uwucs,&chklen);         //~vb2uR~
        if (ii!=Pu8len)                                            //~vb2uR~
        	*pco++=',';                                            //~vb2uI~
//      len=sprintf(wknum,"%x",uwucs);                             //~vb2uR~
        len=sprintf(wknum,"%x",(UINT)uwucs);                       //~vb2uI~
        if (len%2)	//odd                                          //~vb2uI~
        	*pco++='0';                                            //~vb2uI~
        memcpy(pco,wknum,(size_t)len);                             //~vb2uR~
        pco+=len;                                                  //~vb2uI~
        pc+=u8chlen;                                               //~vb2uR~
        ii-=u8chlen;                                               //~vb2uI~
    }                                                              //~vb2uI~
    *pco++='(';                                                    //~vb2uI~
  if (Popt)	//utf8 file mode                                       //~vbvbI~
  {                                                                //~vbvbI~
    memcpy(pco,Pu8,(size_t)Pu8len);                                //~vbvbI~
    pco+=Pu8len;                                                   //~vbvbI~
  }                                                                //~vbvbI~
  else                                                             //~vbvbI~
  {                                                                //~vbvbI~
    opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH<<8);                         //~vb2uR~
    utfcvf2l(opt,pco,Pu8,Pu8len,0/*chklen*/,&outlen,0/*Ppcharwidth*/);//~vb2uR~
    pco+=outlen;                                                   //~vb2uI~
  }                                                                //~vbvbI~
    *pco++=')';                                                    //~vb2uI~
    outlen=(int)PTRDIFF(pco,Pout);                                 //~vb2uR~
    return outlen;                                                 //~vb2uI~
}//funct2printu8data                                               //~vb2uI~
//***********************************************************************//~vbvdI~
//*print hex or local data for file7:fkt                           //~vbvdI~
//*opt:0 hex, 1:lc string                                          //~vbvdI~
//************************************************************************//~vbvdI~
int funct2printlcdata(int Popt,char *Pout,char *Pinp,int Plen)     //~vbvdI~
{                                                                  //~vbvdI~
    UCHAR *poutwk;                                                 //~vbvdI~
    int outlen,opt,len;                                            //~vbvdR~
//  char *pco;                                                     //~vbvdI~//~vbveR~
//**********************                                           //~vbvdI~
//  pco=Pout;                                                      //~vbvdI~//~vbveR~
	len=Plen;                                                      //~vbvdI~
    opt=0;                                                         //~vbvdR~
	xeutf_cvdata(opt,Pinp,len,&poutwk,&outlen);//locale-->utf8    //~vbvdI~//~vbveR~
    memcpy(Pout,poutwk,(UINT)outlen);                              //~vbvdI~
    UTRACED("Pout",Pout,outlen);                                   //~vbvdI~
    return outlen;                                                 //~vbvdI~
}//funct2printlcdata                                               //~vbvdI~
//***********************************************************************
//*setup fkct line data
//*opt:0x02 fk file UTF8                                           //~vbvdI~
//*opt:0x01 on:Eng, on Jpn comment                                 //~vbvdI~
//************************************************************************
//int funct2getlinechstr(int Popt,FUNCTBL *Ppft,char *Pout)        //~vb2AR~
int funct2getlinechstr(int Popt,FUNCTBL *Ppft,char *Pout,int Pbuffsz)//~vb2AI~
{
	PLINECHTB plcht;
	char *pc,*pco,*pc0;
    int ii,jj,ch,len;
    char wkbuff[MAXSTRINPUT*6]; //0x____(cc) or u-xxxx,uyyyy(uuvv) //~vb2AI~
    int outlen;                                                    //~vb2AR~
    int charwidth;                                                 //~vbvtI~
//*************************
	UTRACEP("%s:opt=%d,FTnamee=%s\n",UTT,Popt,Ppft->FTnamee);      //~vbvdR~
    pco=Pout;
    plcht=Slchtb+(Ppft->FTfuncid-(FUNCID_GRAPHCHAR+1));
//  if (!Popt)	//FTnamee print(max 3 byte area by hex)            //~vbvdR~
    if (!(Popt&0x01))	//FTnamee print(max 3 byte area by hex)    //~vbvdI~
    {
        len=plcht->LCTonoff[0].LCSlen;
		UTRACEP("%s:len=%d,LCSdata=x%x,LCSflag=x%x\n",UTT,len,*plcht->LCTonoff[0].LCSdata,plcht->LCTonoff[0].LCSflag);//~vbvtR~
        if (UCBITCHK(plcht->LCTonoff[0].LCSflag,LCSFSJIS))	//japanese only//~vbveI~
//      	if (!memcmp(Ppft->FTnamee,GRAPH_ENGLISH,3))            //~vbveR~
        	if (Ppft->FTflag & FTFEONLY)                           //~vbveI~
            {                                                      //~vbveI~
		  		len=0;	//call fuct2printlcdata                    //~vbveI~
            }                                                      //~vbveI~
		UTRACEP("%s:len=%d\n",UTT,len);                            //~vbvtI~
        if (len==1)
        {
        	pc=plcht->LCTonoff[0].LCSdata;
        	ch=*pc;
        	pco++;
        	CH2HEXU(ch,pco);
        	pco+=3;
          if (Popt & 0x02)                                         //~vbvdI~
          {                                                        //~vbvtI~
//			funct2printlcdata(0/*Hex*/,pco,pc,1);                  //~vbvtR~
  			outlen=funct2printlcdata(0/*Hex*/,pco,pc,1);           //~vbvtR~
			UTRACEP("%s:after funct2printlcdata outlen=%d\n",UTT,outlen);//~vbvtI~
            *(pco+1)=' ';                                          //~vbvtR~
            outlen+=5;                                             //~vbvtI~
          }                                                        //~vbvtI~
          else                                                     //~vbvdI~
          {                                                        //~vbvtI~
        	*pco=(char)ch;                                         //~v70mR~
            outlen=5;                                              //~vbvtR~
          }                                                        //~vbvtI~
//        outlen=5;                                                //~vbvtR~
			UTRACEP("%s:outlen=%d\n",UTT,outlen);                  //~vbvtI~
        }
        else
        {
        	if (len)	//both specified
            {                                                      //~vbvdI~
              if (UCBITCHK(Ppft->FTflag3,FTF3LINECHSETJP))	       //~vbvtI~
              {                                                    //~vbvtI~
        		len=plcht->LCTonoff[0].LCSlen;                     //~vbvtR~
    			utfcvl2f(0,pco,plcht->LCTonoff[0].LCSdata,0/*init offs*/,len,0/*out choftbl*/,0/*out dbcstbl*/,0/*chklen*/,&outlen/*outlen*/,0/*pcharcnt*/,&charwidth);//~vbvtR~
         		memset(pco+outlen,' ',(UINT)(6-charwidth));        //~vbvtR~
                outlen+=6-charwidth;                               //~vbvtR~
	    		UTRACEP("%s:outlen=%d,charwidth=%d\n",UTT,outlen,charwidth);//~vbvtR~
              }                                                    //~vbvtI~
              else                                                 //~vbvtI~
              {                                                    //~vbvtI~
//          	memcpy(pco,"StrKey",6);                            //~vbveR~
            	memcpy(pco,"StrKy ",6);                            //~vbveI~
//              len=6;                                             //~vbvdR~
                outlen=6;                                          //~vbvdI~
              }                                                    //~vbvtI~
            }                                                      //~vbvdI~
            else                                                   //~vbvdI~
            {                                                      //~vbvtI~
				outlen=4+funct2printlcdata(0/*Hex*/,pco+4,&(Ppft->FTchar),1);//~vbvdR~
                *(pco+4+outlen)=' ';                               //~vbvtI~
                outlen++;                                          //~vbvtI~
            }                                                      //~vbvtI~
        }
	    UTRACED("Pout",Pout,outlen);                               //~vbvdR~
        return outlen;                                             //~vbvdR~
    }
//fill FTnamej print area
    pco=wkbuff;                                                    //~vb2AI~
    for (jj=0;jj<2;jj++)
    {
        len=plcht->LCTonoff[jj].LCSlen;
        if (UCBITCHK(plcht->LCTonoff[jj].LCSflag,LCSFSJIS))	//japanese only//~vbveR~
//      	if (!memcmp(Ppft->FTnamee,GRAPH_ENGLISH,3))            //~vbveR~
        	if (Ppft->FTflag & FTFEONLY)                           //~vbveI~
            {                                                      //~vbveI~
		  		len=0;	//call fuct2printlcdata                    //~vbveI~
            }                                                      //~vbveI~
        if (len)
        {
            pc0=plcht->LCTonoff[jj].LCSdata;
            if (plcht->LCTonoff[jj].LCSflag & LCSFHEXDATA)
            {
                memcpy(pco,"0x",2);
                pco+=2;
                for (ii=len,pc=pc0;ii>0;ii--)
                {
                    ch=*pc++;
                    CH2HEXU(ch,pco);
                    pco+=2;
                }
                *pco++='(';
//              memcpy(pco,pc0,(UINT)len);                         //~vbvdR~
				len=funct2printlcdata(0/*Hex*/,pco,pc0,len);       //~vbvdR~
                pco+=len;
                *pco++=')';
            }
            else
            if (plcht->LCTonoff[jj].LCSflag & LCSFU8DATA)          //~vb2uI~
            {                                                      //~vb2uI~
//              pco+=funct2printu8data(0,pc0,len,pco);             //~vb2uI~//~vbvbR~
                pco+=funct2printu8data((Popt & 0x02),pc0,len,pco); //0x02 utf8file mode//~vbvbI~
            }                                                      //~vb2uI~
            else                                                   //~vb2uI~
            {
//              memcpy(pco,pc0,(UINT)len);                         //~vbvdR~
				len=funct2printlcdata(1/*localeString*/,pco,pc0,len);//~vbvdI~
                pco+=len;
            }
        }
        else
        {
        	if (!jj)
            {
            	CH2HEXU(Ppft->FTchar,pco);
            	pco+=2;
            }
        }
        *pco++=';';
    }
//  return (int)((ULONG)pco-(ULONG)Pout);                          //~vafkR~
    outlen=PTRDIFF(pco,wkbuff);                                    //~vb2AR~
    outlen=min(Pbuffsz,outlen);                                    //~vb2AI~
    memcpy(Pout,wkbuff,(size_t)outlen);                            //~vb2AI~
    UTRACED("Pout",Pout,outlen);                                   //~vbvdI~
    return outlen;                                                 //~vb2AI~
}//funct2getlinechstr
//***********************************************************************
//*set UCWkeydata
//rc:0:continue process data,-1:retry from kbd input,4:err
//************************************************************************
int funct2getinputgc(PUCLIENTWE Ppcw,FUNCTBL *Ppft)
{
static int Swarningsw[2];
	PLINECHTB plcht;
	char *pc,*pcd;                                                 //~v70mR~
    int len,acsoff;
    int acsoff1;                                                   //~v79SI~
//*************************
    Sstrinputbyhexsw=0;                                            //~v79RR~
    Sstrinputbyu8sw=0;                                             //~vb2uI~
    Gstrinputlen=0;
    plcht=Slchtb+(Ppft->FTfuncid-(FUNCID_GRAPHCHAR+1));
#if defined(LNX) && !defined(XXE)                                  //~v70mM~
    acsoff=(UCBITCHK(Gopt5,GOPT5ACS)==0); //0:on,1:off( acs mode)  //~v70mR~
    if (acsoff) //no acs mode
    {
      if (!(plcht->LCTonoff[acsoff].LCSflag & (LCSFHEXDATA|LCSFU8DATA)))//~vb2uI~
//      if (Swarningsw[acsoff]<3) //3 times warning                //~va0BR~
        if (Swarningsw[acsoff]++<3) //3 times warning              //~va0BI~
            uerrmsg("\"OPT LINECH ON\" is required to display Line-Drawing-Character",
                  "罫線表\示には \"OPT LINECH ON\" と設定する必要があります");
    }
#else                                                              //~v70mM~
    acsoff=(Ppcw->UCWkeyshift & (KBDSTF_LEFTSHIFT|KBDSTF_RIGHTSHIFT))!=0; //2nd string when width shift key//~v70mM~
#endif
    acsoff1=acsoff;     //save for the case 1st is err by DBCS 1st byte//~v79SI~
    len=plcht->LCTonoff[acsoff].LCSlen;
    UTRACEP("%s:UCWkeyshift=x%x,scsoff=%d,len=%d\n",UTT,Ppcw->UCWkeyshift,acsoff,len);
    if (!len)
    {
    	if (plcht->LCTonoff[!acsoff].LCSlen)
        {
        	acsoff=!acsoff;
		    len=plcht->LCTonoff[acsoff].LCSlen;
        }
    }
    if (!len)
    {
//	    if (!Swarningsw[acsoff]) //1st times warning               //~va0BR~
  	    if (!Swarningsw[acsoff]++)//1st times warning              //~va0BI~
            uerrmsg("line drawing char may be setup by using %s",  //~v70mR~
                      "罫線文字は %s から設定できます。",          //~v70mR~
#ifdef UTF8SUPPH                                                   //~va16I~
						Sdefaultfnm);                              //~va16I~
#else                                                              //~va16I~
						LINECHFILE "xx.ini");                      //~v70mR~
#endif                                                             //~va16I~
    }
    else                                                           //~vb46I~
    {                                                              //~vb46I~
  	    if (!Swarningsw[acsoff]++)//1st times warning              //~vb46I~
            uerrmsg("line drawing seting file %s was used. (warning only at once)",//~vb46R~
                      "罫線文字設定ファイル %s が使用されました(一度だけの情報\x95\\示です)。",//~vb46I~
						Sdefaultfnm);                              //~vb46I~
    }                                                              //~vb46I~
//  Swarningsw[acsoff]++;                                          //~va0BR~
    acsoff=acsoff1;    //restore                                   //~v79SI~
    len=plcht->LCTonoff[acsoff].LCSlen;                            //~v79SI~
    if (!len)
    {                                                              //~v79RI~
        UCBITON(Ppcw->UCWflag3,UCWF3HEXKBDGC);  //request dbcstbl re-evaluation//~v79RI~
    	return 0;
    }                                                              //~v79RI~
    pc=plcht->LCTonoff[acsoff].LCSdata;
    pcd=plcht->LCTonoff[acsoff].LCSdbcs;
    UTRACEP("%s:pc=%s,pcd=%p=x%x,acsoff=%d,len=%d\n",UTT,pc,pcd,*pcd,acsoff,len);
    if (len==1)
    {
    	Ppcw->UCWkeydata[0]=*pc;
        if (plcht->LCTonoff[acsoff].LCSflag & LCSFHEXDATA)  //hex notation//~v79RR~
        	UCBITON(Ppcw->UCWflag3,UCWF3HEXKBDGC);                 //~v79RR~
        return 0;
    }
//*3/4 byte dbcs is read by getnextinputgc by returning with rc=-1 //~va16I~
	if (len==2 && *pcd==DBCS1STCHAR)
    {
#ifdef UTF8SUPP
  		if (!XEUTF8MODE())
        {
#endif
			*Ppcw->UCWkeydata=*pc;
  			*(Ppcw->UCWkeydata+1)=*(pc+1);
			Ppcw->UCWkeytype=UCWKTDBCS;		//sbcs
            return 0;
#ifdef UTF8SUPP
        }
#endif
    }
//multibyte (not dbcs)
    Gstrinputlen=len;
    if (plcht->LCTonoff[acsoff].LCSflag & LCSFHEXDATA)  //hex notation//~v79RI~
        Sstrinputbyhexsw=1;                                        //~v79RR~
  	if (plcht->LCTonoff[acsoff].LCSflag & LCSFU8DATA)              //~vb2yR~
    {                                                              //~vb2yR~
        Sstrinputbyu8sw=1;                                         //~vb2yR~
        funct2saveforerrmsg(0,Ppcw,pc,len);                        //~vb2yR~
    }                                                              //~vb2yR~
    memcpy(Gstrinput,pc,(UINT)len);                                //~v70mR~
    memcpy(Gstrinputdbcs,pcd,(UINT)len);                           //~v70mR~
    UTRACEP("%s:Gstrinput=%s,Gstrinputdbcs=%p=x%x,acsoff=%d,len=%d\n",UTT,pc,pcd,*pcd,acsoff,len);
    return -1;
}//funct2getinputgc
//***********************************************************************
//*get string input
//************************************************************************
//int funct2getnextinputgc(char *Pinput)                           //~v79RR~
#ifdef UTF8SUPPH                                                   //~va16I~
int funct2getnextinputgc(PUCLIENTWE Ppcw,char *Pinput,void *Ppkeyinf)//~va16I~
#else                                                              //~va16I~
int funct2getnextinputgc(PUCLIENTWE Ppcw,char *Pinput)             //~v79RI~
#endif                                                             //~va16I~
{
	int len,rc;
#ifdef UTF8SUPPH                                                   //~va16M~
	KBDKEYINFO *pki;                                               //~va16M~
#endif                                                             //~va16M~
//*************************
    if (Sstrinputbyu8sw)    //hex notation acs string              //~vb2uI~
    {                                                              //~vb2uI~
    	if ((rc=funct2getnextinputgcUTF8(Ppcw,Pinput,Ppkeyinf))>=0)	//-1 for NO UTF8 mode//~vb2uR~
        	return rc;                                             //~vb2uI~
    }                                                              //~vb2uI~
#ifdef UTF8SUPPH                                                   //~va16I~
	pki=(KBDKEYINFO *)Ppkeyinf;                                    //~va16I~
    len=XESUB_DBCSSPLITCTR(Gstrinputdbcs,Gstrinputlen,0/*pos*/);   //~va16I~
    pki->bNlsShift=0;                                              //~va16R~
    if (len>UDBCSCHK_DBCSSZ)                                       //~va16I~
    {                                                              //~va16I~
        rc=UCWKTDBCS;                                              //~va16I~
//      memcpy(Pinput,Gstrinput,len);                              //~va16I~//~vb2uR~
        memcpy(Pinput,Gstrinput,(size_t)len);                      //~vb2uI~
        if (len==UDBCSCHK_GB4SZ)                                   //~va16R~
        {                                                          //~va16I~
		    pki->bNlsShift|=KBDNLS_GB4;	//to UCWnls and chk by xechar//~va16R~
        }                                                          //~va16I~
        else                                                       //~va16I~
        {                                                          //~va16I~
		    pki->bNlsShift|=KBDNLS_SS3;	//to UCWnls and chk by xechar//~va16R~
        }                                                          //~va16I~
    }                                                              //~va16I~
    else                                                           //~va16I~
#endif                                                             //~va16I~
	if (Gstrinputlen>=2 && *Gstrinputdbcs==DBCS1STCHAR)
    {
    	*Pinput=*Gstrinput;    //char code
    	*(Pinput+1)=*(Gstrinput+1);			   //scan code
        len=2;
	    rc=UCWKTDBCS;
	}
    else
    {
    	*Pinput=*Gstrinput;    //char code
    	*(Pinput+1)=0;			   //scan code
        len=1;
	    rc=UCWKTSBCS;
	}
	Gstrinputlen-=len;
    if (Gstrinputlen)
    {                                                              //~v70gI~
		memcpy(Gstrinput,Gstrinput+len,(UINT)Gstrinputlen);        //~v70mR~
		memcpy(Gstrinputdbcs,Gstrinputdbcs+len,(UINT)Gstrinputlen);//~v70mR~
    }                                                              //~v70gI~
    if (Sstrinputbyhexsw)    //hex notation acs string             //~v79RR~
        UCBITON(Ppcw->UCWflag3,UCWF3HEXKBDGC);                     //~v79RI~
UTRACEP("getnextinputgc hexsw=%d,ch=%x\n",Sstrinputbyhexsw,*Pinput);//~v79RR~
UTRACED("getnextinputgc input",Pinput,len);                        //~va16R~
    return rc;
}//funct2getnextinputgc
//***********************************************************************//~vb2uI~
//*get utf8 string input                                           //~vb2uI~
//*return -1:no utf8 mode,UCWkeytype                               //~vb2uI~
//************************************************************************//~vb2uI~
int funct2getnextinputgcUTF8(PUCLIENTWE Ppcw,char *Pinput,void *Ppkeyinf)//~vb2uI~
{                                                                  //~vb2uI~
	int len,keytype,rc2;                                           //~vb2uR~
	KBDKEYINFO *pki;                                               //~vb2uI~
    char *pu8,*inputc;                                             //~vb2uR~
//*************************                                        //~vb2uI~
	pki=(KBDKEYINFO *)Ppkeyinf;                                    //~vb2uI~
UTRACED("kinfo",pki,(int)sizeof(KBDKEYINFO));                      //~vb2uI~
    pu8=Gstrinput;                                                 //~vb2uI~
    len=UTF8CHARLEN(*pu8);                                         //~vb2uI~
UTRACED("Gstrinput",Gstrinput,(int)strlen(Gstrinput));             //~vb2uR~
    inputc=Pinput;                                                 //~vb2uR~
    rc2=funct2kbdsimutf8(0,pu8,len,pki);  //setup KBDKEYINFO       //~vb2uR~
    if (rc2==2)	//NOUTF8 mode                                      //~vb2uI~
    {                                                              //~vb2uI~
    	Sstrinputbyu8sw=0;                                         //~vb2uI~
    	return -1;                                                 //~vb2uI~
    }                                                              //~vb2uI~
//*                                                                //~vb2uI~
    if (pki->bNlsShift & (KBDNLS_F2L_DBCS1ST|KBDNLS_F2L_SBCS))	//utf8 str was set//~vb2uI~
    {                                                              //~vb2uI~
    	memcpy(Ppcw->UCWkeydata_utf8str,pki->u8str,sizeof(Ppcw->UCWkeydata_utf8str));//~vb2uR~
        UCBITON(Ppcw->UCWflag2,UCWF2UTF8STR);                      //~vb2uR~
    }                                                              //~vb2uI~
    else                                                           //~vb2uI~
    	UCBITOFF(Ppcw->UCWflag2,UCWF2UTF8STR);                     //~vb2uR~
    keytype=UCWKTSBCS;                                             //~vb2uI~
    inputc[0]=pki->chChar;    //char code                          //~vb2uI~
	if (pki->bNlsShift & (KBDNLS_DBCS|KBDNLS_F2L_DBCS1ST))//dbcs or f2l dbcsno need to chk lead byte//~vva1cR~//~vb2uR~
    {                                                              //~vb2uI~
    	keytype=UCWKTDBCS;                                         //~vb2uI~
        if (pki->bNlsShift & KBDNLS_SS3)//no need to chk lead byte//~vva1cI~//~vb2uR~
        	UmemcpyZ(inputc+1,pki->mbstr+1,2);       //~vva1cR~    //~vb2uI~
        else                                            //~vva1cI~ //~vb2uI~
        if (pki->bNlsShift & KBDNLS_GB4)//no need to chk lead byte//~vva1cI~//~vb2uR~
        	UmemcpyZ(inputc+1,pki->mbstr+1,3);       //~vva1cR~    //~vb2uR~
        else                                            //~vva1cI~ //~vb2uI~
        if (pki->bNlsShift & KBDNLS_DBCS)//locale 2 byte dbcs//~vva1cI~//~vb2uR~
        	inputc[1]=pki->mbstr[1];	//2nd byte     //~vva1cI~  //~vb2uR~
    }                                                              //~vb2uI~
//*                                                                //~vb2uI~
	Gstrinputlen-=len;                                             //~vb2uI~
    if (Gstrinputlen>0)                                            //~vb2uI~
		memcpy(Gstrinput,Gstrinput+len,(UINT)Gstrinputlen);        //~vb2uI~
UTRACEP("%s: input=%s\n",UTT,inputc);                                //~vb2uR~
UTRACED("KBDKEYINFO input",pki,(int)sizeof(pki));                  //~vb2uI~
    return keytype;                                                //~vb2uR~
}//funct2getnextinputgc                                            //~vb2uI~
//***********************************************************************
//*errmsg
//************************************************************************
int funct2fmterr(char *Ppc)
{
	uerrmsg("LINECH char file format err around %s",0,
            		Ppc);
    return 4;
}//funct2fmterr
//*****************************************************************//~vb2xI~
//*utf-->mb for kbd simutf8                                        //~vb2uI~
//*****************************************************************//~vb2uI~
//*****************************************************************//~vb2uR~
//*read kbd event simulation for 1 utf8 char string                //~vb2uR~
//ret:0:f2l ok,1:f2l err,2:NOUTF8 mode;                            //~vb2uR~
//*****************************************************************//~vb2uR~
int funct2kbdsimutf8(int Popt,char *Putf8,int Plen,PKBDKEYINFO Ppkinfo)//~vb2uR~
{                                                                  //~vb2uR~
	UCHAR wkmbs[MAX_MBCSLEN];                                      //~vb2uR~
    UCHAR ch;                                                      //~vb2uR~
    int mbslen,utf8len;               //~v6BeR~                    //~vb2uR~
    int rc=0,rc2,opt;                                              //~vb2uR~
//**********************                                           //~vb2uR~
UTRACEP("%s:Putf8",UTT,Putf8);                                     //~vb2uR~
	memset(Ppkinfo,0,sizeof(KBDKEYINFO));                          //~vb2uR~
    utf8len=min(Plen,UTF8_MAXCHARSZMAX);                           //~vb2uR~
    memcpy(Ppkinfo->u8str,Putf8,(size_t)utf8len);                  //~vb2uR~
	*(Ppkinfo->u8str+utf8len)=0;                                   //~vb2uR~
    ch=*Putf8;                                                     //~vb2uR~
    if (Plen!=1)                                                   //~vb2uR~
    {                                                              //~vb2uR~
		if (Gotherstatus & GOTHERS_NOUTF8)   //no utf8 option under utf env//~vb2uI~
	    	rc=2;                                                  //~vb2uR~
	    else                                                       //~vb2uR~
        {                                                          //~vb2uR~
            opt=XEUTF_ERRREPCH_F2LFILE;      //"?"                 //~vb2uR~
            rc2=ukbd_simutf8_f2l(opt,Putf8,Plen,wkmbs,(int)sizeof(wkmbs),&mbslen);//~vb2uR~
            if (rc2)                                               //~vb2uR~
            {                                                      //~vb2uR~
                Ppkinfo->bNlsShift|=KBDNLS_F2L_ERR;    //UTF->LOCALE conversion failed//~vb2uR~
                rc=1;                                              //~vb2uR~
            }                                                      //~vb2uR~
            ch=*wkmbs;                                             //~vb2uR~
            mbslen=min(mbslen,UTF8_MAXCHARSZMAX);                  //~vb2uR~
            memcpy(Ppkinfo->mbstr,wkmbs,(size_t)mbslen);           //~vb2uR~
            if (mbslen>1)                                          //~vb2uR~
            {                                                      //~vb2uR~
                Ppkinfo->bNlsShift|=KBDNLS_F2L_DBCS1ST|KBDNLS_DBCS;//~vb2uR~
                if (mbslen==3)                                     //~vb2uR~
                    Ppkinfo->bNlsShift|=KBDNLS_SS3;                //~vb2uR~
                else                                               //~vb2uR~
                if (mbslen==4)                                     //~vb2uR~
                    Ppkinfo->bNlsShift|=KBDNLS_GB4;                //~vb2uR~
                else                                               //~vb2uR~
                    Ppkinfo->bNlsShift|=KBDNLS_F2L_DBCS2ND;        //~vb2uR~
            }                                                      //~vb2uR~
            else                                                   //~vb2uR~
                Ppkinfo->bNlsShift|=KBDNLS_F2L_SBCS;               //~vb2uR~
        }//!NOUTF8                                                 //~vb2uR~
    }//Plen!=0                                                     //~vb2uR~
	Ppkinfo->chScan=KBDSCAN_IMECHAR;	//=0                       //~vb2uR~
    Ppkinfo->chChar=ch;                                            //~vb2uR~
UTRACEP("%s:ret r=%d\n",UTT,rc);                                   //~vb2uR~
UTRACED("keyinfo",Ppkinfo,sizeof(KBDKEYINFO));                     //~vb2uR~
	return rc;	//processed                                        //~vb2uR~
}//funct2kbdsimutf8                                                //~vb2uR~
//*****************************************************************//~vb2yR~
//sve utf8 string for errmsg                                       //~vb2yR~
//rc:1 ct has utf8,0 has no utf8 or err                            //~vb2yI~
//*****************************************************************//~vb2yR~
int funct2saveforerrmsg(int Popt,PUCLIENTWE Ppcw,char *Ppu8,int Pu8len)//~vb2yR~
{                                                                  //~vb2yR~
	int opt,ddlen,rc=0;                                            //~vb2yR~
//  char *pdddata,*pdddbcs,*pddct;                                 //~vb2yR~//~vb2uR~
    UCHAR *pdddata,*pdddbcs,*pddct;                                //~vb2uI~
//*****************************                                    //~vb2yR~
	opt=0;                                                         //~vb2yR~
    if (xeutf_cvf2ddct(opt,Ppu8,Pu8len,&pdddata,&pdddbcs,&pddct,&ddlen)==XEUTFCT_UTF8)//~vb2yR~
    {                                                              //~vb2yR~
		opt=XEUTFSLCFEO_DDFMT|Ppcw->UCWsplitid;                    //~vb2yR~
    	xeutf_savelcctforerrmsg(opt,Ppu8,Pu8len,pdddata,pdddbcs,pddct,ddlen);//~vb2yR~
        rc=1;                                                      //~vb2yR~
    }                                                              //~vb2yR~
    return rc;                                                     //~vb2yR~
}//funct2saveforerrmsg                                             //~vb2yR~
