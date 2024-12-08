//*CID://+vbA1R~:                             update#=  703;       //~vbA1R~
//*************************************************************
//*xefile23.c  *                                                   //~v69DR~
//* draw(func_draw_file/setlineattr)                               //~v69DI~
//*************************************************************
//vbA1:240528 (gxe:bug) dbcs combining(x309a) split when lig off and split//~vbA1I~
//vbzV:240422 SCM(Mc) by green attr                                //~vbzVI~
//vbzS:240418 ligature mode; need redraw also when csr is on lineno to reset back to normal combine mode when csr is back to lineno fld//~vbzSI~
//vbm9:180722 (BUG)utf8 file u-2Exx treated as ERRREPCH(2e) and shown by green.//~vbm9I~
//vbk7:180613 (BUG)csrpos ucs display; shown altch for OVF ucs     //~vbk7I~
//vbi3:180211 supprt command history list                          //~vbi3R~
//vb5j:160919 (W32) when Lig:On and Comb:SPLIT,altch should be green//~vb5jI~
//vb5a:160913 (W32)locale file ligature support                    //~vb5aI~
//vb59:160913 vhex line shift to left when focus lost              //~vb59I~
//vb4A:160815 if UNICOMB UNPR mode and LIGATURE ON, write altch just after base char using GetTextExtentPoint32W//~vb4AI~
//vb4y:160814 set same attr to UNICOMB UNPR altch for edit panel as dirlist//~vb4yI~
//vb4x:160814 (Bug) tabdisplay's unprintable id 'l' may be  yes by UDBCSCHK_ISUCSWIDTH0//~vb4xI~
//vb4f:160802 (ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~vb4fI~
//vb3x:160621 ffff is treated as dbcsspace on dirlist. tabdisplay set dbcs space to ffff/()//~vb3xI~
//vb2a:160117 display hex char on hdrline for the case dbcs split at UFCleft//~vb2aI~
//vb28:160116 (BUG)display spilit utf8 by lineattr                 //~vb28I~
//vazp:150113 (BUG)scroll-right MAX crash when maxline<scrwidth    //~vazpI~
//vazn:150113 display 5 buye(32760) cursor cols                    //~vaznI~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //~vaz0I~
//vawi:140603 (BUG)utf8 file pso2offs;offset may be 2 or 3 byte    //~vawiI~
//vaw3:140526 (Win:UNICODE)hex kbd for 3byte unicode               //~vaw3I~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//va7j:100820 (BUG)non ascii char on lineno fld of ebc file is not show for lcmd "+".//~va7jI~
//va6W:100726 (BUG) va6T for also console version if utf8 file     //~va6WI~
//va6T:100724 (BUG:WXEXXE) vhex line not redraw by insert line when Ligature on or combine mode//~va6TI~
//va6x:000628 avoid screen flickeer for utf8 file(no draw if csr is on lineno fld) if not ciombine or ligature mode//~va6xI~
//va6u:000626 (WXE)ligature support for also locale code file
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va45:100331 (BUG)Tab is displayed as 0x20 for cpu8 on hdr line   //~va45I~
//va3Y:100322 (BUG) hhex csr reverse split dbcs                    //~va3YI~
//va3X:100322 (BUG of va3B) vhex csr is not shown yet              //~va3XI~
//va3L:100317 Hex input mode;draw both split screen hdr line       //~va3LI~
//va3K:100316 allow unicode hex input on cmdline                   //~va3KI~
//va3H:100313 hexinput mode prefix for ucs,v:ucs4,default wait 2 byte//~va3HI~
//va3G:100313 (BUG)Hex input mode id disappear by csr move         //~va3GI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va3B:100309 (BUG)reverse block is not displayed when FG color is same between Browse and Edit//~va3BI~
//va3u:100221 (BUG)not unconditionaly set green for combining char when ligature+split mode//~va3uI~
//            If so so,sub string split at it,then ligature in effective.//~va3uI~
//va3s:100219 simple split mode like as windows. single write combining char when split mode.//~va3sI~
//            visibility depends to curses. user select split or combine mode.//~va3sI~
//            shadow is another option by A+":"                    //~va3sI~
//va3r:100219 set different attr for the column around cursor      //~va3rI~
//            Because unconditional setting to combining char result drawing shadow whe split mode//~va3rI~
//va3n:100217 (LNX:CONS)for FC5(combining char ocuupy 1 column), no combine mode is same as combine mode//~va3nI~
//va3m:100211 set tab attr to W0 char around data csr by vhexcsr   //~va3nI~
//            file23.c                                             //~va3nI~
//va3m:100211 set tab attr to W0 char around data csr by vhexcsr   //~va3mI~
//va3j:100208 (LNX)try ligature for console version                //~va3jI~
//            draw csr line when ligature or combinemode for utf8 file//~va3jR~
//va3h:100207 try ligature for also win32 console version          //~va3hI~
//va36:100203 (BUG)can not save to itself if file update was whole undoed after once saved//~va36I~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            file23.c:set csr position vhexline/dataline attr     //~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//v79e:080818 (BUG)remains csr pos reverse when Hhex+Vhex display mode//~v79eI~
//v78o:080322 (SYN:BUG)reverse is not able to distingush on browse screen//~v78oI~
//v780:080212 syntaxhighlight support                              //~v780I~
//v90j:071021 (BUG) full-draw by lineno size change when split scr(sholuld chk for each file)//~v90jI~
//v76J:070907*(BUG)lineend-file abend by access EOL position       //~v76JI~
//v76u:070801 (BUG)celldrawsw=2 even when no bnds2 set             //~v76uI~
//v74E:070315 BOUNDS cmd support                                   //~v74EI~
//v747:070212 (BUG)ABEND by UFCcurtop==NULL(whos set 0 ois not known but ::cb?)//~v73aI~
//v73a:070109 (BUG)corrupted display if dbcs is splited by margin boundary//~v73aI~
//v70n:060815 cut hex display part for vhex mode hex line          //~v70nI~
//v69D:060708 split xefile2 to xefile23(func_draw_file,filecolsdisp,setlineattr)//~v69DI~
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
#ifdef LNX                                                         //~va3nI~
	#define _XOPEN_SOURCE_EXTENDED		//ncurses define           //~va3nI~
	#include <ucurses.h>	         //v1.3 add                    //~va3nI~
#endif                                                             //~va3nI~
#ifdef W32                                                         //~va3sI~
	#include <windows.h>                                           //~va3sI~
#endif                                                             //~va3sI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318R~
#include <ualloc.h>                                             //~5318I~
#include <udbcschk.h>                                              //~v217I~
#include <uedit2.h>                                                //~v440I~
#include <utrace.h>                                                //~v06yI~
#ifdef FTPSUPP                                                     //~v58LI~
	#include <uftp.h>                                              //~v58LI~
#endif                                                             //~v58LI~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include <udbcschk.h>                                              //~va1cR~
#endif                                                             //~va1qI~
#ifdef UTF8UCS2                                                    //~va20I~
	#include <utf.h>                                               //~va30I~
	#include <utf22.h>                                             //~va20R~
	#include <uviom.h>                                             //~va3nI~
#endif                                                             //~va20I~
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
#include "xesub.h"                                              //~5318I~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xesub2.h"                                                //~va1cR~
#endif                                                             //~va1qI~
#include "xedir.h"                                              //~v04dI~
#include "xedlcmd.h"                                            //~v046M~
#include "xedlcmd2.h"                                           //~v046M~
#include "xegbl.h"                                                 //~v440I~
#include "xeopt.h"                                                 //~v44mI~
#include "xeundo.h"                                                //~v780I~
#include "xesyn.h"                                                 //~v780I~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xeutf.h"                                                 //~va3hI~
#include "xeutf2.h"                                                //~va20I~
#include "xelcmd4.h"                                               //~va7jI~
#ifdef XXE                                                         //~va3uI~
#include "xxexei.h"                                                //~va3uR~
#endif                                                             //~va3uI~
#ifdef WXE                                                         //~va3uI~
#include "wxexei.h"                                                //~va3uI~
#endif                                                             //~va3uI~
#endif                                                             //~va20I~
//*******************************************************
#define FILENAMEPOS   8
//#define COLUMNDISPPOS 18     //" xxx-(xxx)-xxx Rep"              //~v57GR~
#define COLUMNDISPPOS 19       //" xxxx-xxxx-xxxx Rep"             //~v57GI~
#define COLUMNDISPPOSDIR 4       //" Rep"                          //~v60bI~
#define COLUMNDISPW   4        //" xxxx-xxxx-xxxx Rep"             //~v57GI~
#define COLUMNDISPSC  1      //start column
#define COLUMNDISPCC  6      //curr  column
#define COLUMNDISPEC  11     //end   column
#define NOTUPDATEDID  '|'    //update file/line id              //~5107I~
#define UPDATEID      '*'    //update file/line id              //~5107I~
#define SPLITTOPID    '-'    //post of split line id               //~v0agR~
#define U8CMDID       'u'    //on lineno fld splitter              //~vbi3I~
#define SPLITID       '.'    //post of split line id             //~v0eQR~
#define SPLITTOPUPDID '+'    //post of split line id               //~v0agI~
#define SPLITUPDATEID ':'    //post of split update line id      //~v0eQR~
#define TABPADCHARDISPX '-'   //tab skip hex notation              //~v09SI~
#define PROTAREADRAW	19				//prot area display        //~v0ifI~
                                                                   //~v780I~
#define SYNTAX_DRAW 0x0100   //on celldrawsw                       //~v780I~
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
static int Smerginoffs;   	//parm to setline attr                 //~v0buI~
static int Sbndsoffs1,Sbndsoffs2;   	//parm to setline attr     //~v74EI~
static int Shexoffs,Shexcsrpos,Sdatacsrpos;   		//parm to setline attr//~v443R~
#ifdef UTF8SUPPH                                                   //~va1cR~
static int Sdatacsrpos1;  		//for Sdatacsrpos1<Sdatacsrpos2    //~va1cR~
#endif                                                             //~va1cR~
static int Sdatacsrpos2;  		//parm to setline attr             //~v450R~
//static int Sdatacsrposu8;  		//parm to setline attr             //~va3rI~//~va3sR~
static int Sprotlen;   		//parm to setline attr                 //~v0ifI~
static int Sfileupundoctr;	//parm to setline attr              //~5105I~
static int Sfileupctr;	//parm to setline attr                  //~5105I~
static int Sfileresetsw;//v011 parm to setline attr(cap paste reset)//~5610I~
//static int Soldlinesw=0;		//lineno field width               //~v90jI~
//static int Seolid=EOLID;		//change by many line isrt         //~v47dR~
static UCHAR Scolor_lineno,Scolor_client,Scolor_lineno_r,Scolor_client_r;//~5430I~
static UCHAR Sprotattr,Sprotattr_r;                                //~v0ifI~
static UCHAR Smerginattr;                                          //~v0iiI~
static UCHAR Sbndsattr;                                            //~v74EI~
static UCHAR Shexattr;                                             //~v440I~
static UCHAR Shexcsrattr;                                          //~v457I~
#ifdef SYNSUPP                                                     //~v780I~
	static int   Ssynbgtab;	//syntax highlight bg for tab          //~v780R~
#endif                                                             //~v780I~
#ifdef UTF8UCS2                                                    //~va20I~
	static int Svhexcold1=-1,Svhexcold2=-1,Svhexcolx=-1,Svhexcolxsv,Svhexcsrsw=0;//~va20I~
	static int Svhexcold1sv;                                       //~va20I~
	static UCHAR Shexcsrmarginattr,Shexcsrmarginattrc;             //~va20I~
	static UCHAR Shexmerginattr;                                   //~va20I~
#endif                                                             //~va20I~
//#ifdef WXE                                                       //~v621R~
//    static int Sresizesw=0;                                      //~v621R~
//#endif                                                           //~v621R~
//unprintable char definition(for english x00 only)                //~v09UI~
//*************************                                        //~v09UI~
//void vsplitshift(PUCLIENTWE Ppcw);                               //~v69DR~
//int tabdisplay(UCHAR *Pdata,UCHAR *Pdbcs,int Plen);              //~v0avR~
void setlineattr(PUCLIENTWE Ppcw,PULINEH Pplh,PUSCRD Ppsd,         //~v09RR~
//  				int Pcellsw);                                  //~v09RR~//~vbi3R~
    				int Pcellsw,int Pline);                        //~vbi3R~
#ifdef W32                                                         //~va3mI~
//int setattraroundvhexdataline(int Popt,UCHAR *Pdbcs,USHORT *Pattr,int Ppos1,int Ppos2,int Pwidth,int Pcolor);//~va3mI~//~vbzVR~
int setattraroundvhexdataline(int Popt,UCHAR *Ppdata,UCHAR *Pdbcs,USHORT *Pattr,int Ppos1,int Ppos2,int Pwidth,int Pcolor);//~vbzVR~
#else                                                              //~va3mI~
//int setattraroundvhexdataline(int Popt,UCHAR *Pdbcs,UCHAR *Pattr,int Ppos1,int Ppos2,int Pwidth,int Pcolor);//~va3mI~//~vbzVR~
int setattraroundvhexdataline(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,UCHAR *Pattr,int Ppos1,int Ppos2,int Pwidth,int Pcolor);//~vbzVR~
#endif                                                             //~va3mI~
#ifdef W32                                                         //~va3rI~
int setattraroundcsrpos(int Popt,UCHAR *Pdbcs,USHORT *Pattr,int Ppos,int Pwidth,int Pcolor);//~va3rI~
#else                                                              //~va3rI~
int setattraroundcsrpos(int Popt,UCHAR *Pdbcs,UCHAR *Pattr,int Ppos,int Pwidth,int Pcolor);//~va3rI~
#endif                                                             //~va3rI~
//void filecolsdisp(PUCLIENTWE Ppcw,PUSCRD Ppsd,int Pfullsw);      //~v69DR~
int f23_isutf8dbcssplit(int Popt,char *Pdbcs,int Pcol,int Pwidth); //~vbm9I~
int f23_iscombining(int Popt,char *Pdddata,char *Pdddbcs,int Plen);//~vbzVI~
int f23_isFormat(int Popt,char *Pdddata,char *Pdddbcs,int Plen);   //~vbA1I~
//****************************************************************
// file_draw
//*setup screen line data
//*parm1:no use
//*parm2:file client work element
//*rc   :0 or UALLOC_FAILED                                     //~v04dR~
//****************************************************************
int func_draw_file(PUCLIENTWE Ppcw)
{
#define HEXEDITLEN 5                                               //~v09SI~
//                       //for 2 byte dbcs   E-x1x2-|fnm           //~va1cR~
#define HEXEDITLENSS3 6  //for ss3           x1x2x3-|fnm           //~va1cR~
#define HEXEDITLENGB4 8  //for GB4           x1x2x3x4fnm           //~va1cR~
#define HEXEDITLENMAX 8                                            //~va1cR~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
	#define HEXEDITLENUCS4 6  //for ucs4     x1x2x3-|fnm           //~va3xI~
#endif                                                             //~va3xI~
	UCHAR  *pc,*pcd;
	UCHAR  *hexdata,*pdata0;                                       //~v440R~
	UCHAR  *pdbcs0;                                                //~v450I~
    UCHAR   uch;                                                   //~v09SI~
	int     len,len2,offs,maxline,line,csrposdisp,drawline;     //~5126R~
	int     linesw=0,revctr,csrfldtopline=0;                       //~v19kR~
    int     ii,hexinputlen=0;                                        //~v101I~//~vafcR~
	PUSCRD  psd,psdline;                                        //~5126R~
	PUSCRD  psd0;           //header line psd                      //~v09SI~
	PUSCRD  psdgauge=0;       //gauge line psd                     //~v74ER~
	PUFILEH pfh;
	PULINEH plh;                                                //~5126R~
	PULINEH plhcl;               //last line of cmd edit           //~v07dR~
	PULINEH plhcsr;              //csr line plh                    //~v09SI~
	PULINEH plhdrawstart;        //redraw start plh                //~v0hfI~
//	UCHAR   linenowk[8];                                           //~vazpR~
  	UCHAR   linenowk[32];   //for minus value expand to 9 byte ffffffff\0//~vazpI~
//  UCHAR   linenowk2[12];                                         //~vaz0R~
    UCHAR   linenowk2[32];                                         //~vaz0I~
	UCHAR   hexeditwk[HEXEDITLEN+1];                               //~v09SI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	UCHAR   hexeditcompwk[HEXEDITLENMAX];                          //~va1cR~
	UCHAR   hexeditwkgb4[HEXEDITLENGB4+1];                         //~va1cR~
#endif                                                             //~va1cR~
	long    li;
	UFILEC *pfc;
    int     linenosz;                                           //~v069I~
    int     fulldrawsw;                                            //~v08dI~
    int     celldrawsw;                                            //~v09RI~
    int     csrpos;                                                //~v09SI~
    int     dpos;                                                  //~v59vI~
    int     mergin;                                                //~v0buI~
    int drawstartsw;                                               //~v0hfR~
    int     drawhexsw;  //hex display sw                           //~v101I~
    int     xlinenosw;  //hex lineno display sw                    //~v10XI~
    int     colslinesw;	//cols line display sw                     //~v11NI~
    int     hexmodesw;		//hex display mode                     //~v440I~
    int     binmodesw;		//binary file draw                     //~v60mI~
    int     newposx,newposy;		//new cursor pos               //~v44kR~
    char    *hexeditpat4c;                                         //~v57GI~
    int     hexoptupper;                                           //~v44mI~
    int     colw;                                                  //~v57GI~
    int     csrline,vhexmode,vhexpsdid,vhexdrawsw=0,vhexplhctr,vhexplhctrcsr;//~v60vR~
    int bndsoffs1,bndsoffs2;                                       //~v74ER~
#ifdef SYNSUPP                                                     //~v780I~
    int syntaxdrawsw=0;                                            //~v780I~
    int synopt=0;                                                  //~v78oI~
#endif                                                             //~v780I~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int dbcssz;                                                    //~va1cR~
#endif                                                             //~va1cR~
#ifdef UTF8UCS2                                                    //~va20I~
    int tdopt,vhlen,vhexcsrlinetype=0,swutf8file,vhexdrawsw2,vhexdrawsw3,ucs;//~va20R~//~vafcR~
    PULINEH vhexcsrlineplh=0;                                      //~va20I~
    int csrcols;                                                   //~va3jI~
#endif                                                             //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
    int swucs4=0;                                                  //~va3xI~
#endif                                                             //~va3xI~
	int recordmodesw;                                              //~va50I~
    int swligaturemode=0,swutf8orligaturemode=0;                   //~vafcR~
    int swlongrecord;                                              //~vaznI~
    int oldcsrline;                                                //~vbi3R~
//****************************
//  fulldrawsw=UCBITCHK(Ppcw->UCWflag,UCWFDRAW);                   //~v0k0R~
    linenosz=Ppcw->UCWlinenosz;                                 //~v069I~
	if (UCBITCHK(Ppcw->UCWflag,UCWFWAKEUP))
//  {                                                              //~v08bR~
//  	UCBITOFF(Ppcw->UCWflag,UCWFWAKEUP);                        //~v08bR~
		filewakeup(Ppcw);			//init USCRD                //~v020R~
//  }                                                              //~v08bR~
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;
	plh=pfc->UFCcurtop;						//top line to be display
    if (!plh)                                                      //~v747R~
    	pfc->UFCcurtop=plh=UGETQTOP(&pfh->UFHlineque);      //avoid ABEND//~v747R~
    vhexmode=UCBITCHK(pfc->UFCflag2,UFCF2VHEX);                    //~v60vI~
    UCBITOFF(pfc->UFCflag2,UFCF2VHEXINCOMP);	//once clear;last line is not full 3 line//~v60vI~
#ifdef SYNSUPP                                                     //~v780I~
    if (                                                           //~v780I~
		(pfh->UFHsynflag & UFHSF_HASCOLORDATA)                     //~v780I~
	&&  (pfh->UFHsynflag & UFHSF_ON)                               //~v780R~
    )                                                              //~v780I~
    {                                                              //~v780I~
    	syntaxdrawsw=1;   //on celldrawsw                          //~v780I~
        if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                     //~v78oI~
            synopt|=SYNCPO_BROWSE;                                 //~v78oI~
//      Ssynbgtab=syngetbgtab(0);                                  //~v78oR~
        Ssynbgtab=syngetbgtab(synopt);                             //~v78oI~
    }                                                              //~v780I~
#endif                                                             //~v780I~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(pfh);                                  //~va20R~
#endif                                                             //~va20I~
    mergin=pfh->UFHmergin;                                         //~v0buI~
    Smerginoffs=mergin-pfc->UFCleft;                               //~v0buI~
    if (Smerginoffs<0)                                             //~v0buI~
    	Smerginoffs=0;                                             //~v0buI~
    bndsoffs1=pfh->UFHbndscol1-1;                                  //~v74EI~
    bndsoffs2=pfh->UFHbndscol2;                                    //~v74EI~
    Sbndsoffs1=bndsoffs1-pfc->UFCleft;                             //~v74ER~
    if (Sbndsoffs1<0)                                              //~v74EI~
    	Sbndsoffs1=0;                                              //~v74EI~
    if (bndsoffs2)                                                 //~v74EI~
    {                                                              //~v74EI~
	    Sbndsoffs2=bndsoffs2-pfc->UFCleft;                         //~v74ER~
	    if (Sbndsoffs2<0)                                          //~v74EI~
    		Sbndsoffs2=0;                                          //~v74EI~
    }                                                              //~v74EI~
    else                                                           //~v74EI~
	    Sbndsoffs2=-1;                                             //~v74EI~
    Sprotlen=pfh->UFHprotlen-pfc->UFCleft;                         //~v0ifI~
    if (Sprotlen<0)                                                //~v0ifI~
    	Sprotlen=0;                                                //~v0ifI~
                                                                   //~v410I~
    xlinenosw=UCBITCHK(pfh->UFHflag4,UFHF4XLINENO);                //~v44mR~
	hexoptupper=UCBITCHK(Goptopt,GOPT_HEX_UPPER);                  //~v44mR~
	if (hexoptupper)                                               //~v44mI~
    {                                                              //~v57GI~
    	hexeditpat4c="%05X";                                       //~v57GR~
    }                                                              //~v57GI~
    else                                                           //~v44mI~
    {                                                              //~v57GI~
    	hexeditpat4c="%05x";                                       //~v57GR~
    }                                                              //~v57GI~
    hexmodesw=UCBITCHK(pfh->UFHflag5,UFHF5HEX);                    //~v440R~
    binmodesw=UCBITCHK(pfh->UFHflag4,UFHF4BIN);                    //~v60mI~
    recordmodesw=UCBITCHK(pfh->UFHflag10,UFHF10RECORD);            //~va50I~
    Sfileresetsw=UCBITCHK(pfh->UFHflag2,UFHF2RESETPASTE);//v011 //~5610R~
 	if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))  //excluded      //~5105I~
    {                                                              //~v0k0I~
        pfc->UFCcurtop=plh=getdisplayline(plh,-1,0);                 //prev line//~5204R~
        filesetfulldraw(Ppcw);  //clear UFCdrawplh                 //~v0k0I~
    }                                                              //~v0k0I~
                                                                   //~v0k0I~
    fulldrawsw=UCBITCHK(Ppcw->UCWflag,UCWFDRAW);//after curtop changed chk//~v0k0I~
                                                                   //~v0k0I~
