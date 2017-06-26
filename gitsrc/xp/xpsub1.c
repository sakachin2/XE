//*CID://+v9a0R~:                             update#=   53;       //~v9a0R~
//***********************************************************
//* XPSUB1.C: subroutines                                          //~v827R~
//***********************************************************
//v9a0:160418 v9.33 LNX compiler warning                           //+v9a0I~
//v992:150529 v9.31 uerrmsg parm count err by xuerpck              //~v992I~
//v96i:130726 v9.25 add -EOLPRINT: option to identify eol of vfmt  //~v96iI~
//v96e:130724 v9.25 recfm=V(-Vvfmt) support                        //~v96eI~
//120611 v965 avoid C4701 warning(variable may not be uninitialized)//~v965I~
//071029 v92p (LNX)src pkg packaging err(xpw95s.h missing err)     //~v92pI~
//071024 v92n (LNX)support utf8 file(conv to locale)               //~v92nI~
//            /Y3 optio to control SS3(0x8f) for EUC               //~v92nI~
//030926 v91i (LNX) conv dbcs to euc from sjis(supported by uerr)  //~v91iR~
//030920 v91h (LNX) use english because linux is EUC(not SJIS)     //~v91hI~
//011209 v90m :support stdout output                               //~v90mI~
//010519 v907 :LINUX support                                       //~v907I~
//990918 v895 :move trt file option to /Kfxxxx from /Mmfxxxx       //~v895I~
//990918 v893 :supprt TRT by file                                  //~v893I~
//981006 v850 :display printed pageno when ESC cancel              //~v850I~
//981005 v847 :dbcsenvchk by ulib rtn because chk also codepage    //~v847I~
//980927 v844 :(WIN) /EW option(use Win32 API to use spool)        //~v844I~
//971221 v83a :2000 year consideration                             //~v83aI~
//971124 v834 :GCC version                                         //~v834I~
//971123 v827 :split xpsub1 from xrint.c
//***********************************************************      //~v765I~
//*************************************************************
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add
#ifdef UTF8SUPP                                                    //~v92nI~
	#include <locale.h>                                            //~v92nI~
#endif                                                             //~v92nI~
//*************************************************************

#ifdef DOS                           //v3.6a                    //~v743I~
	#include <dos.h>                     //v3.7a                   //~v827I~
	#include <bios.h>            		//av4.2                    //~v827I~
#else                                //v3.6a                    //~v743I~
                                                                //~v743I~
  #ifdef W32                                                       //~v826I~
  #else                                                            //~v826I~
	#define INCL_BASE                     //v1.3 add v3.7r         //~v827I~
	#include <os2.h>         //v1.3 add                            //~v827I~
  #endif                                                           //~v826I~
                                                                //~v743I~
#endif                               //v3.6a                    //~v743I~
                                                                //~v743I~
#include <ulib.h>	                                            //~v743M~
#include <ustring.h>                                               //~v768I~
#include <uerr.h>                                                  //~v801I~
#include <ufile.h>                                                 //~v807I~
#include <ufile5.h>                                                //~v96eI~
//#ifdef DPMI                 //DPMI version                       //~v847R~
	#include <udbcschk.h>                                          //~v834I~
//#else                       //not DPMI                           //~v847R~
//#endif                      //DPMI or not                        //~v847R~
#ifdef UNX                                                         //~v907I~
	#include <ukbd.h>                                              //~v907I~
	#include <ugcclib.h>                                           //~v907I~
#endif                                                             //~v907R~
#include <utrace.h>                                                //~v96eI~
//*********************************************************************
#include  "xp.h"                                                //~v74kI~
#ifdef W32                                                         //~v92pR~
#include  "xpw95s.h"                                               //~v827I~
#endif                                                             //~v92pR~
#include  "xpsub1.h"                                               //~v826I~
#ifdef W32                                                         //~v844I~
	#include  "xpwinp.h"                                           //~v844I~
