//*CID://+vb7kR~:                             update#=  601;       //+vb7kR~
//*************************************************************
//*xefile2.c  *                                                 //~v04dR~
//* draw                                                           //~v549R~
//*************************************************************
//vb7k:170115 dir list;gree attr overflow to "=Rep" when dirname is too long//+vb7kI~
//vb52:160827 (Bug)hdr of opt0.2 is opt0.2.2                       //~vb52I~
//vb4f:160802 (ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~vb4fI~
//vb3i:160608 (LNX:BUG)by vb3d,timestamp fld of hdr was set to green//~vb3iI~
//vb3d:160607 set hdr attr not to the char but to pathname to draw at uviom by Ligature same as dir member//~vb3dI~
//vb3c:160607 (BUG)when scr changed to inactive of split,hdr attr of green was disappeared//~vb3cI~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2m:160130 (BUG)UTF8 attr on edit/browse 1st line(filename) was not shown when filename is too long(prefixed by "...")//~vb2mI~
//vb2k:160130 membername on dirlist is FNLC but edit panelfile name is FNU8.//~vb2kI~
//            dirsetlocalename call dirsetddfmtname(DSDFO_L2DD) if not all utf8,//~vb2kI~
//            fileutf8setfilenamecodetype call xeutf_getlocalepathname and GUM_MIXWORDMODE allow UTF8/LC mixed in a pathname.//~vb2kI~
//            Now xeutf_getlocalepathname pre-chk all utf8 and accept the path is utf8.//~vb2kI~
//vb2h:160129 display filename encoding type on hdr/trailer linet at ufcleft//~vb2hI~
//vb2e:160122 (LNX)convert filename according IOCHARSET mount option//~vb2eI~
//vavG:140401 (W32UNICODE) MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;hdrname truncated by l2u err//~vavGI~
//vavt:140428 strip uid from UFHfilenamedddata                     //~vavtI~
//vavr:140426 (Bug of vavc)mem corrupted windows debug msg.(UFHhdrname attr jave only width of hdrname)//~vavrI~
//vavp:140426 (vaub/vau7 for Win)maintain ddfmt for pan fnmlist and util panel//~vavpI~
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavcI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vav9:140410 (Win)unicode support(UD fmt string,_MAX_PATH changes)//~vav9I~
//vauL:140318 (BUG)filename hdr utf8 green err                     //~vauLI~
//vauJ:140317 (BUG)UFHfilename:membername ct of fpath should not apply to pathname//~vauJI~
//vauA:140315 (BUG)u8 membername on dir list by fnu8 option,but fhfilename is treated by lc by env:lc on windows//~vauAI~
//            support select lcmd but not for Select cmd(may specify path, so use FNU8 cmd option for select cmd)//~vauAI~
//vauq:140314 (BUG)timestamp of hdr line of file/dir panel was lost//~vauqI~
//vaub:140306 maintain ddfmt for pan fnmlist and util panel        //~vaubI~
//vaua:140306 getmixwdword output dddata and dddbcs                //~vauaI~
//vau7:140303 keep ddfmt on pfh(yet remains dbcs and lcname)       //~vau7I~
//vau4:140228 (BUG)like as vau0,invalid colomn width for u8filename on hdrline if f2l is done(invalid translation for german by japanese)//~vau4I~
//vaq1:131226 LNX compiler warning:unused                          //~vaq1I~
//vamB:131106 (BUG of va5s:display hdr line filename by dd fmt) not cleared shrinked//~vamBI~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va5s:100514 display hdr line filename by dd fmt                  //~va5sI~
//va1C:091112 (UTF8)reffer pfh for filename codetype on errmsg     //~va1CI~
//va1B:091112 (UTF8)hdrline codetype from cmd buff if avail       //~va1BI~//~va5sR~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va13:091022_(BUG)hdrline filename dbcs split consideration for long name cut from top by screen width//~va13I~
//va0x:090920!kbd mode change(A+u)                                 //~va0xI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          header line filename cv f2l                            //~va00I~
//          set encoding id on header line                         //~va00I~
//v8@Z:080715 3270:TSO keyboard mode by A+q                        //~v8@ZI~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v77k:080105*(BUG)dbcs tbl of hdr line was shared                 //~v77kI~
//v76Z:071113*(BUG)dbcs filename hdrline display "." at vsplit boundary//~v76ZI~
//v76Q:071001 compchchk !UTF8SUPP compile                          //~v76QI~
//v75E:070508 displya ","/">" on Cols line for bnds                //~v75EI~
//v730:061225 use UPLbuff for cmdline(to display as long as possible if del key used, and accept insert over screen width)//~v730I~
//v72d:061123 (BUG)reversed csr pos on guage line is not reset by csr move for 2nd split screen//~v72dI~
//v69D:060708 split xefile2 to xefile23(func_draw_file,setlineattr)//~v69DI~
//v64i:050619 (LNX)xxe support;scr width                           //~v64iI~
//v64d:050619 (UNX)cut hostname by "." on hdr filename             //~v64dI~
//v64b:050619 (LNX)to shorten hostname,chk local                   //~v64bI~
//v62c:050312 multireverse option by single foundctr(continuous chk is no problem)//~v62cI~
//v62a:050311 -m[n] option of find cmd to keep previous reverse;n:multi rev from next//~v62aI~
//v621:050308 (WXE:BUG)scr-resize dose not reset dirlist expanded for not current displayed page//~v621I~
//v61s:050306 for multiple found reverse support;change structure of mfwtbl(offs,len,next entry offset ushort count)//~v61sI~
//v60v:050201 virtual hex display option(/Mx,HEX on/off,prev HEX is XIN)//~v60vI~
//v60m:050129 display different id from eolid for contline terminater.//~v60mI~
//v60b:050109 for dirlist column is not required to print,expand filename field of hdr line//~v60bI~
//v59v:041114 (BUG)hex disp mode:display char part column when csr is on hex part//~v59vR~
//v58L:041117 (BUG)whe dbcsspace char>x20 other dbcs with that char is displayed by lineno fld attribute//~v59vR~
//v57G:040612 except DOSDOS;expand max lrecl 999-->9999(also gauge)//~v57GI~
//v56r:040410 (BUG)column field "(",")" is cleared by wakeup       //~v56rI~
//v56q:040407 (BUG)scroll size fieled is restored to default by resize//~v56qI~
//v56i:040404 (WXE:BUG)scroll fld on 2nd line is not displayed when vsplit//~v56iI~
//v558:040204 new func:path up/down by A+left/right                //~v558I~
//v549:040102 (WXE:BUG)finename is not shotened on hdr line        //~v549I~
//v53g:030923 (BUG)for xprint **;lineno shift like as screen       //~v53gI~
//v53e:030923 (BUG)for xprint **;lineno may changed lineno to hex offset//~v53eR~
//            after once displayed(plhlineno is set previous fmt)  //~v53eR~
//v53d:030923 option seti/setr without renum                       //~v51VI~
//v51V:030808 v51A if for UNX;for WXE abend when scr size is shorten.//~v51VI~
//            (us Gscrbuffwidth for other than WXE)                //~v51VI~
//v50o:030103 (BUG)abend when resized(too short width)             //~v50oI~
//v507:021027 csr line invalid when x cmd with & option(not excluded yet at 1st word)//~v507I~
//v500:020827 wxe support                                          //~v496I~
//            resize support                                       //~v496I~
//v496:020617 find *L (search lineserch result;for after == lcmd)  //~v496I~
//v493:020616 (BUG)hex dbcs 2 byte display on hdr line after split dbcs by split cmd//~v493I~
//v47d:020223 opt eol char on/off;end of line char and attr specification cmd//~v47dI~
//            change defaut attr on except for aix                 //~v47dI~
//v47b:020223 display tail on hdr line for long filename           //~v47bI~
//v45z:011222 same logic CURUPDATE and CURUPDATE for clear reverse(see v45v)//~v45zI~
//v45y:011222 skip csrline dbcs clear should be for not full drawcase//~v45yI~
//v45v:011216 (BUG)unpdate line reverse remain after undo the replace//~v45vI~
//            because there is no triger to redraw,3CURUPDATE flag is already reset//~v45vI~
//            3CURUPDATE set when lhupctr=fhupctr and reset when lhupctr!=fhupctr//~v45vI~
//            with setting fdraw flag                              //~v45vI~
//v45k:001015 UNX for hex mode,dbcs clear only when update,simple write when cursor move//~v45kI~
//v45d:011209 (BUG)dbcs split on filename of hdrline when vsplit   //~v45dI~
//v457:011208 (BUG)unprintable char is not drawn by tab char attr when hex display mode//~v457I~
//v451:011208 v450,but for find/cap reverse attr,no set on half of dbcs//~v451I~
//v450:011208 DBCS consideration for hex mode cursor id on data pos//~v450I~
//            Especialy LNX required same attr for 2 byte of a DBCS.//~v450I~
//v44m:011204 option of upper/lower hex code display               //~v44mI~
//v44k:011204 (BUG)hex corsor line is invalid for the case setcsr is called//~v44kI~
//v44c:011202 re-draw cursol line for csr attr                     //~v44cI~
//v445:011201 binary file support for xprint **/***                //~v445I~
//v443:011201 colr on data csr corresponding on csr on hex part    //~v443I~
//v440:011125 browse hex                                           //~v440I~
//v43g:011030 save each find word len for multiple word search case//~v43gI~
//            (spanded or *& case)                                 //~v43gI~
//v42z:011010 cobol linenosz=5 for small file                      //~v42zI~
//v41v:010908 UNX:hostname display                                 //~v41vI~
//v41p:010820 cobol lineno suffix size=2(max 99)                   //~v41pI~
//v410:010728 disply column by hex when lineno is hex offs         //~v410I~
//v40Y:010728 lineno column width should be caliculated from line no not by line count//~v40YI~
//v40w:010618 display unprintable for dbcs split by line width parm//~v40wI~
//v40h:010526 xprint **;like as print screen                       //~v40hI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v30b:001213 AIX support:no highlight of eolid for aix            //~v30bI~
//v30a:001213 AIX support:(BUG of 302)                             //~v30aI~
//v309:001209 AIX support:eol highlight for AIX only               //~v309I~
//v302:001124 AIX support:Because mono-color,highlite unprintable and eol char.//~v302I~
//v301:001124 AIX support:end of line id by "_"                    //~v301I~
//v21q:000924 revers gauge csrpos                                  //~v21qI~
//v217:001126 LINUX support:printable EOL id for kon               //~v217I~
//v20W:001124 highline for unprintable char when mono-color mode   //~v20WI~
//v20U:001119 display tab and dbcs space when binary mode          //~v20UI~
//v19k:000910 LINUX support(diplay other than 0x1b for EOLID)      //~v19kI~
//v178:000430 renum support for lineno hex mode                    //~v178I~
//v160:000409 (win:BUG)same as ulib-v305 attr tbl lengthe is scrwidth.//~v160I~
//            But on file2,it shoud be limit to screen width.(safety chk).//~v160I~
//            (trigger is vsplit at pos  before linenosz with line reversed.//~v160I~
//            width-linenosz became to minus and memcpy abend).    //~v160I~
//v145:000213:(BUG)Y2K filedate on title line                      //~v145I~
//v11N:990829 COL cmd support                                      //~v11NI~
//v10X:990605 hex digit lineno display for binary file             //~v10XI~
//v10J:990418 (BUG)fulldraw required when lineno pos change by large line isrt//~v10JI~
//v101:981205 hex input                                            //~v101I~
//v0k0:980919 (BUG)miss line re-display for f/y lcmd when excluded is top line//~v0k0I~
//v0js:980723 (BUG)no prot chk for browse screen if linenosz<7     //~v0jsI~
//v0iz:980720 tab for change key assign screen                     //~v0izI~
//v0im:980625 pfk cmd support(optk1 and optk2)                     //~v0imI~
//v0ii:980621 display protected margin by browse attr              //~v0iiI~
//v0ig:980620 (BUG)abend when start line specified                 //~v0igI~
//v0if:980620 pfk cmd support(top line panel id)                   //~v0ifR~
//v0hr:980329 (BUG)when vsplit and its column is shorter than 5.   //~v0hrI~
//            destroy next malloc hdr,cause area is not malloced abend.//~v0hrI~
//v0hf:980130 performance tuning                                   //~v0hfI~
//            draw only after deleted/inserted line                //~v0hfI~
//v0eC:970926 (BUG)csr pos display on hdr line not change after find cmd//~v0eCI~
//            cur pos display after csronthefld                    //~v0eCI~
//v0bu:970728 draw mergin                                          //~v0buI~
//v0az:970720 errline reverse display                              //~v0azI~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//           -expand pre chk(split file2 to file6)                 //~v0avI~
//v0ag:970712 line id;split top,splie cont,top updt,cont updt      //~v0agR~
//v0a1:970705:NULL data accept as 0x00.and change str___ to mem___ //~v0a1I~
//            for ex. find cmd,cid search.                         //~v0a1I~
//v09Y:970629:file NULL(0x00) support                              //~v09YI~
//            set dbcstbl(new function for file area only)   sub   //~v09YI~
//v09X:970629:.ini tab display char parm                           //~v09XI~
//v09U:970628:display unprintable char by 0x0e(J) or 0x16(E)       //~v09UI~
//v09T:970625:(BUG)invalid current csr pos(minus of left most)     //~v09TI~
//             on hdr line when fulldraw                           //~v09TI~
//v09S:970625:display hex notation for edit/browse                 //~v09SI~
//v09R:970625:display tab by lineno color                          //~v09RI~
//v09f:970517:(BUG)when 6 digit line number(>99999),"|" replaced by "0"(suffix)//~v09fI~
//            So,shorten sufix digit 1,0 if >99999,>999999".       //~v09fI~
//v09e:970517:update  line search by *u (identify by offset==-1)   //~v09eI~
//v094:970401:(BUG)max line no ajust when line range specified     //~v094I~
//            (disappear delm between lineno and text column)      //~v094I~
//v08f:961106:performance up                                       //~v08fR~
//			  only once redraw for previous update/previous undo   //~v08fR~
//v08e:961104:(W95)performance up                                  //~v08eI~
//				  cell setup by char string and WORD attr table    //~v08eI~
//v08d:961104:(W95)performance up                                  //~v08dI~
//v08b:961103:(BUG)when first split popupped,UCWpsd point 1st half of USD//~v08bI~
//                 but USDpfld etc is of 2nd half which disppeared.//~v08bI~
//                 for win95 it may be page freed cause c0000005.  //~v08bI~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07j:960713:echo line of cmd result,bg color if length=0(at init open case)//~v07jI~
//v07d:960624:long cmd input at cmd result screen last line        //~v07dI~
//v06S:960427:(BUG of v069)only one UFLD for browse(destroy area)  //~v06SI~
//v06Q:960427:(BUG)not hilighten if reverse range is cut by UFCleft//~v06QI~
//            file2.c                                              //~v06QI~
//v06y:960407:protect edit SO file when it is used by cmd result   //~v06QR~
//            (cmd edit identification only by PANMOCMD)              //~v06yI~
//v06w:960406:(BUG)use panel client color for the line after the bottom//~v06wI~
//v06v:960406:assign pallette no to dir,cmd                           //~v06vI~
//v06u:960406:cmd so screen:lineno color for input cmd echo line      //~v06uI~
//v06q:960324:(BUG)of v069,it must be change all pfld           //~v06qI~
//v06o:960320:(BUG)alias name display for also NEW file         //~v06oI~
//v06n:960320:menu option 6(cmd) support                        //~v06nI~
//v06b:960224:(BUG)tab pad char is not displayed when left most is tab pad char//~v06bI~
//v069:960224:linenosz changeable for edit/browse               //~v069R~
//            edit lineno,set UCWlinenosz,ajust ufld            //~v069I~
//v05v:951203:(BUG)find all offset table shared,it must be for each pfh//~v05vI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v046:950923:view dir lcmd                                     //~v046I~
//v03u:950827:bug;ULHFLINECMD(lcmd reg sw) reset by xechar ignore//~v03uI~
//            lcmd input from other side of same pfc.           //~v03uI~
//            so move lcmd stack to pfh from pfc.(alt of v03q)  //~v03uI~
//*v03n:950819:initial scroll option from xe.ini                //~v03nI~
//*v03f:950731:scroll value err revese(common rtn with xefile2) //~v03fI~
//*v03c:950731:scroll cmd cannot set scroll field when vsplit   //~v03cI~
//            if field len=0                                    //~v03cI~
//*v03a:950730:bug of v032(vsplitchk using static UFLD addr,    //~v03aI~
//             destroy freed UFLDE area after panfree)          //~v03aI~
//             if scroll null err,reverse full field            //~v03aI~
//             no need active sw because ufld for each split    //~v03aI~
//*v032:950712:UFLD for each ppc                                //~v032I~
//*v020:950618:dir support,share filewakeup with dir            //~v020R~
//*    :950701:csr set chk by Gprocstatus                       //~v020I~
//*v011:950610:reset reverse when double ESC                    //~5610I~
//************************************************************* //~v020R~
//*950527 csr set after draw(after setup psd,fld)               //~5527I~
//*950502 dbcs space display if japanese mode                   //~5502I~
//*950430 each color assignment for edit and browse             //~5430R~
//*950422 hilight by cap copy                                   //~5422I~
//*       vsplit called at other client when full draw,invalid update uflde//~5423I~
//*950123 reverse block                                         //~5123R~
//*950105 reverse for current undo result                       //~5123I~
//*950104 csr line chk before draw flag chk,req after maxline set//~5105I~
//*941229 UCWmaxline set                                        //~5104I~
//*941208 csr set req on pfc(avoid set on multiple plh by lcmd and fcmd)//~4C29I~
//*941126 multiple found word on the same line
//*941122 found word display
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
#ifdef W32                                                         //~vb4fI~
	#include <windows.h>                                           //~vb4fI~
#endif                                                             //~vb4fI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318R~
#include <ualloc.h>                                             //~5318I~
#include <udbcschk.h>                                              //~v217I~
#include <uedit2.h>                                                //~v440I~
#include <utrace.h>                                                //~v06yI~
#include <ufilew.h>                                                //~vavaI~
#ifdef FTPSUPP                                                     //~v58LI~
	#include <uftp.h>                                              //~v58LI~
