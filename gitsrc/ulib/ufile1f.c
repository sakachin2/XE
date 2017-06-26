//*CID://+v6J0R~:                             update#=  416;       //~v6J0R~
//*************************************************************
//*ufile1f.c :FTP version of
//*           ufstat,udosfindfirst,udosfindnext,
//*************************************************************
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6H7:170108 FTP crush by long name                               //~v6H7I~
//v6H2:170103 (BUG)uparsefname cut last 1 byte for len=259(_MAX_MATH-1)//~v6H2I~
//v6G3:161212 (Win10) missing error.h , use winerror.h             //~v6G3I~
//v6Ew:160819 (FTP)ufstat_wild use NULL for ffb3 parm, it may cause 0c4//~v6EwI~
//v6D1:160418 LNX64 compiler warning                               //~v6D1I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6uX:140612 chan errmsg "ftp-stat" to uerrmsgcat not to override previous errmsg//~v6uXI~
//v6uW:140610 (W32UNICODE)support UDfmt for ftp filename           //~v6uWI~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6he:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~v6heI~
//v6da:120217 (Axe)smb support                                     //~v6daI~
//v6d1:120131 (SMB)share option for SAMBA node(win64  192.168.2.19 usrskt pswd  share=p)//~v6d1I~
//v6b1:110705 try list wildcard membername                         //~v6b1I~
//v62b:090724 (FTP:BUG) del dir with no member,confirm msg remains because no errmsg is issued//~v62bI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v61p:080121 (FTP)psftp support                                   //~v61pI~
//v61n:080121*Bug report by M.J(LCD fail when LANG is not english) //~v61nI~
//v61m:080121*Bug report by M.J(errmsg is "New file" for "path err"//~v61mI~
//v61b:071123*(FTP)log errmsg to ftplog alos                       //~v61bI~
//v617:071122*(FTP:BUG)when target is window(TinyFTP) drive top is noted as "/C:/",that is not found on dirlist//~v617I~
//v616:071117 (FTP:BUG)assume "/" root as home when current dir is not set(for tiny ftp)//~v616I~
//v5kd:070518 (LNX:BUG)intermediate ../ is not resolved(linux understand but xe display ../ as it is)//~v5kdI~
//v5jg:061015 3270 CurDir utilize for the case no path specified   //~v5jgI~
//v5jb:061002 3270 support:udirlist support                        //~v5jbI~
//v5j4:060914 ftp:3270 support (xehost TSO=portno operand)         //~v5j4I~
//v5fm:050226 keep ftp err msg and not override ufullpath err for the case connection err etc//~v5fmI~
//v5dm:040619 (FTP)issue permission err msg when cd fail           //~v5dmI~
//v5ch:040504 (FTP)recursive call loop,then abend when wildcard path err//~v5chI~
//v5ce:040503 malloc +1 dirlist entry for safety end of list chk   //~v5ceI~
//v5c8:040331 (FTP:BUG)uftpfullpath:parm may not contain remoteID(slink not found msg)//~v5c8I~
//v5bu:040221 (FTP:BUG)output findbuff should be cleared like as non FTP case.//~v5buI~
//v5bf:040204 (FTP:BUG)space containing filename support           //~v5bfI~
//v5b9:040202 (BUG) fullpath for ~/../ (home base)                 //~v5b9I~
//v5at:040111 (FTP:BUG)add "pwd" to lcd responce chk               //~v5atI~
//v5aj:040108 (FTP)allow file for udosfindfirst like as win        //~v5afI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5afI~
//v59n:031109 ftp support:ufstat,udirlist                          //~v59nI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#ifdef UNX
	#include <unistd.h>
	#include <dirent.h>                                            //~v6b1I~
#else
	#include <dos.h>
  #ifdef MGW32                                                     //~v5ncI~
	#include <winerror.h>                                          //~v5ncI~
  #else                                                            //~v5ncI~
   #ifdef WIN10                                                   //+v6BkI//~v6G3I~
	#include <winerror.h>                                          //~v6G3I~
   #else                                                           //~v6G3I~
	#include <error.h>
   #endif                                                          //~v6G3I~
  #endif                                                           //~v5ncI~
#endif
//*******************************************************
#include <ulib.h>
#include <uque.h>                                                  //~v5afM~
#include <ufile.h>
#include <uftp.h>                                                  //~v5afM~
#include <ufile1f.h>                                               //~v59nI~
#include <ufile1l.h>
#include <ufile1l2.h>
#include <ufile5.h>
#include <uerr.h>
#include <ufemsg.h>
#include <uparse.h>
#include <ustring.h>
#include <utrace.h>
#include <ualloc.h>
#include <u3270.h>                                                 //~v5j4I~
#include <uftp3.h>                                                 //~v61pM~
#ifdef ARMXXE                                                      //~v6daI~
	#include <jnic2ju.h>                                           //~v6daR~
