//*CID://+v6J0R~:                             update#=109;         //~v6J0R~
//******************************************************
//*ulibdefw.h
//******************************************************           //~v6uYI~
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6Hp:170121 UstrncpyZW may clear source field                    //~v6HpI~
//v6Hc:170114 (Win)_MAX_PATH is wchar ctr,for dbcs size is doubled.(dir=240,file=255)//~v6HcI~
//v6H9:170109 (Win)del longname using \\?\ prefix(path max is 32767) and Unicode API because move to shortpath dir could not delete dir/file name longer >=260.//~v6H9I~
//v6A0:150614 (BUG)doseditname for UD string,copying stops at starting UD_NOTLC(0x01)//~v6A0I~
//v6y8:150312 _tempnam wait for prefix:aux(filebkupreopen)         //~v6y8I~
//v6w0:141108 (Win:BUG)windows BUG:_fullpath/_wfullpath returns \\.\prn for g:\src\xe\prn//~v6w0I~
//            and returns invalid name(\\.\g:\src\xe\prn is effective)//~v6w0I~
//v6uY:140613 (LNX)f2u accept always UCS4 like as W32              //~v6uYI~
//******************************************************
//#ifdef W32                                                       //~v6u9R~
//    #define _MAX_PATHWC  260   //UWCH count                      //~v6u9R~
//    #define _MAX_PATHU8  ((int)(_MAX_PATHWC*UTF8_MAXCHARSZ))     //~v6u9R~
//    #define PUSH_MAXPATH                                         //~v6u9R~
//    #pragma push_macro("_MAX_PATH")                              //~v6u9R~
//    #undef _MAX_PATH                                             //~v6u9R~
//    #define _MAX_PATH   _MAX_PATHU8                              //~v6u9R~
//#else    //!W32                                                  //~v6u9R~
//  #define _MAX_PATHWC  _MAX_PATH                                 //~v6u9M~//~v6HcR~
    #define _MAX_PATHWC  MAX_PATH_CTR                              //~v6HcR~
//  #define _MAX_PATHWC_LONG  _MAX_PATH_LONG                       //~v6H9I~//~v6HcR~
    #define _MAX_PATHWC_LONG  MAX_PATH_CTR_LINUX                   //~v6HcR~
//  #define _MAX_PATHU8  ((int)(_MAX_PATHWC*UTF8_MAXCHARSZ))       //~v6u9I~//~v6HcR~
    #define _MAX_PATHU8  MAX_PATH_UTF8    //*4                     //~v6HcI~
//#endif   //!W32                                                  //~v6u9R~
    #define MAXPATHLVL     (_MAX_PATHWC/2)                         //~v6u9M~
    #define _MAX_PATHF2L   ((int)(_MAX_PATH*UTF8_F2LMAXRATE))      //~v6u9I~
//*****************************************                        //~v6u9R~
//=====================                                            //~v6u9M~
#ifdef W32                                                         //~v6u9I~
	#define W32UNICODE	//unicode mode                             //~v6u9I~
                                                                   //~v6u9I~
//	typedef unsigned short UWCH,*PUWCH; //for filename utf16(unsigned short)//~v6u9I~//~v6uYR~
//	#define UWCHSZ           sizeof(UWCH)                          //~v6u9I~//~v6uYR~
                                                                   //~v6u9I~
#ifndef NO_MACRO_REDIRECT                                          //~v6u9M~
//*fopen                                                           //~v6u9I~
    #define PUSH_FOPEN
    #pragma push_macro("fopen")                                    //~v6u9R~
    #undef fopen
    #define fopen(fnm,opt)    ufopenW(0,fnm,opt)
	#ifdef _INC_STDIO                                                //~v6u9I~//~v6uaI~//~v6u9I~
    	FILE *ufopenW(int,const char *,const char *);                  //~v6uaM~//~v6u9I~
	#endif                                                           //~v6u9I~//~v6uaI~//~v6u9I~
