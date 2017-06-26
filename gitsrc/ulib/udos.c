//CID://+v188R~:                                                   //+v188R~
//*************************************************************
//*udos.c
//*************************************************************
//v188:980727 Windows98,iswin98 for kbdw                           //+v188R~
//v162:980202 iswin,iswinnt,isos2 for other version                //~v162I~
//v159:980131 udosisos2   for DOS(chk env string "\MDOS\" in comspec)//~v159I~
//v158:980131 udosiswinnt for DOS(chk env OS=Windows_NT)           //~v158I~
//v136:980103 (W32)WINNT support                                   //~v136I~
//            -udosiswinnt func   udos.c/h ualloc.c                //~v136I~
//v133:971221 for Win/NT;malloc logic                              //~v133I~
//v075:970420 (DOS/GCC)udpmi_version support                       //~v075I~
//v074:970420 (OS2)uharederr support(disable or enable popup)      //~v074I~
//v073:970420 (GCC)_harderr,_hardresume support                    //~v073R~
//v072:970413:no need to use _get_dos_version.(use intdos ah=30h for bh,//~v072R~
//            no need to chk cflag)                                //~v072I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -lack of _dos_getvect                                //~v053I~
//v052:961205:win version                                          //~v052I~
//v039:961026:add udos.c(at first udos_version)                    //~v039I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <direct.h>
#include <errno.h>
#include <io.h>
//*******************************************************
#ifdef DOS
	#include <dos.h>
    #ifdef DPMI					//DPMI version                     //~v075I~
    	#include <dpmi.h>                                          //~v075I~
    #else                       //not DPMI                         //~v075I~
    #endif                      //DPMI or not                      //~v075I~
#else
	#ifdef W32
    	#include <windows.h>    //GetVersion                       //~v133R~
	#else
    	#define INCL_BASE                                          //~v039R~
    	#include <os2.h>                                           //~v039R~
	#endif
#endif

//*******************************************************
#include <ulib.h>
#include <udos.h>                                                  //~v052R~
#include <uerr.h>                                                  //~v052I~
#include <uedit.h>                                                 //~v074I~
#include <ustring.h>                                               //~v159I~
#ifdef DOS                                                         //~v053I~
    #ifdef DPMI					//DPMI version                     //~v053I~
		#include <udpmisub.h>                                      //~v053I~
    #else                       //not DPMI                         //~v053I~
    #endif                      //DPMI or not                      //~v053I~
#endif                                                             //~v053I~
                                                                   //~v053I~
#ifdef DOS                                                         //~v052I~
	static int Sharderropt;                                        //~v052I~
#endif                                                             //~v052I~
//*******************************************************
//*dummy for lib(same name as file)						*
//*******************************************************
void udos(void)
{
	return;
}

