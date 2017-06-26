//CID://+vaa2R~:           update#= 15                             //~vaa2R~
//***********************************************************
//* XTS    : set file/dir timestamp
//***********************************************************
//vaa2:160424 Lnx64 compiler warning(FDATE/FTIME)                  //~vaa2I~
//vaa0:160417 Lnx compiler warning                                 //~vaa0I~
//va6c:120808 xts v1.6 FileTimeToDosDateTime round up odd sec to next even number//~va6cI~
//va68:120729 xts v1.6 display/update linux time stamp by not ftime(2 sec) but sec//~va68I~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va3v:080321 xts.c v1.5:add cmd elapsed time calc function(/e)    //~va3vI~
//va3u:080319 xts.c v1.5:add current time display function /c      //~va3uI~
//va3f:071107 xts: v1.4 (Wind/Unx) display creation time           //~va3fI~
//*va1a:040102 xts:v1.3:yyyy 4 digit year support                  //~va1aI~
//*va16:031103 xts:v1.3:ftp support(4 byte udirlist attr for ! UNX)//~va16I~
//*v123 *011015 (BUG)for root dir duplicated dir seperator         //~v123I~
//*v122 *011015 UNX support                                        //~v1.1I~
//*v121 *011015 (BUG)abend when no path exist                      //~v1.1I~
//*v1.1 *980921 filename .a or ..a etc under win95                 //~v1.1I~
//***********************************************************

#define VER "V1.6"   //version                                     //~va3uR~//~vaa0R~
#define PGM "xts"                                                  //~v1.1R~

//**********************************************/
//*parm1 : file name
//*parm2 : time stamp date yy-mm-dd
//*parm3 : time stamp time hh:mm:ss
//*r.c   : 0 :all file area same
//*      : 4 :file not found
//*      : 8 :parameter err
//**********************************************/
//*
#ifdef DOS
	#include <dos.h>
	#include <errno.h>
#else
    #ifdef W32                                                     //~v1.0I~
    	#include <windows.h>                                       //~va3fM~
		#include <dos.h>                                           //~v1.0I~
    #else                                                          //~v1.0I~
		#define INCL_BASE                                          //~v1.0R~
		#include <os2.h>                                           //~v1.0R~
	#endif                                                         //~v1.0R~
#endif                                                             //~v1.0I~


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/timeb.h>                                             //~va3vI~

//*********************************************************************
#include <ulib.h>
#include <ufile.h>
#include <ufile2.h>
#include <ufile3.h>                                                //~va6cI~
#include <uedit.h>
#include <uerr.h>
#include <ucalc2.h>                                                //~va3vI~
#include <uedit2.h>                                                //~vaa2I~
#ifdef DPMI                 //DPMI version                         //~v1.0I~
	#include <ufile4.h>                                            //~v1.0I~
#endif                                                             //~v1.0I~
//*********************************************************************

//*********************************************************************
static char *Spgm=PGM,*Sver=VER;
static char *Sfnm=0;                                               //~v122R~
static FDATE *Spinpdate=0;                                         //~v122R~
static FTIME *Spinptime=0;                                         //~v122R~
static int Sfctr=0;                                                //~v122R~
static int Serrro=0,Serrdir=0;                                     //~v122R~
#ifdef W32                                                         //~va3fI~
   FILETIME Sctime;                                                //~va3fI~
#else                                                              //~va3fI~
	#ifdef UNX                                                     //~va3fI~
    	time_t Sctime;                                             //~va3fI~
    #endif                                                         //~va3fI~
#endif                                                             //~va3fI~
	static int Soddsec,Soddsecinput,Soddsec_ctime,Soddsec_new;     //~va68R~
