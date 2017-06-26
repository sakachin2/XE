//*CID://+v9d0R~:                             update#=  192;       //+v9d0R~
//***************************************************************//~5B03I~
//* xp.h                                                           //~v91rR~
//***************************************************************//~5B03I~
//v9d0:170218 v9.37 from xe,xpr ** total page number is not valid  //+v9d0I~
//v9a2:160623 v9.34 issue msg "-qfile is not supported by gxp"     //~v9a2I~
//v993:160308 v9.32 ucs4 support                                   //~v993I~
//v992:150529 v9.31 uerrmsg parm count err by xuerpck              //~v992I~
//v990:140506 v9.30 (W32UNICODE) filename by UD fmt                //~v990I~
//v98q:140312 v9.29 print selected papersize                       //~v98qI~
//v98p:140219 v9.28 helpmsg print dbcs on xterm                    //~v98pI~
//v97p:131110 hexline monospace(vhex and hhex partially)           //~v97mI~
//v97m:131104 (gxp)header print err for utf8 filename;chk utf8 encoding for filename//~v97mI~
//v97h:131104 conjunct mode subheader should be monospace          //~v97hI~
//v97a:131027 -E/A4L/P P:rotate option for printer was not set to Landscape//~v97aI~
//v975:131022 (GtkPrint)option of scaling for each line if width overflow//~v975I~
//v970:130922 GtkPrint for alternative of Gnomeprint               //~v970I~
//v96z:130809 (BUG:LNX not gxp)EBCFILE ucs2local1 output utf8 when LANG=UTF8,ucvext_b2mDbcsstr cut by 2 byte each//~v96zI~
//            set EBCBYUCS(set dd to buff) and convert to utf8 at write//~v96zI~
//v96s:130804 (BUG)"xpr **" for ebcfile hhex; b2dd twice           //~v96sI~
//v96r:130804 (BUG)"xpr **" for ebcfile hhex+vhex; vhexline length is same as hhex line len//~v96rI~
//v96q:130804 (BUG)"xpr **" for ebcfile from xe;nor crlf is controled//~v96qI~
//v96n:130803 v9.25 Test option /ntu for test !(EBC)BYUCS          //~v96nI~
//v96m:130801 v9.25 Recordmode vhexdump print dbcs split           //~v96mI~
//v96i:130726 v9.25 add -EOLPRINT: option to identify eol of vfmt  //~v96iI~
//v96h:130726 v9.25 new -ICU option to support for EBC file on Windows//~v96hI~
//v96f:130725 v9.25 header shrink if record mode recordsz is too small//~v96fI~
//            xprint.c xp.h                                        //~v96fI~
//v96e:130724 v9.25 recfm=V(-Vvfmt) support                        //~v96eI~
//v96d:130618 findnext required dirname by ulib:v64k(win symlink support)//~v96dI~
//120629 v96a (Win:BUG)c: may be protected; use temp               //~v96aI~
//120629 v968 VC2010:LP64 support                                  //~v968R~
//101106 v962 V9.21(Win:BUG)if without /c for multiple file(wildcard) print,char-height shrink gradually//~v962I~
//101004 v960 option of hex dump by ucs/utf8 for utf8 (/Y8,/N8)    //~v960I~
//100923 v956 v9.20 (BUG) "too long line" err msg when from xe(xpr ** for ebc vhex mode. /Me oprion ignored)//~v956I~
//100909 v955 v9.19 print EBC file by TextOutW for avoid print "?" for trans err to locale code//~v955I~
//100908 v953 v9.19 EBC convertername support                      //~v953I~
//100706 v950 v9.18 64bit compile                                  //~v950R~
//100725 v945 v9.17 OSTYPE='G' for gxp                             //~v945I~
//100706 v944 (gxp)accept cups destination by -q parameter         //~v944I~
//            (use gtk because update of gpa_root by cups printer is done through asyncrronous gtk dispatching system)//~v944I~
//100428 v941 v9.16 ebcdic print support                           //~v941I~
//091215 v940 v9.15 unicode vhex line support by /WNU              //~v940I~
//090728 v93v v9.14 -cmax(max coloumn(=512)) parm for 1 output line/1 input line//~v93vI~
//080215 v92u (BUG)v9.13 ABEND when hex dump not UTF8mode          //~v92uI~
//080130 v92t (BUG)v9.12 help english spell check                  //~v92tI~
//071024 v92n (LNX)support utf8 file(conv to locale)               //~v92bI~
//            /Y3 optio to control SS3(0x8f) for EUC               //~v92nR~
//071006 v92b text mode vhex dump support                          //~v92bI~
//071005 v928 (Win)UTF8 support                                    //~v928I~
//070511 v927 (BUG)compile err by LONG long file size support      //~v927I~
//050606 v91x add /Nu option to bypass set 0x0c(form feed) for linux convenience//~v91xI~
//050511 v91v (BUG)help bug,-Y/Ne option defualt is Ye for also UNX//~v91vI~
//050309 v91r vhex print support for xe(/WN___X);line split and page eject//~v91rI~
//040605 v91n :no "*" on hdr fname when ftp(<xx>yy fmt)--versionno //~v91nI~
//020803 v91d ajust default cols/line table                        //~v91dI~
//020718 v911 form2p support(ex a42,b4l2). /y2 max col is of a4,b4l2 max col is of b5//~v911I~
//020703 v910 lineno and page continue opt by /I[x]xx-xx/[nn] parm //~v910I~
//020406 v9.3 v90v (WIN)Letter support(ZHnn) for the case drive setup is not work//~v90vI~
//011227 v90s another english mode keisen                          //~v90sR~
//011209 v90m :support stdout output                               //~v90mI~
//010527 v90k :2 page support for also not unx version             //~v90kI~
//010526 v90j :ScrPrt support(/WS=xxx(xxx=org filename))           //~v90jI~
//010521 v90g :LINUX support:double pageing                        //~v90gI~
//010521 v90e :(BUG)at uexit,free not yet malloced                 //~v90eI~
//010520 v90a :LINUX support(multifile seperater change from "/" to ":")//~v90aI~
//010519 v907 :LINUX support(cmd prefix,pgmid by lower case)       //~v907R~
//010402 v905 :newpage reset may not required when new windows version.//~v905I~
//            (Skip reset for each page when /Nr to page print speed up)//~v905I~
//010401 v904 :2 parts print suport for windows printer            //~v904I~
//            (no form parm for windows,auto pich calc by device info)//~v904I~
//990626 v886 :(WIN:BUG)coliumn gage too short,MAXCOLMAX=512       //~v886I~
//981024 v863 :(WIN)change keisen default                          //~v863I~
//981010 v857 :/Yk-->/Kx;x=0(through),g(graphic),k(katakana),any char//~v857I~
//981006 v852 :MAXLINEWIDTH*5 miss to MAXCOLMAX+LINENOSZ+10*5(need parethesys)//~v852I~
//980927 v844 :(WIN) /EW option(use Win32 API to use spool)        //~v844I~
//971129 v836 :GCC version                                         //~v836I~
//             xprint.c:putenv(LFN),chk lfn support                //~v836I~
//971124 v831 :split xppf from xprint                              //~v831I~
//971124 v830 :split xphex from xprint                             //~v830I~
//971123 v827 :split xpsub1 from xrint.c                           //~v827I~
//970208 v803:(BUG)header0 overflow when when fast print because   //~v803I~
//                 header0 has not yet pageno                      //~v803I~
//970206 v801:option to print files in a dir conjunctly            //~v801I~
//961108 v785:1st page EJECT bypass option                         //~v785I~
//961106 v783:Cannon printer support(LIPS-III)                     //~v783I~
//***************************************************************  //~v783I~
                                                                //~5B23I~
