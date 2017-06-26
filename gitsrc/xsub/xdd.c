//CID://+vad0R~:        update#=   13                              //~vad0R~
//*************************************************************
//*XDD.C  delete file/dir
//*format
//*************************************************************
//vad0:170101 xdd v2.1 del longname file                           //~vad0I~
//vac0:161219 xdd v2.0 quit option(-q[n], one msg for each n deletion)//~vac0I~
//va90:140503 xdd v1.9:UNICODE version                             //~va90I~
//va4v:110709 xdd:1.8 optionaly delete wildname file               //~va4vI~
//va38:070611 xdd:1.7 (LNX:BUG)do not allow "/" as option parm. for multiple file specification case(by wild card etc)//~va38I~
//            & ulib:v5kn                                          //~va38I~
//va30:061227 xdd v1.6 filesize>4GB support                        //~va30I~
//*va1W:050123 xdd:v1.5:(LNX:BUG) A:(disket) has no groupeid(rootgroup chk is not valid)//~va1eI~
//*va1e:040330 xdd:v1.4:(LNX:BUG) sjis msg-->EUC msg               //~va1eI~
//*va19:031124 xdig:v1.4:(UNX)protect del dir of owner groupe is root//~va19I~
//020525 v123 (UNX)unx version                                     //~v123I~
//991104 v122 display timestamp on dir list                        //~v122I~
//991104 v121 By list req,list member when dirname spacified       //~v121I~
//xdd.c  *990911 v1.2 add option to confirm to delete of each file //~v1.2I~
//*v1.1 relesed 990425                                             //~v104I~
//981123 xdd :v1.04:dos.h is only for non os2                      //~v104I~
//*v1.1 relesed                                                    //~v103I~
//981123 xdd :v1.03:list directory option for reply                //~v103I~
//980920 xdd :v1.02:attr/size on deleted msg(by ufile2 modify)     //~v102I~
//980201 xdd :v1.01:win/gcc version                                //~v101R~
//*v100 first
//*************************************************************
#define VERSION  "v2.1"                                            //~va4vR~//~vad0R~
#define PGMID    "xdd"                                             //~v123R~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef UNX                                                         //~v123I~
#else                                                              //~v123I~
#ifdef DOS
    #include <dos.h>                                               //~v104I~
    #include <conio.h>                                             //~v1.2I~
#else
  #ifdef W32                                                       //~v101I~
    #include <dos.h>                                               //~v104I~
    #include <conio.h>                                             //~v1.2I~
  #else                                                            //~v101I~
    #include <conio.h>                                             //~v1.2I~
	#define INCL_DOSFILEMGR
	#define INCL_BASE
	#include <os2.h>
  #endif                                                           //~v101I~
#endif
#endif  //!unx                                                     //~v123I~
#include <ulib.h>
#include <udbcschk.h>                                              //~v1.2I~
#include <ufile.h>
#include <ufile2.h>
#include <uerr.h>
#include <ualloc.h>                                                //~v103I~
#include <uedit.h>                                                 //~v103R~
#include <uedit2.h>                                                //~v103I~
#include <ufemsg.h>                                                //~va19I~
#ifdef DPMI                 //DPMI version                         //~v101I~
	#include <ufile4.h>                                            //~v101R~
#endif                                                             //~v101I~
#ifdef UNX                 //DPMI version                          //~va19I~
	#include <uunxsub.h>                                           //~va19I~
#endif                                                             //~va19I~
//********************
static	char Spgmver[16];
#ifdef UNX                                                         //~va19I~
	static	int Srootgroupsw=0;                                    //~va19R~
#endif                                                             //~va19I~
//********************
#ifdef UNX                                                         //~va19I~
	int  chkrootgrp(char *Pfname);                                 //~va19R~