//  maxline=Ppcw->UCWheight-FILEHDRLINENO;		//except hdr and cmd//~v11NR~
    maxline=Ppcw->UCWheight-Ppcw->UCWfilehdrlineno;		//except hdr and cmd//~v11NI~
    psd0=                                                          //~v09SI~
	psd=Ppcw->UCWpsd;
	len=Ppcw->UCWwidth;
	Sprotattr  =Gattrtbl[COLOR_FRAME];		//prot line            //~v0ifI~
	Sprotattr_r=Gattrtbl[COLOR_FRAME_R];	//prot line            //~v0ifI~
	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//browse
    {                                                           //~5430I~
		Scolor_client=Gattrtbl[COLOR_BCLIENT];	//browse fg     //~5430R~
#ifdef SYNSUPP                                                     //~v78oI~
      if (syntaxdrawsw)                                            //~v78oI~
//  	Scolor_client_r=xesyngetbgreverse(0);		//0:browsw     //~v78oR~//~vb28R~
    	Scolor_client_r=(UCHAR)xesyngetbgreverse(0);		//0:browsw//~vb28I~
      else                                                         //~v78oI~
#endif                                                             //~v78oI~
		Scolor_client_r=Gattrtbl[COLOR_BCLIENT_R];	//browse fg //~5430R~
		Scolor_lineno=Gattrtbl[COLOR_BLINENO];	//browse fg     //~5430R~
		Scolor_lineno_r=Gattrtbl[COLOR_BLINENO_R];	//browse fg //~5430R~
		Shexcsrattr=Gattrtbl[COLOR_ECLIENT];	//edit fg          //~v457R~
#ifdef UTF8UCS2                                                    //~va20I~
		Shexcsrmarginattrc=Gattrtbl[COLOR_ECLIENT];	//edit fg      //~va20I~
#endif                                                             //~va20I~
    }                                                           //~5430I~
	else
    {                                                           //~5430I~
		if (Ppcw->UCWmenuopt==PANMOCMD)                               //~v06yI~
        {                                                             //~v06vI~
			Scolor_client=Gattrtbl[COLOR_CCLIENT];	//cmd result      //~v06vI~
			Scolor_client_r=Gattrtbl[COLOR_CCLIENT_R];                //~v06vI~
			Scolor_lineno=Gattrtbl[COLOR_CLINENO];	//cmd result      //~v06vI~
			Scolor_lineno_r=Gattrtbl[COLOR_CLINENO_R];                //~v06vI~
//UTRACEI("PANMOCMD COLOR_CLIENT_R",COLOR_CCLIENT_R);              //~v06yR~
//UTRACED("PANMOCMD Scolor_client_r",Gattrtbl+COLOR_CCLIENT_R,1);  //~v06yR~
			plhcl=UGETQPREV(UGETQEND(&pfh->UFHlineque));           //~v07dR~
            if (!plhcl->ULHlen)                                    //~v07dR~
            	UCBITON(plhcl->ULHflag3,ULHF3CMDECHO);	//cmd input line//~v07dR~
        }                                                             //~v06vI~
        else                                                          //~v06vI~
        {                                                             //~v06vI~
			Scolor_client=Gattrtbl[COLOR_ECLIENT];	//browse fg       //~v06vR~
#ifdef SYNSUPP                                                     //~v78oI~
      	  if (syntaxdrawsw)                                        //~v78oI~
//  	    Scolor_client_r=xesyngetbgreverse(1);		//1:edit   //~v78oR~//~vb28R~
    	    Scolor_client_r=(UCHAR)xesyngetbgreverse(1);		//1:edit//~vb28I~
          else                                                     //~v78oI~
#endif                                                             //~v78oI~
			Scolor_client_r=Gattrtbl[COLOR_ECLIENT_R];	//browse fg   //~v06vR~
			Scolor_lineno=Gattrtbl[COLOR_ELINENO];	//browse fg       //~v06vR~
			Scolor_lineno_r=Gattrtbl[COLOR_ELINENO_R];	//browse fg   //~v06vR~
        }                                                             //~v06vI~
		Shexcsrattr=Gattrtbl[COLOR_BCLIENT];	//edit fg          //~v457R~
#ifdef UTF8UCS2                                                    //~va20I~
    	if (UCBITCHK(pfh->UFHflag3,UFHF3OOMNOPROT)) //not proected mergin//~va20I~
			Shexcsrmarginattrc=Gattrtbl[COLOR_BCLIENT];	//browse fg//~va20I~
        else                                                       //~va20I~
			Shexcsrmarginattrc=Scolor_lineno;	//green            //~va20I~
#endif                                                             //~va20I~
    }                                                           //~5430I~
    if (UCBITCHK(pfh->UFHflag3,UFHF3OOMNOPROT)) //not proected mergin//~v0iiI~
    {                                                              //~v20WI~
	    Smerginattr=Scolor_lineno;                                 //~v0iiI~
#ifdef UNX                                                         //~v20WI~
    	if (Gmaxcolor==2)   //mono color                           //~v20WI~
        	Smerginattr=Gattrtbl[COLOR_TITLE];	//highlight        //~v20WI~
#endif //!UNX                                                      //~v20WI~
    }                                                              //~v20WI~
    else                                        //protected        //~v0iiI~
    {                                                              //~v20WI~
		Smerginattr=Gattrtbl[COLOR_BCLIENT];	//browse fg        //~v0iiI~
#ifdef UNX                                                         //~v20WI~
    	if (Gmaxcolor==2)   //mono color                           //~v20WI~
			if (!UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//edit         //~v20WI~
        		Smerginattr=Gattrtbl[COLOR_TITLE];	//highlight    //~v20WI~
#endif //!UNX                                                      //~v20WI~
    }                                                              //~v20WI~
    Shexattr=Scolor_lineno;                                        //~v457R~
#ifdef UTF8UCS2                                                    //~va20I~
    if (swutf8file)                                                //~va20I~
		Shexmerginattr=Gattrtbl[COLOR_BCLIENT];	//white            //~va20I~
    else                                                           //~va20I~
		Shexmerginattr=Shexattr;				//green            //~va20I~
	Shexcsrmarginattr=Scolor_lineno;	//green                    //~va20I~
#endif                                                             //~va20I~
#ifdef UNX                                                         //~v440I~
    if (Gmaxcolor==2)   //mono color                               //~v440I~
    	Shexcsrattr=Gattrtbl[COLOR_TITLE];	//highlight            //~v457R~
#endif //!UNX                                                      //~v440I~
	Sbndsattr=Scolor_lineno;                                       //~v74EI~
#ifdef UNX                                                         //~v74EI~
    if (Gmaxcolor==2)   //mono color                               //~v74EI~
        Sbndsattr=Gattrtbl[COLOR_TITLE];	//highlight            //~v74EI~
#endif //!UNX                                                      //~v74EI~
//**hdr line
	psd->USDlen=len;
	psd->USDoff=0;		//write to from leftmost column
	pc=psd->USDdata;
	csrposdisp=pfc->UFCcsrposdisp;
//	if (UCBITCHK(Ppcw->UCWflag,UCWFDRAW))                          //~v08dR~
	if (fulldrawsw)                                                //~v08dI~
	{
//column
		vsplitshift(Ppcw);
		csrposdisp=pfc->UFCcsrposdisp;
     if (csrposdisp>0) //vsplitshift remained colomn display position//~v51VR~
     {                                                             //~v51VI~
        swlongrecord=0;                                            //~vaznI~
      if (xlinenosw)                                               //~v410I~
//  	sprintf(linenowk,"%04x",pfc->UFCleft);                     //~v44mR~
//  	sprintf(linenowk,hexeditpat4,pfc->UFCleft);                //~v57GR~
    	sprintf(linenowk,hexeditpat4c,pfc->UFCleft);               //~v57GI~
      else                                                         //~v410I~
      {                                                            //~v57GI~
//  	sprintf(linenowk,"%04d",pfc->UFCleft+1);                   //~v57GR~
		colw=pfc->UFCleft+1;                                       //~v57GI~
        if (colw>9999||(pfc->UFCleft+len-linenosz)>9999)           //~vaznI~
        {                                                          //~vaznI~
            swlongrecord=1;                                        //~vaznM~
    		sprintf(linenowk,"%05d(",colw);                        //~vaznI~
        }                                                          //~vaznI~
        else                                                       //~vaznI~
        if (colw<=999)                                             //~v57GI~
    		sprintf(linenowk,"%04d-",colw);                        //~v57GI~
        else                                                       //~v57GI~
    		sprintf(linenowk,"%05d",colw);                         //~vaznR~
      }                                                            //~v57GI~
//  	memcpy(pc+csrposdisp+COLUMNDISPSC,linenowk+1,3);           //~v57GR~
      if (swlongrecord)                                            //~vaznI~
      {                                                            //~vaznI~
    	memcpy(pc+csrposdisp+COLUMNDISPSC,linenowk,COLUMNDISPW+2);//"xxxxx("//~vaznR~
      }                                                            //~vaznI~
      else                                                         //~vaznI~
      {                                                            //~vaznI~
    	memcpy(pc+csrposdisp+COLUMNDISPSC,linenowk+1,COLUMNDISPW); //~v57GR~
    	*(pc+csrposdisp+COLUMNDISPSC+COLUMNDISPW)='(';   // "xxxx("//~vaznI~
      }                                                            //~vaznI~
      if (xlinenosw)                                               //~v410I~
//  	sprintf(linenowk,"%04x",pfc->UFCleft+len-linenosz-1);      //~v44mR~
//  	sprintf(linenowk,hexeditpat4,pfc->UFCleft+len-linenosz-1); //~v57GR~
    	sprintf(linenowk,hexeditpat4c,pfc->UFCleft+len-linenosz-1);//~v57GI~
      else                                                         //~v410I~
      {                                                            //~v57GI~
//  	sprintf(linenowk,"%04d",pfc->UFCleft+len-linenosz);        //~v57GR~
		colw=pfc->UFCleft+len-linenosz;                            //~v57GI~
        if (swlongrecord)                                          //~vaznI~
	    	sprintf(linenowk,"%05d",colw);                         //~vaznR~
        else                                                       //~vaznI~
        if (colw<=999)                                             //~v57GI~
    		sprintf(linenowk," -%03d",colw);                       //~v57GI~
        else                                                       //~v57GI~
	    	sprintf(linenowk,"%05d",pfc->UFCleft+len-linenosz);    //~v57GR~
      }                                                            //~v57GI~
//  	memcpy(pc+csrposdisp+COLUMNDISPEC,linenowk+1,3);           //~v57GR~
    	memcpy(pc+csrposdisp+COLUMNDISPEC,linenowk+1,COLUMNDISPW); //~v57GR~
     }//colomn display space avail                                 //~v51VI~
	}
//    if (Gcsrposy >  Ppcw->UCWorgy+CMDLINENO                      //~v0eCR~
//    &&  Gcsrposy <  Ppcw->UCWorgy+Ppcw->UCWheight                //~v0eCR~
//    &&  Gcsrposx >= Ppcw->UCWorgx+linenosz                       //~v0eCR~
//    &&  Gcsrposx <  Ppcw->UCWorgx+Ppcw->UCWwidth                 //~v0eCR~
////  ||  UCBITCHK(Ppcw->UCWflag,UCWFDRAW))                        //~v0eCR~
//    ||  fulldrawsw)                                              //~v0eCR~
//    {                                                            //~v0eCR~
//        sprintf(linenowk,"%04d",                                 //~v0eCR~
////              max(((PUFILEC)(Ppcw->UCWpfc))->UFCleft           //~v0eCR~
////                  +Gcsrposx-Ppcw->UCWorgx-linenosz+1,0));      //~v0eCR~
//                pfc->UFCleft+1+max(Ppcw->UCWrcsrx-linenosz,0));  //~v0eCR~
//      if (memcmp(pc+csrposdisp+COLUMNDISPCC,linenowk+1,3))       //~v0eCR~
//      {                                                          //~v0eCR~
//        memcpy(pc+csrposdisp+COLUMNDISPCC,linenowk+1,3);         //~v0eCR~
//        UCBITON(psd->USDflag2,USDF2DRAW);                        //~v0eCR~
//      }                                                          //~v0eCR~
//    }                                                            //~v0eCR~
	if (pfh->UFHupctr	//updated                               //~4C31R~
	&&  pfh->UFHupctr!=pfh->UFHupctrsave)	//same as saved     //~4C31I~
		*(pc+FILENAMEPOS-1)=UPDATEID;                           //~5107R~
	else                                                        //~4C31I~
	if (pfh->UFHupctrsave==-1)	//undoed after once saved          //~va36I~
		*(pc+FILENAMEPOS-1)=UPDATEID;                              //~va36I~
    else                                                           //~va36I~
		*(pc+FILENAMEPOS-1)=NOTUPDATEDID;                       //~5107R~
//**cmd line
	psd++;
	filecmdlinedisp(Ppcw,psd);                                  //~v03fR~
	psd++;
//**column gauge line                                              //~v11NI~
	if (Ppcw->UCWfilehdrlineno>FILEHDRLINENO)	//gauge required   //~v11NI~
    {                                                              //~v11NI~
		UCBITON(psd->USDflag2,USDF2PROT);  //reset                 //~v11NI~
//  	if (fulldrawsw)	//scroll etc                               //~v21qR~
//      	filecolsdisp(Ppcw,psd);	                               //~v21qR~
        psdgauge=psd;       //save for filecolsdisp after csrx set for find etc//~v21qI~
		psd++;		//used a line psd                              //~v11NI~
        colslinesw=1;                                              //~v11NI~
    }                                                              //~v11NI~
    else                                                           //~v11NI~
    {                                                              //~v11NI~
		UCBITOFF(psd->USDflag2,USDF2PROT);  //reset                //~v11NI~
        colslinesw=0;                                              //~v11NI~
	}                                                              //~v11NI~
//*determine plh on psd                                         //~5126I~
	psdline=psd;	//save top                                  //~5126I~
	plhdrawstart=pfc->UFCdrawplh;                                  //~v0hfI~
    drawstartsw=0;                                                 //~v0hfR~
    newposx=Ppcw->UCWrcsrx-linenosz;               //cols          //~v44kI~
    newposy=Ppcw->UCWrcsry-FILEHDRLINENO-colslinesw;   //csr line  //~v44kI~
    csrline=newposy;		//csr line offset                      //~v60vI~
    oldcsrline=pfc->UFCcsrline;                                    //~vbi3R~
    if (csrline==oldcsrline)                                       //~vbi3I~
    	pfc->UFCcsrlineold=0;                                      //~vbi3I~
    else                                                           //~vbi3I~
    	pfc->UFCcsrlineold=oldcsrline;                             //~vbi3R~
    pfc->UFCcsrline=csrline;                                       //~vbi3I~
    csrcols=newposx;		//csr column                           //~va3jI~
//case for csr line excluded                                       //~v507I~
	plhcsr=pfc->UFCcsrplh;	//csr set requested                    //~v507I~
    if (plhcsr && UCBITCHK(plhcsr->ULHflag2,ULHF2EXCLUDED))	//excluded//~v507I~
	    pfc->UFCcsrplh=getdisplayline(plhcsr,-1,0);	//back to EXCLUDE line//~v507I~
    vhexplhctr=0;		//for scroll                               //~v60vR~
    vhexplhctrcsr=0;	//for scroll by CSR pos                    //~v60vI~
#ifdef UTF8UCS2                                                    //~va3sI~
    uviom_notify(UVIOMNO_VHEXCSRPOS,-1,-1);//reset                 //~va3sI~
#endif                                                             //~va3sI~
	for (line=0;line<maxline;line++,psd++,plh=UGETQNEXT(plh))   //~5126I~
	{                                                           //~5126I~
		if (!plh)                                               //~5126I~
			break;                                              //~5126I~
//*redraw start line process                                       //~v0hfM~
        if (plhdrawstart)  //draw start plh                        //~v0hfM~
        {                                                          //~v0hfM~
            if (!drawstartsw && plh==plhdrawstart)  //draw start plh//~v0hfM~
            {                                                      //~v549I~
            	if (UCBITCHK(pfc->UFCflag,UFCFISRTDRAW))           //~v0hfM~
                	drawstartsw=2;	//no need to draw after end-of-file//~v0hfM~
                else	                                           //~v0hfM~
                	drawstartsw=1;                                 //~v0hfM~
            }                                                      //~v549I~
            if (drawstartsw)                                       //~v0hfM~
                UCBITON(plh->ULHflag,ULHFDRAW); //redraw           //~v0hfM~
		}                                                          //~v0hfM~
		if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//excluded  //~5126I~
		{                                                       //~5126I~
			line--;                                             //~5126I~
			psd--;                                              //~5126I~
			continue;                                           //~5126I~
		}                                                       //~5126I~
		psd->USDbuffc=plh;                                      //~5126I~
        UCBITOFF(psd->USDflag2,(USDF2VHEXLINE1|USDF2VHEXLINE2));//clear vhex id//~v60vR~
//*csr set req                                                  //~5126I~
		if (plh==pfc->UFCcsrplh)	//csr set requested         //~5126I~
        {                                                          //~v44kI~
//  		csrfldtopline=line+2;	//later csrfldtop              //~v11NR~
    		csrfldtopline=line+2+colslinesw;	//later csrfldtop  //~v11NI~
            newposy=-1;     //out of file area                     //~v44kI~
            if (pfc->UFCcsrfldno==1)                               //~v44kI~
            {                                                      //~v44kI~
				newposx=csronthefldchk(Ppcw,csrfldtopline,1,pfc->UFCcsroffs)-linenosz; //get new pos//~v44kR~
            	if (newposx>=0)                                    //~v44kR~
	            	newposy=line;                                  //~v44kR~
            }                                                      //~v44kI~
        }                                                          //~v44kI~
#ifdef UTF8UCS2                                                    //~va3jI~
        swligaturemode=(UTF_COMBINEMODE()||OPT_ISLIGATUREON());    //~va6uM~
    #ifdef WXEXXE                                                  //~va6uM~
    #else                                                          //~va6uM~
      #ifdef W32                                                   //~vb5aI~
      #else                                                        //~vb5aI~
        if (!swutf8file)                                           //~va6uR~
        	swligaturemode=0;   //no redraw required               //~va6uI~
      #endif                                                       //~vb5aI~
    #endif                                                         //~va6uM~
        swutf8orligaturemode=swutf8file||swligaturemode;
        if (line==csrline)  //csr line                             //~va3jI~
        {                                                          //~va3jI~
            if (                                                   //~va3jR~
//    		    swutf8file                                         //~va3jR~//~va6uR~
      		    swutf8orligaturemode
//          &&  csrcols>=0                                         //~va3jI~
//          &&  (UTF_COMBINEMODE()||UTF_LIGATUREMODE())            //~va3jI~//~va3uR~
//          &&  (UTF_COMBINEMODE()||OPT_ISLIGATUREON())            //~va3uR~
			&&  plh->ULHtype==ULHTDATA	//file data                //~va3jI~
            )                                                      //~va3jI~
//              if (csrcols>=0)   //csr is not on lineno fld       //~vbzSR~
              {
                UTRACEP("file23 csrline nonvhex draw line=%d,linenor=%d\n",line,plh->ULHlinenor); //~va3jI~
                UCBITON(plh->ULHflag,ULHFDRAW); //redraw for combinechar or ligature//~va3jI~
      		   if (!vhexmode && swligaturemode)	//process vhexmode another way//~va6uR~
                plh->ULHvhexcsrlinetype|=USDF2CSRLINE;	//previous csrline id
              }
        }                                                          //~va3jI~
        else
        {
      	  if (!vhexmode)	//process vhexmode another way         //~va6uI~
        	if (plh->ULHvhexcsrlinetype & USDF2CSRLINE)	//redraw when csr line changed for non vhex mode
            {
                UCBITON(plh->ULHflag,ULHFDRAW); //redraw for combinechar or ligature
//              plh->ULHvhexcsrlinetype &= ~USDF2CSRLINE;   //drawn previous csrline//~vb28R~
                UCBITOFF(plh->ULHvhexcsrlinetype,USDF2CSRLINE);   //drawn previous csrline//~vb28I~
	            UTRACEP("file23 csrline nonvhex prevline draw line=%d,linenor=%d\n",line,plh->ULHlinenor);
            }
        }
#endif                                                             //~va3jI~
        if (vhexmode)	//virtical hex display mode                //~v60vI~
        {                                                          //~v60vI~
			if (line==csrline                                      //~v60vR~
            ||  plh==pfc->UFCcsrplh)	//csr set requested        //~v60vI~
            	vhexplhctrcsr=vhexplhctr;	//csr line plh offset  //~v60vI~
			if (plh->ULHtype==ULHTDATA)	//file data                //~v60vI~
            {                                                      //~v60vI~
#ifdef UTF8UCS2                                                    //~va20I~
//    			if (swutf8file)                                    //~va20I~
      			if (swutf8orligaturemode)
        	    	if (line==newposy)   //csr line                //~va20I~
                    {                                              //~va20I~
                		vhexcsrlineplh=plh;                        //~va20I~
                        vhexcsrlinetype=0;                         //~va20I~
                    }                                              //~va20I~
#endif                                                             //~va20I~
				if (line+1<maxline)                                //~v60vI~
                {                                                  //~v60vI~
                    line++;	//screen line count                    //~v60vI~
                    if (line==csrline)                             //~v60vI~
		            	vhexplhctrcsr=vhexplhctr;	//csr line plh offset//~v60vR~
                    psd++;                                         //~v60vI~
#ifdef UTF8UCS2                                                    //~va20I~
//    				if (swutf8file)                                //~va20R~
      				if (swutf8orligaturemode)
		            	if (line==newposy)   //csr line            //~va20I~
                        {                                          //~va20I~
        	        		vhexcsrlineplh=plh;                    //~va20I~
	                        vhexcsrlinetype=USDF2VHEXLINE1;        //~va20I~
                        }                                          //~va20I~
#endif                                                             //~va20I~
			        UCBITOFF(psd->USDflag2,USDF2VHEXLINE2);//1st of vhex display line//~v60vR~
			        UCBITON(psd->USDflag2,USDF2VHEXLINE1);//1st of vhex display line//~v60vI~
					psd->USDbuffc=plh;                             //~v60vI~
                    if (line+1<maxline)                            //~v60vR~
                    {                                              //~v60vI~
    	                line++;                                    //~v60vI~
	                    if (line==csrline)                         //~v60vI~
			            	vhexplhctrcsr=vhexplhctr;	//csr line plh offset//~v60vR~
#ifdef UTF8UCS2                                                    //~va20I~
//    					if (swutf8file)                            //~va20I~
      					if (swutf8orligaturemode)
			            	if (line==newposy)   //csr line        //~va20I~
            	            {                                      //~va20I~
        	    	    		vhexcsrlineplh=plh;                //~va20I~
	                	        vhexcsrlinetype=USDF2VHEXLINE2;    //~va20I~
                        	}                                      //~va20I~
#endif                                                             //~va20I~
                        psd++;                                     //~v60vI~
                        UCBITOFF(psd->USDflag2,USDF2VHEXLINE1);//1st of vhex display line//~v60vR~
                        UCBITON(psd->USDflag2,USDF2VHEXLINE2);//1st of vhex display line//~v60vI~
                        psd->USDbuffc=plh;                         //~v60vI~
                    }//2 line more space                           //~v60vI~
                    else                                           //~v60vI~
                        UCBITON(pfc->UFCflag2,UFCF2VHEXINCOMP); //for page scroll//~v60vI~
                }//1line more space                                //~v60vI~
                else                                               //~v60vI~
                    UCBITON(pfc->UFCflag2,UFCF2VHEXINCOMP); //for page scroll//~v60vI~
            }//data line                                           //~v60vI~
        	vhexplhctr++;                                          //~v60vM~
        }//vhex mode                                               //~v60vI~
    }                                                           //~5126I~
	drawline=line;                                              //~5126R~
	psd=psdline;	//restore                                   //~5126I~
	plh=pfc->UFCcurtop;		//restore top line to be display    //~5126I~
	pfc->UFCcsrplh=0;	//csr set request processed             //~5126I~
	pfc->UFCdrawplh=0;	//drawstart processed                      //~v0hfR~
    UCBITOFF(pfc->UFCflag,UFCFISRTDRAW);	//chked                //~v0hfI~
                                                                //~5126I~
    pfc->UFCvhexplhctr=vhexplhctr;			    //displayed plh when vhexmode//~v60vI~
    pfc->UFCvhexplhctrcsr=vhexplhctrcsr;		//csr pos for scroll//~v60vI~
    pfc->UFCmaxline=line;			    //displayed scr plh no  //~5126I~
//  Ppcw->UCWmaxline=min(line+FILEHDRLINENO,Ppcw->UCWheight);//scr lineno//~v11NR~
    Ppcw->UCWmaxline=min(line+Ppcw->UCWfilehdrlineno,Ppcw->UCWheight);//scr lineno//~v11NI~
  	if (Ppcw==Gcappcw)				//block mode                //~5127R~
		capsavecsrpos(Ppcw);	//set/reset block flag          //~5126I~
//*draw file line                                               //~5126I~
//	linesw=(UGETQCTR(&pfh->UFHlineque)>=10000);                    //~v094R~
//	linesw=(UGETQCTR(&pfh->UFHlineque+pfh->UFHsline)>=10000);      //~v09fR~
//	li=UGETQCTR(&pfh->UFHlineque+pfh->UFHsline);    //line ct      //~v0igR~
//if (UCBITCHK(pfh->UFHflag4,UFHF4XLINENO))                        //~v410R~
//  xlinenosw=1;                                                   //~v410R~
//else                                                             //~v410R~
  if (!xlinenosw)                                                  //~v410I~
  {                                                                //~v10XI~
//  xlinenosw=0;                                                   //~v410R~
//	li=UGETQCTR(&pfh->UFHlineque)+pfh->UFHsline;    //line ct      //~v40YR~
//	li=((PULINEH)UGETQEND(&pfh->UFHlineque))->ULHlinenor;          //~v53eR~
  	li=((PULINEH)UGETQPREV(UGETQEND(&pfh->UFHlineque)))->ULHlinenor;//~v53eI~
  	li/=10000;                  //sufficient by minimum 4 digit?   //~v09fI~
    linesw=0;                                                      //~v09fI~
  	while (li)                                                     //~v09fI~
    {                                                              //~v09fI~
        linesw++;               //required digit                   //~v09fI~
        li/=10;                                                    //~v09fI~
    }                                                              //~v09fI~
//  if (Soldlinesw!=linesw)                                        //~v90jR~
    if (pfh->UFHlinenosw!=(UCHAR)linesw)                           //~v90jI~
    {                                                              //~v10JI~
//  	Soldlinesw=linesw;                                         //~v90jR~
    	pfh->UFHlinenosw=(UCHAR)linesw;                            //~v90jI~
	    fulldrawsw=1;                                              //~v10JI~
	}                                                              //~v10JI~
    sprintf(linenowk,"%%%02dld|",ULHLINENOSZ-1);	//long         //~v53dR~
  }//not hexlineno                                                 //~v10XM~
  else      //helineno                                             //~v53dR~
  {                                                                //~v53dR~
  	linesw=16;		//hex id                                       //~v53dR~
	if (hexoptupper)                                               //~v53dR~
//  	strcpy(linenowk,"%07lX|");                                 //~vaz0R~
    	strcpy(linenowk,"%07X|");                                  //~vaz0I~
    else                                                           //~v53dR~
//  	strcpy(linenowk,"%07lx|");                                 //~vaz0R~
    	strcpy(linenowk,"%07x|");                                  //~vaz0I~
  }                                                                //~v53dR~
    pfh->UFHlinenowk[0]=(UCHAR)linesw;  	//save for xprint,renum seti/setr//~v53dR~
    strcpy(pfh->UFHlinenowk+1,linenowk);                           //~v53dR~
	Sfileupctr=pfh->UFHupctr;		//for display/clear linenosz//~5105R~
	Sfileupundoctr=pfh->UFHupundoctr;		//for display/clear linenosz//~5105R~
	revctr=pfh->UFHfindctr;		//for display/clear linenosz    //~5422R~
//  if (revctr==pfh->UFHfindctrme)	//multi reverse continueing    //~v62cR~
//  	if (pfh->UFHfindctrms>0 && pfh->UFHfindctrms<=pfh->UFHfindctrme)	//reverse from multi reverse start//~v62cR~
//      	revctr=pfh->UFHfindctrms;	//reverse from multi reverse start//~v62cR~
//*block reverse                                                //~5123I~
//  sprintf(linenowk,"%%%02dld|",ULHLINENOSZ-1);	//long         //~v53dR~
	for (line=0;line<drawline;line++,psd++)                     //~5126R~
	{
        vhexpsdid=UCBITCHK(psd->USDflag2,(USDF2VHEXLINE1|USDF2VHEXLINE2));//vhex display hex line sw//~v60vR~
		plh=psd->USDbuffc;                                      //~5126R~
//*reset previous current-update-line
//  	if (plh->ULHupctr                                          //~v08fR~
//  	&&  plh->ULHupctr == Sfileupctr-1)	//previous update      //~v08fR~
//  		UCBITON(plh->ULHflag,ULHFDRAW);	//redraw for clear hilite//~v08fR~
    	if  (UCBITCHK(plh->ULHflag3,ULHF3CURUPDATE)	//cur update   //~v08fI~
		&&  plh->ULHupctr < Sfileupctr)	//not latest update now    //~v08fR~
        {                                                          //~v08fI~
			UCBITON(plh->ULHflag,ULHFDRAW);	//redraw for clear hilite//~v08fR~
			UCBITOFF(plh->ULHflag3,ULHF3CURUPDATE);	//once drwan   //~v08fI~
		}                                                          //~v08fI~
//*reset previous current-undo-line                             //~5105I~
//  	if (plh->ULHupundoctr                                      //~v08fR~
//  	&&  plh->ULHupundoctr == Sfileupundoctr-1)	//previous update//~v08fR~
    	if  (UCBITCHK(plh->ULHflag3,ULHF3CURUNDO)	//cur undo     //~v08fI~
		&&  plh->ULHupundoctr < Sfileupundoctr)		//not latest undo now//~v08fI~
        {                                                          //~v08fI~
			UCBITON(plh->ULHflag,ULHFDRAW);	//redraw for clear hilite//~5105I~
			UCBITOFF(plh->ULHflag3,ULHF3CURUNDO);	//once drwan   //~v08fI~
		}                                                          //~v08fI~
//*reset previous current-found-line
		if (UCBITCHK(plh->ULHflag,ULHFCURFOUND)	//cur found line
		&&  plh->ULHrevctr < revctr)		//but new find occured//~5422R~
		{
			UCBITON(plh->ULHflag,ULHFDRAW);		//redraw for clear found
			UCBITOFF(plh->ULHflag,ULHFCURFOUND);//cleared
		}
		if (UCBITCHK(plh->ULHflag5,ULHF5DRAWHEX))   //csr pos reveres//~v79eR~
		{                                                          //~v79eI~
        	if (!vhexpsdid)	//not vhex line                        //~v79eI~
            {                                                      //~v79eI~
				UCBITON(plh->ULHflag,ULHFDRAW);		//redraw for clear found//~v79eR~
				UCBITOFF(plh->ULHflag5,ULHF5DRAWHEX);//cleared     //~v79eR~
            }                                                      //~v79eI~
UTRACEP("HHEX drawvhex plhlineno=%d,lineno=%d,psdid=%d\n",plh->ULHlinenor,line,vhexpsdid);//~v79eR~
		}                                                          //~v79eI~
	  	if (Ppcw==Gcappcw)				//block mode            //~5128R~
			caplinechk(Ppcw,plh);	//set/reset block flag      //~5126R~
        Shexcsrpos=0;              //id of hexmode csr line        //~v440I~
        Sdatacsrpos=-1;            //not hex mode                  //~v443I~
#ifdef UTF8SUPPH                                                   //~va1cR~
        Sdatacsrpos1=-1;           //for dbcs another byte         //~va1cR~
#endif                                                             //~va1cR~
        Sdatacsrpos2=-1;           //for dbcs another byte         //~v450I~
//      Sdatacsrposu8=-1;          //for combinechar attr setting around csr pos//~va3rI~//~va3sR~
        UCBITOFF(psd->USDflag2,USDF2CSRLINE);//clear csrline id    //~v45kI~
//UTRACEP("HHEX hexmodesw=%d,lineno=%d,line=%d,newposy=%d,drawsw=%d\n",hexmodesw,plh->ULHlinenor,line,newposy,UCBITCHK(plh->ULHflag,ULHFDRAW));//~v79eR~
        if (hexmodesw)                                             //~v440I~
            if (line==newposy)   //csr line                        //~v44kR~
            {                                                      //~v440I~
				if (!UCBITCHK(plh->ULHflag,ULHFDRAW))//not line update//~v45kR~
                {                                                  //~v45kI~
					UCBITON(plh->ULHflag,ULHFDRAW);		//redraw for clear found//~v45kR~
				  if (!fulldrawsw)                                 //~v45yI~
		    		UCBITON(psd->USDflag2,USDF2CSRLINE);//draw by hex csr display reason//~v45kI~
                }                                                  //~v45kI~
                Shexcsrpos=1;                                      //~v440I~
            }                                                      //~v440I~
#ifdef UTF8UCS2                                                    //~va20I~
        if (vhexmode                                               //~va20I~
		&&  !fulldrawsw                                            //~va20I~
//      &&  swutf8file                                             //~va20I~
        &&  swutf8orligaturemode
           )                                                       //~va20I~
        {                                                          //~va20I~
//        	vhexdrawsw=0;   //dont clear set by ULHFDRAW           //~va6TR~
            vhexdrawsw2=plh->ULHvhexcsrlinetype;	//previous csr line//~va20I~
UTRACEP("drawflag=%x,plhcsrlinetype=%x,vhexcsrlinetype=%x,vhexpsdid=%x\n",//~va20I~
		UCBITCHK(plh->ULHflag,ULHFDRAW), plh->ULHvhexcsrlinetype,vhexcsrlinetype,vhexpsdid);//~va20I~
UTRACEP("plh=%p,csrlineplh=%p,lineno=%d\n",plh,vhexcsrlineplh,plh->ULHlinenor);//~va20I~
            if (plh==vhexcsrlineplh                                //~va20I~
			||  UCBITCHK(plh->ULHflag,ULHFDRAW))                   //~va20I~
            {                                                      //~va20I~
                if (!vhexcsrlinetype) //csr is on dataline         //~va20I~
                {                                                  //~va20I~
                   if (csrcols>=0)	//csr is not on lineno fld     //~va6xM~
                   {                                               //~va6xM~
                    vhexdrawsw=1; //draw also char line for hex csr pos calc//~va20I~
	            	if (!vhexpsdid)	//drawing char line            //~va20I~
		                plh->ULHvhexcsrlinetype|=(USDF2VHEXLINE1|USDF2VHEXLINE2);	//redraw required if csr line changed//~va20I~
                    if (swligaturemode)                            //~va6uI~
		                plh->ULHvhexcsrlinetype|=(USDF2CSRLINE);	//redraw required if csr line changed//~va6uI~
                   }                                               //~va6xI~
					UTRACEP("%s:set vhexdrawsw1 line=%d,csrline=%d,vhexdrawsw=%d,csrcols=%d\n",UTT,line,csrline,vhexdrawsw,csrcols);//~vbzSR~
                }                                                  //~va20I~
                else				//csr is on hexline            //~va20I~
                {                                                  //~va20I~
                	if (!vhexpsdid)	//char line drawing            //~va20I~
                    {                                              //~va20I~
                      if (csrcols>=0)	//csr is not on lineno fld //~va6xM~
                      {                                            //~va6xM~
                    	vhexdrawsw=1;  //draw char line            //~va20I~
		                plh->ULHvhexcsrlinetype|=(USDF2CSRLINE);	//redraw required if csr line changed//~va20I~
						if (UCBITCHK(plh->ULHflag,ULHFDRAW))	//updated//~va20I~
			                plh->ULHvhexcsrlinetype|=(USDF2VHEXLINE1|USDF2VHEXLINE2);	//redraw required if updated//~va20I~
                      }                                            //~va6xI~
						UTRACEP("%s:set vhexdrawsw2 line=%d,csrline=%d,vhexdrawsw=%d,csrcols=%d\n",UTT,line,csrline,vhexdrawsw,csrcols);//~vbzSI~
                    }                                              //~va20I~
                    else //hex line drawing                        //~va20I~
                    {                                              //~va20I~
                    	if (vhexdrawsw2 & vhexpsdid)	//previously csr drawn//~va20I~
                        {                                          //~va20I~
			                plh->ULHvhexcsrlinetype=(UCHAR)(plh->ULHvhexcsrlinetype &~ vhexpsdid);//~va20I~
	                    	vhexdrawsw=1;  //draw to clear hex csr //~va20I~
                        }                                          //~va20I~
                    }                                              //~va20I~
                }                                                  //~va20I~
            }                                                      //~va20I~
            else                                                   //~va20I~
            if (vhexdrawsw2)	//previous csr line                //~va20I~
            {                                                      //~va20I~
	            vhexdrawsw3=!vhexpsdid?USDF2CSRLINE:vhexpsdid;     //~va20I~
				if (vhexdrawsw3 & vhexdrawsw2)	//hex line drawing //~va20I~
                {                                                  //~va20I~
                	plh->ULHvhexcsrlinetype=(UCHAR)(vhexdrawsw2 & ~vhexdrawsw3);//~va20I~
                    vhexdrawsw=1;                                  //~va20I~
                }                                                  //~va20I~
UTRACEP("previousline drawsw=%d,vhexdrawsw3=%d\n",vhexdrawsw,vhexdrawsw3);                    //~va6xI~//~vbzSR~
            }                                                      //~va20I~
UTRACEP("%s:line=%d,csrline=%d,vhexdrawsw=%d,sw2=%x,plhcsrlinetype=%x,csrcols=%d\n",         //~va20I~//~vafcR~//~vbzSR~
		UTT,line,csrline,vhexdrawsw,vhexdrawsw2,plh->ULHvhexcsrlinetype,csrcols);//~va20I~//~vafcR~//~vbzSR~
        }                                                          //~va20I~
#endif  //UTF8UCS2                                                 //~va20I~
        if (pfh->UFHtype==UFHTCMDHIST)                             //~vbi3R~
        {                                                          //~vbi3R~
        	if (line==csrline)                                     //~vbi3R~
            {                                                      //~vbi3R~
        		if (csrline!=oldcsrline)	//line changed         //~vbi3R~
                {	                                               //~vbi3R~
					UCBITON(plh->ULHflag,ULHFDRAW);                //~vbi3R~
                }                                                  //~vbi3R~
            }                                                      //~vbi3R~
            else                                                   //~vbi3R~
        	if (line==oldcsrline)   	//old csr line             //~vbi3R~
            {                                                      //~vbi3R~
        		if (line!=csrline)	//line changed                 //~vbi3R~
                {                                                  //~vbi3R~
					UCBITON(plh->ULHflag,ULHFDRAW);                //~vbi3R~
                }                                                  //~vbi3R~
            }                                                      //~vbi3R~
        }                                                          //~vbi3R~
//UTRACEP("HHEX drawsw=%d\n",UCBITCHK(plh->ULHflag,ULHFDRAW));     //~v79eR~
//  	if (!UCBITCHK(Ppcw->UCWflag,UCWFDRAW)	//screen full display//~v08dR~
		if (!fulldrawsw                                            //~v08dI~
		&&  !UCBITCHK(plh->ULHflag,ULHFDRAW))	//updated
          if (!vhexmode||!vhexdrawsw)                              //~v60vR~
			continue;
//#ifdef UTF8UCS2                                                    //~va20I~//~va6WR~
//      if (!swutf8file)   //not utf                                 //~va20I~//~va6WR~
//#endif //utf8                                                      //~va20I~//~va6WR~
        if (vhexmode)      // virtical hex display mode            //~v60vR~
        {                                                          //~v60vI~
			if (plh->ULHtype==ULHTDATA)	//file data                //~v60vI~
            {                                                      //~v60vI~
                if (!vhexpsdid) //char display line                //~v60vR~
                    vhexdrawsw=1;   //draw next 2 hex line         //~v60vR~
                else                                               //~v60vR~
                    if (vhexpsdid & USDF2VHEXLINE2) //2nd of vhex display line//~v60vR~
                        vhexdrawsw=0;   //reset for next char line //~v60vR~
        	}                                                      //~v60vI~
        }                                                          //~v60vI~
UTRACEP("filedraw row=%d,col=%d,csrcol=%d,line=%d,plhlineno=%d,drawflag=%x\n",Ppcw->UCWrcsry,Ppcw->UCWrcsrx,csrcols,line,plh->ULHlinenor,UCBITCHK(plh->ULHflag,ULHFDRAW));           //~v79eR~//~va50R~//~va6xR~
		UCBITOFF(plh->ULHflag,ULHFDRAW);		//already displayed
	    UCBITON(psd->USDflag2,USDF2DRAW);		//req dispaly
//#ifdef UNX                                                       //~v45kR~
//      if (line==Ppcw->UCWrcsry-FILEHDRLINENO-colslinesw)   //csr line//~v45kR~
//			UCBITON(plh->ULHflag,ULHFDRAW);		//next time redraw //~v45kR~
//#endif                                                           //~v45kR~
//*dbcs/tab chk and expand                                      //~5102R~
		if (filechktabdbcs(plh)==UALLOC_FAILED)                 //~v04dR~
        	return UALLOC_FAILED;                               //~v04dR~
//*lineno edit
		if (plh->ULHtype==ULHTDATA)	//file data
		{
    	  if (UCBITCHK(plh->ULHflag4,ULHF4PROTLINE))//protected(change line attr)//~v0izI~
		    UCBITON(psd->USDflag2,USDF2PROTFHDR);	//2nd fld protected//~v0izI~
          else                                                     //~v0izI~
		    UCBITOFF(psd->USDflag2,USDF2PROTFHDR);	//2nd fld protected
    	  if (xlinenosw)	//hex offset lineno display            //~v10XI~
          {                                                        //~v10XI~
//            if (UCBITCHK(plh->ULHflag,ULHFMOVE)                  //~v178R~
//            ||  UCBITCHK(plh->ULHflag2,ULHF2INSERT))             //~v178R~
//                strcpy(linenowk2,"       |");                    //~v178R~
//            else                                                 //~v178R~
//  		if (hexoptupper)                                       //~v53dR~
//  			sprintf(linenowk2,"%07lX|",plh->ULHoffs & 0x0fffffff);//hex line offset//~v53dR~
//          else                                                   //~v53dR~
//  			sprintf(linenowk2,"%07lx|",plh->ULHoffs & 0x0fffffff);//hex line offset//~v53dR~
//    		sprintf(linenowk2,linenowk,plh->ULHoffs & 0x0fffffff);//hex line offset//~vaz0R~
      		sprintf(linenowk2,linenowk,(UINT)(plh->ULHoffs & 0x0fffffff));//hex line offset//~vaz0I~
          }                                                        //~v10XI~
          else                                                     //~v10XI~
          {                                                        //~v10XI~
			if (linesw)				//over 10000;                     //~v069R~
            {                                                      //~v09fI~
			  if (linesw==1)                                       //~v09fI~
				li=plh->ULHlinenor*100+min(99,plh->ULHsuffix);        //~v069R~
			  else	                                               //~v09fI~
			  if (linesw==2)                                       //~v09fI~
				li=plh->ULHlinenor*10+min(9,plh->ULHsuffix);       //~v09fI~
			  else	                                               //~v09fI~
				li=plh->ULHlinenor;                                //~v09fI~
			}                                                      //~v09fI~
			else                                                      //~v069R~
        	  if (UCBITCHK(pfh->UFHflag5,UFHF5COB))                //~v41pI~
              {                                                    //~v42zI~
				li=plh->ULHlinenor*1000+min(99,plh->ULHsuffix)*10;//max suffix=99//~v41pI~
                if (linenosz==SPFCOBNUMFLDLEN) //small lineno (<999)//~v42zI~
                    li*=10;     //shift to left by one digit       //~v42zI~
              }                                                    //~v42zI~
              else                                                 //~v41pI~
				li=plh->ULHlinenor*1000+min(999,plh->ULHsuffix);      //~v069R~
            len2=                                                  //~v41pI~
			sprintf(linenowk2,linenowk,li);//lineno edit
            if (len2>ULHLINENOSZ)                                  //~v41pI~
            	memcpy(linenowk2,linenowk2+len2-ULHLINENOSZ,ULHLINENOSZ);//~v41pI~
          }//normal lineno                                         //~v10XI~
			memcpy(plh->ULHlineno,linenowk2,ULHLINENOSZ);//lineno edit
			if (plh->ULHupctr)
        	  if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2))//~v0agI~
				*(plh->ULHlineno+ULHLINENOSZ-1)=UPDATEID;       //~5107R~
              else                                                 //~v0agI~
        	  	if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))           //~v0agR~
					*(plh->ULHlineno+ULHLINENOSZ-1)=SPLITUPDATEID; //~v0agI~
              	else                                               //~v0agI~
					*(plh->ULHlineno+ULHLINENOSZ-1)=SPLITTOPUPDID; //~v0agI~
            else                                                //~5107I~
        	  	if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))           //~v0agI~
					*(plh->ULHlineno+ULHLINENOSZ-1)=SPLITID;    //~5107I~
              	else                                               //~v0agI~
	        	  	if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))       //~v0agR~
						*(plh->ULHlineno+ULHLINENOSZ-1)=SPLITTOPID;//~v0agI~
			offs=pfc->UFCleft;
			len=max(0,min(Ppcw->UCWwidth-linenosz,plh->ULHlen-pfc->UFCleft));//~v069R~
