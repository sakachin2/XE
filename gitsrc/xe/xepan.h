//*CID://+vav9R~: update#=   62;                                   //+vav9R~
//****************************************************************
//xepan.h                                                       //~v032R~
//************************************************************* //~5610I~
//vav9:140410 (Win)unicode support(UD fmt string,_MAX_PATH changes)//+vav9I~
//vaa3:110926 (WXEXXE:BUG)mouse lineselect on top menu,row count was changed;//~vaa3I~
//va5v:100516 display util fnm by dd fmt                           //~va5vI~
//va3K:100316 allow unicode hex input on cmdline                   //~va3KI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va0x:090920!kbd mode change(A+u)                                 //~va0xI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          cmdline may be mixed of utf8 and locale code           //~va00I~
//va04:090606 expand cmdbuff to include max_path                   //~va04I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v730:061225 use UPLbuff for cmdline(to display as long as possible if del key used, and accept insert over screen width)//~v730I~
//v64i:050619 (LNX)xxe support;scr width                           //~v64iI~
//v59T:041207 dirlist resizeing                                    //~v59TI~
//v557:040203 filename list multi-page support                     //~v557I~
//v54v:040114 display and select by cursor the driveid list.       //~v54vI~
//v500:020827 wxe support                                          //~v500I~
//v20y:001028 new function:filename selection on menu 1/2 name list//~v20yI~
//v20u:001022 LINUX support(drop drive line from filename panel)   //~v20uI~
//v0ja:980721 change define value by change opt start from 0.0     //~v0jaI~
//v0iw:980718 pfk cmd support(del 0.5,cmd change by ini only)      //~v0iwI~
//v0io:980702 pfk cmd support(opt 0.4)                             //~v0ioI~
//v0im:980625 pfk cmd support(optk1 and optk2)                     //~v0imI~
//v0if:980620 pfk cmd support                                      //~v0ifI~
//v09i:970517:rename field length 12->14 for quatation             //~v09iI~
//v075:960608:color option                                         //~v075I~
//v06n:960320:menu option 6(cmd) support                        //~v06nI~
//*v032:950712:UFLD for each ppc(add UFLD ptr to ppc)           //~v032I~
//*v020:950610:dir support                                      //~v020R~
//*     950616:reverse field err                                //~v020I~
//************************************************************* //~5610I~
//****************************************************************
#define PANCSRMODEPOS 4
//** panel id ***                                               //~5611M~
#define  PANTOPMENU   0                                         //~5611M~
#define  PANOPTCOLOR 10                                            //~v06nI~
#define  PANFBROWSE 100                                         //~5611M~
#define  PANFEDIT   200                                         //~5611M~
#define  PANFNAME   300                                         //~v020R~
#define  PANDIR     310                                         //~v020R~
#define  PANUTIL   0x200                                           //~v76gR~
#define  PANUCOMP  (PANUTIL+1)                                     //~v76gI~
#define  PANUGREP  (PANUTIL+2)                                     //~v76gR~
//** topmenu                                                       //~v79zI~
#define  PANL00PARM    3 	//0:PARM                               //~vaa3I~
#define  PANL00COLOR   4 	//0.0 COLOR                            //~vaa3I~
#define  PANL00SCCMD   5 	//0.1 SC-CMD                           //~vaa3R~
#define  PANL00F_K     6 	//0.2 FUNC-KEY                         //~vaa3R~
#define  PANL00K_F     7 	//0.3 KEY_FUNC                         //~vaa3R~
#define  PANL00BROWSE  8 	//1 BROWSE                             //~vaa3I~
#define  PANL00EDIT    9 	//2 EDIT                               //~vaa3I~
#define  PANL00UTIL   10 	//3 UTILITY                            //~vaa3I~
#define  PANL00COMP   11 	//3.12 COMPARE                         //~vaa3I~
#define  PANL00SRCH   12 	//3.14 SEARCH                          //~vaa3I~
#define  PANL00CMD    13 	//6 CMD                                //~vaa3I~
#define  PANL00CMDR   14 	//6 REMOTE CMD                         //~vaa3I~
#define  PANL00EXIT   15 	//X EXIT                               //~vaa3I~
#define  PANL00RET    16 	//R RETURN                             //~vaa3I~
#define  PANL00QUIT   17 	//Q QUIT                               //~vaa3I~
#define  PANL00LC     19	//locale display line                  //~v79zR~
//** for color opt panel lineno/fieldno ***                        //~v075I~
#define  PANL10PAL     6	//pallette line start                  //~v075R~
#define  PANL10PALTI   6	//title                                //~v075R~
#define  PANL10PALFR   7	//frame                                //~v075I~
#define  PANL10PALBL   8	//browse lineno line                   //~v075I~
#define  PANL10PALEL  10	//edit   lineno line                   //~v075I~
#define  PANL10PALDL  12	//dirlist lineno line                  //~v075R~
#define  PANL10PALCL  15	//cmdout lineno line                   //~v075I~
#define  PANL10PALCR  16	//cmdout result line                   //~v075I~
#define  PANL10PALEND 16	//palno last line                      //~v075I~
#define  PANL10COLS   20	//color sample                         //~v075I~
#define  PANL10COL    21	//color value line                     //~v075R~
#define  PANL10COLC   22	//color value line current             //~v075R~
#define  PANL10COLD   23	//color value line default             //~v075R~
#define  PANL10LAST   23	//color value default                  //~v075R~
#define  PANF10PALFG   0	//update FG                            //~v075I~
#define  PANF10PALBG   1	//update BG                            //~v075I~
#define  PANF10PALCFG  2	//current FG                           //~v075I~
#define  PANF10PALCBG  3	//current BG                           //~v075I~
#define  PANF10PALSAMP 4	//sample field                         //~v075I~
//** for panel 300 lineno/fieldno ***                           //~v020I~
                                                                   //~v20uI~
