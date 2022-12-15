//CID://+v5kpR~:                                                   //~v5kpR~
//*************************************************************
//*ukbdpeek/ukbdcharin/ukbdsetrate/ukbdsetstate                 //~5104R~
//*************************************************************
//v5kp:070613 (BUG)repeated rctl is effective only once(need keyup)//~v5kpI~
//v148:980116 (GCC:BUG)ctrl+C terminate appl(need call __djgpp_set_ctrl_c)//~v148I~
//v147:980116 (W32)ukbdsetrate support by SystemParametersInfo API //~v147I~
//v138:980110 (W32)peek function by IO_NOWAIT(refferred kbhit)     //~v138I~
//v137:980110 (W32)split ukbdw.c from ubd ukbd.c                   //~v137I~
//v055:970118:when int 16 ah=13,al=00 or 01 is valid               //~v055I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -REGS contain flags,so no need of ukintf(asm) routine//~v053I~
//v044:961106:split uvio.c to uvio2.c(screen i/o)                  //~v044I~
//v034:961008:VisualC++ support(identify by (_MSC_VER>=800))       //~v034I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//* 950110 shift report(RCTL key support)                       //~5110R~
//* 950104 ukbdsetstate                                         //~5110I~
//************************************************************* //~5104I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
//*******************************************************
#ifdef DOS
	#include <dos.h>
    #ifdef DPMI                                                    //~v148I~
        #include <sys/exceptn.h>    //__djgpp_set_ctrl_c           //~v148I~
    #endif                                                         //~v148I~
#else
    #ifdef W32                                                     //~v022I~
    	#include <windows.h>    //SystemParametersInfo             //~v147R~
	#else                                                          //~v022I~
	#pragma stack16(8192)

	#define INCL_DOSDEVIOCTL
	#define INCL_BASE
	#include <os2.h>
	#endif                                                         //~v022I~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ukbd.h>
#ifdef W32                                                         //~v137I~
    #include <ukbdw.h>                                             //~v137I~
    #include <uedit.h>                                             //~v147I~
#endif                                                             //~v137I~
#include <uvio.h>                                                  //~v022I~
#include <uvio2.h>                                                 //~v044I~
#include <udbcschk.h>                                              //~v034I~
#include <utrace.h>                                                //~v5kpI~
//*******************************************************
#ifdef DOS                                                         //~v034I~
    static int Stypematicdelay=25;  //by 1/100 sec                 //~v5kpI~
    static int Stypematicinterval=3;  //by 1/100 sec, 3:33char/sec //~v5kpI~
#else                                                              //~v034I~
    	static int Stracesw;                                       //~v034I~
#endif                                                             //~v034I~
static KBDINFO Skbdinfo;	//save for ukbdcharin               //~5110I~
//*******************************************************
//*dummy for lib(same name as file)						*
//*******************************************************
void ukbd(void)
{
	return;
}

#ifdef DOS                                                         //~v034I~
#else                                                              //~v034I~
//**************************************************               //~v034M~
//*ukbd_traceinit                                                  //~v137R~
//*trace option set                                                //~v034M~
//*parm1:option(1;trace on,0:off)                                  //~v034M~
//*rc   :none                                                      //~v034M~
//**************************************************               //~v034M~
void ukbd_traceinit(int Popt)                                      //~v137R~
{                                                                  //~v034M~
//**************                                                   //~v034M~
    #ifdef W32                                                     //~v034I~
//      if (Stracesw && !Popt)                                     //~v137R~
//  		ukbd_w95trace("");                                     //~v137R~
        ukbd_w95traceinit(Popt);                                   //~v137I~
    #endif                                                         //~v034I~
	Stracesw=Popt;                                                 //~v034M~
}//ukbd_w95traceinit                                               //~v034M~
#endif                                                             //~v034I~
                                                                   //~v034M~