#ifdef UTF8UCS2                                                    //~va20I~
    		if (swutf8file)                                        //~va20I~
          		if (vhexpsdid)		//hexline of vhex mode         //~va20I~
                {                                                  //~va20I~
              		if (plh->ULHlen>pfc->UFCleft)                  //~va20R~
    					len=min(Ppcw->UCWwidth-linenosz,plh->ULHlen-pfc->UFCleft);//~va20R~
              		else                                           //~va20I~
    					len=0;                                     //~va20I~
                }                                                  //~va20I~
#endif                                                             //~va20I~
			len2=Ppcw->UCWwidth-linenosz-len;//len after data   //~v069R~
		}
		else
		{
		    UCBITON(psd->USDflag2,USDF2PROTFHDR);	//2nd fld protected
			offs=0;
			len=max(0,Ppcw->UCWwidth-linenosz);                 //~v069R~
			len2=0;							//after data len
		}
		memset(pcd=psd->USDdbcs,0,ULHLINENOSZ);//dbcsid
		memcpy(pc=psd->USDdata,plh->ULHlineno,ULHLINENOSZ);	//lineno
//lineno column shift                                           //~v069I~
		if (linenosz)                                           //~v069I~
        {                                                       //~v069I~
        	if (linenosz<ULHLINENOSZ) //short lineno field sz         //~v069R~
            {                                                         //~v069I~
	    	  if (xlinenosw)	//hex offset lineno                //~v10XI~
				memcpy(pc,pc+ULHLINENOSZ-linenosz,(UINT)(linenosz-1));	//lineno//~v10XR~
          	  else                                                 //~v10XI~
    	    	if (linenosz<5+linesw) //short lineno field sz        //~v069I~
					memcpy(pc,pc+(5+linesw-linenosz),(UINT)(linenosz-1));	//lineno//~v069R~
				*(pc+linenosz-1)=*(pc+ULHLINENOSZ-1);	//update sign //~v069R~
            }                                                         //~v069I~
			if (UCBITCHK(plh->ULHflag,ULHFLINECMD))//line cmd input//~v069M~
            {                                                      //~va7jI~
//  			memcpy(pc,plh->ULHlinecmd,(UINT)(linenosz-1));  //~v069R~//~va7jR~
          	  if (!vhexpsdid)//vhex display hex line sw            //~va7jI~
    			filecvlcmd(0,pfh,pc,pcd,plh->ULHlinecmd,linenosz-1);//~va7jI~
            }                                                      //~va7jI~
          	if (vhexpsdid)//vhex display hex line sw               //~v60vI~
				memset(pc,' ',(UINT)(linenosz-1));                 //~v60vI~
	        if (UCBITCHK(plh->ULHflag6,ULHF6CHLCPU8CMD))           //~vbi3R~
     	       *(pc+linenosz-1)=U8CMDID;                           //~vbi3I~
			pc+=linenosz;                                       //~v069R~
			pcd+=linenosz;                                      //~v069R~
        }                                                       //~v069I~
//*data edit
#ifdef UNX                                                         //~v30aI~
        celldrawsw=1;       //for the case len=0                   //~v30aI~
#else                                                              //~v30aI~
        celldrawsw=0;                                              //~v09RI~
