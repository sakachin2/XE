//*CID://+v6J0R~:                             update#=  223;       //~v6J0R~
//*************************************************************    //~v5jxR~
//*ufile3.c
//*  u3270xcopy,u3270xmove                                         //~v5jeR~
//*************************************************************
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6H1:161231 filename >_MAX_PATH occurse when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v6H1I~
//            and it cause fpath area overflow then 0c4            //~v6H1I~
//v6D1:160418 LNX64 compiler warning                               //~v6D1I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v5mQ:080806 (CJK)DBCS chk for C(J)K                              //~v5mQI~
//v5mH:080629 3270:num std fld consideration for SJIS->EBC translation//~v5mBI~
//v5mB:080621 3270:DBCS conversion support                         //~v5mBI~
//v5mx:080602 pass hostid to identify logon cmd hostid             //~v5mxI~
//v5k0:061226 (LNX/WIN)largefile(>4GB) support                     //~v5k0I~
//v5jy:061123 3270:SPF information update                          //~v5jyI~
//v5jx:061123 3270:allow upload to PS dataset                      //~v5jxI~
//v5jw:061123 3270:set exist=replace for also upload. (for the future IND$FILE version up)//~v5jwI~
//v5jk:061021 (3270:BUG)exist chk miss for the target wildcard generated same name//~v5jkI~
//v5je:061013 3270 support:xcopy/xmove                             //~v5jeI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>                                              //~5B12I~
//*******************************************************
#ifdef DOS
#else
    #ifdef W32                                                     //~v022I~
        #include <dos.h>                                           //~v022I~
        #include <windows.h>                                       //~v5e1I~
    #else                                                          //~v022I~
    #endif                                                         //~v022I~
#endif

//*******************************************************
#include <ulib.h>
#include <ufile.h>
#include <ufile2.h>
#include <ufile3.h>
#include <ufile4.h>                                                //~v5jeI~
#include <ufile5.h>                                                //~v280I~
#include <ufemsg.h>                                                //~v053I~
#include <uerr.h>
#include <ualloc.h>
#include <uque.h>                                                  //~v59rI~
#ifdef FTPSUPP                                                     //~v59rI~
	#include <uftp.h>                                              //~v59rI~
	#include <u3270.h>                                             //~v5jeI~
	#include <u32702.h>                                            //~v5jeI~
#endif                                                             //~v59rI~
#include <utrace.h>                                                //~v5jkM~
#include <ustring.h>                                               //~v6J0I~
//*******************************************************
typedef struct _WCPARMTSOFTP  {                                    //~v5jeR~
                            UCHAR *wctfullpath;                 //~5916I~
                            int wcopt;                          //~5916I~
                            int wctpathlen;                     //~5916I~
                            int wcspathlen; //source path len      //~v5jeI~
                            unsigned wcattrmask;                   //~v5jeR~
                            int wcflag; //flag                     //~v291R~
#define CPYMV_TWILD    0x01     //target is wild card              //~v291I~
#define CPYMV_TFILE    0x02     //target is file                   //~v291I~
#define CPYMV_TNEW     0x04     //target is not found              //~v291I~
#define CPYMV_TROOT    0x08     //target is root                   //~v291I~
#define CPYMV_TDIR     0x10     //target is dir                    //~v291I~
#define CPYMV_TPATHERR 0x20     //target is path err               //~v5cdR~
#define CPYMV_TMEMBER  0x40     //target is PDS member             //~v5jeI~
#define CPYMV_CHKMEMB  0x80     //member replace check hes to be done//~v5jeI~
#define CPYMV_OTHERERR 0x0100   //3270 err                         //~v5jeI~
                            int wccopyctr; //copye successed count //~v5jeR~
                            int wcskipctr; //invalid membername skipped//~v5jeI~
                            PUFTPHOST wcpuftph;                    //~v5jeI~
                            PUDIRLIST wcpudl;   //target dirlist   //~v5jeI~
                            int       wcpudlctr;//target dirlist ctr//~v5jeI~
                            FILEFINDBUF3 wcpfstat3t;//pds fstat    //~v5jyI~
                            FILEFINDBUF3 wcpfstat3s;//source(get) pds fstat//~v5mBI~
                            } WCPARMTSOFTP;                        //~v5jeR~
//*******************************************************
#define R2R_GET  0x01000000           //get ok falg on udirlist attr for r2r//~v5jeI~
#define R2R_PUT  0x02000000           //put ok falg on udirlist attr for r2r//~v5jeI~
//**************************************************************** //~v5jeI~
static int  Sr2rsrcattrs=0;                                        //~v5jeR~
static int  Sr2rskipctr=0;                                         //~v5jeI~
static int  Sr2rfilectr=0;                                         //~v5jeI~
static PUDIRLIST Sr2rpudl;                                         //~v5jeI~
static FILEFINDBUF3 Sr2rsinglememberfstat;                         //~v5jyI~
static char Sr2rsinglemember[DSN_MAXLEN];                          //~v5jeI~
//**************************************************************** //~v5jeI~
int u3270xcopyr2r(int Popt,PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,  //~v5jeR~
			UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask);     //~v5jeI~
int u3270xcopyget(int Popt,PUFTPHOST Ppuftphs,UCHAR *Psource,UCHAR *Ptarget);//~v5jeI~
int u3270xcopyput(int Popt,PUFTPHOST Ppuftpht,UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask);//~v5jeI~
//int u3270copysubput(int Popt,PUFTPHOST Ppuftph,UCHAR *Psource,UCHAR *Ptarget,int Pflags);//~v5jyR~
int u3270copysubput(int Popt,PUFTPHOST Ppuftph,UCHAR *Psource,UCHAR *Ptarget,int Pflags,FILEFINDBUF3 *Ppfstat3s,FILEFINDBUF3 *Ppfstat3t);//~v5jyR~
//int u3270copysubget(int Popt,PUFTPHOST Ppuftph,UCHAR *Psource,UCHAR *Ptarget);//~v5mBR~
int u3270copysubget(int Popt,PUFTPHOST Ppuftph,UCHAR *Psource,UCHAR *Ptarget,FILEFINDBUF3 *Ppfstat3s);//~v5mBI~
int u3270filecreateparmproc(PUFTPHOST Ppuftphs,char *Psfullpath,ULONG Psattr,//~v5jeR~
							PUFTPHOST Ppuftpht,char *Ptfullpath,int *Pptrootsw);//~v5jeI~
