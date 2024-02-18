//*CID://+vbzgR~:                            update#=  497;        //+vbzgR~
//*************************************************************
//*xechar.c                                                     //~v04dR~
//*************************************************************
//vbzg:240131 v78g do locate cmd by key on prot fld of dirlist. protect it if col=1(top of num fld) for avoid easy jump.//+vbzgI~
//vbt4:201212 (WIN)apply -Nm on LC file only when utf8 inputmode(A+u)//~vbt4I~
//vbi3:180211 supprt command history list                          //~vbi3I~
//vb97:170311 Trap lcmd ineffective bug(Windows dump is taken by ueh,so change uerrmsg to uerrexit)//~vb97I~
//vb81:170206 trap for edit panel lcmd input ignored case if !NOTRACE//~vb81I~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vaze:150112 expand MAXLINEDATA 9999 to 32760                     //~vazeI~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vawu:140610 (BUG)ts fld claered when additional input wfter move csr to right//~vawuI~
//vaw3:140526 (Win:UNICODE)hex kbd for 3byte unicode               //~vaw3I~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW|FD|HD|F|H})//~vaj0I~
//vagp:120906 not used path but for chk by xci                     //~vagpI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafd:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(copile optio -Ox is required also)//~vafdI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va5Q:100524 (BUG)marginchk faile by missing clear keyindata_dddbcs//~va5QI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3T:100322 Hex cmd:add option to zigzag csr move mode HEX [YZ|NZ]//~va3TI~
//va3S:100322 (BUG)"S" lcmd replace split dbcs to space,it should be avoid when split on vhex line//~va3SI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va38:100205 (BUG)makeucs("U") key dose not delete next TAB expansion.( ex. 0x03+0x09(TAB)-->0x0309)//~va38I~
//va22:091207 (BUG)buff expand chk for GB4                         //~va22I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            char.c :update ucs line                              //~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va12:091021_(BUG) no need to move csr by del eol if csr is on vhex line//~va12I~
//va0G:090725!rename fld by codetype                               //~va0GI~
//va0t:090913!maintains locale and utf8 code for panel input(cmdline,panutil)//~va0tI
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I
//          cmdline may be mixed of utf8 and locale code           //~va00I
//v7ai:081206 (BUG)loose input char on rename overflow are if after cursor move//~v7aiI
//v7a6:081104 (BUG)dbcs evaluation required when prev is dbcserr   //~v7a6I
//v7a2:081102 (LNX:BUG)display hankana on FC%                      //~v7a2I
//v7a0:081030 (BUG)hex char input access out of record             //~v7a0I
//v79Z:081030 (BUG) vhexmode insert miss dbcstbl setting           //~v79ZI
//v79R:081027 (BUG)dbcs evaluation required when graphic char input specification is by hex notation//~v79RI
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI
//v8@Z:080715 3270:TSO keyboard mode by A+q                        //~v8@ZI
//v8@M:080707 3270:convert to uppercase for =6.TSO panel           //~v8@MI
//v8@2:080529 save tabctr in profile                               //~v8@2I
//v78g:080312 on dirlist;execute locate cmd by type on filename fld//~v78gI
//v77A:080126*(BUGof v777) GUNX_KON dosenot means EUC              //~v77AI
//v77g:071227 (UTF)re-evaluate utf8 char after join-line           //~v77gI
//v77b:071219 accept numeric only for color panel                  //~v77bI
//v778:071204*(BUG)after hex input by C+F11,dbcstbl recalc required//~v778I
//v777:071204*EUC hankana chk(2byte but 1 column)                  //~v777I
//v76A:070822 leave split dbcs when vhex mode                      //~v76AI
//v76j:070626 (WXEXXE)dnd by paste to utility panel. ins and rep only;std paste is disabled//~v76jI
//v76g:070620 utility panel(3.14:grep and 3.12:compare)            //~v76gI
//v76d:070618 vhex mode:allow input at EOL on hex part             //~v76dI
//v760:070529 avoid err join failed by margin chk by pre-chk for the case one line(No-EOL) stdpaste//~v760I
//v74E:070315 BOUNDS cmd support(find,shift-lcmd,paste-lcmd)       //~v74EI
//v74A:070225 (BUG)c&p cut lost space on EOL of top line for margined file//~v74AI
//            (v42g allow lost for join lcmd but keep space for c&p)//~v74AI
//v74z:070225 (BUG of v74u) //not oom shift back to oom            //~v74zI
//v74u:070221 (BUG)C&P lost margin for in invalid spf number       //~v74uI
//            ::cb dose not keep spf info,so num fld is not deleted//~v74uI
//v74s:070221*(BUG)S+BS at lineno fld abend because parm plh=0     //~v74sI
//v74q:070218 Cut/Clear:keep cobol margin if line split;after cob margin is save to ::cb//~v74qI
//            Paste:paste into after cobol margin                  //~v74qI
//v74m:070217 (BUG)marginchk err for cob file by cobol margin      //~v74mI
//v74j:070216 (BUG)C&P del fail by join fail for margined file.    //~v74jI
//            (by remaining oom of 1st line;delete oom for 1stline for region cut)//~v74jI
//v74i:070216 (BUG)C&P paste to region fail by join fail for margined file.//~v74iI
//            (ignore space before margin when join and keep oom(ignore oom for spf but)//~v74iI
//v74e:070215 (BUG)C&P ceare regin clear oom only for margined file//~v74eI
//v74d:070215 (BUG)ETOL should consider DBCS split at mergin boundary//~v74dI
//v74c:070213 (BUG)ETOL require imtabexp for margined file         //~v74cI
//v73w:070127 (BUG)under v73v,dbcs re-evaluation required for (v)hex mode update//~v73vI
//v73v:070127 (BUG)tab dose not back to part of dbcs 2nd byte after prev byte is changed to dbcs 1st byte by (v)hex mode//~v73vI
//            so,undo v73k.(AIX/LNX is set UDBCSCHK_HKDBCSERR if 2nd byte err.So WIN,DOS,OS/2 set HKDBCSERR only when 2nd byte is tab.//~v73vI
//v73u:070127 (BUG)bug of v734 alived by later update              //~v73uI
//v73q:070121*(BUG)for the line oom contain tab,after del omm contains imm data by shiftback//~v73hI
//v73p:070121 (BUG)for margined file,ins before tab(char just before the margin is expire if no record expand case)//~v73pI
//v73n:070117 (BUG)hexmode edit cursor DEL on hex part should back 1 col if data is longer than width//~v73nI
//v73j:070116 (BUG)shiftback require even if rep for the case tab inserted by vhex mode//~v73jR
//v73h:070114 (BUG)tab rep by hex mode dosen not delete expanded char//~v73jI
//v73g:070112 (BUG)margin chk is not correct when rep char by TAB using vhex mode//~v73gI
//v735:070104 support vhex line insert                             //~v735I
//v734:070102 (BUG)del key on vhex part delete the dbcs 2byte all  //~v734I
//v730:061225 use UPLbuff for cmdline(to display as long as possible if del key used, and accept insert over screen width)//~v730I~
//v72N:061214 CAPS:cmdline caps option "cap on/off cmd" to set caps optio to same as file contents option//~v72NI~
//v72M:061213 CAPS:change to lower by shift-key when CAPS on.      //~v72mI~
//            Linux console version can not detect SHIFT key but to avoid effect CapsLock Key on for TSO file(default cap on)//~v72mI~
//v72m:061125 3270:abandon half of v72g,CAPS is for only file contents//~v72mR~
//v72g:061124 change effect of CAPS to the whole of file screen.   //~v71UI~
//            change function to means reversing lower/upper to allow generate lower//~v71UI~
//v71U:061112 (BUG)accept insert in short(<mergin) record of margined file//~v71UI~
//v71H:061103 (3270)for RECFM=F,set UFHlrecl                       //~v71HI~
//v70n:060815 cut hex display part for vhex mode hex line(BUG:accept as char itself input on vhex line)//~v70nI~
//v69J:060712 cap(CAPS LOCK On) support                            //~v69JI~
//v69H:060711*(BUG)vhex replace tab miss original 09;ex entered 1 for upper line 09 is replaced by 10 (it should be 19)//~v69HI~
//v66g:051021 (BUG)cap del add expand len when outof line delete   //~v66gI~
//v63u:050527 (BUG)vhexmode char rep replace arounding of DBCS by space//~v63uI~
//v63n:050510 (LNX)revese  mouse selected line on dirlist          //~v63nI~
//v63h:050504 (WXE)support DragOut(regist required for dragdrop target to use ondragover etc)//~v63hI~
//v618:050212 (BUG)accept ETOL when cursor is just on 1st of protected margin//~v618I~
//v60v:050201 virtual hex display option(/Mx,HEX on/off,prev HEX is XIN)//~v60vI~
//v58R:041021 (BUG)ABEND when hexmode del-key at just after hex part because//~v58LI~
//            buff is not yet expandesd.                           //~v58LI~
//v47j:020303 for del CR of last line of concat line,simply conactinate next line//~v45jI~
//v454:011208 (BUG)tab remain at hex mode repl because dbcs tbl tabid write tab//~v454I~
//v448:011202 (BUG)hex input replace another half of dbcs          //~v444I~
//v444:011201 del on hex part                                      //~v444I~
//v442:011201 skip csr over hex intermidiate space                 //~v442I~
//v441:011130 edit   hex                                           //~v441I~
//v42g:010929 spf join ignoreing num fld                           //~v42gR~
//v42f:010929 cut record by EEOL for spf file with non protected numfld//~v417I~
//v417:010729 allow lineno fld when not protected for spf file     //~v417I~
//v179:000501 (BUG)when n line join is overflow,errmsg "Already one of split line"//~v179I~
//            So,join to split last line.                          //~v179I~
//v106:981212 no tab expand when binaly file                       //~v106I~
//v0ih:980621 pfk cmd support(input protect)                       //~v0ihI~
//v0i7:980520 line cmd split cmd('S')/join('J') support
//v0hN:980426 On cmd line,ctl char should be allowed for find cmd  //~v0hNI~
//            (reject x0a and x0d only)                            //~v0hNI~
//v0ht:980410 W95 report 0d1e additionaly to 0d1c(enter).          //~v0htI~
//            over v0hp and v0hn.                                  //~v0htR~
//            prohibit ctl char(<20h) except BS(08)/TAB(09)/ESC(1b)//~v0htI~
//v0hp:980308 (BUG of v0hn)v0hn reject BS(x08) input               //~v0hpI~
//v0hn:980221 W95 sometimes return 1c0a after 1c0d.(8000 entry generated)//~v0hnI~
//            especialy at startup.So prohibit input 0a on lineno or cmdline.//~v0hnI~
//v0ev:970922 abondan /v0ep/v0er/v0es/v0eu;                        //~v0evI~
//            use filetabexp2(expand in mergin only)               //~v0evI~
//v0et:970921 split char12 from char                               //~v0erI~
//v0es:970921 for v0ep,by method of v0er                           //~v0esI~
//v0er:970921 (BUG)shitback err when isrt if tab is on oom         //~v0erI~
//v0eq:970920 optionaize to update oom.default is prohibit(option=(p1))//~v0eqI~
//v0ep:970920 (BUG)shitback err when del tab on mergin boundary    //~v0epI~
//v0e0:970914 MAXLINEDATA chk need if allowed insert into out of mergin//~v0e0I~
//v0dw:970914 CTOL up to mergin for mergin file(also for spf err line)//~v0dwI~
//v0du:970909 for performance,use flag once chked spfnumok         //~v0duI~
//            set on when chked,reset when line update or insert.  //~v0duI~
//v0dq:970908 dose not drop out of mergin for ETOL(cap cut use ETOL)//~v0dpI~
//v0dp:970907 no page shift for ETOL because out of mergin ETOL dose not//~v0dpI~
//            clear in mergin by v0d0                              //~v0dpI~
//v0do:970907 clear lineno fld by EEOL for spf ok line to do join line//~v0doI~
//            (change ulhlen).also for ETOL change ulhlen          //~v0doI~
//v0dj:970907 short record is valid for spf when copy or char input//~v0dhI~
//v0dh:970907 allow update out of mergin                           //~v0dhI~
//v0de:970831 EEOL in mergin when csr <mergin for also not spf mergin file//~v0dbI~
//v0db:970831 for spf;EEOL in mergin,reject EEOL/ETOL/CTOL out of mergin//~v0dbI~
//v0cg:970810 shorten reclen by eol regardless csr pos             //~v0cgI~
//v0ce:970810 (BUG)no csr plh when undo if update line then concatinate//~v0ceI~
//            to prev line.(last undo line is deleted)             //~v0ceI~
//v0cd:970810 allow split at out of mergin                         //~v0cdI~
//v0cc:970803 filegetcidlen return last cidpos                     //~v0cbI~
//v0cb:970802 split allow for long rec even if at out of mergin    //~v0cbI~
//            EOL   allow for long rec even if at out of mergin    //~v0cbI~
//            if mergin=cidpos=topcidpos remain cid                //~v0cbI~
//            else same as no mergin specified                     //~v0cbI~
//v0ca:970802 dont create split lines by del csr when mergin specified//~v0c8I~
//            (cid pos is fixed if mergin specified.and it is for continuation column)//~v0c8I~
//v0c8:970802 filecidlrecl return len in mergin if cidps<mergin    //~v0c8I~
//v0c4:970802 dbcssplit chk,tab reset needed for also char del/eol etc//~v0c4I~
//v0c3:970802 del keep mergin                                      //~v0c3I~
//v0c2:970728 simple principle.do not touch/move out of mergin     //~v0c2I~
//            if mergin not specified,last space is not dropped    //~v0c2I~
//v0by:970728 retore cid for isrt char                             //~v0byI~
//v0bv:970728 split file4-->file42                                 //~v0bpI~
//v0bp:970727 allow erase end of line at out of mergin             //~v0bpI~
//            char.c                                               //~v0bpI~
//v0bo:970727 allow crlf pos del key to concatinate line           //~v0azI~
//            reverse of splitline split.                          //~v0azI~
//            char.c char2.c                                       //~v0azI~
//v0az:970720 errline reverse display                              //~v0azI~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//           -charmaxovererr has maxlen parm                       //~v0avI~
//           (drop out of mergin area when line concatination)     //~v0avI~
//           -expand pre chk(split file2 to file6)                 //~v0avI~
//v09K:970622:change char define value on dbcs tbl                 //~v09KI~
//v09j:970517:accept isrt mode as rep mode when 1 byte field input //~v09jI~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v06h:960310:support Copy/Move file by ALt+a                   //~v06hI~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//v067:960217:(BUG)csr skip to next field when insert field full//~v067I~
//v05D:960105:move deleted line chk to xedlcmd from xechar      //~v05DI~
//v057:951015:(BUG)same as v055 for capdel del CR(line concat)  //~v057I~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v03u:950827:bug;ULHFLINECMD(lcmd reg sw) reset by xechar ignore//~v03uI~
//            lcmd input from other side of same pfc.           //~v03uI~
//            so move lcmd stack to pfh from pfc.(alt of v03q)  //~v03uI~
//*v03q:950826:bug,lcmd ignored by ULHFLINECMD flag on for other client//~v03qI~
//            it may ended after lcmd input.                    //~v03qI~
//*v03k:950813:bug,erase top of line,ULHlen set too long        //~v03kI~
//*v03e:950731:set to ULHdata for dir list                      //~v03eI~
//*v03d:950731:(bug)dir list scroll field input ignored         //~v03dI~
//*v03b:950730:zenkaku err msg for lineno,scroll fld etc        //~v03bI~
//*v03a:950730:scroll err clear when input                      //~v03aI~
//*v034:950715:use func_char_pan for dir                        //~v034I~
//*v020:950616:dir support(field full intercept)                //~v020I~
//*     950616:fldprotchk return pufld                          //~v020R~
//*     950616:pan field err reverse                            //~v020I~
//v01b:950708:bug for capsave when over reclen(need clear also dbcs tbl)//~v01bI~
//v017:950701:fld len set bug for manel                         //~5701I~
//************************************************************* //~v020I~
//*950521 bug:tab char insert and scroll right chk              //~5521I~
//*950507 bug:Pdbcs/Pdata may change after tab expand           //~5507I~
//*       allow ctrl+i(tab) replace input                       //~5507R~
//*950503 bug:box cut remain right padding char,case data drop  //~5503I~
//*           at xefile when save data(drop data at pos padd char)//~5503I~
//*950423 scroll when reached to right                          //~5423R~
//*950111 claer top of line                                     //~5423I~
//*950104 line concatination                                    //~5111I~
//*941123 protchk bug                                           //~5104I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
    #ifdef W32                                                     //~v72NI~
    #else                                                          //~v72NI~
        #define INCL_BASE                                          //~v72NR~
        #include <os2.h>                                           //~v72NR~
    #endif                                                         //~v72NI~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ualloc.h>
#include <ufile.h>                                              //~5318I~
#include <ukbd.h>                                                  //~v72MI~
//#include <utf.h>                                                  //~v72MI~//~v77bI//~v7a6R
#include <udbcschk.h>                                              //~v72MI~//~v777I
#include <utf22.h>                                                //~v72MI~//~v77bI//~v7a6R//~va3xI~
#include <utrace.h>                                               //~v72MI~//~v77bI//~v7a6R//~vaj0I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"
#include "xecsr.h"
#include "xefile.h"
#include "xefile12.h"                                              //~v0dhI~
#include "xefile14.h"                                              //~vbi3I~
#include "xefile22.h"                                              //~v441I~
#include "xefile3.h"                                              //~v441I~//~v73gI
#include "xefile4.h"                                               //~v0bpR~
#include "xefile42.h"                                              //~v0bpI~
#include "xefile6.h"                                               //~v0avR~
#include "xechar.h"                                             //~5124I~
#include "xechar12.h"                                              //~v0erI~
#include "xechar2.h"                                               //~v0azI~
#include "xelcmd.h"                                             //~5105R~
#include "xelcmd2.h"                                            //~5105I~
#include "xeundo.h"
#include "xefunc.h"
#include "xefunc2.h"                                               //~vbi3I~
#include "xepan.h"                                              //~5318I~
#include "xepan2.h"                                             //~5701I~
#ifdef UTF8SUPPH                                                   //~va00I
	#include "xepan22.h"                                             //~5701I~//~va00I
#endif                                                             //~va00I
#include "xesub.h"
#include "xesub2.h"                                                //~va1cR~
#include "xeerr.h"                                              //~v03bI~
#include "xedir.h"                                              //~v03eI~
#include "xedir3.h"                                              //~v03eI~//~v78gI
#include "xefsub.h"                                                //~v179I~
#include "xedlcmd.h"                                               //~v63hI~
#include "xeopt.h"                                                 //~v72NI~
#include "xegbl.h"                                                 //~v72NI~//~v777I
#include "xeutf.h"                                             //~5701I~//~va00I//~vbt4I~
#ifdef UTF8UCS2                                                    //~va20I~
	#include "xeutf2.h"                                             //~5701I~//~va00I//~va20R~
#endif                                                             //~va00I//~va20I~
//*******************************************************
static int Stabexpoksw=0;                                          //~v441R~
static int Snetlen;	//len without cid                              //~v0cdI~
static PULINEH Slcmdplh2;	//parm to char fld edit                //~v0i7R~
//static int Sswresetigm;                                          //~v74uR
static int Snetoomlen;                                             //~v74uI
//*******************************************************       //~v04dI~
//void chartabclear(UCHAR *Pdbcs,int Plen);                        //~v0erR~
//int charfieldfullerr(void);                                      //~v0erR~
int charcaps(PUCLIENTWE Ppcw,PUFILEH Ppfh);                        //~v72MI~
//int charjoinchk(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Pcol,int Popt);//~v42gR~//~v74iR
//#define INMARGINJOIN  0x1000                                       //~v42gI~//~v74iR
int charjoinsetdbcstbl(int Popt,PULINEH Pplh,int *Pppos,int *Pplenc);//~v77gI
int charfldeditchl(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);         //~vbi3R~
int charfldedit_noutf8(int *Prc,int Popt,int Precoff,PUCLIENTWE Ppcw,PULINEH Pplh);//~vbt4I~
//**************************************************
//* menu field char input **************************
//**************************************************
int func_char_pan(PUCLIENTWE Ppcw)
{
	return charpan(Ppcw,UCBITCHK(Gscrstatus,GSCRSINS)!=0);
}
//**************************************************
//* file field char input * file browse/edit panel**            //~v03dR~
//**************************************************
int func_char_file(PUCLIENTWE Ppcw)
{
//  Ppcw->UCWreason=0;	//for filecharcsr and filecharhexinput     //~v442I~//~v73nR
 	return charfile(Ppcw,UCBITCHK(Gscrstatus,GSCRSINS)!=0);
}

