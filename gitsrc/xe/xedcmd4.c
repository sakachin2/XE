//*CID://+vbkeR~:                             update#=  710;       //~vbkeR~
//*************************************************************
//*xedcmd4.c                                                       //~v638R~
//* grep,androsend                                                 //~vaa4R~
//*************************************************************
//vbke:180619 add msg to display utf8 code filename                //~vbkeI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vavN:140405 (W32UNICODE)vavM is not effective,spawn dose also multibyte process(invalid UD to dbcs translation),back to by alias//~vavNI~
//vavM:140405 (W32UNICODE)xfc/xdc by spawn(because cmd propt translate filename to bestfit)//~vavMI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafg:120613 (ARM)avoid uninitialized variable warning by gcc 4.4.3 on FC12(copile optio -Ox is required also)//~vafgI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaa4:110520 ANDROID Send command/dlcmd                           //~vaa4I~
//va6E:100719 grep cmd hung byif string contains "&" etc.          //~va6ER~
//v76p:070628 compare remote file support                          //~v76pI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v75M:070509 "="(compare) lcmd support. 1st file is line with cmd option on Enter'ed screen.//~v75MI~
//v75J:070509 "g"(grep) dlcmd support                              //~v75JI~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v70r:060826 sub cmd;set stdin redirect to protect hung by wait kbd input//~v70rI~
//v67N:060224 (BUG)grep:when space containing dir for *\ or ^*\,it should not enclose wildcard by unix shell standard.//~v67NI~
//v64r:050630 (XXE)xxe support;child shell                         //~v64rI~
//v647:050617 grep fmt change for the availability of dir search on edit/browse scr//~v647I~
//            specify * as filename to search on the current scr   //~v647I~
//v644:050617 (BUG)grep fail if intermediate dir name has embedded space even not used *\,**\  ;//~v647R~
//                 and consider *\ generated space embeding file name//~v644I~
//v63w:050530 grep cmd;support *\ etc for filename only whe that is last parm//~v63wI~
//v63v:050528 (UNX:BUG)grep rc=2(parmerr) for LNX is 512(need ch ::#go)//~v63vR~
//v63t:050527 grep cmd ;chk filename opd exist to protect wait     //~v63tI~
//v63c:050429 change dcmd stdout file(::so) to use pid for contension inter user//~v63cI~
//v63b:050429 change dlcmd "%" temp file(cfso/cf) to use pid for contension inter user//~v63bI~
//v63a:050429 grep original file when file is not updated          //~v63aI~
//v638:050428 change xprint temp file to use pid for contension inter user//~v638I~
//v637:050428 change submit temp file to use pid for contension inter user//~v637I~
//v636:050428 new workdir filename naming ::#((pid).xxx) for grep work filename//~v636I~
//v632:050427 find cmd;support grepline search by *G               //~v632I~
//v630:050426 grep support  as dos cmd(for edit screen flag line and search by rfind for *L)
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#ifdef UNX
	#include <termios.h>
#else
#include <process.h>
  #ifdef W32
	#include <io.h>    		//for _A_SUBDIR etc
  #endif
#endif

//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ualloc.h>
#include <ufile.h>
#include <ufile2.h>                                                //~v636I~
#include <ufile3.h>
#include <uparse.h>
#include <ustring.h>
#include <uedit.h>
#include <uproc.h>
#include <uproc2.h>
#include <ufemsg.h>                                                //~v75JI~
#include <utrace.h>
#include <ufilew.h>                                                //~vavNI~
#ifdef FTPSUPP
    #include <uftp.h>
    #include <ufile1f.h>
#endif

#include "xe.h"
#include "xescr.h"
#include "xefunc.h"
#include "xeerr.h"
#include "xefile.h"
#include "xefile12.h"
#include "xefile2.h"
#include "xesub.h"                                                 //~v74xM~
#include "xefcmd2.h"
#include "xefcmd22.h"
#include "xefcmd27.h"                                              //~v76dR~
#include "xeftp.h"
#include "xepan.h"
#include "xedir.h"
#include "xedcmd.h"
#include "xedcmd2.h"
#include "xedcmd3.h"
#define  XEGBL_DCMD4                                               //~v636I~
#include "xedcmd4.h"                                               //~v636I~
#include "xedlcmd.h"                                               //~vaa4I~
#include "xefsubw.h"                                               //~vbkeI~
//****************************************************************
#define GREPPARM      "-n"
//****************************************************************
#ifdef ARM                                                         //~vaa4R~
	#define SENDTEMPPFX "::tmp_update"                             //~vaa4R~
	#define SENDTEMPLST "::tmp_sendlist.txt"                       //~vaa4I~
	#define LISTFILEID  '@'                                        //~vaa4I~
