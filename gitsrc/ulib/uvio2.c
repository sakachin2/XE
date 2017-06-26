//CID://+v6BiR~:       update#=     121                            //+v6BiR~
//*************************************************************
//v6Bi:160212 (W32)compiler warning                                //+v6BiI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v5fh:050125 (W32)window should be at current last of consolebuff //~v5fhI~
//v570:020824 wxe support                                          //~v570I~
//v252:990626 (Win):for redirect;Once create console buff and then get inf befre destroy//~v252I~
//v156:980126 ugetconhwnd:get console appl HWND                    //~v156I~
//v151:980119 (BUG:DOS/GCC)video buff direct write determined by not dbcs env//~v151M~
//            but video mode.video buff chk by int 10 ah=FE        //~v151M~
//            (none is displayed under os2 dos session when changed chev us)//~v151M~
//v056:970119:for int10 ah=0e(tty write),not needed INT10X,INT10 is sufficiant.//~v056I~
//v053:970406:gcc version(control by DPMI)                         //~v053I~
//            -short size ont equal int size                       //~v053I~
//v044:961106:too large for XEDOS,split uvio.c to uvio2.c          //~v044I~
//v043:961104:(W95)write attr string function support              //~v043I~
//v042:961102:(W95)write all line to screen by one api issue for performance//~v042I~
//v034:961008:VC support(identify by (_MSC_VER>=800))              //~v034I~
//           .scroll function not usefull for clear screen         //~v034R~
//            (dest position must not negative,so need twice half scroll)//~v034I~
//           .WriteConsoleOutput is not effective when full-screen mode//~v034I~
//            Output can be seen after when change active screen buffer//~v034I~
//            to another and returned.                             //~v034I~
//            (so use WriteConsoleOutputCharacter and WriteConsoleOutputAttribute)//~v034I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//*ugetstdhandle                                                   //~v044I~
//*uviogetcurtype/uviogetcurpos                                    //~v044R~
//*uviosetcurtype/uviosetcurpos                                    //~v044R~
//*uviowrttty                                                      //~v043I~
//*uviogetstate/uviosetsate
//*uvioscrolldn(back)/uvioscrollup(forward)                     //~5222I~
//*************************************************************
//v015:960211:(BUG)uviowrttty advance char ptr for DOS          //~6212I~
//951001:malloc uvio work at init(uvio_init,uvio_term)          //~5A01I~
//950930:malloc/calloc rc chk for dos                           //~5930I~
//*950513 write direct to b800 when english display mode 3      //~5513I~
//*       (int10 ax=1302 cause scroll up when write to row 25 col 80)//~5513I~
//*950222 scroll down/up                                        //~5222R~
//*941221 int 10 ax=1302 for english mode not but 1320          //~5222I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
#ifdef DOS
	#include <dos.h>                                               //~v022R~
    #ifdef DPMI                                                    //~v151I~
    	#include <dpmi.h>                                          //~v151I~
    	#include <go32.h>                                          //~v151I~
    #endif                                                         //~v151I~
#else
	#ifdef W32                           //v3.6a                   //~v022M~
		#include <windows.h>	         //v1.3 add                //~v022M~
	#else                                //v3.6a                   //~v022M~
		#define INCL_BASE                                          //~v022R~
		#include <os2.h>                                           //~v022R~
    	#pragma stack16(8192)                                      //~v034I~
	#endif                                                         //~v022M~
#endif
//*******************************************************
#include <ulib.h>                                                  //~v022R~
#include <uvio.h>
#include <uvio2.h>                                                 //~v044I~
#include <ustring.h>                                               //~v044I~
#include <uedit.h>                                                 //~v044I~
#include <uerr.h>                                                  //~v022I~
#include <utrace.h>                                                //~v151I~
#ifdef DPMI                                                        //~v151I~
	#include <udpmisub.h>	//udpmiint86x                          //~v151I~
