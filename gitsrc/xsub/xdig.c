//*CID://+vas3R~:                             update#=   52;       //~vas3R~
//***********************************************************
//* XDig : apply program into dir/subdir
//***********************************************************
//vas3:230630 ARM;closeall for arm subthread execution             //~vas3I~
//van4:200516 xdig 1.13:/Cx parm for alternative of %, e.g $fp$ by /C$.//~van4I~
//van3:200515 xdig 1.13:%rp% support(path relative to starting dir)//~van3I~
//vae1:170206 xdig v1.12 (BUG of 64bit) ptrsize is 8 byte          //~vae1I~
//vaa1:160418 Lnx64 compiler warning                               //~vaa1I~
//va99:150119 xdig v1.11 Win64 spawn returns intptr                //~va99I~
//va71:130618 (W32)dirwalk support windows slink/junction/mountpoint//~va71I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va3q:080129 xdig v1.9 english msg spell miss                     //~va3qI~
//va2j:060829 xdig:1.8 %fb%:basename support                       //~va2jI~
//021210 xdig:v1.7 v174 (BUG)cmdflag prefix on errmsg              //~v174I~
//021009 xdig:v1.7 v173 (UNX)symbolic link errmsg skip option(/Nm)(u#1)//~v173I~
//020714 xdig:v1.7 v172 (UNX)symbolic link skip option             //~v172I~
//020714 xdig:v1.7 v171 (UNX)special file option                   //~v171I~
//v141 xdig.c    V1.6 000930 LINUX support                         //~v141R~
//                           .no extention chk,use system          //~v141I~
//                           .no confirm option                    //~v141R~
//                           .option flag prefix "/"-->"-"         //~v141I~
//                           .no attr mask option                  //~v141I~
//v140 xdig.c    V1.6 000930 split option to cmd print from trace option//~v140I~
//*991113 v1.5 v138 (BUG)when /pd(dir apply mode) %fp% is not replaced//~v138I~
//v137 991031 v1.5 display level difault on help                   //~v137I~
//                         warning when redirectonly               //~v137I~
//*********** v1.4 *****(bellow this line)**************************//~v137I~
//*            will v1.4 relese                                    //~v132I~
//*            doc updated                                         //~v135I~
//v136 981101 by bug of udirwalk(ufile4.c) level calc              //~v135I~
//v135 980926 completion msg on redirect file also                 //~v135I~
//v134 980926 display filename for trace msg(dir name is already displayed)//~v134R~
//v133 980926 helpmsg double line                                  //~v132I~
//*********** v1.3 *****(bellow this line)**************************//~v132I~
//v132 980410 abend if redirectonly(no dir name specified with redirect sw)//~v132R~
//v131 980228 allow wildcard filespec(no need separate mask parm)  //~v132I~
//v130 980201 win/gcc version                                      //~v130I~
//v129 971018 uparse is split from string.h                        //~v129I~
//v128 970427 ignore also tab on cmd string before cmd name        //~v128R~
//v127 970406 /Nl(No logo) /Na(account msg) option                 //~v128I~
//v126 970406 change /Yf,/Yd-->/Px(file,dir,both,none)             //~v126I~
//v125 970406 change /Xtype-->/Yx                                  //~v125R~
//            try by system if not executable                      //~v125I~
//v124 970406 /Yt option(trace command text)                       //~v124R~
//v123 970405 (BUG)drop ',' from delm tbl(dos treate it as char)   //~v122I~
//v122 970330 (BUG)errornous use of uparse,output is string but not argv//~v122I~
//            (BUG)toupper(++x) may 2up                            //~v122I~
//v121 970302 redirect only function(no dir parm)                  //~v121I~
//***********************************************************

#define VER "V1.13"  //version                                     //~vae1R~//~van3R~
#define PGM "XDIG"

//**********************************************/
//*parm1 : dir name
//*parm2 : wild card
//*parm3 : /options //cmd-string
//*r.c   : 0 :normal,else err
//**********************************************/
//*
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
                                                                   //~v141I~
#ifdef UNX                                                         //~v141I~
	#include <sys/stat.h>                                          //~v172I~
#else  //!UNX                                                      //~v141I~
#include <conio.h>
#include <process.h>
#endif //!UNX                                                      //~v141I~

#ifdef DOS
        #include <errno.h>
#else
  #ifdef W32                                                       //~v130I~
        #include <dos.h>                                               //~v130I~
  #else                                                            //~v130I~
        #define INCL_BASE
        #include <os2.h>
  #endif                                                           //~v130I~
#endif

//*********************************************************************
#include <ulib.h>
#include <ufile.h>
#include <uproc.h>
#include <uerr.h>
#include <ualloc.h>
#include <ufile4.h>
#include <ustring.h>
#include <uparse.h>                                                //~v129I~
#include <uedit.h>
//*********************************************************************
#define MAXCMDSZ 8192   //cmd edit buff size
#define HELPMSG         uerrhelpmsg(stdout,stderr,

//*********************************************************************
static char *Spgm=PGM,*Sver=VER;
static char *Sdir,*Sfilemask="",*Sdirmask="";
static int Stopfpathlen;	//top dir fpathlen                     //~van3I~
static char **Scmdarg0;
static char Sfilesw=1;          //default file call
static char Sdirsw,Semptysw,Scdsw=1,Sredirectsw,Srevsortsw,Sredironlysw;//~v121R~
static char Sconfirmsw,Sexetype,Sforcetype;
static char Ssortorder='N';             //default name seq
//static char Straceopt=1;                //command text trace option//~v140R~
static char Straceopt;                    //command text trace option//~v140I~
static char Sdirtraceopt=1;               //sub dir trace option   //~v140I~
static char Slogosw=1,Saccountsw=1;                                //~v124I~
static int  Sdirctr,Scallctr,Sfilectr;
static int  Sdwopt;
static int  Snullsw;    //set null if no data like as fullpath name
static int  Sattrmask=FILE_ALL-FILE_DIRECTORY;  //default all file
static int  Sstopdepth=4096;                                    //default no depth
static int  Scmdargno;
static char *Sredirectf1,*Sredirectf2,*Scmdstr0;
static char Sredirectf1fp[_MAX_PATH];
static char Sredirectf2fp[_MAX_PATH];
static char Sfnmask[_MAX_PATH];				//mask from dir name   //~v131I~
static FILE *Smsgfh;
//static char *Scmdrepword[]={"%d%","%f%","%fp%",0};               //~va2jR~
//static char *Scmdrepword[]={"%d%","%f%","%fp%","%fb%",0};          //~va2jI~//~van3R~
static char *Scmdrepword[]={"%d%","%f%","%fp%","%fb%","%rp%",0};   //rp:[4]//~van3I~
static int Ssw_altsign;                                            //~van4I~
#ifdef UNX                                                         //~v171I~
	static int  Sspfsw=0;		//special filesw                   //~v171I~
#endif                                                             //~va71I~
#if defined(W32)||defined(UNX)                                     //~va71R~
	static int  Sskipslinksw=0; //slink skip option                //~v172I~
#endif                                                             //~v171I~
//********************
void parmchk(int,char *[]);
int applycmd(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,
                                int Pdepth,void *Pdata,int *Prc);
