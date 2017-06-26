//CID://+vb2DR~: update#=      1 1                                 //+vb2DR~
//****************************************************************//~5308I~
//*xefcmd4.h                                                       //~9417R~
//****************************************************************//~5308I~
//vb2D:160221 LNX compiler warning                                 //+vb2DI~
//va8w:101209 SPLIT/TFLOW:delete so/si when join dbcs string       //~va8wI~
//va8k:101013 SPLit cmd;dbcs consideration for split ALL/OVER without SBCS option .//~va8kI~
//**************************************************************** //~v11NI~
#ifdef GBL_FC43                                                    //~va8kI~
    int Gswebcfile_fc43;                                           //~va8kI~
    int Gswutf8file_fc43;                                          //~va8kI~
	int Gchspace_fc43;                                             //~va8kI~
	int Gotheropt_fc43;                                            //~va8wR~
	int Gopt2_fc43;                                                //~va8wI~
#else                                                              //~va8kI~
    extern int Gswebcfile_fc43;                                    //~va8kI~
    extern int Gswutf8file_fc43;                                   //~va8kI~
	extern int Gchspace_fc43;                                      //~va8kI~
	extern int Gotheropt_fc43;                                     //~va8wR~
	extern int Gopt2_fc43;                                         //~va8wI~
#endif                                                             //~va8kI~
#define  SOTHO_STRSPACEADD    0x01    //insert space in delmstr    //~va5qI~//~va8wM~
#define  SOTHO_APPENDSO       0x02    //append SO for split ebc dbcs string//~va8kI~//~va8wM~
#define  SOTHO_JOIN           0x04    //allow splitlen=0 for ebc data//~va8kR~//~va8wM~
#define  SOTHO_APPENDSODONE   0x08    //append SO for split ebc dbcs string//~va8kI~//~va8wM~
#define  SOTHO_DELMONTOL      0x10    //delm matched on tol        //~va8qR~//~va8wM~
//#define  SOTHO_EBCMIN0TOL     0x08    //allow splitlen=0 for ebc TOL delmstr found case//~va8kR~//~va8wM~
#define  SOTHO_TOPLINETOL     0x20    //delm on tol is err         //~va8uI~//~va8wM~
#define  SOTHO_SPLITBNDSSHORT 0x40    //bnds short rec for SPLIT cmd//~va8vI~//~va8wM~
#define  SOTHO_SPLITJOINED    0x80    //split conwk joined         //~va8vI~//~va8wM~
#define  SOTHO_BNDSCONTSETSO  0x0100  //bnds contdata top SO by dbcs string split//~va8wI~
#define  SOTHO_BNDSCONTSETSI  0x0200  //bnds contdata end SI by dbcs string split//~va8wI~
#define  SOTHO_OLB2ND         0x0400  //tgt line left out boundary is DBCS2ND//~va8wI~
#define  SOTHO_ORB1ST         0x0800  //tgt line right out boundary is DBCS1ST//~va8wI~
#define  SOTHO_IRB2NDOK       0x1000  //cut ok at next of DBCS2ND by ORB1ST//~va8wI~
#define  SOTHO_DELSI          0x2000  //delete end SI              //~va8wI~
//*Sopt2                                                           //~va8wI~
#define SOPT2_SPLCRLF               0x01  //display width change   //~v77fI~//~va8wM~
//*******************************************************
#define  FCSPLRC_PSTOP  32              //stop paragraph           //~v758R~
#define  FCSPLRC_PNEW   33              //start new paragraph      //~v758R~
#define  FCSPLRC_DBCSSPLIT  0x80        //rc for bndsgetsrc        //~v74WI~
#define  FCSPLRC_DELMFOUND     1           //linefilled sw(splitted by delm)//~v75eI~
#define  FCSPLRC_WORDKEPT      2           //linefilled sw(splitted by space,pos shifted by KWB option)//~v75eR~
#define  FCSPLRC_WORDKEPTAFTER 3           //linefilled sw(splitted by space,pos shifted by KWA option)//~v75eI~
#define  FCSPLRC_SPACEDELM     4           //edge is space         //~v75mI~
#define  FCSPLRC_APPENDSO   0x0100         //append so for split ebc dbcs string//~va8kI~
#define  FCSPLRC_DELSI      0x0200         //delete last si        //~va8wR~
#define  FCSPLRC_TFEBCSPLIT 0x0400         //tflow split long for ebcfile//~va8wI~