int u3270filecpymvflags(int Ptwild,int Ptrootsw,PUFTPHOST Puftpht,char *Ptfullpath,FILEFINDBUF3 *Ppfstat3t);//~v5jeI~
int u3270filewildcopyput(UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm);//~v5jeI~
int u3270filewildcopyget(PUFTPHOST Ppuftph,UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm);//~v5jeI~
//int u3270transfer(int Popt,PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,//~v5mBR~
//			UCHAR *Psource,UCHAR *Ptarget);                        //~v5mBR~
int u3270srcdupchk(char *Psfullpath,ULONG Psattr,char *Ptfullpath);//~v5jkI~
int u3270copyspfupdate(int Popt,PUFTPHOST Ppuftph,UCHAR *Psource,UCHAR *Ptarget,int Pflags,FILEFINDBUF3 *Ppfstat3s,FILEFINDBUF3 *Ppfstat3t);//~v5jyR~
int u3270setftpparm(int Popt,PUFTPHOST Ppuftph,PUTSOFTPPARM Pptsop,FILEFINDBUF3 *Ppfstat3);//~v5mBI~
//**************************************************************** //~v5jeM~
//u3270xmove                                                       //~v5jeM~
//*retrn:rc                                                        //~v5jeM~
//**************************************************************** //~v5jeM~
int u3270xmove(int Popt,PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,     //~v5jeM~
			UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask)      //~v5jeM~
{                                                                  //~v5jeM~
	int ii,rc;                                                     //~v5jeR~
    char wksrc[DSN_MAXLEN];                                        //~v5jeI~
    PUDIRLIST pudl;                                                //~v5jeI~
//**************************                                       //~v5jeI~
    rc=u3270xcopy(Popt|DCPY_MOVE,Ppuftphs,Ppuftpht,Psource,Ptarget,Pattrmask);//~v5jeR~
    if (Sr2rpudl) 	//for delete source member moved when r2r      //~v5jeI~
    {                                                              //~v5jeI~
    	for (ii=Sr2rfilectr,pudl=Sr2rpudl;ii>0;ii--,pudl++)        //~v5jeI~
        {                                                          //~v5jeI~
        	if ((pudl->attr & (R2R_GET|R2R_PUT))==(R2R_GET|R2R_PUT))	//get/put success//~v5jeR~
            {                                                      //~v5jeI~
		     	u3270concatfilename(U3CF_FORCEASMEMBERIFNOTWILD,Psource,pudl->name,wksrc);//~v5jeI~
		    	rc+=u3270remove(Ppuftphs,UXDELNOMSG,wksrc);        //~v5jeR~
            }                                                      //~v5jeI~
        }                                                          //~v5jeI~
//  	ufree(Sr2rpudl);                                           //~v5jeR~//~v6qaR~
    	UDIRLIST_FREE(Sr2rpudl);                                   //~v6qaI~
    	Sr2rpudl=0;                                                //~v5jeI~
    }                                                              //~v5jeI~
    else                                                           //~v5jeI~
    	if (!rc)                                                   //~v5jeI~
	    	if (*Sr2rsinglemember)                                 //~v5jeR~
            {                                                      //~v5jeI~
		    	rc+=u3270remove(Ppuftphs,UXDELNOMSG,Sr2rsinglemember);//~v5jeR~
		    	*Sr2rsinglemember=0;                               //~v5jeI~
            }                                                      //~v5jeI~
    return rc;                                                     //~v5jeM~
}//u3270xmove                                                      //~v5jeI~
//**************************************************************** //~v5jeI~
//u3270xcopyr2r                                                    //~v5jeI~
//**************************************************************** //~v5jeI~
int u3270xcopyr2r(int Popt,PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,  //~v5jeR~
			UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask)      //~v5jeI~
{                                                                  //~v5jeI~
    char tempfnm[_MAX_PATH];                                       //~v5jeI~
    char tempfnm0[_MAX_PATH];                                      //~v5jeI~
    char tgt[_MAX_PATH];                                           //~v5jeI~
    int len,rc,opt;                                                //~v5jeR~
//*************************                                        //~v5jeI~
	if (uftpmktempwd(tempfnm))                                     //~v5jeI~
    	return -1;                                                 //~v5jeI~
    strcpy(tempfnm0,tempfnm);                                      //~v5jeI~
    strcpy(tgt,Ptarget);                                           //~v5jeI~
    opt=Popt & ~DCPY_APPEND;                                       //~v5jeI~
    opt|=Popt | DCPY_R2R;                                          //~v5jeI~
    rc=u3270xcopyget(opt,Ppuftphs,Psource,tempfnm);                //~v5jeI~
    if (!rc||rc==DCPY_RC_NOTCOPY)                                  //~v5jeR~
    {                                                              //~v5jeI~
//  	len=strlen(tempfnm);                                       //~v5jeI~//~v6D0R~
    	len=(int)strlen(tempfnm);                                  //~v6D0I~
        if (!(Sr2rsrcattrs & FILE_DIRECTORY))	//filename should be append; \tempd\fnm//~v5jeR~
	    {                                                          //~v5jeR~
    		*(tempfnm+len++)=DIR_SEPC;                             //~v5jeR~
	        u3270getlastname(0,Psource,tempfnm+len);               //~v5jeI~
      	}                                                          //~v5jeR~
	    opt=Popt & ~DCPY_MOVE; 	//delete tempdir at once           //~v5jeI~
        opt|=DCPY_R2R;      //for spf update                       //~v5jyI~
		rc=u3270xcopyput(opt,Ppuftpht,tempfnm,tgt,FILE_ALL-FILE_DIRECTORY);//~v5jeR~
        if (!rc)                                                   //~v5jeI~
        	if (Sr2rskipctr)                                       //~v5jeI~
            {                                                      //~v5jeI~
            	uerrmsgcat("%d member skipped by InvalidMemberName or AlreadyExist",0,//~v5jeR~
    	            		Sr2rskipctr);                          //~v5jeI~
	            rc=DCPY_RC_NOTCOPY;                                //~v5jeR~
            }                                                      //~v5jeI~
    }                                                              //~v5jeI~
	rc+=uftpdeltempwd(tempfnm0);                                   //~v5jeI~
    if (Sr2rpudl) 	//for delete source member moved when r2r      //~v5jyI~
        if (!(Popt & DCPY_MOVE))                                   //~v5jyI~
        {                                                          //~v5jyI~
//  		ufree(Sr2rpudl);                                       //~v5jyI~//~v6qaR~
    		UDIRLIST_FREE(Sr2rpudl);                               //~v6qaI~
    		Sr2rpudl=0;                                            //~v5jyI~
        }                                                          //~v5jyI~
    return rc;                                                     //~v5jeI~
}//uftpxcopyr2r                                                    //~v5jeI~
//**************************************************************** //~v5jeI~
//u3270xcopy                                                       //~v5jeR~
//* file/dir copy                                                  //~v5jeI~
//**************************************************************** //~v5jeI~
int u3270xcopy(int Popt,PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask)//~v5jeR~
{                                                                  //~v5jeI~
//********************                                             //~v5jeI~
	Sr2rsrcattrs=0;                                                //~v5jeR~
	Sr2rskipctr=0;                                                 //~v5jeI~
	Sr2rpudl=0;                                                    //~v5jeI~
	*Sr2rsinglemember=0;                                           //~v5jeI~
	Sr2rsinglememberfstat.attrFile=0;                              //~v5jyR~
    if (Popt & DCPY_REPOLD)       //repl old member only           //~v5jeI~
			return uerrnotsupported("Replace New Option","TSO file",U3CR_RC_NOTSUPPORT);//~v5jeI~
                                                                   //~v5jeI~
  	if (UFTPHISTSO(Ppuftphs))                                      //~v5jeR~
        if (UFTPHISTSO(Ppuftpht))                                  //~v5jeR~
    		return u3270xcopyr2r(Popt,Ppuftphs,Ppuftpht,Psource,Ptarget,Pattrmask);//~v5jeR~
        else                                                       //~v5jeI~
        	if (Ppuftpht)	//remote ftp                           //~v5jeI~
				return uerrnotsupported("Transfer between remote","TSO and FTP",U3CR_RC_NOTSUPPORT);//~v5jeR~
            else                                                   //~v5jeI~
	    		return u3270xcopyget(Popt,Ppuftphs,Psource,Ptarget);//~v5jeR~
    else                                                           //~v5jeI~
        if (UFTPHISTSO(Ppuftpht))                                  //~v5jeR~
        	if (Ppuftphs)	//src is ftp                           //~v5jeI~
				return uerrnotsupported("Transfer between remote","TSO and FTP",U3CR_RC_NOTSUPPORT);//~v5jeR~
            else                                                   //~v5jeI~
	    		return u3270xcopyput(Popt,Ppuftpht,Psource,Ptarget,Pattrmask);//~v5jeR~
        else                                                       //~v5jeI~
    		return 16;                                             //~v5jeI~
}//u3270xcopy                                                      //~v5jeI~
//**************************************************************** //~v5jeI~
//u3270xcopyget                                                    //~v5jeI~
//**************************************************************** //~v5jeI~
int u3270xcopyget(int Popt,PUFTPHOST Ppuftphs,UCHAR *Psource,UCHAR *Ptarget)//~v5jeR~
{                                                                  //~v5jeI~
    UCHAR sfullpath[DSN_MAXLEN],tfullpath[_MAX_PATH];              //~v5jeI~
    UCHAR lastname[DSN_MAXLEN];                                    //~v5jeI~
    FILEFINDBUF3 fstat3s;                                          //~v5jeI~
    FILEFINDBUF3 fstat3t;                                          //~v5jeI~
    int tpathlen,trootsw,filectr;                                  //~v5jeR~
    int twild;                                                     //~v5jeI~
    int flags;                                                     //~v5jeI~
    int rc,membsw;                                                 //~v5jeR~
    WCPARMTSOFTP wccopy;                                           //~v5jeR~
    PUDIRLIST  *ppudl=0;                                           //~v5jeI~
//********************                                             //~v5jeI~
    if (WILDCARD(Ptarget))                                         //~v5jeI~
        twild=1;                                                   //~v5jeI~
    else                                                           //~v5jeI~
        twild=0;                                                   //~v5jeI~
    if (!u3270fullpath(Ppuftphs,sfullpath,Psource,DSN_MAXLEN))     //~v5jeI~
        return -1;                                                 //~v5jeI~
    if (!ufullpath(tfullpath,Ptarget,_MAX_PATH))                   //~v5jeI~
        return -1;                                                 //~v5jeI~
	membsw=MEMBOFDSN(sfullpath)!=0;                                //~v5jeI~
    if (Popt & DCPY_MOVE && !membsw)	//move                     //~v5jeI~
    {                                                              //~v5jeI~
    	uerrmsg("TSO DataSet Delete is not supported,specify (wildcard) member",//~v5jeI~
        		"TSOでDataSet削除は出来ません,(ワイルドカード)メンバー指定してください");//~v5jeR~
        return -1;                                                 //~v5jeI~
    }                                                              //~v5jeI~
    trootsw=ROOTDIR2(tfullpath);                                   //~v5jeI~
    if (u3270findfile(0,Ppuftphs,sfullpath,&fstat3s,0)) 	//0:not noerrmsg for not found,0:no entryno output//~v5jeI~
     	return -1;                                                 //~v5jeI~
//  Sr2rsrcattrs=fstat3s.attrFile;                                 //~v5jeR~//~v6D0R~
    Sr2rsrcattrs=(int)fstat3s.attrFile;                            //~v6D0I~
    if (Popt & DCPY_CREATE                                         //~v5jeR~
    ||  ((Popt & DCPY_MOVE && !(Popt & DCPY_R2R))&&(fstat3s.attrFile & FILE_DIRECTORY)))//~v5jeR~
    {                                                              //~v5jeI~
	   	if (u3270filecreateparmproc(Ppuftphs,sfullpath,fstat3s.attrFile,0,tfullpath,&trootsw))//~v5jeR~
        	return -1;                                             //~v5jeI~
    }                                                              //~v5jeI~
//set parm flags                                                   //~v5jeI~
    flags=u3270filecpymvflags(twild,trootsw,0,tfullpath,&fstat3t); //~v5jeR~
    if (flags & (CPYMV_TPATHERR|CPYMV_OTHERERR))                   //~v5jeR~
    	return -1;                                                 //~v5jeI~
    tpathlen=(int)strlen(tfullpath);                               //~v5jeI~
    if (UCBITCHK(fstat3s.attrFile,FILE_DIRECTORY))//source dir     //~v5jeI~
        if (!WILDCARD(sfullpath))   //source not wild card         //~v5jeI~
    		u3270concatfilename(U3CF_FORCEASMEMBERIFNOTWILD,sfullpath,DIR_ALLMEMB,sfullpath);//~v5jeR~
    Popt=Popt & ~DCPY_ROOT;                                        //~v5jeI~
    if (!(Popt & DCPY_APPEND))            //not append req         //~v5jeI~
        if (flags & CPYMV_TFILE)          //target file            //~v5jeI~
            if (WILDCARD(sfullpath)         //source wild card     //~v5jeI~
            ||  UCBITCHK(fstat3s.attrFile,FILE_DIRECTORY))//source dir//~v5jeI~
                return ufileerrdirandfile(Psource,Ptarget);        //~v5jeI~
    if (DSNWILDCARD(sfullpath))         //source wild card         //~v5jeI~
    {                                                              //~v5jeI~
       if (Popt & DCPY_APPEND)            //append req             //~v5jeI~
       {                                                           //~v5jeI~
            if (flags & CPYMV_TDIR) //target is root               //~v5jeI~
                *(tfullpath+tpathlen++)=DIR_SEPC;                  //~v5jeI~
       }                                                           //~v5jeI~
       else                                                        //~v5jeI~
        if (!trootsw)   //target is not root                       //~v5jeI~
        {                                                          //~v5jeI~
            if (flags & CPYMV_TNEW) //not found                    //~v5jeI~
            {                                                      //~v5jeI~
                if (umkdir(tfullpath))                             //~v5jeI~
                    return -1;                                     //~v5jeI~
                flags=CPYMV_TDIR;                                  //~v5jeI~
            }                                                      //~v5jeI~
          if (flags & CPYMV_TDIR) //target is dir                  //~v5jeI~
            *(tfullpath+tpathlen++)=DIR_SEPC;                      //~v5jeI~
        }                                                          //~v5jeI~
        wccopy.wctfullpath  =tfullpath;                            //~v5jeI~
        wccopy.wcopt        =Popt;                                 //~v5jeI~
        wccopy.wcattrmask   =0;                                    //~v5jeR~
        wccopy.wctpathlen   =tpathlen;                             //~v5jeI~
        wccopy.wcflag       =flags;                                //~v5jeI~
    	wccopy.wcskipctr    =0;                                    //~v5jeI~
    	wccopy.wccopyctr    =0;                                    //~v5jeI~
	    memcpy(&wccopy.wcpfstat3s,&fstat3s,sizeof(fstat3s)); //dataset fstat for EBC conversion lrecl//~v5mBI~
        filectr=0;  //for compile warning                          //~v5jeI~
//      if ((Popt & DCPY_MOVE) && (Popt & DCPY_R2R))               //~v5jyR~
        if ((Popt & DCPY_R2R))                                     //~v5jyI~
        	ppudl=&Sr2rpudl;    //delete after r2r copy end        //~v5jeI~
        rc=u3270wildfunc(Ppuftphs,sfullpath,u3270filewildcopyget,&wccopy,&filectr,ppudl);//~v5jeR~
        Sr2rfilectr=filectr;                                       //~v5jeR~
		Sr2rskipctr=wccopy.wcskipctr;                              //~v5jeI~
        if (!rc)                                                   //~v5jeI~
        {                                                          //~v5jeI~
        	if (wccopy.wcskipctr)                                  //~v5jeI~
            {                                                      //~v5jeI~
            	uerrmsg("%d/%d member skipped by InvalidMemberName or AlreadyExist",0,//~v5jeR~
                		wccopy.wcskipctr,wccopy.wccopyctr+wccopy.wcskipctr);//~v5jeI~
                rc=DCPY_RC_NOTCOPY;                                //~v5jeR~
            }                                                      //~v5jeI~
            else                                                   //~v5jeI~
	        	uerrmsg("%d files are copied.",0,                  //~v5jeR~
    	        		wccopy.wccopyctr);                         //~v5jeR~
        }                                                          //~v5jeI~
        return rc;                                                 //~v5jeI~
    }                                                              //~v5jeI~
//not wild card nor PDS                                            //~v5jeI~
    if (!membsw)    //source is SEQ DS                             //~v5jeI~
        u3270parentdsn(U3PL_DROPMEMBER|U3PD_DROPQUOTE,sfullpath+Ppuftphs->UFTPHhostnmlen+1,lastname);//get dsn//~v5jeI~
    else                                                           //~v5jeI~
        u3270getlastname(0,sfullpath,lastname);                    //~v5jeI~
    if (twild)      //target is wild card                          //~v5jeI~
        ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,         //~v5jeI~
						lastname,tfullpath,tfullpath);    //determin target//~v5jeI~
    else                                                           //~v5jeI~
    if (trootsw)                                                   //~v5jeI~
