//*CID://+v9d0R~:                             update#=  380;       //~v9a0R~//+v9d0R~
//***********************************************************
//* XPRINT : file print utility                                    //~v801R~
//***********************************************************
//v9d0:170218 v9.37 from xe,xpr ** total page number is not valid  //+v9d0I~
//v9a0:160418 v9.33 LNX compiler warning                           //~v9a0I~
//v990:140506 v9.30 (W32UNICODE) filename by UD fmt                //~v990I~
//v97H:131118 (BUG)vhexlinech initial clear missing                //~v97GI~
//v97G:131118 (BUG)xpr **;line is cut short by Gdatalinenosz       //~v97GI~
//v97y:131115 (BUG)-n8 is not effective for ebc file,issue errmsg  //~v97yI~
//v97w:131115 (BUG)record mode vhex dump;heder1 length=105(!=lrecl)//~v97wI~
//v97n:131105 (LNX:BUG) sigseg when wildcard filename was specified,shell expand too long cmdline parm//~v97nI~
//v97k:131104 (gxp)when no multijob(=Nj),not all page printed;projibit Nj option//~v97kI~
//v97j:131104 (gxp)prohibit fastpath(-Yf) option pagecont not determined//~v97jI~
//v97i:131104 (UNX)no docname parameter(-J) (deleted on xphlp but not on parmchk)//~v97iI~
//v97f:131104 (BUG)Order option default was not applied(issues errmsg)//~v97fI~
//v97e:131104 (BUG)Order option was changed from -Y/No to -Oxx by v924//~v97eI~
//v973:131011 (GtkPrint)new form option(E[w]/form[L](2p is by /Y2 only)//~v973I~
//v972:131011 add trace option /Yt/Nt                              //~v972I~
//v970:130922 GtkPrint for alternative of Gnomeprint               //~v970I~
//v96D:130811 (BUG:Linux)TAB(0x09) should be tabctr=1 for record mode or vfmt because if expanded overflow lrecl(eject line)//~v96DI~
//v96A:130810 samechk defualt is 0 for recfm=F,V if not hhex dump  //~v96AI~
//v96u:130804 Y/Ns option is for hexdump only                      //~v96uI~
//v96s:130804 (BUG)"xpr **" for ebcfile hhex; b2dd twice           //~v96sI~
//v96q:130804 (BUG)"xpr **" for ebcfile from xe;nor crlf is controled//~v96qI~
//v96n:130803 v9.25 Test option /ntu for test !(EBC)BYUCS          //~v96nI~
//v96k:130731 v9.25 Recordmode vhexdump by -mtx not by mx(hhex dump)//~v96kI~
//v96i:130726 v9.25 add -EOLPRINT: option to identify eol of vfmt  //~v96iI~
//v96h:130726 v9.25 new -ICU option to support for EBC file on Windows//~v96hI~
//v96f:130725 v9.25 header shrink if record mode recordsz is too small//~v96fI~
//v96e:130724 v9.25 recfm=V(-Vvfmt) support                        //~v96eI~
//120629 v96a (Win:BUG)c: may be protected; use temp               //~v96aI~
//120611 v965 avoid C4701 warning(variable may not be uninitialized)//~v965I~
//111117 v964 (gcc4.6)Warning:unused-but-set                       //~v964I~
//101004 v960 option of hex dump by ucs/utf8 for utf8 (/Y8,/N8)    //~v960I~
//100923 v957 v9.20 /Wxxx(workdir existance chk)                   //~v957I~
//100908 v953 v9.19 EBC convertername support /CPEB:               //~v953I~
//100429 v942 option support for each file on filename list        //~v942I~
//100428 v941 v9.16 ebcdic print support                           //~v941I~
//091215 v940 v9.15 unicode vhex line support by /WNU              //~v940I~
//090728 v93v v9.14 -cmax(max coloumn(=512)) parm for 1 output line/1 input line//~v93vI~
//071024 v92n (LNX)support utf8 file(conv to locale)               //~v92nI~
//            /Y8 optio to control SS3(0x8f) for EUC               //~v92nI~
//071024 v92m (GXP)warning "missing /Mu" when locale2utf8 conversion err//~v92mI~
//071014 v92h (GXP)color parameter                                 //~v92hI~
//071006 v92d (Lnx)UTF8 support                                    //~v92dI~
//071006 v92b text mode vhex dump support                          //~v92bI~
//071005 v928 (Win)UTF8 support                                    //~v928I~
//050712 v926 (BUG)when doubled -q parm,last parm only is not efective.(stdout flag remain)//~v926I~
//050607 v924 /Yo option is duplicated with /O                     //~v924R~
//050606 v922 (UNX)same effect of default /yo option as oyher than UNX//~v922I~
//            (if no -Y/No is specified,sort when no /Ol and widlcard/dir input)//~v922I~
//            to sort double quation for wildcard                  //~v922I~
//050606 v921 outputfilename by -q parm only to avoid override for also other than UNX//~v920I~
//050606 v920 (UNX:BUG)help msg ostype err                         //~v920I~
//050606 v91x add /Nu option to bypass set 0x0c(form feed) for linux convenience//~v91xI~
//050604 v91w (BUG)printf by SJIS,so force englist                 //~v91wI~
//050309 v91r vhex print support for xe(/WNlinenosz);line split and page eject//~v91rI~
//040531 v91k (FTP)remote file print support;"<orgfname>LocalTempFile" fmt//~v91kI~
//                 on parm and indirect file.                      //~v91kI~
//030116 v91g (BUG) /Nd option ignored                             //~v91gI~
//020727 v917 (BUG)minimum colomn for form2p is not 70(COLMAX1)    //~v917I~
//020720 v916 (WIN)auto set form orientation by option /Yd         //~v916I~
//020719 v913 (BUG)2p for hex dump mode is /y2 only,form2p not supported//~v913I~
//            because max col is fixed to 16 or 32                 //~v913I~
//020718 v911 form2p support(ex a42,b4l2). /y2 max col is of a4,b4l2 max col is of b5//~v911I~
//020703 v910 lineno and page continue opt by /I[x]xx-xx/[pnn] parm//~v910I~
//020406 v90v (WIN)Letter support(ZHnn) for the case drive setup is not work//~v90vI~
//011227 v90s another english mode keisen                          //~v90sI~
//011225 v90r :back UNX default /ne to /ye                         //~v90rI~
//011209 v90m :support stdout output                               //~v90kI~
//010527 v90k :2 page support for also not unx version             //~v90kI~
//010526 v90j :ScrPrt support(/WN=linenosz /WS=xxx(xxx=org filename))//~v90jR~
//010522 v90i :LINUX support(default change-->/N1,/Ne)             //~v90iI~
//010521 v90g :LINUX support:double pageing                        //~v90gI~
//010521 v90f :LINUX support:shell expand wildcard(outfile is by -q only)//~v920I~
//010521 v90e :(BUG)at uexit,free not yet malloced                 //~v90eI~
//010521 v90d :LINUX support:no esc cmd as default                 //~v907I~
//010520 v90c :LINUX supportno archive option                      //~v90cI~
//010520 v90b :LINUX support(allow dirname without wild card because shell expand wild card)//~v90bI~
//010520 v90a :LINUX support(multifile seperater change from "/" to ":")//~v90aI~
//010519 v907 :LINUX support(cmd prefix,fnm sep)                   //~v907R~
//010407 v906 :first null chk for /Y,/N parm                       //~v906I~
//010402 v905 :newpage reset may not required when new windows version.//~v905I~
//            (Skip reset for each page when /Nr to page print speed up)//~v905I~
//010401 v904 :2 parts print suport for windows printer            //~v904I~
//            (no form parm for windows,auto pich calc by device info)//~v904I~
//001210 v903 :(BUG)abend when /L parm err                         //~v903I~
//001105 v902 :new sort order option "F"(fullname),not base+ext    //~v902I~
//000115 v899 :more errchk /o option                               //~v899I~
//990918 v895 :move trt file option to /Kfxxxx from /Mmfxxxx       //~v895I~
//990918 v893 :supprt TRT by file                                  //~v893I~
//990915 v891 :EBCDIC support /M.e[k/e]                            //~v891I~
//990829 v889 :/Yt win trace option for win.                       //~v889I~
//990828 v888 :/W= support(filename on header;for xe current file print thru work)//~v888I~
//981115 v878 :allow /L/lpi(no maxline parm) format                //~v878I~
//981114 v874 :(WIN)set cpi when specified maxcol only(no cpi/no form specified)//~v874I~
//981028 v869 :docname parm support(/J)                            //~v864I~
//981028 v868 :(BUG)fullpath failed when dest is "プリンター"　    //~v868I~
//             for chk input and out put is same name.             //~v868I~
//981025 v867 :(WIN)same closedoc timing as os2                    //~v867I~
//             (need not chk conjunctmode.loop all input in printfile() whn that mode)//~v867I~
//981024 v865 :(OS2)docname set by startdoc api                    //~v865I~
//981024 v864 :setup graphic set for CANON                         //~v864I~
//             Swiss,Dutch,Ncourier for ascii                      //~v864I~
//981024 v863 :(WIN)change keisen default                          //~v863I~
//981024 v860 :chk output is printer by enumprinter                //~v860I~
//981023 v859 :(BUG of v844)output should not to be open when _WIN //~v859I~
//981023 v858 :(BUG of v844)win and outfile err should chk after outdevprn chk//~v858I~
//981010 v857 :/Yk-->/Kx;x=0(through),g(graphic),k(katakana),any char//~v857I~
//981010 v856 :last formfeed set to last page(currentry new job of x0c line only)//~v856I~
//981006 v853 :change default char set for hexdump mode to 'j'(keisen by '.')//~v857R~
//981006 v851 :write formfeed at exit                              //~v846I~
//981001 v846 :keisen print for non ibm(/yk,/nk)                   //~v846R~
//980927 v844 :(WIN) /EW option(use Win32 API to use spool)        //~v844I~
//980923 v842 :(BUG)/lpt1 is not rejected                          //~v842I~
//971130 v838 :new option /Qoutfile to avoid positional parm for xe//~v836I~
//971129 v836 :GCC version                                         //~v836I~
//             xprint.c/h:putenv(LFN),chk lfn support              //~v836I~
//971124 v832 :split xpdesp from xprint                            //~v832I~
//971124 v830 :split xphex from xprint                             //~v830I~
//971123 v827 :split xpsub1 from xrint.c                           //~v827I~
//970928 v826 :w95 version                                         //~v826I~
//             compiler warning:comp singned and unsigned          //~v826I~
//             _bios_keybrd-->xpw95kbinp                           //~v826I~
//                   intdos 6300 -->xpw95dbcsenv                   //~v826I~
//970413 v808:break at page eject timing not but line print        //~v808I~
//970214 v807:use FINDBUF3 by ufile.h                              //~v807I~
//970209 v804:change sort sequece default to name form extention   //~v804I~
//970208 v803:(BUG)header0 overflow when when fast print because   //~v803I~
//                 header0 has not yet pageno                      //~v803I~
//970206 v801:option to print files in a dir conjunctly            //~v801I~
//961217 v78c:ESCP kanji need kanji command(set:[FS]& and reset:[FS].)//~v78cI~
//961215 v78b:in ESCP,LIPS text mode,change IBM keisen moji to "/" //~v78bI~
//961214 v78a:kanji conversion jis to shift-jis when ESCP for DOS version//~v78aI~
//961214 v789:char set for cannon(dbcs but x00-x1f is unprintable) //~v789I~
//961108 v785:1st page EJECT bypass option                         //~v785I~
//961106 v783:Cannon printer support(LIPS-III)                     //~v782I~
//961106 v782:(BUG) esc kanji font style chk                       //~v781I~
//960918 v781(v7.9):(BUG) /mx /y6 position of '-' mot after 8 byte //~v781I~
//960824 v769 :(BUG of v769)need reset also pagepos when shorten header0//~v768I~
//960721 v768 :(BUG)2 line header0 when long pathname              //~v768I~
//960707 v766 :ibmc2-->msc6                                        //~v766I~
//960707 v765 :form feed ignore option for text mode w/o record option//~v765I~
//***********************************************************      //~v765I~

//#define MAXINPUTF  100			//multiple input file spec,filename ptr v5.7a//~v742R~
#define MAXPAGERANGE  20 			//max page range input      //~v74fI~
#define MAXPAGE      0x7fff 		//max page                  //~v74fI~
#define PAGEWKSZ   MALLOCMAX 		//v5.8a descendant print page work size//~v853R~
#define POSWKMAXPAGE (MALLOCMAX2/sizeof(long))	//v5.8 pos work max entry v7.0rv7/12r
#define INPUTRANGEMAX 0x1fffffff;	//v7.21a	
#define TABSKIP 4    //v2.1add

//*************************************************************
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add
//*************************************************************

#ifdef DOS                           //v3.6a                    //~v743I~
                                                                //~v743I~
	#include <dos.h>                     //v3.7a                //~v743I~
	#include <errno.h>                   //v3.7a                //~v743I~
	#include <bios.h>            		//av4.2                 //~v743I~
                                                                //~v743I~
#else                                //v3.6a                    //~v743I~
                                                                //~v743I~
  #ifdef W32                                                       //~v826I~
  #else                                                            //~v826I~
	#define INCL_BASE                     //v1.3 add v3.7r      //~v743I~
	#define INCL_SPL						//v7.11a            //~v743I~
	#define INCL_WINSHELLDATA				//v7.11a            //~v743I~
	#define INCL_SPLDOSPRINT  				//prqinfo3 v7.11a   //~v743I~
	#include <os2.h>         //v1.3 add                         //~v743I~
  #endif                                                           //~v826I~
                                                                //~v743I~
#endif                               //v3.6a                    //~v743I~
#ifdef UTF8SUPP                                                    //~v92nI~
	#include <locale.h>                                            //~v92nI~
#endif                               //v3.6a                       //~v92nI~
                                                                //~v743I~
#include <ulib.h>	                                            //~v743M~
#include <ustring.h>                                               //~v768I~
#include <uerr.h>                                                  //~v801I~
#include <ufile.h>                                                 //~v807I~
#include <ufile5.h>                                                //~v96eR~
#ifdef DPMI                 //DPMI version                         //~v836I~
    #include <ufile4.h>     //ufileisvfat                          //~v836R~
#else                       //not DPMI                             //~v836I~
#endif                      //DPMI or not                          //~v836I~
#include <udbcschk.h>                                              //~v941I~
#include <utrace.h>                                                //~v96qI~
                                                                //~v743I~
//*********************************************************************
#define GLOBAL                                                  //~v74kI~
#include  "xp.h"                                                //~v74kI~
#include  "xpsub1.h"                                               //~v827I~
#include  "xphex.h"                                                //~v830I~
#include  "xppf.h"                                                 //~v830I~
#include  "xpdesp.h"                                               //~v832I~
#include  "xpinp.h"                                                //~v91kI~
#include  "xputf.h"                                                //~v928I~
#ifdef W32                                                         //~v844I~
	#include  "xpwinp.h"                                           //~v844I~
#endif                                                             //~v844I~
#ifdef OS2                                                         //~v865I~
	#include  "xpjob.h"                                            //~v865I~
#endif                                                             //~v865I~
#ifdef GXP                                                         //~v92dI~
	#include  "xplnxp.h"                                           //~v92dI~
#endif                                                             //~v92dI~
//#ifdef UNX                                                       //~v90kR~
	#include  "xp2p.h"                                             //~v90kR~
//#endif                                                           //~v90kR~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
#include  "xpebc.h"                                                //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
//*********************************************************************//~v74kI~
//* global to share with xphlp                                  //~v74kR~
//*********************************************************************
       char pgmid[]=PGMID;     //v7.1a v7.23r
       char ver[]=VER; 		    //v7.1a v7.23r
       int tabskip=TABSKIP;      //tab skip colomn count v1.5add v2.1rep v7.23r
       int  dbcsenv;           //dbcs environment sw v4.9a v7.23r
//#ifdef DOS                                                       //~v920R~
//  #ifdef DPMI                   //DPMI version                   //~v920R~
//    int os='G';                                                  //~v920R~
//  #else                       //not DPMI                         //~v920R~
//    int os='D';                                                  //~v920R~
//  #endif                      //DPMI or not                      //~v920R~
//#else                                                            //~v920R~
//    #ifdef W32                                                   //~v920R~
//        int os='W';                                              //~v920R~
//    #else                                                        //~v920R~
//        int os='2';                                              //~v920R~
//    #endif                                                       //~v920R~
//#endif                                                           //~v920R~
	int os=OSTYPE;                                                 //~v920I~
                                                                //~v74kI~
//*********************************************************************//~v889I~
//* global to share with xpwinp                                    //~v889I~
//*********************************************************************//~v889I~
int Gtraceopt;                                                     //~v889I~
int Gzoomh=100;     //zoom rate for page height                    //~v90vI~
#define ZOOM_LETTER_H    94		//letter size                      //~v90vI~
int Gzoomw=100;                                                    //~v90vI~
//*********************************************************************//~v745I~
//* global to share with xpesc                                  //~v745I~
//*********************************************************************//~v745I~
       int colomnspec=0;      //colomn option specified sw  v5.1a  //~v874I~
       int maxcol=MAXCOL;      //colomn no per line v1.4rep v1.7rep v7.23r//~v74lM~
       int maxline=MAXLINE;    //line   no per page v7.23r      //~v74lM~
       int linespec=0;      //line option specified sw  v6.7a   //~v74lI~
//#ifdef UNX                                                       //~v90rR~
//       int escsw=0;            //no Esc cmd issue when LNX default//~v90rR~
//#else                                                            //~v90rR~
       int escsw=1;            //Esc cmd issue sw v3.3add       //~v745I~
//#endif                                                           //~v90rR~
       int  cpitch=0,lpitch=0;	//pitch parameter        v7.24a //~v745I~
       int esccmdlen;          //esccmd lenngth     ..v2.9add v3.6rep//~v745I~
       int lineprefixsw=1;		//line prefix output v7.12a     //~v745I~
       char *fontstyle=NULL;	//font style parm    v7.24a     //~v745I~
//     int  fontid=0;        	//font style parm    v7.24a        //~v783R~
//     int  fontid2=0;        	//ESCP kanji         v7.28a        //~v783R~
extern char esccmd[];            //v2.9add esc command string v2.9add v5.5r//~v745R~
extern int endjobreq;                                              //~v864I~
extern int colmax1;          	//maxcolomn for  pich 5cpi;var on xpesc.c//~v917I~
#ifdef GXP                                                         //~v92hI~
//  extern int Gprint_color;                                       //~v92hI~//~v9a0R~
    extern unsigned Gprint_color;                                  //~v9a0I~
	extern int Gl2uconverr;                                        //~v92mI~
#endif                                                             //~v92hI~
//*********************************************************************//~v74lI~
//* global to share with xpjob                                  //~v74lI~
//*********************************************************************//~v74lI~
       char  docname[256];			//document name				v7.11a//~v74lI~
#ifdef DOS                                                         //~v869R~
#else                                                              //~v869R~
       char  *jobname;  			//override filename            //~v869R~
#endif                                                             //~v869R~
//*********************************************************************//~v74pI~
//* global to share with xpinp                                  //~v74pI~
//*********************************************************************//~v74pI~
    UCHAR *Ghdrfnm;         //by /W= parm header filename          //~v888M~
//     int ordertype='E';     //default order is by EXT and NAME    v4.6a//~v804R~
       int ordertype='N';     //default order is by NAME           //~v804I~
       int ordersw=-1;        //file select in the specified order  v4.6a v5.7r//~v74pI~
       char *prn="prn";    // default output                    //~v74pI~
       long inputrange1=0,inputrange2=INPUTRANGEMAX;	//v7.21a//~v74pI~
       int multiprintjob=-1; //output multijob sw v7.1a         //~v74pI~
       int dumpmode=-1;         //dump mode default=text v2.8rep v6.7r//~v74pI~
       int swconfirm=1;        //confirm when wild card  v3.7a  //~v74pI~
       int  os2sw=0;			//v7.27a 0:dos,1:mvdm dos,2:os2    //~v827I~
       int outdevprn=1; 	//output device is printer sw v7.1a    //~v868I~