//********************
//int pfile(char *Pfnm,char Pattr);                                //~va16R~
int pfile(char *Pfnm,ULONG Pattr);                                 //~va16I~
void parmchk(int parmc,char *parmp[]);
int getnum(char *Pdata,int *Ppi1,int *Ppi2,int *Ppi3);
void optionerr(char *type,char* value);
void parmerr(char* value);                                         //~v1.0I~
void help(void);
void pline(int Popt,FDATE Pfdto,FTIME Pftmo,FDATE Pfdtn,FTIME Pftmn,char *Pfnm,int Pdirid);//~v1.0R~
void printnow(char *Pfmt);                                         //~va3uR~
int cmdtime(char *Pcmd,int Ploop);                                 //~va3vI~
//*********************************************************************
int main(int parmc,char *parmp[])
{
    int filectr,ii,pathlen,reqctr=0;                               //~v1.0R~
    PUDIRLIST pudirlist,pudirlist0;                                //~v1.0I~
    char pathnm[_MAX_PATH];                                        //~v1.0R~
    char *fnm;                                                     //~v1.0I~
//  char attr;                                                     //~va16R~
    ULONG attr;                                                    //~va16I~
    FILEFINDBUF3 fstat3;                                           //~v1.0I~
//**********************
	uerrmsg_init("",stdout,0);//msg to stdout                      //~v1.0I~
	uerrexit_init("",stdout,0,0,0);//stdout only,no pathmsg        //~v1.0I~
#ifdef DPMI					//DPMI version                         //~v1.0I~
    putenv("LFN=Y");                 //need for ufileisvfat        //~v1.0I~
	ufileisvfat(ISVFAT_FORCE);      //force vfat                   //~v1.0I~
#endif                      //DPMI or not                          //~v1.0I~
    parmchk(parmc,parmp);
//*get current value
    if (WILDCARD(Sfnm))                                            //~v1.0I~
    {                                                              //~v1.0I~
        if ((filectr=udirlist(Sfnm,FILE_ALL,&pudirlist0,0))==-1) //no sort,-1 not found//~v1.0I~
	    	return 4;                                              //~v1.0I~
		pathlen=PATHLEN(Sfnm);                                     //~v1.0I~
        if (pathlen<0)                                             //~v121R~
            pathlen=0;                                             //~v121R~
        memcpy(pathnm,Sfnm,(UINT)pathlen);                         //~v1.0R~
        for (ii=0,pudirlist=pudirlist0;ii<filectr;ii++,pudirlist++) //until eof/err//~v1.0I~
        {                                                          //~v1.0I~
            fnm=pudirlist->name;                                   //~v1.0I~
//          if (*fnm=='.')      //parent or self                   //~v1.1R~
            if (!strcmp(fnm,".")      //self                       //~v1.1I~
            ||  !strcmp(fnm,".."))    //parent                     //~v1.1I~
                continue;                   //already inseted entr //~v1.0I~
            reqctr++;                                              //~v1.0I~
            strcpy(pathnm+pathlen,fnm);                            //~v1.0I~
            attr=pudirlist->attr;                                  //~v1.0I~
#ifdef W32                                                         //~va3fI~
        	Sctime=pudirlist->ftCreationTime;                      //~va3fI~
#else                                                              //~va3fI~
	#ifdef UNX                                                     //~va3fI~
    		Sctime=pudirlist->ctime;                               //~va3fI~
    #endif                                                         //~va3fI~
#endif                                                             //~va3fI~
			pfile(pathnm,attr);                                    //~v1.0R~
        }                                                          //~v1.0I~
    }                                                              //~v1.0I~
    else                                                           //~v1.0I~
		if (!ufstat(Sfnm,&fstat3))                                 //~v1.0R~
        {                                                          //~v1.0I~
	        reqctr=1;                                              //~v1.0I~
//          attr=(char)fstat3.attrFile;                            //~va16R~
            attr=(ULONG)fstat3.attrFile;                           //~va16I~
#ifdef W32                                                         //~va3fI~
        	Sctime=fstat3.ftCreationTime;                          //~va3fI~
#else                                                              //~va3fI~
	#ifdef UNX                                                     //~va3fI~
    		Sctime=fstat3.ctime;                                   //~va3fI~
    #endif                                                         //~va3fI~
#endif                                                             //~va3fI~
			pfile(Sfnm,attr);                                      //~v1.0R~
        }                                                          //~v1.0I~
        else                                                       //~v1.0I~
            uerrexit("%s is not found",                            //~v1.0R~
                    "%s が見つかりません",                         //~v1.0I~
                    Sfnm);                                         //~v1.0I~
//*                                                                //~v1.0I~
    printf("%s:%s:=(%c)= %s -- ok = %d, err = %d (Dir= %d, Ronly= %d).\n",//~v1.0R~
			Spgm,Sver,OSTYPE,Sfnm,Sfctr,reqctr-Sfctr,Serrdir,Serrro);//~v1.0R~
	return 0;
}//main
//**********************************************************************
//* pfile
//*parm1:filename
//*return:rc
//**********************************************************************
//int pfile(char *Pfnm,char Pattr)                                 //~va16R~
int pfile(char *Pfnm,ULONG Pattr)                                  //~va16I~
{
  	FDATE fdto,fdtn={0};                                           //~va64R~
  	FTIME ftmo,ftmn={0};                                           //~va64R~
    int rc;
    int dirid;                                                     //~v1.0R~
    int oddsec;                                                    //~va68I~
//**********************
//  dirid=(char)((Pattr & FILE_DIRECTORY)?'\\':' ');               //~v122R~
    dirid=(char)((Pattr & FILE_DIRECTORY) ? DIR_SEPC : ' ');       //~v122I~
//  if (rc=ugetftime(Pfnm,&fdto,&ftmo),rc)                         //~va68R~
    if (rc=ugetftime_1sec(Pfnm,&fdto,&ftmo,&oddsec),rc)            //~va68R~
    	return rc;
    Soddsec=oddsec;                                                //~va68I~
    if (Spinpdate || Spinptime)
    {
    	if (Pattr & FILE_READONLY)                                 //~v1.0R~
        {                                                          //~v1.0I~
			pline(1,fdto,ftmo,fdto,ftmo,Pfnm,dirid);	//readonly err//~v1.0R~
            Serrro++;                                              //~v1.0I~
            return 4;                                              //~v1.0I~
        }                                                          //~v1.0I~
#if defined(DOS) || defined(W32)                                   //~v1.0I~
    	if (dirid=='\\')                                           //~v1.0R~
        {                                                          //~v1.0I~
			pline(2,fdto,ftmo,fdto,ftmo,Pfnm,dirid);	//directory err//~v1.0R~
            Serrdir++;                                             //~v1.0I~
            return 4;                                              //~v1.0I~
        }                                                          //~v1.0I~
#endif                                                             //~v1.0I~
//*set req     value
        if (Spinpdate)
            fdtn=*Spinpdate;
		else
            fdtn=fdto;
        if (Spinptime)
            ftmn=*Spinptime;
		else
            ftmn=ftmo;
#if defined(UNX)||defined(W32)                                     //~va68R~
        if (rc=usetftime_1sec(Pfnm,fdtn,ftmn,Soddsecinput),rc)     //~va68R~
#else                                                              //~va68I~
        if (rc=usetftime(Pfnm,fdtn,ftmn),rc)
#endif                                                             //~va68I~
            return rc;
//      if (rc=ugetftime(Pfnm,&fdtn,&ftmn),rc)                     //~va68R~
        if (rc=ugetftime_1sec(Pfnm,&fdtn,&ftmn,&oddsec),rc)        //~va68R~
            return rc;
        Soddsec_new=oddsec;                                        //~va68R~
	}
	pline(0,fdto,ftmo,fdtn,ftmn,Pfnm,dirid);	//success          //~v1.0R~
    Sfctr++;
    return 0;
}//pfile
//**********************************************************************
//* print line
//*parm1:option;0:success,1:readonly err,2:dir                     //~v1.0R~
//*parm1:old FDATE                                                 //~v1.0I~
//*parm2:old FTIME
//*parm3:new FDATE
//*parm4:new FTIME
//*parm5:filename
//*parm6:directory id                                              //~v1.0I~
//*return:none
//**********************************************************************
void pline(int Popt,FDATE Pfdto,FTIME Pftmo,FDATE Pfdtn,FTIME Pftmn,char *Pfnm,int Pdirid)//~v1.0R~
{
    char cftmo[12],cftmn[12];
    char cfdto[12],cfdtn[12];
//static char Sdtep[]="YY-MM-DD";                                  //~va1aR~
static char Sdtep[]="YYYY-MM-DD";                                  //~va1aI~
static char Stmep[]="HH:MM:SS";
#ifdef W32                                                         //~va3fI~
	FDATE crfdate;                                                 //~va3fI~
	FTIME crftime;                                                 //~va3fI~
    FILETIME lft;                                                  //~va3fI~
#endif                                                             //~va3fI~
#ifdef UNX                                                         //~va3fI~
	FDATE crfdate;                                                 //~va3fI~
	FTIME crftime;                                                 //~va3fI~
	int xtstime2dosfiletime(ULONG Ptime,FDATE *Ppfdate,FTIME *Ppftime);//~va3fI~
#endif                                                             //~va3fI~
//**********************
//printf("dt=%04d-%04d-%04d,tm=%04d:%04d:%04d\n",
//        fdt.year,
//        fdt.month,
//        fdt.day,
//        ftm.hours,
//        ftm.minutes,
//        ftm.twosecs);//@@@@
	if (ROOTDIR(Pfnm))                                             //~v123R~
    	Pdirid=' ';                                                //~v123I~
//  printf("mod date=%x,time=%x\n",(int)(*(USHORT*)(ULONG)(&Pfdto)),(int)(*(USHORT*)(ULONG)(&Pftmo)));//~va3fR~
	ufdateedit(Pfdto,Sdtep,cfdto);
//  uftimeedit(Pftmo,Stmep,cftmo);                                 //~va68R~
    uftimeedit_1sec(Pftmo,Stmep,cftmo,Soddsec);                    //~va68R~
    if (!Spinpdate && !Spinptime)
    {
#ifdef W32                                                         //~va3fI~
    	FileTimeToLocalFileTime(&Sctime,&lft);                     //~va3fR~
//		FileTimeToDosDateTime(&lft,(USHORT*)(ULONG)&crfdate,(USHORT*)(ULONG)&crftime);//~va3fR~//~va66R~
    	filetime2dosdatetime(&lft,(USHORT*)(ULPTR)&crfdate,(USHORT*)(ULPTR)&crftime,0);//~va66I~//~va6cR~
//      printf("cre date=%x,time=%x\n",(int)(*(USHORT*)(ULONG)(&crfdate)),(int)(*(USHORT*)(ULONG)(&crftime)));//~va3fR~
		ufdateedit(crfdate,Sdtep,cfdtn);                           //~va3fR~
		uftimeedit(crftime,Stmep,cftmn);                           //~va3fR~
        printf("= %s %s (Created: %s %s) == %s%c\n",               //~va3fR~
				cfdto,cftmo,cfdtn,cftmn,Pfnm,Pdirid);              //~va3fR~
#else                                                              //~va3fR~
	#ifdef UNX                                                     //~va3fI~
		xtstime2dosfiletime((ULONG)Sctime,&crfdate,&crftime);      //~va3fI~
		ufdateedit(crfdate,Sdtep,cfdtn);                           //~va3fI~
//  	uftimeedit(crftime,Stmep,cftmn);                           //~va68R~
    	uftimeedit_1sec(crftime,Stmep,cftmn,Soddsec_ctime);        //~va68R~
//      printf("= %s %s (Changed: %s %s) == %s%c\n",               //~va68R~
        printf("= %s %s (Created: %s %s) == %s%c\n",               //~va68I~
				cfdto,cftmo,cfdtn,cftmn,Pfnm,Pdirid);              //~va3fR~
	#else                                                          //~va3fI~
        printf("= %s  %s  == %s%c\n",                              //~v1.0R~
				cfdto,cftmo,Pfnm,Pdirid);                          //~v1.0R~
	#endif                                                         //~va3fI~
#endif                                                             //~va3fI~
		return;
	}
//printf("dt=%04d-%04d-%04d,tm=%04d:%04d:%04d\n",
//        fdt.year,
//        fdt.month,
//        fdt.day,
//        ftm.hours,
//        ftm.minutes,
//        ftm.twosecs);//@@@@
	switch(Popt)                                                   //~v1.0I~
    {                                                              //~v1.0I~
    case 0:                                                        //~v1.0I~
		ufdateedit(Pfdtn,Sdtep,cfdtn);                             //~v1.0R~
//  	uftimeedit(Pftmn,Stmep,cftmn);                             //~va68R~
    	uftimeedit_1sec(Pftmn,Stmep,cftmn,Soddsec_new);            //~va68R~
    	printf("= %s  %s  -->  %s  %s  == %s%c\n",                 //~v1.0R~
				cfdto,cftmo,cfdtn,cftmn,Pfnm,Pdirid);              //~v1.0R~
		break;                                                     //~v1.0I~
    case 1:			//read only file                               //~v1.0I~
    	printf("= %s  %s  ???  Error, ReadOnly     == %s%c\n",     //~v1.0R~
				cfdto,cftmo,Pfnm,Pdirid);                          //~v1.0R~
		break;                                                     //~v1.0I~
    case 2:			//dir                                          //~v1.0I~
    	printf("= %s  %s  ???  Error, Directory    == %s%c\n",     //~v1.0R~
				cfdto,cftmo,Pfnm,Pdirid);                          //~v1.0R~
		break;                                                     //~v1.0I~
	}                                                              //~v1.0I~
	return;
}//pline
#ifdef W32                                                         //~va3fI~
//**********************************************************************//~va3fI~
//* pedittsfiletime                                                //~va3fI~
//* print timestamp                                                //~va3fI~
//*  parm1:timestamp                                               //~va3fI~
//*  parm2:output edit timestamp area addr                         //~va3fI~
//**********************************************************************//~va3fI~
char *pedittsfiletime(FILETIME *Ppftm,char *Peditout)              //~va3fI~
{                                                                  //~va3fI~
	FDATE fdate;                                                   //~va3fI~
	FTIME ftime;                                                   //~va3fI~
    FILETIME lft;                                                  //~va3fI~
//**************************                                       //~va3fI~
    FileTimeToLocalFileTime(Ppftm,&lft);                           //~va3fI~
//	if (FileTimeToDosDateTime(&lft,(USHORT*)(ULONG)&fdate,(USHORT*)(ULONG)&ftime))//~va3fI~//~va66R~
    if (filetime2dosdatetime(&lft,(USHORT*)(ULPTR)&fdate,(USHORT*)(ULPTR)&ftime,0),0)//~va66I~//~va6cR~
    {                                                              //~va3fI~
		ufdateedit(fdate,"YY-MM-DD  ",Peditout);    //date and time//~va3fI~
		uftimeedit(ftime,"HH:MM:SS",Peditout+10);    //date and time//~va3fI~
    }                                                              //~va3fI~
    else                                                           //~va3fI~
    	*Peditout=0;                                               //~va3fI~
    return Peditout;                                               //~va3fI~
}//pedittsfiletime                                                 //~va3fI~
#endif	//W32                                                      //~va3fI~
#ifdef UNX                                                         //~va3fI~
//**********************************************************************//~va3fI~
//* conv time to dosfiletime                                       //~va3fI~
//*parm1:ulong sec from 1970                                       //~va3fI~
//*return:ULONG fdate/ftime                                        //~va3fI~
//**********************************************************************//~va3fI~
int xtstime2dosfiletime(ULONG Ptime,FDATE *Ppfdate,FTIME *Ppftime) //~va3fI~
{                                                                  //~va3fI~
    struct    tm* ptm;       //date and time                       //~va3fI~
    FDATE fdt;                                                     //~va3fI~
    FTIME ftm;                                                     //~va3fI~
    long  ptime;                                                   //~va3fI~
//**************                                                   //~va3fI~
//  ptime=Ptime;                                                   //~va3fI~//~vaa0R~
    ptime=(long)Ptime;                                             //~vaa0I~
    ptm=localtime(&ptime);                                         //~va3fI~
//#ifdef AIX                                                         //~va3fI~//~vaa2R~
//    fdt.dummy=0;                                                   //~va3fI~//~vaa2R~
//#endif                                                             //~va3fI~//~vaa2R~
//  fdt.year =ptm->tm_year-80;  	//unix:~1900,dos:~1980         //~va3fI~//~vaa2R~
//  fdt.month=ptm->tm_mon+1;                                       //~va3fI~//~vaa2R~
//  fdt.day  =ptm->tm_mday;                                        //~va3fI~//~vaa2R~
    ueditsetfdateUSHORT(0,ptm->tm_year-80,ptm->tm_mon+1,ptm->tm_mday,&fdt);//~vaa2I~
//#ifdef AIX                                                         //~va3fI~//~vaa2R~
//    ftm.dummy=0;                                                   //~va3fI~//~vaa2R~
//#endif                                                             //~va3fI~//~vaa2R~
//  ftm.hours  =ptm->tm_hour;                                      //~va3fI~//~vaa2R~
//  ftm.minutes=ptm->tm_min;                                       //~va3fI~//~vaa2R~
//  ftm.twosecs=ptm->tm_sec/2;                                     //~va3fI~//~vaa2R~
    ueditsetftimeUSHORT(0,ptm->tm_hour,ptm->tm_min,ptm->tm_sec/2,&ftm);//~vaa2I~
    *Ppfdate=fdt;                                                  //~va3fI~
    *Ppftime=ftm;                                                  //~va3fI~
    Soddsec_ctime=ptm->tm_sec & 1;                                 //~va68I~
    return 0;                                                      //~va3fI~
}//xtstime2dosfiletime                                             //~va3fI~
#endif                                                             //~va3fI~
//**********************************************************************
//*parameter chk
//**********************************************************************
void parmchk(int parmc,char *parmp[])
{
  	unsigned char c;    //read char
  	char *cptr;         //char ptr work
  	int parmno; //parm count work
  	int posparmno=0; //parm count work
    char *pdate=0,*ptime=0;
    int ii,jj,kk,rc;
    int endsw=0;
    int yesno;                                                     //~v1.0I~
static FDATE Sfdt;
static FTIME Sftm;
	int loopcnt=-1;                                                //~va3vI~
    int yy;                                                        //~vaa2I~
//*************************
  	if (parmc<2 || *parmp[1]=='?')
  	{
    	help();
    	exit(0);
  	}
//*******************************
//* parm process                *
//*******************************
	for (parmno=1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
#ifdef UNX                                                         //~v122I~
  		if(*cptr=='-')                                             //~v122I~
#else                                                              //~v122I~
  		if(*cptr=='/'||*cptr=='-')
#endif                                                             //~v122I~
  		{//option
    		c=*(++cptr);                      //first option byte
    		c=(UCHAR)toupper(c);                                   //~v1.0R~
    		switch(c)             //option                         //~v1.0R~
    		{
    		case '?':                      //date                  //~v1.0I~
                help();                                            //~v1.0I~
                exit(0);                                           //~v1.0I~
                break;                                             //~v1.0I~
    		case 'C':                      //current time stamp display//~va3uI~
                printnow(cptr+1);	//fmt                          //~va3uR~
                exit(0);                                           //~va3uI~
                break;                                             //~va3vI~
    		case 'D':                      //date
                pdate=cptr+1;                                      //~v1.0R~
                break;
    		case 'E':                      //date                  //~va3vI~
                loopcnt=atoi(cptr+1);                              //~va3vI~
                break;                                             //~va3vI~
    		case 'T':                      //time
                ptime=cptr+1;                                      //~v1.0R~
                break;
#ifdef UNX                                                         //~v122I~
#else                                                              //~v122I~
    		case '/':                      //time
#endif                                                             //~v122I~
    		case '-':                      //time
                endsw=1;
                break;
    		case 'Y':                      //time                  //~v1.0I~
            case 'N':                                              //~v1.0I~
                yesno=(c=='Y');                                    //~v1.0I~
	    		c=*(++cptr);                      //first option byte//~v1.0I~
	    		c=(UCHAR)toupper(c);                               //~v1.0R~
                switch(c)                                          //~v1.0I~
                {                                                  //~v1.0I~
                case '9':   //japnese                              //~v1.0I~
                    uerrmsg_init("",stdout,UERR_FORCE_ENGLISH*(!yesno));//msg to stdout//~v1.0R~
                    break;                                         //~v1.0I~
                default:                                           //~v1.0I~
                    parmerr(cptr-2);                               //~v1.0R~
                }                                                  //~v1.0I~
                break;                                             //~v1.0I~
    		default:                           //not option
        		parmerr(cptr-1);                                   //~v1.0R~
    		}//switch  by first option byte
  		}
  		else
  		{//positional parmno
    		posparmno++;
    		switch (posparmno)
    		{
    		case  1:          //first parm
//printf("p1=%s;",cptr);  //@@@@
      			Sfnm=cptr;
      			break;
    		case  2:          //first parm
//printf("p2=%s;",cptr);	//@@@@
                if (*cptr!=',')
      				pdate=cptr;
      			break;
    		case  3:          //first parm
//printf("p3=%s;",cptr);	//@@@@
                if (*cptr!=',')
      				ptime=cptr;
      			break;
//************************************
    		default:
      			printf("%s:%s:too many positional parameter(%s)\n",Spgm,Sver,cptr);
      			exit(4);
    		}//switch by parmno
  		}//option or posparm
        if (endsw)
            break;
	}//for all parm

  	if (posparmno<1)
  	{                                                              //~v1.0I~
    	help();                                                    //~v1.0I~
    	exit(0);                                                   //~v1.0I~
  	}                                                              //~v1.0I~
    if (loopcnt>=0)	//-E option                                    //~va3vR~
    {                                                              //~va3vI~
    	cmdtime(Sfnm,loopcnt);                                     //~va3vR~
        exit(0);                                                   //~va3vI~
    }                                                              //~va3vI~
    if (pdate)
    {
        rc=getnum(pdate,&ii,&jj,&kk);
        if (rc)
        	optionerr("Date parm",pdate);
        if (ii<80)
//          Sfdt.year =(USHORT)(2000-1980+ii);                     //~va68R~//~vaa2R~
            yy=2000-1980+ii;                                       //~vaa2I~
        else
//          Sfdt.year =(USHORT)(ii-80);                            //~va68R~//~vaa2R~
            yy=ii-80;                                              //~vaa2I~
//      Sfdt.month=(USHORT)jj;                                     //~va68R~//~vaa2R~
//      Sfdt.day  =(USHORT)kk;                                     //~va68R~//~vaa2R~
    	ueditsetfdateUSHORT(0,yy,jj,kk,&Sfdt);                     //~vaa2I~
        Spinpdate=&Sfdt;
    }
    if (ptime)
    {
        rc=getnum(ptime,&ii,&jj,&kk);
        if (rc)
        	optionerr("Time parm",ptime);
//      Sftm.hours  =(USHORT)ii;                                   //~va68R~//~vaa2R~
//      Sftm.minutes=(USHORT)jj;                                   //~va68R~//~vaa2R~
//      Sftm.twosecs=(USHORT)(kk/2);                               //~va68R~//~vaa2R~
   		ueditsetftimeUSHORT(0,ii,jj,kk/2,&Sftm);                   //+vaa2R~
        Spinptime=&Sftm;
        Soddsecinput=kk&1;                                         //~va68I~
    }
}//parmchk