char **cmdedit(char *Pdir,char *Pfile,char *Pfullpath);
void getcmd(int Pcmdparmno,char **Pcmd);
int confirmchk(char *Pobj);
void help(void);
void titlemsg(void);
void setredirect(int Popt);
void redirecterr(char *Psource,char *Ptarget);
void redirectrestoreerr(char *Psource);
void msgout(char *Pmsg);
void optionerr(char *type,char* value);
void flushout(void);
//int execute(char **Pargv,int Pdepth,char *Pdata,int *Prc);       //~v134R~
int execute(char **Pargv,int Pdepth,char *Pdata,int *Prc,char *Pfullpath);//~v134I~
void errtoolongcmd(void);
//void errrepandopt(char *Prepw);                                  //~v174R~
void completemsg(void);                                            //~v135I~
//*********************************************************************
//* parm    :dir-name,mask,/options,//cmd-string
//* return 0:
//*        1:unmatch exist
//*        4:encountered error condition
//*********************************************************************
int main(int parmc,char *parmp[])
{
        int applrc,rc;
        char lastobj[_MAX_PATH];
//**********************************
//* main
//**********************************
#ifdef DPMI                                     //DPMI version                         //~v130I~
    putenv("LFN=Y");                 //need for ufileisvfat        //~v130I~
        ufileisvfat(ISVFAT_FORCE);      //force vfat                   //~v130I~
#endif                      //DPMI or not                          //~v130I~
        Smsgfh=stdout;                  //defult;
//**********************************
        parmchk(parmc,parmp);
//*navigate
    Sdwopt=UDIRWALK_NOMSG;              //no msg from udirwalk
    if (Srevsortsw)
        Sdwopt|=UDIRWALK_SORT_REV;  //reverse sort sw
    Sdwopt|=(int)Ssortorder;            //no msg from udirwalk
    if (Sfilesw)
        Sdwopt|=UDIRWALK_FILECALL;
    if (Sdirsw)
        Sdwopt|=UDIRWALK_DIRCALL;
    if (Scdsw)                                                     //~v1.1I~
        Sdwopt|=UDIRWALK_CD;                                       //~v1.1I~
    Sdwopt|=UDIRWALK_EMPTYCALL;
//#ifdef UNX                                                         //~v171I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71R~
	if (Sskipslinksw)                                              //~v172I~
        Sdwopt|=UDIRWALK_SKIPSLINK;                                //~v172I~
#ifdef UNX                                                         //~va71I~
    if (Sspfsw)                                                    //~v171I~
    	Sattrmask|=FILE_SPECIAL;                                   //~v171I~
#endif                                                             //~v171I~
#endif                                                             //~va71I~
  if (Sredironlysw)                                                //~v121I~
//        rc=applycmd(0,0,0,0,0,0);       //call only once         //~v132R~
	    rc=applycmd(0,0,0,0,lastobj,&applrc);       //call only once//~v132I~
  else                                                             //~v121I~
        rc=udirwalk(Sdwopt,Sdir,Sdirmask,Sfilemask,Sattrmask,
                        Sstopdepth,applycmd,lastobj,&applrc);
//*restore cur path
    if (Scallctr)
    {
		if (Sredirectsw==3	//stdout+stderr to same file           //~v135I~
		|| Sredirectsw==4)  //stdout and stderr redirect to each file//~v135R~
        {                                                          //~v135I~
			completemsg();                                         //~v135R~
			if (Slogosw)                                           //~v135I~
		        titlemsg();                                        //~v135I~
        }                                                          //~v135I~
        flushout();
        setredirect(1); //restore
    }
//printf("rc=%d\n",rc);
//if (Saccountsw)                                                  //~v135R~
//  uerrmsg("\n%s executed %d times for %d directories and %d files.",//~v135R~
//                      "\n%s は %d 回 実行.(%d ディレクトリ, %d ファイル)",//~v135R~
//                      Scmdarg0[0],Scallctr,Sdirctr,Sfilectr);    //~v135R~
    completemsg();                                                 //~v135I~
  if (Slogosw)                                                     //~v124I~
        titlemsg();
	ARMXSUB_CLOSE(PGM);	//close for Arm subthread execution                                          //~v6B1I~//~vas2I~//+vas3I~
        return rc;
}//end main
//**********************************************************************//~v135I~
//* last msg                                                       //~v135I~
//*  parm:no parm                                                  //~v135I~
//*  return:none                                                   //~v135I~
//**********************************************************************//~v135I~
void completemsg(void)                                             //~v135I~
{                                                                  //~v135I~
	if (Saccountsw)                                                //~v135I~
    	uerrmsg("\n%s executed %d times for %d directories and %d files.",//~v135I~
                "\n%s は %d 回 実行.(%d ディレクトリ, %d ファイル)",//~v135I~
                 Scmdarg0[0],Scallctr,Sdirctr,Sfilectr);           //~v135I~
	return;                                                        //~v135I~
}//completemsg                                                     //~v135I~
//**********************************************************************
//* applycmd
//*  parm1:dir name
//*  parm2:fullpathname,0 if dir entry,or empty call
//*  parm3:PUDIRLIST,0 if empty entry
//*  parm4:depth
//*  parm5:appl data
//*  parm6:appl rc area
//*  return:0:continue walk,else stop walk
//**********************************************************************
int applycmd(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,
                                int Pdepth,void *Pdata,int *Prc)
{
        char *pc,*pcobj;
    char **cmdargv;
    int  rc,ii;
static char S1stsw=1;                                              //~v124I~
//**************************
    if (S1stsw)                                                    //~v124I~
    {                                                              //~van3I~
        setredirect(0);    //redirect                              //~v124I~
        Stopfpathlen=(int)strlen(Pdir);                            //~van3I~
    }                                                              //~van3I~
//  if (Straceopt)//command text printf                            //~v140R~
    if (Sdirtraceopt)//command text printf                         //~v140I~
        if ((!Pfullpath)        //fileentry or empty call              //~v124R~
        ||  (!Sdirsw && S1stsw))                                   //~v124R~
                        if (!Sredironlysw)                                     //~v124I~
            {                                                      //~v124R~
                        printf("\n==Dir==%s\n",Pdir);                      //~v124R~
                flushout();                                        //~v124R~
            }                                                      //~v124R~
        S1stsw=0;                                                      //~v124I~
  if (Sredironlysw)                                                //~v121I~
        rc=0;   //no confirm                                           //~v121I~
  else                                                             //~v121I~
  {                                                                //~v121I~
        if (!Ppudirlist) //empty call
            if (!Semptysw)
        {
                        pc=uerrsprintf("%s has no file(filemask=%s)\n",//~v172R~
                                   "%s には該当ファイルがありません(filemask=%s)\n",
                                Pdir,Sfilemask);
                        msgout(pc);
                return 0;
        }

    if (Pfullpath)      //fileentry
                pcobj=Pfullpath;
    else
                pcobj=Pdir;
        strcpy(Pdata,pcobj);
        rc=confirmchk(pcobj);   //confirm rejected                     //~v121I~
  }                                                                    //~v121R~
        switch(rc)      //confirm rejected                                 //~v121R~
    {
    case 0:     //go
        Scallctr++;                                                //~v124R~
//printf(":dir=%s,fullpath=%s\n",Pdir,Pfullpath);
        cmdargv=cmdedit(Pdir,Ppudirlist->name,Pfullpath);
        if (!Sredironlysw)                                           //~v121I~
        {                                                          //~va2jI~
        	if (Pfullpath)  //fileentry
            	Sfilectr++;
        	else
                Sdirctr++;
        }                                                          //~va2jI~
//        rc=execute(cmdargv,Pdepth,Pdata,Prc);                    //~v134R~
          rc=execute(cmdargv,Pdepth,Pdata,Prc,Pfullpath);          //~v134I~
        for (ii=0;pc=cmdargv[ii],pc;ii++)
                ufree(pc);
        ufree(cmdargv);
        break;
    case 1:     //cancel
        rc=0;           //continue walk
        break;
        case 2: //stop
        rc=8;           //return to main
        break;          //return to main
        }
        return rc;
}//applycmd
//**********************************************************************
//* execute
//*  parm1:user data ptr
//*  parm2:depth
//*  parm3:data ptr
//*  parm4:user rc area ptr
//*  parm5:fullpath name(0 if dir entry)                           //~v134I~
//*  return:0:continue walk,else stop walk
//**********************************************************************
int execute(char **Pargv,int Pdepth,char *Pdata,int *Prc,char *Pfullpath)//~v134R~
{
    int  rc;
    int ii;                                                        //~v124I~
    char *pc;
    char *fnm;                                                     //~v134I~
    LONGHANDLE ph;                                                 //~va99I~
//**************************
    flushout();
        if (Sexetype==1)                                               //~v122R~
    {
        if (Straceopt)//command text printf                        //~v124I~
        {                                                          //~v124I~
        	if (Pfullpath)                                         //~v134I~
            	fnm=Pfullpath+PATHLEN(Pfullpath);                  //~v134I~
            else                                                   //~v134I~
            	fnm=".\\";                                         //~v134R~
            printf("\n==Exe==(%-12s)==%s",fnm,Pargv[0]);           //~v134R~
            for (ii=1;Pargv[ii];ii++)                              //~v124I~
                                printf(" %s",Pargv[ii]);                           //~v124I~
                        printf("\n");                                          //~v124I~
            flushout();                                            //~v124I~
                }                                                          //~v124I~
//      rc=uspawnvp(P_WAIT,Pargv[0],Pargv);                        //~va99R~
        ph=uspawnvp(P_WAIT,Pargv[0],Pargv);                        //~va99I~
        rc=(int)ph;                                                //~va99I~
    }
        else
    {
        if (Straceopt)//command text printf                        //~v124I~
        {                                                          //~v124I~
        	if (Pfullpath)                                         //~v134I~
            	fnm=Pfullpath+PATHLEN(Pfullpath);                  //~v134I~
            else                                                   //~v134I~
            	fnm=".\\";                                         //~v134R~
                printf("\n==Cmd==(%-12s)==%s\n",fnm,Pargv[0]);     //~v134R~
            flushout();                                            //~v124I~
        }                                                          //~v124I~
        rc=usystem(Pargv[0]);
    }
    flushout();
        *Prc=rc;
    if (rc==-1)
    {
        pc=uerrsprintf("%s execution stopped for %s(level=%d,reason=%d)\n",
                                        "%s の %s への実行停止(level=%d,rc=%d)",
                                                        Pargv[0],Pdata,Pdepth,errno);
        msgout(pc);
        return 8;       //stop walk
        }
        return 0;
}//execute
//**********************************************************************
//* confirmchk
//*  parm1:dir/file name
//      return:1:confirm rejected,0:accepted
//**********************************************************************
int confirmchk(char *Pobj)
{
#ifdef UNX                                                         //~v141I~
#else  //!UNX                                                      //~v141I~
        char *pc;
    int rc;
    int ch;                                                        //~v122I~
#endif //!UNX                                                      //~v141I~
//**************************
        if (!Sconfirmsw)
        return 0;
#ifdef UNX                                                         //~v141I~
        return 0;                                                  //~v141I~
#else  //!UNX                                                      //~v141I~
        for(;;)
    {
        pc=uerrsprintf("%s ?,Enter \"Y\"(Yes),\"N\"(No),\"A\"(All) or Esc-",
                    "%s ?,\"Y\"(実行),\"N\"(取消),\"A\"(以後全実行),Esc(中止)-",
                   Pobj);
//      msgout(pc);
        cputs(pc);
        ch=getche();                                               //~v122R~
        switch(toupper(ch))                                        //~v122I~
        {
        case 0x1b:
                pc=uerrsprintf("\x0d\x0aExit requested",
                                "\x0d\x0aユーザーによる打切り");
                cputs(pc);
                rc=2;   //stop
                        break;
        case 'A':
                Sconfirmsw=0;
            rc=0;
            break;
        case 'Y':
            rc=0;
            break;
        case 'N':
                pc=uerrsprintf("\x0d\x0aexecution canceled by operator for %s",
                                                "\x0d\x0a実行は取り消されました(%s)",
                                                        Pobj);
//          msgout(pc);
            cputs(pc);
            rc=1;
            break;
                default:
                rc=-1;          //loop
        }
        cputs("\x0d\x0a");
        if (rc>=0)
                break;
    }
    return      rc;
#endif //!UNX                                                      //~v141I~
}//confirmchk
//**********************************************************************
//* msgout
//*     msg output by msglevel
//*  parm:msg
//      return:none;
//**********************************************************************
void msgout(char *Pmsg)
{
//**************************
    if (Smsgfh)
        fprintf(Smsgfh,"\n=*= %s\n",Pmsg);
        return;
}//msgout
//**********************************************************************
//* flushout
//* flush stdout/stderr
//**********************************************************************
void flushout(void)
{
//**************************
    fflush(stdout);
    fflush(stderr);
    return;
}//flushout
//**********************************************************************
//* setredirect
//  parm1:opt 0:redirect setup,1:restore redirect
//      return:none;
//**********************************************************************
void setredirect(int Popt)
{
//**************************
        if (!Sredirectsw)                       //no redirection
        return;
        flushout();
        if (!Popt)      //set req
        {
        switch(Sredirectsw)
        {
        case 1:                         //stdout to stderr
                        if (!uredirect(1,0,stderr))     //stdout,no fname,source fh
                    redirecterr("stdout","stderr");
            break;
        case 2:                         //stderr to stdout
                        if (!uredirect(2,0,stdout))     //stderr,no fname,source fh
                    redirecterr("stderr","stdout");
            break;
        case 3:                         //stdout and stderr to same file
                        if (!uredirect(3,Sredirectf1,0))        //stdout and stderr,fname,not opened
                    redirecterr("stdout/stderr",Sredirectf1);
            break;
        case 4:                         //stdout and stderr to each file
                        if (Sredirectf1)
                        if (!uredirect(1,Sredirectf1,0))        //stdout to file,not opened
                            redirecterr("stdout",Sredirectf1);
                        if (Sredirectf2)
                        if (!uredirect(2,Sredirectf2,0))        //stderr to file,not opened
                            redirecterr("stderr",Sredirectf2);
            break;
        }
    }
    else        //restore req
        {
        switch(Sredirectsw)
        {
        case 1:                         //stdout to stderr
                        if (uredirectrestore(1))        //restore stdout
                    redirectrestoreerr("stdout");
            break;
        case 2:                         //stderr to stdout
                        if (uredirectrestore(2))        //stderr,no fname,source fh
                    redirectrestoreerr("stderr");
            break;
        case 3:                         //stdout and stderr to same file
                        if (uredirectrestore(3))        //stdout and stderr,fname,not opened
                    redirectrestoreerr("stdout/stderr");
            break;
        case 4:                         //stdout and stderr to each file
                        if (Sredirectf1)
                        if (uredirectrestore(1))        //stdout to file,not opened
                        redirectrestoreerr("stdout");
                        if (Sredirectf2)
                        if (uredirectrestore(2))        //stderr to file,not opened
                        redirectrestoreerr("stderr");
            break;
        }//sw
    }//req type
        return;
}//setredirect
//**********************************************************************
//* redirecterr
//*  parm1:source
//*  parm2:target
//*  return:none(exit)
//**********************************************************************
void redirecterr(char *Psource,char *Ptarget)
{
        uerrexit("redirection failed,%s to %s\n",
                "%s から %s へのリダイレクト失敗\n",
            Psource,Ptarget);
        return;
}
//**********************************************************************
//* redirectrestoreerr
//*  parm1:resstore source
//*  return:none(exit)
//**********************************************************************
void redirectrestoreerr(char *Psource)
{
        uerrexit("redirection restore for %s is failed\n",
                "%s のリダイレクト戻しの失敗\n",
            Psource);
        return;
}//redirectrestoreerr