#ifdef UNX                                                         //~v20uI~
    #define  PANL300FILENAME 3  //filename  lineno                 //~v20uI~
    #define  PANL300DIR      4  //directory lineno                 //~v20yR~
    #define  PANL300CURRENT  5  //current dir lineno               //~v20yR~
    #define  PANL300PAGENO   6  //pageno display line              //~v557R~
    #define  PANL300LISTTOP  7  //latest filename list             //~v557I~
#else  //!UNX                                                      //~v20uI~
                                                                   //~v20uI~
#define  PANL300FILENAME 3	//filename  lineno                  //~v020R~
#define  PANL300DRIVE    4	//driveid   lineno                     //~v20yR~
	#define  PANF300DRIVEID           0	//driveid input fldno      //~v54vR~
	#define  PANF300DRIVEIDLIST       1	//drivelist fieldno        //~v54vR~
#define  PANL300DIR      5	//directory lineno                     //~v20yR~
#define  PANL300CURRENT  6	//current dir lineno                   //~v20yR~
    #define  PANL300PAGENO   7  //pageno display line              //~v557I~
    #define  PANL300LISTTOP 8   //latest filename list             //~v20yR~
                                                                   //~v20uI~
#endif //!UNX                                                      //~v20uI~
                                                                   //~v20yI~
#define  PANL300LCMD     0	//filename  fieldno                    //~v20yI~
#define  PANL300NAME     1	//filename  fieldno                    //~v20yI~
                                                                   //~v20yI~
//** for panel 310 fieldno/fldlen ***                           //~v032R~
#define  PANL310LINENO   0	//filename  lineno                  //~v032I~
#define  PANL310ATTR     1	//driveid   lineno                  //~v032I~
#define  PANL310RENAME   2	//directory lineno                  //~v032I~
//#define  PANL310MASKLEN  12	//file mask field len              //~v09iR~
#define  PANL310MASKLEN  14	//file mask field len                  //~v09iI~
                                                                   //~v76gI~
                                                                   //~v76gI~
#define  PANLUHDRFLD    0	//header field to set reverse cursor line//~v76gI~
#define  PANLUDATAFLD   1	//data                                 //~v76gI~
#define  PANLUCDIRFLD   0	//current dir set fld                  //~v76gR~
                                                                   //~v76gI~
#define  PANLUCOPT       3	//compare panel option  line           //~v76gI~
#define  PANLUCCDIR      5	//compare panel cur dir line           //~v76gI~
#define  PANLUCFILE1     7	//compare panel file1   line           //~v76gI~
#define  PANLUCFILE2     9	//compare panel file1   line           //~v76gI~
                                                                   //~v76gI~