#ifdef UNX                                                         //~v5jeI~
	  if (ROOTDIR(tfullpath))                                      //~v5jeI~
      	strcpy(tfullpath+1,lastname);                              //~v5jeI~
      else                                                         //~v5jeI~
#endif                                                             //~v5jeI~
        strcpy(tfullpath+3,lastname);                              //~v5jeI~
    else                    //target is not root                   //~v5jeI~
        if (flags & CPYMV_TDIR) //target is dir                    //~v5jeI~
        {                                                          //~v5jeI~
            *(tfullpath+tpathlen++)=DIR_SEPC;                      //~v5jeI~
            strcpy(tfullpath+tpathlen,lastname);                   //~v5jeI~
        }                                                          //~v5jeI~
//  rc=u3270copysubget(Popt|DCPY_NOSKIPMSG,Ppuftphs,sfullpath,tfullpath);//~v5mBR~
    rc=u3270copysubget(Popt|DCPY_NOSKIPMSG,Ppuftphs,sfullpath,tfullpath,&fstat3s);//~v5mBI~
    if (Popt & DCPY_MOVE)   //set id of target is dir for dlcmd3   //~v5jeI~
    {                                                              //~v5jeI~
    	if (Popt & DCPY_R2R)   //target is temp dir                //~v5jeR~
        	strcpy(Sr2rsinglemember,sfullpath);	//member to be deleted delete//~v5jeI~
        else            //target is local                          //~v5jeI~
    	{                                                          //~v5jeR~
    		if (!trootsw                                           //~v5jeR~
        	&&  flags & CPYMV_TDIR) //target is dir                //~v5jeR~
        		strcat(Ptarget,DIR_SEPS);   //sign of dir          //~v5jeR~
    	}                                                          //~v5jeR~
    }                                                              //~v5jeI~
    if (Popt & DCPY_R2R)   //target is temp dir                    //~v5jyI~
    	memcpy(&Sr2rsinglememberfstat,&fstat3s,sizeof(fstat3s));//r2r source fstat//~v5jyR~
    return rc;                                                     //~v5jeI~
}//u3270xcopyget                                                   //~v5mBR~
//**************************************************************** //~v5jeI~
//uxcopyput                                                        //~v5jeI~
//**************************************************************** //~v5jeI~
int u3270xcopyput(int Popt,PUFTPHOST Ppuftpht,UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask)//~v5jeR~
{                                                                  //~v5jeI~
//  UCHAR sfullpath[_MAX_PATH],tfullpath[DSN_MAXLEN];              //~v5jeR~//~v6H1R~
    UCHAR sfullpath[_MAX_PATH2],tfullpath[DSN_MAXLEN];             //~v6H1R~
    UCHAR tdsn[DSN_MAXLEN];                                        //~v5jeI~
    FILEFINDBUF3 fstat3s={0};                                          //~v5jeI~//~v6h7R~
    FILEFINDBUF3 fstat3t;                                          //~v5jeI~
    PUDIRLIST pudl;                                                //~v5jeI~
    int trootsw,spathlen,filectr;                                  //~v5jeR~
    int twild;                                                     //~v5jeI~
    int flags;                                                     //~v5jeI~
    int rc,membsw;                                                 //~v5jeR~
    WCPARMTSOFTP wccopy;                                           //~v5jeR~
//********************                                             //~v5jeI~
    Pattrmask=Pattrmask & (FILE_ALL-FILE_DIRECTORY);     //drop directory process bit//~v5jeR~
    membsw=MEMBOFDSN(Ptarget)!=0;                                  //~v5jeI~
    if (DSNWILDCARD(Ptarget))                                      //~v5jeI~
    {                                                              //~v5jeI~
    	if (!membsw)                                               //~v5jeI~
			return uerrnotsupported("Upload","TSO DataSet(Wildcard)",U3CR_RC_NOTSUPPORT);//~v5jeR~
        twild=1;                                                   //~v5jeI~
    }                                                              //~v5jeI~
    else                                                           //~v5jeI~
        twild=0;                                                   //~v5jeI~
    if (!ufullpath(sfullpath,Psource,_MAX_PATH))                   //~v5jeI~
        return -1;                                                 //~v5jeI~
    if (!u3270fullpath(Ppuftpht,tfullpath,Ptarget,DSN_MAXLEN))     //~v5jeR~
        return -1;                                                 //~v5jeI~
//*avoid source root case for successfull dosfindfirst             //~v5jeI~
    trootsw=0;                                                     //~v5jeI~
    spathlen=PATHLEN(sfullpath);                                   //~v5jeI~
    if (!ROOTDIR2(sfullpath)) //dosfindfirst faile if root         //~v5jeI~
    	if (udosfindfirst(sfullpath,0,Pattrmask|FILE_DIRECTORY,&fstat3s))//~v5jeI~
     		return -1;                                             //~v5jeI~
    if (Popt & DCPY_CREATE)                                        //~v5jeI~
    {                                                              //~v5jeI~
	   	if (u3270filecreateparmproc(0,sfullpath,fstat3s.attrFile,Ppuftpht,tfullpath,&trootsw))//~v5jeR~
        	return -1;                                             //~v5jeI~
    }                                                              //~v5jeI~
    if (Popt & DCPY_MOVE)                                          //~v5jeI~
    {                                                              //~v5jeI~
	   	if (fstat3s.attrFile & FILE_DIRECTORY)                     //~v5jeI~
        {                                                          //~v5jeI~
        	uerrmsg("Directoy Move is not supported when target is TSO",//~v5jeI~
            	    "宛先がTSOのときDirectory移動は出来ません。"); //~v5jeI~
        	return -1;                                             //~v5jeI~
        }                                                          //~v5jeI~
    }                                                              //~v5jeI~
//set parm flags                                                   //~v5jeI~
    flags=u3270filecpymvflags(twild,trootsw,Ppuftpht,tfullpath,&fstat3t);//~v5jeR~
    if (flags & (CPYMV_TPATHERR|CPYMV_OTHERERR))                   //~v5jeI~
    	return -1;                                                 //~v5jeI~
    if (ROOTDIR2(sfullpath)) //dosfindfirst faile if root          //~v5jeI~
    	return ufileroot(sfullpath,4);                             //~v5jeR~
    else                                                           //~v5jeI~
    {                                                              //~v5jeI~
//*source exist chk for not found err apirc of target              //~v5jeI~
        if (UCBITCHK(fstat3s.attrFile,FILE_DIRECTORY))//source dir //~v5jeI~
        {                                                          //~v5jeI~
            if (!WILDCARD(sfullpath))   //source not wild card     //~v5jeI~
            {                                                      //~v5jeI~
            	strcat(sfullpath,DIR_SEPS DIR_ALLMEMB);            //~v5jeI~
            	spathlen=PATHLEN(sfullpath);                       //~v5jeI~
            }                                                      //~v5jeI~
        }//src is dir                                              //~v5jeI~
    }                                                              //~v5jeI~
                                                                   //~v5jeI~
    if (!(Popt & DCPY_APPEND))            //not append req         //~v5jeI~
        if (flags & (CPYMV_TFILE|CPYMV_TNEW))          //target file//~v5jeR~
            if (WILDCARD(sfullpath)         //source wild card     //~v5jeI~
            ||  UCBITCHK(fstat3s.attrFile,FILE_DIRECTORY))//source dir//~v5jeI~
                return ufileerrdirandfile(Psource,Ptarget);        //~v5jeI~
    if (WILDCARD(sfullpath))         //source wild card or directory//~v5jeR~
    {                                                              //~v5jeI~
    	pudl=0;                                                    //~v5jeR~
		if ((Popt & DCPY_APPEND)||!(Popt & DCPY_EXISTING))	//target member existance chk required case//~v5jeI~
        {                                                          //~v5jeI~
    		if (flags & (CPYMV_TWILD))	//target wild              //~v5jkM~
				if (u3270srcdupchk(sfullpath,Pattrmask,tfullpath)) //~v5jkM~
	        		return 4;                                      //~v5jkM~
        }                                                          //~v5jyI~
		if ((Popt & DCPY_APPEND)||!(Popt & DCPY_EXISTING) 	//target member existance chk required case//~v5jyI~
        ||  (fstat3t.attrFile & FILE_SPFDS))                //target may contain spf info//~v5jyI~
        {                                                          //~v5jyI~
			u3270parentdsn(U3PL_DROPMEMBER,tfullpath,tdsn);        //~v5jeI~
			rc=u3270dirlistsub(Ppuftpht,0,&filectr,tdsn,0,&pudl);  //~v5jeR~
		    if (rc)  //err                                         //~v5jeI~
        		return 4;                                          //~v5jeI~
	    	wccopy.wcpudlctr=filectr;	//performance up to chk exist already//~v5jeI~
        }                                                          //~v5jeI~
        wccopy.wctfullpath  =tfullpath;                            //~v5jeI~
        wccopy.wcopt        =Popt;                                 //~v5jeR~
        wccopy.wcattrmask   =Pattrmask;                            //~v5jeI~
        wccopy.wctpathlen   =0;                                    //~v5jeR~
        wccopy.wcflag       =flags;                                //~v5jeI~
    	wccopy.wcpuftph     =Ppuftpht;                             //~v5jeR~
    	wccopy.wcskipctr    =0;                                    //~v5jeI~
    	wccopy.wccopyctr    =0;                                    //~v5jeI~
	    wccopy.wcpudl       =pudl;                                 //~v5jeR~
	    memcpy(&wccopy.wcpfstat3t,&fstat3t,sizeof(fstat3t)); //dataset fstat for spfupdate//~v5jyI~
        rc=uwildfunc(0,         //bypass ea data                   //~v5jeR~
                    sfullpath,Pattrmask,u3270filewildcopyput,&wccopy,&filectr);//~v5jeI~
	    if (pudl)                                                  //~v5jeR~
//  		ufree(pudl);                                           //~v5jeR~//~v6qaR~
    		UDIRLIST_FREE(pudl);                                   //~v6qaI~
        if (!rc)                                                   //~v5jeI~
        {                                                          //~v5jeI~
        	if (wccopy.wcskipctr)                                  //~v5jeI~
            {                                                      //~v5jeI~
            	uerrmsg("%d/%d member skipped by InvalidMemberName or AlreadyExist",0,//~v5jeR~
                	wccopy.wcskipctr,wccopy.wccopyctr+wccopy.wcskipctr);//~v5jeR~
                rc=DCPY_RC_NOTCOPY;                                //~v5jeR~
            }                                                      //~v5jeI~
            else                                                   //~v5jeI~
        		uerrmsg("%d files are copied.",0,                  //~v5jeI~
            			wccopy.wccopyctr);                         //~v5jeI~
        }                                                          //~v5jeI~
        return rc;                                                 //~v5jeI~
    }                                                              //~v5jeI~
//  if (!(flags & (CPYMV_TDIR|CPYMV_TMEMBER|CPYMV_TNEW))) //target is bot dir//~v5jxR~
//  	return uerrnotsupported("Upload","TSO Sequencial DataSet",U3CR_RC_NOTSUPPORT);//~v5jxR~
//not wild card                                                    //~v5jeI~
    if (flags & CPYMV_TDIR) //target is bot dir                    //~v5jeI~
    {                                                              //~v5jeI~
        u3270concatfilename(U3CF_FORCEASMEMBERIFNOTWILD,tfullpath,sfullpath+spathlen,tfullpath);    //determin target//~v5jeR~
		flags|=CPYMV_CHKMEMB;     //replace chk to be done for this member//~v5jeI~
    }                                                              //~v5jeI~
    else                                                           //~v5jeI~
    if (twild)      //target is wild card                          //~v5jeI~
    {                                                              //~v5jeI~
        u3270editname(Ppuftpht,U3EN_WILDSOURCE,tfullpath,sfullpath+spathlen,tfullpath);    //determin target//~v5jeR~
		flags|=CPYMV_CHKMEMB;     //replace chk to be done for this member//~v5jeI~
    }                                                              //~v5jeI~
//  rc=u3270copysubput(Popt|DCPY_NOSKIPMSG,Ppuftpht,sfullpath,tfullpath,flags);//~v5jyR~
    rc=u3270copysubput(Popt|DCPY_NOSKIPMSG,Ppuftpht,sfullpath,tfullpath,flags,&Sr2rsinglememberfstat,&fstat3t);//~v5jyI~
    return rc;                                                     //~v5jeI~
}//u3270xcopyput                                                   //~v5jeI~
//**************************************************************** //~v5cdI~
//!ufilecreateparmproc                                             //~v5cdI~
//* insert src dirname into target path                            //~v5cdI~
//* and mkdir if the dir is not found                              //~v5cdI~
//*retrn:rc                                                        //~v5cdR~
//**************************************************************** //~v5cdI~
int u3270filecreateparmproc(PUFTPHOST Ppuftphs,char *Psfullpath,ULONG Psattr,//~v5jeR~
							PUFTPHOST Ppuftpht,char *Ptfullpath,int *Pptrootsw)//~v5jeI~
{                                                                  //~v5cdI~
    FILEFINDBUF3 fstat3t;                                          //~v5cdR~
    UCHAR srcdir[_MAX_PATH],tgtdir[_MAX_PATH];                     //~v5cdM~
	int tpathlen,twildsw=0;                                        //~v5jeR~
//*********************                                            //~v5cdI~
    if (Ppuftpht)                                                  //~v5jeR~
    {                                                              //~v5jeI~
        uerrmsg("Create option is invalid when target is TSO",     //~v5jeI~
                "宛先がTSOのときCreteオプションは使えません。");   //~v5jeI~
        return 4;                                                  //~v5jeI~
    }                                                              //~v5jeI~
    if (Psattr & FILE_DIRECTORY)//source is dir                    //~v5jeR~
		u3270parentdsn(U3PL_DROPMEMBER|U3PD_DROPQUOTE,Psfullpath+Ppuftphs->UFTPHhostnmlen+1,srcdir);	//drop lastname//~v5jeI~
    else                                                           //~v5jeI~
		u3270parentdsn(U3PL_PARENTORDROPMEMBER|U3PD_DROPQUOTE,Psfullpath+Ppuftphs->UFTPHhostnmlen+1,srcdir);	//drop lastname//~v5jeR~
//target is local for CREATE option                                //~v5jeI~
    tpathlen=PATHLEN(Ptfullpath);                                  //~v5cdR~
    if (WILDCARD(Ptfullpath))        //target wild card            //~v5cdR~
    {                                                              //~v5cdR~
        memcpy(tgtdir,Ptfullpath,(UINT)tpathlen);                  //~v5jeR~
        strcpy(tgtdir+tpathlen,srcdir);                            //~v5jeR~
        twildsw=1;                                                 //~v5cdR~
    }                                                              //~v5cdR~
    else                                                           //~v5cdR~
    {                                                              //~v5cdR~
        strcpy(tgtdir,Ptfullpath);                                 //~v5cdR~
        if (!*Pptrootsw)                                           //~v5jeR~
        	strcat(tgtdir,DIR_SEPS);                               //~v5jeI~
        strcat(tgtdir,srcdir);                                     //~v5jeR~
    }                                                              //~v5cdR~
    if (ufstat(tgtdir,&fstat3t)) //not found                       //~v5cdR~
        if (umkdir(tgtdir))                                        //~v5cdR~
            return -1;                                             //~v5cdR~
    if (twildsw)                                                   //~v5cdR~
        strcat(tgtdir,Ptfullpath+tpathlen-1);                      //~v5cdR~
    strcpy(Ptfullpath,tgtdir);                                     //~v5cdR~
    *Pptrootsw=0;   //no more root                                 //~v5cdR~
    return 0;                                                      //~v5cdI~
}//u3270filecreateparmproc                                         //~v5jeR~
//**************************************************************** //~v291I~
//!u3270filecpymvflags                                             //~v5jeR~
//* set copy/move flags                                            //~v291I~
//*parm1:target wild card sw                                       //~v291I~
//*parm2:target rootsw                                             //~v291I~
//*parm3:target pathname                                           //~v291I~
//*retrn:flags                                                     //~v291I~
//**************************************************************** //~v291I~
int u3270filecpymvflags(int Ptwild,int Ptrootsw,PUFTPHOST Ppuftpht,char *Ptfullpath,FILEFINDBUF3 *Ppfstat3t)//~v5jeR~
{                                                                  //~v291I~
    int flags;                                                     //~v291I~
    int pathlen,rc;                                                //~v5cdR~
    UCHAR fpath[_MAX_PATH];                                        //~v5cdI~
    UCHAR  membname[DSN_MAXMEMBERNAMELEN+1];                       //~v5jeI~
//*****************                                                //~v291I~
  if (Ppuftpht)	//target is TSO                                    //~v5jeI~
  {                                                                //~v5jeI~
    if (Ptwild)                                                    //~v5jeI~
    {                                                              //~v5jeI~
    	if (u3270getmembname(U3GM_RETLENERR,Ptfullpath,membname)<0 //~v5jeR~
    	||  (*membname && u3270chkmembname(U3CM_CHKWILD,membname)>1))//~v5jeI~
        {                                                          //~v5jeI~
		    uerrmsg("%s has invalid membername",0,                 //~v5jeI~
        		    		Ptfullpath);                           //~v5jeI~
        	flags=CPYMV_OTHERERR;                                  //~v5jeI~
        }                                                          //~v5jeI~
        else                                                       //~v5jeI~
        {                                                          //~v5jeI~
            u3270parentdsn(U3PL_PARENTORDROPMEMBER,Ptfullpath,fpath);//~v5jeR~
//          if (rc=u3270fstat(Ppuftpht,fpath,Ppfstat3t),rc) //not found//~v5jeR~//~v6D0R~
            if (rc=(int)u3270fstat(Ppuftpht,fpath,Ppfstat3t),rc) //not found//~v6D0I~
            {                                                      //~v5jeR~
                if (rc==ERROR_PATH_NOT_FOUND)                      //~v5jeR~
                {                                                  //~v5jeR~
                    ufilepatherr(Ptfullpath,4);                    //~v5jeR~
                    flags=CPYMV_TPATHERR;                          //~v5jeR~
                }                                                  //~v5jeR~
                else                                               //~v5jeR~
                    flags=CPYMV_OTHERERR;                          //~v5jeR~
            }                                                      //~v5jeR~
            else                                                   //~v5jeR~
            {                                                      //~v5jeR~
                flags=CPYMV_TWILD;                                 //~v5jeR~
                if (MEMBOFDSN(Ptfullpath))                         //~v5jeR~
                    flags|=CPYMV_TMEMBER;                          //~v5jeR~
            }                                                      //~v5jeR~
        }                                                          //~v5jeI~
    }                                                              //~v5jeI~
    else                                                           //~v5jeI~
//  	if (rc=u3270fstat(Ppuftpht,Ptfullpath,Ppfstat3t),rc) //not found//~v5jeI~//~v6D0R~
    	if (rc=(int)u3270fstat(Ppuftpht,Ptfullpath,Ppfstat3t),rc) //not found//~v6D0I~
    	{                                                          //~v5jeI~
      		if (rc==ERROR_PATH_NOT_FOUND)                          //~v5jeI~
      		{                                                      //~v5jeI~
      			ufilepatherr(Ptfullpath,4);                        //~v5jeI~
        		flags=CPYMV_TPATHERR;                              //~v5jeI~
      		}                                                      //~v5jeI~
      		else                                                   //~v5jeI~
      		if (rc==ERROR_FILE_NOT_FOUND)                          //~v5jeI~
            {                                                      //~v5jeI~
                if (MEMBOFDSN(Ptfullpath)==0)   //no member specification//~v5jeI~
                {                                                  //~v5jeI~
        			ufilenotfound(Ptfullpath,4);                   //~v5jeR~
	        		flags=CPYMV_TPATHERR;                          //~v5jeI~
                }                                                  //~v5jeI~
                else                                               //~v5jeI~
	        		flags=CPYMV_TNEW;                              //~v5jeR~
            }                                                      //~v5jeI~
            else                                                   //~v5jeI~
	        	flags=CPYMV_OTHERERR;                              //~v5jeI~
    	}                                                          //~v5jeI~
    	else                                                       //~v5jeR~
    		if (UCBITCHK(Ppfstat3t->attrFile,FILE_DIRECTORY))//target dir//~v5jeR~
        		flags=CPYMV_TDIR;                                  //~v5jeR~
    		else                                                   //~v5jeR~
            {                                                      //~v5jeI~
        		flags=CPYMV_TFILE;                                 //~v5jeR~
    			if (Ppfstat3t->attrFile & FILE_PDSMEMB)//target dir//~v5jeM~
	        		flags|=CPYMV_TMEMBER;                          //~v5jeR~
            }                                                      //~v5jeI~
  }                                                                //~v5jeI~
  else//target is local                                            //~v5jeI~
  {                                                                //~v5jeI~
    if (Ptwild)                                                    //~v291I~
    {                                                              //~v5cdI~
        strcpy(fpath,Ptfullpath);                                  //~v5cdI~
        pathlen=PATHLEN(Ptfullpath);                               //~v5cdI~
        *(fpath+pathlen)=0;                                        //~v5cdR~
	 if (ROOTDIR2(fpath))                                          //~v5cdI~
        flags=CPYMV_TWILD;                                         //~v5cdI~
     else                                                          //~v5cdI~
     {                                                             //~v5cdI~
        *(fpath+pathlen-1)=0;                                      //~v5cdI~
	  if (ufstat(fpath,Ppfstat3t)) //not found                     //~v5cdR~
      {                                                            //~v5cdI~
      	ufilepatherr(Ptfullpath,4);                                //~v5cdI~
        flags=CPYMV_TPATHERR;                                      //~v5cdR~
      }                                                            //~v5cdI~
      else                                                         //~v5cdI~
        flags=CPYMV_TWILD;                                         //~v291I~
     }                                                             //~v5cdI~
    }                                                              //~v5cdI~
    else                                                           //~v291I~
    if (Ptrootsw)                                                  //~v291I~
        flags=CPYMV_TROOT;                                         //~v291I~
    else                                                           //~v291I~
    if (rc=(int)ufstat(Ptfullpath,Ppfstat3t),rc) //not found       //~v5e1R~
    {                                                              //~v5cdI~
      if (rc==ERROR_PATH_NOT_FOUND)                                //~v5cdI~
      {                                                            //~v5cdI~
      	ufilepatherr(Ptfullpath,4);                                //~v5cdI~
        flags=CPYMV_TPATHERR;                                      //~v5cdI~
      }                                                            //~v5cdI~
      else                                                         //~v5cdI~
        flags=CPYMV_TNEW;                                          //~v291I~
    }                                                              //~v5cdI~
    else                                                           //~v291I~
    if (UCBITCHK(Ppfstat3t->attrFile,FILE_DIRECTORY))//target dir  //~v291I~
        flags=CPYMV_TDIR;                                          //~v291I~
    else                                                           //~v291I~
        flags=CPYMV_TFILE;                                         //~v291I~
  }//target is local                                               //~v5jeI~
    return flags;                                                  //~v291I~
}//u3270filecpymvflags                                             //~v5jeR~
//****************************************************************//~5910I~
//!u3270wildcopyget                                                //~v5jeR~
//* download by wild card                                          //~v5jeR~
//*parm1:filename thru wildfunc                                 //~5916I~
//*parm2:dirlist ptr thru wildfunc                              //~5916I~
//*parm3:parm thru uwildfunc(ucopy parameter structure)         //~5916I~
//*retrn:rc                                                     //~5916I~
//****************************************************************//~5910I~
int u3270filewildcopyget(PUFTPHOST Ppuftph,UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm)//~v5jeR~
{                                                               //~5910I~
    WCPARMTSOFTP *pwccopy;                                         //~v5jeR~
    UCHAR      *ptarget,wktarget[_MAX_PATH];                       //~v280I~
    UCHAR      lastname[DSN_MAXLEN];                               //~v5jeI~
    int rc;                                                        //~v5e1I~
//********************                                          //~5910I~
    if (MEMBOFDSN(Pfullpath))    //source is SEQ DS                //~v5jeI~
        strcpy(lastname,Ppudirlist->name);                         //~v5jeR~
    else                                                           //~v5jeI~
        u3270parentdsn(U3PL_DROPMEMBER|U3PD_DROPQUOTE,Pfullpath+Ppuftph->UFTPHhostnmlen+1,lastname);//get dsn//~v5jeI~
    pwccopy=Pparm;                                              //~5916I~
    if (pwccopy->wcflag & CPYMV_TWILD)      //target is wild card  //~v291I~
    {                                                              //~v280I~
        ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,         //~v5jeI~
						lastname,pwccopy->wctfullpath,wktarget);   //~v5jeR~
        ptarget=wktarget;                                          //~v280I~
    }                                                              //~v280I~
    else                                                           //~v280I~
    {                                                              //~v280I~
        if (pwccopy->wcflag & (CPYMV_TROOT|CPYMV_TDIR)) //target is root or dir//~v291R~
    		strcpy(pwccopy->wctfullpath+pwccopy->wctpathlen,lastname);//~v5jeR~
        ptarget=pwccopy->wctfullpath;                              //~v280I~
    }                                                              //~v280I~
