//*CID://+vbp0R~:                             update#=  401;       //~vbj1R~//~vbp0R~
//*************************************************************
//*xedlcmd6.c                                                      //~v51WR~
//* %:apply command                                                //~v51WR~
//* !:openwith cmd                                                 //~v8@BR~
//* #:submit/rsh                                                   //~v59eI~
//* g:grep                                                         //~v76gI~
//*************************************************************
//vbp0:180922 &(spawn) to msi get errmsg "not found or not executable",add "try !" to execute default app for the extension//~vbp0I~
//vbj1:180305 cpu8 option to "=" cmd                               //~vb7eI~
//vb7e:170108 FTP crash by longname                                //~vb7eI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vavN:140405 (W32UNICODE)vavM is not effective,spawn dose also multibyte process(invalid UD to dbcs translation),back to by alias//~vavNI~
//vavM:140405 (W32UNICODE)xfc/xdc by spawn(because cmd propt translate filename to bestfit)//~vavMI~
//vavH:140403 (W32UNICODE)use alias for xdc/xfc(on cmdprompt filename was translated to BestFit even by _wsystem)//~vavHI~
//vap0:131215 (ARM)warning strict aliasing                         //~vap0I~
//vamH:131119 (BUG)"$" cmd fails by redirect file contension       //~vamHI~
//vamA:131104 % parm of % dlcd; enclose filename if space embedding(when %\*.c etc enclose all)//~vamAI~
//vamy:131103 add dlcmd "$"(async version of "%")                  //~vamyI~
//vagy:120915 rc chk to avoid buff overflow                        //~vagyI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va90:110520 ANDROID porting                                      //~va90I~
//va0G:090725!rename fld by codetype                               //~va0GI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//va03:090605 (BUG)"S" lcmd abend for long path filename(MAXCOLUMN is shorter than _MAX_PATH;define MAXPARMSZ)//~va03I~
//v8@B:080627 3270:submit cmd support by TSO SUBMIT cmd(cmd->3270, add TSO/cmd)//~v8@BI~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v77J:080204 % dlcmd support multiline cmd by ";" (\; is treat as  data)//~v77JI~
//v77a:071214 (BUG)A+i ABEND on util panel                         //~v77aI~
//v76r:070704 (BUG)dlcmd "=" option parm after filename is dropped //~v76rI~
//v76p:070628 compare remote file support                          //~v76pI~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v76h:070621 do xdc for compare dir and dir                       //~v76hI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v75Q:070512 dlcmd "g":keep input on errored line                 //~v75QI~
//v75P:070512 (BUG)dlcmd grep hung when wildcard is used as serach patern//~v75PI~
//v75M:070509 "="(compare) lcmd support. 1st file is line with cmd option on Enter'ed screen.//~v75MI~
//v75J:070509 "g"(grep) dlcmd support                              //~v75JI~
//v71N:061107 (3270)support "#"/% dlcmd for TSO file               //~v71NI~
//v71r:061022 association not supported for remote file;chk also for WXE/XXE mouse operation//~v71rI~
//v662:050863 &(spawn) linecmd support(async version of #)         //~v662I~
//v64v:050708 (LNX)openwith support                                //~v64vI~
//v63b:050429 change dlcmd "%" temp file(cfso/cf) to use pid for contension inter user//~v63bI~
//v59e:041107 add "#" lcmd:submit for localfile/rsh for remotefile //~v59eI~
//v59c:041107 % lcmd:remote support(use rsh)                       //~v59cI~
//v58K:041011 (BUG)"%" cmd parse delm tbl to call func_submit()    //~v58KI~
//v58h:040905 (BUG)rename fld by %cmd prevent long filename display//~v58hI~
//v588:040823 % dlcmd:enclose filename if blank embedding when no % used as parm//~v588I~
//v583:040822 keep csr on the line for dlcmd ! and %               //~v583I~
//v57F:040612 (BUG)don't enclose filename  by quote because cmd fail when % is concatinated like as "%\*"//~v57FI~
//v56e:040404 xp open dir by explorler,so allow dir for openwith   //~v56eI~
//v55V:040321 (WIN)filename list ! lcmd(openwith) support          //~v55VI~
//v55v:040229 (W32)v55u for W32 console xe(dlcmd "!":openwith)     //~v55vI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
#ifdef W32                                                         //~v56eI~
	#include <io.h>                                                //~v56eI~
#endif                                                             //~v56eI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <uque.h>
#include <ustring.h>
#include <ufile.h>
#include <ufile2.h>                                                //~v71NI~
#include <ufile3.h>                                                //~v71NI~
#include <uparse.h>                                                //~v10pI~
#include <ufemsg.h>                                                //~v51WI~
#include <udos.h>                                                  //~v51WI~
#include <uftp.h>                                                  //~v59cI~
#include <u3270.h>                                                 //~v76pI~
#ifdef UNX                                                         //~v51WI~
	#include <ufile2l.h>                                           //~v51WI~
#endif                                                             //~v51WI~
#include <uproc.h>                                                 //~v64vI~
#ifdef W32                                                         //~v55vI~
	#include <uwinsub.h>                                           //~v56eI~
#endif                                                             //~v55vI~
#include <ufilew.h>                                                //~vavNI~

#include "xe.h"
#include "xescr.h"                                                 //~v51WI~
#include "xefile.h"
#include "xefile2.h"                                               //~v583I~
#include "xepan.h"
#include "xepan2.h"                                                //~v76gI~
#include "xepan22.h"                                               //~v55VM~
#include "xedir.h"
#include "xedir2.h"                                                //~v51WI~
#include "xedlcmd.h"                                            //~v05oM~
#include "xedlcmd2.h"                                              //~v51WI~
#include "xedlcmd3.h"                                              //~v71NI~
#include "xedlcmd6.h"                                              //~v51WR~
#include "xefunc.h"                                                //~v51WI~
#include "xefunc2.h"                                               //~v75JI~
#include "xesub.h"                                                 //~v51WI~
#include "xeerr.h"                                                 //~v51WI~
#include "xedcmd.h"                                                //~v75MI~
#include "xedcmd2.h"                                               //~v662I~
#include "xedcmd3.h"                                               //~v59cI~
#include "xedcmd4.h"                                               //~v63bI~
#include "xeftp.h"                                                 //~v71NI~
#include "xegbl.h"                                                 //~v76gI~
#ifdef WXE                                                         //~v76gR~
	#include "wxexei.h"                                            //~v76gI~
#endif                                                             //~v76gI~
#ifdef XXE                                                         //~v76gI~
	#include "xxexei.h"                                            //~v76gI~
#endif                                                             //~v76gI~
#include "xetso.h"                                                 //~v8@sI~
#include "xeopt.h"                                                 //~vbj1R~
//*******************************************************
#define CMDFNM	"cf"                                               //~v51WR~
#define SOFNM	"cfso"                                             //~v51WR~
#ifdef W32                                                         //~vamyI~
	#define ASYNC_CMD "start"                                      //~vamyI~
#endif                                                             //~vamyI~
#ifdef UNX                                                         //~vamyI~
	#define ASYNC_CMD "&"                                          //~vamyI~
#endif                                                             //~vamyI~
//*******************************************************          //~v51WI~
//#ifdef UNX                                                       //~v63bR~
//        static UCHAR Scmdfnm[]=WORKDIRPATHID CMDFNM;             //~v63bR~
//#else                                                            //~v63bR~
//    #ifdef OS2                                                   //~v63bR~
//        static UCHAR Scmdfnm[]=WORKDIRPATHID CMDFNM ".cmd";      //~v63bR~
//    #else                                                        //~v63bR~
//        static UCHAR Scmdfnm[]=WORKDIRPATHID CMDFNM ".bat";      //~v63bR~
//    #endif                                                       //~v63bR~
//#endif                                                           //~v63bR~
    static UCHAR Scmdfnm[]=DCMDSUBMITCMDFNM;                       //~v63bI~
//do not set inter-space after ">" befause parse required          //~v51WR~
//static UCHAR Sredirectparm[]=">" WORKDIRPATHID SOFNM;            //~v63bR~
static UCHAR Sredirectparm[]=">" DCMDDLCMDCFSO;                    //~v63bR~
static UCHAR Scmdfullpath[_MAX_PATH]="";                           //~v55VR~
#ifdef FTPSUPP                                                     //~v71NI~
	static UCHAR Sappcmdtmpdir[_MAX_PATH]="";                      //~v71NR~
	static PUDLCMD Splcac1;                                        //~v71NI~
