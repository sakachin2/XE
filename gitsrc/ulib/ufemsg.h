//CID://+v6H9R~:             update#=     16                       //~v6H9R~
//******************************************************
//*ufemsg.h                                                     //~5708I~
//******************************************************        //~5708I~
//v6H9:170109 (Win)del longname using \\?\ prefix(path max is 32767) and Unicode API because move to shortpath dir could not delete dir/file name longer >=260.//~v6H9I~
//v@99:161231 filename >_MAX_PATH occurse when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v@99I~
//            and it cause fpath area overflow then 0c4            //~v@99I~
//v6B7:160121 errmsg for open err with errno=22(Invalid argument)  //~v6B7I~
//v6xb:150111 add apierr with errno description                    //~v6xbI~
//v6km:130704 notfound msg --> dir exist but no file exist;for xcopy wildcard parm sepcified//~v6kmI~
//v6kg:130629 errno=5(ioerr) when symlink created by mklink /D(dir) to a file//~v6kgI~
//v6k8:130623 junction is link to dir,so issue errmsg for junction to file//~v6k8I~
//v6k6:130619 (BUG of v6hc)OSTYPE=6 for 2010 64bit                 //~v6k5I~
//v6hL:120917 chk and errmsg when too long fullpath                //~v6hLI~
//v62b:090724 (FTP:BUG) del dir confirm msg remains when member is file only(no dir member exist)//~v62bI~
//v5kq:070630 remote file compare support                          //~v5kqI~
//v5k0:061226 (LNX/WIN)largefile(>4GB) support                     //~v5k0I~
//v5d9:040530 (FTP)skip upload for r2r to bypass not found msg if downloaded no entry//~v5d9I~
//v5d8:040530 (FTP)hide temp filename for dir to file operation err mnsg//~v5d8I~
//v5d3:040529 (BUG)xmove cannot override same name file            //~v5d3I~
//v5cd:040425 xcopy support option to create src dir intarget dir. //~v5cdI~
//v5av:040112 (FTP)addtional errmsg for FTP like as UNX            //~v5avI~
//v59e:031103 ftp support(4 byte udirlist attr for ! UNX)          //~v59eI~
//v56s:020712 (UNX)allow to udirlist select non-reguler file       //~v56sI~
//v56g:020711 (UNX)ELOOP msg for lstat                             //~v56gI~
//v39X:010204 LINUX support:warning:missing function def           //~v39XI~
//v379:000930 LINUX support(4 byte attr)                           //~v379I~
//v366:000927 LINUX support(display operation on permission errmsg)//~v366I~
//v329 000827:LINUX:add msg permission err                         //~v329I~
//v276:990813 chk wild card before rename                          //~v276I~
//v195:980920 display attr/size on xdd list                        //~v195I~
//v161:980201 ufiledeleted,ufilereadonly2 =>ufemsg.h               //~v161I~
//v101:971009 long filename                                        //~v101I~
//            ufilevfat for DOS/W95                                //~v101I~
//v036:961016:new member for errmsg of ufile_.c
//v035:961016:_dos_open of ugetftime fail for dir,so use ufstat    //~v035I~
//            _dos_open of usetftime fail for dir,so chk it before open//~v035I~
//****************************************************************//~5909I~
int ufilenotfound(UCHAR *Pfname,int Prc);                       //~5909I~
//****************************************************************//~5909I~
int ufilepatherr(UCHAR *Ppathname,int Prc);                     //~5909I~
//****************************************************************//~5905M~
int ufileapierr(UCHAR *Papiname,UCHAR *Pfname,int Papirc);      //~5905M~
//**************************************************************** //~v6xbI~
int ufileapierr_str(UCHAR *Papiname,UCHAR *Pfname,int Perrno);     //~v6xbI~
//****************************************************************//~5B12I~
int ufiledelpath(UCHAR *Pfname,int Prc);                        //~5B12I~
//****************************************************************//~5910I~
int ufilereadonly(UCHAR *Pfname,int Prc);                       //~5910I~
//****************************************************************//~5910I~
int ufileshare(UCHAR *Pfname,int Prc);                          //~5910I~
//****************************************************************//~5910I~
int ufileexist(UCHAR *Pfname,int Prc);                          //~5910I~
//**************************************************************** //~v5cdI~
int ufileexistcopy(UCHAR *Pfname,int Prc);                         //~v5cdI~
//****************************************************************//~5A14I~
int ufileexist2(UCHAR *Pfname,UCHAR *Pdir,int Prc);             //~5A14I~
//**************************************************************** //~v5d3I~
int ufileexistdir(UCHAR *Pdir,int Prc);                            //~v5d3I~
//****************************************************************//~5910I~
int ufilenotdir(UCHAR *Pfname,int Prc);                         //~5910I~
//****************************************************************//~5910I~
int ufilediskfull(UCHAR *Pfname,int Prc);                       //~5910I~
//****************************************************************//~5B11I~
int ufilewildtarget(int Prc);                                   //~5B11R~
//**************************************************************** //~v276I~
int ufilewildcarderr(int Prc);                                     //~v276I~
//**************************************************************** //~v276I~
int ufilewildpatherr(int Prc);                                     //~v276I~
//****************************************************************//~5910I~
int ufileapierr2(UCHAR *Papiname,UCHAR *Pfname1,UCHAR *Pfname2,int Papirc);//~5910I~
//**************************************************************** //~v035I~
int ufiledirna(UCHAR *Pfname,UCHAR *Pfunc,int Prc);                //~v035I~
int ufileerrdir(UCHAR *Pfname,int Prc);                            //~v5kqI~
                                                                   //~v5cdI~
