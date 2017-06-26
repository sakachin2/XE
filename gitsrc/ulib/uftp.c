//*CID://+v6J0R~:                             update#=  823;       //~v6J0R~
//*************************************************************
//*ufile1f.c
//* get remote file/dir info by ftp
//*************************************************************
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6Di:160625 for compiler warning,-Wformat-security(not literal printf format)//~v6DiI~
//v6D2:160423 LNX compiler warning for bitmask assignment(FDATE,FTIE)//~v6D2I~
//v6D1:160418 LNX64 compiler warning                               //~v6D1I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6BM:160313 (W32) compiler warning                               //~v6BMI~
//v6u2:140331 (Win:ftp BUG) err if filename is relative and without pathname//~v6u2I~
//v6qg:131208 xehosts pswd;protect copy line(update line should be decripted pswd)//~v6qgI~
//v6qf:131208 (BUG)slink target chk;multiple cmd will miss to chk "dir" ftp cmd output when "cd" ftp cmd failed because next cmd "dir" is executed.//~v6qfI~
//v6qe:131206 (BUG)ftp "ls" dose not show slinkname,but "l" on attr. display dummy slinkname.//~v6qeI~
//v6qc:131206 (BUG)slink err flag was not set for ftp dirlist      //~v6qcI~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6dh:120224 (Axe)there is a case smb user is null                //~v6dhI~
//v6d9:120211 8 byte hostid is not accepted as hostid(current max is 7)//~v6d9I~
//v6d7:120209 (SMB)adjust for target:Windows                       //~v6d7I~
//v6d6:120209 (BUG)initially set modtime err for psftp             //~v6d6I~
//v6d1:120131 (SMB)share option for SAMBA node(win64  192.168.2.19 usrskt pswd  share=p)//~v6d1I~
//v6d0:120131 (SMB)volatile password on UFTPHOST                   //~v6d0I~
//v5mQ:080806 (CJK)DBCS chk for C(J)K                              //~v5mQI~
//v5mG:080627 3270:distigush TSO and TSOE for submit cmd           //~v5mGI~
//v5mB:080621 3270:DBCS conversion support(CP930(290+300)/CP939(1027+300)//~v5mBI~
//v61p:080121 (FTP)psftp support                                   //~v61pI~
//v61m:080121*Bug report by M.J(errmsg is "New file" for "path err"//~v61mI~
//v61e:071126*(FTP)use ls -la if avail to get list of "." file     //~v61eI~
//v61d:071126*(FTP)skip modtime if not supported                   //~v61dI~
//v61c:071123*(FTP)for the case /home is read protected by SELinux //~v61cI~
//v61b:071123*(FTP)log errmsg to ftplog alos                       //~v61bI~
//v61a:071123*(FTP:BUG)226 is also failed case("226 Transfer done (but failed to open irectory)." is returned)//~v61aI~
//v615:071117 (FTP:BUG)lowercase icmd= rejected                    //~v615I~
//v5kt:070702 from rh9 to ProFtpd,ls cmd fail by "no route to host". it requires active mod(once issue passive cmd to set off)//~v5ktI~
//            support ICMD parm on xehost                          //~v5ktI~
//v5ks:070702 ProFtpd return filename only for ls -l by rfc from v1.2.10//~v5ksI~
//            "ls" use NLST(fname only),"dir" usr LIST(detail list) cmd. so change to "dir"//~v5ksI~
//v5jz:061129 3270:host id is case insensitive for TSO remote      //~v5jzI~
//v5jg:061015 3270 CurDir utilize for the case no path specified   //~v5jgI~
//v5j9:060918 more chk for pasword specification missing           //~v5j9I~
//v5j7:060914 (BUG)xehosts file ipaddr chk err                     //~v5j7I~
//v5j4:060914 ftp:3270 support (xehost TSO=portno operand)         //~v5j4I~
//v5f0:041111 line comment support for ftp host list(" #" patern " " ion//~v5f0I~
//v5ex:041107 tempname support at remote                           //~v5exI~
//v5di:040610 (FTP:BUG)modtime should get also date because tz ajust may change date//~v5diI~
//v5df:040609 (AIX:BUG)AIX responce is by JST for ls,GMT for modtime//~v5deI~
//                     LNX responce is both by GMT;                //~v5deI~
//                     ajust ls time by xehosts,mdtime result by ftime tz//~v5deI~
//v5de:040609 (AIX:BUG)filetime set not done for download file     //~v5deI~
//v5d0:040525 (FTP:BUG)commentline chk should before opdno chk     //~v5d0I~
//v5c8:040331 (FTP:BUG)uftpfullpath:parm may not contain remoteID(slink not found msg)//~v5c8I~
//v5c7:040330 (UNX)always ignore slink err(put on udirlist)        //~v5c7I~
//v5c6:040330 (FTP:BUG)optionaly setup udirlist for slinkerr like as v5c4//~v5c6I~
//v5bo:040211 (FTP)password cryptograph                            //~v5boI~
//v5bn:040211 (FTP)allow tab as delm of hosts file                 //~v5bnI~
//v5bf:040204 (FTP:BUG)space containing filename support           //~v5bfI~
//v5be:040204 (FTP:BUG)uftpisremote should chk filename enclosed by quate//~v5beI~
//v5bb:040202 (FTP:BUG)home= parm set miss                         //~v5bbI~
//v5ba:040202 (FTP:BUG)consider 0d0a eol for hosts data            //~v5bbR~
//v5ar:040111 (FTP)wild card err responce chk specification like as 5**//~v5arI~
//v5ai:040108 clear not used slink area clear on ufstat            //~v5aiI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5afI~
//v5ad:040105 support TZ=hhmm and DBCS=EUC/SJIS                    //~v5adI~
//v5ac:040105 chk "GMT" string to ajust to JST                     //~v5acI~
//v5ab:040104 integrate ROOTDIR2--->ROOTDIR3                       //~v5abI~
//v5a9:040104 (BUG slink not found)                                //~v5a9I~
//v5a7:040104 missing ufree                                        //~v5a7I~
//v5a6:040104 (UNX,FTP)save slink uid,gid,uname,gname on dirlist for xe dirlist//~v5a6I~
//v5a1:040102 (WIN:BUG)UQFREE ASSERTION err;free and umalloc unmatch for win//~v5a1I~
//v59y:040101 (UNX,FTP)use slink source uname/gname                //~v59yI~
//v59x:040101 (UNX,FTP)save slink timestamp and size for dirlist for xe//~v59xI~
//v59d:030816 ftp support
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#ifdef UNX  //!!!!!!!!!!!!!!!!!!
    #include <unistd.h>
#else       //!!!!!!!!!!!!!!!!!!
//*******************************************************
#include <direct.h>
#include <io.h>

#ifdef W32
	#include <windows.h>
#endif	//UNX
#endif //!!!!!!!!!!!!!!!!!!

//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <ufile.h>
#include <ufile5.h>
#include <uerr.h>
#include <ustring.h>
#include <ualloc.h>
#include <uproc.h>
#include <uftp.h>
#include <ufile1f.h>
#include <uftp3.h>                                                 //~v61pM~
#include <ufemsg.h>
#include <uedit.h>
#include <uparse.h>
#include <utrace.h>                                                //~v5a6I~
#include <u3270.h>                                                 //~v5mBI~
#include <ufemsg.h>                                                //~v6qgI~
#include <uedit2.h>                                                //~v6D2I~
#include <utf.h>                                                   //~v6J0I~
#include <utf22.h>                                                 //~v6J0I~
#include <ucvucs.h>                                                //~v6J0I~
#ifdef ARMXXE                                                      //~v6d9R~
	#include <jnic2ju.h>                                           //~v6d9I~
#endif                                                             //~v6d9I~
//*******************************************************
typedef struct _USLCPARM  {
                            PUFTPHOST   USLpuftph;                 //~v5ksI~
                            PUDIRLIST   USLpudl;
                            int         USLpudlno;
                            char       *USLtargetfnm;
                            } USLCPARM,*PUSLCPARM;
#define UFSLCARMSZ (sizeof(USLCPARM))
static 	UQUEH Suftphqh;  //ftpnode table

#define MAXHDIR 100
static UFTPDIRH  Sfdh[MAXHDIR];
#define HOMEDIR "/home"                                            //~v61cI~
static char Sslinkerrmsg[512];                                     //~v6qfI~
#define ERR_PSWD "error"                                           //~v6qgI~
//*******************************************************
int uftpfstatroot(FILEFINDBUF3 *Ppffb3);
#define UFFSO_CD    0x01
#define UFFSO_HOME  0x02     //search in /home it's may fail by SELinux protection//~v61cI~
int uftplsoutchk(PUFTPHOST Ppuftph,int Popt,char *Pfname,PUDIRLIST Ppudl,char **Pstdo,int Pstdoctr);//~v5afR~
int uftplsoutchkslink(PUFTPHOST Ppuftph,int Popt,char *Pslink,PUDIRLIST Ppudl,char ***Ppstdo,int *Ppstdoctr);//~v5afR~
int uftpsavehdir(PUFTPHOST Ppuftph,PUDIRLIST Ppudl,char *Pwild,ULONG Pattr,int *Phdir);//~v5afR~
PUFTPDIRH uftpsrchhdir(ULONG Phandle);
int uftpclosehdir(int Phandle);
FTPCMD_CALLBACK    uftpslinklscmd;
//int uftpgetpathname(char *Pfpath,char *Ppath,int Plen);          //~v6d1R~
int uftpgetslinkattr(PUFTPHOST Ppuftph,char *Pdirnm,PUDIRLIST Ppudl);//~v5afR~
int uftpmodtimerchk(PUFTPHOST Ppuftph,char **Ppstdo,int Pstdoctr,PUDIRLIST Ppudl);//~v5afR~
int uftpslinkcomp(const void *ent1,const void *ent2);              //~v59dI~
int uftpsortslink(int Popt,PUDIRLIST Ppudl,int Pentno);            //~v59dI~
int uftgetstringopd(int Popt,char *Pparmid,char *Pbuff,char *Pin,char *Pout,int Poutlen,//~v5ktR~
					UCHAR **Ppargc,int Pmaxii,int *Ppii);          //~v5ktR~
int uftplshome(PUFTPHOST Ppuftph,int Popt,char *Pfpnm,PUDIRLIST Ppudl);//~v61cR~
int uftpmodtimeerr(PUFTPHOST Ppuftph);                             //~v61dI~
//*******************************************************
//*set ffb3 from stdo
//*******************************************************
int uftpfstatroot(FILEFINDBUF3 *Ppffb3)
{
#ifdef UNX
	FILEFINDBUF3 Sffb3root={
                          FILE_DIRECTORY+FILE_REMOTE,//ULNG         attrFile;       //DWORD dwFileAttributes
                  		  0,           //srcattr; //slink source attr;mode(2)+rsv(1)+attr(1)
                          0,           //uid_t     uid;
                          0,           //gid_t     gid;
                          0,           //dev_t     fsid;//filesystem
                          0,           //USHORT    dsv;
                          0,           //time_t    atime;     //accessed
                          0,           //time_t    mtime;     //modified
                          0,           //time_t    ctime;     //corrected
                          {0},             //FTIME         ftimeLastWrite; //ftLastWriteTime
                          {0},             //FDATE         fdateLastWrite; //:
                          0,             //ULONG         cbFile;         //nFileSizeLow
                          0,             //time_t        slinkmtime      //nFileSizeLow//~v59xR~
                          {0},           //FTIME         slinkftime      //nFileSizeLow//~v59xR~
                          {0},           //FDATE         slinkfdate      //nFileSizeLow//~v59xR~
                          0,             //ULONG         slinksize       //nFileSizeLow//~v59xR~
                  		  0,             //uid_t     slinkuid;     //~v5a6I~
                          0,             //gid_t     slinkgid;     //~v5a6I~
                          "/",           //char          achName //MAX_PATH of windef.h
                          "",            //char          slink
                          "",            //char          uname
                          "",            //char          gname     //~v5a6R~
                          "",            //char      slinkuname[MAXUNAMESZ+1];   //for ftp:user name//~v5a6I~
                          ""             //char      slinkgname[MAXGNAMESZ+1];   //for ftp:group name//~v5a6I~
                        };
#else   //!UNX
	FILEFINDBUF3 Sffb3root={
                          FILE_DIRECTORY+FILE_REMOTE,//ULNG         attrFile;       //DWORD dwFileAttributes
                          0,                //ULNG         srcattr ;       //DWORD dwFileAttributes
                          {0},             //FTIME         ftimeLastWrite; //ftLastWriteTime
                          {0},             //FDATE         fdateLastWrite; //:
                          {0},             //FILETIME      ftCreationTime;   //by FindFirstFile API
                          {0},             //FILETIME      ftLastAccessTime;
                          {0},             //FILETIME      ftLastWriteTime;
                          0,             //ULONG         cbFile;         //nFileSizeLow
                          {0},           //FTIME         slinkftime      //nFileSizeLow//~v59xR~
                          {0},           //FDATE         slinkfdate      //nFileSizeLow//~v59xR~
                          0,             //ULONG         slinksize       //nFileSizeLow//~v59xR~
                          "/",           //char          cFileName[260]; //MAX_PATH of windef.h
                          "",            //char          achName[14];    //cAlternateFileName//~v5a6R~
                          "",            //char          slink           //cAlternateFileName//~v5a6R~
                          "",            //char          uname     //~v5a6R~
                          "",            //char          gname     //~v5a6R~
                          "",            //char          slinkuname[MAXUNAMESZ+1];   //for ftp:user name//~v5a6I~
                          ""             //char          slinkgname[MAXGNAMESZ+1];   //for ftp:group name//~v5a6I~
                        };
#endif
//*********************************
	*Ppffb3=Sffb3root;
	return 0;
}//uftpfstatroot
//*******************************************************          //~v61cI~
//*serch in /home dir(for the case /home read protected by SELinux)//~v61cI~
//*Ppudl is by UDIRLIST_WK                                         //~v6J0I~
//*******************************************************          //~v61cI~
int uftplshome(PUFTPHOST Ppuftph,int Popt,char *Pfpnm,PUDIRLIST Ppudl)//~v61cR~
{                                                                  //~v61cI~
    int rc,opt=0;                                                  //~v61cI~
    UCHAR homedir[FTP_MAXPATH];                                    //~v61cI~
//*********************************                                //~v61cI~
    sprintf(homedir,"%s/%s/.",HOMEDIR,Pfpnm);                      //~v61cI~
//	rc=uftpfstatudl(Ppuftph,opt,homedir,Ppudl);                    //~v61cI~//~v6D0R~
  	rc=(int)uftpfstatudl(Ppuftph,opt,homedir,Ppudl);               //~v6D0I~
    if (!rc)                                                       //~v61cI~
//  	strcpy(Ppudl->name,Pfpnm);                                 //~v61cI~//~v6J0R~
    	uftp_udirlist_setname(0,Ppuftph,Ppudl,Pfpnm,0);            //~v6J0R~
    else                                                           //~v61cI~
//  if (rc==ENOENT)                                                //~v61mR~
    if (rc==ENOENT||ERROR_PATH_NOT_FOUND)                          //~v61mI~
    {                                                              //~v61cI~
//  	memset(Ppudl,0,UDIRLISTSZ); //clear value set before name compare//~v61cI~//~v6qaR~
//  	UDIRLIST_WK_INIT(*Ppudl,(Ppudl)->slinkdummy); //clear value set before name compare//~v6qaR~//~v6J0R~
    	Ppudl->attr=FILE_SETMODEATTR(S_IFDIR,0);                   //~v61cR~
//  	strcpy(Ppudl->name,Pfpnm);                                 //~v61cI~//~v6J0R~
    	uftp_udirlist_setname(0,Ppuftph,Ppudl,Pfpnm,0);  //will not malloc because UDLIRLIST_WK allocate max buffsz for name and nameW//~v6J0R~
        rc=0;                      //assume the user home dir is exist//~v61cM~
    }                                                              //~v61cI~
    return rc;                                                     //~v61cI~
}//uftplshome                                                      //~v61cR~
//*******************************************************
//*fstat for remotre file
//* parm Pfpnm should be without nodename                          //~v5afI~
//* chk path then chk file for path err chk for hidden file(.xxx)
//*******************************************************
unsigned int uftpfstatudl(PUFTPHOST Ppuftph,int Popt,char *Pfpnm,PUDIRLIST Ppudl)//~v5afR~
{
    int rc,pathlen;
    int stdoctr,opt;
    char **stdo;
    UCHAR ftpcmd[FTP_MAXPATH+128];	//cd then ls -la
    UCHAR pathnm[FTP_MAXPATH];	//cd then ls -la
    char *listcmd;                                                 //~v5ksI~
//*********************************
  	if (UFTPH_ISSMB(Ppuftph))                                      //~v6d1I~
    	return uftp3smb_fstatudl(Popt,Ppuftph,Pfpnm,Ppudl);        //~v6d1R~
    listcmd=Ppuftph->UFTPHlscmd;                                   //~v5ksR~
	pathlen=uftpgetpathname(Pfpnm,pathnm,sizeof(pathnm));
    opt=0;
  if (Ppuftph->UFTPHflag & UFTPHFMODTERR)                          //~v61dI~
  {                                                                //~v61dI~
    if (pathlen)                                                   //~v61dI~
    {                                                              //~v61dI~
	    sprintf(ftpcmd,                                            //~v61dI~
				"cd \"%s\"\n"      \
        	    "%s\n",                                            //~v61dI~
            	pathnm,listcmd);                                   //~v61dI~
    	opt=UFFSO_CD;                                              //~v61dI~
    }                                                              //~v61dI~
    else                                                           //~v61dI~
	    sprintf(ftpcmd,                                            //~v61dI~
        	    "%s\n",                                            //~v61dI~
    			listcmd);                                          //~v61dI~
  }                                                                //~v61dI~
  else                                                             //~v61dI~
  {                                                                //~v61dI~
    if (pathlen)
    {
	    sprintf(ftpcmd,
				"cd \"%s\"\n"      \
//      	    "ls -la\n"                                         //~v5ksR~
        	    "%s\n"    \
        	    "modtime \"%s\"\n",  \
//          	pathnm,Pfpnm);                                     //~v5ksR~
            	pathnm,listcmd,Pfpnm);                             //~v5ksI~
    	opt=UFFSO_CD;
    }
    else
	    sprintf(ftpcmd,
//      	    "ls -la\n"                                         //~v5ksR~
        	    "%s\n"  \
        	    "modtime \"%s\"\n",                                //~v5bfR~
//  			Pfpnm);                                            //~v5ksR~
    			listcmd,Pfpnm);                                    //~v5ksI~
  }                                                                //~v61dI~
    rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo,&stdoctr,0,0);	//get stdout/stderr//~v5afR~
    if (!strcmp(pathnm,HOMEDIR))                                   //~v61cI~
    	opt=UFFSO_HOME;                                            //~v61cI~
    if (!rc)
	    rc=uftplsoutchk(Ppuftph,opt,Pfpnm+pathlen,Ppudl,stdo,stdoctr);//skip top "?" line//~v5afR~
    if (stdo)
	    ufree(stdo);
    if (!rc)
        if (!(Popt & FTPSUD_SLINK))     //not recursive call from ufgetslinkattr
            uftpgetslinkattr(Ppuftph,pathnm,Ppudl);                //~v5afR~