//**********************************************************************
//*getcmd
//*create cmd string and its argv format
//**********************************************************************
void getcmd(int Pargno,char **Pargv)
{
        FILE *fh;
    int  cmdlen=0,ii,rc;
    UINT ulen;
    char *cmd,*pc;                                                 //~v130R~
        char **argv;                                                   //~v130R~
    char buff[512];
                                                                   //~v141I~
#ifdef UNX                                                         //~v141I~
#else                                                              //~v141I~
    char fullpath[_MAX_PATH];
#endif                                                             //~v141I~
//**********************
        if (*Pargv[0]=='@')
    {
        if (!(fh=fopen(Pargv[0]+1,"r")))
                uerrapi1x("fopen",Pargv[0]+1,errno);
                while(fgets(buff,sizeof(buff),fh))
        {
//              ulen=strlen(buff);                                 //~vaa1R~
            ulen=(UINT)strlen(buff);                               //~vaa1I~
            cmdlen+=(int)ulen;
            if (*(buff+ulen-1)=='\n')
                break;
        }
        cmdlen--;
        cmd=umalloc((UINT)(cmdlen+2));  //string and argv          //~v122R~
        fseek(fh,0,SEEK_SET);
                fgets(cmd,cmdlen+2,fh);
        fclose(fh);
                *(cmd+cmdlen)=0;                //drop \n
//      ulen=strspn(cmd," ");                                      //~v128I~
        for (ii=0,pc=cmd;*pc;ii++,pc++)                            //~v128R~
            if (*pc!=' ' && *pc!='\t')                             //~v128I~
                break;                                             //~v128I~
        ulen=(UINT)ii;                                             //~v128I~
        strcpy(cmd,cmd+ulen);
        cmdlen-=(int)ulen;
//          if (rc=uparsev(cmd,(UCHAR***)(&argv),&Pargno,0,0),rc) //no delmtbl//~va64R~
            if (rc=uparsev(cmd,(UCHAR***)(ULPTR)(&argv),&Pargno,0,0),rc) //no delmtbl//~va64R~
                uerrexit("Error in cmd in file %s",
                                "コマンドファイル(%s)のコマンド行に誤りがあります",
                                        Pargv[0]+1);
    }
    else
    {
        argv=Pargv;
        for (ii=0;ii<Pargno;ii++,cmdlen++)
                cmdlen+=(int)strlen(Pargv[ii]);
        cmdlen--;       //last ++
        cmd=umalloc((UINT)(cmdlen+1));  //with last null
//*
        for (ii=0,pc=cmd;ii<Pargno;ii++)
        {
//              ulen=strlen(Pargv[ii]);                            //~vaa1R~
            ulen=(UINT)strlen(Pargv[ii]);                          //~vaa1I~
            memcpy(pc,Pargv[ii],ulen);
            pc+=ulen;
            *pc++=' ';
        }
        *(cmd+cmdlen)=0;        //last null
    }
#ifdef UNX                                                         //~v141I~
#else  //!UNX                                                      //~v141I~
    switch(uexecchk(argv[0],fullpath))
    {
    case 0:                     //not found on PATH or extention invalid
        if (!Sforcetype)
        {                                                          //~v125R~
//          uerrmsg("%s may not executable,try as shell command",  //~v125R~
//                  "%s は実行形式ファイルではありません,シェルコマンドとして実行します",//~v125R~
//                              argv[0]);                                      //~v125R~
                Sexetype=2; //use system                               //~v125R~
        }                                                          //~v125R~
        break;
    case 1:                     //.EXE
    case 2:                     //.COM
                Sexetype=1;     //use spawn
        break;
#ifdef DOS
    case 3:                     //.CMD
#else
#endif
    case 4:                     //.BAT
        Sexetype=2; //use system
        break;
    }
#endif //!UNX                                                      //~v141I~
        if (Sforcetype)
                Sexetype=Sforcetype;
//*
    Scmdstr0=cmd;
    Scmdarg0=argv;
    Scmdargno=Pargno;
}//getcmd
//**********************************************************************
//*edit cmd string
//* output by argv fmt(also for shell type,with  1 entry  cmd string)
//**********************************************************************
char **cmdedit(char *Pdir,char *Pfile,char *Pfullpath)
{
        int ii,argno,opt;
        char **ppcmdi,**ppcmdo;
    char basename[_MAX_PATH],*pc;                                  //~va2jI~
    char *cmdstri;
//  char *data[3];                                                 //~va2jR~
//  char *data[4];                                                 //~va2jI~//~van3R~
    char *data[5];                                                 //~van3I~
//************
//repl word
        if (Sexetype==1)        //use spawn;
    {
        argno=Scmdargno;
        ppcmdi=Scmdarg0;
        }
        else                            //use system
    {
        argno=1;                //edit full string at once
        cmdstri=Scmdstr0;
        ppcmdi=&cmdstri;
        }
//      ppcmdo=umalloc((UINT)((argno+1)<<2));                      //~vae1R~
        ppcmdo=umalloc(((size_t)argno+1)*sizeof(char *));          //~vae1I~
    data[0]=Pdir;           //dirname                              //~v138R~
    data[1]=Pfile;
                                                                   //~v138I~
  if (Pfullpath)    //file entry                                   //~v138M~
    data[2]=Pfullpath;
  else              //dir entry                                    //~v138M~
    data[2]=Pdir;                                                  //~v138I~
    pc=ustrrchr2(data[2],DIR_SEPC);          //basename %fb% data  //~va2jR~
    if (pc)                                                        //~va2jR~
        strcpy(basename,pc+1);                                     //~va2jI~
    else                                                           //~va2jI~
        strcpy(basename,data[2]);                                  //~va2jI~
    if (pc=strchr(basename,'.'),pc)                                //~va2jI~
    	*pc=0;                                                     //~va2jI~
    data[3]=basename;                                              //~va2jI~
    data[4]=Pdir+Stopfpathlen;          //%rp%                     //~van3I~
                                                                   //~v138I~
//  opt=Snullsw;                                                   //~v130R~
    opt=(Snullsw|WORDREP_IC);           //case incensitive             //~v130I~
    if (Ssw_altsign)                                               //~van4I~
        opt|=WORDREP_ALTSIGN;                                      //~van4I~
        for (ii=0;ii<argno;ii++)
        ppcmdo[ii]=uwordrep(opt,ppcmdi[ii],Scmdrepword,data,0,0);//no ctr output
    ppcmdo[argno]=0;    //last null
    return ppcmdo;
}//cmdedit