//**************************************************
//* menu field char input **************************
//* parm1 :pcw
//* parm2 :operation(Rep/Ins/Del)
//* retrn :r.c
//**************************************************
int charpan(PUCLIENTWE Ppcw,int Popt)
{
	PUSCRD psd;
	PUPANELC ppc;
	PUFLD    pfl;
	UCHAR    *pc,*pcd;
	int rc,pos,len,flen;                                        //~5701R~
	int pfli,x,y;		//field def index
    int cmdfldsw=0,buffend;                                        //~v730I~
    int panutilsw=0;                                               //~v76gI
    PULINEH plh;                                                //~v034I~
	PUFILEH pfh;                                                //~v03uR~
	PUDIRLH pdh;                                                   //~v7aiI
#ifdef UTF8SUPPH                                                   //~va0tI
    UCHAR *pu8=NULL,*pct=NULL;                                               //~va0tI//~vaf9R~
    int swu8=0,buffszu8;                                            //~va0tI//~va0tR~
    PUPANELL pupl;                                                 //~va0tI~
#endif                                                             //~va0tI
//****************************
//#ifdef WXE                                                       //~v63nR~
#if defined(WXE)||defined(LNX)                                     //~v63nI~
    if (Ppcw->UCWtype==UCWTDIR)                                    //~v63hI~
		dlcmddndreset(Ppcw);                                       //~v63hI~
#endif                                                             //~v63hI~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;
	ppc=Ppcw->UCWppc;
	if ((pfli=fldprotchk(Ppcw,FPC_DBCSCHK,&pfl))<0)		//protected//~v020R~
    {                                                              //~v78gI
#ifdef UTF8SUPPH                                                   //~va00I
      if (pfli!=-2) //!dbcsinputerr                                //~va00I
#endif                                                             //~va00I
    	if (Ppcw->UCWtype==UCWTDIR)                                  //~v034M~//~v78gI
          if (Ppcw->UCWrcsrx!=1)  //avoid col1                     //+vbzgI~
        	return dirlocate(0,Ppcw);                              //~v78gI
		return 4;
    }                                                              //~v78gI
	if (UCBITCHK(psd->USDflag2,USDF2CMD))	//command line      //~v03bI~
    {                                                              //~v730I~
		if (pfli)					//scroll field              //~v03bI~
        {                                                          //~v730I~
			if (Ppcw->UCWkeytype==UCWKTDBCS)	//dbcs input    //~v03bI~
				return errdbcsinput();                          //~v03bI~
        }                                                          //~v730I~
        else                                                       //~v730I~
            cmdfldsw=1;                                            //~v730I~
    }                                                              //~v730I~
    else                                                           //~v76gI
    {                                                              //~v77bI
        if (ppc->UPCid==PANOPTCOLOR)                               //~v77bI
        {                                                          //~v77bI
            if (Ppcw->UCWkeytype==UCWKTDBCS                        //~v77bR
            )                                                      //~v77bI
				return errdbcsinput();                          //~v03bI~//~v77bI
            if (Ppcw->UCWkeytype==UCWKTSBCS                        //~v77bI
            &&  !UTF8ISASCII(*Ppcw->UCWkeydata)                    //~v77bI
            )                                                      //~v77bI
				return errnotascii();                              //~v77bI
        }                                                          //~v77bI
        panutilsw=(ppc->UPCid & PANUTIL);                          //~v76gI
    }                                                              //~v77bI
    if (Ppcw->UCWkeytype==UCWKTSBCS                                //~v0hnI~
//  &&  *(Ppcw->UCWkeydata)==0x0a)	//sometimes follow 1c1d when W95//~v0htR~
//    &&  *(Ppcw->UCWkeydata)<0x20    //sometimes follow 1c1d when W95//~v0hNR~
//    &&  *(Ppcw->UCWkeydata)!=0x08   //BS                         //~v0hNR~
//    &&  *(Ppcw->UCWkeydata)!=0x1b   //ESC                        //~v0hNR~
//    &&  *(Ppcw->UCWkeydata)!=TABCHAR)   //TAB                    //~v0hNR~
    &&  (*(Ppcw->UCWkeydata)==0x0a                                 //~v0hNI~
       ||*(Ppcw->UCWkeydata)==0x0d))//sometimes follow 1c0d when W95//~v0hNI~
    	return 4;				//ignore                           //~v0hnI~
//	pfl=((UPANELD*)(psd->USDppd))->UPDpfld;                     //~v020R~
	x=Ppcw->UCWrcsrx;	//col
	y=Ppcw->UCWrcsry;	//row
	pos=pfl->UFLentry[pfli].UFLstart;	//start col
	pc=ppc->UPCline[y].UPLbuff;			//buffer                //~v034M~
	pcd=ppc->UPCline[y].UPLdbcs;		//dbcs id tbl           //~v034M~
    flen=pfl->UFLentry[pfli].UFLend-pfl->UFLentry[pfli].UFLstart;//~v03bM~
//for dir list lcmd input                                       //~v034I~
    if (Ppcw->UCWtype==UCWTDIR                                  //~v034M~
    &&  Ppcw->UCWrcsry>CMDLINENO)                               //~v03eR~
	{                                                           //~v034M~
		plh=psd->USDbuffc;                                      //~v034R~
  		UCBITOFF(plh->ULHflag,ULHFDIRLFLDERR);                  //~v020R~
		if (pfli)//attr or rename                               //~v03eI~
        {                                                       //~v03eI~
			pc=plh->ULHdata-UDHLINENOSZ;                        //~v03eR~
			pcd=plh->ULHdbcs-UDHLINENOSZ;                       //~v03eR~
			len=(int)strlen(pc+pos);					//count strlen//~v03eI~
    		len=min(len,flen);                                  //~v03eI~
#ifdef UTF8SUPPH                                                   //~va0GI~
          if (pfli==PANL310RENAME) //rename fld input              //~va0GR~
          {                                                        //~va0GI~
		    pdh=UGETPDH(plh);                                      //~va0GI~
            pu8=pdh->UDHrename_utf8;                               //~va0GI~
            pct=pdh->UDHrename_codetype;                           //~va0GI~
            buffszu8=UDHRENAME_UTF8SZ;                             //~va0GI~
			rc=charfldeditu8(Popt,    //mode                       //~va0GI~
				   pc,								//buffer       //~va0GI~
				   pcd,								//dbcs id tbl  //~va0GI~
				   pu8,								//utf8buffer   //~va0GI~
                   pct,                             //codetype     //~va0GI~
				   x,             					//current col  //~va0GI~
				   pos,								//fld start col//~va0GI~
				   pos+len,                    		//end col      //~va0GI~
    			   pos+flen,                     	//buff end     //~va0GI~
    			   buffszu8,                     	//buff len     //~va0GI~
				   Ppcw,                                           //~va0GI~
				   0/*pupl*/);                                     //~va0GI~
          }                                                        //~va0GI~
          else                                                     //~va0GI~
#endif                                                             //~va0GI~
          {                                                        //~va0GI~
			rc=charfldedit(Popt,							//mode//~v03eI~
							pc,								//buffer//~v03eI~
				  			pcd,								//dbcs id tbl//~v03eI~
				   			x,             					//current col//~v03eI~
				   			pos,								//fld start col//~v03eI~
				   			pos+len,                    		//end col//~v03eI~
				   			pos+flen,					//buff len//~v03eI~
				   			Ppcw,							//key data and len//~v03eI~
				   			0);								//no plh//~v03eI~
          }                                                        //~va0GI~
			if (!rc)                                            //~v03eI~
            {                                                   //~v03eI~
				UCBITON(plh->ULHflag,ULHFDRAW);		//req redraw//~v03eI~
				pfh=UGETPFH(plh);                               //~v03uR~
				UCBITOFF(pfh->UFHflag2,UFHF2LCMDCOMP);//need command process//~v03uR~
		    	pdh=UGETPDH(plh);                                  //~v7aiI
        		if (pfli==2   //rename fld                         //~v7aiI
//      		&&  x>(pos+len)		//fld overflow                 //~v7aiI//~vawuR~
        		&&  x>=(pos+(int)sizeof(((PUDIRLD)0)->UDDrname))		//fld overflow                 //~v7aiI//~vawuR~
        		&&  x<(pos+flen)		//fld overflow             //~v7aiR
				&&  !UCBITCHK(pdh->UDHflag2,UDHF2RENAMEOVF)   //1st time overflow//~v7aiI
                )                                                  //~v7aiI
                {                                                  //~v7aiI
                	memset(pc+x+Ppcw->UCWkeytype,0,(UINT)(pos+flen-x-Ppcw->UCWkeytype));//~v7aiR
		        	UCBITON(pdh->UDHflag2,UDHF2RENAMEOVF);  //protect clear by func_draw_dir//~v7aiI
            	}                                                  //~v7aiI
                                                                   //~v7aiI
			}                                                   //~v03eI~
        }                                                       //~v03eI~
        else	//linenofld                                     //~v03eI~
        {                                                       //~v03eI~
			if (plh->ULHtype!=ULHTDATA)     	//header line/excluded display//~v034R~
				return 4;                                       //~v034R~
//    		if (UCBITCHK(UGETPDH(plh)->UDHupdatetype,UDHUTNOTEXIST))//~v05DR~
//     		{                                                   //~v05DR~
//	    		uerrmsg("Deleted entry",                        //~v05DR~
//            			"削除済行");                            //~v05DR~
//				return 4;                                       //~v05DR~
//			}                                                   //~v05DR~
        	if (rc=charfile(Ppcw,Popt),rc)                      //~v034R~
				return 4;                                       //~v034I~
			*(pc+pos)=*plh->ULHlinecmd;	//for panfieldevent getfldinput//~v034R~
			*(pcd+pos)=0;                                       //~v034I~
        }	//lineno fld                                        //~v03eI~
	}                                                           //~v034M~
    else                                                        //~v034M~
    {                                                           //~v034M~
//*count cmdline len
    if (cmdfldsw)                                                  //~v730I~
    {                                                              //~v730I~
		pc=ppc->UPCcmddata;                                        //~v730I~
		pcd=ppc->UPCcmddbcs;                                       //~v730I~
    	buffend=UPCCMDFLDWKSZ-1;                                   //~v730I~
#ifdef UTF8SUPPH                                                   //~va0tI
        swu8=CFEO_OPTCMDLINE;     //mixed fld update                             //~va0tI//~va0tR~
        pu8=ppc->UPCcmddatabyutf8;                                 //~va0tI
        pct=ppc->UPCcmdcodetb;                                     //~va0tI
        buffszu8=UPCCMDFLDWKSZ;                                    //~va0tI~
        pupl=0;                                                    //~va0tI~
#endif                                                             //+va0tI
  	}                                                              //~v730I~
  	else                                                           //~v730I~
    if (panutilsw)                                                 //~v76gI
    {                                                              //~v76gI
//    	if (panutildataproc(PANUO_GETLINE,Ppcw,(char**)&pc,(char**)&pcd,&buffend))	//get buffer for expand case//~v76gR//~vaa0R~
//    	if (panutildataproc(PANUO_GETLINE,Ppcw,(char**)(ULONG)(&pc),(char**)(ULONG)(&pcd),&buffend))	//get buffer for expand case//~v76gR//~vaa0I~//~vafkR~
    	if (panutildataproc(PANUO_GETLINE,Ppcw,(char**)(ULPTR)(&pc),(char**)(ULPTR)(&pcd),&buffend))	//get buffer for expand case//~v76gR//~vafkI~
        	return 4;                                              //~v76gI
#ifdef UTF8SUPPH                                                   //~va0tI
		panutilgetpupl(0,Ppcw,&pupl,&buffszu8);                    //~va0tR~
        if (buffszu8)                                              //~va0tI~
        {                                                          //~va0tI~
        	pu8=pupl->UPLbuffbyutf8;                               //~va0tR~
        	pct=pupl->UPLcodetype;                                 //~va0tI~
	        swu8=CFEO_OPTPANUTIL;     //mixed fld update                             //~va0tI//~va0tI~
        }                                                          //~va0tI~
#endif                                                             //~va0tI
    }                                                              //~v76gI
    else                                                           //~v76gI
    {                                                              //~va0tI~
#ifdef UTF8SUPPH                                                   //~va0tI//~va0tI~
		swu8=pangetbuff_utf8(0,Ppcw,y,pfli,&pupl,&pu8,&pct,&buffszu8);//~va0tR~
#endif                                                             //~va0tI//~va0tI~
    	buffend=pfl->UFLentry[pfli].UFLend;      //buff len        //~v730I~
    }                                                              //~va0tI~
	len=(int)strlen(pc+pos);					//count strlen
  if (!cmdfldsw)                                                   //~v730I~
  if (!panutilsw)                                                  //~v76jI
    len=min(len,flen);                                          //~5701I~
#ifdef UTF8SUPPH                                                   //~va0tI//~va1qI~
  if (swu8)                                                        //~va0tI
	rc=charfldeditu8(Popt|swu8,							//mode         //~va0tI//~va0tR~
				   pc,								//buffer       //~va0tI
				   pcd,								//dbcs id tbl  //~va0tI
				   pu8,								//utf8buffer   //~va0tI
                   pct,                             //codetype     //~va0tI
				   x,             					//current col  //~va0tI
				   pos,								//fld start col//~va0tI
				   pos+len,                    		//end col      //~va0tI
    			   buffend,                     	//buff len     //~v730I~//~va0tI
    			   buffszu8,                     	//buff len     //~v730I~//~va0tI//~va0tI~
				   Ppcw,                                           //~va0tR~
				   pupl);							//key data and len//~4C27R~//~va0tI//~va0tI~
  else                                                             //~va0tI
#endif                                                             //~va0tI//~va1qI~
	rc=charfldedit(Popt,							//mode
				   pc,								//buffer
				   pcd,								//dbcs id tbl
				   x,             					//current col
				   pos,								//fld start col
				   pos+len,                    		//end col
//  			   pfl->UFLentry[pfli].UFLend,		//buff len     //~v730R~
    			   buffend,                     	//buff len     //~v730I~
				   Ppcw,							//key data and len//~4C27R~
				   0);								//no plh    //~4C27R~
	}//not dir lcmd                                             //~v034I~
	if (rc) 		//buff overflow
		return rc;
	if (UCBITCHK(psd->USDflag2,USDF2CMD))	//command line      //~v03dR~
    {                                                           //~v03dI~
		if (pfli)			//scroll field                      //~v03dR~
        {                                                       //~v03aI~
			UCBITON(ppc->UPCflag,UPCFSCROLLINPUT);              //~v03dI~
			UCBITOFF(ppc->UPCflag,UPCFSCROLLERR);               //~v03aI~
        }                                                       //~v03aI~
        else                                                    //~v03dI~
        {                                                       //~v06hI~
//#ifdef UTF8SUPPH                                                   //~va00I//~va0tR~
//			BYUTF8_setflddatacmd(0,Ppcw,0);                        //~va00R//~va0tR~
//#else                                                              //~va00I//~va0tR~
			setflddatacmd(Ppcw,0);	//0:copy to UPLbuff only       //~v730I~
//#endif                                                             //~va00I//~va0tR~
	  		UCBITOFF(Ppcw->UCWflag,UCWFCMDERR);//clear cmd err  //~v03dR~
		    if (Ppcw->UCWtype==UCWTFILE)	//edit/browse       //~v06hI~
            	((PUFILEC)(Ppcw->UCWpfc))->UFCpendfcmd=0;//no pending cmd//~v06hR~
		}                                                       //~v06hI~
	}                                                           //~v03dI~
	else                                                        //~v020I~
    {                                                              //~va00I
//      if (Ppcw->UCWtype==UCWTMENU)                                  //~v034M~//+va00I~//~va00I//~va0tR~
//  		pansetflddata_utf8(0/*opt*/,Ppcw,y,pfli);              //~va00R//~va0tR~
    	panflderr(Ppcw,PANFECSRLINE,pfli,PANFERESET);//reset fld err//~v020R~
    }                                                              //~va00I
                                                                //~v034I~
	UCBITON(psd->USDflag2,USDF2DRAW);
    if (!*(pc+pos))	//field cleared                             //~5701M~
        if (rc=panfieldevent(Ppcw,PFE_CLEAR),rc)//intercept field clear//~5701I~
            return rc;                                          //~5701I~
	return 0;
}//charpan
//**************************************************
//* file field char input **************************
//* parm1 :pcw
//* parm2 :operation(Rep/Ins/Del)
//* retrn :r.c
//**************************************************
int charfile(PUCLIENTWE Ppcw,int Popt)
{
static UCHAR Sdummydbcs[ULHLINENOSZ];
//  PUPANELC ppc;                                               //~v03dR~
	PUSCRD 	 psd;
	PUFLD    pfld;
	PULINEH  plh;                                                  //~v0i7R~
	PUFILEC  pfc;
	PUFILEH  pfh;                                               //~v03uI~
	int rc,pfli,recoff,len,newlcmdsw;                           //~v03uR~
//  int mergin;                                                    //~v0i7R~
    int vhexmode,opt;                                              //~v60vI~
    int swcapcmd=0;                                                //~v8@MI
//****************************
    Ppcw->UCWreason=0;	//for filecharcsr and filecharhexinput     //~v442I~//~v73nR
    pfc=Ppcw->UCWpfc;                                              //~vbi3M~
    if (pfc)                                                       //~vbi3M~
    {                                                              //~vbi3M~
    	pfh=pfc->UFCpfh;                                           //~vbi3M~
    	if (pfh && pfh->UFHtype==UFHTCMDHIST)                      //~vbi3M~
    	{                                                          //~vbi3M~
    		if (rc=charfldeditchl(0,Ppcw,pfh),rc>=0)               //~vbi3R~
        		return rc;                                         //~vbi3M~
    	}                                                          //~vbi3M~
    }                                                              //~vbi3M~
 	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;
	if ((pfli=fldprotchk(Ppcw,FPC_NODBCSCHK,&pfld))<0)          //~v020R~
		return 4;

//  ppc=Ppcw->UCWppc;                                           //~v03dR~
//  pfc=Ppcw->UCWpfc;                                              //~v03uR~//~vbi3R~
    pfh=pfc->UFCpfh;                                            //~v03uI~
//    if (UCBITCHK(pfh->UFHflag8,UFHF8CAPSON))                     //~v72mR~
//        if (Ppcw->UCWkeytype==UCWKTSBCS)                         //~v72mR~
//        {                                                        //~v72mR~
//            if (Ppcw->UCWtype==UCWTFILE)    //avoid dirlist lcmd fld//~v72mR~
//            {                                                    //~v72mR~
//                if (*Ppcw->UCWkeydata<'a')  //upper char         //~v72mR~
//                    *Ppcw->UCWkeydata=(UCHAR)(tolower(*(Ppcw->UCWkeydata)));//~v72mR~
//                else                                             //~v72mR~
//                    *Ppcw->UCWkeydata=(UCHAR)(toupper(*(Ppcw->UCWkeydata)));//~v72mR~
//            }                                                    //~v72mR~
//        }                                                        //~v72mR~
   	if (UCBITCHK(pfh->UFHflag8,UFHF8CAPSON))                       //~v72NI~
   		if (UCBITCHK(Goptopt,GOPT_CAPLOCK_CMD))                    //~v72NI~
        {                                                          //~v8@MI
        	charcaps(Ppcw,pfh);                                    //~v72NI~
            swcapcmd=1;                                            //~v8@MI
        }                                                          //~v8@MI
//  mergin=(int)pfh->UFHmergin;                                    //~v0i7R~
//	pfld=((PUPANELD)psd->USDppd)->UPDpfld;                      //~v020R~
	plh=psd->USDbuffc;
    if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))                         //~v60vI~
	    vhexmode=(psd->USDflag2 & (USDF2VHEXLINE1|USDF2VHEXLINE2));//~v60vI~
    else                                                           //~v60vI~
    	vhexmode=0;                                                //~v60vI~
	if (UCBITCHK(psd->USDflag2,USDF2CMD))	//command line
	{
        if (!swcapcmd                                              //~v8@MI
        &&   UCBITCHK(pfh->UFHflag9,UFHF9CAPSONCMD))	//command line//~v8@MR
        	charcaps(Ppcw,pfh);                                    //~v72NI~//~v8@MI
//		if (pfli)					//scroll field              //~v03bR~
//			if (Ppcw->UCWkeytype==UCWKTDBCS)	//dbcs input    //~v03bR~
//				return errdbcsinput();                          //~v03bR~
#ifdef FTPSUPP                                                     //~v8@ZI
      	if (UCBITCHK(Ppcw->UCWflag3,(UCWF33270KBD|UCWF33270KBD2))==(UCWF33270KBD|UCWF33270KBD2))//~v8@ZI~//~v8@ZR
			return func_3270kbd(Ppcw);                                     //~v8@ZI~//~v8@ZI
#endif                                                             //~v8@ZI
		if (rc=charpan(Ppcw,Popt),rc)
			return rc;
//		if (pfli)					//cmd field                 //~v03dR~
//			UCBITON(ppc->UPCflag,UPCFSCROLLINPUT);              //~v03dR~
		return 0;
	}//cmd line