#endif                                                             //~v58LI~
#ifdef UTF8SUPPH                                                   //~va00R~
	#include <ustring.h>                                           //~va00I~
	#include <utf.h>                                               //~va00I~
#endif                                                             //~v58LI~//~va00I~
#include <utf22.h>                                                 //~vavtI~
#define UVIOMDEFONLY	//for uviom.h                              //~vb4fI~
#include <uviom.h>                                                 //~vb4fI~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefunc.h"
#include "xefile.h"
#include "xefile2.h"
#include "xefile22.h"                                              //~v440I~
#include "xefile3.h"                                            //~v03nI~
#include "xefile6.h"                                               //~v0avI~
#include "xefcmd4.h"                                               //~v11NI~
#include "xechar.h"
#include "xecap.h"                                              //~5123I~
#include "xefsub.h"                                             //~5318R~
#include "xepan.h"                                              //~5318I~
#include "xepan22.h"                                               //~va1BI~
#include "xesub.h"                                              //~5318I~
#include "xesub2.h"                                                //~va1cR~
#include "xedir.h"                                              //~v04dI~
#include "xedlcmd.h"                                            //~v046M~
#include "xedlcmd2.h"                                           //~v046M~
#include "xegbl.h"                                                 //~v440I~
#include "xeopt.h"                                                 //~v44mI~
#ifdef UTF8SUPPH                                                   //~va00R~
	#include "xeutf.h"                                             //~va00I~
	#include "xeutf2.h"                                            //~va5sI~
#endif                                                             //~v58LI~//~va00I~
#include "xefsubw.h"                                               //~vavcI~
//*******************************************************
#define FILENAMEPOS   8
//#define COLUMNDISPPOS 18     //" xxx-(xxx)-xxx Rep"              //~v57GR~
#define COLUMNDISPPOS 19       //" xxxx-xxxx-xxxx Rep"             //~v57GI~
//#define COLUMNDISPPOSDIR 4       //" Rep"                          //~v60bI~//+vb7kR~
#define COLUMNDISPW   4        //" xxxx-xxxx-xxxx Rep"             //~v57GI~
#define COLUMNDISPSC  1      //start column
#define COLUMNDISPCC  6      //curr  column
#define COLUMNDISPEC  11     //end   column
#define NOTUPDATEDID  '|'    //update file/line id              //~5107I~
#define UPDATEID      '*'    //update file/line id              //~5107I~
#define SPLITTOPID    '-'    //post of split line id               //~v0agR~
#define SPLITID       '.'    //post of split line id             //~v0eQR~
#define SPLITTOPUPDID '+'    //post of split line id               //~v0agI~
#define SPLITUPDATEID ':'    //post of split update line id      //~v0eQR~
#define TABPADCHARDISPX '-'   //tab skip hex notation              //~v09SI~
#define PROTAREADRAW	19				//prot area display        //~v0ifI~
                                                                   //~v75EI~
#define BNDS_LEFTID   '<'		//boundary indicator               //~v75EI~
#define BNDS_RIGHTID  '>'		//boundary indicator               //~v75EI~
                                                                   //~v217I~
//#define PRINTABLE_EOLID '_'                                      //~v47dR~
//#ifdef UNX                                                       //~v47dR~
//  #ifdef LNX                                                     //~v47dR~
//    #define EOLID  0x1d                                          //~v47dR~
//  #else                                                          //~v47dR~
//    #define EOLID  PRINTABLE_EOLID                               //~v47dR~
//  #endif                                                         //~v47dR~
//#else                                                            //~v47dR~
//    #define EOLID  0x1b                                          //~v47dR~
//#endif                                                           //~v47dR~
//*************************
//static int Smerginoffs;     //parm to setline attr               //~v69DR~
//static int Shexoffs,Shexcsrpos,Sdatacsrpos;         //parm to setline attr//~v69DR~
//static int Sdatacsrpos2;        //parm to setline attr           //~v69DR~
//static int Sprotlen;        //parm to setline attr               //~v69DR~
//static int Sfileupundoctr;  //parm to setline attr               //~v69DR~
//static int Sfileupctr;  //parm to setline attr                   //~v69DR~
//static int Sfileresetsw;//v011 parm to setline attr(cap paste reset)//~v69DR~
//static int Soldlinesw=0;        //change by many line isrt       //~v69DR~
//static int Seolid=EOLID;		//change by many line isrt         //~v47dR~
//static UCHAR Scolor_lineno,Scolor_client,Scolor_lineno_r,Scolor_client_r;//~v69DR~
//static UCHAR Sprotattr,Sprotattr_r;                              //~v69DR~
//static UCHAR Smerginattr;                                        //~v69DR~
//static UCHAR Shexattr;                                           //~v69DR~
//static UCHAR Shexcsrattr;                                        //~v69DR~
//#ifdef WXE                                                       //~v621R~
//    static int Sresizesw=0;                                      //~v621R~
//#endif                                                           //~v621R~
//unprintable char definition(for english x00 only)                //~v09UI~
//*************************                                        //~v09UI~
void vsplitshift(PUCLIENTWE Ppcw);
//int tabdisplay(UCHAR *Pdata,UCHAR *Pdbcs,int Plen);              //~v0avR~
//void setlineattr(PUCLIENTWE Ppcw,PULINEH Pplh,PUSCRD Ppsd,       //~v69DR~
//					int Pcellsw);                                  //~v69DR~
//void filecolsdisp(PUCLIENTWE Ppcw,PUSCRD Ppsd,int Pfullsw);      //~v69DR~
#ifdef UTF8SUPPH                                                   //~va00R~
	int fileutf8inithdrattr(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PUSCRD Ppsd,char *Phdr,int *Pphdrlen);//~va00R~
	int fileutf8sethdrattr(PUCLIENTWE Ppcw,PUSCRD Ppsd,PUFILEH Ppfh,int Poutoffs,int Pfnoffs,int Pfnwidth,int Pscrwidth);//~va00R~
	int fileutf8sethdrattrreset(PUCLIENTWE Ppcw,PUSCRD Ppsd,PUFILEH Ppfh);  //~v91yR~//~va00R~
#ifdef AAA //not used                                              //~vau4I~
	int filehdrlf2dd(int Popt,PUFILEH Ppfh,PUPANELC Pppc,int Phdroffs,int Pfnmlcoffs,int Pfnmlclen);//~va5sR~
#endif                                                             //~vau4I~
#endif                                                             //~va00I~
int fileutf8sethdrattr_adjusted(PUCLIENTWE Ppcw,PUSCRD Ppsd,PUFILEH Ppfh,char *Ppct,int Poutoffs,int Pfnoffs,int Pfnwidth,int Pscrwidth);//~vamBI~
int filehdrlf2dd_full(int Popt,PUFILEH Ppfh,char **Pppdata,char **Pppdbcs,int *Ppddlen);//~vamBR~
#ifdef W32UNICODE                                                  //~vavaI~
	int filehdrnameUD2DD(int Popt,PUFILEH Ppfh,char *Puddata,char *Puddbcs,int Pudlen,char *Pdddata,char *Pdddbcs,int Pbuffsz,int *Ppddlen);//~vavaI~
#endif                                                             //~vavaI~
//****************************************************************
// filepopup
//*free file clientwe and popup previousclient
//*parm :client work element
//*return:new client work
//****************************************************************
PUCLIENTWE filepopup(PUCLIENTWE Ppcw)
{
	PUFILEC pfc;
//*******************
//*UFILEC init
	pfc=Ppcw->UCWpfc;
//  if (pfc->UFCpvlcmd)                                         //~v03uR~
//  	ufree(pfc->UFCpvlcmd);	//ULCMD copy area               //~v03uR~
	dlcmddeqpfc(pfc);                                           //~v046I~
    fcmdcolfree(pfc);            //free cols data                  //~v11NR~
	if (pfc->UFCdeepestpath)   //for path up/down                  //~v558I~
		ufree(pfc->UFCdeepestpath);                                //~v558I~
	ufree(pfc);
	return panpopup(Ppcw);
}//filepopup                                                    //~5118R~
//*************************************************************************************//~vamBI~
//*fill hdrline by ddfmt filename                                  //~vamBI~
//*************************************************************************************//~vamBI~
void adjustddfmthdr(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUPANELC Pppc,PUSCRD Ppsd,int Pfldwidth,char *Ppdddata,char *Ppdddbcs,int Pddstrlen,int Ptailsz)                                                 //~v046I~//~vamBR~
{                                                                  //~vamBI~
	int ui,uj,tailsz,fnmlen,lenpadd,lenct;                         //~vau7R~
    char *pdddata,*pdddbcs,*pdata,*pdbcs;                          //~vaubR~
    int ddstrlen;                                                  //~vauqR~
    char *pdddata0,*pdddbcs0;                                      //~vauqI~
//#ifdef LNX                                                         //~vau7I~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
	char wkdddata[_MAX_PATH+32];                                   //~vauqI~
	char wkdddbcs[_MAX_PATH+32];                                   //~vauqI~
#else                                                              //~vau7I~
//#ifdef AAA                                                         //~vauLI~//~vavaR~
//    int len;                                                       //~vau7I~//~vavaR~
//    char *pcd;                                                     //~vau7I~//~vavaR~
//    char *pct;                                                     //~vaubI~//~vavaR~
//#endif                                                             //~vauLI~//~vavaR~
#endif                                                             //~vau7I~
#ifdef W32UNICODE                                                  //~vavcI~
    char *pct;                                                     //~vavcI~
#endif                                                             //~vavcI~
#ifdef LNX                                                         //~vb2mI~
    int ctoffs=0;                                                  //~vb2mR~
#endif                                                             //~vb2mI~
//***********************************                              //~vamBI~
    UTRACEP("adjustddfmthdr fldwidth=%d,ddstrlen=%d,tailsz=%d\n",Pfldwidth,Pddstrlen,Ptailsz);//~vamBR~
    UTRACED("adjustddfmthdr inp pdddata_full=",Ppdddata,Pddstrlen);//~vamBI~
    UTRACED("adjustddfmthdr inp pdddbcs_full=",Ppdddbcs,Pddstrlen);//~vamBI~
#ifdef LNX                                                         //~vauqI~//~vavaR~
//	memcpy(wkdddata,Ppdddata,Pddstrlen);	                       //~vauqR~//~vb2eR~
  	memcpy(wkdddata,Ppdddata,(size_t)Pddstrlen);                   //~vb2eI~
//  memcpy(wkdddbcs,Ppdddbcs,Pddstrlen);                           //~vauqR~//~vb2eR~
    memcpy(wkdddbcs,Ppdddbcs,(size_t)Pddstrlen);                   //~vb2eI~
//  memcpy(wkdddata+Pddstrlen,Ppfh->UFHhdrnamebyu8+strlen(Ppfh->UFHhdrnamebyu8)-Ptailsz,Ptailsz);//~vauqI~//~vb2eR~
    memcpy(wkdddata+Pddstrlen,Ppfh->UFHhdrnamebyu8+strlen(Ppfh->UFHhdrnamebyu8)-Ptailsz,(size_t)Ptailsz);//~vb2eI~
//  memset(wkdddbcs+Pddstrlen,0,Ptailsz);                          //~vauqI~//~vb2eR~
    memset(wkdddbcs+Pddstrlen,0,(size_t)Ptailsz);                  //~vb2eI~
    Ppfh->UFHhdrnamewidth=Pddstrlen;                               //~vb3iI~
    ddstrlen=Pddstrlen+Ptailsz;                                    //~vauqR~
    pdddata0=wkdddata;                                             //~vauqI~
    pdddbcs0=wkdddbcs;                                             //~vauqI~
#else                                                              //~vauqI~
#ifdef W32UNICODE                                                  //~vavaI~
	filehdrnameUD2DD(0,Ppfh,Ppdddata,Ppdddbcs,Pddstrlen,wkdddata,wkdddbcs,_MAX_PATH,&ddstrlen);//~vavaR~
    memcpy(wkdddata+ddstrlen,Ppfh->UFHhdrnamebyu8+strlen(Ppfh->UFHhdrnamebyu8)-Ptailsz,Ptailsz);//~vavaI~
	memset(wkdddbcs+ddstrlen,0,Ptailsz);                           //~vavaI~
    ddstrlen+=Ptailsz;                                             //~vavaI~
    pdddata0=wkdddata;                                             //~vavaI~
    pdddbcs0=wkdddbcs;                                             //~vavaI~
    pct=Ppfh->UFHhdrnameattr;                                      //~vavcI~
#else                                                              //~vavaI~
    ddstrlen=Pddstrlen;                                            //~vauqM~
    pdddata0=Ppdddata;                                             //~vauqI~
    pdddbcs0=Ppdddbcs;                                             //~vauqR~
#endif                                                             //~vavaI~
#endif                                                             //~vauqI~
    pdata=Ppsd->USDdata+FILENAMEPOS;                               //~vamBR~
    pdbcs=Ppsd->USDdbcs+FILENAMEPOS;                               //~vamBR~
	tailsz=Ptailsz;                                                //~vamBI~
    ui=Pfldwidth;         //filename sapec before colomn display
//  uj=(int)(strlen(Gfilebuff)-tailsz);		//except timestamp     //~vamBI~
//  uj=Pddstrlen-tailsz;                                           //~vauqR~
    uj=ddstrlen-tailsz;                                            //~vauqI~
    if (uj<=ui)		//avail space                                  //~vamBI~
    {                                                              //~vamBI~
    	uj+=(int)tailsz;		//containing timestamp             //~vamBI~
        ui=min(uj,ui);  //until " COL..."                          //~vamBR~
        if (ui>0)                                                  //~vamBI~
        {                                                          //~vamBI~
//        memcpy(pdata,Ppdddata,(UINT)ui);                         //~vauqR~
//        memcpy(pdbcs,Ppdddbcs,(UINT)ui);                         //~vauqR~
          memcpy(pdata,pdddata0,(UINT)ui);                         //~vauqI~
          memcpy(pdbcs,pdddbcs0,(UINT)ui);                         //~vauqI~
        }                                                          //~vamBI~
        fnmlen=ui;                                                 //~vamBR~
    }                                                              //~vamBI~
    else            //no space,display tail                        //~vamBI~
    {                                                              //~vamBI~
    	ui-=3;                                                     //~vamBI~
        memcpy(pdata,"...",3);                                     //~vamBR~
        memset(pdbcs,0,3);                                         //~vamBR~
#ifdef W32UNICODE                                                  //~vb3dI~
        memset(pct,0,3);                                           //~vb3dI~
#endif                                                             //~vb3dI~
        fnmlen=3;                                                  //~vamBI~
      	if (ui>0)	//filename space avail                         //~vamBR~
      	{                                                          //~vamBR~
//  		memcpy(pdata+3,Ppdddata+uj-ui,ui);                     //~vauqR~
//  		memcpy(pdbcs+3,Ppdddbcs+uj-ui,ui);                     //~vauqR~
//  		memcpy(pdata+3,pdddata0+uj-ui,ui);                     //~vauqI~//~vb2eR~
    		memcpy(pdata+3,pdddata0+uj-ui,(size_t)ui);             //~vb2eI~
//  		memcpy(pdbcs+3,pdddbcs0+uj-ui,ui);                     //~vauqI~//~vb2eR~
    		memcpy(pdbcs+3,pdddbcs0+uj-ui,(size_t)ui);             //~vb2eI~
#ifdef W32UNICODE                                                  //~vavcI~
    		memcpy(pct+3,pct+uj-ui,ui);                            //~vavcI~
#endif                                                             //~vavcI~
#ifdef LNX                                                         //~vb2mI~
            ctoffs=uj-ui;                                          //~vb2mI~
#endif                                                             //~vb2mI~
            fnmlen+=ui;                                            //~vamBI~
      	}                                                          //~vamBR~
        if (UDBCSCHK_DBCS2NDU(*(pdbcs+3)))                   //~va5sI~//~vamBI~
        {                                                          //~vamBR~
			*(pdata+3)=' ';                                        //~vamBR~
			*(pdbcs+3)=0;                                          //~vamBI~
        }                                                          //~vamBR~
    }                                                              //~vamBI~
  	lenpadd=Pfldwidth-fnmlen;                                      //~vamBI~
    lenct=Ppfh->UFHhdrnamewidth; //codetbl length                  //~vavrI~
  	if (lenpadd>0)
  	{                                                              //~vamBI~
//		memset(pdata+Pfldwidth-lenpadd,'-',lenpadd);               //~vamBR~//~vb2eR~
  		memset(pdata+Pfldwidth-lenpadd,'-',(size_t)lenpadd);       //~vb2eI~
//		memset(pdbcs+Pfldwidth-lenpadd,0,lenpadd);                 //~vamBR~//~vb2eR~
  		memset(pdbcs+Pfldwidth-lenpadd,0,(size_t)lenpadd);         //~vb2eI~
#ifdef W32UNICODE                                                  //~vavcI~
//		memset(pct+Pfldwidth-lenpadd,0,lenpadd);                   //~vavcI~//~vavrR~
		if (lenct<Pfldwidth-lenpadd)                               //~vavrI~
			memset(pct+Pfldwidth-lenpadd,0,min(lenpadd,Pfldwidth-lenpadd-lenct));//~vavrI~
#endif                                                             //~vavcI~
	}                                                              //~vamBI~
    UTRACED("adjustddfmthdr pdata",pdata,Pfldwidth);               //~vamBI~
    UTRACED("adjustddfmthdr pdbcs",pdbcs,Pfldwidth);               //~vamBI~
	pdddata=Pppc->UPCline[0].UPLbuff+FILENAMEPOS;	//USDbuffc     //~vamBM~
    pdddbcs=Pppc->UPCline[0].UPLdbcs+FILENAMEPOS;                  //~vamBM~
//  memcpy(pdddata,pdata,Pfldwidth);   //vsplitshift set from USDbuffc(=UPLbuffc)//~vamBI~//~vb2eR~
    memcpy(pdddata,pdata,(size_t)Pfldwidth);   //vsplitshift set from USDbuffc(=UPLbuffc)//~vb2eI~
//  memcpy(pdddbcs,pdbcs,Pfldwidth);                               //~vamBI~//~vb2eR~
    memcpy(pdddbcs,pdbcs,(size_t)Pfldwidth);                       //~vb2eI~
    UTRACED("adjustddfmthdr pdddata",pdddata,Pfldwidth);           //~vamBI~
    UTRACED("adjustddfmthdr pdddbcs",pdddbcs,Pfldwidth);           //~vamBI~
//set utf8 attr                                                    //~vamBI~
//#ifdef LNX                                                         //~vaubI~//~vavaR~
//#else                                                              //~vaubI~//~vavaR~
//#ifdef AAA                                                         //~vauLI~//~vavaR~
//    pct=Ppfh->UFHhdrnameattr;                                      //~vamBI~//~vavaR~
//#endif                                                             //~vauLI~//~vavaR~
//#endif                                                             //~vaubI~//~vavaR~
    lenct=Ppfh->UFHhdrnamewidth; //codetbl length                  //~vamBI~
    UTRACED("adjustddfmthdr pct old",Ppfh->UFHhdrnameattr,Ppfh->UFHhdrnamewidth);//~vamBI~
//#ifdef LNX                                                         //~vau7I~//~vavaR~
//#else                                                              //~vau7I~//~vavaR~
//#ifdef AAA                                                         //~vauLI~//~vavaR~
//    memset(pct,0,lenct);                                           //~vamBI~//~vavaR~
//    len=min(lenct,fnmlen);                                         //~vamBR~//~vavaR~
//    for (pcd=pdbcs;len>0;len--,pct++,pcd++)                        //~vamBR~//~vavaR~
//        if (*pcd)                                                  //~vamBI~//~vavaR~
//            *pct=XEUTFCT_UTF8;  //   0x01                          //~vamBR~//~vavaR~
//    UTRACED("adjustddfmthdr pct old2",Ppfh->UFHhdrnameattr,Ppfh->UFHhdrnamewidth);//~vamBI~//~vavaR~
//#endif                                                             //~vauLI~//~vavaR~
//#endif                                                             //~vau7I~//~vavaR~
#ifdef LNX                                                         //~vb2mI~
    fileutf8sethdrattr(Ppcw,Ppsd,Ppfh,FILENAMEPOS/*out pos in cell*/,ctoffs,lenct,Pfldwidth);	//set cell attr//~vb2mI~
#else                                                              //~vb2mI~
    fileutf8sethdrattr(Ppcw,Ppsd,Ppfh,FILENAMEPOS/*out pos in cell*/,0/*input pos in pct*/,lenct,Pfldwidth);	//set cell attr//~vamBR~
#endif                                                             //~vb2mI~
    UTRACED("adjustddfmthdr pct",Ppfh->UFHhdrnameattr,Ppfh->UFHhdrnamewidth);//~vamBR~
#ifdef LNX                                                         //~vb2mI~
    UTRACED("adjustddfmthdr pct",Ppfh->UFHhdrnameattr+ctoffs,Ppfh->UFHhdrnamewidth-ctoffs);//~vb2mI~
#endif                                                             //~vb2mI~
    UTRACED("adjustddfmthdr data=",pdata,Pfldwidth);               //~vamBR~
    UTRACED("adjustddfmthdr dbcs=",pdbcs,Pfldwidth);               //~vamBR~
}//adjustddfmthdr                                                  //~vamBI~
//****************************************************************
// filewakeup                                                   //~v020R~
//*USCRD init at first and when became new forground screen
//*parm1:client work
//*rc   :0
//****************************************************************
int filewakeup(PUCLIENTWE Ppcw)                                 //~v020R~
{
//	UINT ui,uj,tailsz=0;                                           //~v51VR~
  	UINT tailsz=0;                                                 //~v51VI~
  	int  ui,uj;                                                    //~v51VI~
    int i,jj,maxline,width;                                     //~v032R~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iI~
    int oldscrollid;                                               //~v56qI~
    int resizesw;                                                  //~v621I~
#endif                                                             //~v56qI~
#ifdef FTPSUPP                                                     //~v58LI~
    PUFTPHOST puftph;                                              //~v58LI~
#endif                                                             //~v58LI~
	PUSCRD psd;
	PUPANELC ppc;
	PUPANELD ppd;
	PUFILEC  pfc;
	PUFILEH  pfh;
	UCHAR *pc,*pcw;                                             //~5224R~
	UCHAR *pdbcs;                                                  //~v77kI~
#ifdef UTF8SUPPH                                                   //~va00I~
    int  lenlc;                                                    //~va00I~
    int  encoding;                                                 //~va00I~
    int  dbcssplitsw;                                              //~va13I~
    char dbcswk[_MAX_PATH];                                        //~va13I~
#endif                                                             //~va00I~
//  PUFLD	pfld;                                               //~v06qR~
//	int fnmlcoffs,fnmlclen,hdroffs;                                //~va5sI~//~vaq1R~
    int ddstrlen;                                                  //~vamBR~
    char *pdddata,*pdddbcs;                                        //~vamBI~
//*******************
//#ifdef UNX                                                       //~v47dR~
////  if (Gudbcschk_flag & UDBCSCHK_UNICODE)                       //~v47dR~
//    if (Gunxflag & GUNX_KON)         //may be kon                //~v47dR~
//        Seolid=PRINTABLE_EOLID;                                  //~v47dR~
//#endif                                                           //~v47dR~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iI~
	ppc=Ppcw->UCWppc;                                              //~v56qI~
    oldscrollid=ppc->UPCscroll;	//save over resize init            //~v56qI~
//  Sresizesw=UCBITCHK(Ppcw->UCWflag,UCWFRESIZE);	//for vsplit   //~v621R~
    resizesw=UCBITCHK(Ppcw->UCWflag,UCWFRESIZE);	//for vsplit   //~v621I~
    ppdinit_resize(Ppcw); //re-int ufld                            //~v500R~
//  if (Sresizesw)	//save over resize init                        //~v621R~
    if (resizesw)	//save over resize init                        //~v621I~
    {                                                              //~v56qI~
	    ppc->UPCscroll=oldscrollid;	//save over resize init        //~v56qI~
		filesetscrollsz(Ppcw,filegetscrollid(oldscrollid));	//default half//~v56qI~
    }                                                              //~v56qI~
#endif                                                             //~v500R~
	psd=Ppcw->UCWpsd;
	ppc=Ppcw->UCWppc;
	ppd=ppc->UPCppd;
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iI~
    if (resizesw)	//save over resize init                        //~v621R~
    {                                                              //~v621I~
	    UCBITON(pfh->UFHflag6,UFHF6RESIZE);                        //~v621I~
	    UCBITON(pfc->UFCflag2,UFCF2RESIZE);                        //~v621I~
    }                                                              //~v621I~
#endif                                                             //~v621I~
	maxline=Gscrheight;
//  width  =Gscrwidth;                                             //~v51VR~
//  width  =Gscrbuffwidth;   //fixed or,for wxe,max width          //~v549R~
    width  =Gscrwidth;                                             //~v549R~
//hdr line *********
//	psd->USDnattr=Gattrtbl[COLOR_FRAME];	override by xescr
	psd->USDcell0len=0;			//no special cell
	psd->USDnattr0len=0;		//no special attr data
	pc=psd->USDbuffc=ppc->UPCline[0].UPLbuff;                       //~4C17R~
	if (Ppcw->UCWmenuopt==PANMOCMD)                                   //~v06yI~
    {                                                              //~v58LI~
#ifdef FTPSUPP                                                     //~v8@ZI~
      if (UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD))                   //~v78ZI~
      {                                                            //~v8@ZI~
       if (UCBITCHK(Ppcw->UCWflag3,UCWF33270KBD2))                 //~v8@ZI~
        memcpy(pc,"TSO-",4);                                       //~v8@ZR~
       else                                                        //~v8@ZI~
        memcpy(pc,"3270",4);                                       //~v78ZI~
      }                                                            //~v8@ZI~
      else                                                         //~v78ZI~
#endif                                                             //~v8@ZI~
      if (UCBITCHK(pfh->UFHflag6,UFHF6RLOGIN))                     //~v58LI~
        memcpy(pc,"RSH-",4);                                       //~v58LI~
      else                                                         //~v58LI~
        memcpy(pc,"CMD-",4);                                          //~v06nI~
    }                                                              //~v58LI~
    else                                                           //~v0ifI~
   		if (pfh->UFHtype==UFHTKFI)	//ke func ini file             //~v0ifI~
	        memcpy(pc,"KEY---",6);                                 //~v0izR~
	psd->USDpfld=ppc->UPCline[0].UPLpfld;	//UFLD              //~v032R~
	psd->USDflag=USDFCHARSTRATT;
    psd->USDuvioo=0; //set at inithdr                              //~vb4fR~
	psd->USDflag2=(UCHAR)ppd->UPDprottype;
