//*CID://+vaj0R~:                             update#=   66;       //+vaj0R~
//**************************************************************** //~v54dI~
//xefile14.h                                                       //~v54dI~
//**************************************************************** //~v54dI~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW|FD|HD|F|H})//+vaj0I~
//va6k:000622 COPY cmd considers priofile RECORD mode              //~va6kI~
//va1e:091101_(UTF8) retry by lc for f2l err at load if no CPU8 option specified//~va1eI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          Copy:CPxx option  COPy/MOVe fnm [CPU8] [IE]            //~va00I~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HI~
//v70z:060904 3270 ftp support                                     //~v70zI~
//v576:040513 (FTP:BUG)if u edit same filename except case,        //~v576I~
//            another file name is  save back to remote.so use tempdir//~v576I~
//v54d:040103 split xefile.c to xefile.c xefile14.c                //~v54dI~
//****************************************************************
#define FILE_OPEN_BIN     0x0100                                   //~v0abR~
#define FILE_OPEN_APPEND  0x0200       //append mode open          //~v0iaI~
#define FILE_OPEN_OUT     0x007f                                   //~v0abR~
#define FILE_NOSPLITMSG   0x1000       //no split msg by filegetline//~v41qI~
#define FILE_BINHEXFILE   0x2000       //bin or hex edit/browse cmd//~v70zI~
#define FILE_READUTF8     0x4000       //reading copy cmd utf8 sourcefile;parm to filegetline//~va00R~
#ifdef UNX                                                         //~v48cI~
int filefindopen(UCHAR *Ppfile,FILEFINDBUF3 *Ppfstat3,int Popt,    //~v48cI~
//  			FILE** Pphfile,int Pmsgopt,UCHAR *Ptempalias);     //~v576R~
    			FILE** Pphfile,int Pmsgopt,UCHAR *Ptempalias,UCHAR *Pftplocalfnm);//~v576I~
#else                                                              //~v48cI~
  #ifdef FTPSUPP                                                   //~v576I~
int filefindopen(UCHAR *Ppfile,FILEFINDBUF3 *Ppfstat3,int Popt,    //~v576I~
				FILE** Pphfile,int Pmsgopt,UCHAR *Pftplocalfnm);   //~v576R~
  #else                                                            //~v576I~
int filefindopen(UCHAR *Ppfile,FILEFINDBUF3 *Ppfstat3,int Popt, //~5625I~
                FILE** Pphfile,int Pmsgopt);                    //~5625I~
  #endif                                                           //~v576I~
#endif                                                             //~v48cI~
                                                                //~5118I~
//****************************************************************
int filegetline(UCHAR *Pfilename,FILE *Phfile,long Pline,PULINEH *Ppplh,//~v09YR~
                int Prbmode,PUFILEH Ppfh);                         //~v107R~
                                                                //~5118I~
//**************************************************************** //~va6kI~
int filegetline_copysrc(int Popt,UCHAR *Pfilename,FILE *Phfile,long Pline,PULINEH *Ppplh,//~va6kI~
                int Prbmode,PUFILEH Ppfh,int Pcopyopt,int Pcopylrecl);//~va6kI~
                                                                   //~va6kI~
//**************************************************************** //~v54dI~
int fileload(PUCLIENTWE Ppcw,UCHAR *Ppfile,UCHAR *Pfullpath,UCHAR Ppopt,PUFILEH *Pppfh,//~v54dI~
//  		char Pbinsw,char Peditsosw,char Pfkinisw);             //~v75HR~
    		int  Pbinsw,char Peditsosw,int Pfkinisw);              //~v76mR~
#define FLO2_FKINI        0x01                                     //~v76mI~
#define FLO2_OPT2         0xfffe      //other option is for func_edit_file2//~v76mI~
#define FLRC_RETRYCPU8ERR -8          //translation err at CPU8 parm not specified//~va1eR~

//**************************************************************** //~v542I~
void filesetfstat(PUFILEH Ppfh,FILEFINDBUF3 *Ppfstat3);            //~v542I~
//**************************************************************** //+vaj0I~
int setufgetsoptVparm2(int Pvfmt);                                 //+vaj0I~
