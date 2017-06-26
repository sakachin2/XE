//*CID://+v6BkR~:                             update#=  111;       //~v6BkR~
//*************************************************************
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bi:160212 (W32)compiler warning                                //~v6BiI~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6uY:140613 (LNX)f2u accept always UCS4 like as W32              //~v6uYI~
//v6uT:140606 for xcv;display full utf char for cv err uerrmsg     //~v6uTI~
//v6uF:140529 (W32)UCVUCS_UCS4:if v6uE output is 4byte ucs,so specify only when 4byte ucs is required,else output surrogate pair for UCS4//~v6uFI~
//v6uE:140529 (W32)request explicit option UCVUCS_UCS4 for UCS4 for also Win//~v6uEI~
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~v6uBI~
//v6ue:140423 (Win:BUG)See v6u7;surrogate pair support (!UTF8UCS4 but UCS4(WUCS is 4 byte when UTF8UCS4)),treate as 2 unprintable//~v6u4I~
//v6r4:131221 (WIN:BUG)did not cv utf8 to sarrogate pair           //~v6r4I~
//v6r0:131215 (ARM)warning strict aliasing                         //~v6r0I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~//~v6h7R~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v695:100804 for xcv,option of set repch when len err for f2x     //~v695I~
//v691:100730 LP64 wchar_t is 4byte on LP64                        //~v691I~
//v690:100701 m64(LP64:: int:32, long,void*:64) support (__LP64_):chk pointer size at 1st.//~v690I~
//v62J:091008_ASCIIRET support for ucvsutf2sjis<-f2l               //~v62JI~
//v62D:091003_f2l support errret for also sjis                     //~v62gI~
//v62g:090811 ucvssutf2sjis:option to no errchar replace           //~v62gI~
//v62f:090811 ucvssutf2sjis:option to advanse 1 byte for conversion err//~v62fI~
//v62d:090725 (BUG) utf8->ucs:result range to be chked             //~v62dI~
//            current c1b4-->0074(110x xxxx+10xx xxxx) should be range 0x0080->0x07ff.//~v62dI~
//v622:090616 option to return ALLASCII                            //~v622I~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v61g:071222 (UTF)locale<-->utf8 conversion support               //~v61gI~
//v614:071117 (UTF)EUC<->UTF8 conversion support                   //~v614I~
//v600:070710 (UTF8)new support                                    //~v600I~
//v5ic:060601 (LNX:UTF)optionaly avoid ucs2sjis for ucs=<0xff      //~v5icI~
//v5h6:060321 ucs conv:support \u option for sjis2ucs/utf2ucs(\uxxxx format output) and ucs2utf(\uxxxx input)//~v5h6R~
//v5b3:040122 \uxxxx unicode fmt conv support                      //~v5b3I~
//v57r:030119 (BUG)ucsconv ;missing ufree                          //~v57mI~
//v57m:030111 (BUG)rrmsg function:display byte                     //~v57mI~
//v57k:030106 cp943,sjis option(ucvucst is ms932)                  //~v57kR~
//v57k:030101 add termfunc(free word)                              //~v57jI~
//v57j:021231 ucs conv:err callback function support               //~v57iI~
//v57i:021231 ucs conv:set rc for ucs=-1                           //~v57iI~
//v57h:021231 ucs conv:readfunc return 1 when end of line of utf/sjis source textfile//~v57hI~
//v57c:021214 unicode,utf8 conversion support
//*************************************************************
//*ukbdlnxc.c
//*kbd get for linux console screen
//*************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#ifdef LNX                                                         //~v61gI~
	#include <iconv.h>                                             //~v61gI~
#endif                                                             //~v61gI~

#include <ulib.h>
#include <ualloc.h>
#include <ucvucs.h>
#include <ucvucst.h>
#include <uerr.h>
#include <udbcschk.h>
#include <utrace.h>                                                //~v57kR~
#include <uedit.h>                                                 //~v5b3I~
#include <utf.h>                                                   //~v61gI~
#include <utf2.h>                                                  //~v6f3I~
#include <utf22.h>                                                 //~v6uBI~
//*************************************************
#define UCSTBSZ  0x10000                                           //~v57kR~
#define SJISTBSZ ((1+(0xfc-0x81+1))<<8)                            //~v57kR~
#define SJISINDEX(sjis)              \
        (  (USHORT)(sjis)<0x0100     \
           ? sjis                    \
           : ( (    ((USHORT)(sjis)>>8)>=0x81  \
                 && ((USHORT)(sjis)>>8)<=0xfc  \
               )                               \
               ?   ((USHORT)(sjis)-0x8000)       \
               :   (0xfaff-0x8000)  /*return err ucs*/  \
             )                                 \
        )                                                          //~v57kR~
#define IBMSEL1 0xfa                                               //~v57kR~
#define IBMSEL2 0xfc                                               //~v57kR~
#define NECSELIBM1 0xed                                            //~v57kR~
#define NECSELIBM2 0xee                                            //~v57kR~
#define NECSPEC    0x87                                            //~v57kR~
#define DUPSJISID  0x1000    //1xxx; entry is index to sjis:ucs=n:1 tbl//~v57kR~
#define DUPSJISIDMASK   0xf000                                     //~v57kR~
#define DUPSJISCTRMASK  0x0fff                                     //~v57kR~
#define DUPSJISTBENTRY  5   //4 entry for each unicode             //~v57kR~
#define IDXUCS          0   //SJIS std                             //~v57kR~
#define IDXSJIS         1   //SJIS std                             //~v57kR~
#define IDXNECS         2   //NEC special char                     //~v57kR~
#define IDXNEC          3   //NEC selected IBM extention           //~v57kR~
#define IDXIBM          4   //IBM selected extention               //~v57kR~
//*************************************************
static USHORT *Ss2utb=0,*Su2stb=0,*Sdupsjistb;                     //~v57kR~
                                                                   //~v57kR~
//*sjis difference between ms932                                   //~v57kR~
static USHORT Scvtsjis2sjis[]={                                    //~v57kR~
    0x8160, 0x301C ,                                               //~v57kR~
    0x8161, 0x2016 ,                                               //~v57kR~
    0x817C, 0x2212 ,                                               //~v57kR~
    0x8191, 0x00A2 ,                                               //~v57kR~
    0x8192, 0x00A3 ,                                               //~v57kR~
    0x81CA, 0x00AC };                                              //~v57kR~
#define SJIS2SJISENTNO (sizeof(Scvtsjis2sjis)/4)                   //~v57kR~
                                                                   //~v57kR~
//*cp943c difference between ms932                                 //~v57kR~
static USHORT Scvtsjis2cp943c[]={                                  //~v57kR~
    0x815C, 0x2014 ,                                               //~v57kR~
    0x8160, 0x301C ,                                               //~v57kR~
    0x8161, 0x2016 ,                                               //~v57kR~
    0x817C, 0x2212 };                                              //~v57kR~
#define SJIS2CP943CENTNO (sizeof(Scvtsjis2cp943c)/4)               //~v57kR~
                                                                   //~v57kR~
//*************************************************
int ucverrucs(ULONG Popt,int Prc,int Prepctr);                     //~v57kR~
int ucverrutf(ULONG Popt,int Prc,int Perrctr);                     //~v57kR~
int ucverrsjis(ULONG Popt,int Prc,int Prepctr);                    //~v57kR~
int ucvsescucs2sjis(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v5b3I~
				int *Ppchklen,int *Ppoutlen,int *Pprepctr);        //~v5b3I~
int ucvsescucs2utf(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v5h6I~
				int *Ppchklen,int *Ppoutlen,int *Pprepctr);        //~v5h6I~