//*** line cmd
	if (!pfli)					//lineno field
	{
		if (Ppcw->UCWkeytype==UCWKTDBCS)	//dbcs input        //~5225R~
			return errdbcsinput();                              //~v03bI~
        else                                                       //~v0hnI~
		    if (Ppcw->UCWkeytype==UCWKTSBCS                        //~v0hnI~
//  		&&  *(Ppcw->UCWkeydata)<0x20)	//sometimes follow 1c1d when W95//~v0hpI~
//          &&  *(Ppcw->UCWkeydata)==0x0a)  //sometimes follow 1c1d when W95//~v0htR~
    		&&  *(Ppcw->UCWkeydata)<0x20	//sometimes follow 1c1d when W95//~v0htR~
    		&&  *(Ppcw->UCWkeydata)!=0x08 	//BS                   //~v0htI~
    		&&  *(Ppcw->UCWkeydata)!=0x1b 	//ESC                  //~v0htI~
    		&&  *(Ppcw->UCWkeydata)!=TABCHAR)	//TAB              //~v0htI~
    			return 4;				//ignore                   //~v0hnI~
		newlcmdsw=!UCBITCHK(plh->ULHflag,ULHFLINECMD);          //~v03qR~
		if (newlcmdsw)//line cmd registration not yest for this pfh//~v03uR~
			if (pfh->UFHcmdlinectr==MAXCMDLINE)//linecmd ctr    //~v03uR~
			{
				uerrmsg("Line cmd max line is %d",
						"行コマンドは最大 %d 行まで入力できます",
						MAXCMDLINE);
				return 4;
			}
		rc=charfldedit(Popt,						//mode rep/del
				   plh->ULHlinecmd,					//buffer
				   Sdummydbcs,         				//dbcs id tbl
				   Ppcw->UCWrcsrx,					//current col
				   pfld->UFLentry[0].UFLstart,		//start col
				   (int)strlen(plh->ULHlinecmd),	//input len
				   pfld->UFLentry[0].UFLend,		//buff len
				   Ppcw,							//pcw       //~4C27R~
				   0);								//no plh    //~4C27R~
		if (rc)				//overflow
			return rc;
		UCBITON(plh->ULHflag,ULHFDRAW);		//req redraw
		UCBITOFF(pfh->UFHflag2,UFHF2LCMDCOMP);//need command process//~v03uI~
		UCBITOFF(plh->ULHflag,ULHFLCMDERR);//reset err lcmd        //~v0azI~
		UCBITOFF(plh->ULHflag3,ULHF3ERRLINE);//reset err line      //~v0azI~
		if (newlcmdsw)//line cmd registration not yest for this pfh//~v03uR~
		{
 			UCBITON(plh->ULHflag,ULHFLINECMD);//line cmd input     //~vb81R~
			pfh->UFHcmdline[pfh->UFHcmdlinectr++]=plh;	//save cmd line//~v03uR~
	    	UTRACEP("@@@1 %s:add %c cmd,cmdlinectr=%d\n",UTT,*plh->ULHlinecmd,pfh->UFHcmdlinectr);//~vaz8R~
		}
#ifndef NOTRACE                                                    //~vb81I~
		else                                                       //~vb81I~
        {                                                          //~vb81I~
        	int idx;                                               //~vb81I~
			idx=dlcsrchplh(0,pfh,plh);                             //~vb81I~
			if (idx<0)	//old but not registered on UFHcmdline     //~vb81R~
//          	uerrmsg("%s:internal error UFHcmdlinectr=%d,idx=%d,plh=%p,lineno=%d\n",0,//~vb81R~//~vb97R~
            	uerrexit("%s:internal error UFHcmdlinectr=%d,idx=%d,plh=%p,lineno=%d\n",0,//~vb97I~
					UTT,pfh->UFHcmdlinectr,idx,plh,plh->ULHlinenor);//~vb81I~
                		                                           //~vb81I~
        }                                                          //~vb81I~
#endif                                                             //~vb81I~
		return 0;
	}//lineno fld input

	if (plh->ULHtype!=ULHTDATA)     	//header line/excluded display
		return 4;
    if (UCBITCHK(plh->ULHflag4,ULHF4PROTLINE))//protected line     //~v0ihR~
		return 4;                                                  //~v0ihI~

//  if ((recoff=pfc->UFCleft+Ppcw->UCWrcsrx-Ppcw->UCWlinenosz)>=MAXLINEDATA)	//current col//~v0avR~
//  	return charmaxovererr(MAXLINEDATA);                                    //~51//~v0avR~
//  if ((recoff=pfc->UFCleft+Ppcw->UCWrcsrx-Ppcw->UCWlinenosz)>=mergin)	//current col//~v0bpR~
//    if (Popt!=CHAROPDEL		//not del                          //~v0bpR~
//    ||  recoff!=plh->ULHlen)	//not del cr                       //~v0bpR~
//  	return charmerginerr(mergin);                                    //~51//~v0bpR~
    recoff=pfc->UFCleft+Ppcw->UCWrcsrx-Ppcw->UCWlinenosz;          //~v0bpI~
    if (recoff<pfh->UFHprotlen)                                    //~v0ihR~
		return 4;                                                  //~v0ihI~
	if (Popt==CHAROPDEL)	//del                               //~5104I~
	{                                                           //~5104I~
		if (recoff==plh->ULHlen)	//del cr                    //~5104I~
		{                                                       //~5104I~
//            plhnext=UGETQNEXT(plh);                             //~5104I~
//            if (!plhnext || plhnext->ULHtype!=ULHTDATA) //not data//~5104I~
//                return 4;                                       //~5104I~
//            if (!plhnext->ULHdbcs)  //not once displayed        //~5104I~
//                if (filechktabdbcs(plhnext)==UALLOC_FAILED)//expand data len//~v04dR~
//                    return 4;                                   //~v04dI~
////          if ((len=plh->ULHlen+plhnext->ULHlen)>MAXLINEDATA)     //~v0avR~
////              return charmaxovererr(MAXLINEDATA);                            //~51//~v0avR~
//            Snetlen=                                               //~v0cdI~
//            len=filecidlrecl2(plhnext,pfh); //len without cid      //~v0cdR~
//            if (filemerginchk(plh,recoff,plhnext->ULHdata,len,0,//dellen=0//~v0c2R~
//                                MERGIN_NOMSG,0,0,0))//no errmsg,addlen=newlen=oomlen=0//~v0c2I~
////              return charmaxovererr(mergin);                            //~51//~v0azR~
//              if (UCBITCHK(pfh->UFHflag2,UFHF2MERGIN))             //~v0c8I~
//                return charmaxovererr(mergin);                            //~51//~v0c8I~
//              else                                                 //~v0c8I~
//                if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))//already split//~v0azI~
//                {                                                  //~v0c2I~
//                    uerrmsg("Already one of split lines",          //~v0c2I~
//                            "既に分割行の一部です");               //~v0c2I~
//                    return 4;                                      //~v0azI~
//                }                                                  //~v0c2I~
//                else                                               //~v0azR~
//                    return charconcatline(Ppcw,plh,plhnext);       //~v0azR~
////          len=plh->ULHlen+plhnext->ULHlen;                       //~v0c8R~
//            len=plh->ULHlen+len;    //drop nextline cid            //~v0c8I~
//            if (len>plh->ULHbufflen)                            //~5104R~
//                if (fileexpandbuff(plh,len)==UALLOC_FAILED)     //expand buff//~v04dR~
//                    return 4;                                   //~v04dI~
//  		if (rc=charjoinchk(Ppcw,plh,0,recoff,0),rc)	           //~v47jR~
    		if (rc=charjoinchk(Ppcw,plh,0,recoff,0),rc>1)          //~v47jI~
            	return rc;                                         //~v0i7R~
			UPCTRREQ(pfh);	//end of a shot                        //~v0ceI~
            if (rc==1)		//line concatinated concat line        //~v47jI~
            	return 0;                                          //~v47jI~
		}//del CR                                               //~5104I~
	}                                                           //~5104I~
	else		//not del                                       //~5104I~
    {                                                              //~v69JI~
//  	if ((len=max(recoff,plh->ULHlen)+2)>plh->ULHbufflen)       //~va22R~
		if ((len=max(recoff,plh->ULHlen)+MAX_MBCSLEN)>plh->ULHbufflen)//~va22I~
			if (fileexpandbuff(plh,len)==UALLOC_FAILED)		//expand buff//~v04dR~
               	return 4;                                       //~v04dI~
//      if (UCBITCHK(pfh->UFHflag8,UFHF8CAPSON))                   //~v71UR~
//      	if (Ppcw->UCWkeytype==UCWKTSBCS)                       //~v71UR~
//          	*Ppcw->UCWkeydata=(UCHAR)(toupper(*(Ppcw->UCWkeydata)));//~v71UR~
      	if (UCBITCHK(pfh->UFHflag8,UFHF8CAPSON))                   //~v72mR~
   	  	  if (!UCBITCHK(Goptopt,GOPT_CAPLOCK_CMD))                 //~v72NI~
        	charcaps(Ppcw,pfh);                                    //~v72MI~
//            if (Ppcw->UCWkeytype==UCWKTSBCS)                       //+v72mR~,//~v72MR~
//            {                                                      //+v72mR~,//~v72MR~
//                if (*Ppcw->UCWkeydata<'a')  //upper char           //+v72mR~,//~v72MR~
//                    *Ppcw->UCWkeydata=(UCHAR)(tolower(*(Ppcw->UCWkeydata)));//+v72mR~,//~v72MR~
//                else                                               //+v72mR~,//~v72MR~
//                    *Ppcw->UCWkeydata=(UCHAR)(toupper(*(Ppcw->UCWkeydata)));//+v72mR~,//~v72MR~
//            }                                                      //+v72mR~,//~v72MR~
    }                                                              //~v69JI~
//  rc=charfldedit(Popt,							//mode         //~v60vR~
    opt=Popt|(int)((UINT)vhexmode<<8); //notify vhexmode           //~v618R~
  if (!charfldedit_noutf8(&rc,opt,recoff,Ppcw,plh))                //~vbt4I~
    rc=charfldedit(opt,							//mode             //~v60vI~
				   plh->ULHdata,					//buffer
				   plh->ULHdbcs,					//buffer
				   recoff,							//current col
				   0,                          		//start col
				   plh->ULHlen,						//end col
				   plh->ULHbufflen,					//buff len last 
				   Ppcw,							//pcw       //~4C27R~
				   plh);							//update ctr etc
    if (Ppcw->UCWreason==UCWREASON_HEXSTEPDEL)	//del of long line hex part//~v73nR
        filecharcsr(Ppcw);  //step back by data shortened          //~v73nR
#ifdef UTF8SUPPH                                                   //~va1cR~
    else                                                           //~va1cR~
    if (Ppcw->UCWreason==UCWREASON_DELEOLGB4)	//del eol          //~va1cR~
        filecharcsr(Ppcw);  //csr right if new gb4 char combined   //~va1cR~
#endif                                                             //~va1cR~
	if (rc)
		return rc;
                                                                //~5423I~
//*update scr dbcstbl for func_right at func_char,func_nexttab_file//~5423I~
//	if ((len=min(plh->ULHlen-recoff,Ppcw->UCWwidth-Ppcw->UCWrcsrx))>0)//~5423R~
//		csrsetdbcstbl2(Ppcw->UCWorgx+Ppcw->UCWrcsrx,Ppcw->UCWorgy+Ppcw->UCWrcsry,//~5423R~
//						plh->ULHdbcs+recoff,len);//for tab or dbcs//~5423R~
//*set right step count for func_right                          //~5423I~
	return 0;
}//charfile
//**************************************************               //~vbt4I~
int charfldedit_noutf8(int *Prc,int Popt,int Precoff,PUCLIENTWE Ppcw,PULINEH Pplh)//~vbt4I~
{                                                                  //~vbt4I~
	int done=0,rc=0,u8len,recoff,ii;                               //~vbt4R~
    char *pu8;                                                     //~vbt4I~
//****************                                                 //~vbt4I~
    UTRACEP("%s:charfldedit_noutf8 Gotherstatus=x%x,utf8str=%s\n",UTT,Gotherstatus,Ppcw->UCWkeydata_utf8str);//~vbt4I~
	if (Gotherstatus & GOTHERS_NOUTF8     //-Nm                    //~vbt4I~
	&&  Gutfmode2 & GUM2_KBDUTF8     //A+u                         //~vbt4I~
    &&  UCBITCHK(Ppcw->UCWflag2,UCWF2UTF8STR)                      //~vbt4I~
    &&  *(Ppcw->UCWkeydata_utf8str+1)    //u8len>1                 //~vbt4R~
    &&  !FILEUTF8MODE(UGETPFH(Pplh))                               //~vbt4I~
    )                                                              //~vbt4I~
    {                                                              //~vbt4I~
        done=1;                                                    //~vbt4I~
    	pu8=Ppcw->UCWkeydata_utf8str;                              //~vbt4I~
    	u8len=(int)strlen(pu8);                                    //~vbt4I~
        recoff=Precoff;                                            //~vbt4I~
        Ppcw->UCWkeytype=UCWKTSBCS;                                //~vbt4I~
	    Ppcw->UCWkeydata[1]=0;                                     //~vbt4I~
        for (ii=0;ii<u8len;ii++)                                   //~vbt4I~
        {                                                          //~vbt4I~
	        Ppcw->UCWkeydata[0]=*pu8;                              //~vbt4R~
    		rc=charfldedit(Popt,							//mode //~vbt4I~
				   Pplh->ULHdata,					//buffer       //~vbt4I~
				   Pplh->ULHdbcs,					//buffer       //~vbt4I~
				   recoff,							//current col  //~vbt4I~
				   0,                          		//start col    //~vbt4I~
				   Pplh->ULHlen,						//end col  //~vbt4I~
				   Pplh->ULHbufflen,					//buff len last//~vbt4I~
				   Ppcw,							//pcw          //~vbt4I~
				   Pplh);							//update ctr etc//~vbt4I~
            if (rc)                                                //~vbt4I~
            	break;                                             //~vbt4I~
            recoff++;                                              //~vbt4I~
            pu8++;                                                 //~vbt4I~
        }                                                          //~vbt4I~
        if (recoff>Precoff)                                        //~vbt4I~
	        csronthefld(Ppcw,Ppcw->UCWrcsry,0,Ppcw->UCWrcsrx+recoff-Precoff-1);     //-1 by csrcharright by filecharcsr//~vbt4R~
    }                                                              //~vbt4I~
    UTRACEP("%s:charfldedit_noutf8 done=%d,rc=%d\n",UTT,done,rc);  //~vbt4I~
    *Prc=rc;                                                       //~vbt4I~
    return done;                                                   //~vbt4I~
}                                                                //~5124I~//~vbt4R~
//**************************************************               //~v72MI~
//*caps on process                                                 //~v72MI~
//*if linux console version:reverse lower<-->upper                 //~v72MI~
//*else lower by shift key                                         //~v72MI~
//**************************************************               //~v72MI~
int charcaps(PUCLIENTWE Ppcw,PUFILEH Ppfh)                         //~v72MI~
{                                                                  //~v72MI~
	if (Ppcw->UCWkeytype!=UCWKTSBCS)                       //+v72mR~,//~v72MI~
    	return 0;                                                  //~v72MI~
#if defined(LNX) && !defined(XXE)                                  //~v72MI~
    if (*Ppcw->UCWkeydata<'a')  //upper char           //+v72mR~,  //~v72MI~
        *Ppcw->UCWkeydata=(UCHAR)(tolower(*(Ppcw->UCWkeydata)));//+v72mR~,//~v72MI~
    else                                               //+v72mR~,  //~v72MI~
        *Ppcw->UCWkeydata=(UCHAR)(toupper(*(Ppcw->UCWkeydata)));//+v72mR~,//~v72MI~
#else                                                              //~v72MI~
    if (Ppcw->UCWkeyshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT))  //upper char           //+v72mR~,//~v72MI~
        *Ppcw->UCWkeydata=(UCHAR)(tolower(*(Ppcw->UCWkeydata)));//+v72mR~,//~v72MI~
    else                                               //+v72mR~,  //~v72MI~
        *Ppcw->UCWkeydata=(UCHAR)(toupper(*(Ppcw->UCWkeydata)));//+v72mR~,//~v72MI~
