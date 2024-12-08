//*CID://+v742R~:                              update#=  496;      //~v743R~//~v742R~
//************************************************************* //~5825I~
//*uproc3.c                                                        //~v5kkR~
//* ushellexec,uprocconnect                                        //~v5jaR~
//*************************************************************    //~v022I~
//v743:201222 gnome-terminal --disable-factory is not supported    //~v743I~
//v742:201221 if one is found, no errmsg for other terminal prog   //~v742I~
//v741:201221 chk terminal prog specified on ini file              //~v741I~
//v6Y1:190809 gnome2 obsoleted use gio                             //~v6Y1I~
//v6G2:161211 (UB16.04)mim_get_default_application_type is deprecated and link faile by undefined symbol//~v6G2I~
//v6xi:150115 conversion warning                                   //~v6xiI~
//v6x7:150109 (warning C4244) additional to v6x5 but avoid warning only//~v6x7I~
//v6s2:140213 add xfce4-terminal as terminal emulator              //~v6s2I~
//v6p0:130916 (LNX)usleep was deleted by POSIX.1-2008              //~v6p0I~
//v6k0:130524 mkarmnc is compile err(term.h not found) by v6j0     //~v6k0I~
//v6j0:121102 for xcifb; -DNOCURSES -DXSUB                         //~v6j0I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6hg:120622 (BUG)Server dose not start in 1 seconds; expand wait time//~v6hgI~
//v6hd:120616 for VC6:/W4 warning(C4053)                           //~v6hdI~
//v6hb:120612 FC5:avoid strict type-punned warning                 //~v6hbI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5mF:080627 sometimes serverstart timeout,expand wait time 1->2sec//~v5mFI~
//v5ma:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v5maI~
//v5km:070601 (LNX)ufree missing                                   //~v5kmI~
//v5kk:070531 (LNX)support Konsole as X-terminal                   //~v5kkI~
//v5jq:061103 (3270) pipe read err msg(remains more data)          //~v5jpI~
//v5jn:061024 (BUG:FC5)gnome_vfs\mine_get_default_application_type is deprecated.//~v5jnI~
//            rh9:gnome_vfs_mime_get_default_application return null if type is not application//~v5jnI~
//            fc5:return type is 0 but application is returned to schecyule cmd//~v5jnI~
//v5jm:061022 (XXE:3270:BUG)r-btn-down issue assertion fail localfullpath[0]=='/ etc//~v5jmI~
//v5ja:060921 (LNX)3270 support                                    //~v5jaI~
//v5j5:060914 named pipe server                                    //~v5j5I~
//v5gc:050709 (LNX)child shell create function for spawn terminalsim screen//~v5gcI~
//v5gb:050709 move ushellexec to uproc3.c to avoid gnome link for xsub utility//~v5gbI~
//v5ga:050708 (UNX:BUG)space enclosing is not required for LNX,spawn cmd fail. See v082//~v5g9R~
//v5g9:050708 (LNX)openwith support                                //~v5g9M~
//v5es:041031 (BUG)stderr ptr should be safe to be cleared         //~v5csI~
//v5cw:040516 (WXE)it should be notified to cmd server of cd drive id change//~v5cwI~
//v5cs:040509 (WIN:BUG)_tempnam  returns prefix itself if prefix length >=8//~v5csI~
//                     and loop when the only one name exist       //~v5csI~
//v5cc:040414 (WXE)confirm xesyscmd.exe is alive before write to pipe//~v5ccI~
//v5by:040229 shellexecute(open with application by ext association) support//~v5byI~
//************************************************************* //~5825I~
#include <time.h>                                               //~5825I~
#include <stdio.h>                                              //~5825I~
#include <stdlib.h>                                             //~5825I~
#include <stddef.h>	//offsetof                                     //~v5jaI~
#include <string.h>                                             //~5825I~
#include <stdarg.h>                                             //~5A10I~
#include <errno.h>                                              //~5A10I~
#include <fcntl.h>                                                 //~v59jI~
#ifdef UNX                                                         //~v327I~
  #ifdef LNX                                                       //~v59jI~
	#include <sys/wait.h>                                          //~v59jI~
#if !(defined(ARM) && defined(XXE))                                //~v6a0I~
//#ifndef NOCURSES                                                 //~v6j0R~
  #ifndef NOCURSES                                                 //~v6k0I~
	#include <term.h>                                              //~v5g9I~
  #endif //NOCURSES                                                //~v6k0I~
//#endif //NOCURSES                                                //~v6j0R~
#endif //ARMXXE                                                    //~v6a0I~
                                                                   //~v5g9R~
   #ifndef ARM 
     #ifndef NOGNOME2                                                    //~v6a0I~
	#include <libgnomevfs/gnome-vfs.h>                             //~v5g9I~
      #include <libgnomevfs/gnome-vfs-init.h>                        //~v5g9R~
   	#include <libgnomevfs/gnome-vfs-utils.h>                       //~v5g9R~
  	#include <libgnomevfs/gnome-vfs-mime-info.h>                   //~v5g9I~
  	#include <libgnomevfs/gnome-vfs-mime-handlers.h>               //~v5g9I~
  	#include <libgnomevfs/gnome-vfs-mime.h>                        //~v5g9I~
  	#include <libgnomevfs/gnome-vfs-file-info.h>                   //~v6G2R~
  	#include <libgnomevfs/gnome-vfs-ops.h>
     #else //NOGNOME2                                              //~v6Y1I~
		#include <glib.h>                                          //~v6Y1R~
		#include <gio/gio.h>                                       //~v6Y1I~
//		#include <gio/gappinfo.h>                                  //~v6Y1R~
     #endif                          //~v6G2I~
   #endif //ARM                                                    //~v6a0I~
  #endif                                                           //~v59jI~
	#include <sys/stat.h>                                          //~v327I~
	#include <unistd.h>                                            //~v428I~
  #ifdef MGW32                                                     //~v5ncI~
	#include <process.h>                                           //~v5ncM~
  #else                                                            //~v5ncM~
   #ifndef ARM      //not found                                    //~v6a0I~
	#include <spawn.h>                                             //~v5kkI~
   #endif                                                          //~v6a0I~
  #endif                                                           //~v5ncI~
#else                                                              //~v327I~
	#include <process.h>                                           //~v50HI~
#ifdef DOS                                                      //~5825I~
#else                                                           //~5825I~
    #ifdef W32                                                     //~v022I~
        #include <windows.h>                                       //~v316I~
        #include <dos.h>                                           //~v065I~
        #include <io.h>                                            //~v59jI~
    #else                                                          //~v022I~
    #endif                                                         //~v022I~
#endif                                                          //~5825I~
#endif   //!UNX                                                    //~v327I~
                                                                   //~v022I~
#include <ulib.h>                                               //~5825I~
#include <ualloc.h>                                                //~v5jaR~
#include <uque.h>                                                  //~v5jmI~
#include <uerr.h>                                                  //~v5jaI~
#include <uproc.h>                                              //~5A10I~
#include <uparse.h>                                                //~v5gcI~
#include <ufile.h>                                                 //~v064I~
#ifdef UNX                                                         //~v327I~
	#include <ufile2l.h>                                           //~v327I~
	#ifdef LNX                                                     //~v5g9I~
		#include <ukbdl.h>                                         //~v5g9I~
	#endif                                                         //~v5g9I~
#endif                                                             //~v327I~
#ifdef WINCON                                                      //~v5maI~
    #include <ukbd.h>                                              //~v5maI~
    #include <ukbdw.h>                                             //~v5maI~
#endif                                                             //~v5maI~
#include <uftp.h>                                                  //~v5jmI~
#include <utrace.h>                                                //~v5j5I~
#include <u3270.h>                                                 //~v5jpI~
#include <ustring.h>                                               //~v741I~
//*********************************************                    //~v064R~
#ifdef LNX                                                         //~v5gcI~
	int ulnxlgettermpgmopt(int Ptermsimid,char *Ptermsimname,char *Poptprefix);//~v5gcI~
	int uproc3pgmchk(int Popt,char *Pbinname);                     //~v5kkR~
