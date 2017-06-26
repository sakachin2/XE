//CID://+vaj0R~:   update#=   10;                                  //+vaj0R~
//****************************************************************
//*xefcmd6.h                                                       //~v8@FR~
//****************************************************************
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW})         //+vaj0I~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//va6i:000622 COPY cmd;chk CPxx profile of copy source file        //~va6iI~
//va51:100415 Record mode file option                              //~va51I~
//v8@F:080629 3270:NUMSTD consideration when SJIS=>EBC translation(SO/SI insert case)//~v8@FI~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v78r:080326 profile function                                     //~v78rI~
//v511:030302 new rotate cmd
//****************************************************************
int fcmdlineupdate(PUCLIENTWE Ppcw,PULINEH Pplh,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen);//~v511R~
//****************************************************************
int fcmdgetabrange(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Pplabt[][ULHLINENOSZ+1],
						int Plabctr,PULINEH *Ppplhs,PULINEH *Ppplhe,int Popt);
//**************************************************************** //~v78rI~
int fcmdprofgetprofile(int Popt,PUFILEH Ppfh,long *Pprofflag);     //~v78rR~
//**************************************************************** //~va6iI~
int fcmdprofgetprofilebyfilename(int Popt,PUCLIENTWE Ppcw,char *Pfnm,PUFILEH /*output dummy*/Ppfh,long *Ppsetflag);//~va6iR~
//**************************************************************** //~v78rI~
int fcmdprofupdaterecord(ULONG Popt,char *Pfnm,char *Pstrvalue,int Pintval1,int Pintval2);//~v78rR~
//#define FPURO_FUNCMASK       0xffff                              //~v8@2R~
#define FPURO_FUNCMASK     0xffffff                                //~v8@2I~
#define FPURO_CAPS           0x0001                                //~v78rR~
#define FPURO_NUMSTD         0x0002                                //~v78rR~
#define FPURO_NUMCOB         0x0004                                //~v78rR~
#define FPURO_BNDS           0x0008                                //~v78rR~
#define FPURO_LRECL          0x0010                                //~v78rR~
#define FPURO_SYNOPEN        0x0020                                //~v78rR~
#define FPURO_SYNENTER       0x0040                                //~v78rR~
#define FPURO_SYNLANG        0x0080                                //~v78rR~
#define FPURO_TABCLEAR       0x0100                                //~v78rR~
#define FPURO_OOMNOPROT      0x0200                                //~v78rR~
#define FPURO_MARGIN         0x0400                                //~v78rI~
#define FPURO_SYNOFF         0x0800                                //~v78rI~
#define FPURO_VHEX           0x1000                                //~v78rI~
#define FPURO_COLS           0x2000                                //~v78rI~
#define FPURO_COLSDEF        0x4000      //default cols            //~v78rR~
#define FPURO_CP             0x8000                                //~v8@2R~
#define FPURO_TABCTR       0x010000      //tabctr                  //~v8@2R~
#define FPURO_RECORD       0x020000      //record mode             //~va51I~
#define FPURO_CVNAME       0x040000      //record mode             //~va6iI~
#define FPURO_FNCP         0x080000      //filename encoding       //~vagEI~
#define FPURO_RECORDV      0x100000      //record mode variavle    //+vaj0I~
#define FPURO_PROFILE      0x800000      //profile gotten          //~v8@FI~
#define FPURO_EBCMD      0x80000000      //save profile from eb cmd option//~v78rR~
#define FPURO_EXT        0x40000000      //write ext record        //~v78rR~
#define FPURO_PATH       0x20000000      //write path record       //~v78rI~
#define FPURO_FILE       0x10000000      //write file record       //~v78rI~
//**************************************************************** //~v78rI~
int fcmdproferrnoext(char *Pfnm);                                  //~v78rI~
//**************************************************************** //~v78rI~