#endif                                                             //~v72MI~
    return 0;                                                      //~v72MI~
}//charcaps                                                        //~v72MI~
//**************************************************
//*join line pre chk,called also from lcmd 'J'                     //~v0i7R~
//*parm1:pcw                                                       //~v0i7R~
//*parm2:1st plh                                                   //~v0i7I~
//*parm3:2nd plh to be join,0 if join to next                      //~v0i7R~
//*parm4:column                                                    //~v0i7R~
//*return:0:ok,4:split line err,UALLOC_FAILED                      //~v0i7I~
//**************************************************
int charjoinchk(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Pcol,int Popt)//~v42gR~
{
	PULINEH plh,plhnext;                                           //~v0i7I~
    PUFILEH pfh;                                                   //~v0i7I~
    int len,recoff;                                                //~v0i7R~
    int opt;                                                       //~v42gI~
    int oomlen=0,marginchklen;                                     //~v74iR
    int cuteolspace,coboffs=0;                                     //~v74zR
//********************                                             //~v0i7I~
//  Sswresetigm=0;                                                 //~v74uR
	pfh=UGETPFH(Pplh1);                                            //~v0i7I~
	plh=Pplh1;                                                     //~v0i7I~
    recoff=Pcol;                                                   //~v0i7I~
  if (Pplh2)                                                       //~v0i7I~
    plhnext=Pplh2;                                                 //~v0i7I~
  else                                                             //~v0i7I~
    plhnext=UGETQNEXT(plh);
    if (!plhnext || plhnext->ULHtype!=ULHTDATA) //not data
        return 4;
    if (!plhnext->ULHdbcs)  //not once displayed
        if (filechktabdbcs(plhnext)==UALLOC_FAILED)//expand data len
            return UALLOC_FAILED;                                  //~v0i7R~
    Snetlen=
    len=filecidlrecl2(plhnext,pfh); //len without cid
    Snetoomlen=0;                                                  //~v74uM
  	if (len>pfh->UFHmergin) //margin exit,but notr valid spf number//~v74uR
    {                                                              //~v74zR
    	cuteolspace=plhnext->ULHlen-len;                           //~v74uR
    	oomlen=filegetoomlen(pfh,plhnext);  //out of mergin len//~v0esR~//~v74zR
        if (oomlen>0)                                              //~v74zR
            oomlen-=cuteolspace;                                   //~v74zR
        Snetoomlen=oomlen;                                         //~v74zR
    }                                                              //~v74zR
//  marginchklen=len;                                              //~v74mR
    if (UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file             //~v42gI~
    {                                                              //~v42gI~
    	if (len>SPFCOBNUMFLDLEN)                                   //~v42gI~
        {                                                          //~v74zR
        	len-=SPFCOBNUMFLDLEN;                                  //~v42gI~
        	coboffs=SPFCOBNUMFLDLEN;                                  //~v42gI~//~v74zR
        }                                                          //~v74zR
        else                                                       //~v42gI~
        	len=0;                                                 //~v42gI~
        Snetlen=len;                                               //~v42gR~
    }                                                              //~v42gI~
    marginchklen=len;                                              //~v74mI
  if (Popt & IGMARGINJOIN)	//ignore margin                        //~v74iM
  {                                                                //~v74iM
        opt=MERGIN_JOINSPF;                                        //~v42gR~//~v74iM
        marginchklen=filecidlrecl(plhnext,pfh); //len in mergin widthout cid//~v74mR
    	if (UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file             //~v42gI~//~v74mI
    		if (marginchklen>SPFCOBNUMFLDLEN)                                   //~v42gI~//~v74mI
        		marginchklen-=SPFCOBNUMFLDLEN;                                  //~v42gI~//~v74mI
//      if (len+oomlen<=plhnext->ULHlen)		//oom is valid spfnumber//~v74uR
//  		Sswresetigm=1;                                         //~v74uR
  }                                                                //~v74iM
  else                                                             //~v74iM
  {                                                                //~v74iM
    if (Popt & INMARGINJOIN)                                       //~v42gI~
        opt=MERGIN_JOINSPF;                                        //~v42gR~
    else                                                           //~v42gI~
        opt=0;                                                     //~v42gI~
  }                                                                //~v74iI
//  if (filemerginchk(plh,recoff,plhnext->ULHdata,len,0,//dellen=0 //~v74iR
//  if (filemerginchk(plh,recoff,plhnext->ULHdata,marginchklen,0,//dellen=0//~v74uR
#ifdef UTF8UCS2                                                    //~va20I~
    if (filemerginchk(plh,recoff,plhnext->ULHdata+coboffs,plhnext->ULHdbcs+coboffs,marginchklen,0,//dellen=0//~v74zR//~va20I~
#else                                                              //~va20I~
    if (filemerginchk(plh,recoff,plhnext->ULHdata+coboffs,marginchklen,0,//dellen=0//~v74zR
#endif                                                             //~va20I~
                        opt|                                       //~v42gI~
                        MERGIN_NOMSG,0,0,0))//no errmsg,addlen=newlen=oomlen=0
    {                                                              //~v58RI~
      if (UCBITCHK(pfh->UFHflag2,UFHF2MERGIN))
        return charmaxovererr((int)pfh->UFHmergin);                //~v0i7R~
      else
        if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))//already split
        {
            uerrmsg("Already one of split lines",
                    "既に分割行の一部です");
            return 4;
        }
        else
            return charconcatline(Ppcw,plh,plhnext);
    }//merginchk                                                   //~v58RI~
    if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT1) //has no follower     //~v47jR~
    &&   UCBITCHK(plh->ULHflag2,ULHF2SPLIT2) //has prev //last of concat//~v47jR~
    &&   UCBITCHK(plhnext->ULHflag2,ULHF2SPLIT1))//has follower    //~v47jI~
        return charconcatline(Ppcw,plh,plhnext);                   //~v47jR~
  if (Popt & INMARGINJOIN)                                         //~v42gI~
    len=Pcol+len;    //ignore numfld                               //~v42gI~
  else                                                             //~v42gI~
//  len=plh->ULHlen+len;    //drop nextline cid                    //~v74iR
    len=plh->ULHlen+len+oomlen;    //drop nextline cid             //~v74iI
    if (len>plh->ULHbufflen)
        if (fileexpandbuff(plh,len)==UALLOC_FAILED)     //expand buff
            return UALLOC_FAILED;                                  //~v0i7R~
	return 0;                                                      //~v0i7I~
}//charjoinchk                                                     //~v0i7R~
//**************************************************               //~v0i7I~
//*join line,intf with charfldedit fir 'J'(join) lcmd              //~v0i7I~
//*parm1:pcw                                                       //~v0i7I~
//*parm2:1st plh (join to)                                         //~v179R~
//*parm3:2nd plh (join from),0 if join to next                     //~v179R~
//*return:0:ok,4:split line err,UALLOC_FAILED                      //~v0i7I~
//**************************************************               //~v0i7I~
//int charlcmdjoin(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2)      //~v0i7I~//~v74iR
int charlcmdjoin(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2)//~v74iI
{                                                                  //~v0i7I~
	PUFILEH pfh;                                                   //~v42gI~
    int rc,reclen;                                                 //~v0i7R~
    int opt,mode;                                                  //~v42gR~
//********************                                             //~v0i7I~
	if (!(Pplh1=fsubnextlineoversplit(0,Pplh1,0,0)))               //~v179R~
						//no ignore excluded,last of concat lines,no stopplh//~v179R~
        return 4;		//err protection                           //~v179R~
                                                                   //~v179I~
	if (!Pplh1->ULHdbcs)                                           //~v0i7M~
    	if (filechktabdbcs(Pplh1)==UALLOC_FAILED)                  //~v0i7M~
        		return UALLOC_FAILED;                              //~v0i7M~
    reclen=Pplh1->ULHlen;                                          //~v0i7I~
    pfh=UGETPFH(Pplh1);                                            //~v42gI~
    mode=0;                                                        //~v74qI
  if (UCBITCHK(pfh->UFHflag2,UFHF2MERGIN)                          //~v74iI
  &&  Popt & CLJ_IGM)                                              //~v74iI
  {                                                                //~v74iI
//    reclen=filecidlrecl2(Pplh1,pfh); //len without cid(ignore margin)//~v74AR
      mode=CHAROPJOINIGM;		                                   //~v74qR
      opt=IGMARGINJOIN;   //ignore margin err at charjoinchk       //~v74qR
  }                                                                //~v74iI
  else                                                             //~v74qI
  {                                                                //~v74iI
    if (pfh->UFHspfpos                                             //~v42gR~
	&&  UCBITCHK(pfh->UFHflag3,UFHF3OOMNOPROT))                    //~v42gR~
    {                                                              //~v42gI~
    	reclen=filecidlrecl2(Pplh1,pfh); //len without cid         //~v42gI~
    	opt=INMARGINJOIN;                                          //~v42gI~
        mode=CHAROPIMJOIN;                                         //~v42gI~
    }                                                              //~v42gI~
    else                                                           //~v42gI~
    {                                                              //~v42gI~
    	opt=0;                                                     //~v42gI~
        mode=CHAROPDEL;			//normal del cr                    //~v42gI~
    }                                                              //~v42gI~
  }                                                                //~v74iI
    if (rc=charjoinchk(Ppcw,Pplh1,Pplh2,reclen,opt),rc)            //~v42gR~
    	return rc;                                                 //~v0i7M~
//  if (Sswresetigm)                                               //~v74uR
//      mode=CHAROPIMJOIN;                                         //~v42gI~//~v74uR
	Slcmdplh2=Pplh2;	//parm to char fld edit                    //~v0i7I~
	rc=charfldedit(mode,                                           //~v42gR~
					Pplh1->ULHdata,                                //~v0i7I~
					Pplh1->ULHdbcs,                                //~v0i7I~
                    reclen,			//cur col                      //~v0i7I~
                    0,              //start col                    //~v0i7I~
                    reclen,	//endcol                               //~v0i7I~
                    Pplh1->ULHbufflen,//bufflen                    //~v0i7R~
					Ppcw,                                          //~v0i7I~
					Pplh1);                                        //~v0i7I~
	Slcmdplh2=0;	//parm to char fld edit                        //~v0i7I~
	return rc;                                                     //~v0i7I~
}//charlcmdjoin                                                    //~v0i7I~
//**************************************************
//*char field input process
//*parm 1:mode 0:rep 1:insert 2:del 3:erase eof
//*parm 2:input and output buff
//*parm 3:dbcs attr tbl
//*parm 4:current cursor column
//*parm 5:buffer start column
//*parm 6:buffer end column
//*parm 7:buffer alloc size
//*parm 8:input data addr
//*parm 9:ULINEH addr
//*return:0:ok  ,4:buff overflow
//**************************************************
int charfldedit(int Pmode,UCHAR *Pbuff,UCHAR *Pdbcs,
				int Pcurcol,int Pstartcol,int Pendcol,int Pbuffend,
				PUCLIENTWE Ppcw,PULINEH Pplh)                   //~4C27R~
{
//static UCHAR Sdbcsid[2]="\x01\x02";	//dbcs id                  //~v09KR~
static UCHAR Sdbcsid[2]={DBCS1STCHAR,DBCS2NDCHAR};                 //~v09KI~
#ifdef UTF8SUPPH                                                   //~va1cR~
static UCHAR Sdbcsidss3[]=UDBCSCHK_DBCSIDSTRSS3;                   //~va1cR~
static UCHAR Sdbcsidgb4[]=UDBCSCHK_DBCSIDSTRGB4;                   //~va1cR~
#endif                                                             //~va1cR~
	UCHAR *pc,*pcd;                                             //~5506R~
	UCHAR *keyindata;                                           //~4C27I~
    PULINEH plhnext;                                            //~5104I~
    PUFILEH  pfh=NULL;                                                  //~v0byR~//~vaf9R~
	int len,addlen=0,keyindatalen;                                //~5507R~//~vafcR~
	int mergin=0;                                                    //~v0avR~//~vafcR~
    int oomlen=0;	//out of mergin len                            //~v0dhR~
    int spfsw2=0;                                                  //~v0dhR~
    int spfpos=0;                                                    //~v417I~//~vafcR~
    int merginsw=0;                                                  //~v0dbI~//~vafcR~
    int coboffs;                                                   //~v42gI~
    int oomprotsw=0;                                               //~v0eqR~
    int newlen;                                                    //~v0e0I~
    int inmerginsw;                                                //~v0evI~
    int protlen=0;                                                 //~v0ihI~
    int binsw=0;                                                   //~v106I~
    int hexmodesw=0;                                               //~v444I~
    int datapos,hexinpsw;                                          //~v441R~
//    int lastcidpos;//top cid pos                                 //~v0cgR~
	int vhexmode,vhexolddata;		//virtical hex display mode    //~v60vI~
    UCHAR vhexnewchar;                                             //~v60vR~
    int rcmc=0;   //marginchk rc(==1:overflow but space only)      //~v71UR~
    int opt;                                                       //~v73gI
    int imlen;                                                     //~v73pI
    int delpadctr,ii;                                              //~v73hI
    int tabrepsw;                                                  //~v73wI
    int hexkbdsw;                                                  //~v778I
    int hexkbdgcsw; //hex notation graph char input                //~v79RI
    int joinpos;                                                   //~v77gI
    int tabskip=1;                                                 //~v8@2I
    int newlen2,addlen2;                                           //~v7a0R
#ifdef LNX                                                         //~v777I
    int hankanasw=0;                                               //~v777I
#endif                                                             //~v777I
#ifdef UTF8SUPPH                                                   //~va1cR~
    int splitdbcsctr;                                              //~v777I//~va1cR~
#endif                                                             //~v777I//~va1cR~
#ifdef UTF8UCS2                                                    //~va20I~
//  int swutf8file=0,swutf8data=0,keyindatalen_dd,rc3,ucsdatapos,u8vhexrepsw;//~va20R~//~vafcR~
    int swutf8file=0,swutf8data=0,keyindatalen_dd=0,rc3,ucsdatapos,u8vhexrepsw=0;//~vafcR~
  #ifdef UTF8UTF16                                                 //~vaw3I~
    UCHAR   keyindata_dddata[4];	//ddlen max=2,4 for safety(4 on LINUX previously)//~vaw3I~
    UCHAR   keyindata_dddbcs[4];                                   //~vaw3I~
  #else                                                            //~vaw3I~
    UCHAR   keyindata_dddata[sizeof(WUCS)];  //key data 1 or 2 byte,or 4 byte for GB18030//~va20I~
    UCHAR   keyindata_dddbcs[sizeof(WUCS)];  //key data 1 or 2 byte,or 4 byte for GB18030//~va20I~
  #endif                                                           //~vaw3I~
#endif                                                             //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
	int delpadlen=0;                                               //~va3xI~//~vafdR~
#endif                                                             //~va3xI~
    int optorg;                                                    //~va3SI~
//****************************
    UTRACEP("%s:mode=x%x,curCol=%d\n",UTT,Pmode,Pcurcol);          //~vbt4R~
//#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~//~vaf9R~
	if (Pplh)                                                      //~va50R~
    {                                                              //~va50I~
		pfh=UGETPFH(Pplh);                                         //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~vaf9I~
		if (PFH_ISEBC(pfh))                                        //~va50I~
			return charfldeditebc(Pmode,Pbuff,Pdbcs,Pcurcol,Pstartcol,Pendcol,Pbuffend,Ppcw,Pplh,//~va50R~
					Slcmdplh2,Snetlen,Snetoomlen);                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~vaf9I~
    }                                                              //~va50I~
//#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~vaf9R~
    optorg=Pmode;                                                  //~va3SI~
    Pmode &=0xffff; //vhexmode and ope code                        //~va3SI~
    vhexmode=(int)((UINT)Pmode>>8);                                //~v60vR~
    Pmode&=0xff;	//clear vhexmode parm;mode byte                //~v60vR~
	hexinpsw=0;				//next hex csr position                //~v441R~
    hexkbdsw=UCBITCHK(Ppcw->UCWflag3,UCWF3HEXKBD);                 //~v79RR
	hexkbdgcsw=UCBITCHK(Ppcw->UCWflag3,UCWF3HEXKBDGC); //graph char input//~v79RR
	if (Pplh)                                                      //~v0avI~
    {                                                              //~v0byI~
	    hexkbdsw|=hexkbdgcsw;	//do filesetdbcstbl                //~v79RI
//#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~//~vaf9R~
//#else                             done but for C4701                                 //~va50I~//~vaf9R~
//		pfh=UGETPFH(Pplh);                                         //~v0byR~//~vaf9R~
//#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~vaf9R~
        tabskip=pfh->UFHtabskip;                                   //~v8@2I
		if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                      //~v106I~
        	binsw=1;	//no tab skip                              //~v106I~
        if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                      //~v444I~
            hexmodesw=1;                                           //~v444I~
	    if ((vhexmode & USDF2VHEXLINE2)         //csr on lower vhex line//~va3TI~
        &&  (Goptopt3 & GOPT3_VHEXCSRZIGZAG)    //zigzag csr mov mode//~va3TI~
        &&  (Pmode==CHAROPINS)                                     //~va3TI~
        )                                                          //~va3TI~
        	Pmode=CHAROPREP;	//replace lower line hex char      //~va3TI~
#ifdef UTF8UCS2                                                    //~va20I~
        memset(keyindata_dddbcs,0,sizeof(keyindata_dddbcs));       //~va5QI~
        swutf8file=FILEUTF8MODE(pfh);                              //~va20I~
        if (swutf8file)                                            //~va20I~
        {                                                          //~va20I~
            u8vhexrepsw=0;                                         //~va20I~
            if (Pmode==CHAROPREP||Pmode==CHAROPINS)                //~va20I~
            {                                                      //~va20I~
                if (vhexmode)                                      //~va20I~
                {                                                  //~va20I~
                    rc3=xeutf_chargetvhexdd(Pmode,vhexmode,Ppcw,Pplh,Pcurcol,keyindata_dddata,keyindata_dddbcs,&keyindatalen_dd,&ucsdatapos);//~va20R~
                    Pcurcol=ucsdatapos;	//updatae plh datapos      //~va20R~
                    if (rc3 & XEUTF_VHEXRC_ERR)	//insert split ucs //~va20I~
                    	return 4;                                  //~va20I~
                    if (rc3 & XEUTF_VHEXRC_INSREP)	//insert split ucs//~va20R~
                    	Pmode=CHAROPREP;	//rep the ucs          //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
                  if (rc3 & XEUTF_VHEXRC_UCS4)	//3 byte rep by makeucs4//~va3xI~
                  {                                                //~va3xI~
                    Pmode=CHAROPDEL;	//rep the ucs              //~va3xI~
                    //u8vhexrepsw is effective on OPDEL            //~vafcI~
                    delpadlen=keyindatalen_dd>>8;                  //~va3xI~
                    keyindatalen_dd &= 0xff;                       //~va3xI~
                    u8vhexrepsw=3-keyindatalen_dd; //del 2 for sbcs,1 for dbcs//~va3xR~
                  }//UCS4                                          //~va3xI~
                  else                                             //~va3xI~
#endif                                                             //~va3xI~
                  {//UCS2                                          //~va3xI~
                    if (rc3 & XEUTF_VHEXRC_S2D)	//insert split ucs //~va20I~
                    {                                              //~va20I~
                        keyindatalen_dd=1;  //insert 1 byte rep 1 byte//~va20I~
                    	u8vhexrepsw=1; //expand                    //~va20I~
                    	Pmode=CHAROPINS;	//rep the ucs          //~va20I~
                    }                                              //~va20I~
                    else                                           //~va20I~
                    if (rc3 & XEUTF_VHEXRC_D2S)	//insert split ucs //~va20I~
                    {                                              //~va20I~
//                      keyindatalen_dd=1;  //delete 1 byte rep 1 byte//~va20I~//~va38R~
                    	u8vhexrepsw=-1;  //shrink                  //~va20R~
                    	Pmode=CHAROPDEL;	//rep the ucs          //~va20I~
		                //u8vhexrepsw is effective on OPDEL        //~vafcI~
                    }                                              //~va20I~
                  }//UCS2                                          //~va3xI~
                }                                                  //~va20I~
                else                                               //~va20I~
                {                                                  //~va20I~
                	rc3=xeutf_chargetkbddd(0,Ppcw,keyindata_dddata,keyindata_dddbcs,&keyindatalen_dd);//~va20R~
                	if (rc3>=4)                                    //~va20R~
                    	return 4;                                  //~va20R~
                }                                                  //~va20I~
	            swutf8data=(*keyindata_dddbcs!=0);//	f2l err or ucs data//~va20I~
                if (vhexmode || swutf8data|| keyindatalen_dd!=Ppcw->UCWkeytype)	//not ascii//~va20R~
                {                                                  //~va20I~
                	memcpy(Ppcw->UCWkeydata,keyindata_dddata,(UINT)keyindatalen_dd);//~va20R~
//              	Ppcw->UCWkeytype=keyindatalen_dd;              //~vaz8R~
                	Ppcw->UCWkeytype=(UCHAR)keyindatalen_dd;       //~vaz8I~
                }                                                  //~va20I~
                vhexmode=0; //normal char input, no binary consideration//~va20I~
                hexkbdsw=0; //hexkbd input ucs translated to dd str//~va20I~
            }//rep/ins                                             //~va20I~
            else                                                   //~va20I~
            {                                                      //~va20I~
                if (vhexmode)                                      //~va20I~
                {                                                  //~va20I~
					xeutf_getvhexpos(XEUTFGVXOO_RECOFFS,Ppcw,Pplh,Pcurcol,&ucsdatapos,&keyindatalen_dd);//~va20I~
                    Pcurcol=ucsdatapos;                            //~va20M~
                    vhexmode=0;	//pos changed to top byte of the char//~va20R~
                }                                                  //~va20I~
            }                                                      //~va20I~
        }                                                          //~va20I~
#endif                                                             //~va20I~
    	protlen=pfh->UFHprotlen;                                   //~v0ihI~
		mergin=pfh->UFHmergin;                                     //~v0byI~
		spfpos=pfh->UFHspfpos;                                     //~v417I~
        spfsw2=UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR);//~v0dhR~
        if (spfsw2)                                                //~v0dhI~
            if (Pendcol>mergin)	//if <=mergin,it is valid spf line //~v0dhI~
              	spfsw2=fileisvalidspfline(pfh,Pplh,0);//no update line spf flag//~v0duR~
        merginsw=UCBITCHK(pfh->UFHflag2,UFHF2MERGIN);              //~v0dbI~
        oomprotsw=!UCBITCHK(pfh->UFHflag3,UFHF3OOMNOPROT);         //~v0eqR~
    }                                                              //~v0byI~
	keyindata=Ppcw->UCWkeydata;                                 //~4C27I~
	keyindatalen=Ppcw->UCWkeytype;                              //~4C27I~
                                                                   //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
  if (!swutf8data)                                                 //~va20R~
#endif                                                             //~va20I~
  {                                                                //~va20I~
#ifdef UTF8SUPPH                                                   //~va1cR~
    if (Ppcw->UCWnls & KBDNLS_SS3)                                 //~va1cR~
        keyindatalen=UDBCSCHK_SS3SZ;                               //~va1cR~
    else                                                           //~va1cR~
    if (Ppcw->UCWnls & KBDNLS_GB4)                                 //~va1cR~
        keyindatalen=UDBCSCHK_GB4SZ;                               //~va1cR~
#endif                                                             //~va1cR~
#ifdef LNX                                                         //~v777I
    if (*keyindata==SS2 && keyindatalen==2) //EUC hankana          //~v777R
//  	hankanasw=(Gunxflag & GUNX_KON);    //set dbcserr          //~v77AR
//  	hankanasw=((Gunxflag & (GUNX_EUC|GUNX_KON))==(GUNX_EUC|GUNX_KON)); //under kon//~v79zR
    	hankanasw=XE_ISDBCSKONJ(); //Japanese under kon            //~v79zI
#endif                                                             //~v777I
  }//not ddfmt                                                     //~va20I~
	pc=Pbuff+Pcurcol;
	pcd=Pdbcs+Pcurcol;
    if (Pmode==CHAROPINS        //insert mode                      //~v09jI~
    &&  Pbuffend==Pstartcol+1   //1byte input fld                  //~v09jI~
    &&  keyindatalen==1)        //1byte input                      //~v09jI~
        Pmode=CHAROPREP;        //accept as rep                    //~v09jI~
	switch(Pmode)
	{
//**********************                                           //~va50I~
//* REP ****************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPREP:	//rep
		if ((Pcurcol+keyindatalen)>=Pbuffend)                   //~v020R~
		{                                                       //~5127I~
			if ((Pcurcol+keyindatalen)>Pbuffend)                //~v020I~
				return charfieldfullerr();                      //~v020R~
            UCBITON(Ppcw->UCWflag,UCWFFIELDFULL);//for func_char//~v020I~
		}                                                       //~5127I~

		if (Pplh)                                               //~4C27I~
        {                                                          //~v0avI~
            if (hexmodesw)                                         //~v444R~
            {                                                      //~v441I~
            	datapos=Pcurcol;                                   //~v441R~
				hexinpsw=filecharhexinput(Ppcw,pfh,Pplh,Pcurcol,&datapos,Pmode);//~v441R~
                if (hexinpsw>=4) 	//err                          //~v441R~
                	return 4;                                      //~v441I~
                if (hexinpsw)		//hex part input               //~v441R~
                {                                                  //~v441I~
    		        if (vhexmode)	//hex display line of vhexmode //~v70nI~
	                	return 4;                                  //~v70nI~
                	Pcurcol=datapos;                               //~v441R~
					pc=Pbuff+Pcurcol;	//pos on data              //~v441I~
					pcd=Pdbcs+Pcurcol;                             //~v441I~
                }                                                  //~v441I~
            }                                                      //~v441I~
//          else                                                   //~v70nR~
            if (vhexmode)	//hex display line of vhexmode         //~v60vI~
            {                                                      //~v60vI~
//            	if (Pcurcol>=Pendcol)                              //~v60vR~//~v76dR
              	if (Pcurcol>Pendcol)                              //~v60vR~//~v76dI
	            	vhexolddata=-1;	//id of outof range            //~v60vI~
                else                                               //~v60vI~//~v76dI
              	if (Pcurcol==Pendcol)                              //~v60vR~//~v76dI
	            	vhexolddata=0;	//append 1 byte                //~v76dI
                else                                               //~v60vI~
                  if (*(Pdbcs+Pcurcol)==TABCHAR)                   //~v69HI~
                	vhexolddata=TABCHAR;                           //~v69HI~
                  else                                             //~v69HI~
                	vhexolddata=*pc;                               //~v60vR~
//				if (filecharhexinput_v(keyindata,keyindatalen,vhexolddata,Pmode,vhexmode,&vhexnewchar))//~va3SR~
				if (filecharhexinput_v(Ppcw,keyindata,keyindatalen,vhexolddata,Pmode,vhexmode,&vhexnewchar))//~va3SI~
                	return 4;                                      //~v60vI~
                keyindatalen=1;                                    //~v60vI~
                keyindata=&vhexnewchar;                            //~v60vR~
            }                                                      //~v60vI~
          if (!hexinpsw)	//not input on hex part                //~v441R~
          {                                                        //~v441I~
			if (Pcurcol>=mergin)                                   //~v0bpI~
            {                                                      //~v0dhI~
//            if (oomprotsw || spfsw2)                             //~v417R~
              if (oomprotsw)                                       //~v417I~
//  			return charmerginerr(mergin);                                    //~51//~v417R~
    			return errprotected();                             //~v417I~
              if (UCBITCHK(pfh->UFHflag7,UFHF7FIXLRECL))           //~v71HI~
			  	if (Pcurcol+keyindatalen>pfh->UFHlrecl)            //~v71HI~
					return charfixlenovererr(pfh->UFHlrecl);                            //~51//~v71HI~
			  if ((Pcurcol+keyindatalen)>MAXLINEDATA)              //~v0e0I~
				return charmaxovererr(MAXLINEDATA);                            //~51//~v0e0I~
			}                                                      //~v0dhI~
            else	//curcol<mergin                                //~v0dhI~
            {                                                      //~v73hI
			if ((Pcurcol+keyindatalen)>mergin)                     //~v0avI~
				return charmaxovererr(mergin);                            //~51//~v0avI~
//  		if (*keyindata==TABCHAR) //tab rep case may not occur? //~v0avR~//~v73jR
            opt=0;                                                 //~v73gR
            opt=MERGIN_SHORTRECOK;                                 //~v73gI
            if (vhexmode)                                          //~v73gI
                opt|=MERGIN_HEX;                                   //~v73gI
#ifdef UTF8UCS2                                                    //~va22I~
        	if (vhexmode||(*keyindata==TABCHAR && !swutf8data)) //tab not part of ucs//~va22I~
#else                                                              //~va22I~
        	if (vhexmode||*keyindata==TABCHAR) //tab rep case may not occur?//~v73gR
#endif                                                             //~va22I~
#ifdef UTF8UCS2                                                    //~va20I~
			    if (filemerginchk(Pplh,Pcurcol,keyindata,keyindata_dddbcs,1,1,//addlen=1,dellen=1//~va20I~
#else                                                              //~va20I~
			    if (filemerginchk(Pplh,Pcurcol,keyindata,1,1,//addlen=1,dellen=1//~v0c2R~
#endif                                                             //~va20I~
//  				0,0,0,0))//opt=addlen=newlen=oomlen=0          //~v0c2R~//~v73jR
//      			0,0,0,&oomlen))//opt=addlen=newlen=oomlen=0          //~v0c2R~//~v73gR
        			opt,0,0,&oomlen))//opt=addlen=newlen=oomlen=0          //~v0c2R~//~v73gR
		    		return 4;                                      //~v0avI~
            }                                                      //~v73hI
          }//not hex part input                                    //~v441I~
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)	//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
        }                                                          //~v0avI~
                                                                //~5506I~
		if ((len=Pcurcol-Pendcol)>=0)	//out of reclen         //~5507R~
        {                                                          //~v7a0I
 			addlen=keyindatalen;	//after cur col             //~5506I~
            memset(Pbuff+Pendcol,' ',(UINT)len); //set before chk tab is replaced//~v7a0I
            memset(Pdbcs+Pendcol,0,(UINT)len);  //result of shorten record//~5507I~//~v7a0I
			newlen2=Pcurcol+addlen;                                //~v7a0I
        }                                                          //~v7a0I
        else                                                    //~5506I~
        {                                                          //~v7a0I
			addlen=max(0,Pcurcol+keyindatalen-Pendcol);         //~5506I~
			newlen2=Pendcol+addlen;                                //~v7a0R
        }                                                          //~v7a0I
      if (!hexinpsw)	//not input on hex part                    //~v448R~
      {                                                            //~v73nI
       if (!vhexmode)	//hex display line of vhexmode             //~v63uR~
       {                                                           //~v63uR~
#ifdef UTF8UCS2                                                    //~va22I~
		if (!(*keyindata==TABCHAR && !swutf8data)                  //~va22I~
#else                                                              //~va22I~
		if (*keyindata!=TABCHAR		//not tab char input        //~5507I~
#endif                                                             //~va22I~
		||	addlen                  //out of rec                //~5507I~
		|| *pcd!=TABCHAR)           //not repl tab              //~5507I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	        setobtabdbcs(0,0,Pbuff,Pdbcs,Pendcol,Pcurcol,keyindatalen);//~va50I~
#else                                                              //~va50I~
	        setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pcurcol,keyindatalen);//~5507R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
 						//replace opverridden tab/dbcs          //~5506I~
       }                                                           //~v63uR~
     }                                                             //~v73nI
     delpadctr=0;                                                  //~v73hI
		if (keyindatalen==2)                                    //~4C27R~
		{
//			if (Pcurcol==Pendcol-1)                             //~5506R~
//				*(pc+1)=0;	//avoid next byte of rec is checked //~5506R~
//			tabrepsw=(*pc==Gfiletab1 || *(pc+1)==Gfiletab1);    //~5102R~
			UMOVSW(pc,keyindata);                               //~4C27R~
#ifdef LNX                                                         //~v777I
		  if (hankanasw)                                           //~v777I
          {                                                        //~v777I
    #ifdef CURSESW                                                 //~v7a2R
			UMOVSW(pcd,Sdbcsid);                                   //~v7a2I
    #else                                                          //~v7a2I
           	*(pcd+1)=*pcd=UDBCSCHK_HKDBCSERR;                      //~v777I
	        Ppcw->UCWreason=UCWREASON_CSRBYKEYTYPE;	//step by 2 column//~v777I
    #endif                                                         //~v7a2I
          }                                                        //~v777I
          else                                                     //~v777I
#endif                                                             //~v777I
#ifdef UTF8UCS2                                                    //~va20I~
  		  if (swutf8data)		//ddfmt utf8 line                  //~va20I~
			memcpy(pcd,keyindata_dddbcs,2);	//ucs id               //~va20I~
          else                                                     //~va20I~
#endif                                                             //~va20I~
			UMOVSW(pcd,Sdbcsid);
          if (Pplh && Pcurcol<=Pendcol && Pcurcol && *(pcd-1)==UDBCSCHK_HKDBCSERR)//~v7a6R
//*no HKDBCSERR on dd fmt                                          //~va20I~
    	    filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,newlen2,FSDT_TABSAVE);//~v448R~//~v7a6I
		}
		else
#ifdef UTF8SUPPH                                                   //~va1cR~
		if (keyindatalen>UDBCSCHK_DBCSSZ)                          //~va1cR~
		{                                                          //~va1cR~
			memcpy(pc,keyindata,(UINT)keyindatalen);               //~va1cR~
		  	if (keyindatalen==UDBCSCHK_SS3SZ)                      //~va1cR~
				memcpy(pcd,Sdbcsidss3,UDBCSCHK_SS3SZ);                                   //~v7a2I//~va1cR~
            else                                                   //~va1cR~
				memcpy(pcd,Sdbcsidgb4,UDBCSCHK_GB4SZ);                                   //~v7a2I//~va1cR~
          	if (Pplh                                               //~va1cR~
            &&  Pcurcol<=Pendcol                                   //~va1cR~
            &&  Pcurcol && *(pcd-1)==UDBCSCHK_HKDBCSERR)//~v7a6R   //~va1cR~
//*no HKDBCSERR on dd fmt                                          //~va20I~
    	    	filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,newlen2,FSDT_TABSAVE);//~v448R~//~v7a6I//~va1cR~
		}                                                          //~va1cR~
		else                                                       //~va1cR~
