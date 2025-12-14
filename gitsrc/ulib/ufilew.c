//*CID://+v7e0R~:                             update#=989;         //+v7e0R~
//*********************************************************************************
//v7e0:250613 system() for sush as xfg hungs sume time. manual say reuires flush stream. try _flushall.//~v7e0I~
//v6T4:180217 f2l option to set dbcs "?" for f2l err               //~v6T4I~
//v6J1:170206 errmsg loop when UD fmt err(uerrmsg->ufprintf->ufilecvUD2Wnopath->uerrmsg);occued when !UD_MODE()//~v6J1I~
//v6Hs:170122 (Win)Support maxpath:32767                           //~v6HsI~
//v6Hn:170120 (Win)when not too long but little bit short path fails when rsv name//~v6HnI~
//v6Hh:170118 (Win)prefix \\?\ is effective for also reserved name(it required prefix \\.\)//~v6HnI~//~v6HhR~
//v6Hg:170117 (Win)CreateDirectory maxpath is 248                  //~v6HgI~
//v6He:170116 (Win)wfopen faile by errno=22(invalid cmd) errno=123(invalid name fmt) for \\?\... filename fmt//~v6HeI~
//v6Hd:170115 (Win)no set 8.3 name if it was not set on FiLE_FIND_DATA//~v6HdI~
//v6Hc:170114 (Win)_MAX_PATH is wchar ctr,for dbcs size is doubled.(dir=240,file=255)//~v6HcI~
//v6Hb:170114 leave shortname as NULL;(GetShortPathName fail when len>67, set same as cFilename will cause crash by longname)//~v6HbI~
//v6Ha:170113 (Win:BUG)uGetShortPathName;no more use pathtbl       //~v6HaI~
//v6H9:170109 (Win)del longname using \\?\ prefix(path max is 32767) and Unicode API because move to shortpath dir could not delete dir/file name longer >=260.//~v6H9I~
//v6F8:160911 invalid name format for profile record when "." is included in UD range//~v6F8I~
//            add split functiopn                                  //~v6F8I~
//v6H3:170105 (BUG)crash when too long name;it should chk strlen   //~v6H3I~//~v6H9M~
//v6Eh:160801 (W32:BUG)utfcvU82UDnopath;when UFCVO_FNLC(set localecode) should close UD string//~v6EhI~
//v6Eb:160729 (BUG) err msg "Invalid FileNAme Format" when saved cmd stack contains UD format char(0x01 etc)//~v6EbI~
//v6E3:160718 (W32)add ufilestrlenUDstrip for dirlist green attr len//~v6E3I~
//v6E2:160718 (W32)by v6E2(ctlen=2 but lclen=1) not usr USUBSTRLEN //~v6E2I~
//v6BR:160319 (W32)Bug of 6BS, E A?" cmd disply errmsg 0xccccc(uninitialized area) because wincp2ucs1 return rc=4 by "?" is contained to output//~v6BRI~
//v6Ba:160201 (BUG:W32)allow "/" as dir sepc for remote ftp file   //~v6BaI~
//v6B1:160114 trace,mtrace file no share mode                      //~v6B1I~
//v6B0:151222 (BUG)xe://vb18:151222 dlcmd rename loop(by u8len==0) by mixedstrupdate bug(codetbl indicate u8 but data is lcdbcs only)//~v6B0I~
//v6yh:150315 _wfullpath set \\dir for \dir when cd is reservedname//~v6yeI~
//v6ye:150314 (BUG)mkdir failes for "AUX" in xcopy processing      //~v6yeI~
//v6ya:150313 chdir for reserved name dir                          //~v6y9I~
//v6y9:150312 _tempnam wait for prefix:lpt1(filebkupreopen); reason is not dir but prefix//~v6y9I~
//v6y8:150312 _tempnam wait for prefix:aux(filebkupreopen); Reason is not reservedname but UD format.//~v6y8I~
//v6y7:150312 need v6w0 for filenameW                              //~v6y7I~
//v6y6:150312 CreteFile is also same as v6y5(copy time stamp)      //~v6y6I~
//v6y5:150312 copy cmd wait at fread for such as AUX,COMx because fopen success and no prefix \\.\ is prepend.//~v6y5I~
//v6y4:150311 CreateFile for prn(copypath)                         //~v6y4I~
//v6y3:150311 SetFileAttribute for prn(copypath)                   //~v6y3I~
//v6y2:150311 additional to v6w0(fopen fail for reserved filename prn etc)//~v6y2I~
//            v6w0 is not applyed for wildcopy fopen which dose not call ufullpath//~v6y2I~
//v6w0:141108 (Win:BUG)windows BUG:_fullpath/_wfullpath returns \\.\prn for g:\src\xe\prn//~v6w0I~
//            and returns invalid name(\\.\g:\src\xe\prn is effective)//~v6w0I~
//v6uK:140603 add WC2UDnopath for exe * cmd                        //~v6uKI~
//v6uF:140529 (W32)UCVUCS_UCS4:if v6uE output is 4byte ucs,so specify only when 4byte ucs is required,else output surrogate pair for UCS4//~v6uFI~
//v6uE:140529 (W32)request explicit option UCVUCS_UCS4 for UCS4 for also Win//~v6u9I~
//v6un:140502 MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;pass it not W func as is//~vaunI~
//v6ug:140425 (BUG of v6ua)scan on dd fmt should chk dbcs(confirm UD:0x01 is ascii)//~vaugI~
//v6ue:140423 (Win:BUG)See v6u7;surrogate pair support (!UTF8UCS4 but UCS4(WUCS is 4 byte when UTF8UCS4)),treate as 2 unprintable//~vaueI~
//vaud:140422 (Win:BUG of vauc)do fullpathW for also all ascii for the case currrentdir(.\) may be subchar dir name//~vaudI~
//vauc:140420 (Win)unicode support by UD fmt string                //~vaucI~
//v6ua:140410 (Win)use UNICODE Api;apply WIN32_FIND_DATAW by "#ifdef W32UNICODE"//~v6uaI~
//v6u9:140408 (Win)use UNICODE Api using special filename fmt.     //~v6u9I~
//*****************************************************************
//*ufilew.c
//******************************************************
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <direct.h>                                                //~v6u9R~
#include <fcntl.h>                                                 //~v6HeI~
#include <io.h>                                                    //~v6HeI~

#include <windows.h>
#include <wchar.h>                                                 //~v6uaR~
#include <dos.h>                                                   //~v6uaI~

#define NO_MACRO_REDIRECT   //for ulibdefw.h                       //~v6uaR~
#include <ulib.h>
#include <uque.h>
#include <ualloc.h>
#include <ustring.h>
#include <utrace.h>
#include <uwinsub.h>
#include <ucvucs.h>                                                //~v6u9I~
#include <ucvext.h>
#include <ucvext2.h>
#include <utf.h>                                                   //~v6u9R~
#include <utf22.h>                                                 //~v6uaI~
#include <ufile.h>                                                 //~v6u9I~
#include <uwinsub.h>                                               //~v6u9R~
#include <uerr.h>                                                  //~v6u9R~
#define GBL_UFILEW                                                 //~v6uaI~
#include <ufilew.h>                                                //~v6u9I~
#include <uftp.h>                                                  //~v6uaI~
#include <uedit.h>                                                 //~v6u9R~
#include <uedit2.h>                                                //~v6u9R~
#include <ustring.h>                                               //~v6H3I~
#include <ufemsg.h>                                                //~v6H9I~

//===============================================================
//#ifdef ULIB64X  //ptr:64bit,long:32bit                             //~v6hhI~//~v6HnR~
////  #define TRYRC_RSVNAME (FILE*)((unsigned long long )(-2))     //~v6HnR~
//    #define TRYRC_RSVNAME ((HANDLE)((LONG_PTR)-2))               //~v6HnR~
//#else                                                            //~v6HnR~
//    #define TRYRC_RSVNAME ((HANDLE)-2)                           //~v6HnR~
//#endif                                                           //~v6HnR~
//*******************************************************          //~v6uaI~
static int SlastReservedNameDriveLetter;                                  //~v6yhR~//~v6HsR~
#ifndef BBB                                                        //~v6HsI~
static UWCH SmaxbuffW[MAX_PATH_LONGNAME_MAXCTR];  // 32768            //by \\?\ support max 32767 chars//~v6HsI~
static UWCH SmaxbuffW2[MAX_PATH_LONGNAME_MAXCTR]; // 32768            //by \\?\ support max 32767 chars//~v6HsI~
static UWCH SmaxbuffW3[MAX_PATH_LONGNAME_MAXCTR]; // 32768            //by \\?\ support max 32767 chars//~v6HsI~
static UWCH SmaxbuffW4[MAX_PATH_LONGNAME_MAXCTR]; // 32768            //by \\?\ support max 32767 chars//~v6HsI~
static UWCH SmaxbuffW5[MAX_PATH_LONGNAME_MAXCTR]; // 32768            //by \\?\ support max 32767 chars//~v6HsI~
static UWCH SmaxbuffW6[MAX_PATH_LONGNAME_MAXCTR]; // 32768            //by \\?\ support max 32767 chars//~v6HsI~
#define MAXBUFFSZ sizeof(SmaxbuffW)                                //~v6HsI~
#endif                                                             //~v6HsI~
//*******************************************************          //~v6yhI~
int ufilecvsetpathtbl(int Popt,UWCH *Pfnmw,int Pucsctr,char *Ppathtbl,int Ppathtblsz,int Ppathctr,int Pudtype,int *Ppoutvtr);//~v6uaR~
#define UFCVSPTO_NEXT1       0x01  //set next entry only           //~v6uaI~
int adjustReservedNameW(UWCH *Pfnm,UWCH *Pfpath,int Pbuffsz);      //~v6w0R~
int adjustReservedName(char *Pfnm,char *Pfpath,int Pbuffsz);       //~v6w0I~
HDIR chkReservedNameW(HDIR Phdir,UWCH *Pfnm,WIN32_FIND_DATAW *Ppw32fd);//~v6w0I~
int tryMoveFileForReservedNameW(UWCH *Pold,UWCH *Pnew,int Prc);    //~v6w0R~
int tryRemoveForReservedName(char *Pfnm,int Prc);                  //~v6w0I~
FILE *tryFopenForReservedName(const char *Pfnm,const char *Popenopt,FILE *Pfh);//~v6y2I~
FILE *tryWfopenForReservedName(UWCH *Pfnm,UWCH *Popenopt);         //~v6y2I~
int trySetFileAttributesW(UWCH *Pfpathw,DWORD Pdwattr,int Prc);    //~v6y3I~
HANDLE tryCreateFileForReservedName(UWCH *Pfnmw,DWORD Pacc,DWORD Pshare,LPSECURITY_ATTRIBUTES Psecattr,DWORD Pdisp,DWORD Pattr,HANDLE Phtemp);//~v6y4I~
int tryWremoveForReservedName(UWCH *Pfnmw,int Prc);                //~v6y7I~
UWCH *tryWtempnamForReservedName(UWCH *Pdirw,UWCH *Pprefixw);      //~v6y8R~
char *tryTempnamForReservedName(const char *Pdir,const char *Pprefix);//~v6y8I~
int tryChdirForReservedName(char *Pfnm,int Prc);                   //~v6y9I~
int tryWChdirForReservedName(UWCH *Pfnmw,int Prc);                 //~v6y9I~//~v6yeR~//~v6HnR~
int tryMkdirForReservedName(char *Pfnm,int Prc);                   //~v6yeI~
int tryWMkdirForReservedName(UWCH *Pfnmw,int Prc);                 //~v6yeI~//~v6HnR~
#ifdef AAA                                                         //~v6HsI~
int adjustReservedNameWRoot(UWCH *Pfnm,UWCH *Pfpath,int Pbuffsz);  //~v6yeI~
#endif                                                             //~v6HsI~
char *adjustReservedNameRootDrive(char *Pfnm,char *Pfpath,int Pbuffsz);//~v6yhI~
#ifdef AAA                                                         //~v6HsI~
FILE *ufopenWLong(int Popt,UWCH *PfnmW,UWCH *PopenoptW);           //~v6HeI~
#endif                                                             //~v6HsI~
HDIR tryLongNamePrefixFindFirstFileW(HDIR Phdir,UWCH *Pfnm,WIN32_FIND_DATAW *Ppw32fd);//~v6HhR~
int tryRmdirForReservedName(char *Pfnm,int Prc);                   //~v6HnI~
BOOL tryGetFileAttributesExW(UWCH *Pfpathw,GET_FILEEX_INFO_LEVELS Pinfolvl,LPVOID Ppinfo,int Prc);//~v6HsR~
BOOL tryGetDiskFreeSpaceW(UWCH *Pfpathw,LPDWORD Psector,LPDWORD Pbyte,LPDWORD Pfree,LPDWORD Ptotal,int Prc);//~v6HsI~
int tryWRmdirForReservedName(UWCH *Pfnmw,int Prc);                 //~v6HsI~
//******************************************************************//~v6HnI~
static int SmovefileExflag;                                          //~v6HnI~//~v6HsR~
static int SswRsvNameTryFailed;                                    //~v6HnI~
//**************************************************************** //~v7e0I~
void flushstreamw()                                                //~v7e0I~
{                                                                  //~v7e0I~
    UTRACEP("%s",UTT);                                             //~v7e0I~
	_flushall();                                                   //~v7e0I~
}                                                                  //~v7e0I~
//*******************************************************          //~v6uaI~
//*get file path name length(length containing last '\' from top)  //~v6uaI~
//*parm 1:filename                                                 //~v6uaI~
//*return:length, <0 if err                                        //~v6uaI~
//*******************************************************          //~v6uaI~
int upathlenWW(int Popt,UWCH *Pfilename)                           //~v6uaI~
{                                                                  //~v6uaI~
    UWCH *pc;                                                      //~v6uaI~
    UWCH *pc2;                                                     //~v6BaI~
    int ctr;                                                       //~v6uaI~
//*********************************                                //~v6uaI~
//if (pc=strrchr(Pfilename,FTP_DIR_SEPC),!pc)	//allow "/" as dir sep//~v6uaI~
  if (pc=strrchrW(Pfilename,FTP_DIR_SEPC),!pc)	//allow "/" as dir sep//~v6uaI~
  {                                                                //~v6uaI~
//  if (pc=ustrrchr2(Pfilename,'\\'),!pc)                          //~v6uaI~
    if (pc=strrchrW(Pfilename,'\\'),!pc)                           //~v6uaI~
        return -16;     //avoid -1                                 //~v6uaI~
  }                                                                //~v6uaI~
  else                                                             //~v6BaI~
  {                                                                //~v6BaI~
    if (pc2=strrchrW(Pfilename,DIR_SEPC),pc2)	//found both       //~v6BaI~
    {                                                              //~v6BaI~
    	if (pc2>pc)                                                //~v6BaI~
        	pc=pc2;	//strRchr                                      //~v6BaI~
    }                                                              //~v6BaI~
  }                                                                //~v6BaI~
//    return (int)((ULPTR)pc-(ULPTR)Pfilename)+1;                  //~v6uaI~
    ctr=sz2ctrW((int)((ULPTR)pc-(ULPTR)Pfilename))+1;                     //~v6uaI~//~v6yeR~
    if (Popt & UPLWO_CTR)                                          //~v6uaI~
    	return ctr;                                                //~v6uaI~
    return ctr2szW(ctr);                                           //~v6uaI~
}//upathlenWW                                                      //~v6uaI~
//*****************************************************************
//*cv ucs2-->utf8
//*****************************************************************
int ufilecvucs2utfW(int Popt,PWCH Ppucs,int Pucsctr,char *Ppu8,int Pbuffsz,int *Pplenu8)
{
    int rc,opt=0,ucsctr,u8len;
//*********************************
    if (!(ucsctr=Pucsctr))
    	ucsctr=strctrW(Ppucs);
	UTRACED("inp ucs",Ppucs,ctr2szW(ucsctr));
  	rc=ucvext_winucs2cp(opt,CP_UTF8,Ppucs,ucsctr,Ppu8,Pbuffsz,&u8len);
    if (Pplenu8)
        *Pplenu8=u8len;
    if (Popt & UFCVO_STRZ)
    	*(Ppu8+u8len)=0;
    UTRACED("out u8",Ppu8,u8len);
    UTRACEP("%s:rc=%d\n",UTT,rc);
    return rc;
}//ufilecvucs2utfW
//******************************************************************
//*utf 2 ucs2; allows surrogate pair
//*rc:16:optionally allascii
//******************************************************************
int ufilecvutf2ucsW(int Popt,UCHAR *Ppmbs,int Pinplen,UWCH *Ppucs,int Poutbuffsz,int *Ppoutctr)
{
    int outlen,rc,chklen,errctr,opt,ucsctr;
//*********************
    UTRACED("inp u8",Ppmbs,Pinplen);
//  Gulibutfmode|=GULIBUTF_WINSURROGATE;// 0x00800000  //parm to uccvutf2ucs; set surrogate pare for ucs4(>0x10000)//~vaueR~
    opt=UCVUCS_LE;
//  opt|=UCVUCS_UCS4|UCVUCS_UCS4S;  //accept ucs4 and output by UTF16//~v6uER~//~v6uFR~
    if (Popt & UFCVO_RETALLASCII)
    	opt|=UCVUCS_RETALLA;
    rc=ucvsutf2ucs(0/*errfunc*/,opt,Ppmbs,Pinplen,(UCHAR*)(ULPTR)Ppucs,Poutbuffsz,&chklen,&outlen,&errctr);
//  Gulibutfmode&=~GULIBUTF_WINSURROGATE;// 0x00800000  //parm to uccvutf2ucs; set surrogate pare for ucs4(>0x10000)//~vaueR~
    ucsctr=sz2ctrW(outlen);
    if (Ppoutctr)
    	*Ppoutctr=ucsctr;
    if (Popt & UFCVO_STRZ)
    	*(Ppucs+ucsctr)=0;
    UTRACED("out ucs2",Ppucs,outlen);
    return rc;
}//ufilecvutf2ucsW
//*******************************************************
//*ucs2<--locale
//*******************************************************
int ufilecvcp2ucsW(int Popt,char *Plc,int Plclen,UWCH *Puwch,int Pbuffsz,int *Ppucsctr)
{
	int rc,lclen,outlen,ucsctr,buffsz,opt;                         //~vaunR~
//*****************************
	if (!(lclen=Plclen))
    	lclen=strlen(Plc);
    UTRACED("inp lc",Plc,lclen);
	buffsz=Pbuffsz;
	if (Popt & UFCVO_STRZ)
    	buffsz-=UWCHSZ;
    opt=0;                                                         //~vaunI~
    if (Popt & UFCVO_ALLOWCP2UERR)      //ignore MultibyteToWideChar err//~vaunI~
    	opt|=UWSMWO_ALLOWCP2UERR; //      0x01   //ignore MultibyteToWideChar err//~vaunI~
	rc=mbs2wc(Plc,lclen,Puwch,buffsz,&outlen,opt);                 //~vaunR~
    if (!rc)
    {
    	ucsctr=sz2ctrW(outlen);
    	if (Ppucsctr)
    		*Ppucsctr=ucsctr;
        if (Popt & UFCVO_STRZ)
        	*(Puwch+ucsctr)=0;
	    UTRACED("out ucs2",Puwch,outlen);
    }
	 UTRACEP("%s rc=%d\n",UTRACETIT,rc);
    return rc;
}//ufilecvcp2ucsW
//*******************************************************
//*ucs2-->locale
// rc from outmbs::UCVEXTRC_SUBCH,WideToMultiByte-GetLAstError()   //~v6u9R~
//*******************************************************
int ufilecvucs2cpW(int Popt,UWCH *Puwch,int Pucsctr,char *Plc,int Pbuffsz,int *Pplclen)
{
	int rc,ctr,lclen,buffsz,opt=0;
//*****************************
	if (!(ctr=Pucsctr))
    	ctr=strctrW(Puwch);
    UTRACED("inp uwch",Puwch,ctr2szW(ctr));
	buffsz=Pbuffsz;
	if (Popt & UFCVO_STRZ)
    	buffsz--;
	if (Popt & UFCVO_SETSUBCHRC)
		opt|=UWSOMO_SETSUBCHRC;	//set rc if trans err
	if (Popt & UFCVO_BESTFIT)                                      //~v6uaI~
		opt|=UWSOMO_BESTFIT;	//set rc if trans err              //~v6uaI~
	rc=outmbs(opt,Puwch,ctr2szW(ctr),Plc,buffsz,&lclen);
    if (!rc||rc==UCVEXTRC_SUBCH)                                   //~v6u9R~
    {
	    if (Pplclen)
    		*Pplclen=lclen;
        if (Popt & UFCVO_STRZ)
        	*(Plc+lclen)=0;
    }
	UTRACEP("%s rc=%d,out cp=%s\n",UTRACETIT,rc,Plc);
    return rc;
}//ufilecvucs2cpW
//#ifdef AAA                                                         //~v6uaI~//~vaucR~
////****************************************************************//~vaucR~
////locale/utf to ucs                                              //~vaucR~
////apply locale as default if both ok                             //~vaucR~
////no set strz                                                    //~vaucR~
////****************************************************************//~vaucR~
//int ufilecvlf2UDsub(int Popt,char *Pfnm,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~vaucR~
//{                                                                //~vaucR~
//    int rc,rc2,rcf,rcl,opt,ucsctrl,ucsctrf,outlen,charctr,reslen;//~vaucR~
//    int swu8=0,swlc=0;                                           //~vaucR~
//    char *pco;                                                   //~vaucR~
//    UWCH wkuwchf[_MAX_PATHWC];                                   //~vaucR~
//    UWCH wkuwchl[_MAX_PATHWC];                                   //~vaucR~
////*****************************                                  //~vaucR~
//    UTRACED("inp",Pfnm,Plen);                                    //~vaucR~

//    if (Popt & UFNMCVO_UTF8)                                     //~vaucR~
//    {                                                            //~vaucR~
//        opt=UFCVO_RETALLASCII;                                   //~vaucR~
//        rcf=ufilecvutf2ucsW(opt,Pfnm,Plen,wkuwchf,sizeof(wkuwchf),&ucsctrf);//~vaucR~
//        if (!rcf)                                                //~vaucR~
//            swu8=1;                                              //~vaucR~
//        else                                                     //~vaucR~
//            swlc=1;                                              //~vaucR~
//    }                                                            //~vaucR~
//    if (!swu8 && !swlc) //not yet determined                     //~vaucR~
//    {                                                            //~vaucR~
//        opt=0;                                                   //~vaucR~
//        rcl=ufilecvcp2ucsW(opt,Pfnm,Plen,wkuwchl,sizeof(wkuwchl),&ucsctrl);//~vaucR~
//        if (!rcl && Plen && *(Pfnm+Plen-1)=='\\' && *(wkuwchl+ucsctrl-1)!=L'\\')    //last \ is dbcs 2nd//~vaucR~
//            return UDRC_CONT; //avoid next string treated as utf8//~vaucR~

//        if (rcl)  //lc ng                                        //~vaucR~
//        {                                                        //~vaucR~
//            opt=UFCVO_RETALLASCII;                               //~vaucR~
//            rcf=ufilecvutf2ucsW(opt,Pfnm,Plen,wkuwchf,sizeof(wkuwchf),&ucsctrf);//~vaucR~
//            if (!rcf)                                            //~vaucR~
//                swu8=1;                                          //~vaucR~
//        }                                                        //~vaucR~
//    }                                                            //~vaucR~

//    outlen=0;                                                    //~vaucR~
//    reslen=Pbuffsz;                                              //~vaucR~
//    pco=Poutbuff;                                                //~vaucR~

//    rc2=0;                                                       //~vaucR~
//    if (swu8)                                                    //~vaucR~
//    {                                                            //~vaucR~
//        opt=UFCVO_SETSUBCHRC;   //rc if trans err                //~vaucR~
//        rc2=ufilecvucs2cpW(opt,wkuwchf,ucsctrf,Poutbuff,Pbuffsz,&charctr);//~vaucR~
//    }                                                            //~vaucR~
//    rc=UDRC_ERR;          //buff shortage                        //~vaucR~
//    for (;;)                                                     //~vaucR~
//    {                                                            //~vaucR~
//        if (rc2==UCVEXTRC_SUBCH)                                 //~vaucR~
//        {                                                        //~vaucR~
//            rc=UDRC_UTF8SUBC;                                    //~vaucR~
//            *pco++=UD_NOTLC;                                     //~vaucR~
//            *pco++=UD_UTF8WCSUBC;                                  //~v6uaR~//~vaucR~
//            reslen-=2;                                           //~vaucR~
//            outlen=2;                                            //~vaucR~
//        }                                                        //~vaucR~
////        else                                                     //~v6uaR~//~vaucR~
////        if (swu8 && !rc2 && Popt & UFCVO_UTF8FN)                 //~v6uaR~//~vaucR~
////        {                                                        //~v6uaR~//~vaucR~
////            rc=UDRC_UTF8FN;                                      //~v6uaR~//~vaucR~
////            *pco++=UD_NOTLC;                                     //~v6uaR~//~vaucR~
////            *pco++=UD_UTF8FN;                                    //~v6uaR~//~vaucR~
////            reslen-=2;                                           //~v6uaR~//~vaucR~
////            outlen=2;                                            //~v6uaR~//~vaucR~
////        }                                                        //~v6uaR~//~vaucR~
//        else                                                       //~v6uaI~//~vaucR~
//        if (swu8 && !rc2 && Popt & UFCVO_SETUTF8OK)                //~v6uaR~//~vaucR~
//        {                                                          //~v6uaI~//~vaucR~
//            rc=UDRC_UTF8OK;                                        //~v6uaI~//~vaucR~
//            *pco++=UD_NOTLC;                                       //~v6uaI~//~vaucR~
//            *pco++=UD_UTF8WC;                                      //~v6uaI~//~vaucR~
//            reslen-=2;                                             //~v6uaI~//~vaucR~
//            outlen=2;                                              //~v6uaI~//~vaucR~
//        }                                                          //~v6uaI~//~vaucR~
//        if (Plen>reslen)                                         //~vaucR~
//            break;                                               //~vaucR~
//        memcpy(pco,Pfnm,Plen);                                   //~vaucR~
//        outlen+=Plen;                                            //~vaucR~
//        reslen-=Plen;                                            //~vaucR~
//        pco+=Plen;                                               //~vaucR~
//        if (rc!=UDRC_ERR) //UTF8OK or UTF8SUBC                   //~vaucR~
//        {                                                        //~vaucR~
//            if (reslen<=0)                                       //~vaucR~
//            {                                                    //~vaucR~
//                rc=UDRC_ERR;          //buff shortage            //~vaucR~
//                break;                                           //~vaucR~
//            }                                                    //~vaucR~
//            if (*(pco-1)==DIR_SEPC)                              //~vaucR~
//                *(pco-1)=UD_NOTLC,*pco++=DIR_SEPC;               //~vaucR~
//            else                                                 //~vaucR~
//                *pco++=UD_NOTLC;                                 //~vaucR~
//            outlen++;                                            //~vaucR~
//        }                                                        //~vaucR~
//        else                                                     //~vaucR~
//            rc=0;   //no utf str                                 //~vaucR~
//        break;                                                   //~vaucR~
//    }                                                            //~vaucR~
//    if (Ppoutlen)                                                //~vaucR~
//        *Ppoutlen=outlen;                                        //~vaucR~
//    UTRACEP("%s:rc=%d,swlc=%d\n",UTT,rc,swlc);                   //~vaucR~
//    UTRACED("out",Poutbuff,outlen);                              //~vaucR~
//    return rc;                                                   //~vaucR~
//}//ufilecvlf2UDsub                                               //~vaucR~
////****************************************************************//~vaucR~
////locale/utf to UD fmt(enclose utf8 path)                        //~vaucR~
////return UDRC_                                                   //~vaucR~
////****************************************************************//~vaucR~
//int ufilecvlf2UD(int Popt,char *Pfnm,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~vaucR~
//{                                                                //~vaucR~
//    int rc=0,rc2,reslen,resleno,ilen,len,outlen,opt;             //~vaucR~
//    char *pc,*pc2,*pc3,*pco;                                     //~vaucR~
////*****************                                              //~vaucR~
//    if (!(ilen=Plen))                                            //~vaucR~
//        ilen=strlen(Pfnm);                                       //~vaucR~
//    UTRACED("inp",Pfnm,ilen);                                    //~vaucR~
//    for (pc=Pfnm,pc3=pc,reslen=ilen,pco=Poutbuff,resleno=Pbuffsz-1;//~vaucR~
//        reslen>0 && resleno>0;)                                  //~vaucR~
//    {                                                            //~vaucR~
//        opt=Popt;                                                //~vaucR~
//        pc2=umempbrk(pc3,"\\/",reslen);                          //~vaucR~
//        if (pc2)                                                 //~vaucR~
//            len=PTRDIFF(pc2,pc)+1;  //path last '\' to chk dbcs 2nd//~vaucR~
//        else                                                     //~vaucR~
//        {                                                        //~vaucR~
//            len=reslen;                                          //~vaucR~
//            if (Popt & UFNMCVO_UTF8MEMB)                         //~vaucR~
//            {                                                    //~vaucR~
//                opt&=UFNMCVO_LC;                                 //~vaucR~
//                opt|=UFNMCVO_UTF8;                               //~vaucR~
//            }                                                    //~vaucR~
//            else                                                 //~vaucR~
//            if (Popt & UFNMCVO_LCMEMB)                           //~vaucR~
//            {                                                    //~vaucR~
//                opt&=UFNMCVO_UTF8;                               //~vaucR~
//                opt|=UFNMCVO_LC;                                 //~vaucR~
//            }                                                    //~vaucR~
//        }                                                        //~vaucR~
//        rc2=ufilecvlf2UDsub(opt,pc,len,pco,resleno,&outlen);     //~vaucR~
//        if (rc2==UDRC_ERR)                                       //~vaucR~
//            break;                                               //~vaucR~
//        if (rc2==UDRC_CONT) //last '\' is dbcs 2nd               //~vaucR~
//        {                                                        //~vaucR~
//            pc3=pc2+1;  //continue umempbrk                      //~vaucR~
//            continue;                                            //~vaucR~
//        }                                                        //~vaucR~
//        rc|=rc2;    //UDRC_UTF8OK/UDRC_UTF8SUBC                  //~vaucR~
//        pco+=outlen;                                             //~vaucR~
//        resleno-=outlen;                                         //~vaucR~
//        reslen-=len;                                             //~vaucR~
//        if (!pc2)                                                //~vaucR~
//            break;                                               //~vaucR~
//        pc+=len;                                                 //~vaucR~
//        pc3=pc;                                                  //~vaucR~

