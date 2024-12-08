//*CID://+v6C2R~:                                   update#=  240; //~v6C2R~
//***********************************************************************
//***********************************************************************
//* ucvebc32.c                                                     //~v69dR~
//*   ebc string func                                              //~v69dR~
//***********************************************************************
//v6C2:160328 consideration for dbcssz>2 case(UDBCSCHK_DBCSPAD chk )//~v6C2I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v69j:100821 (EBC:BUG)memcmp fail for sbcs compare                //~v69jI~
//v69d:100815 split ucvebc3                                        //~v69dI~
//***********************************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>                                                 //~0518I~

#include <ulib.h>
#include <uerr.h>
#include <udbcschk.h>
#include <uedit.h>
#include <ucvucs.h>
#include <ucvext.h>                                                //+v6C2M~
#include <ucvebc.h>
#include <ucvebc2.h>
#include <ucvebc4.h>                                               //~v69cM~
#include <utf.h>
#include <utf2.h>                                                  //~v687I~
#include <utf22.h>
#include <utrace.h>
#include <ustring.h>
//*******************************************************
//*************************************************************************//~v66qI~
//***************************************************************
//ebcdic umemspnc
// count continued char length
//***************************************************************
int ucvebc_umemspnc(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen)
{
    int ctr,reslen;
    UCHAR *pc,*pcd;
//****************************
    if (Popt & UCVEBCO_STRN)
//      reslen=ustrnlen(Pdata,Plen);                               //~v6BkR~
        reslen=(int)ustrnlen(Pdata,(UINT)Plen);                    //~v6BkI~
    else
        reslen=Plen;
    for (pc=Pdata,pcd=Pdbcs,ctr=0;reslen>0;pc++,pcd++,reslen--,ctr++)
    {
    	if (*pcd)
        	break;
        if (*pc!=Pch)
        	break;
    }
    return ctr;
}//ucvebc_umemspnc
//***************************************************************
//memrspnc
// count continued char length
// pdbcs is optional
//***************************************************************
int ucvebc_umemrspnc(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen)
{
    int ctr,reslen;
    UCHAR *pc,*pcd;
//****************************
    for (pc=Pdata+Plen-1,pcd=Pdbcs+Plen-1,reslen=Plen-1,ctr=0;reslen>=0;pc--,pcd--,reslen--,ctr++)
    {
    	if (Pdbcs && *pcd)	//not ascii,not f2l err
        	break;
        if (*pc!=Pch)
        	break;
    }
    return ctr;
}//ucvebc_umemrspnc
//***************************************************************  //~0501I~
//memrchr                                                          //~0501I~
// search ascii char reverse                                       //~0501I~
//***************************************************************  //~0501I~
//char *ucvebc_umemchr(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen)//~0501I~//~v69cR~
char *ucvebc_umemchr(int Popt,int Phandle,char *Pdata,char *Pdbcs,int Pch,int Plen)//~v69cI~
{                                                                  //~0501I~
    UCHAR *pc,*pc2=NULL,*pce;                                           //~0501R~//~v6h6R~
    int ch,reslen;                                                 //~0501R~
//****************************                                     //~0501I~
	if (Popt & UCVEBCO_A2B)                                        //~0501I~
//  	ch=EBC_A2B(Pch);                                           //~0501I~//~v69cR~
    	ch=UCVEBCH_A2B(Phandle,Pch);                               //~v69cI~
    else                                                           //~0501I~
    	ch=Pch;                                                    //~0501I~
	for (pc=Pdata,pce=pc+Plen;;)                                   //~0501I~
    {                                                              //~0501I~
//    	reslen=(ULONG)pce-(ULONG)pc;                               //~0501I~//~v6hhR~
//  	reslen=(ULPTR)pce-(ULPTR)pc;                               //~v6hhI~//~v6BkR~
    	reslen=PTRDIFF(pce,pc);                                    //~v6BkI~
        if (reslen<=0)                                             //~0501I~
        	break;                                                 //~0501I~
//      pc2=memchr(pc,ch,reslen);                                  //~0501I~//~v6BkR~
        pc2=memchr(pc,ch,(size_t)reslen);                          //~v6BkI~
        if (!pc2)                                                  //~0501I~
        	break;                                                 //~0501I~
//      if (!*(Pdbcs+(ULONG)pc2-(ULONG)Pdata))                     //~0501I~//~v6hhR~
        if (!*(Pdbcs+(ULPTR)pc2-(ULPTR)Pdata))                     //~v6hhI~
        	break;                                                 //~0501I~
        pc=pc2+1;                                                  //~0501I~
	}                                                              //~0501I~
    return pc2;                                                    //~0501I~
}//ucvebc_umemchr                                                  //~0507R~
//***************************************************************
//memrchr
// search ascii char reverse
//***************************************************************
//char *ucvebc_umemrchr(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen)//~v69cR~
char *ucvebc_umemrchr(int Popt,int Phandle,char *Pdata,char *Pdbcs,int Pch,int Plen)//~v69cI~
{
    UCHAR *pc;
    int ch,dbcsid;
//****************************
	if (Popt & UCVEBCO_A2B)
//  	ch=EBC_A2B(Pch);                                           //~v69cR~
    	ch=UCVEBCH_A2B(Phandle,Pch);                               //~v69cI~
    else
    	ch=Pch;
	for (pc=Pdata+Plen-1;pc>=(UCHAR*)Pdata;pc--)
    {
    	if (*pc==ch)
        {
//        	dbcsid=*(Pdbcs+(ULONG)pc-(ULONG)Pdata);                //~v6hhR~
        	dbcsid=*(Pdbcs+(ULPTR)pc-(ULPTR)Pdata);                //~v6hhI~
    		if (!dbcsid)
        		return pc;
        }
	}
    return 0;
}//ucvebc_umemrchr
//***************************************************************  //~0501I~
//memrchr                                                          //~0501I~
// compare ascii and ebdic SBCS                                    //~0501I~
// rc:0(EQ),1(NE)                                                  //~0501I~
//***************************************************************  //~0501I~
//int ucvebc_memcmp_banda(int Popt,char *Pdata1,char *Pdbcs1,char *Pdata2,int Plen)//~0507R~//~v69cR~
int ucvebc_memcmp_banda(int Popt,int Phandle,char *Pdata1,char *Pdbcs1,char *Pdata2,int Plen)//~v69cI~
{                                                                  //~0501I~
    UCHAR *pc1,*pc2,*pcd1,*pce;                                    //~0501R~
    int ch1,ch2,rc=0,dbcsid,ch3;                                   //~0507R~
    int swnocase;                                                  //~0507I~
//****************************                                     //~0501I~
    swnocase=Popt & UCVEBCO_NOCASE;                                //~0507I~
	for (pc1=Pdata1,pcd1=Pdbcs1,pc2=Pdata2,pce=pc1+Plen;pc1<pce;)  //~0501I~
    {                                                              //~0501I~
    	ch1=*pc1++;                                                //~0501I~
        ch2=*pc2++;                                                //~0501I~
        dbcsid=*pcd1++;                                            //~0501I~
        if (dbcsid)	//not sbcs                                     //~0501I~
        {                                                          //~0501I~
        	rc=1;                                                  //~0501I~
        	break;                                                 //~0501I~
        }                                                          //~0501I~
//      if (EBC_B2A(ch1)!=(ULONG)ch2)                                     //~0501I~//~v66XR~//~v69cR~
        if (UCVEBCH_B2A(Phandle,ch1)!=(ULONG)ch2)                  //~v69cR~
        {                                                          //~0501I~
            if (swnocase)                                          //~0507I~
            {                                                      //~0507I~
//          	ch3=EBC_toupper(ch1);                              //~0507I~//~v69cR~
            	ch3=UCVEBCH_toupper(Phandle,ch1);                  //~v69cR~
//          	if (EBC_B2A(ch3)!=(ULONG)toupper(ch2))                    //~0507I~//~v66XR~//~v69cR~
            	if (UCVEBCH_B2A(Phandle,ch3)!=(ULONG)toupper(ch2)) //~v69cR~
                {                                                  //~0507I~
	        		rc=1;                                          //~0507I~
    	        	break;                                         //~0507I~
                }                                                  //~0507I~
            }                                                      //~0507I~
            else                                                   //~0507I~
            {                                                      //~0507I~
        		rc=1;                                              //~0507R~
            	break;                                             //~0507R~
            }                                                      //~0507I~
        }                                                          //~0501I~
    }                                                              //~0501I~
    UTRACED("ucvebc_memcmp_banda data1",Pdata1,Plen);              //~0507R~
    UTRACED("ucvebc_memcmp_banda dbcs1",Pdbcs1,Plen);              //~0507R~
    UTRACED("ucvebc_memcmp_banda data2",Pdata2,Plen);              //~0507R~
    UTRACEP("ucvebc_memcmp_banda rc=%d\n",rc);                     //~0507R~
    return rc;                                                     //~0501I~
}//ucvebc_umemcmp_b2a                                              //~0501I~
//***************************************************************  //~0430I~
//memicmp                                                          //~0501R~
// compare ebc str (with both dbcstb)                              //~0507R~
// rc:0/+/-                                                        //~0430I~
//***************************************************************  //~0430I~
//int ucvebc_memicmp(char *Pdata1,char *Pdbcs1,char *Pdata2,char *Pdbcs2,int Plen)//~0430I~//~v69cR~
int ucvebc_memicmp(int Phandle,char *Pdata1,char *Pdbcs1,char *Pdata2,char *Pdbcs2,int Plen)//~v69cI~
{                                                                  //~0430I~
    int rc;                                                        //~0507I~
//****************************                                     //~0430I~
//  rc=ucvebc_memcmp(UCVEBCO_NOCASE,Pdata1,Pdbcs1,Pdata2,Pdbcs2,Plen);//~0507R~//~v69cR~
    rc=ucvebc_memcmp(UCVEBCO_NOCASE,Phandle,Pdata1,Pdbcs1,Pdata2,Pdbcs2,Plen);//~v69cI~
    return rc;                                                     //~0430I~
}//ucvebc_umemicmp                                                 //~0430I~
//***************************************************************  //~0507I~
//memcmp                                                           //~0507I~
// compare ebc str (with both dbcstb)                              //~0507I~
// rc:0/+/-                                                        //~0507I~
//***************************************************************  //~0507I~
//int ucvebc_memcmp(int Popt,char *Pdata1,char *Pdbcs1,char *Pdata2,char *Pdbcs2,int Plen)//~0507I~//~v69cR~
int ucvebc_memcmp(int Popt,int Phandle,char *Pdata1,char *Pdbcs1,char *Pdata2,char *Pdbcs2,int Plen)//~v69cI~
{                                                                  //~0507I~
    UCHAR *pc1,*pc2,*pcd1,*pcd2,*pce;                              //~0507I~
    int ch1,ch2,rc=0,dbcsid,rc2,swnocase;                            //~0507R~//~v6h6R~
    int swdbcs;                                                    //~v660I~
//****************************                                     //~0507I~
    swnocase=Popt & UCVEBCO_NOCASE;                                //~0507I~
    swdbcs=(Popt & UCVEBCO_NODBCS)==0;                             //~v660I~
    dbcsid=0;   //always 0 for sbcs                                //~v69jI~
	for (pc1=Pdata1,pcd1=Pdbcs1,pc2=Pdata2,pcd2=Pdbcs2,pce=pc1+Plen;pc1<pce;)//~0507I~
    {                                                              //~0507I~
    	ch1=*pc1++;                                                //~0507I~
        ch2=*pc2++;                                                //~0507I~
        rc=ch1-ch2;                                                //~0507I~
      if (swdbcs)                                                  //~v660I~
      {                                                            //~v660I~
        dbcsid=*pcd1++;                                            //~0507I~
        rc2=dbcsid-*pcd2++;                                        //~0507I~
      }                                                            //~v660I~
      else                                                         //~v660I~
        rc2=0;  //no dbcs chk                                      //~v660I~
                                                                   //~v69jI~
        if (rc)                                                    //~0507I~
        {                                                          //~0507I~
        	if (rc2)	//dbcsid unmatch                           //~0507I~
            	break;                                             //~0507I~
            if (dbcsid)	//dbcs,no case                             //~0507I~
            	break;                                             //~0507I~
            if (swnocase)                                          //~0507I~
            {                                                      //~0507I~
//          	ch1=EBC_toupper(ch1);                              //~0507I~//~v69cR~
            	ch1=UCVEBCH_toupper(Phandle,ch1);                  //~v69cI~
//          	ch2=EBC_toupper(ch2);                              //~0507I~//~v69cR~
            	ch2=UCVEBCH_toupper(Phandle,ch2);                  //~v69cI~
            }                                                      //~0507I~
            rc=ch1-ch2;                                            //~0507I~
            if (rc)                                                //~0507I~
            	break;                                             //~0507I~
        }                                                          //~0507I~
        else	//char match                                       //~0507I~
        {                                                          //~0507I~
        	if (rc2)	//dbcsid unmatch                           //~0507I~
            {                                                      //~0507I~
            	rc=rc2;                                            //~0507I~
            	break;                                             //~0507I~
            }                                                      //~0507I~
        }                                                          //~0507I~
    }                                                              //~0507I~
    UTRACED("ucvebc_memcmp data1",Pdata1,Plen);                    //~0507I~
    UTRACED("ucvebc_memcmp dbcs1",Pdbcs1,Plen);                    //~0507I~
    UTRACED("ucvebc_memcmp data2",Pdata2,Plen);                    //~0507I~
    UTRACED("ucvebc_memcmp dbcs2",Pdbcs2,Plen);                    //~0507I~
    UTRACEP("ucvebc_memcmp rc=%d\n",rc);                           //~0507I~
    if (rc>1)                                                      //~0507I~
        rc=1;                                                      //~0507I~
    else                                                           //~0507I~
    if (rc<-1)                                                     //~0507I~
        rc=-1;                                                     //~0507I~
    return rc;                                                     //~0507I~
}//ucvebc_umemcmp                                                  //~0507I~
//***************************************************************  //~0430I~
//ucvebc_umemmemi                                                  //~0430I~
// case insensitive str search                                     //~0430I~
//***************************************************************  //~0430I~
char *ucvebc_umemmemi(int Popt,int Phandle,char *Pdata,char *Pdbcs,int Plen,char *Pkey,char *Pkeydbcs,int Plenk)//~0430I~//~v69cR~
{                                                                  //~0430I~
	unsigned char *pc,*pce,topl,topu,*pcu,*pcd;                    //~0430I~
	unsigned int len;                                              //~0430I~
//******************                                               //~0430I~
	if (!Plenk)                                                    //~0430I~
		return Pdata;                                              //~0430I~
//  topu=(UCHAR)EBC_toupper((int)*Pkey);                           //~0430I~//~v69cR~
  if (*Pkeydbcs)                                                   //~v69dR~
  {                                                                //~v69dI~
    topu=topl=(CHAR)(*Pkey);                                       //~v69dI~
  }                                                                //~v69dI~
  else                                                             //~v69dI~
  {                                                                //~v69dI~
    topu=(UCHAR)UCVEBCH_toupper(Phandle,(int)*Pkey);               //~v69cR~
//  topl=(UCHAR)EBC_tolower((int)*Pkey);                           //~0430I~//~v69cR~
    topl=(UCHAR)UCVEBCH_tolower(Phandle,(int)*Pkey);               //~v69cR~
  }                                                                //~v69dI~
    pce=Pdata+Plen;                                                //~0430I~
    pc=Pdata;                                                      //~0430I~
//search by upper                                                  //~0430I~
    for (;;)                                                       //~0430I~
    {                                                              //~0430I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~0430I~//~v6hhR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	if (pc=memchr(pc,topu,len),!pc)                            //~0430I~
	    	break;                                                 //~0430I~
        if (pc+Plenk>pce)                                          //~0430I~
        {                                                          //~0430I~
            pc=0;                                                  //~0430I~
            break;                                                 //~0430I~
        }                                                          //~0430I~
        pcd=UTF_PC2PCD(Pdbcs,pc,Pdata);                            //~0430I~
//  	if (!ucvebc_memicmp(pc,pcd,Pkey,Pkeydbcs,Plenk))	//found//~0430I~//~v69cR~
    	if (!ucvebc_memicmp(Phandle,pc,pcd,Pkey,Pkeydbcs,Plenk))	//found//~v69cI~
	    	break;                                                 //~0430I~
    	pc++;                                                      //~0430I~
	}                                                              //~0430I~
//serach by lower                                                  //~0430I~
	pcu=pc;                                                        //~0430I~
    if (topu==topl)     //top is case insensitive                  //~0430I~
        return pcu;     //not required by lower case               //~0430I~
	if (pcu)				//found                                //~0430I~
    	pce=pcu+Plenk;                                             //~0430I~
    pc=Pdata;                                                      //~0430I~
    for (;;)                                                       //~0430I~
    {                                                              //~0430I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~0430I~//~v6hhR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	if (pc=memchr(pc,topl,len),!pc)                            //~0430I~
	    	break;                                                 //~0430I~
    	if (pc+Plenk>pce)                                          //~0430I~
        {                                                          //~0430I~
            pc=0;                                                  //~0430I~
        	break;                                                 //~0430I~
        }                                                          //~0430I~
        pcd=UTF_PC2PCD(Pdbcs,pc,Pdata);                            //~0430I~
//  	if (!ucvebc_memicmp(pc,pcd,Pkey,Pkeydbcs,Plenk))           //~0430I~//~v69cR~
    	if (!ucvebc_memicmp(Phandle,pc,pcd,Pkey,Pkeydbcs,Plenk))   //~v69cI~
        	break;                                                 //~0430I~
    	pc++;                                                      //~0430I~
	}                                                              //~0430I~
    if (!pc)                                                       //~0430R~
    	pc=pcu;                                                    //~0430R~
    UTRACED("ucvebc_umemmemi data",Pdata,Plen);                    //~0430I~
    UTRACED("ucvebc_umemmemi dbcs",Pdbcs,Plen);                    //~0430I~
    UTRACED("ucvebc_umemmemi key ",Pkey,Plenk);                    //~0430I~
    UTRACED("ucvebc_umemmemi keyd",Pkeydbcs,Plenk);                //~0430I~
    UTRACEP("rc=%p\n",pc);                                         //~0430I~
    return pc;                                                     //~0430I~
}//ucvebc_umemmemi                                                 //~0430I~
//***************************************************************  //~0430I~
//ucvebc_umemmemi                                                  //~0430R~
// case sensitive str search                                       //~0430R~
//***************************************************************  //~0430I~
char *ucvebc_umemmem(int Popt,char *Pdata,char *Pdbcs,int Plen,char *Pkey,char *Pkeydbcs,int Plenk)//~0430R~
{                                                                  //~0430I~
	char *pc,*pce,top,*pcd;                               //~0430R~//~0518R~
	unsigned int len;                                              //~0430I~
//******************                                               //~0430I~
	if (!Plenk)                                                    //~0430I~
		return Pdata;                                              //~0430I~
	top=*Pkey;                                                     //~0430R~
    pce=Pdata+Plen;                                                //~0430I~
    pc=Pdata;                                                      //~0430I~
//search by upper                                                  //~0430I~
    for (;;)                                                       //~0430I~
    {                                                              //~0430I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~0430I~//~v6hhR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	if (pc=memchr(pc,top,len),!pc)                             //~0430R~
	    	break;                                                 //~0430I~
        if (pc+Plenk>pce)                                          //~0430I~
        {                                                          //~0430I~
            pc=0;                                                  //~0430I~
            break;                                                 //~0430I~
        }                                                          //~0430I~
        pcd=UTF_PC2PCD(Pdbcs,pc,Pdata);                            //~0430M~
//  	if (!memcmp(pc,Pkey,Plenk)                                 //~0430I~//~v6BkR~
    	if (!memcmp(pc,Pkey,(size_t)Plenk)                         //~v6BkI~
//      &&  !memcmp(pcd,Pkeydbcs,Plenk))	//found                //~0430I~//~v6BkR~
        &&  !memcmp(pcd,Pkeydbcs,(size_t)Plenk))	//found        //~v6BkI~
            break;                                                 //~0430I~
    	pc++;                                                      //~0430I~
	}                                                              //~0430I~
    if (Popt & UCVEBC3O_CMPSO)                                     //~0510R~
    	if (pc && pc>Pdata && *Pkeydbcs==UDBCSCHK_DBCS1ST)         //~0510R~
        	if (*(pc-1)==CHAR_SO)                                  //~0510I~
            	pc--;                                              //~0510I~
    UTRACED("ucvebc_umemmem data",Pdata,Plen);                     //~0430I~
    UTRACED("ucvebc_umemmem dbcs",Pdbcs,Plen);                     //~0430I~
    UTRACED("ucvebc_umemmem key ",Pkey,Plenk);                     //~0430I~
    UTRACED("ucvebc_umemmem keyd",Pkeydbcs,Plenk);                 //~0430I~
    UTRACEP("rc=%p\n",pc);                                         //~0430I~
    return pc;                                                     //~0430R~
}//ucvebc_umemmem                                                  //~0430R~
//*******************************************************          //~0430I~
//*ucvebc_umemrmemi                                                //~0430I~
// case insensitive str reverse search                             //~0430I~
//******************************************************           //~0430I~
//char *ucvebc_umemrmemi(int Popt,char *Pdata,char *Pdbcs,int Plen,char *Pkey,char *Pkeydbcs,int Plenk)//~0430R~//~v69cR~
char *ucvebc_umemrmemi(int Popt,int Phandle,char *Pdata,char *Pdbcs,int Plen,char *Pkey,char *Pkeydbcs,int Plenk)//~v69cI~
{                                                                  //~0430I~
	unsigned char *pc,*pce,*pcl,topl,topu,*pcd;                    //~0430I~
	unsigned int len;                                              //~0430I~
//  PUCVEBCH pucveh;                                               //~v69cI~//~v6b9R~
//******************                                               //~0430I~
//  pucveh=UCVEBC_GETPUCVEH(Phandle);                              //~v69cI~//~v6b9R~
	if (!Plenk)                                                    //~0430I~
		return Pdata;                                              //~0430I~
//  topu=(UCHAR)EBC_toupper((int)*Pkey);                           //~0430I~//~v69cR~
    topu=(UCHAR)UCVEBCH_toupper(Phandle,(int)*Pkey);               //~v69cR~
//  topl=(UCHAR)EBC_tolower((int)*Pkey);                           //~0430I~//~v69cR~
    topl=(UCHAR)UCVEBCH_tolower(Phandle,(int)*Pkey);               //~v69cI~
    pc=Pdata;                                                      //~0430I~
    pce=Pdata+Plen;                                                //~0430I~
    pcl=0;                                                         //~0430I~
//search by upper                                                  //~0430I~
    for (;;)                                                       //~0430I~
    {                                                              //~0430I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~0430I~//~v6hhR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	if (pc=memchr(pc,topu,len),!pc)                            //~0430I~
	       	break;                                                 //~0430I~
		if (pc+Plenk>pce)                                          //~0430I~
        	break;                                                 //~0430I~
        pcd=UTF_PC2PCD(Pdbcs,pc,Pdata);                            //~0430I~
//  	if (!ucvebc_memicmp(pc,pcd,Pkey,Pkeydbcs,Plenk))           //~0430I~//~v69cR~
    	if (!ucvebc_memicmp(Phandle,pc,pcd,Pkey,Pkeydbcs,Plenk))   //~v69cI~
        	pcl=pc;                                                //~0430I~
    	pc++;                                                      //~0430I~
	}                                                              //~0430I~
//serach by lower                                                  //~0430I~
    if (topu==topl)     //top is case insensitive                  //~0430I~
        return pcl;     //not required by lower case               //~0430I~
	if (pcl)                                                       //~0430I~
    	pc=pcl+1;                                                  //~0430I~
    else                                                           //~0430I~
        pc=Pdata;                                                  //~0430I~
    for (;;)                                                       //~0430I~
    {                                                              //~0430I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~0430I~//~v6hhR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	if (pc=memchr(pc,topl,len),!pc)                            //~0430I~
	    	break;                                                 //~0430I~
		if (pc+Plenk>pce)                                          //~0430I~
	    	break;                                                 //~0430I~
        pcd=UTF_PC2PCD(Pdbcs,pc,Pdata);                            //~0430I~
//  	if (!ucvebc_memicmp(pc,pcd,Pkey,Pkeydbcs,Plenk))           //~0430I~//~v69cR~
    	if (!ucvebc_memicmp(Phandle,pc,pcd,Pkey,Pkeydbcs,Plenk))   //~v69cI~
        	pcl=pc;                                                //~0430I~
    	pc++;                                                      //~0430I~
	}                                                              //~0430I~
    UTRACED("ucvebc_umemrmemi data",Pdata,Plen);                   //~0430I~
    UTRACED("ucvebc_umemrmemi dbcs",Pdbcs,Plen);                   //~0430I~
    UTRACED("ucvebc_umemrmemi key ",Pkey,Plenk);                   //~0430I~
    UTRACED("ucvebc_umemrmemi keyd",Pkeydbcs,Plenk);               //~0430I~
    UTRACEP("rc=%p\n",pcl);                                        //~0430I~
	return pcl;                                                    //~0430I~
}//ucvebc_umemrmemi                                                //~0430I~
//*******************************************************          //~0430I~
//*ucvebc_umemrmem                                                 //~0430I~
// case sensitive str reverse search                               //~0430I~
//******************************************************           //~0430I~
char *ucvebc_umemrmem(int Popt,char *Pdata,char *Pdbcs,int Plen,char *Pkey,char *Pkeydbcs,int Plenk)//~0430R~
{                                                                  //~0430I~
	char *pc,*pce,*pcl=0,top,*pcd;                        //~0430I~//~0518R~
	unsigned int len;                                              //~0430I~
//******************                                               //~0430I~
	if (!Plenk)                                                    //~0430I~
		return Pdata;                                              //~0430I~
	top=*Pkey;                                                     //~0430I~
    pc=Pdata;                                                      //~0430I~
    pce=Pdata+Plen;                                                //~0430I~
    for (;;)                                                       //~0430I~
    {                                                              //~0430I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~0430I~//~v6hhR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	if (pc=memchr(pc,top,len),!pc)                             //~0430I~
	       	break;                                                 //~0430I~
		if (pc+Plenk>pce)                                          //~0430I~
        	break;                                                 //~0430I~
        pcd=UTF_PC2PCD(Pdbcs,pc,Pdata);                            //~0430I~
//  	if (!memcmp(pc,Pkey,Plenk)                                 //~0430I~//~v6BkR~
    	if (!memcmp(pc,Pkey,(size_t)Plenk)                         //~v6BkI~
//  	&&  !memcmp(pcd,Pkeydbcs,Plenk))                           //~0430I~//~v6BkR~
    	&&  !memcmp(pcd,Pkeydbcs,(size_t)Plenk))                   //~v6BkI~
        	pcl=pc;                                                //~0430I~
    	pc++;                                                      //~0430I~
	}                                                              //~0430I~
    if (Popt & UCVEBC3O_CMPSO)                                     //~0510I~
    	if (pcl && pcl>Pdata && *Pkeydbcs==UDBCSCHK_DBCS1ST)       //~0510R~
        	if (*(pcl-1)==CHAR_SO)                                 //~0510R~
            	pcl--;                                             //~0510R~
    UTRACED("ucvebc_umemrmem data",Pdata,Plen);                    //~0430I~
    UTRACED("ucvebc_umemrmem dbcs",Pdbcs,Plen);                    //~0430I~
    UTRACED("ucvebc_umemrmem key ",Pkey,Plenk);                    //~0430I~
    UTRACED("ucvebc_umemrmem keyd",Pkeydbcs,Plenk);                //~0430I~
    UTRACEP("rc=%p\n",pcl);                                        //~0430I~
	return pcl;                                                    //~0430I~
}//ucvebc_umemrmem                                                 //~0430I~
//*******************************************************
//*ebcdic unumlen ebcdic
//* numric str length
//******************************************************
int ucvebc_unumlen(int Popt,char *Pstr,char *Pdbcs,int Plen)
{
    int ii,hexopt,minusopt=0,dbcsid;                               //~0506R~
    int octopt;
    char *pcd=NULL;                                                     //~0506I~//~v6h6R~
//******************
    hexopt=(Popt & UNUMLEN_HEX);
    octopt=(Popt & UNUMLEN_OCT);
    if (Pdbcs)                                                     //~0506I~
        pcd=Pdbcs;                                                 //~0506I~
    ii=0;
    if (Popt & UNUMLEN_SPACE)
        for (;ii<Plen && *Pstr;ii++,Pstr++,pcd++)                  //~0506R~
        {
            if (*Pstr!=CHAR_EBC_SPACE)
                break;
            if (Pdbcs && *pcd)                                     //~0506R~
                break;
        }
    if (Pdbcs)                                                     //~0506I~
        dbcsid=*pcd;                                               //~0506I~
    else                                                           //~0506I~
    	dbcsid=0;                                                  //~0506I~
    if (UCVEBC_ASCIIEQ(*Pstr,dbcsid,CHAR_EBC_PLUS))                //~0506R~
    {
        Pstr++;
        pcd++;                                                     //~0506R~
        ii++;
    }
    else
    if (UCVEBC_ASCIIEQ(*Pstr,dbcsid,CHAR_EBC_MINUS))               //~0506R~
    {
        Pstr++;
        pcd++;                                                     //~0506R~
        ii++;
        if (ii>=Plen)
            return 0;
        minusopt=(Popt & UNUMLEN_MINUS);
    }
    for (;ii<Plen && *Pstr;ii++,Pstr++,pcd++)                      //~0506R~
    {
    	if (Pdbcs && *pcd)                                         //~0506R~
        	break;
        if (octopt)
        {
        	if (*Pstr>=CHAR_EBC_0 && *Pstr <=CHAR_EBC_7)
            	continue;
            else
            	break;
        }
        if (*Pstr>=CHAR_EBC_0 && *Pstr <=CHAR_EBC_9)
            continue;
        if (!hexopt)
            break;
        if (*Pstr>=CHAR_EBC_a && *Pstr <=CHAR_EBC_f)
            continue;
        if (*Pstr>=CHAR_EBC_A && *Pstr <=CHAR_EBC_F)
            continue;
        break;
    }
    if (minusopt)
        return -ii;
    return ii;
}//ucvebc_unumlen
//*******************************************************          //~0506I~
//*ebcdic unumlen ebcdic                                           //~0506I~
//* numric str length                                              //~0506I~
//******************************************************           //~0506I~
//int ucvebc_asciilen(int Popt,char *Pstr,char *Pdbcs,int Plen)      //~0506I~//~v69cR~
int ucvebc_asciilen(int Popt,int Phandle,char *Pstr,char *Pdbcs,int Plen)//~v69cI~
{                                                                  //~0506I~
    int len,ebc,ch;                                                //~0506I~
    UCHAR *pcd,*pc,*pce;                                           //~0506I~
//******************                                               //~0506I~
    for (pc=Pstr,pcd=Pdbcs,pce=pc+Plen;pc<pce;pc++,pcd++)          //~0506I~
    {                                                              //~0506I~
    	if (*pcd)                                                  //~0506I~
        	break;                                                 //~0506I~
        ebc=*pc;                                                   //~0506I~
//      ch=EBC_B2A(ebc);                                           //~0506R~//~v69cR~
//      ch=UCVEBCH_B2A(Phandle,ebc);                               //~v69cR~//~v6BkR~
        ch=(int)UCVEBCH_B2A(Phandle,ebc);                          //~v6BkI~
        if (!ch && ebc)	//tras err                                 //~0506I~
        	break;                                                 //~0506I~
        if (!UTF8ISASCII(ch))	//locale sbcs over 0x80            //~0506I~
        	break;                                                 //~0506I~
    }                                                              //~0506I~
//  len=(ULONG)pc-(ULONG)Pstr;                                     //~0506R~//~v6hhR~
//  len=(ULPTR)pc-(ULPTR)Pstr;                                     //~v6hhI~//~v6BkR~
    len=PTRDIFF(pc,Pstr);                                          //~v6BkI~
    return len;                                                    //~0506I~
}//ucvebc_asciilen                                                 //~0506I~
//*******************************************************
//*ebcdic sbcs chk
//******************************************************
int ucvebc_issbcsstr(int Popt,char *Pdbcs,int Plen)
{
//******************
//  if (memchr(Pdbcs,UDBCSCHK_DBCS1ST,Plen))                       //~v6BkR~
    if (memchr(Pdbcs,UDBCSCHK_DBCS1ST,(size_t)Plen))               //~v6BkI~
    	return 0;
//  if (memchr(Pdbcs,UDBCSCHK_DBCS2ND,Plen))                       //~v6BkR~
    if (memchr(Pdbcs,UDBCSCHK_DBCS2ND,(size_t)Plen))               //~v6BkI~
    	return 0;
    if (memchr(Pdbcs,UDBCSCHK_DBCSPAD,(size_t)Plen))               //~v6C2I~
    	return 0;                                                  //~v6C2I~
    return 1;
}//ucvebc_issbcsstr
//*******************************************************          //~0501I~
//*ebcdic punctuation chk                                          //~0502R~
//ctlchar is always punctuation                                    //~v69jI~
//rc:1 sbcs punc,2:dbcspunc                                        //~0502I~
//******************************************************           //~0501I~
//int ucvebc_uispunct(int Popt,char *Pdata,char *Pdbcs,int Preslen)                //~0501I~//~0502R~//~0518R~//~v69cR~
int ucvebc_uispunct(int Popt,int Phandle,char *Pdata,char *Pdbcs,int Preslen)//~v69cI~
{                                                                  //~0501I~
	int rc=0,ch,ebcdbcs,dbcsid;                                                      //~0501I~//~0502R~
//******************                                               //~0501I~
	ch=*Pdata;                                                     //~0502I~
	dbcsid=*Pdbcs;                                                 //~0502I~
    if(!dbcsid) //ascii ,dbcs is not punct                 //~0501R~//~0502R~
    {                                                          //~0501I~//~0502R~
        if (ch<CHAR_EBC_SPACE                                      //~0502I~
//      ||  uispunct(0,EBC_B2A(ch))  //space is fales by ispunct,so uispunct//~0501I~//~0502R~//~v69cR~
//      ||  uispunct(0,UCVEBCH_B2A(Phandle,ch))  //space is fales by ispunct,so uispunct//~v69cI~//~v6BkR~
        ||  uispunct(0,(int)UCVEBCH_B2A(Phandle,ch))  //space is fales by ispunct,so uispunct//~v6BkI~
        )                                                      //~0501I~//~0502R~
            rc=1;                                              //~0501I~//~0502R~
    }                                                          //~0501I~//~0502R~
    else                                                           //~0502R~
    if (Preslen>1 && dbcsid==UDBCSCHK_DBCS1ST)                     //~0502R~
    {                                                              //~0502R~
        ebcdbcs=UTF_GETUCSBESTR(Pdata);                            //~0502R~
        if (ebcdbcs==CHAR_EBC_DBCS_SPACE)                          //~0502R~
            rc=2;                                                  //~0502R~
    }                                                              //~0502R~
    UTRACEP("ucvebc_uispunct opt=%x,ch=%x,dbcsid=%x,rc=%d\n",Popt,ch,dbcsid,rc);//~0501I~//~0502R~
    return rc;                                                     //~0501I~
}//ucvebc_issbcsstr                                                //~0501I~
//*******************************************************
//*ebc uatoin
//* atoi with max len
//* return:int
//******************************************************
int ucvebc_uatoin(int Popt,char *Pstr,char *Pdbcs,int Plen)
{
    int len ,ii;
    UCHAR *pc,*pcd,wk[12],ch;
//******************
    if (Plen<=0)
        return 0;
    len=sizeof(wk)-1;
    if (Plen)
    	len=min(Plen,len);
    for (ii=0,pc=Pstr,pcd=Pdbcs;ii<len;ii++,pc++)
    {
    	if (*pcd) 	//not sbcs
        	break;
    	ch=*pc;
    	if (!EBC_ISNUMERIC(ch))
        	break;
//      wk[ii]=ch-CHAR_EBC_0+'0';                                  //~v6BkR~
        wk[ii]=(UCHAR)(ch-CHAR_EBC_0+'0');                         //~v6BkI~
    }
    wk[ii]=0;	//strz
    return atoi(wk);
}//ucvebc_uatoin
//*******************************************************
//*numeric digit cv from ascii to ebcdic
//*allow last null and space override input
//* return:outlen;
//******************************************************
//int ucvebc_a2bfld(int Popt,char *Pstr,char *Pout,int Plen)       //~v69cR~
int ucvebc_a2bfld(int Popt,int Phandle,char *Pstr,char *Pout,int Plen)//~v69cI~
{
    int len,ii;
    UCHAR *pc,ch,*pco;
//******************
    if (!(len=Plen))
//      len=strlen(Pstr);                                          //~v6BkR~
        len=(int)strlen(Pstr);                                     //~v6BkI~
UTRACED("a2bfld inp",Pstr,len);
    if (!(pco=Pout))
    	pco=Pstr;
    for (ii=0,pc=Pstr;ii<len;ii++,pc++,pco++)
    {
//  	ch=EBC_A2B(*pc);                                           //~v69cR~
    	ch=UCVEBCH_A2B(Phandle,*pc);                               //~v69cI~
        if (!ch)
        	ch=CHAR_EBC_ERR;
        *pco=ch;
    }
UTRACED("a2bfld out",Pout,len);
    return len;
}//ucvebc_a2bfld                                                   //~0506I~
//*******************************************************          //~0506I~
//*numeric digit cv from ebcdic to ascii                           //~0506I~
//* return:outlen;                                                 //~0506I~
//******************************************************           //~0506I~
//int ucvebc_b2afld(int Popt,char *Pstr,char *Pout,int Plen)         //~0506I~//~v69cR~
int ucvebc_b2afld(int Popt,int Phandle,char *Pstr,char *Pout,int Plen)//~v69cI~
{                                                                  //~0506I~
    int len,ii;                                                    //~0506I~
    UCHAR *pc,/*ch,*/*pco;                                             //~0506I~//~v66XR~
    ULONG ch;                                                      //~v66XI~
//******************                                               //~0506I~
    if (!(len=Plen))                                               //~0506I~
//      len=strlen(Pstr);                                          //~0506I~//~v6BkR~
        len=(int)strlen(Pstr);                                     //~v6BkI~
UTRACED("b2afld inp",Pstr,len);                                    //~0506I~
    if (!(pco=Pout))                                               //~0506I~
    	pco=Pstr;                                                  //~0506I~
    for (ii=0,pc=Pstr;ii<len;ii++,pc++,pco++)                      //~0506I~
    {                                                              //~0506I~
//  	ch=EBC_B2A(*pc);                                           //~0506I~//~v69cR~
    	ch=UCVEBCH_B2A(Phandle,*pc);                               //~v69cI~
        if (!ch)                                                   //~0506I~
        	ch=CHAR_ASCII_ERR;                                     //~0506I~
        else                                                       //~v66XI~
        if (ch>0x100)                                              //~v66XR~
        	ch=CHAR_ASCII_ERR;                                     //~v66XI~
        *pco=(UCHAR)ch;                                                   //~0506I~//~v66XR~
    }                                                              //~0506I~
UTRACED("b2afld out",Pout,len);                                    //~0506I~
    return len;                                                    //~0506I~
}//ucvebc_b2afld                                                   //~0506R~
//***************************************************************  //~0507I~
//mempbrk                                                          //~0507I~
// search 1st ascii char in the parmstr                            //~0507I~
//***************************************************************  //~0507I~
//char *ucvebc_umempbrk(int Popt,char *Pbuff,char *Pdbcs,char *Pstr,int Plen)//~0507I~//~v69cR~
char *ucvebc_umempbrk(int Popt,int Phandle,char *Pbuff,char *Pdbcs,char *Pstr,int Plen)//~v69cI~
{                                                                  //~0507I~
	char *pcb,*pcs,*pcbn,*pco=0;                                   //~0507I~
    int len,delm;                                                  //~0508R~
//******************                                               //~0507I~
	pcb=Pbuff;                                                     //~0507I~
    len=Plen;                                                      //~0507I~
    for (pcs=Pstr;len && *pcs;pcs++)                               //~0507I~
    {                                                              //~0507I~
    	delm=*pcs;                                                 //~0507I~
//  	if (pcbn=ucvebc_umemchr(Popt,pcb,Pdbcs,delm,len),pcbn)     //~0507I~//~v69cR~
    	if (pcbn=ucvebc_umemchr(Popt,Phandle,pcb,Pdbcs,delm,len),pcbn)//~v69cI~
        {                                                          //~0507I~
			pco=pcbn;                                              //~0507I~
            if (pcbn==pcb)  //found at top                         //~0507I~
            	break;                                             //~0507I~
//        	len=(ULONG)pco-(ULONG)pcb;                             //~0507I~//~v6hhR~
//      	len=(ULPTR)pco-(ULPTR)pcb;                             //~v6hhI~//~v6BkR~
        	len=PTRDIFF(pco,pcb);                                  //~v6BkI~
        }                                                          //~0507I~
	}                                                              //~0507I~
    return pco;                                                    //~0507I~
}//ucvebc_umempbrk                                                 //~0507I~
//***************************************************************  //~0511I~
//memrpbrk                                                         //~0511I~
// reverse search any ascii char in the parmstr                    //~0511I~
//***************************************************************  //~0511I~
//char *ucvebc_umemrpbrk(int Popt,char *Pbuff,char *Pdbcs,char *Pstr,int Plen)//~0511I~//~v69cR~
char *ucvebc_umemrpbrk(int Popt,int Phandle,char *Pbuff,char *Pdbcs,char *Pstr,int Plen)//~v69cI~
{                                                                  //~0511I~
	char *pcb,*pcs,*pcbn,*pco=0,*pce,*pcd;                         //~0511I~
    UINT len;                                                      //~0511I~
//******************                                               //~0511I~
	pcb=Pbuff;                                                     //~0511I~
    pce=pcb+Plen;		//end addr                                 //~0511I~
//  len=Plen;                                                      //~0511I~//~v6BkR~
    len=(UINT)Plen;                                                //~v6BkI~
    for (pcs=Pstr;len && *pcs;pcs++)                               //~0511I~
    {                                                              //~0511I~
    	pcd=UTF_PC2PCD(Pdbcs,pcb,Pbuff);                           //~0511I~
//  	if (pcbn=ucvebc_umemrchr(0,pcb,pcd,*pcs,len),pcbn)         //~0511I~//~v69cR~
//  	if (pcbn=ucvebc_umemrchr(0,Phandle,pcb,pcd,*pcs,len),pcbn) //~v69cI~//~v6BkR~
    	if (pcbn=ucvebc_umemrchr(0,Phandle,pcb,pcd,*pcs,(int)len),pcbn)//~v6BkI~
        {                                                          //~0511I~
			pco=pcbn;                                              //~0511I~
        	pcb=pcbn+1;                                            //~0511I~
//        	len=(ULONG)pce-(ULONG)pcb;                             //~0511I~//~v6hhR~
//      	len=(ULPTR)pce-(ULPTR)pcb;                             //~v6hhI~//~v6BxR~
        	len=(UINT)PTRDIFF(pce,pcb);                            //~v6BxI~
        }                                                          //~0511I~
	}                                                              //~0511I~
    return pco;                                                    //~0511I~
}//ucvebc_umemrpbrk                                                //~0511I~
//*******************************************************          //~0509I~
//*umemspn                                                         //~0509I~
//* search first char which is not on parm2 string                 //~0509I~
//* return:offset to the last char,length if all match             //~0509I~
//******************************************************           //~0509I~
int ucvebc_umemspn(int Popt,char *Pbuff,char *Pdbcs,char *Pxstr,int Plen)//~0509I~
{                                                                  //~0509I~
	char *pcb,*pcd;                                                //~0509I~
	int lenb,lenk,span=0,dbcsid;                                   //~0509I~
//******************                                               //~0509I~
    if (Plen<=0)                                                   //~0509I~
    	return 0;                                                  //~0509I~
//  lenk=strlen(Pxstr);                                            //~0509I~//~v6BkR~
    lenk=(int)strlen(Pxstr);                                       //~v6BkI~
    lenb=Plen;                                                     //~0509I~
	pcb=Pbuff;                                                     //~0509I~
	pcd=Pdbcs;                                                     //~0509I~
	while(lenb)                                                    //~0509I~
	{                                                              //~0509I~
    	dbcsid=*pcd;                                               //~0509I~
    	if (dbcsid)	//not ascii                                    //~0509I~
        	break;                                                 //~0509I~
//  	if (!memchr(Pxstr,*pcb,lenk))		//not found            //~0509I~//~v6BkR~
    	if (!memchr(Pxstr,*pcb,(size_t)lenk))		//not found    //~v6BkI~
			break;                                                 //~0509I~
		lenb--;                                                    //~0509I~
		pcb++;                                                     //~0509I~
		pcd++;                                                     //~0509I~
        span++;                                                    //~0509I~
	}                                                              //~0509I~
	return span;                                                   //~0509I~
}//ucvebc_umemspn                                                  //~0509I~
//***************************************************************  //~0509I~
//memrspn                                                          //~0509I~
// search ascii char not on parm string by reverse direction       //~0509I~
//***************************************************************  //~0509I~
int ucvebc_umemrspn(int Popt,char *Pbuff,char *Pdbcs,char *Pxstr,int Plen)//~0509I~
{                                                                  //~0509I~
	char *pcb,*pcd;                                                //~0509I~
	int lenb,lenk,span=0,dbcsid;                                   //~0509I~
//******************                                               //~0509I~
//  lenk=strlen(Pxstr);                                            //~0509I~//~v6BkR~
    lenk=(int)strlen(Pxstr);                                       //~v6BkI~
    lenb=Plen;                                                     //~0509I~
	pcb=Pbuff+lenb-1;		//last char                            //~0509I~
	pcd=Pdbcs+lenb-1;		//last char                            //~0509I~
	while(lenb)                                                    //~0509I~
	{                                                              //~0509I~
    	dbcsid=*pcd;                                               //~0509I~
    	if (dbcsid)	//not ascii,not f2l err                        //~0509I~
        	break;                                                 //~0509I~
//  	if (!memchr(Pxstr,*pcb,lenk))		//not found            //~0509I~//~v6BkR~
    	if (!memchr(Pxstr,*pcb,(size_t)lenk))		//not found    //~v6BkI~
			break;                                                 //~0509I~
		lenb--;                                                    //~0509I~
		pcb--;                                                     //~0509I~
		pcd--;                                                     //~0509I~
        span++;                                                    //~0509I~
	}                                                              //~0509I~
	return span;                                                   //~0509I~
}//umemrspn                                                        //~v69dR~