//*******************************************************
//*get os version                                                  //~v039R~
//*parm 1:major version output area                                //~v039R~
//*parm 2:minor version output area                                //~v039I~
//*parm 3:other information output area                            //~v039R~
//*       DOS:1 byte ROM option, 0:not on ROM,8:on ROM             //~v039R~
//*       OS2:int revision letter                                  //~v039I~
//*       Win:int revision letter,bit0 is off if NT                //~v133I~
//*******************************************************
int udos_version(int *Ppmaj,int *Ppmin,void *Ppinfo)
{
#ifdef DOS
//  #ifdef DPMI					//DPMI version                     //~v072R~
//      int ver;                                                   //~v072R~
//  #else                       //not DPMI                         //~v072R~
	union 	REGS	reg;
//  #endif                      //DPMI or not                      //~v072R~
#else
    #ifdef W32
        DWORD dwvno;                                               //~v133I~
    #else
    	APIRET apiret;
        ULONG  buffsz;                                             //~v039I~
        int    buff[3];                                            //~v039I~
    #endif
#endif
//**************************************
#ifdef DOS
//  #ifdef DPMI					//DPMI version                     //~v072R~
//      ver=_get_dos_version(1);    //true version not efected set VER//~v072R~
//      *Ppmaj=(ver>>8);                                           //~v072R~
//      *Ppmin=(ver & 255);                                        //~v072R~
//  	*(char*)Ppinfo=0;                                          //~v072R~
//  #else                       //not DPMI                         //~v072R~
	reg.h.ah=0x30;					//get version
	intdos(&reg,&reg);				//set cursor pos
//  if (reg.x.cflag)				//carry                        //~v072R~
//  	return uerrapi1("intdos","AH=30h(DOS version)",4);         //~v072R~
    *Ppmaj=reg.h.al;
    *Ppmin=reg.h.ah;
	*(char*)Ppinfo=reg.h.bh;	//0:not on ROM,8:on ROM            //~v039R~
//  #endif                      //DPMI or not                      //~v072R~
    return 0;                                                      //~v039I~
#else
    #ifdef W32
        dwvno=GetVersion();      	//80000000 on if not NT,buldno(2)+min+maj//~v133I~
        *Ppmaj=(dwvno & 255);                                      //~v133R~
        *Ppmin=((dwvno>>8) & 255);                                 //~v133R~
		*(int*)Ppinfo=dwvno;		//with revision                //~v133I~
    	return 0;                                                  //~v039I~
    #else
        buffsz=sizeof(buff);                                       //~v039I~
        apiret=DosQuerySysInfo(QSV_VERSION_MAJOR,QSV_VERSION_REVISION,buff,buffsz);//~v039I~
        if (apiret)                                                //~v039I~
			return uerrapi1("DosQuerySysInfo","Version Information",(int)apiret);//~v039R~
	    *Ppmaj=buff[0];       		//major                        //~v039I~
    	*Ppmin=buff[1];             //minor                        //~v039I~
		*(int*)Ppinfo=buff[2];		//revision                     //~v039I~
    	return 0;                                                  //~v039I~
    #endif
#endif                                                             //~v039I~
}//udos_version
                                                                   //~v052I~
#ifdef DOS                                                         //~v052I~
//*******************************************************          //~v075I~
//*get dpmi version for DOS and GCC                                //~v075I~
//*parm 1:output structure(optional)                               //~v075I~
//*return:version(major*100+min) or 0 not supported                //~v075I~
//*******************************************************          //~v075I~
int udpmi_version(UDPMIVER *Pdpmiver)                              //~v075I~
{                                                                  //~v075I~
#ifdef DPMI					//DPMI version                         //~v075I~
    __dpmi_version_ret dpmiver;                                    //~v075I~
#else                       //not DPMI                             //~v075I~
	union 	REGS	reg;                                           //~v075I~
#endif                      //DPMI or not                          //~v075I~
	int rc;                                                        //~v075I~
//**************************************                           //~v075I~
#ifdef DPMI					//DPMI version                         //~v075I~
	__dpmi_get_version(&dpmiver);	//always rc=0                  //~v075I~
    rc=dpmiver.major*100+dpmiver.minor;                            //~v075I~
    if (Pdpmiver)                                                  //~v075I~
    	memcpy(Pdpmiver,&dpmiver,sizeof(UDPMIVER));                //~v075I~
#else                       //not DPMI                             //~v075I~
    reg.x.ax=0x1687;		//obtain switch entry                  //~v075I~
    int86(0x2f,&reg,&reg);                                         //~v075I~
    if (reg.x.ax)			//fail                                 //~v075I~
    	rc=0;                                                      //~v075I~
	else                                                           //~v075I~
    {                                                              //~v075I~
        rc=reg.h.dh*100+reg.h.dl;                                  //~v075R~
        if (Pdpmiver)                                              //~v075R~
        {                                                          //~v075R~
        	Pdpmiver->major=reg.h.dh;                              //~v075R~
        	Pdpmiver->minor=reg.h.dl;                              //~v075R~
        	Pdpmiver->flags=reg.x.bx;                              //~v075R~
        	Pdpmiver->cpu=reg.h.cl;                                //~v075R~
        	Pdpmiver->master_pic=0;     //not supported            //~v075R~
        	Pdpmiver->slave_pic=0;      //not supported            //~v075R~
        }                                                          //~v075R~
    }                                                              //~v075I~
#endif                      //DPMI or not                          //~v075I~
	return rc;                                                     //~v075I~
}//udpmi_version                                                   //~v075I~
                                                                   //~v075I~