#endif                                                             //~v71NI~
static PUDLCMD Splcac;                                             //~v51WI~
static int Sasynccmdseqno;  //suffix for redirect file of $ cmd    //~vamHI~
static int Scompcmdcpu8=0;                                         //~vbj1R~
//*******************************************************       //~v04bI~
//int dlcmdappcmdedit(char *Ppatern,char *Pfnm,char *Poutstr);       //~v51WI~//~vamyR~
int dlcmdappcmdedit(PUDLCMD Pplc,char *Ppatern,char *Pfnm,char *Poutstr);//~vamyI~
int dlcmdgetcmdstr(PUCLIENTWE Ppcw,PUDLCMD Pplc,char *Pcmdstr);    //~v51WI~
int dlcmdsubrshcmdedit(char *Pfnm,char *Pparm,char *Poutstr);      //~v59eR~
#ifdef FTPSUPP                                                     //~v71NI~
int dlcmdgetcmdstrtso(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDLCMD Pplc,char *Pcmdstr);//~v71NI~
int dlcmdaclisttso(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDLCMD Pplc,int Precno);//~v71NI~
#endif                                                             //~v71NI~
int dlcmdgetcmdparm(PUCLIENTWE Ppcw,PULINEH Pplh,char *Pparmstr,int *Ppparmlen,char *Pcmdopt,char *Pfnm);//~v75MI~
int funcsenddir(int Popt,PUCLIENTWE Ppcw);                         //~v76gI~
int dlcmdsendsub(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh);           //~v76gI~
#ifdef FTPSUPP                                                     //~v8@BI~
int dlcmdtsosub(int Popt,PUCLIENTWE Ppcw,PUFTPHOST Ppuftph,char *Pcmdlistfnm,char *Pjclfnm);//~v8@BI~
#endif                                                             //~v8@BI~
//**************************************************************** //~v51WI~
//!dlcmdaclist                                                     //~v51WI~
// setup xprint indirect file list                                 //~v51WI~
//*parm1:pcw                                                       //~v51WI~
//*parm2:plc                                                       //~v51WI~
//*parm3:record seq no(1 start,0 for eof)                          //~v51WI~
//*ret  :0:ok,4 io err                                             //~v51WI~
//**************************************************************** //~v51WI~
int dlcmdaclist(PUCLIENTWE Ppcw,PUDLCMD Pplc,int Precno)           //~v51WI~
{                                                                  //~v51WI~
    UCHAR  cmdstr[_MAX_PATH+MAXCOLUMN];                            //~v51WI~
#ifdef W32                                                         //~v51WI~
    UCHAR  *pc;                                                    //~v51WI~
#endif                                                             //~v51WI~
    int rc;                                                        //~v51WI~
	static FILE *Sfh=0;                                            //~v51WR~
#ifdef FTPSUPP                                                     //~v71NI~
    PUFILEH pfh;                                                   //~v71NI~
#endif                                                             //~v71NI~
//*******************                                              //~v51WI~
//#ifdef FTPSUPP                                                   //~v8@BR~
//    pfh=UGETPFHFROMPCW(Ppcw);                                    //~v8@BR~
//    if (FILEISTSO(pfh))                                          //~v8@BR~
//        return dlcmdaclisttso(Ppcw,pfh,Pplc,Precno);             //~v8@BR~
//#endif                                                           //~v8@BR~
	if (!*Scmdfullpath)                                            //~v51WR~
    {                                                              //~v51WI~
#ifdef W32                                                         //~v51WI~
      	if (udosiswinnt())                                         //~v51WI~
        {	                                                       //~v51WI~
        	if (pc=strchr(Scmdfnm,'.'),pc)                         //~v51WI~
	        	strcpy(pc+1,"cmd");                                //~v51WI~
        }                                                          //~v51WI~
#endif                                                             //~v51WI~
		if (!filefullpath(Scmdfullpath,Scmdfnm,_MAX_PATH))         //~v51WI~
        	return 4;   //full path err                            //~v51WI~
    }                                                              //~v51WI~
#ifdef FTPSUPP                                                     //~v8@BI~
    pfh=UGETPFHFROMPCW(Ppcw);                                      //~v8@BI~
    if (FILEISTSO(pfh))                                            //~v8@BI~
        return dlcmdaclisttso(Ppcw,pfh,Pplc,Precno);               //~v8@BI~
#endif                                                             //~v8@BI~
	if (!Precno)	//last call                                    //~v51WI~
    {                                                              //~v51WI~
    	if (Sfh)                                                   //~v51WI~
        {                                                          //~v51WI~
		    fileclose(Scmdfullpath,Sfh);                           //~v51WI~
#ifdef UNX                                                         //~v51WI~
	        if (uattrxon(Scmdfullpath))    //user x bit on         //~v51WI~
    	        return 4;                                          //~v51WI~
#endif //UNX                                                       //~v51WI~
        }                                                          //~v51WI~
		Sfh=0;                                                     //~v51WI~
        Splcac=Pplc;	//xprint kick(last '%' lcmd plc)           //~v51WR~
        return 0;                                                  //~v51WI~
	}                                                              //~v51WI~
	if (Precno==1)	//first call                                   //~v51WI~
    {                                                              //~v63bI~
    	if (!(Sfh=fileopen(Scmdfullpath,"w")))                     //~v51WI~
        	return 4;   //open err                                 //~v51WI~
    	Gdcmdtempf|=GDCMDTEMPF_SUB; //del at term                  //~v63bI~
    }                                                              //~v63bI~
	if (dlcmdgetcmdstr(Ppcw,Pplc,cmdstr))                          //~v51WR~
    	return 4;                                                  //~v51WI~
	strcat(cmdstr,"\n");                                           //~v51WI~
  	rc=fputs(cmdstr,Sfh);                                          //~v51WI~
#ifdef DOS                                                         //~v51WI~
    #ifdef DPMI					//DPMI version                     //~v51WI~
    if (rc==-1)                                                    //~v51WI~
    #else                       //not DPMI                         //~v51WI~
    if (rc)                                                        //~v51WI~
    #endif                      //DPMI or not                      //~v51WI~
#else                                                              //~v51WI~
    if (rc==-1)                                                    //~v51WI~
#endif                                                             //~v51WI~
    {                                                              //~v51WI~
    	ufileapierr("fputs",Scmdfullpath,rc);                      //~v51WR~
        return 4;                                                  //~v51WI~
	}                                                              //~v51WI~
    return 0;                                                      //~v51WI~
}//dlcmdaclist                                                     //~v51WI~
#ifdef FTPSUPP                                                     //~v71NI~
//**************************************************************** //~v71NI~
//!dlcmdaclisttso                                                  //~v71NI~
// setup %/# cmd indirect file list for remote is TSO case         //~v71NI~
//*parm1:pcw                                                       //~v71NI~
//*parm2:plc                                                       //~v71NI~
//*parm3:record seq no(1 start,0 for eof)                          //~v71NI~
//*ret  :0:ok,4 io err                                             //~v71NI~
//**************************************************************** //~v71NI~
int dlcmdaclisttso(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDLCMD Pplc,int Precno)//~v71NI~
{                                                                  //~v71NI~
    UCHAR  cmdstr[_MAX_PATH+MAXCOLUMN];                            //~v71NI~
    UCHAR  fullpathname[_MAX_PATH];                                //~v71NI~
    int rc;                                                        //~v71NI~
	static FILE *Sfh=0;                                            //~v71NI~
    PULINEH plh;                                                   //~v71NI~
    PUDIRLH pdh;                                                   //~v71NI~
    PUFTPHOST puftph;                                              //~v8@BI~
//*******************                                              //~v71NI~
	if (!Precno)	//last call                                    //~v71NI~
    {                                                              //~v71NI~
    	if (Sfh)                                                   //~v71NI~
		    fileclose(Scmdfullpath,Sfh);                           //~v71NI~
		Sfh=0;                                                     //~v71NI~
        Splcac=Pplc;	//xprint kick(last '%' lcmd plc)           //~v71NI~
        return 0;                                                  //~v71NI~
	}                                                              //~v71NI~
	if (Precno==1)	//first call                                   //~v71NI~
    {                                                              //~v71NI~
    	if (Pplc->UDLCcmd==DLCMD_APPCMD)                           //~v71NI~
        {                                                          //~v71NI~
        	if (!*Sappcmdtmpdir)                                   //~v71NR~
	  			if (rc=dlcxpgettmpdir(Sappcmdtmpdir),rc)           //~v71NR~
  					return rc;                                     //~v71NI~
			if (!filefullpath(Scmdfullpath,Scmdfnm,_MAX_PATH))     //~v71NR~
        		return 4;   //full path err                        //~v71NI~
	    	if (!(Sfh=fileopen(Scmdfullpath,"w")))                 //~v71NR~
    	    	return 4;   //open err                             //~v71NI~
    		Gdcmdtempf|=GDCMDTEMPF_SUB; //del at term              //~v71NI~
        }                                                          //~v71NI~
    	if (Pplc->UDLCcmd==DLCMD_SUBRSH)                           //~v71NI~
        {                                                          //~v71NI~
            puftph=Ppfh->UFHpuftph;                                //~v8@BI~
          if (UFTPHISTSOSUBM(puftph))   //use TSO submit           //~v8@BI~
            uremovenomsg(Scmdfullpath); //delete                   //~v8@BI~
          else                                                     //~v8@BI~
          {                                                        //~v8@BI~
    		plh=Pplc->UDLCplh;                                     //~v71NI~
    		pdh=UGETPDH(plh);                                      //~v71NI~
    		dlcgetfullname(pdh,fullpathname);                      //~v71NI~
//			xeftpgetwdfname(Ppfh->UFHpuftph,fullpathname,Scmdfullpath);//~v71NR~//~vb7eR~
  			if (xeftpgetwdfname(Ppfh->UFHpuftph,fullpathname,Scmdfullpath,sizeof(Scmdfullpath))<0)	//longname//~vb7eR~
            	return 4;                                          //~vb7eI~
            uremovenomsg(Scmdfullpath);                            //~v71NR~
          }                                                        //~v8@BI~
        }                                                          //~v71NI~
        Splcac1=Pplc;	//1st to chk same cmd                      //~v71NR~
    }                                                              //~v71NI~
    else	//not 1st                                              //~v71NI~
    if (Pplc->UDLCcmd!=Splcac1->UDLCcmd)                           //~v71NR~
    {                                                              //~v71NM~
    	uerrmsg("mixed command is not supported for TSO file(%c and %c)",0,//~v71NR~
    			Pplc->UDLCcmd,Splcac1->UDLCcmd);                   //~v71NR~
        return 4;                                                  //~v71NM~
    }                                                              //~v71NM~
	if (dlcmdgetcmdstrtso(Ppcw,Ppfh,Pplc,cmdstr))                  //~v71NR~
    	return 4;                                                  //~v71NI~
    if (Pplc->UDLCcmd==DLCMD_APPCMD)                               //~v71NI~
    {                                                              //~v71NI~
        strcat(cmdstr,"\n");                                       //~v71NI~
        rc=fputs(cmdstr,Sfh);                                      //~v71NI~
        if (rc==-1)                                                //~v71NI~
        {                                                          //~v71NI~
            ufileapierr("fputs",Scmdfullpath,rc);                  //~v71NR~
            return 4;                                              //~v71NI~
        }                                                          //~v71NI~
    }                                                              //~v71NI~
    return 0;                                                      //~v71NI~
}//dlcmdaclisttso                                                  //~v71NI~
#endif                                                             //~v71NI~
//**************************************************************** //~v47PI~
// dlcmdgetcmdstr                                                  //~v58hR~
// retrieve cmd string for #,%,& lcmd                              //~v662R~
//*rc   :0                                                         //~v47PI~
//**************************************************************** //~v47PI~
int dlcmdgetcmdstr(PUCLIENTWE Ppcw,PUDLCMD Pplc,char *Pcmdstr)     //~v51WR~
{                                                                  //~v47QI~
    PULINEH plh;                                                   //~v47PI~
#ifdef FTPSUPP                                                     //~v59cI~
    PUFILEH pfh;                                                   //~v59cI~
#endif                                                             //~v59cI~
    PUDIRLH pdh;                                                   //~v47PI~
    UCHAR  parmcmd[MAXCOLUMN];                                     //~v51WR~
    UCHAR  fullpathname[_MAX_PATH];                                //~v51WI~
    int rc;                                                        //~v51WI~
//*******************                                              //~v47PI~
    plh=Pplc->UDLCplh;                                             //~v51WM~
    pdh=UGETPDH(plh);                                              //~v51WM~
    if (dlcgetfullname(pdh,fullpathname))                          //~v51WI~
        return 4;                                                  //~v51WI~
#ifdef FTPSUPP                                                     //~v59cI~
    pfh=UGETPFH(plh);                                              //~v59cI~
  	if (FILEISREMOTE(pfh))                                         //~v59cI~
    	strcpy(fullpathname,fullpathname+((PUFTPHOST)(pfh->UFHpuftph))->UFTPHhostnmlen+1);//cut hostid//~v59cR~
#endif                                                             //~v59cI~
//  if (dirgetflddata(Ppcw,plh,PANL310RENAME,parmcmd)<=0)  //fld len//~v51WM~//~va00R~
    if (BYUTF8_dirgetflddata(Ppcw,plh,PANL310RENAME,parmcmd)<=0)  //fld len//~va00I~
//      strcpy(Pcmdstr,fullpathname);	//no parm,exec the file    //~v59eR~
		dlcmdsubrshcmdedit(fullpathname,0,Pcmdstr);	//replace % to filename//~v59eR~
    else                                                           //~v51WI~
      if (Pplc->UDLCcmd==DLCMD_SPAWN)	//"&" cmd                  //~v662I~
		dlcmdsubrshcmdedit(fullpathname,parmcmd,Pcmdstr);   //replace % to filename//~v662I~
      else                                                         //~v662I~
      if (Pplc->UDLCcmd==DLCMD_SUBRSH)	//"#" cmd                  //~v59eR~
		dlcmdsubrshcmdedit(fullpathname,parmcmd,Pcmdstr);   //replace % to filename//~v59eR~
      else                                                         //~v59eI~
      {                                                            //~v59eI~
//  	if (dlcmdappcmdedit(parmcmd,fullpathname,Pcmdstr))	//replace % to filename//~v51WR~//~vamyR~
    	if (dlcmdappcmdedit(Pplc,parmcmd,fullpathname,Pcmdstr))	//replace % to filename//~vamyI~
        	return 4;   //internal logic err                       //~v51WR~
      }                                                            //~v59eI~
#ifdef UNX                                                         //~v51WI~
    rc=strcmp(Scmdfullpath,fullpathname);                          //~v51WR~
#else                                                              //~v51WI~
    rc=stricmp(Scmdfullpath,fullpathname);                         //~v51WR~
#endif                                                             //~v51WI~
	if (!rc)	//same as temp cmd file                            //~v51WI~
    {                                                              //~v51WI~
    	uerrmsg("%s is same as work cmd file",0,                   //~v51WI~
        		Scmdfullpath);                                     //~v51WR~
        return 4;                                                  //~v51WI~
    }                                                              //~v51WI~
  	UCBITON(pdh->UDHflag,UDHFAPPCMDSTR); //rename fld is by % lcmd //~v58hI~
	UCBITOFF(pdh->UDHflag,UDHFLCMDIN2|UDHFDDSETUP);//protect rename fld//~v58hI~
//  if (dirsavename(plh,parmcmd))                                  //~v58hR~//~va00R~
//  if (BYUTF8_dirsavename(plh,parmcmd))                           //~va0GR~
    if (dirsavename(plh,parmcmd))                                  //~va0GI~
        return 4;                                                  //~v58hI~
	return 0;                                                      //~v51WR~
}//dlcmdgetcmdstr                                                  //~v51WR~
#ifdef FTPSUPP                                                     //~v71NI~
//**************************************************************** //~v71NI~
// dlcmdgetcmdstrto                                                //~v71NI~
// retrieve cmd string for #,% lcmd  for TSO file                  //~v71NI~
//*rc   :0                                                         //~v71NI~
//**************************************************************** //~v71NI~
int dlcmdgetcmdstrtso(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDLCMD Pplc,char *Pcmdstr)//~v71NI~
{                                                                  //~v71NI~
    PULINEH plh;                                                   //~v71NI~
    PUDIRLH pdh;                                                   //~v71NI~
    UCHAR  parmcmd[MAXCOLUMN];                                     //~v71NI~
    UCHAR  fullpathname[_MAX_PATH];                                //~v71NI~
    UCHAR  localfnm[_MAX_PATH];                                    //~v71NI~
    PUFTPHOST puftph;                                              //~v8@BR~
    int rc;                                                        //~v71NI~
//*******************                                              //~v71NI~
    plh=Pplc->UDLCplh;                                             //~v71NI~
    pdh=UGETPDH(plh);                                              //~v71NI~
    puftph=Ppfh->UFHpuftph;                                        //~v8@BI~
    if (!(pdh->UDHattr & FILE_PDSMEMB))                            //~v71NI~
    {                                                              //~v71NM~
    	uerrmsg("command %c is supported only for PDS member",0,   //~v71NR~
	        	Pplc->UDLCcmd);                                    //~v71NM~
    	return 4;                                                  //~v71NM~
    }                                                              //~v71NM~
    if (dlcgetfullname(pdh,fullpathname))                          //~v71NI~
        return 4;                                                  //~v71NI~
    if (Pplc->UDLCcmd==DLCMD_SPAWN)	//"&" cmd                      //~v71NI~
    {                                                              //~v71NI~
      	uerrmsg("%c cmd is not supported for TSO file",0,          //~v71NI~
        	Pplc->UDLCcmd);                                        //~v71NI~
		return 4;                                                  //~v71NI~
    }                                                              //~v71NI~
    if (Pplc->UDLCcmd==DLCMD_SUBRSH)	//"#" cmd                  //~v71NI~
    {                                                              //~v8@BI~
      if (UFTPHISTSOSUBM(puftph))   //use TSO submit               //~v8@BI~
        rc=dlcmdtsosub(0,Ppcw,puftph,Scmdfullpath,fullpathname);	//write a line of submit dsn//~v8@BI~
      else                                                         //~v8@BI~
        rc=uxcopy(fullpathname,Scmdfullpath,DCPY_APPEND,FILE_NORMAL); //append to now downloaded//~v71NR~
        if (rc)                                                    //~v8@BI~
        	return 4;                                              //~v8@BI~
    }                                                              //~v8@BI~
    else                              //%                          //~v71NI~
    {                                                              //~v71NI~
	    dirgetflddata(Ppcw,plh,PANL310RENAME,parmcmd);             //~v71NI~
  		sprintf(localfnm,"%s%c%s",Sappcmdtmpdir,DIR_SEPC,pdh->UDHname);//~v71NR~
//    	if (xeftpgetremotecopy(0,fullpathname,Ppfh->UFHpuftph,localfnm))//copy into parmdir//~v8@sR~
//    	if (xeftpgetremotecopy(0,fullpathname,Ppfh->UFHpuftph,localfnm,Ppfh))//copy into parmdir//~v8@sR~//~vb7eR~
      	if (xeftpgetremotecopy(0,fullpathname,Ppfh->UFHpuftph,localfnm,sizeof(localfnm),Ppfh))//copy into parmdir//~vb7eI~
    		return 4;                                              //~v71NI~
//  	if (dlcmdappcmdedit(parmcmd,localfnm,Pcmdstr))	//replace % to filename//~v71NR~//~vamyR~
    	if (dlcmdappcmdedit(Pplc,parmcmd,localfnm,Pcmdstr))	//replace % to filename//~vamyI~
        	return 4;   //internal logic err                       //~v71NI~
        UCBITON(pdh->UDHflag,UDHFAPPCMDSTR); //rename fld is by % lcmd//~v71NR~
        UCBITOFF(pdh->UDHflag,UDHFLCMDIN2|UDHFDDSETUP);//protect rename fld//~v71NR~
        if (dirsavename(plh,parmcmd))                              //~v71NR~
            return 4;                                              //~v71NR~
    }                                                              //~v71NM~
	return 0;                                                      //~v71NI~
}//dlcmdgetcmdstrtso                                               //~v71NI~
#endif                                                             //~v71NI~
//**************************************************************** //~v51WI~
//* edit cmd string edit for % dlcmd                               //~v51WI~
//* parm1 :pcw                                                     //~v51WI~
//* retrn :-1:err, 1:execute, 0:cmd set on line only               //~v51WI~
//**************************************************************** //~v51WI~
//int dlcmdappcmdedit(char *Ppatern,char *Pfnm,char *Poutstr)        //~v51WI~//~vamyR~
int dlcmdappcmdedit(PUDLCMD Pplc,char *Ppatern,char *Pfnm,char *Poutstr)//~vamyI~
{                                                                  //~v51WI~
    int repsw,fnmlen,len;                                          //~v51WR~
    int spaceembeddingsw;                                          //~v588I~
    char  *pci,*pcio,*pco;                                         //~v51WR~
    char  *pci2;                                                   //~v77JI~
	char fnmwk[_MAX_PATH+4],*pc2;                                  //~vamAI~
//********************                                             //~v51WI~
                                                                   //~v51WI~
	fnmlen=(int)strlen(Pfnm);                                      //~v51WI~
    pco=Poutstr;                                                   //~v51WI~
#ifdef W32                                                         //~vamyM~
    if (Pplc->UDLCcmd==DLCMD_APPASYNC)	//"$" cmd                  //~vamyI~
    {                                                              //~vamyI~
    	strcpy(pco,ASYNC_CMD);                                     //~vamyI~
        pco+=sizeof(ASYNC_CMD)-1;                                  //~vamyI~
        *pco++=' ';                                                //~vamyI~
    }                                                              //~vamyI~
#endif                                                             //~vamyM~
//    if (*Ppatern=='>')  //redirect parm only,exec the file       //~v57FR~
//    {                                                            //~v57FR~
//        *pco++='\"';                                             //~v57FR~
//        memcpy(pco,Pfnm,fnmlen);                                 //~v57FR~
//        pco+=fnmlen;                                             //~v57FR~
//        *pco++='\"';                                             //~v57FR~
//        strcpy(pco,Ppatern);                                     //~v57FR~
//        return 0;                                                //~v57FR~
//    }                                                            //~v57FR~
//  for (pci=Ppatern,repsw=0,pco=Poutstr;;)                        //~v51WR~//~vamyR~
    for (pci=Ppatern,repsw=0;;)                                    //~vamyI~
    {                                                              //~v51WI~
    	pcio=pci;                                                  //~v51WI~
    	pci=strchr(pci,'%');                                       //~v51WR~
    	pci2=strchr(pcio,';');                                     //~v77JR~
        if (pci2 && (!pci||pci2<pci) && pci2>Ppatern)              //~v77JR~
        {                                                          //~v77JI~
        	if (*(pci2-1)=='\\')	// ";" is not data("\;")       //~v77JI~
            {                                                      //~v77JI~
//              len=(int)((ULONG)pci2-(ULONG)pcio-1);              //~v77JI~//~vafkR~
                len=(int)((ULPTR)pci2-(ULPTR)pcio-1);              //~vafkI~
                memcpy(pco,pcio,(UINT)len);                        //~v77JI~
                pco+=len;                                          //~v77JI~
                *pco++=';';                                        //~v77JI~
            }                                                      //~v77JI~
            else                                                   //~v77JI~
            {                                                      //~v77JI~
//              len=(int)((ULONG)pci2-(ULONG)pcio);                //~v77JI~//~vafkR~
                len=(int)((ULPTR)pci2-(ULPTR)pcio);                //~vafkI~
                memcpy(pco,pcio,(UINT)len);                        //~v77JI~
                pco+=len;                                          //~v77JI~
                *pco++='\n';                                       //~v77JI~
            }                                                      //~v77JI~
            pci=pci2+1;                                            //~v77JI~
            continue;                                              //~v77JI~
        }                                                          //~v77JI~
        if (!pci)                                                  //~v51WI~
        {                                                          //~v51WI~
           strcpy(pco,pcio);                                       //~v51WR~
           pco+=strlen(pcio);                                      //~v51WI~
        	break;                                                 //~v51WI~
        }                                                          //~v51WI~
//      len=(int)((ULONG)pci-(ULONG)pcio);                         //~v58hR~//~vafkR~
        len=(int)((ULPTR)pci-(ULPTR)pcio);                         //~vafkI~
        memcpy(pco,pcio,(UINT)len);                                //~v51WI~
        pco+=len;                                                  //~v51WI~
        if (pci!=Ppatern && *(pci-1)=='\\')	// \% is for char '%' as cmd parm//~v51WR~
        {	                                                       //~v51WI~
        	*(pco-1)='%';                                          //~v51WR~
            pci++;                                                 //~v51WI~
            continue;                                              //~v51WI~
        }                                                          //~v51WI~
        repsw=1;                                                   //~v51WI~
		strcpy(fnmwk,Pfnm);                                        //~vamAI~
//  	spaceembeddingsw=dlcgetfullnameenclose(0/*rc=1 when enclosed*/,fnmwk);	//" " or "(" or ")"//~vamAR~//~vavHR~
    	spaceembeddingsw=dlcgetfullnameenclose(0/*opt*/,0/*rc=1 when enclosed*/,fnmwk);	//" " or "(" or ")"//~vavHI~
      if (spaceembeddingsw)                                        //~vamAI~
      {                                                            //~vamAI~
	    pci++;                                                     //~vamAI~
		memcpy(pco,fnmwk,(UINT)(fnmlen+2));                        //~vamAI~
        pco+=fnmlen+2;                                             //~vamAI~
      	if (*pci && *pci!=' ')	// "%\" pattern                    //~vamAR~
        {                                                          //~vamAI~
        	pc2=strchr(pci,' ');                                   //~vamAI~
            if (pc2)                                               //~vamAI~
            	len=PTRDIFF(pc2,pci);                              //~vamAI~
            else                                                   //~vamAI~
//          	len=strlen(pci);                                   //~vamAI~//~vb2DR~
            	len=(int)strlen(pci);                              //~vb2DI~
			memcpy(pco-1,pci,(UINT)len);                           //~vamAI~
            pco+=len-1;                                            //~vamAR~
            *pco++='"';                                            //~vamAI~
            pci+=len;                                              //~vamAI~
        }                                                          //~vamAI~
      }                                                            //~vamAI~
      else                                                         //~vamAI~
      {                                                            //~vamAI~
//      *pco++='\"';                                               //~v57FR~
        memcpy(pco,Pfnm,(UINT)fnmlen);                             //~v58hR~
        pco+=fnmlen;                                               //~v51WI~
//      *pco++='\"';                                               //~v57FR~
        pci++;                                                     //~v51WI~
      }                                                            //~vamAI~
    }                                                              //~v51WI~
    if (!repsw)                                                    //~v51WI~
    {                                                              //~v51WI~
//      spaceembeddingsw=memchr(Pfnm,' ',(UINT)fnmlen)!=0;         //~v588R~//~vamAR~
		strcpy(fnmwk,Pfnm);                                        //~vamAI~
//  	spaceembeddingsw=dlcgetfullnameenclose(0/*rc=1 when enclosed*/,fnmwk);	//" " or "(" or ")"//~vamAR~//~vavHR~
    	spaceembeddingsw=dlcgetfullnameenclose(0/*opt*/,0/*rc=1 when enclosed*/,fnmwk);	//" " or "(" or ")"//~vavHI~
    	*pco++=' ';                                                //~v51WI~
//      *pco++='\"';                                               //~v57FR~
		if (spaceembeddingsw)                                      //~v588R~
			*pco++='\"';                                           //~v588I~
        memcpy(pco,Pfnm,(UINT)fnmlen);                             //~v58hR~
        pco+=fnmlen;                                               //~v51WI~
//      *pco++='\"';                                               //~v57FR~
		if (spaceembeddingsw)                                      //~v588R~
			*pco++='\"';                                           //~v588I~
    }                                                              //~v51WI~
#ifdef UNX                                                         //~vamyI~
    if (Pplc->UDLCcmd==DLCMD_APPASYNC)	//"$" cmd                  //~vamyI~
    {                                                              //~vamyI~
    	*pco++=' ';                                                //~vamyR~
    	strcpy(pco,ASYNC_CMD);      //append "&"                   //~vamyR~
    	pco+=sizeof(ASYNC_CMD)-1;                                  //~vamyR~
    }                                                              //~vamyI~
#endif                                                             //~vamyI~
    *pco++=0;	//null term                                        //~v51WI~
    return 0;                                                      //~v51WI~
}//dlcmdappcmdedit                                                 //~v51WI~
//**************************************************************** //~v59eI~
//* edit cmd string edit for # dlcmd                               //~v59eI~
//* parm1 :pcw                                                     //~v59eI~
//* retrn :0;                                                      //~v59eR~
//**************************************************************** //~v59eI~
int dlcmdsubrshcmdedit(char *Pfnm,char *Pparm,char *Poutstr)       //~v59eR~
{                                                                  //~v59eI~
    int fnmlen,spaceembeddingsw;                                   //~v59eR~
    char  *pco;                                                    //~v59eR~
//********************                                             //~v59eI~
	fnmlen=(int)strlen(Pfnm);                                      //~v59eI~
    pco=Poutstr;                                                   //~v59eI~
    spaceembeddingsw=memchr(Pfnm,' ',(UINT)fnmlen)!=0;             //~v59eI~
	if (spaceembeddingsw)                                          //~v59eI~
		*pco++='\"';                                               //~v59eI~
    memcpy(pco,Pfnm,(UINT)fnmlen);                                 //~v59eI~
    pco+=fnmlen;                                                   //~v59eI~
	if (spaceembeddingsw)                                          //~v59eI~
		*pco++='\"';                                               //~v59eI~
    *pco++=' ';                                                    //~v59eR~
    if (Pparm)                                                     //~v59eI~
	    strcpy(pco,Pparm);                                         //~v59eR~
    else                                                           //~v59eI~
	    *pco++=0;                                                  //~v59eI~
    return 0;                                                      //~v59eI~
}//dlcmdsubrshcmdedit                                              //~v59eI~
//**************************************************************** //~v51WI~
// dlcmdappcmd                                                     //~v51WI~
// submit cmd work file                                            //~v51WI~
//*ret  :rc                                                        //~v51WI~
//**************************************************************** //~v51WI~
int dlcmdappcmd(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)    //~v51WI~
{                                                                  //~v51WI~
    PULINEH plh;                                                   //~v583I~
#ifdef FTPSUPP                                                     //~v59cI~
    PUFILEH pfh;                                                   //~v59cI~
    PUFTPHOST puftph;                                              //~v8@BI~
#endif                                                             //~v59cI~
//  UCHAR wkpot[MAXCOLUMN+1];                                      //~v71NM~//~va03R~
//  UCHAR wkpodt[MAXCOLUMN+1];                                     //~v71NM~//~va03R~
    UCHAR wkpot[_MAX_PATH+MAXCOLUMN+32+1];                         //~va03I~
    UCHAR wkpodt[_MAX_PATH+MAXCOLUMN+32+1];                        //~va03I~
	UCHAR *wkppot;                                                 //~v71NM~
	int wordno;                                                    //~v71NM~
    PUPODELMTBL podt;                                              //~v71NM~
    UCHAR  cmdstr[_MAX_PATH+MAXCOLUMN+32];                         //~v51WI~
//  UCHAR  cmdstrpo[_MAX_PATH+MAXCOLUMN+32];                       //~v71NR~
//  UPODELMTBL delmt[2];                                           //~v71NR~
    int rc;                                                        //~v51WI~
    void *pvoid;                                                   //~vap0I~
//*******************                                              //~v51WI~
    if (Pplc!=Splcac)   //not last print entry                     //~v51WR~
        return 0;                                                  //~v51WI~
    plh=Pplc->UDLCplh;                                             //~v583I~
    Gdcmdtempf|=GDCMDTEMPF_DLCMDCF; //del at term                  //~v63bR~
#ifdef FTPSUPP                                                     //~v59cM~
    pfh=UGETPFH(plh);                                              //~v59cR~
    puftph=pfh->UFHpuftph;                                         //~v8@BI~
//if (FILEISREMOTE(pfh))                                           //~v71NR~
  if (FILEISREMOTE(pfh)                                            //~v71NI~
  &&  !FILEISTSO(pfh))                                             //~v71NI~
    rc=dcmdrshlocalfile(Ppcw,pfh,Scmdfullpath,Sredirectparm+1,0);	//stde is &1//~v59cI~
  else                                                             //~v59cM~
  {                                                                //~v59cM~
   if (FILEISTSO(pfh)                                              //~v71NI~
   && Pplc->UDLCcmd==DLCMD_SUBRSH)                                 //~v71NI~
   {                                                               //~v71NI~
   if (UFTPHISTSOSUBM(puftph))   //use TSO submit                  //~v8@BI~
    rc=dlcmdtsosub(1,Ppcw,puftph,Scmdfullpath,Sredirectparm+1);	//issue TSO SUB cmd//~v8@BR~
   else                                                            //~v8@BI~
   {                                                               //~v8@BI~
   	sprintf(cmdstr,"%s %s %s 2>&1",TSOSUBCMD,Scmdfullpath,Sredirectparm);//~v71NR~
    Ppcw->UCWparm=cmdstr;                                          //~v71NI~
//	podt=(PUPODELMTBL)(ULONG)wkpodt;                               //~v71NR~//~vafkR~
//	podt=(PUPODELMTBL)(ULPTR)wkpodt;                               //~vafkI~//~vap0R~
    pvoid=wkpodt;                                                  //~vap0I~
	podt=(PUPODELMTBL)pvoid;                                       //~vap0I~
	wkppot=wkpot;                                                  //~v71NI~
    uparse2(cmdstr,&podt,&wkppot,&wordno,                          //~v71NI~
    		UPARSE2USEAREAPARM|UPARSE2SETCONTDLM2,0);              //~v71NI~
    Ppcw->UCWopdno=wordno;	//cmd operand number                   //~v71NR~
    Ppcw->UCWopdpot=wkppot;                                        //~v71NR~
    Ppcw->UCWopddelmt=podt;                                        //~v71NR~
    rc=func_submit(Ppcw);                                          //~v71NI~
   }                                                               //~v8@BI~
   }                                                               //~v71NI~
   else                                                            //~v71NI~
   {                                                               //~v71NI~
#endif                                                             //~v59cM~
//    Ppcw->UCWopdno=2;       //cmd operand number                 //~v71NR~
//    strcpy(cmdstr,Scmdfullpath);                                 //~v71NR~
//    strcat(cmdstr," "); //ajust for delmtbl                      //~v71NR~
//    strcat(cmdstr,Sredirectparm);                                //~v71NR~
//    Ppcw->UCWparm=cmdstr;                                        //~v71NR~
//    strcpy(cmdstrpo,Scmdfullpath);                               //~v71NR~
//    strcpy(cmdstrpo+strlen(Scmdfullpath)+1,Sredirectparm);//parse out fmt//~v71NR~
//    Ppcw->UCWopdpot=cmdstrpo;                                    //~v71NR~
//    memset(&delmt,0,sizeof(delmt));                              //~v71NR~
//    delmt[0].upodelmoffs=(USHORT)strlen(Scmdfullpath);           //~v71NR~
//    delmt[1].upodelmoffs=(USHORT)(delmt[0].upodelmoffs+1+strlen(Sredirectparm));//~v71NR~
//    Ppcw->UCWopddelmt=&delmt;                                    //~v71NR~
   	sprintf(cmdstr,"%s %s 2>&1",Scmdfullpath,Sredirectparm);       //~v71NI~
    Ppcw->UCWparm=cmdstr;                                          //~v71NI~
//	podt=(PUPODELMTBL)(ULONG)wkpodt;                               //~v71NI~//~vafkR~
//	podt=(PUPODELMTBL)(ULPTR)wkpodt;                               //~vafkI~//~vap0R~
    pvoid=wkpodt;                                                  //~vap0I~
	podt=(PUPODELMTBL)pvoid;                                       //~vap0I~
	wkppot=wkpot;                                                  //~v71NI~
    uparse2(cmdstr,&podt,&wkppot,&wordno,                          //~v71NI~
    		UPARSE2USEAREAPARM|UPARSE2SETCONTDLM2,0);              //~v71NI~
    Ppcw->UCWopdno=wordno;	//cmd operand number                   //~v71NI~
    Ppcw->UCWopdpot=wkppot;                                        //~v71NI~
    Ppcw->UCWopddelmt=podt;                                        //~v71NI~
    rc=func_submit(Ppcw);                                          //~v51WR~
#ifdef FTPSUPP                                                     //~v59cI~
	dlcxpdelremotetemp();	//delete tempdir downloaded contaims file//~v71NI~
   }//!TSO sub                                                     //~v71NI~
  }//local submit                                                  //~v59cI~
#endif                                                             //~v59cI~
  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr                 //~v583I~
    uerrmsg("done,see cmdfile=%s,stdout=%s",0,                     //~v51WR~
		    Scmdfnm,Sredirectparm+1);                              //~v51WR~
    return rc;                                                     //~v51WI~
}//dlcmdappcmd                                                     //~v51WI~
//**************************************************************** //~vamyI~
// dlcmdappasync                                                   //~vamyI~
// submit cmd work file asyncronously                              //~vamyI~
//*ret  :rc                                                        //~vamyI~
//**************************************************************** //~vamyI~
int dlcmdappasync(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)  //~vamyI~
{                                                                  //~vamyI~
    PULINEH plh;                                                   //~vamyI~
    PUFILEH pfh;                                                   //~vamyI~
    UCHAR  cmdstr[_MAX_PATH+MAXCOLUMN+32];                         //~vamyI~
    UCHAR  redirectfile[_MAX_PATH];                                //~vamHI~
    int rc;                                                        //~vamyR~
    UCHAR wkpot[_MAX_PATH+MAXCOLUMN+32+1];                         //~vamyI~
    UCHAR wkpodt[_MAX_PATH+MAXCOLUMN+32+1];                        //~vamyI~
	UCHAR *wkppot;                                                 //~vamyI~
    PUPODELMTBL podt;                                              //~vamyI~
	int wordno;                                                    //~vamyI~
    void *pvoid;                                                   //~vap0I~
//*******************                                              //~vamyI~
    if (Pplc!=Splcac)   //not last print entry                     //~vamyI~
        return 0;                                                  //~vamyI~
    plh=Pplc->UDLCplh;                                             //~vamyI~
    Gdcmdtempf|=GDCMDTEMPF_DLCMDCF; //del at term                  //~vamyI~
    pfh=UGETPFH(plh);                                              //~vamyI~
  	if (FILEISREMOTE(pfh))                                         //~vamyR~
    {                                                              //~vamyI~
   		uerrmsg("'%c' cmd is not supported for remote file",0,     //~vamyI~
    			UDLCCMD_APPASYNC);	                               //~vamyI~
        rc=4;        	                                           //~vamyI~
    }                                                              //~vamyI~
  	else                                                           //~vamyR~
  	{                                                              //~vamyR~
//      sprintf(cmdstr,"%s %s 2>&1",Scmdfullpath,Sredirectparm);   //~vamyI~//~vamHR~
		Sasynccmdseqno++;                                          //~vamHI~
        sprintf(redirectfile,"%s_%d",Sredirectparm,Sasynccmdseqno);//~vamHR~
        sprintf(cmdstr,"%s %s 2>&1",Scmdfullpath,redirectfile);    //~vamHI~
        Ppcw->UCWparm=cmdstr;                                      //~vamyI~
//      podt=(PUPODELMTBL)(ULPTR)wkpodt;                           //~vamyI~//~vap0R~
        pvoid=wkpodt;                                              //~vap0I~
        podt=(PUPODELMTBL)pvoid;                                   //~vap0I~
        wkppot=wkpot;                                              //~vamyI~
        uparse2(cmdstr,&podt,&wkppot,&wordno,                      //~vamyI~
                UPARSE2USEAREAPARM|UPARSE2SETCONTDLM2,0);          //~vamyI~
        Ppcw->UCWopdno=wordno;  //cmd operand number               //~vamyI~
        Ppcw->UCWopdpot=wkppot;                                    //~vamyI~
        Ppcw->UCWopddelmt=podt;                                    //~vamyI~
        rc=func_submit(Ppcw);                                      //~vamyI~
  	}//local submit                                                //~vamyR~
  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr                 //~vamyI~
    uerrmsg("done,see cmdfile=%s,stdout=%s",0,                     //~vamyI~
//  	    Scmdfnm,Sredirectparm+1);                              //~vamyI~//~vamHR~
    	    Scmdfnm,redirectfile+1);                               //~vamHI~
    return rc;                                                     //~vamyI~
}//dlcmdappasync                                                   //~vamyI~
#ifdef FTPSUPP                                                     //~v8@BI~
//**************************************************************** //~v8@BI~
// dlcmtsosub                                                      //~v8@BI~
// submit by TSO SUBMIT cmd                                        //~v8@BI~
//*ret  :rc                                                        //~v8@BI~
//**************************************************************** //~v8@BI~
int dlcmdtsosub(int Popt,PUCLIENTWE Ppcw,PUFTPHOST Ppuftph,char *Pcmdlistfnm,char *Pjclfnm)//~v8@BI~
{                                                                  //~v8@BI~
	int rc=0;                                                        //~v8@BI~//~vaf9R~
    FILE *fh,*fho;                                                 //~v8@BR~
    char fpath[_MAX_PATH],fpatho[_MAX_PATH],*pmsg;                 //~v8@BR~
//*******************                                              //~v8@BI~
	if (!(Popt & 0x01)) //dlc entry                                //~v8@BR~
    {                                                              //~v8@BI~
    	fh=fopen(Pcmdlistfnm,"a");	//append mode                  //~v8@BI~
        if (!fh)                                                   //~v8@BI~
        	return ufileapierr("fopen-a",Pcmdlistfnm,4);           //~v8@BI~
        fprintf(fh,"%s\n",Pjclfnm);                                //~v8@BR~
        fclose(fh);                                                //~v8@BI~
    }                                                              //~v8@BI~
    else   //last call,jcl parm is redirectfile name               //~v8@BR~
    {                                                              //~v8@BI~
    	fh=fopen(Pcmdlistfnm,"r");	//append mode                  //~v8@BI~
        if (!fh)                                                   //~v8@BI~
        	return ufileapierr("fopen-r",Pcmdlistfnm,4);           //~v8@BI~
	    dcmdfullpath(Ppcw,fpatho,Pjclfnm);   //redirect fnm ::#.cfso//~v8@BI~
    	fho=fopen(fpatho,"w");	//output                           //~v8@BR~
        if (!fho)                                                  //~v8@BI~
        {                                                          //~v8@BI~
        	fclose(fh);                                            //~v8@BI~
        	return ufileapierr("fopen-r",Pcmdlistfnm,4);           //~v8@BI~
        }                                                          //~v8@BI~
        for (;;)                                                   //~v8@BI~
        {                                                          //~v8@BI~
        	if (!fgets(fpath,sizeof(fpath),fh))                    //~v8@BR~
            	break;                                             //~v8@BI~
	        USTR_DROPEOL(fpath);     //del last \n                 //~v8@BI~
            rc=xetsosubmit(0,Ppuftph,fpath,0);	//issue TSO submit //~v8@BR~
            pmsg=ugeterrmsg2();	//no clear                         //~v8@BR~
            if (pmsg)                                              //~v8@BI~
            	fprintf(fho,"%s\n",pmsg);                          //~v8@BI~
            if (rc)                                                //~v8@BI~
            	break;                                             //~v8@BI~
        }                                                          //~v8@BI~
        fclose(fh);                                                //~v8@BI~
        fclose(fho);                                               //~v8@BI~
    }                                                              //~v8@BI~
    return rc;                                                     //~v8@BI~
}//dlcmdtsosub                                                     //~v8@BI~
#endif                                                             //~v8@BI~
//**************************************************************** //~v59eI~
// dlcmdsubrshcmd                                                  //~v8@BR~
// submit cmd work file                                            //~v59eI~
//*ret  :rc                                                        //~v59eI~
//**************************************************************** //~v59eI~
int dlcmdsubrshcmd(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy) //~v59eI~
{                                                                  //~v59eI~
	int rc;                                                        //~v59eI~
//*******************                                              //~v59eI~
	rc=dlcmdappcmd(Ppcw,Pplc,Pplcdummy);                           //~v59eI~
    return rc;                                                     //~v59eI~
}//dlcmdsubrshcmd                                                  //~v59eI~
#ifndef DOS                                                        //~v662I~
//**************************************************************** //~v662I~
// dlcmdappcmd                                                     //~v662I~
// submit cmd work file                                            //~v662I~
//*ret  :rc                                                        //~v662I~
//**************************************************************** //~v662I~
int dlcmdspawn(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)     //~v662I~
{                                                                  //~v662I~
	int rc;                                                        //~v662I~
    UCHAR  cmdstr[_MAX_PATH+MAXCOLUMN];                            //~v662I~
    PULINEH plh;                                                   //~v662I~
#ifdef FTPSUPP                                                     //~v662I~
    PUFILEH pfh;                                                   //~v662I~
#endif                                                             //~v662I~
#ifndef UNX                                                        //~v662I~
    PUDIRLH pdh;                                                   //~v662I~
#endif                                                             //~v662I~
//*******************                                              //~v662I~
    plh=Pplc->UDLCplh;                                             //~v662M~
#ifndef UNX                                                        //~v662I~
    pdh=UGETPDH(plh);                                              //~v662I~
    if (dlcgetfullname(pdh,cmdstr))                                //~v662I~
        return 4;                                                  //~v662I~
    rc=uextchk(cmdstr);                                            //~v662I~
    if (!rc||rc==9)		//ext err or no extention                  //~v662I~
    {                                                              //~v662I~
//    	uerrmsg("filename extension error",0);                     //~v662I~//~vbp0R~
      	uerrmsg("filename extension error, try \"!\" line cmd if default app is defined to the filename extension.",//~vbp0I~
      	        "拡張子エラー、この拡張子に関連付けされたアプリがある場合は \"!\" 行コマンドを試してください");//~vbp0I~
        return 4;                                                  //~v662I~
    }                                                              //~v662I~
#endif                                                             //~v662I~
	if (dlcmdgetcmdstr(Ppcw,Pplc,cmdstr))                          //~v662I~
    	return 4;                                                  //~v662I~
#ifdef FTPSUPP                                                     //~v662I~
    pfh=UGETPFH(plh);                                              //~v662I~
  	if (FILEISREMOTE(pfh))                                         //~v662I~
    {                                                              //~v662I~
    	uerrmsg("remote file not yet supported",0);                //~v662I~
        rc=4;                                                      //~v662I~
    }                                                              //~v662I~
  	else                                                           //~v662I~
  	{                                                              //~v662I~
#endif                                                             //~v662I~
        Ppcw->UCWparm=cmdstr;                                      //~v662I~
        rc=dcmd_spawn(Ppcw);                                       //~v662I~
        if (rc)                                                    //~vbp0I~
      		uerrmsgcat(";try \"!\" line cmd if default app is defined to the filename extension.",//+vbp0R~
      	        "、この拡張子に関連付けされたアプリがある場合は \"!\" 行コマンドを試してください");//~vbp0I~
#ifdef FTPSUPP                                                     //~v662I~
  	}//local submit                                                //~v662I~
#endif                                                             //~v662I~
  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr                 //~v662I~
    return rc;                                                     //~v662I~
}//dlcmdspawn                                                      //~v662I~
#endif                                                             //~v662I~
//#ifdef W32                                                       //~v64vR~
#if defined(W32) || defined(LNX)                                   //~v64vI~
//**************************************************************** //~v55vI~
// dlcmdopenwith                                                   //~v55vI~
// submit cmd work file                                            //~v55vI~
//*ret  :rc                                                        //~v55vI~
//**************************************************************** //~v55vI~
int dlcmdopenwith(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)  //~v55vI~
{                                                                  //~v55vI~
    char fpath[_MAX_PATH];                                         //~v55vI~
    PULINEH plh;                                                   //~v55vI~
    PUDIRLH pdh;                                                   //~v55vI~
    int rc;                                                        //~v55vI~
//***********************                                          //~v55vI~
    plh=Pplc->UDLCplh;                                             //~v55vI~
    pdh=UGETPDH(plh);                                              //~v55vI~
    if (dlcgetfullname(pdh,fpath))                                 //~v55vI~
        return 4;                                                  //~v55vI~
//  rc=ushellexec(fpath); 	//0:no return HINSTANCE                //~v55VR~
    rc=dlcmdopenwithsub(Ppcw,fpath); 	//0:no return HINSTANCE    //~v55VI~
  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr                 //~v583I~
    return rc;                                                     //~v55vI~
}//dlcmdopenwith                                                   //~v55vI~
//**************************************************************** //~v55VI~
// dlcmdopenwithsub                                                //~v55VI~
// subbmit associated app and register file to filename list       //~v55VI~
//*ret  :rc                                                        //~v55VI~
//**************************************************************** //~v55VI~
int dlcmdopenwithsub(PUCLIENTWE Ppcw,char *Pfnm)                   //~v55VI~
{                                                                  //~v55VI~
    int rc;                                                        //~v55VI~
//***********************                                          //~v55VI~
#ifdef FTPSUPP                                                     //~v64vI~
    if (uftpisremote(Pfnm,0))                                      //~v64vI~
    {                                                              //~v64vI~
        uerrmsg("remote file is not supported",0);                 //~v64vI~
        return 4;                                                  //~v64vI~
    }                                                              //~v64vI~
#endif                                                             //~v64vI~
//  pan300addentry(Pfnm,strlen(Pfnm),0);                           //~v55VI~//~vb2DR~
    pan300addentry(Pfnm,(int)strlen(Pfnm),0);                      //~vb2DI~
  #ifdef LNX                                                       //~v64vI~
//   #ifdef ARM                                                    //~va90R~
//    rc=errnotsupported("Kick Application by Mime Type","Android");//~va90R~
//   #else                                                         //~va90R~
    rc=(ushellexec(0,Pfnm)==-1);                                   //~v64vI~
//   #endif                                                        //~va90R~
  #else                                                            //~v64vI~
	rc=ushellexec(Pfnm); 	//0:no return HINSTANCE                //~v55VI~
  #endif                                                           //~v64vI~
    return rc;                                                     //~v55VI~
}//dlcmdopenwithsub                                                //~v55VI~
#endif                                                             //~v55vI~
//#ifdef WXE                                                       //~v64vR~
#if defined(WXE) || defined(LNX)                                   //~v64vR~
//*************************************************************    //~v56eM~
//*association chk for filenamelist                                //~v56eM~
//*************************************************************    //~v56eM~
int dlcmdassocchk_fnamelist(PUCLIENTWE Ppcw)                       //~v56eM~
{                                                                  //~v56eM~
#ifndef LNX                                                        //~v64vR~
	FILEFINDBUF3 ffb3;                                             //~v56eM~
    UCHAR *pc;                                                     //~v64vI~
#endif                                                             //~v64vI~
	int assocsw=0;                                                 //~v56eM~
    UCHAR fpath[_MAX_PATH];                                        //~v64vR~
//**************************************                           //~v56eM~
    if (pan300getfnm(Ppcw->UCWrcsry+Ppcw->UCWtopfnlist,fpath))	//get stacked name over scr width//~v56eM~
    {                                                              //~v56eM~
	  if (!uftpisremote(fpath,0))                                  //~v71rI~
      {                                                            //~v71rI~
#ifdef LNX                                                         //~v64vR~
    #ifdef ARM                                                     //~va90I~
        return errnotsupported("Kick Application by Mime Type","Android");//~va90I~
    #else                                                          //~va90I~
        assocsw=(ushellexec(USHEXE_CHKONLY|USHEXE_NOMSG,fpath)>=0);//~v64vR~
    #endif                                                         //~va90I~
#else                                                              //~v64vI~
	  if (!ufstat(fpath,&ffb3))                                    //~v56eR~
		if (ffb3.attrFile & FILE_DIRECTORY)                        //~v56eI~
        	assocsw=1;	//use explorer under win XP                //~v56eM~
        else                                                       //~v56eM~
        {                                                          //~v56eM~
    		pc=umemrchr(fpath,'.',strlen(fpath));	//search extension//~v56eM~
        	if (pc)                                                //~v56eM~
        		assocsw=uwinreg_chkassociation(pc);                //~v56eM~
        }                                                          //~v56eM~
#endif                                                             //~v64vI~
      }//not remote                                                //~v71rI~
    }                                                              //~v56eM~
    return assocsw;                                                //~v56eM~
}//dlcmdassocchk_fnamelist                                         //~v56eM~
//*************************************************************    //~v56eM~
//*association chk for dirlist filename                            //~v56eM~
//*************************************************************    //~v56eM~
int  dlcmdassocchk_dirlist(PUCLIENTWE Ppcw)                        //~v56eM~
{                                                                  //~v56eM~
	PUDIRLH pdh;                                                   //~v56eM~
#ifndef LNX                                                        //~v64vR~
    UCHAR *pc;                                                     //~v64vI~
#endif                                                             //~v64vI~
	int assocsw=0;                                                 //~v56eM~
    UCHAR fpath[_MAX_PATH];                                        //~v64vR~
//**********************************                               //~v56eM~
    if (!dlcgetdirlistfname(Ppcw,fpath,&pdh))                      //~v56eM~
    {                                                              //~v56eM~
	  if (!uftpisremote(fpath,0))                                  //~v71rI~
      {                                                            //~v71rI~
#ifdef LNX                                                         //~v64vR~
    #ifdef ARM                                                     //~va90I~
        return errnotsupported("Kick Application by Mime Type","Android");//~va90I~
    #else                                                          //~va90I~
        assocsw=(ushellexec(USHEXE_CHKONLY|USHEXE_NOMSG,fpath)>=0);//~v64vR~
    #endif                                                         //~va90I~
#else                                                              //~v64vI~
    	if (pdh->UDHattr & FILE_DIRECTORY)//not dirname            //~v56eM~
        	assocsw=1;	//use explorer under win XP                //~v56eM~
        else                                                       //~v56eM~
	    {                                                          //~v56eM~
    		pc=umemrchr(fpath,'.',strlen(fpath));	//search extension//~v56eM~
        	if (pc)                                                //~v56eM~
        		assocsw=uwinreg_chkassociation(pc);                //~v56eM~
    	}                                                          //~v56eM~
#endif                                                             //~v64vI~
      }//not remote                                                //~v71rI~
    }                                                              //~v56eM~
    return assocsw;                                                //~v56eM~
}//dlcmdassocchk_dirlist                                           //~v56eM~
#endif                                                             //~v56eI~
//**************************************************************** //~v75JI~
// dlcmdgrep                                                       //~v75MR~
// grep search                                                     //~v75MR~
//*ret  :rc                                                        //~v75JI~
//**************************************************************** //~v75JI~
int dlcmdgrep(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)      //~v75JI~
{                                                                  //~v75JI~
#define FINDGREPCMD "f *g all"                                     //~v75JI~
	int rc,len,grepctr;                                            //~v75JR~
    UCHAR  cmdstr[_MAX_PATH+MAXCOLUMN],*pc,*pc2;                   //~v75JR~
    UCHAR  wildcard[_MAX_PATH],*pcwild;                            //~v75JI~
    UCHAR  redirectfnm[_MAX_PATH];                                 //~v75JI~
    PULINEH plh;                                                   //~v75JI~
#ifdef FTPSUPP
    PUFILEH pfh;                                                   //~v75JI~
#endif
    PUDIRLH pdh;                                                   //~v75JI~
#ifdef UNX                                                         //~v75JI~
#else                                                              //~v75JI~
    int quotesw;                                                   //~v75JR~
#endif                                                             //~v75JI~
//*******************                                              //~v75JI~
	grepctr=(int)Pplc->UDLCparm1;                                  //~v75JR~
    plh=Pplc->UDLCplh;                                             //~v75JI~
#ifdef FTPSUPP
    pfh=UGETPFH(plh);                                              //~v75JI~
#endif
    pdh=UGETPDH(plh);                                              //~v75JI~
    pc=cmdstr;                                                     //~v75JI~
//  strcpy(pc,"grep ");                                            //~v76gR~
//  pc+=5;                                                         //~v76gR~
    pc+=sprintf(pc,"%s ",Ggrepcmd);                                //~v76gR~
    pc2=pc;		//top of parm                                      //~v75JI~
//  if ((len=dirgetflddata(Ppcw,plh,PANL310RENAME,pc))<0)          //~v75JR~//~va00R~
    if ((len=BYUTF8_dirgetflddata(Ppcw,plh,PANL310RENAME,pc))<0)   //~va00I~
    	return 4;                                                  //~v75JI~
    if (!len) 	//no grep string                                   //~v75JI~
    {                                                              //~v75JI~
    	uerrmsg("specify grep search string",                      //~v75JI~
        		"grepの探索文字を指定してください");               //~v75JI~
        return 4;                                                  //~v75JI~
    }                                                              //~v75JI~
  if (pdh->UDHtype==UDHTFILE) 	//search in dir                    //~v75PI~
    pcwild=0;                                                      //~v75PI~
  else                                                             //~v75PI~
  {                                                                //~v75PI~
    pcwild=umemrchr(pc2,' ',(UINT)len);		//end of parm          //~v75JI~
	if (pcwild) //last of multiple parm                            //~v75JI~
    {                                                              //~v75JI~
        pcwild++;      //over space                                //~v75JI~
        if (*pcwild=='"'||*pcwild=='\'')    //quotation is grep expression//~v75PI~
            pcwild=0;                                              //~v75PI~
        else                                                       //~v75PI~
        if (*pcwild=='/' || *pcwild=='-' || !WILDCARD(pcwild))     //~v75JI~
            pcwild=0;                                              //~v75JI~
        else                                                       //~v75JI~
        {                                                          //~v75JI~
//          len=(int)((ULONG)pcwild-(ULONG)pc2)-1;                 //~v75JI~//~vafkR~
            len=(int)((ULPTR)pcwild-(ULPTR)pc2)-1;                 //~vafkI~
            strcpy(wildcard,pcwild);                               //~v75JI~
            *pcwild=0;                                             //~v75JI~
            pcwild=wildcard;                                       //~v75JI~
        }                                                          //~v75JI~
    }                                                              //~v75JI~
  }                                                                //~v75PI~
    pc+=len;                                                       //~v75JI~
    *pc++=' ';                                                     //~v75JI~
    if (pdh->UDHtype==UDHTFILE) 	//search in the file           //~v75JI~
    {                                                              //~v75JI~
//      if (dlcgetfullnameenclose(pdh,pc))                         //~v75JI~//~vavHR~
        if (dlcgetfullnameenclose(0/*opt*/,pdh,pc))                //~vavHI~
            return 4;                                              //~v75JI~
        pc+=strlen(pc);                                            //~v75JI~
    }                                                              //~v75JI~
    else                                                           //~v75JI~
    {                                                              //~v75JI~
#ifdef FTPSUPP                                                     //~v75JM~
  		if (FILEISREMOTE(pfh))                                     //~v75JI~
    		return errnotsupported("grep","remote file");          //~v75JI~
#endif                                                             //~v75JM~
//searc wildcard specification                                     //~v75JI~
        if (!pcwild)                                               //~v75JR~
        	pcwild=DIR_ALLMEMB;                                    //~v75JI~
//      if (dlcgetfullnameenclose(pdh,pc))                         //~v75JI~//~vavHR~
        if (dlcgetfullnameenclose(0/*opt*/,pdh,pc))                //~vavHI~
            return 4;                                              //~v75JI~
        pc+=strlen(pc);                                            //~v75JI~
#ifdef UNX                                                         //~v75JI~
        pc2=pc;                                                    //~v75JI~
#else                                                              //~v75JI~
        if (*(pc-1)=='"')                                          //~v75JI~
            quotesw=1;                                             //~v75JI~
        else                                                       //~v75JI~
            quotesw=0;                                             //~v75JI~
        pc2=pc-quotesw;                                            //~v75JI~
#endif                                                             //~v75JI~
        if (*(pc2-1)!=DIR_SEPC)                                    //~v75JR~
        	*pc2++=DIR_SEPC;                                       //~v75JI~
        strcpy(pc2,pcwild);                                        //~v75JI~
        pc2+=strlen(pc2);                                          //~v75JI~
#ifdef UNX                                                         //~v75JI~
#else                                                              //~v75JI~
        if (quotesw)                                               //~v75JR~
        {                                                          //~v75JI~
        	*pc2++='"';                                            //~v75JI~
        	*pc2=0;                                                //~v75JI~
        }                                                          //~v75JI~
#endif                                                             //~v75JI~
        pc=pc2;                                                    //~v75JI~
    }                                                              //~v75JI~
//  len=(int)((ULONG)pc-(ULONG)cmdstr);                            //~v75JR~//~vafkR~
    len=(int)((ULPTR)pc-(ULPTR)cmdstr);                            //~vafkI~
    rc=dcmd_grepdlcmd(Ppcw,cmdstr,len,redirectfnm,grepctr);        //~v75JR~
    if (rc==1)	//no line found                                    //~v75JI~
    	if (UCBITCHK(Pplc->UDLCflag,UDLCFLAST)                     //~v75JI~
    	&&  UCBITCHK(Pplc->UDLCflag,UDLCF1ST))	                   //~v75JI~
        	return 4;                                              //~v75JI~
    if (!rc)                                                       //~v75QI~
		UCBITOFF(pdh->UDHflag,UDHFLCMDIN2|UDHFDDSETUP);//set pro at ddsetup//~v75QI~
    else                                                           //~v75QI~
    	if (rc<8)                                                  //~v75QI~
    		if (!UCBITCHK(Pplc->UDLCflag,UDLCFLAST))               //~v75QI~
        		rc=2;   //continue to next line                    //~v75QR~
            else                                                   //~v75QI~
	        	rc=4;   //stop process of multiple cmd             //~v75QI~
        else                                                       //~v75QI~
        	rc=4;   //stop process of multiple cmd                 //~v75QI~
    if (!UCBITCHK(Pplc->UDLCflag,UDLCFLAST))                       //~v75JM~
    {                                                              //~v75JI~
//        if (rc<8)   //stop other grep process                    //~v75QR~
//            rc=0;   //continue process                           //~v75QR~
    	return rc;                                                 //~v75JI~
    }                                                              //~v75JI~
//edit/browse redirect file at last                                //~v75JI~
    pc=cmdstr;                                                     //~v75JR~
    pc+=sprintf(pc,"%c %s",(dlcmdbecmdid(Ppcw,Pplc)?'e':'b'),redirectfnm);//~v75JR~
//  len=(int)((ULONG)pc-(ULONG)cmdstr);                            //~v75JR~//~vafkR~
    len=(int)((ULPTR)pc-(ULPTR)cmdstr);                            //~vafkI~
    funcsetlongcmd(Ppcw,1,cmdstr,len,0); //1:execute(put on cmd buff),0:no output len//~v75QR~
    Ppcw->UCWreason=UCWRCMDSET; //do not clear at func_exec_pan    //~v75JR~
  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr                 //~v75JI~
    return rc;                                                     //~v75QR~
}//dlcmdgrep                                                       //~v75JI~
//**************************************************************** //~v75MI~
// dlcmdcompare                                                    //~v75MI~
// file compare by xfc                                             //~v75MI~
//*ret  :rc                                                        //~v75MI~
//**************************************************************** //~v75MI~
int dlcmdcompare(PUCLIENTWE Ppcw,PUDLCMD Pplc1,PUDLCMD Pplc2)      //~v75MR~
{                                                                  //~v75MI~
//#define COMPARETOOL "xfc"                                        //~v76gR~
	int rc,rc1,rc2,len,len1,len2,redirectctr;                      //~v75MR~
    UCHAR  cmdparm1[MAXCOLUMN],cmdparm2[MAXCOLUMN];                //~v75MI~
    UCHAR  cmdopt1[MAXCOLUMN],cmdopt2[MAXCOLUMN];                  //~v75MI~
    UCHAR  fnm1[_MAX_PATH],fnm2[_MAX_PATH],fpath[_MAX_PATH],*pfnm1,*pfnm2;//~v75MI~
    UCHAR  pdhfnm1[_MAX_PATH],pdhfnm2[_MAX_PATH],redirectfnm[_MAX_PATH];//~v75MR~
//  UCHAR  cmdstr[_MAX_PATH+MAXCOLUMN],*pc,*pengmode;              //~v75MR~//~vavHR~
    UCHAR  cmdstr[_MAX_PATH*2+MAXCOLUMN],*pc,*pengmode;            //~vavHI~
	PUDLCMD plc;                                                   //~v75MI~
    PULINEH plh1,plh2=NULL,plh;                                         //~v75MR~//~vafcR~
    PUFILEH pfh,pfh1,pfh2=NULL;                                         //~v75MR~//~vafcR~
    PUDIRLH pdh1,pdh2;                                             //~v75MI~
    int dirsw1,dirsw2=0;                                           //~v76hI~
    char *pcmdnm;                                                  //~v76hI~
    FILEFINDBUF3 ffb3;                                             //~v76hI~
#ifdef FTPSUPP                                                     //~v76pI~
//	PUFTPHOST puftph1=(PUFTPHOST)-1,puftph2=(PUFTPHOST)-1;         //~v76pR~//~vafkR~
	PUFTPHOST puftph1=(PUFTPHOST)(ULPTR)-1,puftph2=(PUFTPHOST)(ULPTR)-1;//~vafkI~
#endif                                                             //~v76pI~
#ifdef W32UNICODE                                                //~vavHR~//~vavNR~
//    UCHAR cmdoptu8[16]={0};                                      //~vavHR~
//#define U8OPT1   "/U1"                                           //~vavHR~
//#define U8OPT2   "/U2"                                           //~vavHR~
#endif                                                           //~vavHR~//~vavNR~
//*******************                                              //~v75MI~
    Scompcmdcpu8=0;                                                //~vbj1R~
	redirectctr=(int)Pplc1->UDLCparm1;                             //~v75MR~
    pfh=UGETPFHFROMPCW(Ppcw);                                      //~v75MI~
    plh1=Pplc1->UDLCplh;                                           //~v75MI~
    pfh1=UGETPFH(plh1);                                            //~v75MI~
    pdh1=UGETPDH(plh1);                                            //~v75MI~
    dirsw1=(int)(pdh1->UDHattr & FILE_DIRECTORY);                  //~v76pR~
#ifdef FTPSUPP                                                     //~v76pI~
    if (pdh1->UDHattr & (FILE_SPECIAL|FILE_DSNPATH))               //~v76pI~
		return ufileerrnotnormal(pdh1->UDHname,4);                 //~v76pR~
	puftph1=pfh1->UFHpuftph;                                       //~v76pR~
#endif                                                             //~v76pI~
    if (Pplc2)	//single line cmd                                  //~v75MI~
    {                                                              //~v75MI~
    	plh2=Pplc2->UDLCplh;                                       //~v75MI~
        pfh2=UGETPFH(plh2);                                        //~v75MI~
        pdh2=UGETPDH(plh2);                                        //~v75MI~
        dirsw2=(int)(pdh2->UDHattr & FILE_DIRECTORY);              //~v76pR~
#ifdef FTPSUPP                                                     //~v76pI~
	    if (pdh2->UDHattr & (FILE_SPECIAL|FILE_DSNPATH))           //~v76pI~
			return ufileerrnotnormal(pdh2->UDHname,4);             //~v76pI~
		puftph2=pfh2->UFHpuftph;                                   //~v76pI~
#endif                                                             //~v76pI~
    }                                                              //~v75MI~
    else                                                           //~v75MI~
    	pdh2=0;                                                    //~v75MI~
    if (pfh==pfh1)                                                 //~v75MI~
    {                                                              //~v75MI~
//*if !Pplc2, pfh=pfh1                                             //~vafcI~
    	plc=Pplc1;                                                 //~v75MI~
        plh=plh1;                                                  //~v75MI~
    }                                                              //~v75MI~
    else                                                           //~v75MI~
    {                                                              //~v75MI~
    	plc=Pplc2;                                                 //~v75MI~
        plh=plh2;                                                  //~v75MI~
    }                                                              //~v75MI~
//#ifdef FTPSUPP                                                   //~v76pR~
//	if (FILEISREMOTE(pfh1))                                        //~v76pR~
//  	return errnotsupported("=(compare)","remote file");        //~v76pR~
//#endif                                                           //~v76pR~
//  if (dlcgetfullnameenclose(pdh1,pdhfnm1))                       //~v75MI~//~vavHR~
#ifdef W32UNICODE                                                  //~vavHR~
    {                                                              //~vavHR~
        int opt3,rc3;                                              //~vavHR~
////      opt3=DLCGFEO_ENCUD|DLCGFEO_STRIPUD;                      //~vavHR~
//        opt3=DLCGFEO_ENCUD;                                      //~vavHR~
//        rc3=dlcgetfullnameenclose(opt3,pdh1,pdhfnm1);            //~vavHR~
//        if (rc3==2) //UD string strip and enclosed               //~vavHR~
//           strcat(cmdoptu8," " U8OPT1);                          //~vavHR~
//        else                                                     //~vavHR~
//      opt3=DLCGFEO_ALIAS;                                        //~vavHR~//~vavMR~
        opt3=0;//xfc support UD string fnm                         //~vavMI~//~vavNR~
        rc3=dlcgetfullnameenclose(opt3,pdh1,pdhfnm1);              //~vavHI~
        if (rc3 && rc3!=2)	//rc=2 alias used                      //~vavHR~
            return 4;                                              //~vavHR~
    }                                                              //~vavHR~
#else                                                              //~vavHR~
    if (dlcgetfullnameenclose(0/*opt*/,pdh1,pdhfnm1))              //~vavHI~
    	return 4;                                                  //~v75MI~
#endif                                                             //~vavHR~
    rc1=dlcmdgetcmdparm(Ppcw,plh1,cmdparm1,&len1,cmdopt1,fnm1);    //~v75MI~
    if (rc1>1)                                                     //~v75MI~
    	return rc1;                                                //~v75MI~
    if (Guerropt & GBL_UERR_FORCEENG)                              //~v75MR~
    	pengmode="-N9";                                            //~v75MI~
    else                                                           //~v75MI~
    	pengmode="";                                               //~v75MI~
    if (!Pplc2)	//single line cmd                                  //~v75MI~
    {                                                              //~v75MI~
    	if (!len1 || rc1)	//single line w/o pospatm              //~v75MI~
        {                                                          //~v75MI~
        	uerrmsg("Specify 2nd filename or set '=' command on another line",//~v75MI~
            		"ファイル名を指定するか、別の行に'='コマンドをセットする。");//~v75MI~
            return 1;                                              //~v75MI~
        }                                                          //~v75MI~
        dcmdfullpath(Ppcw,fpath,fnm1);	//support *\,**\,^*,::     //~v76pR~
#ifdef FTPSUPP                                                     //~v76pI~
      	dirsw2=-1;	//chk requireed                                //~v76pI~
        if (dlccompchkfiletype(pdhfnm1,fpath,&puftph1,&puftph2,&dirsw1,&dirsw2))//~v76pR~
        	return 4;                                              //~v76pI~
#endif                                                             //~v76pI~
        if (dirsw1)                                                //~v76hI~
	        dirsw2=!ufstat(fpath,&ffb3) && (ffb3.attrFile & FILE_DIRECTORY);//~v76hR~
        if (dirsw1 && dirsw2)                                      //~v76hI~
//      	pcmdnm=COMPARETOOLDIR;                                 //~v76gR~
        	pcmdnm=Gcomparecmdd;                                   //~v76gI~
        else                                                       //~v76hI~
//      	pcmdnm=COMPARETOOL;                                    //~v76gR~
        	pcmdnm=Gcomparecmdf;                                   //~v76gI~
//      len=sprintf(cmdstr,"%s %s %s %s \"%s\"",COMPARETOOL,pengmode,cmdopt1,pdhfnm1,fpath);//~v76hR~
//      len=sprintf(cmdstr,"%s %s %s %s \"%s\"",pcmdnm,pengmode,cmdopt1,pdhfnm1,fpath);//~v76pR~
        ufilenameenclose(0,fpath,fpath); //required for the case local(if remote enclosed by chkfiletype)//~v76pR~
        len=sprintf(cmdstr,"%s %s %s %s %s",pcmdnm,pengmode,cmdopt1,pdhfnm1,fpath);//~v76pI~
    }                                                              //~v75MI~
    else                                                           //~v75MI~
    {                                                              //~v75MI~
#ifdef FTPSUPP                                                     //~v75MI~
//      if (FILEISREMOTE(pfh2))                                    //~v76pR~
//          return errnotsupported("=(compare)","remote file");    //~v76pR~
#endif                                                             //~v75MI~
//	    if (dlcgetfullnameenclose(pdh2,pdhfnm2))                   //~v75MI~//~vavHR~
#ifdef W32UNICODE                                                  //~vavHR~
        {                                                          //~vavHR~
            int opt3,rc3;                                          //~vavHR~
////          opt3=DLCGFEO_ENCUD|DLCGFEO_STRIPUD;                  //~vavHR~
//            opt3=DLCGFEO_ENCUD;                                  //~vavHR~
//            rc3=dlcgetfullnameenclose(opt3,pdh2,pdhfnm2);        //~vavHR~
//            if (rc3==2) //UD string strip and enclosed           //~vavHR~
//                strcat(cmdoptu8," " U8OPT2);                     //~vavHR~
//            else                                                 //~vavHR~
//          opt3=DLCGFEO_ALIAS;                                    //~vavHR~//~vavMR~
            opt3=0;//xfc support UD string fnm                     //~vavMI~//~vavNR~
            rc3=dlcgetfullnameenclose(opt3,pdh2,pdhfnm2);          //~vavHR~
	        if (rc3 && rc3!=2)	//rc=2 alias used                  //~vavHI~
                return 4;                                          //~vavHR~
        }                                                          //~vavHR~
#else                                                              //~vavHR~
  	    if (dlcgetfullnameenclose(0/*opt*/,pdh2,pdhfnm2))          //~vavHI~
            return 4;                                              //~v75MI~
#endif                                                             //~vavHR~
	    rc2=dlcmdgetcmdparm(Ppcw,plh2,cmdparm2,&len2,cmdopt2,fnm2);//~v75MI~
	    if (rc2>1)                                                 //~v75MI~
    		return rc2;                                            //~v75MI~
        pfnm1=pdhfnm1,pfnm2=pdhfnm2;  //default 1st files on upper line(reverse processing)//~v75MR~
        if (len1 && len2)	//both line contains cmd parm          //~v75MI~
        {                                                          //~v75MI~
        	if (pfh1!=pfh2)	//screen split                         //~v75MI~
            {                                                      //~v75MI~
                if (pfh==pfh1)                                     //~v75MI~
                	pfnm1=pdhfnm1,pfnm2=pdhfnm2; //1st file is of "Enter"ed screen//~v75MI~
                else                                               //~v75MI~
                	pfnm1=pdhfnm2,pfnm2=pdhfnm1;                   //~v75MI~
            }                                                      //~v75MI~
        }                                                          //~v75MI~
        else                                                       //~v75MI~
        if (len1)                                                  //~v75MI~
            pfnm1=pdhfnm1,pfnm2=pdhfnm2;  //1st file is line of cmd parm//~v75MI~
        else                                                       //~v75MI~
        if (len2)                                                  //~v75MI~
            pfnm1=pdhfnm2,pfnm2=pdhfnm1;  //1st file is line of cmd parm//~v75MI~
#ifdef FTPSUPP                                                     //~v76pI~
        rc=dlccompchkfiletype(pdhfnm1,pdhfnm2,&puftph1,&puftph2,&dirsw1,&dirsw2);//~v76pR~
        if (rc)                                                    //~v76pI~
            return 4;                                              //~v76pI~
#endif                                                             //~v76pI~
        if (dirsw1 && dirsw2)                                      //~v76hI~
//      	pcmdnm=COMPARETOOLDIR;                                 //~v76gR~
        	pcmdnm=Gcomparecmdd;                                   //~v76gI~
        else                                                       //~v76hI~
//      	pcmdnm=COMPARETOOL;                                    //~v76gR~
        	pcmdnm=Gcomparecmdf;                                   //~v76gI~
//      len=sprintf(cmdstr,"%s %s %s %s %s %s",COMPARETOOL,pengmode,cmdopt1,cmdopt2,pfnm1,pfnm2);//~v76hR~
//#ifdef W32UNICODE                                                //~vavHR~
//       if (*cmdoptu8)                                            //~vavHR~
//        len=sprintf(cmdstr,"%s %s %s %s %s %s %s",pcmdnm,pengmode,cmdoptu8,cmdopt1,cmdopt2,pfnm1,pfnm2);//~vavHR~
//       else                                                      //~vavHR~
//#endif                                                           //~vavHR~
        len=sprintf(cmdstr,"%s %s %s %s %s %s",pcmdnm,pengmode,cmdopt1,cmdopt2,pfnm1,pfnm2);//~v76hI~
    }                                                              //~v75MI~
    rc=dcmd_comparedlcmd(Ppcw,cmdstr,len,redirectfnm,redirectctr); //~v75MR~
	UCBITOFF(pdh1->UDHflag,UDHFLCMDIN2|UDHFDDSETUP);//set pro at ddsetup//~v75MI~
    if (pdh2)                                                      //~v75MI~
		UCBITOFF(pdh2->UDHflag,UDHFLCMDIN2|UDHFDDSETUP);//set pro at ddsetup//~v75MI~
//edit/browse redirect file at last                                //~v75MI~
    pc=cmdstr;                                                     //~v75MI~
  if (Scompcmdcpu8)                                                //~vbj1R~
    pc+=sprintf(pc,"%c %s %s %s",(dlcmdbecmdid(Ppcw,plc)?'e':'b'),redirectfnm,MODE_UTF8,MODE_IE);//~vbj1R~
  else                                                             //~vbj1R~
    pc+=sprintf(pc,"%c %s",(dlcmdbecmdid(Ppcw,plc)?'e':'b'),redirectfnm);//~v75MI~
//  len=(int)((ULONG)pc-(ULONG)cmdstr);                            //~v75MI~//~vafkR~
    len=(int)((ULPTR)pc-(ULPTR)cmdstr);                            //~vafkI~
    rc=funcsetlongcmd(Ppcw,1,cmdstr,len,0); //1:execute(put on cmd buff),0:no output len//~v75MI~
    Ppcw->UCWreason=UCWRCMDSET; //do not clear at func_exec_pan    //~v75MI~
  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr                 //~v75MI~
    return rc;                                                     //~v75MI~
}//dlcmdcompare                                                    //~v75MI~
#ifdef FTPSUPP                                                     //~v76pI~
//**************************************************************** //~v76pI~
// copy to local if remote is file,err if remote is dir            //~v76pI~
//*ret  :4,remote is dir,8:ffile not found:                        //~v76pI~
//**************************************************************** //~v76pI~
int dlccompchkfiletype(char *Pfnm1,char *Pfnm2,PUFTPHOST *Pppuftph1,PUFTPHOST *Pppuftph2,int *Ppdirsw1,int *Ppdirsw2)//~v76pR~
{                                                                  //~v76pI~
	PUFTPHOST puftph1,puftph2;                                     //~v76pI~
	int dirsw1,dirsw2,rc=0,opt,opt0;                               //~v76pR~
    char lastname[_MAX_PATH];                                      //~v76pI~
    char concatname[_MAX_PATH];                                    //~v76pI~
//**********************                                           //~v76pI~
	puftph1=*Pppuftph1;                                            //~v76pR~
	puftph2=*Pppuftph2;                                            //~v76pI~
//  if (puftph1==(PUFTPHOST)-1)                                    //~v76pR~//~vafkR~
    if (puftph1==(PUFTPHOST)(ULPTR)-1)                             //~vafkI~
    {                                                              //~v76pI~
        uftpisremote(Pfnm1,&puftph1);                              //~v76pR~
        *Pppuftph1=puftph1;                                        //~v76pI~
    }                                                              //~v76pI~
//  if (puftph2==(PUFTPHOST)-1)                                    //~v76pI~//~vafkR~
    if (puftph2==(PUFTPHOST)(ULPTR)-1)                             //~vafkI~
    {                                                              //~v76pI~
        uftpisremote(Pfnm2,&puftph2);                              //~v76pI~
        *Pppuftph2=puftph2;                                        //~v76pI~
    }                                                              //~v76pI~
	if (!puftph1 && !puftph2)	//both local                       //~v76pR~
    	return 0;                                                  //~v76pI~
	dirsw1=*Ppdirsw1;                                              //~v76pR~
	dirsw2=*Ppdirsw2;                                              //~v76pR~
    for (;;)                                                       //~v76pI~
    {                                                              //~v76pI~
        if (dirsw1<0)   //spec1:unknown                            //~v76pI~
        {                                                          //~v76pI~
            dirsw1=ufileisnormalfile(FINF_ERRMSGALL-FINF_ERRMSGDIR,puftph1,Pfnm1);//~v76pR~
            if (dirsw1>1)	//not file nor dir                     //~v76pR~
                break;                                             //~v76pI~
        }                                                          //~v76pI~
        if (dirsw2<0)   //spec2:unknown                            //~v76pI~
        {                                                          //~v76pI~
            dirsw2=ufileisnormalfile(FINF_ERRMSGALL-FINF_ERRMSGDIR,puftph2,Pfnm2);//~v76pR~
            if (dirsw2>1)	//not file nor dir                     //~v76pI~
                break;                                             //~v76pI~
        }                                                          //~v76pI~
        if (dirsw1 && dirsw2)	//both dir                         //~v76pI~
        {                                                          //~v76pI~
			errnotsupported("=(compare)","remote dir compare");    //~v76pR~
        	rc=4;                                                  //~v76pI~
            break;                                                 //~v76pI~
        }                                                          //~v76pI~
        if (dirsw1)  //dir:file                                    //~v76pI~
        {                                                          //~v76pI~
            if (!ufilegetlastname(0,puftph2,Pfnm2,lastname))//outlen=0 err//~v76pR~
            {                                                      //~v76pR~
                rc=4;                                              //~v76pR~
                break;                                             //~v76pR~
            }                                                      //~v76pR~
            ufileconcatlastname(0,puftph1,Pfnm1,lastname,concatname);//~v76pR~
            strcpy(Pfnm1,concatname);                              //~v76pR~
        }                                                          //~v76pI~
        if (dirsw2)  //file:dir                                    //~v76pI~
        {                                                          //~v76pI~
            if (!ufilegetlastname(0,puftph1,Pfnm1,lastname))//outlen=0 err//~v76pR~
            {                                                      //~v76pR~
                rc=4;                                              //~v76pR~
                break;                                             //~v76pR~
            }                                                      //~v76pR~
            ufileconcatlastname(0,puftph2,Pfnm2,lastname,concatname);//~v76pR~
            strcpy(Pfnm2,concatname);                              //~v76pR~
        }                                                          //~v76pI~
        break;                                                     //~v76pI~
    }//err break                                                   //~v76pI~
    if (rc)                                                        //~v76pI~
        return rc;                                                 //~v76pI~
    opt0=FFPA_WILDPATH|FFPA_WILDMEMB|FFPA_LOCALCOPYIFREMOTEFILE|FFPA_FULLPATHTEMP;//~v76pR~
    if (puftph1)	//spec1:remote file                            //~v76pR~
    {                                                              //~v76pI~
    	if (!dirsw1)                                               //~v76pI~
	        opt=opt0|FFPA_REMOTEFILE;	//already confirmed remote is normal file//~v76pI~
        else                                                       //~v76pI~
        	opt=opt0;                                              //~v76pI~
		if (filefullpatha(opt,0,Pfnm1,0,0,Pfnm1))//get local copy  //~v76pI~
        	return 12;                                             //~v76pI~
        ufilenameenclose(0,Pfnm1,Pfnm1);//enclose if space embedding//~v76pI~
    }                                                              //~v76pI~
    if (puftph2)	//spec1:remote file                            //~v76pR~
    {                                                              //~v76pI~
    	if (!dirsw2)                                               //~v76pI~
	        opt=opt0|FFPA_REMOTEFILE;	//already confirmed remote is normal file//~v76pI~
        else                                                       //~v76pI~
        	opt=opt0;                                              //~v76pI~
		if (filefullpatha(opt,0,Pfnm2,0,0,Pfnm2))//get local copy  //~v76pI~
        	return 12;                                             //~v76pI~
        ufilenameenclose(0,Pfnm2,Pfnm2);//enclose if space embedding//~v76pI~
    }                                                              //~v76pI~
    *Ppdirsw1=dirsw1;                                              //~v76pI~
    *Ppdirsw2=dirsw2;                                              //~v76pI~
    return 0;                                                      //~v76pI~
}//dlccompchkfiletype                                              //~v76pI~
#endif                                                             //~v76pI~
//**************************************************************** //~v75MI~
// dlcmdgetposparm                                                 //~v75MI~
// get positional parm from rename field input                     //~v75MI~
//*ret  :1 no posparm,4 err                                        //~v75MI~
//**************************************************************** //~v75MI~
int dlcmdgetcmdparm(PUCLIENTWE Ppcw,PULINEH Pplh,char *Pparmstr,int *Ppparmlen,char *Pcmdopt,char *Pfnm)//~v75MI~
{                                                                  //~v75MI~
	int len,ii,opdno;                                              //~v75MI~
    char cmdparm[MAXCOLUMN],*pc,*pfnm;                             //~v75MI~
    char *pce;                                                     //~v76rI~
    int len2;                                                      //~v76rI~
#ifdef UNX                                                         //~v75QI~
    int firstparmsw=0;                                             //~v75QI~
#endif //!UNX                                                      //~v75QI~
//*******************                                              //~v75MI~
    *Pparmstr=0;                                                   //~v75MI~
    *Pcmdopt=0;                                                    //~v75MI~
    *Pfnm=0;                                                       //~v75MI~
    if ((len=dirgetflddata(Ppcw,Pplh,PANL310RENAME,Pparmstr))<0)   //~v75MR~
    	return 4;                                                  //~v75MI~
    *Ppparmlen=len;                                                //~v75MI~
    if (!len)                                                      //~v75MI~
    	return 1;	//no posparm                                   //~v75MI~
    UPARSERC(Pparmstr,cmdparm,&opdno,0,",");   //parse out string(accept cr/lf)//~v75MI~
    for (pc=cmdparm,pfnm=0,ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)    //~v75MI~
    {                                                              //~v75MI~
        if (!CMDFLAGCHK(*pc,firstparmsw)) // '-' or '/'            //~v75MI~
            pfnm=pc;                                               //~v75MI~
        else                                                       //~vbj1R~
        {                                                          //~vbj1R~
        	if (!stricmp(pc+1,MODE_UTF8))                          //~vbj1R~
            	Scompcmdcpu8=1;                                    //~vbj1R~
        }                                                          //~vbj1R~
    }                                                              //~v75MI~
    if (!pfnm)  //last posparm                                     //~v75MI~
    {                                                              //~v75MI~
    	strcpy(Pcmdopt,Pparmstr);                                  //~v75MI~
        return 1;                                                  //~v75MI~
    }                                                              //~v75MI~
    strcpy(Pfnm,pfnm);                                             //~v75MI~
    pc=umemrstr(Pparmstr,pfnm,(UINT)len);                                //~v75MI~
    if (!pc)                                                       //~v75MI~
    	return 4;	//logic err                                    //~v75MI~
    pce=pc+strlen(pfnm);	//parm after filename                  //~v76rI~
    if (*(pc-1)=='"' || *(pc-1)=='\'')                             //~v75MR~
    	pc--;                                                      //~v75MI~
    if (*pce=='"' || *pce=='\'')                                   //~v76rI~
    	pce++;                                                     //~v76rI~
    if (pc>Pparmstr)	//multiple opd                             //~v75MI~
	    pc--;	//delm                                             //~v75MR~
//  len=(int)((ULONG)pc-(ULONG)Pparmstr);                          //~v75MI~//~vafkR~
    len=(int)((ULPTR)pc-(ULPTR)Pparmstr);                          //~vafkI~
    if (len)                                                       //~v75MI~
	    memcpy(Pcmdopt,Pparmstr,(UINT)len);                        //~v75MR~
    len2=(int)strlen(pce);                                         //~v76rR~
    if (len2)                                                      //~v76rI~
    {                                                              //~v76rI~
	    memcpy(Pcmdopt+len,pce,(UINT)len2);                        //~v76rI~
        len+=len2;                                                 //~v76rI~
    }                                                              //~v76rI~
    *(Pcmdopt+len)=0;	//drop posparm                             //~v75MI~
    return 0;                                                      //~v75MI~
}//dlcmdgetcmdparm                                                 //~v75MI~
//**************************************************************** //~v76gI~
// func_sendins_dir                                                //~v76gI~
//*ret  :rc                                                        //~v76gI~
//**************************************************************** //~v76gI~
int func_sendins_dir(PUCLIENTWE Ppcw)                              //~v76gI~
{                                                                  //~v76gI~
	return funcsenddir(PANSENDO_INS,Ppcw);                         //~v76gR~
}//func_sendins_dir                                                //~v76gI~
//**************************************************************** //~v76gI~
// func_sendrep_dir                                                //~v76gI~
//*ret  :rc                                                        //~v76gI~
//**************************************************************** //~v76gI~
int func_sendrep_dir(PUCLIENTWE Ppcw)                              //~v76gI~
{                                                                  //~v76gI~
	return funcsenddir(PANSENDO_REP,Ppcw);                         //~v76gR~
}//func_sendrep_dir                                                //~v76gI~
                                                                   //~v76gI~