//*_tempnam                                                        //~v6y8I~
    #define PUSH_TEMPNAM                                           //~v6y8I~
    #pragma push_macro("_tempnam")                                 //~v6y8I~
    #undef _tempnam                                                //~v6y8I~
    #define _tempnam(dir,prefix)    u_tempnamW(dir,prefix)         //~v6y8I~
	char *u_tempnamW(const char *,const char *);                   //~v6y8I~
//*_fullpath                                                       //~v6u9I~
    #define PUSH_FULLPATH
    #pragma push_macro("_fullpath")                                //~v6u9R~
    #undef _fullpath
    #define _fullpath(fpath,src,sz)    u_fullpathW(0,fpath,src,sz)
	char *u_fullpathW(int,char *,const char *,size_t);                 //~v6uaI~//~v6u9I~
//*remove                                                          //~v6u9I~
    #define PUSH_REMOVW                                            //~v6u9I~
    #pragma push_macro("remode")                                   //~v6u9I~
    #undef remode                                                  //~v6u9I~
    #define remove(fnm)    uremoveW(0,fnm)                         //~v6u9I~
	int uremoveW(int,char *);                                      //~v6u9R~
//*rmdir                                                           //~v6u9I~
    #define PUSH_RMDIR                                             //~v6u9I~
    #pragma push_macro("rmdir")                                    //~v6u9I~
    #undef rmdir                                                   //~v6u9I~
    #define rmdir(fnm)    urmdirW(0,fnm)                           //~v6u9I~
	int urmdirW(int,char *);                                       //~v6u9R~
//*mkdir                                                           //~v6u9I~
    #define PUSH_MKDIR                                             //~v6u9I~
    #pragma push_macro("mkdir")                                    //~v6u9I~
    #undef mkdir                                                   //~v6u9I~
    #define mkdir(fnm)    umkdirW(0,fnm)                           //~v6u9I~
	int umkdirW(int,char *);                                       //~v6u9I~
//*chdir                                                           //~v6u9I~
    #define PUSH_CHDIR                                             //~v6u9I~
    #pragma push_macro("chdir")                                    //~v6u9I~
    #undef chdir                                                   //~v6u9I~
    #define chdir(fnm)    uchdirW(0,fnm)                           //~v6u9I~
	int uchdirW(int,char *);                                       //~v6u9I~
    //************************************                         //~v6u9I~
//*FindFirstFile                                                   //~v6u9I~
        #define  WIN32_FIND_DATA     WIN32_FIND_DATAW              //~v6uaI~//~v6u9M~
        #define  LPWIN32_FIND_DATA   LPWIN32_FIND_DATAW            //~v6uaI~//~v6u9M~
//*FindFirstFile                                                   //~v6uaI~//~v6u9M~
        #ifdef FindFirstFile                                       //~v6uaI~//~v6u9M~
              #undef FindFirstFile                                 //~v6uaI~//~v6u9M~
        #endif                                                     //~v6uaI~//~v6u9M~
        #define  FindFirstFile(pfnm,pfinddata) uFindFirstFileW(pfnm,pfinddata,0/*opt*/,NULL/*PfnmW*/,0/*Pbuffsz*/,NULL/*Ppucsctr*/)//~v6uaI~//~v6u9M~
                                                                   //~v6u9I~
		#if defined(_WINBASE_) && defined(_WINNT_)    //winbase(FIND_DATA) and winnt(HANDLE)//~v6u9R~
			HANDLE uFindFirstFileW(char *Pfnm,WIN32_FIND_DATAW *Ppw32fd,int Popt,UWCH *PfnmW,int Pbuffsz,int *Ppucsctr);//~v6u9I~//~v6uaI~//~v6u9R~
		#endif              //windows.h included                           //~v6uaI~//~v6u9I~
