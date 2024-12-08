//*CID://+vat5R~:                             update#=  378;       //~vat5R~
//******************************************************
//*ufile.h                                                         //~v5d1R~
//******************************************************        //~5708I~
//vat5:241023 xdig:add option to apply dirmask once and all        //~vat5I~
//v794:230818 ARM:confirm IS_DOCPATH excepting "///"               //~v794I~
//v784:230721 ARM:xdelete; no entry msg and successefull when 0 member//~v784I~
//v781:230720 (Bug)del dir fail by errmsg of "no entry but other attr exist" when dir contains only one dir//~v781I~
//v77p:230502 ARM:request "//" option to delete shortpath root(//Axe etc)//~v77pI~
//v77j:230428 ARM;udirlist by opendir optionally                   //~v77jI~
//v777:230403 ARM;udirlistFD                                       //~v777I~
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0R~
//v6Hu:170126 expand max allocsz for udirlist 16M-->32M            //~v6HuI~
//v6Hj:170119 bypass toolong errmsg at xe term                     //~v6HjI~
//v6Hc:170114 (Win)_MAX_PATH is wchar ctr,for dbcs size is doubled.(dir=240,file=255)//~v6HcI~
//v6H9:170109 (Win)del longname using \\?\ prefix(path max is 32767) and Unicode API because move to shortpath dir could not delete dir/file name longer >=260.//~v6H9I~
//v6H1:161231 filename >_MAX_PATH occurse when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v6H1I~
//            and it cause fpath area overflow then 0c4            //~v6H1I~
//v6D2:160423 LNX compiler warning for bitmask assignment(FDATE,FTIE)//~v6D2I~
//v6B9:160121 (LNX)new ufullpathCP function to chk optionally filesystem iocharset  convert to utf8 from locale code//~v6B9I~
//v6yg:150314 avoid \\.\ is displayed on errmsg                    //~v6ygI~
//v6yb:150313 new func "ugetcwdW" to retun dropped \\.\ prefix     //~v6ybI~
//v6w0:141108 (Win:BUG)windows BUG:_fullpath/_wfullpath returns \\.\prn for g:\src\xe\prn//~v6w0I~
//            and returns invalid name(\\.\g:\src\xe\prn is effective)//~v6w0I~
//v6uC:140524 (BUG of v6u0)duplicate ufree pslinkW(dirwalk free member,then walk into subdir,the free it)//~v6uCI~
//v6ua:140410 (Win)use UNICODE Api;apply WIN32_FIND_DATAW by "#ifdef W32UNICODE"//~v6uaI~
//v6u9:140408 (Win)use UNICODE Api using special filename fmt.     //~v6u9I~
//v6qd:131206 (BUG)slink target not found err(uftpgetdl1 set x00 to stdout)//~v6qdI~
//v6qb:131205 chk max filectr to avoid malloc size over uerrexit when 32bit mode(see v6q9)//~v6qbI~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6q3:131129 (LNX)compiler warning;dereferencing type-punned pointer//~v6q3I~
//v6q0:131126 (WIN)fails to delete wildcard entry;use shortname    //~v6q0I~
//v6p3:131026 for compiler warining type-punned pointer(it may cause bug when opt=2)//~v6p3I~
//v6ke:130626 add work area to udirlist not to use attr field      //~v6keI~
//v6kd:130625 copy/move warning not by rc but flag to keep rc= for successfull operation//~v6kdI~
//v6kc:130625 slink err flag by ufstat                             //~v6kcI~
//v6k8:130623 junction is link to dir,so issue errmsg for junction to file//~v6k8I~
//            Doc:mklink /J creates directory junction             //~v6k8I~
//v6k4:130525 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//            reparse point is by FILE_SLINK and mode IFMT(f0000)!=SLINK(a000)//~v6k4I~
//            mode is 8000 for SLINK,2000 for junction             //~v6k4I~
//v6hu:120807 (WIN)display odd number file time stamp for xdc/xts for also Win//~v6huI~
//v6ht:120729 (LNX)display odd number file time stamp              //~v6htI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6d8:120211 "invalid name" err msg when UNC path is share root such as \\192.168.8.44\p//~v6d8I~
//v6b1:110705 try list wildcard membername                         //~v6b1I~
//v63b:091119 (LNX:BUG) dirlist sort sequence err.                 //~v63bI~
//                      Because,file attr bit duplicated YSO and SLINK,re-assign TSO//~v63bI~
//v62a:090723 To delete target of symbolic linc is denagerous(Wine set slink to Winndows drive)//~v62aI~
//v5nD:090329*S390 support                                         //~v5nDI~
//v5nB:081208 avoid network search twice for invalid network path  //~v5nBI~
//v5nu:081107 (Win)\\x\y remote filename support                   //~v5nuI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v61p:080121 (FTP)psftp support                                   //~v61pI~
//v5kw:070820 support bkup before reopen at save                   //~v5kwI~
//v5kq:070630 remote file compare support                          //~v5kqI~
//v5kd:070518 (LNX:BUG)intermediate ../ is not resolved(linux understand but xe display ../ as it is)//~v5kdI~
//v5k0:061226 (LNX/WIN)largefile(>4GB) support                     //~v5k0I~
//v5jy:061123 3270:SPF information update                          //~v5jyI~
//v5ja:060921 (LNX)3270 support                                    //~v5jaI~
//v5e1:040920 support new xcopy option:copy override if updated    //~v5e1I~
//v5de:040609 (AIX:BUG)filetime set not done for download file     //~v5deI~
//v5d1:040526 new func to get parent pathname                      //~v5d1I~
//v5c7:040330 (UNX)always ignore slink err(put on udirlist)        //~v5c7I~
//v5c4:040330 (UNX:BUG)xdd fail if slink err(no entry on udirlist if slink err)//~v5c4I~
//v5ab:040104 integrate ROOTDIR2--->ROOTDIR3                       //~v5abI~
//v5a6:040104 (UNX,FTP)save slink uid,gid,uname,gname on dirlist for xe dirlist//~v5a6I~
//v59x:040101 (UNX,FTP)save slink timestamp and size for dirlist for xe//~v59xI~
//v59v:031223 (WIN)ROOTDIR support both ftp remote and local       //~v59vI~
//v59f:031103 fd root chk macro FDROOTDIR for dlcmd use            //~v59fI~
//v59e:031103 ftp support(4 byte udirlist attr for ! UNX)          //~v59eI~
//v59d:030816 ftp support                                          //~v59dI~
//v578:021207 udirlist performance tuning(stat call on the current dir)//~v578I~
//v573:021009 (UNX)slink err msg bypass option (u#37)              //~v573I~
//v56s:020712 (UNX)allow to udirlist select non-reguler file       //~v56sI~
//v56n:020711 (UNX:BUG) xff loop by FIFO file.it is slink,so not chked.//~v56nI~
//v55n:020503 (AIX)disket support                                  //~v55nI~
//v547:020330 (WIN/OS2)keep ctime(creatio time)/atime(last access time) for xff cmd//~v547R~
//v538:020322 (LNX)mdos disk support;mkdir rmdir;attrib            //~v538I~
//v50T:010920 (BUG:AIX) FTIME/FDATE for big endian                 //~v50TI~
//v50G:010618 LNX:disket support(using mtools)                     //~v50GI~
//v50F:010618 add function of fullpath expand wild card            //~v50FI~
//v50E:010616 return symbolic link attr/name for dir list          //~v50EI~
//v50d:010401 AIX:bit definition is only for int                   //~v50dI~
//v50c:010331 (BUG)ROOTDIR macro should chk ":"                    //~v50cI~
//v349:000926 LINUX support(ufstat now returns more info for copy info;fsid,timestamp etc)//~v349I~
//v327 000820:LINUX support                                        //~v327I~
//v324 000813:LINUX support(CRLF)                                  //~v324R~
//v195:980921 (BUG:WIN)FTIME/FDATE should be size of short(2 byte) //~v195I~
//            (inconpatible index file for win and os2/gcc/dos)    //~v195I~
//v179:980505 no msg (not found msg) vaersion of udosfindfirst/udirlist//~v179I~
//v115:971109 new dirlist sort option('L');simple longname compare(OS/2,W95,GCC)//~v115I~
//v113:971103 release dir filename compare func udircomp for dirlist sort/merge//~v113I~
//v105:971026 (GCC)lfn support                                     //~v101I~
//           -findfirst/findnext lfn support                       //~v101I~
//v101:971009 long filename                                        //~v101I~
//            ufile.h :max filename size 255 and 12(dos)           //~v101I~
//v068:970222:ufstat change ffbf3 to optional parm,use as file_exist func//~v068I~
//v067:970215:(BUG)dir sort compare('E' type sort)                 //~v067I~
//            add 'S' type                                         //~v067I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -different structure _dos_find_first,ftime,fdate     //~v053I~
//v034:961008:VC support(identify by (_MSC_VER>=800))              //~v034I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//v016:960211:(BUG)PATHLEN need chk dbcs 2nd byte '\',ex ‰\        //~v327R~
//*950826:no msg option by Gufile_nomsg(for remove,rename)         //~v016I~
//*950826:no msg option by Gufile_nomsg(for remove,rename)      //~5826R~
//*950708:ugetcwd,ugetdrive,usetdrive,usetdir                   //~5826I~
//******************************************************        //~5708I~
#ifdef AIX                                                         //~v5e1I~
    #define FDATETIME2ULONG(fdate,ftime) (\
                (ULONG)(                  \
		         ((*((ULONG*)((ULONG)(&(fdate)))))<<16)   \
		       | ((*((ULONG*)((ULONG)(&(ftime)))))&0xffff)   \
                       )                  \
                                         )                         //~v5e1I~
#else                                                              //~v5e1I~
/**                                                                //~v6hhI~
    #define FDATETIME2ULONG(fdate,ftime) (\
                (ULONG)(                  \
		         ((*((USHORT*)((ULONG)(&(fdate)))))<<16)   \
		       | ((*((USHORT*)((ULONG)(&(ftime))))))   \
                       )                  \
                                         )                         //~v5e1I~
**/                                                                //~v6hhI~
/**                                                                //~v6q3I~
    #define FDATETIME2ULONG(fdate,ftime) (\
                (UINT4)(                  \
		         ((*((USHORT*)((ULPTR)(&(fdate)))))<<16)   \
		       | ((*((USHORT*)((ULPTR)(&(ftime))))))   \
                       )                  \
                                         )                         //~v6hhI~
**/                                                                //~v6q3I~
    #define FDATETIME2ULONG(fdate,ftime) (\
                (UINT4)(                  \
		         (FDATE2USHORT(fdate)<<16)   \
		       | (FTIME2USHORT(ftime)    )   \
                       )                  \
                                         )                         //~v6q3I~
    #define PFDATETIME2ULONG(pfdate,pftime) (\
                (UINT4)(                  \
		         (PFDATE2USHORT(pfdate)<<16)   \
		       | (PFTIME2USHORT(pftime)    )   \
                       )                  \
                                         )                         //~v6q3I~