//*************************************************
//*init sjis<-->ucs conv tbl                                       //~v57jI~
//*parm1,2:optional 65536 entry conv tbl                           //~v57jI~
//*ret    :rc 4:malloc failed                                      //~v57jI~
//*************************************************                //~v57jI~
int ucp932init(USHORT **Ps2u,USHORT **Pu2s)
{
	USHORT *s2u,*u2s,*cp9320,*cp932,uss,usu,olduss,*dupsjis;       //~v57kR~
    int    rgnid,rgnidx;                                           //~v57kR~
    char *pc;
    int ii,len,entno;
    int sjisindex,dupctr;                                          //~v57mR~
//******************************
    if (Ss2utb)                                                    //~v57jI~
    {                                                              //~v57jI~
        if (Ps2u)                                                  //~v57jI~
            *Ps2u=Ss2utb;                                          //~v57jI~
        if (Pu2s)                                                  //~v57jI~
            *Pu2s=Su2stb;                                          //~v57jI~
        return 0;                                                  //~v57jI~
    }                                                              //~v57jI~
    entno=ugetcp932tbl(&cp9320);                                   //~v57kR~
//sjis-->ucs conv tbl                                              //~v57kR~
	len=SJISTBSZ<<1;  	//USHORT len                               //~v57kR~
	pc=(char *)umalloc((UINT)len);                                 //~v57jR~
    if (!pc)                                                       //~v57jI~
        return 4;                                                  //~v57jI~
    memset(pc,0xff,(UINT)len);                                     //~v57kR~
//  Ss2utb=s2u=(USHORT*)(ULONG)pc;                                 //~v57kR~//~v6hhR~
    Ss2utb=s2u=(USHORT*)(ULPTR)pc;                                 //~v6hhI~
    if (Ps2u)                                                      //~v57jI~
		*Ps2u=Ss2utb;                                              //~v57jI~
//*ucs-->sjis conv tbl                                             //~v57kR~
	len=UCSTBSZ<<1;     //USHORT len                               //~v57kR~
	pc=(char *)umalloc((UINT)len);                                 //~v57kR~
    if (!pc)                                                       //~v57kR~
        return 4;                                                  //~v57kR~
    memset(pc,0xff,(UINT)len);                                     //~v57kR~
//  Su2stb=u2s=(USHORT*)(ULONG)pc;                                 //~v57jI~//~v6hhR~
    Su2stb=u2s=(USHORT*)(ULPTR)pc;                                 //~v6hhI~
    if (Pu2s)                                                      //~v57jI~
    	*Pu2s=Su2stb;                                              //~v57jR~
    for (ii=0,dupctr=0,cp932=cp9320;ii<entno;ii++)                 //~v57kR~
    {
    	uss=*cp932++;       //sjis
    	usu=*cp932++;       //unicode
        if (usu==UCVERRUCS)   //undefined
        	continue;
        sjisindex=SJISINDEX(uss);     //sjis-->unicode             //~v57kR~
        *(s2u+sjisindex)=usu;     //sjis-->unicode                 //~v57kR~
//UTRACEP("s->u  addr=%x,indx=%08x,usu=%x,uss=%x(%c%c)\n",s2u+sjisindex,sjisindex,usu,uss);//~v57kR~
		olduss=*(u2s+usu);                                         //~v57kR~
		if (olduss==UCVERRUCS) //unicode-->multiple sjis code      //~v57kR~
        	*(u2s+usu)=uss;     //unicode-->sjis                   //~v57kR~
        else                                                       //~v57kR~
			if ((olduss & DUPSJISIDMASK)!=DUPSJISID)//duplicated entry//~v57kR~
            {                                                      //~v57kR~
        		*(u2s+usu)=(USHORT)(DUPSJISID|dupctr++);     //duplicated sjiscode//~v57kR~
//UTRACEP("u-->s  dupctr=%d olduss=%04x,uss=%04x,usu=%04x\n",dupctr,olduss,uss,usu);//~v57mR~
            }                                                      //~v57kR~
    }
//duplicate sjis table setup                                       //~v57kR~
	len=(dupctr*DUPSJISTBENTRY)<<1;    //entry 0 is free,max 4 duplication//~v57kR~
	pc=(char *)umalloc((UINT)len);                                 //~v57kR~
    if (!pc)                                                       //~v57kR~
        return 4;                                                  //~v57kR~
    memset(pc,0xff,(UINT)len);                                     //~v57kR~
//  Sdupsjistb=(USHORT*)(ULONG)pc;                                 //~v57kR~//~v6hhR~
    Sdupsjistb=(USHORT*)(ULPTR)pc;                                 //~v6hhI~
    for (ii=0,cp932=cp9320;ii<entno;ii++)                          //~v57kR~
    {                                                              //~v57kR~
    	uss=*cp932++;       //sjis                                 //~v57kR~
    	usu=*cp932++;       //unicode                              //~v57kR~
        if (usu==UCVERRUCS)   //undefined                          //~v57kR~
        	continue;                                              //~v57kR~
		olduss=*(u2s+usu);                                         //~v57kR~
		if ((olduss & DUPSJISIDMASK)==DUPSJISID) //duplicated entry//~v57kR~
        {                                                          //~v57kR~
            dupctr=olduss & DUPSJISCTRMASK;                        //~v57kR~
            dupsjis=Sdupsjistb+dupctr*DUPSJISTBENTRY;              //~v57kR~
            rgnid=uss>>8;	//1st sjis byte                        //~v57kR~
            if (rgnid==NECSPEC)                                    //~v57kR~
            	rgnidx=IDXNECS;     //0:hikanji,1:nec sel,2:ibmsel //~v57kR~
            else                                                   //~v57kR~
            if (rgnid>=NECSELIBM1 && rgnid<=NECSELIBM2)            //~v57kR~
            	rgnidx=IDXNEC;     //0:hikanji,1:nec sel,2:ibmsel  //~v57kR~
            else                                                   //~v57kR~
            if (rgnid>=IBMSEL1    && rgnid<=IBMSEL2)               //~v57kR~
            	rgnidx=IDXIBM;     //0:hikanji,1:nec sel,2:ibmsel  //~v57kR~
            else                                                   //~v57kR~
            	rgnidx=IDXSJIS;     //0:hikanji,1:nec sel,2:ibmsel //~v57kR~
            *(dupsjis+rgnidx)=uss;     //0:hikanji,1:nec sel,2:ibmsel//~v57kR~
            *(dupsjis+IDXUCS)=usu;	//save unicode                 //~v57kR~
//UTRACEP("dupsjis ctr=%d,old=%x,idx=%d,uss=%x,usu=%x\n",dupctr,olduss,rgnidx,uss,usu);//~v57mR~
        }//duplicated entry                                        //~v57kR~
    }//cp932tbl                                                    //~v57kR~
//clear nec special if common to nec sel and ibm sel               //~v57kR~
//  for (ii=0,dupsjis=Sdupsjistb;ii<dupctr0;ii++,dupsjis+=DUPSJISTBENTRY)//~v57mR~
//  {                                                              //~v57mR~
//UTRACEP("duptbl bef ii=%d,usu=%x,sjis1=%x,sjis2=%x,sjis3=%x\n",ii,*(dupsjis+3),*dupsjis,*(dupsjis+1),*(dupsjis+2));//~v57kR~
//        if ((*dupsjis>>8)==NECSPEC)                              //~v57kR~
//            if (*(dupsjis+1)!=UCVERRUCS && *(dupsjis+2)!=UCVERRUCS)//~v57kR~
//                *dupsjis=UCVERRUCS;                              //~v57kR~
//UTRACEP("duptbl ii=%d,ucs=%04x,sjis0=%04x,sjis1=%04xx,sjis2=%04x,sjis3=%04x\n",//~v57mR~
//			ii,*dupsjis,*(dupsjis+1),*(dupsjis+2),*(dupsjis+3),*(dupsjis+4));//~v57mR~
//  }                                                              //~v57mR~
                                                                   //~v57kR~
//cp943c ucs-->sjis                                                //~v57kR~
    u2s=Scvtsjis2cp943c;                                           //~v57kR~
    for (ii=0;ii<SJIS2CP943CENTNO;ii++)                            //~v57kR~
    {                                                              //~v57kR~
        uss=*u2s++;       //sjis                                   //~v57kR~
        usu=*u2s++;       //unicode                                //~v57kR~
        Su2stb[usu]=uss;                                           //~v57kR~
//UTRACEP("cp943c ent=%08x,usu=%x,uss=%x\n",&Su2stb[usu],usu,uss); //~v57mR~
    }                                                              //~v57kR~
//sjis   ucs-->sjis                                                //~v57kR~
    u2s=Scvtsjis2sjis;                                             //~v57kR~
    for (ii=0;ii<SJIS2SJISENTNO;ii++)                              //~v57kR~
    {                                                              //~v57kR~
        uss=*u2s++;       //sjis                                   //~v57kR~
        usu=*u2s++;       //unicode                                //~v57kR~
        Su2stb[usu]=uss;                                           //~v57kR~
//UTRACEP("sjis   ent=%08x,usu=%x,uss=%x\n",&Su2stb[usu],usu,uss); //~v57mR~
    }                                                              //~v57kR~
    return 0;
}//ucp932init
//*************************************************                //~v57jI~
//*free malloc:rc 0:already freed,1:now freed *                    //~v57jR~
//*************************************************                //~v57jI~
int ucp932term(void)                                               //~v57jR~
{                                                                  //~v57jI~
	USHORT *old;                                                   //~v57jR~
//******************                                               //~v57jI~
	old=Ss2utb;                                                    //~v57jI~
    if (Ss2utb)                                                    //~v57jI~
    {                                                              //~v57jI~
    	ufree(Ss2utb);                                             //~v57jR~
    	Ss2utb=0;                                                  //~v57jI~
    	ufree(Su2stb);                                             //~v57mI~
    	Su2stb=0;                                                  //~v57mI~
    	ufree(Sdupsjistb);                                         //~v57mR~
    	Sdupsjistb=0;                                              //~v57mI~
    }                                                              //~v57jI~
    return (old!=0);                                               //~v57jR~
}//ucp932term                                                      //~v57jI~
//*************************************************
//sjis-->ucs  (ms932)                                              //~v57kR~
//parm1:sjis
//ret :0xffffffff if err
//*************************************************
//ULONG ucp932sjis2ucs(int Psjis)                                  //~v691R~
UWUCS ucp932sjis2ucs(int Psjis)                                    //~v691I~
{
    ULONG ucs;
    int sjisindex;                                                 //~v57kR~
//******************************
    if (!Ss2utb)
    	ucp932init(&Ss2utb,&Su2stb);
    sjisindex=(Psjis&0xffff);                                      //~v57kR~
    sjisindex=SJISINDEX(sjisindex);                                //~v57kR~
    ucs=(ULONG)Ss2utb[sjisindex];                                  //~v57kR~
//UTRACEP("sjis=%0x,indx=%x,ucs=%x\n",Psjis,sjisindex,ucs);        //~v57mR~
//  if (ucs==UCVERRUCS)                                            //~v57mR~
//  	ucs=UCVULONGERRUCS;                                        //~v57mR~
//  return ucs;                                                    //~v6BkR~
    return (UWUCS)ucs;                                             //~v6BkI~
}//ucp932sjis2ucs
//*************************************************
//ucs-->sjis (ms932)                                               //~v57kR~
//parm1:ucs
//ret :sjis code,-1 is err ucs                                     //~v57cR~
//*************************************************
int ucp932ucs2sjis(ULONG Popt,ULONG Pucs)                          //~v57kR~
{
	int sjis;                                                      //~v57cR~
    USHORT us,*pus,usstd,usibm,usnec,usnecs;                       //~v57kR~
//******************************
    if (!Ss2utb)
    	ucp932init(&Ss2utb,&Su2stb);
    us=Su2stb[(Pucs&0xffff)];                                      //~v57cR~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
    if (Popt & UCVUCS_LATIN)                                       //~v5icI~
        if (Pucs<=0xff)                                            //~v5icI~
            return (int)Pucs;   //keep latin                       //~v5icI~
#endif                                                             //~v600I~
    if (us==UCVERRUCS)                                             //~v57cR~
    	sjis=(int)UCVERRUCS;                                       //~v57mR~
    else                                                           //~v57cI~
    if ((us & DUPSJISIDMASK)==DUPSJISID)                           //~v57kR~
    {                                                              //~v57kR~
    	pus=Sdupsjistb+(us & DUPSJISCTRMASK)*DUPSJISTBENTRY;       //~v57kR~
        usstd=*(pus+IDXSJIS);                                      //~v57kR~
        if (usstd!=UCVERRUCS)                                      //~v57kR~
        	sjis=(int)usstd;	//sjis std                         //~v57kR~
        else                                                       //~v57kR~
        {                                                          //~v57kR~
            usnecs=*(pus+IDXNECS);                                 //~v57kR~
            usnec =*(pus+IDXNEC);                                  //~v57kR~
            usibm =*(pus+IDXIBM);                                  //~v57kR~
            if (Popt & UCVUCS_NEC)                                 //~v57kR~
            {                                                      //~v57kR~
        		if (usnec!=UCVERRUCS)                              //~v57kR~
                    sjis=usnec;                                    //~v57kR~
                else                                               //~v57kR~
                    sjis=usnecs;                                   //~v57kR~
            }                                                      //~v57kR~
            else 		//IBM option                               //~v57kR~
            {                                                      //~v57kR~
            	sjis=usibm;                                        //~v57kR~
            }                                                      //~v57kR~
        }                                                          //~v57kR~
    }                                                              //~v57kR~
    else                                                           //~v57kR~
    	sjis=(int)us;                                              //~v57cI~
//UTRACEP("ucp932ucs2sjis tbtop=%08x,ent=%08x\n",Su2stb,&Su2stb[(Pucs&0xffff)]);//~v57mR~
//UTRACEP("ucp932ucs2sjis sjis=%0x,us=%0x,pucs=%0x\n",sjis,us,Pucs);//~v57mR~
    return sjis;                                                   //~v57cR~
}//ucp932ucs2sjis
//*************************************************                //~v57kR~
//sjis-->ucs (mscp932,ibmcp943,sjsi)                               //~v57kR~
//parm1:sjis                                                       //~v57kR~
//ret :0x0000ffff if err                                           //~v57kR~//~v62JR~
//*************************************************                //~v57kR~
//ULONG uccvsjis2ucs(ULONG Popt,int Psjis)                           //~v57kR~//~v691R~
UWUCS uccvsjis2ucs(ULONG Popt,int Psjis)                           //~v691I~
{                                                                  //~v57kR~
    USHORT *u2s,uss,usu;                                           //~v57kR~
    int ii;                                                        //~v57kR~
//******************************                                   //~v57kR~
    if (Popt & UCVUCS_CP943C)                                      //~v57kR~
    {                                                              //~v57kR~
        u2s=Scvtsjis2cp943c;                                       //~v57kR~
        for (ii=0;ii<SJIS2CP943CENTNO;ii++)                        //~v57kR~
        {                                                          //~v57kR~
            uss=*u2s++;       //sjis                               //~v57kR~
    		usu=*u2s++;       //unicode                            //~v57kR~
            if (uss==(USHORT)Psjis)                                //~v57kR~
            	return (ULONG)usu;       //unicode                 //~v57kR~
        }                                                          //~v57kR~
    }                                                              //~v57kR~
    if (!(Popt & UCVUCS_CPMS932))                                  //~v57kR~
    {                                                              //~v57kR~
        u2s=Scvtsjis2sjis;                                         //~v57kR~
        for (ii=0;ii<SJIS2SJISENTNO;ii++)                          //~v57kR~
        {                                                          //~v57kR~
            uss=*u2s++;       //sjis                               //~v57kR~
    		usu=*u2s++;       //unicode                            //~v57kR~
            if (uss==(USHORT)Psjis)                                //~v57kR~
            	return (ULONG)usu;       //unicode                 //~v57kR~
        }                                                          //~v57kR~
    }                                                              //~v57kR~
	return ucp932sjis2ucs(Psjis);	//ms932 conv                   //~v57mR~
}//uccvsjis2ucs                                                    //~v57kR~
//*************************************************                //~v57kR~
//ucs-->sjis(ms932,cp943c,sjis)                                    //~v57kR~
//parm1:ucs                                                        //~v57kR~
//ret :sjis code,-1 is err ucs                                     //~v57kR~
//*************************************************                //~v57kR~
//int uccvucs2sjis(ULONG Popt,ULONG Pucs)                            //~v57kR~//~v691R~
int uccvucs2sjis(ULONG Popt,UWUCS Pucs)                            //~v691I~
{                                                                  //~v57kR~
//******************************                                   //~v57kR~
//  return ucp932ucs2sjis(Popt,Pucs);                              //~v57kR~//~v6BkR~
    return ucp932ucs2sjis(Popt,(ULONG)Pucs);                       //~v6BkI~
}//uccvucs2sjis                                                    //~v57kR~
//*************************************************
// char conv ucs-->utf-8
//parm1:ucs
//parm2:out utf-8 addr
//ret  :utf-8 length,0 if err
//*************************
//   ucs                                   utf-8
//  u+0000..u+007f  : 0000.0000-0xxx.xxxx    0xxx.xxxx
//  u+0080..u+07ff  : 0000.0xxx-xxyy.yyyy    110x.xxxx-10yy.yyyy
//  u+0800..u+ffff  : xxxx.yyyy-yyzz.zzzz    1110.xxxx-10yy.yyyy-10zz.zzzz
//  u+010000..      : 0000.0000-000w.wwxx    1111.0www-10xx.xxxx-10yy.yyyy-
//  u+1fffff          xxxx.yyyy-yyzz.zzzz    10zz.zzzz
//*************************************************
//int uccvucs2utf(ULONG Pucs,UCHAR *Putf)                          //~v691R~
int uccvucs2utf(UWUCS Pucs,UCHAR *Putf)                            //~v691I~
{
    int len;
	UCHAR *pc;
//******************************
    pc=Putf;
//  if (!(Pucs & 0xffffff80))   //u+0000 -- u+007f                 //~v6BkR~
    if (!(Pucs & (UWUCS)0xffffff80))   //u+0000 -- u+007f          //~v6BkI~
    {
        *pc=(UCHAR)(Pucs & 0x007f);
        len=1;
    }
    else
//  if (!(Pucs & 0xfffff800))   //u+0080 -- u+07ff                 //~v6BkR~
    if (!(Pucs & (UWUCS)0xfffff800))   //u+0080 -- u+07ff          //~v6BkI~
    {
        *pc++=(UCHAR)(0xc0+((UINT)(Pucs & 0x07c0)>>6));
        *pc  =(UCHAR)(0x80+((Pucs & 0x003f)   ));
        len=2;
    }
    else                     //u+0800 -- u+ffff
//  if (!(Pucs & 0xffff0000))   //u+08000 -- u+fffff               //~v6BkR~
    if (!(Pucs & (UWUCS)0xffff0000))   //u+08000 -- u+fffff        //~v6BkI~
    {
        *pc++=(UCHAR)(0xe0+((UINT)(Pucs & 0xf000)>>12));
        *pc++=(UCHAR)(0x80+((UINT)(Pucs & 0x0fc0)>>6 ));
        *pc=  (UCHAR)(0x80+((Pucs & 0x003f)    ));
        len=3;
    }
    else
//  if (!(Pucs & 0xffe00000))   //u+10000 -- u+1fffff              //~v6BkR~
    if (!(Pucs & (UWUCS)0xffe00000))   //u+10000 -- u+1fffff       //~v6BkI~
    {
        *pc++=(UCHAR)(0xf0+((UINT)(Pucs & 0x1c0000)>>18));
        *pc++=(UCHAR)(0x80+((UINT)(Pucs & 0x03f000)>>12));
        *pc++=(UCHAR)(0x80+((UINT)(Pucs & 0x000fc0)>>6 ));
        *pc=  (UCHAR)(0x80+((Pucs & 0x00003f)    ));
        len=4;
    }
    else
        len=0;
    return len;
}//uccvucs2utf
//*************************************************
// conv utf-8 --> ucs
//parm1:option
//parm2:utf-8 buff
//parm3:bufflen
//parm4:output ucs code
//parm5:output,converted utf-8 char len
//ret  :rc       ;-1 if fmt err,-2 if short input utf-8 string
//*************************************************
//int uccvutf2ucs(ULONG Popt,UCHAR *Putf,int Plen,ULONG *Ppucs,int *Ppchklen)//~v57kR~//~v691R~
int uccvutf2ucs(ULONG Popt,UCHAR *Putf,int Plen,UWUCS *Ppucs,int *Ppchklen)//~v691I~
{
    int   rc=UCVUCS_FMTERR;
    ULONG ucsw,ucs;
//  ULONG ucsH,ucsL;                                               //~v6r4I~//~v6uBR~
	UCHAR *pc,ch;
//******************************
//	ucs=(ULONG)-1;                                                 //~v57cR~//~v690R~
	ucs=UCVULONGERRUCS;         //ffffffff                         //~v690R~
    pc=Putf;
    for (;;)
    {
        if (Plen<1)
        {
        	rc=UCVUCS_LENERR;
        	break;
        }
        ch=*pc++;
        if (!(ch & 0x80))          //0xxx.xxxx
        {
            ucs=(ULONG)(ch & 0x7f);       //1byte utf-8            //~v57jR~
            rc=0;					//1byte output
            break;
        }
    	if (!(ch & 0x40))          //10xx.xxxx is  following byte
            break;
//11xx.xxxx
    	if (!(ch & 0x20))      //110x.xxxx 2byte fmt
        {
	        if (Plen<2)
	        {
     		   	rc=UCVUCS_LENERR;
        		break;
	        }
        	ucsw=(ULONG)((ch & 0x1f)<<6);      //000.0xxx xx00.0000//~v57jR~
            ch=*pc++;          //2nd byte
        	if ((ch & 0xc0)!=0x80)      //10xx.xxxx
        		break;
            ucs=ucsw+(ch & 0x3f);         //00yy.yyyy
            if (ucs<0x0080) //valid range 0x0080->0x07ff           //~v62dI~
        		break;                                             //~v62dI~
            rc=0;                         //2byte output
            break;
        }
        if (!(ch & 0x10))    //1110.xxxx
        {
	        if (Plen<3)
	        {
     		   	rc=UCVUCS_LENERR;
        		break;
	        }
            ucsw=(ULONG)((ch & 0x0f)<<12);      //xxxx.0000 0000.0000//~v57jR~
            ch=*pc++;          //2nd byte
        	if ((ch & 0xc0)!=0x80)      //10xx.xxxx
        		break;
//          ucsw+=((ch & 0x3f)<<6);         //xxxx.yyyy yy00.0000  //~v6BkR~
            ucsw+=(ULONG)((ch & 0x3f)<<6);         //xxxx.yyyy yy00.0000//~v6BkI~
            ch=*pc++;          //3rd byte
        	if ((ch & 0xc0)!=0x80)      //10xx.xxxx
        		break;
            ucs=ucsw+(ch & 0x3f);
            if (ucs<0x0800) //valid range 0x0800->0xffff           //~v62dI~
        		break;                                             //~v62dI~
            rc=0;					//3byte output
            break;
        }
//1111.xxxx
//#ifdef UTF8UTF16                                                   //~v6uBI~//~v6uER~
//#else                                                              //~v6uBI~//~v6uER~
//#ifdef UTF8UTF16    //always accept UTF8-UCS4                      //~v6uFI~//~v6uYR~
//#else                                                              //~v6uFI~//~v6uYR~
//        if (!(Popt & UCVUCS_UCS4)) //not accept ucs4             //~v6uYR~
////#ifdef W32UNICODE                                                  //~v6u4I~//~v6uBR~//~v6uYR~
////          if (!(Gulibutfmode & GULIBUTF_WINSURROGATE))             //~v6r4I~//~v6uBR~//~v6uYR~
////#endif                                                             //~v6u4I~//~v6uBR~//~v6uYR~
//            break;                                               //~v6uYR~
////#endif                                                             //~v6uBI~//~v6uER~//~v6uYR~
//#endif                                                             //~v6uFI~//~v6uYR~
        if ((ch & 0x08))      //1111.0xxx
            break;
        if (Plen<4)
        {
            rc=UCVUCS_LENERR;
            break;
        }
        ucsw=(ULONG)((ch & 0x07)<<18);      //000w.wwxx xxxx.yyyy yyzz.zzzz//~v57jR~
        ch=*pc++;          //2nd byte
        if ((ch & 0xc0)!=0x80)      //10xx.xxxx
            break;
//      ucsw+=((ch & 0x3f)<<12);         //xxxx.yyyy yyzz.zzzz     //~v6BkR~
        ucsw+=(ULONG)((ch & 0x3f)<<12);         //xxxx.yyyy yyzz.zzzz//~v6BkI~
        ch=*pc++;          //3rd byte
        if ((ch & 0xc0)!=0x80)      //10yy.yyyy
            break;
//      ucsw+=((ch & 0x3f)<<6);         //xxxx.yyyy yyzz.zzzz      //~v6BkR~
        ucsw+=(ULONG)((ch & 0x3f)<<6);         //xxxx.yyyy yyzz.zzzz//~v6BkI~
        ch=*pc++;          //3rd byte
        if ((ch & 0xc0)!=0x80)      //10zz.zzzz
            break;
        ucs=ucsw+(ch & 0x3f);
        if (ucs<0x00010000) //ucs4 valid range 0x00010000->0x0010ffff//~v62dI~
        	break;                                                 //~v62dI~
        if (ucs>0x0010ffff) //ucs4 valid range 0x00010000->0x0010ffff//~v62dI~
        	break;                                                 //~v62dI~
//#ifdef W32UNICODE                                                //~v6u4R~//~v6uBR~
//        if ((Gulibutfmode & GULIBUTF_WINSURROGATE))                //~v6r4I~//~v6uBR~
//        {                                                          //~v6r4I~//~v6uBR~
//            ucsH=((ucs-0x10000)/0x0400+0xD800);                    //~v6r4R~//~v6uBR~
//            ucsL=((ucs-0x10000)%0x0400+0xDC00);                    //~v6r4R~//~v6uBR~
//            ucs=ucsL+(ucsH<<16);                                   //~v6r4I~//~v6u4R~//~v6uBR~
//        }                                                          //~v6r4I~//~v6uBR~
//#endif                                                           //~v6u4R~//~v6uBR~
        rc=0;                        //4byte output
        break;
    }//for
//  *Ppchklen=(int)((ULONG)pc-(ULONG)Putf);                        //~v57jR~//~v6hhR~
    *Ppchklen=(int)((ULPTR)pc-(ULPTR)Putf);                        //~v6hhI~
//  *Ppucs=ucs;                                                    //~v6BkR~
    *Ppucs=(UWUCS)ucs;                                             //~v6BkI~
    if (rc==UCVUCS_LENERR)                                         //~v57hI~
    	if (Popt & UCVUCS_FULLREC)	//end of line                  //~v57hI~
    		rc=UCVUCS_FMTERR;                                      //~v57hI~
    return rc;
}//uccvutf2ucs
//*************************************************
// conv single ucs string -->utf-8
//parm1:opt
//parm2:pointer to ucs
//ret  :utf-8 length,0 if err
//*************************************************
//#ifdef UTF8UTF16                                                   //~v6uBI~//~v6uYR~
int uccvucss2utf(ULONG Popt,UCHAR *Pucs,UCHAR *Putf,int *Ppucsctr) //~v6uBI~
//#else                                                              //~v6uBI~//~v6uYR~
//int uccvucss2utf(ULONG Popt,UCHAR *Pucs,UCHAR *Putf)               //~v57kR~//~v6uYR~
//#endif                                                             //~v6uBI~//~v6uYR~
{
    ULONG ucs;
//******************************
	ucs=ucvgetucss(Popt,Pucs);
//#ifdef UTF8UTF16                                                   //~v6uBI~//~v6uYR~
	*Ppucsctr=1;                                                   //~v6uBI~
	if (!(Popt & UCVUCS_UCS4))                                     //~v6uBI~
    {                                                              //~v6uBI~
    	if (IS_UTF16_HIGH(ucs))                                    //~v6uBI~
        {                                                          //~v6uBI~
        	ULONG ucs2L;                                           //~v6uBI~
            ucs2L=ucvgetucss(Popt,Pucs+2);                         //~v6uBI~
	    	if (IS_UTF16_LOW(ucs2L))                               //~v6uBI~
            {                                                      //~v6uBI~
            	ucs=UTF16_TO_UCS4(ucs,ucs2L);                      //~v6uBI~
				*Ppucsctr=2;                                       //~v6uBI~
            }                                                      //~v6uBI~
        }                                                          //~v6uBI~
    }                                                              //~v6uBI~
//#endif                                                             //~v6uBI~//~v6uYR~
//  return uccvucs2utf(ucs,Putf);                                  //~v6BkR~
    return uccvucs2utf((UWUCS)ucs,Putf);                           //~v6BkI~
}//uccvucss2utf
//*************************************************
// conv utf-8 --> 1 ucs code string
//parm1:option
//parm2:utf-8 buff
//parm3:bufflen
//parm4:output ucs code
//parm5:output,converted utf-8 char len
//*************************************************
//int uccvutf2ucss(ULONG Popt,UCHAR *Putf,int Plen,UCHAR *Pucs,int *Ppchklen)//~v5h6R~
//int uccvutf2ucss(ULONG Popt,UCHAR *Putf,int Plen,UCHAR *Pucs,int *Ppchklen,int *Poutlen)//~v5h6I~//~v6uYR~
int uccvutf2ucss(ULONG Popt,UCHAR *Putf,int Plen,UCHAR *Pucs,int Pbuffsz,int *Ppchklen,int *Poutlen)//~v6uYR~
{
    int   rc=UCVUCS_FMTERR;
//  ULONG ucs;                                                     //~v691R~
    UWUCS ucs;                                                     //~v691I~
//#ifdef W32UNICODE                                                  //~v6u4I~//~v6uBR~
//    int swsurrogate;                                               //~v6r4I~//~v6uBR~
//*FIXME test ucs4 on LNX:FIXED                                    //~v6uFR~
//#endif                                                             //~v6u4I~//~v6uBR~
//******************************
	rc=uccvutf2ucs(Popt,Putf,Plen,&ucs,Ppchklen);
    *Poutlen=0;                                                    //~v5h6I~
    if (rc!=UCVUCS_LENERR)
    {
	 	if (rc==UCVUCS_FMTERR)
        {                                                          //~v5b3I~
        	if (Popt & UCVUCS_UCS4)                                //~v57mI~
//      		ucs=UCVULONGERRUCS;                                //~v57mR~//~v6BkR~
        		ucs=(UWUCS)UCVULONGERRUCS;                         //~v6BkI~
            else                                                   //~v57mI~
	    		ucs=UCVERRUCS;                                     //~v57mI~
//      	swsurrogate=0;                                         //~v6r4I~//~v6uBR~
        }                                                          //~v5b3I~
//#ifdef W32UNICODE                                                  //~v6u4I~//~v6uBR~
//        else                                                       //~v6r4I~//~v6uBR~
//            swsurrogate=((Gulibutfmode & GULIBUTF_WINSURROGATE) && (ucs>>16)!=0);//~v6r4R~//~v6uBR~
//#endif                                                             //~v6u4I~//~v6uBR~
//#ifdef W32UNICODE                                                  //~v6u4I~//~v6uBR~
//      if (swsurrogate)                                             //~v6r4I~//~v6uBR~
//      {                                                            //~v6r4I~//~v6uBR~
//        *Poutlen=4;                                                //~v6r4I~//~v6uBR~
//        ucvsetucss(Popt,ucs>>16,Pucs);                           //~v6r4I~//~v6u4R~//~v6uBR~
//        ucvsetucss(Popt,ucs&0xffff,Pucs+2);                          //~v6r4I~//~v6u4I~//~v6uBR~
//      }                                                            //~v6r4I~//~v6uBR~
//      else                                                         //~v6r4I~//~v6uBR~
//#endif                                                             //~v6u4I~//~v6uBR~
//#ifdef UTF8UTF16                                                   //~v6uBI~//~v6uYR~
	  if (ucs>UTF_UCS2MAX)                                         //~v6uBI~
      {                                                            //~v6uBI~
      	int ctr;                                                   //~v6uBI~
        UWCH wkuwch[2];                                            //~v6uBI~
        UWUCS uwucs;                                               //~v6uBI~
      if (Pbuffsz<4)                                               //~v6uYI~
       rc=UCVUCS_BUFFOVF;                                          //~v6uYI~
      else                                                         //~v6uYI~
      {  	                                                       //~v6uYI~
//     if (Popt & UCVUCS_UCS4) //accept ucs4                       //~v6uBI~//~v6uER~
//     if (Popt & UCVUCS_UCS4W))   //output not surrogate pair but ucs4//~v6uER~//~v6uFR~
       if (Popt & UCVUCS_UCS4) //accept ucs4                       //~v6uFI~
		ucvsetucss(Popt,ucs,Pucs);   //set BE/LE 4byte ucs         //~v6uBI~
       else                                                        //~v6uBI~
       {                                                           //~v6uBI~
        UCS4_TO_UTF16(ucs,wkuwch,&ctr);                            //~v6uBI~
        uwucs=(UWUCS)wkuwch[0];                                    //~v6uBI~
        ucvsetucss(Popt,uwucs,Pucs);                               //~v6uBI~
        uwucs=(UWUCS)wkuwch[1];                                    //~v6uBI~
        ucvsetucss(Popt,uwucs,Pucs+2);                             //~v6uBI~
       }                                                           //~v6uBI~
      }                                                            //~v6uYI~
        *Poutlen=4;                                                //~v6uBI~
      }                                                            //~v6uBI~
      else                                                         //~v6uBI~
//#endif UTF8UTF16                                                             //~v6uBI~//~v6uYR~
      *Poutlen=                                                    //~v5h6R~
		ucvsetucss(Popt,ucs,Pucs);
    }//!lenerr
    return rc;
}//uccvutf2ucss
//*************************************************
// conv sjis--> 1 ucs code string
//parm1:option
//parm2:sjis
//parm3:output ucs buff
//ret  :ucs
//*************************************************
//ULONG uccvsjis2ucss(int Popt,int Psjis,UCHAR *Pucs)              //~v57iR~
//int uccvsjis2ucss(ULONG Popt,int Psjis,UCHAR *Pucs)              //~v5h6R~
int uccvsjis2ucss(ULONG Popt,int Psjis,UCHAR *Pucs,int *Poutlen)   //~v5h6I~
{
    int   rc;                                                      //~v57iR~
    ULONG ucs;
//******************************
//  ucs=ucp932sjis2ucs(Psjis);                                     //~v57kR~
//  ucs=uccvsjis2ucs(Popt,Psjis);                                  //~v57kR~//+v6BkR~
    ucs=(ULONG)uccvsjis2ucs(Popt,Psjis);                           //+v6BkI~
    if (ucs==UCVERRUCS)                                            //~v57mR~
    	rc=UCVUCS_CONVERR;                                         //~v57iR~
    else                                                           //~v57iI~
    	rc=0;                                                      //~v57iI~
  *Poutlen=                                                        //~v5h6I~
//  ucvsetucss(Popt,ucs,Pucs);                                     //+v6BkR~
    ucvsetucss(Popt,(UWUCS)ucs,Pucs);                              //+v6BkI~
    return rc;
}//uccvsjis2ucss
//*************************************************
// conv ucs string ->sjis
//parm1:option
//parm2:ucs string
//ret  :sjis ,-1 if err ucs                                        //~v57cR~
//*************************************************
int uccvucss2sjis(ULONG Popt,UCHAR *Pucs)                          //~v57kR~
{
    int   sjis;
    ULONG ucs;
//******************************
    ucs=ucvgetucss(Popt,Pucs);
//  sjis=ucp932ucs2sjis(ucs);                                      //~v57kR~
//  sjis=uccvucs2sjis(Popt,ucs);                                   //~v57kR~//+v6BkR~
    sjis=uccvucs2sjis(Popt,(UWUCS)ucs);                            //+v6BkI~
    return sjis;
}//uccvucss2sjis
//*************************************************
// char conv sjis-->utf-8
//parm1:sjis
//parm2:out utf-8 addr
//ret  :utf-8 length,0 if err(ucs>0x1fffff)
//*************************************************
//int uccvsjis2utf(int Psjis,UCHAR *Putf)                          //~v57iR~
//int uccvsjis2utf(int Psjis,UCHAR *Putf,int *Pplen)               //~v57kR~
int uccvsjis2utf(ULONG Popt,int Psjis,UCHAR *Putf,int *Pplen)      //~v57kR~
{
    int len;
    ULONG ucs=0;                                                   //~v6h6R~
    int rc;                                                        //~v57iI~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
	int euc,eucerr=0;                                              //~v614R~
#endif                                                             //~v614I~
//******************************
//  ucs=ucp932sjis2ucs(Psjis);	//0:sjis-->ucs                     //~v57kR~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
    if (Popt & UCVUCS_EUC)                                         //~v614I~
    {                                                              //~v614I~
        if (ueuc2shift1c(UDBCSCHK_RC0IFNOERR|UDBCSCHK_ERRDBCSCHK,Psjis,&euc))          //~v614R~//~v614R~
        {                                                          //~v614I~
	    	eucerr=1;                                              //~v614R~
            ucs=UCVERRUCS;                                         //~v614R~
        }                                                          //~v614I~
	    Psjis=euc;                                                 //~v614R~
    }                                                              //~v614I~
  if (!eucerr)                                                     //~v614R~
#endif                                                             //~v614I~
//  ucs=uccvsjis2ucs(Popt,Psjis);	//0:sjis-->ucs                 //~v57kR~//+v6BkR~
    ucs=(ULONG)uccvsjis2ucs(Popt,Psjis);	//0:sjis-->ucs         //+v6BkI~
//  len=uccvucs2utf(ucs,Putf);                                     //+v6BkR~
    len=uccvucs2utf((UWUCS)ucs,Putf);                              //+v6BkI~
    if (ucs==UCVERRUCS)                                            //~v57mR~
    	rc=UCVUCS_CONVERR;                                         //~v57iR~
    else                                                           //~v57iI~
    	rc=0;                                                      //~v57iI~
//  return len;                                                    //~v57iR~
    *Pplen=len;                                                    //~v57iI~
    return rc;                                                     //~v57iI~
}//uccvsjis2utf
//*************************************************
// char conv utf-8-->sjis
//ret  :utf-8 fmt err
//*************************************************
int uccvutf2sjis(ULONG Popt,UCHAR *Putf,int Plen,int *Ppsjis,int *Ppchklen)//~v57kR~
{
    int  rc;
//  ULONG ucs;                                                     //~v691R~
    UWUCS ucs;                                                     //~v691I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
	int euc;                                                       //~v614I~
#endif                                                             //~v614I~
//******************************
	rc=uccvutf2ucs(Popt,Putf,Plen,&ucs,Ppchklen);
    if (!rc)
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
	{                                                              //~v614I~
#endif                                                             //~v614I~
//  	*Ppsjis=ucp932ucs2sjis(ucs);	//1:sjis<--ucs             //~v57kR~
    	*Ppsjis=uccvucs2sjis(Popt,ucs);	//1:sjis<--ucs             //~v57kR~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
		if (Popt & UCVUCS_EUC)                                     //~v614I~
        {                                                          //~v614I~
        	if (ushift2euc1(UDBCSCHK_RC0IFNOERR,*Ppsjis,&euc))     //~v614R~
            {                                                      //~v614I~
		    	rc=UCVUCS_CONVERR;                                 //~v614I~
                euc=UCVERRUCS;                                     //~v614I~
            }                                                      //~v614I~
            *Ppsjis=euc;                                           //~v614I~
        }                                                          //~v614I~
	}                                                              //~v614I~
#endif                                                             //~v614I~
    return rc;
}//uccvutf2sjis
//*************************************************
// string conv ucs   --> utf
//parm1:opt
//parm2:char replace conv err
//parm3:ucs  buff
//parm4:ucs  bufflen
//parm5:utf buff
//parm6:utf bufflen
//parm7:output conv len until length shortage
//ret  :rc
//*************************************************
int ucvsucs2utf(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr)         //~v57cR~
{
	int   rc=0,ucssz,utflen,reslen,outreslen,errctr=0;             //~v57cR~
    UCHAR *putf,*pucs,utf[4];
//#ifdef UTF8UTF16                                                   //~v6uBI~//~v6uYR~
    int ucsctr;                                                    //~v6uBI~
//#endif                                                             //~v6uBR~//~v6uYR~
//****************************************
    if (Popt & UCVUCS_ESCUCS) //input is \uxxxx unicode fmt        //~v5h6I~
		return ucvsescucs2utf(Pferr,Popt,Pibuff,Pibufflen,Pobuff,Pobufflen,//~v5h6I~
								Ppchklen,Ppoutlen,Pperrctr);       //~v5h6R~
    if (Popt & UCVUCS_UCS4) //accept ucs4
    	ucssz=4;
    else
    	ucssz=2;
    for (reslen=Pibufflen,pucs=Pibuff,outreslen=Pobufflen,putf=Pobuff;reslen>0;)
    {
    	if (reslen<ucssz)
        {
          if (Popt & UCVUCS_FULLREC)    //eol is eof for ucs input //~v57iI~
          {                                                        //~v57iI~
        	if (Pferr)                                             //~v57iI~
//	            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,reslen);//~v57mR~//~v6hhR~
	            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
            rc|=UCVUCS_FMTERR;                                     //~v57iI~
        	errctr++;                                              //~v57iI~
          }                                                        //~v57iI~
          else                                                     //~v57iI~
          {                                                        //~v57iI~
        	if (Pferr)                                             //~v57iI~
//	            Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,reslen);//~v57mR~//~v6hhR~
	            Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
            rc|=UCVUCS_LENERR;
          }                                                        //~v57iI~
            break;
        }
//#ifdef UTF8UTF16                                                   //~v6uBI~//~v6uYR~
        utflen=uccvucss2utf(Popt,pucs,utf,&ucsctr);                //~v6uBI~
//#else                                                              //~v6uBI~//~v6uYR~
//        utflen=uccvucss2utf(Popt,pucs,utf);                      //~v6uYR~
//#endif                                                             //~v6uBI~//~v6uYR~
//printf("ucs-->utf offs=%08x,outoffs=%08x,ucs=%08x,%4.4s, utflen=%d,utf=%08x,%*.*s\n",//~v57cR~
//				Pibufflen-reslen,Pobufflen-outreslen,              //~v57cR~
//			*(ULONG*)(ULONG)pucs,pucs,utflen,*(ULONG*)utf,utflen,utflen,utf);//~v57cR~
        if (!utflen)   //conv err
        {
        	if (Pferr)                                             //~v57iI~
//	            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,1);//~v57mR~//~v6hhR~
	            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,1);//~v6hhI~
        	errctr++;                                              //~v57cI~
	        rc|=UCVUCS_FMTERR;
	        utflen=uccvucs2utf(UCVERRUCS,utf);
        }
    	if (!outreslen 		//for fmt err case
		||outreslen<utflen)
        {
        	if (Pferr)                                             //~v57iI~
//	            Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,0);//~v57mR~//~v6hhR~
	            Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,0);//~v6hhI~
	        rc|=UCVUCS_BUFFOVF;
            break;
        }
        if (utflen)
        	memcpy(putf,utf,(UINT)utflen);                         //~v57jR~
        outreslen-=utflen;
        putf+=utflen;
        reslen-=ucssz;
        pucs+=ucssz;
