//*CID://+v7dJR~:                                   update#=  719; //~v7dJR~
//***********************************************************************//~v69cI~
//v7dJ:241104 dispaly sbcs cvname on hdr line if it is not dbcs cvname//~v7dJI~
//v7dH:241104 (Bug)case no ebc cfg and profile cvname is of previous run;e cpeb=prof cvname, chk of "Not external converter and multiple converter" is not done and 0c4//~v7dHI~
//v7dp:241011 (BUG)0c4 when cv m2b cpeb:37(Windows codepafe); reject cpeb:xx when converter is not external(ICU/iconv)//~v7dpI~
//vbBf:241006 adjust ebc file header line. del "CFG:" when by cmdline /ebc//~vbBfI~
//v7dg:240922 display EBCDIC_STATEFUL for icu converter list       //~v7dgI~
//v7d4:240817 allow matching CP930-Internal and CP930              //~v7d4I~
//v6Bu:160226 support ebc(0x00->oxff)->ucs4  mapping               //~v6BuI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6Bi:160212 (W32)compiler warning                                //~v6BiI~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6x4:150107 gcc warning: array subscript is above array bounds [-Warray-bounds]//~v6x4I~
//v6m7:130809 (BUG)sbcs map tbl err(use cfg codepage mapping(handle=0) at creting new code page(handle!=0) mapping table)//~v6m7I~
//            cp930 lowercase/katakana <-->ascii invalid translation//~v6m7I~
//v6m5:130808 (BUG)when xeebc.map did not define DBCS converter,copy line from EBC filet hader//~v6m5I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6hf:120616 (BUG)found by VC10:/W4 warning except                //~v6hfI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6bk:111213 chk cfg converter is ebcdic(CPEB is alrady chked at setuphandle)//~v6bkI~
//v6bd:111209 change default map to cp37(contains ctl char) from c3270ftp when not xe3270//~v6bdI~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v69v:100905 avoid CP37 duplicated assign cfg and cmd             //~v69vI~
//v69t:100903 add isebccodepage                                    //~v69tI~
//v69c:100809 converter parm support for each b2m/m2b translation  //~v69cI~
//***********************************************************************//~v69cI~
//* ucvebc4.c                                                      //~v69cR~
//* ebc conversion                                                 //~v69cI~
//***********************************************************************//~v69cI~
#if defined(W32) || defined(LNX)                                   //~v69cI~
//***********************************************************************//~v69cI~
#include <stdio.h>                                                 //~v69cI~
#include <string.h>                                                //~v69cI~
#include <stdlib.h>                                                //~v69cI~
#include <stddef.h>                                                //~v69cI~
#ifdef W32                                                         //~v68hI~//~v69cI~
    #include <io.h>     //setmode                                  //~v68hI~//~v69cI~
    #include <fcntl.h>     //setmode                               //~v68hI~//~v69cI~
#endif                                                             //~v68hI~//~v69cI~
                                                                   //~v69cI~
