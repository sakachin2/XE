//CID://+vbmiR~:      update#=   35                                //+vbmiR~
//****************************************************************
//xescr.h                                                          //~va00R~
//****************************************************************//~5611I~
//vbmi:180807 (W32:Bug)top panel LC line is corrupted,use not OutputW but OutputCharacterW.(See v6C8)//+vbmiI~
//vbi3:180211 supprt command history list                          //~vbi3I~
//vbd7:171119 "SEL all" support on file panel                      //~vbd7I~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vb4f:160802 (ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~vb4fI~
//vb2Y:160405 by vb2U string remains on screen when split screen or exit xe if ligature mode ON//~vb2YI~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vavQ:140405 set parsed cmdlc(for xprint dcmd u8filename)         //~vavQR~
//vaar:120101 over vaap;not by padding but position for ddfmt also for locale dbcs(contains "d")//~vaarI~
//vaan:111230 another way of vaak;column positioning by ddfmt(USDdata and USDdbcs)//~vaanR~
//va7M:100905 bin file vhex mode;csr was step down(reason was duplicated code definition)//~va7MI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va3b:100205 (GXE)no ligature for hex edit(HEX mode and EH cmd)   //~va3bI~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          header line filename cv f2l                            //~va00I~
//          cmdline may be mixed of utf8 and locale code           //~va00I~
//          select cmd chk cpu8/cplc of dir open parm              //~va00I~
//v79T:081028 Gunxflag setup required for sedbcstbl from functinit;move to xe.c from xescr.c//~v79TI~
//v79R:081027 (BUG)dbcs evaluation required when graphic char input specification is by hex notation//~v79RI~
//v8@Z:080715 3270:TSO keyboard mode by A+q                        //~v8@ZI~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v780:080212 syntaxhighlight support                              //~v780I~
//v77L:080206 (BUG)EXE cmd ABEND when "END" cmd closed all panel   //~v77LI~
//v778:071204*(BUG)after hex input by C+F11,dbcstbl recalc required//~v778I~
//v777:071204*EUC hankana chk(2byte but 1 column) hankana input not avail on rh9 but on fc5//~v777I~
//v768:070613 new RCTL option(Enter->Execute,Rctl->NewLine)        //~v768I~
//v75J:070509 "g"(grep) dlcmd support                              //~v75JI~
//v69F:060710 (LNX:BUG)box drawing not avail(use acs)              //~v69FI~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~v670I~
//v65c:050728 (XXE)8 color->16 color                               //~v65cI~
//v64h:050619 (LNX)xxe support;abondon v64g to share xe_save_ with non xxe version(Gpalette is saved and restored)//~v64hI~
//v64g:050619 (LNX)xxe support;color-no 8-->16                     //~v64gI~
//v64a:050618 (LNX)xxe support                                     //~v64aI~
//v60v:050201 virtual hex display option(/Mx,HEX on/off,prev HEX is XIN)//~v60vI~
//v603:041220 multiline errmsg support(for find help msg)          //~v603I~
//v557:040203 filename list multi-page support                     //~v557I~
//v53m:030928 (LNX)mouse support                                   //~v53mI~
//v51V:030808 v51A if for UNX;for WXE abend when scr size is shorten.//~v51VI~
//            (us Gscrbuffwidth for other than WXE)                //~v51VI~
//v500:020827 wxe support                                          //~v500I~
//v47r:020315 screen width  parm support(/Wnn)                     //~v47mI~
//v47m:020309 screen height parm support(/Hnn)                     //~v45mI~
//v45k:001015 UNX for hex mode,dbcs clear only when update,simple write when cursor move//~v45kI~
//v20n:001015 LINUX support(fix max color=8)                       //~v190I~
//v190:000902 LINUX support(CRLF)                                  //~v190I~
//v11Q:990904 keep csr pos when csr is on cols line for pgright/left//~v11QI~
//v11N:990829 COL cmd support                                      //~v11NI~
//v0im:980627 pfk cmd support(long cmd ove screenwidth)            //~v0imI~
//v08l:961123:edit/browse line range parameter                     //~v08lI~
//v08e:961104:(W95)performance up                                  //~v08eI~
//                cell setup by char string and WORD attr table    //~v08eI~
//v08d:961104:(W95)performance up                                  //~v08dI~
//v075:960608:color option                                         //~v075I~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//v061:960211:SHELL cmd(CMD,COM,>>)                             //~v061I~
//v05O:960120:copy/move cmd *\(same as source) / **\(parent of source) support//~v05OR~
//            sub.c dlcmd3.c dcmd.c                             //~v05OI~
//v056:951015:general DOS command                               //~v056I~
//*v032:950712:UFLD for each ppc                                //~v032I~
//*v020:950611:dir support(prot fld only line)                  //~5611I~
//*     950616:field full condition intercept                   //~v020I~
//*     950701:field clear condition intercept                  //~v020I~
//****************************************************************
//*macro****                                                    //~v069I~
                                                                   //~v190I~