#ifdef OSTYPE                                                      //~v945I~
//    #ifdef GXP                                                     //~v945I~//~v950R~
//        #undef OSTYPE                                              //~v945I~//~v950R~
//        #define OSTYPE 'G'                                         //~v945I~//~v950R~
//    #endif                                                         //~v945I~//~v950R~
#endif                                                             //~v945I~
#define VER "V9.37"  //version                                     //+v9d0R~
#ifdef UNX                                                         //~v907I~
  #ifdef GXP                                                       //~v950I~
	#define PGMID   "gxp"                                          //~v950I~
  #else                                                            //~v950I~
	#define PGMID   "xprint"                                       //~v907I~
  #endif                                                           //~v950I~
#else                                                              //~v907I~
#define PGMID   "XPRINT"	//v4.9a                             //~5B23M~
#endif                                                             //~v907I~
                                                                //~5B23I~
//***************************************************************//~5B23I~
#ifdef  GLOBAL                                                     //~v941I~
  #define EXT                                                      //~v941I~
#else                                                              //~v941I~
  #define EXT extern                                               //~v941I~
#endif                                                             //~v941I~
//***************************************************************//~5B03I~
#ifdef UNX                                                         //~v907I~
	#define WKFDIR   "/tmp"		//page descending order print work file dir v5.3a//~v907I~
    #define MULTI_SEPS ":"      //multifile seperater              //~v90aR~
    #define MULTI_SEPC ':'      //multifile seperater              //~v90aI~
