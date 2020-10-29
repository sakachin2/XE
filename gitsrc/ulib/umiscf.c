//CID://+v711R~:         update#=  127                             //~v711R~
//**************************************************
//*umiscf.c
//*other miscellaneous function
//*  uchksum,uaddc                                                 //~v192R~
//**************************************************
//v711:201022 ftime deprecated                                     //~v711I~
//v6hq:120707 printf format "%n" disabled by default and assetion when debug mode//~v6hqM~
//v192:980905 add uchksum func
//**************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef UNX                                                         //~v711I~
	#include <sys/time.h>                                         //~v651I~//~v711R~
#endif                                                             //~v711I~
#include <sys/timeb.h>                                             //~v711I~
//*************************************************************
#ifdef DOS
#else
    #ifdef W32
    #else
	#endif
#endif
//*************************************************************
#include <ulib.h>
#include <umiscf.h>
//*******************************************************
//*******************************************************
//*uchksum
//* calc dword chksum considering boundary
//*   at beginning boundar 0 is padded on lower pos of ULONG
//*   at ending boundar 0 is padded on higer pos of ULONG
//*parm1:addr:pointer to data
//*parm2:offset:data start offset boundary
//*parm3:len:data len
//*parm4:prev value                                                //~v192I~
//*ret  :dword chksum value
//*******************************************************
unsigned long uchksum(unsigned char *Paddr,unsigned long Poffs,    //~v192R~
				unsigned long Plen,unsigned long Pprevchksum)      //~v192I~
{
	UCHAR *pc,wk[4];
	ULONG sum,len,lenw,offs,*ulp,osum;                             //~v192R~
//**********************
    sum=Pprevchksum;                                               //~v192I~
	len=Plen;
    pc=Paddr;
	if ((offs=Poffs&3)!=0)		//not DWORD boundary
	{
		memset(wk,0,4);			//clear ULONG
        if ((lenw=4-offs)>Plen)  //fill dword
        	lenw=Plen;
		memcpy(wk+offs,pc,(UINT)lenw);                             //~v192R~
    	osum=sum;                                                  //~v192I~
//      sum+=*(ULONG*)(void*)wk;                                   //~v192R~//~v6hqR~
        sum+=USTR2UL(wk);                                          //~v6hqI~
    	if (sum<osum)  		//carry set                            //~v192I~
        	sum++;                                                 //~v192I~
		len-=lenw;
		pc+=lenw;
	}
//*
    ulp=(ULONG*)(void*)pc;
    lenw=len/4;
    while(lenw)
    {
    	osum=sum;
        sum+=*ulp++;
    	if (sum<osum)  		//carry set
        	sum++;
        lenw--;                                                    //~v192I~
    }
//*
	if ((lenw=len&3)!=0)		//end is not DWORD boundary
	{
		memset(wk,0,4);			//clear ULONG
		memcpy(wk,ulp,(UINT)lenw);                                 //~v192R~
    	osum=sum;
//      sum+=*(ULONG*)(void*)wk;                                   //~v6hqR~
        sum+=USTR2UL(wk);                                          //~v6hqI~
    	if (sum<osum)  		//carry set
        	sum++;
	}
    return sum;
}//uchksum

//*******************************************************          //~v192I~
//*uaddc                                                           //~v192I~
//* add ulong then if carry on add 1                               //~v192I~
//*parm1:ulong1                                                    //~v192I~
//*parm2:ulong2                                                    //~v192I~
//*ret  :result                                                    //~v192I~
//*******************************************************          //~v192I~
unsigned long uaddc(unsigned long Pv1,unsigned long Pv2)           //~v192I~
{                                                                  //~v192I~
	ULONG sum;                                                     //~v192I~
//**********************                                           //~v192I~
    sum=Pv1+Pv2;                                                   //~v192I~
    if (sum<Pv1)  		//carry set                                //~v192I~
    	sum++;                                                     //~v192I~
    return sum;                                                    //~v192I~
}//uaddc                                                           //~v192I~
#ifdef VC10EXP                                                     //~v6hqM~
//**********************************************************       //~v6hqM~
//*default diable by security reason                               //~v6hqM~
//**********************************************************       //~v6hqM~
int uwin_enablecountoutput(int Penable)                            //~v6hqM~
{                                                                  //~v6hqM~
	return _set_printf_count_output(Penable);                      //~v6hqM~
}//uwin_enablecountoutput                                          //~v6hqM~
#endif                                                             //~v6hqM~
//**********************************************************       //~v711I~
//*ftime deprecated                                                //~v711I~
//**********************************************************       //~v711I~
int uftime(struct timeb * Ptb)                                     //~v711R~
{                                                                  //~0610I~//~v711I~
#ifdef W32                                                         //~v711I~
    ftime(Ptb);                                               //~v560I~//~v711R~
    return 0;                                                      //~v711I~
#else                                                              //~v711I~
	struct timezone tz;                                            //~v711I~
	struct timeval  tv;                                            //~v711I~
//*********************                                            //~v711I~
	if (gettimeofday(&tv,&tz)<0)                                   //~v711I~
    	return -1;                                                 //~v711I~
    Ptb->time=tv.tv_sec;                                           //~v711I~
    Ptb->millitm=(unsigned short)(tv.tv_usec/1000);                //~v711R~
    Ptb->timezone=(short)(tz.tz_minuteswest);                      //+v711R~
    Ptb->dstflag=(short)(tz.tz_dsttime);                           //+v711R~
    return 0;                                                      //~v711I~
#endif                                                             //~v711I~
}                                                                  //~0610I~//~v711I~