#ifdef UNX                                                         //~v190I~
  #ifdef XXE                                                       //~v65cR~
	#define MAX_COLOR  16                                          //~v65cR~
  #else                                                            //~v65cR~
    #define MAX_COLOR  8                                           //~v190I~
  #endif                                                           //~v65cR~
#else //!UNX                                                       //~v190I~
    #define MAX_COLOR 16                                           //~v190I~
#endif//!UNX                                                       //~v190I~
                                                                   //~v190I~
//*check csr is on file line area or not                        //~v069M~
#define CSRONFILEDATA(pcw) \
    (pcw->UCWrcsry>=pcw->UCWfilehdrlineno && pcw->UCWrcsry<pcw->UCWmaxline \
    && pcw->UCWrcsrx>=(int)pcw->UCWlinenosz)                    //~v069I~
//  (pcw->UCWrcsry>CMDLINENO && pcw->UCWrcsry<pcw->UCWmaxline      //~v11NI~
#define GPOSONFILEDATA(pcw,row,col) \
    ((row)-pcw->UCWorgy>=pcw->UCWfilehdrlineno && (row)-pcw->UCWorgy<pcw->UCWmaxline \
    && (col)-pcw->UCWorgx>=(int)pcw->UCWlinenosz)                  //~va3bI~
#define RPOSONFILEDATA(pcw,row,col) \
    ((row)>=pcw->UCWfilehdrlineno && (row)<pcw->UCWmaxline \
    && (col)>=(int)pcw->UCWlinenosz)                               //~va3bI~
                                                                //~v069M~
//*check csr is on file line/lineno area or not                 //~v069M~
#define CSRONFILELINE(pcw) \
    (pcw->UCWrcsry>=pcw->UCWfilehdrlineno && pcw->UCWrcsry<pcw->UCWmaxline)//~v11NI~
//  (pcw->UCWrcsry>CMDLINENO && pcw->UCWrcsry<pcw->UCWmaxline)     //~v11NR~
#define GPOSONFILELINE(pcw,row) \
    ((row)-pcw->UCWorgy>=pcw->UCWfilehdrlineno && (row)-pcw->UCWorgy<pcw->UCWmaxline)//~va3bI~
#define RPOSONFILELINE(pcw,row) \
    ((row)>=pcw->UCWfilehdrlineno && (row)<pcw->UCWmaxline)        //~va3bI~
                                                                //~v069M~
#define CSRONFILEDATA_COLS(pcw) \
    (pcw->UCWrcsry>CMDLINENO && pcw->UCWrcsry<pcw->UCWmaxline   \
    && pcw->UCWrcsrx>=(int)pcw->UCWlinenosz)                       //~v11QI~
                                                                   //~v11QI~
#define CSRONFILELINE_COLS(pcw) \
    (pcw->UCWrcsry>CMDLINENO && pcw->UCWrcsry<pcw->UCWmaxline)     //~v11QI~
                                                                   //~v11QI~
