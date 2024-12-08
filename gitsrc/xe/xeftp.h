//*CID://+vb7eR~:                             update#=   30;       //~vb7eR~
//**************************************************************** //~v0fqI~
//xeftp.h                                                          //~v53UR~
//**************************************************************** //~v0fqI~
//vb7e:170108 FTP crash by longname                                //~vb7eI~
//vane:131208 clear crypt pswd for inserted line to avoid copy line(But,effective only for update)//~vaneI~
//vac0:120131 (SMB)node cmd to set volatile password to UFTPHOST   //~vac0I~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v76p:070628 compare remote file support                          //~v76pI~
//v72n:061127 3270:spf cmd to update spf info                      //~v72nI~
//v710:060916 (BUG)tmp file remains in xeftpwd by save cmd with remotefile operand.//~v710I~
//v70z:060904 3270 ftp support                                     //~v70zI~
//v64a:050618 (LNX)xxe support                                     //~v64aI~
//v63j:050507 (WXE)dragdrop remote file support                    //~v63jI~
//v62h:050316 ftp undel support                                    //~v62hI~
//v59d:041107 rsh:log also shell script itself                     //~v59dI~
//v57K:040619 (FTP:BUG)append cmd dose not append but copy only    //~v57KI~
//v57s:040530 (FTP)xpr dcmd support                                //~v57sI~
//v576:040513 (FTP:BUG)if u edit same filename except case,        //~v576I~
//            another file name is  save back to remote.so use tempdir//~v576I~
//v54x:040115 no deelte tempwd option for test                     //~v54xI~
//v54p:040106 (FTP)uftpisremote interface changed                  //~v54pI~
//v54n:040105 (FTP)support hosts filename /f                       //~v54nI~
//v53U:031109 (WIN,UNX)ftp support                                 //~v53UI~
//**************************************************************** //~v0fqI~
#ifdef  XEFTP_GLOBAL                                               //~vaneI~
  char *Gxehostsfnm;                                               //~vaneI~
#else                                                              //~vaneI~
  extern char *Gxehostsfnm;                                        //~vaneI~
#endif                                                             //~vaneI~
#ifdef FTPSUPP      //************************                     //~v54xI~
                                                                   //~v54xI~