//**********************************************************************
//*too long cmd arg
//**********************************************************************
void errtoolongcmd(void)
{
        uerrexit("too long cmd string(over %d) ",
                "コマンド文字列が長過ぎる(最大 %d)",
                                MAXCMDSZ);      //cmd edit buff size
        return;
}//errtoolongcmd
////**********************************************************************//~v174R~
////*too long cmd arg                                              //~v174R~
////**********************************************************************//~v174R~
//void errrepandopt(char *Prepw)                                   //~v174R~
//{                                                                //~v174R~
//        uerrexit("%s in cmd-string and %cYf option is exclusive",//~v174R~
//                        "コマンド文字列中の %s と %cYf オプションが矛盾します",//~v174R~
//                Prepw,CMDFLAG_PREFIX);                           //~v174R~
//        return;                                                  //~v174R~
//}//errrepandopt                                                  //~v174R~

//**********************************************************************
//*parameter chk
//**********************************************************************
void parmchk(int parmc,char *parmp[])
{
    unsigned char c;    //read char
    char *cptr,*cptr0;         //char ptr work
    int parmno; //parm count work
    int posparmno=0; //parm count work
    int cmdparmno=0; //cmd parm count
    int redirsw1=0,redirsw2=0;
#ifdef UNX                                                         //~v141I~
#else  //!UNX                                                      //~v141I~
    int attrflg;
#endif //!UNX                                                      //~v141I~
    int pathlen;                                                   //~v131I~
    char **ppcmdstr=0;
    char parmchar=0;                                               //~van4I~
//*************************
    if (parmc<2 || *parmp[1]=='?')
    {
      help();
      exit(0);
    }
//*******************************
//* parm process                *
//*******************************
    for (parmno=1;parmno<parmc;parmno++)
    {
        cptr=cptr0=parmp[parmno];
        if (cmdparmno)          //already cmd started
        {
                        if (*ppcmdstr[0]=='@')
                        uerrexit("cmdfile specification(%s) must be on last\n",
                                 "コマンドファイル指定(%s)は最後に指定する\n",
                                                        ppcmdstr[0]);
                cmdparmno++;
                continue;
                }
#ifdef UNX                                                         //~v141I~
        if(*cptr==CMDFLAG_PREFIX)                                  //~v141I~
#else  //!UNX                                                      //~v141I~
        if(*cptr=='/'||*cptr=='-')
#endif //!UNX                                                      //~v141I~
        {//option
                c=*(++cptr);                      //first option byte
            switch(toupper(c))             //option
            {
//**************************
//* cmd string     /?      *
//**************************
            case '?':           //cmd string start
            case 'H':           //apply to file
                help();
                exit(0);
                break;
//**************************
//* cmd string     //      *
//**************************
            case '/':           //cmd string start
            case '-':           //apply to file
                parmp[parmno]+=2;       //drop //
                ppcmdstr=parmp+parmno;
                cmdparmno=1;
                break;
//**************************
//* stdout option  /1      *
//**************************
            case '1':           //apply to file
                    c=*(++cptr);
                    switch(c)
                    {
                    case   0:       //deney
                        Sredirectf1=0;
                        redirsw1=0;
                                break;
                    case '2':       //to std err
                        Sredirectf1=0;
                        redirsw1=2;
                                break;
                    default:                           //not option
                        Sredirectf1=cptr;
                        redirsw1=0;
                        }
                break;
//**************************
//* stderr option  /2      *
//**************************
            case '2':           //redirect
                    c=*(++cptr);    //intermediate file ussage
                    switch(c)
                    {
                    case   0:       //no file
                        Sredirectf2=0;
                        redirsw2=0;
                                break;
                    case '1':       //to std err
                        Sredirectf2=0;
                        redirsw2=1;
                                break;
                    default:                           //not option
                        Sredirectf2=cptr;
                        redirsw2=0;
                        }
                break;
#ifdef UNX                                                         //~v141I~
#else  //!UNX                                                      //~v141I~
//**************************                                       //~v141I~
//* confirm option /A       *
//**************************
            case 'A':           //attrmask
                attrflg=0;      //default on
                                c=*(cptr+1);
                if (c!='+' && c!='-')   //rep mode
                        Sattrmask=FILE_READONLY+FILE_ARCHIVED;
                    for (;;)
                {
                                        c=*(++cptr);
                    if (!c)
                        break;
                    switch(toupper(c))
                    {
                    case '+':           //no parm
                        attrflg=0;              //attr on
                        break;
                    case '-':           //no parm
                        attrflg=1;              //attr off
                        break;
                    case 'D':           //archive
                        if (attrflg)    //reset
                                        UCBITOFF(Sattrmask,FILE_DIRECTORY);
                                                else
                                        UCBITON(Sattrmask,FILE_DIRECTORY);
                                break;
                    case 'H':           //hidden
                        if (attrflg)    //reset
                                        UCBITOFF(Sattrmask,FILE_HIDDEN);
                                                else
                                        UCBITON(Sattrmask,FILE_HIDDEN);
                                break;
                    case 'S':           //system
                        if (attrflg)    //reset
                                        UCBITOFF(Sattrmask,FILE_SYSTEM);
                                                else
                                        UCBITON(Sattrmask,FILE_SYSTEM);
                                break;
                    default:                           //not option
                                optionerr("attribute",cptr0);
                                }
                        }//all attr char
                break;
#endif //!UNX                                                      //~v141I~
//**************************                                       //~van4I~
//* parm char                                                      //~van4I~
//**************************                                       //~van4I~
            case 'C':                                              //~van4I~
                parmchar=*(++cptr);                                //~van4I~
                break;                                             //~van4I~
//**************************
//* stop dir level /L      *
//**************************
            case 'L':           //apply to file
                Sstopdepth=atoi(++cptr);
                break;
//**************************
//* order  option  /O      *
//**************************
            case 'O':           //msg redirection
                    c=*(++cptr);                                       //~v122R~
                    c=(char)toupper(c);                                //~v122I~
                    if (c=='-') //reverse
                {
                    Srevsortsw=1;
                            c=*(++cptr);                                   //~v122R~
                            c=(char)toupper(c);                            //~v122I~
                }
                    switch(c)
                    {
                    case 'N':       //name
                    case 'E':       //extention
                    case 'D':       //date
                    case 'S':       //size
                    case '0':       //no sort
                                Ssortorder=c;
                                break;
                    default:                           //not option
                        optionerr("Order",cptr0);
                        }
                break;
//**************************                                       //~v126I~
//* apply type     /P      *                                       //~v126I~
//**************************                                       //~v126I~
            case 'P':           //msg redirection                  //~v126I~
                    c=*(++cptr);                                       //~v126I~
                    c=(char)toupper(c);                                //~v126I~
                    switch(c)                                          //~v126I~
                    {                                                  //~v126I~
                    case 'F':       //name                             //~v126I~
                                Sfilesw=1;                                     //~v126I~
                                Sdirsw=0;                                      //~v126I~
                                break;                                         //~v126I~
                    case 'D':       //extention                        //~v126I~
                                Sfilesw=0;                                     //~v126I~
                                Sdirsw=1;                                      //~v126I~
                                break;                                         //~v126I~
                    case 'B':       //date                             //~v126I~
                                Sfilesw=1;                                     //~v126I~
                                Sdirsw=1;                                      //~v126I~
                                break;                                         //~v126I~
                    case 'N':       //size                             //~v126I~
                                Sfilesw=0;                                     //~v126I~
                                Sdirsw=0;                                      //~v126I~
                                break;                                         //~v126I~
                    default:                           //not option    //~v126I~
                        optionerr("Apply type",cptr0);                 //~v126I~
                        }                                                  //~v126I~
                break;                                             //~v126I~
//**************************
//* Word           /X      *                                       //~v125R~
//**************************
//          case 'X':           //msg redirection                  //~v125R~
//                  c=*(++cptr);                                       //~v125R~
//                  c=(char)toupper(c);                                //~v125R~
//                  switch(c)                                          //~v125R~
//                  {                                                  //~v125R~
//                  case 'E':       //name                             //~v125R~
//                      Sforcetype=1;   //use spawn                    //~v125R~
//                              break;                                         //~v125R~
//                  case 'B':       //extention                        //~v125R~
//                  case 'C':       //date                             //~v125R~
//                      Sforcetype=2;   //use system                   //~v125R~
//                              break;                                         //~v125R~
//                  default:                           //not option    //~v125R~
//                      optionerr("Exe type",cptr0);                   //~v125R~
//                      }                                                  //~v125R~
//              break;                                             //~v125R~
//**************************
//* yes    option  /Y      *
//**************************
            case 'Y':           //toggle on
                for (;;)
                {
                    c=*(++cptr);
                    if (!c)
                        break;
                    switch(toupper(c))
                    {
                    case 'A':       //account msg                  //~v124I~
                                Saccountsw=1;                              //~v124I~
                                break;                                     //~v124I~
#ifdef UNX                                                         //~v141I~
#else  //!UNX                                                      //~v141I~
                    case 'C':       //directory
                                Sconfirmsw=1;
                                break;
#endif //!UNX                                                      //~v141I~
                                                                   //~v141I~
//                  case 'D':       //directory                    //~v126R~
//                              Sdirsw=1;                                  //~v126R~
//                              break;                                     //~v126R~
#ifdef UNX                                                         //~v171I~
                    case 'D':       //device                       //~v171I~
                                Sspfsw=1;   //specialfile          //~v171I~
                                break;                             //~v171I~
#endif //UNX                                                       //~v171I~
                    case 'E':       //empty call for file req
                                Semptysw=1;
                                break;
//                  case 'F':       //file                         //~v126R~
//                              Sfilesw=1;                                 //~v126R~
//                              break;                                     //~v126R~
                    case 'H':       //file
                                Scdsw=1;        //change dir
                                break;
//#ifdef UNX                                                         //~v172I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71R~
                    case 'K':       //no dir                       //~v172I~
                        Sskipslinksw=0;                            //~v172I~
                        break;                                     //~v172I~
#endif                                                             //~v172I~
                    case 'L':       //logo msg                     //~v124I~
                                Slogosw=1;  //write title msg              //~v124I~
                                break;                                     //~v124I~
//#ifdef UNX                                                         //~v173I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71R~
                    case 'M':       //no dir                       //~v173I~
                      	Gufile_opt&=~GFILEOPT_NOSLINKERRMSG;       //~v173I~
                        break;                                     //~v173I~
#endif                                                             //~v173I~
                    case 'N':       //file
                                Snullsw=WORDREP_NODATANULL;     //nullify not used keyword
                                break;
                    case 'S':       //file                         //~v140I~
                                Sdirtraceopt=1;//command text printf//~v140I~
                                break;                             //~v140I~
                    case 'T':       //file                         //~v124I~
                                Straceopt=1;//command text printf          //~v124I~
                                break;                                     //~v124I~
                    case 'X':       //exe type                     //~v125I~
                        Sforcetype=1;   //use spawn                //~v125I~
                                break;                                     //~v125I~
                    case '9':       //dbcs sw
                                        UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                                        UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs
                                break;
                    default:                           //not option
                                optionerr("Yes/No option",cptr0);
                        }
                        }
                break;
//**************************
//* no     option  /N      *
//**************************
            case 'N':           //toggle on
                for (;;)
                {
                    c=*(++cptr);
                    if (!c)
                        break;
                    switch(toupper(c))
                    {
                    case 'A':       //account msg                  //~v124I~
                                Saccountsw=0;                              //~v124I~
                                break;                                     //~v124I~
#ifdef UNX                                                         //~v141I~
#else  //!UNX                                                      //~v141I~
                    case 'C':       //directory
                                Sconfirmsw=0;
                                break;
#endif //!UNX                                                      //~v141I~
                                                                   //~v141I~
//                  case 'D':       //directory                    //~v126R~
//                              Sdirsw=0;                                  //~v126R~
//                              break;                                     //~v126R~
#ifdef UNX                                                         //~v171I~
                    case 'D':       //device                       //~v171I~
                                Sspfsw=0;   //specialfile          //~v171I~
                                break;                             //~v171I~
#endif //UNX                                                       //~v171I~
                    case 'E':       //empty call for file req
                                Semptysw=0;
                                break;
//                  case 'F':       //file                         //~v126R~
//                              Sfilesw=0;                                 //~v126R~
//                              break;                                     //~v126R~
                    case 'H':       //file
                                Scdsw=0;        //change dir
                                break;
//#ifdef UNX                                                         //~v172I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71R~
                    case 'K':       //no dir                       //~v172I~
                        Sskipslinksw=1;                            //~v172I~
                        break;                                     //~v172I~
#endif                                                             //~v172I~
                    case 'L':       //logo msg                     //~v124I~
                                Slogosw=0;  //write title msg              //~v124I~
                                break;                                     //~v124I~
//#ifdef UNX                                                         //~v173I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71R~
                    case 'M':       //no dir                       //~v173I~
                      	Gufile_opt|= GFILEOPT_NOSLINKERRMSG;       //~v173I~
                        break;                                     //~v173I~
#endif                                                             //~v173I~
                    case 'N':       //file
                                Snullsw=0;      //nullify not used keyword
                                break;
                    case 'S':       //file                         //~v140I~
                                Sdirtraceopt=0;//command text printf//~v140I~
                                break;                             //~v140I~
                    case 'T':       //file                         //~v124I~
                                Straceopt=0;//command text printf          //~v124I~
                                break;                                     //~v124I~
                    case 'X':       //exe type                     //~v125I~
                        Sforcetype=0;   //use spawn                //~v125I~
                                break;                                     //~v125I~
                    case '9':       //dbcs sw
                                        UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                                        UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs
                                break;
                    default:                           //not option
                                optionerr("Yes/No option",cptr0);
                        }
                        }
                break;
            default:                           //not option
                uerrexit("undefined option parm(%s)\n",
                                        "未定義パラメータ(%s)\n",
                                                cptr0);
            }//switch  by first option byte
            continue;
                }//option
//pos parm
                posparmno++;
                switch (posparmno)
                {
//**************************
//* top dir                *
//**************************
                case  1:          //first parm
                        Sdir=cptr0;
                    	if (WILDCARD(Sdir))                        //~v131I~
                        {                                          //~v131I~
                            pathlen=PATHLEN(Sdir);                 //~v131I~
                            if (pathlen>0)  //root dir             //~v131I~
                            {                                      //~v131I~
                                strcpy(Sfnmask,Sdir+pathlen);      //~v131I~
                                Sfilemask=Sfnmask;                 //~v131I~
				                posparmno++;                       //~v131I~
                                if (pathlen!=1                     //~v131R~
                                &&  (pathlen!=3 || *(Sdir+1)!=':')) //root//~v131I~
                                    pathlen--;                     //~v131I~
                                *(Sdir+pathlen)=0;  //drop \ last  //~v131I~
                                                                   //~v131I~
							}                                      //~v131I~
                        }                                          //~v131I~
                        break;
//**************************
//* file mask              *
//**************************
                case 2:
                        Sfilemask=cptr0;
                        break;
//**************************
//* dir  mask              *
//**************************
                case 3:
                        Sdirmask=cptr0;
                        break;
//************************************
                default:
                        uerrexit("too many %s positional parameter(%s)\n",
                                 "多過ぎる %s の定位置パラメータ(%s)\n",
                                                Spgm,cptr0);
                }//switch by parmno
        }//for all parm
//chk more
        if (!cmdparmno)
        uerrexit("%c%cCommand-string parameter missing\n",         //~v174R~
                        "%c%cコマンド文字列パラメータが欠けています",//~v174R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v174I~
        if (Semptysw && !Sfilesw)
        uerrexit("%cYe is effective only when apply to file(%cPf or %cPb)\n",//~v174R~
                        "%cYe は ファイル適用(%cPf,%cPb)のときにのみ有効です",//~v174R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX); //~v174I~
        if (redirsw1 && redirsw2)
        uerrexit("intermixed redirection parameter\n",
                        "リダイレクト指定が矛盾しています");
        if (Sredirectf1 && redirsw2)
        Sredirectf2=Sredirectf1;                //same file
        if (Sredirectf2 && redirsw1)
        Sredirectf2=Sredirectf1;                //same file
        if (Sredirectf1)
    {
        if (!ufullpath(Sredirectf1fp,Sredirectf1,sizeof(Sredirectf1fp)))
                exit(8);
                Sredirectf1=Sredirectf1fp;
        }
        if (Sredirectf2)
    {
        if (!ufullpath(Sredirectf2fp,Sredirectf2,sizeof(Sredirectf2fp)))
                exit(8);
                Sredirectf2=Sredirectf2fp;
        }
        Sredirectsw=0;                                          //no redirection id
        if (Sredirectf1 || Sredirectf2) //redir to file
        if (Sredirectf1 && Sredirectf2
        &&  !stricmp(Sredirectf1,Sredirectf2))
                Sredirectsw=3;                          //to same file
                else
                Sredirectsw=4;              //to each file
        else                                                    //no file redirect
        if (redirsw1)
                Sredirectsw=1;                          //stdout to stderr
                else
                if (redirsw2)
                Sredirectsw=2;         //stderr to stderr
    if (!posparmno)                                                //~v121M~
    {                                                              //~v121I~
        if (!Sredirectsw)                                          //~v121I~
//      uerrexit("Sdir-name parameter missing\n",                  //~v121I~
//                      "ディレクトリー名を指定して下さい");               //~v121I~
            uerrexit("dir-name or redirect parameter is required\n",//~v121I~
                                "ディレクトリー名かリダイレクトオプションを指定して下さい");//~v121I~
//      uerrmsg("Missing Dir-name parm,Cmd execute only once",     //~v137R~
//               "ディレクトリー名の指定がありませんコマンドは一回のみ実行されます");//~v137R~
        Sredironlysw=1;                                            //~v121I~
    }                                                                  //~v121I~
    else                                                           //~v121I~
        if (!Sfilesw && !Sdirsw)                                   //~v121I~
                uerrexit("%cPn is invalid when directory specified.\n",//~v174R~
                                "ディレクトリーを指定した時は%cPnは無効です\n",//~v174R~
					CMDFLAG_PREFIX);                               //~v174I~
//*cmd string create
        getcmd(cmdparmno,ppcmdstr);
    if (parmchar!=0)                                               //~van4I~
    {                                                              //~van4I~
        Ssw_altsign=1;                                             //~van4I~
    	int ii;                                                    //~van4I~
    	for (ii=0;;ii++)                                           //~van4I~
        {                                                          //~van4I~
			if (!Scmdrepword[ii])                                  //~van4R~
            	break;                                             //~van4I~
			*Scmdrepword[ii]=parmchar;                             //~van4R~
			*(Scmdrepword[ii]+(int)strlen(Scmdrepword[ii])-1)=parmchar;//~van4R~
		}                                                          //~van4I~
    }                                                              //~van4I~
}//parmchk
//**********************************************************************
//* write option err msg  v3.8a
//**********************************************************************
void optionerr(char *type,char* value)
{
        uerrexit("invalid %s option parm value(%s)\n",
                         "%s の値(%s)の誤り\n",
                        type,value);
}//optionerr


//**********************************************************************
//* write help msg
//**********************************************************************
void help(void)
{
//*******************
        HELPMSG
"%s : utility apply command to all sub-directories\n",
"%s : コマンドの全サブディレクトリーへの適用ツール\n",
                Spgm);
        HELPMSG
"fmt  : %s [directory] [file-mask] [dir-mask] [%coptions]  %c%ccmd-string\n",//~v141R~
"形式 : %s [directory] [file-mask] [dir-mask] [%coptions]  %c%ccmd-string\n",//~v141R~
                Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~v141R~
        HELPMSG
"  directory :directory under which command-string is executed.\n",
"  directory :コマンド文字列を実行するディレクトリー\n");
        HELPMSG                                                        //~v121I~
"             it is optional for cmd output redirection.\n",       //~v121R~
"             出力のリダイレクションが目的の場合指定しなくてもよい\n");//~v121R~
        HELPMSG
