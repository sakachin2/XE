//CID://+vba3R~:        update#=    5                              //+vba3R~
//******************************************************************************//~v003I~
//vba3:170715 msvs2017 warning;(Windows:PTR:64bit,ULONG 32bit,HWND:64bit)//+vba3I~
//vb3w:160621 w64 compiler warning                                 //~vb3wI~
//vak7:130906 redirect memcpy to memmove when overlaped            //~vak7I~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//vafa:120607 (WXE2010)C4700 warning(used uninitialized variable)  //~vafaI~
//va3W:100322 (wxe:BUG)Ctl+F10 is not work(syskey proc returns FALSE width out pass kbd msg)//~va3WI~
//            syskey proc get control by C+(Header line "File" menu is shown shadow like as pushued)//~va3WI~
//va3D:100310 (WXE)Unicode direct input support(A+"+" and Uxxxx)   //~va3DI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~v740I~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//v70f:060801 (BUG)C+10key,C+"-",c+"+" is ignored                  //~v70fI~
//v69i:060523 (WXE)use pgleft/pgright also for elecom hscroll mouse(generate VK_SCROLL+VK_LEFT/VK_RIGHT+VK_SCROLL)//~v69iI~
//v69b:060516 horizontal scroll function by Left/Right key on ScrollLock status//~v69bI~
//v68q:060417 (WXE)set IME font size same as screen font           //~v68qI~
//v67K:060205 (BUG:WXE)beep by Alt+char if not menu key;correction of v51U//~v67KI~
//v67J:060205 (BUG:WXE)menu key activation is done by accelerater checkbox//~v67JI~
//v65d:050728 (WXE)S+prtscr accept as file print key like as XXE(win dose not intercept prtscr)//~v65dI~
//            C+ptrtscr is treated as hardcopy                     //~v65dI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//******************************************************************************//~v003I~
//******************************************************************************//~v003I~
//                                                                 //~v003R~
#include <sys/timeb.h>                                             //~v69bI~
#include    "StdAfx.h"                                             //~v003I~
#include    "imm.h"                                                //~v003M~
                                                                   //~v003I~
#define NO_MACRO_REDIRECT                                          //~vak7I~
#include    "ulib.h"                                               //~vak7I~
#include    "wxedef.h"                                             //~v003I~
#include    "wxe.h"                                                //~v003I~
#include    "wxefile.h"                                            //~v003M~
#include    "wxeDoc.h"                                             //~v003I~
#include    "wxemain.h"                                            //~v003I~
#include    "mainfrm.h"                                            //~v003I~
#include    "wxexei.h"                                             //~v003I~
#include    "wxecsub.h"                                            //~v003I~
#include    "resource.h"                                           //~v003I~
                                                                   //~v003I~
//#include    "ulib.h"                                               //~v003I~//~vak7R~
#include    "udbcschk.h"                                           //~v79zI~
#include    "utrace.h"                                             //~v003I~
//===============================================================================//~v003I~
#define SCROLLLOCKMSGINTVL   50  //interval between SCROLLLOCK up and VK_LEFT/RIGHT down to treate as mouse scroll//~v69bI~
                                                                   //~v69bI~
#define SCAN_NUMPAD7         0x47                                  //~v003I~
#define SCAN_NUMPAD8         0x48                                  //~v003I~
#define SCAN_NUMPAD9         0x49                                  //~v003I~
                                                                   //~v003I~
#define SCAN_SUBTRACT        0x4a                                  //~v003I~
                                                                   //~v003I~
#define SCAN_NUMPAD4         0x4b                                  //~v003I~
#define SCAN_NUMPAD5         0x4c                                  //~v003I~
#define SCAN_NUMPAD6         0x4d                                  //~v003I~
                                                                   //~v003I~
#define SCAN_ADD             0x4e                                  //~v003I~
                                                                   //~v003I~
#define SCAN_NUMPAD1         0x4f                                  //~v003I~
#define SCAN_NUMPAD2         0x50                                  //~v003I~
#define SCAN_NUMPAD3         0x51                                  //~v003I~
#define SCAN_NUMPAD0         0x52                                  //~v003I~
                                                                   //~v003I~