#endif                                                             //~v151I~
#ifdef WXE                                                         //~v570I~
	#include <wxexei.h>     //ukbd_w95init                         //~v570I~
#endif                                                             //~v570I~
//*******************************************************
//*******************************************************
#ifdef DOS
	static	union 	REGS	Sreg;
    static	struct 	SREGS 	Ssegreg;                               //~v151R~
#else                                                              //~v022I~
	#ifdef W32                           //v3.6a                   //~v022I~
		static 	HANDLE  Shconout;		 //std  output console handle//~v022I~
		static 	int     Stoplineoffs;    //window top line in consolebuff//~v5fhI~
	#else                                //v3.6a                   //~v022I~
	#endif                                                         //~v022I~
#endif
//*******************************************************
//*dummy for lib(same name as file)						*
//*******************************************************
void uvio2(void)                                                   //~v044R~
{
	return;
}

#ifdef W32                                                         //~v044M~
                                                                   //~v044I~
//*******************************************************          //~v044I~
//*init,receive handle from uvio                                   //~v044I~
//*parm1:stdout handle                                             //~v044I~
//*ret  :none                                                      //~v044I~
//*******************************************************          //~v044I~
//void uvio2_init(HANDLE Phconout)                                 //~v5fhR~
void uvio2_init(HANDLE Phconout,int Ptoplineoffs)                  //~v5fhI~
{                                                                  //~v044I~
	Shconout=Phconout;                                             //~v044I~
	Stoplineoffs=Ptoplineoffs;                                     //~v5fhI~
	return;                                                        //~v044I~
}//uvio2_init                                                      //~v044R~
//*******************************************************          //~v022M~
//*get win95 console handle                                        //~v022M~
//*parm  :id(STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STR_ERROR_HANDLE)  //~v022M~
//*return:handle                                                   //~v022M~
//*******************************************************          //~v022M~
HANDLE ugetstdhandle(int Pid)                                      //~v022R~
{                                                                  //~v022M~
    HANDLE h;                                                      //~v022I~
//**********************                                           //~v022M~
    h=GetStdHandle(Pid);                                           //~v022R~
    if (h==INVALID_HANDLE_VALUE)                                   //~v022I~
		uerrapi1x("GetStdHandle",uitoa10(Pid),GetLastError());     //~v022R~
    return h;                                                      //~v022I~
}//ugetstdhandle                                                   //~v022I~
                                                                   //~v252I~
//*******************************************************          //~v252I~
//*get CreateConsoleScreenBuffer                                   //~v252I~
//*parm  :opt	1:issue errmsg                                     //~v252I~
//*return:handle                                                   //~v252I~
//*******************************************************          //~v252I~
HANDLE uviowincreatecsb(int Popt)                                  //~v252I~
{                                                                  //~v252I~
	HANDLE csbh;                                                   //~v252I~
//********                                                         //~v252I~
    csbh=CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,   //~v252I~
                 FILE_SHARE_READ | FILE_SHARE_WRITE,               //~v252I~
                 NULL,                                             //~v252I~
                 CONSOLE_TEXTMODE_BUFFER,                          //~v252I~
                 NULL);                                            //~v252I~
    if (csbh==INVALID_HANDLE_VALUE)                                //~v252I~
    	if (Popt)                                                  //~v252I~
        	printf("CreateConsoleScreenBuffer failed,LastError=%d",GetLastError());//~v252I~
	return csbh;                                                   //~v252I~
}//uviowincreatecsb                                                //~v252I~
#endif                                                             //~v022M~
                                                                   //~v022I~
