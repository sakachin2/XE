//*CID://+v6H7R~:                             update#=   60;       //~v6H7R~
//******************************************************        //~5826I~
//*ufile2.h                                                     //~5826I~
//******************************************************        //~5826I~
//v6H7:170108 FTP crush by long name                               //~v6H7I~
//v6H1:161231 filename >_MAX_PATH occurse when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v6H1I~
//            and it cause fpath area overflow then 0c4            //~v6H1I~
//v6G7:161219 xdd:quiet option(-q[n], one msg for each n deletion) //~v6G7I~
//v6B1:160114 trace,mtrace file no share mode                      //~v6B1I~
//v6q1:131128 (WIN)for wildname dir,use alias to get dirlist       //~v6q1I~
//v6q0:131126 (WIN)fails to delete wildcard entry;use shortname    //~v6huI~
//v6hu:120807 (WIN)display odd number file time stamp for xdc/xts for also Win//~v6huI~
//v6ht:120729 (LNX)display odd number file time stamp              //~v6htI~
//v6dj:120323 (BUG of ftp)xdd did not delete subdir                //~v6djI~
//v6b1:110705 try list wildcard membername                         //~v6b1I~
//v5fb:050101 avoid duplicated ronly chk of del for ftp del performance//~v5fbI~
//v5am:040110 (FTP)del file in a dir at once for performance       //~v5amI~
//v59q:031124 (UNX)xdd protection for dir/file owned by root group user//~v59pI~
//v59e:031103 ftp support(4 byte udirlist attr for ! UNX)          //~v59eI~
//v56s:020712 (UNX)allow to udirlist select non-reguler file       //~v56sI~
//v55r:020525 (UNX)no fd option for xdd cmd                        //~v55rI~
//v55d:020428 (UNX:BUG)not found msg when diskfull for move(target is not created yet)//~v55dI~
//v520:011228 support move override                                //~v520I~
//v327 000820:LINUX support                                        //~v327I~
//v281:990911 xdd confirm each support                             //~v281I~
//v277:990813 rename:wildcard target support                       //~v277I~
//v011:960131:add xdd function(parm chk,call xdelete and issue msg)//~v011I~
//v010:960120:uxdelete,read only chk option,force del  read only option//~v010I~
//******************************************************        //~v010I~
typedef int (WILDAPPLYFUNC)(UCHAR *,PUDIRLIST,void*);           //~5916R~
typedef int (WCWCFUNC)(UCHAR *,UCHAR *,PUDIRLIST,void *);          //~v6q0R~
typedef struct _WCPARMWC  {                                        //~v6q0R~
                            int wcopt;                             //~v6q0R~
#define WCWCO_MSG      0x01		//print all wild member            //~v6q0R~
#define WCWCO_FILEMASK 0x02		//filmask parm specified           //~v6q0R~
#define WCWCO_DEPTH    0x04		//depth parm specified             //~v6q0R~
#define WCWCO_XFF      0x08		//msg by xff format                //~v6q0R~
#define WCWCO_DIGBYALIAS 0x10		//dig by alias for wildname directory//~v6q1R~
							WCWCFUNC *wcpfunc;                     //~v6q0R~
                            int wcdepth;                           //~v6q0R~
                            int wcchkctr;	//checked ctr          //~v6q0R~
                            int wcctr;      //wildcard ctr         //~v6q0R~
                            char wcfilemask[_MAX_PATH];            //~v6q0R~
                            char wcfnm[_MAX_PATH];                 //~v6q0R~
                          } WCPARMWC,*PWCPARMWC;                   //~v6q0R~
//******************************************************        //~5826I~
//****************************************************************//~5909I~
int umkdir(UCHAR *Pdirname);                                    //~5909I~
#ifdef FTPSUPP                                                     //~v59pI~
	#ifndef UNX		//for unit see ufile2l.h                       //~v59pI~
		int umkdirmode(UCHAR *Pdirname,ULONG Pmode,ULONG *Pprmode);//~v59pI~
		int uattrxon(UCHAR *Pfname);                               //~v59pI~
		int uattrxchk(UCHAR *Pfname,int Popt);                     //~v59pI~
    #endif                                                         //~v59pI~
#endif                                                             //~v59pI~
                                                                //~5909I~
//****************************************************************//~5909I~
int urmdir(UCHAR *Pdirname);                                    //~5909I~
                                                                //~5909I~