//      return rc;                                                 //~v6D0R~
        return (unsigned)rc;                                       //~v6D0I~
}//uftpfstatudl
#ifdef ARMXXE                                                      //~v6d9I~
//*******************************************************          //~v6d9M~
int uftpsmbj_isexist(int Popt,PUFTPHOST Ppuftph,char *Pfpath)      //~v6d9M~
{                                                                  //~v6d9M~
    int rc;                                                        //~v6d9M~
    FILEFINDBUF3 ffb3;                                             //~v6d9M~
//*********************************                                //~v6d9M~
	rc=jnismb_ufstat(0,Ppuftph,Pfpath,&ffb3);                      //~v6d9M~
    if (rc)                                                        //~v6d9M~
    	return 0;		//not found                                //~v6d9M~
    if (ffb3.attrFile & FILE_DIRECTORY)                            //~v6d9M~
    	return 2;		//dir                                      //~v6d9M~
    return 1;			//file                                     //~v6d9M~
}//uftpsmbj_isexist                                                //~v6d9M~
#endif                                                             //~v6d9I~
//*******************************************************
//*simple chk file is exist
//* parm1:hostname,if 0 extract ftom filename
//* "ls fnm" avail for hidden file(.xxx file)
//* "cd fnm" for chk empty dir(ls return 550 whenempty)
//* (LNX)ls return no err when not found
//* (LNX)ls return no line for empty dir
//* rc:1:file,2:dir,0:notfound
//*******************************************************
int uftpisexist(PUFTPHOST Ppuftph,char *Pfpath)                    //~v5afR~
{
//    int stdoctr,existsw=0,rc;
//    char **stdo,**stdo0,*pfname,*pnode;
//    UCHAR ftpcmd[FTP_MAXPATH+128];  //cd then ls -la
//    char  hostnm[FTP_HOSTNAMELEN+1];
////*********************************
//    if (Pnode)
//    {
//        pfname=Pfname;
//        pnode=Pnode;
//    }
//    else
//    {
//        pfname=Pfname+uftpisremote(Pfname,hostnm)+1;
//        pnode=hostnm;
//    }
//    sprintf(ftpcmd,
//            "ls %s\n"
//            "cd %s\n",
//             pfname,pfname);
//    rc=uftpcmd(0,pnode,ftpcmd,&stdo0,&stdoctr,0);
//    if (!rc)
//    {
//        stdo=stdo0;
//        rc=uftpcmdsrchrespid(&stdo,&stdoctr,"150 550 ");//skip 150:open data connection/~v59dR~
//        if (!rc)
//        {
//            existsw=1;      //cd success
//            rc=uftpcmdsrchrespid(&stdo,&stdoctr,FTPRESPID_XCOMP);//jump to end of ls
//        }
//        if (!rc)
//        {
//            rc=uftpcmdsrchrespid(&stdo,&stdoctr,"250 550 ");//skip 150:open data connection/~v59dR~
//            if (!rc)
//                existsw=2;      //cd success
//        }
//        ufree(stdo0);
//    }
//    return existsw;
//  UDIRLIST udl;                                                  //~v6qaR~
//  UDIRLIST_WK(udl,wkslinkname);                                  //~v6qaI~//~v6J0R~
    UDIRLIST_WK(udl,wkname,wknamew,wkslinkname);                   //~v6J0I~
    int rc;
//*********************************
#ifdef ARMXXE                                                      //~v6d9I~
  	if (UFTPH_ISSMBJ(Ppuftph))                                     //~v6d9I~
		return uftpsmbj_isexist(0,Ppuftph,Pfpath);                 //~v6d9R~
#endif                                                             //~v6d9I~
//  UDIRLIST_WK_INIT(udl,wkslinkname);                             //~v6qaI~//~v6J0R~
    UDIRLIST_WK_INIT(udl,wkname,wknamew,wkslinkname);              //~v6J0I~
//  rc=uftpfstatudl(Ppuftph,0,Pfpath+Ppuftph->UFTPHhostnmlen+1,&udl);//~v5afR~//~v6D0R~
    rc=(int)uftpfstatudl(Ppuftph,0,Pfpath+Ppuftph->UFTPHhostnmlen+1,&udl);//~v6D0I~
    if (rc)
    	return 0;		//not found
    if (udl.attr & FILE_DIRECTORY)
    	return 2;		//dir
    return 1;			//file
}//uftpisexist
//**********************************************************************
// find first for msdos discket(create udirlist)
// parm filename should be without nodename                        //~v5afI~
// return :r.c
//**********************************************************************
int uftpopendir(PUFTPHOST Ppuftph,char *Pfpath,ULONG Pattr,ULONG *Phdir,int *Pentno)//~v5afR~
{
	PUDIRLIST pudl0=NULL;                                          //~v6h7R~
//  unsigned rc=FTPRC_PARSEERR,rc2;                                //~v6D0R~
    int rc=FTPRC_PARSEERR,rc2;                                     //~v6D0I~
    UCHAR ftpcmd[FTP_MAXPATH+128];
    UCHAR pathnm[FTP_MAXPATH];	//cd then ls -la
    char **stdo,**stdo0,*pwild,*pdirnm;
//  int stdoctr,fno,hdir=0,pathlen;                                //~v6h7R~
    int stdoctr,fno=0,hdir=0,pathlen;                              //~v6h7I~
    char *listcmd;                                                 //~v5ksI~
//*********************************
    listcmd=Ppuftph->UFTPHlscmd;                                   //~v5ksR~
	pathlen=uftpgetpathname(Pfpath,pathnm,sizeof(pathnm));
    pwild=Pfpath+pathlen;
    if (WILDCARD(pwild))
    	pdirnm=pathnm;
    else
    {
	    pwild=0;
    	pdirnm=Pfpath;
    }
  if (UFTPH_ISSMB(Ppuftph))                                        //~v6d1I~
  	uftp3smb_setcmd(UFTPSMBCMD_DIR,Ppuftph,ftpcmd,Pfpath,0/*charparm2*/,pathlen,0/*intpam2*/);//~v6d1R~
  else                                                             //~v6d1I~
  {                                                                //~v6u2I~
   if (*pdirnm)                                                    //~v6u2I~
    sprintf(ftpcmd,
            "cd \"%s\"\n"      \
//          "ls -la\n",                                            //~v5ksR~
            "%s\n",                                                //~v5ksI~
//          pdirnm);                                               //~v5ksR~
            pdirnm,listcmd);                                       //~v5ksI~
   else                                                            //~v6u2I~
    sprintf(ftpcmd,                                                //~v6u2I~
            "cd\n"      \
            "%s\n",                                                //~v6u2I~
            listcmd);                                              //~v6u2I~
  }                                                                //~v6u2I~
    rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo0,&stdoctr,0,0);	//get stdout/stderr//~v5afR~
    if (!rc)
    {
        stdo=stdo0;
        for (;;)
        {
          	if (UFTPH_ISSMB(Ppuftph))                              //~v6d1I~
            {                                                      //~v6d1I~
    			uftp3smb_respchk(UFTPSMBCMD_DIR|F3SMBO_SINGLESTART,Ppuftph,Pfpath,&stdo,&stdoctr,0/*rc*/);//~v6d1R~
                break;                                             //~v6d1I~
            }                                                      //~v6d1I~
//cd
//          if (rc2=uftpcmdsrchrespid(&stdo,&stdoctr,"250 5** "),rc2) //CD ok or no such file//~v61pR~
          	if (UFTPHISPSFTP(Ppuftph))                             //~v61pR~
				rc2=uftp3cdrespchk(0,Ppuftph,pdirnm,&stdo,&stdoctr);//~v61pR~
          	else                                                   //~v61pI~
            	rc2=uftpcmdsrchrespid(&stdo,&stdoctr,"250 5** "); //CD ok or no such file//~v61pR~
            if (rc2)                                               //~v61pI~
            {
                if (rc2==1)  //cd fail
                    rc=ENOENT;
                break;
            }
//ls
//          if (rc2=uftpcmdsrchrespid(&stdo,&stdoctr,"150 "),rc2) //150:open data connection/~v59dR~//~v61pR~
	  		if (UFTPHISPSFTP(Ppuftph))                             //~v61pI~
    			rc2=uftpcmdsrchrespid(&stdo,&stdoctr,FTP_PSFTP_OK_LIST); //Listing directory ____//~v61pI~
            else                                                   //~v61pI~
                rc2=uftpcmdsrchrespid(&stdo,&stdoctr,"150 "); //150:open data connection/~v59dR~//~v61pR~
            if (rc2)                                               //~v61pI~
                break;
            rc=0;
            break;
        }//rc chk
        if (!rc)
            rc=uftpgetdl(Ppuftph,stdo,stdoctr,&pudl0,&fno);//skip top "?"//~v5afR~
        ufree(stdo0);
  		if (UFTPH_ISSMB(Ppuftph))                                  //~v6d1I~
  			uftp3smb_getdlattr(0,Ppuftph,Pfpath,pathlen,pudl0,fno);//fill attr,uid,gid by stat cmd//~v6d1R~
        if (!rc)
            if (rc=uftpsavehdir(Ppuftph,pudl0,pwild,Pattr,&hdir),rc)//~v5afR~
//              ufree(pudl0);                                      //~v6qaR~
                UDIRLIST_FREE(pudl0);                              //~v6qaI~
    }