//*******************************************************
//*VioGetCurPos
//*******************************************************
UINT uviogetcurpos (int *Pprow,int *Ppcol)
{
#ifdef DOS
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifndef WXE                                                  //~v570I~
    	CONSOLE_SCREEN_BUFFER_INFO csbi;                           //~v022I~
		APIRET16 apiret16;                                         //~v022I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	USHORT seg16usrow,seg16uscol;
	#pragma seg16(seg16usrow)
	#pragma seg16(seg16uscol)
	APIRET16 apiret16;
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	Sreg.h.bh=0;		//page no
	INT10(0x03);		//read cursor position
	*Pprow=Sreg.h.dh;
	*Ppcol=Sreg.h.dl;
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
        return (UINT)wxe_getcurpos(Pprow,Ppcol);                   //~v570I~
      #else  //!WXE                                                //~v570I~
    	apiret16=(APIRET16)!GetConsoleScreenBufferInfo(Shconout,&csbi);//true/false//~v022R~
		*Ppcol=(int)csbi.dwCursorPosition.X;                       //~v022I~
//  	*Pprow=(int)csbi.dwCursorPosition.Y;                       //~v5fhR~
    	*Pprow=(int)(csbi.dwCursorPosition.Y-Stoplineoffs);        //~v5fhI~
		return (UINT)apiret16;                                     //~v022I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	apiret16=VioGetCurPos(&seg16usrow,&seg16uscol,0);
	*Pprow=(int)seg16usrow;
	*Ppcol=(int)seg16uscol;
	return (UINT)apiret16;
	#endif                                                         //~v022I~
#endif
}//uviogetcurpos

//*******************************************************
//*VioSetCurPos
//*******************************************************
UINT uviosetcurpos (int Prow,int Pcol)
{
#ifdef DOS
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
      #ifndef WXE                                                  //~v570I~
    	COORD coord;                                               //~v022R~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	Sreg.h.bh=0;					//page no
	Sreg.h.dh=(UCHAR)Prow;
	Sreg.h.dl=(UCHAR)Pcol;
	INT10(0x02);					//set cursor pos
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
        return (UINT)wxe_setcurpos(Prow,Pcol);                     //~v570I~
      #else  //!WXE                                                //~v570I~
    	coord.X=(SHORT)Pcol;                                       //~v022R~
//  	coord.Y=(SHORT)Prow;                                       //~v5fhR~
    	coord.Y=(SHORT)(Prow+Stoplineoffs);                        //~v5fhI~
        return !SetConsoleCursorPosition(Shconout,coord);          //~v022I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
   return (UINT)VioSetCurPos((USHORT)Prow,(USHORT)Pcol,0);
	#endif                                                         //~v022I~
#endif
}//uviosetcurpos                                                   //~v022R~

//*******************************************************
//*VioGetCurType
//*******************************************************
UINT uviogetcurtype(PVIOCURSORINFO pvioCursorInfo)
{
#ifdef DOS
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifndef WXE                                                  //~v570I~
    	CONSOLE_CURSOR_INFO cci;                                   //~v022I~
		APIRET16 rc16;                                             //~v022I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	VIOCURSORINFO 	seg16cursorinfo1;
	#pragma seg16(seg16cursorinfo1)
	APIRET16 rc16;
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	Sreg.h.bh=0;		//page no
	INT10(0x03);		//read cursor position
	pvioCursorInfo->yStart	=(USHORT)Sreg.h.ch;
    pvioCursorInfo->cEnd	=(USHORT)Sreg.h.cl;
    pvioCursorInfo->cx		=0;
    pvioCursorInfo->attr	=0;
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
        return (UINT)wxe_getcurtype(pvioCursorInfo);               //~v570R~
      #else  //!WXE                                                //~v570I~
    	rc16=(APIRET16)!GetConsoleCursorInfo(Shconout,&cci);       //~v022R~
        if (rc16)                                                  //~v034I~
//          rc16=uerrapi0("GetConsoleCursorInfo",GetLastError());  //~v034I~//+v6BiR~
            rc16=(USHORT)uerrapi0("GetConsoleCursorInfo",GetLastError());//+v6BiI~
		pvioCursorInfo->yStart	=(USHORT)cci.dwSize;//percentage(0-100)//~v022R~
	    pvioCursorInfo->cEnd	=0;                                //~v022I~
	    pvioCursorInfo->cx		=0;                                //~v022I~
	    if (cci.bVisible)                                          //~v022R~
		    pvioCursorInfo->attr=0;                                //~v022I~
		else                                                       //~v022I~
		    pvioCursorInfo->attr=(USHORT)-1;                       //~v034R~
		return (UINT)rc16;                                         //~v022I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
   rc16=VioGetCurType (&seg16cursorinfo1,0);
   *pvioCursorInfo=seg16cursorinfo1;
   return (UINT)rc16;
	#endif                                                         //~v022I~
#endif
}//uviogetcurtype