//***********************************************                  //~v075I~
//**screen line display data 
typedef struct _USCRD {
                        UCHAR   USDcbid[4];                     //~5105I~
#define USDCBID         "USD "                                  //~5105I~
                        int     USDrow;         //screen row
                        UCHAR   USDflag;        //flag
#define USDFCELLSTR     0x01                    //use VioWrtNCellStr
#define USDFCHARSTR     0x02                    //use VioCharStr
#define USDFCHARSTRATT  0x03                    //use VioWrtCharStrAtt
#define USDFNATTR       0x04                    //use VioWrtNattr
#define USDFNCELL       0x05                    //use VioWrtNcell
#define USDFNCHAR       0x06                    //use VioWrtNchar
#ifdef W32                                                         //~v08eI~
    #define USDFCELLSTR2 0x07                   //use attr WORD table//~v08eI~
#endif                                                             //~v08eI~
#ifdef UTF8SUPPH                                                   //~va00I~
  #define USDFCELLSTR3  0x08                     //use SDcell as attr byte table//~va00I~
#endif                                                             //~va00I~
                        UCHAR   USDflag2;       //flag
#define USDF2DRAW       0x01                    //redraw req
#define USDF2PROTFHDR   0x02                    //for file 2nd fld prot
#define USDF2PROT       0x04                    //line fully protected
#define USDF2CMD        0x08                    //cmd line
#define USDF2PROTONLY   0x10                    //prot fld only v020//~5611I~
#define USDF2CSRLINE    0x20                    //csr line for file scr//~v45kI~
#define USDF2VHEXLINE1  0x40                    //virtical hex display line1//~v60vI~
#define USDF2VHEXLINE2  0x80                    //virtical hex display line2//~v60vI~
                        UCHAR   USDnattr0;      //additional nattr data
                        UCHAR   USDnattr;       //attr data for nattr
                                                                   //~vbi3I~
                        UCHAR   USDflag3;       //attr data for nattr//~v780I~
#define USDF3SYNTAX     0x01                    //draw by syntax highlight//~v780I~
//#define USDF3NOLIGATURE 0x02                    //non ligaturemode//~vb4fR~
//#define USDF3DDFMT      0x02                    //dd fmt for cmdline when containing utf8 code//~vaanR~//~vaarR~
//                      UCHAR   USDrsv[3];                         //~vb4fR~
//                      UCHAR   USDuvioo;       //UVIOO_XX for ligature/combine line by line(see uviom.h)//~vb4fI~//+vbmiR~
//                      UCHAR   USDrsv[2];                         //~vb4fI~//+vbmiR~
                        UCHAR   USDrsv[1];                         //+vbmiR~
                        USHORT  USDuvioo;       //UVIOO_XX for ligature/combine line by line(see uviom.h)//+vbmiR~
                        int     USDlen;         //write len for data
                        int     USDoff;         //write data offset
                        int     USDnattr0len;   //additional nattr len
                        int     USDnattr0off;   //additional nattr offset
                        int     USDcell0len;    //additional cell datalen
                        UCHAR  *USDcell;        //display cell data
                        UCHAR  *USDdata;        //string data
                        PVOID   USDppd;         //UPANELD
                        PVOID   USDpfld;        //UFLD          //~v032I~
                        PVOID   USDbuffc;       //line buff or ULINEH
                        UCHAR  *USDdbcs;        //dbcs id tbl ptr
                        UCHAR  *USDstyle;       //style data       //~v780I~
                        int     USDddfldlen;    //for cmdline ddfmt len fom fld start pos//~vaanI~
                        } USCRD;
typedef USCRD  *PUSCRD;
#define USCRDSZ (sizeof(USCRD))

#ifdef XESCR_GLOBAL                                                //~v500I~
//  #ifdef WXE                                                     //~v51VR~
        int Gscrbuffheight=0;   //buff max size,row                //~v500I~
        int Gscrbuffwidth=0;      //buff max size,col              //~v500I~
//  #endif                                                         //~v51VR~
    int   Gscropt=0;      //displey req 2nd line of multiline errmsg//~v603R~
#else                                                              //~v500I~
//  #ifdef WXE                                                     //~v51VR~
        extern int Gscrbuffheight;   //buff max size,row           //~v500I~
        extern int Gscrbuffwidth;      //buff max size,col         //~v500I~
//  #endif                                                         //~v51VR~
    extern int   Gscropt;      //displey req 2nd line of multiline errmsg//~v603R~
