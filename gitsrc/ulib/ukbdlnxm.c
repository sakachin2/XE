//*CID://+v730R~:                             update#=  432;       //+v730R~
//*************************************************************    //~v592I~
//*ukbdlnxm.c                                                      //~v592R~
//*mouse get for linux xterm/kterm/gterm                           //~v592I~
//*************************************************************    //~v592I~
//v730:201218 (BUG:LNX console)crash by mouse drag; at V712(V129P) coding miss; deleted length clear statemaent//~v730I~
//v712:201023 Manjaro;mouse esc seq 0x1b[<b;x;yM  M:down/m:up      //~v6D5I~
//v6D5:160430 LNX compiler warning for FD_SET/FD_ISSET             //~v6D5I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v62L:091012_(LNX:BUG)some time cap block start by mouse click;   //~v62LI~
//            Button up/down event was read at once,but generate kbd event twice.//~v62LI~
//v5g4:050602 (LNX:BUG)whell mouse(roll up/down middle button(button2)) generate no btunup//~v5g4I~
//            So,ABEND by readbuff overflow;return rollup/dn event //~v5g4R~
//v5c0:040318 limit mouse event id to be reported(shift key may be detect?)//~v5c0I~
//v592:030928 (LNX)mouse support                                   //~v592I~
//*************************************************************    //~v592I~
#include <stdlib.h>                                                //~v592I~
#include <stdio.h>                                                 //~v592I~
#include <string.h>                                                //~v592I~
#include <ctype.h>                                                 //~v592I~
#include <sys/time.h>                                              //~v592I~
#include <sys/ioctl.h>                                             //~v5g4I~
#include <linux/types.h>                                           //~v592I~
#include <linux/kd.h>                                              //~v592I~
#include <linux/keyboard.h>                                        //~v592I~
#include <sys/ioctl.h>                                             //~v592I~
#include <sys/select.h>                                            //~v592I~
#include <errno.h>                                                 //~v592I~
#include <term.h>                                                  //~v592I~
#include <unistd.h>                                                //~v592M~
#include <ncurses.h>                                               //~v592M~
                                                                   //~v592I~