//filename
//  memset(pc+FILENAMEPOS,'-',ui=(UINT)(width-COLUMNDISPPOS-FILENAMEPOS));//~v50oR~
  if (pfh->UFHtype==UFHTDIR)          //dir                        //~v60bI~
    ui=(width-COLUMNDISPPOSDIR-FILENAMEPOS);                       //~v60bI~
  else                                                             //~v60bI~
    ui=(width-COLUMNDISPPOS-FILENAMEPOS);                          //~v51VR~
    if ((int)ui>0)                                                 //~v51VR~
		memset(pc+FILENAMEPOS,'-',(UINT)ui);                       //~v51VR~
	*(pc+FILENAMEPOS-1)=' ';
    if (UCBITCHK(pfh->UFHflag,UFHFNEW)) //new file              //~4C31I~
    {                                                           //~v06oI~
    	if (UCBITCHK(pfh->UFHflag,UFHFWORKDIRFILE))             //~v06oI~
        	pcw=pfh->UFHalias;                                  //~v06oI~
        else                                                    //~v06oI~
        	pcw=pfh->UFHfilename;                               //~v06oI~
	  if (pfh->UFHtype==UFHTKFI)	//ke func ini file             //~v0imR~
    	sprintf(Gfilebuff,"%s",                                    //~v0imR~
				pcw);                                              //~v0imI~
      else                                                         //~v0imI~
      {                                                            //~v47bI~
#ifdef UNX                                                         //~v41vI~
       if (Glocalhostsw)                                           //~v64bI~
    	sprintf(Gfilebuff,"%s (NEW FILE)",                         //~v64bI~
    			pcw);                                              //~v64bI~
       else                                                        //~v64bI~
    	sprintf(Gfilebuff,"%s|%s (NEW FILE)",                      //~v41vR~
//    			Ghostname,pcw);                                    //~v64dR~
      			Ghostname2,pcw);                                   //~v64dI~
#else                                                              //~v41vI~
    	sprintf(Gfilebuff,"%s (NEW FILE)",                      //~4C31R~
				pcw);                                           //~v06oR~
#endif                                                             //~v41vI~
		tailsz=11;		//timestampsz                              //~v47bI~
      }                                                            //~v47bI~
    }                                                           //~v06oI~
	else                                                        //~v020I~
    if (pfh->UFHtype==UFHTDIR           //dir                   //~v020I~
    &&  !pfh->UFHlevel) //root level                            //~v03fR~
    {                                                              //~v47bI~
#ifdef UNX                                                         //~v41vI~
       if (Glocalhostsw)                                           //~v64bI~
    	sprintf(Gfilebuff,"%s (ROOT DIR)",                         //~v64bI~
    			pfh->UFHfilename);                                 //~v64bI~
       else                                                        //~v64bI~
    	sprintf(Gfilebuff,"%s|%s (ROOT DIR)",                      //~v41vR~
//  			Ghostname,pfh->UFHfilename);                       //~v64dR~
    			Ghostname2,pfh->UFHfilename);                      //~v64dI~
#else                                                              //~v41vI~
    	sprintf(Gfilebuff,"%s (ROOT DIR)",                      //~v020I~
				pfh->UFHfilename);                              //~v020I~
#endif                                                             //~v41vI~
		tailsz=11;		//timestampsz                              //~v47bI~
    }                                                              //~v47bI~
	else                                                        //~4C31I~
    {                                                           //~5224I~
    	if (UCBITCHK(pfh->UFHflag,UFHFWORKDIRFILE))             //~5224I~
        	pcw=pfh->UFHalias;                                  //~5224I~
        else                                                    //~5224I~
        	pcw=pfh->UFHfilename;                               //~5224I~
#ifdef FTPSUPP                                                     //~v58LR~
      if (UCBITCHK(pfh->UFHflag6,UFHF6RLOGIN))                     //~v58LI~
      {	//rlogin                                                   //~v58LI~
      	puftph=pfh->UFHpuftph;                                     //~v58LI~
	#ifdef UNX                                                     //~v58LI~
       if (Glocalhostsw)                                           //~v64bI~
    	sprintf(Gfilebuff,"%s %8s:(%s)",                           //~v64bI~
    			pcw,                                               //~v64bI~
    	        puftph->UFTPHhost,puftph->UFTPHipad);              //~v64bI~
       else                                                        //~v64bI~
    	sprintf(Gfilebuff,"%s|%s %8s:(%s)",                        //~v58LI~
//  			Ghostname,pcw,                                     //~v64dR~
    			Ghostname2,pcw,                                    //~v64dI~
    	        puftph->UFTPHhost,puftph->UFTPHipad);              //~v58LI~
	#else                                                          //~v58LI~
    	sprintf(Gfilebuff,"%s %s:(%s)",                            //~v58LI~
				pcw,                                               //~v58LI~
    	        puftph->UFTPHhost,puftph->UFTPHipad);              //~v58LI~
	#endif                                                         //~v58LI~
//  	tailsz=strlen(Gfilebuff)                                   //~v58LI~//~vb2ER~
    	tailsz=(UINT)(strlen(Gfilebuff)                            //~vb2EI~
//             -((ULONG)strchr(Gfilebuff,' ')-(ULONG)Gfilebuff);   //~v58LR~//~vafkR~
//             -((ULPTR)strchr(Gfilebuff,' ')-(ULPTR)Gfilebuff);   //~vafkI~//~vb2ER~
               -((ULPTR)strchr(Gfilebuff,' ')-(ULPTR)Gfilebuff));  //~vb2EI~
      }                                                            //~v58LI~
      else                                                         //~v58LI~
      {	//not rlogin                                               //~v58LI~
#endif                                                             //~v58LI~
#ifdef UNX                                                         //~v41vI~
       if (Glocalhostsw)                                           //~v64bI~
    	sprintf(Gfilebuff,"%s (%02d-%02d-%02d %02d:%02d)",         //~v64bI~
  	 			pcw,                                               //~v64bI~
    	        (pfh->UFHfiledate.year+80)%100,                    //~v64bI~
       			pfh->UFHfiledate.month,                            //~v64bI~
          		pfh->UFHfiledate.day,                              //~v64bI~
          		pfh->UFHfiletime.hours,                            //~v64bI~
          		pfh->UFHfiletime.minutes);                         //~v64bI~
       else                                                        //~v64bI~
    	sprintf(Gfilebuff,"%s|%s (%02d-%02d-%02d %02d:%02d)",      //~v41vR~
//  	 		Ghostname,pcw,                                     //~v64dR~
  	 			Ghostname2,pcw,                                    //~v64dI~
    	        (pfh->UFHfiledate.year+80)%100,                    //~v41vI~
       			pfh->UFHfiledate.month,                            //~v41vI~
          		pfh->UFHfiledate.day,                              //~v41vI~
          		pfh->UFHfiletime.hours,                            //~v41vI~
          		pfh->UFHfiletime.minutes);                         //~v41vI~
#else                                                              //~v41vI~
    	sprintf(Gfilebuff,"%s (%02d-%02d-%02d %02d:%02d)",      //~4C31R~
				pcw,                                            //~5224R~
//  	        pfh->UFHfiledate.year+80,                          //~v145R~
    	        (pfh->UFHfiledate.year+80)%100,                    //~v145R~
       			pfh->UFHfiledate.month,                         //~4C31R~
          		pfh->UFHfiledate.day,                           //~4C31R~
          		pfh->UFHfiletime.hours,                         //~4C31R~
          		pfh->UFHfiletime.minutes);                      //~4C31R~
#endif                                                             //~v41vI~
		tailsz=17;		//timestampsz                              //~v47bI~
#ifdef FTPSUPP                                                     //~v58LI~
      }//	//not rlogin                                           //~v58LI~
#endif                                                             //~v58LI~
	}                                                           //~5224I~
//  memcpy(pc+FILENAMEPOS,Gfilebuff,                               //~v47bR~
//  		ui=min(strlen(Gfilebuff),ui));	//until " COL..."      //~v47bR~
#ifdef UTF8SUPPH                                                   //~va00I~
    encoding=filegetencoding(Ppcw,pfc,pfh);                        //~va00I~
    if (encoding)                                                  //~va00I~
    {                                                              //~va00I~
      if (tailsz)                                                  //~vb52M~
      {                                                            //~vb52M~
//      lenlc=strlen(Gfilebuff)-tailsz+1;   //top of tail is space //~va00R~//~vb2eR~
        lenlc=(int)strlen(Gfilebuff)-(int)tailsz+1;   //top of tail is space//~vb2eR~
    	memmove(Gfilebuff+lenlc+2,Gfilebuff+lenlc,tailsz); //with last null//~va00R~
        *(Gfilebuff+lenlc)='=';                                    //~va00R~//~va0xR~
        *(Gfilebuff+lenlc+1)=(char)encoding;                       //~va00I~
        tailsz+=2;                                                 //~va00R~
      }                                                            //~vb52M~
    }                                                              //~va00I~
//  lenlc=tailsz;                                                  //~va00I~//~vb2eR~
    lenlc=(int)tailsz;                                             //~vb2eI~
	fileutf8inithdrattr(0,Ppcw,pfh,psd,Gfilebuff,&lenlc);          //~va00R~