//*********************************************************************//~v830I~
//* global to share with xphex                                     //~v830I~
//*********************************************************************//~v830I~
       int printdumpfsw;				//printdump sub first sw v6.7a//~v830I~
       int samechk=-1;	      	//chk same as above      v6.7a     //~v830I~
       int puthexfsw;					//puthexline sub first sw v6.7a//~v830I~
       int dumpwidth=32;       	//hexdump 1 line dump width	v6.7a  //~v830I~
       int Linehexdpos;       //hex dec colomn in line   v6.7a     //~v830I~
       int recordsz=0;       	//input record length      	v6.7a  //~v830I~
       FILE *output=NULL;       //handle v7.11r                    //~v830I~
       int Linecharpos;       //char dump colomn in line v6.7a     //~v830I~
       int lineskip=0;         //print line advancing count v3.5add//~v830I~
       int line;                 //v2.1rep v6.7r                   //~v830I~
       long inputrange1b=0;		//boundary alignment v7.21a	v7.25r //~v830I~
       char linespwk[8];             		//line hdr(line/offset) edit sprintf wk v6.7a//~v830I~
//*********************************************************************//~v830I~
//* global to share with xppf                                      //~v830I~
//*********************************************************************//~v830I~
	   int Gcontpageno=0;                                          //~v910I~
       int Gdatalinenosz;			//lineno data width in the file//~v90jI~
  	   char *Gptrtfnm;     //code page tbl filename                //~v893I~
       int pagesw;            //sw in the print page range v3.2add v3.7r//~v830I~
       int  realpage;				//real output page count    v5.8a//~v830I~
       int nocrlfsw=0; 	      	//ignore crlf for dump mode v6.7a  //~v830I~
       int asciimode=0;        //char set id                     v2.5add//~v830I~
       int keisenconvsw=0;   //keisen conversion req           v2.5add//~v857R~
       int Gebcdictype=0;		//EBCDIC subtype 1:katakana,2:english small char//~v891R~
       int pagestart=1;        //print page range v3.2add          //~v830I~
       int pageend=MAXPAGE;    //print page range v3.2add      v3.6r//~v830I~
       int  totfile=0;         //v4.1a total file count            //~v830I~
       long totline=0;         //v4.6a total page count            //~v830I~
       int  totpage=0;         //v4.1a total page count            //~v830I~
       int  despagesw=0;       //descending page print sw v5.3a    //~v830I~
       int header1outsw=1;		//header1 output v7.12a            //~v830I~
       int header0outsw=1;		//header0 output v7.12a            //~v830I~
       char *inputrangep="";		//parm for range err msg v7.21a//~v830I~
       int swsetarchive=0;		//sw:set archive attr after print v7.2a//~v830I~
       int minprnc=0;          //min continuous printable        v2.8addv3.1rep//~v830I~
       int actualmaxc;         //colomn option specified sw  v5.1a //~v830I~
       int  ffrepl=-1;  		//form feed repl char              //~v830I~
       char *cmdfile; 		//printer cmd file	//v5.5a v6.7r      //~v830I~
#ifdef UNX                                                         //~v90iI~
       int  skip1stff=1;		//skip for UNX,first page formfeed cmd out//~v90iI~
#else                                                              //~v90iI~
       int  skip1stff=0;		//skip first page formfeed cmd opt //~v830I~
#endif                                                             //~v90iI~
       int  skip1stff2=0;		//skip first page formfeed cmd     //~v830I~
       int hexdump=0;       	//hexdump mode	v6.7a              //~v830I~
//       int prntyp='I'; 		//printer type(default ibm5577/ibm5575 etc) av4.5 v6.7r//~v830I~
#ifdef W32                                                         //~v844I~
       int prntyp=PRINTER_WIN;	//printer type(default Win for win version)//~v844I~
#else                                                              //~v844I~
	#ifdef GXP                                                     //~v92dI~
       int prntyp=PRINTER_WIN;	//printer type(default Win for win version)//~v92dI~
	#else                                                          //~v92dI~
       int prntyp=PRINTER_IBM;	//printer type(default ibm5577/ibm5575 etc) av4.5 v6.7r//~v830I~
	#endif                                                         //~v92dI~
#endif                                                             //~v844I~
       int pagerangectr;		//entry no of pagerange            //~v830I~
       int pagerange[MAXPAGERANGE*2];                              //~v830I~
       long pageoutlen;          //output len      v5.8a           //~v830I~
       int onceputsw;           //to write ff at uexit             //~v846I~
       int docnamesw=1;				//document name set functio v7.11a//~v865I~
#ifdef W32                                                         //~v916I~
       int Gdriversetsw=-1; 	//set orientation,form at createdc //~v916R~
#endif                                                             //~v916I~
//*********************************************************************//~v832I~
//* global to share with xpdesp                                    //~v832I~
//*********************************************************************//~v832I~
       char deswkfnpage[_MAX_PATH]=WKFDIR; //page work file name v5.3a//~v91kR~
       char deswkfnpos[_MAX_PATH]=WKFDIR; //pos work file name v5.3a//~v91kR~
       int  pagefsw; 				//page work file use sw v5.8a  //~v832I~
       char *pagebufft=NULL,*pagebuffc;//page work buff v5.8a v7.0r//~v832I~
       FPOST *poswkbufft=NULL,*poswkbuffc;//position work buff v5.8av7.0r//~v832I~
       int  poswkfsw;				//position work file use sw v5.8a//~v832I~
       int  despagecntsw;           //parm to escmsg from despageout//~v846I~
//     FILE *Gmsgfile=stdout;        //output to stdout for comp msg etc//~v90mR~
       FILE *Gmsgfile;        //output to stdout for comp msg etc  //~v90mR~
#define STDOUTID  "-"		    //output filename of stdout        //~v90mR~
#define STDOUTID2 "--"		    //output filename of stdout,also for comp msg//~v90mR~
//*********************************************************************//~v90bI~
//*********************************************************************//~v74lM~
static int Sstdoutsw=0;      //print output to stdout              //~v90mR~
//static int colomnspec=0;      //colomn option specified sw  v5.1a//~v874R~

//static char header0w[MAXLINEWIDTH];     //alignment work v4.7a v6.7r//~v830R~
//static  UCHAR dumpline[MAXLINEWIDTH];      //dump print line v6.7a//~v832R~
//static  UCHAR Sameline[MAXLINEWIDTH];      //same as above line v6.7a//~v832R~
//static  UCHAR Hexline1[MAXLINEWIDTH];       //record hexdump hex first 4bit v6.7a//~v832R~
//static  UCHAR Hexline2[MAXLINEWIDTH];       //record hexdump hex last 4 bit v6.7a//~v832R~
//static char uppercnv1[256];   		//for upper case compare v5.0a//~v742R~
//static char uppercnv2[256];   		//for upper case compare v5.0a//~v742R~
static char *parmfname;     //parm file name v3.7a                 //~v801R~
static int  multifilesw;        //multiple input(include wildcard) v5.7r//~v90bR~
//static int  despageno=0;       //descending page print page no v5.3a//~v832R~
//static FILE *deswkfhpage=NULL; //page work file handle v5.3a     //~v832R~
//static FILE *deswkfhpos=NULL; //pos work file handle v5.3a       //~v832R~
//#ifdef UNX                                                       //~v920R~
  	char *Sunixexpandfnm;         //char ptr work                  //~v90fI~
//#endif                                                           //~v920R~
//****************************************************************//~v742R~
void titlemsg(int,char *,char *);                               //~v741R~
//int    getinput(void);             //get 1 byte input char av4.2 //~v830R~
//void   printfile(void);            //wild card file open v3.7r   //~v830R~
//void   pline(void*,int,int,FILE*); //v3.2add v3.5r               //~v830R~
//void   datapline(void*,int,int,FILE*); //v7.12a                  //~v830R~
//int getcondts(char *Pparm,int *Pcondcode,USHORT *Pconddate,USHORT *Pcondtime);//~v827R~
//int breakchk(int Pexitsw);      //keyboard break chk    av4.2 v4.7r//~v827R~
//int dbcsenvchk(void);           //DBCS environment chk av4.9     //~v827R~
//void deswkfwrite(char*,int);    //descending page workfile write v5.3a//~v830R~
//void despageout(FILE*);         //descending page output v5.3a   //~v830R~
//int  cistrcmp(char *,char *);	//case insensitive str compare v5.3a//~v742R~
char *uindirect(char *Pindirectfnm);	//file name indirect    //~v742R~
//char **umultifnlist(char *parmfname,int Preversesw);             //~v90bI~
char **umultifnlist(char *Pparmfname,int Pswreverse,int *Ppappendsw);//~v91kR~
//void hline(char *);			//v6.5a help msg 1 line output v7.23d
//void printhdr(void);        //v6.7a                              //~v830R~
//void header0edit(void);                                          //~v830R~
void escdefaultmax(int);		    //default maxcol/maxline by form//~v74lR~
void escformchk(char *Pform);                                   //~v74lI~
//void esccmdsetup(int,int,char *);           //v5.1a v5.5r v7.0m  //~v830R~
//void os2init(void);             //v7.0a                          //~v827R~
FILE *openoutput(char *,char *);	//v7.11a
void archoff(void);			//v7.2a set archive attribute off
//void printsubhdr(int Plinewidth);                                //~v830R~
void parmprechk(int parmc,char **parmp);                           //~v972I~
//*********************************************************************