#define  PANLUGOPT       3	//grep    panel option1 line           //~v76gR~
#define  PANLUGCDIR      5	//grep    panel cur dir line           //~v76gR~
#define  PANLUGFILE1     7	//grep    panel filespec1              //~v76gR~
#define  PANLUGFILENO   15	//              last line              //~v76gR~
#define  PANLUGFILELAST 21	//              last line              //~v76gR~
//** menu option id ***                                         //~v020R~
#define  PANMOPARM   '0'                                           //~v075I~
#define  PANMOPARM_COLOR "0.0"         //color                     //~v0iwR~
#define  PANMOPARM_KCMD  "0.1"         //key cmd                   //~v0jaR~
#define  PANMOPARM_FKEY  "0.2"         //function and key          //~v0jaR~
#define  PANMOPARM_KLIST "0.3"         //key and function          //~v0jaI~
#define  PANMOPARM_UCOMP "3.12"        //compare                   //~v76gI~
#define  PANMOPARM_UGREP "3.14"        //grep                      //~v76gI~
//#define  PANMOPARM_FKEY4 "0.5"         //function and key        //~v0iwR~
#define  PANMOPARMFK_KCMD  'A'         //pfk cmd                   //~v0jaR~
#define  PANMOPARMFK_FKEY  'B'         //func-key assign           //~v0jaR~
#define  PANMOPARMFK_KLIST 'C'         //key-func list             //~v0jaI~
#define  PANMOPARM_UCOMPID 'F'         //abreviation of 3.12       //~v76gI~
#define  PANMOPARM_UGREPID 'G'         //abreviation of 3.14       //~v76gI~
//#define  PANMOPARMFK4 'D'         //func-key assign              //~v0iwR~
#define  PANMOBROWSE '1'                                        //~v020R~
#define  PANMOEDIT   '2'                                        //~v020R~
#define  PANMOFILE   '3'                                        //~v020R~
#define  PANMOCMD    '6'                                        //~v06nI~
//*********************************
//*pannell input field definition
typedef struct _UFLDE  {							//field def
						UCHAR     UFLfieldno; 	//field seqno   //~v032I~
						UCHAR     UFLflag;    	//field start   //~v032R~
#define UFLEFPROT       0x01                    //protected fld //~5611I~
						int       UFLstart;   	//field start
						int       UFLend;       //next prot field
					  	} UFLDE;
typedef struct _UFLD  {							//field def
                        UCHAR     UFLcbid[4];   //acronym       //~5105I~
#define UFLCBID  "UFL"                                          //~5225R~
						int       UFLctr;		//fld count
						UFLDE     UFLentry[1];
					  } UFLD;
typedef UFLD    *PUFLD;
#define UFLDSZ   (sizeof(UFLD))
#define UFLESZ   (sizeof(UFLDE))

//*menu data deffinition table
typedef struct _UPANELD{						//file cwe
						UCHAR    *UPDdatadef;	//display data
						int       UPDprottype;  //full line prot type
						UCHAR    *UPDprotdef;	//protection attr tbl
						UCHAR    *UPDdata;		//line width data
						UCHAR    *UPDdbcs;		//dbcs id tbl
						PUFLD     UPDpfld;   	//UFLD
					  	} UPANELD;
typedef UPANELD *PUPANELD;
#define UPANELDSZ (sizeof(UPANELD))

//*client work element for MENU *********************************
typedef struct _UPANELL {						//MENU cwe
						UCHAR    *UPLbuff;      //input line buff ptr
						UCHAR    *UPLdbcs;      //dbcs id tbl ptr
#ifdef UTF8SUPPH                                                   //~va00I~
//  #define UPLBUFF2SZ  (_MAX_PATH+30/*fldoffs*/)  //length for UPLbuffbyutf8 and UPLcodetype//~va1cR~
//  #define UPLBUFF2SZNET (_MAX_PATH*UTF8_F2LMAXRATE)              //~va1cR~//+vav9R~
    #define UPLBUFF2SZNET (_MAX_PATHF2L)                           //+vav9I~
    #define UPLBUFF2SZ  (UPLBUFF2SZNET+30/*fldoffs*/)  //length for UPLbuffbyutf8 and UPLcodetype//~va1cR~
                        ULONG     UPLflags;                        //~va00I~
    #define   UPLFUTF8            0x0001         //UPLbuffbyutf8 contains UTF8 code//~va00I~
						char     *UPLbuffbyutf8;//utf8le code type //~va00M~
//  					int       UPLctlen;     //codetype tbl len //~va00R~
						char     *UPLcodetype;  //locale code type //~va00I~
#endif                                                             //~va00I~
                        PUFLD     UPLpfld;      //ufld ptr      //~v032I~
                        ULONG     UPLerrflag;//max 32 field err flag//~v020R~
					  	} UPANELL;
typedef UPANELL *PUPANELL;
#define UPANELLSZ (sizeof(UPANELL))
#define UPANLINEMAXFLD  (sizeof(ULONG)*8)                       //~v020R~