#endif                                                             //~va00I~
  if (psd->USDflag==USDFCELLSTR3)  //fileutf8 set "contains utf8 code"//~vamBR~
  {                                                                //~vamBI~
  	if (!filehdrlf2dd_full(0,pfh,&pdddata,&pdddbcs,&ddstrlen))//to dd fmt//~vamBR~
//      adjustddfmthdr(Ppcw,pfh,ppc,psd,ui,pdddata,pdddbcs,ddstrlen,tailsz);//~vamBR~//~vb2eR~
        adjustddfmthdr(Ppcw,pfh,ppc,psd,ui,pdddata,pdddbcs,ddstrlen,(int)tailsz);//~vb2eI~
    else                                                           //~vamBI~
    	ddstrlen=0;                                                //~vamBI~
  }                                                                //~vamBI~
  else                                                             //~vamBI~
  	ddstrlen=0;                                                    //~vamBI~
  if (ddstrlen==0)                                                 //~vamBI~
  {                                                                //~vamBI~
    uj=(int)(strlen(Gfilebuff)-tailsz);		//except timestamp     //~v51VR~
    if (uj<=ui)		//avail space                                  //~v47bI~
    {                                                              //~v47bI~
    	uj+=(int)tailsz;		//containing timestamp             //~v51VR~
		ui=min(uj,ui);	//until " COL..."                          //~v47bI~
      if (ui>0)                                                    //~v51VI~
		memcpy(pc+FILENAMEPOS,Gfilebuff,(UINT)ui);                 //~v51VR~
#ifdef UTF8SUPPH                                                   //~va00I~
        fileutf8sethdrattr(Ppcw,psd,pfh,FILENAMEPOS,0/*offset on name fld*/,ui,width);	//set cell attr//~v90rR~//~va00R~
//      hdroffs=FILENAMEPOS; fnmlcoffs=0; fnmlclen=ui;             //~va5sI~//~vaq1R~
#endif                                                             //~va00I~
    }                                                              //~v47bI~
    else            //no space,display tail                        //~v47bI~
    {                                                              //~v47bI~
    	ui-=3;                                                     //~v47bI~
		memcpy(pc+FILENAMEPOS,"...",3);                            //~v47bI~
#ifdef UTF8SUPPH                                                   //~va13I~
    	setdbcstbl(Gfilebuff,dbcswk,uj);                           //~va13I~
//      dbcssplitsw=dbcswk[uj-ui]==UDBCSCHK_DBCS2ND;               //~va1cR~
        dbcssplitsw=XESUB_DBCSSPLITCTR_R(dbcswk+uj-ui,ui);         //~va1cR~
        ui-=dbcssplitsw;                                           //~va13I~
#endif                                                             //~va13I~
      if (ui>0)	//filename space avail                             //~v51VI~
		memcpy(pc+FILENAMEPOS+3,Gfilebuff+uj-ui,(UINT)ui);         //~v51VR~
#ifdef UTF8SUPPH                                                   //~va00I~
        if (ui>0 && dbcssplitsw)                                   //~va13I~
			*(pc+FILENAMEPOS+3+ui)=' ';                            //~va13I~
        fileutf8sethdrattr(Ppcw,psd,pfh,FILENAMEPOS+3,uj-ui,ui,width);	//set cell attr//~va00R~
//      hdroffs=FILENAMEPOS+3; fnmlcoffs=uj-ui; fnmlclen=ui-dbcssplitsw;//~va5sI~//~vaq1R~
        ui+=dbcssplitsw;                                           //~va13I~
#endif                                                             //~va00I~
        ui+=3;                                                     //~v47bI~
    }                                                              //~v47bI~
  if (ui>=0)	//filename space avail                             //~v51VI~
	*(pc+FILENAMEPOS+ui)=' ';
//  setdbcstbl(pc,ppd->UPDdbcs,width);                             //~v77kR~
    pdbcs=ppc->UPCline[0].UPLdbcs;                                 //~v77kI~
    setdbcstbl(pc,pdbcs,width);                                    //~v77kI~
//  if (psd->USDflag==USDFCELLSTR3)  //contains utf8 code          //~va5sM~//~vamBR~
//  	filehdrlf2dd(0,pfh,ppc,hdroffs,fnmlcoffs,fnmlclen);//to dd fmt//~va5sI~//~vamBR~
	memcpy(psd->USDdata,psd->USDbuffc,(UINT)width); //hdr line data//~4C17I~
//  memcpy(psd->USDdbcs,ppd->UPDdbcs,(UINT)width);	//dbcs id tbl  //~v77kR~
    memcpy(psd->USDdbcs,pdbcs,(UINT)width);	//dbcs id tbl          //~v77kI~
  }//not UTF8                                                      //~vamBI~
	(psd++)->USDppd=ppd++;
//cmd line                                                      //~v020M~
	psd->USDcell0len=0;			//no special cell
	psd->USDnattr0len=0;		//no special attr data
	psd->USDnattr=Gattrtbl[COLOR_FRAME];
	psd->USDflag=USDFCHARSTRATT;
    psd->USDuvioo=0;	//no ligature/combine for cmdline          //~vb4fR~
	psd->USDflag2=(UCHAR)ppd->UPDprottype;
	psd->USDbuffc=ppc->UPCline[1].UPLbuff;
	psd->USDpfld=ppc->UPCline[1].UPLpfld;	//UFLD              //~v032R~
	psd->USDnattr0=Gattrtbl[COLOR_FRAME_R];//used when err
	(psd++)->USDppd=ppd++;
//text line
	fileufldinit(Ppcw);	//ajust ufld                                  //~v069R~
//  pfld=ppc->UPCline[2].UPLpfld;  //UFLD for all line same     //~v06qR~
	jj=2;                                                       //~v06qI~
	for (i=2;i<maxline;i++,psd++)
	{
		psd->USDflag2=(UCHAR)ppd->UPDprottype;
		psd->USDppd=ppd;
//  	psd->USDpfld=pfld;  //UFLD for all line same            //~v06qR~
		psd->USDpfld=ppc->UPCline[jj].UPLpfld;  //UFLD for all line same//~v06qI~
        if (Ppcw->UCWtype!=UCWTFILE)	//dir                   //~v032R~
        	jj++;						//not all same          //~v032R~
	}
  	UCBITOFF(Ppcw->UCWflag,UCWFWAKEUP);                            //~v08bI~
  	UCBITON(pfc->UFCflag2,UFCF2PPCRESET);  //usdbuff reset done    //~v56rI~
	return 0;
}//filewakeup                                                   //~v020R~
                                                                //~v069I~
//****************************************************************//~v069I~
// fileufldinit                                                 //~v069I~
//*ufld setup by linenosz                                       //~v069I~
//*parm1:pcw                                                    //~v069I~
//*rc   :none                                                   //~v069I~
//****************************************************************//~v069I~
void fileufldinit(PUCLIENTWE Ppcw)                              //~v069I~
{                                                               //~v069I~
	PUPANELC ppc;                                               //~v069I~
    PUFLD	pfld;                                               //~v069I~
    int     linenosz;                                           //~v069I~
//*******************                                           //~v069I~
	if (Ppcw->UCWtype==UCWTDIR)	//browse/edit only                    //~v069I~
    	return;                                                       //~v069I~
	ppc=Ppcw->UCWppc;                                           //~v069I~
	pfld=ppc->UPCline[2].UPLpfld;  //UFLD for all line same     //~v069I~
//  if (pfld->UFLctr<=1)    //lineno fld only(BROWSE case)         //~v0jsR~
//  	return;                                                    //~v0jsR~
    linenosz=(int)Ppcw->UCWlinenosz;                            //~v069I~
  if (pfld->UFLctr>1)    //not lineno fld only(BROWSE case)        //~v0jsI~
    pfld->UFLentry[1].UFLstart=linenosz;                        //~v069I~
    if (--linenosz<0)                                           //~v069I~
    	linenosz=0;                                             //~v069I~
    pfld->UFLentry[0].UFLend=linenosz;                          //~v069I~
    return;                                                     //~v069I~
}//fileufldinit                                                 //~v069I~
//**************************************************************   //~v40hI~
// fileinitialeditlineno                                           //~v40hI~
//*edit lineno                                                     //~v40hI~
//*parm1:pfh                                                       //~v40hI~
//*parm2:plh  not yet displayed DATA line only                     //~v40hR~
//*parm3:output lineno edit area                                   //~v40hI~
//*rc   :out area fld len                                          //~v53gR~
//**************************************************************   //~v40hI~
//int fileinitialeditlineno(PUFILEH Ppfh,PULINEH Pplh,char *Pwklineno)//~v53eI~
//int fileeditlineno(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,char *Pwklineno)//~v53gR~
int fileeditlineno(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,char *Pwklineno,int Plinenosz,int Popt)//~v53gR~
{                                                                  //~v40hI~
	int    li,linesw;                                              //~v40hI~
//  UCHAR  linenowk[8];                                            //~v53dR~
    UCHAR *linenowk;                                               //~v53dR~
    UCHAR  linenowk2[12];                                          //~v53eI~
    UCHAR  *pc;                                                    //~v53gI~
    int len2;                                                      //~v53eI~
    int linenosz;                                                  //~v53gI~
//******************                                               //~v40hI~
	*Pwklineno=0;                                                  //~v40hI~
//  if (Pplh->ULHtype!=ULHTDATA)	//file data                    //~v53eR~
//  	return 4;                                                  //~v53eR~
    linesw=(int)Ppfh->UFHlinenowk[0];                              //~v53dR~
    linenowk=Ppfh->UFHlinenowk+1;                                  //~v53dR~
    linenosz=Plinenosz;                                            //~v53gR~
    if (Pplh->ULHtype!=ULHTDATA)	//file data                    //~v53eI~
    {                                                              //~v53eI~
		memcpy(Pwklineno,Pplh->ULHlineno,ULHLINENOSZ);             //~v53eI~
    }                                                              //~v53eI~
    else                                                           //~v53eI~
  	if (UCBITCHK(Ppfh->UFHflag4,UFHF4XLINENO))                     //~v40hI~
    {                                                              //~v40hI~
//    if (UCBITCHK(Goptopt,GOPT_HEX_UPPER))                        //~v53dR~
//      sprintf(Pwklineno,"%07lX|",Pplh->ULHoffs & 0x0fffffff);//hex line offset//~v53dR~
//    else                                                         //~v53dR~
//      sprintf(Pwklineno,"%07lx|",Pplh->ULHoffs & 0x0fffffff);//hex line offset//~v53dR~
        sprintf(Pwklineno,linenowk,Pplh->ULHoffs & 0x0fffffff);//hex line offset//~v53dR~
//      return 0;                                                  //~v53eR~
    }                                                              //~v40hI~
    else    //lineno                                               //~v53eI~
    {                                                              //~v53eI~
//count digit required                                             //~v40hI~
//  li=UGETQCTR(&Ppfh->UFHlineque)+Ppfh->UFHsline;    //line ct    //~v53dR~
//  li/=10000;                  //sufficient by minimum 4 digit?   //~v53dR~
//  linesw=0;                                                      //~v53dR~
//  while (li)                                                     //~v53dR~
//  {                                                              //~v53dR~
//      linesw++;               //required digit                   //~v53dR~
//      li/=10;                                                    //~v53dR~
//  }                                                              //~v53dR~
//  sprintf(linenowk,"%%%02dld|",ULHLINENOSZ-1);	//long         //~v53dR~
//*lineno edit **                                                  //~v40hI~
    if (linesw)             //over 10000;                          //~v40hI~
    {                                                              //~v40hI~
        if (linesw==1)                                             //~v40hI~
//        	li=Pplh->ULHlinenor*100;                               //~v53eR~
//  		li=Pplh->ULHlinenor*100+min(99,Pplh->ULHsuffix);       //~v53eI~//~vb2ER~
    		li=(int)(Pplh->ULHlinenor*100+min(99,Pplh->ULHsuffix));//~vb2EI~
        else                                                       //~v40hI~
        if (linesw==2)                                             //~v40hI~
//        	li=Pplh->ULHlinenor*10;                                //~v53eR~
//  		li=Pplh->ULHlinenor*10+min(9,Pplh->ULHsuffix);         //~v53eI~//~vb2ER~
    		li=(int)(Pplh->ULHlinenor*10+min(9,Pplh->ULHsuffix));  //~vb2EI~
        else                                                       //~v40hI~
//        	li=Pplh->ULHlinenor;                                   //~v40hR~//~vb2ER~
          	li=(int)Pplh->ULHlinenor;                              //~vb2EI~
    }                                                              //~v40hI~
    else                                                           //~v40hI~
    {                                                              //~v53eI~
//  	li=Pplh->ULHlinenor*1000;                                  //~v53eR~
        if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB))                     //~v53eI~
        {                                                          //~v53eI~
//  		li=Pplh->ULHlinenor*1000+min(99,Pplh->ULHsuffix)*10;//max suffix=99//~v53eI~//~vb2ER~
    		li=(int)(Pplh->ULHlinenor*1000+min(99,Pplh->ULHsuffix)*10);//max suffix=99//~vb2EI~
//          if (Ppcw->UCWlinenosz==SPFCOBNUMFLDLEN) //small lineno (<999)//~v53gI~
            if (Popt & FELN_SHIFT 	//column shift by linenosz     //~v53gR~
            &&  linenosz==SPFCOBNUMFLDLEN) //small lineno (<999)   //~v53gR~
            	li*=10;     //shift to left by one digit           //~v53eI~
        }                                                          //~v53eI~
        else                                                       //~v53eI~
//  		li=Pplh->ULHlinenor*1000+min(999,Pplh->ULHsuffix);     //~v53eI~//~vb2ER~
    		li=(int)(Pplh->ULHlinenor*1000+min(999,Pplh->ULHsuffix));//~vb2EI~
    }                                                              //~v53eI~