//*FindNextFile                                                    //~v6uaI~//~v6u9M~
        #ifdef FindNextFile                                        //~v6uaI~//~v6u9M~
              #undef FindNextFile                                  //~v6uaI~//~v6u9M~
        #endif                                                     //~v6uaI~//~v6u9M~
        #define  FindNextFile(hdir,pfinddata) FindNextFileW(hdir,pfinddata)//~v6uaI~//~v6u9M~
//*GetShortPathName                                                //~v6uaI~//~v6u9M~
        #ifdef GetShortPathName                                    //~v6uaI~//~v6u9M~
              #undef GetShortPathName                              //~v6uaI~//~v6u9M~
        #endif                                                     //~v6uaI~//~v6u9M~
        #define  GetShortPathName(longname,shortname,buffsz) uGetShortPathNameW(longname,shortname,buffsz,0/*opt*/,NULL/*PfnmW*/,0/*PbuffszW*/,NULL/*Ppucsctr*/,NULL/*Ppudfmt*/)//~v6uaR~//~v6u9M~
                                                                   //~v6u9I~
		#ifdef _WINBASE_    //windows.h included                   //~v6u9I~
			int uGetShortPathNameW(char *Plongfnm,char *Pshortfnm,int Pbuffsz,int Popt,UWCH *PshortfnmW,int PbuffszW,int *Ppucsctr,int *Ppudfmt);//~v6uaI~//~v6u9I~
		#endif              //windows.h included                           //~v6uaI~//~v6u9I~
//*SetFileAttributes                                               //~v6u9I~
        #ifdef SetFileAttributes                                   //~v6u9I~
              #undef SetFileAttributes                             //~v6u9I~
        #endif                                                     //~v6u9I~
        #define  SetFileAttributes(filename,dwAttr) uSetFileAttributesW(filename,dwAttr,0/*opt*/,NULL/*PfnmW*/,0/*PbuffszW*/,NULL/*Ppucsctr*/)//~v6u9R~
                                                                   //~v6u9I~
		#ifdef _WINBASE_    //windows.h included                   //~v6u9I~
			BOOL uSetFileAttributesW(char *Pfnm,DWORD Pdwattr,int Popt,UWCH *PfnmW,int Pbuffsz,int *Ppucsctr);//~v6uaR~//~v6u9I~
		#endif              //windows.h included                           //~v6uaI~//~v6u9I~
//*MoveFile                                                        //~v6u9I~
        #ifdef MoveFile                                            //~v6u9I~
              #undef MoveFile                                      //~v6u9I~
        #endif                                                     //~v6u9I~
        #define  MoveFile(old,new) uMoveFileW(old,new,0/*opt*/)    //~v6u9I~
                                                                   //~v6u9I~
		#ifdef _WINBASE_    //windows.h included                   //~v6u9I~
			BOOL uMoveFileW(char *Pold,char *Pnew,int Popt);       //~v6u9R~
        #endif                                                     //~v6u9I~
//*MoveFileEx                                                      //~v6u9I~
        #ifdef MoveFileEx                                          //~v6u9I~
              #undef MoveFileEx                                    //~v6u9I~
        #endif                                                     //~v6u9I~
        #define  MoveFileEx(old,new,flags) uMoveFileExW(old,new,flags,0/*opt*/)//~v6u9R~
                                                                   //~v6u9I~
		#ifdef _WINBASE_    //windows.h included                   //~v6u9I~
			BOOL uMoveFileExW(char *Pold,char *Pnew,DWORD Pflags,int Popt);//~v6u9R~
        #endif                                                     //~v6u9I~
//*CreateFile                                                      //~v6u9I~
        #ifdef CreateFile                                          //~v6u9I~
              #undef CreateFile                                    //~v6u9I~
        #endif                                                     //~v6u9I~
        #define  CreateFile(fnm,access,share,aecattr,disp,attr,handle) uCreateFileW(fnm,access,share,aecattr,disp,attr,handle,0/*opt*/)//~v6u9I~
                                                                   //~v6u9I~
		#ifdef _WINBASE_    //windows.h included                   //~v6u9I~
			HANDLE uCreateFileW(const char *Pfnm,DWORD Pacc,DWORD Pshare,LPSECURITY_ATTRIBUTES secattr,DWORD Pdisp,DWORD Pattr,HANDLE Phtemp,int Popt);//~v6u9R~
        #endif                                                     //~v6u9I~
