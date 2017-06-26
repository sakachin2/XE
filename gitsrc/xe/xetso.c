//*CID://+vb7eR~:                             update#=  536;       //+vb7eR~
//*************************************************************
//*xetso.c
//**interface to xe3270
//*************************************************************
//vb7e:170108 FTP crash by longname                                //+vb7eI~
//vb72:161212 (Win10) missing error.h , use winerror.h             //~vb72I~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vb2C:160221 W32 compiler warning                                 //~vb2CI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va90:110520 ANDROID porting                                      //~va90R~
//v79n:080824 (BUG)bin opt remains when save to tso file(not save to itself case)//~v79nR~
//v9@6:080717 3270:TSO cmd initial 3270/TSO mode option            //~v9@6I~
//v8@F:080629 3270:NUMSTD consideration when SJIS=>EBC translation(SO/SI insert case)//~v8@FI~
//v8@B:080627 3270:submit cmd support by TSO SUBMIT cmd(cmd->3270, add TSO/cmd)//~v8@BI~
//v8@A:080626 3270:TSOE spfinfo has seconds of update timestamp,unse it for updatechk//~v8@AI~
//v8@w:080625 3270:issue STOW failed msg                           //~v8@wI~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v8@g:080618 subcmd alias Action for tso cmd                      //~v8@gI~
//v765:070531 (LNX:BUG)support "Konsole" as one of X-terminal      //~v765I~
//v731:061226 filesize>4GB support                                 //~v731I~
//v72E:061205 3270:add tso subcmd "cmd" to enter Enter/PA1 etc     //~v72EI~
//v72D:061205 3270:allow alloc cmd before logon(set pswd)          //~v72DI~
//v72B:061205 3270:like rsh,use =6 panel as TSO terminal screen "tso "tostid TSO"/Exit//~v72BI~
//v72y:061203 3270:expand changing wildcard mask is not effective  //~v72yI~
//v72u:061202 3270:tso spf cmd support                             //~v72uI~
//v72r:061129 3270:initialy lineno display for TSO SPF             //~v72rI~
//v72q:061129 3270:tso alloc fail by "quatation dropped            //~v72qI~
//v72n:061127 3270:spf cmd to update spf info                      //~v72nI~
//v727:061119 3270:optionaly use xe4s001z to list pds member and display spf info//~v727I~
//v725:061117 3270:conf file support                               //~v725I~
//v71V:061113 add tabclear option to edit cmd. TC|NTC. set TC on if -F specified.//~v71VI~
//v71R:061111 3270:check after save by reloading and keep result in workdir//~v71RI~
//v71K:061103 NONUM option for TSO SPF file(reset dfault num fld)  //~v71KI~
//v71H:061103 (3270)for RECFM=F,set UFHlrecl                       //~v71HI~
//v71z:061024 3270:"." dirlsit lcmd for path, xxx.* is generated,it should be xxx//~v71zI~
//v71p:061021 (BUG:3270)edit err when 2nd ref+wildcard mask such as ^*/*KK//~v71pI~
//v71n:061020 3270:add alloc/free cmd                              //~v71nI~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v71e:061011 3270:Rename/delete support                           //~v71eI~
//v71a:061005 3270:dirlist:display filesize if once downloaded from localfile//~v71aI~
//v717:060926 3270:dirlist support                                 //~v717I~
//v716:060926 3270:"listds" cmd to chk file exist/dsorg            //~v716I~
//v715:060221 (LNX)3270 ftp support(hostfile,TSO command)          //~v715I~
//v70z:060904 3270 ftp support(hostfile,TSO command)
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef W32                                                         //~v70zI~
#include <io.h>
    #ifdef WIN10                                                   //+v6BkI//~vb72I~
		#include <winerror.h>                                      //~vb72I~
    #else                                                          //~vb72I~
#include <error.h>                                                 //~v71eI~
    #endif                                                         //~vb72I~
#include <errno.h>                                                 //~v71eR~
#endif                                                             //~v70zI~
#ifdef ARM                                                         //~va90R~
	#include <pthread.h>                                           //~va90R~
#endif                                                             //~va90R~

//*******************************************************
#include <ulib.h>
#include <ualloc.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ufile3.h>
#include <ufile5.h>
#include <ustring.h>
#include <uedit.h>
#include <uproc.h>
#include <uftp.h>
#include <utrace.h>
#include <uparse.h>                                                //~v72qI~
#include <u3270.h>
#include <u32702.h>                                                //~v71gI~
#include <ufemsg.h>                                                //~vb72I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefunc.h"
#include "xeftp.h"
#include "xesub.h"
#include "xedir.h"                                                 //~v717I~
#include "xe3270.h"
#include "xetso.h"
#include "xeerr.h"
#include "xepan.h"                                                 //~v72BI~

#ifdef FTPSUPP