//  sprintf(Pwklineno,linenowk,li);//lineno edit                   //~v53eR~
    len2=sprintf(linenowk2,linenowk,li);//lineno edit              //~v53eI~
    len2-=ULHLINENOSZ;                                             //~v53eI~
    if (len2<0)                                                    //~v53eI~
    	len2=0;                                                    //~v53eI~
    memcpy(Pwklineno,linenowk2+len2,ULHLINENOSZ);                  //~v53eI~
    }//not offset but lineno                                       //~v53eI~
                                                                   //~v53gI~
    pc=Pwklineno;                                                  //~v53gI~
    if (linenosz)                                                  //~v53gI~
    {                                                              //~v53gI~
	    if (Popt & FELN_SHIFT)                                     //~v53gI~
        {                                                          //~v53gI~
        	if (linenosz<ULHLINENOSZ) //short lineno field sz      //~v53gI~
            {                                                      //~v53gI~
  				if (UCBITCHK(Ppfh->UFHflag4,UFHF4XLINENO))         //~v53gI~
					memcpy(pc,pc+ULHLINENOSZ-linenosz,(UINT)linenosz);	//lineno//~v53gR~
          	  	else                                               //~v53gI~
    	    		if (linenosz<5+linesw) //short lineno field sz //~v53gI~
						memcpy(pc,pc+(5+linesw-linenosz),(UINT)linenosz);	//lineno//~v53gR~
            }                                                      //~v53gI~
        }                                                          //~v53gI~
	    else                                                       //~v53gI~
    		linenosz=ULHLINENOSZ;                                  //~v53gI~
        if (Popt & FELN_SETCMD)                                    //~v53gR~
            if (UCBITCHK(Pplh->ULHflag,ULHFLINECMD))//line cmd input//~v53gR~
            {                                                      //~v53gR~
                memset(pc,' ',(UINT)(linenosz-1));                 //~v53gR~
                len2=(int)strlen(Pplh->ULHlinecmd);                //~v57GR~
                len2=min(len2,linenosz-1);                         //~v53gR~
                memcpy(pc,Pplh->ULHlinecmd,(UINT)len2);            //~v53gR~
            }                                                      //~v53gR~
        pc+=linenosz-1;                                            //~v53gI~
        if (Pplh->ULHupctr)                                        //~v53gI~
            if (!UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2)) //~v53gI~
                *pc=UPDATEID;                                      //~v53gI~
            else                                                   //~v53gI~
                if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT2))          //~v53gI~
                    *pc=SPLITUPDATEID;                             //~v53gI~
                else                                               //~v53gI~
                    *pc=SPLITTOPUPDID;                             //~v53gI~
        else                                                       //~v53gI~
            if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT2))              //~v53gI~
                *pc=SPLITID;                                       //~v53gI~
          	else                                                   //~v53gI~
            	if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT1))          //~v53gI~
                	*pc=SPLITTOPID;                                //~v53gI~
                else                                               //~v53gI~
					*pc=NOTUPDATEDID;//  '|'    //update file/line id//~v53gI~
    }//linenosz!=0                                                 //~v53gI~
    return linenosz;                                               //~v53gR~
}//fileinitialeditlineno                                           //~v40hI~
//**************************************************************//~v03fR~
// filecmdlinedisp                                              //~v03fR~
//*display setup for file/dir command line                      //~v03fR~
//*parm1:pcw                                                    //~v03fR~
//*parm2:psd                                                    //~v03fR~
//*rc   :none                                                   //~v03fR~
//**************************************************************//~v03fR~
void filecmdlinedisp(PUCLIENTWE Ppcw,PUSCRD Ppsd)               //~v03fR~
{                                                               //~v03fR~
	UFLDE  *pfle;                                               //~v03fR~
	PUPANELC  ppc;                                              //~v03fI~
    int len;                                                    //~v03fR~
//******************                                            //~v03fR~
	ppc=Ppcw->UCWppc;                                           //~v03fI~
	len=Ppcw->UCWwidth;                                         //~v03fR~
	if (UCBITCHK(Ppcw->UCWflag,UCWFDRAW)                        //~v03fR~
	||  UCBITCHK(Ppsd->USDflag2,USDF2DRAW))                     //~v03fR~
	{                                                           //~v03fR~
		Ppsd->USDoff=0;		//write to from leftmost column     //~v03fR~
		Ppsd->USDlen=len;                                       //~v03fR~
		Ppsd->USDcell0len=0;				//no linenofld data //~v03fR~
		Ppsd->USDnattr0len=0;                                   //~v03fR~
//		memcpy(Ppsd->USDdata,Ppsd->USDbuffc,(UINT)len); //updated cmd line//~v730R~
		memcpy(Ppsd->USDdata,ppc->UPCline[CMDLINENO].UPLbuff,(UINT)len); //updated cmd line,copy from plbuff(vsplitshift setup)//~v730I~
    	memcpy(Ppsd->USDdbcs,ppc->UPCline[CMDLINENO].UPLdbcs,(UINT)len);//~v03fR~
    	if (UCBITCHK(Ppcw->UCWflag,UCWFCMDERR))                 //~v03fR~
    	{                                                       //~v03fR~
    		pfle=getuflde(Ppcw,CMDLINENO,0);                    //~v03fR~
    		Ppsd->USDnattr0len=(int)strlen(Ppsd->USDdata+pfle->UFLstart);//~v03fR~
    		Ppsd->USDnattr0off=pfle->UFLstart;	//use USDnattr0 //~v03fR~
    	}                                                       //~v03fR~
    	else                                                    //~v03fR~
    		if (UCBITCHK(ppc->UPCflag,UPCFSCROLLERR))           //~v03fR~
    		{                                                   //~v03fR~
    			pfle=getuflde(Ppcw,CMDLINENO,1);                //~v03fR~
    			if (!(Ppsd->USDnattr0len=(int)strlen(Ppsd->USDdata+pfle->UFLstart)))//~v03fR~
    				Ppsd->USDnattr0len=pfle->UFLend-pfle->UFLstart;//~v03fR~
    			Ppsd->USDnattr0off=pfle->UFLstart;              //~v03fR~
    		}                                                   //~v03fR~
    		else                                                //~v03fR~
    			Ppsd->USDnattr0len=0;                           //~v03fR~
#ifdef UTF8SUPPH                                                   //~va00I~
		pansetinputmode(Ppcw,Ppsd);                                //~v916R~//~va0xM~
		pansetcmdcodeattr(0,Ppcw,Ppsd,ppc);	//draw utf8 code       //~va00I~
#endif                                                             //~va00I~
    }                                                           //~v03fR~
    return;                                                     //~v03fR~
}//filecmdlinedisp                                              //~v03fR~
//**************************************************************   //~v11NI~
// filecolsdisp                                                    //~v11NI~
//*display column gauge                                            //~v11NI~
//*parm1:pcw                                                       //~v11NI~
//*parm2:psd                                                       //~v11NI~
//*parm3:1:fulldraw case,0:csr moved case                          //~v21qI~
//*rc   :none                                                      //~v11NI~
//**************************************************************   //~v11NI~
//void filecolsdisp(PUCLIENTWE Ppcw,PUSCRD Ppsd,int Pfullsw)       //~v69DR~
void filecolsdisp(PUCLIENTWE Ppcw,PUSCRD Ppsd,int Pfullsw,UCHAR Pprotattr,UCHAR Pprotattr_r)//~v69DI~
{                                                                  //~v11NI~
//static int Soldpos=0;                                            //~v72dR~
    int oldpos;                                                    //~v72dR~
	PUFILEC pfc;                                                   //~v11NI~
	PUFILEH pfh;                                                   //~v75EI~
    int len,linenosz,offs,len2,colsdatalen;                        //~v11NI~
    int ii,len3,csrx,drawsw;                                       //~v21qI~
    int bndsoffs1,bndsoffs2;                                       //~v75EI~
    UCHAR *pdata,*pdbcs,*colsdata,*colstype;                       //~v11NI~
    UCHAR *pc,*pdata0;                                             //~v21qI~
//******************                                               //~v11NI~
	pfc=Ppcw->UCWpfc;                                              //~v11NI~
	pfh=pfc->UFCpfh;                                               //~v75EI~
    linenosz=Ppcw->UCWlinenosz;                                    //~v11NI~
	colsdatalen=pfc->UFCcolsdatalen;                               //~v11NI~
	colsdata=pfc->UFCcolsdata;                                     //~v11NI~
	colstype=pfc->UFCcolstype;                                     //~v11NI~
	Ppsd->USDbuffc=0;		//id of cols line                      //~v11NR~
                                                                   //~v11NI~
//  UCBITON(Ppsd->USDflag2,USDF2DRAW);		//req dispaly          //~v21qI~
	UCBITON(Ppsd->USDflag2,USDF2PROTFHDR);	//2nd fld protected    //~v11NR~
    csrx=Ppcw->UCWrcsrx;                                           //~v21qI~
    pdata0=Ppsd->USDcell;                                          //~v21qI~
    drawsw=0;                                                      //~v21qI~
  if (Pfullsw)	//fulldraw case                                    //~v21qI~
  {                                                                //~v21qI~
	offs=pfc->UFCleft;                                             //~v11NI~
	len=max(0,min(Ppcw->UCWwidth-linenosz,colsdatalen-pfc->UFCleft));//~v11NR~
	len2=Ppcw->UCWwidth-linenosz-len;//len after data              //~v11NI~
//lineno column                                                    //~v11NI~
	pdbcs=Ppsd->USDdbcs;                                           //~v11NI~
//  pdata=Ppsd->USDdata;                                           //~v21qR~
    pdata=pdata0;                                                  //~v21qI~
	if (linenosz)                                                  //~v11NI~
    {                                                              //~v11NI~
		memset(pdbcs,0,(UINT)linenosz);//dbcsid                    //~v11NR~
		pdbcs+=linenosz;                                           //~v21qM~
//  	memset(pdata,' ',(UINT)linenosz-1);//dbcsid                //~v21qR~
//  	memcpy(pdata,colstype,strlen(colstype));                   //~v21qR~
//  	*(pdata+linenosz-1)='|';                                   //~v21qR~
//  	pdata+=linenosz;                                           //~v21qR~
        len3=(int)strlen(colstype);                                //~v40bR~
        for (pc=colstype,ii=0;ii<linenosz;ii++)                    //~v21qI~
        {                                                          //~v21qI~
        	if (ii<len3)                                           //~v21qI~
        		*pdata++=*pc++;                                    //~v21qI~
            else                                                   //~v21qI~
        		*pdata++=' ';                                      //~v21qI~
//          *pdata++=Sprotattr;                                    //~v69DR~
            *pdata++=Pprotattr;                                    //~v69DI~
        }                                                          //~v21qI~
		*(pdata-2)='|';                                            //~v21qI~
    }                                                              //~v11NI~
//*data edit                                                       //~v11NI~
	if (len)                                                       //~v11NI~
	{                                                              //~v11NI~
//  	memcpy(pdata,colsdata+offs,(UINT)len);//data               //~v21qR~
		memset(pdbcs,0,(UINT)len);			//dbcs id tbl          //~v11NI~
//		pdata+=len;                                                //~v21qR~
  		pdbcs+=len;                                                //~v11NI~
        for (pc=colsdata+offs,ii=0;ii<len;ii++)                    //~v21qI~
        {                                                          //~v21qI~
        	*pdata++=*pc++;                                        //~v21qI~
//          *pdata++=Sprotattr;                                    //~v69DR~
            *pdata++=Pprotattr;                                    //~v69DI~
        }                                                          //~v21qI~
	}//data exist                                                  //~v11NI~
	if (len2>0)		//after data                                   //~v11NI~
	{                                                              //~v11NI~
		memset(pdbcs,0,(UINT)len2);                                //~v11NI~
//  	*pdata++=0x1b;                                             //~v19kR~
//  	*pdata++=EOLID;                                            //~v217R~
//  	*pdata++=(UCHAR)Seolid;                                    //~v47dR~
    	*pdata++=(UCHAR)Gopteol2;                                  //~v47dI~
//      *pdata++=Sprotattr;                                        //~v69DR~
        *pdata++=Pprotattr;                                        //~v69DI~
		if (--len2>0)                                              //~v11NI~
//  		memset(pdata,' ',(UINT)len2);                          //~v21qR~
            for (ii=0;ii<len2;ii++)                                //~v21qI~
            {                                                      //~v21qI~
                *pdata++=' ';                                      //~v21qI~
//              *pdata++=Sprotattr;                                //~v69DR~
                *pdata++=Pprotattr;                                //~v69DI~
            }                                                      //~v21qI~
	}                                                              //~v11NI~
//*display boundary                                                //~v75EI~
	bndsoffs1=pfh->UFHbndscol1-1;                                  //~v75EI~
	bndsoffs2=pfh->UFHbndscol2;                                    //~v75ER~
    if (bndsoffs1>=0)   //left boundary specified                  //~v75EI~
    {                                                              //~v75EI~
        bndsoffs1-=offs;                                           //~v75EI~
        if (bndsoffs1>=0 && bndsoffs1<Ppcw->UCWwidth-linenosz)     //~v75EI~
        	*(pdata0+(linenosz+bndsoffs1)*2)=BNDS_LEFTID;          //~v75ER~
    }                                                              //~v75EI~
    if (bndsoffs2>0)                                               //~v75EI~
    {                                                              //~v75EI~
        bndsoffs2-=offs;                                           //~v75ER~
        bndsoffs2--;	//1 column before                          //~v75EI~
        if (bndsoffs2>=0 && bndsoffs2<Ppcw->UCWwidth-linenosz)     //~v75EI~
        	*(pdata0+(linenosz+bndsoffs2)*2)=BNDS_RIGHTID;         //~v75ER~
    }                                                              //~v75EI~
    drawsw=1;                                                      //~v21qI~
  }                                                                //~v21qI~
  else                                                             //~v21qI~
  {                                                                //~v21qI~
//  pc=pdata0+Soldpos+Soldpos+1;                                   //~v72dR~
    oldpos=pfc->UFCcolscsrpos;                                     //~v72dR~
    pc=pdata0+oldpos+oldpos+1;                                     //~v72dI~
//  if (*pc!=Sprotattr)                                            //~v69DR~
    if (*pc!=Pprotattr)                                            //~v69DI~
    {                                                              //~v21qI~
//  	*pc=Sprotattr;	//reset old pos                            //~v69DR~
    	*pc=Pprotattr;	//reset old pos                            //~v69DI~
	    drawsw=1;                                                  //~v21qI~
    }                                                              //~v21qI~
  }                                                                //~v21qI~
    if (CSRONFILELINE_COLS(Ppcw))                                  //~v21qR~
    {                                                              //~v21qI~
//      Soldpos=csrx;                                              //~v72dR~
        pfc->UFCcolscsrpos=oldpos=csrx;                            //~v72dI~
//  	pc=pdata0+Soldpos+Soldpos+1;                               //~v72dR~
    	pc=pdata0+oldpos+oldpos+1;                                 //~v72dI~
//  	if (*pc!=Sprotattr_r)                                      //~v69DR~
    	if (*pc!=Pprotattr_r)                                      //~v69DI~
        {                                                          //~v21qI~
//  		*pc=Sprotattr_r;                                       //~v69DR~
    		*pc=Pprotattr_r;                                       //~v69DI~
	    	drawsw=1;                                              //~v21qI~
        }                                                          //~v21qI~
    }                                                              //~v21qI~
    if (drawsw)                                                    //~v21qI~
		UCBITON(Ppsd->USDflag2,USDF2DRAW);		//req dispaly      //~v21qI~
//  Ppsd->USDlen=Ppcw->UCWwidth;                                   //~v21qR~
    Ppsd->USDlen=Ppcw->UCWwidth*2;                                 //~v21qI~
//*setup color                                                     //~v11NI~
//  Ppsd->USDflag=USDFCHARSTRATT;                                  //~v21qR~
    Ppsd->USDflag=USDFCELLSTR;    //all by cell                    //~v21qI~
    Ppsd->USDuvioo=0;	//no ligature/combine for guage line       //~vb4fI~
	Ppsd->USDoff=0;			//write to from leftmost column        //~v11NI~
	Ppsd->USDcell0len=0;		//no special cell data             //~v11NI~
	Ppsd->USDnattr0len=0;	//no additional attr                   //~v11NI~
	Ppsd->USDnattr0off=0;                                          //~v11NI~
//  Ppsd->USDnattr=Sprotattr;                                      //~v21qR~
    Ppsd->USDnattr=0;                                              //~v21qI~
    return;                                                        //~v11NI~
}//filecolsdisp                                                    //~v11NI~
//**************************************************************   //~v445I~
// filecolsprint                                                   //~v445I~
//*setup print cols line for xprint **                             //~v445I~
//*parm1:pcw                                                       //~v445I~
//*parm2:output area                                               //~v445I~
//*parm3:linenofld sz                                              //~v445I~
//*parm4:linesz                                                    //~v445I~
//*rc   :print len                                                 //~v445R~
//**************************************************************   //~v445I~
int filecolsprint(PUCLIENTWE Ppcw,UCHAR *Ppout,int Plinenosz,int Plinesz)//~v445R~
{                                                                  //~v445I~
	PUFILEC pfc;                                                   //~v445I~
    int   colsdatalen,len,linesz,linenosz;                         //~v445R~
    UCHAR *pout,*colsdata,*colstype;                               //~v445I~
//******************                                               //~v445I~
	pfc=Ppcw->UCWpfc;                                              //~v445I~
	colsdatalen=pfc->UFCcolsdatalen;                               //~v445I~
	colsdata=pfc->UFCcolsdata;                                     //~v445I~
	colstype=pfc->UFCcolstype;                                     //~v445I~
    pout=Ppout;                                                    //~v445I~
    linenosz=Plinenosz-1;                                          //~v445I~
    len=(int)strlen(colstype);                                     //~v445I~
    len=min(len,linenosz);                                         //~v445R~
	memset(pout,' ',(UINT)linenosz);//dbcsid                       //~v445I~
    memcpy(pout,colstype,(UINT)len);                               //~v445I~
    pout+=linenosz;                                                //~v445I~
    *pout++='|';                                                   //~v445R~
    linesz=Plinesz+Plinenosz-Ppcw->UCWlinenosz;	//diff with display wdth//~v445I~
    len=min(linesz,colsdatalen);                                   //~v445I~
    memcpy(pout,colsdata,(UINT)len);                               //~v45zR~
    *(pout+len++)='\n';                                            //~v445I~
    return Plinenosz+len;                                          //~v45kR~
}//filecolsprint                                                   //~v445I~
//****************************************************************
// vsplitshift
//*setup for file screen vsplit(hdr line column/cmd line scroll size)
//*parm1:PUCLIENTWE
//*rc   :none
//****************************************************************
void vsplitshift(PUCLIENTWE Ppcw)
{
static int Scmdpos=0,Scmdend;                                      //~v42zR~
static int Sscrolltlen,Sscrollhlen,Sscrolldlen;                 //~5423R~
    UFLDE *pflescrol,*pflecmd;	//scroll,cmd field              //~v03aI~
	int width,prevwidth,colsize,cmdend,prevcmdend;              //~v03aR~
//  int lenw;                                                      //~v730R~
	PUSCRD psd;
	UCHAR  *pc;
	UCHAR  *pcd;        //dbcs data ptr                            //~v45dI~
	PUPANELC  ppc;
	PUFILEC  pfc;
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iI~
    int resizesw=0;                                                //~v500R~
    int pfcresizesw;                                               //~v621I~
#endif                                                             //~v500R~
	int resetsw;                                                   //~v56rI~
	PUPANELL  upl;                                                 //~v730I~
//  PUPANELD ppd;                                                  //~v76ZR~
//******************
	UTRACEP("vsplitshift\n");                                      //~vamBI~
	pfc=Ppcw->UCWpfc;		//for csrpos disp                   //~4C31I~
	psd=Ppcw->UCWpsd;		//hdr line                          //~4C31I~
  	ppc=Ppcw->UCWppc;                                              //~v730I~
//  ppd=ppc->UPCppd;                                               //~v76ZR~
    if ((resetsw=UCBITCHK(pfc->UFCflag2,UFCF2PPCRESET))!=0)  //usdbuff reset done//~v56rI~
	    UCBITOFF(pfc->UFCflag2,UFCF2PPCRESET);  //usdbuff reset done//~v56rI~
    	                                                           //~v56rI~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iI~
	pfcresizesw=UCBITCHK(pfc->UFCflag2,UFCF2RESIZE);               //~v621I~
	UCBITOFF(pfc->UFCflag2,UFCF2RESIZE);                           //~v621I~
//  if (!Scmdpos || Sresizesw)                                     //~v621R~
    if (!Scmdpos || pfcresizesw)                                   //~v621I~
    {                                                              //~v500R~
//      resizesw=Sresizesw;                                        //~v621R~
        resizesw=pfcresizesw;                                      //~v621I~
//  	Sresizesw=0;	//set once at wakeup                       //~v621R~
//      resizesw=1;                                                //~v56iR~
#else                                                              //~v500R~
	if (!Scmdpos)		//first time any way                    //~5423I~
    {                                                           //~5423I~
#endif                                                             //~v500R~
		pflecmd=getuflde(Ppcw,CMDLINENO,0);	//cmd fld.          //~v03aR~
		pflescrol=getuflde(Ppcw,CMDLINENO,1);	//scroll fld    //~v03aR~
		Scmdpos=pflecmd->UFLstart;                              //~v03aR~
		Scmdend=pflecmd->UFLend;                                //~v03aR~
		Sscrolltlen=Gscrwidth-Scmdend;//scroll hdr/data field len//~5423R~
		Sscrollhlen=pflescrol->UFLstart-Scmdend;                //~v03aR~
		Sscrolldlen=pflescrol->UFLend-pflescrol->UFLstart;      //~v03aR~
    }                                                           //~4C31I~
//  activesw=(Ppcw->UCWsplitid==Gscrcurclient);	//current client id//~v03aR~
	width=Ppcw->UCWwidth;                                       //~5204I~
	prevwidth=pfc->UFCprevwidth;                                //~5423I~
//  if (width==prevwidth && !activesw)//vsplit width not changed//~v03aR~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iI~
  if (!resizesw)                                                   //~v56iI~
#endif                                                             //~v56iI~
   if (!resetsw) //usdbuff reset done                              //~v56rR~
    if (width==prevwidth)             //vsplit width not changed//~v03aI~
    {                                                              //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
		fileutf8vsplithdrattr(0,Ppcw,psd,pfc->UFCpfh,pfc->UFCcsrposdisp);//~va00I~
#endif                                                             //~va00I~
		return;                      //if act reset uflde       //~5423R~
    }                                                              //~va00I~
	pfc->UFCprevwidth=width;                                    //~5423I~
//*hdr column display
	pc=psd->USDbuffc;                                           //~4C31I~
	memcpy(psd->USDdata,pc,(UINT)Gscrwidth);
//  memcpy(psd->USDdbcs,ppd->UPDdbcs,(UINT)Gscrwidth);             //~v77kR~
    memcpy(psd->USDdbcs,ppc->UPCline[0].UPLdbcs,(UINT)Gscrwidth);  //~v77kR~
//  pfc->UFCcsrposdisp=Gscrwidth-COLUMNDISPPOS;	//colomn set pos   //~v51VR~
	if (width==Gscrwidth || Ppcw->UCWsplitid)	//client second //~5204R~
		colsize=COLUMNDISPPOS;
	else
		colsize=COLUMNDISPPOS-4;	//drop Rep/Ins
  	pfc->UFCcsrposdisp=width-colsize;	//colomn set pos           //~v51VI~
//  if (colsize<=width-FILENAMEPOS)                                //~v51VR~
    if (pfc->UFCcsrposdisp>FILENAMEPOS)	//space avail              //~v51VR~
	{
//  	pfc->UFCcsrposdisp=width-colsize;	//colomn set pos       //~v51VR~
//  	memcpy(psd->USDdata+pfc->UFCcsrposdisp,                    //~v76QR~
//  			pc+Gscrwidth-COLUMNDISPPOS,(UINT)colsize);         //~v51VR~
//  			pc+Gscrbuffwidth-COLUMNDISPPOS,(UINT)colsize);     //~v76QR~
    	memcpy(psd->USDdata+pfc->UFCcsrposdisp,pc+Gscrbuffwidth-COLUMNDISPPOS,(UINT)colsize);//~v76QR~
		pcd=psd->USDdbcs+pfc->UFCcsrposdisp;                       //~v45dI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	    xesub_cleardbcssplit(XESUBCDSO_RIGHT,psd->USDdata,psd->USDdbcs,pfc->UFCcsrposdisp,'.');//~va1cR~
#else                                                              //~va1cR~
        if (*pcd==DBCS2NDCHAR)                                     //~v45dI~
        {                                                          //~v76ZI~
			*(psd->USDdata+pfc->UFCcsrposdisp-1)='.';              //~v45dI~
            *(pcd-1)=0;                                            //~v76ZI~
        }                                                          //~v76ZI~
#endif                                                             //~va1cR~
        memset(pcd,0,(UINT)colsize);                               //~v76ZR~
#ifdef UTF8SUPPH                                                   //~va00I~
		fileutf8vsplithdrattr(FUVSHAO_CHNGWIDTH,Ppcw,psd,pfc->UFCpfh,pfc->UFCcsrposdisp);//~va00R~
#endif                                                             //~va00I~
	}
    else                                                           //~v51VI~
	    pfc->UFCcsrposdisp=0;	//id of no avail space for csr col display//~v51VI~
    UTRACED("vsplitshift data",psd->USDdata,width);                //~vamBI~
    UTRACED("vsplitshift dbcs",psd->USDdbcs,width);                //~vamBR~
    UTRACED("vsplitshift cell",psd->USDcell,width*2);              //~vamBR~
//*cmd line scroll display
	if ((cmdend=width-Sscrolltlen)>Scmdpos)	//scroll can display//~5204R~
	{                                                           //~5204I~
//      if (activesw)                                           //~v03aR~
//      {                                                       //~v03aR~
			pflecmd=getuflde(Ppcw,CMDLINENO,0);	//cmd fld.      //~v03aI~
			pflescrol=getuflde(Ppcw,CMDLINENO,1);	//scroll fld//~v03aI~
			pflecmd->UFLend=cmdend;				//save for next //~v03aR~
			pflescrol->UFLstart=cmdend+Sscrollhlen;             //~v03aR~
			pflescrol->UFLend=pflescrol->UFLstart+Sscrolldlen;  //~v03aR~
//      }                                                       //~v03aR~
	}                                                           //~5204I~
	else                                                        //~5204I~
	{                                                           //~5204I~
		pflecmd=getuflde(Ppcw,CMDLINENO,0);	//cmd fld.          //~v03aI~
		pflescrol=getuflde(Ppcw,CMDLINENO,1);	//scroll fld    //~v03aI~
		if (width<=Scmdpos)		//no input fld                  //~5204I~
		{                                                       //~5204I~
			cmdend=Scmdpos;                                     //~5204I~
//          if (activesw)                                       //~v03aR~
				pflecmd->UFLend=pflecmd->UFLstart;	//force len=0//~v03aR~
		}                                                       //~5204I~
		else	//cmd input only                                //~5204I~
		{                                                       //~5204I~
			cmdend=width;                                       //~5423R~
//          if (activesw)                                       //~v03aR~
				pflecmd->UFLend=width;                          //~v03aR~
		}                                                       //~5204I~
//      if (activesw)                                           //~v03aR~
//			pflescrol->UFLend=pflescrol->UFLstart;//len=0,protect input//~v03cR~
			pflescrol->UFLstart=cmdend+Sscrollhlen;             //~v03cI~
			pflescrol->UFLend=pflescrol->UFLstart+Sscrolldlen;  //~v03cI~
	}                                                           //~5204I~
	prevcmdend=pfc->UFCscrolldisp;                              //~5423I~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iI~
  if (!resizesw)                                                   //~v56iI~
#endif                                                             //~v56iI~
	if (cmdend==prevcmdend)		//scroll disp pos not changed   //~5204M~
		return;                                                 //~5204M~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iI~
	if (!prevcmdend||resizesw)//when resize,ppd_init is done       //~v56iI~
#else                                                              //~v56iI~
	if (!prevcmdend)                                            //~5423I~
#endif                                                             //~v56iI~
		prevcmdend=Scmdend;                                     //~5423I~
	pfc->UFCscrolldisp=cmdend;	                                //~5204M~
	if (cmdend==Scmdpos)		//scroll cannot display         //~5204M~
		return;                                                 //~5204M~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iI~
    if (resizesw)                                                  //~v500R~
      if (width==Gscrwidth)    //resize rtn already set,but cotinue process required for vsplit//~v56iR~
        return;         //pan_resize rest scroll field             //~v500R~
#endif                                                             //~v500R~
	psd++;
	pc=psd->USDbuffc;
  	upl=ppc->UPCline+CMDLINENO;                                    //~v730I~
	if (cmdend>prevcmdend)			//expanded
	{
		memmove(pc+cmdend,pc+prevcmdend,(UINT)Sscrolltlen);     //~5204R~
//  	memset(pc+prevcmdend,0,(UINT)(cmdend-prevcmdend));         //~v730R~
	}
	else
	{							//forward copy
		memcpy(pc+cmdend,pc+prevcmdend,(UINT)Sscrolltlen);      //~5204R~
//  	memset(pc+cmdend+Sscrolltlen,0,(UINT)(Gscrwidth-width));   //~v0hrR~
//  	lenw=Gscrwidth-(cmdend+Sscrolltlen);                       //~v730R~
//      if (lenw<0)                                                //~v730R~
//      	lenw=0;                                                //~v730R~
//  	memset(pc+cmdend+Sscrolltlen,0,(UINT)lenw);                //~v730R~
	}
    memcpy(pc,ppc->UPCcmddata,(UINT)cmdend); //(pc==USDbuffc==UPLbuff)//~v730R~
    memcpy(upl->UPLdbcs,ppc->UPCcmddbcs,(UINT)cmdend);             //~v730I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5sI~
    xesub_setdbcssplit(0,0/*plh*/,pc,upl->UPLdbcs,cmdend,'.');     //~va5sI~
#else                                                              //~va5sI~
    setdbcssplit(pc,upl->UPLdbcs,cmdend,'.');                      //~v730R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5sI~
//  ppc=Ppcw->UCWppc;                                              //~v730R~
	memset(ppc->UPCline[CMDLINENO].UPLdbcs+cmdend,0,
			(UINT)(Gscrwidth-cmdend));
	return;
}//vsplitshift
                                                                //~4C30I~
//****************************************************************
// filesetcsr
//*request set cursor to the field top of the line
//*parm1:pcw
//*parm2:plh
//*parm3:fldno
//*parm4:offset in the fld                                      //~5223I~
//*rc   :none
//****************************************************************
void filesetcsr(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,int Poffs)//~v020R~
{
	PUFILEC pfc;
//*****************
	pfc=Ppcw->UCWpfc;
	pfc->UFCcsrplh=Pplh;				//csr set line
	pfc->UFCcsrfldno=Pfldno;			//csr move to the  fld
	pfc->UFCcsroffs=Poffs;			//csr move to the  fld      //~5223I~
	UCBITON(Gprocstatus,GPROCSCSRSET);                          //~v020I~
	return;
}//filesetcsr
                                                                //~5118I~
//****************************************************************//~5118I~
// filesetdraw                                                  //~5118I~
//*set scr draw flag of the file(multi scr display file)        //~5118I~
//*parm1:pcw                                                    //~5118I~
//*rc   :none                                                   //~5118I~
//****************************************************************//~5118I~
void filesetmultdraw(PUCLIENTWE Ppcw)                           //~5118R~
{                                                               //~5118I~
	PUFILEH   pfh;                                              //~5118R~
	PUCLIENTWE pcw;                                             //~5118I~
//*****************                                             //~5118I~
	pfh=((PUFILEC)Ppcw->UCWpfc)->UFCpfh;                        //~5118I~
	if (pcw=pfh->UFHeditpcw,pcw)                                //~5118I~
		UCBITON(pcw->UCWflag,UCWFDRAW);	//scr draw              //~5118I~
	if (pcw=pfh->UFHbrowsepcw[0],pcw)                           //~5118I~
		UCBITON(pcw->UCWflag,UCWFDRAW);	//scr draw              //~5118I~
	if (pcw=pfh->UFHbrowsepcw[1],pcw)                           //~5118I~
		UCBITON(pcw->UCWflag,UCWFDRAW);	//scr draw              //~5118I~
	return;                                                     //~5118I~
}//filesemultdraw                                               //~5118R~
                                                                   //~v0hfI~
//**************************************************************** //~v0hfI~
// filesetdrawstart                                                //~v0hfI~
//*set redraw start plh                                            //~v0hfI~
//*parm1:pcw                                                       //~v0hfI~
//*parm2:plh                                                       //~v0hfI~
//*parm3:option                                                    //~v0hfR~
//*			x01 other ufc of same file is also set                 //~v0hfI~
//*			x02 redraw by line isrt                                //~v0hfI~
//*rc   :none                                                      //~v0hfI~
//**************************************************************** //~v0hfI~
void filesetdrawstart(PUCLIENTWE Ppcw,PULINEH Pplh,int Popt)       //~v0hfR~
{                                                                  //~v0hfI~
	PUFILEC pfc;                                                   //~v0hfI~
	PUFILEH pfh;                                                   //~v0hfI~
	PUCLIENTWE pcw;                                                //~v0hfI~
    int ii;                                                        //~v0hfI~
//*****************                                                //~v0hfI~
	pcw=Ppcw;                                                      //~v0hfI~
    for (ii=0;ii<2;ii++)                                           //~v0hfI~
    {                                                              //~v0hfI~
		pfc=pcw->UCWpfc;                                           //~v0hfI~
        if (UCBITCHK(pcw->UCWflag,UCWFDRAW)  //fulldraw            //~v0hfR~
        ||  pfc->UFCdrawplh)    //multiple set req                 //~v0hfI~
        {                                                          //~v0hfI~
            UCBITON(pcw->UCWflag,UCWFDRAW); //scr draw             //~v0hfI~
            pfc->UFCdrawplh=0;   //no more need                    //~v0hfI~
            UCBITOFF(pfc->UFCflag,UFCFISRTDRAW);                   //~v0hfI~
        }                                                          //~v0hfI~
        else                                                       //~v0hfI~
        {                                                          //~v0hfI~
            pfc->UFCdrawplh=Pplh;           //request redraw after this line//~v0hfR~
            if (Popt & DRAW_ISRT)                                  //~v0hfR~
                UCBITON(pfc->UFCflag,UFCFISRTDRAW);                //~v0hfR~
        }                                                          //~v0hfI~
        if (ii==1)                                                 //~v0hfI~
        	break;                                                 //~v0hfI~
	    if (!(Popt & DRAW_MULT))	//no multi req                 //~v0hfI~
        	break;                                                 //~v0hfI~
    	pcw=scrgetcw(-1);			//other client                 //~v0hfI~
        if (!pcw)					//no other client              //~v0hfI~
        	break;                                                 //~v0hfI~
		pfh=pfc->UFCpfh;                                           //~v0hfI~
		if (pcw!=pfh->UFHbrowsepcw[0]                              //~v0hfI~
		&&  pcw!=pfh->UFHbrowsepcw[1])	//browse active on another screen//~v0hfI~
        	break;                                                 //~v0hfI~
    }//loop twice                                                  //~v0hfI~
	return;                                                        //~v0hfI~
}//filesetdrawstart                                                //~v0hfI~
                                                                   //~v0hfI~
//**************************************************************** //~v0k0I~
// filesetfulldraw                                                 //~v0k0I~
//*set full draw sw(not for dir list but edit/browse)              //~v0k0I~
//*parm1:pcw                                                       //~v0k0I~
//*rc   :none                                                      //~v0k0I~
//**************************************************************** //~v0k0I~
void filesetfulldraw(PUCLIENTWE Ppcw)                              //~v0k0I~
{                                                                  //~v0k0I~
	PUFILEC pfc;                                                   //~v0k0I~
//*****************                                                //~v0k0I~
    UCBITON(Ppcw->UCWflag,UCWFDRAW); //scr draw                    //~v0k0R~
	pfc=Ppcw->UCWpfc;                                              //~v0k0I~
    pfc->UFCdrawplh=0;   //no more need                            //~v0k0I~
    UCBITOFF(pfc->UFCflag,UFCFISRTDRAW);                           //~v0k0I~
	return;                                                        //~v0k0I~
}//filesetfulldraw                                                 //~v0k0I~
#ifdef UTF8SUPPH                                                   //~va00I~
//***************************************************************************//~v91yI~//~va00I~
//*fill hdr cell attr                                              //~v91yI~//~va00I~
//***************************************************************************//~v91yI~//~va00I~
int fileutf8resethdrattr(PUCLIENTWE Ppcw,PUSCRD Ppsd,PUFILEH Ppfh)  //~v91yR~//~va00R~
{                                                                  //~v91yI~//~va00I~
    int ii,len;                                                    //~v91yI~//~va00I~
    char *pattr,*pattr0,attr0;                         //~v91yR~   //~va00R~
//*****************                                                //~v91yI~//~va00I~
   	pattr0=Ppsd->USDcell+1;                                        //~v91ZI~//~va00R~
	if (Ppcw==scrgetcw(0))	//actve client                         //~v91yI~//~va00I~
    	attr0=Gattrtbl[COLOR_TITLE];                               //~v91yI~//~va00R~
    else                                                           //~v91yI~//~va00I~
    	attr0=Gattrtbl[COLOR_FRAME];                               //~v91yI~//~va00R~
    len=Ppcw->UCWwidth;                                            //~v91yI~//~va00I~
    for (pattr=pattr0,ii=0;ii<len;ii++)     //char+attr//~v91yI~   //~va00R~
    {                                                              //~va00I~
        *pattr++=attr0;                                        //~v91yI~//~va00I~
        pattr++;                                                   //~va00I~
    }                                                              //~va00I~
    return 0;                                                      //~v91yI~//~va00I~
}//fileutf8resethdrattr                                            //~va00R~
//**************************************************************** //~va1BM~
// setcodetype from cmdbuff codetype(save as filenamelist registration)//~va1BM~
// rc:0 set lcname from cmdbuff,1:by getlocalepathname,UALLOC_FAILED//~va1CR~
//**************************************************************** //~va1BM~
int fileutf8setfilenamecodetype(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)//~va1BI~
{                                                                  //~va1BM~
	char *pc,*pct,*plc,*pu8;                                       //~va1BI~
//  int allocsz,lenlc,rc=0;                                        //~va1CR~//~vaf9R~
    int allocsz,lenlc=0,rc=0;                                      //~vaf9I~
    int lenu8;                                                     //~va1BI~
//  char wkfpathlc[_MAX_PATH*UTF8_F2LMAXRATE];                     //~va1BI~//~vav9R~
//  char wkfpathct[_MAX_PATH*UTF8_F2LMAXRATE];                     //~va1BI~//~vav9R~
    char wkfpathlc[_MAX_PATHF2L];                                  //~vav9I~
    char wkfpathct[_MAX_PATHF2L];                                  //~vav9I~
    int opt;                                                       //~vagEI~
//#ifdef LNX                                                         //~vau7I~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)     //always ddfmt         //~vavaI~
    int lendd=0;                                                   //~vauaR~
    char wkdddata[_MAX_PATH*2];                                    //~vau7I~
    char wkdddbcs[_MAX_PATH*2];                                    //~vau7I~
    char wkddct[_MAX_PATH*2];                                      //~vau7I~
#endif                                                             //~vau7I~
#ifdef W32UNICODE                                                  //~vavcI~
    char wkfpathlc2[_MAX_PATH];                                    //~vavcR~
#endif                                                             //~vavcI~
    int pathlen;                                                   //~vb2hI~
//*****************                                                //~va1BM~
    UTRACEP("%s:opt=%x\n",UTT,Popt);                               //~vb2kI~
  if (UCBITCHK(Ppfh->UFHflag,UFHFWORKDIRFILE))                     //~va5sR~
    pu8=Ppfh->UFHalias;                                            //~va5sR~
  else                                                             //~va5sI~
    pu8=Ppfh->UFHfilename;                                         //~va1BI~
//  lenu8=strlen(pu8);                                             //~va1BI~//~vb2eR~
    lenu8=(int)strlen(pu8);                                        //~vb2eI~
#ifdef LNX                                                         //~vb2eI~
    if (UCBITCHK(Ppfh->UFHflag14,UFHF14MOUNTU8CV))	//locale translated to utf8 by mount option chk//~vb2eI~
    {                                                              //~vb2eI~
    	rc=1;	//not on Gcmdbuff,do getlocalepathname             //~vb2eI~
        UTRACEP("%s:F14MOUNTU8CV\n",UTT);                          //~vb2eI~
    }                                                              //~vb2eI~
    else                                                           //~vb2eI~
#endif                                                             //~vb2eI~
    if (!pan300stackchkcmdbuff(0,pu8))	//locale name remains on cmd buff//~va1BI~
    	rc=1;                                                      //~va1CR~
    else                                                           //~va1CI~
    {                                                              //~va1CI~
//  	lenlc=pan300stacksetctfromcmdbuffsub(0,pu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc));//~vaubR~
//#ifdef LNX                                                         //~vaubI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)     //always ddfmt         //~vavaI~
    	lenlc=pan300stacksetctfromcmdbuffsub(0,pu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),wkdddata,wkdddbcs,wkddct,sizeof(wkdddata),&lendd);//~vaubR~
#else                                                              //~vaubI~
    	lenlc=pan300stacksetctfromcmdbuffsub(0,pu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),NULL,NULL,NULL,0,NULL);//~vaubI~
#endif                                                             //~vaubI~
    	if (!lenlc)                                                //~va1CR~
        	rc=1;                                                  //~va1CI~
    }                                                              //~va1CI~
    if (rc==1)                                                     //~va1CI~
    {                                                              //~vagEI~
    	opt=0;                                                     //~vagEI~
        if (UCBITCHK(Ppfh->UFHflag13,UFHF13SELECTFNU8)) //utf8 filename on dirlist//~vauAR~
//      	opt|=XEUTFGLPNO_FNU8;	//select utf8 for filename encoding if both utf8 and locale is valid//~vauJR~
        	opt|=XEUTFGLPNO_FNU8MEMB;	//select utf8 for member encoding if both utf8 and locale is valid//~vauJI~
        else                                                       //~vauAI~
        if (UCBITCHK(Ppfh->UFHflag13,UFHF13SELECTFNLC))            //~vauAR~
//        	opt|=XEUTFGLPNO_FNLC;	//select utf8 for filename encoding if both utf8 and locale is valid//~vauJR~
          	opt|=XEUTFGLPNO_FNLCMEMB;	//select utf8 for membername encoding if both utf8 and locale is valid//~vauJI~
    	if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNU8))                  //~vagER~
        {                                                          //~vb2eI~
        	opt|=XEUTFGLPNO_FNU8;	//select utf8 for filename encoding if both utf8 and locale is valid//~vagEI~
	        UTRACEP("%s:F12FNU8\n",UTT);                           //~vb2eI~
        }                                                          //~vb2eI~
        else                                                       //~vagEI~
    	if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNLC))                  //~vagER~
        	opt|=XEUTFGLPNO_FNLC;	//select localecode for filename encoding if both utf8 and locale is valid//~vagEI~