//*GetFileAttributesEx                                             //~v6u9R~
        #ifdef GetFileAttributesEx                                 //~v6u9R~
              #undef GetFileAttributesEx                           //~v6u9R~
        #endif                                                     //~v6u9I~
        #define  GetFileAttributesEx(fnm,infolvl,pinfo) uGetFileAttributesExW(fnm,infolvl,pinfo,0/*opt*/,NULL/*outucs2*/,0/*buffsz*/,NULL/*outucsctr*/)//~v6u9R~
                                                                   //~v6u9I~
		#ifdef _WINBASE_    //windows.h included                   //~v6u9I~
			BOOL uGetFileAttributesExW(const char *Pfnm,GET_FILEEX_INFO_LEVELS Pinfolvl,LPVOID Ppinfo,int Popt,UWCH *Poutucs2,int Pbuffsz,int *Ppucsctr);//~v6u9R~
        #endif                                                     //~v6u9I~
//*GetDiskFreeSpace                                                //~v6u9I~
        #ifdef GetDiskFreeSpace                                    //~v6u9I~
              #undef GetDiskFreeSpace                              //~v6u9I~
        #endif                                                     //~v6u9I~
        #define  GetDiskFreeSpace(fnm,sector,bytes,free,total) uGetDiskFreeSpaceW(fnm,sector,bytes,free,total,0/*opt*/)//~v6u9R~
                                                                   //~v6u9I~
		#ifdef _WINBASE_    //windows.h included                   //~v6u9I~
			BOOL uGetDiskFreeSpaceW(char *Pfnm,LPDWORD lpSectorsPerCluster,LPDWORD lpBytesPerSector,LPDWORD lpNumberOfFreeClusters,LPDWORD lpTotalNumberOfClusters,int Popt);//~v6u9I~
        #endif                                                     //~v6u9I~
#endif //!NO_MACRO_REDIRECT
//*****************************************

#define strctrW(pwucs)   ((pwucs)?(int)wcslen((const wchar_t *)pwucs):0)//~v6u9R~
//#define strnctrW(pwucs,len)   (memchrW(pwucs,0,len) ? (int)strctrW(pwucs) : (int)(len))//~v6HcI~//~v6HpR~
#define strnctrWlen(pwucs,len)   (memchrW(pwucs,0,sz2ctr(len)) ? (int)strctrW(pwucs) : (int)(len))//~v6HpI~
#define strnctrWctr(pwucs,ctr)   (memchrW(pwucs,0,ctr) ? (int)strctrW(pwucs) : (int)(ctr))//~v6HpR~
#define strszW(pwucs)    (strctrW(pwucs)*(int)UWCHSZ)
#define sz2ctrW(wucs)    ((wucs)/(int)UWCHSZ)
#define ctr2szW(wucsctr) ((wucsctr)*(int)UWCHSZ)
#define strcatW(tgt,src) wcscat(tgt,src)
#define strcatW(tgt,src) wcscat(tgt,src)
#define strchrW(tgt,ch)  wcschr(tgt,ch)
#define memchrW(tgt,ch,ctr)  wmemchr(tgt,ch,ctr)                   //~v6u9R~
#define strrchrW(tgt,ch) wcsrchr(tgt,ch)
#define stricmpW(f1,f2)  _wcsicmp(f1,f2)                           //~v6u9R~
#define memsetW(tgt,ch,ctr)  wmemset(tgt,ch,ctr)                   //~v6w0I~
//#define memcmpW(f1,f2)   wmemcmp(f1,f2)                          //~v6w0R~
#define memcmpW(f1,f2,ctr)   wmemcmp(f1,f2,ctr)                    //~v6w0I~
//#define memicmpW(f1,f2)  _wmeimcmp(f1,f2)                        //~v6w0R~
//#define memicmpW(f1,f2,ctr)  _wmeimcmp(f1,f2,ctr)                  //~v6w0I~//+v6J0R~
#define memicmpW(tgt,src,wktgt,wksrc,ctr) /*prepare enough size of work buff because _wcsupr update in the replace*/ \
		(strcpyW(wktgt,tgt),strcpyW(wksrc,src),_wcsupr(wktgt),_wcsupr(wksrc),memcmpW(wktgt,wksrc,ctr))//~8811R~//+v6J0M~