//****************************************************************
#define TSO_POSTFIX_UPDATECHK  ".UPDATECHK"                        //~v71RI~
//**************************************************************** //~v71RI~
static int Sftpopt;
static char Sserverstartcmd[128+_MAX_PATH];
//****************************************************************
int xetsosetspf(PUFILEH Ppfh,PPDSSPFINFO Ppspfi);                  //~v72nI~
int setupspfcmdopt(PUFTPHOST Ppftph,char *Popd,int Popdno,char *Pout);//~v72uR~
//****************************************************************
//xetsoinit
//****************************************************************
int xetsoinit(int Popt)
{
	int opt=0;
    char fpath[_MAX_PATH];
    char cmdwk[_MAX_PATH+128];                                     //~v715I~
    void *parg[4];                                                 //~v715R~
//*****************************::
	Sftpopt=Popt;
    if (Popt & XEFTP_LOG)
		opt|=XE3270OPT_LOG;	//alwas log append mode
	if (Popt & XEFTP_APPEND)
		opt|=XE3270OPT_APPENDLOG;	//alwas log append mode
    if (Gotheropt & GOTHERO_TRACEON)                               //~v716I~
		opt|=XE3270OPT_TRACE;		//trace on                     //~v716I~
    filefullpath(fpath,WORKDIRPATHID XE3270_DEFAULT_LOGFILE,sizeof(fpath));
//	sprintf(cmdwk,"%s -L%s %d",XE3270SERVER,fpath,opt);            //~v725R~
  	sprintf(cmdwk,"%s -L%s -W%s %d",XE3270SERVER,fpath,Gworkdir,opt);//~v725I~
#ifdef LNX                                                         //~v765I~
    ulnxxgettermpgmopt(0,cmdwk,Sserverstartcmd); //spawn async     //~v765R~
#else                                                              //~v765I~
  	sprintf(Sserverstartcmd,XE3270_STARTCMD,cmdwk);                //~v715R~
#endif                                                             //~v765I~
    parg[0]=Sserverstartcmd;                                       //~v715I~
    parg[1]=XE3270PIPE;                                            //~v715I~
//  parg[2]=(void*)(ULONG)(UCBITCHK(Gopt,GOPTNOFTP));	//nop mode //~v715R~//~vafkR~
    parg[2]=(void*)(ULPTR)(UCBITCHK(Gopt,GOPTNOFTP));	//nop mode //~vafkI~
//  u3270init((void**)(ULONG)parg);                                //~v715I~//~vafkR~
    u3270init((void**)(ULPTR)parg);                                //~vafkI~
    return 0;
}//xetsoinit
//****************************************************************
// send cmd to xe3270
//*rc   :0
//****************************************************************
int func_tso(PUCLIENTWE Ppcw)
{
    PUFTPHOST puftph=NULL;                                         //~vafcR~
    PUPODELMTBL pdelmt;                                            //~v72qI~
    char cmd[MAX_CMDSZ],*phostid,*psubcmd,*ptext=0,*popd,*pc,*popt=0,*popt2=0;//~v72uR~
//  char pswd[FTP_PSWDNAMELEN+2];                                  //~v72DR~
    char fpdsn[DSN_MAXLEN];                                        //~v72uI~
    int rc,opdno,stringcmdsw,logoncmdsw,quitsw,optionsw;           //~v71nR~
    int spfsw;                                                     //~v72uI~
    int logoffcmdsw,logonopt=0;                                    //~v72ER~
    int cmdcmdsw;                                                  //~v72ER~
    int actionsw;                                                  //~v8@BI~
//*********************************
	if (!Ppcw->UCWparm)		//operand
    {
//      uerrmsg("TSO hostid { %s | %s | Logoff | Cancel | %s [\"text..\"] | {%s | %s} hostfile [options] }",0,//~v72uR~
//      uerrmsg("TSO hostid { %s | %s | Logoff | Cancel | %s [\"text..\"] | {%s|%s|%s} hostfile [options] }",0,//~v72BR~
//      uerrmsg("TSO hostid { %s | %s | %s | Cancel | %s [\"text..\"] | {%s|%s|%s} hostfile [options] }",0,//~v72ER~
//      uerrmsg("TSO hostid { %s | %s [FS] | %s | Cancel | {%s|%s} [\"text..\"] | {%s|%s|%s} hostfile [options] }",0,//~v8@gR~
//      uerrmsg("TSO hostid { %s | %s [FS] | %s | Cancel | {%s|{%s|%s}} [\"text..\"] | {%s|%s|%s} hostfile [options] }",0,//~v8@BR~
//      uerrmsg("TSO hostid { %s | %s [FS] | %s | Cancel | {%s|%s|%s} [\"text..\"] | {%s|%s|%s} hostfile [options] }",0,//~v9@6R~
        uerrmsg("TSO hostid { %s | %s [FS|FS3|FST] | %s | Cancel | {%s|%s|%s} [\"text..\"] | {%s|%s|%s} hostfile [options] }",0,//~v9@6I~
					XE3270_SUBCMD_QUIT,
					XE3270_SUBCMD_LOGON,
					XE3270_SUBCMD_LOGOFF,                          //~v72BI~
					XE3270_SUBCMD_STRING,                          //~v71nR~
					XE3270_SUBCMD_CMD,                             //~v72EI~
					XE3270_SUBCMD_ACTION,                          //~v8@gI~
					XE3270_SUBCMD_ALLOC,                           //~v71nI~
					XE3270_SUBCMD_FREE                             //~v71nI~
					,XE3270_SUBCMD_SPF                             //~v72uI~
					);                                             //~v71nI~
        return 0;
    }
    opdno=Ppcw->UCWopdno;           //funccmd created already
    popd=Ppcw->UCWopdpot;
    pdelmt=Ppcw->UCWopddelmt; 	//cmd operand delm table           //~v72qI~
    phostid=popd;                      //1st parm;                 //~v715I~
    psubcmd=phostid+strlen(phostid)+1;	//2nd parm                 //~v715R~
    if (opdno>=3)                                                  //~v71nI~
    {                                                              //~v71nI~
	    popt=psubcmd+strlen(psubcmd)+1;	//hostfilename             //~v71nR~
	    if (opdno>=4)                                              //~v71nI~
		    popt2=popt+strlen(popt)+1;  //alloc options            //~v71nI~
    }                                                              //~v71nI~
    stringcmdsw=!stricmp(psubcmd,XE3270_SUBCMD_STRING);
    cmdcmdsw=!stricmp(psubcmd,XE3270_SUBCMD_CMD);                  //~v72EI~
//  cmdcmdsw|=!stricmp(psubcmd,XE3270_SUBCMD_ACTION);              //~v8@BR~
    actionsw=!stricmp(psubcmd,XE3270_SUBCMD_ACTION);               //~v8@BR~
    stringcmdsw|=cmdcmdsw;                                         //~v72ER~
    stringcmdsw|=actionsw;                                         //~v8@BI~
    spfsw=!stricmp(psubcmd,XE3270_SUBCMD_SPF);                     //~v72uI~
    optionsw=  !stricmp(psubcmd,XE3270_SUBCMD_ALLOC)               //~v71nI~
            || spfsw                                               //~v72uI~
            || !stricmp(psubcmd,XE3270_SUBCMD_FREE);               //~v71nI~
    logoncmdsw=!stricmp(psubcmd,XE3270_SUBCMD_LOGON);
    logoffcmdsw=!stricmp(psubcmd,XE3270_SUBCMD_LOGOFF);            //~v72BI~
    quitsw=!stricmp(psubcmd,XE3270_SUBCMD_QUIT)                    //~v716R~
           ||!stricmp(phostid,XE3270_SUBCMD_QUIT);                 //~v716R~
    if (!quitsw)
    {
        if (opdno<2)
                return errmissing();
        if (logoncmdsw)                                            //~v72EI~
        {                                                          //~v72EI~
            if (opdno>2)    //logon option                         //~v72EI~
            {                                                      //~v72EI~
            	pc=psubcmd+strlen(psubcmd)+1;    //3rd parm logon option//~v72EI~
                if (!stricmp(pc,"FS3"))                            //~v9@6I~
                	logonopt|=XETSOCMDO_LOGONFS3270;	//fullscreen mode//~v9@6I~
                else                                               //~v9@6I~
                if (!stricmp(pc,"FST"))                            //~v9@6I~
                	logonopt|=XETSOCMDO_LOGONFS3270TSO; //fullscreen mode//~v9@6R~
                else                                               //~v9@6I~
                if (stricmp(pc,"FS"))                              //~v72EI~
                {                                                  //~v72EI~
	                uerrmsg("Invalid logon option(%s)",0,          //~v72EI~
							pc);                                   //~v72EI~
    		        return 4;                                      //~v72EI~
                }                                                  //~v72EI~
                logonopt|=XETSOCMDO_LOGONFS;	//fullscreen mode  //~v72EI~
            }                                                      //~v72EI~
        }                                                          //~v72EI~
        if (stringcmdsw)
        {
            if (opdno<3)
                return errmissing();
            else
            if (opdno>3)
            {
//              uerrmsg("enclose by quotation for %s cmd text parameter",0,//~v72ER~
//                      XE3270_SUBCMD_STRING);                     //~v72ER~
                uerrmsg("enclose by quotation for \"%s\" cmd text parameter",//~v72EI~
						"\"%s\"コマンドのテキストパラメータは全体を引用符で囲んでください",//~v72ER~
                        psubcmd);                                  //~v72EI~
                return 4;
            }
            ptext=psubcmd+strlen(psubcmd)+1;    //2nd parm         //~v716R~
        }
        else
        if (optionsw)	//not string cmd but additional operand required//~v71nI~
        {                                                          //~v71nI~
            if (opdno<3)                                           //~v71nI~
                return errmissing();                               //~v71nI~
            if ((pdelmt+2)->upoquate=='\'')                        //~v72qR~
            	optionsw=2;                                        //~v72qI~
            if (popt2)	//alloc options                            //~v71nI~
	            ptext=strstr(Ppcw->UCWparm,popt2);                 //~v71nR~
        }                                                          //~v71nI~
        else                                                       //~v71nI~
            ptext=0;
        sprintf(cmd,"%s:",phostid);
        uftpisremote(cmd,&puftph); //remote hostname prefix exist
        if (!puftph)
        {
            uerrmsg("hostid \"%s\" is not registered on ::xehost file",0,
                        phostid);
            return 4;
        }
        if (!UFTPHISTSO(puftph))
        {
            uerrmsg("hostid \"%s\" is not registered as 3270 host on ::xehost file",0,
                        phostid);
            return 4;
        }
//        if (logoncmdsw && *puftph->UFTPHpswd)                    //~v72DR~
//        {                                                        //~v72DR~
//            *pswd='/';                                           //~v72DR~
//            uftphostscrypt(1,puftph->UFTPHpswd,pswd+1);          //~v72DR~
//        }                                                        //~v72DR~
//        else                                                     //~v72DR~
//            *pswd=0;                                             //~v72DR~
//        pc=cmd+sprintf(cmd,"%s %s:%d %s%s",                      //~v72DR~
//                        psubcmd,                                 //~v72DR~
//                        puftph->UFTPHipad,  //hostname           //~v72DR~
//                        puftph->UFTPHport,  //portno             //~v72DR~
//                        puftph->UFTPHuser,  //username           //~v72DR~
//                        pswd);              //password           //~v72DR~
		pc=cmd+u3270sethostuser(puftph,psubcmd,cmd);               //~v72DI~
        if (optionsw)	//not string cmd but additional operand required//~v71nI~
        {                                                          //~v71nI~
            *pc++=' ';                                             //~v71nI~
          if (optionsw==2)                                         //~v72qI~
            pc+=sprintf(pc,"'%s'",popt); //host filename with quatation//~v72qI~
          else                                                     //~v72qI~
          {                                                        //~v72uI~
           if (spfsw)                                              //~v72uI~
           {                                                       //~v72uI~
            u3270fullpath(puftph,fpdsn,popt,sizeof(fpdsn)); //curdir or userid append//~v72uR~
            pc+=sprintf(pc,"%s",fpdsn+puftph->UFTPHhostnmlen+1); //host filename//~v72uI~
           }                                                       //~v72uI~
           else                                                    //~v72uI~
            pc+=sprintf(pc,"%s",popt); //host filename             //~v71nI~
          }                                                        //~v72uI~
        }                                                          //~v71nI~
        if (spfsw)                                                 //~v72uI~
        {                                                          //~v72uI~
        	if (!popt2)                                            //~v72uI~
            {                                                      //~v72uI~
                uerrmsg("missing spf update info parameter",0);    //~v72uR~
                return 4;                                          //~v72uI~
            }                                                      //~v72uI~
            if (setupspfcmdopt(puftph,popt2,opdno-3,pc))           //~v72uR~
                return 4;                                          //~v72uI~
        }                                                          //~v72uI~
        else                                                       //~v72uI~
        if (ptext)
        {
            *pc++=' ';
            sprintf(pc,"\"%s\"",ptext); //enclose to keep "," in text//~v71nR~
        }
    }
    else
    {
        strcpy(cmd,XE3270_SUBCMD_QUIT);
    }
    rc=u3270cmdrequest(U3CRO_UERRMSG,cmd,0,0);                     //~v715R~
    if (rc==U3CR_RC_DONE)   //rc for success msg display           //~v71nI~
        rc=0;                                                      //~v71nI~
    if (!rc)                                                       //~v72BI~
    {                                                              //~v72BI~
	 	if (Ppcw->UCWmenuopt==PANMOCMD)                            //~v72BI~
        {                                                          //~v72BI~
    		if (logoncmdsw||logoffcmdsw)                           //~v72BI~
    			rc=xetsotsocmdlogon(logoffcmdsw|logonopt,Ppcw,puftph);//~v72ER~
        }                                                          //~v72BI~
    }                                                              //~v72BI~
    return rc;
}//func_tso
//****************************************************************
//xetsoxcopy
//ret XE3270RC_NEWMEMBER if dsn valid and member not found
//****************************************************************
int xetsoxcopy(int Popt,PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,
//  		UCHAR *Psource,UCHAR *Ptarget,int Pcopyopt,unsigned Pattrmask)//~v8@sR~
    		UCHAR *Psource,UCHAR *Ptarget,int Pcopyopt,unsigned Pattrmask,/*PUTSOFTPPARM*/ void *Putsop)//~v8@wR~
{
    UTSOFTPPARM utsop,*putsop;                                     //~v8@BI~
    int copyopt;                                                   //~v71gI~
//********************
    copyopt=Pcopyopt;                                              //~v71gI~
    if (Popt & XETSOXCOPY_BIN)                                     //~v71gI~
        copyopt=DCPY_BIN;                                          //~v71gI~
  if ((Popt & XEFTP_GRC_PARMDIR))	//target is not dir            //~v71gI~
    return u3270xcopy(copyopt,Ppuftphs,Ppuftpht,Psource,Ptarget,Pattrmask);//~v71gI~
  else                                                             //~v71gI~
  {                                                                //~v8@BI~
    putsop=&utsop;                                                 //~v8@BI~
    if (Popt & XETSOXCOPY_SETBYTGTF)                               //~v8@BI~
//      xetsosetftpparm(XETSOFTPO_DBCSCONV|XETSOFTPO_FPATH,Ppuftpht,&utsop,Ptarget); //set tso parm to puftph//~v8@FR~
        xetsosetftpparm(XETSOFTPO_DBCSCONV|XETSOFTPO_FPATH|XETSOFTPO_CHKPROF,Ppuftpht,&utsop,Ptarget); //set tso parm to puftph//~v8@FR~
    else                                                           //~v8@BI~
    if (Popt & XETSOXCOPY_SETBYSRCF)                               //~v8@BI~
        xetsosetftpparm(XETSOFTPO_DBCSCONV|XETSOFTPO_FPATH,Ppuftphs,&utsop,Psource); //set tso parm to puftph//~v8@BR~
    else                                                           //~v8@BI~
    	putsop=Putsop;                                             //~v8@BI~
//  return u3270transfer(copyopt,Ppuftphs,Ppuftpht,Psource,Ptarget);//~v8@sR~
    return u3270transfer(copyopt,Ppuftphs,Ppuftpht,Psource,Ptarget,putsop);//~v8@BR~
  }                                                                //~v8@BI~
}//xetsoxcopy
//****************************************************************
//xetsosave
//save(upload) to TSO
//****************************************************************
int xetsosave(int Popt,PUFILEH Ppfh,PUFTPHOST Ppuftpht,
			UCHAR *Psource,UCHAR *Ptarget,int Pcopyopt,unsigned Pattrmask)
{
    char localfile[_MAX_PATH];
    char *phostfile,*appendfile;
    FILEFINDBUF3 ffb3;                                             //~v72nR~
    int  rc,opt,opt2=0;                                            //~v72nR~
    int  opt3=0;                                                   //~v8@FI~
    UTSOFTPPARM tsop;                                              //~v8@sR~
//********************
   if (Popt & XETSOSO_OUTFILE)	//not save to my self              //~v79nR~
   	opt=0;	//not bin mode save                                    //~v79nR~
   else                                                            //~v79nR~
    opt=((UCBITCHK(Ppfh->UFHflag4,UFHF4BIN)|UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))!=0)*XEFTPO_BIN;
  	if (!(Pcopyopt & DCPY_APPEND))            //not append req
    {                                                              //~v72nI~
		if ( (Popt & XETSOSO_OUTFILE)	//not save to my self      //~v72nI~
        &&  !(Ppfh->UFHattr & FILE_SPF))	//source has no spf info(ufh is copyed from source)//~v72nI~
        {                                                          //~v72nI~
//		    rc=u3270fstat(Ppuftpht,Ptarget,&ffb3);                 //~v72nR~//~vb30R~
  		    rc=(int)u3270fstat(Ppuftpht,Ptarget,&ffb3);            //~vb30I~
            if (rc)                                                //~v72nI~
            {                                                      //~v72nI~
        	    if (rc!=U3CR_RC_NOTFOUND)                          //~v72nI~
            	    return rc;                                     //~v72nR~
                opt2=XETSOSO_OUTNEW;                               //~v72nI~
            }                                                      //~v72nI~
			xetsodefaultlrecl(Ppfh,&ffb3);                         //~v72nR~
        }                                                          //~v72nI~
//      return xetsoxcopy(opt,0,Ppuftpht,Psource,Ptarget,Pcopyopt,Pattrmask);//~v72nR~
//      rc=xetsoxcopy(opt,0,Ppuftpht,Psource,Ptarget,Pcopyopt,Pattrmask);//~v8@sR~
//      xetsosetftpparm(XETSOFTPO_DBCSCONV,Ppuftpht,&tsop,Ppfh); //set tso parm to puftph//~v8@FR~
        opt3=XETSOFTPO_DBCSCONV;                                   //~v8@FI~
		if (Popt & XETSOSO_OUTFILE)	//not save to my self          //~v8@FI~
        	opt3|=XETSOFTPO_CHKPROF;                               //~v8@FI~
        xetsosetftpparm(opt3,Ppuftpht,&tsop,Ppfh); //set tso parm to puftph//~v8@FI~
        rc=xetsoxcopy(opt,0,Ppuftpht,Psource,Ptarget,Pcopyopt,Pattrmask,&tsop);//~v8@sI~
        if (!rc)                                                   //~v72nI~
        {                                                          //~v72nI~
            rc=xetsospfupdate(Popt|opt2,Ppfh,Ppuftpht,Ptarget);    //~v72nR~
            if (rc==U3CR_RC_INUSE)                                 //~v72qI~
                uerrmsg("File saved normaly,But SPF-INFO update failed by \"DATASET-IN-USE\"",//~v72nR~
						"ファイル保存は正常終了しましたが,SPF情報更新がDATASET使用中のため失敗");//~v72nI~
            else                                                   //~v8@wI~
            if (rc==U3CR_RC_STOWFAILED)                            //~v8@wI~
                uerrmsg("File saved normaly,But SPF-INFO update failed by STOW failure(Directory full?)",//~v8@wI~
						"ファイル保存しましたが,SPF情報更新がSTOWエラー(Directory Full?)");//~v8@wR~
        }                                                          //~v72nI~
        return rc;                                                 //~v72nI~
    }                                                              //~v72nI~