#endif                                                             //~v6daI~
#include <ufilew.h>                                                //~v6uWI~
//*******************************************************
#define SPECIAL_DIRID    '.'
//*******************************************************
static int Snoridsw=0;                                             //~v5c8I~
//*******************************************************          //~v5c8I~
char *uftpgethome(char *Phost);
PUFTPDIRH uftpsrchhdir(int Phdir);
int uftpgethdir(PUDIRLIST Ppudl,int *Pphdir);
int uftpsethdir(int Phdir,char *Pwildcard,ULONG Pattr);
int uftpgethomesub(PUFTPHOST Ppfh);                                //~v59nR~
int uftpchdirsub(PUFTPHOST Ppuftph,char *Pdirname);                //~v5afR~
int uftpfindfirstfile(PUFTPHOST Ppuftph,char *Pfpath,unsigned int Pattr,FILEFINDBUF3 *Ppfstat3);//~v5ajR~
int uftpwinchk(PUFTPHOST Ppuftph,char *Pfpath,PUDIRLIST Ppudl);    //~v617I~
//*******************************************************
//*get file status(size,time stmp)
//*parm 1:file name
//*parm 2:output file info addr(optional)
//*******************************************************
unsigned int uftpfstat(PUFTPHOST Ppuftph,char *Pfpath,FILEFINDBUF3 *Ppffb3)//~v5afR~
{
    FILEFINDBUF3 ft;
    FILEFINDBUF3 *pft;
//  UDIRLIST udl;   //output file information                      //~v6qaR~
//  UDIRLIST_WK(udl,wkslinkname);   //output file information      //~v6qaI~//+v6J0R~
    UDIRLIST_WK(udl,wkname,wknamew,wkslinkname);   //output file information//+v6J0I~
    int rc;                                                        //~v5afR~
//*********************************
    if (!(pft=Ppffb3))  //optional parm                            //~v6EwI~
        pft=&ft;                        //use internal work        //~v6EwI~
    if (Ppuftph->UFTPHflag & UFTPHFTSO)                            //~v5j4I~
//      return u3270fstat(Ppuftph,Pfpath,Ppffb3);                  //~v6EwR~
        return u3270fstat(Ppuftph,Pfpath,pft);                     //~v6EwI~
#ifdef ARMXXE                                                      //~v6daI~
    if (UFTPH_ISSMBJ(Ppuftph))                                     //~v6daI~
//      return jnismb_ufstat(0,Ppuftph,Pfpath,Ppffb3);             //~v6EwR~
        return jnismb_ufstat(0,Ppuftph,Pfpath,pft);                //~v6EwI~
#endif                                                             //~v6daR~
//  if (!(pft=Ppffb3))  //optional parm                            //~v6EwR~
//      pft=&ft;                        //use internal work        //~v6EwR~
    memset(pft,0,sizeof(FILEFINDBUF3));   //new find first         //~v5buI~
    if (WILDCARD(Pfpath))
    {
//    	if (rc=uftpfindfirst(Ppuftph,UFTPFF_NOMSG,Pfpath,0,FILE_ALLSP,Ppffb3),rc)//~v6EwR~
      	if (rc=uftpfindfirst(Ppuftph,UFTPFF_NOMSG,Pfpath,0,FILE_ALLSP,pft),rc)//~v6EwI~
//      	return rc;                                             //~v6D0R~
        	return (unsigned)rc;                                   //~v6D0I~
        return 0;
    }

//  if (Gufile_opt & GFILEOPT_STATCD)
//  	statfnm=pfpath+pathlen;
//  else
//  	statfnm=pfpath;                                            //~v5afR~

//  UDIRLIST_WK_INIT(udl,wkslinkname);                             //~v6qaI~//+v6J0R~
    UDIRLIST_WK_INIT(udl,wkname,wknamew,wkslinkname);              //+v6J0I~
//  if (rc=uftpfstatudl(Ppuftph,0,Pfpath+Ppuftph->UFTPHhostnmlen+1,&udl),rc)//~v5afR~//~v6D0R~
    if (rc=(int)uftpfstatudl(Ppuftph,0,Pfpath+Ppuftph->UFTPHhostnmlen+1,&udl),rc)//~v6D0I~
    {
//      if(rc!=ENOENT && rc!=ENOTDIR) //not found or no more file  //~v61mR~
        if(rc!=ENOENT && rc!=ERROR_PATH_NOT_FOUND) //not found or no more file//~v61mI~
        {                                                          //~v6uXI~
		  if (rc!=FTPRC_SSHERR                                     //~v6uXI~
		  &&  rc!=FTPRC_OPENERR                                    //~v6uXI~
		  &&  rc!=FTPRC_LOGONERR                                   //~v6uXI~
          )                                                        //~v6uXI~
//          return ufileapierr("ftp-stat",Pfpath,rc);              //~v5afR~//~v6D0R~
            return (unsigned)ufileapierr("ftp-stat",Pfpath,rc);    //~v6D0I~
        }                                                          //~v6uXI~
      if (uftpwinchk(Ppuftph,Pfpath,&udl))	//windows home dir setting chk err//~v617I~
//      return rc;                                                 //~v6D0R~
        return (unsigned)rc;                                       //~v6D0I~
    }
//conv stat to findbuf3
	uftpudl2ffb3(&udl,pft);
    return 0;
}//uftpfstat
//*******************************************************          //~v617I~
//*windows home dir chk                                            //~v617I~
//*return:4:if not windows homedir,0 ok                            //~v617I~
//*******************************************************          //~v617I~
int uftpwinchk(PUFTPHOST Ppuftph,char *Pfpath,PUDIRLIST Ppudl)     //~v617I~
{                                                                  //~v617I~
	char *fnm,*home;                                               //~v617I~
    int lenfnm,lenhome,pathlen;                                    //~v617I~
//********************************                                 //~v617I~
    fnm=Pfpath+Ppuftph->UFTPHhostnmlen+1;                          //~v617I~
    home=Ppuftph->UFTPHhome;                                       //~v617I~
//  lenfnm=strlen(fnm);                                            //~v617I~//~v6D0R~
    lenfnm=(int)strlen(fnm);                                       //~v6D0I~
//  lenhome=strlen(home);                                          //~v617I~//~v6D0R~
    lenhome=(int)strlen(home);                                     //~v6D0I~
//  if ((lenfnm+1==lenhome && !memcmp(fnm,home,lenfnm) && *(home+lenfnm)==FTP_DIR_SEPC)//~v617I~//~v6D0R~
    if ((lenfnm+1==lenhome && !memcmp(fnm,home,(size_t)lenfnm) && *(home+lenfnm)==FTP_DIR_SEPC)//~v6D0I~
       )                                                           //~v617I~
    {                                                              //~v617I~
    	memset(Ppudl,0,UDIRLISTSZ);                                //~v617I~
        Ppudl->attr=FILE_DIRECTORY;                                //~v617I~
        pathlen=PATHLEN(fnm);                                      //~v617I~
        if (pathlen>0)                                             //~v617I~
//          strcpy(Ppudl->name,fnm+pathlen);                       //~v617I~//~v6J0R~
        	udirlist_setname(0,Ppudl,fnm+pathlen,0);               //~v6J0I~
        else                                                       //~v617I~
//          strcpy(Ppudl->name,fnm);                               //~v617I~//~v6J0R~
        	udirlist_setname(0,Ppudl,fnm,0);                       //~v6J0I~
        return 0;	//match with home dir                          //~v617I~
    }                                                              //~v617I~
    return 4;                                                      //~v617I~
}//uftpwinchk                                                      //~v617I~
//*******************************************************          //~v5c8I~
//*get file fullpath name without remoteID on input name           //~v5c8R~
//*(output has remote id)                                          //~v5c8I~
//*parm 1:remote CB                                                //~v5c8I~
//*parm 2:output fullpth mame                                      //~v5c8I~
//*parm 3:fname with node prefix                                   //~v5c8I~
//*parm 4:output area size                                         //~v5c8I~
//*return:output buff addr or NULL if err                          //~v5c8I~
//*******************************************************          //~v5c8I~
char *uftpfullpathnorid(PUFTPHOST Ppuftph,char *Pfullpath,char *Pfname,size_t Plen)//~v5c8I~
{                                                                  //~v5c8I~
	char *fpath;                                                   //~v5c8I~
//********************************                                 //~v5c8I~
	Snoridsw=1;                                                    //~v5c8I~
	fpath=uftpfullpath(Ppuftph,Pfullpath,Pfname,Plen);             //~v5c8R~
	Snoridsw=0;                                                    //~v5c8I~
    return fpath;                                                  //~v5c8I~
}//uftpfullpathnorid                                               //~v5c8I~
//*******************************************************
//*get file fullpath name
//*parm 1:remote CB                                                //~v5c8I~
//*parm 2:output fullpath                                          //~v5c8R~
//*parm 3:fname with node prefix                                   //~v5c8R~
//*parm 4:output area size                                         //~v5c8I~
//*return:output buff addr or NULL if err
//*******************************************************
char *uftpfullpath(PUFTPHOST Ppuftph,char *Pfullpath,char *Pfname,size_t Plen)//~v5afR~
{
    char wk[FTP_MAXPATH],*pwk,*home;                               //~v59nR~
    int  hostnmlen,pathlen;                                        //~v59nR~
    UINT  len;
    char wkdropq[FTP_MAXPATH];    //drop quataition work
    char *pc,*phostnm;                                             //~v5b9R~
    int rootpos=FTP_ROOTDIRPOS;
    int rc2;                                                       //~v6H2I~
//********************************
//*drp quatation encloser
    if (Ppuftph->UFTPHflag & UFTPHFTSO)                            //~v5j4R~
        return u3270fullpath(Ppuftph,Pfullpath,Pfname,Plen);       //~v5j4R~
    hostnmlen=Ppuftph->UFTPHhostnmlen;                             //~v5afR~
    phostnm=Ppuftph->UFTPHhost;                                    //~v5afR~
//  uparsefname(0,Pfname,wkdropq,0,0);//no opd,no need delmpos,outlen//~v6H2R~
    rc2=uparsefname(0,Pfname,wkdropq,0,(int)sizeof(wkdropq),0);//no opd,no need delmpos,outlen//~v6H2R~
    if (rc2==8)	//buff ovf                                         //~v6H2I~
    	return 0;                                                  //~v6H2I~
  if (Snoridsw)                                                    //~v5c8R~
    pc=wkdropq;                                                    //~v5c8I~
  else                                                             //~v5c8I~
    pc=wkdropq+hostnmlen+1;                                        //~v5b9R~
//  len=strlen(pc);                                                //~v6D1R~
    len=(UINT)strlen(pc);                                          //~v6D1I~
//*dir path
//    if (*pc=='~') //homedir                                      //~v5b9R~
//    {                                                            //~v5b9R~
//        if (!(home=uftpgethome(phostnm)))                        //~v5b9R~
//        {                                                        //~v5b9R~
//            uerrmsg("ufullpath:no home dir define for %s",       //~v5b9R~
//                    "ufullpath:%s のホームディレクトリーは設定無し",//~v5b9R~
//                    phostnm);                                    //~v5b9R~
//            return 0;                                            //~v5b9R~
//        }                                                        //~v5b9R~
//        strcpy(wk,home);                                         //~v5b9R~
//        if ((*home=='/' && !*(home+1))  //home is root           //~v5b9R~
//        &&  *(pc+1)=='/')               // parm is "~/"          //~v5b9R~
//            strcpy(wk+1,pc+2);                                   //~v5b9R~
//        else                                                     //~v5b9R~
//        strcat(wk,pc+1);                                         //~v5b9R~
//    }                                                            //~v5b9R~
//    else                                                         //~v5b9R~
    if ((*pc)=='/')                //from root
        strcpy(wk,pc);
    else                        //from cur dir
    {
        memset(wk,0,sizeof(wk));
        if (*pc=='~'  //homedir                                    //~v5b9I~
        &&  (*(pc+1)=='/' || *(pc+1)==0)) // ~ or ~/               //~v5b9I~
        {                                                          //~v5b9I~
            if (!(home=uftpgethome(phostnm)))                      //~v5b9I~
            {                                                      //~v5b9I~
                uerrmsg("ufullpath:no home dir define for %s",     //~v5b9I~
                        "ufullpath:%s のホームディレクトリーは設定無し",//~v5b9I~
                        phostnm);                                  //~v5b9I~
				uftplog(FTPLOG_ERRM,0);	//logging errmsg           //~v61bI~
                return 0;                                          //~v5b9I~
            }                                                      //~v5b9I~
            strcpy(wk,home);                                       //~v5b9I~
            pc++;                                                  //~v5b9I~
            len--;                                                 //~v5b9I~
            if (len)               // parm is "~/"                 //~v5b9I~
                pc++,len--;                                        //~v5b9I~
        }                                                          //~v5b9I~
        else                                                       //~v5b9I~
//      if (!ugetcwd(wk))
        if (!uftpgetcwd(phostnm,wk))                               //~v59nR~
        {
//          uerrmsg("ufullpath:get current dir for %s failed,rc=%d",//~v5fmR~
            uerrmsg2("ufullpath:get current dir for %s failed,rc=%d",		//errmsg when no err msg by uftpgetcwd//~v5fmI~
                    "ufullpath:%s の現行ディレクトリー取得の失敗,rc=%d",
                    Pfname,errno);
			uftplog(FTPLOG_ERRM,0);	//logging errmsg               //~v61bI~
            return 0;
        }
//process "../"
        pwk=wk;
        while ((len>=2 && *pc==SPECIAL_DIRID && *(pc+1)==SPECIAL_DIRID)
            && (len==2 || *(pc+2)=='/')) //.. or ../               //~v59nR~
        {
            pc+=2;
            len-=2;
        	if (len)
            {
            	pc++;
                len--;
            }
            pathlen=FTP_PATHLEN(wk);                               //~v59nR~
            if (pathlen)                                           //~v59nI~
            {                                                      //~v59nI~
            	pwk=wk+FTP_PATHLEN(wk)-1;                          //~v59nI~
            	memset(pwk+1,0,strlen(pwk+1));                     //~v59nR~
            }                                                      //~v59nI~
            else                                                   //~v59nI~
            {                                                      //~v59nI~
            	pwk=wk;                                            //~v59nI~
                *pwk=0;                                            //~v59nI~
            }                                                      //~v59nI~
            if (pwk!=wk)    //not yet reached to root
                *pwk=0;    //drop parent dir
        }//loop process parent
//*
        if (len)//filename on input
        {
            if ((len && *pc==SPECIAL_DIRID)
            &&  (len==1 || *(pc+1)=='/')) //. or ./                //~v59nR~
            {
                pc++;
                len--;
                if (len)
                {
                    pc++;
                    len--;
                }
                if (len)
                {
                    pwk=wk+strlen(wk);
                    if (*(pwk-1)!='/')    //curr is not to root    //~v59nR~
                        *pwk++='/';
                    memcpy(pwk,pc,len);
                }
            }//.
            else    //not special .
            {
                pwk+=strlen(pwk);
                if (*(pwk-1)!='/')    //curr is not to root        //~v59nI~
                    *pwk++='/';     //add intermediate
                memcpy(pwk,pc,len);
            }
        }//not all space
    }//not root dir specified
    ufullpathresolvespecialdirid(wk,FTP_DIR_SEPC);   //resolve ./ and ..///~v5kdR~
//  if ((int)(len=strlen(wk))>rootpos+1 		//not root         //~v6D1R~
    if ((int)(len=(UINT)strlen(wk))>rootpos+1 		//not root     //~v6D1I~
    &&  FTP_PATHLEN(wk)==(int)len)   //last is '/'
    {
        *(wk+len-1)=0;
        len--;
    }
    if (Plen<=len)
        return 0;
#ifdef W32UNICODE                                                  //~v6uWI~
	if (IS_MEM_UDSTR(wk,len))                                      //~v6uWR~
    {                                                              //~v6uWI~
		STRIP_UDSTR(wk,len,wk/*out*/,NULL/*outlen*/);              //~v6uWI~
        UTRACED("strip name",wk,strlen(wk));                       //~v6uWI~
    }                                                              //~v6uWI~
#endif                                                             //~v6uWI~
//  FTP_SETPATHN(hostnmlen,phostnm,wk,Pfullpath);                  //~v59nR~//~v6D0R~
    FTP_SETPATHN((size_t)hostnmlen,phostnm,wk,Pfullpath);          //~v6D0I~
    return Pfullpath;
}//uftpfullpath
//*******************************************************
//*get file path name length(length containing last '/' from top)
//*parm 1:filename
//*return:length, =0 if err                                        //~v59nR~
//*******************************************************
int uftppathlen(char *Pfilename)
{
    char *pc;
//*********************************
    if (pc=ustrrchr2(Pfilename,'/'),!pc)
        return 0;     //avoid -1                                   //~v59nR~
//  return (int)((ULONG)pc-(ULONG)Pfilename)+1;                    //~v6hhR~
    return (int)((ULPTR)pc-(ULPTR)Pfilename)+1;                    //~v6hhI~
}//uftppathlen
//*******************************************************
//*get current dir                                                 //~v59nR~
//*parm  :output buff
//*return:ptr to buff
//*******************************************************
char *uftpgetcwd(char *Phost,unsigned char *Pbuff)
{
	PUFTPHOST pfh;
//*********************************
	if (!(pfh=uftpnodesrch(Phost)))
    	return 0;
    if (UFTPHISTSO(pfh))                                           //~v5jgI~
        return u3270getcwd(pfh,Pbuff);                             //~v5jgI~
    if (!*pfh->UFTPHcwd)		//not yet set                      //~v59nR~
    {                                                              //~v59nI~
	    if (!*pfh->UFTPHhome)                                      //~v59nI~
        	uftpgethomesub(pfh);                                   //~v59nI~
        strcpy(pfh->UFTPHcwd,pfh->UFTPHhome);	//copy home        //~v59nI~
    }                                                              //~v59nI~
    strcpy(Pbuff,pfh->UFTPHcwd);                                   //~v59nI~
    if (!*Pbuff)                                                   //~v59nR~
//  	return 0;                                                  //~v616R~
    	strcpy(Pbuff,FTP_DIR_SEPS);                                //~v616R~
    return Pbuff;                                                  //~v59nI~
}//uftpgetcwd
//*******************************************************
//*get home dir
//*parm  :output buff
//*return:ptr to buff
//*******************************************************
char *uftpgethome(char *Phost)
{
	PUFTPHOST pfh;
    char *phome;
//*********************************
	if (!(pfh=uftpnodesrch(Phost)))
    	return 0;
    phome=pfh->UFTPHhome;
    if (!*phome)                                                   //~v59nI~
    	uftpgethomesub(pfh);                                       //~v59nI~
    if (!*phome)
    	return 0;
    return phome;
}//uftpgethome                                                     //~v59nR~
//*******************************************************          //~v59nI~
//*get home dir                                                    //~v59nR~
//*******************************************************          //~v59nI~
int uftpgethomesub(PUFTPHOST Ppfh)                                 //~v59nR~
{                                                                  //~v59nI~
	int rc,len,stdoctr;                                            //~v59nR~
    char **stdo,**stdo0,*pc,*pc2;                                  //~v59nI~
//*********************************                                //~v59nI~
    rc=uftpcmd(Ppfh,0,"pwd\n",&stdo0,&stdoctr,0,0);  //get stdout/stderr//~v5afR~
    if (!rc)                                                       //~v59nI~
    {                                                              //~v59nI~
        stdo=stdo0;                                                //~v59nI~
      if (UFTPHISPSFTP(Ppfh))                                      //~v61pI~
        rc=uftp3gethomesub(0,Ppfh,stdo,stdoctr);                   //~v61pR~
      else                                                         //~v61pI~
      {                                                            //~v61pI~
        rc=uftpcmdsrchrespid(&stdo,&stdoctr,"257 ");               //~v59nI~
        switch(rc)                                                 //~v59nI~
        {                                                          //~v59nI~
        case 0:    //257 "---" is current dir                      //~v59nI~
            pc=*(stdo-1);	//stdo is next of 257 line             //~v59nR~
            pc+=4;                                                 //~v59nI~
            pc+=strspn(pc," ");                                    //~v59nI~
            if (*pc=='"')                                          //~v59nI~
            {                                                      //~v59nI~
                pc++;                                              //~v59nR~
                pc2=strchr(pc,'"');                                //~v59nI~
            }                                                      //~v59nI~
            else                                                   //~v59nI~
                pc2=strchr(pc,' ');                                //~v59nI~
            if (pc2)                                               //~v59nI~
//              len=(int)((ULONG)pc2-(ULONG)pc);                   //~v59nM~//~v6hhR~
                len=(int)((ULPTR)pc2-(ULPTR)pc);                   //~v6hhI~
            else                                                   //~v59nI~
//              len=strlen(pc);                                    //~v59nI~//~v6D0R~
                len=(int)strlen(pc);                               //~v6D0I~
            if (len<FTP_MAXPATH)                                   //~v59nR~
            {                                                      //~v59nR~
                memcpy(Ppfh->UFTPHhome,pc,(UINT)len);              //~v59nR~
                *(Ppfh->UFTPHhome+len)=0;                          //~v59nR~
            }                                                      //~v59nR~
            else                                                   //~v59nI~
                rc=8;                                              //~v59nI~
            break;                                                 //~v59nI~
        default:                                                   //~v59nI~
            ;                                                      //~v59nI~
        }                                                          //~v59nI~
      }                                                            //~v61pI~
        ufree(stdo0);                                              //~v59nI~
    }                                                              //~v59nI~
    return rc;                                                     //~v59nI~
}//uftpgethomesub                                                  //~v59nI~
//*******************************************************
//*change current directory
//*parm 1:path name
//*return:0:ok else err
//*******************************************************
int uftpchdir(PUFTPHOST Ppuftph,int Popt,unsigned char *Ppath)     //~v5afR~
{
    int rc,hostnmlen;                                              //~v59nR~
    char fpath[FTP_MAXPATH],*pdirnm;                               //~v59nR~
//*********************************
    if (UFTPHISTSO(Ppuftph))                                       //~v5jgI~
		return u3270chdir(Ppuftph,Popt,Ppath);                     //~v5jgR~
	hostnmlen=Ppuftph->UFTPHhostnmlen;                             //~v5afR~
    if (!uftpfullpath(Ppuftph,fpath,Ppath,sizeof(fpath)))          //~v5afR~
        rc=ENOENT;                                                 //~v5afR~
    else                                                           //~v5afR~
    {                                                              //~v5afR~
        pdirnm=fpath+hostnmlen+1;                                  //~v5afR~
        rc=uftpchdirsub(Ppuftph,pdirnm);                           //~v5afR~
        if (rc)                                                    //~v5afR~
            rc=ENOENT;                                             //~v5afR~
        else                                                       //~v5afR~
            strncpy(Ppuftph->UFTPHcwd,pdirnm,sizeof(Ppuftph->UFTPHcwd));//~v5afR~
    }                                                              //~v5afR~
    if (rc)                                                        //~v59nI~
    {                                                              //~v59nI~
      	if (!(Popt & UCHD_NOMSG))		//not no errmsg option     //~v59nI~
        {                                                          //~v61bI~
        	uerrmsg("FTP chdir failed for %s",0,                   //~v59nR~
                	Ppath);                                        //~v59nR~
			uftplog(FTPLOG_ERRM,0);	//logging errmsg               //~v61bI~
        }                                                          //~v61bI~
    }                                                              //~v59nI~
    return rc;
}//uftpchdir
//*******************************************************          //~v59nI~
//*chk chdir validity                                              //~v59nI~
//*******************************************************          //~v59nI~
int uftpchdirsub(PUFTPHOST Ppuftph,char *Pdirname)                 //~v5afR~
{                                                                  //~v59nI~
	int rc,stdoctr;                                                //~v59nI~
    char **stdo,**stdo0;                                           //~v59nR~
    UCHAR ftpcmd[FTP_MAXPATH+128];                                 //~v59nI~
//*********************************                                //~v59nI~
#ifdef ARMXXE                                                      //~v6daI~
    if (UFTPH_ISSMBJ(Ppuftph))                                     //~v6daI~
        return jnismb_uchdir(0,Ppuftph,Pdirname);                  //~v6daI~
#endif                                                             //~v6daI~
    sprintf(ftpcmd,"cd  \"%s\"\n",Pdirname);                       //~v5bfR~
    rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo0,&stdoctr,0,0);  //get stdout/stderr//~v5afR~
    if (!rc)                                                       //~v59nI~
    {                                                              //~v59nI~
        stdo=stdo0;                                                //~v59nI~
      if (UFTPH_ISSMB(Ppuftph))                                    //~v6d1R~
		rc=uftp3smb_respchk(UFTPSMBCMD_CD,Ppuftph,Pdirname,&stdo,&stdoctr,4);//~v6d1R~
      else                                                         //~v6d1R~
      if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
		rc=uftp3cdrespchk(0,Ppuftph,Pdirname,&stdo,&stdoctr);      //~v61pI~
      else                                                         //~v61pI~
        rc=uftpcmdsrchrespid(&stdo,&stdoctr,"250 550 "); //CD ok or no such file//~v59nI~
        if (rc)	//cd fail                                          //~v59nI~
        	rc=ENOENT;                                             //~v59nI~
        ufree(stdo0);                                              //~v59nI~
    }                                                              //~v59nI~
    return rc;                                                     //~v59nI~
}//uftpchdirsub                                                    //~v59nI~
#ifdef AAA  //not used                                             //~v61pI~
//*******************************************************          //~v59nI~
//*chang local dir                                                 //~v59nI~
//*******************************************************          //~v59nI~
int uftplchdir(PUFTPHOST Ppuftph,int Popt,char *Pdirname)          //~v5afR~
{                                                                  //~v59nI~
	int rc,stdoctr;                                                //~v59nI~
    char **stdo,**stdo0;                                           //~v59nI~
    UCHAR ftpcmd[FTP_MAXPATH+128];                                 //~v59nI~
//*********************************                                //~v59nI~
//  sprintf(ftpcmd,"lcd  \"%s\"\npwd\n",Pdirname);                 //~v61nR~
    sprintf(ftpcmd,"lcd  \"%s\"\n" FTP_LOCALCMD_PWD "\npwd\n",Pdirname);//~v61nI~
    rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo0,&stdoctr,0,0);  //get stdout/stderr//~v5afR~
    if (!rc)                                                       //~v59nI~
    {                                                              //~v59nI~
        stdo=stdo0;                                                //~v59nI~
//      rc=uftplchdirrespchk(&stdo,&stdoctr); //lcd(returns no msg id) responce chk//~v61nR~
        rc=uftplchdirrespchk(&stdo,&stdoctr,Pdirname); //lcd(returns no msg id) responce chk//~v61nI~
        ufree(stdo0);                                              //~v59nM~
    }                                                              //~v59nM~
    if (rc)                                                        //~v59nI~
    {                                                              //~v59nI~
        if (!(Popt & UCHD_NOMSG))       //not no errmsg option     //~v59nI~
        {                                                          //~v61bI~
            uerrmsg("FTP local chdir failed for %s",0,             //~v59nI~
                    Pdirname);                                     //~v59nI~
			uftplog(FTPLOG_ERRM,0);	//logging errmsg               //~v61bI~
        }                                                          //~v61bI~
    }                                                              //~v59nI~
    return rc;                                                     //~v59nI~
}//uftplchdir                                                      //~v59nI~
#endif                                                             //~v61pI~
//*******************************************************          //~v59nI~
//*chang local dir responce msg chk                                //~v59nI~
//*******************************************************          //~v59nI~
//int uftplchdirrespchk(char ***Ppstdo,int *Ppstdoctr)             //~v61nR~
//int uftplchdirrespchk(char ***Ppstdo,int *Ppstdoctr,char *Pdirnm)//~v61pR~
int uftplchdirrespchk(int Popt,PUFTPHOST Ppuftph,char ***Ppstdo,int *Ppstdoctr,char *Pdirnm)//~v61pI~
{                                                                  //~v59nI~
	int rc,stdoctr;                                                //~v59nI~
    char **stdo,**stdo0,*rmsg;                                     //~v5atR~
//*********************************                                //~v59nI~
    if (UFTPH_ISSMB(Ppuftph))                                      //~v6d1R~
    	return uftp3smb_lchdirrespchk(0,Ppuftph,Ppstdo,Ppstdoctr,Pdirnm);//~v6d1R~
    if (UFTPHISPSFTP(Ppuftph))                                     //~v61pI~
    	return uftp3lchdirrespchk(Popt,Ppuftph,Ppstdo,Ppstdoctr,Pdirnm);//~v61pI~
	stdo=*Ppstdo;                                                  //~v59nI~
	stdoctr=*Ppstdoctr;                                            //~v59nI~
    if (!stdoctr)                                                  //~v59nI~
    	return ENOENT;                                             //~v59nI~
//  rc=uftpcmdsrchrespid(&stdo,&stdoctr,"250 550 "); //CD ok or no such file//~v59nI~
	rc=ENOENT;                                                     //~v5atI~
    stdo0=stdo;                                                    //~v5atI~
    for (;stdoctr>0;stdoctr--,stdo++)                              //~v5atR~
    {                                                              //~v5atI~
    	rmsg=*stdo;                                                //~v5atI~
		if (!memcmp(rmsg,"257 ",4)) //next pwd responce            //~v5atR~
        {                                                          //~v5atI~
        	if (stdo==stdo0)                                       //~v5atI~
            	rc=0;                                              //~v5atI~
        	break;                                                 //~v5atI~
        }                                                          //~v5atI~
        else                                                       //~v5atI~
        if (!memcmp(rmsg,"250 ",4))                                //~v59nR~
            rc=0;                                                  //~v59nR~
        else                                                       //~v59nR~
        if (ustrstri(rmsg,"directory now")) //ambiguous but        //~v59nR~
            rc=0;                                                  //~v59nR~
        else                                                       //~v61nI~
#ifdef W32                                                         //~v61nI~
        if (!stricmp(rmsg,Pdirnm)) //result of !cd cmd             //~v61nI~
#else	                                                           //~v61nI~
        if (!strcmp(rmsg,Pdirnm)) //result of !pwd cmd             //~v61nI~
#endif                                                             //~v61nI~
            rc=0;                                                  //~v61nI~
    }                                                              //~v59nI~
    if (stdoctr)                                                   //~v5atI~
    {                                                              //~v5atI~
    	stdoctr--;                                                 //~v5atI~
        stdo++;                                                    //~v5atR~
    }                                                              //~v5atI~
	*Ppstdo=stdo;                                                  //~v5atR~
	*Ppstdoctr=stdoctr;                                            //~v5atR~
    return rc;                                                     //~v59nI~
}//uftplchdirrespchk                                               //~v59nI~
//**********************************************************************//~v59nM~
// return :r.c                                                     //~v59nM~
//**********************************************************************//~v59nM~
int uftpdirlistsub(PUFTPHOST Ppuftph,int Popt,int *Ppentno,char *Pfpath,ULONG Pattr,PUDIRLIST *Pppudl)//~v5afR~
{                                                                  //~v59nM~
    int rc,entnoall,entno;                                         //~v59nR~
    int rc2;                                                       //~v5dmR~
    PUDIRLIST pudl,pudl0,pudlw;                                    //~v59nR~
    ULONG hdir;                                                    //~v59nM~
//  char fpath[_MAX_PATH];                                         //~v5dmI~//~v6H7R~
    char fpath[FTP_MAXPATH];                                       //~v6H7I~
    int membsw;                                                    //~v5dmI~
//*********************************                                //~v59nI~
    *Ppentno=0;                                                    //~v59nI~
    *Pppudl=0;                                                     //~v59nI~
    if (Ppuftph->UFTPHflag & UFTPHFTSO)                            //~v5jbI~
        return u3270dirlistsub(Ppuftph,Popt,Ppentno,Pfpath,Pattr,Pppudl);//~v5jbR~
#ifdef ARMXXE                                                      //~v6daI~
    if (UFTPH_ISSMBJ(Ppuftph))                                     //~v6daI~
        return jnismb_udirlist(Popt,Ppuftph,Ppentno,Pfpath,Pattr,Pppudl);;//~v6daR~
#endif                                                             //~v6daI~
    rc=uftpopendir(Ppuftph,Pfpath+Ppuftph->UFTPHhostnmlen+1,Pattr,&hdir,&entnoall);//~v5afR~
    if (rc)                                                        //~v59nM~
    {                                                              //~v59nM~
        if(rc==ENOENT)                //cd failed                  //~v59nR~
	    	if (!(Popt & FTP_DLSNONFMSG))                          //~v59nM~
            {                                                      //~v59nI~
//              if (uftpisexist(Ppuftph,Pfpath)==1)  //exist not dir file//~v5dmR~
				if (WILDCARD(Pfpath))                              //~v5dmI~
                {                                                  //~v5dmI~
					if (ufilegetpathdir(Pfpath,fpath))//root       //~v5dmR~
                    	rc2=4;	//rootdir                          //~v5dmI~
                    else                                           //~v5dmI~
	                	rc2=uftpisexist(Ppuftph,fpath);//chk parentdir//~v5dmI~
                }	                                               //~v5dmI~
                else                                               //~v5dmI~
                	rc2=uftpisexist(Ppuftph,Pfpath);               //~v5dmR~
                if (rc2==1)  //exist as file                       //~v5dmR~
            		ufilenotdir(Pfpath,rc);                        //~v59nM~
                else                                               //~v59nI~
                if (rc2==2)  //exist as dir                        //~v5dmR~
                	rc=ufilenopermission("ls",Pfpath,EPERM);//rc=1:operation not permitted//~v5dmR~
                else                                               //~v5dmR~
            		ufilenotfound(Pfpath,rc);                      //~v59nM~
            }//nomsg                                               //~v59nI~
        return rc;                                                 //~v59nM~
    }                                                              //~v59nM~
//  pudl0=umalloc((UINT)(entnoall*UDIRLISTSZ));                    //~v5ceR~
//  pudl0=umalloc((UINT)((entnoall+1)*UDIRLISTSZ));                //~v5ceI~//~v6qaR~
//  pudl0=UALLOCC(1,(UINT)((entnoall+1)*UDIRLISTSZ));//clear for free entry chk//~v6qaI~//~v6D0R~
    pudl0=UALLOCC(1,(size_t)((entnoall+1)*(int)UDIRLISTSZ));//clear for free entry chk//~v6D0I~
    UALLOCCHK(pudl0,UALLOC_FAILED);                                //~v59nM~
    membsw=0;                                                      //~v5dmI~
    for (pudl=pudl0,entno=0;entno<entnoall;entno++,pudl++)         //~v59nM~
    {                                                              //~v59nM~
//      if (uftpreaddir(hdir,&pudlw))                              //~v59nR~//~v6D0R~
        if (uftpreaddir((int)hdir,&pudlw))                         //~v6D0I~
            break;                                                 //~v59nM~
//      *pudl=*pudlw;                                              //~v59nI~//~v6qaR~
        UDIRLIST_COPY(pudl,pudlw);	//move allocated slinkname of pudlw  to pudl//~v6qaR~
        membsw=1;   //found a entry                                //~v5dmI~
    }                                                              //~v59nM~
//  uftpclosehdir(hdir);                                           //~v59nM~//~v6D0R~
    uftpclosehdir((int)hdir);                                      //~v6D0I~
    if (!membsw)                                                   //~v5dmI~
    {                                                              //~v5dmI~
//      ufree(pudl0);                                              //~v5dmI~//~v6qaR~
        UDIRLIST_FREE(pudl0);                                      //~v6qaI~
        rc=ENOENT;                                                 //~v5dmI~
#ifdef UTF8SUPPH                                                   //~v62bI~
        if (Pattr & FILE_DIRECTORY)                                //~v62bI~
        	return ufileerrnoentry(Pfpath,rc);                     //~v62bI~
        else                                                       //~v62bI~
        	return ufileerrnofileentry(Pfpath,rc);                 //~v62bI~
#else                                                              //~v62bI~
	    if (!(Popt & FTP_DLSNONFMSG))                              //~v5dmI~
        	return ufilenotfound(Pfpath,rc);                       //~v5dmI~
//#endif                                                             //~v62bI~//~v6heR~
        return rc;                                                 //~v5dmI~
#endif                                                             //~v6heI~
                                                                   //~v62bI~
    }                                                              //~v5dmI~
    *Ppentno=entno;                                                //~v59nM~
    *Pppudl=pudl0;                                                 //~v59nM~
    return 0;                                                      //~v59nM~
}//uftpdirlistsub                                                  //~v59nM~
//**********************************************************************
// find first
// parm1  :file name
//         opendir fail if wild card for UNX
// parm2  :HDIR ptr,if no contention,specify 0.for dos specify always 0
// parm3  :search file attribute
// parm4  :found file info
// return :r.c
//**********************************************************************
int uftpfindfirst(PUFTPHOST Ppuftph,int Popt,char *Pfpath,ULONG *Pphdir,unsigned int Pattr,FILEFINDBUF3 *Ppfstat3)//~v5afR~
{
    ULONG hdir;                                                    //~v59nR~
    int rc,entno;                                                  //~v5afR~
//*********************************
#ifdef ARMXXE                                                      //~v6daI~
    if (UFTPH_ISSMBJ(Ppuftph))                                     //~v6daI~
    {                                                              //~v6daI~
        rc=jnismb_ufindfirst(Popt,Ppuftph,Pfpath,Pattr,Ppfstat3);  //~v6daR~
        return rc;                                                 //~v6daI~
    }                                                              //~v6daI~
#endif                                                             //~v6daI~
    rc=uftpopendir(Ppuftph,Pfpath+Ppuftph->UFTPHhostnmlen+1,Pattr,&hdir,&entno);//~v5afR~
    if (rc)                                                        //~v59nR~
    {
        if(rc==ENOENT) //cd faile                                  //~v59nR~
        {                                                          //~v5ajR~
          if (!WILDCARD(Pfpath))                                   //~v5chR~
        	if (!uftpfindfirstfile(Ppuftph,Pfpath,Pattr,Ppfstat3)) //~v5ajR~
            	return 0;                                          //~v5ajR~
	    	if (!(Popt & UFTPFF_NOMSG))                            //~v59nR~
            	ufilenotfound(Pfpath,rc);                          //~v5ajR~
        }                                                          //~v5ajR~
        return rc;                                                 //~v59nI~
    }
//  rc=uftpfindnext(hdir,Ppfstat3);                                //~v5afR~//~v6D0R~
    rc=(int)uftpfindnext((int)hdir,Ppfstat3);                      //~v6D0I~
    if (rc)                                                        //~v59nI~
    {                                                              //~v59nI~
    	if (rc==4)                                                 //~v59nR~
//  		rc=ERROR_FILE_NOT_FOUND;                               //~v59nR~
    		rc=ERROR_NO_MORE_FILES;                                //~v59nI~
//  	uftpclosehdir(hdir);//free handle                          //~v59nI~//~v6D0R~
    	uftpclosehdir((int)hdir);//free handle                     //~v6D0I~
    }                                                              //~v59nI~
    else                                                           //~v59nI~
    {                                                              //~v59nI~
    	if (Pphdir)     //handle return not required for find next //~v59nR~
        	*Pphdir=hdir;                                          //~v59nR~
        else                                                       //~v59nI~
//      	uftpclosehdir(hdir);//free handle                      //~v59nR~//~v6D0R~
        	uftpclosehdir((int)hdir);//free handle                 //~v6D0I~
    }
    return rc;
}//uftpfindfirst                                                   //~v59nR~
//**********************************************************************//~v5ajR~
// find first file                                                 //~v5ajR~
// return :r.c                                                     //~v5ajR~
//**********************************************************************//~v5ajR~
int uftpfindfirstfile(PUFTPHOST Ppuftph,char *Pfpath,unsigned int Pattr,FILEFINDBUF3 *Ppfstat3)//~v5ajR~
{                                                                  //~v5ajR~
    int rc;                                                        //~v5ajR~
//*********************************                                //~v5ajR~
//  rc=uftpfstat(Ppuftph,Pfpath,Ppfstat3);                         //~v5ajR~//~v6D0R~
    rc=(int)uftpfstat(Ppuftph,Pfpath,Ppfstat3);                    //~v6D0I~
    if (rc)                                                        //~v5ajR~
        return rc;                                                 //~v5ajR~
    if (!uftpattrselect(Ppfstat3->attrFile,Ppfstat3->srcattr,Pattr))    //attr match//~v5ajR~
        return ENOENT;                                             //~v5ajR~
    return 0;                                                      //~v5ajR~
}//uftpfindfirstfile                                               //~v5ajR~
//**********************************************************************
// find next
// parm1  :HDIR specified at findfirst. for dos specify always 0
// parm2  :found file info
// return :r.c  0:found 4:no more file else errno
//**********************************************************************
unsigned uftpfindnext(int Phdir,FILEFINDBUF3 *Ppfstat3)
{
    PUFTPDIRH pfdh;
    PUDIRLIST pudl;                                                //~v59nR~
    int    rc;
//*********************************
    if (!(pfdh=uftpsrchhdir(Phdir)))                               //~v59nR~
        return ERROR_INVALID_HANDLE;
    rc=uftpreaddir(Phdir,&pudl);                                   //~v59nR~
    if (rc)                                                        //~v59nI~
    {                                                              //~v59nI~
        rc=4;                                                      //~v59nI~
        uftpclosehdir(Phdir);                                      //~v59nR~
    }                                                              //~v59nI~
    else                                                           //~v59nI~
		uftpudl2ffb3(pudl,Ppfstat3);                               //~v59nR~
//  return rc;                                                     //~v59nR~//~v6D0R~
    return (unsigned)rc;                                           //~v6D0I~
}//uftpfindnext