#endif                                                             //~va1cR~
		{
//			tabrepsw=(*pc==Gfiletab1);                          //~5102R~
#ifdef UTF8UCS2                                                    //~va22I~
			if (Pplh && (*keyindata==TABCHAR && !swutf8data)) //tab not part of ucs//~va22I~
#else                                                              //~va22I~
			if (Pplh && *keyindata==TABCHAR)		//tab char input//~5507R~
#endif                                                             //~va22I~
            {                                                   //~5507I~
//            if (*pcd==DBCS2NDCHAR)	//when by hexmode replace  //~v73vR
//  			*pc=*keyindata;                                    //~v73vR
//            else                                                 //~v73vR
//            {                                                    //~v73vR
				*pc=' ';                                        //~5507I~
				*pcd=TABCHAR;		//sbcs                      //~5507I~
//            }                                                    //~v73vR
//    		  if (hexinpsw||vhexmode)	//not input on hex part    //~v63uR~//~v73wI//~v7a0R
      		  if (hexinpsw||vhexmode||hexkbdsw)	//may not normal char//~v7a0I
//  	    	filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,FSDT_TABSAVE);//~v448R~//~v73wI//~v7a0R
//*no vhexmode for utf8file,hexinpsw=hHexmode is binfile,hexkbdsw(hex input mode) is rejexted on utf8 file//~va20I~
    	    	filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,newlen2,FSDT_TABSAVE);//~v448R~//~v7a0I
            }                                                   //~5507I~
            else                                                //~5507I~
            {                                                   //~5507I~
				*pc=*keyindata;                                 //~5507R~
//    		  if (hexinpsw)	//not input on hex part                //~v63uR~
//    		  if (hexinpsw||vhexmode)	//not input on hex part    //~v63uR~//~v778R
//    		  if (hexinpsw||vhexmode||hexkbdsw)	//not input on hex part    //~v63uR~//~v778I//~v7a6R
      		  if (hexinpsw||vhexmode||hexkbdsw		//hex input    //~v7a6I
              ||  (Pplh && Pcurcol<=Pendcol && Pcurcol && *(pcd-1)==UDBCSCHK_HKDBCSERR)//~v7a6R
			  )                                                    //~v7a6I
              {                                                    //~v454I~
//  			tabrepsw=(*pcd==TABCHAR);                          //~v73wI//~v7a0R
				tabrepsw=(Pcurcol<Pendcol) && (*pcd==TABCHAR);     //~v7a0I
#ifdef UTF8UCS2                                                    //~va20I~
  		  	   if (swutf8data)		//ddfmt utf8 line              //~va20I~
				*pcd=*keyindata_dddbcs;	//sbcs ucs id              //~va20I~
          	   else                                                //~va20I~
#endif                                                             //~va20I~
				*pcd=0;		//clear TAB attr before filesetdbcstbl with FSDT_TABSAVE//~v73wI
//  	    	filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,FSDT_TABSAVE);//~v448R~//~v7a0R
//*no HKDBCSERR on dd fmt                                          //~va20I~
//*no vhexmode for utf8file,hexinpsw=hHexmode is binfile,hexkbdsw(hex input mode) is rejexted on utf8 file//~va20I~
    	    	filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,newlen2,FSDT_TABSAVE);//~v448R~//~v7a0I
//            	if (*pcd==TABCHAR)                                 //~v454I~//~v73wR
              	if (tabrepsw)                                      //~v73wI
                {                                                  //~v73hI
                    for (ii=0;;ii++)                               //~v73hI
                        if (*(pcd+ii+1)!=TABPADCHAR)               //~v73hI
                            break;                                 //~v73hI
                    delpadctr=ii;                                  //~v73hI
                    if (delpadctr)                                 //~v73hI
                    {                                              //~v73hI
                        memcpy(pc+1,pc+1+delpadctr,(UINT)(Pendcol-Pcurcol-delpadctr-1));//~v73wR
                        memcpy(pcd+1,pcd+1+delpadctr,(UINT)(Pendcol-Pcurcol-delpadctr-1));//~v73wR
                    }                                              //~v73hI
                    addlen=-delpadctr;                             //~v73hI
//              	*pcd=0;		//tab is replaced                  //~v454I~//~v73wR
                }                                                  //~v73hI
              }                                                    //~v454I~
              else                                                 //~v448R~
              {//not hex,not setdbcs required                      //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
  		  	   if (swutf8data)		//ddfmt utf8 line              //~va20I~
				*pcd=*keyindata_dddbcs;	//sbcs ucs id              //~va20I~
          	   else                                                //~va20I~
#endif                                                             //~va20I~
				*pcd=0;		//sbcs                              //~5507R~
              }//not hex                                           //~va20I~
            }                                                   //~5507I~
		}
//		if (Pcurcol+keyindatalen<Pendcol	//repled next dbcs first byte//~5506R~
//		&&  *(pcd+keyindatalen)==DBCS2NDCHAR)//repled next dbcs first byte//~5506R~
//		{                                                       //~5506R~
//			*(pcd+keyindatalen)=0;	//repled next dbcs first byte//~5506R~
//			*(pc+keyindatalen)=' ';	//repled next dbcs sec byte //~5506R~
//		}	                                                    //~5506R~
//		if (Pcurcol<Pendcol)	//override                      //~5506R~
//		{                                                       //~5506R~
//			addlen=max(0,Pcurcol+keyindatalen-Pendcol);         //~5506R~
//			len=Pendcol+addlen;                                 //~5506R~
//			for(pc2=pc+keyindatalen,pcd2=pcd+keyindatalen;*pcd2==TABPADCHAR;)//~5506R~
//			{                                                   //~5506R~
//				*pc2++=' ';		//rep after tab dummy char      //~5506R~
//				*pcd2++=0;		//rep after tab dummy char      //~5506R~
//			}                                                   //~5506R~
//			if (tabrepsw)                                   //~5102R~
//				addlen+=chartabexp(Pplh,pc,Pcurcol,len);    //~5102R~
//		}//rep                                                  //~5506R~
//		else	//add(out of record)                            //~5506R~
//			addlen=keyindatalen;                                //~5506R~
		if (Pplh)                                               //~5507I~
        {                                                          //~v73jR
			if (delpadctr)	//tab is replaced by vhex mode         //~v73hI
            {                                                      //~v73hI
              Pplh->ULHlen+=addlen;                                //~v73hI
              if (oomlen)                                          //~v73hI
              {                                                    //~v73hI
//      		fileoomshiftback(pfh,Pplh,oomlen);                 //~v74ER
        		fileoomshiftback(pfh,Pplh,oomlen,0);               //~v74EI
			  }                                                    //~v73hI
              else                                                 //~v73hI
              {                                                    //~v73hI
                len=Pendcol-Pcurcol+addlen;                        //~v73hI
				chartabexp(Pplh,&Pbuff,&Pdbcs,&pc,&pcd,Pcurcol,len,&addlen);//~v73hI
                UALLOCCHK(Stabexpoksw,UALLOC_FAILED);//return if storage shortage//~v73hI
              }                                                    //~v73hI
              addlen=0;                                            //~v73hI
            }                                                      //~v73hI
            else                                                   //~v73hI
#ifdef UTF8UCS2                                                    //~va22I~
			if ((*keyindata==TABCHAR && !swutf8data)) //tab not part of ucs//~va22I~
#else                                                              //~va22I~
			if (*keyindata==TABCHAR)                            //~5507I~
#endif                                                             //~va22I~
			{                                                   //~5507I~
              if (oomlen)                                          //~v73hI
    			fileimtabexp(Pplh,Pcurcol,0,mergin);//len=mergin;expand in mergin//~v73hI
              else                                                 //~v73hI
              {                                                    //~v73hI
				if (!(len=addlen))                              //~5507I~
                	len=Pendcol-Pcurcol;                        //~5507R~
				chartabexp(Pplh,&Pbuff,&Pdbcs,&pc,&pcd,Pcurcol,len,&addlen);//~5507I~
                UALLOCCHK(Stabexpoksw,UALLOC_FAILED);//return if storage shortage//~v04dI~
              }                                                    //~v73hI
//*count csr right step for func_right                          //~5507I~
//              keyindatalen=TABSKIPCTR(Pcurcol)+1;                //~v106R~
//              keyindatalen=TABSKIPCTR2(binsw,Pcurcol)+1;         //~v106I~//~v8@2R
                keyindatalen=TABSKIPCTR2F(binsw,tabskip,Pcurcol)+1;         //~v106I~//~v8@2R
                Ppcw->UCWkeytype=(UCHAR)keyindatalen;           //~5507I~
			}                                                   //~5507I~
        }                                                          //~v73jR
        else //!Pplh                                               //~v79RI
        {                                                          //~v79RI
			if (hexkbdgcsw)     //hex input by ACS key             //~v79RI
            {                                                      //~v79RI
//          	len=max(Pendcol,Pcurcol+keyindatalen);             //~v79RI//~v7a0R
    	    	setdbcstbl(Pbuff,Pdbcs,newlen2);              //~v79RR//~v7a0R
            }                                                      //~v79RI
        }                                                          //~v79RI
//        if ((len=Pcurcol-Pendcol)>0)    //out of reclen         //~5507I~//~v7a0R
//        {                                                       //~5507I~//~v7a0R
//            memset(Pbuff+Pendcol,' ',(UINT)len);                //~5507I~//~v7a0R
//            memset(Pdbcs+Pendcol,0,(UINT)len);  //result of shorten record//~5507I~//~v7a0R
//        }                                                       //~5507I~//~v7a0R
		break;
