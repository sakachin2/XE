//CID://+v7c3R~:                             update#=  143;        //~v7c3R~
//*************************************************************
//*uedit2.c
//*  uasciidump,ueditfattr,uxdumpline,ugetdtparm(date/time parm)   //~v5czR~
//*  uxdumpstr                                                     //~v6BfI~
//*************************************************************
//v7c3:240615 add UB2X(binay to hex digit) for utrace              //~v7c3I~
//v70j:200725 add ucode2str to avoid logcat terminate by ctrl char output//~v70jI~
//v6Xc:180823 add ueditescrep,process \a,\x..                      //~v6XcI~
//v6T2:180211 add ueditNowFileTime (current time -->FTIME/FDATE)   //~v6T2I~
//v6D2:160423 LNX compiler warning for bitmask assignment(FDATE,FTIE)//~v6D2I~
//v6BM:160313 (W32) compiler warning                               //~v6BMI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bf:160211 add uedit2:uxdumpstr                                 //~v6BfI~
//v6x5:150108 (warning C4244)ULONG 64 bit for LNX,32 bit for WIN on 64bit cpu,pointr is 64bit for both LNX and WIN.//~v6x5I~
//v6uE:140529 (W32)request explicit option UCVUCS_UCS4 for UCS4 for also Win//~v6uEI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h9:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(copile optio -Ox is required also)//~v6h9I~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6d7:120209 (SMB)adjust for target:Windows                       //~v6d7I~
//v691:100730 LP64 wchar_t is 4byte on LP64                        //~v691I~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v62j:090907 UTF8SUPP-->UTF8SUPPH for common to xe and wxe        //~v62jI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//                 kana is sjis only                               //~v5n8I~
//v604:070718 use wcwidth for CJK version(source from web)         //~v604I~
//v601:070718 wcwidth is not on windows;skip to use printable chk  //~v601I~
//v600:070717 sync by precompile with no /DUTF8SUPP option and xfc tool//~v600I~
//v5k4:070104-(LNX:UTF)uasciidump link to utf dump                 //~v5k4I~
//v5i9:060601 (LNX:UTF)support UTF8 for other than japanese        //~v5i9I~
//v5i5:060505 (XDA)print ucs code                                  //~v5i5I~
//v5cz:040522 date/time edit func for locate cmd                   //~v5czI~
//v59e:031103 ftp support(4 byte udirlist attr for ! UNX)          //~v59eI~
//v56s:020712 (UNX)allow to udirlist select non-reguler file       //~v56sI~
//v50R:010917 UNX:chng attr fmt to ugtdl(S=u+g,L=d+l),d is option, //~v50RR~
//v50Q:010915 UNX:edit file attr for other than xe(rwxd/lugt fmt)  //~v50QR~
//v50G:010618 LNX:disket support(using mtools)                     //~v50GI~
//v50E:010616 return symbolic link attr/name for dir list          //~v50EI~
//v378:000930 LINUX support(file attr by 777st fmt)                //~v378I~
//v333 000904:LINUX support(file attr size 1-->4)                  //~v327I~
//v327 000820:LINUX support                                        //~v327I~
//v256:990626 seg:off display for dump of DOS                      //~v256I~
//v226:990307 dumpxline addr invalid when not on boundary          //~v226I~
//v222:990213 no delm option for dump                              //~v222I~
//v217:990108 disas:change v216;for current buff addr use same value//~v217I~
//v216:990108 disas:base 0 id(-1)                                  //~v216I~
//v207:981220 add uxdumpline                                       //~v207I~
//v195:980920 display attr/size on xdd list                        //~v195I~
//v163:980301 add uasciidump                                       //~v163I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef UNX                                                         //~v327I~
	#include <sys/stat.h>                                          //~v378R~
	#ifdef LNX                                                     //~v5k4I~
//    #ifdef UTF8SUPP                                              //~v600I~//~v62jR~
      #ifdef UTF8SUPPH                                             //~v62jI~
    	#define __USE_XOPEN         //for wcwidth                  //~v5k4I~
    	#include <wchar.h>                                         //~v5k4I~
      #endif                                                       //~v600I~
	#endif                                                         //~v5k4I~
#else                                                              //~v327I~
#include <io.h>                                                    //~v195I~
#endif                                                             //~v327I~
#include <errno.h>                                                 //~v226I~
//*******************************************************
#ifdef DOS
#else
    #ifdef W32
    #else
	#endif
#endif
//*******************************************************
#include <ulib.h>
#include <ufile.h>                                                 //~v195I~
#include <uedit.h>                                                 //~v5czI~
#include <uedit2.h>
#include <udbcschk.h>                                              //~v163I~
#include <uerr.h>                                                  //~v195I~
#include <uque.h>                                                  //~v59eI~
#include <uftp.h>                                                  //~v59eI~
#include <ucvucs.h>                                                //~v5i5I~
#include <utrace.h>                                                //~v6XcI~
//#ifdef UTF8SUPP                                                    //~v5n8I~//~v62jR~
#ifdef UTF8SUPPH                                                   //~v62jI~
#include <utf.h>                                                   //~v5i9I~
#endif                                                             //~v5n8I~
//*******************************************************
#ifdef UNX                                                         //~v59eI~
void ueditfattr_mdos(UCHAR Pattr,UCHAR *Pout,int Popt);            //~v50GI~
#else                                                              //~v59eI~
void ueditfattrunix(ULONG Pattr,UCHAR *Pout,int Popt);             //~v59eI~
#endif                                                             //~v59eI~
char ueditfattrspf(ULONG Pmode);                                   //~v56sI~
int ueditgetftnum(char *Pdata,int *Ppi1,int *Ppi2,int *Ppi3);      //~v5czI~
//*******************************************************
//*uedit
//* dummy for LIB
//******************************************************
void uedit2(void)
{
	return;
}//uedit