//*******************************************************          //~v052I~
//*get win version(original is unautorized windows is_win function)//~v052I~
//*parm 1:major version output area                                //~v052I~
//*parm 2:minor version output area                                //~v052I~
//*parm 3:mode output; 2:standard,3:enhanced                       //~v052I~
//*return:1:win is running,0:win is not running                    //~v052I~
//*******************************************************          //~v052I~
int uwin_version(int *pmaj,int *pmin,int *pmode)                   //~v052I~
{                                                                  //~v052I~
#ifdef DPMI					//DPMI version                         //~v053I~
	union 	REGS	reg;                                           //~v053I~
#else                       //not DPMI                             //~v053I~
#endif                      //DPMI or not                          //~v053I~
    unsigned short retval;                                         //~v052I~
    int maj=0, min=0, mode=0;                                      //~v052I~
int detect_switcher(void);                                         //~v052I~
//**************************************                           //~v052I~
    /* make sure someone, anyone has INT 2Fh */                    //~v052I~
    if (_dos_getvect(0x2F) == 0)                                   //~v052I~
        return 0;                                                  //~v052I~
                                                                   //~v052I~
    /* call 2F/160A to see if Windows 3.1+ */                      //~v052I~
#ifdef DPMI					//DPMI version                         //~v053I~
    reg.x.ax=0x160a;                                               //~v053R~
    int86(0x2f,&reg,&reg);                                         //~v053I~
    retval=reg.x.ax;                                               //~v053R~
#else                       //not DPMI                             //~v053I~
    _asm mov ax, 160ah                                             //~v052I~
    _asm int 2fh                                                   //~v052I~
    _asm mov retval, ax                                            //~v052I~
#endif                      //DPMI or not                          //~v053I~
    if (retval == 0)                /* AX=0 if Windows running */  //~v052I~
    {                                                              //~v052I~
#ifdef DPMI					//DPMI version                         //~v053I~
    	mode=reg.x.cx;                                             //~v053R~
    	maj=reg.h.bh;                                              //~v053I~
    	min=reg.h.bl;                                              //~v053I~
#else                       //not DPMI                             //~v053I~
        _asm mov mode, cx           /* CX=2 means Std; CX=3 means Enh *///~v052I~
        _asm mov byte ptr maj, bh   /* BX = major/minor (e.g., 030Ah) *///~v052I~
        _asm mov byte ptr min, bl                                  //~v052I~
#endif                      //DPMI or not                          //~v053I~
        *pmaj = maj;                                               //~v052I~
        *pmin = min;                                               //~v052I~
        *pmode = mode;                                             //~v052I~
        return 1;                                                  //~v052I~
    }                                                              //~v052I~
                                                                   //~v052I~
    /* call 2F/1600 to see if Windows 3.0 Enhanced mode or Windows/386 *///~v052I~
#ifdef DPMI					//DPMI version                         //~v053I~
    reg.x.ax=0x1600;                                               //~v053R~
    int86(0x2f,&reg,&reg);                                         //~v053I~
	maj=reg.h.al;                                                  //~v053I~
	min=reg.h.ah;                                                  //~v053I~
#else                       //not DPMI                             //~v053I~
    _asm mov ax, 1600h                                             //~v052I~
    _asm int 2fh                                                   //~v052I~
    _asm mov byte ptr maj, al                                      //~v052I~
    _asm mov byte ptr min, ah                                      //~v052I~
#endif                                                             //~v053I~
    if ((maj == 1) || (maj == 0xFF))    /* Windows/386 2.x is running *///~v052I~
    {                                                              //~v052I~
        *pmaj = 2;              /* Windows/386 2.x */              //~v052I~
        *pmin = 1;              /* don't know; assume 2.1? */      //~v052I~
        *pmode = ENHANCED_MODE; /* Windows/386 sort of like Enhanced *///~v052I~
        return 1;                                                  //~v052I~
    }                                                              //~v052I~
    else if (! ((maj == 0) || (maj == 0x80))) /* AL=0 or 80h if no Windows *///~v052I~
    {   /* must be Windows 3.0 Enhanced mode */                    //~v052I~
        *pmaj = maj;                                               //~v052I~
        *pmin = min;                                               //~v052I~
        *pmode = ENHANCED_MODE;                                    //~v052I~
        return 1;                                                  //~v052I~
    }                                                              //~v052I~
                                                                   //~v052I~
    /* call 2F/4680 to see if Windows 3.0 Standard or Real mode; but,//~v052I~
       this could be a "3.0 derivative" such as DOSSHELL task switcher! *///~v052I~
#ifdef DPMI					//DPMI version                         //~v053I~
    reg.x.ax=0x4680;                                               //~v053R~
    int86(0x2f,&reg,&reg);                                         //~v053I~
	retval=reg.x.ax;                                               //~v053I~
#else                       //not DPMI                             //~v053I~
    _asm mov ax, 4680h                                             //~v052I~
    _asm int 2fh                                                   //~v052I~
    _asm mov retval, ax                                            //~v052I~
#endif                                                             //~v053I~
    if (retval == 0)            /* AX=0 if 2F/4680 handled */      //~v052I~
    {                                                              //~v052I~
        /* make sure it isn't DOSSHELL task switcher */            //~v052I~
        if (detect_switcher())                                     //~v052I~
            return 0;                                              //~v052I~
        *pmaj = 3;                                                 //~v052I~
        *pmin = 0;                                                 //~v052I~
                                                                   //~v052I~
        /* either have Windows Standard mode or Real mode; to      //~v052I~
           distinguish, have to do fake Windows broadcasts with    //~v052I~
           2F/1605.  Yuk!  We'll avoid that here by assuming       //~v052I~
           3.0 Standard mode.  If you really want to distinguish   //~v052I~
           3.0 Standard mode and Real mode, see _MSJ_, March 1991, //~v052I~
           p. 113; and MS KB articles Q75943 and Q75338 */         //~v052I~
        *pmode = STANDARD_MODE;                                    //~v052I~
        return 1;                                                  //~v052I~
    }                                                              //~v052I~
                                                                   //~v052I~
    /* still here -- must not be running Windows */                //~v052I~
    return 0;                                                      //~v052I~
}//uwin_version                                                    //~v052I~
//**************************************************************** //~v052I~
int detect_switcher(void)                                          //~v052I~
{                                                                  //~v052I~
    int retval = 1;                                                //~v052I~
#ifdef DPMI					//DPMI version                         //~v053I~
	union REGS reg;                                                //~v053I~
	struct SREGS sreg;                                             //~v053R~
#else                       //not DPMI                             //~v053I~
#endif                      //DPMI or not                          //~v053I~
//*****************                                                //~v053I~
#ifdef DPMI					//DPMI version                         //~v053I~
	reg.x.bx=0;                                                    //~v053I~
	reg.x.di=0;                                                    //~v053I~
    sreg.es=0;                                                     //~v053R~
    reg.x.ax=0x4b02;                                               //~v053I~
    udpmiint86s(0x2f,&reg,&reg,&sreg);                             //~v053R~
    if (sreg.es | reg.x.di)                                        //~v053R~
    	retval=0;	                                               //~v053I~
	return retval;                                                 //~v053I~
#else                       //not DPMI                             //~v053I~
    _asm push di                                                   //~v052I~
    _asm push es                                                   //~v052I~
    _asm xor bx, bx                                                //~v052I~
    _asm mov di, bx                                                //~v052I~
    _asm mov es, bx                                                //~v052I~
    _asm mov ax, 4b02h                                             //~v052I~
    _asm int 2fh                                                   //~v052I~
    _asm mov cx, es                                                //~v052I~
    _asm or cx, di                                                 //~v052I~
    _asm je no_switcher                                            //~v052I~
done:                                                              //~v052I~
    _asm pop es                                                    //~v052I~
    _asm pop di                                                    //~v052I~
    return retval;                                                 //~v052I~
no_switcher:                                                       //~v052I~
    retval = 0;                                                    //~v052I~
    goto done;                                                     //~v052I~
#endif                      //DPMI or not                          //~v053I~
}                                                                  //~v052I~
#endif //DOS                                                       //~v074I~
                                                                   //~v052I~