//**************************************************
//*kbdpeek
//*peek keyin
//*rc   :0:no data, 1:data exist
//**************************************************
int ukbdpeek(PKBDKEYINFO Pkeyinfo)
{
#ifdef DOS
	union 	REGS	reg;
	APIRET16 apiret16;                                             //~v138I~
#else
	KBDKEYINFO 	seg16keyinfo1;
	#ifdef W32                                                     //~v022I~
//        DWORD readctr;                                           //~v138R~
//        INPUT_RECORD inprec;                                     //~v138R~
	#else                                                          //~v022I~
		#pragma seg16(seg16keyinfo1)                               //~v022I~
        APIRET16 apiret16;                                         //~v138I~
	#endif                                                         //~v022I~
#endif
//*********************
#ifdef DOS
	memset(Pkeyinfo,0,sizeof(KBDKEYINFO));
	reg.h.ah=0x11;							//char input status
//	int86(0x16,&reg,&reg);					//ZF=0-->char exist
    #ifdef DPMI					//DPMI version                     //~v053I~
  		int86(0x16,&reg,&reg);					//ZF=0-->char exist//~v053I~
		apiret16=!(reg.x.flags & FLAGZF);                          //~v053I~
    #else                       //not DPMI                         //~v053I~
  	ukintf(&reg,&reg);						//INT16 with flag out
	apiret16=!(reg.x.cflag & FLAGZF);
    #endif                      //DPMI or not                      //~v053I~
	Pkeyinfo->chChar=reg.h.al;
	Pkeyinfo->chScan=reg.h.ah;

	reg.h.ah=0x13;							//dbcs status
//  reg.h.al=0x11;							//read                 //~v055R~
    reg.h.al=0x01;							//read                 //~v055I~
	int86(0x16,&reg,&reg);					//ZF=0-->char exist
	Pkeyinfo->bNlsShift=reg.h.dl;

	reg.h.ah=0x12;							//ext shift status
	int86(0x16,&reg,&reg);					//ZF=0-->char exist
	Pkeyinfo->fsState=reg.x.ax;

	return apiret16;
#else
	memset(&seg16keyinfo1,0,sizeof(KBDKEYINFO));
	#ifdef W32                                                     //~v022I~
//        if (!Shstdin)                                            //~v138R~
//            ukbd_w95init();                                      //~v138R~
//        apiret16=(APIRET16)PeekConsoleInput(Shstdin,             //~v138R~
//                                    &inprec,                     //~v138R~
//                                    1,          //request count  //~v138R~
//                                    &readctr);                   //~v138R~
//        if (!apiret16)              //BOOL                       //~v138R~
//            uerrapi1x("PeekConsoleInput","STD_INPUT",GetLastError());//~v138R~
//        ukbd_w95keyinfo(&inprec,Pkeyinfo,0,-1);//key record      //~v138R~
//        return readctr;                                          //~v138R~
		return ukbdcharin(Pkeyinfo,IO_NOWAIT);                     //~v138I~
    #else                                                          //~v022I~
	apiret16=KbdPeek(&seg16keyinfo1,0);
	if (apiret16)
		uerrexit("ukbdpeek:KbdPeek failed,rc=%d",
				 "ukbdpeek:KbdPeek API‚ÌŽ¸”s(rc=%d).",
				 (int)apiret16);
	*Pkeyinfo=seg16keyinfo1;
	return Pkeyinfo->chChar || Pkeyinfo->chScan;	//char or scan code
	#endif                                                         //~v022I~
#endif
}//ukbdpeek