int main(int parmc,char *parmp[])                 //v1.3 rep
{
  int  infileno;				//multi file ptr index v5.7a	
  char uppercnv1[256];   		//for upper case compare v5.0a  //~v742I~
//char *parmfname;     //parm file name v3.7a                   //~v742R~
  char *cptr;         //char ptr work
  char *pc;	         //char ptr work 940609a
  char *picontpos;                                                 //~v910I~
  char *qfile=0,*pofile=0;     //out filename by /Q parm,2nd parm filename//~v836R~
  char outopenopt[2];	//output open option v7.11a
  int  i,ii;             //work v2.8add                         //~v74fR~
  int  maxcoli;       //save parameter maccol v5.1a
  int  openrc;        //open sub r.c v3.7a
  unsigned char c;    //read char   v1.4rep
  int parmno; //parm count work                 v2.6add
  int posparmno=0; //parm count work                 v2.6add
//#ifdef W32                                                       //~v92dR~
#if defined(W32) || defined(GXP)                                   //~v92dR~
	int prntypsw=0;             //prntype specified                //~v844I~
#endif                                                             //~v853I~
    int keisenreq=0;                                               //~v846I~
#ifdef WCSUPP	//W32,LNX;   by wcinit                             //~v964I~
#else                                                              //~v964I~
    int asciireq=0;                                                //~v853I~
#endif                                                             //~v964I~
    int outclosependsw;                                            //~v856I~
    int dirnamesw;		//for UNIX, dirname without wildcard       //~v90bI~
//#ifdef UNX                                                       //~v920R~
  	char *unixexpandfnm=NULL;         //char ptr work                   //~v90fI~//~v965R~
//#endif                                                           //~v920R~
//**
//void help(void); //v3.8a                                      //~v741R~
  void helpabridge(void); //v7.23a
//void history(void); //v7.21a                                  //~v741R~
//void general(void); //v5.9a                                   //~v741R~
#ifdef UTF8SUPP                                                    //~v928I~
    int utf8sw=0;                                                  //~v928I~
#endif                                                             //~v928I~
#ifdef GXP                                                         //~v92hI~
    unsigned int rgb;                                              //~v92hR~
#endif                                                             //~v92hI~
    char *pebccfgfname=0;                                          //~v953I~
    char *pebccvname=0;                                            //~v953I~
    int swyn8=0;                                                   //~v960I~
    int swtabparm=0;                                               //~v96DI~
//*************************
#ifdef W32UNICODE                                                  //~v990I~
    SET_UDMODE();  //filename by UD format                         //~v990I~
//  getche();                                                      //~v990R~
#endif                                                             //~v990I~
    modeparm=" ";                                                  //~v96fR~
    parmprechk(parmc,parmp);                 //v1.3 rep            //~v972I~
#ifdef WCSUPP	//W32,LNX                                          //~v941I~
    udbcschk_wcinit(0,Gdefaultlocalecode); //utf8 version //~v79zR~//~v941I~
    if (UDBCSCHK_DBCSCVEXT())                                      //~v941I~
    	asciimode=0;    //DBCS                                     //~v941I~
    else                                                           //~v941I~
    	asciimode=2;	//SBCS                                     //~v941I~
#endif                                                             //~v941I~
    Gmsgfile=stdout;        //output to stdout for comp msg etc    //~v90mR~
    #ifdef DPMI					//DPMI version                     //~v836I~
        putenv("LFN=Y");                 //need for ufileisvfat    //~v836I~
		if (ufileisvfat(ISVFAT_FORCE))                             //~v836I~
        	UCBITON(swsw3,SW3GCCLFN);                              //~v836I~
    #else                       //not DPMI                         //~v836I~
    #endif                      //DPMI or not                      //~v836I~
	os2init();					//v7.0a
#ifdef LNX                                                         //~v91wI~
  #ifdef GXP                                                       //~v92dI~
	dbcsenv=dbcsenvchk();		//set utf flag i uerrmsg           //~v92dI~
  #else                                                            //~v92nI~
	dbcsenvchk();				//setlocale for wcrtomb            //~v92nI~
  #endif                                                           //~v92dI~
	dbcsenv=0;					//force english                    //~v91wI~
#else                                                              //~v91wI~
	dbcsenv=dbcsenvchk();		//v4.9a
#endif                                                             //~v91wI~

  if (parmc<2)
//    ||*parmp[1]=='?')   //v1.4add v5.9d
  {
//  general(); 				//v5.9r help->general               //~v741R~
	helpabridge();                                              //~v741I~
    uexit(4);                                                   //~v742R~
  }
//*******************************
//* parm process                *
//*******************************
//#ifdef UNX                                                       //~v920R~
//get total parm length                                            //~v90fI~
	for (ii=0,parmno=1;parmno<parmc;parmno++)  //v2.6add           //~v90fR~
    	ii+=(int)strlen(parmp[parmno]);                            //~v90fR~
    Sunixexpandfnm=malloc((UINT)(ii+parmc+1));	//for : concatination//~v926R~
//#endif                                                           //~v920R~
for (parmno=1;parmno<parmc;parmno++)  //v2.6add
{                                     //v2.6add
  cptr=parmp[parmno];                 //v2.6add
    UTRACEP("parmno=%d=%s\n",parmno,cptr);                         //~v96qI~
#ifdef UNX                                                         //~v907I~
  if(*cptr=='-')                                                   //~v907I~
#else                                                              //~v907I~
  if(*cptr=='/'||*cptr=='-')          //v2.6add
#endif                                                             //~v907I~
  {//option                            //v2.6add
    c=*(++cptr);                      //first option byte v3.1add
    if (USTRHEADIS_IC(cptr,PARM_CPEB))    //icase CP=              //~v953M~
    {                                                              //~v953M~
    	xpebc_getparmcvname(0,cptr);                               //~v953M~
        pebccvname=cptr;                                           //~v953I~
        continue;                                                  //~v953M~
    }                                                              //~v953M~
    if (USTRHEADIS_IC(cptr,PARM_EOLPRINT))    //icase CP=          //~v96iI~
    {                                                              //~v96iI~
        cptr+=sizeof(PARM_EOLPRINT)-1;                             //~v96iI~
        if (!*cptr)                                                //~v96iM~
        	optionerr("EndOfLine print char option",parmp[parmno]);  //errmsg and exit v3.8r//~v96iM~
        eolprintfmt=cptr;                                          //~v96iR~
        continue;                                                  //~v96iI~
    }                                                              //~v96iI~
    if (USTRHEADIS_IC(cptr,GOO_ASCEOLS))    //icase CP=            //~v953R~
    {                                                              //~v953I~
    	Gxpotheropt|=GOO_ASCEOL;                                   //~v953R~
        continue;                                                  //~v953I~
    }                                                              //~v953I~
    if (USTRHEADIS_IC(cptr,GOO_EBCEOLS))    //icase CP=            //~v953I~
    {                                                              //~v953I~
    	Gxpotheropt&=~GOO_ASCEOL;			//for xe,override file attr//~v953R~
        continue;                                                  //~v953I~
    }                                                              //~v953I~
    if (*(++cptr)==':')               // /o:x format      v3.1add
      cptr++;                         //skip :
    switch(toupper(c))       //option     //v3.1add rv4.5   
    {                                                     //v2.0add
//**************************
//* help msg  vv7.21a  /V
//**************************
//  case 'V':                                                   //~v742R~
//	  history();                                                //~v741R~
//    exit(4);                                                  //~v742R~
//    break;                                                    //~v742R~
//**************************
//* help msg  v5.9a        /H*
//**************************
    case '?':
    case 'H':                                                   //~v741I~
	  helpabridge();	//v7.23a
      uexit(4);			//v7.23a                                //~v742R~
      break;			//v7.23a
//  case 'H':                                                   //~v741R~
//	  help();                                                   //~v741R~
//    exit(4);                                                  //~v741R~
//    break;                                                    //~v741R~
//**************************
//* general function v5.9a /G*
//**************************
//  case 'G':                                                   //~v741R~
//    general();                                                //~v741R~
//    exit(4);                                                  //~v741R~
//    break;                                              //v2.5add//~v741R~
#ifdef UTF8EBCD                                                    //~v940I~
	case 'B':           //utf8 file                                //~v940I~
      	switch (toupper(*cptr))      //v3.1add rv4.5               //~v940I~
      	{                   //v3.1add                              //~v940I~
	  	case 'C':           //utf8 file                            //~v940I~
//    		Gebccfgfname=cptr+1;                                   //~v940I~//~v953R~
      		pebccfgfname=cptr+1;                                   //~v953I~
	        break;                                                 //~v940I~
        default:                                                   //~v940I~
        	optionerr("EBCDIC cfg filename option",parmp[parmno]);  //errmsg and exit v3.8r//~v940I~
        }                                                          //~v940I~
    break;                                                         //~v940I~
#endif                                                             //~v940I~
//**************************
//* mode /M                *
//**************************
    case 'M':             //v3.1add 
#ifdef UTF8SUPP                                                    //~v928I~
	   utf8sw=0;        //for duplicated /M                        //~v928I~
#endif                                                             //~v928I~
        modeparm=cptr;                                             //~v96fI~
      switch (toupper(*cptr))      //v3.1add rv4.5
      {                   //v3.1add
#ifdef UTF8SUPP                                                    //~v92mI~
	  case 'U':           //utf8 file                              //~v92mI~
	  	utf8sw=1;                                                  //~v92mI~
        break;                                                     //~v941I~
#endif                                                             //~v92mI~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
	  case 'E':           //utf8 file                              //~v941I~
        Gebcdictype=3;	//cfg file                                 //~v941I~
        break;                                                     //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
      case 'T':                          //dump mode        //v3.8a
        dumpmode=0;                      //dump mode        //v3.8a
//      asciimode=0;                     //override  ASCII  //v3.8av6.5d
      	if (toupper(*(cptr+1))=='X')                               //~v92bI~
        {                                                          //~v92bI~
        	textmodevhexsw=1;                                      //~v92bI~
            cptr++;                                                //~v92bI~
        }                                                          //~v92bI~
        break;                                              //v3.8a
      case 'D':                          //dump mode        //v2.0add
        dumpmode=1;                      //dump mode        //v2.0add 
//      asciimode=0;                     //overridfe ASCII  //v3.8av6.5d
        break;                                              //v2.5add
//    case 'A':                          //ascii mode       //v2.5addv6.5d
//      dumpmode=1;                      //dump mode        //v3.1addv6.5d
//      asciimode=1;                     //dump mode ASCII  //v2.5addv6.5d
//      break;                                              //v2.5addv6.5d
      case 'X':                          //hex dump         //v6.7a
       if (toupper(*(cptr+1))=='T')                                //~v92bI~
       {                                                           //~v92bI~
       	textmodevhexsw=1;                                          //~v92bI~
        cptr++;                                                    //~v92bI~
       }                                                           //~v92bI~
       else                                                        //~v92bI~
       {                                                           //~v92bI~
        dumpmode=1;                      //dump mode        //v6.7a
        hexdump=1;                       //hexdump mode     //v6.7a
       }                                                           //~v92bI~
        break;                                              //v6.7a
      default:                           //not option       //v2.4add
		if (dbcsenv)	//DBCS mode v4.9a
        	optionerr("モード",parmp[parmno]);  //errmsg and exit v4.9a
		else			//SBCS mode v4.9a	
        	optionerr("Mode",parmp[parmno]);  //errmsg and exit v3.8r
      }//mode option v3.1add
//********second mode byte chk v6.5a
      if (*(cptr+1) && !isdigit(*(cptr+1)))		//0-9
	  {
		  cptr++;	
	      switch (toupper(*cptr))
	      {
#ifdef UTF8SUPP                                                    //~v928I~
	      case 'U':           //utf8 file                          //~v928R~
	        utf8sw=1;                                              //~v928R~
	        break;                                                 //~v928I~
#endif                                                             //~v928I~
	      case 'S': 		//sbcs mode
    	    asciimode=2;    //override  ASCII
     	    break;          
	      case 'D':         //dbcs  mode
        	asciimode=0;    //overridfe ASCII
        	break;         
  	      case 'A':         //ascii mode
	  	    asciimode=1;    //dump mode ASCII
	        break;        
  	      case 'J':         //JIS code set                         //~v789I~
	  	    asciimode=3;    //dump mode JIS                        //~v789I~
	        break;                                                 //~v789I~
  	      case 'I':         // -Mei                                //~v96hI~
            Gebcdictype=3;	//cfg file                             //~v96hI~
        	swsw5|=SW5USEICU;                                      //~v96hI~
	        break;                                                 //~v96hI~
  	      case 'E':         //EBCDIC                               //~v891I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941M~
            Gebcdictype=3;	//cfg file                             //~v941M~
#else                                                              //~v941M~
	  	    asciimode=4;    //                                     //~v891I~
            Gebcdictype=1;	//default katakana                     //~v891R~
#endif          //EBCDIC dbcs support                              //~v941I~
	      	switch (toupper(*(cptr+1)))                            //~v891R~
            {                                                      //~v891I~
            case 0:                                                //~v891I~
            	break;                                             //~v891R~
            case 'K':                                              //~v891I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
 	            Gebcdictype=1;	//default katakana                 //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
            	cptr++;                                            //~v891I~
            	break;                                             //~v891I~
            case 'E':                                              //~v891I~
            	cptr++;                                            //~v891I~
            	Gebcdictype=2;      //ebcdic english               //~v891R~
            	break;                                             //~v891I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
            case 'C':                                              //~v941I~
            	cptr++;                                            //~v941I~
            	Gebcdictype=3;      //ebcdic english               //~v941I~
            	break;                                             //~v941I~
            case 'I':                                              //~v96hI~
        		swsw5|=SW5USEICU;                                  //~v96hI~
            	cptr++;                                            //~v96hI~
            	break;                                             //~v96hI~
#endif          //EBCDIC dbcs support                              //~v941I~
            default:                                               //~v891R~
      			if (!isdigit(*(cptr+1)))		//0-9              //~v891R~
                {                                                  //~v91rI~
                    if (dbcsenv)    //DBCS mode                    //~v891I~
                        optionerr("EBCDIC文字セットのタイプ(k:カタカナ,e:英小文字)",parmp[parmno]);  //errmsg and exit//~v891R~
                    else            //SBCS mode                    //~v891I~
                        optionerr("EBCDIC type(k:katakana,e:alph small letter)",parmp[parmno]);  //errmsg and exit//~v891R~
                }                                                  //~v91rI~
			}//EBCDIC type                                         //~v891I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
            if (Gebcdictype!=3)	//when cfg file,defaulkt by loacle env//~v941R~
	  	    	asciimode=4;    //                                 //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
	        break;                                                 //~v891I~
	      default:         //not option
			if (dbcsenv)	//DBCS mode
        		optionerr("文字セット",parmp[parmno]);  //errmsg and exit
			else			//SBCS mode
        		optionerr("Char Set",parmp[parmno]);  //errmsg and exit
	      }//second mode option byte
#ifdef WCSUPP	//W32,LNX;   by wcinit                             //~v964I~
#else                                                              //~v964I~
          asciireq=1;		//explicit req                         //~v853I~
#endif                                                             //~v964I~
	  }
//********second mode byte chk v6.5a
		
      if (strlen(cptr+1))//n of /dn or /an       //v3.1add
      {//v2.8add
//*reject skim count when textmode or hex dump mode v6.7a start
		if (!dumpmode||hexdump)
        {
		  if (dbcsenv)	//DBCS mode
//            printf("%s:%s:印刷可能連続文字数の指定(%sの%s)は /Md のときだけ可能です\n",//~v836R~
              printf("%s:%s:印刷可\x94\\連続文字数の指定(%sの%s)は %cMd のときだけ可\x94\\です\n",//~v907R~
						pgmid,ver,parmp[parmno],cptr+1,CMDFLAG_PREFIX);//~v907R~
		  else			//SBCS
	          printf("%s:%s:Cont. char len (%s) of (%s) is avail only with %cMd option\n",//~v907R~
						pgmid,ver,cptr+1,parmp[parmno],CMDFLAG_PREFIX);//~v907R~
          uexit(4);                                             //~v742R~
        }
//*reject skim count when textmode or hex dump mode v6.7a end
        minprnc=atoi(cptr+1); //conv to integer //v2.8addv3.1rep
        if (minprnc<=0)   //conv to integer v2.8add
        {//v2.8add
		  if (dbcsenv)	//DBCS mode v4.9a
//            printf("%s:%s:印刷可能連続文字数の指定(%sの%s)は 1以上でなければなりません\n",pgmid,ver,parmp[parmno],cptr+1);//v4.9a//~v836R~
              printf("%s:%s:印刷可\x94\\連続文字数の指定(%sの%s)は 1以上でなければなりません\n",pgmid,ver,parmp[parmno],cptr+1);//v4.9a//~v836I~
		  else			//SBCS mode v4.9a	
	          printf("%s:%s:Cont. char len (%s) of (%s) must >=1\n",pgmid,ver,cptr+1,parmp[parmno]);//v2.8av3.1rv3.8r
          uexit(4);//v2.8add                                    //~v742R~
        }//v2.8add
        dumpmode=2; //extract printable char mode v3.1add
      }//v2.8add
      break;                                              //v2.5add
//**************************
//* page range   /P        *
//**************************
    case 'P':                          //v3.2add
        if (!*cptr)				//no parm                       //~v748R~
        {                                                          //~v91rI~
			if (dbcsenv)	//DBCS mode                         //~v748R~
        		optionerr("ページ範囲",parmp[parmno]);  //errmsg and exit//~v748R~
			else			//SBCS mode                         //~v748R~
        		optionerr("Page range",parmp[parmno]);  //errmsg and exit//~v748R~
        }                                                          //~v91rI~
	  pagefile=strpbrk(cptr,"/");	//v6.2a restart file name v7.0r
      UCBITOFF(swsw2,SW2PAGERANGE);                             //~v74nI~
	  if (strchr(cptr,'-'))			//- used                    //~v74nI~
	      UCBITON(swsw2,SW2PAGERANGE);	//range specified       //~v74nI~
	  if (pagefile)					//v6.2a restart file name v7.0r
	  {//v6.2a	
      	                                                        //~v74fI~
		pagefilesw=1;			//resume file sw v6.2a
		*pagefile=0;			//for strspn   v6.2a            //~v74fI~
		i=(strspn(cptr,"0123456789-")!=strlen(cptr));           //~v74fR~
		*pagefile++='/';		//restore                       //~v74fR~
	  }//v6.2a	
//"/"before file name chk v6.8a start
	  else
		i=(strspn(cptr,"0123456789-+")!=strlen(cptr));          //~v74oR~
	  if (i)                                                    //~v74fI~
      {                                                            //~v91rI~
		if (dbcsenv)	//DBCS mode                             //~v74fI~
        	optionerr("ページ範囲",parmp[parmno]);  //errmsg and exit//~v74fI~
		else			//SBCS mode                             //~v74fI~
        	optionerr("Page range",parmp[parmno]);  //errmsg and exit//~v74fI~
      }                                                            //~v91rI~
//"/"before file name chk v6.8a end
//    if (*cptr=='/')			//no page parm and with file name v6.2a//~v74hR~
//  	pagestart=1;			//default,from first page	v6.2a//~v74hR~
//    else	 					//v6.2a                         //~v74hR~
//      pagestart=atoi(cptr); //conv to integer //v3.2add       //~v74hR~
//    if (strrchr(cptr,'-')) //nn-mm format   //v3.2add         //~v74hR~
//    {//v3.2add                                                //~v74hR~
//      i=atoi(strrchr(cptr,'-')+1);//conv to integer //v3.2add //~v74hR~
//      if (i) //end page specified v3.2add                     //~v74hR~
//        pageend=i; //accept page end; v3.2add                 //~v74hR~
//      if (pagestart>pageend)    //conv to integer v3.2add     //~v74hR~
//      {//v3.2add                                              //~v74hR~
//  	  if (dbcsenv)	//DBCS mode v4.9a                       //~v74hR~
//          printf("%s:%s:開始頁番号印 %d が終了頁番号 %d より大きい\n",//~v74hR~
//               pgmid,ver,pagestart,pageend);//v4.9a           //~v74hR~
//  	  else			//SBCS mode v4.9a	                    //~v74hR~
//        	printf("%s:%s:start page %d is larger than end page %d\n",//~v74hR~
//               pgmid,ver,pagestart,pageend);//v3.2add         //~v74hR~
//        uexit(4);//v3.2add                                    //~v74hR~
//      }//v3.2add                                              //~v74hR~
//    }//v3.2add                                                //~v74hR~
//    else                                                      //~v74hR~
//  	if (!pagefilesw)		//not resume print case v6.2a   //~v74hR~
//          pageend=pagestart; //1 page print v3.2add           //~v74hR~
      	for (pc=cptr;*pc && *pc!='/';)                          //~v74hR~
      	{                                                       //~v74hR~
            if (pagerangectr>=MAXPAGERANGE*2)                   //~v74hR~
            {                                                   //~v74hR~
    			if (dbcsenv)	//DBCS mode                     //~v74hR~
            		printf("%s:%s:ページ範囲指定は最大 %d 個迄\n",//~v74hR~
                     		pgmid,ver,MAXPAGERANGE);            //~v74hR~
    	  		else			//SBCS mode                     //~v74hR~
          			printf("%s:%s:page range max pair is %d\n", //~v74hR~
                     		pgmid,ver,MAXPAGERANGE);            //~v74hR~
          		uexit(4);                                       //~v74hR~
    		}                                                   //~v74hR~
            if (*pc=='-')                                       //~v74hR~
            	i=1;                                            //~v74hR~
            else                                                //~v74hR~
            	i=atoi(pc);                                     //~v74hR~
            pagerange[pagerangectr]=i;                          //~v74hR~
        	pagerange[pagerangectr+1]=i;  //next file to last page//~v74hR~
            pc=strpbrk(pc,"+-/");	//search delm               //~v74oR~
        	if (!pc)                                            //~v74hR~
        		break;                                          //~v74hR~
        	switch (*pc)                                        //~v74hR~
        	{                                                   //~v74hR~
        	case '-':                                           //~v74hR~
	        	if (!(i=atoi(pc+1)))//conv to integer //v3.2add //~v74hR~
                	i=MAXPAGE;                                  //~v74hR~
		        pagerange[pagerangectr+1]=i;//else max          //~v74hR~
	        	pc+=strspn(pc+1,"01234567890")+1;	//next range//~v74hR~
                if (*pc=='+')                                   //~v74oR~
                {                                               //~v74hR~
                	pc++;                                       //~v74hR~
			    	pagerangectr+=2;                            //~v74hR~
                }                                               //~v74hR~
            	break;                                          //~v74hR~
        	case '+':                                           //~v74oR~
	        	pagerangectr+=2;                                //~v74hR~
            	pc++;                                           //~v74hR~
            	break;                                          //~v74hR~
        	case '/':                                           //~v74hR~
            	break;                                          //~v74hR~
    		}//sw                                               //~v74hR~
    	}//loop by delm ,                                       //~v74hR~
        pagerangectr+=2;                                        //~v74hR~
        pagestart=MAXPAGE;                                      //~v74hR~
        pageend=0;                                              //~v74hR~
        for (ii=0;ii<pagerangectr;ii+=2)                        //~v74hR~
        {                                                       //~v74hR~
//        	printf("\n range %d-%d",pagerange[ii],pagerange[ii+1]);//~v74jR~
        	if (pagerange[ii]>pagerange[ii+1])                  //~v74hR~
        	{                                                   //~v74hR~
	      		if (dbcsenv)	//DBCS mode                     //~v74hR~
	        		printf("%s:%s:開始頁番号印 %d が終了頁番号 %d より大きい\n",//~v74hR~
                 		pgmid,ver,pagerange[ii],pagerange[ii+1]);//~v74hR~
	      		else			//SBCS mode                     //~v74hR~
	    			printf("%s:%s:start page %d is larger than end page %d\n",//~v74hR~
                 		pgmid,ver,pagerange[ii],pagerange[ii+1]);//~v74hR~
    	       	uexit(4);                                       //~v74hR~
            }                                                   //~v74hR~
        	if (pagerange[ii]<pagestart)                        //~v74hR~
        		pagestart=pagerange[ii];                        //~v74hR~
        	if (pagerange[ii+1]>pageend)                        //~v74hR~
        		pageend=pagerange[ii+1];                        //~v74hR~
        }//seq chk                                              //~v74hR~
      	break;                           //v3.2add              //~v74fR~
//**************************
//* input range  /I  v7.21a *
//**************************
    case 'I':
       	if (!stricmp(cptr-1,"ICU"))                                //~v96hI~
        {                                                          //~v96hI~
        	swsw5|=SW5USEICU;                                      //~v96hI~
            break;                                                 //~v96hI~
        }                                                          //~v96hI~
	  inputrangep=cptr;				//save for later err msg v7.21a
	  if (toupper(*cptr)=='X')		//file offset
	  {
		inputrangeopt=2;	
		cptr++;
	  }	
	  else	
		inputrangeopt=1;	

	  i=0;		//errflag	
//cont pageno chk                                                  //~v910I~
      pc=strchr(cptr,'/');                                         //~v910I~
      picontpos=0;                                                 //~v910I~
      if (pc)                                                      //~v910I~
      {                                                            //~v910I~
          picontpos=pc++;                                          //~v910I~
          if (strspn(pc,"0123456789")!=strlen(pc))                 //~v910I~
              i=1;            //err                                //~v910I~
          else                                                     //~v910I~
              Gcontpageno=atoi(pc);                                //~v910I~
          *picontpos=0;                                            //~v910I~
      }                                                            //~v910I~
//input range chk                                                  //~v910I~
	  pc=strpbrk(cptr,"-");
	  if (pc)			//end value specified
	  {	 
		pc++;		    //end parm addr
		if (strlen(pc)>8)
			i=1;
		if ((strlen(cptr)-strlen(pc)-1)>8)
			i=1;
	  }
//	  else				//no end parm
//		i=1;			//err

	  if (inputrangeopt==1)	//lineno
	  {
		  if (strspn(cptr,"0123456789-")!=strlen(cptr))
			i=1;			//err
		  sscanf(cptr,"%ld-",&inputrange1);
    	  	if (pc)	                                            //~5208I~
		  	{                                                   //~5208I~
		  		if (strspn(pc,"0123456789")!=strlen(pc))        //~5208I~
					i=1;			//err                       //~5208I~
		 		sscanf(pc,"%ld",&inputrange2);                  //~5208R~
			}	                                                //~5208I~
	  }
	  else				//hex offset
	  {
		if (strspn(cptr,"0123456789abcdefgABCDEFG-")!=strlen(cptr))
			i=1;			//err
	    sscanf(cptr,"%lx-",&inputrange1);
    	if (pc)	                                                //~5208I~
		{                                                       //~5208I~
			if (strspn(pc,"0123456789abcdefgABCDEFG")!=strlen(pc))//~5208I~
				i=1;			//err                           //~5208I~
	    	sscanf(pc,"%lx",&inputrange2);                      //~5208R~
		}	                                                    //~5208I~
	  }	
//	  printf("input range:1=%ld(%08lx),2=%ld(%08lx)\n",inputrange1,inputrange1,inputrange2,inputrange2);
	  if (inputrange1<=0)
		inputrange1=0;		//high value
	  if (inputrange2)
		inputrange2++;
	  else	
		inputrange2=INPUTRANGEMAX;	//high value
//	  printf("input range:1=%ld(%08lx),2=%ld(%08lx)\n",inputrange1,inputrange1,inputrange2,inputrange2);
      if (inputrange1>inputrange2)
		i=1;
      if (picontpos)                                               //~v910I~
      	*picontpos='/';                                            //~v910I~
//    printf("cont p=%d\n",Gcontpageno);                           //~v911R~
	  if (i)	//err
	  {
		  if (dbcsenv)	//DBCS mode
        	optionerr("入力範囲[/継続頁No]",parmp[parmno]);        //~v910R~
	  	  else			//SBCS mode
        	optionerr("Input range[/Restart PageNo]",parmp[parmno]);//~v910R~
       	  uexit(4);                                             //~v742R~
  	  }		

      break;
#ifndef UNX                                                        //~v97iI~
//**************************                                       //~v869R~
//* jobname      /J         *                                      //~v869R~
//**************************                                       //~v869R~
    case 'J':                                                      //~v869R~
#ifdef DOS                                                         //~v869R~
        if (dbcsenv)    //DBCS mode                                //~v869R~
            printf("ジョブ名はDOS版では無効\n");                   //~v869R~
        else            //SBCS mode                                //~v869R~
            printf("Jobname is invalid for DOS version");          //~v869R~
        uexit(8);                                                  //~v869I~
#else                                                              //~v869R~
	  	jobname=cptr;	                                           //~v869R~
#endif                                                             //~v869R~
      	break;                                                     //~v869R~
#endif                                                             //~v97iI~
//**************************
//* max  colomn  v3.2add /C*      /Cnn[/p]
//**************************
    case 'C':
//*process pitch parm start v7.24a
	  pc=strpbrk(cptr,"/");	//search "/" position
	  if (pc)					//v6.2a restart file name v7.0r
	  {	
		if (strspn(pc+1,"0123456789")!=strlen(pc+1))
        {                                                          //~v91rI~
			if (dbcsenv)	//DBCS mode
    	    	optionerr("文字ピッチ",parmp[parmno]);  //errmsg and exit v4.9a
			else			//SBCS mode v4.9a	
    	    	optionerr("Char pitch",parmp[parmno]);  //errmsg and exit v3.8r
        }                                                          //~v91rI~
		cpitch=atoi(pc+1);		//get pitch value
        *pc=0;
	    i=atoi(cptr); //conv to integer
        *pc='/';
	  }	
	  else 
	  {
	  	cpitch=0;	
#if defined(W32) || defined(GXP)                                   //~v93vI~
       if (!stricmp(cptr,"MAX"))                                   //~v93vI~
       {                                                           //~v93vI~
	    i=MAXCOLMAX-1; //conv to integer                           //~v93vR~
	    UCBITON(swsw4,SW4CMAX);      //later adjust to actualmax column//~v93vI~
       }                                                           //~v93vI~
       else                                                        //~v93vI~
#endif                                                             //~v93vI~
	    i=atoi(cptr); //conv to integer
	  }
//*process pitch parm end  v7.24a
      if (i)				//v7.24a                            //~v74lR~
      {                                                            //~v91rI~
      	if (i>0)				                                //~v74lR~
	    	maxcol=i;//atoi(cptr); //conv to integer            //~v74lR~
      	else                                                    //~v74lR~
			maxcol=-i;		 //conv to integer                  //~v74lR~
      }                                                            //~v91rI~
      if (maxcol<=0||maxcol>MAXCOLMAX) //range chk
      {
		  if (dbcsenv)	//DBCS mode v4.9a
        	printf("%s:%s:1行の桁数(%s) は %d 以下でなければなりません\n",pgmid,ver,parmp[parmno],MAXCOLMAX);//v4.9a
		  else			//SBCS mode v4.9a	
        	printf("%s:%s:max colomn parm(%s) must<=%d\n",pgmid,ver,parmp[parmno],MAXCOLMAX);//v2.7rep
        uexit(4);                                               //~v742R~
      }
//    if (i)				//v7.24a                            //~v74iR~
      if (i>0)				//v7.24a if minus dynamic           //~v74iI~
	      colomnspec=1;      //colomn option specified sw  v5.1a
      if (i)				//v7.24a if minus dynamic           //~v74lI~
	      UCBITON(swsw2,SW2MAXCOLP);      //colomn option specified sw  v5.1a//~v74lI~
	  else	                                                    //~v74lI~
	      UCBITOFF(swsw2,SW2MAXCOLP);      //colomn option specified sw  v5.1a//~v74lI~
      break;
//**************************
//* Font style /Fxxx v7.24a or form feed char /FFXxx               //~v765R~
//**************************
    case 'F':
      if (!memicmp(cptr,"FX",2))	//form feed                    //~v765R~
      {                                                            //~v765I~
			if (strlen(cptr+2)!=2                                  //~v765R~
            ||  !isxdigit((int)*(cptr+2))                          //~v765R~
            ||  !isxdigit((int)*(cptr+3))                          //~v765R~
            ||  (sscanf(cptr+2,"%2x",&i),                          //~v765I~
                 ffrepl=(int)(unsigned char)i,                     //~v765I~
                 ffrepl> 0x7f))                                    //~v765R~
            {                                                      //~v91rI~
				if (dbcsenv)	//DBCS mode                        //~v765I~
    		    	optionerr("改頁置換文字",parmp[parmno]);  //errmsg and exit v4.9a//~v765I~
				else			//SBCS mode v4.9a	               //~v765I~
    		    	optionerr("FormFeed replace char",parmp[parmno]);  //errmsg and exit v3.8r//~v765I~
            }                                                      //~v91rI~
      }                                                            //~v765I~
      else                                                         //~v765I~
	  fontstyle=cptr;			//save for esccmdsetup
      break;
//**************************
//* record length /R v6.7a *
//**************************
    case 'R':
#ifdef GXP                                                         //~v92hM~
    	if (strlen(cptr)>=4 && !memicmp(cptr,"GB=",3))	//TC=      //~v92hR~
        {                                                          //~v92hM~
        	sscanf(cptr+3,"%x",&rgb);                              //~v92hR~
            Gprint_color=(Gprint_color & 255)|(rgb<<8);            //~v92hM~
            break;                                                 //~v92hM~
        }                                                          //~v92hM~
        else                                                       //~v92hI~
    	if (strlen(cptr)>=3 && !memicmp(cptr,"GB",2))	//TC=      //~v92hI~
    		optionerr("RGB parm(RGB=)",parmp[parmno]);  //errmsg and exit v3.8r//~v92hI~
        else                                                       //~v96uI~
#endif                                                             //~v92hM~
      if (!(recordsz=atoi(cptr))) //conv to integer
      {                                                            //~v96uI~
       if (*cptr)  // "-R0"                                        //~v96uI~
		recordsz=0;	//reset recordmode                             //~v96uI~
       else        // "-R"                                         //~v96uI~
		recordsz=-1;	//same as maxcol
	    recordszparm=0;                                            //~v96uI~
      }                                                            //~v96uI~
      else                                                         //~v96uI~
	    recordszparm=cptr-1;                                         //~v96qI~//~v96uR~
      break;
//**************************                                       //~v96eR~
//* recfm=V                                                        //~v96eR~
//**************************                                       //~v96eR~
    case 'V':                                                      //~v96eR~
      	if (!*cptr) 	// "-V"    reset prev -V parm              //~v96uI~
        {                                                          //~v96uI~
        	vfmtparm=0;                                            //~v96uI~
            vfmt=0;                                                //~v96uI~
            break;                                                 //~v96uI~
        }                                                          //~v96uI~
        vfmtparm=(cptr-1);                                         //~v96uR~
    	chkvfmtparm(cptr);                                         //~v96eI~
      break;                                                       //~v96eR~
//**************************                                       //~v857I~
//* keisen conversion                                              //~v857I~
//**************************                                       //~v857I~
    case 'K':             //v7.1a                                  //~v857I~
        keisenreq=1;    //v7.1a                                    //~v857I~
        switch (toupper(*cptr))                                    //~v857I~
        {                                                          //~v857I~
        case 0:           // /o:                                   //~v857I~
            if (dbcsenv)    //DBCS mode                            //~v857I~
                optionerr("罫線置換指定",parmp[parmno]);  //errmsg and exit v4.9a//~v857I~
            else            //SBCS mode v4.9a                      //~v857I~
                optionerr("graphic char replacement",parmp[parmno]);  //errmsg and exit v3.8r//~v857I~
            break;                                                 //~v857I~
        case '0':           // /o:                                 //~v857I~
			keisenconvsw=0;                                        //~v857I~
            break;                                                 //~v857I~
        case KEISEN_ESCPASCII:         //'G' graphic for ascii     //~v857I~
			keisenconvsw=KEISEN_ESCPASCII;                         //~v857R~
            break;                                                 //~v857I~
        case KEISEN_ESCPASCII2:        //'G' graphic for ascii     //~v90sI~
			keisenconvsw=KEISEN_ESCPASCII2;                        //~v90sI~
            break;                                                 //~v90sI~
        case KEISEN_ESCPKATAKANA:      //'K' katakana              //~v857I~
			keisenconvsw=KEISEN_ESCPKATAKANA;                      //~v857I~
          	break;                                                 //~v857I~
  	    case 'F':         //JIS code set                           //~v895I~
			keisenconvsw=0;                                        //~v895I~
            Gptrtfnm=cptr+1; //save trt filename;                  //~v895M~
	        break;                                                 //~v895M~
        default:         //arbitary specification                  //~v857I~
			keisenconvsw=*cptr;                                    //~v857I~
        }                                                          //~v857I~
    	break;              //v7.1a                                //~v857I~
//**************************
//* max line    v3.2add /Ln/p *
//**************************
    case 'L':
//*process pitch parm start v7.24a
	  pc=strpbrk(cptr,"/");	//search "/" position
	  if (pc)					//v6.2a restart file name v7.0r
	  {
		if (strspn(pc+1,"0123456789")!=strlen(pc+1))
        {                                                          //~v91rI~
			if (dbcsenv)	//DBCS mode
    	    	optionerr("改行ピッチ",parmp[parmno]);  //errmsg and exit v4.9a
			else			//SBCS mode v4.9a	
    	    	optionerr("Line pitch",parmp[parmno]);  //errmsg and exit v3.8r
        }                                                          //~v91rI~
		lpitch=atoi(pc+1);		//get pitch value
        *pc=0;
	    i=atoi(cptr); //conv to integer
	  }	
	  else 
	  {
	    i=atoi(cptr); //conv to integer
	  	lpitch=0;	
      }
//printf ("cptr=%02x,i=%d,sptrspn=%d,strlen=%d\n",                 //~v878R~
//			(int)(*cptr),i,strspn(cptr,"0123456789"),strlen(cptr));//last may spacing char//~v878R~
//*process pitch parm end  v7.24a
	  if (i)		//v7.24a
	  {	 
		  maxline=atoi(cptr);               //conv to int
		  linespec=1;					//line parm specified sw v6.7a
	  }				//v7.24a	
//    if (maxline<=0 )	//v7.24r                                   //~v842R~
   if (*cptr)		//line specified                               //~v878R~
      if (maxline<=0  	//v7.24r                                   //~v842I~
      ||  strspn(cptr,"0123456789")<(strlen(cptr)-1)) //last may spacing char//~v842I~
      {                                                            //~v878I~
       if (pc)                                                     //~v903I~
        *pc='/';            //recov for errmsg                     //~v878I~
		if (dbcsenv)	//DBCS mode v4.9a
        	optionerr("1頁の行数",parmp[parmno]);  //errmsg and exit v4.9a
		else			//SBCS mode v4.9a	
        	optionerr("Max Line",parmp[parmno]);  //errmsg and exit v3.8r
      }                                                            //~v878I~
//***************
//*line space   *v3.5add
//***************
      if (*cptr && !isdigit(*(cptr+strlen(cptr)-1)) )//last is not numeric v7.24r
      {
        switch (toupper(*(cptr+strlen(cptr)-1)))
        {
        case 'D':
          lineskip=1;//add 1 \n after line print
          break;
        case 'T':
          lineskip=2;//add 2 \n after line print
          break;
        default : //param err
		if (dbcsenv)	//DBCS mode v4.9a
          optionerr("行間スペース行",parmp[parmno]);//errmsg and exit v4.9a
		else			//SBCS mode v4.9a	
          optionerr("Line Space",parmp[parmno]);//errmsg and exit v3.8r
        }//switch by last non digit char
      }//lst is not numeric
      break;
//**************************
//* tab skip count v3.2 add* /T
//**************************
    case 'T':
      if (toupper(*cptr)=='U')                                     //~v96nR~
      {                                                            //~v96nI~
          swsw5|=SW5NOBYUCS;                                       //~v96nI~
          break;                                                   //~v96nI~
      }                                                            //~v96nI~
      swtabparm=1;                                                 //~v96DI~
      tabskip=atoi(cptr);                //conv to int
      if (!isdigit(*cptr)||tabskip<0)//allow 0
      {                                                            //~v91rI~
		if (dbcsenv)	//DBCS mode v4.9a
        	optionerr("タブ桁位置",parmp[parmno]);  //errmsg and exit v4.9a
		else			//SBCS mode v4.9a	
        	optionerr("Tab Skip",parmp[parmno]);  //errmsg and exit v3.8r
      }                                                            //~v91rI~
      break;
//**************************
//* printer type    v4.5a /E
//**************************
    case 'E':							//v7.291r
      cmdfile=escprntyp(cptr,&prntyp,&skip1stff); //printer type ok//~v785R~
//#ifdef W32                                                       //~v92dR~
#if defined(W32)||defined(GXP)                                     //~v92dI~
      if (*cptr!='/')                                              //~v844I~
	      prntypsw=1;                       //prntype specified    //~v844R~
#endif                                                             //~v853I~
      break;
//**************************
//* work directory   v5.3a /W
//**************************
    case 'W':
      if (*cptr=='=')                                              //~v888I~
        Ghdrfnm=cptr+1;                                            //~v888I~
      else                                                         //~v90jI~
      if (toupper(*cptr)=='S'                                      //~v90jR~
      &&  *(cptr+1)=='=')    // /WS=                               //~v90jI~
      {                                                            //~v90jI~
        Ghdrfnm=cptr+2;                                            //~v90jI~
        UCBITON(swsw3,SW3SCRPRT);                                  //~v90jI~
      }                                                            //~v90jI~
      else                                                         //~v90jI~
      if (toupper(*cptr)=='N'                                      //~v90jR~
      &&  *(cptr+1)=='=')    // /WS=                               //~v90jI~
      {                                                            //~v90jI~
        Gdatalinenosz=atoi(cptr+2);                                //~v90jI~
        if (!Gdatalinenosz || Gdatalinenosz>10)                    //~v90kR~
        {                                                          //~v90jI~
        	if (dbcsenv)  //DBCS mode v5.3a                        //~v90jI~
            	printf("%s:%s:%cWN= パラメータ(ファイル中の行番号桁数)は 1 から 10 まで。\n",//~v90kR~
            			pgmid,ver,CMDFLAG_PREFIX);//v5.3a          //~v90jI~
            else            //SBCS mode v5.3a                      //~v90jI~
            	printf("%s:%s:%cWN= (Line-no Data width of the file) is 1 to 10\n",//~v90kR~
                	    pgmid,ver,CMDFLAG_PREFIX); //v5.3a         //~v90jI~
            uexit(4);                                            //v5.3a//~v90jI~
                                                                   //~v90jI~
		}                                                          //~v90jI~
        if (toupper(*(cptr+strlen(cptr)-1))=='X')                  //~v91rI~
//      	swsw4|=SW4VHEXMODE;	//line top byte contain lineid('*':not data line,'0':char line,' ':hex line//~v91rR~
        	UCBITON(swsw4,SW4VHEXMODE);	//line top byte contain lineid('*':not data line,'0':char line,' ':hex line//~v91rR~
#ifdef UTF8UCS2                                                    //~v940I~
        else                                                       //~v940I~
        if (toupper(*(cptr+strlen(cptr)-1))=='U')                  //~v940I~
        	UCBITON(swsw4,(SW4VHEXMODE|SW4VHEXMODEU));	//line top byte contain lineid('*':not data line,'0':char line,' ':hex line//~v940I~
#endif                                                             //~v940I~
        else                                                       //~v96sM~
        	UCBITON(swsw5,SW5HHEXMODE);	//line top byte contain lineid('*':not data line,'0':char line,' ':hex line//~v96sM~
      }                                                            //~v90jI~
      else                                                         //~v888I~
      {                                                            //~v888I~
        if (!ROOTDIR(cptr) && ufstat(cptr,0/*ffb3*/))              //~v957R~
          	if (*(cptr+strlen(cptr)-1)!=DIR_SEPC                   //~v957R~
          	|| (*(cptr+strlen(cptr)-1)=0,ufstat(cptr,0)!=0)        //~v957R~
            )                                                      //~v957I~
            	uerrexit("workdir(%s) not found",0,                //~v957R~
            	cptr);                                             //~v957I~
    	UCBITON(swsw2,SW2WKDIR);	//wkdir specified           //~v74dI~
      strcpy(deswkfnpage,cptr);	//page work
      strcpy(deswkfnpos,cptr);	//page position work
      }                                                            //~v888I~
      break;
//**************************
//* file output order v4.6a /O
//**************************
    case 'O':
	  i=0;
	  if (*cptr=='+')
		cptr++;
	  else
		  if (*cptr=='-')
		  {
	  		i=1;	//reverse order
			cptr++;
	  	  }
//      if (*(cptr+1))                                               //~v899I~//~v97fR~
//      {                                                            //~v899I~//~v97fR~
//        if (dbcsenv)    //DBCS mode v4.9a                          //~v899I~//~v97fR~
//            optionerr("ファイルプリント順序",parmp[parmno]);//errmsg and exit v4.9a//~v899I~//~v97fR~
//        else            //SBCS mode v4.9a                          //~v899I~//~v97fR~
//            optionerr("File Print Order",parmp[parmno]);//errmsg and exit v3.8r//~v899I~//~v97fR~
//      }                                                            //~v899I~//~v97fR~
      ordersw=1;          //sort                                   //~v924R~
      switch (toupper(*cptr))
      {
      case 0:			// /o:
      case 'E':			// /o:e	by ext and name
        ordertype='E';
        break;
      case 'N':			// /o:f	by fullname                        //~v902R~
        ordertype='N';                                             //~v902R~
        break;                                                     //~v902I~
//    case 'N':			// /o:b	by name(base+ext)                  //~v902R~
      case 'B':			// /o:b	by name(base+ext)                  //~v902I~
//      ordertype='N';                                             //~v902R~
        ordertype='B';                                             //~v902I~
        break;
      case 'D':			// /o:d	by date and time
        ordertype='D';
        break;
      case 'L':			// /o:l	file list forward seq           //~v743I~
    	ordersw=0;          //no sort                              //~v924R~
      	UCBITON(swsw1,SW1FILESEQ);	//file seq specified        //~v743I~
        if (i)		//reverse                                   //~v743I~
	      	UCBITON(swsw1,SW1FILESEQR);	//file seq reverse      //~v743I~
		else                                                    //~v743I~
	      	UCBITOFF(swsw1,SW1FILESEQR);//file seq forward      //~v743I~
		i=-1;		//avoid set ordertype                       //~v743I~
        break;                                                  //~v743I~
      default:
		if (dbcsenv)	//DBCS mode v4.9a
        	optionerr("ファイルプリント順序",parmp[parmno]);//errmsg and exit v4.9a
		else			//SBCS mode v4.9a	
        	optionerr("File Print Order",parmp[parmno]);//errmsg and exit v3.8r
        break;                                              //v3.8a
	  }	
	  if (i>0)	//reverse order                                 //~v743R~
	    ordertype=-ordertype;
      break;
//**************************
//* file selection by time stamp  940609a /D
//**************************
    case 'D':
        UCBITOFF(swsw2,SW2ANDDATE|SW2ORDATE);	//crear prev cmd//~v74kI~
      	strcpy(uppercnv1,cptr); //v5.0a                         //~v74jR~
	  	strupr(uppercnv1);	//upper case v5.0r                  //~v74jR~
		if (pc=strpbrk(uppercnv1,"-+"),pc)	//and/or cond       //~v74jR~
        {                                                       //~v74jI~
			if (*pc=='-')                                       //~v74jR~
            	UCBITON(swsw2,SW2ANDDATE);                      //~v74jI~
            else                                                //~v74jI~
            	UCBITON(swsw2,SW2ORDATE);                       //~v74jI~
        	*pc++=0;                                            //~v74jR~
		}                                                       //~v74jI~
      	if (!(i=getcondts(uppercnv1,&condcode,&conddate,&condtime)))//~v74jI~
		  	if (pc)	//and/or cond                               //~v74jI~
				i=getcondts(pc,&condcode2,&conddate2,&condtime2);//~v74jR~
        if (i)	//err sign                                      //~v74jI~
        {                                                          //~v91rI~
			if (dbcsenv)	//DBCS mode v4.9a                   //~v74jI~
    	    	optionerr("ファイル選択条件",parmp[parmno]);//errmsg and exit v4.9a//~v74jR~
			else			//SBCS mode v4.9a	                //~v74jI~
        		optionerr("File Selection Condition",parmp[parmno]);//errmsg and exit v3.8r//~v74jR~
        }                                                          //~v91rI~
      break;
//**************************                                       //~v836I~
//* outfile name /Q                                                //~v836I~
//**************************                                       //~v836I~
    case 'Q':                                                      //~v836I~
        qfile=cptr;                                                //~v836I~
        if (!*qfile)                                               //~v920R~
//          uerrexit("filename missing for %cq parameter",         //~v920I~//~v973R~
//          		"%cq パラメータにファイル名がありません",      //~v920I~//~v973R~
            uerrexit("destination missing for %cq parameter",      //~v973I~
            		"%cq パラメータに宛先がありません",            //~v973I~
					CMDFLAG_PREFIX);                               //~v920I~
        if (!strcmp(qfile,STDOUTID))                               //~v90mR~
        {                                                          //~v90mR~
          Sstdoutsw=1;                                             //~v90mR~
          Gmsgfile=stderr;    //compmsg to stderr                  //~v90mR~
        }                                                          //~v90mR~
        else                                                       //~v90mR~
        if  (!strcmp(qfile,STDOUTID2))                             //~v90mR~
        {                                                          //~v926I~
          Sstdoutsw=1;          //to stdout                        //~v90mR~
          Gmsgfile=stdout;    //compmsg to stdout                  //~v926I~
        }                                                          //~v926I~
        else                                                       //~v926I~
        {                                                          //~v926I~
          Sstdoutsw=0;          //reset prev parm efect            //~v926I~
          Gmsgfile=stdout;    //compmsg to stdout                  //~v926I~
        }                                                          //~v926I~
      break;                                                       //~v836I~
//**************************                                       //~v90vI~
//* outfile name /Z                                                //~v90vI~
//**************************                                       //~v90vI~
    case 'Z':                                                      //~v90vI~
        switch(toupper(*cptr))                                     //~v90vI~
        {                                                          //~v90vI~
        case 'H':       //height                                   //~v90vI~
            if (toupper(*(cptr+1))=='L')                           //~v90vI~
            	Gzoomh=ZOOM_LETTER_H;                              //~v90vR~
            else                                                   //~v90vI~
            	Gzoomh=atoi(cptr+1);                               //~v90vR~
            break;                                                 //~v90vI~
        case 'W':       //width                                    //~v90vI~
            if (toupper(*(cptr+1))=='L')                           //~v90vI~
            	Gzoomw=ZOOM_LETTER_H;                              //~v90vI~
            else                                                   //~v90vI~
            	Gzoomw=atoi(cptr+1);                               //~v90vI~
            break;                                                 //~v90vI~
        default:                                                   //~v90vR~
			if (dbcsenv)	//DBCS mode v4.9a                      //~v90vI~
    	    	optionerr("頁圧縮率",parmp[parmno]);//errmsg and exit v4.9a//~v90vI~
			else			//SBCS mode v4.9a                      //~v90vI~
        		optionerr("Page Zoom rate",parmp[parmno]);//errmsg and exit v3.8r//~v90vI~
        }                                                          //~v90vI~
        if (Gzoomh<10||Gzoomw<10)                                  //~v90vR~
        	uerrexit("Zoom rate is to be >=10",                    //~v90vR~
            		 "頁圧縮率は10以上");                          //~v90vI~
      break;                                                       //~v90vI~
//**************************
//* set option     v3.3add */Y
//**************************
    case 'Y':             //v3.8a
//    while (*cptr)			//v7.1a                                //~v906R~
      do                                                           //~v906I~
	  {						//v7.1a
	      switch (toupper(*cptr)) //rv4.5
    	  {             
#ifdef UNX                                                         //~v90cI~
#else                                                              //~v90cI~
	      case 'A':           //v7.2a
    	    swgetarchive=1;		//print archive attr file only v7.2a
	        break; 				//v7.2a
#endif                                                             //~v90bR~
	      case 'B':                                             //~v74bI~
    	    UCBITON(swsw1,SW1BACKG);                            //~v74bI~
	        break;                                              //~v74bI~
	      case 'C':           //v3.8r 
          	UCBITON(swsw1,SW1CONFY);                            //~v74bI~
    	    swconfirm=1;
	        break; 
#ifdef OS2                                                         //~v916I~
	      case 'D':           	//v7.11a 
    	    docnamesw=1;		//v7.11a
	        break; 				//v7.11a
#endif                                                             //~v916I~
#ifdef W32                                                         //~v916I~
	      case 'D':                                                //~v916I~
    	    Gdriversetsw=1;		//specify orientation and form at createdc//~v916I~
	        break; 			                                       //~v916I~
#endif                                                             //~v916I~
#ifdef GTKPRINT                                                    //~v970I~
	      case 'D':                                                //~v970I~
    	    Gxpotheropt|=GOO_PRINTDIALOG;		//popup print dialog//~v970I~
	        break;                                                 //~v970I~
#endif                                                             //~v970I~
	      case 'E':
 	        escsw=1;
	        break; 
#ifndef GTKPRINT                                                   //~v97jI~
	      case 'F':				//fast path	v7.26a
 	        fastpathsw=1;		//v7.26a
	        break; 				//v7.26a
#endif                                                             //~v97jI~
	      case 'G':				//colomn gage output option v7.12a
	        header1outsw=1; 	//v7.12a
	        break; 				//v7.12a
	      case 'H':				//header0 output option v7.12a
	        header0outsw=1; 	//v7.12a
	        break; 				//v7.12a
	      case 'I':				//header0 output option v7.12a  //~v742I~
	        UCBITON(swsw1,SW1INDIRECT);                         //~v742I~
	        break; 				//v7.12a                        //~v742I~
#ifndef GTKPRINT                                                   //~v97kI~
	      case 'J':				//v7.1a
	        multiprintjob=1;	//v7.1a
	        break; 				//v7.1a
#endif                                                             //~v97kI~
//          case 'K':             //v7.1a                          //~v857R~
//            keisenreq=1;    //v7.1a                              //~v857R~
//            keisenconvsw=1;                                      //~v857R~
//            break;              //v7.1a                          //~v857R~
	      case 'L':           //crlf chk under (not hex)dump mode v6.7a
	        nocrlfsw=0;			//crlf chk v6.7a
	        break; 				//v6.7a
#ifdef UNX                                                         //~v922I~
#else                                                              //~v922I~
	      case 'M':           //v7.2a
	        swsetarchive=1;		//set archive attr after print v7.2a
	        break; 				//v7.2a
#endif                                                             //~v922I~
	      case 'N':           //line prefix output option v7.12a
	        lineprefixsw=1;		//v7.12a
	        break; 				//v7.12a
//          case 'O':           //oder file v4.6a                  //~v924R~
//            ordersw=1;          //v4.6a                          //~v924R~
//            break;              //v4.6a                          //~v924R~
	      case 'P':           //descending page v5.3a
	        despagesw=1;		//v5.3a
	        break; 				//v5.3a
#ifdef W32                                                         //~v905I~
	      case 'R':           //descending page v5.3a              //~v905I~
	        UCBITOFF(swsw3,SW3WINNPNR);   //restore when newpage   //~v905R~
	        break; 				//v5.3a                            //~v905I~
#endif                                                             //~v905I~
	      case 'S':           //same as above chk                 v6.7a
	        samechk=1;			//chk      v6.7a
	        break; 				//v6.7a
	      case 'T':           //trace option                       //~v889I~
	        Gtraceopt=1;		                                   //~v889I~
	        break; 				                                   //~v889I~
	      case 'U':         //skip formfeed(0x0c) at page eject    //~v91xI~
    	    UCBITOFF(swsw4,SW4NOFFCMD); //write FF                 //~v91xI~
	        break;                                                 //~v91xI~
	      case 'V':                                                //~v801I~
    	    UCBITON(swsw3,SW3CONJUNCT);                            //~v801M~
	        break; 			                                       //~v801M~
	      case '0':           //stdin as handle 0               //~v742I~
	        UCBITOFF(swsw1,SW1NOSTDIN);	//filename stdin is handle 0//~v742I~
	        break; 				//v6.7a                         //~v742I~
	      case '1':                                                //~v785I~
	        UCBITON(swsw2,SW21STPAGEOPT|SW21STPAGEEJECT);	//1st page eject option//~v785I~
	        break;                                                 //~v785I~
//#ifdef W32                                                       //~v90kR~
	      case '2':                                                //~v904I~
    	    UCBITON(swsw3,SW3WIN2P);                               //~v904I~
	        break;                                                 //~v904I~
//#endif                                                           //~v90kR~
#if defined(LNX) && !defined(GXP)                                  //~v92nI~
	      case '3':           //16 byte hex dump v6.7a             //~v92nI~
    	    UCBITON(swsw4,SW4SS3);                                 //~v92nI~
	        break; 				//v6.7a                            //~v92nI~
#endif                                                             //~v92nI~
	      case '6':           //16 byte hex dump v6.7a
	        dumpwidth=16;		//16 byte dump length per line v6.7a
	        break; 				//v6.7a
	      case '8':           //utf8 code for vhex dump            //~v960I~
	        swyn8=1;                                               //~v960I~
            Gxpotheropt&=~GOO_VHEXBYUCS;                           //~v960I~
	        break; 				//v6.7a                            //~v960I~
	      case '9':         	//force dbcs env (cp 932)v7.291a
			UCBITON(Guerropt,GBL_UERR_DBCSSET);	//external set     //~v801I~
			UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs for uerrexit//~v801I~
			uerrmsg_init("",stdout,0);                             //~v907I~
	        dbcsenv=1;     		//v7.291a
	        break; 				//v7.291a
	      default: 
			if (dbcsenv)	//DBCS mode v4.9a
	        	optionerr("トグル設定",parmp[parmno]);  //errmsg and exit v4.9a
			else			//SBCS mode v4.9a	
	        	optionerr("Set",parmp[parmno]);  //errmsg and exit v3.8r
	      }//switch by set option
		  cptr++;			//v7.1a
      }//until strlen v7.1a
      while (*cptr);                                               //~v906I~
      break;
//**************************
//* reset option   v3.7a   */N
//**************************
    case 'N':
//    while (*cptr)			//v7.1a                                //~v906R~
      do                                                           //~v906I~
	  {						//v7.1a
	      switch (toupper(*cptr))
    	  {             
#ifdef UNX                                                         //~v90cI~
#else                                                              //~v90cI~
	      case 'A':           //v7.2a
    	    swgetarchive=0;		//not print archive attr file only v7.2a
	        break; 				//v7.2a
#endif                                                             //~v90cI~
	      case 'B':                                             //~v74bI~
    	    UCBITOFF(swsw1,SW1BACKG);                           //~v74bI~
	        break;                                              //~v74bI~
	      case 'C':           //v3.8r 
	        swconfirm=0;
	        break; 
#ifdef OS2                                                         //~v916I~
	      case 'D':           	//v7.11a 
    	    docnamesw=0;		//v7.11a
	        break; 				//v7.11a
#endif                                                             //~v916I~
#ifdef W32                                                         //~v916I~
	      case 'D':                                                //~v916I~
//  	    Gdriversetsw=1;		//specify orientation and form at createdc//~v91gR~
    	    Gdriversetsw=0;		//specify orientation and form at createdc//~v91gI~
	        break;                                                 //~v916I~
#endif                                                             //~v916I~
#ifdef GTKPRINT                                                    //~v970I~
	      case 'D':                                                //~v970I~
    	    Gxpotheropt&=~GOO_PRINTDIALOG;		//No popup print dialog//~v970I~
	        break;                                                 //~v970I~
#endif                                                             //~v970I~
	      case 'E':
	        escsw=0;
	        break; 
#ifndef GTKPRINT                                                   //~v97jI~
	      case 'F':				//fast path	v7.26a
 	        fastpathsw=0;		//v7.26a
	        break; 				//v7.26a
#endif                                                             //~v97jI~
	      case 'G':				//colomn gage output v7.12a
	        header1outsw=0; 	//v7.12a
	        break; 				//v7.12a
	      case 'H':				//header0 output option v7.12a
	        header0outsw=0; 	//v7.12a
	        break; 				//v7.12a
	      case 'I':				//header0 output option v7.12a  //~v742I~
	        UCBITOFF(swsw1,SW1INDIRECT);                        //~v742I~
	        break; 				//v7.12a                        //~v742I~
#ifndef GTKPRINT                                                   //~v97kI~
	      case 'J':				//v7.1a
	        multiprintjob=0;	//v7.1a
	        break; 				//v7.1a
#endif                                                             //~v97kI~
//          case 'K':             //v7.1a                          //~v857R~
//            keisenreq=1;    //v7.1a                              //~v857R~
//            keisenconvsw=0;                                      //~v857R~
//            break;              //v7.1a                          //~v857R~
	      case 'L':           //crlf chk under (not hex)dump mode v6.7a
	        nocrlfsw=1;			//crlf chk v6.7a
	        break; 				//v6.7a
#ifdef UNX                                                         //~v922I~
#else                                                              //~v922I~
	      case 'M':           //v7.2a
	        swsetarchive=0;		//not set archive attr after print v7.2a
	        break; 				//v7.2a
#endif                                                             //~v922I~
	      case 'N':           //line prefix output option v7.12a
	        lineprefixsw=0;		//v7.12a
	        break; 				//v7.12a
//          case 'O':           //oder file v4.6a                  //~v924R~
//            ordersw=0;          //v4.6a                          //~v924R~
//            break;              //v4.6a                          //~v924R~
	      case 'P':           //descending page v5.3a
	        despagesw=0;		//v5.3a
	        break; 				//v5.3a
#ifdef W32                                                         //~v905I~
	      case 'R':           //descending page v5.3a              //~v905I~
	        UCBITON(swsw3,SW3WINNPNR);   //restore when newpage    //~v905R~
	        break; 				//v5.3a                            //~v905I~
#endif                                                             //~v905I~
	      case 'S':           //no same as above chk              v6.7a
	        samechk=0;			//no chk   v6.7a
	        break; 				//v6.7a
	      case 'T':           //trace option                       //~v889I~
	        Gtraceopt=0;                                           //~v889I~
	        break;                                                 //~v889I~
	      case 'U':         //skip formfeed(0x0c) at page eject    //~v91xI~
    	    UCBITON(swsw4,SW4NOFFCMD); //skip write FF             //~v91xI~
            skip1stff=0;				//also before 1st page     //~v91xI~
	        break;                                                 //~v91xI~
	      case 'V':                                                //~v801I~
    	    UCBITOFF(swsw3,SW3CONJUNCT);                           //~v801M~
	        break; 			                                       //~v801M~
	      case '0':           //stdin as handle 0               //~v742I~
	        UCBITON(swsw1,SW1NOSTDIN);	//filename stdin is handle 0//~v742I~
	        break; 				//v6.7a                         //~v742I~
	      case '1':                                                //~v785I~
	        UCBITON(swsw2,SW21STPAGEOPT);		//1st page eject option specified//~v785I~
	        UCBITOFF(swsw2,SW21STPAGEEJECT);	//no 1st page eject option//~v785I~
	        break;                                                 //~v785I~
//#ifdef W32                                                       //~v90kR~
	      case '2':                                                //~v904I~
    	    UCBITOFF(swsw3,SW3WIN2P);	//no 2part print           //~v904I~
	        break;                                                 //~v904I~
//#endif                                                           //~v90kR~
#if defined(LNX) && !defined(GXP)                                  //~v92nI~
	      case '3':           //16 byte hex dump v6.7a             //~v92nI~
    	    UCBITOFF(swsw4,SW4SS3);                                //~v92nI~
	        break; 				//v6.7a                            //~v92nI~
#endif                                                             //~v92nI~
	      case '6':           //16 byte hex dump v6.7a
	        dumpwidth=32;		//32 byte dump length per line v6.7a
	        break; 				//v6.7a
	      case '8':           //utf8 code for vhex dump            //~v960I~
	        swyn8=1;                                               //~v960I~
            Gxpotheropt|=GOO_VHEXBYUCS;                            //~v960I~
	        break; 				//v6.7a                            //~v960I~
	      case '9':         	//force dbcs env (cp 932)v7.291a
			UCBITON(Guerropt,GBL_UERR_DBCSSET);	//external set     //~v801I~
			UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs            //~v801I~
			uerrmsg_init("",stdout,UERR_FORCE_ENGLISH);            //~v907I~
	        dbcsenv=0;     		//v7.291a
	        break; 				//v7.291a
	      default: 
			if (dbcsenv)	//DBCS mode v4.9a
	        	optionerr("トグル設定解除",parmp[parmno]);  //errmsg and exit v4.9a
			else			//SBCS mode v4.9a	
	        	optionerr("Reset",parmp[parmno]);  //errmsg and exit v3.8r
	      }//switch by /Nx
		  cptr++;			//v7.1a
      }//until strlen v7.1a
      while (*cptr);                                               //~v906I~
      break;
//**************************
//* option err             *
//**************************
    default:                           //not option       //v2.4add
	  if (dbcsenv)	//DBCS mode v4.9a
      	printf("%s:%s:%s は認識できません\n",pgmid,ver,parmp[parmno]);//v4.9a
	  else			//SBCS mode v4.9a	
      	printf("%s:%s:undefined option parm(%s)\n",pgmid,ver,parmp[parmno]);//v2.6addv3.8r
      uexit(4);                                                 //~v742R~
    }//switch  by first option byte                          //v2.0add
  }
  else
  {//positional parmno
    posparmno++;
//#ifdef UNX                                                       //~v920R~
    if (posparmno==1)	//first time                               //~v90fI~
    {                                                              //~v90fI~
    	posparmno=1;				//all concatinated             //~v90fI~
      	parmfname=Sunixexpandfnm;	//top addr                     //~v90fI~
      	strcpy(parmfname,cptr);	  		//for strcat               //~v90fI~
        unixexpandfnm=parmfname+strlen(cptr);		//next strcat addr//~v90fI~
    }                                                              //~v90fI~
    else                                                           //~v90fI~
    	unixexpandfnm+=sprintf(unixexpandfnm,"%c%s",MULTI_SEPC,cptr);//~v90fI~
//#else   //!UNX                                                   //~v920R~
//    switch (posparmno)                                           //~v920R~
//    {                                                            //~v920R~
////**************************                                     //~v920R~
////* input file             *                                     //~v920R~
////**************************                                     //~v920R~
//    case  1:          //first parm //v2.6add                     //~v920R~
//      parmfname=cptr;  //v3.7a                                   //~v920R~
//      Gparmfname=malloc(strlen(parmfname)+1); //save over uindirect/umultifnlist//~v920R~
//      strcpy(Gparmfname,parmfname);                              //~v920R~
//      break;                                 //v2.6add           //~v920R~
////**************************                                     //~v920R~
////* output file            *                                     //~v920R~
////**************************                                     //~v920R~
//    case 2: // 2nd parm             v2.6add                      //~v920R~
//      if (*cptr!=',')             //v2.6add                      //~v920R~
//        pofile=cptr;                                             //~v920R~
////      {                                                        //~v920R~
////        strcpy(uppercnv1,cptr);     //for get except ext    v5.3a//~v920R~
////        pc=strpbrk(uppercnv1,".");              //v5.3a     v7.0r//~v920R~
////        if (pc)             //v5.3a                         v7.0r//~v920R~
////            *pc=0;                  //drop extention v5.3a     //~v920R~
////        if (!(pc=strrchr(uppercnv1,'\\')))  //search last \ v5.3a//~v920R~
////            if (!(pc=strrchr(uppercnv1,':')))// search last : v5.3a//~v920R~
////                pc=uppercnv1-1;     //not found chk first      //~v920R~
////        if (!stricmp(pc+1,pgmid))   //same as pgmname v5.3r    //~v920R~
////        {                                                      //~v920R~
////          if (dbcsenv)  //DBCS mode v5.3a                      //~v920R~
////            printf("%s:%s:%s ? えっエー！！\n",pgmid,ver,cptr);//v5.3a//~v920R~
////          else          //SBCS mode v5.3a                      //~v920R~
////            printf("%s:%s:%s ? Oup!!\n",pgmid,ver,cptr); //v5.3a//~v920R~
////          uexit(4);                                            //v5.3a//~v920R~
////        }                                                      //~v920R~
////        prn=cptr;                            //v2.6add         //~v920R~
////        if (stricmp(prn,"PRN")              //v7.1a            //~v920R~
////        &&  stricmp(prn,"LPT1")         //v7.1a                //~v920R~
////        &&  stricmp(prn,"LPT2")         //v7.1a                //~v920R~
////        &&  stricmp(prn,"LPT3"))            //v7.1a            //~v920R~
////            outdevprn=0;                    //output is not printer v7.1a//~v920R~
////      }                                                        //~v920R~

//      break;                                 //v2.6add           //~v920R~
////************************************                           //~v920R~
//    default:                                                     //~v920R~
//      if (dbcsenv)  //DBCS mode v4.9a                            //~v920R~
//        printf("%s:%s:パラメータが多過ぎます(%s)\n",pgmid,ver,cptr);//v4.9a//~v920R~
//      else          //SBCS mode v4.9a                            //~v920R~
//        printf("%s:%s:too many positional parameter(%s)\n",pgmid,ver,cptr); //v2.6repv3.8r//~v920R~
//      uexit(4);                                            //v1.5add//~v920R~
//    }//switch by parmno //v2.6add                                //~v920R~
//#endif  //!UNX                                                   //~v920R~
  }//option or posparm       //v2.6add
}//for all parm                                  //v2.6add
#ifdef UTF8SUPP                                                    //~v928I~
    if (utf8sw)                                                    //~v928I~
        Gxputfstat=GXPUS_UTF8ON;                                   //~v928I~
#endif                                                             //~v928I~
//***no pos parm chk v6.7a
	if (!posparmno)
	{
	  if (dbcsenv)	//DBCS mode
      	printf("%s:%s:入力ファイルを指定して下さい\n",pgmid,ver);
	  else			//SBCS mode
      	printf("%s:%s:specify file name to be printed.\n",pgmid,ver);
      uexit(4);                                                 //~v742R~
	}
    if (UCBITCHK(swsw3,SW3SCRPRT))                                 //~v96uR~
    {                                                              //~v96uI~
        recordsz=0;                                                //~v96uI~
    	vfmt=0;	//screen print data is text file                   //~v96uI~
    }                                                              //~v96uI~
    Gparmfname=malloc(strlen(parmfname)+1);//for conjunct mode print start msg//~v920I~
    strcpy(Gparmfname,parmfname);                                  //~v920I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
    if (Gebcdictype==3)	//when cfg file,defaulkt by loacle env     //~v941I~
//  	xpebc_init(0,0);                                             //~v941I~//~v942R~//~v953R~
    	xpebc_init(0,pebccfgfname);                                //~v953R~
    else                                                           //~v953I~
    {                                                              //~v953I~
        if (pebccfgfname || pebccvname||(swsw5 & SW5USEICU))                            //~v953R~//~v96hR~
//          uerrexit("cfg filename or convertername specified, but missing charset=EBCDIC specification?",0);//~v953R~//~v96eR~
            uerrexit("-BCcfgfnm or -CPEB=cp or -ICU requires -Me(charset:EBCDIC)",//~v96eI~//~v96hR~
            		 "-BCcfgfnm または CPEB=cp または -ICU のとき -Me(EBCDIC文字セット)を指定する");//~v96eI~//~v96hR~
    }                                                              //~v953I~
#endif          //EBCDIC dbcs support                              //~v941I~
//**********************************
//* init                           *
//**********************************
	if (swsw4 & SW4VHEXMODE)    //from xe, 3line vhex dump work file print//~v96qI~
    {                                                              //~v96qI~
    	recordsz=0;	//-R parm is trailer print only;               //~v96qI~
    }                                                              //~v96qI~
    if (recordsz && vfmt)                                          //~v96eR~
        errexclusive("V","R");                                     //~v96eR~
    if (recordsz || vfmt)                                          //~v96DI~
    {                                                              //~v96DI~
        if (swtabparm)                                             //~v96DI~
            uerrexit("TAB parm is invalid for fixed/variable length record mode",//~v96DR~
					"固定長/可変長レコードモードではTABパラメータは無効です");//~v96DI~
        tabskip=1;                                                 //~v96DI~
    }                                                              //~v96DI~
//outfilename get                                                  //~v836I~
	if (pofile && qfile)	//outfile by both /Q and 2nd parm      //~v836I~
	{                                                              //~v836I~
    	cptr=NULL;                                                 //~v965I~
	  	if (dbcsenv)	//DBCS mode                                //~v836I~
      		printf("%s:%s:出力ファイルの重複指定(%s と %s)\n",     //~v836R~
				pgmid,ver,pofile,qfile);                           //~v836I~
	  	else			//SBCS mode                                //~v836I~
      		printf("%s:%s:duplicated output specification(%s and %s)\n",//~v836R~
				pgmid,ver,pofile,qfile);                           //~v836I~
      	uexit(4);                                                  //~v836I~
	}                                                              //~v836I~
    else                                                           //~v836I~
    {                                                              //~v836R~
		if (pofile)                                                //~v836I~
        	cptr=pofile;                                           //~v836I~
        else                                                       //~v836I~
        	cptr=qfile;                                            //~v836I~
		if (cptr)                                                  //~v836I~
        {                                                          //~v836I~
#ifdef UTF8SUPP                                                    //~v928I~
            UCBITON(swsw4,SW4OUTFILE);                             //~v928I~
//         	if (Sstdoutsw);                                        //~v92mI~//~v970R~
           	if (Sstdoutsw)                                         //~v970I~
	            UCBITON(swsw4,SW4OUTSTDO);                         //~v92mI~
#endif                                                             //~v928I~
            strcpy(uppercnv1,cptr);     //for get except ext    v5.3a//~v836R~
#ifdef UNX  //chk by full name(under unix no extention like as .bat)//~v907I~
#else                                                              //~v907I~
            pc=strpbrk(uppercnv1,".");              //v5.3a     v7.0r//~v836R~
            if (pc)             //v5.3a                         v7.0r//~v836R~
                *pc=0;                  //drop extention v5.3a     //~v836R~
#endif                                                             //~v907I~
//          if (!(pc=strrchr(uppercnv1,'\\')))  //search last \ v5.3a//~v907R~
            if (!(pc=strrchr(uppercnv1,DIR_SEPC)))  //search last \ v5.3a//~v907I~
#ifdef UNX                                                         //~v907I~
#else                                                              //~v907I~
                if (!(pc=strrchr(uppercnv1,':')))// search last : v5.3a//~v836R~
#endif                                                             //~v907I~
                    pc=uppercnv1-1;     //not found chk first      //~v836R~
#ifdef UNX                                                         //~v907I~
            if (!strcmp(pc+1,pgmid))   //same as pgmname v5.3r     //~v907I~
#else                                                              //~v907I~
            if (!stricmp(pc+1,pgmid))   //same as pgmname v5.3r    //~v836R~
#endif                                                             //~v907I~
            {                                                      //~v836R~
              if (dbcsenv)  //DBCS mode v5.3a                      //~v836R~
                printf("%s:%s:%s ? えっエー！！\n",pgmid,ver,cptr);//v5.3a//~v836R~
              else          //SBCS mode v5.3a                      //~v836R~
                printf("%s:%s:%s ? Oup!!\n",pgmid,ver,cptr); //v5.3a//~v836R~
              uexit(4);                                            //v5.3a//~v836R~
            }                                                      //~v836R~
            prn=cptr;                            //v2.6add         //~v836R~
#ifdef W32                                                         //~v860I~
            outdevprn=win_portchk(prn);                            //~v860R~
#else                                                              //~v860I~
            if (stricmp(prn,"PRN")              //v7.1a            //~v836R~
            &&  stricmp(prn,"LPT1")         //v7.1a                //~v836R~
            &&  stricmp(prn,"LPT2")         //v7.1a                //~v836R~
            &&  stricmp(prn,"LPT3"))            //v7.1a            //~v836R~
                outdevprn=0;                    //output is not printer v7.1a//~v836R~
#endif                                                             //~v860I~
    	}                                                          //~v836R~
    }                                                              //~v836I~
#ifdef GXP                                                         //~v92dI~
    outdevprn=lnx_init(parmc,parmp);                               //~v92dR~
#endif                                                             //~v92dI~
    if (UCBITCHK(swsw3,SW3FORM2P))	//form2p                       //~v911R~
    {                                                              //~v911I~
        if (UCBITCHK(swsw3,SW3WIN2P)) // /y2                       //~v911R~
        {                                                          //~v911R~
            if (dbcsenv)                                           //~v911R~
                printf("2頁/1枚 印刷は /Y2か /Eの用紙指定かどちらか一方で指定する。\n");//~v911R~
            else                                                   //~v911R~
                printf("request 2-page/1-sheet print by /Y2 OR Form of /E parm.\n");//~v911R~
              uexit(4);                                            //v5.3a//~v911R~
        }                                                          //~v911R~
    	if (hexdump)		//hexdumpmode                          //~v913R~
        {                                                          //~v913R~
            if (dbcsenv)                                           //~v913R~
                printf("ヘキサダンプで 2頁/1枚 印刷は /Y2 のみ指定可\x94\\。\n");//~v916R~
            else                                                   //~v913R~
                printf("request 2-page/1-sheet by /Y2 when hex-dump mode.\n");//~v913R~
              uexit(4);                                            //v5.3a//~v913R~
        }                                                          //~v913R~
    }                                                              //~v911I~
    if (swsw4 & SW4VHEXMODE)                                       //~v91rI~
    {                                                              //~v91rI~
        if (lineprefixsw)                                          //~v91rI~
            uerrexit("/Nn required for vhex mode",0);              //~v91rI~
    }                                                              //~v91rI~
#ifdef W32        	                                               //~v858M~
//printf("prn=%d,prntyp=%d,prntyp=%c\n",outdevprn,prntypsw,prntyp);//~v860R~
    if (UCBITCHK(swsw3,SW3WIN2P))                                  //~v904I~
    {                                                              //~v911I~
//        if (prntyp!=PRINTER_WIN)                                 //~v911R~
//        {                                                        //~v911R~
//            if (dbcsenv)                                         //~v911R~
//                printf("2頁/1枚 印刷はプリンタータイプ = W の時のみです\n");//~v911R~
//            else                                                 //~v911R~
//                printf("2-page/1-sheet print is for printer-type=W only.\n");//~v911R~
//              uexit(4);                                            //v5.3a//~v911R~
//         }                                                       //~v911R~
    }                                                              //~v911I~
    if (!outdevprn)			//output to file                       //~v858I~
        if (prntypsw)       //prntype parm specified               //~v858I~
        {                                                          //~v858I~
            if (prntyp==PRINTER_WIN)                               //~v858I~
            {                                                      //~v858I~
                if (dbcsenv)  //DBCS mode v5.3a                    //~v858I~
                    printf("%s:%s:%s 出力ファイル指定とプリンタータイプ = W の指定は両立しません\n",//~v858I~
                        pgmid,ver,cptr);//v5.3a                    //~v858I~
                else            //SBCS mode v5.3a                  //~v858I~
                     printf("%s:%s:%s Output file specification and printertype=W is inconsistent\n",//~v858I~
                    pgmid,ver,cptr); //v5.3a                       //~v858I~
                  uexit(4);                                            //v5.3a//~v858I~
             }                                                     //~v858I~
        }                                                          //~v858I~
        else                                                       //~v858I~
            prntyp=PRINTER_IBM;     //reset default to IBM         //~v858I~
                                                                   //~v916I~
    if (prntyp!=PRINTER_WIN)                                       //~v916I~
    	if (Gdriversetsw==1) 	//parm request                     //~v916I~
    		printf("%cYd parm ignored for printer-type!=W\n",CMDFLAG_PREFIX);//~v916R~
#endif                                                             //~v858M~
#ifdef GXP                                                         //~v92dI~
    if (!outdevprn)			//output to file                       //~v92dI~
    {                                                              //~v92dI~
        if (prntypsw)       //prntype parm specified               //~v92dI~
        {                                                          //~v92dI~
            if (prntyp==PRINTER_WIN)                               //~v92dI~
                uerrexit("Output file specification and printertype=W is inconsistent",//~v92dR~
                         "出力ファイル指定とプリンタータイプ = W の指定は両立しません");//~v92dR~
        }                                                          //~v92dI~
#ifndef GTKPRINT        		                                   //~v970I~
        else                                                       //~v92dI~
            prntyp=PRINTER_IBM;     //reset default to IBM         //~v92dI~
#endif                                                             //~v970I~
    }                                                              //~v92dI~
#endif                                                             //~v92dI~
                                                                   //~v865I~
#ifdef OS2                                                         //~v863I~
	if (docnamesw=os2_devinit(prn,outdevprn,docnamesw),docnamesw)	//q found//~v863R~
		outdevprn=1;                //dest is not LPTx but qname   //~v863R~
//printf("outdevprn=%d,docnamesw=%d\n",outdevprn,docnamesw);       //~v878R~
#endif                                                             //~v863I~
//*****************                                                //~v836I~
	escdefaultmax(prntyp);		    //default maxcol/maxline by form//~v74lR~
//*process font style parm start  v7.24a
	escfontchk(prntyp,fontstyle);				//logic moved to xpesc//~v783R~
//#ifdef W32                                                       //~v92dR~
#if defined(W32) || defined(GXP)                                   //~v92dI~
    if (UCBITCHK(swsw3,SW3WINTATE))	//escfontchk chk tate/yoko form//~v904I~
    	if (!linespec && !lpitch)	//no linecount and line pitch  //~v904R~
			 if (UCBITCHK(swsw3,SW3WIN2P))	//double page print req//~v904I~
               if (prntyp==PRINTER_WIN)                            //~v911I~
             	maxline+=maxline;			//double line count    //~v904I~
#endif                                                             //~v904I~
//*process font style parm end  v7.24a
//*****************
//  strcpy(docname,parmfname);		//doc name for /Nj case v7.11a //~v97nR~
    UstrncpyZ(docname,parmfname,sizeof(docname));		//doc name for /Nj case v7.11a//~v97nI~
	if (!fastpathsw)				//2 phase process v7.26a
	{								//v7.26a
      if (swsw4 & SW4VHEXMODE)      //vhex mode,dose not use file cache//~v91rI~
      {                                                            //~v91rI~
        vhexlinech=malloc(MAXTEXTINPLINESZ*3);	//vhexline work    //~v91rR~
        if (!vhexlinech)                                           //~v91rR~
        	uerrexit("malloc failed for vhexmode buff,sz=%d",0,MAXTEXTINPLINESZ*3);//~v91rI~
        memset(vhexlinech,0,MAXTEXTINPLINESZ*3);	//need clear   //~v97GI~
        vhexlinex1=vhexlinech+MAXTEXTINPLINESZ;                    //~v91rR~
        vhexlinex2=vhexlinex1+MAXTEXTINPLINESZ;                    //~v91rI~
      }                                                            //~v91rI~
      else                                                         //~v91rI~
		databufft=malloc((UINT)DATABUFFSZ);	//input data save v5.8a//~v766R~
		if (despagesw)		//page descending order print v7.0a
		{													//v7.0a	
			poswkbufft=(FPOST*)malloc(POSWKMAXPAGE*sizeof(FPOST));	//pos work buff v5.8av7.0r
			pagebufft=malloc((UINT)PAGEWKSZ);	//page work buff v5.8a//~v766R~
		}													//v7.0a	
	}//v7.26a
//restart page                                                  //~v74nI~
	if (pagefilesw)			//resume file sw                    //~v74nI~
		if (!UCBITCHK(swsw2,SW2PAGERANGE))	//nor range specified//~v74nI~
        {                                                          //~v91rI~
			if (despagesw)		//page descending order print   //~v74nI~
				pagerange[0]=pagestart=1;	//from start        //~v74nR~
			else                                                //~v74nI~
				pagerange[1]=pageend=MAXPAGE;	//up to end     //~v74nI~
        }                                                          //~v91rI~
//dumpwidth and recordsz v6.7a start
	if (dumpmode==-1)		//no dumpmode specified
    {                                                              //~v91rI~
		if (recordsz)	//record mode parm specified
			dumpmode=1;	//assume dumpmode
		else		
        if (vfmt)                                                  //~v96eI~
			dumpmode=1;	//assume dumpmode                          //~v96eI~
		else                                                       //~v96eI~
			dumpmode=0;	//assume dumpmode
    }                                                              //~v91rI~
    if (textmodevhexsw && recordsz)                                //~v96kI~
    {                                                              //~v96kI~
        dumpmode=1;                                                //~v96kI~
        textmodevhexsw=0;                                          //~v96kI~
        vhexdump=2;         //recordmode vhex dump                 //~v96kI~
    }                                                              //~v96kI~
//  if (dumpmode!=1 && recordsz)                                   //~v96kR~
    if (dumpmode==2 && recordsz)                                   //~v96kI~
    {
	  if (dbcsenv)	//DBCS mode
//       printf("%s:%s:テキストまたはスキムダンプモードでは %cR オプションは指定できません。\n",//~v907R~//~v96kR~
         printf("%s:%s:スキムダンプモードでは %cR オプションは指定できません。\n",//~v96kI~
					pgmid,ver,CMDFLAG_PREFIX);                     //~v907I~
	  else			//SBCS
//       printf("%s:%s:%cR option is not avail with Text mode nor Skim dump mode\n",//~v907R~//~v96kR~
         printf("%s:%s:%cR option is not avail with Skim dump mode\n",//~v96kI~
					pgmid,ver,CMDFLAG_PREFIX);                     //~v907I~
      uexit(4);                                                 //~v742R~
    }
    if (textmodevhexsw && vfmt)                                    //~v96eI~
    {                                                              //~v96eI~
        dumpmode=1;                                                //~v96eI~
        vhexdump=3;         //recordmode vhex dump                 //~v96kI~
        textmodevhexsw=0;                                          //~v96eI~
    }                                                              //~v96eI~
	if (dumpmode==2 && vfmt)                                       //~v96eR~
    {                                                              //~v96eI~
	  if (dbcsenv)	//DBCS mode                                    //~v96eI~
         printf("%s:%s:スキムダンプモードでは %cV オプションは指定できません。\n",//~v96eR~
					pgmid,ver,CMDFLAG_PREFIX);                     //~v96eI~
	  else			//SBCS                                         //~v96eI~
         printf("%s:%s:%cV option is not avail with Skim dump mode\n",//~v96eR~
					pgmid,ver,CMDFLAG_PREFIX);                     //~v96eI~
      uexit(4);                                                    //~v96eI~
    }                                                              //~v96eI~
	if (dumpmode && ffrepl!=-1)	//dumpmode and form feed replace char//~v765R~
    {                                                              //~v765I~
	  if (dbcsenv)	//DBCS mode                                    //~v765I~
//       printf("%s:%s:レコードモードでないテキストモード以外では %cFFX オプションは指定できません。\n",//~v907R~//~v96sR~
         printf("%s:%s:テキストモード以外では %cFFX オプションは指定できません。\n",//~v96sI~
					pgmid,ver,CMDFLAG_PREFIX);                     //~v907I~
	  else			//SBCS                                         //~v765I~
//       printf("%s:%s:%cFFX option is not avail except under Text mode w/o Record option\n",//~v907R~//~v96sR~
         printf("%s:%s:%cFFX option is not avail except under Text mode.\n",//~v96sI~
					pgmid,ver,CMDFLAG_PREFIX);                     //~v907I~
      uexit(4);                                                    //~v765I~
    }                                                              //~v765I~
	if (dumpmode==1 && !recordsz)	//dumpmode without record parm v7.21a
		if (nocrlfsw)		//v7.21a
          if (!vfmt)                                               //~v96eI~
			recordsz=-1;	//asume record mode v7.21a
	if (recordsz==-1)		//record dump,recsz is same as maxcol
		recordsz=maxcol;
	if (recordsz)
	{
//  	colomnspec=1;                                              //~v96fR~
//      if (recordsz<maxcol)        //record dump,recsz is same as maxcol//~v96fR~
//          maxcol=recordsz;                                       //~v96fR~
//		if (hexdump)		//hexdumpmode                          //~v96kR~
  		if (vhexdump)		//hexdumpmode                          //~v96kI~
		{
//  		if (maxcol!=recordsz)	//not 1 line record            //~v96fR~
//            if (recordsz>=maxcol)        //record dump,recsz is same as maxcol//~v96fI~//~v96uR~
//            {                                                    //~v96uR~
//                if (samechk==1)     // /Ys option specified      //~v96uR~
//                {                                                //~v96uR~
//                  if (dbcsenv)  //DBCS mode                      //~v96uR~
//                     printf("%s:%s:複数行レコードヘキサダンプ では　%cYs オプションは使えません。\n",//~v907R~//~v96uR~
//                            pgmid,ver,CMDFLAG_PREFIX);             //~v907I~//~v96uR~
//                  else          //SBCS                           //~v96uR~
//                     printf("%s:%s:%cYs option is not avail when multi-line record hexdump.\n",//~v907R~//~v96uR~
//                            pgmid,ver,CMDFLAG_PREFIX);             //~v907I~//~v96uR~
//                  uexit(4);                                     //~v742R~//~v96uR~
//                }                                                //~v96uR~
//                samechk=0;          //reset default(samechk)     //~v96uR~
//            }                                                    //~v96uR~
//          if (samechk==-1)                                       //~v96uI~//~v96AR~
//              samechk=0;                                         //~v96uI~//~v96AR~
			dumpwidth=maxcol;
		}	
  		if (!hexdump)		//hexdumpmode                          //~v96AI~
          	if (samechk==-1)                                       //~v96AI~
            	samechk=0;                                         //~v96AI~
	}
    else                                                           //~v96eI~
	if (vfmt)                                                      //~v96eI~
	{                                                              //~v96eI~
//  	colomnspec=1;                                              //~v96eI~//~v96kR~
//  	if (hexdump)		//hexdumpmode                          //~v96eI~//~v96kR~
  		if (vhexdump)		//vhx dump                             //~v96kI~
		{                                                          //~v96eI~
//            if (samechk==1)     // /Ys option specified            //~v96eI~//~v96uR~
//            {                                                      //~v96eI~//~v96uR~
//              if (dbcsenv)  //DBCS mode                            //~v96eI~//~v96uR~
//                 printf("%s:%s:可変長レコードファイルヘキサダンプ では %cYs オプションは使えません。\n",//~v96eI~//~v96uR~
//                        pgmid,ver,CMDFLAG_PREFIX);                 //~v96eI~//~v96uR~
//              else          //SBCS                                 //~v96eI~//~v96uR~
//                 printf("%s:%s:%cYs option is not avail for variable record length file hexdump.\n",//~v96eI~//~v96uR~
//                        pgmid,ver,CMDFLAG_PREFIX);                 //~v96eI~//~v96uR~
//              uexit(4);                                            //~v96eI~//~v96uR~
//            }                                                      //~v96eI~//~v96uR~
//        if (samechk==-1)     //no parm                           //~v96uI~//~v96AR~
//          samechk=0;          //reset default(samechk)           //~v96eI~//~v96AR~
			dumpwidth=maxcol;                                      //~v96eI~
		}                                                          //~v96eI~
  		if (!hexdump)		//hexdumpmode                          //~v96AI~
          	if (samechk==-1)                                       //~v96AI~
            	samechk=0;                                         //~v96AI~
	}                                                              //~v96eI~
	else
		if (hexdump)		//hexdumpmode
		{
			if (colomnspec)
			{
				if (dbcsenv)	//DBCS mode
//      			printf("%s:%s:レコードモードでないヘキサダンプ で %cC オプションは使えません。\n",//~v907R~//~v96kR~
        			printf("%s:%s:ヘキサダンプ で %cC オプションは使えません。\n",//~v96kI~
							pgmid,ver,CMDFLAG_PREFIX);             //~v907I~
				else			//SBCS
//  				printf("%s:%s:%cC option is not available under not recode mode hex-dump.\n",//~v907R~//~v96kR~
    				printf("%s:%s:%cC option is not available for hex-dump.\n",//~v96kI~
							pgmid,ver,CMDFLAG_PREFIX);             //~v907I~
				uexit(4);                                       //~v742R~
			}
			colomnspec=1;
			maxcol=dumpwidth;
		}
    if (eolprintfmt)                                               //~v96kI~
    {                                                              //~v96kI~
		if (hexdump||!vfmt)	                                       //~v96kI~
        {                                                          //~v96kI~
            uerrexit("%c%s is for VariableRecordLength file without horizontal hexdump option",//~v96kR~//~v96nR~//~v96sR~
                     "%c%s は可変長レコードファイルの横ヘキサダンプ以外で使用",//~v96kI~//~v96nR~//~v96sR~
                        CMDFLAG_PREFIX,PARM_EOLPRINT);             //~v96kR~
        }                                                          //~v96kI~
    }                                                              //~v96kI~
	if (samechk==1&&!hexdump)		// /Ys option specified 
	{
		if (dbcsenv)	//DBCS mode
	    	printf("%s:%s:ヘキサダンプ 以外で %cYs オプションは使えません。\n",//~v907R~
					pgmid,ver,CMDFLAG_PREFIX);                     //~v907I~
		else			//SBCS
			printf("%s:%s:%cYs option is avail only under hex-dump mode.\n",//~v907R~
					pgmid,ver,CMDFLAG_PREFIX);                     //~v907I~
		uexit(4);                                               //~v742R~
	}
	if (recordsz||hexdump) //fixed record input or hexdump
		nocrlfsw=1;		//ignore crlf
    if (vfmt)                                                      //~v96eI~
		nocrlfsw=1;		//ignore crlf                              //~v96eI~

	if (!linespec && recordsz && hexdump) //hex record dump without maxline
		maxline=(maxline/3)*3;		//multiple of 3

//*input range and mode chk v7.21a start
	if (inputrangeopt==1)	//lineno
	{
		if (dumpmode==2 || (hexdump && !recordsz)) //skim dump or non-rec hexdump//~v836R~
		{
			if (dbcsenv)	//DBCS mode
	    		printf("%s:%s:スキムダンプ,非レコードモードヘキサダンプでの入力範囲はオフセット指定形式(%cIxa-b)を使って下さい。\n",//~v907R~
						pgmid,ver,CMDFLAG_PREFIX);                 //~v907I~
			else			//SBCS
				printf("%s:%s:Specify Hex-digit offset(%cIxa-b fmt) when Skim-dump or non-record-mode Hex-dump.\n",//~v907R~
						pgmid,ver,CMDFLAG_PREFIX);                 //~v907I~
			uexit(4);                                           //~v742R~
		}
	}
	if (inputrangeopt==2)	//offset
	{
		if (!dumpmode) //text mode
		{
			if (dbcsenv)	//DBCS mode
	    		printf("%s:%s:テキストモードでの入力範囲は行数指定形式(%cIn-m)を使って下さい。\n",//~v907R~
						pgmid,ver,CMDFLAG_PREFIX);                 //~v907I~
			else			//SBCS
				printf("%s:%s:Specify input range(%cIn-m fmt) by line-No when Text mode print.\n",//~v907R~
						pgmid,ver,CMDFLAG_PREFIX);                 //~v907I~
			uexit(4);                                           //~v742R~
		}
		inputrange1b=inputrange1;	//read start offset
//		inputrange2b=inputrange2;	//read limit v7.25d
		if (hexdump)
		{	
			inputrange1b=(inputrange1/dumpwidth)*dumpwidth;//lower booundary fo
//			inputrange2b=((inputrange2+dumpwidth-1)/dumpwidth)*dumpwidth;//higher booundaryv7.25d
		}
//		printf("input range-b:1=%ld(%08lx)\n",inputrange1b,inputrange1b);v7.25r
	}
//*input range and mode chk v7.21a end
//wkdir by getenv                                               //~v74dI~
    if (!UCBITCHK(swsw2,SW2WKDIR))//no wkdir parm               //~v74dI~
	    if (pc=getenv("XP"),pc)                                 //~v74dR~
        {                                                       //~v74dI~
      		strcpy(deswkfnpage,pc);	//page work                 //~v74dI~
      		strcpy(deswkfnpos,pc);	//page position work        //~v74dI~
      	}                                                       //~v74dI~
#ifdef W32                                                         //~v96aI~
        else                                                       //~v96aI~
        {                                                          //~v96aI~
    		pc=getenv("TMP");                                          //~v59dR~//~v96aI~
        	if (!pc)                                                   //~v59dI~//~v96aI~
        		pc=getenv("TEMP");                                     //~v59dR~//~v96aI~
            if (pc)	//else  .\ is used                             //~v96aI~
            {                                                      //~v96aI~
      			strcpy(deswkfnpage,pc);	//page work                //~v96aI~
      			strcpy(deswkfnpos,pc);	//page position work       //~v96aI~
            }                                                      //~v96aI~
        }                                                          //~v96aI~
#endif                                                             //~v96aI~

//dumpwidth and recordsz v6.7a end
//cpi write for 5577     
//esccmdsetup(maxcol,prntyp,cmdfile);	//esccmd setup v5.1r v5.5r v6.7d
    maxcol+=Gdatalinenosz;                                         //~v97GR~
  maxcoli=maxcol;						//parameter maxcol v5.1a
//maxcol+=LINENOSZ+1;                    //v2.1rep v5.1d
//strcpy(header0wp,"\f%");				//v4.7a  v5.1d
//sprintf(header0wp+2,"%ds\n",max(maxcol,79));	//v4.7a v5.1d
    if (UCBITCHK(swsw1,SW1BACKG))	//background                //~v74bI~
    	if (swconfirm)				//explicit confirm yes      //~v74bI~
        {                                                       //~v74bI~
    		if (UCBITCHK(swsw1,SW1CONFY))	//background        //~v74bI~
	  		{                                                   //~v74bI~
				if (dbcsenv)	//DBCS mode                     //~v74bI~
    				printf("%s:%s:バックグランドで確認入力は使えません(%cYc)\n",//~v907R~
							pgmid,ver,CMDFLAG_PREFIX);             //~v907I~
				else			//SBCS mode                     //~v74bI~
    				printf("%s:%s:%cYc is invalid when background mode.\n",//~v907R~
							pgmid,ver,CMDFLAG_PREFIX);             //~v907I~
    			uexit(4);                                       //~v74bI~
			}                                                   //~v74bI~
            swconfirm=0;                                        //~v74bI~
	  	}                                                       //~v74bI~

	if ((!stricmp(parmfname,"STDIN") || !stricmp(parmfname,","))//~v74fR~
    &&  !UCBITCHK(swsw1,SW1NOSTDIN))                            //~v742I~
    {                                                           //~v742I~
    	if (UCBITCHK(swsw1,SW1BACKG))	//background            //~v74bI~
  		{                                                       //~v74bI~
			if (dbcsenv)	//DBCS mode                         //~v74bI~
    			printf("%s:%s:バックグランドで標準入力は使えません\n",pgmid,ver);//~v74bI~
			else			//SBCS mode                         //~v74bI~
    			printf("%s:%s:stdin is not avail under background mode.\n",pgmid,ver);//~v74bI~
    		uexit(4);                                           //~v74bI~
	  	}                                                       //~v74bI~
    	parmfname=uindirect(0);		//file name from stdin      //~v742R~
        UCBITON(swsw1,SW1STDIN);		//for uexit free()      //~v742R~
	}                                                           //~v742I~
    else                                                        //~v742I~
		if (UCBITCHK(swsw1,SW1INDIRECT))                        //~v742I~
	    	parmfname=uindirect(parmfname);	//file name from parmfname//~v742I~
//if (ordersw==-1)					//no order option v5.7a        //~v90bR~
//  if (UCBITCHK(swsw1,SW1FILESEQ)) //file seq specified           //~v90bR~
//      ordersw=0;                                                 //~v90bR~
//  else                                                           //~v90bR~
//  	ordersw=(strpbrk(parmfname,"*?")!=0); //sort when wild card v5.7a//~v90bR~
//multifilesw=(strpbrk(parmfname,"*?/")!=NULL);//nonzero if "*" , "?" or "/" is used v5.7r//~v90aR~
  multifilesw=(strpbrk(parmfname,"*?" MULTI_SEPS)!=NULL);//nonzero if "*" , "?" or "/" is used v5.7r//~v90aI~

//  if (pagefilesw && !multifilesw)   //restart file name but not multi-file v6.2a//~v90bR~
//  {//v6.2a                                                       //~v90bR~
//    if (dbcsenv)    //DBCS mode v6.2a                            //~v90bR~
//        printf("%s:%s:/P パラメータのファイル名指定は複数ファイルプリントの時だけです\n",pgmid,ver);//v6.2a//~v90bR~
//    else            //SBCS mode v6.2a                            //~v90bR~
//        printf("%s:%s:use filename on /P only when multiple file print.\n",pgmid,ver);//v6.2a//~v90bR~
//    uexit(4);//v6.2a                                             //~v90bR~
//  }//v6.2a                                                       //~v90bR~
//  if (UCBITCHK(swsw3,SW3CONJUNCT))	//onjunct modde            //~v801R~
//      if (pagefilesw                                             //~v801R~
//  	&&  (pagerange[0]!=1 || pagerange[1]!=MAXPAGE)) //both specified//~v801R~
//      	uerrexit("%s:%s:both page range and start file can not be used when conjunct mode.",//~v801R~
//       			"%s:%s:連結印刷モードの時ページ範囲と開始ファイルの両方は指定できません",pgmid,ver);//~v801R~

    if (!UCBITCHK(swsw1,SW1FILESEQ)) //file seq specified       //~v743I~
		if (despagesw)		//page descending order print v7.0a //~v743I~
    	    UCBITON(swsw1,SW1FILESEQR);		//for uexit free()  //~v743I~
    	                                                        //~v743M~
	multifile=umultifnlist(parmfname,UCBITCHK(swsw1,SW1FILESEQR),&dirnamesw);//~v90bR~
    if (dirnamesw)		//for UNIX, dirname without wildcard       //~v90bI~
    	multifilesw=1;  //* is padded                              //~v90bI~
    if (ordersw==-1)                  //no order option v5.7a      //~v90bI~
    {                                                              //~v91rI~
//#ifdef UNX                                                       //~v922R~
//      if (posparmno>=2) //shell expand case                      //~v922R~
//        ordersw=1;                                               //~v922R~
//      else                                                       //~v922R~
//#endif                                                           //~v922R~
      	if (UCBITCHK(swsw1,SW1FILESEQ)) //file seq specified       //~v90bI~
          	ordersw=0;                                             //~v90bI~
      	else                                                       //~v90bI~
          	ordersw=(strpbrk(parmfname,"*?")!=0)||(dirnamesw!=0); //sort when wild card v5.7a//~v90bI~
    }                                                              //~v91rI~
    if (pagefilesw && !multifilesw)   //restart file name but not multi-file v6.2a//~v90bI~
    {//v6.2a                                                       //~v90bI~
      	if (dbcsenv)    //DBCS mode v6.2a                          //~v90bI~
        	printf("%s:%s:%cP パラメータのファイル名指定は複数ファイルプリントの時だけです\n",//~v907R~
						pgmid,ver,CMDFLAG_PREFIX);//v6.2a          //~v907I~
      	else            //SBCS mode v6.2a                          //~v90bI~
          	printf("%s:%s:use filename on %cP only when multiple file print.\n",//~v907R~
						pgmid,ver,CMDFLAG_PREFIX);//v6.2a          //~v907I~
      	uexit(4);//v6.2a                                           //~v90bI~
    }//v6.2a                                                       //~v90bI~
//  pc=parmfname;						//top addr v5.7a        //~v742R~
//  for (i=0;i<MAXINPUTF-1;i++)			//get multiple filename spec//~v742R~
//  {									//v5.7a                 //~v742R~
//	multifile[i]=pc;				//single file name ptr v5.7a//~v742R~
//	pc=strpbrk(pc,"/");	           //search delm v5.7a          //~v742R~
//	if (!pc)						//not found v5.7a           //~v742R~
//		break;						//v5.7a                     //~v742R~
//	*pc++=0;						//string terminator v5.7a   //~v742R~
//  }									//v5.7a                 //~v742R~
//  multifile[++i]=0;					//terminator v5.7a      //~v742R~

	if ((ordersw&=multifilesw)!=0)			//both on then go sort  v4.62 v5.7rv7.0r
    {                                                           //~v74cI~
		UCBITON(swsw2,SW2MERGE);		//file all merge        //~v74cI~
    	flist=listgen(multifile,parmfname);		//create file list  	v4.6a v5.7r//~v801R~
    }                                                           //~v74cI~
    else                                                           //~v801I~
		if (UCBITCHK(swsw3,SW3CONJUNCT))	//onjunct modde        //~v801R~
        {                                                          //~v801I~
//            if (dbcsenv)    //DBCS mode v6.2a                      //~v801I~//~v97eR~
//                    printf("\n%s:%s:連結印刷モードは無順序印刷(%cNo)あるいは単一ファイルでは無効.\n",//~v907R~//~v97eR~
//                            pgmid,ver,CMDFLAG_PREFIX);//v6.2a      //~v907I~//~v97eR~
//            else            //SBCS mode v4.9a                      //~v801I~//~v97eR~
//                    printf("\n%s:%s:conjunct mode is invalid when no order(%cNo) or for single file\n",//~v907R~//~v97eR~
//                            pgmid,ver,CMDFLAG_PREFIX);//v6.2a      //~v907I~//~v97eR~
//          uexit(4);//v6.2a                                         //~v801I~//~v97eR~
			if (!multifilesw)			//both on then go sort  v4.62 v5.7rv7.0r//~v97eI~
				uerrexit("\n%s:%s:conjunct mode is invalid for single file print.",//~v97eR~
		 				 "\n%s:%s:連結印刷モードは単一ファイル印刷では無効.",//~v97eI~
							pgmid,ver);                            //~v97eR~
            else                                                   //~v97eI~
				uerrexit("\n%s:%s:conjunct mode requires order(%cOx:x!=L) option.",//~v97eI~
		 				 "\n%s:%s:連結印刷モードは印刷順序指定(%cOx:x!=L)が必要",//~v97eI~
							pgmid,ver,CMDFLAG_PREFIX);             //~v97eI~
        }                                                          //~v801I~
	if (multiprintjob==-1)				//no parameter specified v7.1a
    {                                                              //~v91rI~
		if (outdevprn)					//PRN,LPTn				v7.1a
			multiprintjob=1;			//default multijob		v7.1a
		else							//						v7.1a
			multiprintjob=0;			//default multijob		v7.1a
    }                                                              //~v91rI~
//1st page eject option                                            //~v785I~
	if (UCBITCHK(swsw2,SW21STPAGEOPT))	//1st page eject option specified//~v785R~
    {                                                              //~v91rI~
		if (UCBITCHK(swsw2,SW21STPAGEEJECT))	//1st page eject option//~v785R~
			skip1stff=0;		//write first page formfeed cmd opt//~v785R~
		else                                                       //~v785I~
			skip1stff=1;		//skip first page formfeed cmd opt //~v785R~
    }   	                                                       //~v91rR~
#ifdef WCSUPP	//W32,LNX;   by wcinit                             //~v941I~
#else                                                              //~v941I~
	if (hexdump)		//hexdump mode                             //~v853I~
    	if (!asciireq)			//no explicit asciimode            //~v853I~
        	asciimode=3;		//'j' as default whe hexdump       //~v853I~
#endif                                                             //~v941I~
    if (keisenreq)                                                 //~v846M~
    {                                                              //~v846M~
    	;                                                          //~v90vI~
//        if (dumpmode&&!hexdump)                                  //~v846R~
//        {                                                        //~v846R~
//            if (dbcsenv)    //DBCS mode                          //~v846R~
//                printf("罫線オプションは/Mdのときは無効\n");  //errmsg and exit//~v846R~
//            else            //SBCS mode                          //~v846R~
//                printf("Graphic char conversion optin is not avail with /Md\n");//~v846R~
//            uexit(8);                                            //~v846R~
//        }                                                        //~v846R~
//      if (!Gptrtfnm)        //no trt tbl parm                    //~v90sR~
//        if (prntyp==PRINTER_IBM)                                 //~v90sR~
//        {                                                        //~v90sR~
//            if (dbcsenv)    //DBCS mode                          //~v90sR~
//                printf("(注)プリンタータイプ=IBMで罫線オプション指定\n");  //errmsg and exit//~v90sR~
//            else            //SBCS mode                          //~v90sR~
//                printf("(Warn)Graphic char conversion optin used with printer type=IBM\n");//~v90sR~
////            uexit(8);                                          //~v90sR~
//        }                                                        //~v90sR~
    }                                                              //~v846M~
    else            //no keisen req                                //~v846I~
        if (hexdump)                                               //~v846I~
            keisenconvsw=0;     //default no conv for hexdump      //~v846R~
        else                    //not hexdump                      //~v857I~
            switch(prntyp)      //default for each type            //~v857I~
            {                                                      //~v857I~
            case PRINTER_IBM:                                      //~v857I~
	            keisenconvsw=0;     //default no conv for hexdump  //~v857I~
                break;                                             //~v857I~
            case PRINTER_ESCP:                                     //~v857I~
//          	if (asciimode==1)		                           //~v891R~
            	if (asciimode==1 || asciimode==4)   //ascii or EBCDIC//~v895R~
	            	keisenconvsw=0;                                //~v863R~
                else                                               //~v857I~
	            	keisenconvsw=KEISEN_SLASH;//KATAKANA require large pich//~v863R~
                break;                                             //~v857I~
            case PRINTER_CANNON:                                   //~v857I~
//          	if (asciimode==1)                                  //~v891R~
            	if (asciimode==1 || asciimode==4)   //ascii or EBCDIC//~v895R~
	            	keisenconvsw=0;                                //~v863R~
                else                                               //~v857I~
		            keisenconvsw=KEISEN_SLASH; //ext-graphic       //~v863R~
                break;                                             //~v857I~
            case PRINTER_WIN:                                      //~v857I~
            	if (asciimode==1)                                  //~v857I~
	            	keisenconvsw=0;                                //~v863R~
                else                                               //~v857I~
		            keisenconvsw=0;                                //~v863R~
            }                                                      //~v857I~
    if (swyn8)                                                     //~v960I~
    {                                                              //~v960I~
//    	if (!utf8sw||!textmodevhexsw)                              //~v960I~//~v97yR~
//        if (vhexdump<2)   //not vhex of recordmode/recfm=V       //~v96sR~//~v97yR~
      	if (!utf8sw||!(textmodevhexsw||vhexdump>1))                //~v97yI~
        	uerrexit("%cY8, %cN8 is for utf8 textmode vertical dump mode(%cMtxu) only",//~v960R~
        	         "%cY8, %cN8 は UTF8ファイル縦３段ダンプ(%cMtxu)用です.",//~v960R~
            		CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX); //~v960R~
    }                                                              //~v960I~
//*****************************
//* main loop                 *
//*****************************
    outclosependsw=0; 			//not prev job output close pending//~v856I~
    strcpy(outopenopt,"w");	//at first replace mode v7.11a
	for (infileno=0;;infileno++)				//v5.7a         //~v742R~
	{															//v5.7a 
  		if (!multifile[infileno])			//end of list	v5.7a
			break;							//v5.7a	
		databuffc=databufft;//current data as top at first(useed at openinput)//~v803I~
//		openrc=openinput(multifile[infileno]); //open input v3.7r v5.7r//~v91kR~
        xpmult_chkindirectopt(0,multifile[infileno],&maxcoli);     //~v942R~
        	maxcoli=maxcol;	//lrecl specified                      //~v942I~
  		openrc=openinput(xpparsehdrfnm(multifile[infileno])); //open input v3.7r v5.7r//~v91kI~
        if (openrc)                                             //~v742I~
        	uexit(8);					//find first err        //~v742I~
                                                                   //~v970I~
#ifdef GTKPRINT                                                    //~v970I~
		lnx_startjob(docname);	//open main window                 //~v970I~
#endif //!GTKPRINT                                                 //~v970I~
  		while(!openrc)                   //all wild card file v3.7a
  		{                                 //v3.7a
   			maxcol=maxcoli+LINENOSZ+1;                    //v5.1a

//restart file control v6.2a
				if (pagefilesw==3)		//restart file specified
				{
					pagestart=1;				//next file from page top
					pageend=MAXPAGE;			//next file to last page//~v74fR~
				}
//restart file control v6.2a

    		if (input)                      //file selected v3.7a
    		{//v3.7a
//  			if (!output)				//closed v7.1a         //~v856R~
    			if (!output 				//not opened           //~v856I~
    			||   outclosependsw)		//prev job output close pending//~v856I~
                {                                                  //~v856I~
    				if (output)			//prev job output close pending//~v856I~
				      if (!Sstdoutsw)	//not output stdout        //~v90mI~
                    	fclose(output);	//delay close for last ff  //~v856I~
				  output=openoutput(prn,outopenopt);//open output v7.11r
				}                                                  //~v856I~
			    strcpy(outopenopt,"a");	//later append mode v7.11a
	  			phase2sw=0;					//count page v4.4a
      			actualmaxc=0;     			//max colomn v5.1a
				databuffc=databufft;//current data as top at first(useed at openinput)//~v803I~
      			realpage=0;       			//actual write page //~v74hI~
             	rmax=rcount=RBUFFSZ;		//at first read from file //v5.8a
             	pageoutlen=0;				//output length //v5.8a
				readcount=inputrange1b;		//v6.6a v7.21r

		  		if (fseek(input,inputrange1b,SEEK_SET))		//position to input start pos v7.21a
    				printf("\n%s:%s:positioning to input start(%08lx) is failed.\n",//~v868R~
									pgmid,ver,inputrange1b);//v7.21a//~v868I~
  				if (UCBITCHK(swsw4,SW4EBCCFG))                     //~v953I~
  					xpebc_open(0);  //ufgetsinit when EOL=0x15     //~v953I~
				if (!fastpathsw)			//2 phase run v7.26a
				{							//v7.26a
	      			printfile();                  //v3.7a 
                  if (!UCBITCHK(swsw3,SW3CONJUNCT))//not closed at printfile//~v803I~
                  {                                                //~v91rI~
					if (databuffsw)				//data saved v5.9a
	    	  			fclose(input);          //close input v5.9a
					else						//input is too large v5.9a
//		  				if (fseek(input,(long)0,SEEK_SET))	//reposition to top of file av4.4 v7.21d
		  				if (fseek(input,inputrange1b,SEEK_SET))	//reposition to start of file v7.21a
                        {                                          //~v91rI~
							if (dbcsenv)	//DBCS mode v4.9a
	    						printf("\n%s:%s:ＳＥＥＫの失敗.\n",pgmid,ver);//v4.9a
							else			//SBCS mode v4.9a	
	    						printf("\n%s:%s:re-positioning failed.\n",pgmid,ver);//v4.4a
                        }                                          //~v91rI~
  					if (UCBITCHK(swsw4,SW4EBCCFG))                 //~v953I~
  						xpebc_open(1);  //ufgetsinit when EOL=0x15 //~v953I~
                  }                                                //~v91rI~
//******* colomn max determin v5.1a
		  			if (!colomnspec) 	//not colomn specified
		  			{
                      if (recordsz || vfmt)   //recordmode or recfm=V//~v97nI~//~v97wR~
                      {                                            //~v97wI~
        				actualmaxc=min(actualmaxc,maxcoli);	//v5.6add//~v97wI~
                      }                                            //~v97wI~
                      else                                         //~v97wI~
                      {                                            //~v97wI~
                        actualmaxc-=Gdatalinenosz;                 //+v9d0I~
                        maxcoli-=Gdatalinenosz;                    //+v9d0I~
//        				actualmaxc=max(actualmaxc,COLMAX1);        //~v917R~
          				actualmaxc=max(actualmaxc,colmax1);        //~v917I~
        				actualmaxc=min(actualmaxc,maxcoli);	//v5.6add//~v74iR~
		      			actualmaxc=((actualmaxc+4)/5)*5;
                        actualmaxc+=Gdatalinenosz;                 //+v9d0I~
                        maxcoli+=Gdatalinenosz;                    //+v9d0I~
                      }                                            //~v97wI~
			  			maxcol=actualmaxc+LINENOSZ+1;
                        UTRACEP("colomnspec=0:maxcol=%d,actualmaxc=%d,maxcoli=%d,colmax1=%d\n",maxcol,actualmaxc,maxcoli,colmax1);//~v97nR~
	  				}
#if defined(W32) || defined(GXP)                                   //~v93vI~
                    else                                           //~v93vI~
                    if (UCBITCHK(swsw4,SW4CMAX))//-cmax parameter ; get maxcol by longest line//~v93vR~
                    {                                              //~v93vI~
			  			maxcol=actualmaxc+LINENOSZ+1;              //~v93vI~
                    }                                              //~v93vI~
#endif                                                             //~v93vI~
					if (vhexdump>1)                                //~v97wI~
						dumpwidth=maxcol-LINENOSZ-1;               //~v97wR~
//*********************** v5.1a
					databuffl=databuffc;		//current as last addr v5.8a
					databuffc=databufft;		//current as top at start v5.8a
		  			phase2sw=1;					//for openinput    //~v803I~
					sub1freadVinitphase();	//reset Geoloffsv      //~v96sI~
                    if (UCBITCHK(swsw3,SW3CONJUNCT))				//also listgen mode//~v801R~
//  			  		openinput(multifile[infileno]); //get 1st selected//~v91kR~
    			  		openinput(xpparsehdrfnm(multifile[infileno])); //get 1st selected//~v91kI~
				}							//2 phase run v7.26a
				poswkbuffc=poswkbufft;		//top addr v5.8a
				pagebuffc=pagebufft;		//top addr v5.8a
				poswkfsw=(!poswkbufft || ((realpage+1)>POSWKMAXPAGE));//v5.8a file use sw
                //if /Yfp(first path nad despage) poswkbufft=0  //~v74hI~
				pagefsw=(!pagebufft || (pageoutlen>PAGEWKSZ));//v5.8a file use sw
             	rmax=rcount=RBUFFSZ;		//at first read from file //v5.8a
				readcount=inputrange1b;				//v6.6a v7.21r
	  			phase2sw=1;					//print page v4.4a
#ifdef GTKPRINT                                                    //~v970I~
				lnx_startdoc2(realpage);	//page count for begin print callback//~v970I~
#endif //!GTKPRINT                                                 //~v970I~
      			realpage=0;       			//actual write page //~v74hI~
      			printfile();                  //v4.4a
				skip1stff=0;		//for second file              //~v785I~

              if (!UCBITCHK(swsw3,SW3CONJUNCT))//not closed at printfile//~v803I~
				if (!databuffsw)				//not phase1 closed v5.9a
	      			fclose(input);                //close inputv3.7a
				if (pagefilesw==2)		//restart file specified v6.2a
					pagefilesw=3;		//next file from page top v6.2a
//#ifndef DOS					//os/2      v7.1a v7.22d
				if (multiprintjob)    //output multijob sw v7.1a
				{						//v7.1a
//  				  fclose(output);       //close output v7.1a   //~v856R~
//  				  output=NULL;			//v7.1a                //~v856R~
    				  outclosependsw=1;		//prev job output close pending//~v856I~
#ifdef OS2                                                         //~v865I~
					if (docnamesw)                                 //~v865I~
                    	os2_closedoc();                            //~v865R~
#endif                                                             //~v865I~
#ifdef W32                                                         //~v867I~
				    if (prntyp==PRINTER_WIN)    //printer type(default Win for win version)//~v867I~
			            win_closedoc(); //only when PRINTER_WIN    //~v867I~
#endif                                                             //~v867I~
#ifdef GXP                                                         //~v92dI~
				    if (prntyp==PRINTER_WIN)    //printer type(default Win for win version)//~v92dI~
			            lnx_closedoc(); //only when PRINTER_WIN    //~v92dI~
#endif                                                             //~v92dI~
				}						//v7.1a
//#endif									//v7.1a v7.22d
	            if (UCBITCHK(swsw3,SW3CONJUNCT))				//also listgen mode//~v801I~
    	        	break;			//break while !openrc          //~v801I~
			    closedoc2p();                                      //~v90kI~
				if (swsetarchive)		//set archive attribute off v7.2a
					archoff();			//v7.2a
    		}//file selected v3.7a
    		openrc=openinput(NULL);         //v3.7a
  		}//while !openrc                                           //~v801R~
		if (UCBITCHK(swsw2,SW2MERGE))		//file all merge    //~v74cI~
        	break;                                              //~v74cI~
	}//all input file spec(multi input file)	v5.7a

  if (pagefilesw==1)	//restart filename not exist	v6.2a	
  {	
	if (dbcsenv)	//DBCS mode v6.2a
   		printf("\n%s:%s:%cP パラメータの ファイル名の誤りです.\n", //~v907R~
					pgmid,ver,CMDFLAG_PREFIX);//v6.2a              //~v907I~
	else			//SBCS mode v4.9a	
   		printf("\n%s:%s:error of filename on %cP parameter.\n",    //~v907R~
					pgmid,ver,CMDFLAG_PREFIX);//v6.2a              //~v907I~
    uexit(4);//v6.2a                                            //~v742R~
  }	

  if (despagesw)		//page descending order print v5.3a
//    despageout(0); 	//zero work file size v5.3a                //~v859R~
      despageout(0,output); 	//zero work file size v5.3a        //~v859I~
  despagesw=0;			//need use work no more v5.3a
//if (output)				//opened v7.1a v7.27d
#ifdef OS2                                                         //~v865I~
 if (docnamesw)		//set docname to printer output                //~v865I~
	os2_endjob(0);//normal end                                     //~v865I~
 else	//not docnamesw                                            //~v865I~
 {                                                                 //~v865I~
#endif                                                             //~v865I~
  if (!os2sw)				//dos native v7.27a
  {							//v7.1a
//#ifdef W32                                                       //~v92dR~
#if defined(W32) || defined(GXP)                                   //~v92dR~
    if (prntyp==PRINTER_WIN)	//printer type(default Win for win version)//~v844R~
	#ifdef GXP                                                     //~v92dI~
		lnx_endjob(0);//normal end                                 //~v92dI~
	#else                                                          //~v92dI~
		win_endjob(0);//normal end                                 //~v844R~
	#endif                                                         //~v92dI~
    else                                                           //~v844I~
    {                                                              //~v844I~
#endif                                                             //~v844M~
	  if (!output)				//closed v7.27a
		  output=openoutput(prn,outopenopt);//open output v7.11r
//      pline("\f",1,1,output);       //last page eject v5.3a      //~v864R~
//    if(output)                                                   //~v864R~
//      fclose(output);                //close output              //~v864R~
	dos_endjob();                                                  //~v864I~
//#ifdef W32                                                       //~v92dR~
#if defined(W32) || defined(GXP)                                   //~v92dR~
    }                                                              //~v844I~
#endif                                                             //~v844I~
  }							//v7.1a
#ifdef OS2                                                         //~v865I~
 }//not docnamesw							//v7.1a                //~v865I~
#endif                                                             //~v865I~
//  if (multifilesw)	//v4.1a v5.7r                           //~v741R~
		if (dbcsenv)	//DBCS mode v4.9a
//    		printf("\n%s:%s:(%c)全処理完了;出力合計 %d 頁, 入力合計 %ld 行 ( %d ファイル).\n",//~v90mR~
      		fprintf(Gmsgfile,"\n%s:%s:(%c)全処理完了;出力合計 %d 頁, 入力合計 %ld 行 ( %d ファイル).\n",//~v90mR~
	  			pgmid,ver,os,totpage,totline,totfile);//v4.9a      //~v836R~
		else			//SBCS mode v4.9a	
//    		printf("\n%s:%s:(%c)process completed;total %d page output from %ld lines of %d file.\n",//~v90mR~
      		fprintf(Gmsgfile,"\n%s:%s:(%c)process completed;total %d page output from %ld lines of %d file.\n",//~v90mR~
	  			pgmid,ver,os,totpage,totline,totfile);//v4.1a v4.6r//~v836R~
	if (!UCBITCHK(swsw1,SW1BACKG))                              //~v74bI~
	    titlemsg(dbcsenv,pgmid,ver);                            //~v74bR~
#ifdef GXP                                                         //~v92mI~
    if (Gl2uconverr)                                               //~v92mI~
        printf("\nWarning: %d conversion error(locale to utf8) detected\n",Gl2uconverr);//~v92mR~
#endif                                                             //~v92mI~
  return 0;                      //v1.3add

}   //end maine

