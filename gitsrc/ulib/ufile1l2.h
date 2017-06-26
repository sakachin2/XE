//*CID://+v6hdR~:                             update#=   21;       //+v6hdR~
//******************************************************           //~v327I~
//v6hd:120616 for VC6:/W4 warning(C4115)                           //+v6hdI~
//v563:020702 (AIX)filename set to notsupported msg                //~v563I~
//v55n:020503 (AIX)disket support                                  //~v55nI~
//v55f:020429 (UNX)mcd(cd for mdos disk) support                   //~v55fI~
//v558:020427 (UNX:BUG)mtools may write err msg(not found etc) to stdout(for ex mdir)//~v538I~
//v538:020322 (LNX)mdos disk support;mkdir rmdir;attrib            //~v538I~
//v50G:010618 LNX:disket support(using mtools)                     //~v50GI~
//******************************************************           //~v327I~
unsigned int ufstat_mdos(char *Ppfile,FILEFINDBUF3 *Ppffb3);       //~v50GI~
                                                                   //~v50GI~
//******************************************************           //~v55fI~
int uchdir_mdos(UCHAR *Pfnm);                                      //~v55fI~
                                                                   //~v55fI~
//******************************************************           //~v50GI~
unsigned uopendir_mdos(char *Ppfname,PUDIRLIST *Pppudl);           //~v55nR~
                                                                   //~v55fI~
//******************************************************           //~v50GI~
unsigned ureaddir_mdos(PUDIRLIST *Pppudl,char *Ppath,int Ppathlen,ULONG Pattr,//~v55nR~
							FILEFINDBUF3 *Ppfstat3);               //~v50GI~
//******************************************************           //~v50GI~
int ugetcwd_mdos(UCHAR *Pfnm);                                     //~v50GR~
                                                                   //~v538I~
//******************************************************           //~v50GI~
#ifdef UNX                                                         //+v6hdR~
int ustatfs_mdos(UCHAR *Pfnm,struct statfs *Ppsfs);                //~v50GI~
#endif                                                             //+v6hdR~
//******************************************************           //~v538I~
int ufilemdoscmd(int Popt,char *Pcmd,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr);//~v538I~
//do not use 0x4000:UPROC_NOOKMSG and 0x2000:UPROC_NOMSG           //~v538I~
#define MDCO_CHKSTDO   0x0001 //chk also stdout                    //~v538I~
#define MDCO_NOMSG     0x0002 //no errmsg                          //~v55nI~
                                                                   //~v55nI~
//******************************************************           //~v55nI~
int ufileerrmdosnotsupported(char *Pcmd,char *Pfnm);               //~v563R~