//******************************************************************//~v011I~
char *uxddpchk(char *Ppgmver,int Pparmc,char *Pparm,            //~v011R~
                int *Pxdelopt,int *Pxddopt,int *Pposparmno);    //~v011R~
                                                                //~v011I~
//******************************************************************//~v011I~
int uxddsub(char *Pname,int Pxdelopt,int Pxddopt,char *Pfullpath);//~v011R~
#define UXDDNOCONF  0x01        //not no confirm for xddopt     //~v011I~
#define UXDDENGLISH 0x02        //force english                    //~v281I~
                                                                //~v011I~
//****************************************************************//~5B12I~
int uxdelete(UCHAR *Pfile,unsigned Pattrmask,int Popt,          //~v010I~
            int *Ppprocctr,int *Ppronlyctr,int *Ppdelctr);      //~v010I~
#ifdef UNX                                                         //~v56sI~
#define UXDELDIR   (((unsigned)-1)-FILE_MDOSDISK-FILE_SPECIAL)   //for Pattrmask//~v56sI~
#else                                                              //~v56sI~
#define UXDELDIR   ((unsigned)-1)   //for Pattrmask             //~6121R~
#endif                                                             //~v56sI~
                                                                   //~v55dI~
#define UXDELNOMSG      0x00        //for Popt,no deleate/read only msg//~v010R~
#define UXDELMSG        0x01        //for Popt,deleate/read only msg//~v010R~
#define UXDELRONLYCHK   0x02        //for Popt,read only check only//~v010R~
#define UXDELFORCE      0x04        //for Popt,continue proces even if ronly//~v010R~
#define UXDELSKIPRONLY  0x08        //for Popt,skip ronly file delete//~v010I~
#define UXDELCONFEACH   0x10        //for Popt,confirm each member of top level//~v281I~
#define UXDELNONOTFMSG  0x20        //for Popt,bypass source file not found msg//~v55dI~
#ifdef UNX                                                         //~v55rI~
#define UXDELNOTFD      0x40        //no floppy support            //~v55rI~
#define UXDELFORCEROOT  0x80        //force delete object of root user grp//~v59pI~
#endif                                                             //~v55rI~
#define UXDELRONLYCHKOK 0x0100      //ronly chk done for no delforce nand skipronly//~v5fbI~
                                                                   //~v6b1R~
#ifdef UNX                                                         //~v6b1R~
#define UXDELWILDNAME     0x0200      //name is not wildcard but, use in xe//~v6b1R~
#define UXDELWILDMULTIPLE 0x0400      //multiple wildname         use in xe//~v6b1R~
#define UXDELUNDELCOPY    0x0800      //wildname chk at ronlychk   //~v6b1I~
#endif                                                             //~v6b1R~
                                                                   //~v6G7I~
#define UXDELQUIET        0x1000      //quiet(no deleted msg)      //~v6G7R~
                                                                   //~v6H7I~
#define UXDELRC_FTP_RMDIR_FAILED  4097   //FTP rmdir Failed        //~v6H7I~
                                                                //~5B12I~
//****************************************************************//~5826I~
int uremovenomsg(UCHAR *Pfilename);                                //~v5amI~
//**************************************************************** //~v5amI~
int uremove(UCHAR *Pfilename);                                  //~5826I~
//**************************************************************** //+v6H7I~
#ifdef W32                                                         //+v6H7I~
int uremoveWLong(int Popt,UCHAR *Pfilename);                       //~v6H9I~//+v6H7M~
#define       URWLO_NOMSG        0x01                              //~v6H9I~//+v6H7M~
#endif                                                             //+v6H7I~
//****************************************************************//~5826I~
int urename(UCHAR *Poldname,UCHAR *Pnewname,UCHAR *Pnewspec);      //~v277I~
//**************************************************************** //~v520I~
int urename2(UCHAR *Poldname,UCHAR *Pnewname,UCHAR *Pnewspec);     //~v520I~
//**************************************************************** //~v6huI~
int ftime2sec(FILETIME *Pft,LONG *Pout);                           //~v6huI~
//****************************************************************//~5910I~
int ugetftime(UCHAR *Pfname,FDATE *Ppdate,FTIME *Pptime);       //~5910I~
//**************************************************************** //~v6htI~
int ugetftime_1sec(UCHAR *Pfname,FDATE *Ppdate,FTIME *Pptime,int *Ppoddsec);//~v6htI~//~v6huR~
//****************************************************************//~5910I~
int usetftime(UCHAR *Pfname,FDATE Pdate,FTIME Ptime);           //~5910I~
//****************************************************************//~5910I~
int usetftime_1sec(UCHAR *Pfname,FDATE Pdate,FTIME Ptime,int Poddsec);//~v6htI~//~v6huR~
//**************************************************************** //~v6htI~
int ucopypathinfo(UCHAR *Psource,UCHAR *Ptarget);               //~5910R~
//****************************************************************//~5903I~
//#ifdef UNX                                                       //~v59eR~
int uattrib(UCHAR *Pfname,ULONG Pattron,ULONG Pattroff,ULONG *Poutattr);//~v327M~
//#else                                                            //~v59eR~
//int uattrib(UCHAR *Pfname,UCHAR Pattron,UCHAR Pattroff,UCHAR *Poutattr);//~v59eR~
//#endif                                                           //~v59eR~
//****************************************************************//~5916I~
int uwildfunc(int Popt,UCHAR *Psource,unsigned Pattrmask,       //~5916I~
                WILDAPPLYFUNC *Pfunc,void *Pparm,int *Pfilectr);//~5916R~