//**************************************************************** //~v76gI~
// func_senddel_dir                                                //~v76gI~
//*ret  :rc                                                        //~v76gI~
//**************************************************************** //~v76gI~
int func_senddel_dir(PUCLIENTWE Ppcw)                              //~v76gI~
{                                                                  //~v76gI~
	return funcsenddir(PANSENDO_DEL,Ppcw);                         //~v76gI~
}//func_sendrep_dir                                                //~v76gI~
                                                                   //~v76gI~
//**************************************************************** //~v76gI~
// func_sendup_dir                                                 //~v76gI~
//*ret  :rc                                                        //~v76gI~
//**************************************************************** //~v76gI~
int func_sendup_dir(PUCLIENTWE Ppcw)                               //~v76gI~
{                                                                  //~v76gI~
	return funcsenddir(PANSENDO_UP,Ppcw);                          //~v76gI~
}//func_sendup_dir                                                 //~v76gI~
//**************************************************************** //~v76gI~
// func_senddown_dir                                               //~v76gI~
//*ret  :rc                                                        //~v76gI~
//**************************************************************** //~v76gI~
int func_senddown_dir(PUCLIENTWE Ppcw)                             //~v76gI~
{                                                                  //~v76gI~
	return funcsenddir(PANSENDO_DOWN,Ppcw);                        //~v76gI~
}//func_senddown_dir                                               //~v76gI~
                                                                   //~v76gI~
