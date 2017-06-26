//CID://+v6BRR~: update#=    193                                   //~v6BRR~
//*************************************************************
//v6Hp:170121 UstrncpyZW may clear source field                    //+v6BRI~
//v6BR:160319 (W32)Bug of 6BS, E A?" cmd disply errmsg 0xccccc(uninitialized area) because wincp2ucs1 return rc=4 by "?" is contained to output//~v6BRI~
//v6Bi:160212 (W32)compiler warning                                //~v6BjI~
//v6un:140502 MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;pass it not W func as is//~v6unI~
//v6u9:140408 (Win)use UNICODE Api using special filename fmt.     //~v6ktI~
//v6kt:130706 (W32:BUG) not CloseHandle but FindClose for FindFirst//~v6ktI~
//v6kn:130704 (W32)copy timestamp for slink copy                   //~v6knI~
//v6ki:130702 GetVolumePathNamesForVolumeName is not on vc6,no chk if not VC10//~v6kiI~
//v6kh:130702 FSCT_GET_REPARSE_POINT requires _WIN32_WINNT>=0x0500 //~v6khI~
//v6k9:130623 slink copy file target option                        //~v6k9I~
//v6k4:130525 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//                 source copy from junction.c by Mark Russinovich //~v6k4I~
//v6hd:120616 for VC6:/W4 warning(C4057)                           //~v6hdI~
//v5g2:050509 (WXE:BUG)association chk ABEND;when right btn down after selected file with no assiciation defined//~v5g2I~
//v5c1:040321 add file association chk sub                         //~v5c1I~
//*************************************************************
//#define _WIN32_WINNT 0x0500 //VC++ disposal for W95,W98,ME,NT;reuired to use disposed macro//~v6k4R~
// 0501:XP, 0600:vista, 0502:Server20003, 0601:W7, 0602:W8         //~v6k4R~
#ifndef VC10EXP                                                    //~v6khI~
	#define _WIN32_WINNT 0x0500 //VC++ disposal for W95,W98,ME,NT;reuired to use disposed macro//~v6khI~
#endif                                                             //~v6khI~
#include <windows.h>                                               //~v6k4I~
#include <winbase.h>                                               //~v6k4I~
#include <winioctl.h>                                              //~v6k4I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <io.h>                     //v3.7a
#include <errno.h>                     //v3.7a                     //~v6u9I~
#include <wchar.h>                                                 //+v6BRI~
//*************************
//#define WIN32_NO_STATUS                                          //~v6k4R~
//#define _WDMDDK_ //wdm.h dup with winnt                          //~v6k4I~
//#define _NTDDK_   //ntddk.h dup with winnt                       //~v6k4I~
//#include <api/windows.h>    //WDK71                              //~v6k4R~
//#include <api/winnt.h>    //WDK71                                //~v6k4I~
//#include <ddk/ntifs.h>                                           //~v6k4R~
//#include <windows.h>                                             //~v6k4R~
#include <tchar.h>                                                 //~v6k4I~
//*************************
#include <ulib.h>
#include <uerr.h>
#include <udos.h>
#include <uwinsub.h>                                               //~v5c1R~
#include <udbcschk.h>                                              //~v6k4I~
#include <ucvucs.h>                                                //~v6k4R~
#include <ucvext.h>                                                //~v6k4I~
#include <ucvext2.h>                                               //~v6k4I~
#include <utrace.h>                                                //~v6k4I~
#include <ufile.h>                                                 //~v6k4I~
#include <ufile2.h>                                                //~v6k4I~
#include <ufile3.h>                                                //~v6k4I~
#include <ufile4.h>                                                //~v6k9I~
#include <ualloc.h>                                                //~v6k4I~
#include <uproc.h>                                                 //~v6k4I~
#include <ufilew.h>                                                //~v6u9I~
//************************************************************     //~v5c1I~
//int uwinreg_keysetvalue(UCHAR *Pkeyname,UCHAR *Pkeyvalue,UINT *Pdisp);//~v5c1I~//~v6hdR~
int uwinreg_keysetvalue(UCHAR *Pkeyname,UCHAR *Pkeyvalue,DWORD *Pdisp);//~v6hdI~
//int uwinreg_keygetvalue(UCHAR *Pkeyname,UCHAR *Pkeyvalue,UINT *Pvaluelen);//~v5c1I~//~v6hdR~
int uwinreg_keygetvalue(UCHAR *Pkeyname,UCHAR *Pkeyvalue,DWORD *Pvaluelen);//~v6hdI~
int uwinsuberr(int Prc,char *Pfnm);                                //~v6k4I~
int uwincopyerr(int Prc,char *Psrc,char *Pdest);                   //~v6k4I~
int uwincopyerrnotarget(int Prc,char *Psrc,char *Ptarget);         //~v6k4I~
int uwincopyerrmountpoint(int Prc,char *Psrc,char *Pdest);         //~v6k4I~
int uwincopymountpointerrnotarget(int Prc,char *Psrc,char *Pdest); //~v6k4I~
int uwincopysymlinkerrprevilege(int Prc,char *Psrc,char *Pdest);   //~v6k4I~
//************************************************************     //~v5c1R~
//*chk association                                                 //~v5c1I~
//* chk registry entry .xxx-->yyyy\shell\Open\command,type=REG_SZ  //~v5c1I~
//************************************************************     //~v5c1I~
int uwinreg_chkassociation(char *Pext)                             //~v5c1I~
{                                                                  //~v5c1I~
//  HKEY hkey=0;                                                   //~v5c1I~//~v6hdR~
    int  rc;                                                       //~v5c1R~
//  UINT ulen;                                                     //~v5c1I~//~v6hdR~
    DWORD ulen;                                                    //~v6hdI~
    char assocregkey[_MAX_PATH];                                   //~v5c1R~
    char assocapp[_MAX_PATH];                                      //~v5c1R~
//**************************                                       //~v5c1I~
    ulen=sizeof(assocregkey);                                      //~v5c1I~
	rc=uwinreg_keygetvalue(Pext,assocregkey,&ulen);                //~v5c1R~
    if (!rc)                                                       //~v5c1I~
    {                                                              //~v5c1I~
    	strcat(assocregkey,"\\shell\\Open\\command");              //~v5c1R~
    	ulen=sizeof(assocapp);                                     //~v5c1I~
		rc=uwinreg_keygetvalue(assocregkey,assocapp,&ulen);        //~v5c1R~
        if (!rc)                                                   //~v5c1I~
        	if (!ulen)                                             //~v5c1R~
            	rc=4;                                              //~v5c1I~
    }                                                              //~v5c1I~
    return rc==0;                                                  //~v5c1I~
}//uwinreg_chkassociation                                          //~v5c1I~
//************************************************************     //~v5c1I~
//int uwinreg_keysetvalue(UCHAR *Pkeyname,UCHAR *Pkeyvalue,UINT *Pdisp)//~v5c1I~//~v6hdR~
int uwinreg_keysetvalue(UCHAR *Pkeyname,UCHAR *Pkeyvalue,DWORD *Pdisp)//~v6hdI~
{                                                                  //~v5c1I~
    HKEY hkey=0;                                                   //~v5c1I~
    LONG rc;                                                       //~v5c1I~
//**************************                                       //~v5c1I~
    rc=RegCreateKeyEx(HKEY_CLASSES_ROOT,//parent key               //~v5c1I~
                           Pkeyname,      //keyname                //~v5c1I~
                           0,                //rsv                 //~v5c1I~
                           "",               //key class           //~v5c1I~
                           REG_OPTION_VOLATILE,          //opt     //~v5c1I~
                           KEY_ALL_ACCESS|KEY_EXECUTE|KEY_SET_VALUE,//access option//~v5c1I~
                           NULL,			//security             //~v5c1I~
                           &hkey,			//output handle        //~v5c1I~
                           Pdisp);			//created or opened    //~v5c1I~
//  printf("CreateKey:rc=%d,hkey=%08x,disp=%08x\n",rc,hkey,*Pdisp);//~v5c1R~
    if (rc!=ERROR_SUCCESS)                                         //~v5c1I~
    	return rc;                                                 //~v5c1I~
    rc=RegSetValueEx(hkey,      //key                              //~v5c1I~
                       "",           //name                        //~v5c1I~
                       0,                //rsv                     //~v5c1I~
                       REG_SZ,           //data type               //~v5c1I~
                       Pkeyvalue,           //value                //~v5c1I~
                       strlen(Pkeyvalue));                         //~v5c1I~
//  printf("SetValue:rc=%d\n",rc);                                 //~v5c1R~
    rc=RegCloseKey(hkey);       //key                              //~v5c1I~
//  printf("CloseKey:rc=%d\n",rc);                                 //~v5c1R~
    return 0;                                                      //~v5c1I~
}//uwinreg_keysetvalue                                             //~v5c1I~
//int uwinreg_keygetvalue(UCHAR *Pkeyname,UCHAR *Pkeyvalue,UINT *Pvaluelen)//~v5c1I~//~v6hdR~
int uwinreg_keygetvalue(UCHAR *Pkeyname,UCHAR *Pkeyvalue,DWORD *Pvaluelen)//~v6hdI~
{                                                                  //~v5c1I~
    HKEY hkey=0;                                                   //~v5c1I~
    LONG rc;                                                       //~v5c1I~
    ULONG dwtype;                                                  //~v5c1I~
//**************************                                       //~v5c1I~
    rc=RegOpenKeyEx(HKEY_CLASSES_ROOT,//parent key                 //~v5c1I~
                           Pkeyname,      //keyname                //~v5c1I~
                           0,                //rsv                 //~v5c1I~
                           KEY_ALL_ACCESS|KEY_EXECUTE|KEY_SET_VALUE,//access option//~v5c1I~
                           &hkey);			//output handle        //~v5c1I~
//  printf("OpenKey:keyname=%s,rc=%d,hkey=%08x\n",Pkeyname,rc,hkey);//~v5c1R~
    if (rc!=ERROR_SUCCESS)                                         //~v5c1I~
    	return rc;                                                 //~v5c1I~
    rc=RegQueryValueEx(hkey,        //key                          //~v5c1I~
                       "",           //name                        //~v5c1I~
                       0,                //rsv                     //~v5c1I~
                       &dwtype,           //data type              //~v5c1I~
                       Pkeyvalue,           //value                //~v5c1I~
                       Pvaluelen);                                 //~v5c1I~
//  printf("QueryValue:rc=%d,value=%s,type=%08x,len=%d\n",rc,Pkeyvalue,dwtype,*Pvaluelen);//~v5c1R~
//  rc=RegCloseKey(hkey);       //key                              //~v5g2R~
    rc+=RegCloseKey(hkey);       //key                             //~v5g2I~
//  printf("CloseKey:rc=%d\n",rc);                                 //~v5c1R~
//  return 0;                                                      //~v5g2R~
    return rc;                                                     //~v5g2I~
}//uwinreg_keygetvalue                                             //~v5c1I~
int uwinreg_keydeletevalue(UCHAR *Pkeyname)                        //~v5c1I~
{                                                                  //~v5c1I~
    HKEY hkey=0;                                                   //~v5c1I~
    LONG rc;                                                       //~v5c1I~
//**************************                                       //~v5c1I~
    rc=RegOpenKeyEx(HKEY_CLASSES_ROOT,//parent key                 //~v5c1I~
                           Pkeyname,      //keyname                //~v5c1I~
                           0,                //rsv                 //~v5c1I~
                           KEY_ALL_ACCESS|KEY_EXECUTE|KEY_SET_VALUE,//access option//~v5c1I~
                           &hkey);			//output handle        //~v5c1I~
//  printf("OpenKey:rc=%d,hkey=%08x\n",rc,hkey);                   //~v5c1R~
    if (rc!=ERROR_SUCCESS)                                         //~v5c1I~
    	return rc;                                                 //~v5c1I~
    rc=RegDeleteValue(hkey,        //key                           //~v5c1I~
                      NULL);                                       //~v5c1I~
//  printf("DeleteValue:rc=%d\n",rc);                              //~v5c1R~
    rc=RegCloseKey(hkey);       //key                              //~v5c1I~
//  printf("CloseKey:rc=%d\n",rc);                                 //~v5c1R~
    return 0;                                                      //~v5c1I~
}//uwinreg_keydeletevalue                                          //~v5c1I~
//**************************************************************   //~v6k4I~
//*from junction.c                                                 //~v6k4I~
//**************************************************************   //~v6k4I~
#define TAG_SYMLINK 0xa000000c  //IO_REPARSE_TAG_SYMLINK:      //0xa000000c//~v6k4R~
#ifndef MAXIMUM_REPARSE_NBUFFER_SIZE                               //~v6k4I~
	#define MAX_REPARSE_SIZE   17000 // MAXIMUM_REPARSE_NBUFFER_SIZE //16*1024 17000  //16k+hdr//~v6k4I~