//**************************************************
//*get keyboard input
//*wait option: 0(IO_WAIT) 1(IO_NOWAIT)
//*rc   :0:no data(NO WAIT only), 1:data exist
//**************************************************
int ukbdcharin(KBDKEYINFO *Pkeyinfo,int Pwait)
{
#ifdef DOS
static int oldfsState;	                                        //~5110I~
	union 	REGS	reg;
    int     getsw;                                              //~5110I~
//  APIRET16 apiret16;                                             //~v053R~
    int     reportsw,sstat,diff;                                   //~v5kpR~
	struct dostime_t dost0,dost;                                   //~v5kpI~
static int Srepeatsw=0;                                            //~v5kpI~
#else
	#ifdef W32                                                     //~v022M~
	#else                                                          //~v022M~
	KBDKEYINFO 	seg16keyinfo2;
	#pragma seg16(seg16keyinfo2)                                   //~v022R~
	APIRET16 apiret16;                                             //~v034M~
	#endif                                                         //~v022I~
#endif
//*********************
#ifdef DOS
	memset(Pkeyinfo,0,sizeof(KBDKEYINFO));
//UTRACEP("charin wait=%d\n",Pwait);                               //~v5kpR~
	if (Pwait==IO_NOWAIT)
		if (!ukbdpeek(Pkeyinfo))                                   //~v022R~
        	return 0;                                              //~v022I~
    if (USBITCHK(Skbdinfo.fsMask,KEYBOARD_SHIFT_REPORT))        //~5110R~
    {                                                           //~5110I~
    	reportsw=0;                                                //~v5kpR~
//UTRACEP("SHIFT REPORT\n");                                       //~v5kpR~
		for (;;)                                                //~5110I~
		{                                                       //~5110I~
//UTRACEP("loop repeatsw=%d\n",Srepeatsw);                         //~v5kpR~
//*get ext shift status	                                        //~5110I~
			reg.h.ah=0x12;							//read char //~5110I~
			int86(0x16,&reg,&reg);					//          //~5110I~
//     		if (oldfsState!=(Pkeyinfo->fsState=reg.x.ax))          //~v5kpR~
       		if (oldfsState!=(Pkeyinfo->fsState=reg.x.ax)           //~v5kpI~
            ||  reportsw==2)//timeout                              //~v5kpR~
			{                                                   //~5110I~
//UTRACEP("exit shift report sw=%d\n",reportsw);                   //~v5kpR~
				oldfsState=Pkeyinfo->fsState;                   //~5110I~
				Pkeyinfo->fbStatus=KBDTRF_SHIFT_KEY_IN;//shift report//~5110R~
				Pkeyinfo->chChar=0;                             //~5110I~
				Pkeyinfo->chScan=0;                             //~5110I~
//dbcs shift status                                             //~5110I~
				reg.h.ah=0x13;							//dbcs status//~5110I~
//  			reg.h.al=0x11;							//read     //~v055R~
			    reg.h.al=0x01;							//read     //~v055I~
				int86(0x16,&reg,&reg);					//ZF=0-->char exist//~5110I~
				Pkeyinfo->bNlsShift=reg.h.dl;                   //~5110I~
        		getsw=0;                                        //~5110I~
				break;                                          //~5110I~
			}                                                   //~5110I~
			if (ukbdpeek(Pkeyinfo))                             //~5110I~
            {                                                   //~5110I~
                getsw=1;    //issue ah=10(char read)            //~5110I~
//UTRACEP("PEEK getsw=%d\n",getsw);                                //~v5kpR~
				break;                                          //~5110I~
            }                                                   //~5110I~
    		sstat=reg.x.ax & (KBDSTF_RIGHTSHIFT                    //~v5kpM~
      								|KBDSTF_LEFTSHIFT              //~v5kpM~
      								|KBDSTF_ALT                    //~v5kpM~
                                    |KBDSTF_LEFTCONTROL            //~v5kpM~
                                    |KBDSTF_LEFTALT                //~v5kpM~
                                    |KBDSTF_RIGHTCONTROL           //~v5kpM~
                                    |KBDSTF_RIGHTALT);             //~v5kpM~
    		if (sstat==KBDSTF_RIGHTCONTROL)//RCTL only             //~v5kpR~
            {                                                      //~v5kpM~
            	if (!reportsw)	//same shift status and first time //~v5kpR~
            	{                                                  //~v5kpR~
            		reportsw=1;                                    //~v5kpR~
                	_dos_gettime(&dost0);                          //~v5kpR~
//UTRACEP("same shift time=%d:%d:%d.%d\n",dost0.hour,dost0.minute,dost0.second,dost0.hsecond);//~v5kpR~
            	}                                                  //~v5kpR~
            	else                                               //~v5kpR~
            	{                                                  //~v5kpR~
                	_dos_gettime(&dost);                           //~v5kpR~
//UTRACEP("same shift next time=%d:%d:%d.%d\n",dost.hour,dost.minute,dost.second,dost.hsecond);//~v5kpR~
                	diff=(dost.minute!=dost0.minute)*60            //~v5kpR~
                     	+dost.second-dost0.second;                 //~v5kpR~
                	diff=diff*100+dost.hsecond-dost0.hsecond;      //~v5kpR~
//UTRACEP("diff=%d\n",diff);                                       //~v5kpR~
					if (!Srepeatsw)                                //~v5kpI~
                    {                                              //~v5kpI~
	                	if (diff>Stypematicdelay)	//elapsed 0.20 sec//~v5kpI~
                        {                                          //~v5kpI~
                			reportsw=2;	//break                    //~v5kpR~
                            Srepeatsw=1;                           //~v5kpI~
                        }                                          //~v5kpI~
                    }                                              //~v5kpI~
                    else                                           //~v5kpI~
                    {                                              //~v5kpI~
	                	if (diff>Stypematicinterval)	//elapsed 0.20 sec//~v5kpI~
                			reportsw=2;	//break                    //~v5kpI~
                    }                                              //~v5kpI~
            	}                                                  //~v5kpR~
            }//RCTL only                                           //~v5kpR~
            else                                                   //~v5kpI~
            	Srepeatsw=0;                                       //~v5kpI~
		}//until shift change or key peek                       //~5110I~
    }                                                           //~5110I~
    else	//not req shift report                              //~5110I~
        getsw=1;                                                //~5110I~
//UTRACEP("getsw=%d    \n",getsw);                                 //~v5kpR~
	if (getsw)                                                  //~5110I~
    {                                                           //~5110I~
        Srepeatsw=0;                                               //~v5kpI~
		reg.h.ah=0x10;							//read char     //~5110R~
		int86(0x16,&reg,&reg);					//              //~5110R~
		Pkeyinfo->chChar=reg.h.al;                              //~5110R~
		Pkeyinfo->chScan=reg.h.ah;                              //~5110R~
   	                                                            //~5110R~
		reg.h.ah=0x13;							//dbcs status   //~5110R~
//  	reg.h.al=0x11;							//read             //~v055R~
	    reg.h.al=0x01;							//read             //~v055I~
		int86(0x16,&reg,&reg);					//-->DL         //~5110R~
		Pkeyinfo->bNlsShift=reg.h.dl;                           //~5110R~

		reg.h.ah=0x12;							//ext shift status//~5110R~
		int86(0x16,&reg,&reg);					//-->AX         //~5110R~
		Pkeyinfo->fsState=reg.x.ax;                             //~5110R~
    }                                                           //~5110I~

	return getsw;	//0 if shift report                         //~5110R~
#else
	#ifdef W32                                                     //~v022I~
//        if (Pwait==IO_NOWAIT)                                    //~v138R~
//            if (!ukbdpeek(Pkeyinfo))                             //~v138R~
//                return 0;                                        //~v138R~
		return ukbd_w95read(Pkeyinfo,Pwait);                       //~v034R~
    #else                                                          //~v022I~
	apiret16=KbdCharIn(&seg16keyinfo2,(USHORT)Pwait,0);
	if (apiret16)
		uerrexit("ukbdcharin:KbdCharIn failed,rc=%d",
				 "ukbdcharin:KbdCharIn API‚ÌŽ¸”s(rc=%d).",
				 (int)apiret16);
	*Pkeyinfo=seg16keyinfo2;
    if (Stracesw)                                                  //~v034I~
        printf("KbdCharIn:scan=%02x,char=%02x,bstat=%02x,nls=%02x,shift=%04x,time=%08x\n",//~v034R~
                         (int)seg16keyinfo2.chScan,                //~v034I~
                         (int)seg16keyinfo2.chChar,                //~v034I~
                         (int)seg16keyinfo2.fbStatus,              //~v034I~
                         (int)seg16keyinfo2.bNlsShift,             //~v034I~
                         (int)seg16keyinfo2.fsState,               //~v034I~
						 (int)seg16keyinfo2.time);                 //~v034I~
	return Pkeyinfo->chChar || Pkeyinfo->chScan;	//char or scan code
    #endif                                                         //~v022I~
#endif
}//ukbdcharin