#endif                                                             //~v5e1I~
#define EADATAID   "EA DATA. SF"                                //~5916I~
#define WILDCARD(fname) (strpbrk(fname,"*?"))   //wild card     //~5909I~
                                                                   //~v349I~
#ifdef UNX                                                         //~v327I~
    #define LFNM_MEMCMP(f1,f2,len) memcmp(f1,f2,len)               //~v61pI~
    #define LFNM_STRCMP(f1,f2)     strcmp(f1,f2)                   //~v61pR~
    #define ROOT_UID 0                                             //~v5d1I~
    #define ROOT_GID 0                                             //~v5d1I~
    #define ROOT_MODE 0755  //root dir permission                  //~v5d1I~
	#define ROOTDIR(fname) (*fname==DIR_SEPC && *(fname+1)==0) //root id//~v50GR~
    #define ROOTDIRPOS      0    //dirname from byte 0             //~v349M~
#ifdef AIX                                                         //~v55nI~
    #define MDOSDISK(fnm) (*((fnm)+1)==':' && (*(fnm)=='a'||*(fnm)=='A'))//~v55nI~
#else                                                              //~v55nI~
    #define MDOSDISK(fnm) (*((fnm)+1)==':' && (*(fnm)=='a'||*(fnm)=='A'||*(fnm)=='b'||*(fnm)=='B'))//~v50GR~
#endif                                                             //~v55nI~
    #define MDOSDISKOK(fnm) ((Gufile_opt & GFILEOPT_LNXMTOOL) && MDOSDISK(fnm))//~v50GI~
    #define MDOSROOTDIR(fnm) (*((fnm)+2)=='/' && *((fnm)+3)==0 && MDOSDISKOK(fnm))//~v50GI~
    #define MDOSROOTDIRPOS      2    //dirname from byte 2 (a:)    //~v50GI~
	#define ROOTDIR2(fname) ((ROOTDIR(fname))||(MDOSROOTDIR(fname)))//~v50GR~
	#define ROOTDIR_LOCAL(fname) ROOTDIR(fname)                    //~v59vI~
	#define ROOTDIR3(fname) ((ROOTDIR2(fname))||uftpisrootdir(fname))//~v5abI~
#else                                                              //~v327I~
    #define LFNM_MEMCMP(f1,f2,len) memicmp(f1,f2,len)              //~v61pI~
    #define LFNM_STRCMP(f1,f2)     stricmp(f1,f2)                  //~v61pR~
//#define ROOTDIR(fname) (strlen(fname)==3 && *(fname+2)=='\\') //root id//~v50cR~
#ifdef W32                                                         //~v59vI~
    #define ROOT_UID 0                                             //~v5d1I~
    #define ROOT_GID 0                                             //~v5d1I~
    #define ROOT_MODE 0755  //root dir permission                  //~v5d1I~
	#define ROOTDIR(fname) (ufileisroot(fname))                    //~v59vI~
	#define ROOTDIR_LOCAL(fname) (strlen(fname)==3 && *(fname+1)==':' && *(fname+2)=='\\') //root id//~v59vI~
	#define IS_FULLPATH(pc) ((int)(*(pc))!=0 && (int)(*((pc)+1))==':' && (int)(*((pc)+2))=='\\') //fullpath or fullpathW//~v6H9I~
#else                                                              //~v59vI~
#define ROOTDIR(fname) (strlen(fname)==3 && *(fname+1)==':' && *(fname+2)=='\\') //root id//~v50cI~
	#define ROOTDIR_LOCAL(fname) ROOTDIR(fname)                    //~v59vI~
#endif                                                             //~v59vI~
    #define FDFILE(fnm) (*((fnm)+1)==':' && (*(fnm)=='a'||*(fnm)=='A'||*(fnm)=='b'||*(fnm)=='B'))//~v5kwR~
    #define FDROOTDIR(fnm) (ROOTDIR(fnm) &&  \
				(*fnm=='a'||*fnm=='A'||*fnm=='b'||*fnm=='B'))      //~v59fI~
	#define ROOTDIR2(fname) (ROOTDIR(fname))                       //~v50GI~
    #define ROOTDIRPOS      2    //dirname from byte 2 (a:)        //~v349M~
  	#ifdef W32                                                     //~v5abI~
		#define ROOTDIR3(fname) ((ROOTDIR(fname))||uftpisrootdir(fname))//~v5abI~
    #else                                                          //~v5abI~
		#define ROOTDIR3(fname) (ROOTDIR(fname))                   //~v5abI~
    #endif                                                         //~v5abI~
#endif                                                             //~v327I~
                                                                   //~v349I~
#define PATHLEN(fname) (upathlen(fname))                           //~v016R~
#define PATHLEN_DOC(fname) (upathlenDoc(0,fname,0/*PplenRoot*/,0/*PpswRoot*/,0/*PplenPrefix*/,0/*Ppalias*/))//~v777I~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nuI~
    #define DIR_WINREMOTE    "\\\\"                                //~v5nuM~
    #define WIN_UNCID '\\'                                         //~v5nuR~
//  #define WIN_ISREMOTEPATH(fname) (*(fname)=='\\' && *(fname+1)=='\\') //remote dir//~v6w0R~
    #define WIN_ISREMOTEPATH(fname) (*(fname)=='\\' && *(fname+1)=='\\' && *(fname+2)!='.' && *(fname+2)!='?') //remote dir//~v6w0I~
	#define WIN_ISREMOTEDRIVE(fname) (*(fname)=='\\' && *(fname+1)==':') //remote drive//~v5nuR~
                                                                   //~v6H9I~
#endif                                                             //~v5nuI~
#ifdef ARMXXE                                                      //~v777I~
    #define PREFIX_ARM_SHARE   "//"                                //~v777I~
    #define PREFIX_ARM_SHARE_LEN  2                                //~v777I~
    #define SEP_ARM_SHARE      ':'     //separator between alias and uri//~v777I~
    #define SEP_ARM_SHARE_PATH "%3A"   //separator between uri and root path//~v777R~
    #define SEP_ARM_SHARE_PATH_SUBDIR "%2A"   //separator "/"      //~v777I~
//  #define IS_DOCPATH(fname) (*(fname)=='/' && *(fname+1)=='/')   //~v777I~//~v794R~
    #define IS_DOCPATH(fname) (*(fname)=='/' && *(fname+1)=='/' && *(fname+2)!='/')//~v794I~
    #define IS_DOCROOT(fname) (IS_DOCPATH(fname) && !strchr(fname+PREFIX_ARM_SHARE_LEN,'/'))//~v77pI~
#endif                                                             //~v777I~
#ifdef W32                                                         //~v6ygI~
//*see ufilew.h                                                    //~v6ygI~
#else                                                              //~v6ygI~
#define STD_FNM(fpath) (fpath)                                     //~v6ygI~
#endif                                                             //~v6ygI~
//********                                                      //~5826I~
//**data**                                                      //~5826I~
//********                                                      //~5826I~
#ifdef UFILE_SELF                                               //~5826I~
int Gufile_nomsg;                                               //~5826I~
int Gufile_opt;                                                    //~v50GI~
#else                                                           //~5826I~
extern int Gufile_nomsg;                                        //~5826I~
extern int Gufile_opt;                                             //~v50GI~
#endif                                                          //~5826I~
//#ifdef LNX                                                       //~v50GR~
	#define GFILEOPT_LNXMTOOL      0x01 //support mtool            //~v50GI~
	#define GFILEOPT_NOSLINKERRMSG 0x02 //bypass slink err msg issue//~v573I~
//#endif                                                           //~v50GR~
#ifdef UNX                                                         //~v578R~
	#define GFILEOPT_STATCD        0x04 //stat by only filename(cd is set this dir)//~v578M~
#endif                                                             //~v578I~
//	#define GFILEOPT_IGNORESLINKERR 0x08 //udirlist returns also slinkerr entry//~v5c7R~
	#define GFILEOPT_IGN_UNCPATHERR 0x08 //ignore UNC fmt path err msg//~v5nBI~
//#ifdef UNX                                                         //~v6b1I~//~v6q0R~
	#define GFILEOPT_WILDCARDNAMEOK 0x10 //udirlist accept wildcard member name//~v6b1I~
#ifdef UNX                                                         //~v6q0I~
	#define GFILEOPT_XDDUTIL        0x20 //xdd utility             //~v6b1I~
#endif                                                             //~v6b1I~
#ifdef W32                                                         //~v6k8I~
	#define GFILEOPT_J2FBYTARGETFNM 0x40 //access by target filename to junction to file//~v6k8R~
#endif                                                             //~v6k8I~
	#define GFILEOPT_RC_WARNING     0x80 //bypass successfull copy/move because slink err msg issued//~v6kdI~
//#ifdef UNX                                                       //~v6q0R~
	#define GFILEOPT_NOWILDERRMSG   0x0100 //skip filename invalid warning//~v6q0I~
//#endif                                                           //~v6q0R~
#ifdef W32                                                         //~v6u9I~
	#define GFILEOPT_UDMODE           0x0200 //wide cahr api mode  //~v6u9I~
//  #define  IS_UDMODE()  (Gufile_opt & GFILEOPT_UDMODE)           //~v6u9I~//~v6J0R~
    #define  IS_UDMODE()  (1)                                      //~v6J0I~
	#define  SET_UDMODE()  (Gufile_opt |= GFILEOPT_UDMODE)         //~v6u9I~
#endif                                                             //~v6u9I~
	#define GFILEOPT_XETERMINATING   0x0400 //xe ytermination avoid toolongname errmsg at dlterm//~v6HjI~
#ifdef ARMXXE                                                      //~v77jI~
	#define GFILEOPT_NOOPENDIRUDL    0x0800    //udirlist not by opendir//~v77jR~
	#define IS_NOOPENDIRDL()  (Gufile_opt &  GFILEOPT_NOOPENDIRUDL)//~v77jR~
#endif                                                             //~v77jI~
//******************************************************        //~5826I~
#define MAXFILENAMEZ_FAT  13     //8.3 with term null              //~v101R~
#define SHORTNAME_FLDSZ    MAXFILENAMEZ_FAT  //13     //8.3 with term null//~v6J0I~
#ifdef UNX                                                         //~v327I~
//  #define MAXFILENAMEZ   _MAX_PATH                               //~v6d8I~
  #ifdef LNX                                                       //~v6d8I~
//*255 OK,256 fail for filename(not PATH)                          //~v6qaI~
    #define MAXFILENAMEZ   256                                     //~v6d8I~
  #else                                                            //~v6d8I~
    #define MAXFILENAMEZ   MAXNAMELEN                              //~v327I~//~v6d8R~
  #endif                                                           //~v6d8I~
    #define MAXSLINKNMSZ   _MAX_PATH                               //~v59fI~
#else //!UNX                                                       //~v327I~
#ifdef DOS                                                         //~v101I~
    #ifdef DPMI                 //DPMI version                     //~v101I~
        #define MAXFILENAMEZ      256    //with term null          //~v101R~
    #else                                                          //~v101I~
        #define MAXFILENAMEZ      13     //8.3 with term null      //~v101R~
    #endif                                                         //~v101I~