#define  FTPHOSTS           "::xehosts"   //ftp hosts              //~v53UI~
#define  FTPLOG             "::xeftplog"  //ftp log file           //~v53UI~
#define  FTPWKDIR           "::xeftpwd"   //ftp log file           //~v53UI~
#define  FTPDNDWKDIR        "::xeftpdnd"  //remote file dragdrop work//~v63jI~
//**************************************************************** //~v53UI~
int xeftphostsget(PUCLIENTWE Ppcw,PUFILEH Ppfh);                   //~v53UR~
//**************************************************************** //~v53UI~
int xeftpipachk(char *Pipa,ULONG *Pxips);                          //~v53UR~
//**************************************************************** //~v53UI~
int xeftpinit(int Popt,char *Phostsfnm);                           //~v54nI~
#define XEFTP_NOUSE    0x01     //no use ftp func                  //~v53UR~
#define XEFTP_LOG      0x02     //log write                        //~v53UR~
#define XEFTP_APPEND   0x04     //append mode log                  //~v53UR~
#define XEFTP_TEST     0x08     //test option                      //~v54xI~
//**************************************************************** //~v53UI~
int xeftpterm(void);                                               //~v53UI~
//**************************************************************** //~v53UI~
//int xeftpget(PUFTPHOST Ppuftph,char *Prfname);                   //~v576R~
//int xeftpget(PUFTPHOST Ppuftph,char *Prfname,char *Ptmplocalfnm);//~v70zR~
//int xeftpget(int Popt,PUFTPHOST Ppuftph,char *Prfname,char *Ptmplocalfnm);//~v8@sR~
int xeftpget(int Popt,PUFTPHOST Ppuftph,char *Prfname,char *Ptmplocalfnm,/*PUTSOFTPPARM*/ void *Pptsop);//~v8@sI~
#define XEFTPO_BIN      0x010000   //bin transfer                  //~v70zR~
#define XEFTPO_2TEMPF   0x020000   //get to local temp file        //+vb7eI~
//**************************************************************** //~v53UI~
//int xeftpgetwdfname(char *Pfname,char *Pwdfname);                //~v70zR~
//int xeftpgetwdfname(PUFTPHOST Ppuftph,char *Pfname,char *Pwdfname);//~v70zI~//~vb7eR~
int xeftpgetwdfname(PUFTPHOST Ppuftph,char *Pfname,char *Pwdfname,size_t Pbuffsz);//~vb7eR~
//**************************************************************** //~v76pI~
//int xeftpgetwdfname2(int Popt,char *Pfname,char *Pwdfname);        //~v76pI~//~vb7eR~
int xeftpgetwdfname2(int Popt,char *Pfname,char *Pwdfname,size_t Pbuffsz);//~vb7eI~
//**************************************************************** //~v53UI~
int xeftpsave(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);              //~v53UI~
#define XEFTPSO_UPDATECHKONLY   0x01      //chk updated befor save //~v53UR~
#define XEFTPSO_UPDATEFDATE     0x02      //update file time stamp //~v53UI~
#define XEFTPSO_APPEND          0x04      //append to remote file  //~v57KI~
#define XEFTPSO_DELTEMP         0x08      //delete temp local file //~v710I~
#define XEFTPSO_OUTFILE         0x10      //write to other file    //~v72nI~
#define XEFTPSO_OUTPARTIAL      0x20      //partial output bt cre/rep/app cmd//~v72nI~
                                                                   //~v72nI~
                                                                   //~v54xI~
int xeftpdelwd(int Popt,char *Pwdfname);                           //~v576R~
//int xeftpgetremotecopy(int Popt,char *Ppfile,PUFTPHOST Ppuftph,char *Pouttmpf);//~v8@sR~
//int xeftpgetremotecopy(int Popt,char *Ppfile,PUFTPHOST Ppuftph,char *Pouttmpf,void *Pparm);//~v8@sR~//~vb7eR~
int xeftpgetremotecopy(int Popt,char *Ppfile,PUFTPHOST Ppuftph,char *Pouttmpf,size_t Pbuffsz,void *Pparm);//~vb7eI~
#define XEFTP_GRC_DEFDIR     0x01    //copy into default dir       //~v57sI~
#define XEFTP_GRC_PARMFILE   0x02    //copy to parm file           //~v57sI~
#define XEFTP_GRC_PARMDIR    0x04    //copy to into parm dir       //~v57sI~
#define XEFTP_GRC_SUBDIR     0x08    //copy dir                    //~v57sI~
#define XEFTP_GRC_SUBDIRCOPY 0x10    //copy subdir                 //~v63jI~
#define XEFTP_GRC_DEFDIR2    0x20    //copy into default dir with fullpath tempname//~v76pI~
#define XEFTP_GRC_CHKNORMAL  0x40    //confirm remote is reguler file before transfer//~v76pI~
#define XEFTP_GRC_FFB3       0x80    //last parm is ffb3           //~v8@sI~
#define XEFTP_GRC_FPATH      0x0100  //last parm is fullpath name  //~v8@sI~
//**************************************************************** //~v59dI~
int xeftplog(int Popt,PUFILEH Ppfh,char *Psrcfnm,char *Ptmpfnm);   //~v59dR~
                                                                   //~v59dI~
//**************************************************************** //~v62hI~
int xeftprename(PUFTPHOST Ppuftph,char *Pfpathold,char *Pnewmemb); //~v62hI~
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
//**************************************************************** //~v63jI~
int xeftpgetdndwd(char *Pwdfname);                                 //~v63jR~
#endif  //WXE                                                      //~v63jR~
#endif  //************************                                 //~v54xI~