//**************************************************
//*ukbdsetrate
//*set typamatic rate
//*parm1:continued key press delay by milisecond
//*parm2:contined key press action speed by char/second
//*rc   :0
//**************************************************
int ukbdsetrate(int Pdelay,int Pspeed)
{
#ifdef DOS
static int speedtbl[][2]={
							{2,0x1f},
							{3,0x1a},
							{4,0x17},
							{5,0x14},
							{6,0x12},
							{8,0x0f},
							{10,0x0c},
							{12,0x0a},
							{15,0x08},
							{16,0x07},
							{20,0x04},
							{24,0x02},
							{30,0x00},
							{0}
						};
	int i,delayclass,speedclass;
    int charcnt;                                                   //~v5kpI~
	union 	REGS	reg;
#else
	#ifdef W32                                                     //~v022I~
		int delayclass,speedclass;                                 //~v147R~
	#else                                                          //~v022I~
static	char *device="KBD$";
	unsigned int packet;	//speed(char/sec)+delay(milisec)
	HFILE hf;
	ULONG 	ulrc,ulact,outl=sizeof(packet);
	#endif                                                         //~v022I~
#endif
	int rc=0;                                                      //~v147I~
//***************************************
#ifdef DOS
	speedclass=0;
    charcnt=30;	//max charcnt per second                           //~v5kpI~
	for (i=0;;i++)
	{
		if (!speedtbl[i][0])
			break;
		if (Pspeed<=speedtbl[i][0])
		{
			speedclass=speedtbl[i][1];
            charcnt=speedtbl[i][0];                                //~v5kpI~
			break;
		}
	}
    Stypematicinterval=100/charcnt;  //by 1/100 sec                //~v5kpI~
                                                                   //~v5kpI~
	if (Pdelay<=250)		delayclass=0;
	else if (Pdelay<=500)	delayclass=1;
	else if (Pdelay<=750)	delayclass=2;
	else                  	delayclass=3;
	reg.x.ax=0x0305;				//kbd speed set
	reg.h.bl=(unsigned char)speedclass;
	reg.h.bh=(unsigned char)delayclass;
	int86(0x16,&reg,&reg);
    Stypematicdelay=100/(4-delayclass);  //by 1/100 sec            //~v5kpI~
//UTRACEP("parm=%d,%d, delay=%d,repeat=%d\n",Pdelay,Pspeed,Stypematicdelay,Stypematicinterval);//~v5kpR~
#else
	#ifdef W32                                                     //~v022I~
        if (Pspeed>31)                                             //~v147I~
            speedclass=31;  //31 ismost rapid,reverse of dos       //~v147R~
        else                                                       //~v147I~
        if (Pspeed<0)                                              //~v147I~
        	speedclass=0;	//0 is most slow                       //~v147R~
        else                                                       //~v147I~
        	speedclass=Pspeed;	//0 is speedest                    //~v147I~
                                                                   //~v147I~
		if (Pdelay<=250)		delayclass=0;	//shortest         //~v147R~
		else if (Pdelay<=500)	delayclass=1;   //same as dos      //~v147R~
		else if (Pdelay<=750)	delayclass=2;                      //~v147R~
		else                  	delayclass=3;   //longest          //~v147R~
        rc=0;                                                      //~v147I~
        if (!SystemParametersInfo(SPI_SETKEYBOARDDELAY,delayclass,0,0))//~v147R~
        {                                                          //~v147I~
        	uerrapi1("SystemParametersInfo:SPI_SETKEYBOARDDELAY",uitoa10(delayclass),GetLastError());//~v147R~
            rc=4;                                                  //~v147I~
		}                                                          //~v147I~
        if (!SystemParametersInfo(SPI_SETKEYBOARDSPEED,speedclass,0,0))//~v147R~
        {                                                          //~v147I~
        	uerrapi1("SystemParametersInfo:SPI_SETKEYBOARDSPEED",uitoa10(speedclass),GetLastError());//~v147R~
            rc+=4;                                                 //~v147I~
		}                                                          //~v147I~
	#else                                                          //~v022I~
	packet=(unsigned int)((Pspeed<<16)|Pdelay);
	ulrc=DosOpen(device,
				&hf,
				&ulact,
				0,	//filesize
				FILE_READONLY,	//attr
				FILE_OPEN,		//flag
				OPEN_ACCESS_READONLY|OPEN_SHARE_DENYNONE,	//mode
				NULL);
	if (ulrc)
		uerrexit("ukbdsetrate:%s DosOpen failed,rc=%d",         //~5104R~
				 "ukbdsetrate:%s DosOpen‚ÌŽ¸”s,rc=%d",          //~5104R~
                 device,ulrc);

	ulrc=DosDevIOCtl(hf,
				(ULONG)IOCTL_KEYBOARD,	//categoly
				(ULONG)KBD_SETTYPAMATICRATE,	//func
				&packet,	//	packet
				sizeof(packet),
				&outl,
				NULL,0,0);
	if (ulrc)
		uerrexit("ukbdsetrate:%s DosDevIOCtl failed,rc=%d",     //~5104R~
				 "ukbdsetrate:%s DosDevIOCtl‚ÌŽ¸”s,rc=%d",      //~5104R~
                 device,ulrc);

	ulrc=DosClose(hf);
	if (ulrc)
		uerrexit("ukbdsetrate:%s DosClose failed,rc=%d",        //~5104R~
				 "ukbdsetrate:%s DosClose ‚ÌŽ¸”s,rc=%d",        //~5104R~
                 device,ulrc);

	rc=(int)ulrc;                                                       //~v147R~
	#endif                                                         //~v022I~
#endif
	return rc;                                                     //~v147R~
}//ukbdsetrate
                                                                //~5104I~
