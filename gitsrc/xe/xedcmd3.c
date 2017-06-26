//*CID://+vb7eR~:                             update#=  593;       //+vb7eR~
//************************************************************* //~v051I~
//*xedcmd3.c                                                       //~v765R~
//* submit,rsh                                                     //~v59cR~
//************************************************************* //~v051I~
//vb7e:170108 FTP crash by longname                                //+vb7eI~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//v798:080803 (BUG)after PgUp key,TSO full screen mode panel draw is qureous//~v798I~
//v9@5:080717 3270:TSO FS mode;draw update line only for performance//~v9@5I~
//v78X:080627 (BUG of v78W)# lcmd faile for TSO file("sub sub fnm" for tso:tunkeymvs)//~v78XI~
//v8@B:080627 3270:submit cmd support by TSO SUBMIT cmd            //~v8@BI~
//v78W:080625 (BUG)err when *\ used for submit cmd file            //~v78WI~
//v78V:080625 (BUG)connection err(try to remote to no TSO) msg when submit using TSO filename//~v78VI~
//v74B:070225 (LNX:BUG)ini file process fail by EOL type for the file Windows created.//~v74BI~
//            chk other fgets process                              //~v74BI~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v72L:061209 rsh cmd abend when cmd missing after userid          //~v72LI~
//v72B:061205 3270:like rsh,use =6 panel as TSO terminal screen "tso "tostid TSO"/Exit//~v72BI~
//v71N:061107 (3270)support "#"/% dlcmd for TSO file               //~v71NI~
//v71F:061103 3270:treate SUB cmd on TSO file opend panel as sub to remote("sub sub *" cmd)//~v71FI~
//v71D:061102 (BUG)submit cmd;3270 submit case,if 2nd opd=='*' for tso file,tso filename shjould not to pass to local sub cmd.//~v71DI~
//            for updated case,set attr is invalid by tso file attr.//~v71DI~
//v70t:060828 SUB cmd;treate filename "**" if not enclosed by quotation as original filename even if that is updated//~v70tI~
//            and accept "**" as parameter of original filename    //~v70tI~
//v70r:060826 sub cmd;set stdin redirect to protect hung by wait kbd input//~v70rI~
//v70q:060823 SUB cmd;support /U option(submit using) to submit to the script file//~v70qI~
//v70p:060821 Missng submit help,cmdstring err msg issued when "sub ?" entered//~v70pI~
//v64y:050709 (BUG)duplicate env set msg for xe on child shell of xe when envfile used//~v64yI~
//v637:050428 change submit temp file to use pid for contension inter user//~v637I~
//v59K:041121 env file *\ :: support                               //~v59KI~
//v59H:041121 allow set/export in env-file                         //~v59HI~
//v59G:041121 support ennv reference by set cmd($abc,${abc},%abc%) //~v59GI~
//v59F:041121 chng cmd name,exp/xen-->set/env and issue dos cmd when no opd under cmd panel//~v59FI~
//v59E:041120 (WXE)pass env to sub process xesyscmd.exe            //~v59EI~
//v59D:041120 env init file support                                //~v59DI~
//v59C:041120 xen command. xenv {< file| var[=[value]]}            //~v59CI~
//v59g:041107 rsh:set MOCMD screen as rlogin                       //~v59gI~
//v59d:041107 rsh:log also shell script itself                     //~v59dI~
//v59c:041107 % lcmd:remote support(use rsh)                       //~v59cI~
//v59b:041106 rsh cmd:curr edit file support                       //~v59bI~
//v59a:041106 rsh cmd fmt chng:rsh [-{e2s|s2e}] {{[hsitid|*]:|ipaddr} [-l user] cmdstr|* [cmd parm]}//~v59aI~
//v599:041104 rsh cmd:support *: on remote list                    //~v599I~
//v598:041104 rsh cmd fmt chng to same as native; rsh host -l user cmd//~v598I~
//v593:041102 split xedcmd2-->xedcmd3(submit,rsh)                  //~v593I~
//************************************************************* //~v051I~
#include <time.h>                                               //~v051I~
#include <stdio.h>                                              //~v051I~
#include <stddef.h>                                             //~v051I~
#include <stdlib.h>                                             //~v051I~
#include <ctype.h>                                              //~v051I~
#include <string.h>                                             //~v051I~
#include <errno.h>                                              //~v051I~
#ifdef UNX                                                         //~v593I~
	#include <termios.h>                                           //~v593I~
#else                                                              //~v593I~
#include <process.h>                                               //~v593I~
  #ifdef W32                                                       //~v593I~
	#include <io.h>    		//for _A_SUBDIR etc                    //~v593I~
  #endif                                                           //~v593I~
#endif                                                             //~v593I~
                                                                //~v051I~
#ifdef DOS                                                      //~v051I~
#else                                                           //~v051I~
    #ifdef W32                                                     //~v085I~
//      #include <windows.h>                                       //~v085I~
    #else                                                          //~v085I~
    #define INCL_BASE                                           //~v051I~
    #include <os2.h>                                            //~v051I~
    #endif                                                         //~v085I~
#endif                                                          //~v051I~
//*******************************************************       //~v051I~
#include <ulib.h>                                               //~v051I~
#include <uerr.h>                                               //~v051I~
#include <uque.h>                                               //~v051I~
#include <ualloc.h>                                             //~v051I~
#include <ufile.h>                                              //~v051I~
#include <ufile2.h>                                                //~v59bI~
#include <ufile3.h>                                                //~v53VI~
#include <uproc.h>                                              //~v051I~
#include <uproc2.h>                                                //~v58CI~
#include <uedit.h>                                              //~v051I~
#include <uparse.h>                                                //~v0b2R~
#include <ustring.h>                                               //~v0b2I~
#include <utrace.h>                                                //~v09tI~
#include <udos.h>                                                  //~v0hjI~
#ifdef FTPSUPP                                                     //~v53VI~
    #include <uftp.h>                                              //~v53ZR~
    #include <ufile1f.h>                                           //~v55fI~
#endif                                                             //~v53VI~
#ifdef UNX                                                         //~v593I~
    #include <ufile2l.h>                                           //~v593I~
    #include <ukbdl.h>                                             //~v765I~
#endif                                                             //~v593I~
                                                                //~v051I~
#include "xe.h"                                                 //~v051I~
#include "xescr.h"                                              //~v051I~
#include "xefunc.h"                                             //~v051I~
#include "xeerr.h"                                              //~v051I~
#include "xefile.h"                                             //~v06nI~
#include "xefile12.h"                                              //~v0k4I~
#include "xefile2.h"                                               //~v59gI~
#include "xesub.h"                                                 //~v74xR~
#include "xepan.h"                                                    //~v06nI~
#include "xelcmd.h"                                                   //~v06tI~
#include "xedir.h"                                                 //~v11MI~
#include "xedcmd.h"                                                //~v11MI~
#include "xedcmd2.h"                                               //~v11MM~
#include "xedcmd3.h"                                               //~v59CI~
#include "xedcmd4.h"                                               //~v637I~
#include "xeftp.h"                                                 //~v59aI~
#include "xesyscmd.h"                                              //~v59EI~
#include "xetso.h"                                                 //~v72BI~
//****************************************************************//~v051I~
//#define TEMPCMDFNM   "XE!TEMP"                                   //~v19ER~
//#define TEMPCMDFNM   "XE_TEMP"                                   //~v637R~
#define TEMPRSHCMDF "xe_rshcmd"                                    //~v637R~
#define STR_REDIRECT21  "&1"                                       //~v58FI~
//#define TSOSUBCMD    "sub"                                       //~v71NI~
//****************************************************************//~v051I~
//****************************************************************//~v051I~
#ifdef FTPSUPP                                                     //~v57BI~
	int dcmd_rshhelp(void);                                        //~v592I~
	int dcmdrshgetuseridparm(char **Ppparmstr,char **Ppuserid);    //~v59aR~
	int dcmdrshcreatetempshell(PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pcmdstr);//~v59bR~
	int dcmdrloginsetup(PUCLIENTWE Ppcw,char *Pphostid);           //~v59gI~
	int dcmd_hostiderr(char *Pphostid);                            //~v59gI~