#else                                                              //~v907I~
  #ifdef W32                                                       //~v96aI~
	#define WKFDIR   ".\\"		//page descending order print work file dir v5.3a//~v96aI~
  #else                                                            //~v96aI~
	#define WKFDIR   "c:\\"		//page descending order print work file dir v5.3a//~v907I~
  #endif                                                           //~v96aI~
    #define MULTI_SEPS "/"      //multifile seperater              //~v90aR~
    #define MULTI_SEPC '/'      //multifile seperater              //~v90aI~
#endif                                                             //~v907I~
    #define MULTI_SEPCINDIRECT1  '\t' //multifile seperater for indirect file opt//~v941R~
    #define MULTI_SEPCINDIRECT2  '\n' //multifile seperater for indirect file opt//~v941R~
#define MAXESCCMD 256  //esccmd length v5.5a                       //~v886I~
#ifdef DOS  					//v7.0a                         //~5B23M~
	#define SYSTEM  "DOS"		//v7.0a                         //~5B23M~
	#define MALLOCMAX 65516		//v5.8a malloc max size v7.12m  //~5B23M~
	#define MALLOCMAX2 32700	//poswork malloc max size v7/12a//~5B23M~
#else							//v7.0a                         //~5B23M~
	#define SYSTEM  "OS/2"		//v7.0a                         //~5B23M~
	#define MALLOCMAX 200000	//v7.12a                        //~5B23M~
	#define MALLOCMAX2 32700	//poswork malloc max size v7/12a//~5B23M~
#endif							//v7.0a                         //~5B23M~
#ifdef DOS                           //v3.6a                    //~5B22M~
                                                                //~5B22M~
#define FPOST         fpos_t		 //v7.0a                    //~5B22M~
//#define FILE_ARCHIVED _A_ARCH        //v7.2a                     //~v801R~
                                                                //~5B22M~
//typedef struct _FILEFINDBUF3 {                                   //~v801R~
//                  char reserved[21];                             //~v801R~
//                  char attrFile;		//v7.0r                    //~v801R~
//                  struct {                                       //~v801R~
//                           unsigned int sec2:5;                  //~v801R~
//                           unsigned int minutes:6;               //~v801R~
//                           unsigned int hours:5;                 //~v801R~
//                         } ftimeLastWrite;                       //~v801R~
//	              struct {                                         //~v801R~
//                           unsigned int day:5;                   //~v801R~
//                           unsigned int month:4;                 //~v801R~
//		                   unsigned int year:7;                    //~v801R~
//                         } fdateLastWrite;                       //~v801R~
//	              ULONG cbFile;				//v7.0r                //~v801R~
//                  char achName[13];                              //~v801R~
//                } FILEFINDBUF3;		//v4.6r                    //~v801R~
                                                                //~5B22M~