#endif                                                             //~v500I~
#define GSCROPT_MULTILINENEXTREQ    0x01   //request 2nd line display//~v603R~
#define GSCROPT_MULTILINEPENDING    0x02   //multiline msg diplay pending//~v603I~
//********************************************
//**client work element
typedef struct _UCLIENTWE{
                        UQUEE   UCWqelem;       //que chain
                        UCHAR   UCWcbid[4];                     //~5105I~
#define UCWCBID         "UCW"                                   //~5122R~
                        int     UCWsplitid;     //split part no
                        int     UCWtype;        //client type
#define UCWMAXTYPE      3                       //client type count//~v020R~
#define UCWTMENU        0                       //client type:panel     
#define UCWTFILE        1                       //client type:UFILEH    
#define UCWTDIR         2                       //client type:UDIRLH//~v020I~

                        UCHAR   UCWflag;        //client flag
#define UCWFDRAW        0x01                    //redraw need
#define UCWFWAKEUP      0x02                    //activate req
#define UCWFCMDERR      0x04                    //command err
#define UCWFRESIZE      0x08                    //command err      //~v500I~
#define UCWFCSRDOWN     0x10                    //csr down after draw//~5423I~
#define UCWFCSRRIGHT    0x20                    //csr right after draw//~5423I~
#define UCWFFIELDFULL   0x40                    //pan field full//~v020I~
#define UCWFNODOSCMD    0x80                    //parm from func_cmd to func_dos//~v056I~
                        UCHAR   UCWkeytype;     //key type
#define UCWKTEXTKEY     0                       //extended key  //~5225I~
#define UCWKTSBCS       1                       //SBCS          //~5225I~
#define UCWKTDBCS       2                       //DBCS          //~5225I~
#define UCWKTSCRDRAW    3                       //intarnaly draw func call//~5225I~
#define UCWKTCMD        4                       //cmd line input process//~5225I~
#define UCWKTMOUSE      5                       //cmd line input process//~v53mI~
#define UCWKTFUNCID     6                       //kbdproc request to call by funcid//~v768I~
#ifdef FTPSUPP                                                     //~v8@ZR~
#define UCWKT3270KBD    7                       //TSO 3270KEY operation//~v78ZR~
#endif                                                             //~v8@ZI~
#define UCWKTUTF8STR    8                       //utf8 string input//~v78ZI~
                                                                   //~v778I~
                        UCHAR   UCWflag3;       //                 //~v778I~
#define UCWF3HEXKBD     0x01                    //char input by hex kbd mode(C+F11)//~v778I~
#define UCWF3EXECMD     0x02                    //protect free(exe cmd owner)//~v77LI~
#ifdef FTPSUPP                                                     //~v8@ZR~
#define UCWF33270KBD    0x04                    //3270kbd mode     //~v78ZI~
#define UCWF33270KBD2   0x08                    //3270kbd mode,more emulater mode//~v8@ZI~
#endif                                                             //~v8@ZI~
#define UCWF3HEXKBDGC   0x10                    //input is hex notation graph char//~v79RI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
#define UCWF3HEXKBDUCS4 0x20                    //3byte ucs        //~va3xR~
#endif                                                             //~va3xI~
#define UCWF3HEXKBDUCS2 0x40                   //2byte ucs         //~va3xI~
#define UCWF3FINDCMD    0x80                   //apply find cmd of UCWfindcmd//~vbCBR~
                        UCHAR   UCWflag2;       //for utf          //~v778I~
#ifdef UTF8SUPPH                                                   //~va00I~
#define UCWF2SETFLD     0x01                    //parm to setflddata//~va00R~
#define UCWF2CMDGETU8   0x02                    //parm to getfldpos;select utf8code cmd//~va00I~
#define UCWF2UTF8STR    0x04                    //UCWkeydata_utf8str was set//~va00R~
#define UCWF2CMDSETU8   0x08                    //parm to setflddata;cv l2f then set utf8//~va00I~
#define UCWF2SELECTCMD  0x10                    //select member cmd;chk utf8 option from dirlist//~va00I~
#define UCWF2CMDLINEDD  0x20                    //dd fmt for cmdline when containing utf8 code//~vaarI~
#endif                                                             //~va00I~
                                                                   //~va00I~
#ifdef UTF8SUPP                                                    //~v778M~//~va00I~
#define UCWF2U8         0x01                    //input is utf8mode(contains l2u and u8 prefix cmd,dosenot contain filecp)//~v916R~//~va00I~
#define UCWF2U8CMD      0x04                    //by U8 cmd        //~v90xR~//~va00I~
#define UCWF2LCCMD      0x08                    //by LC cmd        //~v90xR~//~va00I~
#define UCWF2UTF8CHAR   0x10                    //kbd input by utf8 char//~v910I~//~va00I~
#define UCWF2CPFILEL2U  0x20                    //u8 or lc is by CPFILE option//~v916R~//~va00I~
#define UCWF2CPFILEU2L  0x40                    //u8 or lc is by CPFILE option//~v916I~//~va00I~
#define UCWF2CPFILEASIS 0x80                    //no conv by cpfile option//~v91yI~//~va00I~
#endif                                                             //~va00I~
                                                                   //~v778I~
#ifndef UTF8SUPPH                                                  //~va1cI~//~va1qR~
                        UCHAR   UCWkeydata[2];  //key data 1 or 2 byte//~va00R~//~va1cR~//~va1qR~
#else                                                              //~va1cI~//~va1qR~
                        UCHAR   UCWkeydata[MAX_MBCSLENLC];  //key data 1 or 2 byte,or 4 byte for GB18030//~va00I~//~va1qR~
#endif                                                             //~va1cI~//~va1qR~
#ifdef UTF8SUPPH                                                   //~va00I~
#ifdef WCSUPP                                                      //~va00I~
                        UCHAR   UCWkeydata_utf8str[UTF8_MAXCHARSZMAX+1]; //by utf8//~va00I~
                        UCHAR   UCWnls;			//nls support		//~va1cR~
#endif                                                             //~va00I~
#endif                                                             //~va00I~
                        USHORT  UCWkeyshift;    //shift status
                        UCHAR   UCWmenuopt;     //v020:for file panel//~5611R~
                        UCHAR   UCWreason;      //additional return info//~v05OR~
#define UCWRDRAWCSRMOVE  1  //parm to func_draw_file:draw file header only//~v08dI~
#define UCWRDRAWSAMELINE 2  //parm to func_draw_file:draw same line only//~v08dI~
#define UCWRCMDSET     0x71 //parm to func_exec_pan from dlcmd_grep//~v75JI~
#define UCWREASON_HEXSTEP   0x81    //csr step over intermediate space//~va7MI~
#define UCWREASON_HEXSTEPDEL   0x82 //delete hex part shift to left//~va7MI~
#define UCWREASON_DELEOLGB4    0x83 //join by delete end of line,gb4 case//~va7MI~
#define UCWREASON_VHEX1STEP    0x84 //rep/ins on vhex upper line   //~va7MI~
#define UCWREASON_VHEX2STEP    0x85 //rep/ins on vhex lower line   //~va7MI~
//#define UCWREASON_CSRBYKEYTYPE 0x84	//step by keytype              //~v777I~//~va7MR~
#define UCWREASON_CSRBYKEYTYPE 0x86	//step by keytype              //~va7MI~
#define UCWREASON_CHLSPLIT     0x88	//cmd history list char cmd,set other split//~vbi3I~
#define UCWREASON_CHLNOSPLIT   0x89	//cmd history list char cmd,set my split//~vbi3I~
                        int     UCWwidth;       //client screen width
                        int     UCWheight;      //client screen hight
                        int     UCWmaxline;     //min(height,defined on ppc)//~v11NR~
                        int     UCWfilehdrlineno;//header line count for FILE/DIR//~v11NI~
                        int     UCWorgx;        //absolute cursor pos-x
                        int     UCWorgy;        //absolute cursor pos-y
                        int     UCWrcsrx;       //relative cursor pos-x
                        int     UCWrcsry;       //relative cursor pos-y
                        int     UCWvsplitx;     //save before csrhome//~5527R~
                        int     UCWfleno;       //char input UFLDE index//~4C29I~
                        int     UCWopdno;       //cmd operand number//~v08lI~
                        UCHAR  *UCWopdpot;      //cmd operand parseout string tbl//~v08lI~
                        PVOID   UCWopddelmt;    //cmd operand delm table//~v08lR~
                        PVOID   UCWppc;         //panel control
                        PVOID   UCWpfc;         //file client
                        PUSCRD  UCWpsd;         //USCRD ptr
                        UCHAR  *UCWparm;        //parm ptr      //~v032R~
                        PVOID   UCWpfunct;      //func table
                        UCHAR   UCWlinenosz;    //lineno field size//~v069R~
                        int     UCWtopfnlist;   //page top line filename list entryno//~v557R~
                        int     UCWoldheight;   //previous scr height to chk redraw fnmlist//~v557I~
                        int     UCWseqno;       //instance id for cmd history retrieve//~v670I~
                        int     UCWcmdLClen;                       //~vavQI~
                        PVOID   UCWcmddelmtLC;  //cmd operand delm table cmd by lc//~vavQR~
                        char   *UCWcmdLC;       //cmd by lc from cmd verb//~vavQI~
                        char   *UCWcmdCT;       //ct for cmdLC     //~vavQR~
                        void   *UCWfindcmd;     //PUSCMD:pcw specific find cmd//~vbCBR~
                        char    UCWcmdverb[4];  //cmd verb to srch funct//~vbd7R~
                        } UCLIENTWE;
