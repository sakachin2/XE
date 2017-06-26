//*CID://+vb4rR~:                             update#=  112;       //+vb4rR~
//****************************************************************//~6104I~
//xeopt.h                                                       //~6104I~
//****************************************************************//~6104I~
//vb4r:160811 (XXE) v4f for XXE((ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel))//+vb4rI~
//vb4q:160810 display ligature/combine mode on "TOP OF LINE"       //~vb4qI~
//vb4o:160809 set default to COMBINE mode                          //~vb4oI~
//vb4n:160808 (LNX)UNPR char was lost when change to split mode    //~vb4nI~
//vb4m:160808 set default combaltch by u-00                        //~vb4mI~
//vb4j:160806 (W32)OPT UNICOMP UNPR was effective only for file contents(chk at tabdisplay)//~vb4jI~
//vb2X:160404 display -Ccp value on optcombine help                //~vb2XI~
//vb2h:160129 display filename encoding type on hdr/trailer linet at ufcleft//~vb2hI~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//va7K:100904 add RESET option to cv cmd B2B(change UFHhandle) and CPEB option to RESet cmd.//~va7KI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3T:100322 Hex cmd:add option to zigzag csr move mode HEX [YZ|NZ]//~va3TI~
//va3s:100219 simple split mode like as windows. single write combining char when split mode.//~va3sI~
//            visibility depends to curses. user select split or combine mode.//~va3sI~
//            shadow is another option by opt cmd                  //~va3sI~
//va3h:100207 try ligature for also win32 console version          //~va3hI~
//va3e:100207 (LNX)Console version:to display combine char is not stable. add 3rd option to set unprintable. by A+":"//~va3eI~
//va30:100126 combine mode of diacritical marks by A+/             //~va30I~
//va1N:091122 (UTF8)CPU8 trans err reloading is option by UTF8 cmd //~va1NI~
//va1p:091104_(UTF8)file/dir default encoding option by UTF cmd    //~va1pI~
//va02:090525 CID copyon/copyoff(lcmd copy CID option)             //~va02I~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          for xeopt2                                             //~va00M~
//          files encoded by utf8                                  //~va00I~
//          select cmd chk cpu8/cplc of dir open parm              //~va00I~
//          set encoding id on header line                         //~va00I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v78S:080606 continuede insert line mode by lcmd "i"              //~v78SI~
//v779:071207 (UTF)do not clear locale info on inifile for xeu(v91d)//~v779I~
//v768:070613 new RCTL option(Enter->Execute,Rctl->NewLine)        //~v768I~
//v74y:070223 new option to set COLS ON as default                 //~v74yI~
//v72N:061214 CAPS:cmdline caps option "cap on/off cmd" to set caps optio to same as file contents option//~v72NI~
//v71L:061104 CAP option save and apply as default or apply TSO only//~v71LI~
//v705:060727 graphic char setup by external file                  //~v705I~
//v69X:060720 (XXE)line-draw support also fo gxe when OPT LINECH ON.(v69M)//~v69XI~
//v69M:060713 (LNX)Change line drawing char effectiveness to optional. OPT LINECHAR [on|off]//~v69MI~
//                 (no code in iso8859 but in old IBM-PC Extended Char Set(ECS) only)//~v69MI~
//v678:051227 opt option "RETTOL":return to top of line by return key//~v678I~
//v64t:050704 (XXE)xxe support;RCTL support                        //~v64tI~
//v645:050617 OPT DELZ ON/OFF;option to prohibit dlcmd z/0;default is on//~v645R~
//v62G:050412 cmdlog function                                      //~v62GI~
//v60m:050129 display different id from eolid for contline terminater.//~v60mI~
//v584:040823 cap option not to copy to ::cb when cap-delete for performance up for large file//~v584I~
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //~v55qI~
//v55j:040215 (LNX)use ctl+char as alternative of Shift+xx         //~v55jI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//v54S:040125 add opt cmd:beep on/off                              //~v54SI~
//v47N:020330 (UNX)mdos is option;set on of by opt dos cmd         //~v47NI~
//v47d:020223 opt eol char on/off;end of line char and attr specification cmd//~v47dI~
//v44m:011204 option of upper/lower hex code display               //~v44mI~
//v43y:011122 7bit dump mode                                       //~v43yI~
//v0g1:971207 print parm by short filename option(opt plfn on/off) //~v0g1I~
//v0f0:971010 long filename support                                //~v0f0I~
//            win95 alias dir list option(OPT FAT cmd)             //~v0f0I~
//v05B:960104:Option commnad                                    //~6104I~
//****************************************************************//~6104I~
#ifdef  XEOPT_GLOBAL                                               //~v44mI~
  #define XEOPT_EXT                                                //~v44mI~
  #define XEOPT_INIT(value) =value                                 //~v44mI~