#else                                //v3.6a                    //~5B22M~
//*******************************************************       //~5B22M~
//#define FPOST          int				//v7.0a                //~v950R~
//#define FPOST         LONG                                         //~v950I~//~v968R~
#define FPOST         ULPTR                                        //~v968R~
#define _KEYBRD_READ		0	/* read next character from keyboard */ //v7.0a//~5B22M~
#define _KEYBRD_READY		1	/* check for keystroke */				//v7.0a//~5B22M~
//*********************                                         //~5B22M~
//static HKBD hkbd;				//v7.0a os2 kbd handler v7.1d   //~5B22M~
                                                                //~5B22M~
#endif                               //v3.6a                    //~5B22M~
//**********************************************************    //~5B23R~
//*printer type                                                    //~v783I~
#define PRINTER_IBM    'I'                                         //~v783I~
#define PRINTER_ESCP   'E'                                         //~v783I~
#define PRINTER_CANNON 'C'                                         //~v783I~
#define PRINTER_WIN    'W'                                         //~v844I~
#define KEISEN_ESCPASCII     'G' 	//keisen conversion,ascii graphic of ESCP//~v857R~
#define KEISEN_ESCPASCII2    'L' 	//single line keisen for english//~v90sR~
#define KEISEN_ESCPKATAKANA  'K'                                   //~v857I~
#define KEISEN_SLASH         '/'                                   //~v863R~
//default for A4P                                               //~5B03I~
#define MAXLINE 60                                              //~5B03M~
#define MAXCOL 105		//v6.6r 110-->100-->110 v6.7r           //~5B07R~
//#define COLMAX1  70  	//maxcolomn for  pich 5cpi v5.1a           //~v91dR~
#define COLMAX1  65  	//maxcolomn for  pich 5cpi v5.1a           //~v91dI~
#define DEFAULTLPI 6                                            //~6114I~
//#define COLMAX20 80  	//maxcolomn for  pich 6cpi v5.1a        //~5B03M~
#define COLMAX2  85  	//maxcolomn for  pich 6cpi v5.1a        //~5B03M~
#define COLMAX3  95  	//maxcolomn for  pich 6.7cpi if over pich 7.5 cpi v5.1a//~5B03M~
#define COLMAX4 100  	//maxcolomn for  pich 7.2cpi if over pich 7.5 cpi v5.1a//~v785I~
                                                                   //~v907I~
#ifdef UNX                                                         //~v907I~
	#define WKFPAGE  "_XPWKF.1__" //page descending,output page save       v5.3a//~v907I~
	#define WKFPOS   "_XPWKF.2__" //page descending,output page position   v5.3a//~v907I~