#else                                                              //~v101I~
  #ifdef W32UNICODE                                                //~v6uaI~
    #define MAXFILENAMEZWC    _MAX_FNAME // 256        //with term null//~v6uaI~
//  #define MAXFILENAMEZ      (MAXFILENAMEZWC+3)       //UD fmt max//~v6uaR~//~v6HcR~
//  #define MAXFILENAMEZ      (MAXFILENAMEZWC*2+3)       //UD fmt max//~v6HcR~
    #define MAXFILENAMEZ      (MAXFILENAMEZWC*MAX_UCS2UTF8+3)       //UD fmt max//~v6HcI~
  #else                                                            //~v6uaI~
    #define MAXFILENAMEZ      256        //with term null          //~v101R~
  #endif                                                           //~v6uaI~
//  #define MAXSLINKNMSZ      256                                  //~v59fI~//~v6qaR~
//  #define MAXSLINKNMSZ      4096      //value of linux           //~v6qaI~//~v6HcR~
    #define MAXSLINKNMSZWC    4096      //value of linux           //~v6HcM~
    #define MAXSLINKNMSZ      (MAXSLINKNMSZWC*MAX_UCS2UTF8+3)     //value of linux//~v6HcR~
#endif                                                             //~v101I~
#endif//!UNX                                                       //~v327I~
                                                                   //~v59fI~
#define MAXUNAMESZ   8   //for ftp:user name                       //~v59fI~
#define MAXGNAMESZ   8   //for ftp:user name                       //~v59fI~
//******************************************************        //~5826I~
#ifdef FTPSUPP                                                     //~v5jyI~
    #define TSO_GETINITLINE(pffb3)       TSOGN_GETINITLINE(pffb3->gname)//~v5jyR~
    #define TSO_SETINITLINE(pffb3,value) TSOGN_SETINITLINE(pffb3->gname,value)//~v5jyR~
    #define TSO_GETVV(pffb3)             TSOGN_GETVV(pffb3->gname) //~v5jyR~
    #define TSO_SETVV(pffb3,value)       TSOGN_SETVV(pffb3->gname,value)//~v5jyR~
    #define TSO_GETMM(pffb3)             TSOGN_GETMM(pffb3->gname) //~v5jyR~
    #define TSO_SETMM(pffb3,value)       TSOGN_SETMM(pffb3->gname,value)//~v5jyR~
    #define TSO_GETCDATE(pffb3)          TSOGN_GETCDATE(pffb3->gname)//~v5jyR~
    #define TSO_SETCDATE(pffb3,value)    TSOGN_SETCDATE(pffb3->gname,value)//~v5jyR~
                                                                   //~v5jyI~
//  #define TSOGN_GETINITLINE(gname) (*(USHORT*)(ULONG)((gname)+1))//~v5jyI~//~v6hhR~
    #define TSOGN_GETINITLINE(gname) (*(USHORT*)(ULPTR)((gname)+1))//~v6hhI~
//  #define TSOGN_SETINITLINE(gname,value) *(USHORT*)(ULONG)((gname)+1)=(USHORT)(value)//~v5jyI~//~v6hhR~
    #define TSOGN_SETINITLINE(gname,value) *(USHORT*)(ULPTR)((gname)+1)=(USHORT)(value)//~v6hhI~
    #define TSOGN_GETVV(gname) (*((gname)+1+sizeof(USHORT)))       //~v5jyI~
    #define TSOGN_SETVV(gname,value) *((gname)+1+sizeof(USHORT))=(char)(value)//~v5jyI~
    #define TSOGN_GETMM(gname) (*((gname)+1+sizeof(USHORT)+1))     //~v5jyI~
    #define TSOGN_SETMM(gname,value) *((gname)+1+sizeof(USHORT)+1)=(char)(value)//~v5jyI~
//  #define TSOGN_GETCDATE(gname) (*((FDATE*)(ULONG)((gname)+1+sizeof(USHORT)+2)))//~v5jyR~//~v6hhR~
    #define TSOGN_GETCDATE(gname) (*((FDATE*)(ULPTR)((gname)+1+sizeof(USHORT)+2)))//~v6hhI~
//  #define TSOGN_SETCDATE(gname,value) *(FDATE*)(ULONG)((gname)+1+sizeof(USHORT)+2)=(value)//~v5jyI~//~v6hhR~
    #define TSOGN_SETCDATE(gname,value) *(FDATE*)(ULPTR)((gname)+1+sizeof(USHORT)+2)=(value)//~v6hhI~
#endif                                                             //~v5jyI~
#ifdef FTPSUPP                                                     //~v5jaI~
    #define FILE_RECFMB     0x0001  //RECFM=B :READONLY            //~v5jaI~
    #define FILE_RECFMF     0x0002  //RECFM=F :HIDDEN              //~v5jaI~
    #define FILE_RECFMV     0x0004  //RECFM=V :SYSTEM              //~v5jaI~
    #define FILE_PS         0x0020  //DSORG=PS:ARCHIVED            //~v5jaI~
    #define FILE_PO         0x0100  //DSORG=PO:FTPWKSL             //~v5jaR~
    #define FILE_PDSMEMB    0x0200  //member of PDS:FTPJST(FILE_PO is also ON)//~v5jaR~
    #define FILE_DSNPATH    0x0400  //DSN path name:FTPWKSL2       //~v5jaI~
//  #define FILE_TSO        0x0800  //tso file                     //~v5jaI~//~v63bR~
    #define FILE_SPF        0x1000  //spf info gotten              //~v5jaI~
    #define FILE_ALIAS      0x2000  //alias member(also FILE_SPECIAL on)//~v5jaI~
    #define FILE_SPFDS      0x4000  //PDS with RECFM=Fx,LRECL=80   //~v5jyI~
    #define FILE_TSO        0x8000  //tso file                     //~v63bI~
#endif                                                             //~v5jaI~
#ifdef UNX                                                         //~v327I~
    #include <errno.h>                                                                   //~v327I~
    typedef      ULONG      HDIR; //DIR *(dirent.h)                //~v327R~
                                                                   //~v327I~
    #define FILE_NORMAL     0x0000                                 //~v56sR~
    #define FILE_READONLY   0x0001                                 //~v327R~
    #define FILE_HIDDEN     0x0002                                 //~v327R~
    #define FILE_SYSTEM     0x0004                                 //~v327R~
    #define FILE_VOLID      0x0008  //dos only                     //~v327R~
    #define FILE_MDOSDISK   0x0008  //files on disket              //~v50GI~
    #define FILE_DIRECTORY  0x0010                                 //~v327R~
    #define FILE_ARCHIVED   0x0020                                 //~v327R~
#ifdef ARMXXE                                                      //~v777M~
    #define FILE_DOCUMENT   0x0020  //ARM document file, included inFILE_ALL//~v777I~
#endif                                                             //~v777M~
    #define FILE_REMOTE     0x0040  //ftp file                     //~v59dI~
    #define FILE_SPECIAL    0x0080  //special file select request  //~v56sI~
                                                                   //~v59fI~
    #define FILE_FTPWKSL    0x0100  //work flag for ftp slink process//~v59fI~
//  #define FILE_FTPJST     0x0200  //ftime is ajusted by tz       //~v5deR~
    #define FILE_SLINKERR   0x0200  //loop/duplicated slink entry  //~v6kcR~
    #define FILE_FTPWKSL2   0x0400  //work flag for slink dup chk  //~v59dI~
//#ifdef LNX                                                       //~v6H1R~
//    #define FILE_TOOLONGNM  0x0400  //temporary flag of TooLongFileName(not FTP)//~v6H1R~
//#endif                                                           //~v6H1R~
    #define FILE_SLINK      0x0800  //slink entry                  //~v62aR~
    #define FILE_WILDNAME   0x2000  //=FILE_ALIAS of TSO file;membername contains wildchar(*?)//~v6b1I~
    #define FILE_WILDNAME_MULTIPLE 0x4000 //=FILE_SPFDS of TSO;same wildname member exist//~v6b1I~
    #define FILE_IS_WILDNAME(attr) (attr & FILE_WILDNAME)          //~v6q0I~
                                                                   //~v62aI~
    #define FILE_ISNOSLINKDIR(attr) (((attr) & FILE_DIRECTORY) && ((attr) & FILE_SLINK)==0)//~v62aM~
    #define FILE_ISSLINKDIR(attr) (((attr) & FILE_DIRECTORY) && ((attr) & FILE_SLINK))//~v62aM~
    #define FILE_ISSLINK(attr) ((attr) & FILE_SLINK)               //~v62aM~
                                                                   //~v327I~
    #define FILE_MODEMASK   0xffff0000  //mode mask on attr+mode   //~v327R~
    #define FILE_CHMODMASK_UNIX  07777       //chmod availbit 0x0fff//~v538R~
    #define FILE_CHMODMASK_MODE 0x0fff0000   //chmod availbit on mode part//~v538R~
                                                                   //~v62aI~
#ifdef UTF8SUPPH                                                   //~v62aR~
//  #define FILE_ATTRMASK   (0x000000ff|FILE_SLINK)  //mode mask on attr+mode//~v62aI~//~v6qdR~
    #define FILE_ATTRMASK   (0x000000ff|FILE_SLINK|FILE_SLINKERR)  //mode mask on attr+mode//~v6qdI~
#else                                                              //~v62aI~
    #define FILE_ATTRMASK   0x000000ff  //mode mask on attr+mode   //~v5deR~
#endif                                                             //~v62aI~
                                                                   //~v62aI~
    #define FILE_ALL (FILE_NORMAL|FILE_READONLY|FILE_HIDDEN|FILE_SYSTEM \
                     |FILE_DIRECTORY|FILE_ARCHIVED)                //~v327I~
    #define FILE_ALLSP (FILE_ALL | FILE_SPECIAL)                   //~v56sR~
    #define FILE_CHMODMASK (FILE_READONLY|FILE_HIDDEN|FILE_SYSTEM|FILE_ARCHIVED)//~v327I~
                                                                   //~v327I~
    #define FILE_GETMODE(modeattr) (modeattr>>16)                  //~v327I~
    #define FILE_SETMODEATTR(mode,attr) ((mode<<16)|(attr & FILE_ATTRMASK))//~v327R~
    #define FILE_GETATTR(modeattr) (modeattr & FILE_ATTRMASK)      //~v327I~
//***                                                              //~v327I~
    #define ERROR_FILE_NOT_FOUND    ENOENT  /* MSG%FILE_NOT_FOUND *///~v327I~
    #define ERROR_PATH_NOT_FOUND    ENOTDIR /* MSG%PATH_NOT_FOUND *///~v327I~
    #define ERROR_NO_MORE_FILES     ECHILD //temp use /* MSG%NO_MORE_FILES *///~v327I~
                                                                   //~v327I~
    #define ERROR_INVALID_HANDLE      EBADF                        //~v327I~
    #define ERROR_TOO_MANY_OPEN_FILES EMFILE                       //~v327I~
                                                                   //~v327I~