#endif //UNX                                                       //~v30aI~
		pdata0=pc;			//data start addr                      //~v440I~
		pdbcs0=pcd;     	//dbcs start addr on file data area of psd//~v450R~
        Shexoffs=0;                                                //~v440R~
		if (len)
		{
#ifdef UTF8UCS2                                                    //~va20I~
      		Svhexcsrsw=0;	//utf code length differ from display column,so display csr pos//~va20I~
    		if (swutf8file)                                        //~va20R~
            {                                                      //~va20I~
          		if (vhexpsdid)                                     //~va20I~
          		{                                                  //~va20I~
                    if (plh==vhexcsrlineplh)                       //~va20I~
                    {                                              //~va20I~
                        Svhexcsrsw=1;                              //~va20I~
                        Svhexcolx=Svhexcolxsv;  //gotten at char line//~va20I~
                        Svhexcold1=-1;           //avoid set attr by old column//~va20I~
                        Svhexcold2=-1;           //avoid set attr by old column//~va20I~
                    }                                              //~va20I~
                }                                                  //~va20I~
                else                                               //~va20I~
                {                                                  //~va20I~
                    if (plh==vhexcsrlineplh)                       //~va20I~
                    {                                              //~va20I~
                        Svhexcsrsw=1;                              //~va20I~
                        Svhexcolx=-1;           //avoid set attr by old column//~va20I~
                        xeutf_getvhexcsrposdbcs(vhexcsrlinetype,Ppcw,plh,offs,newposx,&Svhexcold1,&Svhexcold2,&Svhexcolxsv); //get pc,pcd);//vhex display line setup;//~va20R~
                        Svhexcold1sv=Svhexcold1;    //to display hex on hdr line//~va20I~
                        if (vhexcsrlinetype)	//csr on hexline   //~va3sI~
            				uviom_notify(UVIOMNO_VHEXCSRPOS,Svhexcold1+Ppcw->UCWorgx+linenosz,line+Ppcw->UCWfilehdrlineno+Ppcw->UCWorgy);//~va3sI~
                    }                                              //~va20I~
//  				if (line==csrline)                             //~va3rI~//~va3sR~
//      				Sdatacsrposu8=newposx;          //for combinechar attr setting around csr pos//~va3rI~//~va3sR~
                }                                                  //~va20I~
          	}//swu8                                                //~va20I~
          if (!vhexpsdid)                                          //~va20I~
#endif //UTF8UCS2                                                  //~va20I~
          {                                                        //~va20I~
			memcpy(pc,plh->ULHdata+offs,(UINT)len);//data
			memcpy(pcd,plh->ULHdbcs+offs,(UINT)len);	//dbcs id tbl
//  		if (UCBITCHK(Gopt,GOPTTABDISPLAY))                     //~v09UR~
#ifdef UTF8UCS2                                                    //~va20I~
                tdopt=UCBITCHK(pfh->UFHflag4,UFHF4BIN);            //~va20I~
                if (swutf8file)                                    //~va20R~
	                tdopt=FILETDO_UTF8;                            //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                celldrawsw=tabdisplay(plh,pc,pcd,len,tdopt);       //~va50I~
#else                                                              //~va50I~
                celldrawsw=tabdisplay(pc,pcd,len,tdopt);           //~va20I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
#else                                                              //~va20I~
                celldrawsw=                                        //~v09RI~
//  			tabdisplay(pc,pcd,len);                            //~v20UR~
    			tabdisplay(pc,pcd,len,UCBITCHK(pfh->UFHflag4,UFHF4BIN));//~v20UI~
#endif                                                             //~va20I~
          }//!vhex                                                 //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
	      if (Svhexcsrsw)     //                                   //~va20I~
            celldrawsw=1;   //For wiindowns,to draw charline csr when opt eol is OFF//~va20I~
#endif                                                             //~va20I~
                                                                   //~v302I~
#ifdef UNX                                                         //~v302I~
            celldrawsw=1;   //as a result,use mvaddchnstr          //~v302I~
#endif //UNX                                                       //~v302I~
            if (offs+len>=mergin)           //data or crlf into mergin//~v0buI~
            	celldrawsw=2;				//mergin draw          //~v0buI~
//          if (bndsoffs1>=0||bndsoffs2>=0)	//bounds specified     //~v76uR~
            if (bndsoffs1>=0||bndsoffs2>0)	//bounds specified     //~v76uR~
            	celldrawsw=2;				//mergin draw          //~v74EI~
            if (Sprotlen)       //prot area on display screen      //~v0ifR~
            	celldrawsw=PROTAREADRAW;				//prot area display//~v0ifI~
          if (vhexpsdid)                                           //~v60vI~
          {                                                        //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
			vhlen=Ppcw->UCWwidth-linenosz;	//output limit         //~va20R~
			filevhexdisplay(vhexpsdid,plh->ULHdata+offs,plh->ULHdbcs+offs,pc,pcd,len,&vhlen);//vhex display line setup;//~va20I~
            len2-=(vhlen-len);                                     //~va20I~
            if (len2<0)                                            //~va20I~
                len2=0;                                            //~va20I~
            len=vhlen;                                             //~va20I~
#else                                                              //~va20I~
			filevhexdisplay(vhexpsdid,plh->ULHdata+offs,plh->ULHdbcs+offs,pc,pcd,len);//vhex display line setup;//~v60vR~
#endif                                                             //~va20I~
          }                                                        //~va20I~
          else                                                     //~v60vI~
//  		setdbcssplit(pc,pcd,len,'.');   //by dbcs tbl          //~v40wR~
//*ebcfile was translated to utf8 on psd by tabdisplay             //~va50I~
//  		setdbcssplit2(pc,pcd,len,'.');	//by dbcstbl and char  //~v40wI~//~vb28R~
//  		setdbcssplit2(pc,pcd,len,'.',DISPLINEATTRID);	//by dbcstbl and char//~vb28R~
    		setdbcssplit2(pc,pcd,len,XEUTF_ERRREPCH/*'.'*/,0/*repdbcs*/);	//if replaced dbcstbl,csr dose not skip half byte//~vb28R~
  			pc+=len;
  			pcd+=len;
		}//data exist
		if (len2>0)
		{
			memset(pcd,0,(UINT)len2);
//  		*pc++=0x1b;                                            //~v19kR~
//  		*pc++=EOLID;                                           //~v217R~
//  		*pc++=(UCHAR)Seolid;                                   //~v47dR~
          if (binmodesw                                            //~v60mI~
          ||  recordmodesw                                         //~va50I~
          ||  UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))	//has follower //~v60mR~
    		*pc++=(UCHAR)Gopteolcont2;  //foldID char              //~v60mI~
          else                                                     //~v60mI~
    		*pc++=(UCHAR)Gopteol2;  //may be default               //~v47dI~
            if (UCBITCHK(Goptopt,GOPT_EOL_ATTRON)) //if ASCII off  //~v47dI~
            {                                                      //~v47dI~
            	celldrawsw=1;   //as a result,use mvaddchnstr      //~v47dI~
            	*pcd=DISPLINEATTRID;    //highlight                //~v47dI~
            }                                                      //~v47dI~
            else                                                   //~v47dM~
            if (!UCBITCHK(Goptopt,GOPT_EOL_ATTROFF)) //not explicitly off//~v47dM~
            {                                                      //~v47dM~
#ifdef UNX                                                         //~v302I~
	#ifdef LNX                                                     //~v309I~
//  		if (Gmaxcolor!=2)                                      //~v47dR~
            	*pcd=DISPLINEATTRID;    //highlight                //~v309I~
	#else                                                          //~v309I~
//          *pcd=DISPLINEATTRID;    //highlight                    //~v30bR~
            *pcd=0;                                                //~v47dI~
	#endif                                                         //~v309I~
#else                                                              //~v47dI~
            	celldrawsw=1;   //as a result,use mvaddchnstr      //~v47dI~
            	*pcd=DISPLINEATTRID;    //highlight                //~v47dI~
#endif //                                                          //~v302I~
			}//default                                             //~v47dM~
			if (--len2>0)
            {                                                      //~v440I~
				memset(pc,' ',(UINT)len2);
              	if (hexmodesw)                                     //~v440I~
              	{                                                  //~v440I~
                  if (vhexpsdid)    //vhex mode hex line           //~v70nI~
                    Shexcsrpos=-1;                                 //~v70nI~
                  else                                             //~v70nI~
                  {                                                //~v70nI~
                    if (Shexcsrpos)	//csr line                     //~v440R~
                    	Shexcsrpos=newposx;	//csr on the line of file area//~v44kR~
                    else                                           //~v440I~
                        Shexcsrpos=-1;                             //~v440I~
    				hexdata=filehexdisplay(Ppcw,pc,len2,len,plh,&Shexcsrpos,&Sdatacsrpos);//~v443R~
                    if (hexdata)                                   //~v440I~
                    {                                              //~v440I~
//                      Shexoffs=(int)((ULONG)hexdata-(ULONG)pdata0);//~v45zR~//~vafkR~
                        Shexoffs=(int)((ULPTR)hexdata-(ULPTR)pdata0);//~vafkI~
//UTRACEP("HHEX lineno=%d,Shexoffs=%d,Shexcsrpos=%d,Sdatacsrpos=%d,drawsw=%d\n",plh->ULHlinenor,Shexoffs,Shexcsrpos,Sdatacsrpos,UCBITCHK(plh->ULHflag,ULHFDRAW));//~v79eR~
                        if (Shexcsrpos>=0  //csrto be disply       //~v443R~
                        ||  Sdatacsrpos>=0)                        //~v443I~
//                          UCBITON(plh->ULHflag,ULHFDRAW);     //for reset at csr move//~v79eR~
                            UCBITON(plh->ULHflag5,ULHF5DRAWHEX);     //for reset at csr move//~v79eI~
                        if (!celldrawsw)                           //~v440R~
                            celldrawsw=1;                          //~v440R~
                        if (Sdatacsrpos>=0)//data csr display      //~v450I~
                        {                                          //~v549I~
#ifdef UTF8SUPPH                                                   //~va1cR~
                			if (UDBCSCHK_DBCSCOLS(*(pdbcs0+Sdatacsrpos)))//dbcs 1st,pad,2nd//~va1cR~
                            {                                      //~va1cR~
                            	Sdatacsrpos1=Sdatacsrpos-XESUB_DBCSSPLITCTR_L(pdbcs0,Sdatacsrpos);//~va1cR~
//                          	Sdatacsrpos2=Sdatacsrpos+XESUB_DBCSSPLITCTR_L(pdbcs0+Sdatacsrpos,len);//~va1cR~//~va3YR~
                            	Sdatacsrpos2=Sdatacsrpos1+XESUB_DBCSSPLITCTR(pdbcs0,len,Sdatacsrpos1)-1;//~va3YR~
                            }                                      //~va1cR~
                            else                                   //~va1cR~
                            	Sdatacsrpos1=Sdatacsrpos2=Sdatacsrpos;//~va1cR~
#else                                                              //~va1cR~
                			if (*(pdbcs0+Sdatacsrpos)==DBCS1STCHAR)//~v450I~
                            	Sdatacsrpos2=Sdatacsrpos+1;        //~v450I~
                            else                                   //~v450I~
                			if (*(pdbcs0+Sdatacsrpos)==DBCS2NDCHAR)//~v450I~
                            	Sdatacsrpos2=Sdatacsrpos-1;        //~v450I~
#endif                                                             //~va1cR~
                        }                                          //~v549I~
//    UTRACEP("DRAWHEX=%d\n",UCBITCHK(plh->ULHflag5,ULHF5DRAWHEX));     //for reset at csr move//~v79eR~
                    }                                              //~v440I~
                  }//not vhex mode hex line                        //~v70nI~
              	}                                                  //~v440I~
			}                                                      //~v440I~
		}
		psd->USDlen=Ppcw->UCWwidth;
//*setup color
#ifdef SYNSUPP                                                     //~v780I~
        if (syntaxdrawsw                                           //~v780R~
        )                                                          //~v780I~
        {                                                          //~v780I~
			celldrawsw=1;                                          //~v780I~
        	UCBITON(psd->USDflag3,USDF3SYNTAX);                    //~v780R~
        }                                                          //~v780I~
        else                                                       //~v780I~
        	UCBITOFF(psd->USDflag3,USDF3SYNTAX);                   //~v780I~
#endif                                                             //~v780I~
UTRACEP("%s:lineno=%d,drawsw=%d\n",UTT,plh->ULHlinenor,UCBITCHK(plh->ULHflag,ULHFDRAW));//~va3jR~//~vbzVR~//~vbA1R~
		setlineattr(Ppcw,plh,psd,                                  //~v09RR~
//  				celldrawsw);                                   //~v09RI~//~vbi3R~
    				celldrawsw,line);                              //~vbi3R~
	}//while ULINEH exist
    pfc->UFCcsrline=csrline;                                       //~vbi3R~
//after bottom of data
//  if (UCBITCHK(Ppcw->UCWflag,UCWFDRAW))                          //~v08dR~
//  if (fulldrawsw)                                                //~v0hfR~
    if (fulldrawsw                                                 //~v0hfR~
	||  drawstartsw==1)	//draw after the line but not by isrt      //~v0hfI~
		for (;line<maxline;line++,psd++)
		{
			psd->USDbuffc=0;				//no corresponding plh
			psd->USDflag = USDFNCELL;
			psd->USDuvioo=0;		//no ligature                  //~vb4fI~
		    UCBITON(psd->USDflag2,USDF2DRAW);		//req dispaly  //~v0hfI~
			psd->USDnattr0len=0;			//write once
			psd->USDcell0len=0;				//no linenofld data
			psd->USDlen=Ppcw->UCWwidth;
			*psd->USDcell=' ';
			*(psd->USDcell+1)=Gattrtbl[COLOR_FRAME];                  //~v06wR~
		}
//*determine csr line                                           //~5527M~
	if (csrfldtopline)                                          //~5527M~
		csronthefld(Ppcw,csrfldtopline,pfc->UFCcsrfldno,pfc->UFCcsroffs); //move csr//~5527M~
//set hex data notation                                            //~v09SI~
    pc=(char*)(psd0->USDbuffc)+1;                                  //~v09SM~
    memcpy(hexeditwk,pc,HEXEDITLEN);                               //~v09SM~
#ifdef UTF8SUPPH                                                   //~va1cR~
    memcpy(hexeditcompwk,pc-1,HEXEDITLENMAX-1);	//to chk changed   //~va1cR~
    hexeditcompwk[HEXEDITLENMAX-1]=*(psd0->USDdata+FILENAMEPOS-1);//update id//~va1cR~
    dbcssz=0;                                                      //~va1cR~//~va1qM~
#endif                                                             //~va1cR~
    drawhexsw=0;                                                   //~v101I~
    if (CSRONFILEDATA(Ppcw))                                       //~v09SM~
    {                                                              //~v09SM~
    	plhcsr=(psd0+Ppcw->UCWrcsry)->USDbuffc;                    //~v09SM~
#ifdef UTF8UCS2                                                    //~va20I~
      if (swutf8file                                               //~va20I~
      &&  vhexcsrlineplh==plhcsr                                   //~va20I~
	  &&  UCBITCHK((psd0+Ppcw->UCWrcsry)->USDflag2,(USDF2VHEXLINE1|USDF2VHEXLINE2))//~va20I~
      )                                                            //~va20I~
        csrpos=Svhexcold1sv+pfc->UFCleft;                          //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
        csrpos=pfc->UFCleft+Ppcw->UCWrcsrx-linenosz;               //~v09SM~
      	if (plhcsr->ULHtype==ULHTDATA)                             //~v09SM~
            if (csrpos<plhcsr->ULHlen)                             //~v09SM~
            {                                                      //~v09SI~
			    drawhexsw=1;                                       //~v101I~
                pcd=plhcsr->ULHdbcs+csrpos;                        //~v09SR~
                pc=plhcsr->ULHdata+csrpos;                         //~v09SI~
#ifdef UTF8UCS2                                                    //~va20I~
                if (swutf8file)                                    //~va20I~
                {                                                  //~va20I~
                    if (*pcd==UDBCSCHK_F2LERR)                     //~va20I~
                        ucs=*pc;                                   //~va20I~
                    else                                           //~va45I~
//*for utf8 file                                                   //~va50I~
                    if (*pcd==TABCHAR)                             //~va45I~
        	        	ucs=TABCHAR;                               //~va45R~
                    else                                           //~va20I~
                    {                                              //~vbk7I~
//                  	ucs=(int)UTF_GETDDUCS1(pc,pcd,plhcsr->ULHlen-csrpos);//~va20R~//~vbk7R~
                    	ucs=(int)utfdd2u1chsz(0,pc,pcd,plhcsr->ULHlen-csrpos,0/*&chsz*/);//~vbk7I~
                    }                                              //~vbk7I~
                    if (*pcd==UDBCSCHK_F2LERR||UTF8ISASCII(ucs))   //~va20R~
                    {                                              //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
				  		if (hexoptupper)                           //~va3xI~
    	        			sprintf(hexeditwk,"---%02X",ucs);      //~va3xI~
                  		else                                       //~va3xI~
    	        			sprintf(hexeditwk,"---%02x",ucs);      //~va3xI~
#else                                                              //~va3xI~
				  		if (hexoptupper)                           //~va20I~
    	        			sprintf(hexeditwk,"-%02X",ucs);        //~va20I~
                  		else                                       //~va20I~
    	        			sprintf(hexeditwk,"-%02x",ucs);        //~va20I~
#endif                                                             //~va3xI~
                    }                                              //~va20I~
                    else                                           //~va20I~
                    {                                              //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
                      if (UTF_ISUCS4(ucs))                         //~va3xI~
                      {                                            //~va3xI~
                      	swucs4=1;                                  //~va3xI~
				  		if (hexoptupper)                           //~va3xI~
    	        			sprintf(hexeditwkgb4,"%06X-",ucs);     //~va3xI~
                  		else                                       //~va3xI~
    	        			sprintf(hexeditwkgb4,"%06x-",ucs);     //~va3xI~
                      }//UCS4                                      //~va3xI~
                      else                                         //~va3xI~
#endif                                                             //~va3xI~
                      {//UCS2                                      //~va3xI~
				  		if (hexoptupper)                           //~va20I~
    	        			sprintf(hexeditwk,"-%04X",ucs);        //~va20I~
                  		else                                       //~va20I~
    	        			sprintf(hexeditwk,"-%04x",ucs);        //~va20I~
                      }                                            //~va3xI~
                    }                                              //~va20I~
                }                                                  //~va20I~
                else                                               //~va20I~
#endif                                                             //~va20I~
//              if (*pcd==DBCS1STCHAR)                             //~v493R~
//              if ((*pcd==DBCS1STCHAR) && ((csrpos+1)<plhcsr->ULHlen))//~v76JR~
//**not utf8 file***                                               //~va20I~
                if (((csrpos+1)<plhcsr->ULHlen) && (*pcd==DBCS1STCHAR))//~v76JR~
                {                                                  //~va1cR~
#ifdef UTF8SUPPH                                                   //~va1qI~
                    dbcssz=XESUB_DBCSSPLITCTR(plhcsr->ULHdbcs,plhcsr->ULHlen,csrpos);//~va1cR~
                  if (dbcssz==UDBCSCHK_GB4SZ)                      //~va1cR~
                  {                                                //~va1cR~
					if (hexoptupper)                               //~va1cR~
    		        	sprintf(hexeditwkgb4,"%02X%02X%02X%02X",(UINT)*pc,(UINT)*(pc+1),(UINT)*(pc+2),(UINT)*(pc+3));//~va1cR~
        	        else                                           //~va1cR~
    		        	sprintf(hexeditwkgb4,"%02x%02x%02x%02x",(UINT)*pc,(UINT)*(pc+1),(UINT)*(pc+2),(UINT)*(pc+3));//~va1cR~
                  }                                                //~va1cR~
                  else                                             //~va1cR~
                  if (dbcssz==UDBCSCHK_SS3SZ)                      //~va1cR~
                  {                                                //~va1cR~
					if (hexoptupper)                               //~va1cR~
    		        	sprintf(hexeditwkgb4,"%02X%02X%02X-",(UINT)*pc,(UINT)*(pc+1),(UINT)*(pc+2));//~va1cR~
        	        else                                           //~va1cR~
    		        	sprintf(hexeditwkgb4,"%02x%02x%02x-",(UINT)*pc,(UINT)*(pc+1),(UINT)*(pc+2));//~va1cR~
                  }                                                //~va1cR~
                  else                                             //~va1cR~
#endif                                                             //~va1qI~
				  if (hexoptupper)                                 //~v44mI~
    	        	sprintf(hexeditwk,"-%02X%02X",(UINT)*pc,(UINT)*(pc+1));//~v09SR~
                  else                                             //~v44mI~
    	        	sprintf(hexeditwk,"-%02x%02x",(UINT)*pc,(UINT)*(pc+1));//~v44mI~
                }                                                  //~va1cR~
				else                                               //~v09SI~
                if (UDBCSCHK_DBCSNOT1ST_L(*pcd)) //dbcs split      //~vb2aI~
                {                                                  //~vb2aI~
                	int backto1st=XESUB_DBCSSPLITCTR_L(plhcsr->ULHdbcs,csrpos);//~vb2aR~
                    dbcssz=XESUB_DBCSSPLITCTR(plhcsr->ULHdbcs,plhcsr->ULHlen,csrpos-backto1st);//~vb2aI~
                    pc-=backto1st;                                 //~vb2aI~
                    if (dbcssz==UDBCSCHK_GB4SZ)                    //~vb2aR~
                    {                                              //~vb2aR~
                        if (hexoptupper)                           //~vb2aR~
                            sprintf(hexeditwkgb4,"%02X%02X%02X%02X",(UINT)*pc,(UINT)*(pc+1),(UINT)*(pc+2),(UINT)*(pc+3));//~vb2aR~
                        else                                       //~vb2aR~
                            sprintf(hexeditwkgb4,"%02x%02x%02x%02x",(UINT)*pc,(UINT)*(pc+1),(UINT)*(pc+2),(UINT)*(pc+3));//~vb2aR~
                    }                                              //~vb2aR~
                    else                                           //~vb2aR~
                    if (dbcssz==UDBCSCHK_SS3SZ)                    //~vb2aR~
                    {                                              //~vb2aR~
                        if (hexoptupper)                           //~vb2aR~
                            sprintf(hexeditwkgb4,"%02X%02X%02X-",(UINT)*pc,(UINT)*(pc+1),(UINT)*(pc+2));//~vb2aR~
                        else                                       //~vb2aR~
                            sprintf(hexeditwkgb4,"%02x%02x%02x-",(UINT)*pc,(UINT)*(pc+1),(UINT)*(pc+2));//~vb2aR~
                    }                                              //~vb2aR~
                    else                                           //~vb2aR~
                    if (hexoptupper)                               //~vb2aR~
                      	sprintf(hexeditwk,"-%02X%02X",(UINT)*pc,(UINT)*(pc+1));//~vb2aR~
                    else                                           //~vb2aR~
                      	sprintf(hexeditwk,"-%02x%02x",(UINT)*pc,(UINT)*(pc+1));//~vb2aR~
                    pc+=backto1st;                                 //~vb2aI~
                }                                                  //~vb2aI~
				else                                               //~vb2aI~
                if (*pcd==TABPADCHAR)                              //~v09SI~
                	sprintf(hexeditwk,"---%c-",Gfiletabdisp2);     //~v09SI~
//              if (*pcd==NULLCHARIDDBCS)                          //~v0a1R~
//              	memcpy(hexeditwk,"---00-",HEXEDITLEN);         //~v0a1R~
    			else                                               //~v09SM~
                {                                                  //~v09SI~
//*no TABCHAR on dbcstbl for ebcfile                               //~va50I~
                    if (*pcd==TABCHAR)                             //~v09SI~
        	        	uch=TABCHAR;                               //~v09SI~
                    else                                           //~v09SI~
    	    			uch=*pc;                                   //~v09SI~
				  if (hexoptupper)                                 //~v44mI~
                	sprintf(hexeditwk,"---%02X",(UINT)uch);        //~v09SR~
                  else                                             //~v44mI~
                	sprintf(hexeditwk,"---%02x",(UINT)uch);        //~v44mI~
				}//sbcs                                            //~v09SI~
			}                                                      //~v09SI~
    }//in data range                                               //~v09SM~
//hexinput mode display                                            //~v101I~
	if (Ghexctl[HEXCTL_MODE])	//hex input mode                   //~v101I~
    {                                                              //~v101I~
    	if (!drawhexsw)                                            //~v101I~
        	memset(hexeditwk,'-',5);    //clear EDIT/BROWSE/CMD    //~v101I~
    	hexinputlen=(int)Ghexctl[HEXCTL_LEN];	//input xdigit len //~v101I~
        for (ii=0;ii<hexinputlen;ii++)                             //~v101I~
            hexeditwk[ii]=Ghexctl[HEXCTL_DATA+ii];                 //~v101R~
        hexeditwk[ii]='_';                                         //~v101R~
//#ifdef UTF8UCS4                                                    //~va3HI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
	  if (Ghexctl[HEXCTL_MODE] & HEXCTL_MODE_UCS4)	//hex input mode//~va3HR~
		*psd0->USDdata='v';				//ucs4 id                  //~va3KR~
      else                                                         //~va3HI~
#endif                                                             //~va3HI~
	  if (Ghexctl[HEXCTL_MODE] & HEXCTL_MODE_UCS2)	//hex input mode//~va3KI~
		*psd0->USDdata='u';				//ucs4 id                  //~va3KI~
      else                                                         //~va3KI~
		*psd0->USDdata='x';				//id of hex mode           //~v101I~
    }                                                              //~v101I~
    else                                                           //~v101I~
		*psd0->USDdata=*(UCHAR*)psd0->USDbuffc;	//recover 1st byte //~v101I~
//**                                                               //~v101I~
    pc=(char*)(psd0->USDdata)+1;                                   //~v09SM~