#define strcpyW(tgt,src)   memcpy(tgt,src,strszW(src)+(int)UWCHSZ)
#define strpbrkW(tgt,src)  wcspbrk(tgt,src)
#define strstrW(tgt,src)   wcsstr(tgt,src)                         //~v6w0I~
#define strstriW(tgt,src,wktgt,wksrc) /*prepare enough size of work buff because _wcsupr update in the replace*/ \
		(strcpyW(wktgt,tgt),strcpyW(wksrc,src),strstrW(_wcsupr(wktgt),_wcsupr(wksrc)))//+v6J0I~
#define strspnW(tgt,src)   wcsspn(tgt,src)  //return ctr           //~v6A0I~
#define memcpyWctr(tgt,src,ctr)    memcpy(tgt,src,ctr2szW(ctr))    //~v6u9I~
#define UmemcpyZWctr(tgt,src,ctr)  memcpyWctr(tgt,src,ctr),*((PUWCH)(tgt)+(ctr))=0//~v6u0R~//~v6u9R~
#define UmemcpyZWszctr(tgt,src,sz,ctr)                      \
		do{                                               \
            int _ctr;                                     \
            _ctr=min(sz2ctrW(sz)-1,ctr);         \
            memcpy(tgt,src,ctr2szW(_ctr));                         \
            *(tgt+_ctr)=0;                                \
        }while(0)                                                  //~v6u9I~
#define memdupW(tgt,src,ctr)  *(tgt)=umalloc(ctr2szW(ctr)),(*(tgt)?memcpy(*(tgt),src,ctr2szW(ctr)):NULL)//~v6u0R~//~v6u9M~
#define strdupW(tgt,src)  *(tgt)=umalloc(strszW(src)+UWCHSZ),(*(tgt)?memcpy(*(tgt),src,strszW(src)+UWCHSZ):NULL)//~v6u0R~//~v6u9M~
//**********************************************************************//~v6u9R~
//#define UstrncpyZW(to,from,len)  memset(to,0,len),memmove(to,from,min(ctr2szW(sz2ctrW(len-2)),strszW((PWCH)from)))//~v6u9M~//~v6HpR~
//#define UstrncpyZWctr(to,from,ctr)  memset(to,0,ctr2szW(ctr)),memmove(to,from,ctr2szW(min((ctr)-1,strctrW((PWCH)from))))//~v6u9I~//~v6HpR~
#define UstrncpyZW(to,from,len)  \
		do{                                               \
            int _ctr,_ctr2,_res;                          \
            _ctr2=sz2ctrW(len);                           \
            _ctr=strnctrWctr(from,_ctr2);                    \
            if (_ctr==_ctr2)                              \
            	_ctr--;                                   \
            memmove(to,from,ctr2szW(_ctr));               \
            _res=(len)-ctr2szW(_ctr);                     \
            if (_res>0)                                   \
            	memset(to+_ctr,0,_res);                   \
        }while(0)                                                  //~v6HpI~
//*strcpy winthin tgt size with guaranty of last null              //~v6J0I~
#define UstrcpyZW(to,from,len)  \
		do{                                               \
            int _ctr,_ctr2,_res;                          \
            _ctr2=sz2ctrW(len);                           \
            _ctr=strnctrWctr(from,_ctr2);                    \
            if (_ctr==_ctr2)                              \
            	_ctr--;                                   \
            memmove(to,from,ctr2szW(_ctr));               \
            _res=(len)-ctr2szW(_ctr);                     \
            if (_res>0)                                   \
            	*(to+_ctr)=0;                        \
        }while(0)                                                  //~v6J0I~