"  file-mask :file selective wild card mask\n",
"  file-mask :ファイル選択のワイルドカード指定\n");
        HELPMSG
"  dir-mask  :directory selective wild card mask\n",
"  dir-mask  :ディレクトリー選択のワイルドカード指定\n");
        HELPMSG
"  cmd-string:specify command with its parms\n",
"  cmd-string:コマンドとそのパラメータを指定\n");
        HELPMSG
"             for indirect by 1 line cmd file,use %c%c@cmdfile format.\n",//~v141R~
"             %c%c@cmdfile 形式で一行コマンドファイルも指定可\n",  //~v141R~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);                    //~v141R~
        HELPMSG
//"             use %s,%s,%s for pathname,file-name,fullpath each.\n",//~va2jR~
//"             %s,%s,%s を各々経路名,ファイル名,フルパス名に使用可.\n",//~va2jR~
//                                        Scmdrepword[0],Scmdrepword[1],Scmdrepword[2],Scmdrepword[3]);//~va2jR~
//"             use %s,%s,%s,%s for path,file,fullpath,base name each.\n",//~va2jR~//~van3R~
//"             %s,%s,%s,%s を各々経路,ファイル,フルパス,ベース名に使用可.\n",//~va2jR~//~van3R~
//                                        Scmdrepword[0],Scmdrepword[1],Scmdrepword[2],Scmdrepword[3]);//~va2jI~//~van3R~
"             use %s,%s,%s,%s,%s for path,file,fullpath,base name each.\n",//~van3I~
"             %s,%s,%s,%s,%s を各々経路,ファイル,フルパス,ベース名に使用\n",//~van3R~
                                        Scmdrepword[0],Scmdrepword[1],Scmdrepword[2],Scmdrepword[3],Scmdrepword[4]);//~van3I~
        HELPMSG                                                    //~van3I~
