//*CID://+vba1R~:                                                  //~v7aDR~//+vba1R~
//**************************************************************** //~v780I~
//xesyn2.h                                                         //~v780I~
//**************************************************************** //~v780I~
//vba1:170625 (BUG) syntaxh,podelmtbl overflow crash for long record of xesynl.cfg; expand max cmdlen 256-->512//+vba1I~
//vaaD:120114 install highlight-2.16                               //~v7aDI~
//va7N:100905 simon's highlight parameter was changed at v3.1 ( -A is invalid for ansi, valid option is --//~v7aNI~
//            "-A" is invalid for ansi, valid option is --out-format=ansi//~v7aNI~
//v7at:090403 support andre-simon's Highlight(not resident mode)   //~v7atI~
//            (it drop triling space for ansi output)              //~v7atI~
//v79G:081014 (SYNH) source-highlight inheritance                  //~v79GI~
//v78o:080322 (SYN:BUG)reverse is not able to distingush on browse screen//~v78oI~
//v78m:080321 (SYN)S.H performance;ot thru acb but direct read source-highlight output//~v78aI~
//v78a:080304 (SYN)debug option(no unlink temp file at termination)//~v78aI~
//v786:080301 (SYNH)"ENTERU":update line only option               //~v786I~
//v780:080212 syntaxhighlight support                              //~v780I~
//**************************************************************** //~v780I~
#ifdef  XESYN2_GLOBAL                                              //~v780I~
  #define XESYN2_EXT                                               //~v780I~
  #define XESYN2_INIT(value) =value                                //~v780I~
#else                                                              //~v780I~
  #define XESYN2_EXT extern                                        //~v780I~
  #define XESYN2_INIT(value)                                       //~v780I~
#endif                                                             //~v780I~
//*filename table inde                                             //~v780I~
#ifdef W32                                                         //~v780I~
    #define SHFNM_CONFIG   "::xesynw.cfg"                          //~v780R~
#else                                                              //~v780I~
  #ifdef ARM                                                       //~v7aDI~
    #define SHFNM_CONFIG   "::xesyna.cfg"                          //~v7aDI~
  #else                                                            //~v7aDI~
    #define SHFNM_CONFIG   "::xesynl.cfg"                          //~v780I~
  #endif                                                           //~v7aDI~
#endif                                                             //~v780I~
#define SHFNM_PREFIX   "::#syn"                                    //~v780R~
#define SHFNM_INPUTF   ".inp"                                      //~v780R~
#define SHFNM_COLORF   ".clr"                                      //~v780R~
#define SHFNM_INDEXF   ".idx"                                      //~v780R~
#define SHFNM_ESCOUTF  ".esc"                                      //~v78mI~
#define SHFNM_ERRORF   ".err"		//source-highlight stderr      //~v780R~
#define SHFNM_ERRORF2  ".errexit"    //xeacb uerrexitmsg file      //~v780I~
                                                                   //~v780I~
//#define SHMAX_CMDLEN   256                                         //~v780I~//+vba1R~
#define SHMAX_CMDLEN   512                                         //+vba1I~
#define SH_DEFAULT_CMDNAME     "source-highlight"                  //~v780I~
#define SH_DEFAULT_CMDOPT      "-f esc"                            //~v780I~
//#define SH_DEFAULT_CMDOPT2     "-A"  //ansi option for andre-simon's Highlight-->invalid at v3.1//~v7atI~//~v7aNR~
#define SH_DEFAULT_CMDOPT2     ""  //spacify ansi option by xesyn_.cfg//~v7aNI~
#define SHID_NOEXT            ".noext"                             //~v780R~
                                                                   //~v780I~
#ifdef WXEXXE                                                      //~v780I~
	#define SH_ACBOPT     ""                                       //~v780I~
#else                                                              //~v780I~
//  #define SH_ACBOPT     "-I"		//intensive by BOLD            //~v780R~
	#define SH_ACBOPT     ""        //intensity is config option   //~v780I~
#endif                                                             //~v780R~
                                                                   //~v780I~