//**************************************************************** //~v76gI~
// delcmdsend                                                      //~v76gR~
//*ret  :rc                                                        //~v76gI~
//**************************************************************** //~v76gI~
int funcsenddir(int Popt,PUCLIENTWE Ppcw)                          //~v76gI~
{                                                                  //~v76gI~
    PULINEH plh;                                                   //~v76gI~
	PUSCRD psd;                                                    //~v76gI~
//****************************                                     //~v76gI~
	if (!(Popt & (PANSENDO_INS|PANSENDO_REP)))                     //~v76gR~
    	plh=0;                                                     //~v76gI~
    else                                                           //~v76gI~
    {                                                              //~v76gI~
		if (!CSRONFILELINE(Ppcw))				//out of screen    //~v76gR~
        	return errcsrpos();                                    //~v76gR~
        psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                           //~v76gR~
        plh=psd->USDbuffc;                                         //~v76gR~
        if (plh->ULHtype!=ULHTDATA)                                //~v76gR~
            return errcsrpos();                                    //~v76gR~
    }                                                              //~v76gI~
    ERRMSGCLEAR(Ppcw);	//redraw screen hdr line                   //~v76gR~
	return dlcmdsendsub(Popt,Ppcw,plh);                            //~v76gR~
}//funcsenddir                                                     //~v76gR~
//**************************************************************** //~v76gI~
// dlcmdsend                                                       //~v76gR~
// send filename to utility panel                                  //~v76gR~
//*ret  :rc                                                        //~v76gI~
//**************************************************************** //~v76gI~
int dlcmdsend(PUCLIENTWE Ppcw,PUDLCMD Pplc1,PUDLCMD Pplc2)         //~v76gI~
{                                                                  //~v76gI~
    PULINEH plh;                                                   //~v76gI~
    int opt;                                                       //~v76gI~
//*******************                                              //~v76gI~
    plh=Pplc1->UDLCplh;                                            //~v76gI~
	if (UCBITCHK(Gscrstatus,GSCRSINS))	//insert mode              //~v76gR~
        opt=PANSENDO_INS;                                          //~v76gI~
    else                                                           //~v76gI~
        opt=PANSENDO_REP;                                          //~v76gI~
	return dlcmdsendsub(opt,Ppcw,plh);                             //~v76gR~
}//dlcmdsend                                                       //~v76gI~
//**************************************************************** //~v76gI~
// dlcmdsendsub                                                    //~v76gR~
// send filename to utility panel                                  //~v76gI~
//*ret  :rc                                                        //~v76gI~
//**************************************************************** //~v76gI~
int dlcmdsendsub(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh)            //~v76gR~
{                                                                  //~v76gI~
	PUCLIENTWE pcw2;                                               //~v76gI~
//  PUFILEH pfh;                                                   //~v76pR~
    PUDIRLH pdh;                                                   //~v76gI~
    UCHAR  pdhfnm[_MAX_PATH];                                      //~v76gI~
	int rc,panelid;                                                //~v76gI~
//*******************                                              //~v76gI~
	if (Pplh)	//ins or rep                                       //~v76gI~
    {                                                              //~v76gI~
//    	pfh=UGETPFH(Pplh);                                         //~v76pR~
    	pdh=UGETPDH(Pplh);                                         //~v76gR~
//#ifdef FTPSUPP                                                   //~v76pR~
//        if (FILEISREMOTE(pfh))                                   //~v76pR~
//            return errnotsupported("^(send)","remote file");     //~v76pR~
//#endif                                                           //~v76pR~
//  	if (dlcgetfullnameenclose(pdh,pdhfnm))                     //~v76gR~//~vavHR~
    	if (dlcgetfullnameenclose(0/*opt*/,pdh,pdhfnm))            //~vavHI~
    		return 4;                                              //~v76gR~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
    	*pdhfnm=0;                                                 //~v76gI~
    pcw2=scrgetcw(-1);	//other split screen                       //~v76gR~
    if (pcw2)                                                      //~v76gI~
		panelid=((PUPANELC)(pcw2->UCWppc))->UPCid;					//UPANELC//~v76gR~
    else                                                           //~v76gI~
    	panelid=0;                                                 //~v76gI~
    if (!(panelid & PANUTIL))                                      //~v76gI~
    {                                                              //~v76gI~
        uerrmsg("Screen is not split for valid receive screen",    //~v76gR~
            	"正当な送られる画面が画面分割で開かれていません"); //~v76gR~
        return 4;                                                  //~v76gI~
    }                                                              //~v76gI~
    rc=panutilreceive(Popt,Ppcw,pcw2,panelid,pdhfnm);              //~v76gR~
    return rc;                                                     //~v76gI~
}//dlcmdsendsub                                                    //~v76gR~
//**************************************************************** //~v76gI~
// dlcmdsenddnd                                                    //~v76gI~
// send filename by drag drop or al+i/r key                        //~v76pR~
//*ret  :rc                                                        //~v76gI~
//**************************************************************** //~v76gI~
int dlcmdsenddnd(int Popt,PUCLIENTWE Ppcw)                         //~v76gI~
{                                                                  //~v76gI~
	int rc,panelid,yy,opt;                                         //~v76gR~
    char enclosed[_MAX_PATH+2];                                    //~v76gI~
    char *pfnm;                                                    //~v76gI~
    int rc2;                                                       //~vagyI~
//*******************                                              //~v76gI~
	pfnm=Ppcw->UCWparm;                                            //~v76gI~
    yy=Ppcw->UCWrcsry;                                             //~v76gR~
    opt=PANSENDO_CMD;                                              //~v76gI~
#ifdef WXEXXE                                                      //~v76gI~
  	if (Gwxestat & GWXES_CMD)	//cmd from wxe                     //~v76gI~
    {                                                              //~v76gI~
    	if (Ppcw->UCWopdno<2)           //funccmd created already  //~v76gI~
        	return 4;                                              //~v76gI~
	    pfnm=Ppcw->UCWopdpot;                                      //~v76gI~
    	yy=atoi(pfnm);                                             //~v76jR~
        pfnm+=strlen(pfnm)+1;                                      //~v76gR~
        opt|=PANSENDO_DND;                                         //~v76gI~
    }                                                              //~v76gI~
#endif                                                             //~v76gI~
	panelid=((PUPANELC)(Ppcw->UCWppc))->UPCid;					//UPANELC//~v76gI~
    if (!(panelid & PANUTIL))                                      //~v76gI~
    {                                                              //~v76gI~
        uerrmsg("Screen is utilty panel",                          //~v76gI~
            	"画面がユーティリティー画面でない");               //~v76gI~
        rc=4;                                                      //~v76gI~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
    {                                                              //~v76gI~
        if (!pfnm)                                                 //~v77aI~
        {                                                          //~v77aI~
            if (Ppcw->UCWkeytype==UCWKTCMD)                        //~v77aR~
                return errmissing();                               //~v77aI~
            uerrmsg("Use on the dir-list panel",0);                //~v77aI~
            return 4;                                              //~v77aI~
        }                                                          //~v77aI~
      rc2=                                                         //~vagyI~
        uparsecmdin(pfnm,enclosed,sizeof(enclosed),0);  //0:no need outlen//~v76gI~
      	if (rc2>=4)	//1:enclosed by space embedding                //~vagyI~
      		return rc2;                                            //~vagyI~
    	rc=panutilreceive(Popt|opt|yy,Ppcw,Ppcw,panelid,enclosed); //~v76gR~
    }                                                              //~v76gI~
#ifdef WXEXXE                                                      //~v76gI~
	setflddata(Ppcw,CMDLINENO,0,"");                               //~v76gI~
#endif                                                             //~v76gI~
    return rc;                                                     //~v76gI~
}//dlcmdsenddnd                                                    //~v76gI~