//***                                                              //~v327I~
#ifdef AIX                                                         //~v50dI~
    typedef struct _FTIME           /* ftime */                    //~v50dI~
             {                                                     //~v50dI~
                unsigned int    dummy   :16;                       //~v50dI~
//              unsigned int    twosecs : 5;                       //~v50TR~
//              unsigned int    minutes : 6;                       //~v50TR~
//              unsigned int    hours   : 5;                       //~v50TR~
                unsigned int    hours   : 5;                       //~v50TI~
                unsigned int    minutes : 6;                       //~v50TI~
                unsigned int    twosecs : 5;                       //~v50TI~
             } FTIME;                                              //~v50dI~
    typedef FTIME *PFTIME;                                         //~v50dI~
                                                                   //~v50dI~
    typedef struct _FDATE           /* fdate */                    //~v50dI~
             {                                                     //~v50dI~
                unsigned int      dummy   :16;                     //~v50dI~
//              unsigned int      day     : 5;                     //~v50TR~
//              unsigned int      month   : 4;                     //~v50TR~
//              unsigned int      year    : 7;                     //~v50TR~
                unsigned int      year    : 7;                     //~v50TI~
                unsigned int      month   : 4;                     //~v50TI~
                unsigned int      day     : 5;                     //~v50TI~
             } FDATE;                                              //~v50dI~
    typedef FDATE   *PFDATE;                                       //~v50dI~
#else                                                              //~v50dI~
typedef struct _FTIME           /* ftime */                        //~v327I~
         {                                                         //~v327I~
    #ifdef BIGENDIAN                                               //~v5nDI~
            unsigned short  hours   : 5;                           //~v5nDI~
            unsigned short  minutes : 6;                           //~v5nDI~
            unsigned short  twosecs : 5;                           //~v5nDI~
    #else                                                          //~v5nDI~
            unsigned short  twosecs : 5;                           //~v327I~
            unsigned short  minutes : 6;                           //~v327I~
            unsigned short  hours   : 5;                           //~v327I~
    #endif                                                         //~v5nDI~
         } FTIME;                                                  //~v327I~
typedef FTIME *PFTIME;                                             //~v327I~
                                                                   //~v327I~
typedef struct _FDATE           /* fdate */                        //~v327I~
         {                                                         //~v327I~
    #ifdef BIGENDIAN                                               //~v5nDI~
            unsigned short    year    : 7;                         //~v5nDI~
            unsigned short    month   : 4;                         //~v5nDI~
            unsigned short    day     : 5;                         //~v5nDI~
    #else                                                          //~v5nDI~
            unsigned short    day     : 5;                         //~v327I~
            unsigned short    month   : 4;                         //~v327I~
            unsigned short    year    : 7;                         //~v327I~
    #endif                                                         //~v5nDI~
         } FDATE;                                                  //~v327I~
typedef FDATE   *PFDATE;                                           //~v327I~
                                                                   //~v6D2I~
                                                                   //~v6D2I~
#define FDATE2USHORT(fd) (USHORT)(((fd.year)<<9)|((fd.month)<<5)|((fd.day)))//~v6p3I~
//#define USHORT2FDATE(fd,us) ( fd.year=((us)&0xffff)>>9, fd.month=((us)&0x01ff)>>5, fd.day=(us)&0x1f )//~v6q3I~//~v6D2R~
#define USHORT2FDATE(fd,us) ( *(USHORT*)(ULPTR)(&(fd))=(us) )      //~v6D2I~
#define FTIME2USHORT(ft) (USHORT)(((ft.hours)<<11)|((ft.minutes)<<5)|((ft.twosecs)))//~v6p3R~
//#define USHORT2FTIME(ft,us) ( ft.hours=((us)&0xffff)>>11, ft.minutes=((us)&0x07ff)>>5, ft.twosecs=(us)&0x1f )//~v6q3R~//~v6D2R~
#define USHORT2FTIME(ft,us) ( *(USHORT*)(ULPTR)(&(ft))=(us) )      //~v6D2I~
#define PFDATE2USHORT(pfd) (USHORT)(((pfd->year)<<9)|((pfd->month)<<5)|((pfd->day)))//~v6p3I~
#define PFTIME2USHORT(pft) (USHORT)(((pft->hours)<<11)|((pft->minutes)<<5)|((pft->twosecs)))//~v6p3R~
#endif                                                             //~v50dI~
//*UNX **if change check Sffb3root of uftp.c                       //~v6b1R~
typedef struct _FILEFINDBUF3 {                                     //~v327I~
                  ULONG     attrFile; //mode(2)+rsv(1)+attr(1)     //~v327R~
                  ULONG     srcattr; //slink source attr;mode(2)+rsv(1)+attr(1)//~v56nI~
//*                                 lrecl+blksize for TSO file     //~v5jyI~
                  uid_t     uid;                                   //~v349R~
                  gid_t     gid;                                   //~v349R~
                  dev_t     fsid;//filesystem                      //~v349I~
//                USHORT    rsv;                                   //~v6b1R~
                  ino_t     inode;      //inodeNo                  //~v6b1I~
                  time_t    atime;     //accessed                  //~v349I~
                  time_t    mtime;     //modified                  //~v349I~
                  time_t    ctime;     //corrected                 //~v349I~
                  FTIME     ftimeLastWrite;                        //~v327I~
                  FDATE     fdateLastWrite;                        //~v327I~
//                ULONG     cbFile   ;                             //~v5k0R~
                  FILESZT   cbFile   ;                             //~v5k0I~
                  time_t    slinkmtime;     //modified             //~v59xI~
                  FTIME     slinkftime;                            //~v59xI~
//*                                 SPF  update time for TSO SPF   //~v5jaI~
                  FDATE     slinkfdate;                            //~v59xI~
//*                                 SPF  update date for TSO SPF   //~v5jaI~
//                ULONG     slinksize;                             //~v5k0R~
                  FILESZT   slinksize;                             //~v5k0R~
//*                                        line count for TSO SPF  //~v5jaI~
                  uid_t     slinkuid;                              //~v5a6I~
                  gid_t     slinkgid;                              //~v5a6I~
                  char      achName[MAXFILENAMEZ];                 //~v327R~
//                char      slink[MAXFILENAMEZ];                   //~v59fR~
                  char      slink[MAXSLINKNMSZ];                   //~v59fI~
                  char      uname[MAXUNAMESZ+1];   //for ftp:user name//~v59fI~
                  char      gname[MAXGNAMESZ+1];   //for ftp:group name//~v59fI~
//*                         initline/vv/mm/creation date by FDATE fmt for TSO SPF//~v5jyM~
                  char      slinkuname[MAXUNAMESZ+1];   //for ftp:user name//~v5a6I~
                  char      slinkgname[MAXGNAMESZ+1];   //for ftp:group name//~v5a6I~
#ifdef ARMXXE                                                      //~v777I~
				  int docFlags;                                    //~v777I~
				  int otherflag;       //UDLOF_ARMDOC              //~v777I~
#endif                                                             //~v777I~
                } FILEFINDBUF3;                                    //~v327I~
//*UNX                                                             //~v6b1R~
typedef struct _UDIRLIST{   //same fmt as findbuf3                 //~v327I~
                      ULONG         attr;   //attr+mode            //~v327R~
                      ULONG     srcattr; //slink source attr;mode(2)+rsv(1)+attr(1)//~v56nI~
                      ULONG     workflag;                          //~v6keI~
//*                                      lrecl+blksize for TSO file//~v5jyR~
                      uid_t         uid;                           //~v349R~
                      gid_t         gid;                           //~v349R~
                  	  dev_t     fsid;//filesystem                  //~v349I~
//                    USHORT    rsv;                               //~v6b1R~
                      ino_t     inode;      //inodeNo              //~v6b1I~
                      time_t    atime;     //accessed              //~v349I~
                      time_t    mtime;     //modified              //~v349I~
                      time_t    ctime;     //corrected             //~v349I~
                      FTIME         time;                          //~v327I~
                      FDATE         date;                          //~v327I~
//                    ULONG         size;                          //~v5k0R~
                      FILESZT       size;                          //~v5k0I~
	                  time_t    slinkmtime;     //modified         //~v59xI~
    	              FTIME     slinkftime;                        //~v59xI~
//*                                 SPF  update time for TSO SPF   //~v5jaI~
        	          FDATE     slinkfdate;                        //~v59xI~
//*                                 SPF  update date for TSO SPF   //~v5jaI~
//          	      ULONG     slinksize;                         //~v5k0R~
            	      FILESZT   slinksize;                         //~v5k0I~
//*                                        line count for TSO SPF  //~v5jaI~
                      uid_t     slinkuid;                          //~v5a6I~
                      gid_t     slinkgid;                          //~v5a6I~
//                    char          name[MAXFILENAMEZ];            //~v327I~//~v6J0R~
                      int       namesz;                            //~v6J0I~
                      char     *name;                              //~v6J0I~
                      char      nameShortbuff[SHORTNAME_FLDSZ];    //~v6J0I~
#define UDIRLISTNAMESZ  MAXFILENAMEZ                               //~v6J0I~
//                    char      slink[MAXFILENAMEZ];               //~v59fR~
//                    char      slink[MAXSLINKNMSZ];               //~v59fI~//~v6qaR~
                      char     *pslink;                            //~v6qaR~
                      int       otherflag;                         //~v6qaI~
#define UDLOF_SLINK_ALLOC        0x0001     //pslink points malloced area//~v6qaR~
#define UDLOF_WKENTRY            0x0002     //udirlist is work variable//~v6qaI~
#define UDLOF_ALLOC1             0x0004     //name may be null but slink allocated//~v6qdI~
#define UDLOF_SLINKNAME_NA       0x0008     //psftp dose not show slink target//~v6qbI~
#define UDLOF_ALLOCNAME          0x0010     //*name point malloc   //~v6J0I~
#ifdef ARM                                                         //~v777I~
#define PUDIRLIST_ISARMDOC(pudl) ((pudl->otherflag & UDLOF_ARMDOC)!=0)//~v777I~
#define UDIRLIST_ISARMDOC(udl) ((udl.otherflag & UDLOF_ARMDOC)!=0) //~v777I~
#define UDLOF_ARMDOC             0x0020     //*share document file //~v777I~
#endif                                                             //~v777I~
#define UDLOF_ALLOC_FLAGS (\
        UDLOF_SLINK_ALLOC  \
       |UDLOF_WKENTRY      \
       |UDLOF_ALLOC1       \
/*      UDLOF_SLINKNAME_NA*/ \
       |UDLOF_ALLOCNAME      \
       )                                                           //~v6J0I~
#ifdef ARM                                                         //~v777I~
				      int       docFlags;		                   //~v777I~
#endif                                                             //~v777I~
                      char      slinkdummy[4]; //pslink point this when no slink//~v6qaI~
                      char      uname[MAXUNAMESZ+1];   //for ftp:user name//~v59fI~
                      char      gname[MAXGNAMESZ+1];   //for ftp:group name//~v59fI~
