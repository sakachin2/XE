//*CID://+vbdrR~:                                   update#=  279; //~vbdrR~
//*************************************************************
//*xecap.c                                                         //~v66jR~
//* cut and paste
//************************************************************* //~v069I~
//vbdr:171130 support label and lineno range option to SEL command //~vbdrI~
//vbd8:171120 (WXE)stdregion by PFK(F6) should disable PAste REP/INS//~vbd8I~
//vbd7:171119 "SEL all" support on file panel                      //~vbd7I~
//vbd4:171118 (BUG) invalid csr pos msg when capsave data(A+F9) even after block closed//~vbd4I~
//vbd2:171114 (Wxe)Add SelectAll menuitem                          //~vbd2I~
//vb84:170215 (BUG)line of status ULHFLINECMD on but not on UFHliencmd[], the line cmd input is ignored//~vb84I~
//vb4f:160801 (W32)embet by NOTLC for copyword uerrmsg CB:xxx      //~vb4fI~
//vb4a:160729 display C+W word copyed from utf8 on errmsg          //~vb4aI~
//vb49:160729 display copyword(Alt+W) for also editr panel if not ebc file//~vb49I~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vb25:160114 avoid overflow err for capmove when tgt=src range and tgt pos>=srcpos2//~vb25I~
//vb24:160111 (BUG)access Ssortplh1/2 may cause 0c4 after capreset(Gcappcw=0 but Gcapplh1 remains when fileclosed or line deleted)//~vb24I~
//vawJ:140623 (BUG)Ctl+W then F5 fail bey the reason of cursor position;move cursor to cmdline after Ctrl+W//~vawJI~
//vawk:140605 (BUG:LNX)additional to vawj;lc len shring but colpos remainsby setflddata;use dd2l like as other paste such as to cmdline//~vawkI~
//vawc:140601 support to paste to rename fld                       //~vawcI~
//vavk:140425 (BUG)cmd retrieve miss to recovery utf8 encoding     //~vavkI~
//vauG:140316 (BUG)rfind(f5) misses utf8 code when searchword on cmdline.//~vauGI~
//vauD:140315 (Win BUG)Ctl+W(copyword to cmdline) from dirlist;keep original u8/lc and ignore kbd mode.//~vauDI~//~vauGR~
//vauC:140315 (BUG of vau8)Ctl+W(copyword to cmdline) from utf8 file convert U8->LC depending kbd mode(A+u)//~vauCI~
//vaun:140313 C+W(copy word to cmdline) support for dir list       //~vaunI~
//vaub:140306 maintain ddfmt for pan fnmlist and util panel        //~vaubI~
//vau8:140303 use utf8 at copywordcmd_file source is utf8 file     //~vau8I~
//vau3:140227 copy to clipboard from dirlist;consider utf8name;copy slinkname if csr is on it.//~vau3R~
//vaj3:130722 (BUG:vagD)cut & paste append SO/SI from also non EBC file//~vaj3I~
//vagD:120918 (BUG)C&P savedata from EBC file may dismiss SO/SI    //~vagDI~
//vagC:120918 (BUG)Al+w(capsavedataword) dismiss ebchandle and accordingly paste dismiss dbcs mode//~vagCI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaar:120101 over vaap;not by padding but position for ddfmt also for locale dbcs(contains "d")//~vaarI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va7A:100829 (WXE:EBC)handle support for mouse cap                //~va7AI~
//va7z:100828 (WXE:BUG)windows native(created out of xe) cb miss translation(EBCS flag clear missing)//~va7zI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va5D:100520 chk kbdutf8 mode to paste cmdline not only for mouse paste but also kbd paste for EBD data//~va5DI~
//va5C:100520 Ctl+W (copy word to cmd) chk kbdutf8 mode for paste by u8/lc//~va5CI~
//va5B:100519 v70e(cb data set to win clipboard) missing for Alt+W operation//~va5BI~
//va5A:100519 Ctrl+W(copyword to cmdline);drop so/si               //~va5AI~
//va5y:100518 (WXE)Windows Clipboard translate text. It cause invalid sjis to u-30fb when CF_UNICODETEXT mode//~va5yI~
//            on the otherhand getclipboarddata with CF_TEXT option returns "?" for u2l trans err coed.//~va5yI~
//            so for EBCDIC code, SetClipboard by CF_UNICODETEXT after trans to ucs2 by bynary mode(1 byte to 1 ucs2)//~va5yI~
//va5j:100510 dispaly cmdline by dd fmt(more printable than locale code for Ctl+w(copy word to cmd lien).//~va5jI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            cap.c   :file utf8 mode is set from copy source      //~va20I~
//                    :copy to cmd line from dd fmt                //~va20I~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va0u:090909_(BUG)paste to cmdline abend(malloc len==0) if clipboard data start from EOL//~va0uI~
//va04:090606 expand cmdbuff to include edit cmd for the file with _max_path//~va04I~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          cmdline may be mixed of utf8 and locale code           //~va00I~
//          ::CB is always CPLC                                    //~va00I~
//          wxe/xxe clipboard data conversion                      //~va00I~
//v77F:080204 C+W copy to cmdline(No cmd verb)                     //~v77FI~
//v77E:080203 FW(C+"["/"]")/IW(A+"["|"]") cmd support              //~v77EI~
//v76j:070626 (WXEXXE)dnd by paste to utility panel. ins and rep only;std paste is disabled//~v76jI~
//v76b:070617 support paste to =2 panel                            //~v76bI~
//v74w:070222 (BUG of v74q)blockmode paste from saved data by block mode lose trailer space
//v74q:070218 (BUG)cob margin consideration for ETOL(by C+b)       //~v74qI~
//v74h:070216 (BUG)C&P paste to region fail by join fail for margined file.//~v74hI~
//            (because if target is region,once cut region(join top and last) then split)//~v74hI~
//            delay join till after insert source line)            //~v74hI~
//v74f:070215 (BUG)C&P ::cb oomproto attr was not set              //~v74fI~
//v74b:070213 (BUG)C&P wordcopy save undo data for ::cb;(savedata dose not save by v585)//~v74bI~
//v749:070212 (BUG)data by paste in cmdline is not displayed after v730//~v749I~
//v746:070212 (BUG)cap outof range chk should be done after filechktabdbcs(savedata is chk before so,set to ::cb  but not cleared)//~v70eI~
//v70e:060731 (WXEXXE)add to v69Z;copy to win clipboard thw data that is by pfkey operation//~v70eI~
//v70b:060731 (WXEXXE:BUG)copy of word on endofline insert eol at paste(include eol only when cursor is next line lino-fld)//~v70bI~
//v709:060730 (WXE:XXE)bug by v703;dbl click rejected by csr pos err//~v709I~
//v704:060726 (WXEXXE:BUG)stdrgn 1st line dose not include eol even when multiline std rgn//~v704I~
//v703:060726 (WXEXXE:BUG)if range is from cmd line to file area,pastev to file area.it should be cmd line//~v703I~
//v69Z:060726 (WXEXXE)sync C&P between PFkey and mouse operation.(update enable/disable menu by also Key operation)//~v69ZI~
//v697:060427 (BUG) if ::cb contain null by previous Cut&Paste operation. Next paste line splitted binary file display width//~v697I~
//v677:051226 cut & paste;accept block copy from region if saved   //~v677I~
//v675:051226 (BUG of v66j)abend by dup enq CB pcw when split scr,"e ::cb" at 2nd , paste in 1st,"e ::cb" at 1st;//~v675I~
//            for 66j(WXE), call pfhsrch                           //~v675I~
//v674:051226 cut & paste;margined file(COBOL etc) consideration(bell when copy by invalid spf line)//~v674I~
//v66y:051211 C&p allow X-line hdr line as 2nd point(range is up to before of the X-line hdr)//~v66yI~
//v66u:051121 cap:accept hdr/end line as region specification start/end point//~v66uI~
//v66j:051023 (WXE:BUG)C & P fail if ::CB is opened before first c&P copy because Gcapcbpcw is not set//~v66jI~
//v66h:051023 C & P;region mode by mouse; mouse drag->region mode,A+mouse drag->block mode//~v66hI~
//            delete Ctrl+V(preview) from menu and add to icon menu and popup menu//~v66hI~
//v66f:051021 support standard mode cut & paste,assign Ctrl+v for stream insert//~v66fI~
//                     None   OpenBlock  ClosedBlock   OpenRegion ClosedRegion//~v66fI~
//            C+v    RgnIns   NoBlockErr BlockClearRep OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Ins  BlockIns NoBlockErr GetBlock+Ins  OpenRgnErr RgnModeErr//~v66fI~
//            A+Rep  BlockRep NoBlockErr GetBlock+Rep  OpenRgnErr RgnModeErr//~v66fI~
//v66f:051021 (BUG)A+F9 abend when A+F7 on same excludeline and pos1>pos2//~v66fI~
//v66e:051020 support standard mode cut & paste;                   //~v66eI~
//            A+F6/A+v:range specification, A+F9:copy, A+Ins:paste Ins, A+F8:paste Rep, C+v:paste Del then Ins//~v66eR~
//            Del/BackSpace:delete range, A+Del:del+copy to clipboard//~v66eI~
//v641:050614 (LNX)xxe support                                     //~v641I~
//v585:040823 cap performance up;skip undo data save when clipboard repl//~v585I~
//v584:040823 cap option not to copy to ::cb when cap-delete for performance up for large file//~v584I~
//v54h:040105 compile err(unsigned char set to -1)                 //~v54hI~
//v53L:031029 (BUG)A+o result msg correct,上書き-->空白上書き      //~v53LI~
//v53w:031005 (BUG)capreset should clear old pos to redraw next A+F7.//~v53wI~
//v53c:030921 alt+w for C&P copy word                              //~v53cI~
//v50K:030203 (WXE) word cut func                                  //~v50KI~
//v50t:030112 (BUG)mac eolid=4 but eollen=1,offset calc miss       //~v50tI~
//v502:021005 (BUG)caste to cmd line abend when overflow           //~v502I~
//v500:020929 (WXE)scr cut/paste                                   //~v500I~
//v418:010729 when line mode cap,set spf flag to CB file to drop number fld at lcmdcopy//~v418I~
//v417:010729 allow lineno fld when not protected for spf file     //~v417I~
//v158:000404 (BUG)when cap boundary plh is freed by undo which is inserted line,//~v158I~
//            Ssortplh is not now on plh chain.It cause abend at capreset to reset reverse.//~v158I~
//v155:000318 numeric calc func(double A+F7 cause "tc =")          //~v155R~
//v11N:990829 COL cmd support                                      //~v11NI~
//v10M:990424 support cap to cmdline                               //~v10MI~
//v0ih:980621 pfk cmd support(input protect)                       //~v0ihI~
//v0ia:980530 add APPend cmd                                       //~v0iaI~
//v0i8:980522 move csrposerr to xeerr                              //~v0i8I~
//v0he:980130 cap save operation for paste after end/cancel(Alt+f9)//~v0heI~
//v0eK:970927 margin and cap                                       //~v0eKI~
//            for SPFERR/SPFOK file;oom update prohibit            //~v0eKI~
//            for mergined file;prohibit over mergin line.         //~v0eKI~
//                             ;avail on oom                       //~v0eKI~
//v0ec:970915 cap same prohibit for mergined file as spf file.     //~v0ecI~
//v0dn:970907 source of cap not avail from out of mergin for also spferr file//~v0dnI~
//v0dc:970831 for spf;reject capblock is out of mergin             //~v0dcI~
//v0bg:970727 mergin err notify to cap to protect err msg override //~v0bgI~
//v0bf:970726 mergin chk before capmove(avoid del then return)     //~v0bfI~
//v0av:970720-fixed lrecl support                                  //~v0avI~
//           -expand pre chk(split file2 to file6)                 //~v0avI~
//v098:970413:(BUG)avail update on browse line(but its is not saved)//~v098I~
//            by Shift+Ins/Del/F10(rep)/Enter(Split).              //~v098I~
//            (move errmsg to xeerr.c from xecap.c)                //~v098I~
//v095:970405:DPMI version                                         //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//v08l:961123:edit/browse line range parameter                     //~v08lI~
//v08f:961106:performance up                                       //~v08fI~
//			  block draw only when block is not closed             //~v08fI~
//v085:961024:W95 VC                                               //~v085I~
//v06R:960427:(BUG)cut & paste block key on lineno fld dose not mean//~v06RI~
//            line mode if UFCleft!=0                              //~v06RI~
//v06E:960415:abondan line insert by additional SHIFT key          //~v06EI~
//v06t:960406:cmd so screen:append cmd result                         //~v06tI~
//v06l:960317:rearange key for no num option                    //~v06lI~
//           -shift key to insert line for insert/copy/move/null move//~v06lR~
//           -change copy/move/null move is insert mode only,   //~v06lI~
//			  so join alt+c	to alt+Ins                          //~v06lI~
//           -COPY/MOVE destination not by alt+a but by any line insert cmd//~v06lI~
//           -REPL/CREATE avail from any line mode              //~v06lI~
//v06k:960316:(BUG)line not cleared when line mode by alt+End(pos1=pos2=0)//~v06kI~
//            err when block mode and pos1=pos2                 //~v06kI~
//v06j:960316:(BUG)line mode move(alt+m) abend(Gcappcw cleared at lcmddel)//~v06jI~
//v06i:960310:support REPl/CREate file by ALt+l for no line-no display mode//~v06iI~
//v06h:960310:support Copy/Move file by ALt+a                   //~v06hI~
//v06g:960310:Alt+c for copy ins/rep by Ins mode                //~v06gI~
//v06f:960309:change paste key Alt+o-->Alt+p,add Alt+o as override//~v06eI~
//            funct.c                                           //~v06eI~
//v06e:960309:for num off case,                                 //~v06eR~
//            add line mark(Alt+l) and Alt+a(copy after)        //~v06eI~
//            block mode also when col=1                        //~v06eI~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//v057:951015:(BUG)same as v055 for capdel del CR(line concat)  //~v057I~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//*950603 cb chk before save                                    //~5603I~
//*950527 each file upctr when move over split                  //~5527I~
//*950521 move with clear function                              //~5521I~
//*950520 move range (source and target) overrap case           //~5520I~
//*950513 move by copy and del not but del(because offset chang) and copy//~5520R~
//*       block clear function                                  //~5513I~
//*950503 bel when out of range only when cut                   //~5513I~
//*950502 bug plh2 is end-of-line/excluded when cut             //~5502I~
//*       block move function add                               //~5502I~
//*950425 bug when f7 and f7 then alt+del,block not copyed      //~5425R~
//*950424 copy after when csr is on lineno fld                  //~5425I~
//*950422 hilighten copyed block                                //~5424I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
	#ifdef W32                                                     //~v085I~
//  	#include <windows.h>                                       //~v085I~
	#else                                                          //~v085I~
	#define INCL_BASE
	#include <os2.h>
	#endif                                                         //~v085I~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318R~
#include <ualloc.h>                                             //~v04dI~
#include <ukbd.h>                                               //~v06lI~
#include <utrace.h>                                                //~v66hI~
#include <ustring.h>                                               //~v77FI~
#include <uparse.h>                                                //~vbdrI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include <utf.h>                                               //~va00I~
#endif                                                             //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
	#include <utf22.h>                                             //~va20I~
#endif                                                             //~va20I~
#include <ucvebc.h>                                                //~vagDI~
#include <ufilew.h>                                                //~vauGI~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"                                                //~v500I~
#include "xefile.h"
#include "xefile13.h"                                              //~v585I~
#include "xefile2.h"                                               //~v0avI~
#include "xefile22.h"  	//filegetword                              //~v53cI~
#include "xefile6.h"                                               //~v0avR~
#include "xedir2.h"     //dirgetword                               //~v53cI~
#include "xedir3.h"                                                //~vawcI~
#include "xefcmd3.h"     //fcmdisrtline                            //~v53cI~
#include "xefcmd4.h"     //fcmdgetlabparm                          //~vbdrI~
#include "xefunc.h"
#include "xefunc2.h"                                               //~v500I~
#include "xechar.h"
#include "xechar12.h"                                              //~v10MI~
#include "xelcmd.h"
#include "xelcmd2.h"
#include "xelcmd3.h"
#include "xefsub.h"                                             //~5318I~
#include "xefcmd.h"                                             //~v06iI~
#include "xeerr.h"                                                 //~v098I~
#include "xecap.h"                                                    //~v06tI~
#include "xecap2.h"                                                //~v66fI~
#include "xepan.h"                                                 //~v10MI~
#include "xepan2.h"                                                //~v76jI~
#include "xepan22.h"   	//pan300getword                            //~v53cI~
#include "xesub.h"                                                 //~v10MI~
#include "xesub2.h"                                                //~va1cR~
#include "xecalc2.h"                                               //~v155I~
#ifdef WXE                                                         //~v500I~
	#include "wxexei.h"                                            //~v500I~
#endif                                                             //~v500I~
#ifdef XXE                                                         //~v641I~
	#include "xxexei.h"                                            //~v641I~
#endif                                                             //~v641I~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xeopt.h"                                             //~va00R~
	#include "xeutf.h"                                             //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
	#include "xeutf2.h"                                            //~va20I~
#endif                                                             //~va20I~
#endif                                                             //~va00I~
#include "xeebc.h"                                                 //~va50I~
#include "xecsr.h"                                                 //~vawJI~
//*******************************************************
int capmove(PUCLIENTWE Ppcw,int Pclearopt);                     //~5521I~
int capmovesub(PUCLIENTWE Ppcw,int Pinsopt,PUFILEH Ppfh,int Pclearopt);//~5521I~
int capmoveovchk(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Pinsopt,int Pclearopt);//~v0bfR~
int capcopy(PUCLIENTWE Ppcw,int Pinsopt);                       //~5520R~
int capfcmdi2(PUCLIENTWE Ppcw,char Prepcre,int Popdsw);         //~v06lR~
int capcopysub(PUCLIENTWE Ppcw,int Pinsopt);                    //~5520I~
int capdel(PUCLIENTWE Ppcw,int Pclearopt);                      //~5513I~
int capcut(PUCLIENTWE Ppcw,int Povmovechkopt);                  //~5521I~
int capclear(PUCLIENTWE Ppcw);                                  //~5513I~
//int capsavedata(PUCLIENTWE Ppcw);                                //~v500R~
int capsavepoint(PUCLIENTWE Ppcw,int Pendsw);
int capchkboxwidth(PUFILEH pfh);                                   //~v0dcR~
void  capsortpoint(void);                                       //~5226R~
//PUFILEH capgetpfh(PUCLIENTWE Ppcw);                              //~v66fR~
PUFILEH capgetpfh(int Popt,PUCLIENTWE Ppcw);                       //~va7AI~
#define CAPGPFO_SAVE    0x01   //old data is not required because immediately deleted at data save operation//~va7AI~
//PUFILEH capgetdata(PUCLIENTWE Ppcw,PULINEH *Ppplh1,PULINEH *Ppplh2);//~v66fR~
PULINEH capgetcsrplh(PUCLIENTWE Ppcw);                          //~v06lI~
//int capcsrposerr(void);                                          //~v0i8R~
//int capbrowseerr(void);                                          //~v098R~
int capcberr(void);                                             //~5603I~
int capchkmergin(PUFILEH Ppfh,int Ppos1,int Ppos2,int Popt);       //~v0eKI~
void capmsgsaved(void);                                            //~v0heI~
int captocmdline(PUCLIENTWE Ppcw,int Pinsopt);                     //~v10MI~
//int captofld(PUCLIENTWE Ppcw,int Pinsopt,UFLDE *Ppflde);         //~v76bR~
int captofld(PUCLIENTWE Ppcw,int Pinsopt,UFLDE *Ppflde,int Pfldno);//~v76bR~
int cap_calcrev(void);                                             //~v155I~
#ifdef UTF8UCS2                                                    //~va20I~
	int capsavedataword(int Popt,PUCLIENTWE Ppcw,char *Pdata,char *Pdbcs,int Plen);//~va20I~
	#define CSDWO_CPU8      0x01       //source file is utf8 file(dd fmt)//~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	#define CSDWO_CPEB      0x02       //source file is ebc        //~va50R~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
	#define CSDWO_CPU8WORD  0x04       //utf8 string without dbcstbl//~vau3R~
#else                                                              //~va20I~
int capsavedataword(PUCLIENTWE Ppcw,char *Pword,int Plen);         //~v53cI~
#endif                                                             //~va20I~
int captopanfld(PUCLIENTWE Ppcw,int Pinsopt);                      //~v76bI~
int func_copywordcmd_dir(PUCLIENTWE Ppcw);                         //~vaunI~
int capchkcsrpos(int Prow,int Pcol,PUCLIENTWE *Pppcw);             //~vbd7I~
#ifdef WXEXXE                                                      //~vbd2I~//~vbd7R~
	int capselectallfile(PUCLIENTWE Ppcw);                         //~vbd2I~
//	int capsavepointselectall(PUCLIENTWE Ppcw,int Pendsw);         //~vbd2I~//~vbd7R~
//  void capsortpointselectall(void);                              //~vbd2I~//~vbd7R~
#endif                                                             //~vbd2I~
//	int capsavepointselectall(PUCLIENTWE Ppcw,int Pendsw);         //~vbd7I~//~vbdrR~
	int capsavepointselectall(PUCLIENTWE Ppcw,int Pendsw,PULINEH Pplh1,PULINEH Pplh2);//~vbdrI~
    void capsortpointselectall(int PswBlockmode);                  //~vbd7R~
//  int capselectallfilecmdstd(PUCLIENTWE Ppcw);                   //~vbd7I~//~vbdrR~
int capselectallfilecmdstd(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2);//~vbdrI~
//  int capselectallfilecmdblock(PUCLIENTWE Ppcw,int Pcol1,int Pcol2);//~vbd7I~//~vbdrR~
int capselectallfilecmdblock(PUCLIENTWE Ppcw,int Pcol1,int Pcol2,PULINEH Pplh1,PULINEH Pplh2);//~vbdrI~
//	int capselectallfilecmdblocksub(PUCLIENTWE Ppcw,int Pcol1,int Pcol2);//~vbd7I~//~vbdrR~
int capselectallfilecmdblocksub(PUCLIENTWE Ppcw,int Pcol1,int Pcol2,PULINEH Pplh,PULINEH Pplh2);//~vbdrI~
//int capsavepointselectallblock(PUCLIENTWE Ppcw,int Pendsw,int Pcol1,int Pcol2);//~vbd7I~//~vbdrR~
int capsavepointselectallblock(PUCLIENTWE Ppcw,int Pendsw,int Pcol1,int Pcol2,PULINEH Pplh1,PULINEH Pplh2);//~vbdrI~
//*******************************************************
static char Sblockstat=0;	//block operation statistic            //~v54hR~
//#define SBLOCKCLOSED            0x01    //start and block closed //~v66fR~
//#define SBLOCKMODE          0x02    //block mode(not line mode)  //~v66fR~
//#define SBLOCKSAVED        0x04    //copyed to clip boad         //~v66fR~
static char Sblockstat2;	//block operation statistic               //~v06eI~
//#define SBLOCK2LINEMARK     0x01    //line mark operation flag   //~v66fR~
//#define SBLOCK2SAVEDATA     0x02    //savedata  operation flag   //~v66fR~
//#define SBLOCK2WORDCOPY     0x04    //word copy mode             //~v66fR~
static char Spendfcmd;		//cmd pending sw		            //~v06hI~
static char Sblockdraw=0;	//re-draw flag                         //~v08fI~
static int Scapposx1;		//fixed block start
static int Scapposx2;		//fixed block end
static int Ssortposx1=0;		//sorted start record  offset      //~v54hR~
static int Ssortposx2=0;		//sorted end record  offset        //~v54hR~
static PULINEH Ssortplh1=0;	//sorted top line                      //~v54hR~
static PULINEH Ssortplh2=0;	//sorted end line                      //~v54hR~
static 	UCHAR Scbfnm[]=CLIPBOARDID;
                                                                   //~v155I~
static char Scalcblockstat;	//block operation statistic for calc   //~v155I~
static int Scalcposx1;		//sorted start record  offset          //~v155I~
static int Scalcposx2;		//sorted end record  offset            //~v155I~
static int Soldx=-1,Soldy=-1;                                      //~v53wI~
//static char Soldrc=-1;                                           //~v54hR~
static char Soldrc=0;                                              //~v54hI~
//*******************************************************
//!capreset
//* reset block mode
//* parm1:1:reset plh,0:no reset plh,2:reset plh but keep calcpcw  //~v155R~
//* retrn:none
//*******************************************************
void capreset(int Popt)
{
    PULINEH plh;
//*****************
	if (!Gcappcw)
    {                                                              //~v69ZI~
#ifdef WXEXXE                                                      //~v69ZM~
	    wxemouse_capi(WXEM_RESET,0);     //reset mouse status;call for also copypan reset//~v69ZI~
#endif                                                             //~v69ZM~
		return;
    }                                                              //~v69ZI~
 	capsortpoint();	//set Ssortplh                              //~5226I~
	if (Popt)
//    	for(plh=Ssortplh1;;plh=UGETQNEXT(plh))                     //~v158R~
    	for(plh=Ssortplh1;plh;plh=UGETQNEXT(plh))//confirm for Sortplh is invalidated case//~v158R~
  	 	{
			if (UCBITCHK(plh->ULHflag,ULHFBLOCK))	//block reversed
			{
				UCBITOFF(plh->ULHflag,ULHFBLOCK);	//block reversed
				UCBITON(plh->ULHflag,ULHFDRAW);	//block reversed
        	}
    		if (plh==Ssortplh2)                                 //~5226R~
				break;
    	}
	Gcappcw=0;
    Gcapplh1=Ssortplh1=0;   //avoid access evenif Gcappcw=0        //~vb24I~
    Gcapplh2=Ssortplh2=0;                                          //~vb24I~
  	if (Popt!=2)                                                   //~v155I~
		Gcalcpcw=0;                                                //~v158R~
    else                                                           //~v155I~
        if (Gcalcpcw)                                              //~v158R~
            cap_calcrev();                                         //~v155I~
	Sblockstat2=0;	//line mark mode etc                              //~v06eI~
	Soldx=-1;Soldy=-1;                                             //~v53wI~
//  Soldrc=-1;                                                     //~v54hR~
    Soldrc=0;                                                      //~v54hI~
#ifdef WXEXXE                                                      //~v69ZI~
	wxemouse_capi(WXEM_RESET,0);     //after status update,reset mouse status;call for also copypan reset//~v69ZI~
#endif                                                             //~v69ZI~
	return;
}//capreset

//*******************************************************          //~v155I~
//!capresetcalc                                                    //~v155I~
//* reset block bu file close                                      //~v155I~
//* parm1:pcw to be closed                                         //~v155I~
//* retrn:none                                                     //~v155I~
//*******************************************************          //~v155I~
void capresetcalc(PUCLIENTWE Ppcw)                                 //~v155I~
{                                                                  //~v155I~
//*****************                                                //~v155I~
	if (Ppcw!=Gcalcpcw)                                            //~v158R~
		return;                                                    //~v155I~
	Gcalcpcw=0;                                                    //~v158R~
	return;                                                        //~v155I~
}//capresetcalc                                                    //~v155I~
                                                                   //~v155I~
//*******************************************************
//!capsavecsrpos
//* save temporary end point by csr pos for caplinechk by file_draw
//* parm1:pcw
//* retrn:none
//*******************************************************
void capsavecsrpos(PUCLIENTWE Ppcw)
{
//static int Soldx,Soldy;                                          //~v53wR~
//static char Soldrc;                                              //~v53wR~
//*******************
	if (!UCBITCHK(Sblockstat,SBLOCKCLOSED))	//block not closed  //~5502R~
    {                                                              //~v08fI~
//    	if (capsavepoint(Ppcw,1))//save end point                  //~v66eR~
      	if (capsavepoint(Ppcw,3))//save end point temporary        //~v66jR~
      	{                        //csr err                         //~v0dnI~
        	if (!Soldrc)         //first time                      //~v0dnI~
        	{                                                      //~v0dnI~
        		Soldrc=1;                                          //~v0dnI~
	       	 	ubell();                                           //~v0dnR~
			}                                                      //~v0dnI~
      	}                                                          //~v0dnI~
      	else                                                       //~v0dnI~
        	Soldrc=0;                                              //~v0dnI~
	  if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//regin mode   //~v66eI~
      {                                                            //~v66eI~
		if (Soldy!=Ppcw->UCWrcsry)  //chk y at first               //~v66eI~
        	Sblockdraw=1;	        //y changed draw all           //~v66eI~
		else                                                       //~v66eI~
			if (Soldx!=Ppcw->UCWrcsrx)                             //~v66eI~
	        	Sblockdraw=2;	    //x changed,draw the line only //~v66eI~
			else                                                   //~v66eI~
	        	Sblockdraw=0;		//no need draw                 //~v66eI~
      }                                                            //~v66eI~
      else                                                         //~v66eI~
      {                                                            //~v66eI~
		if (Soldx!=Ppcw->UCWrcsrx)                                 //~v08fI~
        	Sblockdraw=2;	        //draw all                     //~v08fI~
		else                                                       //~v08fI~
			if (Soldy!=Ppcw->UCWrcsry)                             //~v08fI~
	        	Sblockdraw=1;	    //redraw new block only        //~v08fI~
			else                                                   //~v08fI~
	        	Sblockdraw=0;		//no need draw                 //~v08fI~
      }                                                            //~v66eI~
    }                                                              //~v08fI~
    else                                                           //~v08fI~
    {                                                              //~v53cI~
	  if (UCBITCHK(Sblockstat2,SBLOCK2WORDCOPY))                   //~v53cI~
      {                                                            //~v53cI~
	    UCBITOFF(Sblockstat2,SBLOCK2WORDCOPY);                     //~v53cI~
    	Sblockdraw=2;		//x changed                            //~v53cI~
      }                                                            //~v53cI~
      else                                                         //~v53cI~
    	Sblockdraw=0;		//no need draw                         //~v08fI~
    }                                                              //~v53cI~
	Soldy=Ppcw->UCWrcsry;                                          //~v08fI~
	Soldx=Ppcw->UCWrcsrx;                                          //~v08fI~
}//capsavecsrpoint