//  int dcmdrloginlog(PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Plogtext);//~v72BR~
#endif                                                             //~v57BI~
int dcmdxenvhelp(void);                                            //~v59CI~
int dcmdsubmithelp(void);                                          //~v70pR~
int dcmdxenvvar(int Popt,char *Pvarname,char *Pnewval);            //~v59CR~
//**************************************************************** //~v0k4I~
//!submit                                                          //~v0k4I~
//*ret :rc 8                                                       //~v0k4I~
//**************************************************************** //~v0k4I~
int func_submit(PUCLIENTWE Ppcw)                                   //~v0k4I~
{                                                                  //~v0k4I~
#define ORGFILENAMEID "**"                                         //~v70tI~
    PUFILEC pfc;                                                   //~v0k4I~
    UFILEH *pfh;                                                   //~v0k4I~
    char *fnm,*pc;                                                 //~v0k4R~
//#ifndef UNX                                                      //~v52aR~
//    int  extid;                                                  //~v52aR~
//#endif                                                           //~v52aR~
	PUPODELMTBL ppodt;                                             //~v58JI~
    int  editsw;        //1:edit screen,2:sub from cur edit file   //~v0k4I~
//  char cmd[_MAX_PATH+MAXCOLUMN];                                 //~v70qR~
    char cmd[_MAX_PATH+_MAX_PATH+_MAX_PATH+MAXCOLUMN];             //~v70rR~
    char tempcmdfnm[16];                                           //~v0k4I~
    int  opdno,ii,len,rc;                                          //~v58JR~
    int redirsw,netcmdlen,offs,parmctr=0;                          //~v58JR~
//  char *redirectfnm=0,parmctr=0,redirectfnm2[_MAX_PATH],*pcr;    //~v58FR~
    char redirectfnm[_MAX_PATH],redirectfnm2[_MAX_PATH],*pcr;      //~v58JR~
    char redirectstdin[_MAX_PATH],redirectstdinfpath[_MAX_PATH];   //~v70rR~
    char *pstdefnm,*pstdofnm;                                      //~v58FR~
    char *parm1s=0,*parm2s=0,*parm1=0;	                           //~v70qI~
    int editsw2=0;                                                 //~v70qI~
#if defined(LNX) && !defined(XXE) //linux console                  //~vaa7I~
#else                                                              //~vaa7I~
    int stdinredirectsw=0;                                         //~v70tI~
#endif                                                             //~vaa7I~
    int orgfilenamesw=0,len2;                                      //~v70tR~
    char fpath[_MAX_PATH];                                         //~v70tR~
#ifdef FTPSUPP                                                     //~v798M~
    char fpath2[_MAX_PATH];                                        //~v78WI~
    int remotefileopdsw=0;                                           //~v53VI~//~vafcR~
    int tsosavesw=0;                                               //~v8@BR~
    PUFTPHOST  puftph=NULL;                                             //~v55fR~//~vafcR~
    int tsofilesw=0;                                               //~v78VI~
    int tsosubrc=0;                                                  //~v8@BI~//~vafcR~
#endif                                                             //~v53VI~
	ULONG attr;                                                    //~v70qI~
//*******************                                              //~v0k4I~
    pc=Ppcw->UCWparm;                                              //~v51XR~
//  if (pc)                                                        //~v58FR~
//  {                                                              //~v58FR~
//      pc=strchr(pc,'>');                                         //~v58FR~
//  	if (pc)                                                    //~v58FR~
//      	*pc=0;  //drop redirect                                //~v58FR~
//  }                                                              //~v58FR~
  if (pc)                                                          //~v58PI~
  {                                                                //~v58PI~
    if (*pc=='?')   //help req                                     //~v70pR~
        return dcmdsubmithelp();                                   //~v70pR~
//  if (uprocparseredirect(pc,redirectfnm,redirectfnm2,&redirsw,&netcmdlen))//~v70rR~
    if (uprocparseredirect(pc,redirectstdin,redirectfnm,redirectfnm2,&redirsw,&netcmdlen))//~v70rR~
		return dcmdredirectparmerr();                              //~v58HI~
    *(pc+netcmdlen)=0;                                             //~v58FI~
  }                                                                //~v58PI~
  else                                                             //~v58PI~
  {                                                                //~v58PI~
    *redirectfnm=0;*redirectfnm2=0;redirsw=0;netcmdlen=0;          //~v58PI~
    *redirectstdin=0;                                              //~v70rI~
  }                                                                //~v58PI~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v58JI~
    pc=Ppcw->UCWopdpot;                                            //~v58JI~
    ppodt=Ppcw->UCWopddelmt;                                       //~v58JI~
    len=0;                                                         //~v58JI~
    for (ii=0;ii<opdno;ii++,pc+=len+1)	//next operand addr        //~v58JI~
	{                                                              //~v58JI~
    	if (ii==0)                                                 //~v70qI~
        {                                                          //~v70qI~
//          if (*pc=='<')                                          //~v70rR~
//              parm1s=Ppcw->UCWparm;                              //~v70rR~
//          else                                                   //~v70rR~
		    	parm1s=Ppcw->UCWparm+ppodt->upodelmoffs;	//parm to be strcat//~v70qR~
        }                                                          //~v70qI~
	    if (!ppodt->upoquate)	//not quotation enclosed 1st parm  //~v70tI~
        	if (!strcmp(pc,ORGFILENAMEID))                         //~v70tI~
            {                                                      //~v70tI~
                if (ii)                                            //~v70tI~
	            	orgfilenamesw|=2;	//as parm2                 //~v70tR~
                else                                               //~v70tI~
	            	orgfilenamesw|=1;	//as parm1                 //~v70tI~
            }                                                      //~v70tI~
    	if (ii==1)                                                 //~v70qI~
        {                                                          //~v70qI~
	    	parm2s=Ppcw->UCWparm+ppodt->upodelmoffs;    //parm to be strcat//~v70qI~
	    	if (!ppodt->upoquate)	//not quotation enclosed 1st parm//~v70qI~
        		parm1=pc;			//to be chk ="*" after drop ">"//~v70qI~
        }                                                          //~v70qI~
		len=(int)strlen(pc);                                       //~v58JI~
    	if (*redirectstdin && (pcr=strchr(pc,'<'))) // "opd<stdinf" case(no space before "<")//~v70rR~
        {                                                          //~v70rI~
	        offs=ppodt->upodelmoffs;                               //~v70rI~
          	if (offs>=netcmdlen)                                   //~v70rI~
          	{                                                      //~v70rI~
        		*pcr=0;                                            //~v70rI~
            	if (pc!=pcr)	//top is not ">"                   //~v70rI~
                	parmctr++;                                     //~v70rI~
            	break;                                             //~v70rI~
          	}//valid redirect sign                                 //~v70rI~
        }                                                          //~v70rI~
    	pcr=strchr(pc,'>');	//redirect filename                    //~v58JI~
    	if (pcr)	//redirect filename                            //~v58JI~
        {                                                          //~v58JI~
	        offs=ppodt->upodelmoffs;                               //~v58JI~
          if (offs>=netcmdlen)                                     //~v58JI~
          {                                                        //~v58JI~
        	*pcr=0;                                                //~v58JI~
//      	if (*(pcr+1))                                          //~v58JI~
//          {                                                      //~v58JI~
//          	redirectfnm=pcr+1;                                 //~v58JI~
//              redirectparmsw=2;                                  //~v58JI~
//          }                                                      //~v58JI~
//          else                                                   //~v58JI~
//          {                                                      //~v58JI~
//              redirectfnm="";	//once int by no redirectfilename  //~v58JI~
//              redirectparmsw=1;                                  //~v58JI~
//          }                                                      //~v58JI~
            if (pc!=pcr)	//top is not ">"                       //~v58JI~
                parmctr++;                                         //~v58JI~
            break;                                                 //~v58JI~
          }//valid redirect sign                                   //~v58JI~
        }                                                          //~v58JI~
//      else                                                       //~v58JI~
//          if (redirectparmsw)                                    //~v58JI~
//          {                                                      //~v58JI~
//          	if (redirectparmsw==2)                             //~v58JI~
//      			return errtoomany();                           //~v58JI~
//              redirectparmsw=2;                                  //~v58JI~
//              redirectfnm=pc;                                    //~v58JI~
//          }                                                      //~v58JI~
//      if (!redirectparmsw)                                       //~v58JI~
        	parmctr++;                                             //~v58JI~
        ppodt++;                                                   //~v58JI~
    }//search redirect parm                                        //~v58JI~
    if (*redirectstdin)                                            //~v70rI~
    {                                                              //~v70rI~
#ifdef UNX                                                         //~v70rI~
		if (strcmp(redirectstdin,NULLDEVICE))                      //~v70rR~
#else                                                              //~v70rI~
		if (stricmp(redirectstdin,NULLDEVICE))                     //~v70rR~
#endif                                                             //~v70rI~
	    	dcmdfullpath(Ppcw,redirectstdinfpath,redirectstdin);   //consider :://~v70rI~
        else                                                       //~v70rI~
	        strcpy(redirectstdinfpath,redirectstdin);              //~v70rI~
#if defined(LNX) && !defined(XXE) //linux console                  //~vaa7I~
#else                                                              //~vaa7I~
        stdinredirectsw=1;                                         //~v70rI~
#endif                                                             //~vaa7I~
    }                                                              //~v70rI~
    else                                                           //~v70rI~
        strcpy(redirectstdinfpath,NULLDEVICE);                     //~v70rI~
//  if (parmctr>1)                                                 //~v528R~
//      return errtoomany();                                       //~v528R~
    pfh=0;      //for the case file operand exist(not cur file)    //~v53VI~
    if (Ppcw->UCWtype==UCWTFILE                                    //~v0k4R~
    &&  Ppcw->UCWmenuopt!=PANMOCMD)                                //~v0k4I~
    {                                                              //~v20MI~
        pfc=Ppcw->UCWpfc;                                          //~v20MI~
        pfh=pfc->UFCpfh;                                           //~v20MI~
#ifdef FTPSUPP                                                     //~v8@BI~
        puftph=pfh->UFHpuftph; 		//avoid c005 abend             //~v8@BI~
#endif                                                             //~v8@BI~
      if (pfh->UFHtype==UFHTKFI)    //funckey                      //~v20MI~
        editsw=0;                                                  //~v20MI~
      else                                                         //~v20MI~
      {                                                            //~v70qI~
        editsw=1;                                                  //~v0k4I~
        if (parm1 && *parm1=='*' && *(parm1+1)==0)                 //~v70qR~
        	editsw2=1;	//parm1 is "*" and to be replaced          //~v70qI~
      }                                                            //~v70qI~
    }                                                              //~v20MI~
    else                                                           //~v0k4I~
        editsw=0;                                                  //~v0k4I~
    if (!editsw)	//not edit/browse scr                          //~v70tI~
    	orgfilenamesw=0;                                           //~v70tR~
//  if (parmctr)                                                   //~v58HR~
	    fnm=Ppcw->UCWopdpot;                                       //~v51XR~
//  else                                                           //~v58HR~
    if (fnm && !*fnm)                                              //~v58HI~
        fnm=0;                                                     //~v51XR~
//  if (!(fnm=Ppcw->UCWopdpot)                                     //~v51XM~
    if (!fnm                                                       //~v51XR~
//  ||   *fnm=='<'		//stdin redirect at 1st opd                //~v70rR~
//  ||   (*fnm=='*'	&& *(fnm+1)=='<')                              //~v70rR~
    ||   (*fnm=='*' && *(fnm+1)==0))    //operand not exist        //~v0k4I~
    {                                                              //~v0k4I~
        if (editsw)                                                //~v0k4I~
        {                                                          //~v0k4I~
            if (fnm)                                               //~v0k4M~
//  		  if (*fnm=='<')		//stdin redirect at 1st opd    //~v70rR~
//              editsw=4;   //with opernd start by input redirect  //~v70rR~
//            else                                                 //~v70rR~
                editsw=3;   //with opernd                          //~v0k4M~
            else                                                   //~v0k4M~
                editsw=2;   //no operand                           //~v0k4M~
                                                                   //~v0k4I~
//          pfc=Ppcw->UCWpfc;                                      //~v20MR~
//          pfh=pfc->UFCpfh;                                       //~v20MR~
            fnm=pfh->UFHfilename;                                  //~v0k4I~
        }                                                          //~v0k4I~
        else                                                       //~v0k4I~
        {                                                          //~v70qI~
//          return errmissing();                                   //~v70qR~
            uerrmsg("missing filename.(\"*\" is not used at this panel)",0);//~v70qR~
            return 4;                                              //~v70qI~
        }                                                          //~v70qI~
    }                                                              //~v0k4I~
#ifdef UNX                                                         //~v197I~
    if (editsw<2)   //direct submit(not edit temp file)            //~v197I~
    {                                                              //~v197I~
      if (stricmp(fnm,TSOSUBCMD))	//not sub sub(from dlcmd6)     //~v78XI~
      {                                                            //~v78XI~
		if (!dcmdfullpath(Ppcw,fpath2,fnm))                        //~v78WR~
        {                                                          //~v78WI~
            uerrmsg("filename(%s) err",0,                          //~v78WI~
            		fnm);                                          //~v78WI~
        	return 4;                                              //~v78WI~
        }                                                          //~v78WI~
    	fnm=fpath2;                                                //~v78WR~
      }                                                            //~v78XI~
#ifdef FTPSUPP                                                     //~v53VI~
      if (!(remotefileopdsw=uftpisremote(fnm,&puftph)))	//allow not-x for remote file//~v55fR~
#endif                                                             //~v53VI~
        if (!uattrxchk(fnm,UAXC_MSG))   //not executable           //~v197I~
            return 8;                                              //~v197I~
    }                                                              //~v197I~
#else  //!UNX                                                      //~v197I~
//    extid=uextchk(fnm); //0:other ext,1:exe.2:com,3:bat(DOS)/cmd(else),4:bat(else DOS),9:no ext//~v52aR~
//    switch(extid)                                                //~v52aR~
//    {                                                            //~v52aR~
//    case 0:     //other ext                                      //~v52aR~
//        if (editsw<2)                                            //~v52aR~
////          return dcmdextnmerr();                               //~v52aR~
//            return dcmdextnmerr(fnm);                            //~v52aR~
//        break;                                                   //~v52aR~
//    case 9:     //no ext                                         //~v52aR~
////        if (editsw<2)                                          //~v52aR~
////            return dcmdextnmerr();                             //~v52aR~
////      break;                                                   //~v52aR~
//    case 1:     //exe                                            //~v52aR~
//    case 2:     //com                                            //~v52aR~
////      return dcmdextnmerr();                                   //~v52aR~
//        return dcmdextnmerr(fnm);                                //~v52aR~
//#ifdef  DOS                                                      //~v52aR~
//    case 3:     //bat                                            //~v52aR~
//        break;                                                   //~v52aR~
//#else                                                            //~v52aR~
//    case 3:     //cmd                                            //~v52aR~
//    #ifdef W32                                                   //~v52aR~
//        if (!udosiswinnt())                                      //~v52aR~
////          return dcmdextnmerr();                               //~v52aR~
//            return dcmdextnmerr(fnm);                            //~v52aR~
//        break;                                                   //~v52aR~
//    #else                                                        //~v52aR~
//        break;                                                   //~v52aR~
//    #endif                                                       //~v52aR~
//    case 4:     //bat                                            //~v52aR~
//    #ifdef OS2                                                   //~v52aR~
////      return dcmdextnmerr();                                   //~v52aR~
//        return dcmdextnmerr(fnm);                                //~v52aR~
//    #else                                                        //~v52aR~
//        break;                                                   //~v52aR~
//    #endif                                                       //~v52aR~
//#endif                                                           //~v52aR~
//    }                                                            //~v52aR~
#ifdef FTPSUPP                                                     //~v53VI~
    if (editsw<2)	//submit direct from filename                  //~v55fI~
    {                                                              //~v78WI~
      if (stricmp(fnm,TSOSUBCMD))	//not sub sub(from dlcmd6)     //~v78XI~
      {                                                            //~v78XI~
		if (!dcmdfullpath(Ppcw,fpath2,fnm))                        //~v78WR~
        {                                                          //~v78WI~
            uerrmsg("filename(%s) err",0,                          //~v78WI~
            		fnm);                                          //~v78WI~
        	return 4;                                              //~v78WI~
        }                                                          //~v78WI~
    	fnm=fpath2;                                                //~v78WI~
      }                                                            //~v78XI~
      remotefileopdsw=uftpisremote(fnm,&puftph);	//save if remote//~v55fR~
    }                                                              //~v78WI~
#endif                                                             //~v53VI~
#endif //!UNX                                                      //~v197I~
//copy current edit file                                           //~v0k4I~
//  if (editsw>=2)                                                 //~v53VR~
    if (editsw>=2                                                  //~v53VI~
#ifdef FTPSUPP                                                     //~v53VI~
    ||  remotefileopdsw     //remote file name operand exist       //~v53VR~
#endif                                                             //~v53VI~
    )                                                              //~v53VI~
    {                                                              //~v0k4I~
//      strcpy(tempcmdfnm,WORKDIRPATHID TEMPCMDFNM);               //~v637R~
//#ifndef UNX                                                      //~v637R~
//#ifdef OS2                                                       //~v637R~
//        strcat(tempcmdfnm,".CMD");                               //~v637R~
//#else                                                            //~v637R~
//        strcat(tempcmdfnm,".BAT");                               //~v637R~
//#endif                                                           //~v637R~
//#endif //!UNX                                                    //~v637R~
#ifdef FTPSUPP                                                     //~v71FI~
	  tsosavesw=1;                                                 //~v71FI~
      if (editsw==2     //no operand                               //~v71FI~
      &&  FILEISTSO(pfh)   //on TSO file edit screen               //~v71FI~
	  &&  pfh->UFHupctr==pfh->UFHupctrsave)	//same as saved        //~v71FI~
      {                                                            //~v71FI~
        strcpy(cmd,pfh->UFHftpwdfnm);                              //~v71FI~
        tsosavesw=0;                                               //~v71FI~
      }                                                            //~v71FI~
      else                                                         //~v71FI~
      {                                                            //~v71FI~
#endif                                                             //~v71FI~
        strcpy(tempcmdfnm,DCMDSUBMITCMDFNM);                       //~v637M~
        Gdcmdtempf|=GDCMDTEMPF_SUB; //del at term                  //~v637M~
        if (!filefullpath(cmd,tempcmdfnm,_MAX_PATH))               //~v0k4R~
            return 4;                                              //~v0k4M~
#ifdef FTPSUPP                                                     //~v71FI~
      }//save required                                             //~v71FI~
#endif                                                             //~v71FI~
//      if (filesave(0,pfh,0,0,cmd))                               //~v445R~
#ifdef FTPSUPP                                                     //~v55fI~
    if (editsw>=2)                                                 //~v55fI~
    {                                                              //~v55fI~
      if (tsosavesw)                                               //~v71FI~
      {                                                            //~v71FI~
#endif                                                             //~v55fI~
        if (filesave(Ppcw,0,pfh,0,0,cmd))                          //~v445R~
            return 4;                                              //~v0k4I~
#ifdef FTPSUPP                                                     //~v55fI~
      }                                                            //~v71FI~
    }                                                              //~v55fI~
    else                                                           //~v55fI~
    {                                                              //~v55fI~
  	  if (UFTPHISTSO(puftph))   //host is tso                      //~v78VI~
      {                                                            //~v78VI~
       if (!UFTPHISTSOSUBM(puftph)) //not use TSO SUBMIT cmd       //~v78XR~
       {                                                           //~v8@BI~
//		if (xeftpgetremotecopy(XEFTP_GRC_CHKNORMAL|XEFTP_GRC_FPATH,fnm,puftph,cmd,fnm))//~v78VI~//+vb7eR~
  		if (xeftpgetremotecopy(XEFTP_GRC_CHKNORMAL|XEFTP_GRC_FPATH,fnm,puftph,cmd,sizeof(cmd),fnm))//+vb7eI~
            return 4;                                              //~v78VI~
       }                                                           //~v8@BI~
        tsofilesw=1;                                               //~v78VI~
      }                                                            //~v78VI~
      else                                                         //~v78VI~
      {                                                            //~v78VI~
        if (uftpxcopy(puftph,0,fnm,cmd,DCPY_EXISTING,FILE_ALL-FILE_DIRECTORY))//~v55fR~
            return 4;                                              //~v55fI~
      }                                                            //~v78VI~
    }                                                              //~v55fI~
#endif                                                             //~v55fI~
#ifdef UNX                                                         //~v197I~
        if (uattrxon(cmd))    //user x bit on                      //~v197R~
            return 4;                                              //~v197I~
#endif //UNX                                                       //~v197I~
        if (editsw>2)   //may have opd                             //~v0k4I~
        {                                                          //~v0k4I~
//        if (editsw==3)                                           //~v70rR~
//        {                                                        //~v70rR~
            pc=strchr(Ppcw->UCWparm,'*');                          //~v70qR~
            if (pc)                                                //~v70qR~
                strcat(cmd,pc+1);                                  //~v70qR~
//        }                                                        //~v70rR~
//        else                                                     //~v70rR~
//        {                                                        //~v70rR~
//          if (parm1s)                                            //~v70rR~
//              strcat(cmd,parm1s);                                //~v70rR~
//        }                                                        //~v70rR~
        }                                                          //~v0k4I~
#ifdef FTPSUPP                                                     //~v71FI~
//      if (editsw==2     //no operand                             //~v78VR~
        if ((tsofilesw)                                            //~v78VI~
        ||  (editsw==2                                             //~v78VI~
        && FILEISTSO(pfh))  //on TSO file edit screen              //~v71FI~
        )                                                          //~v78VI~
        {                                       //inser TSO sub cmd//~v71FI~
  	      if (UFTPHISTSO(puftph)   //host is tso                   //~v8@BI~
          &&  UFTPHISTSOSUBM(puftph)) //use TSO SUBMIT cmd         //~v78XI~
          {                                                        //~v8@BI~
          	tsosubrc=xetsosubmit(0,puftph,                         //~v8@BR~
            					(editsw>=2 ? (char*)(pfh->UFHfilename) : fnm),//~v78XR~
								((tsosavesw && !tsofilesw) ? cmd : 0));//~v8@BR~
            tsofilesw=2;	//skip system call                     //~v8@BI~
          }                                                        //~v8@BI~
          else                                                     //~v8@BI~
          {                                                        //~v8@BI~
	        len=(int)strlen(cmd);                                  //~v71FI~
	        len2=sizeof(TSOSUBCMD)-1;                              //~v71FI~
            memmove(cmd+len2+1,cmd,(UINT)(len+1));                 //~v71FR~
            memcpy(cmd,TSOSUBCMD,(UINT)len2);                      //~v71FI~
            *(cmd+len2)=' ';                                       //~v71FI~
          }                                                        //~v8@BI~
        }                                                          //~v71FI~
#endif                                                             //~v71FI~
        Ppcw->UCWparm=cmd;  //parm to func_save_file               //~v0k4R~
    }                                                              //~v0k4I~
    else 	//!(sub file is current file or remote file)           //~v70qI~
    {                                                              //~v70qI~
    	if (orgfilenamesw & 1)	//filename is "**"                 //~v70tR~
			uparsein(pfh->UFHfilename,cmd,_MAX_PATH,0,'"');	//enclose if space embedding//~v70tI~
        else                                                       //~v70tI~
		if (dcmdexefullpath(Ppcw,cmd,fnm)>=4)	//process *\,:: etc//~v70qI~
        	return 4;                                              //~v70qI~
        len=(int)strlen(cmd);                                      //~v70rR~
        if (editsw2)	//2nd opd is "*" to be replaced            //~v70qI~
        {                                                          //~v70qI~
        	*(cmd+len++)=' ';                                      //~v70qI~
			if (pfh->UFHupctr==pfh->UFHupctrsave)	//same as saved//~v70qI~
#ifdef FTPSUPP                                                     //~v71DI~
              if (FILEISREMOTE(pfh))                               //~v71DI~
		        uparsein(pfh->UFHftpwdfnm,cmd+len,_MAX_PATH,0,'"');	//enclose if space embedding//~v71DI~
              else                                                 //~v71DI~
#endif                                                             //~v71DI~
		        uparsein(pfh->UFHfilename,cmd+len,_MAX_PATH,0,'"');	//enclose if space embedding//~v70qR~
            else                                                   //~v70qI~
            {                                                      //~v70qI~
                strcpy(tempcmdfnm,DCMDSUBMITCMDFNM);               //~v70qI~
                Gdcmdtempf|=GDCMDTEMPF_SUB; //del at term          //~v70qI~
                if (!filefullpath(cmd+len,tempcmdfnm,_MAX_PATH))   //~v70qI~
                    return 4;                                      //~v70qI~
                if (filesave(Ppcw,0,pfh,0,0,cmd+len))              //~v70qI~
                    return 4;                                      //~v70qI~
#ifdef FTPSUPP                                                     //~v71DI~
              if (!FILEISTSO(pfh))                                 //~v71DR~
              {                                                    //~v71DI~
#endif                                                             //~v71DI~
                attr=pfh->UFHattr;                                 //~v70qI~
		        uattrib(cmd+len,attr,0xff,&attr); //copy attr      //~v70qI~
#ifdef FTPSUPP                                                     //~v71DI~
              }                                                    //~v71DI~
#endif                                                             //~v71DI~
            }                                                      //~v70qI~
            if (parm2s)	//other parm                               //~v70qI~
            {                                                      //~v70qI~
            	len+=(int)strlen(cmd+len);                         //~v70rR~
        		strcpy(cmd+len,parm2s);                            //~v70qI~
            }                                                      //~v70qI~
        }                                                          //~v70qI~
        else                                                       //~v70qI~
        {                                                          //~v70qI~
            if (parm1s)	//other parm                               //~v70qR~
        		strcpy(cmd+len,parm1s);                            //~v70qR~
        }                                                          //~v70qI~
        Ppcw->UCWparm=cmd;  //parm to func_save_file               //~v70qI~
    }                                                              //~v70qI~
#ifdef FTPSUPP                                                     //~v798I~
  if (tsofilesw!=2)	//skip system call                             //~v8@BI~
  {                                                                //~v8@BI~
#endif                                                             //~v798I~
    if (orgfilenamesw & 2)	//parm "**" specified                  //~v70tR~
    {                                                              //~v70tI~
        pc=strstr(cmd,ORGFILENAMEID);                              //~v70tI~
        if (pc && *(pc-1)==' ' && (*(pc+2)==' '||*(pc+2)==0))      //~v70tI~
        {                                                          //~v70tI~
			uparsein(pfh->UFHfilename,fpath,_MAX_PATH,0,'"');	//enclose if space embedding//~v70tI~
        	len=(int)strlen(pc+2);                                 //~v70tI~
	        len2=(int)strlen(fpath);                               //~v70tR~
            if (len)                                               //~v70tI~
            	memmove(pc+len2,pc+2,(UINT)(len+1));               //~v70tR~
            else                                                   //~v70tI~
            	*(pc+len2)=0;                                      //~v70tI~
            memcpy(pc,fpath,(UINT)len2);                           //~v70tR~
        }                                                          //~v70tI~
    }                                                              //~v70tI~
//execute                                                          //~v0k4I~
//  if (redirectfnm)                                               //~v58FR~
    if (*redirectfnm||*redirectfnm2||Ppcw->UCWmenuopt==PANMOCMD)   //~v58FI~
    {                                                              //~v51XI~
        strcat(cmd," <");                                          //~v70rM~
        strcat(cmd,redirectstdinfpath);                            //~v70rM~
        pstdofnm=redirectfnm;                                      //~v58FI~
        pstdefnm=redirectfnm2;                                     //~v58FI~
//      if (Ppcw->UCWmenuopt!=PANMOCMD)                            //~v58PR~
//      {                                                          //~v58PR~
//      	if (!*pstdefnm)                                        //~v58PR~
//          	pstdefnm=0;	//no redirect                          //~v58PR~
//      }                                                          //~v58PR~
//  	strcpy(redirectfnm2,redirectfnm);	//output when sofile selected//~v58FR~
//  	Sredirectfnm=redirectfnm2;	//parm to dcmd_system from submit//~v58FR~
//      rc=dcmdsystemcall(Ppcw,Ppcw->UCWparm);                     //~v58FR~
        rc=dcmdsystemcall(Ppcw,Ppcw->UCWparm,redirsw,pstdofnm,pstdefnm);//~v58FR~
//  	Sredirectfnm=0;                                            //~v58FR~
        return rc;                                                 //~v51XI~
    }                                                              //~v51XI~
#if defined(LNX) && !defined(XXE) //linux console                  //~v70rR~
#else                                                              //~v70rI~
	if (stdinredirectsw)	//user specified stdin redirect        //~v70rR~
    {                                                              //~v70rI~
#endif                                                             //~v70rI~
        strcat(cmd," <");                                          //~v70rI~
        strcat(cmd,redirectstdinfpath);                            //~v70rI~
#if defined(LNX) && !defined(XXE) //linux console                  //~v70rI~
#else                                                              //~v70rI~
    }                                                              //~v70rI~
#endif                                                             //~v70rI~
    dcmd_system(Ppcw);                                             //~v0k4I~
#ifdef FTPSUPP                                                     //~v798I~
  }                                                                //~v8@BI~
  else                                                             //~v8@BI~
  	return tsosubrc;                                               //~v8@BI~
#endif                                                             //~v798I~
    return 0;                                                      //~v0k4I~
}//func_submit                                                     //~v0k4I~
#ifdef FTPSUPP                                                     //~v592M~
//**************************************************************** //~v592I~
//!rsh                                                             //~v592I~
//* rsh hostid:[username] cmd-string                               //~v592I~
//*ret :rc 8                                                       //~v592I~
//**************************************************************** //~v592I~
int func_rsh(PUCLIENTWE Ppcw)                                      //~v592I~
{                                                                  //~v592I~
    PUFTPHOST  puftph=0;                                           //~v59aR~
    PUFILEH    pfh=0;                                                //~v599I~//~vafcR~
    char *pc,stdofnm[_MAX_PATH],stdefnm[_MAX_PATH],fpath[_MAX_PATH];//~v592I~
    char sofname[_MAX_PATH];                                       //~v598R~
	char *phostid,*pcmdstr,*puserid=0;                             //~v59gR~
	UCHAR *logcmd;                                                 //~v59gI~
    int redirsw,netcmdlen,hostnmlen,rc,crc,len,currshellsw,remotesw=0;//~v59bR~
    int procctr;                                                   //~v59bI~
    ULONG opt=0;                                                   //~v592I~
    void *voidphostid;                                             //~v59bI~
    char cmdsv[MAXCOLUMN+1];                                       //~v592I~
    char cmdwk[_MAX_PATH+MAXCOLUMN+1];                             //~v59aI~
    char tmpcmdfnm[_MAX_PATH];                                     //~v59bR~
//*******************                                              //~v592I~
	*sofname=0;                                                    //~v592I~
    pc=Ppcw->UCWparm;                                              //~v592R~
    if (!pc)                                                       //~v592I~
    	return dcmd_rshhelp();                                     //~v592I~
//get redirect parm                                                //~v592I~
//  if (uprocparseredirect(pc,stdofnm,stdefnm,&redirsw,&netcmdlen))//~v70rR~
    if (uprocparseredirect(pc,0,stdofnm,stdefnm,&redirsw,&netcmdlen))//0:no stdin//~v70rI~
        return dcmdredirectparmerr();                              //~v592I~
    *(pc+netcmdlen)=0;                                             //~v592I~
    strcpy(cmdsv,"rsh ");                                          //~v592I~
    strncpy(cmdsv+4,pc,MAXCOLUMN-4);                               //~v592R~
    *(cmdsv+MAXCOLUMN)=0;                                          //~v592I~
    if (redirsw & PRERC_STDOAPPEND)                                //~v592I~
    	opt|=UPROC_APPENDSO;                                       //~v592I~
    if (redirsw & PRERC_STDEAPPEND)                                //~v592I~
    	opt|=UPROC_APPENDSE;                                       //~v592I~
    if (*stdofnm)                                                  //~v592I~
    {                                                              //~v592I~
    	if (!dcmdfullpath(Ppcw,fpath,stdofnm))   //consider ::     //~v592I~
        	return 4;                                              //~v592I~
    }                                                              //~v592I~
    else                                                           //~v592I~
    {                                                              //~v592I~
        if (dcmdgetsofname(sofname,fpath)) //get stdout work       //~v592I~
            return 4;                                              //~v592I~
    }                                                              //~v592I~
    strcpy(stdofnm,fpath);                                         //~v592I~
    if (*stdefnm)                                                  //~v592I~
    {                                                              //~v592I~
        if (*stdefnm=='&')                                         //~v592I~
			strcpy(stdefnm,STR_REDIRECT21);                        //~v592I~
        else                                                       //~v592I~
        {                                                          //~v592I~
	    	if (!dcmdfullpath(Ppcw,stdefnm,stdefnm))   //consider :://~v592I~
	        	return 4;                                          //~v592I~
        }                                                          //~v592I~
    }                                                              //~v592I~
    else                                                           //~v592I~
		strcpy(stdefnm,STR_REDIRECT21);                            //~v592I~
//cv parm                                                          //~v59aM~
	if (!memicmp(pc,"-E2S",4))                                     //~v59aR~
    {                                                              //~v59aI~
        opt|=UPROC_CVE2S;  //euc-->sjis                            //~v59aI~
        pc+=4;                                                     //~v59aI~
        pc+=strspn(pc," ");                                        //~v59aI~
    }                                                              //~v59aI~
    else                                                           //~v59aI~
	if (!memicmp(pc,"-S2E",4))                                     //~v59aR~
    {                                                              //~v59aI~
        opt|=UPROC_CVS2E;  //sjis-->euc                            //~v59aI~
        pc+=4;                                                     //~v59aI~
        pc+=strspn(pc," ");                                        //~v59aI~
    }                                                              //~v59aI~
//userid chk for "rsh -l user * cmdparm" patern                    //~v59aI~
	if (dcmdrshgetuseridparm(&pc,&puserid))                        //~v59aR~
    	return dcmd_rshhelp();                                     //~v59aI~
//get hostid,userid                                                //~v592I~
	phostid=pc;                                                    //~v59bR~
    currshellsw=(*phostid=='*'&&(*(phostid+1)==' '||*(phostid+1)==0));//~v59aR~
	pc=strpbrk(phostid," :");                                      //~v59aR~
    if (!pc)                                                       //~v592I~
      if (!currshellsw)                                            //~v59aR~
    	return dcmd_rshhelp();                                     //~v592I~
      else                                                         //~v59aI~
        pc=phostid+strlen(phostid);                                //~v59aI~
    else                                                           //~v59aI~
    	remotesw=(*pc==':');                                       //~v59bR~
    if (Ppcw->UCWmenuopt==PANMOCMD)                                //~v59gI~
    	if (remotesw &&  !*(pc+1) && !puserid) //"rsh hostid:" fmt //~v59gR~
        	return dcmdrloginsetup(Ppcw,phostid);                  //~v59gI~
    *tmpcmdfnm=0;	//tmp save cmd file                            //~v59bI~
  if (*pc==':' && *(pc+1)!=' ')   //hsotid specification,cmd can be continued without userid parm//~v59aI~
  { //"hostid:cmd cmdparm..."  patern                              //~v59aI~
      puserid=0;  //no userid                                      //~v59aI~
      pcmdstr=pc+1;                                                //~v59aI~
  }                                                                //~v59aI~
  else   // "hostid: [-l user] cmd cmdparm..."                     //~v59aI~
  {                                                                //~v59aI~
  	if (*pc==':')                                                  //~v59aI~
    	pc++;                                                      //~v59aI~
    if (*pc)                                                       //~v59aI~
	    *pc++=0;                                                   //~v59aR~
    pcmdstr=pc+strspn(pc," ");	                                   //~v592I~
//userid parm("-l userid")                                         //~v598I~
	if (!puserid)                                                  //~v59aI~
		if (dcmdrshgetuseridparm(&pcmdstr,&puserid))               //~v59aR~
	    	return dcmd_rshhelp();                                 //~v59aI~
    if (!strcmp(phostid,"*:")   // hsotid="*:"                     //~v59aR~
    ||  currshellsw)	//"rsh * [-l user] cmdparm" fmt            //~v59aR~
    {                                                              //~v599I~
    	if (Ppcw->UCWtype==UCWTFILE                                //~v599I~
    	||  Ppcw->UCWtype==UCWTDIR)                                //~v599I~
        {                                                          //~v599I~
        	pfh=UGETPFHFROMPCW(Ppcw);                              //~v599I~
            puftph=pfh->UFHpuftph;                                 //~v59bR~
        }                                                          //~v599I~
    	if (!puftph)                                               //~v59bR~
        {                                                          //~v599I~
            uerrmsg("\"*\" is valid for remote file screen.",      //~v59aR~
                    "\"*\"はリモートファイル画面で使用。");        //~v59aR~
            return 4;                                              //~v599I~
        }                                                          //~v599I~
    	remotesw=1;                                                //~v59bI~
    	hostnmlen=puftph->UFTPHhostnmlen;                          //~v59bI~
        if (currshellsw)	//"rsh *" format                       //~v59aR~
        {                                                          //~v59aI~
		  if (pfh->UFHupctr==pfh->UFHupctrsave)	//saved            //~v59bI~
        	strcpy(cmdwk,pfh->UFHfilename+hostnmlen+1);	//allow not-x for remote file//~v59aI~
          else                                                     //~v59bI~
          {                                                        //~v59bI~
          	if (dcmdrshcreatetempshell(Ppcw,pfh,tmpcmdfnm))//save to remote temp and set to cmdstring//~v59bR~
            	return 4;                                          //~v59bI~
            strcpy(cmdwk,tmpcmdfnm+hostnmlen+1);//drop hostid      //~v59bR~
          }                                                        //~v59bI~
//          len=strlen(cmdwk);                                     //~v59aI~//~vb30R~
            len=(int)strlen(cmdwk);                                //~vb30I~
            pc=cmdwk+len++;                                        //~v59aI~
            *pc++=' ';                                             //~v59aI~
//          len=sizeof(cmdwk)-len-1;                               //~v59aI~//~vb30R~
            len=(int)sizeof(cmdwk)-len-1;                          //~vb30I~
//          strncpy(pc,pcmdstr,len);                               //~v59aI~//~vb30R~
            strncpy(pc,pcmdstr,(size_t)len);                       //~vb30I~
            *(pc+len)=0;                                           //~v59aI~
            pcmdstr=cmdwk;                                         //~v59aR~
        }                                                          //~v59aI~
    }//"rsh *: cmd" or "rsh * cmdparm" fmt                         //~v59aR~
  }// hostid [-l user] cmd string patern                           //~v59aI~
  	if (remotesw && !puftph)                                       //~v59bR~
    {                                                              //~v59aI~
      	if (!uftpisremote(phostid,&puftph))	//allow not-x for remote file//~v59aR~
			return dcmd_hostiderr(phostid);                        //~v59gI~
    }                                                              //~v59aI~
    if (remotesw)                                                  //~v59bI~
    {                                                              //~v59bI~
        opt|=UPROC_PUFTPH;                                         //~v59bI~
        voidphostid=(void*)puftph;                                 //~v59bR~
        if (UFTPHISTSO(puftph))                                    //~v72BI~
        {                                                          //~v72BI~
            uerrmsg("%s is TSO,use TSO command",                   //~v72BI~
                    "%s は TSO ホストです。TSO コマンドを使用してください。",//~v72BI~
						puftph->UFTPHhost);                        //~v72BI~
            return 4;                                              //~v72BI~
        }                                                          //~v72BI~
    }                                                              //~v59bI~
    else                                                           //~v59bI~
        voidphostid=(void*)phostid;                                //~v59bR~
//execute                                                          //~v592I~
    opt|=UPROC_RSHLOG;  //log rsh response                         //~v59dI~
	crc=rc=uproc_rsh(opt,voidphostid,puserid,pcmdstr,stdofnm,stdefnm,0,0,0,0);//no buff out//~v59bR~
    if (*tmpcmdfnm) 	//tmp save cmd file                        //~v59cR~
		uxdelete(tmpcmdfnm,0,UXDELFORCE,&procctr,&procctr,&procctr);//~v59bI~
    if (rc!=-1)                                                    //~v598R~
    {                                                              //~v592I~
        if (Ppcw->UCWmenuopt==PANMOCMD) //not cmd pannel           //~v592I~
        {                                                          //~v592I~
        	logcmd=cmdsv;                                          //~v592R~
			dcmdeditredirect(redirsw,&logcmd,stdofnm,stdefnm);     //~v592R~
            rc+=dcmdappendso(Ppcw,sofname,logcmd);                 //~v592I~
            if (Ppcw->UCWsplitid)   //0:first,1:second screen      //~v592I~
                UCBITON(((PUSCRD)scrgetcw(1)->UCWpsd)->USDflag2,USDF2DRAW);//draw hdr//~v592I~
            ufree(logcmd);                                         //~v592I~
        }                                                          //~v592I~
        else                                                       //~v592I~
            rc+=dcmdsolast(sofname,fpath,crc);//from stdout        //~v592I~
    }                                                              //~v592I~
    return rc;                                                     //~v592I~
}//func_rsh                                                        //~v592I~
//**************************************************************** //~v59cI~
//!rshlocal                                                        //~v59cI~
//* submit local shell to remote                                   //~v59cI~
//*   called by % lcmd                                             //~v59cI~
//*ret :rc                                                         //~v59cI~
//**************************************************************** //~v59cI~
int dcmdrshlocalfile(PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pcmdfile,char *Pstdofnm,char *Pstdefnm)//~v59cR~
{                                                                  //~v59cI~
	PUFTPHOST puftph;                                              //~v59cI~
    char *pc;                                                      //~v59cI~
    char cmdwk[_MAX_PATH+_MAX_PATH+_MAX_PATH+8];                   //~v59cR~
    char tmpcmdfnm[_MAX_PATH];                                     //~v59cR~
    int procctr,len,rc;                                            //~v59cR~
//*******************                                              //~v59cI~
	puftph=Ppfh->UFHpuftph;                                        //~v59cM~
	uftptempnam(puftph->UFTPHhost,TEMPRSHCMDF,tmpcmdfnm);          //~v59cR~
	if (rc=uftpxcopy(0,puftph,Pcmdfile,tmpcmdfnm,DCPY_FTPTEXTMODE,FILE_ALL-FILE_DIRECTORY),rc)//~v59cR~
        return rc;                                                 //~v59cR~
    if (rc=uattrxon(tmpcmdfnm),rc)    //user x bit on              //~v59cI~
    {                                                              //~v59cI~
		rc+=uxdelete(tmpcmdfnm,0,UXDELFORCE,&procctr,&procctr,&procctr);//~v59cI~
        return rc;                                                 //~v59cI~
    }                                                              //~v59cI~
//  len=strlen(tmpcmdfnm);                                         //~v59cI~//~vb30R~
    len=(int)strlen(tmpcmdfnm);                                    //~vb30I~
    memcpy(cmdwk,tmpcmdfnm,(UINT)len);                             //~v59cI~
    pc=cmdwk+len;                                                  //~v59cI~
    if (Pstdofnm && *Pstdofnm)                                     //~v59cI~
    	pc+=sprintf(pc," >%s",Pstdofnm);                           //~v59cR~
    if (Pstdefnm && *Pstdefnm)                                     //~v59cI~
    	pc+=sprintf(pc," 2>%s",Pstdefnm);                          //~v59cR~
    if (rc=xeftplog(0,Ppfh,Pcmdfile,tmpcmdfnm),rc)	//log from local file//~v59dI~
    	return rc;                                                 //~v59dI~
    Ppcw->UCWparm=cmdwk;                                           //~v59cI~
    rc=func_rsh(Ppcw);                                             //~v59cI~
	rc+=uxdelete(tmpcmdfnm,0,UXDELFORCE,&procctr,&procctr,&procctr);//~v59cI~
    return rc;                                                     //~v59cI~
}//dcmdrshlocalfile                                                //~v59cR~
//***********************************************************      //~v59aI~
//* dcmdrshgetuseridparm                                           //~v59aI~
//***********************************************************      //~v59aI~
int dcmdrshgetuseridparm(char **Ppparmstr,char **Ppuserid)         //~v59aR~
{                                                                  //~v59aI~
	char *pc,*puserid;                                             //~v59aI~
//********************                                             //~v59aI~
	pc=*Ppparmstr;                                                 //~v59aI~
    if (*pc=='-'	//userid specified                             //~v59aI~
    &&  toupper(*(pc+1))=='L')	//userid specified                 //~v59aI~
    {                                                              //~v59aI~
    	puserid=pc+2;                                              //~v59aI~
	    puserid+=strspn(puserid," ");                              //~v59aI~
	    if (!*puserid)                                             //~v59aI~
    		return 4;                                              //~v59aI~
        pc=strchr(puserid,' ');                                    //~v59aI~
//      if (!*pc)                                                  //~v72LR~
        if (!pc)                                                   //~v72LR~
    		return 4;                                              //~v59aI~
        *pc++=0;                                                   //~v59aI~
        pc+=strspn(pc," ");                                        //~v59aI~
        *Ppuserid=puserid;                                         //~v59aR~
        *Ppparmstr=pc;		//advance parm to be chked             //~v59aR~
    }                                                              //~v59aI~
	return 0;                                                      //~v59aR~
}//dcmdgetuseridparm                                               //~v59aI~
//***********************************************************      //~v59bI~
//* dcmdrshcreatetempshell                                         //~v59bI~
//* create temp shell from current edit screen and setup cmd verb  //~v59bI~
//***********************************************************      //~v59bI~
int dcmdrshcreatetempshell(PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pcmdstr)//~v59bI~
{                                                                  //~v59bI~
    char tmpcmdfnm[_MAX_PATH];                                     //~v59cR~
    PUFTPHOST puftph;                                              //~v59bR~
//********************                                             //~v59bI~
	puftph=Ppfh->UFHpuftph;                                        //~v59bI~
	uftptempnam(puftph->UFTPHhost,TEMPRSHCMDF,tmpcmdfnm);          //~v59cR~
    if (filesave(Ppcw,0,Ppfh,0,0,tmpcmdfnm))//no end,no line sta/end out file//~v59bR~
    	return 4;                                                  //~v59bI~
    if (uattrxon(tmpcmdfnm))    //user x bit on                    //~v59bI~
    	return 4;                                                  //~v59bI~
    strcpy(Pcmdstr,tmpcmdfnm);                                     //~v59bR~
    xeftplog(0,Ppfh,0,tmpcmdfnm);	//log from pfh                 //~v59dR~
    return 0;                                                      //~v59bI~
}//dcmdrshcreatetempshell                                          //~v59bI~
//***********************************************************      //~v59gI~
//* dcmdrshcreatetempshell                                         //~v59gI~
//* create temp shell from current edit screen and setup cmd verb  //~v59gI~
//***********************************************************      //~v59gI~
int dcmdrloginsetup(PUCLIENTWE Ppcw,char *Pphostid)                //~v59gI~
{                                                                  //~v59gI~
    PUFTPHOST puftpho,puftphn;                                     //~v59gI~
    PUFILEC  pfc;                                                  //~v59gR~
    PUFILEH  pfh;                                                  //~v59gR~
    char logtext[256];                                             //~v59gR~
//********************                                             //~v59gI~
	pfc=Ppcw->UCWpfc;                                              //~v59gI~
	pfh=pfc->UFCpfh;                                               //~v59gI~
	puftpho=pfh->UFHpuftph;	//old                                  //~v59gR~
    if (*Pphostid==':')	//reset req                                //~v59gI~
    {                                                              //~v59gI~
    	if (puftpho)                                               //~v59gI~
        {                                                          //~v59gI~
			pfh->UFHpuftph=0;	//old                              //~v59gR~
            UCBITOFF(pfh->UFHflag6,UFHF6RLOGIN);                   //~v59gI~
		    sprintf(logtext,"rlogin exit from %s:(%s).",           //~v59gM~
					puftpho->UFTPHhost,puftpho->UFTPHipad);        //~v59gM~
			dcmdrloginlog(Ppcw,pfh,logtext);                       //~v59gI~
            uerrmsg("reset rlogin to %s",0,                        //~v59gI~
					puftpho->UFTPHhost);                           //~v59gR~
            return 0;                                              //~v59gI~
        }                                                          //~v59gI~
        uerrmsg("Already local mode",0);                           //~v59gR~
        return 4;                                                  //~v59gI~
    }//reset req                                                   //~v59gI~
    if (!uftpisremote(Pphostid,&puftphn))	//allow not-x for remote file//~v59gI~
		return dcmd_hostiderr(Pphostid);                           //~v59gR~
    if (puftphn==puftpho)                                          //~v59gI~
    {                                                              //~v59gI~
    	uerrmsg("already login'ed to %s",0,                        //~v59gI~
        		puftphn->UFTPHhost);                               //~v59gI~
        return 4;                                                  //~v59gI~
    }                                                              //~v59gI~
    UCBITON(pfh->UFHflag6,UFHF6RLOGIN);                            //~v59gI~
    pfh->UFHpuftph=puftphn;  //new                                 //~v59gR~
//put delm line                                                    //~v59gI~
    sprintf(logtext,"rlogin to %s:(%s).",                          //~v59gI~
            puftphn->UFTPHhost,puftphn->UFTPHipad);                //~v59gI~
	dcmdrloginlog(Ppcw,pfh,logtext);                               //~v59gI~
    return 0;                                                      //~v59gI~
}//dcmdrshcreatetempshell                                          //~v59gI~
//**************************************************************** //~v59gI~
//!dcmdrlogincmd                                                   //~v59gI~
//* process cmd on RSH MOCMD panel                                 //~v59gI~
//*ret :rc                                                         //~v59gI~
//**************************************************************** //~v59gI~
int dcmd_rlogin(PUCLIENTWE Ppcw)                                   //~v59gR~
{                                                                  //~v59gI~
    PUFILEC  pfc;                                                  //~v59gI~
    PUFILEH  pfh;                                                  //~v59gI~
	PUFTPHOST puftph;                                              //~v59gI~
    char cmdwk[MAXCOLUMN+16],*pcmdstr;                             //~v59gR~
    int rc;                                                        //~v59gI~
//*******************                                              //~v59gI~
	pcmdstr=Ppcw->UCWparm;                                         //~v59gI~
	pfc=Ppcw->UCWpfc;                                              //~v59gI~
	pfh=pfc->UFCpfh;                                               //~v59gI~
	puftph=pfh->UFHpuftph;                                         //~v59gI~
    if (!puftph)                                                   //~v59gI~
    	return 4;                                                  //~v59gI~
    if (UFTPHISTSO(puftph))                                        //~v72BR~
    	return xetsotsocmd(Ppcw);                                  //~v72BI~
    sprintf(cmdwk,"%s:%s",puftph->UFTPHhost,pcmdstr);              //~v59gR~
    Ppcw->UCWparm=cmdwk;                                           //~v59gI~
    rc=func_rsh(Ppcw);                                             //~v59gI~
    return rc;                                                     //~v59gI~
}//dcmdrlogincmd                                                   //~v59gI~
//***********************************************************      //~v59gI~
//* dcmdrloginlog                                                  //~v59gI~
//* put log to mocmd scr                                           //~v59gI~
//***********************************************************      //~v59gI~
int dcmdrloginlog(PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Plogtext)     //~v59gR~
{                                                                  //~v59gI~
    PULINEH plh;                                                   //~v59gI~
    PUFILEC  pfc;                                                  //~v59gI~
//***************************                                      //~v59gI~
	pfc=Ppcw->UCWpfc;                                              //~v59gI~
  if (UCBITCHK(Ppfh->UFHflag8,UFHF8TSOFSMODE))                     //~v9@5R~
    plh=UGETQTOP(&Ppfh->UFHlineque);                               //~v9@5I~
  else                                                             //~v9@5I~
    plh=UGETQPREV(UGETQEND(&Ppfh->UFHlineque));                    //~v59gR~
	dcmdputcmdlog(Ppcw,plh,1,Plogtext);	//1:set timestamp          //~v59gR~
    plh=UGETQNEXT(plh);		//plh after isrt                       //~v59gI~
  if (!UCBITCHK(Ppfh->UFHflag8,UFHF8TSOFSMODE))                    //~v798I~
    pfc->UFCcurtop=plh;                                            //~v59gI~
    UCBITON(plh->ULHflag3,ULHF3CMDECHO);                           //~v59gI~
  if (!UCBITCHK(Ppfh->UFHflag8,UFHF8TSOFSMODE))                    //~v9@5R~
    UCBITON(Ppcw->UCWflag,UCWFWAKEUP|UCWFDRAW);                    //~v59gI~
  else                                                             //~v798I~
    UCBITON(plh->ULHflag,ULHFDRAW); //redraw for clear hilite      //~v798I~
    filesetcsr(Ppcw,0,0,0); //data field,fldtop,reset csr setting  //~v59gI~
    return 0;                                                      //~v59gI~
}//dcmdrloginlog                                                   //~v59gI~
//**************************************************************** //~v592I~
//!rsh help                                                        //~v592I~
//*ret :rc 4                                                       //~v592I~
//**************************************************************** //~v592I~
int dcmd_rshhelp(void)                                             //~v592I~
{                                                                  //~v592I~
    uerrmsg("rsh [-{e2s|s2e}] [-L username] {* cmd-parm | {hostid:|*:|hostname|ipaddr} [-L username] [cmd-string]}",0);//~v59gR~
    return 4;                                                      //~v592I~
}//dcmd_rshhelp                                                    //~v592I~
//**************************************************************** //~v59gI~
//!rsh hostid err                                                  //~v59gI~
//*ret :rc 4                                                       //~v59gI~
//**************************************************************** //~v59gI~
int dcmd_hostiderr(char *Pphostid)                                 //~v59gI~
{                                                                  //~v59gI~
    uerrmsg("%s is not defined on %s",0,                           //~v59gI~
            Pphostid,FTPHOSTS);                                    //~v59gI~
    return 4;                                                      //~v59gI~
}//dcmd_hostiderr                                                  //~v59gI~
#endif                                                             //~v592I~
//**************************************************************** //~v59CI~
//!xenv cmd                                                        //~v59CI~
//*ret :rc 4                                                       //~v59CI~
//**************************************************************** //~v59CI~
int dcmd_xenv(PUCLIENTWE Ppcw)                                     //~v59CI~
{                                                                  //~v59CI~
    UCHAR *pc,*pot,*newval,*varname;                               //~v59CR~
    UCHAR fpath[_MAX_PATH];                                        //~v59KI~
    PUPODELMTBL podt;                                              //~v59CI~
    int opdno,rc;                                                  //~v59CR~
#ifdef UNX                                                         //~v59FR~
  #ifdef ARM                                                       //~vaa0I~
    UCHAR dispallcmd[8]="set";                                     //~vaa0I~
  #else                                                            //~vaa0I~
    UCHAR dispallcmd[8]="env";                                     //~v59FR~
  #endif                                                           //~vaa0I~
#else                                                              //~v59FR~
    UCHAR dispallcmd[8]="set";                                     //~v59FR~
#endif                                                             //~v59FR~
//***********************************                              //~v59CI~
    if (!(pc=Ppcw->UCWparm))                                       //~v59CI~
    {                                                              //~v59EI~
      if (Ppcw->UCWmenuopt==PANMOCMD) //not cmd pannel             //~v59FR~
      {                                                            //~v59FR~
        dcmdsystemcall_intf(Ppcw,dispallcmd);                      //~v59FR~
#ifdef WXE                                                         //~v59EI~
    	usystem2(0,"set"); //use cmd server if setup ok            //~v59ER~
#endif                                                             //~v59EI~
      }                                                            //~v59FR~
      else                                                         //~v59FR~
    	dcmdxenvhelp();                                            //~v59ER~
        return 0;                                                  //~v59EI~
    }                                                              //~v59EI~
    if (*pc=='<')                                                  //~v59CI~
    {                                                              //~v59CI~
    	pc++;                                                      //~v59CI~
        pc+=strspn(pc," ");                                        //~v59CI~
    	if (!dcmdfullpath(Ppcw,fpath,pc))   //consider ::          //~v59KI~
        	return 4;                                              //~v59KI~
        pc=fpath;                                                  //~v59KI~
    	return dcmdxenvfile(0,pc);                                 //~v59CR~
    }                                                              //~v59CI~
    if (uparse2(pc,&podt,&pot,&opdno,UPARSE2TABISSPACE,",="))      //~v59CR~
    	return dcmdxenvhelp();                                     //~v59CI~
    varname=pot;                                                   //~v59CR~
    if (podt->upodelm=='=')                                        //~v59CI~
        if (*(pc+podt->upodelmoffs+1)==' ')                        //~v59CR~
            newval="";                                             //~v59CI~
        else                                                       //~v59CI~
	        newval=varname+strlen(varname)+1;                      //~v59CR~
    else                                                           //~v59CI~
	    newval=0;                                                  //~v59CI~
    rc=dcmdxenvvar(0,varname,newval);                              //~v59CR~
    ufree(podt);                                                   //~v59CI~
    return rc;                                                     //~v59CI~
}//dcmd_xenv                                                       //~v59CI~
//**************************************************************** //~v59CI~
//!set/display env variable                                        //~v59CI~
//*ret :rc                                                         //~v59CI~
//**************************************************************** //~v59CI~
int dcmdxenvvar(int Popt,char *Pvarname,char *Pnewval)             //~v59CR~
{                                                                  //~v59CI~
    UCHAR *oldval,*putstr;                                         //~v59CR~
    int comp,len;                                                  //~v59CR~
//***********************************                              //~v59CI~
	oldval=getenv(Pvarname);                                       //~v59CI~
    if (!Pnewval)	// varname only,display value                  //~v59CI~
    {                                                              //~v59CI~
#ifdef WXE                                                         //~v59EI~
    	dcmdsyscmdnotify(XECMDSVR_GETENV,"GET-ENV",Pvarname);      //~v59ER~
#endif                                                             //~v59EI~
        if (!oldval)                                               //~v59CI~
        	uerrmsg("%s is not defined",0,                         //~v59CI~
					Pvarname);                                     //~v59CR~
        else                                                       //~v59CI~
        if (!*oldval)                                              //~v59CI~
        	uerrmsg("%s is Null",0,                                //~v59CI~
					Pvarname);                                     //~v59CR~
        else                                                       //~v59CI~
        	uerrmsg("%s=%s",0,                                     //~v59CI~
					Pvarname,oldval);                              //~v59CR~
        return 0;                                                  //~v59CI~
    }                                                              //~v59CI~
    if (oldval)                                                    //~v59CI~
    {                                                              //~v59CI~
#ifdef UNX                                                         //~v59CI~
		comp=strcmp(oldval,Pnewval);                               //~v59CI~
#else                                                              //~v59CI~
		comp=stricmp(oldval,Pnewval);                              //~v59CI~
#endif //!UNX                                                      //~v59CI~
	}                                                              //~v59CI~
	else                                                           //~v59CI~
        if (!*Pnewval)                                             //~v59CR~
        {                                                          //~v59CI~
            comp=0;                                                //~v59CI~
            oldval="";  //for errmsg                               //~v59CI~
        }                                                          //~v59CI~
        else                                                       //~v59CI~
	    	comp=2;                                                //~v59CR~
    if (!comp)	//same                                             //~v59CI~
    {                                                              //~v59CI~
      if (!(Popt & DCMDENV_INIT))                                  //~v64yI~
    	uerrmsg("Already %s=%s",0,                                 //~v59CI~
        			Pvarname,oldval);                              //~v59CI~
        return 0;                                                  //~v59CI~
    }                                                              //~v59CI~
//  len=strlen(Pvarname)+1+strlen(Pnewval)+1;                      //~v59GR~
    len=ueditenv(0,Pnewval,0);    //get length after env replaced  //~v59GR~
    len+=(int)strlen(Pvarname)+1+1;                                //~v59KR~
    putstr=malloc((UINT)len);	//do not free until exit           //~v59CI~
    if (!putstr)                                                   //~v59CI~
    	return 4;                                                  //~v59CI~
//  sprintf(putstr,"%s=%s",Pvarname,Pnewval);                      //~v59GR~
    len=sprintf(putstr,"%s=",Pvarname);                            //~v59GR~
    ueditenv(0,Pnewval,putstr+len);    //env replaced              //~v59GR~
#ifdef WXE                                                         //~v59EI~
    dcmdsyscmdnotify(XECMDSVR_PUTENV,"SET-ENV",putstr);            //~v59ER~
#endif                                                             //~v59EI~
    if (putenv(putstr))                                            //~v59CI~
    {                                                              //~v59CI~
    	uerrmsg("%s putenv failed,rc=%d",0,                        //~v59CR~
        		putstr,errno);                                     //~v59CI~
    	return 4;                                                  //~v59CI~
    }                                                              //~v59CI~
    if (!*Pnewval)                                                 //~v59CI~
	    uerrmsg("%s is reset",0,                                   //~v59CI~
    	    	putstr);                                           //~v59CI~
    else                                                           //~v59CI~
    {                                                              //~v59DI~
      if (!(Popt & DCMDENV_INIT))                                  //~v59DR~
	    uerrmsg("set ok %s",0,                                     //~v59CR~
    	    	putstr);                                           //~v59CR~
    }                                                              //~v59DI~
    return 0;                                                      //~v59CI~
}//dcmdxenvvar                                                     //~v59CI~
//**************************************************************** //~v59CI~
//!set/display env variable by file                                //~v59CI~
//*ret :rc                                                         //~v59CI~
//**************************************************************** //~v59CI~
int dcmdxenvfile(int Popt,char *Pfnm)                              //~v59CR~
{                                                                  //~v59CI~
	FILE *fh;                                                      //~v59CI~
    UCHAR *value,*varname,buff[512],*pot;                          //~v59CR~
    PUPODELMTBL podt,podt0;                                        //~v59HR~
    int lineno=0,rc,opdno,len;                                     //~v59CR~
//***********************************                              //~v59CI~
    if (!(fh=fileopen(Pfnm,"r")))                                  //~v59CR~
        return 8;                                                  //~v59CI~
	for (;;)	//until eof/err                                    //~v59CI~
	{                                                              //~v59CI~
    	rc=4;                                                      //~v59CI~
    	if (!fgets(buff,sizeof(buff),fh))//null if error/ eof      //~v59CR~
        {                                                          //~v59CI~
		    rc=0;	//normal eof                                   //~v59CI~
        	break;                                                 //~v59CI~
        }                                                          //~v59CI~
		++lineno;                                                  //~v59CI~
        pot=0;	//malloc req                                       //~v59CI~
        len=(int)strlen(buff);                                     //~v59KR~
        if (len && *(buff+len-1)=='\n')                            //~v59CI~
        {                                                          //~v74BI~
        	*(buff+len-1)=0;                                       //~v59CI~
        	if (len>1 && *(buff+len-2)=='\r')                      //~v74BI~
        		*(buff+len-2)=0;                                   //~v74BI~
        }                                                          //~v74BI~
    	if (uparse2(buff,&podt,&pot,&opdno,UPARSE2TABISSPACE,",="))//~v59CR~
	        break;                                                 //~v59CI~
        podt0=podt;                                                //~v59HI~
        if (!opdno)                                                //~v59CI~
        {                                                          //~v59CI~
            ufree(podt0);                                          //~v59HR~
        	continue;                                              //~v59CI~
        }                                                          //~v59CI~
        varname=pot;                                               //~v59CR~
        if (*varname=='#')	//comment                              //~v59CR~
        {                                                          //~v59CI~
            ufree(podt0);                                          //~v59HR~
        	continue;                                              //~v59CI~
        }                                                          //~v59CI~
        if (podt->upodelm==' ')                                    //~v59HI~
        {                                                          //~v59HI~
        	if (!stricmp(varname,"export")                         //~v59HI~
        	||  !stricmp(varname,"set"))                           //~v59HR~
            {                                                      //~v59HI~
        		varname+=strlen(varname)+1;                        //~v59HR~
                podt++;                                            //~v59HI~
            }                                                      //~v59HI~
        }                                                          //~v59HI~
        if (podt->upodelm=='=')                                    //~v59CI~
        	if (*(buff+podt->upodelmoffs+1)==' ')                  //~v59CR~
            	value="";                                          //~v59CI~
            else                                                   //~v59CI~
	        	value=varname+strlen(varname)+1;                   //~v59CR~
        else                                                       //~v59CI~
        {                                                          //~v59CI~
            ufree(podt0);                                          //~v59HR~
        	break;                                                 //~v59CI~
        }                                                          //~v59CI~
        if (dcmdxenvvar(Popt,varname,value))                       //~v59DR~
        {                                                          //~v59CI~
            ufree(podt0);                                          //~v59HR~
        	break;                                                 //~v59CI~
        }                                                          //~v59CI~
        ufree(podt0);                                              //~v59HR~
    }                                                              //~v59CI~
    fileclose(Pfnm,fh);                                            //~v59CR~
    if (rc)                                                        //~v59CI~
    {	                                                           //~v59CI~
    	uerrmsg("%s lineno %d contains error",0,                   //~v59CI~
        		Pfnm,lineno);                                      //~v59CI~
        return 4;                                                  //~v59CI~
    }                                                              //~v59CI~
    if (!(Popt & DCMDENV_INIT))                                    //~v59CI~
	    uerrmsg("%d lines processed",0,                            //~v59CR~
    	    	lineno);                                           //~v59CR~
    return 0;                                                      //~v59CI~
}//dcmdxenvfile                                                    //~v59CI~
//**************************************************************** //~v59DI~
//!xe init env by env file                                         //~v59DI~
//*ret :rc 4                                                       //~v59DI~
//**************************************************************** //~v59DI~
int dcmdenvinit(char *Postype)                                     //~v59DI~
{                                                                  //~v59DI~
    char wkfname[_MAX_PATH];                                       //~v59DI~
    int rc;                                                        //~v59DI~
//*******************************                                  //~v59DI~
    sprintf(wkfname,"%sxe%s.env",Gworkdir,Postype);                //~v59DI~
    if (ufstat(wkfname,0))  //for os specific not found            //~v59DR~
    {                                                              //~v59DI~
	    sprintf(wkfname,"%sxe.env",Gworkdir);                      //~v59DI~
    	if (ufstat(wkfname,0))	//not found                        //~v59DI~
        	*wkfname=0;                                            //~v59DI~
    }                                                              //~v59DI~
    if (*wkfname)                                                  //~v59DI~
		rc=dcmdxenvfile(DCMDENV_INIT,wkfname);                     //~v59DI~
    else                                                           //~v59DI~
    	rc=0;                                                      //~v59DI~
    return rc;                                                     //~v59DI~
}//dcmdenvinit                                                     //~v59DI~
//**************************************************************** //~v59CI~
//!xenv helpmsg                                                    //~v59CI~
//*ret :rc 4                                                       //~v59CI~
//**************************************************************** //~v59CI~
int dcmdxenvhelp(void)                                             //~v59CI~
{                                                                  //~v59CI~
    uerrmsg("{SET|EXP} [ { varname[=[value]] | < env-file } ]",0); //~v59FR~
	return 4;                                                      //~v59CI~
}                                                                  //~v59CI~
//**************************************************************** //~v70pR~
//!submit helpmsg                                                  //~v70pR~
//*ret :rc 4                                                       //~v70pR~
//**************************************************************** //~v70pR~
int dcmdsubmithelp(void)                                           //~v70pR~
{                                                                  //~v70pR~
    uerrmsg("SUB  [* | ** | filename [*]] [ [**] parameters] [<redirect-in] [>redirect-out]",0);//~v70tR~
	return 4;                                                      //~v70pR~
}                                                                  //~v70pR~