//*                         initline/vv/mm/creation date by FDATE fmt for TSO SPF//~v5jyI~
                      char      slinkuname[MAXUNAMESZ+1];   //for ftp:user name//~v5a6I~
                      char      slinkgname[MAXGNAMESZ+1];   //for ftp:group name//~v5a6I~
                    } UDIRLIST;                                    //~v327I~
typedef UDIRLIST *PUDIRLIST;                                       //~v327I~
#define UDIRLISTSZ (sizeof(UDIRLIST))                              //~v327I~
//*********************************************************        //~v327I~
#else //!UNX                                                       //~v327I~
//* define same structure as OS/2
#if defined(DOS) || defined(W32)                                   //~v022R~
#if (_MSC_VER >= 800)                                              //~v034I~
    typedef void  *HDIR;                                           //~v034I~
#else                                                              //~v034I~
typedef unsigned long HDIR;
#endif                                                             //~v034I~
//*same definition as OS/2 for option
    #ifdef W32                                                     //~v022I~
        #if (_MSC_VER >= 800)                                      //~v034I~
            #define FILE_NORMAL     0x0000                         //~v034I~
            #define FILE_READONLY   _A_RDONLY                      //~v034I~
            #define FILE_HIDDEN     _A_HIDDEN                      //~v034I~
            #define FILE_SYSTEM     _A_SYSTEM                      //~v034I~
            #define FILE_DIRECTORY  _A_SUBDIR                      //~v034R~
            #define FILE_ARCHIVED   _A_ARCH                        //~v034I~
        #else                                                      //~v034I~
        #define FILE_NORMAL     0x0000                             //~v022I~
        #define FILE_READONLY   FA_RDONLY                          //~v022I~
        #define FILE_HIDDEN     FA_HIDDEN                          //~v022I~
        #define FILE_SYSTEM     FA_SYSTEM                          //~v022I~
        #define FILE_VOLID      FA_LABEL                           //~v022I~
        #define FILE_DIRECTORY  FA_DIREC                           //~v022I~
        #define FILE_ARCHIVED   FA_ARCH                            //~v022I~
        #endif                                                     //~v034I~
//** for ftp support                                               //~v59dR~
    	#define FILE_REMOTE     0x0040  //ftp file                 //~v59dI~
    	#define FILE_SPECIAL    0x0080  //special file for ftp file//~v59dI~
                                                                   //~v59fI~
    	#define FILE_FTPWKSL    0x0100  //work flag for ftp slink process//~v59fI~
//      #define FILE_FTPJST     0x0200  //ftime is ajusted by tz   //~v59dI~//~v6k4R~
        #define FILE_SLINKERR   0x0200  //loop/duplicated slink entry//~v6kcR~
    	#define FILE_FTPWKSL2   0x0400  //work flag for slink dup chk//~v59dI~
//      #define FILE_REPARSE    0x0400  //=WinNT.h:FILE_ATTRIBUTE_REPARSE_POINT;use FILE_SLINK//~v6k4R~
    	#define FILE_SLINK      0x0800  //slink entry              //~v62aI~
#ifdef W32                                                         //~v6q0I~
        #define FILE_WILDNAME   0x2000  //=FILE_ALIAS of TSO file; //~v6q0R~
                                        //has alias && membername contains wildchar(*?)//~v6q0M~
        #define FILE_WILDNAMEER 0x4000  //=FILE_SPFDS of TSO file; wildname without alias//~v6q0I~
        #define FILE_IS_WILDNAME(attr) (attr & FILE_WILDNAME)      //~v6q0R~
        #define FILE_IS_WILDNAMEER(attr) (attr & FILE_WILDNAMEER)  //~v6q0I~
#endif                                                             //~v6q0I~
                                                                   //~v62aI~
    	#define FILE_ISNOSLINKDIR(attr) (((attr) & FILE_DIRECTORY) && ((attr) & FILE_SLINK)==0)//~v62aI~
    	#define FILE_ISSLINKDIR(attr) (((attr) & FILE_DIRECTORY) && ((attr) & FILE_SLINK))//~v62aI~
    	#define FILE_ISSLINK(attr) ((attr) & FILE_SLINK)           //~v62aI~
                                                                   //~v62aI~
    	#define FILE_GETMODE(modeattr) (modeattr>>16)              //~v59dI~
    	#define FILE_SETMODEATTR(mode,attr) ((mode<<16)|(attr & FILE_ATTRMASK))//~v59dI~
    	#define FILE_GETATTR(modeattr) (modeattr & FILE_ATTRMASK)  //~v59dI~
        #define FILE_MODEMASK   0xffff0000  //mode mask on attr+mode//~v59dI~
        #define FILE_CHMODMASK_UNIX  07777       //chmod availbit 0x0fff//~v59dI~
        #define FILE_CHMODMASK_MODE 0x0fff0000   //chmod availbit on mode part//~v59dI~
//*win                                                             //~v6k4I~
#ifdef W32                                                         //~v6k4I~
        #define FILE_MODEMASK_IFMT      0xf0000000   //IFMT mask   //~v6k4I~
        #define FILE_NTFS_SLINK         0x80000000   //NTFS symlink//~v6k4I~
        #define FILE_NTFS_MOUNTVOL      0x40000000   //NTFS MOUNTPOINT//~v6k4I~
        #define FILE_NTFS_JUNCTION      0x20000000   //NTFS junction to file/dir//~v6k4R~
        #define FILE_NTFS_OTHER_REPARSE 0x10000000   //NTFS reparse except symlinc and junction//~v6k4R~
        #define FILE_MODEISNTFS_SLINK(mode) ((mode & FILE_MODEMASK_IFMT)==FILE_NTFS_SLINK)//~v6k4I~
        #define FILE_MODEISNTFS_JUNCTION(mode) ((mode & FILE_MODEMASK_IFMT)==FILE_NTFS_JUNCTION)//~v6k4I~
        #define FILE_MODEISNTFS_MOUNTVOL(mode) ((mode & FILE_MODEMASK_IFMT)==FILE_NTFS_MOUNTVOL)//~v6k4I~
        #define FILE_MODEISNTFS_OTHER_REPARSE(mode) ((mode & FILE_MODEMASK_IFMT)==FILE_NTFS_OTHER_REPARSE)//~v6k4I~
        #define FILE_MODEISNTFS_REPARSE(mode) \
                (\
        			FILE_MODEISNTFS_SLINK(mode)\
        		||	FILE_MODEISNTFS_JUNCTION(mode)\
        		||	FILE_MODEISNTFS_MOUNTVOL(mode)\
        		||	FILE_MODEISNTFS_OTHER_REPARSE(mode)\
                )                                                  //~v6k4I~
        #define FILE_MODEISNTFS_JUNCTION2FILE(mode) \
        		( FILE_MODEISNTFS_JUNCTION(mode)\
                && !(mode & FILE_DIRECTORY))                       //~v6k4I~
        #define FILE_MODEISNTFS_JUNCTION2DIR(mode) \
        		( FILE_MODEISNTFS_JUNCTION(mode)\
                && (mode & FILE_DIRECTORY))                        //~v6k4I~
#endif //W32                                                       //~v6k4I~
#ifdef UTF8SUPPH                                                   //~v62aM~
//      #define FILE_ATTRMASK   (0x000000ff|FILE_SLINK)  //mode mask on attr+mode//~v62aI~//~v6qbR~
        #define FILE_ATTRMASK   (0x000000ff|FILE_SLINK|FILE_SLINKERR)  //mode mask on attr+mode//~v6qbI~
#else                                                              //~v62aM~
        #define FILE_ATTRMASK   0x000000ff  //mode mask on attr+mode//~v5deR~
#endif                                                             //~v62aM~
        #define FILE_ALLSP (FILE_ALL | FILE_SPECIAL)               //~v59dI~
                                                                   //~v59dI~
                                                                   //~v022I~
        #ifndef _INC_WINDOWS                                       //~v022R~
          #ifndef _WINDOWS_H     //mingw windows.h                 //~v5ncI~
            #if (_MSC_VER >= 800)                                  //~v034I~
            #else                                                  //~v034I~
            #define ERROR_FILE_NOT_FOUND    ENOFILE     //doserr:2 //~v022R~
            #define ERROR_PATH_NOT_FOUND    ENOPATH     //doserr:3 //~v022R~
            #define ERROR_NO_MORE_FILES     ENMFILE     //doserr:18//~v022R~
            #endif                                                 //~v034I~
          #endif                                                   //~v5ncI~
        #else                                                      //~v022R~
        #endif                                                     //~v022R~
                                                                   //~v022I~
    #else                                                          //~v022I~
                                                                   //~v022I~
    #define FILE_NORMAL     0x0000                              //~5909R~
    #define FILE_READONLY   0x0001                              //~5909R~
    #define FILE_HIDDEN     0x0002                              //~5909R~
    #define FILE_SYSTEM     0x0004                              //~5909R~
    #define FILE_VOLID      0x0008  //dos only                  //~5909R~
    #define FILE_DIRECTORY  0x0010                              //~5909R~
    #define FILE_ARCHIVED   0x0020                              //~5909R~
//***
    #define ERROR_FILE_NOT_FOUND    2       /* MSG%FILE_NOT_FOUND */
    #define ERROR_PATH_NOT_FOUND    3       /* MSG%PATH_NOT_FOUND */
    #define ERROR_NO_MORE_FILES     18      /* MSG%NO_MORE_FILES */
                                                                   //~v022I~
    #endif                                                         //~v022I~
//***
    #ifdef DPMI                 //DPMI version                     //~v053I~
typedef struct _FTIME           /* ftime */                        //~v053I~
         {                                                         //~v053I~
            unsigned short  twosecs : 5;                           //~v053I~
            unsigned short  minutes : 6;                           //~v053I~
            unsigned short  hours   : 5;                           //~v053I~
         } FTIME;                                                  //~v053I~
    #else                       //not DPMI                         //~v053I~
      #ifdef W32                                                   //~v195I~
typedef struct _FTIME           /* ftime */                        //~v195I~
         {                                                         //~v195I~
            unsigned short  twosecs : 5;                           //~v195I~
            unsigned short  minutes : 6;                           //~v195I~
            unsigned short  hours   : 5;                           //~v195I~
         } FTIME;                                                  //~v195I~
      #else                     //DOS                              //~v195I~
typedef struct _FTIME           /* ftime */
         {
            unsigned int    twosecs : 5;
            unsigned int    minutes : 6;
            unsigned int    hours   : 5;
         } FTIME;
      #endif                                                       //~v195I~
    #endif                      //DPMI or not                      //~v053I~
typedef FTIME *PFTIME;

    #ifdef DPMI                 //DPMI version                     //~v053I~
typedef struct _FDATE           /* fdate */                        //~v053I~
         {                                                         //~v053I~
            unsigned short    day     : 5;                         //~v053I~
            unsigned short    month   : 4;                         //~v053I~
            unsigned short    year    : 7;                         //~v053I~
         } FDATE;                                                  //~v053I~
    #else                       //not DPMI                         //~v053I~
      #ifdef W32                                                   //~v195I~