#define UP3PC_NOMSG   0x01                                         //~v5kkI~
#endif                                                             //~v5gcI~
#ifdef W32                                                         //~v5gcI~
char *ushellexecerrmsg(ULONG Perrid);                              //~v5gcI~
#endif                                                             //~v5gcI~
//int uprocpiperecevmsg(ULONG Phpipe,char *Precvmsg,int Precvbuffsz,int *Ppreadlen,char **Ppdata,int *Ppdatalen);//~v5jaI~//~v6hhR~
int uprocpiperecevmsg(ULPTR Phpipe,char *Precvmsg,int Precvbuffsz,int *Ppreadlen,char **Ppdata,int *Ppdatalen);//~v6hhI~
//int uprocpiperead(ULONG Phpipe,char *Pbuff,int Preqlen,int *Ppreadlen);//~v5jaR~//~v6hhR~
int uprocpiperead(ULPTR Phpipe,char *Pbuff,int Preqlen,int *Ppreadlen);//~v6hhI~
//int uprocpipeiodata(ULONG Phpipe,char *Pbuff,int Pbufflen,int Preqlen,int *Ppreadlen);//~v5jaI~//~v6hhR~
int uprocpipeiodata(ULPTR Phpipe,char *Pbuff,int Pbufflen,int Preqlen,int *Ppreadlen);//~v6hhI~
int uproc3pgmchkInifile(int Popt,char *Pbinname);                  //~v741I~
//*********************************************                    //~v064R~
#ifdef W32                                                         //~v5byI~
//**************************************************************** //~v5byI~
//*start application by ext association                            //~v5byI~
//*rc:ret code                                                     //~v5byI~
//**************************************************************** //~v5byI~
int ushellexec(char *Pfname)                                       //~v5byI~
{                                                                  //~v5byI~
    int showcmd,rc;                                                //~v5byI~
    HINSTANCE hi;                                                  //~v5byI~
//  ULONG ulrc;                                                    //~v5byI~//~v6hhR~
//  ULPTR ulrc;                                                    //~v6x7R~
    ULONG ulrc;      //HINSTANCE but meaning is >=<32              //~v6x7I~
    char *pseerrmsg;                                               //~v5byI~
//********************************                                 //~v5byI~
    showcmd=SW_SHOW;                                               //~v5byI~
    hi=ShellExecute(HWND_DESKTOP,"open",Pfname,                    //~v5byR~
				NULL, //parm                                       //~v5byI~
				NULL, //default dir                                //~v5byI~
                showcmd);                                          //~v5byI~
//  ulrc=(ULONG)hi;                                                //~v5byI~//~v6hhR~
//  ulrc=(ULPTR)hi;                                                //~v6x7R~
    ulrc=(ULONG)(ULPTR)hi;   //HINSTANCE is for compatibility, value is for chk >=<32//~v6x7R~
    if (ulrc<=32)                                                  //~v5byI~
    {                                                              //~v5byI~
        pseerrmsg=ushellexecerrmsg(ulrc);                          //~v5byI~
    	uerrmsg("ShellExecute failed for \"%s\",rc=%ld(%s)",0,     //~v5byI~
					Pfname,ulrc,pseerrmsg);                        //~v5byI~
        rc=4;                                                      //~v5byI~
    }                                                              //~v5byI~
    else                                                           //~v5byI~
    	rc=0;                                                      //~v5byI~
    return rc;                                                     //~v5byI~
}//ushellexec                                                      //~v5byI~
//**************************************************************** //~v5byI~
//*start application by ext association                            //~v5byI~
//*rc:ret code                                                     //~v5byI~
//**************************************************************** //~v5byI~
char *ushellexecerrmsg(ULONG Perrid)                               //~v5byI~
{                                                                  //~v5byI~
	char *perrmsg;                                                 //~v5byI~
//********************************                                 //~v5byI~
	switch(Perrid)                                                 //~v5byI~
    {                                                              //~v5byI~
    case SE_ERR_FNF:           //2       // file not found         //~v5byI~
        perrmsg="file not found";                                  //~v5byI~
        break;                                                     //~v5byI~
    case SE_ERR_PNF:           //3       // path not found         //~v5byI~
        perrmsg="path not found";                                  //~v5byI~
        break;                                                     //~v5byI~
    case SE_ERR_ACCESSDENIED:  //5       // access denied          //~v5byI~
        perrmsg="access denied";                                   //~v5byI~
        break;                                                     //~v5byI~
    case SE_ERR_OOM:          // 8       // out of memory          //~v5byI~
        perrmsg="out of memory";                                   //~v5byI~
        break;                                                     //~v5byI~
    case SE_ERR_DLLNOTFOUND:    //       32                        //~v5byI~
        perrmsg="dll not found";                                   //~v5byI~
        break;                                                     //~v5byI~
    case SE_ERR_SHARE:          //       26                        //~v5byI~
        perrmsg="sharing vioration";                               //~v5byI~
        break;                                                     //~v5byI~
    case SE_ERR_ASSOCINCOMPLETE:  //     27                        //~v5byI~
        perrmsg="incomplete association";                          //~v5byI~
        break;                                                     //~v5byI~
    case SE_ERR_DDETIMEOUT:         //   28                        //~v5byI~
        perrmsg="DDE timeout";                                     //~v5byI~
        break;                                                     //~v5byI~
    case SE_ERR_DDEFAIL:            //   29                        //~v5byI~
        perrmsg="DDE failed";                                      //~v5byI~
        break;                                                     //~v5byI~
    case SE_ERR_DDEBUSY:            //   30                        //~v5byI~
        perrmsg="DDE busy";                                        //~v5byI~
        break;                                                     //~v5byI~
    case SE_ERR_NOASSOC:            //   31                        //~v5byI~
        perrmsg="no association";                                  //~v5byI~
        break;                                                     //~v5byI~
    default:                                                       //~v5byI~
        perrmsg="unknown err";                                     //~v5byI~
    }                                                              //~v5byI~
    return perrmsg;                                                //~v5byI~
}//ushellexecerrmsg                                                //~v5byI~
#endif                                                             //~v5byI~
#ifdef LNX                                                         //~v5g9M~
#ifndef ARM                                                        //~v6a0I~
#ifndef XSUB                                                       //~v6j0I~
#ifndef NOGNOME2                                                   //~v6Y1M~
//**************************************************************** //~v5g9I~
//* initialize for gnome vfs                                       //~v5g9I~
//**************************************************************** //~v5g9I~
int uproc_gvfsinit(void)                                           //~v5g9I~
{                                                                  //~v5g9I~
	static int Sinitsw=0;                                          //~v5g9R~
//******************                                               //~v5g9I~
	if (Sinitsw)                                                   //~v5g9I~
    	return 0;                                                  //~v5g9I~
#ifndef NOGNOME2
	if (!gnome_vfs_init())                                         //~v5g9I~
    {                                                              //~v5g9I~
		uerrmsg("gnome_vfs_init failed",0);                        //~v5g9I~
		return -1;                                                 //~v5g9I~
	}                                                              //~v5g9I~
#endif
    Sinitsw=1;                                                     //~v5g9I~
    return 0;                                                      //~v5g9I~
}//uproc_gvfsinit                                                  //~v5g9I~
int ushellexecsub(char *Pfpath,char *Pcmd,int Ptermuse);           //~v5g9I~
//**************************************************************** //~v5g9M~
//* ulnxopenwidth                                                  //~v5g9M~
//* send file to associated application                            //~v5g9M~
//* rc:1 requre terminal for chkonly option                        //~v5g9M~
//**************************************************************** //~v5g9M~
int ushellexec(int Popt,char *Pfnm)                                //~v5g9I~
{
int ushellexecsub(char *Pfpath,char *Pcmd,int Ptermuse);           //~v5g9I~
#ifdef AAA                                                         //~v6G2I~
    GnomeVFSMimeActionType actiontype;                             //~v5g9M~
#endif                                                             //~v6G2I~
    GnomeVFSMimeApplication *papp;                                 //~v5g9M~
	char *pmimetype,*puri,*pparmname,*pdircmd=0,*pcmd,*pname;      //~v5gbR~
    char fpath[_MAX_PATH];                                         //~v5g9M~
    int rc=0,termsw,simid,termid,actiontypeerr=0,reqterm;          //~v5gbR~
#define MIME_DIR  "x-directory/"                                   //~v5gbI~
#define MIME_DIR_CMD  "nautilus"                                   //~v5gbI~
    GnomeVFSFileInfo finf;                                         //~v6G2I~
    GnomeVFSFileInfoOptions optfi;                                 //~v6G2I~
	char *pmimetypeslow;                                           //~v6G2I~
//*********************                                            //~v5g9M~
    UTRACEP("%s:fnm=%s\n",UTT,Pfnm);                               //~v742I~
	termid=ukbdl_gettermid();                                      //~v5g9R~
    if ((termid & TERM_IDMASK)==TERM_TTYLCONS)                     //~v5g9R~
    {                                                              //~v5g9I~
		if (!(Popt & USHEXE_NOMSG))                                //~v5g9I~
	    	uerrmsg("Open With Application is not avail on console screen",0);//~v5g9R~
    	return -1;		//no mime type defined                     //~v5g9I~
    }                                                              //~v5g9I~
	simid=termid&TERM_SIMID;                                       //~v5g9I~
    if (uproc_gvfsinit())                                          //~v5g9I~
    	return -1;                                                 //~v5g9I~
	if(!ufullpath(fpath,Pfnm,sizeof(fpath)))                       //~v5g9R~
    	return -1;                                                 //~v5g9M~
	if (uftpisremote(fpath,0))  //gnome_vfs assersion fail for "hostid:/" format//~v5jmI~
    	return -1;                                                 //~v5jmI~
    if (ufstat(fpath,0))                                           //~v5gcI~
    {                                                              //~v5gcI~
		uerrmsg("%s not found",0,                                  //~v5gcI~
        		fpath);                                            //~v5gcI~
        return -1;                                                 //~v5gcI~
    }                                                              //~v5gcI~
    puri=gnome_vfs_get_uri_from_local_path(fpath);	// file:///root/... fmt//~v5g9M~
    if (!puri)                                                     //~v5jmI~
    {                                                              //~v5jmI~
		uerrmsg("uri format err(%s)",0,                            //~v5jmI~
        		fpath);                                            //~v5jmI~
    	return -1;                                                 //~v5jmI~
    }                                                              //~v5jmI~
    pmimetype=gnome_vfs_get_mime_type(puri);                       //~v5g9R~
//printf("mimetype=%s from uristr=%s \n",pmimetype,puri);          //~v5g9R~
    if (!pmimetype)                                                //~v5g9R~
    {                                                              //~v5g9I~
		if (!(Popt & USHEXE_NOMSG))                                //~v5g9I~
	    	uerrmsg("MIME type not defined for %s",0,              //~v5g9R~
        				puri);                                     //~v5g9I~
    	return -1;		//no mime type defined                     //~v5g9M~
    }                                                              //~v5g9I~
    papp=gnome_vfs_mime_get_default_application(pmimetype);        //~v5jnI~
    UTRACEP("%s,getdefault app mimetype=%s,papp=%p\n",UTT,pmimetype,papp);//~v6G2R~
    if (!papp)                                                     //~v6G2I~
    {                                                              //~v6G2I~
        optfi=GNOME_VFS_FILE_INFO_FORCE_SLOW_MIME_TYPE|GNOME_VFS_FILE_INFO_GET_MIME_TYPE;//~v6G2I~
        gnome_vfs_get_file_info(puri,&finf,optfi);                 //~v6G2I~
        pmimetypeslow=finf.mime_type;                              //~v6G2R~
	    papp=gnome_vfs_mime_get_default_application(pmimetypeslow);//~v6G2I~
        UTRACEP("%s,fileinfo slow mimetype=%s,papp=%p\n",UTT,pmimetypeslow,papp);//~v6G2I~
        if (papp)                                                  //~v6G2I~
        	pmimetype=pmimetypeslow;                               //~v6G2R~
    }                                                              //~v6G2I~
  if (!papp)	//no application defined                           //~v5jnI~
  {                                                                //~v5jnI~
#ifdef AAA                                                         //~v6G2I~
    actiontype=gnome_vfs_mime_get_default_action_type(pmimetype);  //~v5g9M~
//printf("mimetype:%s actiontype=%d (0:non,1:app,2:comp)\n",pmimetype,actiontype);//~v5g9R~
    if (actiontype==GNOME_VFS_MIME_ACTION_TYPE_COMPONENT)          //~v5gbI~
    {                                                              //~v5gbI~
		if (strlen(pmimetype)>sizeof(MIME_DIR) && !memcmp(pmimetype,MIME_DIR,sizeof(MIME_DIR)-1))//~v5gbR~
        	pdircmd=MIME_DIR_CMD;                                  //~v5gbI~
        else                                                       //~v5gbI~
        	actiontypeerr=1;                                       //~v5gbI~
    }                                                              //~v5gbI~
    else                                                           //~v5gbI~
//  	if (actiontype!=GNOME_VFS_MIME_ACTION_TYPE_APPLICATION)    //~v5jnR~
        	actiontypeerr=1;                                       //~v5gbI~
#else                                                              //~v6G2I~
        	actiontypeerr=1;                                       //~v6G2I~
#endif                                                             //~v6G2I~
    if (actiontypeerr)                                             //~v5gbI~
    {                                                              //~v5g9I~
		if (!(Popt & USHEXE_NOMSG))                                //~v5g9I~
	    	uerrmsg("default action is not defined for MIME type:%s",0,//~v5gbR~
        				pmimetype);                                //~v5g9I~
    	return -1;		//no application binded                    //~v5g9M~
    }                                                              //~v5g9I~
  }//application not defined                                       //~v5jnI~
    if (pdircmd)                                                   //~v5gbI~
    {                                                              //~v5gbI~
    	papp=0;                                                    //~v5gbI~
        pparmname=fpath;                                           //~v5gbI~
        reqterm=0;                                                 //~v5gbI~
        pname=pcmd=pdircmd;                                        //~v5gbI~
    }                                                              //~v5gbI~
    else                                                           //~v5gbI~
    {                                                              //~v5gbI~
//      papp=gnome_vfs_mime_get_default_application(pmimetype);    //~v5jnR~
//printf("mimetype:%s papp=%p\n",pmimetype,papp);                  //~v5g9R~
//printf("id=%s,name=%s,command=%s,can_open_multiple_files=%d,expects_uris=%d,requires_terminal=%d\n",//~v5g9R~
//papp->id,papp->name,papp->command,papp->can_open_multiple_files,papp->expects_uris,papp->requires_terminal);//~v5g9R~
        if (papp->expects_uris==GNOME_VFS_MIME_APPLICATION_ARGUMENT_TYPE_URIS) ////~v5gbR~
            pparmname=puri;                                        //~v5gbR~
        else                                                       //~v5gbR~
        if (papp->expects_uris==GNOME_VFS_MIME_APPLICATION_ARGUMENT_TYPE_PATHS) ////~v5gbR~
            pparmname=fpath;                                       //~v5gbR~
        else                                                       //~v5gbR~
        {                                                          //~v5gbR~
            if (!(Popt & USHEXE_NOMSG))                            //~v5gbR~
                uerrmsg("parameter type for default application(%s) for MIME type:%s is not local-pathname nor uri",0,//~v5gbR~
                            papp->name,pmimetype);                 //~v5gbR~
            return -1;      //no application binded                //~v5gbR~
        }                                                          //~v5gbR~
		pcmd=papp->command;                                        //~v5gbI~
		pname=papp->name;                                          //~v5gbI~
		reqterm=(papp->requires_terminal!=0);                      //~v5gbI~
    }                                                              //~v5gbI~
    if (Popt & USHEXE_CHKONLY)                                     //~v5g9R~
		rc=reqterm;		//terminal requred as rc                   //~v5gbR~
    else                                                           //~v5g9M~
    {                                                              //~v5g9I~
        termsw=reqterm || (Popt & USHEXE_FORCETERM);               //~v5gbR~
        if (termsw)                                                //~v5g9R~
        {                                                          //~v5g9I~
	        if (!simid)                                            //~v5g9I~
    	    	simid=TERM_OTHERSIM;                               //~v5g9R~
        }                                                          //~v5g9I~
        else                                                       //~v5g9I~
        	simid=0;	//no term required                         //~v5g9I~
		rc=ushellexecsub(pparmname,pcmd,simid);                    //~v5gbR~
        if (rc>0)	//pid                                          //~v5g9R~
			if (!(Popt & USHEXE_NOMSG))                            //~v5g9I~
		    	uerrmsg("sent \"%s\" to %s(pid=%d)",0,             //~v5gbR~
        				Pfnm,pname,rc);                            //~v5gbR~
    }                                                              //~v5g9I~
    if (papp)                                                      //~v5gbI~
		gnome_vfs_mime_application_free(papp);                     //~v5gbR~
//printf("use term");                                              //~v5g9R~
    return rc;
//  return 0;//TODO                                                //~v6Y1R~
}//ushellexec                                                      //~v5g9I~
//**************************************************************** //~v5g9M~
//* ulnxlaunchapp                                                  //~v5g9M~
//*(gnome_vfs_mine_application_launch is supported from gnome_vfs v2.4;rh9 is v2.0)//~v5jnI~
//* apwan assciated appl                                           //~v5g9M~
//* rc:                                                            //~v5g9M~
//**************************************************************** //~v5g9M~
int ushellexecsub(char *Pfpath,char *Pcmd,int Ptermsimid)          //~v5g9R~
{                                                                  //~v5g9M~
    int parmctr=0,rc;                                              //~v5g9R~
    int ii,wordno;                                                 //~v5jnR~
    char *parmv[20],ppopt[8],psim[32],*pcmd;                       //~v5jnR~
    char cmdinterm[_MAX_PATH+_MAX_PATH];                           //~v5g9R~
    UCHAR **cmdparsev=0;                                           //~v5jnR~
//*********************                                            //~v5g9M~
	if (Ptermsimid)                                                //~v5g9R~
    {                                                              //~v5g9M~
		ulnxlgettermpgmopt(Ptermsimid,psim,ppopt);                 //~v5gcR~
        pcmd=psim;                                                 //~v5g9M~
		parmv[parmctr++]=pcmd;                                     //~v5g9M~
		parmv[parmctr++]=ppopt;                                    //~v5g9R~
		parmv[parmctr++]="/bin/sh";                                //~v5g9M~
		parmv[parmctr++]="-c";                                     //~v5g9M~
        sprintf(cmdinterm,"%s '%s'",Pcmd,Pfpath);                  //~v5g9R~
		parmv[parmctr++]=cmdinterm;                                //~v5g9M~
    }                                                              //~v5g9M~
    else                                                           //~v5g9M~
    {                                                              //~v5g9M~
//  	pcmd=Pcmd;                                                 //~v5jnR~
//  	parmv[parmctr++]=pcmd;                                     //~v5jnR~
    	if (uparsev(Pcmd,&cmdparsev,&wordno,0,0))//nocrlf,no delmtb//~v5jnI~
    	{                                                          //~v5jnI~
    		uerrmsg("associated cmd(%s) parse failed",0,           //~v5jnI~
        				Pcmd);                                     //~v5jnI~
    		return -1;//err pid                                    //~v5jnI~
    	}                                                          //~v5jnI~
    	pcmd=cmdparsev[0];                                         //~v5jnI~
    	for (ii=0;ii<wordno;ii++)                                  //~v5jnI~
    		parmv[parmctr++]=cmdparsev[ii];                        //~v5jnI~
		parmv[parmctr++]=Pfpath;                                   //~v5g9M~
	}                                                              //~v5g9M~
//  for (ii=0;ii<parmctr;ii++)                                     //~v5g9R~
//	    printf("spawn parm ii=%d=%s\n",ii,parmv[ii]);              //~v5g9R~
	parmv[parmctr++]=0;	//last                                     //~v5g9M~
    rc=uspawnvp(P_NOWAIT,pcmd,parmv);                              //~v5g9R~
//printf("uspawn async pid=%d\n",pid);                             //~v5g9R~
    if (cmdparsev)                                                 //~v5jnI~
        ufree(cmdparsev);                                          //~v5jnI~
    return rc;  //return pid                                       //~v5g9R~
}//ushellexecsub                                                   //~v5g9I~
#else //!NOGNOME2                                                  //~v6Y1R~
//**************************************************************** //~v6Y1I~
//* send file to associated application                            //~v6Y1I~
//* rc:1 requre terminal for chkonly option                        //~v6Y1I~
//**************************************************************** //~v6Y1I~
int ushellexec(int Popt,char *Pfnm)                                //~v6Y1I~
{                                                                  //~v6Y1I~
//int ushellexecsub(char *Pfpath,char *Pcmd,int Ptermuse);         //~v6Y1I~
	int ushellexecsub(GAppInfo *Papp,char *Pparm);                 //~v6Y1I~
	int ushellexecsubcmdline(GAppInfo *Papp,char *Pcmd,char *Pparm);//~v6Y1I~
//  GnomeVFSMimeApplication *papp;                                 //~v6Y1I~
    char /*pmimetype,*/*puri,*pparmname/*pdircmd=0,*pcmd,*pname*/; //~v6Y1I~
    char fpath[_MAX_PATH];                                         //~v6Y1I~
    int rc=0/*,termsw,simid,termid,actiontypeerr=0,reqterm*/;      //~v6Y1I~
//#define MIME_DIR  "x-directory/"                                 //~v6Y1I~
//#define MIME_DIR_CMD  "nautilus"                                 //~v6Y1I~
//  GnomeVFSFileInfo finf;                                         //~v6Y1I~
//  GnomeVFSFileInfoOptions optfi;                                 //~v6Y1I~
//  char *pmimetypeslow;                                           //~v6Y1I~
//*********************                                            //~v6Y1I~
    GFile *gfh;                                                    //~v6Y1I~
    GFileInfo *gfi;                                                //~v6Y1I~
    GError    *gerr;                                               //~v6Y1I~
    GAppInfo  *papp;                                               //~v6Y1I~
    const char *pmimetype,*pname;                                  //~v6Y1R~
    const char *pcmd;                                              //~v6Y1I~
    int swCmdLine=0;                                               //~v6Y1R~
//*********************                                            //~v6Y1I~
//    termid=ukbdl_gettermid();                                    //~v6Y1I~
//    if ((termid & TERM_IDMASK)==TERM_TTYLCONS)                   //~v6Y1I~
//    {                                                            //~v6Y1I~
//        if (!(Popt & USHEXE_NOMSG))                              //~v6Y1I~
//            uerrmsg("Open With Application is not avail on console screen",0);//~v6Y1I~
//        return -1;      //no mime type defined                   //~v6Y1I~
//    }                                                            //~v6Y1I~
//    simid=termid&TERM_SIMID;                                     //~v6Y1I~
//    if (uproc_gvfsinit())                                        //~v6Y1I~
//        return -1;                                               //~v6Y1I~
    if(!ufullpath(fpath,Pfnm,sizeof(fpath)))                       //~v6Y1I~
        return -1;                                                 //~v6Y1I~
    if (uftpisremote(fpath,0))  //gnome_vfs assersion fail for "hostid:/" format//~v6Y1I~
        return -1;                                                 //~v6Y1I~
    if (ufstat(fpath,0))                                           //~v6Y1I~
    {                                                              //~v6Y1I~
        uerrmsg("%s not found",0,                                  //~v6Y1I~
                fpath);                                            //~v6Y1I~
        return -1;                                                 //~v6Y1I~
    }                                                              //~v6Y1I~
    gfh=g_file_new_for_path(Pfnm);  //    g_object_unref() later   //~v6Y1I~
    char *pfpath=g_file_get_path(gfh);                             //~v6Y1I~
    if (!pfpath)                                                   //~v6Y1I~
        return -1;                                                 //~v6Y1I~
   	UTRACEP("ushellexec fpath=%s\n",fpath);                        //~v6Y1R~
//  puri=gnome_vfs_get_uri_from_local_path(fpath);  // file:///root/... fmt//~v6Y1I~
    puri=g_file_get_uri(gfh);	//g_free() later                   //~v6Y1I~
  	UTRACEP("ushellexec uri=%s\n",puri);                           //~v6Y1R~
    if (!puri)                                                     //~v6Y1I~
    {                                                              //~v6Y1I~
        uerrmsg("ushellexec:uri format err(%s)",0,                 //~v6Y1I~
                fpath);                                            //~v6Y1I~
        g_object_unref(gfh);                                       //~v6Y1I~
        return -1;                                                 //~v6Y1I~
    }                                                              //~v6Y1I~
//  pmimetype=gnome_vfs_get_mime_type(puri);                       //~v6Y1I~
    gfi=g_file_query_info(gfh,"standard::*",0/*flag*/,NULL/*Gcancelable*/,&gerr);//g_onbject_unref() later//~v6Y1I~
    if (gfi)                                                       //~v6Y1I~
    {                                                              //~v6Y1I~
    	pmimetype=g_file_info_get_content_type(gfi);               //~v6Y1I~
    }                                                              //~v6Y1I~
    else                                                           //~v6Y1I~
    {                                                              //~v6Y1I~
        UTRACEP("gfi is null\n");                                  //~v6Y1R~
    	pmimetype=0;                                               //~v6Y1I~
    }                                                              //~v6Y1I~
    if (!pmimetype)                                                //~v6Y1I~
    {                                                              //~v6Y1I~
        if (!(Popt & USHEXE_NOMSG))                                //~v6Y1I~
            uerrmsg("MIME type not defined for %s",0,              //~v6Y1I~
                        puri);                                     //~v6Y1I~
        return -1;      //no mime type defined                     //~v6Y1I~
    }                                                              //~v6Y1I~
	UTRACEP("ushellexec mimetype=%s desc=%s\n",pmimetype,g_content_type_get_description(pmimetype));//~v6Y1R~
//  papp=gnome_vfs_mime_get_default_application(pmimetype);        //~v6Y1I~
    papp=g_app_info_get_default_for_type(pmimetype,FALSE/*must support uri*/);//~v6Y1I~
//    if (!papp)                                                   //~v6Y1I~
//    {                                                            //~v6Y1I~
//        optfi=GNOME_VFS_FILE_INFO_FORCE_SLOW_MIME_TYPE|GNOME_VFS_FILE_INFO_GET_MIME_TYPE;//~v6Y1I~
//        gnome_vfs_get_file_info(puri,&finf,optfi);               //~v6Y1I~
//        pmimetypeslow=finf.mime_type;                            //~v6Y1I~
//        papp=gnome_vfs_mime_get_default_application(pmimetypeslow);//~v6Y1I~
//        UTRACEP("%s,fileinfo slow mimetype=%s,papp=%p\n",UTT,pmimetypeslow,papp);//~v6Y1I~
//        if (papp)                                                //~v6Y1I~
//            pmimetype=pmimetypeslow;                             //~v6Y1I~
//    }                                                            //~v6Y1I~
    if (!papp)    //no application defined                         //~v6Y1I~
    {                                                              //~v6Y1I~
//        actiontypeerr=1;                                         //~v6Y1I~
//        if (actiontypeerr)                                       //~v6Y1I~
//        {                                                        //~v6Y1I~
            if (!(Popt & USHEXE_NOMSG))                            //~v6Y1I~
                uerrmsg("default action is not defined for MIME type:%s",0,//~v6Y1I~
                            pmimetype);                            //~v6Y1I~
        	g_object_unref(gfh);                                   //~v6Y1I~
        	g_object_unref(gfi);                                   //~v6Y1I~
            if (puri)                                              //~v6Y1I~
			    g_free(puri);                                      //~v6Y1I~
            return -1;      //no application binded                //~v6Y1I~
//        }                                                        //~v6Y1I~
    }//application not defined                                     //~v6Y1I~
	UTRACEP("ushellexec app name=%s\n",g_app_info_get_name(papp)); //~v6Y1R~
	UTRACEP("ushellexec app display name=%s\n",g_app_info_get_display_name(papp));//~v6Y1R~
	UTRACEP("ushellexec app description=%s\n",g_app_info_get_description(papp));//~v6Y1R~
	UTRACEP("ushellexec app executable=%s\n",g_app_info_get_executable(papp));//~v6Y1R~
	UTRACEP("ushellexec app cmdline=%s\n",g_app_info_get_commandline(papp));//~v6Y1R~
	pname=g_app_info_get_executable(papp);                         //~v6Y1I~
//    if (pdircmd)                                                 //~v6Y1I~
//    {                                                            //~v6Y1I~
//        papp=0;                                                  //~v6Y1I~
//        pparmname=fpath;                                         //~v6Y1I~
//        reqterm=0;                                               //~v6Y1I~
//        pname=pcmd=pdircmd;                                      //~v6Y1I~
//    }                                                            //~v6Y1I~
//    else                                                         //~v6Y1I~
//    {                                                            //~v6Y1I~
//      papp=gnome_vfs_mime_get_default_application(pmimetype);    //~v6Y1I~
//printf("mimetype:%s papp=%p\n",pmimetype,papp);                  //~v6Y1I~
//printf("id=%s,name=%s,command=%s,can_open_multiple_files=%d,expects_uris=%d,requires_terminal=%d\n",//~v6Y1I~
//papp->id,papp->name,papp->command,papp->can_open_multiple_files,papp->expects_uris,papp->requires_terminal);//~v6Y1I~
		UTRACEP("ushellexec isSupportFiles=%d,isSupportUri=%d\n",g_app_info_supports_files(papp),g_app_info_supports_uris(papp));//~v6Y1R~
//      if (papp->expects_uris==GNOME_VFS_MIME_APPLICATION_ARGUMENT_TYPE_URIS) ////~v6Y1I~
        if (g_app_info_supports_uris(papp))                        //~v6Y1I~
            pparmname=puri;                                        //~v6Y1I~
        else                                                       //~v6Y1I~
//      if (papp->expects_uris==GNOME_VFS_MIME_APPLICATION_ARGUMENT_TYPE_PATHS) ////~v6Y1I~
        if (g_app_info_supports_files(papp))                       //~v6Y1I~
            pparmname=fpath;                                       //~v6Y1I~
        else                                                       //~v6Y1I~
        {                                                          //~v6Y1I~
            if (!(Popt & USHEXE_NOMSG))                            //~v6Y1I~
                uerrmsg("parameter type for default application(%s) for MIME type:%s is not local-pathname nor uri",0,//~v6Y1I~
//                          papp->name,pmimetype);                 //~v6Y1I~
							pname,pmimetype);                      //~v6Y1I~
        	g_object_unref(gfh);                                   //~v6Y1I~
        	g_object_unref(gfi);                                   //~v6Y1I~
            if (puri)                                              //~v6Y1I~
			    g_free(puri);                                      //~v6Y1I~
            return -1;      //no application binded                //~v6Y1I~
        }                                                          //~v6Y1I~
//      pcmd=papp->command;                                        //~v6Y1I~
//      pname=papp->name;                                          //~v6Y1I~
//      reqterm=(papp->requires_terminal!=0);                      //~v6Y1I~
//    }                                                            //~v6Y1I~
    if (Popt & USHEXE_CHKONLY)                                     //~v6Y1I~
//      rc=reqterm;     //terminal requred as rc                   //~v6Y1I~
        rc=1;           //associated                               //~v6Y1I~
    else                                                           //~v6Y1I~
    {                                                              //~v6Y1I~
//        termsw=reqterm || (Popt & USHEXE_FORCETERM);             //~v6Y1I~
//        if (termsw)                                              //~v6Y1I~
//        {                                                        //~v6Y1I~
//            if (!simid)                                          //~v6Y1I~
//                simid=TERM_OTHERSIM;                             //~v6Y1I~
//        }                                                        //~v6Y1I~
//        else                                                     //~v6Y1I~
//            simid=0;    //no term required                       //~v6Y1I~
//        rc=ushellexecsub(pparmname,pcmd,simid);                  //~v6Y1I~
#if (GLIB_CHECK_VERSION(2,50,0))                                   //~v6Y1R~
      if (swCmdLine)                                               //~v6Y1I~
      {                                                            //~v6Y1I~
		pcmd=g_app_info_get_commandline(papp);                     //~v6Y1I~
		rc=ushellexecsubcmdline(papp,(char*)pcmd,pparmname);       //~v6Y1I~
      }                                                            //~v6Y1I~
      else                                                         //~v6Y1I~
	    rc=ushellexecsub(papp,pparmname);                          //~v6Y1R~
#else                                                              //~v6Y1R~
		pcmd=g_app_info_get_commandline(papp);                     //~v6Y1I~
		rc=ushellexecsubcmdline(papp,(char*)pcmd,pparmname);       //~v6Y1R~
#endif                                                             //~v6Y1I~
//      if (rc>0)   //pid                                          //~v6Y1I~
        if (rc>0)   //TRUE                                         //~v6Y1I~
            if (!(Popt & USHEXE_NOMSG))                            //~v6Y1I~
//              uerrmsg("sent \"%s\" to %s(pid=%d)",0,             //~v6Y1I~
//                      Pfnm,pname,rc);                            //~v6Y1I~
                uerrmsg("sent \"%s\" to %s",0,                     //~v6Y1I~
                        Pfnm,pname);                               //~v6Y1I~
    }                                                              //~v6Y1I~
//  if (papp)                                                      //~v6Y1I~
//      gnome_vfs_mime_application_free(papp);                     //~v6Y1I~
    g_object_unref(gfh);                                           //~v6Y1I~
    g_object_unref(gfi);                                           //~v6Y1I~
    if (puri)                                                      //~v6Y1I~
        g_free(puri);                                              //~v6Y1I~
//printf("use term");                                              //~v6Y1I~
    return rc;                                                     //~v6Y1I~
}//ushellexec                                                      //~v6Y1I~
#if (GLIB_CHECK_VERSION(2,50,0))                                   //~v6Y1I~
//**************************************************************** //~v6Y1I~
void asyncCB(GObject *Pobj,GAsyncResult *Presult,gpointer Puserdata)//~v6Y1I~
{                                                                  //~v6Y1I~
	GError *gerr;                                                  //~v6Y1I~
//  gboolean rc;                                                   //~v6Y1R~
//  rc=g_app_info_launch_default_for_uri_finish(Presult,&gerr); //used in callback//~v6Y1R~
    g_app_info_launch_default_for_uri_finish(Presult,&gerr); //used in callback//~v6Y1I~
	UTRACEP("ushellexecsub asyncCB\n");                            //~v6Y1R~
}                                                                  //~v6Y1I~
//**************************************************************** //~v6Y1I~
//* ulnxlaunchapp                                                  //~v6Y1I~
//*(gnome_vfs_mine_application_launch is supported from gnome_vfs v2.4;rh9 is v2.0)//~v6Y1I~
//* apwan assciated appl                                           //~v6Y1I~
//* rc:                                                            //~v6Y1I~
//**************************************************************** //~v6Y1I~
int ushellexecsub(GAppInfo *Papp,char *Pparm)                      //~v6Y1I~
{                                                                  //~v6Y1I~
	GError *gerr;                                                  //~v6Y1I~
    GList *parms=NULL;                                             //~v6Y1R~
//  GAsyncResult *result;                                          //~v6Y1R~
    gboolean rc;                                                   //~v6Y1I~
    int swAsync=1;  //sync failed for html                         //~v6Y1R~
    //*****************                                            //~v6Y1I~
	UTRACEP("ushellexecsub parm=%s\n",Pparm);                      //~v6Y1R~
	if (g_app_info_supports_uris(Papp))                            //~v6Y1I~
    {                                                              //~v6Y1I~
        if (swAsync)                                               //~v6Y1I~
        {                                                          //~v6Y1I~
      		g_app_info_launch_default_for_uri_async(Pparm,NULL/*context*/,NULL/*cancelable*/,asyncCB/*GAsyncReadyCallBack*/,NULL/*userData*/);//~v6Y1R~
        	rc=TRUE;	//async support from 2.50                  //~v6Y1R~
        }                                                          //~v6Y1I~
        else                                                       //~v6Y1I~
        {                                                          //~v6Y1I~
	    	parms=g_list_append(parms,Pparm);                      //~v6Y1R~
			rc=g_app_info_launch_uris(Papp,parms,NULL/*context*/,&gerr);//~v6Y1I~
		}                                                          //~v6Y1I~
		UTRACEP("ushellexecsub lauch_uri_async\n");                //~v6Y1I~
    }                                                              //~v6Y1I~
    else                                                           //~v6Y1I~
    {                                                              //~v6Y1I~
    	parms=g_list_prepend(NULL,Pparm);                          //~v6Y1I~
    	rc=g_app_info_launch(Papp,parms,NULL/*context*/,&gerr);    //~v6Y1I~
    }                                                              //~v6Y1I~
	UTRACEP("ushellexecsub rc=%d,parm=%s\n",rc,Pparm);             //~v6Y1R~
    return rc;                                                     //~v6Y1I~
}//ushellexecsub                                                   //~v6Y1I~
#endif  //GLIB_CHECK_VERSION                                       //~v6Y1M~
//**************************************************************** //~v6Y1I~
int ushellexecsubcmdline(GAppInfo *Papp,char *Pcmd,char *Pparm)    //~v6Y1I~
{                                                                  //~v6Y1I~
    int rc;                                                        //~v6Y1I~
    char *pc;                                                      //~v6Y1I~
    char cmdinterm[_MAX_PATH+_MAX_PATH];                           //~v6Y1I~
//*********************                                            //~v6Y1I~
	strcpy(cmdinterm,Pcmd);                                        //~v6Y1I~
    pc=strchr(cmdinterm,'%');                                      //~v6Y1I~
    strcpy(pc,Pparm);                                              //~v6Y1I~
	strcat(pc," 2>&1 >/dev/null &");                               //~v6Y1R~
    UTRACEP("ushellexecsubcmdline cmd=%s\n",cmdinterm);            //~v6Y1R~
    rc=system(cmdinterm);                                          //~v6Y1I~
    UTRACEP("system rc=%u\n",rc);                                  //~v6Y1R~
    rc=rc!=-1 && rc!=127;       //-1:chiled not created,127:child process could not execute shell//~v6Y1I~
    UTRACEP("ushellexecsubcmdline rc=%d\n",rc);                    //~v6Y1R~
    return rc;                                                     //~v6Y1I~
}//ushellexecsubcmdline                                            //~v6Y1I~
#endif                                                             //~v6Y1I~
#endif //!XSUB                                                     //~v6j0I~
#endif //ARM                                                       //~v6a0I~
//**************************************************************** //~v5gcI~
//* ulnxlgettermpgmopt                                             //~v5gcI~
//* get terminal simulater name and subcmd prefix                  //~v5gcI~
//* rc:                                                            //~v5gcI~
//**************************************************************** //~v5gcI~
int ulnxlgettermpgmopt(int Ptermsimid,char *Ptermsimname,char *Poptprefix)//~v5gcI~
{                                                                  //~v5gcI~
    char *ppopt,*psim;                                             //~v5gcI~
//*****************                                                //~v5gcI~
    ppopt="-e";                                                    //~v5gcI~
    switch(Ptermsimid)                                             //~v5gcI~
    {                                                              //~v5gcI~
    case TERM_GTERMSIM:                                            //~v5gcI~
        psim="gnome-terminal";                                     //~v5gcI~
        ppopt="-x";                                                //~v5gcI~
        break;                                                     //~v5gcI~
    case TERM_DTTERMSIM:                                           //~v5gcI~
        psim="dtterm";                                             //~v5gcI~
        break;                                                     //~v5gcI~
    case TERM_NXTERMSIM:                                           //~v5gcI~
        psim="nxterm";                                             //~v5gcI~
        break;                                                     //~v5gcI~
    case TERM_COLORXSIM:                                           //~v5gcI~
        psim="color-xterm";                                        //~v5gcI~
        break;                                                     //~v5gcI~
    case TERM_RXVTSIM:                                             //~v5gcI~
        psim="rxvt";                                               //~v5gcI~
        break;                                                     //~v5gcI~
    case TERM_XTERMSIM:                                            //~v5gcI~
        psim="xterm";                                              //~v5gcI~
        break;                                                     //~v5gcI~
    case TERM_KONSOLE:                                             //~v5kkI~
        psim="konsole";                                            //~v5kkI~
        ppopt="--ls";    	//login shell                          //~v5kkI~
        break;                                                     //~v5kkI~
    case TERM_XFCE4TERM:                                           //~v6s2I~
        psim="xfce4-terminal";                                     //~v6s2I~
        break;                                                     //~v6s2I~
    default:                                                       //~v5gcI~
        psim="gnome-terminal";                                     //~v5gcI~
        ppopt="-x";                                                //~v5gcI~
    }                                                              //~v5gcI~
    strcpy(Ptermsimname,psim);                                     //~v5gcI~
    if (Poptprefix)                                                //~v5gcI~
	    strcpy(Poptprefix,ppopt);                                  //~v5gcI~
    return 0;                                                      //~v5gcI~
}//ulnxlgettermpgmopt                                              //~v5gcI~
//**************************************************************** //~v5kkI~
//* ulnxgetshellpgm                                                //~v5kkI~
//* get shell pgm name for ">" cmd                                 //~v5kkI~
//* rc:                                                            //~v5kkI~
//**************************************************************** //~v5kkI~
int ulnxlgetshellpgm(int Popt,char *Pout)                          //~v5kkI~
{                                                                  //~v5kkI~
static char *Sforcedefault=0;                                      //~v5kkI~
//*****************                                                //~v5kkI~
    if (Popt & XGSP_SETDEFAULT) //set default                      //~v5kkI~
    {                                                              //~v5kkI~
    	Sforcedefault=Pout;	                                       //~v5kkI~
        return 0;                                                  //~v5kkI~
    }                                                              //~v5kkI~
    if (Sforcedefault)                                             //~v5kkI~
    {                                                              //~v5kkI~
    	strcpy(Pout,Sforcedefault);                                //~v5kkI~
        return 0;                                                  //~v5kkI~
    }                                                              //~v5kkI~
	strcpy(Pout,"sh");                                             //~v5kkI~
	if (!uproc3pgmchk(UP3PC_NOMSG,"dash")) //(K)ubuntu:dash is slink from sh//~v5kkR~
		if (!uproc3pgmchk(UP3PC_NOMSG,"bash"))	//if bash installed//~v5kkI~
    		strcpy(Pout,"bash");                //replace dash to bash//~v5kkR~
    return 0;                                                      //~v5kkI~
}//ulnxlgetshellpgm                                                //~v5kkI~
//*********************************************************************//~v5kkM~
//* get terminal pgm cmd string for system() use by XXE,no parent shell may exits//~v5kkI~
//*********************************************************************//~v5kkM~
int ulnxxgettermpgmopt(int Popt,char *Pcmd,char *Pout)             //~v5kkI~
{                                                                  //~v5kkM~
static char *Spgmtb[]={                                            //~v5kkR~
                     "xterm",                                      //~v5kkM~
	                 "gnome-terminal",                             //~v5kkR~
                     "konsole",                                    //~v5kkR~
                     "xfce4-terminal",                             //~v6s2I~
                     0};                                           //~v5kkM~
static char *Sopttb[]={ //option always when no user cmd           //~v5kkR~
                     "",                                           //~v5kkI~
//	                 "--disable-factory", //fork syncronouse       //~v743R~
  	                 "", //fork syncronouse                        //~v743I~
                     "-ls",               //konsole login session  //~v5kkR~
                     "",                                           //~v6s2I~
                     0};                                           //~v5kkI~
static char *Sopttbe[]={      //option when user cmd specified     //~v5kkR~
	                 "-e",                                         //~v5kkR~
//                   "--disable-factory -x", //gnome-terminal fork syncronouse//~v743R~
                     "-e", //gnome-terminal fork syncronouse       //~v743R~
	                 "-e",                                         //~v5kkR~
	                 "-e",                                         //~v6s2I~
                     0};                  //konsole                //~v5kkR~
static int   Stermid[]={                                           //~v5kkR~
	                 TERM_XTERMSIM,                                //~v5kkI~
	                 TERM_GTERMSIM,                                //~v5kkI~
	                 TERM_KONSOLE,                                 //~v5kkI~
	                 TERM_XFCE4TERM,                               //~v6s2I~
                     0};                                           //~v5kkI~
static int Stermtbidx=-1;	//test only once                       //~v5kkR~
static char *Sforcedefaults=0,*Sforcedefaultc=0;                   //~v5kkI~
    char *pc,*pc2;                                                 //~v5kkR~
    int ii,len;                                                    //~v5kkR~
#ifdef XXE                                                         //~v742I~
    int jj;                                                        //~v742I~
#endif                                                             //~v742I~
//*************************************                            //~v5kkM~
    if (Popt & XGTP_SETDEFAULT) //set default shell                //~v5kkR~
    {                                                              //~v5kkI~
	    uproc3pgmchkInifile(0,Pout);                               //~v741R~
        if (Pcmd)                                                  //~v5kkI~
    		Sforcedefaultc=Pout;                                   //~v5kkI~
        else                                                       //~v5kkI~
	    	Sforcedefaults=Pout;                                   //~v5kkR~
        return 0;                                                  //~v5kkI~
    }                                                              //~v5kkI~
  if (Popt & XGTP_GETDEFAULT)	//0:no user cmd                    //~v5kkI~
  	ii=Popt & XGTP_GETDEFAULTIX;                                   //~v5kkI~
  else                                                             //~v5kkI~
	if (Stermtbidx<0)                                              //~v5kkM~
    {                                                              //~v5kkM~
	  if (!Sforcedefaultc                                          //~v5kkR~
	  ||  !Sforcedefaults) //not bot is default                    //~v5kkR~
      {                                                            //~v5kkI~
        for (ii=1;;ii++)                                           //~v5kkM~
        {                                                          //~v5kkM~
            pc=Spgmtb[ii];                                         //~v5kkR~
            if (!pc)                                               //~v5kkM~
            {                                                      //~v5kkM~
                ii=0;  //default xterm                             //~v5kkM~
                break;                                             //~v5kkM~
            }                                                      //~v5kkM~
//          if (!uproc3pgmchk(0,pc))                               //~v5kkR~//~v742R~
            if (!uproc3pgmchk(UP3PC_NOMSG,pc))	//if bash installed//~v742I~
            	break;                                             //~v5kkI~
        }                                                          //~v5kkM~
        Stermtbidx=ii;                                             //~v5kkM~
        if (ii==0)                                                 //~v742I~
        {                                                          //~v742I~
#ifdef XXE                                                         //~v742I~
            for (jj=1;;jj++)                                       //~v742I~
            {                                                      //~v742I~
                pc=Spgmtb[jj];                                     //~v742I~
                if (!pc)                                           //~v742I~
                    break;                                         //~v742I~
                uproc3pgmchk(0,pc); //issue errmsg                 //~v742I~
            }                                                      //~v742I~
#else                                                              //~v742I~
			;                                                      //~v742I~
#endif                                                             //~v742I~
    	}                                                          //~v742I~
        else                                                       //~v742I~
        {                                                          //~v742I~
                pc=Spgmtb[ii];                                     //~v742I~
                uproc3pgmchk(0,pc); //issue found msg              //~v742I~
        }                                                          //~v742I~
      }                                                            //~v5kkI~
      else                                                         //~v5kkI~
      	ii=0;	//no meaning                                       //~v5kkI~
    }                                                              //~v5kkM~
    else                                                           //~v5kkM~
    	ii=Stermtbidx;                                             //~v5kkR~
	if (Popt & XGTP_GETPGMNAME)	//0:no user cmd                    //~v5kkI~
    {                                                              //~v5kkI~
	  	if (Pcmd)                                                  //~v5kkI~
 			pc=Sforcedefaultc;                                     //~v5kkI~
        else                                                       //~v5kkI~
 			pc=Sforcedefaults;                                     //~v5kkI~
      if (pc)                                                      //~v5kkI~
      {                                                            //~v5kkI~
        pc+=strspn(pc," ");                                        //~v5kkI~
        pc2=strchr(pc,' ');                                        //~v5kkI~
        if (pc2)                                                   //~v5kkI~
//      	len=(ULONG)pc2-(ULONG)pc;                              //~v5kkI~//~v6xiR~
        	len=(int)((ULONG)pc2-(ULONG)pc);                       //~v6xiI~
        else                                                       //~v5kkI~
//      	len=strlen(pc);                                        //~v5kkI~//~v6xiR~
        	len=(int)strlen(pc);                                   //~v6xiI~
        memcpy(Pout,pc,(UINT)len);                                 //~v5kkI~
        *(Pout+len)=0;                                             //~v5kkI~
      }                                                            //~v5kkI~
      else                                                         //~v5kkI~
        strcpy(Pout,Spgmtb[ii]);                                   //~v5kkI~
    }                                                              //~v5kkI~
    else                                                           //~v5kkI~
        if (Pcmd)                                                  //~v5kkR~
		  if (Sforcedefaultc)                                      //~v5kkI~
            sprintf(Pout,"%s %s",Sforcedefaultc,Pcmd);             //~v5kkI~
          else                                                     //~v5kkI~
            sprintf(Pout,"%s %s %s",Spgmtb[ii],Sopttbe[ii],Pcmd);  //~v5kkR~
        else                                                       //~v5kkR~
		  if (Sforcedefaults)                                      //~v5kkI~
            strcpy(Pout,Sforcedefaults);                           //~v5kkI~
          else                                                     //~v5kkI~
            sprintf(Pout,"%s %s",Spgmtb[ii],Sopttb[ii]);           //~v5kkR~
    return Stermid[ii];                                            //~v5kkI~
}//ulnxxgettermpgmopt                                              //~v5kkI~
//*********************************************************************//~v5kkI~
//* executable access chk by which cmd                             //~v5kkI~
//* rc=0 ok                                                        //~v5kkI~
//*********************************************************************//~v5kkI~
int uproc3pgmchk(int Popt,char *Pbinname)                          //~v5kkR~
{                                                                  //~v5kkI~
    int rc,rc2;                                                    //~v5kkR~
    char whichcmd[256];                                            //~v5kkI~
//*************************************                            //~v5kkI~
    sprintf(whichcmd,"which %s >/dev/null 2>&1",Pbinname);         //~v5kkR~
    rc=system(whichcmd);                                           //~v5kkI~
//  printf("rc=%d for %s\n",rc,whichcmd);                          //~v5kkR~
	if (!(Popt & UP3PC_NOMSG))                                     //~v5kkI~
    {                                                              //~v5kkI~
        if (rc)                                                    //~v5kkR~
        {                                                          //~v5kkR~
            rc2=errno;                                             //~v5kkR~
//          printf("??? xe: serach for %s by \"which\" cmd failed,rc=%d(errno=%d). ???\n",Pbinname,rc,rc2);//~v6s2R~
            printf("??? xe: search for %s by \"which\" cmd failed,rc=%d(errno=%d). ???\n",Pbinname,rc,rc2);//~v6s2I~
        }                                                          //~v5kkR~
        else                                                       //~v5kkR~
//          printf("    xe: use %s for shell terminal\n",Pbinname);//~v5kkR~//~v742R~
//          printf("Info:use \"%s\" as terminal program\n",Pbinname);//+v742R~
            printf("Info:uses \"%s\" as terminal program\n",Pbinname);//+v742I~
    }                                                              //~v5kkI~
    return rc;                                                     //~v5kkI~
}//uproc3pgmchk                                                    //~v5kkI~
//*********************************************************************//~v741I~
//* executable access chk by which cmd                             //~v741I~
//* rc=0 ok                                                        //~v741I~
//*********************************************************************//~v741I~
int uproc3pgmchkInifile(int Popt,char *Pbinname)                   //~v741I~
{                                                                  //~v741I~
    char binname[200],*pc;                                         //~v741I~
    char whichcmd[256];                                            //~v741I~
    int rc,rc2;                                                    //~v741I~
//*************************************                            //~v741I~
	pc=strspn(Pbinname," ")+Pbinname;                              //~v741R~
	UstrncpyZ(binname,pc,sizeof(binname));                         //~v741I~
	pc=strchr(binname,' ');                                        //~v741I~
    if (pc)                                                        //~v741I~
    	*pc=0;                                                     //~v741I~
    sprintf(whichcmd,"which %s >/dev/null 2>&1",binname);          //~v741I~
    rc=system(whichcmd);                                           //~v741I~
    if (rc)                                                        //~v741I~
    {                                                              //~v741I~
        rc2=errno;                                                 //~v741I~
        uerrexit("Inifile parm(\"%s\") err(errno=%d), which cmd failed for %s.",0,//~v741R~
					Pbinname,rc2,binname);                         //~v741I~
    }                                                              //~v741I~
    return 0;                                                      //~v741I~
}//uproc3pgmchkInifile                                             //~v741I~
//**************************************************************** //~v5gcI~
//* ulnxlaunchapp                                                  //~v5gcI~
//* apwan assciated appl                                           //~v5gcI~
//* rc:                                                            //~v5gcI~
//**************************************************************** //~v5gcI~
int usystemlnxterm(char *Poptions)                                 //~v5gcI~
{                                                                  //~v5gcI~
#ifdef XXE                                                         //~v5kkI~
#else                                                              //~v5kkI~
    int termid,simid;                                              //~v5kkI~
#endif                                                             //~v5kkI~
    int rc=0,argc;                                                 //~v5kkR~
//  char  psim[32],**argv;                                         //~v5gcR~//~v6hbR~
    UCHAR psim[32],**argv;                                         //~v6hbR~
//*********************                                            //~v5gcI~
    UTRACEP("%s:Poptions=%s\n",UTT,Poptions);                      //~v742I~
#ifdef XXE                                                         //~v5kkI~
	ulnxxgettermpgmopt(XGTP_GETPGMNAME,0,psim);	//0:no user cmd    //~v5kkI~
#else                                                              //~v5kkI~
	termid=ukbdl_gettermid();                                      //~v5gcI~
    if ((termid & TERM_IDMASK)==TERM_TTYLCONS)                     //~v5gcI~
    {                                                              //~v5gcI~
	    uerrmsg("start terminal is not avail on console screen",0);//~v5gcR~
    	return -1;                                                 //~v5gcR~
    }                                                              //~v5gcI~
	simid=termid&TERM_SIMID;                                       //~v5gcI~
	ulnxlgettermpgmopt(simid,psim,0);	//0:no option prefix required//~v5gcI~
#endif                                                             //~v5kkI~
#ifdef ARM                                                         //~v6a0I~
    uparsev(Poptions,(UCHAR ***)(ULONG)(&argv),&argc,0,0);         //~v6a0I~
#else                                                              //~v6a0I~
    uparsev(Poptions,(UCHAR ***)(&argv),&argc,0,0);                //~v5gcR~
#endif                                                             //~v6a0I~
    argv[0]=psim;                                                  //~v5gcI~
//  rc=uspawnvp(P_NOWAIT,psim,argv);                               //~v5gcI~//~v6hbR~
    rc=uspawnvp(P_NOWAIT,psim,(char**)argv);                       //~v6h9I~
    uerrmsg("started %s,pid=%d",0,                                 //~v5gcI~
            psim,rc);                                              //~v5gcI~
    ufree(argv);                                                   //~v5kmI~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v742I~
    return rc;  //return pid                                       //~v5gcI~
}//usystemlnxterm                                                  //~v5kkR~
#endif                                                             //~v5g9M~
#if defined(W32) || defined(UNX)                                   //~v5jaI~
//************************************************************     //~v5jaI~
//*sleep                                                           //~v5jaI~
//************************************************************     //~v5jaI~
void usleepms(int Pmilisec)                                        //~v5jaI~
{                                                                  //~v5jaI~
#ifdef W32                                                         //~v6p0I~
#else                                                              //~v6p0I~
    struct timespec sleeptime;                                     //~v6p0I~
#endif                                                             //~v6p0I~
//*************************                                        //~v6p0I~
#ifdef W32                                                         //~v5jaI~
	Sleep(Pmilisec);                                               //~v5jaI~
#else                                                              //~v5jaI~
//  usleep(Pmilisec*1000); 	//by microsec                          //~v5jaI~//~v6p0R~
    sleeptime.tv_sec=Pmilisec/1000;                                //~v6p0I~
    sleeptime.tv_nsec=(Pmilisec%1000)*1000000; //nanosec           //~v6p0I~
    nanosleep(&sleeptime,NULL);                                    //~v6p0I~
    UTRACEP("usleepms msec=%d,tvsec=%d,tvnsec=%d\n",Pmilisec,sleeptime.tv_sec,sleeptime.tv_nsec);//~v6p0I~
#endif                                                             //~v5jaI~
}//usleepms                                                        //~v5jaI~
#endif                                                             //~v5jaI~
                                                                   //~v5jaI~