//  rc=u3270copysubget(pwccopy->wcopt,Ppuftph,Pfullpath,ptarget);  //~v5mBR~
    rc=u3270copysubget(pwccopy->wcopt,Ppuftph,Pfullpath,ptarget,&pwccopy->wcpfstat3s);//~v5mBI~
    if (!rc)                                                       //~v5jeI~
    {                                                              //~v5jeI~
    	pwccopy->wccopyctr++;                                      //~v5jeI~
        Ppudirlist->attr|=R2R_GET;                                 //~v5jeI~
    }                                                              //~v5jeI~
    else                                                           //~v5jeI~
	if (rc==U3CR_RC_INVALIDNAME                                    //~v5jeR~
    ||  rc==DCPY_RC_NOTCOPY)    //copy bypass by timestamp option  //~v5jeI~
    {                                                              //~v5jeI~
        pwccopy->wcskipctr++;                                      //~v5jeI~
        rc=0;                                                      //~v5jeI~
    }                                                              //~v5jeI~
    return rc;                                                     //~v5e1I~
}//u3270filewildcopyget                                            //~v5jeR~
//**************************************************************** //~v5jeI~
//!u3270wildcopyput                                                //~v5jeI~
//* copy by wild card                                              //~v5jeI~
//*parm1:filename thru wildfunc                                    //~v5jeI~
//*parm2:dirlist ptr thru wildfunc                                 //~v5jeI~
//*parm3:parm thru uwildfunc(ucopy parameter structure)            //~v5jeI~
//*retrn:rc                                                        //~v5jeI~
//**************************************************************** //~v5jeI~
int u3270filewildcopyput(UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm)//~v5jeR~
{                                                                  //~v5jeI~
	PUFTPHOST puftph;                                              //~v5jeI~
    WCPARMTSOFTP *pwccopy;                                         //~v5jeR~
    UCHAR      *ptarget,wktarget[_MAX_PATH],member[DSN_MAXMEMBERNAMELEN+1];//~v5jeR~
    PUDIRLIST pudl,pudlget=NULL;                                        //~v5jeR~//~v6h7R~
    int rc,flags;                                                  //~v5jeR~
    FILEFINDBUF3 fstat3s,fstat3t,*pfstat3t;                        //~v5jyR~
//********************                                             //~v5jeI~
    pwccopy=Pparm;                                                 //~v5jeI~
    puftph=pwccopy->wcpuftph;                                      //~v5jeR~
    if (pwccopy->wcflag & CPYMV_TWILD)      //target is wild card  //~v5jeI~
        u3270editname(puftph,U3EN_WILDSOURCE,pwccopy->wctfullpath,Ppudirlist->name,wktarget);    //determin target//~v5jeR~
    else                                                           //~v5jeI~
     	u3270concatfilename(U3CF_FORCEASMEMBERIFNOTWILD,pwccopy->wctfullpath,Ppudirlist->name,wktarget);//~v5jeR~
    ptarget=wktarget;                                              //~v5jeI~
//chk member exist                                                 //~v5jeI~
	pudl=pwccopy->wcpudl;	//performance up to chk exist already  //~v5jeI~
    flags=pwccopy->wcflag;                                         //~v5jeI~
	pfstat3t=&pwccopy->wcpfstat3t;                                 //~v5jyI~
    if (pudl)                                                      //~v5jeI~
    {                                                              //~v5jeI~
    	if (u3270getmembname(U3GM_RETLENERR,ptarget,member)<0)     //~v5jkI~
        {                                                          //~v5jkI~
    		pwccopy->wcskipctr++;                                  //~v5jkI~
        	return 0;   //continue process                         //~v5jkI~
        }                                                          //~v5jkI~
		pudl=u3270srchdirlist(0,pwccopy->wcpudlctr,pudl,member);   //~v5jeR~
        if (!pudl)                                                 //~v5jeI~
	    	flags|=CPYMV_TNEW;     //replace chk to be done for this member//~v5jeI~
        else                                                       //~v5jyI~
        {                                                          //~v5jyI~
        	uftpudl2ffb3(pudl,&fstat3t);	//wildcard matched target fstat for each member//~v5jyI~
            pfstat3t=&fstat3t;                                     //~v5jyI~
        }                                                          //~v5jyI~
	}                                                              //~v5jeI~
    else                                                           //~v5jeI~
    	flags|=CPYMV_CHKMEMB;     //replace chk to be done for this member//~v5jeR~
    if (Sr2rpudl)	//move TSO to TSO                              //~v5jyI~
    {                                                              //~v5jyI~
		pudlget=u3270srchdirlist(0,Sr2rfilectr,Sr2rpudl,Ppudirlist->name);//~v5jyI~
        if (pudlget)                                               //~v5jyI~
			uftpudl2ffb3(pudlget,&fstat3s);         //r2r source fstat//~v5jyR~
        else                                                       //~v5jyI~
        	memset(&fstat3s,0,sizeof(fstat3s));                    //~v5jyI~
    }                                                              //~v5jyI~
    rc=u3270copysubput(pwccopy->wcopt,                             //~v5jeR~
    				puftph,                                        //~v5jeI~
					Pfullpath,                                     //~v5jeI~
                    ptarget,                                       //~v5jeI~
//                  flags);                                        //~v5jyR~
                    flags,                                         //~v5jyI~
					&fstat3s,pfstat3t);                            //~v5jyR~
    if (!rc)                                                       //~v5jeI~
    {                                                              //~v5jeI~
    	pwccopy->wccopyctr++;                                      //~v5jeI~
        if (Sr2rpudl)	//move TSO to TSO                          //~v5jeR~
        {                                                          //~v5jeI~
//  		pudlget=u3270srchdirlist(0,Sr2rfilectr,Sr2rpudl,Ppudirlist->name);//~v5jyR~
            if (pudlget)                                           //~v5jeR~
	        	pudlget->attr|=R2R_PUT;	//uploadedd flag,delete later//~v5jeI~
        }                                                          //~v5jeI~
    }                                                              //~v5jeI~
    else                                                           //~v5jeI~
	if (rc==U3CR_RC_INVALIDNAME                                    //~v5jeR~
    ||  rc==DCPY_RC_NOTCOPY)    //copy bypass by timestamp option  //~v5jeI~
    {                                                              //~v5jeI~
    	pwccopy->wcskipctr++;                                      //~v5jeR~
        rc=0;   //continue process                                 //~v5jeI~
    }                                                              //~v5jeI~
    return rc;                                                     //~v5jeI~
}//u3270filewildcopyput                                            //~v5jeR~
//**************************************************************** //~v5jeI~
//u3270copysubget                                                  //~v5jeI~
//*retrn:rc                                                        //~v5jeI~
//**************************************************************** //~v5jeI~
//int u3270copysubget(int Popt,PUFTPHOST Ppuftph,UCHAR *Psource,UCHAR *Ptarget)//~v5mBR~
int u3270copysubget(int Popt,PUFTPHOST Ppuftph,UCHAR *Psource,UCHAR *Ptarget,FILEFINDBUF3 *Ppfstat3s)//~v5mBI~
{                                                                  //~v5jeI~
    int texistsw;                                                  //~v5jeR~
    FILEFINDBUF3 fstat3t;                                          //~v5jeI~
    int flags,rc;                                                  //~v5jeR~
    UTSOFTPPARM tsop;                                              //~v5mBR~
//********************                                             //~v5jeI~
    u3270setftpparm(0,Ppuftph,&tsop,Ppfstat3s);                    //~v5mBR~
    flags=u3270filecpymvflags(0,0,0,Ptarget,&fstat3t);   //not wild,root//~v5jeR~
    if (flags & (CPYMV_TPATHERR|CPYMV_OTHERERR))                   //~v5jeI~
     	return -1;                                                 //~v5jeR~
    texistsw=!(flags & CPYMV_TNEW); //target existsw               //~v5jeI~
    if (texistsw)                                                  //~v5jeR~
    {                                                              //~v5jeR~
        if (flags & CPYMV_TDIR)          //target file             //~v5jeM~
        {                                                          //~v5jeI~
            uerrmsg("%s(target of %s) already exists as directotry.",0,//~v5jeR~
            		Ptarget,Psource);                              //~v5jeI~
            return -1;                                             //~v5jeI~
        }                                                          //~v5jeI~
        if (!(Popt & DCPY_APPEND))            //append req         //~v5jeR~
        {                                                          //~v5jeI~
            if (!(Popt & DCPY_EXISTING))       //repl req          //~v5jeR~
            {                                                      //~v5jeI~
                if (Popt & DCPY_SKIPEXIST)       //skip override   //~v5jeR~
                    return DCPY_RC_NOTCOPY;                        //~v5jeR~
                else                                               //~v5jeR~
                    return ufileexistcopy(Ptarget,-1);             //~v5jeR~
            }                                                      //~v5jeI~
        }                                                          //~v5jeI~
    }                                                              //~v5jeR~
//  rc=u3270transfer(Popt,Ppuftph,0,Psource,Ptarget);              //~v5mBR~
    rc=u3270transfer(Popt,Ppuftph,0,Psource,Ptarget,&tsop);        //~v5mBR~
    if (!rc && (Popt &  DCPY_MOVE) && !(Popt & DCPY_R2R))          //~v5jeI~
    	rc=u3270remove(Ppuftph,UXDELNOMSG,Psource);                //~v5jeI~
    return rc;                                                     //~v5jeI~
}//u3270copysubget                                                 //~v5jeI~
//**************************************************************** //~v5jeI~
//u3270copysubput                                                  //~v5jyR~
//* copy file(also time stamp)                                     //~v5jeI~
//*parm1:source fullpath filename                                  //~v5jeI~
//*parm2:target fullpath filename                                  //~v5jeI~
//*parm3:option append/replace                                     //~v5jeI~
//*parm4:source selection file attr                                //~v5jeI~
//*parm5:source attr                                               //~v5jeI~
//*retrn:rc                                                        //~v5jeI~
//**************************************************************** //~v5jeI~
//int u3270copysubput(int Popt,PUFTPHOST Ppuftph,UCHAR *Psource,UCHAR *Ptarget,int Pflags)//~v5jyR~
int u3270copysubput(int Popt,PUFTPHOST Ppuftph,UCHAR *Psource,UCHAR *Ptarget,int Pflags,FILEFINDBUF3 *Ppfstat3s,FILEFINDBUF3 *Ppfstat3t)//~v5jyI~
{                                                                  //~v5jeI~
    int texistsw,rc,flags;                                         //~v5jeR~
    char tempfnm[_MAX_PATH];                                       //~v5jeI~
    FILEFINDBUF3 fstat3t;                                          //~v5jeI~
    FILEFINDBUF3 *pfstat3t;                                        //~v5jyI~
    UTSOFTPPARM tsop;                                              //~v5mBR~
//********************                                             //~v5jeI~
	pfstat3t=Ppfstat3t;                                            //~v5jyI~
    u3270setftpparm(0,Ppuftph,&tsop,Ppfstat3t);                    //~v5mBI~
	if (Pflags & CPYMV_CHKMEMB     //replace chk to be done for this member//~v5jeI~
    &&  ((Popt & DCPY_APPEND)||!(Popt & DCPY_EXISTING)))           //~v5jeR~
    {                                                              //~v5jeI~
    	flags=u3270filecpymvflags(0,0,Ppuftph,Ptarget,&fstat3t);   //not wild,root//~v5jeI~
	    if (flags & (CPYMV_TPATHERR|CPYMV_OTHERERR))               //~v5jeI~
        	return -1;                                             //~v5jeI~
        pfstat3t=&fstat3t;                                         //~v5jyR~
    }                                                              //~v5jeI~
    else                                                           //~v5jeI~
    	flags=Pflags;                                              //~v5jeI~
    texistsw=!(flags & CPYMV_TNEW); //target existsw               //~v5jeR~
    if (texistsw)                                                  //~v5jeR~
    {                                                              //~v5jeI~
        if ((Popt & DCPY_APPEND))                                  //~v5jeR~
        {                                                          //~v5jeI~
			utempnam("","u3270append",tempfnm);                    //~v5jeR~
            for (;;)                                               //~v5jeI~
            {                                                      //~v5jeI~
//  			if ((rc=u3270transfer(Popt,Ppuftph,0,Ptarget,tempfnm)))//~v5mBR~
    			if ((rc=u3270transfer(Popt,Ppuftph,0,Ptarget,tempfnm,&tsop)))//~v5mBR~
                	break;                                         //~v5jeI~
	        	if ((rc=uxcopy(Psource,tempfnm,DCPY_APPEND,FILE_NORMAL))) //append to now downloaded//~v5jeR~
                	break;                                         //~v5jeI~
//  			rc=u3270transfer(Popt,0,Ppuftph,tempfnm,Ptarget);    //repl//~v5mBR~
    			rc=u3270transfer(Popt,0,Ppuftph,tempfnm,Ptarget,&tsop);    //repl//~v5mBR~
			    if (!rc)                                           //~v5jyI~
					rc=u3270copyspfupdate(Popt,Ppuftph,Psource,Ptarget,flags,Ppfstat3s,pfstat3t);//~v5jyR~
                break;                                             //~v5jeI~
            }                                                      //~v5jeI~
            uremove(tempfnm);                                      //~v5jeI~
            return rc;                                             //~v5jeI~
        }                                                          //~v5jeI~
        else                                                       //~v5jeI~
        	if (!(Popt & DCPY_EXISTING))                           //~v5jeR~
            {                                                      //~v5jeI~
            	if (Popt & DCPY_SKIPEXIST)       //skip override   //~v5jeR~
    	       		return DCPY_RC_NOTCOPY;                        //~v5jeR~
            	else                                               //~v5jeR~
            		return ufileexistcopy(Ptarget,-1);             //~v5jeR~
            }                                                      //~v5jeI~
    }                                                              //~v5jeI~
//  rc=u3270transfer(Popt,0,Ppuftph,Psource,Ptarget);    //repl    //~v5mBR~
    rc=u3270transfer(Popt,0,Ppuftph,Psource,Ptarget,&tsop);    //repl//~v5mBR~
    if (!rc)                                                       //~v5jyI~
		rc=u3270copyspfupdate(Popt,Ppuftph,Psource,Ptarget,flags,Ppfstat3s,pfstat3t);//~v5jyR~
    if (!rc && (Popt & DCPY_MOVE)) //when r2r MOVE is off          //~v5jeR~
    	rc=uremovenomsg(Psource);                                  //~v5jeI~
    return rc;                                                     //~v5jeI~
}//u3270copysubput                                                 //~v5jeR~
                                                                   //~v5jeI~
