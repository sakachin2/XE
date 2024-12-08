//CID://+v6EiR~:                                                   //+v6EiR~
//*************************************************************
//*uerrexit/uerrmsg/uerrexit_init/uerrmsg_init/ugeterrmsg**
//*************************************************************
//v6Ei:160802 (XE:vb4f)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//+v6EiI~
//v150:980119 need differrentiate codepage and dbcs tbl            //~v150I~
//            w95J codepdge 437 hase dbcs table and first half of DBCS on//~v150I~
//            rightmost column effect on first column of next line //~v150I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -warning unused static                               //~v053I~
//v044:961106:split uvio.c to uvio2.c(screen i/o)                  //~v044I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//*950827 printf errexit msg before ufuncpathmsg(may call errmsg//~5827R~
//*       and reset static errmsg by map open err etc)          //~5827I~
//*pathmsg only when mapfile specified                          //~5827I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

#ifdef DOS
	#include <dos.h>                                               //~v053I~
#else
    #ifdef W32                                                     //~v022I~
		#include <windows.h>                                       //~v022I~
    #else                                                          //~v022I~
	#define INCL_BASE
	#include <os2.h>
	#endif                                                         //~v022I~
#endif
//*******************************************************
#include <ulib.h>
#include <upopup.h>                                             //~5902R~
#include <uerr.h>                                               //~5902I~
#include <uvio.h>
#include <uvio2.h>                                                 //~v044I~
#include <ukbd.h>
#include <udbcschk.h>
//*******************************************************
//*dummy for LIB(same name as file)						*
//*******************************************************
void upopup(void)                                               //~5902R~
{
	return;
}
//******************************************************
//* popupmsg
//* parm1:psg text(nullterminated)
//* parm2:attr byte
//******************************************************
int upopupmsg(char *Pmsg,unsigned char Pattr)
{
#define BOXWIDTH 60
static	int   Sboxinit=0; //init sw
static	int   Sorgx=8,Sorgy=10; //co-ordination of left top of box
static 	unsigned char Stop[BOXWIDTH];
static	unsigned char Smid[BOXWIDTH];
static	unsigned char Smid2[BOXWIDTH];
static	unsigned char Send[BOXWIDTH];
static	unsigned char Spressmsgj[]="âΩÇ©ÉLÅ|ÇâüÇµÇƒâ∫Ç≥Ç¢ÅB";
static	unsigned char Spressmsge[]="Press Anykey.";
    #ifdef W32                                                     //~v022M~
    	HANDLE hconold,hconnew;                                    //~v022M~
    #else                                                          //~v022M~
    #ifdef DOS                                                     //~v053I~
    #else                                                          //~v053I~
	USHORT usopt=3;//transparent+wait until avail                  //~v022I~
//	USHORT usopt=1;//non transparent+wait until avail              //~v022I~
	USHORT usrc;
    #endif                                                         //~v053I~
    #endif                                                         //~v022M~
                                                                   //~v022I~
	unsigned int  ulrc=0;                                          //~v022R~
	KBDKEYINFO ki;
	unsigned char *pcf,*pct;
	int i,y,len=0;
	int dbcssw=0;
    int lineopt=0;	//func not called                              //+v6EiI~
//***********************************
	if (!Sboxinit)
	{
		memset(Stop,0x06,BOXWIDTH);
		memset(Smid,' ' ,BOXWIDTH);
		memset(Smid2,' ' ,BOXWIDTH);
		memset(Send,0x06,BOXWIDTH);
		Stop[0]=0x01;
		Stop[BOXWIDTH-1]=0x02;
		Smid[0]=0x05;
		Smid[BOXWIDTH-1]=0x05;
		Smid2[0]=0x05;
//  	if (udbcschk(0x81))                                        //~v150R~
    	if (udbcschkcp())	//dbcs env and cp=932                  //~v150I~
			memcpy(Smid2+4,Spressmsgj,strlen(Spressmsgj));
		else
			memcpy(Smid2+4,Spressmsge,strlen(Spressmsge));
		Smid2[BOXWIDTH-1]=0x05;
		Send[0]=0x03;
		Send[BOXWIDTH-1]=0x04;
	}
#ifdef DOS
#else
    #ifdef W32                                                     //~v022I~
    	hconold=ugetstdhandle(STD_OUTPUT_HANDLE);                  //~v022I~
    	hconnew=CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE,//~v022I~
								FILE_SHARE_READ|FILE_SHARE_WRITE,  //~v022R~
								NULL,                  //security  //~v022I~
								CONSOLE_TEXTMODE_BUFFER,           //~v022R~
								NULL);	//rsv                      //~v022I~
		if (hconnew==INVALID_HANDLE_VALUE)                         //~v022I~
			uerrapi1x("CreateConsoleScreenBuffer","POPUP",GetLastError());//~v022I~
    	ulrc=SetConsoleActiveScreenBuffer(hconnew);                //~v022I~
		if (!ulrc)	//bool                                         //~v022I~
			uerrapi1x("SetConsoleActiveScreenBuffer","POPUP",GetLastError());//~v022I~
	#else                                                          //~v022I~
	usrc=VioPopUp(&usopt,0);