#endif                                                             //~v844I~
//*********************************************************************//~v745I~
void escstopmsg2(int kbdinp);                                      //~v827I~
//*********************************************************************//~v827I~
extern int  dbcsenv;           //dbcs environment sw v4.9a v7.23r  //~v827I~
extern int  breakpage;         //in xppf.c,page no at ESC hit      //~v850I~
extern int  despagesw;       //descending page print sw            //~v850I~
extern int  despagecntsw;    //parm from despageout                //~v850I~
extern int  os;                                                    //~v850I~
extern int  hexdump;                                               //~v96iI~
extern char pgmid[];                                               //~v827I~
extern char ver[];                                                 //~v827I~
extern FILE *Gmsgfile;       //for print start msg                 //~v90mI~
//*********************************************************************
extern char *Gptrtfnm;     //code page tbl filename                //~v893M~
extern int  os2sw;			//v7.27a 0:dos,1:mvdm dos,2:os2        //~v827I~
extern int prntyp;	//printer type(default ibm5577/ibm5575 etc)    //~v844I~
static int readlineV;                                              //~v96eI~
static char SfilenameV[_MAX_PATH];                                 //~v96eI~
static int SswtolV;	//reading top of record                        //~v96iR~
//**********************************************************************//~v74jI~
//* date parm get                                               //~v74jI~
//**********************************************************************//~v74jI~
int getcondts(char *Pparm,int *Pcondcode,USHORT *Pconddate,USHORT *Pcondtime)//~v74jR~
{                                                               //~v74jI~
static char *cond[]={"EQ","NE","GT","GE","LT","LE"}; //date compare 940609a//~v74jM~
	char *pc,*cptr;                                             //~v74jI~
    int i;                                                      //~v74jI~
    int j;                                                         //~v766I~
    int yy;                                                        //~v83aI~
//********************                                          //~v74jI~
	pc=Pparm;	//upper case v5.0r                              //~v74jI~
//cond                                                          //~v74jI~
	for (i=0;i<6;i++)                                           //~v74jI~
		if (!memcmp(pc,cond[i],2))	//condition chk             //~v74jI~
			break;                                              //~v74jI~
	if (i==6)	                                                //~v74jI~
    	return 4;                                               //~v74jI~
	*Pcondcode=i+1;						//compare parm          //~v74jI~
//date                                                          //~v74jI~
	cptr=(pc+=2);	                                            //~v74jR~
	for (i=0;i<6;i++)                                           //~v74jI~
		if (!isdigit(*pc++))                                    //~v74jI~
			break;                                              //~v74jI~
	if (i!=6)	                                                //~v74jI~
    	return 4;                                               //~v74jI~
    yy=(*cptr-'0')*10+*(cptr+1)-'0';                               //~v83aI~
    if (yy>=80)                                                    //~v83aI~
        yy-=80;         //diff from 1980                           //~v83aI~
    else                                                           //~v83aI~
        yy+=20;         //diff from 2000(20=2000-1980)             //~v83aI~
//  *Pconddate=(USHORT)((((*cptr-'0')*10+*(cptr+1)-'0'-80)<<9)  //year from 1980 bit 0-6//~v83aR~
    *Pconddate=(USHORT)((yy<<9)  //year from 1980 bit 0-6          //~v83aI~
	          +(((*(cptr+2)-'0')*10+*(cptr+3)-'0')<<5)  //month bit 7-10//~v74jI~
	          +((*(cptr+4)-'0')*10+*(cptr+5)-'0'));	  //day bit 11-15 v7.0r//~v74jI~
//time                                                          //~v74jI~
	if (*(cptr=pc)==':')                                        //~v74jI~
		cptr++;                                                 //~v74jI~
	if (*cptr)                                                  //~v74jI~
	{	                                                        //~v74jI~
		pc=cptr;                                                //~v74jI~
	    for (i=0;i<4;i++)                                       //~v74jI~
		  	if (!isdigit(*pc++))                                //~v74jI~
		    	break;                                          //~v74jI~
	    if (i!=4)	                                            //~v74jI~
	    	return 4;                                           //~v74jI~
	    j=( ( (*cptr-'0')*10 + *(cptr+1)-'0' ) <<11 );  //hour  bit 0-4//~v766R~
	    *Pcondtime=(USHORT)(j+( ( (*(cptr+2)-'0')*10 + *(cptr+3)-'0' ) << 5 ) );  //month bit 5-10 v7.0r//~v766I~
	}                                                           //~v74jI~
//  printf ("\n %04x,%04x,%d\n",*Pconddate,*Pcondtime,*Pcondcode); //~v766R~
    return 0;                                                   //~v74jR~
}//getcondts                                                    //~v74jI~
                                                                //~v74jI~