#endif                                                             //~va19I~
void listdir(UCHAR *Pfullpath);                                    //~v103I~
void help(void);
//*************************************************************
int main(int parmc,char * parmp[])
{
	int parmno,posparmno=0,rc;
    int xdelopt,xddopt;
    UCHAR reply[4];
    UCHAR *cptr,*errparm;
    UCHAR fpath[_MAX_PATH];                                        //~va1eR~
//  int dbcssw;                                                    //~va1eR~
//**********************
#ifdef W32UNICODE                                                  //~va90I~
    SET_UDMODE();  //filename by UD format                         //~va90I~
#endif                                                             //~va90I~
//  dbcssw=udbcschkcp();                                           //~va1eR~
	sprintf(Spgmver,"%s:%s: ",PGMID,VERSION);
	uerrmsg_init(Spgmver,stdout,0);//msg to stdout
	uerrexit_init(Spgmver,stdout,0,0,0);//stdout only,no pathmsg
#ifdef UNX                                                         //~va4vI~
    Gufile_opt|=GFILEOPT_XDDUTIL;   //change err msg for wildname file//~va4vI~
#endif                                                             //~va4vI~
#ifdef DPMI					//DPMI version                         //~v101I~
    putenv("LFN=Y");                 //need for ufileisvfat        //~v101I~
	ufileisvfat(ISVFAT_FORCE);      //force vfat                   //~v101I~
#endif                      //DPMI or not                          //~v101I~
	if (errparm=uxddpchk(Spgmver,parmc-1,parmp[1],&xdelopt,&xddopt,&posparmno),errparm)//~v100R~
    {
		uerrexit("Invalid option (%s)",
			"無効なオプション (%s)",
			errparm);
    	return 8;
	}
#ifdef UNX                                                         //~v123M~
	if (!(xdelopt & UXDELNOTFD))	//not no fd support            //~v123I~
	    UCBITON(Gufile_opt,GFILEOPT_LNXMTOOL);	//mdos disk support//~v123I~
	if (xdelopt & UXDELFORCEROOT)//force delete file owned root user group//~va19I~
	    Srootgroupsw=1;                                            //~va19I~
#endif                                                             //~v123M~
    if (!posparmno)
    {
    	help();
        exit (4);
    }
//  if (xddopt & UXDDENGLISH)	//force english                    //~va1eR~
//  	dbcssw=0;                                                  //~va1eR~
//****** main *******
	xdelopt|=UXDELMSG;	//detail msg issue
    posparmno=0;                                                   //~v123I~
	for (parmno=1;parmno<parmc;parmno++)
	{
		cptr=parmp[parmno];
#ifdef UNX                                                         //~v123I~
//    	if (!CMDFLAGCHK(*cptr,posparmno))                          //~va38R~
      	if (!CMDFLAGCHK(*cptr,0))	// "/" is file even if 2nd parm//~va38I~
#else                                                              //~v123I~
	  	if(*cptr!='/')
#endif                                                             //~v123I~
		{//positional parmno
            posparmno++;      //for / parm chk                     //~v123I~
#ifdef UNX                                                         //~va19I~
	    	if (chkrootgrp(cptr))	//chk owner grp is root;dir or file in the dir//~va19R~
            	continue;                                          //~va19I~
#endif                                                             //~va19I~
	    	rc=uxddsub(cptr,xdelopt,xddopt,fpath);                 //~va1eR~
            if (rc>=4)                                          //~v100R~
                return rc;                                      //~v100I~
            if (rc==1)                                          //~v100I~
	    		for (;;)
    			{
//  				uerrmsg("%s;Delete OK(\"Y\"), Cancel(\"N\") or List Dir(\"L\")?",//~v1.2R~
//          				"%s の確認,削除(\"Y\"),取消(\"N\"),\x95\\示(\"L\")?",//~v1.2R~
//  						fullpath);                             //~v1.2I~
//                  if (!dbcssw)                                   //~va1eR~
//                  	printf("%s ;Delete Yes/No/List/Select ? ",fullpath);//~va1eR~
//                  else                                           //~va1eR~
//          			printf("%s ;削除確認,Yes/No/List(\x95\\示)/Select(選択) ? ",fullpath);//~va1eR~
                    uerrmsg("%s ;Delete Yes/No/List/Select ? ",    //~va1eI~
                            "%s ;削除確認,Yes/No/List(\x95\\示)/Select(選択) ? ",//~va1eI~
							fpath);                                //~va1eR~
                    fflush(stdout);                                //~v122I~
//              	scanf("%3s",reply);                            //~v1.2R~
#ifdef OS2                                                         //~v1.2I~
                	reply[0]=(UCHAR)_getche();                     //~v1.2I~
#else                                                              //~v1.2I~
                	reply[0]=(UCHAR)getche();                      //~v1.2I~
#endif                                                             //~v1.2I~
                    printf("\n");                                  //~v1.2I~
    		    	if (*reply=='N' || *reply=='n' || *reply==0x1b)//~v1.2R~
        	        {
    					uerrmsg("Process canceled for %s",
    	    		    		"%s の処理が取り消されました",
    							fpath);                            //~va1eR~
	    				break;
    				}
    		    	if (*reply=='L' || *reply=='l')                //~v103I~
        	        {                                              //~v103I~
    					listdir(fpath);                            //~va1eR~
	    				continue;                                  //~v103I~
    				}                                              //~v103I~
	            	if (*reply=='Y' || *reply=='y')
                    {
			    		if (rc=uxddsub(cptr,xdelopt,xddopt|UXDDNOCONF,fpath),rc)//~va1eR~
                			return rc;                          //~v100I~
    		    		break;
					}
	            	if (*reply=='S' || *reply=='s')                //~v1.2I~
                    {                                              //~v1.2I~
			    		if (rc=uxddsub(cptr,xdelopt|UXDELCONFEACH,xddopt|UXDDNOCONF,fpath),rc)//~va1eR~
                			return rc;                             //~v1.2I~
    		    		break;                                     //~v1.2I~
					}                                              //~v1.2I~
    			}//for
		}//option or posparm
	}//for all parm
    printf("%s:%s:=(%c)=== Directory/File Delete (%s) =========================\n",//~v101R~
            PGMID,VERSION,OSTYPE,__DATE__);                        //~v101I~
    return 0;
}//main
//*********************                                            //~v103I~
void listdir(UCHAR *Pfullpath)                                     //~v103I~
{                                                                  //~v103I~
    int fno,ii;                                                    //~v103R~
    PUDIRLIST pudirlist,pudirlist0;                                //~v103I~
    char editwk[16];                                               //~v103I~
    char attrwk[8];                                                //~v103I~
    char datewk[12];                                               //~v122I~
    char timewk[8];                                                //~v122I~
    char fpath[_MAX_PATH];                                         //~v121I~
#ifdef UNX                                                         //~v123I~
    int efaopt;                                                    //~v123I~
#endif                                                             //~v123I~
//************                                                     //~v103I~
//  if ((fno=udirlist(Pfullpath,FILE_ALL,&pudirlist0,'N'))<=0)     //~v121R~
    strcpy(fpath,Pfullpath);                                       //~v121R~
    if (!WILDCARD(fpath))       //listdir called when rc=1(dir or wildcard)//~v121R~
//      strcat(fpath,"\\*.*");                                     //~v123R~
        strcat(fpath,DIR_SEPS DIR_ALLMEMB);                        //~v123I~
    if ((fno=udirlist(fpath,FILE_ALL,&pudirlist0,'N'))<=0)         //~v121I~
    {                                                              //~v103I~
    	uerrmsg("No file found",0);                                //~v103I~
        return;                                                    //~v103I~
    }                                                              //~v103I~
    for (ii=0,pudirlist=pudirlist0;ii<fno;ii++,pudirlist++)        //~v103R~
    {                                                              //~v103I~
    	if (!strcmp(pudirlist->name,"."))                          //~v103I~
        	continue;                                              //~v103R~
    	if (!strcmp(pudirlist->name,".."))                         //~v103I~
        	continue;                                              //~v103R~
//      unumedit((ULONG)pudirlist->size,"z,zzz,zzz,zz9",editwk);   //~va30R~
		ufileeditsz(0,pudirlist->size,editwk);                     //~va30R~
#ifdef UNX                                                         //~v123I~
        efaopt=UEFA_DIR|UEFA_SZ;        //set sz at last           //~v123I~
        if (MDOSDISKOK(fpath))                                     //~v123I~
            efaopt|=UEFA_MDOS;                                     //~v123I~
        ueditfattr(pudirlist->attr,attrwk,efaopt);      //set sz at last//~v123I~
#else                                                              //~v123I~
        ueditfattr(pudirlist->attr,attrwk,UEFA_DIR|UEFA_SZ);      //set sz at last//~v103I~
#endif                                                             //~v123I~
//date/time                                                        //~v122I~
        ufdateedit(pudirlist->date,"YY-MM-DD",datewk);             //~v122I~
        uftimeedit(pudirlist->time,"HH:MM",timewk);                //~v122I~
//      uerrhelpmsg(stdout,stderr,"%s%s %s\n",0,                   //~v122R~
//  				attrwk,editwk,pudirlist->name);                //~v122R~
        uerrhelpmsg(stdout,stderr,"%s%s %s %s %s\n",0,             //~v122I~
    				attrwk,editwk,datewk,timewk,pudirlist->name);  //~v122I~
    }                                                              //~v103I~
    ufree(pudirlist0);                                             //~v103I~
    return;                                                        //~v103I~
}//listdir                                                         //~v103I~
#ifdef UNX                                                         //~va19I~
//*******************************************************************//~va19I~
//* chk protect root group                                         //~va19R~
//*   wildcard del in the dir of root owner group                  //~va19I~
//*   dir of root owner group                                      //~va19I~
//*   root owner group file in the dir of root owner group         //~va19I~
//* rc:1=protected,0:do del                                        //~va19I~
//*******************************************************************//~va19I~
int chkrootgrp(char *Pfname)                                       //~va19R~
{                                                                  //~va19I~
	FILEFINDBUF3 ffb3;                                             //~va19I~
    char fpath[_MAX_PATH];                                         //~va19I~
//  uid_t uid;                                                     //~va19R~
//  gid_t gid;                                                     //~va19R~
    int pathlen;                                                   //~va19R~
//************                                                     //~va19I~
//  ugetugid(&uid,&gid);                                           //~va19R~
//  if (gid)		//not root grp                                 //~va19R~
//  	return 0;        //do nothing,may later permission err     //~va19R~
	if (!ufullpath(fpath,Pfname,sizeof(fpath)))//fpath err         //~va19R~
    	return 0;	//try del                                      //~va19I~
    if (!strcmp(fpath,"/"))                                        //~va19R~
    	return ufileroot(fpath,1);                                 //~va19I~
    if (MDOSDISK(fpath))                                           //~va1eR~
        return 0;                                                  //~va1eR~
	if (Srootgroupsw)	//force parm                               //~va19M~
    	return 0;                                                  //~va19M~
    pathlen=PATHLEN(fpath);                                        //~va19I~
    if (pathlen<1)                                                 //~va19I~
    	return 0;	//try del                                      //~va19I~
    if (WILDCARD(fpath+pathlen))                                   //~va19I~
    {                                                              //~va19I~
    	if (pathlen==1)                                            //~va19I~
        {                                                          //~va19I~
        	uerrmsg("%s:wildcard delete of root dir is protected(even for owner group user)",0,//~va19R~
            		fpath);                                        //~va19I~
        	return 1; 		//protected                            //~va19I~
        }                                                          //~va19I~
        *(fpath+pathlen-1)=0;	//drop last "/"                    //~va19I~
	    if (ufstat(fpath,&ffb3))	//not found                    //~va19I~
	    	return 0;               //msg later                    //~va19I~
        if (!ffb3.gid)		//root group                           //~va19I~
        {                                                          //~va19I~
//      	uerrmsg("%s is owned by root group user,wild card delete is protected(even for owner group)",0,//~va1eR~
        	uerrmsg("%s is owned by root group user,wild card delete is protected(even for owner group),OR use -root option.",0,//~va1eR~
            		fpath);                                        //~va19I~
        	return 1; 		//protected                            //~va19I~
        }                                                          //~va19I~
	    return 0;               //msg later                        //~va19I~
    }//wildcard                                                    //~va19I~
//not wildcard                                                     //~va19I~
    if (ufstat(fpath,&ffb3))    //not found                        //~va19I~
	   	return 0;               //msg later                        //~va19I~
	if (ffb3.attrFile & FILE_DIRECTORY)                            //~va19R~
    {                                                              //~va19I~
        if (!ffb3.gid)		//root group                           //~va19I~
        {                                                          //~va19I~
//      	uerrmsg("%s is owned by root group user,dir delete is protected(even for owner user group)",0,//~va1eR~
        	uerrmsg("%s is owned by root group user,dir delete is protected(even for owner user group),OR use -root option.",0,//~va1eR~
            		fpath);                                        //~va19I~
        	return 1; 		//protected                            //~va19I~
        }                                                          //~va19I~
    	return 0;               //del                              //~va19I~
    }                                                              //~va19I~
//reguler file                                                     //~va19I~
    if (ffb3.gid)      //not root group                            //~va19I~
	    return 0;               //del                              //~va19I~
    *(fpath+pathlen-1)=0;	//drop last "/"                        //~va19I~
	if (pathlen==1			                                       //~va19I~
    ||  (ufstat(fpath,&ffb3),ffb3.gid==0))    //parent is root or owner grp is root//~va19I~
    {                                                              //~va19I~
	    *(fpath+pathlen-1)='/';	//drop last "/"                    //~va19I~
//      uerrmsg("%s is owned by root group user and parent dir is also,it's protected(even for owner group)",0,//~va1eR~
        uerrmsg("%s is owned by root group user and parent dir is also,it's protected(even for owner group),OR use -root option.",0,//~va1eR~
                fpath);                                            //~va19I~
        return 1;       //protected                                //~va19I~
    }                                                              //~va19I~
    return 0;               //del                                  //~va19I~
}//chkrootgrp                                                      //~va19I~
#endif                                                             //~va19I~
//*********************
void help(void)
{
//************
	uerrmsg("%s:%s(%c) Directory/File delete tool (%s)",           //~v101R~
			"%s:%s(%c)ディレクトリー/ファイル削除ツール (%s)",     //~v101R~
            PGMID,VERSION,OSTYPE,__DATE__);                        //~v101R~
//  uerrmsg("format: %s Dir-name [,Dir-name...] %s",               //~v123R~
//  		"形式　: %s Dir名 [,Dir名...] %s",                     //~v123R~
//  			PGMID,"[ /r | /r- | /rl ] [ /s ] [/y]");           //~v123R~
#ifdef UNX                                                         //~v123I~
//  uerrmsg("format: %s [ %cr | %cr- | %crl ] [%croot] [ %cs ] [%cy] [%cu]"//~va4vR~
//  uerrmsg("format: %s [ %cr | %cr- | %crl ] [%croot] [ %cs ] [%cy] [%cu] [%cw]"//~vac0R~
    uerrmsg("format: %s [ %cr | %cr- | %crl ] [%cq[n]] [%croot] [ %cs ] [%cy] [%cu] [%cw]" \
					   " Dir-name [,Dir-name...]",                 //~v123I~
//    		"形式　: %s [ %cr | %cr- | %crl ] [%croot] [ %cs ] [%cy] [%cu]"//~va4vR~
//    		"形式　: %s [ %cr | %cr- | %crl ] [%croot] [ %cs ] [%cy] [%cu] [%cw]"//~vac0R~
      		"形式　: %s [ %cr | %cr- | %crl ] [%cq[n]] [%croot] [ %cs ] [%cy] [%cu] [%cw]" \
					   " Dir名 [,Dir名...]",                       //~v123I~
    			PGMID,                                             //~v123I~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,//~va4vR~
				CMDFLAG_PREFIX,                                    //~vac0I~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va4vI~
#else                                                              //~v123I~
//  uerrmsg("format: %s [ %cr | %cr- | %crl ] [ %cs ] [%cy]"       //~vac0R~
    uerrmsg("format: %s [ %cr | %cr- | %crl ] [ %cq[n]] [ %cs ] [%cy]" \
					   " Dir-name [,Dir-name...]",                 //~v123R~
//  		"形式　: %s [ %cr | %cr- | %crl ] [ %cs ] [%cy]"       //~vac0R~
    		"形式　: %s [ %cr | %cr- | %crl ] [ %cq[n]] [ %cs ] [%cy]" \
					   " Dir名 [,Dir名...]",                       //~v123R~
    			PGMID,                                             //~vac0I~
				CMDFLAG_PREFIX,                                    //~vac0I~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~v123R~
#endif                                                             //~v123I~
	uerrmsg("         q[n] : quiet mode(msg at each 10**n deletion, default=3(=1000))",//~vac0R~
    		"         q[n] : 10**n 件ごとに削除メッセージを出力,省略値:3(=1000)");//~vac0R~
	uerrmsg("            r : Delete also Read-only file/directory",
    		"            r : Read only(読取専用をも強制削除)");
	uerrmsg("                Use also to delete too long file path name.",//~vad0I~
    		"                長すぎるファイル名を削除する時も指定する");//~vad0I~
	uerrmsg("                (Long name is deleted after renamed.)",//+vad0R~
    		"                (長すぎるファイル名は改名後に削除される)");//+vad0R~
	uerrmsg("            r-: Delete except Read-Only file/directory",
    		"            r-: 読取専用以外を削除");
	uerrmsg("           (bypass readonly-check phase when r/r- is specified.)",//~vac0R~
    		"     (r/r- を指定すると読み取り専用ファイルチェックをしないので早い)");//~vac0R~
	uerrmsg("            rl: Do not delete,but List Read-only file/directory",
    		"            rl: List(削除はせず読取専用のリストを\x95\x5c示する)");//~v101R~
#ifdef UNX                                                         //~va19I~
	uerrmsg("            root: Force delete even if owner group is root.",//~va19I~
    		"            root: オーナーグループ＝ルートでも強制削除");//~va19I~
#endif                                                             //~va19I~
	uerrmsg("            s : select member with confirmation to each",//~v1.2I~
    		"            s : Select(各ファイル毎に削除確認する)"); //~v1.2R~
#ifdef UNX                                                         //~v123I~
	uerrmsg("            u : No floppy drive procees.",            //~v123I~
    		"            u : a: をフロッピードライブとしない。");  //~v123I~
	uerrmsg("            w : Force to delete invalid(contains wildcard) entry.",//~va4vI~
    		"            w : 無効(ワイルドカード含みの)ファイルも削除。");//~va4vR~
#endif                                                             //~v123I~
	uerrmsg("            y : Assume Yes replyed for dir delete confirmation",
    		"            y : Yes(ディレクトリー削除の確認をとらない)");
	return;
}//help
