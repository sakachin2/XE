//*CID://+v7fxR~:                               update#=  599;     //+v7fxR~
//*********************************************************************//~v55cI~
//* wxe interface definition-3                                     //~v55cI~
//* rctl; menu enability;openwith;at cmd                           //~v55WR~
//*********************************************************************//~v55cI~
//v7fx:251205 (Wxe)addtionally to WINCON, optionally chk EOL for also Wxe.//+v7fxI~
//vbEd:251107 (WXE)hcopy by saving TextOutW to buffer              //~vbEdI~
//vbAn:240627 for performance bypass glyphchk when help            //~vbAnI~
//vbzM:240408 (WXE) support hardcopy function                      //~vbzMI~
//vbz4:240120 try vbz3 to WXE                                      //~vbz4I~
//vbdn:171125 disable filemenu depending curent pcw type           //~vbdnI~
//vb2W:160404 W32 64 compiler warning                              //~vb2WI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v73yI~
//v68n:060414 (WXEXXE)Drag&Drop:accept opened dir as target dir when target dir line is not selectedd.//~v68nI~
//v68g:060330 (WXE)dnd copy loop chk(case of target path is under source path)//~v68gR~
//v68e:060330 accept drop on not dirlist for internal dnd          //~v68eI~
//v68d:060329 (BUG:WXE)dnd copy;require /s (sub dir copy)          //~v68dI~
//v686:060323 dnd support by paste                                 //~v686I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v682:060313 (WXE:BUG)menu enable re-evaluation requred for drag selection on dirlist;and also when reset by esc key//~v682I~
//v67E:051229 (WXE:BUG) dup atcmd msg for dup sleep cmd            //~v67EI~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~v67CI~
//v63i:050507 (WXE)dragdrop by copy/paste                          //~v63hI~
//v63h:050504 (WXE)support DragOut                                 //~v63hI~
//v56g:040404 (WXE)use lcmd to reset filename list top entry       //~v56gI~
//v56b:040403 (WXE)openwith menu item enable for also filename history list//~v56bI~
//v568:040402 (WXE:BUG)ignore association for dir(force open by xe)//~v568I~
//v564:040326 (WIN)at cmd ignore err option "-i"                   //~v564I~
//v560:040324 (WXE)break sleep by esc*2                            //~v560R~
//v55Z:040324 (WXE)ctl multicmd by wxe to display intermediate screen//~v55ZI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55WI~
//v55U:040321 (WXE)openwith when dblclick on filenamelist/dirlist if associated//~v55UI~
//v55G:040315 (WXE)Beep option on setup dialog                     //~v55GI~
//v55F:040314 (WXE)english help                                    //~v55FI~
//v55u:040229 (WXE)add open with for dir-list                      //~v55uI~
//v55t:040229 disable "save" popup menu when not edit screen       //~v55tI~
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //~v55qI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//*********************************************************************//~v55cI~
#include <time.h>                                                  //~v55cI~
#include <stdio.h>                                                 //~v55cI~
#include <stdlib.h>                                                //~v55cI~
#include <string.h>                                                //~v55cI~
#include <io.h>                                                    //~v568I~
//*************************************************************    //~v55cI~
#include <windows.h>                                               //~v55cI~
//*************************************************************    //~v55cI~
#include <ulib.h>                                                  //~v55cI~
#include <uque.h>                                                  //~v55cI~
#include <ufile.h>                                                 //~v55cI~
#include <uerr.h>                                                  //~v55cI~
#include <ualloc.h>                                                //~v55cI~
#include <utrace.h>                                                //~v55cI~
#include <uproc.h>                                                 //~v55uI~
#include <uparse.h>                                                //~v55WI~
#include <ustring.h>                                               //~v56bI~
#include <uwinsub.h>                                               //~v56bI~
#include <uftp.h>                                                  //~v68eI~
#include <utf22.h>                                                 //~vbz4I~
#include <uvio.h>                                                  //~vbAnI~
#include <uvio2.h>                                                 //~vbAnI~
                                                                   //~v55cI~
#include "xe.h"                                                    //~v55cI~
#include "xescr.h"                                                 //~v55cI~
#include "xefile.h"                                                //~v55cI~
#include "xepan.h"                                                 //~v55cI~
#include "xepan22.h"                                               //~v56bI~
#include "xegbl.h"                                                 //~v55cI~
#include "xedir.h"                                                 //~v55uI~
#include "xedlcmd.h"                                               //~v55uR~
#include "xedlcmd2.h"                                              //~v55uI~
#include "xedlcmd6.h"                                              //~v56bI~
#include "xefunc.h"                                                //~v55WI~
#include "xescr2.h"                                                //~v63hI~
#include "xecsr.h"                                                 //~v63hI~
                                                                   //~v55cI~