#else                                                              //~v44mI~
  #define XEOPT_EXT extern                                         //~v44mI~
  #define XEOPT_INIT(value)                                        //~v44mI~
#endif                                                             //~v44mI~
//**************************************************************** //~v44mI~
//XEOPT_EXT UCHAR  Goptopt;                                        //~v71LR~
#define GOPT_HEX_UPPER        0x01   //hex display by UPPER case   //~v44mI~
#define GOPT_EOL_ATTRON       0x02   //eol char attr bit set       //~v47dI~
#define GOPT_EOL_ATTROFF      0x04   //eol char attr bit no set    //~v47dI~
#define GOPT_CMDLOG           0x08   //cmd log on                  //~v62GR~
#define GOPT_RETTOL           0x10   //return to tol on            //~v678I~
#define GOPT_CAPLOCK_TSO      0x20   //default for tso file        //~v71LI~
#define GOPT_CAPLOCK_DEFAULT  0x40   //default for all file        //~v71LI~
#define GOPT_CAPLOCK_CMD      0x80   //set cmd line to same status as file contents//~v72NI~
                                                                   //~v71LI~
XEOPT_EXT UCHAR  Goptopt XEOPT_INIT(GOPT_CAPLOCK_TSO);             //~v71LM~
                                                                   //~v768I~
//XEOPT_EXT UCHAR  Goptopt2;                                       //~vb4oR~
#ifdef UTF8SUPPH                                                    //~v91dM~//~va00I~
#define GOPT2_MODEINPUTL2U    0x01   //convert input locale to utf //~v90zI~//~va00I~
//#define GOPT2_MODEINPUTU2L  0x02   //convert input locale from utf//~v90zI~//~va00I~//~va1pR~
#define GOPT2_ALLFNUTF8       0x02   //all filename is utf8 encoded//~va1pR~
#define GOPT2_ALLFILEUTF8     0x04   //all file is utf8 encoded    //~v90zI~//~va00I~
#define GOPT2_ALLFILELOCALE   0x20   //all file is locale encoded  //~v916I~//~va00I~
//#define GOPT2_MODEINPUTCPFILE 0x40   //conv to cp of file          //~v916R~//~va00I~//~va1pR~
#define GOPT2_ALLFNLOCALE     0x40   //all filename is locale encoded//~va1pI~
#endif                                                             //~v78SI~//~va00I~
#define GOPT2_NOCONTINS       0x08   //NO cotinued insert line option//~v78SR~
#define GOPT2_CIDCOPY         0x10   //"c" lcmd copy also CID      //~va02I~
#ifdef UTF8UCS2                                                    //~va30I~
#define GOPT2_COMBINE         0x20   //diacritical mark combine mode//~va30I~
#endif                                                             //~va30I~
#define GOPT2_NORETRYCPLC     0x80   //no retry if cpu8 err        //~va1NR~
                                                                   //~vb4oI~
XEOPT_EXT UCHAR  Goptopt2 XEOPT_INIT(GOPT2_COMBINE);               //~vb4oR~
                                                                   //~vb4oI~
//#ifdef UTF8UCS2                                                  //~va3TR~
XEOPT_EXT UCHAR  Goptopt3;                                         //~va3eI~
#ifdef UTF8UCS2                                                    //~va3TI~
#define GOPT3_COMBINENP       0x01   //display combine char as not printable//~va3eI~
#define GOPT3_LIGATURE        0x02   //for console version         //~va3hR~
#endif                                                             //~va3TI~
#define GOPT3_VHEXCSRZIGZAG   0x04   //csr movement on vhexline,zigzag mode//~va3TI~
                                                                   //~va3sI~