//append mode
//  rc=u3270fstat(Ppuftpht,Ptarget,&ffb3);                         //~v72nI~//~vb30R~
    rc=(int)u3270fstat(Ppuftpht,Ptarget,&ffb3);                    //~vb30I~
    if (rc)                                                        //~v72nI~
    {                                                              //~v72nI~
        if (rc!=U3CR_RC_NOTFOUND)                                  //~v72nI~
            return rc;                                             //~v72nI~
        opt2=XETSOSO_OUTNEW;        //copy from source             //~v72nI~
    }                                                              //~v72nI~
    xetsodefaultlrecl(Ppfh,&ffb3);                                 //~v72nI~
                                                                   //~v72nI~
	phostfile=Ptarget;
	appendfile=Ppfh->UFHftpwdfnm;
//  xeftpgetwdfname(Ppuftpht,phostfile,localfile);                 //+vb7eR~
    xeftpgetwdfname(Ppuftpht,phostfile,localfile,sizeof(localfile));//+vb7eI~
    strcat(localfile,"_appended");  //avoid timestamp match
//  rc=xeftpget(Popt,Ppuftpht,phostfile,localfile);	//get target file append to//~v72nR~
//  rc=xeftpget(opt,Ppuftpht,phostfile,localfile);	//get target file append to//~v8@sR~
    xetsosetftpparm(XETSOFTPO_DBCSCONV,Ppuftpht,&tsop,Ppfh); //set tso parm to puftph//~v8@sR~
    rc=xeftpget(opt,Ppuftpht,phostfile,localfile,&tsop);	//get target file append to//~v8@sI~
    if (rc && rc!=U3CR_RC_NOTFOUND)                                //~v71eR~
    	return rc;
    if (rc)	// not exist
    	strcpy(localfile,appendfile);
    else
    {
        rc=uxcopy(appendfile,localfile,DCPY_APPEND,FILE_NORMAL); //append to now downloaded
        if (rc)
            return rc;
        xeftpdelwd(0,appendfile);
        strcpy(Ppfh->UFHftpwdfnm,localfile);    //update pfh,deleted at xeftpsave
        Pcopyopt&=~DCPY_APPEND;
    }