#define FCSPL_TYPEMASK   0xff                                      //~v45xI~
#define FCSPL_SBCS       0x0100                                    //~v45xI~
#define FCSPL_ALLWIDTH0  0x0200                                    //~v50zR~
#define FCSPL_TOL        0x0400    //top of line option            //~v50AI~
#define FCSPL_STRDELM    0x0800    //string deleimeter             //~v50BI~
#define FCSPL_MARGIN     0x1000    //ALL option with width by margin or bnds//~v74WR~
#define FCSPL_STRSPACE   0x2000    //STRSPACE(split only once by continued space)//~v74XI~
#define FCSPL_OOM        0x4000    //OOM for TAIL(ignore margin)   //~v74WI~
#define FCSPL_SPACE1     0x8000    //SPACE1(rduce spaces to one space)//~v74YI~
#define FCSPL_EACHPARAG  0x010000  //inser remainig data at end of each paragraph//~v75kI~
#define FCSPL_SRCPLHEND  0x020000  //src plh exausted              //~v74WI~
#define FCSPL_TFLOW      0x040000  //tflow patern(shrink space at line boundary)//~v74ZI~
#define FCSPL_TFLOWCMD   0x080000  //tflow cmd                     //~v751I~
#define FCSPL_TFNOP      0x00100000  //tflow ignore paragraph      //~v75wI~
#define FCSPL_TFTOPLINE  0x00200000  //tflow no indentation        //~v74ZR~
#define FCSPL_SETDBCSERR 0x00400000  //set err for DBCS split by SBCS option//~v750I~
#define FCSPL_NOWIDTH    0x00800000  //no width parm(width by margin or bnds)//~v76LI~
#define FCSPL_KEEPWORD   0x01000000  //tflow no split word at boundary//~v753R~
//#define FCSPL_PNEW       0x02000000  //continue next paragraph when indentation change//~v759R~
#define FCSPL_KEEPWORDSN 0x02000000  //keepword,split at next delm //~v75eI~
//#define FCSPL_PSTOP    0x04000000  //stop process when indentation change//~v759R~
#define FCSPL_SPLITBNDS  0x04000000  //slplitlen by bnds           //~v76LI~
#define FCSPL_TFLOWLCMD  0x08000000  //tflow no split word at boundary//~v75aR~
#define FCSPL_TFJOIN1ST  0x10000000  //tflowjoinsub     join 1st   //~v75eR~
#define FCSPL_TFJOIN     0x20000000  //tflowsplitlen req by join(do KEEPWORD)//~v75rI~
#define FCSPL_IND1ST     0x40000000  //indentation by 1st line     //~v75gR~
#define FCSPL_SPWKPARAG  0x80000000  //parm to getindent(chk data on SPWORK)//~v75iI~
                                                                   //~v75gR~
#define  PARM_WORDSPLIT   "SWORD"      //split in a word           //~v75eI~
#define  PARM_WORDAFTER   "AWORD"      //split after a word        //~v75eI~
#define  PARM_IBASE1      "BASE1"      //indentation base is 1st line//~v75gI~
#define  PARM_IGNPARAG    "NOP"         //ignore paragraph         //~v75hI~
#define  PARM_EACHPARAG   "EACH"        //insert after each paragraph//~v75kI~
#define  PARM_CRLF        "CRLF"                                   //~v77fI~
                                                                   //~v75qI~