//*******************************************************
//*VioSetCurType
//*******************************************************
UINT uviosetcurtype (PVIOCURSORINFO pvioCursorInfo)
{
#ifdef DOS
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifndef WXE                                                  //~v570I~
    	CONSOLE_CURSOR_INFO cci;                                   //~v022I~
        UINT rc;                                                   //~v034I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
	VIOCURSORINFO 	seg16cursorinfo2;
	#pragma seg16(seg16cursorinfo2)
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	Sreg.h.ch			=(UCHAR)pvioCursorInfo->yStart;
    Sreg.h.cl			=(UCHAR)pvioCursorInfo->cEnd;
	INT10(0x01);						//set cursor type
	return 0;                                                   //~v013R~
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
        return (UINT)wxe_setcurtype(pvioCursorInfo);               //~v570R~
      #else  //!WXE                                                //~v570I~
		cci.dwSize=pvioCursorInfo->yStart; //height percent        //~v034R~
		if (!pvioCursorInfo->attr)		//normal(visible)          //~v022R~
			cci.bVisible=1;                                        //~v022I~
		else                                                       //~v022I~
			cci.bVisible=0;   			//hidden                   //~v022I~
    	rc=!SetConsoleCursorInfo(Shconout,&cci);                   //~v034R~
        if (rc)                                                    //~v034I~
            rc=uerrapi0("SetConsoleCursorInfo",GetLastError());    //~v034I~
		return rc;                                                 //~v034I~
      #endif //!WXE                                                //~v570I~
    #else                                                          //~v022I~
   seg16cursorinfo2=*pvioCursorInfo;
   return (UINT)VioSetCurType(&seg16cursorinfo2,0);
	#endif                                                         //~v022I~
#endif
}//uviosetcurtype

//*******************************************************
//*VioWrtTTY
//*******************************************************
UINT uviowrttty(PCH pch,int Plen)
{
#ifdef DOS
	int i;
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
		DWORD         len;                                         //~v022R~
    #else                                                          //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
	for (i=0;i<Plen;i++)
	{
		Sreg.h.al	=*pch++;                                    //~6212R~
		Sreg.h.bl	=0;						//parm for graphic		
//  	INT10X(0x0e);						//teletype write       //~v056R~
    	INT10(0x0e);						//teletype write       //~v056I~
	}
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
		return !WriteConsole(Shconout,pch,Plen,&len,NULL);         //~v022I~
    #else                                                          //~v022I~
   return (UINT)VioWrtTTY(pch,(USHORT)Plen,0);
	#endif                                                         //~v022I~
#endif
}//uviowrttty
//*******************************************************
//*uviogetstate
//* for DOS,supprt pallette reg and overscan reg
//*parm:req block addr
//*******************************************************
UINT uviogetstate(PVOID Ppreqblk)
{
#ifdef DOS
	int reqtype,i,max;
	PVIOPALSTATE ppal;
	PVIOOVERSCAN povs;
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
//	reqtype=*((int*)Ppreqblk+1);                                   //~v053R~
  	reqtype=(int)(*((short*)Ppreqblk+1));                          //~v053I~
	switch(reqtype)
	{
	case 0:		//pallette reg get req
		ppal=Ppreqblk;
		if (ppal->cb < sizeof(VIOPALSTATE)
		||  ppal->cb > sizeof(VIOPALSTATE)+15*2)
			return ERROR_VIO_INVALID_LENGTH;
		if (ppal->iFirst > 15)
			return ERROR_VIO_INVALID_PARMS;
		max=(ppal->cb-sizeof(VIOPALSTATE))/2+1;
		for (i=0;i<max;i++)
		{
			Sreg.h.al=0x07;				//read each pallet reg
			Sreg.h.bl=(UCHAR)(ppal->iFirst+i);	//pallette reg number
			INT10(0x10);				//pallette reg
			ppal->acolor[i]=Sreg.h.bh;	//color reg of the pallette
		}//reg count
		break;
	case 1:		//overscan reg get req
		povs=Ppreqblk;
		Sreg.h.al=0x08;				//read overscan reg
		INT10(0x10);				//pallette reg
		povs->color=Sreg.h.bh;		//overscan reg value
		break;
	default:
		return ERROR_VIO_INVALID_PARMS;
	}//switch by reqtype
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
    	return (UINT)wxe_uviogetstate(Ppreqblk);                   //~v570I~
      #else  //!WXE                                                //~v570I~
		*(int*)Ppreqblk=0;                                         //~v022I~
    	return ERROR_VIO_EXTENDED_SG;   //not supported            //~v034R~
      #endif //!WXE                                                //~v570I~
	#else                                                          //~v022I~
   return (UINT)VioGetState(Ppreqblk,0);
	#endif                                                         //~v022I~
#endif
}//uvigetstate
                                                                //~5222I~