#ifdef UTF8SUPPH                                                   //~va1cR~
	if (dbcssz==UDBCSCHK_GB4SZ)                                    //~va1cR~
    	memcpy(hexeditcompwk,hexeditwkgb4,HEXEDITLENGB4); //"x1x2x3x4"//~va1cR~
    else                                                           //~va1cR~
	if (dbcssz==UDBCSCHK_SS3SZ)                                    //~va1cR~
    	memcpy(hexeditcompwk,hexeditwkgb4,HEXEDITLENSS3+1); //"x1x2x3-|"//~va1cR~
    else                                                           //~va1cR~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
	if (swucs4)                                                    //~va3xI~
    	memcpy(hexeditcompwk,hexeditwkgb4,HEXEDITLENUCS4+1); //"x1x2x3-|"//~va3xI~
    else                                                           //~va3xI~
#endif                                                             //~va3xI~
    	memcpy(hexeditcompwk+1,hexeditwk,HEXEDITLEN);              //~va1cR~
	if (Ghexctl[HEXCTL_MODE])	//hex input mode                   //~va3GI~
    {                                                              //~va3GI~
    	*(hexeditcompwk)=*(pc-1);				//id of hex mode,x or X       //~va3GI~//~va3HR~
//  	memcpy(hexeditcompwk+1,hexeditwk,hexinputlen+1);           //~va3GI~//~vb28R~
    	memcpy(hexeditcompwk+1,hexeditwk,(size_t)hexinputlen+1);   //~vb28I~
    }                                                              //~va3GI~
#endif                                                             //~va1cR~
#ifdef UTF8SUPPH                                                   //~va1cR~
    if (memcmp(pc-1,hexeditcompwk,HEXEDITLENMAX))                  //~va1cR~
#else                                                              //~va1cR~
    if (memcmp(pc,hexeditwk,HEXEDITLEN))                           //~v09SM~
#endif                                                             //~va1cR~
    {                                                              //~v09SM~
#ifdef UTF8SUPPH                                                   //~va1cR~
  	  	memcpy(pc-1,hexeditcompwk,HEXEDITLENMAX);                  //~va1cR~
#else                                                              //~va1cR~
  	  	memcpy(pc,hexeditwk,HEXEDITLEN);                           //~v09SM~
#endif                                                             //~va1cR~
      if (Ppcw->UCWsplitid==Gscrcurclient)	//active pcw           //~va3LI~
      {                                                            //~va3LI~
UTRACEP("draw hdr line by hex pcw=%p\n",Ppcw);                     //~va3KI~
		UCBITON(psd0->USDflag2,USDF2DRAW);                         //~v09SM~
      }                                                            //~va3LI~
  	}                                                              //~v09SM~
    if ((Gcsrposy >  Ppcw->UCWorgy+CMDLINENO                       //~v19kR~
    &&  Gcsrposy <  Ppcw->UCWorgy+Ppcw->UCWheight                  //~v0eCI~
    &&  Gcsrposx >= Ppcw->UCWorgx+linenosz                         //~v0eCI~
    &&  Gcsrposx <  Ppcw->UCWorgx+Ppcw->UCWwidth)                  //~v19kR~
    ||  fulldrawsw)                                                //~v0eCI~
    {                                                              //~v0eCI~
        swlongrecord=0;                                            //~vaznI~
     if (csrposdisp>0)	//colomn display space avail               //~v51VI~
     {                                                             //~v51VI~
        pc=psd0->USDdata;                                          //~v0eCI~
        dpos=-1;	//id of not hex part                           //~v59vI~
        if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                      //~v59vI~
        {                                                          //~v59vI~
            filegethexcsrdpos(0,Ppcw,pfh,&dpos);	//dpos=-1: if data part,-2 if intermediate hex//~v59vR~
            if (dpos>=0)    //csr on valid hex part                //~v59vI~
            {                                                      //~v59vI~
                if (xlinenosw)                                     //~v59vI~
                    sprintf(linenowk,hexeditpat4c,dpos);           //~v59vI~
                else                                               //~v59vI~
                {                                                  //~v59vI~
                    if (dpos<=9999)                                //~v59vI~
                        sprintf(linenowk,"% 5d",dpos); //"% 5d" expand to 6 byte if colw>9999//~v59vI~
                    else                                           //~v59vI~
                        sprintf(linenowk,"%05d",dpos);             //~v59vI~
                }                                                  //~v59vI~
            }                                                      //~v59vI~
        }                                                          //~v59vI~
     if (dpos<0)    //data part or out of range                    //~v59vR~
     {                                                             //~v59vI~
      if (xlinenosw)                                               //~v410I~
//      sprintf(linenowk,hexeditpat4,                              //~v57GR~
        sprintf(linenowk,hexeditpat4c,                             //~v57GI~
                pfc->UFCleft+max(Ppcw->UCWrcsrx-linenosz,0));      //~v410I~
      else                                                         //~v410I~
      {                                                            //~v57GI~
//      sprintf(linenowk,"%04d",                                   //~v57GR~
//      sprintf(linenowk,"% 5d",                                   //~v57GR~
//              pfc->UFCleft+1+max(Ppcw->UCWrcsrx-linenosz,0));    //~v57GR~
        colw=pfc->UFCleft+1+max(Ppcw->UCWrcsrx-linenosz,0);        //~v57GI~
        if (pfc->UFCleft+1>9999||(pfc->UFCleft+Ppcw->UCWwidth-linenosz)>9999)//~vaznR~
        {                                                          //~vaznI~
        	swlongrecord=1;                                        //~vaznM~
			sprintf(linenowk,"%05d",colw);                         //~vaznI~
        }                                                          //~vaznI~
        else                                                       //~vaznI~
        if (colw<=9999)                                            //~v57GI~
			sprintf(linenowk,"% 5d",colw); //"% 5d" expand to 6 byte if colw>9999//~v57GI~
        else                                                       //~v57GI~
			sprintf(linenowk,"%05d",colw);                         //~v57GI~
      }                                                            //~v57GI~
     }//not hex parxt                                              //~v59vI~
       if (swlongrecord)                                           //~vaznI~
       {                                                           //~vaznI~
        if (memcmp(pc+csrposdisp+COLUMNDISPCC+1,linenowk+2,COLUMNDISPW-1))//~vaznI~
        {                                                          //~vaznI~
          	memcpy(pc+csrposdisp+COLUMNDISPCC+1,linenowk+2,COLUMNDISPW-1);//~vaznI~
          	UCBITON(psd0->USDflag2,USDF2DRAW);                     //~vaznI~
        }                                                          //~vaznI~
       }                                                           //~vaznI~
       else                                                        //~vaznI~
//      if (memcmp(pc+csrposdisp+COLUMNDISPCC,linenowk+1,3))       //~v57GR~
        if (memcmp(pc+csrposdisp+COLUMNDISPCC,linenowk+1,COLUMNDISPW))//~v57GR~
        {                                                          //~v0eCI~
//        	memcpy(pc+csrposdisp+COLUMNDISPCC,linenowk+1,3);       //~v57GR~
          	memcpy(pc+csrposdisp+COLUMNDISPCC,linenowk+1,COLUMNDISPW);//~v57GR~
          	UCBITON(psd0->USDflag2,USDF2DRAW);                     //~v0eCI~
        }                                                          //~v0eCI~
     }//colomn display space avail                                 //~v51VI~
    }                                                              //~v0eCI~
    if (colslinesw) //gauge exist                                  //~v21qI~
