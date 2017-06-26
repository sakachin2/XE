//CID://+v152R~:                                                   //~v152R~
//*************************************************************
//*udpmisub.c common functions for DPMI                            //~v053R~
//*************************************************************    //~v053I~
//v152:980119 (BUG:GCC)udpmiint86s is not used parm intno(always int 21)//~v152I~
//v151:980119 (BUG:DOS/GCC)video buff direct write determined by not dbcs env//~v152I~
//            but video mode.video buff chk by int 10 ah=FE        //~v152I~
//            (none is displayed under os2 dos session when changed chev us)//~v152I~
//            add udpmiint86x(pass through es/dsetc )              //~v152I~
//v105:971026 (GCC)lfn support                                     //~v105I~
//           -int21 ah=60/7160(get pathname and lfn)               //~v105I~
//v104:971025 _MAX_PATH is contain NULL term;change _MAX_PATH+1-->_MAX_PATH//~v104I~
//v053:970107:gcc version(control by DPMI)                         //~v053R~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//*******************************************************
#include <dos.h>                                                   //~v053R~
#include <dpmi.h>                                                  //~v053R~
#include <go32.h>                                                  //~v053I~
#include <errno.h>                                                 //~v105I~
#include <sys/movedata.h>                                          //~v053R~
#include <libc/dosio.h>  	//__doserr_to_errno                    //~v105I~
//*******************************************************
#include <ulib.h>                                                  //~v022R~
#include <udpmisub.h>                                              //~v053R~
//#include <utrace.h>                                              //~v152R~
//*******************************************************
#define REGSSZ    (sizeof(union REGS)-2)	//34                   //~v053I~
static	__dpmi_regs Sdpmireg;                                      //~v053I~
static	int Spasssw;                                               //~v053I~
void udpmiint8610(union REGS *Pregi,union REGS *Prego);            //~v053R~
//*******************************************************          //~v053I~
//*udpmidosmemget                                                  //~v053R~
//*memcopy from dos memory                                         //~v053R~
//*parm1:out buff addr                                             //~v053I~
//*parm2:dos memory segment                                        //~v053R~
//*parm3:dos memory offset                                         //~v053R~
//*parm4:move length                                               //~v053R~
//*ret  :none                                                      //~v053I~
//*******************************************************          //~v053I~
void udpmidosmemget(void *Pbuff,int Pdosseg,int Pdosoff,int Plen)  //~v053R~
{                                                                  //~v053I~
//*******************                                              //~v053I~
	dosmemget(DOS_MAKE_FLAT(Pdosseg,Pdosoff),Plen,Pbuff);          //~v053R~
	return;                                                        //~v053R~
}//udpmidosmemget                                                  //~v053R~
                                                                   //~v053I~
//*******************************************************          //~v053I~
//*udpmidosmemput                                                  //~v053I~
//*memcopy to   dos memory                                         //~v053I~
//*parm1:dos memory segment                                        //~v053I~
//*parm2:dos memory offset                                         //~v053I~
//*parm3:input buff addr                                           //~v053R~
//*parm4:move length                                               //~v053I~
//*ret  :none                                                      //~v053I~
//*******************************************************          //~v053I~
void udpmidosmemput(int Pdosseg,int Pdosoff,void *Pbuff,int Plen)  //~v053R~
{                                                                  //~v053I~
//*******************                                              //~v053I~
	dosmemput(Pbuff,Plen,DOS_MAKE_FLAT(Pdosseg,Pdosoff));          //~v053R~
	return;                                                        //~v053I~
}//udpmidosmemput                                                  //~v053I~
                                                                   //~v053I~
