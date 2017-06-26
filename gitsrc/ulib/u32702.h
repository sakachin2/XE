//*CID://+v5mBR~:                             update#=  353;       //+v5mBR~
//******************************************************           //~v5jdI~
//*u32702.h                                                        //~v5jdI~
//******************************************************           //~v5jdI~
//v5mB:080621 3270:DBCS conversion support                         //+v5mBI~
//v5jy:061123 3270:SPF information update                          //~v5jyI~
//v5jd:061002 3270 support:rename/delete                           //~v5jdI~
//******************************************************           //~v5jdI~
#ifdef FTPSUPP                                                     //~v5jdI~
//******************************************************           //~v5jdI~
typedef int (TSO_WILDAPPLYFUNC)(PUFTPHOST,UCHAR *,PUDIRLIST,void*);//~v5jdR~
//******************************************************           //~v5jdI~
int u3270mkdir(PUFTPHOST Ppuftph,UCHAR *Pdirname,ULONG Pmode,ULONG *Pprmode);//~v5jdI~
//******************************************************           //~v5jdI~
int u3270rmdir(PUFTPHOST Ppuftph,UCHAR *Pdirname);                 //~v5jdI~
//******************************************************           //~v5jdI~
int u3270remove(PUFTPHOST Ppuftph,int Popt,UCHAR *Pfilename);      //~v5jdI~
//******************************************************           //~v5jdI~
int u3270rename(PUFTPHOST Ppuftph,int Popt,UCHAR *Poldname,UCHAR *Pnewname,UCHAR *Pnewspec);//~v5jdI~
//******************************************************           //~v5jdI~
int u3270attrib(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Pattron,ULONG  Pattroff,ULONG  *Poutattr);//~v5jdI~
//******************************************************           //~v5jdI~
int u3270attrxchk(PUFTPHOST Ppuftph,UCHAR *Pfname,int Popt);       //~v5jdI~
//******************************************************           //~v5jdI~
int u3270getftime(PUFTPHOST Ppuftph,UCHAR *Pfname,FDATE *Ppdate,FTIME *Pptime);//~v5jdI~
//******************************************************           //~v5jdI~
int u3270setftime(PUFTPHOST Ppuftph,UCHAR *Pfname,FDATE Pdate,FTIME Ptime);//~v5jdI~
//******************************************************           //~v5jdI~
int u3270setftime2(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Patime,ULONG Pmtime);//~v5jdI~
//******************************************************           //~v5jdI~
int u3270copypathinfo(PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,UCHAR *Psource,UCHAR *Ptarget);//~v5jdI~
//******************************************************           //~v5jdI~
int u3270setown(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Puid,ULONG Pgid);//~v5jdI~
//******************************************************           //~v5jdI~
int u3270setmod(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Pmode);      //~v5jdI~
//******************************************************           //~v5jdI~
int u3270xdelete(PUFTPHOST Ppuftph,UCHAR *Pfile,int Popt,          //~v5jdI~
            int *Ppprocctr,int *Ppronlyctr,int *Ppdelctr);         //~v5jdI~
//******************************************************           //~v5jdI~
int u3270xddsub(PUFTPHOST Ppuftph,int Pxdelopt,int Pxddopt,char *Pfullpath);//~v5jdI~
//******************************************************           //~v5jdI~
int u3270wildfunc(PUFTPHOST Ppuftph,UCHAR *Psource,                //~v5jdM~
                TSO_WILDAPPLYFUNC *Pfunc,void *Pparm,int *Pfilectr,PUDIRLIST *Pppudl);//~v5jdR~
//******************************************************           //~v5jdI~
int u3270xcopy(int Popt,PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask);//~v5jdI~
//******************************************************           //~v5jdI~
int u3270xmove(int Popt,PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask);//~v5jdI~
//******************************************************           //~v5jdI~
int u3270transfer(int Popt,PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,  //~v5jdI~
//  		UCHAR *Psource,UCHAR *Ptarget);                        //+v5mBR~
    		UCHAR *Psource,UCHAR *Ptarget,PUTSOFTPPARM Pptsop);    //+v5mBI~
//******************************************************           //~v5jdI~
int u3270spfupdate(int Popt,PUFTPHOST Ppuftph,char *Pfpath,PPDSSPFINFO Ppspfi,PPDSSPFINFO Ppspfinew);//~v5jyR~
#define U3270SPFO_VER       0x01     // version update             //~v5jyR~
#define U3270SPFO_MOD       0x02     // mod lvl update             //~v5jyR~
#define U3270SPFO_CDATE     0x04     // creation date              //~v5jyR~
#define U3270SPFO_UPDATE    0x08     // update date/time           //~v5jyR~
#define U3270SPFO_CLINE     0x10     // current line               //~v5jyR~
#define U3270SPFO_ILINE     0x20     // initial line               //~v5jyI~
#define U3270SPFO_USERID    0x40     // userid                     //~v5jyR~
#define U3270SPFO_NOWMOD    0x0200   // set CDATE to today         //~v5jyR~
#define U3270SPFO_NOWCDATE  0x0400   // set CDATE to today         //~v5jyR~
#define U3270SPFO_NOWUPDATE 0x0800   // set UPDATE to current day/time//~v5jyR~
#define U3270SPFO_NOWCLINE  0x1000   // count current line reading member//~v5jyI~
#define U3270SPFO_NOWILINE  0x2000   // count current line reading member//~v5jyI~
#define U3270SPFNOW   "NOW"          // parm to set current status //~v5jyR~
                                                                   //~v5jyI~
#endif                                                             //~v5jdI~