typedef struct _FDATE           /* fdate */                        //~v195I~
         {                                                         //~v195I~
            unsigned short    day     : 5;                         //~v195I~
            unsigned short    month   : 4;                         //~v195I~
            unsigned short    year    : 7;                         //~v195I~
         } FDATE;                                                  //~v195I~
      #else                     //DOS                              //~v195I~
typedef struct _FDATE           /* fdate */
         {
            unsigned int    day     : 5;
            unsigned int    month   : 4;
            unsigned int    year    : 7;
         } FDATE;
      #endif                                                       //~v195I~
    #endif                      //DPMI or not                      //~v053I~
typedef FDATE   *PFDATE;
#define FDATE2USHORT(fd) (USHORT)(((fd.year)<<9)|((fd.month)<<5)|((fd.day)))//~v6p3I~
#define USHORT2FDATE(fd,us) ( fd.year=((us)&0xffff)>>9, fd.month=((us)&0x01ff)>>5, fd.day=(us)&0x1f )//~v6qbI~
#define FTIME2USHORT(ft) (USHORT)(((ft.hours)<<11)|((ft.minutes)<<5)|((ft.twosecs)))//~v6p3I~
#define USHORT2FTIME(ft,us) ( ft.hours=((us)&0xffff)>>11, ft.minutes=((us)&0x07ff)>>5, ft.twosecs=(us)&0x1f )//~v6qbI~
#define PFDATE2USHORT(pfd) (USHORT)(((pfd->year)<<9)|((pfd->month)<<5)|((pfd->day)))//~v6p3I~
#define PFTIME2USHORT(pft) (USHORT)(((pft->hours)<<11)|((pft->minutes)<<5)|((pft->twosecs)))//~v6p3I~

    #ifdef W32                                                     //~v022I~
        #if (_MSC_VER >= 800)                                      //~v034I~
//same format as WIN32_FIND_DATA                                   //~v034I~
                                                                   //~v6b1I~
//*W32*** if changed check Sffb3root of uftp.c ****                //~v6b1R~
            typedef struct _FILEFINDBUF3 {                         //~v034I~
                          ULONG         attrFile;       //DWORD dwFileAttributes//~v034R~
                  		  ULONG         srcattr; //slink source attr;mode(2)+rsv(1)+attr(1)//~v59fR~
//*                                      lrecl+blksize for TSO file//~v5jyI~
                          FTIME         ftimeLastWrite; //ftLastWriteTime//~v034R~
                          FDATE         fdateLastWrite; //:        //~v034R~
                          FILETIME      ftCreationTime;   //by FindFirstFile API//~v547I~
                          FILETIME      ftLastAccessTime;          //~v547I~
                          FILETIME      ftLastWriteTime;           //~v547I~
#define FILETIME1SEC      10000000      //1 sec by 100ns(unit of FILETIME)//~v6huR~
#define FILETIMESEC(filetime) (((filetime).dwLowDateTime)/FILETIME1SEC)//~v6huI~
                                                                   //~v6huI~
//                        ULONG         cbFile;         //nFileSizeLow//~v5k0R~
                          FILESZT       cbFile;         //nFileSizeLow//~v5k0I~
    		              FTIME     	slinkftime;                //~v59xI~
//*                                 SPF  update time for TSO SPF   //~v5jaI~
        		          FDATE     	slinkfdate;                //~v59xI~
//*                                 SPF  update date for TSO SPF   //~v5jaI~
//          		      ULONG     	slinksize;                 //~v5k0R~
            		      FILESZT   	slinksize;                 //~v5k0I~
//*                                        line count for TSO SPF  //~v5jaI~
//                        char          cFileName[260]; //MAX_PATH of windef.h//~v034R~//~v6uaR~
                          char          cFileName[MAXFILENAMEZ]; //MAXFILENAME of UD fmt//~v6uaR~
//                        char          achName[14];    //cAlternateFileName//~v034R~//~v6uaR~
                          char          achName[MAXFILENAMEZ_FAT];    //from cAlternateFileName//~v6uaR~
                          //*           no UD fmt. if subchar, set bestfit//~v6uaI~
                          char          slink[MAXSLINKNMSZ];   //for ftp:slink source filename//~v59fR~
                          				//*UD fmt				   //~v6uaR~
                          char          uname[MAXUNAMESZ+1];   //for ftp:user name//~v59fR~
                          char          gname[MAXGNAMESZ+1];   //for ftp:group name//~v59fR~
//*                         initline/vv/mm/creation date by FDATE fmt for TSO SPF//~v5jyM~
                          char          slinkuname[MAXUNAMESZ+1];   //for ftp:user name//~v5a6I~
                          char          slinkgname[MAXGNAMESZ+1];   //for ftp:group name//~v5a6I~
#ifdef W32UNICODE                                                  //~v6uaI~
                          int           otherflag;                 //~v6uaI~
        		#define FFB3OF_SUBCHFNAME   0x01   //cFileName contains substitution char//~v6uaI~
        		#define FFB3OF_SUBCHSLINK   0x02   //slink     contains substitution char//~v6uaI~
        		#define FFB3OF_SUBCHALTNAME 0x04   //alias     contains substitution char//~v6uaR~
        		#define FFB3OF_UDFMTFNAME   0x08   //cFileName by UD fmt//~v6uaI~
                          int           cFileNameWctr;             //~v6uaI~
                          int           achNameWctr;               //~v6uaI~
                          int           slinkWctr;                 //~v6uaI~
		                  UWCH      	cFileNameW[_MAX_PATHWC];   //~v6uaI~
		                  UWCH      	achNameW[MAXFILENAMEZ_FAT];//~v6uaR~
//        		          UWCH      	slinkW[MAXSLINKNMSZ]; //4096//~v6uaI~//~v6HcR~
          		          UWCH      	slinkW[MAXSLINKNMSZWC]; //4096//~v6HcI~
#endif                                                             //~v6uaI~
                        } FILEFINDBUF3;                            //~v034I~
        #else                                                      //~v034I~
        typedef struct _FILEFINDBUF3 {                             //~v022I~
                      long          reserved;                      //~v022I~
                      long          cbFile;                        //~v022I~
                      unsigned long attrFile;                      //~v022I~
                      FTIME         ftimeLastWrite;                //~v022I~
                      FDATE         fdateLastWrite;                //~v022I~
                      char          achName[256];                  //~v022I~
                    } FILEFINDBUF3;                                //~v022I~
        #endif                                                     //~v034I~
    #else                                                          //~v022I~
        #ifdef DPMI                 //DPMI version                 //~v053I~
typedef struct _FILEFINDBUF3 {                                     //~v053I~
                  char      reserved[21]   __attribute__((packed));//~v053I~
                  char      attrFile       __attribute__((packed));//~v053I~
                  FTIME     ftimeLastWrite __attribute__((packed));//~v053I~
                  FDATE     fdateLastWrite __attribute__((packed));//~v053I~
                  unsigned  long cbFile    __attribute__((packed));//~v053I~
//                char      achName[256]   __attribute__((packed));//~v101R~
                  char      cFileName[260] __attribute__((packed));//~v101R~
                  char      achName[MAXFILENAMEZ_FAT]    __attribute__((packed));//~v101R~
                } FILEFINDBUF3;                                    //~v053I~
        #else                       //not DPMI                     //~v053I~
typedef struct _FILEFINDBUF3 {
                  char      reserved[21];
                  char      attrFile;
                  FTIME     ftimeLastWrite;
                  FDATE     fdateLastWrite;
                  unsigned  long cbFile;
                  char      achName[13];
                } FILEFINDBUF3;
        #endif                      //DPMI or not                  //~v053I~
    #endif                                                         //~v022I~
#endif
//*********************************************************        //~v327R~
#define FILE_ALL (FILE_NORMAL|FILE_READONLY|FILE_HIDDEN|FILE_SYSTEM \
                 |FILE_DIRECTORY|FILE_ARCHIVED)                 //~5909I~
#define FILE_CHMODMASK (FILE_READONLY|FILE_HIDDEN|FILE_SYSTEM|FILE_ARCHIVED)//~5909I~
//******************************************************
//file sort list v4.6a
//*!UNX                                                            //~v6b1I~
typedef struct _UDIRLIST{
#ifdef DOS                                                         //~v101I~
    #ifdef DPMI                 //DPMI version                     //~v101I~
                      char          name[MAXFILENAMEZ];            //~v101R~
                      char          alias[MAXFILENAMEZ_FAT];       //~v101R~
    #else                                                          //~v101I~
                      char          name[MAXFILENAMEZ_FAT];        //~v101R~
                      char          rsv[1];     //dword boundary   //~v101R~
    #endif                                                         //~v101I~
#else                                                              //~v101I~
    #ifdef W32                                                     //~v101I~
                      FILETIME      ftCreationTime;   //by FindFirstFile API//~v547I~
                      FILETIME      ftLastAccessTime;              //~v547I~
                      FILETIME      ftLastWriteTime;               //~v547I~
//                    char          name[MAXFILENAMEZ];            //~v101R~//~v6J0R~
                      int           namesz;                        //~v6J0I~
                      char         *name;                          //~v6J0I~
                      char          nameShortbuff[SHORTNAME_FLDSZ];//~v6J0I~
#define UDIRLISTNAMESZ  MAXFILENAMEZ                               //~v6J0I~
                      //                               by UD fmt   //~v6uaI~
                      char          alias[MAXFILENAMEZ_FAT];       //~v101R~
                      //*           no UD fmt. if subchar, set bestfit//~v6uaI~
    #else             //os2                                        //~v101R~
                      char          name[MAXFILENAMEZ];            //~v101R~
    #endif                                                         //~v101I~
#endif                                                             //~v101I~
//                    char          attr;                          //~v59eR~
                      ULONG         attr;   //4 byte for ftp support//~v59eI~
#ifdef FTPSUPP                                                     //~v59fR~
                      ULONG      srcattr;   //for ftp:slink source attr//~v59fR~
                      ULONG      workflag;                         //~v6keI~
//*                                      lrecl+blksize for TSO SPF //~v5jaI~
#endif                                                             //~v59fR~
                      FTIME         time;
                      FDATE         date;
					#ifdef OS2                                     //~v547I~
                      FTIME         atime; //last access           //~v547I~
                      FDATE         adate;                         //~v547I~
                      FTIME         ctime; //creation              //~v547I~
                      FDATE         cdate;                         //~v547I~
					#endif                                         //~v547I~
//                    unsigned long size;                          //~v5k0R~
                      FILESZT       size;                          //~v5k0I~
    #ifdef W32                                                     //~v59fI~
    		          FTIME     	slinkftime;                    //~v59xI~
//*                                 SPF  update time for TSO SPF   //~v5jaI~
        		      FDATE     	slinkfdate;                    //~v59xI~
//*                                 SPF  update date for TSO SPF   //~v5jaI~
//          		  ULONG     	slinksize;                     //~v5k0R~
            		  FILESZT   	slinksize;                     //~v5k0I~
//*                                        line count for TSO SPF  //~v5jaI~
//                    UCHAR         slink[MAXSLINKNMSZ];   //for ftp:slink source filename//~v59fR~//~v6qaR~
                      char          *pslink;                 //for ftp:slink source filename//~v6qaR~
                      				//*UD fmt                      //~v6uaI~
                      int           otherflag;                     //~v6qaI~
#define UDLOF_SLINK_ALLOC           0x0001     //pslink points malloced area//~v6qaI~
#define UDLOF_WKENTRY               0x0002     //udirlist is work variable//~v6qaI~
#define UDLOF_ALLOC1                0x0004     //name may be null but slink allocated//~v6qdI~
#define UDLOF_SLINKNAME_NA          0x0008     //psftp dose not show slink target//~v6qbI~
#define UDLOF_ALLOCNAME             0x0010     //*name point malloc//~v6J0I~
#define UDLOF_ALLOCNAMEW            0x0020     //*nameW point malloc//~v6J0I~
#define UDLOF_ALLOC_FLAGS (\
        UDLOF_SLINK_ALLOC  \
       |UDLOF_WKENTRY      \
       |UDLOF_ALLOC1       \
/*      UDLOF_SLINKNAME_NA*/ \
       |UDLOF_ALLOCNAME    \
	   |UDLOF_ALLOCNAMEW   \
       )                                                           //~v6J0I~
                      char          slinkdummy[4]; //pslink point this when no slink//~v6qaI~
                      UCHAR         uname[MAXUNAMESZ+1];   //for ftp:user name//~v59fI~
                      UCHAR         gname[MAXGNAMESZ+1];   //for ftp:group name//~v59fI~