//#ifdef DPMI					//DPMI version                     //~v073R~
#ifdef W32                                                         //~v073I~
#else                       //not win                              //~v073R~
//*******************************************************          //~v052I~
//*uharderr                                                        //~v052I~
//*faital err routine setup                                        //~v052I~
//*parm 1:Abort option,0:return fail to api,1:abort appl           //~v052I~
//*      (GCC only)   -1:reset previos setup                       //~v073I~
//*      (OS/2)        0:return fail to api,1:popup                //~v074I~
//*******************************************************          //~v052I~
void uharderr(int Pabortopt)                                       //~v052I~
{                                                                  //~v052I~
#ifdef DOS                                                         //~v074I~
void uharderrfunc(USHORT deverr,USHORT errcode,char *hdr);         //~v073R~
#else                                                              //~v074I~
    APIRET apiret;                                                 //~v074I~
    ULONG  opt;                                                    //~v074I~
#endif                                                             //~v074I~
//***********************                                          //~v052I~
#ifdef DOS                                                         //~v074I~
	Sharderropt=Pabortopt;                                         //~v052I~
    #ifdef DPMI					//DPMI version                     //~v073I~
    	if (Pabortopt==-1)		//reset req                        //~v073I~
        	return _harderr((FUNC24)0);	//reset int24              //~v073R~
    #else                       //not DPMI                         //~v073I~
    #endif                      //DPMI or not                      //~v073I~
	 _harderr(uharderrfunc);                                       //~v052I~
#else                                                              //~v074I~
    switch(Pabortopt)                                              //~v074I~
    {                                                              //~v074I~
    case 0:                                                        //~v074I~
        opt=FERR_DISABLEHARDERR;                                   //~v074I~
        break;                                                     //~v074I~
    case 1:                                                        //~v074I~
        opt=FERR_ENABLEHARDERR;                                    //~v074I~
        break;                                                     //~v074I~
    default:                                                       //~v074I~
        opt=FERR_ENABLEHARDERR;                                    //~v074I~
    }                                                              //~v074I~
    if (apiret=DosError(opt),apiret)                               //~v074I~
    	uerrapi1x("DosError",uitoa10((int)opt),(int)apiret);       //~v074R~
#endif                                                             //~v074I~
	return;                                                        //~v074I~
}//uharderr                                                        //~v052I~
                                                                   //~v052I~