//*******************************************************
//*uviosetstate
//* for DOS,supprt pallette reg and overscan reg
//*parm:req block addr
//*******************************************************
UINT uviosetstate(PVOID Ppreqblk)
{
#ifdef DOS
	int reqtype,i,max;
	PVIOPALSTATE  ppal;
	PVIOOVERSCAN  povs;
	PVIOINTENSITY pint;
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
	#endif                                                         //~v022I~
#endif
//*********************************
#ifdef DOS
//  reqtype=*((int*)Ppreqblk+1);                                   //~v053R~
    reqtype=(int)(*((short*)Ppreqblk+1));                          //~v053I~
	switch(reqtype)
	{
	case 0:		//pallette reg set req
		ppal=Ppreqblk;
		if (ppal->cb < sizeof(VIOPALSTATE)
		||  ppal->cb > sizeof(VIOPALSTATE)+15*2)
			return ERROR_VIO_INVALID_LENGTH;
		if (ppal->iFirst > 15)
			return ERROR_VIO_INVALID_PARMS;
		max=(ppal->cb-sizeof(VIOPALSTATE))/2+1;
		for (i=0;i<max;i++)
		{
			Sreg.h.al=0x00;				//set  each pallet reg
			Sreg.h.bl=(UCHAR)(ppal->iFirst+i);	//pallette reg number
			Sreg.h.bh=(UCHAR)ppal->acolor[i];	//color reg of the pallette
			INT10(0x10);				//pallette reg
		}//reg count
		break;
	case 1:		//overscan reg set req
		povs=Ppreqblk;
		Sreg.h.al=0x01;				//set  overscan reg
		Sreg.h.bh=(UCHAR)povs->color;		//overscan reg value
		INT10(0x10);				//pallette reg
		break;
	case 2:		//brink or highlight background
		pint=Ppreqblk;
		Sreg.h.al=0x03;				//set change brink/bg hilight
		Sreg.h.bl=(UCHAR)(!pint->fs);//overscan reg value 01:brink
		INT10(0x10);				//pallette reg
		break;
	default:
		return ERROR_VIO_INVALID_PARMS;
	}//switch by reqtype
	return 0;
#else
	#ifdef W32                           //win95                   //~v022I~
      #ifdef WXE                                                   //~v570I~
    	return (UINT)wxe_uviosetstate(Ppreqblk);                   //~v570I~
      #else  //!WXE                                                //~v570I~
		*(int*)Ppreqblk=0;                                         //~v022I~
    	return 16;						//not supported            //~v022I~
      #endif //!WXE                                                //~v570I~
	#else                                                          //~v022I~
   return (UINT)VioSetState(Ppreqblk,0);
	#endif                                                         //~v022I~
#endif
}//uviosetstate                                                 //~5222R~
                                                                //~5222I~