#define UstrncpyZWctr(to,from,ctr) \
		do{                                               \
            int _ctr,_res;                                \
            _ctr=strnctrWctr(from,(ctr));                 \
            if (_ctr==(ctr))                              \
            	_ctr--;                                   \
            memmove(to,from,ctr2szW(_ctr));               \
            _res=(ctr)-_ctr;                              \
            if (_res>0)                                   \
            	memset(to+_ctr,0,ctr2szW(_res));          \
        }while(0)                                                  //~v6HpI~
//*strcpy winthin tgt size by ctr with guaranty of last null       //~v6J0I~
#define UstrcpyZWctr(to,from,ctr) \
		do{                                               \
            int _ctr,_res;                                \
            _ctr=strnctrWctr(from,(ctr));                 \
            if (_ctr==(ctr))                              \
            	_ctr--;                                   \
            memmove(to,from,ctr2szW(_ctr));               \
            _res=(ctr)-_ctr;                              \
            if (_res>0)                                   \
            	*(to+_ctr)=0;                        \
        }while(0)                                                  //~v6J0I~
                                                                   //~v6u9M~
#define STRCPY_CATW_ASCII(Ppw,Ppc,Poffs)\
		do{                                               \
            char *_pc; UWCH *_pw;                           \
            for(_pw=(Ppw)+(Poffs),_pc=(char*)(Ppc);*_pc;)    \
            	*_pw++=(UWCH)*_pc++;                        \
            *_pw=0;                                        \
        }while(0)                                                  //~v6u9M~
#define strcpyW_ASCII(Ppw,Ppc)  STRCPY_CATW_ASCII(Ppw,Ppc,0/*offset*/)//~v6u9M~
#define strcatW_ASCII(Ppw,Ppc)  STRCPY_CATW_ASCII(Ppw,Ppc,strctrW(Ppw))//~v6u9M~
                                                                   //~v6u9M~
#define umemcpyZ_ASCII2W(Ppw,Ppc,Pctr)\
		do{                                               \
            char *_pc; UWCH *_pw;                            \
            int ii=Pctr;                                 \
            for(_pw=(Ppw),_pc=(char*)(Ppc);ii>0;ii--)    \
            	*_pw++=(UWCH)*_pc++;                           \
            *_pw=0;                                            \
        }while(0)                                                  //~v6u9M~
#define umemcpyZ_W2ASCII(Ppc,Ppw,Pctr)\
		do{                                               \
            char *_pc; UWCH *_pw;                            \
            int ii=Pctr;                                 \
            for(_pw=(Ppw),_pc=(char*)(Ppc);ii>0;ii--)    \
            	*_pc++=(char)*_pw++;                           \
            *_pc=0;                                            \
        }while(0)                                                  //~v6u9I~
#define STRNCPY_ZW_ASCII(Ppw,Ppc,Pctr,Pz)\
		do{                                               \
            char *_pc; UWCH *_pw;                            \
            int ii=Pctr-Pz;                                 \
            for(_pw=(Ppw),_pc=(char*)(Ppc);*_pc && ii>0;ii--)    \
            	*_pw++=(UWCH)*_pc++;                           \
            memset(_pw,0,ctr2szW(ii+Pz));                     \
        }while(0)                                                  //~v6u9M~
#define UstrncpyZW_ASCII(Ppw,Ppc,Pctr) STRNCPY_ZW_ASCII(Ppw,Ppc,Pctr,1/*strz*/)//~v6u9M~
#define strncpyW_ASCII(Ppw,Ppc,Pctr) STRNCPY_ZW_ASCII(Ppw,Ppc,Pctr,0)//~v6u9M~
//=====================
#endif //W32                                                       //~v6u9I~
