//*CID://+vak2R~:                             update#=   85;       //+vak2R~
//***********************************************************
//* xkp    : kill/list process
//***********************************************************
//vak2:180821 xkp 1.4: At XP fullpath was displayed and /l show pid and shortpath by the reason of PSAPI and windows version//+vak2I~
//vak1:180819 xkp 1.4: bt /V option display fullpathname           //~vak1I~
//va9t:150529 xkp v1.3 parm count error(by xuerpck)                //~va9tI~
//va98:150118 xkp 1.2 cbfunc parm was changed                      //~va98I~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va3cI~
//va3c:070709 xkp:1.1 display parent pid                           //~va3cI~
//va2m:060907 xkp:1.0 list/kill pid;1st virsion
//***********************************************************
#define VER  "1.4"                                                 //~va3cR~//~va98R~//~va9tR~//~vak1R~
   #include <stdio.h>
   #include <stdlib.h>
   #include <conio.h>

   #include <windows.h>


   #include <ulib.h>
   #include <ualloc.h>
   #include <uerr.h>
   #include <uproc2.h>
   #include <uedit.h>
   #include <ustring.h>
//***********************************************************
typedef struct _PIDLIST{
                        ULONG PLpid;
                        char *PLfnm;
                       } PIDLIST,*PPIDLIST;
#define PIDLISTSZ sizeof(PIDLIST)
//***********************************************************
#define PGM "xkp"
#define MAXPID_BYNAME 500
//#define MINPID_KILL   0x100 //to kill pid under this number,sepecify -ff//~va2mR~

static PPIDLIST  Sppl;
static int       Spplctr;

static int Sopt=0;
#define OPT_LIST         0x01
#define OPT_NOCONFIRM    0x02
//#define OPT_NOCONFIRM2   0x04   //kill small number of pid(<256) //~va2mR~
#define OPT_BYNAME       0x08
#define OPT_BYPID        0x10
#define OPT_VERBOSE      0x20   //display parent pid               //~va3cI~
//#define OPT_VERBOSE2     0x40   //display parent pid,fullpathname  //~vak1I~//+vak2R~