//#ifdef UTF8UTF16                                                   //~v6uBI~//~v6uYR~
        if (ucsctr==2)	//surrogate pair                           //~v6uBI~
			reslen-=ucssz,pucs+=ucssz;                             //~v6uBR~
//#endif                                                             //~v6uBI~//~v6uYR~
    }
    *Ppchklen=Pibufflen-reslen;
    *Ppoutlen=Pobufflen-outreslen;                                 //~v57cR~
    *Pperrctr=errctr;                                              //~v57cI~
    if (Pferr)                                                     //~v57iR~
        Pferr(0,*Ppchklen,*Ppoutlen,Pibuff,0);                     //~v57mR~
    return rc;
}//ucvsucs2utf
//**************************************************************** //~v5h6I~
//	ucs-->utf;ucscode by \uxxxx fmt                                //~v5h6I~
//	rc: ucs err count                                              //~v5h6I~
//**************************************************************** //~v5h6I~
int ucvsescucs2utf(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v5h6I~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr)         //~v5h6R~
{                                                                  //~v5h6I~
	int rc=0,outreslen,ucssz,utflen,reslen,errctr=0,rc2;           //~v5h6R~
	int shortrecsw,escucssw;                                       //~v5h6I~
	ULONG ucscode=0;                                                 //~v5h6I~//~v6h7R~
    char *pucs,*putf,utf[4],xcvwk[4];                              //~v5h6R~
//*******************************                                  //~v5h6I~
    for (reslen=Pibufflen,pucs=Pibuff,outreslen=Pobufflen,putf=Pobuff;reslen>0;)//~v5h6I~
    {                                                              //~v5h6I~
    	shortrecsw=0;                                              //~v5h6I~
        escucssw=0;                                                //~v5h6I~
    	if (*pucs=='\\')                                           //~v5h6I~
        {                                                          //~v5h6I~
			if (reslen==1)                                         //~v5h6I~
            	shortrecsw=2;                                      //~v5h6I~
            else                                                   //~v5h6I~
            {                                                      //~v5h6I~
            	if (*(pucs+1)=='u')	// \\u                         //~v5h6I~
                {                                                  //~v5h6I~
                	if (reslen<6)                                  //~v5h6I~
                    	shortrecsw=1;                              //~v5h6I~
                    else                                           //~v5h6I~
                    	escucssw=1;                                //~v5h6I~
                }                                                  //~v5h6I~
            }                                                      //~v5h6I~
        }                                                          //~v5h6I~
                                                                   //~v5h6I~
        if (Popt & UCVUCS_FULLREC)    //eol is eof for ucs input   //~v5h6I~
        {                                                          //~v5h6I~
        	if (shortrecsw==1) 	//\u but len<6                     //~v5h6I~
            {                                                      //~v5h6I~
	            if (Pferr)                                         //~v5h6I~
//		            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,reslen);//~v5h6I~//~v6hhR~
		            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
        	    rc|=UCVUCS_FMTERR;                                 //~v5h6I~
            	errctr++;                                          //~v5h6R~
	            break;                                             //~v5h6I~
          	}                                                      //~v5h6I~
        }                                                          //~v5h6I~
        else                                                       //~v5h6I~
        {                                                          //~v5h6I~
        	if (shortrecsw)                                        //~v5h6I~
            {                                                      //~v5h6I~
	            rc|=UCVUCS_LENERR;                                 //~v5h6I~
	            break;                                             //~v5h6I~
            }                                                      //~v5h6I~
        }                                                          //~v5h6I~
        if (escucssw)                                              //~v5h6I~
        {                                                          //~v5h6I~
        	rc2=ugethex(pucs+2,xcvwk,4);                           //~v5h6R~
            if (rc2==2)                                            //~v5h6R~
            	ucscode=(ULONG)((xcvwk[0]<<8)|xcvwk[1]);           //~v5h6R~
            else                                                   //~v5h6I~
            	escucssw=0;                                        //~v5h6I~
        }                                                          //~v5h6I~
        if (escucssw)                                              //~v5h6I~
        {                                                          //~v5h6I~
            ucssz=6;		//input \uxxxx fmt len                 //~v5h6I~
//          utflen=uccvucs2utf(ucscode,utf);                       //~v5h6I~//+v6BkR~
            utflen=uccvucs2utf((UWUCS)ucscode,utf);                //+v6BkI~
            if (!utflen)   //conv err                              //~v5h6I~
            {                                                      //~v5h6I~
                if (Pferr)                                         //~v5h6I~
//                  Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,1);//~v5h6I~//~v6hhR~
                    Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,1);//~v6hhI~
                errctr++;                                          //~v5h6I~
                rc|=UCVUCS_FMTERR;                                 //~v5h6I~
                utflen=uccvucs2utf(UCVERRUCS,utf);                 //~v5h6I~
            }                                                      //~v5h6I~
            if (!outreslen      //for fmt err case                 //~v5h6I~
            ||outreslen<utflen)                                    //~v5h6I~
            {                                                      //~v5h6I~
                if (Pferr)                                         //~v5h6I~
//                  Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,0);//~v5h6I~//~v6hhR~
                    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,0);//~v6hhI~
                rc|=UCVUCS_BUFFOVF;                                //~v5h6I~
                break;                                             //~v5h6I~
            }                                                      //~v5h6I~
            if (utflen)                                            //~v5h6I~
                memcpy(putf,utf,(UINT)utflen);                     //~v5h6I~
        }//valid fmt                                               //~v5h6I~
        else                                                       //~v5h6I~
        {                                                          //~v5h6I~
        	ucssz=1;	//advance 1 byte                           //~v5h6I~
            utflen=1;                                              //~v5h6I~
            *putf=*pucs;                                           //~v5h6I~
        }                                                          //~v5h6I~
        outreslen-=utflen;                                         //~v5h6I~
        putf+=utflen;                                              //~v5h6I~
        reslen-=ucssz;                                             //~v5h6I~
        pucs  +=ucssz;                                             //~v5h6I~
    }//for                                                         //~v5h6I~
    *Ppchklen=Pibufflen-reslen;                                    //~v5h6I~
    *Ppoutlen=Pobufflen-outreslen;                                 //~v5h6I~
    *Pperrctr=errctr;                                              //~v5h6R~
    if (Pferr)                                                     //~v5h6I~
        Pferr(0,*Ppchklen,*Ppoutlen,Pibuff,0);                     //~v5h6I~
    return rc;                                                     //~v5h6I~
}//ucvsescucs2utf                                                  //~v5h6I~
//*************************************************
// string conv sjis  --> utf
//parm1:opt
//parm2:sjis  buff
//parm3:ucs  bufflen
//parm4:utf buff
//parm5:utf bufflen
//parm6:output conv len until length shortage
//ret  :rc len-err(last is dbcs 1st half)
//*************************************************
int ucvssjis2utf(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr)         //~v57iR~
{
	int   rc=0,utflen,reslen,outreslen,sjis,sjislen;               //~v57cR~
    UCHAR *putf,*psjis,utf[4];
    int errctr=0,rcs;                                              //~v57iR~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
    int sw2byte;                                                   //~v614I~
#endif                                                             //~v614I~
//****************************************
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
	if (Popt & UCVUCS_MB) //locale->utf                            //~v61gI~
    	return ucvsmb2utf(Pferr,Popt,Pibuff,Pibufflen,Pobuff,Pobufflen,Ppchklen,Ppoutlen,Pperrctr);//~v61gI~
#endif                                                             //~v61gI~
    for (reslen=Pibufflen,psjis=Pibuff,outreslen=Pobufflen,putf=Pobuff;reslen>0;)
    {
        sjis=*psjis;                                               //~v57cI~
        sjislen=1;                                                 //~v57cI~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
	    if (Popt & UCVUCS_EUC) //euc->utf                          //~v614I~
        	sw2byte=ISEUC(*psjis)||*psjis==SS2;		//dbcs 1st byte or hankana leading byte//~v614R~
        else	                                                   //~v614I~
        	sw2byte=SJIS1(*psjis);		//dbcs 1st byte            //~v614I~
		if (sw2byte)                                               //~v614I~
#else                                                              //~v614I~
        if (SJIS1(*psjis))		//dbcs 1st byte
#endif                                                             //~v614I~
        {
            if (reslen==1)
            {                                                      //~v57cI~
                if (!(Popt & UCVUCS_FULLREC))
                {
		        	if (Pferr)                                     //~v57iI~
//			            Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,reslen);//~v57mR~//~v6hhR~
			            Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
	             	rc|=UCVUCS_LENERR;
	                break;
	            }
            }
            else
            {
            	sjislen=2;                                         //~v57cI~
                sjis=(sjis<<8)+*(psjis+1);                         //~v57cR~
            }
        }
        psjis+=sjislen;                                            //~v57cI~
        reslen-=sjislen;                                           //~v57cR~
//      utflen=uccvsjis2utf(sjis,utf);                             //~v57iR~
//      rcs=uccvsjis2utf(sjis,utf,&utflen);                        //~v57kR~
        rcs=uccvsjis2utf(Popt,sjis,utf,&utflen);                   //~v57kR~
        if (rcs)                                                   //~v57iI~
        {                                                          //~v57iI~
        	if (Pferr)                                             //~v57iI~
//	            Pferr(rcs,Pibufflen-reslen-sjislen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,sjislen);//~v57mR~//~v6hhR~
	            Pferr(rcs,Pibufflen-reslen-sjislen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,sjislen);//~v6hhI~
            errctr++;                                              //~v57iI~
        }                                                          //~v57iI~
        rc|=rcs;                                                   //~v57iI~
//printf("usjis-->utf offs=%08x,outoffs=%08x,sjis=%04x,utflen=%d,utf=%08x,%*.*s\n",//~v57cR~
//				Pibufflen-reslen,Pobufflen-outreslen,              //~v57cR~
//				sjis,utflen,*(ULONG*)utf,utflen,utflen,utf);       //~v57cR~
    	if (!outreslen 		//for fmt err case
		||outreslen<utflen)
        {
            if (Pferr)                                             //~v57iI~
//			    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,0);//~v57mR~//~v6hhR~
			    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,0);//~v6hhI~
	        rc|=UCVUCS_BUFFOVF;
            break;
        }
        memcpy(putf,utf,(UINT)utflen);                             //~v57jR~
        outreslen-=utflen;
        putf+=utflen;
    }
    *Ppchklen=Pibufflen-reslen;
    *Ppoutlen=Pobufflen-outreslen;
    *Pperrctr=errctr;                                              //~v57iI~
    if (Pferr)                                                     //~v57iR~
        Pferr(0,*Ppchklen,*Ppoutlen,Pibuff,0);                     //~v57mR~
    return rc;
}//ucvssjis2utf
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
//*************************************************                //~v61gI~
// string conv mb(locale) --> utf                                  //~v61gI~
//parm1:opt                                                        //~v61gI~
//parm2:sjis  buff                                                 //~v61gI~
//parm3:ucs  bufflen                                               //~v61gI~
//parm4:utf buff                                                   //~v61gI~
//parm5:utf bufflen                                                //~v61gI~
//parm6:output conv len until length shortage                      //~v61gI~
//ret  :converr|out overflow                                       //~v61gI~
//*************************************************                //~v61gI~
int ucvsmb2utf(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v61gI~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr)         //~v61gI~
{                                                                  //~v61gI~
#ifdef LNX                                                         //~v61gI~
    iconv_t hiconv=0;                                              //~v61gI~
#endif                                                             //~v61gI~
//  ULONG *phandle;                                                //~v61gI~//~v6hhR~
    ULPTR *phandle;                                                //~v6hhI~
	int   rc=0,utflen,reslen,outreslen,chklen,opt;                 //~v61gR~
    UCHAR *putf,*pmb;                                              //~v61gR~
    int errctr=0,rcs,repch;                                        //~v61gR~
#ifdef LNX                                                         //~v6r0I~
    ULPTR ulp;                                                     //~v6r0I~
#endif                                                             //~v6r0I~
//****************************************                         //~v61gI~
#ifdef LNX                                                         //~v61gI~
//	phandle=(ULONG*)(ULONG)&hiconv;                                //~v61gR~//~v6r0R~
	ulp=(ULPTR)(&hiconv);                                          //~v6r0I~
//  phandle=(ULONG*)ulp;                                           //~v6x5R~
    phandle=(ULPTR*)ulp;                                           //~v6x5I~
#else                                                              //~v61gR~
    phandle=0;                                                     //~v61gI~
#endif                                                             //~v61gI~
    opt=0;                                                         //~v61gI~
    repch=(int)(Popt & UCVUCS_ERRCH);                              //~v61gI~
    for (reslen=Pibufflen,pmb=Pibuff,outreslen=Pobufflen,putf=Pobuff;reslen>0;)//~v61gI~
    {                                                              //~v61gI~
	  if (UDBCSCHK_IS_LOCALICU())                                  //~v6f3I~
		rcs=utfcvl2fany1ICU(opt,0/*locale*/,phandle,putf,outreslen,pmb,reslen,&chklen,&utflen);//~v6f3I~
      else                                                         //~v6f3I~
		rcs=utfcvl2fany1(opt,0,phandle,putf,outreslen,pmb,reslen,&chklen,&utflen);//~v61gR~
        if (rcs & UTFCVRC_SEVERR)	//iconv open err               //~v61gI~
        {                                                          //~v61gI~
            rc|=UCVUCS_CONVERR;                                    //~v61gI~
            break;                                                 //~v61gI~
        }                                                          //~v61gI~
        outreslen-=utflen;                                         //~v61gM~
        putf+=utflen;                                              //~v61gM~
        reslen-=chklen;                                            //~v61gI~
        pmb+=chklen;                                               //~v61gI~
        if (!rcs)                                                  //~v61gR~
        {                                                          //~v61gI~
			if (reslen) 		//input exausted                   //~v61gI~
            	continue;                                          //~v61gI~
        	break;                                                 //~v61gI~
        }                                                          //~v61gI~
    	if (rcs==UTFCVRC_ERROVF||outreslen==0) 		//buff overflow//~v61gI~
        {                                                          //~v61gI~
            if (Pferr)                                             //~v61gI~
//			    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,0);//~v61gI~//~v6hhR~
			    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,0);//~v6hhI~
	        rc|=UCVUCS_BUFFOVF;                                    //~v61gI~
            break;                                                 //~v61gI~
        }                                                          //~v61gI~
        rcs=UCVUCS_CONVERR;                                        //~v61gI~
        if (Pferr)                                                 //~v61gR~
//	    	Pferr(rcs,Pibufflen-reslen,(int)((ULONG)putf-(ULONG)Pobuff),Pibuff,1/*errlen*/);//~v61gR~//~v6hhR~
	    	Pferr(rcs,Pibufflen-reslen,(int)((ULPTR)putf-(ULPTR)Pobuff),Pibuff,1/*errlen*/);//~v6hhI~
        errctr++;                                                  //~v61gR~
        rc|=rcs;                                                   //~v61gR~
//      *putf++=repch;                                             //~v61gR~//~v6BiR~
        *putf++=(UCHAR)repch;                                      //~v6BiI~
        outreslen--;                                               //~v61gI~
        reslen--;                                                  //~v61gI~
        pmb++;                                                     //~v61gI~
    }                                                              //~v61gI~
    *Ppchklen=Pibufflen-reslen;                                    //~v61gI~
    *Ppoutlen=Pobufflen-outreslen;                                 //~v61gI~
    *Pperrctr=errctr;                                              //~v61gI~
    if (Pferr)                                                     //~v61gI~
        Pferr(0,*Ppchklen,*Ppoutlen,Pibuff,0);                     //~v61gI~