#ifdef OS2                                                         //~v101I~
#else                                                              //~v101I~
//**************************************************************** //~v101I~
int ufilenotvfat(void);                                            //~v101I~
#endif                                                             //~v101I~
                                                                   //~v161I~
//**************************************************************** //~v161I~
//void ufiledeleted(UCHAR *Pfname,UCHAR Pid);                      //~v195R~
                                                                   //~v379I~
//#ifdef UNX                                                       //~v59eR~
//void ufiledeleted(UCHAR *Pfname,UCHAR Pid,long Psize,ULONG Pattr);//~v5k0R~
void ufiledeleted(UCHAR *Pfname,UCHAR Pid,FILESZT Psize,ULONG Pattr);//~v5k0I~
//#else  //!UNX                                                    //~v59eR~
//void ufiledeleted(UCHAR *Pfname,UCHAR Pid,long Psize,UCHAR Pattr);//~v59eR~
//#endif //!UNX                                                    //~v59eR~
                                                                   //~v161I~
//**************************************************************** //~v161I~
void ufilereadonly2(UCHAR *Pfname,UCHAR Pid);                      //~v161I~
//#ifdef UNX                                                       //~v59eR~
//**************************************************************** //~v379M~
int ufilenopermission(UCHAR *Poperation,UCHAR *Pfnm,int Prc);      //~v366I~
//#ifdef UNX                                                       //~v5avR~
#ifdef FTPSUPP                                                     //~v5avI~
//**************************************************************** //~v56gR~
int ufileslinkloop(UCHAR *Poperation,UCHAR *Pfnm);                 //~v56gR~//~v6k8R~
//**************************************************************** //~v56sI~
int ufileerrspecialfile(UCHAR *Pfnm,int Prc);                      //~v56sI~
#endif                                                             //~v329I~
                                                                   //~v39XI~
//**************************************************************** //~v5kqI~
int ufileerrnotnormal(UCHAR *Pfnm,int Prc);                        //~v5kqI~
//**************************************************************** //~v39XI~
int ufileroot(char *Pfullpath,int Prc);                            //~v39XI~
//**************************************************************** //~v5d8I~
int ufileerrdir2file(int Prc);                                     //~v5d8I~
//**************************************************************** //~v5d9I~
int ufileerrnoentry(char *Pfnm,int Prc);                           //~v5d9I~
//**************************************************************** //~v62bI~
#ifdef UTF8SUPPH                                                   //~v62bI~
int ufileerrnofileentry(char *Pfnm,int Prc);                       //~v62bI~
#endif                                                             //~v62bI~
//**************************************************************** //~v5k0I~
char *ufileeditsz(int Popt,FILESZT Psz,char *Pout);                //~v5k0R~
#define  UFEFSZ_MINSZMASK  0xff  	//minimum output size          //~v5k0I~
#define  UFEFSZ_HEXLOWER   0x0100	//hex edit                     //~v5k0R~
#define  UFEFSZ_HEXUPPER   0x0200	//hex uppercase                //~v5k0R~
#define  UFEFSZ_STDFMT     0x0400	//output by printf fmt         //~v5k0I~
#define  UFEFSZ_FULLZ      0x0800	//"," insert full edit(no K/M set)//~v5k0I~
#define  UFEFSZ_NOTMINZ10  0x1000	//FULLZ minimun 10 digit out   //~v5k0R~
//**************************************************************** //~v6hLI~
int ufileTooLongFullpathName(int Prc);                             //~v6hLI~
int ufileTooLongFullpathName2(int Prc,char *Ppath,char *Pfnm);     //~v@99I~
//**************************************************************** //~v6k5I~
#if defined(W32)||defined(UNX)                                     //~va71I~//~v6k5I~
int ufileslinktargeterr(int Prc,char *Pslink,char *Ptarget);       //~v6k5I~
#endif                                                             //~v6k5I~
#if defined(W32)                                                   //~v6k8I~
int ufileslinkj2ferr(int Prc,char *Pslink,char *Ptarget);          //~v6k8I~
int ufileslinkd2ferr(int Prc,char *Pslink,char *Ptarget);          //~v6kgI~
#endif                                                             //~v6k8I~
int ufilenotfoundotherexist(char *Pfnm,int rc);                    //~v6kmI~
int ufileopenerrInvalidargument(int Popt,int Prc,char *Ppfile);    //~v6B7R~
int ufileErrInvalidName(int Prc,char *Ppfile);                     //+v6H9R~