//**********************************************************************
//* get 3 int value
//*parm1:parm string
//*parm2:out int area1
//*parm3:out int area1
//*parm4:out int area1
//*return:rc;
//**********************************************************************
int getnum(char *Pdata,int *Ppi1,int *Ppi2,int *Ppi3)
{
    int len,i1,i2,i3;
//****************
    len=(int)strlen(Pdata);
    switch(len)
    {
    case 1:           //"0"
    	if (*Pdata!='0')
        	return 4;
        i1=i2=i3=0;
    	break;
    case 4:           //"hhmm"
		if (unumlen(Pdata  ,0,4)!=4)
	    	return 4;
		i1=uatoin(Pdata,  2);
		i2=uatoin(Pdata+2,2);
		i3=0;
    	break;
    case 5:           //"hh:mm"
		if (unumlen(Pdata  ,0,2)!=2
		||  *(Pdata+2)!=':'                                        //~v1.0I~
    	||  unumlen(Pdata+3,0,2)!=2)
    		return 4;
		i1=uatoin(Pdata,  2);
		i2=uatoin(Pdata+3,2);
		i3=0;
    	break;
    case 6:           //"yymmdd"
		if (unumlen(Pdata  ,0,6)!=6)
	    	return 4;
		i1=uatoin(Pdata,  2);
		i2=uatoin(Pdata+2,2);
		i3=uatoin(Pdata+4,2);
    	break;
    case 8:           //"yy:mm:dd"
	  if (unumlen(Pdata  ,0,8)==8) //yyyymmdd fmt                  //~va1aI~
      {                                                            //~va1aI~
		i1=uatoin(Pdata+2,2);                                      //~va1aR~
		i2=uatoin(Pdata+4,2);                                      //~va1aR~
		i3=uatoin(Pdata+6,2);                                      //~va1aI~
      }                                                            //~va1aI~
      else      //yy-mm-dd fmt                                     //~va1aI~
      {                                                            //~va1aI~
		if (unumlen(Pdata  ,0,2)!=2
    	||  unumlen(Pdata+3,0,2)!=2
    	||  unumlen(Pdata+6,0,2)!=2)
    		return 4;
		i1=uatoin(Pdata,  2);
		i2=uatoin(Pdata+3,2);
		i3=uatoin(Pdata+6,2);
      }                                                            //~va1aI~
    	break;
    case 10:          //"yyyy:mm:dd"                               //~va1aI~
		if (unumlen(Pdata  ,0,5)!=4                                //~va1aI~
    	||  unumlen(Pdata+5,0,3)!=2                                //~va1aI~
    	||  unumlen(Pdata+8,0,3)!=2)                               //~va1aI~
    		return 4;                                              //~va1aI~
		i1=uatoin(Pdata+2,2);                                      //~va1aI~
		i2=uatoin(Pdata+5,2);                                      //~va1aI~
		i3=uatoin(Pdata+8,2);                                      //~va1aI~
    	break;                                                     //~va1aI~
	default:
    	return 4;
	}
	*Ppi1=i1;
	*Ppi2=i2;
	*Ppi3=i3;
    return 0;
}//getnum