#else                                                              //~v907I~
#define WKFPAGE  "!XPWKF.1!!" //page descending,output page save       v5.3a//~5B22M~
#define WKFPOS   "!XPWKF.2!!" //page descending,output page position   v5.3a//~5B22M~
#endif                                                             //~v907I~
#define MAXFLIST (MALLOCMAX/sizeof(FLIST))		//v5.7r v5.8r   //~5B23M~
#define DATABUFFSZ MALLOCMAX 		//v5.8a input file data save//~5B23M~
#define RBUFFSZ 4096	//av4.2 read buffer size                //~5B23M~
#define MAXTEXTINPLINESZ 10240	//for vhex mode max input record size from xe//~v91rR~
//#define MAXCOLMAX 150  //maximum colomn allowable max  v2.7add//~5B23M~
//#define MAXCOLMAX 256  //maximum colomn allowable max            //~v801R~
#define MAXCOLMAX 512  //for header0 long fullpath name            //~v801I~
#define LINENOSZ 6   //v2.1add v6.6r v6.7r                      //~5B23M~
#define MAXLINEWIDTH (MAXCOLMAX+LINENOSZ+10)  //print line width max v6.7a//~v852R~
//*                                                                //~v827I~
#define CHARDELM   '|'     //char dump area boundary char v6.7a    //~v827M~
#define ADDRDELM   '|'     //addr     pwidthboundary char v6.7a    //~v827M~
#define FORMFEED '\f' //0x0c v2.2add                               //~v827M~
#define TAB      '\t' //0x09 v2.7add                               //~v827M~
#define CRLF     '\n' //0x0d0a v2.7add                             //~v827M~
#define CR       0x0d //for binary mode read v4.3a                 //~v827M~
#define KEI      '/'                                               //~v827M~
#define LINEHEXPOSS  (LINENOSZ+2) //single hex dump hex edit pos v6.7a//~v852R~
#define LINEHEXPOSW  (LINENOSZ+2) //wide hex dump hex edit pos v6.7a//~v852R~
#define LINECHARPOSS (LINENOSZ+1+51)  //single mode char dump start colomn v6.7a//~v852R~
#define LINECHARPOSW (LINENOSZ+1+76)  //wide   mode char dump start colomn  v6.7a//~v852R~
//***************************************************************//~5B03I~
//file sort list v4.6a                                          //~5B22M~
typedef struct _FLIST{                                          //~5B22M~
#ifdef DOS                                                         //~v836I~
    #ifdef DPMI                                                    //~v836I~
                  	  char 			alias[13];                     //~v836I~
                  	  char 			name[MAXFILENAMEZ];            //~v836I~
    #else                                                          //~v836I~
                  	  char 			name[13];                   //~5B22M~
    #endif                                                         //~v836I~
#else                                                              //~v836I~
    #ifdef W32                                                     //~v836I~
                  	  char 			alias[13];                     //~v836I~
                  	  char 			name[MAXFILENAMEZ];            //~v836I~
    #else                                                          //~v836I~
                  	  char 			name[MAXFILENAMEZ];            //~v836I~
    #endif                                                         //~v836I~
#endif                                                             //~v836I~
	                  char 			attr;                       //~5B22M~
	                  USHORT		time;	//v7.0r             //~5B22M~
	                  USHORT		date;	//v7.0r             //~5B22M~
//                	  ULONG			size;	//v7.0r                //~v927R~
                  	  FILESZT   	size;   //LONG LONG            //~v927I~
	              	  int  			inpfindex;	//index of multifile v5.7a//~5B22M~
	              	  char 		   *databuffl;	//eof pos on databuff//~v801R~
	                } FLIST;                                    //~5B22M~
//***************************************************************//~5B22I~
EXT    char swsw1;			//switches                          //~5A30I~
#define SW1STDIN		0x80	//file name from stdin(may be redirect)//~5A30M~
#define SW1NOSTDIN		0x40	//input-file=stdin is filename  //~5A30M~
#define SW1NOKBD  		0x20	//kbd not avail                 //~5A30M~
#define SW1INDIRECT     0x10    //indirect file name            //~5A30M~
#define SW1FILESEQ      0x08    //file seq specified            //~5A30M~
#define SW1FILESEQR     0x04    //file seq reverse              //~5A30M~
#define SW1BACKG        0x02    //back ground                   //~5A30M~
#define SW1CONFY        0x01    //explicit confirm yes          //~5A30M~
                                                                //~5A30I~
EXT    char swsw2;			//switches                          //~5A30I~
#define SW2MERGE    	0x80	//file all merge                //~5A30M~
#define SW2WKDIR    	0x40	// /Wdir specified              //~5A30M~
#define SW2ANDDATE    	0x20	// select by date and condition //~5A30M~
#define SW2ORDATE    	0x10	// select by date or condition  //~5A30M~
#define SW2MAXCOLP   	0x08	// max column parameter specified//~5B03I~
#define SW2PAGERANGE 	0x04	//page range specified          //~5B11I~
#define SW21STPAGEOPT   0x02	//1st page eject opt specified     //~v785R~
#define SW21STPAGEEJECT 0x01	//1st page eject                   //~v785I~
                                                                   //~v801I~
EXT    char swsw3;			//switches                             //~v801I~
#define SW3CONJUNCT 	0x80	//conjunct mode                    //~v801I~
#define SW3GCCLFN   	0x40	//gcc lfn support                  //~v836I~
//#ifdef W32                                                       //~v90kR~
	#define SW3WIN2P    	0x20	//win 2part print              //~v904I~
	#define SW3WINTATE  	0x10	//portrate                     //~v904I~
	#define SW3WINNPNR   	0x08	//newpage no restore           //~v905R~