//**************************************************************** //~v780I~
typedef struct _SYNCFG {                                           //~v780I~
						int   SYNCflag;                            //~v780I~
#define   SYNCF_NF      0x01    //config file not fount (use default)//~v780R~
#define   SYNCF_OK      0x02    //bg specified                     //~v780I~
#define   SYNCF_BG      0x04    //bg specified                     //~v780R~
#define   SYNCF_FG      0x08    //fg specified                     //~v780R~
#define   SYNCF_BG_EOL  0x10    //draw out of line BG by BG color  //~v780I~
#define   SYNCF_BG_TAB  0x20    //draw TAB/err DBCS BG by BG color //~v780I~
#define   SYNCF_OPEN    0x40    //syn on at file open              //~v780I~
#define   SYNCF_OPENALL 0x80    //syn on at file open              //~v780I~
#define   SYNCF_BG_UPD  0x0100  //bg_upd specified                 //~v780I~
#define   SYNCF_ALLOCOL 0x0200  //rgb changed and color allocated  //~v780I~
#define   SYNCF_DEBUG1  0x0400  //debug no delete temp file at session end//~v78aI~
#define   SYNCF_DEFAULT_UPDONLY  0x00010000 //default updonly option//~v786R~
#define   SYNCF_USEACB           0x00020000 //use xeacb to process s.h output(old version)//~v78mR~
#define   SYNCF_BG_BROWSE        0x00040000 //bg for braowse panel specified//~v78oR~
#define   SYNCF_NORESIDENT       0x00080000 //not resident SH server//~v79GI~
#define   SYNCF_RSVRACTIVE       0x00100000 //resident server started//~v79GR~
#define   SYNCF_RSVRPARMOK       0x00200000 //parameter ok(server alive after 1st request)//~v79GI~
#define   SYNCF_HIGHLIGHT2       0x00400000 //cmd is andre-simon's Highlight//~v7atI~
						int    SYNCenter;                          //~v780M~
						UCHAR  SYNCbg;                             //~v780R~
						UCHAR  SYNCfg;                             //~v780R~
						UCHAR  SYNCbgbrowse;                       //~v78oI~
						UCHAR  SYNCbgeol;                          //~v780R~
						UCHAR  SYNCbgtab;                          //~v780R~
						UCHAR  SYNCbgupd;                          //~v780I~
						UCHAR  SYNCbgrevedit;  //reverse bg for edit panel//~v78oI~
						UCHAR  SYNCbgrevbrowse;//browse panel      //~v78oI~
						UCHAR  SYNCcmap[SHMAX_COLOR];              //~v780I~
						int    SYNCrgb[SHMAX_COLOR];               //~v780R~
						UCHAR  SYNCsmap[SHSTYLE_MAXNO];	//style maxp//~v780R~
#define SYNC_STYLE_NORMAL    0                                     //~v780M~
#define SYNC_STYLE_BOLD      1                                     //~v780M~
#define SYNC_STYLE_UNDERLINE 2                                     //~v780M~
#define SYNC_STYLE_ITALIC    3                                     //~v780M~
#define SYNC_STYLE_NOSYNTAX  4  //header line,pan etc              //~v780M~
#define SYNC_MAXSTYLE   4                                          //~v780I~
						UCHAR  SYNCstyleopt[SYNC_MAXSTYLE];        //~v780R~
#define SYNC_STYLE_CUI_HIGH   0x01     //high intensity for CUI version//~v780R~
#define SYNC_STYLE_GUI_HIGH   0x02     //high intensity for GUI version//~v780R~
#ifdef WXEXXE                                                      //~v780I~
	#define SYNC_STYLE_HIGH   SYNC_STYLE_GUI_HIGH                  //~v780R~
#else                                                              //~v780I~
	#define SYNC_STYLE_HIGH   SYNC_STYLE_CUI_HIGH                  //~v780R~
#endif                                                             //~v780I~
#define SYNC_STYLE_GUI_EACH   0x04     //apply each style          //~v780R~
                        char *SYNCshcmd;                           //~v780I~
                        char *SYNCacbcmd;                          //~v780I~
                        char *SYNCacbopt;                          //~v780I~
                        char *SYNCpfnmprefix;                      //~v780R~
                        UQUEH SYNCqhopenextlist;                   //~v780I~
                        UQUEH SYNCqhlangpathlist;                  //~v780I~
                        UQUEH SYNCqhupdonlyextlist;                //~v786R~
                      } SYNCFG,*PSYNSYG;                           //~v780I~