//**********************************************************************//~va3uI~
//* display current timestamp                                      //~va3uI~
//**********************************************************************//~va3uI~
void printnow(char *Pfmt)                                          //~va3uR~
{                                                                  //~va3uI~
	char *pts;                                                     //~va3uI~
#define FMT_DT  "YYYY/MM/DD"                                       //~va3uI~
#define FMT_TM  "HH:MM:SS.MIL"                                     //~va3uI~
    char fmt[128]=FMT_TM;                                          //~va3uI~
    char *pco,*pci;                                                //~va3uI~
    int dtsw=0;                                                    //~va3uI~
//********************************                                 //~va3uI~
	if (*Pfmt)                                                     //~va3uI~
    {                                                              //~va3uI~
        for (pci=Pfmt,pco=fmt;*pci;pci++)                          //~va3uI~
        {                                                          //~va3uI~
            if (*pci=='\\' && *(pci+1)=='n')                       //~va3uR~
            {                                                      //~va3uI~
                *pco++='\n';                                       //~va3uI~
                pci++;                                             //~va3uI~
                dtsw=0; //no intermediate space required           //~va3uI~
                continue;                                          //~va3uI~
            }                                                      //~va3uI~
            if (toupper(*pci)=='D')                                //~va3uI~
            {                                                      //~va3uI~
                strcpy(pco,FMT_DT);                                //~va3uI~
                pco+=sizeof(FMT_DT)-1;                             //~va3uI~
                dtsw=1;                                            //~va3uI~
            }                                                      //~va3uI~
            if (toupper(*pci)=='T')                                //~va3uI~
            {                                                      //~va3uI~
                if (dtsw)                                          //~va3uI~
                    *pco++=' ';                                    //~va3uI~
                strcpy(pco,FMT_TM);                                //~va3uI~
                pco+=sizeof(FMT_TM)-1;                             //~va3uI~
                continue;                                          //~va3uI~
            }                                                      //~va3uI~
        }                                                          //~va3uI~
        *pco=0;                                                    //~va3uI~
    }                                                              //~va3uI~
    pts=utimeedit(fmt,0);                                          //~va3uR~
    printf("%s",pts);                                              //~va3uR~
    return;                                                        //~va3uI~
}//printnow                                                        //~va3uI~
//**********************************************************************//~va3vI~
//* display current timestamp                                      //~va3vI~
//**********************************************************************//~va3vI~
int cmdtime(char *Pcmd,int Ploop)                                  //~va3vI~
{                                                                  //~va3vI~
    int loop=1;                                                    //~va3vI~
    struct timeb tmb;                                              //~va3vI~
    long sec1,sec2,mili1,mili2,accumsec=0,accummili=0,minsec=0xffff,minmili=0,maxsec=0,maxmili=0;//~va3vR~
    long avgsec,avgmili;                                           //~va3vR~
//********************************                                 //~va3vI~
    printf("loop=%d,cmd:%s\n",Ploop,Pcmd);                         //~va3vR~
	do                                                             //~va3vI~
    {                                                              //~va3vI~
		ftime(&tmb);                                               //~va3vR~
        sec1=(long)tmb.time ;                                      //~va3vI~
        mili1=(long)tmb.millitm;                                   //~va3vR~
//printf("start %d,%d\n",sec1,mili1);                              //~va3vR~
        system(Pcmd);                                              //~va3vI~
		ftime(&tmb);                                               //~va3vR~
        sec2=(long)tmb.time ;                                      //~va3vI~
        mili2=(long)tmb.millitm;                                   //~va3vR~
//printf("end %d,%d\n",sec2,mili2);                                //~va3vR~
        if (mili2>mili1)                                           //~va3vR~
        	sec2-=sec1,mili2-=mili1;                               //~va3vI~
        else                                                       //~va3vI~
        	sec2-=sec1+1,mili2+=1000-mili1;                        //~va3vI~
        if (DWORD_COMP(sec2,mili2,minsec,minmili)<0)               //~va3vI~
        	minsec=sec2,minmili=mili2;                             //~va3vI~
        if (DWORD_COMP(sec2,mili2,maxsec,maxmili)>0)               //~va3vI~
        	maxsec=sec2,maxmili=mili2;                             //~va3vI~
		printf("loop=% 3d elapsed  %ld.%03ld sec\n",loop,sec2,mili2);//~va3vR~
        if (accummili+mili2>=1000)                                 //~va3vR~
        	accumsec+=sec2+1,accummili+=mili2-1000;                //~va3vI~
        else                                                       //~va3vI~
        	accumsec+=sec2,accummili+=mili2;                       //~va3vI~
//printf("total %d,%d\n",accumsec,accummili);                      //~va3vR~
		loop++;                                                    //~va3vR~
    } while(loop<=Ploop);                                          //~va3vI~
    if (Ploop>1)                                                   //~va3vI~
    {                                                              //~va3vI~
    	avgsec=(accumsec*1000+accummili)/Ploop/1000;               //~va3vR~
    	avgmili=(accumsec*1000+accummili)/Ploop%1000;              //~va3vR~
    	printf(" %d times total=% 3ld.%03ld, Max=% 3ld.%03ld, Min=% 3ld.%03ld, Avg=% 3ld.%03ld\n",//~va3vR~
        		Ploop,accumsec,accummili,                          //~va3vR~
        		maxsec,maxmili,minsec,minmili,avgsec,avgmili);     //~va3vI~
    }                                                              //~va3vI~
    return 0;                                                      //~va3vR~
}//cmdtime                                                         //~va3vI~
//**********************************************************************
//* write option err msg  v3.8a
//**********************************************************************
void optionerr(char *type,char* value)
{
  	uerrexit("invalid %s option parm value(%s)\n",
	  		 "%s の値(%s)の誤り\n",
			type,value);
    return;                                                        //~v1.0I~
}//optionerr

