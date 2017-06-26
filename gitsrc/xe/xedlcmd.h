//CID://+vb81R~:                 update#=      3                   //+vb81R~
//****************************************************************
//xedlcmd.h                                                     //~5715R~
//****************************************************************//~5715I~
//vb81:170206 trap for edit panel lcmd input ignored case if !NOTRACE//+vb81I~
//vamy:131103 add dlcmd "$"(async version of "%")                  //~vamyI~
//vaa4:110520 ANDROID Send command/dlcmd                           //~vaa4I~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          files encoded by utf8,option cplc/cpu8                 //~va00I~
//v92h:080505 (UTF)new dlcmd "[":cplc, "]":cpu8 option for edit/browse//~v90hI~//~v76gI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v75M:070509 "="(compare) lcmd support. 1st file is line with cmd option on Enter'ed screen.//~v75MI~
//v75J:070509 "g"(grep) dlcmd support                              //~v75MI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HR~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v64w:050709 (LNX)openwith support by mouse dbl click             //~v64aI~
//v64a:050618 (LNX)xxe support                                     //~v64aI~
//v645:050617 OPT DELZ ON/OFF;option to prohibit dlcmd z/0;default is on//~v645R~
//v63n:050510 (LNX)revese  mouse selected line on dirlist          //~v63nI~
//v63h:050504 (WXE)support DragOut                                 //~v63hI~
//v609:050102 (FTP)for performance,multiple file delete at once from dirlist//~v609I~
//v57d:040517 for safety;protect del/rename/move for path dir from cur dir//~v57dI~
//v54E:040121 (BUG)abend when err dlcmd pending on the plh which is deleted by unexpand cmd//~v54EI~
//v44f:011204 new dlcmd 'H'/'h'(h:follow edit/browse open mode,'H':reverse)//~v44fI~
//v41c:010804 limit del etc. update function on browse dirlist     //~v41cI~
//v10s:990404 move csr to split scr for view/vieedit               //~v10sI~
//v0hm:980215 pend/err lcmd reset by double Esc or typed RESET     //~v0hmI~
//**************************************************************** //~v0hmI~
#ifdef  XEGBL_DLCMD                                                //~v76gI~
  #define XEDLCMD_EXT                                              //~v76gI~
  #define XEDLCMD_INIT(value) =value                               //~v76gI~
#else                                                              //~v76gI~
  #define XEDLCMD_EXT extern                                       //~v76gI~
  #define XEDLCMD_INIT(value)                                      //~v76gI~
#endif                                                             //~v76gI~
XEDLCMD_EXT int Ggrepctr;                                          //~v76gI~
XEDLCMD_EXT int Gcompctr;                                          //~v76gI~
//**************************************************************** //~v76gI~
                                                                //~5721I~
typedef struct _UDLCMD {                                        //~5715R~
						UCHAR   UDLCcmd;			//cmd code  //~5715R~
#define UDLCCMD_DNDSELECT  '_'  //drag and drop selected line      //~v63hI~
#define UDLCCMD_OPENWITH   '!'  //open by application associated   //~v64aI~
#define UDLCCMD_EDITF80    '8'  //edit open with F80 option        //~v75HI~
#define UDLCCMD_GREP       'g'  //grep cmd                         //~v75JI~
#define UDLCCMD_GREPUPPER  'G'  //grep cmd                         //~v75JI~
#define UDLCCMD_COMPARE    '='  //compare by xfc                   //~v75MI~
#define UDLCCMD_SEND       '^'  //send to utility panel            //~v76gR~
                                                                   //~v76gI~
#ifdef UTF8SUPPH                                                   //~v90hI~//~va00R~
  	#define UDLCCMD_CPLC   '['  //e/b with cplc option             //~v90hR~//~va00R~
 	#define UDLCCMD_CPU8   ']'  //e/b with cpu8 option             //~v90hR~//~va00R~
#endif                                                             //~v90hI~//~va00R~
#define UDLCCMD_APPASYNC   '$'  //execute asynchronously with the filename parameter//~vamyR~
						UCHAR   UDLCtype;         //cmd type    //~5715R~
#define UDLCTNOPAIR 	0x00					//single cmd    //~5715R~
#define UDLCTNEEDPOS	0x01					//need postion cmd//~5715I~
#define UDLCTPOSCMD 	0x02					//postion cmd   //~5715R~
#define UDLCTDISPLAY	0x04					//browse/edit   //~5715R~
#define UDLCTLINEINP1   0x08					//attr update   //~5716R~
#define UDLCTLINEINP2   0x10					//new name update//~5716I~
#define UDLCTMASK       0x20					//new name is mask//~5807I~
#define UDLCTERRBRW     0x40					//reject when browse mode//~v41cR~
#define UDLCTERRPATH    0x80					//reject for path(:) record//~v57dI~
						UCHAR   UDLCflag;         //cmd flag    //~5715R~
#define UDLCFERR      	0x80					//err detected  //~5715R~
#define UDLCFCOMP     	0x40					//command completed//~5715R~
#define UDLCFPEND     	0x20					//pair command pending//~5715R~
//#define UDLCBROWSE    0x10					//browse dirlist   //~v44fR~
#define UDLCUPPER       0x10					//cmd by upper case char//~v44fI~
#define UDLCEDIT     	0x08                    //edit dirlist     //~v44fR~
#define UDLCFFTPDEL  	0x04                    //remote file delete requested//~v609I~
#define UDLCFLAST    	0x02                    //last entry of same cmd//~v75JI~
#define UDLCF1ST     	0x01                    //1st  entry of same cmd//~v75JI~
//  					UCHAR   UDLCrsv;                           //~v609R~
    					UCHAR   UDLCtype2;                         //~v609I~
#define UDLCT2DELCMD    0x01					//delete cmd       //~v609I~
#define UDLCT2DELZCMD   0x02					//delete undoable cmd//~v645I~
                        int (*UDLCpfunc)(PUCLIENTWE,struct _UDLCMD *,struct _UDLCMD *);//~5721R~
						int     UDLCindex; 		//UFCcmd index  //~5715R~
						int     UDLCsplitid; 	//pcw splitid   //~5715R~
						PULINEH UDLCplh;			//ULINEH addr//~5715R~
						UCHAR   UDLCparm1;        //cmd flag       //~v75JM~
    					UCHAR   UDLCrsv2[3];                       //~v75JM~
					  	} UDLCMD;                               //~5715R~
