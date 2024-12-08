//*CID://+v6T4R~:                             update#=266;         //+v6T4R~
//******************************************************
//*ufilew.h
//******************************************************
//v6T4:180217 f2l option to set dbcs "?" for f2l err               //+v6T4I~
//v6J1:170206 errmsg loop when UD fmt err(uerrmsg->ufprintf->ufilecvUD2Wnopath->uerrmsg);occued when !UD_MODE()//~v6J1I~
//v6Hn:170120 (Win)when not too long but little bit short path fails when rsv name//~v6HnI~
//v6Hg:170117 (Win)CreateDirectory maxpath is 248                  //~v6HgI~
//v6Hc:170114 (Win)_MAX_PATH is wchar ctr,for dbcs size is doubled.(dir=240,file=255)//~v6H9I~
//v6H9:170109 (Win)del longname using \\?\ prefix(path max is 32767) and Unicode API because move to shortpath dir could not delete dir/file name longer >=260.//~v6H9I~
//v6Eb:160729 (BUG) err msg "Invalid FileNAme Format" when saved cmd stack contains UD format char(0x01 etc)//~v6EbI~
//v6E3:160718 (W32)add ufilestrlenUDstrip for dirlist green attr len//~v6E3I~
//v6B1:160114 trace,mtrace file no share mode                      //~v6B1I~
//v6yg:150314 avoid \\.\ is displayed on errmsg                    //~v6ygI~
//v6w0:141108 (Win:BUG)windows BUG:_fullpath/_wfullpath returns \\.\prn for g:\src\xe\prn//~v6w0I~
//            and returns invalid name(\\.\g:\src\xe\prn is effective)//~v6w0I~
//v6un:140502 MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;pass it not W func as is//~v6unI~
//v6uj:140501 (Win:UNICODE)open ufilecvUD2WCnopath                 //~v6ujI~
//vauc:140420 (Win)unicode support by UD fmt string                //~v6ucI~
//v6ua:140410 (Win)use UNICODE Api;apply WIN32_FIND_DATAW by "#ifdef W32UNICODE"//~v6uaR~
//v6u9:140408 (Win)use UNICODE Api using special filename fmt.     //~v6u9I~
//******************************************************           //~v6u9I~
#ifdef W32                                                         //~v6u9I~
//================================================================
#ifdef GBL_UFILEW                                                  //~v6uaI~
//    UWCH Gufilew_findfirstnameW[_MAX_PATHWC];                    //~v6uaR~
//    int  Gufilew_findfirstnameWctr;                              //~v6uaR~
#else                                                              //~v6uaI~
//    extern UWCH Gufilew_findfirstnameW[_MAX_PATHWC];             //~v6uaR~
//    extern int  Gufilew_findfirstnameWctr;                       //~v6uaR~
#endif                                                             //~v6uaI~
#define RESERVED_NAMEIDW     L"\\\\.\\"                            //~v6w0M~
#define RESERVED_NAMEID       "\\\\.\\"                            //~v6w0I~
#define RESERVED_NAMEID_CTR 4                                      //~v6w0R~
#define IS_RESERVED_NAME(fpath) \
			(*(fpath)=='\\' && *(fpath+1)=='\\' && *(fpath+2)=='.' && *(fpath+3)=='\\')//~v6w0R~
#define IS_RESERVED_NAME_FULLPATH(fpath) \
			(IS_RESERVED_NAME(fpath) && *(fpath+5)==':')           //~v6w0R~
#define WIN32_DRIVEID(fpath) \
		toupper(             \
			(IS_RESERVED_NAME(fpath) ? *(fpath+4)) : *(fpath) \
               )                                                   //~v6w0I~
#define STD_FNM(fpath) \
        ( IS_RESERVED_NAME(fpath) ? ((fpath)+RESERVED_NAMEID_CTR) :(fpath) )//~v6ygI~
#define WIN_LONGNAME_PREFIX      "\\\\?\\"                         //~v6H9I~
#define WIN_LONGNAME_PREFIXCTR   4                                 //~v6H9I~
#define WIN_LONGNAME_PREFIXW     L"\\\\?\\"                        //~v6H9I~
#define IS_WIN_LONGNAME_PREFIX(pc)  \
     				((int)(*(pc))=='\\' && (int)(*((pc)+1))=='\\' && (int)(*((pc)+2))=='?' && (int)(*((pc)+3))=='\\')//~v6H9M~