typedef UCLIENTWE  *PUCLIENTWE;
#define UCLIENTWESZ (sizeof(UCLIENTWE))

//****************************************************************
//int scrinit(int Pheightparm);                                    //~v47rR~
int scrinit(int *Pscrparm);                                        //~v47rI~
                                                                //~5430I~
//****************************************************************
int scrterm(void);
                                                                //~5430I~
//****************************************************************//~4C23I~
int scrreset(void);                                             //~4C23I~
                                                                   //~v0imI~
//****************************************************************//~v061I~
int scrcls(char *Ppcell);                                       //~v061R~
                                                                   //~v0imI~
//****************************************************************
int scrdisp(void);

//****************************************************************
PUCLIENTWE scrregist(UCHAR Pclienttype,PVOID Pctl);

//****************************************************************
PUCLIENTWE scrgetcw(int Pclientid);

//****************************************************************//~5228I~
PUCLIENTWE scrpopup(PUCLIENTWE Ppcw,PUCLIENTWE *Pppcw);         //~5228I~

//****************************************************************
void scrresize(PUCLIENTWE Ppcw);

//****************************************************************
PUCLIENTWE scrfulldraw(PUCLIENTWE Ppcw);
                                                                //~5224I~
//****************************************************************//~5224I~
void screnqcw(int Psplitid,PUCLIENTWE Ppcw,int Ppos,PUCLIENTWE Ppcwt);//~v032I~
                                                                //~5224I~
