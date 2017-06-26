//CID://+v375R~:                                                   //+v375R~
//******************************************************           //~v327I~
//*ufile2l.h   UNIX version                                        //~v327I~
//******************************************************           //~v327I~
//v375:000929 LINUX support(umkdirmode optionaly returns resulted mode;umask value effest)//~v375I~
//**************************************************************** //~v327I~
int umkdirmode(UCHAR *Pdirname,ULONG Pmode,ULONG *Pprmode);        //~v375R~
//**************************************************************** //~v327I~
int uattrxon(UCHAR *Pfname);                                       //~v327I~
//**************************************************************** //~v327I~
int uattrxchk(UCHAR *Pfname,int Popt);                             //~v327I~
#define UAXC_MSG	 0x01                                          //~v327I~
//**************************************************************** //~v327I~
int usetftime2(UCHAR *Pfname,time_t Patime,time_t Pmtime);         //~v327I~
//**************************************************************** //~v327I~
int ufilesetugid(UCHAR *Psource,uid_t Puid,gid_t Pgid);            //~v327I~
//**************************************************************** //~v327I~
int ufilesetown(UCHAR *Psource,uid_t Puid,gid_t Pgid);             //~v327I~
//**************************************************************** //~v327I~
int ufilesetmod(UCHAR *Psource,mode_t Pmode);                      //~v327I~