//*******************************************************
//*uasciidump
//* dump to ascii char(replace non-printable to ".")               //~v5i9R~
//* parm1 :opt 1:dbcs chk,2:allow kana
//* parm2 :outbuff
//* parm3 :inpdata
//* parm4 :inpdata len
//* return:0:ok,1:last dbcs split                                  //~v163R~
//******************************************************
int uasciidump(int Popt,UCHAR *Pout,UCHAR *Pinp,int Pinplen)       //~v163R~
{
	UCHAR *pco,*pci,*pcie,ch;                                      //~v163R~
    int dbcschk,kanachk,dbcssw;
//******************
//  dbcschk=((Popt&UAD_DBCS) && udbcschkcp());                     //~v5i9R~
//#ifdef UTF8SUPP                                                    //~v600I~//~v62jR~
#ifdef UTF8SUPPH                                                   //~v62jI~
    dbcschk=(udbcschkcp() && (Popt&UAD_DBCS));	//do udbcschkcp    //~v5i9I~
#else                                                              //~v600I~
    dbcschk=((Popt&UAD_DBCS) && udbcschkcp());                     //~v600I~
#endif                                                             //~v600I~
//#ifdef UTF8SUPP                                                    //~v5k4I~//~v62jR~
#ifdef UTF8SUPPH                                                   //~v62jI~
	if (UDBCSCHK_ISUTF8())                                         //~v5k4R~
    {                                                              //~v5k4I~
        dbcssw=UAD_ALLUTF;                                         //~v5k4I~
		return uasciidump_utf(dbcssw,Pout,Pinp,Pinplen);           //~v5k4I~
    }                                                              //~v5k4I~
#endif                                                             //~v5k4I~
  if (Gudbcschk_flag & UDBCSCHK_MS932)                             //~v5n8I~
    kanachk=(Popt&UAD_KANA);
  else                                                             //~v5n8I~
  	kanachk=0;                                                     //~v5n8I~
    dbcssw=0;
    pco=Pout;
    pci=Pinp;
    pcie=pci+Pinplen;
    while (pci<pcie)           /* 1 line setup*/                   //~v163R~
    {
        ch=*pci++;                                                 //~v163R~
		if (dbcssw)
        {                                                          //~v163I~
            if (ch<' ')	//previous is not valid                    //~v163I~
            {                                                      //~v163I~
            	ch='.';                                            //~v163R~
                *(pco-1)='.';                                      //~v163I~
            }                                                      //~v163I~
			dbcssw=0;
        }                                                          //~v163I~
        else
        {
            if (dbcschk)
            	dbcssw=udbcschk(ch);                               //~v163R~
			if (!dbcssw)
            {                                                      //~v59eI~
				if (ch<' ')
                    ch='.';
                else
					if (ch>=0x7f)
                    {                                              //~v59eI~
						if (kanachk)
                        {
                        	if (ch<0xa1 || ch>0xdf)	//katakana
                            	ch='.';
						}
                        else
                            ch='.';
                    }//7f                                          //~v59eI~
            }//dbcssw                                              //~v59eI~
        }//dbcschk faile
		*pco++=ch;
	}//for loop
    if (dbcssw)
    {                                                              //~v163I~
		if (!(Popt & UAD_LLASTDBCS))//not leave last dbcs          //~v163I~
   			*(pco-1)='.';                                          //~v163R~
        return 1;                                                  //~v163I~
	}                                                              //~v163I~
	return 0;                                                      //~v163R~
}//uasciidump
//*******************************************************          //~v70jI~
char *ucode2str(int Popt,UCHAR *Pinp,int Pinplen)                  //~v70jI~
{                                                                  //~v70jI~
	UCHAR *pco,*pci,*pcie,ch;                                      //~v70jI~
    int len;                                                       //~v70jI~
#define MAX_CHARDUMP 128                                           //~v70jI~
    static UCHAR wk0[MAX_CHARDUMP+12];                             //~v70jR~
    static UCHAR wk1[MAX_CHARDUMP+12];                             //~v70jI~
    static UCHAR wk2[MAX_CHARDUMP+12];                             //~v70jI~
    UCHAR  *pwk;                                                   //~v70jI~
//******************                                               //~v70jI~
    if (!Pinp)                                                     //~v70jI~
    	return "null";                                             //~v70jI~
	if (Pinplen)                                                   //~v70jI~
    	len=Pinplen;                                               //~v70jI~
    else                                                           //~v70jI~
    	len=(int)strlen(Pinp);                                     //~v70jR~
    pci=Pinp;                                                      //~v70jI~
    pcie=Pinp+len;                                                 //~v70jI~
    switch(Popt & 0x0f)                                            //~v70jI~
    {                                                              //~v70jI~
    case 0:                                                        //~v70jI~
    	pwk=wk0;                                                   //~v70jR~
    	break;                                                     //~v70jI~
    case 1:                                                        //~v70jI~
    	pwk=wk1;                                                   //~v70jI~
    	break;                                                     //~v70jI~
    case 2:                                                        //~v70jI~
    	pwk=wk2;                                                   //~v70jI~
    	break;                                                     //~v70jI~
    default:                                                       //~v70jI~
    	return "parm err";                                         //~v70jI~
    }                                                              //~v70jI~
    pco=pwk;                                                       //~v70jI~
    while (pci<pcie)           /* 1 line setup*/                   //~v70jI~
    {                                                              //~v70jI~
        ch=*pci++;                                                 //~v70jI~
		if (ch>=0x20)                                              //~v70jI~
        	*pco++=ch;                                             //~v70jI~
        else                                                       //~v70jI~
            pco+=sprintf(pco,"-0x%02x-",ch);                       //~v70jI~
        if (pco>pwk+MAX_CHARDUMP)                                  //~v70jR~
        {                                                          //~v70jI~
        	strcpy(pco,"...");                                     //~v70jI~
            break;                                                 //~v70jI~
        }                                                          //~v70jI~
	}//for loop                                                    //~v70jI~
    if (pci<pcie)           /* 1 line setup*/                      //~v70jI~
        *pco=0;                                                    //~v70jI~
    return pwk;                                                    //~v70jR~
}//ucode2str                                                       //~v70jI~
//#ifdef UTF8SUPP                                                    //~v5k4I~//~v62jR~
#ifdef UTF8SUPPH                                                   //~v62jI~
//*******************************************************          //~v5i9I~
//*uasciidump_utf                                                  //~v5i9I~
//* dump to ascii char by utf8(replace non-printable to ".")       //~v5i9R~
//* parm1 :opt 1:dbcs chk,2:allow kana                             //~v5i9I~
//* parm2 :outbuff                                                 //~v5i9I~
//* parm3 :inpdata                                                 //~v5i9I~
//* parm4 :inpdata len                                             //~v5i9I~
//* return:last remaining length                                   //~v5i9I~
//******************************************************           //~v5i9I~
int uasciidump_utf(int Popt,UCHAR *Pout,UCHAR *Pinp,int Pinplen)   //~v5i9R~
{                                                                  //~v5i9I~
	UCHAR *pco,*pci;                                               //~v5i9I~
    int dbcschk,latinchk,allutf,printable=0,reslen,rc=0,ii,chklen;     //~v5i9R~//~v6h6R~
//  ULONG opt=0,ucs;                                               //~v5i9I~//~v691R~
    ULONG opt=0; UWUCS ucs;                                        //~v691I~
//******************                                               //~v5i9I~
    latinchk=(Popt&UAD_LATIN);                                     //~v5i9R~
	dbcschk=(Popt&UAD_DBCS);                                       //~v5i9I~
	allutf=(Popt&UAD_ALLUTF);                                      //~v5i9I~
    pco=Pout;                                                      //~v5i9I~
    pci=Pinp;                                                      //~v5i9I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uER~
#ifdef UTF8UCS416                                                  //~v6uER~
	opt=UCVUCS_UCS4; //accept ucs4                                 //~v65cI~
#endif                                                             //~v65cI~
    for (reslen=Pinplen;reslen>0;)                                 //~v5i9R~
    {                                                              //~v5i9I~
        rc=uccvutf2ucs(opt,pci,reslen,&ucs,&chklen);               //~v5i9I~
//      printf("utf2ucs rc=%d,len=%d,%x->%lx\n",rc,chklen,*(UINT*)(ULONG)pci,ucs);//~v5i9R~
        switch(rc)                                                 //~v5i9I~
        {                                                          //~v5i9I~
        case 0:	//ucs gotten                                       //~v5i9I~
//      	printable=(allutf && ucs>=0x20)                        //~v5k4R~
//      	printable=(allutf && wcwidth(ucs)>0)    //all printable//~v604R~
//        	printable=(allutf && utfisprint(0,ucs)>0)    //all printable//~v604R~//~v6BkR~
          	printable=(allutf && utfisprint(0,(ULONG)ucs)>0)    //all printable//~v6BkI~
        	        ||(ucs>=0x20 && ucs<0x7f) //ascii              //~v5i9I~
                    ||(latinchk && (ucs>=0x80 && ucs<=0xff))       //~v5i9R~
//      	        ||(dbcschk && utfiswide(UTF_ISWIDEJ,ucs));//japanese valid DBCS//~v604R~
//      	        ||(dbcschk && utfiswide(0,ucs));//japanese valid DBCS//~v604I~//~v6BkR~
        	        ||(dbcschk && utfiswide(0,(ULONG)ucs));//japanese valid DBCS//~v6BkI~
            break;                                                 //~v5i9I~
        case UCVUCS_FMTERR:		//shorlen                          //~v5i9I~
        	printable=0;                                           //~v5i9I~
            rc=0;                                                  //~v5i9I~
            break;                                                 //~v5i9I~
        default:    //len err                                      //~v5i9I~
            break;                                                 //~v5i9I~
        }                                                          //~v5i9I~
        if (rc) //len err                                          //~v5i9I~
            break;                                                 //~v5i9I~
        if (printable)                                             //~v5i9I~
        {                                                          //~v5i9I~
            for (ii=0;ii<chklen;ii++)                              //~v5i9I~
                *pco++=*pci++;                                     //~v5i9I~
        }                                                          //~v5i9I~
        else                                                       //~v5i9I~
        {                                                          //~v5i9I~
            for (ii=0;ii<chklen;ii++)                              //~v5i9I~
                *pco++='.';                                        //~v5i9I~
            pci+=chklen;                                           //~v5i9I~
        }                                                          //~v5i9I~
        reslen-=chklen;                                            //~v5i9I~
    }                                                              //~v5i9I~
    if (rc)	//last                                                 //~v5i9I~
    {                                                              //~v5i9I~
		if (!(Popt & UAD_LLASTDBCS))//not leave last dbcs          //~v5i9I~
            for (ii=0;ii<reslen;ii++)                              //~v5i9I~
                *pco++='.';                                        //~v5i9I~
        return reslen;                                             //~v5i9I~
	}                                                              //~v5i9I~
	return 0;                                                      //~v5i9I~
}//uasciidump_utf                                                  //~v5i9I~
#endif                                                             //~v5k4R~
//*******************************************************          //~v5i5I~
//*uucsdump                                                        //~v5i5I~
//* dump as source is ucs(conv to sjis)                            //~v5i5I~//~v70jR~
//* parm1 :opt 1:dbcs chk                                          //~v5i5I~
//* parm2 :outbuff                                                 //~v5i5I~
//* parm3 :inpdata                                                 //~v5i5I~
//* parm4 :len to be printed  //max 32 byte                        //~v5i5I~
//* parm4 :inpdata total len                                       //~v5i5I~
//* return:0:ok,1:last dbcs split                                  //~v5i5I~
//******************************************************           //~v5i5I~
int uucsdump(int Popt,UCHAR *Pout,UCHAR *Pinp,int Pprintlen,int Pinplen)//~v5i5I~
{                                                                  //~v5i5I~
	UCHAR *pco,*pc,errch='.';                                      //~v5i5R~
//  int dbcschk,ii,jj,sjis,len,ucsctr,ucsctr1,padsw,maxoutlen=0,outlen;//~v5i5R~//~v6h6R~
    int dbcschk,ii,jj,sjis,len,ucsctr,ucsctr1=0,padsw,maxoutlen=0,outlen=0;//~v6h6I~
    ULONG ucs,opt;                                                 //~v5i5R~
//******************                                               //~v5i5I~
    dbcschk=((Popt&UUD_DBCS) && udbcschkcp());                     //~v5i5R~
    opt=UCVUCS_LE;                                                 //~v5i5I~
    len=Pprintlen;                                                 //~v5i5I~
    pc=Pinp;                                                       //~v5i5I~
    for (jj=0;jj<3;jj++)	//conv from top, from 2nd, back to top because more ucs detected//~v5i5I~
    {                                                              //~v5i5I~
    	pco=Pout;                                                  //~v5i5I~
        ucsctr=0;                                                  //~v5i5I~
        padsw=0;                                                   //~v5i5I~
	    if (len & 0x01)	//odd number                               //~v5i5I~
    		if (Pinplen>Pprintlen)                                 //~v5i5I~
            {                                                      //~v5i5I~
        		len++;                                             //~v5i5I~
                padsw=1;                                           //~v5i5I~
            }                                                      //~v5i5I~
        for (ii=len;ii>1;ii-=2,pc+=2)                              //~v5i5R~
        {                                                          //~v5i5I~
            ucs=(ULONG)(*pc+(*(pc+1)<<8));   //little endian       //~v5i5R~
//          sjis=uccvucs2sjis(opt,ucs);                            //~v5i5I~//~v6BkR~
            sjis=uccvucs2sjis(opt,(UWUCS)ucs);                     //~v6BkI~
            if (sjis==UCVERRUCS)    //err                          //~v5i5I~
            {                                                      //~v5i5I~
                *pco++=errch;                                      //~v5i5I~
            }                                                      //~v5i5I~
            else                                                   //~v5i5I~
            if (dbcschk && (sjis & 0xff00))  //dbcs                //~v5i5I~
            {                                                      //~v5i5I~
                *pco++=(UCHAR)(sjis>>8);                           //~v5i5R~
                *pco++=(UCHAR)(sjis & 0xff);                       //~v5i5I~
                ucsctr++;                                          //~v5i5I~
            }                                                      //~v5i5I~
            else                                                   //~v5i5I~
            {                                                      //~v5i5I~
                if (sjis>=' ' && sjis<0x7f)                        //~v5i5I~
                {                                                  //~v5i5I~
	                ucsctr++;                                      //~v5i5I~
                    *pco++=(UCHAR)sjis;                            //~v5i5I~
                }                                                  //~v5i5I~
                else                                               //~v5i5I~
                    *pco++=errch;                                  //~v5i5I~
            }                                                      //~v5i5I~
        }                                                          //~v5i5I~
        if (ii && !padsw)                                          //~v5i5I~
        	*pco++=errch;                                          //~v5i5I~
//		outlen=(int)((ULONG)pco-(ULONG)Pout);                      //~v5i5R~//~v6hhR~
		outlen=(int)((ULPTR)pco-(ULPTR)Pout);                      //~v6hhI~
        if (maxoutlen<outlen)                                      //~v5i5I~
        	maxoutlen=outlen;                                      //~v5i5I~
        if (Popt & UUD_NORETRY)	// 	0x02		//try from top byte only//~v5i5I~
        	break;                                                 //~v5i5I~
        if (!jj)	//1st loop                                     //~v5i5I~
        {                                                          //~v5i5I~
	        ucsctr1=ucsctr;		//save of 1st loop                 //~v5i5I~
    	    pc=Pinp+1;                                             //~v5i5I~
        	len=Pprintlen-1;                                       //~v5i5I~
        }                                                          //~v5i5I~
        else                                                       //~v5i5I~
        if (jj==1)	//2nd loop                                     //~v5i5I~
        {                                                          //~v5i5I~
	    	if (ucsctr>=ucsctr1)	//2nd loop detected more ucs code than 1st loop//~v5i5I~
        		break;                                             //~v5i5I~
    		len=Pprintlen;                                         //~v5i5I~
    		pc=Pinp;                                               //~v5i5I~
        }                                                          //~v5i5I~
    }                                                              //~v5i5I~
    if (maxoutlen>outlen)                                          //~v5i5I~
    	memset(Pout+outlen,' ',(UINT)(maxoutlen-outlen));	//clear longer retry//~v5i5I~
	return outlen;                                                 //~v5i5R~
}//uucsdump                                                        //~v5i5I~
//*******************************************************          //~v163I~
//*ub2x                                                            //~v163I~
//* binary to hex degit                                            //~v163I~
//* parm1 :option    0:upper case,1:lower case output              //~v163I~
//* parm2 :outbuff                                                 //~v163I~
//* parm3 :source                                                  //~v163I~
//* parm4 :len                                                     //~v163I~
//* return:0                                                       //~v163I~
//******************************************************           //~v163I~
int ub2x(int Popt,UCHAR *Pout,void *Pinp,int Plen)                 //~v163R~
{                                                                  //~v163I~
static UCHAR Sucase[17]="0123456789ABCDEF";                        //~v59eR~
static UCHAR Slcase[17]="0123456789abcdef";                        //~v59eR~
	UCHAR *pce,*pc;                                                //~v163R~
    int ch,chh,chl,lsw;                                            //~v163R~
//******************                                               //~v163I~
	lsw=Popt & UBX_LOWER;                                          //~v163I~
    for (pc=Pinp,pce=pc+Plen;pc<pce;pc++)                          //~v163R~
    {                                                              //~v163I~
    	ch=(int)*pc;                                               //~v163R~
        chh=(int)((UINT)ch>>4);                                           //~v59eR~
        chl=ch & 0x0f;                                             //~v163I~
        if (lsw)                                                   //~v163R~
        {                                                          //~v163I~
        	*Pout++=Slcase[chh];                                   //~v163M~
        	*Pout++=Slcase[chl];                                   //~v163M~
        }                                                          //~v163M~
        else                                                       //~v163M~
        {                                                          //~v163M~
        	*Pout++=Sucase[chh];                                   //~v163M~
        	*Pout++=Sucase[chl];                                   //~v163M~
        }                                                          //~v163M~
    }                                                              //~v163I~
	return 0;                                                      //~v163I~
}//uasciidump                                                      //~v163I~
//*******************************************************          //~v7c3I~
//*ub2xString                                                      //~v7c3I~
//* binary to hex degit for short string when inp top is not ascii //~v7c3R~
//* return:0                                                       //~v7c3I~
//******************************************************           //~v7c3I~
char *ub2xString(int Popt,void *Pinp,int Plen)                     //~v7c3R~
{                                                                  //~v7c3I~
#define UB2XS_MAXINPLEN 16                                         //~v7c3I~
	static char Sout[UB2XS_MAXINPLEN*2+4];                         //~v7c3R~
	int len,swOvf=0;                                               //~v7c3R~
//******************                                               //~v7c3I~
    if (UTF8ISASCII(*((char*)Pinp)))                               //~v7c3R~
        return (char*)Pinp;                                        //~v7c3I~
	if (Plen)                                                      //~v7c3I~
    	len=Plen;	                                               //~v7c3I~
    else                                                           //~v7c3I~
    	len=(int)strlen(Pinp);                                     //~v7c3I~
    if (len>UB2XS_MAXINPLEN)                                       //~v7c3I~
    {                                                              //~v7c3I~
	    len=UB2XS_MAXINPLEN;                                       //~v7c3R~
        swOvf=1;                                                   //~v7c3I~
    }                                                              //~v7c3I~
    *(Sout)='0';                                                   //~v7c3I~
    *(Sout+1)='x';                                                 //~v7c3I~
	ub2x(Popt,Sout+2,Pinp,len);                                    //~v7c3R~
    if (swOvf)                                                     //~v7c3I~
    {                                                              //~v7c3I~
		Sout[2+len*2]='>';                                         //+v7c3R~
		Sout[2+len*2+1]=0;                                         //~v7c3I~
    }                                                              //~v7c3I~
    else                                                           //~v7c3I~
		Sout[2+len*2]=0;                                           //~v7c3R~
	return Sout;                                                   //~v7c3I~
}//ub2xString                                                      //~v7c3I~
                                                                   //~v195I~