//  return xetsoxcopy(opt,0,Ppuftpht,localfile,Ptarget,Pcopyopt,Pattrmask);//~v72nR~
//  rc=xetsoxcopy(opt,0,Ppuftpht,localfile,Ptarget,Pcopyopt,Pattrmask);//~v8@sR~
    xetsosetftpparm(XETSOFTPO_DBCSCONV,Ppuftpht,&tsop,Ppfh); //set tso parm to puftph//~v8@sR~
    rc=xetsoxcopy(opt,0,Ppuftpht,localfile,Ptarget,Pcopyopt,Pattrmask,&tsop);//~v8@sI~
    if (!rc)                                                       //~v72nI~
    {                                                              //~v72nI~
        rc=xetsospfupdate(Popt|opt2,Ppfh,Ppuftpht,Ptarget);        //~v72nI~
        if (rc==U3CR_RC_INUSE)                                     //~v72nI~
            uerrmsg("File appended normaly,But SPF-INFO update failed by \"DATASET-IN-USE\"",//~v72nI~
					"ファイルへの追加は正常終了しましたが,SPF情報更新がDATASET使用中のため失敗");//~v72nI~
    }                                                              //~v72nI~
    return rc;                                                     //~v72nI~
}//xetsosave
//**************************************************************** //~v72nI~
// xetsospfupdate                                                  //~v72nI~
// attrib dlcmd for tso                                            //~v72nI~
//*rc   :0                                                         //~v72nI~
//**************************************************************** //~v72nI~
int xetsospfupdate(int Popt,PUFILEH Ppfh,PUFTPHOST Ppuftph,char *Pfpath)//~v72nR~
{                                                                  //~v72nI~
    int rc,spfopt=0;                                               //~v72nR~
    PDSSPFINFO spfi,spfinew;                                       //~v72nI~
//*******************                                              //~v72nI~
	if (!UCBITCHK(Ppfh->UFHflag8,UFHF8TSOSPF))                     //~v72nR~
    	return 0;                                                  //~v72nI~
    memset(&spfi,0,PDSSPFINFOSZ);                                  //~v72nI~
	if (Popt & XETSOSO_OUTFILE)	//not save to my self              //~v72nI~
    {                                                              //~v72nI~
		if ( (Ppfh->UFHattr & FILE_SPF)	//source has spf info spf info(ufh is copyed from source)//~v72nR~
		&&  !(Popt & XETSOSO_OUTPARTIAL))	//full save            //~v72nI~
        {                                                          //~v72nI~
        	spfi.SPFIver=Ppfh->UFHspfvv;                           //~v72nI~
            if (Ppfh->UFHspfver)			//by lineno            //~v72nI~
            	spfi.SPFImod=Ppfh->UFHspfver;                      //~v72nI~
            else                                                   //~v72nI~
            	spfi.SPFImod=Ppfh->UFHspfmm;                       //~v72nR~
            spfi.SPFIinitcnt=Ppfh->UFHspfinitline;  //keep value at download//~v72nI~
            spfi.SPFIcdate=Ppfh->UFHspfcredate;                    //~v72nI~
            spfi.SPFIudate=Ppfh->UFHfiledate;                      //~v72nI~
            spfi.SPFIutime=Ppfh->UFHfiletime;                      //~v72nI~
            if (FILETSOLRECL(Ppfh))                                //~v72nI~
//              spfi.SPFIlinecnt=Ppfh->UFHsize/FILETSOLRECL(Ppfh); //~v731R~
//              spfi.SPFIlinecnt=(int)(Ppfh->UFHsize/FILETSOLRECL(Ppfh));//~v731I~//~vb31R~
                spfi.SPFIlinecnt=(int)(Ppfh->UFHsize/(FILESZT)FILETSOLRECL(Ppfh));//~vb31I~
            strcpy(spfi.SPFIuserid,Ppuftph->UFTPHuser);            //~v72nI~
            spfopt|=U3270SPFO_VER                                  //~v72nI~
                   |U3270SPFO_MOD                                  //~v72nI~
                   |U3270SPFO_ILINE                                //~v72nI~
                   |U3270SPFO_CDATE                                //~v72nI~
            	   |U3270SPFO_UPDATE                               //~v72nI~
                   |U3270SPFO_CLINE    //count line                //~v72nI~
                   |U3270SPFO_USERID;                              //~v72nI~
		    if (Ppfh->UFHupctr)	//updated                          //~v72nR~
            {                                                      //~v72nI~
        		spfopt|=U3270SPFO_NOWUPDATE  //update date/time    //~v72nI~
                       |U3270SPFO_NOWCLINE;    //count line        //~v72nI~
            	spfi.SPFImod++;                                    //~v72nI~
            }                                                      //~v72nI~
        }                                                          //~v72nI~
        else	//source is pc file or partial output              //~v72nR~
        {                                                          //~v72nI~
            if (Popt & XETSOSO_OUTNEW)	//target is new meber      //~v72nR~
            {                                                      //~v72nI~
		        if (!(Popt & XETSOSO_OUTPARTIAL))	//full save    //~v72nI~
                {                                                  //~v72nI~
                    if (Ppfh->UFHspfver)            //by lineno    //~v72nR~
                    {                                              //~v72nR~
                        spfopt|=U3270SPFO_MOD;                     //~v72nR~
                        spfi.SPFImod=Ppfh->UFHspfver;              //~v72nR~
					    if (Ppfh->UFHupctr)	//updated              //~v72nI~
            				spfi.SPFImod++;                        //~v72nI~
                    }                                              //~v72nR~
                }                                                  //~v72nI~
	            spfopt|=U3270SPFO_NOWILINE                         //~v72nI~
    	               |U3270SPFO_NOWCDATE;  //vv,mm=0             //~v72nI~
            }                                                      //~v72nI~
            else    //replace TSO SPF by pc file                   //~v72nR~
            {                                                      //~v72nI~
    	      	spfi.SPFIver=Ppfh->UFHspfvv;                       //~v72nR~
                spfi.SPFImod=Ppfh->UFHspfmm+1;                     //~v72nI~
		        if (!(Popt & XETSOSO_OUTPARTIAL))	//full save    //~v72nI~
	            	if (Ppfh->UFHspfver)			//by lineno    //~v72nR~
                    {                                              //~v72nI~
    	        		spfi.SPFImod=Ppfh->UFHspfver;              //~v72nR~
					    if (Ppfh->UFHupctr)	//updated              //~v72nI~
            				spfi.SPFImod++;                        //~v72nI~
                    }                                              //~v72nI~
    	        spfi.SPFIinitcnt=Ppfh->UFHspfinitline;             //~v72nR~
    	        spfi.SPFIcdate=Ppfh->UFHspfcredate;                //~v72nR~
            	spfopt|=U3270SPFO_VER                              //~v72nI~
                	   |U3270SPFO_MOD;                             //~v72nR~
            }                                                      //~v72nI~
            strcpy(spfi.SPFIuserid,Ppuftph->UFTPHuser);            //~v72nI~
            spfopt|=U3270SPFO_ILINE                                //~v72nI~
                   |U3270SPFO_CDATE                                //~v72nR~
                   |U3270SPFO_UPDATE|U3270SPFO_NOWUPDATE  //update date/time//~v72nR~
                   |U3270SPFO_CLINE|U3270SPFO_NOWCLINE    //count line//~v72nI~
                   |U3270SPFO_USERID;                              //~v72nI~
        }//source is pc file                                       //~v72nI~
    }                                                              //~v72nI~
    else                                                           //~v72nI~
    {                                                              //~v72nI~
		if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))                       //~v72nI~
        {                                                          //~v72nI~
            spfopt|=U3270SPFO_ILINE|U3270SPFO_NOWILINE             //~v72nR~
                   |U3270SPFO_CDATE|U3270SPFO_NOWCDATE;  //vv,mm=0 //~v72nR~
        }                                                          //~v72nI~
        else                                                       //~v72nI~
        {                                                          //~v72nI~
    		spfi.SPFIver=Ppfh->UFHspfvv;                           //~v72nI~
	        if (Ppfh->UFHspfver)			//by lineno            //~v72nI~
    	        spfi.SPFImod=Ppfh->UFHspfver+1;                    //~v72nI~
            else                                                   //~v72nI~
	    		spfi.SPFImod=Ppfh->UFHspfmm+1;                     //~v72nR~
    		spfi.SPFIinitcnt=Ppfh->UFHspfinitline;	//keep value at download//~v72nI~
    		spfi.SPFIcdate=Ppfh->UFHspfcredate;                    //~v72nR~
            spfopt|=U3270SPFO_VER                                  //~v72nI~
                   |U3270SPFO_MOD                                  //~v72nI~
                   |U3270SPFO_ILINE                                //~v72nI~
                   |U3270SPFO_CDATE;                               //~v72nI~
        }                                                          //~v72nI~
        strcpy(spfi.SPFIuserid,Ppuftph->UFTPHuser);                //~v72nR~
        spfopt|=U3270SPFO_UPDATE|U3270SPFO_NOWUPDATE  //update date/time//~v72nI~
               |U3270SPFO_CLINE|U3270SPFO_NOWCLINE    //count line //~v72nI~
               |U3270SPFO_USERID;                                  //~v72nI~
    }                                                              //~v72nI~
    if (rc=u3270spfupdate(spfopt,Ppfh->UFHpuftph,Pfpath,&spfi,&spfinew),rc)//~v72nR~
    {                                                              //~v72rI~
    	if (rc==U3CR_RC_NOTSUPPORT)                                //~v72rI~
    		return 0;                                              //~v72rI~
    	return rc;                                                 //~v72nI~
    }                                                              //~v72rI~
	if (xetsosetspf(Ppfh,&spfinew))	//update pfh spf info          //~v72nR~
		Ppfh->UFHattr|=FILE_SPF;                                   //~v72nR~
    return 0;                                                      //~v72nI~
}//xetsospfupdate                                                  //~v72nR~
//****************************************************************
//* file update chk at save
//* retrn:rc UALLOC_FAILED or 8(unmatch or cannot compare)
//****************************************************************
int xetsoupdatechk(PUCLIENTWE Ppcw,PUFILEH Ppfh)
{
	char templocalfnm[_MAX_PATH],*phostfilename;
    int rc,rc2,opt;
	PUFTPHOST puftph;
	FILEFINDBUF3 ffb3;                                             //~v716I~
    UTSOFTPPARM tsop;                                              //~v8@sR~
//*****************
    puftph=Ppfh->UFHpuftph;
    phostfilename=Ppfh->UFHfilename;
//  rc=u3270fstat(puftph,phostfilename,&ffb3);	//chk before download because IND$FILE ABDEND 013 then wait infinite//~v716R~//~vb30R~
    rc=(int)u3270fstat(puftph,phostfilename,&ffb3);	//chk before download because IND$FILE ABDEND 013 then wait infinite//~vb30I~
    if (rc==U3CR_RC_OTHER)                                         //~v716I~
    	return -2;		//do not override xe3270 errmsg            //~v716I~
    if (rc==U3CR_RC_INUSE)                                         //~v72qI~
    	return -2;		//do not override xe3270 errmsg            //~v72qI~
    if (rc)	//not found                                            //~v716I~
    {                                                              //~v716I~
        if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))                       //~v716I~
            rc=0;//ok if not exist                                 //~v716I~
        else                                                       //~v716I~
        	rc=8;                                                  //~v716I~
        return rc;                                                 //~v716I~
    }                                                              //~v716I~
    else                                                           //~v716I~
    {                                                              //~v716I~
        if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))                       //~v716I~
            return 8;//someone saved                               //~v716I~
    }                                                              //~v716I~
    if ((ffb3.attrFile & FILE_SPF) && (Ppfh->UFHattr & FILE_SPF))	//spf info gotten//~v8@AI~
    {                                                              //~v8@AI~
    	if (!memcmp(&ffb3.fdateLastWrite,&Ppfh->UFHfiledate,sizeof(FDATE))//~v8@AR~
        &&  !memcmp(&ffb3.ftimeLastWrite,&Ppfh->UFHfiletime,sizeof(FTIME)))//~v8@AR~
        	rc=0;                                                  //~v8@AI~
        else                                                       //~v8@AI~
        	rc=8;                                                  //~v8@AI~
        return rc;       //no file compare if spf info exist       //~v8@AI~
    }                                                              //~v8@AI~
