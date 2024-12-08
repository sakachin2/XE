//CID://+v6BkR~: update#=     6                                    //~v6BiR~//~v6BkR~
//***********************************************************************
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bi:160212 (W32)compiler warning                                //~v6BiI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v66C:100604 use converters native subchar if no subchar was specified on cfg//~v66CI~
//v66i:100527 B2E support(EBC and EUC)                             //~v66iI~
//v66f:100522 add ebcdic cv dbcs err ch function                   //~v66fI~
//v660:100325 local EBCDIC translation support                     //~v660I~
//v5mZ:080821 (BUG)setso should chk not inp area but out area      //~v5mZI~
//v5mX:080820 Fixed LRECL support to avoid EBC DBCS split by LRECL //~v5mXI~
//v5mP:080805 EBC translation by ICU for 3270                      //~v5mPI~
//v5ej:041023 ebc<-->sjis dbcs support;delete rep any char by so/si//~v5ejI~
//v5ei:041023 ebc<-->sjis dbcs support;xe cont line support        //~v5eiI~
//v5eh:041023 ebc<-->sjis dbcs support;length chk option(before set conversion out)//~v5ehI~
//v5ef:041023 ebc<-->sjis dbcs support,dbcs errrep char support    //~v5efI~
//v5ed:041020 ebc<-->sjis dbcs support
//***********************************************************************
//* ucvebc2c
//* ebc<->sjis dbcs conversion
//***********************************************************************
//***********************************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <ulib.h>
#include <uerr.h>
#include <ucvext.h>                                                //~v6BkI~
#include <ucvebc.h>
#include <ucvebc2.h>
#include <udbcschk.h>
#include <utrace.h>                                                //~v5mXI~
//*******************************************************
static EBCMAPTBL *Spe2st=0,*Sps2et;
static DUPMAPTBL *Spdupmap=0;
static JISNEWOLDTBL *Spnewoldt=0;
int    Se2stctr,Ss2etctr,Snewoldctr,Sduptctr;
//*******************************************************
int ucvebc2_codecomp(const void *Pent1,const void *Pent2);
int ucvebc2_s2esub(int Popt,EBCMAPTBL *Ppmapt);
int ucvebc2_e2ssub(int Popt,EBCMAPTBL *Ppmapt);
//int ucvebc2_setso(int Popt,UCHAR *Pinp,UCHAR *Pout,              //~v5mPR~
//            int Pinplen,int *Poutlen);                           //~v5mPR~
//int ucvebc2_setsi(int Popt,UCHAR *Pinp,UCHAR *Pout,              //~v5mPR~
//            int Pinplen,int *Pchklen,int *Poutlen);              //~v5mPR~
//*******************************************************
//*dummy for lib(same name as file)						*
//*******************************************************
void ucvebc2(void)
{
	return;
}//ucvebc
//****************************************************************
//*get translation table
//*ret :table addr
//****************************************************************
int ucvebc2_init(void)
{
//********************
	return ucvebc2gettbl(&Spe2st,&Se2stctr,&Sps2et,&Ss2etctr,
						&Spdupmap,&Sduptctr,&Spnewoldt,&Snewoldctr);
}//ucvebc2_init
//****************************************************************
//*get translation table
//*ret :table addr
//****************************************************************
int ucvebc2_codecomp(const void *Pent1,const void *Pent2)
{
	int key1,key2;
//********************
//	key1=(int)(((EBCMAPTBL*)(ULONG)Pent1)->EMfrom);                //~v5ejR~//~v6hhR~
	key1=(int)(((EBCMAPTBL*)(ULPTR)Pent1)->EMfrom);                //~v6hhI~
//	key2=(int)(((EBCMAPTBL*)(ULONG)Pent2)->EMfrom);                //~v5ejR~//~v6hhR~
	key2=(int)(((EBCMAPTBL*)(ULPTR)Pent2)->EMfrom);                //~v6hhI~
	return (key1-key2);
}//ucvebc2_codecomp
//****************************************************************
//*ebc-->sjis
//*ret :0 if err
//****************************************************************
int ucvebc2_s2e(int Popt,USHORT Psjis)
{
	EBCMAPTBL *panst;
    int ans;
//********************
	if (!Spe2st)
		ucvebc2_init();
	panst=(EBCMAPTBL*)bsearch((void*)(&Psjis),(void*)Sps2et,(UINT)Ss2etctr,sizeof(EBCMAPTBL),ucvebc2_codecomp);//~v5ejR~
    if (!panst)
    	return 0;
	ans=ucvebc2_s2esub(Popt,panst);
    return ans;
}//ucvebc2_s2e
//****************************************************************
//*ebc-->sjis
//*ret :0 if err
//****************************************************************
int ucvebc2_e2s(int Popt,USHORT Pebc)
{
	EBCMAPTBL *panst;
    int ans;
//********************
	if (!Spe2st)
		ucvebc2_init();
	panst=(EBCMAPTBL*)bsearch(&Pebc,Spe2st,(UINT)Se2stctr,sizeof(EBCMAPTBL),ucvebc2_codecomp);//~v5ejR~
    if (!panst)
    	return 0;
	ans=ucvebc2_e2ssub(Popt,panst);
    UTRACEP("%s:opt=%04x,ebc=0x%04x,ans=0x%04x\n",UTT,Popt,Pebc,ans);//~v6BkI~
    return ans;
}//ucvebc2_e2s
//****************************************************************
//*ebc-->sjis
//*ret :none
//****************************************************************
int ucvebc2_chkprint(int Popt)
{
	EBCMAPTBL *pmapt,*pmapte;
    int ans,key;
//********************
	if (!Spe2st)
		ucvebc2_init();
	if (Popt & EBC2ASC_A2E)
    {
    	printf("*** SJIS --> EBCDIC conversion table ***\n");
        printf("***   option:");
    	if (!(Popt & (EBC2ASC_OLD|EBC2ASC_NEW)))
            printf(" default(JIS83)");
        else
        {
            if (Popt & EBC2ASC_OLD)
                printf(" JIS78");
            if (Popt & EBC2ASC_NEW)
                printf(" JIS83");
        }
        printf("\n");
        for (pmapt=Sps2et,pmapte=Sps2et+Ss2etctr;pmapt<pmapte;pmapt++)
        {
			ans=ucvebc2_s2esub(Popt,pmapt);
            key=(int)pmapt->EMfrom;
            printf("0x%04x-->0x%04x  //%c%c\n",key,ans,(char)((UINT)key>>8),(char)(key&255));//~v5ejR~
        }
    }
    else   //e2s
    {
    	printf("*** EBCDIC --> SJIS conversion table ***\n");
        printf("***   option:");
    	if (!(Popt & (EBC2ASC_NEC|EBC2ASC_IBM)))
        	printf(" default(IBM)");
        else
        {
    		if (Popt & EBC2ASC_NEC)
            	printf(" NEC");
    		if (Popt & EBC2ASC_IBM)
            	printf(" IBM");
        }
    	if (!(Popt & (EBC2ASC_OLD|EBC2ASC_NEW)))
            printf(" & default(JIS83)");
        else
        {
            if (Popt & EBC2ASC_OLD)
                printf(" & JIS78");
            if (Popt & EBC2ASC_NEW)
                printf(" & JIS83");
        }
        printf("\n");
        for (pmapt=Spe2st,pmapte=Spe2st+Se2stctr;pmapt<pmapte;pmapt++)
        {
			ans=ucvebc2_e2ssub(Popt,pmapt);
            key=(int)pmapt->EMfrom;
            printf("0x%04x-->0x%04x  //%c%c\n",key,ans,(char)((UINT)ans>>8),(char)(ans&255));//~v5ejR~
        }
    }
	return 0;
}//ucvebc2_chkprint
//****************************************************************
//*ebc-->sjis
//*ret :none
//****************************************************************
int ucvebc2_chkprintnewold(int Popt)
{
	JISNEWOLDTBL *pmapt,*pmapte;
    int sjis1,sjis2,ebc1,ebc2;
//********************
	if (!Spe2st)
		ucvebc2_init();
	if (Popt & EBC2ASC_A2E)
    {
    	printf("*** JIS78 & JIS83 exchange list ***\n");
    	printf("SJIS            JIS-83:JIS-78\n");
        for (pmapt=Spnewoldt,pmapte=Spnewoldt+Snewoldctr;pmapt<pmapte;pmapt+=2)//1st entry is dummy
        {
            sjis1=(int)(pmapt->JSTsjisnew);
            sjis2=(int)((pmapt+1)->JSTsjisnew);
            ebc1=(int)(pmapt->JSTebc);
            ebc2=(int)((pmapt+1)->JSTebc);
            printf("0x%04x (%c%c) --> %04x  : %04x\n",
					sjis1,(UINT)sjis1>>8,sjis1&255,ebc1,ebc2);     //~v5ejR~
            printf("0x%04x (%c%c) --> %04x  : %04x\n",
					sjis2,(UINT)sjis2>>8,sjis2&255,ebc2,ebc1);     //~v5ejR~
        }
    }
    else   //e2s
    {
    	printf("*** JIS78 & JIS83 exchange list ***\n");
    	printf("EBC        JIS-83   : JIS-78\n");
        for (pmapt=Spnewoldt,pmapte=Spnewoldt+Snewoldctr;pmapt<pmapte;pmapt+=2)//1st entry is dummy
        {
            sjis1=(int)(pmapt->JSTsjisnew);
            sjis2=(int)((pmapt+1)->JSTsjisnew);
            ebc1=(int)(pmapt->JSTebc);
            ebc2=(int)((pmapt+1)->JSTebc);
            printf("0x%04x --> %04x (%c%c): %04x (%c%c)\n",
					ebc1,sjis1,(UINT)sjis1>>8,sjis1&255,sjis2,(UINT)sjis2>>8,sjis2&255);//~v5ejR~
            printf("0x%04x --> %04x (%c%c): %04x (%c%c)\n",
					ebc2,sjis2,(UINT)sjis2>>8,sjis2&255,sjis1,(UINT)sjis1>>8,sjis1&255);//~v5ejR~
        }
    }
	return 0;
}//ucvebc2_chkprintnewold
//****************************************************************
//*ebc-->sjis
//*ret :none
//****************************************************************
int ucvebc2_chkprintdup(int Popt)
{
	DUPMAPTBL *pmapt,*pmapte;
    int ebc,sjis,sjis1,sjis2,sjis3;
//********************
	if (!Spe2st)
		ucvebc2_init();
    printf("*** SJIS duplicated code point list ***\n");
    printf("EBC    : NonKanji: NEC  : IBM\n");
    for (pmapt=Spdupmap,pmapte=Spdupmap+Sduptctr;pmapt<pmapte;pmapt++)//1st entry is dummy
    {
        ebc=(int)(pmapt->DMebc);
        sjis1=(int)(pmapt->DMnonkanji);
        sjis2=(int)(pmapt->DMnec);
        sjis3=(int)(pmapt->DMibm);
        sjis=sjis1;
        if (!sjis)
        	sjis=sjis2;
        if (!sjis)
        	sjis=sjis3;
        printf("0x%04x :",ebc);
        if (sjis1)
        	printf("    %04x :",sjis1);
        else
        	printf("    -    :");
        if (sjis2)
        	printf(" %04x :",sjis2);
        else
        	printf(" -    :");
        if (sjis3)
        	printf(" %04x :",sjis3);
        else
        	printf(" -    :");
        printf(" (%c%c)\n",(UINT)sjis>>8,sjis&255);                //~v5ejR~
    }
	return 0;
}//ucvebc2_chkprintdup
//****************************************************************
//*ebc-->sjis
//*ret :0 if err
//****************************************************************
int ucvebc2_e2ssub(int Popt,EBCMAPTBL *Ppmapt)
{
	DUPMAPTBL *pdupmap;
    int ans,newoldidx;
    int euc;                                                       //~v66iI~
//********************
    ans=(int)(Ppmapt->EMto);
    if (ans>0x1000)		//1:1 mapping
    {                                                              //~v66iI~
    	if (Popt & EBC2ASC_EUC)                                    //~v66iI~
    	{                                                          //~v66iI~
        	euc=0;  //return if err,call will set errrep           //~v66iI~
        	ushift2euc1(0,ans,&euc);                               //~v66iI~
        	ans=euc;                                               //~v66iI~
    	}                                                          //~v66iI~
    	return ans;
    }                                                              //~v66iI~
    if (ans & UCVEBC2_DUP2)  //map to nec or ibm area
    {
    	pdupmap=Spdupmap+(ans&0xff);
    	if (Popt & EBC2ASC_NEC)
        	ans=pdupmap->DMnec;
        else
        {
    		if (Popt & EBC2ASC_IBM)
            {
        		ans=pdupmap->DMibm;
            	if (!ans)
	        		ans=pdupmap->DMnonkanji;
            }
            else
            {
		        ans=pdupmap->DMnonkanji;
            	if (!ans)
	        		ans=pdupmap->DMibm;
            }
        }
    }
    else
    if (ans & UCVEBC2_DUP3)  //3 puplicated code(std nonkanji,nec,ibm)
    {
    	pdupmap=Spdupmap+(ans&0xff);
    	if (Popt & EBC2ASC_NEC)
        	ans=pdupmap->DMnec;
        else
        {
            if (Popt & EBC2ASC_OLD)  //new jis seq mapping
                ans=pdupmap->DMibm;
            else
                ans=pdupmap->DMnonkanji;
        }
    }
    else	//new-old sjis mapping
    {
        if (Popt & EBC2ASC_OLD)  //new jis seq mapping
        {
            if (ans & 0x01) //odd number index is new
                newoldidx=ans;  //use next even number index entry
            else
                newoldidx=ans-2;//use prev odd number index entry
        }
        else    //NEW or no parm
            newoldidx=ans-1;    //use the entry(index start from 1)
	    ans=(int)((Spnewoldt+newoldidx)->JSTsjisnew);
    }
    if (Popt & EBC2ASC_EUC)                                        //~v66iI~
    {                                                              //~v66iI~
        euc=0;  //return if err,call will set errrep               //~v66iI~
        ushift2euc1(0,ans,&euc);                                   //~v66iI~
        ans=euc;                                                   //~v66iI~
    }                                                              //~v66iI~
    return ans;
}//ucvebc2_e2ssub
//****************************************************************
//*ebc<--sjis
//*ret :0 if err
//****************************************************************
int ucvebc2_s2esub(int Popt,EBCMAPTBL *Ppmapt)
{
    int ans,newoldidx;
//********************
    ans=(int)(Ppmapt->EMto);
    if (ans>=0x4040)	//lowest ebc
    	return ans;
    if (Popt & EBC2ASC_OLD)  //new jis seq mapping
    {
    	if (ans & 0x01)	//odd number index is new
	    	newoldidx=ans;	//use next even number index entry
        else
	    	newoldidx=ans-2;//use prev odd number index entry
    }
    else    //NEW or no parm
    	newoldidx=ans-1;	//use the entry(index start from 1)
    ans=(int)((Spnewoldt+newoldidx)->JSTebc);
    return ans;
}//ucvebc2_s2esub                                                  //~v66iR~
//****************************************************************
//*ebc-->sjis  string conv
//*            rep so/si by space or delete so/si by option        //~v5efI~
//*ret :0x01:err rep occured,0x04 last is 1byte or 1byte+SI        //~v5efR~
//****************************************************************
int ucvebc2_stre2s(int Popt,UCHAR *Pinp,UCHAR *Pout,
			int Pinplen,int *Pchklen,int *Poutlen,int Prepchar)
{
	char *pi,*po,*pie;
    int ebc,rc=0,sjis;
//**************************
    if (!Prepchar)
    {                                                              //~v66iI~
        Prepchar=0x8148;    //"ÅH"                                 //~v5efR~
	    if (Popt & EBC2ASC_EUC)                                    //~v66iI~
        	ushift2euc1(0,Prepchar,&Prepchar);                     //~v66iI~
    }                                                              //~v66iI~
	pi=Pinp;
	po=Pout;
    pie=pi+Pinplen;	//end addr
	if (*pi==CHAR_SO)
    {
    	if (Popt & EBC2ASC_SOSI) //rep so/si by spce(default)      //~v5efR~
            *po++=' ';      //rep SO by space
        pi++;
    }
    for (;pi<pie;)
    {
    	if (*pi==CHAR_SI)
        	break;
    	ebc=(int)*pi++;
        if (pi==pie)  //2nd byte missing                           //~v5eiR~
        {
        	pi--;                                                  //~v5ejR~
            rc|=EBC2ASC_RC_HALFBYTE;                               //~v5efR~
            break;
        }
        ebc=(ebc<<8)+(int)*pi++;
        sjis=ucvebc2_e2s(Popt,(USHORT)ebc);
        if (sjis)
        {
        	*po++=(char)((UINT)sjis>>8);                           //~v5ejR~
        	*po++=(char)(sjis&255);
        }
        else
        {
            rc|=EBC2ASC_RC_ERRREP;                                 //~v5efR~
        	*po++=(char)((UINT)Prepchar>>8);                       //~v5ejR~
        	*po++=(char)(Prepchar&255);                            //~v5efR~
        }
    }
	if (pi<pie && *pi==CHAR_SI)
    {
    	if (Popt & EBC2ASC_SOSI) //rep by space(default)           //~v5efR~
            *po++=' ';      //rep SO by space
        pi++;
        rc|=EBC2ASC_RC_DBCSFOUND; //dbcs found                     //~v5eiM~
    }
    else                                                           //~v5eiI~
    {                                                              //~v5eiI~
        if (Popt & EBC2ASC_LNCONT)                                 //~v5eiR~
        {                                                          //~v5eiI~
       		rc|=EBC2ASC_RC_SIPEND;                                 //~v5eiI~
	        rc|=EBC2ASC_RC_DBCSFOUND; //dbcs found                 //~v5eiI~
        }                                                          //~v5eiI~
    }                                                              //~v5eiI~
//  *Pchklen=(int)((ULONG)pi-(ULONG)Pinp);                         //~v6hhR~
    *Pchklen=(int)((ULPTR)pi-(ULPTR)Pinp);                         //~v6hhI~
//  *Poutlen=(int)((ULONG)po-(ULONG)Pout);                         //~v6hhR~
    *Poutlen=(int)((ULPTR)po-(ULPTR)Pout);                         //~v6hhI~
    return rc;
}//ucvebc2_stre2s
#ifdef UTF8EBCD                                                    //~v660I~
//**************************************************************** //~v660I~
//*ebc-->ucs1 for Japnese dbcs                                     //~v660I~
//*ret :0x01:err rep occured                                       //~v660I~
//**************************************************************** //~v660I~
int ucvebc2_ebc2asc1dbcsJ(int Popt,UCHAR *Pebc,int Prepchar,USHORT *Ppsjis)//~v660R~
{                                                                  //~v660I~
    int ebc,rc=0,sjis;                                             //~v660I~
//**************************                                       //~v660I~
//  if (!Prepchar)                                                 //~v66CR~
//      Prepchar=CHAR_DBCS_ERR;    //"ÅH"                          //~v660I~//~v66fR~
//      Prepchar=ucvebc_getsubchar_dbcs(UCVEBCGSCDO_LC);           //~v66CR~
    ebc=(*Pebc<<8)+*(Pebc+1);                                      //~v660I~
    sjis=ucvebc2_e2s(Popt,(USHORT)ebc);                            //~v660I~
    if (!sjis)                                                     //~v660R~
    {                                                              //~v660I~
    	sjis=Prepchar;                                             //~v660R~
        rc|=EBC2ASC_RC_ERRREP;                                     //~v660I~
    }                                                              //~v660I~
//  *Ppsjis=sjis;                                                  //~v660I~//~v6BiR~
    *Ppsjis=(USHORT)sjis;                                          //~v6BiI~
	UTRACEP("%s:opt=0x%04x,rc=%d,ebc=0x%02x,sjis=0x%04x\n",UTT,Popt,rc,*Pebc,*Ppsjis);//+v6BkR~
    return rc;                                                     //~v660I~
}//ucvebc2_ebc2asc1dbcsJ                                           //~v660I~
#endif                                                             //~v660I~
//****************************************************************
//*ebc<--sjis  string conv
//*parm 3:Pout:output area;if 0 no output set(return output length)//~v5ehI~
//*ret :0x01:err rep occured,0x02:set SI failed,0x04:last is 1st byte of dbcs//~v5efR~
//****************************************************************
int ucvebc2_strs2e(int Popt,UCHAR *Pinp,UCHAR *Pout,
			int Pinplen,int *Pchklen,int *Poutlen,int Prepchar)
{
	char *pi,*po,*pie;
	char *pos,*poo;                                                //~v5mXI~
    int ebc,rc=0,sjis,dbcssw=0,len,chklen,outlen;                  //~v5eiR~
    int lrecl,lrecl0,fixsw,rlen,setsoopt;                          //~v5mXI~
    int eucopt,euc;                                                //~v66iI~
//**************************
	lrecl=*Poutlen&0xffff;    //residual len when DBCS start       //~v5mXI~
	lrecl0=*Poutlen>>16;      //lrecl                              //~v5mXI~
	fixsw=(Popt & EBC2ASC_FIXEDLRECL) && (lrecl0!=0);              //~v5mXI~
	eucopt=Popt & EBC2ASC_EUC;                                     //~v66iI~
UTRACEP("ucvebc2_strs2e len=%d, inp=%02x,lrecl=%d,lrecl0=%d,errrep=%x,fixsw=%d\n",Pinplen,*Pinp,lrecl,lrecl0,Prepchar,fixsw);//~v5mXI~
    if (!Prepchar)
        Prepchar=EBCDBCS_Q; //ebcdic dbcs "?"
	pi=Pinp;
	po=Pout;
    pos=po;   //record start pos                                   //~v5mXI~
    pie=pi+Pinplen;	//end addr
    if ((Popt & EBC2ASC_SOCONT)                                    //~v5eiR~
    &&  (Popt & EBC2ASC_BUFTOP)) //dbcs continued from prev line   //~v5eiI~
    	dbcssw=1;	//set SI                                       //~v5eiI~
    for (;pi<pie;)                                                 //~v5eiR~
    {
    	sjis=(int)*pi;
      if (eucopt)                                                  //~v66iI~
      {                                                            //~v66iI~
        if (!ISEUC(sjis))	//dbcs 1st byte 8e/8f is not contained //~v66iI~
        	break;                                                 //~v66iI~
      }                                                            //~v66iI~
      else                                                         //~v66iI~
      {                                                            //~v66iI~
        if (!SJIS1(sjis))	//dbcs 1st byte
        	break;
      }                                                            //~v66iI~
        if (pi+1==pie)
        {                                                          //~v5efI~
            rc|=EBC2ASC_RC_HALFBYTE;                               //~v5efI~
        	break;
        }                                                          //~v5efI~
        pi++;
        sjis=(sjis<<8)+(int)*pi++;
    	if (eucopt)                                                //~v66iI~
    	{                                                          //~v66iI~
        	ueuc2shift1c(0,sjis,&euc);                             //~v66iI~
            if (euc==sjis)	 //err                                 //~v66iI~
            	sjis=0;	//to repch later                           //~v66iI~
            else                                                   //~v66iI~
        		sjis=euc;                                          //~v66iI~
    	}                                                          //~v66iI~
        ebc=ucvebc2_s2e(Popt,(USHORT)sjis);
		poo=po;		//pos before insert 1 ebc                      //~v5mXI~
        if (!dbcssw)
        {
        	dbcssw=1;
            setsoopt=Popt;                                         //~v5mXI~
            if (po==pos && fixsw && lrecl==lrecl0)                 //~v5mXI~
	            setsoopt|=EBC2ASC_BUFTOP;	//insert SO            //~v5mXI~
//          rc|=ucvebc2_setso(Popt,pi-2,po,Pinplen,&outlen);       //~v5mXR~
            rc|=ucvebc2_setso(setsoopt,pi-2,po,Pinplen,&outlen);   //~v5mXI~
            po+=outlen;                                            //~v5eiR~
            if (!outlen)                                           //~v5mXI~
            	poo--;                                             //~v5mXI~
    UTRACEP("strs2e setso outlen=%d\n",outlen);                    //~v5mXI~
        }//1st dbcs                                                //~v5efR~
        if (ebc)
        {
	        *po++=(char)((UINT)ebc>>8);                            //~v5ejR~
	        *po++=(char)(ebc&255);                                 //~v5eiR~
        }
        else
        {
        	*po++=(char)((UINT)Prepchar>>8);                       //~v5ejR~
        	*po++=(char)(Prepchar&255);                            //~v5eiR~
            rc|=EBC2ASC_RC_ERRREP;                                 //~v5efI~
        }
        if (fixsw) //lrecl specified                               //~v5mXI~
        {                                                          //~v5mXI~
//        	rlen=lrecl-(int)((ULONG)po-(ULONG)pos);                //~v5mZR~//~v6hhR~
        	rlen=lrecl-(int)((ULPTR)po-(ULPTR)pos);                //~v6hhI~
    UTRACEP("strs2e pos=%p,lrecl=%d,rlen=%d\n",pos,lrecl,rlen);    //~v5mXI~
            if (rlen<1)	//overflow or no space to inser SI         //~v5mXI~
            {                                                      //~v5mXI~
//	        	rlen=(int)((ULONG)po-(ULONG)poo); 	//currect output len//~v5mXI~//~v6hhR~
	        	rlen=(int)((ULPTR)po-(ULPTR)poo); 	//currect output len//~v6hhI~
                po=pos+lrecl;                                      //~v5mXI~
                if (*poo!=CHAR_SO)                                 //~v5mXI~
                {                                                  //~v5mXI~
    	            memmove(po+1,poo,(UINT)rlen);                  //~v5mXR~
                	*po++=CHAR_SO;                                 //~v5mXM~
                }                                                  //~v5mXI~
                else                                               //~v5mXI~
	                memmove(po,poo,(UINT)rlen);                    //~v5mXI~
                po+=rlen;                                          //~v5mXI~
//	        	rlen=lrecl-(int)((ULONG)poo-(ULONG)pos);           //~v5mZR~//~v6hhR~
	        	rlen=lrecl-(int)((ULPTR)poo-(ULPTR)pos);           //~v6hhI~
                if (*poo==CHAR_SO)                                 //~v5mXI~
                	memset(poo,CHAR_EBC_SPACE,(UINT)rlen);	//fill space//~v5mXI~
                else                                               //~v5mXI~
                {                                                  //~v5mXI~
                	*poo++=CHAR_SI;                                //~v5mXR~
                    rlen--;                                        //~v5mXI~
                    if (rlen>0)                                    //~v5mXI~
	                	memset(poo,CHAR_EBC_SPACE,(UINT)rlen);	//fill space//~v5mXI~
                }                                                  //~v5mXI~
    UTRACED("after shift",pos,PTRDIFF(po,pos));               //~v5mXI~//~v6hhR~//~v6BkR~
                pos+=lrecl;                                        //~v5mXI~
            	lrecl=lrecl0;	//new split line by lrecl          //~v5mXI~
            }                                                      //~v5mXI~
        }                                                          //~v5mXI~
    }
    if (dbcssw)
    {
        rc|=EBC2ASC_RC_DBCSFOUND; //dbcs found                     //~v5eiI~
      	 if (Popt & (EBC2ASC_SOSI | EBC2ASC_SOSIOS))//SOSI SET OPTION//~v5ejR~
      	 {                                                         //~v5eiR~
       		if ((Popt & EBC2ASC_LNCONT)                            //~v5eiR~
	   		&&  (pi==pie || rc & EBC2ASC_RC_HALFBYTE))	//line continued to next//~v5eiR~
       			rc|=EBC2ASC_RC_SIPEND;                             //~v5eiR~
       		else	//line not continued to next line              //~v5eiR~
            {                                                      //~v5eiI~
//				len=(int)((ULONG)pie-(ULONG)pi);                   //~v5eiI~//~v6hhR~
				len=(int)((ULPTR)pie-(ULPTR)pi);                   //~v6hhI~
				rc|=ucvebc2_setsi(Popt,pi,po,len,&chklen,&outlen); //~v5eiI~
                pi+=chklen;                                        //~v5eiI~
                po+=outlen;                                        //~v5eiI~
            }                                                      //~v5eiI~
      	 }//SOSI SET OPTION                                        //~v5eiR~
    }
//  *Pchklen=(int)((ULONG)pi-(ULONG)Pinp);                         //~v6hhR~
    *Pchklen=(int)((ULPTR)pi-(ULPTR)Pinp);                         //~v6hhI~
//  *Poutlen=(int)((ULONG)po-(ULONG)Pout);                         //~v6hhR~
    *Poutlen=(int)((ULPTR)po-(ULPTR)Pout);                         //~v6hhI~
    return rc;
}//ucvebc2_strs2e
//**************************************************************** //~v5eiI~
//*write SI                                                        //~v5eiI~
//*rc:ISRTSI(x10)                                                  //~v5mZI~
//**************************************************************** //~v5eiI~
int ucvebc2_setsi(int Popt,UCHAR *Pinp,UCHAR *Pout,                //~v5eiI~
			int Pinplen,int *Pchklen,int *Poutlen)                 //~v5eiI~
{                                                                  //~v5eiI~
	char *pi,*po,*pie;                                             //~v5eiI~
    int rc=0;                                                      //~v5eiI~
//**************************                                       //~v5eiI~
    pi=Pinp;                                                       //~v5eiI~
    po=Pout;                                                       //~v5eiI~
    pie=pi+Pinplen;	//end addr                                     //~v5eiI~
    if (Popt & EBC2ASC_SOSI) //ins so/si                           //~v5eiI~
        *po++=CHAR_SI;                                             //~v5eiI~
    else                                                           //~v5eiI~
    if (Popt & EBC2ASC_SOSIOS) //override space                    //~v5ejR~
    {                                                              //~v5eiI~
        if (pi<pie && *pi==' ')                                    //~v5eiI~
        {                                                          //~v5eiI~
            pi++;                                                  //~v5ejR~
            *po++=CHAR_SI;                                         //~v5eiI~
        }                                                          //~v5eiI~
        else                                                       //~v5eiI~
        {                                                          //~v5eiI~
            *po++=CHAR_SI;                                         //~v5eiI~
            rc|=EBC2ASC_RC_ISRTSI;    //inserted SI                //~v5eiI~
        }                                                          //~v5eiI~
    }                                                              //~v5eiI~
//  else                                                           //~v5ejR~
//  if (Popt & EBC2ASC_SOSIOA) //override any char                 //~v5ejR~
//  {                                                              //~v5ejR~
//      if (pi<pie)                                                //~v5ejR~
//      {                                                          //~v5ejR~
//          *pi++;                                                 //~v5ejR~
//          *po++=CHAR_SI;                                         //~v5ejR~
//      }                                                          //~v5ejR~
//      else                                                       //~v5ejR~
//      {                                                          //~v5ejR~
//          *po++=CHAR_SI;                                         //~v5ejR~
//          rc|=EBC2ASC_RC_ISRTSI;    //inserted SI                //~v5ejR~
//      }                                                          //~v5ejR~
//  }                                                              //~v5ejR~
//  *Pchklen=(int)((ULONG)pi-(ULONG)Pinp);                         //~v5eiI~//~v6hhR~
    *Pchklen=(int)((ULPTR)pi-(ULPTR)Pinp);                         //~v6hhI~
//  *Poutlen=(int)((ULONG)po-(ULONG)Pout);                         //~v5eiI~//~v6hhR~
    *Poutlen=(int)((ULPTR)po-(ULPTR)Pout);                         //~v6hhI~
    return rc;                                                     //~v5eiI~
}//ucvebc2_setsi                                                   //~v5eiI~
//**************************************************************** //~v5eiI~
//*write SO                                                        //~v5eiI~
//*rc:ISRTSO(x08),ISRTTOPSO(0x80)                                  //~v5mZI~
//**************************************************************** //~v5eiI~
int ucvebc2_setso(int Popt,UCHAR *Pinp,UCHAR *Pout,                //~v5eiI~
			int Pinplen,int *Poutlen)                              //~v5eiI~
{                                                                  //~v5eiI~
	char *po;                                                      //~v5eiR~
    int rc=0;                                                      //~v5eiI~
//**************************                                       //~v5eiI~
UTRACEP("setso opt=%x inp=%p=%02x\n",Popt,Pinp,*Pinp);//~v5mXI~    //~v66CR~
    po=Pout;                                                       //~v5eiI~
    if (Popt & EBC2ASC_SOSI) //ins so/si                           //~v5eiI~
        *po++=CHAR_SO;                                             //~v5eiI~
    else                                                           //~v5eiI~
    if (Popt & EBC2ASC_SOSIOS) //override space                    //~v5ejR~
    {                                                              //~v5eiI~
        if (Popt & EBC2ASC_BUFTOP) //override spece                //~v5eiI~
        {                                                          //~v5eiI~
            rc|=EBC2ASC_RC_ISRTTOPSO;    //insertion occued        //~v5eiR~
            *po++=CHAR_SO;                                         //~v5eiI~
        }                                                          //~v5eiI~
        else                                                       //~v5eiI~
//      if (*(Pinp-1)==' ')                                        //~v5mZR~
        if (*(po-1)==CHAR_EBC_SPACE)                               //~v5mZR~
            *(po-1)=CHAR_SO;                                       //~v5eiI~
        else                                                       //~v5eiI~
        {                                                          //~v5eiI~
            *po++=CHAR_SO;                                         //~v5eiI~
            rc|=EBC2ASC_RC_ISRTSO;    //insertion occued           //~v5eiI~
        }                                                          //~v5eiI~
    }                                                              //~v5eiI~
//  else                                                           //~v5ejR~
//  if (Popt & EBC2ASC_SOSIOA) //override any char                 //~v5ejR~
//  {                                                              //~v5ejR~
//      if (Popt & EBC2ASC_BUFTOP) //override spece                //~v5ejR~
//      {                                                          //~v5ejR~
//          rc|=EBC2ASC_RC_ISRTSO;    //insertion occued           //~v5ejR~
//          *po++=CHAR_SO;                                         //~v5ejR~
//      }                                                          //~v5ejR~
//      else                                                       //~v5ejR~
//          *po++=CHAR_SO;                                         //~v5ejR~
//  }                                                              //~v5ejR~
//  *Poutlen=(int)((ULONG)po-(ULONG)Pout);                         //~v5eiI~//~v6hhR~
    *Poutlen=(int)((ULPTR)po-(ULPTR)Pout);                         //~v6hhI~
    return rc;                                                     //~v5eiI~
}//ucvebc2_setso                                                   //~v5eiI~