#else                                                              //~v6k4I~
	#define MAX_REPARSE_SIZE   MAXIMUM_REPARSE_NBUFFER_SIZE        //~v6k4I~
#endif                                                             //~v6k4I~
#define MAX_NAME_LENGTH  (_MAX_PATH*sizeof(UWCHART))       //  1024                                   //~3610I~//~v6k4R~
#define PREFIXCTR   4                                              //~v6k4M~
#define VOL_PREFIX "\\\\?\\"                                       //~v6k4R~
#ifndef SYMBOLIC_LINK_FLAG_DIRECTORY 	//WINNT>=0x0600(Vista)     //~v6k4R~
	#define SYMBOLIC_LINK_FLAG_DIRECTORY     1                     //~v6k4I~
#endif                                                             //~v6k4I~
//int outmbs(UWCHART *Ptch,int Plen,char *Pch,int Pbuffsz,int *Ppoutlen);//~v6k4R~//~v6ktR~
//**********************************************************       //~v6k9I~
int isNtfs(int Prc,char *Pdest)                                    //~v6k9I~
{                                                                  //~v6k9I~
    int rc=0;                                                      //~v6k9I~
//***********************                                          //~v6k9I~
    if (ufileisntfs(*Pdest)!=1)                                    //~v6k9R~
    {                                                              //~v6k9I~
    	uerrmsg("%s is not on NTFS",                               //~v6k9I~
                "%s はNTFSボリュームにありません",                 //~v6k9R~
                Pdest);                                            //~v6k9I~
      	rc=UWINLNKERR_NOTNTFS;  //      -11    //junction to file  //~v6k9I~
    }                                                              //~v6k9I~
    UTRACEP("isNtfs rc=%d,dest=%s\n",rc,Pdest);                    //~v6k9I~
    return rc;                                                     //~v6k9I~
}                                                                  //~v6k9I~
//**************************************************************   //~v6k4I~
//--------------------------------------------------------------------//~3610I~//~v6k4I~
//                                                                 //~3610I~//~v6k4I~
// Junction                                                        //~3610I~//~v6k4I~
// Copyright (C) 1999 Mark Russinovich                             //~3610I~//~v6k4I~
// Systems Internals - http://www.sysinternals.com                 //~3610I~//~v6k4I~
//                                                                 //~3610I~//~v6k4I~
// Reparse point-related definitions and typedefs.                 //~3610I~//~v6k4I~
//                                                                 //~3610I~//~v6k4I~
//--------------------------------------------------------------------//~3610I~//~v6k4I~
                                                                   //~3610I~//~v6k4I~
//                                                                 //~3610I~//~v6k4I~
// Undocumented FSCTL_SET_REPARSE_POINT structure definition       //~3610I~//~v6k4I~
//                                                                 //~3610I~//~v6k4I~
#define REPARSE_MOUNTPOINT_HEADER_SIZE   8                         //~3610I~//~v6k4I~
typedef struct {                                                   //~3610I~//~v6k4I~
    DWORD          ReparseTag;                                     //~3610I~//~v6k4I~
    DWORD          ReparseDataLength;                              //~3610I~//~v6k4I~
    WORD           Reserved;                                       //~3610I~//~v6k4I~
    WORD           ReparseTargetLength;                            //~3610I~//~v6k4I~
    WORD           ReparseTargetMaximumLength;                     //~3610I~//~v6k4I~
    WORD           Reserved1;                                      //~3610I~//~v6k4I~
    WCHAR          ReparseTarget[1];                               //~3610I~//~v6k4I~
} REPARSE_MOUNTPOINT_DATA_BUFFER, *PREPARSE_MOUNTPOINT_DATA_BUFFER;//~3610I~//~v6k4I~
//**************************************************************   //~v6k4I~
//*copyed from wdk710\inc\ddk\ntifs.h                              //~v6k4I~
//*when included fully, many duplicate define warning              //~v6k4I~
//**************************************************************   //~v6k4I~
#ifndef REPARSE_DATA_BUFFER_HEADER_SIZE //VC6 winnt.h defines it   //~v6k4I~
    #pragma warning(push)                                          //~v6k4R~
    #pragma warning(disable:4201)       // unnamed struct          //~v6k4R~
    #define SYMLINK_FLAG_RELATIVE   1                              //~v6k4R~
    typedef struct _REPARSE_DATA_BUFFER {                          //~v6k4R~
        ULONG  ReparseTag;                                         //~v6k4R~
        USHORT ReparseDataLength;                                  //~v6k4R~
        USHORT Reserved;                                           //~v6k4R~
        union {                                                    //~v6k4R~
            struct {                                               //~v6k4R~
                USHORT SubstituteNameOffset;                       //~v6k4R~
                USHORT SubstituteNameLength;                       //~v6k4R~
                USHORT PrintNameOffset;                            //~v6k4R~
                USHORT PrintNameLength;                            //~v6k4R~
                ULONG Flags;                                       //~v6k4R~
                WCHAR PathBuffer[1];                               //~v6k4R~
            } SymbolicLinkReparseBuffer;                           //~v6k4R~
            struct {                                               //~v6k4R~
                USHORT SubstituteNameOffset;                       //~v6k4R~
                USHORT SubstituteNameLength;                       //~v6k4R~
                USHORT PrintNameOffset;                            //~v6k4R~
                USHORT PrintNameLength;                            //~v6k4R~
                WCHAR PathBuffer[1];                               //~v6k4R~
            } MountPointReparseBuffer;                             //~v6k4R~
            struct {                                               //~v6k4R~
                UCHAR  DataBuffer[1];                              //~v6k4R~
            } GenericReparseBuffer;                                //~v6k4R~
        } DUMMYUNIONNAME;                                          //~v6k4R~
    } REPARSE_DATA_BUFFER, *PREPARSE_DATA_BUFFER;                  //~v6k4R~
    #define REPARSE_DATA_BUFFER_HEADER_SIZE   FIELD_OFFSET(REPARSE_DATA_BUFFER, GenericReparseBuffer)//~v6k4R~
    #pragma warning(pop)                                           //~v6k4R~