"             %s is relative path from top dir(top is \"\").\n",   //~van3I~
"             %s は トップDirからの相対パス、トップは \"\"\n",     //~van3I~
                                        Scmdrepword[4]);           //~van3I~
        HELPMSG                                                    //~v138I~
"             (%s is replaced to dir-name when %cPd.)\n",          //~v141R~
"             (%s は %cPd のときはディレクトリー名に置換されます.)\n",//~v141R~
                         Scmdrepword[1],CMDFLAG_PREFIX);           //~v141R~
        HELPMSG                                                        //~v131I~
"             in .BAT or .CMD file or on command line input under Win95,\n",//~v133R~
"             .BAT や .CMD ファイル またはWindows95 のＤＯＳ窓のコマンド入力では\n");//~v133R~
        HELPMSG                                                    //~v132I~
"             use doubled %% like as %%%%f%%%%.\n",                //~v138R~
"             %%%%f%%%% のように 1 つの %% に ２ 個の %% が必要\n");//~v138R~
        HELPMSG
"  options   :\n",
"  options   :\n");
        HELPMSG
"    %c1file  :redirection of stdout(\"2\" mean stderr)\n",        //~v141R~
"    %c1file  :標準出力の出力先変更(\"2\" は標準エラー出力)\n",    //~v174R~
				CMDFLAG_PREFIX);                                   //~v141I~
        HELPMSG