//*******************************************************
//!caplinechk
//* set flag to draw block reverse
//* parm1:pcw
//* parm2:line plh
//* retrn:none
//*******************************************************
void caplinechk(PUCLIENTWE Ppcw,PULINEH Pplh)
{
//*******************
	if (lineseqchk(Ssortplh1,Pplh)<=0                           //~5226R~
    &&  lineseqchk(Pplh,Ssortplh2)<=0)	//between start and end //~5226R~
	  if (!Sblockdraw)			//block closed,no csr moved        //~v08fR~
		UCBITON(Pplh->ULHflag,ULHFBLOCK);                          //~v08fI~
      else                                                         //~v08fI~
	   if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//regin mode   //~v66eR~
       {                                                           //~v66eI~
			if (Sblockdraw==1)			//csr y changed            //~v66eI~
				UCBITON(Pplh->ULHflag,ULHFDRAW|ULHFBLOCK);	//draw all line//~v66eI~
        	else						//csr x changed            //~v66eI~
        	{                                                      //~v66eI~
				if (Pplh==Ssortplh1 || Pplh==Ssortplh2)            //~v66eR~
        			UCBITON(Pplh->ULHflag,ULHFDRAW|ULHFBLOCK);     //~v66eI~
			}                                                      //~v66eI~
       }                                                           //~v66eI~
       else		//block/line mode                                  //~v66eI~
       {                                                           //~v66eI~
		if (Sblockdraw==1)			//csr y changed                //~v08fI~
        {                                                          //~v08fI~
			if (!UCBITCHK(Pplh->ULHflag,ULHFBLOCK))	//new member   //~v08fI~
        		UCBITON(Pplh->ULHflag,ULHFDRAW|ULHFBLOCK);         //~v08fI~
		}                                                          //~v08fI~
        else						//csr x changed                //~v08fI~
		UCBITON(Pplh->ULHflag,ULHFDRAW|ULHFBLOCK);
       }                                                           //~v66eI~
	else
		if (UCBITCHK(Pplh->ULHflag,ULHFBLOCK))
		{
			UCBITOFF(Pplh->ULHflag,ULHFBLOCK);
			UCBITON(Pplh->ULHflag,ULHFDRAW);
		}
	return;
}//caplinechk

//*******************************************************
//!capblockchk
//* chk block is in the current screen to draw cell
//* parm1:pcw
//* parm2:plh
//* parm3:output offset pos in the client scrren(contain lineno fld)
//* retrn:display length
//*******************************************************
int capblockchk(PUCLIENTWE Ppcw,PULINEH Pplh,int *Ppoffs)
{
	PUFILEC pfc;
	int offs1,offs2;
    int linenosz;                                               //~v069I~
//*******************
	linenosz=Ppcw->UCWlinenosz;                                 //~v069I~
	pfc=Ppcw->UCWpfc;
	if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//regin mode       //~v66eR~
    {                                                              //~v66eI~
		if (Pplh==Ssortplh1)	//region top line                  //~v66eI~
        {                                                          //~v66eI~
            if (Pplh==Ssortplh2)                                   //~v66eI~
            {                                                      //~v66eI~
				offs1=Ssortposx1-pfc->UFCleft+linenosz;            //~v66eI~
				offs2=Ssortposx2-pfc->UFCleft+linenosz;            //~v66eI~
            }                                                      //~v66eI~
            else                                                   //~v66eI~
            {                                                      //~v66eI~
				offs1=Ssortposx1-pfc->UFCleft+linenosz;            //~v66eR~
//				offs2=Pplh->ULHlen-pfc->UFCleft+linenosz;          //~v704R~
  				offs2=Pplh->ULHlen-pfc->UFCleft+linenosz+1;//include eol//~v704I~
                if (offs2<=offs1) //out of line                    //~v66fI~
                    offs2=offs1+1;                                 //~v66fI~
            }                                                      //~v66eI~
        }                                                          //~v66eI~
        else                                                       //~v66eI~
		if (Pplh==Ssortplh2)	//region top line                  //~v66eI~
        {                                                          //~v66eI~
			offs1=linenosz;                                        //~v66eI~
			offs2=Ssortposx2-pfc->UFCleft+linenosz;                //~v66eI~
        }                                                          //~v66eI~
        else                                                       //~v66eI~
        {                                                          //~v66eI~
			offs1=linenosz;                                        //~v66eI~
			offs2=Pplh->ULHlen-pfc->UFCleft+linenosz+1;	//include eol//~v66fR~
        }                                                          //~v66eI~
    }                                                              //~v66eI~
    else                                                           //~v66eI~
	if (UCBITCHK(Sblockstat,SBLOCKMODE))
    {
		offs1=Ssortposx1-pfc->UFCleft+linenosz;                 //~v069R~
		offs2=Ssortposx2-pfc->UFCleft+linenosz;                 //~v069R~
    }
    else	//line mode
    {
		offs1=linenosz;                                         //~v069R~
		offs2=Pplh->ULHlen-pfc->UFCleft+linenosz;               //~v069R~
    }
	if (offs1>=Ppcw->UCWwidth || offs2<linenosz) //out of screen//~v069R~
		return 0;
	if (offs1<linenosz)                                         //~v069R~
		offs1=linenosz;                                         //~v069R~
	if (offs2>Ppcw->UCWwidth)
		offs2=Ppcw->UCWwidth;
	*Ppoffs=offs1;
	return offs2-offs1;
}//capblockchk
                                                                   //~v0heI~
//*******************************************************          //~v0heI~
//!func_capsave_file                                               //~v0heI~
//* save cap data to CB                                            //~v0heI~
//* parm1:pcw                                                      //~v0heI~
//* retrn:rc                                                       //~v0heI~
//*******************************************************          //~v0heI~
int func_copytocb_file(PUCLIENTWE Ppcw)                            //~v0heR~
{                                                                  //~v0heI~
	int rc;                                                        //~v0heI~
//*******************                                              //~v0heI~
	UCBITON(Sblockstat2,SBLOCK2SAVEDATA);	//parm to func_block_file//~v0heI~
	if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//start stdregin mode//~v66eR~
    {                                                              //~v66hI~
	    rc=func_stdcpregion_file(Ppcw);                            //~v66eR~
//UTRACEP("func_stdcpregion_fire rc=%d\n",rc);                     //~v66hR~
    }                                                              //~v66hI~
    else                                                           //~v66eI~
    rc=func_block_file(Ppcw);                                      //~v0heI~
	UCBITOFF(Sblockstat2,SBLOCK2SAVEDATA);	//reset                //~v0heI~
    return rc;                                                     //~v0heI~
}//func_copytocb_file                                              //~v0heR~

//*******************************************************             //~v06eI~
//!func_lmark_file
//* line mark  start/stop                                             //~v06eI~
//* parm1:pcw                                                         //~v06eI~
//* retrn:rc                                                          //~v06eI~
//*******************************************************             //~v06eI~
int func_lmark_file(PUCLIENTWE Ppcw)                                  //~v06eR~
{                                                                     //~v06eI~
	int rc;                                                           //~v06eI~
//*******************                                                 //~v06eI~
	UCBITON(Sblockstat2,SBLOCK2LINEMARK);	//parm to capsavepoint    //~v06eR~
#ifdef WXEXXE                                                      //~vbd2I~
  if (Gwxestat & GWXES_SELECTALL)		//flag for xecap,req callback//~vbd2I~
  {                                                                //~vbd2I~
	rc=capselectallfile(Ppcw);                                     //~vbd2I~
	UCBITOFF(Sblockstat2,SBLOCK2LINEMARK);	//parm to capsavepoint //~vbd2I~
  }                                                                //~vbd2I~
  else                                                             //~vbd2I~
  {                                                                //~vbd2I~
#endif                                                             //~vbd2I~
    rc=func_block_file(Ppcw);                                         //~v06eR~
    if (rc)                                                           //~v06eI~
		UCBITOFF(Sblockstat2,SBLOCK2LINEMARK);	//parm to capsavepoint//~v06eR~
#ifdef WXEXXE                                                      //~vbd8I~
  }                                                                //~vbd2I~
#endif                                                             //~vbd2I~
    return rc;                                                        //~v06eI~
}//func_lmark_file                                                    //~v06eR~
                                                                      //~v06eI~
