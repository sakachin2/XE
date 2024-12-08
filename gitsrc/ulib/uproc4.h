//*CID://+v6D5R~:                             update#=  151;       //~v6D5R~
//*************************************************************
//*proc4.h
//*************************************************************
//v6D5:160430 LNX compiler warning for FD_SET/FD_ISSET             //~v6D5I~
//v5nd:081009 (SYNH) external process ctl
//*************************************************************
#define SH_MAX_RESPMSG           512                               //~v5ndI~
//*************************************************************
int uproc_shcmd(int Popt,char *Pcmd,char *Prespbuff,int Prespbuffsz);//~v5ndI~
#define  UPSPO_ALIVECHK 0x01         //check server is active before read response to protect read wait//~v5ndI~
#define  UPSPRC_WRTERR  -1           //write err                   //~v5ndR~
#define  UPSPRC_PSTOP   -2           //process stopped(result of ALIVECHK)//~v5ndI~
#define  UPSPRC_EXIT    -3           //response by server atexit   //~v5ndI~
//*************************************************************
#ifdef SYNSUPP                                                     //~v5ndI~
int uproc_shserverinit(int Popt,CMDSVRCALLBACK *Pcmdsvrcallback,char *Pserverpgm,int *Pppid,int *Ppfpipew,int *Ppfdpiper);
#endif                                                             //~v5ndI~
//*************************************************************
int uproc_shserverterm(int Popt,int Ppid,int Pfdw,int Pfdr);
//*************************************************************    //~v5ndI~
int uproc_srchprocessw(int Popt,int Ppid,char *Pexename,int *Pppid,int Pwaittime);//~v5ndR~
//*************************************************************    //~v5ndI~
int uproc_srchprocess(int Popt,int Ppid,char *Pexename,int *Pppid);//~v5ndI~
#define  UPSPO_BYNAME   0x08                                       //~v5ndI~
#define  UPSPO_BYPID    0x10                                       //~v5ndI~
//*************************************************************    //~v5ndI~
#ifdef UNX                                                         //~v5ndI~
int uproc_select(int Popt,int Prfd,int Pwfd,int Pefd,int Pmilisec,int Pchildpid);//~v5ndR~
//*************************************************************    //~v6D5I~
#define UFD_SET(fd,pfd_set) uproc4_fdset(fd,pfd_set)               //~v6D5I~
void uproc4_fdset(int Pfd,fd_set *Ppfd_set);                       //~v6D5R~
//*************************************************************    //~v6D5I~
#define UFD_ISSET(fd,pfd_set) uproc4_fdisset(fd,pfd_set)           //~v6D5I~
int uproc4_fdisset(int Pfd,fd_set *Ppfd_set);                      //+v6D5R~
#endif                                                             //~v5ndI~