//#endif                                                           //~v90kR~
#define SW3FNMMALLOC 	0x04	//indirect filename area malloc end//~v90eI~
#define SW3SCRPRT   	0x02	//screen print option              //~v90jI~
#define SW3FORM2P   	0x01	//2p by form                       //~v911I~
EXT    char swsw4;			//switches                             //~v91rI~
#define SW4VHEXMODE 	0x80	//virtical hex dump mode           //~v91rI~
#define SW4NOFFCMD  	0x40	//skip formfeed at pafe eject      //~v91xI~
#ifdef UTF8SUPP                                                    //~v928I~
#define SW4OUTFILE  	0x20	//output is file                   //~v928I~
#define SW4OUTSTDO    	0x10	//output is stdout                 //~v92nR~
#if defined(LNX) && !defined(GXP)                                  //~v92nI~
#define SW4SS3       	0x08	//accept utf8->EUC-SS3(0x8f-hojokanji)//~v92nI~
#endif                                                             //~v92nI~
#endif                                                             //~v928I~
#if defined(W32) || defined(GXP)                                   //~v93vI~
	#define SW4CMAX   	0x04	//-CMAX parameter specified        //~v93vR~
#endif                                                             //~v93vI~
#ifdef UTF8UCS2                                                    //~v940I~
#define SW4VHEXMODEU  	0x02	//input vhex line is unicode(data is utf8,so length unmatch)//~v940I~
#endif                                                             //~v940I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
#define SW4EBCCFG     	0x01	//ebc trans using config file      //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
//**                                                               //~v96hI~
EXT    char swsw5;			                                       //~v96hI~
#define SW5USEICU 	0x80	//for ebc translation without cfg parm //~v96hI~
#define SW5NOBYUCS  0x40	//not (EBC)BYUCS                       //~v96nI~
#define SW5HHEXMODE 0x40	//from xe data is hhex                 //~v96sR~
//***********************                                          //~v96hI~
EXT     int Gxpotheropt;	//creared each time of indirect file   //~v955R~
#define GOO_ASCEOL    	    0x00000001 //EBC file eol is 0a or 0d0a(else 0x15)//~v953I~
#define GOO_ASCEOLS   	    "ASCEOL"                               //~v953R~
#define GOO_EBCEOLS   	    "EBCEOL"                               //~v953I~
#define GOO_BC        	    "BC"                                   //~v955I~
#define GOO_UFGETS     	    0x00000002 //read EBC file by ufgets   //~v953I~
#define GOO_EBCBYUCS   	    0x00000004 //print EBC by ucs api      //~v955I~
#define GOO_EBCFREAD   	    0x00000008 //fread moed for record/hhex//~v955I~
#define GOO_VHEXBYUCS  	    0x00000010 //vhex dump by dd fmt       //~v960I~
#define GOO_EBCBYUCSRECORD  0x00000020 //print EBC by ucs api for translated full record//~v96mI~
#define GOO_EBCBYUCS_UTF8   0x00000040 //colomn is by dd,output is by utf8//~v96zI~
#define GOO_PRINTDIALOG     0x00000080 //use PrintDialog           //~v970I~
#define GOO_DESTPRN         0x00000100 //-QPRN                     //~v970I~
#define GOO_ELLIPSIZE       0x00000200 //line cut at end when overflow//~v975I~
#define GOO_NOPAGEPRINTED   0x00000400 //no page oprinted          //~v970I~
#define GOO_NOROTATION      0x00000800 //no rotation for landscape(printer will be set landscape)//~v97aI~
#define GOO_MONOSPACELINE   0x00001000 //monospace line flag to write to desp(gxp)//~v97hI~
#define GOO_FILENAMEHDR     0x00002000 //filename header line      //~v97mI~
#define GOO_HEADERUCS       0x00004000 //filename is utf8          //~v97mR~
#define GOO_FILENAMESUBHDR  0x00008000 //filename sub header line  //~v97mI~
#define GOO_HHEXLINE        0x00010000 //hhex line(monospace xdump part)//~v97mI~
//***************************************************************//~5B03I~
EXT    int listgensw;         //implicit parm to openinput function v4.6a//~5B23I~
EXT    FILEFINDBUF3 fstat3;     //output from DosFindxxxx v3.7a v4.6r//~5B23I~
EXT    FILE *input;        //handle                             //~5B23I~
EXT    FLIST *flist;          //filename sorted list                v4.6a//~5B23I~
EXT    FLIST *flistc;		//current opened flist                 //~v801I~
EXT    char **multifile;  //multiple file name ptr v5.7a        //~5B23I~
EXT    int  condcode;         //time stamp compare condition 940609a//~5B23I~
EXT    int  condcode2;         //time stamp compare condition   //~5B23I~
EXT    int swgetarchive;		//sw:print archive attr file only v7.2a//~5B23I~
EXT    int pagefilesw;     //restart filename sw v6.2a          //~5B23I~
EXT    char *pagefile;         //print restart file name v6.2a  //~5B23I~
EXT    int	inputrangeopt;		//input range specified option v7.21a//~5B23I~
EXT    char header0[MAXLINEWIDTH];     //form feed v1.1rep v3.5r(static)v3.7r v4.7r v6.7r//~5B23I~
EXT    char headers[MAXLINEWIDTH];     //sub header when conjunct mode//~v801I~
#ifdef GTKPRINT                                                    //~v97mI~
EXT    char header0utf8[MAXLINEWIDTH];                             //~v97mI~
EXT    char headersutf8[MAXLINEWIDTH];                             //~v97mI~
//EXT    WUCS header0ucs[MAXLINEWIDTH];                              //~v97mR~//~v993R~
EXT    UWUCS header0ucs[MAXLINEWIDTH];                             //~v993I~
//EXT    WUCS headersucs[MAXLINEWIDTH];     //sub header when conjunct mode//~v97mI~//~v993R~
EXT    UWUCS headersucs[MAXLINEWIDTH];     //sub header when conjunct mode//~v993I~
EXT    int  header0ucsctr;                                         //~v97mI~
EXT    int  headersucsctr;		//subhdr line ucs ctr              //~v97mI~
EXT    int  pageposucs; 			                               //~v97mI~
#endif                                                             //~v97mI~
EXT    int pagepos; 			//v1.1add  v1.4rep v2.9rep v4.4r//~5B23I~
EXT    int  databuffsw;          //input data saveed swfor each file v5.8a//~5B23I~
EXT    char *databufft,*databuffc,*databuffl;//input data save area ptr v5.8a v7.26r//~5B23I~
EXT    char *vhexlinech,*vhexlinex1,*vhexlinex2;	//data and 2 hex line//~v91rR~
#define VHEXDATALINEID '0'	//top col is lineid(char/hex1/hex2/hdr)//~v91rI~
#define VHEXDATALINEID_EBC 0xf0	//top col is lineid(char/hex1/hex2/hdr)//~v956I~
#define VHEXDATALINEID_CMT_ASCII '*'	//for header/trailer/comment ascii line even for ebcfile scrprint//~v96sI~
EXT    USHORT conddate;         //time stamp compare date      940609a//~5B23I~
EXT    USHORT condtime;         //time stamp compare time      940609a//~5B23I~
EXT    USHORT conddate2;         //time stamp compare date      //~5B23I~
EXT    USHORT condtime2;         //time stamp compare time      //~5B23I~
EXT    long readcount;          	//input data read count v6.6a//~5B23I~
EXT    int  vhexreadline;       	//vhex mode line read count    //~v91rI~
EXT    int phase2sw;          //phase1:count page,phase2:print v4.4a//~5B23I~
EXT    int rmax;				//read buff data count		//v5.8a//~5B23I~
EXT    int vfmt;                                                   //~v96eI~
EXT    int eolV;			//recf=V record endof line             //~v96eI~
EXT    int rcount;				//read char count on buff	//v5.8a//~5B23I~
EXT    int vhexrcount;  		//read char count in the read line //~v91rI~
EXT    int vhexrmax;        	//char count in the read line      //~v91rI~
EXT    int Gvhexlineoffs;       //print offset in vhex line        //~v91rI~
EXT    char *Gparmfname;		//filename on cmd line             //~v801I~
EXT    int  fastpathsw;		//v7.26a                               //~v801I~
EXT    int  textmodevhexsw;                                        //~v92bI~
EXT    int  vhexdump;    //2:recfm=F 3:recfm=V                     //~v96eR~
#ifdef UTF8UCS2                                                    //~v940I~
EXT    int  Gutf8vhexlen;       //vhex line length for xe utf8 file vhex print//~v940I~
#endif                                                             //~v940I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
	EXT char *Gebccfgfname;		//EBCDIC cfg fnm                   //~v941I~
	EXT char  Gdefaultlocalecode[MAXLOCALESZ];                     //~v941R~
	EXT int   Gebcctype;        //ebcdic ctype(DBCS starter,unprintable)//~v941R~
	EXT int   Gebcorgcode;      //ebcdic code                      //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