//  	xeutf_getlocalepathname(0,pu8,lenu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),&lenlc);//~va1CI~//~vagER~
//  	xeutf_getlocalepathname(opt,pu8,lenu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),&lenlc);//~vauaR~
//#ifdef LNX                                                         //~vauaI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)     //always ddfmt         //~vavaI~
        opt|=XEUTFGLPNO_LCWIDTHBYDDWIDTH;	//rep by "?" when lcwidth!=ddwidth for ddfmt field//~vaubI~
    #ifdef W32UNICODE                                              //~vavcI~
//FIXME flag was set?:FIXED                                              //~vavcI~//~vavGR~
        if (FILEISREMOTE(Ppfh))                                    //~vavcI~
        	opt|=XEUTFGLPNO_REMOTE;                                //~vavcI~
        opt|=XEUTFGLPNO_ALLOWSUBCH; //allow rep to subch           //~vavGI~
    #else                                                          //~vb2mI~
        opt|=XEUTFGLPNO_ERRREPLC; //rep l2f err by '.'             //~vb2kR~//~vb2mM~
    #endif                                                         //~vavcI~
    	xeutf_getlocalepathname(opt,pu8,lenu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),&lenlc,wkdddata,wkdddbcs,wkddct,sizeof(wkdddata),&lendd);//~vauaI~