"    %c2file  :redirection of stderr(\"1\" mean stdout)\n",        //~v141R~
"    %c2file  :標準エラー出力の出力先変更(\"1\" は標準出力)\n",    //~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
#ifdef UNX                                                         //~v141I~
#else  //!UNX                                                      //~v141I~
        HELPMSG
"    %cAattr  :file/dir selective attribute mask\n",               //~v141R~
"    %cAattr  :ファイル属性による選択指定\n",                      //~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
        HELPMSG
"            :attr=S,H,D(default is SH).'+'/'-' can  be prefixed.\n",//~v131R~
"            :attr=S,H,D(省略値は SH),'+'/'-'を前付けできる\n");
#endif //!UNX                                                      //~v174M~
        HELPMSG                                                    //~van4I~
"    %cCx     :change parameter sign to x. (e.g) $fp$ by %cC$.\n", //~van4I~
"    %cCx     :パラメータ指定文字に x を使う、例えば %cC$ で $fp$\n",//~van4I~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);                    //~van4I~
        HELPMSG
"    %cLlevel :dig directory up to the depth(0 mean starting dir,Default=4096)\n",//~v141R~
"    %cLlevel :掘り下げるディレクトリーの深さ(0が開始ディレクトリー,省略値=4096)\n",//~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
        HELPMSG
"    %cO[-]ord:cmd apply file sequence in a directory.\n",         //~v141R~
"    %cO[-]ord:コマンドを適用するファイルの順序.\n",               //~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
        HELPMSG
"             N:name,E:extention+name,D:date,S:size,0:no sort(default is 'N')\n",
"             N:名前,E:拡張子,D:日付,S:サイズ,0:配置順(省略値は'N')\n");
        HELPMSG                                                        //~v126I~