#endif                                                             //~v6k4I~
//**************************************************************   //~v6k4I~
//*delete Junction/SymLink by rmdir                                //~v6k4I~
//*rc:0 or GetLastError                                            //~v6k4I~
//**************************************************************   //~v6k4I~
int uwinlnk_delete(int Popt,ULONG Pattr,char *Pfnm)                //~v6k4R~
{                                                                  //~v6k4I~
//  BOOL rcb;                                                      //~v6u9R~
    int rc,tag,len;                                                //~v6k4R~
    ULONG attr;                                                    //~v6k4I~
    char target[_MAX_PATH];                                        //~v6k4I~
//****************************************                         //~v6k4I~
	UTRACEP("uwinlnk_delete attr=%x,fnm=%s\n",Pattr,Pfnm);         //~v6k4I~
#ifdef W32UNICODE                                                  //~v6u9I~
	rc=uwinlnk_gettargetW(Popt,Pattr,Pfnm,target,sizeof(target),&len,&attr,&tag,NULL/*repasebuffer*/,NULL/*targetW*/,0,NULL,NULL/*Ppudrc*);//~v6u9R~
#else                                                              //~v6u9I~
	rc=uwinlnk_gettarget(Popt,Pattr,Pfnm,target,sizeof(target),&len,&attr,&tag,NULL/*repasebuffer*/);//~v6k4R~
#endif                                                             //~v6u9I~
    if (!rc)                                                       //~v6k4I~
    {                                                              //~v6k4I~
    	switch(tag)                                                //~v6k4I~
        {                                                          //~v6k4I~
//      case IO_REPARSE_TAG_SYMLINK:      //0xa000000c             //~v6k4R~
        case TAG_SYMLINK:      //0xa000000c                        //~v6k4I~
        	if(attr & FILE_ATTRIBUTE_DIRECTORY)                    //~v6k4I~
            {                                                      //~v6k4I~
				UTRACEP("uwinlnk_delete removedir for symlink dir\n");//~v6k4I~
//FIXME:FIXED                                                      //~v6u9R~
//  	    	rcb=RemoveDirectory(Pfnm);                         //~v6u9R~
//  	    	if (!rcb)                                          //~v6u9R~
            	if (urmdir(Pfnm))                                  //~v6u9I~
    				rc=GetLastError();                             //~v6k4I~
            }                                                      //~v6k4I~
            else                                                   //~v6k4I~
            {                                                      //~v6k4I~
//FIXME:FIXED                                                      //~v6u9R~
            	rc=uremove(Pfnm);                                  //~v6k4I~
				UTRACEP("uwinlnk_delete remove for symlink file\n");//~v6k4I~
            }                                                      //~v6k4I~
            break;                                                 //~v6k4I~
        case IO_REPARSE_TAG_MOUNT_POINT:	//MOUNT POINT or JUNCTION//~v6k4R~
//FIXME:FIXED no caller                                            //~v6u9R~
//      	rcb=RemoveDirectory(Pfnm);                             //~v6u9R~
//      	if (!rcb)                                              //~v6u9R~
            if (urmdir(Pfnm))                                      //~v6u9I~
    			rc=GetLastError();                                 //~v6k4I~
			UTRACEP("uwinlnk_delete removedir for Junction file/dir\n");//~v6k4R~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
    }                                                              //~v6k4I~
    return rc;                                                     //~v6k4I~
}//uwinlnk_delete                                                  //~v6k4I~
//**************************************************************   //~v6k4I~
//*delete Junction/SymLink by rmdir                                //~v6k4I~
//*rc:0 or GetLastError                                            //~v6k4I~
//**************************************************************   //~v6k4I~
int uwinlnk_gettarget(int Popt,ULONG Pattr,char *Pfnm,char *Ptarget,int Poutbuffsz,//~v6k4R~
					int *Ppoutlen,ULONG *Ppattr,int *Pptag,PBYTE *Pprepasebuff)//~v6k4R~
{                                                                  //~v6k4I~
    HANDLE   fileHandle=NULL;                                      //~v6k4R~
    BYTE     *reparseBuffer;                                       //~v6k4R~
    PBYTE    reparseData;                                          //~v6k4I~
    PREPARSE_GUID_DATA_BUFFER reparseInfo;                         //~v6k4R~
    PREPARSE_DATA_BUFFER msReparseInfo;                            //~v6k4R~
    DWORD   returnedLength;                                        //~v6k4I~
//    TCHAR   name[MAX_NAME_LENGTH];                               //~v6k4R~
    UWCHART  name1[MAX_NAME_LENGTH];                               //~v6k4R~
    ULONG attr;                                                    //~v6k4I~
    int rc=0;                                                      //~v6k4I~
    LPCSTR pfnm;                                                   //~v6k4I~
    int len,offs=0,flag,swfilejunction=0,swreparse=0;              //~v6k4R~
    UWCHART prefix[PREFIXCTR]={'\\','?','?','\\'};                 //~v6k4R~
//****************************                                     //~v6k4I~
	UTRACEP("uwinlnk_gettarget attr=%x,fnm=%s\n",Pattr,Pfnm);      //~v6k4R~
    reparseBuffer=umalloc(MAX_REPARSE_SIZE);                       //~v6k4R~
    if (!reparseBuffer)                                            //~v6k4R~
    	return UWINLNKERR_MALLOCERR;                               //~v6k4I~
    reparseInfo=(PREPARSE_GUID_DATA_BUFFER)reparseBuffer;          //~v6k4I~
    msReparseInfo=(PREPARSE_DATA_BUFFER)reparseBuffer;             //~v6k4I~
    *Ptarget=0;                                                    //~v6k4I~
    *Ppoutlen=0;                                                   //~v6k4I~
    pfnm=Pfnm;                                                     //~v6k4R~
	if (Pattr==-1)                                                 //~v6k4I~
    {                                                              //~v6k4I~
    	attr=GetFileAttributes(pfnm);	//dir bit on also for junction to file//~v6k4R~
	 	swreparse=(attr & FILE_ATTRIBUTE_REPARSE_POINT);           //~v6k4I~
	}                                                              //~v6k4I~
    else                                                           //~v6k4I~
    {                                                              //~v6k4I~
    	attr=Pattr;                                                //~v6k4I~
        if (Popt & UWINGTO_W32ATTR)	//from ufilew32getslink,attr is value of FindFirstFile//~v6k4I~
		 	swreparse=(attr & FILE_ATTRIBUTE_REPARSE_POINT);       //~v6k4I~
        else                                                       //~v6k4I~
        {                                                          //~v6k4I~
        	swreparse=(Pattr & FILE_SLINK);                        //~v6k4I~
        	swfilejunction=FILE_MODEISNTFS_JUNCTION2FILE(Pattr);   //~v6k4I~
        }                                                          //~v6k4I~
    }                                                              //~v6k4I~
    if (Ppattr)                                                    //~v6k4I~
    	*Ppattr=attr;                                              //~v6k4I~
    for (;;)                                                       //~v6k4I~
    {                                                              //~v6k4I~
	 	if (!swreparse)                                            //~v6k4R~
        {                                                          //~v6k4I~
    	    rc=UWINLNKERR_NOTREPARSE;                              //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
        flag=FILE_FLAG_OPEN_REPARSE_POINT;                         //~v6k4I~
        if(attr & FILE_ATTRIBUTE_DIRECTORY )                       //~v6k4I~
        	flag|=FILE_FLAG_BACKUP_SEMANTICS;                      //~v6k4I~
        else                                                       //~v6k4I~
        	if (swfilejunction)                                    //~v6k4I~
	        	flag|=FILE_FLAG_BACKUP_SEMANTICS;                  //~v6k4I~
        fileHandle=CreateFile(pfnm, 0,                             //~v6k4I~
                        FILE_SHARE_READ|FILE_SHARE_WRITE, NULL,    //~v6k4I~
                        OPEN_EXISTING,                             //~v6k4I~
                        flag,0);                                   //~v6k4I~
	 	if (fileHandle==INVALID_HANDLE_VALUE)                      //~v6k4R~
        {                                                          //~v6k4I~
    	    rc=GetLastError();                                     //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
        if(!DeviceIoControl(fileHandle,FSCTL_GET_REPARSE_POINT,    //~v6k4I~
                        NULL, 0, reparseInfo,MAX_REPARSE_SIZE,     //~v6k4R~
                        &returnedLength,NULL))                     //~v6k4I~
        {                                                          //~v6k4I~
            rc=GetLastError();                                     //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
        UTRACED("uwinsub DeviceIoControl out",reparseInfo,returnedLength);//~v6k4I~
    	if(!IsReparseTagMicrosoft(reparseInfo->ReparseTag))        //~v6k4I~
		{                                                          //~v6k4I~
    	    rc=UWINLNKERR_NOTMF;                                   //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
        if (Pptag)                                                 //~v6k4I~
        	*Pptag=reparseInfo->ReparseTag;                        //~v6k4I~
        switch( reparseInfo->ReparseTag )                          //~v6k4I~
        {                                                          //~v6k4I~
//      case 0x80000000|IO_REPARSE_TAG_SYMBOLIC_LINK:              //~v6k4R~
//      case IO_REPARSE_TAG_SYMLINK:      //0xa000000c             //~v6k4R~
        case TAG_SYMLINK:      //0xa000000c                        //~v6k4I~
                    //                                             //~v6k4I~
                    // I don't know if this is a valid reparse point//~v6k4I~
                    //                                             //~v6k4I~
        	reparseData = (PBYTE) &msReparseInfo->SymbolicLinkReparseBuffer.PathBuffer;//~v6k4I~
//            _tcsncpy( name,                                      //~v6k4R~
//                      (PWCHAR) (reparseData + msReparseInfo->SymbolicLinkReparseBuffer.PrintNameOffset),//~v6k4R~
//                      msReparseInfo->SymbolicLinkReparseBuffer.PrintNameLength );//~v6k4R~
//            name[msReparseInfo->SymbolicLinkReparseBuffer.PrintNameLength] = 0;//~v6k4R~
			len=msReparseInfo->MountPointReparseBuffer.PrintNameLength;//~v6k4I~
            if (len!=0)	//print name                               //~v6k4I~
            {                                                      //~v6k4I~
	            memcpy(name1,(reparseData + msReparseInfo->MountPointReparseBuffer.PrintNameOffset),len);//~v6k4I~
            	UTRACED("MOUNTPOINT printname",name1,len);         //~v6k4I~
            }                                                      //~v6k4I~
            else                                                   //~v6k4I~
            {                                                      //~v6k4I~
            	len=msReparseInfo->SymbolicLinkReparseBuffer.SubstituteNameLength;//~v6k4R~
            	memcpy(name1,(reparseData + msReparseInfo->SymbolicLinkReparseBuffer.SubstituteNameOffset),len);//~v6k4R~
            }                                                      //~v6k4I~
            name1[len] = 0;                                        //~v6k4R~
            UTRACED("SYMLINK",name1,len);                          //~v6k4I~
            offs=0;                                                //~v6k4I~
            if (!memcmp(name1,prefix,PREFIXCTR*sizeof(UWCHART))) //"\??\"//~v6k4I~
            {                                                      //~v6k4I~
                len-=PREFIXCTR*sizeof(UWCHART);                    //~v6k4I~
                offs=PREFIXCTR;                                    //~v6k4I~
            }                                                      //~v6k4I~
//          rc=outmbs(name1+offs,len,Ptarget,Poutbuffsz,Ppoutlen); //~v6k4R~//~v6u9R~
            rc=outmbs(0,name1+offs,len,Ptarget,Poutbuffsz,Ppoutlen);//~v6u9I~
            break;                                                 //~v6k4I~
        case IO_REPARSE_TAG_MOUNT_POINT:                           //~v6k4I~
                    //                                             //~v6k4I~
                    // Mount points and junctions                  //~v6k4I~
                    //                                             //~v6k4I~
            offs=0;                                                //~v6k4I~
        	reparseData = (PBYTE) &msReparseInfo->MountPointReparseBuffer.PathBuffer;//~v6k4I~
			len=msReparseInfo->MountPointReparseBuffer.PrintNameLength;//~v6k4I~
            if (len!=0)	//win32 format filename                    //~v6k4I~
            {                                                      //~v6k4I~
	            memcpy(name1,(reparseData + msReparseInfo->MountPointReparseBuffer.PrintNameOffset),len);//~v6k4I~
            	UTRACED("MOUNTPOINT printname",name1,len);         //~v6k4I~
            }                                                      //~v6k4I~
            else                                                   //~v6k4I~
            {                                                      //~v6k4I~
                len=msReparseInfo->MountPointReparseBuffer.SubstituteNameLength;//~v6k4R~
                memcpy(name1,(reparseData + msReparseInfo->MountPointReparseBuffer.SubstituteNameOffset),len);//~v6k4R~
            	UTRACED("MOUNTPOINT substitutename",name1,len);    //~v6k4I~
            }                                                      //~v6k4I~
            if (!memcmp(name1,prefix,PREFIXCTR*sizeof(UWCHART))) //"\??\"//~v6k4I~
            {                                                      //~v6k4I~
                len-=PREFIXCTR*sizeof(UWCHART);                    //~v6k4I~
                offs=PREFIXCTR;                                    //~v6k4I~
            }                                                      //~v6k4I~
//          rc=outmbs(name1+offs,len,Ptarget,Poutbuffsz,Ppoutlen); //~v6k4I~//~v6u9R~
            rc=outmbs(0,name1+offs,len,Ptarget,Poutbuffsz,Ppoutlen);//~v6u9I~
            //                                                     //~v6k4I~
            // I use a simple heuristic to differentiate mount points and junctions: a junction//~v6k4I~
            // specifies a drive-letter based target, so I look for the drive letter colon//~v6k4I~
            // in the target, which should be in the form \??\D:\target//~v6k4I~
            //                                                     //~v6k4I~
//          if(!_tcsstr( name1, _T(":") ))                         //~v6k4R~
            break;                                                 //~v6k4I~
		case IO_REPARSE_TAG_HSM:                                   //~v6k4I~
    	    rc=UWINLNKERR_OTHER;                                   //~v6k4I~
            break;                                                 //~v6k4I~
        case IO_REPARSE_TAG_SIS:                                   //~v6k4I~
                    // Sinlge Instance Store installs and executes as part//~v6k4I~
                    // of the Remote Installation Service (RIS)    //~v6k4I~
    	    rc=UWINLNKERR_OTHER;                                   //~v6k4I~
            break;                                                 //~v6k4I~
        case IO_REPARSE_TAG_DFS:                                   //~v6k4I~
    	    rc=UWINLNKERR_OTHER;                                   //~v6k4I~
            break;                                                 //~v6k4I~
        default:                                                   //~v6k4I~
    	    rc=UWINLNKERR_OTHERUNKNOWN;                            //~v6k4I~
                    break;                                         //~v6k4I~
        }                                                          //~v6k4I~
        break;//for(;;)                                            //~v6k4R~
    }                                                              //~v6k4I~
    if (fileHandle)                                                //~v6k4I~
	    CloseHandle( fileHandle );                                 //~v6k4I~
    if (Pprepasebuff)                                              //~v6k4I~
    	*Pprepasebuff=reparseBuffer;                               //~v6k4I~
    else                                                           //~v6k4I~
    	ufree(reparseBuffer);                                      //~v6k4I~
	UTRACEP("uwinlnk_gettarget rc=%d target=%s\n",rc,Ptarget);     //~v6k4R~
    return rc;                                                     //~v6k4I~
}//uwinlnk_gettarget                                               //~v6k4I~
#ifdef W32UNICODE                                                  //~v6u9I~
//*******************************************************          //~v6uaI~//~v6u9M~
//*get UWCH slink target with UDL string parrm                     //~v6uaI~//~v6u9M~
//*rc:UCVEXT_SUBCHRC                                               //~v6u9I~
//*******************************************************          //~v6uaI~//~v6u9M~
int uwinlnk_gettargetW(int Popt,ULONG Pattr,char *Pfnm,char *Ptarget,int Poutbuffsz,//~v6uaR~//~v6u9I~
			int *Ppoutlen,ULONG *Ppattr,int *Pptag,PBYTE *Preparsebuff,//~v6uaI~//~v6u9M~
			UWCH *PtargetW,int PtargetWsz,int *PptargetWctr,int *Pprcud)       //~v6uaR~//~v6u9R~
{                                                                  //~v6uaI~//~v6u9M~
	int opt,rc,ucsctr,targetlen,targetWsz,rcud=0;                       //~v6uaR~//~v6u9R~
    UWCH wkfnmw[_MAX_PATHWC];                                      //~v6uaR~//~v6u9M~
    UWCH wktargetw[_MAX_PATHWC];                                   //~v6unI~
//*****************************                                    //~v6uaI~//~v6u9M~
    UTRACED("inp",Pfnm,strlen(Pfnm));                              //~v6uaI~//~v6u9M~
    if (PtargetW)                                                  //~v6uaI~//~v6u9M~
        *PtargetW=0;                                               //~v6uaI~//~v6u9M~
    else                                                           //~v6unI~
        PtargetW=wktargetw,*PtargetW=0,PtargetWsz=sizeof(wktargetw);//~v6unI~
    if (PptargetWctr)                                              //~v6uaI~//~v6u9M~
        *PptargetWctr=0;                                           //~v6uaI~//~v6u9M~
	if (!IS_UDMODE())                                              //~v6uaI~//~v6u9M~
    {                                                              //~v6uaI~//~v6u9M~
    	return uwinlnk_gettarget(Popt,Pattr,Pfnm,Ptarget,Poutbuffsz,Ppoutlen,Ppattr,Pptag,Preparsebuff);//~v6uaR~//~v6u9M~
    }                                                              //~v6uaI~//~v6u9M~
    for (;;)                                                       //~v6uaI~//~v6u9M~
    {                                                              //~v6uaI~//~v6u9M~
    	opt=0;	//drop UD                                          //~v6u9I~
		rc=ufilecvUD2WC(opt,Pfnm,wkfnmw,sizeof(wkfnmw),&ucsctr,NULL/*wkpathtbl*/,0/*sizeof(wkpathtbl)*/,NULL/*&pathctr*/);   //~v6uaI~//~v6u9R~
    	if (rc>=UDRC_ERR)                                                    //~v6uaI~//~v6u9R~
    	{                                                          //~v6uaI~//~v6u9M~
    		errno=EINVAL;                                          //~v6uaI~//~v6u9M~
    		break;                                                 //~v6uaI~//~v6u9M~
    	}                                                          //~v6uaI~//~v6u9M~
        UTRACED("fnmW",wkfnmw,ucsctr);                             //~v6uaI~//~v6u9M~
    	rc=uwinlnk_gettargetWW(Popt,Pattr,wkfnmw,PtargetW,PtargetWsz,&targetWsz,Ppattr,Pptag,Preparsebuff);//~v6uaR~//~v6u9M~
        if (PptargetWctr)                                          //~v6uaI~//~v6u9M~
        	*PptargetWctr=sz2ctrW(targetWsz);                      //~v6uaR~//~v6u9M~
    	if (rc)                                                    //~v6uaI~//~v6u9M~
    		break;                                                 //~v6uaI~//~v6u9M~
		if (Popt & UWINGTO_NOOUTUD)  //targetA by UDfmt            //~v6u9R~
        {                                                          //~v6u9I~
	    	opt=UFCVO_SETSUBCHRC|UFCVO_STRZ;                       //~v6u9I~
			rc=ufilecvucs2cpW(opt,PtargetW,sz2ctrW(targetWsz),Ptarget,Poutbuffsz,&targetlen);//~v6u9R~
	    	if (rc==UCVEXTRC_SUBCH)                                //~v6u9I~
            {                                                      //~v6u9I~
			    rcud=UCVEXTRC_SUBCH;                               //~v6u9R~
                rc=0;                                              //~v6u9I~
            }                                                      //~v6u9I~
        }                                                          //~v6u9I~
        else                                                       //~v6u9I~
        {                                                          //~v6u9I~
        	opt=UFCVO_NEW;	//do subchar chk                       //~v6u9I~
			rc=ufilecvWC2UD(opt,PtargetW,Ptarget,Poutbuffsz,&targetlen,NULL/*pathtbl*/,0);//~v6uaR~//~v6u9R~
            if (rc==1)                                             //~v6u9I~
            {                                                      //~v6u9I~
			    rcud=UCVEXTRC_SUBCH;                               //~v6u9R~
                rc=0;                                              //~v6u9I~
            }                                                      //~v6u9I~
        }                                                          //~v6u9I~
        if (Ppoutlen)                                              //~v6uaI~//~v6u9R~
        	*Ppoutlen=targetlen;                                   //~v6uaI~//~v6u9R~
	    if (rc)                                                    //~v6u9R~
    		break;                                                 //~v6uaI~//~v6u9R~
        UTRACED("out target",Ptarget,targetlen);                   //~v6uaI~//~v6u9M~
        UTRACED("out targetW",PtargetW,targetWsz);                 //~v6uaR~//~v6u9M~
        break;                                                     //~v6uaI~//~v6u9M~
	}                                                              //~v6uaI~//~v6u9M~
    if (Pprcud)                                                    //~v6u9R~
    	*Pprcud=rcud;                                              //~v6u9R~
	UTRACEP("%s:rc=%p\n",UTT,rc);                                  //~v6uaI~//~v6u9M~
    return rc;                                                     //~v6uaR~//~v6u9M~
}//uwinlnk_gettargetW                                              //~v6u9I~
//**************************************************************   //~v6k4I~
//*rc:0 or GetLastError                                            //~v6k4I~
//**************************************************************   //~v6k4I~
//int uwinlnk_gettarget(int Popt,ULONG Pattr,char *Pfnm,char *Ptarget,int Poutbuffsz,//~v6k4R~//~v6uaR~//~v6u9R~
int uwinlnk_gettargetWW(int Popt,ULONG Pattr,UWCH *Pfnm,UWCH *Ptarget,int Poutbuffsz,//~v6uaI~//~v6u9R~
					int *Ppoutlen,ULONG *Ppattr,int *Pptag,PBYTE *Pprepasebuff)//~v6k4R~
{                                                                  //~v6k4I~
    HANDLE   fileHandle=NULL;                                      //~v6k4R~
    BYTE     *reparseBuffer;                                       //~v6k4R~
    PBYTE    reparseData;                                          //~v6k4I~
    PREPARSE_GUID_DATA_BUFFER reparseInfo;                         //~v6k4R~
    PREPARSE_DATA_BUFFER msReparseInfo;                            //~v6k4R~
    DWORD   returnedLength;                                        //~v6k4I~
    UWCHART  name1[MAX_NAME_LENGTH];                               //~v6k4R~
    ULONG attr;                                                    //~v6k4I~
    int rc=0;                                                      //~v6k4I~
//  LPCSTR pfnm;                                                   //~v6k4I~//~v6uaR~//~v6u9R~
    UWCH  *pfnm;                                                   //~v6uaI~//~v6u9R~
    int len,offs=0,flag,swfilejunction=0,swreparse=0;              //~v6k4R~
    UWCHART prefix[PREFIXCTR]={'\\','?','?','\\'};                 //~v6k4R~
//****************************                                     //~v6k4I~
	UTRACEP("uwinlnk_gettarget attr=%x,fnm=%s\n",Pattr,Pfnm);      //~v6k4R~
    reparseBuffer=umalloc(MAX_REPARSE_SIZE);                       //~v6k4R~
    if (!reparseBuffer)                                            //~v6k4R~
    	return UWINLNKERR_MALLOCERR;                               //~v6k4I~
    reparseInfo=(PREPARSE_GUID_DATA_BUFFER)reparseBuffer;          //~v6k4I~
    msReparseInfo=(PREPARSE_DATA_BUFFER)reparseBuffer;             //~v6k4I~
    *Ptarget=0;                                                    //~v6k4I~
    *Ppoutlen=0;                                                   //~v6k4I~
    pfnm=Pfnm;                                                     //~v6k4R~
	if (Pattr==-1)                                                 //~v6k4I~
    {                                                              //~v6k4I~
//  	attr=GetFileAttributes(pfnm);	//dir bit on also for junction to file//~v6k4R~//~v6uaR~//~v6u9R~
    	attr=GetFileAttributesW(pfnm);	//dir bit on also for junction to file//~v6uaI~//~v6u9R~
	 	swreparse=(attr & FILE_ATTRIBUTE_REPARSE_POINT);           //~v6k4I~
	}                                                              //~v6k4I~
    else                                                           //~v6k4I~
    {                                                              //~v6k4I~
    	attr=Pattr;                                                //~v6k4I~
        if (Popt & UWINGTO_W32ATTR)	//from ufilew32getslink,attr is value of FindFirstFile//~v6k4I~
		 	swreparse=(attr & FILE_ATTRIBUTE_REPARSE_POINT);       //~v6k4I~
        else                                                       //~v6k4I~
        {                                                          //~v6k4I~
        	swreparse=(Pattr & FILE_SLINK);                        //~v6k4I~
        	swfilejunction=FILE_MODEISNTFS_JUNCTION2FILE(Pattr);   //~v6k4I~
        }                                                          //~v6k4I~
    }                                                              //~v6k4I~
    if (Ppattr)                                                    //~v6k4I~
    	*Ppattr=attr;                                              //~v6k4I~
    for (;;)                                                       //~v6k4I~
    {                                                              //~v6k4I~
	 	if (!swreparse)                                            //~v6k4R~
        {                                                          //~v6k4I~
    	    rc=UWINLNKERR_NOTREPARSE;                              //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
        flag=FILE_FLAG_OPEN_REPARSE_POINT;                         //~v6k4I~
        if(attr & FILE_ATTRIBUTE_DIRECTORY )                       //~v6k4I~
        	flag|=FILE_FLAG_BACKUP_SEMANTICS;                      //~v6k4I~
        else                                                       //~v6k4I~
        	if (swfilejunction)                                    //~v6k4I~
	        	flag|=FILE_FLAG_BACKUP_SEMANTICS;                  //~v6k4I~
//      fileHandle=CreateFile(pfnm, 0,                             //~v6k4I~//~v6uaR~//~v6u9R~
        fileHandle=CreateFileW(pfnm, 0,                            //~v6uaI~//~v6u9R~
                        FILE_SHARE_READ|FILE_SHARE_WRITE, NULL,    //~v6k4I~
                        OPEN_EXISTING,                             //~v6k4I~
                        flag,0);                                   //~v6k4I~
	 	if (fileHandle==INVALID_HANDLE_VALUE)                      //~v6k4R~
        {                                                          //~v6k4I~
    	    rc=GetLastError();                                     //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
        if(!DeviceIoControl(fileHandle,FSCTL_GET_REPARSE_POINT,    //~v6k4I~
                        NULL, 0, reparseInfo,MAX_REPARSE_SIZE,     //~v6k4R~
                        &returnedLength,NULL))                     //~v6k4I~
        {                                                          //~v6k4I~
            rc=GetLastError();                                     //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
        UTRACED("uwinsub DeviceIoControl out",reparseInfo,returnedLength);//~v6k4I~
    	if(!IsReparseTagMicrosoft(reparseInfo->ReparseTag))        //~v6k4I~
		{                                                          //~v6k4I~
    	    rc=UWINLNKERR_NOTMF;                                   //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
        if (Pptag)                                                 //~v6k4I~
        	*Pptag=reparseInfo->ReparseTag;                        //~v6k4I~
        switch( reparseInfo->ReparseTag )                          //~v6k4I~
        {                                                          //~v6k4I~
        case TAG_SYMLINK:      //0xa000000c                        //~v6k4I~
                    //                                             //~v6k4I~
                    // I don't know if this is a valid reparse point//~v6k4I~
                    //                                             //~v6k4I~
        	reparseData = (PBYTE) &msReparseInfo->SymbolicLinkReparseBuffer.PathBuffer;//~v6k4I~
			len=msReparseInfo->MountPointReparseBuffer.PrintNameLength;//~v6k4I~
            if (len!=0)	//print name                               //~v6k4I~
            {                                                      //~v6k4I~
                memcpy(name1,(reparseData + msReparseInfo->MountPointReparseBuffer.PrintNameOffset),len);//~v6uaR~//~v6u9R~
            	UTRACED("MOUNTPOINT printname",name1,len);         //~v6k4I~
            }                                                      //~v6k4I~
            else                                                   //~v6k4I~
            {                                                      //~v6k4I~
            	len=msReparseInfo->SymbolicLinkReparseBuffer.SubstituteNameLength;//~v6k4R~
            	memcpy(name1,(reparseData + msReparseInfo->SymbolicLinkReparseBuffer.SubstituteNameOffset),len);//~v6uaR~//~v6u9R~
            }                                                      //~v6k4I~
//          name1[len] = 0;                                        //~v6uaR~//~v6u9R~
            name1[sz2ctrW(len)] = 0;                               //~v6uaI~//~v6u9R~
            UTRACED("SYMLINK",name1,len);                          //~v6k4I~
            offs=0;                                                //~v6k4I~
            if (!memcmp(name1,prefix,PREFIXCTR*sizeof(UWCHART))) //"\??\"//~v6k4I~
            {                                                      //~v6k4I~
//              len-=PREFIXCTR*sizeof(UWCHART);                    //~v6uaR~//~v6u9R~
                offs=PREFIXCTR;                                    //~v6k4I~
            }                                                      //~v6k4I~
//          rc=outmbs(name1+offs,len,Ptarget,Poutbuffsz,Ppoutlen); //~v6k4R~//~v6uaR~//~v6u9R~
            UstrncpyZW(Ptarget,name1+offs,Poutbuffsz);             //~v6uaI~//~v6u9R~
            *Ppoutlen=strszW(Ptarget);                             //~v6uaR~//~v6u9R~
            break;                                                 //~v6k4I~
        case IO_REPARSE_TAG_MOUNT_POINT:                           //~v6k4I~
                    //                                             //~v6k4I~
                    // Mount points and junctions                  //~v6k4I~
                    //                                             //~v6k4I~
            offs=0;                                                //~v6k4I~
        	reparseData = (PBYTE) &msReparseInfo->MountPointReparseBuffer.PathBuffer;//~v6k4I~
			len=msReparseInfo->MountPointReparseBuffer.PrintNameLength;//~v6k4I~
            if (len!=0)	//win32 format filename                    //~v6k4I~
            {                                                      //~v6k4I~
                memcpy(name1,(reparseData + msReparseInfo->MountPointReparseBuffer.PrintNameOffset),len);//~v6uaR~//~v6u9R~
            	UTRACED("MOUNTPOINT printname",name1,ctr2szW(len));//~v6uaR~//~v6u9R~
            }                                                      //~v6k4I~
            else                                                   //~v6k4I~
            {                                                      //~v6k4I~
                len=msReparseInfo->MountPointReparseBuffer.SubstituteNameLength;//~v6k4R~
                memcpy(name1,(reparseData + msReparseInfo->MountPointReparseBuffer.SubstituteNameOffset),len);//~v6uaR~//~v6u9R~
            	UTRACED("MOUNTPOINT substitutename",name1,ctr2szW(len));//~v6uaR~//~v6u9R~
            }                                                      //~v6k4I~
            if (!memcmp(name1,prefix,PREFIXCTR*sizeof(UWCHART))) //"\??\"//~v6k4I~
            {                                                      //~v6k4I~
//              len-=PREFIXCTR*sizeof(UWCHART);                    //~v6uaR~//~v6u9R~
                offs=PREFIXCTR;                                    //~v6k4I~
            }                                                      //~v6k4I~
//          rc=outmbs(name1+offs,len,Ptarget,Poutbuffsz,Ppoutlen); //~v6k4I~//~v6uaR~//~v6u9R~
            name1[sz2ctrW(len)]=0;//outmbs set strz but            //~v6uaI~//~v6u9R~
            UstrncpyZW(Ptarget,name1+offs,Poutbuffsz);             //~v6uaI~//~v6u9R~
            *Ppoutlen=strszW(Ptarget);                             //~v6uaR~//~v6u9R~
            //                                                     //~v6k4I~
            // I use a simple heuristic to differentiate mount points and junctions: a junction//~v6k4I~
            // specifies a drive-letter based target, so I look for the drive letter colon//~v6k4I~
            // in the target, which should be in the form \??\D:\target//~v6k4I~
            //                                                     //~v6k4I~
            break;                                                 //~v6k4I~
		case IO_REPARSE_TAG_HSM:                                   //~v6k4I~
    	    rc=UWINLNKERR_OTHER;                                   //~v6k4I~
            break;                                                 //~v6k4I~
        case IO_REPARSE_TAG_SIS:                                   //~v6k4I~
                    // Sinlge Instance Store installs and executes as part//~v6k4I~
                    // of the Remote Installation Service (RIS)    //~v6k4I~
    	    rc=UWINLNKERR_OTHER;                                   //~v6k4I~
            break;                                                 //~v6k4I~
        case IO_REPARSE_TAG_DFS:                                   //~v6k4I~
    	    rc=UWINLNKERR_OTHER;                                   //~v6k4I~
            break;                                                 //~v6k4I~
        default:                                                   //~v6k4I~
    	    rc=UWINLNKERR_OTHERUNKNOWN;                            //~v6k4I~
                    break;                                         //~v6k4I~
        }                                                          //~v6k4I~
        break;//for(;;)                                            //~v6k4R~
    }                                                              //~v6k4I~
    if (fileHandle)                                                //~v6k4I~
	    CloseHandle( fileHandle );                                 //~v6k4I~
    if (Pprepasebuff)                                              //~v6k4I~
    	*Pprepasebuff=reparseBuffer;                               //~v6k4I~
    else                                                           //~v6k4I~
    	ufree(reparseBuffer);                                      //~v6k4I~
	UTRACEP("uwinlnk_gettarget rc=%d target=%s\n",rc,Ptarget);     //~v6k4R~//~v6uaR~//~v6u9R~
    return rc;                                                     //~v6k4I~
}//uwinlnk_gettargetWW                                             //~v6k4I~//~v6uaR~//~v6u9R~
#endif	//W32UNICODE                                               //~v6u9I~
//**************************************************************   //~v6k4I~
//*if BESTFIT, retry when SUBCH was set                            //~v6u9I~
// rc:UCVEXTRC_SUBCH,WideToMultiByte-GetLastError()                //~v6unI~//~v6u9R~
//**************************************************************   //~v6u9I~
//int outmbs(UWCHART *Ptch,int Plen,char *Pch,int Pbuffsz,int *Ppoutlen)//~v6k4R~//~v6u9R~
int outmbs(int Popt,UWCHART *Ptch,int Plen,char *Pch,int Pbuffsz,int *Ppoutlen)//~v6u0I~//~v6u9I~
{                                                                  //~v6k4I~
	int rc=0,rc2,opt=0;                                            //~v6k4R~
    ULONG converter;                                               //~v6k4I~
//**************                                                   //~v6k4I~
    converter=ugetcp();                                            //~v6k4I~
    if (Popt & UWSOMO_SETSUBCHRC)       //return err if subchar was set//~v6u0I~//~v6u9I~
    	opt|=UCVUCS_SETSUBCHRC;                                    //~v6u0I~//~v6u9I~
	rc2=ucvext_winucs2cp(opt,converter,Ptch,Plen/2,Pch,Pbuffsz,Ppoutlen);//~v6k4R~
    if (rc2==ERROR_INSUFFICIENT_BUFFER)                            //~v6k4I~
    	rc=UWINLNKERR_BUFFOVF;                                     //~v6k4I~
    else                                                           //~v6k4I~
    	rc=rc2;                                                    //~v6k4I~
    if (rc2==UCVEXTRC_SUBCH)                                       //~v6u0I~//~v6u9I~
    	if (Popt & UWSOMO_BESTFIT)       //return err if subchar was set//~v6u0I~//~v6u9I~
        {                                                          //~v6u0I~//~v6u9I~
			ucvext_winucs2cp(opt|UCVUCS_BESTFIT,converter,Ptch,Plen/2,Pch,Pbuffsz,Ppoutlen);//~v6u0R~//~v6u9I~
            UTRACED("bestfit",Pch,*Ppoutlen);                      //~v6u0I~//~v6u9I~
        }                                                          //~v6u0I~//~v6u9I~
//  if (!rc)                                                       //~v6k4I~//~v6u9R~
    if (!rc || rc==UCVEXTRC_SUBCH)                                                       //~v6k4I~//~v6u0R~//~v6u9I~
      if (*Ppoutlen<Pbuffsz)                                       //~v6u9I~
		*(Pch+*Ppoutlen)=0;                                        //~v6k4R~
    UTRACED("outmbs",Pch,*Ppoutlen);                               //~v6k4I~
    return rc;                                                     //~v6k4R~
}                                                                  //~v6k4I~
//**************************************************************   //~v6k4I~
//int mbs2wc(char *Ppmbs,int Plen,UWCHART *Pwch,int Pbuffsz,int *Ppoutlen)//~v6k4R~//~v6unR~
int mbs2wc(char *Ppmbs,int Plen,UWCHART *Pwch,int Pbuffsz,int *Ppoutlen,int Popt)//~v6unI~
{                                                                  //~v6k4I~
	int rc,opt,outctr=0;                                           //~v6k4R~
    ULONG converter;                                               //~v6k4I~
    char *pdbcs=0;                                                 //~v6k4I~
//**************                                                   //~v6k4I~
    *Ppoutlen=0;    //set for errcase                              //~v6u9I~
    converter=ugetcp();                                            //~v6k4I~
    opt=0;                                                         //~v6unI~
  if (!(Popt & UWSMWO_ALLOWCP2UERR))   //ignore MultibyteToWideChar err//~v6unI~
    opt=UCVUCS_ERRSTOP;                                            //~v6k4I~
    *Pwch=0;                                                               //~v6unI~//~v6BRR~
	rc=ucvext_wincp2ucss(opt,converter,Ppmbs,pdbcs,Plen,Pwch,Pbuffsz,&outctr);//~v6k4R~
    if (!rc)                                                       //~v6k4I~
    {                                                              //~v6k4I~
    	*Ppoutlen=outctr*sizeof(UWCHART);                          //~v6k4I~
//    if (outctr<sz2ctrW(Pbuffsz))                                 //~v6u0I~//~v6u9I~//~v6BRR~
//  	*(Pwch+outctr)=0;                                          //~v6k4R~//~v6BRR~
    }                                                              //~v6k4I~
    if (outctr>=0 && outctr<sz2ctrW(Pbuffsz))                      //~v6BRI~
	  	*(Pwch+outctr)=0;                                          //~v6BRI~
    UTRACED("mbs2wc",Pwch,*Ppoutlen);                              //~v6k4R~
    UTRACEP("mbs2wc rc=%d,len=%d\n",rc,outctr*2);                     //~v6k4I~//~v6u9R~
    return rc;                                                     //~v6k4I~
}                                                                  //~v6k4I~
//**************************************************************   //~v6knI~
//**************************************************************   //~v6knI~
int uwinlnk_copyfiletime(int Popt,HANDLE Pfhsrc,HANDLE Pfhdest,char *Psrc,char *Pdest)//~v6knI~
{                                                                  //~v6knI~
	WIN32_FIND_DATA w32fd;                                         //~v6knI~
    HANDLE   fhd=INVALID_HANDLE_VALUE,fhs=INVALID_HANDLE_VALUE;    //~v6ktR~
    int rc=0;                                                      //~v6knI~
//****************************************                         //~v6knI~
	UTRACEP("uwinlnk_copyfiletime src=%s,dest=%s,handle=%x\n",Psrc,Pdest,Pfhdest);//~v6knI~
    for (;;)                                                       //~v6knI~
    {                                                              //~v6knI~
    	if (Pfhdest)                                               //~v6knI~
        	fhd=Pfhdest;                                           //~v6knI~
        else                                                       //~v6knI~
        	fhd=CreateFile(Pdest,GENERIC_READ|GENERIC_WRITE,       //~v6knI~
                            0,NULL,                                //~v6knI~
                            OPEN_EXISTING,                         //~v6knI~
                            FILE_FLAG_BACKUP_SEMANTICS|FILE_FLAG_OPEN_REPARSE_POINT ,NULL);//~v6knI~
		UTRACEP("uwinlnk_copyfiletime CreateFile handle=%x\n",fhd);//~v6knI~
	 	if (fhd==INVALID_HANDLE_VALUE)                             //~v6knI~
        {                                                          //~v6knI~
    	    rc=GetLastError();                                     //~v6knI~
            break;                                                 //~v6knI~
        }                                                          //~v6knI~
    	fhs=FindFirstFile(Psrc,&w32fd);                            //~v6knI~
	 	if (fhs==INVALID_HANDLE_VALUE)                             //~v6knI~
        {                                                          //~v6knI~
    	    rc=GetLastError();                                     //~v6knI~
            break;                                                 //~v6knI~
        }                                                          //~v6knI~
        if (!SetFileTime(fhd,NULL/*creationtime*/,&w32fd.ftLastAccessTime,&w32fd.ftLastWriteTime))//~v6knI~
        {                                                          //~v6knI~
            rc=GetLastError();                                     //~v6knI~
            break;                                                 //~v6knI~
        }                                                          //~v6knI~
		UTRACEP("uwinlnk_copyfiletime setfiletime\n");             //~v6knI~
        break;                                                     //~v6knI~
    }                                                              //~v6knI~
    if (fhs!=INVALID_HANDLE_VALUE)                                 //~v6ktR~
    {                                                              //~v6knI~
//      CloseHandle(fhs);                                          //~v6ktR~
        FindClose(fhs);                                            //~v6ktR~
    }                                                              //~v6knI~
    if (fhd!=INVALID_HANDLE_VALUE && fhd!=Pfhdest)                 //~v6ktR~
    {                                                              //~v6knI~
	    CloseHandle(fhd);                                          //~v6knI~
    }                                                              //~v6knI~
    UTRACEP("uwinsub copyfiletime rc=%d\n",rc);                    //~v6knI~
    return rc;                                                     //~v6knI~
}//uwinlnk_copyfiletime                                            //~v6knI~
//**************************************************************   //~v6k4I~
//*copy Junction                                                   //~v6k4R~
//*rc:0 or GetLastError                                            //~v6k4I~
//**************************************************************   //~v6k4I~
int uwinlnk_copyjunction(int Popt,ULONG Pattr,char *Psrc,char *Pdest,char *Ptarget,int Plen)//~v6k4R~
{                                                                  //~v6k4I~
    int rc=0,buffsz,len,swtargeterr=0;                             //~v6k4R~
    HANDLE   fileHandle=NULL;                                      //~v6k4R~
    DWORD   returnedLength;                                        //~v6k4I~
    PREPARSE_MOUNTPOINT_DATA_BUFFER reparseInfo;                   //~v6k4R~
    UWCHART wctarget[_MAX_PATH];                                   //~v6k4I~
    UWCHART prefix[PREFIXCTR]={'\\','?','?','\\'};                 //~v6k4I~
    FILEFINDBUF3 ffb3;                                             //~v6k4I~
    int rc2,opt2,ucsctr;                                           //~v6u9R~
//****************************************                         //~v6k4I~
	UTRACEP("uwinlnk_copyjunction attr=%x,src=%s,dest=%s,tgt=%s\n",Pattr,Psrc,Pdest,Ptarget);//~v6k4R~
    for (;;)                                                       //~v6k4I~
    {                                                              //~v6k4I~
        if (!(Popt & UWINGTO_COPYOVERRIDE))	//not exist            //~v6k4I~
        {                                                          //~v6k4I~
    		rc=umkdir(Pdest);                                      //~v6k4R~
			UTRACEP("uwinlnk_copyjunction umkdir rc=%d\n",rc);     //~v6k4R~
    		if (rc)                                                //~v6k4R~
        		break;                                             //~v6k4R~
        }                                                          //~v6k4I~
        fileHandle=CreateFile(Pdest,GENERIC_READ|GENERIC_WRITE,    //~v6k4R~
                            0,NULL,                                //~v6k4I~
                            OPEN_EXISTING,                         //~v6k4I~
                            FILE_FLAG_BACKUP_SEMANTICS|FILE_FLAG_OPEN_REPARSE_POINT ,NULL);//~v6k4I~
		UTRACEP("uwinlnk_copyjunction CreateFile handle=%x\n",fileHandle);//~v6k4I~
	 	if (fileHandle==INVALID_HANDLE_VALUE)                      //~v6k4I~
        {                                                          //~v6k4I~
    	    rc=GetLastError();                                     //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
//      mbs2wc(Ptarget,Plen,wctarget,sizeof(wctarget),&len);       //~v6k4I~//~v6unR~
//    rc2=                                                         //~v6u9R~
//      mbs2wc(Ptarget,Plen,wctarget,sizeof(wctarget),&len,0);     //~v6u9R~
//    if (rc2)                                                     //~v6u9R~
		opt2=0;                                                    //~v6u9I~
      rc2=ufilecvUD2WCnopath(opt2,Ptarget,wctarget,sizeof(wctarget),&ucsctr);//~v6u9I~
      len=ctr2szW(ucsctr);                                         //~v6u9I~
	  if (rc2>=UDRC_FMTERR)                                        //~v6u9I~
      {                                                            //~v6u9I~
//      rc=UWINLNKERR_NOTARGET;//  -9     //targetfile not found   //~v6u9R~
        rc=GetLastError();//ERROR_INVALID_NAME                     //~v6u9I~
        swtargeterr=1;                                             //~v6u9I~
        break;                                                     //~v6u9I~
      }                                                            //~v6u9I~
        buffsz=len+sizeof(REPARSE_MOUNTPOINT_DATA_BUFFER)+16;      //~v6k4R~
	    reparseInfo=(PREPARSE_MOUNTPOINT_DATA_BUFFER)umalloc(buffsz);//~v6k4R~
        if (reparseInfo==NULL)                                     //~v6k4I~
        {                                                          //~v6k4I~
    		rc=UWINLNKERR_MALLOCERR;                               //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
        memset(reparseInfo,0,buffsz);                              //~v6k4R~
        reparseInfo->ReparseTag=IO_REPARSE_TAG_MOUNT_POINT;        //~v6k4I~
//      reparseInfo->ReparseTargetLength=len+sizeof(prefix);       //~v6k4I~//~v6BjR~
        reparseInfo->ReparseTargetLength=(WORD)(len+(int)sizeof(prefix));//~v6BjI~
        reparseInfo->ReparseTargetMaximumLength=reparseInfo->ReparseTargetLength+sizeof(UWCHART);//~v6k4I~
        reparseInfo->ReparseDataLength=reparseInfo->ReparseTargetLength+12;//~v6k4I~
        memcpy(reparseInfo->ReparseTarget,prefix,sizeof(prefix));  //~v6k4I~
        memcpy(reparseInfo->ReparseTarget+PREFIXCTR,wctarget,len+sizeof(UWCHART));//append last 0//~v6k4R~
                                                                   //~v6k4I~
		UTRACED("uwinlnk_copyjunction setrepase data",reparseInfo,buffsz);//~v6k4R~
        if(!DeviceIoControl(fileHandle,FSCTL_SET_REPARSE_POINT,    //~v6k4I~
                        reparseInfo,                               //~v6k4I~
                        reparseInfo->ReparseDataLength+REPARSE_MOUNTPOINT_HEADER_SIZE,//~v6k4R~
						NULL,0,                                    //~v6k4I~
                        &returnedLength,NULL))                     //~v6k4I~
        {                                                          //~v6k4I~
            rc=GetLastError();                                     //~v6k4I~
			UTRACEP("uwinlnk_copyjunction SET_REPASE lasterr=%d\n",rc);//~v6k4I~
	    	CloseHandle(fileHandle);                               //~v6k4I~
            fileHandle=NULL;                                       //~v6k4I~
            urmdir(Pdest);                                         //~v6k4I~
          if (isNtfs(rc,Pdest))                                    //~v6k9I~
          {                                                        //~v6k9I~
          	rc=UWINLNKERR_NOTNTFS;  //      -11    //junction to file//~v6k9I~
            swtargeterr=2;                                         //~v6k9I~
          }                                                        //~v6k9I~
          else                                                     //~v6k9I~
            if (ufstat(Ptarget,&ffb3))                             //~v6k4R~
                swtargeterr=1;                                     //~v6k4I~
        }                                                          //~v6k4I~
        ufree(reparseInfo);                                        //~v6k4I~
        uwinlnk_copyfiletime(0,NULL/*srcfile handle*/,fileHandle,Psrc,Pdest);//~v6knI~
        break;                                                     //~v6k4I~
    }                                                              //~v6k4I~
    if (fileHandle)                                                //~v6k4I~
	    CloseHandle( fileHandle );                                 //~v6k4I~
    if (rc)                                                        //~v6k4I~
    	if (swtargeterr)//  -9     //targetfile not found          //~v6k4I~
        {                                                          //~v6k4I~
          if (swtargeterr!=2)   //not ntfs errmsg issued           //~v6k9I~
          {                                                        //~v6k9I~
			uwincopyerrnotarget(rc,Psrc,Ptarget);                  //~v6k4I~
            rc=UWINLNKERR_NOTARGET;//  -9     //targetfile not found//~v6k4I~
          }                                                        //~v6k9I~
        }                                                          //~v6k4I~
        else                                                       //~v6k4I~
    		uwincopyerr(rc,Psrc,Pdest);                            //~v6k4R~
    UTRACEP("uwinsub copyjunction rc=%d\n",rc);                    //~v6k4I~
    return rc;                                                     //~v6k4I~
}//uwinlnk_copyjunction                                            //~v6k4I~
//**************************************************************   //~v6k4I~
//*chk volume is mounted                                           //~v6k4I~
//**************************************************************   //~v6k4I~
int uwinlnk_isMounted(int Popt,char *Psrc,char *Ptarget,int Plen)  //~v6k4I~
{                                                                  //~v6k4I~
#ifndef VC10EXP                                                    //~v6kiI~
    return 0;   //assume mounted                                   //~v6kiI~
#else                                                              //~v6kiI~
	int rc=0;                                                      //~v6k4I~
    DWORD   returnedLength=0;                                      //~v6k4R~
    char *pfnm;                                                    //~v6k4I~
    BOOL rcb;                                                      //~v6k4I~
    char volname[_MAX_PATH];                                       //~v6k4I~
    char buff[1024];                                               //~v6k4I~
//**********************                                           //~v6k4I~
    strcpy(volname,VOL_PREFIX);                                    //~v6k4I~
    strcpy(volname+sizeof(VOL_PREFIX)-1,Ptarget);                  //~v6k4R~
	pfnm=volname;                                                  //~v6k4I~
    rcb=GetVolumePathNamesForVolumeName(                           //~v6k4R~
        pfnm,                                                      //~v6k4I~
        buff,sizeof(buff),&returnedLength                          //~v6k4I~
        );                                                         //~v6k4I~
    if (!rcb)                                                      //~v6k4I~
        rc=GetLastError();  //2 if not mounted                     //~v6k4R~
    UTRACEP("uwinlnk_isMounted getvolpathname rcb=%d,lasterr=%d,volname=%s\n",rcb,rc,volname);//~v6k4R~
    UTRACED("uwinlnk_isMounted getvolpathname out",buff,returnedLength);//~v6k4I~
    UTRACEP("uwinlnk_isMounted rc=%d,src=%s,target=%s\n",rc,Psrc,Ptarget);//~v6k4I~
    return rc;                                                     //~v6k4I~
#endif                                                             //~v6kiI~
}//uwinlnk_isMounted                                               //~v6k4I~
//**************************************************************   //~v6k4I~
//*copy mountpoint                                                 //~v6k4I~
//*rc:0 or GetLastError                                            //~v6k4I~
//**************************************************************   //~v6k4I~
int uwinlnk_copymountpoint(int Popt,ULONG Pattr,char *Psrc,char *Pdest,char *Ptarget,int Plen)//~v6k4I~
{                                                                  //~v6k4I~
    int rc=0,buffsz,len,swtargeterr=0;                             //~v6k4R~
    HANDLE   fileHandle=NULL;                                      //~v6k4I~
    DWORD   returnedLength;                                        //~v6k4I~
    PREPARSE_MOUNTPOINT_DATA_BUFFER reparseInfo;                   //~v6k4I~
    UWCHART wctarget[_MAX_PATH];                                   //~v6k4I~
    UWCHART prefix[PREFIXCTR]={'\\','?','?','\\'};                 //~v6k4I~
//****************************************                         //~v6k4I~
	UTRACEP("uwinlnk_copymountpoint attr=%x,src=%s,dest=%s,tgt=%s\n",Pattr,Psrc,Pdest,Ptarget);//~v6k4I~
    for (;;)                                                       //~v6k4I~
    {                                                              //~v6k4I~
        if (!(Popt & UWINGTO_COPYOVERRIDE))	//not exist            //~v6k4I~
        {                                                          //~v6k4I~
    		rc=umkdir(Pdest);                                      //~v6k4I~
			UTRACEP("uwinlnk_copymountpoint umkdir rc=%d\n",rc);   //~v6k4I~
    		if (rc)                                                //~v6k4I~
        		break;                                             //~v6k4I~
        }                                                          //~v6k4I~
        fileHandle=CreateFile(Pdest,GENERIC_READ|GENERIC_WRITE,    //~v6k4I~
                            0,NULL,                                //~v6k4I~
                            OPEN_EXISTING,                         //~v6k4I~
                            FILE_FLAG_BACKUP_SEMANTICS|FILE_FLAG_OPEN_REPARSE_POINT ,NULL);//~v6k4I~
		UTRACEP("uwinlnk_copymountpoint CreateFile handle=%x\n",fileHandle);//~v6k4I~
	 	if (fileHandle==INVALID_HANDLE_VALUE)                      //~v6k4I~
        {                                                          //~v6k4I~
    	    rc=GetLastError();                                     //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
//      mbs2wc(Ptarget,Plen,wctarget,sizeof(wctarget),&len);       //~v6k4I~//~v6unR~
        mbs2wc(Ptarget,Plen,wctarget,sizeof(wctarget),&len,0);     //~v6unI~
        buffsz=len+sizeof(REPARSE_MOUNTPOINT_DATA_BUFFER)+16;      //~v6k4I~
	    reparseInfo=(PREPARSE_MOUNTPOINT_DATA_BUFFER)umalloc(buffsz);//~v6k4I~
        if (reparseInfo==NULL)                                     //~v6k4I~
        {                                                          //~v6k4I~
    		rc=UWINLNKERR_MALLOCERR;                               //~v6k4I~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
        memset(reparseInfo,0,buffsz);                              //~v6k4I~
        reparseInfo->ReparseTag=IO_REPARSE_TAG_MOUNT_POINT;        //~v6k4I~
//      reparseInfo->ReparseTargetLength=len+sizeof(prefix);       //~v6k4I~//~v6BjR~
        reparseInfo->ReparseTargetLength=(WORD)(len+(int)sizeof(prefix));//~v6BjI~
        reparseInfo->ReparseTargetMaximumLength=reparseInfo->ReparseTargetLength+sizeof(UWCHART);//~v6k4I~
        reparseInfo->ReparseDataLength=reparseInfo->ReparseTargetLength+12;//~v6k4I~
        memcpy(reparseInfo->ReparseTarget,prefix,sizeof(prefix));  //~v6k4I~
        memcpy(reparseInfo->ReparseTarget+PREFIXCTR,wctarget,len+sizeof(UWCHART));//append last 0//~v6k4I~
                                                                   //~v6k4I~
		UTRACED("uwinlnk_copymountpoint setrepase data",reparseInfo,buffsz);//~v6k4I~
        if(!DeviceIoControl(fileHandle,FSCTL_SET_REPARSE_POINT,    //~v6k4I~
                        reparseInfo,                               //~v6k4I~
                        reparseInfo->ReparseDataLength+REPARSE_MOUNTPOINT_HEADER_SIZE,//~v6k4I~
						NULL,0,                                    //~v6k4I~
                        &returnedLength,NULL))                     //~v6k4I~
        {                                                          //~v6k4I~
            rc=GetLastError();                                     //~v6k4I~
			UTRACEP("uwinlnk_copymountpoint SET_REPASE lasterr=%d\n",rc);//~v6k4I~
	    	CloseHandle(fileHandle);                               //~v6k4I~
            fileHandle=NULL;                                       //~v6k4I~
            urmdir(Pdest);                                         //~v6k4I~
          if (isNtfs(rc,Pdest))                                    //~v6k9I~
          {                                                        //~v6k9I~
            swtargeterr=2;                                         //~v6k9I~
          	rc=UWINLNKERR_NOTNTFS;  //      -11    //junction to file//~v6k9I~
          }                                                        //~v6k9I~
          else                                                     //~v6k9I~
            swtargeterr=uwinlnk_isMounted(Popt,Psrc,Ptarget,Plen)?1:0;//~v6k9R~
        }                                                          //~v6k4I~
        ufree(reparseInfo);                                        //~v6k4I~
        uwinlnk_copyfiletime(0,NULL/*srcfile handle*/,fileHandle,Psrc,Pdest);//~v6knI~
        break;                                                     //~v6k4I~
    }                                                              //~v6k4I~
    if (fileHandle)                                                //~v6k4I~
	    CloseHandle( fileHandle );                                 //~v6k4I~
    if (rc)                                                        //~v6k4I~
    	if (swtargeterr)                                           //~v6k4I~
        {                                                          //~v6k4I~
          if (swtargeterr!=2)                                      //~v6k9I~
          {                                                        //~v6k9I~
			uwincopymountpointerrnotarget(rc,Psrc,Pdest);          //~v6k4I~
            rc=UWINLNKERR_NOTARGET;//  -9     //targetfile not found//~v6k4I~
          }                                                        //~v6k9I~
        }                                                          //~v6k4I~
        else                                                       //~v6k4I~
	    	uwincopyerrmountpoint(rc,Psrc,Pdest);                  //~v6k4R~
    UTRACEP("uwinsub copymountpont rc=%d\n",rc);                   //~v6k4I~
    return rc;                                                     //~v6k4I~
}//uwinlnk_copymountpoint                                          //~v6k4I~
//**************************************************************   //~v6k4I~
//*copy SymLink(on XP proc not found in kernel32)                  //~v6k4I~
//*rc:0 or GetLastError                                            //~v6k4I~
//**************************************************************   //~v6k4I~
int uwinlnk_copysymlink(int Popt,char *Psrc,char *Pdest,char *Ptarget,DWORD Pflag)//~v6k4R~
{                                                                  //~v6k4I~
    int rc=0,opt;                                                  //~v6k4R~
	BOOL rcb;                                                      //~v6k4I~
//  char *procname="CreateSymbolicLinkA";                          //~v6unR~
    char *procname="CreateSymbolicLinkW";                          //~v6unI~
    char *dllname="Kernel32.dll";                                  //~v6k4I~
    ULPTR paddr;                                                   //~v6k4I~
    typedef                                                        //~v6k4I~
//WINBASEAPI       __declspec(import)                              //~v6k4R~
BOOLEAN                                                            //~v6k4R~
//APIENTRY            //FAR __stdcall                              //~v6k4R~
//(*TypedefCreateSymbolicLinkA) (                                  //~v6unR~
(*TypedefCreateSymbolicLinkW) (                                    //~v6unI~
//  /*__in*/     LPCSTR lpSymlinkFileName,                         //~v6unR~
    /*__in*/     LPCWSTR lpSymlinkFileName,                        //~v6unI~
//  /*__in*/     LPCSTR lpTargetFileName,                          //~v6unR~
    /*__in*/     LPCWSTR lpTargetFileName,                         //~v6unI~
    /*__in*/     DWORD dwFlags                                     //~v6k4R~
    );                                                             //~v6k4I~
//static	TypedefCreateSymbolicLinkA proc;                       //~v6unR~
static	TypedefCreateSymbolicLinkW proc;                           //~v6unI~
	WUCS targetW[_MAX_PATHWC],destW[_MAX_PATHWC];                  //~v6unI~
    int opt2,rc2,ucsctr;                                           //~v6unR~
//****************************************                         //~v6k4I~
	UTRACEP("uwinlnk_copysymlink flag=%d,src=%s,dest=%s,target=%s\n",Pflag,Psrc,Pdest,Ptarget);//~v6k4R~
    for (;;)                                                       //~v6k4I~
    {                                                              //~v6k4I~
    	if (!proc)                                                 //~v6k4I~
        {                                                          //~v6k4I~
            opt=UPGPAO_NOW|UPGPAO_NOMSG;        //RTLD_NOW         //~v6k4R~
            rc=uproc_getprocaddr(opt,dllname,NULL/*dllversion*/,procname,NULL/*apiver*/,NULL,&paddr);//~v6k4R~
            if (rc||paddr==0)                                      //~v6k4R~
            {                                                      //~v6k4R~
                rc=UWINLNKERR_NOAPISUPP;   //CreateSymbolicLinc is not supported on XP//~v6k4R~
                break;                                             //~v6k4R~
            }                                                      //~v6k4R~
//          proc=(TypedefCreateSymbolicLinkA)paddr;                //~v6unR~
            proc=(TypedefCreateSymbolicLinkW)paddr;                //~v6unI~
        }                                                          //~v6k4I~
      if (isNtfs(0,Pdest))                                         //~v6k9I~
      	rc=UWINLNKERR_NOTNTFS;  //      -11    //junction to file  //~v6k9I~
      else                                                         //~v6k9I~
      {                                                            //~v6k9I~
        if (Popt & UWINGTO_COPYOVERRIDE)	//not exist            //~v6k4I~
        {                                                          //~v6k4I~
			uwinlnk_delete(Popt,-1,Pdest);                         //~v6k4I~
			UTRACEP("uwinlnk_copysymlink urmdir %s\n",Pdest);      //~v6k4R~
        }                                                          //~v6k4I~
//      rcb=proc(Pdest,Ptarget,Pflag);                             //~v6unR~
		opt2=0;                                                    //~v6unR~
	    rc2=ufilecvUD2WCnopath(opt2,Pdest,destW,sizeof(destW),&ucsctr);//~v6unR~
	    rc2|=ufilecvUD2WCnopath(opt2,Ptarget,targetW,sizeof(targetW),&ucsctr);//~v6unR~
	   if (rc2>=UDRC_FMTERR)                                       //~v6unI~
        rc=GetLastError();//ERROR_INVALID_NAME                     //~v6unI~
       else                                                        //~v6unI~
       {                                                           //~v6unI~
        rcb=proc(destW,targetW,Pflag);                             //~v6unI~
        if (!rcb)                                                  //~v6k4I~
        	rc=GetLastError();                                     //~v6k4I~
        else                                                       //~v6knI~
        	uwinlnk_copyfiletime(0,NULL/*srcfile handle*/,NULL/*destfile handle*/,Psrc,Pdest);//~v6knI~
       }                                                           //~v6unI~
      }                                                            //~v6k9I~
        break;                                                     //~v6k4I~
    }                                                              //~v6k4I~
    if (rc)                                                        //~v6k4I~
        if (rc==ERROR_PRIVILEGE_NOT_HELD)	//         1314L       //~v6k4I~
    		uwincopysymlinkerrprevilege(rc,Psrc,Pdest);            //~v6k4I~
        else                                                       //~v6k4I~
      	if (rc!=UWINLNKERR_NOTNTFS)  //      -11    //junction to file//~v6k9I~
    		uwincopyerr(rc,Psrc,Pdest);                            //~v6k4R~
	UTRACEP("uwinlnk_copysymlink rc=%d\n",rc);                     //~v6k4I~
    return rc;                                                     //~v6k4I~
}//uwinlnk_copysymlink                                             //~v6k4I~
//**************************************************************   //~v6k4I~
//*copy Junction/SymLink                                           //~v6k4I~
//*rc:0 or GetLastError                                            //~v6k4I~
//**************************************************************   //~v6k4I~
int uwinlnk_copy(int Popt,ULONG Pattr,char *Psrc,char *Pdest,char *Pslink)//~v6k9R~
{                                                                  //~v6k4I~
    int rc,tag,len;                                                //~v6k4I~
    ULONG attr;                                                    //~v6k4I~
    char target[_MAX_PATH];                                        //~v6k4I~
    DWORD flag;                                                    //~v6k4I~
    int swnopathchk=0;                                             //~v6knI~
//****************************************                         //~v6k4I~
	UTRACEP("uwinlnk_copy attr=%x,src=%s,dest=%s,slink=%s\n",Pattr,Psrc,Pdest,Pslink);//~v6k4I~//~v6k9R~
#ifdef W32UNICODE                                                  //~v6u9I~
	rc=uwinlnk_gettargetW(Popt,Pattr,Psrc,target,sizeof(target),&len,&attr,&tag,NULL/*Ppreparsebuff*/,NULL/*targetW*/,0,NULL,NULL/*Ppudrc*/);//~v6u9R~
#else                                                              //~v6u9I~
	rc=uwinlnk_gettarget(Popt,Pattr,Psrc,target,sizeof(target),&len,&attr,&tag,NULL/*Ppreparsebuff*/);//~v6k4R~
#endif                                                             //~v6u9I~
    if (!rc)                                                       //~v6k4I~
    {                                                              //~v6k4I~
    	switch(tag)                                                //~v6k4I~
        {                                                          //~v6k4I~
//      case IO_REPARSE_TAG_SYMLINK:      //0xa000000c             //~v6k4R~
        case TAG_SYMLINK:      //0xa000000c                        //~v6k4I~
			UTRACEP("uwinlnk_copy symlink\n");                     //~v6k4I~
            flag=0;                                                //~v6k4I~
        	if(attr & FILE_ATTRIBUTE_DIRECTORY)                    //~v6k4I~
            	flag|=SYMBOLIC_LINK_FLAG_DIRECTORY;                //~v6k4I~
//            rcb=CreateSymbolicLink(Psrc,Pdest,flag);             //~v6k4R~
//            if (!rcb)                                            //~v6k4R~
//                rc=GetLastError();                               //~v6k4R~
//FIXME;FIXED                                                      //~v6u9R~
			rc=uwinlnk_copysymlink(Popt,Psrc,Pdest,target,flag);   //~v6k4R~
            break;                                                 //~v6k4I~
        case IO_REPARSE_TAG_MOUNT_POINT:	//MOUNT POINT, or JUNCTION//~v6k4R~
        	if(strchr(target,':'))                                 //~v6k4I~
//FIXME:FIXED                                                      //~v6u9I~
				rc=uwinlnk_copyjunction(Popt,attr,Psrc,Pdest,target,len);//~v6k4R~
            else                                                   //~v6k4I~
            {                                                      //~v6knI~
            	swnopathchk=1;                                     //~v6knI~
//FIXME:FIXED                                                      //~v6u9R~
				rc=uwinlnk_copymountpoint(Popt,attr,Psrc,Pdest,target,len);//~v6k4I~
            }                                                      //~v6knI~
            break;                                                 //~v6k4I~
        }                                                          //~v6k4I~
      if (!swnopathchk)	//not mountpoint                           //~v6knI~
    	if (!rc && Popt & UWINGTO_CHKTARGET)                       //~v6k4I~
//FIXME;FIXED                                                      //~v6u9R~
			ufilechkslinkpath(Psrc,target,Pdest,NULL/*fpathslinktarget*/,NULL/*ffb3*/);                  //~v6k4I~//~v6k9R~
                                                                   //~v6k4I~
    }                                                              //~v6k4I~
    else                                                           //~v6k4I~
        uwinsuberr(rc,Psrc);                                       //~v6k4R~
    return rc;                                                     //~v6k4I~
}//uwinlnk_copy                                                    //~v6k4I~
//************************************                             //~v6k4I~
int uwinsuberr(int Prc,char *Pfnm)                                 //~v6k4I~
{                                                                  //~v6k4I~
	uerrmsg("rc=%d, ascess failed for %s(Symlinc or Junction)",    //~v6k4I~
            "rc=%d, %s アクセス失敗(シンボリックリンクあるいはジャンクション)",//~v6k4I~
            Prc,Pfnm);                                             //~v6k4I~
    return Prc;                                                    //~v6k4R~
}                                                                  //~v6k4I~
//************************************                             //~v6k4I~
int uwincopyerr(int Prc,char *Psrc,char *Pdest)                    //~v6k4I~
{                                                                  //~v6k4I~
	uerrmsg("rc=%d, copy failed for %s(Symlinc or Junction) to %s",//~v6k4I~
            "rc=%d, %s コピー失敗(シンボリックリンクあるいはジャンクション) 複写先:%s",//~v6k4R~
            Prc,Psrc,Pdest);                                       //~v6k4I~
    return Prc;                                                    //~v6k4I~
}                                                                  //~v6k4I~
//************************************                             //~v6k4I~
int uwincopyerrmountpoint(int Prc,char *Psrc,char *Pdest)          //~v6k4I~
{                                                                  //~v6k4I~
	uerrmsg("rc=%d, copy failed for %s(MountPoint) to %s",         //~v6k4I~
            "rc=%d, %s コピー失敗(マウントポイント) 複写先:%s",    //~v6k4I~
            Prc,Psrc,Pdest);                                       //~v6k4I~
    return Prc;                                                    //~v6k4I~
}                                                                  //~v6k4I~
//************************************                             //~v6k4I~
int uwincopyerrnotarget(int Prc,char *Psrc,char *Ptarget)          //~v6k4I~
{                                                                  //~v6k4I~
	uerrmsg("rc=%d, copy failed for %s, Symlinc or Junction target(%s) not found",//~v6k4I~
            "rc=%d, %s コピー失敗, シンボリックリンクあるいはジャンクションの宛先(%s)が見つかりません",//~v6k4I~
            Prc,Psrc,Ptarget);                                     //~v6k4I~
    return Prc;                                                    //~v6k4I~
}                                                                  //~v6k4I~
//************************************                             //~v6k4I~
int uwincopymountpointerrnotarget(int Prc,char *Psrc,char *Pdest)  //~v6k4I~
{                                                                  //~v6k4I~
	uerrmsg("rc=%d, copy failed for %s, Volume is not mounted",    //~v6k4R~
            "rc=%d, %s コピー失敗,ボリュームがマウントされていません",//~v6k4R~
            Prc,Psrc);                                             //~v6k4R~
    return Prc;                                                    //~v6k4I~
}                                                                  //~v6k4I~
//************************************                             //~v6k4I~
int uwincopysymlinkerrprevilege(int Prc,char *Psrc,char *Pdest)    //~v6k4R~
{                                                                  //~v6k4I~
	uerrmsg("rc=%d, copy failed for %s, Symlink copy requres previlege(Exec as Administrator). OR use skip option.",//~v6k4R~
            "rc=%d, %s コピー失敗,シンボリックリンクのコピーは特権(管理者として実行)が必要。またはスキップオプションを指定する",//~v6k4R~
            Prc,Psrc);                                             //~v6k4I~
    return Prc;                                                    //~v6k4I~
}                                                                  //~v6k4I~