//  *Phdir=hdir;                                                   //~v6D0R~
    *Phdir=(ULONG)hdir;                                            //~v6D0I~
    *Pentno=fno;
    if (!rc)
		uftpdirlistslink(Ppuftph,Pfpath,pudl0,fno);                //~v5afR~
    return rc;
}//uftpopendir
//**********************************************************************
// find next msdos disket drive
// return :r.c  0:found 4:no more file else errno
//**********************************************************************
int uftpreaddir(int Phdir,PUDIRLIST *Pppudl)
{
    PUFTPDIRH pfdh;
    PUDIRLIST pudl;
    int    rc=0,npos;
    ULONG attr;
    char *pwild;
//*********************************
//  if (!(pfdh=uftpsrchhdir(Phdir)))                               //~v6D0R~
    if (!(pfdh=uftpsrchhdir((ULONG)Phdir)))                        //~v6D0I~
        return ERROR_INVALID_HANDLE;
    npos=pfdh->UFTPDHnpos;
    pudl=pfdh->UFTPDHpudl+npos;
    attr=pfdh->UFTPDHattr;
    pwild=pfdh->UFTPDHwild;
    if (!*pwild)
    	pwild=0;
    for (;;npos++,pudl++)
    {
//  	if (!*pudl->name)	//last entry                           //~v6J0R~
    	if (!pudl->name)	//last entry                           //~v6J0I~
        {
    		rc=ERROR_NO_MORE_FILES;
            break;
        }
//  	if (!(Gufile_opt & GFILEOPT_IGNORESLINKERR))  //not ignore slinkerr//~v5c7R~
//      {                                                          //~v5c7R~
//      	if (pudl->srcattr & FILE_FTPWKSL)  //slink er          //~v5c7R~
//          	continue;	//skip listup                          //~v5c7R~
//      }                                                          //~v5c7R~
        if (pwild)
        {
			if (ufilewildcomp(UFWC_CASE|UFWC_0BYTE,pudl->name,pwild,0))//not match
            	continue;
        }
        if (uftpattrselect(pudl->attr,pudl->srcattr,attr))    //attr match
        {
		    *Pppudl=pudl;
			pfdh->UFTPDHnpos=npos+1;
        	break;
        }
    }
    return rc;
}//uftpreaddir
//*******************************************************
//*select member by attr specified
//*parm 1:file attr
//*parm 2:file attr of slink src
//*parm 3:parm attr(select req)
//*return:1:ok,0:ng
//*******************************************************
int uftpattrselect(ULONG Pfattr,ULONG Pfattrsrc,ULONG Ppattr)
{
    unsigned int modef,modep;
//*********************************
//  modef=FILE_GETMODE(Pfattr);                                    //~v6D1R~
    modef=(unsigned)FILE_GETMODE(Pfattr);                          //~v6D1I~
//  modep=FILE_GETMODE(Ppattr);                                    //~v6D1R~
    modep=(unsigned)FILE_GETMODE(Ppattr);                          //~v6D1I~
   if (!(Ppattr & FILE_SPECIAL))  //select reguler file only
   {
    if (Pfattr & FILE_SPECIAL)  //select reguler file only
    	return 0;
   }
   else
   {
    if (S_ISLNK(modef))//symbolic link
//  	modef=FILE_GETMODE(Pfattrsrc);                             //~v6D1R~
    	modef=(unsigned)FILE_GETMODE(Pfattrsrc);                   //~v6D1I~
    if (S_ISCHR(modep))       //req char only
      if (!S_ISCHR(modef))
    	return 0;
    if (S_ISBLK(modep))       //req blk only
	  if (!S_ISBLK(modef))
    	return 0;
    if (S_ISFIFO(modep))      //req fifo only
      if (!S_ISFIFO(modef))
    	return 0;
    if (S_ISSOCK(modep))
      if (!S_ISSOCK(modef))
    	return 0;
   }//non reg
#ifdef UTF8SUPPH                                                   //~v5mQI~
    if (Pfattr & FILE_SLINK)	//file is SLINK                    //~v5mQI~
    	if ((Ppattr & FILE_SLINK))		//requested SLINK select   //~v5mQI~
       		return 1;					//select even if dir and dir is not requested//~v5mQI~
#endif                                                             //~v5mQI~
    if (Pfattr & FILE_DIRECTORY)	//file is dir
    	if (!(Ppattr & FILE_DIRECTORY))		//dir not specified
       		return 0;					//no select
    if (Pfattr & FILE_HIDDEN)	//file is dir
    	if (!(Ppattr & FILE_HIDDEN))		//dir not specified
       		return 0;					//no select
    if (Pfattr & FILE_SYSTEM)	//file is dir
    	if (!(Ppattr & FILE_SYSTEM))		//dir not specified
       		return 0;					//no select
    return 1;
}//uftpattrselect
//*******************************************************
//*read slink
//*******************************************************
int uftpgetslinkattr(PUFTPHOST Ppuftph,char *Pdirnm,PUDIRLIST Ppudl)//~v5afR~
{
//  UDIRLIST udl;                                                  //~v6qaR~
//  UDIRLIST_WK(udl,wkslinkname);                                  //~v6qaI~//~v6J0R~
    UDIRLIST_WK(udl,wkname,wknamew,wkslinkname);                   //~v6J0I~
    int rc,pathlen;
    char *pslink,slinkfpath[FTP_MAXPATH];
//*************************
    if (!S_ISLNK(FILE_GETMODE(Ppudl->attr)))//symbolic link
		Ppudl->srcattr=0;
    else                                                           //~v61pI~
//  if (!*Ppudl->slink)		//PSFTP-v060 dosenot display slink target//~v61pI~//~v6qaR~
//  if (Ppudl->pslink || !*Ppudl->pslink)		//PSFTP-v060 dosenot display slink target//~v6qaI~//+v6J0R~
    if (!Ppudl->pslink || !*Ppudl->pslink)		//PSFTP-v060 dosenot display slink target//+v6J0I~
    {                                                              //~v61pI~
		Ppudl->srcattr=0;                                          //~v61pI~
        if (!(Gufile_opt & GFILEOPT_NOSLINKERRMSG))                //~v61pI~
        	uerrmsg("S-Link target get failed for link-name %s",0, //~v61pI~
                            Ppudl->name);                          //~v61pI~
    }                                                              //~v61pI~
    else
    {
//      pslink=Ppudl->slink;                                       //~v6qaR~
        pslink=Ppudl->pslink;                                      //~v6qaI~
        if (*pslink!='/')   //relative path
        {
//        	uftpfullpath(Ppuftph,slinkfpath,Pdirnm,sizeof(slinkfpath));//~v5c8R~
          	uftpfullpathnorid(Ppuftph,slinkfpath,Pdirnm,sizeof(slinkfpath));//~v5c8I~
//          pathlen=strlen(slinkfpath);                            //~v6D0R~
            pathlen=(int)strlen(slinkfpath);                       //~v6D0I~
            *(slinkfpath+pathlen++)='/';
            strcpy(slinkfpath+pathlen,pslink);//relative to target
            pslink=slinkfpath+Ppuftph->UFTPHhostnmlen+1;           //~v5afR~
        }
//      UDIRLIST_WK_INIT(udl,wkslinkname);                         //~v6qaI~//~v6J0R~
        UDIRLIST_WK_INIT(udl,wkname,wknamew,wkslinkname);          //~v6J0I~
//      if (rc=uftpfstatudl(Ppuftph,FTPSUD_SLINK,pslink,&udl),rc)    //to chk directory//~v5afR~//~v6D0R~
        if (rc=(int)uftpfstatudl(Ppuftph,FTPSUD_SLINK,pslink,&udl),rc)    //to chk directory//~v6D0I~
        {
//          if (rc==ENOENT||rc==ENOTDIR)    //notf or path err     //~v61mR~
            if (rc==ENOENT||rc==ERROR_PATH_NOT_FOUND)    //notf or path err//~v61mI~
            {
                if (!(Gufile_opt & GFILEOPT_NOSLINKERRMSG))
                    uerrmsg("S-Link source %s for %s is not found",0,
//                          Ppudl->slink,Ppudl->name);             //~v6qaR~
                            Ppudl->pslink,Ppudl->name);            //~v6qaI~
            }
            else
                uerrmsg("invalid S-link source %s for %s,rc=%d",0,
//                          Ppudl->slink,Ppudl->name,rc);          //~v6qaR~
                            Ppudl->pslink,Ppudl->name,rc);         //~v6qaI~
			uftplog(FTPLOG_ERRM,0);	//logging errmsg               //~v61bI~
//          memset(&udl,0,sizeof(udl));                            //~v59xR~//~v6qaR~
        }
        Ppudl->srcattr=udl.attr;    //link source permission etc
        Ppudl->slinksize=udl.size;    //link source permission etc //~v59xR~
        Ppudl->slinkfdate=udl.date;    //link source permission etc//~v5a6R~
        Ppudl->slinkftime=udl.time;    //link source permission etc//~v5a6R~
		memcpy(Ppudl->slinkuname,udl.uname,sizeof(Ppudl->slinkuname));//~v5a6I~
		memcpy(Ppudl->slinkgname,udl.gname,sizeof(Ppudl->slinkgname));//~v5a6I~
    }//slink
    uftpmode2attr(Ppudl);    //after filename set to chk .xxx(hidden file)
    return 0;
}// uftpgetslinkattr
//*******************************************************
//*read slink for dirlist
//*Ppudl:udirlist from uftpopendir                                //~v6qaI~//~v6qcR~
//*******************************************************
int uftpdirlistslink(PUFTPHOST Ppuftph,char *Pfpnm,PUDIRLIST Ppudl,int Pentno)//~v5afR~
{
    PUDIRLIST pudl;
    USLCPARM uslp;
//  UDIRLIST  udl;                                                 //~v6qaR~
//  UDIRLIST_WK(udl,wkslinkname);                                  //~v6qaI~//~v6J0R~
    UDIRLIST_WK(udl,wkname,wknamew,wkslinkname);                   //~v6J0I~
    int rc=0,slinksw=0,ii;
    int stdoctr,pathlen,prevstdoctr=0;                             //~v5a1R~
    char **stdo,*pslink,**prevstdo=0,**stdo0;                      //~v5a7R~
    char fpath[FTP_MAXPATH];
//*********************************
    for (pudl=Ppudl,ii=0;ii<Pentno;ii++,pudl++)
    {
      if (!(pudl->otherflag & UDLOF_SLINKNAME_NA))	//uftpgetdl1 set FTP_SLINKNAME_NA to slinkname//~v6qeR~
    	if (S_ISLNK(FILE_GETMODE(pudl->attr)))//symbolic link
        {
//  	  if (*pudl->slink)                                        //~v61pI~//~v6qaR~
    	  if (pudl->pslink && *pudl->pslink)                       //~v6qaR~
          {                                                        //~v61pI~
//  		printf("ii=%2d:%-30s\n",ii,pudl->slink);               //~v59dR~
            slinksw=1;
            break;
          }                                                        //~v61pI~
        }
    }
    if (slinksw)
    {
        uftpsortslink(0,Ppudl,Pentno);                             //~v59dI~
    	uslp.USLpuftph=Ppuftph;	//parm to uftpslinklscmd           //~v5ksI~
    	uslp.USLpudl=Ppudl;		//parm to uftpslinklscmd
		uslp.USLpudlno=Pentno;
        if (*Pfpnm=='/')
			uslp.USLtargetfnm=Pfpnm;
        else
        {
//        	uftpfullpath(Ppuftph,fpath,Pfpnm,sizeof(fpath));       //~v5c8R~
           	uftpfullpathnorid(Ppuftph,fpath,Pfpnm,sizeof(fpath));  //~v5c8I~
			uslp.USLtargetfnm=fpath+Ppuftph->UFTPHhostnmlen+1;     //~v5afR~
        }
		rc=uftpcmd(Ppuftph,0,0,&stdo,&stdoctr,uftpslinklscmd,&uslp);	//get stdout/stderr//~v5afR~
        if (!rc)
        {
            stdo0=stdo; //free addr                                //~v5a7I~
//          UDIRLIST_WK_INIT(udl,wkslinkname);                     //~v6qaI~//~v6J0R~
            UDIRLIST_WK_INIT(udl,wkname,wknamew,wkslinkname);      //~v6J0I~
            for (pudl=Ppudl,ii=0;ii<Pentno;ii++,pudl++)
            {
        		if (!(pudl->srcattr & FILE_FTPWKSL))//not ls cmd requested
                    continue;
//              pslink=pudl->slink;                                //~v6qaR~
                pslink=pudl->pslink;                               //~v6qaI~
//UTRACEP("ftp ii=%d,%s\n",ii,pslink);                             //~v5a9R~
				pathlen=FTP_PATHLEN(pslink);
        		if (pudl->srcattr & FILE_FTPWKSL2)//same source dir as prev//~v59dI~
                {                                                  //~v59dI~
                	stdo=prevstdo;                                 //~v59dI~
                	stdoctr=prevstdoctr;                           //~v59dI~
                }                                                  //~v59dI~
                else                                               //~v59dI~
                {                                                  //~v59dI~
                	prevstdo=stdo;         //save for resore when duplicated//~v59dI~
                	prevstdoctr=stdoctr;                           //~v59dR~
                }                                                  //~v59dI~
            	*Sslinkerrmsg=0;                                   //~v6qfI~
                if (!uftplsoutchkslink(Ppuftph,0,pslink+pathlen,&udl,&stdo,&stdoctr))//~v5afR~
                {                                                  //~v5a6I~
                	pudl->srcattr=udl.attr;
        			pudl->slinksize=udl.size;    //link source permission etc//~v5a6I~
        			pudl->slinkfdate=udl.date;    //link source permission etc//~v5a6I~
        			pudl->slinkftime=udl.time;    //link source permission etc//~v5a6I~
					memcpy(pudl->slinkuname,udl.uname,sizeof(Ppudl->slinkuname));//~v5a6I~
					memcpy(pudl->slinkgname,udl.gname,sizeof(Ppudl->slinkgname));//~v5a6I~
//        		    pudl->srcattr &= ~FILE_FTPWKSL;  //slink ok    //~v5c7R~
                }                                                  //~v5a6I~
                else
                {                                                  //~v5c6I~
                  if (!(Gufile_opt & GFILEOPT_NOSLINKERRMSG))      //~v5c6I~
                  {                                                //~v61bI~
                   if (*Sslinkerrmsg)                              //~v6qfI~
//                	uerrmsg("no slink source(%s) found for target(%s) by %s",0,//~v6qfI~//~v6J0R~
//                    		pslink,pudl->name,Sslinkerrmsg);       //~v6qfR~//~v6J0R~
                  	uerrmsg("slink(%s) has no source(%s) %s",0,    //~v6J0I~
                    		pudl->name,pslink,Sslinkerrmsg);       //~v6J0I~
                   else                                            //~v6qfI~
//              	uerrmsg("no slink source(%s) found for target(%s)",0,//~v6qfR~//~v6J0R~
//                  		pslink,pudl->name);                    //~v6J0R~
                	uerrmsg("slink(%s) has no source(%s)",0,       //~v6J0I~
                    		pudl->name,pslink);                    //~v6J0I~
					uftplog(FTPLOG_ERRM,0);	//logging errmsg       //~v61bI~
                  }                                                //~v61bI~
//  		      if (Gufile_opt & GFILEOPT_IGNORESLINKERR)  //ignore slinkerr//~v5c7R~
//      		    pudl->srcattr &= ~FILE_FTPWKSL;  //slink ok    //~v5c7R~
      		      pudl->attr|=FILE_SLINKERR;  //slink err          //~v6qcI~
                }                                                  //~v5c6I~
            }//all pudl
            ufree(stdo0);                                          //~v5a7R~
        }//slink cmd ok
        uftpsortslink(1,Ppudl,Pentno);      //back to original name sequence//~v59dI~
    }
    for (pudl=Ppudl,ii=0;ii<Pentno;ii++,pudl++)
    {
//      pudl->srcattr&=~(FILE_FTPWKSL|FILE_FTPWKSL2);    //work flag to chk found//~v5c6R~
//      pudl->srcattr&=~(FILE_FTPWKSL2);    //work flag to chk found//~v5c7R~
//      pudl->srcattr&=~(FILE_FTPWKSL|FILE_FTPWKSL2);    //work flag to chk found//~v5c7I~//~v6D0R~
        pudl->srcattr&=~(ULONG)(FILE_FTPWKSL|FILE_FTPWKSL2);    //work flag to chk found//~v6D0I~
      if (Ppuftph->UFTPHflag & UFTPHFRWIN)                         //~v6d7R~
    	uftp3smb_mode2attr_win(0,Ppuftph,pudl);	//attr by attr and srcattr//~v6d7I~
      else                                                         //~v6d7I~
    	uftpmode2attr(pudl);	//attr by attr and srcattr
    }
    return rc;
}//uftpdirlistslink
//*******************************************************          //~v59dI~
//*write ftpcmd file for ls slink                                  //~v59dI~
//*******************************************************          //~v59dI~
int uftpsortslink(int Popt,PUDIRLIST Ppudl,int Pentno)             //~v59dR~
{                                                                  //~v59dI~
//*********************************                                //~v59dI~
	if (Popt==0) //before slink chk                                //~v59dR~
//      qsort(Ppudl,(UINT)Pentno,UDIRLISTSZ,uftpslinkcomp);        //~v59dR~//~v6J0R~
        udirlistsort(FTP_SORTTYPE_SLINK,Ppudl,Pentno);   //sort by slinkname//~v6J0I~
    else         //after slink chk                                 //~v59dR~
        udirlistsort('L',Ppudl,Pentno);   //sort by fullname       //~v59dR~
    return 0;                                                      //~v59dI~
}//uftpslinksort                                                   //~v59dI~
//**********************************************************************//~v59dI~
//* sort by slink name                                             //~v59dI~
//*  return code: -1: ent1<ent2                                    //~v59dI~
//*                0: ent1=ent2                                    //~v59dI~
//*                1: ent1>ent2                                    //~v59dI~
//**********************************************************************//~v59dI~
int uftpslinkcomp(const void *ent1,const void *ent2)               //~v59dI~
{                                                                  //~v59dI~
    PUDIRLIST flist1,flist2;                                       //~v59dI~
    char *pc,*pc2;                                                 //~v59dI~
//*****************                                                //~v59dI~
//  flist1=(PUDIRLIST)(ULONG)ent1;                                 //~v59dI~//~v6hhR~
    flist1=(PUDIRLIST)(ULPTR)ent1;                                 //~v6hhI~
//  flist2=(PUDIRLIST)(ULONG)ent2;                                 //~v59dI~//~v6hhR~
    flist2=(PUDIRLIST)(ULPTR)ent2;                                 //~v6hhI~
//  pc=flist1->slink;                                              //~v59dI~//~v6qaR~
    pc=flist1->pslink;                                             //~v6qaI~
    if (!pc)                                                       //~v6qaI~
    	pc=" ";                                                    //~v6qaI~
//  pc2=flist2->slink;                                             //~v59dI~//~v6qaR~
    pc2=flist2->pslink;                                            //~v6qaI~
    if (!pc2)                                                      //~v6qaI~
    	pc2=" ";                                                   //~v6qaI~
//  printf("rc=%2d:%-30s:%-30s\n",strcmp(pc,pc2),pc,pc2);          //~v59dR~
    return strcmp(pc,pc2);                                         //~v59dI~
}//uftpslinkcomp                                                   //~v59dI~
//*******************************************************
//*write ftpcmd file for ls slink
//*******************************************************
int uftpslinklscmd(FILE *Pstdin,void *Ppvoid)
{
    int ii,relbasepathlen,relbasewildpathlen,relbasewildsw,pathlen;
    PUDIRLIST pudl;
    PUFTPHOST puftph;                                              //~v5ksI~
    PUSLCPARM puslp;
    char  *pslink;
    UCHAR ftpcmd[FTP_MAXPATH+128];
    UCHAR sourcefpath[FTP_MAXPATH],*ptarget;
    UCHAR pathnm[FTP_MAXPATH];
    UCHAR prevpathnm[FTP_MAXPATH];                                 //~v59dI~
    char *listcmd;                                                 //~v5ksI~
//*********************************
	puslp=(PUSLCPARM)Ppvoid;
    puftph=puslp->USLpuftph;                                       //~v5ksI~
    listcmd=puftph->UFTPHlscmd;                                    //~v5ksI~
    ptarget=puslp->USLtargetfnm;
//  relbasepathlen=strlen(ptarget);//base of source dir            //~v6D0R~
    relbasepathlen=(int)strlen(ptarget);//base of source dir       //~v6D0I~
    relbasewildpathlen=FTP_PATHLEN(ptarget);
    relbasewildsw=WILDCARD(ptarget+relbasewildpathlen)!=0;
    *prevpathnm=0;                                                 //~v59dR~
    for (pudl=puslp->USLpudl,ii=0;ii<puslp->USLpudlno;ii++,pudl++)
    {
            UTRACEP("%s:pudl=%p,name=%s,slink=%s\n",UTT,pudl,pudl->name,pudl->pslink);//~v6J0R~
      if (!(pudl->otherflag & UDLOF_SLINKNAME_NA))	//uftpgetdl1 set FTP_SLINKNAME_NA to slinkname//~v6qeI~
    	if (S_ISLNK(FILE_GETMODE(pudl->attr)))//symbolic link
        {
//        if (*pudl->slink)		//PSFTP-v060 dosenot display slink target//~v61pI~//~v6qaR~
          if (pudl->pslink && *pudl->pslink)		//PSFTP-v060 dosenot display slink target//~v6qaR~
          {                                                        //~v61pI~
        	pudl->srcattr|=FILE_FTPWKSL;    //work flag to chk found
//          pslink=pudl->slink;                                    //~v6qaR~
            pslink=pudl->pslink;                                   //~v6qaI~
            UTRACEP("%s:slink:pudl=%p,name=%s,slink=%s\n",UTT,pudl,pudl->name,pslink);//~v6qaI~//~v6J0R~
            if (*pslink!='/')	//relative path
            {
            	if (relbasewildsw)
                    pathlen=relbasewildpathlen;
                else
                    pathlen=relbasepathlen;
                memcpy(sourcefpath,ptarget,(UINT)pathlen);
                if (*(sourcefpath+pathlen-1)!='/')
                	*(sourcefpath+pathlen++)='/';
            	strcpy(sourcefpath+pathlen,pslink);//relative to target
                pslink=sourcefpath;
            }
			uftpgetpathname(pslink,pathnm,sizeof(pathnm));
            if (strcmp(pathnm,prevpathnm))	//name changed         //~v59dI~
            {                                                      //~v59dI~
                sprintf(ftpcmd,                                    //~v59dR~
                        "cd \"%s\"\n"      \
//                      "ls -la\n",                                //~v5ksR~
                        "%s\n",   \
//                      pathnm);                                   //~v5ksR~
                        pathnm,listcmd);                           //~v5ksI~
//              fprintf(Pstdin,ftpcmd);                            //~v59dR~//~v6DiR~
                fprintf(Pstdin,"%s",ftpcmd);                       //~v6DiI~
                uftplog(0,ftpcmd);                                 //~v59dR~
                strcpy(prevpathnm,pathnm);                         //~v59dI~
                UTRACEP("ftpslinklscmd cmd=%s\n",ftpcmd);          //~v6qaI~
            }                                                      //~v59dI~
            else                                                   //~v59dI~
            	pudl->srcattr|=FILE_FTPWKSL2;	//dup id for performance up//~v5a9R~
          }//null target                                           //~v61pI~
        }
    }
    return 0;
}//uftpslinklscmd
//*******************************************************
//*set ffb3 from stdo
//*******************************************************
int uftplsoutchk(PUFTPHOST Ppuftph,int Popt,char *Pfname,PUDIRLIST Ppudl,char **Pstdo,int Pstdoctr)//~v5afR~
{
    int rc=FTPRC_PARSEERR,rc2;
    int stdoctr;
    char **stdo;
//  UDIRLIST_WK(udlhome,wkslinkname);                              //~v6qaI~//~v6J0R~
    UDIRLIST_WK(udlhome,wkname,wknamew,wkslinkname);               //~v6J0I~
//*********************************
	stdo=Pstdo;
    stdoctr=Pstdoctr;
    for (;;)
    {
//cd
		if (Popt & UFFSO_CD)	//cd issued
        {                                                          //~v61pI~
//          if (rc2=uftpcmdsrchrespid(&stdo,&stdoctr,"250 5** "),rc2) //CD ok or no such file//~v61pR~
          	if (UFTPHISPSFTP(Ppuftph))                             //~v61pR~
				rc2=uftp3cdrespchk(0,Ppuftph,Pfname,&stdo,&stdoctr);//~v61pI~
          	else                                                   //~v61pI~
            	rc2=uftpcmdsrchrespid(&stdo,&stdoctr,"250 5** "); //CD ok or no such file//~v61pI~
            if (rc2) //CD ok or no such file                       //~v61pI~
            {
                if (rc2==1)       //550:no such file
//                  rc=ENOTDIR;                                    //~v61mR~
                    rc=ERROR_PATH_NOT_FOUND;      	//!=ENOTDIR(20) on Windows//~v61mI~
            }
        }                                                          //~v61pI~
//ls
	  if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
    	rc2=uftpcmdsrchrespid(&stdo,&stdoctr,FTP_PSFTP_OK_LIST); //Listing directory ____//~v61pI~
      else                                                         //~v61pI~
    	rc2=uftpcmdsrchrespid(&stdo,&stdoctr,"150 "); //150:open data connection
        if (rc2 || rc!=FTPRC_PARSEERR)  //not found or rc changed  //~v59dR~
            break;
		rc2=uftpsrchfname(Ppuftph,stdo,stdoctr,Pfname,Ppudl);      //~v5afR~
		if (rc2==EPERM && Popt & UFFSO_HOME)	//open failed for home dir//~v61cI~
        {                                                          //~v61cI~
//  	    UDIRLIST_WK_INIT(udlhome,wkslinkname);                 //~v6qaI~//~v6J0R~
    	    UDIRLIST_WK_INIT(udlhome,wkname,wknamew,wkslinkname);  //~v6J0I~
//      	if (!uftplshome(Ppuftph,Popt,Pfname,Ppudl))	//udirlist filled//~v61cI~//~v6qaR~
        	if (!uftplshome(Ppuftph,Popt,Pfname,&udlhome))	//udirlist filled//~v6qaI~
            {                                                      //~v61cI~
                UTRACED("Ppudl old",Ppudl,UDIRLISTSZ);             //~v6J0I~
            	UDIRLIST_COPY(Ppudl,&udlhome);                     //~v6qaI~
                UTRACED("Ppud newl",Ppudl,UDIRLISTSZ);             //~v6J0I~
                rc=0;                                              //~v61cI~
            	break;                                             //~v61cI~
            }                                                      //~v61cI~
        }                                                          //~v61cI~
    	if (rc2)	//ls has no msg;dir fail
        {
//  		rc=ENOENT;                                             //~v61aR~
    		rc=rc2;                                                //~v61aI~
    		break;
        }
	  if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
      {                                                            //~v61pI~
    	rc2=uftpcmdsrchrespid(&stdo,&stdoctr,FTP_ECHO_PSFTP_ID); //modtime//~v61pR~
        if (rc2)                                                   //~v61pI~
            break;                                                 //~v61pI~
      }                                                            //~v61pI~
      else                                                         //~v61pI~
      {                                                            //~v61pI~
    	rc2=uftpcmdsrchrespid(&stdo,&stdoctr,FTPRESPID_XCOMP); //226:xfer comp//~v59dI~
        if (rc2)                                                   //~v59dI~
            break;                                                 //~v59dI~
		uftpmodtimerchk(Ppuftph,stdo,stdoctr,Ppudl);               //~v5afR~
      }                                                            //~v61pI~
        rc=0;
        break;
    }//rc chk
    return rc;
}//uftplsoutchk
//**************************************************************** //~v59dI~
//ftp cmd result chk                                               //~v59dI~
//*retrn:rc                                                        //~v59dI~
//**************************************************************** //~v59dI~
int uftpmodtimerchk(PUFTPHOST Ppuftph,char **Ppstdo,int Pstdoctr,PUDIRLIST Ppudl)//~v5afR~
{                                                                  //~v59dI~
    int rc,stdoctr,hh,mm,ss,gmtsw;                                 //~v5acR~
    int len,len1,len2,len3,yy,mt,dd;                               //~v5diR~
    char *pc,*rec,**stdo;                                          //~v59dI~
    char *pcdate,*pc3,*pc2,*pc1;                                   //~v5diR~
//****************************                                     //~v59dI~
	stdoctr=Pstdoctr;                                              //~v59dR~
    if (!stdoctr)                                                  //~v59dI~
    	return 4;                                                  //~v59dI~
    stdo=Ppstdo;                                                   //~v59dR~
    rec=*stdo;                                                     //~v59dI~
    rc=4;                                                          //~v59dI~
    for (;;)                                                       //~v5a1R~
    {                                                              //~v59dI~
        if (Ppuftph->UFTPHflag & UFTPHFMODTERR)                    //~v61dI~
            break;                                                 //~v61dI~
        if (*rec=='5') 	//failed retcode 502:not implemented,505 could not get//~v59dI~
        {                                                          //~v61dI~
			uftpmodtimeerr(Ppuftph);                               //~v61dI~
        	break;                                                 //~v59dI~
        }                                                          //~v61dI~
        if (ustrstri(rec,"Invalid"))//not supported                //~v59dR~
        {                                                          //~v61dI~
			uftpmodtimeerr(Ppuftph);                               //~v61dI~
        	break;                                                 //~v59dI~
        }                                                          //~v61dI~
        if (!(pc=strchr(rec,':')))	//search hh:mm:ss pos          //~v59dR~
        	break;                                                 //~v59dI~
        pc-=2; //hh                                                //~v59dR~
        pcdate=pc-1;//date end addr "mm/dd/yyyy hh:mm:ss GMT"      //~v5diI~
        if (unumlen(pc,UNUMLEN_SPACE,3)!=2)                        //~v59dI~
        	break;                                                 //~v59dI~
        hh=atoi(pc);                                               //~v59dI~
        pc+=3;                                                     //~v59dI~
        if (unumlen(pc,UNUMLEN_SPACE,3)!=2)                        //~v59dI~
        	break;                                                 //~v59dI~
        mm=atoi(pc);                                               //~v59dI~
        pc+=3;                                                     //~v59dI~
        if (unumlen(pc,UNUMLEN_SPACE,3)!=2)                        //~v59dI~
        	break;                                                 //~v59dI~
        ss=atoi(pc);                                               //~v59dI~
        pc+=2;                                                     //~v5acI~
//      gmtsw=(strstr(pc,"GMT")!=0);                               //~v615R~
        gmtsw=(ustrstri(pc,"GMT")!=0);                             //~v615I~
//      Ppudl->time.hours=hh;                                      //~v59dR~//~v6BMR~
//      Ppudl->time.hours=(USHORT)hh;                              //~v6BMR~//~v6D2R~
//      Ppudl->time.minutes=mm;                                    //~v59dR~//~v6BMR~
//      Ppudl->time.minutes=(USHORT)mm;                            //~v6BMR~//~v6D2R~
//      Ppudl->time.twosecs=ss/2;      //for savetime chk          //~v59dR~//~v6BMR~
//      Ppudl->time.twosecs=(USHORT)(ss/2);      //for savetime chk//~v6BMR~//~v6D2R~
        ueditsetftimeUSHORT(0,hh,mm,ss/2,&Ppudl->time);            //~v6D2R~
//get date                                                         //~v5diI~
//		len=(int)((ULONG)pcdate-(ULONG)rec);//len before time string//~v5diR~//~v6hhR~
  		len=(int)((ULPTR)pcdate-(ULPTR)rec);//len before time string//~v6hhI~
        len-=(int)umemrspn(rec," \t",(UINT)len);//len up to date string end//~v5diR~
        pc3=umemrchr(rec,'/',(UINT)len);//last digit len           //~v5diR~
//      len3=len-((ULONG)pc3-(ULONG)rec+1);//last digit len        //~v5diR~//~v6hhR~
//      len3=len-((ULPTR)pc3-(ULPTR)rec+1);//last digit len        //~v6hhI~//~v6D0R~
        len3=len-(PTRDIFF(pc3,rec)+1);//last digit len             //~v6D0I~
        if (pc3 && (len3==4||len3==2) && unumlen(pc3+1,0,len3)==len3)		//yyyy or dd//~v5diR~
        {                                                          //~v5diI~
        	pc3++;                                                 //~v5diI~
        	len-=len3+1;                                           //~v5diR~
        	pc2=umemrchr(rec,'/',(UINT)len);//last digit len       //~v5diR~
//	        len2=len-((ULONG)pc2-(ULONG)rec+1);//last digit len    //~v5diR~//~v6hhR~
//          len2=len-((ULPTR)pc2-(ULPTR)rec+1);//last digit len    //~v6hhI~//~v6D0R~
            len2=len-(PTRDIFF(pc2,rec)+1);//last digit len         //~v6D0I~
            if (pc2 && len2==2 && unumlen(pc2+1,0,len2)==len2)	//mm or dd//~v5diR~
            {                                                      //~v5diI~
            	pc2++;                                             //~v5diI~
	        	len-=len2+1;                                       //~v5diR~
    	    	pc1=umemrpbrk(rec," \t",(UINT)len);//last digit len//~v5diR~
//		        len1=len-((ULONG)pc1-(ULONG)rec+1);//last digit len//~v5diR~//~v6hhR~
//  	        len1=len-((ULPTR)pc1-(ULPTR)rec+1);//last digit len//~v6hhI~//~v6D0R~
    	        len1=len-(PTRDIFF(pc1,rec)+1);//last digit len     //~v6D0I~
                if (pc1 && (len1==4||len1==2) && unumlen(pc1+1,0,len1)==len1)	//yyyy or mm//~v5diR~
                {                                                  //~v5diI~
                	pc1++;                                         //~v5diR~
                    if (len1==4)    //yyyy/mm/dd fmt               //~v5diI~
                    {                                              //~v5diI~
                        yy=atoi(pc1);                              //~v5diI~
                        mt=atoi(pc2);                              //~v5diI~
                        dd=atoi(pc3);                              //~v5diI~
                    }                                              //~v5diI~
                    else            //mm/dd/yyyy fmt               //~v5diI~
                    {                                              //~v5diI~
                        yy=atoi(pc3);                              //~v5diI~
                        mt=atoi(pc1);                              //~v5diI~
                        dd=atoi(pc2);                              //~v5diI~
                    }                                              //~v5diI~
//                  Ppudl->date.year=yy-1980;                      //~v5diR~//~v6BMR~
//                  Ppudl->date.year=(USHORT)(yy-1980);            //~v6BMR~//~v6D2R~
//                  Ppudl->date.month=mt;                          //~v5diI~//~v6BMR~
//                  Ppudl->date.month=(USHORT)mt;                  //~v6BMR~//~v6D2R~
//                  Ppudl->date.day=dd;                            //~v5diI~//~v6BMR~
//                  Ppudl->date.day=(USHORT)dd;                    //~v6BMR~//~v6D2R~
        			ueditsetfdateUSHORT(0,yy-1980,mt,dd,&Ppudl->date);//~v6D2R~
                }                                                  //~v5diI~
            }                                                      //~v5diI~
        }                                                          //~v5diI~
    if (gmtsw)                                                     //~v5acI~
//		uftpmajustjst(Ppuftph,&Ppudl->date,&Ppudl->time);          //~v5deR~
  		uftpajustjst(UFAJO_GMT,Ppuftph,&Ppudl->date,&Ppudl->time);  //not use xehosts tz but ftime//~v5deI~
    else                                                           //~v5diI~
  		uftpajustjst(0,Ppuftph,&Ppudl->date,&Ppudl->time);  //not use xehosts tz but ftime//~v5diI~
//      Ppudl->attr|=FILE_FTPJST;                                  //~v5deR~
        rc=0;                                                      //~v59dI~
        break;                                                     //~v59dI~
    }                                                              //~v59dI~
    return rc;                                                     //~v59dI~
}//uftpmodtimerchk                                                 //~v59dI~
//*******************************************************          //~v61dI~
//*set modtime not supported                                       //~v61dI~
//*******************************************************          //~v61dI~
int uftpmodtimeerr(PUFTPHOST Ppuftph)                              //~v61dI~
{                                                                  //~v61dI~
    Ppuftph->UFTPHflag|=UFTPHFMODTERR;                             //~v61dI~
    uerrmsg("\"modtime\" is not supported",0);                     //~v61dR~
    uftplog(FTPLOG_ERRM,0); //logging errmsg                       //~v61dI~
    ugeterrmsg();   //clear errmsg after loghging                  //~v61dI~
    return 0;                                                      //~v61dI~
}//uftpmodtimeerr                                                  //~v61dR~
//*******************************************************          //~v6qfI~
//*chk slink search;skip to next cmd beyond change dit failed      //~v6qfI~
//*rc:0 skipped to end of "dir" response                           //~v6qfI~
//*******************************************************          //~v6qfI~
int uftplsoutchkslinkerrskip(char **Ppstdo0,int Ppstdoctr0,char ***Ppstdo,int *Ppstdoctr)//~v6qfI~
{                                                                  //~v6qfI~
    int rc=4,rc2;                                                  //~v6qfI~
    int stdoctr;                                                   //~v6qfI~
    char **stdo,**stdoprev;                                        //~v6qfR~
//*********************************                                //~v6qfI~
	stdo=*Ppstdo;                                                  //~v6qfI~
    stdoctr=*Ppstdoctr;                                            //~v6qfI~
    if (stdoctr-2<=Ppstdoctr0)	//2 line before                    //~v6qfI~
    {                                                              //~v6qfI~
        stdoprev=stdo-2;                                           //~v6qfR~
        if (!memcmp(*stdoprev,"cd ",3))                            //~v6qfR~
        {                                                          //~v6qfI~
    		rc2=uftpcmdsrchrespid(&stdo,&stdoctr,"150 5** "); //150:open data connection//~v6qfR~
            if (!rc2)     //dir cmd response                       //~v6qfI~
            {                                                      //~v6qfI~
	    		rc2=uftpcmdsrchrespid(&stdo,&stdoctr,"226 5** "); //request succeeded//~v6qfI~
                if (!rc2)                                          //~v6qfI~
                {                                                  //~v6qfI~
                    *Ppstdo=stdo;                                  //~v6qfI~
                    *Ppstdoctr=stdoctr;                            //~v6qfI~
                    rc=0;                                          //~v6qfI~
                }                                                  //~v6qfI~
            }                                                      //~v6qfI~
            sprintf(Sslinkerrmsg,"%s;%s(chroot is configured?)",*stdoprev,*(stdoprev+1)); //~v6qfR~//~v6qeR~
    	}                                                          //~v6qfI~
    }                                                              //~v6qfI~
    return rc;                                                     //~v6qfI~
}//uftplsoutchkslinkerrskip                                        //~v6qfI~
//*******************************************************
//*set ffb3 from stdo
//*******************************************************
int uftplsoutchkslink(PUFTPHOST Ppuftph,int Popt,char *Pslink,PUDIRLIST Ppudl,char ***Ppstdo,int *Ppstdoctr)//~v5afR~
{
    int rc;
    int stdoctr;
    char **stdo;
//*********************************
	stdo=*Ppstdo;
    stdoctr=*Ppstdoctr;
  if (UFTPHISPSFTP(Ppuftph))                                       //~v61pI~
    rc=uftpcmdsrchrespid(&stdo,&stdoctr,FTP_PSFTP_OK_LIST); //Listing directory ____//~v61pI~
  else                                                             //~v61pI~
  {                                                                //~v6qfI~
    rc=uftpcmdsrchrespid(&stdo,&stdoctr,"150 5** "); //150:open data connection//~v5arR~
    if (rc==1)  //detected 5**                                     //~v6qfI~
        uftplsoutchkslinkerrskip(*Ppstdo,*Ppstdoctr,&stdo,&stdoctr);//~v6qfR~
  }                                                                //~v6qfI~
    if (!rc)
    	rc=uftpsrchfnameslink(Ppuftph,&stdo,&stdoctr,Pslink,Ppudl);//~v5afR~
	*Ppstdo=stdo;
    *Ppstdoctr=stdoctr;
    return rc;
}//uftplsoutchkslink
//*******************************************************
//*save hdir and requested attrib for findnext
//*return:handle(entno+1)
//*******************************************************
int uftpsavehdir(PUFTPHOST Ppuftph,PUDIRLIST Ppudl,char *Pwild,ULONG Pattr,int *Pphdir)//~v5afR~
{
    int ii,rc=0;
    PUFTPDIRH pfdh;
//*************
	*Pphdir=0;
    for (ii=0,pfdh=Sfdh;ii<MAXHDIR;ii++,pfdh++)
        if (!pfdh->UFTPDHpudl)
        {
            pfdh->UFTPDHpudl=Ppudl;
            pfdh->UFTPDHpuftph=Ppuftph; //node tbl                 //~v5afI~
            if (Pwild)
	            strncpy(pfdh->UFTPDHwild,Pwild,sizeof(pfdh->UFTPDHwild));
            else
            	*pfdh->UFTPDHwild=0;
            pfdh->UFTPDHattr=Pattr;
	        pfdh->UFTPDHnpos=0;
//  		*Pphdir=ii+FTP_HDIRID;                                 //~v6D0R~
    		*Pphdir=ii+(int)FTP_HDIRID;                            //~v6D0I~
            break;
        }
    if (ii==MAXHDIR)
    {
        uerrmsg("Pending FindFirst HANDLE overflow(max %d)",
                "ŽdŠ|‚©‚è’†‚Ì FindFirst ‚Ì§ŒÀ’´(Å‘å %d)",
                    MAXHDIR);
        rc=ERROR_TOO_MANY_OPEN_FILES;
		uftplog(FTPLOG_ERRM,0);	//logging errmsg                   //~v61bI~
    }
    return rc;
}//uftpsavehdir
//*******************************************************
//*search hdir table when findnext
//*return:UFTPDIRH or 0
//*******************************************************
PUFTPDIRH uftpsrchhdir(ULONG Phdir)
{
    int indx;
	PUFTPDIRH pfdh;
//*************
    if ((Phdir & FTP_HDIRMASK)!=FTP_HDIRID)	//special hdir for FTP
        return 0;
    indx=(Phdir & FTP_HDIRIDXMASK);	//special hdir for FTP
    if (indx>=MAXHDIR)
        return 0;
    pfdh=Sfdh+indx;
    if (!pfdh->UFTPDHpudl)
        return 0;
    return pfdh;
}//uftpsrchhdir
//*******************************************************
//*clear hdir table when findclose
//*return:0 or 4(not found)
//*******************************************************
int uftpclosehdir(int Phdir)
{
    PUFTPDIRH pfdh;
//*************
//  pfdh=uftpsrchhdir(Phdir);                                      //~v6D0R~
    pfdh=uftpsrchhdir((ULONG)Phdir);                               //~v6D0I~
    if (!pfdh)
        return ERROR_INVALID_HANDLE;
//	ufree(pfdh->UFTPDHpudl);		//free mdir list,top word is ptr//~v6qaR~
  	UDIRLIST_FREE(pfdh->UFTPDHpudl);		//free mdir list,top word is ptr//~v6qaI~
  	pfdh->UFTPDHpudl=0;		//free mdir list,top word is ptr
    return 0;
}//uftpclosehdir
//*******************************************************
//*set attr from  mode and slink mode
//*parm :findbuff3
//*return:attr
//*******************************************************
ULONG uftpmode2attr(PUDIRLIST Ppudl)
{
    ULONG attr=FILE_REMOTE;
    ULONG mode,modew;
//*************
    mode=FILE_GETMODE(Ppudl->attr);
    UTRACEP("uftpmode2attr name=%s,slink=%s,attr=%x,mode=%x,slink=%x\n",Ppudl->name,Ppudl->pslink,Ppudl->attr,mode,S_ISLNK(mode));//~v6qcR~
    if (S_ISLNK(mode))
    {                                                              //~v5mQI~
    	modew=FILE_GETMODE(Ppudl->srcattr);	//slink attr
#ifdef UTF8SUPPH                                                   //~v5mQI~
//      attr|=FILE_SLINK;                                          //~v5mQI~//~v6qcR~
        attr|=FILE_SLINK|(Ppudl->attr & FILE_SLINKERR);            //~v6qcI~
#endif                                                             //~v5mQI~
    	UTRACEP("uftpmode2attr slink attr=%x\n",attr);             //~v6qcI~
    }                                                              //~v5mQI~
    else
    	modew=mode;
    if (S_ISDIR(modew))
        attr|=FILE_DIRECTORY;
    if (S_ISCHR(modew) 	//char device
    ||  S_ISBLK(modew)  //blk device
    ||  S_ISFIFO(modew) //pipe
    ||  S_ISSOCK(modew)) //socket
        attr|=FILE_SPECIAL;
    if (!((mode & S_IWOTH) || (mode & S_IWGRP) || (mode & S_IWUSR))
    &&   ((mode & S_IROTH) || (mode & S_IRGRP) || (mode & S_IRUSR)))
        attr|=FILE_READONLY;
    Ppudl->attr=FILE_SETMODEATTR(mode,attr);
    UTRACEP("uftpmode2attr slink pudlattr=%x\n",Ppudl->attr);      //~v6qcI~
    return attr;
}//uftpmode2attr
//*******************************************************
//*set from udtpstat to ffb3
//*******************************************************
void uftpudl2ffb3(PUDIRLIST Ppudl,FILEFINDBUF3 *Ppffb3)
{
    memset(Ppffb3,0,sizeof(FILEFINDBUF3));                         //~v5aiI~
#ifdef W32
	strncpy(Ppffb3->cFileName,Ppudl->name,sizeof(Ppffb3->cFileName));
	*Ppffb3->achName=0;
#else
	strncpy(Ppffb3->achName,Ppudl->name,sizeof(Ppffb3->achName));
#endif
	Ppffb3->cbFile=Ppudl->size;
	Ppffb3->fdateLastWrite=Ppudl->date;
	Ppffb3->ftimeLastWrite=Ppudl->time;
	Ppffb3->attrFile=Ppudl->attr;	//ufilegetmdosdl can set attr by dosdir cmd
    Ppffb3->srcattr=Ppudl->srcattr;	//ufilegetmdosdl can set attr by dosdir cmd
//  memcpy(Ppffb3->slink,Ppudl->slink,sizeof(Ppffb3->slink));      //~v6qaR~
    if (Ppudl->pslink)                                             //~v6qaI~
    	UstrncpyZ(Ppffb3->slink,Ppudl->pslink,sizeof(Ppffb3->slink));//~v6qaR~
	memcpy(Ppffb3->uname,Ppudl->uname,sizeof(Ppffb3->uname));
	memcpy(Ppffb3->gname,Ppudl->gname,sizeof(Ppffb3->gname));
#ifdef UNX                //smbclient show not uname/gname but uid/gid//~v6d7I~
	Ppffb3->uid=Ppudl->uid;                                        //~v6d7I~
	Ppffb3->gid=Ppudl->gid;                                        //~v6d7I~
#endif                                                             //~v6d7I~
    Ppffb3->slinksize=Ppudl->slinksize;                            //~v59dI~
    Ppffb3->slinkfdate=Ppudl->slinkfdate;                          //~v59dI~
    Ppffb3->slinkftime=Ppudl->slinkftime;                          //~v59dI~
	memcpy(Ppffb3->slinkuname,Ppudl->slinkuname,sizeof(Ppffb3->slinkuname));//~v5a6I~
	memcpy(Ppffb3->slinkgname,Ppudl->slinkgname,sizeof(Ppffb3->slinkgname));//~v5a6I~
    return;
}//uftpudl2ffb3
//*******************************************************
//*set from udtpstat to ffb3
//*******************************************************
int uftpgetpathname(char *Pfpath,char *Ppath,int Plen)
{
	int pathlen;
//*******************************
    pathlen=FTP_PATHLEN(Pfpath);
    if (pathlen>Plen)
    	pathlen=Plen;
    if (pathlen==1)	//root
    {
    	*Ppath=*Pfpath;
    	*(Ppath+1)=0;
    }
    else
    if (pathlen>1)	//root
    {
    	memcpy(Ppath,Pfpath,(UINT)(pathlen-1));
    	*(Ppath+pathlen-1)=0;
    }
    else
		*Ppath=0;
    return pathlen;
}//uftpgetpathname
//*******************************************************
//*searc node table by nodeid
//*******************************************************
PUFTPHOST uftpnodesrch(char *Pnode)
{
	PUFTPHOST puftph;
//************************
	for (puftph=UGETQTOP(&Suftphqh);puftph;puftph=UGETQNEXT(puftph))
	{
      if (puftph->UFTPHflag & UFTPHFTSO)    //host is tso          //~v5jzI~
      {                                                            //~v5jzI~
		if (!stricmp(puftph->UFTPHhost,Pnode))                     //~v5jzI~
            return puftph;                                         //~v5jzI~
      }                                                            //~v5jzI~
      else                                                         //~v5jzI~
		if (!strcmp(puftph->UFTPHhost,Pnode))
            return puftph;
	}
	return 0;
}//uftpnodesrch
//*******************************************************
//*add entry to node tbl
//*rc:0:added,1:rep,UALLOC_FAILED
//*******************************************************
int uftpnodeadd(PUFTPHOST Ppuftph)                                 //~v5afR~
{
	PUFTPHOST puftph;
    int rc;                                                        //~v5afR~
//************************
	if (puftph=uftpnodesrch(Ppuftph->UFTPHhost),!puftph)           //~v5afR~
    {
    	puftph=ucalloc(1,UFTPHOSTSZ);
        UALLOCCHK(puftph,UALLOC_FAILED);
        memcpy(puftph,Ppuftph,sizeof(UFTPHOST));                   //~v5afR~
        memset(&(puftph->UFTPHqe),0,sizeof(puftph->UFTPHqe));      //~v5afI~
        UENQ(UQUE_END,&Suftphqh,puftph);
        rc=0;	//added
    }
    else
    {                                                              //~v5afI~
//  	memcpy(&(Ppuftph->UFTPHqe),&(puftph->UFTPHqe),sizeof(Ppuftph->UFTPHqe));//~v5bbR~
//      memcpy(puftph,Ppuftph,sizeof(UFTPHOST));                   //~v5bbR~
        rc=1;   //replaced
    }                                                              //~v5afI~
	return rc;
}//uftpnodeadd
//*******************************************************
//*del entry from node tbl
//*******************************************************
int uftpnodedel(char *Pnode)
{
	PUFTPHOST puftph;
//************************
	if (puftph=uftpnodesrch(Pnode),!puftph)
    	return 4;
    UDEQ(UQUE_ENT,&Suftphqh,puftph);
    ufree(puftph);
	return 0;
}//uftpnodedel
//*******************************************************
//*del all entry from node tbl
//*******************************************************
void uftpnodeclear(void)
{
//  PUQUEE pqe;                                                    //~v5bbR~
//************************
//  UQFREE(&Suftphqh);                                             //~v5a1R~
//    while(pqe=udeq(UQUE_TOP,&Suftphqh,0),pqe)   //entry exist    //~v5bbR~
//        ufree(pqe);                                              //~v5bbR~
    UQUFREE(&Suftphqh);	//use ufree                                //~v5bbI~
	return;
}//uftpnodeclear
//*******************************************************
//*return qh addr
//*******************************************************
UQUEH *uftpgethostqhaddr(void)
{
//************************
	return &Suftphqh;
}//uftpgethostqhaddr
//*******************************************************
//*return qh addr
//*******************************************************
int uftphoststbinit(char *Phostsfnm)
{
#define HOSTSRECLEN 512
    char buff[HOSTSRECLEN];
	FILE *fh;
	UFTPHOST ufh;
//  int errctr=0,linectr=0,len,rc2;                                //~v6h7R~
    int errctr=0,linectr=0,len,rc2=0;                              //~v6h7I~
    FILEFINDBUF3 ffb3;                                             //~v6qgI~
//************************
	if (ufstat(Phostsfnm,&ffb3))                                   //~v6qgR~
    	return ufilenotfound(Phostsfnm,4);                         //~v6qgR~
    strcpy(Gftpclient,FTP_VALUE_PSFTP);   //default psftp cmd name //~v61pR~
    Gftpopt&=~GFTPO_PSFTPALL;                                      //~v61pI~
    fh=fopen(Phostsfnm,"r");
    if (!fh)
    {
    	ufileapierr("ftp hosts file open",Phostsfnm,errno);
        return 4;
    }
    while (fgets(buff,HOSTSRECLEN,fh))
    {
    	linectr++;
//  	len=strlen(buff);                                          //~v6D0R~
    	len=(int)strlen(buff);                                     //~v6D0I~
        if (len && *(buff+len-1)=='\n')
        {
            len--;
            *(buff+len)=0;
        }
        if (len && *(buff+len-1)=='\r') 	//0x0d                 //~v5baI~
        {                                                          //~v5baI~
            len--;                                                 //~v5baI~
            *(buff+len)=0;                                         //~v5baI~
        }                                                          //~v5baI~
        if (linectr==1)                                            //~v6qgI~
                                                                   //~v6qgI~
        memset(&ufh,0,sizeof(ufh));                                //~v5afI~
//  	rc2=uftpgethostsdata(buff,len,&ufh);                       //~v6qeR~
    	rc2=uftpgethostsdata(0,buff,len,&ufh);                     //~v6qeI~
        if (rc2==1)  	//comment line
        	continue;
        if (rc2)
        {
        	errctr++;
            continue;
        }
        rc2=uftpnodeadd(&ufh);                                     //~v5afR~
        if (rc2==UALLOC_FAILED)
        	break;
        if (rc2)
        {
            uerrmsg("duplicated ftp hosts entry:%s",0,
        				ufh.UFTPHhost);
        	errctr++;
        }
    }
    fclose(fh);
    if (rc2==UALLOC_FAILED)
     	return UALLOC_FAILED;
    if (errctr)
    {
//  	uerrmsg("ftp hosts file(%s) has format err %d of %d",0,    //~v5ksR~
//  	uerrmsg("ftp hosts file(%s) has format err %d/%d lines",0, //~v61eR~
    	uerrmsgcat(";ftp hosts file(%s) has format err %d/%d lines",0,//~v61eR~
        		Phostsfnm,errctr,linectr);
        return 8;
    }
    return 0;
}//uftphoststbinit
//****************************************************************
//* get hosts data
//* rc:0:ok, 1:comment line, 4:err                                 //~v5boR~
//****************************************************************
//int uftpgethostsdata(char *Pdata,int Plen,PUFTPHOST Ppufh)       //~v6qeR~
int uftpgethostsdata(int Popt,char *Pdata,int Plen,PUFTPHOST Ppufh)//~v6qeI~
{
    char *pnode,*puser,*ppswd,*pipaddr,*pcwd,*pbuff,*pc;           //~v5boR~
    char *pdelmstr=" \t";
    char *popttso;                                                 //~v5mGI~
    int swerrtsooption;                                            //~v5mGI~
    int len,opdno,rc,ii,signsw,hh,mm,opt;                          //~v5bnR~
    int numlen;                                                    //~v5mGI~
    ULONG xipa;
    UCHAR  **pargc;
    void   *pargc0;                                                //~v5a7I~
    char   crptpswd[FTP_PSWDNAMELEN];                              //~v5boR~
#define MIN_PARMNO 4 //id,ipaddr,uid,pswd,cwd
//*****************
    memset(Ppufh,0,UFTPHOSTSZ);
    if (Gftpopt & GFTPO_PSFTPALL)                                  //~v61pI~
    {                                                              //~v6d6I~
        Ppufh->UFTPHflag|=UFTPHFPSFTP;                             //~v61pR~
    	Ppufh->UFTPHflag|=UFTPHFMODTERR;                         //~v6d6I~//~v6d1R~
    }                                                              //~v6d6I~
    strcpy(Ppufh->UFTPHlscmd,UFTPHLSCMD_NEW);	//default ls by "dir"//~v5ksI~
//  pbuff=umalloc(Plen+1);	//to pad null                          //~v61pR~
//  pbuff=umalloc(Plen+32);	//to pad null                          //~v61pI~//~v6D0R~
    pbuff=umalloc((size_t)Plen+32);	//to pad null                  //~v6D0I~
    UALLOCCHK(pbuff,UALLOC_FAILED);
//  memcpy(pbuff,Pdata,Plen);                                      //~v6D0R~
    memcpy(pbuff,Pdata,(size_t)Plen);                              //~v6D0I~
    *(pbuff+Plen)=0;
    for (rc=4;;)
    {
    	opt=UPARSETABISSPACE;                                      //~v5bnI~
        pc=strchr(pbuff,'#');                                      //~v5f0R~
        if (pc && *(pc+1)==FTP_HDR_PARMID)                         //~v61pI~
        {                                                          //~v61pI~
        	uftp3setssh(0,0,pc,0);                                 //~v61pR~
        	rc=1;	//processed no need more                       //~v61pR~
	        pargc0=0;    //avoid free                              //~v61pI~
	        break;                                                 //~v61pR~
        }                                                          //~v61pI~
        if (pc)                                                    //~v5f0I~
        	if (pc==pbuff                                          //~v5f0I~
            ||  *(pc-1)==' '                                       //~v5f0I~
            ||  *(pc-1)=='\t')                                     //~v5f0I~
            	*pc=0;		//cut line comment                     //~v5f0I~
        uparsev(pbuff,&pargc,&opdno,opt,pdelmstr);//no ignore crlf,no delmstr//~v5bnR~
//      pargc0=(void*)(ULONG)pargc;   //free area                  //~v5a7I~//~v6hhR~
        pargc0=(void*)(ULPTR)pargc;   //free area                  //~v6hhI~
//      if (*pargc[0]=='#')    //comment line                      //~v5f0R~
//      {                                                          //~v5f0R~
//          rc=1;                                                  //~v5f0R~
//          break;                                                 //~v5f0R~
//      }                                                          //~v5f0R~
        if (!opdno)    //comment line                              //~v5f0I~
        {                                                          //~v5f0I~
            rc=1;                                                  //~v5f0I~
            break;                                                 //~v5f0I~
        }                                                          //~v5f0I~
        if (opdno<MIN_PARMNO)                                      //~v5boR~
        {
            uerrmsg("hosts line data fmt is \"id ipaddr uid pswd init-dir\"\n",0);
            break;
        }
//hostid
        pnode=pargc[0];
//      if (*pnode=='#')    //comment line                         //~v5d0R~
//      {                                                          //~v5d0R~
//          rc=1;                                                  //~v5d0R~
//          break;                                                 //~v5d0R~
//      }                                                          //~v5d0R~
//      len=strlen(pnode);                                         //~v6D0R~
        len=(int)strlen(pnode);                                    //~v6D0I~
        if (len<2||len>FTP_HOSTNAMELEN)     //nodeid must be over 2 byte
        {
            uerrmsg("hostid(%s) len should be 2 to %d",0,          //~v59dR~
                    pnode,FTP_HOSTNAMELEN);                        //~v59dR~
            break;
        }
        memcpy(Ppufh->UFTPHhost,pnode,(UINT)len);
        Ppufh->UFTPHhostnmlen=len;                                 //~v5afI~
//ipaddr
        pipaddr=pargc[1];
//      len=strlen(pipaddr);                                       //~v6D0R~
        len=(int)strlen(pipaddr);                                  //~v6D0I~
        if (len>FTP_IPADNAMELEN)    //nodeid must be over 2 byte
        {
            uerrmsg("ip-addr len should be up to %d",0,
                    FTP_IPADNAMELEN);
            break;
        }
        memcpy(Ppufh->UFTPHipad,pipaddr,(UINT)len);
        if (uftpipachk(Ppufh->UFTPHipad,&xipa))
        {
            uerrmsg("ip-addr(%s) format err",0,
                    Ppufh->UFTPHipad);
            break;
        }
//username
        puser=pargc[2];
//      len=strlen(puser);                                         //~v6D0R~
        len=(int)strlen(puser);                                    //~v6D0I~
      if (len)                                                     //~v6dhI~
      {                                                            //~v6dhI~
        if (len>FTP_USERNAMELEN)    //nodeid must be over 2 byte
        {
            uerrmsg("username len should be up to %d",0,
                    FTP_USERNAMELEN);
            break;
        }
        memcpy(Ppufh->UFTPHuser,puser,(UINT)len);
      }                                                            //~v6dhI~
//password
        ppswd=pargc[3];
//      len=strlen(ppswd);                                         //~v6D0R~
        len=(int)strlen(ppswd);                                    //~v6D0I~
        if (len>FTP_USERNAMELEN)    //nodeid must be over 2 byte
        {
            uerrmsg("password len should be up to %d",0,
                    FTP_PSWDNAMELEN);
            break;
        }
	  if (!uftphostscrypt(0,ppswd,crptpswd))	//decrypted        //~v5boI~
      {                                                            //~v6qgR~
        memcpy(Ppufh->UFTPHpswd,crptpswd,(UINT)len);               //~v5boM~
        Ppufh->UFTPHflag|=UFTPHFPSWDENC;    //enclipted at load    //~v6qgI~
		if (Popt & UFGHDO_CLEAR_ENCPSWD) //clear pswd on the line if encripted//~v6qgR~
        {	                                                       //~v6qgR~
            Ppufh->UFTPHflag|=UFTPHFPSWDCLR;    //                 //~v6qgR~
//rep original data pswd by crypted user+pswd                      //~v6qgR~
			pc=pbuff+strspn(pbuff," \t");                          //~v6qgR~
        	for (ii=0;ii<MIN_PARMNO-1;ii++) 	//search user fld  //~v6qgR~
            {                                                      //~v6qgR~
            	pc=strpbrk(pc," \t");                              //~v6qgR~
            	pc+=strspn(pc," \t");                              //~v6qgR~
            }                                                      //~v6qgR~
            memset(Pdata+PTRDIFF(pc,pbuff),' ',(UINT)len);         //~v6qgR~
//          memcpy(Pdata+PTRDIFF(pc,pbuff),ERR_PSWD,min(len,sizeof(ERR_PSWD)-1));//~v6qgR~//~v6D0R~
            memcpy(Pdata+PTRDIFF(pc,pbuff),ERR_PSWD,min((size_t)len,sizeof(ERR_PSWD)-1));//~v6D0I~
	        strcpy(Ppufh->UFTPHpswd,ERR_PSWD);                     //~v6qgR~
        }                                                          //~v6qgR~
      }                                                            //~v6qgR~
      else                                                         //~v5boM~
      {                                                            //~v5boM~
//      Ppufh->UFTPHflag&=~UFTPHFPSWDENC;    //enclipted at load   //~v6qgI~//~v6D0R~
        Ppufh->UFTPHflag&=~(ULONG)UFTPHFPSWDENC;    //enclipted at load//~v6D0I~
        memcpy(Ppufh->UFTPHpswd,ppswd,(UINT)len);
        if (strchr(ppswd,'='))                                     //~v5j9I~
        {                                                          //~v5j9I~
            uerrmsg("Warning:password contains char '=' for %s",0, //~v5j9I~
            			pnode);                                    //~v5j9I~
        }                                                          //~v5j9I~
	  	if (!uftphostscrypt(1,ppswd,crptpswd))	//encrypted        //~v5boR~
        {                                                          //~v5boI~
//rep original data pswd by crypted user+pswd                      //~v5boR~
			pc=pbuff+strspn(pbuff," \t");                          //~v5boR~
        	for (ii=0;ii<MIN_PARMNO-1;ii++) 	//search user fld  //~v5boR~
            {                                                      //~v5boI~
            	pc=strpbrk(pc," \t");                              //~v5boR~
            	pc+=strspn(pc," \t");                              //~v5boI~
            }                                                      //~v5boI~
//          memcpy(Pdata+((ULONG)pc-(ULONG)pbuff),crptpswd,(UINT)len);//~v5boR~//~v6hhR~
            memcpy(Pdata+((ULPTR)pc-(ULPTR)pbuff),crptpswd,(UINT)len);//~v6hhI~
        }                                                          //~v5boI~
      }//crypt chk                                                 //~v5boI~
//initial cwd
    	for (ii=MIN_PARMNO;ii<opdno;ii++)                          //~v5boR~
        {                                                          //~v5adI~
            pcwd=pargc[ii];                                        //~v5adR~
            if (*pcwd=='#')	//comment                              //~v5adR~
            {                                                      //~v5adI~
                rc=0;                                              //~v5adI~
            	break;                                             //~v5adI~
            }                                                      //~v5adI~
//          len=strlen(pcwd);                                      //~v5adI~//~v6D0R~
            len=(int)strlen(pcwd);                                 //~v6D0I~
            if (len>5 && !memicmp(pcwd,"HOME=",5))                 //~v5adI~
            {                                                      //~v59dI~
            	pcwd+=5;                                           //~v5adI~
//              if (*pcwd && *pcwd!='/')    //start from root      //~v5jgR~
//              {                                                  //~v5jgR~
//                  uerrmsg("initial dir err(%s),use fullpath name",0,//~v5jgR~
//                          pcwd);                                 //~v5jgR~
//                  break;                                         //~v5jgR~
//              }                                                  //~v5jgR~
//              strncpy(Ppufh->UFTPHcwd,pcwd,sizeof(Ppufh->UFTPHcwd)-1);//~v5bbR~
                strncpy(Ppufh->UFTPHhome,pcwd,sizeof(Ppufh->UFTPHhome)-1);//~v5bbI~
            }//home                                                //~v5adR~
            else                                                   //~v5adI~
            if (len>3 && !memicmp(pcwd,"TZ=",3))                   //~v5adI~
            {                                                      //~v5adI~
            	pcwd+=3;                                           //~v5adI~
//              len=unumlen(pcwd,UNUMLEN_MINUS,strlen(pcwd));      //~v5adR~//~v6D0R~
                len=unumlen(pcwd,UNUMLEN_MINUS,(int)strlen(pcwd)); //~v6D0I~
                if (len<0)                                         //~v5adR~
                {                                                  //~v5adI~
                    signsw=-1;                                     //~v5adI~
                    pcwd++;                                        //~v5adI~
                    len=-len-1;                                    //~v5adI~
                }                                                  //~v5adI~
                else                                               //~v5adI~
                	signsw=1;                                      //~v5adI~
                if (len==4)                                        //~v5adI~
                {                                                  //~v5adI~
                	hh=uatoin(pcwd,2);                             //~v5adR~
                	mm=uatoin(pcwd+2,2);                           //~v5adR~
                    if (hh>=0 && hh<=23 && mm>=0 && mm<=59)        //~v5adI~
                    {                                              //~v5afI~
		                Ppufh->UFTPHtz=(hh*60+mm)*signsw;          //~v5adI~
			        	Ppufh->UFTPHflag|=UFTPHFAJUST;             //~v5afI~
                	}                                              //~v5afI~
                }                                                  //~v5adI~
			    if (!(Ppufh->UFTPHflag & UFTPHFAJUST))             //~v5afI~
                {                                                  //~v5adI~
                    uerrmsg("timezone parm err(%s)",0,             //~v5adI~
                            pcwd);                                 //~v5adI~
                    break;                                         //~v5adI~
                }                                                  //~v5adI~
            }//tz                                                  //~v5adI~
            else                                                   //~v5adI~
            if (len>5 && !memicmp(pcwd,"DBCS=",5))                 //~v5adI~
            {                                                      //~v5adI~
            	pcwd+=5;                                           //~v5adI~
//              len=strlen(pcwd);                                  //~v5adI~//~v6D0R~
                len=(int)strlen(pcwd);                             //~v6D0I~
		        if (len>=3 && !memicmp(pcwd,"EUC",3))              //~v5adR~
                	Ppufh->UFTPHflag|=UFTPHFEUC;                   //~v5adR~
                else                                               //~v5adI~
		        if (len>=4 && !memicmp(pcwd,"SJIS",4))             //~v5adR~
                	Ppufh->UFTPHflag|=UFTPHFSJIS;                  //~v5adR~
                else                                               //~v5adI~
		        if (USTRHEADIS_IC(pcwd,CP939))                     //~v5mBR~
                	Ppufh->UFTPHflag|=UFTPHFCP939;                 //~v5mBI~
                else                                               //~v5mBI~
		        if (USTRHEADIS_IC(pcwd,CP930))                     //~v5mBR~
                	Ppufh->UFTPHflag|=UFTPHFCP930;                 //~v5mBI~
                else                                               //~v5mBI~
		        if (USTRHEADIS_IC(pcwd,CPCJK))                     //~v5mQR~
                	Ppufh->UFTPHflag|=UFTPHFCPCJK;                 //~v5mQR~
                else                                               //~v5mQI~
                {                                                  //~v5adI~
//                  uerrmsg("dbcs parm err(%s),specify EUC or SJIS",0,//~v5mQR~
                    uerrmsg("dbcs parm err(%s)",0,                 //~v5mQI~
                            pcwd);                                 //~v5adI~
                    break;                                         //~v5adI~
                }                                                  //~v5adI~
            }//dbcs                                                //~v5adI~
            else                                                   //~v5adI~
            if (len>4 && !memicmp(pcwd,"TSO=",4))                  //~v5j4I~
            {                                                      //~v5j4I~
            	swerrtsooption=0;                                  //~v5mGI~
            	pcwd+=4;                                           //~v5j4I~
//              len=strlen(pcwd);                                  //~v5j4I~//~v6D0R~
                len=(int)strlen(pcwd);                             //~v6D0I~
//  	        if (len==unumlen(pcwd,0,len))                      //~v5mGR~
		        numlen=unumlen(pcwd,0,len);                        //~v5mGI~
    	        if (len==numlen)                                   //~v5mGI~
                	Ppufh->UFTPHport=atoi(pcwd);                   //~v5j4I~
                else                                               //~v5j4I~
                {                                                  //~v5j4I~
//                  uerrmsg("TSO parm err(%s),port number numeric err",0,//~v5mGR~
//                          pcwd);                                 //~v5mGR~
//                  break;                                         //~v5mGI~
                	Ppufh->UFTPHport=atoi(pcwd);                   //~v5mGI~
                    for (popttso=pcwd+numlen;*popttso;popttso++)   //~v5mGR~
                    {                                              //~v5mGI~
                        switch(toupper(*popttso))                  //~v5mGR~
                        {                                          //~v5mGI~
                        case 'R':                                  //~v5mGI~
                			Ppufh->UFTPHflag|=UFTPHFREALMF;	//real mainframe//~v5mGI~
                            break;                                 //~v5mGI~
                        case 'S':   //submit                       //~v5mGI~
                			Ppufh->UFTPHflag|=UFTPHFTSOSUBM;//submit use TSO SUBMIT cmd//~v5mGI~
                            break;                                 //~v5mGI~
                        default:                                   //~v5mGI~
                        	swerrtsooption=1;                      //~v5mGI~
			                uerrmsg("TSO parm err(%s),error option letter after port number",0,//~v5mGI~
                                    pcwd);                         //~v5mGI~
                        }                                          //~v5mGI~
                    }                                              //~v5mGI~
                }                                                  //~v5j4I~
                if (swerrtsooption)                                //~v5mGI~
                	break;				//rc!=0                    //~v5mGI~
                Ppufh->UFTPHflag|=UFTPHFTSO;                       //~v5j4I~
            }//dbcs                                                //~v5j4I~
            else                                                   //~v5ksI~
            if (len>3 && !memicmp(pcwd,"LS=",3))                   //~v5ksI~
            {                                                      //~v5ksI~
            	pcwd+=3;                                           //~v5ksI~
//              len=strlen(pcwd);                                  //~v5ksI~//~v6D0R~
                len=(int)strlen(pcwd);                             //~v6D0I~
		        if (len>=4 && !memicmp(pcwd,"NLST",4))             //~v5ksI~
                	strcpy(Ppufh->UFTPHlscmd,UFTPHLSCMD_OLD);      //~v5ksR~
                else                                               //~v5ksI~
                {                                                  //~v5ksI~
					if (uftgetstringopd(0,"LS=\"",pbuff,pcwd,Ppufh->UFTPHlscmd,sizeof(Ppufh->UFTPHlscmd),pargc,opdno,&ii))//~v5ktR~
                    	break;                                     //~v5ktI~
                }                                                  //~v5ksI~
			    Ppufh->UFTPHflag|=UFTPHFULSCMD;  //user specific   //~v61eR~
            }//dbcs                                                //~v5ksI~
            else                                                   //~v5j4I~
            if (len>5 && !memicmp(pcwd,"ICMD=",5))                 //~v5ktI~
            {                                                      //~v5ktI~
            	pcwd+=5;                                           //~v5ktI~
				if (uftgetstringopd(1,"ICMD=\"",pbuff,pcwd,Ppufh->UFTPHicmd,sizeof(Ppufh->UFTPHicmd),pargc,opdno,&ii))//~v5ktR~
                    break;                                         //~v5ktI~
            }//dbcs                                                //~v5ktI~
            else                                                   //~v5ktI~
			if (USTRHEADIS_IC(pcwd,FTP_OPT_SSH))  //~v61pR~        //~v6d1R~
        		uftp3setssh(1,Ppufh,pcwd+sizeof(FTP_OPT_SSH)-1,&pcwd);//~v61pI~
            else                                                   //~v61pI~
			if (!memicmp(pcwd,FTP_OPT_SMB,sizeof(FTP_OPT_SMB)-1))  //~v6d1I~
        		uftp3setsmb(0,Ppufh,pcwd+sizeof(FTP_OPT_SMB)-1,&pcwd);//~v6d1I~
            else                                                   //~v6d1I~
            {                                                      //~v6d1I~
                uerrmsg("not supported parm(%s)",0,                //~v5adI~
                        pcwd);                                     //~v5adI~
                break;                                             //~v5adI~
            }                                                      //~v5adI~
        }//other option loop                                       //~v5adR~
        if (ii<opdno)                                              //~v5adI~
        	break;  //rc=4 if not comment reached                  //~v5adR~
        rc=0;
        break;
    }
    if (!UFTPHISTSO(Ppufh))                                        //~v5jgR~
    {                                                              //~v5jgI~
	    pcwd=Ppufh->UFTPHhome;                                     //~v5jgI~
        if (*pcwd && *pcwd!='/')    //start from root              //~v5jgI~
        {                                                          //~v5jgI~
        	uerrmsg("initial dir err(%s),use fullpath name",0,     //~v5jgI~
                            pcwd);                                 //~v5jgI~
        	rc=4;                                                  //~v5jgI~
        }                                                          //~v5jgI~
//      if (Ppufh->UFTPHflag & (UFTPHFCP939|UFTPHFCP930))          //~v5mQR~
        if (Ppufh->UFTPHflag & (UFTPHFCP939|UFTPHFCP930|UFTPHFCPCJK))//~v5mQR~
        {                                                          //~v5mBI~
        	uerrmsg("invalid DBCS codepage for not TSO destination",0);//~v5mBI~
        	rc=4;                                                  //~v5mBI~
        }                                                          //~v5mBI~
    }                                                              //~v5jgI~
    else                                                           //~v5mBI~
    {                                                              //~v5mBI~
        if (Ppufh->UFTPHflag & (UFTPHFSJIS|UFTPHFEUC))             //~v5mBR~
        {                                                          //~v5mBI~
        	uerrmsg("invalid DBCS codepage for TSO destination",0);//~v5mBI~
        	rc=4;                                                  //~v5mBI~
        }                                                          //~v5mBI~
    }                                                              //~v5mBI~
    ufree(pbuff);
    if (pargc0)                                                    //~v5a7I~
	    ufree(pargc0);                                             //~v5a7I~
    return rc;
}//uftpgethostsdata
//**************************************************************** //~v5ktI~
//* get string operand                                             //~v5ktI~
//**************************************************************** //~v5ktI~
int uftgetstringopd(int Popt,char *Pparmid,char *Pbuff,char *Pin,char *Pout,int Poutlen,//~v5ktR~
					UCHAR **Ppargc,int Pmaxii,int *Ppii)           //~v5ktR~
{                                                                  //~v5ktI~
	char *pc,*pc2,*pc3=NULL;                                            //~v5ktR~//~v6h6R~
    int len,ii,len2;                                               //~v5ktR~
    char wk[256];                                                  //~v5ktI~
//***********************                                          //~v5ktI~
	if (*Pin!='"') //'"' is nt parsed because "=" is not delm because encrypted data may contains "="//~v5ktI~
    {                                                              //~v5ktI~
//  	strncpy(Pout,Pin,Poutlen-1);                               //~v5ktI~//~v6D0R~
    	strncpy(Pout,Pin,(size_t)Poutlen-1);                       //~v6D0I~
        return 0;                                                  //~v5ktI~
    }                                                              //~v5ktI~
//  pc2=strstr(Pbuff,Pparmid);                                     //~v615R~
    pc2=ustrstri(Pbuff,Pparmid);                                   //~v615I~
    if (pc2)                                                       //~v5ktI~
    {                                                              //~v5ktI~
    	pc2+=strlen(Pparmid);                                      //~v5ktI~
        pc3=strchr(pc2,'"');                                       //~v5ktI~
    }                                                              //~v5ktI~
    if (!pc2 || !pc3)                                              //~v5ktI~
    {                                                              //~v5ktI~
		uerrmsg("%s parm err(%s),internal logic err",0,            //~v5ktI~
                            		Pparmid,Pin);                  //~v5ktI~
        return 4;                                                  //~v5ktI~
    }                                                              //~v5ktI~
//  len=(int)((ULONG)pc3-(ULONG)pc2);                              //~v5ktI~//~v6hhR~
    len=(int)((ULPTR)pc3-(ULPTR)pc2);                              //~v6hhI~
    if (Popt & 0x01)	//rep "\n" to \n                           //~v5ktI~
    {                                                              //~v5ktI~
//      len2=min(len,sizeof(wk)-1);                                //~v5ktI~//~v6D0R~
        len2=min(len,(int)sizeof(wk)-1);                           //~v6D0I~
    	memcpy(wk,pc2,(UINT)len2);                                 //~v5ktI~
    	*(wk+len2)=0;                                              //~v5ktI~
        for (pc=wk;;)                                              //~v5ktI~
        {                                                          //~v5ktI~
        	pc3=strstr(pc,"\\n");                                  //~v5ktI~
            if (!pc3)                                              //~v5ktI~
            	break;                                             //~v5ktI~
            *pc3++='\n';                                           //~v5ktI~
            strcpy(pc3,pc3+1);                                     //~v5ktI~
            pc=pc3;                                                //~v5ktI~
        }                                                          //~v5ktI~
        pc2=wk;                                                    //~v5ktI~
//      len=strlen(pc2);                                           //~v5ktI~//~v6D0R~
        len=(int)strlen(pc2);                                      //~v6D0I~
    }                                                              //~v5ktI~
    len=min(len,Poutlen-1);                                        //~v5ktI~
    memcpy(Pout,pc2,(UINT)len);                                    //~v5ktI~
    *(Pout+len)=0;                                                 //~v5ktI~
	for (ii=*Ppii;ii<Pmaxii;ii++)                                  //~v5ktR~
		if (*(Ppargc[ii]+strlen(Ppargc[ii])-1)=='"')               //~v5ktI~
        	break;                                                 //~v5ktI~
    *Ppii=ii;                                                      //~v5ktR~
    return 0;                                                      //~v5ktI~
}//uftgetstringopd                                                 //~v5ktI~
//****************************************************************
//* ipaddr fmt chk
//****************************************************************
int uftpipachk(char *Pipa,ULONG *Ppxipa)
{
    char *pc,*pcs;
    int len,ii;
    ULONG xipa=0,ipa[4];
//*****************
//  if (*Pipa>'A')  //by name                                      //~v5j7R~
    if (*Pipa>='A')  //by name                                     //~v5j7I~
    {                                                              //~v59dI~
    	*Ppxipa=0;                                                 //~v59dR~
    	if (strlen(Pipa)>FTP_IPADNAMELEN)                          //~v59dI~
        	return 4;                                              //~v59dI~
    	return 0;                                                  //~v59dI~
    }                                                              //~v59dI~
//*num1-3
	for (ii=0,pcs=Pipa;ii<3;ii++,pcs=pc+1)
    {
        pc=strchr(pcs,'.');
        if (!pc)
            return 4;
//      len=(ULONG)pc-(ULONG)pcs;                                  //~v6hhR~
//      len=(ULPTR)pc-(ULPTR)pcs;                                  //~v6hhI~//~v6D0R~
        len=PTRDIFF(pc,pcs);                                       //~v6D0I~
    	if (len>3 || len<1
	    ||  unumlen(pcs,0,len)!=len)	//numeric chk
            return 4;
        ipa[ii]=(ULONG)atoi(pcs);
    }
//*num4
//  len=strlen(pcs);                                               //~v6D0R~
    len=(int)strlen(pcs);                                          //~v6D0I~
    if (len>3 || len<1
    ||  unumlen(pcs,0,len)!=len)	//numeric chk
    	return 4;
    ipa[3]=(ULONG)atoi(pcs);
    for (ii=0;ii<4;ii++)
    {
    	if (ipa[ii]>255)
        	return 4;
        xipa+=(ipa[ii]<<((3-ii)*8));
    }
    *Ppxipa=xipa;
    return 0;
}//uftpipachk
//**********************************************************************//~v59dM~
//* chk fullpath name is remote file specification                 //~v59dM~
//* "xx:filname" fmt                                               //~v59dM~
//* return nodename length,0:for local                             //~v59dM~
//**********************************************************************//~v59dM~
int uftpisremote(char *Pfpath,PUFTPHOST *Pppuftph)                 //~v5afR~
{                                                                  //~v59dM~
	PUFTPHOST puftph;                                              //~v5afR~
	char *pc,*pfnm;                                                //~v5beR~
    int len;                                                       //~v59dM~
    char  hostnm[FTP_HOSTNAMELEN+1];                               //~v5afI~
//********************                                             //~v59dM~
    if (Pppuftph)                                                  //~v5afI~
    	*Pppuftph=0;	//init for the case copypathinfo           //~v5afI~
	if (!(Gftpopt & GFTPO_AVAIL))  	//no ftp support option        //~v59dM~
    	return 0;				                                   //~v59dM~
//  len=ustrnlen(Pfpath,FTP_HOSTNAMELEN)-2;                        //~v59dM~//~v6D0R~
    len=(int)ustrnlen(Pfpath,FTP_HOSTNAMELEN)-2;                   //~v6D0I~
    if (len<1)      	//fnmlen<=2                                //~v59dM~
    	return 0;	//local                                        //~v59dM~
//	pc=memchr(Pfpath+2,FTP_REMOTEID,len);                          //~v59dM~//~v6d9R~
  	pc=strchr(Pfpath+2,FTP_REMOTEID);                              //~v6d9I~
    if (!pc)	//":" not found in the nodename range              //~v59dM~
    	return 0;	//local                                        //~v59dM~
    pfnm=Pfpath;                                                   //~v5beI~
    if (*pfnm=='\"')                                               //~v5beI~
        if (*pfnm==*(pfnm+strlen(pfnm)-1))                         //~v5beI~
            pfnm++;                                                //~v5beI~
//  len=(int)((ULONG)pc-(ULONG)pfnm);                              //~v5beR~//~v6hhR~
    len=(int)((ULPTR)pc-(ULPTR)pfnm);                              //~v6hhI~
    if (len>FTP_HOSTNAMELEN)                                       //~v5afI~
    	return 0;	//local                                        //~v5afI~
    memcpy(hostnm,pfnm,(UINT)len);                                 //~v5beR~
    *(hostnm+len)=0;                                               //~v5afI~
    if ((puftph=uftpnodesrch(hostnm))==0)                          //~v5afI~
        return 0;   //local                                        //~v5afI~
    if (Pppuftph)                                                  //~v5afR~
		*Pppuftph=puftph;                                          //~v5afR~
    return len;                                                    //~v59dM~
}//uftpisremote                                                    //~v59dM~
//**********************************************************************//~v5abI~
//* chk remote filename is root dir                                //~v5abI~
//* return 0:not remote root 1:remote root                         //~v5abI~
//**********************************************************************//~v5abI~
int uftpisrootdir(char *Pfpath)                                    //~v5abI~
{                                                                  //~v5abI~
	int hostnmlen;                                                 //~v5abI~
    char *pc;                                                      //~v5abI~
//********************                                             //~v5abI~
	hostnmlen=uftpisremote(Pfpath,0);                              //~v5abR~
    if (!hostnmlen)                                                //~v5abI~
    	return 0;                                                  //~v5abI~
    pc=Pfpath+hostnmlen+1;                                         //~v5abI~
    if (*pc==FTP_DIR_SEPC && !*(pc+1))                             //~v5abI~
    	return 1;                                                  //~v5abI~
    return 0;                                                      //~v5abI~
}//uftpisrootdir                                                   //~v5abI~
//**********************************************************************//~v5boI~
//* pswd encription                                                //~v5boI~
//* return 1:already,4:fmt err                                     //~v5boI~
//**********************************************************************//~v5boI~
int uftphostscrypt(int Popt,char *Pipswd,char *Popswd)             //~v5boR~
{                                                                  //~v5boI~
	int ii,len,ch;                                                 //~v5boR~
    UCHAR *pci,*pco;                                               //~v5boI~
static char Sxormask[FTP_PSWDNAMELEN]={0x0f,0x07,0x0e,0x01,0x0d,0x02,0x0c,0x03,//~v5boR~
                                       0x0b,0x04,0x0a,0x05,0x09,0x06,0x08,0x07};//~v5boR~
#define UP_REPSPC	0x01                                           //~v5boR~
#define UP_REPCOMMA 0x02                                           //~v5boR~
//********************                                             //~v5boI~
	if (Popt)	//encript                                          //~v5boI~
    {                                                              //~v5boI~
    	if (*Pipswd & 0x80)                                        //~v5boR~
        	return 1;		//already encrypted                    //~v5boI~
//      len=strlen(Pipswd);                                        //~v5boR~//~v6D0R~
        len=(int)strlen(Pipswd);                                   //~v6D0I~
	    if (len>FTP_PSWDNAMELEN)                                   //~v5boR~
    		return 4;		//err                                  //~v5boI~
//      if (!memcmp(Pipswd,ERR_PSWD,min(len,sizeof(ERR_PSWD)-1)))  //~v6qgR~//~v6D0R~
        if (!memcmp(Pipswd,ERR_PSWD,min((size_t)len,sizeof(ERR_PSWD)-1)))//~v6D0I~
        {                                                          //~v6qgM~
        	strcpy(Popswd,Pipswd);                                 //~v6qgI~
            return 0;                                              //~v6qgM~
        }                                                          //~v6qgM~
        for (pci=Pipswd,pco=Popswd,ii=0;ii<len;ii++,pco++,pci++)   //~v5boR~
        {                                                          //~v5boI~
        	ch=*pci;                                               //~v5boI~
            ch&=0x7f;                                              //~v5boR~
//          ch=((ch&0x0f)<<3)|((UINT)(ch&0x70)>>4);                //~v5boR~
            ch-=0x07;                                              //~v5boR~
            ch=ch^Sxormask[ii];                                    //~v5boR~
            if (ch==' ')                                           //~v5boI~
                ch=UP_REPSPC;                                      //~v5boI~
            else                                                   //~v5boI~
            if (ch==',')                                           //~v5boI~
                ch=UP_REPCOMMA;                                    //~v5boI~
            *pco=(UCHAR)ch;                                        //~v5boI~
        }                                                          //~v5boI~
        *pco=0;                                                    //~v5boI~
      if (len)                                                     //~v5j9I~
//      *Popswd=*Popswd+0x80;	//encryptid                        //~v5boI~//~v6D0R~
        *Popswd=(char)(*Popswd+0x80);	//encryptid                //~v6D0I~
    }                                                              //~v5boI~
    else	//decrypt                                              //~v5boI~
    {                                                              //~v5boI~
    	if (!(*Pipswd & 0x80))                                     //~v5boI~
        	return 1;		//already encrypted                    //~v5boI~
//      len=strlen(Pipswd);                                        //~v5boR~//~v6D0R~
        len=(int)strlen(Pipswd);                                   //~v6D0I~
	    if (len>FTP_PSWDNAMELEN)                                   //~v5boI~
    		return 4;		//err                                  //~v5boI~
        for (pci=Pipswd,pco=Popswd,ii=0;ii<len;ii++,pco++,pci++)   //~v5boR~
        {                                                          //~v5boI~
        	ch=*pci;                                               //~v5boI~
            ch&=0x7f;                                              //~v5boI~
            if (ch==UP_REPSPC)                                     //~v5boI~
                ch=' ';                                            //~v5boI~
            else                                                   //~v5boI~
            if (ch==UP_REPCOMMA)                                   //~v5boI~
                ch=',';                                            //~v5boI~
            ch=ch^Sxormask[ii];                                    //~v5boR~
            ch+=0x07;                                              //~v5boR~
//          ch=((UINT)(ch&0x78)>>3)|((ch&0x07)<<4);                //~v5boR~
            *pco=(UCHAR)ch;                                        //~v5boI~
        }                                                          //~v5boI~
        *pco=0;                                                    //~v5boI~
    }                                                              //~v5boI~
    return 0;                                                      //~v5boI~
}//uftphostscrypt                                                  //~v5boI~
//**********************************************************************//~v5exI~
//*remote utempnam                                                 //~v5exI~
//**********************************************************************//~v5exI~
char *uftptempnam(char *Phost,char *Pprefix,char *Ptempfile)       //~v5exI~
{                                                                  //~v5exI~
    char ts[32];                                                   //~v5exI~
//********************                                             //~v5exI~
	utimeedit("YYYYMMDD-HHMMSS.MIL",ts);                           //~v5exI~
	sprintf(Ptempfile,"%s:/tmp/%s%s",Phost,Pprefix,ts);            //~v5exI~
    return Ptempfile;                                              //~v5exI~
}//uftptempnam                                                     //~v5exI~
//*******************************************************          //~v6d0I~
//*set volatile pswd                                               //~v6d0I~
//*******************************************************          //~v6d0I~
int uftp_mempswd(int Popt,char *Pnode,PUFTPHOST Ppftph,char *Ppswd)//~v6d0I~
{                                                                  //~v6d0I~
	PUFTPHOST puftph;                                              //~v6d0I~
//************************                                         //~v6d0I~
	if (!(puftph=Ppftph))                                          //~v6d0I~
    {                                                              //~v6d0I~
    	if (!(puftph=uftpnodesrch(Pnode)))                         //~v6d0I~
        	return 4;                                              //~v6d0I~
	}                                                              //~v6d0I~
    puftph->UFTPHflag|=UFTPHFMEMPSWD;                              //~v6d0I~
	UstrncpyZ(puftph->UFTPHpswd,Ppswd,sizeof(puftph->UFTPHpswd));  //~v6d0R~
	return 0;                                                      //~v6d0I~
}//uftpnodesrch                                                    //~v6d0I~
//*******************************************************          //~v6J0I~
//*set volatile pswd                                               //~v6J0I~
//*rc: 0xff rc of udirlist_setname                                 //~v6J0I~
//*    0xff00 rc of udirlist_setnameW                              //~v6J0I~
//*******************************************************          //~v6J0I~
int uftp_udirlist_setname(int Popt,PUFTPHOST Ppufh,PUDIRLIST Ppudl,char *Pname,size_t Pnamefldsz)//~v6J0I~
{                                                                  //~v6J0I~
    int rc;                                                        //~v6J0I~
#ifdef W32                                                         //~v6J0I~
    UWCH  wkucs2[UDIRLISTNAMEWSZ/sizeof(UWCH)];                    //~v6J0R~
    UWUCS wkucs4[UDIRLISTNAMEWSZ/sizeof(UWCH)];                    //~v6J0I~
    char  wkutf8[_MAX_PATH];                                       //~v6J0I~
    char *pc;                                                      //~v6J0I~
    int swutf8,rc2;                                                //~v6J0R~
    int chklen,outlen,errctr,u8len=0;                              //~v6J0I~
    int ucs2ctr,ucs4ctr,opt,len;                                   //~v6J0R~
#endif                                                             //~v6J0I~
//************************                                         //~v6J0I~
	rc=udirlist_setname(0,Ppudl,Pname,Pnamefldsz);                 //~v6J0I~
#ifdef W32                                                         //~v6J0I~
    pc=Ppudl->name;                                                //~v6J0I~
    len=(int)strlen(pc);                                           //~v6J0I~
    opt= UFTPHFSJIS                                                //~v6J0I~
		|UFTPHFEUC                                                 //~v6J0I~
		|UFTPHFTSO;                                                //~v6J0I~
    swutf8=2;	//try locale conv                                  //~v6J0I~
    if (!(Ppufh->UFTPHflag & opt))                                 //~v6J0R~
    {                                                              //~v6J0I~
    	opt=UGU8LO_LIMIT_UCSCOUNT;	//ucsctr limit by ucs4ctr      //~v6J0I~
        ucs4ctr=(int)(sizeof(wkucs4)/sizeof(wkucs4[0]));           //~v6J0R~
    	u8len=utfgetutf8strlen(opt,pc,len,&ucs4ctr);               //~v6J0R~
        if (u8len==len)	//valid ascii and utf8                     //~v6J0I~
    		if (ucs4ctr<u8len)	//not all ascii                    //~v6J0I~
        		swutf8=1;                                          //~v6J0R~
            else                                                   //~v6J0I~
        		swutf8=0;                                          //~v6J0I~
    }                                                              //~v6J0I~
    if (swutf8==2)   //try locale conv                             //~v6J0I~
    {                                                              //~v6J0I~
    	opt=UTFCVO_BUFFSZPARM; //outbuff size parm specified,buffsz limit//~v6J0I~
        outlen=(int)sizeof(wkutf8);                                //~v6J0I~
		rc2=utfcvl2f(opt,wkutf8,pc,0/*Pinitoffs*/,len,0/*Pchof*/,0/*Pdbcs*/,&chklen,&outlen,0/*Ppcharcnt*/,0/*Ppcharwidth*/);//~v6J0I~
        if (rc2<UTFCVRC_ERR)                                       //~v6J0R~
            if (rc2 & UTFCVRC_ALLASCII)                            //~v6J0I~
            	swutf8=0;                                          //~v6J0I~
            else                                                   //~v6J0I~
            {                                                      //~v6J0R~
                pc=wkutf8;                                         //~v6J0R~
                len=outlen;                                        //~v6J0R~
                swutf8=3;                                          //~v6J0R~
            }                                                      //~v6J0R~
    }                                                              //~v6J0I~
    ucs4ctr=0;                                                     //~v6J0M~
    if (swutf8==1||swutf8==3)                                      //~v6J0R~
    {                                                              //~v6J0I~
    	opt=UCVUCS_UCS4; //accept ucs4                             //~v6J0I~
    	rc2=ucvsutf2ucs(0/*errfunc*/,opt,pc,len,(UCHAR*)wkucs4,(int)sizeof(wkucs4),&chklen,&outlen,&errctr);//~v6J0R~
        if (!rc2)                                                  //~v6J0R~
    		ucs4ctr=outlen/(int)sizeof(wkucs4[0]);                 //~v6J0R~
    }                                                              //~v6J0I~
    if (ucs4ctr)                                                   //~v6J0R~
    {                                                              //~v6J0I~
        opt=0;                                                     //~v6J0I~
        utfucs42utf16(opt,wkucs4,ucs4ctr,wkucs2,(int)sizeof(wkucs2),&ucs2ctr);//~v6J0R~
		rc2=udirlist_setnameW(0,Ppudl,wkucs2,ucs2ctr);             //~v6J0I~
    }                                                              //~v6J0I~
    else                                                           //~v6J0I~
		rc2=udirlist_setnameW(0,Ppudl,L"",0);                      //~v6J0I~
	rc|=(rc2<<8);                                                  //~v6J0R~
#endif                                                             //~v6J0I~
	return rc;                                                     //~v6J0R~
}//uftpnodesrch                                                    //~v6J0I~
