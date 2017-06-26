//*CID://+vb00R~:                             update#=   39;       //+vb00R~
//*********************************************************************
//* xegbl.h
//*********************************************************************
//vb00:150309 v1.28 xegbl.h                                        //+vb00I~
//vaiD:130703 xe version  1.27                                     //~vaiDI~
//va8x:110520 version:v1.26                                        //~va8xI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          version 1.25                                           //~va00I~
//v79T:081028 Gunxflag setup required for sedbcstbl from functinit;move to xe.c from xescr.c//~v79TR~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v730:061225 use UPLbuff for cmdline(to display as long as possible if del key used, and accept insert over screen width)(also xeutf)//~v690I~
//v690:060418 (v122)display file-description support on dir-list panel//~v690I~
//v67L:060205 v121                                                 //~v67LI~
//v64d:050619 (UNX)cut hostname by "." on hdr filename             //~v64dI~
//v64b:050619 (LNX)to shorten hostname,chk local                   //~v63qI~
//v63q:050519 v118                                                 //~v63qR~
//v570:040420 version 116                                          //~v570I~
//v55y:040303 update version no to 1.15                            //~v55yI~
//v51k:030530 v1.13 id                                             //~v51kI~
//v500:020929 (WXE)for charset change;exchange unp char,tabdisp char//~v500I~
//v460:020119 (UNX)v110(kbd restore bug)                           //~v460I~
//v440:011125 browse hex                                           //~v440I~
//v43r:011109 rel v109(AIX only)                                   //~v43rI~
//v41v:010908 UNX:hostname display                                 //~v41vI~
//v305:001124 AIX support:tab disp char                            //~v305I~
//v20R:001119 set versio 1.07                                      //~v20RI~
//v20q:001015 max color number display on panel 0.0                //~v20qI~
//v21i:010113 LINUX support:euc code dbcs support                  //~v21iI~
//v19T:000928 LINUX support(Global userid var;from now new grobal is on xegbl.h)//~v19TI~
//v19x:000923 LINUX support(another main for other parm by -- and external parm)//~v19xI~
//v19e:000904 LINUX support(version 1.09)                          //~v19eI~
//v176:000430 default change for bin file line width from 999 to 72//~v176I~
//v175:000430 ver set to v1.06                                     //~v150I~
//v150:990822 v1.05                                                //~v150I~
//v140:990822 v1.04                                                //~v140I~
//v130:990822 v1.03                                                //~v130I~
//v0jb:980721 v1.00                                                //~v0jbI~
//v0i1:980430 move version defi to gbl.h from gbl.c                //~v0i1I~
//v051:951014:print dlcmd                                       //~v051I~
//*v031:950712:new
//*********************************************************************
#define VER   "v1.28"                                              //~v76gR~//~vaiDR~//+vb00R~
                                                                   //~v440I~
#define BINFILE_LINEWIDTH  72//default width for bin file          //~v176I~
#define BINFILE_HEXLINEWIDTH  20//default width for bin file hex display//~v440R~
//*******************************************************
#ifdef  XEGBL_GLOBAL                                               //~v19TI~
  #define XEGBL_EXT                                                //~v19TI~
  #define XEGBL_INIT(value) =value                                 //~v19TI~
#else                                                              //~v19TI~
  #define XEGBL_EXT extern                                         //~v19TI~
  #define XEGBL_INIT(value)                                        //~v19TI~
#endif                                                             //~v19TI~
//*******************************************************          //~v19TI~
#ifdef UNX                                                         //~v19TI~
                                                                   //~v19TI~
XEGBL_EXT int  Guserid;                                            //~v19TR~
XEGBL_EXT int  Ggroupid;                                           //~v19TR~
XEGBL_EXT char Ghostname[32];	//hostname                         //~v41vI~
XEGBL_EXT char Ghostname2[32];	//only hostid of with domainid     //~v64dI~
XEGBL_EXT int  Glocalhostsw;	//hostname is local                //~v64bR~
                                                                   //~v305I~
XEGBL_EXT int  Gunxflag;                                           //~v305I~
#define   GUNX_KON         0x01     //under kon                    //~v305I~
#define   GUNX_EUC         0x02     //euc code                     //~v21iI~
#define   GUNX_UNDERX      0x04     //linux X                      //~v460I~
#define   GUNX_KONTERM     0x08     //KON by uviol_konchk          //~v79TR~
#define   GUNX_XTERM       0x10     //DBCS not avail on emulater xterm//~v79TR~
#define   GUNX_FENG        0x20     //no dbcs term emulater,force english//~v79TR~
                                                                   //~v19TI~
#endif                                                             //~v19TI~
                                                                   //~v20qI~
XEGBL_EXT int  Gmaxcolor;	//init at xescr                        //~v20qI~
XEGBL_EXT char *Gcomparecmdf;	//diff or xfc                      //~v76gI~
XEGBL_EXT char *Gcomparecmdd;	//xdc                              //~v76gI~
XEGBL_EXT char *Ggrepcmd;       //grep                             //~v76gI~
                                                                   //~v20qI~
//*******************************************************          //~v19TI~
void gblinit(void);
                                                                //~v051I~
//*******************************************************          //~v19eI~
#ifdef UNX                                                         //~v19xR~
void xesetkbdopt(int Popt);                                        //~v19xR~
//*******************************************************          //~v305I~
void gblkon(int Popt);                                             //~v305I~
#define KON_TABDISP   1                                            //~v305I~
#define KON_UNPCHAR   2                                            //~v305I~
#endif                                                             //~v19xR~
//*******************************************************       //~v051I~
void gblterm(void);                                             //~v051I~
                                                                   //~v500I~
#ifdef WXE                                                         //~v500I~
//*******************************************************          //~v500I~
void gblcpchng(int Pjpnmode);                                      //~v500I~
#endif                                                             //~v500I~