#endif                                                             //~vaa4R~
//****************************************************************
int dcmdgetgrepresult(PUCLIENTWE Ppcw,char *Pfnm,PUFILEH Ppfh);
int dcmdgrephighlight(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,int Plocatesw);
//int dcmdwritehdrline(char *Pfnm,char *Pmode,char *Phdrline);       //~v75JI~//~vavNR~
int dcmdwritehdrline(char *Pfnm,char *Pmode,char *Phdrline,char *PcmdUDX);//~vavNI~
int dcmdstrchk(int Popt,char *Pstr);                               //~va6EI~
#define  DCSCO_NOMSG       0x01      //no err msg                  //~va6ER~
#define  DCSCO_PARSE       0x02      //chk after string parse      //~va6ER~
#define  DCSCO_REDIRECTOK  0x04      //allow ">"                   //~va6EI~
//**************************************************************** //~va6EI~
// cmd string chk                                                  //~va6EI~
//   err if contains "&" or "|" or "<", ">"                        //~va6EI~
//**************************************************************** //~va6EI~
int dcmdstrchk(int Popt,char *Pstr)                                //~va6EI~
{                                                                  //~va6EI~
	int rc=0,opdno,opt,ii;                                         //~va6ER~
    UCHAR *pot,*pc,*perrch;                                        //~va6ER~
    PUPODELMTBL podt,podt0;                                        //~va6ER~
//****************                                                 //~va6EI~
	pc=Pstr;                                                       //~va6EI~
    if (Popt & DCSCO_PARSE)                                        //~va6EI~
    {                                                              //~va6EI~
    	opt=Popt & ~DCSCO_PARSE;                                   //~va6ER~
    	uparse2(Pstr,&podt,&pot,&opdno,UPARSE2SETCONTDLM2,0/*delmtbl*/);//~va6EI~
        podt0=podt;                                                //~va6EI~
        for (ii=0,pc=pot;ii<opdno;ii++,pc+=strlen(pc)+1,podt++)    //~va6EI~
        {                                                          //~va6EI~
        	if (!podt->upoquate)                                   //~va6EI~
            	if (dcmdstrchk(opt,pc))                            //~va6EI~
                {                                                  //~va6EI~
                	rc=1;                                          //~va6EI~
                	break;                                         //~va6ER~
                }                                                  //~va6EI~
        }                                                          //~va6EI~
        ufree(podt0);                                              //~va6ER~
        return rc;                                                 //~va6ER~
    }                                                              //~va6EI~
    if (Popt & DCSCO_REDIRECTOK)                                   //~va6EI~
    	perrch="&|<";                                              //~va6EI~
    else                                                           //~va6EI~
		perrch="&|<>";                                             //~va6ER~
	if (strpbrk(pc,perrch))                                        //~va6EI~
    {                                                              //~va6EI~
    	rc=1;                                                      //~va6EI~
        if (!(Popt & DCSCO_NOMSG))                                 //~va6EI~
        	uerrmsg("%s Contains Invalid char, enclose by quotation(\").",0,//~va6ER~
            		Pstr);                                         //~va6EI~
    }                                                              //~va6EI~
    return rc;                                                     //~va6EI~
}//dcmdstrchk                                                      //~va6EI~
//****************************************************************
//!grep
//*ret :rc 8
//****************************************************************
int dcmd_grep(PUCLIENTWE Ppcw)
{
    UFILEH *pfh;
    char *pparm;
    char cmd[_MAX_PATH+MAXCOLUMN];
    char wdtemp[16],fpathtempi[_MAX_PATH],fpathtempo[_MAX_PATH];
    int  rc,dcmdsw,droptabsw,setredirectsw=0;
    int redirsw,netcmdlen;                                         //~v638R~
    char redirectfnm[_MAX_PATH],redirectfnm2[_MAX_PATH];
    char *pfnm=NULL,fpath[_MAX_PATH];                                   //~v63wI~//~vafcR~
    int  offsc,offsp=0;                                              //~v63wI~//~vafcR~
    UCHAR *pot,*pc;                                                //~v63tR~
    int ii,opdno,notflagctr;                                       //~v63tR~
    PUPODELMTBL podt;                                              //~v63cI~
    int scrgrepsw,len;                                             //~v647R~
//*******************
    pparm=Ppcw->UCWparm;
    if (!pparm)
    {
//      uerrmsg("Same parameter as grep cmd of each OS except filename(not requred for browse/edit screen)",//~v647R~
//              "各OSのgrepコマンドと同じ、但しファイル名は\x95\\示編集画面では指定しない。");//~v647R~
//      uerrmsg("Same parameter as grep cmd of each OS except spcify * as filename to search on the current screen.",//~v76pR~
//              "各OSのgrepコマンドと同じ、但し現\x95\\示編集画面上をgrepするときはファイル名は\"*\"を指定。");//~v76pR~
        uerrmsg("Same parameter as grep cmd of each OS(use \"*\" for current file). See also -g option of Find cmd.",//~v76pI~
                "各OSのgrepコマンドと同じ(ファイル名:\"*\"は現\x95\\示編集画面。Findコマンドの-gオプションも参照。");//~v76pI~
        return 4;
    }
    *redirectfnm=0;
    *redirectfnm2=0;
//  if (uprocparseredirect(pparm,redirectfnm,redirectfnm2,&redirsw,&netcmdlen))//~v70rR~
    if (uprocparseredirect(pparm,0,redirectfnm,redirectfnm2,&redirsw,&netcmdlen))//no stdin//~v70rI~
		return dcmdredirectparmerr();
    len=netcmdlen-(int)umemrspnc(pparm,' ',(UINT)netcmdlen);       //~v64rR~
    scrgrepsw=(len>2 && *(pparm+len-2)==' ' && *(pparm+len-1)=='*');//~v647R~
	if (Ppcw->UCWtype==UCWTFILE)//browse/edit
        pfh=UGETPFHFROMPCW(Ppcw);
    else
	if (Ppcw->UCWtype==UCWTDIR)//browse/edit                       //~v644R~
        pfh=UGETPFHFROMPCW(Ppcw);                                  //~v644R~
    else                                                           //~v644I~
        pfh=0;
//  dcmdsw=!pfh						//not browse/edit              //~v644R~
    dcmdsw=!pfh						//not browse/edit/dir          //~v644I~
	    || Ppcw->UCWtype==UCWTDIR  //browse/edit                   //~v644I~
    	|| Ppcw->UCWmenuopt==PANMOCMD	//menu 6
      	|| pfh->UFHtype==UFHTKFI;       //funckey
    if (!dcmdsw)            //edit/browse scr                      //~v647I~
    {                                                              //~v647I~
    	if (scrgrepsw)		// filename is "*"                     //~v647I~
			*(pparm+netcmdlen-2)=0;	//cut current scr id parm      //~v647I~
        else                                                       //~v647I~
        	dcmdsw=1;		//search dir                           //~v647I~
    }                                                              //~v647I~
    if (*redirectfnm||*redirectfnm2)	//redeirect parm exist
    {
		if (!dcmdsw)
        {
    		uerrmsg("redirection not avail for grep in current screen",
					"画面中をgrepするときリダイレクトは使用できません。");
            return 4;
        }
	    *(pparm+netcmdlen)=0;	//drop redirect parm
    }
    if (dcmdsw)
    {
    	podt=Ppcw->UCWopddelmt;                                    //~v63tR~
    	pot=Ppcw->UCWopdpot;                                       //~v63tR~
    	uparse2(pparm,&podt,&pot,&opdno,UPARSE2USEAREAPARM|UPARSE2SETCONTDLM2,0);//~v63tR~
        offsc=0;                                                   //~v63wI~
        for (ii=0,notflagctr=0,pc=pot;ii<opdno;ii++,pc+=strlen(pc)+1,podt++)//~v63tR~
        {                                                          //~v63tR~
        	if (!podt->upoquate)                                   //~va6EI~
                if (dcmdstrchk(0,pc))	//contains pipe char("&" or "|")//~va6EI~
                	return 4;                                      //~va6EI~
        	if (podt->upoquate||*pc!='-')                          //~v63tR~
            {                                                      //~v63wI~
            	notflagctr++;                                      //~v63tR~
                offsp=offsc;			//prev delm offs           //~v63wI~
                offsc=podt->upodelmoffs;   //current offs          //~v63wI~
                pfnm=pc;                                           //~v63wI~
            }                                                      //~v63wI~
        }                                                          //~v63tR~
//      if (Ppcw->UCWopdno==1)                                     //~v63tR~
        if (notflagctr<2)                                          //~v63tR~
            return errmissing();
	    sprintf(cmd,"grep %s",pparm);   //without redirect parm
//      if ((*pfnm==SAMEDIR && Ppcw->UCWtype==UCWTDIR)             //~v644R~
//      if ((  (*pfnm==SAMEDIR && Ppcw->UCWtype==UCWTDIR)          //~v647R~
        if ((  (*pfnm==SAMEDIR && pfh)                             //~v647R~
	         &&((*pfnm+1)==SAMEDIR || *(pfnm+1)==pfh->UFHdirsepc)) //~v644R~
        ||	!memcmp(pfnm,FNMOF2NDSCR,sizeof(FNMOF2NDSCR)-1))	//other screen filename spec//~v63wI~
        {                                                          //~v63wI~
		    if (dcmdfullpath(Ppcw,fpath,pfnm))	//support *\,**\,^*,:://~v63wI~
//  	    	strcpy(cmd+5+offsp+1,fpath);                       //~v644R~
//  	    	uparsein(fpath,cmd+5+offsp+1,sizeof(cmd)-offsp-6,0,'\"');//~v67NR~
//    	    	uparseindir(0,fpath,cmd+5+offsp+1,sizeof(cmd)-offsp-6);//~v67NI~//~vb2DR~
      	    	uparseindir(0,fpath,cmd+5+offsp+1,(int)sizeof(cmd)-offsp-6);//~vb2DI~
        }                                                          //~v63wI~
    	if (Ppcw->UCWmenuopt!=PANMOCMD)	//menu 6
    		if (!*redirectfnm&&!*redirectfnm2)	//redeirect parm exist
            {
		        strcpy(redirectfnm,DCMDGREPTEMPFNMO);              //~v637R~
                setredirectsw=1;
				Gdcmdtempf|=GDCMDTEMPF_GREPO;                      //~v636R~
            }
    }
    else
    {
        strcpy(redirectfnm,DCMDGREPTEMPFNMO);                      //~v63aM~
        Gdcmdtempf|=GDCMDTEMPF_GREPO;                              //~v63aM~
        *redirectfnm2=0;	// 2>&1                                //~v63aM~
        if (!filefullpath(fpathtempo,redirectfnm,_MAX_PATH))       //~v63aM~
            return 4;                                              //~v63aM~
	  	if (pfh->UFHupctr)	//file updated                         //~v63aR~
      	{                                                          //~v63aR~
            strcpy(wdtemp,DCMDGREPTEMPFNMI);                           //~v637R~
            if (!filefullpath(fpathtempi,wdtemp,_MAX_PATH))
                return 4;
            Gdcmdtempf|=GDCMDTEMPF_GREPI;                              //~v636R~
            droptabsw=0;
            if (!UCBITCHK(Gopt,GOPTTABDISPLAY)) //tab display
            {
                if (!UCBITCHK(pfh->UFHflag5,UFHF5DROPTAB))  //once reset
                {
                    droptabsw=1;
                    UCBITON(pfh->UFHflag5,UFHF5DROPTAB);    //drop tab when save
                }
            }
            rc=filesave(Ppcw,0,pfh,0,0,fpathtempi);
            if (droptabsw)
                UCBITOFF(pfh->UFHflag5,UFHF5DROPTAB);   //drop tab when save
            if (rc)
                return 4;
      	}//grep work saved                                         //~v63aR~
      	else                                                       //~v63aI~
        	strcpy(fpathtempi,pfh->UFHfilename);                   //~v63aI~
        if (dcmdstrchk(DCSCO_PARSE,pparm))	//contains pipe char("&" or "|")//~va6ER~
            return 4;                                              //~va6EI~
	    sprintf(cmd,"grep %s %s %s",GREPPARM,pparm,fpathtempi);
        redirsw=0;	//appendmode=0
    }
    Ppcw->UCWparm=cmd;
//execute
    rc=dcmdsystemcall(Ppcw,Ppcw->UCWparm,redirsw,redirectfnm,redirectfnm2);
#ifdef UNX                                                         //~v63vR~
    rc>>=8;                                                        //~v63vR~
#endif                                                             //~v63vR~
    if (rc==2)	//parm err
    {
    	if (Ppcw->UCWmenuopt!=PANMOCMD)	//menu 6
        {                                                          //~v63tI~
            if (*redirectfnm2)                                     //~v63bI~
		    	uerrmsg("grep failed;See %s",0,                    //~v647R~
    		    			redirectfnm2);                         //~v63bI~
            else                                                   //~v63bI~
        	if (*redirectfnm)
		    	uerrmsg("grep failed;See %s",0,                    //~v647R~
    		    			redirectfnm);
        }                                                          //~v63tI~
        return 4;
    }
    if (rc)
    {                                                              //~v647I~
        if (rc==1)                                                 //~v647I~
		    uerrmsgcat(";No Line Found.",0);                       //~v647R~
    	return 4;
    }                                                              //~v647I~
    if (setredirectsw)
		uerrmsg("grep result is %s",0,
    		    		redirectfnm);
    if (dcmdsw)
    	return 0;
    rc=dcmdgetgrepresult(Ppcw,fpathtempo,pfh);
    return rc;
}//dcmd_grep
//**************************************************************** //~v75JI~
//!grep by dlcmd(append redirecfnm then execute grep               //~v75JI~
//*ret :rc 8                                                       //~v75JI~
//**************************************************************** //~v75JI~
int dcmd_grepdlcmd(PUCLIENTWE Ppcw,char *Pcmd,int Pcmdlen,char *Predirectfnm,int Pgrepctr)//~v75JR~
{                                                                  //~v75JI~
    int rc,redirsw;                                                //~v75JR~
#ifdef W32UNICODE                                                  //~vavNI~
    char *pcmdlc=NULL;                                             //~vavNI~
    int cmdlenlc;                                                  //~vavNI~
#endif                                                             //~vavNI~
//*******************                                              //~v75JI~
#ifdef W32UNICODE                                                  //~vavNI~
    if (memchr(Pcmd,UD_NOTLC,Pcmdlen))                             //~vavNI~
    {                                                              //~vavNI~
    	pcmdlc=umalloc(Pcmdlen);                                   //~vavNI~
    	ufilecvUD2LC_bestfit(0,Pcmd,Pcmdlen,pcmdlc,Pcmdlen,&cmdlenlc);//~vavNI~
        Pcmd=pcmdlc;                                               //~vavNI~
    }                                                              //~vavNI~
#endif                                                             //~vavNI~
    sprintf(Predirectfnm,"%s.%03d",DCMDGREPTEMPFNMODLC,Pgrepctr);  //~v75JR~
//  dcmdwritehdrline(Predirectfnm,"a",Pcmd);	//append mode      //~v75JI~//~vavNR~
    dcmdwritehdrline(Predirectfnm,"a",Pcmd,NULL/*UDX*/);	//append mode//~vavNI~
	if (dcmdstrchk(DCSCO_PARSE,Pcmd))                              //~va6ER~
    {                                                              //~vavNI~
#ifdef W32UNICODE                                                  //~vavNI~
  		if (pcmdlc)                                                //~vavNI~
    		ufree(pcmdlc);                                         //~vavNR~
#endif                                                             //~vavNI~
    	return 8;      //stop multi dlcmd                          //~va6ER~
    }                                                              //~vavNI~
    Ppcw->UCWparm=Pcmd;                                            //~v75JR~
    redirsw=PRERC_STDOAPPEND|PRERC_STDEAPPEND;                     //~v75JI~
    rc=dcmdsystemcall(Ppcw,Pcmd,redirsw,Predirectfnm,"&1");        //~v75JR~
#ifdef W32UNICODE                                                  //~vavNI~
  	if (pcmdlc)                                                    //~vavNR~
    	ufree(pcmdlc);                                             //~vavNI~
#endif                                                             //~vavNI~
	Gdcmdtempf|=GDCMDTEMPF_GREPODLC;                               //~v75JM~
#ifdef UNX                                                         //~v75JI~
    rc>>=8;                                                        //~v75JI~
#endif                                                             //~v75JI~
    if (rc==2)	//parm err                                         //~v75JI~
		uerrmsg("grep failed",0);                                  //~v75JR~
    else                                                           //~v75JI~
    if (rc)                                                        //~v75JI~
    {                                                              //~v75JI~
        if (rc==1)                                                 //~v75JI~
		    uerrmsg("No Line Found.",0);                           //~v75JR~
        else                                                       //~v75JI~
    		rc=8;                                                  //~v75JR~
    }                                                              //~v75JI~
    return rc;                                                     //~v75JR~
}//dcmd_grepdlcmd                                                  //~v75JI~
//**************************************************************** //~v75MI~
//!file compare by dlcmd(append redirecfnm then execute xfc)       //~v75MI~
//*ret :rc 8                                                       //~v75MI~
//**************************************************************** //~v75MI~
int dcmd_comparedlcmd(PUCLIENTWE Ppcw,char *Pcmd,int Pcmdlen,char *Predirectfnm,int Pgrepctr)//~v75MI~
{                                                                  //~v75MI~
    int rc,redirsw;                                                //~v75MI~
#ifdef W32UNICODE                                                  //~vavNI~
    int cmdlenx;                                                   //~vavNR~
    char *pcmdx=NULL,*pcmdud;                                      //~vavNR~
#endif                                                             //~vavNI~
//*******************                                              //~v75MI~
#ifdef W32UNICODE                                                  //~vavNI~
    pcmdud=Pcmd;                                                   //~vavNI~
    if (memchr(Pcmd,UD_NOTLC,Pcmdlen))                             //~vavNR~
    {                                                              //~vavNI~
    	pcmdx=umalloc(Pcmdlen*2+1);                                //~vavNR~
    	ufilecvUD2UDX(UFCVO_STRZ,Pcmd,Pcmdlen,pcmdx,Pcmdlen*2+1,&cmdlenx);//~vavNR~
        Pcmd=pcmdx;                                                //~vavNR~
    }                                                              //~vavNI~
#endif                                                             //~vavNI~
  if (Pgrepctr>=0)	//new file                                     //~v76gI~
    sprintf(Predirectfnm,"%s.%03d",DCMDCOMPTEMPFNMODLC,Pgrepctr);  //~v75MI~
#ifdef W32UNICODE                                                  //~vavNI~
	dcmdwritehdrline(Predirectfnm,"a",pcmdud,Pcmd/*udx*/);	//append mode//~vavNI~
#else                                                              //~vavNI~
	dcmdwritehdrline(Predirectfnm,"a",Pcmd,NULL/*udx*/);	//append mode      //~v75MI~//~vavNR~
#endif                                                             //~vavNI~
    Ppcw->UCWparm=Pcmd;                                            //~v75MI~
    redirsw=PRERC_STDOAPPEND|PRERC_STDEAPPEND;                     //~v75MI~
//  rc=dcmdsystemcall(Ppcw,Pcmd,redirsw,Predirectfnm,"&1");        //~vavMI~
//  rc=dcmdsystemcall_spawn(0,Ppcw,Pcmd,redirsw,Predirectfnm,"&1");//~vavMR~//~vavNR~
    rc=dcmdsystemcall(Ppcw,Pcmd,redirsw,Predirectfnm,"&1");        //~vavNI~
	Gdcmdtempf|=GDCMDTEMPF_COMPODLC;                               //~v75MI~
#ifdef W32UNICODE                                                  //~vavNI~
  	if (pcmdx)                                                     //~vavNI~
    	ufree(pcmdx);                                              //~vavNI~
#endif                                                             //~vavNI~
#ifdef UNX                                                         //~v75MI~
    rc>>=8;                                                        //~v75MI~
#endif                                                             //~v75MI~
//  uerrmsg("compare rc=%d",0,rc);                                 //~v75MI~
    return rc;                                                     //~v75MI~
}//dcmd_comparedlcmd                                               //~v75MI~
//**************************************************************** //~v75JI~
//write header line as delimiter                                   //~v75JI~
//*ret :rc                                                         //~v75JI~
//**************************************************************** //~v75JI~
//int dcmdwritehdrline(char *Pfnm,char *Pmode,char *Phdrline)        //~v75JI~//~vavNR~
int dcmdwritehdrline(char *Pfnm,char *Pmode,char *Phdrline,char *Pcmdudx)//~vavNI~
{                                                                  //~v75JI~
    FILE *fh;                                                      //~v75JI~
    UCHAR fpath[_MAX_PATH],timestamp[32];                          //~v75JI~
#ifdef W32UNICODE                                                  //~vavNI~
//    UCHAR cmdlc[_MAX_PATH*4];                                    //~vavNR~
    UCHAR wku8[_MAX_PATH*2+MAXLINEDATA];                           //+vbkeM~
#endif                                                             //~vavNI~
//*******************                                              //~v75JI~
    if (!filefullpath(fpath,Pfnm,_MAX_PATH))                       //~v75JR~
        return 8;                                                  //~v75JI~
    if (!(fh=fopen(fpath,Pmode)))                                  //~v75JR~
    {                                                              //~v75JR~
    	ufileapierr("fopen",fpath,errno);                          //~v75JI~
        return 8;                                                  //~v75JI~
    }                                                              //~v75JI~
    memset(timestamp,0,sizeof(timestamp));                         //~v75JI~
    utimeedit("YYYY/MM/DD-HH:MM:SS.MIL",timestamp);                //~v75JR~
#ifdef W32UNICODE                                                  //~vavNI~
  if (strchr(Phdrline,UD_NOTLC))	                               //~vavNI~
  {                                                                //~vavNI~
//    ufilecvUD2LC(0,Phdrline,strlen(Phdrline),cmdlc,sizeof(cmdlc),NULL/*outlen*/);//~vavNR~
//    fprintf(fh,"\n=== %s == %s\n\n",timestamp,cmdlc);            //~vavNR~
    fprintf(fh,"\n=== %s == ",timestamp);                          //~vavNI~
    ufprintfW(fh,"%s\n\n",Phdrline);                               //~vavNR~
  }                                                                //~vavNI~
  else                                                             //~vavNI~
#endif                                                             //~vavNI~
    fprintf(fh,"\n=== %s == %s\n\n",timestamp,Phdrline);           //~v75JR~
#ifdef W32UNICODE                                                  //~vavNI~
	if (Pcmdudx)                                                   //~vavNI~
      if (strcmp(Pcmdudx,Phdrline))                                //~vavNI~
      {                                                            //~vbkeI~
//      fprintf(fh,"=== %23s == %s\n\n","(Internal format param filename)",Pcmdudx);//~vavNR~//~vbkeR~
        fprintf(fh,"=== %23s == %s\n\n","(Internal format param)",Pcmdudx);//~vbkeI~
        if (!fsubw_UD2U8(0,Phdrline,strlen(Phdrline),wku8,sizeof(wku8),0/*outu8len*/))//~vbkeI~
		    fprintf(fh,"=== %23s == %s\n\n"," ",wku8);             //~vbkeR~
      }                                                            //~vbkeI~
#endif                                                             //~vavNI~
    fclose(fh);                                                    //~v75JI~
    return 0;                                                      //~v75JI~
}//dcmdwritehdrline                                                //~v75JI~
//****************************************************************
//flag plh found
//*ret :rc 8
//****************************************************************
int dcmdgetgrepresult(PUCLIENTWE Ppcw,char *Pfnm,PUFILEH Ppfh)
{
	PULINEH plh;
    FILE *fh;
	char *pc;
    int readlen,swcont,swconto=0,locatesw=1,rc,len,foundlinectr=0,updatesw;//~v63aR~
    LONG lineno,linenorw;                                          //~v63aR~
//**********************************************************
	plh=UGETQNEXT(UGETQTOP(&Ppfh->UFHlineque));		//top entry
	fh=fileopen(Pfnm,"rb");
    if (!fh)
    	return 4;
	updatesw=Ppfh->UFHupctr;	//file updated                     //~v63aI~
    for (;;)
    {
    	rc=0;
    	if (!fgets(Gfilebuff,MAXLINEDATA,fh))
        	break;
        pc=memchr(Gfilebuff,'\n',MAXLINEDATA);
        if (pc)
        {
//        	readlen=(int)((ULONG)pc-(ULONG)Gfilebuff);             //~vafkR~
          	readlen=(int)((ULPTR)pc-(ULPTR)Gfilebuff);             //~vafkI~
#ifndef UNX
			if (readlen && *(pc-1)==0x0d)
            	readlen--;
#endif
			swcont=0;
        }
        else
        {
        	readlen=MAXLINEDATA-1;
            swcont=1;
        }
		if (swconto)	//cont line of prev
        	continue;
        swconto=swcont;
        rc=4;		//err when break by errchk
        if (!readlen)
        	break;
        pc=memchr(Gfilebuff,':',(UINT)readlen);	//nnn: fmt lineno
        if (!pc)
        	break;
//      len=(int)((ULONG)pc-(ULONG)Gfilebuff);                     //~vafkR~
        len=(int)((ULPTR)pc-(ULPTR)Gfilebuff);                     //~vafkI~
        if (len!=unumlen(Gfilebuff,0,len))
        	break;
        lineno=atol(Gfilebuff);
//lineno matching
        for (;plh;plh=UGETQNEXT(plh))
        {                                                          //~v632I~
    		if (plh->ULHtype==ULHTDATA)                            //~v632R~
            {                                                      //~v63aI~
            	if (updatesw)                                      //~v63aR~
                	linenorw=plh->ULHlinenow;                      //~v63aI~
                else                                               //~v63aI~
                	linenorw=plh->ULHlinenor;                      //~v63aI~
        		if (lineno==linenorw)                              //~v63aR~
                {                                                  //~v632I~
                    UCBITON(plh->ULHflag4,ULHF4GREP);   //for search by *G//~v632I~
                    break;                                         //~v632R~
                }                                                  //~v632I~
                else                                               //~v632I~
		            UCBITOFF(plh->ULHflag4,ULHF4GREP);             //~v632I~
            }                                                      //~v63aI~
        }                                                          //~v632I~
        if (!plh)
        	break;
        rc=0;
        dcmdgrephighlight(Ppcw,Ppfh,plh,locatesw);
        foundlinectr++;
        locatesw=0;
        plh=UGETQNEXT(plh); //next of matched                      //~v632I~
    }//until eof
    for (;plh;plh=UGETQNEXT(plh))                                  //~v632I~
        UCBITOFF(plh->ULHflag4,ULHF4GREP);//clear after last greped//~v632I~
	fileclose(Pfnm,fh);
    if (rc)
    {
    	uerrmsg("Invalid grep option?(No lineno prefix),check %s",0,
        			Pfnm);
    	return 4;
    }
    uerrmsg("%d line found",0,
			foundlinectr);
    return 0;
}//dcmdsetgrepline
//***********************************************************
//* setup line as found line
//***********************************************************
int  dcmdgrephighlight(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,int Plocatesw)
{
    int rc=0,linenosz;
//*******************
	if (Plocatesw)	//locate to found word
	{
        fcmdfindscroll(Ppcw,Pplh,0);	//0:no scroll option
	    linenosz=Ppcw->UCWlinenosz;
        if (linenosz)
			filesetcsr(Ppcw,Pplh,0,linenosz-1);//csr set on update sign
		else
			filesetcsr(Ppcw,Pplh,1,0);		//csr set on col 1
		Ppfh->UFHmfwtindex=0;
        Ppfh->UFHfindctr++;
        Ppfh->UFHupctrgrep=Ppfh->UFHupctr;                         //~v632I~
//      Sstep=1;//reverse len,next rfind step
//  	Sfoundplh=Pplh;
//  	Sfoundoffs=0;	            //to chk continuas rfind
//  	Schangeopt=0;			//for next rchange
//  	Sfindopt &= ~(FINDOPT_MULTIREV|FINDOPT_MULTIREVNEXT); //ignore multi rev
//  	Sfoundctr=0;					//count up at return
//  	Smfwtovf=0;						//overflow point
// 		Spfhfindctr=Ppfh->UFHfindctr;
	}//first time
    Pplh->ULHrevctr=Ppfh->UFHfindctr;//find cmd ctr for disply current;
	Pplh->ULHrevoffs=ULHULFOUND;		//ipdate line search result id
    Pplh->ULHrevlen=1;//reverse len,next rfind step
    UCBITON(Pplh->ULHflag,ULHFDRAW|ULHFCURFOUND);//draw word after wordrep
	UCBITOFF(Pplh->ULHflag2,ULHF2MFOUND);//reset multiple
    UCBITOFF(Pplh->ULHflag,ULHFCURCAP);//reset hilight reason cap
	return rc;
}//dcmdgrepsetline
//***********************************************************      //~v636I~
//* delete all ::#(pid work file)                                  //~v636I~
//***********************************************************      //~v636I~
int dcmdwdclear(void)                                              //~v636R~
{                                                                  //~v636I~
    char fpath[_MAX_PATH];                                         //~v636I~
    int pctr=0;                                                    //~v75JI~
//**************************************                           //~v636I~
	if (Gdcmdtempf & GDCMDTEMPF_GREPI)                             //~v636R~
    {                                                              //~v636I~
    	if (filefullpath(fpath,DCMDGREPTEMPFNMI,_MAX_PATH))        //~v637R~
			uremove(fpath);                                        //~v63bI~
    }                                                              //~v636I~
	if (Gdcmdtempf & GDCMDTEMPF_GREPO)                             //~v636I~
    {                                                              //~v636I~
    	if (filefullpath(fpath,DCMDGREPTEMPFNMO,_MAX_PATH))        //~v637R~
			uremove(fpath);                                        //~v63bI~
    }                                                              //~v636I~
	if (Gdcmdtempf & GDCMDTEMPF_SUB)                               //~v637I~
    {                                                              //~v637I~
    	if (filefullpath(fpath,DCMDSUBMITCMDFNM,_MAX_PATH))        //~v637I~
			uremove(fpath);                                        //~v63bI~
    }                                                              //~v637I~
	if (Gdcmdtempf & GDCMDTEMPF_XPRINT)                            //~v638I~
    {                                                              //~v638I~
    	if (filefullpath(fpath,DCMDXPRINTTEMPFNM,_MAX_PATH))       //~v638I~
			uremove(fpath);                                        //~v63bI~
    }                                                              //~v638I~
	if (Gdcmdtempf & GDCMDTEMPF_DLCMDP)                            //~v638I~
    {                                                              //~v638I~
    	if (filefullpath(fpath,DCMDDLCMDPINPFNM,_MAX_PATH))        //~v638I~
			uremove(fpath);                                        //~v63bR~
    }                                                              //~v638I~
	if (Gdcmdtempf & GDCMDTEMPF_DLCMDCF)                           //~v63bR~
    {                                                              //~v63bI~
    	if (filefullpath(fpath,DCMDDLCMDCFSO,_MAX_PATH))           //~v63bR~
			uremove(fpath);                                        //~v63bI~
    }                                                              //~v63bI~
	if (Gdcmdtempf & GDCMDTEMPF_DCMDSO)                            //~v63cI~
    {                                                              //~v63cI~
    	if (filefullpath(fpath,DCMDDCMDSO,_MAX_PATH))              //~v63cI~
			uremove(fpath);                                        //~v63cI~
    }                                                              //~v63cI~
	if (Gdcmdtempf & GDCMDTEMPF_SYSCMDF)	//child shell kick     //~v64rR~
    {                                                              //~v64rR~
    	if (filefullpath(fpath,DCMDSYSCMDTEMPF,_MAX_PATH))         //~v64rR~
			uremove(fpath);                                        //~v64rR~
    }                                                              //~v64rR~
	if (Gdcmdtempf & GDCMDTEMPF_GREPODLC)                          //~v75JI~
    {                                                              //~v75JI~
    	if (filefullpath(fpath,DCMDGREPTEMPFNMODLC "." DIR_ALLMEMB,_MAX_PATH))//~v75JR~
			uxdelete(fpath,0,0,&pctr,&pctr,&pctr);                 //~v75JR~
    }                                                              //~v75JI~
	if (Gdcmdtempf & GDCMDTEMPF_COMPODLC)                          //~v75MI~
    {                                                              //~v75MI~
    	if (filefullpath(fpath,DCMDCOMPTEMPFNMODLC "." DIR_ALLMEMB,_MAX_PATH))//~v75MI~
			uxdelete(fpath,0,0,&pctr,&pctr,&pctr);                 //~v75MI~
    }                                                              //~v75MI~
    subdeletetempfile();                                           //~v76pI~
    return 0;                                                      //~v636R~
}//dcmdwdclear                                                     //~v636R~
#ifdef ARM                                                         //~vaa4R~
//**************************************************************** //~vaa4I~
//ASE cmd help                                                     //~vaa4I~
//*ret :rc 4                                                       //~vaa4I~
//**************************************************************** //~vaa4I~
int dcmdhelp_androsend(void)                                       //~vaa4I~
{                                                                  //~vaa4I~
    uerrmsg("ASE  [ * | - | filename ] [@][attachement]",0);       //~vaa4R~
	return 1;                                                      //~vaa4I~
}                                                                  //~vaa4I~
//***********************************************************      //~vaa4I~
//* create send filename list                                      //~vaa4I~
//***********************************************************      //~vaa4I~
int putfilelist(char *Pbuff,int Psz,char *Pfnm)                    //~vaa4I~
{                                                                  //~vaa4I~
	FILE *fh;                                                      //~vaa4I~
//****************************                                     //~vaa4I~
	fh=fopen(Pfnm,"wb");                                           //~vaa4I~
    if (!fh)                                                       //~vaa4I~
    {                                                              //~vaa4I~
    	return ufileapierr("fopen",Pfnm,4);                        //~vaa4I~
    }                                                              //~vaa4I~
	fwrite(Pbuff,1,Psz,fh);                                        //~vaa4I~
    fclose(fh);                                                    //~vaa4I~
    return 0;                                                      //~vaa4I~
}//putfilelist                                                     //~vaa4R~
//***********************************************************      //~vaa4I~
//* create send filename list                                      //~vaa4I~
//***********************************************************      //~vaa4I~
int setupsendlist(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Poutfnm)//~vaa4R~
{                                                                  //~vaa4I~
	int buffsz,opt,rc;                                             //~vaa4I~
    char *psendlist,*pc;                                           //~vaa4R~
//****************************                                     //~vaa4I~
	*Poutfnm=LISTFILEID;                                           //~vaa4I~
	if (!dcmdfullpath(Ppcw,Poutfnm+1,SENDTEMPLST))                 //~vaa4R~
    	return 4;                                                  //~vaa4I~
	opt=DLCMDDND_NODIR|DLCMDDND_SETEOL;   //err if directory       //~vaa4I~
	rc=dlcmddndsetuplist(opt,Ppcw,Ppfh,0/*Pbuff*/,&buffsz);    //get length             //~v63iR~//~vaa4I~
    if (rc)                                                        //~v63hI~//~vaa4I~
    	return 4;                                                  //~v63hR~//~vaa4I~
    if (buffsz==0)	//no selected entry                            //~vaa4I~
    {                                                              //~vaa4I~
    	if (Popt & 0x01)	//errmsg                               //~vaa4I~
	    	uerrmsg("select entry to be send.(enter one line cmd '%c' to left-most column)",0,//~vaa4R~
					UDLCCMD_DNDSELECT);	//  '_'  //drag and drop selected line//~vaa4R~
        return 1;                                                  //~vaa4R~
    }                                                              //~vaa4I~
    psendlist=(char*)umalloc(buffsz+1);                             //~v63hR~//~vaa4R~
    *(psendlist+buffsz)=0;                                         //~vaa4I~
	rc=dlcmddndsetuplist(opt,Ppcw,Ppfh,psendlist,&buffsz);    //get length//~vaa4I~
    if (!rc)                                                       //~vaa4I~
    {                                                              //~vaa4I~
    	pc=strchr(psendlist,'\n');                                 //~vaa4I~
        if (pc && strchr(pc+1,'\n')==0)	//one file                 //~vaa4R~
        {                                                          //~vaa4I~
        	*pc=0;                                                 //~vaa4I~
        	strcpy(Poutfnm,psendlist);                             //~vaa4R~
        }                                                          //~vaa4I~
        else                                                       //~vaa4I~
    		if (putfilelist(psendlist,buffsz,Poutfnm+1))           //~vaa4R~
    			rc=4;                                              //~vaa4R~
    }                                                              //~vaa4I~
    ufree(psendlist);                                              //~vaa4I~
    return rc;                                                     //~vaa4I~
}//setupsendlist                                                   //~vaa4I~
#ifdef TEST                                                        //~vaa4I~
int usend2app(int Popt,char *pfnm,char *pattachfnm) //jnic2j       //~vaa4I~
{                                                                  //~vaa4I~
    char pc[1024];                                                 //~vaa4I~
    return sprintf(pc,"usend2app %s,%s\n",pfnm,pattachfnm);        //~vaa4R~
}                                                                  //~vaa4I~
#endif                                                             //~vaa4I~
//***********************************************************      //~vaa4I~
//* android send cmd                                               //~vaa4I~
//***********************************************************      //~vaa4I~
int dcmd_androsend(PUCLIENTWE Ppcw)                                //~vaa4R~
{                                                                  //~vaa4I~
    PUFILEH pfh;                                                   //~vaa4I~
//  char *pc,*pfnm,*pattachfnm=0;                                  //~vafgR~
    char *pc,*pfnm=NULL,*pattachfnm=0;                             //~vafgI~
    int ii,opdno,rc,rc2;                                           //~vaa4R~
    char fpath1[_MAX_PATH],fpath2[_MAX_PATH];                      //~vaa4I~
    char updatefnm[_MAX_PATH];                                     //~vaa4I~
//****************************                                     //~vaa4I~
    pc=Ppcw->UCWparm;                                              //~vaa4I~
  	if (!pc)                                                       //~vaa4I~
  	{                                                              //~vaa4I~
    	return dcmdhelp_androsend();                               //~vaa4I~
    }                                                              //~vaa4I~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~vaa4I~
    pc=Ppcw->UCWopdpot;                                            //~vaa4I~
    for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~vaa4R~
	{                                                              //~vaa4I~
    	if (ii==0)                                                 //~vaa4I~
        	pfnm=pc;                                               //~vaa4I~
        else                                                       //~vaa4I~
    	if (ii==1)                                                 //~vaa4I~
        	pattachfnm=pc;                                         //~vaa4I~
    }                                                              //~vaa4I~
    if (!strcmp(pfnm,"*"))                                         //~vaa4I~
    {                                                              //~vaa4I~
    	if (Ppcw->UCWtype==UCWTFILE)                               //~vaa4I~
        {                                                          //~vaa4I~
            pfh=UGETPFHFROMPCW(((PUCLIENTWE)(Ppcw)));              //~vaa4R~
            pfnm=pfh->UFHfilename;                                 //~vaa4I~
			if (pfh->UFHupctr!=pfh->UFHupctrsave)	//same as saved//~vaa4I~
            {                                                      //~vaa4I~
            	pc=strrchr(pfnm,'/');                              //~vaa4I~
                if (pc)                                            //~vaa4I~
                	pc++;                                          //~vaa4I~
                else                                               //~vaa4I~
                	pc="";                                         //~vaa4I~
            	sprintf(updatefnm,"%s_%s",SENDTEMPPFX,pc);         //~vaa4I~
				if (dcmdfullpath(Ppcw,fpath1,updatefnm))           //~vaa4R~
                {                                                  //~vaa4I~
                	if (!filesave(Ppcw,0,pfh,0,0,fpath1))          //~vaa4R~
		        		pfnm=fpath1;                               //~vaa4R~
                }                                                  //~vaa4I~
            }                                                      //~vaa4I~
        }                                                          //~vaa4I~
        else                                                       //~vaa4I~
        {                                                          //~vaa4I~
        	uerrmsg("Specify filename or \"-\"",0);                //~vaa4R~
            return 4;                                              //~vaa4I~
        }                                                          //~vaa4I~
    }                                                              //~vaa4I~
    else                                                           //~vaa4I~
    if (!strcmp(pfnm,"-"))	//missing                              //~vaa4I~
        pfnm=0;                                                    //~vaa4I~
    else                                                           //~vaa4I~
    {                                                              //~vaa4I~
		if (dcmdfullpath(Ppcw,fpath1,pfnm))                        //~vaa4R~
        	pfnm=fpath1;                                           //~vaa4I~
    }                                                              //~vaa4I~
//*attachment file                                                 //~vaa4I~
    if (pattachfnm)                                                //~vaa4I~
    {                                                              //~vaa4I~
    	if (*pattachfnm==LISTFILEID)                               //~vaa4R~
        {                                                          //~vaa4I~
			if (dcmdfullpath(Ppcw,fpath2+1,pattachfnm+1))          //~vaa4R~
            {                                                      //~vaa4I~
            	*fpath2=LISTFILEID;                                //~vaa4R~
	        	pattachfnm=fpath2;                                 //~vaa4I~
            }                                                      //~vaa4I~
        }                                                          //~vaa4I~
        else                                                       //~vaa4I~
		if (dcmdfullpath(Ppcw,fpath2,pattachfnm))                  //~vaa4R~
        	pattachfnm=fpath2;                                     //~vaa4R~
    }                                                              //~vaa4I~
    else                                                           //~vaa4I~
    {                                                              //~vaa4I~
    	if (Ppcw->UCWtype==UCWTDIR)                                //~vaa4I~
        {                                                          //~vaa4I~
            pfh=UGETPFHFROMPCW(((PUCLIENTWE)(Ppcw)));              //~vaa4R~
            rc2=setupsendlist(0,Ppcw,pfh,fpath2);                  //~vaa4R~
            if (rc2>1)                                             //~vaa4R~
            	return 4;                                          //~vaa4R~
            if (rc2)	//==1 no selection                         //~vaa4R~
            	pattachfnm=0;                                      //~vaa4I~
            else                                                   //~vaa4I~
		    	pattachfnm=fpath2;                                 //~vaa4R~
        }                                                          //~vaa4I~
    }                                                              //~vaa4I~
    if (!pfnm && !pattachfnm)                                      //~vaa4R~
    {                                                              //~vaa4I~
    	uerrmsg("no file specified",0);                            //~vaa4R~
        return 4;                                                  //~vaa4I~
    }                                                              //~vaa4I~
    rc=usend2app(0,pfnm,pattachfnm); //jnic2j                      //~vaa4R~
    return rc;                                                     //~vaa4I~
}//dcmd_androsend                                                  //~vaa4I~
#endif  //ARM                                                      //~vaa4R~