//*******************************************************          //~v66eI~
//!func_stdcpregion_file                                           //~v66eI~
//* line mark  start/stop                                          //~v66eI~
//* parm1:pcw                                                      //~v66eI~
//* retrn:rc                                                       //~v66eI~
//*******************************************************          //~v66eI~
int func_stdcpregion_file(PUCLIENTWE Ppcw)                         //~v66eI~
{                                                                  //~v66eI~
	PUFILEC pfc;                                                   //~v66eI~
	PUFILEH pfh;                                                   //~v66eI~
//*******************                                              //~v66eI~
	if (!CSRONFILELINE(Ppcw))				//out of screen        //~v66eI~
    {                                                              //~vbd8I~
	  if (UCBITCHK(Sblockstat2,SBLOCK2SAVEDATA) && UCBITCHK(Sblockstat,SBLOCKCLOSED))	//savedata req and block closed//~vbd4I~
      	;                                                          //~vbd4I~
      else                                                         //~vbd4I~
  		return errcsrpos();                                        //~v66eI~
    }                                                              //~vbd8I~
	pfc=Ppcw->UCWpfc;                                              //~v66eI~
	pfh=pfc->UFCpfh;                                               //~v66eI~
	if (pfh->UFHtype==UFHTCLIPBOARD)                               //~v66eI~
    	return capcberr();                                         //~v66eI~
                                                                   //~v66eI~
	if (Ppcw==Gcappcw                                              //~v66eI~
	&&  !UCBITCHK(Sblockstat,SBLOCKCLOSED))	//not closed           //~v66eI~
	{                                                              //~v66eI~
		if (!UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//not started by "start stdregin"//~v66eI~
        {                                                          //~v66eI~
        	uerrmsg("Previously started Block mode",               //~v66eI~
            		"ブロックモード中");                           //~v66eI~
			return 4;                                              //~v66eI~
        }                                                          //~v66eI~
		if (capsavepoint(Ppcw,1))                                  //~v66eI~
        {                                                          //~v66hI~
//UTRACEP("capsave point err  \n");                                //~v66hR~
			return 4;                                              //~v66eI~
        }                                                          //~v66hI~
		if (capchkboxwidth(pfh))	//width 0                      //~v66eI~
			return 4;                                              //~v66eI~
		UCBITON(Sblockstat,SBLOCKCLOSED);	//block closed         //~v66eI~
		UCBITOFF(Sblockstat,SBLOCKSAVED);	//block closed         //~v66eI~
	  if (UCBITCHK(Sblockstat2,SBLOCK2SAVEDATA))	//save data req//~v66eI~
      {                                                            //~v66eI~
      	if (capsavedata(Ppcw))                                     //~v66eI~
        {                                                          //~v66hI~
//UTRACEP("capdata  err  \n");                                     //~v66hR~
        	return 4;                                              //~v66eI~
        }                                                          //~v66hI~
		capmsgsaved();                                             //~v66eI~
      }                                                            //~v66eI~
      else                                                         //~v66eI~
      {                                                            //~v66eI~
#ifdef WXEXXE                                                      //~v69ZI~
    	wxemouse_capi(WXEM_SETRGN,0);     //enable copy menu       //~v69ZI~
#endif                                                             //~v69ZI~
		uerrmsg("Region Defined",                                  //~v66fR~
				"領域指定完了");                                   //~v66eI~
      }                                                            //~v66eI~
    }                                                              //~v66eI~
    else                                                           //~v66eI~
	{                                                              //~v66eI~
	  if (UCBITCHK(Sblockstat2,SBLOCK2SAVEDATA))	//save data req//~v66eI~
      {                                                            //~v66eI~
		if (Ppcw==Gcappcw)	//started                              //~v66eI~
        {                                                          //~v66eI~
	      	if (capsavedata(Ppcw))                                 //~v66eI~
	        	return 4;                                          //~v66eI~
			capmsgsaved();                                         //~v66eI~
		}                                                          //~v66eI~
        else                                                       //~v66eI~
            return capnoblockerr();                                //~v66eI~
      }//savedata                                                  //~v66eI~
      else//not save data                                          //~v66eI~
      {                                                            //~v66eI~
		if (Gcappcw)                                               //~v66eI~
        {                                                          //~v66eI~
            capreset(1);	//keep calc pcw                        //~v66jR~
		   	uerrmsg("Regin mode re-start",                         //~v66fR~
					"領域指定再開始");                             //~v66eI~
        }                                                          //~v66eI~
		else                                                       //~v66eI~
			uerrmsg("Region mode start",                           //~v66fR~
					"領域指定開始");                               //~v66eI~
		UCBITON(Sblockstat2,SBLOCK2STDREGION);	//not started by "start stdregin"//~v66eI~
		if (capsavepoint(Ppcw,0)) //startpoint                     //~v66eI~
			return 4;                                              //~v66eI~
      }//not savedata                                              //~v66eI~
	}                                                              //~v66eI~
	return 0;                                                      //~v66eI~
}//func_stdcpregion_file                                           //~v66eI~
//*******************************************************
//!func_block_file
//* block mode start/stop
//* parm1:pcw
//* retrn:rc
//*******************************************************
int func_block_file(PUCLIENTWE Ppcw)
{
	PUFILEC pfc;
	PUFILEH pfh;
static int Skbdinpctr;                                             //~v155I~
//*******************
	if (!CSRONFILELINE(Ppcw))				//out of screen
    {                                                              //~vbd8I~
//		return capcsrposerr();                                     //~v0i8R~
	  if (UCBITCHK(Sblockstat2,SBLOCK2SAVEDATA) && UCBITCHK(Sblockstat,SBLOCKCLOSED))	//savedata req and block closed//~vbd4I~
      	;                                                          //~vbd4I~
      else                                                         //~vbd4I~
  		return errcsrpos();                                        //~v0i8I~
    }                                                              //~vbd8I~
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;
	if (pfh->UFHtype==UFHTCLIPBOARD)
    	return capcberr();                                      //~5603I~
                                                                //~5603I~
	if (Ppcw==Gcappcw
	&&  !UCBITCHK(Sblockstat,SBLOCKCLOSED))	//not closed        //~5502R~
	{
		if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//not started by "start stdregin"//~v66eI~
        {                                                          //~v66eI~
        	uerrmsg("Previously started Region mode",              //~v66eI~
            		"領域モード中");                               //~v66eI~
			return 4;                                              //~v66eI~
        }                                                          //~v66eI~
		if (capsavepoint(Ppcw,1))                               //~v06kM~
			return 4;                                           //~v06kM~
		if (capchkboxwidth(pfh))	//width 0                      //~v0dcR~
			return 4;                                           //~v06kI~
                                                                //~v06kI~
		UCBITON(Sblockstat,SBLOCKCLOSED);	//block closed      //~5502R~
		UCBITOFF(Sblockstat,SBLOCKSAVED);	//block closed      //~5502R~
		UCBITOFF(Sblockstat2,SBLOCK2LINEMARK);	//block closed  //~v06lI~
	  if (UCBITCHK(Sblockstat2,SBLOCK2SAVEDATA))	//save data req//~v0heR~
      {                                                            //~v0heI~
      	if (capsavedata(Ppcw))                                     //~v0heI~
        	return 4;                                              //~v0heI~
		capmsgsaved();                                             //~v0heI~
      }                                                            //~v0heI~
      else                                                         //~v0heI~
      {                                                            //~v155I~
#ifdef WXEXXE                                                      //~v69ZM~
      	wxemouse_capi(WXEM_SETRGN,0);     //enable copy menu       //~v69ZI~
#endif                                                             //~v69ZM~
      	Skbdinpctr=Gkbdinpctr;		//ctr when block closed        //~v155I~
		uerrmsg("Block defined",                                //~5423R~
				"ブロック指定完了");                            //~5423R~
      }                                                            //~v155I~
    }
    else
	{
	  if (UCBITCHK(Sblockstat2,SBLOCK2SAVEDATA))	//save data req//~v0heR~
      {                                                            //~v0heI~
		if (Ppcw==Gcappcw)	//closed                               //~v0heI~
        {                                                          //~v0heI~
	      	if (capsavedata(Ppcw))                                 //~v0heI~
	        	return 4;                                          //~v0heI~
			capmsgsaved();                                         //~v0heI~
		}                                                          //~v0heI~
        else                                                       //~v0heI~
            return capnoblockerr();                                //~v0heI~
      }//savedata                                                  //~v0heI~
      else//not save data                                          //~v0heI~
      {                                                            //~v0heI~
		if (Gcappcw)
        {
//          capreset(1);	//clear previous block                 //~v155R~
			if (Skbdinpctr+1==Gkbdinpctr)	//just after block close//~v155M~
		        return tc_blocksave(Ppcw);                         //~v155I~
            else                                                   //~v155M~
            {                                                      //~v155I~
            capreset(2);	//keep calc pcw                        //~v155I~
		   	uerrmsg("Block mode re-start",
					"ブロック指定再開始");                      //~5423R~
            }                                                      //~v155I~
        }
		else
			uerrmsg("Block mode start",
					"ブロック指定開始");                        //~5423R~
		if (capsavepoint(Ppcw,0)) //startpoint
			return 4;
      }//not savedata                                              //~v0heI~
	}
	return 0;
}//func_block_file
#ifdef WXEXXE                                                      //~vbd2I~
//*******************************************************          //~vbd2I~
//* WXE selectall                                                  //~vbd2I~
//*******************************************************          //~vbd2I~
int capselectallfile(PUCLIENTWE Ppcw)                              //~vbd2I~
{                                                                  //~vbd2I~
    PULINEH plh;                                                   //~vbd2R~
	int rc;                                                        //~vbd2I~
//*******************                                              //~vbd2I~
//  if (!CSRONFILELINE(Ppcw))				//out of screen        //~vbd2R~
//		return errcsrpos();                                        //~vbd2R~
//  if (capsavepointselectall(Ppcw,0)) //startpoint                //~vbd2I~//+vbdrR~
    if (capsavepointselectall(Ppcw,0,0,0)) //startpoint            //+vbdrI~
		return 4;                                                  //~vbd2I~
//  if (capsavepointselectall(Ppcw,1))                             //~vbd2R~//+vbdrR~
    if (capsavepointselectall(Ppcw,1,0,0))                         //+vbdrI~
		return 4;                                                  //~vbd2R~
    for (plh=Gcapplh1;plh;plh=UGETQNEXT(plh))                      //~vbd2R~
    {                                                              //~vbd2R~
        if (plh->ULHtype==ULHTDATA)                                //~vbd2R~
            UCBITON(plh->ULHflag,ULHFDRAW|ULHFBLOCK);              //~vbd2R~
    }                                                              //~vbd2R~
	UCBITON(Sblockstat,SBLOCKCLOSED);	//block closed             //~vbd2R~
	UCBITOFF(Sblockstat,SBLOCKSAVED);	//block closed             //~vbd2R~
	UCBITOFF(Sblockstat2,SBLOCK2LINEMARK);	//block closed         //~vbd2R~
    rc=capchkcsrpos(Gcsrposy,Gcsrposx,0/*Pppcw*/);                 //~vbd2I~
    if (rc==2)	//on cmdline                                       //~vbd2I~
		func_nextline(Ppcw); //bypass capchkcsrpos <-- wxe_capprotchk to enable pasteV menuitem//~vbd2I~
    wxemouse_capi(WXEM_SETRGN,0);     //set Mcpcopysw=2 then enable copy menu           //~vbd2R~//~vbd8R~
  	uerrmsg("Selected all lines(Region Mode)",                                  //~vbd2R~//~vbd7R~
  				"領域モード全選択完了");                                     //~vbd2I~//~vbd7R~
	return 0;                                                      //~vbd2I~
}//capselectallfile                                                //~vbd2I~
#endif                                                             //~vbd2R~
//*******************************************************          //~vbd7I~
//* SEL all cmd for range type(A+F6)                               //~vbd7I~
//*******************************************************          //~vbd7I~
//int capselectallfilecmdstd(PUCLIENTWE Ppcw)                        //~vbd7I~//~vbdrR~
int capselectallfilecmdstd(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2)//~vbdrI~
{                                                                  //~vbd7I~
	int rc;                                                        //~vbd7I~
//*******************                                              //~vbd7I~
	UTRACEP("%s\n",UTT);                                           //~vbd7R~
//  if (capsavepointselectall(Ppcw,0)) //startpoint                //~vbd7I~//~vbdrR~
    if (capsavepointselectall(Ppcw,0,Pplh1,Pplh2)) //startpoint    //~vbdrI~
		return 4;                                                  //~vbd7I~
//  if (capsavepointselectall(Ppcw,1))                             //~vbd7I~//~vbdrR~
    if (capsavepointselectall(Ppcw,1,Pplh1,Pplh2))                 //~vbdrI~
		return 4;                                                  //~vbd7I~
	UCBITON(Sblockstat,SBLOCKCLOSED);	//block closed             //~vbd7I~
	UCBITOFF(Sblockstat,SBLOCKSAVED);	//block closed             //~vbd7I~
    rc=capchkcsrpos(Gcsrposy,Gcsrposx,0/*Pppcw*/);                 //~vbd7I~
    if (rc==2)	//on cmdline                                       //~vbd7I~
		func_nextline(Ppcw); //bypass capchkcsrpos <-- wxe_capprotchk to enable pasteV menuitem//~vbd7I~
#ifdef WXEXXE                                                      //~vbd7I~
    wxemouse_capi(WXEM_SETRGN2,0);     //enable copy menu           //~vbd7I~//~vbd8R~
#endif                                                             //~vbd7I~
  if (Pplh1)                                                       //~vbdrI~
  {                                                                //~vbdrI~
    if (*Pplh1->ULHlinecmd && *Pplh2->ULHlinecmd)                  //~vbdrI~
  		uerrmsg("RegionMode:Selected by line label(%s<-->%s)",     //~vbdrR~
  				"領域モード ラベル指定(%s<-->%s) 完了",            //~vbdrR~
                Pplh1->ULHlinecmd,Pplh2->ULHlinecmd);              //~vbdrR~
    else                                                           //~vbdrI~
  		uerrmsg("RegionMode:Selected by lineno(%d<-->%d)",         //~vbdrR~
  				"領域モード 行番号指定(%d<-->%d) 完了",            //~vbdrR~
                Pplh1->ULHlinenor,Pplh2->ULHlinenor);              //~vbdrR~
  }                                                                //~vbdrI~
  else                                                             //~vbdrI~
  	uerrmsg("RegionMode:Selected all lines",                       //~vbd7R~
  				"領域モード全選択完了");                           //~vbd7R~
	return 0;                                                      //~vbd7I~
}//capselectallfilecmdstd                                          //~vbd7R~
//*******************************************************          //~vbd7I~
//* SEL all cmd with col range(block mode)                         //~vbd7I~
//*******************************************************          //~vbd7I~
//int capselectallfilecmdblocksub(PUCLIENTWE Ppcw,int Pcol1,int Pcol2)//~vbd7I~//~vbdrR~
int capselectallfilecmdblocksub(PUCLIENTWE Ppcw,int Pcol1,int Pcol2,PULINEH Pplh1,PULINEH Pplh2)//~vbdrR~
{                                                                  //~vbd7I~
	int rc,col1,col2;                                              //~vbd7R~
//*******************                                              //~vbd7I~
	UTRACEP("%s\n",UTT);                                           //~vbd7R~
    col1=Pcol1-1;                                                  //~vbd7I~
    col2=Pcol2;                                                    //~vbd7R~
//  if (capsavepointselectallblock(Ppcw,0,col1,col2)) //startpoint //~vbd7R~//~vbdrR~
    if (capsavepointselectallblock(Ppcw,0,col1,col2,Pplh1,Pplh2)) //startpoint//~vbdrI~
		return 4;                                                  //~vbd7I~
//  if (capsavepointselectallblock(Ppcw,1,col1,col2))              //~vbd7R~//~vbdrR~
    if (capsavepointselectallblock(Ppcw,1,col1,col2,Pplh1,Pplh2))  //~vbdrI~
		return 4;                                                  //~vbd7I~
	UCBITON(Sblockstat,SBLOCKCLOSED);	//block closed             //~vbd7I~
	UCBITOFF(Sblockstat,SBLOCKSAVED);	//block closed             //~vbd7I~
    rc=capchkcsrpos(Gcsrposy,Gcsrposx,0/*Pppcw*/);                 //~vbd7I~
    if (rc==2)	//on cmdline                                       //~vbd7I~
		func_nextline(Ppcw); //bypass capchkcsrpos <-- wxe_capprotchk to enable pasteV menuitem//~vbd7I~
#ifdef WXEXXE                                                      //~vbd7I~
    wxemouse_capi(WXEM_SETRGN,0);     //enable copy menu           //~vbd7I~//~vbd8R~
#endif                                                             //~vbd7I~
  if (Pplh1)                                                       //~vbdrI~
    if (*Pplh1->ULHlinecmd && *Pplh2->ULHlinecmd)                  //~vbdrI~
	  	uerrmsg("BlockMode:Selected by line label(%s<-->%s), Colomn %d-%d",//~vbdrR~
  				"ブロックモード ラベル指定(%s<-->%s) 選択完了, カラム=%d-%d",//~vbdrI~
                Pplh1->ULHlinecmd,Pplh2->ULHlinecmd,Pcol1,Pcol2);  //~vbdrI~
    else                                                           //~vbdrI~
	  	uerrmsg("BlockMode:Selected by lineno(%d<-->%d), Colomn %d-%d",//~vbdrI~
  				"ブロックモード 行番号指定(%d<-->%d) 選択完了, カラム=%d-%d",//~vbdrI~
                Pplh1->ULHlinenor,Pplh2->ULHlinenor,Pcol1,Pcol2);  //~vbdrI~
  else                                                             //~vbdrI~
  	uerrmsg("BlockMode:Selected all lines,Colomn %d-%d",           //~vbd7R~
  				"ブロックモード全選択完了, カラム=%d-%d",          //~vbd7R~
                Pcol1,Pcol2);                                      //~vbd7I~
	return 0;                                                      //~vbd7I~
}//capselectallfilecmdblocksub                                     //~vbd7R~
//*******************************************************          //~v53cI~
//!func_copyword                                                   //~v53cI~
//* block mode start/stop                                          //~v53cI~
//* parm1:pcw                                                      //~v53cI~
//* retrn:rc                                                       //~v53cI~
//*******************************************************          //~v53cI~
int func_copyword(PUCLIENTWE Ppcw)                                 //~v53cI~
{                                                                  //~v53cI~
    PUFILEC pfc;                                                   //~v53cI~
    PUFILEH pfh=0;                                                   //~v53cI~//~vb49R~
    PULINEH plh;                                                   //~v53cI~
    char *pword,word[MAXCOLUMN+1];   //word get area               //~v53cR~
    char wku8[MAXCOLUMN+1];   //word get area                      //~vb49I~
    char wkct[MAXCOLUMN+1];   //word get area                      //~vb49I~
    char wkdbcs[MAXCOLUMN+1];   //word get area                    //~vb49I~
    int len,wordpos=-1,msgtype;                                    //~v53cR~
#ifdef UTF8UCS2                                                    //~va20I~
	char *pdbcs=0;                                                 //~va20I~
    int optsw=0;                                                   //~va20I~
#endif                                                             //~va20I~
	int wordct;                                                    //~vau3R~
    int ddlen;                                                     //~vauGR~
    char *pdddata,*pdddbcs;                                        //~vauGR~
#ifdef W32UNICODE                                                  //~vauGI~
    char wordstrip[MAXCOLUMN+1],*pwordstrip=NULL;   //word get area//~vauGI~
    int lenstrip=0;                                                //~vauGI~
#endif                                                             //~vauGI~
	int rc2,swedit=0,u8len,opt,handle=0,lclen;                     //~vb49R~
    UCHAR *pu8;                                                    //~vb49R~
//*******************                                              //~v53cI~
	pword=word;                                                    //~v53cI~
    msgtype=1;                                                     //~v53cI~
	switch (((PUPANELC)Ppcw->UCWppc)->UPCid)                       //~v53cI~
    {                                                              //~v53cI~
	case PANFBROWSE:                                               //~v53cI~
	case PANFEDIT:                                                 //~v53cI~
        pfc=Ppcw->UCWpfc;                                          //~v53cI~
        pfh=pfc->UFCpfh;                                           //~v53cI~
        if (pfh->UFHtype==UFHTCLIPBOARD)                           //~v53cI~
            return capcberr();                                     //~v53cI~
//		len=filegetword(Ppcw,&plh,&wordpos);                       //~v77ER~
  		len=filegetword(Ppcw,&plh,&wordpos,0);                     //~v77EI~
        if (!len)                                                  //~v53cR~
        	break;                                                 //~v53cI~
        Gcappcw=Ppcw;                                              //~v53cR~
        Ssortplh1=Ssortplh2=Gcapplh1=Gcapplh2=plh;                 //~v53cR~
        Ssortposx1=Scapposx1=wordpos;                              //~v53cR~
        Ssortposx2=Scapposx2=wordpos+len;                          //~v53cR~
        UCBITON(Sblockstat2,SBLOCK2WORDCOPY);   //request redraw word//~v53cR~
        pword=plh->ULHdata+wordpos;                                //~v53cR~
#ifdef UTF8UCS2                                                    //~va20I~
        pdbcs=plh->ULHdbcs+wordpos;                                //~va20I~
        if (FILEUTF8MODE(pfh))                                     //~va20I~
        	optsw=CSDWO_CPU8;                                      //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		else                                                       //~va50I~
        if (PFH_ISEBC(pfh))                                        //~va50I~
        	optsw=CSDWO_CPEB;                                      //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        UCBITON(Sblockstat,SBLOCKMODE|SBLOCKCLOSED);   //block     //~v53cI~
        UCBITOFF(Sblockstat,SBLOCKSAVED);   //block saved          //~v53cI~
        UCBITOFF(Sblockstat2,SBLOCK2LINEMARK);  //block closed     //~v53cI~
        UCBITOFF(Sblockstat2,SBLOCK2STDREGION);	//not started by "start stdregin"//~v66eI~
        msgtype=0;                                                 //~v53cI~
        swedit=1;                                                  //~vb49I~
    	handle=pfh->UFHhandle;                                     //~vb49I~
        break;                                                     //~v53cI~
	case PANDIR:                                                   //~v53cI~
//  	len=dirgetword(Ppcw,word,sizeof(word));                    //~v53cI~//~vau3R~
//  	len=dirgetword(Ppcw,word,sizeof(word),&wordct);            //~vau3R~//~vauGR~
    	len=dirgetword(Ppcw,word,sizeof(word)-1,&wordct,&pdddata,&pdddbcs,&ddlen);//~vauGR~
        if (wordct==XEUTFCT_UTF8)                                  //~vau3R~
        	optsw=CSDWO_CPU8WORD;      //source file is utf8 file  //~vau3R~
        *(word+len)=0;                                             //~vauGI~
#ifdef W32UNICODE                                                  //~vauGI~
//	  	ufilecvstripUD(0,word,len,wordstrip,sizeof(wordstrip),&lenstrip);//~vavkR~
    	ufilecvstripUD(0,word,len,wordstrip,sizeof(wordstrip),&lenstrip,NULL/*pct*/,NULL/*pcto*/);//~vavkR~
        pwordstrip=wordstrip;                                      //~vauGI~
#endif                                                             //~vauGI~
        break;                                                     //~v53cI~
	case PANFNAME  :		//filename list                        //~v53cI~
        len=pan300getword(Ppcw,word,sizeof(word));                 //~v53cI~
        break;                                                     //~v53cI~
    default:                                                       //~v53cI~
  		return errscrtype("WordCopyToCB");                         //~v53cI~
    }                                                              //~v53cI~
    if (!len)                                                      //~v53cI~
        return 4;                                                  //~v53cI~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef W32UNICODE                                                  //~vauGI~
    if (capsavedataword(optsw,Ppcw,(pwordstrip?pwordstrip:pword),pdbcs,(pwordstrip?lenstrip:len)))//~vauGR~
#else                                                              //~vauGI~
    if (capsavedataword(optsw,Ppcw,pword,pdbcs,len))               //~va20I~
#endif                                                             //~vauGI~
#else                                                              //~va20I~
    if (capsavedataword(Ppcw,pword,len))                           //~v53cR~
#endif                                                             //~va20I~
    	return 4;                                                  //~v53cI~
    if (swedit)                                                    //~vb49I~
    {                                                              //~vb49I~
        if (FILEUTF8MODE(pfh))                                     //~vb49I~
        {                                                          //~vb49I~
#ifdef W32                                                         //~vb4fM~
        	opt=0;                                                 //~vb4fI~
    		rc2=xeutfcvDD2UD(opt,pword,pdbcs,len,len*MAX_MBCSLEN/*malloc at DDUUD*/,&pu8,&u8len); //subchar by UD fmt//~vb4fI~
          if (rc2<4)                                               //~vb4fI~
          {                                                        //~vb4fI~
            	pword=pu8;                                         //~vb4fI~
                len=u8len;                                         //~vb4fI~
            	msgtype=1;      //display cb:xxxx                  //~vb4fI~
          }                                                        //~vb4fI~
          else                                                     //~vb4fI~
#endif                                                             //~vb4fM~
          {                                                        //~vb4fI~
        	opt=XEUTFDD2FO_OUTSTRZ; //       0x0002 //setdbcstbl as bin file//~vb49I~
			if (xeutfcvdd2f(opt,pword,pdbcs,len,&pu8,&u8len,0/*Ppoutdbcs*/)<UTFDD2FRC_ERR)//~vb49I~
            {                                                      //~vb49I~
            	pword=pu8;                                         //~vb49I~
                len=u8len;                                         //~vb49I~
            	msgtype=1;      //display cb:xxxx                  //~vb49I~
            }                                                      //~vb49I~
          }                                                        //~vb4fI~
        }                                                          //~vb49I~
        else                                                       //~vb49I~
        if (PFH_ISEBC(pfh))                                        //~vb49I~
        {                                                          //~vb49I~
            opt=XEEBCO_DROPSOSI|XEEBCO_ERRREP;//delete so/si at B2M//~vb49I~
            if ((rc2=xeebc_b2fl(opt,handle,pword,pdbcs,len,        //~vb49I~
                    wku8,sizeof(wku8)-1,&u8len,                    //~vb49I~
                    word,wkdbcs,wkct,sizeof(word)-1,&lclen))<4)    //~vb49I~
            {                                                      //~vb49I~
                if (!rc2)   //b2l ok                               //~vb49I~
                {                                                  //~vb49I~
                    len=lclen;                                     //~vb49I~
                    pword=word;                                    //~vb49R~
                }                                                  //~vb49I~
                else                                               //~vb49I~
                {                                                  //~vb49I~
                    len=u8len;                                     //~vb49I~
                    pword=wku8;                                    //~vb49I~
                }                                                  //~vb49I~
            	msgtype=1;      //display cb:xxxx                  //~vb49I~
            }                                                      //~vb49I~
        }                                                          //~vb49I~
        else                                                       //~vb49I~
        {                                                          //~vb49I~
            if (len<(int)sizeof(word)-1)                           //~vb49I~
            {                                                      //~vb49I~
            	memcpy(word,pword,(size_t)len);                    //~vb49I~
            	pword=word;                                        //~vb49I~
            	msgtype=1;      //display cb:xxxx                  //~vb49I~
            }                                                      //~vb49I~
        }                                                          //~vb49I~
    }                                                              //~vb49I~
    if (msgtype)                                                   //~v53cI~
    {                                                              //~v53cI~
    	*(pword+len)=0;		//strz                                 //~v53cI~
    	uerrmsg("CB:%s",0,                                         //~v53cI~
        		pword);                                            //~v53cI~
    }                                                              //~v53cI~
    else                                                           //~v53cI~
	    capmsgsaved();                                             //~v53cR~
	return 0;                                                      //~v53cI~
}//func_copyword                                                   //~v53cI~
//*******************************************************          ///~vb4aR~
int capfilesavelcctforerrmsg(int Popt,PUCLIENTWE Ppcw,char *Pdddata,char *Pdddbcs,char *Pddcode,int Pddlen,int Pu8len)//~vb4aR~
{                                                                  //~vb4aR~
	int idx,opt;                                                   //~vb4aR~
//********************************                                 //~vb4aR~
	idx=Ppcw->UCWsplitid;                                          //~vb4aR~
	opt=idx|XEUTFSLCFEO_DDFMT;                                     //~vb4aR~
    return xeutf_savelcctforerrmsg(opt,NULL,Pu8len,Pdddata,Pdddbcs,Pddcode,Pddlen);//~vb4aR~
}//capfilesavelcctforerrmsg                                        //~vb4aR~
//*******************************************************          //~v77FI~
//!func_copywordcmd                                                //~v77FI~
//* copy word on cursor to cmdline                                 //~v77FI~
//* parm1:pcw                                                      //~v77FI~
//* retrn:rc                                                       //~v77FI~
//*******************************************************          //~v77FI~
int func_copywordcmd_file(PUCLIENTWE Ppcw)                         //~v77FI~
{                                                                  //~v77FI~
    PULINEH plh;                                                   //~v77FI~
    char *pword,cmdlinewk[UPCCMDFLDWKSZ];   //word get area        //~v77FR~
    UCHAR  *flddata;                                               //~v77FR~
    int cmdlen,wordpos,addlen;                                     //~v77ER~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file,u8len,opt,lclen;                                //~va20R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile,rc2,swkbdu8=0;                                                 //~va50I~//~va5BR~//~vaf9R~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*******************                                              //~v77FI~
	switch (((PUPANELC)Ppcw->UCWppc)->UPCid)                       //~vaunI~
    {                                                              //~vaunI~
	case PANDIR:                                                   //~vaunI~
		return func_copywordcmd_dir(Ppcw);                         //~vaunR~
    }                                                              //~vaunI~
	if (capgetmouseword(0,Ppcw,&plh,&wordpos,&addlen))             //~v77FI~
  		addlen=filegetword(Ppcw,&plh,&wordpos,0);                  //~v77FR~
    if (!addlen)                                                   //~v77FI~
        return 4;                                                  //~v77FI~
    pword=plh->ULHdata+wordpos;                                    //~v77FI~
    UTRACED("wordpos=%s",pword,plh->ULHlen-wordpos);                   //~vau3I~//~vb2ER~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=PLHUTF8MODE(plh);                                   //~va20I~
    handle=UGETPFH(plh)->UFHhandle;                                //~va79I~
    if (swutf8file)                                                //~va20I~
    {                                                              //~va20I~
//  	opt=XEUTFDD2FLO_U8ERRMSG;	//      0x01 //register utf8 code for errmsg//~va5jR~
        opt=0;                                                     //~va50I~
//  	if (xeutfcvdd2fl(opt,Ppcw,pword,plh->ULHdbcs+wordpos,addlen,//~va20I~//~va5CR~
    	if ((rc2=xeutfcvdd2fl(opt,Ppcw,pword,plh->ULHdbcs+wordpos,addlen,//~va5CI~
				Gcmdbuffu8,sizeof(Gcmdbuffu8),&u8len,              //~va20I~
//  			Gcmdbufflc,Gcmdbuffdbcs,Gcmdbuffct,sizeof(Gcmdbufflc),&lclen)>=4)//~va20R~//~va5CR~
    			Gcmdbufflc,Gcmdbuffdbcs,Gcmdbuffct,sizeof(Gcmdbufflc),&lclen))>=4)//~va5CI~
            return 4;    	                                       //~va20I~
        Gcmdbufflclen=lclen;                                       //~va20I~
        addlen=u8len;                                              //~va20I~
        pword=Gcmdbuffu8;                                          //~va20R~
        swkbdu8=((rc2/*f2l err*/)||(Gutfmode2 & GUM2_KBDUTF8/*kbd utf8 mode*/));//~va5CI~
//        if (!swkbdu8)                                            //~vau8R~
//        {                                                        //~vau8R~
//            addlen=lclen;                                        //~vau8R~
//            pword=Gcmdbufflc;                                    //~vau8R~
//        }                                                        //~vau8R~
        if (!swkbdu8)                                              //~vauCI~
        {                                                          //~vauCI~
            addlen=lclen;                                          //~vauCI~
            pword=Gcmdbufflc;                                      //~vauCI~
        }                                                          //~vauCI~
        capfilesavelcctforerrmsg(0,Ppcw,plh->ULHdata+wordpos,plh->ULHdbcs+wordpos,Gcmdbuffct,lclen,addlen);//~vb4aR~
    }                                                              //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PLH_ISEBC(plh);                                      //~va50I~
    if (swebcfile)                                                 //~va50I~
    {                                                              //~va50I~
//  	opt=0;                                                     //~va50I~//~va5AR~
    	opt=XEEBCO_DROPSOSI|XEEBCO_ERRREP;//delete so/si at B2M    //~va5AR~
//  	if ((rc2=xeebc_b2fl(opt,pword,plh->ULHdbcs+wordpos,addlen,      //~va50R~//~va5BR~//~va79R~
    	if ((rc2=xeebc_b2fl(opt,handle,pword,plh->ULHdbcs+wordpos,addlen,//~va79I~
				Gcmdbuffu8,sizeof(Gcmdbuffu8),&u8len,              //~va50I~
				Gcmdbufflc,Gcmdbuffdbcs,Gcmdbuffct,sizeof(Gcmdbufflc),&lclen))>=4)//~va50I~//~va5BR~
            return 4;                                              //~va50I~
        swkbdu8=((rc2/*f2l err*/)||(Gutfmode2 & GUM2_KBDUTF8/*kbd utf8 mode*/));//~va5BI~
        Gcmdbufflclen=lclen;                                       //~va50I~
        addlen=u8len;                                              //~va50I~
        pword=Gcmdbuffu8;                                          //~va50I~
        if (!swkbdu8)   //kbd lc mode and cv b2l ok
        {                                                          //~va5BI~
    		addlen=lclen;                                          //~va5BI~
        	pword=Gcmdbufflc;                                      //~va5BI~
        }                                                          //~va5BI~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (!(getfldpos(Ppcw,CMDLINENO,0,&flddata,0/*no dbcs out*/)))	//no dbcs parm//~v77ER~
        return 4;                                                  //~v77FI~
    cmdlen=(int)strlen(flddata);                                   //~v77ER~
    if (cmdlen>=sizeof(cmdlinewk)-1)                               //~v77FI~
    	return 4;                                                  //~v77FI~
    if (cmdlen+addlen>=sizeof(cmdlinewk)-1)                        //~v77FI~
    	return errtoolong();                                       //~v77FI~
#ifdef UTF8SUPPH                                                   //~va00I~
    *cmdlinewk=0;   // for compiler warning(not used)              //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
	opt=0;                                                         //~va20I~
	if (swutf8file)                                                //~va20I~
    {                                                              //~va5CI~
	  if (swkbdu8)                                                 //~va5CI~
		opt|=SFDDCUO_SETCT2;                                       //~va20R~
    }                                                              //~va5CI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    else                                                           //~va50I~
    if (swebcfile)                                                 //~va50I~
    {                                                              //~va5CI~
      if (swkbdu8)                                                 //~va5BI~
		opt|=SFDDCUO_SETCT2;                                       //~va50I~
    }                                                              //~va5CI~
#endif                                                             //~va50I~
	setflddatadbcscmd_byutf8(opt,Ppcw,cmdlen,pword,Gcmdbuffdbcs,addlen);//~va20R~
#else                                                              //~va20I~
	setflddatadbcscmd_byutf8(0,Ppcw,cmdlen,pword,plh->ULHdbcs+wordpos,addlen);//~va00R~
#endif                                                             //~va20I~
#else                                                              //~va00I~
    memcpy(cmdlinewk,flddata,(UINT)cmdlen);                        //~v77FI~
    UmemcpyZ(cmdlinewk+cmdlen,pword,(UINT)addlen);                 //~v77FR~
    setflddata(Ppcw,CMDLINENO,0,cmdlinewk);                        //~v77FI~
#endif                                                             //~va00I~
	csrhomepos(0/*current panel*/);                                //~vawJI~
    UTRACEP("func_copywordcmd\n");                                 //~vau3I~
	return 0;                                                      //~v77FI~
}//func_copywordcmd_file                                           //~vaunR~
//*******************************************************       //~5513I~
//!func_blockdel_file
//* block delete                                                //~5513I~
//* parm1:pcw                                                   //~5513I~
//* retrn:rc                                                    //~5513I~
//*******************************************************       //~5513I~
int func_blockdel_file(PUCLIENTWE Ppcw)                         //~5513I~
{                                                               //~5513I~
	return capdel(Ppcw,0);	//del                               //~5513I~
}//func_blockdel_file                                           //~5513I~
                                                                //~5513I~
//*******************************************************       //~5513I~
//!func_blockclear_file
//* block clear                                                 //~5513I~
//* parm1:pcw                                                   //~5513I~
//* retrn:rc                                                    //~5513I~
//*******************************************************       //~5513I~
int func_blockclear_file(PUCLIENTWE Ppcw)                       //~5513I~
{                                                               //~5513I~
	return capdel(Ppcw,1);	//space clear                       //~5513I~
}//func_blockclear_file                                         //~5513R~
                                                                //~5513I~
//*******************************************************
//!capdel
//* block delete
//* parm1:pcw
//* parm2:clear option  0:del block , 1:clear block             //~5513I~
//* retrn:rc
//*******************************************************
int capdel(PUCLIENTWE Ppcw,int Pclearopt)                       //~5513R~
{
	PUFILEC pfc;
	PUFILEH  pfh;                                               //~5520M~
	int rc,col;                                                 //~5521R~
    char *popt;                                                    //~v584I~
//*******************
	if (Ppcw!=Gcappcw)	//not block mode                        //~5527R~
//    {                                                            //~v0heR~
//        uerrmsg("Block is not specified",                        //~v0heR~
//                "ブロックが未指定");                             //~v0heR~
//        return 4;                                                //~v0heR~
//    }                                                            //~v0heR~
		return capnoblockerr();                                    //~v0heI~
	pfc=Ppcw->UCWpfc;                                           //~5520I~
	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//browse mode
		return errbrowsemode();                                    //~v098R~
                                                                //~5521I~
	if (!UCBITCHK(Sblockstat,SBLOCKCLOSED))	//block not closed  //~5520R~
    {                                                           //~5502I~
		if (capsavepoint(Ppcw,1))                               //~v06kM~
			return 4;                                           //~v06kM~
		if (capchkboxwidth(pfc->UFCpfh))	//width 0              //~v0dcR~
			return 4;                                           //~v06kI~
		UCBITON(Sblockstat,SBLOCKCLOSED);	//block closed      //~5502R~
		UCBITOFF(Sblockstat,SBLOCKSAVED);	//block closed      //~5502I~
		UCBITOFF(Sblockstat2,SBLOCK2LINEMARK);	//line mark processed //~v06eI~
    }                                                           //~5502I~
  if (!UCBITCHK(Gopt5,GOPT5CBNOCOPY))   //scroll by csr            //~v584I~
  {                                                                //~v584I~
	if (capsavedata(Ppcw))                                      //~5520R~
		return 4;                                               //~5502R~
    popt="On";                                                     //~v584R~
  }                                                                //~v584I~
  else                                                             //~v584I~
    popt="Off";                                                    //~v584R~
    pfh=UGETPFH(Ssortplh1);                                     //~5520M~
	UPCTRREQ(pfh);	//end of a shot                             //~5520I~
                                                                //~5520I~
	if (Pclearopt)                                              //~5513I~
    {                                                           //~5513I~
		if (!(rc=capclear(Ppcw)))                               //~5513I~
        {                                                          //~v66jI~
//  		uerrmsg("Block is cleared by space",                   //~v584R~
//  				"ブロックをスペースクリアー");                 //~v584R~
		  if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//not started by "start stdregin"//~v66eI~
    		uerrmsg("Region is cleared by space with save to ::CB option is %s.",//~v66eI~
    				"領域をスペースクリアー。::CB 保存オプションは %s。",//~v66eI~
					popt);                                         //~v66eI~
          else                                                     //~v66eI~
    		uerrmsg("Block is cleared by space with save to ::CB option is %s.",//~v584R~
    				"ブロックをスペースクリアー。::CB 保存オプションは %s。",//~v584R~
					popt);                                         //~v584I~
        }                                                          //~v66jI~
	}                                                           //~5513I~
    else                                                        //~5513I~
    {                                                           //~5513I~
		if (!(rc=capcut(Ppcw,0)))	//no overrapchk             //~5521R~
        {                                                          //~v66jI~
//  		uerrmsg("Cut and Copyed Block to Clipboard",           //~v584R~
//  				"ブロックの切り抜き");                         //~v584R~
		  if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//not started by "start stdregin"//~v66eI~
    		uerrmsg("Cut and Copyed the Region to Clipboard with ::CB save option is %s.",//~v66eI~
    				"領域の切り抜き。::CB 保存オプションは %s。",  //~v66eI~
					popt);                                         //~v66eI~
          else                                                     //~v66eI~
    		uerrmsg("Cut and Copyed Block to Clipboard with ::CB save option is %s.",//~v584R~
    				"ブロックの切り抜き。::CB 保存オプションは %s。",//~v584R~
					popt);                                         //~v584I~
        }                                                          //~v66jI~
    }                                                           //~5513I~
                                                                //~5520I~
	UPCTRREQ(pfh);	//end of a shot                             //~5520I~
//  col=Ssortposx1-pfc->UFCleft;                                   //~v0ihR~
  if (Ssortplh1==0)	//range deleted                                //~v66eR~
  {                                                                //~v66eI~
	filesetcsr(Ppcw,Ssortplh2,1,0);	//Ssortplh1 point prev line    //~v66eR~
	capreset(0);	//no access to Ssortplh1 to reset BLOCK flag   //~v66eI~
  }                                                                //~v66eI~
  else                                                             //~v66eI~
  {                                                                //~v66eI~
    col=pfh->UFHprotlen; 		//prot area len                    //~v0ihI~
    if (col<Ssortposx1)         //pos1 is right of prot area       //~v0ihI~
    	col=Ssortposx1;			//csr on left edge of del area     //~v0ihI~
    col-=pfc->UFCleft;                                             //~v0ihI~
    if (col>=0 && col < Ppcw->UCWwidth-Ppcw->UCWlinenosz)       //~v069R~
		filesetcsr(Ppcw,Ssortplh1,1,col);                       //~5527R~
	capreset(1);                                                //~5503I~
  }                                                                //~v66eI~
	return rc;
}//capdel                                                       //~5513R~

//*******************************************************       //~5521I~
//!func_blockcutmove_file
//* block move with cut                                         //~5521I~
//* parm1:pcw                                                   //~5521I~
//* retrn:rc                                                    //~5521I~
//*******************************************************       //~5521I~
int func_blockcutmove_file(PUCLIENTWE Ppcw)                     //~5521I~
{                                                               //~5521I~
//*******************                                           //~5521I~
	return capmove(Ppcw,0);		//move with cut                 //~5521I~
}//func_blockcutmove_file                                       //~5521I~
                                                                //~5521I~
//*******************************************************       //~5521I~
//!func_blockclearmove_file
//* block move with clear                                       //~5521I~
//* parm1:pcw                                                   //~5521I~
//* retrn:rc                                                    //~5521I~
//*******************************************************       //~5521I~
int func_blockclearmove_file(PUCLIENTWE Ppcw)                   //~5521I~
{                                                               //~5521I~
//*******************                                           //~5521I~
	return capmove(Ppcw,1);		//move with cut                 //~5521I~
}//func_blockclearmove_file                                     //~5521I~
                                                                //~5521I~
//*******************************************************       //~5502I~
//!capmove
//* block move                                                  //~5502I~
//* parm1:pcw                                                   //~5502I~
//* parm2:clear option(0:cut,1:clear)                           //~5521I~
//* retrn:rc                                                    //~5502I~
//*******************************************************       //~5502I~
int capmove(PUCLIENTWE Ppcw,int Pclearopt)                      //~5521R~
{                                                               //~5502I~
	PUFILEH pfh;                                                //~5520M~
    int insopt;                                                 //~5520R~
//*******************                                           //~5502I~
	if (!CSRONFILELINE(Ppcw))				//out of screen     //~5513I~
//  	return capcsrposerr();                                     //~v0i8R~
		return errcsrpos();                                        //~v0i8R~
    if (!Gcappcw                                                //~5520R~
	||  !UCBITCHK(Sblockstat,SBLOCKCLOSED))	//block not closed  //~5520R~
//    {                                                            //~v0heR~
//        uerrmsg("Block is not closed",                           //~v0heR~
//                "ブロック指定が未了");                           //~v0heR~
//        return 4;                                                //~v0heR~
//    }                                                            //~v0heR~
		return capnoblockerr();                                    //~v0heI~
                                                                //~5520R~
	if (UCBITCHK(((PUFILEC)((PUCLIENTWE)Gcappcw)->UCWpfc)->UFCflag,UFCFBROWSE))	//browse mode//~5520R~
		return errbrowsemode();                                    //~v098R~
	if (UCBITCHK(((PUFILEC)Ppcw->UCWpfc)->UFCflag,UFCFBROWSE))	//browse mode//~5520I~
		return errbrowsemode();                                    //~v098R~
                                                                //~5521I~
	pfh=((PUFILEC)Ppcw->UCWpfc)->UFCpfh;                        //~5520M~
	if (pfh->UFHtype==UFHTCLIPBOARD)                            //~5520M~
    	return capcberr();                                      //~5603I~
                                                                //~5520I~
//  if (Ppcw->UCWkeyshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT)   //~v06ER~
    if (((FUNCTBL*)(Ppcw->UCWpfunct))->FTfuncid==FUNCID_LIBLOCKCUTMOVE//~v06ER~
    ||  ((FUNCTBL*)(Ppcw->UCWpfunct))->FTfuncid==FUNCID_LIBLOCKCLRMOVE)//~v06lI~
    	insopt=2;	//line insert                               //~v06lI~
	else                                                        //~v06lI~
//      insopt=UCBITCHK(Gscrstatus,GSCRSINS);                   //~v06lR~
        insopt=1;                                               //~v06lI~
    if (capmovesub(Ppcw,insopt,pfh,Pclearopt))                  //~5521R~
    	return 4;                                               //~5520M~
	if (Pclearopt)                                              //~5521I~
    	if (insopt)                                             //~5521I~
    		uerrmsg("Block inserted from Clipboard",            //~5521I~
    				"クリアー+挿入複写");                       //~5521R~
        else                                                    //~5521I~
    		uerrmsg("Block overridden from Clipboard",             //~v66hR~
    				"クリアー+上書複写");                       //~5521R~
    else                                                        //~5521I~
    	if (insopt)                                             //~5521R~
    		uerrmsg("Block inserted from Clipboard",            //~5521R~
    				"削除+挿入複写");                           //~5521R~
        else                                                    //~5521R~
    		uerrmsg("Block overridden from Clipboard",             //~v66hR~
    				"削除+上書複写");                           //~5521R~
    return 0;                                                   //~5513I~
}//capmove                                                      //~5527R~
                                                                //~5502I~
//*******************************************************       //~5520I~
//!capmovesub
//* block move sub                                              //~5520I~
//* parm1:pcw                                                   //~5520I~
//* parm2:insert option                                         //~5520I~
//* parm3:pfh                                                   //~5521I~
//* parm4:clear option                                          //~5521I~
//* retrn:rc                                                    //~5520I~
//*******************************************************       //~5520I~
int capmovesub(PUCLIENTWE Ppcw,int Pinsopt,PUFILEH Ppfh,int Pclearopt)//~5521R~
{                                                               //~5520I~
    int rc;                                                     //~5520I~//~5521R~
    PUFILEH pfh;                                                //~5527I~
    int post1;                                                     //~v0bfR~
    int posx1afterdel;                                             //~vb25R~
//*******************                                           //~5520I~
	if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//not started by "start stdregin"//~v66eI~
        return caperrregionmode();                                 //~v66eI~
    if ((rc=capmoveovchk(Ppcw,Ppfh,Pinsopt,Pclearopt))>0)	//override chk//~v0bfR~
    	return 4;                                               //~5520I~
    if (UCBITCHK(Sblockstat,SBLOCKMODE))    //block mode           //~v0bfR~
        if (!Pinsopt || Ppcw->UCWrcsrx>=Ppcw->UCWlinenosz)//not insert on lineno//~v0bfR~
        {                                                          //~v0bfR~
            post1=Ppcw->UCWrcsrx-Ppcw->UCWlinenosz+((PUFILEC)Ppcw->UCWpfc)->UFCleft;//target pos 1//~v0bfR~
//            if (post1>=Ppfh->UFHmergin)                          //~v0eKR~
//                return charmerginerr(Ppfh->UFHmergin);           //~v0eKR~
    		if (capchkmergin(Ppfh,0,post1,2))                      //~v0eKI~
            	return 4;                                          //~v0eKI~
        }                                                          //~v0bfR~
	if (capsavedata(Gcappcw))                                   //~5520M~
		return 4;                                               //~5520M~
	UPCTRREQ(Ppfh);	//end of a shot                             //~5520R~
    if (Ppcw!=Gcappcw)                                          //~5527I~
    {                                                              //~v53wI~
//  	UPCTRREQ(pfh=((PUFILEC)((PUCLIENTWE)Gcappcw)->UCWpfc)->UFCpfh);//~v53wR~
    	pfh=((PUFILEC)((PUCLIENTWE)Gcappcw)->UCWpfc)->UFCpfh;      //~v53wI~
    	UPCTRREQ(pfh);                                             //~v53wI~
    }                                                              //~v53wI~
    else                                                        //~v06jI~
        pfh=0;          //source is same as target              //~v06jI~
                                                                //~5527I~
    posx1afterdel=Ppcw->UCWrcsrx-(Ssortposx2-Ssortposx1);//paste pos after cut//~vb25I~
    if (Pclearopt)                                              //~5521I~
    {                                                           //~5521I~
    	if (!(rc=capclear(Gcappcw)))                            //~5527R~
    	   	rc=capcopysub(Ppcw,Pinsopt);                        //~5521I~
    }                                                           //~5521I~
    else                                                        //~5521I~
    	if (rc==-2)                                                //~vb25R~
        {                                                          //~vb25I~
    		if (posx1afterdel>=Ppcw->UCWlinenosz)	//tgtplh1=Ssortplh1 && tgt posx1>=Ssortposx2//~vb25I~
            {                                                      //~vb25I~
                if (!(rc=capcut(Gcappcw,0)))    //no overrapchk    //~vb25R~
                {                                                  //~vb25R~
                    Ppcw->UCWrcsrx=posx1afterdel;//paste pos after cut(avoid <0; it cause isrt line)//~vb25R~
                    rc=capcopysub(Ppcw,Pinsopt);                   //~vb25R~
                }                                                  //~vb25R~
            }                                                      //~vb25I~
            else	//rcsrx after del is on linenosz               //~vb25I~
            {                                                      //~vb25I~
    	    	if (!(rc=capcopysub(Ppcw,Pinsopt)))                //~vb25I~
    				rc=capcut(Gcappcw,1);	//overrap chk          //~vb25I~
    			posx1afterdel=Ppcw->UCWrcsrx-(Ssortposx2-Ssortposx1);//paste pos after cut//~vb25I~
        		if (posx1afterdel<Ppcw->UCWlinenosz)	//tgtplh1=Ssortplh1 && tgt posx1>=Ssortposx2//~vb25R~
                	posx1afterdel=Ppcw->UCWlinenosz-1;             //~vb25R~
			    Ppcw->UCWrcsrx=posx1afterdel;                      //~vb25R~
                csrloctogbl(Ppcw);                                 //~vb25I~
            }                                                      //~vb25I~
    	}                                                          //~vb25I~
        else			//del and copy(target<source)              //~vb25I~
        if (rc)			//copy and del(source<target)           //~5521R~
        {                                                       //~5521R~
    	    if (!(rc=capcopysub(Ppcw,Pinsopt)))                 //~5521R~
    			rc=capcut(Gcappcw,1);	//overrap chk           //~5527R~
    	}                                                       //~5521R~
        else			//del and copy(target<source)           //~5521R~
        {                                                       //~5521R~
    		if (!(rc=capcut(Gcappcw,0)))	//no overrapchk     //~5527R~
    	    	rc=capcopysub(Ppcw,Pinsopt);                    //~5521R~
    	}                                                       //~5521R~
	UPCTRREQ(Ppfh);	//end of a shot                             //~5520R~
//  if (Ppcw!=Gcappcw)                                          //~v06jR~
    if (pfh)            //source pfh                            //~v06jI~
		UPCTRREQ(pfh);                                          //~5527I~
    capreset(1);                                                //~5520I~
	return rc;                                                  //~5520R~
}//capmovesub                                                   //~5520I~
                                                                //~5520I~
//*******************************************************       //~5520I~
//!capmoveovchk
//* block move target and source override chk                   //~5520I~
//* parm1:pcw                                                   //~5520I~
//* parm2:pfh                                                      //~v0bfI~
//* parm3:insert option                                            //~v0bfR~
//* parm4:clear option                                             //~v0bfR~
//* retrn:rc 0:no overrap(target<source:del then copy)          //~5520R~
//*         -1:no overrap(source<target:copy then del)          //~5520I~
//*         -2:no overrap(source<target and tgtplh1==Ssortplh1:del then copy)//~vb25I~
//*          4:overrap or other                                 //~5520I~
//*******************************************************       //~5520I~
int capmoveovchk(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Pinsopt,int Pclearopt)//~v0bfR~
{                                                               //~5520I~
    int rc=0,ii,lineno,post1,post2;                             //~5520R~
    PULINEH plh,plht1,plht2;                                    //~5520R~
//*******************                                           //~5520I~
    if (Gcappcw!=Ppcw)                                          //~5520I~
        return 0;                                               //~5520I~
    if (UCBITCHK(Ssortplh1->ULHflag2,ULHF2EXCLUDED)             //~5520R~
    ||  UCBITCHK(Ssortplh2->ULHflag2,ULHF2EXCLUDED))            //~5520I~
	{                                                           //~5520I~
		uerrmsg("Start or End line of block is excluded",       //~5520I~
//  			"ブロックの境界行が非表示行になっています");       //~v095R~
    			"ブロックの境界行が非\x95\\示行になっています");   //~v095I~
    	return 4;                                               //~5520R~
    }                                                           //~5520I~
    if (Pclearopt)                                              //~5521I~
    	return 0; 			//allow any override                //~5521I~
//count lineno and chk target y1                                //~5520I~
	plht1=(Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc;              //~5520R~
  if (plht1==Ssortplh1)                                            //~vb25I~
    rc=3;                                                          //~vb25I~
  else                                                             //~vb25I~
  {                                                                //~vb25I~
    ii=0;                                                       //~5520I~
    for (plh=Ssortplh1;plh;plh=UGETQNEXT(plh))                  //~5520R~
    {                                                           //~5520I~
    	if (plh==plht1)            	//target-y1 on source       //~5520R~
        {                                                       //~5520I~
        	rc=1;					//target-y1 on source 	    //~5520I~
            break;	                                            //~5520I~
		}                                                       //~5520I~
        if (plh->ULHtype==ULHTDATA)                             //~5520I~
        	ii++;                                               //~5520I~
        if (plh==Ssortplh2)                                     //~5520I~
			break;                                              //~5520I~
	}                                                           //~5520I~
    lineno=ii;                                                  //~5520I~
//chk target y2                                                 //~5520I~
    if (!rc)	//target y1 not on source                       //~5520I~
    {                                                           //~5520I~
    	ii=0;                                                   //~5520I~
        for (plht2=plht1;plht2;plht2=UGETQNEXT(plht2))          //~5520I~
        {                                                       //~5520I~
            if (plht2->ULHtype==ULHTDATA)                       //~5520I~
            	ii++;                                           //~5520I~
            if (ii==lineno)                                     //~5520I~
    			break;                                          //~5520I~
    	}                                                       //~5520I~
        if (plht2)		//not after end of file,may target y2 on source//~5520I~
        {                                                       //~5520I~
//search target y2 on source                                    //~5520I~
            for (plh=Ssortplh1;plh;plh=UGETQNEXT(plh))          //~5520I~
            {                                                   //~5520I~
            	if (plh==plht2)            	//target-y1 on source//~5520I~
                {                                               //~5520I~
                	rc=2;					//target-y1 on source//~5520I~
                    break;                                      //~5520I~
        		}                                               //~5520I~
                if (plh==Ssortplh2)                             //~5520I~
        			break;                                      //~5520I~
        	}                                                   //~5520I~
		}//target y2 exist                                      //~5520I~
	}//target y1 out of source                                  //~5520I~
  }//tgtplh!=Ssortplh1                                             //~vb25I~
    if (!rc)	//no line overrap                               //~5520I~
		return 0;                                               //~5520R~
//chk x                                                         //~5520I~
	if (UCBITCHK(Sblockstat,SBLOCKMODE))	//block mode        //~5520I~
    {                                                           //~5520I~
		if (Pinsopt && Ppcw->UCWrcsrx<Ppcw->UCWlinenosz)//insert on lineno//~v069R~
    		return 0;	//block ins after line                  //~5520I~
	    if (plht1->ULHtype==ULHTHDR)	//err at lcmdcopy paste/on//~5520I~
//  		return capcsrposerr();                                 //~v0i8R~
  			return errcsrpos();                                    //~v0i8I~
//block and block                                               //~5520I~
    	post1=Ppcw->UCWrcsrx-Ppcw->UCWlinenosz+((PUFILEC)Ppcw->UCWpfc)->UFCleft;//target pos 1//~v069R~
        if (post1<0)                                            //~5520I~
            post1=0;                                            //~5520I~
    	if (post1>=Ssortposx1)	//target is right               //~5520I~
        {                                                       //~5520I~
    		if (post1>=Ssortposx2)	//target far away to right  //~5520I~
            {                                                      //~vb25I~
                if (rc==3)  //plht1==Ssortplh1                     //~vb25I~
                    return -2;                                     //~vb25I~
        		return -1;          //copy then del             //~5520R~
            }                                                      //~vb25I~
//else target on right part of source block                     //~5520I~
    	}                                                       //~5520I~
        else					//target is left                //~5520I~
        {                                                       //~5520I~
    		post2=post1+Ssortposx2-Ssortposx1;	//target x2     //~5520I~
    		if (post2<=Ssortposx1)	//target is far away to left//~5520I~
        		return 0;           //del then copy             //~5520R~
//else target on left part of source block                      //~5520I~
           	if (Pinsopt)		//rep mode                      //~5520I~
    	    	return 0;           //del then insert           //~5520R~
    	}                                                       //~5520I~
    }//block mode                                               //~5520I~
                                                                //~5521I~
	uerrmsg("Target and source block is overrided",             //~5520I~
			"移動先と移動元のブロックが重複しています");        //~5520I~
    return 4;                                                   //~5520I~
}//capmoveovchk                                                 //~5520I~
                                                                //~5520I~
//*******************************************************       //~v06gI~
//!func_blockcopy_file
//* block copy by Ins/Rep Mode                                  //~v06gI~
//* parm1:pcw                                                   //~v06gI~
//* retrn:rc                                                    //~v06gI~
//*******************************************************       //~v06gI~
//int func_blockcopy_file(PUCLIENTWE Ppcw)                      //~v06lR~
//{                                                             //~v06lR~
//    int insopt;                                               //~v06lR~
//*******************                                           //~v06gI~
//    if (Ppcw->UCWkeyshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT)//~v06lR~
//    ||  ((FUNCTBL*)(Ppcw->UCWpfunct))->FTfuncid==FUNCID_LIBLOCKCOPY)//~v06lR~
//    	insopt=2;	//line insert	                            //~v06lR~
//	else                                                        //~v06lR~
//      insopt=UCBITCHK(Gscrstatus,GSCRSINS);                   //~v06lR~
//        insopt=1;                                             //~v06lR~
//	return capcopy(Ppcw,insopt);                                //~v06lR~
//}//func_blockcopy_file                                        //~v06lR~
                                                                //~v06gI~
//*******************************************************
//!func_blockrep_file
//* block replace copy
//* parm1:pcw
//* retrn:rc
//*******************************************************
int func_blockrep_file(PUCLIENTWE Ppcw)
{
	return capcopy(Ppcw,0);	//repmode                           //~5520R~
}//func_blockrep_file                                           //~v04dR~
//*******************************************************          //~v10MI~
//!func_blockrep_pan                                               //~v76bR~
//* block replace copy                                             //~v10MI~
//* parm1:pcw                                                      //~v10MI~
//* retrn:rc                                                       //~v10MI~
//*******************************************************          //~v10MI~
int func_blockrep_pan(PUCLIENTWE Ppcw)                             //~v10MI~
{                                                                  //~v10MI~
	int rc;                                                        //~v10MI~
//****************                                                 //~v10MI~
//    if (Ppcw->UCWrcsry!=CMDLINENO                                //~v76bR~
//    ||  (rc=captocmdline(Ppcw,0))==-1)                           //~v76bR~
//        return errcsrpos();                                      //~v76bR~
    if (Ppcw->UCWrcsry==CMDLINENO)                                 //~v76bR~
    {                                                              //~v76bI~
      	if ((rc=captocmdline(Ppcw,0))==-1)                         //~v76bI~
        	return errcsrpos();                                    //~v76bI~
    }                                                              //~v76bI~
    else                                                           //~v76bI~
    {                                                              //~v76bI~
      	if ((rc=captopanfld(Ppcw,0))==-1)                          //~v76bI~
        	return errcsrpos();                                    //~v76bI~
    }                                                              //~v76bI~
	return rc;                                                     //~v10MI~
}//func_blockrep_pan                                               //~v10MI~
//*******************************************************
//!func_blockins_file
//* block insert copy
//* parm1:pcw
//* retrn:rc
//*******************************************************
int func_blockins_file(PUCLIENTWE Ppcw)
{
    int insopt;                                                 //~v06lI~
//*******************                                           //~v06lI~
//  if (Ppcw->UCWkeyshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT)   //~v06ER~
    if (((FUNCTBL*)(Ppcw->UCWpfunct))->FTfuncid==FUNCID_LIBLOCKINS)//~v06ER~
    	insopt=2;	//line insert                               //~v06lI~
	else                                                        //~v06lI~
        insopt=1;                                               //~v06lI~
	return capcopy(Ppcw,insopt);	//insert mode               //~v06lR~
}//func_blockins_file                                           //~5520R~
//*******************************************************          //~v10MI~
//!func_blockins_pan                                               //~v10MI~
//* block insert copy                                              //~v10MI~
//* parm1:pcw                                                      //~v10MI~
//* retrn:rc                                                       //~v10MI~
//*******************************************************          //~v10MI~
int func_blockins_pan(PUCLIENTWE Ppcw)                             //~v10MI~
{                                                                  //~v10MI~
	int rc;                                                        //~v10MI~
//*******************                                              //~v10MI~
//    if (Ppcw->UCWrcsry!=CMDLINENO                                //~v76bR~
//    ||  (rc=captocmdline(Ppcw,1))==-1)                           //~v76bR~
//        return errcsrpos();                                      //~v76bR~
    if (Ppcw->UCWrcsry==CMDLINENO)                                 //~v76bI~
    {                                                              //~v76bI~
      	if ((rc=captocmdline(Ppcw,1))==-1)                         //~v76bI~
        	return errcsrpos();                                    //~v76bI~
    }                                                              //~v76bI~
    else                                                           //~v76bI~
    {                                                              //~v76bI~
      	if ((rc=captopanfld(Ppcw,1))==-1)                          //~v76bI~
        	return errcsrpos();                                    //~v76bI~
    }                                                              //~v76bI~
	return rc;                                                     //~v10MI~
}//func_blockins_pan                                               //~v10MI~
                                                                   //~v10MI~
//*******************************************************          //~v66fM~
//!func_blockins_pan                                               //~v66fM~
//* block insert copy                                              //~v66fM~
//* parm1:pcw                                                      //~v66fM~
//* retrn:rc                                                       //~v66fM~
//*******************************************************          //~v66fM~
int func_stdcppaste_pan(PUCLIENTWE Ppcw)                           //~v66fM~
{                                                                  //~v66fM~
//*******************                                              //~v66fM~
	return func_blockins_pan(Ppcw);                                //~v66fM~
}//func_stdcppaste_pan                                             //~v66fM~
//*******************************************************          //~v66fI~
//!capcopy                                                         //~v66fI~
//* block copy                                                     //~v66fI~
//* parm1:pcw                                                      //~v66fI~
//* parm2:insert option 0- rep 1:insert                            //~v66fI~
//* retrn:rc                                                       //~v66fI~
//*******************************************************          //~v66fI~
int func_stdcppaste_file(PUCLIENTWE Ppcw)                          //~v66fI~
{                                                                  //~v66fI~
	PUFILEH pfh;                                                   //~v66fI~
	PUFILEC pfc;                                                   //~v66fI~
	int rc;                                                        //~v66fI~
    char stat1,stat2;                                              //~v66fR~
//*******************                                              //~v66fI~
//  if (!CSRONFILELINE(Ppcw))				//out of screen        //~v703R~
//  if (!Gcappcw||!CSRONFILELINE(Ppcw))				//out of screen//~v703I~,//~v709R~
    if (!CSRONFILELINE(Ppcw))				//out of screen        //~v709I~
    	return func_stdcppaste_pan(Ppcw);                          //~v66fI~
	if (UCBITCHK(((PUFILEC)Ppcw->UCWpfc)->UFCflag,UFCFBROWSE))	//browse mode//~v66fI~
		return errbrowsemode();                                    //~v66fI~
                                                                   //~v66fI~
	pfc=Ppcw->UCWpfc;                                              //~v66fI~
	pfh=pfc->UFCpfh;                                               //~v66fI~
	if (pfh->UFHtype==UFHTCLIPBOARD)                               //~v66fI~
    	return capcberr();                                         //~v66fI~
    stat1=Sblockstat;                                              //~v66fM~
    stat2=Sblockstat2;  //capreset clear flag                      //~v66fM~
	UPCTRREQ(pfh);	//end of a shot                                //~v66fI~
                                                                   //~v66fI~
    rc=capstdpaste(Ppcw,Ssortplh1,Ssortplh2,Ssortposx1,Ssortposx2,stat1,stat2);//~v66fR~
                                                                   //~v66fI~
	UPCTRREQ(pfh);	//end of a shot                                //~v66fI~
	return rc;                                                     //~v66fI~
}//func_stdcppaste_file                                            //~v66fI~
                                                                   //~v66fM~
//*******************************************************
//!capcopy
//* block copy
//* parm1:pcw
//* parm2:insert option 0- rep 1:insert
//* retrn:rc
//*******************************************************
int capcopy(PUCLIENTWE Ppcw,int Pinsopt)                        //~5520R~
{
	PUFILEH pfh;
	PUFILEC pfc;                                                //~v06hI~
	int rc;
//*******************
	if (!CSRONFILELINE(Ppcw))				//out of screen
    {                                                              //~v10MI~
		if (Ppcw->UCWrcsry==CMDLINENO)                             //~v10MI~
        	if ((rc=captocmdline(Ppcw,Pinsopt))>=0)                //~v10MI~
            	return rc;                                         //~v10MI~
//  	return capcsrposerr();                                     //~v0i8R~
  		return errcsrpos();                                        //~v0i8I~
    }                                                              //~v10MI~
	if (UCBITCHK(((PUFILEC)Ppcw->UCWpfc)->UFCflag,UFCFBROWSE))	//browse mode//~5520R~
		return errbrowsemode();                                    //~v098R~
                                                                //~5521I~
	pfc=Ppcw->UCWpfc;                                           //~v06hI~
    Spendfcmd=(char)(pfc->UFCpendfcmd==ULCCMDCOPY||pfc->UFCpendfcmd==ULCCMDMOVE);//~v06hR~
	pfh=pfc->UFCpfh;                                            //~v06hR~
  if (!Spendfcmd)	//normal cat & paste	                    //~v06hI~
  {                                                             //~v06hI~
	if (pfh->UFHtype==UFHTCLIPBOARD)                            //~5603M~
    	return capcberr();                                      //~5603I~
                                                                //~5603I~
    if (Gcappcw)                                                //~5423I~
    {                                                           //~5423I~
  		if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//save region mode//~v66fI~
        {                                                          //~v677I~
        	                                                       //~v677I~
		  if (!UCBITCHK(Sblockstat,SBLOCKCLOSED)	//block not closed//~v677I~
		  ||  !UCBITCHK(Sblockstat,SBLOCKSAVED))	//block not saved//~v677I~
          {                                                        //~v677I~
//  		return caperrregionmode();                             //~v677R~
            uerrmsg("Region is not yet saved.",                    //~v677I~
                    "領域が未保存です");                           //~v677I~
            return 4;                                              //~v677I~
          }                                                        //~v677I~
        }                                                          //~v677I~
		if (!UCBITCHK(Sblockstat,SBLOCKCLOSED))	//block not closed//~5502R~
//        {                                                        //~v0heR~
//            uerrmsg("Block is not closed",                       //~v0heR~
//                    "ブロック指定が未了");                       //~v0heR~
//            return 4;                                            //~v0heR~
//        }                                                        //~v0heR~
			return capnoblockerr();                                //~v0heI~
		if (!UCBITCHK(Sblockstat,SBLOCKSAVED))	//block not saved//~5520R~
//      {                                                          //~v0heR~
			if (capsavedata(Gcappcw))                           //~5502R~
				return 4;                                       //~5502R~
	        capreset(1);                                        //~5520R~
//      }                                                          //~v0heR~
    }                                                           //~5423I~
                                                                //~5423I~
	UPCTRREQ(pfh);	//end of a shot
  }	//normal cat & paste	                                    //~v06hI~
                                                                //~5520I~
    rc=capcopysub(Ppcw,Pinsopt);                                //~5520I~
                                                                //~5520I~
  if (!Spendfcmd)	//normal cat & paste	                    //~v06hI~
  {                                                             //~v06hI~
	UPCTRREQ(pfh);	//end of a shot
    if (!rc)                                                    //~5423I~
    {                                                              //~v53wI~
		if (Pinsopt)                                            //~5520R~
			uerrmsg("Block inserted from Clipboard",            //~5520R~
					"ボードのブロックを挿入複写");              //~5520R~
		else                                                    //~5520R~
	      if (((FUNCTBL*)(Ppcw->UCWpfunct))->FTfuncid==FUNCID_BLOCKREPSPACE)//~v53LI~
			uerrmsg("Space in block overridden by Clipboard",      //~v66hR~
					"ブロックの空白を上書複写");                   //~v53LR~
          else                                                     //~v53LI~
			uerrmsg("Block overridden from Clipboard",             //~v66hR~
					"ボードのブロックを上書複写");              //~5520R~
    }//rc                                                          //~v53wI~
  }	//normal cat & paste	                                    //~v06hI~
	return rc;
}//capcopy
//*******************************************************          //~v10MI~
//!captocmdline                                                    //~v10MI~
//* block copy                                                     //~v10MI~
//* parm1:pcw                                                      //~v10MI~
//* parm2:insert option 0- rep 1:insert                            //~v10MI~
//* retrn:rc  ,-1 for csr pos err at return                        //~v10MI~
//*******************************************************          //~v10MI~
int captocmdline(PUCLIENTWE Ppcw,int Pinsopt)                      //~v10MI~
{                                                                  //~v10MI~
	PUSCRD psd;                                                    //~v10MI~
	UFLDE   *pfle;                                                 //~v10MR~
    int rc;                                                        //~v10MI~
//*******************                                              //~v10MI~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                               //~v10MI~
	pfle=getuflde(Ppcw,CMDLINENO,0);     //cmd line fld            //~v10MI~
//	rc=captofld(Ppcw,Pinsopt,pfle);                                //~v76bR~
  	rc=captofld(Ppcw,Pinsopt,pfle,0);                              //~v76bI~
//copysub end                                                      //~v10MI~
	UCBITON(psd->USDflag2,USDF2DRAW);                              //~v10MI~
	return rc;                                                     //~v10MR~
}//captocmdline                                                    //~v10MI~
//*******************************************************          //~v76bI~
//!captopanfld                                                     //~v76bI~
//* parm1:pcw                                                      //~v76bI~
//* parm2:insert option 0- rep 1:insert                            //~v76bI~
//* retrn:rc  ,-1 for csr pos err at return                        //~v76bI~
//*******************************************************          //~v76bI~
int captopanfld(PUCLIENTWE Ppcw,int Pinsopt)                       //~v76bI~
{                                                                  //~v76bI~
	PUSCRD psd;                                                    //~v76bI~
	UFLDE   *pfle;                                                 //~v76bI~
	UFLD    *pufld;                                                //~v76jR~
    int rc=-1,cposy;                                               //~v76bR~
    int fldno;                                                     //~v76jI~
//*******************                                              //~v76bI~
	cposy=Ppcw->UCWrcsry;                                          //~v76bR~
	psd=Ppcw->UCWpsd+cposy;                                        //~v76bR~
	switch(((PUPANELC)Ppcw->UCWppc)->UPCid)                        //~v76bI~
    {                                                              //~v76bI~
	case PANFNAME  :		//filename                             //~v76bI~
    	if (cposy==PANL300FILENAME                                 //~v76bR~
        ||  cposy==PANL300DIR)                                     //~v76bR~
        {                                                          //~v76bI~
			pfle=getuflde(Ppcw,cposy,0);     //cmd line fld        //~v76bR~
    		rc=captofld(Ppcw,Pinsopt,pfle,0);                      //~v76bR~
			UCBITON(psd->USDflag2,USDF2DRAW);                      //~v76bI~
        }                                                          //~v76bI~
    	break;                                                     //~v76bI~
	case PANUCOMP  :		//compare utility                      //~v76jI~
	case PANUGREP  :		//grep utility panel                   //~v76jI~
		if ((fldno=fldprotchk(Ppcw,0,&pufld))<0)	//fldno==-1:no fld//~v76jI~
        	break;	//rc=-1                                        //~v76jI~
		pfle=&pufld->UFLentry[fldno];                              //~v76jI~
    	rc=captofld(Ppcw,Pinsopt,pfle,fldno);                      //~v76jI~
    	break;                                                     //~v76jI~
	case PANDIR:		//compare utility                          //~vawcI~
		if ((fldno=fldprotchk(Ppcw,0,&pufld))<0)	//fldno==-1:no fld//~vawcI~
        	break;	//rc=-1                                        //~vawcI~
		if (fldno!=PANL310RENAME)                                  //~vawcI~
        	break;	//rc=-1                                        //~vawcI~
		pfle=&pufld->UFLentry[fldno];                              //~vawcI~
    	rc=captofld(Ppcw,Pinsopt,pfle,fldno);                      //~vawcI~
    	break;                                                     //~vawcI~
    }                                                              //~v76bI~
//copysub end                                                      //~v76bI~
	return rc;                                                     //~v76bI~
}//captopanfld                                                     //~v76bI~
//*******************************************************          //~v10MI~
//!captofld                                                        //~v76bR~
//* block copy                                                     //~v10MI~
//* parm1:pcw                                                      //~v10MI~
//* parm2:insert option 0- rep 1:insert                            //~v10MI~
//* retrn:rc  ,-1 for csr pos err at return                        //~v10MI~
//*******************************************************          //~v10MI~
//int captofld(PUCLIENTWE Ppcw,int Pinsopt,UFLDE *Ppflde)          //~v76bR~
int captofld(PUCLIENTWE Ppcw,int Pinsopt,UFLDE *Ppflde,int Pfldno) //~v76bI~
{                                                                  //~v10MI~
	PULINEH plh1,plh2,plh=NULL;                                         //~v10MI~//~vaf9R~
#ifdef AAA                                                         //~va00I~
	int rc=0,copylen,reslen,oldlen,newlen,offs,cposx,fldlen,availlen;//~v10MR~
#else                                                              //~va00I~
//  int rc=0,copylen,offs,cposx;                                   //~va00I~//~vaf9R~
    int rc=0,copylen=0,offs,cposx;                                 //~vaf9I~
#endif                                                             //~va00I~
    int cposy;                                                     //~v76bI~
#ifdef AAA                                                         //~va00I~
    UCHAR  *flddata,*flddbcs;                                      //~v10MI~
    UCHAR cmdlinewk[UPCCMDFLDWKSZ];                                //~v749I~
#endif                                                             //~va00I~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
  	int wxesw;                                                     //~v500I~
    char *pdata=NULL,*pdbcs=NULL;                                            //~v500I~//~vaf9R~
#endif                                                             //~v500I~
	int swutilfld;                                                 //~v76jI~
#ifdef UTF8SUPPH                                                   //~va00I~
    char *psrcdata,*psrcdbcs;                                      //~va00R~
  	int opt;                                                       //~va00I~
#endif                                                             //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8data,u8len,lclen,rc2,swkbdu8;                        //~va20R~
    char *pcbdata=NULL,*pcbdbcs=NULL;                                        //~va20R~//~vaf9R~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5AI~//~va5DI~
	int swebcdata=0;                                               //~va5AR~//~va5DM~
    int handle=0;                                                    //~va79I~//~vaf9R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5AI~//~va5DI~
    int swrenamefld;                                               //~vawcI~
//*******************                                              //~v10MI~
    cposx=Ppcw->UCWrcsrx;                                          //~v10MI~
    cposy=Ppcw->UCWrcsry;                                          //~v76bI~
	swutilfld=(cposy!=CMDLINENO)                                   //~v76jR~
              && ((((PUPANELC)Ppcw->UCWppc)->UPCid) & PANUTIL);//utility panel field//~v76jI~
	swrenamefld=((((PUPANELC)Ppcw->UCWppc)->UPCid)==PANDIR)//utility panel field//~vawcI~
    		    && 	(Pfldno=PANL310RENAME);                        //~vawcI~
	if ((offs=cposx-Ppflde->UFLstart)<0                            //~v10MI~
    ||	cposx>=Ppflde->UFLend)                                     //~v10MI~
		return -1;           				//msg csr pos err at return//~v10MI~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
  	wxesw=(Gwxestat & GWXES_MOUSECAPPASTE);		//flag for xecap,req callback//~v500I~
  if (!wxesw)                                                      //~v500I~
#endif                                                             //~v500I~
    if (Gcappcw)                                                   //~v10MI~
    {                                                              //~v10MI~
		if (!UCBITCHK(Sblockstat,SBLOCKCLOSED))	//block not closed //~v10MI~
			return capnoblockerr();                                //~v10MI~
		if (!UCBITCHK(Sblockstat,SBLOCKSAVED))	//block not saved  //~v10MI~
			if (capsavedata(Gcappcw))                              //~v10MI~
				return 4;                                          //~v10MI~
	        capreset(1);                                           //~v10MI~
    }                                                              //~v10MI~
                                                                   //~v10MI~
//copysub                                                          //~v10MI~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
  	if (wxesw)                                                     //~v500I~
    {                                                              //~v500I~
//  	if (wxe_cappastecallback(0,&pdata,&pdbcs,&copylen,0,0,0,0))//get windows clipboard data//~v50tR~
    	if (wxe_cappastecallback(0,0,&pdata,&pdbcs,&copylen,0,0,0,0))//get windows clipboard data//~v50tI~
        	copylen=0;                                             //~v500I~
#ifdef UTF8UCS2                                                    //~va20I~
        pcbdata=pdata;	//clipboard data may be dd fmt             //~va20I~
        pcbdbcs=pdbcs;                                             //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5DI~
		swebcdata=(Gwxestat & GWXES_CPDATAEBC);     		//daat is unicodetextcallback//~va5DI~
  		handle=Gwxecapebchandle;                                   //~va7AI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5DI~
    }                                                              //~v500I~
    else                                                           //~v500I~
#endif                                                             //~v500I~
	if (capgetdata(Ppcw,&plh1,&plh2)) 		//clipboard data       //~v10MI~
    {                                                              //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5DI~
		swebcdata=PLH_ISEBC(plh1);                                 //~va5DI~
  		handle=UGETPFH(plh1)->UFHhandle;                           //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va5DI~
    	for (plh=plh1;plh;plh=UGETQNEXT(plh))                      //~v10MI~
        {                                                          //~v10MI~
#ifdef UTF8UCS2                                                    //~va20I~
        	pcbdata=plh->ULHdata;	//clipboard data may be dd fmt //~va20R~
        	pcbdbcs=plh->ULHdbcs;                                  //~va20R~
#endif                                                             //~va20I~
    		if (copylen=plh->ULHlen,copylen)                       //~v10MI~
            	break;                                             //~v10MI~
            if (plh==plh2)                                         //~v10MI~
            	break;                                             //~v10MI~
        }                                                          //~v10MI~
    }                                                              //~va20I~
	else                                                           //~v10MI~
    	copylen=0;                                                 //~v10MI~
    if (!copylen)                                                  //~v10MI~
	{                                                              //~v10MI~
//  	uerrmsg("No clip board data",                              //~v10MI~//~va0uR~
//  			"\x93\\付データがありません");                     //~v10MI~//~va0uR~
    	uerrmsg("No clip board data, or 1st line is NULL line.",   //~va0uI~
    			"\x93\\付データがないか、最初がNULL行です");       //~va0uI~
		return 4;                                                  //~v10MI~
	}                                                              //~v10MI~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5DI~
    swutf8data=0;                                                  //~va5DI~
  if (swebcdata)                                                   //~va5DI~
  {                                                                //~va5DI~
    	opt=XEEBCO_DROPSOSI|XEEBCO_ERRREP;//delete so/si at B2M    //~va5DI~
//  	if ((rc2=xeebc_b2fl(opt,pcbdata,pcbdbcs,copylen,           //~va5DR~//~va79R~
    	if ((rc2=xeebc_b2fl(opt,handle,pcbdata,pcbdbcs,copylen,    //~va79I~
				Gcmdbuffu8,sizeof(Gcmdbuffu8),&u8len,              //~va5DI~
				Gcmdbufflc,Gcmdbuffdbcs,Gcmdbuffct,sizeof(Gcmdbufflc),&lclen))>=4)//~va5DI~
        	return 4;                                              //~va5DI~
        swkbdu8=((rc2/*f2l err*/)||(Gutfmode2 & GUM2_KBDUTF8/*kbd utf8 mode*/));//~va5DI~
        Gcmdbufflclen=lclen;                                       //~va5DI~
        pcbdbcs=Gcmdbuffdbcs;                                      //~va5DI~
		if (swkbdu8) //kbd:lc and b2l cv err                       //~va79R~
  			if (cposy!=CMDLINENO//paste to cmdline                 //~va79I~
			&&  getfldutf8(Ppcw,cposy,Pfldno,0/*Pputf8*/,0/*Ppcodetype*/)	//has no utf8 data save area//~va79I~
            )                                                      //~va79I~
        		swkbdu8=0;                                         //~va79R~
        if (swkbdu8)                                               //~va5DI~
        {                                                          //~va5DI~
            copylen=u8len;                                         //~va5DI~
            pcbdata=Gcmdbuffu8;                                    //~va5DI~
        }                                                          //~va5DI~
        else                                                       //~va5DI~
        {                                                          //~va5DI~
            copylen=lclen;                                         //~va5DI~
            pcbdata=Gcmdbufflc;                                    //~va5DI~
        }                                                          //~va5DI~
  }                                                                //~va5DI~
  else                                                             //~va5DI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5DI~
	swutf8data=pcbdbcs && utfchkdd(0,pcbdbcs,copylen);             //~va20R~
    if (swutf8data)                                                //~va20I~
    {                                                              //~va20I~
    	opt=XEUTFDD2FLO_U8ERRMSG;	//      0x01 //register utf8 code for errmsg//~va20I~
		if ((rc2=xeutfcvdd2fl(opt,Ppcw,pcbdata,pcbdbcs,copylen,    //~va20R~
				Gcmdbuffu8,sizeof(Gcmdbuffu8),&u8len,              //~va20I~
				Gcmdbufflc,Gcmdbuffdbcs,Gcmdbuffct,sizeof(Gcmdbufflc),&lclen))>=4)//~va20R~
            return 4;                                              //~va20I~
#ifdef LNX                                                         //~vaubI~
        swkbdu8=1;	//set by utf8 if not into file area            //~vaubI~
#else                                                              //~vaubI~
        swkbdu8=((rc2/*f2l err*/)||(Gutfmode2 & GUM2_KBDUTF8/*kbd utf8 mode*/));//~va20R~
#endif                                                             //~vaubI~
        Gcmdbufflclen=lclen;                                       //~va20I~
        pcbdbcs=Gcmdbuffdbcs;                                      //~va20I~
        if (swkbdu8)                                               //~va20I~
        {                                                          //~va20I~
            copylen=u8len;                                         //~va20R~
            pcbdata=Gcmdbuffu8;                                    //~va20R~
        }                                                          //~va20I~
        else                                                       //~va20I~
        {                                                          //~va20I~
            copylen=lclen;                                         //~va20I~
            pcbdata=Gcmdbufflc;                                    //~va20I~
        }                                                          //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    	swkbdu8=0;                                                 //~va20I~
#endif                                                             //~va20I~
//  if (!(fldlen=getfldpos(Ppcw,CMDLINENO,0,&flddata,&flddbcs)))	//no dbcs parm//~v76bR~
//--ifndef------------                                             //~va5DI~
#ifndef UTF8SUPPH                                                  //~va00I~
  if (swutilfld)                                                   //~v76jI~
  {                                                                //~v76jI~
	if (panutildataproc(PANUO_GETLINE|PANUO_FLDTOP,Ppcw,(char**)(&flddata),(char**)(&flddbcs),&fldlen))//~v76jR~
    	return -1;				//fld top addr                     //~v76jI~
  }                                                                //~v76jI~
  else                                                             //~v76jI~
  {                                                                //~v76jI~
    if (!(fldlen=getfldpos(Ppcw,cposy,Pfldno,&flddata,&flddbcs)))	//no dbcs parm//~v76bI~
    	return -1;				//fld top addr                     //~v10MI~
  }                                                                //~v76jI~
#endif                                                             //~va00R~
//--------------------                                             //~va5DI~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
  if (!wxesw)                                                      //~v500R~
#endif                                                             //~v500I~
	if (!plh->ULHdbcs)	//not once displayed                       //~v10MM~
		if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len   //~v10MM~
        	return UALLOC_FAILED;                                  //~v10MM~
//---ifndef-----------                                             //~va5DI~
#ifndef UTF8SUPPH                                                  //~va00R~
	oldlen=(int)strlen(flddata);                                   //~v10MI~
    reslen=oldlen-offs;                                            //~v10MI~
	newlen=offs;                                                   //~v10MI~
    if (Pinsopt)                                                   //~v10MI~
    	newlen+=copylen+max(reslen,0);                             //~v10MI~
    else                                                           //~v10MI~
    	newlen+=(max(copylen,reslen));                             //~v10MI~
  if (!swutilfld)                                                  //~v76jI~
  {                                                                //~v76jI~
    strncpy(cmdlinewk,flddata,sizeof(cmdlinewk));                  //~v749M~
//  fldlen=MAXCOLUMN;                                              //~v749M~//~va04R~
    fldlen=UPCCMDFLDWKNETSZ;                                       //~va04I~
    flddata=cmdlinewk;	//data concat on work                      //~v749M~
  }                                                                //~v76jI~
	if (newlen>fldlen)                                             //~v10MI~
    {                                                              //~v10MI~
    	rc=charfieldfullerr();                                     //~v10MR~
        newlen=fldlen;                                             //~v76jI~
	}                                                              //~v10MI~
    if (reslen<0)  	//csr over curr len                            //~v10MI~
    {                                                              //~v10MI~
		memset(flddata+oldlen,' ',(UINT)(-reslen));                //~v10MI~
//  	memset(flddbcs+oldlen,0,(UINT)(-reslen));                  //~v749R~
    }                                                              //~v10MI~
    if (Pinsopt)                                                   //~v10MI~
    	if (reslen>0)                                              //~v10MI~
        {                                                          //~v10MI~
//      	if ((availlen=fldlen-offs-copylen)<reslen)             //~v502R~
        	availlen=fldlen-offs-copylen;                          //~v502I~
          if (availlen>0)                                          //~v502I~
          {                                                        //~v502I~
        	if (availlen<reslen)                                   //~v502I~
            	reslen=availlen;                                   //~v10MI~
            memmove(flddata+offs+copylen,flddata+offs,(UINT)reslen);//~v10MI~
//          memmove(flddbcs+offs+copylen,flddbcs+offs,(UINT)reslen);//~v749R~
          }//avail len                                             //~v502I~
		}                                                          //~v10MI~
    if ((availlen=fldlen-offs)<copylen)                            //~v10MR~
    	copylen=availlen;                                          //~v10MI~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
  if (wxesw)                                                       //~v500I~
  {                                                                //~v500I~
	memcpy(flddata+offs,pdata,(UINT)copylen);                      //~v500I~
//  memcpy(flddbcs+offs,pdbcs,(UINT)copylen);                      //~v749R~
    ufree(pdbcs);                                                  //~v500I~
  }                                                                //~v500I~
  else                                                             //~v500I~
  {                                                                //~v500I~
#endif                                                             //~v500I~
	memcpy(flddata+offs,plh->ULHdata,(UINT)copylen);               //~v10MI~
//  memcpy(flddbcs+offs,plh->ULHdbcs,(UINT)copylen);               //~v749R~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
  }                                                                //~v500I~
#endif                                                             //~v500I~
//  if (!Pinsopt)                                                  //~v749R~
//      if (copylen<reslen)     //more residual                    //~v749R~
//  		setobtabdbcs(flddata,flddbcs,oldlen,offs,copylen);     //~v749R~
//  if (newlen>fldlen)                                             //~v749R~
//      setdbcssplit(flddata,flddbcs,fldlen,' ');	//clear dbcs id for dbcs chardel at end of fld abend//~v749R~
//  setflddata(Ppcw,CMDLINENO,0,cmdlinewk);                        //~v76bR~
  if (swutilfld)                                                   //~v76jI~
  {                                                                //~v76jI~
  	*(flddata+newlen)=0;                                           //~v76jR~
	panutildataproc(PANUO_SETFLD|PANUO_SETSAVE,Ppcw,0,0,0);        //~v76jI~
  }                                                                //~v76jI~
  else                                                             //~v76jI~
    setflddata(Ppcw,cposy,Pfldno,cmdlinewk);                       //~v76bI~
#endif //!UTF8SUPPH                                                //~va00R~
//--------------------                                             //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
#ifdef UTF8UCS2                                                    //~va20M~
    if (swutf8data)                                                //~va20I~
    {                                                              //~va20I~
        psrcdata=pcbdata;                                          //~va20R~
        psrcdbcs=pcbdbcs;                                          //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
#endif                                                             //~va20M~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5DI~
    if (swebcdata)                                                 //~va5DI~
    {                                                              //~va5DI~
        psrcdata=pcbdata;                                          //~va5DI~
        psrcdbcs=pcbdbcs;                                          //~va5DI~
    }                                                              //~va5DI~
    else                                                           //~va5DI~
#endif                                                             //~va5DI~
#ifdef WXEXXE                                                      //~va00M~
    if (wxesw)                                                     //~va00M~
    {                                                              //~va00M~
        psrcdata=pdata;                                            //~va00M~
        psrcdbcs=pdbcs;                                            //~va00M~
    }                                                              //~va00M~
    else                                                           //~va00M~
#endif                                                             //~va00M~
    {                                                              //~va00M~
        psrcdata=plh->ULHdata;                                     //~va00M~
        psrcdbcs=plh->ULHdbcs;                                     //~va00M~
    }                                                              //~va00M~
    opt=0;                                                         //~va00I~
  	if (cposy==CMDLINENO)//paste to cmdline                        //~va00M~
    {                                                              //~va00M~
    	if (Pinsopt)                                               //~va00M~
    		opt|=SFDDCUO_INS;                                      //~va00M~
#ifdef UTF8UCS2                                                    //~va20I~
    	if (swkbdu8)                                               //~va20R~
    		opt|=SFDDCUO_SETCT2;	//pass lc by Gcmdbuff          //~va20I~
#endif                                                             //~va20I~
		opt|=SFDDCUO_CAP;                                          //~vaarI~
		setflddatadbcscmd_byutf8(opt,Ppcw,offs,psrcdata,psrcdbcs,copylen);//~va00M~
        rc=0;                                                      //~va00I~
    }                                                              //~va00M~
    else                                                           //~va00I~
  	if (swutilfld)                                                 //~va00M~
    {                                                              //~va00M~
    	if (Pinsopt)                                               //~va00M~
    		opt|=PUFU8O_INS;                                       //~va00M~
#ifdef UTF8UCS2                                                    //~va20I~
    	if (swkbdu8)                                               //~va20R~
    		opt|=PUFU8O_SETCT2;	//pass lc by Gcmdbuff              //~va20I~
#endif                                                             //~va20I~
		rc=panutilfldupdate_utf8(opt,Ppcw,cposy,Pfldno,offs,psrcdata,copylen,psrcdbcs);//~va00I~
    }                                                              //~va00M~
    else                                                           //~vawcI~
  	if (swrenamefld)                                               //~vawcI~
    {                                                              //~vawcI~
    	int opt2=0;                                                //~vawcI~
	    if (swutf8data)                                            //~vawcI~
//      	opt2|=DRFPO_U8;                                        //~vawkR~
        	opt2|=DRFPO_U8|DRFPO_SETCT2; 	//Gcmdbufflc/Gcmdbuffct//~vawkI~
        else                                                       //~vawcI~
	    if (swebcdata)                                             //~vawcI~
        	opt2|=DRFPO_EBC;                                       //~vawcI~
        if (Pinsopt)                                               //~vawcI~
        	opt2|=DRFPO_INS;                                       //~vawcI~
    	rc=dirpasterenamefld(opt2,Ppcw,psrcdata,psrcdbcs,offs,copylen);//~vawcI~
    }                                                              //~vawcI~
    else                                                           //~va00M~
    {                                                              //~va00M~
    	if (Pinsopt)                                               //~va00M~
    		opt|=P3FU8O_INS;                                       //~va00M~
#ifdef UTF8UCS2                                                    //~va20I~
    	if (swkbdu8)                                               //~va20R~
    		opt|=P3FU8O_SETCT2;	//pass lc by Gcmdbuff              //~va20I~
#endif                                                             //~va20I~
		rc=pan300fldupdate_utf8(opt,Ppcw,cposy,Pfldno,offs,psrcdata,copylen,psrcdbcs);//~va00I~
    }                                                              //~va00M~
#ifdef WXEXXE                                                      //~va00I~
  	if (wxesw)                                                     //~va00I~
    	ufree(pdbcs);                                              //~va00I~
#endif //WXEXXE                                                    //~va20I~
#endif  //UTF8SUPPH                                                //~va00I~
	return rc;                                                     //~v10MR~
}//captofld                                                        //~v10MI~
//*******************************************************       //~5520I~
//!capcopysub
//* block copy sub                                              //~5520I~
//* parm1:pcw                                                   //~5520I~
//* parm2:insert option 0- rep 1:insert                         //~5520I~
//* retrn:rc                                                    //~5520I~
//*******************************************************       //~5520I~
int capcopysub(PUCLIENTWE Ppcw,int Pinsopt)                     //~5520I~
{                                                               //~5520I~
	ULCMD  *plc;                                                //~5520I~
	PULINEH plh1=NULL,plh2=NULL,plh;                                      //~v06hR~//~vaf9R~
	int rc;                                                     //~5520I~
//*******************                                           //~5520I~
                                                                //~5520I~
  if (!Spendfcmd)	//normal cat & paste	                    //~v06hI~
  {                                                             //~v06hI~
	if (!capgetdata(Ppcw,&plh1,&plh2))		//no clipboard data //~5520I~
	{                                                           //~5520I~
		uerrmsg("No clip board data",                           //~5520I~
//  			"貼付データがありません");                         //~v095R~
    			"\x93\\付データがありません");                     //~v095I~
		return 4;                                               //~5520I~
	}                                                           //~5520I~
  }	//normal cat & paste	                                    //~v06hI~
                                                                //~5520I~
	if (((FUNCTBL*)(Ppcw->UCWpfunct))->FTfuncid==FUNCID_BLOCKREPSPACE)//~v06eR~
		plc=lcmdgetdummyplc(Ppcw,'O');	//destination Paste     //~v06eI~
	else                                                        //~v06eI~
	if (Pinsopt && (Ppcw->UCWrcsrx<Ppcw->UCWlinenosz || Pinsopt==2))//~v06lR~
//  ||  ((FUNCTBL*)(Ppcw->UCWpfunct))->FTfuncid==FUNCID_LINECOPY)//~v06lR~
		plc=lcmdgetdummyplc(Ppcw,'A');	//destination After     //~5520I~
    else                                                        //~5520I~
		plc=lcmdgetdummyplc(Ppcw,'P');	//destination Paste     //~5520I~
	plc->ULCplh=plh=(Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc;    //~v06hR~
  if (!Spendfcmd)	//normal cat & paste	                    //~v06hI~
  {                                                             //~v06hI~
	if (Pinsopt)                                                //~5520I~
	{                                                           //~5520I~
		UCBITON(plc->ULCflag2,ULCF2CAPINS);                     //~5520I~
		UCBITOFF(plc->ULCflag2,ULCF2CAPREP);                    //~5520I~
	}                                                           //~5520I~
	else                                                        //~5520I~
	{                                                           //~5520I~
		UCBITOFF(plc->ULCflag2,ULCF2CAPINS);                    //~5520I~
		UCBITON(plc->ULCflag2,ULCF2CAPREP);                     //~5520I~
	}                                                           //~5520I~
                                                                //~5520I~
	rc=lcmdcopy(Ppcw,plh1,plh2,1,plc);                          //~5520I~
    if (UCBITCHK(plc->ULCflag2,ULCF2MERGINERR))                    //~v0bgI~
    	rc=4;                                                      //~v0bgI~
  }	//normal cat & paste	                                    //~v06hI~
  else                                                          //~v06hI~
  {                                                             //~v06hI~
	capfcmdi(Ppcw,plh,1);                                       //~v06iR~
    *plh->ULHlinecmd=plc->ULCcmd;                               //~v06iR~
	UCBITON(plh->ULHflag,ULHFDRAW);//draw word after wordrep       //~vb84I~
    rc=func_copy_file(Ppcw);	//file cmd call                 //~v06hI~
    UCBITOFF(plh->ULHflag3,ULHF3TEMPLCMD);//not saved at savependlcmd//~v06hR~
  }                                                             //~v06hI~
	return rc;                                                  //~5520I~
}//capcopysub                                                   //~5520I~
                                                                //~5520I~
//*******************************************************       //~v06hI~
//!capfcmdi
//* COPY/MOVE fcmd interface(drop file cmd verb)                //~v06hR~
//* parm1:pcw                                                   //~v06hI~
//* parm2:plh                                                   //~v06hR~
//* parm3:cmd verv drop option                                  //~v06iI~
//* retrn:none                                                  //~v06hI~
//*******************************************************       //~v06hI~
void capfcmdi(PUCLIENTWE Ppcw,PULINEH Pplh,int Pverbopt)        //~v06iR~
{                                                               //~v06hI~
    PUFILEH pfh;                                                //~v06hI~
    char *pc;                                                   //~v06hI~
//*******************                                           //~v06hI~
//*drop cmd verb                                                //~v06hI~
	if (Pverbopt)                                               //~v06iI~
    {                                                           //~v06iI~
	    pc=Ppcw->UCWparm;                                       //~v06iR~
    	if (pc)                                                 //~v06iR~
	    {                                                       //~v06iR~
		    if (pc=strchr(pc,' '),pc)	//first non space       //~v06iR~
        		pc+=strspn(pc," ");		//non space pos         //~v06iR~
	        Ppcw->UCWparm=pc;                                   //~v06iR~
		}                                                       //~v06iR~
    }                                                           //~v06iI~
    pfh=UGETPFH(Pplh);                                          //~v06hR~
//same as xechar                                                //~v06hI~
	if (!UCBITCHK(Pplh->ULHflag,ULHFLINECMD))	//not yet lcmd input//~v06hR~
    {                                                           //~v06hI~
		UCBITOFF(pfh->UFHflag2,UFHF2LCMDCOMP);//need command process//~vb84I~
		UCBITON(Pplh->ULHflag,ULHFLINECMD);//line cmd input     //~v06hR~
		pfh->UFHcmdline[pfh->UFHcmdlinectr++]=Pplh;	//save cmd line//~v06iR~
	    UTRACEP("@@@1 %s:add %c cmd,cmdlinectr=%d\n",UTT,*Pplh->ULHlinecmd,pfh->UFHcmdlinectr);//~vb25I~
                                                                   //~vb84I~
	}                                                           //~v06hI~
    UCBITON(Pplh->ULHflag3,ULHF3TEMPLCMD); //not saved at savependlcmd//~v06iR~
    memset(Pplh->ULHlinecmd,0,sizeof(Pplh->ULHlinecmd));        //~v06iR~
    return;                                                     //~v06hI~
}//capfcmdi                                                     //~v06hI~
                                                                //~v06hI~
//*******************************************************       //~v06hI~
//!capfcmdi2
//* REP/CRE fcmd interface(drop file cmd verb)                  //~v06hI~
//* parm1:pcw                                                   //~v06hI~
//* parm2:REP(1)/CRE(2)/APP(3)                                     //~v0iaR~
//* retrn:none                                                  //~v06hI~
//*******************************************************       //~v06hI~
int capfcmdi2(PUCLIENTWE Ppcw,char Prepcre,int Popdsw)          //~v06lR~
{                                                               //~v06hI~
    int rc;                                                     //~v06iR~
//*******************                                           //~v06hI~
//*drop cmd verb                                                //~v06hI~
	capfcmdi(Ppcw,Gcapplh1,Popdsw);	//init plh1,drop cmd verb   //~v06lR~
    *((PULINEH)Gcapplh1)->ULHlinecmd=ULCCMDCOPY;                //~v06iR~
    if (Gcapplh2!=Gcapplh1)     //multiple line                 //~v06lI~
    {                                                           //~v06lI~
	    *(((PULINEH)Gcapplh1)->ULHlinecmd+1)=ULCCMDCOPY;        //~v06lR~
		capfcmdi(Ppcw,Gcapplh2,0);	//init plh2,no drop cmd verb//~v06lR~
	    *((PULINEH)Gcapplh2)->ULHlinecmd=ULCCMDCOPY;            //~v06lR~
	    *(((PULINEH)Gcapplh2)->ULHlinecmd+1)=ULCCMDCOPY;        //~v06lR~
    }                                                           //~v06lI~
    rc=fcmdfileout(Ppcw,(int)Prepcre);	//file cmd call         //~v06iR~
    UCBITOFF(((PULINEH)Gcapplh1)->ULHflag3,ULHF3TEMPLCMD);//not saved at savependlcmd//~v06iR~
    UCBITOFF(((PULINEH)Gcapplh2)->ULHflag3,ULHF3TEMPLCMD);//not saved at savependlcmd//~v06iR~
    funcopdpostp(Ppcw,rc); //cmd line clear etc                 //~v06iR~
	capreset(1);		//reset cut and paste(reset plh)        //~v06iI~
    return rc;                                                  //~v06iR~
}//capfcmdi2                                                    //~v06iR~
                                                                //~v06hI~
//*******************************************************       //~v06lI~
//!capfcmdi3
//* REP/CRE fcmd interface from fcmdcalllcmd                    //~v06lI~
//* output file from line mode cap range                           //~vb24I~
//* parm1:pcw                                                   //~v06lI~
//* parm2:cmd id REP(1)/CRE(2)/APP(3)                              //~v0iaR~
//* retrn:1:no pending line closed box,other rc of fcmdfileout  //~v06lI~
//*******************************************************       //~v06lI~
int capfcmdi3(PUCLIENTWE Ppcw,char Prepcre)                     //~v06lI~
{                                                               //~v06lI~
//*******************                                           //~v06lI~
	if (Ppcw!=Gcappcw                       //same line         //~v06lI~
	||  !UCBITCHK(Sblockstat,SBLOCKCLOSED) 	//not closed        //~v06lI~
	||  UCBITCHK(Sblockstat,SBLOCKMODE))	//line mode         //~v06lI~
    	return 1;		//err msg to req specify range          //~v06lI~
	return capfcmdi2(Ppcw,Prepcre,0);	//no drop opd           //~v06lR~
}//capfcmdi3                                                    //~v06lI~
                                                                //~v06lI~
//*******************************************************       //~v06lI~
//!func_lineexclude_file
//* exclude                                                     //~v06lI~
//* parm1:pcw                                                   //~v06lI~
//* retrn:rc                                                    //~v06lI~
//*******************************************************       //~v06lI~
int func_lineexclude_file(PUCLIENTWE Ppcw)                      //~v06lR~
{                                                               //~v06lI~
    PULINEH plh1,plh2;                                          //~v06lI~
    int rc;                                                     //~v06lI~
//*******************                                           //~v06lI~
	plh1=capgetcsrplh(Ppcw);                                    //~v06lR~
	if (Ppcw!=Gcappcw                       //not started       //~v06lI~
	||  UCBITCHK(Sblockstat,SBLOCKMODE))	//line mode         //~v06lI~
    {                                                           //~v06lI~
        if (!plh1)                                              //~v06lI~
//  		return capcsrposerr();                                 //~v0i8R~
	  		return errcsrpos();                                    //~v0i8I~
		plh2=plh1;                                              //~v06lR~
    }                                                           //~v06lI~
    else                                                        //~v06lI~
		if (!UCBITCHK(Sblockstat,SBLOCKCLOSED)) 	//not closed//~v06lI~
        {                                                       //~v06lI~
	        if (!plh1)                                          //~v06lI~
//  			return capcsrposerr();                             //~v0i8R~
	  			return errcsrpos();                                //~v0i8I~
            plh2=Gcapplh1;                                      //~v06lR~
	    }                                                       //~v06lI~
    	else                                                    //~v06lI~
	    {                                                       //~v06lI~
    		plh1=Gcapplh1;                                      //~v06lI~
    		plh2=Gcapplh2;                                      //~v06lI~
	    }                                                       //~v06lI~
	capfcmdi(Ppcw,plh1,0);	//init plh1,no drop cmd verb        //~v06lI~
    *plh1->ULHlinecmd=ULCCMDEXCLUDE;                            //~v06lI~
    if (plh2!=plh1)     //multiple line                         //~v06lI~
    {                                                           //~v06lI~
	    *(plh1->ULHlinecmd+1)=ULCCMDEXCLUDE;                    //~v06lI~
		capfcmdi(Ppcw,plh2,0);	//init plh2,no drop cmd verb    //~v06lI~
	    *plh2->ULHlinecmd=ULCCMDEXCLUDE;                        //~v06lI~
	    *(plh2->ULHlinecmd+1)=ULCCMDEXCLUDE;                    //~v06lI~
    }                                                           //~v06lI~
    rc=filelinecmd(Ppcw);	//lcmd call                         //~v06lI~
    UCBITOFF(plh1->ULHflag3,ULHF3TEMPLCMD);//not saved at savependlcmd//~v06lI~
    UCBITOFF(plh2->ULHflag3,ULHF3TEMPLCMD);//not saved at savependlcmd//~v06lI~
	capreset(1);		//reset cut and paste(reset plh)        //~v06lI~
    return rc;                                                  //~v06lI~
}//func_lineexclude_file                                        //~v06lR~
                                                                //~v06lI~
//*******************************************************       //~v06lI~
//!func_lineinclude_file
//* include                                                     //~v06lI~
//* parm1:pcw                                                   //~v06lI~
//* retrn:rc                                                    //~v06lI~
//*******************************************************       //~v06lI~
int func_lineinclude_file(PUCLIENTWE Ppcw)                      //~v06lR~
{                                                               //~v06lI~
    PULINEH plh;                                                //~v06lI~
    int rc;                                                     //~v06lI~
//*******************                                           //~v06lI~
	if (!(plh=capgetcsrplh(Ppcw))                               //~v06lR~
    ||  plh->ULHtype!=ULHTEXCLUDE)                              //~v06lI~
//  	return capcsrposerr();                                     //~v0i8R~
		return errcsrpos();                                        //~v0i8I~
	capfcmdi(Ppcw,plh,0);	//init plh1,no drop cmd verb        //~v06lI~
    switch(((FUNCTBL*)(Ppcw->UCWpfunct))->FTfuncid)             //~v06lI~
    {                                                           //~v06lI~
	case FUNCID_LINEINCF:                                       //~v06lI~
	    *plh->ULHlinecmd=ULCCMDINCF;                            //~v06lI~
    	break;                                                  //~v06lI~
	case FUNCID_LINEINCL:                                       //~v06lI~
	    *plh->ULHlinecmd=ULCCMDINCL;                            //~v06lI~
    	break;                                                  //~v06lI~
	default:                                                    //~v06lR~
	    *plh->ULHlinecmd=ULCCMDINCLUDE;                         //~v06lR~
    	break;                                                  //~v06lI~
    }                                                           //~v06lI~
    rc=filelinecmd(Ppcw);	//lcmd call                         //~v06lI~
    UCBITOFF(plh->ULHflag3,ULHF3TEMPLCMD);//not saved at savependlcmd//~v06lI~
    return rc;                                                  //~v06lI~
}//func_lineinclude_file                                        //~v06lR~
                                                                //~v06lI~
//*******************************************************
//!capgetdata
//* get clipboard data
//* parm1:pcw
//* retrn:top line plh
//*******************************************************
PUFILEH capgetdata(PUCLIENTWE Ppcw,PULINEH *Ppplh1,PULINEH *Ppplh2)
{
 	PUFILEH  pfh;
//*******************
//  if (!(pfh=capgetpfh(Ppcw)))                                    //~va7AR~
    if (!(pfh=capgetpfh(0,Ppcw)))                                  //~va7AI~
		return 0;
	if (UGETQCTR(&pfh->UFHlineque)==2)
		return 0;				//no line data
  	if (filepfhchktabdbcs(pfh))	//confirm dbcs	data               //~v66hI~
  		return 0;                                                  //~v66hI~
	*Ppplh1=UGETQNEXT(UGETQTOP(&pfh->UFHlineque));	//top data
	*Ppplh2=UGETQPREV(UGETQEND(&pfh->UFHlineque));	//top data
	return pfh;
}//capgetdata

//*******************************************************
//!capgetpfh
//* get clipboard pfh
//* parm1:pcw
//* retrn:pfh
//*******************************************************
//PUFILEH capgetpfh(PUCLIENTWE Ppcw)                               //~va7AR~
PUFILEH capgetpfh(int Popt,PUCLIENTWE Ppcw)                        //~va7AI~
{
 	PUCLIENTWE pcw;
 	PUFILEH  pfh;
//  UCHAR  fullpath[_MAX_PATH];                                    //~v54hR~
    UCHAR  fpath[_MAX_PATH];                                       //~v54hI~
    UCHAR  cbwithmt[_MAX_PATH];                                    //~v697I~
    int rc;                                                     //~5228R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int ccbstat;                                                   //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//    int posx,posy;                                            //~5228I~
	int handle;                                                    //~va79I~
    CBSTAT cbsrec;                                                 //~va79I~
//*******************
//  if (filesrchpfh(Scbfnm,fullpath,&pfh)//not found on fileq or err//~v54hR~
    if (filesrchpfh(Scbfnm,fpath,&pfh)//not found on fileq or err  //~v54hI~
	||  !pfh->UFHeditpcw)	//browse only
	{
//  	Ppcw->UCWparm=Scbfnm;                                      //~v697R~
        strcpy(cbwithmt,Scbfnm);                                   //~v697I~
        strcat(cbwithmt," /MT");                                   //~v697I~
	 if (Popt & CAPGPFO_SAVE)   //old data is not required because immediately deleted at data save operation//~va7AI~
     {                                                             //~va7AI~
        strcat(cbwithmt," " MODE_LOCALE);	//load without translation//~va7AI~
     }                                                             //~va7AI~
     else                                                          //~va7AI~
     {                                                             //~va7AI~
#ifdef UTF8SUPPH                                                   //~va00I~
#ifdef UTF8UCS2    	                                               //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//    if ((ccbstat=capcbstatr(0,Ppcw)) & CCBSTF_CPEB)              //~va50I~//~va79R~
//    if ((ccbstat=capcbstatr(0,Ppcw,&cbsrec)) & CCBSTF_CPEB)      //~va79I~//~vb2DR~
      if ((ccbstat=(int)capcbstatr(0,Ppcw,&cbsrec)) & CCBSTF_CPEB) //~vb2DI~
      {                                                            //~va79I~
        handle=CCBSTF_GETHANDLE(ccbstat);                          //~va79M~
       if (handle)                                                 //~va79I~
        sprintf(cbwithmt+strlen(cbwithmt)," " MODE_EBC "=%s " MODE_IE,cbsrec.CBSTcvname);//~va79R~
       else                                                        //~va79I~
        strcat(cbwithmt," " MODE_EBC " " MODE_IE);                 //~va50R~
      }                                                            //~va79I~
      else                                                         //~va50I~
      if (ccbstat & CCBSTF_CPU8)                                   //~va50I~
#else                                                              //~va50I~
      if (capcbstatr(0,Ppcw) & CCBSTF_CPU8)	                       //~va20R~//~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        strcat(cbwithmt," " MODE_UTF8 " " MODE_IE);                //~va20R~
      else                                                         //~va20I~
#endif                                                             //~va20I~
        strcat(cbwithmt," " MODE_LOCALE);                          //~va00R~
#endif                                                             //~va00I~
     }//no save but get                                            //~va7AI~
    	Ppcw->UCWparm=cbwithmt;                                    //~v697I~
//        posx=Gcsrposx;		//func_edit_file set csr pos by csrhomepos//~5228R~
//        posy=Gcsrposy;	                                    //~5228R~
//  	rc=func_edit_file2(Ppcw,0);	//file name only               //~v697R~
    	rc=func_edit_file2(Ppcw,1);	//file name with option parm /MT//~v697I~
//        Gcsrposx=posx;		//restore current pos           //~5228R~
//        Gcsrposy=posy;	                                    //~5228R~
		Ppcw->UCWparm=0;        //worked                        //~5504I~
		if (rc)                                                 //~5226I~
			return 0;
//		scrpopup((PUCLIENTWE)-1,&pcw);//get edit pcw,pop myself //~5228R~//~vafkR~
		scrpopup((PUCLIENTWE)(ULPTR)-1,&pcw);//get edit pcw,pop myself//~vafkI~
//		Gcapcbpcw=pcw;			//save cb edit pcw                 //~v66jR~
  		Gcapcbpcw=pcw;			//save cb edit pcw                 //~v675I~
		pfh=((PUFILEC)pcw->UCWpfc)->UFCpfh;
//  	if (filepfhchktabdbcs(pfh))	//set all line dbcs	at init    //~v66hR~
//  		return 0;                                              //~v66hR~
	}
//  Gcapcbpcw=pfh->UFHeditpcw;			//save cb edit pcw         //~v66jR~ //del//~v675R~
#ifdef WXEXXE                                                      //~v675I~
    Gcapcbpfh=pfh;			//for xei2                             //~v675R~
#endif                                                             //~v675I~
	return pfh;
}//capgetpfh

//*******************************************************
//!capsavedata
//* save clipboard data
//* parm1:pcw
//* retrn:rc
//*******************************************************
int capsavedata(PUCLIENTWE Ppcw)
{
	ULCMD  *plc;
	PULINEH plh1,plh2,plh,plhwk;
	PULINEH endplh;                                                //~v66fI~
 	PUFILEH  pfh,pfhs;                                             //~v418R~
 	PUCLIENTWE pcw;
	int blocksw,len,rc=0;                                          //~v500R~
    int addsosi;                                                   //~vagDI~
//*******************
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
  if (!(Gwxestat & GWXES_MOUSECAPPASTE))		//flag for xecap,req callback//~v500I~
#endif                                                             //~v500I~
    if (UGETQCTR(&(UGETPFH(Ssortplh1)->UFHlineque))==2	//no data//~5226R~
    ||  (Ssortplh1==Ssortplh2 && ((PULINEH)Ssortplh1)->ULHtype==ULHTHDR))//~v50KR~
	{
		uerrmsg("Invalid Block specification",                  //~5423R~
				"ブロックの指定が正しくない");                  //~5423R~
		return 4;
	}
                                                                //~5502I~
//  if (!(pfh=capgetpfh(Ppcw)))                                    //~va7AR~
    if (!(pfh=capgetpfh(CAPGPFO_SAVE,Ppcw)))                       //~va7AI~
		return 4;
	UPCTRREQ(pfh);	//end of a shot

	plh1=UGETQTOP(&pfh->UFHlineque);	//top data
	plh2=UGETQEND(&pfh->UFHlineque);	//end data        k
	pcw=pfh->UFHeditpcw;
	if (UGETQCTR(&pfh->UFHlineque)!=2)	//del old all
    {                                                              //~v585I~
//  	if (lcmddel(pcw,plh1,plh2,1,0,1)==UALLOC_FAILED)           //~v585R~
            	//repeat=1,csr noset req,UFHcmdline clear       //~v057I~
//         	return UALLOC_FAILED;                                  //~v585R~
        filefreealldataplh(pfh);   //free all plh and undo data    //~v746R~
		UCBITON(pcw->UCWflag,UCWFDRAW);                            //~v585I~
    }                                                              //~v585I~
  	if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//save region mode //~v66eI~
    	UCBITON(pfh->UFHflag7,UFHF7REGIONCB);                      //~v66eI~
    else                                                           //~v66eI~
    	UCBITOFF(pfh->UFHflag7,UFHF7REGIONCB);                     //~v66eI~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
  if ((Gwxestat & GWXES_MOUSECAPPASTE))		//flag for xecap,req callback//~v500M~
  {                                                                //~v500M~
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef LNX                                                       //~va20I~
    if (Gwxestat & GWXES_ENVISUTF8)                                //~va20R~
    	UCBITON(pfh->UFHflag8,UFHF8UTF8);                          //~va20I~
    else                                                           //~va20I~
    	UCBITOFF(pfh->UFHflag8,UFHF8UTF8);                         //~va20I~
  #else                                                            //~va20I~
	if (Gwxestat & GWXES_CPDATAUCS)     		//daat is unicodetextcallback//~va20R~
    	UCBITON(pfh->UFHflag8,UFHF8UTF8);                          //~va20I~
    else                                                           //~va20I~
    	UCBITOFF(pfh->UFHflag8,UFHF8UTF8);                         //~va20I~
  #endif                                                           //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va5yR~
	if (Gwxestat & GWXES_CPDATAEBC)     		//daat is unicodetextcallback//~va5yR~
    {                                                              //~va5yR~
    	UCBITON(pfh->UFHflag10,UFHF10EBC);                         //~va5yR~
  #ifdef LNX                                                       //~va5yR~
    	UCBITOFF(pfh->UFHflag8,UFHF8UTF8); //linux set by env not by GWXES_CPDATAUCS//~va5yR~
  #endif                                                           //~va5yR~
  		pfh->UFHhandle=Gwxecapebchandle;  //wxexei set it at capb2u//~va7AM~
    }                                                              //~va5yR~
    else                                                           //~va5yR~
//  	UCBITOFF(pfh->UFHflag8,UFHF10EBC);                         //~va5yR~//~va7zR~
    	UCBITOFF(pfh->UFHflag10,UFHF10EBC);                        //~va7zI~
#endif //UTF8EBCD raw ebcdic file support                          //~va5yR~
#endif                                                             //~va20I~
    pfh->UFHlrecl  =0;                                             //~v500M~
//  pfh->UFHmergin =0;                                             //~v66hR~
    pfh->UFHmergin=MAXLINEDATA;                                    //~v66hI~
    pfh->UFHspfpos =0;                                             //~v500M~
    pfh->UFHflag2  =0;                                             //~v500M~
    pfh->UFHcmdline[pfh->UFHcmdlinectr++]=plh1;	//dumy plh added by fcmdaddslh//~v500I~
	UTRACEP("@@@1 %s:add %c cmd,cmdlinectr=%d\n",UTT,*plh1->ULHlinecmd,pfh->UFHcmdlinectr);//~vb25I~
    strcpy(plh1->ULHlinecmd,"A");	//sim copy fcmd                //~v500I~
    fcmdaddslh(pcw);                                               //~v500M~
    plh=pfh->UFHcmdline[pfh->UFHcmdlinectr-1];	//dumy plh added by fcmdaddslh//~v500M~
    strcpy(plh->ULHlinecmd,"C");	//sim copy fcmd                //~v500M~
    UCBITON(pfh->UFHflag6,UFHF6NOUNDO);  //skip save undo data(for ::cb)//~v585I~
	rc=filelinecmd(pcw);	//lcmdcopy callback wxe                //~v500M~
    UCBITOFF(pfh->UFHflag6,UFHF6NOUNDO);  //skip save undo data(for ::cb)//~v585I~
  }                                                                //~v500M~
  else                                                             //~v500M~
//*!mousepaste                                                     //~va7zI~
  {                                                                //~v500M~
#endif                                                             //~v500M~
//  plc=lcmdgetdummyplc(Ppcw,'A');	//destination After            //~v500R~
    plc=lcmdgetdummyplc(pcw,'A');	//destination After(BUG?)      //~v500I~
	plc->ULCplh=plh1;	//copy after top
//*                                                                //~v500I~
//set spf attr for lcmdcopy to drop numfld                         //~v418I~
    pfhs=UGETPFH(Ssortplh1);	//source pfh                       //~v418I~
#ifdef UTF8UCS2                                                    //~va20I~
    if (FILEUTF8MODE(pfhs))	//source file is utf8,so ::cb is utf8  //~va20R~
    	UCBITON(pfh->UFHflag8,UFHF8UTF8);                          //~va20I~
    else                                                           //~va20I~
    	UCBITOFF(pfh->UFHflag8,UFHF8UTF8);                         //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (PFH_ISEBC(pfhs))	//source file is utf8,so ::cb is utf8  //~va50I~
    {                                                              //~va79I~
    	UCBITON(pfh->UFHflag10,UFHF10EBC);                         //~va50I~
        pfh->UFHhandle=pfhs->UFHhandle;                            //~va79I~
    }                                                              //~va79I~
    else                                                           //~va50I~
    	UCBITOFF(pfh->UFHflag10,UFHF10EBC);                        //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    pfh->UFHlrecl  =pfhs->UFHlrecl ;                               //~v418I~
    pfh->UFHmergin =pfhs->UFHmergin;                               //~v418I~
    pfh->UFHspfpos =pfhs->UFHspfpos;                               //~v418I~
    pfh->UFHflag2  =(UCHAR)(pfhs->UFHflag2 & (UFHF2MERGIN|UFHF2SPFNUMOK|UFHF2SPFNUMERR)) ;     //mergin,spf//~v418I~
    pfh->UFHflag5  =(UCHAR)(pfhs->UFHflag5 & (UFHF5COB|UFHF5NOAUTONUM|UFHF5COB2)) ;  //avoid lcmdcopy issue bell by spf num err//~v674I~
    pfh->UFHflag3  =(UCHAR)(pfhs->UFHflag3 & (UFHF3OOMNOPROT)) ;  //margin prot attr//~v74fI~
//*                                                                //~v418I~
    UCBITON(pfh->UFHflag6,UFHF6NOUNDO);  //skip save undo data(for ::cb)//~v585I~
  if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))                      //~v66fR~
  {                                                                //~v66fI~
  		if (Ssortposx2<=0)	//save region mode                     //~v66fI~
        	endplh=UGETQPREV(Ssortplh2);                           //~v66fI~
        else                                                       //~v66fI~
        	endplh=Ssortplh2;                                      //~v66fI~
		lcmdcopy(pcw,Ssortplh1,endplh,1,plc);	//repeat=1         //~v66fR~
  }                                                                //~v66fI~
  else                                                             //~v66eI~
  {
	lcmdcopy(pcw,Ssortplh1,Ssortplh2,1,plc);	//repeat=1      //~5226R~
//  pfh->UFHflag5  =0;                               //~v675R~,     //~v74qR~
	if (UCBITCHK(Sblockstat,SBLOCKMODE))			//block mode   //~v74wI~
    {                                                              //~v74wI~
   		pfh->UFHflag5=0;                                           //~v74wR~
    	pfh->UFHflag2=0;                                           //~v74wI~
    	pfh->UFHflag3=0;                                           //~v74wI~
    	pfh->UFHspfpos=0;                                          //~v74wI~
    }                                                              //~v74wI~
  }
    UCBITOFF(pfh->UFHflag6,UFHF6NOUNDO);  //skip save undo data(for ::cb)//~v585I~
//block process
	plh1=UGETQNEXT(UGETQTOP(&pfh->UFHlineque));	//top data
	plh2=UGETQPREV(UGETQEND(&pfh->UFHlineque));	//top data
	blocksw=UCBITCHK(Sblockstat,SBLOCKMODE);
	len=Ssortposx2-Ssortposx1;                                  //~5226R~
	for (plh=plh1;;plh=UGETQNEXT(plh))
	{
    	if (plh->ULHtype!=ULHTDATA)
		{
			plhwk=UGETQPREV(plh);	//for after deq
            xefsubresetcsrplh(0,plh);                              //~v66fI~
            UDEQ(UQUE_ENT,0,plh);
			filefreeplh(plh,1);	//free data and plh(type EXCLUDE)
			plh=plhwk;			//for next UGETQNEXT
			continue;
		}
		UCBITOFF(plh->ULHflag2,ULHF2EXCLUDED);
        if (!plh->ULHdbcs)
			if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
		if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//save region mode//~v66eI~
        {                                                          //~v66eI~
        	if (plh==plh2)	//last line                            //~v66eM~
            {                                                      //~v66eM~
//          	if (Ssortposx2>0 && plh->ULHlen>Ssortposx2)        //~v70bR~
            	if (Ssortposx2>0 && plh->ULHlen>=Ssortposx2)       //~v70bI~
                {                                                  //~v66fI~
            	  if (plh->ULHlen>Ssortposx2                       //~vagDI~
          		  &&  PFH_ISEBC(pfh)   //source is EBC file        //~vaj3I~
                  &&  *(plh->ULHdbcs+Ssortposx2-1)==DBCS2NDCHAR)   //~vagDR~
                  {                                                //~vagDI~
            	    *(plh->ULHdata+Ssortposx2)=CHAR_SI;            //~vagDI~
            	    *(plh->ULHdbcs+Ssortposx2)=0;                  //~vagDI~
	            	plh->ULHlen=Ssortposx2+1;                      //~vagDI~
                  }                                                //~vagDI~
                  else                                             //~vagDI~
	            	plh->ULHlen=Ssortposx2;                        //~v66eM~
                    plh->ULHeolid=0;	//no endofline id ,concatinate naxtline when pasted by Ctrl+v//~v66fI~
                    plh->ULHeolidid=0;	//no endofline id ,concatinate naxtline when pasted by Ctrl+v//~v66hI~
					UCBITON(plh->ULHflag4,ULHF4NOEOL);//skip write eol at save//~v66fI~
                }                                                  //~v66fI~
                else                                               //~v66fI~
					UCBITOFF(plh->ULHflag4,ULHF4NOEOL);//write eol at save//~v66fI~
            }                                                      //~v66eM~
        	if (plh==plh1)	//top line                             //~v66eR~
            {                                                      //~v66eI~
	    		UCBITON(pfh->UFHflag6,UFHF6NOUNDO);  //skip save undo data(for ::cb)//~v66eI~
              if (Ssortposx1 && Ssortposx1<plh->ULHlen             //~vagDR~
          	  &&  PFH_ISEBC(pfh)   //source is EBC file            //~vaj3I~
              &&  *(plh->ULHdbcs+Ssortposx1)==DBCS1STCHAR)         //~vagDI~
              {                                                    //~vagDI~
                *(plh->ULHdata+Ssortposx1-1)=CHAR_SO;   //insert SO before dbcs//~vagDI~
                *(plh->ULHdbcs+Ssortposx1-1)=0;                    //~vagDI~
    			charfldedit(CHAROPETOL,		//mode erase top of line//~vagDI~
					   plh->ULHdata,		//buffer               //~vagDI~
					   plh->ULHdbcs,		//buffer               //~vagDI~
    				   Ssortposx1-1,   	//current col              //~vagDI~
					   0,         //start col                      //~vagDI~
					   plh->ULHlen,			//end col              //~vagDI~
					   plh->ULHbufflen,		//buff len last        //~vagDI~
					   pcw,		    		//pcw                  //~vagDI~
					   plh);				//update ctr etc       //~vagDI~
              }                                                    //~vagDI~
              else                                                 //~vagDI~
              {                                                    //~vagDI~
    			charfldedit(CHAROPETOL,		//mode erase top of line//~v66eR~
					   plh->ULHdata,		//buffer               //~v66eI~
					   plh->ULHdbcs,		//buffer               //~v66eI~
    				   Ssortposx1,   	//current col              //~6757R~
					   0,         //start col                      //~v66eI~
					   plh->ULHlen,			//end col              //~v66eI~
					   plh->ULHbufflen,		//buff len last        //~v66eI~
					   pcw,		    		//pcw                  //~v66eI~
					   plh);				//update ctr etc       //~v66eI~
              }                                                    //~vagDI~
		    	UCBITOFF(pfh->UFHflag6,UFHF6NOUNDO);  //skip save undo data(for ::cb)//~v66eI~
            }                                                      //~v66eI~
        }                                                          //~v66eI~
        else                                                       //~v66eI~
		if (blocksw)
		{
//  		if (len>plh->ULHbufflen)                               //~vagDR~
//  			if (fileexpandbuff(plh,len)==UALLOC_FAILED)		//expand buff//~v04dR~//~vagDR~
    		if (len+2>plh->ULHbufflen)                             //~vagDI~
    			if (fileexpandbuff(plh,len+2)==UALLOC_FAILED)		//expand buff//~vagDI~
	            	return UALLOC_FAILED;                       //~v04dI~
    		UCBITON(pfh->UFHflag6,UFHF6NOUNDO);  //skip save undo data(for ::cb)//~v585I~
        	addsosi=0;                                             //~vagDI~
          if (PFH_ISEBC(pfh))   //source is EBC file               //~vaj3I~
          {                                                        //~vaj3I~
            if (plh->ULHlen>Ssortposx2                             //~vagDI~
            &&  *(plh->ULHdbcs+Ssortposx2-1)==DBCS2NDCHAR)         //~vagDI~
            	addsosi=2;                                         //~vagDI~
            if (Ssortposx1 && Ssortposx1<plh->ULHlen               //~vagDI~
            &&  *(plh->ULHdbcs+Ssortposx1)==DBCS1STCHAR)           //~vagDI~
            	addsosi|=1;                                        //~vagDI~
          }                                                        //~vaj3I~
          if (addsosi)                                             //~vagDI~
          {                                                        //~vagDI~
          	if (addsosi & 2)	//need SI                          //~vagDI~
            {                                                      //~vagDI~
                *(plh->ULHdata+Ssortposx2)=CHAR_SI;                //~vagDI~
                *(plh->ULHdbcs+Ssortposx2)=0;                      //~vagDI~
            }                                                      //~vagDI~
          	if (addsosi & 1)	//need SO                          //~vagDI~
            {                                                      //~vagDI~
                *(plh->ULHdata+Ssortposx1-1)=CHAR_SO;   //insert SO before dbcs//~vagDI~
                *(plh->ULHdbcs+Ssortposx1-1)=0;                    //~vagDI~
            }                                                      //~vagDI~
			charfldedit(CHAROPMGET,		//mode erase top of line   //~vagDI~
					   plh->ULHdata,		//buffer               //~vagDI~
					   plh->ULHdbcs,		//buffer               //~vagDI~
					   Ssortposx2+((addsosi & 2)!=0),   	//current col//~vagDI~
					   Ssortposx1-((addsosi & 1)!=0),         //start col//~vagDI~
					   plh->ULHlen,			//end col              //~vagDI~
					   plh->ULHbufflen,		//buff len last        //~vagDI~
					   pcw,		    		//pcw                  //~vagDI~
					   plh);				//update ctr etc       //~vagDI~
          }                                                        //~vagDI~
          else                                                     //~vagDI~
			charfldedit(CHAROPMGET,		//mode erase top of line
					   plh->ULHdata,		//buffer
					   plh->ULHdbcs,		//buffer
					   Ssortposx2,   	//current col           //~5226R~
					   Ssortposx1,         //start col          //~5226R~
					   plh->ULHlen,			//end col
					   plh->ULHbufflen,		//buff len last
					   pcw,		    		//pcw
					   plh);				//update ctr etc
		    UCBITOFF(pfh->UFHflag6,UFHF6NOUNDO);  //skip save undo data(for ::cb)//~v585I~
    	}//block mode
		if (plh==plh2)
			break;
	}//all plh
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
  }	//cp from wxe                                                  //~v500I~
#endif                                                             //~v500I~
	UPCTRREQ(pfh);	//end of a shot
#ifdef WXEXXE                                                      //~v66hI~
  if (!(Gwxestat & GWXES_MOUSECAPPASTE))	//to write to ::cb from windows clipboard//~v66hI~
  											//if reset region flag,cannot replace region//~v66hI~
#endif                                                             //~v66hI~
	UCBITON(Sblockstat,SBLOCKSAVED);	//block copyed          //~5502I~
#ifdef WXEXXE                                                      //~v70eI~
    if (!(Gwxestat & GWXES_MOUSECAPCOPY))	//operation by pfkey   //~v70eI~
    	wxe_capcopytowincbfromxe();		//copy to windows clipboard//~v70eR~
#endif                                                             //~v70eI~
//  return 0;                                                      //~v500R~
    return rc;                                                     //~v500I~
}//capsavedata
//*******************************************************          //~v53cI~
//!capsavedataword                                                 //~v53cI~
//* save word to clipboard                                         //~v53cI~
//* parm1:pcw                                                      //~v53cI~
//* retrn:rc                                                       //~v53cI~
//*******************************************************          //~v53cI~
#ifdef UTF8UCS2                                                    //~va20I~
int capsavedataword(int Popt,PUCLIENTWE Ppcw,char *Pword,char *Pdbcs,int Plen)//~va20I~
#else                                                              //~va20I~
int capsavedataword(PUCLIENTWE Ppcw,char *Pword,int Plen)          //~v53cI~
#endif                                                             //~va20I~
{                                                                  //~v53cI~
	PULINEH  plh1,/*plh2,*/plh;                                    //~v74wR~
 	PUFILEH  pfh;                                                  //~v53cI~
 	PUFILEH  pfhs;                                                 //~vagCI~
	PUCLIENTWE pcw;                                                //~v53cI~
	int rc;                                                        //~v53cR~
//*******************                                              //~v53cI~
//  if (!(pfh=capgetpfh(Ppcw)))	//CB pfh                           //~v53cI~//~va7AR~
    if (!(pfh=capgetpfh(CAPGPFO_SAVE,Ppcw)))	//CB pfh           //~va7AI~
		return 4;                                                  //~v53cI~
    pfhs=UGETPFHFROMPCW(Ppcw);                                     //~vagCI~
	plh1=UGETQTOP(&pfh->UFHlineque);	//top data                 //~v53cI~
//  plh2=UGETQEND(&pfh->UFHlineque);	//end data        k        //~v74wR~
	UPCTRREQ(pfh);	//end of a shot                                //~v53cI~
	pcw=pfh->UFHeditpcw;                                           //~v53cI~
	if (UGETQCTR(&pfh->UFHlineque)!=2)	//del old all              //~v53cI~
//  	if (lcmddel(pcw,plh1,plh2,1,0,1)==UALLOC_FAILED)           //~v74bR~
            	//repeat=1,csr noset req,UFHcmdline clear          //~v53cI~
//         	return UALLOC_FAILED;                                  //~v74bR~
        filefreealldataplh(pfh);   //free all plh and undo data    //~v74bI~
#ifdef UTF8UCS2                                                    //~va20I~
    UCBITOFF(pfh->UFHflag8,UFHF8UTF8);	//::cb mode                //~va20I~
    UCBITOFF(pfh->UFHflag10,UFHF10EBC);	//::cb mode                //~va5DI~
  	if (Popt & CSDWO_CPU8)	                                       //~va20I~
  	{                                                              //~va20I~
    	UCBITON(pfh->UFHflag8,UFHF8UTF8);                          //~va20I~
		rc=fcmdisrtlinedbcs(pcw,plh1,Pword,Pdbcs,Plen);            //~va20I~
  	}                                                              //~va20I~
  	else                                                           //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  	if (Popt & CSDWO_CPEB)                                         //~va50I~
  	{                                                              //~va50I~
    	UCBITON(pfh->UFHflag10,UFHF10EBC);                         //~va50I~
        pfh->UFHhandle=pfhs->UFHhandle;                            //~vagCI~
		rc=fcmdisrtlinedbcs(pcw,plh1,Pword,Pdbcs,Plen);            //~va50I~
  	}                                                              //~va50I~
  	else                                                           //~va50I~
  	if (Popt & CSDWO_CPU8WORD)                                     //~vau3R~
    {                                                              //~vau3R~
    	UCBITON(pfh->UFHflag8,UFHF8UTF8);                          //~vau3R~
		rc=fcmdisrtline(pcw,plh1,Pword,Plen);	//set dbcs from filechktabdbcs//~vau3R~
    }                                                              //~vau3R~
    else                                                           //~vau3R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		rc=fcmdisrtline(pcw,plh1,Pword,Plen);	//set dbcs from filechktabdbcs//~va20I~
	if (rc)                                                        //~va20I~
#else                                                              //~va20R~
	if (rc=fcmdisrtline(pcw,plh1,Pword,Plen),rc)                   //~v53cR~
#endif                                                             //~va20I~
    	return rc;                                                 //~v53cI~
    plh=UGETQNEXT(plh1);		//inserted                         //~v66hI~
    plh->ULHeolid=0;	//no endofline id ,concatinate naxtline when pasted by Ctrl+v//~v66hI~
    plh->ULHeolidid=0;	//no endofline id ,concatinate naxtline when pasted by Ctrl+v//~v66hI~
	UCBITON(plh->ULHflag4,ULHF4NOEOL);//skip write eol at save     //~v66hI~
	UPCTRREQ(pfh);	//end of a shot                                //~v53cI~
	UCBITON(Sblockstat,SBLOCKSAVED);	//block copyed             //~v53cI~
#ifdef WXEXXE                                                      //~va5BI~
    if (!(Gwxestat & GWXES_MOUSECAPCOPY))	//operation by pfkey   //~va5BI~
    	wxe_capcopytowincbfromxe();		//copy to windows clipboard//~va5BI~
#endif                                                             //~va5BI~
    return rc;                                                     //~v53cI~
}//capsavedataword                                                 //~v53cI~
#ifdef UTF8SUPPH                                                   //~va00I~
//*******************************************************          //~va00I~
//!capcvcb                                                         //~va00I~
//* translate clipboard data                                       //~va00I~
//*******************************************************          //~va00I~
int xecapcvcb(int Popt,char *Pdata,int Pdatalen,char *Poutdata,int *Ppoutlen)//~va00I~
{                                                                  //~va00I~
	int opt,lclen,rc=0,rc2;                                        //~va00I~
    UCHAR *pc=0;                                                    //~va00I~//~va5jR~
//*******************                                              //~va00I~
	*Ppoutlen=Pdatalen;		//no conversion case                   //~va00I~
	if (Popt & CCVCBO_F2L)	//clipboard to locale code             //~va00I~
    {                                                              //~va00I~
    	if (XEUTF8MODE_ENV())	//clipboard utf8 is not translated at xxe//~va00R~
        {                                                          //~va00I~
            opt=XEUTFCVO_CPLC|XEUTFCVO_STRZ|XEUTFCVO_RETALLASCII;  //~va00R~
            rc2=xeutf_cvdata(opt,Pdata,Pdatalen,&pc,&lclen);       //~va00R~
            if (rc2==XEUTFCVRC_ALLASCII)                           //~va00R~
            {                                                      //~va00R~
                if (Poutdata!=Pdata)                               //~va00R~
                    UmemcpyZ(Poutdata,Pdata,(UINT)lclen);          //~va00R~
            }                                                      //~va00R~
            else                                                   //~va00R~
            if (!rc2)  //all valid utf8                            //~va00R~
            {                                                      //~va00R~
                UmemcpyZ(Poutdata,pc,(UINT)lclen);                 //~va00R~
                *Ppoutlen=lclen;                                   //~va00R~
                rc=1;        //conversion done                     //~va00R~
            }                                                      //~va00R~
        }                                                          //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
    	opt=XEUTFCVO_CPU8|XEUTFCVO_STRZ|XEUTFCVO_RETALLASCII|XEUTFCVO_ERRREPQM;//~va00I~
		rc2=xeutf_cvdata(opt,Pdata,Pdatalen,&pc,&lclen);           //~va00I~
        if (rc2==XEUTFCVRC_ALLASCII)                               //~va00I~
        {                                                          //~va00I~
        	if (Poutdata!=Pdata)                                   //~va00I~
            	UmemcpyZ(Poutdata,Pdata,(UINT)lclen);              //~va00I~
        }                                                          //~va00I~
        else                                                       //~va00I~
        if (rc2!=UALLOC_FAILED)                                    //~va00I~
        {                                                          //~va00I~
            UmemcpyZ(Poutdata,pc,(UINT)lclen);                     //~va00I~
            *Ppoutlen=lclen;                                       //~va00I~
        	rc=1;        //conversion done                         //~va00I~
        }                                                          //~va00I~
    }                                                              //~va00I~
    return rc;                                                     //~va00I~
}//xecapcvcb                                                       //~va00I~
#endif                                                             //~va00I~
                                                                   //~v53cI~
//*******************************************************
//!capcut
//* del block
//* parm1:pcw
//* parm2:move overrap chk option                               //~5521I~
//* retrn:rc
//*******************************************************
int capcut(PUCLIENTWE Ppcw,int Povmovechkopt)                   //~5521R~
{
	PULINEH  plh,endplh;                                        //~5502R~
	int rc,stepline,fileupctr,len,dellen;                       //~5521R~
//*******************
  	if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//not started by "start stdregin"//~v66eI~
//  	return capcutregion(Ppcw,&Ssortplh1,&Ssortplh2,Ssortposx1,Ssortposx2);//~v74hR~
    	return capcutregion(0,Ppcw,&Ssortplh1,&Ssortplh2,Ssortposx1,Ssortposx2,0);//~v74hR~
//fullline process
	if (!UCBITCHK(Sblockstat,SBLOCKMODE))
    {
    	endplh=getdisplayline(Ssortplh2,1,&stepline); //next csr line//~v66eI~
		rc=lcmddel(Ppcw,Ssortplh1,Ssortplh2,1,1,1);             //~v057R~
                 //repeat=1,csr set req,UFHcmdline clear        //~v057I~
        Ssortplh1=0;		//range deleted id                     //~v66eR~
        if (endplh)                                  //not end of file//~v66eI~
        	Ssortplh2=endplh;                        //set csr to next line//~v66eI~
        return rc;
    }

//block process
    endplh=getdisplayline(Ssortplh2,1,&stepline);               //~5502R~
    rc=0;                                                       //~5503R~
    fileupctr=UGETPFH(Ssortplh1)->UFHupctr;//this is not 0      //~5521I~
    dellen=Ssortposx2-Ssortposx1;                               //~5521I~
	for (plh=Ssortplh1;plh!=endplh;plh=UGETQNEXT(plh))          //~5502R~
	{
    	if (plh->ULHtype!=ULHTDATA)
			continue;
//      if (plh->ULHlen<=Ssortposx1)                               //~v746R~
//          continue;                                              //~v746R~
        if (!plh->ULHdbcs)
			if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
        if (plh->ULHlen<=Ssortposx1)                               //~v746R~
            continue;                                              //~v746R~

		if (Povmovechkopt	//taget<source move                 //~5521I~
        &&  plh->ULHupctr==fileupctr)	//copyed by move before del//~5521I~
        	len=plh->ULHlen;	//overrap id and len before del //~5521I~
		else                                                    //~5521I~
        	len=0;				//not overrap id                //~5521I~
		charfldedit(CHAROPETOL,//erase top of line up to start col//~5503R~
					   plh->ULHdata,		//buffer
					   plh->ULHdbcs,		//buffer
					   Ssortposx2,			//current col
					   Ssortposx1,         //start col          //~5226R~
					   plh->ULHlen,			//end col
					   plh->ULHbufflen,		//buff len last
					   Ppcw,		    		//pcw
					   plh);				//update ctr etc    //~5503R~
		if (len)		//overrapped                            //~5521I~
        {                                                       //~5521I~
			UCBITON(plh->ULHflag,ULHFCURCAP);//cleared by undoprep//~5521I~
            plh->ULHrevoffs=(USHORT)(plh->ULHrevoffs-dellen);//reduced len by del//~5521R~
        }                                                       //~5521I~
	}//all plh

	return rc;
}//capcut
//*******************************************************       //~5513I~
//!capclear
//* space clear block                                           //~5513I~
//* parm1:pcw                                                   //~5513I~
//* retrn:rc                                                    //~5513I~
//*******************************************************       //~5513I~
int capclear(PUCLIENTWE Ppcw)                                   //~5513I~
{                                                               //~5513I~
	PULINEH  plh,endplh;                                        //~5513I~
	int rc,stepline;                                            //~5513I~
    int endpos;                                                 //~v06kI~
//*******************                                           //~5513I~
  	if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//not started by "start stdregin"//~v66eI~
    	return capclearregion(Ppcw,Ssortplh1,Ssortplh2,Ssortposx1,Ssortposx2);//~v66eI~
    endplh=getdisplayline(Ssortplh2,1,&stepline);               //~5513I~
    rc=0;                                                       //~5513I~
	for (plh=Ssortplh1;plh!=endplh;plh=UGETQNEXT(plh))          //~5513I~
	{                                                           //~5513I~
    	if (plh->ULHtype!=ULHTDATA)                             //~5513I~
			continue;                                           //~5513I~
//      if (plh->ULHlen<=Ssortposx1)                               //~v746R~
//          continue;                                              //~v746R~
        if (!plh->ULHdbcs)                                      //~5513I~
			if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
        if (plh->ULHlen<=Ssortposx1)                               //~v746R~
            continue;                                              //~v746R~
                                                                //~5513I~
		if (UCBITCHK(Sblockstat,SBLOCKMODE))                    //~v06kI~
        	endpos=Ssortposx2;                                  //~v06kI~
		else                                                    //~v06kI~
        	endpos=plh->ULHlen;                                 //~v06kI~
        rc=                                                        //~v0ihI~
		charfldedit(CHAROPCTOL,//erase top of line up to start col//~5513I~
					   plh->ULHdata,		//buffer            //~5513I~
					   plh->ULHdbcs,		//buffer            //~5513I~
					   endpos,    			//current col       //~v06kR~
					   Ssortposx1,         //start col          //~5513I~
					   plh->ULHlen,			//end col           //~5513I~
					   plh->ULHbufflen,		//buff len last     //~5513I~
					   Ppcw,		    		//pcw           //~5513I~
					   plh);				//update ctr etc    //~5513I~
	}//all plh                                                  //~5513I~
                                                                //~5513I~
	return rc;                                                  //~5513I~
}//capclear                                                     //~5520R~
                                                                //~5513I~
//*******************************************************          //~v66jI~
//!capgetpoint                                                     //~v66jI~
//* parm1:pcw                                                      //~v66jI~
//* retrn:rc                                                       //~v66jI~
//*******************************************************          //~v66jI~
int capgetpoint(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Pppos)         //~v66jI~
{                                                                  //~v66jI~
	PUFILEC pfc;                                                   //~v66jI~
	PULINEH plh;                                                   //~v66jI~
	PUFILEH pfh;                                                   //~v66jI~
    int line,pos;                                                  //~v66jI~
//*******************                                              //~v66jI~
	pfc=Ppcw->UCWpfc;                                              //~v66jI~
	pfh=pfc->UFCpfh;                                               //~v66jI~
    line=max(Ppcw->UCWrcsry-Ppcw->UCWfilehdrlineno,0);             //~v66jI~
	line=min(line,pfc->UFCmaxline-1);                              //~v66jI~
	if (line<0)                                                    //~v66jI~
		return 4;                                                  //~v66jI~
	plh=(Ppcw->UCWpsd+line+Ppcw->UCWfilehdrlineno)->USDbuffc;      //~v66jI~
	if (Ppcw->UCWrcsrx<Ppcw->UCWlinenosz)                          //~v66jI~
    	pos=-1;    //line mode                                     //~v66jI~
	else                                                           //~v66jI~
		pos=Ppcw->UCWrcsrx-Ppcw->UCWlinenosz+pfc->UFCleft;         //~v66jI~
    if (capchkmergin(pfh,pos,pos,2))                               //~v66jI~
        return 4;                                                  //~v66jI~
    *Ppplh=plh;                                                    //~v66jI~
    *Pppos=pos;                                                    //~v66jI~
	return 0;                                                      //~v66jI~
}//capgetpoint                                                     //~v66jI~
//*******************************************************          //~v77EI~
//!capgetmouseword                                                 //~v77EI~
//* get region for wordsearch by mouse or pf6/7                    //~v77ER~
//* retrn:rc                                                       //~v77EI~
//*******************************************************          //~v77EI~
int capgetmouseword(int Popt,PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Pppos,int *Pplen)//~v77EI~
{                                                                  //~v77EI~
	PULINEH plh,plh2;                                              //~v77ER~
    int pos,pos1,pos2,len,plhlen;                                  //~v77ER~
    char *pdbcs;                                                   //~v77EI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int splitctr;                                                  //~va1cR~
#endif                                                             //~va1cR~
//*******************                                              //~v77EI~
	if (                                                           //~v77EI~
		!UCBITCHK(Sblockstat,SBLOCKCLOSED) 	//not closed           //~v77EI~
	||  Gcappcw!=Ppcw                                              //~v77EI~
    )                                                              //~v77EI~
    	return 4;                                                  //~v77EI~
	if (capgetpoint(Ppcw,Ppplh,Pppos))	//get csr line plh         //~v77ER~
    	return 4;                                                  //~v77ER~
    plh=*Ppplh;                                                    //~v77EI~
    pos=*Pppos;                                                    //~v77EI~
    plhlen=plh->ULHlen;                                            //~v77EI~
    if (pos>=plhlen)                                               //~v77EI~
    	return 4;                                                  //~v77EI~
                                                                   //~v77EI~
	if (                                                           //~v77ER~
      	Ssortplh1!=plh                                             //~v77ER~
	&&  Ssortplh2!=plh                                             //~v77ER~
	)                                                              //~v77EI~
    {                                                              //~v77EI~
    	for (plh2=Ssortplh1;plh2 && plh2!=Ssortplh2;plh2=UGETQNEXT(plh2))//~v77ER~
        	if (plh2==plh)                                         //~v77EI~
            	break;                                             //~v77EI~
        if (plh2!=plh)                                             //~v77EI~
	    	return 4;                                              //~v77ER~
    }                                                              //~v77EI~
    len=0;                                                         //~v77EI~
    pos1=min(Ssortposx1,plhlen);                                   //~v77ER~
    pos2=min(Ssortposx2,plhlen);                                   //~v77ER~
	if (!UCBITCHK(Sblockstat,SBLOCKMODE)                           //~v77EI~
    &&  !UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//linemode     //~v77EI~
    {                                                              //~v77EI~
    	pos=0;                                                     //~v77EI~
        len=plh->ULHlen;                                           //~v77EI~
    }                                                              //~v77EI~
    else                                                           //~v77EI~
    if (Ssortplh1==Ssortplh2                                       //~v77ER~
    ||  !UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//block mode   //~v77EI~
    {                                                              //~v77EI~
        if (pos>=pos1 && pos<pos2)                                 //~v77EI~
        {                                                          //~v77EI~
        	pos=pos1;                                              //~v77ER~
    		len=pos2-pos1;                                         //~v77ER~
        }                                                          //~v77EI~
    }                                                              //~v77EI~
    else                                                           //~v77EI~
    if (plh==Ssortplh1)	//csr on top line                          //~v77ER~
    {                                                              //~v77EI~
    	if (pos>=pos1)                                             //~v77EI~
        {                                                          //~v77EI~
        	pos=pos1;                                              //~v77ER~
    		len=plh->ULHlen-pos1;                                  //~v77ER~
        }                                                          //~v77EI~
    }                                                              //~v77EI~
    else                //csr on last line                         //~v77ER~
    if (plh==Ssortplh2)	//end plh                                  //~v77EI~
    {                                                              //~v77EI~
    	if (pos<pos2)                                              //~v77EI~
        {                                                          //~v77EI~
        	pos=0;                                                 //~v77ER~
    		len=pos2;                                              //~v77ER~
        }                                                          //~v77EI~
    }                                                              //~v77EI~
    else		//middle                                           //~v77EI~
    {                                                              //~v77EI~
    	pos=0;                                                     //~v77EI~
        len=plh->ULHlen;                                           //~v77EI~
    }                                                              //~v77EI~
    pdbcs=plh->ULHdbcs;                                            //~v77EI~
    if (pdbcs)                                                     //~v77EI~
    {                                                              //~v77EI~
//split occurs when box defined by mouse                           //~va1cR~
#ifdef UTF8SUPPH                                                   //~va1cR~
		splitctr=XESUB_DBCSSPLITCTR_R(pdbcs+pos,len);//splitdbcs right part ctr//~va1cR~
        len-=splitctr;                                             //~va1cR~
        pos+=splitctr;                                             //~va1cR~
    	len-=XESUB_DBCSSPLITCTR_L(pdbcs+pos,len);                  //~va1cR~
#else                                                              //~va1cR~
    	if (*(pdbcs+pos)==DBCS2NDCHAR)                             //~v77EI~
        {                                                          //~v77EI~
        	len--;                                                 //~v77EI~
        	pos++;                                                 //~v77EI~
        }                                                          //~v77EI~
    	if (len && *(pdbcs+pos+len-1)==DBCS1STCHAR)                //~v77EI~
        	len--;                                                 //~v77EI~
#endif                                                             //~va1cR~
    }                                                              //~v77EI~
    if (len<=0)                                                    //~v77ER~
    	return 4;                                                  //~v77EI~
    *Pppos=pos;                                                    //~v77ER~
    *Pplen=len;                                                    //~v77ER~
	return 0;                                                      //~v77EI~
}//capgetmouseword                                                 //~v77EI~
//*******************************************************
//!capsavepoint
//* capsavepoint
//* parm1:pcw
//* parm2:0:start point, 1:end pint, 3:tempraly endpoint(csr pos before block close)//~v66jR~
//* retrn:rc
//*******************************************************
int capsavepoint(PUCLIENTWE Ppcw,int Pendsw)
{
	PUFILEC pfc;
	PULINEH plh;
	PULINEH plh1,plh2;		//start end point plh                  //~v66yI~
	PUFILEH pfh;                                                   //~v0dnR~
//    int mergin;                                                  //~v0eKR~
    int line,pos;
    int dragdest=0;                                                //~v66yR~
//*******************
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;                                               //~v0dnI~
//  line=max(Ppcw->UCWrcsry-FILEHDRLINENO,0);                      //~v11NR~
    line=max(Ppcw->UCWrcsry-Ppcw->UCWfilehdrlineno,0);             //~v11NI~
	line=min(line,pfc->UFCmaxline-1);
	if (line<0)
		return 4;
//  plh=(Ppcw->UCWpsd+line+FILEHDRLINENO)->USDbuffc;               //~v11NR~
	plh=(Ppcw->UCWpsd+line+Ppcw->UCWfilehdrlineno)->USDbuffc;      //~v11NI~
	if (UCBITCHK(Sblockstat2,SBLOCK2LINEMARK))	//line mark req       //~v06eR~
    	pos=-1;    //line mode                                        //~v06eI~
	else                                                              //~v06eI~
	if (Ppcw->UCWrcsrx<Ppcw->UCWlinenosz)                       //~v069R~
//  {                                                              //~v06RR~
//  	pos=pfc->UFCleft;                                          //~v06RR~
//      if (!pos)                                                  //~v06RR~
            pos=-1;    //line mode
//  }                                                              //~v06RR~
	else
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
    {                                                              //~v50KI~
        if (Gwxecpposx>0)                                          //~v50KI~
        	pos=Gwxecpposx-1;	//parm from wxexei2 when word dblclick//~v50KR~
        else                                                       //~v50KI~
			pos=Ppcw->UCWrcsrx-Ppcw->UCWlinenosz+pfc->UFCleft;     //~v50KI~
    }                                                              //~v50KI~
#else                                                              //~v50KI~
		pos=Ppcw->UCWrcsrx-Ppcw->UCWlinenosz+pfc->UFCleft;      //~v069R~
#endif                                                             //~v50KI~
//    mergin=pfh->UFHmergin;                                       //~v0eKR~
//    if (pos>mergin)                                              //~v0eKR~
//      if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR))  //~v0ecR~
//            return charmerginerr(mergin);                                    //~51//~v0eKR~
    if (capchkmergin(pfh,Scapposx1,pos,Pendsw))                    //~v0eKI~
        return 4;                                                  //~v0eKI~
    if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//started by "start stdregin"//~v66eI~
    {                                                              //~v66eI~
    	if (Pendsw!=3)	//not temporary csr pos                    //~v66jR~
        {                                                          //~v66yI~
	    	if (UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file     //~v74qI~
            {                                                      //~v74qI~
                if (pos>0 && pos<SPFCOBNUMFLDLEN)                  //~v74qI~
                    return errcsrpos();                            //~v74qI~
            }                                                      //~v74qI~
                                                                   //~v66yI~
            if (Pendsw==1)                                         //~v66yI~
            {                                                      //~v66yI~
                if (plh->ULHtype==ULHTEXCLUDE||((PULINEH)Gcapplh1)->ULHtype==ULHTEXCLUDE)//start or end is X-line hdr//~v66yI~
                {                                                  //~v66yI~
                    if (lineseqchk(Gcapplh1,plh)>0) //start lineno>end lineno,drag up//~v66yI~
                    {                                              //~v66yI~
                        plh1=plh;                                  //~v66yI~
                        plh2=Gcapplh1;      //draaged to upper     //~v66yI~
                        dragdest=2;                                //~v66yR~
                    }                                 //drag down  //~v66yI~
                    else                                           //~v66yI~
                    {                                              //~v66yI~
                        plh1=Gcapplh1;                             //~v66yI~
                        plh2=plh;       //draaged to lower         //~v66yI~
                        dragdest=1;                                //~v66yR~
                    }                                              //~v66yI~
                    if (plh1->ULHtype==ULHTEXCLUDE)                //~v66yI~
                        return errcsrpos();                        //~v66yI~
                    if (plh2->ULHtype==ULHTEXCLUDE)                //~v66yI~
                    {                                              //~v66yI~
                        if (dragdest==2)   //plh2=Gcapplh1         //~v66yR~
                            Scapposx1=-1;                          //~v66yI~
                        else                                       //~v66yI~
                            pos=-1;                                //~v66yI~
                    }                                              //~v66yI~
                }                                                  //~v66yI~
            }                                                      //~v66yI~
          if (dragdest==0)                                         //~v66yI~
        	if (plh->ULHtype!=ULHTDATA)	                           //~v66eI~
            {                                                      //~v66uI~
              	if (!UGETQPREV(plh))	//top hdr line             //~v66uR~
              	{                                                  //~v66uI~
            		if (((PULINEH)UGETQNEXT(plh))->ULHtype!=ULHTDATA)//~v66uR~
            			return errcsrpos();                        //~v66uI~
                    pos=-1;	//force full line                      //~v66uI~
              	}                                                  //~v66uI~
                else                                               //~v66uI~
              	if (!UGETQNEXT(plh))	//last hdr line            //~v66uI~
              	{                                                  //~v66uI~
            		if (((PULINEH)UGETQPREV(plh))->ULHtype!=ULHTDATA)//~v66uR~
            			return errcsrpos();                        //~v66uI~
                    pos=-1;	//force full line                      //~v66uI~
              	}                                                  //~v66uI~
              	else                                               //~v66uI~
				return errcsrpos();                                //~v66eI~
            }                                                      //~v66uI~
        }//pendsw!=3                                               //~v66yI~
    }                                                              //~v66eI~
	if (Pendsw)
	{
		Gcapplh2=plh;
		Scapposx2=pos;
		if (UCBITCHK(Sblockstat2,SBLOCK2LINEMARK))	//line mark req   //~v06eI~
			Scapposx1=pos;                                            //~v06eI~
	}//end point
	else	//start point
	{
		Gcappcw=Ppcw;
		Sblockstat=0;                                                 //~v06eR~
		Gcapplh2=Gcapplh1=plh;
		Scapposx2=Scapposx1=pos;
	}
    capsortpoint();                                             //~5226I~
	return 0;
}//capsavepoint
//#ifdef WXEXXE                                                      //~vbd2I~//~vbd7R~
//*******************************************************          //~vbd2I~
//!capsavepointselectall                                           //~vbd2I~
//* capsavepoint                                                   //~vbd2I~
//* parm1:pcw                                                      //~vbd2I~
//* parm2:0:start point, 1:end pint                                //~vbd2I~
//* retrn:rc                                                       //~vbd2I~
//*******************************************************          //~vbd2I~
//int capsavepointselectall(PUCLIENTWE Ppcw,int Pendsw)              //~vbd2R~//~vbdrR~
int capsavepointselectall(PUCLIENTWE Ppcw,int Pendsw,PULINEH Pplh1,PULINEH Pplh2)//~vbdrI~
{                                                                  //~vbd2I~
	PUFILEC pfc;                                                   //~vbd2I~
	PULINEH plh;                                                   //~vbd2I~
	PUFILEH pfh;                                                   //~vbd2I~
//*******************                                              //~vbd2I~
	pfc=Ppcw->UCWpfc;                                              //~vbd2I~
	pfh=pfc->UFCpfh;                                               //~vbd2R~
	if (UGETQCTR(&pfh->UFHlineque)==2)	//del old all              //~vbd2I~
    	return 4;                                                  //~vbd2I~
  if (Pplh1)	//label specified                                  //~vbdrI~
  {                                                                //~vbdrI~
    if (Pendsw)                                                    //~vbdrI~
    {                                                              //~vbdrI~
    	plh=UGETQNEXT(Pplh2);                                      //~vbdrR~
        if (!plh)                                                  //~vbdrI~
            plh=Pplh2;                                             //~vbdrI~
    }                                                              //~vbdrI~
    else                                                           //~vbdrI~
		plh=Pplh1;                                                 //~vbdrR~
  }                                                                //~vbdrI~
  else                                                             //~vbdrI~
  {                                                                //~vbdrI~
    if (Pendsw)                                                    //~vbd2I~
    	plh=UGETQEND(&pfh->UFHlineque);	//last line                //~vbd2R~
    else                                                           //~vbd2I~
		plh=UGETQNEXT(UGETQTOP(&pfh->UFHlineque));	//top line     //~vbd2I~
  }                                                                //~vbdrI~
	if (Pendsw)                                                    //~vbd2I~
	{                                                              //~vbd2I~
		Gcapplh2=plh;                                              //~vbd2I~
		Scapposx2=-1;                                              //~vbd2R~
	}//end point                                                   //~vbd2I~
	else	//start point                                          //~vbd2I~
	{                                                              //~vbd2I~
		Gcappcw=Ppcw;                                              //~vbd2I~
		Sblockstat=0;                                              //~vbd2I~
		Gcapplh2=Gcapplh1=plh;                                     //~vbd2I~
		Scapposx2=Scapposx1=-1;                                    //~vbd2R~
	}                                                              //~vbd2I~
    capsortpointselectall(0);                                       //~vbd2I~//~vbd7R~
	return 0;                                                      //~vbd2I~
}//capsavepointselectall                                           //~vbd2I~
//#endif                                                             //~vbd2R~//~vbd7R~
//*******************************************************          //~vbd7I~
//!capsavepointselectallblock                                      //~vbd7I~
//* capsavepoint                                                   //~vbd7I~
//* parm1:pcw                                                      //~vbd7I~
//* parm2:0:start point, 1:end pint                                //~vbd7I~
//* retrn:rc                                                       //~vbd7I~
//*******************************************************          //~vbd7I~
//int capsavepointselectallblock(PUCLIENTWE Ppcw,int Pendsw,int Pcol1,int Pcol2)//~vbd7I~//~vbdrR~
int capsavepointselectallblock(PUCLIENTWE Ppcw,int Pendsw,int Pcol1,int Pcol2,PULINEH Pplh1,PULINEH Pplh2)//~vbdrI~
{                                                                  //~vbd7I~
	PUFILEC pfc;                                                   //~vbd7I~
	PULINEH plh;                                                   //~vbd7I~
	PUFILEH pfh;                                                   //~vbd7I~
//*******************                                              //~vbd7I~
	pfc=Ppcw->UCWpfc;                                              //~vbd7I~
	pfh=pfc->UFCpfh;                                               //~vbd7I~
	if (UGETQCTR(&pfh->UFHlineque)==2)	//del old all              //~vbd7I~
    	return 4;                                                  //~vbd7I~
  if (Pplh1)                                                       //~vbdrI~
  {                                                                //~vbdrI~
    if (Pendsw)                                                    //~vbdrI~
    	plh=Pplh2;                                                 //~vbdrI~
    else                                                           //~vbdrI~
		plh=Pplh1;                                                 //~vbdrR~
  }                                                                //~vbdrI~
  else                                                             //~vbdrI~
  {                                                                //~vbdrI~
    if (Pendsw)                                                    //~vbd7I~
    	plh=UGETQEND(&pfh->UFHlineque);	//last line                //~vbd7I~
    else                                                           //~vbd7I~
		plh=UGETQNEXT(UGETQTOP(&pfh->UFHlineque));	//top line     //~vbd7I~
  }                                                                //~vbdrI~
	if (Pendsw)                                                    //~vbd7I~
	{                                                              //~vbd7I~
		Gcapplh2=plh;                                              //~vbd7I~
		Scapposx2=Pcol2;                                           //~vbd7I~
	}//end point                                                   //~vbd7I~
	else	//start point                                          //~vbd7I~
	{                                                              //~vbd7I~
		Gcappcw=Ppcw;                                              //~vbd7I~
		Sblockstat=0;                                              //~vbd7I~
		Gcapplh2=Gcapplh1=plh;                                     //~vbd7I~
		Scapposx2=Scapposx1=Pcol1;                                 //~vbd7I~
	}                                                              //~vbd7I~
    capsortpointselectall(1);   //blockmode                        //~vbd7I~
	return 0;                                                      //~vbd7I~
}//capsavepointselectallblock                                      //~vbd7I~
//*******************************************************          //~v0eKI~
//!capchkmergin                                                    //~v0eKI~
//* chk cross mergin,oom for spf and oom protected mergined file   //~v0eKI~
//* parm1:pfh                                                      //~v0eKI~
//* parm2:pos1                                                     //~v0eKI~
//* parm3:pos2                                                     //~v0eKI~
//* parm4:option:0 source not closed(Ppos2 only)                   //~v0eKI~
//*              1 source closed                                   //~v0eKI~
//*              2 target chk(Ppos2 only)                          //~v0eKI~
//* retrn:rc                                                       //~v0eKI~
//*******************************************************          //~v0eKI~
int capchkmergin(PUFILEH Ppfh,int Ppos1,int Ppos2,int Popt)        //~v0eKI~
{                                                                  //~v0eKI~
    int mergin,m2protsw;                                           //~v417R~
//****************                                                 //~v0eKI~
    mergin=Ppfh->UFHmergin;                                        //~v0eKI~
//  spfsw=UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR);//spf file prohibit oom//~v417R~
    m2protsw=(UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN)                 //~v0eKI~
             && !UCBITCHK(Ppfh->UFHflag3,UFHF3OOMNOPROT));         //~v0eKI~
//  rc=0;                                                          //~v417R~
    if (Popt==2)    //target chk                                   //~v0eKI~
    {                                                              //~v0eKI~
        if (Ppos2>=mergin)                                         //~v0eKI~
//      	if (spfsw || m2protsw)                                 //~v417R~
        	if (m2protsw)                                          //~v417I~
//          	rc=4;		//oom protected                        //~v417R~
    			return errprotected();                             //~v417I~
    }                                                              //~v0eKI~
//  else            //source chk                                   //~v417R~
//      if (Ppos2>mergin)                                          //~v417R~
//      	if (spfsw || m2protsw)                                 //~v417R~
//          	rc=4;	                                           //~v417R~
//  if (!rc)                                                       //~v417R~
        if (Popt==1)        //pos1 and pos2                        //~v0eKR~
            if (Ppos1>0 || Ppos2>0) //box mode                     //~v0eKR~
                if ((Ppos1>mergin && Ppos2<mergin)                 //~v0eKR~
                ||  (Ppos2>mergin && Ppos1<mergin))                //~v0eKR~
//                  rc=4;   //cross mergin                         //~v417R~
    			  	return errmarginboundary();                    //~v417R~
//	if (rc)                                                        //~v417R~
//  	return charmerginerr(mergin);                              //~v417R~
	return 0;                                                      //~v0eKI~
}//capchkmergin                                                    //~v0eKI~
//*******************************************************
//!capsortpoint
//* capsortpoint
//*  sort 2 point data                                          //~5226R~
//* 	input  :Gcapplh,Scappos                                 //~5226R~
//* 	output :Ssortplh,Sblockpos                              //~5226I~
//* retrn:none
//*******************************************************
void capsortpoint(void)                                         //~5226R~
{
	int rc;                                                        //~v66eI~
//*******************
  if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//not started by "start stdregin"//~v66eI~
  {                                                                //~v66eI~
//	rc=lineseqchk(Gcapplh1,Gcapplh2);                              //~v66eI~//~vb2ER~
  	rc=(int)lineseqchk(Gcapplh1,Gcapplh2);                         //~vb2EI~
	if (rc>0 || (rc==0 && Scapposx2<Scapposx1))	//start>end || start==end && pos2<pos1//~v66jR~
	{                                                              //~v66eI~
		Ssortplh1=Gcapplh2;                                        //~v66eI~
		Ssortplh2=Gcapplh1;                                        //~v66eI~
        Ssortposx1=Scapposx2;                                      //~v66eI~
        Ssortposx2=Scapposx1;                                      //~v66eI~
	}                                                              //~v66eI~
    else                                                           //~v66eI~
	{                                                              //~v66eI~
		Ssortplh1=Gcapplh1;                                        //~v66eI~
		Ssortplh2=Gcapplh2;                                        //~v66eI~
        Ssortposx1=Scapposx1;                                      //~v66eI~
        Ssortposx2=Scapposx2;                                      //~v66eI~
	}                                                              //~v66eI~
  }                                                                //~v66eI~
  else                                                             //~v66eI~
  {                                                                //~v66eI~
	if (lineseqchk(Gcapplh1,Gcapplh2)>0)	//start>end         //~5226R~
	{
		Ssortplh1=Gcapplh2;                                     //~5226R~
		Ssortplh2=Gcapplh1;                                     //~5226I~
	}                                                           //~5226R~
    else                                                        //~5226I~
	{                                                           //~5226I~
		Ssortplh1=Gcapplh1;                                     //~5226I~
		Ssortplh2=Gcapplh2;                                     //~5226I~
	}                                                           //~5226I~
   	if (Scapposx1>Scapposx2)                                    //~5226R~
	{
		Ssortposx1=Scapposx2;                                   //~5226R~
		Ssortposx2=Scapposx1;                                   //~5226I~
	}                                                           //~5226R~
    else                                                        //~5226I~
	{                                                           //~5226I~
		Ssortposx1=Scapposx1;                                   //~5226R~
		Ssortposx2=Scapposx2;                                   //~5226R~
	}                                                           //~5226I~
  }                                                                //~v66eI~
	if (Scapposx1<=0 && Scapposx2<=0)                           //~v06eR~
		UCBITOFF(Sblockstat,SBLOCKMODE);
	else
		UCBITON(Sblockstat,SBLOCKMODE);
	if (Ssortposx1<0)                                           //~5226R~
		Ssortposx1=0;                                           //~5226I~
	if (Ssortposx2<0)                                           //~5226I~
		Ssortposx2=0;                                           //~5226I~
	return ;
}//capsortpoint
                                                                   //~vbd2I~
//#ifdef WXEXXE                                                      //~vbd2I~//~vbd7R~
//*******************************************************          //~vbd2I~
//void capsortpointselectall(void)                                   //~vbd2I~//~vbd7R~
void capsortpointselectall(int Pswblockmode)                       //~vbd7I~
{                                                                  //~vbd2I~
//*******************                                              //~vbd2I~
	Ssortplh1=Gcapplh1;                                            //~vbd2I~
	Ssortplh2=Gcapplh2;                                            //~vbd2I~
	Ssortposx1=Scapposx1;                                          //~vbd2I~
	Ssortposx2=Scapposx2;                                          //~vbd2I~
  if (Pswblockmode)                                                //~vbd7I~
  {                                                                //~vbd7I~
	UCBITON(Sblockstat,SBLOCKMODE);                                //~vbd7I~
	UCBITOFF(Sblockstat2,SBLOCK2STDREGION);	//Not Blockmode to enable paste to selected//~vbd7I~
  }                                                                //~vbd7I~
  else                                                             //~vbd7I~
  {                                                                //~vbd7I~
	UCBITOFF(Sblockstat,SBLOCKMODE);                               //~vbd2I~
	UCBITON(Sblockstat2,SBLOCK2STDREGION);	//Not Blockmode to enable paste to selected//~vbd2M~
  }                                                                //~vbd7I~
	if (Ssortposx1<0)                                              //~vbd2I~
		Ssortposx1=0;                                              //~vbd2I~
	if (Ssortposx2<0)                                              //~vbd2I~
		Ssortposx2=0;                                              //~vbd2I~
	return ;                                                       //~vbd2I~
}//capsortpointselectall                                           //~vbd2I~
//#endif                                                             //~vbd2R~//~vbd7R~
//*******************************************************       //~v06lI~
//!capgetcsrplh
//* capgetcsrplh                                                //~v06lI~
//* get plh on csr line                                         //~v06lI~
//* retrn:plh                                                   //~v06lI~
//*******************************************************       //~v06lI~
PULINEH capgetcsrplh(PUCLIENTWE Ppcw)                           //~v06lI~
{                                                               //~v06lI~
//*******************                                           //~v06lI~
	if (!CSRONFILELINE(Ppcw))				//out of screen     //~v06lI~
    	return 0;                                               //~v06lI~
	return (Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc;             //~v06lI~
}//capgetcsrplh                                                 //~v06lI~
                                                                //~v06lI~
//*******************************************************       //~v06kI~
//!capchkboxwidth
//* capchkboxwidth                                              //~v06kI~
//*  chk posx is not same when block mode                       //~v06kI~
//* retrn:rc                                                    //~v06kI~
//*******************************************************       //~v06kI~
int capchkboxwidth(PUFILEH Ppfh)                                   //~v0dcR~
{                                                               //~v06kI~
//    int mergin;                                                  //~v0eKR~
//*******************                                           //~v06kI~
//    mergin=Ppfh->UFHmergin;                                      //~v0eKR~
//    if (UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR))   //~v0eKR~
//        if (Ssortposx2>mergin)                                   //~v0eKR~
//            return charmerginerr(mergin);                                    //~51//~v0eKR~
	if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//not started by "start stdregin"//~v66eM~
    {                                                              //~v66eM~
       	if (Ssortposx1==Ssortposx2 && Ssortplh1==Ssortplh2)	//csr not moved//~v66eM~
			return errcsrpos();                                    //~v66eM~
    }                                                              //~v66eM~
    else                                                           //~v66eM~
	if (UCBITCHK(Sblockstat,SBLOCKMODE))	//block closed      //~v06kR~
    {                                                              //~v66eI~
       	if (Ssortposx1==Ssortposx2)                             //~v06kI~
//      	return capcsrposerr();                                 //~v0i8R~
			return errcsrpos();                                    //~v0i8I~
    }                                                              //~v66eI~
	return 0;                                                   //~v06kI~
}//capchkboxwidth                                               //~v06kI~
                                                                //~v06kI~
//*******************************************************          //~v155I~
//!cap_savecalcinfo                                                //~v155I~
//* chk box info and save it as calc data                          //~v155I~
//* parm1:pcw                                                      //~v155I~
//* retrn:rc                                                       //~v155I~
//*******************************************************          //~v155I~
int cap_savecalcinfo(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Ppos1,int Ppos2)//~v158R~
{                                                                  //~v155I~
//*******************                                              //~v155I~
	if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//started by "start stdregin"//~v66eI~
		return caperrregionmode();                                 //~v66eI~
	if (Pplh1)                                                     //~v158I~
    {                                                              //~v158I~
        Gcalcpcw=Ppcw;                                             //~v158I~
        Scalcblockstat=SBLOCKCLOSED;                               //~v158I~
        Gcalcplh1=Pplh1;                                           //~v158I~
        Gcalcplh2=Pplh2;                                           //~v158I~
        Scalcposx1=Ppos1;                                          //~v158I~
        Scalcposx2=Ppos2;                                          //~v158I~
    }                                                              //~v158I~
    else                                                           //~v158I~
    {                                                              //~v158I~
        if (Ppcw!=Gcappcw)  //not block mode                       //~v158R~
            return capnoblockerr();                                //~v158R~
        if (!UCBITCHK(Sblockstat,SBLOCKCLOSED)) //block not closed //~v158R~
			return capnoblockerr();                                //~v158R~
        Gcalcpcw=Gcappcw;                                          //~v158R~
        Scalcblockstat=Sblockstat;                                 //~v158R~
        Gcalcplh1=Ssortplh1;                                       //~v158R~
        Gcalcplh2=Ssortplh2;                                       //~v158R~
        Scalcposx1=Ssortposx1;                                     //~v158R~
        Scalcposx2=Ssortposx2;                                     //~v158R~
    }                                                              //~v158I~
	uerrmsg("First Operand Block for TC cmd",                      //~v155I~
			"TCコマンド第一オペランドブロック");                   //~v155I~
	return 0;                                                      //~v155I~
}//cap_savecalcinfo                                                //~v155R~
//*******************************************************          //~v155I~
//!cap_calcrev                                                     //~v155R~
//* reverse display for target calc box by find mechanism          //~v155R~
//* parm1:pcw                                                      //~v155I~
//* retrn:rc                                                       //~v155I~
//*******************************************************          //~v155I~
int cap_calcrev(void)                                              //~v155I~
{                                                                  //~v155I~
	PULINEH plh;                                                   //~v155I~
	PUFILEH pfh;                                                   //~v155I~
	int width,findctr;                                             //~v155R~
//*******************                                              //~v155I~
	pfh=UGETPFH(Gcalcplh1);                                        //~v158R~
    width=Scalcposx2-Scalcposx1;                                   //~v155I~
	findctr=++pfh->UFHfindctr;//find cmd ctr for disply current;   //~v155R~
	for (plh=Gcalcplh1;plh;)                                       //~v158R~
	{                                                              //~v155I~
    	if (plh->ULHtype==ULHTDATA)                                //~v155I~
        {                                                          //~v155I~
			plh->ULHrevoffs=(USHORT)Scalcposx1;                    //~v155I~
			plh->ULHrevlen=(USHORT)width;                          //~v155I~
			plh->ULHrevctr=findctr;//find cmd ctr for disply current;//~v155I~
			UCBITOFF(plh->ULHflag2,ULHF2MFOUND);//reset multiple   //~v155I~
			UCBITON(plh->ULHflag,ULHFDRAW|ULHFCURFOUND);//draw word after wordrep//~v155I~
			UCBITOFF(plh->ULHflag,ULHFCURCAP);//reset hilight reason cap//~v155I~
        }                                                          //~v155I~
		if (plh==Gcalcplh2)                                        //~v158R~
        	break;                                                 //~v155I~
		plh=UGETQNEXT(plh);                                        //~v155I~
    }                                                              //~v155I~
	return 0;                                                      //~v155I~
}//cap_calcrev                                                     //~v155I~
//*******************************************************          //~v155I~
//!cap_getcalccurinfo                                              //~v155I~
//* get curr cap box info                                          //~v155I~
//* parm1:pcw                                                      //~v155I~
//* parm2:cap line from                                            //~v155I~
//* parm3:cap line to                                              //~v155I~
//* parm4:box start pos                                            //~v155I~
//* parm5:box end pos                                              //~v155I~
//* retrn:rc                                                       //~v155I~
//*******************************************************          //~v155I~
int cap_getcalcprevinfo(PUCLIENTWE *Pppcw,PULINEH *Ppplh1,PULINEH *Ppplh2,int *Pppos1,int *Pppos2)//~v155R~
{                                                                  //~v155I~
//*******************                                              //~v155I~
	if (!Gcalcpcw)	//not block mode                               //~v158R~
    {                                                              //~v155I~
    	uerrmsg("No target block specified",                       //~v155I~
        		"宛先ブロックの指定無し");                         //~v155R~
		return 4;                                                  //~v155I~
	}                                                              //~v155I~
	if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//started by "start stdregin"//~v66eI~
		return caperrregionmode();                                 //~v66eI~
	if (!UCBITCHK(Scalcblockstat,SBLOCKCLOSED))	//block not closed //~v155I~
		return capnoblockerr();                                    //~v155I~
	*Pppcw=Gcalcpcw;                                               //~v158R~
	*Ppplh1=Gcalcplh1;                                             //~v158R~
	*Ppplh2=Gcalcplh2;                                             //~v158R~
	*Pppos1=Scalcposx1;                                            //~v155R~
	*Pppos2=Scalcposx2;                                            //~v155R~
	return 0;                                                      //~v155I~
}//capd_getcalcprevinfo                                            //~v155I~
//*******************************************************          //~v155I~
//!cap_getcalccurinfo                                              //~v155I~
//* get curr cap box info                                          //~v155I~
//* parm1:pcw                                                      //~v155I~
//* parm2:cap line from                                            //~v155I~
//* parm3:cap line to                                              //~v155I~
//* parm4:box start pos                                            //~v155I~
//* parm5:box end pos                                              //~v155I~
//* retrn:rc                                                       //~v155I~
//*******************************************************          //~v155I~
int cap_getcalccurinfo(PUCLIENTWE Ppcw,PULINEH *Ppplh1,PULINEH *Ppplh2,int *Pppos1,int *Pppos2)//~v155I~
{                                                                  //~v155I~
//*******************                                              //~v155I~
	if (Ppcw!=Gcappcw)	//not block mode                           //~v155I~
		return capnoblockerr();                                    //~v155I~
	if (UCBITCHK(Sblockstat2,SBLOCK2STDREGION))	//started by "start stdregin"//~v66eI~
		return caperrregionmode();                                 //~v66eI~
	if (!UCBITCHK(Sblockstat,SBLOCKCLOSED))	//block not closed     //~v155I~
		return capnoblockerr();                                    //~v155I~
	*Ppplh1=Ssortplh1;                                             //~v155I~
	*Ppplh2=Ssortplh2;                                             //~v155I~
	*Pppos1=Ssortposx1;                                            //~v155R~
	*Pppos2=Ssortposx2;                                            //~v155R~
	return 0;                                                      //~v155I~
}//capd_getcalccurinfo                                             //~v155I~
////*******************************************************        //~v0i8R~
////!capcsrposerr(void)                                            //~v0i8R~
////* capcsrposerr                                                 //~v0i8R~
////* parm:none                                                    //~v0i8R~
////* retrn:4                                                      //~v0i8R~
////*******************************************************        //~v0i8R~
//int capcsrposerr(void)                                           //~v0i8R~
//{                                                                //~v0i8R~
////*******************                                            //~v0i8R~
//    uerrmsg("Invalid cursor position",                           //~v0i8R~
////          "カーソル位置の誤り");                               //~v0i8R~
//            "カー\x83\\ル位置の誤り");                           //~v0i8R~
//    return 4;                                                    //~v0i8R~
//}//capcsrposerr                                                  //~v0i8R~
//                                                                 //~v0i8R~
//*******************************************************       //~5603I~
//!capcberr
//* capcberr                                                    //~5603I~
//* parm:none                                                   //~5603I~
//* retrn:4                                                     //~5603I~
//*******************************************************       //~5603I~
int capcberr(void)                                              //~5603I~
{                                                               //~5603I~
//*******************                                           //~5603I~
	uerrmsg("Cannot operate Cut/Paste on clipboard file",       //~5603I~
//  		"このファイル上で切り貼りはできません");               //~v095R~
    		"このファイル上で切り\x93\\りはできません");           //~v095I~
	return 4;                                                   //~5603I~
}//capcberr                                                     //~5603I~
                                                                //~5603I~
//*******************************************************          //~v0heI~
//!capmsgsaved                                                     //~v0heI~
//* saved capdata msg                                              //~v0heI~
//* parm:none                                                      //~v0heI~
//* retrn:0                                                        //~v0heI~
//*******************************************************          //~v0heI~
void capmsgsaved(void)                                             //~v0heI~
{                                                                  //~v0heI~
//*******************                                              //~v0heI~
	uerrmsg("Copyed to Clipboard",                                 //~v0heI~
    		"クリップボードに複写");                               //~v0heI~
	return;                                                        //~v0heI~
}//capmsgsaved                                                     //~v0heI~
                                                                   //~v0heI~
//*******************************************************          //~v0heI~
//!capnoblockerr                                                   //~v0heI~
//* errmsg issue                                                   //~v0heI~
//* parm:none                                                      //~v0heI~
//* retrn:4                                                        //~v0heI~
//*******************************************************          //~v0heI~
int capnoblockerr(void)                                            //~v0heI~
{                                                                  //~v0heI~
//*******************                                              //~v0heI~
    uerrmsg("Block is not specified",                              //~v0heI~
            "ブロックが未指定");                                   //~v0heI~
    return 4;                                                      //~v0heI~
}//capnoblockerr                                                   //~v0heI~
//#ifdef WXE                                                       //~v641R~
//#ifdef WXEXXE                                                      //~v641I~//~vbd7R~
////****************************************************************//~v502R~
//// chk paste pos is on file area                                 //~v502R~
////pcol      :-1 :2nd line                                        //~v502R~
////pcmdbuff  :optional output cmd buff                            //~v502R~
////pcw       :optional output pcw at the pos                      //~v502R~
////rc:0;cmd set,0:filearea,1:file lineno fld,2:cmdline copyed;4:paste not avail//~v502R~
////****************************************************************//~v502R~
//int capchkpastepos(int Prow,int Pcol,char *Pcmdbuff,PUCLIENTWE *Pppcw)//~v502R~
//{                                                                //~v502R~
//    PUCLIENTWE pcw;                                              //~v502R~
//    PUFILEC    pfc;                                              //~v502R~
//    PUFILEH    pfh;                                              //~v502R~
//    UFLDE     *pfld;                                             //~v502R~
//    PUSCRD     psd;                                              //~v502R~
//    int pcwtype,psdpos,rc,poss,pose,len,col,row;                 //~v502R~
////**********************                                         //~v502R~
//    psdpos=scrcpgetpcw(Prow,Pcol,&pcw);                          //~v502R~
//    row=pcw->UCWrcsry;                                           //~v502R~
//    col=pcw->UCWrcsrx;                                           //~v502R~
//    psd=pcw->UCWpsd+psdpos;                                      //~v502R~
//    pcwtype=pcw->UCWtype;                                        //~v502R~
//    rc=4;       //paste not avail position                       //~v502R~
//    if (psdpos==CMDLINENO)                                       //~v502R~
//    {                                                            //~v502R~
//        pfld=getuflde(pcw,CMDLINENO,0);  //no need dbcstbl       //~v502R~
//        poss=pfld->UFLstart;                                     //~v502R~
//        pose=pfld->UFLend;                                       //~v502R~
//        if (col>=poss && col<pose)                               //~v502R~
//        {                                                        //~v502R~
//            rc=-1;                                               //~v502R~
//            if (Pcmdbuff)                                        //~v502R~
//            {                                                    //~v502R~
//                len=funcgetlongcmd(pcw,Pcmdbuff);   //input on cmdline//~v502R~
//                if (poss+len<col)                                //~v502R~
//                {                                                //~v502R~
//                    memset(Pcmdbuff+len,' ',col-poss-len);       //~v502R~
//                    *(Pcmdbuff+col-poss)=0;    //for caller strlen//~v502R~
//                }                                                //~v502R~
//                rc=-(col-poss);        //do direct copy          //~v502R~
//            }                                                    //~v502R~
//        }                                                        //~v502R~
//    }                                                            //~v502R~
//    else                                                         //~v502R~
//        if (pcwtype==UCWTFILE                                    //~v502R~
//        &&  row>=pcw->UCWfilehdrlineno                           //~v502R~
//        &&  row<pcw->UCWmaxline)                                 //~v502R~
//        {                                                        //~v502R~
//              pfc=pcw->UCWpfc;                                   //~v502R~
//              pfh=pfc->UFCpfh;                                   //~v502R~
////            if (Pcmdbuff)                                      //~v502R~
////            {                                                  //~v502R~
////                pfc=pcw->UCWpfc;                               //~v502R~
////                if (sw2nd)      //shift to left most           //~v502R~
////                    if (pfc->UFCleft)                          //~v502R~
////                        sprintf(Pcmdbuff,"LEFT max;POS %d,%d;",row,pcw->UCWlinenosz);//~v502R~
////                    else                                       //~v502R~
////                        sprintf(Pcmdbuff,"POS %d,%d;",row,pcw->UCWlinenosz);//~v502R~
////                else                                           //~v502R~
////                    sprintf(Pcmdbuff,"POS %d,%d;",row,col);    //~v502R~
////            }                                                  //~v502R~
//            if (pfh->UFHtype!=UFHTCLIPBOARD)                     //~v502R~
//                rc=0;                                            //~v502R~
//        }                                                        //~v502R~
//    if (Pppcw)                                                   //~v502R~
//        *Pppcw=pcw;                                              //~v502R~
//    return rc;                                                   //~v502R~
//}//capchkpastepos                                                //~v502R~
//**************************************************************** //~v502I~
// chk cut pos is on file area                                     //~v502I~
//pcol 		:-1 :2nd line                                          //~v502I~
//pcmdbuff  :optional output cmd buff                              //~v502I~
//pcw       :optional output pcw at the pos                        //~v502I~
//rc:0;cmd set,0:filearea,1:file lineno fld,2:cmdline copyed;4:paste not avail//~v502I~
//   3:pan fld                                                     //~v76jI~
//**************************************************************** //~v502I~
int capchkcsrpos(int Prow,int Pcol,PUCLIENTWE *Pppcw)              //~v502I~
{                                                                  //~v502I~
    PUCLIENTWE pcw;                                                //~v502I~
    PUFILEC    pfc;                                                //~v502I~
    PUFILEH    pfh;                                                //~v502I~
    UFLDE     *pfld;                                               //~v502I~
//  PUSCRD     psd;                                                //~v502I~//~vaa7R~
    int pcwtype,psdpos,rc,poss,pose,col,row;                       //~v502R~
//**********************                                           //~v502I~
	psdpos=scrcpgetpcw(Prow,Pcol,&pcw);                            //~v502R~
    row=Prow-pcw->UCWorgy;  //rcsrx may not set yet(cap pan case)  //~v502R~
    col=Pcol-pcw->UCWorgx;                                         //~v502I~
//  psd=pcw->UCWpsd+psdpos;                                        //~v502I~//~vaa7R~
    pcwtype=pcw->UCWtype;                                          //~v502I~
    rc=4;		//paste not avail position                         //~v502I~
    if (psdpos==CMDLINENO)                                         //~v502I~
    {                                                              //~v502I~
	    pfld=getuflde(pcw,CMDLINENO,0);  //no need dbcstbl         //~v502I~
        poss=pfld->UFLstart;                                       //~v502I~
        pose=pfld->UFLend;                                         //~v502I~
        if (col>=poss && col<pose)                                 //~v502I~
        	rc=2;                                                  //~v502I~
    }                                                              //~v502I~
    else                                                           //~v502I~
	if (((PUPANELC)pcw->UCWppc)->UPCid==PANFNAME)                  //~v76bR~
    {                                                              //~v76bI~
    	if (row==PANL300FILENAME                                   //~v76bI~
        ||  row==PANL300DIR)                                       //~v76bI~
        {                                                          //~v76bI~
			pfld=getuflde(pcw,row,0);     //cmd line fld           //~v76bR~
	        poss=pfld->UFLstart;                                   //~v76bI~
    	    pose=pfld->UFLend;                                     //~v76bI~
        	if (col>=poss && col<pose)                             //~v76bI~
        		rc=2;                                              //~v76bI~
        }                                                          //~v76bI~
    }                                                              //~v76bI~
    else                                                           //~v76bI~
	if (((PUPANELC)pcw->UCWppc)->UPCid & PANUTIL)                  //~v76jI~
    {                                                              //~v76jI~
		if (fldprotchk(pcw,FPC_DBCSCHK,0)>=0)		//0:no output UFLD; not protected//~v76jI~
        	rc=3;		//paste avail pan fld                      //~v76jI~
    }                                                              //~v76jI~
    else                                                           //~v76jI~
		if (pcwtype==UCWTFILE                                      //~v502I~
    	&&  row>=pcw->UCWfilehdrlineno                             //~v502I~
		&&  row<pcw->UCWmaxline)                                   //~v502I~
        {                                                          //~v502I~
        	pfc=pcw->UCWpfc;                                       //~v502I~
            pfh=pfc->UFCpfh;                                       //~v502I~
            if (pfh->UFHtype!=UFHTCLIPBOARD)                       //~v502I~
	            rc=0;                                              //~v502I~
            else                                                   //~v502I~
        		if (col<pcw->UCWlinenosz)                          //~v502I~
            		rc=1;                                          //~v502I~
        }                                                          //~v502I~
    if (Pppcw)                                                     //~v502I~
	    *Pppcw=pcw;                                                //~v502I~
    return rc;                                                     //~v502I~
}//capchkcsrpos                                                    //~v502I~
#ifdef WXEXXE                                                      //~vbd7I~
//**************************************************************** //~v69ZI~
// return status flag                                              //~v69ZI~
//**************************************************************** //~v69ZI~
void capgetxestat(char *Ppstat1,char *Ppstat2)                     //~v69ZI~
{                                                                  //~v69ZI~
//**********************                                           //~v69ZI~
    if (Ppstat1)                                                   //~v69ZI~
		*Ppstat1=Sblockstat;                                       //~v69ZR~
    if (Ppstat2)                                                   //~v69ZI~
		*Ppstat2=Sblockstat2;                                      //~v69ZR~
    return;                                                        //~v69ZI~
}//capgetxestat                                                    //~v76bR~
#endif                                                             //~v500I~
//*******************************************************          //~vaunI~
//!func_copywordcmd on Dir list                                    //~vaunI~
//* copy word on cursor to cmdline                                 //~vaunI~
//* parm1:pcw                                                      //~vaunI~
//* retrn:rc                                                       //~vaunI~
//*******************************************************          //~vaunI~
int func_copywordcmd_dir(PUCLIENTWE Ppcw)                          //~vaunI~
{                                                                  //~vaunI~
    char *pword;   //word get area                                 //~vaunR~
    char word[MAXCOLUMN+1];   //word get area                      //~vaunI~
    UCHAR  *flddata;                                               //~vaunI~
    int cmdlen,addlen,opt,wordct;                                  //~vaunR~
    char *pdddata,*pdddbcs;                                        //~vauGR~
    int u8len,ddlen,lclen,opt2;                                    //~vauGR~
#ifdef W32UNICODE                                                  //~vauGI~
    char wordstrip[MAXCOLUMN+1];   //word get area                 //~vauGI~
#endif                                                             //~vauGI~
//*******************                                              //~vaunI~
    scrclearmsg(Ppcw);                                             //~vaunR~
//  addlen=dirgetword(Ppcw,word,sizeof(word),&wordct);             //~vaunI~//~vauGR~
    addlen=dirgetword(Ppcw,word,sizeof(word)-1,&wordct,&pdddata,&pdddbcs,&ddlen);//~vauGR~
    if (!addlen)                                                   //~vaunI~
        return 4;                                                  //~vaunI~
    *(word+addlen)=0;                                              //~vauGR~
    opt=0;                                                         //~vaunR~
#ifdef W32UNICODE                                                  //~vavaR~//~vauGI~
//  ufilecvstripUD(0,word,addlen,wordstrip,sizeof(wordstrip),&addlen);                //~vavaR~//~vavkR~
    ufilecvstripUD(0,word,addlen,wordstrip,sizeof(wordstrip),&addlen,NULL/*pct*/,NULL/*pcto*/);//~vavkR~
    pword=wordstrip;                                               //~vauGR~
#else                                                              //~vavaR~//~vauGI~
    pword=word;                                                    //~vaunR~
#endif                                                             //~vauGI~
    if (!(getfldpos(Ppcw,CMDLINENO,0,&flddata,0/*no dbcs out*/)))	//no dbcs parm//~vaunI~
        return 4;                                                  //~vaunI~
    cmdlen=(int)strlen(flddata);                                   //~vaunI~
    if (cmdlen+addlen>=UPCCMDFLDWKSZ-1)                            //~vaunR~
    	return errtoolong();                                       //~vaunI~
	opt=0;                                                         //~vaunI~
    if (wordct==XEUTFCT_UTF8)                                      //~vauDI~
    {                                                              //~vauGR~
        opt2=0;                                                    //~vauGI~
    //*for fcmdrfind chk Gcmdbuff funccmdstack:SETCT option        //~vauGI~
    	if (xeutfcvdd2fl(opt2,Ppcw,pdddata,pdddbcs,ddlen,          //~vauGR~
				Gcmdbuffu8,sizeof(Gcmdbuffu8),&u8len,              //~vauGR~
    			Gcmdbufflc,Gcmdbuffdbcs,Gcmdbuffct,sizeof(Gcmdbufflc),&lclen)>=4)//~vauGR~
            return 4;                                              //~vauGR~
        Gcmdbufflclen=lclen;                                       //~vauGR~
        opt|=SFDDCUO_UTF8;               //from func_copyword_dir;membername is utf8//~vauGR~
        opt|=SFDDCUO_SETCT2;//mixedstrupdate                       //~vauGR~
    }                                                              //~vauGR~
    else                                                           //~vauDI~
    if (wordct==XEUTFCT_LC)                                        //~vauDI~
        opt|=SFDDCUO_LC;                                           //~vauDI~
	setflddatadbcscmd_byutf8(opt,Ppcw,cmdlen,pword,Gcmdbuffdbcs,addlen);//~vaunR~//~vauGR~
	csrhomepos(0/*current panel*/);                                //~vawJI~
    UTRACEP("func_copywordcmd_dir cmdlen=%d,codetype=%d,word=%s\n",cmdlen,wordct,pword);                             //~vaunI~//~vauDR~
	return 0;                                                      //~vaunI~
}//func_copywordcmd_dir                                            //~vaunI~
//*******************************************************          //~vbd7I~
int capselectallfilecmdhelp(PUCLIENTWE Ppcw)                       //~vbd7R~
{                                                                  //~vbd7I~
//*********************************                                //~vbd7I~
//  uerrmsg("Sel All [col1 col2]",0);                              //~vbd7I~//~vbdrR~
    uerrmsg("Sel [All] [col1 col2] [.label1 .label2]",0);          //~vbdrI~
    return 1;                                                      //~vbd7I~
}//capselectallfilecmdhelp                                         //~vbd7I~
//*******************************************************          //~vbd7I~
//* selectall cmd                                                  //~vbd7I~
//*******************************************************          //~vbd7I~
//int capselectallfilecmdblock(PUCLIENTWE Ppcw,int Pcol1,int Pcol2)  //~vbd7I~//~vbdrR~
int capselectallfilecmdblock(PUCLIENTWE Ppcw,int Pcol1,int Pcol2,PULINEH Pplh1,PULINEH Pplh2)//~vbdrI~
{                                                                  //~vbd7I~
    PULINEH plh;                                                   //~vbd7I~
	int rc;                                                        //~vbd7I~
//*******************                                              //~vbd7I~
    capreset(1);	//keep calc pcw                                //~vbd7I~
	if (Pcol1<0)                                                   //~vbd7I~
//  	rc=capselectallfilecmdstd(Ppcw);                           //~vbd7R~//~vbdrR~
    	rc=capselectallfilecmdstd(Ppcw,Pplh1,Pplh2);               //~vbdrI~
    else                                                           //~vbd7I~
//		rc=capselectallfilecmdblocksub(Ppcw,Pcol1,Pcol2);          //~vbd7R~//~vbdrR~
  		rc=capselectallfilecmdblocksub(Ppcw,Pcol1,Pcol2,Pplh1,Pplh2);//~vbdrI~
    rc=capchkcsrpos(Gcsrposy,Gcsrposx,0/*Pppcw*/);                 //~vbd7I~
    if (rc==2)	//on cmdline                                       //~vbd7I~
		func_nextline(Ppcw); //bypass capchkcsrpos <-- wxe_capprotchk to enable pasteV menuitem//~vbd7I~
    if (!rc)                                                       //~vbd7I~
    {                                                              //~vbd7I~
        for (plh=Gcapplh1;plh;plh=UGETQNEXT(plh))                  //~vbd7I~
        {                                                          //~vbd7I~
            if (plh->ULHtype==ULHTDATA)                            //~vbd7I~
                UCBITON(plh->ULHflag,ULHFDRAW|ULHFBLOCK);          //~vbd7I~
        }                                                          //~vbd7I~
    }                                                              //~vbd7I~
	return rc;                                                     //~vbd7I~
}//capselectallfilecmdblock                                        //~vbd7I~
//*******************************************************          //~vbd7I~
//SEL/S cmd on file panel                                          //~vbd7R~
//*******************************************************          //~vbd7I~
int capselectallfilecmd(PUCLIENTWE Ppcw,PUFILEH Ppfh)              //~vbd7I~
{                                                                  //~vbd7I~
	int rc=0;                                                      //~vbd7R~
    int ii,opdno,col1=-1,col2=-1;                                  //~vbd7I~
    UCHAR *pc;                                                     //~vbd7R~
    int nonlabelopdno=0;                                           //~vbdrI~
    PULINEH plh1=0,plh2=0;                                         //~vbdrI~
    UPODELMTBL *podt;                                              //~v47iI~//~vbdrI~
//*********************************                                //~vbd7I~
    UTRACEP("%s",0,UTT);                                           //~vbd7I~
    rc=fcmdgetlabparm(Ppcw,0,&plh1,&plh2,FCGLP_SPLITCHK|FCGLP_0IFNOLAB);	//label on split line is err//~vbdrR~
    if (rc)                                                        //~vbdrI~
    	return rc;                                                 //~vbdrI~
	pc=Ppcw->UCWopdpot;                                            //~vbd7I~
	opdno=Ppcw->UCWopdno;                                          //~vbd7I~
    podt=Ppcw->UCWopddelmt;                                        //~v47iI~//~vbdrI~
//  for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)                      //~vbd7R~//~vbdrR~
    for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1,podt++)               //~vbdrI~
    {                                                              //~vbd7I~
      	if ((*pc==ULCCMDLABEL && !podt->upoquate))  //start by . but not in quate//~vbdrI~
    		continue;                                              //~vbdrI~
//        switch (ii)                                                //~vbd7R~//~vbdrR~
//        {                                                          //~vbd7I~//~vbdrR~
//        case 0:                                                    //~vbd7I~//~vbdrR~
//            if (stricmp(pc,"ALL"))                                 //~vbd7I~//~vbdrR~
//                return capselectallfilecmdhelp(Ppcw);              //~vbd7R~//~vbdrR~
//            break;                                                 //~vbd7I~//~vbdrR~
//        case 1:                                                    //~vbd7I~//~vbdrR~
//            col1=atoi(pc);                                         //~vbd7I~//~vbdrR~
//            break;                                                 //~vbd7I~//~vbdrR~
//        case 2:                                                    //~vbd7I~//~vbdrR~
//            col2=atoi(pc);                                         //~vbd7I~//~vbdrR~
//            break;                                                 //~vbd7I~//~vbdrR~
//        default:                                                   //~vbd7I~//~vbdrR~
//            return errtoomany();                                   //~vbd7R~//~vbdrR~
//        }                                                          //~vbd7I~//~vbdrR~
        if (!stricmp(pc,"ALL"))                                    //~vbdrI~
        	continue;                                              //~vbdrI~
        nonlabelopdno++;                                           //~vbdrI~
        switch (nonlabelopdno)                                     //~vbdrI~
        {                                                          //~vbdrI~
        case 1:                                                    //~vbdrI~
            col1=atoi(pc);                                         //~vbdrI~
            break;                                                 //~vbdrI~
        case 2:                                                    //~vbdrI~
            col2=atoi(pc);                                         //~vbdrI~
            break;                                                 //~vbdrI~
        default:                                                   //~vbdrI~
            return errtoomany();                                   //~vbdrI~
        }                                                          //~vbdrI~
    }                                                              //~vbd7I~
    if (col1>=0)                                                   //~vbd7I~
    {                                                              //~vbd7I~
    	if (col2<=col1)                                            //~vbd7I~
            return capselectallfilecmdhelp(Ppcw);                  //~vbd7R~
    }                                                              //~vbd7I~
//  rc=capselectallfilecmdblock(Ppcw,col1,col2);                   //~vbd7I~//~vbdrR~
    rc=capselectallfilecmdblock(Ppcw,col1,col2,plh1,plh2);         //~vbdrI~
	return rc;                                                     //~vbd7I~
}//capselectallfilecmd                                             //~vbd7I~
