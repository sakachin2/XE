//**Fixed-CID://+vb50R~:*      update#=9                           //+vb50R~
//**************************************************************** //~v0fqI~
//xefile7.h                                                        //~v0fqI~
//**************************************************************** //~v0fqI~
//vb50:160827 accept S+A/C+extended key                            //~vb50I~
//v71P:061107 enable cmd verb change on =0.2 panel                 //~v71PI~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~v67CI~
//v40K:010714 option to insert comment line for drop excluded cmd(dro x|nx rep)//~v40KI~
//v0ja:980721 change define value by change opt start from 0.0     //~v0iwI~
//v0ix:980718 key assign by key press                              //~v0ixI~
//v0iw:980718 pfk cmd support(del 0.5,cmd change by ini only)      //~v0iwI~
//v0io:980702 pfk cmd support(opt 0.4)                             //~v0ioI~
//v0im:980625 pfk cmd support(optk1 and optk2)                     //~v0imI~
//v0if:980620 pfk cmd support                                      //~v0ifI~
//v0ic:980607 label support for DROP cmd                           //~v0icI~
//v0hq:980316 add DROP cmd(del all line XON/XOFF)                  //~v0fqI~
//**************************************************************** //~v0fqI~
#ifndef KKK                                                        //~vb50I~
	#define FKF_PROTLEN1   8     //prot area len for cmd key file  //~vb50I~
#else                                                              //~vb50I~
#define FKF_PROTLEN1   6     //prot area len for cmd key file      //~v0imR~
#endif                                                             //~vb50I~
#define FKF_LRECL1     (FKF_PROTLEN1+FKF_MAXCMDLEN)    //cmd key list//~v0ioI~
#define FKF_MAXCMDLEN  MAXCOLUMN   //max cmd len                   //~v0ioM~
#ifndef KKK                                                        //~vb50I~
	#define FKF_PROTLEN2   16    //=0.3prot area len for func key file//~vb50I~
#else                                                              //~vb50I~
#define FKF_PROTLEN2   15    //prot area len for func key file     //~v0imI~
#endif                                                             //~vb50I~
#define FKF_MARGIN2    (FKF_PROTLEN2+7)   //key-func list          //~v0iwR~
#define FKF_LRECL2     (FKF_MARGIN2+48)                            //~v0iwR~
#define FKF_PROTLEN3   21   				//func-key list        //~v0ioR~
                                                                   //~vb50I~
#ifndef KKK                                                        //~vb50I~
	#define FKF_MARGIN3    (FKF_PROTLEN3+4+11)    //=0.2 key name(2 modifier prefix)//~vb50I~
#else                                                              //~vb50I~
#define FKF_MARGIN3    (FKF_PROTLEN3+2+11)    //key name           //~v0ixR~
#endif                                                             //~vb50I~
                                                                   //~vb50I~
#define FKF_LRECL3     (FKF_MARGIN3+22)      //func comment        //~v0ixR~
#define FKF_PROTLEN4   21    				//func-cmd list        //~v0iwR~,//~v71PR~
//#define FKF_MARGIN4    28                  	//cmd/cmda         //~v0iwR~,//~v71PR~
#define FKF_MARGIN4    29                  	//cmd/cmda         //~v0iwR~,//~v71PI~
#define FKF_LRECL4     50                 	//func comment     //~v0iwR~,//~v71PR~
#define FKF_OPTFNM     "XE OPT0."                     //fnm for option key//~v0imI~
#define FKF_OPTFNM_OPTPOS  8                          //fnm for option key//~v0imI~
//**************************************************************** //~v67CI~
typedef struct _ALCT	{      //alias cmd tbl entry               //~v67CI~
                            UQUEE  ALCqe;                          //~v67CI~
    			 			char   ALCTcmdverb[4];  //cmd verb     //~v67CI~
    			 			int    ALCTkbdctr;  //for loop chk     //~v67CR~
    			 			int    ALCTcmdlen;  //len of ALCTcmd   //~v67CR~
				 			char   ALCTcmd[1]; //cmd string from verb//~v67CR~
						} ALCT,*PALCT;                             //~v67CI~
#define ALCTSZ (sizeof(ALCT))                                      //~v67CI~
//**************************************************************** //~v0ifI~
int filedrop(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt,PULINEH Pplh1,PULINEH Pplh2);//~v0icI~
#define DFOPT_X      0x0001                                        //~v40KI~
#define DFOPT_NX     0x0002                                        //~v40KI~
#define DFOPT_REP    0x0100                                        //~v40KI~
                                                                   //~v0ifI~
//**************************************************************** //~v0ifI~
int filefk(PUCLIENTWE Ppcw,int Popt);                              //~v0imI~
#define FILEFK_OPTKCMD  '1'                                        //~v0iwR~
#define FILEFK_OPTFKEY  '2'                                        //~v0iwR~
#define FILEFK_OPTKLIST '3'                                        //~v0iwR~
//#define FILEFK_OPT05  '5'                                        //~v0iwR~
                                                                   //~v0ifI~
//**************************************************************** //~v0ifI~
int filefksave(PUFILEH Ppfh);                                      //~v0ifI~
                                                                   //~v0ixI~
//**************************************************************** //~v0ixI~
int filesetassign(PUCLIENTWE Ppcw,int Pextkeysw,USHORT Pkey,int Pshiftkeysw);//~v0ixI~
                                                                   //~v67CI~
//**************************************************************** //~v67CI~
int filesetupalct(void);                                           //~v67CI~
                                                                   //~v67CI~
//**************************************************************** //~v67CI~
PALCT filesrchalct(char *Pcmd,UQUEH *Ppqhalct);                    //~v67CI~
                                                                   //~v67CI~
//**************************************************************** //~v67CI~
void file7term(void);                                              //~v67CR~