//********************************************************
//*output file open and call docname set for os2  v7.11a  *
//*  parm1:file name                                     *
//*  parm2:open option                                   *
//*  ret  :file handle                                   *
//********************************************************
FILE *openoutput(char *outfile,char *opt)
{
	FILE *outputh;
//int setdocname(UCHAR *);                                         //~v865R~
//#ifndef DOS                                                      //~v865R~
//#ifndef W32                                                      //~v865R~
//    UCHAR *port;                                                 //~v865R~
//#endif                                                           //~v865R~
//#endif                                                           //~v865R~
//************************
#ifdef W32                                                         //~v859I~
  	if (prntyp==PRINTER_WIN)                                       //~v859R~
  		return 0;                                                  //~v859I~
#endif                                                             //~v859I~
#ifdef GXP                                                         //~v92dI~
  	if (prntyp==PRINTER_WIN)                                       //~v92dI~
  		return 0;                                                  //~v92dI~
#endif                                                             //~v92dI~
#ifdef OS2                                                         //~v865I~
 	if (docnamesw)		//set docname to printer output            //~v865I~
    {                                                              //~v865I~
		os2_opendoc();                                             //~v865R~
        return 0;                                                  //~v865I~
	}                                                              //~v865I~
#endif                                                             //~v865I~
  if (Sstdoutsw)                                                   //~v90mR~
    outputh=stdout;                                                //~v90mR~
  else                                                             //~v90mR~
	if (!(outputh=fopen(outfile,opt)))
	{
		if (dbcsenv)	//DBCS mode v4.9a
    		printf("\n%s:%s:出力ファイル(%s) オープンエラー\n",pgmid,ver,prn);//v4.9a//~v74dR~
		else			//SBCS mode v4.9a	
    		printf("\n%s:%s:output file(%s) open err\n",pgmid,ver,prn);//v2.6rep//~v74dR~
    	uexit(4);                                               //~v742R~
  	}
//#ifndef DOS                                                      //~v865R~
//  #ifndef W32                                                    //~v865R~
//    if (docnamesw && outdevprn) //output is printer              //~v865R~
//    {                                                            //~v865R~
//        if (!stricmp(outfile,"PRN"))                             //~v865R~
//            port="LPT1";                                         //~v865R~
//        else                                                     //~v865R~
//            port=outfile;                                        //~v865R~
//        if (!setdocname(port))                                   //~v865R~
//            docnamesw=0;                                         //~v865R~
//    }                                                            //~v865R~
//  #endif                                                         //~v865R~
//#endif                                                           //~v865R~
	return outputh;
}
//**********************************************************************//~v742I~
//*creen up at exit                                             //~v742I~
//**********************************************************************//~v742I~
void uexit(int rc)                                              //~v742R~
{                                                               //~v742I~
	static int uexitsw=0;                                          //~v91kR~
//********                                                      //~v742I~
//printf("uexit uexitsw=%d,prntype=%d,onceputsw=%d,output=%p,despagesw=%d\n",//~v846R~
//        uexitsw,prntyp,onceputsw,output,despagesw);              //~v846R~
    if (!uexitsw)                                                  //~v865M~
    {                                                              //~v865M~
		uexitsw=1;                                                 //~v865M~
#ifdef W32                                                         //~v844I~
    if (prntyp==PRINTER_WIN)                                       //~v846I~
		win_endjob(8);                                             //~v846R~
#endif                                                             //~v846M~
#ifdef GXP                                                         //~v92dI~
    if (prntyp==PRINTER_WIN)                                       //~v92dI~
		lnx_endjob(8);                                             //~v92dI~
#endif                                                             //~v92dI~
#ifdef OS2                                                         //~v865I~
 	  if (docnamesw)		//set docname to printer output        //~v865I~
		os2_endjob(8);                                             //~v865I~
      else                                                         //~v865I~
      {                                                            //~v865I~
#endif                                                             //~v865I~
	    if (prntyp!=PRINTER_WIN)                                   //~v846I~
            if (onceputsw)                                         //~v846R~
//                if (output)     //opened                         //~v864R~
//                {                                                //~v864R~
////printf("uexit uexitsw=%d,prntype=%d,onceputsw=%d,output=%08p,despagesw=%d\n",//~v864R~
////        uexitsw,prntyp,onceputsw,output,despagesw);            //~v864R~
//                    fwrite("\f",1,1,output);       //last page eject v5.3a//~v864R~
//                    fclose(output);                //close output//~v864R~
//                }                                                //~v864R~
				dos_endjob();                                      //~v864I~
#ifdef OS2                                                         //~v865I~
      }//not docnamesw on                                          //~v865I~
#endif                                                             //~v865I~
    }                                                              //~v846I~
//  if (UCBITCHK(swsw1,SW1STDIN|SW1INDIRECT))                      //~v90eR~
    if (UCBITCHK(swsw3,SW3FNMMALLOC))                              //~v90eI~
        free(parmfname);            //file name from stdin      //~v742I~
                                                                   //~v90fI~
#ifdef UNX                                                         //~v90fI~
    if (Sunixexpandfnm)                                            //~v90fI~
    {                                                              //~v90fI~
        free(Sunixexpandfnm);            //file name from stdin    //~v90fI~
	    Sunixexpandfnm=0;                                          //~v90fI~
    }                                                              //~v90fI~
#endif                                                             //~v90fI~
    if (multifile)                                              //~v742I~
	    free(multifile);                                        //~v742I~
    exit(rc);                                                   //~v742I~
    return;                                                     //~v742I~
}//uexit                                                        //~v742I~
//**********************************************************************//~v864I~
//*creen up at exit                                                //~v864I~
//**********************************************************************//~v864I~
void dos_endjob(void)                                              //~v864I~
{                                                                  //~v864I~
    if (output)     //opened                                       //~v864I~
    {                                                              //~v864I~
    	if (prntyp==PRINTER_CANNON                                 //~v864I~
        &&  endjobreq)                                             //~v864I~
        {                                                          //~v91xI~
          if (UCBITCHK(swsw4,SW4NOFFCMD)) //skip ff insert         //~v91xI~
	        fwrite("\x1bP0J\x1b\\",1,6,output); //last page eject and job end//~v91xI~
          else                                                     //~v91xI~
	        fwrite("\f\x1bP0J\x1b\\",1,7,output); //last page eject and job end//~v864R~
        }                                                          //~v91xI~
#ifndef UNX                                                        //~v90iI~
        else                                                       //~v864I~
        {                                                          //~v91xI~
          if (!UCBITCHK(swsw4,SW4NOFFCMD)) //skip ff insert        //~v91xI~
	        fwrite("\f",1,1,output);       //last page eject v5.3a //~v864I~
        }                                                          //~v91xI~
#endif                                                             //~v90iI~
		closedoc2p();                                              //~v90kI~
      if (!Sstdoutsw)	//not output stdout                        //~v90mI~
        fclose(output);                //close output              //~v864I~
    }                                                              //~v864I~
}//dos_endjob                                                      //~v864I~
//************************************************************     //~v972I~
//parm prechk                                                      //~v972I~
//************************************************************     //~v972I~
void                                                               //~v972I~
parmprechk(int parmc,char **parmp)                                 //~v972I~
{                                                                  //~v972I~
	char *cptr;                                                    //~v972I~
    int utraceon=0,parmno,c;                                       //~v972R~
//***********************                                          //~v972I~
    for (parmno=1;parmno<parmc;parmno++)  //v2.6add                //~v972I~
    {                                     //v2.6add                //~v972I~
      	cptr=parmp[parmno];                 //v2.6add              //~v972I~
    #ifdef UNX                                                     //~v972I~
      	if(*cptr=='-')                                             //~v972I~
    #else                                                          //~v972I~
      	if(*cptr=='/'||*cptr=='-')          //v2.6add              //~v972I~
    #endif                                                         //~v972I~
      	{//option                            //v2.6add             //~v972I~
        	c=*(++cptr);                      //first option byte v3.1add//~v972I~
            cptr++;                                                //~v970I~
        	switch(toupper(c))       //option     //v3.1add rv4.5  //~v972I~
        	{                                                     //v2.0add//~v972I~
#ifdef GTKPRINT                                                    //~v973I~//~v970M~
    		case 'Q':                                              //~v970I~
	        	if (!strcmp(cptr,STDOUTID)                         //~v970I~
        		||  !strcmp(cptr,STDOUTID2))                       //~v970R~
                	;	//lnx_init will not called                 //~v970I~
                else                                               //~v970I~
            	if (stricmp(cptr,"PRN")              //v7.1a       //~v970R~
            	&&  stricmp(cptr,"LPT1")         //v7.1a           //~v970R~
            	&&  stricmp(cptr,"LPT2")         //v7.1a           //~v970R~
            	&&  stricmp(cptr,"LPT3"))            //v7.1a       //~v970R~
	          		Gqparm=strdup(cptr); //set for escformchk                                     //~v973I~//~v970I~
                else                                               //~v970I~
					Gxpotheropt|=GOO_DESTPRN;                      //~v970I~
                break;                                             //~v970I~
#endif                                                             //~v973I~//~v970M~
	        case 'Y':             //v3.8a                          //~v972I~
          		do                                                 //~v972I~
          		{                     //v7.1a                      //~v972I~
              		switch (toupper(*cptr)) //rv4.5                //~v972I~
              		{                                              //~v972I~
              		case 'T':           //trace option             //~v972I~
                		utraceon=1;                                //~v972I~
                		break;                                     //~v972I~
	              	}//switch by set option                        //~v972I~
	              	cptr++;           //v7.1a                      //~v972I~
    	    	}//until strlen v7.1a                              //~v972I~
         	 	while (*cptr);                                     //~v972I~
          		break;                                             //~v972I~
        	case 'N':                                              //~v972I~
          		do                                                 //~v972I~
          		{                     //v7.1a                      //~v972I~
            		switch (toupper(*cptr))                        //~v972I~
              		{                                              //~v972I~
              		case 'T':           //trace option             //~v972I~
                		utraceon=0;                                //~v972I~
                		break;                                     //~v972I~
              		}//switch by /Nx                               //~v972I~
              		cptr++;           //v7.1a                      //~v972I~
          		}//until strlen v7.1a                              //~v972I~
          		while (*cptr);                                     //~v972I~
          		break;                                             //~v972I~
        	}//switch  by first option byte                          //v2.0add//~v972I~
      	}//optional                                                //~v972I~
	}//for all parm                                  //v2.6add     //~v972I~
    if (!utraceon)                                                 //~v972I~
	    UTRACE_INIT(0/*tracefilename*/,0/*notrace*/);              //~v972I~
}//parmprechk                                                      //~v972I~