//**********************                                           //~va50I~
//* INS ****************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPINS:	//isrt
		if (Pplh)                                                  //~v441I~
        {                                                          //~v441I~
            if (hexmodesw)                                         //~v444I~
            {                                                      //~v441I~
            	datapos=Pcurcol;                                   //~v441I~
				hexinpsw=filecharhexinput(Ppcw,pfh,Pplh,Pcurcol,&datapos,Pmode);//~v441I~
                if (hexinpsw>=4)                                   //~v441I~
                	return 4;                                      //~v441I~
                if (hexinpsw)		//hex part input               //~v441I~
                {                                                  //~v441I~
                    if (hexinpsw==FCHI_ODDINS)  //ins on 2nd byte  //~v441I~
//  					return charfldedit(CHAROPREP,Pbuff,Pdbcs,  //~v70nR~
    					return charfldedit(CHAROPREP|(vhexmode<<8),Pbuff,Pdbcs,//~v70nI~
											Pcurcol,Pstartcol,Pendcol,Pbuffend,//~v441I~
											Ppcw,Pplh);            //~v441I~
    		        if (vhexmode)	//hex display line of vhexmode //~v70nI~
	                	return 4;                                  //~v70nI~
                	Pcurcol=datapos;                               //~v441I~
					pc=Pbuff+Pcurcol;	//pos on data              //~v441I~
					pcd=Pdbcs+Pcurcol;                             //~v441I~
                }                                                  //~v441I~
            }//hex mode                                            //~v441R~
//          else                                                   //~v70nR~
            if (vhexmode)	//hex display line of vhexmode         //~v60vI~
            {                                                      //~v60vI~
//          	if (Pcurcol>=Pendcol)                              //~v60vR~//~v76dR
            	if (Pcurcol>Pendcol)                              //~v60vR~//~v76dI
	            	vhexolddata=-1;	//id of outof range            //~v60vI~
                else                                               //~v76dI
            	if (Pcurcol==Pendcol)                              //~v60vR~//~v76dI
	            	vhexolddata=0;	//id of outof range            //~v60vI~//~v76dI
                else                                               //~v60vI~
                	vhexolddata=*pc;                               //~v60vR~
//  			if (filecharhexinput_v(keyindata,keyindatalen,vhexolddata,Pmode,vhexmode,&vhexnewchar))//~va3SR~
    			if (filecharhexinput_v(Ppcw,keyindata,keyindatalen,vhexolddata,Pmode,vhexmode,&vhexnewchar))//~va3SI~
                	return 4;                                      //~v60vI~
                keyindatalen=1;                                    //~v60vI~
                keyindata=&vhexnewchar;                            //~v60vR~
            }                                                      //~v60vI~
        }//plh                                                     //~v441I~
		if (Pcurcol<Pendcol)		//isrt inter-char
			len=Pendcol-Pcurcol;
		else							//isrt on null
			len=0;

		if ((Pcurcol+keyindatalen+len)>=Pbuffend)               //~v020R~
		{                                                       //~5127I~
			if ((Pcurcol+keyindatalen+len)>Pbuffend)            //~v067I~
				return charfieldfullerr();                      //~v067R~
            if (!len)                                           //~v067I~
            UCBITON(Ppcw->UCWflag,UCWFFIELDFULL);//for func_char//~v020I~
		}                                                       //~5127I~

		if (Pplh)                                               //~4C27I~
        {                                                          //~v0avI~
          if (!hexinpsw)	//not input on hex part                //~v441R~
          {                                                        //~v441I~
			if (Pcurcol>=mergin)                                   //~v0bpI~
            {                                                      //~v0dhI~
//            if (oomprotsw || spfsw2)                             //~v417R~
              if (oomprotsw)                                       //~v417I~
//  			return charmerginerr(mergin);                                    //~51//~v417R~
    			return errprotected();                             //~v417I~
#ifdef UTF8UCS2                                                    //~va20I~
		      newlen=filegettabexplen(Pplh,Pcurcol,keyindata,keyindata_dddbcs,keyindatalen,0,Pendcol)+Pendcol;//~va20R~
#else                                                              //~va20I~
		      newlen=filegettabexplen(Pplh,Pcurcol,keyindata,keyindatalen,0,Pendcol)//dellen=0//~v0e0R~
                     +Pendcol;                                     //~v0e0I~
#endif                                                             //~va20I~
              	if (UCBITCHK(pfh->UFHflag7,UFHF7FIXLRECL))         //~v71HR~
			  		if (newlen>pfh->UFHlrecl)                      //~v71HI~
						return charfixlenovererr(pfh->UFHlrecl);                            //~51//~v71HR~
			  if (newlen>MAXLINEDATA)                              //~v0e0I~
				return charmaxovererr(MAXLINEDATA);                            //~51//~v0e0I~
			}                                                      //~v0dhI~
            else	//curcol<mergin                                //~v0dhI~
            {                                                      //~v73hI
//  	    if (filemerginchk(Pplh,Pcurcol,keyindata,keyindatalen,0,//dellen=0//~v71UR~
//  							0,0,0,&oomlen)>=4)                 //~v71UI~
    			opt=MERGIN_SHORTRECOK;                             //~v73gR
    			if (vhexmode)                                      //~v73gR
           		 	opt|=MERGIN_HEX;                               //~v73gR
#ifdef UTF8UCS2                                                    //~va20I~
    	    if (filemerginchk(Pplh,Pcurcol,keyindata,keyindata_dddbcs,keyindatalen,0,//dellen=0//~va20I~
#else                                                              //~va20I~
    	    if (filemerginchk(Pplh,Pcurcol,keyindata,keyindatalen,0,//dellen=0//~v71UR~
#endif                                                             //~va20I~
//  							MERGIN_SHORTRECOK,0,0,&oomlen)) //accept merginover flow is space only for short record//~v71UR~//~v73hR
    							opt,0,0,&oomlen)) //accept merginover flow is space only for short record//~v71UR~//~v73gR
	    		return 4;                                          //~v0avI~
            }                                                      //~v73hI
            if (oomlen==-1)	//shortrec overflow but tab/space only //~v71UI~
            {	                                                   //~v71UI~
            	oomlen=0;                                          //~v71UI~
                rcmc=1;                                            //~v71UI~
            }                                                      //~v71UI~
          }//not hex part input                                    //~v441I~
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
            if (oomlen)	//ins in mergin and has oom                //~v0evR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		        setobtabdbcs(0,0,Pbuff,Pdbcs,Pendcol,mergin,0);//left/rigth of mergin//~va50I~
#else                                                              //~va50I~
		        setobtabdbcs(Pbuff,Pdbcs,Pendcol,mergin,0);//left/rigth of mergin//~v0evR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        }                                                          //~v0avI~
		if (len)
		{
          if (!hexinpsw)	//not input on hex part                //~v448I~
           if (!vhexmode)	//not input on hex part  of vhex mode              //~v448I~//~v735R
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	        setobtabdbcs(0,0,Pbuff,Pdbcs,Pendcol,Pcurcol,0);       //~va50I~
#else                                                              //~va50I~
	        setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pcurcol,0);           //~v0c4I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
 						//replace splitted tab/dbcs                //~v0c4I~
			memmove(pc+keyindatalen,pc,(UINT)len);//shift to right//~4C27R~
			memmove(pcd+keyindatalen,pcd,(UINT)len);            //~4C27R~
		}
		addlen=keyindatalen;                                    //~4C27R~

		if (keyindatalen==2)                                    //~4C27R~
		{
			UMOVSW(pc,keyindata);                               //~4C27R~
#ifdef LNX                                                         //~v777I
		  if (hankanasw)                                           //~v777I
          {                                                        //~v777I
    #ifdef CURSESW                                                 //~v7a2R
			UMOVSW(pcd,Sdbcsid);                                   //~v7a2I
    #else                                                          //~v7a2I
           	*(pcd+1)=*pcd=UDBCSCHK_HKDBCSERR;                      //~v777I
	        Ppcw->UCWreason=UCWREASON_CSRBYKEYTYPE;	//step by 2 column//~v777I
    #endif                                                         //~v7a2I
          }                                                        //~v777I
          else                                                     //~v777I
#endif                                                             //~v777I
#ifdef UTF8UCS2                                                    //~va20I~
  		  if (swutf8data)		//ddfmt utf8 line                  //~va20I~
			memcpy(pcd,keyindata_dddbcs,2);	//ucs id               //~va20I~
          else                                                     //~va20I~
#endif                                                             //~va20I~
			UMOVSW(pcd,Sdbcsid);
		}
		else
#ifdef UTF8SUPPH                                                   //~va1cR~
		if (keyindatalen>UDBCSCHK_DBCSSZ)                          //~va1cR~
		{                                                          //~va1cR~
			memcpy(pc,keyindata,(UINT)keyindatalen);               //~va1cR~
		  	if (keyindatalen==UDBCSCHK_SS3SZ)                      //~va1cR~
				memcpy(pcd,Sdbcsidss3,UDBCSCHK_SS3SZ);                                   //~v7a2I//~va1cR~
            else                                                   //~va1cR~
				memcpy(pcd,Sdbcsidgb4,UDBCSCHK_GB4SZ);                                   //~v7a2I//~va1cR~
		}                                                          //~va1cR~
		else                                                       //~va1cR~
#endif                                                             //~va1cR~
		{
			if (*keyindata==TABCHAR)                            //~5102I~
			{                                                   //~5102I~
				*pc=' ';                                        //~5102I~
				*pcd=TABCHAR;		//sbcs                      //~5102I~
            }                                                   //~5102I~
			else                                                //~5102I~
			{                                                   //~5102I~
				*pc=*keyindata;                                 //~5102R~
#ifdef UTF8UCS2                                                    //~va20I~
  		  	   if (swutf8data)		//ddfmt utf8 line              //~va20I~
               {                                                   //~va20I~
				*pcd=*keyindata_dddbcs;	//sbcs ucs id              //~va20I~
                if (u8vhexrepsw)                                   //~va20I~
                {                                                  //~va20I~
					*(pc+1)=*(keyindata_dddata+1);	//sbcs expand to dbcs//~va20I~
					*(pcd+1)=*(keyindata_dddbcs+1);	               //~va20I~
                }                                                  //~va20I~
               }                                                   //~va20I~
          	   else                                                //~va20I~
#endif                                                             //~va20I~
				*pcd=0;		//sbcs                              //~5102R~
			}                                                   //~5102I~
		}
        if ((addlen2=Pcurcol-Pendcol)>0)    //out of reclen         //~5507I~//~v7a0I
        {                                                       //~5507M~//~v7a0I
            memset(Pbuff+Pendcol,' ',(UINT)addlen2);                //~5507I~//~v7a0I
            memset(Pdbcs+Pendcol,0,(UINT)addlen2);  //result of shorten record//~5507I~//~v7a0I
        }                                                       //~5507M~//~v7a0I
        else                                                       //~v7a0I
        	addlen2=0;                                             //~v7a0I
		if (Pplh)                                               //~5102I~
        {                                                          //~v0erI~
			if (*keyindata==TABCHAR                             //~5102R~
			||UCBITCHK(Pplh->ULHflag2,ULHF2TABFOUND))//once tab chk//~5102R~
			{
              if (oomlen)                                          //~v0evR~
              {                                                    //~v73pI
//  			fileimtabexp(Pplh,Pcurcol,0,mergin);//len=mergin;expand in mergin//~v0evI~//~v73pR
                imlen=mergin+keyindatalen-Pcurcol;                 //~v73pI
    			fileimtabexp(Pplh,Pcurcol,&imlen,mergin);//len=mergin;expand in mergin//~v73pI
              }                                                    //~v73pI
              else                                                 //~v0evI~
              if (rcmc)                                            //~v71UI~
				fileimtabexp(Pplh,Pcurcol,0,mergin);//len=mergin;expand in mergin//~v71UI~
              else                                                 //~v71UI~
              {                                                    //~v0evI~
				len+=addlen;
				len+=chartabexp(Pplh,&Pbuff,&Pdbcs,&pc,&pcd,Pcurcol,len,&addlen);//~5507R~
                UALLOCCHK(Stabexpoksw,UALLOC_FAILED);//return if storage shortage//~v04dI~
              }                                                    //~v0evI~
//*count csr right step for func_right                          //~5423I~
				if (*keyindata==TABCHAR)                        //~5521I~
                {                                               //~5521I~
//              	keyindatalen=TABSKIPCTR(Pcurcol)+1;            //~v106R~
//              	keyindatalen=TABSKIPCTR2(binsw,Pcurcol)+1;     //~v106I~//~v8@2R
                	keyindatalen=TABSKIPCTR2F(binsw,tabskip,Pcurcol)+1;     //~v106I~//~v8@2R
                	Ppcw->UCWkeytype=(UCHAR)keyindatalen;       //~5521R~
				}                                               //~5521I~
			}
    	    if (oomlen)                                            //~v0evI~
            {                                                      //~v0evI~
            	Pplh->ULHlen+=addlen;                              //~v0evI~
                addlen=0;                                          //~v0evI~
//      		fileoomshiftback(pfh,Pplh,oomlen);                 //~v0evI~//~v74ER
        		fileoomshiftback(pfh,Pplh,oomlen,0);                 //~v0evI~//~v74EI
			}                                                      //~v0evI~
    	    if (rcmc==1)	//short record margin overflow only space//~v71UI~
            {                                                      //~v71UI~
            	Pplh->ULHlen=mergin;                               //~v71UI~
                addlen=0;                                          //~v71UI~
			}                                                      //~v71UI~
//          if (hexinpsw) //not input on hex part                  //~v448I~//~v73wR
//          if (hexinpsw||vhexmode) //not input on hex part                  //~v448I~//~v778R
//          if (hexinpsw||vhexmode||hexkbdsw) //not input on hex part                  //~v448I~//~v778I//~v7a6R
            if (hexinpsw||vhexmode||hexkbdsw  //not input on hex part                  //~v448I~//~v7a6I
            ||  (Pcurcol<=Pendcol && Pcurcol && *(pcd-1)==UDBCSCHK_HKDBCSERR)//~v7a6I
            )                                                      //~v7a6I
            {                                                      //~v778I
//  	    	filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,FSDT_TABSAVE);//~v448I~//~v73wR//~v79ZR
//  	    	filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen+addlen,FSDT_TABSAVE);//~v448I~//~v79ZI//~v7a0R
				if (!addlen)	//not ulhlen reset                 //~v7a0I
                	addlen2=0;                                     //~v7a0I
                else                                               //~v7a0I
                	addlen2+=addlen;                               //~v7a0I
//*no HKDBCSERR on dd fmt                                          //~va20I~
//*no vhexmode for utf8file,hexinpsw=hHexmode is binfile,hexkbdsw(hex input mode) is rejexted on utf8 file//~va20I~
    	    	filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen+addlen2,FSDT_TABSAVE);//~v448I~//~v7a0I
            }                                                      //~v778I
		}                                                          //~v0erI~
        else //!Pplh                                               //~v79RI
        {                                                          //~v79RI
			if (hexkbdgcsw)     //hex input by ACS key             //~v79RI
            {                                                      //~v79RI
            	len=Pendcol+keyindatalen;                          //~v79RI
    	    	setdbcstbl(Pbuff,Pdbcs,len);                       //~v79RI
            }                                                      //~v79RI
        }                                                          //~v79RI
//        if ((len=Pcurcol-Pendcol)>0)    //out of reclen         //~5507I~//~v7a0R
//        {                                                       //~5507M~//~v7a0R
//            memset(Pbuff+Pendcol,' ',(UINT)len);                //~5507I~//~v7a0R
//            memset(Pdbcs+Pendcol,0,(UINT)len);  //result of shorten record//~5507I~//~v7a0R
//        }                                                       //~5507M~//~v7a0R
		break;
//**********************                                           //~va50I~
//* DEL ****************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPDEL:	//del
	case CHAROPIMJOIN:	//inmergin join                            //~v42gI~
	case CHAROPJOINIGM: //join ignore margin                       //~v42gI~//~v74iI
		if (Pplh)                                               //~4C27I~
		{                                                       //~5104I~
          	if (Pmode==CHAROPDEL)       //del key                  //~v444I~
            {                                                      //~v70nI~
                if (hexmodesw)                                     //~v444I~
                {                                                  //~v444I~
                    datapos=Pcurcol;                               //~v444I~
                    hexinpsw=filecharhexinput(Ppcw,pfh,Pplh,Pcurcol,&datapos,Pmode);//~v444I~
                    if (hexinpsw>=4)    //protected                //~v444I~
                        return 4;                                  //~v444I~
                    if (hexinpsw)       //hex part input           //~v444I~
                    {                                              //~v444I~
	    		        if (vhexmode)	//hex display line of vhexmode//~v70nI~
		                	return 4;                              //~v70nI~
        				if (datapos==Pendcol)       //del CR       //~v58RR~
                        	return 4;                              //~v58RR~
                        Pcurcol=datapos;                           //~v444I~
                        pc=Pbuff+Pcurcol;   //pos on data          //~v444I~
                        pcd=Pdbcs+Pcurcol;                         //~v444I~
                    }                                              //~v444I~
                }//hex mode                                        //~v444I~
            }                                                      //~v70nI~
          if (!hexinpsw)                                           //~v444I~
          {                                                        //~v444I~
			if (Pcurcol>Pendcol)                                //~5104I~
				return 4;                                       //~5104I~
			if (Pcurcol>=mergin)                                   //~v0c3I~
            {                                                      //~v0dhI~
//            if (oomprotsw || spfsw2)                             //~v417R~
              if (oomprotsw)                                       //~v417I~
//  			return charmerginerr(mergin);                                    //~51//~v417R~
    			return errprotected();                             //~v417I~
			}                                                      //~v0dhI~
            else                                                   //~v0dhI~
            {                                                      //~v73gI
              if (Pmode!=CHAROPIMJOIN)       //spf join ignored num fld//~v42gI~
    		    oomlen=filegetoomlen(pfh,Pplh);  //out of mergin len//~v0esR~
            }                                                      //~v73gI
          }//not hex part del                                      //~v444I~
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)	//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
            if (Pmode==CHAROPIMJOIN)       //spf join ignored num fld//~v42gI~
                Pplh->ULHlen=Pendcol;                              //~v42gI~
           if (!vhexmode)                                          //~v73gI
	        if (oomlen)	//ins in mergin and has oom                //~v0evI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		        setobtabdbcs(0,0,Pbuff,Pdbcs,Pendcol,mergin,0);//left/rigth of mergin//~va50I~
#else                                                              //~va50I~
		        setobtabdbcs(Pbuff,Pdbcs,Pendcol,mergin,0);//left/rigth of mergin//~v0evR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		}                                                       //~5104I~
		else                                                    //~5104I~
			if (Pcurcol>=Pendcol)                               //~5104I~
				return 4;                                       //~5104I~
        if (Pplh && Pcurcol==Pendcol)       //del CR               //~v0bpR~
		{                                                       //~5104I~
          if (Slcmdplh2)                                           //~v0i7I~
			plhnext=Slcmdplh2;                                     //~v0i7I~
          else                                                     //~v0i7I~
			plhnext=UGETQNEXT(Pplh);                            //~5104I~
//  		len=addlen=plhnext->ULHlen;                            //~v0c8R~
    		addlen=                                                //~v0c8I~
//          len=filecidlrecl(plhnext,pfh);	//len without cid      //~v0cdR~
            len=Snetlen;                    //len without cid      //~v0cdI~
            if (UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file     //~v42gI~
                coboffs=SPFCOBNUMFLDLEN;                           //~v42gI~
            else                                                   //~v42gI~
                coboffs=0;                                         //~v42gI~
			memcpy(pc,plhnext->ULHdata+coboffs,(UINT)len);         //~v42gR~
			memcpy(pcd,plhnext->ULHdbcs+coboffs,(UINT)len);        //~v42gR~
          	if (Pmode==CHAROPJOINIGM)      //shift back if avail   //~v74iI
//      		oomlen=filegetoomlen(pfh,plhnext);  //out of mergin len//~v0esR~//~v74uR
        		oomlen=Snetoomlen;                                 //~v74uI
			if (UCBITCHK(plhnext->ULHflag2,ULHF2TABFOUND))      //~5104I~
            {                                                      //~v58RI~
        	  if (Pmode==CHAROPIMJOIN)       //spf join ignored num fld//~v42gI~
            	chartabclear(pcd,len);//tab clear                  //~v42gI~
              else                                                 //~v42gI~
				UCBITON(Pplh->ULHflag2,ULHF2TABFOUND);          //~5104I~
            }                                                      //~v58RI~
#ifdef UTF8SUPPH                                                   //~va1cR~
          	if (UDBCSCHK_ISGB4ENV()  //also fo 2 byte dbcs if gb4 env//~va1cR~
          	&&  pcd>Pplh->ULHdbcs                                  //~va1cR~
            )                                                      //~va1cR~
            {                                                      //~v77gI//~va1cR~
                joinpos=Pcurcol;                                   //~v77gI//~va1cR~
//*ddfmt chk will be done at charjoinsetdbcstbl                    //~va20I~
				addlen+=charjoinsetdbcstbl(0,Pplh,&joinpos,&len);  //~v77gI//~va1cR~
                if (!vhexmode)                                     //~va1cR~
					if (UDBCSCHK_DBCSNOT1ST(*pcd))//setdbcstbl changed this column to dbcs parts not 1st(conbined to prev column)                        //~v77gR//~va1cR~
						Ppcw->UCWreason=UCWREASON_DELEOLGB4;	//csr move to right//~va1cR~
            }                                                      //~v77gI//~va1cR~
            else                                                   //~va1cR~
#endif                                                             //~va1cR~
          	if (pcd>Pplh->ULHdbcs && *(pcd-1)==UDBCSCHK_HKDBCSERR) //~v77gI
            {                                                      //~v77gI
                joinpos=Pcurcol;                                   //~v77gI
//*no HKDBCSERR on dd fmt                                          //~va20I~
				addlen+=charjoinsetdbcstbl(0,Pplh,&joinpos,&len);  //~v77gI
#ifdef UTF8SUPPH                                                   //~va1qI~
              if (!vhexmode)                                          //~v73gI//~va12I~
#endif                                                             //~va1qI~
#ifdef UTF8SUPPH                                                   //~va1cR~
				if (UDBCSCHK_DBCSNOT1ST(*pcd))//setdbcstbl changed this column to dbcs parts not 1st(conbined to prev column)                        //~v77gR//~va1cR~
#else                                                              //~va1cR~
				if (*pcd==UDBCSCHK_DBCS2ND)                        //~v77gR
#endif                                                             //~va1cR~
				    Ppcw->UCWreason=UCWREASON_HEXSTEPDEL;	//func_del_file dose not call filecharcsr(assume csr will not move),so//~v77gR
            }                                                      //~v77gI
            if (lcmddel(Ppcw,plhnext,plhnext,1,0,1)==UALLOC_FAILED)//~v057R~
					//1 linedel,no csr move,clear UFHcmdline    //~v057I~
            	return UALLOC_FAILED;                           //~v04dI~
          if (!Slcmdplh2)                                          //~v0i7I~
			UPCTRREQ(pfh);	//end of a shot                        //~v0ceI~
		}                                                       //~5104I~
		else		//not concat line                           //~5104I~
		{                                                       //~5104I~
          if (vhexmode)	//not input on hex part                    //~v448I~//~v73uI
          {                                                        //~v73wI
			if (*pcd==TABCHAR)                              //~5104R~//~v73wI
//  			keyindatalen=TABSKIPCTR2(binsw,Pcurcol)+1;     //~v106I~//~v8@2R
    			keyindatalen=TABSKIPCTR2F(binsw,tabskip,Pcurcol)+1;     //~v106I~//~v8@2I
            else                                                   //~v73wI
			    keyindatalen=1;  //nodbcs consideration                                //~v448I~//~v73uI
          }                                                        //~v73wI
          else                                                     //~v448I~//~v73uI
          if (hexinpsw)	//not input on hex part                    //~v448I~
			    keyindatalen=1;                                    //~v448I~
          else                                                     //~v448I~
          {                                                        //~v448I~
#ifdef UTF8UCS2                                                    //~va20I~
//            if (swutf8file && u8vhexrepsw)                         //~va20I~//~va38R~
//            {                                                      //~va20I~//~va38R~
//                *(pc+1)=*keyindata_dddata;  //dbcs shirinked to sbcs//~va20I~//~va38R~
//                *(pcd+1)=*keyindata_dddbcs;//rep by input sbcs(ascii/ucs) before shift//~va20I~//~va38R~
//            }                                                      //~va20I~//~va38R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
            if (swutf8file && u8vhexrepsw>0) //ucs4 vhexline makeucs//~va3xI~
            {                                                      //~va3xI~
            	keyindatalen=u8vhexrepsw+delpadlen;	//delete len(includeing tab padding)//~va3xI~
//              memcpy(pc+keyindatalen,keyindata_dddata,keyindatalen_dd);//~va3xI~//~vb2DR~
                memcpy(pc+keyindatalen,keyindata_dddata,(size_t)keyindatalen_dd);//~vb2DI~
//  	        memcpy(pcd+keyindatalen,keyindata_dddbcs,keyindatalen_dd);//~va3xI~//~vb2DR~
    	        memcpy(pcd+keyindatalen,keyindata_dddbcs,(size_t)keyindatalen_dd);//~vb2DI~
            }                                                      //~va3xI~
            else	//not make ucs4                                //~va3xI~
#endif                                                             //~va3xI~
			if (UDBCSCHK_DBCS1STLU(*pcd))	//also ucs dd fmt      //~va20R~
            {                                                      //~va38I~
#else                                                              //~va20I~
			if (*pcd==DBCS1STCHAR)                              //~5104R~
            {         //for indentation chk(no effect because UTF8UCS is defined)//~vagpI~
#endif                                                             //~va20I~
#ifdef UTF8SUPPH                                                   //~va1cR~
			    keyindatalen=1+xesub_cleardbcssplit(XESUBCDSO_LEFT|XESUBCDSO_GETCTR,0/*data*/,pcd+1,Pendcol-Pcurcol,0/*repct*/);//~va1cR~
#else                                                              //~va1cR~
			    keyindatalen=2;                                 //~5104R~
#endif                                                             //~va1cR~
#ifdef UTF8UCS2                                                    //~va38I~
                if (swutf8file && u8vhexrepsw)                     //~va38I~
                {                                                  //~va38I~
                	keyindatalen--;     //dddata len=1 if OPDEL is selected(shrink case)//~va38R~
                    *(pc+keyindatalen)=*keyindata_dddata;  //dbcs shirinked to sbcs//~va38I~
                    *(pcd+keyindatalen)=*keyindata_dddbcs;//rep by input sbcs(ascii/ucs) before shift//~va38I~
                }                                                  //~va38I~
#endif                                                             //~va38I~
            }                                                      //~va38I~
			else                                                //~5104R~
            {                                                      //~va38I~
				if (*pcd==TABCHAR)                              //~5104R~
//  				keyindatalen=TABSKIPCTR(Pcurcol)+1;	           //~v106R~
//  				keyindatalen=TABSKIPCTR2(binsw,Pcurcol)+1;     //~v106I~//~v8@2R
    				keyindatalen=TABSKIPCTR2F(binsw,tabskip,Pcurcol)+1;     //~v106I~//~v8@2I
				else                                            //~5104R~
				    keyindatalen=1;                             //~5104R~
#ifdef UTF8UCS2                                                    //~va38I~
                if (swutf8file && u8vhexrepsw)                     //~va38R~
                {                                                  //~va38R~
                    if (*(pcd+keyindatalen)==TABCHAR)              //~va38R~
                        keyindatalen+=TABSKIPCTR2F(binsw,tabskip,(Pcurcol+keyindatalen))+1;//~va38R~
                    else                                           //~va38I~
                    	keyindatalen++;	//for 2nd byte             //~va38R~
                    keyindatalen-=keyindatalen_dd;                 //~va38I~
                    memcpy(pc+keyindatalen,keyindata_dddata,(UINT)keyindatalen_dd);//~va38R~
                    memcpy(pcd+keyindatalen,keyindata_dddbcs,(UINT)keyindatalen_dd);//~va38R~
                }                                                  //~va38R~
#endif                                                             //~va38I~
            }                                                      //~va38I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	        setobtabdbcs(0,0,Pbuff,Pdbcs,Pendcol,Pcurcol,keyindatalen);//~va50I~
#else                                                              //~va50I~
	        setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pcurcol,keyindatalen);//~v0c4I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
 						//replace deleted tab/dbcs                 //~v0c4I~
          }//not hexinput                                          //~v448I~
			len=Pendcol-Pcurcol-keyindatalen;                   //~5104R~
            UTRACED("xechar DEL data before",pc,len+keyindatalen); //~vaj0I~
            UTRACED("xechar DEL dbcs before",pcd,len+keyindatalen);//~vaj0I~
			memcpy(pc,pc+keyindatalen,(UINT)len);               //~5104R~
			memcpy(pcd,pcd+keyindatalen,(UINT)len);             //~5104R~
			addlen=-keyindatalen;                               //~5104R~
            UTRACED("xechar DEL data after ",pc,len);              //~vaj0I~
            UTRACED("xechar DEL dbcs after ",pcd,len);             //~vaj0I~
		}                                                       //~5104I~
		if (Pplh)		//file client area
		{
	        if (oomlen)                                            //~v0evI~
            {                                                      //~v0evI~
                Pplh->ULHlen+=addlen;                              //~v0evI~
                addlen=0;                                          //~v0evM~
//  			fileoomshiftback(pfh,Pplh,oomlen);                 //~v0evI~//~v74ER
    			fileoomshiftback(pfh,Pplh,oomlen,0);                 //~v0evI~//~v74EI
			}                                                      //~v0evI~
			if (UCBITCHK(Pplh->ULHflag2,ULHF2TABFOUND))//chk at file write//~5102R~
            {                                                   //~v04dI~
	          if (oomlen)                                          //~v0evI~
              {                                                    //~v73hI
//  			fileimtabexp(Pplh,Pcurcol,0,mergin);//expand in mergin//~v0evR~//~v73hR
                imlen=mergin-keyindatalen-Pcurcol;                 //~v73hI
    			fileimtabexp(Pplh,Pcurcol,&imlen,mergin);//expand in mergin//~v73hI
              }                                                    //~v73hI
              else                                                 //~v0evI~
              {                                                    //~v0evI~
				chartabexp(Pplh,&Pbuff,&Pdbcs,&pc,&pcd,Pcurcol,len,&addlen);//~5507R~
                UALLOCCHK(Stabexpoksw,UALLOC_FAILED);//return if storage shortage//~v04dI~
              }                                                    //~v0evI~
            UTRACED("xechar DEL TAB FOUND plh data after ",Pplh->ULHdata,Pplh->ULHlen);//~vaj0I~
			}	                                                //~v04dI~
//            if (hexinpsw) //not input on hex part                  //~v448I~//~v7a0R
//                filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,FSDT_TABSAVE);//~v448I~//~v7a0R
//            else                                                   //~v734I//~v7a0R
//            if (vhexmode)   //hex display line of vhexmode         //~v734I//~v7a0R
//                filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,FSDT_TABSAVE);//~v734I//~v7a0R
        	if (Pcurcol!=Pendcol)       //not del CR               //~v0bpR~//~v7a0I
                if (hexinpsw  //not input on hex part                  //~v448I~//~v7a0R
//              ||  vhexmode)   //hex display line of vhexmode     //~v7a0R//~v7a6R
                ||  vhexmode    //hex display line of vhexmode     //~v7a6I
                ||  (Pcurcol<=Pendcol && Pcurcol && *(pcd-1)==UDBCSCHK_HKDBCSERR)//~v7a6I
                )                                                  //~v7a6I
                {                                                  //~v7a6I
//*no HKDBCSERR on dd fmt                                          //~va20I~
//*no vhexmode for utf8file,hexinpsw=hHexmode is binfile,hexkbdsw(hex input mode) is rejexted on utf8 file//~va20I~
                    filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen+addlen,FSDT_TABSAVE);//~v7a0R
                }                                                  //~v7a6I
            UTRACED("xechar DEL plh data after ",Pplh->ULHdata,Pplh->ULHlen);//~vaj0I~
		}
		else		//cmd line
		{
			memset(pc+len,0,(UINT)keyindatalen);                //~4C27R~
			memset(pcd+len,0,(UINT)keyindatalen);               //~4C27R~
		}
		break;
//**********************                                           //~va50I~
//* EOL ****************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPEEOL:	//erase eof(trunc line)                 //~5111R~
	case CHAROPEEOLIGM:	//erase eof(trunc line;erase also oom)                 //~5111R~//~v74jI
		if (Pcurcol>=Pendcol)
			return 4;
        inmerginsw=0;                                              //~v0dbI~
		if (Pplh)                                               //~4C27I~
        {                                                          //~v0c3I~
	     if (Pmode!=CHAROPEEOLIGM)	//erase eof(trunc line)        //~v74jI
         {                                                         //~v74jI
    		if (Pcurcol>=mergin)                                   //~v0eqI~
//        		if (oomprotsw || spfsw2)                           //~v417R~
          		if (oomprotsw)                                     //~v417I~
//  				return charmerginerr(mergin);                                    //~51//~v417R~
    			return errprotected();                             //~v417I~
                                                                   //~v0eqI~
//        if (spfsw2)                                              //~v0eqR~
//        {                                                        //~v0eqR~
//  		if (Pcurcol>=mergin)                                   //~v0eqR~
//  			return charmerginerr(mergin);                                    //~51//~v0eqR~
//  		inmerginsw=1;                                          //~v0doR~
//        }                                                        //~v0eqR~
//        else                                                     //~v0eqR~
//        if (!spfsw2)                                             //~v417R~
          if (!spfpos || oomprotsw)//not spf by n of topline or /mn cmdline option//~v42fR~
          	if (merginsw)                                          //~v0dbI~
	    		if (Pcurcol<mergin && Pendcol>mergin)//data on out of mergin//~v0dbR~
                	inmerginsw=1;                                  //~v0dbI~
//            if (Pcurcol>=mergin)                                 //~v0cgR~
//            {                                                    //~v0cgR~
//                if (UCBITCHK(pfh->UFHflag2,UFHF2MERGINCID))      //~v0cgR~
//                {                                                //~v0cgR~
//                    filegetcidlen2(Pplh,pfh,0,&lastcidpos);      //~v0cgR~
//                    if (lastcidpos==mergin) //cid on just mergin //~v0cgR~
//                        return 0;                                //~v0cgR~
//                }                                                //~v0cgR~
//                oomlen=0;       //shorten lrecl                  //~v0cgR~
//            }                                                    //~v0cgR~
//            else                                                 //~v0cgR~
//                oomlen=filegetoomlen(pfh,Pplh);  //out of mergin len//~v0cgR~
         }//not ignore margin                                      //~v74jI
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)	//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
//  	    oomlen=filegetoomlen(pfh,Pplh);  //out of mergin len   //~v0cgR~
        }                                                          //~v0cgR~