//*******************************************************       //~5222I~
//*uvioscrolldn                                                 //~5222I~
//* scrool down(backward)                                       //~5222I~
//*parm:range (top left and bottom right)                       //~5222I~
//*    :scroll count(line count inserted to top)                //~5222I~
//*    :  if 0,full scroll                                      //~5222I~
//*    :insert line padding char and attr                       //~5222I~
//*    :   for dos char ignored and always space is written     //~5222I~
//*******************************************************       //~5222I~
UINT uvioscrolldn(int Ptoprow,int Pleftcol,int Pbottomrow,int Prightcol,int Pline,UCHAR *Pcell)//~5222I~
{                                                               //~5222I~
#ifdef DOS                                                         //~v022I~
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
    	SMALL_RECT srcrect;				//rectangular              //~v022I~
    	COORD      coorddest;				//x,y                  //~v022R~
    	CHAR_INFO  chi;                                            //~v022I~
	#endif                                                         //~v022I~
#endif                                                             //~v022I~
//*********************************                             //~5222I~
#ifdef DOS                                                      //~5222I~
	Sreg.h.al=(UCHAR)Pline;			//scroll count              //~5222I~
	Sreg.h.ch=(UCHAR)Ptoprow;		                            //~5222I~
	Sreg.h.cl=(UCHAR)Pleftcol;                                  //~5222I~
	Sreg.h.dh=(UCHAR)Pbottomrow;		                        //~5222I~
	Sreg.h.dl=(UCHAR)Prightcol;                                 //~5222I~
	Sreg.h.bh=*(Pcell+1);			//attr                      //~5222I~
	INT10(0x07);				//scroll down                   //~5222I~
	return Sreg.x.cflag;                                        //~5222I~
#else                                                           //~5222I~
	#ifdef W32                           //win95                   //~v022I~
    	srcrect.Right	=(SHORT)Prightcol;                         //~v022R~
//  	srcrect.Bottom	=(SHORT)Pbottomrow;                        //~v5fhR~
    	srcrect.Bottom	=(SHORT)(Pbottomrow+Stoplineoffs);         //~v5fhI~
    	srcrect.Left	=(SHORT)Pleftcol;                          //~v022R~
//    	srcrect.Top		=(SHORT)Ptoprow;                           //~v5fhR~
      	srcrect.Top		=(SHORT)(Ptoprow+Stoplineoffs);            //~v5fhI~
        coorddest.X     =(SHORT)Pleftcol;                          //~v022R~
//      coorddest.Y     =(SHORT)(Ptoprow+Pline);	//Pline down   //~v5fhR~
        coorddest.Y     =(SHORT)(Ptoprow+Pline+Stoplineoffs);	//Pline down//~v5fhI~
        chi.Char.UnicodeChar=0;                                    //~v022I~
        chi.Char.AsciiChar=*Pcell;			//insert space line    //~v022R~
        chi.Attributes    =(WORD)*(Pcell+1);                       //~v022R~
    	return !ScrollConsoleScreenBuffer(Shconout,                //~v022I~
        									&srcrect,	//move box //~v022R~
        									NULL,		//no clip  //~v022I~
        									coorddest,	//destination//~v022R~
                                            &chi);//fill cell      //~v022I~
    #else                                                          //~v022I~
    if (!Pline)             //0 line scroll                     //~5222I~
        Pline=-1;           //execute full line scroll          //~5222I~
  	return (UINT)VioScrollDn((USHORT)Ptoprow,(USHORT)Pleftcol,(USHORT)Pbottomrow,(USHORT)Prightcol,//~5222R~
								(USHORT)Pline,Pcell,0);         //~5222R~
	#endif                                                         //~v022I~
#endif                                                          //~5222I~
}//uvioscrolldn                                                 //~5222I~
                                                                //~5222I~