//    }                                                            //~vaucR~
//    *pco=0;                                                      //~vaucR~
//    outlen=PTRDIFF(pco,Poutbuff);                                //~vaucR~
//    UTRACED("outucs",Poutbuff,outlen);                           //~vaucR~
//    if (reslen)                                                  //~vaucR~
//        rc=UDRC_ERR;   //outbuff shortage                        //~vaucR~
//    if (Ppoutlen)                                                //~vaucR~
//        *Ppoutlen=outlen;                                        //~vaucR~
//    UTRACEP("%s:rc=%d,outlen=%d\n",UTT,rc,outlen);               //~vaucR~
//    return rc;                                                   //~vaucR~
//}//ufilecvlf2UD                                                  //~vaucR~
//#endif //AAA                                                       //~v6uaI~//~vaucR~
//**************************************************************** //~v6H9R~
//*prepend longname prefix                                         //~v6H9R~
//*rc:0:shortname; 1:prefix inserted 2:already set; 3:not fullpath, 4:buff shortage//~v6H9R~
//**************************************************************** //~v6H9R~
int ufilewSetLongnamePrefix(int Popt,UWCH *PfnmW,int Pctr,int Pbuffsz,int *Ppucsctr/*optional*/)//~v6H9R~
{                                                                  //~v6H9R~
	int prefixsz,szold;                                            //~v6H9R~
//**************                                                   //~v6H9R~
    UTRACEP("%s:opt=%x,ctr=%d,buffsz=%d",UTT,Popt,Pctr,Pbuffsz);   //~v6HgR~
    UTRACED("longnameW inp",PfnmW,ctr2szW(Pctr));                  //~v6H9I~
//  if (Pctr<_MAX_PATH)                                            //~v6H9I~//~v6HcR~
 if (!(Popt & UFCVO_RSVNAME)) //    0x020000       //path is dir path(max:248)//~v6HnI~
 {                                                                 //~v6HnI~
  if (Popt & UFCVO_DIRPATH) //    0x010000       //path is dir path(max:248)//~v6HgR~
  {                                                                //~v6HgI~
    if (Pctr<MAX_PATH_CTR_DIR)   //char ctr<248                    //~v6HgR~
    	return 0;                                                  //~v6HgI~
  }                                                                //~v6HgI~
  else                                                             //~v6HgI~
  {                                                                //~v6HgI~
    if (Pctr<MAX_PATH_CTR)   //char ctr<260                        //~v6HcR~
    	return 0;                                                  //~v6H9I~
  }                                                                //~v6HgI~
 }                                                                 //~v6HnI~
    if (!IS_FULLPATH(PfnmW))                                       //~v6H9R~
        return 3;                                                  //~v6H9I~
	prefixsz=ctr2szW(WIN_LONGNAME_PREFIXCTR);                      //~v6H9M~
    if (!memcmp(PfnmW,WIN_LONGNAME_PREFIXW,(size_t)prefixsz))	//already set prefix//~v6H9R~
    	return 2;                                                  //~v6H9R~
	szold=ctr2szW(Pctr);                                           //~v6H9R~
    if (szold+prefixsz>=Pbuffsz)                                   //~v6H9I~
    	return 4;                                                  //~v6H9I~
	memmove(PfnmW+WIN_LONGNAME_PREFIXCTR,PfnmW,(size_t)szold+sizeof(UWCH));//~v6H9R~
	memcpy(PfnmW,WIN_LONGNAME_PREFIXW,(size_t)prefixsz);           //~v6H9M~
    if (*Ppucsctr)                                                 //~v6H9I~
    	*Ppucsctr=Pctr+WIN_LONGNAME_PREFIXCTR;                     //~v6H9I~
    UTRACED("longnameW out",PfnmW,szold+prefixsz);                 //~v6H9R~
    return 1;                                                      //~v6H9R~
}//ufilewSetLongnamePrefix                                         //~v6H9R~
//**************************************************************** //~vaudI~
//*to UWCH from str containing utf8 with delm char ignore dir sepc for profile open//~vaudI~
//*output UWCH-Z                                                   //~vaudI~
//rc:0:no utf8,0x02:contains utf8subch,0x01:optionally chked containing utf8ok,UDRC_FMTERR and set ERROR_INVALID_NAME//~vaudI~
//**************************************************************** //~vaudI~
int ufilecvUD2WCnopath(int Popt,char *Pfnm,UWCH *PfnmW,int Pbuffsz,int *Ppucsctr)//~vaudI~
{                                                                  //~vaudI~
    UCHAR *pc,*pc2,*pc3;                                           //~vaudI~
    UWCH *pw;                                                      //~vaudI~
    int len,ucsctr,rc=0,rc2=0,reslen,udtype,opt,lenx;                       //~vaudR~//~vaunR~//~v6u9R~
//  char wkfpathx[_MAX_PATH];                                      //~v6u9R~//~v6H9R~
    char wkfpathx[_MAX_PATH_LONG];                                 //~v6H9R~
    int ilen;                                                      //~v6H3I~
    UCHAR *pce;                                                    //~v6H3I~
//************************                                         //~vaudI~
    UTRACED("inp",Pfnm,strlen(Pfnm));                              //~vaudI~
	opt=UFCVO_ALLOWCP2UERR;	//ignore MultibyteToWideChar err       //~vaunI~
//  pce=Pfnm+_MAX_PATH-1;                                          //~v6H3I~//~v6H9R~
    pce=Pfnm+(int)strlen(Pfnm);                                    //~v6H9I~
    for (pc=Pfnm,pw=PfnmW,reslen=Pbuffsz-UWCHSZ;*pc;pc=pc3)        //~vaudR~
    {                                                              //~vaudI~
        rc2=0;                                                     //~vaudI~
//      pc2=strchr(pc,UD_NOTLC);                                   //~v6H3R~
        ilen=PTRDIFF(pce,pc);                                      //~v6H3I~
        pc2=ustrnchr(pc,UD_NOTLC,ilen);                            //~v6H3R~
        if (pc2)                                                   //~vaudI~
            len=PTRDIFF(pc2,pc);                                   //~vaudI~
        else                                                       //~vaudI~
//          len=strlen(pc);                                        //~v6H3R~
            len=strnlen(pc,ilen);                                  //~v6H3R~
        if (len)                                                   //~vaucR~
        {                                                          //~vaucI~
        	rc2=ufilecvcp2ucsW(opt,pc,len,pw,reslen,&ucsctr);        //~vaucR~//~vaunR~
        	if (rc2)                                               //~vaucR~
            	break;                                             //~vaucR~
        	pw+=ucsctr;                                            //~vaucR~
        	reslen-=ctr2szW(ucsctr);                               //~vaucR~
        }                                                          //~vaucI~
        if (!pc2)   //no UD_NOTLC found                            //~vaudI~
            break;                                                 //~vaudI~
        pc2++;                                                     //~vaudI~
        udtype=*pc2++;                                             //~vaudI~
        rc|=udtype;                                                //~vaudI~
//      pc3=strchr(pc2,UD_NOTLC);                                  //~v6H3R~
        ilen=PTRDIFF(pce,pc2);                                     //~v6H3I~
        pc3=ustrnchr(pc2,UD_NOTLC,ilen);                           //~v6H3R~
        if (!pc3)                                                  //~vaudI~
        {                                                          //~vaudI~
        	rc2=4;	//fmt err                                      //~vaudI~
            break;                                                 //~vaudI~
        }                                                          //~vaudI~
        len=PTRDIFF(pc3,pc2);                                      //~vaudI~
        if (!len)                                                  //~vaudI~
        {                                                          //~vaudI~
        	rc2=4;	//fmt err                                      //~vaudI~
            break;                                                 //~vaudI~
        }                                                          //~vaudI~
        *pc3++;                                                    //~vaudI~
        if (udtype==UD_UTF8WC                                      //~vaudI~
        ||  udtype==UD_UTF8WCSUBC                                  //~vaudI~
        )                                                          //~vaudI~
        {                                                          //~vaudI~
            rc2=ufilecvutf2ucsW(0,pc2,len,pw,reslen,&ucsctr);      //~vaudI~
            if (rc2)                                               //~vaudI~
                break;                                             //~vaudI~
            pw+=ucsctr;                                            //~vaudI~
            reslen-=ctr2szW(ucsctr);                               //~vaudI~
        }                                                          //~vaudI~
        else                                                       //~v6u9R~
        if (udtype==UD_UTF8X)                                      //~v6u9R~
        {                                                          //~v6u9R~
			if ((lenx=ugethex(pc2,wkfpathx,len))<0)                //~v6u9R~
            	break;                                             //~v6u9R~
            rc2=ufilecvutf2ucsW(0,wkfpathx,lenx,pw,reslen,&ucsctr);//~v6u9R~
            if (rc2)                                               //~v6u9R~
                break;                                             //~v6u9R~
            pw+=ucsctr;                                            //~v6u9R~
            reslen-=ctr2szW(ucsctr);                               //~v6u9R~
        }                                                          //~v6u9R~
    }                                                              //~vaudI~
    *pw=0;                                                         //~vaudI~
    ucsctr=sz2ctrW(PTRDIFF(pw,PfnmW));                             //~vaudI~
    ufilewSetLongnamePrefix(Popt,PfnmW,ucsctr,Pbuffsz,&ucsctr);       //~v6H9I~//~v6HgR~
    if (Ppucsctr)                                                  //~vaudI~
        *Ppucsctr=ucsctr;                                          //~vaudI~
    if (rc2)                                                       //~vaudI~
    {                                                              //~vaudI~
      if (!(Popt & UFCVO_NOMSG))                                   //~v6J1R~
        uerrmsg("Invalid FileName Format(%s)",0,                   //~vaudI~
                Pfnm);                                             //~vaudI~
        rc=UDRC_FMTERR;                                            //~vaudI~
        SetLastError(ERROR_INVALID_NAME);                          //~vaudI~
    }                                                              //~vaudI~
    UTRACED("out ucs2",PfnmW,ctr2szW(ucsctr));                     //~vaudI~
//  PRINTUWCH("UD2WC:",PfnmW,"\n");                                //~vaudI~
    UTRACEP("%s rc=%d\n",UTT,rc);                                  //~vaudI~
    return rc;                                                     //~vaudI~
}//ufilecvUD2WCnopath                                              //~vaudI~
//**************************************************************** //~vaucI~
//*to LC from UD str containing utf8 with errrep '?'                               //~vaucI~//~v6u9R~
//*rc: udtype or FMTERR                                            //~vaucI~
//**************************************************************** //~vaucI~
int ufilecvUD2LC(int Popt,char *Pfnm,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~vaucI~
{                                                                  //~vaucI~
    UCHAR *pc,*pc2,*pc3,*pco;                                      //~vaucR~
    int len,outlen,rc=0,rc2=0,reslen,resleno,udtype,chklen,opt;    //~vaucR~
//************************                                         //~vaucI~
    UTRACED("inp",Pfnm,Plen);                                      //~vaucR~
    opt=UTFCVO_ERRREP|('?'/*XEUTF_ERRREPCH*/<<8);                  //~vaucI~
    for (pc=Pfnm,pco=Poutbuff,reslen=Plen,resleno=Pbuffsz-1;reslen;pc=pc3)//~vaucR~
    {                                                              //~vaucI~
        rc2=0;                                                     //~vaucI~
        pc2=memchr(pc,UD_NOTLC,reslen);                            //~vaucR~
        if (pc2)                                                   //~vaucI~
            len=PTRDIFF(pc2,pc);                                   //~vaucI~
        else                                                       //~vaucI~
            len=reslen;                                            //~vaucR~
        if (len)                                                   //~vaucI~
        {                                                          //~vaucI~
        	if (len>resleno)                                       //~vaucR~
            {                                                      //~vaucI~
	        	rc=UDRC_BUFFSHORTAGE;                              //~vaucI~
    	        break;                                             //~vaucI~
            }                                                      //~vaucI~
        	memcpy(pco,pc,len);                                    //~vaucI~
            pco+=len;                                              //~vaucI~
            resleno-=len;                                          //~vaucI~
        }                                                          //~vaucI~
        if (!pc2)   //no UD_NOTLC found                            //~vaucI~
            break;                                                 //~vaucI~
        pc2++;                                                     //~vaucI~
        udtype=*pc2++;                                             //~vaucI~
        rc|=udtype;                                                //~vaucI~
        reslen=Plen-PTRDIFF(pc2,Pfnm);                             //~vaucI~
        pc3=memchr(pc2,UD_NOTLC,reslen);                           //~vaucR~
        if (!pc3)                                                  //~vaucI~
        {                                                          //~vaucI~
        	rc2=4;	//fmt err                                      //~vaucI~
            break;                                                 //~vaucI~
        }                                                          //~vaucI~
        len=PTRDIFF(pc3,pc2);                                      //~vaucI~
        if (!len)                                                  //~vaucI~
        {                                                          //~vaucI~
        	rc2=4;	//fmt err                                      //~vaucI~
            break;                                                 //~vaucI~
        }                                                          //~vaucI~
        *pc3++;                                                    //~vaucI~
        if (udtype==UD_UTF8WC                                      //~vaucI~
        ||  udtype==UD_UTF8WCSUBC                                  //~vaucI~
        )                                                          //~vaucI~
        {                                                          //~vaucI~
			rc2=utfcvf2l(opt,pco,pc2,len,&chklen,&len,NULL/*Ppcharwidth*/);//~vaucR~
        	if (rc2==UTFCVRC_ERR)	//errrep                       //~vaucI~
                rc2=0;                                             //~vaucI~
            if (rc2) //overflow                                    //~vaucR~
                break;                                             //~vaucI~
            pco+=len;                                              //~vaucI~
            resleno-=len;                                          //~vaucR~
        }                                                          //~vaucI~
        else                                                       //~vaucI~
        {                                                          //~vaucI~
        	rc2=4;                                                 //~vaucI~
            break;                                                 //~vaucI~
        }                                                          //~vaucI~
        reslen=Plen-PTRDIFF(pc3,Pfnm);                             //~vaucI~
    }                                                              //~vaucI~
    *pco=0;                                                        //~vaucI~
    outlen=PTRDIFF(pco,Poutbuff);                                  //~vaucR~
    if (Ppoutlen)                                                  //~vaucI~
        *Ppoutlen=outlen;                                          //~vaucI~
    if (rc2)                                                       //~vaucI~
    {                                                              //~vaucI~
      if (!(Popt & UFCUD2LCO_NOMSG))                               //~v6EbI~
        uerrmsg("Invalid FileName Format(%s)",0,                   //~vaucI~
                Pfnm);                                             //~vaucI~
        rc=UDRC_FMTERR;                                            //~vaucI~
        SetLastError(ERROR_INVALID_NAME);                          //~vaucI~
    }                                                              //~vaucI~
    UTRACED("out ucs2",Poutbuff,outlen);                           //~vaucI~
    UTRACEP("%s rc=%d\n",UTT,rc);                                  //~vaucI~
    return rc;                                                     //~vaucI~
}//ufilecvUD2LC                                                    //~vaucI~
//**************************************************************** //~v6u9R~
//*to LC from UD with BEstFit                                      //~v6u9R~
//*rc: 4:err                                                       //~v6u9R~
//**************************************************************** //~v6u9R~
int ufilecvUD2LC_bestfit(int Popt,char *Pfnm,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~v6u9R~
{                                                                  //~v6u9R~
//	UWCH wkW[_MAX_PATHWC];                                         //~v6u9R~//~v6H9R~
  	UWCH wkW[_MAX_PATHWC_LONG];                                    //~v6H9I~
    int ucsctr,outlen,rc2,opt;                                     //~v6u9R~
//************************                                         //~v6u9R~
    UTRACED("inp",Pfnm,Plen);                                      //~v6u9R~
    rc2=ufilecvUD2WCnopath(0,Pfnm,wkW,sizeof(wkW),&ucsctr);        //~v6u9R~
	if (rc2>=UDRC_FMTERR)                                          //~v6u9R~
    	return 4;                                                  //~v6u9R~
	opt=UFCVO_BESTFIT|UFCVO_STRZ|UFCVO_SETSUBCHRC;//bestfit apply when subch was set//~v6u9R~
	rc2=ufilecvucs2cpW(opt,wkW,ucsctr,Poutbuff,Pbuffsz,&outlen);   //~v6u9R~
	if (rc2 && rc2!=UCVEXTRC_SUBCH)                                //~v6u9R~
    	return 4;                                                  //~v6u9R~
    if (Ppoutlen)                                                  //~v6u9R~
    	*Ppoutlen=outlen;                                          //~v6u9R~
    UTRACED("out lc",Poutbuff,outlen);                             //~v6u9R~
    return 0;                                                      //~v6u9R~
}//ufilecvUD2LC_bestfit                                            //~v6u9R~
//**************************************************************** //~v6uaI~
//* cut off 1 path level                                           //~v6uaI~
//* return path length contains last "\"                           //~v6uaR~
//* rc:4:cp2ucs err                                                //~v6uaI~
//**************************************************************** //~v6uaI~
int ufilecvgetpath1(int Popt,char *Pfnm,int Plen,UWCH *PfnmW,int Pbuffsz,int *Ppreadlen,int *Ppucsctr)//~v6uaR~
{                                                                  //~v6uaI~
    UCHAR *pc,*pc2,*pc3;                                           //~v6uaI~
    UWCH *pw;                                                      //~v6uaI~
    int len,ucsctr,rc,rc2=0,reslen,resleno;                        //~v6uaI~
//************************                                         //~v6uaI~
	for (pc=Pfnm,pw=PfnmW,reslen=Plen,resleno=Pbuffsz,pc3=pc+reslen;reslen && resleno;)//~v6uaI~
    {                                                              //~v6uaI~
    	pc2=umempbrk(pc,"\\/",reslen);                             //~v6uaI~
        if (pc2)                                                   //~v6uaI~
        	len=PTRDIFF(pc2,pc)+1;                                 //~v6uaI~
        else                                                       //~v6uaI~
        	len=reslen;                                            //~v6uaI~
        pc3=pc+len;                                                //~v6uaR~
        rc2=ufilecvcp2ucsW(Popt,pc,len,pw,resleno,&ucsctr);        //~v6uaR~
        if (rc2)                                                   //~v6uaI~
        	break;                                                 //~v6uaI~
        pw+=ucsctr;                                                //~v6uaI~
        if (!pc2 || *(pw-1)==DIR_SEPC)	//"\" is not dbcs 2nd      //~v6uaI~
        	break;                                                 //~v6uaM~
        if (*(pw-1)==FTP_DIR_SEPC)	//"/" is not dbcs 2nd          //~v6BaI~
        	break;                                                 //~v6BaI~
        resleno-=ctr2szW(ucsctr);                                  //~v6uaI~
        pc+=len;                                                   //~v6uaI~
        reslen-=len;                                               //~v6uaI~
    }                                                              //~v6uaI~
    *Ppreadlen=PTRDIFF(pc3,Pfnm);                                  //~v6uaI~
    *Ppucsctr=sz2ctrW(PTRDIFF(pw,PfnmW));                          //~v6uaI~
    if (rc2)                                                       //~v6uaI~
    	rc=4;                                                      //~v6uaI~
    else                                                           //~v6uaI~
    	rc=0;                                                      //~v6uaI~
    return rc;                                                     //~v6uaI~
}//ufilecvgetpath1                                                 //~v6uaI~
//**************************************************************** //~v6uaI~
//* try f2u                                                        //~v6uaI~
//* rc:0 setlect utf8,4:f2u err,UFCVO_ALLASCIIP                    //~v6uaR~
//**************************************************************** //~v6uaI~
int ufilecvf2upath1(int Popt,char *Pfnm,int Plen,UWCH *PfnmW,int Pbuffsz,int *Ppucsctr,int *Ppudtype)//~v6uaR~
{                                                                  //~v6uaI~
    int rc2,rcf,opt,ucsctr,charctr,udtype;                         //~v6uaR~
//  char wklc[_MAX_PATHWC];                                        //~v6uaR~//~v6H9R~
    char wklc[_MAX_PATHWC_LONG];                                   //~v6H9I~
//*****************************                                    //~v6uaI~
    UTRACED("inp",Pfnm,Plen);                                      //~v6uaI~
	if (Popt & UFCVO_RETALLASCIIP)    //set rc if all ascii        //~v6uaI~
    {                                                              //~v6uaI~
    	if (isPrintableASCIImem(Pfnm,Plen))                        //~v6uaI~
        	return UFCVO_RETALLASCIIP;                             //~v6uaI~
    }                                                              //~v6uaI~
    *Ppudtype=0;                                                   //~v6uaI~
    opt=0;                                                         //~v6uaI~
    rcf=ufilecvutf2ucsW(opt,Pfnm,Plen,PfnmW,Pbuffsz,&ucsctr);      //~v6uaR~
    if (rcf)                                                       //~v6uaI~
        return 4;   //use LC2WC                                    //~v6uaI~
    opt=UFCVO_SETSUBCHRC;   //rc if trans err                      //~v6uaI~
    rc2=ufilecvucs2cpW(opt,PfnmW,ucsctr,wklc,sizeof(wklc),&charctr);//~v6uaR~
    if (rc2==UCVEXTRC_SUBCH)                                       //~v6uaI~
        udtype=UD_UTF8WCSUBC;                                      //~v6uaI~
    else                                                           //~v6uaI~
    if (rc2)                                                       //~v6uaI~
        return 4;                                                  //~v6uaI~
    else                                                           //~v6uaI~
        udtype=UD_UTF8WC;                                          //~v6uaR~
    *Ppucsctr=ucsctr;                                              //~v6uaR~
    *Ppudtype=udtype;                                              //~v6uaI~
    return 0;                                                      //~v6uaI~
}//ufilecvf2upath1                                                 //~v6uaR~
//**************************************************************** //~v6uaI~
//*to UWCH from str containing utf8 with delm char                 //~v6uaI~
//rc:0:no utf8,0x02:contains utf8subch,0x01:optionally chked containing utf8ok,UDRC_FMTERR and set ERROR_INVALID_NAME//~v6uaI~
//**************************************************************** //~v6uaI~
int ufilecvUD2WC(int Popt,char *Pfnm,UWCH *PfnmW,int Pbuffsz,int *Ppucsctr,char *Ppathtbl,int Ppathtblsz,int *Pppathctr)//~v6uaI~
{                                                                  //~v6uaI~
    UCHAR *pc,*pc2,*pc3;                                           //~v6uaR~
    UWCH *pw;                                                      //~v6uaI~
    UWCH uwsepc,uwsepc4=DIR_SEPC;                                  //~v6BaR~
    int inplen,len,ucsctr,ucsctrlc=0,rc=0,rc2=0,reslen,pathctr=0,udtype,resleno,swff,chklen,opt;//~v6uaR~
//  UWCH wklcw[_MAX_PATHWC];                                       //~v6uaI~//~v6H9R~
//  UWCH wku8w[_MAX_PATHWC];                                       //~v6uaI~//~v6H9R~
    UWCH wklcw[_MAX_PATHWC_LONG];                                  //~v6H9I~
    UWCH wku8w[_MAX_PATHWC_LONG];                                  //~v6H9I~
//************************                                         //~v6uaI~
    UTRACED("inp",Pfnm,strlen(Pfnm));                              //~v6uaI~
	if (!(Popt & UFCVO_ENCAPATH))       //chk a path is fully enclosed by UD//~v6u9R~
    {                                                              //~v6u9R~
    	if (Pppathctr)                                             //~v6u9R~
	    	*Pppathctr=0;                                          //~v6u9R~
	    if (Ppathtbl)                                              //~v6u9R~
	    	*Ppathtbl=0;                                           //~v6u9R~
		return ufilecvUD2WCnopath(Popt,Pfnm,PfnmW,Pbuffsz,Ppucsctr);//~v6u9R~
    }                                                              //~v6u9R~
    inplen=strlen(Pfnm);                                           //~v6uaR~
    if (!Ppathtbl && inplen<Pbuffsz-(int)UWCHSZ && isPrintableASCIImem(Pfnm,inplen))//~v6uaR~
    {                                                              //~v6uaI~
    	umemcpyZ_ASCII2W(PfnmW,Pfnm,inplen);                       //~v6uaI~
        *Ppucsctr=inplen;                                          //~v6uaI~
        return 0;                                                  //~v6uaI~
    }                                                              //~v6uaI~
    ucsctr=0;   //for uninit warning                               //~v6uEI~
	for (pc=Pfnm,pw=PfnmW,reslen=inplen,resleno=Pbuffsz-UWCHSZ;reslen;pc=pc3)//~v6uaR~
    {                                                              //~v6uaI~
    	swff=0;                                                    //~v6uaI~
    	if (*pc==UD_NOTLC)                                         //~v6uaI~
        {                                                          //~v6uaI~
        	if (reslen<3)                                          //~v6uaI~
            	break;                                             //~v6uaI~
        	*pc++;                                                 //~v6uaR~
        	udtype=*pc++;                                          //~v6uaI~
            reslen-=2;                                             //~v6uaI~
            pc2=memchr(pc,UD_NOTLC,reslen);                        //~v6uaR~
            if (!pc2)                                              //~v6uaI~
            	break;                                             //~v6uaI~
            len=PTRDIFF(pc2,pc);                                   //~v6uaI~
        	if (udtype==UD_UTF8WC                                  //~v6uaI~
        	||  udtype==UD_UTF8WCSUBC)                             //~v6uaI~
            {                                                      //~v6uaI~
        		rc2=ufilecvutf2ucsW(0,pc,len,wku8w,sizeof(wku8w),&ucsctr);//~v6uaR~
            	if (rc2)                                           //~v6uaI~
					break;                                         //~v6uaI~
            }                                                      //~v6uaI~
            pc3=pc+len+1;                                          //~v6uaR~
            reslen-=len+1;                                         //~v6uaI~
            if (*pc3)                                              //~v6uaR~
            {                                                      //~v6uaI~
//          	if (*pc3!=DIR_SEPC)                                //~v6uaR~//~v6BaR~
            	if (*pc3!=DIR_SEPC                                 //~v6BaI~
            	&&  *pc3!=FTP_DIR_SEPC)                            //~v6BaI~
            		break;                                         //~v6uaR~
                uwsepc4=*pc3;                                      //~v6BaI~
            	pc3++;                                             //~v6uaR~
            	reslen--;                                          //~v6uaR~
                swff=4; //add dir_sepc                             //~v6uaI~
            }                                                      //~v6uaI~
        }                                                          //~v6uaI~
        else                                                       //~v6uaI~
        {                                                          //~v6uaI~
        	udtype=0;                                              //~v6uaI~
    		rc2=ufilecvgetpath1(0,pc,reslen,wklcw,sizeof(wklcw),&chklen,&ucsctrlc);//~v6uaI~
            swff=1;//use wklcw                                     //~v6uaI~
            if (rc2)                                               //~v6uaR~
            {                                                      //~v6uaI~
				opt=UFCVO_RETALLASCIIP;    //set rc if all ascii   //~v6uaI~
    			rc2=ufilecvf2upath1(opt,pc,chklen,wku8w,sizeof(wku8w),&ucsctr,&udtype);//~v6uaR~
                if (rc2)      //both err,if !rc2, udhtype!=0       //~v6uaR~
                	swff=2;//both err lc2ff                        //~v6uaR~
//                if (udtype && Popt & UFCVO_FNU8)                   //~v6uaI~//~vaucR~
//                    udtype=UD_UTF8FN;                              //~v6uaI~//~vaucR~
            }                                                      //~v6uaI~
#ifdef AAA //for parent path also,enclose by UD                    //~vaucI~
            else                                                   //~v6uaI~
            if (Popt & UFCVO_UTF8PRIMARY)  //no caller now                       //~v6uaI~//~vaucR~
            {                                                      //~v6uaI~
				opt=UFCVO_RETALLASCIIP;    //set rc if all ascii   //~v6uaI~
    			ufilecvf2upath1(opt,pc,chklen,wku8w,sizeof(wku8w),&ucsctr,&udtype);//select u8 if udtype was set//~v6uaR~
//                if (udtype && Popt & UFCVO_FNU8)                   //~v6uaI~//~vaucR~
//                    udtype=UD_UTF8FN;                              //~v6uaI~//~vaucR~
            }                                                      //~v6uaI~
#endif                                                             //~vaucI~
            len=chklen;                                            //~v6uaI~
            pc3=pc+len;                                            //~v6uaI~
            reslen-=len;                                           //~v6uaI~
        }                                                          //~v6uaI~
	    if (Ppathtbl)                                              //~v6uaR~
        {                                                          //~v6uaI~
//  		*(Ppathtbl+pathctr++)=udtype;                          //~v6uaR~//~v6y2R~
    		*(Ppathtbl+pathctr++)=(char)udtype;                    //~v6y2I~
        }                                                          //~v6uaI~
//        if (udtype==UD_UTF8WC||udtype==UD_UTF8WCSUBC||udtype==UD_UTF8FN)//~v6uaR~//~vaucR~
        if (udtype==UD_UTF8WC||udtype==UD_UTF8WCSUBC)              //~vaucI~
        {                                                          //~v6uaI~
            if (Popt & UFCVO_KEEPUD)                               //~v6uaI~
            {                                                      //~v6uaI~
            	if (resleno<3)                                     //~v6uaI~
                	break;                                         //~v6uaI~
                *pw++=UD_NOTLC;                                    //~v6uaR~
//              *pw++=udtype;                                      //~v6uaR~//~v6y2R~
                *pw++=(UWCH)udtype;                                //~v6y2I~
                resleno-=UWCHSZ*2;                                 //~v6uaR~
            }                                                      //~v6uaI~
//            if (udtype==UD_UTF8FN)                                 //~v6uaI~//~vaucR~
//            {                                                      //~v6uaI~//~vaucR~
//                if (resleno<ctr2szW(len))                          //~v6uaR~//~vaucR~
//                    break;                                         //~v6uaI~//~vaucR~
//                umemcpyZ_ASCII2W(pw,pc,len);                       //~v6uaR~//~vaucR~
//                pw+=len;                                           //~v6uaI~//~vaucR~
//                resleno-=ctr2szW(len);                             //~v6uaI~//~vaucR~
//            }                                                      //~v6uaI~//~vaucR~
//            else                                                   //~v6uaI~//~vaucR~
            {                                                      //~v6uaI~
                if (resleno<ctr2szW(ucsctr))                       //~v6uaI~
                    break;                                         //~v6uaI~
                len=ctr2szW(ucsctr);                               //~v6uaI~
                memcpy(pw,wku8w,len);                              //~v6uaR~
                pw+=ucsctr;                                        //~v6uaI~
                resleno-=len;                                      //~v6uaI~
            }                                                      //~v6uaI~
            if (Popt & UFCVO_KEEPUD)                               //~v6uaI~
            {                                                      //~v6uaI~
                if (!resleno)                                      //~v6uaI~
                    break;                                         //~v6uaI~
//              if (len && *(pw-1)==DIR_SEPC)                      //~v6uaI~//~v6BaR~
                if (len && (*(pw-1)==DIR_SEPC||*(pw-1)==FTP_DIR_SEPC))//~v6BaI~
                {                                                  //~v6uaI~
                	uwsepc=*(pw-1);                                //~v6BaI~
                	*(pw-1)=UD_NOTLC;                              //~v6uaI~
//              	*pw++=DIR_SEPC;                                //~v6uaI~//~v6BaR~
                	*pw++=uwsepc;                                  //~v6BaI~
                }                                                  //~v6uaI~
                else                                               //~v6uaI~
                	*pw++=UD_NOTLC;                                //~v6uaR~
                resleno-=UWCHSZ;                                   //~v6uaR~
            }                                                      //~v6uaI~
        	if (swff==4) //chked "\" after UD_NOTLC                //~v6uaI~
            {                                                      //~v6uaI~
            	if (!resleno)                                      //~v6uaI~
                	break;                                         //~v6uaI~
//              *pw++=DIR_SEPC;                                    //~v6uaI~//~v6BaR~
                *pw++=uwsepc4;                                     //~v6BaI~
                resleno-=UWCHSZ;                                   //~v6uaR~
            }                                                      //~v6uaI~
        }                                                          //~v6uaI~
        else  //udtype=0                                           //~v6uaR~
        {                                                          //~v6uaI~
        	if (swff==2) //both err                                //~v6uaR~
            {                                                      //~v6uaI~
            	if (resleno<len)                                   //~v6uaI~
                	break;                                         //~v6uaI~
		        umemcpyZ_ASCII2W(pw,pc,sz2ctrW(len));              //~v6uaR~
                pw+=len;                                           //~v6uaI~
                resleno-=ctr2szW(len);                             //~v6uaI~
            }                                                      //~v6uaI~
            else                                                   //~v6uaI~
        	if (swff==1)                                           //~v6uaI~
            {                                                      //~v6uaI~
                len=ctr2szW(ucsctrlc);                             //~v6uaI~
                if (resleno<len)                                   //~v6uaI~
                    break;                                         //~v6uaI~
                memcpy(pw,wklcw,len);                              //~v6uaI~
                pw+=ucsctrlc;                                      //~v6uaR~
                resleno-=len;                                      //~v6uaI~
            }                                                      //~v6uaI~
        }                                                          //~v6uaI~
    }//for                                                         //~v6uaI~
    if (Pppathctr)                                                 //~v6uaI~
	    *Pppathctr=pathctr;                                        //~v6uaR~
    *pw=0;                                                         //~v6uaI~
    ucsctr=sz2ctrW(PTRDIFF(pw,PfnmW));                             //~v6uaI~
    *Ppucsctr=ucsctr;                                              //~v6uaR~
    if (reslen)                                                    //~v6uaI~
    	rc|=UDRC_ERR;   //outbuff shortage                         //~v6uaI~
    UTRACED("out ucs2",PfnmW,ctr2szW(ucsctr));                     //~v6uaI~
//  PRINTUWCH("UD2WC:",PfnmW,"\n");                                //~v6uaI~
	UTRACEP("%s rc=%d,resleno=%d\n",UTT,rc,resleno);               //~v6uaR~
    return rc;                                                     //~v6uaI~
}//ufilecvUD2WC                                                    //~v6uaI~
//**************************************************************** //~v6uaI~
//*to UD from str containing utf8                                  //~v6uaI~
//**************************************************************** //~v6uaI~
int ufilecvU82UD(int Popt,char *Pfnm,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~v6uaR~
{                                                                  //~v6uaI~
    UCHAR *pc,*pc2,*pc3,*pco;                                      //~v6uaI~
    UCHAR dirsepc=DIR_SEPC;                                        //~v6BaI~
    int inplen,len,outlen,rc=0,reslen,udtype,resleno,chklen,ucsctrl,ucsctrf;//~v6uaR~
    int swerrL,swerrF,opt,swsepc;                                  //~v6uaR~
//  UWCH wklcw[_MAX_PATHWC];                                       //~v6uaI~//~v6H9R~
//  UWCH wku8w[_MAX_PATHWC];                                       //~v6uaI~//~v6H9R~
    UWCH wklcw[_MAX_PATHWC_LONG];                                  //~v6H9I~
    UWCH wku8w[_MAX_PATHWC_LONG];                                  //~v6H9I~
//************************                                         //~v6uaI~
    UTRACED("inp",Pfnm,strlen(Pfnm));                              //~v6uaI~
    inplen=strlen(Pfnm);                                           //~v6uaI~
    if (isPrintableASCIImem(Pfnm,inplen) && inplen<Pbuffsz-1)      //~v6uaI~
    {                                                              //~v6uaI~
    	memcpy(Poutbuff,Pfnm,inplen+1);                            //~v6uaI~
        *Ppoutlen=inplen;                                          //~v6uaI~
        return 0;                                                  //~v6uaI~
    }                                                              //~v6uaI~
	for (pc=Pfnm,pco=Poutbuff,reslen=inplen,resleno=Pbuffsz-1;reslen;pc=pc3,reslen=inplen-PTRDIFF(pc3,Pfnm))//~v6uaI~
    {                                                              //~v6uaI~
    	if (*pc==UD_NOTLC)                                         //~v6uaI~
        {                                                          //~v6uaI~
        	if (reslen<3)                                          //~v6uaI~
            	break;                                             //~v6uaI~
            pc2=memchr(pc+2,UD_NOTLC,reslen-2);                    //~v6uaI~
            if (!pc2)                                              //~v6uaI~
            	break;                                             //~v6uaI~
            len=PTRDIFF(pc2,pc)+1;                                 //~v6uaI~
            if (resleno<len)                                       //~v6uaI~
                break;                                             //~v6uaI~
            memcpy(pco,pc,len);                                    //~v6uaR~
            pco+=len;                                              //~v6uaI~
            pc3=pc+len;                                            //~v6uaM~
            if (!*pc3)                                             //~v6uaI~
            {                                                      //~v6uaI~
            	reslen=0;                                          //~v6uaI~
            	break;                                             //~v6uaI~
            }                                                      //~v6uaI~
//          if (*pc3!=DIR_SEPC)                                    //~v6uaI~//~v6BaR~
            if (*pc3!=DIR_SEPC                                     //~v6BaI~
            &&  *pc3!=FTP_DIR_SEPC)                                //~v6BaR~
                break;                                             //~v6uaI~
            if (!resleno)                                          //~v6uaI~
                break;                                             //~v6uaI~
            *pco++=*pc3++;                                         //~v6uaI~
            resleno--;                                             //~v6uaI~
            continue;                                              //~v6uaI~
        }                                                          //~v6uaI~
        udtype=0;                                                  //~v6uaI~
    	swerrL=ufilecvgetpath1(0,pc,reslen,wklcw,sizeof(wklcw),&chklen,&ucsctrl);//~v6uaI~
		opt=UFCVO_RETALLASCIIP;    //set rc if all ascii           //~v6uaI~
    	swerrF=ufilecvf2upath1(opt,pc,chklen,wku8w,sizeof(wku8w),&ucsctrf,&udtype);//~v6uaR~
//      swsepc=!swerrF && ucsctrf && *(wku8w+ucsctrf-1)==DIR_SEPC; //~v6uaR~//~v6BaR~
        swsepc=!swerrF && ucsctrf && (*(wku8w+ucsctrf-1)==DIR_SEPC||*(wku8w+ucsctrf-1)==FTP_DIR_SEPC);//~v6BaI~
        if (swsepc)                                                //~v6BaI~
        	dirsepc=(UCHAR)(*(wku8w+ucsctrf-1));                   //~v6BaR~
        len=chklen; //including last sepc                          //~v6uaI~
        pc3=pc+len;                                                //~v6uaI~
//select utf8 or locale                                            //~v6uaI~
        if (swerrF)   //fl2 err	                                   //~v6uaI~
            udtype=0;    //as locale code                          //~v6uaR~
        else                                                       //~v6uaI~
        {                                                          //~v6uaI~
            if (swerrL)          //f2l ok,l2f ng                   //~v6uaI~
                ;                //select f2l                      //~v6uaI~
            else                 //both ok                         //~v6uaI~
            {                                                      //~v6uaI~
#ifdef AAA //for parent path also,enclose by UD                    //~vaucI~
				if (Popt & UFCVO_UTF8PRIMARY)//no caller now                      //~v6uaR~//~vaucR~
                	;                                              //~v6uaI~
                else                                               //~v6uaI~
#endif                                                             //~vaucI~
                    udtype=0;                                      //~v6uaR~
            }                                                      //~v6uaI~
        }                                                          //~v6uaI~
        if (udtype)                                                //~v6uaI~
        {                                                          //~v6uaI~
//            if (Popt & UFCVO_FNU8)                                 //~v6uaI~//~vaucR~
//                udtype=UD_UTF8FN;                                  //~v6uaR~//~vaucR~
            if (resleno<3)                                         //~v6uaI~
            	break;                                             //~v6uaI~
//          *pco++=UD_NOTLC;                                       //~v6uaI~//~v6y2R~
            *pco++=(UCHAR)UD_NOTLC;                                //~v6y2I~
//          *pco++=udtype;                                         //~v6uaI~//~v6y2R~
            *pco++=(UCHAR)udtype;                                  //~v6y2I~
            resleno-=2;                                            //~v6uaI~
        }                                                          //~v6uaI~
        if (resleno<len)                                           //~v6uaI~
        	break;                                                 //~v6uaI~
        memcpy(pco,pc,len);                                        //~v6uaI~
        pco+=len;                                                  //~v6uaI~
        resleno-=len;                                              //~v6uaI~
        if (udtype)                                                //~v6uaI~
        {                                                          //~v6uaI~
        	if (!resleno)                                          //~v6uaI~
            	break;                                             //~v6uaI~
            if (swsepc)	                                           //~v6uaI~
            {                                                      //~v6uaI~
            	*(pco-1)=UD_NOTLC;                                 //~v6uaI~
//              *pco++=DIR_SEPC;                                   //~v6uaI~//~v6BaR~
                *pco++=dirsepc;                                    //~v6BaI~
            }                                                      //~v6uaI~
            else                                                   //~v6uaI~
            	*pco++=UD_NOTLC;                                   //~v6uaR~
            resleno--;                                             //~v6uaI~
        }                                                          //~v6uaI~
        if (!*pc3)                                                 //~v6uaI~
        	reslen=0;                                              //~v6uaI~
    }//for                                                         //~v6uaI~
    *pco=0;                                                        //~v6uaI~
    outlen=PTRDIFF(pco,Poutbuff);                                  //~v6uaI~
    *Ppoutlen=outlen;                                              //~v6uaI~
    if (reslen)                                                    //~v6uaI~
    	rc|=UDRC_ERR;   //outbuff shortage                         //~v6uaI~
    UTRACED("out ud",Poutbuff,outlen);                             //~v6uaI~
	UTRACEP("%s rc=%d,resleno=%d\n",UTT,rc,resleno);               //~v6uaI~
    return rc;                                                     //~v6uaI~
}//ufilecvU82UD                                                    //~v6uaI~//~v6uKR~
#ifndef AAA  //keep dbcs for f8f1 at uwindechartomultibyte         //~v6E2R~
//**************************************************************** //~v6u9R~
//*to UD from utf8 and ct for f2l err parts only                   //~v6u9R~
//*rc:0 no change,1:UD inserted,4:err                              //~v6u9R~
//*rc:8 logical err                                                //~v6B0I~
//**************************************************************** //~v6u9R~
int ufilecvU8CT2UD(int Popt,char *Pfnm,char *Pct,int Pctlen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~v6u9R~
{                                                                  //~v6u9R~
    UCHAR *pc,*pct,*pct2,*pco;                                     //~v6u9R~
    int outlen,rc2,reslenct,rc=0,resleno,chklen,swud,opt,lenct,lenu8,lenlc;//~v6u9R~
    char wklc[8];                                                  //~v6u9R~
//************************                                         //~v6u9R~
    UTRACED("inp",Pfnm,strlen(Pfnm));                              //~v6u9R~
    opt=UTFCVO_ERRREP|('?'/*XEUTF_ERRREPCH*/<<8);	//f2l opt      //~v6u9R~
    if (Popt & UFCVO_ERRREPDBCS)                                   //~v6T4M~
        opt|=UTFCVO_ERRREPDBCS;                                    //~v6T4M~
    swud=0;                                                        //~v6u9R~
	for (pc=Pfnm,pct=Pct,pco=Poutbuff,reslenct=Pctlen,resleno=Pbuffsz-1;resleno;)//~v6u9R~
    {                                                              //~v6u9R~
		USUBSTRLEN(pct,UTFCT_UTF8,reslenct,&pct2,&lenct);          //~v6u9R~
        if (lenct)                                                 //~v6u9R~
        {                                                          //~v6u9R~
        	if (swud)                                              //~v6u9R~
            {                                                      //~v6u9R~
            	swud=0;                                            //~v6u9R~
            	*pco++=UD_NOTLC;                                   //~v6u9R~
                resleno--;                                         //~v6u9R~
            }                                                      //~v6u9R~
            if (resleno<lenct)                                     //~v6u9R~
                break;                                             //~v6u9R~
            memcpy(pco,pc,lenct);                                  //~v6u9R~
            pc+=lenct;                                             //~v6u9R~
            pct+=lenct;                                            //~v6u9R~
            reslenct-=lenct;                                       //~v6u9R~
            pco+=lenct;                                            //~v6u9R~
            resleno-=lenct;                                        //~v6u9R~
        }                                                          //~v6u9R~
        if (!pct2)                                                 //~v6u9R~
        	break;                                                 //~v6u9R~
        lenu8=UTF8CHARLEN(*pc);                                    //~v6u9R~
        if (!lenu8)       //not utf8 code after reached to UTFCT_UTF8//~v6B0I~
        {                                                          //~v6B0I~
        	rc=8;                                                  //~v6B0I~
        	break;    //codetbl indicate u8 but no utf8 data       //~v6B0I~
        }                                                          //~v6B0I~
		rc2=utfcvf2l(opt,wklc,pc,lenu8,&chklen,&lenlc,NULL/*Ppcharwidth*/);//~v6u9R~
      if (Popt & UFCVO_ENCUTF8WC)       //enclose f2l err only     //~v6u9R~
      {                                                            //~v6u9R~
        	if (!swud)                                             //~v6u9R~
            {                                                      //~v6u9R~
            	if (resleno<3)                                     //~v6u9R~
                	break;                                         //~v6u9R~
                swud=1;                                            //~v6u9R~
                rc=1;                                              //~v6u9R~
                *pco++=UD_NOTLC;                                   //~v6u9R~
                *pco++=UD_UTF8WC;                                  //~v6u9R~
                resleno-=2;                                        //~v6u9R~
            }                                                      //~v6u9R~
      }                                                            //~v6u9R~
      else	//SUBC only                                            //~v6u9R~
      {                                                            //~v6u9R~
        if (rc2==UTFCVRC_ERR)	//errrep                           //~v6u9R~
        {                                                          //~v6u9R~
        	if (!swud)                                             //~v6u9R~
            {                                                      //~v6u9R~
            	if (resleno<3)                                     //~v6u9R~
                	break;                                         //~v6u9R~
                swud=1;                                            //~v6u9R~
                rc=1;                                              //~v6u9R~
                *pco++=UD_NOTLC;                                   //~v6u9R~
                *pco++=UD_UTF8WCSUBC;                              //~v6u9R~
                resleno-=2;                                        //~v6u9R~
            }                                                      //~v6u9R~
        }                                                          //~v6u9R~
      }                                                            //~v6u9R~
        if (resleno<lenu8)                                         //~v6u9R~
        	break;                                                 //~v6u9R~
        memcpy(pco,pc,lenu8);                                      //~v6u9R~
        pc+=lenu8;                                                 //~v6u9R~
        pco+=lenu8;                                                //~v6u9R~
        resleno-=lenu8;                                            //~v6u9R~
        pct+=lenlc;                                                //~v6u9R~
        reslenct-=lenlc;                                           //~v6u9R~
    }                                                              //~v6u9R~
    if (swud && resleno)                                           //~v6u9R~
    	*pco++=UD_NOTLC,resleno--;                                 //~v6u9R~
    if (resleno)                                                   //~v6u9R~
	    *pco=0;                                                    //~v6u9R~
    else                                                           //~v6u9R~
    	rc=4;                                                      //~v6u9R~
    outlen=PTRDIFF(pco,Poutbuff);                                  //~v6u9R~
    if (Ppoutlen)                                                  //~v6u9R~
	    *Ppoutlen=outlen;                                          //~v6u9R~
    if (reslenct)                                                  //~v6u9R~
    	rc=4;   //outbuff shortage                                 //~v6u9R~
    UTRACED("out ud",Poutbuff,outlen);                             //~v6u9R~
	UTRACEP("%s rc=%d,resleno=%d\n",UTT,rc,resleno);               //~v6u9R~
    return rc;                                                     //~v6u9R~
}//ufilecvU8CT2UD                                                  //~v6u9R~
#else //AAA                                                        //~v6E2I~
//**************************************************************** //~v6u9R~//~v6E2I~
//*to UD from utf8 and ct for f2l err parts only                   //~v6u9R~//~v6E2I~
//*!!no use ct now                                                 //~v6E2I~
//*rc:0 no change,1:UD inserted,4:err                              //~v6u9R~//~v6E2I~
//*rc:8 logical err                                                //~v6B0I~//~v6E2I~
//**************************************************************** //~v6u9R~//~v6E2I~
int ufilecvU8CT2UD(int Popt,char *Pfnm,char *Pct,int Pctlen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~v6u9R~//~v6E2I~
{                                                                  //~v6u9R~//~v6E2I~
    UCHAR *pc,/* *pct,*/*pct2,*pco;                                     //~v6u9R~//~v6E2R~
    int outlen,rc2,reslenct,rc=0,resleno,chklen,swud,opt,lenct,lenu8,lenlc;//~v6u9R~//~v6E2I~
    char wklc[8];                                                  //~v6u9R~//~v6E2I~
//************************                                         //~v6u9R~//~v6E2I~
    UTRACED("inp",Pfnm,strlen(Pfnm));                              //~v6u9R~//~v6E2I~
    opt=UTFCVO_ERRREP|('?'/*XEUTF_ERRREPCH*/<<8);	//f2l opt      //~v6u9R~//~v6E2I~
    lenu8=(int)ustrnlen(Pfnm,Pctlen);                              //~v6E2I~
    swud=0;                                                        //~v6u9R~//~v6E2I~
//  for (pc=Pfnm,pct=Pct,pco=Poutbuff,reslenct=Pctlen,resleno=Pbuffsz-1;resleno;)//~v6u9R~//~v6E2I~
    for (pc=Pfnm,pco=Poutbuff,reslenct=lenu8,resleno=Pbuffsz-1;resleno;)//~v6E2I~
    {                                                              //~v6u9R~//~v6E2I~
//  	USUBSTRLEN(pct,UTFCT_UTF8,reslenct,&pct2,&lenct);          //~v6u9R~//~v6E2I~
    	ASCIISTRLEN(pc,reslenct,&pct2,&lenct);                     //~v6E2I~
        if (lenct==reslenct)                                       //~v6E2I~
            pct2=0;                                                //~v6E2I~
        if (lenct)                                                 //~v6u9R~//~v6E2I~
        {                                                          //~v6u9R~//~v6E2I~
        	if (swud)                                              //~v6u9R~//~v6E2I~
            {                                                      //~v6u9R~//~v6E2I~
            	swud=0;                                            //~v6u9R~//~v6E2I~
            	*pco++=UD_NOTLC;                                   //~v6u9R~//~v6E2I~
                resleno--;                                         //~v6u9R~//~v6E2I~
            }                                                      //~v6u9R~//~v6E2I~
            if (resleno<lenct)                                     //~v6u9R~//~v6E2I~
                break;                                             //~v6u9R~//~v6E2I~
            memcpy(pco,pc,lenct);                                  //~v6u9R~//~v6E2I~
            pc+=lenct;                                             //~v6u9R~//~v6E2I~
//          pct+=lenct;                                            //~v6u9R~//~v6E2I~
            reslenct-=lenct;                                       //~v6u9R~//~v6E2I~
            pco+=lenct;                                            //~v6u9R~//~v6E2I~
            resleno-=lenct;                                        //~v6u9R~//~v6E2I~
        }                                                          //~v6u9R~//~v6E2I~
        if (!pct2)                                                 //~v6u9R~//~v6E2I~
        	break;                                                 //~v6u9R~//~v6E2I~
        lenu8=UTF8CHARLEN(*pc);                                    //~v6u9R~//~v6E2I~
        if (!lenu8)       //not utf8 code after reached to UTFCT_UTF8//~v6B0I~//~v6E2I~
        {                                                          //~v6B0I~//~v6E2I~
        	rc=8;                                                  //~v6B0I~//~v6E2I~
        	break;    //codetbl indicate u8 but no utf8 data       //~v6B0I~//~v6E2I~
        }                                                          //~v6B0I~//~v6E2I~
		rc2=utfcvf2l(opt,wklc,pc,lenu8,&chklen,&lenlc,NULL/*Ppcharwidth*/);//~v6u9R~//~v6E2I~
      if (Popt & UFCVO_ENCUTF8WC)       //enclose f2l err only     //~v6u9R~//~v6E2I~
      {                                                            //~v6u9R~//~v6E2I~
        	if (!swud)                                             //~v6u9R~//~v6E2I~
            {                                                      //~v6u9R~//~v6E2I~
            	if (resleno<3)                                     //~v6u9R~//~v6E2I~
                	break;                                         //~v6u9R~//~v6E2I~
                swud=1;                                            //~v6u9R~//~v6E2I~
                rc=1;                                              //~v6u9R~//~v6E2I~
                *pco++=UD_NOTLC;                                   //~v6u9R~//~v6E2I~
                *pco++=UD_UTF8WC;                                  //~v6u9R~//~v6E2I~
                resleno-=2;                                        //~v6u9R~//~v6E2I~
            }                                                      //~v6u9R~//~v6E2I~
      }                                                            //~v6u9R~//~v6E2I~
      else	//SUBC only                                            //~v6u9R~//~v6E2I~
      {                                                            //~v6u9R~//~v6E2I~
        if (rc2==UTFCVRC_ERR)	//errrep                           //~v6u9R~//~v6E2I~
        {                                                          //~v6u9R~//~v6E2I~
        	if (!swud)                                             //~v6u9R~//~v6E2I~
            {                                                      //~v6u9R~//~v6E2I~
            	if (resleno<3)                                     //~v6u9R~//~v6E2I~
                	break;                                         //~v6u9R~//~v6E2I~
                swud=1;                                            //~v6u9R~//~v6E2I~
                rc=1;                                              //~v6u9R~//~v6E2I~
                *pco++=UD_NOTLC;                                   //~v6u9R~//~v6E2I~
                *pco++=UD_UTF8WCSUBC;                              //~v6u9R~//~v6E2I~
                resleno-=2;                                        //~v6u9R~//~v6E2I~
            }                                                      //~v6u9R~//~v6E2I~
        }                                                          //~v6u9R~//~v6E2I~
      }                                                            //~v6u9R~//~v6E2I~
        if (resleno<lenu8)                                         //~v6u9R~//~v6E2I~
        	break;                                                 //~v6u9R~//~v6E2I~
        memcpy(pco,pc,lenu8);                                      //~v6u9R~//~v6E2I~
        pc+=lenu8;                                                 //~v6u9R~//~v6E2I~
        pco+=lenu8;                                                //~v6u9R~//~v6E2I~
        resleno-=lenu8;                                            //~v6u9R~//~v6E2I~
//      pct+=lenlc;                                                //~v6u9R~//~v6E2I~
        reslenct-=lenlc;                                           //~v6u9R~//~v6E2I~
    }                                                              //~v6u9R~//~v6E2I~
    if (swud && resleno)                                           //~v6u9R~//~v6E2I~
    	*pco++=UD_NOTLC,resleno--;                                 //~v6u9R~//~v6E2I~
    if (resleno)                                                   //~v6u9R~//~v6E2I~
	    *pco=0;                                                    //~v6u9R~//~v6E2I~
    else                                                           //~v6u9R~//~v6E2I~
    	rc=4;                                                      //~v6u9R~//~v6E2I~
    outlen=PTRDIFF(pco,Poutbuff);                                  //~v6u9R~//~v6E2I~
    if (Ppoutlen)                                                  //~v6u9R~//~v6E2I~
	    *Ppoutlen=outlen;                                          //~v6u9R~//~v6E2I~
    if (reslenct)                                                  //~v6u9R~//~v6E2I~
    	rc=4;   //outbuff shortage                                 //~v6u9R~//~v6E2I~
    UTRACED("out ud",Poutbuff,outlen);                             //~v6u9R~//~v6E2I~
	UTRACEP("%s rc=%d,resleno=%d\n",UTT,rc,resleno);               //~v6u9R~//~v6E2I~
    return rc;                                                     //~v6u9R~//~v6E2I~
}//ufilecvU8CT2UD                                                  //~v6u9R~//~v6E2I~
#endif  //AAA                                                      //~v6E2I~
//**************************************************************** //~v6uKI~
//*to UD from utf8 and ct for f2l err parts only                   //~v6uKI~
//*rc:0 no change,1:UD inserted,4:err                              //~v6uKI~
//**************************************************************** //~v6uKI~
int ufilecvU82UDnopath(int Popt,char *Pfnm,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~v6uKI~
{                                                                  //~v6uKI~
    UCHAR *pc,*pco;                                                //~v6uKR~
    int outlen,rc2,reslen,rc=0,resleno,chklen,swud,opt,lenu8,lenlc,swcv2lc;//~v6uKR~
    char wklc[8];                                                  //~v6uKI~
//************************                                         //~v6uKI~
    UTRACED("inp",Pfnm,strlen(Pfnm));                              //~v6uKI~
    opt=UTFCVO_ERRREP|('?'/*XEUTF_ERRREPCH*/<<8);	//f2l opt      //~v6uKI~
    swud=0;                                                        //~v6uKI~
	for (pc=Pfnm,pco=Poutbuff,reslen=Plen,resleno=Pbuffsz-1;resleno && reslen;)//~v6uKR~
    {                                                              //~v6uKI~
		if (UTF8ISASCII(*pc))                                      //~v6uKR~
        {                                                          //~v6uKI~
        	if (swud)                                              //~v6uKI~
            {                                                      //~v6uKI~
            	swud=0;                                            //~v6uKI~
            	*pco++=UD_NOTLC;                                   //~v6uKI~
                resleno--;                                         //~v6uKI~
            }                                                      //~v6uKI~
            *pco++=*pc++;                                          //~v6uKI~
            resleno--;                                             //~v6uKI~
            reslen--;                                              //~v6uKI~
            continue;                                              //~v6uKI~
        }                                                          //~v6uKI~
        swcv2lc=0;                                                 //~v6uKI~
        lenu8=UTF8CHARLEN(*pc);                                    //~v6uKI~
		rc2=utfcvf2l(opt,wklc,pc,lenu8,&chklen,&lenlc,NULL/*Ppcharwidth*/);//~v6uKI~
      if (Popt & UFCVO_ENCUTF8WC)       //enclose not f2l err only //~v6uKI~
      {                                                            //~v6uKI~
        	if (!swud)                                             //~v6uKI~
            {                                                      //~v6uKI~
            	if (resleno<3)                                     //~v6uKI~
                	break;                                         //~v6uKI~
                swud=1;                                            //~v6uKI~
                rc=1;                                              //~v6uKI~
                *pco++=UD_NOTLC;                                   //~v6uKI~
                *pco++=UD_UTF8WC;                                  //~v6uKI~
                resleno-=2;                                        //~v6uKI~
            }                                                      //~v6uKI~
      }                                                            //~v6uKI~
      else	//SUBC only                                            //~v6uKI~
      {                                                            //~v6uKI~
        if (rc2==UTFCVRC_ERR)	//errrep                           //~v6uKI~
        {                                                          //~v6uKI~
        	if (!swud)                                             //~v6uKI~
            {                                                      //~v6uKI~
            	if (resleno<3)                                     //~v6uKI~
                	break;                                         //~v6uKI~
                swud=1;                                            //~v6uKI~
                rc=1;                                              //~v6uKI~
                *pco++=UD_NOTLC;                                   //~v6uKI~
                *pco++=UD_UTF8WCSUBC;                              //~v6uKI~
                resleno-=2;                                        //~v6uKI~
            }                                                      //~v6uKI~
        }                                                          //~v6uKI~
        else                                                       //~v6uKI~
      	if (Popt & UFCVO_FNLC)       //cv to lc                    //~v6uKI~
        {                                                          //~v6uKI~
        	swcv2lc=1;                                             //~v6uKI~
        }                                                          //~v6uKI~
      }                                                            //~v6uKI~
      if (swcv2lc)                                                 //~v6uKI~
      {                                                            //~v6uKI~
       	if (swud)                                                  //~v6EhI~
       	{                                                          //~v6EhI~
        	if (resleno<1)                                         //~v6EhI~
        		break;                                             //~v6EhI~
            swud=0;                                                //~v6EhI~
            *pco++=UD_NOTLC;                                       //~v6EhI~
            resleno--;                                             //~v6EhI~
       	}                                                          //~v6EhI~
        if (resleno<lenlc)                                         //~v6uKI~
        	break;                                                 //~v6uKI~
        memcpy(pco,wklc,lenlc);                                    //~v6uKI~
        pco+=lenlc;                                                //~v6uKI~
        resleno-=lenlc;                                            //~v6uKI~
      }                                                            //~v6uKI~
      else                                                         //~v6uKI~
      {                                                            //~v6uKI~
        if (resleno<lenu8)                                         //~v6uKI~
        	break;                                                 //~v6uKI~
        memcpy(pco,pc,lenu8);                                      //~v6uKI~
        pco+=lenu8;                                                //~v6uKI~
        resleno-=lenu8;                                            //~v6uKI~
      }                                                            //~v6uKI~
        pc+=lenu8;                                                 //~v6uKM~
        reslen-=lenu8;                                             //~v6uKI~
    }                                                              //~v6uKI~
    if (swud && resleno)                                           //~v6uKI~
    	*pco++=UD_NOTLC,resleno--;                                 //~v6uKI~
    if (resleno)                                                   //~v6uKI~
	    *pco=0;                                                    //~v6uKI~
    else                                                           //~v6uKI~
    	rc=4;                                                      //~v6uKI~
    outlen=PTRDIFF(pco,Poutbuff);                                  //~v6uKI~
    if (Ppoutlen)                                                  //~v6uKI~
	    *Ppoutlen=outlen;                                          //~v6uKI~
    UTRACED("out ud",Poutbuff,outlen);                             //~v6uKI~
	UTRACEP("%s rc=%d,resleno=%d\n",UTT,rc,resleno);               //~v6uKI~
    return rc;                                                     //~v6uKI~
}//ufilecvU82UDnopath                                              //~v6uKI~
//**************************************************************** //~v6uaI~
//*strip delm from DDfmt of UD fmt                                  //~v6uaR~//~v6u9R~
//*Puct is optional                                                //~vaucR~
//rc:0:utf8,1:contains UTF8SUBC,4 buff overflow                    //~v6uaI~
//**************************************************************** //~vav0I~//~v6uaI~
int ufilecvUDD2DD(int Popt,char *Puddata,char *Puddbcs,char *Pudct,int Pudlen,char *Pdddata,char *Pdddbcs,char *Pddct,int Pbuffsz,int *Ppddlen)//~v6uaR~
{                                                                  //~vav0I~//~v6uaI~
    int reslen,resleno,rc=0,len,ddlen;                             //~v6uaR~
    char *pc,*pc2,*pc3,*pcd,*pco,*pcdo,*pct,*pcto;                 //~v6uaR~
//*****************                                                //~vav0I~//~v6uaI~
    UTRACED("inp dddata",Puddata,Pudlen);                          //~v6uaI~
    UTRACED("inp dddbcs",Puddbcs,Pudlen);                          //~v6uaI~
    UTRACED("inp ct",Pudct,Pudlen);                                //~v6uaI~
	for (pc=Puddata,pcd=Puddbcs,reslen=Pudlen,pco=Pdddata,pcdo=Pdddbcs,pct=Pudct,pcto=Pddct,resleno=Pbuffsz;//~v6uaR~
			reslen;)                                               //~v6uaI~
    {                                                              //~v6uaI~
//  	pc2=memchr(pc,UD_NOTLC,reslen);                            //~vaugR~
		pc2=utfddmemchr(0,pc,pcd,UD_NOTLC,reslen);                 //~vaugI~
        if (pc2)                                                   //~v6uaI~
	        len=PTRDIFF(pc2,pc);                                   //~v6uaI~
        else                                                       //~v6uaI~
        	len=reslen;                                            //~v6uaI~
        if (resleno<len)                                           //~v6uaI~
            break;                                                 //~v6uaI~
        memcpy(pco,pc,len);                                        //~v6uaI~
        memcpy(pcdo,pcd,len);                                      //~v6uaI~
      if (Pudct)                                                   //~vaucR~
        memcpy(pcto,pct,len);                                      //~v6uaI~
        pco+=len;                                                  //~v6uaM~
        pcdo+=len;                                                 //~v6uaM~
        pcto+=len;                                                 //~v6uaI~
        resleno-=len;                                              //~v6uaM~
        pc+=len;                                                   //~v6uaM~
        pcd+=len;                                                  //~v6uaM~
        pct+=len;                                                  //~v6uaI~
        reslen-=len;                                               //~v6uaM~
        if (!pc2)                                                  //~v6uaI~
        	break;                                                 //~v6uaI~
//        if (!*pcd && reslen>=3                                   //~vaugR~
//        &&  (*(pc+1)==UD_UTF8WCSUBC || *(pc+1)==UD_UTF8WC) && !*(pcd+1)//~vaugR~
//        &&  (pc3=memchr(pc+2,UD_NOTLC,reslen-2),pc3)             //~vaugR~
//        &&  (len=PTRDIFF(pc3,pc),len>0)                          //~vaugR~
//        &&  !*(pcd+len)                                          //~vaugR~
//        )                                                        //~vaugR~
        if (reslen>=3                                              //~vaugI~
        &&  (*(pc+1)==UD_UTF8WCSUBC || *(pc+1)==UD_UTF8WC) && !*(pcd+1)//~vaugI~
        &&  (pc3=utfddmemchr(0,pc+2,pcd+2,UD_NOTLC,reslen-2),pc3)  //~vaugR~
        &&  (len=PTRDIFF(pc3,pc),len>0)                            //~vaugI~
        )                                                          //~vaugI~
        {                                                          //~v6uaI~
        	if (resleno<len-2)                                     //~v6uaI~
            	break;                                             //~v6uaI~
            rc=1;                                                  //~v6uaI~
        	memcpy(pco,pc2+2,len-2);                               //~v6uaI~
        	memcpy(pcdo,pcd+2,len-2);                              //~v6uaI~
         if (Pudct)                                                //~vaucR~
        	memcpy(pcto,pct+2,len-2);                              //~v6uaI~
            reslen-=len;                                           //~v6uaI~
            pc+=len+1;                                             //~v6uaR~
            pcd+=len+1;                                            //~v6uaR~
            pct+=len+1;                                            //~v6uaI~
            reslen--;                                              //~v6uaI~
            resleno-=len-2;                                        //~v6uaI~
            pco+=len-2;                                            //~v6uaI~
            pcdo+=len-2;                                           //~v6uaI~
            pcto+=len-2;                                           //~v6uaI~
        }                                                          //~v6uaI~
        else                                                       //~v6uaI~
        {                                                          //~v6uaI~
        	*pco++=*pc++;                                          //~v6uaR~
        	*pcdo++=*pcd++;                                        //~v6uaR~
         if (Pudct)                                                //~vaucR~
        	*pcto++=*pct++;                                        //~v6uaI~
        	reslen--;                                              //~v6uaR~
        	resleno--;                                             //~v6uaR~
        }                                                          //~v6uaI~
    }                                                              //~v6uaI~
    ddlen=PTRDIFF(pco,Pdddata);                                    //~v6uaI~
    *Ppddlen=ddlen;                                                //~v6uaI~
    if (reslen>0)                                                  //~v6uaI~
    	rc=4;                                                      //~v6uaR~
    UTRACED("out dddata",Pdddata,ddlen);                           //~v6uaI~
    UTRACED("out dddbcs",Pdddbcs,ddlen);                           //~v6uaI~
    UTRACED("out ct",Pddct,ddlen);                                 //~v6uaI~
    UTRACEP("%s:reslen=%d,resleno=%d,rc=%d\n",UTT,reslen,resleno,rc);                            //~vav0I~//~v6uaR~
    return rc;                                                     //~vav0I~//~v6uaI~
}//ufilecvUDD2DD                                                   //~v6uaR~
//#ifdef AAA                                                       //~vaugR~
////**************************************************************** //~vav0I~//~vaugR~
////enclose DD string to UD string                                   //~vav0R~//~vaugR~
////4:buff overflow,0:no utf8 data,1:utf8 data detected            //~vaugR~
////**************************************************************** //~vav0I~//~vaugR~
//int ufilecvDDCT2UD(int Popt,char *Pdddata,char *Pdddbcs,char *Pddct,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen)//~vav0R~//~vaugR~
//{                                                                  //~vav0I~//~vaugR~
//    int swenclose,opt=0,rc,rc2,wrtlen,len,reslen,resleno,outlen;//~vav0R~//~vaugR~
//    char *pc,*pco,*pcd,*pct,*pcsep;                 //~vav0R~    //~vaugR~
////*****************                                                //~vav0I~//~vaugR~
//    UTRACED("inp dddata",Pdddata,Plen);                                    //~vav0R~//~vaugR~
//    UTRACED("inp dddbcs",Pdddbcs,Plen);                          //~vaugR~
//    UTRACED("inp ddct",Pddct,Plen);                              //~vaugR~
//    if (memchr(Pddct,UTFCT_UTF8,Plen))  //no utf8 code           //~vaugR~
//    {                                                              //~vav0I~//~vaugR~
//        outlen=min(Plen,Pbuffsz-1);                              //~vav0I~//~vaugR~
//        rc2=utfcvdd2f(opt,Pdddata,Plen,Pdddbcs,Poutbuff,outlen,&wrtlen,NULL);//~vaugR~
//        *Ppoutlen=wrtlen;                                          //~vav0I~//~vaugR~
//        if (rc2 & UTFDD2FRC_BUFFOVERFLOW)                        //~vaugR~
//            return 4;                                            //~vaugR~
//        return 0;                                                  //~vav0I~//~vaugR~
//    }                                                              //~vav0I~//~vaugR~
//    for (pc=Pdddata,pcd=Pdddbcs,pct=Pddct,pco=Poutbuff,reslen=Plen,resleno=Pbuffsz-1;;)//~vaugR~
//    {                                                            //~vaugR~
//        pcsep=utfmemrchrDD(pc,pcd,reslen,DIR_SEPC);              //~vaugR~
//        if (pcsep)                                               //~vaugR~
//            len=PTRDIFF(pcsep,pc);                               //~vaugR~
//        else                                                     //~vaugR~
//            len=reslen;                                          //~vaugR~
//        swenclose=!(*pc==UD_NOTLC && !*pcd) //already UD fmt     //~vaugR~
//               &&  memchr(pct,UTFCT_UTF8,reslen); //contains utf8 code//~vaugR~
//        if (swenclose)                                           //~vaugR~
//        {                                                        //~vaugR~
//            if (resleno<3)                                       //~vaugR~
//                break;                                           //~vaugR~
//            *pco++=UD_NOTLC;                                     //~vaugR~
//            *pco+=UD_UTF8WC;                                     //~vaugR~
//                                                                 //~vaugR~
//        }                                                        //~vaugR~
//        rc2=utfcvdd2f(opt,pc,len,pcd,pco,resleno,&wrtlen,NULL);  //~vaugR~
//        if (rc2 & UTFDD2FRC_BUFFOVERFLOW)                        //~vaugR~
//            break;                                               //~vaugR~
//        pco+=wrtlen;                                             //~vaugR~
//        resleno-=wrtlen;                                         //~vaugR~
//        pc+=len;                                                 //~vaugR~
//        pcd+=len;                                                //~vaugR~
//        pct+=len;                                                //~vaugR~
//        reslen-=len;                                             //~vaugR~
//        if (swenclose)                                           //~vaugR~
//        {                                                        //~vaugR~
//            if (!resleno)                                        //~vaugR~
//                break;                                           //~vaugR~
//            *pco++=UD_NOTLC;                                     //~vaugR~
//                                                                 //~vaugR~
//        }                                                        //~vaugR~
//    }                                                            //~vaugR~
//    *pco=0;                                                      //~vaugR~
//    outlen=PTRDIFF(pco,Poutbuff);                                  //~vav0R~//~vaugR~
//    *Ppoutlen=outlen;                                              //~vav0I~//~vaugR~
//    UTRACED("out",Poutbuff,outlen);                                //~vav0R~//~vaugR~
//    if (reslen)                                                  //~vaugR~
//        rc=4;                                                    //~vaugR~
//    else                                                         //~vaugR~
//        rc=1;                                                    //~vaugR~
//    return rc;                                                     //~vav0I~//~vaugR~
//}//ufilecvDDCT2UD                                                //~vaugR~
//#endif                                                           //~vaugR~
//****************************************************************
//*from UWCH(utf16) to str containing utf8 with delm char          //~v6uFR~//~v6BaR~
//*output UWCH-Z
//rc:0:no utf8,1:contains utf8 subchar,UDRC_FMTERR and set ERROR_INVALID_NAME//~v6uaR~
//****************************************************************
int ufilecvWC2UD(int Popt,UWCH *PfnmW,char *Pfnm,int Pbuffsz,int *Ppcharctr,char *Ppathtbl,int Ppathctr)//~v6uaR~
{
    UWCH *pw,*pw2,*pw3;                                            //~v6u9R~
    UWCH uwseps[3]={DIR_SEPC,FTP_DIR_SEPC};                        //~v6BaI~
    char dirsepc;                                                  //~v6BaR~
    char *pco;
    int ctr,charctr=0,rc=0,rc2=0,resleno,opt,pathctr=0,udtype,swu2l;//~v6uaR~
    int swkeptud,postasciictr;                                                  //~vaudI~//~v6u9R~
//************************
    UTRACED("inp",PfnmW,strszW(PfnmW));                            //~v6uaR~
//  for (pco=Pfnm,pw=PfnmW,resleno=Pbuffsz-1;*pw;pw=pw2)           //~v6uaR~//~v6H9R~
    pw=PfnmW;                                                      //~v6H9I~
    if (IS_RESERVED_NAME(pw))    //drop longname prefix             //~v6H9I~//~v6HaR~//~v6HnR~
        pw+=RESERVED_NAMEID_CTR;                                   //~v6H9I~
    if (IS_WIN_LONGNAME_PREFIX(pw))    //drop longname prefix      //~v6HnI~
        pw+=WIN_LONGNAME_PREFIXCTR;                                //~v6HnI~
    for (pco=Pfnm,resleno=Pbuffsz-1;*pw;pw=pw2)                    //~v6H9I~
    {
    	rc2=0;                                                     //~v6uaI~
        swu2l=0;                                                   //~v6uaI~
//  	pw2=strchrW(pw,DIR_SEPC);                                  //~v6BaR~
    	pw2=strpbrkW(pw,uwseps);                                   //~v6BaI~
        if (pw2)
        {                                                          //~v6BaI~
	        ctr=sz2ctrW(PTRDIFF(pw2,pw));
            dirsepc=(char)*pw2;                                    //~v6BaI~
        }                                                          //~v6BaI~
        else
        {                                                          //~v6BaI~
        	ctr=strctrW(pw);
            dirsepc=0;                                             //~v6BaI~
        }                                                          //~v6BaI~
        swkeptud=0;                                                //~vaudI~
        if (Popt & UFCVO_KEPTUD)    //ucs2 contains ud(from ufullpath)//~v6uaR~
        {                                                          //~v6uaR~
            if (ctr && *pw==UD_NOTLC)                              //~v6uaR~
            {                                                      //~v6uaR~
                pw++;                                              //~v6uaR~
                udtype=*pw++;                                      //~v6uaR~
                ctr-=2;                                            //~v6uaR~
                swkeptud=1;                                        //~vaudI~
            }                                                      //~v6uaR~
            else                                                   //~v6uaR~
                udtype=0;                                          //~v6uaR~
        }                                                          //~v6uaR~
        else                                                       //~v6uaR~
        {                                                          //~v6uaR~
            if (Ppathtbl)                                          //~v6uaR~
                udtype=*(Ppathtbl+pathctr++);                      //~v6uaR~
            else                                                   //~v6uaR~
                udtype=0;                                          //~v6uaR~
        }                                                          //~v6uaR~
        if (ctr)                                                   //~v6uaM~
        {                                                          //~v6uaM~
            if (!udtype && Popt & UFCVO_NEW)                       //~v6uaR~
            {                                                      //~v6uaR~
                opt=UFCVO_SETSUBCHRC;   //rc if trans err          //~v6uaR~
                rc2=ufilecvucs2cpW(opt,pw,ctr,pco,resleno,&charctr);//~v6uaR~
                if (rc2==UWINLNKERR_BUFFOVF)                       //~v6HsR~
                    break;                                         //~v6HsI~
                if (rc2==UCVEXTRC_SUBCH)                           //~v6HsI~
                {                                                  //~v6uaR~
                    rc=1;                                          //~v6uaR~
                    udtype=UD_UTF8WCSUBC;                          //~v6uaR~
                }                                                  //~v6uaR~
                swu2l=1;    //ucs2cp was done                      //~v6uaR~
            }                                                      //~v6uaR~
            if (udtype)                                            //~v6uaR~
            {                                                      //~v6uaR~
                if (resleno<2)                                     //~v6uaR~
                    break;                                         //~v6uaR~
	          if (!(Popt & UFCVO_ENCAPATH)  //partial enclose(rrip ascii)//~v6u9R~
              &&  swu2l			//not by UD on input               //~v6u9R~
              )                                                    //~v6u9R~
              {                                                    //~v6u9R~
              	for (;resleno;ctr--,resleno--,pw++,pco++)          //~v6u9R~
                	if (!UTF8ISASCII(*pw))                         //~v6u9R~
                        break;                                     //~v6u9R~
                if (resleno<2)                                     //~v6u9R~
                    break;                                         //~v6u9R~
                *pco++=UD_NOTLC;                                   //~v6u9R~
//              *pco++=udtype;                                     //~v6u9R~//~v6y2R~
                *pco++=(char)udtype;                               //~v6y2I~
                resleno-=2;                                        //~v6u9R~
                if (!ctr)                                          //~v6u9R~
                	break;                                         //~v6u9R~
              	for (postasciictr=0,pw3=pw+ctr-1;postasciictr<ctr;postasciictr++,pw3--)//~v6u9R~
                	if (!UTF8ISASCII(*pw3))                        //~v6u9R~
                    	break;                                     //~v6u9R~
                ctr-=postasciictr;                                 //~v6u9R~
                if (udtype==UD_UTF8WC||udtype==UD_UTF8WCSUBC)      //~v6u9R~
                {                                                  //~v6u9R~
                    rc2=ufilecvucs2utfW(0,pw,ctr,pco,resleno,&charctr);//~v6u9R~
                    if (rc2)                                       //~v6u9R~
                        break;                                     //~v6u9R~
                    pco+=charctr;                                  //~v6u9R~
                    resleno-=charctr;                              //~v6u9R~
                    pw+=ctr;                                       //~v6u9R~
                }                                                  //~v6u9R~
                else                                               //~v6u9R~
                    break;                                         //~v6u9R~
                if (resleno<postasciictr+1)                        //~v6u9R~
                    break;                                         //~v6u9R~
                *pco++=UD_NOTLC;                                   //~v6u9R~
                resleno--;                                         //~v6u9R~
                umemcpyZ_W2ASCII(pco,pw,postasciictr);             //~v6u9R~
                pw+=postasciictr;                                  //~v6u9R~
                pco+=postasciictr;                                 //~v6u9R~
                resleno-=postasciictr;                             //~v6u9R~
              }                                                    //~v6u9R~
              else  //full for a apth                              //~v6u9R~
              {                                                    //~v6u9R~
                *pco++=UD_NOTLC;                                   //~v6uaR~
//              *pco++=udtype;                                     //~v6uaR~//~v6y2R~
                *pco++=(char)udtype;                               //~v6y2I~
                resleno-=2;                                        //~v6uaR~
                if (udtype==UD_UTF8WC||udtype==UD_UTF8WCSUBC)      //~v6uaR~
                {                                                  //~v6uaR~
                    rc2=ufilecvucs2utfW(0,pw,ctr,pco,resleno,&charctr);//~v6uaR~
                    if (rc2)                                       //~v6uaR~
                        break;                                     //~v6uaR~
                    pco+=charctr;                                  //~v6uaR~
                    resleno-=charctr;                              //~v6uaR~
                }                                                  //~v6uaR~
//                else                                               //~v6uaR~//~vaucR~
//                if (udtype==UD_UTF8FN)                             //~v6uaR~//~vaucR~
//                {                                                  //~v6uaR~//~vaucR~
//                    opt=0;                                         //~v6uaR~//~vaucR~
//                    if (resleno<ctr2szW(ctr))                      //~v6uaR~//~vaucR~
//                        break;                                     //~v6uaR~//~vaucR~
//                    umemcpyZ_W2ASCII(pco,pw,ctr);                  //~v6uaR~//~vaucR~
//                    if (rc2)                                       //~v6uaR~//~vaucR~
//                        break;                                     //~v6uaR~//~vaucR~
//                    pco+=ctr;                                      //~v6uaR~//~vaucR~
//                    resleno-=ctr;                                  //~v6uaR~//~vaucR~
//                }                                                  //~v6uaR~//~vaucR~
                else                                               //~v6uaR~
                    break;                                         //~v6uaR~
                if (!resleno)                                      //~v6uaR~
                    break;                                         //~v6uaR~
                pw+=ctr;                                           //~v6uaR~
//              if (!(Popt & UFCVO_KEPTUD))    //ucs2 contains ud(from ufullpath)//~v6uaR~//~vaudR~
				if (!swkeptud)                                     //~vaudR~
                {                                                  //~v6uaI~
                	*pco++=UD_NOTLC;                               //~v6uaI~
                    resleno--;                                     //~v6uaR~
                }                                                  //~v6uaI~
              }//not full for a path                               //~v6u9R~
            }                                                      //~v6uaR~
            else //!udtype                                          //~v6uaR~//~v6u9R~
            {                                                      //~v6uaR~
                opt=0;                                             //~v6uaR~
                if (!swu2l)                                        //~v6uaR~
                {                                                  //~v6uaR~
                    rc2=ufilecvucs2cpW(opt,pw,ctr,pco,resleno,&charctr);//~v6uaR~
                    if (rc2)                                       //~v6uaR~
                        break;                                     //~v6uaR~
                }                                                  //~v6uaR~
                pco+=charctr;                                      //~v6uaR~
                resleno-=charctr;                                  //~v6uaR~
                pw+=ctr;                                           //~v6uaR~
            }                                                      //~v6uaR~
        }//ctr!=0                                                  //~v6uaI~
        if (!pw2)
        	break;
        if (!resleno)                                              //~v6uaR~
        	break;                                                 //~v6uaI~
        pw2++;
//      *pco++=DIR_SEPC;                                           //~v6BaR~
        *pco++=dirsepc;                                            //~v6BaR~
        resleno--;                                                 //~v6uaR~
    }
    charctr=PTRDIFF(pco,Pfnm);
	*(Pfnm+charctr)=0;	//strz                                     //~v6uaR~
    if (Ppcharctr)
    	*Ppcharctr=charctr;
    if (*pw)                                                       //~v6HsR~
    {                                                              //~v6HsI~
		rc=UDRC_BUFFSHORTAGE;                                      //~v6HsI~
    }                                                              //~v6HsI~
    else                                                           //~v6HsI~
    if (rc2)
    {
        uerrmsg("Invalid WideChar FileName Format(%s)",0,
        		PfnmW);
    	rc=UDRC_FMTERR;
        SetLastError(ERROR_INVALID_NAME);
    }
    UTRACED("out char",Pfnm,charctr);
	UTRACEP("%s:rc=%d,resleno=%d\n",UTT,rc,resleno);               //~v6uaR~
    return rc;
}//ufilecvWC2UD
//**************************************************************** //~vaucI~
//*DD fmt to utf8 with checking 2cp err(subchar)                   //~vaucI~
//*rc:4:err,SUBCHRC                                                //~vaucI~
//**************************************************************** //~vaucI~
int ufilecvDD2U8(int Popt,char *Pdddata,char *Pdddbcs,int Pddlen,char *Poutu8,int Pu8buffsz,char *Poutlc,int Plcbuffsz,int *Ppoutu8len,int *Ppoutlclen)//~vaucR~
{                                                                  //~vaucI~
	                                                               //~vaucI~
    int rc=0,rc2=0,u8len,ucsctr,buffsz,lclen,opt;                  //~vaucR~
//  UWCH wkucs[_MAX_PATHWC];                                       //~vaucI~//~v6H9R~
//  char wklc[_MAX_PATH],*plc;                                     //~vaucR~//~v6H9R~
    UWCH wkucs[_MAX_PATHWC_LONG];                                  //~v6H9I~
    char wklc[_MAX_PATH_LONG],*plc;                                //~v6H9I~
//************************                                         //~vaucI~
    UTRACED("inp dddata",Pdddata,Pddlen);                          //~vaucI~
    UTRACED("inp dddbcs",Pdddbcs,Pddlen);                          //~vaucI~
    opt=0;                                                         //~vaucI~
	rc2=utfcvdd2f(opt,Pdddata,Pddlen,Pdddbcs,Poutu8,Pu8buffsz,&u8len,NULL/*Ppoutdbcs*/);//~vaucI~
    *Ppoutu8len=u8len;                                             //~vaucI~
    if (rc2 & UTFDD2FRC_BUFFOVERFLOW)                      //~vav0I~//~vaucI~
    	return 4;                                                  //~vaucI~
    opt=0;                                                         //~vaucI~
	rc2=ufilecvutf2ucsW(opt,Poutu8,u8len,wkucs,sizeof(wkucs),&ucsctr);//~vaucI~
    if (rc2)                                                       //~vaucI~
    	return 4;                                                  //~vaucI~
    if (Poutlc)                                                    //~vaucI~
    	plc=Poutlc,buffsz=Plcbuffsz;                               //~vaucI~
    else                                                           //~vaucI~
    	plc=wklc,buffsz=sizeof(wklc);                              //~vaucI~
    opt=UFCVO_STRZ|UFCVO_SETSUBCHRC;                               //~vaucI~
	rc2=ufilecvucs2cpW(opt,wkucs,ucsctr,plc,buffsz,&lclen);        //~vaucI~
    if (Ppoutlclen)                                                //~vaucI~
	    *Ppoutlclen=lclen;                                         //~vaucI~
    if (!rc2)                                                      //~vaucI~
    	rc=0;                                                      //~vaucI~
    else                                                           //~vaucI~
    if (rc2==UCVEXTRC_SUBCH)                                       //~vaucI~
    	rc=rc2;                                                    //~vaucI~
    else                                                           //~vaucI~
    	rc=4;                                                      //~vaucI~
    return rc;                                                     //~vaucI~
}//ufilecvDD2U8                                                    //~vaucI~
//**************************************************************** //~v6uaI~
//*enclose utf8 string to UD fmt                                   //~v6uaR~
//rc:1:already UD fmt,4:buff shortage                              //~v6uaI~
//**************************************************************** //~v6uaI~
//int ufilecvencloseu8(int Popt,char *Ppu8,int Pu8len,char **Pppud,int Ppudsz,int *Ppudlen)//~v6uaI~//~vaucR~
int ufilecvencloseu8(int Popt,int Pudtype,char *Ppu8,int Pu8len,char **Pppud,int Ppudsz,int *Ppudlen)//~vaucI~
{                                                                  //~v6uaI~
    char *pco;                                                     //~v6uaI~
    int outlen;                                                    //~v6uaR~
//************************                                         //~v6uaI~
    UTRACED("inp",Ppu8,Pu8len);                                    //~v6uaI~
	if (*Ppu8==UD_NOTLC)                                           //~v6uaI~
    	return 1;                                                  //~v6uaI~
    if (Popt & UFCEUO_PTR)                                         //~v6uaI~
    {                                                              //~v6uaI~
    	pco=*Pppud;                                                //~v6uaI~
        ufree(pco);                                                //~v6uaI~
    	pco=umalloc(Pu8len+3+1);                                   //~v6uaR~
        *Pppud=pco;                                                //~v6uaI~
    }                                                              //~v6uaI~
    else                                                           //~v6uaI~
    {	                                                           //~v6uaI~
    	if (Ppudsz<Pu8len+3+1)                                     //~v6uaI~
        	return 4;                                              //~v6uaI~
        pco=*Pppud;                                                //~v6uaI~
    }                                                              //~v6uaI~
    *pco++=UD_NOTLC;                                               //~v6uaI~
//    *pco++=UD_UTF8WC;                                              //~v6uaR~//~vaucR~
//  *pco++=Pudtype;                                                //~vaucI~//~v6y2R~
    *pco++=(char)Pudtype;                                          //~v6y2I~
    memcpy(pco,Ppu8,Pu8len);                                       //~v6uaI~
    pco+=Pu8len;                                                   //~v6uaR~
    *pco++=UD_NOTLC;                                               //~v6uaI~
    *pco=0;                                                        //~v6uaI~
    outlen=PTRDIFF(pco,*Pppud);                                    //~v6uaR~
    if (Ppudlen)                                                   //~v6uaI~
    	*Ppudlen=outlen;                                           //~v6uaI~
    UTRACED("out char",*Pppud,outlen);                             //~v6uaR~
    return 0;                                                      //~v6uaI~
}//ufilecvencloseu8                                                //~v6uaR~
//**************************************************************** //~v6uaI~
//*drop UD id from UD strong                                       //~vaudR~
//*no outct support because "?" by reperr was reset by the reason of ascii//~vaucI~
//*outCT is optional,in ct is required when outCT was specvified   //~v6uKR~
//rc:1:stripped                                                    //~v6uaI~
//**************************************************************** //~v6uaI~
//int ufilecvstripUD(int Popt,char *Ppud,int Pudlen,char *Ppu8,int Pbuffsz,int *Ppu8len)//~vaugR~//~vaucR~
int ufilecvstripUD(int Popt,char *Ppud,int Pudlen,char *Ppu8,int Pbuffsz,int *Ppu8len,char *Pct,char *Poutct)//~vaugI~//~vaucR~
{                                                                  //~v6uaI~
    char *pco,*pc,*pc2,*pc3;                                       //~v6uaR~
    char *pct,*pcto;                                                     //~vaugI~//~vaucR~
    int rc=0,outlen,reslen,resleno,len;                            //~v6uaR~
//************************                                         //~v6uaI~
    UTRACED("inp",Ppud,Pudlen);                                    //~v6uaI~
	for (pc=Ppud,reslen=Pudlen,pco=Ppu8,resleno=Pbuffsz;reslen;)   //~v6uaI~
    {                                                              //~v6uaI~
    	pc2=memchr(pc,UD_NOTLC,reslen);                            //~v6uaI~
        if (pc2)                                                   //~v6uaI~
	        len=PTRDIFF(pc2,pc);                                   //~v6uaI~
        else                                                       //~v6uaI~
        	len=reslen;                                            //~v6uaI~
        if (resleno<len)                                           //~v6uaI~
            break;                                                 //~v6uaI~
        pcto=Poutct+PTRDIFF(pco,Ppu8);                              //~vaugI~//~vaucR~
        if (Poutct)                                                //~vaugI~//~vaucR~
            memset(pcto,0,len);                                     //~vaugI~//~vaucR~
        memcpy(pco,pc,len);                                        //~v6uaI~
        pco+=len;                                                  //~v6uaI~
        resleno-=len;                                              //~v6uaI~
        pc+=len;                                                   //~v6uaI~
        reslen-=len;                                               //~v6uaI~
        if (!pc2)                                                  //~v6uaI~
        	break;                                                 //~v6uaI~
        if (reslen>=3                                              //~v6uaI~
        &&  (*(pc+1)==UD_UTF8WCSUBC || *(pc+1)==UD_UTF8WC)         //~v6uKR~
        &&  (pc3=memchr(pc+2,UD_NOTLC,reslen-2),pc3)               //~v6uaI~
        &&  (len=PTRDIFF(pc3,pc),len>0)                            //~v6uaI~
        )                                                          //~v6uaI~
        {                                                          //~v6uaI~
        	if (resleno<len-2)                                     //~v6uaI~
            	break;                                             //~v6uaI~
            rc=1;                                                  //~v6uaI~
            pcto=Poutct+PTRDIFF(pco,Ppu8);                          //~vaugI~//~vaucR~
            pct=Pct+PTRDIFF(pc,Ppud);                              //~vaucI~
            if (Poutct)                                            //~vaugI~//~vaucR~
            {                                                      //~vaugI~//~vaucR~
//                int ii;                                            //~vaugI~//~vaucR~
//                char *_pct,*_pc;                                   //~vaugI~//~vaucR~
//                for (_pct=pct,_pc=pc+2,ii=len-2;ii>0;ii--,_pct++,_pc++)//~vaugR~//~vaucR~
//                    if (UTF8ISASCII(*_pc))                         //~vaugR~//~vaucR~
//                        *_pct=0;                                   //~vaugI~//~vaucR~
//                    else                                           //~vaugI~//~vaucR~
//                        *_pct=UTFCT_UTF8;                          //~vaugI~//~vaucR~
				memcpy(pcto,pct+2,len-2);                          //~vaucR~
            }                                                      //~vaugI~//~vaucR~
        	memcpy(pco,pc+2,len-2);                                //~v6uaI~
            pc+=len+1;                                             //~v6uaI~
            reslen-=len+1;                                         //~v6uaI~
            pco+=len-2;                                            //~v6uaI~
            resleno-=len-2;                                        //~v6uaI~
        }                                                          //~v6uaI~
        else                                                       //~v6uaI~
        {                                                          //~v6uaI~
            pcto=Poutct+PTRDIFF(pco,Ppu8);                          //~vaugI~//~vaucR~
            if (Poutct)                                            //~vaugI~//~vaucR~
                *pcto++=0;                                          //~vaugI~//~vaucR~
        	*pco++=*pc++;                                          //~v6uaI~
        	reslen--;                                              //~v6uaI~
        	resleno--;                                             //~v6uaI~
        }                                                          //~v6uaI~
    }                                                              //~v6uaI~
    outlen=PTRDIFF(pco,Ppu8);                                      //~v6uaR~
    if (Popt & UFCVO_STRZ)                                         //~vaugI~
        if (Pbuffsz>outlen)                                        //~vaugI~
	        *pco=0;                                                //~vaugI~
    if (Ppu8len)                                                   //~v6uaI~
	    *Ppu8len=outlen;                                           //~v6uaI~
    if (reslen>0)                                                  //~v6uaI~
    	rc=4;                                                      //~v6uaI~
    UTRACED("out char",Ppu8,outlen);                               //~v6uaI~
    return rc;                                                     //~v6uaI~
}//ufilecvstripUD                                                  //~v6uaI~
//**************************************************************** //~v6u9R~
//*change UD fmt to hex notation for cmdline parm                  //~v6u9R~
//rc:1:notation changed                                            //~v6u9R~
//**************************************************************** //~v6u9R~
int ufilecvUD2UDX(int Popt,char *Ppud,int Pudlen,char *Ppu8,int Pbuffsz,int *Ppu8len)//~v6u9R~
{                                                                  //~v6u9R~
    char *pco,*pc,*pc2,*pc3,*pc4;                                  //~v6u9R~
    int rc=0,outlen,reslen,resleno,len,lenx;                       //~v6u9R~
//************************                                         //~v6u9R~
    UTRACED("inp",Ppud,Pudlen);                                    //~v6u9R~
	for (pc=Ppud,reslen=Pudlen,pco=Ppu8,resleno=Pbuffsz;reslen;)   //~v6u9R~
    {                                                              //~v6u9R~
    	pc2=memchr(pc,UD_NOTLC,reslen);                            //~v6u9R~
        if (pc2)                                                   //~v6u9R~
	        len=PTRDIFF(pc2,pc);                                   //~v6u9R~
        else                                                       //~v6u9R~
        	len=reslen;                                            //~v6u9R~
        if (resleno<len)                                           //~v6u9R~
            break;                                                 //~v6u9R~
        memcpy(pco,pc,len);                                        //~v6u9R~
        pco+=len;                                                  //~v6u9R~
        resleno-=len;                                              //~v6u9R~
        pc+=len;                                                   //~v6u9R~
        reslen-=len;                                               //~v6u9R~
        if (!pc2)                                                  //~v6u9R~
        	break;                                                 //~v6u9R~
        if (reslen>=3                                              //~v6u9R~
        &&  (*(pc+1)==UD_UTF8WCSUBC || *(pc+1)==UD_UTF8WC)         //~v6u9R~
        &&  (pc3=memchr(pc+2,UD_NOTLC,reslen-2),pc3)               //~v6u9R~
        &&  (len=PTRDIFF(pc3,pc),len>0)                            //~v6u9R~
        )                                                          //~v6u9R~
        {                                                          //~v6u9R~
            rc=1;                                                  //~v6u9R~
            reslen-=len+1;                                         //~v6u9R~
        	for (pc4=pc+2;pc4<pc3 && resleno>3;)                   //~v6u9R~
            {                                                      //~v6u9R~
                if (!UTF8ISASCII(*pc4))                            //~v6u9R~
                	break;                                         //~v6u9R~
                *pco++=*pc4++;                                     //~v6u9R~
                resleno--;                                         //~v6u9R~
            }                                                      //~v6u9R~
            *pco++=UD_NOTLC;                                       //~v6u9R~
            *pco++=UD_UTF8X;                                       //~v6u9R~
            resleno-=2;                                            //~v6u9R~
            lenx=PTRDIFF(pc3,pc4);                                 //~v6u9R~
            if (resleno<lenx*2+1)                                  //~v6u9R~
            	break;                                             //~v6u9R~
        	ub2x(0,pco,pc4,lenx);                                  //~v6u9R~
            pco+=lenx*2;                                           //~v6u9R~
            *pco++=UD_NOTLC;                                       //~v6u9R~
            resleno-=lenx*2+1;                                     //~v6u9R~
            pc=pc3+1;                                              //~v6u9R~
        }                                                          //~v6u9R~
        else                                                       //~v6u9R~
        {                                                          //~v6u9R~
        	*pco++=*pc++;                                          //~v6u9R~
        	reslen--;                                              //~v6u9R~
        	resleno--;                                             //~v6u9R~
        }                                                          //~v6u9R~
    }                                                              //~v6u9R~
    outlen=PTRDIFF(pco,Ppu8);                                      //~v6u9R~
    if (Popt & UFCVO_STRZ)                                         //~v6u9R~
        if (Pbuffsz>outlen)                                        //~v6u9R~
	        *pco=0;                                                //~v6u9R~
    if (Ppu8len)                                                   //~v6u9R~
	    *Ppu8len=outlen;                                           //~v6u9R~
    if (reslen>0)                                                  //~v6u9R~
    	rc=4;                                                      //~v6u9R~
    UTRACED("out char",Ppu8,outlen);                               //~v6u9R~
    return rc;                                                     //~v6u9R~
}//ufilecvUD2UDX                                                   //~v6u9R~
//**************************************************************** //~v6u9R~
//*change UD fmt to hex notation for cmdline parm                  //~v6u9R~
//rc:1:stripped                                                    //~v6u9R~
//**************************************************************** //~v6u9R~
int ufilecvUDX2UD(int Popt,char *Ppud,int Pudlen,char *Ppu8,int Pbuffsz,int *Ppu8len)//~v6u9R~
{                                                                  //~v6u9R~
    char *pco,*pc,*pc2,*pc3;                                       //~v6u9R~
    int rc=0,outlen,reslen,resleno,len;                            //~v6u9R~
//************************                                         //~v6u9R~
    UTRACED("inp",Ppud,Pudlen);                                    //~v6u9R~
	for (pc=Ppud,reslen=Pudlen,pco=Ppu8,resleno=Pbuffsz;reslen;)   //~v6u9R~
    {                                                              //~v6u9R~
    	pc2=memchr(pc,UD_NOTLC,reslen);                            //~v6u9R~
        if (pc2)                                                   //~v6u9R~
	        len=PTRDIFF(pc2,pc);                                   //~v6u9R~
        else                                                       //~v6u9R~
        	len=reslen;                                            //~v6u9R~
        if (resleno<len)                                           //~v6u9R~
            break;                                                 //~v6u9R~
        memcpy(pco,pc,len);                                        //~v6u9R~
        pco+=len;                                                  //~v6u9R~
        resleno-=len;                                              //~v6u9R~
        pc+=len;                                                   //~v6u9R~
        reslen-=len;                                               //~v6u9R~
        if (!pc2)                                                  //~v6u9R~
        	break;                                                 //~v6u9R~
        if (reslen>=3                                              //~v6u9R~
        &&  *(pc+1)==UD_UTF8X                                      //~v6u9R~
        &&  (pc3=memchr(pc+2,UD_NOTLC,reslen-2),pc3)               //~v6u9R~
        &&  (len=PTRDIFF(pc3,pc),len>0)                            //~v6u9R~
        )                                                          //~v6u9R~
        {                                                          //~v6u9R~
            rc=1;                                                  //~v6u9R~
            reslen-=len+1;                                         //~v6u9R~
            if (resleno<(len-2)/2+3)                               //~v6u9R~
            	break;                                             //~v6u9R~
            *pco++=UD_NOTLC;                                       //~v6u9R~
            *pco++=UD_UTF8WC;                                      //~v6u9R~
        	ugethex(pc+2,pco,len-2);                               //~v6u9R~
            pco+=(len-2)/2;                                        //~v6u9R~
            *pco++=UD_NOTLC;                                       //~v6u9R~
            resleno-=(len-2)/2+3;                                  //~v6u9R~
            pc=pc3+1;                                              //~v6u9R~
        }                                                          //~v6u9R~
        else                                                       //~v6u9R~
        {                                                          //~v6u9R~
        	*pco++=*pc++;                                          //~v6u9R~
        	reslen--;                                              //~v6u9R~
        	resleno--;                                             //~v6u9R~
        }                                                          //~v6u9R~
    }                                                              //~v6u9R~
    outlen=PTRDIFF(pco,Ppu8);                                      //~v6u9R~
    if (Popt & UFCVO_STRZ)                                         //~v6u9R~
        if (Pbuffsz>outlen)                                        //~v6u9R~
	        *pco=0;                                                //~v6u9R~
    if (Ppu8len)                                                   //~v6u9R~
	    *Ppu8len=outlen;                                           //~v6u9R~
    if (reslen>0)                                                  //~v6u9R~
    	rc=4;                                                      //~v6u9R~
    UTRACED("out char",Ppu8,outlen);                               //~v6u9R~
    return rc;                                                     //~v6u9R~
}//ufilecvUDX2UD                                                   //~v6u9R~
//****************************************************************
//*FindFirstFileW with UD string parm
//*
//****************************************************************
HDIR uFindFirstFileW(char *Pfnm,WIN32_FIND_DATAW *Ppw32fd,int Popt,UWCH *PfnmW,int Pbuffsz,int *Ppucsctr)
{
    int rc=0,opt,buffsz,ucsctr;                                    //~v6uaR~
    HDIR   hdir;
    UWCH *pw;                                                      //~v6uaR~
//  UWCH  fnmW[_MAX_PATHWC];                                       //~v6uaI~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH  fnmW[_MAX_PATHWC_LONG];                                  //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *fnmW;                                                    //~v6HsI~
#endif                                                             //~v6HsI~
//************************
	UTRACED("inp",Pfnm,strlen(Pfnm));
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    fnmW=SmaxbuffW;                                                //~v6HsI~
#endif                                                             //~v6HsI~
    pw=PfnmW;                                                      //~v6uaR~
    buffsz=Pbuffsz;                                                //~v6uaI~
    if (!pw)                                                       //~v6uaI~
    {                                                              //~v6uaI~
    	pw=fnmW;                                                   //~v6uaI~
#ifdef BBB                                                         //~v6HsI~
	    buffsz=sizeof(fnmW);                                       //~v6uaI~
#else                                                              //~v6HsI~
	    buffsz=MAXBUFFSZ;                                          //~v6HsI~
#endif                                                             //~v6HsI~
    }                                                              //~v6uaI~
    opt=0;//drop UD                                                //~v6uaI~
//  rc=ufilecvUD2WC(opt,Pfnm,pw,buffsz,&ucsctr,NULL/*pathtbl*/,0/*pathtblsz*/,NULL/*outpathctr*/);//~v6uaR~//~vaudR~
    rc=ufilecvUD2WCnopath(opt,Pfnm,pw,buffsz,&ucsctr);             //~vaudI~
    if (rc>=UDRC_ERR)                                              //~v6uaR~
    	hdir=INVALID_HANDLE_VALUE;
    else
    {                                                              //~v6uaI~
	    hdir=FindFirstFileW(pw,Ppw32fd);
    	UTRACEP("%s:hdir=%x\n",UTT,hdir);                          //~v6HnI~//~v6HhR~
    	UTRACED("fnmw",pw,strszW(pw));                             //~v6uaI~//~v6HnM~//~v6HhR~
    	if (hdir!=INVALID_HANDLE_VALUE)                            //~v6w0I~
        {                                                          //~v6HnI~//~v6HhR~
        	if (!Ppw32fd->ftCreationTime.dwLowDateTime && !Ppw32fd->ftCreationTime.dwHighDateTime)	//may be reserved file//~v6w0I~
            {                                                      //~v6HnI~
            	hdir=chkReservedNameW(hdir,pw,Ppw32fd);            //~v6w0I~
                UTRACEP("%s:hdir=%x,errno=%d,lasterr=%d\n",UTT,hdir,errno,GetLastError());//~v6HnR~
                UTRACED("pw",pw,strszW(pw));                       //~v6HnI~
            }                                                      //~v6HnI~
        }                                                          //~v6HnI~//~v6HhR~
    	if (hdir==INVALID_HANDLE_VALUE)                            //~v6HnI~//~v6HhR~
           	hdir=tryLongNamePrefixFindFirstFileW(hdir,pw,Ppw32fd); //~v6HnI~//~v6HhR~
    	if (hdir==INVALID_HANDLE_VALUE)                            //~v6yhI~
        {                                                          //~v6yhI~
    		UTRACEP("%s:errno=%d,GetLastError=%d\n",UTT,errno,GetLastError());//~v6yhI~
        }                                                          //~v6yhI~
        if (Ppucsctr)                                              //~v6uaI~
        	*Ppucsctr=ucsctr;                                      //~v6uaR~
    }                                                              //~v6uaI~
    UTRACED("w32fd",Ppw32fd,sizeof(WIN32_FIND_DATAW));
    UTRACEP("%s:hdir=%p\n",UTT,hdir);
    return hdir;
}//uFindFirstFileW
//**************************************************************** //~v6uaI~
//*GetShortPathNameW with UD string parm                           //~v6uaI~
//**************************************************************** //~v6uaI~
int uGetShortPathNameW(char *Plongfnm,char *Pshortfnm,int Pbuffsz,int Popt,UWCH *PshortfnmW,int PbuffszW,int *Ppucsctr,int *Ppudfmt)//~v6uaR~
{                                                                  //~v6uaI~
    int rc,opt,ucsctr,charctr,pathctr;                             //~v6uaR~
//  UWCH  fnmlongW[_MAX_PATHWC];                                   //~v6uaR~//~v6H9R~
//  UWCH  fnmshortW[_MAX_PATHWC];                                  //~v6uaI~//~v6HaI~
#ifdef BBB                                                         //~v6HsI~
    UWCH  fnmlongW[_MAX_PATHWC_LONG];                              //~v6H9I~
    UWCH  fnmshortW[_MAX_PATHWC_LONG];                             //~v6HaI~
#else                                                              //~v6HsI~
    UWCH *fnmlongW;                                                //~v6HsI~
    UWCH *fnmshortW;                                               //~v6HsI~
#endif                                                             //~v6HsI~
    char  wkfnmshort[_MAX_PATH_LONG];                              //~v6HcI~
    char pathtbl[MAXPATHLVL];                                      //~v6uaI~
//************************                                         //~v6uaI~
	UTRACED("inp",Plongfnm,strlen(Plongfnm));                      //~v6uaR~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    fnmlongW=SmaxbuffW;                                            //~v6HsI~
    fnmshortW=SmaxbuffW2;                                          //~v6HsI~
#endif                                                             //~v6HsI~
    opt=0;	//drop UD                                              //~v6uaI~
#ifdef BBB                                                         //~v6HsI~
	rc=ufilecvUD2WC(opt,Plongfnm,fnmlongW,sizeof(fnmlongW),&ucsctr,pathtbl,sizeof(pathtbl),&pathctr);//~v6uaR~
#else                                                              //~v6HsI~
	rc=ufilecvUD2WC(opt,Plongfnm,fnmlongW,MAXBUFFSZ,&ucsctr,pathtbl,sizeof(pathtbl),&pathctr);//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc>=UDRC_ERR)                                              //~v6uaR~
    	rc=0;	//err                                              //~v6uaI~
    else                                                           //~v6uaI~
    {                                                              //~v6uaI~
    	UTRACED("fnmw",fnmlongW,ctr2szW(ucsctr));                  //~v6uaR~
#ifdef BBB                                                         //~v6HsI~
	    ucsctr=GetShortPathNameW(fnmlongW,fnmshortW,sz2ctrW(sizeof(fnmshortW)));//~v6uaR~
#else                                                              //~v6HsI~
	    ucsctr=GetShortPathNameW(fnmlongW,fnmshortW,sz2ctrW(MAXBUFFSZ));//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc>=UDRC_ERR)                                              //~v6HsI~
        if (Ppucsctr)                                              //~v6uaI~
        	*Ppucsctr=ucsctr;                                      //~v6uaI~
        rc=0;                                                      //~v6uaI~
        if (ucsctr)                                                //~v6uaI~
        {                                                          //~v6uaI~
        	opt=UFCVO_NEW;	//chk and set WCSUBC                   //~v6uaI~
          if (Pbuffsz && Pshortfnm)                                //~v6H9I~
          {                                                        //~v6H9I~
//  		rc=ufilecvWC2UD(opt,fnmshortW,Pshortfnm,Pbuffsz,&charctr,pathtbl,pathctr);//~v6uaR~//~v6HaR~
    		rc=ufilecvWC2UD(opt,fnmshortW,Pshortfnm,Pbuffsz,&charctr,NULL/*pathtbl*/,0/*pathctr*/);//~v6HaI~
            UTRACED("short",Pshortfnm,Pbuffsz);                //~v6uaI~//~v6H9I~
          }                                                        //~v6H9I~
          else                                                     //~v6HcI~
          {                                                        //~v6HcI~
#ifdef BBB                                                         //~v6HsI~
    		rc=ufilecvWC2UD(opt,fnmshortW,wkfnmshort,sizeof(wkfnmshort),&charctr,NULL/*pathtbl*/,0/*pathctr*/);//~v6HcI~
#else                                                              //~v6HsI~
    		rc=ufilecvWC2UD(opt,fnmshortW,wkfnmshort,MAXBUFFSZ,&charctr,NULL/*pathtbl*/,0/*pathctr*/);//~v6HsI~
#endif                                                             //~v6HsI~
            UTRACED("short",wkfnmshort,strszW(wkfnmshort));        //~v6HcI~//~v6HsR~
          }                                                        //~v6HcI~
            if (rc==1)	//UD fmt output                            //~v6uaI~
            {                                                      //~v6uaI~
            	rc=0;                                              //~v6uaI~
                if (Ppudfmt)                                       //~v6uaI~
                	*Ppudfmt=1;                                    //~v6uaI~
            }                                                      //~v6uaI~
	    	if (rc)                                                //~v6uaI~
    		{                                                      //~v6uaI~
        		SetLastError(ERROR_INVALID_PARAMETER); 	//see doc of GetShortPathName//~v6uaI~
                rc=0;                                              //~v6uaI~
    		}                                                      //~v6uaI~
            else                                                   //~v6uaI~
    		{                                                      //~v6uaI~
//              if (PshortfnmW)                                    //~v6uaI~//~v6H9R~
                if (PbuffszW && PshortfnmW)                        //~v6H9I~
                {                                                  //~v6uaI~
                	UstrncpyZW(PshortfnmW,fnmshortW,PbuffszW);     //~v6uaI~
                    UTRACED("shortW",PshortfnmW,PbuffszW);         //~v6uaI~
                }                                                  //~v6uaI~
            	rc=charctr;                                        //~v6uaM~
    		}                                                      //~v6uaI~
        }                                                          //~v6uaI~
    }                                                              //~v6uaI~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v6uaI~
    return rc;                                                     //~v6uaI~
}//uGetShortPathNameW                                              //~v6uaI~
//**************************************************************** //~v6uaI~
//*SetFileAttributes with UD string parm                           //~v6uaI~
//*                                                                //~v6uaI~
//**************************************************************** //~v6uaI~
BOOL uSetFileAttributesW(char *Pfnm,DWORD Pdwattr,int Popt,UWCH *PfnmW,int Pbuffsz,int *Ppucsctr)//~v6uaR~
{                                                                  //~v6uaI~
    int rc=0,opt,buffsz,ucsctr;                                    //~v6uaR~
    UWCH *pw;                                                      //~v6uaI~
//  UWCH  fnmW[_MAX_PATHWC];                                       //~v6uaI~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH  fnmW[_MAX_PATHWC_LONG];                                  //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *fnmW;                                                    //~v6HsI~
#endif                                                             //~v6HsI~
//************************                                         //~v6uaI~
	UTRACED("inp",Pfnm,strlen(Pfnm));                              //~v6uaI~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    fnmW=SmaxbuffW;                                                //~v6HsI~
#endif                                                             //~v6HsI~
    pw=PfnmW;                                                      //~v6uaI~
    buffsz=Pbuffsz;                                                //~v6uaI~
    if (!pw)                                                       //~v6uaI~
    {                                                              //~v6uaI~
    	pw=fnmW;                                                   //~v6uaI~
#ifdef BBB                                                         //~v6HsI~
	    buffsz=sizeof(fnmW);                                       //~v6uaI~
#else                                                              //~v6HsI~
	    buffsz=MAXBUFFSZ;                                          //~v6HsI~
#endif                                                             //~v6HsI~
    }                                                              //~v6uaI~
    opt=0;//drop UD                                                //~v6uaI~
//  rc=ufilecvUD2WC(opt,Pfnm,pw,buffsz,&ucsctr,NULL/*pathtbl*/,0/*pathtblsz*/,NULL/*pathctr*/);//~v6uaR~//~vaudR~
    rc=ufilecvUD2WCnopath(opt,Pfnm,pw,buffsz,&ucsctr);             //~vaudI~
    if (rc>=UDRC_ERR)                                              //~v6uaI~
    	rc=FALSE;	//false;                                       //~v6uaI~
    else                                                           //~v6uaI~
    {                                                              //~v6uaI~
    	UTRACED("fnmw",pw,strszW(pw));                             //~v6uaI~
	    rc=SetFileAttributesW(pw,Pdwattr);                         //~v6uaR~
        if (!rc)                                                   //~v6y3I~
		    rc=trySetFileAttributesW(pw,Pdwattr,rc);               //~v6y3I~
        if (Ppucsctr)                                              //~v6uaI~
        	*Ppucsctr=ucsctr;                                      //~v6uaI~
    }                                                              //~v6uaI~
    UTRACEP("%s:rc=%d,dwattr=%x\n",UTT,rc,Pdwattr);                //~v6uaI~
    return rc;                                                     //~v6uaR~
}//uSetFileAttributesW                                              //~v6uaI~//~v6u9R~
//**************************************************************** //~v6u9R~
//*MoveFile                                                        //~v6u9R~
//**************************************************************** //~v6u9R~
int/*bool*/ uMoveFileW(char *Pold,char *Pnew,int Popt)             //~v6u9R~
{                                                                  //~v6u9R~
    int rc=0,rc2,opt,ucsctro,ucsctrn;                              //~v6u9R~
//  UWCH  fnmoldW[_MAX_PATHWC];                                    //~v6u9R~//~v6H9R~
//  UWCH  fnmnewW[_MAX_PATHWC];                                    //~v6u9R~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH  fnmoldW[_MAX_PATHWC_LONG];                               //~v6H9I~
    UWCH  fnmnewW[_MAX_PATHWC_LONG];                               //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *fnmoldW;                                                 //~v6HsI~
    UWCH *fnmnewW;                                                 //~v6HsI~
#endif                                                             //~v6HsI~
    int lasterr;                                                   //~v6H9I~
//************************                                         //~v6u9R~
	UTRACEP("%s:opt=%x,old=%s,new=%s\n",UTT,Popt,Pold,Pnew);       //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    fnmoldW=SmaxbuffW;                                             //~v6HsI~
    fnmnewW=SmaxbuffW2;                                            //~v6HsI~
#endif                                                             //~v6HsI~
    opt=0;//drop UD                                                //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
    rc2=ufilecvUD2WCnopath(opt,Pold,fnmoldW,sizeof(fnmoldW),&ucsctro);//strz out//~v6u9R~
#else                                                              //~v6HsI~
    rc2=ufilecvUD2WCnopath(opt,Pold,fnmoldW,MAXBUFFSZ,&ucsctro);//strz out//~v6HsR~
#endif                                                             //~v6HsI~
    if (rc2<UDRC_ERR)                                              //~v6u9R~
    {                                                              //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
    	rc2=ufilecvUD2WCnopath(opt,Pnew,fnmnewW,sizeof(fnmnewW),&ucsctrn);//~v6u9R~
#else                                                              //~v6HsI~
    	rc2=ufilecvUD2WCnopath(opt,Pnew,fnmnewW,MAXBUFFSZ,&ucsctrn);//~v6HsR~
#endif                                                             //~v6HsI~
    }                                                              //~v6HsI~
    if (rc2<UDRC_ERR)                                              //~v6u9R~
    {                                                              //~v6w0I~
        rc=MoveFileW(fnmoldW,fnmnewW);                             //~v6u9R~
        lasterr=GetLastError();                                    //~v6H9I~
        UTRACEP("%s:bool rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6H9R~
        UTRACED("old",SmaxbuffW,strszW(SmaxbuffW));                    //~v6H9I~//~v6HsR~
        UTRACED("new",SmaxbuffW2,strszW(SmaxbuffW2));                    //~v6H9I~//~v6HsR~
        if (!rc)                                                   //~v6w0R~
    	    rc=tryMoveFileForReservedNameW(fnmoldW,fnmnewW,rc);    //~v6w0I~
        if (!rc)                                                   //~v6H9I~
        	if (lasterr==ERROR_INVALID_NAME) //123                 //~v6H9I~
		    	errno=EINVAL;    //notify to caller                //~v6H9I~
    }                                                              //~v6w0I~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v6u9R~
    return rc;                                                     //~v6u9R~
}//uMoveFileW                                                      //~v6u9R~
//**************************************************************** //~v6u9R~
//*MoveFileEx                                                      //~v6u9R~
//**************************************************************** //~v6u9R~
BOOL uMoveFileExW(char *Pold,char *Pnew,DWORD Pflags,int Popt)     //~v6u9R~
{                                                                  //~v6u9R~
    int rc=0,rc2,opt,ucsctro,ucsctrn;                              //~v6u9R~
    int lasterr;                                                   //~v6HnI~
//  UWCH  fnmoldW[_MAX_PATHWC];                                    //~v6u9R~//~v6H9R~
//  UWCH  fnmnewW[_MAX_PATHWC];                                    //~v6u9R~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH  fnmoldW[_MAX_PATHWC_LONG];                               //~v6H9I~
    UWCH  fnmnewW[_MAX_PATHWC_LONG];                               //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *fnmoldW;                                                 //~v6HsI~
    UWCH *fnmnewW;                                                 //~v6HsI~
#endif                                                             //~v6HsI~
//************************                                         //~v6u9R~
	UTRACEP("%s:opt=%x,flag=%x,old=%s,new=%s\n",UTT,Popt,Pflags,Pold,Pnew);       //~v6u9R~//~v6HnR~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    fnmoldW=SmaxbuffW;                                             //~v6HsI~
    fnmnewW=SmaxbuffW2;                                            //~v6HsI~
#endif                                                             //~v6HsI~
    opt=0;//drop UD                                                //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
    rc2=ufilecvUD2WCnopath(opt,Pold,fnmoldW,sizeof(fnmoldW),&ucsctro);//strz out//~v6u9R~
#else                                                              //~v6HsI~
    rc2=ufilecvUD2WCnopath(opt,Pold,fnmoldW,MAXBUFFSZ,&ucsctro);//strz out//~v6HsR~
#endif                                                             //~v6HsI~
    if (rc2<UDRC_ERR)                                              //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
    	rc2=ufilecvUD2WCnopath(opt,Pnew,fnmnewW,sizeof(fnmnewW),&ucsctrn);//~v6u9R~
#else                                                              //~v6HsI~
    	rc2=ufilecvUD2WCnopath(opt,Pnew,fnmnewW,MAXBUFFSZ,&ucsctrn);//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc2<UDRC_ERR)                                              //~v6u9R~
    {                                                              //~v6HnI~
	    rc=MoveFileExW(fnmoldW,fnmnewW,Pflags);                    //~v6u9R~
        lasterr=GetLastError();                                    //~v6HnI~
    	UTRACEP("%s:rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());                                  //~v6u9R~//~v6HnR~
        if (!rc)                                                   //~v6HnI~
        {                                                          //~v6HnI~
        	SmovefileExflag=Pflags;	//parm                         //~v6HnI~//~v6HsR~
		    rc=tryMoveFileForReservedNameW(fnmoldW,fnmnewW,rc);    //~v6HnI~
        	SmovefileExflag=0;	//parm                             //~v6HnI~//~v6HsR~
        }                                                          //~v6HnI~
        if (!rc)                                                   //~v6HnI~
        	if (lasterr==ERROR_INVALID_NAME) //123                 //~v6HnI~
		    	errno=EINVAL;    //notify to caller                //~v6HnI~
    }                                                              //~v6HnI~
    return rc;                                                     //~v6u9R~
}//uMoveFileExW                                                    //~v6u9R~
//**************************************************************** //~v6u9R~
//*uCreateFileW                                                    //~v6u9R~//~v6y7R~
//**************************************************************** //~v6u9R~
HANDLE uCreateFileW(const char *Pfnm,DWORD Pacc,DWORD Pshare,LPSECURITY_ATTRIBUTES Psecattr,DWORD Pdisp,DWORD Pattr,HANDLE Phtemp,int Popt)//~v6u9R~
{                                                                  //~v6u9R~
    int rc=0,opt,ucsctr;                                           //~v6u9R~
//  UWCH  fnmW[_MAX_PATHWC];                                       //~v6u9R~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH  fnmW[_MAX_PATHWC_LONG];                                  //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *fnmW;                                                    //~v6HsI~
#endif                                                             //~v6HsI~
    HANDLE hdir;                                                   //~v6u9R~
//************************                                         //~v6u9R~
	UTRACEP("%s:opt=%x,fnm=%s\n",UTT,Popt,Pfnm);                   //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    fnmW=SmaxbuffW;                                                //~v6HsI~
#endif                                                             //~v6HsI~
    opt=0;//drop UD                                                //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,(char*)Pfnm,fnmW,sizeof(fnmW),&ucsctr);//strz out//~v6u9R~
#else                                                              //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,(char*)Pfnm,fnmW,MAXBUFFSZ,&ucsctr);//strz out//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc>=UDRC_ERR)                                              //~v6u9R~
    	hdir=INVALID_HANDLE_VALUE;                                 //~v6u9R~
    else                                                           //~v6u9R~
    {                                                              //~v6y4I~
//  	hdir=CreateFileW(fnmW,Pacc,Pshare,Psecattr,Pdisp,Pattr,Phtemp);//~v6u9R~//~v6y6R~
//  	if (hdir==INVALID_HANDLE_VALUE)                            //~v6y4I~//~v6y6R~
//  		hdir=tryCreateFileForReservedName(fnmW,Pacc,Pshare,Psecattr,Pdisp,Pattr,Phtemp);//~v6y4I~//~v6y6R~
    	hdir=tryCreateFileForReservedName(fnmW,Pacc,Pshare,Psecattr,Pdisp,Pattr,Phtemp);//~v6y6I~
    	if (hdir==INVALID_HANDLE_VALUE)                            //~v6y6I~
    		hdir=CreateFileW(fnmW,Pacc,Pshare,Psecattr,Pdisp,Pattr,Phtemp);//~v6y6I~
    }                                                              //~v6y4I~
    UTRACEP("%s:handle=%p\n",UTT,hdir);                            //~v6u9R~
    return hdir;                                                   //~v6u9R~
}//uCreateFileW                                                    //~v6u9R~
//**************************************************************** //~v6B1I~
//*native WinCreateFile                                            //~v6B1I~
//*Do not call UTRACE(cause infinite loop)!!                       //~v6B1I~
//**************************************************************** //~v6B1I~
HANDLE uCreateFileNative(const char *Pfnm,DWORD Pacc,DWORD Pshare,void* /*LPSECURITY_ATTRIBUTES*/ Psecattr,DWORD Pdisp,DWORD Pattr,HANDLE Phtemp)//~v6B1R~
{                                                                  //~v6B1I~
	return CreateFile(Pfnm,Pacc,Pshare,(LPSECURITY_ATTRIBUTES)Psecattr,Pdisp,Pattr,Phtemp);//~v6B1R~
}//uCreateFileNative                                               //~v6B1I~
//**************************************************************** //~v6u9R~
//*GetFileAttributesEx                                             //~v6u9R~
//**************************************************************** //~v6u9R~
BOOL uGetFileAttributesExW(const char *Pfnm,GET_FILEEX_INFO_LEVELS Pinfolvl,LPVOID Ppinfo,int Popt,UWCH *Poutucs2,int Pbuffsz,int *Ppucsctr)//~v6u9R~
{                                                                  //~v6u9R~
    BOOL rc;                                                       //~v6u9R~
    int opt,ucsctr,buffsz,*pucsctr;                                //~v6u9R~
//  UWCH  fnmW[_MAX_PATHWC],*pw;                                   //~v6u9R~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH  fnmW[_MAX_PATHWC_LONG],*pw;                              //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *fnmW,*pw;                                                //~v6HsI~
#endif                                                             //~v6HsI~
//************************                                         //~v6u9R~
	UTRACEP("%s:opt=%x,fnm=%s\n",UTT,Popt,Pfnm);                   //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    fnmW=SmaxbuffW;                                                //~v6HsI~
#endif                                                             //~v6HsI~
    opt=0;//drop UD                                                //~v6u9R~
    if (Poutucs2)                                                  //~v6u9R~
//  	pw=Poutucs2,buffsz=Pbuffsz,pucsctr=Ppucsctr;               //~v6u9R~//~v6HsR~
    	pw=Poutucs2,buffsz=Pbuffsz;                                //~v6HsI~
    else                                                           //~v6u9R~
    {                                                              //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
    	pw=fnmW,buffsz=sizeof(fnmW),pucsctr=&ucsctr;               //~v6u9R~
#else                                                              //~v6HsI~
//  	pw=fnmW,buffsz=MAXBUFFSZ,pucsctr=&ucsctr;                  //~v6HsR~
    	pw=fnmW,buffsz=MAXBUFFSZ;                                  //~v6HsI~
#endif                                                             //~v6HsI~
	}                                                              //~v6HsI~
    if (Ppucsctr)                                                  //~v6HsI~
        pucsctr=Ppucsctr;                                          //~v6HsI~
    else                                                           //~v6HsI~
    	pucsctr=&ucsctr;                                           //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,(char*)Pfnm,pw,buffsz,Ppucsctr);//strz out//~v6u9R~
    if (rc>=UDRC_ERR)                                              //~v6u9R~
    	rc=FALSE;                                                  //~v6u9R~
    else                                                           //~v6u9R~
    {                                                              //~v6HsI~
    	UTRACED("fnmw",pw,strszW(pw));                             //~v6HsI~
		rc=GetFileAttributesExW(pw,Pinfolvl,Ppinfo);               //~v6u9R~
        if (!rc)                                                   //~v6HsI~
		    rc=tryGetFileAttributesExW(pw,Pinfolvl,Ppinfo,rc);     //~v6HsI~
    }                                                              //~v6HsI~
    UTRACEP("%s:rc=%d,lasterr=%d\n",UTT,rc,GetLastError());        //~v6u9R~
    return rc;                                                     //~v6u9R~
}//uGetFileAttributesExW                                           //~v6u9R~
//**************************************************************** //~v6u9R~
//*GetDiskFreeSpace                                                //~v6u9R~
//**************************************************************** //~v6u9R~
BOOL uGetDiskFreeSpaceW(char *Pfnm,LPDWORD Psector,LPDWORD Pbyte,LPDWORD Pfree,LPDWORD Ptotal,int Popt)//~v6u9R~
{                                                                  //~v6u9R~
    BOOL rc;                                                       //~v6u9R~
    int opt,ucsctr;                                                //~v6u9R~
//  UWCH  fnmW[_MAX_PATHWC];                                       //~v6u9R~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH  fnmW[_MAX_PATHWC_LONG];                                  //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *fnmW;                                                    //~v6HsI~
#endif                                                             //~v6HsI~
//************************                                         //~v6u9R~
	UTRACEP("%s:opt=%x,fnm=%s\n",UTT,Popt,Pfnm);                   //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    fnmW=SmaxbuffW;                                                //~v6HsI~
#endif                                                             //~v6HsI~
    opt=0;//drop UD                                                //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,(char*)Pfnm,fnmW,sizeof(fnmW),&ucsctr);//strz out//~v6u9R~
#else                                                              //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,(char*)Pfnm,fnmW,MAXBUFFSZ,&ucsctr);//strz out//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc>=UDRC_ERR)                                              //~v6u9R~
    	rc=FALSE;                                                  //~v6u9R~
    else                                                           //~v6u9R~
    {                                                              //~v6HsI~
		rc=GetDiskFreeSpaceW(fnmW,Psector,Pbyte,Pfree,Ptotal);     //~v6u9R~
        if (!rc)                                                   //~v6HsI~
		    rc=tryGetDiskFreeSpaceW(fnmW,Psector,Pbyte,Pfree,Ptotal,rc);//~v6HsI~
    }                                                              //~v6HsI~
    UTRACEP("%s:rc=%d,lasterr=%d,sect=%x,byte=%x,free=%x,total=%x\n",UTT,rc,GetLastError(),*Psector,*Pbyte,*Pfree,*Ptotal);        //~v6u9R~//~v6HsR~
    return rc;                                                     //~v6u9R~
}//uGetDiskFreeSpaceW                                              //~v6u9R~
//***************************************************************
//redirect fopen to _wfopen
//set EINVAL if parm err
//***************************************************************
#ifdef PUSH_FOPEN
	#pragma pop_macro("fopen")
#else
	#undef fopen
#endif
FILE *ufopenW(int Popt,const char * Pfnm,const char * Popenopt)
{
	int opt,rc,ucsctr;                                             //~v6uaR~
    UWCH optw[8];
//  UWCH wkfnmw[_MAX_PATHWC];                                      //~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfnmw[_MAX_PATHWC_LONG];                                 //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkfnmw;                                                  //~v6HsI~
#endif                                                             //~v6HsI~
    FILE *fh;
    int swnoud=0,swlong;                                           //~v6HeR~
//*****************************
    UTRACEP("%s:fnm=%s\n",UTT,Pfnm);
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfnmw=SmaxbuffW;                                              //~v6HsI~
#endif                                                             //~v6HsI~
	if (!IS_UDMODE()                                               //~vaunR~
    ||  !strchr(Pfnm,UD_NOTLC))                                    //~vaunR~
    {
//  	return fopen(Pfnm,Popenopt);                               //~v6y2R~
//    	fh=fopen(Pfnm,Popenopt);                                   //~v6y2I~//~v6y5R~
//      if (!fh)                                                   //~v6y2I~//~v6y5R~
//      	fh=tryFopenForReservedName(Pfnm,Popenopt,fh);          //~v6y2R~//~v6y5R~
//        fh=tryFopenForReservedName(Pfnm,Popenopt,0);  //try for reserved name//~v6y5I~//~v6HeR~
//        if (!fh)                                                   //~v6y5I~//~v6HeR~
//            fh=fopen(Pfnm,Popenopt);                               //~v6y5I~//~v6HeR~
//        return fh;                                                 //~v6y2I~//~v6HeR~
		swnoud=1;                                                  //~v6HeI~
    }
    UstrncpyZW_ASCII(optw,Popenopt,sz2ctrW(sizeof(optw)));         //~v6u9R~
    opt=0; 	//drop UD                                              //~v6uaI~
//  rc=ufilecvUD2WC(opt,(char*)Pfnm,wkfnmw,sizeof(wkfnmw),&ucsctr,NULL/*pathtbl*/,0/*pathtblsz*/,NULL/*pathctr*/);//~v6uaR~//~vaudR~
#ifdef BBB                                                         //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,(char*)Pfnm,wkfnmw,sizeof(wkfnmw),&ucsctr);//for profile record file no path sepc chk//~vaudI~
#else                                                              //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,(char*)Pfnm,wkfnmw,MAXBUFFSZ,&ucsctr);//for profile record file no path sepc chk//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc>=UDRC_ERR)                                              //~v6uaR~
    {
    	errno=EINVAL;
    	return NULL;
    }
    swlong=IS_WIN_LONGNAME_PREFIX(wkfnmw);                         //~v6HeR~
    if (swnoud && !swlong)                                         //~v6HeI~
    {                                                              //~v6HeI~
        fh=tryFopenForReservedName(Pfnm,Popenopt,0);  //try for reserved name//~v6HeI~
//    if (fh!=TRYRC_RSVNAME)		// (FILE*)(-3) \\.\ failed by ascii api//~v6HnR~
      if (!SswRsvNameTryFailed)                                    //~v6HnI~
      {                                                            //~v6HnI~
        if (!fh)                                                   //~v6HeI~
        {                                                          //~v6HhI~
            fh=fopen(Pfnm,Popenopt);                               //~v6HeI~
    		UTRACEP("%s:fh=%x errno=%d,lasterr=%d,fnm=%s\n",UTT,fh,errno,GetLastError(),Pfnm);              //~v6HhR~//~v6HnR~//~v6HhR~
		    UTRACED("Pfnm",Pfnm,strlen(Pfnm));                     //~v6HnI~
    	}                                                          //~v6HhI~
        return fh;                                                 //~v6HeI~
      }                                                            //~v6HnI~
      SswRsvNameTryFailed=0;                                       //~v6HnI~
    }                                                              //~v6HeI~
//  fh=_wfopen(wkfnmw,optw); //errno=2 for file not found and path not found//~v6y5R~
//  if (!fh)                                                       //~v6y2I~//~v6y5R~
//      fh=tryWfopenForReservedName(wkfnmw,optw);                  //~v6y2I~//~v6y5R~
    fh=tryWfopenForReservedName(wkfnmw,optw);                      //~v6y5I~
    if (!fh)                                                       //~v6y5I~
    {                                                              //~v6HeI~
#ifdef AAA                                                         //~v6HnI~
	  if (swlong)                                                  //~v6HeR~
		fh=ufopenWLong(0,wkfnmw,optw);                             //~v6HeI~
      else                                                         //~v6HeI~
#endif                                                             //~v6HnI~
		fh=_wfopen(wkfnmw,optw); //errno=2 for file not found and path not found//~v6y5I~
	    UTRACEP("%s:_wfopen fh=%p,errno=%d,lasterr=%d\n",UTT,fh,errno,GetLastError());//~v6HnI~
	    UTRACED("wkfnmw",wkfnmw,strszW(wkfnmw));                   //~v6HnI~
    }                                                              //~v6HeI~
    UTRACEP("%s:fh=%p,errno=%d,lasterr=%d\n",UTT,fh,errno,GetLastError());
//  errno=GetLastError();
    return fh;
}//ufopenW
//***************************************************************  //~v6B1I~
//Native fopen                                                     //~v6B1I~
//Don't include UTRACE!!                                           //~v6B1I~
//***************************************************************  //~v6B1I~
FILE *ufopenNative(const char * Pfnm,const char * Popenopt)        //~v6B1I~
{                                                                  //~v6B1I~
	return fopen(Pfnm,Popenopt);                                   //~v6B1I~
}//ufopenNative                                                    //~v6B1I~
//***************************************************************  //~v6u9R~
//redirect remove                                                  //~v6u9R~
//set EINVAL if parm err                                           //~v6u9R~
//***************************************************************  //~v6u9R~
#ifdef PUSH_REMOVE                                                 //~v6u9R~
	#pragma pop_macro("remove")                                    //~v6u9R~
#else                                                              //~v6u9R~
	#undef remove                                                  //~v6u9R~
#endif                                                             //~v6u9R~
int uremoveW(int Popt,char * Pfnm)                                 //~v6u9R~
{                                                                  //~v6u9R~
	int rc,ucsctr,opt;                                             //~v6u9R~
//  UWCH wkfnmw[_MAX_PATHWC];                                      //~v6u9R~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfnmw[_MAX_PATHWC_LONG];                                 //~v6H9R~
#else                                                              //~v6HsI~
    UWCH *wkfnmw;                                                  //~v6HsI~
#endif                                                             //~v6HsI~
//  int longfnm;                                                //~v6H9R~//~v6HaR~//~v6HcR~
    int swnoud=0,swlong;                                           //~v6HeI~
//*****************************                                    //~v6u9R~
    UTRACEP("%s:fnm=%s\n",UTT,Pfnm);                               //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfnmw=SmaxbuffW;                                              //~v6HsI~
#endif                                                             //~v6HsI~
//  longfnm=IS_WIN_LONGPATH(Pfnm);                                 //~v6HaR~//~v6HcR~
//if (!longfnm)                                      //~v6H9R~     //~v6HaR~//~v6HcR~
    if (!IS_UDMODE()                                              //~v6u9I~//~vaunR~//~v6u9R~//~v6HcR~//~v6HeR~
    ||  !strchr(Pfnm,UD_NOTLC))                                    //~vaunR~//~v6HcR~//~v6HeR~
    {                                                              //~v6u9R~//~v6HcR~//~v6HeR~
//  	return remove(Pfnm);                                       //~v6w0R~
//  	rc=remove(Pfnm);                                           //~v6w0I~//~v6HcR~
//      if (rc)                                                    //~v6w0R~//~v6HcR~
//  		rc=tryRemoveForReservedName(Pfnm,rc);                  //~v6w0I~//~v6HcR~
//      return rc;                                                 //~v6w0I~//~v6HcR~
		swnoud=1;                                                  //~v6HeI~
    }                                                              //~v6u9R~//~v6HcR~//~v6HeR~
    opt=0; 	//drop UD                                              //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,Pfnm,wkfnmw,sizeof(wkfnmw),&ucsctr);//for profile record file no path sepc chk//~v6u9R~
#else                                                              //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,Pfnm,wkfnmw,MAXBUFFSZ,&ucsctr);//for profile record file no path sepc chk//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc>=UDRC_ERR)                                              //~v6u9R~
    {                                                              //~v6u9R~
    	errno=EINVAL;                                              //~v6u9R~
    	return -1;                                                 //~v6u9R~
    }                                                              //~v6u9R~
    swlong=IS_WIN_LONGNAME_PREFIX(wkfnmw);                         //~v6HeI~
    if (swnoud && !swlong)                                         //~v6HeI~
    {                                                              //~v6HeI~
    	rc=remove(Pfnm);                                           //~v6HeI~
        if (rc)                                                    //~v6HeI~
        {                                                          //~v6HnI~
    		rc=tryRemoveForReservedName(Pfnm,rc);                  //~v6HeI~
        	UTRACEP("%s:after try rsv rc=%d,errno=%d,lasterr=%d,Sswrsvnametried=%d\n",UTT,rc,errno,GetLastError(),SswRsvNameTryFailed);//~v6HnI~
        }                                                          //~v6HnI~
      if (!SswRsvNameTryFailed)                                    //~v6HnI~
        return rc;                                                 //~v6HeI~
	    SswRsvNameTryFailed=0;                                     //~v6HnI~
    }                                                              //~v6HeI~
//  rc=_wremove((const wchar_t*)wkfnmw);                           //~v6u9R~//~v6H9R~
#ifdef AAA                                                         //~v6HnI~
    rc=DeleteFileW(wkfnmw);                                        //~v6H9M~
    UTRACEP("%s:DeleteFile rc bool=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6H9M~//~v6HnR~
    if (rc)                                                        //~v6H9M~
    	rc=0;                                                      //~v6H9M~
    else                                                           //~v6H9M~
    {                                                              //~v6HaI~
    	rc=GetLastError();                                         //~v6H9M~//~v6HaR~
    }                                                              //~v6HaI~
#else                                                              //~v6HnI~
	rc=_wremove((const wchar_t*)wkfnmw);                           //~v6HnI~
    UTRACEP("%s:_wremove rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
    UTRACED("_wremove wkfnmw\n",wkfnmw,strszW(wkfnmw));            //~v6HnI~
#endif                                                             //~v6HnI~
    if (rc)                                                        //~v6y7I~
        rc=tryWremoveForReservedName(wkfnmw,rc);                   //~v6y7I~
    UTRACEP("%s:rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6u9R~
    return rc;                                                     //~v6u9R~
}//uremoveW                                                        //~v6w0R~
//***************************************************************  //~v6u9R~
//redirect rmdir                                                   //~v6u9R~
//set EINVAL if parm err                                           //~v6u9R~
//***************************************************************  //~v6u9R~
#ifdef PUSH_RMDIR                                                  //~v6u9R~
	#pragma pop_macro("rmdir")                                     //~v6u9R~
#else                                                              //~v6u9R~
	#undef rmdir                                                   //~v6u9R~
#endif                                                             //~v6u9R~
int urmdirW(int Popt,char * Pfnm)                                  //~v6u9R~
{                                                                  //~v6u9R~
	int rc,opt,ucsctr;                                             //~v6u9R~
//  int lasterr;                                                   //~v6HaI~//~v6HnR~
//  UWCH wkfnmw[_MAX_PATHWC];                                      //~v6u9R~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfnmw[_MAX_PATHWC_LONG];                                 //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkfnmw;                                                  //~v6HsI~
#endif                                                             //~v6HsI~
    int swnoud=0,swlong;                                           //~v6HeI~
//*****************************                                    //~v6u9R~
    UTRACEP("%s:fnm=%s\n",UTT,Pfnm);                               //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfnmw=SmaxbuffW;                                              //~v6HsI~
#endif                                                             //~v6HsI~
    if (!IS_UDMODE()                                              //~v6u9I~//~vaunR~//~v6u9R~//~v6H9R~//~v6HeR~
    ||  !strchr(Pfnm,UD_NOTLC))                                    //~vaunR~//~v6H9R~//~v6HeR~
    {                                                              //~v6u9R~//~v6H9R~//~v6HeR~
//  	return _rmdir(Pfnm);                                       //~v6u9R~//~v6H9R~//~v6HeR~
		swnoud=1;                                                  //~v6HeI~
    }                                                              //~v6u9R~//~v6H9R~//~v6HeR~
  	opt=UFCVO_DIRPATH; //    0x010000       //path is dir path(max:248)//~v6HgI~
#ifdef BBB                                                         //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,Pfnm,wkfnmw,sizeof(wkfnmw),&ucsctr);//for profile record file no path sepc chk//~v6u9R~
#else                                                              //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,Pfnm,wkfnmw,MAXBUFFSZ,&ucsctr);//for profile record file no path sepc chk//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc>=UDRC_ERR)                                              //~v6u9R~
    {                                                              //~v6u9R~
    	errno=EINVAL;                                              //~v6u9R~
    	return -1;                                                 //~v6u9R~
    }                                                              //~v6u9R~
    swlong=IS_WIN_LONGNAME_PREFIX(wkfnmw);                         //~v6HeI~
    if (swnoud && !swlong)                                         //~v6HeI~
    {                                                              //~v6HeI~
//  	return _rmdir(Pfnm);                                       //~v6HeI~//~v6HnR~
    	rc=_rmdir(Pfnm);                                           //~v6HnI~
        UTRACEP("%s:_rmdir rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
    	UTRACED("Pfnm\n",Pfnm,strlen(Pfnm));                       //~v6HnR~
        if (rc)                                                    //~v6HnI~
        {                                                          //~v6HnI~
    		rc=tryRmdirForReservedName(Pfnm,rc);                   //~v6HnI~
        	UTRACEP("%s:after try rsv rc=%d,errno=%d,lasterr=%d,Sswrsvnametried=%d\n",UTT,rc,errno,GetLastError(),SswRsvNameTryFailed);//~v6HnI~
        }                                                          //~v6HnI~
      if (!SswRsvNameTryFailed)                                    //~v6HnI~
        return rc;                                                 //~v6HnI~
	    SswRsvNameTryFailed=0;                                     //~v6HnI~
    }                                                              //~v6HeI~
//  rc=_wrmdir((const wchar_t*)wkfnmw);                            //~v6u9R~//~v6H9R~
#ifdef AAA                                                         //~v6HnI~
    rc=RemoveDirectoryW(wkfnmw);                                   //~v6H9I~
    UTRACEP("%s:RemoveDirectory rc=bool=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
    UTRACED("wkfnmw\n",wkfnmw,ucsctr);                             //~v6HnI~
    if (!rc && !errno)                                             //~v6HaI~
    {                                                              //~v6HaI~
        lasterr=GetLastError();                                    //~v6HaI~
        if (lasterr==ERROR_PATH_NOT_FOUND)                         //~v6HaI~
        	errno=ENOENT;                                          //~v6HaI~
    }                                                              //~v6HaI~
    UTRACEP("%s:boolean rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6H9I~
    rc=rc ? 0 : -1;                                                //~v6H9I~
#else                                                              //~v6HnI~
	rc=_wrmdir((const wchar_t*)wkfnmw);                            //~v6HnI~
    UTRACEP("%s:_wrmdir rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
    UTRACED("wkfnmw\n",wkfnmw,strszW(wkfnmw));                     //~v6HnI~
    if (rc)                                                        //~v6HsI~
        rc=tryWRmdirForReservedName(wkfnmw,rc);                    //~v6HsI~
#endif                                                             //~v6HnI~
    return rc;                                                     //~v6u9R~
}//urmdirW                                                         //~v6u9R~
//***************************************************************  //~v6u9R~
//redirect mkdir                                                   //~v6u9R~
//set EINVAL if parm err                                           //~v6u9R~
//***************************************************************  //~v6u9R~
#ifdef PUSH_MKDIR                                                  //~v6u9R~//~v6yeR~
	#pragma pop_macro("mkdir")                                     //~v6u9R~
#else                                                              //~v6u9R~
	#undef mkdir                                                   //~v6u9R~
#endif                                                             //~v6u9R~
int umkdirW(int Popt,char * Pfnm)                                  //~v6u9R~
{                                                                  //~v6u9R~
	int rc,opt,ucsctr;                                             //~v6u9R~
//    UWCH wkfnmw[_MAX_PATHWC];                                      //~v6u9R~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
      UWCH wkfnmw[_MAX_PATHWC_LONG];                               //~v6H9I~
#else                                                              //~v6HsI~
      UWCH *wkfnmw;                                                //~v6HsI~
#endif                                                             //~v6HsI~
    int swnoud=0,swlong;                                           //~v6HeI~
//*****************************                                    //~v6u9R~
    UTRACEP("%s:fnm=%s\n",UTT,Pfnm);                               //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
      wkfnmw=SmaxbuffW;                                            //~v6HsI~
#endif                                                             //~v6HsI~
	if (!IS_UDMODE()                                               //~v6u9R~
    ||  !strchr(Pfnm,UD_NOTLC))                                    //~v6u9R~
    {                                                              //~v6u9R~
//  	return _mkdir(Pfnm);                                       //~v6u9R~//~v6yeR~
//        rc=_mkdir(Pfnm);                                           //~v6yeI~//~v6HeR~
//        if (rc)                                                    //~v6yeI~//~v6HeR~
//            rc=tryMkdirForReservedName(Pfnm,rc);                   //~v6yeI~//~v6HeR~
//        return rc;                                                 //~v6yeI~//~v6HeR~
		swnoud=1;                                                  //~v6HeI~
    }                                                              //~v6u9R~
    opt=UFCVO_DIRPATH;       //path is dir path(max:248)           //~v6HgR~
#ifdef BBB                                                         //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,Pfnm,wkfnmw,sizeof(wkfnmw),&ucsctr);//for profile record file no path sepc chk//~v6u9R~
#else                                                              //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,Pfnm,wkfnmw,MAXBUFFSZ,&ucsctr);//for profile record file no path sepc chk//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc>=UDRC_ERR)                                              //~v6u9R~
    {                                                              //~v6u9R~
    	errno=EINVAL;                                              //~v6u9R~
    	return -1;                                                 //~v6u9R~
    }                                                              //~v6u9R~
    swlong=IS_WIN_LONGNAME_PREFIX(wkfnmw);                         //~v6HeI~
    if (swnoud && !swlong)                                         //~v6HeI~
    {                                                              //~v6HeI~
    	UTRACEP("%s:_mkdir rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HeI~
//      rc=_mkdir(Pfnm);                                           //~v6HeR~
		rc=_wmkdir((const wchar_t*)wkfnmw);                        //~v6HeI~
    	UTRACEP("%s:_wmkdir rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HeR~
        if (rc)                                                    //~v6HeI~
            rc=tryMkdirForReservedName(Pfnm,rc);                   //~v6HeI~
      if (!SswRsvNameTryFailed)                                    //~v6HnI~
        return rc;                                                 //~v6HeI~
	    SswRsvNameTryFailed=0;                                     //~v6HnI~
    }                                                              //~v6HeI~
//  rc=_wmkdir((const wchar_t*)wkfnmw);                            //~v6u9R~//~v6HeR~
#ifdef AAA                                                         //~v6HnI~
    rc=CreateDirectoryW(wkfnmw,NULL/*security*/);                  //~v6HeR~
    UTRACEP("%s:CreateDirectory rc=%d,lasterr=%d\n",UTT,rc,GetLastError());//~v6HeI~
    if (!rc)                                                       //~v6HeI~
    	rc=GetLastError();                                         //~v6HeI~
    else                                                           //~v6HgI~
    	rc=0;                                                      //~v6HgI~
#else     //need errno                                             //~v6HnI~
    rc=_wmkdir((const wchar_t*)wkfnmw);                            //~v6HnI~
    UTRACEP("%s:_wmkdir rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
    UTRACED("wkfnmw",wkfnmw,strszW(wkfnmw));                       //~v6HnI~
#endif                                                             //~v6HnI~
    if (rc)                                                        //~v6yeI~
    	rc=tryWMkdirForReservedName(wkfnmw,rc);                    //~v6yeR~//~v6HnR~
    UTRACEP("%s:rc=%d,lasterr=%d\n",UTT,rc,GetLastError());//~v6u9R~//~v6HeR~
    return rc;                                                     //~v6u9R~
}//umkdirW                                                         //~v6u9R~
//***************************************************************  //~v6u9R~
//redirect chdir                                                   //~v6u9R~
//set EINVAL if parm err                                           //~v6u9R~
//!!SetCurrentDirectory dose not support \\.\ and max path is _MAX_PATH-2(for last \ to be appended)//~v6HgI~
//***************************************************************  //~v6u9R~
#ifdef PUSH_CHDIR                                                  //~v6u9R~//~v6yeR~
	#pragma pop_macro("chdir")                                     //~v6u9R~
#else                                                              //~v6u9R~
	#undef chdir                                                   //~v6u9R~
#endif                                                             //~v6u9R~
int uchdirW(int Popt,char * Pfnm)                                  //~v6u9R~
{                                                                  //~v6u9R~
	int rc,opt,ucsctr;                                             //~v6u9R~
    int swnoud=0,swlong;                                           //~v6HnI~
//  UWCH wkfnmw[_MAX_PATHWC];                                      //~v6u9R~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfnmw[_MAX_PATHWC_LONG];                                 //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkfnmw;                                                  //~v6HsI~
#endif                                                             //~v6HsI~
//*****************************                                    //~v6u9R~
    UTRACEP("%s:fnm=%s\n",UTT,Pfnm);                               //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfnmw=SmaxbuffW;                                              //~v6HsI~
#endif                                                             //~v6HsI~
    SlastReservedNameDriveLetter=0;                                //~v6yhI~
	if (!IS_UDMODE()                                               //~v6u9R~
    ||  !strchr(Pfnm,UD_NOTLC))                                    //~v6u9R~
    {                                                              //~v6u9R~
//  	return _chdir(Pfnm);                                       //~v6u9R~//~v6y9R~
//  	rc=_chdir(Pfnm); //rc=0:ok,-1:err                          //~v6y9I~//~v6HnR~
//      if (rc)                                                    //~v6y9I~//~v6HnR~
//  		rc=tryChdirForReservedName(Pfnm,rc);                   //~v6y9I~//~v6HnR~
//      return rc;                                                 //~v6y9I~//~v6HnR~
		swnoud=1;
    }                                                              //~v6u9R~
    opt=0; 	//drop UD                                              //~v6u9R~
#ifdef BBB                                                         //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,Pfnm,wkfnmw,sizeof(wkfnmw),&ucsctr);//for profile record file no path sepc chk//~v6u9R~
#else                                                              //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,Pfnm,wkfnmw,MAXBUFFSZ,&ucsctr);//for profile record file no path sepc chk//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc>=UDRC_ERR)                                              //~v6u9R~
    {                                                              //~v6u9R~
    	errno=EINVAL;                                              //~v6u9R~
    	return -1;                                                 //~v6u9R~
    }                                                              //~v6u9R~
    swlong=IS_WIN_LONGNAME_PREFIX(wkfnmw);
    if (swnoud && !swlong)
    {
    	rc=_chdir(Pfnm); //rc=0:ok,-1:err
	    UTRACEP("%s:_chdir rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
        if (rc)
			rc=tryChdirForReservedName(Pfnm,rc);
      if (!SswRsvNameTryFailed)                                    //~v6HnI~
        return rc;
	    SswRsvNameTryFailed=0;                                     //~v6HnI~
    }
    rc=_wchdir((const wchar_t*)wkfnmw);                            //~v6u9R~
    UTRACEP("%s:_wchdir rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
    UTRACED("wkfnmw",wkfnmw,strszW(wkfnmw));                       //~v6HnI~
    if (rc)                                                        //~v6yeI~
		rc=tryWChdirForReservedName(wkfnmw,rc);                    //~v6yeR~//~v6HnR~
    UTRACEP("%s:rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6u9R~
    return rc;                                                     //~v6u9R~
}//uchdirW                                                         //~v6u9R~
//***************************************************************
//redirect _fullpath to _wfullpath
//set EINVAL if parm err
//***************************************************************
#ifdef PUSH_FULLPATH
	#pragma pop_macro("_fullpath")
#else
	#undef _fullpath
#endif
char *u_fullpathW(int Popt,char * Pfpath,const char * Prpath,size_t Pbuffsz)
{
	int opt,rc,ucsctr,charctr;                                     //~v6uaR~
#ifdef BBB                                                         //~v6HsI~
//  UWCH wkfnmw[_MAX_PATHWC],*pw;                                  //~v6H9R~
    UWCH wkfnmw[_MAX_PATHWC_LONG],*pw;                             //~v6H9I~
//  UWCH wkfpathw[_MAX_PATHWC];                                    //~v6H9R~
    UWCH wkfpathw[_MAX_PATHWC_LONG];                               //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkfnmw,*pw;                                              //~v6HsI~
    UWCH *wkfpathw;                                                //~v6HsI~
#endif                                                             //~v6HsI~
    char *pc;
//  char wkfpathc[_MAX_PATH];                                      //~v6yeR~
//  char wkdrive[_MAX_PATH];                                          //~v6yeI~//~v6yhR~//~v6HnR~
    char wkdrive[_MAX_PATH_LONG];                                  //~v6HnI~
//*****************************
    UTRACED("inp",Prpath,strlen(Prpath));
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfnmw=SmaxbuffW;                                              //~v6HsR~
    wkfpathw=SmaxbuffW2;                                           //~v6HsR~
#endif                                                             //~v6HsI~
#ifdef AAA                                                         //~v6HnI~
    if (Pbuffsz>_MAX_PATH)	//assume long pathg                    //~v6HaI~
		return u_fullpathWLong(Popt,Pfpath,NULL/*Pfpathw*//*option*/,Prpath,Pbuffsz,NULL/*Ppucsctr*//*option*/);//~v6HaI~
#endif                                                                   //~v6HaI~//~v6HnR~
//  if (!IS_UDMODE())   //even not UD excute fullpathW for intermediate path//~v6u9R~//~v6HnR~
    if (!IS_UDMODE()    //even not UD excute fullpathW for intermediate path//~v6HnI~
    ||  !strchr(Prpath,UD_NOTLC))                                  //~v6HnI~
    {                                                              //~v6HnI~
    	pc=_fullpath(Pfpath,Prpath,Pbuffsz);                       //~v6HnR~
    	if (pc && IS_RESERVED_NAME(pc))                            //~v6HnI~
    	{                                                          //~v6HnI~
			if (adjustReservedName((char *)Prpath,Pfpath,Pbuffsz)) //~v6HnR~
            	pc=0;                                              //~v6HnI~
            else                                                   //~v6HnI~
            {                                                      //~v6HnI~
        		if (IS_RESERVED_NAME(Pfpath))                      //~v6HnI~
	    			strcpy(Pfpath,Pfpath+RESERVED_NAMEID_CTR);     //~v6HnI~
                pc=Pfpath;                                         //~v6HnR~
            }                                                      //~v6HnI~
        }                                                          //~v6HnI~
        else                                                       //~v6HnI~
        {                                                          //~v6HnI~
            if (!pc)                                               //~v6HnI~
	  			SswRsvNameTryFailed=1;	//try _wfullpath           //~v6HnI~
        }                                                          //~v6HnI~
        UTRACEP("%s:no ud out=%s\n",UTT,pc);                       //~v6HnI~
	  if (!SswRsvNameTryFailed)	//not longname err                 //~v6HnI~
        return pc;                                                 //~v6HnI~
	  SswRsvNameTryFailed=0;	//not longname err                 //~v6HnI~
    }                                                              //~v6HnI~
//    if (isPrintableASCIIstr((char*)Prpath))                        //~v6uaR~//~vaudR~
//        return _fullpath(Pfpath,Prpath,Pbuffsz);                   //~v6uaR~//~vaudR~
//  UTRACEP("_fullpath=%s\n",_fullpath(wkfpathc,Prpath,sizeof(wkfpathc)));//@@@test//~v6yeR~
    pc=NULL;
    *Pfpath=0;   //for err exit case                               //~v6BRR~
    for (;;)
    {
//        if (*Prpath=='\\') //@@@@test                              //~v6yeR~//~v6yhR~
//        {                                                          //~v6yeR~//~v6yhR~
////          wkwk[0]=ugetdrive();    //return @(_getdrive rc=0)     //~v6yeR~//~v6yhR~
//            wkwk[0]='g';    //return @(_getdrive rc=0)             //~v6yeI~//~v6yhR~
//            wkwk[1]=':';                                           //~v6yeR~//~v6yhR~
//            strcpy(wkwk+2,Prpath);                                 //~v6yeR~//~v6yhR~
//            Prpath=wkwk;                                           //~v6yeR~//~v6yhR~
//        }                                                          //~v6yeR~//~v6yhR~
        pc=adjustReservedNameRootDrive((char*)Prpath,wkdrive,sizeof(wkdrive));//~v6yhR~
        if (!pc)                                                   //~v6yhI~
            pc=(char*)Prpath;                                      //~v6yhI~
    	opt=UFCVO_KEEPUD;         //leave utf8OK threa             //~v6uaR~
//  	rc=ufilecvUD2WC(opt,(char*)Prpath,wkfnmw,sizeof(wkfnmw),&ucsctr,NULL/*pathtbl*/,0/*sizeof(wkpathtbl)*/,NULL/*&pathctr*/);//~v6uaR~//~v6yhR~
#ifdef BBB                                                         //~v6HsI~
    	rc=ufilecvUD2WC(opt,pc,wkfnmw,sizeof(wkfnmw),&ucsctr,NULL/*pathtbl*/,0/*sizeof(wkpathtbl)*/,NULL/*&pathctr*/);//~v6yhI~
#else                                                              //~v6HsI~
    	rc=ufilecvUD2WC(opt,pc,wkfnmw,MAXBUFFSZ,&ucsctr,NULL/*pathtbl*/,0/*sizeof(wkpathtbl)*/,NULL/*&pathctr*/);//~v6HsI~
#endif                                                             //~v6HsI~
    	if (rc>=UDRC_ERR)                                          //~v6uaR~
    	{
    		errno=EINVAL;
            pc=0;                                                  //~v6HnI~
    		break;
    	}
#ifdef BBB                                                         //~v6HsI~
    	pw=_wfullpath(wkfpathw,wkfnmw,sz2ctrW(sizeof(wkfpathw)));  //~v6uaR~
#else                                                              //~v6HsI~
    	pw=_wfullpath(wkfpathw,wkfnmw,sz2ctrW(MAXBUFFSZ));         //~v6HsI~
#endif                                                             //~v6HsI~
    	if (!pw)
        {                                                          //~v6H3I~
//  	    UWCH wkfpathwt[_MAX_PATHWC*2];                         //~v6H3R~
            UTRACEP("%s:errno=%d,lasterr=%d\n",UTT,errno,GetLastError());//~v6H3I~
//      	pw=_wfullpath(wkfpathwt,wkfnmw,sz2ctrW(sizeof(wkfpathwt)));           //@@@@test//~v6H3R~
//          UTRACEP("%s:pw=%p,errno=%d,lasterr=%d\n",UTT,pw,errno,GetLastError());//~v6H3R~
//          UTRACED("pw",pw,(int)sizeof(wkfpathwt));               //~v6H3R~
            pc=0;                                                  //~v6H3I~
    		break;
        }                                                          //~v6H3I~
		if (!memcmpW(wkfpathw,RESERVED_NAMEIDW,RESERVED_NAMEID_CTR)) //\\.\prn//~v6w0R~
        {                                                          //~v6HnI~
#ifdef BBB                                                         //~v6HsI~
          rc=                                                      //~v6HnI~
        	adjustReservedNameW(wkfnmw,wkfpathw,sizeof(wkfpathw)); //~v6w0R~
#else                                                              //~v6HsI~
          rc=adjustReservedNameW(wkfnmw,wkfpathw,MAXBUFFSZ);       //~v6HsR~
#endif                                                             //~v6HsI~
            if (rc)                                                //~v6HnI~
            {                                                      //~v6HnI~
	            pc=0;                                              //~v6HnI~
    			break;                                             //~v6HnI~
            }                                                      //~v6HnI~
	        if (IS_RESERVED_NAME(wkfpathw))                        //~v6HnI~
		    	strcpyW(wkfpathw,wkfpathw+RESERVED_NAMEID_CTR);    //~v6HnI~
//        else                                                       //~v6yeI~//~v6yhR~
//            adjustReservedNameWRoot(wkfnmw,wkfpathw,sizeof(wkfpathw));//~v6yeI~//~v6yhR~
		}                                                          //~v6HnI~
        opt=UFCVO_KEPTUD|UFCVO_NEW;    //chk and set UTF8WCSUBC if no ud was set//~v6uaR~
		rc=ufilecvWC2UD(opt,wkfpathw,Pfpath,Pbuffsz,&charctr,NULL/*wkpathtbl*/,0/*pathctr*/);//~v6uaR~
	    if (rc>=UDRC_ERR)  //1:detected utf7                       //~v6uaR~
    	{
	        pc=0;                                                  //~v6HnI~
    		errno=EINVAL;
	    	if (rc==UDRC_BUFFSHORTAGE)  //1:detected utf7          //~v6HsI~
				errno=ENAMETOOLONG;                                //~v6HsR~
    		break;
    	}
        pc=Pfpath;
	    UTRACED("outfpath",Pfpath,charctr);
        break;
	}
	UTRACEP("%s:rc=%p\n",UTT,pc);
    return pc;
}//u_fullpathW
#ifdef AAA                                                         //~v6HnI~
//***************************************************************  //~v6H9I~
//redirect _fullpath to _wfullpath for longname                    //~v6H9I~
//set EINVAL if parm err                                           //~v6H9I~
//***************************************************************  //~v6H9I~
char *u_fullpathWLong(int Popt,char * Pfpath,UWCH *Pfpathw/*option*/,const char * Prpath,size_t Pbuffsz,int *Ppucsctr/*option*/)//~v6H9R~
{                                                                  //~v6H9I~
	int opt,rc,ucsctr,charctr;                                     //~v6H9I~
//  UWCH wkfnmw[_MAX_PATHWC],*pw;                                  //~v6H9R~
//  UWCH wkfpathw[_MAX_PATHWC];                                    //~v6H9R~
    UWCH wkfnmw[_MAX_PATHWC_LONG],*pw;                             //~v6H9I~
    UWCH wkfpathw[_MAX_PATHWC_LONG];                               //~v6H9I~
    char *pc;                                                      //~v6H9I~
    char wkdrive[_MAX_PATH];                                       //~v6H9I~
//*****************************                                    //~v6H9I~
    UTRACED("inp",Prpath,strlen(Prpath));                          //~v6H9I~
//  if (!IS_UDMODE())   //even not UD excute fullpathW for intermediate path//~v6H9R~
//  	return _fullpath(Pfpath,Prpath,Pbuffsz);                   //~v6H9R~
    pc=NULL;                                                       //~v6H9I~
    *Pfpath=0;   //for err exit case                               //~v6H9I~
    if (Ppucsctr)                                                  //~v6H9I~
	    *Ppucsctr=0;                                               //~v6H9R~
    for (;;)                                                       //~v6H9I~
    {                                                              //~v6H9I~
        pc=adjustReservedNameRootDrive((char*)Prpath,wkdrive,sizeof(wkdrive));//~v6H9I~
        if (!pc)                                                   //~v6H9I~
            pc=(char*)Prpath;                                      //~v6H9I~
    	opt=UFCVO_KEEPUD;         //leave utf8OK threa             //~v6H9I~
    	rc=ufilecvUD2WC(opt,pc,wkfnmw,sizeof(wkfnmw),&ucsctr,NULL/*pathtbl*/,0/*sizeof(wkpathtbl)*/,NULL/*&pathctr*/);//~v6H9I~
    	if (rc>=UDRC_ERR)                                          //~v6H9I~
    	{                                                          //~v6H9I~
    		errno=EINVAL;                                          //~v6H9I~
    		break;                                                 //~v6H9I~
    	}                                                          //~v6H9I~
    	pw=_wfullpath(wkfpathw,wkfnmw,sz2ctrW(sizeof(wkfpathw)));  //~v6H9I~
    	if (!pw)                                                   //~v6H9I~
        {                                                          //~v6H9I~
            UTRACEP("%s:errno=%d,lasterr=%d\n",UTT,errno,GetLastError());//~v6H9I~
            pc=0;                                                  //~v6H9I~
    		break;                                                 //~v6H9I~
        }                                                          //~v6H9I~
        if (Pfpathw)                                               //~v6H9I~
        	strcpyW(Pfpathw,wkfpathw);                             //~v6H9I~
		if (!memcmpW(wkfpathw,RESERVED_NAMEIDW,RESERVED_NAMEID_CTR)) //\\.\prn//~v6H9I~
        	adjustReservedNameW(wkfnmw,wkfpathw,sizeof(wkfpathw)); //~v6H9I~
        opt=UFCVO_KEPTUD|UFCVO_NEW;    //chk and set UTF8WCSUBC if no ud was set//~v6H9I~
		rc=ufilecvWC2UD(opt,wkfpathw,Pfpath,Pbuffsz,&charctr,NULL/*wkpathtbl*/,0/*pathctr*/);//~v6H9I~
	    if (rc>=UDRC_ERR)  //1:detected utf7                       //~v6H9I~
    	{                                                          //~v6H9I~
    		errno=EINVAL;                                          //~v6H9I~
    		break;                                                 //~v6H9I~
    	}                                                          //~v6H9I~
        pc=Pfpath;                                                 //~v6H9I~
	 	if (Ppucsctr)                                              //~v6H9I~
        	*Ppucsctr=strctrW(wkfpathw);                           //~v6H9R~
	    UTRACED("outfpath",Pfpath,charctr);                        //~v6H9I~
        break;                                                     //~v6H9I~
	}                                                              //~v6H9I~
	UTRACEP("%s:rc=%p\n",UTT,pc);                                  //~v6H9I~
    return pc;                                                     //~v6H9I~
}//u_fullpathWLong                                                 //~v6H9R~
#endif //AAA                                                       //~v6HnI~
//***************************************************************  //~v6u9R~
//wsystem                                                          //~v6u9R~
//set EINVAL if parm err                                           //~v6u9R~
//***************************************************************  //~v6u9R~
int usystemW(int Popt,char *Pcmd)                                  //~v6u9R~
{                                                                  //~v6u9R~
	int opt,rc,ucsctr,cmdlen,cmdsz;                                //~v6u9R~
    UWCH *pcmdw;                                                   //~v6u9R~
//*****************************                                    //~v6u9R~
    UTRACED("inp",Pcmd,strlen(Pcmd));                              //~v6u9R~
	if (!IS_UDMODE()   //even not UD excute fullpathW for intermediate path//~v6u9R~
    ||  !strchr(Pcmd,UD_NOTLC))                                    //~v6u9R~
    {                                                              //~v7e0I~
		flushstreamw();                                            //~v7e0I~
    	return system(Pcmd);                                       //~v6u9R~
    }                                                              //~v7e0I~
    cmdlen=strlen(Pcmd);                                           //~v6u9R~
    cmdsz=ctr2szW(cmdlen+1);                                       //~v6u9R~
    pcmdw=umalloc(cmdsz);                                          //~v6u9R~
    opt=0; 	//drop UD                                              //~v6u9R~
    rc=ufilecvUD2WCnopath(opt,Pcmd,pcmdw,cmdsz,&ucsctr);//for profile record file no path sepc chk//~v6u9R~
    if (rc>=UDRC_ERR)                                              //~v6u9R~
    {                                                              //~v6u9R~
    	ufree(pcmdw);                                              //~v6u9R~
    	errno=EINVAL;                                              //~v6u9R~
    	return -1;                                                 //~v6u9R~
    }                                                              //~v6u9R~
    UTRACED("cmdw",pcmdw,ctr2szW(ucsctr));                         //~v6u9R~
	flushstreamw();                                                //~v7e0I~
    rc=_wsystem(pcmdw);                                            //~v6u9R~
    ufree(pcmdw);                                                  //~v6u9R~
	UTRACEP("%s:rc=%p\n",UTT,rc);                                  //~v6u9R~
    return rc;                                                     //~v6u9R~
}//usystemW                                                        //~v6u9R~
//*******************************************************          //~v6uaI~
//*set up FILEFINDBUF3 name/alias from Win32_FIND_DATAW            //~v6uaI~
//*******************************************************          //~v6uaI~
void ufilew_copyfstat_name(int Popt,LPWIN32_FIND_DATAW Pw32fd,FILEFINDBUF3 *Ppffb3)//~v6uaR~
{                                                                  //~v6uaI~
	int opt,rc2,ctr,wrtlen;                                        //~v6uaR~
//*************                                                    //~v6uaI~
//  memcpy(Ppffb3->cFileName,Pw32fd->cFileName,sizeof(Ppffb3->cFileName));//~v6uaI~
	ctr=strctrW(Pw32fd->cFileName);                                //~v6uaI~
    if (Popt & UFCVO_2UD)                                          //~v6uaI~
    {                                                              //~v6uaI~
    	opt=UFCVO_NEW;   //chk subchar by wc2cp                    //~v6uaR~
		rc2=ufilecvWC2UD(opt,Pw32fd->cFileName,Ppffb3->cFileName,sizeof(Ppffb3->cFileName),&wrtlen,NULL,0);//~v6uaR~
	    if (rc2==1)                                                //~v6uaI~
    	    Ppffb3->otherflag|=FFB3OF_SUBCHFNAME|FFB3OF_UDFMTFNAME;//~v6uaI~
    }                                                              //~v6uaI~
    else                                                           //~v6uaI~
    {                                                              //~v6uaI~
//  	opt=UFCVO_SETSUBCHRC|UFCVO_STRZ|UFCVO_BESTFIT;             //~v6uaR~
    	opt=UFCVO_SETSUBCHRC|UFCVO_STRZ;                           //~v6uaR~
		rc2=ufilecvucs2cpW(opt,Pw32fd->cFileName,ctr,Ppffb3->cFileName,sizeof(Ppffb3->cFileName),&wrtlen);//~v6uaR~
	    if (rc2==UCVEXTRC_SUBCH)                                   //~v6uaR~
    	    Ppffb3->otherflag|=FFB3OF_SUBCHFNAME;                  //~v6uaR~
    }                                                              //~v6uaI~
    UstrncpyZW(Ppffb3->cFileNameW,Pw32fd->cFileName,sizeof(Ppffb3->cFileNameW));//~v6uaI~
    Ppffb3->cFileNameWctr=ctr;                                     //~v6uaI~
    UTRACEP("%s:cFileName=%s\n",UTT,Ppffb3->cFileName);            //~v6uaR~
    if (*Pw32fd->cAlternateFileName)                               //~v6uaI~
    {                                                              //~v6uaI~
//      memcpy(Ppffb3->achName,Pw32fd->cAlternateFileName,sizeof(Ppffb3->achName));//~v6uaI~
        UstrncpyZW(Ppffb3->achNameW,Pw32fd->cAlternateFileName,sizeof(Ppffb3->achNameW));//~v6uaI~
        Ppffb3->achNameWctr=strctrW(Ppffb3->achNameW);             //~v6uaI~
        opt=UFCVO_SETSUBCHRC|UFCVO_STRZ|UFCVO_BESTFIT;             //~v6uaR~
//      opt=UFCVO_SETSUBCHRC|UFCVO_STRZ;                           //~v6uaR~
		rc2=ufilecvucs2cpW(opt,Pw32fd->cAlternateFileName,0/*ucsctr*/,Ppffb3->achName,sizeof(Ppffb3->achName),&wrtlen);//~v6uaI~
	    if (rc2==UCVEXTRC_SUBCH)                                   //~v6uaI~
    	    Ppffb3->otherflag|=FFB3OF_SUBCHALTNAME;                //~v6uaI~
    }                                                              //~v6uaI~
    else                                                           //~v6uaI~
    {                                                              //~v6uaI~
#ifdef AAA                                                         //~v6HdR~
//      strncpy(Ppffb3->achName,Pw32fd->cFileName,sizeof(Ppffb3->achName));//~v6uaI~
//      UstrncpyZW(Ppffb3->achNameW,Pw32fd->cFileName,sizeof(Ppffb3->achNameW));//~v6uaI~//~v6HbR~
        ctr=Ppffb3->cFileNameWctr;                                 //~v6HbR~
        if (ctr<MAXFILENAMEZ_FAT)   //<13    //8.3 with term null  //~v6HbI~
	        strcpyW(Ppffb3->achNameW,Pw32fd->cFileName);           //~v6HbR~
        else                                                       //~v6HbI~
        {                                                          //~v6HbI~
        	UstrncpyZWctr(Ppffb3->achNameW,Pw32fd->cFileName,MAXFILENAMEZ_FAT-2);   //=13-2     //8.3 with term null//~v6HbR~
        	strcatW(Ppffb3->achNameW,L"*");            //(11x)* pattern//~v6HbR~
        }                                                          //~v6HbI~
        Ppffb3->achNameWctr=strctrW(Ppffb3->achNameW);             //~v6uaI~
//      strncpy(Ppffb3->achName,Ppffb3->cFileName,sizeof(Ppffb3->achName));//~v6uaR~
        opt=UFCVO_SETSUBCHRC|UFCVO_STRZ|UFCVO_BESTFIT;             //~v6uaI~
//      opt=UFCVO_SETSUBCHRC|UFCVO_STRZ;                           //~v6uaI~
//  	rc2=ufilecvucs2cpW(opt,Pw32fd->cFileName,0/*ucsctr*/,Ppffb3->achName,sizeof(Ppffb3->achName),&wrtlen);//~v6uaI~//~v6HbR~
    	rc2=ufilecvucs2cpW(opt,Ppffb3->achNameW,0/*ucsctr*/,Ppffb3->achName,sizeof(Ppffb3->achName),&wrtlen);//~v6HbI~
//      strupr(Ppffb3->achName);                                   //~v6uaR~
#else                                                              //~v6HdI~
        Ppffb3->achNameWctr=0;                                     //~v6HdI~
    	*Ppffb3->achNameW=0;                                       //~v6HdI~
    	*Ppffb3->achName=0;                                        //~v6HdI~
#endif                                                             //~v6HdI~
    }                                                              //~v6uaI~
}//ufilew_copyfstat_name                                           //~v6uaI~
//******************************************************           //~v6uaI~
//ucs compare for dirsort                                          //~v6uaI~
//*type L/N/E                                                      //~v6uaI~
//******************************************************           //~v6uaI~
int ufilew_dircompW(int Ptype,PUDIRLIST Ppudl1,PUDIRLIST Ppudl2)   //~v6uaR~
{                                                                  //~v6uaI~
	UWCH *pw1,*pw2,*pwe1,*pwe2;                                    //~v6uaI~
    int rc=0;                                                      //~v6uaI~
//**********************                                           //~v6uaI~
    pw1=Ppudl1->nameW;                                             //~v6uaR~
    pw2=Ppudl2->nameW;                                             //~v6uaR~
    UTRACED("pw1",pw1,ctr2szW(Ppudl1->nameWctr));                  //~v6uaI~
    UTRACED("pw2",pw2,ctr2szW(Ppudl2->nameWctr));                  //~v6uaI~
	switch(Ptype)                                                  //~v6uaR~
    {                                                              //~v6uaI~
    case 'L': //full comp                                          //~v6uaI~
    	rc=stricmpW(pw1,pw2);                                      //~v6uaI~
    	break;                                                     //~v6uaI~
    case 'N': //1st name compare                                   //~v6uaI~
    	pwe1=strchrW(pw1,L'.');                                    //~v6uaI~
    	pwe2=strchrW(pw2,L'.');                                    //~v6uaI~
        if (pwe1)                                                  //~v6uaI~
        	*pwe1=0;                                               //~v6uaI~
        if (pwe2)                                                  //~v6uaI~
        	*pwe2=0;                                               //~v6uaI~
    	rc=stricmpW(pw1,pw2);                                      //~v6uaI~
        if (pwe1)                                                  //~v6uaI~
        	*pwe1=L'.';                                            //~v6uaI~
        if (pwe2)                                                  //~v6uaI~
        	*pwe2=L'.';                                            //~v6uaI~
        if (rc)                                                    //~v6uaI~
        	break;                                                 //~v6uaI~
        if (pwe1 && pwe2)                                          //~v6uaI~
	    	rc=stricmpW(pwe1,pwe2);                                //~v6uaI~
        else                                                       //~v6uaI~
        if (!pwe1)                                                 //~v6uaI~
        	rc=-1;                                                 //~v6uaR~
        else                                                       //~v6uaI~
			rc=1;                                                  //~v6uaI~
    	break;                                                     //~v6uaI~
    case 'E': //after 1st name                                     //~v6uaI~
    	pwe1=strchrW(pw1,L'.');                                    //~v6uaI~
    	pwe2=strchrW(pw2,L'.');                                    //~v6uaI~
        if (!pwe1 && !pwe2)                                        //~v6uaI~
        {                                                          //~v6uaI~
	    	rc=stricmpW(pw1,pw2);                                  //~v6uaI~
            break;                                                 //~v6uaI~
        }                                                          //~v6uaI~
        else                                                       //~v6uaI~
        if (pwe1 && pwe2)                                          //~v6uaI~
        {                                                          //~v6uaI~
	    	rc=stricmpW(pwe1,pwe2);                                //~v6uaI~
            if (rc)                                                //~v6uaI~
	            break;                                             //~v6uaI~
        	*pwe1=0;                                               //~v6uaI~
        	*pwe2=0;                                               //~v6uaI~
	    	rc=stricmpW(pw1,pw2);                                  //~v6uaI~
        	*pwe1=L'.';                                            //~v6uaI~
        	*pwe2=L'.';                                            //~v6uaI~
            break;                                                 //~v6uaI~
        }                                                          //~v6uaI~
        if (!pwe1)                                                 //~v6uaI~
        	rc=-1;                                                 //~v6uaR~
        else                                                       //~v6uaI~
			rc=1;                                                  //~v6uaI~
    	break;                                                     //~v6uaI~
    }                                                              //~v6uaI~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v6uaI~
    return rc;                                                     //~v6uaI~
}//ufilew_dircompW                                                 //~v6uaR~
//******************************************************           //~vaucI~
//set UTFCT_UTF8 for  DDfmt                                        //~vaucI~
//*int 0:all ascii,1:no ascii found,4:ovf                          //~vaucI~
//******************************************************           //~vaucI~
int ufilew_setctDD(int Popt,int Pcodetype,char *Pdddata,char *Pdddbcs,int Plen,char *Poutbuff,int Pbuffsz)//~vaucR~
{                                                                  //~vaucI~
	char *pc,*pcd,*pct;                                            //~vaucI~
    int resleno,rc=0,ii;                                           //~vaucR~
//******************************	                               //~vaucI~
	for (pct=Poutbuff,pc=Pdddata,pcd=Pdddbcs,ii=0,resleno=Pbuffsz;ii<Plen && resleno;pct++,pc++,pcd++,resleno--)//~vaucI~
    {                                                              //~vaucI~
    	if (*pcd)                                                  //~vaucI~
        {                                                          //~vaucI~
//      	*pct=Pcodetype;                                        //~vaucI~//~v6y2R~
        	*pct=(char)Pcodetype;                                  //~v6y2I~
            rc=1;                                                  //~vaucI~
        }                                                          //~vaucI~
        else                                                       //~vaucI~
    		*pct=0;                                                //~vaucI~
    }                                                      //~vaugI~//~vaucI~
    if (ii<Plen)                                                   //~vaucI~
    	rc=4;                                                      //~vaucI~
    return rc;                                                     //~vaucI~
}//ufilew_setctDD                                                  //~vaucI~
//***************************************************************  //~v6w0I~
//adjust for windows bug for reservedname                          //~v6w0I~
//return 0:replaced by fpath,1:err                                 //~v6w0R~
//Use Smaxbuff3/4                                                  //~v6HsI~
//***************************************************************  //~v6w0I~
int adjustReservedNameW(UWCH *Pfnm,UWCH *Pfpath,int Pbuffsz)       //~v6w0R~
{                                                                  //~v6w0I~
	UWCH *pws,*pwt,*pw;                                            //~v6w0R~
//  UWCH wkfpathw[_MAX_PATHWC*2];                                  //~v6w0I~//~v6H9R~
//  UWCH wkrpath[_MAX_PATHWC];                                     //~v6w0R~//~v6H9R~
//  UWCH wkrpathfp[_MAX_PATHWC];                                   //~v6w0R~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG*2];                             //~v6H9I~//~v6HnR~
    UWCH wkrpath[_MAX_PATHWC_LONG];                                //~v6H9I~//~v6HnR~
    UWCH wkrpathfp[_MAX_PATHWC_LONG];                              //~v6H9I~//~v6HnR~
#else                                                              //~v6HsI~
    UWCH *wkfpathw;                                                //~v6HsI~
    UWCH *wkrpath;                                                 //~v6HsI~
    UWCH *wkrpathfp;                                               //~v6HsI~
#endif                                                             //~v6HsI~
    int pos,ctr,tailctr;                                           //~v6w0I~
//*************************	                                       //~v6w0I~
    UTRACED("inp",Pfnm,strszW(Pfnm));                              //~v6HnI~//~v6HhR~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=Pfpath;	//output                                   //~v6HsI~
    wkrpath=SmaxbuffW3;	//output                                   //~v6HsI~
    wkrpathfp=SmaxbuffW4;	//output                               //~v6HsI~
#endif                                                             //~v6HsI~
	pws=Pfpath+RESERVED_NAMEID_CTR;                                //~v6w0R~
  	if (*(pws+1)==L':' && *(pws+2)==L'\\')                         //~v6HnR~
  	{                                                              //~v6HnI~
    	UstrncpyZW(Pfpath,pws,Pbuffsz);                            //~v6HnR~
    	UTRACED("alread fpath out",Pfpath,Pbuffsz);                //~v6HnI~
    	return 0;                                                  //~v6HnI~
  	}                                                              //~v6HnI~
    pwt=strstrW(Pfnm,pws);                                         //~v6w0I~
    if (!pwt)                                                      //~v6w0I~
    	return 1;                                                  //~v6w0I~
	if (!memcmpW(Pfnm,RESERVED_NAMEIDW,RESERVED_NAMEID_CTR)) //already \\.\ pattern//~v6w0I~
    	return 1;                                                  //~v6w0I~
    memcpyWctr(wkfpathw,RESERVED_NAMEIDW,RESERVED_NAMEID_CTR);     //~v6w0R~
    if (*(Pfnm+1)!=L':')	//drive: fmt                           //~v6w0M~
    {   // path\prn.txt    --> \\.\prn                             //~v6w0R~
    	strcpyW(wkrpath,Pfnm);          // path\prn.txt            //~v6w0R~
    	pos=sz2ctrW(PTRDIFF(pwt,Pfnm)); //pos of "prn" of path\prn.txt//~v6w0R~
        ctr=strctrW(pws);               // ctr of "prn" on \\.\prn //~v6w0R~
        memsetW(wkrpath+pos,L'x',ctr);  //path\prn.txt  -->path\xxx.txt//~v6w0R~
        tailctr=strctrW(wkrpath+pos);   //ctr of xxx.txt from end of str//~v6w0R~
#ifdef BBB                                                         //~v6HsI~
    	pw=_wfullpath(wkrpathfp,wkrpath,sz2ctrW(sizeof(wkrpathfp)));//~v6w0R~
#else                                                              //~v6HsI~
    	pw=_wfullpath(wkrpathfp,wkrpath,sz2ctrW(MAXBUFFSZ));       //~v6HsR~
#endif                                                             //~v6HsI~
    	if (!pw)                                                   //~v6w0I~
    		return 1;                                              //~v6w0I~
//      if (adjustReservedNameWRoot(wkrpath,wkrpathfp,sizeof(wkrpathfp)))//~v6yeR~//~v6yhR~
//      {                                                            //~v6yeI~//~v6yhR~
//        memcpyWctr(wkrpathfp+strctrW(wkrpathfp)-tailctr,pws,ctr);  //~v6yeI~//~v6yhR~
//        strcpyW(wkfpathw,wkrpathfp);                               //~v6yeI~//~v6yhR~
//      }                                                            //~v6yeI~//~v6yhR~
//      else                                                         //~v6yeI~//~v6yhR~
//      {                                                            //~v6yeI~//~v6yhR~
	    memcpyWctr(wkrpathfp+strctrW(wkrpathfp)-tailctr,pws,ctr);  //~v6w0R~
      if (IS_WIN_LONGNAME_PREFIX(wkrpathfp)                        //~v6HnI~
      ||  IS_RESERVED_NAME(wkrpathfp))	//already prefixed         //~v6HnI~
    	strcpyW(wkfpathw,wkrpathfp);                               //~v6HnI~
      else                                                         //~v6HnI~
    	strcpyW(wkfpathw+RESERVED_NAMEID_CTR,wkrpathfp);           //~v6w0R~
//      }                                                            //~v6yeI~//~v6yhR~
    }                                                              //~v6w0I~
    else                                                           //~v6w0I~
    {                                                              //~v6HnI~
      if (IS_WIN_LONGNAME_PREFIX(Pfnm)                             //~v6HnI~
      ||  IS_RESERVED_NAME(Pfnm))	//already prefixed             //~v6HnI~
    	strcpyW(wkfpathw,Pfnm);                                    //~v6HnI~
      else                                                         //~v6HnI~
    	strcpyW(wkfpathw+RESERVED_NAMEID_CTR,Pfnm);                //~v6w0R~
    }                                                              //~v6HnI~
#ifdef BBB                                                         //~v6HsI~
    memcpy(Pfpath,wkfpathw,Pbuffsz);                               //~v6w0I~
#else                                                              //~v6HsI~
#endif                                                             //~v6HsI~
    UTRACED("out",Pfpath,Pbuffsz);                                 //~v6HnI~//~v6HhR~
    return 0;                                                      //~v6w0I~
}//adjustReservedNameW                                             //~v6w0I~
#ifdef AAA                                                         //~v6HsI~
//***************************************************************  //~v6yeI~
//adjust for windows bug for reservedname                          //~v6yeI~
//_wfullpath set \dir -->\\dir                                     //~v6yeI~
//adjust to \\.\g:\dir                                             //~v6yeI~
//return 0:replaced by fpath,1:ajusted                             //~v6yeR~
//***************************************************************  //~v6yeI~
int adjustReservedNameWRoot(UWCH *Pfnm,UWCH *Pfpath,int Pbuffsz)   //~v6yeI~
{                                                                  //~v6yeI~
//  UWCH wkfpathw[_MAX_PATHWC*2];                                  //~v6yeI~//~v6H9R~
    UWCH wkfpathw[_MAX_PATHWC_LONG*2];                             //~v6H9I~
    int rc=0;                                                      //~v6yeI~
//*************************                                        //~v6yeI~
	if (*Pfnm==L'\\' && *(Pfnm+1)!=L'\\'                           //~v6yeI~
    &&  *Pfpath==L'\\' && *(Pfpath+1)==L'\\')                      //~v6yeI~
    {                                                              //~v6yeI~
    	_wgetcwd(wkfpathw,_MAX_PATHWC/*count*/);                   //~v6yeR~
        if (IS_RESERVED_NAME(wkfpathw))                            //~v6yeI~
        {                                                          //~v6yeI~
	    	strcpyW(wkfpathw+RESERVED_NAMEID_CTR+2,Pfnm);          //~v6yeI~
	    	strcpyW(Pfpath,wkfpathw);                              //~v6yeI~
            rc=1;                                                  //~v6yeI~
        }                                                          //~v6yeI~
    }                                                              //~v6yeI~
    return rc;                                                     //~v6yeR~
}//adjustReservedNameWRoot                                         //~v6yeI~
#endif                                                             //~v6HsI~
//***************************************************************  //~v6w0I~
//adjust for windows bug for reservedname                          //~v6w0I~
//return 0:replaced by fpath,1:err                                 //~v6w0I~
//***************************************************************  //~v6w0I~
int adjustReservedName(char *Pfnm,char *Pfpath,int Pbuffsz)        //~v6w0I~
{                                                                  //~v6w0I~
	char *pws,*pwt,*pw;                                            //~v6w0I~
//  char wkfpathw[_MAX_PATHWC*2];                                  //~v6w0I~//~v6H9R~
//  char wkrpath[_MAX_PATHWC];                                     //~v6w0I~//~v6H9R~
//  char wkrpathfp[_MAX_PATHWC];                                   //~v6w0I~//~v6H9R~
    char wkfpathw[_MAX_PATH_LONG*2];                             //~v6H9I~//~v6HnR~
    char wkrpath[_MAX_PATH_LONG];                                //~v6H9I~//~v6HnR~
    char wkrpathfp[_MAX_PATH_LONG];                              //~v6H9I~//~v6HnR~
    int pos,ctr,tailctr;                                           //~v6w0I~
//*************************                                        //~v6w0I~
	SswRsvNameTryFailed=0;                                         //~v6HnI~
	pws=Pfpath+RESERVED_NAMEID_CTR;                                //~v6w0I~
    pwt=strstr(Pfnm,pws);                                          //~v6w0I~
    if (!pwt)                                                      //~v6w0I~
    	return 1;                                                  //~v6w0I~
	if (!memcmp(Pfnm,RESERVED_NAMEID,RESERVED_NAMEID_CTR)) //already \\.\ pattern//~v6w0R~
    	return 1;                                                  //~v6w0I~
    memcpy(wkfpathw,RESERVED_NAMEID,RESERVED_NAMEID_CTR);          //~v6w0R~
    if (*(Pfnm+1)!=L':')	//drive: fmt                           //~v6w0I~
    {   // path\prn.txt    --> \\.\prn                             //~v6w0I~
    	strcpy(wkrpath,Pfnm);          // path\prn.txt             //~v6w0I~
    	pos=(PTRDIFF(pwt,Pfnm)); //pos of "prn" of path\prn.txt    //~v6w0I~
        ctr=strlen(pws);               // ctr of "prn" on \\.\prn  //~v6w0R~
        memset(wkrpath+pos,L'x',ctr);  //path\prn.txt  -->path\xxx.txt//~v6w0I~
        tailctr=strlen(wkrpath+pos);   //ctr of xxx.txt from end of str//~v6w0R~
    	pw=_fullpath(wkrpathfp,wkrpath,sizeof(wkrpathfp));         //~v6w0I~
        UTRACEP("%s: _fullpath rc=pw=%p, errno=%d,lasterr=%d\n",UTT,pw,errno,GetLastError());//~v6HnI~
    	if (!pw)                                                   //~v6w0I~
        {                                                          //~v6HnI~
			SswRsvNameTryFailed=2;                                 //~v6HnI~
    		return 1;                                              //~v6w0I~
        }                                                          //~v6HnI~
	    memcpy(wkrpathfp+strlen(wkrpathfp)-tailctr,pws,ctr);       //~v6w0R~
      if (IS_WIN_LONGNAME_PREFIX(wkrpathfp)                        //~v6HnR~
      ||  IS_RESERVED_NAME(wkrpathfp))	//already prefixed         //~v6HnR~
    	strcpy(wkfpathw,wkrpathfp);                                //~v6HnI~
      else                                                         //~v6HnI~
    	strcpy(wkfpathw+RESERVED_NAMEID_CTR,wkrpathfp);            //~v6w0I~
    }                                                              //~v6w0I~
    else                                                           //~v6w0I~
    {                                                              //~v6HnI~
      if (IS_WIN_LONGNAME_PREFIX(Pfnm)                             //~v6HnR~
      ||  IS_RESERVED_NAME(Pfnm))	//already prefixed             //~v6HnI~
    	strcpy(wkfpathw,Pfnm);                                     //~v6HnI~
      else                                                         //~v6HnI~
    	strcpy(wkfpathw+RESERVED_NAMEID_CTR,Pfnm);                 //~v6w0I~
    }                                                              //~v6HnI~
    memcpy(Pfpath,wkfpathw,Pbuffsz);                               //~v6w0I~
    return 0;                                                      //~v6w0I~
}//adjustReservedName                                              //~v6w0I~
//***************************************************************  //~v6yhI~
//adjust for windows bug for reservedname                          //~v6yhI~
//return 0:replaced by fpath,1:err                                 //~v6yhI~
//***************************************************************  //~v6yhI~
char *adjustReservedNameRootDrive(char *Pfnm,char *Pfpath,int Pbuffsz)//~v6yhI~
{                                                                  //~v6yhI~
	char *pc=0;                                                    //~v6yhI~
    int driveid;                                                   //~v6yhI~
//*************************                                        //~v6yhI~
	if (*Pfnm=='\\')	//from root                                //~v6yhR~
    {                                                              //~v6yhI~
		driveid=ugetdrive();    //return @(_getdrive rc=0)         //~v6yhI~
        if (driveid=='@')		//@                                //~v6yhI~
        {                                                          //~v6yhI~
        	if (SlastReservedNameDriveLetter!=0)                   //~v6yhR~
            {                                                      //~v6yhI~
        		sprintf(Pfpath,"%c:%s",SlastReservedNameDriveLetter,Pfnm);//~v6yhR~
            	pc=Pfpath;                                         //~v6yhR~
            }                                                      //~v6yhI~
        }                                                          //~v6yhI~
    }                                                              //~v6yhI~
    return pc;                                                     //~v6yhI~
}//adjustReservedNameRootDrive                                     //~v6yhI~
//***************************************************************  //~v6w0I~
//adjust for windows bug for reservedname                          //~v6w0I~
//return 0:replaced by fpath,1:err                                 //~v6w0I~
//***************************************************************  //~v6w0I~
HDIR chkReservedNameW(HDIR Phdir,UWCH *Pfnm,WIN32_FIND_DATAW *Ppw32fd)//~v6w0I~
{                                                                  //~v6w0I~
//  UWCH wkfpathw[_MAX_PATHWC],*pw;                                //~v6w0R~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG],*pw;                           //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkfpathw,*pw;                                            //~v6HsI~
#endif                                                             //~v6HsI~
    HDIR hdir;                                                     //~v6w0I~
    int rc;                                                        //~v6w0I~
//*************************                                        //~v6w0I~
	UTRACED("inp",Pfnm,strszW(Pfnm));                              //~v6HnI~//~v6HhR~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=SmaxbuffW2;                                           //~v6HsI~
#endif                                                             //~v6HsI~
	hdir=Phdir;                                                    //~v6w0I~
	for (;;)                                                       //~v6w0I~
    {                                                              //~v6w0I~
#ifdef BBB                                                         //~v6HsI~
    	pw=_wfullpath(wkfpathw,Pfnm,sz2ctrW(sizeof(wkfpathw)));    //~v6w0I~
#else                                                              //~v6HsI~
    	pw=_wfullpath(wkfpathw,Pfnm,sz2ctrW(MAXBUFFSZ));           //~v6HsI~
#endif                                                             //~v6HsI~
    	if (!pw)                                                   //~v6w0I~
    		break;                                                 //~v6w0I~
		if (memcmpW(wkfpathw,RESERVED_NAMEIDW,RESERVED_NAMEID_CTR)) //not \\.\prn//~v6w0I~
        	break;                                                 //~v6w0I~
#ifdef BBB                                                         //~v6HsI~
        rc=adjustReservedNameW(Pfnm,wkfpathw,sizeof(wkfpathw));    //~v6w0R~
#else                                                              //~v6HsI~
        rc=adjustReservedNameW(Pfnm,wkfpathw,MAXBUFFSZ);           //~v6HsI~
#endif                                                             //~v6HsI~
        if (rc)	//not replaced                                     //~v6w0I~
        {		                                                   //~v6w0I~
	    	hdir=INVALID_HANDLE_VALUE;                             //~v6w0I~
        	break;                                                 //~v6w0I~
        }                                                          //~v6w0I~
	    hdir=FindFirstFileW(wkfpathw,Ppw32fd);                     //~v6w0R~
		UTRACEP("%s:FindFirstFileW hdir=%x,errno=%d,lasterr=%d\n",UTT,hdir,errno,GetLastError());//~v6HnI~//~v6HhR~
		UTRACED("wkfpathw",wkfpathw,strszW(wkfpathw));             //~v6HnI~//~v6HhR~
        break;                                                     //~v6w0I~
    }                                                              //~v6w0I~
    return hdir;                                                   //~v6w0I~
}//chkReservedNameW                                             //~v6w0I~//~v6y2R~
//***************************************************************
//adjust for windows bug for reservedname
//return 0:replaced by fpath,1:err
//***************************************************************
HDIR tryLongNamePrefixFindFirstFileW(HDIR Phdir,UWCH *Pfnm,WIN32_FIND_DATAW *Ppw32fd)//~v6HnI~//~v6HhR~
{
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG];                               //~v6HnI~//~v6HhR~
#else                                                              //~v6HsI~
    UWCH *wkfpathw;                                                //~v6HsI~
#endif                                                             //~v6HsI~
    HDIR hdir;
//*************************
	UTRACED("inp",Pfnm,strszW(Pfnm));                              //~v6HnI~//~v6HhR~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=SmaxbuffW2;                                           //~v6HsI~
#endif                                                             //~v6HsI~
	hdir=Phdir;
	for (;;)
    {
    	if (!IS_WIN_LONGNAME_PREFIX(Pfnm))                          //~v6HnI~//~v6HhR~//~v6HnR~
    	{                                                          //~v6HnR~
        	strcpyW(wkfpathw,WIN_LONGNAME_PREFIXW);                    //~v6HnI~//~v6HhR~//~v6HnR~
        	strcpyW(wkfpathw+WIN_LONGNAME_PREFIXCTR,Pfnm);             //~v6HnR~//~v6HhR~//~v6HnR~
		    hdir=FindFirstFileW(wkfpathw,Ppw32fd);                 //~v6HnI~
        }                                                          //~v6HnI~
		UTRACEP("%s:FindFirstFileW:hdir=%x,errno=%d,lasterr=%d\n",UTT,hdir,errno,GetLastError());//~v6HnI~//~v6HhR~//~v6HnR~
		UTRACED("fnmw",wkfpathw,strszW(wkfpathw));                 //~v6HnI~//~v6HhR~
        break;
    }
    return hdir;
}//tryLongNamePrefixFindFirstFileW                                 //~v6HnR~
//***************************************************************  //~v6w0I~
//test by reservedname                                             //~v6w0I~
//***************************************************************  //~v6w0I~
int tryMoveFileForReservedNameW(UWCH *Pold,UWCH *Pnew,int Prc)     //~v6w0R~
{                                                                  //~v6w0I~
//  UWCH wkold[_MAX_PATHWC],*pw,*pwold,*pwnew;                     //~v6w0R~//~v6H9R~
//  UWCH wknew[_MAX_PATHWC];                                       //~v6w0I~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkold[_MAX_PATHWC_LONG],*pw,*pwold,*pwnew;                //~v6H9I~
    UWCH wknew[_MAX_PATHWC_LONG];                                  //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkold,*pw,*pwold,*pwnew;                                 //~v6HsI~
    UWCH *wknew;                                                   //~v6HsI~
#endif                                                             //~v6HsI~
    int rc;                                                        //~v6w0I~
    int swrsv=0;                                                   //~v6HnI~
//*************************                                        //~v6w0I~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkold=SmaxbuffW5;                                              //~v6HsR~
    wknew=SmaxbuffW6;                                              //~v6HsR~
#endif                                                             //~v6HsI~
	pwold=Pold;                                                    //~v6w0I~
#ifdef BBB                                                         //~v6HsI~
    pw=_wfullpath(wkold,Pold,sz2ctrW(sizeof(wkold)));              //~v6w0R~
#else                                                              //~v6HsI~
    pw=_wfullpath(wkold,Pold,sz2ctrW(MAXBUFFSZ));                  //~v6HsI~
#endif                                                             //~v6HsI~
    if (pw && IS_RESERVED_NAME(pw))                                //~v6w0I~
    {                                                              //~v6w0I~
        swrsv|=0x01;                                               //~v6HnI~
#ifdef BBB                                                         //~v6HsI~
		rc=adjustReservedNameW(Pold,wkold,sizeof(wkold));          //~v6w0R~
#else                                                              //~v6HsI~
		rc=adjustReservedNameW(Pold,wkold,MAXBUFFSZ);              //~v6HsI~
#endif                                                             //~v6HsI~
        if (!rc)                                                   //~v6w0I~
	    	pwold=pw;                                              //~v6w0I~
    }                                                              //~v6w0I~
	pwnew=Pnew;                                                    //~v6w0I~
#ifdef BBB                                                         //~v6HsI~
    pw=_wfullpath(wknew,Pnew,sz2ctrW(sizeof(wknew)));              //~v6w0R~
#else                                                              //~v6HsI~
    pw=_wfullpath(wknew,Pnew,sz2ctrW(MAXBUFFSZ));                  //~v6HsI~
#endif                                                             //~v6HsI~
    if (pw && IS_RESERVED_NAME(pw))                                //~v6w0I~
    {                                                              //~v6w0I~
        swrsv|=0x02;                                               //~v6HnI~
#ifdef BBB                                                         //~v6HsI~
		rc=adjustReservedNameW(Pnew,wknew,sizeof(wknew));          //~v6w0R~
#else                                                              //~v6HsI~
		rc=adjustReservedNameW(Pnew,wknew,MAXBUFFSZ);              //~v6HsI~
#endif                                                             //~v6HsI~
        if (!rc)                                                   //~v6w0I~
	    	pwnew=pw;                                              //~v6w0I~
    }                                                              //~v6w0I~
    if (pwold==Pold && pwnew==Pnew)                                //~v6w0I~
    	return Prc;                                                //~v6w0I~
  if (SmovefileExflag)	//parm                                     //~v6HnI~//~v6HsR~
	rc=MoveFileExW(pwold,pwnew,SmovefileExflag);                     //~v6HnI~//~v6HsR~
  else                                                             //~v6HnI~
	rc=MoveFileW(pwold,pwnew);                                     //~v6w0I~
    UTRACEP("%s:with rsv rc=%d,errno=%d,SmovefileExflag=%x\n",UTT,rc,errno,GetLastError(),SmovefileExflag);                                  //~v6w0I~//~v6HnR~//~v6HsR~
    UTRACED("old",pwold,strszW(pwold));                            //~v6HnI~
    UTRACED("new",pwnew,strszW(pwnew));                            //~v6HnI~
    if (!rc && swrsv)    //try longpath                            //~v6HnR~
    {                                                              //~v6HnI~
    	if (swrsv & 0x01)                                          //~v6HnI~
        	memcpy(wkold,WIN_LONGNAME_PREFIXW,ctr2szW(WIN_LONGNAME_PREFIXCTR));//~v6HnI~
    	if (swrsv & 0x02)                                          //~v6HnI~
        	memcpy(wknew,WIN_LONGNAME_PREFIXW,ctr2szW(WIN_LONGNAME_PREFIXCTR));//~v6HnI~
      if (SmovefileExflag)	//parm                                 //~v6HnI~//~v6HsR~
	    rc=MoveFileExW(pwold,pwnew,SmovefileExflag);                 //~v6HnI~//~v6HsR~
      else                                                         //~v6HnI~
		rc=MoveFileW(pwold,pwnew);                                 //~v6HnI~
	    UTRACEP("%s:retry by longname prefix rc=%d,errno=%d,lasterr=%d,SmovefileExflag=%x\n",UTT,rc,errno,GetLastError(),SmovefileExflag);//~v6HnR~//~v6HsR~
	    UTRACED("old",pwold,strszW(pwold));                        //~v6HnI~
    	UTRACED("new",pwnew,strszW(pwnew));                        //~v6HnI~
    }                                                              //~v6HnI~
    return rc;                                                     //~v6w0I~
}//tryMoveFileForReservedNameW                                     //~v6w0I~
//***************************************************************  //~v6w0I~
//test by reservedname                                             //~v6w0I~
//***************************************************************  //~v6w0I~
int tryRemoveForReservedName(char *Pfnm,int Prc)                   //~v6w0I~
{                                                                  //~v6w0I~
//  char wkfpath[_MAX_PATH],*pc;                                   //~v6w0R~//~v6H9R~
    char wkfpath[_MAX_PATH_LONG],*pc;                              //~v6H9I~
    int rc;                                                        //~v6w0I~
//*************************                                        //~v6w0I~
	pc=Pfnm;                                                       //~v6w0I~
    rc=Prc;                                                        //~v6w0I~
    pc=_fullpath(wkfpath,pc,sizeof(wkfpath));                      //~v6w0R~
	SswRsvNameTryFailed=0;                                         //~v6HnI~
    if (pc && IS_RESERVED_NAME(pc))                                //~v6w0I~
    {                                                              //~v6w0I~
		if (!adjustReservedName(Pfnm,wkfpath,sizeof(wkfpath)))     //~v6w0R~
        {                                                          //~v6HnI~
	    	rc=remove(pc);                                         //~v6w0I~
            UTRACEP("%s:remove rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
            UTRACED("pc",pc,strlen(pc));                           //~v6HnI~
			if (rc)                                                //~v6HnI~
				SswRsvNameTryFailed=1;                             //~v6HnI~
        }                                                          //~v6HnI~
    }                                                              //~v6w0I~
    UTRACEP("%s:rc=%d,SswRsvNameTryFailed=%d,errno=%d,lasterr=%d\n",UTT,rc,SswRsvNameTryFailed,errno,GetLastError());//~v6HnI~
    return rc;                                                     //~v6w0I~
}//tryRemoveFileForReservedName                                     //~v6w0I~//~v6y7R~
//***************************************************************  //~v6y7I~
//test by reservedname                                             //~v6y7I~
//***************************************************************  //~v6y7I~
int tryWremoveForReservedName(UWCH *Pfnmw,int Prc)                 //~v6y7I~
{                                                                  //~v6y7I~
//  UWCH wkfpathw[_MAX_PATHWC],*pw;                                //~v6y7I~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG],*pw;                           //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkfpathw,*pw;                                            //~v6HsI~
#endif                                                             //~v6HsI~
    int rc,rc2;                                                    //~v6y7I~
//*************************                                        //~v6y7I~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=SmaxbuffW2;                                           //~v6HsR~
#endif                                                             //~v6HsI~
	pw=Pfnmw;                                                      //~v6y7I~
    rc=Prc;                                                        //~v6y7I~
#ifdef BBB                                                         //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(sizeof(wkfpathw)));       //~v6y7I~
#else                                                              //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(MAXBUFFSZ));              //~v6HsI~
#endif                                                             //~v6HsI~
    if (pw && IS_RESERVED_NAME(pw))                                //~v6y7R~
    {                                                              //~v6y7I~
#ifdef BBB                                                         //~v6HsI~
		rc2=adjustReservedNameW(Pfnmw,wkfpathw,sizeof(wkfpathw));  //~v6y7I~
#else                                                              //~v6HsI~
		rc2=adjustReservedNameW(Pfnmw,wkfpathw,MAXBUFFSZ);         //~v6HsI~
#endif                                                             //~v6HsI~
        if (!rc2)                                                  //~v6y7I~
        {                                                          //~v6HnI~
		    rc=_wremove(pw);                                       //~v6y7I~
            UTRACEP("%s:_wremove rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnR~
            UTRACED("pw",pw,strszW(pw));                           //~v6HnI~
            if (rc)                                                //~v6HnI~
            {
            	memcpy(pw,WIN_LONGNAME_PREFIXW,ctr2szW(WIN_LONGNAME_PREFIXCTR));
			    rc=_wremove(pw);                                   //~v6HnI~
            	UTRACEP("%s:_wremove rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
	            UTRACED("wkfpathw",pw,strszW(pw));                 //~v6HnI~
            }
        }                                                          //~v6HnI~
    }                                                              //~v6y7I~
    return rc;                                                     //~v6y7I~
}//tryWremoveForReservedName                                       //~v6y7I~
//***************************************************************  //~v6HsI~
//test by reservedname                                             //~v6HsI~
//***************************************************************  //~v6HsI~
int tryWRmdirForReservedName(UWCH *Pfnmw,int Prc)                  //~v6HsI~
{                                                                  //~v6HsI~
//  UWCH wkfpathw[_MAX_PATHWC],*pw;                                //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG],*pw;                           //~v6HsI~
#else                                                              //~v6HsI~
    UWCH *wkfpathw,*pw;                                            //~v6HsI~
#endif                                                             //~v6HsI~
    int rc,rc2;                                                    //~v6HsI~
//*************************                                        //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=SmaxbuffW2;                                           //~v6HsI~
#endif                                                             //~v6HsI~
	pw=Pfnmw;                                                      //~v6HsI~
    rc=Prc;                                                        //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(sizeof(wkfpathw)));       //~v6HsI~
#else                                                              //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(MAXBUFFSZ));              //~v6HsI~
#endif                                                             //~v6HsI~
    if (pw && IS_RESERVED_NAME(pw))                                //~v6HsI~
    {                                                              //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
		rc2=adjustReservedNameW(Pfnmw,wkfpathw,sizeof(wkfpathw));  //~v6HsI~
#else                                                              //~v6HsI~
		rc2=adjustReservedNameW(Pfnmw,wkfpathw,MAXBUFFSZ);         //~v6HsI~
#endif                                                             //~v6HsI~
        if (!rc2)                                                  //~v6HsI~
        {                                                          //~v6HsI~
			rc=_wrmdir(pw);                                        //~v6HsI~
            UTRACEP("%s:_wrmdir rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HsI~
            UTRACED("pw",pw,strszW(pw));                           //~v6HsI~
            if (rc)                                                //~v6HsI~
            {                                                      //~v6HsI~
            	memcpy(pw,WIN_LONGNAME_PREFIXW,ctr2szW(WIN_LONGNAME_PREFIXCTR));//~v6HsI~
				rc=_wrmdir(pw);                                    //~v6HsI~
            	UTRACEP("%s:_wrmdir rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HsI~
	            UTRACED("pw",pw,strszW(pw));                       //~v6HsI~
            }                                                      //~v6HsI~
        }                                                          //~v6HsI~
    }                                                              //~v6HsI~
    return rc;                                                     //~v6HsI~
}//tryWRmdirForReservedName                                        //~v6HsI~
//***************************************************************  //~v6HnI~
//test by reservedname                                             //~v6HnI~
//***************************************************************  //~v6HnI~
int tryRmdirForReservedName(char *Pfnm,int Prc)                    //~v6HnI~
{                                                                  //~v6HnI~
    char wkfpath[_MAX_PATH_LONG],*pc;                              //~v6HnI~
    int rc;                                                        //~v6HnI~
//*************************                                        //~v6HnI~
	pc=Pfnm;                                                       //~v6HnI~
    rc=Prc;                                                        //~v6HnI~
    pc=_fullpath(wkfpath,pc,sizeof(wkfpath));                      //~v6HnI~
	SswRsvNameTryFailed=0;                                         //~v6HnI~
    if (pc && IS_RESERVED_NAME(pc))                                //~v6HnI~
    {                                                              //~v6HnI~
		if (!adjustReservedName(Pfnm,wkfpath,sizeof(wkfpath)))     //~v6HnI~
        {                                                          //~v6HnI~
	    	rc=_rmdir(pc);                                         //~v6HnI~
			if (rc)                                                //~v6HnI~
				SswRsvNameTryFailed=1;                             //~v6HnI~
		    UTRACEP("%s:_rmdir rc=%d,errno=%d\n",UTT,rc,errno);    //~v6HnR~
		    UTRACED("wkfpath",pc,strlen(pc));
        }                                                          //~v6HnI~
    }                                                              //~v6HnI~
    UTRACEP("%s:rc=%d,SswRsvNameTryFailed=%d,errno=%d,lasterr=%d\n",UTT,rc,SswRsvNameTryFailed,errno,GetLastError());//~v6HnI~
    return rc;                                                     //~v6HnI~
}//tryRemoveFileForReservedName                                    //~v6HnI~
//***************************************************************  //~v6y2I~
//test by reservedname                                             //~v6y2I~
//***************************************************************  //~v6y2I~
FILE *tryFopenForReservedName(const char *Pfnm,const char *Popenopt,FILE *Pfh)//~v6y2R~
{                                                                  //~v6y2I~
//  char wkfpath[_MAX_PATH],*pc;                                   //~v6y2I~//~v6H9R~
    char wkfpath[_MAX_PATH_LONG],*pc;                              //~v6H9I~
    FILE *fh;                                                      //~v6y2I~
//*************************                                        //~v6y2I~
	pc=(char *)Pfnm;                                               //~v6y2R~
    fh=Pfh;                                                        //~v6y2I~
    pc=_fullpath(wkfpath,pc,sizeof(wkfpath));                      //~v6y2I~
    UTRACEP("%s:fullpath fnm=%s for %s\n",UTT,pc,Pfnm);            //~v6HhR~
	SswRsvNameTryFailed=0;                                         //~v6HnI~
    if (pc && IS_RESERVED_NAME(pc))                                //~v6y2I~
    {                                                              //~v6y2I~
		if (!adjustReservedName((char *)Pfnm,wkfpath,sizeof(wkfpath)))//~v6y2R~
        {                                                          //~v6HhI~
	    	fh=fopen(pc,Popenopt);                                 //~v6y2I~
            UTRACEP("%s:fh=%x,err=%d,lasterr=%d,fnm=%s\n",UTT,fh,errno,GetLastError(),pc);              //~v6HhR~//~v6HnR~//~v6HhR~
            UTRACED("fopen pc",pc,strlen(pc));                     //~v6HnI~
            if (!fh)                                               //~v6HnI~
//  			fh=TRYRC_RSVNAME;		// (FILE*)(-3)             //~v6HnR~
				SswRsvNameTryFailed=1;                             //~v6HnI~
        }                                                          //~v6HhI~
    }                                                              //~v6y2I~
    return fh;                                                     //~v6y2I~
}//tryFopenForReservedName                                         //~v6y3R~
//***************************************************************  //~v6y2I~
//test by reservedname                                             //~v6y2I~
//***************************************************************  //~v6y2I~
FILE *tryWfopenForReservedName(UWCH *Pfnmw,UWCH *Popenoptw)        //~v6y2I~
{                                                                  //~v6y2I~
//  UWCH wkfpathw[_MAX_PATHWC],*pw;                                //~v6y2I~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG],*pw;                           //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkfpathw,*pw;                                            //~v6HsI~
#endif                                                             //~v6HsI~
    FILE *fh=NULL;                                                 //~v6y2I~
    int rc2;                                                       //~v6y2I~
//*************************                                        //~v6y2I~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=SmaxbuffW2;                                           //~v6HsR~
#endif                                                             //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(sizeof(wkfpathw)));       //~v6y2I~
#else                                                              //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(MAXBUFFSZ));              //~v6HsI~
#endif                                                             //~v6HsI~
    UTRACED("_wfullpath wkfpathw",wkfpathw,strszW(wkfpathw));      //~v6HnI~
    if (pw && IS_RESERVED_NAME(pw))                                //~v6y2I~
    {                                                              //~v6y2I~
#ifdef BBB                                                         //~v6HsI~
		rc2=adjustReservedNameW(Pfnmw,wkfpathw,sizeof(wkfpathw));  //~v6y2I~
#else                                                              //~v6HsI~
		rc2=adjustReservedNameW(Pfnmw,wkfpathw,MAXBUFFSZ);         //~v6HsI~
#endif                                                             //~v6HsI~
        if (!rc2)                                                  //~v6y2I~
        {                                                          //~v6HnI~
	    	fh=_wfopen(pw,Popenoptw);                              //~v6y2I~
            UTRACEP("%s:_wfopen fh=%x,errno=%d,lasterr=%d\n",UTT,fh,errno,GetLastError());//~v6HnR~
            UTRACED("wkfpathw",wkfpathw,strszW(wkfpathw));         //~v6HnR~
            if (!fh)                                               //~v6HnI~
            {                                                      //~v6HnI~
            	memcpy(pw,WIN_LONGNAME_PREFIXW,ctr2szW(WIN_LONGNAME_PREFIXCTR));//~v6HnI~
		    	fh=_wfopen(pw,Popenoptw);                          //~v6HnI~
            	UTRACEP("%s:_wfopen fh=%x,errno=%d,lasterr=%d\n",UTT,fh,errno,GetLastError());//~v6HnR~
	            UTRACED("wkfpathw",wkfpathw,strszW(wkfpathw));     //~v6HnR~
            }                                                      //~v6HnI~
        }                                                          //~v6HnI~
    }                                                              //~v6y2I~
    return fh;                                                     //~v6y2I~
}//tryWfopenForReservedName                                        //~v6y2I~
//***************************************************************  //~v6y3I~
//test by reservedname                                             //~v6y3I~
//***************************************************************  //~v6y3I~
int trySetFileAttributesW(UWCH *Pfpathw,DWORD Pdwattr,int Prc)     //~v6y3I~
{                                                                  //~v6y3I~
//  UWCH wkfpathw[_MAX_PATHWC],*pw;                                //~v6y3I~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG],*pw;                           //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkfpathw,*pw;                                            //~v6HsI~
#endif                                                             //~v6HsI~
    int rc,rc2;                                                    //~v6y3I~
//*************************                                        //~v6y3I~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=SmaxbuffW2;                                           //~v6HsR~
#endif                                                             //~v6HsI~
    rc=Prc;                                                        //~v6y3I~
#ifdef BBB                                                         //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfpathw,sz2ctrW(sizeof(wkfpathw)));     //~v6y3I~
#else                                                              //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfpathw,sz2ctrW(MAXBUFFSZ));            //~v6HsI~
#endif                                                             //~v6HsI~
    if (pw && IS_RESERVED_NAME(pw))                                //~v6y3I~
    {                                                              //~v6y3I~
#ifdef BBB                                                         //~v6HsI~
		rc2=adjustReservedNameW(Pfpathw,wkfpathw,sizeof(wkfpathw));//~v6y3I~
#else                                                              //~v6HsI~
		rc2=adjustReservedNameW(Pfpathw,wkfpathw,MAXBUFFSZ);       //~v6HsI~
#endif                                                             //~v6HsI~
        if (!rc2)                                                  //~v6y3I~
        {                                                          //~v6HnI~
	    	rc=SetFileAttributesW(pw,Pdwattr);                     //~v6y3I~
        	UTRACEP("%s:rsvname rc=bool=%d,errno=%d,lastError=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
        	UTRACED("pw",pw,strszW(pw));                           //~v6HnI~
            if (!rc)                                               //~v6HnI~
            {                                                      //~v6HnI~
            	memcpy(pw,WIN_LONGNAME_PREFIXW,ctr2szW(WIN_LONGNAME_PREFIXCTR));
		    	rc=SetFileAttributesW(pw,Pdwattr);                 //~v6HnI~
	        	UTRACEP("%s:by long name rc=bool=%d,errno=%d,lastError=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
    	    	UTRACED("pw",pw,strszW(pw));                       //~v6HnI~
            }                                                      //~v6HnI~
        }                                                          //~v6HnI~
    }                                                              //~v6y3I~
    return rc;                                                     //~v6y3I~
}//trySetFileAttributesW                                           //~v6y3I~
//***************************************************************  //~v6HsI~
//test by reservedname                                             //~v6HsI~
//***************************************************************  //~v6HsI~
BOOL tryGetFileAttributesExW(UWCH *Pfpathw,GET_FILEEX_INFO_LEVELS Pinfolvl,LPVOID Ppinfo,int Prc)//~v6HsI~
{                                                                  //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG],*pw;                           //~v6HsI~
#else                                                              //~v6HsI~
    UWCH *wkfpathw,*pw;                                            //~v6HsI~
#endif                                                             //~v6HsI~
    int rc,rc2;                                                    //~v6HsI~
//*************************                                        //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=SmaxbuffW2;                                           //~v6HsI~
#endif                                                             //~v6HsI~
    rc=Prc;                                                        //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfpathw,sz2ctrW(sizeof(wkfpathw)));     //~v6HsI~
#else                                                              //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfpathw,sz2ctrW(MAXBUFFSZ));            //~v6HsI~
#endif                                                             //~v6HsI~
    if (pw && IS_RESERVED_NAME(pw))                                //~v6HsI~
    {                                                              //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
		rc2=adjustReservedNameW(Pfpathw,wkfpathw,sizeof(wkfpathw));//~v6HsI~
#else                                                              //~v6HsI~
		rc2=adjustReservedNameW(Pfpathw,wkfpathw,MAXBUFFSZ);       //~v6HsI~
#endif                                                             //~v6HsI~
        if (!rc2)                                                  //~v6HsI~
        {                                                          //~v6HsI~
			rc=GetFileAttributesExW(pw,Pinfolvl,Ppinfo);           //~v6HsI~
        	UTRACEP("%s:GetFileAttributeExW rsvname rc=bool=%d,errno=%d,lastError=%d\n",UTT,rc,errno,GetLastError());//~v6HsI~
        	UTRACED("pw",pw,strszW(pw));                           //~v6HsI~
            if (!rc)                                               //~v6HsI~
            {                                                      //~v6HsI~
            	memcpy(pw,WIN_LONGNAME_PREFIXW,ctr2szW(WIN_LONGNAME_PREFIXCTR));//~v6HsI~
				rc=GetFileAttributesExW(pw,Pinfolvl,Ppinfo);       //~v6HsI~
	        	UTRACEP("%s:by long name rc=bool=%d,errno=%d,lastError=%d\n",UTT,rc,errno,GetLastError());//~v6HsI~
    	    	UTRACED("pw",pw,strszW(pw));                       //~v6HsI~
            }                                                      //~v6HsI~
        }                                                          //~v6HsI~
    }                                                              //~v6HsI~
    return rc;                                                     //~v6HsI~
}//tryGetFileAttributesExW                                         //~v6HsR~
//***************************************************************  //~v6HsI~
//test by reservedname                                             //~v6HsI~
//***************************************************************  //~v6HsI~
BOOL tryGetDiskFreeSpaceW(UWCH *Pfpathw,LPDWORD Psector,LPDWORD Pbyte,LPDWORD Pfree,LPDWORD Ptotal,int Prc)//~v6HsI~
{                                                                  //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG],*pw;                           //~v6HsI~
#else                                                              //~v6HsI~
    UWCH *wkfpathw,*pw;                                            //~v6HsI~
#endif                                                             //~v6HsI~
    UWCH *pw2;                                                     //~v6HsI~
    int rc,rc2;                                                    //~v6HsI~
//*************************                                        //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=SmaxbuffW2;                                           //~v6HsI~
#endif                                                             //~v6HsI~
    rc=Prc;                                                        //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfpathw,sz2ctrW(sizeof(wkfpathw)));     //~v6HsI~
#else                                                              //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfpathw,sz2ctrW(MAXBUFFSZ));            //~v6HsI~
#endif                                                             //~v6HsI~
	rc2=0;                                                         //~v6HsI~
    if (pw && IS_RESERVED_NAME(pw))                                //~v6HsI~
    {                                                              //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
		rc2=adjustReservedNameW(Pfpathw,wkfpathw,sizeof(wkfpathw));//~v6HsI~
#else                                                              //~v6HsI~
		rc2=adjustReservedNameW(Pfpathw,wkfpathw,MAXBUFFSZ);       //~v6HsI~
#endif                                                             //~v6HsI~
	}                                                              //~v6HsI~
    else                                                           //~v6HsI~
    	strcpyW(wkfpathw,Pfpathw);                                 //~v6HsI~
    if (!rc2)                                                      //~v6HsI~
    {                                                              //~v6HsI~
        pw=wkfpathw;                                               //~v6HsI~
        if (IS_RESERVED_NAME(pw))                                  //~v6HsI~
            pw+=RESERVED_NAMEID_CTR;                               //~v6HsI~
        else                                                       //~v6HsI~
        if (IS_WIN_LONGNAME_PREFIX(pw))                            //~v6HsI~
            pw+=WIN_LONGNAME_PREFIXCTR;                            //~v6HsI~
        pw2=strchrW(pw,L'\\');                                     //~v6HsI~
        if (pw2)                                                   //~v6HsI~
            *(pw2+1)=0;                                            //~v6HsI~
        rc=GetDiskFreeSpaceW(pw,Psector,Pbyte,Pfree,Ptotal);       //~v6HsI~
        UTRACEP("%s:GetDiskFreeSpaceW rsvname rc=bool=%d,errno=%d,lastError=%d\n",UTT,rc,errno,GetLastError());//~v6HsI~
        UTRACED("pw",pw,strszW(pw));                               //~v6HsI~
    }                                                              //~v6HsI~
    return rc;                                                     //~v6HsI~
}//tryGetDiskFreeSpaceW                                            //~v6HsI~
//***************************************************************  //~v6y4I~
HANDLE tryCreateFileForReservedName(UWCH *Pfnmw,DWORD Pacc,DWORD Pshare,LPSECURITY_ATTRIBUTES Psecattr,DWORD Pdisp,DWORD Pattr,HANDLE Phtemp)//~v6y4I~
{                                                                  //~v6y4I~
//  UWCH wkfpathw[_MAX_PATHWC],*pw;                                //~v6y4I~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG],*pw;                           //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkfpathw,*pw;                                            //~v6HsI~
#endif                                                             //~v6HsI~
	HANDLE fh=INVALID_HANDLE_VALUE;                                //~v6y4I~
    int rc2;                                                       //~v6y4I~
//*************************                                        //~v6y4I~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=SmaxbuffW2;                                           //~v6HsR~
#endif                                                             //~v6HsI~
#ifdef BBB                                                         //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(sizeof(wkfpathw)));       //~v6y4I~
#else                                                              //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(MAXBUFFSZ));              //~v6HsI~
#endif                                                             //~v6HsI~
    if (pw && IS_RESERVED_NAME(pw))                                //~v6y4I~
    {                                                              //~v6y4I~
#ifdef BBB                                                         //~v6HsI~
		rc2=adjustReservedNameW(Pfnmw,wkfpathw,sizeof(wkfpathw));  //~v6y4I~
#else                                                              //~v6HsI~
		rc2=adjustReservedNameW(Pfnmw,wkfpathw,MAXBUFFSZ);         //~v6HsI~
#endif                                                             //~v6HsI~
        if (!rc2)                                                  //~v6y4I~
        {                                                          //~v6HnI~
	    	fh=CreateFileW(pw,Pacc,Pshare,Psecattr,Pdisp,Pattr,Phtemp);//~v6y4I~
            UTRACEP("%s:rc=fh=%x,errno=%d,lasterr=%d\n",UTT,fh,errno,GetLastError());//~v6HnI~
            if (fh==INVALID_HANDLE_VALUE)                          //~v6HnI~
            {                                                      //~v6HnI~
            	if (IS_RESERVED_NAME_FULLPATH(pw))                 //~v6HnR~
                {                                                  //~v6HnI~
        			memcpy(pw,WIN_LONGNAME_PREFIXW,ctr2szW(WIN_LONGNAME_PREFIXCTR));//~v6HnI~
			    	fh=CreateFileW(pw,Pacc,Pshare,Psecattr,Pdisp,Pattr,Phtemp);//~v6HnI~
        		    UTRACEP("%s:try longname rc=fh=%x,errno=%d,lasterr=%d\n",UTT,fh,errno,GetLastError());//~v6HnI~
                }                                                  //~v6HnI~
            }                                                      //~v6HnI~
        }                                                          //~v6HnI~
    }                                                              //~v6y4I~
    return fh;                                                     //~v6y4I~
}//tryCreateFileForReservedName                                    //~v6y4I~
//***************************************************************  //~v6y8I~
//redirect fopen to _tempnam                                       //~v6y8I~
//set EINVAL if parm err                                           //~v6y8I~
//!! Pdir should be <MAX_PATH-14                                   //~v6HgI~
//tmpnam and _wtmpnam returns static variable                      //~v6HsI~
//_tempnam and _wtempnam returns allocated buff(need to free)      //~v6HsI~
//***************************************************************  //~v6y8I~
#ifdef PUSH_TEMPNAM                                                //~v6y8I~//~v6yeR~
	#pragma pop_macro("_tempnam")                                  //~v6y8I~
#else                                                              //~v6y8I~
	#undef _tempnam                                                //~v6y8I~
#endif                                                             //~v6y8I~
char *u_tempnamW(const char * Pdir,const char * Pprefix)           //~v6y8R~
{                                                                  //~v6y8I~
//  char wktempnam[_MAX_PATH];                                     //~v6y8R~//~v6H9R~
//  char prefix[_MAX_PATH],*pc,*pprefix;                           //~v6y9R~//~v6H9I~
    char wktempnam[_MAX_PATH_LONG];                                //~v6H9I~
    char prefix[_MAX_PATH_LONG],*pc,*pprefix;                      //~v6H9I~
	int opt,rc,ucsctr,charctr;                                     //~v6y8R~
//  UWCH prefixw[_MAX_PATHWC],*pfnmw;                              //~v6y8R~//~v6H9R~
//  UWCH wkfnmw[_MAX_PATHWC];                                      //~v6y8I~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH prefixw[_MAX_PATHWC_LONG],*pfnmw;                         //~v6H9I~
    UWCH wkfnmw[_MAX_PATHWC_LONG];                                 //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *prefixw,*pfnmw;                                          //~v6HsI~
    UWCH *wkfnmw;                                                  //~v6HsI~
#endif                                                             //~v6HsI~
    char *pfnm=0;                                                  //~v6y8R~
//*****************************                                    //~v6y8I~
    UTRACEP("%s:dir=%s,prefix=%s\n",UTT,Pdir,Pprefix);             //~v6y8I~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    prefixw=SmaxbuffW;                                             //~v6HsI~
    wkfnmw=SmaxbuffW2;                                             //~v6HsI~
#endif                                                             //~v6HsI~
    pprefix=(char*)Pprefix;                                        //~v6y9R~
    pc=_fullpath(prefix,Pprefix,sizeof(prefix));                   //~v6y9I~
	if (pc && IS_RESERVED_NAME(pc))                                //~v6y9I~
    {                                                              //~v6y9I~
    	sprintf(prefix,"_%s",Pprefix);                             //~v6y9I~
        pprefix=prefix;                                            //~v6y9I~
    }                                                              //~v6y9I~
	if (!IS_UDMODE()                                               //~v6y8I~
    ||  (!strchr(Pdir,UD_NOTLC) && !strchr(Pprefix,UD_NOTLC)))     //~v6y8R~
    {                                                              //~v6y8I~
//  	pfnm=_tempnam(Pdir,Pprefix);                               //~v6y8R~//~v6y9R~
    	pfnm=_tempnam(Pdir,pprefix);                               //~v6y9I~
        return pfnm;                                               //~v6y8I~
    }                                                              //~v6y8I~
    opt=0; 	//drop UD                                              //~v6y8I~
#ifdef BBB                                                         //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,(char*)Pdir,wkfnmw,sizeof(wkfnmw),&ucsctr);//for profile record file no path sepc chk//~v6y8R~
#else                                                              //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,(char*)Pdir,wkfnmw,MAXBUFFSZ,&ucsctr);//for profile record file no path sepc chk//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc>=UDRC_ERR)                                              //~v6y8I~
    {                                                              //~v6y8I~
    	errno=EINVAL;                                              //~v6y8I~
    	return NULL;                                               //~v6y8I~
    }                                                              //~v6y8I~
//  rc=ufilecvUD2WCnopath(opt,(char*)Pprefix,prefixw,sizeof(prefixw),&ucsctr);//for profile record file no path sepc chk//~v6y8I~//~v6y9R~
#ifdef BBB                                                         //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,pprefix,prefixw,sizeof(prefixw),&ucsctr);//for profile record file no path sepc chk//~v6y9I~
#else                                                              //~v6HsI~
    rc=ufilecvUD2WCnopath(opt,pprefix,prefixw,MAXBUFFSZ,&ucsctr);//for profile record file no path sepc chk//~v6HsI~
#endif                                                             //~v6HsI~
    if (rc>=UDRC_ERR)                                              //~v6y8I~
    {                                                              //~v6y8I~
    	errno=EINVAL;                                              //~v6y8I~
    	return NULL;                                               //~v6y8I~
    }                                                              //~v6y8I~
	pfnmw=_wtempnam(wkfnmw,prefixw); //errno=2 for file not found and path not found//~v6y8R~
    if (pfnmw)                                                     //~v6y8R~
    {                                                              //~v6y8I~
        opt=UFCVO_NEW;    //chk and set UTF8WCSUBC if no ud was set//~v6y8I~
		rc=ufilecvWC2UD(opt,pfnmw,wktempnam,sizeof(wktempnam),&charctr,NULL/*wkpathtbl*/,0/*pathctr*/);//~v6y8R~
	    if (rc>=UDRC_ERR)  //1:detected utf7                       //~v6y8I~
    		errno=EINVAL;                                          //~v6y8I~
        else                                                       //~v6y8I~
        {                                                          //~v6y8I~
        	pfnm=malloc(strlen(wktempnam)+1);                      //~v6y8I~
            strcpy(pfnm,wktempnam);                                //~v6y8I~
		}                                                          //~v6y8I~
        free(pfnmw);                                               //~v6y8I~
    }                                                              //~v6y8I~
    UTRACEP("%s:pfnm=%p,errno=%d,lasterr=%d\n",UTT,pfnm);          //~v6y8I~
    return pfnm;                                                   //~v6y8I~
}//u_tempnamW                                                      //~v6y8R~
//***************************************************************  //~v6y9I~
//test by reservedname                                             //~v6y9I~
//***************************************************************  //~v6y9I~
int tryChdirForReservedName(char *Pfnm,int Prc)                    //~v6y9I~
{                                                                  //~v6y9I~
//  char wkfpath[_MAX_PATH],*pc;                                   //~v6y9I~//~v6H9R~
    char wkfpath[_MAX_PATH_LONG],*pc;                              //~v6H9I~
    int rc;                                                        //~v6y9I~
//*************************                                        //~v6y9I~
	rc=Prc;                                                        //~v6y9I~
	pc=Pfnm;                                                       //~v6y9I~
    pc=_fullpath(wkfpath,pc,sizeof(wkfpath));                      //~v6y9I~
	SswRsvNameTryFailed=0;                                         //~v6HnI~
    if (pc && IS_RESERVED_NAME(pc))                                //~v6y9I~
    {                                                              //~v6y9I~
		if (!adjustReservedName(Pfnm,wkfpath,sizeof(wkfpath)))     //~v6y9I~
	    	rc=_chdir(pc);                                         //~v6y9I~
        UTRACEP("%s:_chdir rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
        UTRACED("wkfpath",wkfpath,strlen(wkfpath));                //~v6HnI~
        if (!rc)                                                   //~v6yhI~
        	SlastReservedNameDriveLetter=(int)*(pc+RESERVED_NAMEID_CTR);//~v6yhR~
        else                                                       //~v6HnI~
			SswRsvNameTryFailed=1;                                 //~v6HnI~
    }                                                              //~v6y9I~
    return rc;                                                     //~v6y9I~
}//tryChdirForReservedName                                         //~v6y9I~
//***************************************************************  //~v6y9I~
//test by reservedname                                             //~v6y9I~
//***************************************************************  //~v6y9I~
int tryWChdirForReservedName(UWCH *Pfnmw,int Prc)                  //~v6y9I~//~v6yeR~//~v6HnR~
{                                                                  //~v6y9I~
//  UWCH wkfpathw[_MAX_PATHWC],*pw;                                //~v6y9I~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG],*pw;                           //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkfpathw,*pw;                                            //~v6HsI~
#endif                                                             //~v6HsI~
    int rc;                                                        //~v6y9I~
//*************************                                        //~v6y9I~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=SmaxbuffW2;                                           //~v6HsR~
#endif                                                             //~v6HsI~
	rc=Prc;                                                        //~v6y9I~
#ifdef BBB                                                         //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(sizeof(wkfpathw)));       //~v6y9I~
#else                                                              //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(MAXBUFFSZ));              //~v6HsI~
#endif                                                             //~v6HsI~
    if (pw && IS_RESERVED_NAME(pw))                                //~v6y9I~
    {                                                              //~v6y9I~
#ifdef BBB                                                         //~v6HsI~
		if (!adjustReservedNameW(Pfnmw,wkfpathw,sizeof(wkfpathw))) //~v6y9I~
#else                                                              //~v6HsI~
		if (!adjustReservedNameW(Pfnmw,wkfpathw,MAXBUFFSZ))        //~v6HsI~
#endif                                                             //~v6HsI~
        {                                                          //~v6HnI~
	    	rc=_wchdir(pw);                                        //~v6y9I~
    		UTRACEP("%s:_wchdir rsvname rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
    		UTRACED("wkfpathw",wkfpathw,strszW(wkfpathw));         //~v6HnI~
            if (rc)                                                //~v6HnI~
            {                                                      //~v6HnI~
            	memcpy(pw,WIN_LONGNAME_PREFIXW,ctr2szW(WIN_LONGNAME_PREFIXCTR));
		    	rc=_wchdir(pw);                                    //~v6HnI~
	        	UTRACEP("%s:_wchdir by long name rc=%d,errno=%d,lastError=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
    	    	UTRACED("pw",pw,strszW(pw));                       //~v6HnI~
            }                                                      //~v6HnI~
    	}	                                                       //~v6HnI~
        if (!rc)                                                   //~v6yhI~
        	SlastReservedNameDriveLetter=(int)*(pw+RESERVED_NAMEID_CTR);//~v6yhR~
    }                                                              //~v6y9I~
    return rc;                                                     //~v6y9I~
}//tryChdirWForReservedName                                        //~v6y9I~//~v6yeR~
//***************************************************************  //~v6yeI~
int tryMkdirForReservedName(char *Pfnm,int Prc)                    //~v6yeI~
{                                                                  //~v6yeI~
//  char wkfpath[_MAX_PATH],*pc;                                   //~v6yeI~//~v6H9R~
    char wkfpath[_MAX_PATH_LONG],*pc;                              //~v6H9I~
    int rc;                                                        //~v6yeI~
//*************************                                        //~v6yeI~
	rc=Prc;                                                        //~v6yeI~
	pc=Pfnm;                                                       //~v6yeI~
    pc=_fullpath(wkfpath,pc,sizeof(wkfpath));                      //~v6yeI~
	SswRsvNameTryFailed=0;                                         //~v6HnI~
    if (pc && IS_RESERVED_NAME(pc))                                //~v6yeI~
    {                                                              //~v6yeI~
		if (!adjustReservedName(Pfnm,wkfpath,sizeof(wkfpath)))     //~v6yeI~
        {                                                          //~v6HnI~
	    	rc=_mkdir(pc);                                         //~v6yeI~
			if (rc)                                                //~v6HnI~
				SswRsvNameTryFailed=1;                             //~v6HnI~
            UTRACEP("%s:_mkdir rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
    	    UTRACED("wkfpath",wkfpath,strlen(wkfpath));            //~v6HnI~
        }                                                          //~v6HnI~
    }                                                              //~v6yeI~
    return rc;                                                     //~v6yeI~
}//tryMkdirForReservedName                                         //~v6yeI~
//***************************************************************  //~v6yeI~
//test by reservedname                                             //~v6yeI~
//***************************************************************  //~v6yeI~
int tryWMkdirForReservedName(UWCH *Pfnmw,int Prc)                  //~v6yeI~//~v6HnR~
{                                                                  //~v6yeI~
//  UWCH wkfpathw[_MAX_PATHWC],*pw;                                //~v6yeI~//~v6H9R~
#ifdef BBB                                                         //~v6HsI~
    UWCH wkfpathw[_MAX_PATHWC_LONG],*pw;                           //~v6H9I~
#else                                                              //~v6HsI~
    UWCH *wkfpathw,*pw;                                            //~v6HsI~
#endif                                                             //~v6HsI~
    int rc;                                                        //~v6yeI~
//*************************                                        //~v6yeI~
#ifdef BBB                                                         //~v6HsI~
#else                                                              //~v6HsI~
    wkfpathw=SmaxbuffW2;                                           //~v6HsR~
#endif                                                             //~v6HsI~
	rc=Prc;                                                        //~v6yeI~
#ifdef BBB                                                         //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(sizeof(wkfpathw)));       //~v6yeI~
#else                                                              //~v6HsI~
    pw=_wfullpath(wkfpathw,Pfnmw,sz2ctrW(MAXBUFFSZ));              //~v6HsI~
#endif                                                             //~v6HsI~
    if (pw && IS_RESERVED_NAME(pw))                                //~v6yeI~
    {                                                              //~v6yeI~
#ifdef BBB                                                         //~v6HsI~
		if (!adjustReservedNameW(Pfnmw,wkfpathw,sizeof(wkfpathw))) //~v6yeI~
#else                                                              //~v6HsI~
		if (!adjustReservedNameW(Pfnmw,wkfpathw,MAXBUFFSZ))        //~v6HsI~
#endif                                                             //~v6HsI~
        {                                                          //~v6HnI~
	    	rc=_wmkdir(pw);                                        //~v6yeI~
            UTRACEP("%s:_wmkdir by rsvname rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
            UTRACED("pw",pw,strszW(pw));                           //~v6HnI~
            if (rc)                                                //~v6HnI~
            {                                                      //~v6HnI~
            	memcpy(pw,WIN_LONGNAME_PREFIXW,ctr2szW(WIN_LONGNAME_PREFIXCTR));//~v6HnI~
		    	rc=_wmkdir(pw);                                    //~v6HnI~
            	UTRACEP("%s:_wkdir by longname rc=%d,errno=%d,lasterr=%d\n",UTT,rc,errno,GetLastError());//~v6HnI~
	            UTRACED("pw",pw,strszW(pw));                       //~v6HnI~
            }                                                      //~v6HnI~
        }                                                          //~v6HnI~
    }                                                              //~v6yeI~
    return rc;                                                     //~v6yeI~
}//tryMkdirWForReservedName                                        //~v6yeI~
//**************************************************************** //~v6E3I~
//*get strlen of UD fmt stripped                                   //~v6E3I~
//**************************************************************** //~v6E3I~
int ufilestrlenUDstrip(int Popt,char *Ppud,int Pudlen)             //~v6E3I~
{                                                                  //~v6E3I~
    char *pc,*pc2;                                                 //~v6E3I~
    int reslen,len,udctr=0;                                        //~v6E3R~
//************************                                         //~v6E3I~
    UTRACED("inp",Ppud,Pudlen);                                    //~v6E3I~
	for (pc=Ppud,reslen=Pudlen;reslen>0;)                          //~v6E3I~
    {                                                              //~v6E3I~
    	pc2=memchr(pc,UD_NOTLC,reslen);                            //~v6E3I~
        if (pc2)                                                   //~v6E3I~
	        len=PTRDIFF(pc2,pc);                                   //~v6E3I~
        else                                                       //~v6E3I~
        	len=reslen;                                            //~v6E3I~
        pc+=len;                                                   //~v6E3I~
        reslen-=len;                                               //~v6E3I~
        if (!pc2)                                                  //~v6E3I~
        	break;                                                 //~v6E3I~
        udctr++;                                                   //~v6E3I~
        pc++;                                                      //~v6E3I~
        reslen--;                                                  //~v6E3I~
        if (reslen>0)                                              //~v6E3I~
        {                                                          //~v6E3I~
            if (*pc==UD_UTF8WCSUBC || *pc==UD_UTF8WC)              //~v6E3I~
            {                                                      //~v6E3I~
                udctr++;                                           //~v6E3I~
                pc++;                                              //~v6E3I~
		        reslen--;                                          //~v6E3I~
            }                                                      //~v6E3I~
        }                                                          //~v6E3I~
    }                                                              //~v6E3I~
    len=Pudlen-udctr;                                              //~v6E3I~
    UTRACEP("%s:rc=len=%d,udctr=%d",UTT,len,udctr);                //~v6E3I~
    return len;                                                    //~v6E3R~
}//ufilecvstripUD                                                  //~v6E3I~
//**************************************************************** //~v6F8I~
//*spli UD format by extension char "."                            //~v6F8I~
//**************************************************************** //~v6F8I~
int ufilesplitUDbyExtention(int Popt,char *Ppud,int Pudlen,char *Pout,int Pbuffsz,int *Ppoutlen)//~v6F8R~
{                                                                  //~v6F8I~
    char *pc,*pc2,*pc3,*pc4,*pco;                                  //~v6F8R~
    int reslen,len,udlen,rc,udtype,outreslen,outlen,reslen2;       //~v6F8R~
//************************                                         //~v6F8I~
	if (!Pudlen)                                                   //~v6F8I~
    	udlen=strlen(Ppud);                                        //~v6F8I~
    else                                                           //~v6F8I~
    	udlen=Pudlen;                                              //~v6F8I~
    UTRACED("inp",Ppud,udlen);                                     //~v6F8I~
	for (pc=Ppud,pco=Pout,reslen=udlen,outreslen=Pbuffsz;reslen>0 && outreslen>0;)//~v6F8I~
    {                                                              //~v6F8I~
    	pc2=memchr(pc,UD_NOTLC,(size_t)reslen);                    //~v6F8I~
        if (pc2)                                                   //~v6F8I~
	        len=PTRDIFF(pc2,pc);                                   //~v6F8I~
        else                                                       //~v6F8I~
        	len=reslen;                                            //~v6F8I~
        if (len>=outreslen)                                        //~v6F8I~
        	break;                                                 //~v6F8I~
        memcpy(pco,pc,(size_t)len);                                //~v6F8I~
        pc+=len;                                                   //~v6F8I~
        reslen-=len;                                               //~v6F8I~
        pco+=len;                                                  //~v6F8I~
        outreslen-=len;                                            //~v6F8I~
        if (!pc2)                                                  //~v6F8I~
        	break;                                                 //~v6F8I~
        if (!outreslen)                                            //~v6F8I~
        	break;                                                 //~v6F8I~
        *pco++=*pc2;    //starting NOTLC                           //~v6F8R~
        outreslen--;                                               //~v6F8I~
        pc=pc2+1;                                                  //~v6F8I~
        reslen--;                                                  //~v6F8I~
//*serach end of UD                                                //~v6F8I~
		udtype=*pc;                                                //~v6F8R~
    	pc3=memchr(pc,UD_NOTLC,(size_t)reslen);                    //~v6F8I~
        if (!pc3)        //no ending NOTLC                         //~v6F8R~
        	break;       //UD fmt err                              //~v6F8R~
	    len=PTRDIFF(pc3,pc)+1;      //include ending NOTLC         //~v6F8R~
//*serach "." in UD                                                //~v6F8I~
		for (reslen2=len;reslen2>0 && outreslen>0;)                //~v6F8I~
        {                                                          //~v6F8I~
    		pc4=memchr(pc,'.',(size_t)reslen2);                    //~v6F8R~
            if (!pc4)                                              //~v6F8I~
            	len=reslen2;                                       //~v6F8I~
            else                                                   //~v6F8I~
		        len=PTRDIFF(pc4,pc);                               //~v6F8I~
            if (len>outreslen)                                     //~v6F8I~
            	break;                                             //~v6F8R~
	    	memcpy(pco,pc,(size_t)len);  //UD string up to ending NOTLC or before "."//~v6F8I~
        	pc+=len;                                               //~v6F8I~
        	reslen2-=len;                                          //~v6F8I~
        	reslen-=len;                                           //~v6F8I~
        	pco+=len;                                              //~v6F8I~
	        outreslen-=len;                                        //~v6F8I~
            if (!pc4)                                              //~v6F8I~
            	break;                                             //~v6F8I~
	        if (outreslen<=4) //NOTLC,".",NOTLC,udtype             //~v6F8I~
    	    	break;                                             //~v6F8I~
        	*pco++=UD_NOTLC;                                       //~v6F8I~
            *pco++='.';                                            //~v6F8I~
        	*pco++=UD_NOTLC;                                       //~v6F8I~
        	*pco++=(char)udtype;                                   //~v6F8I~
    	    outreslen-=4;                                          //~v6F8I~
            pc++;                                                  //~v6F8I~
            reslen2--;                                             //~v6F8I~
            reslen--;                                              //~v6F8I~
        }                                                          //~v6F8I~
    }                                                              //~v6F8I~
    if (!outreslen)                                                //~v6F8I~
    	return 4;                                                  //~v6F8I~
    *pco=0;                                                        //~v6F8I~
    outlen=PTRDIFF(pco,Pout);                                      //~v6F8I~
    *Ppoutlen=outlen;                                              //~v6F8I~
    rc=(reslen?4:0);                                               //~v6F8I~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v6F8R~
    UTRACED("out",Pout,outlen);                                    //~v6F8I~
    return rc;                                                     //~v6F8R~
}//ufilesplitUDbyExtention                                         //~v6F8R~
//**************************************************************** //~v6F8I~
//*spli UD format by extension char "."                            //~v6F8I~
//rc:1:split last extention(set outbuff), 4:err                    //~v6F8R~
//**************************************************************** //~v6F8I~
int ufilesplitUDbyLastExtention(int Popt,char *Ppud,int Pudlen,char *Pout,int Pbuffsz,int *Ppoutlen,char **Ppextention)//~v6F8R~
{                                                                  //~v6F8I~
    char *pc,*pc2,*pc3,*pco;                                       //~v6F8R~
    int len,udlen,rc=0,udtype,outreslen,len2,len3,outlen;          //~v6F8R~
//************************                                         //~v6F8I~
	if (!Pudlen)                                                   //~v6F8I~
    	udlen=strlen(Ppud);                                        //~v6F8I~
    else                                                           //~v6F8I~
    	udlen=Pudlen;                                              //~v6F8I~
    UTRACED("inp",Ppud,udlen);                                     //~v6F8I~
    *Ppextention=0;                                                //~v6F8I~
	for (outreslen=Pbuffsz,pco=Pout;;)                             //~v6F8I~
    {                                                              //~v6F8I~
    	pc3=umemrchr(Ppud,UD_NOTLC,(size_t)udlen);   //last NOTLC  //~v6F8R~
    	if (!pc3)                                                  //~v6F8I~
    		break;            //rc=0                               //~v6F8I~
	    len3=PTRDIFF(pc3,Ppud);                                    //~v6F8I~
        if (memchr(pc3,'.',(size_t)(udlen-len3)))                  //~v6F8R~
        	break;	//"." after last UDstr                         //~v6F8I~
    	pc2=umemrchr(Ppud,UD_NOTLC,(size_t)len3);   //prev NOTLC   //~v6F8R~
    	if (!pc2)                                                  //~v6F8I~
        {                                                          //~v6F8I~
        	rc=4;                                                  //~v6F8I~
    		break;                                                 //~v6F8I~
        }                                                          //~v6F8I~
        udtype=*(pc2+1);                                           //~v6F8I~
	    len2=PTRDIFF(pc3,pc2);   //last UDstr len                  //~v6F8I~
    	pc=umemrchr(pc2,'.',len2);   //in last UDstr               //~v6F8R~
    	if (!pc)       //'.' not in udstr                          //~v6F8I~
    		break;      //rc=0                                     //~v6F8I~
	    len=PTRDIFF(pc,Ppud);   //up to last "."                   //~v6F8R~
        if (len>=outreslen)                                        //~v6F8I~
        {	                                                       //~v6F8I~
        	rc=4;                                                  //~v6F8I~
    		break;                                                 //~v6F8I~
        }                                                          //~v6F8I~
        UTRACEP("%s:1:len=%d\n",UTT,len);                          //~v6F8I~
        memcpy(pco,Ppud,(size_t)len);                              //~v6F8R~
        pco+=len;                                                  //~v6F8I~
        outreslen-=len;                                            //~v6F8I~
        if (4>=outreslen)                                          //~v6F8I~
        {                                                          //~v6F8I~
        	rc=4;                                                  //~v6F8I~
    		break;                                                 //~v6F8I~
        }                                                          //~v6F8I~
        *pco++=UD_NOTLC;                                           //~v6F8I~
        *pco++='.';                                                //~v6F8I~
        *Ppextention=pco;    //last extention part                 //~v6F8I~
        *pco++=UD_NOTLC;                                           //~v6F8I~
        *pco++=(char)udtype;                                       //~v6F8R~
        outreslen-=4;                                              //~v6F8I~
        pc++;   //next of last "."                                 //~v6F8I~
        len=udlen-PTRDIFF(pc,Ppud);                                //~v6F8I~
        if (len>=outreslen)                                        //~v6F8I~
        {                                                          //~v6F8I~
        	rc=4;                                                  //~v6F8I~
    		break;                                                 //~v6F8I~
        }                                                          //~v6F8I~
        UTRACEP("%s:2:len=%d\n",UTT,len);                          //~v6F8I~
        memcpy(pco,pc,(size_t)len);                                //~v6F8R~
        pco+=len;                                                  //~v6F8I~
        *pco=0;                                                    //~v6F8R~
        outlen=PTRDIFF(pco,Pout);                                  //~v6F8I~
        *Ppoutlen=outlen;                                          //~v6F8I~
        rc=1;                                                      //~v6F8I~
	    UTRACED("out",Pout,outlen);                                //~v6F8R~
        break;                                                     //~v6F8I~
    }                                                              //~v6F8I~
    UTRACEP("%s:rc=%d,extpos=%p\n",UTT,rc,*Ppextention);           //~v6F8R~
    return rc;                                                     //~v6F8I~
}//ufilesplitUDbyLastextension                                     //~v6F8R~
////***************************************************************  //~v6H9I~//~v6HaR~
////udirlist for longname                                            //~v6H9I~//~v6HaR~
////out:Pfpat                                                        //~v6H9I~//~v6HaR~
////***************************************************************  //~v6H9I~//~v6HaR~
//int udirlistWLong(int Popt,char * Pfnm,char *Pfpath/*optional output*/,size_t Pbuffsz,UINT Pattrmask,PUDIRLIST *Pppudl,int Psortopt)//~v6H9R~//~v6HaR~
//{                                                                  //~v6H9I~//~v6HaR~
//    int rc,ucsctr;                                                 //~v6H9R~//~v6HaR~
//    char fullpath[_MAX_PATH_LONG];                                 //~v6H9R~//~v6HaR~
//    UWCH fullpathw[_MAX_PATH_LONG];                                //~v6H9I~//~v6HaR~
////*****************************                                    //~v6H9I~//~v6HaR~
//    UTRACEP("%s:fnm=%s\n",UTT,Pfnm);                               //~v6H9I~//~v6HaR~
//    if (!u_fullpathWLong(0,fullpath,fullpathw,Pfnm,sizeof(fullpath),&ucsctr))//~v6H9R~//~v6HaR~
//        return -1;                                                 //~v6H9I~//~v6HaR~
//    if (Pbuffsz && ucsctr>=Pbuffsz)                                           //~v6H9I~//~v6HaR~
//        return -1;                                                 //~v6H9I~//~v6HaR~
//    if (Pbuffsz && Pfpath)                                                    //~v6H9I~//~v6HaR~
//        strcpy(Pfpath,fullpath);                                   //~v6H9R~//~v6HaR~
//    if (ucsctr<_MAX_PATH)                                          //~v6H9I~//~v6HaR~
//    {                                                              //~v6H9I~//~v6HaR~
//        return udirlist(fullpath,Pattrmask,Pppudl,Psortopt);       //~v6H9I~//~v6HaR~
//    }                                                              //~v6H9I~//~v6HaR~
//    if (ucsctr+WIN_LONGNAME_PREFIXCTR>=_MAX_PATH_LONG)             //~v6H9I~//~v6HaR~
//    {                                                              //~v6H9I~//~v6HaR~
//        ufileTooLongFullpathName2(0,fullpath,0);                   //~v6H9R~//~v6HaR~
//        return -1;                                                 //~v6H9I~//~v6HaR~
//    }                                                              //~v6H9I~//~v6HaR~
//    rc=udirlistW(0,fullpath,fullpathw,Pattrmask,Pppudl,Psortopt);  //~v6H9R~//~v6HaR~
//    UTRACEP("%s:filectr=%d,errno=%d,lasterr=%d\n",UTT,rc);         //~v6H9I~//~v6HaR~
//    return rc;                                                     //~v6H9I~//~v6HaR~
//}//udirlistWLong                                                   //~v6H9R~//~v6HaR~
#ifdef AAA                                                         //~v6HsI~
//***************************************************************  //~v6H9I~
//udirlist for longname                                            //~v6H9I~
//out:Pfpat                                                        //~v6H9I~
//***************************************************************  //~v6H9I~
HDIR uFindFirstFileWLong(int Popt,char * Pfnm,UWCH *PfnmW,WIN32_FIND_DATAW *Pw32fdW)//~v6H9R~
{                                                                  //~v6H9I~
	int ctr;                                                       //~v6H9R~
    UWCH fpathw[_MAX_PATH_LONG],*pw;                               //~v6H9I~
    HDIR hdir;                                                     //~v6H9I~
//*****************************                                    //~v6H9I~
	ctr=WIN_LONGNAME_PREFIXCTR;                                    //~v6H9I~
    if (memcmp(PfnmW,WIN_LONGNAME_PREFIXW,(size_t)ctr2szW(ctr)))   //~v6H9I~
    {                                                              //~v6H9I~
		memcpy(fpathw,WIN_LONGNAME_PREFIXW,(size_t)ctr2szW(ctr));  //~v6H9I~
        strcpyW(fpathw+ctr,PfnmW);                                 //~v6H9R~
        pw=fpathw;                                                 //~v6H9I~
    }                                                              //~v6H9I~
    else                                                           //~v6H9I~
        pw=PfnmW;                                                  //~v6H9I~
    UTRACEP("%s:fnm=%s\n",UTT,Pfnm);                               //~v6H9I~
    UTRACED("fnmW",pw,strszW(pw));                                 //~v6H9I~
	hdir=FindFirstFileW(pw,Pw32fdW);                               //~v6H9R~
    UTRACEP("%s:handle=%p,errno=%d,lasterr=%d\n",UTT,hdir,errno,GetLastError());//~v6H9R~
    return hdir;                                                   //~v6H9R~
}//uFindFirstFileWLong                                             //~v6H9R~
//***************************************************************  //~v6HeI~
//fopenW for longname (\\?\ fmt filename)                          //~v6HeI~
//out:Pfpat                                                        //~v6HeI~
//***************************************************************  //~v6HeI~
FILE *ufopenWLong(int Popt,UWCH *PfnmW,UWCH *PopenoptW)            //~v6HeI~
{                                                                  //~v6HeI~
	int optaccess,optdisp,optattr,optopen;                         //~v6HeI~
    int osfh;                                                      //~v6HeI~
    FILE *fh;                                                      //~v6HeI~
    HANDLE hh;                                                     //~v6HeI~
    int swwrite,swappend,swtext,lasterr,err;                       //~v6HeI~
//*****************************                                    //~v6HeI~
	swwrite=strchrW(PopenoptW,'w')?1:0;                            //~v6HeI~
    swappend=strchrW(PopenoptW,'a')?1:0;                           //~v6HeI~
    swtext=strchrW(PopenoptW,'b')?0:1;                             //~v6HeI~
    	                                                           //~v6HeI~
	if (swappend||swwrite)                                         //~v6HeI~
		optdisp=OPEN_ALWAYS;                                       //~v6HeI~
    else                                                           //~v6HeI~
		optdisp=OPEN_EXISTING;                                     //~v6HeI~
	optaccess=GENERIC_READ|GENERIC_WRITE;                          //~v6HeI~
	optattr=FILE_ATTRIBUTE_NORMAL;                                 //~v6HeI~
                                                                   //~v6HeI~
	hh=CreateFileW(PfnmW,optaccess,0/*share*/,NULL/*security desc*/,optdisp,optattr,NULL/*template handle*/);//~v6HeI~
    lasterr=GetLastError();                                        //~v6HeI~
                                                                   //~v6HeI~
	UTRACEP("%s:CreateFileW rc=hh=%d,lasterr=%d\n",UTT,hh,lasterr);//~v6HeR~
	UTRACED("CreateFileW fnmw",PfnmW,strszW(PfnmW));               //~v6HeI~
    if (hh==INVALID_HANDLE_VALUE)                                  //~v6HeI~
    {                                                              //~v6HeI~
    	errno=lasterr;                                             //~v6HeI~
    	return NULL;   //FILE*                                     //~v6HeI~
    }                                                              //~v6HeI~
    optopen=0;                        //_O_TEXT,_O_APPEND,_O_RDONLY,_O_WTEXT//~v6HeI~
	if (swappend)                                                  //~v6HeI~
    	optopen|=_O_APPEND;                                        //~v6HeI~
	if (swtext)                                                    //~v6HeI~
    	optopen|=_O_TEXT;                                          //~v6HeI~
                                                                   //~v6HeI~
    osfh=_open_osfhandle((intptr_t)hh,optopen);                    //~v6HeI~
    err=errno;                                                     //~v6HeI~
    UTRACEP("%s:_open_osfhandle rc=osfh=%d,errno=%d\n",UTT,osfh,err);//~v6HeI~
    if (osfh<0)	//-1 when err                                      //~v6HeI~
    {                                                              //~v6HeI~
    	return NULL;   //FILE*                                     //~v6HeI~
    }                                                              //~v6HeI~
                                                                   //~v6HeI~
    fh=_wfdopen(osfh,PopenoptW);                                   //~v6HeI~
    err=errno;                                                     //~v6HeI~
    UTRACEP("%s:_wfdopen rc=fh=%x,errno=%d\n",UTT,fh,err);         //~v6HeI~
    return fh;                                                     //~v6HeI~
}//ufopenWLong                                                         //~v6HeI~//~v6HsR~
#endif //AAA                                                       //~v6HsI~