//*                         initline/vv/mm/creation date by FDATE fmt for TSO SPF//~v5jyI~
                      UCHAR         slinkuname[MAXUNAMESZ+1];   //for ftp:user name//~v5a6I~
                      UCHAR         slinkgname[MAXGNAMESZ+1];   //for ftp:group name//~v5a6I~
        #ifdef W32UNICODE                                          //~v6uaI~
                      int           ffb3otherflag;                 //~v6uaI~
                      int           nameWctr;                      //~v6uaI~
                      int           aliasWctr;                     //~v6uaI~
                      int           pslinkWctr;                    //~v6uaI~
                      int           nameWsz;                       //~v6J0I~
                      UWCH          nameWShortbuff[SHORTNAME_FLDSZ];//~v6J0M~
//  	              UWCH      	nameW[_MAX_PATH];              //~v6uaI~//~v6J0R~
    	              UWCH         *nameW;                         //~v6J0I~
#define UDIRLISTNAMEWSZ     ctr2szW(MAXFILENAMEZWC)                //~v6J0R~
		              UWCH      	aliasW[MAXFILENAMEZ_FAT];      //~v6uaI~
        		      PUWCH      	pslinkW;                       //~v6uaI~
        #endif                                                     //~v6uaI~
    #endif          //W32                                          //~v59fI~
                    } UDIRLIST;
typedef UDIRLIST *PUDIRLIST;
#define UDIRLISTSZ (sizeof(UDIRLIST))
#endif//!UNX                                                       //~v327M~
                                                                   //~v6D2I~
#define FTMASK_HH(hh)  ((USHORT)(hh) & 0x1f)    //5bit             //~v6D2M~
#define FTMASK_MM(mm)  ((USHORT)(mm) & 0x3f)    //6bit             //~v6D2M~
#define FTMASK_SS(ss)  ((USHORT)(ss) & 0x1f)    //5bit             //~v6D2M~
#define FTMASK_HH_SHIFT 11      //6+5 bit                          //~v6D2M~
#define FTMASK_MM_SHIFT 5       //5 bit                            //~v6D2M~
#define FTMASK_SS_SHIFT 0       //5 bit                            //~v6D2M~
                                                                   //~v6D2I~
#define FDMASK_YY(yy)  ((USHORT)(yy) & 0x7f)    //7bit             //~v6D2M~
#define FDMASK_MM(mm)  ((USHORT)(mm) & 0x0f)    //4bit             //~v6D2M~
#define FDMASK_DD(dd)  ((USHORT)(dd) & 0x1f)    //5bit             //~v6D2M~
#define FDMASK_YY_SHIFT 9       //4+5 bit                          //~v6D2M~
#define FDMASK_MM_SHIFT 5       //5 bit                            //~v6D2M~
#define FDMASK_DD_SHIFT 0       //5 bit                            //~v6D2M~
                                                                   //~v6D2I~
#define MAKE_FTIME(hh,mm,ss)\
        (USHORT)( (FTMASK_HH(hh)<<FTMASK_HH_SHIFT) \
                | (FTMASK_MM(mm)<<FTMASK_MM_SHIFT) \
                | (FTMASK_SS(ss)<<FTMASK_SS_SHIFT) \
                )                                                  //~v6D2M~
#define MAKE_FDATE(yy,mm,dd)\
        (USHORT)( (FDMASK_YY(yy)<<FDMASK_YY_SHIFT) \
                | (FDMASK_MM(mm)<<FDMASK_MM_SHIFT) \
                | (FDMASK_DD(dd)<<FDMASK_DD_SHIFT) \
                )                                                  //~v6D2M~
#if defined(W32)||defined(UNX)                                     //~v6kcR~
    #define IS_SLINKERR(attr)   ((attr & FILE_SLINK) && (attr & FILE_SLINKERR))//~v6kcR~
//*for PUDIRLIST->workflag**                                       //~v6keI~
    #define UDIRLWF_WALK_SLINKERR   0x01 //for dirwalk             //~v6keI~
    #define UDIRLWF_WALK_DIRMASK_NG 0x02 //for dirwalk             //+vat5R~
    #define UDIRLWF_WALK_DIRMASK_OK 0x04 //for dirwalk             //+vat5I~
#endif                                                             //~v6kcI~
//#define MAXUDIRLISTALLOCSZ      0x01000000                         //~v6qbR~//~v6HuR~
//#define MAXUDIRLISTALLOCSZ      (1<<25)                            //~v6HuI~//~v6J0R~
#define MAXUDIRLISTALLOCSZ      (1<<24)  //now reduce UDIRLISTSZ   //~v6J0I~
//******************************************************           //~v6qaI~
#define UDIRLIST_FREE(pudl) ufile_udirlist_free(1,(PUDIRLIST)(pudl))//~v6qaR~
//#define UDIRLIST_FREE_COPYED(pudl) ufile_udirlist_free(0,(PUDIRLIST)(pudl))//~v6qaR~
void ufile_udirlist_free(int Popt,PUDIRLIST Ppudl);                //~v6qaR~
//******************************************************           //~v6qaI~
#define UDIRLIST_COPY(pudlto,pudlfrom) ufile_udirlist_copy(0,(PUDIRLIST)(pudlto),(PUDIRLIST)(pudlfrom))//~v6qaI~
//#define UDIRLIST_COPY_NEW_SLINKNAME(pudlto,pudlfrom) ufile_udirlist_copy(1,(PUDIRLIST)(pudlto),(PUDIRLIST)(pudlfrom))//~v6qaR~
//#define UDIRLIST_COPY_NEW_SLINKNAME(pudlto,pudlfrom) ufile_udirlist_copy(UFDLCO_NEWSLINKNAME,(PUDIRLIST)(pudlto),(PUDIRLIST)(pudlfrom))//~v6uCI~//~v6J0R~
void ufile_udirlist_copy(int Popt,PUDIRLIST Ppudlto,PUDIRLIST Ppudlfrom);//~v6qaI~
//#define UFDLCO_NEWSLINKNAME 0x01                                   //~v6qaI~//~v6J0R~
//******************************************************           //~v6qaI~
#define UDIRLIST_SET_SLINKNAME(pudl,slinkname) \
	udirlist_set_slinkname(pudl,slinkname)                         //~v6qaI~
void udirlist_set_slinkname(PUDIRLIST Ppudl,char *Pslinkname);     //~v6qaI~
//******************************************************           //~v6qaI~
#define UDIRLIST_GET_SLINKNAME_OR_NULLSTR(pudl) \
	((pudl)->pslink?(pudl)->pslink:"")                             //~v6qaR~
//******************************************************           //~v6qaI~
#define UDIRLIST_ALLOC1(opt) \
	ufile_udirlist_alloc1(opt)                                     //~v6qaI~
PUDIRLIST ufile_udirlist_alloc1(int Popt);                         //~v6qaI~
#define UDA1O_ALLOC_SLINKNAME    0x01                              //~v6qaI~
//******************************************************
#ifdef AAA                                                         //~v6J0I~
#define UDIRLIST_WK(udlwk,slnwk) \
	UDIRLIST udlwk; char slnwk[MAXSLINKNMSZ]={0}                   //~v6qaR~
#define UDIRLIST_WK_INIT(udlwk,slnwk) \
	(memset(&(udlwk),0,sizeof(udlwk)),\
	 memset(slnwk,0,sizeof(slnwk)),\
     (udlwk).pslink=slnwk,\
     (udlwk).otherflag|=UDLOF_WKENTRY\
    )                                                              //~v6qaI~