#ifdef W32                                                         //~v5j5I~
//************************************************************     //~v5j5I~
//*connect to server with namedpipe                                //~v5j5I~
//*re rc                                                           //~v5j5I~
//************************************************************     //~v5j5I~
//int uprocconnect(int Popt,char *Pservercmd,char *Ppipename,ULONG *Pphandle)//~v5j5R~//~v6hhR~
int uprocconnect(int Popt,char *Pservercmd,char *Ppipename,ULPTR *Pphandle)//~v6hhI~
{                                                                  //~v5j5I~
	int startserver(int Popt,char *Pservercmd);                    //~v5j5R~
	int retry,errcd,rc;                                            //~v5j5I~
    HANDLE hpipe;                                                  //~v5j5I~
    ULONG mode;                                                    //~v5j5I~
#define SERVER_TIMEOUT 2      //seconds                            //~v5mFR~
//**************************************                           //~v5j5I~
   	for (retry=0;;retry++)                                         //~v5j5I~
   	{                                                              //~v5j5I~
      	hpipe=CreateFile(                                          //~v5j5I~
         					Ppipename,   // pipe name              //~v5j5I~
         					GENERIC_READ |  // read and write access//~v5j5I~
         					GENERIC_WRITE,                         //~v5j5I~
         					0,              // no sharing          //~v5j5I~
         					NULL,           // default security attributes//~v5j5I~
         					OPEN_EXISTING,  // opens existing pipe //~v5j5I~
         					0,              // default attributes  //~v5j5I~
         					NULL);          // no template file    //~v5j5I~
                                                                   //~v5j5I~
      	if (hpipe!=INVALID_HANDLE_VALUE)   	// Break if the pipe handle is valid.//~v5j5I~
         	break;                                                 //~v5j5I~
      	errcd=GetLastError();                                      //~v5j5I~
        if (errcd==ERROR_FILE_NOT_FOUND)	//server not exist     //~v5j5I~
        {                                                          //~v5j5I~
        	if (retry)                                             //~v5j5I~
            {                                                      //~v5j5I~
//          	uerrmsg("Server dose not start",0);                //~v5mFI~
            	uerrmsg("XE3270 server start timeout(%d secs),try once more",0,//~v5mFR~
						SERVER_TIMEOUT);                           //~v5mFI~
				return 4;                                          //~v5j5I~
            }                                                      //~v5j5I~
        	if (startserver(Popt,Pservercmd))                      //~v5j5I~
            	return 4;                                          //~v5j5I~
//          usleepms(1000);                                        //~v5mFR~
            usleepms(SERVER_TIMEOUT*1000);                         //~v5mFR~
            continue;                                              //~v5j5I~
        }                                                          //~v5j5I~
      	if (errcd==ERROR_PIPE_BUSY)      // Exit if an error other than ERROR_PIPE_BUSY occurs.//~v5j5I~
        {                                                          //~v5j5I~
            uerrmsg("Server busy try later",0);                    //~v5j5R~
    	    return 4;                                              //~v5j5I~
        }                                                          //~v5j5I~
        uerrapi1t(1,"CreateFile",Ppipename,-1);                    //~v5j5R~
        return 4;                                                  //~v5j5I~
   	}                                                              //~v5j5I~
   	mode=PIPE_READMODE_MESSAGE;                                    //~v5j5I~
   	rc=SetNamedPipeHandleState(                                    //~v5j5I~
      							hpipe,    // pipe handle           //~v5j5I~
      							&mode,  // new pipe mode           //~v5j5I~
      							NULL,     // don't set maximum bytes//~v5j5I~
      							NULL);    // don't set maximum time//~v5j5I~
   	if (!rc)                                                       //~v5j5I~
        return uerrapi0t(1,"SetnamedPipehandleState",-1);          //~v5j5I~
//  *Pphandle=(ULONG)hpipe;                                        //~v5j5R~//~v6hhR~
    *Pphandle=(ULPTR)hpipe;                                        //~v6hhI~
    return 0;                                                      //~v5j5I~
}//uprocconnect                                                    //~v5j5I~
//************************************************************     //~v5j5I~
//*connect to server with namedpipe                                //~v5j5I~
//*re rc                                                           //~v5j5I~
//************************************************************     //~v5j5I~
//int uprocdisconnect(ULONG Phpipe)                                //~v5jaR~
//int uprocdisconnect(ULONG *Pphpipe,char *Ppopename)                //~v5jaR~//~v6hhR~
int uprocdisconnect(ULPTR *Pphpipe,char *Ppopename)                //~v6hhI~
{                                                                  //~v5j5I~
//  CloseHandle((HANDLE)Phpipe);                                   //~v5jaR~
    CloseHandle((HANDLE)*Pphpipe);                                 //~v5jaI~
    return 0;                                                      //~v5j5I~
}//uprocdisconnect                                                 //~v5j5I~
//************************************************************     //~v5j5I~
//*msg send/receive(WIN)                                           //~v5jaR~
//************************************************************     //~v5j5I~
//int uprocpipeio(ULONG Phpipe,char *Psendmsg,char *Precvmsg,int Precvbuffsz,int *Ppreadlen)//~v5jaR~
//int uprocpipeio(ULONG *Pphpipe,char *Ppipename,char *Psendmsg,char *Precvmsg,int Precvbuffsz,int *Ppreadlen,char **Ppdata,int *Ppdatalen)//~v5jaR~//~v6hhR~
int uprocpipeio(ULPTR *Pphpipe,char *Ppipename,char *Psendmsg,char *Precvmsg,int Precvbuffsz,int *Ppreadlen,char **Ppdata,int *Ppdatalen)//~v6hhI~
{                                                                  //~v5j5I~
//  int rc,writelen,len;                                           //~v5ncR~//~v6hdR~
    int rc,len;                                                    //~v6hdI~
    DWORD writelen;                                                //~v6hdI~
    HANDLE hpipe;                                                  //~v5jaI~
//*****************************                                    //~v5j5I~
	hpipe=(HANDLE)*Pphpipe;                                        //~v5jaR~
    len=strlen(Psendmsg);                                          //~v5j5I~
   	rc=WriteFile(                                                  //~v5j5I~
//    			(HANDLE)Phpipe,                  // pipe handle    //~v5jaR~
      			hpipe,                  // pipe handle             //~v5jaI~
      			Psendmsg,	             // message                //~v5j5I~
      			len,		 			// message length          //~v5j5R~
      			&writelen,             // bytes written            //~v5j5I~
      			NULL);                  // not overlapped          //~v5j5I~
   	if (!rc)                                                       //~v5j5I~
    	return uerrapi0t(1,"WriteFile",-1);                        //~v5j5I~
   	FlushFileBuffers((HANDLE)hpipe);                               //~v5jaR~
//	rc=uprocpiperecevmsg((ULONG)hpipe,Precvmsg,Precvbuffsz,Ppreadlen,Ppdata,Ppdatalen);//~v5jaR~//~v6hhR~
	rc=uprocpiperecevmsg((ULPTR)hpipe,Precvmsg,Precvbuffsz,Ppreadlen,Ppdata,Ppdatalen);//~v6hhI~
   	return rc;                                                     //~v5j5I~
}//uprocpipeio                                                     //~v5jaR~
//************************************************************     //~v5jaI~
//* read pipe                                                      //~v5jaI~
//*return -1:eor,>0 err                                            //~v5jaI~
//************************************************************     //~v5jaI~
//int uprocpiperead(ULONG Phpipe,char *Pbuff,int Preqlen,int *Ppreadlen)//~v5jaR~//~v6hhR~
int uprocpiperead(ULPTR Phpipe,char *Pbuff,int Preqlen,int *Ppreadlen)//~v6hhI~
{                                                                  //~v5jaI~
//	int rc,readlen,ercd=0;                                         //~v5jaR~//~v6hdR~
  	int rc,ercd=0;                                                 //~v6hdI~
  	DWORD readlen;                                                 //~v6hdI~
//*****************************                                    //~v5jaI~
    rc=ReadFile(                                                   //~v5jaI~
                (HANDLE)Phpipe,    // pipe handle                  //~v5jaR~
                Pbuff,    // buffer to receive reply               //~v5jaI~
                Preqlen,  // size of buffer                        //~v5jaI~
                &readlen,  // number of bytes read                 //~v5jaI~
                NULL);    // not overlapped                        //~v5jaI~
UTRACED("piperead",Pbuff,readlen);                                 //~v5jaR~
    if (!rc)	//not success                                      //~v5jaR~
    {                                                              //~v5jaI~
        ercd=GetLastError();                                       //~v5jaI~
        if (ercd==ERROR_MORE_DATA||ercd==ERROR_PIPE_NOT_CONNECTED) //~v5jaR~
            rc=0;                                                  //~v5jaI~
        else                                                       //~v5jaI~
            return uerrapi0t(1,"ReadFile",-1);                     //~v5jaI~
    }                                                              //~v5jaI~
UTRACEP("piperead rc=%d,lasterr=%d\n",rc,ercd);                    //~v5jaI~
//  *Ppreadlen=readlen;                                            //~v5jaI~//~v6hdR~
    *Ppreadlen=(int)readlen;                                       //~v6hdI~
    if (!readlen)                                                  //~v5jaI~
    	return -1;                                                 //~v5jaR~
    return 0;                                                      //~v5jaR~
}//uprocpiperead                                                   //~v5jaI~
//************************************************************     //~v5j5I~
//*msg send/receive                                                //~v5j5I~
//************************************************************     //~v5j5I~
int startserver(int Popt,char *Pservercmd)                         //~v5j5R~
{                                                                  //~v5j5I~
//  SECURITY_ATTRIBUTES sec={sizeof(SECURITY_ATTRIBUTES),          //~v5ncR~
//  							NULL,                              //~v5ncR~
//                              TRUE};	//inherit                  //~v5ncR~
    IFDEF_WINCON(UINT mode=0);                                       //~v5maI~//~v6h7R~
//**********************************                               //~v5j5I~
#ifdef AAA                                                         //~v5j5I~
	ugetcwd(curdir);                                               //~v5j5I~
  	sprintf(cmd,"%s.exe -L%s",XE3270SERVER,XE3270_DEFAULT_LOGFILE);//~v5j5I~
    GetStartupInfo(&sinf);                                         //~v5j5I~
    if (!CreateProcess(NULL,                                       //~v5j5I~
                  cmd,                                             //~v5j5I~
                  NULL,     //inherit gotten pid=No                //~v5j5I~
                  NULL,     //inherit gotten threadid=No           //~v5j5I~
                  FALSE,     //inherit	handle=No                  //~v5j5I~
//                DETACHED_PROCESS,                                //~v5j5I~
                  CREATE_NEW_CONSOLE,                              //~v5j5I~
                  NULL,     //env is same                          //~v5j5I~
                  curdir, //cdir                                   //~v5j5I~
                  &sinf,                                           //~v5j5I~
                  &pinfo)) //output                                //~v5j5I~
		return uerrapi1t(1,"CreatePipe",cmd,-1);                   //~v5j5I~
    	uerrmsg("started server(%s) pid=%d",0,                     //~v5j5I~
    		cmd,pinfo.dwProcessId);                                //~v5j5I~
#else                                                              //~v5j5I~
	IFDEF_WINCON(if (Popt & UPROC_KEEPMODE) mode=ugetconsolemode(0));//~v5maI~
    system(Pservercmd);                                            //~v5j5I~
	IFDEF_WINCON(if (Popt & UPROC_KEEPMODE) usetconsolemode2(0/*opt*/,0/*stdin*/,mode,0/*no output prev mode*/));	//stdin row mode//~v5maR~
//  uerrmsg("started server(%s)",0,                                //~v5jaR~
//  		Pservercmd);                                           //~v5jaR~
#endif                                                             //~v5j5I~
    return 0;                                                      //~v5j5I~
}//startserver                                                     //~v5j5I~
#endif                                                             //~v5j5I~
#ifdef LNX                                                         //~v5jaI~
//************************************************************     //~v5jaI~
//*connect to server with namedpipe                                //~v5jaI~
//*return 1 fd(write to server)                                    //~v5jaR~
//*re rc                                                           //~v5jaI~
//************************************************************     //~v5jaI~
int uprocconnect(int Popt,char *Pservercmd,char *Ppipename,ULONG *Pphandle)//~v5jaI~
{                                                                  //~v5jaI~
	int startserver(int Popt,char *Pservercmd);                    //~v5jaI~
	int retry,rc,fdw;                                              //~v5jaR~
    char readpipename[_MAX_PATH];                                  //~v5jaI~
    char dupchkpipename[_MAX_PATH];                                //~v5jaI~
#define SERVER_TIMEOUT 2      //seconds                            //~v6hgI~
//    int waittime=1;                                                //~v5kkI~//~v6hgR~
      int waittime=SERVER_TIMEOUT;                                 //~v6hgI~
//**************************************                           //~v5jaI~
    sprintf(dupchkpipename,SERVERPIPELOCK,Ppipename);              //~v5jaR~
   	for (retry=0;;retry++)                                         //~v5jaI~
   	{                                                              //~v5jaI~
        fdw=open(dupchkpipename,O_WRONLY|O_NONBLOCK);    //not blocked but fail if no reader exist//~v5jaR~
        if (fdw>0)  //reader exist                                 //~v5jaR~
            break;                                                 //~v5jaR~
        if (retry)                                                 //~v5jaI~
        {                                                          //~v5jaI~
			if (access(dupchkpipename,F_OK)!=-1)  //F_OK:existance chk//~v5jaR~
            	uerrmsg("Server start failed,pipe(%s) should be cleared.",0,//~v5jaI~
    	    			dupchkpipename);                           //~v5jaR~
            else                                                   //~v5jaI~
	            uerrmsg("Server dose not start in %d second.chk pgm path for \"%s\".",0,//~v5kkR~
		        			waittime*retry,Pservercmd);            //~v5kkR~
            return 4;                                              //~v5jaI~
        }                                                          //~v5jaI~
        if (startserver(Popt,Pservercmd))                          //~v5jaI~
            return 4;                                              //~v5jaI~
        usleepms(waittime*1000);                                   //~v5kkR~
        continue;                                                  //~v5jaI~
    }                                                              //~v5jaI~
    close(fdw);	//dupchk only                                      //~v5jaI~
//BLOCK mode open(BLOCK mode required for atomic write)            //~v5jaI~
    fdw=open(Ppipename,O_WRONLY);	//block mode(wait server open by read mode)//~v5jaI~
    if (fdw<0)                                                     //~v5jaI~
    	return uerrapi1t(0,"open(SendPipe)",Ppipename,errno);      //~v5jaR~
    sprintf(readpipename,CLIENTPIPENAME,Ppipename,getpid());       //~v5jaM~
    unlink(readpipename);  //for duplicated call                   //~v5jaM~
    rc=mkfifo(readpipename,0777);                                  //~v5jaM~
    if (rc==-1)                                                    //~v5jaM~
        return uerrapi1t(0,"mkfifo(ClientReadPipe)",readpipename,errno);//~v5jaR~
//  *Pphandle=fdw;                                                 //~v5jaI~//~v6xiR~
    *Pphandle=(ULONG)fdw;                                          //~v6xiI~
    return 0;                                                      //~v5jaI~
}//uprocconnect                                                    //~v5jaI~
//************************************************************     //~v5jaI~
//*connect to server with namedpipe                                //~v5jaI~
//*re rc                                                           //~v5jaI~
//************************************************************     //~v5jaI~
//int uprocdisconnect(ULONG *Phpipe,char *Ppipename)                 //~v5jaI~//~v6hhR~
int uprocdisconnect(ULPTR *Phpipe,char *Ppipename)                 //~v6hhI~
{                                                                  //~v5jaI~
    char readpipename[_MAX_PATH];                                  //~v5jaI~
//**************************************                           //~v5jaI~
UTRACEP("pipe disconnect\n");                                      //~v5jpI~
	close((int)(*Phpipe));                                         //~v5jaI~
	close((int)(*(Phpipe+1)));                                     //~v5jaR~
    sprintf(readpipename,CLIENTPIPENAME,Ppipename,getpid());       //~v5jaI~
    unlink(readpipename);                                          //~v5jaR~
    return 0;                                                      //~v5jaI~
}//uprocdisconnect                                                 //~v5jaI~
//************************************************************     //~v5jaI~
//*msg send/receive (LNX)                                          //~v5jaR~
//*return 1 fd(read from server)                                   //~v5jaI~
//************************************************************     //~v5jaI~
//int uprocpipeio(ULONG *Phpipe,char *Ppipename,char *Psendmsg,      //~v5jaR~//~v6hhR~
int uprocpipeio(ULPTR *Phpipe,char *Ppipename,char *Psendmsg,      //~v6hhI~
				char *Precvmsg,int Precvbuffsz,int *Ppreadlen,char **Ppdata,int *Ppdatalen)//~v5jaR~
{                                                                  //~v5jaI~
	int writelen,len,fdr,fdw,rc;                                   //~v5jaR~
    PIPEMSG pipemsg;                                               //~v5jaI~
    char readpipename[_MAX_PATH];                                  //~v5jaR~
//*****************************                                    //~v5jaI~
//  len=strlen(Psendmsg);                                          //~v5jaI~//~v6xiR~
    len=(int)strlen(Psendmsg);                                     //~v6xiI~
UTRACED("send",Psendmsg,len);                                      //~v5jaI~
    if (len>MAX_PIPEMSG)                                           //~v5jaI~
    	len=MAX_PIPEMSG;                                           //~v5jaI~
    pipemsg.pid=getpid();                                          //~v5jaI~
//  memcpy(pipemsg.msg,Psendmsg,len);                              //~v5jaI~//~v6xiR~
    memcpy(pipemsg.msg,Psendmsg,(size_t)len);                      //~v6xiI~
//  len+=sizeof(pipemsg.pid);                                      //~v5jaI~//~v6xiR~
    len+=(int)sizeof(pipemsg.pid);                                 //~v6xiI~
    fdw=(int)(*Phpipe);                                            //~v5jaI~
// 	writelen=write(fdw,&pipemsg,len);                              //~v5jaI~//~v6xiR~
  	writelen=(int)write(fdw,&pipemsg,(size_t)len);                 //~v6xiI~
    if (writelen!=len)                                             //~v5jaI~
    	return uerrapi0t(1,"write pipe",errno);                    //~v5jaI~
//open response pipe(after write msg because open by block mode)   //~v5jaI~
    sprintf(readpipename,CLIENTPIPENAME,Ppipename,getpid());       //~v5jaI~
	fdr=open(readpipename,O_RDONLY);	//wait server write open   //~v5jaI~
	if (fdr<0)	//reader exist                                     //~v5jaM~
        return uerrapi1t(0,"open pipe(read)",readpipename,errno);  //~v5jaM~
//  *(Phpipe+1)=fdr;                                               //~v5jaI~//~v6xiR~
    *(Phpipe+1)=(ULPTR)fdr;                                        //~v6xiI~
//	rc=uprocpiperecevmsg((ULONG)fdr,Precvmsg,Precvbuffsz,Ppreadlen,Ppdata,Ppdatalen);//~v5jaI~//~v6hhR~
	rc=uprocpiperecevmsg((ULPTR)fdr,Precvmsg,Precvbuffsz,Ppreadlen,Ppdata,Ppdatalen);//~v6hhI~
   	return rc;                                                     //~v5jaR~
}//uprocpipeio                                                     //~v5jaI~
//************************************************************     //~v5jaI~
//*msg send/receive                                                //~v5jaI~
//************************************************************     //~v5jaI~
int startserver(int Popt,char *Pservercmd)                         //~v5jaI~
{                                                                  //~v5jaI~
//  char  **argv;                                                  //~v5kkI~//~v6hbR~
    UCHAR **argv;                                                  //~v6hbR~
    int rc,argc;                                                   //~v5kkR~
//**********************************                               //~v5jaI~
//  system(Pservercmd);   //no async option for other than gnome-terminal//~v5kkR~
#ifdef ARM                                                         //~v6a0I~
    uparsev(Pservercmd,(UCHAR ***)(ULONG)(&argv),&argc,0,0);       //~v6a0I~
#else                                                              //~v6a0I~
    uparsev(Pservercmd,(UCHAR ***)(&argv),&argc,0,0);              //~v5kkR~
#endif                                                             //~v6a0I~
//  rc=uspawnvp(P_NOWAIT,argv[0],argv);                            //~v5kkI~//~v6hbR~
    rc=uspawnvp(P_NOWAIT,argv[0],(char**)argv);                    //~v6hbI~
    ufree(argv);                                                   //~v5kkI~
    if (rc==-1)	//uspawnvp returns pid if not err                  //~v6b9I~
    	return -1;                                                 //~v6b9I~
//  uerrmsg("started server(%s)",0,                                //~v5jaR~
//  		Pservercmd);                                           //~v5jaR~
    return 0;                                                      //~v5kkR~
}//startserver                                                     //~v5jaI~
//************************************************************     //~v5jaI~
//*pipe read                                                       //~v5jaI~
//*return -1:eor,>0 err                                            //~v5jaI~
//************************************************************     //~v5jaI~
//int uprocpiperead(ULONG Phpipe,char *Pbuff,int Preqlen,int *Ppreadlen)//~v5jaI~//~v6hhR~
int uprocpiperead(ULPTR Phpipe,char *Pbuff,int Preqlen,int *Ppreadlen)//~v6hhI~
{                                                                  //~v5jaI~
	int fdr,readlen;                                               //~v5jaI~
//*************************                                        //~v5jaI~
	fdr=(int)Phpipe;                                               //~v5jaI~
//  readlen=read(fdr,Pbuff,Preqlen);                               //~v5jaI~//~v6xiR~
    readlen=(int)read(fdr,Pbuff,(size_t)Preqlen);                  //~v6xiI~
UTRACEP("pipe read req=%d,read=%d\n",Preqlen,readlen);             //~v5jaR~
UTRACED("pipe read",Pbuff,max(readlen,0));                         //~v5jaR~
    if (readlen<0)                                                 //~v5jaI~
    	return uerrapi0t(0,"read(pipe from server)",-1);           //~v5jaR~
    *Ppreadlen=readlen;                                            //~v5jaI~
    if (!readlen)                                                  //~v5jaI~
    	return -1;                                                 //~v5jaI~
    return 0;                                                      //~v5jaI~
}//uprocpiperead                                                   //~v5jaI~
#endif                                                             //~v5jaI~
//************************************************************     //~v5jaI~
//*msg send/receive                                                //~v5jaI~
//*return -1:eof reached before all data read,>0 err               //~v5jaI~
//************************************************************     //~v5jaI~
//int uprocpiperecevmsg(ULONG Phpipe,char *Precvmsg,int Precvbuffsz,int *Ppreadlen,char **Ppdata,int *Ppdatalen)//~v5jaR~//~v6hhR~
int uprocpiperecevmsg(ULPTR Phpipe,char *Precvmsg,int Precvbuffsz,int *Ppreadlen,char **Ppdata,int *Ppdatalen)//~v6hhI~
{                                                                  //~v5jaI~
	int readlen,hdrlen,msglen,datalen,rc;                          //~v5jaR~
    char *pdata;                                                   //~v5jaR~
    PPIPERESPMSG prespmsghdr;                                      //~v5jaR~
//*****************************                                    //~v5jaI~
//*read hdr                                                        //~v5jaI~
    hdrlen=PIPERESPMSGHDRSZ;                                       //~v5jaI~
    rc=uprocpiperead(Phpipe,Precvmsg,hdrlen,&readlen);             //~v5jaI~
    if (rc)                                                        //~v5jaI~
    	return rc;                                                 //~v5jaI~
//  prespmsghdr=(PPIPERESPMSG)(ULONG)Precvmsg;                     //~v5jaI~//~v6hhR~
    prespmsghdr=(PPIPERESPMSG)(ULPTR)Precvmsg;                     //~v6hhI~
    msglen=prespmsghdr->msglen;                                    //~v5jaR~
    datalen=prespmsghdr->datalen;                                  //~v5jaR~
    rc=uprocpipeiodata(Phpipe,Precvmsg+hdrlen,Precvbuffsz-hdrlen-1,msglen,&readlen);//~v5jaR~
    if (rc)                                                        //~v5jaI~
    	return rc;                                                 //~v5jaI~
    *(Precvmsg+hdrlen+readlen)=0;                                  //~v5jaI~
    *Ppreadlen=readlen;                                            //~v5jaI~
    if (datalen && Ppdata)                                         //~v5jaI~
    {                                                              //~v5jaI~
//      pdata=umalloc(datalen);                                    //~v5jaR~//~v6xiR~
        pdata=umalloc((size_t)datalen);                            //~v6xiI~
    	rc=uprocpipeiodata(Phpipe,pdata,0,datalen,&readlen);       //~v5jaR~
    	if (!rc)                                                   //~v5jaR~
    	{                                                          //~v5jaR~
            *Ppdata=pdata;                                         //~v5jaI~
            *Ppdatalen=readlen;                                    //~v5jaR~
        }                                                          //~v5jaI~
        else                                                       //~v5jaI~
        {                                                          //~v5jpI~
            ufree(pdata);                                          //~v5jaI~
            if (rc>0)                                              //~v5jpI~
                return rc;                                         //~v5jpI~
        }                                                          //~v5jpI~
    }                                                              //~v5jaI~
   	return 0;                                                      //~v5jaI~
}//uprocpiperecevmsg                                               //~v5jaI~
//************************************************************     //~v5jaM~
//*msg and data read                                               //~v5jaI~
//*return -1:eof before full data get ,>0 err                      //~v5jaM~
//************************************************************     //~v5jaM~
//int uprocpipeiodata(ULONG Phpipe,char *Pbuff,int Pbufflen,int Preqlen,int *Ppreadlen)//~v5jaI~//~v6hhR~
int uprocpipeiodata(ULPTR Phpipe,char *Pbuff,int Pbufflen,int Preqlen,int *Ppreadlen)//~v6hhI~
{                                                                  //~v5jaM~
	int reslen,rc=0,readlen,reqlen,len;                            //~v5jaR~
    char *pc;                                                      //~v5jaM~
    char buff[4096];                                               //~v5jaM~
//*****************************                                    //~v5jaM~
	if (Pbufflen)      //buffsz limit                              //~v5jaM~
		reqlen=min(Pbufflen,Preqlen);                              //~v5jaM~
    else                                                           //~v5jaM~
    	reqlen=Preqlen;                                            //~v5jaM~
	for (pc=Pbuff,reslen=reqlen;reslen>0;reslen-=readlen,pc+=readlen)//~v5jaM~
    {                                                              //~v5jaM~
    	rc=uprocpiperead(Phpipe,pc,reslen,&readlen);               //~v5jaI~
        if (rc>0)                                                  //~v5jaI~
        	return rc;                                             //~v5jaI~
        if (rc<0)	//eof                                          //~v5jaI~
        	break;                                                 //~v5jaM~
	}                                                              //~v5jaM~
    if (reslen && rc<0)     //eof reached before all data read     //~v5jpI~
    {                                                              //~v5jpI~
        uerrmsg("pipe read failed(reached EOF remaining more len=%d data)",0,//~v5jpR~
                    reslen);                                       //~v5jpI~
		return U3CR_RC_OTHER;                                      //~v5jpI~
    }                                                              //~v5jpI~
    if (reqlen<Preqlen) //buff short                               //~v5jaM~
    {                                                              //~v5jaM~
        if (rc<0)    //eof                                         //~v5jaI~
        	return -1;                                             //~v5jaM~
        for (reslen=Preqlen-reqlen;reslen>0;reslen-=readlen)       //~v5jaM~
        {                                                          //~v5jaM~
//          len=min(sizeof(buff),reslen);                          //~v5jaM~//~v6xiR~
            len=min((int)sizeof(buff),reslen);                     //~v6xiI~
	    	rc=uprocpiperead(Phpipe,buff,len,&readlen);            //~v5jaI~
       		if (rc>0)                                              //~v5jaI~
        		return rc;                                         //~v5jaI~
            if (rc<0)                                              //~v5jaI~
                break;                                             //~v5jaM~
        }                                                          //~v5jaM~
//      if (reslen)     //eof reached                              //~v5jpR~
//      	return -1;                                             //~v5jpR~
    }                                                              //~v5jaM~
    *Ppreadlen=reqlen;                                             //~v5jaM~
   	return 0;                                                      //~v5jaM~
}//uprocpipeiodata                                                 //~v5jaM~