//****************************************************************//~5224I~
PUCLIENTWE scrdeqcw(int Psplitid,int Pfreereq,PUCLIENTWE Ppcw); //~5224I~
                                                                //~5224I~
//**************************************************            //~5224I~
PUCLIENTWE scrsrchcw(int Psplitid,int Ppanid);                  //~5224I~
                                                                   //~v075I~
//**********************************************                   //~v075I~
void scrsetattrtbl(UCHAR *Pattrtbl,UCHAR *Ppnotbl);                //~v075R~
                                                                   //~v075I~
//**********************************************                   //~v075I~
int scrsetpallette(UCHAR *Ppallette);                              //~v075I~
                                                                   //~v08eI~
#ifdef W32                                                         //~v08eI~
//**************************************************************** //~v08eI~
USHORT *scrw95getattrtbl(USHORT Pattr);                            //~v08eI~
#endif                                                             //~v64aI~
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
//**************************************************************** //~v500I~
int scronsize(int Prow,int Pcol,int Pcpchngsw);                    //~v500R~
#endif                                                             //~v500I~
//#endif                                                           //~v64aR~
#ifdef LNX                                                         //~v69FI~
	int scracssetup(int Popt);                                     //~v69FR~
	int scrsetunxflag(int Popt);                                   //~v79TI~
#endif                                                             //~v69FI~
//**************************************************************** //~vbd7I~
PUCLIENTWE scrsrchcwchl(int Popt,int Psplitid);                    //~vbd7I~
