//*CID://+v6BxR~:                             update#=   16;       //~v6BxR~
//******************************************************           //~v053I~
//*ugcclib.h function lack from libc                               //~v134R~
//*************************************************************    //~v053I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v56x:020805 (BUG)editfilename DBCS support                       //~v56xI~
//v50z:010521 LINUX support:support getch                          //~v50zI~
//v402:001027 AIX support:some func in ugcclib not required        //~v402I~
//*************************************************************    //~v352I~
#ifdef LNX                                                         //~v402R~
//int memicmp(void *Psrc1,void *Psrc2,unsigned int Plen);            //~v053R~//~v6BxR~
int memicmp(void *Psrc1,void *Psrc2,size_t Plen);                  //+v6BxR~
//*************************************************************    //~v134I~
#ifndef MGW32                                                      //~v5ncM~
    #ifdef ARM                                                     //~v6a0I~
int stricmp(const char *Psrc1,const char *Psrc2);                  //~v6a0R~
    #else                                                          //~v6a0I~
int stricmp(void *Psrc1,void *Psrc2);                              //~v134R~
    #endif                                                         //~v6a0I~
#endif   //MINGW                                                   //~v5ncI~
//*************************************************************    //~v134I~
char *strupr(char *Pstr);                                          //~0903I~
//*************************************************************    //~0923I~
char *strlwr(char *Pstr);                                          //~0923I~
//*************************************************************    //~0903I~
char *itoa(int Pvalue,char *Pstring,int Pradix);                   //~v134I~
//******************************************************           //~v134I~
int  getche(void);                                                 //~v134I~
//******************************************************           //~v50zI~
#endif                                                             //~v50zI~
#ifdef AIX                                                         //~v56xI~
int  getche(void);                                                 //~v56xI~
#endif                                                             //~v56xI~
#ifdef UNX                                                         //~v50zI~
int  getch_nc(void);                                               //~v50zR~
//******************************************************           //~v50zI~
int  kbhit(void);                                                  //~v50zI~
#endif                                                             //~v402M~
#ifndef MGW32                                                      //~v5ncI~
//**************************************************************** //~0902I~
int spawnv(int Pmodeflag,char *Ppathname,char *Pargv[]);           //~0902R~
#define P_WAIT 		0                                              //~0902I~
#define P_NOWAIT	1                                              //~0902I~
#define P_OVERLAY	2    //not support now                         //~0902I~
#define P_NOWAITO	3    //not support now                         //~0902I~
#define P_DETACH	4    //not support now                         //~0902I~
//**************************************************************** //~0902I~
int spawnvp(int Pmodeflag,char *Ppathname,char *Pargv[]);          //~0902R~
#endif   //MGW32                                                   //~v5ncR~