//**************************************************            //~5104I~
//*ukbdsetstatus                                                //~5104R~
//*set kbd status(binary mode,shift report etc)                 //~5104I~
//*parm1:KBDINFO addr                                           //~5104I~
//*rc   :0 or 504(ERROR_KBD_EXTENDED_SG)                        //~5104I~
//**************************************************            //~5104I~
int ukbdsetstatus(PKBDINFO Ppkbdinfo)                           //~5104R~
{                                                               //~5104I~
#ifdef DOS                                                      //~5104I~
	int ctrlc_break_enable;                                        //~v148I~
#else                                                           //~5104I~
	#ifdef W32                                                     //~v022I~
//        UINT    mode,oldmode;                                    //~v138R~
//        USHORT  mask;                                            //~v138R~
    #else                                                          //~v022I~
	APIRET16 apiret16;                                          //~5104I~
	#endif                                                         //~v022M~
#endif                                                          //~5104I~
	int rc;                                                     //~5104I~
//***************************************                       //~5104I~
#ifdef DOS                                                      //~5104I~
    #ifdef DPMI                                                    //~v148I~
		ctrlc_break_enable=((Ppkbdinfo->fsMask & KEYBOARD_BINARY_MODE)==0);//~v148I~
        __djgpp_set_ctrl_c(ctrlc_break_enable);                    //~v148I~
    #endif                                                         //~v148I~
	rc=0;                                                       //~5104I~
#else                                                           //~5104I~
	#ifdef W32                                                     //~v022I~
//        mask=Ppkbdinfo->fsMask;                                  //~v137R~
//        mode=0;                                                  //~v137R~
//        if (mask & KEYBOARD_ECHO_ON)                             //~v137R~
//            mode|= ENABLE_ECHO_INPUT;                            //~v137R~
//        if (mask & KEYBOARD_ECHO_OFF)                            //~v137R~
//            mode&=~ENABLE_ECHO_INPUT;                            //~v137R~
//        if (mask & KEYBOARD_BINARY_MODE)                         //~v137R~
//            mode&=~ENABLE_PROCESSED_INPUT;                       //~v137R~
//        if (mask & KEYBOARD_ASCII_MODE)                          //~v137R~
//            mode|= ENABLE_PROCESSED_INPUT;                       //~v137R~
//        oldmode=usetconsolemode(mode);                           //~v137R~
//        rc=0;                                                    //~v137R~
        rc=ukbd_w95setstatus(Ppkbdinfo);                           //~v137I~
    #else                                                          //~v022I~
	apiret16=KbdSetStatus(Ppkbdinfo,0);                         //~5104I~
	if (apiret16 && apiret16!=ERROR_KBD_EXTENDED_SG)            //~5104I~
		uerrexit("KbdSetStatus failed,rc=%d",                   //~5104I~
				 "KbdSetStatus ‚ÌŽ¸”s,rc=%d",                   //~5104I~
                 (int)apiret16);                                //~5104I~
                                                                //~5104I~
	rc=(int)apiret16;                                           //~5104I~
	#endif                                                         //~v022I~
#endif                                                          //~5104I~
	if (!rc)                                                    //~5104I~
		Skbdinfo=*Ppkbdinfo;                                    //~5104I~
UTRACEP("%s:skbdinf.fsmask=%x\n",UTT,Skbdinfo.fsMask);             //+v5kpR~
	return rc;                                                  //~5104R~
}//ukbdsetstatus                                                //~5104R~