//**********************************************************************
//* stop msg by Esc key v6.0a
//**********************************************************************
void escstopmsg(int kbdinp)
{
//*************************
	if ((kbdinp&255)==0x1b)				//ESC
	{
		if (dbcsenv)	//DBCS mode v4.9a
			printf("\n%s:%s(%c):Escキーにより中断されました\n",pgmid,ver,os);//v4.9a//~v850R~
		else			//SBCS mode v4.9a	
  			printf("\n%s:%s(%c):break by Esc\n",pgmid,ver,os);     //~v850R~
#ifdef W32                                                         //~v844I~
		if (prntyp==PRINTER_WIN)                                   //~v844R~
			win_endjob(4);//endjob by escape                       //~v844R~
#endif                                                             //~v844I~
		uexit(8);                                               //~v742R~
	}
	return;
}//escstopmsg

//**********************************************************************//~v808I~
//* stop msg by Esc key                                            //~v808I~
//**********************************************************************//~v808I~
void escstopmsg2(int kbdinp)                                       //~v808I~
{                                                                  //~v808I~
	int cpage;                                                     //~v850I~
    char pageedit[32];                                             //~v850I~
//*************************                                        //~v808I~
	if ((kbdinp&255)==0x1b)				//ESC                      //~v808I~
    {                                                              //~v850I~
        cpage=breakpage;                                           //~v850I~
		if (!phase2sw)	//phase2(print end)                        //~v850R~
        	cpage=0;                                               //~v850I~
        if (despagesw)      //in file write                        //~v850R~
        	cpage=0;                                               //~v850I~
		if (despagecntsw)  			//in writing from desp file    //~v850R~
        	sprintf(pageedit,"%d page from last",cpage);           //~v850R~
		else                                                       //~v850I~
        	sprintf(pageedit,"pageno=%d",cpage);                   //~v850R~
		if (dbcsenv)	//DBCS mode v4.9a                          //~v808I~
			printf("\n%s:%s:Escキー検知,頁の切目(%s)で終了します\n",//~v850R~
					pgmid,ver,pageedit);//v4.9a                    //~v850R~
		else			//SBCS mode v4.9a	                       //~v808I~
  			printf("\n%s:%s:Esc accepted,stop at page end.(%s)\n", //~v850R~
					pgmid,ver,pageedit);                           //~v850R~
	}                                                              //~v850I~
	return;                                                        //~v808I~
}//escstopmsg2                                                      //~v808I~//~v965R~
                                                                   //~v808I~
//**********************************************************************
//* write option err msg  v3.8a
//**********************************************************************
void optionerr(char *type,char* value)
{
  if (dbcsenv)  //DBCS mode v4.9a
	  fprintf(stderr,"%s:%s: %s の値が無効です(%s)\n",pgmid,ver,type,value);//v4.9a//~v90mR~
  else			//SBCS mode v4.9a	
	  fprintf(stderr,"%s:%s:invalid %s option parm value(%s)\n",pgmid,ver,type,value);//~v90mR~
  uexit(4);                                                     //~v742R~
}//optionerr

//**********************************************************************
//* os/2 init		v7.0a
//**********************************************************************
void os2init(void)
{
#ifdef DOS
	return;
#else
//v7.1d start
//	APIRET16	apiret16;		//r.c
//	USHORT waitopt=0;
//	int ch;
//***************
//	apiret16=KbdOpen(&hkbd);	//open logical kbd
//	if (apiret16)
//	{
//		fprintf(stderr,"KbdOpen Failed\n");
//		exit(8);
//	}
//	apiret16=KbdGetFocus(waitopt,hkbd);
//	if (apiret16)
//	{
//		ch=apiret16;
//		fprintf(stderr,"KbdGetForcus Failed,rc=%d\n",ch);
//		uexit(8);                                               //~v742R~
//	}
//v7.1d end
  #ifdef OS2                                                       //~v907I~
	if (kbdinp(_KEYBRD_READY)==-1)                              //~v74aI~
    	UCBITON(swsw1,SW1NOKBD);	//kbd not avail             //~v74aI~
  #endif                                                           //~v907I~
	return;
#endif
}//os2init