//    	filecolsdisp(Ppcw,psdgauge,fulldrawsw);		//draw gauge line//~v69DR~
      	filecolsdisp(Ppcw,psdgauge,fulldrawsw,Sprotattr,Sprotattr_r);		//draw gauge line//~v69DI~
	return 0;
}//func_draw_file                                                  //~v09SR~
////****************************************************************//~va3XR~
////*set hex csrpos attr when revesed                              //~va3XR~
////****************************************************************//~va3XR~
//#ifdef W32                                                       //~va3XR~
//int hexcsrrevattr(int Popt,int Pctr,USHORT **Ppaddrtb,USHORT *Paddr,int Prevcolor)//~va3XR~
//#else                                                            //~va3XR~
//int hexcsrrevattr(int Popt,int Pctr,UCHAR  **Ppaddrtb,UCHAR  *Paddr,int Prevcolor)//~va3XR~
//#endif                                                           //~va3XR~
//{                                                                //~va3XR~
//    int ii,hexbg,hexattr,tabattr;                                //~va3XR~
//#ifdef W32                                                       //~va3XR~
//    USHORT **ppaddr;                                             //~va3XR~
//#else                                                            //~va3XR~
//    UCHAR  **ppaddr;                                             //~va3XR~
//#endif                                                           //~va3XR~
////*********************                                          //~va3XR~
//    for (ii=0,ppaddr=Ppaddrtb;ii<Pctr;ii++,ppaddr++)             //~va3XR~
//        if (*ppaddr==Paddr)                                      //~va3XR~
//            break;                                               //~va3XR~
//    if (ii>=Pctr)                                                //~va3XR~
//        return Prevcolor;                                        //~va3XR~
//    hexbg=UVIOM_ATTRBG(Prevcolor);                               //~va3XR~
//    tabattr=UVIOM_ATTRFG(Scolor_lineno);                         //~va3XR~
//    if ((hexbg>>4)==Shexcsrattr     //if set fg of hexcsr char is not identifiable//~va3XR~
//    &&  Shexcsrattr!=tabattr)                                    //~va3XR~
//        hexattr=hexbg|tabattr;                                   //~va3XR~
//    else                                                         //~va3XR~
//        hexattr=hexbg|Shexcsrattr;                               //~va3XR~
//    return hexattr;                                              //~va3XR~
//}//hexcsrrevattr                                                 //~va3XR~
////****************************************************************//~va3XI~
////*adjust vhex csr color on char part                            //~va3XI~
////****************************************************************//~va3XI~
int filesetvhexcsrattr(int Popt,int Prevcolor,int Pdefcolor,int *Ppvhexattr,int *Ppvhexrevattr,int *Ppvhexxrevattr)//~va3XR~
{                                                                  //~va3XI~
    int revattrbg,vhexattr,defattrfg,defattrbg,tabattrfg;          //~va3XI~
//**********************                                           //~va3XI~
	revattrbg=UVIOM_ATTRBG(Prevcolor)>>4;                          //~va3XR~
    defattrfg=UVIOM_ATTRFG(Pdefcolor);                             //~va3XI~
    defattrbg=UVIOM_ATTRBG(Pdefcolor);                             //~va3XI~
    if (revattrbg==defattrfg)	//hide char                        //~va3XI~
    {                                                              //~va3XI~
    	tabattrfg=UVIOM_ATTRFG(Scolor_lineno);                     //~va3XI~
        if (tabattrfg==revattrbg)                                  //~va3XI~
        	vhexattr=Prevcolor;	//giveup                           //~va3XR~
        else                                                       //~va3XI~
        	vhexattr=tabattrfg|defattrbg;                          //~va3XI~
    }                                                              //~va3XI~
    else                                                           //~va3XI~
    	vhexattr=Pdefcolor;	//iidentifiable vhexcsr and reverse box//~va3XR~
    *Ppvhexattr=vhexattr;                                          //~va3XI~
    *Ppvhexrevattr=(revattrbg<<4)|UVIOM_ATTRFG(vhexattr);          //~va3XR~
    *Ppvhexxrevattr=(revattrbg<<4)|defattrfg;                      //~va3XI~
    return 0;                                                      //~va3XI~
}//filesetvhexcsrattr                                              //~va3XI~
//****************************************************************
// setlineattr
//*setup line attr(color) for scrdisp
//*parm1:pcw
//*parm2:plh
//*parm3:psd
//*parm4:draw by cell                                              //~v09RI~
//*rc   :none
//****************************************************************
void setlineattr(PUCLIENTWE Ppcw,PULINEH Pplh,PUSCRD Ppsd,         //~v09RR~
//  				int Pcellsw)                                   //~v09RI~//~vbi3R~
    				int Pcellsw,int Pline)                         //~vbi3R~
{
	PUFILEC pfc;
	PUFILEH pfh;                                                //~v05vI~
	int ii,jj,width,offs=0,len,wordlen=0,curundosw,curupsw,curcapsw;//~5422R~//~va7jR~
	USHORT *pusoffs=NULL;                                          //~va7jR~
#ifdef W32                                                         //~v08eM~
    USHORT *paw,*paw0;				//attr word                    //~v08eM~
    USHORT attr;				//attr word                        //~v08eI~
	UCHAR  *pc;                                                    //~v09RI~
#else                                                              //~v08eI~
	UCHAR  uc;
	UCHAR  *pcc,*pc;
#ifdef UTF8SUPPH                                                   //~va1cM~
    int splitctr;                                                  //~va1cM~
#endif                                                             //~va1cM~
#endif                                                             //~v08eI~
    int     linenosz;                                           //~v069I~
    int   protlinesw;                                              //~v0ifI~
    int   multifindsw;                                             //~v43gI~
    int   vhexpsdid;                                               //~v60vI~
	UCHAR wcolor_client,wcolor_client_r;                              //~v06uI~
    UCHAR *pcd;         //dbcs tbl ptr                             //~v09RI~
    UCHAR *pcd0;        //dbcs tbl ptr at data start pos of psd    //~v450I~
    UCHAR tabattr;          //dbcs tbl ptr                         //~v09RR~
#ifdef SYNSUPP                                                     //~v780I~
    int syntaxsw,synopt=0;                                         //~v780R~
#endif                                                             //~v780I~
#ifdef UTF8UCS2                                                    //~va20I~
	int merginoffs,bndsoffs1,bndsoffs2,swutf8file;                 //~va20R~
    int vhexfwpos,vhexfwlen,vhexfwoffs;                            //~va20R~
    int swvhexdatacsr=0;                                           //~va3mI~
    UCHAR *pdatapcd0;        //datapart top                        //~va3mI~
//    int hexcsrposctr=0;                                          //~va3XR~
#ifdef W32                                                         //~va3mI~
    USHORT *pdatapca0;                                             //~va3mI~
//    USHORT *phexcsrpos[8];                                       //~va3XR~
#else                                                              //~va3mI~
    UCHAR *pdatapca0;                                              //~va3mI~
//    UCHAR  *phexcsrpos[8];                                       //~va3XR~
#endif                                                             //~va3mI~
#endif                                                             //~va20I~
    UCHAR *pdatapc0;                                               //~vbzVI~
	int vhexdcsrattr,hhexdcsrattr,vhexdrevattr,vhexxrevattr,hhexdrevattr;                                   //~va3XR~//~va3YR~//~va3XR~
    int vhexcold1,vhexcold2,vhexcolx=0,hhexcold1,hhexcold2;                                       //~va3YI~//~va3XR~//~va7jR~
//******************
#ifdef SYNSUPP                                                     //~v780I~
	syntaxsw=UCBITCHK(Ppsd->USDflag3,USDF3SYNTAX);                 //~v780I~
#endif                                                             //~v780I~
    vhexpsdid=UCBITCHK(Ppsd->USDflag2,(USDF2VHEXLINE1|USDF2VHEXLINE2));//vhex display hex line sw//~v60vR~
    linenosz=Ppcw->UCWlinenosz;                                 //~v069I~
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;                                               //~v0ifI~
	Ppsd->USDflag=USDFCHARSTRATT;
	Ppsd->USDuvioo=0;                                              //~vb4fI~
	Ppsd->USDoff=0;			//write to from leftmost column
	Ppsd->USDcell0len=0;		//no special cell data 
	Ppsd->USDnattr0len=0;	//no additional attr
	Ppsd->USDnattr0off=0;
    pcd0=Ppsd->USDdbcs;	//dbcstbl                                  //~v451R~
    protlinesw=UCBITCHK(Pplh->ULHflag4,ULHF4PROTLINE); //protected line//~v0ifI~
	curundosw=(Pplh->ULHupundoctr && Pplh->ULHupundoctr==Sfileupundoctr);//~5105I~
	if (curundosw)                                                 //~v45zI~
		UCBITON(Pplh->ULHflag3,ULHF3CURUNDO);//reset at next uundo //~v45zI~
	curupsw=(Pplh->ULHupctr && Pplh->ULHupctr==Sfileupctr);     //~5422I~
    if (curupsw)                                                   //~v45vI~
		UCBITON(Pplh->ULHflag3,ULHF3CURUPDATE);	//redraw when upctr advanced//~v45vI~
    if (Sfileresetsw)	//v011:reset                            //~5610R~
        curcapsw=0;            	//v011:not reverse              //~5610I~
    else                        //v011                          //~5610I~
		curcapsw=(curupsw && UCBITCHK(Pplh->ULHflag,ULHFCURCAP));//~v020R~
//  if (UCBITCHK(Pplh->ULHflag3,ULHF3CMDECHO)                      //~v60vR~
    if ((   UCBITCHK(Pplh->ULHflag3,ULHF3CMDECHO)                  //~v60vR~
         || vhexpsdid)                      //virtial hex display hex line//~v60vR~
    &&  Pplh->ULHlen)	//any cmd string                           //~v07jI~
    {                                                                 //~v06uI~
		wcolor_client  =Scolor_lineno;                                //~v06uI~
		wcolor_client_r=Scolor_lineno_r;                              //~v06uI~
	}                                                                 //~v06uI~
	else                                                              //~v06uI~
    {                                                                 //~v06uI~
      if (protlinesw) //protected line                             //~v0ifR~
      {                                                            //~v0ifI~
		wcolor_client  =Sprotattr;                                 //~v0ifR~
		wcolor_client_r=Sprotattr_r;                               //~v0ifR~
      }                                                            //~v0ifI~
      else                                                         //~v0ifI~
      {                                                            //~v0ifI~
		wcolor_client  =Scolor_client;                                //~v06uI~
		wcolor_client_r=Scolor_client_r;                              //~v06uI~
      }                                                            //~v0ifI~
	}                                                                 //~v06uI~
    filesetvhexcsrattr(0,wcolor_client_r,Shexcsrattr,&vhexdcsrattr,&vhexdrevattr,&vhexxrevattr);//~va3XR~//~va3YR~//~va3XR~
    hhexdcsrattr=vhexdcsrattr;                                     //~va3XR~
    hhexdrevattr=vhexdrevattr;                                     //~va3XI~
//*hdr/exclude line
	if (Pplh->ULHtype!=ULHTDATA)	//only lineno input avail
	{
      if (protlinesw) //protected line                             //~v0ifI~
      {                                                            //~v0ifI~
		Ppsd->USDnattr=Sprotattr;                                  //~v0ifI~
		Ppsd->USDnattr0=Scolor_lineno;                             //~v0ifI~
		Ppsd->USDoff=Ppsd->USDnattr0len=linenosz;//lineno highlite //~v0ifI~
      }                                                            //~v0ifI~
      else                                                         //~v0ifI~
		Ppsd->USDnattr=Scolor_lineno;                           //~5430R~
		if (UCBITCHK(Pplh->ULHflag,ULHFLCMDERR)                    //~v0azR~
		||  UCBITCHK(Pplh->ULHflag3,ULHF3ERRLINE))                 //~v0azI~
		{
			Ppsd->USDnattr0=Scolor_lineno_r;                    //~5430R~
			if (ii=linenosz-1,ii<0)                             //~v069R~
            	ii=0;                                           //~v069I~
			Ppsd->USDoff=Ppsd->USDnattr0len=ii;//lineno highlite//~v069I~
		}
		else                                                    //~5105I~
			if (curundosw)                                      //~5105I~
			{                                                   //~5105I~
				Ppsd->USDnattr0=Scolor_lineno_r;                //~5430R~
				Ppsd->USDoff=Ppsd->USDnattr0len=1;//lineno top highlite//~5127R~
			}                                                   //~5105I~
        IFDEF_SYNSUPP(UCBITOFF(Ppsd->USDflag3,USDF3SYNTAX));	//no syntax line//~v780R~
		return;
	}
//*data line
	Ppsd->USDnattr=wcolor_client;                                     //~v06uR~
  if (!Pcellsw)                                                    //~v09RI~
	if (!UCBITCHK(Pplh->ULHflag,
				ULHFLCMDERR|ULHFCURFOUND|ULHFBLOCK)
	&&  !UCBITCHK(Pplh->ULHflag3,ULHF3ERRLINE)                     //~v0azR~
	&&  !curupsw                                                //~5422R~
#if defined(W32) && !defined(WXE)                                  //~vb59I~
    &&  !vhexpsdid                       //virtial hex display hex line//~vb59R~
#endif                                                             //~vb59I~
	&&  !curundosw)		//not current undo line			        //~5105I~
	{			//change color of only lineno fld
		Ppsd->USDnattr0=Scolor_lineno;                          //~5430R~
		Ppsd->USDoff=Ppsd->USDnattr0len=linenosz;		//additional lineno color//~v069R~
		return;
	}
//*additional attr for dataline
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(pfh);                                  //~va20I~
    if (Smerginoffs && vhexpsdid)   //margined and cpos>UFCleft    //~va20I~
//      xeutf_getvhexcsrpos(0,0/*pos->offs*/,Ppcw,Pplh,Smerginoffs,0/*out pos*/,&merginoffs);//~va20R~
        merginoffs=PLHPOS2OFFS(0,Pplh,Smerginoffs+pfc->UFCleft)    //~va20I~
                  -PLHPOS2OFFS(0,Pplh,pfc->UFCleft);               //~va20I~
    else                                                           //~va20I~
		merginoffs=Smerginoffs;                                    //~va20I~
    if (Sbndsoffs1>0 && vhexpsdid)                                 //~va20I~
//      xeutf_getvhexcsrpos(0,0/*pos->offs*/,Ppcw,Pplh,Sbndsoffs1,0/*out pos*/,&bndsoffs1);//~va20R~
        bndsoffs1=PLHPOS2OFFS(0,Pplh,Sbndsoffs1+pfc->UFCleft)      //~va20I~
                  -PLHPOS2OFFS(0,Pplh,pfc->UFCleft);               //~va20I~
    else                                                           //~va20I~
		bndsoffs1=Sbndsoffs1;                                      //~va20I~
    if (Sbndsoffs2>0 && vhexpsdid)                                 //~va20I~
//      xeutf_getvhexcsrpos(0,0/*pos->offs*/,Ppcw,Pplh,Sbndsoffs2,0/*out pos*/,&bndsoffs2);//~va20R~
        bndsoffs2=PLHPOS2OFFS(0,Pplh,Sbndsoffs2+pfc->UFCleft)      //~va20I~
                  -PLHPOS2OFFS(0,Pplh,pfc->UFCleft);               //~va20I~
    else                                                           //~va20I~
		bndsoffs2=Sbndsoffs2;                                      //~va20I~
    if (!vhexpsdid)                                                //~va20I~
    {                                                              //~va20I~
//        opt=XEUTFGDSO_CSRPOSIN|XEUTFGDSO_CSRPOSOUT; //output is csr pos//~va20R~
//        xeutf_getdataspan(opt,Ppcw,Pplh,0,Smerginoffs,Gscrwidth,0,&merginoffs);//~va20R~
//        xeutf_getdataspan(opt,Ppcw,Pplh,Sbndsoffs1,Sbndsoffs2,Gscrwidth,&bndsoffs1,&bndsoffs2);//~va20R~
		merginoffs=Smerginoffs;                                    //~va20I~
        bndsoffs1=Sbndsoffs1;                                      //~va20I~
        bndsoffs2=Sbndsoffs2;                                      //~va20I~
    }                                                              //~va20I~
#endif//UTF8UCS2                                                   //~va20I~
//*setup cell for lineno
#ifdef W32                                                         //~v08eI~
//*all by cell2 format                                             //~v08eI~
	Ppsd->USDflag=USDFCELLSTR2;			//cell is attr WORD        //~v08eR~
    if (!vhexpsdid)                                                //~vb4fI~
		Ppsd->USDuvioo=UVIOO_LIGATURE1|UVIOO_COMBINE|UVIOO_CSRPOSCHK;//~vb4fR~
	paw0=paw=(USHORT*)(void*)Ppsd->USDcell;                        //~v08eR~
                                                                   //~v08eI~
	if (UCBITCHK(Pplh->ULHflag,ULHFLCMDERR)                        //~v0azR~
	||  UCBITCHK(Pplh->ULHflag3,ULHF3ERRLINE))                     //~v0azI~
		attr=(USHORT)Scolor_lineno_r;//reverse                     //~v08eR~
	else                                                           //~v08eI~
		attr=(USHORT)Scolor_lineno;	//normal lineno                //~v08eR~
    if (linenosz)                                                  //~v08eI~
    {                                                              //~v08eI~
    	for (ii=0;ii<linenosz;ii++)                                //~v08eI~
    		*paw++=attr;				//normal color             //~v08eI~
    	if (curundosw)                                             //~v08eI~
    		*paw0=Scolor_lineno_r;		//latest undo              //~v08eI~
                                                                   //~v08eI~
    	if (curupsw)                                               //~v08eI~
    		*(paw-1)=Scolor_lineno_r;	//latest update            //~v08eI~
      	else                                                       //~v08eI~
    		*(paw-1)=Scolor_lineno;	//normal color                 //~v08eI~
#if defined(W32) && !defined(WXE)                                  //~vb59I~
      	if (vhexpsdid && linenosz>1)                               //~vb59I~
    		*(paw-2)=attr&0xf0;   //fg=0; set diffrent attr with next colomn to protect next column shift//~vb59I~
#endif                                                             //~vb59I~
        if (pfh->UFHtype==UFHTCMDHIST)                             //~vbi3R~
        {                                                          //~vbi3R~
        	if (Pline==pfc->UFCcsrlineold)                         //~vbi3R~
	    		*(paw-1)=Scolor_lineno;	//normal lineno            //~vbi3R~
        	else                                                   //~vbi3R~
        	if (Pline==pfc->UFCcsrline)                            //~vbi3R~
	    		*(paw-1)=Scolor_lineno_r;	//reverse              //~vbi3R~
        }                                                          //~vbi3R~
    }   //linenosz not 0                                           //~v08eI~
//*data part                                                       //~v08eI~
	width=Ppsd->USDlen-linenosz;                                   //~v08eM~
  	if (width>Gscrwidth)    //confirm for safety                   //~v160R~
   		width=Gscrwidth;                                           //~v160R~
  	else                                                           //~v160R~
   		if (width<0)                                               //~v160R~
   			width=0; 		//for vsplit before linenosz           //~v160I~
    memcpy(paw,scrw95getattrtbl((USHORT)wcolor_client),width*sizeof(USHORT));//copy nattr//~v09UR~
//*display tab and dbcs space by lineno attr                       //~v09RI~
	pc=Ppsd->USDdata+linenosz;                                     //~v09RI~
    pcd=Ppsd->USDdbcs+linenosz;	//dbcstbl                          //~v09RR~
    tabattr=(UCHAR)((Scolor_lineno&0x0f)+(wcolor_client&0xf0));    //~v09RR~
#ifdef SYNSUPP                                                     //~v780I~
	if (syntaxsw)                                                  //~v780I~
    {                                                              //~v780I~
        if (vhexpsdid)                                             //~v780I~
        	synopt|=SSLAO_VHEX;                                    //~v780I~
//    	xesynsetlineattr(synopt,Ppcw,pfh,Pplh,pc,pcd,(UCHAR*)(ULONG)paw,Ppsd,width,linenosz);	//fill paw by color data//~v780R~//~vafkR~
    	xesynsetlineattr(synopt,Ppcw,pfh,Pplh,pc,pcd,(UCHAR*)(ULPTR)paw,Ppsd,width,linenosz);	//fill paw by color data//~vafkI~
        if (Ssynbgtab>=0)                                          //~v780I~
		    tabattr=(UCHAR)((Scolor_lineno&0x0f)+Ssynbgtab);       //~v780I~
    }                                                              //~v780I~
#endif                                                             //~v780I~
    pdatapc0=pc;        //datapart top                             //~vbzVI~
    pdatapcd0=pcd;        //datapart top                           //~va3mI~
    pdatapca0=paw;                                                 //~va3mI~
	for (ii=0;ii<width;ii++,pc++,pcd++,paw++)                      //~v09UR~
    {                                                              //~v09RI~
#ifdef UTF8UCS2                                                    //~va20I~
      if (Svhexcsrsw                                               //~va20I~
      &&  (ii==Svhexcold1 || ii==Svhexcold2 || ii==Svhexcolx))     //~va20I~
      {                                                            //~va20I~
	      if (ii>=merginoffs)    //out of mergin                   //~va20R~
            if (vhexpsdid)                                         //~va20I~
       			*paw=Shexcsrmarginattr;  //lineno orbrowsw  color  //~va20I~
            else                                                   //~va20I~
            	*paw=Shexcsrmarginattrc;  //vhexmode char line csr attr on margin//~va20I~
          else                                                     //~va20I~
          {                                                        //~va3BI~
            if (ii==Svhexcold1 || ii==Svhexcold2)                  //~va3XI~
//          	*paw=vhexdcsrattr;      //lineno orbrowsw  color   //~va3XR~//~vb28R~
            	*paw=(USHORT)vhexdcsrattr;      //lineno orbrowsw  color//~vb28I~
            else                                                   //~va3XI~
            	*paw=Shexcsrattr;      //lineno orbrowsw  color    //~va20I~
//                phexcsrpos[hexcsrposctr++]=paw; //another reverse setting for hexcsr position//~va3XR~
          }                                                        //~va3BI~
      }                                                            //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
//*Windows dosnot support gb4, and also ss3                        //~va1cR~
//    if (ii>=Smerginoffs)    //out of mergin                      //~v73aR~
#ifdef UTF8UCS2                                                    //~va20I~
      if (ii>=merginoffs)    //out of mergin                       //~va20R~
#else                                                              //~va20I~
      if (ii>Smerginoffs    //out of mergin                        //~v73aI~
      ||  (ii==Smerginoffs && *pcd!=DBCS2NDCHAR)                   //~v73aI~
      )                                                            //~v73aI~
#endif                                                             //~va20M~
#ifdef UTF8UCS2                                                    //~va20I~
	   if (vhexpsdid)                                              //~va20I~
    	*paw=Shexmerginattr;   	//lineno orbrowsw  color           //~va20I~
       else                                                        //~va20I~
#endif                                                             //~va20I~
    	*paw=Smerginattr;   	//lineno orbrowsw  color           //~v0iiI~
      else                                                         //~v440I~
//*Windows dosnot support gb4, and also ss3                        //~va1cR~
      if (Sbndsoffs2>=0                                            //~v74ER~
#ifdef UTF8UCS2                                                    //~va20I~
      &&  vhexpsdid==0                                             //~va20I~
      &&  ii>=bndsoffs2                                            //~va20I~
#else                                                              //~va20I~
      &&  (  ii>Sbndsoffs2    //out of mergin                      //~v74EI~
           ||(ii==Sbndsoffs2 && *pcd!=DBCS2NDCHAR)                 //~v74ER~
          )                                                        //~v74EI~
#endif                                                             //~va20I~
         )                                                         //~v74ER~
    	*paw=Sbndsattr;   	//lineno orbrowsw  color               //~v74ER~
      else                                                         //~v74EI~
#ifdef UTF8UCS2                                                    //~va20I~
      if (vhexpsdid==0                                             //~va20I~
      &&  ii<bndsoffs1                                             //~va20R~
#else                                                              //~va20I~
//*Windows dosnot support gb4, and also ss3                        //~va1cR~
      if (ii<Sbndsoffs1-1    //out of mergin                       //~v74EI~
      ||  (ii==Sbndsoffs1-1 && *pcd!=DBCS1STCHAR)                  //~v74ER~
#endif                                                             //~va20M~
      )                                                            //~v74EI~
    	*paw=Sbndsattr;   	//lineno orbrowsw  color               //~v74ER~
      else                                                         //~v74EI~
#ifdef UTF8UCS2                                                    //~va20I~
      if (vhexpsdid                                                //~va20I~
      &&  (bndsoffs1>0 || bndsoffs2>0)                             //~va20I~
      &&  (ii==bndsoffs1-1 || ii==bndsoffs2)	//intdicate out boundary//~va20I~
         )                                                         //~va20I~
    	*paw=Shexmerginattr;  //white on boundary                  //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
//    if (Shexoffs && ii>=Shexoffs                                 //~v443R~
//    && ii!=Shexcsrpos && ii!=(Shexcsrpos+1))                     //~v443R~
//  	*paw=Shexattr;   	//lineno orbrowsw  color               //~v443R~
//      if (Shexoffs)                                              //~v457R~
//      {                                                          //~v457R~
//        if (ii>=Shexoffs)                                        //~v457R~
//        {                                                        //~v457R~
//            if (ii!=Shexcsrpos && ii!=(Shexcsrpos+1))            //~v457R~
//                *paw=Shexattr;      //lineno orbrowsw  color     //~v457R~
//        }                                                        //~v457R~
//        else                                                     //~v457R~
////          if (ii==Sdatacsrpos)                                 //~v457R~
//            if (ii==Sdatacsrpos||ii==Sdatacsrpos2)               //~v457R~
//                *paw=Shexattr;      //lineno orbrowsw  color     //~v457R~
//      }                                                          //~v457R~
      if (Shexoffs && ii>=Shexoffs)                                //~v457R~
      	if (ii==Shexcsrpos || ii==(Shexcsrpos+1))                  //~v457I~
        {                                                          //~va3BI~
            *paw=Shexcsrattr;      //lineno orbrowsw  color        //~va3XR~
//#ifdef UTF8UCS2                                                  //~va3XR~
//            phexcsrpos[hexcsrposctr++]=paw; //another reverse setting for hexcsr position//~va3XR~
//#endif                                                           //~va3XR~
        }                                                          //~va3BI~
        else                                                       //~v457I~
            *paw=Shexattr;      //lineno orbrowsw  color           //~v457I~
      else                                                         //~v457I~
      if (Shexoffs                                                 //~v457I~
#ifdef UTF8SUPPH                                                   //~va1cR~
      &&  (ii>=Sdatacsrpos1 && ii<=Sdatacsrpos2))                  //~va1cR~
#else                                                              //~va1cR~
      &&  (ii==Sdatacsrpos||ii==Sdatacsrpos2))                     //~v457R~
#endif                                                             //~va1cR~
      {                                                            //~va3BI~
//          *paw=Shexcsrattr;      //lineno orbrowsw  color        //~v457R~//~va3XR~
//          *paw=hhexdcsrattr;      //lineno orbrowsw  color       //~va3XR~//~vb28R~
            *paw=(USHORT)hhexdcsrattr;      //lineno orbrowsw  color//~vb28I~
//#ifdef UTF8UCS2                                                  //~va3XR~
//            phexcsrpos[hexcsrposctr++]=paw; //another reverse setting for hexcsr position//~va3XR~
//#endif                                                           //~va3XR~
      }                                                            //~va3BI~
      else                                                         //~v0iiI~
       if (ii<Sprotlen)    //out of mergin                         //~v0ifI~
	    *paw=Sprotattr;   		//draw by lineno color             //~v0ifI~
       else                                                        //~v0ifI~
//*no TABCHAR on dbcstbl for ebcfile                               //~va50I~
        if ((*pc==Gfiletabdisp1 && *pcd==TABCHAR)                  //~v09UR~
    	||  (*pc==Gfiletabdisp2 && *pcd==TABPADCHAR))              //~v09UR~
    		*paw=tabattr;	    	//draw by lineno color         //~v09UR~
        else                                                       //~v09UR~
//*Gunpdispchar[3] is for dbcs space,that is 2 byte dbcs           //~va1cR~
//**dbcsspace of utf8 file is processed at tabdisplay **           //~va20I~
            if (*pc==Gunpdispchar[3]                               //~v09XR~
//          &&  (*pcd==DBCS1STCHAR || *pcd==DBCS2NDCHAR))          //~v58LR~
            &&  (   (*pcd==DBCS1STCHAR && *(pc+1)==Gunpdispchar[3])//~v58LR~
                 || (*pcd==DBCS2NDCHAR && *(pc-1)==Gunpdispchar[3])//~v58LR~
                )        //bondary is already replaced by "."      //~v58LI~
               )                                                   //~v58LI~
				*paw=tabattr;   		//draw by lineno color     //~v09UI~
            else                                                   //~v09UI~
#ifndef SSS     //dbcs is set to NP1/NP2 by tabdisplay()           //~vb3xR~
            if (*pc==DEFAULT_ALTCH       //for utf8 file,tabdisplay() set DEFAULT_ALTCH for 0x3000//~vb3xR~
            &&  (   (*pcd==UDBCSCHK_DBCS1STUCS && *(pc+1)==DEFAULT_ALTCH)//~vb3xR~
                 || (*pcd==UDBCSCHK_DBCS2NDUCS && *(pc-1)==DEFAULT_ALTCH)//~vb3xR~
                )        //bondary is already replaced by "."      //~vb3xR~
               )                                                   //~vb3xR~
            {                                                      //~vb3xI~
            	UTRACEP("%s:Win dbcsspace *pc=%02x,*pcd=%02x\n",UTT,*pc,*pcd);//~vb3xR~
                *paw=tabattr;           //draw by lineno color     //~vb3xR~
            }                                                      //~vb3xI~
            else                                                   //~vb3xR~
#endif                                                             //~vb3xR~
            if (*pc==XEUTF_ERRREPCH                                //~vb28I~
            &&  (                                                  //~vb28R~
//                  UDBCSCHK_ISUCSDBCS(*pcd) //dbcs or ucs4        //~vb28R~//~vbm9R~
			        f23_isutf8dbcssplit(0,pcd,ii,width)            //~vbm9R~
                 || UDBCSCHK_DBCSCOLS(*pcd)  //1st,pad,2nd         //~vb28R~
                )        //bondary is already replaced by "."      //~vb28I~
               )                                                   //~vb28I~
				*paw=tabattr;   		//draw by lineno color     //~vb28I~
            else                                                   //~vb28I~
#ifdef UTF8UCS2                                                    //~va20I~
			    if (*pcd==DISPLINEATTRID	//display attr same as lineno//~va20I~
                ||  UDBCSCHK_ISUCSNP(*pcd)                         //~va20I~
//              ||  (UDBCSCHK_ISUCSWIDTH0(*pcd) && UTF_COMBINEMODE() && !(Gutfmode2 & GUM2_CONSLIGATURE))//~va3hR~
//              ||  (UDBCSCHK_ISUCSWIDTH0(*pcd) && !UTF_COMBINEMODE())//~va3uR~
//              ||  (UDBCSCHK_ISUCSWIDTH0(*pcd) && !UTF_COMBINEMODE() && !OPT_ISLIGATUREON())//~vb4yR~
                )                                                  //~va20I~
#else                                                              //~va20I~
			    if (*pcd==DISPLINEATTRID)	//display attr same as lineno//~v09UR~
#endif                                                             //~va20I~
					*paw=tabattr;   		//draw by lineno color //~v09UR~
                else                                               //~vb4yR~
//              if (swutf8file && UDBCSCHK_ISUCSWIDTH0(*pcd))      //~vb4yR~//~vbzVR~
                if (swutf8file && f23_iscombining(0,pc,pcd,width-ii))//Lnx//~vbzVR~
                {                                                  //~vb4yR~
#ifdef WXEXXE     //set ATTR_COMBINENP_FG at wxecsub when ligature mode//+//~vb4AR~
				  if (!OPT_ISLIGATUREON())                         //~vb4AI~
#endif                                                             //~vb4AI~
                  {                                                //~vb4AI~
                	char wkdddata[2],wkdddbcs[2];                  //~vb4yR~
		        	if (UTF_COMBINEMODE_NP() && Gutfcombaltch      //~vb4yR~
					&&  (UTF_UCS2DDSBCS((ULONG)Gutfcombaltch,wkdddata,wkdddbcs)<=1)//~vb4yR~
                    )                                              //~vb4yR~
                    {                                              //~vb4yR~
                    	*pc=*wkdddata;                             //~vb4yR~
                    	*pcd=*wkdddbcs;                            //~vb4yR~
		                *paw=ATTR_COMBINENP_FG;                    //~vb4yR~
                    }                                              //~vb4yR~
                    else                                           //~vb4yR~
//  				if (!UTF_COMBINEMODE() && !OPT_ISLIGATUREON()) //~vb5jR~
    				if (!UTF_COMBINEMODE())                        //~vb5jI~
                    {                                              //~vbA1I~
						*paw=tabattr;   		//draw by lineno color//~vb4yR~
						if (UDBCSCHK_DBCS1STUCS2NWO(*pcd))         //~vbA1I~
                        	*(paw+1)=tabattr;                      //+vbA1R~
                    }                                              //~vbA1I~
                  }                                                //~vb4AI~
                }                                                  //~vb4yR~
//  			else                                               //~v0iiR~
//              	if (ii>=Smerginoffs)    //out of mergin        //~v0iiR~
//  					*paw=tabattr;   		//draw by lineno color//~v0iiR~
                    	                                           //~v0buI~
    }                                                              //~v09RI~
//**end of WIN32 ****                                              //~v60vI~
#else                                                              //~v08eI~
//**not WIN32****                                                  //~v60vI~
	pc=Ppsd->USDdata;
	pcc=Ppsd->USDcell;
                                                                //~5105I~
	if (UCBITCHK(Pplh->ULHflag,ULHFLCMDERR)                        //~v0azR~
	||  UCBITCHK(Pplh->ULHflag3,ULHF3ERRLINE))                     //~v0azI~
		uc=Scolor_lineno_r;//reverse                            //~5430R~
	else
		uc=Scolor_lineno;	//normal lineno                     //~5430R~
    if (linenosz)                                                     //~v069I~
    {                                                                 //~v069I~
	for (ii=0;ii<linenosz;ii++)                                 //~v069R~
	{
		*pcc++=*pc++;			//copy data
		*pcc++=uc;				//normal color
	}
	if (curundosw)                                              //~5105I~
		*(Ppsd->USDcell+1)=Scolor_lineno_r;//latest undo        //~5430R~
                                                                //~5105I~
	if (curupsw)                                                //~5422R~
		*(pcc-1)=Scolor_lineno_r;	//latest update             //~5430R~
  	else                                                        //~5127R~
		*(pcc-1)=Scolor_lineno;	//normal color                  //~5430R~
    if (pfh->UFHtype==UFHTCMDHIST)                                 //~vbi3R~
    {                                                              //~vbi3R~
        if (Pline==pfc->UFCcsrlineold)                             //~vbi3R~
            *(pcc-1)=Scolor_lineno; //normal lineno                //~vbi3R~
        else                                                       //~vbi3R~
        if (Pline==pfc->UFCcsrline)                                //~vbi3R~
            *(pcc-1)=Scolor_lineno_r;   //reverse                  //~vbi3R~
    }                                                              //~vbi3R~
    }   //linenosz not 0                                              //~v069I~
//*data part
  if (!Pcellsw)                                                    //~v09RI~
	if (!UCBITCHK(Pplh->ULHflag,ULHFCURFOUND|ULHFBLOCK)         //~5422R~
	&& !curcapsw)                                               //~5422R~
	{
		Ppsd->USDcell0len=linenosz*2;//write data offset        //~v069R~
		Ppsd->USDoff=linenosz;		//write data offset         //~v069R~
		return;				//lineno by cell,data by stratt 
	}
//*all by cell
	width=Ppsd->USDlen-linenosz;                                //~v069I~
    if (width>Gscrwidth)    //confirm for safety                   //~v160I~
   		width=Gscrwidth;                                           //~v160I~
    else                                                           //~v160I~
   		if (width<0)                                               //~v160R~
   			width=0; 		//for vsplit before linenosz           //~v160I~
	memset(pcc,wcolor_client,(UINT)(width+width));  //fill normal color before syntax attr set//~v78oR~
	Ppsd->USDlen+=Ppsd->USDlen;	//double len
	Ppsd->USDflag=USDFCELLSTR;	//by cell data
    if (!vhexpsdid)                                                //~vb4fI~
		Ppsd->USDuvioo=UVIOO_LIGATURE1|UVIOO_COMBINE|UVIOO_CSRPOSCHK;//~vb4fR~
    pcd=Ppsd->USDdbcs+((ULONG)pc-(ULONG)(Ppsd->USDdata));	//dbcstbl//~v09RR~
    tabattr=(UCHAR)((Scolor_lineno&0x0f)+(wcolor_client&0xf0));    //~v09RR~
#ifdef UNX                                                         //~v20WI~
	if (Gmaxcolor==2)	//mono color                               //~v20WI~
    	tabattr=Gattrtbl[COLOR_TITLE];	//highlight                //~v20WI~
#endif //!UNX                                                      //~v20WI~
#ifdef SYNSUPP                                                     //~v780R~
	if (syntaxsw)                                                  //~v780I~
    {                                                              //~v780I~
        if (vhexpsdid)                                             //~v780I~
        	synopt|=SSLAO_VHEX;                                    //~v780I~
    	xesynsetlineattr(synopt,Ppcw,pfh,Pplh,pc,pcd,pcc,Ppsd,width,linenosz);	//fill paw by color data//~v780R~
        if (Ssynbgtab>=0)                                          //~v780I~
		    tabattr=(UCHAR)((Scolor_lineno&0x0f)+Ssynbgtab);       //~v780I~
    }                                                              //~v780I~
#endif                                                             //~v780I~
    pdatapc0=pc;        //datapart top                             //~vbzVI~
    pdatapcd0=pcd;        //datapart top                           //~va3mI~
    pdatapca0=pcc;       //data+attr cell                          //~va3mR~
	for (ii=0;ii<width;ii++)
	{
//  	*pcc++=*pc++;			//copy data                        //~v09RR~
    	*pcc++=*pc;			//copy data                            //~v09RI~
#ifdef UTF8UCS2                                                    //~va20I~
      if (Svhexcsrsw                                               //~va20I~
//    &&  (ii==Svhexcold1 || ii==Svhexcold2 || ii==Svhexcolx))     //~va20I~//~va3XR~
      &&  ((Svhexcold1>=0 && ii>=Svhexcold1 && ii<=Svhexcold2) || ii==Svhexcolx))//~va3XI~
      {                                                            //~va20I~
	      if (ii>=merginoffs)    //out of mergin                   //~va20R~
            if (vhexpsdid)                                         //~va20I~
       			*pcc++=Shexcsrmarginattr;  //lineno orbrowsw  color//~va20I~
            else                                                   //~va20I~
            	*pcc++=Shexcsrmarginattrc;  //vhexmode char line csr attr on margin//~va20I~
          else                                                     //~va20I~
          {                                                        //~va3mI~
//                phexcsrpos[hexcsrposctr++]=pcc; //another reverse setting for hexcsr position//~va3XR~
            	swvhexdatacsr=1;                                   //~va3mI~
            if (ii>=Svhexcold1 && ii<=Svhexcold2)                  //~va3XR~
//          	*pcc++=vhexdcsrattr;      //lineno orbrowsw  color //~va3XR~//~vb28R~
            	*pcc++=(UCHAR)vhexdcsrattr;      //lineno orbrowsw  color//~vb28I~
            else                                                   //~va3XI~
            	*pcc++=Shexcsrattr;      //lineno orbrowsw  color  //~va20I~
          }                                                        //~va3mI~
      }                                                            //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
//*uviom set attr for dbcs byte same as 1st byte                   //~va1cR~
//    if (ii>=Smerginoffs)    //out of mergin                      //~v73aR~
#ifdef UTF8UCS2                                                    //~va20I~
      if (ii>=merginoffs)    //out of mergin                       //~va20R~
#else                                                              //~va20I~
      if (ii>Smerginoffs    //out of mergin                        //~v73aI~
      ||  (ii==Smerginoffs && *pcd!=DBCS2NDCHAR)                   //~v73aI~
      )                                                            //~v73aI~
#endif                                                             //~va20M~
#ifdef UTF8UCS2                                                    //~va20I~
	   if (vhexpsdid)                                              //~va20I~
    	*pcc++=Shexmerginattr;   	//lineno orbrowsw  color       //~va20I~
       else                                                        //~va20I~
#endif                                                             //~va20I~
    	*pcc++=Smerginattr;   	//lineno orbrowsw  color           //~v0iiI~
      else                                                         //~v440I~
//*uviom set attr for dbcs byte same as 1st byte                   //~va1cR~
      if (Sbndsoffs2>=0                                            //~v74EI~
#ifdef UTF8UCS2                                                    //~va20I~
      &&  vhexpsdid==0                                             //~va20I~
      &&  ii>=bndsoffs2    //out of mergin                         //~va20I~
#else                                                              //~va20I~
      &&  (  ii>Sbndsoffs2    //out of mergin                      //~v74EI~
           ||(ii==Sbndsoffs2 && *pcd!=DBCS2NDCHAR)                 //~v74EI~
          )                                                        //~v74EI~
#endif                                                             //~va20I~
         )                                                         //~v74ER~
    	*pcc++=Sbndsattr;   	//lineno orbrowsw  color           //~v74ER~
      else                                                         //~v74EI~
#ifdef UTF8SUPPH                                                   //~va1cR~
  #ifdef UTF8UCS2                                                  //~va20I~
      if (vhexpsdid==0                                             //~va20I~
      &&  ii<bndsoffs1      //left out of mergin                   //~va20R~
  #else                                                            //~va20I~
      if (ii<Sbndsoffs1      //left out of mergin                  //~va1cR~
      &&  !(   dbcssw=1      //1 or d                              //~va20R~
            && (XESUB_DBCSSPLITCTR(pcd,min(Sbndsoffs1+1,width)-ii,0)>(Sbndsoffs1-ii)) //dbcs byte up to bnds left boundary//~va1cR~
           )                                                       //~va1cR~
  #endif                                                           //~va20M~
      )                                                            //~va1cR~
#else                                                              //~va1cR~
      if (ii<Sbndsoffs1-1    //out of mergin                       //~v74EI~
      ||  (ii==Sbndsoffs1-1 && *pcd!=DBCS1STCHAR)                  //~v74ER~
      )                                                            //~v74EI~
#endif                                                             //~va1cR~
    	*pcc++=Sbndsattr;   	//lineno orbrowsw  color           //~v74ER~
      else                                                         //~v74EI~
#ifdef UTF8UCS2                                                    //~va20I~
      if (vhexpsdid                                                //~va20I~
      &&  (bndsoffs1>0 || bndsoffs2>0)                             //~va20I~
      &&  (ii==bndsoffs1-1 || ii==bndsoffs2)	//intdicate out boundary//~va20I~
         )                                                         //~va20I~
    	*pcc++=Shexmerginattr;  //white on boundary                //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
//    if (Shexoffs && ii>=Shexoffs                                 //~v443R~
//    && ii!=Shexcsrpos && ii!=(Shexcsrpos+1))                     //~v443R~
//  	*pcc++=Shexattr;   	//lineno orbrowsw  color               //~v443R~
//      if (Shexoffs)                                              //~v457R~
//      {                                                          //~v457R~
//        if (ii>=Shexoffs)                                        //~v457R~
//            if (ii!=Shexcsrpos && ii!=(Shexcsrpos+1))            //~v457R~
//                *pcc++=Shexattr;    //lineno orbrowsw  color     //~v457R~
//            else                                                 //~v457R~
//                *pcc++=wcolor_client;               //normal color//~v457R~
//        else                                                     //~v457R~
////          if (ii==Sdatacsrpos)                                 //~v457R~
//            if (ii==Sdatacsrpos||ii==Sdatacsrpos2)               //~v457R~
//                *pcc++=Shexattr;    //lineno orbrowsw  color     //~v457R~
//            else                                                 //~v457R~
//                *pcc++=wcolor_client;               //normal color//~v457R~
//      }                                                          //~v457R~
      if (Shexoffs && ii>=Shexoffs)                                //~v457I~
      	if (ii==Shexcsrpos || ii==(Shexcsrpos+1))                  //~v457I~
        {                                                          //~va3BI~
//#ifdef UTF8UCS2                                                  //~va3XR~
//            phexcsrpos[hexcsrposctr++]=pcc; //another reverse setting for hexcsr position//~va3XR~
//#endif                                                           //~va3XR~
            *pcc++=Shexcsrattr;      //lineno orbrowsw  color      //~v457R~
        }                                                          //~va3BI~
        else                                                       //~v457I~
            *pcc++=Shexattr;      //lineno orbrowsw  color         //~v457R~
      else                                                         //~v457I~
      if (Shexoffs                                                 //~v457I~
#ifdef UTF8SUPPH                                                   //~va1cR~
      &&  (ii>=Sdatacsrpos1 && ii<=Sdatacsrpos2))                  //~va1cR~
#else                                                              //~va1cR~
      &&  (ii==Sdatacsrpos||ii==Sdatacsrpos2))                     //~v457I~
#endif                                                             //~va1cR~
      {                                                            //~va3BI~
//#ifdef UTF8UCS2                                                  //~va3XR~
//            phexcsrpos[hexcsrposctr++]=pcc; //another reverse setting for hexcsr position//~va3XR~
//#endif                                                           //~va3XR~
//          *pcc++=Shexcsrattr;      //lineno orbrowsw  color      //~va3XR~
//          *pcc++=hhexdcsrattr;      //lineno orbrowsw  color     //~va3XR~//~vb28R~
            *pcc++=(UCHAR)hhexdcsrattr;      //lineno orbrowsw  color//~vb28I~
      }                                                            //~va3BI~
      else                                                         //~v457I~
       if (ii<Sprotlen)    //out of mergin                         //~v0ifI~
	    *pcc++=Sprotattr; 	//draw by lineno color                 //~v0ifI~
       else                                                        //~v0ifI~
//*no TABCHAR on dbcstbl for ebcfile                               //~va50I~
        if ((*pc==Gfiletabdisp1 && *pcd==TABCHAR)                  //~v09UR~
    	||  (*pc==Gfiletabdisp2 && *pcd==TABPADCHAR))              //~v09UR~
    		*pcc++=tabattr;	    	//draw by lineno color         //~v09UR~
        else                                                       //~v09UR~
//**dbcsspace of utf8 file is processed at tabdisplay **           //~va20I~
//*Gunpdispchar[3] is for dbcs space,that is 2 byte dbcs           //~va1cR~
            if (*pc==Gunpdispchar[3]                               //~v09XR~
//          &&  (*pcd==DBCS1STCHAR || *pcd==DBCS2NDCHAR))          //~v58LR~
            &&  (   (*pcd==DBCS1STCHAR && *(pc+1)==Gunpdispchar[3])//~v58LR~
                 || (*pcd==DBCS2NDCHAR && *(pc-1)==Gunpdispchar[3])//~v58LR~
                )        //bondary is already replaced by "."      //~v58LR~
               )                                                   //~v58LI~
				*pcc++=tabattr; 		//draw by lineno color     //~v09UI~
            else                                                   //~v09UI~
#ifndef SSS                                                        //~vb3xI~
            if (*pc==DEFAULT_ALTCH       //for utf8 file,tabdisplay() set DEFAULT_ALTCH for 0x3000//~vb3xI~
            &&  (   (*pcd==UDBCSCHK_DBCS1STUCS && *(pc+1)==DEFAULT_ALTCH)//~vb3xI~
                 || (*pcd==UDBCSCHK_DBCS2NDUCS && *(pc-1)==DEFAULT_ALTCH)//~vb3xI~
                )        //bondary is already replaced by "."      //~vb3xI~
               )                                                   //~vb3xI~
            {                                                      //~vb3xI~
            	UTRACEP("%s:LNX dbcsspace *pc=%02x,*pcd=%02x\n",UTT,*pc,*pcd);//~vb3xI~
				*pcc++=tabattr;   		//draw by lineno color     //~vb3xR~
            }                                                      //~vb3xI~
            else                                                   //~vb3xI~
#endif                                                             //~vb3xI~
            if (*pc==XEUTF_ERRREPCH                                //~vb28I~
            &&  (                                                  //~vb28I~
//                  UDBCSCHK_ISUCSDBCS(*pcd) //dbcs or ucs4        //~vb28I~//~vbm9R~
			        f23_isutf8dbcssplit(0,pcd,ii,width)	           //~vbm9R~
                 || UDBCSCHK_DBCSCOLS(*pcd)  //1st,pad,2nd         //~vb28I~
                )        //bondary is already replaced by "."      //~vb28I~
               )                                                   //~vb28I~
				*pcc++=tabattr; 		//draw by lineno color     //~vb28I~
            else                                                   //~vb28I~
#ifdef UTF8UCS2                                                    //~va20I~
			    if (*pcd==DISPLINEATTRID	//display attr same as lineno//~va20I~
                ||  UDBCSCHK_ISUCSNP(*pcd)                         //~va20I~
//#ifndef XXE                                                      //~va3hR~//~va3mR~//~va3uR~
//              ||  (UDBCSCHK_ISUCSWIDTH0(*pcd) && UTF_COMBINEMODE())//~va3hR~
//              ||  (UDBCSCHK_ISUCSWIDTH0(*pcd)                    //~va3mI~//~va3rR~
//  					&& UVIOM_SPLITMODE() //!combine mode except fc5//~va3nR~//~va3rR~
//                  )                                              //~va3mI~//~va3rR~
//              ||  (UDBCSCHK_ISUCSWIDTH0(*pcd) && !UTF_COMBINEMODE())//~va3sI~//~va3uR~
//              ||  (UDBCSCHK_ISUCSWIDTH0(*pcd) && !UTF_COMBINEMODE() && !OPT_ISLIGATUREON())//~vb4xR~
//              ||  (swutf8file && UDBCSCHK_ISUCSWIDTH0(*pcd) && !UTF_COMBINEMODE() && !OPT_ISLIGATUREON())//~vb4yR~
//#else                                                              //~va3mI~//~va3uR~
//              ||  (UDBCSCHK_ISUCSWIDTH0(*pcd) && !UTF_COMBINEMODE())//~va3hI~//~va3uR~
//#endif                                                           //~va3hR~//~va3mR~//~va3uR~
                )                                                  //~va20I~
#else                                                              //~va20I~
			    if (*pcd==DISPLINEATTRID)	//display attr same as lineno//~v09UR~
#endif                                                             //~va20R~
					*pcc++=tabattr; 		//draw by lineno color //~v09UR~
                else                                               //~vb4yI~
//              if (swutf8file && UDBCSCHK_ISUCSWIDTH0(*pcd))      //~vb4yI~//~vbzVR~
                if (swutf8file && f23_iscombining(0,pc,pcd,width-ii))//Lnx//~vbzVI~
                {                                                  //~vb4yI~
                	char wkdddata[2],wkdddbcs[2];                  //~vb4yI~
#ifdef XXE                                                         //~vb4AI~
				  if (OPT_ISLIGATUREON())                          //~vb4AI~
                  	pcc++;                                         //~vb4AI~
                  else                                             //~vb4AI~
#endif                                                             //~vb4AI~
                  {                                                //~vb4AI~
#ifdef XXE                                                         //~vb4yM~
		        	if (UTF_COMBINEMODE_NP() && Gutfcombaltch      //~vb4yI~
					&&  (UTF_UCS2DDSBCS((ULONG)Gutfcombaltch,wkdddata,wkdddbcs)<=1)//~vb4yI~
#else                                                              //~vb4yI~
		        	if (UTF_COMBINEMODE_NP() && GoptcombaltchNP    //~vb4yI~
					&&  (UTF_UCS2DDSBCS((ULONG)GoptcombaltchNP,wkdddata,wkdddbcs)<=1)//~vb4yR~
#endif                                                             //~vb4yI~
                    )                                              //~vb4yI~
                    {                                              //~vb4yI~
                    	*pc=*wkdddata; //also copy src             //~vb4yI~
                    	*pcd=*wkdddbcs;                            //~vb4yI~
                    	*(pcc-1)=*wkdddata; //USCcell              //~vb4yI~
		                *pcc++=ATTR_COMBINENP_FG;                  //~vb4yI~
                    }                                              //~vb4yI~
                    else                                           //~vb4yI~
//  				if (!UTF_COMBINEMODE() && !OPT_ISLIGATUREON()) //~vb4AR~
    				if (!UTF_COMBINEMODE())                        //~vb4AI~
                    {                                              //~vbzVI~
						*pcc++=tabattr;   		//draw by lineno color//~vb4yI~
//				        if (*pcd==UDBCSCHK_DBCS1STUCS)             //~vbA1R~
						if (UDBCSCHK_DBCS1STUCS2NWO(*pcd))         //~vbA1I~
                        	*(pcc+1)=tabattr;                      //~vbA1R~
            	        UTRACEP("%s:combining set tabattr by Not CombineMode pc=%02x,pcd=%02x,pcc-1=%02x\n",UTT,*pc,*pcd,*(pcc-1));//~vbA1R~
//            	        UTRACED("pcc-8",pcc-8,16);  //TODO TEST    //~vbA1R~
                    }                                              //~vbzVI~
                    else                                           //~vb4yI~
                        pcc++;                                     //~vb4yI~
                    UTRACEP("%s:pc=%02x,pcd=%02x,pcc-1=%02x\n",UTT,*pc,*pcd,*pcc);//~vbzVR~
                  }//!ligature mode                                //~vb4AI~
                }                                                  //~vb4yI~
				else                                               //~v09UR~
#ifdef SSS   //try for fmt wcwidth!=0  ==>no good effect(eol pos shift 1 col to left)//~vbA1R~
                if (swutf8file && *pcd && f23_isFormat(0,pc,pcd,width-ii))//Lnx//~vbA1I~
                {                                                  //~vbA1I~
                	char wkdddata[2],wkdddbcs[2];                  //~vbA1I~
#ifdef XXE                                                         //~vbA1I~
				  if (OPT_ISLIGATUREON())                          //~vbA1I~
                  	pcc++;                                         //~vbA1I~
                  else                                             //~vbA1I~
#endif                                                             //~vbA1I~
                  {                                                //~vbA1I~
#ifdef XXE                                                         //~vbA1I~
		        	if (UTF_COMBINEMODE_NP() && Gutfcombaltch      //~vbA1I~
					&&  (UTF_UCS2DDSBCS((ULONG)Gutfcombaltch,wkdddata,wkdddbcs)<=1)//~vbA1I~
#else                                                              //~vbA1I~
		        	if (UTF_COMBINEMODE_NP() && GoptcombaltchNP    //~vbA1I~
					&&  (UTF_UCS2DDSBCS((ULONG)GoptcombaltchNP,wkdddata,wkdddbcs)<=1)//~vbA1I~
#endif                                                             //~vbA1I~
                    )                                              //~vbA1I~
                    {                                              //~vbA1I~
                    	*pc=*wkdddata; //also copy src             //~vbA1I~
                    	*pcd=*wkdddbcs;                            //~vbA1I~
                    	*(pcc-1)=*wkdddata; //USCcell              //~vbA1I~
		                *pcc++=ATTR_COMBINENP_FG;                  //~vbA1I~
                    }                                              //~vbA1I~
                    else                                           //~vbA1I~
    				if (!UTF_COMBINEMODE())                        //~vbA1I~
                    {                                              //~vbA1I~
						*pcc++=tabattr;   		//draw by lineno color//~vbA1I~
						if (UDBCSCHK_DBCS1STUCS2NWO(*pcd))         //~vbA1I~
                        	*(pcc+1)=tabattr;                      //~vbA1I~
            	        UTRACEP("%s:Format set tabattr by Not CombineMode pc=%02x,pcd=%02x,pcc-1=%02x\n",UTT,*pc,*pcd,*(pcc-1));//~vbA1R~
                    }                                              //~vbA1I~
                    else                                           //~vbA1I~
                        pcc++;                                     //~vbA1I~
                    UTRACEP("%s:Format wcw!=0 pc=%02x,pcd=%02x,pcc-1=%02x\n",UTT,*pc,*pcd,*pcc);//~vbA1R~
                  }//!ligature mode                                //~vbA1I~
                }//Format                                          //~vbA1I~
				else                                               //~vbA1I~
#endif //SSS                                                       //~vbA1R~
//              	if (ii>=Smerginoffs)    //out of mergin        //~v0iiR~
//						*pcc++=tabattr; 	//draw by lineno color //~v0iiR~
// 	  				else                                           //~v0ifR~
//  	*pcc++=wcolor_client;				//normal color         //~v780R~
    	pcc++;                                                     //~v780I~
        pc++;                                                      //~v09RI~
        pcd++;                                                     //~v09RI~
	}
//**end of not WIN32 ****                                          //~v60vI~
#endif                                                             //~v08eI~
#ifdef UTF8UCS2                                                    //~va3mI~
    if (swutf8file)                                                //~va3rI~
    {                                                              //~va3rI~
    	if (                                                       //~va3rR~
    		swvhexdatacsr  //set attr to dataline by vhex hexline csr//~va3rI~
    	)                                                          //~va3rI~
//      	setattraroundvhexdataline(0,pdatapcd0,pdatapca0,Svhexcold1,Svhexcold2,width,tabattr);//~va3mR~//~va3rR~//~vbzVR~
        	setattraroundvhexdataline(0,pdatapc0,pdatapcd0,pdatapca0,Svhexcold1,Svhexcold2,width,tabattr);//~vbzVI~
//        if (                                                       //~va3rR~//~va3sR~
//            Sdatacsrposu8>=0                                       //~va3rR~//~va3sR~
//        )                                                          //~va3rR~//~va3sR~
//            setattraroundcsrpos(0,pdatapcd0,pdatapca0,Sdatacsrposu8,width,tabattr);//~va3rR~//~va3sR~
    }                                                              //~va3rI~
#endif                                                             //~va3mI~
//*****************************                                    //~va3XI~
//*find word*******************                                    //~va20R~
//*****************************                                    //~va3XI~
    multifindsw=0;                                                 //~v43gI~
	if (UCBITCHK(Pplh->ULHflag,ULHFCURFOUND)                    //~5422R~
	||  curcapsw)                                               //~5422R~
	{
		if (UCBITCHK(Pplh->ULHflag2,ULHF2MFOUND))	//multiple found word
		{
//  		pfh=pfc->UFCpfh;                                       //~v0ifR~
			if (pfh->UFHmfwtbl)			//find all tbl,umalloc success//~v05vI~
            {                                                   //~v05vI~
				jj=(int)Pplh->ULHrevlen;		//word count    //~v05vR~
//  			wordlen=(int)*pfh->UFHmfwtbl;	 //word length     //~v43gR~
				multifindsw=1;                                     //~v43gI~
				pusoffs=pfh->UFHmfwtbl+Pplh->ULHrevoffs; //offset tbl start//~v05vR~
            }                                                   //~v05vI~
            else                                                //~v05vI~
            	jj=0;		//bypass reverse                    //~v05vI~
		}
		else
		{
			jj=1;							//word count
			wordlen=(int)Pplh->ULHrevlen; 		 //word length  //~5422R~
			pusoffs=&Pplh->ULHrevoffs; 		//offset tbl start  //~5422R~
		}
//UTRACED("wcolor_client_r",&wcolor_client_r,1);                   //~v06yR~
//  	for (;jj;jj--,pusoffs++)                                   //~v61sR~
    	for (;jj;jj--,pusoffs+=*(pusoffs+1)-1)//add offset to next entry//~v61sR~
		{
			if (multifindsw)                                       //~v43gI~
  				wordlen=(int)*(pusoffs+1);	//pair of offset,len   //~v43gI~
//        if (*pusoffs==ULHULFOUND)     //id of update line search //~v496R~
          if (*pusoffs==ULHULFOUND      //id of update line search //~v496I~
          ||  *pusoffs==ULHULFOUNDL)    //id of *L search          //~v496I~
          {                                                        //~v09eI~
            if (linenosz)                                          //~v09eI~
            {                                                      //~v09eI~
                len=1;                  //1byte                    //~v09eR~
                offs=-1;                                           //~v09eR~
    			len=min(len,width);   //cut by right end           //~v09eR~
            }                                                      //~v09eI~
            else                                                   //~v09eI~
                len=0;                  //1byte                    //~v09eI~
          }                                                        //~v09eI~
          else                                                     //~v09eI~
          {                                                        //~v09eI~
			offs=(int)*pusoffs-pfc->UFCleft;
            if (offs<0)         		//start before left end    //~v06QI~
            {                                                      //~v06QI~
                len=wordlen+offs;       //from left lend           //~v06QI~
				len=min(len,width);   //cut by right end           //~v06QI~
            	offs=0;                                            //~v06QR~
			}                                                      //~v06QI~
            else                                                   //~v06QI~
            	if (offs>=width)        //start after right end    //~v06QI~
                	len=0;				//bypass reverse           //~v06QI~
                else                    //start in the screen width//~v06QI~
                {                                                  //~v06QI~
	                len=width-offs;       //up toright lend        //~v06QI~
					len=min(len,wordlen);                          //~v06QI~
				}                                                  //~v06QI~
          }//updateline search or else                             //~v09eI~
    		if (len>0)                                             //~v06QI~
			{
            	pcd=pcd0+linenosz+offs;                            //~v451R~
#ifdef UTF8SUPPH                                                   //~va1cR~
                if (UDBCSCHK_DBCSNOTEND(*(pcd+len-1)))//1st or pad dbcs//~va1cR~
                	len-=XESUB_DBCSSPLITCTR_L(pcd0,linenosz+offs+len);	//back to the front of the splitdbcs//~va1cR~
#else                                                              //~va1cR~
                if (*(pcd+len-1)==DBCS1STCHAR)//last dbcs split    //~v451I~
                    len--;                    //avoid set reverse attr//~v451I~
#endif                                                             //~va1cR~
#ifdef UTF8UCS2                                                    //~va20R~
              if (vhexpsdid && swutf8file && len>0 && offs>=0)     //~va20I~
              {                                                    //~va20I~
              	vhexfwpos=offs;                                    //~va20I~
              	vhexfwlen=len;                                     //~va20I~
#ifdef AAA  //pcd(psd on vhexline) has no dbcs info                //~vawiI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416     //FIXME test surrogate   :FIXED              //~vaw1I~//~vawiR~
                if (UDBCSCHK_DBCS2NDU(*pcd))//start by 2nd char    //~va3xI~
#else                                                              //~va3xI~
                if (UDBCSCHK_DBCS2NDUCS2NWP(*pcd))//start by 2nd char//~va20I~
#endif                                                             //~va3xI~
                {                                                  //~va20I~
                    vhexfwpos++;                                   //~va20I~
					vhexfwlen--;                                   //~va20I~
                    vhexcolx--;                                    //~va3XR~
                }                                                  //~va20I~
#endif  //AAA                                                      //~vawiI~
//  			xeutf_getvhexcsrspan(0,Ppcw,Pplh,vhexfwpos,vhexfwpos+vhexfwlen,&vhexfwoffs,&vhexfwlen);//~va20I~//~vawiR~
    			xeutf_getvhexcsrspan(XEUTFGVXCSO_NEXT,Ppcw,Pplh,vhexfwpos,vhexfwpos+vhexfwlen,&vhexfwoffs,&vhexfwlen);//~vawiI~
                vhexfwlen=max(0,min(width-vhexfwoffs,vhexfwlen));  //~va20I~
                vhexcolx=Svhexcolx-vhexfwoffs;                     //~va3XI~
	#ifdef W32                                                     //~va20I~
				paw=paw0+linenosz+vhexfwoffs;                      //~va20I~
				for (ii=0;ii<vhexfwlen;ii++)                       //~va20I~
                {                                                  //~va20I~
//                  if (*paw==Shexcsrattr)//not hexcsr postion     //~va3XR~
////                  paw++;                                       //~va3XR~
//                    *paw++=(USHORT)hexcsrrevattr(0,hexcsrposctr,phexcsrpos,paw,wcolor_client_r);//~va3XR~
                  if (ii==vhexcolx)                                //~va3XI~
//  				*paw++=vhexxrevattr;		//reverse color wid vhexx fg//~va3XI~//~vb28R~
    				*paw++=(USHORT)vhexxrevattr;		//reverse color wid vhexx fg//~vb28I~
                  else                                             //~va3XR~
					*paw++=wcolor_client_r;		//reverse color    //~va20I~
                }                                                  //~va20I~
	#else                                                          //~va20I~
				pcc=Ppsd->USDcell+(linenosz+vhexfwoffs)*2+1;       //~va20I~
				for (ii=0;ii<vhexfwlen;ii++,pcc++)                 //~va20I~
                {                                                  //~va20I~
//                  if (*pcc==Shexcsrattr)//not hexcsr postion     //~va3XR~
//                  {                                              //~va3XR~
////                  pcc++;                                       //~va3XR~
//                    *pcc=(UCHAR)hexcsrrevattr(0,hexcsrposctr,phexcsrpos,pcc,wcolor_client_r);//~va3XR~
//                    pcc++;  //operation may be undefined for such as n++=n;//~va3XR~
//                  }                                              //~va3XR~
                  if (ii==vhexcolx)                                //~va3XI~
//  				*pcc++=vhexxrevattr;		//reverse color wid vhexx fg//~va3XI~//~vb28R~
    				*pcc++=(UCHAR)vhexxrevattr;		//reverse color wid vhexx fg//~vb28I~
                  else                                             //~va3XR~
					*pcc++=wcolor_client_r;		//reverse color    //~va20I~
                }                                                  //~va20I~
	#endif                                                         //~va20I~
              }                                                    //~va20I~
              else                                                 //~va20I~
#endif  //UTF8UCS2                                                 //~va20R~
              {	//not utf8 vhex                                    //~va20I~
                vhexcold1=Svhexcold1-offs;                   //~va3YI~//~va3XM~
                vhexcold2=Svhexcold2-offs;                   //~va3YI~//~va3XM~
                hhexcold1=Sdatacsrpos1-offs;                       //~va3XR~
                hhexcold2=Sdatacsrpos2-offs;                       //~va3XR~
#ifdef W32                                                         //~v08eI~
				paw=paw0+linenosz+offs;                            //~v08eI~
#ifdef UTF8UCS2                                                    //~va20I~
                if (UDBCSCHK_DBCS2NDLU(*pcd))//start by 2nd char(locale and ucs)//~va20R~
#else                                                              //~va20I~
//windwows support only 2byte dbcs                                 //~va1cR~
                if (*pcd==DBCS2NDCHAR)//start by 2nd char          //~v450I~
#endif                                                             //~va20I~
                {                                                  //~v451I~
                    paw++;                                         //~v451I~
					len--;                                         //~v451I~
                    vhexcold1--,vhexcold2--;                       //~va3XI~
                    hhexcold1--,hhexcold2--;                       //~va3XI~
                }                                                  //~v451I~
				for (ii=0;ii<len;ii++)                             //~v08eI~
                {                                                  //~va20I~
#ifdef UTF8UCS2                                                    //~va3XR~
//                  if (*paw==Shexcsrattr)//not hexcsr postion     //~va3XR~
////                  paw++;                                       //~va3XR~
//                    *paw++=(USHORT)hexcsrrevattr(0,hexcsrposctr,phexcsrpos,paw,wcolor_client_r);//~va3XR~
                  if (ii>=hhexcold1 && ii<=hhexcold2)              //~va3XI~
//  				*paw++=hhexdrevattr;                           //~va3XI~//~vb28R~
    				*paw++=(USHORT)hhexdrevattr;                   //~vb28I~
                  else                                             //~va3XI~
                  if (ii>=vhexcold1 && ii<=vhexcold2)//~va3YI~     //~va3XR~
//  				*paw++=vhexdrevattr;                            //~va3YI~//~va3XR~//~vb28R~
    				*paw++=(USHORT)vhexdrevattr;                   //~vb28I~
                  else                                             //~va3XR~
#endif                                                             //~va3XR~
					*paw++=wcolor_client_r;		//reverse color    //~v08eI~
                }                                                  //~va20I~
#else                                                              //~v08eI~
				pcc=Ppsd->USDcell+(linenosz+offs)*2+1;          //~v069R~
#ifdef UTF8SUPPH                                                   //~va1cR~
                if (UDBCSCHK_DBCSNOT1ST(*pcd))//left boundary is not top of dbcs//~va1cR~
                {                                                  //~va1cR~
                	splitctr=XESUB_DBCSSPLITCTR_R(pcd,len);	//back to the front of the splitdbcs//~va1cR~
                    pcc+=splitctr*2;                               //~va1cR~
					len-=splitctr;                                 //~va1cR~
                    vhexcold1-=splitctr,vhexcold2-=splitctr;       //~va3XI~
                }                                                  //~va1cR~
#else                                                              //~va1cR~
                if (*pcd==DBCS2NDCHAR)//start by 2nd char          //~v451I~
                {                                                  //~v451I~
                    pcc+=2;                                        //~v451I~
					len--;                                         //~v451I~
                }                                                  //~v451I~
#endif                                                             //~va1cR~
				for (ii=0;ii<len;ii++,pcc++)
                {                                                  //~va20I~
#ifdef UTF8UCS2                                                    //~va3XR~
//                  if (*pcc==Shexcsrattr)//not hexcsr postion     //~va3XR~
//                  {                                              //~va3XR~
//                    *pcc=(UCHAR)hexcsrrevattr(0,hexcsrposctr,phexcsrpos,pcc,wcolor_client_r);//~va3XR~
//                    pcc++;                                       //~va3XR~
//                  }                                              //~va3XR~
                  if (ii>=hhexcold1 && ii<=hhexcold2)              //~va3XI~
//  				*pcc++=hhexdrevattr;                           //~va3XR~//~vb28R~
    				*pcc++=(UCHAR)hhexdrevattr;                    //~vb28I~
                  else                                             //~va3XI~
                  if (ii>=vhexcold1 && ii<=vhexcold2)              //~va3XI~
//  				*pcc++=vhexdrevattr;                           //~va3XR~//~vb28R~
    				*pcc++=(UCHAR)vhexdrevattr;                    //~vb28I~
                  else                                             //~va3XR~
#endif                                                             //~va3XR~
					*pcc++=wcolor_client_r;		//reverse color       //~v06uR~
                }                                                  //~va20I~
#endif                                                             //~v08eI~
              }	//utf8 vhex                                        //~va20I~
			}
			if (multifindsw)                                       //~v43gI~
  				pusoffs++;	//skip len;pair of offset,len          //~v43gI~
		}//multiple word
	}//found word
//*************************                                        //~va3XI~
//*block*******************                                        //~va20R~
//*************************                                        //~va3XI~
	if (UCBITCHK(Pplh->ULHflag,ULHFBLOCK))
	{
		if (len=capblockchk(Ppcw,Pplh,&offs),len)//in the client area//~5123I~
		{                                                       //~5123I~
            pcd=pcd0+offs;                                         //~v450I~
#ifdef UTF8SUPPH                                                   //~va1cR~
            if (UDBCSCHK_DBCSNOTEND(*(pcd+len-1)))//1st or pad dbcs//~va1cR~
                len-=XESUB_DBCSSPLITCTR_L(pcd0,offs+len);	//back to the front of the splitdbcs//~va1cR~
#else                                                              //~va1cR~
            if (*(pcd+len-1)==DBCS1STCHAR)//last dbcs split        //~v451I~
                len--;                    //avoid set reverse attr //~v451I~
#endif                                                             //~va1cR~
#ifdef UTF8UCS2                                                    //~va20I~
          if (vhexpsdid && swutf8file && len>0 && offs>=linenosz)  //~va20I~
          {                                                        //~va20I~
            vhexfwpos=offs-linenosz;                               //~va20I~
            vhexfwlen=len;                                         //~va20I~
#ifdef AAA  //pcd(psd on vhexline) has no dbcs info                //~vawiI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416     //FIXME test surrogate:FIXED AAA                       //~vaw1I~//~vawiR~
            if (UDBCSCHK_DBCS2NDU(*pcd))//start by 2nd char        //~va3xI~
#else                                                              //~va3xI~
            if (UDBCSCHK_DBCS2NDUCS2NWP(*pcd))//start by 2nd char  //~va20I~
#endif                                                             //~va3xI~
            {                                                      //~va20I~
                vhexfwpos++;                                       //~va20I~
                vhexfwlen--;                                       //~va20I~
                vhexcolx--;                                        //~va3XI~
            }                                                      //~va20I~
#endif  //AAA                                                      //~vawiI~
//			xeutf_getvhexcsrspan(0,Ppcw,Pplh,vhexfwpos,vhexfwpos+vhexfwlen,&vhexfwoffs,&vhexfwlen);//~va20I~//~vawiR~
  			xeutf_getvhexcsrspan(XEUTFGVXCSO_NEXT,Ppcw,Pplh,vhexfwpos,vhexfwpos+vhexfwlen,&vhexfwoffs,&vhexfwlen);//~vawiI~
            vhexfwlen=max(0,min(width-vhexfwoffs,vhexfwlen));      //~va20I~
            vhexcolx=Svhexcolx-vhexfwoffs;                         //~va3XI~
	#ifdef W32                                                     //~va20I~
            paw=paw0+linenosz+vhexfwoffs;                          //~va20I~
            for (ii=0;ii<vhexfwlen;ii++)                           //~va20I~
            {                                                      //~va20I~
//              if (*paw==Shexcsrattr)//not hexcsr postion         //~va3XR~
////              paw++;                                           //~va3XR~
//                *paw++=(USHORT)hexcsrrevattr(0,hexcsrposctr,phexcsrpos,paw,wcolor_client_r);//~va3XR~
              if (ii==vhexcolx)                                    //~va3XI~
//              *paw++=vhexxrevattr;                               //~va3XI~//~vb28R~
                *paw++=(USHORT)vhexxrevattr;                       //~vb28I~
              else                                                 //~va3XR~
                *paw++=wcolor_client_r;     //reverse color        //~va20I~
            }                                                      //~va20I~
	#else                                                          //~va20I~
            pcc=Ppsd->USDcell+(linenosz+vhexfwoffs)*2+1;           //~va20I~
            for (ii=0;ii<vhexfwlen;ii++,pcc++)                     //~va20I~
            {                                                      //~va20I~
//              if (*pcc==Shexcsrattr)//not hexcsr postion         //~va3XR~
//              {                                                  //~va3XR~
//                *pcc=(UCHAR)hexcsrrevattr(0,hexcsrposctr,phexcsrpos,pcc,wcolor_client_r);//~va3XR~
//                pcc++;                                           //~va3XR~
//              }                                                  //~va3XR~
              if (ii==vhexcolx)                                    //~va3XI~
//              *pcc++=vhexxrevattr;                               //~va3XI~//~vb28R~
                *pcc++=(UCHAR)vhexxrevattr;                        //~vb28I~
              else                                                 //~va3XR~
                *pcc++=wcolor_client_r;     //reverse color        //~va20I~
            }                                                      //~va20I~
	#endif                                                         //~va20I~
          }                                                        //~va20I~
          else                                                     //~va20I~
#endif                                                             //~va20I~
          { //not utf8 vhex                                        //~va20I~
            vhexcold1=Svhexcold1+linenosz-offs;                    //~va3XM~
            vhexcold2=Svhexcold2+linenosz-offs;                    //~va3XM~
            hhexcold1=Sdatacsrpos1+linenosz-offs;                  //~va3XR~
            hhexcold2=Sdatacsrpos2+linenosz-offs;                  //~va3XR~
#ifdef W32                                                         //~v08eI~
			paw=paw0+offs;                                         //~v08eI~
//windows support only 2byte dbcs                                  //~va1cR~
#ifdef UTF8UCS2                                                    //~va20I~
            if (UDBCSCHK_DBCS2NDLU(*pcd))//start by 2nd char       //~va20R~
#else                                                              //~va20I~
            if (*pcd==DBCS2NDCHAR)//start by 2nd char              //~v450I~
#endif                                                             //~va20I~
            {                                                      //~v451I~
                paw++;                                             //~v451I~
                len--;                                             //~v451I~
                vhexcold1--,vhexcold2--;                           //~va3XI~
                hhexcold1--,hhexcold2--;                           //~va3XI~
            }                                                      //~v451I~
			for (ii=0;ii<len;ii++)                                 //~v08eI~
            {                                                      //~va20I~
#ifdef UTF8UCS2                                                    //~va3XR~
//              if (*paw==Shexcsrattr)//not hexcsr postion         //~va3XR~
////              paw++;                                           //~va3XR~
//                *paw++=(USHORT)hexcsrrevattr(0,hexcsrposctr,phexcsrpos,paw,wcolor_client_r);//~va3XR~
              if (ii>=hhexcold1 && ii<=hhexcold2)                  //~va3XI~
//  			*paw++=hhexdrevattr;                               //~va3XI~//~vb28R~
    			*paw++=(USHORT)hhexdrevattr;                       //~vb28I~
              else                                                 //~va3XI~
              if (ii>=vhexcold1 && ii<=vhexcold2)                  //~va3XI~
//  			*paw++=vhexdrevattr;                               //~va3XR~//~vb28R~
    			*paw++=(USHORT)vhexdrevattr;                       //~vb28I~
              else                                                 //~va3XR~
#endif                                                             //~va3XR~
				*paw++=wcolor_client_r;				//reverse color//~v08eI~
            }                                                      //~va20I~
#else                                                              //~v08eI~
			pcc=Ppsd->USDcell+offs*2+1;                         //~5123I~
#ifdef UTF8SUPPH                                                   //~va1cR~
            if (UDBCSCHK_DBCSNOT1ST(*pcd))//left boundary is not top of dbcs//~va1cR~
            {                                                      //~va1cR~
                splitctr=XESUB_DBCSSPLITCTR_R(pcd,len); //back to the front of the splitdbcs//~va1cR~
                pcc+=splitctr*2;                                   //~va1cR~
                len-=splitctr;                                     //~va1cR~
                vhexcold1-=splitctr,vhexcold2-=splitctr;           //~va3XI~
                hhexcold1-=splitctr,hhexcold2-=splitctr;           //~va3XI~
            }                                                      //~va1cR~
#else                                                              //~va1cR~
            if (*pcd==DBCS2NDCHAR)//start by 2nd char              //~v451I~
            {                                                      //~v451I~
                pcc+=2;                                            //~v451I~
                len--;                                             //~v451I~
            }                                                      //~v451I~
#endif                                                             //~va1cR~
			for (ii=0;ii<len;ii++,pcc++)                        //~5123I~
            {                                                      //~va20I~
#ifdef UTF8UCS2                                                    //~va3XR~
//              if (*pcc==Shexcsrattr)//not hexcsr postion         //~va3XR~
//              {                                                  //~va3XR~
//                *pcc=(UCHAR)hexcsrrevattr(0,hexcsrposctr,phexcsrpos,pcc,wcolor_client_r);//~va3XR~
//                pcc++;                                           //~va3XR~
//              }                                                  //~va3XR~
              if (ii>=hhexcold1 && ii<=hhexcold2)                  //~va3XI~
//  			*pcc++=hhexdrevattr;                               //~va3XR~//~vb28R~
    			*pcc++=(UCHAR)hhexdrevattr;                        //~vb28I~
              else                                                 //~va3XI~
              if (ii>=vhexcold1 && ii<=vhexcold2)                  //~va3XI~
//  			*pcc++=vhexdrevattr;                               //~va3XR~//~vb28R~
    			*pcc++=(UCHAR)vhexdrevattr;                        //~vb28I~
              else                                                 //~va3XI~
#endif                                                             //~va3XR~
				*pcc++=wcolor_client_r;				//reverse color   //~v06uR~
            }                                                      //~va20I~
#endif                                                             //~v08eI~
          } //utf8 vhex                                            //~va20I~
		}                                                       //~5123I~
	}//block defined                                            //~5123R~
    UTRACEP("%s:lineno=%d\n",UTT,Pplh->ULHlinenor);                //~vbzVR~
    UTRACED("attr",pdatapca0,width*(int)sizeof(pdatapca0[0]));     //~vbzVR~
	return;
}//setlineattr
//**********************************************************************//~va3mI~
//*set attr of data csr corresponding vhexcsr                      //~va3mI~
//*set green attr to left and right char if it is combining char   //~va3mI~
//**********************************************************************//~va3mI~
#ifdef W32                                                         //~va3mI~
//int setattraroundvhexdataline(int Popt,UCHAR *Pdbcs,USHORT *Pattr,int Ppos1,int Ppos2,int Pwidth,int Pcolor)//~va3mR~//~vbzVR~
int setattraroundvhexdataline(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,USHORT *Pattr,int Ppos1,int Ppos2,int Pwidth,int Pcolor)//~vbzVR~
#else                                                              //~va3mI~
//int setattraroundvhexdataline(int Popt,UCHAR *Pdbcs,UCHAR *Pattr,int Ppos1,int Ppos2,int Pwidth,int Pcolor)//~va3mI~//~vbzVR~
int setattraroundvhexdataline(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,UCHAR *Pattr,int Ppos1,int Ppos2,int Pwidth,int Pcolor)//~vbzVI~
#endif                                                             //~va3mI~
{                                                                  //~va3mI~
	int pos;                                                       //~va3mI~
    UCHAR *pcd;                                                    //~va3mR~
#ifdef W32                                                         //~va3mI~
	int attrstep=1;                                                //~va3mI~//~va3rR~
    USHORT *pca;                                                   //~va3mI~
#else                                                              //~va3mI~
	int attrstep=2;                                                //~va3mI~//~va3rR~
    UCHAR *pca;                                                    //~va3mI~
#endif                                                             //~va3mI~
//****************************                                     //~va3mI~
UTRACEP("setattraroundvhexdataline pos1=%d,pos2=%d,colr=%d\n",Ppos1,Ppos2,Pcolor);//~va3mR~//~va3rR~
//  if (!UTF_COMBINEMODE() && UVIOM_NONSPACECOMBINEMODE())	//splittable or FC5//~va3rI~//~va3sR~
    if (!UTF_COMBINEMODE()) //already set if split mode            //~va3sI~
    	return 0;                                                  //~va3rI~
    pos=Ppos2+1;                                                   //~va3mR~
    for(pcd=Pdbcs+pos,pca=Pattr+pos*attrstep;pos<Pwidth;pos++,pcd++,pca+=attrstep)//~va3mR~
    {                                                              //~va3mR~
//      if (!UDBCSCHK_ISUCSWIDTH0(*pcd))                           //~va3mR~//~vbzVR~
		if (!f23_iscombining(0,Pdata+pos,pcd,min(Pwidth-pos,2)))   //~vbzVR~
            break;                                                 //~va3mR~
        UTRACEP("%s:setattraroundvhexdatacsrpos pos=%d,*pc=0x%02x,dbcs=0x%02x\n",UTT,pos,*(Pdata+pos),*pcd);       //~va3rI~//~vbzVR~
#ifdef W32                                                         //~va3mI~
//      *pca=Pcolor;                                               //~va3mR~//~vb28R~
        *pca=(USHORT)Pcolor;                                       //~vb28I~
#else                                                              //~va3mI~
//      *(pca+1)=Pcolor;                                           //~va3mR~//~vb28R~
        *(pca+1)=(UCHAR)Pcolor;                                    //~vb28I~
#endif                                                             //~va3mI~
    }                                                              //~va3mR~
    return 0;                                                      //~va3mI~
}//setattraroundvhexdataline                                       //~va3mI~
#ifdef AAA //no user                                               //~vb4yI~
//**********************************************************************//~va3rI~
//*set attr of data csr                                            //~va3rI~
//*set green attr to left and right char if it is combining char   //~va3rI~
//**********************************************************************//~va3rI~
#ifdef W32                                                         //~va3rI~
int setattraroundcsrpos(int Popt,UCHAR *Pdbcs,USHORT *Pattr,int Ppos,int Pwidth,int Pcolor)//~va3rI~
#else                                                              //~va3rI~
int setattraroundcsrpos(int Popt,UCHAR *Pdbcs,UCHAR *Pattr,int Ppos,int Pwidth,int Pcolor)//~va3rI~
#endif                                                             //~va3rI~
{                                                                  //~va3rI~
	int pos;                                                       //~va3rI~
    UCHAR *pcd;                                                    //~va3rI~
#ifdef W32                                                         //~va3rI~
	int attrstep=1;                                                //~va3rR~
    USHORT *pca;                                                   //~va3rI~
#else                                                              //~va3rI~
	int attrstep=2;                                                //~va3rR~
    UCHAR *pca;                                                    //~va3rI~
#endif                                                             //~va3rI~
//****************************                                     //~va3rI~
UTRACEP("setattraroundcsrpos pos=%d,colr=%d\n",Ppos,Pcolor);       //~va3rR~
    if (!UVIOM_NONSPACECOMBINEMODE())	//fc5                      //~va3rI~
    	return 0;                                                  //~va3rI~
    pos=Ppos+1;                                                    //~va3rI~
    if (pos<Pwidth)                                                //~va3rI~
    {                                                              //~va3rI~
	    pcd=Pdbcs+pos;                                             //~va3rI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
    	if (UDBCSCHK_DBCS2NDUCS2NWO(*pcd) && pos+1<Pwidth)         //~va3xI~
#else                                                              //~va3xI~
    	if (UDBCSCHK_DBCS2NDUCS2NW(*pcd) && pos+1<Pwidth)          //~va3rR~
#endif                                                             //~va3xI~
        {                                                          //~va3rI~
        	pos++;                                                 //~va3rI~
            pcd++;                                                 //~va3rI~
        }                                                          //~va3rI~
    	for (pca=Pattr+pos*attrstep;pos<Pwidth;pos++,pcd++,pca+=attrstep)//~va3rR~
        {                                                          //~va3rI~
        	if (!UDBCSCHK_ISUCSWIDTH0(*pcd))                       //~va3rR~
            	break;                                             //~va3rI~
            UTRACEP("setattraroundcsrpos pos=%d\n",pos);           //~va3rI~
#ifdef W32                                                         //~va3rI~
//      	*pca=Pcolor;                                           //~va3rI~//~vb28R~
        	*pca=(USHORT)Pcolor;                                   //~vb28I~
#else                                                              //~va3rI~
//      	*(pca+1)=Pcolor;                                       //~va3rI~//~vb28R~
        	*(pca+1)=(UCHAR)Pcolor;                                //~vb28I~
#endif                                                             //~va3rI~
		}                                                          //~va3rI~
    }                                                              //~va3rI~
    pos=Ppos-1;                                                    //~va3rI~
    if (pos>=0)                                                    //~va3rI~
    {                                                              //~va3rI~
	    pcd=Pdbcs+pos;                                             //~va3rI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
    	if (UDBCSCHK_DBCS1STUCS2NWO(*pcd) && pos-1>=0)	//also for ucs4//~va3xI~
#else                                                              //~va3xI~
    	if (UDBCSCHK_DBCS1STUCS2NW(*pcd) && pos-1>=0)              //~va3rR~
#endif                                                             //~va3xI~
        {                                                          //~va3rI~
        	pos--;                                                 //~va3rI~
            pcd--;                                                 //~va3rI~
        }                                                          //~va3rI~
//  	for (pca=Pattr+pos*attrstep;pos>=0;pos--,pcd--,pca-=attrstep)//~va3rI~//~vafhR~
    	for (pca=Pattr+pos*attrstep;pos>=0;)    //C4702 unreachable code//~vafhI~
        {                                                          //~va3rI~
	        if (!UDBCSCHK_ISUCSWIDTH0(*pcd))                       //~va3rI~
            	break;                                             //~va3rI~
            UTRACEP("setattraroundcsrpos pos=%d\n",pos);           //~va3rI~
#ifdef W32                                                         //~va3rI~
//      	*pca=Pcolor;                                           //~va3rI~//~vb28R~
        	*pca=(USHORT)Pcolor;                                   //~vb28I~
#else                                                              //~va3rI~
//      	*(pca+1)=Pcolor;                                       //~va3rI~//~vb28R~
        	*(pca+1)=(UCHAR)Pcolor;                                //~vb28I~
#endif                                                             //~va3rI~
            break;  //set 1 column only,other is combined to prev base//~va3rI~
		}                                                          //~va3rI~
    }                                                              //~va3rI~
    return 0;                                                      //~va3rI~
}//setattraroundcsrpos                                             //~va3rR~
#endif // AAA //no user                                            //~vb4yI~
//*************************************************************    //~vbm9I~
//*chk "."(2e) is result of dbcs split of utf8 file                //~vbm9I~
//*************************************************************    //~vbm9I~
int f23_isutf8dbcssplit(int Popt,char *Pdbcs,int Pcol,int Pwidth)  //~vbm9I~
{                                                                  //~vbm9I~
	int rc=0;                                                      //~vbm9I~
//*******************                                              //~vbm9I~
	if (Pcol==0)                                                   //~vbm9I~
    	rc=UDBCSCHK_DBCS2NDUCS2NWPO(*Pdbcs);                       //~vbm9I~
    else                                                           //~vbm9I~
	if (Pcol==Pwidth-1)                                            //~vbm9R~
    	rc=UDBCSCHK_DBCS1STUCS2NWPO(*Pdbcs);                       //~vbm9I~
    UTRACEP("%s:rc=%d,Pcol=%d,width=%d,dbcsid=%x\n",UTT,rc,Pcol,Pwidth,*Pdbcs);//~vbm9R~
    return rc;                                                     //~vbm9I~
}//f23_isdbcssplit                                                 //~vbm9I~
//*************************************************************    //~vbzVI~
int f23_iscombining(int Popt,char *Pdddata,char *Pdddbcs,int Plen) //~vbzVI~
{                                                                  //~vbzVI~
	int rc=utf_iscombiningDD(Popt,Pdddata,Pdddbcs,Plen);           //~vbzVI~
    UTRACEP("%s:rc=%d,dddata=0x%02x,dbcs=0x%02x\n",UTT,rc,*Pdddata,*Pdddbcs);//~vbzVI~
    return rc;                                                     //~vbzVI~
}                                                                  //~vbzVI~
//*************************************************************    //~vbA1I~
int f23_isFormat(int Popt,char *Pdddata,char *Pdddbcs,int Plen)    //~vbA1I~
{                                                                  //~vbA1I~
    int ucs4=utfdd2u1(0,Pdddata,Pdddbcs,Plen);                     //~vbA1I~
    if (!ucs4)                                                     //~vbA1I~
    	return 0;                                                  //~vbA1I~
    int rc=utf4_isFormat(0,ucs4);                                  //~vbA1I~
    UTRACEP("%s:rc=%d,ucs=0x%04x,dddata=0x%02x,dbcs=0x%02x\n",UTT,rc,ucs4,*Pdddata,*Pdddbcs);//~vbA1I~
    return rc;                                                     //~vbA1I~
}                                                                  //~vbA1I~