//	printf("viopopup,rc=%d\n",(int)usrc);
	#endif                                                         //~v022I~
#endif

	y=Sorgy;
	if (!Pattr)
		Pattr=0x17;
//	ulrc+=uviowrtcharstratt(Stop,BOXWIDTH,y++,Sorgx,&Pattr);       //+v6EiR~
 	ulrc+=uviowrtcharstratt(lineopt,Stop,BOXWIDTH,y++,Sorgx,&Pattr);//+v6EiI~
//	printf("uviowrtncharstratt,rc=%d\n",(int)ulrc);

	pcf=Pmsg;
	if (pcf)
		len=(int)strlen(Pmsg);
	while(len)
	{
		memset(Smid+1,' ',BOXWIDTH-2);
		pct=Smid+2;
		for (i=0;i<BOXWIDTH-4;i++)
		{
			if (!len)
				break;
			if (*pcf=='\n')
			{
				pcf++;
				len--;
				break;
			}
			if (dbcssw)
				dbcssw=0;
			else
				dbcssw=udbcschk(*pcf);
			if (dbcssw && i==BOXWIDTH-5)
				break;
			*pct++=*pcf++;
			len--;
		}
//  	ulrc+=uviowrtcharstratt(Smid,BOXWIDTH,y++,Sorgx,&Pattr);   //+v6EiR~
    	ulrc+=uviowrtcharstratt(lineopt,Smid,BOXWIDTH,y++,Sorgx,&Pattr);//+v6EiI~
//		printf("uviowrtncharstratt,rc=%d\n",(int)ulrc);
		
	}
//  ulrc+=uviowrtcharstratt(Smid2,BOXWIDTH,y++,Sorgx,&Pattr);      //+v6EiR~
    ulrc+=uviowrtcharstratt(lineopt,Smid2,BOXWIDTH,y++,Sorgx,&Pattr);//+v6EiI~
//  ulrc+=uviowrtcharstratt(Send,BOXWIDTH,y,Sorgx,&Pattr);         //+v6EiR~
    ulrc+=uviowrtcharstratt(lineopt,Send,BOXWIDTH,y,Sorgx,&Pattr); //+v6EiI~
//	printf("uviowrtncharstratt,rc=%d\n",(int)ulrc);

	ubell();
#ifdef DOS                                                         //~v022I~
#else                                                              //~v022I~
    #ifdef W32                                                     //~v022I~
    if (ulrc)		//for compiler warning                         //~v022I~
		ubell();                                                   //~v022I~
	#endif                                                         //~v022I~
#endif                                                             //~v022I~

	ukbdcharin(&ki,0);                                             //~v022R~
//	printf("ukbdcharin,rc=%d\n",(int)uirc);

#ifdef DOS
#else
    #ifdef W32                                                     //~v022I~
    	ulrc=SetConsoleActiveScreenBuffer(hconold);                //~v022I~
		if (!ulrc)	//bool                                         //~v022I~
			uerrapi1x("SetConsoleActiveScreenBuffer","STD_OUT",GetLastError());//~v022I~
    	ulrc=CloseHandle(hconold);                                 //~v022I~
		if (!ulrc)	//bool                                         //~v022I~
			uerrapi1x("CloseHandel","POPUP",GetLastError());       //~v022I~
	#else                                                          //~v022I~
	usrc=VioEndPopUp(0);
//	printf("vioendpopup,rc=%d\n",(int)usrc);
	usrc=usrc;
	#endif                                                         //~v022M~
#endif                                                             //~v022M~
	return 0;
}//upopupmsg