#ifdef LNX                                                         //~v61gI~
  if (!UDBCSCHK_IS_LOCALICU())                                     //~v6f3I~
    if (hiconv)	//UTF8MODEENV                                      //~v61gI~
		utfcvlocaletclose(0,(ULONG)hiconv);//close temporary(reset ptr)//~v61gR~
#endif                                                             //~v61gI~
UTRACEP("ucvsmb2utf rc=%x,err%d\n",rc,errctr);                     //~v61gR~
UTRACED("in",Pibuff,Pibufflen);                                    //~v61gI~
UTRACED("out",Pobuff,*Ppoutlen);                                   //~v61gI~
    return rc;                                                     //~v61gI~
}//ucvsmb2utf                                                      //~v61gI~
#endif	//UTF8                                                     //~v61gR~
//*************************************************
// string conv utf-8 --> ucs
//parm1:opt
//parm2:utf buff
//parm3:utf bufflen
//parm4:ucs  buff
//parm5:ucs  bufflen
//parm6:output conv len until length shortage
//ret  :rc
//*************************************************
int ucvsutf2ucs(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr)         //~v57cR~
{
	int   rc=0,ucssz,rcs,chklen,reslen,outreslen,errctr=0;         //~v57cR~
    int outlen;                                                    //~v5h6I~
    UCHAR *putf,*pucs;
#ifdef UTF8SUPPH                                                   //~v622I~
    int asciisw=1;                                                 //~v622I~
#endif                                                             //~v622I~
//****************************************
    if (Popt & UCVUCS_UCS4) //not accept ucs4
    	ucssz=4;
    else
    	ucssz=2;
    if (Popt & UCVUCS_ESCUCS) //output is \uxxxx unicode fmt       //~v5h6I~
    	ucssz+=ucssz+2;                                            //~v5h6I~
    for (reslen=Pibufflen,putf=Pibuff,outreslen=Pobufflen,pucs=Pobuff;reslen>0;)
    {
    	if (outreslen<ucssz)
        {
            if (Pferr)                                             //~v57iI~
//			    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULONG)pucs-(ULONG)Pobuff),Pibuff,0);//~v57mR~//~v6hhR~
			    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULPTR)pucs-(ULPTR)Pobuff),Pibuff,0);//~v6hhI~
	        rc|=UCVUCS_BUFFOVF;
            break;
        }