#include <ulib.h>                                                  //~v69cI~
#include <ualloc.h>                                                //~v69cI~
#include <uerr.h>                                                  //~v69cI~
#include <uque.h>                                                  //~v69cI~
#include <udbcschk.h>                                              //~v69cI~
#include <ucvucs.h>                                                //~v5n3I~//~v69cI~
#include <ucvext.h>                                                //~v69cI~
#include <ucvebc.h>                                                //~v69cI~
#include <ucvebc4.h>                                               //~v69cI~
#include <utf22.h>                                                 //~v69cI~
#include <ustring.h>                                               //~v69cI~
#include <uedit.h>                                                 //~v69vI~
#include <utrace.h>                                                //~v69cI~
//*******************************************************          //~v69cI~
//#define UTRACEP printf //@@@@test                                //~v6bdR~
static PUCVEXTCFG Spcfg;                                           //~v69cI~
//*******************************************************          //~v69cI~
//int ucvebc4_srchcveh(int Popt,ULONG Psrchkey,PUCVEBCH *Ppucveh);   //~v69cR~//~v6hhR~
int ucvebc4_srchcveh(int Popt,ULPTR Psrchkey,PUCVEBCH *Ppucveh);   //~v6hhI~
#define UCVEBC4SHO_BYNAME               0x01                       //~v69cR~
#define UCVEBC4SHO_BYHANDLE             0x02                       //~v69cR~
int ucvebc4_setuphandle(int Popt,PUCVEBCH Ppucveh);                //~v69cR~
int ucvebc4_b2mSbcs(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Pinplen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Pbuffsz,int *Ppmblen);//~v69cI~
//int ucvebc4_b2uSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,WUCS *Ppucs);//~v69cI~//~v6BjR~
int ucvebc4_b2uSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UWUCS *Ppucs);//~v6BjI~
int ucvebc4_setletter(int Popt,int Phandle);                       //~v69cI~
int ucvebc4_setupsubch(int Popt,PUCVEBCH Ppucveh);                 //~v69cR~
//int ucvebc4_chkdbcsconverter(int Popt,PUCVEBCH Ppucveh);         //~v6bkR~
//*************************************************************************//~v69cI~
//*init   called from ucvext:mapinit                               //~v69cR~
// handle 0 init                                                   //~v6m5I~
//*************************************************************************//~v69cI~
int ucvebc4_init(int Popt,PUCVEXTCFG Ppcfg)                        //~v69cR~
{                                                                  //~v69cI~
	char *pcvnm;                                                   //~v69cI~
    int handle=0,opt;                                              //~v69cR~
//********************                                             //~v69cI~
    UTRACEP("%s:opt=0x%04x\n",UTT,Popt);                           //~v7d4I~
	Spcfg=Ppcfg;                                                   //~v69cI~
    UTRACED("ucvext2 cfg",Ppcfg,UCVEXTCFGSZ);                      //~v69cI~
    pcvnm=Ppcfg->UCECcsnamedbcs;                                   //~v69cI~
    if (!*pcvnm)                                                    //~v69cI~//~v69tR~
    	pcvnm=Ppcfg->UCECcsnamesbcs;                               //~v69cI~
    opt=UCVEBCCHO_CFG;                                             //~v69cI~
	ucvebc4_createhandle(opt,pcvnm,&handle);	//cfg converte     //~v69cR~
	ucvext_handle0init(0,Ppcfg);                                   //~v69cR~
    UTRACEP("%s:exit\n",UTT);                                      //~v7d4I~
    return 0;                                                      //~v69cI~
}//ucvebc4_init                                                    //~v69cR~
//**************************************************************** //~v69cI~
//*compare converter name                                          //~v69cI~
//**************************************************************** //~v69cI~
int ucvebc4_compbyname(PUQUEE Ppqe,PVOID Pcvname)                  //~v69cR~
{                                                                  //~v69cI~
	PUCVEBCH pucveh;                                               //~v69cR~
    char *pcvname;                                                 //~v69cI~
//**********************************                               //~v69cI~
    pcvname=(char*)Pcvname;                                        //~v69cI~
//  pucveh=(PUCVEBCH)(ULONG)Ppqe;                                  //~v69cR~//~v6hhR~
    pucveh=(PUCVEBCH)(ULPTR)Ppqe;                                  //~v6hhI~
	return strcmp(pcvname,pucveh->UCVEHcvname)!=0;                 //~v69cR~
}//ucvebc4_compbyname                                              //~v69cR~
//**************************************************************** //~v69cI~
//*compare converter name                                          //~v69cI~
//**************************************************************** //~v69cI~
int ucvebc4_compbyhandle(PUQUEE Ppqe,PVOID Phandle)                //~v69cR~
{                                                                  //~v69cI~
	PUCVEBCH pucveh;                                               //~v69cR~
    int      handle;                                               //~v69cI~
//**********************************                               //~v69cI~
//  handle=(int)(ULONG)Phandle;                                           //~v69cI~//~v69vR~//~v6hhR~
    handle=(int)(ULPTR)Phandle;                                    //~v6hhI~
//  pucveh=(PUCVEBCH)(ULONG)Ppqe;                                  //~v69cR~//~v6hhR~
    pucveh=(PUCVEBCH)(ULPTR)Ppqe;                                  //~v6hhI~
	return handle==pucveh->UCVEHhandle;                            //~v69cR~
}//ucvebc4_compbyhandle                                            //~v69cR~
//**************************************************************** //~v69cI~
//*search handle                                                   //~v69cI~
//*rc:0 , rc=1: returned empty entry ,-1 not found or full         //~v69cR~
//**************************************************************** //~v69cI~
//int ucvebc4_srchcveh(int Popt,ULONG Psrchkey,PUCVEBCH *Ppucveh)    //~v69cR~//~v6hhR~
int ucvebc4_srchcveh(int Popt,ULPTR Psrchkey,PUCVEBCH *Ppucveh)    //~v6hhI~
{                                                                  //~v69cI~
    PUCVEBCH pucveh;                                               //~v69cI~
    int rc=-1,ii,handle;                                           //~v69cR~
    char *pkeynm;                                                  //~v69cI~
#ifdef W32                                                         //~v69vI~
    int wincpnum,len;                                              //~v69vR~
#endif                                                             //~v69vI~
//*******                                                          //~v69cI~
	if (Popt & UCVEBC4SHO_BYNAME)                                  //~v69cR~
    {                                                              //~v69cI~
    	pkeynm=(char*)Psrchkey;                                    //~v69cI~
#ifdef W32                                                         //~v69vI~
    	len=(int)strlen(pkeynm);                                   //~v69vR~
    	if (unumlen(pkeynm,0/*opt*/,len)==len)                     //~v69vI~
        	wincpnum=atoi(pkeynm);                                 //~v69vI~
        else                                                       //~v69vI~
        	wincpnum=-1;                                           //~v69vI~
#else                                                              //~v7d4I~
    	int len=(int)strlen(pkeynm);                               //~v7d4I~
#endif                                                             //~v69vI~
    	for (ii=0,pucveh=Gucvebch;ii<UCVEBCH_MAXHANDLE;ii++,pucveh++)//~v69cR~
        {                                                          //~v69cI~
        	if (!*pucveh->UCVEHcvname)//null entry                 //~v69cI~
            {                                                      //~v69cI~
        		pucveh->UCVEHhandle=ii;                            //~v69cI~
            	rc=1;                                              //~v69cI~
            	break;                                             //~v69cI~
            }                                                      //~v69cI~
        	if (!stricmp(pucveh->UCVEHcvname,pkeynm))              //~v69cI~
            {                                                      //~v69cI~
            	rc=0;                                              //~v69cI~
            	break;                                             //~v69cI~
            }                                                      //~v69cI~
        	if (USTRHEADIS_IC_STR(pucveh->UCVEHcvname,pkeynm)      //~v7d4I~
            &&  !strcmp(pucveh->UCVEHcvname+len,TBLMAPPINGID))     //~v7d4I~
            {                                                      //~v7d4I~
            	UTRACEP("%s:internal cpid match %s and %s\n",UTT,pucveh->UCVEHcvname,pkeynm);//~v7d4R~
            	rc=0;                                              //~v7d4I~
            	break;                                             //~v7d4I~
            }                                                      //~v7d4I~
#ifdef W32                                                         //~v69vI~
            if (wincpnum>0 && wincpnum==atoi(pucveh->UCVEHcvname)) //~v69vR~
            {                                                      //~v69vI~
            	rc=0;                                              //~v69vI~
            	break;                                             //~v69vI~
            }                                                      //~v69vI~
#endif                                                             //~v69vI~
        }                                                          //~v69cI~
    }                                                              //~v69cI~
    else                                                           //~v69cI~
    {                                                              //~v69cI~
    	handle=(int)Psrchkey;                                      //~v69cI~
        if (handle>=0 && handle<UCVEBCH_MAXHANDLE)                 //~v69cR~
        {                                                          //~v69cI~
	    	pucveh=Gucvebch+handle;                                //~v69cI~
            rc=0;                                                  //~v69cI~
        }                                                          //~v69cI~
        else	                                                   //~v69cI~
			pucveh=0;                                              //~v69cR~
    }                                                              //~v69cI~
    *Ppucveh=pucveh;                                               //~v69cR~
	return rc;                                                     //~v69cI~
}//ucvebc4_srchcveh                                                //~v69cR~
//**************************************************************** //~v69cI~
//*get handle by converter name                                    //~v69cI~
//*rc:8:reached max,UALLOC_FAILED,1 new added,0:found              //~v69cR~
//**************************************************************** //~v69cI~
int ucvebc4_gethandle(int Popt,char *Pcvname,PUCVEBCH *Ppucveh)    //~v69cR~
{                                                                  //~v69cI~
	PUCVEBCH pucveh;                                               //~v69cR~
    int opt,rc;                                                    //~v69cI~
    char *pcvname;                                                 //~v69cI~
//*******                                                          //~v69cI~
	opt=UCVEBC4SHO_BYNAME;                                         //~v69cR~
//	rc=ucvebc4_srchcveh(opt,(ULONG)Pcvname,&pucveh);               //~v69cR~//~v6hhR~
	rc=ucvebc4_srchcveh(opt,(ULPTR)Pcvname,&pucveh);               //~v6hhI~
    if (rc<0)                                                      //~v69cR~
    {                                                              //~v69cR~
        uerrmsg("Too many different converter(max is %d)",         //~v69cR~
                "コンバーターは %d 個までです。",                  //~v69cR~
                UCVEBCH_MAXHANDLE);                                //~v69cR~
        return 8;                   //overflow                     //~v69cR~
    }                                                              //~v69cR~
    if (rc)	//new entry                                            //~v69cI~
    {                                                              //~v69cI~
    	pcvname=Pcvname;                                           //~v69cI~
    	if (!*pcvname)	//null entry                               //~v69cR~
        {                                                          //~v69cI~
        	if (Popt & UCVEBC4O_CFG)                               //~v69cI~
            	pcvname="CFG";                                     //~v69cI~
            else                                                   //~v69cI~
            	return 8;                                          //~v69cI~
        }                                                          //~v69cI~
        UstrncpyZ(pucveh->UCVEHcvname,pcvname,MAX_CSNAMESZ);       //~v69cR~
    }                                                              //~v69cI~
    *Ppucveh=pucveh;                                               //~v69cR~
    return rc;                                                     //~v69cI~
}//ucvebc4_gethandle                                               //~v69cR~
//**************************************************************** //~v69cI~
//*get handle                                                      //~v69cR~
//**************************************************************** //~v69cI~
PUCVEBCH ucvebc4_getpucveh(int Popt,int Phandle)                   //~v69cR~
{                                                                  //~v69cI~
	PUCVEBCH pucveh;                                               //~v69cR~
    int opt;                                                       //~v69cR~
//*******                                                          //~v69cI~
	opt=UCVEBC4SHO_BYHANDLE;                                       //~v69cR~
	if (!ucvebc4_srchcveh(opt,(ULONG)Phandle,&pucveh))             //~v69cR~
    	if (Popt & UCVEBC4O_EXCEPTCFG)                             //~v69cR~
    		if (pucveh && !pucveh->UCVEHhandle)                    //~v69cR~
        		pucveh=0;                                          //~v69cR~
    return pucveh;                                                 //~v69cR~
}//ucvebc4_getpucveh                                               //~v69cR~
//**************************************************************** //~v69cI~
//*get converter name                                              //~v69cI~
//**************************************************************** //~v69cI~
char *ucvebc4_getcvname(int Popt,int Phandle)                      //~v69cI~
{                                                                  //~v69cI~
	PUCVEBCH pucveh;                                               //~v69cR~
    int opt;                                                       //~v69cI~
    char *pcvname;                                                 //~v69cI~
    static char Scvname[MAX_CSNAMESZ*2];                           //~v7dJR~
//*******                                                          //~v69cI~
	opt=0;                                                         //~v69cI~
	pucveh=ucvebc4_getpucveh(opt,Phandle);                         //~v69cI~
    if (pucveh)                                                    //~v69cI~
    {                                                              //~v7dJI~
    	pcvname=pucveh->UCVEHcvname;                               //~v69cI~
        UTRACEP("%s:cvname2=%s\n",UTT,pucveh->UCVEHcvname2);       //~v7dJI~
    	if (*(pucveh->UCVEHcvname2))                               //~v7dJI~
        {                                                          //~v7dJI~
        	sprintf(Scvname,"%s+%s",pcvname,pucveh->UCVEHcvname2); //~v7dJI~
            pcvname=Scvname;                                       //~v7dJI~
        }                                                          //~v7dJI~
    }                                                              //~v7dJI~
    else                                                           //~v69cI~
    	pcvname="Unknown";                                         //~v69cI~
    UTRACEP("%s:%s\n",UTT,pcvname);                     //~v6bdI~  //~v7d4R~
    return pcvname;                                                //~v69cI~
}//ucvebc4_getcvname                                               //~v69cI~
//**************************************************************** //~v69cI~
//*get converter type                                              //~v69cI~
//**************************************************************** //~v69cI~
int ucvebc4_getcvtype(int Popt,int Phandle)                        //~v69cI~
{                                                                  //~v69cI~
	PUCVEBCH pucveh;                                               //~v69cI~
    int cvtype=0,opt;                                              //~v69cR~
//  ULONG pconverter;                                              //~v6x5R~
    ULPTR pconverter;                                              //~v6x5I~
//*******                                                          //~v69cI~
    UTRACEP("%s:opt=0x%04x,handle=%d\n",UTT,Popt,Phandle);         //~v7d4I~
	opt=0;                                                         //~v69cI~
	pucveh=ucvebc4_getpucveh(opt,Phandle);                         //~v69cI~
    if (Spcfg->UCECflag & UCECF_OPENERR)                           //~vbBfI~
        if (!Phandle)                                              //~vbBfI~
            cvtype|=UCVEBC4CVT_OPENERR;                            //~vbBfI~
    if (UCVEBCH_ISDBCSCV(pucveh))                                  //~v69cR~
    {                                                              //~v69cI~
    	cvtype|=UCVEBC4CVT_DBCSCV;                                 //~v69cI~
        if (!Phandle)                                              //~v69cI~
			pconverter=Spcfg->UCECconverterdbcs;                   //~v69cR~
        else                                                       //~v69cI~
        	pconverter=pucveh->UCVEHpconverters[2];                //~v69cI~
    }                                                              //~v69cI~
    else                                                           //~v69cI~
    {                                                              //~v69cI~
        if (!Phandle)                                              //~v69cI~
			pconverter=Spcfg->UCECconvertersbcs;                   //~v69cR~
        else                                                       //~v69cI~
        	pconverter=pucveh->UCVEHpconverters[1];                //~v69cI~
    }                                                              //~v69cI~
    if (Spcfg->UCECflag & UCECF_USE_CONVERTER)                     //~v69cR~
    {                                                              //~v69cI~
        cvtype|=UCVEBC4CVT_EXT;                                    //~v69cI~
        if (Spcfg->UCECflag & UCECF_USE_ICU)                       //~v69cR~
            cvtype|=UCVEBC4CVT_ICU;                                //~v69cI~
        if (!pconverter)                                           //~v69cI~
            cvtype|=UCVEBC4CVT_OPENERR;                            //~v69cI~
        if (Spcfg->UCECflag & UCECF_SBCSMAP)                       //~v6bdI~
            cvtype|=UCVEBC4CVT_MAP;                                //~v6bdM~
    }                                                              //~v69cI~
    else                                                           //~v69cI~
    if (Phandle)                                                   //~v69cR~
    {                                                              //~v69cI~
        cvtype|=UCVEBC4CVT_EXT;                                    //~v69cI~
        if (!pconverter)                                           //~v69cI~
            cvtype|=UCVEBC4CVT_OPENERR;                            //~v69cI~
    }                                                              //~v69cI~
    UTRACEP("%s:handle=%d,cvtype=%x,UCECflag=0x%08x\n",UTT,Phandle,cvtype,Spcfg->UCECflag);//~v6bdI~//~v6BuR~
    return cvtype;                                                 //~v69cI~
}//ucvebc4_getcvtype                                               //~v69cI~
//**************************************************************** //~v69cI~
//*create handle                                                   //~v69cI~
//*rc:8:reached max,UALLOC_FAILED,4:converter err                  //~v69cI~
//**************************************************************** //~v69cI~
int ucvebc4_createhandle(int Popt,char *Pcvname,int *Pphandle)     //~v69cR~
{                                                                  //~v69cI~
	PUCVEBCH pucveh;                                               //~v69cR~
    int opt,rc,handle;                                             //~v69cI~
//*******                                                          //~v69cI~
	opt=Popt;                                                      //~v69cR~
	rc=ucvebc4_gethandle(opt,Pcvname,&pucveh);                     //~v69cR~
    UTRACEP("%s:Popt=0x%04x,gethandle rc=%d cvname=%s\n",UTT,Popt,rc,Pcvname);//~v6bdI~//~v6BuR~
    if (rc>1)	                                                   //~v69cI~
    	return rc;                                                 //~v69cI~
    *Pphandle=handle=pucveh->UCVEHhandle;                          //~v69cR~
    if (!(Popt & UCVEBC4O_CFG))	//not for cfg parm                 //~v69cI~
    {                                                              //~v6bkI~
//from ucvext_iconva2af(opt=UCVEBCCHO_CHKEBCCP=x02)<-- xcv         //~v7d4I~
//from xefcmd6(profile)                                            //~v7d4I~
//from xefile5(fileoptionchk converter)<--cv cmd                   //~v7d4I~
//      if (rc) //new                                              //~v69cR~//~v7dHR~
//      {                                                          //~v69cR~//~v7dHR~
        	if (handle!=0)                                         //~v7dpI~
            {                                                      //~v7dpI~
				if (!(Spcfg->UCECflag & UCECF_USE_CONVERTER))      //~v7dpI~
                {                                                  //~v7dpI~
  		    		uerrmsgcat(" To use multiple converter, specify ICU or iconv by cfg file.",//~v7dpR~
		    	           " 複数のコンバーターを使用する場合は、cfg ファイルで 外部コンバーター(ICU or iconv)の設定が必要です");//~v7dpI~
                	return 4;                                      //~v7dpR~
                }                                                  //~v7dpI~
            }                                                      //~v7dpI~
        if (rc) //new                                              //~v7dHI~
        {                                                          //~v7dHI~
            opt=Popt;                                              //~v69cR~
    		if (Spcfg->UCECflag & UCECF_USE_ICU)                   //~v69cI~
    			opt|=UCVEBC4O_USEICU;                              //~v69cI~
            rc=ucvebc4_setuphandle(opt,pucveh);                    //~v69cR~
            UTRACEP("%s:ucvebc4_setuphandle rc=%d\n",UTT,rc);      //~vbBfI~
            if (!rc)                                               //~v69cR~
                rc=ucvebc4_setletter(opt,handle);                  //~v69cR~
            if (rc)                                                //~v69cR~
            {                                                      //~v69cR~
                memset(pucveh,0,UCVEBCHSZ); //set empty            //~v69cR~
                if (rc!=UCVEXTRC_ERRMSGISSUED)                     //~v69cR~
	                uerrmsg("converter init for %s failed. ",0,      //~v69cR~//~v6bkR~
    	                        Pcvname);                          //~v69cR~
                return 4;                                          //~v69cR~
            }                                                      //~v69cR~
        }                                                          //~v69cR~
    }                                                              //~v6bkI~
	UTRACED("ucveh",pucveh,UCVEBCHSZ);                             //~v69cR~
    UTRACEP("%s:exit\n",UTT);                                      //~v7d4I~
    return 0;                                                      //~v69cI~
}//ucvebc4_createhandle                                            //~v69cR~
//**************************************************************** //~v69cI~
//*get handle type converte                                        //~v69cI~
//*rc:4:invalid handle                                             //~v69cI~
//**************************************************************** //~v69cI~
//int ucvebc4_getparmconverter(int Popt,int Phandle,ULONG *Pcvdbcs,ULONG *Pcvsbcs,ULONG *Pmapsbcs,ULONG *Pmapsbcsc,int *Ppopt)//~v69cR~//~v6hhR~
int ucvebc4_getparmconverter(int Popt,int Phandle,ULPTR *Pcvdbcs,ULPTR *Pcvsbcs,ULPTR *Pmapsbcs,ULPTR *Pmapsbcsc,int *Ppopt)//~v6hhI~
{                                                                  //~v69cI~
	PUCVEBCH pucveh;                                               //~v69cR~
//	ULONG cvdbcs,cvsbcs,mapsbcs,mapsbcsc;                          //~v69cI~//~v6hhR~
	ULPTR cvdbcs,cvsbcs,mapsbcs,mapsbcsc;                          //~v6hhI~
    int opt;                                                       //~v69cI~
//*******                                                          //~v69cI~
    mapsbcs=mapsbcsc=0;                                            //~v69cI~
	pucveh=ucvebc4_getpucveh(0,Phandle);                           //~v69cR~
    if (!pucveh)                                                   //~v69cI~
    	return 4;                                                  //~v69cI~
    cvdbcs=pucveh->UCVEHpconverter[0];                             //~v69cR~
    cvsbcs=pucveh->UCVEHpconverter[1];                             //~v69cR~
    opt=Popt;                                                      //~v69cI~
	if (Spcfg->UCECflag & UCECF_LOCALCV)                           //~v69cI~
    {                                                              //~v69cI~
		mapsbcs=Spcfg->UCECconverterlocal;                         //~v69cR~
		if (mapsbcs)                                               //~v69cI~
	    	opt|=EBC2ASC_LOCALCV;	//local converter option       //~v69cI~
        UTRACEP("%s:LOCALCV opt=%08x,flag=%08x\n",UTT,opt,Spcfg->UCECflag);//~v7dJR~
	}                                                              //~v69cI~
	if (UCVEBCH_ISDBCSCV(pucveh))                                  //~v6m5I~
    	opt|=EBC2ASC_DBCS;		//dbcs stranslation at ucvext_icuebc2mbs_handle//~v6m5I~
    else                                                           //~v6m5I~
    	opt&=~EBC2ASC_DBCS;		//sbcs only                        //~v6m5I~
    *Pcvdbcs=cvdbcs;                                               //~v69cI~
    *Pcvsbcs=cvsbcs;                                               //~v69cI~
    *Pmapsbcs=mapsbcs;                                             //~v69cI~
    *Pmapsbcsc=mapsbcsc;                                           //~v69cI~
    *Ppopt=opt;                                                    //~v69cI~
UTRACEP("%s:cvdbcs=%x,cvsbcs=%x,mapsbcs=%x,mapsbcsc=%x\n",UTT,cvdbcs,cvsbcs,mapsbcs,mapsbcsc);//~v69cR~//~v7d4R~
    return 0;                                                      //~v69cI~
}//ucvebc4_getparmconverter                                        //~v69cR~
#ifdef AAA	//no caller                                            //~v6x5I~
//**************************************************************** //~v69tI~
//*check ebcdic converter translatiog 0x40                         //~v69tI~
//**************************************************************** //~v69tI~
//int ucvebc4_isebccodepage(int Popt,ULONG Pconverter)             //~v6x5R~
int ucvebc4_isebccodepage(int Popt,ULPTR Pconverter)               //~v6x5I~
{                                                                  //~v69tI~
    UCHAR  ebcspace=CHAR_EBC_SPACE;                                //~v69tI~
//  WUCS  wucs;                                                    //~v69tI~//~v6BjR~
    UWUCS  wucs;                                                   //~v6BjI~
    int opt,rc;                                                    //~v69tI~
//*******                                                          //~v69tI~
	opt=0;                                                         //~v69tI~
	rc=ucvext_icuebc2ucs1(opt,Pconverter,&ebcspace,1,&wucs);       //~v69tI~
    if (rc || wucs!=' ')                                           //~v69tI~
    	rc=0;                                                      //~v69tI~
    else                                                           //~v69tI~
    	rc=1;                                                      //~v69tI~
    return rc;                                                     //~v69tI~
}//ucvebc4_isebccodepage                                           //~v69tI~
#endif                                                             //~v6x5I~
//**************************************************************** //~v69cI~
//*check dbcs support by translatiog 0x0e40400f                    //~v69cI~
//*rc:1:dbcs converter,0:sbcs converter;20:not ebcdic converter    //~v69cR~
//**************************************************************** //~v69cI~
//int ucvebc4_chkdbcsconverter(int Popt,PUCVEBCH Ppucveh)            //~v69cR~//~v6bkR~
//int ucvebc4_chkdbcsconverter(int Popt,ULONG Pconverter,char *Pcvname)//~v6x5R~
int ucvebc4_chkdbcsconverter(int Popt,ULPTR Pconverter,char *Pcvname)//~v6x5I~
{                                                                  //~v69cI~
	USHORT ebcdbcsspace=CHAR_EBC_DBCS_SPACE;                       //~v69cR~
    UCHAR  ebcspace=CHAR_EBC_SPACE,*picumsg;                       //~v69cR~
//  ULONG pconverter;                                              //~v6x5R~
    ULPTR pconverter;                                              //~v6x5I~
//  WUCS  wucs;                                                    //~v69cI~//~v6BjR~
    UWUCS  wucs;                                                   //~v6BjI~
    int opt,rc;                                                    //~v69cI~
//*******                                                          //~v69cI~
//  pconverter=(ULONG)(Ppucveh->UCVEHpconverter[1]);//sbcs converter//~v69cR~//~v6bkR~
    pconverter=Pconverter;                                         //~v6bkI~
	opt=0;                                                         //~v69cI~
	rc=ucvext_icuebc2ucs1(opt,pconverter,&ebcspace,1,&wucs);       //~v69cR~
    if (rc || wucs!=' ')                                           //~v69cI~
    {                                                              //~v69cI~
      if (!(Popt & UCVEBC4O_NOMSG))                                //~v7dgI~
      {                                                            //~v7dgI~
		if (Popt & UCVEBC4O_USEICU)                                //~v69cI~
        	picumsg="ICU";                                         //~v69cR~
        else                                                       //~v69cI~
        	picumsg="nonICU";                                      //~v69cR~
    	uerrmsg("%s is not EBCDIC converter(%s mode)",0,           //~v69cR~
//      		Ppucveh->UCVEHcvname,picumsg);                     //~v69cR~//~v6bkR~
        		Pcvname,picumsg);                                  //~v6bkI~
      }                                                            //~v7dgI~
        return UCVEXTRC_ERRMSGISSUED;                              //~v69cR~
    }                                                              //~v69cI~
	opt=EBC2ASC_STAT_SO;      //dbcs conv                          //~v69cI~
//	rc=ucvext_icuebc2ucs1(opt,pconverter,(UCHAR*)(ULONG)(&ebcdbcsspace),sizeof(ebcdbcsspace),&wucs);//~v69cR~//~v6hhR~
	rc=ucvext_icuebc2ucs1(opt,pconverter,(UCHAR*)(ULPTR)(&ebcdbcsspace),sizeof(ebcdbcsspace),&wucs);//~v6hhI~
    if (!rc)                                                       //~v69cI~
    	rc=1;	//dbcs support                                     //~v69cI~
    else                                                           //~v69cI~
    	rc=0;                                                      //~v69cI~
    UTRACEP("%s:rc=%d,cvname=%s\n",UTT,rc,Pcvname);                //+v7dJI~
    return rc;                                                     //~v69cI~
}//ucvebc4_chkdbcsconverter                                        //~v69cR~
//**************************************************************** //~v69cM~
//*create handle                                                   //~v69cM~
//*rc:8:reached max,UALLOC_FAILED,4:converter err                  //~v69cM~
//**************************************************************** //~v69cM~
int ucvebc4_setuphandle(int Popt,PUCVEBCH Ppucveh)                 //~v69cR~
{                                                                  //~v69cM~
    int opt,rc;                                                    //~v69cR~
//  ULONG addr;                                                    //~v69cM~//~v6hhR~
    ULPTR addr;                                                    //~v6hhI~
//*******                                                          //~v69cM~
	UTRACEP("%s:opt=0x%04x\n",UTT,Popt);                           //~v7d4I~
	opt=0;                                                         //~v69cR~
//  addr=(ULONG)(Ppucveh->UCVEHhiconv);                            //~v69cR~//~v6hhR~
    addr=(ULPTR)(Ppucveh->UCVEHhiconv);                            //~v6hhI~
	rc=ucvext_icugetconverter(opt,Ppucveh->UCVEHcvname,&addr);     //~v69cR~
    if (rc)                                                        //~v69cM~
        return rc;                                                 //~v69cM~
    Ppucveh->UCVEHpconverters=Ppucveh->UCVEHpconverter;            //~v69cM~
    Ppucveh->UCVEHpconverter[1]=addr;                              //~v69cI~
//  rc=ucvebc4_chkdbcsconverter(Popt,Ppucveh);                     //~v69cR~//~v6bkR~
//  rc=ucvebc4_chkdbcsconverter(Popt,(ULONG)(Ppucveh->UCVEHpconverter[1]),Ppucveh->UCVEHcvname);//~v6x5R~
    rc=ucvebc4_chkdbcsconverter(Popt,Ppucveh->UCVEHpconverter[1],Ppucveh->UCVEHcvname);//~v6x5I~
    if (rc>1)                                                      //~v69cI~
        return rc;                                                 //~v69cI~
    if (rc)	//=1:dbcs                                              //~v69cI~
    {                                                              //~v69cI~
    	Ppucveh->UCVEHpconverter[0]=addr;                          //~v69cI~
    	Ppucveh->UCVEHflag|=UCVEHF_DBCSCV;                         //~v69cR~
    	if (UCVEBCH_ISDBCSCV(Ppucveh))                             //~v69cI~
    		Popt|=UCVEBC4O_DBCSCV;                                 //~v69cI~
	}                                                              //~v69cI~
    ucvebc4_setupsubch(Popt,Ppucveh);                              //~v69cR~
    return 0;                                                      //~v69cM~
}//ucvebc4_setuphandle                                             //~v69cM~
//*************************************************************************//~v69cI~
//*get ebc letter for lowercase letter which varies according to codepage//~v69cI~
//*************************************************************************//~v69cI~
int ucvebc4_setletter(int Popt,int Phandle)                        //~v69cR~
{                                                                  //~v69cI~
    int ii,opt,ebc;                                                //~v69cI~
    int len,optb2m;                                                //~v69cI~
    int opt3;                                                      //~v69cI~
    UCHAR ebclower[26],ebcl;                                       //~v69cI~
    UCHAR ebcupper[26],ebcu;                                       //~v69cI~
//  UCHAR wkch[4];                                                 //~v6x4R~
//  UCHAR wkdbcs[4];                                               //~v6x4R~
    UCHAR wkch[8];                                                 //~v6x4I~
    UCHAR wkdbcs[8];                                               //~v6x4I~
//  WUCS ucs=0;                                                      //~v69cI~//~v6h7R~//~v6BuR~
    UWUCS ucs=0;                                                   //~v6BuI~
//  UCHAR *pce2a,*pca2e,mb;                                        //~v69cR~
//  ULONG plocalconverter;                                         //~v69cI~//~v6b9R~
    int rc2,swoverride,swdup,jj;                                   //~v69cI~
    int mb2;                                                       //~v69cI~
	UCHAR *pu2bmap;                                                //~v69cI~
//  WUCS  *pb2umap;                                                //~v69cI~//~v6BuR~
    UWUCS *pb2umap;                                                //~v6BuI~
	UCHAR *pu2bffmap;                                              //~v69cI~
//	WUCS  *pu2bnonasciimapucs;                                     //~v69cI~//~v6BuR~
  	UWUCS *pu2bnonasciimapucs;                                     //~v6BuI~
	UCHAR *pu2bnonasciimapebc;                                     //~v69cI~
	int   u2bnonasciictr=0;                                        //~v69cI~
	UCHAR *ptoupper;                                               //~v69cI~
	UCHAR *ptolower;                                               //~v69cI~
	UCHAR *pa2bmap;    //ascii->ebc map for sbcs                   //~v69cI~
   	ULONG *pb2amap;   //ascii->ebc map for sbcs,2 byte for euchankana//~v69cI~
   	UCHAR *pctype;   //ascii->ebc map for sbcs,2 byte for euchankana//~v69cI~
    PUCVEBCH pucveh;                                               //~v69cR~
    UWUCS ucs4;                                                    //~v6BjI~
//***************************                                      //~v69cI~
UTRACEP("%s:opt=0x%04x,handle=%d\n",UTT,Popt,Phandle);             //~v7d4I~
	pucveh=UCVEBC_GETPUCVEH(Phandle);                              //~v69cR~
UTRACED("ucvebc4_setletter",pucveh,UCVEBCHSZ);                     //~v69cI~
	pu2bmap=pucveh->UCVEHu2bmap;                                   //~v69cI~
	pb2umap=pucveh->UCVEHb2umap;                                   //~v69cI~
	pu2bffmap=pucveh->UCVEHu2bffmap;                               //~v69cI~
	pu2bnonasciimapucs=pucveh->UCVEHu2bnonasciimapucs;             //~v69cI~
	pu2bnonasciimapebc=pucveh->UCVEHu2bnonasciimapebc;             //~v69cI~
	ptoupper=pucveh->UCVEHtoupper;                                 //~v69cI~
	ptolower=pucveh->UCVEHtolower;                                 //~v69cI~
	pa2bmap=pucveh->UCVEHa2bmap;    //ascii->ebc map for sbcs      //~v69cI~
   	pb2amap=pucveh->UCVEHb2amap;   //ascii->ebc map for sbcs,2 byte for euchankana//~v69cI~
    pctype=pucveh->UCVEHctype;                                     //~v69cI~
                                                                   //~v69cI~
//  plocalconverter=Spcfg->UCECconverterlocal;                     //~v69cI~//~v6b9R~
	for (ii=0;ii<26;ii++)                                          //~v69cI~
    {                                                              //~v69cI~
//  	ebcl=ucvebc3_m2b1Sbcs1(0,ii+'a');                          //~v69cR~
//  	ebcl=ucvebc3_m2b1Sbcs1(0,Phandle,ii+'a');                  //~v69cR~//~v6BiR~
    	ebcl=(UCHAR)ucvebc3_m2b1Sbcs1(0,Phandle,ii+'a');           //~v6BiI~
        ebclower[ii]=ebcl;                                         //~v69cI~
//      Gucvebc_ctype[ebcl]|=EBCTYPE_LOWER;                        //~v69cR~
        pctype[ebcl]|=EBCTYPE_LOWER;                               //~v69cR~
//  	ebcu=ucvebc3_m2b1Sbcs1(0,ii+'A');                          //~v69cR~
//  	ebcu=ucvebc3_m2b1Sbcs1(0,Phandle,ii+'A');                  //~v69cI~//~v6BiR~
    	ebcu=(UCHAR)ucvebc3_m2b1Sbcs1(0,Phandle,ii+'A');           //~v6BiI~
        ebcupper[ii]=ebcu;                                         //~v69cI~
//      Gucvebc_ctype[ebcu]|=EBCTYPE_UPPER;                        //~v69cR~
        pctype[ebcu]|=EBCTYPE_UPPER;                               //~v69cR~
    }                                                              //~v69cI~
//  opt=EBC2ASC_CTL|Sebcopta2e;	//additional parm                  //~v69cR~
    opt=EBC2ASC_CTL;	//additional parm                          //~v69cI~
    optb2m=UCVEBC3O_CVCTL;                                         //~v69cI~
    opt3=UCVEBC3O_CVCTL|UCVEBC3O_SBCS;	//additional parm          //~v69cI~
//  if (Spcfg->UCECflag & UCECF_E2A)     //a2a mapping specified   //~v69cR~
//      pce2a=Spcfg->UCECsbcsmape2a;                               //~v69cR~
//  else                                                           //~v69cR~
//  	pce2a=0;                                                   //~v69cR~
//  if (Spcfg->UCECflag & UCECF_A2E)     //a2a mapping specified   //~v69cR~
//      pca2e=Spcfg->UCECsbcsmapa2e;                               //~v69cR~
//  else                                                           //~v69cR~
//  	pca2e=0;                                                   //~v69cR~
//  plocalconverter=Spcfg->UCECconverterlocal;                     //~v69cR~
	for (ii=0;ii<256;ii++) //all ascii                             //~v69cI~
    {                                                              //~v69cI~
//  	if (pca2e && (ebc=pca2e[ii],ebc))                          //~v69cR~
//      	Gucvebc_a2bmap[ii]=ebc;                                //~v69cR~
//      else                                                       //~v69cR~
        {                                                          //~v69cI~
          if (ii==CHAR_SO||ii==CHAR_SI)                            //~v69cI~
//      	Gucvebc_a2bmap[ii]=ii;                                 //~v69cR~
//      	pa2bmap[ii]=ii;                                        //~v69cI~//~v6BiR~
        	pa2bmap[ii]=(UCHAR)ii;                                 //~v6BiI~
          else                                                     //~v69cI~
          {                                                        //~v69cI~
//			ebc=ucvebc3_m2b1Sbcs1(opt,ii);                         //~v69cR~
  			ebc=ucvebc3_m2b1Sbcs1(opt,Phandle,ii);                 //~v69cI~
   		if (ebc>=0)                                                //~v69cI~
//      	Gucvebc_a2bmap[ii]=ebc;                                //~v69cR~
//      	pa2bmap[ii]=ebc;                                       //~v69cI~//~v6BiR~
        	pa2bmap[ii]=(UCHAR)ebc;                                //~v6BiI~
          }                                                        //~v69cI~
        }                                                          //~v69cI~
        UTRACEP("%s:setletter a2b mb=%x--->ebc=%x\n",UTT,ii,pa2bmap[ii]); //~v69cR~//~v7d4R~
        wkch[0]=(UCHAR)ii;                                         //~v69cI~
//  	if (pce2a && (wkch[1]=pce2a[ii],wkch[1]))                  //~v69cR~
//      {                                                          //~v69cR~
//      	rc2=0;                                                 //~v69cR~
//          len=1;                                                 //~v69cR~
//      }                                                          //~v69cR~
//      else                                                       //~v69cR~
//			rc2=ucvebc3_b2mSbcs(optb2m,wkch,wkdbcs,1,wkch+1,wkdbcs,sizeof(wkch)-1,&len);//for the case roundtrip(0x15->0x0a may prohibit by cfg option//~v69cR~
  			rc2=ucvebc4_b2mSbcs(optb2m,Phandle,wkch,wkdbcs,1,wkch+1,wkdbcs,sizeof(wkch)-1,&len);//for the case roundtrip(0x15->0x0a may prohibit by cfg option//~v69cR~
        if (!rc2)                                                  //~v69cI~
        {                                                          //~v69cI~
          if (len>1)    //sbcs->dbcs by EUC hankana                //~v69cI~
          {                                                        //~v69cI~
           if (len==4)                                             //~v69cI~
           {                                                       //~v69cI~
//          Gucvebc_ctype[ii]|=EBCTYPE_GB4|EBCTYPE_DBCS;           //~v69cR~
            pctype[ii]|=EBCTYPE_GB4|EBCTYPE_DBCS;                  //~v69cI~
            mb2=UBESTR2UL(wkch+1);                                 //~v69cI~
           }                                                       //~v69cI~
           else                                                    //~v69cI~
           if (len==3)                                             //~v69cI~
           {                                                       //~v69cI~
//          Gucvebc_ctype[ii]|=EBCTYPE_SS3|EBCTYPE_DBCS;           //~v69cR~
            pctype[ii]|=EBCTYPE_SS3|EBCTYPE_DBCS;                  //~v69cI~
            mb2=UBESTR2UL3(wkch+1);                                //~v69cI~
           }                                                       //~v69cI~
           else                                                    //~v69cI~
           {                                                       //~v69cI~
            mb2=UBESTR2US(wkch+1);                                 //~v69cI~
//          Gucvebc_ctype[ii]|=EBCTYPE_DBCS;                       //~v69cR~
            pctype[ii]|=EBCTYPE_DBCS;                              //~v69cI~
           }                                                       //~v69cI~
//      	Gucvebc_b2amap[ii]=mb2;                                //~v69cR~
//      	pb2amap[ii]=mb2;                                       //~v69cI~//~v6BkR~
        	pb2amap[ii]=(ULONG)mb2;                                //~v6BkI~
          }                                                        //~v69cI~
          else                                                     //~v69cI~
//      	Gucvebc_b2amap[ii]=wkch[1];                            //~v69cR~
        	pb2amap[ii]=wkch[1];                                   //~v69cI~
        }                                                          //~v69cI~
        else                                                       //~v69cI~
        {                                                          //~v69cI~
            if (ii==CHAR_SO||ii==CHAR_SI)                          //~v69cI~
//      		Gucvebc_b2amap[ii]=ii;                             //~v69cR~
//      		pb2amap[ii]=ii;                                    //~v69cI~//~v6BkR~
        		pb2amap[ii]=(ULONG)ii;                             //~v6BkI~
        }                                                          //~v69cI~
        UTRACEP("%s:b2a mb=%08x<--ebc=%02x\n",UTT,pb2amap[ii],ii);//~v69cR~//~v7d4R~
        wkch[0]=(UCHAR)ii;                                         //~v69cI~
		rc2=1;                                                     //~v69cI~
        swoverride=0;                                              //~v69cI~
//  	if (plocalconverter && pce2a && (mb=pce2a[ii],mb))   //accept ascii(ucs==ascii) only//~v69cR~
//          rc2=ucvext_iconvlocal2ucs1(opt,plocalconverter,&mb,1,0/*chklen*/,&ucs);//~v69cR~
        if (rc2)                                                   //~v69cI~
        {                                                          //~v6BjI~
//  		rc2=ucvebc3_b2uSbcs1(opt3,wkch,0/*repch*/,&ucs);       //~v69cR~
//  		rc2=ucvebc4_b2uSbcs1(opt3,Phandle,wkch,0/*repch*/,&ucs);//~v69cR~//~v6BjR~
    		rc2=ucvebc4_b2uSbcs1(opt3,Phandle,wkch,0/*repch*/,&ucs4);//~v6BjI~
//          ucs=(WUCS)ucs4;                                        //~v6BjI~//~v6BuR~
            ucs=ucs4;                                              //~v6BuI~
        }                                                          //~v6BjI~
        else                                                       //~v69cI~
        	swoverride=1;	//ucs by local2ucs                     //~v69cI~
    	if (!rc2)                                                  //~v69cI~
        {                                                          //~v69cI~
//          Sb2umap[ii]=ucs;				//b2u mapping          //~v69cR~
            pb2umap[ii]=ucs;				//b2u mapping          //~v69cI~
            if (ucs<0x100)                                         //~v69cI~
            {                                                      //~v69cI~
//            if (swoverride||!Su2bmap[ucs])	//dup is err if not by cfg parm//~v69cR~
              if (swoverride||!pu2bmap[ucs])	//dup is err if not by cfg parm//~v69cI~
//              Su2bmap[ucs]=ii;				//reverse          //~v69cR~
//              pu2bmap[ucs]=ii;				//reverse          //~v69cI~//~v6BiR~
                pu2bmap[ucs]=(UCHAR)ii;				//reverse      //~v6BiI~
            }                                                      //~v69cI~
            else                                                   //~v69cI~
            if ((ucs>>8)==0xff)     //0xffxx	//japanese hankaku katakana//~v69cI~
            {                                                      //~v69cI~
//            if (swoverride||!Su2bffmap[ucs & 0xff])	//dup is err if not by cfg parm//~v69cR~
              if (swoverride||!pu2bffmap[ucs & 0xff])	//dup is err if not by cfg parm//~v69cI~
//              Su2bffmap[ucs & 0xff]=ii;		//reverse          //~v69cR~
//              pu2bffmap[ucs & 0xff]=ii;		//reverse          //~v69cI~//~v6BiR~
                pu2bffmap[ucs & 0xff]=(UCHAR)ii;		//reverse  //~v6BiI~
            }                                                      //~v69cI~
            else                                                   //~v69cI~
            {                                                      //~v69cI~
            	swdup=0;                                           //~v69cI~
//            	for (jj=0;jj<Su2bnonasciictr;jj++)                 //~v69cR~
              	for (jj=0;jj<u2bnonasciictr;jj++)                  //~v69cI~
                {                                                  //~v69cI~
//              	if (ucs==Su2bnonasciimapucs[jj])	//duplicated ebc to ucs//~v69cR~
                	if (ucs==pu2bnonasciimapucs[jj])	//duplicated ebc to ucs//~v69cR~
                    {                                              //~v69cI~
                    	swdup=1;                                   //~v69cI~
                    	if (swoverride)                            //~v69cI~
//  			            Su2bnonasciimapebc[jj]=ii;		//ebc  //~v69cR~
//  			            pu2bnonasciimapebc[jj]=ii;		//ebc  //~v69cI~//~v6BiR~
    			            pu2bnonasciimapebc[jj]=(UCHAR)ii;		//ebc//~v6BiI~
                    	break;                                     //~v69cI~
                    }                                              //~v69cI~
                }                                                  //~v69cI~
              if (!swdup)                                          //~v69cI~
              {                                                    //~v69cI~
//              Su2bnonasciimapebc[Su2bnonasciictr]=ii;		//ebc  //~v69cR~
//              pu2bnonasciimapebc[u2bnonasciictr]=ii;		//ebc  //~v69cR~//~v6BiR~
                pu2bnonasciimapebc[u2bnonasciictr]=(UCHAR)ii;		//ebc//~v6BiI~
//              Su2bnonasciimapucs[Su2bnonasciictr++]=ucs;		//reverse//~v69cR~
                pu2bnonasciimapucs[u2bnonasciictr++]=ucs;		//reverse//~v69cR~
              }                                                    //~v69cI~
            }                                                      //~v69cI~
        }                                                          //~v69cI~
        else                                                       //~v69cI~
        {                                                          //~v69cI~
            if (ii==CHAR_SO||ii==CHAR_SI)                          //~v69cI~
            {                                                      //~v69cI~
//              Sb2umap[ii]=ii;				//b2u mapping          //~v69cR~
//              pb2umap[ii]=ii;				//b2u mapping          //~v69cI~//~v6BiR~
//              pb2umap[ii]=(WUCS)ii;				//b2u mapping  //~v6BiI~//~v6BuR~
                pb2umap[ii]=(UWUCS)ii;				//b2u mapping  //~v6BuI~
//              Su2bmap[ii]=ii;				//u2b mapping          //~v69cR~
//              pu2bmap[ii]=ii;				//u2b mapping          //~v69cI~//~v6BiR~
                pu2bmap[ii]=(UCHAR)ii;				//u2b mapping  //~v6BiI~
            }                                                      //~v69cI~
        }                                                          //~v69cI~
        UTRACEP("%s:b2u ucs=%x,ebc=%x\n",UTT,pb2umap[ii],ii);   //~v69cR~//~v7d4R~
//  	Gucvebc_toupper[ii]=ii;                                    //~v69cR~
//  	ptoupper[ii]=ii;                                           //~v69cR~//~v6BiR~
    	ptoupper[ii]=(UCHAR)ii;                                    //~v6BiI~
//  	Gucvebc_tolower[ii]=ii;                                    //~v69cR~
//  	ptolower[ii]=ii;                                           //~v69cR~//~v6BiR~
    	ptolower[ii]=(UCHAR)ii;                                    //~v6BiI~
    }                                                              //~v69cI~
	for (ii=0;ii<26;ii++)                                          //~v69cI~
    {                                                              //~v69cI~
		ebcl=ebclower[ii];                                         //~v69cI~
		ebcu=ebcupper[ii];                                         //~v69cI~
//      Gucvebc_toupper[ebcl]=ebcu;                                //~v69cR~
        ptoupper[ebcl]=ebcu;                                       //~v69cR~
//      Gucvebc_tolower[ebcu]=ebcl;                                //~v69cR~
        ptolower[ebcu]=ebcl;                                       //~v69cR~
    }                                                              //~v69cI~
    pucveh->UCVEHu2bnonasciictr=u2bnonasciictr;                    //~v69cR~
    UTRACED("toupper",ptoupper,256);                               //~v69cR~
    UTRACED("tolower",ptolower,256);                               //~v69cR~
    UTRACED("ctype",pctype,256);                                   //~v69cR~
    UTRACED("a2b  ",pa2bmap,256);                                  //~v69cR~
    UTRACED("b2a  ",pb2amap,sizeof(pucveh->UCVEHb2amap));          //~v69cR~
	UTRACED("u2b",pu2bmap,sizeof(pucveh->UCVEHu2bmap));            //~v69cR~
	UTRACED("b2u",pb2umap,sizeof(pucveh->UCVEHb2umap));            //~v69cR~
	UTRACED("u2bff",pu2bffmap,sizeof(pucveh->UCVEHu2bffmap));      //~v69cR~
	UTRACED("u2bnonasciiucs",pu2bnonasciimapucs,u2bnonasciictr*(int)UWUCSSZ);//~v69cR~//~v6BkR~//~v6BuR~
	UTRACED("u2bnonasciiebc",pu2bnonasciimapebc,u2bnonasciictr);   //~v69cR~
//  Gucvebc_stat|=UCVEBCS_SBCSMAPINIT;//sbcsmap was initialized    //~v69cR~
    pucveh->UCVEHflag|=UCVEHF_SBCSMAPINIT;//sbcsmap was initialized//~v69cR~
UTRACED("ucvebc4_setletter end",pucveh,UCVEBCHSZ);                 //~v69cI~
UTRACEP("%s:exit\n",UTT,Popt);                                     //~v7d4I~
    return 0;                                                      //~v69cI~
}//ucvebc3_setletter                                               //~v69cI~
//*************************************************************************
//*ebc->ucs1(SBCS) by handle                                       //~v69cR~
//* 1 ebc to ucs
//*rc:1:errrep,8 invalid handle                                    //~v69cR~
//*************************************************************************
//int ucvebc4_b2uSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,WUCS *Ppucs)//~v69cR~//~v6BjR~
int ucvebc4_b2uSbcs1(int Popt,int Phandle,UCHAR *Ppebc,int Prepch,UWUCS *Ppucs)//~v6BjI~
{
    int rc=0,rc2,opt;                                              //~0428R~
//  WUCS   usucs;                                                  //~v66CI~//~v6BjR~
    UWUCS  usucs;                                                  //~v6BjI~
//  WUCS wucs;                                                     //~v6BjR~
    UWUCS wucs;                                                    //~v6BjI~
//  UCHAR /*ch,*pmap,*pmapc,*/chebc;                               //~v69cR~//~v6b9R~
//  ULONG pconverter;                                              //~v6x5R~
    ULPTR pconverter;                                              //~v6x5I~
    PUCVEBCH pucveh;                                               //~v69cR~
//***************************
	opt=UCVEBC4O_EXCEPTCFG;                                        //~v69cR~
	pucveh=UCVEBC_GETPUCVEH(Phandle);                              //~v69cI~
    if (!pucveh)                                                   //~v69cI~
    	return 8;                                                  //~v69cI~
//  chebc=*Ppebc;                                                  //~v6b9R~
//  opt=Sebcopte2a;                                                //~0428I~//~v69cR~
    opt=0;                                                         //~v69cI~
    opt|=EBC2ASC_EXT_SETSUBCHRC;                                   //~v66NR~
    if (Popt & UCVEBC3O_CVCTL)                                     //~0428I~
        opt|=EBC2ASC_CTL;	                                       //~0428I~
//  if (!(Sebcopte2a & EBC2ASC_EXT))//if not Japanese,EXT on and use cp037 map//~v69cR~
//  {                                                              //~v69cR~
//  	rc=ucvebc2ucs1sbcsJ(opt,Ppebc,Prepch,&wucs);               //~0428R~//~v69cR~
//  }                                                              //~v69cR~
//  else                                                           //~v69cR~
//  {                                                              //~v69cR~
//    if (Gucvebc_stat & UCVEBCS_SBCSMAPINIT)//sbcsmap was initialized//~v66qI~//~v69cR~
//    {                                                            //~v66qI~//~v69cR~
//  	if (chebc<CHAR_EBC_SPACE     //ctl char                    //~v66qI~//~v69cR~
//  	&&  !(opt & EBC2ASC_CTL)                                   //~v66qI~//~v69cR~
//      )                                                          //~v66qI~//~v69cR~
//          wucs=0;	//errrep later                                 //~v66qI~//~v69cR~
//      else                                                       //~v66qI~//~v69cR~
//    		wucs=Sb2umap[(int)chebc];                              //~v66qR~//~v69cR~
//      if (!wucs && chebc)                                        //~v66qR~//~v69cR~
//      {	                                                       //~v66qI~//~v69cR~
//      	wucs=Prepch;                                           //~v66qI~//~v69cR~
//          rc|=1;                                                 //~v66qI~//~v69cR~
//      }                                                          //~v66qI~//~v69cR~
//  	UTRACEP("ucvext4 b2uSbcs aftermapinit opt=%x,ebc=%x,ucs=%x,rc=%d\n",Popt,chebc,wucs,rc);//~v66qR~//~v69cR~
//    }                                                            //~v66qI~//~v69cR~
//    else                                                         //~v66qI~//~v69cR~
//    {                                                            //~v66qI~//~v69cR~
//      pconverter=Spcve2a[CONVERTER_SBCS];                        //~v69cR~
//      pconverter=(ULONG)(pucveh->UCVEHpconverter[1]); //sbcs convereter//~v6x5R~
        pconverter=pucveh->UCVEHpconverter[1]; //sbcs convereter   //~v6x5I~
//      pmap=(UCHAR*)Spcve2a[CONVERTER_SBCSMAP];                   //~v69cR~
//      pmapc=(UCHAR*)Spcve2a[CONVERTER_SBCSMAPC];                 //~v69cR~
        UTRACEP("%s:opt=%x ebc1=%02x\n",UTT,Popt,*Ppebc);    //~v6hhR~//~v7d4R~
//      if ( (Sebcopte2a & EBC2ASC_SBCSMAPC)    //special code point//~v69cR~
//      &&   (ch=pmapc[chebc]))  //source is sbcs                  //~v69cR~
//      {                                                          //~v69cR~
//          wucs=ch;                                               //~v69cR~
//  UTRACEP("b2usbcs SBCSMAPC %02x->%02x\n",chebc,wucs);           //~v69cR~
//      }                                                          //~v69cR~
//      else                                                       //~v69cR~
//      if ( (Sebcopte2a & EBC2ASC_SBCSMAP) //special code point   //~v69cR~
//      )                                                          //~v69cR~
//      {                                                          //~v69cR~
//  		if (chebc<CHAR_EBC_SPACE     //ctl char                //~v69cR~
//  		&&  !(opt & EBC2ASC_CTL)                               //~0428R~//~v69cR~
//          )                                                      //~v69cR~
//          	wucs=0;	//errrep later                             //~v69cR~
//          else                                                   //~v69cR~
//          	wucs=pmap[chebc];                                  //~v69cR~
//  UTRACEP("b2usbcs by SBCSMAP %02x->%02x\n",chebc,wucs);         //~v69cR~
//          if (!wucs && chebc)                                    //~v66mI~//~v69cR~
//          	wucs=chebc;	//keep org value                       //~v66mI~//~v69cR~
//      }                                                          //~v69cR~
//      else                                                       //~v69cR~
//      {                                                          //~v69cR~
            rc2=ucvext_icuebc2ucs1(opt,pconverter,Ppebc,1,&usucs); //~0428R~
//setsubch is replaced by parameter repch                          //~v66DI~
            if (rc2)
            {
//              wucs=Prepch;                                       //~v6BjR~
                wucs=(UWUCS)Prepch;                                //~v6BjR~
                rc|=1;
            }
            else
            {                                                      //~v66sI~
                wucs=usucs;
            }                                                      //~v66sI~
//      }                                                          //~v69cR~
//    }//!not yet mapinit                                          //~v66qI~//~v69cR~
//  }                                                              //~v69cR~
    *Ppucs=wucs;
    UTRACEP("%s:rc=%x,in=%02x,outucs=%x\n",UTT,rc,*Ppebc,wucs);//~v6hhR~//~v7d4R~
    return rc;
}//ucvebc4_b2uSbcs1                                                //~v69cR~
//*************************************************************************
//* ebc string to mbstr(SBCS) by handle                            //~v69cR~
//* rc:1:F2LERR,8:buff ovf
//*************************************************************************
int ucvebc4_b2mSbcs(int Popt,int Phandle,UCHAR *Pdata,UCHAR *Pdbcs,int Pinplen,UCHAR *Poutbuff,UCHAR *Poutdbcs,int Pbuffsz,int *Ppmblen)//~v68bR~//~v69cR~
{
    PUCVEXTCFG pcfg;                                               //~v69cR~
    PUCVEBCH pucveh;                                               //~v69cR~
    int rc=0,rc2,resleno,opt,repch,mblen,ch;
//  int mb2;                                                       //~v66UI~//~v69cR~
    int swsetf2lerr;                                               //~0508I~
    int swdbcsenv;                                                 //~v66mI~
    UCHAR *pci,*pce,*pcd,*pco;
    int dbcsskip;                                                  //~v66XI~
//  ULONG *pconverters;                                            //~v69cR~//~v6hhR~
//  ULPTR *pconverters;                                            //~v6hhI~//~v6m7R~
//***************************
    UTRACEP("%s:b2msbcs opt=%x\n",UTT,Popt);                              //~0423I~//~v7d4R~
    UTRACED("b2msbcs input data",Pdata,Pinplen);                   //~0423I~
    UTRACED("b2msbcs input dbcs",Pdbcs,Pinplen);                   //~0423I~
	opt=UCVEBC4O_EXCEPTCFG;                                        //~v69cR~
	pucveh=UCVEBC_GETPUCVEH(Phandle);                              //~v69cR~
    if (!pucveh)                                                   //~v69cI~
    	return 8;                                                  //~v69cI~
    pcfg=Spcfg;                                                    //~v69cR~
  if (Popt & UCVEBC3O_BIN)                                         //~v66yI~
   	swdbcsenv=0;                                                   //~v66yI~
  else                                                             //~v66yI~
//  swdbcsenv=UDBCSCHK_ISDBCSCV();                                 //~v66mI~//~v69cR~
    swdbcsenv=UCVEBCH_ISDBCSCV(pucveh);                            //~v69cR~
    swsetf2lerr=Popt & UCVEBC3O_SETF2LERR;                         //~0508I~
//  opt=Sebcopte2a;                                                //~v69cR~
    opt=EBC2ASC_EXT;                                               //~v69cR~
    opt|=EBC2ASC_EXT_SETSUBCHRC;                                   //~v66DI~
    if(Popt & UCVEBC3O_CVCTL)                                      //~0428I~
    	opt|=EBC2ASC_CTL;                                          //~0428I~
//  repch=Ssubcharlocalsbcs;                                       //~v66CI~//~v69cR~
    repch=pcfg->UCECsubcharlocalsbcs;                              //~v69cI~
    for (pci=Pdata,pce=pci+Pinplen,pco=Poutbuff,resleno=Pbuffsz;pci<pce;pci++,pco++,resleno--)//~v68bI~
    {
        ch=*pci;
        pcd=UTF_PC2PCD(Poutdbcs,pco,Poutbuff);                     //~v68bI~
        *pcd=0;                                                    //~v68bI~
      if (swdbcsenv)                                               //~v66mI~
      {                                                            //~v66mI~
        if (ch==CHAR_SO||ch==CHAR_SI)
        {
			if (Popt & UCVEBC3O_SOSI2SPACE)    //replace so/si to space//~0423I~
            {                                                      //~0423I~
        		*pco=' ';                                          //~0423I~
            }                                                      //~0423I~
            else                                                   //~0423I~
			if (Popt & UCVEBC3O_SOSIREP)    //replace so/si to space//~0429I~
            {                                                      //~0429I~
        		*pco='.';                                          //~0429I~
        		*pcd=UDBCSCHK_F2LERR;       //keep original value and display by green//~0429I~
            }                                                      //~0429I~
            else                                                   //~0429I~
			if (Popt & UCVEBC3O_SOSIREPQ)    //replace so/si to space//~0501I~
            {                                                      //~0501I~
        		*pco='?';                                          //~0501I~
        		*pcd=UDBCSCHK_F2LERR;       //keep original value and display by green//~0501I~
            }                                                      //~0501I~
            else                                                   //~0501I~
			if (Popt & UCVEBC3O_SOSIREPQP)   //replace so/si to space as printable//~v66gI~
            {                                                      //~v66gI~
        		*pco='?';                                          //~v66gR~
            }                                                      //~v66gI~
            else                                                   //~v66gI~
            {                                                      //~0423I~
//      		*pco=ch;                                           //~0423R~//~v6BiR~
        		*pco=(UCHAR)ch;                                    //~v6BiI~
        		*pcd=UDBCSCHK_F2LERR;       //keep original value and display by green//~0423R~//~0428R~
            }                                                      //~0423I~
            continue;
        }
      }//swdbcsenv                                                 //~v66mI~
        if (ch<CHAR_EBC_SPACE)
        {
            if (!(Popt & UCVEBC3O_CVCTL))
            {
//      		*pco=ch;                                           //~v6BiR~
        		*pco=(UCHAR)ch;                                    //~v6BiI~
              if (swsetf2lerr)                                     //~0508I~
        		*pcd=UDBCSCHK_F2LERR;       //keep original value and display by green//~0426R~
          	  else                                                 //~v66qI~
//      		*pco=repch;                                        //~v66qI~//~v6BiR~
        		*pco=(UCHAR)repch;                                 //~v6BiI~
//	            continue;                                          //~v6hfR~
	            rc|=1;                                             //~v66qI~
	            continue;                                          //~v6hfI~
            }
		}
//    if (Gucvebc_stat & UCVEBCS_SBCSMAPINIT)//sbcsmap was initialized//~v66qI~//~v69cR~
//    {                                                            //~v66qI~//~v69cR~
//  	mb2=UCVEBCH_B2A(Phandle,ch);                                           //~v66UI~//~v69cR~
//     if (mb2>>8)                                                 //~v66UI~//~v69cR~
//     {                                                           //~v66UI~//~v69cR~
//      if (EBC_B2A_TYPEISGB4(ch))                                 //~v66XR~//~v69cR~
//      {                                                          //~v66XI~//~v69cR~
//      	mblen=4;                                               //~v66XI~//~v69cR~
//          UUL2BESTR(mb2,pco);                                    //~v66XI~//~v69cR~
//          *pcd++=UDBCSCHK_DBCS1ST,*pcd++=UDBCSCHK_DBCSPAD,*pcd++=UDBCSCHK_DBCSPAD,*pcd++=UDBCSCHK_DBCS2ND;//~v68bR~//~v69cR~
//      }                                                          //~v66XI~//~v69cR~
//      else                                                       //~v66XR~//~v69cR~
//      if (EBC_B2A_TYPEISSS3(ch))                                 //~v66XR~//~v69cR~
//      {                                                          //~v66XI~//~v69cR~
//      	mblen=3;                                               //~v66XR~//~v69cR~
//          UUL32BESTR(mb2,pco);                                   //~v66XI~//~v69cR~
//          *pcd++=UDBCSCHK_DBCS1ST,*pcd++=UDBCSCHK_DBCSPAD,*pcd++=UDBCSCHK_DBCS2ND;//~v68bR~//~v69cR~
//      }                                                          //~v66XI~//~v69cR~
//      else                                                       //~v66XR~//~v69cR~
//      {                                                          //~v66XI~//~v69cR~
//      mblen=2;                                                   //~v66UI~//~v69cR~
//          UUS2BESTR(mb2,pco);                                    //~v66XI~//~v69cR~
//          *pcd++=UDBCSCHK_DBCS1ST,*pcd++=UDBCSCHK_DBCS2ND;       //~v68bR~//~v69cR~
//      }                                                          //~v66XI~//~v69cR~
//      UTRACED("b2msbcs DBCS from map",pco,mblen);                //~v66XR~//~v69cR~
//     }                                                           //~v66UI~//~v69cR~
//     else                                                        //~v66UI~//~v69cR~
//     {                                                           //~v66UI~//~v69cR~
//   	*pco=mb2;                                                  //~v66UI~//~v69cR~
//      mblen=1;                                                   //~v66qI~//~v69cR~
//     }                                                           //~v66UI~//~v69cR~
//      rc2=0;                                                     //~v66qI~//~v69cR~
//    }                                                            //~v66qI~//~v69cR~
//    else                                                         //~v66qI~//~v69cR~
//    {                                                            //~v66DI~//~v69cR~
//      rc2=ucvebc2asc(opt,pci,0/*pdbcs*/,pco,1,repch,&mblen);     //~v69cR~
//  	pconverters=pucveh->UCVEHpconverters;  //sbcs converetr    //~v69cR~//~v6m7R~
//  	rc2=ucvext_icuebc2mbs(opt,pconverters,pci,0/*pdbcs*/,1,pco,&mblen,repch);//~v69cR~//~v6m7R~
    	rc2=ucvext_icuebc2mbs_handle(opt,Phandle,pci,0/*pdbcs*/,1,pco,&mblen,repch);//~v6m7R~
//    }                                                            //~v66DI~//~v69cR~
        UTRACEP("%s:ebc=%x,mb=%02x%02x,rc=%d,mblen=%d\n",UTT,ch,*pco,*(pco+1),rc2,mblen);//~v66XR~//~v7d4R~
        if (!rc2)
        {
////cv cmd allow Sbcs->DBCS if no NOS2D cfg option nor -SBCS cmd option//~v66UR~
////but force err for REP cmd etc                                  //~v66UR~
//EUC hankana ex) CP930 ebc-81->eucJ-8eb1                          //~v66UI~
      		if (mblen!=1)                                          //~v66UR~
            {                                                      //~v66UI~
                dbcsskip=mblen-1;                                  //~v66XR~
              	pco+=dbcsskip;                                     //~v66XI~
                resleno-=dbcsskip;                                 //~v66XI~
            }                                                      //~v66UI~
          	else                                                   //~v66UR~
            if (*pco=='.' && *pci!=EBC_PERIOD)    //err rep occured//~v66qR~
                rc2=4;
            else
            if (!*pco && ch)    //not null-->null by sbcs map      //~v66qR~
                rc2=4;
        }
    	if (rc2)
    	{
//      	*pco=ch;                                               //~v6BiR~
        	*pco=(UCHAR)ch;                                        //~v6BiI~
          if (swsetf2lerr)                                         //~0508I~
        	*pcd=UDBCSCHK_F2LERR;       //keep original value and siplay by green
          else                                                     //~v66qI~
//      	*pco=repch;                                            //~v66qI~//~v6BiR~
        	*pco=(UCHAR)repch;                                     //~v6BiI~
            rc|=1;
    	}
    }
//  mblen=(ULONG)pco-(ULONG)Poutbuff;                              //~v6hhR~
//  mblen=(ULPTR)pco-(ULPTR)Poutbuff;                              //~v6hhI~//~v6BkR~
    mblen=PTRDIFF(pco,Poutbuff);                                   //~v6BkI~
    if (Ppmblen)
    	*Ppmblen=mblen;
UTRACED("sbcs output data",Poutbuff,mblen);                        //~v7d4R~
UTRACED("sbcs output dbcs",Poutdbcs,mblen);            //~v68bR~   //~v7d4R~
    return rc;
}//ucvebc4_b2mSbcs                                                 //~v69cR~
                                                                   //~v69cI~