//**********************************************************************
//*terminate process by Esc key av4.2
//*parm1:req sw:exitsw 0:set Esc acceptsw,1:exit if sw on          //~v808I~
//**********************************************************************
int  breakchk(int Pexitsw) //v4.7a                                 //~v808R~
{
	int ch=0;		//v4.7r				//v7.0r                    //~v965R~
static char Sbreaksw;                                              //~v808I~
//***************
//#ifdef DOS  						//v7.0d
	if (UCBITCHK(swsw1,SW1NOKBD|SW1BACKG))                      //~v74bR~
    	return -1;                                              //~v74aI~
  if (Pexitsw)						//exit if sw on                //~v808I~
  {                                                                //~v808I~
	if (Sbreaksw)                                                  //~v808R~
		escstopmsg(Sbreaksw);	//v6.0r                            //~v808I~
  }	                                                               //~v808I~
  else                                                             //~v808I~
  {                                                                //~v808I~
	ch=kbdinp(_KEYBRD_READY);		//v7.0r
	if (ch)							//v7.0r
	{
//        printf("keyin ready %08x\n",ch); // v4.2test  //@@@@test //~v827R~
		ch=kbdinp(_KEYBRD_READ);	//v7.0r
//        printf("keyin read %08x\n",ch); // v4.2test   //@@@@test //~v827R~
  		escstopmsg2(ch);	//v6.0r                                //~v808R~
		Sbreaksw=(char)ch;			//accepted char                //~v808R~
	}
  }                                                                //~v808I~
//#endif							//v7.0d
	return ch;
}//breakchk

//**********************************************************************
//* get kbd input	v5.2a
//**********************************************************************
int  kbdinp(USHORT waitopt)
{
#ifdef UNX                                                         //~v907I~
	int ch;		//v4.7r                                            //~v907I~
//***************                                                  //~v907I~
    if (waitopt==_KEYBRD_READY)	/* check for keystroke *///v7.0a   //~v907I~
    	return kbhit();                                            //~v907R~
  	ch=getch_nc();		//not curses rtn                           //~v907R~
#else   //!UNX                                                     //~v907I~
#ifdef DOS                                                         //~v826R~
	int ch;		//v4.7r
//***************
	ch=_bios_keybrd(waitopt);		//v7.0r
#else
//***************                                                  //~v826I~
  #ifdef W32                                                       //~v826I~
	int ch;		//v4.7r                                            //~v827M~
	ch=xpw95kbinp(waitopt);                                        //~v826I~
  #else								//os/2                         //~v826I~
//*** for os2 	v7.0a
	int ch;
	APIRET16 apiret16;
	KBDKEYINFO  kbdkeyinfo;		//kbd information
//***************
	kbdkeyinfo.fbStatus=0;		//v7.1r
    if (waitopt==_KEYBRD_READY)	/* check for keystroke *///v7.0a
  		apiret16=KbdPeek(&kbdkeyinfo,0);					//v7.1r
  	else
		apiret16=KbdCharIn(&kbdkeyinfo,waitopt,0);			//v7.1r
	if (apiret16)
	{
		ch=apiret16;
		fprintf(stderr,"\nKbdCharinfo Failed,rc=%d\n",ch);      //~v74aR~
        if (apiret16==ERROR_KBD_EXTENDED_SG)                    //~v74aR~
            return -1;                                          //~v74aR~
		uexit(ch);                                              //~v74aR~
	}
    if (kbdkeyinfo.fbStatus)		//v7.1r
		ch=kbdkeyinfo.chChar;
	else
		ch=0;
//	if(ch)  //test
//		printf("kbdio char=%02x,scan=%02x,fbstatus=%02x,time=%08x,fsstatus=%04x\n",
//				kbdkeyinfo.chChar,kbdkeyinfo.chScan,
//				kbdkeyinfo.fbStatus,
//				kbdkeyinfo.time,
//				kbdkeyinfo.fsState);	//test
  #endif		//os/2                                             //~v826I~
#endif	
#endif  //!UNX                                                     //~v907I~
	return ch;
}//kbdinp