#ifdef UTF8SUPPH                                                   //~v62JM~
        if (*putf<0x80)                                            //~v62JI~
        	if (Popt & UCVUCS_ASCIIRET)                            //~v62JR~
            {                                                      //~v62JI~
		        rc|=UCVUCSRC_ASCII;                                //~v62JR~
                break;                                             //~v62JI~
            }                                                      //~v62JI~
#endif                                                             //~v62JI~
//      rcs=uccvutf2ucss(Popt,putf,reslen,pucs,&chklen);           //~v5h6R~
//      rcs=uccvutf2ucss(Popt,putf,reslen,pucs,&chklen,&outlen);   //~v5h6I~//~v6uYR~
        rcs=uccvutf2ucss(Popt,putf,reslen,pucs,outreslen,&chklen,&outlen);//~v6uYR~
//printf("utf->ucs offs=%08x,outoffs=%08x,rc=%d,utf=%08x,%c%c%c%c, chklen=%d,ucs=%02x\n",//~v57cR~
//				Pibufflen-reslen,Pobufflen-outreslen,              //~v57cR~
//			rcs,*(ULONG*)(ULONG)putf,*putf,*(putf+1),*(putf+2),*(putf+3),chklen,*(USHORT*)(ULONG)pucs);//~v57cR~
        rc|=rcs;
		if (rcs==UCVUCS_LENERR)
        {                                                          //~v57iI~
            if (Pferr)                                             //~v57iI~
//			    Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULONG)pucs-(ULONG)Pobuff),Pibuff,reslen);//~v57mR~//~v6hhR~
			    Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULPTR)pucs-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
          if (!(Popt & UCVUCS_LENERRREP))                          //~v695I~
        	break;
        }                                                          //~v57iI~
		if (rcs==UCVUCS_FMTERR)                                    //~v57cI~
        {                                                          //~v57iI~
            if (Pferr)                                             //~v57iI~
//			    Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULONG)pucs-(ULONG)Pobuff),Pibuff,chklen);//~v57mR~//~v6hhR~
			    Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULPTR)pucs-(ULPTR)Pobuff),Pibuff,chklen);//~v6hhI~
        	errctr++;                                              //~v57cI~
        }                                                          //~v57iI~
        if (rcs)                                                   //~v5n8I~
			if (Popt & UCVUCS_ERRSTOP)  //no breplace by subchar but returns err//~v5n8I~
	        	break;                                             //~v5n8I~
        reslen-=chklen;
        putf+=chklen;
#ifdef UTF8SUPPH                                                   //~v62gI~
        if (chklen!=1)  //not ascii                                //~v622I~
            asciisw=0;                                             //~v622I~
#endif                                                             //~v62gI~
//      outreslen-=ucssz;                                          //~v5h6R~
//      pucs+=ucssz;                                               //~v5h6R~
        outreslen-=outlen;                                         //~v5h6I~
        pucs+=outlen;                                              //~v5h6I~
    }
    *Ppchklen=Pibufflen-reslen;
    *Ppoutlen=Pobufflen-outreslen;
    *Pperrctr=errctr;                                              //~v57cI~
    if (Pferr)                                                     //~v57iR~
        Pferr(0,*Ppchklen,*Ppoutlen,Pibuff,0);                     //~v57mR~
#ifdef UTF8SUPPH                                                   //~v622I~
    if (!rc && asciisw && (Popt & UCVUCS_RETALLA))                 //~v622I~
 		rc=UCVUCS_ALLASCII;                                        //~v622I~
#endif                                                             //~v622I~
    return rc;
}//ucvsutf2ucs
//*************************************************
// string conv utf-8 --> sjis
//parm1:opt
//parm2:ucscode when err
//parm3:utf buff
//parm4:utf bufflen
//parm5:ucs  buff
//parm6:ucs  bufflen
//parm7:output conv len until length shortage
//ret  :rc
//*************************************************
int ucvsutf2sjis(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pprepctr)         //~v57cR~
{
	int   rc=0,sjislen,rcs,chklen,reslen,outreslen,sjis,dbcssw,repctr=0;//~v57cR~
    UCHAR *putf,*psjis;
#ifdef UTF8SUPPH                                                   //~v622I~
    int asciisw=1;                                                 //~v622I~
    int swerrch;                                                   //~v62gI~
#endif                                                             //~v622I~
//****************************************
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
	if (Popt & UCVUCS_MB) //locale->utf                            //~v61gI~
    	return ucvsutf2mb(Pferr,Popt,Pibuff,Pibufflen,Pobuff,Pobufflen,Ppchklen,Ppoutlen,Pprepctr);//~v61gR~
#endif                                                             //~v61gI~
    for (reslen=Pibufflen,putf=Pibuff,outreslen=Pobufflen,psjis=Pobuff;reslen>0;)
    {
#ifdef UTF8SUPPH                                                   //~v62JI~
        if (*putf<0x80)                                            //~v62JI~
        	if (Popt & UCVUCS_ASCIIRET)                            //~v62JI~
            {                                                      //~v62JI~
		        rc|=UCVUCSRC_ASCII;                                //~v62JI~
                break;                                             //~v62JI~
            }                                                      //~v62JI~
#endif                                                             //~v62JI~
		rcs=uccvutf2sjis(Popt,putf,reslen,&sjis,&chklen);
//printf("utf->ucs offs=%08x,outoffs=%08x,rc=%d,utf=%08x,%c%c%c%c, chklen=%d,sjis=%02x(%c%c)\n",//~v57cR~
//				Pibufflen-reslen,Pobufflen-outreslen,              //~v57cR~
//			rcs,*(ULONG*)(ULONG)putf,*putf,*(putf+1),*(putf+2),*(putf+3),chklen,sjis,sjis>>8,sjis&255);//~v57cR~
        rc|=rcs;
#ifdef UTF8SUPPH                                                   //~v62gI~
        swerrch=0;                                                 //~v62gI~
#endif                                                             //~v62gI~
//      if (rcs==UCVUCS_FMTERR||(UINT)sjis==UCVERRUCS)             //~v57mR~//~v695R~
        if (rcs==UCVUCS_FMTERR||(UINT)sjis==UCVERRUCS              //~v695I~
        ||  (rcs==UCVUCS_LENERR && (Popt & UCVUCS_LENERRREP))      //~v695I~
        )                                                          //~v695I~
        {                                                          //~v57cI~
        	repctr++;                                              //~v57cI~
        	sjis=(int)(Popt & UCVUCS_ERRCH);                       //~v57mR~
            rc|=UCVUCS_FMTERR;                                     //~v57cI~
            if (Pferr)                                             //~v57iI~
            {                                                      //~v695I~
  			  if (rcs==UCVUCS_LENERR)                              //~v695I~
//			    Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULONG)psjis-(ULONG)Pobuff),Pibuff,reslen);//~v695I~//~v6hhR~
			    Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULPTR)psjis-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
              else                                                 //~v695I~
//			    Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULONG)psjis-(ULONG)Pobuff),Pibuff,chklen);//~v57mR~//~v6hhR~
			    Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULPTR)psjis-(ULPTR)Pobuff),Pibuff,chklen);//~v6hhI~
            }                                                      //~v695I~
#ifdef UTF8SUPPH                                                   //~v62fI~
        	if (Popt & UCVUCS_ERRSTOP)                             //~v62gI~
            	break;                  //return                   //~v62gI~
        	if (Popt & UCVUCS_UTFERR1)                             //~v62fI~
            {                                                      //~v62fI~
          		if (!sjis) //no errrep ch                          //~v62gR~
        			sjis=(int)*putf;                               //~v62gR~
                swerrch=1;                                         //~v62gI~
            	chklen=1;                                          //~v62fI~
            }                                                      //~v62fI~
#endif                                                             //~v62fI~
        }                                                          //~v57cI~
#ifdef UTF8SUPPH                                                   //~v62gI~
      if (swerrch)                                                 //~v62gR~
        dbcssw=0;                                                  //~v62gI~
      else                                                         //~v62gI~
#endif                                                             //~v62gI~
        dbcssw=(sjis & 0xff00)!=0;
#ifdef UTF8SUPPH                                                   //~v622I~
    	if (dbcssw)                                                //~v622I~
 			asciisw=0;                                             //~v622I~
#endif                                                             //~v622I~
        sjislen=dbcssw+1;
    	if (outreslen<sjislen)
        {
	        rc|=UCVUCS_BUFFOVF;
            if (Pferr)                                             //~v57iI~
//			    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULONG)psjis-(ULONG)Pobuff),Pibuff,0);//~v57mR~//~v6hhR~
			    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULPTR)psjis-(ULPTR)Pobuff),Pibuff,0);//~v6hhI~
            break;
        }
//  	if (rcs==UCVUCS_LENERR)                                    //~v695R~
        if  (rcs==UCVUCS_LENERR && !(Popt & UCVUCS_LENERRREP))     //~v695I~
        {                                                          //~v57iI~
            if (Pferr)                                             //~v57iI~
//			    Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULONG)psjis-(ULONG)Pobuff),Pibuff,reslen);//~v57mR~//~v6hhR~
			    Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULPTR)psjis-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
        	break;
        }                                                          //~v57iI~
        if (dbcssw)
        	*psjis++=(UCHAR)((UINT)sjis>>8);                       //~v57cR~
        *psjis++=(UCHAR)(sjis & 0xff);                             //~v57cR~
        outreslen-=sjislen;
        reslen-=chklen;
        putf+=chklen;
    }
    *Ppchklen=Pibufflen-reslen;
    *Ppoutlen=Pobufflen-outreslen;
    *Pprepctr=repctr;                                              //~v57cI~
    if (Pferr)                                                     //~v57iR~
        Pferr(0,*Ppchklen,*Ppoutlen,Pibuff,0);                     //~v57mR~
#ifdef UTF8SUPPH                                                   //~v622I~
    if (!rc && asciisw && (Popt & UCVUCS_RETALLA))                 //~v622I~
 		rc=UCVUCS_ALLASCII;                                        //~v622I~