#else   //AAA                                                      //~v6J0R~
    #ifdef W32                                                     //~v6J0I~
        #define UDIRLIST_WK(_udlwk,_namewk,_namewkW,_slnwk) \
            UDIRLIST _udlwk;                                \
            char _namewk[UDIRLISTNAMESZ];                   \
            UWCH _namewkW[MAXFILENAMEZWC];                  \
            char _slnwk[MAXSLINKNMSZ]={0};                  \
            UWCH _slnwk##W[MAXSLINKNMSZWC]={0}                     //~v6J0I~
                                                                   //~v6J0I~
        #define UDIRLIST_WK_INIT(_udlwk,_namewk,_namewkW,_slnwk) \
            (memset(&(_udlwk),0,sizeof(_udlwk)),                 \
             memset(_namewk,0,sizeof(_namewk)),                  \
             memset(_namewkW,0,sizeof(_namewkW)),                \
             memset(_slnwk,0,sizeof(_slnwk)),                    \
             memset(_slnwk##W,0,sizeof(_slnwk##W)),              \
             (_udlwk).name=_namewk,                              \
             (_udlwk).namesz=sizeof(_namewk),                    \
             (_udlwk).nameW=_namewkW,                            \
             (_udlwk).nameWsz=sizeof(_namewkW),                  \
             (_udlwk).pslink=_slnwk,                             \
             (_udlwk).pslinkW=_slnwk##W,                         \
             (_udlwk).otherflag|=UDLOF_WKENTRY                   \
            )                                                      //~v6J0I~
    #else                                                          //~v6J0I~
        #define UDIRLIST_WK(_udlwk,_namewk,_namewkW,_slnwk)      \
            UDIRLIST _udlwk;                                     \
            char _namewk[UDIRLISTNAMESZ];                        \
            char _slnwk[MAXSLINKNMSZ]                              //~v6J0R~
                                                                   //~v6J0I~
        #define UDIRLIST_WK_INIT(_udlwk,_namewk,_namewkW,_slnwk) \
            (memset(&(_udlwk),0,sizeof(_udlwk)),                 \
             memset(_namewk,0,sizeof(_namewk)),                  \
             memset(_slnwk,0,sizeof(_slnwk)),                    \
             (_udlwk).name=_namewk,                              \
             (_udlwk).namesz=sizeof(_namewk),                    \
             (_udlwk).pslink=_slnwk,                             \
             (_udlwk).otherflag|=UDLOF_WKENTRY                   \
            )                                                      //~v6J0I~
    #endif                                                         //~v6J0I~
#endif //!AAA                                                      //~v6J0R~
#define UMAXPATHCHK(fnm,len,rc,msgsw)                            \
    do                                                           \
	{                                                            \
    	if (strnlen(fnm,len)==(size_t)len)                               \
        {                                                        \
        	if (msgsw)                                           \
				ufileTooLongFullpathName2(rc,fnm,0);             \
            if (rc)	/*if rc=0 , continue */                      \
            	return rc;                                       \
        }                                                        \
	} while(0)                                                     //~v6H1I~
#define UMAXPATHCHK_RC(fnm,len,rc,msgsw)                            \
     ( (strnlen(fnm,len)==(size_t)len)                                      \
     ?   ((msgsw) ? ufileTooLongFullpathName2(rc,fnm,0) : (rc))     \
     :0                                                             \
     )                                                             //~v6H1I~
//*******************************************************
unsigned int ufstatWLong(int Popt,char *Ppfile,size_t Pbuffsz,FILEFINDBUF3 *Ppffb3);//~v6H9I~
//*******************************************************          //~v6H9I~
unsigned int ufstat(char *Ppfile,FILEFINDBUF3 *Ppffb3);
//*******************************************************      //~4C18I~
char *ufullpath(char *Pfullpath,char *Pfilename,size_t Plen);  //~4C18I~
//*******************************************************          //~v6B9I~
char *ufullpathCP(int Popt,char *Pfullpath,char *Pfilename,size_t Plen,int *Prc);//~v6B9I~
#define UFPCPO_NOCONV  0x01   //no chk iocharset                   //~v6B9I~
#define UFPCPRC_CONVU8        0x01   //converted to utf            //~v6B9R~
#define UFPCPRC_IOCS_U8       0x02   //mount option:iocharset is utf8//~v6B9I~
#define UFPCPRC_IOCS_UNKNOWN  0x04   //mount option:iocharset is unknown,default is utf8//~v6B9I~
//*******************************************************          //~v5kdI~
int ufullpathresolvespecialdirid(char *Pfpath,int Pdirsepc);       //~v5kdI~
//*******************************************************          //~v50FI~
int ufullpathwildexp(int Popt,char *Pfullpath,char *Pfilename,size_t Plen);//~v50FR~
#define FPOPT_MEMBEXP    0x01                                      //~v50FR~
//*******************************************************          //~v016I~
int upathlen(char *Pfilename);                                     //~v016I~
//*******************************************************       //~5708I~
unsigned char ugetdrive(void);                                  //~5708I~
//*******************************************************       //~5708I~
char *ugetcwd(unsigned char *Pbuff);                            //~5708R~
//*******************************************************          //~v6ybI~
#ifdef W32                                                         //~v6ybI~
int ugetcwdW(int Popt,unsigned char *Pbuff);                       //~v6ybR~
#define UGCWDWO_DROPPREFIX 0x01 //drop reserved name prefix and set rc=1//~v6ybI~
#endif                                                             //~v6ybI~
//*******************************************************       //~5708I~
int uchdrive(char Pdriveletter);                                //~5708I~
//*******************************************************       //~5708I~
//int uchdir(unsigned char *Ppath);                                //~v578R~
int uchdir(int Popt,unsigned char *Ppath);                         //~v578I~
#define UCHD_NOMSG 0x01		//no errmsg option                     //~v578I~
//**********************************************************************//~v781I~
unsigned udosfindfirstOpt(int Popt,char *Ppfname,HDIR *Pphdir,unsigned int Pattr,FILEFINDBUF3 *Ppfstat3);//~v781I~
#define UDFFOO_NOMSG      0x01		//no errmsg option             //~v781R~
#define UDFFOO_ALLOWDIR   0x02		//allow existing dir           //~v781I~
#define UDFFOO_ERRNOENTRY 0x04		//issue errmsg noentry, optio for not list(browse/edit) dirlist//~v784I~
//**********************************************************************//~v179I~
unsigned udosfindfirstnomsg(char *Ppfname,HDIR *Pphdir,unsigned int Pattr,//~v179I~
                        FILEFINDBUF3 *Ppfstat3);                   //~v179I~
//**********************************************************************
unsigned udosfindfirst(char *Ppfname,HDIR *Pphdir,unsigned int Pattr,
                        FILEFINDBUF3 *Ppfstat3);
#ifdef W32                                                         //~v6H9I~
//**********************************************************************//~v6H9I~
unsigned udosfindfirstW(int Popt,char *Pdfname,UWCH *Ppfnamew,HDIR *Pphdir,unsigned int Pattr,//~v6H9I~
                        FILEFINDBUF3 *Ppfstat3);                   //~v6H9R~
#define UDFFWO_NOMSG           0x01                                //~v6H9R~
#endif                                                             //~v6H9I~
//**********************************************************************
//unsigned udosfindnext(HDIR Phdir,FILEFINDBUF3 *Ppfstat3);        //~v6k4R~
unsigned udosfindnext(char *Ppath,HDIR Phdir,FILEFINDBUF3 *Ppfstat3);//~v6k4I~
#ifdef W32                                                         //~v6H9I~
unsigned udosfindnextW(int Popt,char *Ppath,UWCH *Ppathw,HDIR Phdir,FILEFINDBUF3 *Ppfstat3);//~v6H9R~
#endif                                                             //~v6H9I~
//**********************************************************************//~v179I~
int udirlistnomsg(char *Ppdirname,unsigned Pattr,PUDIRLIST *Pppudirlist,//~v179I~
                    int Psorttype);                                //~v179I~
//**********************************************************************
int udirlist(char *Ppdirname,unsigned Pattr,PUDIRLIST *Pppudirlist,
                    int Psorttype);
int udirlistW(int Popt,char *Pdirname,UWCH *Ppdirnamew,unsigned Pattr,PUDIRLIST *Pppudirlist,//~v6H9R~
                    int Psorttype);                                //~v6H9I~
#define UDLWO_NOMSG       0x01                                     //~v6H9R~
//**********************************************************************//~v113I~
int udircomp(PUDIRLIST Ppudirlist1,PUDIRLIST Ppudirlist2,int Psorttype);//~v113I~
//****************************************************************//~5A14I~
FILE *uredirect(int Phandle,char *Pfile,FILE *Pfh);             //~5A15I~
//****************************************************************//~5A14I~
int uredirectrestore(int Phandle);                              //~5A14R~
//*******************************************************       //~5625I~
UCHAR *ufdateedit(FDATE Pdate,UCHAR *Ppatern,UCHAR *Pout);      //~5625I~
//*******************************************************       //~5625I~
UCHAR *uftimeedit(FTIME Ptime,UCHAR *Ppatern,UCHAR *Pout);      //~5625I~
//*******************************************************          //~v6htI~
UCHAR *uftimeedit_1sec(FTIME Ptime,UCHAR *Ppatern,UCHAR *Pout,int Poddsec);//~v6htR~//~v6huR~
//*******************************************************       //~5A14I~
UCHAR *ufdateedit(FDATE Pdate,UCHAR *Ppatern,UCHAR *Pout);      //~5A14I~
//****************************************************************//~5909I~
int ufilenotfound(UCHAR *Pfname,int Prc);                       //~5909I~
//****************************************************************//~5909I~
int ufilepatherr(UCHAR *Ppathname,int Prc);                     //~5909I~
//**************************************************************** //~v59vI~
int ufileisroot(char *Pfname);                                     //~v59vR~
//**************************************************************** //~v5c7I~
int ufilegetpathdir(char *Pfullpath,char *Pdirname);               //~v5d1R~
//**************************************************************** //~v59dI~
void udirlistsort(int Psorttype,PUDIRLIST Ppudirlist,int Pentno);  //~v59dR~
//**************************************************************** //~v5kqI~
int ufilegetlastname(int Popt,void * Ppuftph,char *Pfilename,char *Plastname);//~v5kqI~
//**************************************************************** //~v5kqI~
int ufileconcatlastname(int Popt,void * Ppuftph,char *Pfilename,char *Plastname,char *Pout);//~v5kqI~
//**************************************************************** //~v5kqI~
int ufilefullpathtemp(int Popt,char *Pfname,char *Pout);           //~v5kqI~
#define  FFPT_TIMESTAMP 0x01                                       //~v5kqI~
//**************************************************************** //~v5kqI~
int ufileisnormalfile(int Popt,void * Ppuftph,char *Pfilename);    //~v5kqI~
#define  FINF_ERRMSGALL     0x0f	//issue errmsg all case        //~v5kqI~
#define  FINF_ERRMSGDIR     0x01	//issue errmsg when dir        //~v5kqI~
#define  FINF_ERRMSGSPECIAL 0x02    //issue errmsg when spacial file//~v5kqI~
#define  FINF_ERRMSGSNOTF   0x04    //issue errmsg when not found  //~v5kqI~
//**************************************************************** //~v5kqI~
int ufilenameenclose(int Popt,char *Pfname,char *Pout);            //~v5kqI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v6d8I~
int isRootUNC(int Popt,char *Ppfile);                              //~v6d8I~
#endif //WINREMOTESUPP                                             //~v6d8I~
//**************************************************************** //~v6qbI~
int udirlist_chk_max_entry(int Pctr);                              //~v6qbI~
//**************************************************************** //~v6J0I~
int udirlist_setname(int Popt,PUDIRLIST Ppudl,char *Psrc,size_t Psrcsz);//~v6J0I~
#define UDLSNO_UDIRLISTNAMESZ        0x01   //allocate max size    //~v6J0R~
//**************************************************************** //~v6J0I~
int udirlist_setnameW(int Popt,PUDIRLIST Ppudl,UWCH *PsrcW,int Pucsctr);//~v6J0I~
#define UDLSWNO_UDIRLISTNAMEWSZ      0x01   //allocate max size    //~v6J0I~
//**************************************************************** //~v6J0I~
//*for set Ppudl->name by function call                            //~v6J0I~
//*  once copy to work                                             //~v6J0I~
//*  then after func call copy back to Ppudl->name                 //~v6J0I~
//**************************************************************** //~v6J0I~
#define UDIRLIST_NAMECOPY2WK(_pudl,wkname)                      \
	    char wkname[UDIRLISTNAMESZ];                        \
        if ((_pudl)->name)                                  \
            UstrcpyZ((wkname),(_pudl)->name,sizeof(wkname));\
        else                                                \
            *wkname=0;                                             //~v6J0I~
//**************************************************************** //~v6J0I~
int udirlist_setname_cat(int Popt,PUDIRLIST Ppudl,char *Psrc);     //~v6J0I~
//**************************************************************** //~v6J0I~
void ufile_udirlist_swap(int Popt,PUDIRLIST Ppudl1,PUDIRLIST Ppudl2);//~v6J0R~