typedef UDLCMD *PUDLCMD;                                        //~5721I~
#define UDLCMDSZ sizeof(UDLCMD)                                 //~5715R~
typedef int (UDLCFUNC)(PUCLIENTWE,PUDLCMD,PUDLCMD);             //~5731I~
                                                                //~5721I~
//****************************************************************//~5721I~
typedef int (DLCMDFUNC)(PUCLIENTWE,PUDLCMD,PUDLCMD);            //~5721I~
//****************************************************************//~5715I~
int dlcmdmain(PUCLIENTWE Ppcw);                                 //~5715I~
//**********************************************************************//~5716I~
int dlcmdfe(PUCLIENTWE Ppcw,UFLDE *Ppfle,UCHAR *Pdata,int Peventid);//~5716I~
//**********************************************************************//~5813I~
int dlcmdupctr(PULINEH Pplh);                                   //~5813I~
//**********************************************************************//~v0hmI~
int dlcmdreset(PUCLIENTWE Ppcw,PUFILEH Ppfh);                      //~v0hmI~
//**********************************************************************//~v10sI~
void dlcsaveviewpcw(void);                                         //~v10sI~
//**********************************************************************//~v54EI~
int dlcclearplcdeleted(PULINEH Pplh);                              //~v54ER~
//**********************************************************************//~v609I~
#ifdef FTPSUPP                                                     //~v609I~
int dlcftpmultdelgetrc(PUCLIENTWE Ppcw,UDLCMD *Pplc);              //~v609I~
#endif                                                             //~v609I~
                                                                   //~v63hI~
int dlcmdsetlcmd(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,char Plcmd);//~v63hR~
                                                                   //~v63hI~
//#ifdef WXE                                                       //~v63nR~
#if defined(WXE)||defined(LNX)                                     //~v63nI~
//**********************************************************************//~v63hM~
int dlcmddndset(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2);//~v63hR~
//**********************************************************************//~v63hI~
int dlcmddndreset(PUCLIENTWE Ppcw);                                //~v63hR~
//**********************************************************************//~v63nM~
//int dlcmddndgetpendctr(PUCLIENTWE Ppcw,PUFILEH Ppfh);            //~v685R~
int dlcmddndgetpendctr(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh);//~v685I~
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
//**********************************************************************//~v63hI~
int dlcmddndsetuplist(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Ppbuff,int *Pplen);//~v63hR~
#define DLCMDDND_REMOTECOPY 0x01                                   //~v63hI~
#define DLCMDDND_NODIR      0x02    //err if directory             //~vaa4I~
#define DLCMDDND_SETEOL     0x04    //line seperator               //~vaa4I~
#endif                                                             //~v63hI~
#endif                                                             //~v63nI~
int dlcsrchplh(int Popt,PUFILEH Ppfh,PULINEH Pplh);                //+vb81I~