//*******************************************************          //~v053I~
//*udpmiint86                                                      //~v053R~
//*overtype int86(length parm additional to int86)                 //~v053R~
//*ptr parm is pmode flat addr and so avail for int86x need ds/es setup//~v053I~
//*if under DOS(use transfer buffer set up by GO32 as ds,es).      //~v053R~
//*if addr parm is not needed,user int86.                          //~v053I~
//*parm1:int no                                                    //~v053R~
//*parm2:input  REGS                                               //~v053I~
//*parm3:output REGS                                               //~v053R~
//*ret  :ax                                                        //~v053R~
//*******************************************************          //~v053I~
int udpmiint86(int Pint,union REGS *Pregi,union REGS *Prego)       //~v053R~
{                                                                  //~v053I~
    char *pc;                                                      //~v053I~
    char *pc2;                                                     //~v105I~
    char copywk[_MAX_PATH];                                        //~v104R~
    int  ah,dosfuncid;                                             //~v105I~
//*******************                                              //~v053I~
	Spasssw=0;		//call int86 sw                                //~v053I~
    memset(&Sdpmireg,0,sizeof(Sdpmireg));                          //~v053I~
    memcpy(&Sdpmireg,Pregi,REGSSZ);	//size of REGS                 //~v053I~
  	Sdpmireg.x.ds = Sdpmireg.x.es = __tb / 16;	//transfer buffer  //~v053I~
	switch(Pint)                                                   //~v053I~
    {                                                              //~v053I~
    case 0x10:          //video                                    //~v053I~
    	udpmiint8610(Pregi,Prego);                                 //~v053R~
        break;                                                     //~v053I~
    case 0x21:          //dos                                      //~v053I~
//  	switch(Sdpmireg.h.ah)                                      //~v105R~
        dosfuncid=ah=(int)Sdpmireg.h.ah;                           //~v105I~
        if (ah==0x71)    //lfn func                                //~v105R~
           dosfuncid=(int)Sdpmireg.h.al;                           //~v105I~
    	switch(dosfuncid)                                          //~v105I~
    	{                                                          //~v053R~
        case 0x47:                                                 //~v053R~
//esi:output cdir name area                                        //~v105I~
            pc=(char *)Sdpmireg.d.esi;	//pmode flat addr          //~v053M~
            Sdpmireg.x.si = 0;			//offset of transfer buffer(DS:SI)//~v053R~
            __dpmi_int(0x21,&Sdpmireg);                            //~v053R~
            dosmemget(__tb,_MAX_PATH,copywk);	//by req len       //~v053R~
//          copywk[_MAX_PATH]=0;                                   //~v104R~
            copywk[_MAX_PATH-1]=0;                                 //~v104I~
            strcpy(pc,copywk);                                     //~v053I~
	        break;                                                 //~v053I~
        case 0x60:                                                 //~v105I~
//esi:input fname area, edi:output pathname area                   //~v105I~
            pc=(char *)Sdpmireg.d.esi;	//input name pmode flat addr//~v105I~
            Sdpmireg.x.si = 0;			//offset of transfer buffer(DS:SI)//~v105I~
            pc2=(char *)Sdpmireg.d.edi;	//output pmode flat addr   //~v105I~
            Sdpmireg.x.di = _MAX_PATH;	//offset of transfer buffer(DS:DI)//~v105I~
            strncpy(copywk,pc,sizeof(copywk));//for dosmemput      //~v105I~
            dosmemput(copywk,_MAX_PATH,__tb);//copy input to dos mem//~v105I~
            __dpmi_int(0x21,&Sdpmireg);                            //~v105I~
            dosmemget(__tb+_MAX_PATH,_MAX_PATH,copywk);//get output//~v105R~
            copywk[_MAX_PATH-1]=0;                                 //~v105I~
            strcpy(pc2,copywk);                                    //~v105I~
	        break;                                                 //~v105I~
        default:                                                   //~v053R~
			Spasssw=1;		//call int86 sw                        //~v053I~
      	}//case ah                                                 //~v053R~
    	if (Sdpmireg.x.flags & 1)   //expand like as int86         //~v105I~
        	errno=__doserr_to_errno(Sdpmireg.x.ax);                //~v105R~
    	break;                                                     //~v053I~
    default:                                                       //~v053I~
		Spasssw=1;		//call int86 sw                            //~v053I~
  	}//case Pint                                                   //~v053I~
                                                                   //~v053I~
    if (Spasssw)                                                   //~v053I~
    	return int86(Pint,Pregi,Prego);                            //~v053M~
                                                                   //~v053M~
    memcpy(Prego,&Sdpmireg,REGSSZ);                                //~v053R~
    Prego->d.eflags =Sdpmireg.x.flags;    	//expand like as int86 //~v053R~
    Prego->d.cflag  =Sdpmireg.x.flags & 1;   //expand like as int86//~v053R~
    Prego->d.eax    =Sdpmireg.x.ax;          //expand like as int86//~v053R~
    return Sdpmireg.x.ax;                                          //~v053R~
}//udpmiint86                                                      //~v053R~
                                                                   //~v053I~