//  xeftpgetwdfname(puftph,phostfilename,templocalfnm);	//get tempname to re-download now//+vb7eR~
    xeftpgetwdfname(puftph,phostfilename,templocalfnm,sizeof(templocalfnm));	//get tempname to re-download now//+vb7eI~
    strcat(templocalfnm,TSO_POSTFIX_UPDATECHK);                    //~v71RI~
    opt=((UCBITCHK(Ppfh->UFHflag4,UFHF4BIN)|UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))!=0)*XEFTPO_BIN;
//  rc=rc2=xeftpget(opt,puftph,phostfilename,templocalfnm);        //~v8@sR~
    xetsosetftpparm(XETSOFTPO_DBCSCONV|XETSOFTPO_FFB3,puftph,&tsop,&ffb3);//~v8@sR~
    rc=rc2=xeftpget(opt,puftph,phostfilename,templocalfnm,&tsop);  //~v8@sI~
    if (rc==U3CR_RC_NOTFOUND                                       //~v715R~
    ||  rc==U3CR_RC_PATHERR)                                       //~v71eR~
    {
        if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))
            rc=0;//ok if not exist
        else
        	rc=8;
    }
    else
    if (rc)
    	rc=-2;  //no override tso errmsg                           //~v715R~
    else	//rc=0	exist
    {
        if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))
            rc=8;//someone saved
        else
        {
            rc=ufilecomp(0,templocalfnm,Ppfh->UFHftpwdfnm);//1:file1 not exist,2:file2 not exist,3:both not exist,4:unmatch
            if (rc==UALLOC_FAILED)
                return rc;
            if (rc==0 || rc==3)     //match or both dose not exist
                rc=0;
            else
                rc=8;
        }
    }
    if (!rc2)           //now downloaded temp file exist
      if (rc==0)        //comapre OK                               //~v71RI~
        xeftpdelwd(0,templocalfnm);
    return rc;
}//xetsoupdatechk
#ifdef AAA                                                         //~v715R~
//*******************************************************
//*file find
//* parm1:option to output errmsg 0:err msg 1:bypass not found msg
//* parm2:uftphost
//* parm3:filename
//* parm4:input local filename to copy to
//* parm5:output fstat3 area(option)
//* retrn:rc 0:found, 4:not found, 8:path not found, 12:other err
//*          dont return rc 16(dir)/20(wildcard)
//*******************************************************
int xetsofilefindcopy(int Pmsgopt,PUFTPHOST Ppuftph,UCHAR *Phostfile,
				char *Plocalfile,FILEFINDBUF3 *Ppfstat3)
{
    FILEFINDBUF3 fstat3;
    FILEFINDBUF3 *pfstat3;
    char localfile[_MAX_PATH],*plocalfile;
    int rc;
//****************************
    if (!(pfstat3=Ppfstat3))
        pfstat3=&fstat3;
    if (Plocalfile)	//no localfile required;just chk existance only
    	plocalfile=Plocalfile;
    else
    {
//      xeftpgetwdfname(Ppuftph,Phostfile,localfile);              //+vb7eR~
        xeftpgetwdfname(Ppuftph,Phostfile,localfile,sizeof(localfile));//+vb7eI~
    	plocalfile=localfile;
    }
    if (strpbrk(Phostfile,"*?")) //wild card
    {
        if (!(Pmsgopt & FFNODIRMSG))
            uerrmsg("wild card is not resolved",
                    "ワイルドカードが解決できません");
        return 12;              //wild card
    }
	rc=xeftpget(Pmsgopt,Ppuftph,Phostfile,plocalfile);
    if (rc==U3CR_RC_PATHERR)                                       //~v71eR~
    {
        uerrmsg("%s,invalid path",
                "%s のパスが見つかりません",Phostfile);
        rc=8;
    }
    else
    if (rc==U3CR_RC_NOTFOUND)                                      //~v71eR~
    {
        if (!(Pmsgopt & FFNONFMSG))
            uerrmsg("%s is not found",
                    "%s が見つかりません",Phostfile);
     	rc=4;
    }
    else
    if (rc)
    	rc=12;
    if (!rc)
    {
    	ufstat(plocalfile,pfstat3);		//get filesize,timestamp
    	if (!Plocalfile)	//just chk open
			xeftpdelwd(0,plocalfile);
    }
    return rc;
}//filefind
#endif                                                             //~v715I~
//*******************************************************          //~v716I~
//*set pfh size/timestamp from localfile                           //~v717R~
//*******************************************************          //~v716I~
int xetsolocalfstat(PUFILEH Ppfh,FILEFINDBUF3 *Ppfstat3)           //~v716I~
{                                                                  //~v716I~
	char *plocalfile;                                              //~v716I~
	int rc;                                                        //~v716I~
    FILEFINDBUF3 ffb3;                                             //~v717I~
//****************************                                     //~v716I~
    if (Ppfstat3->attrFile & FILE_SPF)   //spf info exist          //~v727R~
        return 0;                                                  //~v727I~
    plocalfile=Ppfh->UFHftpwdfnm;                                  //~v716R~
//  rc=ufstat(plocalfile,&ffb3);		//get filesize,timestamp   //~v717R~//~vb30R~
    rc=(int)ufstat(plocalfile,&ffb3);		//get filesize,timestamp//~vb30I~
    if (!rc)                                                       //~v717R~
    {                                                              //~v717I~
    	Ppfstat3->cbFile=ffb3.cbFile;                              //~v71gI~
    	memcpy(&Ppfstat3->ftimeLastWrite,&ffb3.ftimeLastWrite,sizeof(FTIME));//~v71gI~
    	memcpy(&Ppfstat3->fdateLastWrite,&ffb3.fdateLastWrite,sizeof(FDATE));//~v71gI~
    }                                                              //~v717I~
    return rc;                                                     //~v716I~
}//xetsolocalfstat                                                 //~v71aR~
//*******************************************************          //~v72nI~
//*set spf info to pfh                                             //~v72nI~
//*******************************************************          //~v72nI~
int xetsogetspf(PUFILEH Ppfh,FILEFINDBUF3 *Ppfstat3)               //~v72nI~
{                                                                  //~v72nI~
    if (Ppfstat3->attrFile & FILE_SPF)	//SPF info gotten          //~v72nI~
    {                                                              //~v72nI~
    	Ppfh->UFHspfvv=TSO_GETVV(Ppfstat3);                        //~v72nI~
    	Ppfh->UFHspfmm=TSO_GETMM(Ppfstat3);                        //~v72nI~
    	Ppfh->UFHspfinitline=TSO_GETINITLINE(Ppfstat3);            //~v72nI~
    	Ppfh->UFHspfcredate=TSO_GETCDATE(Ppfstat3);                //~v72nI~
    	return 1;                                                  //~v72nI~
    }                                                              //~v72nI~
    return 0;                                                      //~v72nI~
}//xetsogetspf                                                     //~v72nI~
//*******************************************************          //~v72nI~
//*set spf info to pfh after update spf info                       //~v72nR~
//*******************************************************          //~v72nI~
int xetsosetspf(PUFILEH Ppfh,PPDSSPFINFO Ppspfi)                   //~v72nR~
{                                                                  //~v72nI~
//****************                                                 //~v72nI~
    if (!(Ppspfi->SPFIflag & SPFIFSPF))	//SPF info gotten          //~v72nR~
    	return 0;                                                  //~v72nI~
    Ppfh->UFHspfvv=(UCHAR)Ppspfi->SPFIver;                         //~v72nR~
    Ppfh->UFHspfmm=(UCHAR)Ppspfi->SPFImod;                         //~v72nR~
    Ppfh->UFHspfinitline=(USHORT)Ppspfi->SPFIinitcnt;              //~v72nR~
    Ppfh->UFHspfcredate=Ppspfi->SPFIcdate;                         //~v72nR~
	Ppfh->UFHfiledate=Ppspfi->SPFIudate;                           //~v72nI~
	Ppfh->UFHfiletime=Ppspfi->SPFIutime;                           //~v72nI~
//  Ppfh->UFHsize=Ppspfi->SPFIlinecnt*FILETSOLRECL(Ppfh);          //~v72nI~//~vb30R~
    Ppfh->UFHsize=(FILESZT)((ULONG)Ppspfi->SPFIlinecnt*FILETSOLRECL(Ppfh));//~vb30R~
    return 1;                                                      //~v72nR~
}//xetsosetspf                                                     //~v72nR~
//*******************************************************          //~v71HI~
//*set lrecl for RECFM=F                                           //~v71HI~
//*******************************************************          //~v71HI~
int xetsodefaultlrecl(PUFILEH Ppfh,FILEFINDBUF3 *Ppfstat3)         //~v71HI~
{                                                                  //~v71HI~
	int lrecl;                                                     //~v71HR~
//****************************                                     //~v71HI~
	xetsogetspf(Ppfh,Ppfstat3);                                    //~v72nI~
    Ppfh->UFHattr =Ppfstat3->attrFile;     //requied for new file  //~v72nR~
    Ppfh->UFHsrcattr =Ppfstat3->srcattr;   //lrecl blksize         //~v72nI~
    if ((Ppfh->UFHattr & FILE_PDSMEMB)                             //~v72nI~
    &&  (Ppfh->UFHattr & FILE_SPFDS))   //member of SPF DS         //~v72nI~
        UCBITON(Ppfh->UFHflag8,UFHF8TSOSPF);                       //~v72nI~
	if (                                                           //~v71HI~
        !(Ppfstat3->attrFile & FILE_RECFMF)                        //~v71HR~
    ||   (Ppfstat3->attrFile & FILE_DIRECTORY)                     //~v72nI~
//  ||   Ppfh->UFHlrecl   //lrecl alraedy set                      //~v71HR~
	||   Ppfh->UFHwidth   //width parm specified or /Mb,/mx etc    //~v71HR~
//  ||   Ppfh->UFHmergin  //width parm specified or /Mb,/mx etc    //~v71HR~
    ||   UCBITCHK(Ppfh->UFHflag7,UFHF7NOFIXOPT|UFHF7FIXLRECL)  // -f option specified//~v71KR~
	||   UCBITCHK(Ppfh->UFHflag4,UFHF4BIN) 	//not text file        //~v71KI~
       )                                                           //~v71HI~
       return 0;                                                   //~v71HI~
  if (!UCBITCHK(Ppfh->UFHflag8,UFHF8NOTABCLEAR))	//cmd parm deny to tab clear at save//~v71VR~
	UCBITON(Ppfh->UFHflag5,UFHF5DROPTAB);	//tab clear at save    //~v71KR~
//  lrecl=Ppfstat3->srcattr>>16;    //lrecl/blksize                //~v71HI~//~vb30R~
    lrecl=(int)(Ppfstat3->srcattr>>16);    //lrecl/blksize         //~vb30I~
//  Ppfh->UFHlrecl=lrecl;                                          //~v71KR~//~vb2CR~
    Ppfh->UFHlrecl=(USHORT)lrecl;                                  //~vb2CI~
    if (!Ppfh->UFHmergin)                                          //~v71HR~
    {                                                              //~v71HI~
        if (UCBITCHK(Ppfh->UFHflag7,UFHF7NONUMOPT))  //ignore RECFM=F attr flag//~v71KR~
//  	    Ppfh->UFHmergin=lrecl;                                 //~v71KI~//~vb2CR~
    	    Ppfh->UFHmergin=(USHORT)lrecl;                         //~vb2CI~
        else                                                       //~v71KI~
        if (lrecl==STDSPFLRECL)                                    //~v71HI~
        {                                                          //~v71HI~
		    Ppfh->UFHmergin=STDSPFLRECL-SPFNUMFLDLEN;              //~v71HI~
    	    UCBITON(Ppfh->UFHflag3,UFHF3OOMNOPROT); //no prot number fld//~v71HI~
			UCBITON(Ppfh->UFHflag4,UFHF4SPFCMD);                   //~v71KI~
		    Ppfh->UFHspfpos=(UCHAR)(STDSPFLRECL-SPFNUMFLDLEN);     //~v71KR~
        }                                                          //~v71HI~
        else                                                       //~v71HI~
//  	    Ppfh->UFHmergin=lrecl;                                 //~v71HR~//~vb2CR~
    	    Ppfh->UFHmergin=(USHORT)lrecl;                         //~vb2CI~
        UCBITON(Ppfh->UFHflag2,UFHF2MERGIN);  //no drop last space //~v71HI~
    }                                                              //~v71HI~
    UCBITON(Ppfh->UFHflag7,UFHF7FIXLRECL);                         //~v71HI~
    return 0;                                                      //~v71HI~
}//xetsodefaultlrecl                                               //~v71HI~
//*******************************************************          //~v71aI~
//*update pdh by  pfh size/timestamp                               //~v71aI~
//*******************************************************          //~v71aI~
int xetsodlcmdsetlocal(PUFILEC Ppfc,PUDIRLH Ppdh,PUFILEH Ppfh)     //~v71aR~
{                                                                  //~v71aI~
	PULINEH plh;                                                   //~v71aI~
	PUDIRLH pdh;                                                   //~v71aI~
	UQUEH  *pqh;                                                   //~v71aI~
//****************************                                     //~v71aI~
	if (!(pdh=Ppdh))                                               //~v71aI~
    {                                                              //~v71aI~
		if (!(pqh=UGETQHDR(Ppfc)))			//qhdr addr on pdh     //~v71aI~
    		return 0;						//parent already freed //~v71aI~
//  	pdh=(PUDIRLH)(PVOID)((ULONG)pqh-offsetof(UDIRLH,UDHviewqh));//~v71aI~//~vafkR~
    	pdh=(PUDIRLH)(PVOID)((ULPTR)pqh-offsetof(UDIRLH,UDHviewqh));//~vafkI~
	}                                                              //~v71aI~
  	plh=UGETDIRPLH(pdh);                                           //~v72rI~
	pdh->UDHsize=Ppfh->UFHsize;                                    //~v71aR~
	pdh->UDHdate=Ppfh->UFHfiledate;                                //~v71aR~
	pdh->UDHtime=Ppfh->UFHfiletime;                                //~v71aR~
    if (Ppfh->UFHattr & FILE_SPF)                                  //~v72nI~
    {                                                              //~v72nI~
    	TSOGN_SETVV(pdh->UDHgname,Ppfh->UFHspfvv);  //update pdh ver//~v72nR~
    	TSOGN_SETMM(pdh->UDHgname,Ppfh->UFHspfmm);  //mod          //~v72nR~
        pdh->UDHattr|=FILE_SPF;                     //display vv/mm//~v72nI~
//  	pdh->UDHslinksize=Ppfh->UFHsize/FILETSOLRECL(Ppfh);        //~v72rR~//~vb31R~
    	pdh->UDHslinksize=Ppfh->UFHsize/(FILESZT)FILETSOLRECL(Ppfh);//~vb31I~
    }                                                              //~v72nI~
//	plh=UGETDIRPLH(pdh);                                           //~v72rR~
    UCBITOFF(pdh->UDHflag,UDHFDDSETUP);                            //~v71aR~
    UCBITON(plh->ULHflag,ULHFDRAW);                                //~v71aI~
    return 0;                                                      //~v71aI~
}//xetsodlcmdsetlocal                                              //~v71aI~
//*******************************************************
//*generate dsn from another split screen dsn( "^*.___" "^*(___" )
//*  *^\..\abc etc
//*parm1 :output area
//*parm2 :pfh of another screen of TSO file
//*parm3 :pos after "^*", called when "." or "("  "" is followed
//*return:always fulpath addr
//*******************************************************
char *xetsofilefullpath2ndedit(char *Pfullpath,PUFILEH Ppfh,char *Pmodifier)
{
	char *fnm,*modf,fpathwk[_MAX_PATH],*appendname;                //~v71gR~
    int  sepc,len;
//************************
	fnm=Ppfh->UFHfilename;
	modf=Pmodifier;
    if (!*modf)	//no modification                                  //~v71gR~
    {
        strcpy(Pfullpath,fnm);
        return Pfullpath;
    }
    sepc=*modf++;
//  strcpy(Pfullpath,fnm);  //pfhfilename                          //~v71pR~
//  if ((pc=MEMBOFDSN(Pfullpath)))	//pos of "("                   //~v71gR~
//  	 *pc=0;	//drop member                                      //~v71gR~
    u3270parentdsn(U3PL_DROPWILDORMEMBER,fnm,Pfullpath);           //~v71gR~
    if ((sepc==DSN_SEPC||sepc==DIR_SEPC)                           //~v71gR~
    &&  *modf==SAMEDIR)			//"^*.*___"
    {
      if (*(modf+1)==SAMEDIR        //^*.**                        //~v71pI~
      ||  *(modf+1)==DSN_SEPC       //^*.*.                        //~v71pI~
      ||  *(modf+1)==DIR_SEPC       //^*.*/                        //~v71pI~
      ||  *(modf+1)==DSN_SEPCMEMB   //^*.*(                        //~v71pI~
         )                                                         //~v71pI~
      {                                                            //~v71pI~
		xetsofilefullpath2(fpathwk,modf,sizeof(fpathwk),Pfullpath);
        strcpy(Pfullpath,fpathwk);
        return Pfullpath;
      }                                                            //~v71pI~
    }
    if ((sepc==DIR_SEPC && !*modf)                                 //~v71nR~
    ||  (sepc==DSN_SEPC && !*modf))                                //~v71nR~
    	return Pfullpath;                                          //~v71gI~
//  strcat(Pfullpath,Pmodifier);   	//append "(xxx)" / ".xxx(yyy)" //~v71gR~
  	if (sepc==DIR_SEPC)                                            //~v71gR~
  	{                                                              //~v71gI~
  		if (Ppfh->UFHattr & FILE_PO)                               //~v71gR~
			sprintf(fpathwk,"(%s)",modf);                          //~v71gR~
    	else                                                       //~v71gI~
			sprintf(fpathwk,".%s",modf);                           //~v71gI~
        appendname=fpathwk;                                        //~v71gI~
  	}                                                              //~v71gI~
	else                                                           //~v71gI~
    	appendname=Pmodifier;                                      //~v71gI~
//  len=strlen(Pfullpath);                                         //~vb30R~
    len=(int)strlen(Pfullpath);                                    //~vb30I~
    if (strchr(Pfullpath,DSN_QUOTE))
    {
		strcpy(Pfullpath+len-1,appendname);   	//append "(xxx)" / ".xxx(yyy)"//~v71gR~
//      len=strlen(Pfullpath);                                     //~v71gI~//~vb30R~
        len=(int)strlen(Pfullpath);                                //~vb30I~
        *(Pfullpath+len++)=DSN_QUOTE;
    	*(Pfullpath+len)=0;
    }
    else                                                           //~v71gI~
		strcat(Pfullpath,appendname);   	//append "(xxx)" / ".xxx(yyy)"//~v71gR~
	return Pfullpath;	//continue by modified filename
}//xe3270filefullpath2ndedit
//*******************************************************
//*get file fullpath name from source (chk "*."   "*("   "**."    "**(" )
//called when dsn(remote file of TSO)
//*parm 1:output full pth mame
//*parm 2:input partial target filename
//*parm 3:output buff len
//*parm 4:source fullpath filename
//*return:output buff addr or NULL if err
//*******************************************************
char *xetsofilefullpath2(char *Pfullpath,char *Ptarget,size_t Plen,char *Psource)
{
    UCHAR *pc,*fname;
    int pathlen,len,level,samedirsw,ii;                            //~v71gR~
//***************************
    if (*Ptarget!=SAMEDIR)
        return filefullpath(Pfullpath,Ptarget,Plen);//process "^*" etc

    if (*(Ptarget+1)==DSN_SEPC || *(Ptarget+1)==DSN_SEPCMEMB || *(Ptarget+1)==DIR_SEPC)   // "*." or "*(" "*\"//~v71gR~
        samedirsw=1;
    else
        if (*(Ptarget+1)==SAMEDIR
        &&  (*(Ptarget+2)==DSN_SEPC||*(Ptarget+2)==DSN_SEPCMEMB||*(Ptarget+2)==DIR_SEPC||*(Ptarget+2)==0)) //"**." or "**(" "**\"//~v71gR~
            samedirsw=0;
        else
            return filefullpath(Pfullpath,Ptarget,Plen);
//"*" or "**" with "." or "("
	strcpy(Pfullpath,Psource);
    if ((pc=MEMBOFDSN(Pfullpath)))	//pos of "("
		 *pc=0;	//drop member

    if (samedirsw)  //samedir
    {                                                              //~v71aI~
        fname=Ptarget+1;                                           //~v71aR~
        if (WILDCARD(Pfullpath))                                   //~v71aI~
        {                                                          //~v71aI~
            pathlen=u3270pathlen(0,Pfullpath);                     //~v71aI~
            if (pathlen>0)                                         //~v71aI~
                *(Pfullpath+pathlen-1)=0;                          //~v71aI~
        }                                                          //~v71aI~
    }                                                              //~v71aI~
    else    //upper dir
    {
        for (level=1,pc=Ptarget+3;;level++,pc+=3)   //count UPPERDIR
            if (*pc!=SAMEDIR
            ||  *(pc+1)!=SAMEDIR
            ||  (*(pc+2)!=DSN_SEPC && *(pc+2)!=DSN_SEPCMEMB && *(pc+2)!=DIR_SEPC && *(pc+2)!=0))//~v71gR~
                break;
        fname=pc-1;	//same to be appended
        for (ii=0;ii<level;ii++)
        {
            pathlen=u3270pathlen(0,Pfullpath);
            if (pathlen<=0) //level up
            	break;
            *(Pfullpath+pathlen-1)=0;	//drop "."
        }
    }//upper dir
//  len=strlen(Pfullpath);                                         //~v71aI~//~vb30R~
    len=(int)strlen(Pfullpath);                                    //~vb30I~
    if (*(Pfullpath+len-1)==DSN_QUOTE)                             //~v71aI~
        len--;                                                     //~v71aI~
    if (*fname==DIR_SEPC)                                          //~v71gI~
    {                                                              //~v71gI~
    	fname++;                                                   //~v71gI~
		if (samedirsw)                                             //~v71gI~
	    	sprintf(Pfullpath+len,"(%s)",fname);                   //~v71gR~
        else                                                       //~v71gI~
	    	sprintf(Pfullpath+len,".%s",fname);                    //~v71gI~
    }                                                              //~v71gM~
    else                                                           //~v71gI~
	    strcpy(Pfullpath+len,fname);                               //~v71gR~
    if (strchr(Pfullpath,DSN_QUOTE))
    {
//      len+=strlen(Pfullpath+len);                                //~v71gR~//~vb30R~
        len+=(int)strlen(Pfullpath+len);                           //~vb30I~
        *(Pfullpath+len++)=DSN_QUOTE;
    	*(Pfullpath+len)=0;
    }
    return Pfullpath;
}//xetsofilefullpath2
//**************************************************               //~v717I~
//*getpathlen                                                      //~v717I~
//* path length and dir level output from filename                 //~v717I~
//* if contains membname,pathlen is dsn len,else parent pathlen    //~v717I~
//**************************************************               //~v717I~
int xetsogetpathlen(UCHAR *Pfilename,UCHAR *Plevel,int Pdirsw)     //~v717I~
{                                                                  //~v717I~
    int ii,len/*,len0*/;                                               //~v717I~//~vaa7R~
    UCHAR *pc,*pc2;                                                //~v717R~
//********************                                             //~v717I~
    pc=Pfilename;                                                  //~v717I~
//  len0=(int)strlen(pc);                                          //~v717I~//~vaa7R~
    for (ii=0;;ii++)                                               //~v717I~
    {                                                              //~v717I~
        pc2=pc;                                                    //~v717I~
        pc=strchr(pc2,DSN_SEPC);	//"."                          //~v717I~
        if (!pc)                                                   //~v717I~
        {                                                          //~v717I~
	        pc=strchr(pc2,DSN_SEPCMEMB);	//"("                  //~v717R~
            if (pc)                                                //~v717I~
            {                                                      //~v717I~
            	pc2=pc+1;                                          //~v717I~
            	ii++;                                              //~v717I~
            }                                                      //~v717I~
            else                                                   //~v717I~
            if (Pdirsw)                                            //~v717I~
            	if (DSNWILDCARD(pc2)==0)                           //~v717R~
	                ii++;                                          //~v717R~
            break;                                                 //~v717I~
        }                                                          //~v717I~
        ++pc;       //next of delm                                 //~v717I~
    }                                                              //~v717I~
//  len=(int)((ULONG)pc2-(ULONG)Pfilename-1);                      //~v717I~//~vafkR~
    len=(int)((ULPTR)pc2-(ULPTR)Pfilename-1);                      //~vafkI~
    if (Plevel)                                                    //~v717I~
        *Plevel=(UCHAR)ii;  //file/dir hierarchical level          //~v717I~
    return len;                                                    //~v717I~
}//xetsogetpathlen                                                 //~v717R~
//**************************************************************** //~v717I~
// xetsolvlfname                                                   //~v717I~
// get filename of the level from full path name                   //~v717I~
//*ret   :rc                                                       //~v717I~
//**************************************************************** //~v717I~
int xetsolvlfname(PUFILEH Ppfh,UCHAR *Pfullpath,int Plevel,UCHAR *Pfname,int *Plen)//~v717I~
{                                                                  //~v717I~
    UCHAR *pc,*pc2;                                                //~v717I~
    int   ii;                                                      //~v717I~
    UINT  len;                                                     //~v717I~
    PUFTPHOST puftph;                                              //~v717R~
//*******************                                              //~v717I~
    puftph=Ppfh->UFHpuftph;                                        //~v717I~
//  len=puftph->UFTPHhostnmlen+1;                                  //~v717I~//~vb30R~
    len=(UINT)puftph->UFTPHhostnmlen+1;                            //~vb30I~
    pc=Pfullpath;                                                  //~v717I~
	if (!Plevel)	//req root;                                    //~v717I~
    {                                                              //~v717I~
        if (Plen)                                                  //~v717I~
//          *Plen=len;                                             //~v717I~//~vb30R~
            *Plen=(int)len;                                        //~vb30I~
    }                                                              //~v717I~
    else                                                           //~v717I~
    {                                                              //~v717I~
        pc+=len;                                                   //~v717I~
        for (ii=1;ii<Plevel;ii++,pc++)                             //~v717R~
            if (!(pc=strpbrk(pc,DSN_SEPS))) //search "."/"("       //~v717R~
                return 4;                                          //~v717R~
        if (!(pc2=strpbrk(pc,DSN_SEPS)))	//next delm            //~v717R~
        {                                                          //~v717R~
//          len=strlen(pc);                                        //~v717R~//~vb31R~
            len=(UINT)strlen(pc);                                  //~vb31I~
            if (Plen)                                              //~v717R~
                *Plen=(int)strlen(Pfullpath);                      //~v717R~
        }                                                          //~v717R~
        else                                                       //~v717R~
        {                                                          //~v717R~
//          len=(UINT)((ULONG)pc2-(ULONG)pc);                      //~v717R~//~vafkR~
            len=(UINT)((ULPTR)pc2-(ULPTR)pc);                      //~vafkI~
            if (Plen)                                              //~v717R~
//              *Plen=(int)((ULONG)pc2-(ULONG)Pfullpath);          //~v717R~//~vafkR~
                *Plen=(int)((ULPTR)pc2-(ULPTR)Pfullpath);          //~vafkI~
        }                                                          //~v717R~
        if (len>MAXFILENAME)                                       //~v717R~
            return 4;                                              //~v717R~
    }                                                              //~v717I~
    if (Pfname)                                                    //~v717I~
    {                                                              //~v717I~
        if (*pc==DSN_QUOTE)                                        //~v717I~
        {                                                          //~v717I~
    		memcpy(Pfname,pc+1,len-1);                             //~v717I~
	    	*(Pfname+len-1)=0;                                     //~v717I~
        }                                                          //~v717I~
        else                                                       //~v717I~
	    if (*(pc+len-1)==DSN_QUOTE)                                //~v717I~
        {                                                          //~v717I~
    		memcpy(Pfname,pc,len-1);                               //~v717I~
	    	*(Pfname+len-1)=0;                                     //~v717I~
        }                                                          //~v717I~
        else                                                       //~v717I~
        {                                                          //~v717I~
	    	memcpy(Pfname,pc,len);                                 //~v717R~
	    	*(Pfname+len)=0;                                       //~v717R~
        }                                                          //~v717I~
	}                                                              //~v717I~
    return 0;                                                      //~v717I~
}//xetsolvlfname                                                   //~v717I~
//**************************************************************** //~v717I~
// xetsodlcgetfullname                                             //~v717I~
// get fullpath filename of dir member                             //~v717I~
//**************************************************************** //~v717I~
int xetsodlcgetfullname(PUFILEH Ppfh,PUDIRLH Ppdh,UCHAR *Pfname)   //~v717I~
{                                                                  //~v717I~
    PUDIRLH pdh;                                                   //~v717I~
    UCHAR *pc;                                                     //~v717I~
    UCHAR *name;                                                   //~v717I~
    UINT   ulen,utlen,utleno,sepc;                                 //~v717R~
//*******************                                              //~v717I~
    pdh=Ppdh->UDHdirptr;    //parent                               //~v717R~
    if (Ppdh->UDHattr & FILE_PDSMEMB)                              //~v717R~
    {                                                              //~v717I~
//  	utlen=1+sprintf(Pfname,"%s%c%c",Ppdh->UDHname,DSN_SEPCMEMB2,DSN_QUOTE);//~v717R~//~vb30R~
    	utlen=1+(UINT)sprintf(Pfname,"%s%c%c",Ppdh->UDHname,DSN_SEPCMEMB2,DSN_QUOTE);//~vb30I~
        sepc=DSN_SEPCMEMB;                                         //~v717I~
    }                                                              //~v717I~
    else                                                           //~v717M~
    {                                                              //~v717M~
	    if (Ppdh->UDHattr & FILE_DSNPATH)                          //~v717I~
//        if (Ppdh->UDHflag & UDHFMASK && Ppdh->UDHrenamesv)       //~v71gR~,//~v72yR~
//      	utlen=1+sprintf(Pfname,"%s.%s%c",Ppdh->UDHname,Ppdh->UDHrenamesv,DSN_QUOTE);//~v71gI~,//~v72yR~
//        else                                                     //~v71gI~,//~v72yR~
//      	utlen=1+sprintf(Pfname,"%s.*%c",Ppdh->UDHname,DSN_QUOTE);//~v71zR~
//      	utlen=1+sprintf(Pfname,"%s%c",Ppdh->UDHname,DSN_QUOTE);//~v71zI~//~vb30R~
        	utlen=1+(UINT)sprintf(Pfname,"%s%c",Ppdh->UDHname,DSN_QUOTE);//~vb30I~
        else                                                       //~v717I~
//        if (Ppdh->UDHflag & UDHFMASK && Ppdh->UDHrenamesv)       //~v71gI~,//~v72yR~
//      	utlen=1+sprintf(Pfname,"%s(%s)%c",Ppdh->UDHname,Ppdh->UDHrenamesv,DSN_QUOTE);//~v71gI~,//~v72yR~
//        else                                                     //~v71gI~,//~v72yR~
//      	utlen=1+sprintf(Pfname,"%s%c",Ppdh->UDHname,DSN_QUOTE);//~v717R~//~vb30R~
        	utlen=1+(UINT)sprintf(Pfname,"%s%c",Ppdh->UDHname,DSN_QUOTE);//~vb30I~
        sepc=DSN_SEPC;                                             //~v717M~
    }                                                              //~v717M~
    pc=Pfname;                                                     //~v717I~
    for (;pdh;pdh=pdh->UDHdirptr)   //hierarchy                    //~v717R~
    {                                                              //~v717I~
        utleno=utlen;                   //save old len             //~v717I~
        name=pdh->UDHname;      //use long filename                //~v717I~
//      ulen=strlen(name);                                         //~v717I~//~vb31R~
        ulen=(UINT)strlen(name);                                   //~vb31I~
        if (utlen+=ulen+1,utlen>=_MAX_PATH)                        //~v717R~
//          return errtoolong();                                   //~vb72R~
        	return ufileTooLongFullpathName(4/*rc*/);              //~vb72I~
        memmove(pc+ulen+1,pc,utleno);                              //~v717R~
        memcpy(pc,name,ulen);   //insert parent dir name           //~v717I~
        if (!pdh->UDHlevel) //hostname                             //~v717R~
        {                                                          //~v717I~
	        *(pc+ulen)=DSN_QUOTE;                                  //~v717I~
            break;                                                 //~v717I~
        }                                                          //~v717I~
//      *(pc+ulen)=sepc;	//1st time "." or "("                  //~v717R~//~vb2CR~
        *(pc+ulen)=(UCHAR)sepc;	//1st time "." or "("              //~vb2CI~
        sepc=DSN_SEPC;                                             //~v717I~
    }                                                              //~v717I~
    return 0;                                                      //~v717I~
}//xetsodlcgetfullname                                             //~v71aR~
//**************************************************************** //~v71aI~
// concatinate filename(wildcard is replaced if exist)             //~v71aR~
//**************************************************************** //~v71aI~
int xetsoconcatfilename(PUFILEH Ppfh,char *Pappendname,char *Poutfname)//~v71aI~
{                                                                  //~v71aI~
    PUFTPHOST puftph;                                              //~v71aR~
    int len,hostnmlen;                                             //~v71aR~
    char *pc;                                                      //~v71aI~
//****************************                                     //~v71aI~
	puftph=Ppfh->UFHpuftph;                                        //~v71aR~
    hostnmlen=puftph->UFTPHhostnmlen+1;                            //~v71aI~
    pc=Ppfh->UFHfilename;            //dir name                    //~v71aR~
    if (WILDCARD(pc))                                              //~v71aI~
    {                                                              //~v71aI~
        len=u3270pathlen(2,pc); 	//drop member or last path     //~v71aR~
        if (len<=0)  //err                                         //~v71aI~
            return 4;                                              //~v71aI~
        len--;              //drop last \ for followed logic       //~v71aI~
    }                                                              //~v71aI~
    else                                                           //~v71aI~
        len=(int)strlen(pc)-1;            //drop last quatation    //~v71aI~
    memcpy(Poutfname,pc,(UINT)len);            //dir name          //~v71aI~
    if (*Pappendname==DSN_QUOTE)	//from root                    //~v71aR~
		strcpy(Poutfname+hostnmlen,Pappendname);                   //~v71aI~
    else                                                           //~v71aI~
    {                                                              //~v71aI~
    	pc=Poutfname+len;                                          //~v71aR~
        if (Ppfh->UFHattr & FILE_DIRECTORY)                        //~v71aI~
            *pc++=DSN_SEPCMEMB;                                    //~v71aI~
        else                                                       //~v71aI~
            *pc++=DSN_SEPC;                                        //~v71aR~
//  	len=strlen(Pappendname);                                   //~v71aI~//~vb30R~
    	len=(int)strlen(Pappendname);                              //~vb30I~
//  	memcpy(pc,Pappendname,len);                                //~v71aI~//~vb30R~
    	memcpy(pc,Pappendname,(size_t)len);                        //~vb30I~
        pc+=len;                                                   //~v71aI~
        if (Ppfh->UFHattr & FILE_DIRECTORY)                        //~v71aI~
            *pc++=DSN_SEPCMEMB2;                                   //~v71aI~
        *pc++=DSN_QUOTE;                                           //~v71aI~
        *pc=0;                                                     //~v71aI~
	}                                                              //~v71aI~
    return 0;                                                      //~v71aI~
}//xetsoconcatfilename                                             //~v71aI~
                                                                   //~v71eI~