#else                                                              //~vauaI~
    	xeutf_getlocalepathname(opt,pu8,lenu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),&lenlc,NULL/*dddata*/,NULL/*dddbcs*/,NULL/*ddcode*/,0/*ddbuffsz*/,NULL/*pddlen*/);//~vauaI~
#endif                                                             //~vauaI~
    }                                                              //~vagEI~
#ifdef W32UNICODE                                                  //~vavcI~
	if (memchr(wkfpathlc,UD_NOTLC,lenlc))                          //~vavcR~
    {                                                              //~vavcI~
		fsubw_stripUDCT(0,wkfpathlc,lenlc,wkfpathlc2,sizeof(wkfpathlc2),wkfpathct,sizeof(wkfpathct),&lenlc);//~vavcR~//~vavrR~
        memcpy(wkfpathlc,wkfpathlc2,lenlc);                        //~vavcI~
    }                                                              //~vavcI~
#endif                                                             //~vavcI~
	allocsz=lenlc+lenlc+1;                                         //~va1BI~
//  pc=umalloc(allocsz);                                           //~va1BM~//~vb2eR~
    pc=umalloc((size_t)allocsz);                                   //~vb2eI~
    UALLOCCHK(pc,UALLOC_FAILED);                                   //~va1BM~
    pct=pc;                                                        //~va1BM~
    plc=pc+lenlc;                                                  //~va1BR~
    memcpy(pct,wkfpathct,(UINT)lenlc);                             //~va1BR~
    UmemcpyZ(plc,wkfpathlc,(UINT)lenlc);                           //~va1BR~
    pathlen=PATHLEN(plc);                                          //~vb2hR~
    UCBITOFF(Ppfh->UFHflag14,UFHF14FN_ENCODED_UTF8);               //~vb2hI~
    if (pathlen>0 && lenlc>pathlen)                                //~vb2hI~
    {                                                              //~vb2hI~
        if (memchr(pct+pathlen,XEUTFCT_UTF8,(size_t)(lenlc-pathlen)))	//utf8 encoded filename(not path)//~vb2hR~
        	UCBITON(Ppfh->UFHflag14,UFHF14FN_ENCODED_UTF8);        //~vb2hI~
    }                                                              //~vb2hI~
	filesetlocaleid_filename(0,Ppfh);                              //~vb2hI~
    Ppfh->UFHfilenamecodetype=pct; // free addr                    //~va1BM~
    Ppfh->UFHfilenamebylc=plc;                                     //~va1BM~
    Ppfh->UFHfilenamebylclen=lenlc;                                //~va1BR~
//#ifdef LNX                                                         //~vau7I~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)     //always ddfmt         //~vavaI~
//	xeutfcvlf2ddAdjust(0,pu8,lenu8,pct,lenlc,wkdddata,wkdddbcs,wkddct,sizeof(wkdddbcs),&lendd);//~vauaR~
    Ppfh->UFHfilenameddlen=lendd;                                  //~vau7I~
  if (lendd)                                                       //~vauaM~
  {                                                                //~vauaM~
	allocsz=lendd*3+1;                                             //~vau7I~
//  pc=umalloc(allocsz);                                           //~vau7I~//~vb2eR~
    pc=umalloc((size_t)allocsz);                                   //~vb2eI~
    UALLOCCHK(pc,UALLOC_FAILED);                                   //~vau7I~
#ifdef W32UNICODE                                                  //~vavtI~
   if (utfmemchrDD(wkdddata,wkdddbcs,lendd,UD_NOTLC))              //~vavtI~
   {                                                               //~vavtI~
    Ppfh->UFHfilenamedddata=pc; // free addr                       //~vavtI~
    pc+=lendd;                                                     //~vavtI~
    Ppfh->UFHfilenamedddbcs=pc;                                    //~vavtI~
    pc+=lendd;                                                     //~vavtI~
    Ppfh->UFHfilenameddct=pc;                                      //~vavtI~
	ufilecvUDD2DD(0,wkdddata,wkdddbcs,wkddct,lendd,Ppfh->UFHfilenamedddata,Ppfh->UFHfilenamedddbcs,Ppfh->UFHfilenameddct,lendd/*buffsz*/,&lendd);//~vavtR~
    Ppfh->UFHfilenameddlen=lendd;                                  //~vavtI~
    UTRACED("out data",Ppfh->UFHfilenamedddata,lendd);             //~vavtR~
    UTRACED("out dbcs",Ppfh->UFHfilenamedddbcs,lendd);             //~vavtR~
    UTRACED("out ct  ",Ppfh->UFHfilenameddct  ,lendd);             //~vavtR~
   }                                                               //~vavtI~
   else                                                            //~vavtI~
#endif                                                             //~vavGM~
   {                                                               //~vavtI~
    Ppfh->UFHfilenamedddata=pc; // free addr                       //~vau7I~
//  memcpy(pc,wkdddata,lendd);                                     //~vau7I~//~vb2eR~
    memcpy(pc,wkdddata,(size_t)lendd);                             //~vb2eI~
    UTRACED("xeutf8setfilenamecodetype data",pc,lendd);            //~vau7I~
    pc+=lendd;                                                     //~vau7I~
    Ppfh->UFHfilenamedddbcs=pc;                                    //~vau7I~
//  memcpy(pc,wkdddbcs,lendd);                                     //~vau7I~//~vb2eR~
    memcpy(pc,wkdddbcs,(size_t)lendd);                             //~vb2eI~
    UTRACED("xeutf8setfilenamecodetype dbcs",pc,lendd);            //~vau7I~
    pc+=lendd;                                                     //~vau7I~
    Ppfh->UFHfilenameddct=pc;                                      //~vau7I~
//  memcpy(pc,wkddct,lendd);                                       //~vau7I~//~vb2eR~
    memcpy(pc,wkddct,(size_t)lendd);                               //~vb2eI~
    UTRACED("xeutf8setfilenamecodetype ct",pc,lendd);              //~vau7I~
   }                                                               //~vavtI~
  }                                                                //~vauaI~
#endif                                                             //~vau7I~
    return rc;                                                     //~va1CR~
}//fileutf8setfilenamecodetype                                     //~va1BM~
#ifdef W32UNICODE                                                  //~vavaI~
//**************************************************************** //~vavaI~
//ud string to dd str,update ct                                    //~vavaI~
//**************************************************************** //~vavaI~
int filehdrnameUD2DD(int Popt,PUFILEH Ppfh,char *Puddata,char *Puddbcs,int Pudlen,char *Pdddata,char *Pdddbcs,int Pbuffsz,int *Ppddlen)//~vavaR~
{                                                                  //~vavaI~
   	int rc,ddlen,lenlc,buffsz,ctlen;                               //~vavaR~
   	char *pct;                                                     //~vavaR~
    char wkct[_MAX_PATH];                                          //~vavaI~
//*****************                                                //~vavaI~
    pct=Ppfh->UFHhdrnameattr;                                      //~vavaR~
    lenlc=Ppfh->UFHhdrnamewidth;                                   //~vavaI~
    ctlen=min(lenlc,Pudlen);                                       //~vavaI~
	buffsz=min(sizeof(wkct),Pbuffsz);                              //~vavaI~
	rc=ufilecvUDD2DD(0,Puddata,Puddbcs,pct,ctlen,Pdddata,Pdddbcs,wkct,buffsz,&ddlen);//~vavaR~
    if (rc)	//subchar utf8                                         //~vavaI~
    	memcpy(pct,wkct,ddlen);                                    //~vavaI~
    Ppfh->UFHhdrnamewidth=ddlen;                                   //~vavaI~
    *Ppddlen=ddlen;                                                //~vavaI~
    return rc;                                                     //~vavaI~
}//filehdrnameUD2DD                                                //~vavaI~
#endif //W32UNICODE                                                //~vavaI~
//**************************************************************** //~v91yI~//~va00I~
//fileutf8inithdrattr                                                  //~v91yI~//~va00R~
//conv to utf8 to locale for hdrline                               //~va00I~
//**************************************************************** //~v91yI~//~va00I~
int fileutf8inithdrattr(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PUSCRD Ppsd,char *Phdr,int *Pphdrlen)//~va00R~
{                                                                  //~v91yI~//~va00I~
	int lenlc,tailsz,opt;                                          //~va00R~
    char *pc,wkhdrfnmbylocale[MAXPARMSZ],wkcodetbl[MAXPARMSZ];     //~va00R~
    int utf8sw,offs;                                               //~va1BR~
    int lenu8;                                                     //~va5sI~
    char *pu8;                                                     //~va5sI~
//#ifdef W32UNICODE                                                //~vavaR~
//    char wkdddata[MAXPARMSZ],wkddct[MAXPARMSZ],wkdddbcs[MAXPARMSZ];//~vavaR~
//#endif                                                           //~vavaR~
//*****************************                                    //~va00I~
    UTRACEP("%s: opt=%x\n",UTT,Popt);                              //~vb2kI~
	tailsz=*Pphdrlen;                                              //~va00I~
	UFREECLEARIFNZ(Ppfh->UFHhdrnameattr);                          //~va00R~
    Ppfh->UFHhdrnamewidth=0; //codetbl length                      //~va00I~
	opt=XEUTFGLPNO_TAIL|(tailsz<<8);	//trailing ascii data length is on parm//~va00R~
//  if (xeutf_getlocalepathname(opt,Phdr,0/*len*/,wkhdrfnmbylocale,wkcodetbl,sizeof(wkhdrfnmbylocale),&lenlc)  & XEUTFGU8MRC_UTF8)//~va00R~//~va1BR~
    if (!Ppfh->UFHfilenamebylclen)  //already set by cmdbuff       //~va1BI~
    {                                                              //~va1BI~
		if (fileutf8setfilenamecodetype(0,Ppcw,Ppfh)>1)            //~va1CR~
		    Ppfh->UFHfilenamebylclen=-1;  //err id                 //~va1BI~
    }                                                              //~va1BI~
    if (Ppfh->UFHfilenamebylc)  //already set by cmdbuff           //~va1BI~
    {                                                              //~va1BI~
//#ifdef LNX     //always ddfmt                                      //~vau7I~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)     //always ddfmt         //~vavaI~
    	lenlc=Ppfh->UFHfilenameddlen;                              //~vau7I~
      if (lenlc)                                                   //~vauaI~
      {                                                            //~vauaI~
        memcpy(wkhdrfnmbylocale,Ppfh->UFHfilenamedddata,(UINT)(lenlc));	//with strz//~vau7I~
        memcpy(wkcodetbl,Ppfh->UFHfilenameddct,(UINT)lenlc);       //~vau7I~
      }                                                            //~vauaI~
      else                                                         //~vauaI~
#endif                                                             //~vauaM~
      {                                                            //~vauaI~
    	lenlc=Ppfh->UFHfilenamebylclen;                            //~va1BI~
        memcpy(wkhdrfnmbylocale,Ppfh->UFHfilenamebylc,(UINT)(lenlc+1));	//with strz//~va1BI~
        memcpy(wkcodetbl,Ppfh->UFHfilenamecodetype,(UINT)lenlc);   //~va1BI~
      }                                                            //~vauaI~
//      offs=strlen(Phdr)-tailsz;                                  //~va1BI~//~vb2eR~
        offs=(int)strlen(Phdr)-tailsz;                             //~vb2eI~
        memcpy(wkhdrfnmbylocale+lenlc,Phdr+offs,(UINT)tailsz);     //~va1BI~
        memset(wkcodetbl+lenlc,0,(UINT)tailsz);                    //~va1BI~
        lenlc+=tailsz;                                             //~va1BI~
    	utf8sw=1;                                                  //~va1BI~
    }                                                              //~va1BI~
    else                                                           //~va1BI~
    {                                                              //~vagEI~
    	if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNU8))                  //~vagER~
        	opt|=XEUTFGLPNO_FNU8;	//select utf8 for filename encoding if both utf8 and locale is valid//~vagEI~
        else                                                       //~vagEI~
    	if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNLC))                  //~vagER~
        	opt|=XEUTFGLPNO_FNLC;	//select localecode for filename encoding if both utf8 and locale is valid//~vagEI~
#ifdef W32UNICODE                                                  //~vavcI~
//FIXME flag was set?:FIXED                                              //~vavcI~//~vavGR~
        if (FILEISREMOTE(Ppfh))                                    //~vavcI~
        	opt|=XEUTFGLPNO_REMOTE;                                //~vavcI~
#endif                                                             //~vavcI~
#ifdef LNX                                                         //~vb2mI~
        opt|=XEUTFGLPNO_ERRREPLC; //rep l2f err by '.'             //~vb2kI~
#endif                                                             //~vb2mI~
//  	utf8sw=(xeutf_getlocalepathname(opt,Phdr,0/*len*/,wkhdrfnmbylocale,wkcodetbl,sizeof(wkhdrfnmbylocale),&lenlc) & XEUTFGU8MRC_UTF8);//~vauaR~
    	utf8sw=(xeutf_getlocalepathname(opt,Phdr,0/*len*/,wkhdrfnmbylocale,wkcodetbl,sizeof(wkhdrfnmbylocale),&lenlc,NULL/*dddata*/,NULL/*dddbcs*/,NULL/*ddcode*/,0/*ddbuffsz*/,NULL/*pddlen*/) & XEUTFGU8MRC_UTF8);//~vauaI~
    }                                                              //~vagEI~
//  Ppsd->USDuvioo=UVIOO_FORCELIGATURE|UVIOO_COMBINE;	//hdr,no csrpos//~vb4fI~
    Ppsd->USDuvioo=UVIOO_COMBINE;	//hdr,no csrpos                //~vb4fI~
//#ifdef LNX     //always ddfmt                                    //~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpI~
    if (utf8sw) //always                                           //~vau7I~
#else                                                              //~vau7I~
//  if (utf8sw)                                                    //~va1BI~//~va5sR~
    if (utf8sw && memchr(wkcodetbl,XEUTFCT_UTF8,lenlc))	//alias(such as ::cb) has no utf8 data;it should be shift codetable//~va5sI~
