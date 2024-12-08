//CID://+v50PR~:                                                   //+v50PR~
//******************************************************           //~6A26I~
//*uunxsub.h                                                       //~v188R~
//******************************************************           //~6A26I~
//v50P:010908 gethostname function                                 //+v50PI~
//v39s:010107 LINUX support:lock file support for ::so             //~v39sI~
//v385:001001 LINUX support(add username/groupename search func)   //~v385I~
//v363:000927 LINUX support(term info by setupterm not scrinit/endwin)//~v363I~
//******************************************************           //~6A26I~
//*******************************************************          //~v159I~
void ugetugid(uid_t *Ppuid,gid_t *Ppgid);                          //~v188I~
//*******************************************************          //~v363I~
char *ugetusername(uid_t Puid);                                    //~v385I~
//*******************************************************          //~v385I~
char *ugetgroupname(gid_t Pgid);                                   //~v385I~
//*******************************************************          //~v385I~
int unc_setupterm(int Popt);                                       //~v363I~
//*******************************************************          //~v39sI~
int unx_fsetlock(char *Pfnm);                                      //~v39sI~
//*******************************************************          //~v39sI~
int unx_fresetlock(char *Pfnm);                                    //~v39sI~
//*******************************************************          //~v39sI~
int unx_fchklock(char *Pfnm);                                      //~v39sR~
//*******************************************************          //+v50PI~
int ugethostname(char *Phnm,int len);                              //+v50PI~
