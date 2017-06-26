//CID://+v6H7R~:         update#=   21                             //~v6H7R~
//******************************************************        //~5B11I~
//*ufile3.h                                                     //~5B11I~
//******************************************************        //~5B11I~
//v6H7:170108 FTP crush by long name                               //~v6H7I~
//v6yd:150314 ino_t is not 32 bit                                  //~v6ydI~
//v6uU:140608 support xcopy create option with rename              //~v6uUI~
//v6kd:130625 copy/move warning not by rc but flag to keep rc= for successfull operation//~v6kdI~
//v6k9:130623 slink copy file target option                        //~v6k9I~
//v6k5:130617 (Linux)treate slink like as windows slink            //~v6k5I~
//v6k4:130525 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//            ufile3.h option to skip slink copy                   //~v6k4I~
//v6hv:120808 (WIN)FileTimeToDosDateTime round up to next 2sec;it display different timestamp with dir cmd on cmd prompt//~v5hvI~
//v5je:061013 3270 support:xcopy/xmove                             //~v5jeI~
//v5fg:050125 skip override option for copy/move                   //~v5fgI~
//v5ey:041107 ftp text mode support(for cmd temp file)             //~v5eyI~
//v5e1:040920 support new xcopy option:copy override if updated    //~v5e1I~
//v5ck:040508 (FTP)same remote move spec as loal move              //~v5ckI~
//v5cd:040425 xcopy support option to create src dir intarget dir. //~v5cdI~
//v59r:031124 ftp support:copy/move                                //~v55rI~
//v55n:020503 (AIX)disket support                                  //~v55nI~
//v559:020427 (UNX)disket support(mcopy) for copy file             //~v559I~
//v523:011228 (UNX)no copypathinfo option                          //~v523I~
//v520:011228 support move override                                //~v520I~
//v327 000820:LINUX support                                        //~v327I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//****************************************************************//~5B12M~
int uxcopy(UCHAR *Psource,UCHAR *Ptarget,int Popt,unsigned Pattrmask);//~5B12M~
//#if defined(DOS) || defined(W32)                                 //~v327R~
//#if defined(DOS) || defined(W32) || defined(UNX)                 //~v5cdR~
  #define DCPY_SKIPEXIST  0x80 	//skip copy override and continue copy//~v5fgI~
  #define DCPY_NOSKIPMSG  0x40 	//no msg when bypass by timestamp  //~v5e1R~
  #define DCPY_REPOLD  0x20 	//override if new,else skip copy   //~v5e1R~
  #define DCPY_MOVE     16 	//move operation(for ftp)              //~v5ckI~
  #define DCPY_CREATE    8 	//create source dir in target dir      //~v5cdI~
#ifndef OS2                                                        //~v5e1I~
  #define DCPY_FAILEAS   4     //fail if dest not support EAs   //~5B12M~
  #define DCPY_APPEND    2     //for not dir,append if file exist//~5B12M~
  #define DCPY_EXISTING  1 	//replace if target exist           //~5B12M~
#endif                                                             //~v5e1I~
//#else                                                            //~v5cdR~
//#endif                                                           //~v5cdR~
#define DCPY_ROOT    0x0100 //root to root support              //~5B12M~
#define DCPY_NOCOPYINFO  0x0200 //skip copypathinfo for permission //~v55rI~
#ifdef UNX                                                         //~v523I~
//#define DCPY_NOCOPYINFO  0x0200 //skip copypathinfo for permission//~v55rR~
#define DCPY_NODELDIRMOVE 0x0400 //skip sorce dir itself delete for AIX mdos disk//~v55nI~
#define DCPY_NOINTODIRMOVE 0x0800 //move member if target is dir for the case aix mdos disk//~v55nI~
#endif                                                             //~v523I~
#define DCPY_FTPCOPYFTIMEY 0x1000 //copy filetime for download file=YES//~v55rI~
#define DCPY_FTPCOPYFTIMEN 0x2000 //copy filetime for download file=NO//~v55rI~
#define DCPY_FTPTEXTMODE   0x4000 //textmode(crlf<-->lf)           //~v5eyI~
//                  default AIX=NO, LNX,WIN=YES                    //~v55rI~
#define DCPY_RC_NOTCOPY  4100  //not copyed by the reason of time stamp//~v5e1R~
//#define DCPY_RC_WARNING  -2    //warning issued, don't issue success msg//~v6k5I~//~v6kdR~
#define DCPY_BIN           0x8000 //TSO binary transfer            //~v5jeI~
//#ifdef W32                                                       //~v6k5R~
#if defined(W32)||defined(UNX)                                     //~v6k5I~
  #define DCPY_SKIPSLINK   0x010000//skip slink copy to avoid previlege err//~v6k4I~
#endif                                                             //~v6k4M~
#define DCPY_WILDCOPYMOVE  0x020000 //to copysub/movesub from wildcopy/wildmove//~v6k4I~
#if defined(W32)||defined(UNX)                                     //~v6k5I~
  #define DCPY_CHKSLINKTGT 0x040000//copy/move chk slink target is accessible//~v6k5I~
  #define DCPY_SLINKTGTF   0x080000//copy slink target for file    //~v6k9I~
#endif                                                             //~v6k5I~
#define DCPY_R2R           0x100000 //remote to remote(not create dir on local te,p dir)//~v5jeI~
#ifdef UNX                                                         //~v5jeI~
#define DCPY_REPWILDNAME   0x200000 //rename wildname              //~v5jeI~
#endif                                                             //~v5jeI~
#define DCPY_CREATERENAME  0x400000 //create target top dir        //~v6uUI~
#define DCPY_FTP2TEMPF     0x800000 //create target top dir        //+v6H7R~
//****************************************************************//~5B11I~
//int uxmove(UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask);    //~v520R~
int uxmove(UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask,int Popt);//~v520I~
                                                                   //~v559I~
//**************************************************************** //~v559I~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v559I~
int udoscopy(UCHAR *Psource,UCHAR *Ptarget,int Popt);              //~v559I~
#else                                                              //~v559I~
#endif                                                             //~v559I~
//**************************************************************** //~v5cdI~
int ufileerrdirandfile(char *Psource,char *Ptarget);               //~v55rI~
//**************************************************************** //~v5e1I~
int ufilecopytschk(int Popt,char *Pfnm,                            //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
                time_t Psmodtime,time_t Ptmodtime);                //~v5e1R~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
                FILETIME Psmodtime,FILETIME Ptmodtime);            //~v5e1R~
    #else                                                          //~v5e1R~
                FDATE Psfdate,FTIME Psftime,FDATE Ptfdate,FTIME Ptftime);//~v5e1R~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
//**************************************************************** //~v5hvR~
#ifdef W32                                                         //~v5hvR~
int filetime2dosdatetime(FILETIME *Ppft,USHORT *Ppfdt,USHORT *Ppftm,int *Ppoddsec);//~v5hvR~
#endif                                                             //~v5hvR~
//int ufilechkslinkpath(char *Psrc,char *Pslink,char *Pdest);        //~v6k5I~//~v6k9R~
int ufilechkslinkpath(char *Psrc,char *Pslink,char *Pdest,char *Pslinktarget,FILEFINDBUF3 *Ppffb3);//~v6k9R~