#endif                                                             //~vau7I~
    {                                                              //~va00R~
//#ifdef W32UNICODE                                                //~vavaR~
//        if (filehdrnameUD2DD(0,Ppfh,wkcodetbl,wkdddata,wkdddbcs,wkddct,sizeof(wkddct),&lenlc))  //contains UD str//~vavaR~
//            memcpy(wkcodetbl,wkddct,lenlc);                      //~vavaR~
//#endif                                                           //~vavaR~
//      UmemcpyZ(Phdr,wkhdrfnmbylocale,(UINT)lenlc);               //~va00R~//~va5sR~
//      pc=umalloc(lenlc);                                         //~va00R~//~va5sR~
//      lenu8=strlen(Phdr);                                        //~va5sI~//~vb2eR~
        lenu8=(int)strlen(Phdr);                                   //~vb2eI~
//      pc=umalloc(lenlc+lenu8+1);                                 //~va5sI~//~vb2eR~
        pc=umalloc((size_t)(lenlc+lenu8+1));                       //~vb2eI~
        UALLOCCHK(pc,UALLOC_FAILED);                               //~va00R~
        pu8=pc+lenlc;                                              //~va5sI~
        memcpy(pc,wkcodetbl,(UINT)lenlc);                          //~va00R~
	    memcpy(pu8,Phdr,(UINT)lenu8+1);	//save before f2l          //~va5sR~
	    Ppfh->UFHhdrnamebyu8=pu8;                                  //~va5sR~
        UmemcpyZ(Phdr,wkhdrfnmbylocale,(UINT)lenlc);               //~va5sI~
        Ppfh->UFHhdrnameattr=pc;                                   //~va00R~
        Ppfh->UFHhdrnamewidth=lenlc; //codetbl length              //~va00R~
        Ppsd->USDflag=USDFCELLSTR3;  //SDdata and SDcell(USHORT attr)~va00I~//~va00R~
        UTRACED("filename hdr u8",pu8,lenu8);                      //~vau7I~
        UTRACED("filename hdr dddata",Phdr,lenlc);                 //~vau7R~
        UTRACED("filename hdr ct",Ppfh->UFHhdrnameattr,lenlc);     //~vau7R~
    }                                                              //~va00R~
    else                                                           //~va00R~
    {                                                              //~va00R~
        Ppsd->USDflag=USDFCHARSTRATT;                              //~va00R~
        Ppsd->USDuvioo=UVIOO_COMBINE;	//hdr,no csrpos            //~vb4fI~
        lenlc=0;                                                   //~va00R~
    }                                                              //~va00R~
    *Pphdrlen=lenlc;                                               //~va00I~
	xeutf_savefnmforerrmsg(0,Ppcw,Ppfh);                           //~va1CR~
    UTRACEP("fileutf8inithdrattr utf8sw=%d,USDflag=%x\n",utf8sw,Ppsd->USDflag);//~vamBR~
    return 0;                                                      //~va00I~
}//fileutf8inithdrattr                                             //~va00R~
//#ifdef AAA //not used                                              //~vau4I~//~vavaR~
////**************************************************************** //~va5sI~//~vavaR~
////filehdrlf2dd                                                     //~va5sI~//~vavaR~
////conv to mixed string to dd fmt for filename hdr line             //~va5sI~//~vavaR~
////output to UPLbuff(=USDbuffc)/UPLdbcs                             //~vamBI~//~vavaR~
////**************************************************************** //~va5sI~//~vavaR~
//int filehdrlf2dd(int Popt,PUFILEH Ppfh,PUPANELC Pppc,int Phdroffs,int Pfnmlcoffs,int Pfnmlclen)//~va5sR~//~vavaR~
//{                                                                  //~va5sI~//~vavaR~
//    UCHAR *pct,*pu8,*pdata,*pdbcs,*pdddbcs,*pdddata;               //~va5sR~//~vavaR~
//    int outlen,fldposs,u8len,lclen,fldw;                           //~va5sR~//~vavaR~
////*****************************                                    //~va5sI~//~vavaR~
//    UTRACEP("filehdrlf2dd opt=%x\n",Popt);                         //~vamBI~//~vavaR~
//    pct=Ppfh->UFHhdrnameattr;   //codetype tbl was setup           //~va5sM~//~vavaR~
//    if (!pct)                                                      //~va5sR~//~vavaR~
//        return 0;                                                  //~va5sI~//~vavaR~
//    pdbcs=Pppc->UPCline[0].UPLdbcs;                                //~va5sI~//~vavaR~
//    pdata=Pppc->UPCline[0].UPLbuff;                                //~va5sI~//~vavaR~
//    lclen=Ppfh->UFHhdrnamewidth; //codetbl length                  //~va5sM~//~vavaR~
//    pu8=Ppfh->UFHhdrnamebyu8;   //mixed str,saved at fileutf8inithdrattr//~va5sM~//~vavaR~
//    fldposs=Phdroffs;                                              //~va5sI~//~vavaR~
//    pdata+=fldposs;                                                //~va5sI~//~vavaR~
//    pdbcs+=fldposs;                                                //~va5sI~//~vavaR~
//    u8len=(int)strlen(pu8);                                        //~va5sI~//~vavaR~
//    fldw=Pfnmlclen;                                                //~va5sR~//~vavaR~
//    pu8+=Pfnmlcoffs;                                               //~va5sI~//~vavaR~
//    pct+=Pfnmlcoffs;                                               //~va5sI~//~vavaR~
//    u8len-=Pfnmlcoffs;                                             //~va5sI~//~vavaR~
//    lclen-=Pfnmlcoffs;                                             //~va5sI~//~vavaR~
//    if (xeutfcvlf2dd(0,pu8,u8len,0/*pdbcs*/,pct,lclen,&pdddata,&pdddbcs,fldw,&outlen)>4)//~va5sR~//~vavaR~
//        return 4;                                                  //~va5sI~//~vavaR~
//    memcpy(pdata,pdddata,outlen);   //ddstr                        //~va5sI~//~vavaR~
//    memcpy(pdbcs,pdddbcs,outlen);   //ddstr                        //~va5sI~//~vavaR~
//    UTRACEP("filehdrlf2dd outlen=%d\n",outlen);                    //~vamBI~//~vavaR~
//    return 0;                                                      //~va5sI~//~vamBR~//~vavaR~
//}//filehdrlf2dd                                                    //~va5sI~//~vavaR~
//#endif //AAA                                                       //~vau4I~//~vavaR~
//**************************************************************** //~vamBI~
//full translation for utf8 filename shrink                        //~vamBI~
//**************************************************************** //~vamBI~
int filehdrlf2dd_full(int Popt,PUFILEH Ppfh,char **Ppdddata,char **Ppdddbcs,int *Ppddlen)//~vamBR~
{                                                                  //~vamBI~
	UCHAR *pdddbcs,*pdddata;                                       //~vau7R~
    int outlen;                                                    //~vau7R~
	UCHAR *pct,*pu8;                                               //~vau7I~
    int u8len,lclen;                                               //~vau7I~
//*****************************                                    //~vamBI~
	UTRACEP("filehdrlf2dd_full opt=%x\n",Popt);                    //~vamBI~
//#ifdef LNX                                                         //~vau7I~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)     //always ddfmt         //~vavaI~
    outlen=Ppfh->UFHfilenameddlen;                                 //~vau7I~
  if (outlen)                                                      //~vauaI~
  {                                                                //~vauaI~
    pdddata=Ppfh->UFHfilenamedddata;                               //~vau7I~
    pdddbcs=Ppfh->UFHfilenamedddbcs;                               //~vau7I~
  }                                                                //~vauaI~
  else                                                             //~vauaR~
#endif                                                             //~vauaM~
  {                                                                //~vauaI~
   	pct=Ppfh->UFHhdrnameattr;	//codetype tbl was setup           //~vau7I~
    if (!pct)                                                      //~vamBI~
    	return 4;                                                  //~vamBI~
    lclen=Ppfh->UFHhdrnamewidth; //codetbl length                  //~vamBI~
    pu8=Ppfh->UFHhdrnamebyu8;	//mixed str,saved at fileutf8inithdrattr//~vamBI~
    u8len=(int)strlen(pu8);                                        //~vamBI~
	if (xeutfcvlf2dd(0,pu8,u8len,0/*pdbcs*/,pct,lclen,&pdddata,&pdddbcs,0/*buffsz*/,&outlen)>4)//~vamBI~
    	return 4;                                                  //~vamBI~
  }                                                                //~vauaI~
    *Ppdddata=pdddata;                                             //~vamBI~
    *Ppdddbcs=pdddbcs;                                             //~vamBI~
    *Ppddlen=outlen;                                               //~vamBI~
	UTRACEP("filehdrlf2dd outlen=%d\n",outlen);                    //~vamBI~
    UTRACED("filehdrlf2dd data",pdddata,outlen);                   //~vamBI~
    UTRACED("filehdrlf2dd dbcs",pdddbcs,outlen);                   //~vamBI~
    return 0;                                                      //~vamBI~
}//filehdrlf2dd_full                                               //~vamBI~
//**************************************************************** //~v91yI~//~va00I~
// filesethdrattr                                                  //~v91yI~//~va00I~
//conv to get utf8(set cell attr) and get width                    //~v91yI~//~va00I~
//**************************************************************** //~v91yI~//~va00I~
int fileutf8sethdrattrsub(PUCLIENTWE Ppcw,char *Ppattr,char *Pattrtype,int Pfnwidth)//~v91yR~//~va00R~
{                                                                  //~v91yI~//~va00I~
	char *pcn,attrfg,codetype;                                     //~v91yR~//~va00R~
    int len,ii;                                                    //~v91yI~//~va00I~
    char *pattr;                                                   //~v91yI~//~va00R~
//*****************                                                //~v91yI~//~va00I~
UTRACEP("hdr attrsub fnw=%d,attrtype=%p\n",Pfnwidth,Pattrtype);//~v91yI~//~va00R~
UTRACED("hdr attrsub attrtype",Pattrtype,Pfnwidth);                //~vamBI~
UTRACED("Ppattr",Ppattr,Pfnwidth*2);                               //~vb3dR~
    codetype=XEUTFCT_UTF8;     //attr change if converted to locale from utf8//~v91yI~//~va00I~
    pcn=Pattrtype;                                                 //~v91yI~//~va00I~
  	pattr=Ppattr+1;                                   //~v91ZI~    //~va00R~
    attrfg=XEUTF_MIXEDFLDFGCOLOR;                                  //~v91yR~//~va00I~
    len=Pfnwidth;                                                  //~v91yI~//~va00I~
	for (ii=0;ii<len;ii++,pcn++,pattr+=2)                   //ushort attr//~v91yR~//~va00R~
    {                                                              //~v91yI~//~va00I~
         UTRACEP("%s:pcn=%p=%02x,pattr=%p=%02x\n",UTT,pcn,*pcn,pattr,*pattr);//~vb3dI~
    	if (*pcn==codetype)	//attr change                          //~v91yI~//~va00I~
        {                                                          //~vb3dI~
//  		*pattr=(*pattr & 0xf0)|attrfg;                         //~v91yR~//~va00I~//~vb2eR~
    		*pattr=(char)((*pattr & 0xf0)|attrfg);                 //~vb2eI~
        }                                                          //~vb3dI~
    }                                                              //~v91yI~//~va00I~
UTRACED("hdr attrsub cell",Ppattr,Pfnwidth*2);                     //~vamBI~
    return 0;                                                      //~v91yI~//~va00I~
}//fileutf8sethdrattrsub                                               //~v91yI~//~va00R~
//**************************************************************** //~v90rM~//~va00I~
// filesethdrattr                                                  //~v90rM~//~va00I~
//ret:UALLOC_FAILED                                                //~v90rI~//~va00I~
//**************************************************************** //~v90rM~//~va00I~
int fileutf8sethdrattr(PUCLIENTWE Ppcw,PUSCRD Ppsd,PUFILEH Ppfh,int Poutoffs,int Pfnoffs,int Pfnwidth,int Pscrwidth)//~v90rR~//~va00R~
{                                                                  //~v90rM~//~va00I~
	char *pcn,*pcell;                                        //~v90rR~//~va00R~
//*****************                                                //~v90rM~//~va00I~
UTRACEP("%s:outoffs=%d,fnoffs=%d,fnwidth=%d,scrwidth=%d\n",UTT,Poutoffs,Pfnoffs,Pfnwidth,Pscrwidth);//~vb3dR~
    pcn=Ppfh->UFHhdrnameattr;                                      //~v90rI~//~va00I~
    if (!pcn)                                                      //~v90rM~//~va00I~
        return 0;                                                  //~v90rM~//~va00I~
	fileutf8resethdrattr(Ppcw,Ppsd,Ppfh);                          //~va00R~
    Ppfh->UFHhdrnamepos=Pfnoffs;	//pos in attr tbl              //~v90rR~//~va00I~
    pcn+=Pfnoffs;                                                  //~v90rI~//~va00I~
    pcell=Ppsd->USDcell+Poutoffs+Poutoffs;                         //~va00I~
    fileutf8sethdrattrsub(Ppcw,pcell,pcn,Pfnwidth);//~v90rI~       //~va00R~
UTRACED("hdr cell attr",Ppsd->USDcell,Pscrwidth*2);                //~v90rR~//~va00I~
    return 1;                                                      //~v90rR~//~va00I~
}//fileutf8sethdrattr                                                  //~v90rM~//~va00R~
#ifdef W32                                                         //~vb3dI~
//**************************************************************** //~vb3dI~
//*expand attr:green to a whole path                               //~vb3dI~
//**************************************************************** //~vb3dI~
int fileutf8vsplithdrattrsub(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd,char *Ppattr,char *Pattrtype,char *Pdata,int Pfnwidth)//~vb3dR~
{                                                                  //~vb3dI~
	char *pcn,attrfg,codetype;                                     //~vb3dI~
    int len,ii;                                                    //~vb3dI~
    char *pattr;                                                   //~vb3dI~
    char *pc,*pc2;                                                 //~vb3dR~
    int jj;                                                        //~vb3dM~
//*****************                                                //~vb3dI~
UTRACEP("%s fnw=%d\n",UTT,Pfnwidth);                               //~vb3dI~
UTRACED("data",Pdata,Pfnwidth);                                    //~vb3dR~
UTRACED("attr",Ppattr,Pfnwidth*2);                                 //~vb3dR~
UTRACED("codetbl",Pattrtype,Pfnwidth);                             //~vb3dI~
    codetype=XEUTFCT_UTF8;     //attr change if converted to locale from utf8//~vb3dI~
    pcn=Pattrtype;  //UFHhdrnameattr                               //~vb3dR~
  	pattr=Ppattr+1;	//USDcell                                      //~vb3dR~
    attrfg=XEUTF_MIXEDFLDFGCOLOR;                                  //~vb3dI~
    len=Pfnwidth;                                                  //~vb3dI~
    pc=Pdata;                                                      //~vb3dI~
	for (ii=0;ii<len;ii++,pc++,pcn++,pattr+=2)                   //ushort attr//~vb3dR~
    {                                                              //~vb3dI~
        UTRACEP("%s:pcn=%p=%02x,pattr=%p=%02x\n",UTT,pcn,*pcn,pattr,*pattr);//~vb3dI~
    	if (*pcn==codetype)	//attr change                          //~vb3dI~
        {                                                          //~vb3dI~
            for (jj=ii-1,pc2=pc-1;jj>=0 && *pc2!=DIR_SEPC;jj--,pc2--)//~vb3dR~
            {                                                      //~vb3dR~
                UTRACEP("%s:pc=%p=%02x\n",UTT,pc2,*pc2);           //~vb3dR~
                *(Ppattr+jj+jj+1)=(char)((*pattr & 0xf0)|attrfg);  //~vb3dR~
            }                                                      //~vb3dR~
            for (;ii<len && *pc!=DIR_SEPC;ii++,pcn++,pattr+=2,pc++)//~vb3dR~
            {                                                      //~vb3dR~
                UTRACEP("%s:pc=%p=%02x\n",UTT,pc,*pc);             //~vb3dR~
                *pattr=(char)((*pattr & 0xf0)|attrfg);             //~vb3dR~
            }                                                      //~vb3dR~
        }                                                          //~vb3dI~
    }                                                              //~vb3dI~
UTRACED("attr",Ppattr,Pfnwidth*2);                                 //~vb3dR~
    return 0;                                                      //~vb3dI~
}//fileutf8vsplithdrattrsub                                        //~vb3dR~
#endif                                                             //~vb3dI~
//**************************************************************** //~va00I~
// filesethdrattrvsplit                                            //~va00I~
//**************************************************************** //~va00I~
int fileutf8vsplithdrattr(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd,PUFILEH Ppfh,int Pcsrposdisp)//~va00R~
{                                                                  //~va00I~
	char *pcn,*pattr;                                              //~va00I~
#ifdef W32                                                         //~vb3dI~
	char *pc;                                                      //~vb3dI~
#endif                                                             //~vb3dI~
    int fnoffs,fnwidth,outoffs,outwidth;                           //~va00I~
//*****************                                                //~va00I~
    UTRACEP("fileutf8vsplithdrattr\n");                            //~vamBI~
    pcn=Ppfh->UFHhdrnameattr;                                      //~va00I~
    if (!pcn)                                                      //~va00I~
        return 0;                                                  //~va00I~
	fileutf8resethdrattr(Ppcw,Ppsd,Ppfh);                          //~va00I~
//    if (!(Popt & FUVSHAO_CHNGWIDTH))    //no width change          //~va00I~//~vb3cR~
//    {                                                              //~va00I~//~vb3cR~
//        if (Ppcw!=scrgetcw(0))  //inactive client                  //~va00R~//~vb3cR~
//            return 0;           //no green                         //~va00R~//~vb3cR~
//    }                                                              //~va00I~//~vb3cR~
    fnoffs=Ppfh->UFHhdrnamepos;	//pos in attr tbl                  //~va00I~
    fnwidth=Ppfh->UFHhdrnamewidth;	//pos in attr tbl              //~va00I~
    fnwidth-=fnoffs;                                               //~va00I~
    pcn+=fnoffs;                                                   //~va00I~
    outoffs=FILENAMEPOS;                                           //~va00I~
    if (fnoffs)                                                    //~va00M~
    	outoffs+=3;		//"..." for long pathname                  //~va00M~
    pattr=Ppsd->USDcell+outoffs+outoffs;                           //~va00I~
    outwidth=Pcsrposdisp-outoffs;                                  //~va00I~
    fnwidth=min(fnwidth,outwidth);                                 //~va00I~
    fileutf8sethdrattrsub(Ppcw,pattr,pcn,fnwidth);                 //~va00I~
#ifdef W32                                                         //~vb3dI~
	pc=Ppsd->USDdata;                                              //~vb3dI~
    pc+=FILENAMEPOS;                                               //~vb3dR~
//  pattr=Ppsd->USDcell;                                           //~vb3dR~
//  pattr+=FILENAMEPOS*2;                                          //~vb3dR~
//  pcn=Ppfh->UFHhdrnameattr;                                      //~vb3dR~
    fileutf8vsplithdrattrsub(0,Ppcw,Ppsd,pattr,pcn,pc,fnwidth);    //~vb3dR~
#endif                                                             //~vb3dI~
    return 1;                                                      //~va00I~
}//fileutf8vsplitthdrattr                                          //~va00I~
#endif                                                             //~va00I~