typedef struct _UPANELC {						//MENU cwe
                        UCHAR     UPCcbid[4];   //acronym       //~5105I~
#define UPCCBID         "UPC "                	//acronym       //~5105I~
						UCHAR     UPCflag;		//flag
#define UPCFSCROLLINPUT	0x01                   	//scroll input
#define UPCFSCROLLERR  	0x02                   	//scroll input err
#define UPCFWAKEN      	0x04                   	//once waked       //~v76gI~
#define UPCFRESIZE     	0x08                   	//resized   at ppdinit resize//~v76gI~
#ifdef UTF8SUPPH                                                   //~va00I~
#define UPCFCMDTYPED   	0x10                   	//kbd typed on cmdline//~va00I~
#ifdef FFF                                                         //~va00I~
#define UPCFCMDUTF8  	0x20                   	//data on UPCcmddatabyutf8//~va00R~
#endif                                                             //~va00I~
#endif                                                             //~va00I~
						UCHAR     UPCfiller[3]; //rsv
						int       UPCid;		//menuid
						int       UPClineno;	//line No
						int       UPCscroll;	//scroll unit
#define UPCSCROLLPAGE	-1                   	//scroll page size
#define UPCSCROLLHALF	-2                   	//scroll half page size
#define UPCSCROLLCSR 	-3                   	//scroll by csr position//~5204I~
#define UPCSCROLLMAX 	-4                   	//scroll max    //~5527I~
						UCHAR    *UPCcmddata;	    //cmd line input buff for utf string//~v730I~
						UCHAR    *UPCcmddbcs;	    //cmd line input buff for utf string//~v730I~
#ifdef UTF8SUPPH                                                   //~va00I~
						UCHAR    *UPCcmddatabyutf8; //by utf8 code //~va00I~
						UCHAR    *UPCcmdcodetb;     //code type tbl//~va00I~
#endif                                                             //~va00I~
						void     *UPCpandata;       //addtional data for each panel//~v76gR~
//#define UPCCMDFLDWKSZ   (MAXCOLUMN+4+4)            //cmd utf string save area size for "==>" and last strz and boundary//~v730I~//~va04R~
#define UPCCMDFLDWKNETSZ   MAXPARMSZ                 //by utfcharsz//~va00R~
#ifndef UTF8SUPPH                                                  //~va00R~
	#define UPCCMDFLDWKSZ   (MAXCOLUMN+4+4)            //cmd utf string save area size for "==>" and last strz and boundary//~va00I~
#else                                                              //~va00I~
#define UPCCMDFLDWKSZ   (4+UPCCMDFLDWKNETSZ)            //cmd utf string save area size;4 is for prefix "==>"//~va04R~
#endif                                                             //~va00I~
						UPANELD  *UPCppd;		//UPANELD   
						UPANELL   UPCline[1];   //panel line buff
					  	} UPANELC;
typedef UPANELC *PUPANELC;
#define UPANELCSZ (sizeof(UPANELC))

//****************************************************************//~v032I~
void paninit(void);                                             //~v032I~
                                                                //~v032I~
//****************************************************************
void panterm(void);

//****************************************************************
PUCLIENTWE panregist(int Pmenuid);                              //~5611R~
                                                                //~v032I~
//****************************************************************
PUPANELC pangetpc(int Ppanelid);
                                                                //~v032I~
//****************************************************************//~v032I~
void panfreepc(PUPANELC Pppc);                                  //~v032I~
                                                                //~v032I~
//****************************************************************
PUCLIENTWE panpopup(PUCLIENTWE Ppcw);

//****************************************************************//~5224I~
int panwakeup(PUCLIENTWE Ppcw);                                 //~5224I~
                                                                //~5318I~
//**************************************************            //~5611I~
int panlinetopfld(PUFLD Ppfl);                                  //~5611I~
                                                                //~v020I~
//**************************************************            //~v020I~
//*Preq flag                                                       //~v76gI~
#define PANFESET      1                                         //~v020R~
#define PANFERESET    0                                         //~v020R~
#define PANFEFORCE    0x0100   //set/reset if PANELL exit even over currents screen hight//~v76gR~
#define PANFEKEEPCSR  0x0200   //set/reset if PANELL exit even over currents screen hight//~v76gR~
//*Pline value                                                     //~v76gI~
#define PANFECSRLINE -1 	//field of csr line                 //~v020I~
int panflderr(PUCLIENTWE Ppcw,int Pline,int Pfldno,int Preq);   //~v020I~
                                                                //~v032I~
//**************************************************            //~v032I~
void pandirprot(PUFLD Ppfld,int Popt);                          //~v032I~
#define PANDPPROT 0 	//set protect                           //~v032I~
#define PANDPINP1 1 	//attr input                            //~v032I~
#define PANDPINP2 2 	//filename input                        //~v032R~
#define PANDPINP3 3 	//file mask                             //~v032I~
//**************************************************               //~v500I~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iI~
	int ppdinit_resize(PUCLIENTWE Ppcw);                           //~v500M~
#endif                                                             //~v500M~
//**************************************************               //~v59TI~
int pandirfldresize(PUCLIENTWE Ppcw,int Pexpandlen);               //~v59TI~
                                                                   //~va00I~
#ifdef UTF8SUPPH                                                   //~va00M~
//**************************************************               //~va00I~
	int pansetcmdcodeattr(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd,PUPANELC Pppc);//~va00M~
	void pansetinputmode(PUCLIENTWE Ppcw,PUSCRD Ppsd);             //~v916R~//~va0xI~
#endif                                                             //~va00M~
int pandrawxkbd(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd);             //~va3KI~