#ifdef UTF8UCS2                                                    //~va3TI~
#define XEOPT_DEFAULT_COMBALTCH XEUTF_ERRREPCH_NPUCS      //":"    //~vb4mI~
#ifdef W32                                                         //~vb4jI~
//XEOPT_EXT int Goptcombaltch XEOPT_INIT(XEUTF_ERRREPCH_NPUCS); // ':' when OPT UNICOMB UNPR//~vb4mR~
XEOPT_EXT int Goptcombaltch XEOPT_INIT(XEOPT_DEFAULT_COMBALTCH); // ':' when OPT UNICOMB UNPR//~vb4mI~
#else                                                              //~vb4jI~
//XEOPT_EXT int Goptcombaltch;    //see uviom.h for value          //~vb4oR~
#ifdef XXE                                                         //+vb4rI~
XEOPT_EXT int Goptcombaltch     XEOPT_INIT(XEOPT_DEFAULT_COMBALTCH); // ':' when OPT UNICOMB UNPR//+vb4rI~
#else                                                              //+vb4rI~
XEOPT_EXT int Goptcombaltch     XEOPT_INIT(UVIOM_ALTCHITSELF);     //~vb4oI~
XEOPT_EXT int GoptcombaltchNP   XEOPT_INIT(XEOPT_DEFAULT_COMBALTCH); // ':' when OPT UNICOMB UNPR//~vb4nI~
#endif //!XXE                                                      //+vb4rI~
#endif                                                             //~vb4jI~
                                                                   //~va3sI~
#endif                                                             //~va3eI~
                                                                   //~v78SI~
XEOPT_EXT UCHAR  Gdefaultlocalecode[MAXLOCALESZ];   //from locale when env isutf8//~v79zI~
XEOPT_EXT UCHAR  Glocalecode[MAXLOCALESZ];   //0 for defauult      //~v768I~
XEOPT_EXT UCHAR  Gparmlocalecode[MAXLOCALESZ];                     //~vb2XI~
                                                                   //~v71LI~
XEOPT_EXT UCHAR  Gopteol;   //0 for defauult                       //~v47dR~
XEOPT_EXT UCHAR  Gopteol2;  //some for default                     //~v47dI~
XEOPT_EXT UCHAR  Gopteolcont;   //conline termID specification     //~v60mI~
XEOPT_EXT UCHAR  Gopteolcont2;  //display char for contline termID //~v60mI~
#ifdef UTF8SUPPH                                                   //~va00I~
    #define MODE_UTF8        "CPU8"                                //~va00I~
    #define MODE_LOCALE      "CPLC"                                //~va00I~
    #define MODE_ASIS        "CPAS"                                //~va00I~
    #define MODE_FNU8        "FNU8"                                //~vagEI~
    #define MODE_FNLC        "FNLC"                                //~vagEI~
    #define MODE_FNAS        "FNAS"                                //~vagEI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    #define MODE_EBC         "CPEB"                                //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    #define MODE_SWKBD       "SWKBD"                               //~va00I~
    #define MODE_OPTUTF8     "L2U"                                 //~va00I~
    #define MODE_OPTLOCALE   "U2L"                                 //~va00I~
    #define MODE_OPTENV      "ENV"                                 //~va00I~
    #define MODE_OPTCPFILE   "CPFILE"                              //~va00I~
    #define MODE_OPTNOCPFILE "NOCPFILE"                            //~va00I~
    #define MODE_RETRYCPLC   "ALTCPLC"                             //~va1NI~
    #define MODE_NORETRYCPLC "NOALTCPLC"                           //~va1NI~
	#define MODE_IE          "IE"  	//ignore cv err cmd option     //~va00I~
    #define MODE_UTF8FILEID    'U'                                 //~va00I~
    #define MODE_LOCALEFILEID  'L'                                 //~va00I~
    #define MODE_ASISFILEID    '*'                                 //~va00I~
    #define MODE_BINFILE       'b'                                 //~va00I~
    #define MODE_UTF8KBDID     'u'                                 //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    #define MODE_EBCFILEID     'E'                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                                                                   //~va3sI~
    #define OPTCMD_COMBINE    "UNICOMB"                            //~va3sR~
    #define OPTCMD_LIGATURE   "LIGATURE"                           //~va3sR~
	#define EBCCMD_OPT_SETCP "SETCP"                               //~va7KI~
                                                                   //~va3sI~
#ifdef WXE                                                         //~va3sI~
    #define OPT_ISLIGATUREON() (wxe_optligature(WXEIOLO_ISON,0)!=0)//~va3sI~
#else                                                              //~va3sI~
#ifdef XXE                                                         //~va3sI~
    #define OPT_ISLIGATUREON() (xxe_optligature(XXEIOLO_ISON,0)!=0)//~va3sI~
#else                                                              //~va3sI~
    #define OPT_ISLIGATUREON() (UTF_LIGATUREMODE()!=0)             //~va3sI~