//#define IS_WIN_LONGPATH(pc)  (ustrnlen(pc,MAX_PATH)==_MAX_PATH)  //~v6H9R~
//#define IS_WIN_LONGPATHW(pw)  (strnctrW(pw,MAX_PATH_WC)==_MAX_PATHWC)//~v6H9I~//~v6HnR~
//************************************************************     //~v6uaI~
//#define ROOTDIR_LOCALW(fname) (strctrW(fname)==3 && *((PWCH)fname+1)==L':' && *((PWCH)fname+2)==L'\\') //root id//~v6uaI~
//#define ROOTDIRW(fname) ROOTDIR_LOCALW(fname)   //ftp has no path//~v6uaI~
#define LFNM_STRCMPW(f1,f2)     stricmpW(f1,f2)                    //~v6uaI~
#define PATHCTRW(pucs) upathlenWW(UPLWO_CTR,pucs)                  //~v6uaI~
#define WILDCARDW(fname) strpbrkW(fname,L"*?")   //wild card       //~v6uaI~
//#define DIR_WINREMOTEW    L"\\\\"                                //~v6uaI~
//#define WIN_ISREMOTEPATHW(fname) (*(fname)==L'\\' && *(fname+1)==L'\\') //remote dir//~v6uaI~
//#define WIN_ISREMOTEDRIVEW(fname) (*(fname)==L'\\' && *(fname+1)==L':') //remote drive//~v6uaI~
#define IS_MEM_UDSTR(fname,len) (memchr(fname,UD_NOTLC,len))       //~v6unI~
#define IS_STR_UDSTR(fname) (strchr(fname,UD_NOTLC))               //~v6unI~
#define STRIP_UDSTR(in,len,out,poutlen) \
		ufilecvstripUD(UFCVO_STRZ,in,len,out,len/*outbuffsz*/,poutlen,NULL/*Pct*/,NULL/*Poutct*/);//~v6unI~
//************************************************************
int upathlenWW(int Popt,UWCH *Pfilename);                          //~v6uaI~
#define UPLWO_CTR                0x01    //output UWCH ctr         //~v6uaI~
//************************************************************     //~v6uaI~
#define UFCVO_STRZ         0x01     //set last NULL
#define UFCVO_SETSUBCHRC   0x02
#define UFCVO_BESTFIT      0x04         //set best fit char for WideToMulti
#define UFCVO_RETALLASCII  0x08
#define UFCVO_2UD          0x10         //locale name by UD fmt    //~v6uaI~
#define UFCVO_NOSUBCHRC    0x20         //not set even when subchar was set//~v6uaI~
#define UFCVO_FNU8         0x40         //linux utf8 encoded filename//~v6uaR~
#define UFCVO_FNLC         0x80         //linux utf8 encoded filename//~v6uaI~
#define UFCVO_KEEPUD       0x0100                                  //~v6uaR~
#define UFCVO_KEPTUD       0x0200                                  //~v6uaR~
#define UFCVO_NEW          0x0400       //chk subchar by wc2cp     //~v6uaR~
#define UFCVO_UTF8PRIMARY  0x0800       //select utf8 if l2u,f2u both ok//~v6uaI~
#define UFCVO_RETALLASCIIP 0x1000       //set rc if all ascii      //~v6uaR~
#define UFCVO_ENCAPATH     0x2000       //chk a path is fully enclosed by UD//~v6ujI~
#define UFCVO_ALLOWCP2UERR 0x4000       //ignore MultibyteToWideChar err//~v6unI~
#define UFCVO_ENCUTF8WC    0x8000       //enclose all utf8(not f2l err only)//~v6unI~
#define UFCVO_DIRPATH    0x010000       //path is dir path(max:248)//~v6HgI~
#define UFCVO_RSVNAME    0x020000       //set longname prefix for rsvname//~v6HnI~//+v6T4R~
#define UFCVO_NOMSG      0x040000       //No fmterr msg            //~v6J1I~
#define UFCVO_ERRREPDBCS 0x080000       //set dbcs "?" for f2l err //+v6T4I~
//************************************************************     //~v6uaI~
int ufilecvcp2ucsW(int Popt,char *Plc,int Plclen,UWCH *Puwch,int Pbuffsz,int *Ppucsctr);
//******************************************************
int ufilecvucs2utfW(int Popt,UWCH *Ppucs,int Pucsctr,char *Ppu8,int Pbuffsz,int *Pplenu8);//~v6uaR~
//******************************************************
int ufilecvucs2cpW(int Popt,UWCH *Puwch,int Pucsctr,char *Plc,int Pbuffsz,int *Pplclen);
//******************************************************
int ufilecvutf2ucsW(int Popt,UCHAR *Ppmbs,int Pinplen,UWCH *Ppucs,int Poutbuffsz,int *Ppoutctr);
//********************************************************************************
//* UD string pattern:[\]0x01,0x02 .... 0x01[\]
#define UD_NOTLC        0x01//=XEERRMCT_NOTLC  //start/end of not locale code path
//#define UD_UTF8FN       0x02//utf8 filename                        //~v6uaR~//~v6ucR~
//#define UD_UTF8CODE     0x02//utf8 filename for Linux(FTP)         //~v6ucI~//~v6unR~
#define UD_UTF8X        0x03//hex notation for cmdparm             //~v6unI~
#define UD_UTF8WC       0x04//utf8 for ucs2                        //~v6uaR~
#define UD_UTF8WCSUBC   0x05//ucs2 could not translate to locale code//~v6uaR~

