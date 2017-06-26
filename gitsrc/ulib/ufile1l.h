//CID://+v6B8R~:        update#=     12                            //~v6B8R~
//******************************************************           //~v327I~
//*ufilel.h   UNIX version                                         //~v327I~
//******************************************************           //~v327I~
//v6B8:160121 add function to check iocharset mount option         //~v6B8I~
//v6yd:150314 ino_t is not 32 bit                                  //~v6ydI~
//v6uV:140608 support isvfat,isntfs for LNX                        //~v6uVI~
//v6hd:120616 for VC6:/W4 warning(C4115)                           //~v6bdI~
//v6b1:110705 try list wildcard membername                         //~v6b1I~
//v5fu:050322 dispaly filetime when copy bypass by /d option       //~v5fuI~
//v56n:020711 (UNX:BUG) xff loop by FIFO file.it is slink,so not chked.//~v56nI~
//v50G:010618 LNX:disket support(using mtools)                     //~v50GI~
//v364:000927 LINUX support(file system chk)                       //~v364I~
//******************************************************           //~v327I~
//**************************************************************** //~v327I~
ULONG ufilemode2attr(FILEFINDBUF3 *Ppft);                          //~v327R~
//**************************************************************** //~v327I~
time_t ufilemktime(FDATE Pfd,FTIME Pft);                           //~v327R~
//**************************************************************** //~v364I~
int ufilefscomp(char *Pfile1,char *Pfile2);                        //~v364R~
//**************************************************************** //~v364I~
int ufilegetfsid(char *Pfile);                                     //~v364I~
//**************************************************************** //~v50GM~
//int ufilelnxattrselect(ULONG Pfattr,ULONG Ppattr);               //~v56nR~
int ufilelnxattrselect(ULONG Pfattr,ULONG Pfattrsrc,ULONG Ppattr); //~v56nI~
//**************************************************************** //~v5fuI~
void ufilegetftime(FTIME* Pft,FDATE *Pfd,time_t Ptime_t);          //~v5fuI~
//**************************************************************** //~v6b1I~
unsigned int ufstat_wild(char *Ppfile,FILEFINDBUF3 *Ppffb3);       //~v6b1I~
//**************************************************************** //~v6b1I~
//int ufilerepwildname(int Popt,char *Pwildname,int Pinode);       //~v6ydR~
int ufilerepwildname(int Popt,char *Pwildname,ULONG Pinode);       //~v6ydI~
//**************************************************************** //~v6b1I~
#ifdef UNX                                                         //~v6bdI~
int ufilechkwildmultiple(int Popt,char *Pfnm,struct dirent *Ppde,FILEFINDBUF3 *Ppffb3);//~v6b1R~//~v6bdR~
#endif                                                             //~v6bdI~
//**************************************************************** //~v6b1I~
int errwildname(int Popt,char *Pmember,char *Ppath);               //~v6b1I~
#define EWN_COPYSRC    0x01  //xcopy cmd source is wildname        //~v6b1R~
#define EWN_RENAME     0x02  //xcopy cmd source was renamed        //~v6b1R~
//**************************************************************** //~v6uVI~
int filesrchmountpoint(char *Pfilename,void *Pmnt/*ptr to Pbuff*/,char *Pbuff,int Pbuffsz);//~v6uVR~
//**************************************************************** //~v6B8I~
int ufilegetiocharset(int Popt,char *Pfpath,dev_t Pdevt,char *Ppiocharset,int Poutbuffsz);//~v6B8R~
#define UFGDO_NEWFILE    0x01    //already stat get rc=2           //~v6B8R~
#define UFGDO_ROOT       0x02    //parent path is root dir         //~v6B8I~
#define UFGDO_DEFAULT_CS  "utf8"                                   //+v6B8I~