#endif                                                             //~va3sI~
#endif                                                             //~va3sI~
#endif                                                             //~va00I~
//**************************************************************** //~v44mI~
typedef struct _UOPTWTBL                                        //~6104M~
{                                                               //~6104M~
//  	UCHAR  UOWcmd  [8];			//command word                 //~v43yR~//~vafhR~
    	UCHAR  UOWcmd  [12];			//command word             //~vafhI~
 		int    (*UOWfunc)(PUCLIENTWE,struct _UOPTWTBL*,int);//function addr//~6104I~
		UCHAR  UOWminopd;			//opd min count             //~6104I~
		UCHAR  UOWmaxopd;			//opd max count             //~6104I~
		UCHAR  UOWflag;				//flag                      //~6104I~
		UCHAR  UOWrsv;				//                          //~6104I~
} UOPTWTBL;                                                     //~6104M~
typedef UOPTWTBL *PUOPTWTBL;                                    //~6104M~
#define UOPTWTBLSZ (sizeof(UOPTWTBL))                           //~6104M~
typedef int (OPTFUNC)(PUCLIENTWE Ppcw,PUOPTWTBL Popt,int Popdno);//~6114R~
//*FUNCTION**************                                       //~6104I~
	OPTFUNC opt_undel;                                          //~6105R~
	OPTFUNC opt_fat;                                               //~v0f0I~
	OPTFUNC opt_pfat;                                              //~v0g1I~
	OPTFUNC opt_7bit;                                              //~v43yI~
	OPTFUNC opt_hex;                                               //~v44mI~
	OPTFUNC opt_eol;                                               //~v47dI~
	OPTFUNC opt_eolcont;                                           //~v60mI~
	OPTFUNC opt_beep;                                              //~v54SI~
	OPTFUNC opt_ccfunc;                                            //~v55jR~
	OPTFUNC opt_freecsr;                                           //~v55qI~
	OPTFUNC opt_cmdlog;                                            //~v62GI~
	OPTFUNC opt_delz;                                              //~v645I~
	OPTFUNC opt_rettol;                                            //~v678I~
	OPTFUNC opt_cols;                                              //~v74yI~
#ifdef UNX                                                         //~v47NI~
	OPTFUNC opt_fd;                                                //~v47NR~
//#ifdef XXE                                                       //~v768R~
	OPTFUNC opt_rctl;                                              //~v64tI~
//#endif                                                           //~v768R~
#else                                                              //~v55cI~
	OPTFUNC opt_rctl;                                              //~v55cI~
#endif                                                             //~v47NI~
	OPTFUNC opt_cbcopy;                                            //~v584I~
//#if defined(LNX) && !defined(XXE)                                //~v69XR~
//#ifdef LNX                                                       //~v705R~
	OPTFUNC opt_acs;                                               //~v69MI~
//#endif                                                           //~v705R~
	OPTFUNC opt_contins;                                           //~v78SI~
	OPTFUNC opt_combine;                                           //~va3sR~
	OPTFUNC opt_ligature;                                          //~va3sI~
//**************************************************               //~v47dI~
void optsetdisplayeolid(void);                                     //~v47NR~
void optsetdisplayeolcontid(void);                                 //~v60mI~
#ifdef UTF8SUPPH                                                   //~v915I~//~va00R~
	int filegetencoding(PUCLIENTWE Ppcw,PUFILEC Ppfc,PUFILEH Ppfh);//~va00I~
	void xeopt2init(void);                                         //~v91sR~//~va00M~
	void filesetlocaleid(PUFILEH Ppfh);                            //~v915I~//~va00R~
	void dirsetlocaleid(int Popt,PUFILEC Ppfc,char *Ppsddata);     //~v91hI~//~va00I~
#endif                                                             //~v915I~//~va00I~
void filesetlocaleid_filename(int Popt,PUFILEH Ppfh);              //~vb2hR~
//**************************************************************** //~va3sI~
int optoffonchk(char *Pparm,int Popt);                             //~va3sI~
#define OPTOFC_ERRMSG    0x01                                      //~va3sI~
#define OPTOFC_RESETCHK  0x02                                      //~va3sI~
//**************************************************************** //~va3sI~
int opt2resethandle(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int Phandle);//~va7KR~
#define OPT2RHO_RESETCMD  0x01          //from RES cmd             //~va7KI~
//**************************************************************** //~va7LI~
int opt2setebccvname(int Popt,PUFILEH Ppfh);                       //~va7LR~
int optresethdrligcomb(int Popt,PUCLIENTWE Ppcw);                  //~vb4qM~