#include <ulib.h>                                                  //~v592I~
#include <ukbdlnxm.h>                                              //~v592I~
#include <utrace.h>                                                //~v592I~
#include <uerr.h>                                                  //~v592I~
#include <ustring.h>                                               //~v592I~
#include <uedit.h>                                                 //~v592I~
#include <uproc.h>                                                 //~v6D5I~
#include <uproc4.h>                                                //~v6D5I~
//*********************************************************************//~v592I~
#define READSIZE  32                                               //~v592I~
#define BTN_WHEEL  0x40  //wheel roll up(btn4=60)/dn(btn5=61)      //~v5g4R~
#define BTN_CTL    0x10  //+Ctrl                                   //~v5g4R~
#define BTN_META   0x08  //+Meta                                   //~v5g4R~
#define BTN_SHIGFT 0x04  //+Shift                                  //~v5g4R~
#define BTN_BTNNO  0x03  //button no mask(0,1,2,3=release)         //~v5g4R~
#define BTN_RELEASE     3                                          //~v592I~
#define MODX_PLAIN     0                                           //~v592I~
#define MODX_SHIFT     1                                           //~v592I~
#define MODX_CONTROL   2                                           //~v592I~
#define MODX_ALT       3                                           //~v592I~
#define BTN_DOWN       'M'                                         //~v712I~
#define BTN_UP         'm'                                         //~v712I~
//*********************************************************************//~v592I~
static int lenMouse2_2;                                            //~v712I~
static int swMouse2;                                               //~v712I~
//*********************************************************************//~v592I~
static  struct timeval Stvclick={0,UKLM_CLICK_INTVL*100000};// sec,microsec//~v592R~
static  struct timeval Stvdblclick={0,UKLM_DBLCLICK_INTVL*100000};// sec,microsec//~v592R~
//*********************************************************************//~v592I~
//int clickchk(int Pfd,char *Pbuff,int *Plen);                       //~v592I~//~v62LR~
int clickchk(int Pfd,char *Pbuff,int *Plen,char *Ppnext,int Pnextreslen);//~v62LI~
//*********************************************************************//~v592I~
//*********************************************************************//~v592I~
//* save mouse option                                              //~v592I~
//*********************************************************************//~v592I~
int ukbdlnxm_mouseopt(long Pintvl)                                 //~v592R~
{                                                                  //~v592I~
	int intvl;                                                     //~v592I~
//*************************                                        //~v592I~
    if (Pintvl!=-1) //not use default                              //~v592I~
    {                                                              //~v592I~
//    	intvl=Pintvl>>16;                                          //~v592R~//~v6BxR~
      	intvl=(int)(Pintvl>>16);                                   //~v6BxI~
        Stvclick.tv_sec=intvl/10;   //0.1 sec unit                 //~v592R~
        Stvclick.tv_usec=(intvl%10)*100000;   //0.1 sec unit       //~v592R~
    	intvl=Pintvl & 0xffff;         //dbl click interval        //~v592R~
        Stvdblclick.tv_sec=intvl/10;   //0.1 sec unit              //~v592R~
        Stvdblclick.tv_usec=(intvl%10)*100000;   //0.1 sec unit    //~v592R~
    }                                                              //~v592I~
//printf("intvl=%d,%d\n",Pintvl>>8,Pintvl&255);                    //~v592R~
    return 0;                                                      //~v592I~
}//ukbdlnxm_mouseopt                                               //~v592I~
//*********************************************************************//~v592I~
//* mouse init                                                     //~v592I~
//*********************************************************************//~v592I~
int ukbdlnxm_mouseinit(void)                                       //~v592I~
{                                                                  //~v592I~
    mmask_t mmn,mmo;                                               //~v592I~
//********************************                                 //~v592I~
	if (Stvclick.tv_sec||Stvclick.tv_usec)	//not no mouse use     //~v592R~
    {                                                              //~v592I~
#define AAA                                                        //~v5c0I~
#ifdef AAA                                                         //~v5c0I~
        mmn=ALL_MOUSE_EVENTS;                                      //~v5c0R~
        mmn=ALL_MOUSE_EVENTS|REPORT_MOUSE_POSITION;                //~v5c0I~
#else                                                              //~v5c0I~
        mmn=(0                                                     //~v5c0R~
     || BUTTON1_RELEASED         // 000000000001L                  //~v5c0R~
     || BUTTON1_PRESSED          // 000000000002L                  //~v5c0R~
     || BUTTON1_CLICKED          // 000000000004L                  //~v5c0R~
     || BUTTON1_DOUBLE_CLICKED   // 000000000010L                  //~v5c0R~
     || BUTTON2_RELEASED         // 000000000100L                  //~v5c0R~
     || BUTTON2_PRESSED          // 000000000200L                  //~v5c0R~
     || BUTTON2_CLICKED          // 000000000400L                  //~v5c0R~
     || BUTTON2_DOUBLE_CLICKED   // 000000001000L                  //~v5c0R~
     || BUTTON3_RELEASED         // 000000010000L                  //~v5c0R~
     || BUTTON3_PRESSED          // 000000020000L                  //~v5c0R~
     || BUTTON3_CLICKED          // 000000040000L                  //~v5c0R~
     || BUTTON3_DOUBLE_CLICKED   // 000000100000L                  //~v5c0R~
     || BUTTON_CTRL              // 000100000000L                  //~v5c0R~
     || BUTTON_SHIFT             // 000200000000L                  //~v5c0R~
//   || BUTTON_ALT               // 000400000000L                  //~v5c0R~
        );                                                         //~v5c0R~
#endif                                                             //~v5c0I~
    	mousemask(mmn,&mmo);                                       //~v592I~
        return 1;                                                  //~v592I~
    }                                                              //~v592I~
    return 0;                                                      //~v592I~
}//ukbdlnxm_mouseinit                                              //~v592I~
//*********************************************************************//~v592I~
//* mouse term                                                     //~v592I~
//*********************************************************************//~v592I~
int ukbdlnxm_mouseterm(void)                                       //~v592I~
{                                                                  //~v592I~
    mmask_t mmn,mmo;                                               //~v592I~
//********************************                                 //~v592I~
	if (Stvclick.tv_sec||Stvclick.tv_usec)	//not no mouse use     //~v592I~
    {                                                              //~v592I~
	    mmn=0;                                                     //~v592I~
    	mousemask(mmn,&mmo);                                       //~v592I~
        return 1;                                                  //~v592I~
    }                                                              //~v592I~
    return 0;                                                      //~v592I~
}//ukbdlnxm_mouseterm                                              //~v592I~
//********************************                                 //~v712I~
int ukbdlnxm_getmouse2(char *Pnextpos,int *Ppbutton,int *Ppweelsw,int *Ppshiftstat,int *Ppposx,int *Ppposy)//~v712I~
{                                                                  //~v712I~
	char *pc;                                                      //~v712I~
    int btnID,button,wheelsw,shiftstat,posx,posy,len;              //~v712I~
//*****************                                                //~v712I~
//  UTRACED("buff",Pnextpos,(int)strlen(Pnextpos));                //~v712R~
    pc=Pnextpos+3;              //esc[Mbxy fmt                     //~v712I~
    btnID=atoi(pc);             //0-2:btnid, modifier              //~v712I~
    button=btnID & 0x03;        //0-2:Pressed button-no,3:button released//~v712I~
    wheelsw=btnID & BTN_WHEEL;                                     //~v712I~
    shiftstat=btnID & 0x1c;                                        //~v712I~
    pc+=unumlen(pc,UNUMLEN_DEC,16/*maxlen*/)+1;     //0x1b[<btn;   //~v712R~
//  UTRACED("pc",pc,(int)strlen(pc));                              //~v712R~
    posx=atoi(pc);                                                 //~v712I~
    pc+=unumlen(pc,UNUMLEN_DEC,16)+1;           //0x1b[<btn;x;     //~v712R~
//  UTRACED("pc",pc,(int)strlen(pc));                              //~v712R~
    posy=atoi(pc);                                                 //~v712I~
    pc+=unumlen(pc,UNUMLEN_DEC,16);           //0x1b[<btn;x;yM  M or m//~v712R~
//  UTRACED("pc",pc,(int)strlen(pc));                              //~v712R~
    if (*pc==BTN_UP)              //'M':down, 'm':up               //~v712R~
        button=BTN_RELEASE;                                        //~v712I~
    pc++;                                                          //~v712I~
    *Ppbutton=button;                                              //~v712I~
    *Ppweelsw=wheelsw;                                             //~v712I~
    *Ppshiftstat=shiftstat;                                        //~v712R~
    *Ppposx=posx;                                                  //~v712I~
    *Ppposy=posy;                                                  //~v712I~
    len=PTRDIFF(pc,Pnextpos);                                      //~v712R~
	UTRACEP("%s:len=%d,x=%d,y=%d,button=%d\n",UTT,len,posx,posy,button);//~v712R~
    return len;                                                    //~v712I~
}                                                                  //~v712I~
//*********************************************************************//~v592I~
//* get mouse info                                                 //~v592I~
//* buff has fmt esc[Mbxy :b:button,x:col(1 start),y:row(1 start)  //~v592I~
//* out fmt char+scan(0xEE)+posx+posy                              //~v592I~
//*    char 40:press,20:click,10:dblclick,03:mouseno               //~v592I~
//*********************************************************************//~v592I~
int ukbdlnxm_getmouse(int Pfd,struct timeval *Pptv,UCHAR **Ppnextpos,int *Ppreslen,char *Pout,int *Pmodifier)//~v592R~
{                                                                  //~v592I~
static int Sprevbutton=0,Sclickctr=0;                              //~v592R~
    struct timeval tv,tvdiff;                                      //~v592I~
    char *pc;                                                      //~v592I~
    char buffnext[READSIZE];                                       //~v592R~
    int shiftstat,posx,posy,button,charcode;                       //~v592I~
    int click,modx,len,rc,dblchksw;                                //~v592R~
    int wheelsw;                                                   //~v5g4I~
    int lenMouse2=0;                                               //~v712R~
//********************************                                 //~v592I~
//UTRACEP("entry reslen=%d,nextpos=%x\n",*Ppreslen,*Ppnextpos);    //~v5g4R~
UTRACED("mouse event",*Ppnextpos,(int)strlen(*Ppnextpos));         //~v712R~
  lenMouse2_2=0;                                                   //~v712I~
  swMouse2=0;                                                      //~v712I~
  if (*(*Ppnextpos+2)==MOUSE_ESCID2)                               //~v6D5I~
  {                                                                //~v6D5I~
    swMouse2=1;                                                    //~v712I~
	lenMouse2=ukbdlnxm_getmouse2(*Ppnextpos,&button,&wheelsw,&shiftstat,&posx,&posy);//~v712I~
  }                                                                //~v6D5I~
  else                                                             //~v6D5I~
  {                                                                //~v6D5I~
    pc=*Ppnextpos+3;              //esc[Mbxy fmt                   //~v592R~
    button=*pc & 0x03;          //0-2:Pressed button-no,3:button released//~v592I~
    wheelsw=*pc & BTN_WHEEL;                                       //~v5g4I~
    shiftstat=*pc & 0x1c;                                          //~v592I~
    posx=*(++pc)-0x21;                                             //~v592R~
    posy=*(++pc)-0x21;                                             //~v592R~
  }                                                                //~v6D5I~
    if (posx<0 || posy<0)                                          //~v592I~
    {                                                              //~v5g4I~
    	*Ppreslen=0;	//for safety of buff overflow,ignor input  //~v5g4I~
        return 0;            //not mouse,continue key proc         //~v592I~
    }                                                              //~v5g4I~
    charcode=0;                 //return event type as char code   //~v592R~
    click=0;                                                       //~v62LI~
//UTRACEP("mouse press whellsw=%d,clickctr=%d,button=%x\n",wheelsw,Sclickctr,button);//~v5g4R~
  if (wheelsw)                                                     //~v5g4I~
  {                                                                //~v5g4I~
    charcode=UKLM_WHEEL;                                           //~v5g4I~
    rc=UKLM_RC_WHEEL;   //RETURN EVENT TO UKBDLNX_READKB CALLER    //~v5g4I~
  }                                                                //~v5g4I~
  else                                                             //~v5g4I~
  {                                                                //~v5g4I~
    if (button==BTN_RELEASE)                                       //~v592R~
    {                                                              //~v592I~
        button=Sprevbutton;                                        //~v592I~
        Sclickctr=0;                                               //~v592R~
        rc=UKLM_RC_UP;                                             //~v592I~
    }                                                              //~v592I~
    else    //press                                                //~v592R~
    {                                                              //~v592I~
        Sprevbutton=button; //for release time                     //~v592M~
    	dblchksw=0;                                                //~v592I~
        if (Pptv)   //previous is also mouse event                 //~v592I~
        {                                                          //~v592I~
            if (gettimeofday(&tv,NULL)!=-1)//time after read       //~v592I~
            {                                                      //~v592I~
            	timersub(&tv,Pptv,&tvdiff);                        //~v592I~
                  //interval;before read after prev click and after read//~v592I~
                if (tvdiff.tv_sec<Stvdblclick.tv_sec               //~v592I~
                || (tvdiff.tv_sec==Stvdblclick.tv_sec              //~v592I~
                    &&  tvdiff.tv_usec<=Stvdblclick.tv_usec))      //~v592I~
                  	dblchksw=1;                                    //~v592I~
            }//prev is click                                       //~v592I~
        }//gettime rc                                              //~v592I~
//UTRACEP("mouse Ptv=%x,dblsw=%d clickctr=%d,timediff=%d,%d\n",Pptv,dblchksw,Sclickctr,tvdiff.tv_sec,tvdiff.tv_usec/1000);//~v5c0R~
//      click=clickchk(Pfd,buffnext,&len);                         //~v592I~//~v62LR~
      if (swMouse2)                                                //~v712I~
        click=clickchk(Pfd,buffnext,&len,*Ppnextpos+lenMouse2,*Ppreslen-lenMouse2);//~v712I~
      else                                                         //~v712I~
        click=clickchk(Pfd,buffnext,&len,*Ppnextpos+MOUSE_ESCLEN,*Ppreslen-MOUSE_ESCLEN);//~v62LI~
UTRACEP("%s:clickchk rc=click=%d,len=%d\n",UTT,click,len);                   //~v5g4R~//~v730R~
        if (click)                                                 //~v592R~
        {                                                          //~v592I~
            if (dblchksw)	//in the click interval                //~v592R~
            	Sclickctr++;                                       //~v592R~
            else                                                   //~v592R~
    	    	Sclickctr=1;                                       //~v592R~
            if (Sclickctr==2)                                      //~v592R~
                charcode=UKLM_DBLCLICK;                            //~v592R~
            else                                                   //~v592R~
            if (Sclickctr==3)                                      //~v592R~
            {                                                      //~v592I~
            	Sclickctr=0;                                       //~v592R~
                charcode=UKLM_TRPCLICK;                            //~v592R~
            }                                                      //~v592I~
            else                                                   //~v592I~
	            charcode=UKLM_CLICK;                               //~v592I~
    	    rc=UKLM_RC_CLICK;                                      //~v592I~
UTRACEP("%s UKLM_RC_CLICK click=%d clickctr=%d,charcode=%x\n",UTT,click,Sclickctr,charcode);//~v5g4R~//~v730R~
        }//click:release gotten in time                            //~v592M~
        else    //release timeout                                  //~v592I~
        {                                                          //~v592I~
    	    Sclickctr=0;                                           //~v592R~
            charcode=UKLM_DOWN;                                    //~v592R~
            if (len)                                               //~v592R~
            {                                                      //~v592R~
//              memcpy(*Ppnextpos+*Ppreslen,buffnext,len);         //~v592R~//~v6BkR~
                memcpy(*Ppnextpos+*Ppreslen,buffnext,(size_t)len); //~v6BkI~
                *Ppreslen=*Ppreslen+len;                           //~v592R~
//UTRACEP("rel timeout len=%d,reslen=%d,nextpos=%x\n",len,*Ppreslen,*Ppnextpos);//~v5g4R~
            }                                                      //~v592R~
    	    rc=UKLM_RC_DOWN;                                       //~v592I~
UTRACEP("%s UKLM_RC_DOWN\n",UTT);                                  //~v730I~
        }//timeout                                                 //~v592I~
    }//btn down                                                    //~v592R~
  }//wheel                                                         //~v5g4I~
//  *Pout=charcode+button;                                         //~v592R~//~v6BkR~
    *Pout=(char)(charcode+button);                                 //~v6BkI~
    *(Pout+1)=UKLM_MOUSEID;                                        //~v592I~
//  *(Pout+2)=posx;                                                //~v592I~//~v6BkR~
    *(Pout+2)=(char)posx;                                          //~v6BkI~
//  *(Pout+3)=posy;                                                //~v592I~//~v6BkR~
    *(Pout+3)=(char)posy;                                          //~v6BkI~
    if (shiftstat & 0x04)                                          //~v592I~
    	modx=MODX_SHIFT;                                           //~v592I~
    else                                                           //~v592I~
    if (shiftstat & 0x08)                                          //~v592I~
    	modx=MODX_ALT;                                             //~v592I~
    else                                                           //~v592I~
    if (shiftstat & 0x10)                                          //~v592I~
    	modx=MODX_CONTROL;                                         //~v592I~
    else                                                           //~v592I~
    	modx=0;                                                    //~v592I~
    *Pmodifier=modx;                                               //~v592I~
//UTRACEP("mouse pos=(%d,%d),button=%x,modx=%x\n",posx,posy,*Pout,modx);//~v5g4R~
  if (swMouse2)	                                                   //~v712R~
  {                                                                //~v712I~
      if (click==2)                                                //~v712I~
      {                                                            //~v712I~
        *Ppnextpos=*Ppnextpos+lenMouse2+lenMouse2_2;               //~v712R~
        *Ppreslen=*Ppreslen-(lenMouse2+lenMouse2_2);               //~v712I~
      }                                                            //~v712I~
      else                                                         //~v712I~
      {                                                            //~v712I~
        *Ppnextpos=*Ppnextpos+lenMouse2;                           //~v712I~
        *Ppreslen=*Ppreslen-lenMouse2;                             //~v712I~
      }                                                            //~v712I~
  }                                                                //~v712I~
  else                                                             //~v712I~
  if (click==2)	                                                   //~v62LI~
  {                                                                //~v62LI~
    *Ppnextpos=*Ppnextpos+MOUSE_ESCLEN*2;                          //~v62LI~
    *Ppreslen=*Ppreslen-MOUSE_ESCLEN*2;                            //~v62LI~
  }                                                                //~v62LI~
  else                                                             //~v62LI~
  {                                                                //~v62LI~
    *Ppnextpos=*Ppnextpos+MOUSE_ESCLEN;                            //~v592I~
    *Ppreslen=*Ppreslen-MOUSE_ESCLEN;                              //~v592I~
  }                                                                //~v62LI~
UTRACEP("%s:return rc=%d,reslen=%d,nextpos=%x\n",UTT,rc,*Ppreslen,*Ppnextpos);//~v5g4R~//~v730R~
    return rc;    //mouse input                                    //~v592R~
}//ukbdlnxm_getmouse                                               //~v592I~
//*********************************************************************//~v592I~
//* chk click                                                      //~v592I~
// 1:next event is release,2:release event was aready read at ukbdlnxc//~v62LI~
//*********************************************************************//~v592I~
//int clickchk(int Pfd,char *Pbuff,int *Plen)                        //~v592I~//~v62LR~
int clickchk(int Pfd,char *Pbuff,int *Plen,char *Ppnext,int Pnextreslen)//~v62LI~
{                                                                  //~v592I~
	struct timeval tv;                                             //~v592I~
    int  len,rc,button;                                            //~v592R~
    fd_set fds;                                                    //~v592I~
    int alreadyread=0;                                             //~v62LI~
//********************************                                 //~v592I~
UTRACED("clickchk",Ppnext,Pnextreslen);                            //~v712R~
    *Plen=0;	                                                   //+v730R~
    tv=Stvclick;             //wait total time                     //~v592R~
//  for (;;)                                                       //~v592R~
//  {                                                              //~v592R~
	  if (Pnextreslen>0)                                           //~v62LR~
      {                                                            //~v62LI~
       if (swMouse2)                                               //~v712I~
       {                                                           //~v712I~
		if (Pnextreslen<MOUSE_ESCLEN2)                             //~v712I~
        {                                                          //~v730I~
UTRACEP("clickchk swMouse2 return 0 nextreslen=%d\n",Pnextreslen); //~v730I~
//printf("clickchk swMouse2 return 0 nextreslen=%d\n",Pnextreslen);//~v730R~
        	return 0;	//not mouse event                          //~v712I~
        }                                                          //~v730I~
        memcpy(Pbuff,Ppnext,(size_t)Pnextreslen);                  //~v712R~
        len=Pnextreslen;                                           //~v712R~
       }                                                           //~v712I~
       else                                                        //~v712I~
       {                                                           //~v712I~
		if (Pnextreslen<MOUSE_ESCLEN)                              //~v62LR~
        {                                                          //~v730I~
UTRACEP("clickchk NOT swMouse2 return 0 nextreslen=%d\n",Pnextreslen);//~v730I~
//printf("clickchk NOT swMouse2 return 0 nextreslen=%d\n",Pnextreslen);//~v730R~
        	return 0;	//not mouse event                          //~v62LI~
        }                                                          //~v730I~
        memcpy(Pbuff,Ppnext,MOUSE_ESCLEN);                         //~v62LI~
        len=MOUSE_ESCLEN;                                          //~v62LI~
       }                                                           //~v712I~
	    alreadyread=1;                                             //~v62LI~
UTRACEP("clickchk set rc=1 nextreslen=%d\n",Pnextreslen);//~v62LI~ //~v730R~
		rc=1;                                                      //~v62LI~
      }                                                            //~v62LI~
      else                                                         //~v62LI~
      {                                                            //~v62LI~
        FD_ZERO(&fds);                                             //~v592I~
//      FD_SET(Pfd,&fds);                                          //~v592I~//~v6BkR~
//      FD_SET((size_t)Pfd,&fds);                                  //~v6BkR~//~v6D5R~
        UFD_SET(Pfd,&fds);                                         //~v6D5I~
        rc=select(Pfd+1,&fds,NULL,NULL,&tv); //tv is remaining time//~v592R~
UTRACEP("clickchk select rc=%d\n",rc);                             //~v5g4I~
      }                                                            //~v62LI~
        switch(rc)                                                 //~v592I~
        {                                                          //~v592I~
        case 0:     //timeout                                      //~v592I~
//      	return click;                                          //~v592R~
UTRACEP("clickchk select rc=0 timeout return 0\n");                //~v730I~
//printf("clickchk select rc=0 timeout return 0\n");               //~v730R~
        	return 0;                                              //~v592I~
        case -1:    //err                                          //~v592I~
UTRACEP("clickchk select rc=-1 error return 0\n");                 //~v730I~
//printf("clickchk select rc=-1 error return 0\n");                //~v730R~
            return 0;                                              //~v592I~
        default:                                                   //~v592I~
          if (!alreadyread)                                        //~v62LI~
//          len=read(Pfd,Pbuff,READSIZE);                          //~v592R~//~v6BxR~
            len=(int)read(Pfd,Pbuff,READSIZE);                     //~v6BxI~
UTRACED("read",Pbuff,len);                                         //~v5g4R~
            if (len>=MOUSE_ESCLEN                                  //~v592R~
            &&  *Pbuff==0x1b                                       //~v592R~
            &&  *(Pbuff+1)=='['                                    //~v592R~
            &&  *(Pbuff+2)==MOUSE_ESCID)                           //~v592R~
            {                                                      //~v592I~
            	if (*(Pbuff+3) & BTN_WHEEL)	//wheel roll up/down   //~v5g4I~
                {                                                  //~v730I~
UTRACEP("clickchk mouse1 BTN_WHEEL return 0 len=%d\n",len);        //~v730R~
//printf("clickchk mouse1 BTN_WHEEL return 0 len=%d\n",len);       //~v730R~
                    return 0;   //ignore read data                 //~v5g4R~
                }                                                  //~v730I~
                button=*(Pbuff+3) & 0x03;                          //~v592I~
                if (button==BTN_RELEASE)                           //~v592I~
                {                                                  //~v592I~
//                  click++;                                       //~v592R~
//                  tv=Stv2;	//wait next down                   //~v592R~
//                  if (click==3)    //                            //~v592R~
//                      return click;                              //~v592R~
          			if (alreadyread)                               //~v62LI~
                    {                                              //~v730I~
UTRACEP("clickchk mouse BTN_RELEASE already read return 2\n");     //~v730I~
                    	return 2;	//id of no read issued         //~v62LI~
                    }                                              //~v730I~
UTRACEP("clickchk mouse BTN_RELEASE not already read return 1\n"); //~v730I~
                    return 1;   //click                            //~v592I~
                }                                                  //~v592I~
//              else                                               //~v592R~
//                  tv=Stv;	//wait next release                    //~v592R~
            }                                                      //~v592I~
            else                                                   //~v712I~
            if (len>=MOUSE_ESCLEN2                                 //~v712I~
            &&  *Pbuff==0x1b                                       //~v712I~
            &&  *(Pbuff+1)=='['                                    //~v712I~
            &&  *(Pbuff+2)==MOUSE_ESCID2)                          //~v712I~
            {                                                      //~v712I~
            	int wheelsw=0,posx=0,posy=0,shiftstat=0;           //~v712I~
				lenMouse2_2=ukbdlnxm_getmouse2(Pbuff,&button,&wheelsw,&shiftstat,&posx,&posy);//~v712R~
            	if (wheelsw)	//wheel roll up/down               //~v712I~
                {                                                  //~v730I~
UTRACEP("clickchk mouse2 wheelsw return 0\n");                     //~v730R~
//printf("clickchk mouse2 wheelsw return 0\n");                    //~v730R~
                    return 0;   //ignore read data                 //~v712I~
                }                                                  //~v730I~
                if (button==BTN_RELEASE)                           //~v712I~
                {                                                  //~v712I~
          			if (alreadyread)                               //~v712I~
                    {                                              //~v730I~
UTRACEP("clickchk mouse2 BTN_RELEASE alreadyread return 2\n");     //~v730I~
                    	return 2;	//id of no read issued         //~v712I~
                    }                                              //~v730I~
UTRACEP("clickchk mouse2 BTN_RELEASE NOT alreadyread return 1\n"); //~v730I~
                    return 1;   //click                            //~v712I~
                }                                                  //~v712I~
  			}                                                      //~v712I~
//          else                                                   //~v592R~
//          {                                                      //~v592R~
//      	    *Plen=len;                                         //~v592R~
//              return click;                                      //~v592R~
//          }                                                      //~v592R~
          	if (alreadyread)                                       //~v62LI~
            	len=0;	//no read new len                          //~v62LI~
        }//sw                                                      //~v592I~
//  }//for                                                         //~v592R~
    *Plen=len;  //next data                                        //~v592I~
UTRACEP("clickchk exit return 0 len=%d\n",len);                    //~v730I~
//printf("clickchk exit return 0 len=%d\n",len);                   //~v730R~
    return 0;                                                      //~v592I~
}//clickchk                                                        //~v592I~