#define UWFO_EADATA   0x01           //force delete "EA DAAT.SF"   //~v6q0R~
#define UWFO_RENAME     0x02         //accept rename wildname      //~v6q0R~
#define UWFO_DELETE     0x04         //accept delete wildname      //~v6q0R~
#define UWFO_LONGWILD   0x08         //accept delete wildname      //~v6H1I~
                                                                   //~v6q0R~
#define UWFRC_WILDNAME  0x11         //stop by wildname            //~v6huI~
#define UWFRC_LONGNAME    0x0100        //over _MAX_PATH           //~v6H1I~
#define UWFRC_LONGNAMEERR 0x0200        //over _MAX_PATH,could not delete//~v6H1I~
//****************************************************************//~5B12I~
int ufilecdirchk(UCHAR *Pfullpath);                             //~5B12I~
//****************************************************************//~5B12I~
int ufiledelpath(UCHAR *Pfname,int Prc);                        //~5B12I~
//****************************************************************//~5910I~
int ufilereadonly(UCHAR *Pfname,int Prc);                       //~5910I~
//****************************************************************//~5910I~
int ufileshare(UCHAR *Pfname,int Prc);                          //~5910I~
//****************************************************************//~5910I~
int ufileexist(UCHAR *Pfname,int Prc);                          //~5910I~
//****************************************************************//~5A14I~
int ufileexist2(UCHAR *Pfname,UCHAR *Pdir,int Prc);             //~5A14I~
//****************************************************************//~5910I~
int ufilenotdir(UCHAR *Pfname,int Prc);                         //~5910I~
//****************************************************************//~5910I~
int ufilediskfull(UCHAR *Pfname,int Prc);                       //~5910I~
//****************************************************************//~5B11I~
int ufilewildtarget(int Prc);                                   //~5B11R~
//**************************************************************** //~v327I~
int ufilespfnchk(UCHAR *Pfname,int Pop);    //if special file      //~v327M~
//**************************************************************** //~v6djI~
int uxdelsub(UCHAR *Pfile,ULONG Pattr,unsigned Pattrmask,int Pdeldirsw,FILESZT Psize);//~v6djI~
//**************************************************************** //~v6huI~
int ufilechkwildmemb(char *Pfnm,PWCPARMWC Ppuparm);                //~v6q0R~
//**************************************************************** //~v6B1I~
int ufiledelifnotopened(int Popt,char *Pfnm,int Ppid);             //~v6B1R~
//**************************************************************** //~v6B1I~
#ifdef W32                                                         //~v6B1I~
FILE *ufileopenexclusivewrite(int Popt,char *Pfnm,HANDLE *Phandle);//~v6B1R~
#else                                                              //~v6B1I~
FILE *ufileopenexclusivewrite(int Popt,char *Pfnm,int *Phandle);   //~v6B1R~
#endif                                                             //~v6B1I~
//**************************************************************** //~v6H7I~
void ufile3xdeleteinit(UCHAR *Pfile,unsigned Pattrmask,int Popt,int *Ppprocctr,int *Ppronlyctr,int *Ppdeldctr,int *Pplongnamectr,FILESZT *Ppdelsize);//~v6H7R~
//**************************************************************** //~v6H7I~
int uxdelsubftp(UCHAR *Pfile,ULONG Pattr,unsigned Pattrmask,int Pdeldirsw,FILESZT Psize);//~v6H7I~