//*******************************************************       //~5222I~
//*uvioscrollup                                                 //~5222I~
//* scrool down(forward)                                        //~5222I~
//*parm:range (top left and bottom right)                       //~5222I~
//*    :scroll count(line count inserted to bottom)             //~5222I~
//*    :  if 0,full scroll                                      //~5222I~
//*    :insert line padding char and attr                       //~5222I~
//*    :   for dos char ignored and always space is written     //~5222I~
//*******************************************************       //~5222I~
UINT uvioscrollup(int Ptoprow,int Pleftcol,int Pbottomrow,int Prightcol,int Pline,UCHAR *Pcell)//~5222R~
{                                                               //~5222I~
#ifdef DOS                                                         //~v022I~
#else                                                              //~v022I~
	#ifdef W32                           //win95                   //~v022I~
    	SMALL_RECT srcrect;				//rectangular              //~v022I~
    	COORD      coorddest;				//x,y                  //~v022R~
    	CHAR_INFO  chi;                                            //~v022I~
	#endif                                                         //~v022I~
#endif                                                             //~v022I~
//*********************************                             //~5222I~
#ifdef DOS                                                      //~5222I~
	Sreg.h.al=(UCHAR)Pline;			//scroll count              //~5222I~
	Sreg.h.ch=(UCHAR)Ptoprow;		                            //~5222I~
	Sreg.h.cl=(UCHAR)Pleftcol;                                  //~5222I~
	Sreg.h.dh=(UCHAR)Pbottomrow;		                        //~5222I~
	Sreg.h.dl=(UCHAR)Prightcol;                                 //~5222I~
	Sreg.h.bh=*(Pcell+1);			//attr                      //~5222I~
	INT10(0x06);				//scroll up                     //~5222I~
	return Sreg.x.cflag;                                        //~5222I~
#else                                                           //~5222I~
	#ifdef W32                           //win95                   //~v022I~
    	srcrect.Right	=(SHORT)Prightcol;                         //~v022R~
//  	srcrect.Bottom	=(SHORT)Pbottomrow;                        //~v5fhR~
    	srcrect.Bottom	=(SHORT)(Pbottomrow+Stoplineoffs);         //~v5fhI~
    	srcrect.Left	=(SHORT)Pleftcol;                          //~v022R~
//  	srcrect.Top		=(SHORT)Ptoprow;                           //~v5fhR~
    	srcrect.Top		=(SHORT)(Ptoprow+Stoplineoffs);            //~v5fhI~
        coorddest.X     =(SHORT)Pleftcol;                          //~v022R~
//      coorddest.Y     =(SHORT)(Ptoprow-Pline);	//Pline up     //~v5fhR~
        coorddest.Y     =(SHORT)(Ptoprow-Pline+Stoplineoffs);	//Pline up//~v5fhI~
        chi.Char.UnicodeChar=0;                                    //~v022I~
        chi.Char.AsciiChar=*Pcell;                                 //~v022R~
        chi.Attributes=(WORD)*(Pcell+1);                           //~v022R~
    	return !ScrollConsoleScreenBuffer(Shconout,                //~v022I~
        									&srcrect,	//move box //~v022R~
        									NULL,		//no clip  //~v022I~
        									coorddest,	//destination//~v022R~
                                            &chi);//fill cell      //~v022I~
    #else                                                          //~v022I~
    if (!Pline)             //0 line scroll                     //~5222I~
        Pline=-1;           //execute full line scroll          //~5222I~
  	return (UINT)VioScrollUp((USHORT)Ptoprow,(USHORT)Pleftcol,(USHORT)Pbottomrow,(USHORT)Prightcol,//~5222I~
								(USHORT)Pline,Pcell,0);         //~5222R~
	#endif                                                         //~v022I~
#endif                                                          //~5222I~
}//uvioscrollup                                                 //~5222I~
                                                                   //~v151I~