//        else                                                     //~v0cgR~
//            oomlen=0;                                            //~v0cgR~
//        if (oomlen                                               //~v0cgR~
//        &&  Pcurcol<mergin) //in mergin                          //~v0cgR~
      if (inmerginsw)                                              //~v0dbR~
        keyindatalen=mergin-Pcurcol;                               //~v0dbR~
      else                                                         //~v0dbR~
		keyindatalen=Pendcol-Pcurcol;                           //~4C27R~
//    if (vhexmode)                                                //~v76AI//~va3SR~
      if (vhexmode                                                //~v76AI//~va3SI~
      ||  (optorg & CFEO_VHEXLCMDS)   //split lcmd on vhex line    //~va3SI~
      )                                                            //~va3SI~
      {                                                            //~v76AI
	      if (inmerginsw)                                              //~v0dbR~//~v76AI
          {                                                        //~v76AI
#ifdef UTF8SUPPH                                                   //~va1cR~
      		if (UDBCSCHK_DBCSNOT1ST(*(pcd+keyindatalen)))  //pad or 2nd                //~v76AI//~va1cR~
#else                                                              //~va1cR~
      		if (*(pcd+keyindatalen)==DBCS2NDCHAR)                  //~v76AI
#endif                                                             //~va1cR~
//*no vhexmode for utf8file                                        //~va20I~
    			filesetdbcstbl(pc+keyindatalen,pcd+keyindatalen,Pendcol-mergin,FSDT_TABSAVE);//~v76AI
          }                                                        //~v76AI
          else                                                     //~v76AI
#ifdef UTF8SUPPH                                                   //~va1cR~
      		if (Pcurcol>0 && UDBCSCHK_DBCSNOT1ST(*pcd))	//del not 1st//~va1cR~
            {                                                      //~va1cR~
            	splitdbcsctr=xesub_cleardbcssplit(XESUBCDSO_RIGHT|XESUBCDSO_GETCTR,0/*Pdata*/,Pdbcs,Pcurcol,0/*repch*/);//~va1cR~
//*no vhexmode for utf8file                                        //~va20I~
    			filesetdbcstbl(pc-splitdbcsctr,pcd-splitdbcsctr,splitdbcsctr,0);                    //~v76AR//~va1cR~
            }                                                      //~va1cR~
#else                                                              //~va1cR~
      		if (Pcurcol>0 && *pcd==DBCS2NDCHAR)                    //~v76AR
    			filesetdbcstbl(pc-1,pcd-1,1,0);                    //~v76AR
#endif                                                             //~va1cR~
      }                                                            //~v76AI
      else                                                         //~v76AI
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        setobtabdbcs(0,0,Pbuff,Pdbcs,Pendcol,Pcurcol,keyindatalen);//~va50I~
#else                                                              //~va50I~
        setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pcurcol,keyindatalen);    //~v0c4I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
 						//replace deleted tab/dbcs                 //~v0c4I~
      if (inmerginsw)                                              //~v0dbR~
      	addlen=0;		//clear only,same ulhlen                   //~v0dbI~
      else                                                         //~v0dbI~
		addlen=-keyindatalen;                                   //~4C27R~
		if (!Pplh)			//not file client area                 //~v0dbR~
		{
			memset(pc,0,(UINT)keyindatalen);                    //~4C27R~
			memset(pcd,0,(UINT)keyindatalen);                   //~4C27R~
		}
    	else			//not file client area                     //~v0dbR~
        	if (inmerginsw)                                        //~v0dbR~
//need?		memset(pcd,0,(UINT)keyindatalen);//data cut by ULHlen//~5506M~
//        else            //not file client area                   //~v0cgR~
//            if (oomlen) //out of mergin exist                    //~v0cgR~
            {                                                      //~v0dbR~
                memset(pc,' ',(UINT)keyindatalen);                 //~v0dbR~
                memset(pcd,0,(UINT)keyindatalen);                  //~v0dbR~
            }                                                      //~v0dbR~
		break;
//**********************                                           //~va50I~
//* ETOL ***************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPETOL:	//erase tof(top of line)                //~5102R~
	case CHAROPETOLCOB:	//erase tof(keep cob margin)                //~5102R~//~v74qI
//      if (Pmode==CHAROPETOLCOB                                   //~v74sR
        if (Pplh && Pmode==CHAROPETOLCOB                           //~v74sI
        &&  UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file     //~v42gI~//~v74qI
        	if (Pstartcol==0)                                      //~v74qR
            {                                                      //~v74AI
                if (Pcurcol>SPFCOBNUMFLDLEN)                       //~v74qI
		            Pstartcol=SPFCOBNUMFLDLEN;                           //~v42gI~//~v74qR
                else                                               //~v74qI
                if (Pcurcol==SPFCOBNUMFLDLEN)                      //~v74qI
                    return 0;                                      //~v74qI
                else                                               //~v74qI
                    return 4;                                      //~v74qI
            }                                                      //~v74AI
        if (protlen>Pstartcol)                                     //~v0ihI~
        	Pstartcol=protlen;   //dont clear prot line            //~v0ihI~
		if (Pcurcol<=Pstartcol)//startcol>0 when box cut        //~5506R~
			return 4;                                           //~4C25I~
        inmerginsw=0;                                              //~v0doI~
		if (Pplh)                                               //~4C27I~
        {                                                          //~v0dbI~
            if (oomprotsw)                                         //~v0eqI~
//              if (Pcurcol>=mergin)//clear before cursor          //~v618R~
                if (Pcurcol>mergin)//clear before cursor           //~v618I~
//                  return charmerginerr(mergin);                                    //~51//~v417R~
		   			return errprotected();                         //~v417I~
//        if (spfsw2)                                          //~v417R~//~va3SR~
//            {                                                    //~v417R~
//                if (Pcurcol>mergin)//just mergin ok,erase before //~v417R~
//                {                                                //~v417R~
//                    Pcurcol=mergin;//drop all rec                //~v417R~
//                    pc=Pbuff+Pcurcol;                            //~v417R~
//                    pcd=Pdbcs+Pcurcol;                           //~v417R~
//                }                                                //~v417R~
//                inmerginsw=1;                                    //~v417R~
//            }                                                    //~v417R~
//            else                                                 //~v417R~
	            if (merginsw)                                      //~v0doR~
                {                                                  //~v58RI~
//  	            if (Pcurcol<mergin && Pendcol>mergin)//data on out of mergin//~v618R~
    	            if (Pcurcol<=mergin && Pendcol>mergin)//data on out of mergin//~v618I~
                    {                                              //~v74cI
        	            inmerginsw=1;                              //~v0doR~
                        oomlen=Pendcol-mergin;                     //~v74cI
                    }                                              //~v74cI
                    else                                           //~v0doI~
	    	            if (Pcurcol>mergin && Pendcol>mergin)//data on out of mergin//~v0dpR~
                        {                                          //~v0dpI~
                            Ppcw->UCWreason=1;  //parm to func_erasetol_file//~v0dpI~
                            Pstartcol=mergin;	//up to mergin     //~v0doI~
                        }                                          //~v0dpI~
                }                                                  //~v58RI~
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
        }                                                          //~v0dbI~
        if (Pcurcol>Pendcol)                                       //~v0doR~
		{                                                       //~4C29I~
			Pcurcol=Pendcol;    	//all cut                   //~4C29I~
			pc=Pbuff+Pendcol;                                   //~4C29I~
			pcd=Pdbcs+Pendcol;                                  //~4C29I~
		}                                                       //~4C29I~
        if (Pstartcol>Pendcol)                                     //~v66gI~
            Pstartcol=Pendcol;                                     //~v66gI~
      if (inmerginsw)                                              //~v0doR~
      {                                                            //~v0dbI~
		addlen=0;                                                  //~v0dbI~
		len=mergin-Pcurcol;                                        //~v0dbI~
      }                                                            //~v0dbI~
      else                                                         //~v0dbI~
      {                                                            //~v0dbI~
		addlen=Pstartcol-Pcurcol;    	//all cut               //~4C29I~
		len=Pendcol-Pcurcol;                                    //~4C29I~
	  }	                                                           //~v0dbI~
		if (Pplh)			//file client area                  //~4C29I~
        {                                                       //~4C29I~
//*left/right boundary tab/tbcs replace by space                //~5503I~
//        if (!vhexmode)                                           //~v76AI//~va3SR~
          if (!vhexmode                                           //~v76AI//~va3SR~
          &&  !(optorg & CFEO_VHEXLCMDS)   //split lcmd on vhex line//~va3SI~
          )                                                        //~va3SI~
          {                                                        //~v76AI
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	setobtabdbcs(0,0,Pbuff,Pdbcs,Pendcol,Pstartcol,Pcurcol-Pstartcol);//~va50I~
#else                                                              //~va50I~
        	setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pstartcol,Pcurcol-Pstartcol);//~5503I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            if (inmerginsw)                                        //~v0doI~//~v74dI
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	        	setobtabdbcs(0,0,Pbuff,Pdbcs,Pendcol,mergin,0);//both side at the boundary//~v74dI//~va50I~
#else                                                              //~va50I~
	        	setobtabdbcs(Pbuff,Pdbcs,Pendcol,mergin,0);//both side at the boundary//~v74dI
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
          }//!vhex                                                 //~v76AI
			memcpy(Pbuff+Pstartcol,pc,(UINT)len);               //~5503I~
			memcpy(Pdbcs+Pstartcol,pcd,(UINT)len);              //~5503I~
//          if (spfsw2)                                            //~v0doR~
            if (inmerginsw)                                        //~v0doI~
            {                                                      //~v0dbI~
                memset(Pbuff+Pstartcol+len,' ',(UINT)(mergin-Pstartcol-len));//~v0dpR~
                memset(Pdbcs+Pstartcol+len,0,(UINT)(mergin-Pstartcol-len));//~v0dpR~
            }                                                      //~v0dbI~
          	if (vhexmode && len>0)                                 //~v76AI
          	{                                                      //~v76AI
#ifdef UTF8SUPPH                                                   //~va1cR~
				if ((Pstartcol>0 && UDBCSCHK_DBCSNOTEND(*(Pdbcs+Pstartcol-1)))//prev is not dbcs last//~va1cR~
				||  (Pcurcol<Pendcol && UDBCSCHK_DBCSNOT1ST(*(Pdbcs+Pstartcol)))//current is not dbcs top//~va1cR~
				||  (inmerginsw && UDBCSCHK_DBCSNOT1ST(*(Pdbcs+mergin)))//margin line split dbcs//~va1cR~
#else                                                              //~va1cR~
				if ((Pstartcol>0 && *(Pdbcs+Pstartcol-1)==DBCS1STCHAR)//~v76AI
				||  (Pcurcol<Pendcol && *(Pdbcs+Pstartcol)==DBCS2NDCHAR)//~v76AR
				||  (inmerginsw && *(Pdbcs+mergin)==DBCS2NDCHAR)   //~v76AI
#endif                                                             //~va1cR~
                   )                                               //~v76AI
//*no vhexmode for utf8file                                        //~va20I~
    	    		filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen+addlen,FSDT_TABSAVE);//~v76AI
          	}                                                      //~v76AI
			pc=Pbuff+Pstartcol;                                 //~5126I~
			pcd=Pdbcs+Pstartcol;                                //~5126I~
			if (UCBITCHK(Pplh->ULHflag2,ULHF2TABFOUND))//chk at file write//~5102I~
            {                                                      //~v58RI~
	        if (spfsw2)                                            //~v0dhR~
	            filetabclear(Pplh);//tab clear                     //~v0dbR~
            else                                                   //~v0dbI~
            {                                                   //~v04dI~
              if (inmerginsw)                                      //~v74cI
              {                                                    //~v74cI
                imlen=mergin-Pstartcol;                            //~v74cI
    			fileimtabexp(Pplh,Pstartcol,&imlen,mergin);//expand in mergin//~v74cR
              }                                                    //~v74cI
              else                                                 //~v74cI
              {                                                    //~v74cI
				chartabexp(Pplh,&Pbuff,&Pdbcs,&pc,&pcd,Pstartcol,len,&addlen);//~5507R~
                UALLOCCHK(Stabexpoksw,UALLOC_FAILED);//return if storage shortage//~v04dI~
              }                                                    //~v74cI
            }                                                   //~v04dI~
            }                                                      //~v58RI~
//          if (spfsw2)                                            //~v0dpR~
//              addlen-=SPFNUMFLDLEN;   //drop num fld             //~v0dpR~
			Pcurcol=0;//for later ULHlen set logic              //~v03kI~
        }                                                       //~4C29I~
		else                                                    //~4C29I~
		{                                                       //~4C29I~
			memcpy(Pbuff+Pstartcol,pc,(UINT)len);               //~5503I~
			memcpy(Pdbcs+Pstartcol,pcd,(UINT)len);              //~5503I~
			memset(Pbuff+Pendcol+addlen,0,(UINT)(-addlen));     //~4C29I~
			memset(Pdbcs+Pendcol+addlen,0,(UINT)(-addlen));     //~4C29I~
		}                                                       //~4C29I~
		break;                                                  //~4C25I~
//**********************                                           //~va50I~
//* CTOL ***************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPCTOL:	//clear tol(top of line)                //~5111I~
	case CHAROPCTOLIM:  //clear tol(ignore margin)                 //~v74eI
        if (protlen>Pstartcol)                                     //~v0ihR~
        	Pstartcol=protlen;   //dont clear prot line            //~v0ihR~
		if (Pcurcol<=Pstartcol)                                 //~5111I~
			return 4;                                           //~5111I~
        if (oomprotsw)                                             //~v0eqI~
            if (Pcurcol>=mergin)//clear before cursor              //~v0eqI~
//  			return charmerginerr(mergin);                                    //~51//~v417R~
    			return errprotected();                             //~v417I~