////**********************************************************************//~v847R~
////*return dbcs environment status(1:dbcs,0:sbcd) v4.9a           //~v847R~
////**********************************************************************//~v847R~
//int  dbcsenvchk(void)                                            //~v847R~
//{                                                                //~v847R~
//#ifdef DOS                      //v7.0a                          //~v847R~
//  #ifdef DPMI                   //DPMI version                   //~v847R~
//  #else                       //not DPMI                         //~v847R~
//    union REGS   reg;                                            //~v847R~
//    struct SREGS sreg;                                           //~v847R~
//    unsigned char far **fpc;                                     //~v847R~
//    USHORT fpi[2];                                               //~v847R~
//  #endif                      //DPMI or not                      //~v847R~
//#else                           //v7.0a                          //~v847R~
//  #ifdef W32                                                     //~v847R~
//  #else                             //os/2                       //~v847R~
//    APIRET apiret;              //v7.0a                          //~v847R~
//    COUNTRYCODE countrycode={0,0};  //v7.0a cuurent countrycode/codepage//~v847R~
//    UCHAR buff[12];             //v7.0a                          //~v847R~
//  #endif                            //os/2                       //~v847R~
//#endif                          //v7.0a                          //~v847R~
//    int dbcssw;             //for os2,DBCS on   v7.0r            //~v847R~
////***************                                                //~v847R~
//#ifdef DOS                                                       //~v847R~
//  #ifdef DPMI                   //DPMI version                   //~v847R~
//    dbcssw=(udbcsenv()!=0);                                      //~v847R~
//  #else                       //not DPMI                         //~v847R~
//    reg.x.ax=0x6300;                  //get DBCS vector          //~v847R~
//    intdosx(&reg,&reg,&sreg);                                    //~v847R~
//    fpi[0]=reg.x.si;                    //DS:SI=vector tbl addr  //~v847R~
//    fpi[1]=sreg.ds;                     //DS:SI=vector tbl addr  //~v847R~
//    fpc=(unsigned char far **)(void*)fpi;           //as far ptr //~v847R~
//    dbcssw=(**fpc || *(*fpc+1));        //DBCS when start/stop byte is null//~v847R~
////** dos version get v7.27a start                                //~v847R~
//    reg.x.ax=0x3000;                  //get dos version          //~v847R~
//    intdos(&reg,&reg);                                           //~v847R~
//    if (reg.h.al>=20)               //al:major                   //~v847R~
//        os2sw=1;                    //os2 mvdm                   //~v847R~
//    else                                                         //~v847R~
//        os2sw=0;                    //dos                        //~v847R~
//  #endif                            //v7.0a                      //~v847R~
////** dos version get v7.27a end                                  //~v847R~
//#else                                                            //~v847R~
//  #ifdef W32                                                     //~v847R~
//    dbcssw=xpw95dbcsenv();                                       //~v847R~
//  #else                             //os/2                       //~v847R~
////** for os2 v7.0                                                //~v847R~
//    apiret=DosQueryDBCSEnv(12,&countrycode,buff);                //~v847R~
//    if (apiret)                                                  //~v847R~
//    {                                                            //~v847R~
//        fprintf(stderr,"DosQueryDBCSEnv Failed,rc=%d\n",apiret); //~v847R~
//        uexit(8);                                                //~v847R~
//    }                                                            //~v847R~
//    dbcssw=(buff[0]||buff[1]);                                   //~v847R~
//    os2sw=2;            //os2versionv7.27a                       //~v847R~
//  #endif                            //os/2                       //~v847R~
//#endif                                                           //~v847R~
//    return dbcssw;                                               //~v847R~
//}//dbcsenvchk                                                    //~v847R~
//**********************************************************************//~v847I~
//*return dbcs environment status(1:dbcs,0:sbcd) v4.9a             //~v847I~
//**********************************************************************//~v847I~
int  dbcsenvchk(void)                                              //~v847I~
{                                                                  //~v847I~
	int rc;                                                        //~v91hI~
//***************                                                  //~v847I~
#ifdef UTF8SUPP                                                    //~v92nI~
    setlocale(LC_ALL,"");   //for pango_language_get_default()     //~v92nI~
#endif                                                             //~v92nI~
//  return udbcschkcp();                                           //~v91hR~
    rc=udbcschkcp();                                               //~v91hI~
//  if (Gudbcschk_flag & UDBCSCHK_EUC)                             //~v91iR~
//      rc=0;	//use english                                      //~v91iR~
    return rc;                                                     //~v91hI~
}//dbcsenvchk                                                      //~v847I~
//**********************************************************************//~v893I~
//*setup codepage from parm file                                   //~v893I~
//*parm1:non printable/sbcs/dbcs id table                          //~v895R~
//*parm2:trt tbl ptr output                                        //~v895I~
//*    ==00:mean no conversion and leave codepage as is            //~v895I~
//*    !=00:translation char   and change codepage as sbcs byte    //~v895I~
//**********************************************************************//~v893I~
void setupcp(int *Pcodepage,UCHAR **Pptrt)                         //~v895R~
{                                                                  //~v893I~
	FILE * hfile;                                                  //~v893I~
    int    ii,*pi;                                                 //~v895R~
static UCHAR  Strt[256],*pc;                                       //~v893I~
//***************                                                  //~v893I~
	if (!(hfile=fopen(Gptrtfnm,"rb")))      //open ascii input     //~v893I~
    {                                                              //~v893I~
		if (dbcsenv)	//DBCS mode                                //~v893I~
			printf("\n%s:%s:コード変換テーブルファイル(%s) オープンエラー\n",pgmid,ver,Gptrtfnm);//~v893I~
		else			//SBCS mode v4.9a                          //~v893I~
			printf("\n%s:%s:Code Translation Table file(%s) open err\n",pgmid,ver,Gptrtfnm);//~v893I~
		uexit(4);                                                  //~v893I~
	}                                                              //~v893I~
   	if (fread(Strt,1,256,hfile)!=256)	//read 1 block v7.0r       //~v893I~
    {                                                              //~v893I~
		if (dbcsenv)	//DBCS mode                                //~v893I~
			printf("\n%s:%s:コード変換テーブルファイル(%s) 読み込みエラー(len<256)\n",pgmid,ver,Gptrtfnm);//~v893I~
		else			//SBCS mode v4.9a                          //~v893I~
			printf("\n%s:%s:Code Translation Table file(%s) read err(len<256)\n",pgmid,ver,Gptrtfnm);//~v893I~
		uexit(4);                                                  //~v893I~
	}                                                              //~v893I~
    for (ii=0,pc=Strt,pi=Pcodepage;ii<256;ii++,pc++,pi++)          //~v895R~
    	if (!*pc)                                                  //~v895R~
            *pc=(UCHAR)ii;      //                                 //~v893I~
        else					//conv specified                   //~v895I~
        	*pi=1;				//change to sbcs                   //~v895I~
    *Pptrt=Strt;                                                   //~v893I~
    return;                                                        //~v895R~
}//setupcp                                                         //~v893I~
//************************************************                 //~v96eM~
void chkvfmtparm(char *Pparm)                                      //~v96eM~
{                                                                  //~v96eM~
    if (!*Pparm)                                                   //~v96eM~
		vfmt=UFGETS_VFMT_DEFAULT;       	//recfm=V default RDW  //~v96eM~
    else                                                           //~v96eM~
    	if (ufile5chkvfmt(0,Pparm,&vfmt))                          //~v96eM~
	    	optionerr("VariableLengthRecord Format",Pparm);        //~v96eM~
}                                                                  //~v96eM~
//************************************************                 //~v96eM~
void errexclusive(char *Popt1,char *Popt2)                         //~v96eM~
{                                                                  //~v96eM~
    uerrexit("%c%s and %c%s is conflict",                          //~v96eM~
             "%c%s と %c%s は矛盾します",                          //~v96eM~
			CMDFLAG_PREFIX,Popt1,CMDFLAG_PREFIX,Popt2);            //~v96eM~
}//errexclusive                                                    //~v96eM~
//************************************************                 //~v96eI~
int	sub1freadVinit(int Popt,char *Pfnm)                            //~v96eR~
{                                                                  //~v96eI~
	int binopt;                                                    //~v96eI~
//************************                                         //~v96eI~
	strcpy(SfilenameV,Pfnm);                                       //~v96eI~
    binopt=UFGETS_BIN                                 //~v107I~    //~v96eR~
    		|UFGETS_RV                                             //~v96eI~
	    	|(vfmt<<UFGETS_VFMTSHIFT);                 //~vaj0R~   //~v96eR~
    if (hexdump)                                                   //~v96iI~
        binopt|=UFGETS_RVHDR;   //output vhdr                      //~v96iI~
    ufgetsinit(binopt,0,0,0);//	default buffsize default rate,width when binary//~v96eI~
	sub1freadVinitphase();                                         //~v96iR~
    return 0;                                                      //~v96eI~
}                                                                  //~v96eI~
//************************************************                 //~v96iI~
int	sub1freadVinitphase()                                          //~v96iI~
{                                                                  //~v96iI~
	readlineV=1;                                                   //~v96iI~
    SswtolV=1;                                                     //~v96iI~
    GeoloffsV=0;                                                   //~v96iI~
    UTRACEP("sub1freadVinit phase=%d\n",phase2sw);                 //~v96iI~
    return 0;                                                      //~v96iI~
}                                                                  //~v96iI~
//************************************************                 //~v96eI~
//read recfm=V record                                              //~v96eR~
//rc:1:endof line(not cont),-1:eof                                 //~v96eR~
//************************************************                 //~v96eI~
int	sub1freadV(int Popt,char *Pbuff,int Pbuffsz,FILE *Pfh,int *Ppreadlen,int *Ppreslen)//~v96eR~
{                                                                  //~v96eI~
	int rc,readlen,rceol=1;                                        //~v96eR~
//************************                                         //~v96eI~
//  rc=ufgets(Pbuff,Pbuffsz,Pfh,&readlen,Ppreslen);                //~v96eR~//~v9a0R~
    rc=ufgets(Pbuff,(unsigned)Pbuffsz,Pfh,&readlen,Ppreslen);      //~v9a0I~
    if (SswtolV)                                                   //~v96iR~
    {                                                              //~v96iI~
    	SswtolV=0;	                                               //~v96iR~
        recordszV0=readlen+*Ppreslen;                              //~v96iI~
	    GeoloffsV+=recordszV0;	                                   //~v96iR~
        GoffsV=0;	//read offset in the record                    //~v96iI~
	    UTRACEP("sub1freadV  phase=%d,eoloffsV=%x\n",phase2sw,GeoloffsV);//~v96iI~
    }                                                              //~v96iI~
    if (rc!=UFGETS_MORE)                                           //~v96eI~
    {                                                              //~v96iI~
	    SswtolV=1;	//next is top of record                        //~v96iR~
		readlineV++;                                               //~v96eI~
    }                                                              //~v96iI~
    switch (rc)		//0 or 4 is ok                                 //~v09YI~//~v96eI~
    {                                                              //~v09YI~//~v96eI~
    case UFGETS_ERR:                                               //~v09YI~//~v96eI~
//      uerrexit("read by fgets",SfilenameV,errno);              //~v09YI~//~v992R~
        uerrexit("%s:read by fgets failed,errno=%d",0,SfilenameV,errno);//~v992R~
    case UFGETS_ERRV:   //recfm=V length err                       //~vaj0I~//~v96eI~
        uerrexit ("vfmt(%s) err at lineNo %ld",0,               //~vaj0R~//~v96eR~
        			ufile5getVfmtstr(0,vfmt),            //~vaj0I~ //~v96eI~
        			readlineV);                                        //~vaj0I~//~v96eR~
    case UFGETS_EOF:                                               //~v09YI~//~v96eI~
        rceol=EOF;                                                 //~v96eI~
        readlen=0;                                                 //~v96eI~
        break;                                                     //~v10aI~//~v96eI~
    case UFGETS_MORE:                                              //~v96eI~
        rceol=0;                                                   //~v96eR~
        break;                                                     //~v96eI~
    case UFGETS_RCMFH2:                                            //~v96eI~
        vfmt=UFGETS_VFMT_MFH2;                                     //~v96eI~
        break;                                                     //~v96eI~
    case UFGETS_RCMFH4:                                            //~v96eI~
        vfmt=UFGETS_VFMT_MFH4;                                     //~v96eI~
        break;                                                     //~v96eI~
    }                                                              //~v09YI~//~v96eI~
    *Ppreadlen=readlen;                                            //~v96eI~
    UTRACED("sub1freadV read",Pbuff,readlen);                      //~v96eI~
    UTRACEP("sub1freadV rc=%d,linectr=%d,vfmt=%d\n",rceol,readlineV,vfmt);//~v96eR~
    return rceol;                                                  //~v96eR~
}//sub1freadV                                                      //~v96eI~