#ifdef DOS                                                         //~v074I~
//*******************************************************          //~v052I~
//*uharderrfunc                                                    //~v074R~
//*faital err routine setup                                        //~v052I~
//*parm 1:deverr                                                   //~v052I~
//*parm 2:errcode(lower byte) 0:write protect,2:drive not ready,8 selecter not found etc//~v052I~
//*******************************************************          //~v052I~
void uharderrfunc(USHORT deverr,USHORT errcode,char *hdr)          //~v073I~
{                                                                  //~v052I~
//***********************                                          //~v052I~
    switch(Sharderropt)                                            //~v052R~
    {                                                              //~v052I~
    case 0:                                                        //~v052I~
    	_hardresume(_HARDERR_FAIL);                                //~v052I~
        break;                                                     //~v052I~
    case 1:                                                        //~v052I~
    	_hardresume(_HARDERR_ABORT);                               //~v052I~
        break;                                                     //~v052I~
    }                                                              //~v052I~
    return;                                                        //~v052I~
} //harderrfunc                                                    //~v052I~
#endif //DOS                                                       //~v052R~
#endif                      //win or not                           //~v073I~
                                                                   //~v136I~
//*******************************************************          //~v162I~
//*udosiswin                                                       //~v162I~
//*return true if os is win(include winnt)                         //~v162R~
//*parm :none                                                      //~v162I~
//*return: 1:win 0:not windows                                     //~v162I~
//*******************************************************          //~v162I~
int udosiswin(void)                                                //~v162I~
{                                                                  //~v162I~
#ifdef DOS                                                         //~v162I~
	int dummy;                                                     //~v162I~
//********                                                         //~v162I~
	return (uwin_version(&dummy,&dummy,&dummy)                     //~v162R~
			||udosiswinnt());                                      //~v162R~
#else			//win                                              //~v162I~
	#ifdef W32                                                     //~v162I~
    	return 1;                                                  //~v162I~
	#else       //os2                                              //~v162I~
    	return 0;                                                  //~v162I~
	#endif                                                         //~v162I~
#endif                                                             //~v162I~
}//udosiswin                                                       //~v162I~
                                                                   //~v162I~