//**************************************************************** //~v5jeI~
//u3270transfer                                                    //~v5jeR~
//**************************************************************** //~v5jeI~
int u3270transfer(int Popt,PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,  //~v5jeI~
//  		UCHAR *Psource,UCHAR *Ptarget)                         //~v5mBR~
    		UCHAR *Psource,UCHAR *Ptarget,PUTSOFTPPARM Pptsop)     //~v5mBI~
{                                                                  //~v5jeI~
	PUFTPHOST puftph;                                              //~v5jeI~
    int  rc;                                                       //~v5jeI~
    int  lrecl;                                                    //~v5mBI~
    char *pc,*phostfnm,*plocalfnm;                                 //~v5jeI~
    char *verb;                                                    //~v5mBI~
    char *pc2,*pc3;                                                //~v5mBR~
    char cmd[MAX_CMDSZ];                                           //~v5jeI~
    char pswd[FTP_PSWDNAMELEN+2];                                  //~v5jeI~
    char ftpopt[MAX_CMDSZ];                                        //~v5jeI~
    char membname[DSN_MAXMEMBERNAMELEN+1];                         //~v5jeR~
//********************                                             //~v5jeI~
    *ftpopt=0;                                                     //~v5jeI~
//  pc=cmd;                                                        //~v5mBR~
    if (Popt & DCPY_BIN)                                           //~v5jeI~
    	strcat(ftpopt," bin");                                     //~v5jeI~
  	if (Ppuftphs && Popt & DCPY_APPEND)   //download append mode   //~v5jeI~
    	strcat(ftpopt," app");              //for download         //~v5jeI~
	if (Ppuftphs)		//download                                 //~v5jeI~
    {                                                              //~v5jeI~
//    	strcpy(pc,"get");                                          //~v5mBR~
//	    pc+=3;                                                     //~v5mBR~
      	verb="get";                                                //~v5mBI~
        puftph=Ppuftphs;                                           //~v5jeI~
        phostfnm=Psource;                                          //~v5jeI~
        plocalfnm=Ptarget;                                         //~v5jeI~
        if (Popt & DCPY_EXISTING)                                  //~v5jeI~
        	strcat(ftpopt," rep");                                 //~v5jeI~
    }                                                              //~v5jeI~
    else                //upload                                   //~v5jeI~
    {                                                              //~v5jeI~
//  	strcpy(pc,"put");                                          //~v5mBR~
//      pc+=3;                                                     //~v5mBR~
      	verb="put";                                                //~v5mBI~
        puftph=Ppuftpht;                                           //~v5jeI~
        phostfnm=Ptarget;                                          //~v5jeI~
        plocalfnm=Psource;                                         //~v5jeI~
        if (Popt & DCPY_EXISTING)                                  //~v5jwR~
        	strcat(ftpopt," rep");                                 //~v5jwR~
    }                                                              //~v5jeI~
    if (!(Popt & DCPY_BIN))	//text mode                            //~v5mBI~
//      if (Pptsop->UTSOFPflag & UTSOFTPF_DBCSCONV) //dbcs conversion(SO/SO process) required//~v5mQR~
        {                                                          //~v5mBI~
//          lrecl=(Pptsop->UTSOFPsrcattr>>16);                     //~v5mBM~//~v6D0R~
            lrecl=(int)(Pptsop->UTSOFPsrcattr>>16);                //~v6D0I~
        	if (puftph->UFTPHflag & UFTPHFCP930)                   //~v5mBR~
            	pc3=CP930;                                         //~v5mBR~
            else                                                   //~v5mBI~
        	if (puftph->UFTPHflag & UFTPHFCP939)                   //~v5mBR~
            	pc3=CP939;                                         //~v5mBR~
            else                                                   //~v5mBI~
        	if (puftph->UFTPHflag & UFTPHFCPCJK)                   //~v5mQR~
            	pc3=CPCJK;                                         //~v5mQI~
            else                                                   //~v5mQI~
//              pc3="";                                            //~v5mQR~
                pc3=CPNODBCS;                                      //~v5mQI~
            if (Pptsop->UTSOFPattr & FILE_RECFMF)                  //~v5mBR~
		        pc2=TSOFTP_PARM_RECFMF;                            //~v5mBI~
            else                                                   //~v5mBI~
            if (Pptsop->UTSOFPattr & FILE_RECFMV)                  //~v5mBR~
		        pc2=TSOFTP_PARM_RECFMV;                            //~v5mBI~
            else                             //undefined not supported//~v5mBI~
                pc2="";                                            //~v5mBR~
            if (lrecl && *pc2 && *pc3)                             //~v5mBR~
            {                                                      //~v5mBI~
        		sprintf(ftpopt+strlen(ftpopt)," %s%s %s %s%d",TSOFTP_PARM_DBCS,pc3,pc2,TSOFTP_PARM_LRECL,lrecl);//~v5mBR~
        		if (Pptsop->UTSOFPflag & UTSOFTPF_NUMSTD) //8 byte linenumber fld exist//~v5mBI~
                	strcat(ftpopt," " TSOFTP_PARM_NUMSTD);         //~v5mBI~
            }                                                      //~v5mBI~
        }                                                          //~v5mBI~
    u3270getmembname(0,phostfnm,membname);                         //~v5jeI~
    if (u3270getmembname(U3GM_RETLENERR,phostfnm,membname)<0       //~v5jeI~
    ||  (*membname && u3270chkmembname(0,membname)))               //~v5jeR~
    {                                                              //~v5jeI~
    	if (Popt &  DCPY_NOSKIPMSG)                                //~v5jeI~
        {                                                          //~v5jeI~
        	uerrmsg("Invalid member name(%s)",0,                   //~v5jeI~
            		membname);                                     //~v5jeR~
            return U3CR_RC_OTHER;   //1 entry copy                 //~v5jeI~
        }                                                          //~v5jeI~
    	return U3CR_RC_INVALIDNAME;	//wildcard                     //~v5jeR~
    }                                                              //~v5jeI~
    phostfnm+=puftph->UFTPHhostnmlen+1;                            //~v5jeI~
    if (*puftph->UFTPHpswd)                                        //~v5jeI~
    {                                                              //~v5jeI~
        *pswd='/';                                                 //~v5jeI~
    	uftphostscrypt(1,puftph->UFTPHpswd,pswd+1);                //~v5jeI~
    }                                                              //~v5jeI~
    else                                                           //~v5jeI~
    	*pswd=0;                                                   //~v5jeI~
//  pc+=sprintf(pc," %s:%d %s%s %s %s",                            //~v5mxR~
//  pc+=sprintf(pc," %s:%d(%s) %s%s %s %s",                        //~v5mBR~
//      			puftph->UFTPHipad,	//hostname                 //~v5mBR~
//      			puftph->UFTPHport,	//portno                   //~v5mBR~
//      			puftph->UFTPHhost,	//hostname                 //~v5mBR~
//      			puftph->UFTPHuser,	//username                 //~v5mBR~
//      			pswd,				//password                 //~v5mBR~
	pc=cmd+u3270sethostuser(puftph,verb,cmd);                      //~v5mBI~
    pc+=sprintf(pc," %s %s",                                       //~v5mBI~
        			phostfnm,                                      //~v5jeI~
        			plocalfnm);                                    //~v5jeI~
    strcpy(pc,ftpopt);                                             //~v5jeI~
    rc=u3270cmdrequest(U3CRO_UERRMSGIFERR,cmd,0,0);                //~v5jeI~
    return rc;                                                     //~v5jeI~
}//u3270transfer                                                   //~v5jeR~
//**************************************************************** //~v5jkI~
//!ufilecreateparmproc                                             //~v5jkI~
//* insert src dirname into target path                            //~v5jkI~
//* and mkdir if the dir is not found                              //~v5jkI~
//*retrn:rc                                                        //~v5jkI~
//**************************************************************** //~v5jkI~
int u3270srcdupchk(char *Psfullpath,ULONG Psattr,char *Ptfullpath) //~v5jkI~
{                                                                  //~v5jkI~
    PUDIRLIST pudl,pudl0,pudl2;                                    //~v5jkR~
	int filectr,rc=0,ii;                                           //~v5jkR~
    char wildcard[DSN_MAXLEN],*pname;                              //~v5jkR~
//*********************                                            //~v5jkI~
    *wildcard=0;    //get req id                                   //~v5jkI~
	if (!u3270getsetdsnwild(U3DW_GET,Ptfullpath,0,wildcard,0))	//0:no output dsn/no output qualifier level//~v5jkR~
    	return 0;//		no target wild                             //~v5jkI~
//	if ((filectr=udirlist(Psfullpath,Psattr,&pudl0,0))<0)//0:no sort//~v5jkR~//~v6D1R~
  	if ((filectr=udirlist(Psfullpath,(unsigned)Psattr,&pudl0,0))<0)//0:no sort//~v6D1I~
    	return 4;                                                  //~v5jkI~
    for (ii=0,pudl=pudl0;ii<filectr;ii++,pudl++)                   //~v5jkI~
    {                                                              //~v5jkI~
        pname=pudl->name;                                          //~v5jkI~
//      strcpy(pudl->slink,pname);	//save orignal name            //~v5jkI~//~v6qaR~
        UDIRLIST_SET_SLINKNAME(pudl,pname);	//save orignal name    //~v6qaR~
//      udoseditname(0,pname,wildcard,pname);                      //~v5jkI~//~v6H1R~
	 	{                                                          //~v6J0R~
			UDIRLIST_NAMECOPY2WK(pudl,wkudlname);                  //+v6J0R~
			udoseditname(0,wkudlname,wildcard,wkudlname);          //~v6J0R~
        	udirlist_setname(0,pudl,wkudlname,0);	//@@@@FIXME test//~v6J0R~
        }                                                          //~v6J0R~
		if (pudl2=u3270srchdirlist(0,ii,pudl0,pname),pudl2)        //~v5jkR~
        {	                                                       //~v5jkI~
        	uerrmsg("duplicated name(%s) generated by wildcard(%s) for %s and %s,use replace option to force copy",0,//~v5jkR~
//          			pname,wildcard,pudl2->slink,pudl->slink);  //~v5jkR~//~v6qaR~
            			pname,wildcard,UDIRLIST_GET_SLINKNAME_OR_NULLSTR(pudl2),UDIRLIST_GET_SLINKNAME_OR_NULLSTR(pudl));//~v6qaI~
            rc=4;                                                  //~v5jkI~
            break;                                                 //~v5jkI~
        }                                                          //~v5jkI~
    }                                                              //~v5jkI~
    if (pudl0)                                                     //~v5jkI~
//      ufree(pudl0);                                              //~v5jkR~//~v6qaR~
        UDIRLIST_FREE(pudl0);                                      //~v6qaI~
    return rc;                                                     //~v5jkI~
}//u3270srcdupchk                                                  //~v5jkI~
//**************************************************************** //~v5jyI~
//u3270copyspfupdate                                               //~v5jyI~
//**************************************************************** //~v5jyI~
int u3270copyspfupdate(int Popt,PUFTPHOST Ppuftph,UCHAR *Psource,UCHAR *Ptarget,int Pflags,FILEFINDBUF3 *Ppfstat3s,FILEFINDBUF3 *Ppfstat3t)//~v5jyR~
{                                                                  //~v5jyI~
    int rc,spfopt=0,appendsw,lrecl,srcspfsw;                       //~v5jyR~
    PDSSPFINFO spfi;                                               //~v5jyR~
//********************                                             //~v5jyI~
	if (!(Ppfstat3t->attrFile & FILE_SPFDS))   //spf dataset       //~v5jyI~
    	return 0;                                                  //~v5jyI~
//  lrecl=Ppfstat3t->srcattr>>16;                                  //~v5jyI~//~v6D0R~
    lrecl=(int)(Ppfstat3t->srcattr>>16);                           //~v6D0I~
    if (Popt & DCPY_R2R)                                           //~v5jyI~
		srcspfsw=(Ppfstat3s->attrFile & FILE_SPF);                 //~v5jyR~
    else                                                           //~v5jyI~
    	srcspfsw=0;                                                //~v5jyI~
    memset(&spfi,0,PDSSPFINFOSZ);                                  //~v5jyI~
    appendsw=(Popt & DCPY_APPEND) && !(Pflags & CPYMV_TNEW); //target existsw//~v5jyI~
    if (!appendsw && srcspfsw)		//full copy of SPF member      //~v5jyR~
    {//copy source SPF                                             //~v5jyR~
        spfi.SPFIver=TSO_GETVV(Ppfstat3s);                         //~v5jyR~
        spfi.SPFImod=TSO_GETMM(Ppfstat3s);                         //~v5jyR~
        spfi.SPFIcdate=TSO_GETCDATE(Ppfstat3s);                    //~v5jyR~
        spfi.SPFIinitcnt=TSO_GETINITLINE(Ppfstat3s);               //~v5jyR~
        spfi.SPFIudate=Ppfstat3s->fdateLastWrite;                  //~v5jyR~
        spfi.SPFIutime=Ppfstat3s->ftimeLastWrite;                  //~v5jyR~
        spfi.SPFIlinecnt=(int)(Ppfstat3s->cbFile/lrecl);           //~v5k0R~
        strcpy(spfi.SPFIuserid,Ppfstat3s->uname);                  //~v5jyR~
        spfopt|=U3270SPFO_VER                                      //~v5jyI~
               |U3270SPFO_MOD                                      //~v5jyI~
               |U3270SPFO_ILINE                                    //~v5jyI~
               |U3270SPFO_CDATE                                    //~v5jyI~
               |U3270SPFO_UPDATE                                   //~v5jyI~
               |U3270SPFO_CLINE                                    //~v5jyI~
               |U3270SPFO_USERID;                                  //~v5jyI~
    }                                                              //~v5jyI~
    else	//partial copy or source has no spf                    //~v5jyR~
    {                                                              //~v5jyI~
 		if (Pflags & CPYMV_TNEW                                    //~v5jyI~
        ||  !(Ppfstat3t->attrFile & FILE_SPF))    //target is new or no spf info//~v5jyR~
        {                                                          //~v5jyI~
            spfopt|=U3270SPFO_ILINE|U3270SPFO_NOWILINE             //~v5jyI~
                   |U3270SPFO_CDATE|U3270SPFO_NOWCDATE;            //~v5jyR~
        }                                                          //~v5jyI~
        else       //append to SPF member                          //~v5jyR~
        {                                                          //~v5jyI~
            spfi.SPFIver=TSO_GETVV(Ppfstat3t);     //keep value as before//~v5jyI~
            spfi.SPFImod=TSO_GETMM(Ppfstat3t)+1;                   //~v5jyR~
            spfi.SPFIcdate=TSO_GETCDATE(Ppfstat3t);                //~v5jyI~
	        spfi.SPFIinitcnt=TSO_GETINITLINE(Ppfstat3t);           //~v5jyI~
        	spfopt|=U3270SPFO_VER                                  //~v5jyI~
            	   |U3270SPFO_MOD                                  //~v5jyI~
               	   |U3270SPFO_CDATE                                //~v5jyI~
                   |U3270SPFO_ILINE;                               //~v5jyI~
        }                                                          //~v5jyI~
	    strcpy(spfi.SPFIuserid,Ppuftph->UFTPHuser);                //~v5jyI~
	    spfopt|=U3270SPFO_UPDATE|U3270SPFO_NOWUPDATE  //update date/time//~v5jyI~
    	      |U3270SPFO_CLINE|U3270SPFO_NOWCLINE    //count line  //~v5jyI~
        	  |U3270SPFO_USERID;                                   //~v5jyI~
    }                                                              //~v5jyI~
    rc=u3270spfupdate(spfopt,Ppuftph,Ptarget,&spfi,0);             //~v5jyI~
    if (rc==U3CR_RC_NOTSUPPORT)	//config set no support            //~v5jyI~
    	rc=0;                                                      //~v5jyI~
    return rc;                                                     //~v5jyI~
}//u3270copyspfupdate                                              //~v5jyI~
//**************************************************************** //~v5mBI~
// set uftph request parm(recfm and lrecl)                         //~v5mBI~
//*rc   :0                                                         //~v5mBI~
//**************************************************************** //~v5mBI~
int u3270setftpparm(int Popt,PUFTPHOST Ppuftph,PUTSOFTPPARM Pptsop,FILEFINDBUF3 *Ppfstat3)//~v5mBI~
{                                                                  //~v5mBI~
//**********************                                           //~v5mBI~
    memset(Pptsop,0,sizeof(UTSOFTPPARM));                          //~v5mBR~
//  if (!(Ppuftph->UFTPHflag & (UFTPHFCP930|UFTPHFCP939)))	//japanese dbcs//~v5mQR~
//  if (!(Ppuftph->UFTPHflag & (UFTPHFCP930|UFTPHFCP939|UFTPHFCPCJK)))	//japanese dbcs//~v5mQR~
//  	return 0;                                                  //~v5mQR~
    Pptsop->UTSOFPattr=Ppfstat3->attrFile;    //fix/variable etc   //~v5mBI~
    Pptsop->UTSOFPsrcattr=Ppfstat3->srcattr; //lrecl+blksz         //~v5mBI~
  if ((Ppuftph->UFTPHflag & (UFTPHFCP930|UFTPHFCP939|UFTPHFCPCJK)))	//japanese dbcs//~v5mQI~
    Pptsop->UTSOFPflag|=UTSOFTPF_DBCSCONV;                         //~v5mBI~
    return 0;                                                      //~v5mBI~
}//u3270setftpparm                                                 //~v5mBI~