#define  SPECIALDELM1      '.'         //insert 2 space after "." at eol//~v75qI~
//****************************************************************
typedef struct _SPLITWK {                                          //~v74WI~
						UQUEE SPWqe;                               //~v74WI~
						int   SPWlen;                              //~v74WI~
                        int   SPWflag;                             //~v74WI~
//#define SPWF_DBCSSPLITTOP  0x01                                  //~v75fR~
//#define SPWF_DBCSSPLITEND  0x02                                  //~v75fR~
#define SPWF_PNEW          0x04  //new paragraph start by indentation change//~v758I~
#define SPWF_PSTOP         0x08  //indentation change under stop new paragraph option//~v758I~
#define SPWF_PARAGCHKED    0x10  //once paragraph chked            //~v75iI~
#define SPWF_DBCSSPLITL    0x20  //getsrcplh inserted SO at left boundary by dbcs split err//~va8wR~
#define SPWF_DBCSSPLITR    0x40  //getsrcplh inserted SI at right boundary by dbcs split err//~va8wI~
#define SPWF_SETSO         0x80  //so was set by dbcs1st on top    //~va8wI~
#define SPWF_SETSI         0x0100//si was set by dbcs2st on end    //~va8wI~
#define SPWF_TFEBCSPLIT    0x0200//ebc long line split for tflow by sosi insertion//~va8wI~
                        int   SPWheadcnt;                          //~v75iI~
                        UCHAR SPWdatadbcs[1];                      //~v74WI~
                       } SPLITWK,*PSPLITWK;                        //~v74WI~
//#define SPLITWKSZ (sizeof(SPLITWK))                                //~v74WI~//+vb2DR~
#define SPLITWKSZ ((int)(sizeof(SPLITWK)))                         //+vb2DI~
//****************************************************************
int fcmdsplitbin(int Popt,PUCLIENTWE Ppcw,UFILEH *Ppfh,char *Ppdelmstr,//~v60sI~
						PULINEH Pplh1,PULINEH Pplh2,int Pwidth);   //~v60sI~
//****************************************************************
int fcmdebcsplitlen(int Pfuncopt,int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Pdatalen,int Pwidth,char *Pstrdelm,int *Ppsplitlen);//~va8kR~
#define FCEBSLO_MIN0     0x01           //allow return length=0    //~va8kI~
#define FCEBSLO_EXPAND   0x02           //expandable within bnds range//~va8kI~
#define FCEBSLO_IRB2NDOK 0x04           //avilable to cut after dbcs2nd//~va8wI~
//****************************************************************
int fcmdsplitspace1data(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int *Ppdelctr);//~v74YR~
//**************************************************************** //~va8kM~
int fcmdebcappendsoeol(int Popt,PULINEH Pplh);                     //~va8kI~
//**************************************************************** //~va8wI~
int fcmdebcchkdbcsconcat(int Popt,UCHAR *Pdata1,UCHAR *Pdbcs1,int Plen1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen2);//~va8wR~
//**************************************************************** //~va8wI~
int fcmdebcchkdbcsconcatbnds(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int *Ppcutflag,PSPLITWK Ppspw,int Psrcoffs,int Pwidth,int Plen2);//~va8wR~
#define FCEBCCF_TOPSO         0x01       //splitcmd updatebnds drop top so//~va8wR~
#define FCEBCCF_ENDSI         0x02       //                         end si//~va8wR~
#define FCEBCCF_INTSOSI       0x04       //                         concat sosi//~va8wR~
#define FCEBCCF_ENDCONCAT     0x08       // right boundary is 2+1  //~va8wI~
#define FCEBCCF_TOPCONCAT     0x10       // left  boundary is 2+1  //~va8wI~
#define FCEBCCF_HEADCONCAT    0x20       // left  boundary is 2+1  //~va8wI~
#define FCEBCCF_APPENDSI      0x40       // short src end width dbcs2nd//~va8wR~
#define FCEBCCF_INSERTSO      0x80       // bnds sork was split at dbcs boundary//~va8wR~
//**************************************************************** //~va8wI~
int fcmdebcchkdbcsconcatbndsupdateL(int Popt,UCHAR *Pdata1,UCHAR *Pdbcs1,int Plen1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen2);//~va8wI~
//**************************************************************** //~va8wI~
int fcmdebcchkdbcsconcatbndsupdateR(int Popt,UCHAR *Pdata1,UCHAR *Pdbcs1,int Plen1,int Pwidth,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen2);//~va8wR~
//**************************************************************** //~va8wI~
int fcmdebcchkdbcsconcatbndsupdate(int Popt,PULINEH Pplh,int Poffs1,int Poffs2,int Pwidth);//~va8wR~