#ifdef FTPSUPP   //UNX or W32                                      //~v59eI~
#ifdef UNX                                                         //~v378M~
                                                                   //~v378M~
//*******************************************************          //~v378I~
//*file attr conv to char                                          //~v378I~
//* parm1: attribute                                               //~v378I~
//* parm2: output area(4 to max 6 byte)                            //~v378I~
//*        s:setuid,S:setuid+setgid,G:setgid,t:stickey             //~v378I~
//* parm3: option;x01:set last 0,x'02' set directory               //~v378I~
//* return:none                                                    //~v378I~
//*******************************************************          //~v378I~
void ueditfattr(ULONG Pattr,UCHAR *Pout,int Popt)                  //~v378M~
#else                                                              //~v59eI~
void ueditfattrunix(ULONG Pattr,UCHAR *Pout,int Popt)              //~v59eI~
#endif                                                             //~v59eI~
{                                                                  //~v378M~
    int mode;                                                      //~v378M~
#ifdef UNX                                                         //~v59eI~
    UCHAR attr;                                                    //~v50GI~
#endif                                                             //~v59eI~
    char filetype;                                                 //~v56sI~
//************************                                         //~v378M~
#ifdef UNX                                                         //~v59eI~
//  if (Popt & UEFA_MDOS)                                          //~v50GI~//~v6d7R~
    if (Popt & (UEFA_MDOS|UEFA_RWIN))                              //~v6d7I~
    {                                                              //~v50GI~
    	attr=(UCHAR)FILE_GETATTR(Pattr);                           //~v50GI~
		ueditfattr_mdos(attr,Pout,Popt);                           //~v50GI~
        return;                                                    //~v50GI~
    }                                                              //~v50GI~
#endif                                                             //~v59eI~
//  mode=FILE_GETMODE(Pattr);                                      //~v378M~//~v6BfR~
    mode=(int)FILE_GETMODE(Pattr);                                 //~v6BfI~
    Pout[0]=(UCHAR)('0'+((UINT)(mode & S_IRWXU)>>6));	//user     //~v59eR~
    Pout[1]=(UCHAR)('0'+((UINT)(mode & S_IRWXG)>>3));	//group    //~v59eR~
    Pout[2]=(UCHAR)('0'+((UINT)(mode & S_IRWXO))   );		//other//~v59eR~
//  filetype=ueditfattrspf(mode);                                  //~v56sI~//~v6BfR~
    filetype=ueditfattrspf((ULONG)mode);                           //~v6BfI~
  if (Popt & UEFA_UFMT) //@dsgt fmt                                //~v50QI~
  {                                                                //~v50QI~
//  if (S_ISLNK(mode))  //slink                                    //~v56sR~
    if (filetype=='l')  //slink                                    //~v56sI~
        Pout[3]='l';                                               //~v56sR~
    else                                                           //~v56sR~
//      if (S_ISDIR(mode))  //dir                                  //~v56sI~
	    if (filetype=='d')  //slink                                //~v56sI~
            Pout[3]='d';                                           //~v56sR~
        else                                                       //~v56sR~
            Pout[3]='-';                                           //~v56sR~
    if (mode & S_ISUID)     //setuid                               //~v50QR~
        Pout[4]='u';                                               //~v50QR~
    else                                                           //~v50QI~
        Pout[4]='-';                                               //~v50QR~
    if (mode & S_ISGID)     //setgid                               //~v50QR~
        Pout[5]='g';                                               //~v50QR~
    else                                                           //~v50QI~
        Pout[5]='-';                                               //~v50QR~
    if (mode & S_ISVTX)     //stickey                              //~v50QI~
        Pout[6]='t';                                               //~v50QI~
    else                                                           //~v50QI~
      if (filetype!='d' && filetype!='l')   //not dir and not slink//~v56sI~
        Pout[6]=filetype;                                          //~v56sI~
      else                                                         //~v56sI~
        Pout[6]='-';                                               //~v50QI~
    if (Popt & UEFA_SZ)                                            //~v50QI~
        Pout[7]=0;                                                 //~v50QI~
  }                                                                //~v50QI~
  else                                                             //~v50QI~
  {                                                                //~v50QI~
    if (mode & S_ISUID)     //setuid                               //~v378R~
        if (mode & S_ISGID)                                        //~v378R~
            Pout[3]='S';                                           //~v378R~
        else                                                       //~v378R~
//          Pout[3]='s';    //"S" for s+x                          //~v50RR~
            Pout[3]='u';    //setuid                               //~v50RR~
    else                                                           //~v378R~
        if (mode & S_ISGID)                                        //~v378I~
//          Pout[3]='G';                                           //~v50RR~
            Pout[3]='g';    //setgid                               //~v50RR~
        else                                                       //~v378I~
            Pout[3]='-';    //"S" for s+x                          //~v378I~
    if (mode & S_ISVTX)//setgid;stickey is no mean for normal file //~v378R~
        Pout[4]='t';                                               //~v378R~
    else                                                           //~v378R~
      if (filetype!='d' && filetype!='l')   //not dir and not slink//~v56sI~
        Pout[4]=filetype;                                          //~v56sI~
      else                                                         //~v56sI~
        Pout[4]='-';                                               //~v378R~
//*                                                                //~v378R~
	if (Popt & UEFA_DIR)	//chk dir attr                         //~v378M~
    {                                                              //~v378M~
//      if (S_ISLNK(mode))  //slink                                //~v56sR~
        if (filetype=='l')  //slink                                //~v56sI~
    		if (Pattr & FILE_DIRECTORY)  //dir                     //~v50EI~
//          	Pout[5]='D';        //symbolink and directory      //~v50RR~
            	Pout[5]='L';        //symbolink and directory      //~v50RI~
        	else                                                   //~v50EI~
//          	Pout[5]='s';        //symbolic link                //~v50RR~
            	Pout[5]='l';        //symbolic link                //~v50RR~
        else                                                       //~v50EI~
//  	if (S_ISDIR(mode))  //dir                                  //~v56sR~
    	if (filetype=='d')  //dir                                  //~v56sI~
            Pout[5]='d';                                           //~v378M~
        else                                                       //~v378M~
            Pout[5]='-';                                           //~v378M~
		if (Popt & UEFA_SZ)                                        //~v378M~
            Pout[6]=0;                                             //~v378M~
	}                                                              //~v378M~
    else                                                           //~v378M~
    {                                                              //~v378M~
		if (Popt & UEFA_SZ)                                        //~v378M~
            Pout[5]=0;                                             //~v378M~
	}                                                              //~v378M~
  }//xe fmt                                                        //~v50QI~
	return;                                                        //~v378M~
}//ueditfattr                                                      //~v378M~
//*******************************************************          //~v56sI~
//*file attr conv to char for special file                         //~v56sI~
//* parm1: attribute                                               //~v56sI~
//* return:char id                                                 //~v56sI~
//*******************************************************          //~v56sI~
char ueditfattrspf(ULONG Pmode)                                    //~v56sI~
{                                                                  //~v56sI~
	char filetype;                                                 //~v56sI~
//*************                                                    //~v56sI~
    if (S_ISLNK(Pmode))  //slink                                   //~v56sI~
        filetype='l';                                              //~v56sI~
    else                                                           //~v56sI~
    if (S_ISDIR(Pmode))  //dir                                     //~v56sI~
        filetype='d';                                              //~v56sI~
    else                                                           //~v56sI~
    if (S_ISCHR(Pmode))  //char device                             //~v56sI~
        filetype='c';                                              //~v56sI~
    else                                                           //~v56sI~
    if (S_ISBLK(Pmode))  //blk  device                             //~v56sI~
        filetype='b';                                              //~v56sI~
    else                                                           //~v56sI~
    if (S_ISFIFO(Pmode))  //pipe  device                           //~v56sI~
        filetype='p';                                              //~v56sI~
    else                                                           //~v56sI~
    if (S_ISSOCK(Pmode))  //socket device                          //~v56sI~
        filetype='s';                                              //~v56sI~
    else                                                           //~v56sI~
        filetype='-';                                              //~v56sI~
    return filetype;                                               //~v56sI~
}//ueditfattrspf                                                   //~v56sI~
#endif  //FTPSUPP                                                  //~v59eI~
//*******************************************************          //~v195I~
//*file attr conv to char                                          //~v195I~
//* parm1: attribute                                               //~v195I~
//* parm2: output area(4 or 6 byte)                                //~v195I~
//* parm3: option;x01:set last 0,x'02' set directory               //~v195R~
//* return:none                                                    //~v195I~
//*******************************************************          //~v195I~
#ifdef UNX                                                         //~v59eI~
void ueditfattr_mdos(UCHAR Pattr,UCHAR *Pout,int Popt)             //~v50GM~
#else   //!UNX                                                     //~v50GI~
//void ueditfattr(UCHAR Pattr,UCHAR *Pout,int Popt)                //~v59eR~
void ueditfattr(ULONG Pattr,UCHAR *Pout,int Popt)                  //~v59eI~
#endif                                                             //~v50GI~
{                                                                  //~v195I~
//************************                                         //~v195I~
#ifdef UNX                                                         //~v59eI~
#else                                                              //~v59eI~
  #ifdef FTPSUPP                                                   //~v59eI~
	if (Pattr & FILE_REMOTE)	//ftp file                         //~v59eI~
    {                                                              //~v59eI~
      if (!(Popt & UEFA_RWIN))	//remote is not windows            //~v6d7I~
      {                                                            //~v6d7I~
		ueditfattrunix(Pattr,Pout,Popt);                           //~v59eR~
        return;                                                    //~v59eI~
      }                                                            //~v6d7I~
    }                                                              //~v59eI~
  #endif                                                           //~v59eI~
#endif                                                             //~v59eI~
 	if (UCBITCHK(Pattr,FILE_ARCHIVED))                             //~v195I~
       	Pout[0]='A';                                               //~v195I~
    else                                                           //~v195I~
       	Pout[0]='-';                                               //~v195I~
    if (UCBITCHK(Pattr,FILE_SYSTEM))                               //~v195I~
       	Pout[1]='S';                                               //~v195I~
    else                                                           //~v195I~
       	Pout[1]='-';                                               //~v195I~
    if (UCBITCHK(Pattr,FILE_HIDDEN))                               //~v195I~
       	Pout[2]='H';                                               //~v195I~
    else                                                           //~v195I~
       	Pout[2]='-';                                               //~v195I~
    if (UCBITCHK(Pattr,FILE_READONLY))                             //~v195I~
       	Pout[3]='R';                                               //~v195I~
    else                                                           //~v195I~
       	Pout[3]='-';                                               //~v195I~
	if (Popt & UEFA_DIR)	//chk dir attr                         //~v195I~
    {                                                              //~v195I~
        if (UCBITCHK(Pattr,FILE_DIRECTORY))                        //~v195R~
            Pout[4]='D';                                           //~v195I~
        else                                                       //~v195I~
            Pout[4]='-';                                           //~v195I~
		if (Popt & UEFA_SZ)                                        //~v195I~
            Pout[5]=0;                                             //~v195I~
	}                                                              //~v195I~
    else                                                           //~v195I~
    {                                                              //~v195I~
		if (Popt & UEFA_SZ)                                        //~v195I~
            Pout[4]=0;                                             //~v195I~
	}                                                              //~v195I~
	return;                                                        //~v195I~
}//ueditfattr                                                      //~v195I~
//#endif //!UNX                                                    //~v50GR~
//********************************************************************//~v195I~
//* hex line edit and print	for xda                                //~v6x5R~
//*   input:                                                       //~v195I~
//*     p1 : XDUMPLINEPRM                                          //~v195I~
//*   output:                                                      //~v195I~
//*     buff or file                                               //~v195I~
//********************************************************************//~v195I~
int uxdumpline(PXDUMPLINEPRM Ppxdlp)                               //~v195I~
{                                                                  //~v195I~
#define LINEWIDTH  256                                             //~v195I~
#if defined(ULIB64) || defined(ULIB64X)                            //~v6x5I~
#define LINENOSZ  16                                               //~v6x5I~
#else                                                              //~v6x5I~
#define LINENOSZ   8                                               //~v195I~
#endif                                                             //~v6x5I~
#define LINENOSZ2  (8+10)                                          //~v256I~
                                                                   //~v195I~
void xdlputs(UCHAR *Pdata,FILE* Pfh,UCHAR **Pppout);               //~v207R~
                                                                   //~v195I~
static  XDUMPLINEPRM  Sxdlp;                                       //~v207I~
static  UCHAR Sdumpline[LINEWIDTH];                                //~v207R~
static  UCHAR Ssameline[LINEWIDTH];                                //~v207R~
static  UCHAR Ssamechksv[32];                                      //~v195I~
//static	ULONG Ssamestart;                                      //~v6x5R~
static	ULPTR Ssamestart;                                          //~v6x5I~
static	int   Sboundary,Sdumpwidth,Shexpos,Scharpos,Slowersw,Sdbcssw;//~v207R~
static	int   Sucspos;                                             //~v5i5I~
static	int   Slinenosz;                                           //~v256I~
#if defined(ULIB64) || defined(ULIB64X)                            //~v6x5I~
static  UCHAR Ssameedit[]="%016" FILESZ_EDIT "X to %016" FILESZ_EDIT "X is same as above\n";//~v6x5R~
static  UCHAR Soffsedit[]="%016" FILESZ_EDIT "X";                  //~v6x5R~
#else                                                              //~v6x5I~
static  UCHAR Ssameedit[]="%08lx to %08lx is same as above\n";     //~v207R~
static  UCHAR Soffsedit[]="%08lx";                                 //~v207I~
#endif                                                             //~v6x5I~
static  UCHAR Sdosedit[]=" %04x:%04x";                             //~v256I~
        UCHAR xdumpwk[LINEWIDTH],*pxdumpwk;      //dump print line v6.7a//~v195R~
//		ULONG offset,reslen;                                       //~v207R~//~v6hhR~
  		ULPTR offset,reslen;                                       //~v6hhI~
//      ULONG vaddr;                                               //~v216I~//~v6hhR~
        ULPTR vaddr;                                               //~v6hhI~
	    UCHAR *pchexd,*inpdata,*outdata;                           //~v195R~
		int ii,opt,line1sw;                                        //~v207R~
		int wlen,linewidth,ilen;                                   //~v207R~
        USHORT dosseg,dossegr;                                     //~v256R~
//******************                                               //~v195I~
	opt=Ppxdlp->XDLPopt;                                           //~v195I~
//  if (vaddr==(ULONG)-1)                                          //~v217R~
//      vaddr=0;                                                   //~v217R~
//init process                                                     //~v195I~
	if (!(opt & XDLP_2ND))				//printdump sub first sw   //~v195I~
	{                                                              //~v195I~
		if (UCBITCHK(Ppxdlp->XDLPopt,XDLP_DOSSEG))                 //~v256I~
        	Slinenosz=LINENOSZ2;	//with seg:off                 //~v256I~
        else                                                       //~v256I~
        	Slinenosz=LINENOSZ;                                    //~v256I~
		Ppxdlp->XDLPopt=(UCHAR)(Ppxdlp->XDLPopt|XDLP_2ND); 			//printdump sub first sw//~v207R~
        memcpy(&Sxdlp,Ppxdlp,sizeof(Sxdlp));                       //~v207I~
        memset(Sdumpline,' ',sizeof(Sdumpline));                   //~v195R~
        memset(Ssameline,' ',sizeof(Ssameline));                   //~v195R~
        Ssamestart=0;                                              //~v207I~
//	    vaddr=(ULONG)Sxdlp.XDLPvirtual;                            //~v217I~//~v6hhR~
	    vaddr=(ULPTR)Sxdlp.XDLPvirtual;                            //~v6hhI~
        if (opt & XDLP_32)              //printdump sub first sw   //~v195I~
        {                                                          //~v195I~
            Sdumpwidth=32;                                         //~v195I~
//          Sboundary=(int)((ULONG)(Sxdlp.XDLPvirtual) & 0x1f);    //~v216R~
            Sboundary=(int)(vaddr & 0x1f);                         //~v216I~
//  		Shexpos=LINENOSZ+1+Sxdlp.XDLPhexpos;                   //~v256R~
    		Shexpos=Slinenosz+1+Sxdlp.XDLPhexpos;                  //~v256I~
			Scharpos=Shexpos+4*9-1+4+4*9-1+Sxdlp.XDLPcharpos+1;    //~v207R~
        }                                                          //~v195I~
        else                                                       //~v195I~
        {                                                          //~v195I~
            Sdumpwidth=16;                                         //~v195I~
//          Sboundary=(int)((ULONG)(Sxdlp.XDLPvirtual) & 0x0f);    //~v216R~
            Sboundary=(int)(vaddr & 0x0f);                         //~v216I~
//			Shexpos=LINENOSZ+1+Sxdlp.XDLPhexpos-1;                 //~v256R~
  			Shexpos=Slinenosz+1+Sxdlp.XDLPhexpos-1;                //~v256I~
			Scharpos=Shexpos+16*3+Sxdlp.XDLPcharpos+1;             //~v207R~
        }                                                          //~v195I~
        if (!Sxdlp.XDLPdelm2)                                      //~v222R~
            Scharpos--;                                            //~v222I~
//  	*(Sdumpline+LINENOSZ)=Sxdlp.XDLPdelm1;                     //~v256R~
    	*(Sdumpline+Slinenosz)=Sxdlp.XDLPdelm1;                    //~v256I~
	if (Sxdlp.XDLPdelm2)                                           //~v222I~
		*(Sdumpline+Scharpos-1)=Sxdlp.XDLPdelm2;                   //~v207R~
        linewidth=Scharpos+Sdumpwidth;                             //~v207R~
	if (Sxdlp.XDLPdelm2)                                           //~v222I~
		*(Sdumpline+linewidth++)=Sxdlp.XDLPdelm2;                  //~v207R~
	if ((Sxdlp.XDLPopt & XDLP_UCS))		//ucs conversion print req //~v5i5I~
    {                                                              //~v5i5I~
    	Sucspos=linewidth+XDLP_UCSSPACE;                           //~v5i5I~
    	linewidth+=XDLP_UCSSPACE+(Sdumpwidth+2);                   //~v5i5R~
    }                                                              //~v5i5I~
		*(Sdumpline+linewidth++)='\n';                             //~v207R~
		*(Sdumpline+linewidth)=0;                                  //~v207R~
        line1sw=1;                                                 //~v195I~
		if (Sxdlp.XDLPopt & XDLP_UPPER)				//printdump sub first sw//~v207I~
        {                                                          //~v207I~
#if defined(ULIB64) || defined(ULIB64X)                            //~v6x5I~
#else                                                              //~v6x5I~
        	Ssameedit[4]='X';                                      //~v207I~
        	Ssameedit[13]='X';                                     //~v207I~
        	Soffsedit[4]='X';                                      //~v207I~
#endif                                                             //~v6x5I~
        	Sdosedit[4]='X';                                       //~v256R~
        	Sdosedit[9]='X';                                       //~v256R~
            Slowersw=UBX_LOWER*0;                                  //~v207R~
        }                                                          //~v207I~
        else                                                       //~v207I~
        {                                                          //~v207I~
#if defined(ULIB64) || defined(ULIB64X)                            //~v6x5I~
#else                                                              //~v6x5I~
        	Ssameedit[4]='x';                                      //~v207I~
        	Ssameedit[13]='x';                                     //~v207I~
        	Soffsedit[4]='x';                                      //~v207I~
#endif                                                             //~v6x5I~
        	Sdosedit[4]='x';                                       //~v256R~
        	Sdosedit[9]='x';                                       //~v256R~
            Slowersw=UBX_LOWER;                                    //~v207I~
		}	                                                       //~v207I~
		if (Sxdlp.XDLPopt & XDLP_DBCS)				//printdump sub first sw//~v207I~
    		Sdbcssw=1;                                             //~v207I~
    	else                                                       //~v207I~
    		Sdbcssw=0;                                             //~v207I~
	}                                                              //~v195I~
    else	                                                       //~v195I~
        line1sw=0;                                                 //~v195I~
                                                                   //~v195I~
//*                                                                //~v195I~
	reslen=Ppxdlp->XDLPlen;                                        //~v195I~
//  offset=(ULONG)Ppxdlp->XDLPvirtual;                             //~v216R~
//  offset=(ULONG)Sxdlp.XDLPvirtual;                               //~v217R~//~v6hhR~
    offset=(ULPTR)Sxdlp.XDLPvirtual;                               //~v6hhI~
//  offset-=Sboundary;                                             //~v195R~//~v6BfR~
    offset-=(ULPTR)Sboundary;                                      //~v6BfI~
//printf("offset=%08lx,vaddr=%08lx,bound=%08lx\n",offset,vaddr,Sboundary);//~v217R~
	inpdata=Ppxdlp->XDLPinpbuff;                                   //~v195I~
	outdata=Ppxdlp->XDLPoutbuff;                                   //~v195R~
    dosseg=Ppxdlp->XDLPdosseg;                                     //~v256I~
    dossegr=Ppxdlp->XDLPdossegr;                                   //~v256I~
//                                                                 //~v195I~
	while (reslen)                                                 //~v195I~
    {                                                              //~v195I~
	    wlen=(int)min(reslen,(UINT)(Sdumpwidth-Sboundary));        //~v207R~
		for (;;)		//break by same chk                        //~v195I~
        {                                                          //~v195I~
//samechk                                                          //~v195I~
            if (wlen==Sdumpwidth                                   //~v195I~
            &&  !line1sw                                           //~v195R~
            &&  !memcmp(Ssamechksv,inpdata,(UINT)Sdumpwidth))      //~v195R~
            {                                                      //~v195I~
                if (!Ssamestart)                                   //~v195I~
                    Ssamestart=offset;                             //~v195I~
                break;      //next input width                     //~v195I~
            }                                                      //~v195I~
            else                                                   //~v195I~
            {                                                      //~v195I~
             	if (Ssamestart)                                    //~v195I~
                {                                                  //~v195I~
//  				sprintf(Ssameline+LINENOSZ+1,Ssameedit,        //~v256R~
    				sprintf(Ssameline+Slinenosz+1,Ssameedit,       //~v256I~
								Ssamestart,offset-1);              //~v207R~
                    xdlputs(Ssameline,Sxdlp.XDLPfh,&outdata);      //~v207R~
				}                                                  //~v195I~
                if (wlen==Sdumpwidth)                              //~v195I~
                	memcpy(Ssamechksv,inpdata,(UINT)Sdumpwidth);   //~v207R~
				Ssamestart=0;                                      //~v195I~
			}                                                      //~v195I~
//addr                                                             //~v195I~
            sprintf(xdumpwk,Soffsedit,offset);                     //~v207R~
#if defined(ULIB64) || defined(ULIB64X)                            //~v6x5I~
            memcpy(Sdumpline,xdumpwk,LINENOSZ);  //16 byte         //~v6x5I~
#else                                                              //~v6x5I~
            memcpy(Sdumpline,xdumpwk,8);                           //~v207I~
#endif                                                             //~v6x5I~
            if (Slinenosz!=LINENOSZ)	//DOS                      //~v256I~
            {                                                      //~v256I~
	            sprintf(xdumpwk,Sdosedit,(UINT)(dosseg+dossegr),offset-(((ULONG)dosseg)<<4));//~v256R~
   		        memcpy(Sdumpline+LINENOSZ,xdumpwk,10);             //~v256R~
            }                                                      //~v256I~
//char dump                                                        //~v195I~
            memset(Sdumpline+Scharpos,' ',(UINT)Sdumpwidth);       //~v207R~
            uasciidump(Sdbcssw,Sdumpline+Scharpos+Sboundary,inpdata,wlen);//~v207R~
			if ((Sxdlp.XDLPopt & XDLP_UCS))		//ucs conversion print req//~v5i5I~
            {                                                      //~v5i5I~
	            memset(Sdumpline+Sucspos,' ',(UINT)(Sdumpwidth+2));//~v5i5I~
	            uucsdump(Sdbcssw,Sdumpline+Sucspos,inpdata,wlen,(int)reslen);//~v5i5R~
            }                                                      //~v5i5I~
//hexdump                                                          //~v195I~
            ub2x(Slowersw,xdumpwk,inpdata,wlen);                   //~v207R~
            pxdumpwk=xdumpwk;                                      //~v195R~
            pchexd=Sdumpline+Shexpos;                              //~v207R~
            ilen=wlen;			//input len                        //~v207I~
            if (Sdumpwidth==16)                                    //~v195I~
                for (ii=0;ii<Sdumpwidth;ii++)           /* 1 line setup*///~v207R~
                {                                                  //~v195I~
                    if (ii==8)                                     //~v195I~
                        *pchexd++='-';                             //~v207R~
                    else                                           //~v207I~
                    	pchexd++;                                  //~v207R~
                    if (ii>=Sboundary && ilen) //for boundary v7.25a//~v207R~
                    {                                              //~v207I~
                        *pchexd++=*pxdumpwk++;                     //~v207R~
                        *pchexd++=*pxdumpwk++;                     //~v207I~
                        --ilen;                                    //~v207R~
					}                                              //~v207I~
                    else                                           //~v207I~
                    {                                              //~v207I~
                    	*pchexd++=' ';                             //~v207R~
                    	*pchexd++=' ';                             //~v207R~
					}                                              //~v207I~
                }                                                  //~v195I~
            else//32byte mode                                      //~v195I~
                for (ii=0;ii<Sdumpwidth;ii++)           /* 1 line setup*///~v207R~
                {                                                  //~v195I~
                	if (ii)                                        //~v207I~
                    {                                              //~v207I~
                    	if (!(ii & 3))                             //~v207R~
                        	pchexd++;                              //~v207R~
                    	if (!(ii & 15))                            //~v207R~
                        	pchexd++;                              //~v207R~
					}                                              //~v207I~
                    if (ii>=Sboundary && ilen) //for boundary v7.25a//~v207R~
                    {                                              //~v207I~
                        *pchexd++=*pxdumpwk++;                     //~v207R~
                        *pchexd++=*pxdumpwk++;                     //~v207I~
                        --ilen;                                    //~v207R~
					}                                              //~v207I~
                    else                                           //~v207I~
                    {                                              //~v207I~
                    	*pchexd++=' ';                             //~v207R~
                    	*pchexd++=' ';                             //~v207R~
					}                                              //~v207I~
                }                                                  //~v195I~
            xdlputs(Sdumpline,Sxdlp.XDLPfh,&outdata);              //~v207R~
            break;                                                 //~v207I~
        }//same chk break                                          //~v195I~
        inpdata+=wlen;                                             //~v195I~
//        offset+=wlen;                                            //~v226R~
//        offset+=(wlen+Sboundary);                                //~v226I~//~v6BfR~
          offset+=(ULPTR)(wlen+Sboundary);                         //~v6BfI~
//      reslen-=wlen;                                              //~v195I~//~v6BfR~
        reslen-=(ULPTR)wlen;                                       //~v6BfI~
        Sboundary=0;                                               //~v195R~
        line1sw=0;                                                 //~v207I~
	}                                                              //~v195I~
    if (Ssamestart                                                 //~v207R~
	&&  !(opt & XDLP_NOTLAST))                                     //~v207I~
    {                                                              //~v207I~
//      sprintf(Ssameline+LINENOSZ+1,Ssameedit,                    //~v256R~
        sprintf(Ssameline+Slinenosz+1,Ssameedit,                   //~v256I~
                    Ssamestart,offset-1);                          //~v207I~
        xdlputs(Ssameline,Sxdlp.XDLPfh,&outdata);                  //~v207I~
    }                                                              //~v207I~
    return 0;                                                      //~v195I~
}//uxdumpline                                                      //~v195I~
                                                                   //~v195I~