//*******************************************************          //~v053I~
//*udpmiint8610                                                    //~v053I~
//*int86 for ah=10h(video)                                         //~v053I~
//*parm1:input  REGS                                               //~v053I~
//*parm2:output REGS                                               //~v053I~
//*ret  :none(set Spasssw)                                         //~v053I~
//*******************************************************          //~v053I~
void udpmiint8610(union REGS *Pregi,union REGS *Prego)             //~v053R~
{                                                                  //~v053I~
#define PALTBLSZ (16+1)		//pallette reg tbl and overscan reg    //~v053I~
    char *pc;                                                      //~v053I~
    int len;                                                       //~v053I~
//*******************                                              //~v053I~
	switch(Sdpmireg.h.ah)                                          //~v053I~
	{                                                              //~v053I~
    case 0x10:					//pallette reg                     //~v053I~
        pc=(char *)Sdpmireg.d.edx;	//ES:DX pallette reg tbl       //~v053I~
        Sdpmireg.x.dx=0;			//offset of transfer buffer(ES:DX)//~v053I~
    	switch(Sdpmireg.h.al)                                      //~v053I~
    	{                                                          //~v053I~
        case 0x02:				//pallette multiple write          //~v053I~
            dosmemput(pc,PALTBLSZ,__tb);	//by req len           //~v053R~
            __dpmi_int(0x10,&Sdpmireg);                            //~v053I~
	        break;                                                 //~v053I~
        case 0x09:				//pallette multiple read           //~v053I~
            __dpmi_int(0x10,&Sdpmireg);                            //~v053I~
            dosmemget(__tb,PALTBLSZ,pc);	//by req len           //~v053R~
	        break;                                                 //~v053I~
        case 0x12:				//color reg multiple write         //~v053M~
        	len=Sdpmireg.x.cx*3;	//write reg count(RGB 3 byte for each)//~v053I~
            dosmemput(pc,len,__tb);	//by req len                   //~v053I~
            __dpmi_int(0x10,&Sdpmireg);                            //~v053I~
	        break;                                                 //~v053I~
        case 0x17:				//color reg multiple read          //~v053M~
        	len=Sdpmireg.x.cx*3;	//write reg count(RGB 3 byte for each)//~v053I~
            __dpmi_int(0x10,&Sdpmireg);                            //~v053I~
            dosmemget(__tb,len,pc);	//by req len                   //~v053I~
	        break;                                                 //~v053I~
        default:                                                   //~v053I~
        	Spasssw=1;                                             //~v053R~
        }//case al                                                 //~v053I~
        break;                                                     //~v053I~
    case 0x13:					//string i/o                       //~v053I~
        len=Sdpmireg.x.cx;		//read/write count                 //~v053I~
        pc=(char *)Sdpmireg.d.ebp;	//ES:DX pallette reg tbl       //~v053I~
        Sdpmireg.x.bp=0;			//offset of transfer buffer(ES:DX)//~v053I~
    	switch(Sdpmireg.h.al)                                      //~v053I~
    	{                                                          //~v053I~
        case 0x00:				//writestringatt csr no move       //~v053I~
        case 0x01:				//writestringatt csr move          //~v053I~
            dosmemput(pc,len,__tb);	//by req len                   //~v053I~
            __dpmi_int(0x10,&Sdpmireg);                            //~v053I~
            break;                                                 //~v053I~
        case 0x02:				//writecellstring csr no move      //~v053I~
        case 0x03:				//writecellstring csr move         //~v053I~
        case 0x20:				//writecellstring csr no move      //~v053M~
        	len<<=1;			//cell string len                  //~v053I~
//UTRACED("udpmisub int10 write ",pc,len);                         //~v053I~
//UTRACED("udpmisub int10 write cx",&Sdpmireg.x.cx,4);             //~v053M~
            dosmemput(pc,len,__tb);	//by cell string len           //~v053I~
            __dpmi_int(0x10,&Sdpmireg);                            //~v053I~
            break;                                                 //~v053I~
        case 0x21:				//writecellstring(3 attrbyte) csr no move//~v053I~
        	len<<=2;			//cell string len                  //~v053I~
            dosmemput(pc,len,__tb);	//by cell str len              //~v053R~
            __dpmi_int(0x10,&Sdpmireg);                            //~v053I~
            break;                                                 //~v053I~
        case 0x10:				//readcellstr(attr=1) csr no move  //~v053I~
        	len<<=1;			//cell string len                  //~v053I~
            __dpmi_int(0x10,&Sdpmireg);                            //~v053I~
            dosmemget(__tb,len,pc);	//by req len                   //~v053I~
//UTRACED("udpmisub int10 read ",pc,len);                          //~v053I~
            break;                                                 //~v053I~
        case 0x11:				//readcellstr(attr=3) csr no move  //~v053I~
        	len<<=2;			//cell string len                  //~v053I~
            __dpmi_int(0x10,&Sdpmireg);                            //~v053I~
            dosmemget(__tb,len,pc);	//by req len                   //~v053R~
            break;                                                 //~v053I~
        default:                                                   //~v053I~
        	Spasssw=1;                                             //~v053R~
        }//case al                                                 //~v053I~
        break;                                                     //~v053I~
    default:                                                       //~v053I~
    	Spasssw=1;                                                 //~v053R~
    }//case ah                                                     //~v053I~
    return;                                                        //~v053I~
}//udpmiint8610                                                    //~v053I~
//*******************************************************          //~v053I~
//*udpmiint86s                                                     //~v053I~
//*additional to int86,return segment reg value(DS/ES only)        //~v053I~
//*input sreg(DS/ES) is set to transfer buff as default if you set no zero value//~v053I~
//*no memory copy function                                         //~v053I~
//*parm1:int no                                                    //~v053I~
//*parm2:input  REGS                                               //~v053I~
//*parm3:output REGS                                               //~v053I~
//*parm4:output SREGS                                              //~v053I~
//*ret  :ax                                                        //~v053I~
//*******************************************************          //~v053I~
int udpmiint86s(int Pint,union REGS *Pregi,union REGS *Prego,struct SREGS *Psrego)//~v053R~
{                                                                  //~v053I~
//*******************                                              //~v053I~
    memset(&Sdpmireg,0,sizeof(Sdpmireg));                          //~v053I~
    memcpy(&Sdpmireg,Pregi,REGSSZ);	//size of REGS                 //~v053I~
  	if (Sdpmireg.x.ds)                                             //~v053R~
	  	Sdpmireg.x.ds = __tb / 16;	//transfer buffer              //~v053I~
  	if (Sdpmireg.x.es)                                             //~v053I~
	  	Sdpmireg.x.es = __tb / 16;	//transfer buffer              //~v053I~
//  __dpmi_int(0x21,&Sdpmireg);                                    //~v152R~
    __dpmi_int(Pint,&Sdpmireg);                                    //~v152R~
    memcpy(Prego,&Sdpmireg,REGSSZ);                                //~v053I~
    Prego->d.eflags =Sdpmireg.x.flags;    	//expand like as int86 //~v053I~
    Prego->d.cflag  =Sdpmireg.x.flags & 1;   //expand like as int86//~v053I~
    Prego->d.eax    =Sdpmireg.x.ax;          //expand like as int86//~v053I~
    Psrego->es=Sdpmireg.x.es;                                      //~v053M~
    Psrego->ds=Sdpmireg.x.ds;                                      //~v053M~
    return Sdpmireg.x.ax;                                          //~v053I~
}//udpmiint86s                                                     //~v053I~
//*******************************************************          //~v152I~
//*udpmiint86x                                                     //~v152I~
//*additional to int86,return segment reg value(DS/ES only)        //~v152I~
//*input sreg(DS/ES) is set path through                           //~v152I~
//*parm1:int no                                                    //~v152I~
//*parm2:input  REGS                                               //~v152I~
//*parm3:output REGS                                               //~v152I~
//*parm4:output SREGS                                              //~v152I~
//*ret  :ax                                                        //~v152I~
//*******************************************************          //~v152I~
int udpmiint86x(int Pint,union REGS *Pregi,union REGS *Prego,struct SREGS *Psrego)//~v152I~
{                                                                  //~v152I~
//*******************                                              //~v152I~
    memset(&Sdpmireg,0,sizeof(Sdpmireg));                          //~v152I~
    memcpy(&Sdpmireg,Pregi,REGSSZ);	//size of REGS                 //~v152I~
	Sdpmireg.x.es=Psrego->es;                                      //~v152I~
	Sdpmireg.x.ds=Psrego->ds;                                      //~v152I~
    __dpmi_int(Pint,&Sdpmireg);                                    //~v152I~
    memcpy(Prego,&Sdpmireg,REGSSZ);                                //~v152I~
    Prego->d.eflags =Sdpmireg.x.flags;    	//expand like as int86 //~v152I~
    Prego->d.cflag  =Sdpmireg.x.flags & 1;   //expand like as int86//~v152I~
    Prego->d.eax    =Sdpmireg.x.ax;          //expand like as int86//~v152I~
    Psrego->es=Sdpmireg.x.es;                                      //~v152I~
    Psrego->ds=Sdpmireg.x.ds;                                      //~v152I~
    return Sdpmireg.x.ax;                                          //~v152I~
}//udpmiint86x                                                     //+v152R~