#endif                                                             //~v622I~
UTRACEP("ucvutf2sjis rc=%d,opt=%x,chklen=%d,inplen=%d\n",rc,Popt,*Ppchklen,Pibufflen);//~v62gI~
    return rc;
}//ucvsutf2sjis
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
//*************************************************                //~v61gI~
// string conv utf-8 <--> mb(locale)                               //~v61gI~
//parm1:opt                                                        //~v61gI~
//parm2:ucscode when err                                           //~v61gI~
//parm3:utf buff                                                   //~v61gI~
//parm4:utf bufflen                                                //~v61gI~
//parm5:ucs  buff                                                  //~v61gI~
//parm6:ucs  bufflen                                               //~v61gI~
//parm7:output conv len until length shortage                      //~v61gI~
//ret  :rc converr buff ovf                                        //~v61gI~
//*************************************************                //~v61gI~
int ucvsutf2mb(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v61gI~
				int *Ppchklen,int *Ppoutlen,int *Pprepctr)         //~v61gI~
{                                                                  //~v61gI~
#ifdef LNX                                                         //~v61gI~
    iconv_t hiconv=0;                                              //~v61gI~
#endif                                                             //~v61gI~
//  ULONG *phandle;                                                //~v6x5R~
    ULPTR *phandle;                                                //~v6x5I~
	int   rc=0,repch,rcs,chklen,reslen,outreslen,mblen,repctr=0,opt;//~v61gR~
    UCHAR *putf,*pmb;                                              //~v61gR~
#ifdef LNX                                                         //~v6r0I~
    ULPTR ulp;                                                     //~v6r0I~
#endif                                                             //~v6r0I~
//****************************************                         //~v61gI~
    UTRACED("inp",Pibuff,Pibufflen);                               //~v6uFI~
#ifdef LNX                                                         //~v61gI~
//  phandle=(ULONG*)(ULONG)&hiconv;                                //~v61gI~//~v6r0R~
    ulp=(ULPTR)(&hiconv);                                          //~v6r0I~
//  phandle=(ULONG*)ulp;                                           //~v6x5R~
    phandle=(ULPTR*)ulp;                                           //~v6x5I~
#else                                                              //~v61gR~
    phandle=0;                                                     //~v61gI~
#endif                                                             //~v61gI~
    repch=(int)(Popt & UCVUCS_ERRCH);                              //~v61gI~
    opt=0;                                                         //~v61gI~
    for (reslen=Pibufflen,putf=Pibuff,outreslen=Pobufflen,pmb=Pobuff;reslen>0;)//~v61gI~
    {                                                              //~v61gI~
#ifdef UTF8SUPPH                                                   //~v62JI~
        if (*putf<0x80)                                            //~v62JI~
        	if (Popt & UCVUCS_ASCIIRET)                            //~v62JI~
            {                                                      //~v62JI~
		        rc|=UCVUCSRC_ASCII;                                //~v62JI~
                break;                                             //~v62JI~
            }                                                      //~v62JI~
#endif                                                             //~v62JI~
	  if (UDBCSCHK_IS_LOCALICU())                                  //~v6f3I~
		rcs=utfcvf2lany1ICU(opt,0/*locale*/,phandle,pmb,outreslen,putf,reslen,&chklen,&mblen);//~v6f3I~
      else                                                         //~v6f3I~
		rcs=utfcvf2lany1(opt,0/*locale*/,phandle,pmb,outreslen,putf,reslen,&chklen,&mblen);//~v61gR~
        if (rcs & UTFCVRC_SEVERR)	//iconv open err               //~v61gI~
        {                                                          //~v61gI~
            rc|=UCVUCS_CONVERR;                                    //~v61gI~
            break;                                                 //~v61gI~
        }                                                          //~v61gI~
        outreslen-=mblen;                                          //~v61gI~
        pmb+=mblen;                                                //~v61gR~
        reslen-=chklen;                                            //~v61gI~
        putf+=chklen;                                              //~v61gI~
        if (!rcs)                                                  //~v61gI~
        {                                                          //~v61gI~
			if (reslen) 		//input exausted                   //~v61gI~
            	continue;                                          //~v61gI~
        	break;                                                 //~v61gI~
        }                                                          //~v61gI~
    	if (rcs==UTFCVRC_ERROVF||outreslen==0) 		//buff overflow//~v61gI~
        {                                                          //~v61gI~
	        rc|=UCVUCS_BUFFOVF;                                    //~v61gI~
            if (Pferr)                                             //~v61gI~
//			    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULONG)pmb-(ULONG)Pobuff),Pibuff,0);//~v61gI~//~v6hhR~
//  		    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULPTR)pmb-(ULPTR)Pobuff),Pibuff,0);//~v6hhI~//~v6uTR~
//  		    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen-chklen,(int)((ULPTR)pmb-(ULPTR)Pobuff-mblen),Pibuff,0);//~v6uTI~//+v6BkR~
    		    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen-chklen,PTRDIFF(pmb,Pobuff)-mblen,Pibuff,0);//+v6BkI~
            break;                                                 //~v61gI~
        }                                                          //~v61gI~
        rc|=UCVUCS_CONVERR;                                        //~v61gR~
        if (Popt & UCVUCS_ERRSTOP)                                 //~v62gI~
            break;                  //return                       //~v62gI~
        repctr++;                                                  //~v61gI~
        if (Pferr)                                                 //~v61gR~
//			Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULONG)pmb-(ULONG)Pobuff),Pibuff,1);//~v61gR~//~v6hhR~
//  		Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULPTR)pmb-(ULPTR)Pobuff),Pibuff,1);//~v6hhI~//~v6uTR~
//  		Pferr(UCVUCS_FMTERR,Pibufflen-reslen-chklen,(int)((ULPTR)pmb-(ULPTR)Pobuff-mblen),Pibuff,chklen);//~v6uTR~//+v6BkR~
    		Pferr(UCVUCS_FMTERR,Pibufflen-reslen-chklen,PTRDIFF(pmb,Pobuff)-mblen,Pibuff,chklen);//+v6BkI~
      if (!mblen)                                                  //~v6f3I~
      {                                                            //~v6f3I~
//      *pmb++=repch;                                              //~v61gR~//~v6BiR~
        *pmb++=(UCHAR)repch;                                       //~v6BiI~
        outreslen--;                                               //~v61gR~
      }                                                            //~v6f3I~
      if (!chklen)                                                 //~v6f3I~
      {                                                            //~v6f3I~
        reslen--;                                                  //~v61gR~
        putf++;                                                    //~v61gR~
      }                                                            //~v6f3I~
    }                                                              //~v61gI~
    *Ppchklen=Pibufflen-reslen;                                    //~v61gI~
    *Ppoutlen=Pobufflen-outreslen;                                 //~v61gI~
    *Pprepctr=repctr;                                              //~v61gI~
    if (Pferr)                                                     //~v61gI~
        Pferr(0,*Ppchklen,*Ppoutlen,Pibuff,0);                     //~v61gI~
#ifdef LNX                                                         //~v61gI~
  if (!UDBCSCHK_IS_LOCALICU())                                     //~v6f3I~
    if (hiconv)	//UTF8MODEENV                                      //~v61gI~
		utfcvlocaletclose(0,(ULONG)hiconv);//close temporary(reset ptr)//~v61gR~
#endif                                                             //~v61gI~
UTRACEP("ucvutf2mb rc=%d,opt=%x,chklen=%d,inplen=%d\n",rc,Popt,*Ppchklen,Pibufflen);//~v62gI~
    return rc;                                                     //~v61gI~
}//ucvsutf2mb                                                      //~v62gR~
#endif                                                             //~v61gI~
//****************************************************************
//	string: sjis-->ucs
//****************************************************************
int ucvssjis2ucs(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pperrctr)         //~v57iR~
{
	int rc=0,sjis,outreslen,sjislen,ucssz,reslen;                  //~v57cR~
    int rcs,errctr=0;                                              //~v57iI~
    int outlen;                                                    //~v5h6I~
    char *psjis,*pucs;
//*******************************
    if (Popt & UCVUCS_UCS4) //not accept ucs4
    	ucssz=4;
    else
    	ucssz=2;
    if (Popt & UCVUCS_ESCUCS) //output is \uxxxx unicode fmt       //~v5h6I~
    	ucssz+=ucssz+2;                                            //~v5h6I~
    for (reslen=Pibufflen,psjis=Pibuff,outreslen=Pobufflen,pucs=Pobuff;reslen>0;)
    {
    	if (outreslen<ucssz)
        {
	        rc|=UCVUCS_BUFFOVF;
            if (Pferr)                                             //~v57iI~
//			    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULONG)pucs-(ULONG)Pobuff),Pibuff,0);//~v57mR~//~v6hhR~
			    Pferr(UCVUCS_BUFFOVF,Pibufflen-reslen,(int)((ULPTR)pucs-(ULPTR)Pobuff),Pibuff,0);//~v6hhI~
            break;
        }
    	sjis=*psjis;                                               //~v57cR~
        sjislen=1;
        if (SJIS1(sjis))
        {
            if (reslen==1)                                         //~v57cI~
            {                                                      //~v57cI~
                if (!(Popt & UCVUCS_FULLREC))                      //~v57cI~
                {                                                  //~v57cI~
		            if (Pferr)                                     //~v57iI~
//					    Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULONG)pucs-(ULONG)Pobuff),Pibuff,reslen);//~v57mR~//~v6hhR~
					    Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULPTR)pucs-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
	             	rc|=UCVUCS_LENERR;                             //~v57cI~
	                break;                                         //~v57cI~
	            }                                                  //~v57cI~
            }                                                      //~v57cI~
            else                                                   //~v57cI~
            {                                                      //~v57cI~
        		sjis=(sjis<<8)+*(psjis+1);                         //~v57cR~
            	sjislen=2;                                         //~v57cR~
            }                                                      //~v57cI~
        }
        reslen-=sjislen;                                           //~v57cI~
        psjis +=sjislen;                                           //~v57cI~
        rcs=                                                       //~v57iR~
//		uccvsjis2ucss(Popt,sjis,pucs);                             //~v5h6R~
		uccvsjis2ucss(Popt,sjis,pucs,&outlen);                     //~v5h6I~
        if (rcs)                                                   //~v57iR~
        {                                                          //~v57iI~
        	if (Pferr)                                             //~v57iI~
//	            Pferr(rcs,Pibufflen-reslen-sjislen,(int)((ULONG)pucs-(ULONG)Pobuff),Pibuff,sjislen);//~v57mR~//~v6hhR~
	            Pferr(rcs,Pibufflen-reslen-sjislen,(int)((ULPTR)pucs-(ULPTR)Pobuff),Pibuff,sjislen);//~v6hhI~
        	errctr++;                                              //~v57iI~
        }                                                          //~v57iI~
        rc|=rcs;                                                   //~v57iI~
//      outreslen-=ucssz;                                          //~v5h6R~
//      pucs+=ucssz;                                               //~v5h6R~
        outreslen-=outlen;                                         //~v5h6I~
        pucs+=outlen;                                              //~v5h6I~
    }//for
    *Ppchklen=Pibufflen-reslen;
    *Ppoutlen=Pobufflen-outreslen;
    *Pperrctr=errctr;                                              //~v57iR~
    if (Pferr)                                                     //~v57iR~
        Pferr(0,*Ppchklen,*Ppoutlen,Pibuff,0);                     //~v57mR~