//        if (spfsw2)                                              //~v417R~
//        {                                                        //~v417R~
//            if (Pcurcol>mergin)//clear before cursor             //~v417R~
//                Pcurcol=mergin;                                  //~v417R~
//        }                                                        //~v417R~
//        else    //not valid spf lien                             //~v417R~
        if (Pmode!=CHAROPCTOLIM) //not ignore margin               //~v74eI
        {                                                          //~v74qI
            if (Pplh)                                              //~v0dwI~
                if (merginsw)                                      //~v0dwI~
                    if (Pcurcol>mergin && Pendcol>mergin)          //~v0dwI~
                        Pstartcol=mergin;   //clear from mergin    //~v0dwI~
        }                                                          //~v74qI
        else                                                       //~v74qI
        {                                                          //~v74qI
          if (Pplh)                                                //~v74sI
            if (UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file     //~v42gI~//~v74qI
        		if (Pstartcol==0)                                  //~v74qI
                	if (Pcurcol>SPFCOBNUMFLDLEN)                   //~v74qI
		            	Pstartcol=SPFCOBNUMFLDLEN;                           //~v42gI~//~v74qI
        }                                                          //~v74qI
        if (Pcurcol>Pendcol)                                    //~5513M~
			Pcurcol=Pendcol;    	//all cut                   //~5513M~
		addlen=0;                                               //~5513M~
		len=Pcurcol-Pstartcol;                                  //~5513M~
		if (Pplh)                                               //~5111I~
        {                                                       //~5513I~
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
//          if (Pstartcol)                                         //~v0c4R~
//  	    	setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pstartcol,len);   //~v0c4R~
        }                                                       //~5513I~
      if (!vhexmode)                                               //~v76AI
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	setobtabdbcs(0,0,Pbuff,Pdbcs,Pendcol,Pstartcol,len);       //~va50I~
#else                                                              //~va50I~
    	setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pstartcol,len);           //~v0c4I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		memset(Pbuff+Pstartcol,' ',(UINT)len);                  //~5111I~
		memset(Pdbcs+Pstartcol,0,(UINT)len);                    //~5111I~
        if (vhexmode && len>0)                                     //~v76AI
        {                                                          //~v76AI
#ifdef UTF8SUPPH                                                   //~va1cR~
			if ((Pstartcol>0 && UDBCSCHK_DBCSNOTEND(*(Pdbcs+Pstartcol-1)))//~va1cR~
			||  (Pcurcol<Pendcol && UDBCSCHK_DBCSNOT1ST(*(Pdbcs+Pcurcol)))//~va1cR~
#else                                                              //~va1cR~
			if ((Pstartcol>0 && *(Pdbcs+Pstartcol-1)==DBCS1STCHAR) //~v76AI
			||  (Pcurcol<Pendcol && *(Pdbcs+Pcurcol)==DBCS2NDCHAR) //~v76AI
#endif                                                             //~va1cR~
               )                                                   //~v76AI
//*no vhexmode for utf8file                                        //~va20I~
    	    	filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,FSDT_TABSAVE);//~v76AI
        }                                                          //~v76AI
		break;                                                  //~5111I~
//**********************                                           //~va50I~
//* MGET ***************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPMGET:	//get block                             //~5125I~
		if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)//prepare undo and update process//~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
        	                                                    //~v04dI~
//*erase tol                                                    //~5125I~
		if (Pendcol<=Pstartcol)		//block out of line         //~5125R~
			addlen=-Pendcol;    	//all cut                   //~5125I~
		else                                                    //~5125I~
        {                                                       //~5125I~
			addlen=-Pstartcol;    	//erase tol                 //~5125I~
 	    	if (Pcurcol>Pendcol)        //full line             //~5125R~
				len=Pendcol-Pstartcol;	                        //~5125I~
			else                                                //~5125I~
				len=Pcurcol-Pstartcol;	//over line             //~5125I~
			memcpy(Pbuff,Pbuff+Pstartcol,(UINT)len);            //~5125R~
			memcpy(Pdbcs,Pdbcs+Pstartcol,(UINT)len);            //~5125R~
		}                                                       //~5125I~
//*erase eol                                                    //~5125I~
		Pendcol+=addlen;			//new rec len               //~5125I~
		Pcurcol-=Pstartcol;			//block width               //~5125I~
		if (Pendcol<=Pcurcol)		//block contain full rec    //~5125I~
		{                                                       //~5125I~
			memset(Pbuff+Pendcol,' ',(UINT)(len=Pcurcol-Pendcol));//~5506R~
					//clear for cmd line etc                    //~5506I~
			memset(Pdbcs+Pendcol,0,(UINT)len);//capsave needs   //~v01bI~
			addlen+=len;                                        //~5125I~
		}                                                       //~5125I~
		else            			//over rec                  //~5125I~
			addlen-=(len=Pendcol-Pcurcol);	//cut len           //~5126R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		xesub_setdbcssplit(0,0/*plh=0;do split process*/,Pbuff,Pdbcs,Pcurcol,' ');//inner boundary dbcs//~va50R~
#else                                                              //~va50I~
		setdbcssplit(Pbuff,Pdbcs,Pcurcol,' ');//inner boundary dbcs//~5506R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		if (UCBITCHK(Pplh->ULHflag2,ULHF2TABFOUND))//chk at file write//~5125R~
		{                                                       //~5125R~
			UCBITOFF(Pplh->ULHflag2,ULHF2TABFOUND);//drop tab   //~5125I~
			chartabclear(Pdbcs,Pcurcol);                        //~5125I~
		}                                                       //~5125R~
		Pcurcol=0;//for later ULHlen set logic                  //~5126I~
		break;                                                  //~5125I~
	}//switch by mode

	scrclearconfirmmsg();	//clear confirmation msg
                                                                //~5103I~
//	if (Pplh)                                                      //~v0avR~
//		if ((Pplh->ULHlen=max(Pplh->ULHlen,Pcurcol)+addlen)>MAXLINEDATA)//~v0avR~
//		{	                                                       //~v0avR~
//			Pplh->ULHlen=MAXLINEDATA;                              //~v0avR~
//			setdbcssplit(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,' ');//~v0avR~
//			return charmaxovererr(MAXLINEDATA);                                //~51//~v0avR~
//		}                                                          //~v0avR~
  	if (Pplh)                                                      //~v0avI~
    {                                                              //~v0byI~
//      if (Pmode==CHAROPEEOL //erase eof(trunc line)              //~v0cgR~
//      &&  oomlen)               //shift occue                    //~v0cgR~
//        fileoomshiftback(pfh,Pplh,oomlen);  //plhlen update      //~v0cgR~
//      else                                                       //~v0cgR~
//      {                                                          //~v0cgR~
  		Pplh->ULHlen=max(Pplh->ULHlen,Pcurcol)+addlen;             //~v0avI~
//      if (oomlen)                                                //~v0evR~
//  	if (Pmode==CHAROPINS    //isrt                             //~v0evR~
//  	||  Pmode==CHAROPDEL)	//del                              //~v0evR~
//  		if (fileoomshiftback(pfh,Pplh,oomlen)==UALLOC_FAILED)  //~v0evR~
//          	return UALLOC_FAILED;                              //~v0evR~
//      }                                                          //~v0cgR~
    }                                                              //~v0byI~
	return 0;
}//charfld edit

//**************************************************            //~5103I~
//*tab expand by char input                                     //~5103I~
//*  update pc and pcd ptr when buff expand occued              //~5211I~
//*parm 1:ULINEH addr                                           //~5103I~
//*parm 2:data start ptr(output)                                //~5507I~
//*parm 3:dbcs start ptr(output)                                //~5507I~
//*parm 4:data ptr(input/output)                                //~5507I~
//*parm 5:dbcs ptr(input/output)                                //~5507I~
//*parm 6:current cursor column                                 //~5507R~
//*parm 7:chk len upto end of record                            //~5507R~
//*parm 8:addlen addr to be clear if tab expanded(LHlen was set)//~5507R~
//*return:expanded len                                          //~5103I~
//**************************************************            //~5103I~
int chartabexp(PULINEH Pplh,UCHAR **Pdata0,UCHAR **Pdbcs0,      //~5507R~
		UCHAR **Pdata,UCHAR **Pdbcs,int Pcurcol,int Plen,int *Paddlen)//~5507I~
{                                                               //~5103I~
	int len,rc;                                                 //~v04dR~
	UCHAR *pc,*pcd;                                             //~5103I~
//****************************                                  //~5103I~
	pc=Pplh->ULHdata;                                           //~5507R~
	pcd=Pplh->ULHdbcs;	//save old addr                         //~5507I~
	len=Plen;                                                   //~5103I~
	Stabexpoksw=1;		//no storage shortage                   //~v04dI~
	if (rc=filetabexp(1,Pplh,Pcurcol,&len),rc) //no tab detected//~v04dR~
    {                                                           //~v04dI~
    	if (rc==UALLOC_FAILED)                                  //~v04dR~
			Stabexpoksw=0;	//storage shortage                  //~v04dI~
		return 0;                                               //~5103I~
	}                                                           //~v04dI~
    if (Pdata0)                                                 //~5507I~
		*Pdata0=Pplh->ULHdata;                                  //~5507R~
    if (Pdbcs0)                                                 //~5507I~
		*Pdbcs0=Pplh->ULHdbcs;                                  //~5507R~
//	*Pdata=Pplh->ULHdata+(ULONG)*Pdata-(ULONG)pc;               //~5507R~//~vafkR~
	*Pdata=Pplh->ULHdata+(ULPTR)*Pdata-(ULPTR)pc;                  //~vafkI~
//	*Pdbcs=Pplh->ULHdbcs+(ULONG)*Pdbcs-(ULONG)pcd;              //~5103I~//~vafkR~
	*Pdbcs=Pplh->ULHdbcs+(ULPTR)*Pdbcs-(ULPTR)pcd;                 //~vafkI~
	*Paddlen=0;                                                 //~5103I~
	return len-Plen;	//expand length                         //~5103I~
}//chartabexp                                                   //~5103I~
                                                                //~5103I~
//**************************************************               //~v77gI
//*charjoinsetdbcstbl                                              //~v77gI
//* re-evaluate dbcstbl after data/dbcs concatinated               //~v77gI
//* called when 1st line eol is utf8 err                           //~v77gI
//*parm  :maxlen                                                   //~v77gI
//*return:expand(+)/shrink(-) count                                //~v77gI
//**************************************************               //~v77gI
int charjoinsetdbcstbl(int Popt,PULINEH Pplh,int *Pppos,int *Pplenc)//~v77gI
{                                                                  //~v77gI
	int lenutf,newpos,pos,lenc,newlenc;                            //~v77gI
    UCHAR *putch;                                                  //~v77gR
#ifdef UTF8UCS2                                                    //~va20I~
    PUFILEH pfh;                                                   //~va20I~
#endif                                                             //~va20I~
//****************************                                     //~v77gI
	newlenc=lenc=*Pplenc;                                          //~v77gI
	newpos=pos=*Pppos;                                             //~v77gI
    lenutf=pos+lenc;                                               //~v77gI
	putch=Pplh->ULHdata;                                           //~v77gR
#ifdef UTF8UCS2                                                    //~va20I~
    pfh=UGETPFH(Pplh);                                             //~va20I~
    if (!FILEUTF8MODE(pfh))                                        //~va20I~
#endif                                                             //~va20I~
	    filesetdbcstbl(putch,Pplh->ULHdbcs,lenutf,FSDT_TABSAVE);   //~v77gR
	newlenc=lenutf-newpos;                                         //~v77gI
    *Pppos=newpos;                                                 //~v77gI
    *Pplenc=newlenc;                                               //~v77gI
    return newpos+newlenc-(pos+lenc);                              //~v77gI
}//charsetdbcstbljoin                                              //~v77gI
//**************************************************            //~5103I~
//*charmaxovererr                                               //~5107R~
//* errmsg for data over limit                                  //~5103I~
//*parm  :maxlen                                                   //~v0avR~
//*return:4                                                     //~5103I~
//**************************************************            //~5103I~
int charmaxovererr(int Pmaxlen)                                    //~v0avR~
{                                                               //~5103I~
//****************************                                  //~5103I~
//  uerrmsg("Max record length is %d",                             //~v0avR~
//  		"最大 レコード長は %d です",                           //~v0avR~
//  		MAXLINEDATA);                                          //~v0avR~
//  uerrmsg("Mergin overflow(>%d)",                                //~v0avR~//~v760R
  if (Pmaxlen==MAXLINEDATA)                                        //~vaj0R~
//  uerrmsg("exceeded max display length(%d), /M parm enable to change the width",//~vazeR~
//  		"\x95\\示最大行長(%d)溢れ,/Mパラメータで\x95\\示行長を短くできます",//~vazeR~
    uerrmsg("exceeded max display length(%d)",                     //~vazeI~
    		"\x95\\示最大行長(%d)溢れ",                            //~vazeI~
    		Pmaxlen);                                              //~vaj0R~
  else                                                             //~vaj0R~
    uerrmsg("Margin overflow(>%d)",                                //~v0avR~//~v760I
    		"行マージン溢れ(>%d)",                                 //~v0avR~
    		Pmaxlen);                                              //~v0avI~
	return 4;                                                   //~5103I~
}//charmaxovererr                                               //~5107R~
//**************************************************               //~v71HI~
//*charmaxovererr                                                  //~v71HI~
//* errmsg for data over limit                                     //~v71HI~
//*parm  :maxlen                                                   //~v71HI~
//*return:4                                                        //~v71HI~
//**************************************************               //~v71HI~
int charfixlenovererr(int Plrecl)                                  //~v71HI~
{                                                                  //~v71HI~
//****************************                                     //~v71HI~
    uerrmsg("File is fixed length(=%d)",                           //~v71HI~
    		"ファイルは固定長です(=%d)",                           //~v71HI~
    		Plrecl);                                               //~v71HI~
	return 4;                                                      //~v71HI~
}//charmaxovererr                                                  //~v71HI~
                                                                //~5125I~
//**************************************************               //~v0avI~
//*charmerginerr                                                   //~v0avI~
//* errmsg for data out of mergin                                  //~v0avI~
//*parm  :maxlen                                                   //~v0avI~
//*return:4                                                        //~v0avI~
//**************************************************               //~v0avI~
int charmerginerr(int Pmaxlen)                                     //~v0avI~
{                                                                  //~v0avI~
//****************************                                     //~v0avI~
//  uerrmsg("Out of Mergin(>%d)",                                  //~v0avI~//~v760R
    uerrmsg("Out of Margin(>%d)",                                  //~v0avI~//~v760I
    		"行マージン外(>%d)",                                   //~v0avR~
    		Pmaxlen);                                              //~v0avI~
	return 4;                                                      //~v0avI~
}//charmerginerr                                                   //~v0avI~
//******************************************************************************//~vbi3I~
int helpchlcmd()                                                   //~vbi3I~
{                                                                  //~vbi3I~
    uerrmsg("Available cmd on CmdHistoryList is %s",                                  //~v0avI~//~v760I//~vbi3I~
    		"コマンドヒストリーリストでは行コマンド  %s が使用できます",//~vbi3I~
            CHL_CMDLIST);                                          //~vbi3I~
	return 4;                                                      //~vbi3I~
}//helpchlcmd()                                                    //~vbi3I~
//*******************************************************          //~vbi3I~
//!chargetlinedata                                                 //~vbi3I~
//*******************************************************          //~vbi3I~
int charsetchlcmd(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PUCLIENTWE Ppcwtgt)//~vbi3I~
{                                                                  //~vbi3I~
    char *pdata;   //word get area                                 //~vbi3I~
    int datalen;                                                   //~vbi3R~
    int swutf8file,u8len,opt,lclen,rc2;                            //~vbi3R~
//*******************                                              //~vbi3I~
    pdata=Pplh->ULHdata;                                           //~vbi3I~
    datalen=Pplh->ULHlen;                                          //~vbi3I~
    UTRACED("wordpos=%s",pdata,datalen);                           //~vbi3I~
    swutf8file=PLHUTF8MODE(Pplh);                                  //~vbi3I~
    if (swutf8file)                                                //~vbi3I~
    {                                                              //~vbi3I~
        opt=0;                                                     //~vbi3I~
    	if ((rc2=xeutfcvdd2fl(opt,Ppcw,pdata,Pplh->ULHdbcs,datalen,//~vbi3I~
				Gcmdbuffu8,sizeof(Gcmdbuffu8),&u8len,              //~vbi3I~
    			Gcmdbufflc,Gcmdbuffdbcs,Gcmdbuffct,sizeof(Gcmdbufflc),&lclen))>=4)//~vbi3I~
            return 4;                                              //~vbi3I~
        Gcmdbufflclen=lclen;                                       //~vbi3I~
        datalen=u8len;                                             //~vbi3I~
        pdata=Gcmdbuffu8;                                          //~vbi3I~
    }                                                              //~vbi3I~
	opt=0;                                                         //~vbi3I~
	setflddatadbcscmd_byutf8(opt,Ppcwtgt,0/*pod*/,pdata,Gcmdbuffdbcs,datalen);//~vbi3I~
	csrhomepos(Ppcwtgt->UCWsplitid);                               //~vbi3I~
    UTRACEP("func_copywordcmd\n");                                 //~vbi3I~
	return 0;                                                      //~vbi3I~
}//charsetchlcmd                                                   //~vbi3I~
//**************************************************************************//~vbi3I~
//*accept cmd history list cmd  s/S/x/X                            //~vbi3I~
//**************************************************************************//~vbi3I~
int charfldeditchl(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)          //~vbi3R~
{                                                                  //~vbi3I~
	int cmd,rc;                                                    //~vbi3R~
    int swexec=0,swpopup=0,swsplit=0;                              //~vbi3I~
    PUCLIENTWE pcwtgt,pcw2;                                        //~vbi3R~
    PUSCRD psd;                                                    //~vbi3I~
    PULINEH plh;                                                   //~vbi3R~
    PUSCMD psc;                                                    //~vbi3I~
//********************************                                 //~vbi3I~
    if (!CSRONFILELINE(Ppcw))                                      //~vbi3R~
        return -1;                                                 //~vbi3I~
    if (Ppcw->UCWrcsrx<Ppcw->UCWlinenosz-1)  //allow on sparator col("|")//~vbi3R~
        return -1;   //continue process normal lineno fld input    //~vbi3R~
    if (Ppcw->UCWkeytype!=UCWKTSBCS)                               //~vbi3I~
        return -1;   //allow limited cmd                           //~vbi3I~
 	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                               //~vbi3M~
	plh=psd->USDbuffc;                                             //~vbi3M~
    psc=funcsrchpsc(FSPO_ERRMSG,plh->ULHuscentryno);               //~vbi3R~
    if (!psc)                                                      //~vbi3M~
    	return 4;                                                  //~vbi3M~
    cmd=(int)Ppcw->UCWkeydata[0];                                  //~vbi3R~
    pcwtgt=Ppcw;                                                   //~vbi3I~
//s:set,x:execute,t:set split,y:execute split                      //~vbi3R~
//uppercase for myself:no popup                                    //~vbi3I~
    switch (cmd)                                                   //~vbi3I~
    {                                                              //~vbi3I~
    case 'x':                                                      //~vbi3I~
    	swexec=1;                                                  //~vbi3I~
    	swpopup=1;                                                 //~vbi3I~
    	break;                                                     //~vbi3I~
    case 'X':                                                      //~vbi3I~
    	swexec=1;                                                  //~vbi3I~
    	break;                                                     //~vbi3I~
    case 'y':                                                      //~vbi3I~
    case 'Y':                                                      //~vbi3I~
    	swexec=1;                                                  //~vbi3I~
    	swsplit=1;                                                 //~vbi3I~
    	break;                                                     //~vbi3I~
    case 's':                                                      //~vbi3I~
    	swpopup=1;                                                 //~vbi3I~
    	break;                                                     //~vbi3I~
    case 'S':                                                      //~vbi3I~
    	break;                                                     //~vbi3I~
    case 't':                                                      //~vbi3I~
    case 'T':                                                      //~vbi3I~
    	swsplit=1;                                                 //~vbi3I~
    	break;                                                     //~vbi3I~
    default:                                                       //~vbi3I~
    	helpchlcmd();                                              //~vbi3I~
    	return 4;                                                  //~vbi3I~
    }                                                              //~vbi3I~
    if (swsplit)	//effect on other of split                     //~vbi3R~
    {                                                              //~vbi3I~
		pcw2=scrgetcw(-1);	//another split                        //~vbi3R~
        if (pcw2)                                                  //~vbi3I~
        	pcwtgt=pcw2;                                           //~vbi3I~
        else                                                       //~vbi3I~
            swsplit=0;                                             //~vbi3R~
    }                                                              //~vbi3I~
    if (!swsplit)	//effect on myselfother of split               //~vbi3I~
    {                                                              //~vbi3I~
    	if (swpopup)                                               //~vbi3I~
        {                                                          //~vbi3I~
			pcw2=UGETQNEXT(&Ppcw->UCWqelem);                       //~vbi3R~
        	if (pcw2)	//exist                                    //~vbi3R~
	        	pcwtgt=pcw2;                                       //~vbi3R~
            else                                                   //~vbi3I~
            	swpopup=0;                                         //~vbi3I~
        }                                                          //~vbi3I~
    }                                                              //~vbi3I~
    if (swsplit)                                                   //~vbi3I~
    {                                                              //~vbi3I~
        funcswap2(0,Ppcw); //swap without size change              //~vbi3I~
    }                                                              //~vbi3I~
    rc=0;                                                          //~vbi3I~
    if (swexec)                                                    //~vbi3R~
		rc=funccmdrepeatpsc(0,pcwtgt,psc);                         //~vbi3R~
    else                                                           //~vbi3I~
		rc=funcretrievepsc(0,pcwtgt,psc,plh);                      //~vbi3R~
    if (!rc)                                                       //~vbi3R~
    {                                                              //~vbi3I~
    	if (swpopup)                                               //~vbi3R~
			Gotherstatus|=GOTHERS_CHLPOPUP;//CommandHistoryList popup at return from funccall,UCWreason is not avail becaquse Ppcw may be freeed//~vbi3R~
    	if (swsplit)                                               //~vbi3I~
			Ppcw->UCWreason=UCWREASON_CHLSPLIT;                    //~vbi3I~
        else                                                       //~vbi3I~
        {                                                          //~vbi3I~
            csrloctogbl(Ppcw);                                     //~vbi3R~
    		Ppcw->UCWreason=UCWREASON_CHLNOSPLIT;  //call filecharcsr not to csrright at func_char//~vbi3R~
        }                                                          //~vbi3I~
    }                                                              //~vbi3I~
    return rc;                                                     //~vbi3R~
}//charfldeditchl                                                  //~vbi3I~