"    %cPapply :potatoes type.(default is 'f')\n",                  //~v141R~
"    %cPapply :コマンド適用タイプ(省略値は'f')\n",                 //~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
        HELPMSG                                                        //~v126I~
"             f:File, d:Dir, b:Both, n:None(for use redirection)\n",//~v124R~
"             f:ファイル, d:ディレクトリー, b:両方, n:リダイレトのみの使用\n");//~v124R~
//      HELPMSG                                                        //~v125R~
//"    /Xtype  :Force file type.E:exe,B/C:bat/cmd\n",              //~v125R~
//"    /Xtype  :実行ファイルのタイプを強制する.E:exe,B/C:bat/cmd.\n");//~v125R~
        HELPMSG
"    %cYsw or :toggle options.\n",                                 //~v141R~
"    %cYsw又は:オン/オフ タイプスィッチ\n",                        //~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
        HELPMSG
"      %cNsw  :sw is as following,default is in ()\n",             //~va3qR~
"      %cNsw  :sw に以下の文字を指定する,()は省略値\n",            //~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
                                                                   //~v141I~
#ifdef UNX                                                         //~v141I~
#else  //!UNX                                                      //~v141I~
        HELPMSG
"          c :confirm before each cmd call.(%cNc)\n",              //~v141R~
"          c :コマンドを実行する前に確認を取る(%cNc)\n",           //~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
#endif //!UNX                                                      //~v141I~
                                                                   //~v141I~
//      HELPMSG                                                        //~v126R~
//"          d :call for directory(/Nd)\n",                        //~v126R~
//"          d :ディレクトリーにコマンドを適用する(/Nd)\n");       //~v126R~
//      HELPMSG                                                        //~v126R~
//"             (no data set to %s,%s)\n",                         //~v126R~
//"             (この時 %s,%sに設定するはデータはありません)\n",   //~v126R~
//                                      Scmdrepword[1],Scmdrepword[2]);                //~v126R~
#ifdef UNX                                                         //~v171R~
        HELPMSG                                                    //~v171I~
"          d :apply to special file(pipe,socket,device).(%cNd)\n", //~v171I~
"          d :パイプ、ソ\ケット、デバイス等、特殊ファイルにも適用。(%cNd)\n",//~v171R~
				CMDFLAG_PREFIX);                                   //~v171I~
#endif                                                             //~v171I~
        HELPMSG
"          e :call also when directory is empty(%cNe)\n",          //~va3qR~
"          e :ディレクトリーが空のときもにコマンドを適用する(%cNe)\n",//~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
//      HELPMSG                                                        //~v126R~
//"          f :call for file(/Yf)\n",                             //~v126R~
//"          f :ファイルにコマンドを適用する(/Yf)\n");             //~v126R~
        HELPMSG
"          h :change directory for each call(%cYh)\n",             //~v141R~
"          h :現行ディレクトリーを設定しつつコマンドを実行する(%cYh)\n",//~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
//#ifdef UNX                                                         //~v172I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71R~
        HELPMSG                                                    //~v172I~
//"          k :process symbolic link(%cYk)\n",                      //~v172I~//~va71R~
//"          k :シンボリックリンクも処理する(%cYh)\n",               //~v172I~//~va71R~
"          k :process symbolic link member(%cYk)\n",               //~va71I~
"          k :シンボリックリンクメンバーも処理する(%cYk)\n",       //~va71I~
				CMDFLAG_PREFIX);                                   //~v172I~
        HELPMSG                                                    //~v173I~
"          m :Output symbolic link err msg (%cYm)\n",              //~v173R~
"          m :シンボリックリンクエラーMsgを出力するか。(%cYm)\n",  //~v173R~
				CMDFLAG_PREFIX);                                   //~v173I~
#endif                                                             //~v172I~
        HELPMSG
"          n :set null value when no parm data for %s,%s,... (%cNn)\n", //~v141R~//~van4R~
"          n :%s,%sなどにデータが無い時それをNULLに置換する(%cNn)\n",  //~v141R~//~van4R~
                Scmdrepword[1],Scmdrepword[2],CMDFLAG_PREFIX);     //~v141R~
//        HELPMSG                                                  //~v140R~
//"          t :trace executed command text and subdir(/Yt)\n",    //~v140R~
//"          t :サブディレクトリー名と実行コマンドを標準出力に書き出す(/Yt)\n");//~v140R~
        HELPMSG                                                    //~v140I~
"          s :print each subdir(%cYs)\n",                          //~v141R~
"          s :サブディレクトリー名を標準出力に書き出す(%cYs)\n",   //~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
        HELPMSG                                                    //~v140I~
"          t :trace executed command text(%cNt)\n",                //~v141R~
"          t :実行コマンドを標準出力に書き出す(%cNt)\n",           //~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
                                                                   //~v141I~
#ifdef UNX                                                         //~v141I~
        HELPMSG                                                    //~v141I~
"          x :use 'spawn'(not 'system' function).(%cNx)\n",        //~v141R~
"          x :spawnで実行（system関数でなく)(%cNx)\n",             //~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
#else  //!UNX                                                      //~v141I~
        HELPMSG                                                        //~v125I~
"          x :use 'spawn'(not 'system' function).(%cNx when invalid ext-name)\n",//~v141R~
"          x :spawnで実行（system関数でなく)(拡張子エラーの時は %cNx)\n",//~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
#endif //!UNX                                                      //~v141I~
                                                                   //~v141I~
        HELPMSG
"(ex.): %s dirabc %c21 %cpd %c/grep \"srch-word\" %s      ::dir operation\n",//~v141R~
"(例) : %s dirabc %c21 %cpd %c/grep \"srch-word\" %s      ::ディレクトリ操作\n",//~v141R~
        Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,Scmdrepword[0]);//~v141R~
        HELPMSG
"       %s dirabc *.c  %c%c@foo           ::command file,file operation\n",//~v141R~
"       %s dirabc *.c  %c%c@foo            ::コマンドファイル,ファイル操作\n",//~v141R~
        Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);        //~v141R~
        HELPMSG                                                        //~v121I~
"       %s %c2wkf %c%cgetstder parm1                  ::redirection only\n",//~v141R~
"       %s %c2wkf %c%cgetstder parm1                     ::リダイレクション\n",//~v141R~
        Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);        //~v141R~
        HELPMSG                                                    //~van3I~
"       %s topdir *.html %cNh %c%cxcv %%fp%% outdir%c%%rp%%%c%%f%% %cs2f   ::relative path\n",//~van3R~
"       %s topdir *.html %cNh %c%cxcv %%fp%% outdir%c%%rp%%%c%%f%% %cs2f   ::相対パス\n",//~van3R~
        Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,DIR_SEPC,DIR_SEPC,CMDFLAG_PREFIX);//~van3R~
        HELPMSG                                                    //~van4I~
"       %s d1 *.html %cNh %cC$ %c%cxcv $fp$ d2%c$rp$%c$f$ %cs2f ::alternative sign\n",//~van4R~
"       %s d1 *.html %cNh %cC$ %c%cxcv $fp$ d2%c$rp$%c$f$ %cs2f ::パラメータ文字\n",//~van4R~
        Spgm,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,DIR_SEPC,DIR_SEPC,CMDFLAG_PREFIX);//~van4I~
        titlemsg();
        return;
}//help
//**********************************************************************
//* write help msg
//**********************************************************************
void titlemsg(void)
{
        HELPMSG
"%s:%s(%c):%s: ===================================== by ONGA-gun ===\n",//~v171R~
"%s:%s(%c):%s: ===================================== by 遠賀君邑 ===\n",//~v171R~
    Spgm,Sver,OSTYPE,__DATE__);                                    //~v130R~
        return;
}//titlemsg