//  return 0;                                                      //~v57iR~
    return rc;                                                     //~v57iI~
}//ucvssjis2ucs
//****************************************************************
//	ucs-->sjis
//	rc: ucs err count
//****************************************************************
int ucvsucs2sjis(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v57kR~
				int *Ppchklen,int *Ppoutlen,int *Pprepctr)         //~v57cR~
{
	int rc=0,dbcssw,outreslen,ucssz,sjis,sjislen,reslen,repctr=0;  //~v57cR~
    char *pucs,*psjis;
//*******************************
    if (Popt & UCVUCS_ESCUCS) //input is \uxxxx unicode fmt        //~v5b3I~
		return ucvsescucs2sjis(Pferr,Popt,Pibuff,Pibufflen,Pobuff,Pobufflen,//~v5b3I~
								Ppchklen,Ppoutlen,Pprepctr);       //~v5b3I~
    if (Popt & UCVUCS_UCS4) //not accept ucs4
    	ucssz=4;
    else
    	ucssz=2;
    for (reslen=Pibufflen,pucs=Pibuff,outreslen=Pobufflen,psjis=Pobuff;reslen>0;)
    {
        if (reslen<ucssz)
        {
        	                                                       //~v57iI~
          if (Popt & UCVUCS_FULLREC)    //eol is eof for ucs input //~v57iI~
          {                                                        //~v57iI~
            if (Pferr)                                             //~v57iI~
//	            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULONG)psjis-(ULONG)Pobuff),Pibuff,reslen);//~v57mR~//~v6hhR~
	            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULPTR)psjis-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
            rc|=UCVUCS_FMTERR;                                     //~v57iI~
            repctr++;                                              //~v57iI~
          }                                                        //~v57iI~
          else                                                     //~v57iI~
          {                                                        //~v57iI~
            if (Pferr)                                             //~v57iI~
//	            Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULONG)psjis-(ULONG)Pobuff),Pibuff,reslen);//~v57mR~//~v6hhR~
	            Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULPTR)psjis-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
            rc|=UCVUCS_LENERR;
          }                                                        //~v57iI~
            break;
        }
		sjis=uccvucss2sjis(Popt,pucs);
        if ((UINT)sjis==UCVERRUCS)                                 //~v57mR~
        {                                                          //~v57cI~
        	sjis=(int)(Popt & UCVUCS_ERRCH);                       //~v57mR~
            rc|=UCVUCS_FMTERR;                                     //~v57cI~
            if (Pferr)                                             //~v57iI~
//	            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULONG)psjis-(ULONG)Pobuff),Pibuff,ucssz);//~v57mR~//~v6hhR~
	            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULPTR)psjis-(ULPTR)Pobuff),Pibuff,ucssz);//~v6hhI~
            repctr++;                                              //~v57cI~
        }                                                          //~v57cI~
        dbcssw=(sjis & 0xff00)!=0;
        sjislen=dbcssw+1;
        if (reslen<sjislen)
        {
            rc|=UCVUCS_LENERR;
            if (Pferr)                                             //~v57iI~
//	            Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULONG)psjis-(ULONG)Pobuff),Pibuff,reslen);//~v57mR~//~v6hhR~
	            Pferr(UCVUCS_LENERR,Pibufflen-reslen,(int)((ULPTR)psjis-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
            break;
        }
        if (dbcssw)
        	*psjis++=(UCHAR)((UINT)sjis>>8);                       //~v57cR~
        *psjis++=(UCHAR)(sjis & 0xff);                             //~v57cR~
        outreslen-=sjislen;                                        //~v57cR~
        reslen-=ucssz;                                             //~v57cI~
        pucs  +=ucssz;                                             //~v57cI~
    }//for
    *Ppchklen=Pibufflen-reslen;                                    //~v57cR~
    *Ppoutlen=Pobufflen-outreslen;                                 //~v57cR~
    *Pprepctr=repctr;                                              //~v57cI~
    if (Pferr)                                                     //~v57iR~
        Pferr(0,*Ppchklen,*Ppoutlen,Pibuff,0);                     //~v57mR~
    return rc;
}//ucvsucs2sjis
//**************************************************************** //~v5b3I~
//	ucs-->sjis;ucscode by \uxxxx fmt                               //~v5b3I~
//	rc: ucs err count                                              //~v5b3I~
//**************************************************************** //~v5b3I~
int ucvsescucs2sjis(UCVUCS_FERR *Pferr,ULONG Popt,UCHAR *Pibuff,int Pibufflen,UCHAR *Pobuff,int Pobufflen,//~v5b3I~
				int *Ppchklen,int *Ppoutlen,int *Pprepctr)         //~v5b3I~
{                                                                  //~v5b3I~
	int rc=0,dbcssw,outreslen,ucssz,sjis,sjislen,reslen,repctr=0;  //~v5b3I~
    int rc2;                                                       //~v5h6I~
	int shortrecsw,escucssw;                                       //~v5b3R~
	ULONG ucscode=0;                                                 //~v5b3I~//~v6h7R~
    char *pucs,*psjis,xcvwk[4];                                    //~v5b3R~
//*******************************                                  //~v5b3I~
    for (reslen=Pibufflen,pucs=Pibuff,outreslen=Pobufflen,psjis=Pobuff;reslen>0;)//~v5b3I~
    {                                                              //~v5b3I~
    	shortrecsw=0;                                              //~v5b3I~
        escucssw=0;                                                //~v5b3I~
    	if (*pucs=='\\')                                           //~v5b3R~
        {                                                          //~v5b3I~
			if (reslen==1)                                         //~v5b3I~
            	shortrecsw=2;                                      //~v5b3R~
            else                                                   //~v5b3I~
            {                                                      //~v5b3I~
            	if (*(pucs+1)=='u')	// \\u                         //~v5b3I~
                {                                                  //~v5b3I~
                	if (reslen<6)                                  //~v5b3I~
                    	shortrecsw=1;                              //~v5b3I~
                    else                                           //~v5b3I~
                    	escucssw=1;                                //~v5b3I~
                }                                                  //~v5b3I~
            }                                                      //~v5b3I~
        }                                                          //~v5b3I~
                                                                   //~v5b3I~
        if (Popt & UCVUCS_FULLREC)    //eol is eof for ucs input   //~v5b3R~
        {                                                          //~v5b3I~
        	if (shortrecsw==1) 	//\u but len<6                     //~v5b3I~
            {                                                      //~v5b3I~
	            if (Pferr)                                         //~v5b3R~
//		            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULONG)psjis-(ULONG)Pobuff),Pibuff,reslen);//~v5b3R~//~v6hhR~
		            Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULPTR)psjis-(ULPTR)Pobuff),Pibuff,reslen);//~v6hhI~
        	    rc|=UCVUCS_FMTERR;                                 //~v5b3R~
            	repctr++;                                          //~v5b3R~
	            break;                                             //~v5b3I~
          	}                                                      //~v5b3R~
        }                                                          //~v5b3I~
        else                                                       //~v5b3R~
        {                                                          //~v5b3R~
        	if (shortrecsw)                                        //~v5b3I~
            {                                                      //~v5b3I~
	            rc|=UCVUCS_LENERR;                                 //~v5b3R~
	            break;                                             //~v5b3I~
            }                                                      //~v5b3I~
        }                                                          //~v5b3R~
        if (escucssw)                                              //~v5b3I~
        {                                                          //~v5b3I~
//      	rc=ugethex(pucs+2,xcvwk,4);                            //~v5h6R~
        	rc2=ugethex(pucs+2,xcvwk,4); //rc2=datalen             //~v5h6I~
//          if (rc==2)                                             //~v5h6R~
            if (rc2==2)                                            //~v5h6I~
            	ucscode=(ULONG)((xcvwk[0]<<8)|xcvwk[1]);           //~v5h6R~
            else                                                   //~v5b3I~
            	escucssw=0;                                        //~v5b3I~
        }                                                          //~v5b3I~
        if (escucssw)                                              //~v5b3I~
        {                                                          //~v5b3I~
            ucssz=6;                                               //~v5b3M~
//  		sjis=uccvucs2sjis(Popt,ucscode);                       //~v5b3R~//+v6BkR~
    		sjis=uccvucs2sjis(Popt,(UWUCS)ucscode);                //+v6BkI~
            if ((UINT)sjis==UCVERRUCS)                             //~v5b3I~
            {                                                      //~v5b3I~
                sjis=(int)(Popt & UCVUCS_ERRCH);                   //~v5b3I~
                rc|=UCVUCS_FMTERR;                                 //~v5b3I~
                if (Pferr)                                         //~v5b3I~
//                  Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULONG)psjis-(ULONG)Pobuff),Pibuff,ucssz);//~v5b3I~//~v6hhR~
                    Pferr(UCVUCS_FMTERR,Pibufflen-reslen,(int)((ULPTR)psjis-(ULPTR)Pobuff),Pibuff,ucssz);//~v6hhI~
                repctr++;                                          //~v5b3I~
            }                                                      //~v5b3I~
            dbcssw=(sjis & 0xff00)!=0;                             //~v5b3I~
            sjislen=dbcssw+1;                                      //~v5b3I~
            if (dbcssw)                                            //~v5b3I~
                *psjis++=(UCHAR)((UINT)sjis>>8);                   //~v5b3I~
        }//valid fmt                                               //~v5b3I~
        else                                                       //~v5b3I~
        {                                                          //~v5b3I~
        	ucssz=1;	//advance 1 byte                           //~v5b3I~
            sjislen=1;                                             //~v5b3I~
            sjis=*pucs;                                            //~v5b3I~
        }                                                          //~v5b3I~
        *psjis++=(UCHAR)(sjis & 0xff);                             //~v5b3I~
        outreslen-=sjislen;                                        //~v5b3I~
        reslen-=ucssz;                                             //~v5b3I~
        pucs  +=ucssz;                                             //~v5b3I~
    }//for                                                         //~v5b3I~
    *Ppchklen=Pibufflen-reslen;                                    //~v5b3I~
    *Ppoutlen=Pobufflen-outreslen;                                 //~v5b3I~
    *Pprepctr=repctr;                                              //~v5b3I~
    if (Pferr)                                                     //~v5b3I~
        Pferr(0,*Ppchklen,*Ppoutlen,Pibuff,0);                     //~v5b3I~
    return rc;                                                     //~v5b3I~
}//ucvsescucs2sjis                                                 //~v5b3I~
//****************************************************************
//	sjis-->ucs
//****************************************************************
int ucvfsjis2ucs(UCVUCS_FREAD *Pfread,UCVUCS_FWRITE *Pfwrite,UCVUCS_FERR *Pferr,//~v57iR~
			 ULONG Popt,UCHAR *Pibuff,int Pibuffsz,UCHAR *Pobuff,int Pobuffsz)//~v57kR~
{
	int len,rc,rcs=0,rct=0,readlen,reslen=0,outlen,chklen;         //~v57cR~
    int lineendid;                                                 //~v57hI~
    int totrep=0,repctr;                                           //~v57iI~
    char *psjis,*pucs;
//*******************************
	psjis=Pibuff;
	pucs=Pobuff;
    for (;;)
    {
	    rc=Pfread(psjis+reslen,Pibuffsz-reslen,&readlen);
        lineendid=0;                                               //~v57hI~
      if (rc==1)                                                   //~v57hI~
            lineendid=UCVUCS_FULLREC;                              //~v57hI~
      else                                                         //~v57hI~
        if (rc)
        	break;
    	len=readlen+reslen;
//      rcs=ucvssjis2ucs(Popt,psjis,len,pucs,Pobuffsz,&chklen,&outlen);//~v57hR~
//      rcs=ucvssjis2ucs(Pferr,Popt|lineendid,psjis,len,pucs,Pobuffsz,&chklen,&outlen,&repctr);//~v57iR~//+v6BkR~
        rcs=ucvssjis2ucs(Pferr,Popt|(ULONG)lineendid,psjis,len,pucs,Pobuffsz,&chklen,&outlen,&repctr);//+v6BkI~
        totrep+=repctr;                                            //~v57iI~
        rct|=rcs;
		Pfwrite(Pobuff,outlen);
        reslen=len-chklen;                                         //~v57cI~
        if (reslen)                                                //~v57cI~
	        memcpy(psjis,psjis+chklen,(UINT)reslen);               //~v57jR~
    }//for
    if (reslen)	//last is dbcs 1st byte                            //~v57cI~
    {                                                              //~v57cI~
		rcs=ucvssjis2ucs(Pferr,Popt|UCVUCS_FULLREC,psjis,reslen,pucs,Pobuffsz,&chklen,&outlen,&repctr);//~v57iR~
        totrep+=repctr;                                            //~v57iR~
		rct|=rcs;                                                  //~v57iI~
		Pfwrite(pucs,outlen);                                      //~v57cI~
    }                                                              //~v57cI~
    rct&=~UCVUCS_LENERR;
    ucverrsjis(Popt,rct,totrep);                                   //~v57iI~
    return rct;
}//ucvfsjis2ucs
//****************************************************************
//	ucs-->sjis
//	rc: ucs err count
//****************************************************************
int ucvfucs2sjis(UCVUCS_FREAD *Pfread,UCVUCS_FWRITE *Pfwrite,UCVUCS_FERR *Pferr,//~v57iR~
			 ULONG Popt,UCHAR *Pibuff,int Pibuffsz,UCHAR *Pobuff,int Pobuffsz)//~v57kR~
{
	int len,rc,rcs=0,rct=0,readlen,reslen=0,chklen,outlen,repctr,totrep=0;//~v57cR~
    int lineendid;                                                 //~v57iI~
    char *pucs,*psjis;
//*******************************
	pucs=Pibuff;
	psjis=Pobuff;
    for (;;)
    {
	    rc=Pfread(pucs+reslen,Pibuffsz-reslen,&readlen);
        lineendid=0;                                               //~v57iI~
      if (rc==1)    //not cont line                                //~v57iR~
            lineendid=UCVUCS_FULLREC;                              //~v57iI~
      else                                                         //~v57iI~
        if (rc)
        	break;
    	len=readlen+reslen;
//  	rcs=ucvsucs2sjis(Pferr,Popt|lineendid,pucs,len,psjis,Pobuffsz,&chklen,&outlen,&repctr);//~v57iR~//+v6BkR~
    	rcs=ucvsucs2sjis(Pferr,Popt|(ULONG)lineendid,pucs,len,psjis,Pobuffsz,&chklen,&outlen,&repctr);//+v6BkI~
        totrep+=repctr;                                            //~v57cI~
        rct|=rcs;
		Pfwrite(Pobuff,outlen);
        reslen=len-chklen;                                         //~v57cI~
        if (reslen)                                                //~v57cI~
        	memcpy(pucs,pucs+chklen,(UINT)reslen);                 //~v57jR~
    }//for
    if (rcs & UCVUCS_LENERR)	//last dbcs 1st
    {                                                              //~v57iI~
		rcs=ucvsucs2sjis(Pferr,Popt|UCVUCS_FULLREC,pucs,reslen,psjis,Pobuffsz,&chklen,&outlen,&repctr);//~v57mI~
        totrep+=repctr;                                            //~v57mI~
    	rct|=rcs;                                                  //~v57mR~
    }                                                              //~v57iI~
    ucverrucs(Popt,rct,totrep);                                    //~v57cR~
    return rct;
}//ucvfucs2sjis
//*************************************************
// file conv utf-8 --> ucs
//ret  :rc
//*************************************************
int ucvfutf2ucs(UCVUCS_FREAD *Pfread,UCVUCS_FWRITE *Pfwrite,UCVUCS_FERR *Pferr,//~v57iR~
			 ULONG Popt,UCHAR *Pibuff,int Pibuffsz,UCHAR *Pobuff,int Pobuffsz)//~v57kR~
{
    int  reslen=0,ucsbufflen,chklen,outlen,rcs=0,rct=0,sw1st=0,bomsz;//~v57cR~
    int  readlen,rc,repctr,totrep=0;                               //~v57kR~
    int lineendid,len;                                             //~v57mR~
    UCHAR *putf,*pucs,*putfc;
    ULONG lesw;                                                    //~v57kR~
//***********************************
    ucsbufflen=Pobuffsz;
	putf=Pibuff;
    pucs=Pobuff;
    for (;;)
    {
	    rc=Pfread(putf+reslen,Pibuffsz-reslen,&readlen);
        lineendid=0;                                               //~v57hI~
      if (rc==1)                                                   //~v57hI~
            lineendid=UCVUCS_FULLREC;                              //~v57hI~
      else                                                         //~v57hI~
        if (rc)
        	break;
        putfc=putf;
    	if (!sw1st)
        {
        	sw1st=1;
        	if (Popt & UCVUCS_BOM)           //chk 0xfeff
            {
				bomsz=ucvbomchk(&lesw,putf,readlen);
                if (bomsz)
                    Popt=lesw;                                     //~v57jR~
	            readlen-=bomsz;
    	        putfc=putf+bomsz;
            }
//printf("bomsz=%d,opt=%0x\n",bomsz,Popt);
        }//1st time
//printf("recoffs =%08x,outoffs=%08x\n",offs);
//  	rcs=ucvsutf2ucs(Popt,putfc,readlen+reslen,pucs,ucsbufflen,&chklen,&outlen,&repctr);//~v57hR~
    	len=readlen+reslen;                                        //~v57mI~
//  	rcs=ucvsutf2ucs(Pferr,Popt|lineendid,putfc,len,pucs,ucsbufflen,&chklen,&outlen,&repctr);//~v57mR~//+v6BkR~
    	rcs=ucvsutf2ucs(Pferr,Popt|(ULONG)lineendid,putfc,len,pucs,ucsbufflen,&chklen,&outlen,&repctr);//+v6BkI~
        totrep+=repctr;                                            //~v57cI~
//      offs+=chklen;
//      outoffs+=outlen;
        rct|=rcs;
        reslen=len-chklen;                                         //~v57mR~
        if (reslen)                                                //~v57cI~
	        memcpy(putf,putfc+chklen,(UINT)reslen);                //~v57jR~
//      fwrite(pucs,1,outlen,fho);
		Pfwrite(pucs,outlen);
    }//until eof
    if (reslen)	//remain data                                      //~v57mR~
    {                                                              //~v57iI~
    	rcs=ucvsutf2ucs(Pferr,Popt|UCVUCS_FULLREC,putf,reslen,pucs,ucsbufflen,&chklen,&outlen,&repctr);//~v57mI~
        totrep+=repctr;                                            //~v57mI~
        rct|=rcs;                                                  //~v57mI~
		Pfwrite(pucs,outlen);                                      //~v57mI~
    }                                                              //~v57iI~
    ucverrutf(Popt,rct,totrep);                                    //~v57cR~
    return rct;
}//ucvfutf2ucs
//*************************************************
// file conv ucs --> utf-8
//ret  :rc
//*************************************************
int ucvfucs2utf(UCVUCS_FREAD *Pfread,UCVUCS_FWRITE *Pfwrite,UCVUCS_FERR *Pferr,//~v57iR~
			 ULONG Popt,UCHAR *Pibuff,int Pibuffsz,UCHAR *Pobuff,int Pobuffsz)//~v57kR~
{
    int  reslen=0,chklen,outlen,rcs=0,rct=0,bomsz=0;               //~v57jR~
    int  readlen,utfbufflen,rc,errctr,toterr=0,len;                //~v57iR~
    int lineendid;                                                 //~v57iI~
    UCHAR *putf,*pucs;
//***********************************
	utfbufflen=Pobuffsz;
	pucs=Pibuff;
    putf=Pobuff;
    if (Popt & UCVUCS_BOM)           //chk 0xfeff
    {
		bomsz=ucvbomset(Popt,putf);
//printf("bom=%08x,%4.4s\n",*(ULONG*)(ULONG)putf,putf);
//  	Pfwrite(putf,bomsz);                                       //~v57jR~
//      totout+=bomsz;
    }//bom write
    for (;;)
    {
	    rc=Pfread(pucs+reslen,Pibuffsz-reslen,&readlen);           //~v57cR~
        lineendid=0;                                               //~v57iI~
      if (rc==1)    //not cont line                                //~v57iR~
            lineendid=UCVUCS_FULLREC;                              //~v57iI~
      else                                                         //~v57iI~
        if (rc)
        	break;
//printf("recoffs =%08x,outtot=%08x\n",offs,totout);
		len=readlen+reslen;                                        //~v57cI~
//  	rcs=ucvsucs2utf(Pferr,Popt|lineendid,pucs,len,putf+bomsz,utfbufflen-bomsz,&chklen,&outlen,&errctr);//~v57jR~//+v6BkR~
    	rcs=ucvsucs2utf(Pferr,Popt|(ULONG)lineendid,pucs,len,putf+bomsz,utfbufflen-bomsz,&chklen,&outlen,&errctr);//+v6BkI~
        toterr+=errctr;                                            //~v57cI~
//      totout+=outlen;                                            //~v57iR~
        rct|=rcs;
		Pfwrite(putf,outlen+bomsz);                                //~v57jR~
        reslen=len-chklen;                                         //~v57cI~
        if (reslen)                                                //~v57cI~
        	memcpy(pucs,pucs+chklen,(UINT)reslen);                 //~v57jR~
        bomsz=0;                                                   //~v57jI~
    }//until eof
    if (rcs & UCVUCS_LENERR)
    {                                                              //~v57iI~
		rcs=ucvsucs2utf(Pferr,Popt|UCVUCS_FULLREC,pucs,reslen,putf+bomsz,utfbufflen-bomsz,&chklen,&outlen,&errctr);//~v57mI~
        toterr+=errctr;                                            //~v57mI~
        rct|=rcs;                                                  //~v57mI~
    }                                                              //~v57iI~
    ucverrucs(Popt,rct,toterr);                                    //~v57mR~
    return rct;
}//ucvfucs2utf
//*************************************************
// file conv sjis--> utf-8
//ret  :rc
//*************************************************
int ucvfsjis2utf(UCVUCS_FREAD *Pfread,UCVUCS_FWRITE *Pfwrite,UCVUCS_FERR *Pferr,//~v57iR~
			 ULONG Popt,UCHAR *Pibuff,int Pibuffsz,UCHAR *Pobuff,int Pobuffsz)//~v57kR~
{
    int  reslen=0,chklen,outlen,rcs,rct=0,bomsz=0;                 //~v57jR~
    int  readlen,utfbufflen,rc,len;                                //~v57iR~
    int lineendid;                                                 //~v57hI~
    int errctr,totrep=0;                                           //~v57iI~
    UCHAR *putf,*psjis;
//***********************************
	psjis=Pibuff;
    putf=Pobuff;
    utfbufflen=Pobuffsz;
    if (Popt & UCVUCS_BOM)           //chk 0xfeff
    {
		bomsz=ucvbomset(Popt,putf);
//printf("bom=%08x,%4.4s\n",*(ULONG*)(ULONG)putf,putf);
//  	Pfwrite(putf,bomsz);                                       //~v57jR~
//      totout+=bomsz;
    }//bom write
    for (;;)
    {
	    rc=Pfread(psjis+reslen,Pibuffsz-reslen,&readlen);
        lineendid=0;                                               //~v57hI~
      if (rc==1)                                                   //~v57hI~
            lineendid=UCVUCS_FULLREC;                              //~v57hI~
      else                                                         //~v57hI~
        if (rc)
        	break;
//printf("recoffs =%08x,outtot=%08x\n",offs,totout);
		len=readlen+reslen;
//  	rcs=ucvssjis2utf(Popt,psjis,len,putf,utfbufflen,&chklen,&outlen);//~v57hR~
//  	rcs=ucvssjis2utf(Pferr,Popt|lineendid,psjis,len,putf+bomsz,utfbufflen-bomsz,&chklen,&outlen,&errctr);//~v57jR~//+v6BkR~
    	rcs=ucvssjis2utf(Pferr,Popt|(ULONG)lineendid,psjis,len,putf+bomsz,utfbufflen-bomsz,&chklen,&outlen,&errctr);//+v6BkI~
        totrep+=errctr;                                            //~v57iI~
        rct|=rcs;                                                  //~v57cI~
        reslen=len-chklen;
        if (reslen)
        	memcpy(psjis,psjis+chklen,(UINT)reslen);	//shift residual//~v57jR~
//      totout+=outlen;                                            //~v57iR~
		Pfwrite(putf,outlen+bomsz);                                //~v57jR~
        bomsz=0;		//only 1st record                          //~v57jI~
    }//until eof
    if (reslen)	//last is dbcs 1st byte
    {
		rcs=ucvssjis2utf(Pferr,Popt|UCVUCS_FULLREC,psjis,reslen,putf,utfbufflen,&chklen,&outlen,&errctr);//~v57iR~
		rct|=rcs;                                                  //~v57iI~
        totrep+=errctr;                                            //~v57iR~
		Pfwrite(putf,outlen);
    }
    rct&=~UCVUCS_LENERR;                                           //~v57cI~
    ucverrsjis(Popt,rct,totrep);                                   //~v57iI~
    return rct;                                                    //~v57cR~
}//ucvfsjis2utf
//*************************************************
// file conv utf-8 --> sjis
//ret  :rc
//*************************************************
int ucvfutf2sjis(UCVUCS_FREAD *Pfread,UCVUCS_FWRITE *Pfwrite,UCVUCS_FERR *Pferr,//~v57iR~
			 ULONG Popt,UCHAR *Pibuff,int Pibuffsz,UCHAR *Pobuff,int Pobuffsz)//~v57kR~
{
    int  reslen=0,len,sjisbuffsz,chklen,outlen,rcs=0,rct=0,sw1st=0,bomsz;//~v57cR~
    int  readlen,rc,repctr,totrep=0;                               //~v57kR~
    int lineendid;                                                 //~v57hI~
    UCHAR *putf,*psjis,*putfc;
    ULONG lesw;                                                    //~v57kR~
//***********************************
	putf=Pibuff;
    psjis=Pobuff;
    sjisbuffsz=Pobuffsz;
    for (;;)
    {
	    rc=Pfread(putf+reslen,Pibuffsz-reslen,&readlen);
        lineendid=0;                                               //~v57hI~
      if (rc==1)                                                   //~v57hI~
            lineendid=UCVUCS_FULLREC;                              //~v57hI~
      else                                                         //~v57hI~
        if (rc)
        	break;
        putfc=putf;
    	if (!sw1st)
        {
        	sw1st=1;
        	if (Popt & UCVUCS_BOM)           //chk 0xfeff
            {
				bomsz=ucvbomchk(&lesw,putf,readlen);
                if (bomsz)
                    Popt=lesw;
	            readlen-=bomsz;
    	        putfc=putf+bomsz;
            }
//printf("bomsz=%d,opt=%0x\n",bomsz,Popt);
        }//1st time
//printf("recoffs =%08x,outoffs=%08x\n",offs);
		len=readlen+reslen;                                        //~v57cI~
//  	rcs=ucvsutf2sjis(Popt,putfc,len,psjis,sjisbuffsz,&chklen,&outlen,&repctr);//~v57hR~
//  	rcs=ucvsutf2sjis(Pferr,Popt|lineendid,putfc,len,psjis,sjisbuffsz,&chklen,&outlen,&repctr);//~v57iR~//+v6BkR~
    	rcs=ucvsutf2sjis(Pferr,Popt|(ULONG)lineendid,putfc,len,psjis,sjisbuffsz,&chklen,&outlen,&repctr);//+v6BkI~
        totrep+=repctr;                                            //~v57cR~
        rct|=rcs;
        reslen=len-chklen;                                         //~v57cR~
        if (reslen)                                                //~v57cI~
	        memcpy(putf,putfc+chklen,(UINT)reslen);                //~v57jR~
		Pfwrite(psjis,outlen);
    }//until eof
    if (reslen) //last rc                                          //~v57mR~
    {                                                              //~v57iI~
    	rcs=ucvsutf2sjis(Pferr,Popt|UCVUCS_FULLREC,putf,reslen,psjis,sjisbuffsz,&chklen,&outlen,&repctr);//~v57mI~
        Pfwrite(psjis,outlen);                                     //~v57mI~
        totrep+=repctr;                                            //~v57mI~
        rct|=rcs;                                                  //~v57mI~
    }                                                              //~v57iI~
    ucverrutf(Popt,rct,totrep);                                    //~v57cR~
    return rct;
}//ucvfutf2sjis
//*************************************************
//chk utf bom on top of file
//return: bomsize,0 if no bom
//*************************************************
int ucvbomchk(ULONG *Ppopt,UCHAR *Putf,int Putfbufflen)            //~v57kR~
{
	int bomsz=0;                                                   //~v57mR~
	ULONG opt=0;                                                   //~v57mI~
//****************
    if (Putfbufflen>=4)
    {
        if (*(Putf)  ==0x00 && *(Putf+1)==0x00
        &&  *(Putf+2)==0xfe && *(Putf+3)==0xff)
        {
            opt|=UCVUCS_UCS4;
            bomsz=4;
        }
        else
        if (*(Putf)  ==0xff && *(Putf+1)==0xfe
        &&  *(Putf+2)==0x00 && *(Putf+3)==0x00)
        {
            opt|=UCVUCS_UCS4;
            opt|=UCVUCS_LE;       //little endian
            bomsz=4;
        }
    }
    if (Putfbufflen>=2
    &&  !(opt & UCVUCS_UCS4)) //ucs2
    {
        if (*(Putf)  ==0xfe && *(Putf+1)==0xff)
            bomsz=2;
        else
        if (*(Putf)  ==0xff && *(Putf+1)==0xfe)
        {
            opt|=UCVUCS_LE;       //little endian
            bomsz=2;
        }
    }
	*Ppopt=opt;
    return bomsz;
}//ucvbomchk
//*************************************************
//set utf bom on top of file
//return: bomsize
//*************************************************
int ucvbomset(ULONG Popt,UCHAR *Putf)                              //~v57kR~
{
	int bomsz;
    char *pc;
//****************
    pc=Putf;
    if (Popt & UCVUCS_UCS4)
    {
    	bomsz=4;
        if (Popt & UCVUCS_LE) //output ucs by little endian
            *pc++=0xff,*pc++=0xfe,*pc++=0x00,*pc=0x00;
        else                   //big endian
            *pc++=0x00,*pc++=0x00,*pc++=0xfe,*pc=0xff;
    }
    else
    {
    	bomsz=2;
        if (Popt & UCVUCS_LE) //output ucs by little endian
            *pc++=0xff,*pc++=0xfe;
        else                  //big endian
            *pc++=0xfe,*pc++=0xff;
    }
    return bomsz;
}//ucvbomset
//*************************************************
//set ucs string by endian
//return: string len
//*************************************************
//int ucvsetucss(ULONG Popt,ULONG Pucs,UCHAR *Pucss)                 //~v57kR~//~v691R~
int ucvsetucss(ULONG Popt,UWUCS Pucs,UCHAR *Pucss)                 //~v691I~
{
	int ucssz;
    UCHAR *pc;
//***********************
	pc=Pucss;
  if (Popt & UCVUCS_ESCUCS) //output is \uxxxx unicode fmt         //~v5h6I~
  {                                                                //~v5h6I~
  	if (Pucs>>8)	//not sbcs                                     //~v5h6I~
  		if (Popt & UCVUCS_UCS4) //accept ucs4                      //~v5h6I~
//        	ucssz=sprintf(pc,"\\u%08lx",Pucs);                     //~v5h6I~//~v691R~
//      	ucssz=sprintf(pc,"\\u%08x",Pucs);                      //~v691I~//+v6BkR~
        	ucssz=sprintf(pc,"\\u%08x",(UINT)Pucs);                //+v6BkI~
        else                                                       //~v5h6I~
//        	ucssz=sprintf(pc,"\\u%04lx",Pucs);                     //~v5h6I~//~v691R~
//      	ucssz=sprintf(pc,"\\u%04x",Pucs);                      //~v691I~//+v6BkR~
        	ucssz=sprintf(pc,"\\u%04x",(UINT)Pucs);                //+v6BkI~
    else                                                           //~v5h6I~
    {                                                              //~v5h6I~
    	*pc=(UCHAR)Pucs;                                           //~v5h6I~
        ucssz=1;                                                   //~v5h6I~
    }                                                              //~v5h6I~
  }                                                                //~v5h6I~
  else                                                             //~v5h6I~
  {                                                                //~v5h6I~
    if (Popt & UCVUCS_LE) //output ucs by little endian
        if (Popt & UCVUCS_UCS4) //accept ucs4
        {
            *pc++=(UCHAR)((Pucs & 0x000000ff));
            *pc++=(UCHAR)((Pucs & 0x0000ff00)>>8);
            *pc++=(UCHAR)((Pucs & 0x00ff0000)>>16);
            *pc  =(UCHAR)((Pucs>>24));
            ucssz=4;
        }
        else
        {
            *pc++=(UCHAR)((Pucs & 0x000000ff));
            *pc  =(UCHAR)((Pucs & 0x0000ff00)>>8);
            ucssz=2;
        }
    else    //big endian
        if (Popt & UCVUCS_UCS4) //not accept ucs4
        {
            *pc++=(UCHAR)((Pucs>>24));
            *pc++=(UCHAR)((Pucs & 0x00ff0000)>>16);
            *pc++=(UCHAR)((Pucs & 0x0000ff00)>>8);
            *pc  =(UCHAR)((Pucs & 0x000000ff));
            ucssz=4;
        }
        else
        {
            *pc++=(UCHAR)((Pucs & 0x0000ff00)>>8);
            *pc  =(UCHAR)((Pucs & 0x000000ff));
            ucssz=2;
        }
  }//binary output                                                 //~v5h6I~
	return ucssz;
}//ucvsetucss
//*************************************************
// get ucs code from string
//parm1:opt
//parm2:pointer to ucs
//ret  :ucs code
//*************************************************
ULONG ucvgetucss(ULONG Popt,UCHAR *Pucs)                           //~v57kR~
{
    ULONG ucs;
//******************************
    if (Popt & UCVUCS_LE) //output ucs by little endian
    	if (Popt & UCVUCS_UCS4) //not accept ucs4
            ucs=((ULONG)*Pucs)+((ULONG)*(Pucs+1)<<8)+
			((ULONG)*(Pucs+2)<<16)+((ULONG)*(Pucs+3)<<24);
        else
            ucs=((ULONG)*Pucs)+((ULONG)*(Pucs+1)<<8);
	else					//big endian
    	if (Popt & UCVUCS_UCS4) //not accept ucs4
            ucs=((ULONG)*Pucs<<24)+((ULONG)*(Pucs+1)<<16)+
			((ULONG)*(Pucs+2)<<8)+((ULONG)*(Pucs+3));
        else
            ucs=((ULONG)*Pucs<<8)+((ULONG)*(Pucs+1));
    return ucs;
}//ucvgetucss
//*************************************************
//*************************************************
int ucverrutf(ULONG Popt,int Prc,int Perrctr)                      //~v57kR~
{
    if (Prc & ~UCVUCS_LENERR) //last rc
    	if (!(Popt & UCVUCS_NOERRMSG))
	    	uerrmsg("%d invalid utf-8 code detected.",             //~v57cR~
    		    	"%d 件 utf-8変換エラー検知",                   //~v57cR~
			Perrctr);                                              //~v57cI~
    return 4;
}//ucverrutf                                                       //~v57iR~
//*************************************************
//*************************************************
int ucverrucs(ULONG Popt,int Prc,int Prepctr)                      //~v57kR~
{
    if (Prc & ~UCVUCS_LENERR) //last rc
    	if (!(Popt & UCVUCS_NOERRMSG))
	    	uerrmsg("%d unicode err.",                             //~v57cR~
    		    	"%d 文字 unicodeエラー。",                     //~v57cR~
					Prepctr);                                      //~v57cR~
    return 4;
}//ucverrucs                                                       //~v57iR~
//*************************************************                //~v57iI~
int ucverrsjis(ULONG Popt,int Prc,int Prepctr)                     //~v57kR~
{                                                                  //~v57iI~
    if (Prc & ~UCVUCS_LENERR) //last rc                            //~v57iI~
    	if (!(Popt & UCVUCS_NOERRMSG))                             //~v57iI~
	    	uerrmsg("%d SJIS code err.",                           //~v57iI~
    		    	"%d 文字 SJIS codeエラー。",                   //~v57iI~
					Prepctr);                                      //~v57iI~
    return 4;                                                      //~v57iI~
}//ucverrsjis                                                      //~v57iI~