EXT int Gxpebchandle;                                              //~v953R~
EXT int recordszV;                                                 //~v96eI~
EXT int recordszV0; 	//record length of lrecrfm=V               //~v96iI~
EXT int recordszVEOL;   //record length of lrecrfm=V+eolprint size //~v96iI~
EXT int recordprintwidth;   //for header0 width by old maxcol if recordsz<maxcol//~v96fR~
EXT char *eolprintfmt;                                             //~v96iR~
#define PARM_EOLPRINT  "EOLPRINT="                                 //~v96iR~
EXT char *modeparm;                                                //~v96eI~
EXT int reccolomn;        //offset in the record v6.7a             //~v96eI~
EXT int recorddumpcopyoffs;   //for hdump offset over same as above//~v96nI~
EXT char *recordszparm;   //for trailer print                        //~v96qR~//~v96sR~
EXT char *vfmtparm;   //for trailer print                          //~v96sR~
EXT int Gvhexlinelenhhex;  //3line dump input hex part len         //~v96rR~
EXT int GeoloffsV;  //end of record offset of recfmV file          //~v96sR~
EXT int GoffsV;  //offset in the Vrecord                           //~v96sI~
EXT int Geolprintcol;  //colomn of eolprint part of V record       //~v96sR~
EXT int Greccolomnold;//before reccolomn=0,parm to printdump       //~v96sR~
#ifdef GTKPRINT                                                    //~v970R~
EXT char *Gqparm;//-q parameter for form chk of the printer        //~v970R~
EXT char *Gpapersizeparm;//-E/form parm                            //~v970R~
#endif                                                             //~v970R~
//***************************************************************//~5B23I~
void uexit(int rc);                                             //~5B10M~
//void optionerr(char *,char*); //v3.8a                            //~v827R~
int    openinput(char*);            //wild card file open v3.7r //~5B22M~
int compare(const void*,const void*);//sort					v4.6a//~5B23M~
//int kbdinp(USHORT);             //keyboard input wait  v5.2a v7.0r//~v827R~
//void escstopmsg(int);               //Esc chk and stop mag      v6.0a//~v827R~
FLIST *listgen(char*[],char *);             //create sorted file list v4.6a v5.7r//~v801M~
//void pagenoedit(void);                                             //~v803I~//~v97mR~
void pagenoedit(int Popt);                                         //~v97mI~
#define PNEO_OPENINPUT       0x01        //from openinput()        //~v97mI~
//*************************************                            //~v783I~
void escfontchk(int prntyp,char *fontstyle);                       //~v783I~
                                                                   //~v783I~
//*************************************                            //~v783I~
char *escprntyp(char *cptr,int *Ppprntyp,int *Ppskip1stff);        //~v785R~
//*************************************                            //~v863I~
void dos_endjob(void);                                             //~v863I~
//*************************************                            //~v941I~
char *xpmult_chkindirectopt(int Popt,char *Pfnm,int *Ppmaxcol);    //~v941R~
//*************************************                            //~v96eI~