//**********************************************************************//~v1.0I~
//* write option err msg                                           //~v1.0I~
//**********************************************************************//~v1.0I~
void parmerr(char* value)                                          //~v1.0I~
{                                                                  //~v1.0I~
  	uerrexit("Invalid switch(%s)\n",                               //~v1.0I~
	  		 "パラメータの誤り(%s)\n",                             //~v1.0I~
			value);                                                //~v1.0I~
    return;                                                        //~v1.0I~
}//parmerr                                                         //~v1.0I~
                                                                   //~v1.0I~
//**********************************************************************
//* write help msg
//**********************************************************************
void help(void)
{
   uerrmsg("%s:%s:==(%c)== Set File TimeStamp ======================================",//~v1.0R~
           "%s:%s:==(%c)== ファイルのタイムスタンプの設定 ==========================",//~v1.0R~
			Spgm,Sver,OSTYPE);                                     //~v1.0I~
// uerrmsg("format:  %s filespec [ date | , ] [ time ] [ %cDdate ] [ %cTtime ] [ %c%c ]",//~va3uR~
//         "形式 :　 %s filespec [ date | , ] [ time ] [ %cDdate ] [ %cTtime ] [ %c%c ]",//~va3uR~
//  		Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va3uI~
// uerrmsg("format:  %s {filespec | %cc} [ date | , ] [ time ] [ %cDdate ] [ %cTtime ] [ %c%c ]",//~va3vR~
//         "形式 :　 %s {filespec | %cc} [ date | , ] [ time ] [ %cDdate ] [ %cTtime ] [ %c%c ]",//~va3vR~
//  		Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va3vR~
   uerrmsg("format:  %s { filespec [ date | , ] [ time ] [ %cDdate ] [ %cTtime ]",//~va3vR~
           "形式 :　 %s { filespec [ date | , ] [ time ] [ %cDdate ] [ %cTtime ]",//~va3vR~
    		Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX);                   //~va3vR~
   uerrmsg("             | %cC[fmt]",                              //~va3vR~
           "             | %cC[fmt]",                              //~va3vR~
    		     CMDFLAG_PREFIX);                                  //~va3vI~
   uerrmsg("             | %cE[n] cmd-string",                     //~va3vR~
           "             | %cE[n] cmd-string",                     //~va3vR~
    		     CMDFLAG_PREFIX);                                  //~va3vI~
   uerrmsg("             } [ %c%c ]",                              //~va3vR~
           "             } [ %c%c ]",                              //~va3vR~
    		CMDFLAG_PREFIX,CMDFLAG_PREFIX);                        //~va3vI~
   uerrmsg("    filespec = file name to be displayed or set timestamp",//~v1.0R~
//         "    filespec = タイムスタンプを設定/表示するファイル名");//~v1.0R~
           "    filespec = タイムスタンプを設定/\x95\\示するファイル名");//~v1.0I~
   uerrmsg("               wild card is available, ReadOnly file is protected",//~v1.0R~
           "               ワイルドカード指定も可, 読取専用ファイルは保護される");//~v1.0R~
   uerrmsg("               Setting to directory is available for OS/2 version only",//~v1.0R~
//         "               OS/2版でのみディレクトリーそのものの設定も可能");//~v1.0R~
           "               OS/2版でのみディレクトリーそのものの設定も可\x94\\");//~v1.0I~
   uerrmsg("    date     = (YY)yy-mm-dd or (YY)yymmdd format, 0 is abridgment of 00-00-00",//~va1aR~
           "    date     = (YY)yy-mm-dd または (YY)yymmdd 形, 0 は 00-00-00 の省略形");//~va1aR~
   uerrmsg("    time     = hh:mm:ss,hhmmss,hh:mm or hhmm format, 0 is abridgment of 00:00:00",//~v1.0R~
           "    time     = hh:mm:ss,hhmmss,hh:mm または hhmm 形式, 0 は 00:00:00 の省略形");//~v1.0R~
#ifndef UNX                                                        //~va68I~
   uerrmsg("               (ss is rounded down to even number)",   //~v1.0R~
           "               (ss は偶数に切り捨てられる)");          //~v1.0I~
#endif                                                             //~va68I~
   uerrmsg("      (if date and time is ommitted,current status is displayed)",//~v1.0R~
//         "      (date,time のどちらも指定しないとファイルのタイムスタンプを表示)");//~v1.0R~
           "      (date,time のどちらも指定しないとファイルのタイムスタンプを\x95\\示)");//~v1.0I~
   uerrmsg("    %cC[fmt]  = display current time. fmt:D, T or \\n or mixed.",//~va3vR~
           "    %cC[fmt]  = 現時刻を\x95\\示。fmt: D/T/\\n のミックス。",//~va3vR~
					CMDFLAG_PREFIX);                               //~va3vI~
   uerrmsg("               ex) %cC\\nDT\\n  %cCD. %cC means %cCT", //~va3vR~
           "               例) %cC\\nDT\\n  %cCD。%cC のみは %cCT となる。",//~va3vR~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va3vI~
   uerrmsg("    %cE[n]    = execute cmd-string, the display elapsed time. n:loop count.",//~va3vM~
           "    %cE[n]    = cmd-string を実行し経過時間を\x95\\示。",//~va3vM~
					CMDFLAG_PREFIX);                               //~va3vM~
   uerrmsg("    %c%c       = parameter end id,use for EOL clear",  //~v122R~
           "    %c%c       = パラメータの終了.コマンド行のクリアーを省略する時に使用",//~v122R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v122I~
   uerrmsg(" ex)    %s file1                      ;display file1 timestamp   ",//~v1.0R~
//         " 例)    %s file1                      ;タイムスタンプの表示",//~v1.0R~
           " 例)    %s file1                      ;タイムスタンプの\x95\\示",//~v1.0I~
			Spgm);                                                 //~v1.0I~
   uerrmsg("        %s file1 971225 12:10:12      ;set to 97-12-15 12:10:12",//~v1.0R~
           "        %s file1 971225 12:10:12      ;97-12-15 12:10:12 に設定",//~v1.0I~
			Spgm);                                                 //~v1.0I~
   uerrmsg("        %s dir%c*.* %cT1200   %cD97-12-25;set to 97-12-15 12:00:00",//~v122R~
           "        %s dir%c*.* %cT120002 %cD97-12-25;97-12-15 12:00:02 に設定",//~v122R~
			Spgm,DIR_SEPC,CMDFLAG_PREFIX,CMDFLAG_PREFIX);          //~v122R~
   uerrmsg("        %s file1 , 0120               ;change time only",//~v1.0R~
           "        %s file1 , 0120               ;時刻のみの設定",//~v1.0I~
			Spgm);                                                 //~v1.0I~
   uerrmsg("        %s dir1 %c%c 0120               ;display dir1 timestamp",//~v122R~
//         "        %s dir1 // 0120               ;ディレクトリータイムスタンプの表示",//~v1.0R~
           "        %s dir1 %c%c 0120               ;ディレクトリータイムスタンプの\x95\\示",//~v122R~
			Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX);                   //~v122R~
   uerrmsg("        %s %cE10 \"source-highlight -i xts.c >x1\" ; cmd elapsed time evaluation.",//~va3vI~
           "        %s %cE10 \"source-highlight -i xts.c >x1\" ; コマンド実行時間計測。",//~va3vI~
			Spgm,CMDFLAG_PREFIX);                                  //~va3vI~
    return;
}//help