//**************************************************************** //~v72uI~
// concatinate filename(wildcard is replaced if exist)             //~v72uI~
//**************************************************************** //~v72uI~
int setupspfcmdopt(PUFTPHOST Ppuftph,char *Popd,int Popdno,char *Pout)//~v72uR~
{                                                                  //~v72uI~
	int ii,len;                                                    //~v72uR~
	char *pc,*vv="",*mm="",*cline="",*user="",*idt="",*udt="",*utm="",*iline="";//~v72uR~
    char dt[7];                                                    //~v72uI~
//****************************                                     //~v72uI~
    for (ii=0,pc=Popd;ii<Popdno;ii++)                              //~v72uR~
    {                                                              //~v72uI~
    	len=(int)strlen(pc);                                       //~v72uR~
        if (len>2 && !memicmp(pc,"V=",2))                          //~v72uR~
        	vv=pc+2;                                               //~v72uI~
        else                                                       //~v72uI~
        if (len>2 && !memicmp(pc,"M=",2))                          //~v72uR~
        	mm=pc+2;                                               //~v72uI~
        else                                                       //~v72uI~
        if (len>4 && !memicmp(pc,"DT0=",4))                        //~v72uI~
        	idt=pc+4;                                              //~v72uI~
        else                                                       //~v72uI~
        if (len>4 && !memicmp(pc,"DTM=",4))                        //~v72uI~
        {                                                          //~v72uI~
        	udt=pc+4;                                              //~v72uI~
            if (len>10)                                            //~v72uI~
            {                                                      //~v72uI~
            	memcpy(dt,udt,6);                                  //~v72uI~
                *(dt+6)=0;                                         //~v72uI~
                udt=dt;                                            //~v72uI~
            	utm=pc+10;                                         //~v72uR~
            }                                                      //~v72uI~
        }                                                          //~v72uI~
        else                                                       //~v72uI~
        if (!stricmp(pc,"DTM"))                                    //~v72uI~
        {                                                          //~v72uI~
        	udt="NOW";                                             //~v72uI~
        	utm="NOW";                                             //~v72uI~
        }                                                          //~v72uI~
        else                                                       //~v72uI~
        if (!stricmp(pc,"LC"))                                     //~v72uR~
        	cline="NOW";                                           //~v72uI~
        else                                                       //~v72uI~
        if (len>4 && !memicmp(pc,"LC0=",4))                        //~v72uI~
        	iline=pc+4;                                            //~v72uI~
        else                                                       //~v72uI~
        if (!stricmp(pc,"LC0"))                                    //~v72uI~
        	iline="NOW";                                           //~v72uI~
        else                                                       //~v72uI~
        if (len>4 && !memicmp(pc,"UID=",4))                        //~v72uR~
        	user=pc+4;                                             //~v72uI~
        else                                                       //~v72uI~
        if (!stricmp(pc,"UID"))                                    //~v72uR~
        	user=Ppuftph->UFTPHuser;                               //~v72uI~
        else                                                       //~v72uI~
        {                                                          //~v72uI~
        	uerrmsg("subcmd SPF option error-\"%s\"; ([V=xx] [M=xx] [DT0=yymmdd] [DTM=[yymmdd[hhtm]]] [LC] [LC0[=xx]] [UID[=userid]])",0,//~v72uR~
					pc);                                           //~v72uI~
            return 4;                                              //~v72uI~
        }                                                          //~v72uI~
    	pc+=len+1;                                                 //~v72uI~
    }                                                              //~v72uI~
    sprintf(Pout," \"%s,%s,%s,%s,%s,%s,%s,%s\"",vv,mm,idt,udt,utm,cline,iline,user);//~v72uR~
    return 0;                                                      //~v72uI~
}//setupspfcmdopt                                                  //~v72uI~
                                                                   //~v72uI~
#endif	//FTPSUPP
