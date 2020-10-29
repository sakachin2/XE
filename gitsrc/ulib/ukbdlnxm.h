//*CID://+v712R~:                             update#=   64;       //~v5iiR~//+v712R~
//****************************************************************
//ukbdlnxm.h
//****************************************************************
//v712:201023 Manjaro;mouse esc seq 0x1b[<b;x;yM  M:down/m:up      //+v712I~
//v62L:091012_(LNX:BUG)some time cap block start by mouse click;   //~v62LI~
//            Button up/down event was read at once,but generate kbd event twice.//~v62LI~
//v5ii:060710 (LNX:BUG)scancode 0x80(Alt+'9') input ignored because it is same as mouse input id//~v5iiI~
//v5g4:050602 (LNX:BUG)whell mouse(roll up/down middle button(button2)) generate no btunup//~v5g4I~
//            So,ABEND by readbuff overflow;return rollup/dn event //~v5g4I~
//v5g3:050526 (LNX)change default mouse click interval 2 to 6 for drag start(cap start)//~v592I~
//v592:030928 (LNX)mouse support
//****************************************************************
//****************************************************************
//#define UKLM_CLICK_INTVL     2   //200ms                         //~v5g3R~
//#define UKLM_CLICK_INTVL     6   //600ms                           //~v5g3R~//~v62LR~
#define UKLM_CLICK_INTVL     4   //400ms                           //~v62LI~
#define UKLM_DBLCLICK_INTVL  2   //200ms                           //~v592I~

//#define UKLM_MOUSEID   0x80 //scan code for mouse event          //~v5iiR~
#define UKLM_MOUSEID   0xFE //scan code for mouse event,80 is used for A+'9'(x8000) and 0xfe is not part of utf8//~v5iiI~
                                                                   //~v592I~
#define UKLM_CLICK     0x10
#define UKLM_DBLCLICK  0x20
#define UKLM_TRPCLICK  0x40                                        //~v592R~
#define UKLM_DOWN      0x80                                        //~v592R~
#define UKLM_DOWNMASK  0xf0  //if mask is 0 up                     //~v592R~
#define UKLM_BUTTON    0x03  //button no mask                      //~v592I~
#define UKLM_WHEEL     0x08  //wheel button rolled(up:btn=0,dn:btn=1//~v5g4I~

#define MOUSE_ESCLEN   6    //scan code for mouse event
#define MOUSE_ESCLEN2  9    //0x1b[<b;x;yM                         //+v712I~
#define MOUSE_ESCID    'M'  //scan code for mouse event
#define MOUSE_ESCID2   '<'  //scan code for mouse event            //+v712I~
//*********************************************************************
int ukbdlnxm_mouseopt(long Pintvl);                                //~v592R~
//*********************************************************************
int ukbdlnxm_mouseinit(void);
//*********************************************************************//~v592I~
int ukbdlnxm_mouseterm(void);                                      //~v592I~
//*********************************************************************
int ukbdlnxm_getmouse(int Pfd,struct timeval *Pptv,unsigned char **Ppnextpos,int *Preslen,char *Pout,int *Pmodifier);//~v592R~
#define UKLM_RC_DOWN    1	//down event                           //~v592I~
#define UKLM_RC_CLICK   2	//click event                          //~v592I~
#define UKLM_RC_UP      3	//up event                             //~v592I~
#define UKLM_RC_WHEEL   4	//wheel roll event                     //~v5g4I~