#define UDRC_UTF8MASK     0x0f                //start of utf8 for utf16 contains locale conversion err//~v6uaR~
#define UDRC_ERR          0x10                  //start of utf8 for utf16 contains locale conversion err//~v6uaR~
#define UDRC_BUFFSHORTAGE 0x14                   //start of utf8 for utf16 contains locale conversion err//~v6uaI~
#define UDRC_FMTERR     4100                                       //~v6uaR~
//****************
int ufilecvUD2WC(int Popt,char *Pfnm,UWCH *PfnmW,int Pbuffsz,int *Ppucsctr,char *Ppathtbl,int Ppathtblsz,int *Pppathctr);//~v6uaI~
int ufilecvWC2UD(int Popt,UWCH *PfnmW,char *Pfnm,int Pbuffsz,int *Ppcharctr,char *Ppathtbl,int Ppathctr);//~v6uaI~
//********************************************************************************
//********************************************************************************
//********************************************************************************//~v6uaI~
//#ifdef AAA                                                         //~v6uaI~//~v6ucR~
//int ufilecvlf2UD(int Popt,char *Pfnm,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~v6ucR~
//#define UFNMCVO_UTF8             0x01                            //~v6ucR~
//#define UFNMCVO_LC               0x02                            //~v6ucR~
//#define UFNMCVO_UTF8MEMB         0x04                            //~v6ucR~
//#define UFNMCVO_LCMEMB           0x08                            //~v6ucR~
//#define UFNMCVO_UTF8FN           0x10                              //~v6uaR~//~v6ucR~
//#define UFNMCVO_SETUTF8OK        0x20                              //~v6uaI~//~v6ucR~
//#endif                                                             //~v6uaI~//~v6ucR~
//********************************************************************************//~v6uaI~
int ufilecvUDD2DD(int Popt,char *Puddata,char *Puddbcs,char *Pudct,int Pudlen,char *Pdddata,char *Pdddbcs,char *Pddct,int Pbuffsz,int *Ppddlen);//~v6uaR~
//********************************************************************************//~v6uaI~
#ifdef _WINBASE_    //windows.h included                           //~v6uaI~//~v6ucR~
void ufilew_copyfstat_name(int Popt,LPWIN32_FIND_DATAW Pw32fd,FILEFINDBUF3 *Ppffb3);//~v6uaR~
#endif              //windows.h included                           //~v6uaI~
//********************************************************************************//~v6uaI~
int ufilew_dircompW(int Ptype,PUDIRLIST Ppudl1,PUDIRLIST Ppudl2);  //~v6uaR~
//********************************************************************************//~v6uaI~
//int ufilecvencloseu8(int Popt,char *Ppu8,int Pu8len,char **Pppud,int Ppudsz,int *Ppudlen);//~v6uaI~//~v6ucR~
int ufilecvencloseu8(int Popt,int Pudtype,char *Ppu8,int Pu8len,char **Pppud,int Ppudsz,int *Ppudlen);//~v6ucI~
#define UFCEUO_PTR   0x01 //free and update ptr                    //~v6uaI~
//********************************************************************************//~v6uaI~
//int ufilecvstripUD(int Popt,char *Ppud,int Pudlen,char *Ppu8,int Pbuffsz,int *Ppu8len);//~v6ucR~
int ufilecvstripUD(int Popt,char *Ppud,int Pudlen,char *Ppu8,int Pbuffsz,int *Ppu8len,char *Pct,char *Poutct);//~v6ucR~
//********************************************************************************//~v6uaI~
int ufilecvU82UD(int Popt,char *Pfnm,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~v6uaI~
//********************************************************************************//~v6ucI~
int ufilecvDD2U8(int Popt,char *Pdddata,char *Pdddbcs,int Pddlen,char *Poutu8,int Pu8buffsz,char *Poutlc,int lcbuffsz,int *Ppoutu8len,int *Ppoutlclen);//~v6ucI~
//********************************************************************************//~v6ucI~
int ufilecvUD2LC(int Popt,char *Pfnm,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~v6ucI~
#define UFCUD2LCO_NOMSG  0x01                                      //~v6EbI~
//********************************************************************************//~v6unM~
int ufilecvUD2LC_bestfit(int Popt,char *Pfnm,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~v6unI~
//********************************************************************************//~v6ucI~
int ufilew_setctDD(int Popt,int Pcodetype,char *Pdddata,char *Pdddbcs,int Plen,char *Poutbuff,int Pbuffsz);//~v6ucR~
//********************************************************************************//~v6ujI~
int ufilecvUD2WCnopath(int Popt,char *Pfnm,UWCH *PfnmW,int Pbuffsz,int *Ppucsctr);//~v6ujI~
//********************************************************************************//~v6unI~
int ufilecvUD2UDX(int Popt,char *Ppud,int Pudlen,char *Ppu8,int Pbuffsz,int *Ppu8len);//~v6unI~
//********************************************************************************//~v6unI~
int ufilecvUDX2UD(int Popt,char *Ppud,int Pudlen,char *Ppu8,int Pbuffsz,int *Ppu8len);//~v6unI~
//********************************************************************************//~v6unI~
int ufilecvU8CT2UD(int Popt,char *Pfnm,char *Pct,int Pctlen,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~v6unI~
//********************************************************************************//~v6unI~
int usystemW(int Popt,char *Pcmd);                                 //~v6unI~
//********************************************************************************//~v6unI~
int ufilecvU82UDnopath(int Popt,char *Pfnm,int Plen,char *Poutbuff,int Pbuffsz,int *Ppoutlen);//~v6unI~
//================================================================ //~v6u9I~
HANDLE uCreateFileNative(const char *Pfnm,DWORD Pacc,DWORD Pshare,void *Psecattr,DWORD Pdisp,DWORD Pattr,HANDLE Phtemp);//~v6B1R~
//================================================================ //~v6B1I~
FILE *ufopenNative(const char * Pfnm,const char * Popenopt);       //~v6B1I~
//================================================================ //~v6E3I~
int ufilestrlenUDstrip(int Popt,char *Ppud,int Pudlen);            //~v6E3I~
//================================================================ //~v6EbI~
int ufilesplitUDbyLastExtention(int Popt,char *Ppud,int Pudlen,char *Pout,int Pbuffsz,int *Ppoutlen,char **Ppextention);//~v6EbI~
//================================================================ //~v6EbI~
char *u_fullpathWLong(int Popt,char * Pfpath,UWCH *Pfpathw,const char * Prpath,size_t Pbuffsz,int *Ppucsctr);//~v6H9I~
//================================================================ //~v6EbI~
int udirlistWLong(int Popt,char * Pfnm,char *Pfpath, size_t Pbuffsz,UINT Pattrmask,PUDIRLIST *Pppudl,int Psortopt);//~v6H9R~
//================================================================ //~v6H9I~
#ifdef AAA                                                         //~v6HnI~
HDIR uFindFirstFileWLong(int Popt,char * Pfnm,UWCH *PfnmW,void /*WIN32_FIND_DATA*/ *Pw32fd);//~v6H9R~
#endif                                                             //~v6HnI~
#endif //W32                                                       //~v6u9I~