#ifdef W32                                                         //+v188R~
//*******************************************************          //+v188R~
//*udosiswin                                                       //+v188R~
//*return true if os is win(include winnt)                         //+v188R~
//*parm :none                                                      //+v188R~
//*return: 1:win 0:not windows                                     //+v188R~
//*******************************************************          //+v188R~
int udosiswin98(void)                                              //+v188R~
{                                                                  //+v188R~
static char S98sw[2];                                              //+v188R~
	int maj,min,rev;                                               //+v188R~
//********                                                         //+v188R~
	if (!S98sw[0])                                                 //+v188R~
    {                                                              //+v188R~
    	S98sw[0]=1;                                                //+v188R~
		udos_version(&maj,&min,&rev);                              //+v188R~
		S98sw[1]=(char)((maj==4 && min>=10) && !udosiswinnt());    //+v188R~
	}                                                              //+v188R~
    return (int)S98sw[1];                                          //+v188R~
}//udosiswin98                                                     //+v188R~
#endif                                                             //+v188R~
                                                                   //+v188R~
//#ifdef W32                                                       //~v158R~
//*******************************************************          //~v136I~
//*udosiswinnt                                                     //~v136I~
//*return true if os is winnt                                      //~v136I~
//*parm :none                                                      //~v136I~
//*return: 1:winnt 0:win95                                         //~v136I~
//*******************************************************          //~v136I~
int udosiswinnt(void)                                              //~v136I~
{                                                                  //~v136I~
#if defined(DOS) || defined(W32)                                   //~v162M~
static char Sntsw[2];                                              //~v136I~
#ifdef DOS                                                         //~v158I~
	char *pc;                                                      //~v158I~
#else			//win                                              //~v158I~
    int vno;                                                       //~v136I~
#endif                                                             //~v158I~
//***********************                                          //~v136I~
	if (!Sntsw[0])	//first sw	                                   //~v136I~
    {                                                              //~v136I~
    	Sntsw[0]=1;                                                //~v136I~
#ifdef DOS                                                         //~v158I~
		pc=getenv("OS");                                           //~v158I~
        Sntsw[1]=(pc && !stricmp(pc,"Windows_NT"));                //~v158R~
#else			//win                                              //~v158I~
    	udos_version(&vno,&vno,&vno);	//3rd parm(dword info) is set last;//~v136I~
    	Sntsw[1]=(vno>0);	//bit 0 on for win32s/win95 off for nt //~v136I~
#endif                                                             //~v158I~
    }                                                              //~v136I~
    return (int)Sntsw[1];                                          //~v136I~
#else       //os2                                                  //~v162I~
    return 0;                                                      //~v162I~
#endif                      //win or not                           //~v162M~
}//udosiswinnt                                                     //~v136I~
                                                                   //~v159I~
//*******************************************************          //~v159I~
//*udosisos2                                                       //~v159I~
//*return true if os is os2 DOS session                            //~v159I~
//*parm :none                                                      //~v159I~
//*return: 1:OS/2  0:not OS/2                                      //~v159I~
//*******************************************************          //~v159I~
int udosisos2(void)                                                //~v159I~
{                                                                  //~v159I~
#ifdef DOS                                                         //~v162M~
static char Sos2sw[2];                                             //~v159I~
	char *pc;                                                      //~v159I~
//***********************                                          //~v159I~
	if (!Sos2sw[0])	//first sw                                     //~v159I~
    {                                                              //~v159I~
    	Sos2sw[0]=1;                                               //~v159I~
		pc=getenv("COMSPEC");                                      //~v159I~
        Sos2sw[1]=(pc && ustrstri(pc,"\\MDOS\\"));                 //~v159I~
    }                                                              //~v159I~
    return (int)Sos2sw[1];                                         //~v159I~
#else                                                              //~v162I~
    #ifdef W32                                                     //~v162I~
        return 0;   //win version                                  //~v162I~
    #else                                                          //~v162I~
        return 1;   //os2 version                                  //~v162I~
    #endif                                                         //~v162I~
#endif                      //win or not                           //~v162M~
}//udosisos2                                                       //~v187R~