#define SYNCFGSZ   sizeof(SYNCFG)                                  //~v780I~
#define SYN_PAL_FGCOLOR(col) (Gsyncfg.SYNCcmap[(col)])             //~v780R~
#define SYN_PAL_BGCOLOR(col) (SYN_PAL_FGCOLOR(col)<<4)             //~v780R~
#define SYN_PAL_COLOR(col)   (SYN_PAL_BGCOLOR((col & 0xf0)>>4) | SYN_PAL_FGCOLOR(col & 0x0f))//~v780R~
#define SYN_STYLE_MAP(chstyle)   (Gsyncfg.SYNCsmap[(chstyle) & 0x0f])//~v780I~
//#define SYN_STYLE_COLOR(chstyle)   (Gsyncfg.SYNCsmap[(chstyle) & 0x0f])//~v780R~
#define SYN_HIGHLIGHT_FG  0x08    //high intesity FG               //~v780I~
//********************************                                 //~v780I~
typedef struct _SYNQE {		//string chain list                    //~v780I~
						UQUEE   SYNQEelem;                         //~v780I~
						char    SYNQEstr[1];                       //~v780I~
                      } SYNQE,*PSYNQE;                             //~v780I~
#define SYNQESZ   sizeof(SYNQE)                                    //~v780I~
//**************************************************************** //~v780I~
 XESYN2_EXT SYNCFG Gsyncfg;                                        //~v780I~
//**************************************************************** //~v780I~
int syngetcfg(int Popt);                                           //~v780M~
#define SGCO_INIT   0x01        //init call                        //~v780R~
#define SGCO_RESET  0x02        //reset call                       //~v780I~
//**************************************************************** //~v780I~
int synkicksh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Ppfnmprefix,char *Ppfnminput,UCHAR *Plangtype);//~v780I~
//**************************************************************** //~v780I~
char *syngetshcmd(int Popt);                                       //~v780I~
//**************************************************************** //~v780I~
char *syngetshopt(int Popt);                                       //~v780I~
//**************************************************************** //~v780I~
char *syngetwkfnm(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);          //~v780R~
//**************************************************************** //~v780I~
int syncfgfree(int Popt);                                          //~v780I~
#define SCFO_UNLINK       0x01 //delete work file                  //~v780I~
//**************************************************************** //~v780I~
int synsetinpfnm(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Ppfpath);//~v780R~
//**************************************************************** //~v780I~
int synopencf(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int *Pphandle);//~v780I~
//**************************************************************** //~v780I~
int synclosecf(int Popt);                                          //~v780I~
//**************************************************************** //~v780I~
int syngetcfdata(int Popt,int Phandle,int Pindex,PULHCI *Pplhci,int Pctr);//~v780R~
#define SGCDO_SPLIT1    0x01  //split to next                      //~v780R~
#define SGCDO_SPLIT2    0x02  //split from prev                    //~v780R~
//**************************************************************** //~v780I~
int synqeproc(int Popt,PUQUEH Ppqh,char *Pstr,PUQUEE *Pppqe);      //~v780R~
#define SYNQEPO_FREE       0x01000000                              //~v780R~
#define SYNQEPO_ENQ        0x02000000                              //~v780R~
#define SYNQEPO_SCAN       0x04000000                              //~v780R~
#define SYNQEPO_ICASE      0x08000000    //ignorecase              //~v786I~
#define SYNQEPO_SCANOFFS_MASK  0x00ff    //scan offset mask        //~v780R~
#define SYNQEPO_LANGTYPE       0x0008    //lanthpe                 //~v780R~
//**************************************************************** //~v780I~
int syngetbgeol(int Popt);                                         //~v780I~
//**************************************************************** //~v780I~
int syngetbgupd(int Popt);                                         //~v780I~
//**************************************************************** //~v780I~
int syngetstylecolor(int Popt,char *Pstylecolor,int *Ppstyle);     //~v780R~