#include "wxemain.h"                                               //~v55cI~
#include "wxexei.h"                                                //~v55cI~
#include "wxecsub.h"                                               //~v55cI~
#include "wxexei3.h"                                               //~v56gI~
#include "wxefile.h"                                               //~v76jI~
//*************************************************************    //~v55WI~
extern WXEINTF *Spwxei;		//defined in wxexei.c                  //~v55WI~
//*************************************************************    //~v55cI~
//int wxegetdirlistfname(PUCLIENTWE Ppcw,char *Pfpath);            //~v55UR~
int wxe_killsleeptime(void);                                       //~v76jR~
//*************************************************************    //~v55cI~
//*return RCTL usage status                                        //~v55cI~
//*************************************************************    //~v55cI~
int wxe_getrctl(void)                                              //~v55cI~
{                                                                  //~v55cI~
//***********************                                          //~v55cI~
	return UCBITCHK(Gopt,GOPTRCTLENTER)!=0;                        //~v55cI~
}//wxe_getrctl                                                     //~v55cI~
//*************************************************************    //~v55cI~
//*issue opt rctl cmd                                              //~v55cI~
//*************************************************************    //~v55cI~
int wxe_setrctl(int Prctlsw)                                       //~v55cI~
{                                                                  //~v55cI~
	int chngsw=0;                                                  //~v55cI~
    char *ponoff="";                                               //~v76jR~
//***********************                                          //~v55cI~
	if (UCBITCHK(Gopt,GOPTRCTLENTER))                              //~v55cI~
    {                                                              //~v55cI~
    	if (!Prctlsw)                                              //~v55cI~
        {                                                          //~v55cI~
        	chngsw=1;                                              //~v55cI~
            ponoff="off";                                          //~v55cI~
        }                                                          //~v55cI~
    }                                                              //~v55cI~
    else                                                           //~v55cI~
    {                                                              //~v55cI~
    	if (Prctlsw)                                               //~v55cI~
        {                                                          //~v55cI~
        	chngsw=1;                                              //~v55cI~
            ponoff="on";                                           //~v55cI~
        }                                                          //~v55cI~
    }                                                              //~v55cI~
    if (chngsw)                                                    //~v55cI~
		wxe_strcmd("opt rctl",ponoff);                             //~v55cI~
	return chngsw;                                                 //~v55cI~
}//wxe_setrctl                                                     //~v55cI~
//*************************************************************    //~v55qI~
//*return RCTL usage status                                        //~v55qI~
//*************************************************************    //~v55qI~
int wxe_getfreecsr(void)                                           //~v55qI~
{                                                                  //~v55qI~
//***********************                                          //~v55qI~
	return (UCBITCHK(Gopt5,GOPT5CSRSCROLL)==0);                    //~v55qR~
}//wxe_getfreecsr                                                  //~v55qI~
//*************************************************************    //~v55qI~
//*issue opt freecsr cmd                                           //~v55qI~
//*************************************************************    //~v55qI~
int wxe_setfreecsr(int Pfreecsrsw)                                 //~v55qR~
{                                                                  //~v55qI~
	int chngsw=0;                                                  //~v55qI~
    char *ponoff="";                                               //~v76jR~
//***********************                                          //~v55qI~
	if (UCBITCHK(Gopt5,GOPT5CSRSCROLL))                            //~v55qR~
    {                                                              //~v55qI~
    	if (Pfreecsrsw)                                            //~v55qR~
        {                                                          //~v55qI~
        	chngsw=1;                                              //~v55qI~
            ponoff="on";                                           //~v55qR~
        }                                                          //~v55qI~
    }                                                              //~v55qI~
    else                                                           //~v55qI~
    {                                                              //~v55qI~
    	if (!Pfreecsrsw)                                           //~v55qR~
        {                                                          //~v55qI~
        	chngsw=1;                                              //~v55qI~
            ponoff="off";                                          //~v55qR~
        }                                                          //~v55qI~
    }                                                              //~v55qI~
    if (chngsw)                                                    //~v55qI~
		wxe_strcmd("opt freecsr",ponoff);                          //~v55qI~
	return chngsw;                                                 //~v55qI~
}//wxe_freecsr                                                     //~v55qI~
//*************************************************************    //~v55GI~
//*return BEEP usage status                                        //~v55GI~
//*************************************************************    //~v55GI~
int wxe_getqexit(void)                                             //~v73yR~
{                                                                  //~v55GI~
//***********************                                          //~v55GI~
	return ((Gwxestat & GWXES_OPT_QEXIT)!=0);                      //~v73yR~
}//wxe_getbeep                                                     //~v55GI~
//*************************************************************    //~v55GI~
//*issue opt freecsr cmd                                           //~v55GI~
//*************************************************************    //~v55GI~
int wxe_setqexit(int Pqexit)                                       //~v73yR~
{                                                                  //~v55GI~
//***********************                                          //~v55GI~
	if (Pqexit)                                                    //~v73yR~
		Gwxestat|=GWXES_OPT_QEXIT;                                 //~v73yI~
    else                                                           //~v73yI~
		Gwxestat&=~GWXES_OPT_QEXIT;                                //~v73yI~
	return Pqexit;                                                 //~v73yR~
}//wxe_setbeep                                                     //~v73yR~
//*************************************************************    //~v73yI~
//*return BEEP usage status                                        //~v73yI~
//*************************************************************    //~v73yI~
int wxe_getbeep(void)                                              //~v73yR~
{                                                                  //~v73yI~
//***********************                                          //~v73yI~
	return (UCBITCHK(Gopt4,GOPT4NOBEEP)==0);                       //~v73yI~
}//wxe_getbeep                                                     //~v73yI~
//*************************************************************    //~v73yI~
//*issue opt freecsr cmd                                           //~v73yI~
//*************************************************************    //~v73yI~
int wxe_setbeep(int Pbeepsw)                                       //~v73yI~
{                                                                  //~v73yI~
	int chngsw=0;                                                  //~v73yI~
    char *ponoff="";                                               //~v76jR~
//***********************                                          //~v73yI~
	if (UCBITCHK(Gopt4,GOPT4NOBEEP))//no beep                      //~v73yI~
    {                                                              //~v73yI~
    	if (Pbeepsw)                                               //~v73yI~
        {                                                          //~v73yI~
        	chngsw=1;                                              //~v73yI~
            ponoff="on";                                           //~v73yI~
        }                                                          //~v73yI~
    }                                                              //~v73yI~
    else                                                           //~v73yI~
    {                                                              //~v73yI~
    	if (!Pbeepsw)                                              //~v73yI~
        {                                                          //~v73yI~
        	chngsw=1;                                              //~v73yI~
            ponoff="off";                                          //~v73yI~
        }                                                          //~v73yI~
    }                                                              //~v73yI~
    if (chngsw)                                                    //~v73yI~
		wxe_strcmd("opt beep",ponoff);                             //~v73yI~
	return chngsw;                                                 //~v73yI~
}//wxe_beep                                                        //~v73yI~
//*************************************************************    //~v55tI~
//*chk menu item enablity                                          //~v55tI~
//*************************************************************    //~v55tI~
int wxe_chkendenable(int Pmenuid)                                  //~v55uR~
{                                                                  //~v55tI~
    PUCLIENTWE pcw;                                                //~v55tI~
    PUFILEC    pfc;                                                //~v55tI~
//  PUDIRLH    pdh;                                                //~v56bR~
    int pcid,assocsw;                                              //~v56bI~
//  UCHAR fpath[_MAX_PATH],*pc;                                    //~v56bR~
//  FILEFINDBUF3 ffb3;                                             //~v56bR~
//  int rc;                                                        //~v56bR~
//***********************                                          //~v55tI~
    pcw=scrgetcw(0); 	//get active                               //~v55tI~
    switch(pcw->UCWtype)                                           //~v55tI~
	{                                                              //~v55tI~
	case UCWTDIR:                                                  //~v55tI~
    	if (Pmenuid!=CHKST_OPENWITH)                               //~v55uI~
            return (Pmenuid==CHKST_END||Pmenuid==CHKST_CANCEL);    //~v55uR~
//  	return wxegetdirlistfname(pcw,0)==0;                       //~v55UR~
//  	return dlcgetdirlistfname(pcw,0)==0;                       //~v568R~
//        assocsw=0;                                               //~v56bR~
////      rc=dlcgetdirlistfname(pcw,0,&pdh);                       //~v56bR~
//        rc=dlcgetdirlistfname(pcw,fpath,&pdh);                   //~v56bR~
////      return (!rc && !(pdh->UDHattr & FILE_DIRECTORY));//not dirname//~v56bR~
//        if (!rc && !(pdh->UDHattr & FILE_DIRECTORY))//not dirname//~v56bR~
//        {                                                        //~v56bR~
//            pc=umemrchr(fpath,'.',strlen(fpath));   //search extension//~v56bR~
//            if (pc)                                              //~v56bR~
//                assocsw=uwinreg_chkassociation(pc);              //~v56bR~
//        }                                                        //~v56bR~
		assocsw=dlcmdassocchk_dirlist(pcw);                        //~v56bR~
        return assocsw;                                            //~v56bI~
	case UCWTFILE:                                                 //~v55tI~
    	pfc=pcw->UCWpfc;                                           //~v55tR~
		if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                     //~v55tI~
	        return (Pmenuid==CHKST_END||Pmenuid==CHKST_CANCEL);    //~v55tR~
        return (Pmenuid==CHKST_END||Pmenuid==CHKST_CANCEL||Pmenuid==CHKST_SAVE);//~v55uR~
        break;                                                     //~v55tI~
    default:                                                       //~v55tI~
		pcid=((PUPANELC)pcw->UCWppc)->UPCid;                       //~v56bI~
		switch(pcid)                                               //~v56bI~
        {                                                          //~v56bI~
		case PANFNAME  :		//filename                         //~v56bI~
            if (Pmenuid!=CHKST_OPENWITH)                           //~v56bI~
                break;                                             //~v56bI~
//            assocsw=0;                                           //~v56bR~
//            if (pan300getfnm(pcw->UCWrcsry+pcw->UCWtopfnlist,fpath))    //get stacked name over scr width//~v56bR~
//            {                                                    //~v56bR~
//                pc=umemrchr(fpath,'.',strlen(fpath));   //search extension//~v56bR~
//                {                                                //~v56bR~
//                    if (!ufstat(fpath,&ffb3)                     //~v56bR~
//                    && !(ffb3.attrFile & FILE_DIRECTORY))        //~v56bR~
//                        assocsw=uwinreg_chkassociation(pc);      //~v56bR~
//                }                                                //~v56bR~
//            }                                                    //~v56bR~
			assocsw=dlcmdassocchk_fnamelist(pcw);                  //~v56bR~
            return assocsw;                                        //~v56bI~
        }                                                          //~v56bI~
        return (Pmenuid==CHKST_END||Pmenuid==CHKST_CANCEL);        //~v55tR~
    }                                                              //~v55tI~
//  return 0;                                                      //~v55tI~//~vafhR~
}//wxe_chkendenable                                                //~v55tI~
//*************************************************************    //~vbdnI~
int wxe_errmenuitemDisabled(int Pid)                               //~vbdnI~
{                                                                  //~vbdnI~
    uerrmsg("MenuItem is disabled on this panel",                  //~vbdnI~
			"Ç±ÇÃâÊñ Ç≈Ç±ÇÃÉÅÉjÉÖÅ[çÄñ⁄ÇÕégópÇ≈Ç´Ç‹ÇπÇÒ");         //~vbdnI~
    scrdisp();                                                     //~vbdnI~
    return 4;                                                      //~vbdnI~
}//wxe_errMenuitemDisabled()                                       //~vbdnI~
//*************************************************************    //~vbdnI~
//*chk File submenu enablity                                       //~vbdnI~
//*************************************************************    //~vbdnI~
int wxe_chkEnableFileSubmenu(int Popt,int Pmenuid)                 //~vbdnR~
{                                                                  //~vbdnI~
    PUCLIENTWE pcw;                                                //~vbdnI~
    PUFILEC    pfc;                                                //~vbdnI~
    BOOL rc=1;                                                     //~vbdnI~
//***********************                                          //~vbdnI~
    pcw=scrgetcw(0); 	//get active                               //~vbdnI~
    switch(Pmenuid)                                                //~vbdnI~
    {                                                              //~vbdnI~
    case CHKSTF_SAVE:                                              //~vbdnR~
    case CHKSTF_SAVEAS:                                            //~vbdnR~
    	if (pcw->UCWtype!=UCWTFILE)                                //~vbdnI~
        	rc=0;                                                  //~vbdnI~
        else                                                       //~vbdnI~
        {                                                          //~vbdnI~
    		pfc=pcw->UCWpfc;                                       //~vbdnI~
			if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                 //~vbdnI~
        		rc=0;                                              //~vbdnI~
        }                                                          //~vbdnI~
	    break;                                                     //~vbdnI~
    case CHKSTF_PRINT:                                             //~vbdnR~
    	if (pcw->UCWtype!=UCWTFILE)                                //~vbdnI~
        	rc=0;                                                  //~vbdnI~
	    break;                                                     //~vbdnI~
    }                                                              //~vbdnI~
    if (!rc)	//disabled                                         //~vbdnI~
    {                                                              //~vbdnI~
    	if (Popt & CHKSTFO_MSG)	//issue disabled msg               //~vbdnI~
			wxe_errmenuitemDisabled(Pmenuid);                      //~vbdnI~
    }                                                              //~vbdnI~
  	return rc;                                                     //~vbdnI~
}//wxe_chkEnableFileSubmenu                                        //~vbdnI~
//*************************************************************    //~v55uI~
//*chk menu item enablity                                          //~v55uI~
//*************************************************************    //~v55uI~
int wxe_onfileopenwith(void)                                       //~v55uR~
{                                                                  //~v55uI~
    PUCLIENTWE pcw;                                                //~v55uI~
    PUDIRLH    pdh;                                                //~v568I~
    char fpath[_MAX_PATH];                                         //~v55uI~
    int rc;                                                        //~v76jR~
    int pcid;                                                      //~v56bR~
//***********************                                          //~v55uI~
    pcw=scrgetcw(0); 	//get active                               //~v55uI~
	pcid=((PUPANELC)pcw->UCWppc)->UPCid;                           //~v56bI~
	if (pcid==PANFNAME)		//filename                             //~v56bR~
    {                                                              //~v56bI~
//  	if (!pan300getfnm(pcw->UCWrcsry+pcw->UCWtopfnlist,fpath))	//get stacked name over scr width//~v56gR~
		wxe_assoclcmd(pcw,0);                                      //~v56gR~
        return 0;                                                  //~v56gR~
    }                                                              //~v56bI~
    else                                                           //~v56bI~
    {                                                              //~v56bI~
//  if (wxegetdirlistfname(pcw,fpath))                             //~v55UR~
//  if (dlcgetdirlistfname(pcw,fpath))                             //~v568R~
    rc=dlcgetdirlistfname(pcw,fpath,&pdh);                         //~v568I~
//  if (rc || (pdh->UDHattr & FILE_DIRECTORY))//dirname            //~v56bR~
      if (rc)                                                      //~v56bI~
    	return 4;                                                  //~v55uI~
    }//not filename list screen                                    //~v56bI~
//  showcmd=SW_SHOW;                                               //~v76jR~
	rc=ushellexec(fpath); 	//0:no return HINSTANCE                //~v55uR~
    if (rc)                                                        //~v55uI~
        scrdisp();          //draw errmsg                          //~v55uI~
    return 0;                                                      //~v55uI~
}//wxe_onfileopenwith                                              //~v55uI~
////*************************************************************  //~v55UR~
////*chk menu item enablity-->moved to xedlcmd2                    //~v55UR~
////*************************************************************  //~v55UR~
//int wxegetdirlistfname(PUCLIENTWE Ppcw,char *Pfpath)             //~v55UR~
//{                                                                //~v55UR~
//    PUSCRD  psd;                                                 //~v55UR~
//    PULINEH    plh;                                              //~v55UR~
////***********************                                        //~v55UR~
//    if (Ppcw->UCWtype!=UCWTDIR)                                  //~v55UR~
//        return 4;                                                //~v55UR~
//    if (!CSRONFILELINE(Ppcw))                                    //~v55UR~
//        return 4;                                                //~v55UR~
//    psd=Ppcw->UCWpsd;                                            //~v55UR~
//    psd+=Ppcw->UCWrcsry;                                         //~v55UR~
//    plh=psd->USDbuffc;                                           //~v55UR~
//    if (!plh)                                                    //~v55UR~
//        return 4;                                                //~v55UR~
//    if (plh->ULHtype==ULHTHDR)                                   //~v55UR~
//        return 4;                                                //~v55UR~
//    if (Pfpath)                                                  //~v55UR~
//        if (dlcgetfullname(UGETPDH(plh),Pfpath))                 //~v55UR~
//            return 4;                                            //~v55UR~
//    return 0;                                                    //~v55UR~
//}//wxegetdirlistfname                                            //~v55UR~
//*************************************************************    //~v55FI~
//*get errmsg option english or japanese                           //~v55FI~
//*ret:1:dbcs mode,0:english mode                                  //~v55FI~
//*************************************************************    //~v55FI~
int wxegetdbcsmode(void)                                           //~v55FI~
{                                                                  //~v55FI~
    if (UCBITCHK(Guerropt,GBL_UERR_FORCEENG))                      //~v55FR~
        return 0;                                                  //~v55FI~
	if (!UCBITCHK(Guerropt,GBL_UERR_DBCSSET))	//not yet chked    //~v55FI~
    {                                                              //~v55FI~
    	uerrmsg("dummy",0);	//to set Guerropt                      //~v55FI~
        ugeterrmsg();	//clear dummy msg                          //~v55FI~
    }                                                              //~v55FI~
	if (UCBITCHK(Guerropt,GBL_UERR_DBCSMODE))                      //~v55FR~
        return 1;                                                  //~v55FI~
    return 0;                                                      //~v55FI~
}//wxegetdbcsmode                                                  //~v55FI~
//*************************************************************    //~v55WI~
//*scr update req from xe                                          //~v55WI~
//*ret:rc                                                          //~v55WI~
//*************************************************************    //~v55WI~
int wxe_scrdraw(void)                                              //~v55WI~
{                                                                  //~v55WI~
    uinvalidate(FALSE);                                            //~v55WR~
    return 0;                                                      //~v55WI~
}//wxe_scrdraw                                                     //~v55WR~
//*************************************************************    //~v55WI~
//*reset timer                                                     //~v55WI~
//*ret:rc                                                          //~v55WI~
//*************************************************************    //~v55WI~
int wxe_timerreset(int Popt)                                       //~v55WI~
{                                                                  //~v55WI~
    int timeropt,rc,sleeptime,atcmdintvlsleepresetsw=0;            //~v55WR~
//**************************************                           //~v55WI~
	if (Popt & WXEAT_DRAW)                                         //~v560M~
    {                                                              //~v560M~
		scrdisp();//display errmsg                                 //~v560M~
        return 0;                                                  //~v560M~
    }                                                              //~v560M~
	if (Popt & WXEAT_SLEEPED)                                      //~v560M~
    {                                                              //~v560M~
		sleeptime=Spwxei->WXEIsleeptime;                           //~v560I~
		sleeptime-=WXEAT_SLEEPINGINTVL;                            //~v560R~
        if (sleeptime<=0)                                          //~v560I~
        {                                                          //~v560I~
			Spwxei->WXEIsleeptime=0;                               //~v560I~
        	funcsetsleepblock(0); //reset input block              //~v55WI~
    		uerrmsg("Sleep %d sec(s) expired",0,                   //~v55WI~
					    Spwxei->WXEIsleepmaxtime);                 //~v55WI~
	    	wxe_strcmd("","");	//nop msg for msg display          //~v55WR~
			if (Spwxei->WXEIsleepinmult)	//sleep is subcmd of multcmd//~v560I~
            {                                                      //~v560I~
		    	timeropt=TID_ATCMD|TID_ATCMDTIMER|TID_SLEEPSUBCMP; //~v560I~
    			usettimer(timeropt,WXEAT_MULTCMDTIMER,0); 	//1sec,no callback//~v560R~
            }                                                      //~v560I~
        }                                                          //~v560I~
        else                                                       //~v560I~
        {                                                          //~v560I~
			wxe_setsleeptime(sleeptime);                           //~v560I~
        	uerrmsg("Sleep more %d sec(s)",0,                      //~v560R~
            		sleeptime);                                    //~v560I~
			scrdisp();//display errmsg                             //~v560I~
        }                                                          //~v560I~
        return 0;                                                  //~v560M~
    }                                                              //~v560M~
	if (Popt & WXEAT_SLEEPRESET)                                   //~v560I~
    {                                                              //~v560I~
		wxe_killsleeptime();                                       //~v560I~
        if (Spwxei->WXEIsleepinmult)    //sleep is subcmd of multcmd//~v560I~
        {                                                          //~v560I~
            timeropt=TID_ATCMD|TID_ATCMDTIMER|TID_SLEEPSUBCMP;     //~v560I~
            usettimer(timeropt,WXEAT_MULTCMDTIMER,0);  //1sec,no callback//~v560R~
        }                                                          //~v560I~
		atcmdintvlsleepresetsw=(Spwxei->WXEIatcmdstring            //~v55WI~
    		                   && (Spwxei->WXEIatcmdnext==Spwxei->WXEIatcmdstring));//~v55WI~
        if (!atcmdintvlsleepresetsw)                               //~v55WI~
        return 0;                                                  //~v560I~
    }                                                              //~v560I~
	if (Popt & WXEAT_RESET                                         //~v55WR~
	||  atcmdintvlsleepresetsw                                     //~v55WR~
	||  Popt & WXEAT_CMDER)                                        //~v55WR~
    {                                                              //~v55WI~
		if (Spwxei->WXEIatcmdstring)                               //~v55WI~
        {                                                          //~v55WI~
        	ufree(Spwxei->WXEIatcmdstring);                        //~v55WI~
			Spwxei->WXEIatcmdstring=0;                             //~v55WI~
          if (Spwxei->WXEIatcmdrepeat!=1)//at cmd                  //~v55WR~
          {                                                        //~v55WI~
			if (Popt & WXEAT_CMDER)                                //~v55WI~
            {                                                      //~v55WI~
            	uerrmsgcat("AT cmd stopped by err,%d times repeated",0,//~v564R~
					        Spwxei->WXEIatcmdcurrctr);             //~v560I~
		    	timeropt=TID_ATCMD|TID_ATCMDTIMER|TID_ATCMDDRAW;   //~v55WR~
    			usettimer(timeropt,WXEAT_MSGTIMER,0); 	//1sec,no callback//~v55WR~
            }                                                      //~v55WI~
            else                                                   //~v55WM~
		        uerrmsgcat("AT cmd interrupted by user,%d times repeated",0,//~v564R~
					        Spwxei->WXEIatcmdcurrctr);             //~v560I~
          }                                                        //~v55WI~
            rc=1;                                                  //~v55WI~
        }                                                          //~v55WI~
        else                                                       //~v55WI~
        	rc=0;                                                  //~v55WI~
        return rc;                                                 //~v55WR~
    }                                                              //~v55WI~
	if (Popt & WXEAT_COMP)                                         //~v55WI~
    {                                                              //~v55WI~
    	ufree(Spwxei->WXEIatcmdstring);                            //~v55WI~
		Spwxei->WXEIatcmdstring=0;                                 //~v55WI~
      if (Spwxei->WXEIatcmdrepeat!=1)//at cmd                      //~v560I~
      {                                                            //~v560I~
        uerrmsgcat("AT cmd completed,repeated %d times",0,         //~v564R~
				Spwxei->WXEIatcmdrepeat);                          //~v55WR~
//      scrdisp();                                                 //~v55WR~
        timeropt=TID_ATCMD|TID_ATCMDTIMER|TID_ATCMDDRAW;           //~v55WI~
        usettimer(timeropt,WXEAT_MSGTIMER,0);   //1sec,no callback //~v55WI~
      }                                                            //~v560I~
        return 0;                                                  //~v55WI~
    }                                                              //~v55WI~
	return 0;
}//wxe_timerreset                                                  //~v55WI~
//*************************************************************    //~v67CI~
//*schedule time for at cmd                                        //~v67CI~
//*parm1:opt                                                       //~v67CI~
//*parm2:interval by second                                        //~v67CI~
//*parm3:repeat count                                              //~v67CI~
//*parm4:comand strings(may multi cmd)                             //~v67CI~
//*ret:rc                                                          //~v67CI~
//*************************************************************    //~v67CI~
int wxe_atcmdisrtalias(char *Pcmd,void *Ppodelmt,int Pwordno)      //~v67CI~
{                                                                  //~v67CI~
    int cmdlen,ii,len1,len2,len3,len;                              //~v67CR~
    char *cmdstr,*top,*pc,*pco,*next,*next0,*cur;                  //~v67CR~
    PUPODELMTBL pupod;                                             //~v67CI~
//**************************************                           //~v67CI~
	top=Spwxei->WXEIatcmdstring;                                   //~v67CI~
	next=Spwxei->WXEIatcmdnext;                                    //~v67CR~
    if (next==top)	//last cmd of mult                             //~v67CI~
    {                                                              //~v67CI~
	    for (pco=pc=top;*pc;pc+=len+1)	//serach end               //~v67CI~
        {                                                          //~v67CI~
        	pco=pc;                                                //~v67CI~
    		len=strlen(pc);                                        //~v67CI~
        }                                                          //~v67CI~
        cur=pco;	//current alias cmd entry                      //~v67CI~
    }                                                              //~v67CI~
    else                                                           //~v67CI~
    {                                                              //~v67CI~
	    for (pco=pc=top;*pc;pc+=len+1)	//serach end               //~v67CI~
        {                                                          //~v67CI~
        	if (pc==next)                                          //~v67CI~
            	break;                                             //~v67CI~
        	pco=pc;                                                //~v67CI~
    		len=strlen(pc);                                        //~v67CI~
        }                                                          //~v67CI~
        cur=pco;	//current alias cmd entry                      //~v67CI~
	    for (;*pc;pc+=len+1)	//serach end                       //~v67CI~
	    	len=strlen(pc);                                        //~v67CI~
    }                                                              //~v67CI~
//  len1=(ULONG)cur-(ULONG)top;	//with last null	               //~v67CI~//~vafkR~
//  len1=(ULPTR)cur-(ULPTR)top;	//with last null                   //~vafkI~//~vb2WR~
    len1=(int)((ULPTR)cur-(ULPTR)top);	//with last null           //~vb2WI~
    len2=strlen(Pcmd)+1;                                           //~v67CI~
	next0=cur+strlen(cur)+1;                                       //~v67CR~
//  len3=(ULONG)pc-(ULONG)next0;                                   //~v67CI~//~vafkR~
//  len3=(ULPTR)pc-(ULPTR)next0;                                   //~vafkI~//~vb2WR~
    len3=(int)((ULPTR)pc-(ULPTR)next0);                            //~vb2WI~
    cmdlen=len1+len2+len3+1;	//with last end of multicmd id     //~v67CR~
    cmdstr=umalloc(cmdlen);   //strz+end of multicmd               //~v67CI~
    UALLOCCHK(cmdstr,UALLOC_FAILED);                               //~v67CI~
    memcpy(cmdstr,top,(UINT)len1); //already executed              //~v67CI~
    next=cmdstr+len1;                                              //~v67CI~
    memcpy(next,Pcmd,(UINT)len2);                                  //~v67CR~
    memcpy(next+len2,next0,(UINT)len3);                            //~v67CR~
    *(cmdstr+cmdlen-1)=0;                                          //~v67CI~
    pc=next;                                                       //~v67CR~
    for (ii=0,pupod=Ppodelmt;ii<Pwordno;ii++,pupod++)              //~v67CI~
    	if (pupod->upodelm==';')	//delm by ";"                  //~v67CI~
        	*(pc+pupod->upodelmoffs)=0;	//split multi cmd          //~v67CI~
    ufree(Spwxei->WXEIatcmdstring);                                //~v67CI~
    Spwxei->WXEIatcmdstring=cmdstr;                                //~v67CI~
    Spwxei->WXEIatcmdnext=next;	//next executed                    //~v67CR~
    Spwxei->WXEIatcmdopt|=WXEAT_ALIASREP;  //tell to wxe_atcmdctl  //~v67CI~
    return 0;                                                      //~v67CI~
}//wxe_atcmdalias                                                  //~v67CI~
//*************************************************************    //~v55WI~
//*schedule time for at cmd                                        //~v55WI~
//*parm1:opt                                                       //~v55WI~
//*parm2:interval by second                                        //~v55WI~
//*parm3:repeat count                                              //~v55WI~
//*parm4:comand strings(may multi cmd)                             //~v55WI~
//*ret:rc                                                          //~v55WI~
//*************************************************************    //~v55WI~
int wxe_atcmd(int Popt,int Pintvl,int Prepeat,char *Pcmd,void *Ppodelmt,int Pwordno)//~v55WR~
{                                                                  //~v55WI~
    int timeropt,cmdlen,ii;                                        //~v560R~
    char *cmdstr;                                                  //~v55WI~
    PUPODELMTBL pupod;                                             //~v55WI~
//**************************************                           //~v55WI~
//new cmd                                                          //~v55WI~
    if (Spwxei->WXEIatcmdstring)                                   //~v55WI~
    {                                                              //~v55WI~
      if (Popt & WXEAT_MCMD)  //not ATCMD but mult cmd             //~v67EI~
      {                                                            //~v67CI~
       	if (Popt & WXEAT_ALIAS)  //alias cmd edit string           //~v67CR~
        	return wxe_atcmdisrtalias(Pcmd,Ppodelmt,Pwordno);      //~v67CR~
        uerrmsg("Nested Sleep cmd",0);                             //~v67EI~
      }                                                            //~v67CI~
      else                                                         //~v67EI~
        uerrmsg("AT cmd is already active,reset by doubled Esc key",0);//~v55WI~
        return 4;                                                  //~v55WI~
    }                                                              //~v55WI~
    cmdlen=strlen(Pcmd);                                           //~v55WI~
    cmdstr=umalloc(cmdlen+2);   //strz+end of multicmd             //~v55WR~
    UALLOCCHK(cmdstr,UALLOC_FAILED);                               //~v55WI~
    memcpy(cmdstr,Pcmd,(UINT)cmdlen);                              //~v55WR~
    *(cmdstr+cmdlen)=0;                                            //~v55WR~
    *(cmdstr+cmdlen+1)=0;	//end of multicmd                      //~v55WI~
    for (ii=0,pupod=Ppodelmt;ii<Pwordno;ii++,pupod++)              //~v55WI~
    	if (pupod->upodelm==';')	//delm by ";"                  //~v55WI~
        	*(cmdstr+pupod->upodelmoffs)=0;	//split multi cmd      //~v55WI~
  if (Popt & WXEAT_MCMD)  //not ATCMD but mult cmd                 //~v55ZI~
  {                                                                //~v55ZI~
    Spwxei->WXEIatcmdintvl=1;	//no meaning but                   //~v55ZI~
    Spwxei->WXEIatcmdrepeat=1;//only once for not atcmd            //~v55ZI~
  }                                                                //~v55ZI~
  else                                                             //~v55ZI~
  {                                                                //~v55ZI~
    Spwxei->WXEIatcmdintvl=Pintvl;                                 //~v55WI~
    Spwxei->WXEIatcmdrepeat=Prepeat;//max ctr                      //~v55WR~
  }                                                                //~v55ZI~
    Spwxei->WXEIatcmdopt=Popt;                                     //~v564I~
    Spwxei->WXEIatcmdstring=cmdstr;                                //~v55WI~
    Spwxei->WXEIatcmdnext=cmdstr;                                  //~v55WI~
    Spwxei->WXEIatcmdcurrctr=0;		//repeated ctr                 //~v55WI~
    Spwxei->WXEIsleepinmult=0;		//sleep cmd in multicmd id     //~v560I~
//  timeropt=TID_ATCMD;                                            //~v55ZR~
//  upostmsg(WM_TIMER,timeropt,0);                                 //~v55ZR~
  if (Popt & WXEAT_MCMD   //mult cmd top is sleep                  //~v560I~
  &&  Spwxei->WXEIsleeptime)                                       //~v560I~
	    Spwxei->WXEIsleepinmult=1;	//subcmd of mult               //~v560I~
  else                                                             //~v560I~
  {                                                                //~v560I~
    timeropt=TID_ATCMD|TID_ATCMDTIMER;                             //~v55ZI~
    usettimer(timeropt,WXEAT_MULTCMDTIMER,0); 	//10ms,no callback //~v55WR~
  }                                                                //~v560I~
    return 0;                                                      //~v55WI~
}//wxe_atcmd                                                       //~v55WR~
//*************************************************************    //~v55WI~
//*execute 1 cmd of mult cmd                                       //~v55WI~
//*parm1:cmd rc                                                    //~v55WI~
//*ret:rc  0:middle of each repeat                                 //~v55WR~
//*        1:end of 1st reeat,2:end of each repeat,3:end of last repeat//~v55WI~
//*************************************************************    //~v55WI~
int wxe_atcmdctl(int *Pprc)                                        //~v55WI~
{                                                                  //~v55WI~
    int rc,apprc;                                                  //~v55WR~
    char *cmdstr,*cmdstrnext;                                      //~v55WR~
    int curctr;                                                    //~v67CR~
//**************************************                           //~v55WI~
    cmdstr=Spwxei->WXEIatcmdnext;                                  //~v55WI~
    cmdstrnext=cmdstr+strlen(cmdstr)+1;                            //~v55WI~
    curctr=Spwxei->WXEIatcmdcurrctr;	//repeated count           //~v67CI~
    if (*cmdstrnext)                                               //~v55WI~
    {                                                              //~v55WI~
    	if (Spwxei->WXEIatcmdnext==Spwxei->WXEIatcmdstring)//top of subcmd//~v55WI~
        	funcsetsleepblock(0); //reset input block              //~v55WI~
	    Spwxei->WXEIatcmdnext=cmdstrnext;                          //~v55WI~
        rc=0;                                                      //~v55WR~
    }                                                              //~v55WI~
    else                                                           //~v55WI~
    {                                                              //~v55WI~
	    Spwxei->WXEIatcmdnext=Spwxei->WXEIatcmdstring;             //~v55WI~
        Spwxei->WXEIatcmdcurrctr++;	//repeated count               //~v55WI~
        Gkbdinpctr++;   //for alias cmd loop chk                   //~v67CI~
        if (Spwxei->WXEIatcmdrepeat    //not infinit               //~v55WI~
        &&  Spwxei->WXEIatcmdcurrctr>=Spwxei->WXEIatcmdrepeat)//reached to req count//~v55WI~
            rc=3;        //end of last repeat                      //~v55WI~
        else                                                       //~v55WI~
        {                                                          //~v55WI~
        	if (Spwxei->WXEIatcmdcurrctr==1)//first time           //~v55WI~
        		rc=1;	//end of first repeat                      //~v55WR~
            else                                                   //~v55WI~
        		rc=2;   //end of each repeat                       //~v55WI~
        }                                                          //~v55WI~
    }                                                              //~v55WI~
    Spwxei->WXEIatcmdopt&=~WXEAT_ALIASREP;  //clear alias cmd replace//~v67CI~
    apprc=wxe_strcmd(cmdstr,"");                                   //~v55WI~
    if (Spwxei->WXEIatcmdopt & WXEAT_ALIASREP)  //alias cmd replaced//~v67CI~
    {                                                              //~v67CI~
    	Spwxei->WXEIatcmdcurrctr=curctr;	//repeated count       //~v67CI~
		return wxe_atcmdctl(Pprc);//retry by new multicmd          //~v67CI~
	}                                                              //~v67CI~
    if (Spwxei->WXEIsleeptime)	//subcmd is sleep                  //~v560I~
    {                                                              //~v560I~
	    Spwxei->WXEIsleepinmult=rc+1;	//event id when sleeped    //~v560I~
    	rc=4;	//wait sleep comp or reset                         //~v560I~
    }                                                              //~v560I~
    *Pprc=apprc;                                                   //~v55WI~
    if (rc==1||rc==2)   //end of multicmd                          //~v55WI~
    {                                                              //~v55WI~
        if (Spwxei->WXEIatcmdrepeat)                               //~v55WI~
            uerrmsgcat(";AT cmd remains %d times repeat",0,        //~v55WI~
                        Spwxei->WXEIatcmdrepeat-Spwxei->WXEIatcmdcurrctr);//~v55WI~
        else                                                       //~v55WI~
            uerrmsgcat(";infinit AT cmd %d times repeated",0,      //~v55WI~
                        Spwxei->WXEIatcmdcurrctr);                 //~v55WI~
                                                                   //~v55WI~
		wxe_strcmd(";",""); //nop cmd to display msg               //~v55WI~
        funcsetsleepblock(Spwxei->WXEIatcmdintvl); //sleeping,input block//~v55WR~
    }                                                              //~v55WI~
    return rc;                                                     //~v55WI~
}//wxe_atcmdctl                                                    //~v55WI~
//*************************************************************    //~v560I~
//*set timer for sleep                                             //~v560I~
//*************************************************************    //~v560I~
int wxe_setsleeptime(int Pintvl)                                   //~v560I~
{                                                                  //~v560I~
    int timeropt,intvl;                                            //~v560R~
//**************************************                           //~v560I~
    timeropt=TID_ATCMD|TID_ATCMDTIMER|TID_ATCMDSLEEP;              //~v560I~
    if (!Spwxei->WXEIsleeptime)	//at sleep start                   //~v55WI~
	    Spwxei->WXEIsleepmaxtime=Pintvl;                           //~v55WI~
    Spwxei->WXEIsleeptime=Pintvl;                                  //~v560R~
    intvl=min(WXEAT_SLEEPINGINTVL,Pintvl);                         //~v560I~
    usettimer(timeropt,intvl*1000,0); 	//no callback              //~v560R~
    return 0;                                                      //~v560I~
}//wxe_setsleeptime                                                //~v560I~
//*************************************************************    //~v560I~
//*set timer for sleep                                             //~v560I~
//*************************************************************    //~v560I~
int wxe_killsleeptime(void)                                        //~v560I~
{                                                                  //~v560I~
    int timeropt;                                                  //~v560I~
//**************************************                           //~v560I~
	Spwxei->WXEIsleeptime=0;                                       //~v560I~
    timeropt=TID_ATCMD|TID_ATCMDTIMER|TID_ATCMDSLEEP;              //~v560I~
    ukilltimer(timeropt); 	//no callback                          //~v560I~
    return 0;                                                      //~v560I~
}//wxe_killsleeptime                                               //~v560I~
//*************************************************************    //~v56gM~
//*lcmd input                                                      //~v56gM~
//*************************************************************    //~v56gM~
int  wxe_assoclcmd(PUCLIENTWE Ppcw,int Pshiftsw)                   //~v56gM~
{                                                                  //~v56gM~
	int lcmd,stat;                                                 //~v56gM~
    PUFILEC pfc;                                                   //~v56gM~
//****************************                                     //~v56gM~
	pfc=Ppcw->UCWpfc;                                              //~v56gM~
    stat=WXEKBDMSG_ONCHAR;                                         //~v56gM~
    lcmd='!';                                                      //~v56gM~
    return wxe_kbdmsg(stat,lcmd,1,0);		//1:repeat,0:flag      //~v56gM~
}//wxe_assoclcmd                                                   //~v56gM~
//*************************************************************    //~v63hI~
//*drag option chk/drag pending chk                                //~v63hR~
//*************************************************************    //~v63hI~
int  wxe_dragselectchk(int Popt,UINT Pflag,int Prow,int Pcol,void **Pppcw,void **Ppplh)//~v63hR~
{                                                                  //~v63hI~
	int  rc=0,pcid,row;                                            //~v63hR~
    PUCLIENTWE pcw;                                                //~v63hI~
	PUSCRD  psd;                                                   //~v63hI~
    PULINEH plh;                                                   //~v63hI~
    PUFILEC pfc;                                                   //~v63hI~
    PUFILEH pfh;                                                   //~v63hI~
//***********************                                          //~v63hI~
  if (Pcol<0 && Prow<0)                                            //~v63iI~
    pcw=scrgetcw(0);	//active client                            //~v63iI~
  else                                                             //~v63iI~
    scrcpgetpcw(Prow,Pcol,&pcw);                                   //~v63hI~
    *Pppcw=pcw;                                                    //~v63hI~
	pcid=((PUPANELC)pcw->UCWppc)->UPCid;                           //~v63hI~
	if (pcid!=PANDIR)                                              //~v63hI~
    	return 0;		//no dragdrop                              //~v63hI~
    row=pcw->UCWrcsry;                                             //~v63hI~
    if (!(row>=pcw->UCWfilehdrlineno && row<pcw->UCWmaxline))      //~v63hR~
    	return 0;                                                  //~v63hI~
    pfc=pcw->UCWpfc;                                               //~v63hM~
    pfh=pfc->UFCpfh;                                               //~v63hI~
    if (Popt & DRAGOPT_DRAG)    //called from mouse move           //~v63hI~
    {                                                              //~v63hI~
//  	if (!dlcmddndgetpendctr(pcw,pfh))                          //~v685R~
    	if (!dlcmddndgetpendctr(pcw,pfh,0))	//no plh return required//~v685I~
        	return 0;                                              //~v63hR~
        return DRAGCHK_DODRAG;                                     //~v63hI~
    }                                                              //~v63hI~
    psd=pcw->UCWpsd;                                               //~v63hR~
    psd+=row;                                                      //~v63hR~
    plh=psd->USDbuffc;                                             //~v63hI~
    if (!plh)                                                      //~v63hI~
    	return 0;                                                  //~v63hI~
    if (Ppplh)                                                     //~v63hI~
	    *Ppplh=plh;                                                //~v63hR~
    if (Pflag & MK_CONTROL)        //with control key              //~v63hR~
        rc=DRAGCHK_ADD;                                            //~v63hR~
    else                                                           //~v63hR~
        if (Pflag & MK_SHIFT)       //range                        //~v63hR~
            rc=DRAGCHK_RANGE;       //from prev entry              //~v63hR~
        else                                                       //~v63hR~
            rc=DRAGCHK_NEW;         //                             //~v63hR~
    return rc;                                                     //~v63hI~
}//wxe_dragselectchk                                               //~v63hI~
//*************************************************************    //~v63hI~
//*set dragdrop file ,line select start/end                        //~v63hI~
//*return reset ctr                                                //~v63hI~
//*************************************************************    //~v63hI~
int wxe_dragreset(void *Ppcw,int Popt)                             //~v63hR~
{                                                                  //~v63hI~
	int resetctr;                                                  //~v63hR~
//******************                                               //~v63hI~
    resetctr=dlcmddndreset((PUCLIENTWE)Ppcw);                      //~v63hR~
    if (Popt & DRAG_RESETBYESC) //from func_reset(by EscKey)       //~v682I~
    {                                                              //~v682I~
    	if (resetctr)                                              //~v682I~
			Spwxei->WXEIstatus|=WXEIS_DRAWMENU;	//menu enable re-evaluation required//~v682R~
    }                                                              //~v682I~
    if (Popt & DRAG_RESETMSG)                                      //~v63hI~
        uerrmsg("%d file dropped",0,                               //~v63hI~
                    resetctr);                                     //~v63hI~
    if (Popt & DRAG_RESETDRAW)                                     //~v63hI~
    {                                                              //~v682I~
	    scrdisp();                                                 //~v63hI~
		Spwxei->WXEIstatus|=WXEIS_DRAWMENU;	//menu enable re-evaluation required//~v682I~
    }                                                              //~v682I~
    return resetctr;                                               //~v63hR~
}                                                                  //~v63hI~
//*************************************************************    //~v63hI~
//*set dragdrop file ,line select start/end                        //~v63hI~
//*************************************************************    //~v63hI~
int wxe_dragset(void *Ppcw,void *Pplh1,void* Pplh2)                //~v63hR~
{                                                                  //~v63hI~
    PUCLIENTWE pcw;                                                //~v63hI~
	PUFILEH pfh;                                                   //~v63hI~
    int rc;                                                        //~v63hI~
//***********************                                          //~v63hI~
	pcw=(PUCLIENTWE)Ppcw;                                          //~v63hI~
	pfh=UGETPFHFROMPCW(pcw);                                       //~v63hR~
    rc=dlcmddndset(pcw,pfh,(PULINEH)Pplh1,(PULINEH)Pplh2);         //~v63hR~
    scrdisp();                                                     //~v63hI~
    return rc;                                                     //~v63hR~
}//wxe_dragset                                                     //~v63hR~
//*************************************************************    //~v63hI~
//*drag drop file                                                  //~v63hI~
//*get filename                                                    //~v63hI~
//*************************************************************    //~v63hI~
int wxe_dragdropfilelist(int Popt,void *Ppcw,char *Pbuff,int *Pplen)//~v63iR~
{                                                                  //~v63hI~
    PUCLIENTWE pcw;                                                //~v63hI~
	PUFILEH pfh;                                                   //~v63hI~
    int rc,opt=0;                                                  //~v63iR~
//***********************                                          //~v63hI~
	pcw=(PUCLIENTWE)Ppcw;                                          //~v63hI~
	pfh=UGETPFHFROMPCW(pcw);                                       //~v63hR~
    if (Popt & DRAG_REMOTECOPY)                                    //~v63iI~
    	opt|=DLCMDDND_REMOTECOPY;                                  //~v63iI~
	rc=dlcmddndsetuplist(opt,pcw,pfh,Pbuff,Pplen);                 //~v63iR~
    if (rc)                                                        //~v63iI~
	    if (Popt & DRAG_REDRAW)                                    //~v63iI~
    		scrdisp();                                             //~v63iI~
    return rc;                                                     //~v63hR~
}//wxe_dragdropfilelist                                            //~v63hR~
//*************************************************************    //~v685I~
//*drop on dirlist availability chk                                //~v685I~
//*rc:0:open by edit,1:file copy,-1:reject drop;2:drop filename to utility panel//~v76gR~
//*     source                target                               //~v685I~
//*                  dir-list          other panel                 //~v685I~
//*  same pcw           -1               -1                        //~v685I~
//*  another split   1(selected) or -1   -1                        //~v685I~
//*  other app       1(selected) or -1    0                        //~v685I~
//*************************************************************    //~v685I~
int wxe_dndfilecopychk(int Popt,void *Ppcw,void *Ppcwtarget,int Prow,int Pcol,char *Ptargetdir)//~v686R~
{                                                                  //~v685I~
    PUCLIENTWE pcws,pcwt,pcwc;                                     //~v685R~
	PUFILEH pfhs,pfht;                                             //~v685I~
	PUDIRLH pdh;                                                   //~v685I~
	PULINEH plh;                                                   //~v685I~
	PULINEH plhpath;                                               //~v68nI~
    int pcid,targetctr,msgsw;                                      //~v685R~
    int rc=0;                                                      //~v685I~
//***********************                                          //~v685I~
    msgsw=(Popt & DROP_COPYCHKMSG);                                //~v685I~
	pcws=(PUCLIENTWE)Ppcw;                                         //~v685I~
  if ((pcwt=Ppcwtarget)==0)	//target pcw not determined yet(not paste but drop case)//~v686I~
    scrcpgetpcw(Prow,Pcol,&pcwt);                                  //~v685I~
	pcid=((PUPANELC)pcwt->UCWppc)->UPCid;                          //~v685I~
    pcwc=scrgetcw(0);	//current                                  //~v685M~
    if (pcwc!=pcwt)                                                //~v685M~
    {                                                              //~v685I~
    	csrhomepos(-1);                                            //~v685M~
    	scrdisp();                                                 //~v685I~
    }                                                              //~v685I~
  for (;;)// err chk break                                         //~v685I~
  {                                                                //~v685I~
	if (pcid & PANUTIL)    //target is not dir                     //~v76gI~
    {                                                              //~v76gI~
    	switch(pcid)                                               //~v76gI~
        {                                                          //~v76gI~
        case PANUCOMP:                                             //~v76gI~
        case PANUGREP:                                             //~v76gI~
        	rc=DROPRC_UTIL;	//get drop filename                    //~v76gR~
            break;                                                 //~v76gI~
        default:                                                   //~v76gI~
        	rc=-1;	//ignore drop                                  //~v76gI~
        }                                                          //~v76gI~
		break;	//rc=0;open by edit cmd                            //~v76gI~
    }                                                              //~v76gI~
	if (pcid!=PANDIR)    //target is not dir                       //~v685I~
    {                                                              //~v685I~
//        if (!pcws)        //source is external                   //~v68eR~
//            break;          //no dragdrop rc=0;                  //~v68eR~
//        if (msgsw)                                               //~v68eR~
//            uerrmsg("Ignored(target is not dir-list panel)",     //~v68eR~
//                    "à∂êÊÇÃâÊñ Ç™ÇcÇâÇíÉäÉXÉgÇ≈Ç»Ç¢");           //~v68eR~
//        rc=-1;                                                   //~v68eR~
		break;	//rc=0;open by edit cmd                            //~v68eI~
    }                                                              //~v685I~
//target is dir list                                               //~v685I~
    pfht=UGETPFHFROMPCW(pcwt);  //target pfh                       //~v685I~
    if (pcws)                                                      //~v685I~
    {                                                              //~v685I~
        pfhs=UGETPFHFROMPCW(pcws);  //source pfh                   //~v685I~
        if (pfht==pfhs) //same dir (file slection display is same) //~v685I~
        {                                                          //~v685I~
	        if (msgsw)                                             //~v685I~
                uerrmsg("Ignored(target panel is same dir-list panel)",//~v68nR~
						"ï°é êÊÇcÇâÇíÇ™ï°é å≥Ç∆ìØÇ∂âÊñ ");         //~v68nR~
    	    rc=-1;                                                 //~v685I~
    		break;    		//no dragdrop                          //~v685I~
        }                                                          //~v685I~
    }                                                              //~v685I~
//target line selection chk                                        //~v685I~
    targetctr=dlcmddndgetpendctr(pcwt,pfht,&plh);                  //~v685R~
    if (!targetctr)                                                //~v685I~
    {                                                              //~v685I~
        for (plhpath=0,plh=UGETQTOP(&(pfht->UFHlineque));plh;plh=UGETQNEXT(plh))//~v68nR~
        {                                                          //~v68nI~
            if (plh->ULHtype==ULHTDATA)                            //~v68nI~
            {                                                      //~v68nI~
		    	pdh=UGETPDH(plh);                                  //~v68nR~
        		if (pdh->UDHtype!=UDHTPARENT)                      //~v68nR~
            		break;                                         //~v68nR~
                plhpath=plh;                                       //~v68nI~
            }                                                      //~v68nI~
        }                                                          //~v68nI~
      if (plhpath)                                                 //~v68nR~
      {                                                            //~v68nI~
      	targetctr=1;	//assume current as target                 //~v68nI~
        plh=plhpath;	//last path entry                          //~v68nI~
      }                                                            //~v68nI~
      else                                                         //~v68nI~
      {                                                            //~v68nI~
        if (msgsw)                                                 //~v685I~
	    	uerrmsg("Ignored(select a target dir line)",           //~v686R~
					"ï°é êÊDirÇÇPçsëIëÇµÇƒÇ≠ÇæÇ≥Ç¢");            //~v686R~
        rc=-1;                                                     //~v685I~
        break;          //no dragdrop                              //~v685I~
      }                                                            //~v68nI~
    }                                                              //~v685I~
    if (targetctr>1)                                               //~v685I~
    {                                                              //~v685I~
        if (msgsw)                                                 //~v685I~
	    	uerrmsg("Ignored(select only one dir line)",           //~v685R~
                     "ï°é êÊÇÕÇPçsÇæÇØÇëIëèÛë‘Ç…ÇµÇƒÇ≠ÇæÇ≥Ç¢");  //~v685I~
        rc=-1;                                                     //~v685I~
        break;          //no dragdrop                              //~v685I~
    }                                                              //~v685I~
    pdh=UGETPDH(plh);                                              //~v685I~
    if (pdh->UDHtype==UDHTFILE)                                    //~v685I~
    {                                                              //~v685I~
        if (msgsw)                                                 //~v685I~
	    	uerrmsg("Ignored(target selected line is not dir)",    //~v685R~
                     "ëIëÇ≥ÇÍÇΩï°é Ç™ÇcÇâÇíÇ≈ÇÕÇ†ÇËÇ‹ÇπÇÒ");      //~v685I~
        rc=-1;                                                     //~v685I~
        break;          //no dragdrop                              //~v685I~
    }                                                              //~v685I~
//get target dirname                                               //~v685I~
    if (Ptargetdir)                                                //~v685I~
    {                                                              //~v685I~
	    if (dlcgetfullname(pdh,Ptargetdir))                        //~v685I~
        {                                                          //~v685I~
	        rc=-1;                                                 //~v685I~
    	    break;          //no dragdrop                          //~v685I~
        }                                                          //~v685I~
    }                                                              //~v685I~
    rc=1;                                                          //~v685I~
    break;	//set r.c                                              //~v685I~
  }//for                                                           //~v685I~
  	if (msgsw && rc<0)		//errmsg issued                        //~v685I~
	    scrdisp();                                                 //~v685R~
    return rc;		//copy file                                    //~v685R~
}//wxe_dndfilecopychk                                              //~v685I~
//*************************************************************    //~v76gI~
//*drop filename to utility panel(pcw is dropped split scr)        //~v76gR~
//*************************************************************    //~v76gI~
int  wxe_dndutil(int Popt,char *Pfnm,int Prow)                     //~v76gR~
{                                                                  //~v76gI~
	int rc,funcid;                                                 //~v76jR~
    char cmdp[_MAX_PATH+8];                                        //~v76gI~
//***********************                                          //~v76gI~
	sprintf(cmdp,"%d \"%s\"",Prow,Pfnm);                           //~v76gR~
    if (Popt & DROPFILE_REP)    //by paste rep mode                //~v76jI~
    	funcid=FUNCID_SENDREP;                                     //~v76jI~
    else                                                           //~v76jI~
    	funcid=FUNCID_SENDINS;                                     //~v76jI~
	rc=wxe_funccall(funcid,cmdp);                                  //~v76jR~
    return rc;                                                     //~v76gI~
}//wxe_dndutil                                                     //~v76gI~
////*************************************************************  //~v686R~
////*drop on dirlist availability chk for enable menu              //~v686R~
////(under the condition CF_DROP exist)                            //~v686R~
////dirlist:chk target dir and accept paste rep/ins,else accept drop by paste-v//~v686R~
////*parm:0x01:pastev,0x00:paste rep/ins                           //~v686R~
////*rc:0:not target,1:available target                            //~v686R~
////*************************************************************  //~v686R~
//int wxe_dropselectchk(int Popt)                                  //~v686R~
//{                                                                //~v686R~
//    PUCLIENTWE pcwt;                                             //~v686R~
//    PUFILEH pfht;                                                //~v686R~
//    PUDIRLH pdh;                                                 //~v686R~
//    PULINEH plh;                                                 //~v686R~
//    int targetctr,rc=0;                                          //~v686R~
////***********************                                        //~v686R~
//    if (wxe_getpcw(&pcwt)!=PRTTYPE_DIR)//current pcw is not dirlist//~v686R~
//    {                                                            //~v686R~
//        if (Popt & 0x01)    //accept pastev                      //~v686R~
//            rc=1;       //accept paste                           //~v686R~
//        else                                                     //~v686R~
//            rc=0;       //reject ins/rep paste                   //~v686R~
//    }                                                            //~v686R~
//    else                                                         //~v686R~
//    {                                                            //~v686R~
//        if (!(Popt & 0x01)) //paste ins/rep                      //~v686R~
//        {                                                        //~v686R~
//            pfht=UGETPFHFROMPCW(pcwt);  //target pfh             //~v686R~
//            targetctr=dlcmddndgetpendctr(pcwt,pfht,&plh);        //~v686R~
//            if (targetctr==1)                                    //~v686R~
//            {                                                    //~v686R~
//                pdh=UGETPDH(plh);                                //~v686R~
//                if (pdh->UDHtype!=UDHTFILE)                      //~v686R~
//                    rc=1;                                        //~v686R~
//            }                                                    //~v686R~
//        }                                                        //~v686R~
//    }                                                            //~v686R~
//    return rc;      //copy file                                  //~v686R~
//}//wxe_dropselectchk                                             //~v68eR~
//*************************************************************    //~v685I~
//*copy file into dir by dnd                                       //~v685I~
//*************************************************************    //~v685I~
int wxe_dndcopyfile(int Popt,int Pseq,int Ptot,char *Psource,char *Ptarget)//~v686R~
{                                                                  //~v685I~
    int rc,len1,len2,lastsw,repsw;                                 //~v685R~
	FILEFINDBUF3  ffb3;                                            //~v685I~
    char cmdbuff[_MAX_PATH*2+32],*pc,*pmsg;                        //~v685I~
    char wkmsg[_MAX_PATH*2+256];                                   //~v685R~
//  char *msgparm[3]={0,"Retry by replace option?",0};             //~v685R~//~vafhR~
    PUCLIENTWE pcw;                                                //~v685I~
static int Scopycnt=0;                                             //~v685I~
    int lens,lent;                                                 //~v68gR~
//***********************                                          //~v685I~
	repsw=Popt&DNDCOPY_REP;                                        //~v686I~
	if (Pseq==1)                                                   //~v685I~
    	Scopycnt=0;                                                //~v685I~
    lastsw=(Pseq==Ptot);                                           //~v685R~
	rc=ufstat(Psource,&ffb3);                                      //~v685R~
//chk source path contains target(protect loop)                    //~v68gR~
    lent=strlen(Ptarget);                                          //~v68gR~
    lens=strlen(Psource);                                          //~v68gR~
    if (ROOTDIR3(Psource))                                         //~v68gR~
    {                                                              //~v68gR~
        uerrmsgbox("Error;Source(%s) is root dir",                 //~v68gR~
					"ÉãÅ[ÉgÇcÇâÇíÇÃï°é ÇÕÇ≈Ç´Ç‹ÇπÇÒ",              //~v68gR~
                    Psource);                                      //~v68gR~
        rc=4;                                                      //~v68gR~
    }                                                              //~v68gR~
    else                                                           //~v68gR~
    if (lens<=lent                                                 //~v68eI~
    &&  !memicmp(Ptarget,Psource,lens)  //target contains source path//~v68eI~
    &&  (lens==lent || *(Ptarget+lens)=='\\'))                     //~v68eR~
    {                                                              //~v68eI~
	    uerrmsgbox("Error;Source(%s) is on path of target path(%s)",//~v68eR~
	    			"ï°é å≥ÉpÉX(%s)Ç™à∂êÊÇcÇâÇí(%s)ÇÃìríÜÇ…Ç†ÇËÇ‹Ç∑",//~v68eR~
					Psource,Ptarget);                              //~v68eI~
        rc=4;                                                      //~v68eI~
    }                                                              //~v68eI~
    else                                                           //~v68eI~
    if (rc)                                                        //~v685I~
    {                                                              //~v685I~
	    uerrmsg("DND source %s not found",                         //~v685R~
                 "ï°é å≥(%s)Ç™å©Ç¬Ç©ÇËÇ‹ÇπÇÒ",                     //~v685R~
					Psource);                                      //~v685R~
        	pmsg=ugeterrmsg();                                     //~v685I~
	    	umsgbox(pmsg,MB_OK);            //once stop operation  //~v685I~
        rc=4;                                                      //~v685I~
    }                                                              //~v685I~
    else                                                           //~v685I~
    {                                                              //~v685I~
    	uparsein(Psource,cmdbuff,sizeof(cmdbuff),0,'\"');          //~v685I~
        len1=strlen(cmdbuff);                                      //~v685R~
        pc=cmdbuff+len1;                                           //~v685I~
        *pc++=' ';                                                 //~v685I~
        len2=sizeof(cmdbuff)-len1-1;                               //~v685I~
        uparsein(Ptarget,pc,len2,0,'\"');                          //~v685I~
        pc+=strlen(pc); //tgt len                                  //~v685I~
		if (ffb3.attrFile & FILE_DIRECTORY)	//source is dir        //~v685I~
        	strcpy(pc," /c /s");		//dir copy into            //~v68dR~
        if (repsw)                                                 //~v686I~
        	strcat(cmdbuff," /y");//append replace option          //~v686I~
        for (;;)                                                   //~v685I~
        {                                                          //~v685I~
            rc=wxe_strcmd("XCOPY",cmdbuff);                        //~v685R~
            if (!rc)                                               //~v685I~
            {                                                      //~v685I~
            	Scopycnt++;                                        //~v685I~
            	break;                                             //~v685I~
            }                                                      //~v685I~
            sprintf(wkmsg,"XCOPY %s , failed.\n Retry by replace option(Yes) or Skip to next file(No) or Stop copy(Cancel)?",cmdbuff);//~v68gR~
            rc=umsgbox(wkmsg,MB_YESNOCANCEL);            //once stop operation//~v685R~
            if (rc)   	//canceled                                 //~v685I~
            {                                                      //~v685I~
            	if (rc==IDCANCEL)                                  //~v685I~
                	rc=-1;                                         //~v685I~
                else                                               //~v685I~
                	rc=4;	//No replyed                           //~v685I~
            	break;                                             //~v685I~
            }                                                      //~v685I~
            if (!repsw)                                            //~v685I~
            {                                                      //~v685I~
                strcat(cmdbuff," /y");//append replace option      //~v685I~
                repsw=1;                                           //~v685I~
            }                                                      //~v685I~
        }//for                                                     //~v685I~
	}                                                              //~v685I~
    if (rc==-1)                                                    //~v685R~
//  	uerrmsg("Canceled; copyed %d of %d",0,                     //~v68nR~
//      			Scopycnt,Ptot);                                //~v68nR~
    	uerrmsg("Canceled; copyed %d of %d, target=%s.",0,         //~v68nI~
        			Scopycnt,Ptot,Ptarget);                        //~v68nI~
	else                                                           //~v685I~
    if (lastsw)                                                    //~v685I~
//    	uerrmsg("Successfully copyed %d of %d",0,                  //~v68nR~
//        			Scopycnt,Ptot);                                //~v68nR~
      	uerrmsg("Successfully copyed %d of %d into %s.",0,         //~v68nI~
          			Scopycnt,Ptot,Ptarget);                        //~v68nI~
    pcw=scrgetcw(0);	//current                                  //~v685R~
    func_dlcmdrefresh(pcw);		//refresh target dirlist           //~v686I~
    scrfulldraw(pcw);	//anothe of split                          //~v685I~
    scrdisp();                                                     //~v685R~
    return rc;		//copy file                                    //~v685R~
}//wxe_dndcopyfile                                                 //~v685I~
//*****************************************************************//~vbdnI~
//*from scrUpdateFileMenu                                          //~vbdnI~
//*****************************************************************//~vbdnI~
int wxe_chkUpdateFileMenu(int Popt)                                //~vbdnR~
{                                                                  //~vbdnI~
	int rc;                                                        //~vbdnI~
//*******************                                              //~vbdnI~
	rc=(Gwxestat & GWXES_UPDATEMENU)?1:0;                          //~vbdnR~
	UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~vbdnI~
	Gwxestat &= ~GWXES_UPDATEMENU;                                 //~vbdnR~
    return rc;                                                     //~vbdnI~
}//wxe_cckUpdateFileMenu                                           //~vbdnR~
//*****************************************************************//~vbz4I~
//*from utf22 apichkConsole                                        //~vbz4I~
//*****************************************************************//~vbz4I~
int wxe_GetCursorWidth(int Popt,ULONG Pucs)                        //~vbz4I~
{                                                                  //~vbz4I~
    if (Guvio2Stat & UVIO2S_NOGLYPHCHK)//     //test skip close, to getglyph width after mapinit//~vbAnI~
    {                                                              //~vbAnI~
		UTRACEP("%s:return -1 NOGLYPHCHK option\n",UTT);           //~vbAnI~
    	return -1;                                                 //~vbAnI~
    }                                                              //~vbAnI~
    return csubGetCursorPos(Popt,Pucs);                            //~vbz4R~
}                                                                  //~vbz4I~
//*****************************************************************//~vbz4I~
//*call ucs mapinit, it callback wxe_getCursorPos                  //~vbz4I~
//*****************************************************************//~vbz4I~
void wxe_mapinit(void)                                             //~vbz4I~
{                                                                  //~vbz4I~
	UTRACEP("%s\n",UTT);                                           //~vbz4R~
    utfucsmapinitWXE();                                            //~vbz4R~
}                                                                  //~vbz4I~
#ifdef AAA                                                         //~vbEdI~
//*****************************************************************//~vbzMI~
//*from uvio_m2dd                                                  //~vbzMI~
//*****************************************************************//~vbzMI~
int wxe_m2u(int Popt,int Prow,int Pcol,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Pbuffsz,int *Ppucsctr)//~vbzMR~
{                                                                  //~vbzMI~
	UTRACEP("%s:opt=0x%02x,row=%d,col=%d,len=%d\n",UTT,Popt,Prow,Pcol,Plen);//~vbzMR~
    int rc=wxescr_m2u(Popt,(WXEINTF*)Gpwxei,Prow,Pcol,Ppdata,Ppdbcs,Plen,Ppucs,Pbuffsz,Ppucsctr);//~vbzMR~
	UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~vbzMI~
    return rc;                                                     //~vbzMI~
}                                                                  //~vbzMI~
int wxe_u2altch(int Popt,int Prow,int Pcol,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Pbuffsz,int *Ppucsctr)//~vbzMR~
{                                                                  //~vbzMI~
	UTRACEP("%s:opt=0x%02x,row=%d,col=%d,len=%d\n",UTT,Popt,Prow,Pcol,Plen);//~vbzMI~
    int rc=wxescr_u2altch(Popt,(WXEINTF*)Gpwxei,Prow,Pcol,Ppdata,Ppdbcs,Plen,Ppucs,Pbuffsz,Ppucsctr);//~vbzMR~
	UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~vbzMI~
    return rc;                                                     //~vbzMI~
}                                                                  //~vbzMI~
#else                                                              //~vbEdI~
//*****************************************************************//~vbEdI~
//void wxe_getucsHC(int Popt,int Prow,int Pmaxcol,UWCH **Ppucs,int *Ppucsctr)//+v7fxR~
void wxe_getucsHC(int Popt,int Prow,int Pmaxcol,int PsplitVpos,UWCH **Ppucs,int *Ppucsctr)//+v7fxI~
{                                                                  //~vbEdI~
	UTRACEP("%s:opt=0x%02x,row=%d.maxcol=%d,vpos=%d\n",UTT,Popt,Prow,Pmaxcol,PsplitVpos);//+v7fxR~
//  csubGetUcsHC(Popt,Prow,Pmaxcol,Ppucs,Ppucsctr);                //+v7fxR~
    csubGetUcsHC(Popt,Prow,Pmaxcol,PsplitVpos,Ppucs,Ppucsctr);     //+v7fxI~
}                                                                  //~vbEdI~
#endif                                                             //~vbEdI~