#define SCAN_DECIMAL         0x53                                  //~v003I~
//===============================================================================//~v003I~
//rc:0:call defaultwindowproc                                      //~v003R~
//===============================================================================//~v003I~
int CWxemain::onkeyup(UINT nChar, UINT nRepCnt, UINT nFlags)       //~v003R~
{                                                                  //~v003I~
    struct _timeb ctm;                                             //~v69bI~
//    int shiftchng=0,sstat=0,rc=FALSE;                            //~v003R~
////*************************                                      //~v003R~
UTRACEP("onkeyup ch=%x,rep=%x,flag=%x\n",nChar,nRepCnt,nFlags);    //~v79zI~
//    switch(nChar)                                                //~v003R~
//    {                                                            //~v003R~
//    case VK_INSERT:                                              //~v003R~
//    case VK_DELETE:                                              //~v003R~
//    case VK_NUMPAD0:                                             //~v003R~
//        sstat=ugetkbdshiftstatus();                              //~v003R~
//        if (sstat)      //with shift or ctl                      //~v003R~
//            rc=TRUE;    //call xe                                //~v003R~
//        break;                                                   //~v003R~
//    case VK_F6:                                                  //~v003R~
//        sstat=ugetkbdshiftstatus();                              //~v003R~
//        rc=TRUE;    //call xe                                    //~v003R~
//        break;                                                   //~v003R~
//    }                                                            //~v003R~
//    if (rc==TRUE)                                                //~v003R~
//        kbdkeyin(sstat|WXEKBDMSG_KEYUP,nChar,nRepCnt,nFlags);//xe called by this key//~v003R~
//    return rc;                                                   //~v003R~
//** ACCELERATOR is deleted from resource file,so key down acceptable//~v003I~
    if (nChar==VK_PRINT       //not generated                      //~v003I~
    ||  nChar==VK_SNAPSHOT)    //but thes is generated bt PrtScr key//~v003I~
    {                                                              //~v003I~
        if (Mpmainframe)                                           //~v003I~
        {                                                          //~v003I~
//  		if (!(ugetkbdshiftstatus() & WXEKBDMSG_SHIFTKEY))//without shift//~v003R~
//*shift,ctl                                                       //~v003I~
  		  if (ugetkbdshiftstatus(nChar) & WXEKBDMSG_SHIFTKEY)//S+PrtScr//~v65dR~
            ((CMainFrame*)Mpmainframe)->PostMessage(WM_COMMAND,ID_FILE_PRINT,0);//~v65dI~
          else                                                     //~v65dI~
            ((CMainFrame*)Mpmainframe)->PostMessage(WM_COMMAND,ID_FILE_SCRPRT,0);//~v003R~
        }                                                          //~v003I~
    }                                                              //~v003I~
    else                                                           //~v69bI~
    if (nChar==VK_SCROLL)   //mouse h-scroll generate scroll down/up the vk_left/right//~v69bI~
    {                                                              //~v69bI~
		_ftime(&ctm);		//chk later lbdown                     //~v69bI~
		Mscrolllocktime=ctm.time;		//chk later lbdown         //~v69bI~
		Mscrolllockmsec=ctm.millitm;	//chk later lbdown         //~v69bI~
        Mscrolllocksw=1;	//start of scroll lock                 //~v69iR~
    }                                                              //~v69bI~
	return FALSE;                                                  //~v003I~
}//wxescr_keyup                                                    //~v003I~
//===============================================================================//~v003I~
//rc:0:call defaultwindowproc                                      //~v003I~
//===============================================================================//~v003I~
int CWxemain::onchar(UINT nChar, UINT nRepCnt, UINT nFlags)        //~v003I~
{                                                                  //~v003I~
	int sstat;                                                     //~v003I~
//*************************                                        //~v003I~
UTRACEP("onchar char=%x,rep=%d,flag=%x\n",nChar,nRepCnt,nFlags);   //~v79zI~
//  sstat=ugetkbdshiftstatus();                                    //~v55cR~
    sstat=ugetkbdshiftstatus(nChar);                               //~v55cI~
  if ((nFlags & 0xff)==(UINT)Maltkeyscancode)     //scancode for onchar to chk unicode raw code mode//~va3DR~
    kbdkeyin(sstat|WXEKBDMSG_ONCHAR|WXEKBDMSG_RAWMODE,nChar,nRepCnt,nFlags);//xe called by this key//~va3DR~
  else                                                             //~va3DI~
    kbdkeyin(sstat|WXEKBDMSG_ONCHAR,nChar,nRepCnt,nFlags);//xe called by this key//~v003R~
    return TRUE;                                                   //~v003I~
}//onchar                                                          //~v69bR~
//===============================================================================//~v003I~
//rc:0:call defaultwindowproc                                      //~v003I~
//===============================================================================//~v003I~
int CWxemain::onkeydown(UINT nChar, UINT nRepCnt, UINT nFlags)     //~v003R~
{                                                                  //~v003I~
//  int shiftchng=0,rc=FALSE,sstat,scanc;                          //~v003R~//~vafhR~
    int rc=FALSE,sstat,scanc;                                      //~vafhI~
    struct _timeb ctm;                                             //~v69bI~
    int rulerid;                                                   //~v740I~
//************************************                             //~v003I~
UTRACEP("onkeydown ch=%x,rep=%x,flag=%x\n",nChar,nRepCnt,nFlags);  //~v79zI~
//  sstat=ugetkbdshiftstatus();                                    //~v55cR~
    sstat=ugetkbdshiftstatus(nChar);                               //~v55cI~
    scanc=nFlags & 0xff;     //scancode                            //~v003I~
    if (sstat & WXEKBDMSG_SHIFTKEY                                 //~v73tI~
    &&  sstat & WXEKBDMSG_CTLKEY)                                  //~v73tI~
    {                                                              //~v73tI~
//        switch(nChar)                                            //~v740R~
//        {                                                        //~v740R~
//        case VK_F1:                                              //~v740R~
//            scrsetruler(WXERULER_V);                             //~v740R~
//            return TRUE;    //no kbdinput  process               //~v740R~
//        case VK_F2:                                              //~v740R~
//            scrsetruler(WXERULER_H);                             //~v740R~
//            return TRUE;    //no kbdinput  process               //~v740R~
//        case VK_F3:                                              //~v740R~
//            scrsetruler(WXERULER_VH);                            //~v740R~
//            return TRUE;    //no kbdinput  process               //~v740R~
//        }                                                        //~v740R~
        rulerid=chkrulerkey(nChar);                                //~v740I~
        if (rulerid)                                               //~v740I~
        {                                                          //~v740I~
            scrsetruler(rulerid);                                  //~v740I~
            return TRUE;    //no kbdinput  process                 //~v740I~
        }                                                          //~v740I~
    }                                                              //~v73tI~
//  switch(nChar)                                                  //~v003R~
    for (;;)      //for break use                                  //~v003I~
    {                                                              //~v003R~
//S+ins,S+del,C+ins miss keydown,so use key up                     //~v003I~
//  case VK_INSERT:                                                //~v003R~
//  case VK_DELETE:                                                //~v003R~
//  case VK_NUMPAD0:                                               //~v003R~
//      if (sstat)		//with shift or ctl                        //~v003R~
//      	break;      //wait key up                              //~v003R~
//      rc=TRUE;	//call xe                                      //~v003R~
//  	break;                                                     //~v003R~
//  case VK_F6:                                                    //~v003R~
//  	break;                                                     //~v003R~
//  default:                                                       //~v003R~
        if (nChar==VK_PROCESSKEY)                                  //~v003I~
        {                                                          //~v003I~
        	rc=FALSE;		//default proc;for ime,avoid csr up/down//~v003I~
            break;                                                 //~v003I~
        }                                                          //~v003I~
        if (nChar>=VK_F1 && nChar <=VK_F12)                        //~v003I~
        {                                                          //~v003I~
        	rc=TRUE;		//process key down                     //~v003I~
            break;                                                 //~v003I~
        }                                                          //~v003I~
    	if (nChar==VK_SCROLL)   //mouse h-scroll generate scroll down/up the vk_left/right//~v69bI~
    	{                                                          //~v69bI~
//          wxe_scrollh(0,nChar);	//end scroll by mouse(reset flag)//~v69iR~
        	Mscrolllocksw=0; 	//VK_SCROLL off                    //~v69iR~
        	rc=FALSE;		//default proc                         //~v69bI~
            break;                                                 //~v69bI~
    	}                                                          //~v69bI~
        if (nChar==VK_LEFT || nChar==VK_RIGHT)	//to be chk scrolllock on//~v69bR~
        {                                                          //~v69bI~
          if (Mscrolllocksw)	//after VK_SCROLL keyup            //~v69iR~
          {                                                        //~v69iI~
	    	_ftime(&ctm);                                          //~v69bI~
    	    ctm.time-=Mscrolllocktime;                             //~v69bI~
        	if (ctm.time==1 || ctm.time==0)                        //~v69bI~
        	{                                                      //~v69bI~
        		ctm.time=ctm.time*1000+ctm.millitm-Mscrolllockmsec;//~v69bR~
            	if (ctm.time<SCROLLLOCKMSGINTVL)  //interval between SCROLLLOCK up and VK_LEFT/RIGHT down to treate as mouse scroll//~v69bR~
                	Mscrolllocksw=2;	//start of scroll          //~v69iR~
            }                                                      //~v69iI~
            if (Mscrolllocksw==2)                                  //~v69iR~
            {                                                      //~v69iI~
                {                                                  //~v69iI~
//          		wxe_scrollh(Mscrollctr,nChar);	//notify to func_left/right to scroll by mouse//~v69iR~
            		wxe_scrollhbar(Mscrollctr,(nChar==VK_LEFT?-1:1));	//notify to func_left/right to scroll by mouse//~v69iI~
				    scrinvalidate();                               //~v69iI~
                    return TRUE;    //no kbdinput  process         //~v69iI~
                }                                                  //~v69iI~
        	}                                                      //~v69bI~
        	                                                       //~v69bI~
        	rc=TRUE;		//process key down                     //~v69bI~
            break;                                                 //~v69bI~
          }//after VK_SCROLL key up                                //~v69iI~
        }                                                          //~v69bI~
//        if (nChar==VK_BACK                                       //~v003R~
//        ||  nChar==VK_TAB                                        //~v003R~
//        ||  nChar==VK_RETURN                                     //~v003R~
//        ||  nChar==VK_ESCAPE)                                    //~v003R~
//        {                                                        //~v003R~
//            if (sstat)  // with shift or ctl                     //~v003R~
//                rc=TRUE;    //without shift wait onchar          //~v003R~
//            break;                                               //~v003R~
//        }                                                        //~v003R~
        if (nChar==VK_DECIMAL|| (nChar>=VK_NUMPAD1 && nChar <=VK_NUMPAD9))//~v003R~
        {                                                          //~v003M~
        	if (sstat)	//(ctl under numlock on)                   //~v003R~
            	rc=TRUE;	//without shift or ctl,wait on char    //~v003M~
            break;                                                 //~v003M~
        }                                                          //~v003M~
        if (nChar>=VK_MULTIPLY && nChar <=VK_DIVIDE)	//num pad key except decimal//~v003M~
        {                                                          //~v003M~
        	if (sstat & WXEKBDMSG_CTLKEY)	//with ctl key         //~v003M~
            	rc=TRUE;                    //wait onchar when without ctl key//~v003M~
        	break;                                                 //~v003M~
        }                                                          //~v003M~
        if (nChar==VK_CONTROL && sstat & WXEKBDMSG_RCTLKEY)	//right ctl key down//~v55cI~
        {                                                          //~v55cI~
            rc=TRUE;                    //wait onchar when without ctl key//~v55cI~
        	break;                                                 //~v55cI~
        }                                                          //~v55cI~
    	if (nFlags & ENHANCED_KEY)	//ins,up etc                   //~v003M~
        {                                                          //~v003I~
        	rc=TRUE;		//process key down                     //~v003M~
        	break;                                                 //~v003I~
        }                                                          //~v003I~
//      if ((scanc>=SCAN_NUMPAD7 && scanc<=SCAN_NUMPAD3) //1-9,-,+ //~v003R~
//      &&  (scanc!=SCAN_SUBTRACT)                                 //~v003R~
//      &&  (scanc!=SCAN_ADD)) //except 0,                         //~v003R~
        if ((nChar>=VK_PRIOR && nChar <=VK_DOWN)	//numpad key(numlock off) miss enhanced flag//~v003R~
        ||  (nChar==VK_INSERT)                                     //~v003I~
		||  (nChar==VK_DELETE))	//numpad key(numlock off) miss enhanced flag//~v003I~
        {                                                          //~v003R~
            rc=TRUE;        //process key down                     //~v003R~
            break;                                                 //~v003R~
        }                                                          //~v003R~
        if (nChar==VK_CLEAR)                                       //~v70fI~
        {                                                          //~v70fI~
            rc=TRUE;        //process key down                     //~v70fI~
            break;                                                 //~v70fI~
        }                                                          //~v70fI~
        break;  //unconditional                                    //~v003I~
	}//switch                                                      //~v003R~
    if (rc==TRUE)                                                  //~v003R~
	    kbdkeyin(sstat|WXEKBDMSG_KEYDOWN,nChar,nRepCnt,nFlags);//xe called by this key//~v003I~
    return rc;                                                     //~v003R~
}//keydown                                                         //~v003R~
//===============================================================================//~v740I~
//rc:0:call defaultwindowproc                                      //~v740I~
//p1:event->keycode                                                //~v740I~
//p2:event->hardware_keycode                                       //~v740I~
//p3:event->state                                                  //~v740I~
//p4:event->string                                                 //~v740I~
//p5:event->length                                                 //~v740I~
//===============================================================================//~v740I~
int CWxemain::chkrulerkey(UINT nChar)                              //~v740R~
{                                                                  //~v740I~
	int ch,ii;                                                     //~v740I~
//************************************                             //~v740I~
UTRACEP("chkrulerkey key=%x,optparm=%s\n",nChar,Mrulerkey);        //~v740I~
    if (nChar>=VK_F1 && nChar<=VK_F12)                             //~v740I~
        ch=(int)(nChar-VK_F1+1);                                   //~v740I~
    else                                                           //~v740I~
    if (nChar<' ')                                                 //~v740I~
    	return 0;                                                  //~v740I~
    else                                                           //~v740I~
        ch=toupper(nChar)&0x7f;	//drop 0x80                        //~v740I~
    for (ii=0;ii<3;ii++)                                           //~v740I~
    	if (Mrulerkey[ii]==ch)                                     //~v740I~
        	return ii+1;                                           //~v740I~
    return 0;                                                      //~v740I~
}//chkrulerkey                                                     //~v740I~
//===============================================================================//~v003I~
//return TRUE if redraw required                                   //~v003R~
//===============================================================================//~v003I~
int CWxemain::kbdkeyin(int Popt,UINT nChar, UINT nRepCnt, UINT nFlags)//~v003I~
{                                                                  //~v003I~
//  int shiftchng=0,rc;                                            //~v003I~//~vafhR~
    int rc;                                                        //~vafhI~
//************************************                             //~v003I~
	if (Mcpcopypansw)	                                           //~v003I~
    {                                                              //~v003I~
    	cpdrawpan(Mcellcopy1.y,Mcellcopy2.y,-1);                   //~v003I~
    	Mcpcopypansw=0;		                                       //~v003I~
    }                                                              //~v003I~
    rc=wxe_kbdmsg(Popt,nChar,nRepCnt,nFlags);//xe called by this key//~v003I~
    if (rc==-1)                                                    //~v003I~
    	exitmain();                                                //~v003I~
    scrinvalidate();                                               //~v003R~
    return rc;                                                     //~v003R~
}//kbdkeyin                                                        //~v003I~
//===============================================================================//~v003I~
// appl should ret 0 if it process this msg                        //~v003R~
//===============================================================================//~v003I~
int CWxemain::syskeyproc(UINT Pmessage,WPARAM wParam,LPARAM lParam)//~v003R~
{                                                                  //~v003I~
//  int shiftchng=0,rc=FALSE,sstat,mtype=0;                        //~vafaR~//~vafhR~
    int rc=FALSE,sstat,mtype=0;                                    //~vafhI~
    UINT flags,uch,rctr;                                           //~v003I~
static int Srawunicodemode;                                        //~va3WI~
//***************************                                      //~v003I~
//  sstat=ugetkbdshiftstatus();                                    //~v55cR~
UTRACEP("syskeyproc msg=%x,wp=%x,lp=%x\n",Pmessage,wParam,lParam); //~v79zI~
//  uch=wParam;                                                    //~v003I~//~vb3wR~
    uch=(UINT)wParam;                                              //~vb3wI~
    sstat=ugetkbdshiftstatus(uch);                                 //~v55cI~
    rctr=(lParam & 0xffff);	//repeatctr                            //~v003I~
//  flags=(lParam>>16);                                            //~v003R~//~vb3wR~
    flags=(UINT)(lParam>>16);                                      //~vb3wI~
    if (uch==VK_MENU)                                              //~v003I~
    {                                                              //~va3DI~
        Maltkeyscancode=flags & 0xff;     //scancode for onchar to chk unicode raw code mode//~va3DR~
		if (Pmessage==WM_SYSKEYUP)                                 //~va3WI~
			Srawunicodemode=0;                                     //~va3WI~
        else                                                       //~va3WI~
		if (Pmessage==WM_SYSKEYDOWN)                               //~va3WI~
			Srawunicodemode=1;                                     //~va3WI~
UTRACEP("syskeyproc MENU rawcodemode=%x\n",Srawunicodemode);       //~va3WI~
//      if (Museact)                                               //~v67JR~
        if (Musemk)                                                //~v67JI~
    		return FALSE;                                          //~v003R~
        else                                                       //~v003I~
    		return TRUE;                                           //~v003I~
    }                                                              //~va3DI~
    if (uch>=0xf0)	//ime?                                         //~v003I~
    	return FALSE;                                              //~v003I~
	switch(Pmessage)                                               //~v003I~
    {                                                              //~v003I~
	case WM_SYSKEYUP:                                              //~v003I~
UTRACEP("syskeyup\n");                                             //~v003I~
        mtype=WXEKBDMSG_KEYUP;                                     //~v003I~
//        switch(uch)                                              //~v003R~
//        {                                                        //~v003R~
//        case VK_BACK:   //Alt+BS miss syskeydown and syschar     //~v003R~
//            rc=TRUE;                                             //~v003R~
//            break;                                               //~v003R~
//        }                                                        //~v003R~
//  	if (!Museact)       //no accelerator usage                 //~v67JR~
    	if (!Musemk)         //no menu key usage                   //~va3DR~
          if (uch=='F' //file                                      //~va3DI~
          ||  uch=='E' //edit                                      //~va3DI~
          ||  uch=='S' //setup                                     //~va3DI~
          ||  uch=='P' //prt setup                                 //~va3DI~
          ||  uch=='H')//help                                      //~va3DI~
        	return TRUE;	//skip default msgproc                 //~v003I~
        break;                                                     //~v003I~
	case WM_SYSKEYDOWN:                                            //~v003R~
UTRACEP("syskey down\n");                                          //~v003I~
        mtype=WXEKBDMSG_KEYDOWN;                                   //~v003I~
        switch(uch)                                                //~v003I~
        {                                                          //~v003I~
		case VK_KANJI:		//          0x19                       //~v003I~
		case VK_CONVERT:	//henkan        0x1C                   //~v003I~
		case VK_NONCONVERT:  //muhenkan   0x1D                     //~v003R~
		case VK_MODECHANGE:  //romaji?   0x1F                      //~v003R~
//      case VK_BACK:  	//Alt+BS miss syskeydown and syschar       //~v003R~
            break;                                                 //~v003I~
        case VK_ADD:  	//10 key "+"  ,trigger of UCS2 RAW code input//~va3DM~
			if (Srawunicodemode & 0x01)	//with Altkey              //~va3WI~
				Srawunicodemode|=0x02;	//rawcode mode             //~va3WI~
UTRACEP("syskey down VK_ADD,rawcodemode=%x\n",Srawunicodemode);    //~va3WR~
            break;                                                 //~va3DI~
        default:                                                   //~v003I~
#ifndef AAA	//back to old logic                                    //~va3WR~
UTRACEP("syskey down other,rawcodemode=%x\n",Srawunicodemode);     //~va3WI~
			if (Srawunicodemode & 0x02)	//rawcode mode             //~va3WI~
        		return FALSE;	//skip default msgproc             //~va3WI~
        	rc=TRUE;                                               //~v003I~
//      	if (Museact)                                           //~v67JR~
        	if (Musemk)                                            //~v67JI~
            	if (uch=='F' //file                                //~v003I~
            	||  uch=='E' //edit                                //~v003I~
            	||  uch=='S' //setup                               //~v003I~
            	||  uch=='P' //prt setup                           //~v003I~
            	||  uch=='H')//help                                //~v003I~
                    rc=FALSE;                                      //~v003I~
#else                                                              //~va3DI~
    	if (!Musemk)       //no menu key    usage                  //~va3DI~
          if (uch=='F' //file                                      //~va3DI~
          ||  uch=='E' //edit                                      //~va3DI~
          ||  uch=='S' //setup                                     //~va3DI~
          ||  uch=='P' //prt setup                                 //~va3DI~
          ||  uch=='H')//help                                      //~va3DI~
        	return TRUE;	//skip default msgproc                 //~va3DI~
#endif                                                             //~va3DI~
        }                                                          //~v003I~
        break;                                                     //~v003I~
	case WM_SYSCHAR:                                               //~v003I~
UTRACEP("syskey onchar\n");                                        //~v003I~
        rc=TRUE;                                                   //~v67KI~
//      if (!Museact)		//no use accelerator                   //~v67JR~
//      if (!Musemk)		//no use menukey                       //~v67KR~
        if (Musemk)		//use menukey                              //~v67KI~
            if (uch=='f' //file                                    //~v003R~
            ||  uch=='e' //edit                                    //~v003R~
            ||  uch=='s' //setup                                   //~v003R~
            ||  uch=='p' //prt setup                               //~v003R~
            ||  uch=='h')//help                                    //~v003R~
//              return TRUE;    //ignore msg                       //~v67KR~
                rc=FALSE;                                          //~v67KI~
//      mtype=WXEKBDMSG_ONCHAR;                                    //~v67KR~
//      break;                                                     //~v67KR~
#ifndef AAA	//avoid input twice onkeydown and onchar                                                         //~va3DR~//~va3WR~
        return rc;                                                 //~v67KI~
#else                                                              //~va3WI~
        mtype=WXEKBDMSG_ONCHAR;                                    //~va3DI~
#endif                                                             //~va3DI~//~va3WM~
    }                                                              //~v003I~
    if (rc==TRUE)                                                  //~v003R~
	    kbdkeyin(sstat|mtype|WXEKBDMSG_SYSKEY,uch,rctr,flags);//xe called by this key//~v003R~
UTRACEP("syskey return %d\n",rc);                                  //~v003I~
    return rc;                                                     //~v003R~
}//syskeyproc                                                      //~v003R~
//===============================================================================//~v003I~
// ime msg seq                                                     //~v003R~
//       sta..compo..compo..char..compo..compo..char..end          //~v003I~
//===============================================================================//~v003I~
//int CWxemain::kbdimectl(HWND Phwnd,UINT Pmsgid)                  //~v79zR~
int CWxemain::kbdimectl(HWND Phwnd,UINT Pmsgid,WPARAM wParam,LPARAM lParam)//~v79zI~
{                                                                  //~v003I~
	HIMC hIMC;                                                     //~v003I~
	COMPOSITIONFORM cf;                                            //~v003I~
    int row,col,swset;                                             //~v003R~
    LOGFONT logfont;                                               //~v68pI~
    int rc;                                                        //~v68pI~
    int nodefprocsw=0;                                             //~v79zI~
    int ucs;                                                       //~v79zM~
//************************************                             //~v003I~
    hIMC=ImmGetContext(Phwnd);                                     //~v68qI~
	switch(Pmsgid)                                                 //~v003I~
    {                                                              //~v003I~
	case WM_IME_COMPOSITION:      //conversion start               //~v003I~
    	Mimeonsw=1;                                                //~v003I~
    	if (Mnewimephrase)			//after CHAR transfered        //~v003I~
        	swset=1;                                               //~v003I~
        else                                                       //~v003I~
        	swset=0;                                               //~v003R~
        if (WXEI_ISWIDEAPI())                                      //~v79zR~
    		if (lParam & GCS_RESULTSTR)                            //~v79zI~
				kbdime_getchar(0,hIMC,Pmsgid,wParam,lParam);       //~v79zR~
        break;                                                     //~v003I~
	case WM_IME_ENDCOMPOSITION:      //conversion start            //~v003I~
    	Mimeonsw=0;                                                //~v003I~
        swset=0;                 //not of v68q;but missing setup BUG//~v68qR~
    	break;                                                     //~v003I~
	case WM_IME_CHAR:            //send DBCS                       //~v003I~
    	Mnewimephrase=1;		//required at next COMOSITION msg  //~v003I~
        swset=0;                                                   //~v003I~
  		if (WXEI_ISWIDEAPI()                                       //~v79zI~
  		&&  Mwxeintf.WXEIimeucsctr)                                //~v79zI~
  		{                                                          //~v79zI~
			ucs=kbdime_getchar(0,0/*himc*/,Pmsgid,0/*wparam*/,0/*lparam*/);//~v79zR~
    		kbdkeyin(WXEKBDMSG_ONCHARUCS,(UINT)ucs,1/*rep*/,0/*flag*/);//xe called by this key//~v79zR~
		    nodefprocsw=1;     //kill following WM_CHAR msg        //~v79zI~
  		}                                                          //~v79zI~
        break;                                                     //~v003I~
    default:					//WM_IME_STARTCOMPOSITION //open   //~v003I~
        	swset=1;                                               //~v003I~
    	if (Mpfont)                                                //~v68qI~
        {                                                          //~v68qI~
    		rc=Mpfont->GetLogFont(&logfont);                       //~v68qI~
UTRACEP("kbdimectl scr logfont rc=%d,face=%s,h=%ld,w=%ld\n",rc,logfont.lfFaceName,logfont.lfHeight,logfont.lfWidth);//~v68qI~
			if (rc)                                                //~v68qI~
            {                                                      //~v68qI~
	    		rc=ImmSetCompositionFont(hIMC,&logfont);           //~v68qI~
UTRACEP("kbdimectl set logfont rc=%d\n",rc);                       //~v68qI~
			}                                                      //~v68qI~
		}                                                          //~v68qI~
    }                                                              //~v003I~
    rc=ImmGetCompositionFont(hIMC,&logfont);                       //~v68pI~
UTRACEP("kbdimectl logfont rc=%d,face=%s,h=%ld,w=%ld\n",rc,logfont.lfFaceName,logfont.lfHeight,logfont.lfWidth);//~v68pI~
    if (swset)                                                     //~v003I~
    {                                                              //~v003I~
    	Mnewimephrase=0;		//position set                     //~v003I~
        wxe_getcurpos(&row,&col);                                  //~v003R~
//      hIMC=ImmGetContext(Phwnd);                                 //~v68qR~
        cf.dwStyle=CFS_POINT;                                      //~v003R~
        cf.ptCurrentPos.x=XX(col);                                 //~v003R~
        cf.ptCurrentPos.y=YY(row);                                 //~v003R~
        ImmSetCompositionWindow(hIMC,&cf);                         //~v003R~
//      ImmReleaseContext(Phwnd,hIMC);                             //~v79zR~
    }                                                              //~v003I~
    ImmReleaseContext(Phwnd,hIMC);                                 //~v79zI~
//UTRACEP("kbdimectl nodefproc=%d,row=%d,col=%d,swset=%d,new=%d,msg=%08x\n",nodefprocsw,row,col,swset,Mnewimephrase,Pmsgid);//~vafaR~
//  return 0;                                                      //~v79zR~
    return nodefprocsw;                                            //~v79zI~
}//kbdimectl                                                       //~v003R~
//===============================================================================//~v79zI~
// get ucs string                                                  //~v79zI~
//===============================================================================//~v79zI~
//int CWxemain::kbdime_getchar(int Popt,ULONG Phimc,UINT Pmsgid,WPARAM wParam,LPARAM lParam)//~@@@@R~
int CWxemain::kbdime_getchar(int Popt,HIMC Phimc,UINT Pmsgid,WPARAM wParam,LPARAM lParam)//~@@@@I~
{                                                                  //~v79zI~
	HIMC himc;                                                     //~v79zI~
    int offs,readlen;                                              //~v79zR~
    UCHAR *pdata;                                                  //~v79zI~
    int ucs=0;                                                     //~v79zR~
//************************************                             //~v79zI~
    switch(Pmsgid)                                                 //~v79zI~
    {                                                              //~v79zI~
	case WM_IME_COMPOSITION:      //conversion start               //~v79zI~
    	himc=(HIMC)Phimc;                                          //~v79zI~
//      pdata=(UCHAR*)(ULONG)Mwxeintf.WXEIimeucs;                  //~v79zI~//+vba3R~
        pdata=(UCHAR*)(ULPTR)Mwxeintf.WXEIimeucs;                  //+vba3I~
        readlen=ImmGetCompositionStringW(himc,GCS_RESULTSTR,NULL,0);  //get requred len//~v79zR~
        ImmGetCompositionStringW(himc,GCS_RESULTSTR,pdata,readlen);//~v79zR~
    	Mwxeintf.WXEIimeucsctr=readlen/sizeof(USHORT);             //~v79zR~
    	Mwxeintf.WXEIimeucsoffs=0;                                 //~v79zR~
UTRACEP("ime_getchar RESULTSTR ucscnt=%d\n",Mwxeintf.WXEIimeucsctr);//~v79zR~
UTRACED("ime_getchar RESULTSTR",Mwxeintf.WXEIimeucs,readlen);      //~v79zR~
        break;                                                     //~v79zI~
	case WM_IME_CHAR:      //conversion start                      //~v79zR~
    	offs=Mwxeintf.WXEIimeucsoffs;                              //~v79zR~
    	readlen=Mwxeintf.WXEIimeucsctr;                            //~v79zR~
        ucs=(int)Mwxeintf.WXEIimeucs[offs++];                      //~v79zR~
    	Mwxeintf.WXEIimeucsoffs=offs;                              //~v79zR~
        if (offs>=readlen)                                         //~v79zI~
        {                                                          //~v79zI~
	    	Mwxeintf.WXEIimeucsctr=0;                              //~v79zR~
        }                                                          //~v79zI~
UTRACEP("ime_getchar getucs ucs=%04x,offs=%d\n",ucs,offs);         //~v79zI~
        break;                                                     //~v79zI~
    }                                                              //~v79zI~
    return ucs;                                                    //~v79zR~
}//kbdime_getchar                                                  //~v79zR~