#ifdef DOS                                                         //~v151M~
//*******************************************************          //~v151M~
//*uvio_dosgetvbuff                                                //~v151M~
//*  get dos video buff                                            //~v151M~
//*parm1:optional output dos video buff ptr                        //~v151M~
//*return:rc  0:not real,1:real buff(b800:0)                       //~v151M~
//*******************************************************          //~v151M~
int uvio_dosgetvbuff(UCHAR **Ppvbuff)                              //~v151M~
{                                                                  //~v151M~
	int rc;                                                        //~v151M~
//*********************************                                //~v151M~
    Ssegreg.es=0xb800;                                             //~v151M~
    Sreg.x.di=0;                                                   //~v151M~
#ifdef DPMI                                                        //~v151M~
    Ssegreg.ds=0;                                                  //~v151I~
    Sreg.x.ax=0xfe00;                                              //~v151I~
    udpmiint86x(0x10,&Sreg,&Sreg,&Ssegreg);                        //~v151R~
    if (Ppvbuff)	//optional                                     //~v151I~
	    *Ppvbuff=(UCHAR*)((((ULONG)Ssegreg.es)<<16)+Sreg.x.di);   //video mode//~v151I~
#else                                                              //~v151M~
    INT10X(0xfe);                                                  //~v151M~
    if (Ppvbuff)	//optional                                     //~v151M~
	    *Ppvbuff=FP_SEGOFF(Ssegreg.es,Sreg.x.di);   //video mode   //~v151M~
#endif                                                             //~v151M~
    rc=(Ssegreg.es==0xb800 && Sreg.x.di==0);    //same as real     //~v151M~
	return rc;                                                     //~v151M~
}//uvio_dosgetvbuff                                                //~v151M~
#endif                                                             //~v151M~
                                                                   //~v156I~
#ifdef W32                                                         //~v156I~
//*******************************************************************//~v156M~
//* FUNCTION: ugetconhwnd                                          //~v156M~
//* PURPOSE: get console appl hwnd                                 //~v156M~
//* parm :node                                                     //~v156M~
//* ret  :hwnd or 0                                                //~v156M~
//********************************************************************///~v156M~
//ULONG ugetconhwnd(void)                                            //~v156R~//~v6hhR~
ULPTR ugetconhwnd(void)                                            //~v6hhI~
{                                                                  //~v156M~
	BOOL ok;                                                       //~v156M~
  	HWND hwnd;                                                     //~v156M~
  	char otitle[1024],ntitle[32];                                  //~v156M~
//**********                                                       //~v156M~
  	ok=GetConsoleTitle(otitle,sizeof(otitle));                     //~v156M~
    if (!ok)                                                       //~v156M~
		uerrapi0x("GetConsoleTitle",GetLastError());               //~v156M~
	sprintf(ntitle,"XE:%d/%d",GetTickCount(),GetCurrentProcessId());//~v156M~
//  printf("new title=%s\n",ntitle);	//@@@@                     //~v156M~
  	ok=SetConsoleTitle(ntitle);                                    //~v156M~
    if (!ok)                                                       //~v156M~
		uerrapi1x("SetConsoleTitle",ntitle,GetLastError());        //~v156M~
	Sleep(50);	//wait sometime like as cd manual                  //~v156M~
  	hwnd=FindWindow(NULL,ntitle);                                  //~v156M~
    if (!hwnd)                                                     //~v156M~
		uerrapi1x("FindWindow",ntitle,GetLastError());             //~v156M~
  	ok=SetConsoleTitle(otitle);	//restore                          //~v156M~
    if (!ok)                                                       //~v156M~
		uerrapi1x("SetConsoleTitle",otitle,GetLastError());        //~v156M~
//  return (ULONG)hwnd;                                            //~v156R~//~v6hhR~
    return (ULPTR)hwnd;                                            //~v6hhI~
}//ugetconhwnd                                                     //~v156M~
#endif                                                             //~v156I~