//*************************************************************************//~v66DI~
//*setup ebc/local subch                                           //~v66DI~
//*************************************************************************//~v66DI~
//int ucvext4_setupsubch(int Popt,PUCVEXTCFG Ppcfg)                //~v69cR~
int ucvebc4_setupsubch(int Popt,PUCVEBCH Ppucveh)                  //~v69cR~
{                                                                  //~v66DI~
//  WUCS ucs,ucs2;                                                 //~v66CR~//~v6BjR~
    UWUCS ucs,ucs2;                                                //~v6BjI~
    int opt,mblen,rc2;                                             //~v66DI~
#ifdef W32                                                         //~v66PI~
    int subchmb,subchucs;                                          //~v66NR~
#endif                                                             //~v66PI~
	UCHAR mbstr[MAX_MBCSLEN];                                      //~v66DI~
//  ULONG pconverter;                                              //~v6x5R~
    ULPTR pconverter;                                              //~v6x5I~
    WUCS subchdbcscandidate[]={CHAR_UCS_DBCS_ERR/*"?"*/,CHAR_UCS_DBCS_ERR2/*space*/};//~v66VR~
    WUCS subchardefaultucssbcs=0,subchardefaultucsdbcs=0;          //~v69cI~
	WUCS subchardbcs=UDBCSCHK_SUBCHAR_DBCS,subcharsbcs=UDBCSCHK_SUBCHAR_SBCS;//~v69cI~
    UCHAR subcharICUebcDbcs[MAX_MBCSLEN]={0},subcharICUebcSbcs=0;  //~v69cR~
    UCHAR subcharebcdbcs[MAX_MBCSLEN]={0},subcharebcsbcs=CHAR_EBC_ERR/*?*/;//~v69cR~
    int subcharICUebcDbcslen=0,subcharebcdbcslen=0;                //~v69cR~
    int ii,swgetdbcs=0,swgetsbcs=0;                                //~v69cR~
//***********************                                          //~v66DI~
//  pconverter=(ULONG)(Ppucveh->UCVEHpconverter[1]);//sbcs/dbcs converter//~v6x5R~
    pconverter=Ppucveh->UCVEHpconverter[1];//sbcs/dbcs converter   //~v6x5I~
//*get ICU subchar translated value to chk subchar was set         //~v66DI~
//	if (Ppcfg->UCECflag & UCECF_USE_ICU)                           //~v69cR~
	if (Popt & UCVEBC4O_USEICU)                                    //~v69cI~
    {                                                              //~v66DI~
//*dbcs                                                            //~v66DI~
//  	if (UDBCSCHK_ISDBCSCV())                                   //~v69cR~
    	if (Popt & UCVEBC4O_DBCSCV)                                //~v69cI~
    	{                                                          //~v66DI~
            opt=0;  //no subchrc(not yet setup chkchar)            //~v66DR~
            ucs=UDBCSCHK_SUBCHAR_DBCS;  //fffd                     //~v66DI~
//      	pconverter=Ppcfg->UCECconverterdbcs;                   //~v69cR~
//      	if (pconverter)                                        //~v69cR~
//      	{                                                      //~v69cR~
        		rc2=ucvext_icuucs2ebc1(opt,pconverter,ucs,mbstr,&mblen);//~v66DI~
        		if (rc2<=1 &&  mblen>1)                            //~v66DI~
                {                                                  //~v66DI~
    				opt=EBC2ASC_STAT_SO;                           //~v66DI~
        			rc2=ucvext_icuebc2ucs1(opt,pconverter,mbstr,mblen,&ucs2);//~v66DI~
                    if (!rc2 && ucs2==ucs)                         //~v66DI~
                    {                                              //~v66DI~
//      				UmemcpyZ(SsubcharICUebcDbcs,mbstr,(UINT)mblen);//~v69cR~
//  					SsubcharICUebcDbcslen=mblen;               //~v69cM~
        				UmemcpyZ(subcharICUebcDbcs,mbstr,(UINT)mblen);//~v69cI~
    					subcharICUebcDbcslen=mblen;                //~v69cI~
        				UmemcpyZ(subcharebcdbcs,mbstr,(UINT)mblen);//~v69cI~
    					subcharebcdbcslen=mblen;                   //~v69cR~
//  					subchardbcs=ucs;                           //~v69cR~//~v6BjR~
    					subchardbcs=(WUCS)ucs;                     //~v6BjI~
    					swgetdbcs=1;                               //~v69cR~
                    }                                              //~v66DI~
                }                                                  //~v66DI~
//      	}                                                      //~v69cR~
        }                                                          //~v66DI~
//*sbcs                                                            //~v66DI~
        opt=0;                                                     //~v66DR~
        ucs=UDBCSCHK_SUBCHAR_SBCS;  //1a                           //~v66DI~
//      pconverter=Ppcfg->UCECconvertersbcs;                       //~v69cR~
//      if (!pconverter)                                           //~v69cR~
//          pconverter=Ppcfg->UCECconverterdbcs;                   //~v69cR~
//      if (pconverter)                                            //~v69cR~
//      {                                                          //~v69cR~
            rc2=ucvext_icuucs2ebc1(opt,pconverter,ucs,mbstr,&mblen);//~v66DI~
            if (rc2<1 &&  mblen==1)                               //~v66DI~//~v69cR~
            {                                                      //~v66DI~
        		rc2=ucvext_icuebc2ucs1(opt,pconverter,mbstr,mblen,&ucs2);//~v66DI~
                if (!rc2 && ucs2==ucs)                             //~v66DI~
                {                                                  //~v69cI~
//                  SsubcharICUebcSbcs=*mbstr;                     //~v69cR~
                    subcharICUebcSbcs=*mbstr;                      //~v69cI~
                    subcharebcsbcs=*mbstr;                         //~v69cI~
//                  subcharsbcs=ucs;                               //~v69cI~//~v6BjR~
                    subcharsbcs=(WUCS)ucs;                         //~v6BjI~
                    swgetsbcs=1;                                   //~v69cR~
                }                                                  //~v69cI~
            }                                                      //~v66DI~
//      }                                                          //~v69cR~
    	UTRACEP("%s:icu getconvertersubch ebcsbcs=%02x,ebcdbcs=%02x%02x,len=%d,ucssbcs=%x,ucsdbcs=%x\n",//~v69cR~//~v6bkR~//~v7d4R~
				UTT,subcharICUebcSbcs,subcharICUebcDbcs[0],subcharICUebcDbcs[1],subcharICUebcDbcslen,subcharsbcs,subchardbcs);//~v69cR~//~v7d4R~
    }//USE_ICU                                                     //~v66DI~
#ifdef W32                                                         //~v66NI~
    else                                                           //~v66NI~
    {                                                              //~v66NI~
//      pconverter=Ppcfg->UCECconverterdbcs;                       //~v69cR~
//  	if (pconverter)                                            //~v69cR~
//  		if (!udbcschk_getsubch(0,pconverter,&subchmb,&subchucs))//~v6x5R~
    		if (!udbcschk_getsubch(0,(ULONG)pconverter/*codepage*/,&subchmb,&subchucs))//~v6x5I~
            {	                                                   //~v66NI~
//          	Ppcfg->UCECsubchardefaultucsdbcs=subchucs;         //~v69cR~
//          	Ppcfg->UCECsubchardefaultmbdbcs=subchmb;           //~v69cR~
    			if (Popt & UCVEBC4O_DBCSCV)                        //~v69cI~
                {                                                  //~v69cI~
                	opt=0;                                         //~v69cI~
//                  ucs=subchucs;                                  //~v69cI~//~v6BiR~
//                  ucs=(WUCS)subchucs;                            //~v6BiI~//~v6BuR~
                    ucs=(UWUCS)subchucs;                           //~v6BuI~
            		rc2=ucvext_icuucs2ebc1(opt,pconverter,ucs,mbstr,&mblen);//~v69cI~
                    if (rc2<=1 &&  mblen>1)                        //~v69cI~
                    {                                              //~v69cI~
                        opt=EBC2ASC_STAT_SO;                       //~v69cI~
                        rc2=ucvext_icuebc2ucs1(opt,pconverter,mbstr,mblen,&ucs2);//~v69cI~
                        if (!rc2 && ucs2==ucs)                     //~v69cI~
                        {                                          //~v69cI~
//  						subchardefaultucsdbcs=subchucs;        //~v69cI~//~v6BiR~
    						subchardefaultucsdbcs=(WUCS)subchucs;  //~v6BiI~
	        				UmemcpyZ(subcharebcdbcs,mbstr,(UINT)mblen);//~v69cI~
    						subcharebcdbcslen=mblen;               //~v69cI~
                    		swgetdbcs=2;                           //~v69cI~
                        }                                          //~v69cI~
                    }                                              //~v69cI~
//                  mbstr[0]=subchmb;                              //~v69cI~//~v6BiR~
                    mbstr[0]=(UCHAR)subchmb;                       //~v6BiI~
            		rc2=ucvext_icuebc2ucs1(opt,pconverter,mbstr,1,&ucs);//~v69cI~
            		if (rc2)                                       //~v69cI~
                    {                                              //~v69cI~
        				rc2=ucvext_icuucs2ebc1(opt,pconverter,ucs,mbstr,&mblen);//~v69cI~
                		if (!rc2 && *mbstr==subchmb)               //~v69cI~
                		{                                          //~v69cI~
//                  		subchardefaultucssbcs=ucs;             //~v69cR~//~v6BjR~
                    		subchardefaultucssbcs=(WUCS)ucs;       //~v6BjI~
//                  		subcharebcsbcs=subchmb;                //~v69cR~//~v6BiR~
                    		subcharebcsbcs=(UCHAR)subchmb;         //~v6BiI~
//                  		subcharsbcs=ucs;                       //~v69cI~//~v6BjR~
                    		subcharsbcs=(WUCS)ucs;                 //~v6BjI~
                    		swgetsbcs=2;                           //~v69cI~
                		}                                          //~v69cI~
            		}                                              //~v69cI~
                }                                                  //~v69cI~
                else                                               //~v69cI~
                {                                                  //~v69cI~
//                  subchardefaultucssbcs=subchucs;                //~v69cR~//~v6BiR~
                    subchardefaultucssbcs=(WUCS)subchucs;          //~v6BiI~
//                  subcharebcsbcs=subchmb;                        //~v69cI~//~v6BiR~
                    subcharebcsbcs=(UCHAR)subchmb;                 //~v6BiI~
//                  subcharsbcs=subchucs;                          //~v69cM~//~v6BiR~
                    subcharsbcs=(WUCS)subchucs;                    //~v6BiI~
                    swgetsbcs=2;                                   //~v69cI~
                }                                                  //~v69cI~
            }                                                      //~v66NI~
//      pconverter=Ppcfg->UCECconvertersbcs;                       //~v69cR~
//  	if (pconverter)                                            //~v69cR~
//  		if (!udbcschk_getsubch(0,pconverter,&subchmb,&subchucs))//~v69cR~
//          {                                                      //~v69cR~
//          	Ppcfg->UCECsubchardefaultucssbcs=subchucs;         //~v69cR~
//          	Ppcfg->UCECsubchardefaultmbsbcs=subchmb;           //~v69cR~
//          }                                                      //~v69cR~
    }                                                              //~v66NM~
#endif                                                             //~v66NI~
//*prepare locale/ebc code subchar                                 //~v66CI~
//*dbcs                                                            //~v66CI~
//  if (UDBCSCHK_ISDBCSCV())                                       //~v69cR~
   	if (Popt & UCVEBC4O_DBCSCV)                                    //~v69cI~
    {                                                              //~v66CI~
      if (!swgetdbcs)	//not icu not wincp                        //~v69cR~
      {                                                            //~v69cI~
        opt=0;  //no subchrc                                       //~v66CI~
//      ucs=Ssubchardbcs;  //default xfffd                         //~v69cR~
        ucs=subchardbcs;  //default xfffd                          //~v69cI~
//      pconverter=Ppcfg->UCECconverterdbcs;                       //~v69cR~
//      Ssubcharebcdbcslen=2;                                      //~v69cR~
        subcharebcdbcslen=2;                                       //~v69cI~
//      UTF_SETUCSBESTR(CHAR_EBC_DBCS_SPACE,Ssubcharebcdbcs);//set default//~v69cR~
        UTF_SETUCSBESTR(CHAR_EBC_DBCS_SPACE,subcharebcdbcs);//set default//~v69cI~
//      if (pconverter)                                            //~v69cR~
//      {                                                          //~v69cR~
          for (ii=0;ii<=sizeof(subchdbcscandidate)/sizeof(WUCS);ii++)
          {
            rc2=ucvext_icuucs2ebc1(opt,pconverter,ucs,mbstr,&mblen);//~v66CI~
        UTRACEP("%s:dbcs ebc chk ucs=%04x,rc=%d\n",UTT,ucs,rc2);//~v6bkR~//~v7d4R~
        UTRACED("dbcs ebc ",mbstr,mblen);       //~v6bkR~          //~v7d4R~
            if (rc2<=1 &&  mblen>1)                                //~v66CI~
            {                                                      //~v66CI~
//          	UmemcpyZ(Ssubcharebcdbcs,mbstr,(UINT)mblen);       //~v69cR~
            	UmemcpyZ(subcharebcdbcs,mbstr,(UINT)mblen);        //~v69cI~
//              Ssubcharebcdbcslen=mblen;                          //~v69cR~
                subcharebcdbcslen=mblen;                           //~v69cI~
//              subchardbcs=ucs;                                   //~v69cI~//~v6BjR~
                subchardbcs=(WUCS)ucs;                             //~v6BjI~
                swgetdbcs=3;                                       //~v69cR~
                break;
            }                                                      //~v66CI~
            ucs=subchdbcscandidate[ii];
          }
//      }                                                          //~v69cR~
      }                                                            //~v69cI~
    }                                                              //~v66CI~
//*sbcs                                                            //~v66CI~
  if (!swgetsbcs)	//not icu not wincp                            //~v69cR~
  {                                                                //~v69cI~
    opt=0;                                                         //~v66CR~
//  ucs=Ssubcharsbcs;  //x1a or cfg parm                           //~v69cR~
    ucs=subcharsbcs;  //x1a or cfg parm                            //~v69cI~
//  pconverter=Ppcfg->UCECconvertersbcs;                           //~v69cR~
//  if (!pconverter)                                               //~v69cR~
//      pconverter=Ppcfg->UCECconverterdbcs;                       //~v69cR~
//  if (pconverter)                                                //~v69cR~
//  {                                                              //~v69cR~
        rc2=ucvext_icuucs2ebc1(opt,pconverter,ucs,mbstr,&mblen);   //~v66CR~
        if (rc2<=1 &&  mblen==1)                                   //~v66CR~
        {                                                          //~v69cI~
//          Ssubcharebcsbcs=*mbstr;                                //~v69cR~
            subcharebcsbcs=*mbstr;                                 //~v69cI~
            swgetsbcs=5;                                           //~v69cR~
        }                                                          //~v69cI~
//  }                                                              //~v69cR~
//  if (!UDBCSCHK_ISDBCSCV())                                      //~v69cR~
  }                                                                //~v69cI~
   	if (!(Popt & UCVEBC4O_DBCSCV))                                 //~v69cI~
    {                                                              //~v69cR~
        subcharebcdbcslen=2;                                       //~v69cR~
        memset(subcharebcdbcs,subcharebcsbcs,2);                   //~v69cR~
    }                                                              //~v68jI~
    UTRACEP("%s:getconvertersubch sbcs=%02x,dbcs=%02x%02x,len=%d,\n",//~v69cR~//~v6bkR~//~v7d4R~
            UTT,subcharebcsbcs,subcharebcdbcs[0],subcharebcdbcs[1],subcharebcdbcslen);//~v69cR~//~v7d4R~
    Ppucveh->UCVEHsubcharebcsbcs=subcharebcsbcs;                   //~v69cR~
    Ppucveh->UCVEHsubcharICUebcSbcs=subcharICUebcSbcs;             //~v69cR~
    Ppucveh->UCVEHsubchardefaultucssbcs=subchardefaultucssbcs;     //~v69cR~
    Ppucveh->UCVEHsubchardefaultucsdbcs=subchardefaultucsdbcs;     //~v69cI~
    Ppucveh->UCVEHsubcharsbcs=subcharsbcs;                         //~v69cR~
    Ppucveh->UCVEHsubchardbcs=subchardbcs;                         //~v69cR~
    Ppucveh->UCVEHsubcharebcdbcslen=subcharebcdbcslen;             //~v69cR~
//  UmemcpyZ(Ppucveh->UCVEHsubcharebcdbcs,subcharebcdbcs,subcharebcdbcslen);//~v69cR~//~v6BkR~
    UmemcpyZ(Ppucveh->UCVEHsubcharebcdbcs,subcharebcdbcs,(size_t)subcharebcdbcslen);//~v6BkI~
    Ppucveh->UCVEHsubcharICUebcDbcslen=subcharICUebcDbcslen;       //~v69cR~
//  UmemcpyZ(Ppucveh->UCVEHsubcharICUebcDbcs,subcharICUebcDbcs,subcharICUebcDbcslen);//~v69cR~//~v6BkR~
    UmemcpyZ(Ppucveh->UCVEHsubcharICUebcDbcs,subcharICUebcDbcs,(size_t)subcharICUebcDbcslen);//~v6BkI~
    return 0;                                                      //~v66DI~
}//ucvebc4_setupsubch                                              //~v69cR~
//*************************************************************************
#endif //WIN/LNX                                                   //~v69cI~