static char *Sselectname=0;
//***********************************************************
int help(void);
char confirm(char *Pmsge,char *Pjmsg,char *Preply);
CB_ENUMPID cbenumpid;                                              //~va98I~
//***********************************************************
int main(int argc,char **argp)
{
//  CB_ENUMPID cbenumpid;                                          //~va98R~
	char *pc,**popd,*preason;
    int pidctr=0,ii,len,rc,exitcode=99;
	PPIDLIST ppl;
    ULONG pid;
    int parentpid=0;                                               //~va3cR~
//  void *enumcbparm[2]={&parentpid,                               //~va3cR~
    void *enumcbparm[2]={0,                                        //~va3cI~
    					0                                          //~va3cI~
						};                                         //~va3cI~
    void *penumcbparm;                                             //~va3cI~
    int opt;                                                       //~va3cI~
//***********
    enumcbparm[0]=&parentpid;                                      //~va3cI~
    uerrmsg_init(0,stdout,0);
    for (ii=1,popd=argp+1;ii<argc;ii++,popd++)
    {
        pc=*popd;
        if (*pc=='-'||*pc=='/') //option
        {
            pc++;
            switch(toupper(*pc))
            {
            case '?':
                help();
                exit(0);
                break;
            case 'F':   //force
//              if (toupper(*(pc+1))=='F')                         //~va2mR~
//                  Sopt|=OPT_NOCONFIRM2;                          //~va2mR~
//              else                                               //~va2mR~
    	            Sopt|=OPT_NOCONFIRM;
                break;
            case 'L':   //list
                Sopt|=OPT_LIST;
                Sopt|=OPT_VERBOSE;                                 //~va3cI~
                break;
            case 'N':   //list
                if (*(pc+1)=='9')
				    uerrmsg_init(0,stdout,UERR_FORCE_ENGLISH);
                break;
            case 'S':   //select by name
                Sopt|=OPT_BYNAME;
                Sselectname=pc+1;
                if (!*Sselectname)
                    uerrexit("specify name string parameter just after the '-N'",0);
                break;
//            case 'V':   //list                                     //~vak1I~//+vak2R~
//                Sopt|=OPT_VERBOSE2;                                //~vak1I~//+vak2R~
//                break;                                             //~vak1I~//+vak2R~
            case 'Y':   //list
                break;
            default:
            	uerrexit("option parm err(%s)",0,
                			*popd);
            }
        }
        else
        {
        	len=strlen(pc);
            if (unumlen(pc,0,len)!=len || !atoi(pc))	//not numeric
            	uerrexit("not numeric operand err(%s)",0,
                			*popd);
            pidctr++;
        }
    }
    if (pidctr)
    {
    	if (Sopt & OPT_BYNAME)
        	uerrexit("pid list and name parameter are mutualy exclusive",0);
    	Sopt|=OPT_BYPID;
    	Sppl=ppl=(PPIDLIST)umalloc(pidctr*PIDLISTSZ);
        Spplctr=pidctr;
        for (ii=1,popd=argp+1;ii<argc;ii++,popd++)
        {
            pc=*popd;
            if (*pc=='-'||*pc=='/') //option
            	continue;
            ppl->PLpid=(ULONG)atoi(pc);
            ppl->PLfnm=0;
            ppl++;
        }
    }
    else
    	if (Sopt & OPT_BYNAME)
	    	Sppl=ppl=(PPIDLIST)umalloc(MAXPID_BYNAME*PIDLISTSZ);

//  uenumpid(cbenumpid,"");                                        //~va3cR~
//  penumcbparm=(void*)(ULONG)enumcbparm;                          //~va3cR~
    penumcbparm=(void*)(ULPTR)enumcbparm;                          //~va3cI~
//  uenumpid(cbenumpid,penumcbparm);                               //~va3cR~
//    if (Sopt & OPT_VERBOSE2)                                       //~vak1I~//+vak2R~
//    {                                                              //~vak1I~//+vak2R~
//        opt=UEPI_HELPER;                                           //~vak1I~//+vak2R~
//        opt=UEPI_VERBOSE;                                          //~vak1I~//+vak2R~
//    }                                                              //~vak1I~//+vak2R~
//    else                                                           //~vak1I~//+vak2R~
    if (Sopt & OPT_VERBOSE)                                        //~va3cI~
		opt=UEPI_HELPER;                                           //~va3cI~
    else                                                           //~va3cI~
        opt=0;                                                     //~va3cI~
    uenumpid(opt,cbenumpid,penumcbparm);                           //~va3cI~
    if (Sopt & OPT_BYNAME)
    {
        uerrmsg("total %d process found by string \"%s\"",0,
                    Spplctr,Sselectname);
    	Spplctr=min(Spplctr,MAXPID_BYNAME);
    }
    for (ppl=Sppl,ii=0;ii<Spplctr;ii++,ppl++)
    {
        pid=ppl->PLpid;
        if (!ppl->PLfnm)
            printf("%10d is not found\n",pid);
        else
        {
			printf("%6d (0x%04x) = %s\n",pid,pid,ppl->PLfnm);
            if (!(Sopt & OPT_LIST)) //not list option
            {
//              if (pid<MINPID_KILL  && !(Sopt & OPT_NOCONFIRM2))  //~va2mR~
//              	uerrmsg("specify -FF to kill pid of under %d",0,//~va2mR~
//  							MINPID_KILL);                      //~va2mR~
//              else                                               //~va2mR~
//              {                                                  //~va2mR~
                    if (!(Sopt & OPT_NOCONFIRM))
                    {
                        rc=uconfirmmsg("??? kill confirmation, Press Y(es) or N(o) or Esc(exit process)",
                                       "??? このプロセスを停止しますか？ Y(es)、 N(o)、Esc(処理中断)。",
                                        "\x1bYyNn");
                        rc=(toupper(rc)=='N');
                        if (rc)
                            printf("   --- kill canceled.\n");     //~va2mR~
                    }
                    else
                        rc=0;
                    if (!rc)
                    {
//                      rc=ukillpid(pid,exitcode);                 //~va2mR~
                        rc=ukillpid(&pid,exitcode);                //~va2mI~
                        if (!rc)    //dsuccess
                            printf("   --- killed %6d (%s).\n",pid,ppl->PLfnm);//~va2mR~
                        else
                        {
                            preason=ugetlasterror(&rc);
                            printf("   ??? kill failed(rc=%d:%s).\n",rc,preason);
                        }
                    }
//              }//pid<256                                         //~va2mR~
            }
        }
    }//
    return 0;
}//main
//****************************************
//*enumpid callback function
//****************************************
//int cbenumpid(ULONG Ppid,USHORT Ppid16,char *Pfnm,void *Pprm)    //~va98R~
int cbenumpid(int Popt,ULONG Ppid,USHORT Ppid16,char *Pfnm,void *Pprm)//~va98I~
{
    ULONG pid;
    int ii,len;
    PPIDLIST ppl;
    int printsw=0;
    int **cbparm,ppid;                                             //~va3cR~
//******************
//  cbparm=(int**)(ULONG)Pprm;                                     //~va3cR~
    cbparm=(int**)(ULPTR)Pprm;                                     //~va3cI~
    if (Ppid16)
        pid=Ppid16;
    else
        pid=Ppid;
    if (Sopt & OPT_BYPID)	//pid operand exist
    {
    	for (ppl=Sppl,ii=0;ii<Spplctr;ii++,ppl++)
        {
        	if (pid==ppl->PLpid)
            {
	            if (ppl->PLfnm)
    	        	uerrmsg("%d is duplicated",0,
                    		pid);
                else
                	if (Pfnm)
                    {
                        len=strlen(Pfnm);
			            ppl->PLfnm=(char*)umalloc(len+1);
                        memcpy(ppl->PLfnm,Pfnm,len+1);
                    }
                    else
			            ppl->PLfnm="?";
                break;
            }
        }
    }
    else
    if (Sopt & OPT_BYNAME && Pfnm)	//pid operand exist
    {
#ifdef W32
		if (ustrstri(Pfnm,Sselectname))
#else
		if (strstr(Pfnm,Sselectname))
#endif
		{
        	if (Spplctr==MAXPID_BYNAME-1)
            	uerrmsg("Too many(max=%d) process for select by string %s",0,
                		MAXPID_BYNAME,Sselectname);
            else
        	if (Spplctr<MAXPID_BYNAME-1)
            {
            	ppl=Sppl+Spplctr;
                len=strlen(Pfnm);
                ppl->PLpid=pid;
                ppl->PLfnm=(char*)umalloc(len+1);
                memcpy(ppl->PLfnm,Pfnm,len+1);
            }
            if (!(Sopt & OPT_NOCONFIRM)                            //~va2mR~
            &&  !(Sopt & OPT_LIST))                                //~va2mI~
	            printsw=1;                                         //~va2mR~
	        Spplctr++;
        }
    }
    else
        printsw=1;
    if (printsw)
    {
//      if (Sopt & OPT_VERBOSE)                                    //~va3cI~//~vak1R~
//      if (Sopt & (OPT_VERBOSE|OPT_VERBOSE2))                     //~vak1I~//+vak2R~
        if (Sopt & OPT_VERBOSE)                                    //+vak2I~
			ppid=*cbparm[0];                                       //~va3cI~
        else                                                       //~va3cI~
        	ppid=-1;                                               //~va3cR~
        if (Ppid16)
			printf("%6d (0x%04x) (16bit) = fnm=%s\n",pid,pid,Pfnm);
        else
          if (ppid>=0)	                                           //~va3cR~
			printf("%6d (0x%04x) ppid:%6d = %s\n",pid,pid,ppid,Pfnm);//~va3cR~
          else                                                     //~va3cI~
			printf("%6d (0x%04x) = %s\n",pid,pid,Pfnm);
    }
    return 1;
}//cbenumpid
//****************************************
int help(void)
{
//***************
    uerrmsg("%s (v%s) list pid/kill process",
    		"%s (v%s) プロセスID を表示あるいは停止",
    		PGM,VER);
//  uerrmsg("Usage:  %s [-L] [-F] [-Sstring] [pid ... ]",          //~vak1R~
//          "用法 :  %s [-L] [-F] [-Sstring] [pid ... ]",          //~vak1R~
//    uerrmsg("Usage:  %s [-L] [-F] [-V] [-Sstring] [pid ... ]",     //~vak1I~//+vak2R~
//            "用法 :  %s [-L] [-F] [-V] [-Sstring] [pid ... ]",     //~vak1I~//+vak2R~
    uerrmsg("Usage:  %s [-L] [-F] [-Sstring] [pid ... ]",          //+vak2I~
              "用法 :  %s [-L] [-F] [-Sstring] [pid ... ]",        //+vak2I~
    		PGM);
    uerrmsg(" -F  : Force kill without confirmation.",
            " -F  : 確認無しで停止.");
//  uerrmsg(" -FF : Kill pid < %d.",                               //~va2mR~
//          " -FF : pid < %d も停止.",                             //~va2mR~
//					MINPID_KILL);                                  //~va2mR~
//  uerrmsg(" -L  : List modulename.",                             //~va3cR~
//          " -L  : 表示のみ.");                                   //~va3cR~
    uerrmsg(" -L  : List only. +parent PID.",                      //~va3cI~
            " -L  : 表示のみ. +親PID表示");                        //~va3cI~
    uerrmsg(" -S  : select process by Name which contains the string value.",
            " -S  : 実行モジュールの一部に\"string\"が含まれるプロセスが対象");
//    uerrmsg(" -V  : exe name by fullpathname.",                    //~vak1I~//+vak2R~
//            " -V  : 実行モジュールをフルパスで表示");              //~vak1I~//+vak2R~
    uerrmsg(" pid : specify processID's to list or kill.",
//          " pid : 処理するプロセスIDを指定.",0);                 //~va9tR~
            " pid : 処理するプロセスIDを指定.");                   //~va9tI~
    uerrmsg("       list-up all process if pid missing.",
//          "       pid指定がないと全プロセスをリストアップ.",0);  //~va9tR~
            "       pid指定がないと全プロセスをリストアップ.");    //~va9tI~
    return 0;
}//help