//********************************************************************//~v195I~
//*lineput                                                         //~v195I~
//*   input:                                                       //~v195I~
//*     p1 : data                                                  //~v195I~
//*     p2 : fh                                                    //~v195I~
//*   output:                                                      //~v195I~
//*     print output                                               //~v195I~
//********************************************************************//~v195I~
void xdlputs(UCHAR *Pdata,FILE* Pfh,UCHAR **Pppout)                //~v207R~
{                                                                  //~v195I~
    int rc;                                                        //~v207I~
//****************                                                 //~v195I~
	if (!Pfh)  			//no fileout                               //~v207I~
    {                                                              //~v207I~
     	strcpy(*Pppout,Pdata);                                     //~v207I~
        *Pppout+=(strlen(Pdata)+1);                                //~v207R~
        return;                                                    //~v207I~
	}                                                              //~v207I~
	rc=fputs(Pdata,Pfh);                                           //~v207R~
#ifdef DOS                                                         //~v207I~
  #ifdef DPMI					//DPMI version                     //~v207I~
    if (rc==-1)                                                    //~v207I~
  #else                       //not DPMI                           //~v207I~
    if (rc)                                                        //~v207I~
  #endif                      //DPMI or not                        //~v207I~
#else                                                              //~v207I~
    if (rc==-1)                                                    //~v207I~
#endif                                                             //~v207I~
	{                                                              //~v195I~
		uerrexit("HexDump output failed,rc=%d\n",0,                //~v195I~
				errno);                                            //~v195I~
	}                                                              //~v195I~
    return;	                                                       //~v195I~
}//xdlputs                                                         //~v195I~
//********************************************************************//~v5czI~
//*ugetdtparm                                                      //~v5czI~
//*   parse date/time parameter                                    //~v5czI~
//********************************************************************//~v5czI~
int ugetdtparm(UCHAR *Pdata,void /*FDATE*/ *Ppfdate,void /*FTIME*/ *Ppftime)//~v5czR~
{                                                                  //~v5czI~
    int len,rc;                                                    //~v5czI~
#define DT_MAX 20                                                  //~v5czI~
    char *pc,strdt[DT_MAX],strtm[DT_MAX];                          //~v5czI~
//*************************                                        //~v5czI~
    len=(int)strlen(Pdata);                                        //~v5czI~
    if (len>=DT_MAX)                                               //~v5czI~
    	return 4;                                                  //~v5czI~
    strcpy(strdt,Pdata);                                           //~v5czI~
	pc=strchr(strdt,'-');                                          //~v5czI~
    if (pc)                                                        //~v5czI~
    {                                                              //~v5czI~
    	*pc=0;                                                     //~v5czI~
    	strcpy(strtm,pc+1);                                        //~v5czI~
        rc=ugetdateparm(strdt,Ppfdate);                            //~v5czI~
        rc+=ugettimeparm(strtm,Ppftime);                           //~v5czI~
    }                                                              //~v5czI~
    else                                                           //~v5czI~
    {                                                              //~v5czI~
        rc=ugetdateparm(strdt,Ppfdate);                            //~v5czI~
        memset(Ppftime,0,sizeof(FTIME));                           //~v5czI~
    }                                                              //~v5czI~
    return rc;                                                     //~v5czI~
}//ugetdtparm                                                      //~v5czI~
//********************************************************************//~v5czI~
//*ugetdtparm                                                      //~v5czI~
//*   parse date/time parameter                                    //~v5czI~
//********************************************************************//~v5czI~
int ugetdateparm(UCHAR *Pdata,void /*FDATE*/ *Ppfdate)             //~v5czR~
{                                                                  //~v5czI~
    int ii,jj,kk;                                                  //~v5czI~
//*************************                                        //~v5czI~
    if (ueditgetftnum(Pdata,&ii,&jj,&kk))                          //~v5czR~
    	return 4;                                                  //~v5czI~
    if (ueditsetfdate(ii,jj,kk,Ppfdate))                           //~v5czR~
        return 4;                                                  //~v5czR~
    return 0;                                                      //~v5czR~
}//ugetdateparm                                                    //~v5czR~
//********************************************************************//~v5czI~
//*ugetdtparm                                                      //~v5czI~
//*   parse date/time parameter                                    //~v5czI~
//********************************************************************//~v5czI~
int ugettimeparm(UCHAR *Pdata,void /*FDATE*/ *Ppftime)             //~v5czR~
{                                                                  //~v5czI~
    int ii,jj,kk;                                                  //~v5czI~
//*************************                                        //~v5czI~
    if (ueditgetftnum(Pdata,&ii,&jj,&kk))                          //~v5czI~
        return 4;                                                  //~v5czI~
    if (ueditsetftime(ii,jj,kk,Ppftime))                           //~v5czI~
        return 4;                                                  //~v5czI~
    return 0;                                                      //~v5czI~
}//ugettimeparm                                                    //~v5czI~
//**********************************************************************//~v5czI~
//* get 3 int value                                                //~v5czI~
//*parm1:parm string                                               //~v5czI~
//*parm2:out int area1                                             //~v5czI~
//*parm3:out int area1                                             //~v5czI~
//*parm4:out int area1                                             //~v5czI~
//*return:rc;                                                      //~v5czI~
//**********************************************************************//~v5czI~
int ueditgetftnum(char *Pdata,int *Ppi1,int *Ppi2,int *Ppi3)       //~v5czI~
{                                                                  //~v5czI~
    int len,i1,i2,i3;                                              //~v5czI~
//****************                                                 //~v5czI~
    len=(int)strlen(Pdata);                                        //~v5czI~
    switch(len)                                                    //~v5czI~
    {                                                              //~v5czI~
    case 1:           //"0"                                        //~v5czI~
    	if (*Pdata!='0')                                           //~v5czI~
        	return 4;                                              //~v5czI~
        i1=i2=i3=0;                                                //~v5czI~
    	break;                                                     //~v5czI~
    case 4:           //"hhmm"                                     //~v5czI~
		if (unumlen(Pdata  ,0,4)!=4)                               //~v5czI~
	    	return 4;                                              //~v5czI~
		i1=uatoin(Pdata,  2);                                      //~v5czI~
		i2=uatoin(Pdata+2,2);                                      //~v5czI~
		i3=0;                                                      //~v5czI~
    	break;                                                     //~v5czI~
    case 5:           //"hh:mm"                                    //~v5czI~
		if (unumlen(Pdata  ,0,2)!=2                                //~v5czI~
		||  *(Pdata+2)!=':'                                        //~v5czI~
    	||  unumlen(Pdata+3,0,2)!=2)                               //~v5czI~
    		return 4;                                              //~v5czI~
		i1=uatoin(Pdata,  2);                                      //~v5czI~
		i2=uatoin(Pdata+3,2);                                      //~v5czI~
		i3=0;                                                      //~v5czI~
    	break;                                                     //~v5czI~
    case 6:           //"yymmdd"                                   //~v5czI~
		if (unumlen(Pdata  ,0,6)!=6)                               //~v5czI~
	    	return 4;                                              //~v5czI~
		i1=uatoin(Pdata,  2);                                      //~v5czI~
		i2=uatoin(Pdata+2,2);                                      //~v5czI~
		i3=uatoin(Pdata+4,2);                                      //~v5czI~
    	break;                                                     //~v5czI~
    case 8:           //"yy:mm:dd"                                 //~v5czI~
		if (unumlen(Pdata  ,0,2)!=2                                //~v5czI~
    	||  unumlen(Pdata+3,0,2)!=2                                //~v5czI~
    	||  unumlen(Pdata+6,0,2)!=2)                               //~v5czI~
    		return 4;                                              //~v5czI~
		i1=uatoin(Pdata,  2);                                      //~v5czI~
		i2=uatoin(Pdata+3,2);                                      //~v5czI~
		i3=uatoin(Pdata+6,2);                                      //~v5czI~
    	break;                                                     //~v5czI~
	default:                                                       //~v5czI~
    	return 4;                                                  //~v5czI~
	}                                                              //~v5czI~
	*Ppi1=i1;                                                      //~v5czI~
	*Ppi2=i2;                                                      //~v5czI~
	*Ppi3=i3;                                                      //~v5czI~
    return 0;                                                      //~v5czI~
}//getftnum                                                        //~v5czI~
//**********************************************************************//~v6D2I~
//* generate FDATE by bit shift to avoid conversion warning(alter its value)//~v6D2I~
//**********************************************************************//~v6D2I~
int ueditsetfdateUSHORT(int Popt,int Pyy,int Pmm,int Pdd,FDATE *Ppfdate)//~v6D2R~
{                                                                  //~v6D2I~
#ifdef AIX                                                         //~v6D2I~
    int    *pfdt;                                                  //~v6D2I~
#else                                                              //~v6D2I~
    USHORT *pfdt;                                                  //~v6D2R~
#endif                                                             //~v6D2I~
    int rc=0;                                                      //~v6D2I~
//**************                                                   //~v6D2I~
#ifdef AIX                                                         //~v6D2I~
    pfdt=(int*)(ULPTR)Ppfdate;                                     //~v6D2I~
    *pfdt=(int)MAKE_FDATE(Pyy,Pmm,Pdd);                            //~v6D2I~
#else                                                              //~v6D2I~
    pfdt=(USHORT*)(ULPTR)Ppfdate;                                  //~v6D2R~
    *pfdt=MAKE_FDATE(Pyy,Pmm,Pdd);                                 //~v6D2R~
#endif                                                             //~v6D2I~
    return rc;                                                     //~v6D2I~
}//ueditsetfdateUSHORT                                             //~v6D2R~
//**********************************************************************//~v5czI~
//* generate FDATE                                                 //~v5czI~
//*parm1:output ULONG(FDATE/FTIME) addr                            //~v5czI~
//*parm2:yy                                                        //~v5czI~
//*parm3:mm                                                        //~v5czI~
//*parm4:dd                                                        //~v5czI~
//*return:rc;                                                      //~v5czI~
//**********************************************************************//~v5czI~
int ueditsetfdate(int Pyy,int Pmm,int Pdd,void /*FDATE*/ *Ppfdate) //~v5czR~
{                                                                  //~v5czI~
//  FDATE fdt={0},*pfdt;                                           //~v6h9R~//~v6D2R~
    int rc=0;                                                      //~v5czI~
    int yy,mm=0,dd=0;                                              //~v6D2R~
//**************                                                   //~v5czI~
    if (Pyy<80)                                                    //~v5czI~
//      fdt.year =2000-1980+Pyy;                                   //~v5czI~//~v6BMR~
//      fdt.year =(USHORT)(2000-1980+Pyy);                         //~v6BMR~//~v6D2R~
        yy=2000-1980+Pyy;                                          //~v6D2I~
    else                                                           //~v5czI~
//      fdt.year =Pyy-80;                                          //~v5czI~//~v6BMR~
//      fdt.year =(USHORT)(Pyy-80);                                //~v6BMI~//~v6D2R~
        yy=Pyy-80;                                                 //~v6D2I~
    if (Pmm>=1 && Pmm<=12)                                         //~v5czI~
//  	fdt.month=Pmm;                                             //~v5czI~//~v6BMR~
//  	fdt.month=(USHORT)Pmm;                                     //~v6BMI~//~v6D2R~
    	mm=Pmm;                                                    //~v6D2I~
    else                                                           //~v5czI~
    	rc=4;                                                      //~v5czI~
    if (Pdd>=1 && Pdd<=31)                                         //~v5czI~
//  	fdt.day  =Pdd;                                             //~v5czI~//~v6BMR~
//  	fdt.day  =(USHORT)Pdd;                                     //~v6BMI~//~v6D2R~
    	dd=Pdd;                                                    //~v6D2I~
    else                                                           //~v5czI~
    	rc=4;                                                      //~v5czI~
//  pfdt=(FDATE*)(ULONG)Ppfdate;                                   //~v5czI~//~v6hhR~
//  pfdt=(FDATE*)(ULPTR)Ppfdate;                                   //~v6hhI~//~v6D2R~
//  pfdt=(FDATE*)(ULPTR)Ppfdate;                                   //~v6D2I~
//  *pfdt=fdt;                                                     //~v5czI~//~v6D2R~
    ueditsetfdateUSHORT(0,yy,mm,dd,Ppfdate);                       //~v6D2R~
    return rc;                                                     //~v5czI~
}//ueditsetfdate                                                   //~v5czI~
//**********************************************************************//~v6D2I~
//* generate FDATE by bit shift to avoid conversion warning(alter its value)//~v6D2I~
//**********************************************************************//~v6D2I~
int ueditsetftimeUSHORT(int Popt,int Phh,int Pmm,int Pss,FTIME *Ppftime)//~v6D2R~
{                                                                  //~v6D2I~
#ifdef AIX                                                         //~v6D2I~
    int    *pftm;                                                  //~v6D2I~
#else                                                              //~v6D2I~
    USHORT *pftm;                                                  //~v6D2I~
#endif                                                             //~v6D2I~
    int rc=0;                                                      //~v6D2I~
//**************                                                   //~v6D2I~
#ifdef AIX                                                         //~v6D2I~
    pftm=(int*)(ULPTR)Ppftime;                                     //~v6D2I~
    *pftm=(int)MAKE_FTIME(Phh,Pmm,Pss);                            //~v6D2I~
#else                                                              //~v6D2I~
    pftm=(USHORT*)(ULPTR)Ppftime;                                  //~v6D2R~
    *pftm=MAKE_FTIME(Phh,Pmm,Pss);                                 //~v6D2I~
#endif                                                             //~v6D2I~
    return rc;                                                     //~v6D2I~
}//ueditsetftimeUSHORT                                             //~v6D2I~
//**********************************************************************//~v5czI~
//* generate FTIME                                                 //~v5czI~
//*parm1:output ULONG(FDATE/FTIME) addr                            //~v5czI~
//*parm2:yy                                                        //~v5czI~
//*parm3:mm                                                        //~v5czI~
//*parm4:dd                                                        //~v5czI~
//*return:rc;                                                      //~v5czI~
//**********************************************************************//~v5czI~
int ueditsetftime(int Phh,int Pmm,int Pss,void /*FTIME*/ *Ppftime) //~v5czR~
{                                                                  //~v5czI~
//  FTIME ftm={0},*pftm;                                               //~v5czR~//~v6h7R~//~v6D2R~
    int rc=0;                                                      //~v5czI~
    int hh=0,mm=0,ss=0;                                            //~v6D2I~
//**************                                                   //~v5czI~
    if (Phh>=0 && Phh<=23)                                         //~v5czI~
//      ftm.hours  =Phh;                                           //~v5czI~//~v6BMR~
//      ftm.hours  =(USHORT)Phh;                                   //~v6BMI~//~v6D2R~
        hh=Phh;                                                    //~v6D2I~
    else                                                           //~v5czI~
    	rc=4;                                                      //~v5czI~
    if (Pmm>=0 && Pmm<=59)                                         //~v5czI~
//      ftm.minutes=Pmm;                                           //~v5czI~//~v6BMR~
//      ftm.minutes=(USHORT)Pmm;                                   //~v6BMI~//~v6D2R~
        mm=Pmm;                                                    //~v6D2I~
    else                                                           //~v5czI~
    	rc=4;                                                      //~v5czI~
    if (Pss>=0 && Pss<=59)                                         //~v5czI~
//      ftm.twosecs=Pss/2;                                         //~v5czI~//~v6BMR~
//      ftm.twosecs=(USHORT)(Pss/2);                               //~v6BMI~//~v6D2R~
        ss=Pss/2;                                                  //~v6D2I~
    else                                                           //~v5czI~
    	rc=4;                                                      //~v5czI~
//  pftm=(FTIME*)(ULONG)Ppftime;                                   //~v5czR~//~v6hhR~
//  pftm=(FTIME*)(ULPTR)Ppftime;                                   //~v6hhI~//~v6D2R~
//  *pftm=ftm;                                                     //~v5czI~//~v6D2R~
    ueditsetftimeUSHORT(0,hh,mm,ss,Ppftime);                       //~v6D2I~
    return rc;                                                     //~v5czI~
}//ueditsetftime                                                   //~v5czI~
//**********************************************************************//~v6BfI~
//* uxdumpstr                                                      //~v6BfI~
//* rc:4:buff overflow                                             //~v6BfI~
//**********************************************************************//~v6BfI~
int uxdumpstr(int Popt,char *Pinp,int Plen,char *Pout,int Pbuffsz,int *Ppoutlen)//~v6BfI~
{                                                                  //~v6BfI~
    int rc=0,outlen,reslen,buffsz;                                 //~v6BfR~
    char *pc,*pco,ch;                                              //~v6BfR~
//**************                                                   //~v6BfI~
    if (Popt & UXDSO_OUTSTRZ)                                      //~v6BfI~
        buffsz=Pbuffsz-1;                                          //~v6BfI~
    else                                                           //~v6BfI~
        buffsz=Pbuffsz;                                            //~v6BfI~
    for (pc=Pinp,reslen=Plen,pco=Pout,outlen=0;reslen>0;reslen--,outlen+=2,pco+=2)//~v6BfI~
    {                                                              //~v6BfI~
    	ch=*pc++;                                                  //~v6BfI~
        if (outlen+2>=buffsz)                                      //~v6BfR~
        {                                                          //~v6BfI~
        	rc=4;                                                  //~v6BfI~
        	break;                                                 //~v6BfI~
        }                                                          //~v6BfI~
        if (Popt & UXDSO_LOWER)                                    //~v6BfI~
            CH2HEXL(ch,pco);                                       //~v6BfI~
        else                                                       //~v6BfI~
            CH2HEXU(ch,pco);                                       //~v6BfI~
    }                                                              //~v6BfI~
    if (Ppoutlen)                                                  //~v6BfI~
    	*Ppoutlen=outlen;                                          //~v6BfI~
    if (Popt & UXDSO_OUTSTRZ)                                      //~v6BfR~
    	*pco=0;                                                    //~v6BfR~
    return rc;                                                     //~v6BfI~
}//ueditsetftime                                                   //~v6BfI~
//**********************************************************************//~v6T2I~
//* current tie to FDATE/FTIME                                     //~v6T2I~
//**********************************************************************//~v6T2I~
int ueditNowFileTime(int Popt,FDATE *Ppfdate,FTIME *Ppftime)       //~v6T2I~
{                                                                  //~v6T2I~
    ULONG uldttm[2];                                               //~v6T2I~
    UINT dt,tm;                                                    //~v6T2I~
    int yy,yy2,mm,dd,hh,mn,ss;                                     //~v6T2R~
//**************                                                   //~v6T2I~
    utimeedit((UCHAR*)(ULPTR)UET_ILONG,uldttm); //each int byte YYyymmdd+hhmmssth//~v6T2I~
    dt=(UINT)uldttm[0];                                            //~v6T2I~
    yy=(int)((dt>>24)*100+((dt>>16)& 255));                        //~v6T2R~
    mm=(yy>>8)&255;                                                //~v6T2I~
    dd=yy&255;                                                     //~v6T2I~
  	if (yy>1980)                                                   //~v6T2I~
    	yy2=yy-1980;                                               //~v6T2I~
  	else                                                           //~v6T2I~
    	yy2=0;                                                     //~v6T2I~
    ueditsetfdateUSHORT(0,yy2,mm,dd,Ppfdate);                      //~v6T2R~
    tm=(UINT)uldttm[1];                                            //~v6T2I~
    hh=(int)(tm>>24);                                              //~v6T2R~
    mn=(tm>>16)&255;                                               //~v6T2I~
    ss=(tm>>8)&255;                                                //~v6T2I~
    ueditsetftimeUSHORT(0,hh,mn,ss,Ppftime);                       //~v6T2R~
    return 0;                                                      //~v6T2I~
}//ueditsetftime                                                   //~v6T2I~
//**********************************************************************//~v6XcI~
//* rep escseq such as \a, \x ...                                  //~v6XcI~
//* \x should be len=2                                             //~v6XcI~
//* rc:0 no esc,1:done,4:hex err,8 fmt err,16:buff ovf             //~v6XcR~
//**********************************************************************//~v6XcI~
int ueditescrep(int Popt,char *Pin,int Plen,char *Pout,int Pbuffsz,int *Ppoutlen)//~v6XcI~
{                                                                  //~v6XcI~
static char Sescseqid[]="XABTNVFR\"\'\\";                                //~v09LR~//~v6XcR~
static char Sescseqtbl[]  ="x\a\b\t\n\v\f\r\"\'\\";                      //~v09LR~//~v6XcR~
    char *pc,*pci,*pco;                                                      //~v09NR~//~v6XcR~
    int ii,reslen,hexlen,outlen;                                                        //~v0apI~//~v6XcR~
    int rc=0;                                                        //~v09NI~//~v6XcR~
    char wk[32];                                                   //~v6XcR~
//*********************************                                //~v09LI~//~v6XcI~
 	if (!*Pin)		//null                                         //~v433I~//~v6XcI~
		return 0;                                                  //~v433I~//~v6XcI~
    for(pci=Pin,pco=Pout,reslen=Pbuffsz,ii=0;ii<Plen;ii++,pci++)   //~v6XcR~
    {                                                              //~v6XcI~
    	if (reslen<=0)                                             //~v6XcI~
        {                                                          //~v6XcI~
        	rc=16;                                                 //~v6XcR~
            break;                                                 //~v6XcI~
        }                                                          //~v6XcI~
 		if (*pci!='\\')                                            //~v6XcI~
        {                                                          //~v6XcI~
        	*pco++=*pci;                                           //~v6XcI~
            reslen--;                                              //~v6XcI~
			continue;                                              //~v6XcI~
        }                                                          //~v6XcI~
        if (ii+1>=Plen)                                            //~v6XcI~
        {                                                          //~v6XcI~
            rc=8;                                                  //~v6XcI~
            break;                                                 //~v6XcI~
        }                                                          //~v6XcI~
        pci++;                                                     //~v6XcI~
        ii++;                                                      //~v6XcI~
 		if (!(pc=strchr(Sescseqid,toupper(*pci))))                 //~v6XcI~
        {                                                          //~v6XcI~
            rc=8;                                                  //~v6XcI~
            break;                                                 //~v6XcI~
        }                                                          //~v6XcI~
    	if (*pc=='X')	//x or X                                       //~v09LR~//~v6XcI~
    	{                                                              //~v09LI~//~v6XcI~
    		if ((hexlen=ugethex(pci+1,wk,2))<0)	//rc is hex len//~v0apI~//~v6XcR~
        	{                                                          //~v09NI~//~v6XcI~
            	UTRACED("pci",pci+1,2);                            //~v6XcR~
            	if (Popt & UEERO_MSG)                              //~v6XcI~
    				uerrmsg("Hex notation error(%s)",                      //~vbc3I~//~v6XcR~
							"ヘキサ指定エラー(%s)",                        //~v09NI~//~v6XcR~
							Pin);                                          //~v09NI~//~v6XcR~
                rc=4;                                              //~v6XcI~
        		break;                                             //~v6XcI~
			}                                                          //~v09NI~//~v6XcI~
            UTRACED("wk",wk,hexlen);                               //~v6XcR~
            pci+=hexlen*2;                                         //~v6XcR~
            ii+=hexlen*2;                                          //~v6XcR~
            if (Popt & UEERO_NULLERR)                              //~v6XcI~
            {                                                      //~v6XcI~
            	if (memchr(wk,0,(size_t)hexlen))                   //~v6XcR~
                {                                                  //~v6XcI~
	            	if (Popt & UEERO_MSG)                          //~v6XcI~
    					uerrmsg("Hex notation error(%s), containing NULL",//~v6XcI~
								"ヘキサ指定エラー, NULL が含まれています(%s)",//~v6XcI~
								Pin);                              //~v6XcI~
                	rc=4;                                          //~v6XcR~
        			break;                                         //~v6XcR~
                }                                                  //~v6XcI~
            }                                                      //~v6XcI~
            if (hexlen>reslen)                                     //~v6XcI~
            {                                                      //~v6XcI~
	        	rc=8;                                              //~v6XcI~
    	        break;                                             //~v6XcI~
            }                                                      //~v6XcI~
            memcpy(pco,wk,(size_t)hexlen);                         //~v6XcR~
            pco+=hexlen;                                           //~v6XcI~
            reslen-=hexlen;                                        //~v6XcI~
            rc=1;                                                  //~v6XcI~
    	}                                                              //~v09LI~//~v6XcR~
    	else                                                           //~v09LI~//~v6XcR~
    	{                                                              //~v09LI~//~v6XcR~
        	*pco++=Sescseqtbl[PTRDIFF(pc,Sescseqid)];              //~v6XcI~
            reslen--;                                              //~v6XcI~
        	rc=1;                                                      //~v09NI~//~v6XcR~
        }                                                          //~v6XcI~
	}                                                              //~v09LI~//~v6XcI~
    if (rc==8)                                                     //~v6XcI~
        if (Popt & UEERO_MSG)                                      //~v6XcI~
    		uerrmsg("EscapeSeq Format err(%s)",0,                  //~v6XcI~
							Pin);                                  //~v6XcI~
    outlen=PTRDIFF(pco,Pout);                                      //~v6XcR~
    *Ppoutlen=outlen;                                              //~v6XcI~
    UTRACED("inp",Pin,Plen);                                       //~v6XcI~
    UTRACED("out",Pout,outlen);                                    //~v6XcI~
    return rc;                                                     //~v09NR~//~v6XcI~
}//ueditescrep                                                     //~v6XcR~
