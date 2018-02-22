//*CID://+vbi2R~:                             update#=  685;       //+vbi2R~
//*************************************************************
//*xefcmd2.c                                                       //~v53FR~
//*  find/change/exclude                                           //~v11kR~
//****************************************************************////~v438R~
//vbi2:180211 (BUG) revRfind with Alt(PSF)/Ctl(PSP) was mixed(But now no effect because no caller)//+vbi2I~
//vb50:160827 accept S+A/C+extended key                            //~vb50I~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vax1:140625 (BUG:Win)find ucs2 failes(searchs ucs4), U4 is not only for change cmd repword but for search word//~vax1I~
//vaw4:140528 (Win:UNICODE)escsrch by 3byte unicode                //~vaw4I~
//vafd:120608 (VC6)Bug found by C4701                              //~vafdI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//va7s:100823 (BUG)searchword recover fail for EBC file(u8str saved but recovery is by simple getmixword//~va7sI~
//va7b:100817 (BUG)and search on ebc file,rfind on next session faile by "no ebcdic data";//~va7bI~
//            (utf8 data was not saved for Sescsrchachar2)         //~va7bI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va41:100326 (BUG)Global var clear overfows                       //~va41I~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            fcmd2.c :escsrch on dd str                           //~va20I~
//va1H:091118 (BUG)tab srch sw not saved on ini file fort 2nd of & srch//~va1HI~
//va1G:091117 (UTF8)add UTF8 trans err char Find/Change function   //~va1GI~
//va0y:090720_add UTF8 to Unicode find option  U[B|L|8] (Big/Little Endian/utf8)//~va0yI~
//va0c:090711 Unicode find option  U[B|L] (Big/Little Endian,default is OS endian)//~va0cI~
//v79V:081028 save and restore search word(A+[) between sessions.  //~v79VI~
//v79L:081020 change cmd support P'..' fmt as target string specification(=(same),<(lower),>(upper) is special char)//~v79LI~
//v78e:080310 supprt find cmd search patern by P'.'                //~v78eI~
//v78d:080308 screen grep support                                  //~v78dI~
//v785:080229 (LNX:BUG)on curses version, Ctrl+[ is trated as 011b,//~v785I~
//            and Alt+{|} (A+S+[|]) is same as A+[|] 1b00/2b00.    //~v785I~
//            so chk Shift bit at function of A+[|]                //~v785I~
//v77E:080203 FW(C+"["/"]")/IW(A+"["|"]") cmd support              //~v77ER~
//v76U:071104 make "find multi reverse" sticky over session        //~v76UI~
//v741:070203*(BUG)2nd word of AND srch is not saved on ini file.(rfind faile after session restart)//~v741I~
//v73d:070111*split fcmd2 to fcmd25 fcmd26                         //~v73dI~
//v72P:061214 add ic cmd(case insensitive change)                  //~v72PI~
//v71U:061112 (BUG)accept insert in short(<mergin) record of margined file//~v71UI~
//v692:060418 display expand file-description field(from attr field)//~v670I~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~v649I~
//v649:050617 Rfind case sensitivity cvhange;set sensitive after Change//~v649I~
//            current sensitibity is from (I)Find cmd before Change.it is flexible,so change spec//~v649I~
//v635:050428 move fcmdgetstartplhoffs from xefcmd2.c xefcmd23.c   //~v635I~
//v634:050428 support *G for 2nd opd of & search                   //~v634I~
//v633:050428 (BUG of v54V)find cmd;duplicate line step forward when ulsrch all//~v633I~
//v632:050427 find cmd;support grepline search by *G               //~v632I~
//v62f:050314 change matching specification "*= & n "-->"*=Mn"     //~v62fI~
//v62e:050314 (BUG)n of *=n is not saved to ini                    //~v62eI~
//v62d:050312 matching cmd;find *= col1 col2 & ^* col3 col4        //~v62dI~
//v62c:050312 multireverse option by single foundctr(continuous chk is no problem)//~v62cI~
//v62b:050312 for -m[n] option of find cmd;assign mfwtbl for each pfh to avoid copy and copyback each time//~v62bI~
//v62a:050311 -m option of find cmd to keep previous reverse       //~v62aI~
//v61h:050226 find cmd set label option(-lxxx)                     //~v61hI~
//v61b:050213 accept minus -a parm of x *= (same search) previously rejected by "-a -b range err"//~v61bI~
//v614:050212 find with -d<0; if string1 and string2 is same,it mean join myself//~v614I~
//            so issue warning                                     //~v614I~
//v613:050212 (BUG)find with -a/-b;"range err" errmsg is overrided by "not found" errmsg//~v613R~
//v612:050212 (BUG)find with -j;join fail stop search but no err notification issued.//~v612R~
//v59Z:041218 find cmd:csr line position option -c[R|L][{T|B}[n]]  //~v59ZR~
//v59T:041207 dirlist resizeing                                    //~v59TI~
//v58Z:041026 (BUG)x *= all:count of excluded part duplicated      //~v58ZI~
//v58r:040923 find cmd option -je:join to eof(line range2) if 2nd word not found//~v58rI~
//v57e:040519 (BUG)find with -j option cmd ABEND if 1st found plh is joind(Sandplh1 is deleted)//~v57eI~
//v550:040202 (BUG) find cmd has to check enclosed for "*\n"       //~v550I~
//v54Z:040202 find cmd:search "x y" at eol by EOL option("a b"\n is fmt err by parse())//~v54ZI~
//            (\n is treated as esc char 0x0a,so use *\n without EOL to search eol)//~v54ZI~
//v54W:040131 find cmd performance tuning                          //~v54WI~
//            scroll page search not excluded line;                //~v54WI~
//            for & search 1st match and 2nd unmatch case,consume cpu when all excluded//~v54WI~
//v54V:040131 find cmd:step to next line whe -a or -b option used  //~v54WR~
//v54R:040125 find cmd:max record pos search by max pos parm       //~v54RI~
//v54B:040120 exclude logic performance up for "(i)x all" cmd      //~v54BI~
//v54z:040118 support eolsrch with any str;*\n, "*"\n is for srch * at eol//~v54zR~
//v54a:040102 dirlist; use ts/size field for for long filename     //~v54aI~
//v548:040102 (BUG)found offset change if joind with befote line   //~v548I~
//v547:040102 (BUG)abend bu find with join option when -b is specified//~v547I~
//            because found plh is deleted by lcmdjoin             //~v547I~
//v53F:031018 find cmd;not found msg not displayed when 2nd word search err of and srch with -d//~v53FI~
//v539:030920 join option for find; {i|f}[nx] -j                   //~v539I~
//v537:030920 find/change allkx option(keep excluded)              //~v537I~
//v536:030920 x cmd performance up                                 //~v536I~
//v532:030915 2 cols pos parm for & search                         //~v532I~
//v51s:030608 & search support for dir list                        //~v51sI~
//v50v:030113 (BUG)find word tbl is not fully used                 //~v50vI~
//v49e:020630 (BUG)same string display on srch err msg of and srch //~v49eI~
//v49d:020629 to exclude from 1st same "x *= -b"                   //~v49dI~
//v49b:020623 support *= for not only "(i)x all" but also "(i)find"//~v49bI~
//v496:020617 find *L (search lineserch result;for after == lcmd)  //~v496I~
//v481:020420 (BUG)dir list search required ddsetup.(not found for not displayed line)//~v481I~
//v47B:020321 find at eol  xxxx\n Ssrch and Ssrch2(& srearch)      //~v47BI~
//v47z:020319 (BUG) & search highlight 1st and 2nd word,and found ctr is accum of 2 word//~v47zR~
//v47t:020315 minus support for -a -b                              //~v47tI~
//v47i:020302 join cmd support:"join nx/x .a .b"                   //~v47iI~
//            join cmd use getstartoffs(-->fcmdgetstartplhoffs)    //~v47iI~
//v43x:011116 save 2nd word of & search                            //~v43wI~
//v43w:011116 ! for also word2 of & search                         //~v43wI~
//v43s:011111 (BUG) find *& loop when word1 is after the word2     //~v43sI~
//v43q:011102 (BUG) *u *& word faile to search;allow *u/*e only on opd1//~v43qI~
//v43o:011031 allow *& between 2 word                              //~v43oI~
//v43j:011101 not found msg for *&                                 //~v43iI~
//v43i:011031 distance option <,>,= (default is =)                 //~v43iI~
//v43h:011030 (BUG)no highlight pair when on the same line         //~v43hI~
//v43g:011030 save each find word len for multiple word search case//~v43gI~
//            (spanded or *& case)                                 //~v43gI~
//v43f:011030 (BUG)missed highlight of spanned for search all case //~v43fI~
//v43e:011026 find cmd option;f *& word1 word2 -dn                 //~v43eI~
//v43d:011026 find cmd option to always set csr to leftmost        //~v43dR~
//v43c:011026 X cmd need search on already excluded line           //~v43cI~
//            for the case -a -b option specified or spanned case  //~v43cI~
//v43b:011026 (BUG)valiable not initialized case exist             //~v43bI~
//v439:011024 (BUG)when non-excluded+excluded spaned case,spaned line is not displayed.//~v439I~
//v438:011024 (BUG)when exclude+non-exclude spanned case,undo delete the line//~v439R~
//v437:011024 add unexclude range optio to find cmd                //~v437I~
//v41s:010830 (BUG) *u/*e search dose not match wit top(next search) or last(last search).//~v41sI~
//v41r:010830 except search "*!" prefix; "i *! word" fmt           //~v41rI~
//            file screen only;no chnage avail                     //~v41rI~
//v40L:010716 add option to "x *= all" of minimum same lineno      //~v40LI~
//v40J:010714 change fmt "x =all" to "x *= all"                    //~v40JR~
//v40H:010714 change spec:C a b-->F c-->f6==>C c b;                //~v40HI~
//            issue err to not active change mode                  //~v40HI~
//v40G:010714 (BUG) f5(rfind) exclude line when after "x all"/"x =all"//~v40GI~
//            (save and restore exclusesw/subcmdid over "x all"/"x =all")//~v40GI~
//v40z:010625 column range support for x =all(same as above)       //~v40zI~
//v40p:010603 add x =all (exclude same as above line)              //~v40zR~
//v21n:010114 LINUX support:wordrep may dsetroy dbcs conbination   //~v21nI~
//v19E:000904 LINUX support(like XE!UNDEL-->XE_UNDEL; ! has mean to bash)//~v19EI~
//v183:001209 long filename display on dirlist;expand to rename fld//~v183I~
//v182:001209 long filename display on dirlist(over attr fld)      //~v19EI~
//v13p:991106 find/rep consideration for bin file                  //~v13pR~
//v13o:991106 find fail;search word containing space will unmatch with tab+word line//~v13oI~
//            before tab expanded.                                 //~v13oI~
//v13h:991029 (BUG)prev find may fail if line has tab and search word expanded to//~v13hI~
//            the offset out of non-expnaded len.                  //~v13hI~
//v11N:990829 COL cmd support                                      //~v11NI~
//v11s:990808 (BUG) not allowed \x string search if \x09 is contained.Allow to bin file.//~v11sI~
//v11p:990725 accept "EXClude all" (no search word  case)          //~v11pI~
//v11o:990720 (BUG)compatibility to DOS;find parm save len change int to SHORT//~v11oI~
//v11n:990720 set debug trace for find cmd/shift lcmd beep         //~v11nI~
//v11k:990718 Find/change/Exclude cmd help                         //~v11kI~
//v11g:990717 set found line in the middle of page                 //~v11gI~
//v10V:990605 (BUG)drop Prev bug(dest change after rfind key with search word)//~v10VI~
//v10U:990605 wrap also when find cmd not found like as rfind      //~v10UI~
//v10T:990605 protect search word is null;for change all no csr advance and//~v10TI~
//            line expand to max line length and stop at there.    //~v10TI~
//            Allow only when exclude cmd to for the case all line exclude//~v10TI~
//v10R:990508 (BUG)change works on browse screen                   //~v10RI~
//v10Q:990508 (BUG)pf6 set and leave casesense-sw,it may be better //~v10QI~
//            to keep it over f6 for f5.                           //~v10QI~
//v10o:990324 (BUG)abend by find cmd on dirlist if line is excluded by x-dlcmd//~v10oI~
//                 -->on dirlist,search limit to displayed line only//~v10oI~
//v10n:990324 Find/Ifind NX (FNX/INX) cmd;search not excluded line only//~v10nI~
//            (on dir list,search on display line only;see v10o)   //~v10oI~
//v0iu:980717 cmd compare by strcpy not by memcpy because i and iii is dup//~v0iuI~
//v0il:980626 (BUG)string on find errmsg is of previous for f */*e //~v0ilI~
//v0hI:980418 (BUG)max operand number incleased change a b all col1 col2 lab1 lab2//~v0hII~
//v0hH:980418 (BUG)last/prev search with label fail if last/csr line len is shorter//~v0hHI~
//            than label line.offset should be reset by last label line.//~v0hHI~
//v0hF:980418 (BUG)Swrapsw need clear for find(not rfind)          //~v0hFI~
//                (Swrapsw on by rfind,the find cmd issue re-searched msg)//~v0hFI~
//v0hE:980418 bypass each found msg for all search for performance up//~v0hEI~
//v0hD:980418 (BUG)Sdirstep effect on search all on edit/browse(skip Sdirstep)//~v0hDI~
//                 it cause find miss next word on same line.      //~v0hDI~
//v0hB:980418 (BUG)change a b,find *u.rchange-->chnage update line by b.//~v0hBI~
//                 so,repword clear at *u/*e(next rchange is not availe//~v0hBI~
//                 because no repword)                             //~v0hBI~
//v0hz:980412 EXCLUDE/IEXCLUDE cmd support                         //~v0hzI~
//v0hx:980410 label lcmd support for find etc.                     //~v0hxI~
//            alternative of v0hk and  v0hw is not needed anymore. //~v0hxI~
//v0hu:980410 not scroll left/right for find if word is in the range//~v0huI~
//            even if it is inthe range of leftmost page.          //~v0huI~
//            user may not want scroll.(deny v068)                 //~v0huI~
//v0hk:980214 support line range by A/B for find/change all cmd    //~v0hdI~
//v0hd:980126 allow (shift+)pf5+"i xxx"/"f xxx"                    //~v0hdI~
//v0fi:971021 step to next column when find on dir                 //~v0fiI~
//v0fh:971019 find cmd on dir list;allow search on time field etc. //~v0fhI~
//            distinguish ifind and find.                          //~v0fhI~
//v0fc:971018 vfat flag should be on ufh not but ufc because uddname created by it//~v0fcI~
//v0f9:971017 UFCFLFN flag for lfn(common to os2/w95/gcc/dos)      //~v0f9I~
//v0f7:971014 long filename support                                //~v0f7I~
//            search on dir list,it may be hiddlen if too long     //~v0f7I~
//v0f6:971012 (BUG)reverse pos err for find dirlist when indent opt=0//~v0f0R~
//v0f0:971010 long filename support                                //~v0f0I~
//            offset not by MAXFILENAME but field size(refind dose not step)//~v0f0I~
//v0eH:970926 if err return,it should not to set Srange1/2         //~v0eHI~
//v0eG:970926 (BUG)of wrap search;after session restart it is wrap search//~v0eGI~
//            because notfoundctr=0 which match with Gkbdinpctr(=0)//~v0eGI~
//v0eF:970926 (BUG)of v0eB;return before clear Swrapsw cause abend //~v0eFI~
//            because of missing set plh before linesrchstring.    //~v0eFI~
//v0eD:970926 (BUG)of v0eB;read range must be from first record    //~v0eDI~
//v0eB:970923 find/change range support                            //~v0eBI~
//v0ey:970920 v0eq to change cmd                                   //~v0eyI~
//v0ew:970922 split fcmd2 to fcmd22                                //~v0ewI~
//v0ev:970922 abondan /v0ep/v0er/v0es/v0eu;                        //~v0euI~
//            use filetabexp2(expand in mergin only)               //~v0euI~
//v0eu:970921 (BUG)same as v0er for change cmd                     //~v0euI~
//v0et:970921 split char12 from char                               //~v0dvI~
//v0e3:970914 allow change cmd on out of mergin                    //~v0e3I~
//v0dv:970914 spf scroll for find/change cmd                       //~v0dvI~
//v0c2:970728 simple principle.do not touch/move out of mergin     //~v0c2I~
//            if mergin not specified,last space is not dropped    //~v0c2I~
//v0bv:970728 split file4-->file42                                 //~v0bvI~
//v0bt:970727 allow rep in the mergin by change cmd                //~v0btI~
//v0bs:970727 chand esc search req cmd fmt *\__-->\__              //~v0bqI~
//v0bq:970727 support find *e(search err line)                     //~v0bqR~
//v0b7:970725 filemerginchk return avail space(last data to mergin)//~v0b7I~
//v0b4:970724 (BUG)simple coding miss.1 byte esc forward search abend.//~v0b4I~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//           -charmaxovererr has maxlen parm                       //~v0avI~
//           -expand pre chk(split file2 to file6)                 //~v0avI~
//v0ap:970713 no length limit for esc seq search(hex char must be even number)//~v0apI~
//v0a9:970707:preserve bin serach cmd for xe!save!                 //~v0a9I~
//v0a6:970706:(BUG)reverse for find overflow line which is previously//~v0a6I~
//                 reverse by find cmd.                            //~v0a6I~
//v0a1:970705:NULL data accept as 0x00.and change str___ to mem___ //~v0a1I~
//v09Y:970629:file NULL(0x00) support                              //~v09YI~
//            set dbcstbl(new function for file area only)   sub   //~v09YI~
//v09P:970625:reject inhibit char input by change esc cmd(Gbl ptr) //~v09PI~
//v09O:970625:allow repl esc other than \t(same as srch char except 0x00)//~v09OI~
//v09N:970625:allow srch esc char only 1 byte.                     //~v09NR~
//v09M:970623:(BUG)change cmd leave half of DBCS or TAb padd       //~v09MI~
//v09L:970622:Find/Change *\x__,*\a etc(no support for replacing char)//~v09LI~
//v09J:970621:(BUG)Re-change after Change xx ""(NULL) cause "At first use Change cmd"//~v09JI~
//            (BUG)Re-change after find cause "At first use Change cmd"//~v09JI~
//v09I:970621:Find/Change *\t support(search tab char)             //~v09IR~
//v09H:970617:(BUG)reverse offset err for not first line for       //~v09eI~
//            find *u(update line) all                             //~v09eI~
//v09e:970517:update  line search by *u (identify by offset==-1)   //~v09eI~
//v09d:970517:identify "*" and * for find cmd                      //~v09dI~
//v09c:970515:re-search from  top/last after not found by rfind    //~v09cI~
//v095:970405:DPMI version                                         //~v095I~
//            -not used variable                                   //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//v085:961024:W95 VC(warning)                                      //~v085I~
//v084:961001:(BUG)for dir list find,revese req once match as current pos//~v084I~
//v083:961001:(BUG)hilight pos for dir list find when muched after '.'//~v083I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07r:960828:(BUG)storage ovwrwrite when find word overflow       //~v07rI~
//            max check missed at first time multiple(2 find word on a line)//~v07rI~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//v068:960224:find scroll position,shift to one more left       //~v068I~
//v064:960217:split inifile for Ginitscroll/Giniopt_/Ginifiletabskip//~v064I~
//v05w:951203:find cmd for dir list                             //~v05wI~
//v05v:951203:(BUG)find all offset table shared,it must be for each pfh//~v05vI~
//v053:951014:file name change for find parm !FIND! --> XE!FIND!//~v053I~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dR~
//*v033:950715:SCROLL cmd for dir list scroll(err msg by xeerr.c)//~v033I~
//*v013 950624 find scroll size(export calc half scroll size func)//~v013I~
//*************************************************************
//*950520 write find parm string only when string is not null   //~5520I~
//*950504 UCWparm commonly set by funccall at xefunc            //~5504I~
//*       command post process by funcopdpostp                  //~5504I~
//*       save cmd env to file and use after restart            //~5504I~
//*       case bug when rfind/rchng                             //~5504I~
//*950422 hilight curr cap block or find block                  //~5422R~
//*950302 destination: pf5:use prev dest,S+pf5:change direction and search//~5422I~
//*950114 destination: pf5:use prev cmd destination(ignore S+pf5)//~5302I~
//*                    s+pf5:always backword search             //~5114I~
//*950106 change cmd                                            //~5114I~
//*941210 all bug                                               //~5106I~
//*941126 rfind_prev
//*941126 multiple found word on the same line
//*941120 func_find                                             //~5104R~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ualloc.h>                                             //~5318I~

#ifdef DOS
#else
  #ifdef OS2                                                       //~v78eI~
    #define INCL_BASE                                              //~v78eR~
    #include <os2.h>                                               //~v78eR~
  #endif                                                           //~v78eI~
#endif
//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <uerr.h>
#include <uparse.h>                                                //~v0b2R~
#include <ustring.h>                                               //~v0b2I~
#include <ufile.h>                                              //~5318R~
#include <uedit.h>                                                 //~v09LI~
#include <utrace.h>                                                //~v11nI~
#include <ukbd.h>                                                  //~v785I~
#ifdef UTF8UCS2                                                    //~va20I~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefile.h"
#include "xefile2.h"                                               //~v0avI~
#include "xefile3.h"                                            //~v013I~
#include "xefile42.h"                                              //~v0bvR~
#include "xefile6.h"                                               //~v0avI~
#include "xedir.h"                                              //~v05wI~
#include "xedir2.h"                                                //~v481I~
#include "xedir3.h"                                                //~v182R~
#include "xechar.h"                                             //~5124I~
#include "xechar12.h"                                              //~v0dvI~
#include "xelcmd.h"
#include "xelcmd2.h"
#include "xelcmd4.h"       //join                                  //~v539I~
#define XEFCMD2_GLOBAL                                             //~v73dI~
#include "xefcmd2.h"
#include "xefcmd22.h"                                              //~v0ewI~
#include "xefcmd23.h"                                              //~v13pI~
#include "xefcmd24.h"	//x =all                                   //~v40pI~
#include "xefcmd5.h"	//x =all                                   //~v50vI~
#include "xefunc.h"
#include "xefunc2.h"  	//funccmdstack                             //~v0hdI~
#include "xefunct.h"                                               //~v09dI~
#include "xeundo.h"                                             //~5106I~
#include "xesub.h"                                              //~5318R~
#include "xefsub.h"                                             //~5318I~
#include "xeerr.h"                                              //~v033I~
//*******************************************************
#define SUBCMDSZ 6
//#define MAXMFWTENTRY 1000                                        //~v43hI~
//#define CMDFIND         0                                        //~vbCBR~
//#define CMDCHANGE       1                                        //~vbCBR~
//#define RC_EXC_ALL  	2                                          //~v73dR~
//#define RC_EXC_ALLSAME  3   //exclude same as above              //~v73dR~
//#define RC_STOP_SRCH  121   //stop all search by join fail etc   //~v73dR~
//#define RC_ERR_NOTNF  122   //not err,but later errmsg           //~v73dR~
                                                                   //~v41rI~
//#define OFFS_TOP        1   //start from top line                //~v62dR~
//#define OFFS_LAST       2   //start from top line                //~v62dR~
                                                                   //~v41rI~
#ifdef UNX                                                         //~v19EI~
	#define FCMDPARMFILE	"xe_find_"                             //~v19EI~
#else                                                              //~v19EI~
	#define FCMDPARMFILE	"XE!FIND!"                             //~v19EI~
#endif                                                             //~v19EI~
                                                                   //~v47BI~
//#define EOLSRCHID  "\\n"        //eol search id                  //~v73dR~
//#define EOLIDLEN   2                                             //~v73dR~
//#define EOLSRCHIDANY  "*\\n"        //eol search without preceding strng specification//~v73dR~
//#define EOLSRCHIDAST  "\"*\"\\n"    //search * at eol            //~v73dR~
//#define MATCHINGID   'M'            //"*=M"                      //~v73dR~
//*******************************************************
#define OTHERSW_NOTSRCH   	0x80                                   //~v41rI~
#define OTHERSW_TABSRCH  	0x40                                   //~v09II~
#define OTHERSW_TABREP   	0x20                                   //~v0apI~
#define OTHERSW_NOTSRCH2   	0x10                                   //~v43wI~
#define OTHERSW_REPNULL  	0x08                                   //~v09JI~
#define OTHERSW_EXCLUDE  	0x04                                   //~v0hzI~
#define OTHERSW_NXSRCH   	0x02                                   //~v10oI~
#define OTHERSW_ANDSRCH  	0x01                                   //~v43wI~
#define OTHERSW2_EXTENDED 	0x80                                   //~v47BR~
#define OTHERSW2_EOLSRCH2 	0x40                                   //~v47BI~
#define OTHERSW2_EOLSRCH  	0x20                                   //~v47BI~
#define OTHERSW2_TABSRCH2  	0x10     //tabsrch for 2nd of & srch   //~va1HR~
#define SAVE_EXTDATASZ  256          //save data extention size    //~v47BI~
#ifndef UTF8UCS2	//moved to xefcmd2.h                           //~va20I~
#define SAVE_SRCHWORDSZ 128          //save data extention size    //~v79VI~
#endif                                                             //~va20I~
                                                                   //~v47BI~
typedef union _SAVE_EXTDATA           /* ftime */                  //~v47BI~
             {                                                     //~v47BI~
             	char extbuff[SAVE_EXTDATASZ];                      //~v47BI~
                struct _SAVE_EXTDATA_STR                           //~v47BI~
                       {                                           //~v47BI~
                       		int dist;                              //~v47BI~
                            int aft;                               //~v47BI~
                            int bef;                               //~v47BI~
                            int minsame;                           //~v62eI~
                            ULONG extflag;                         //~v741I~
#define EXTFLAG_ESCSRCH2    0x80000000    //                       //~v741I~
#define EXTFLAG_MULTIREV    0x40000000    //multiple reverse option(-m)//~v76UI~
#define EXTFLAG_GREP        0x20000000    //multiple reverse option(-m)//~v78dI~
#define EXTFLAG_GREPP       0x10000000    //P'.'                   //~v78eI~
#define EXTFLAG_GREPPTARGET 0x08000000    //P'.'  charnge pattern  //~v79LI~
#define EXTFLAG_SRCHWORD    0x04000000    //serchword saved        //~v79VI~
#define EXTFLAG_SEARCH_UCS     0x02000000    // UCS option         //~va0cI~
#define EXTFLAG_SEARCH_UCS2    0x01000000    // UCS for 2nd word option//~va0cI~
#define EXTFLAG_SEARCH_UCSBE   0x00800000    //BigEndian option    //~va0cI~
#define EXTFLAG_SEARCH_UCSBE2  0x00400000    //BigEndian option for 2nd word//~va0cI~
#define EXTFLAG_SEARCH_UTF8    0x00200000    //UTF8 option         //~va0yI~
#define EXTFLAG_SEARCH_UTF82   0x00100000    //UTF8 option for 2nd word//~va0yI~
#define EXTFLAG_SEARCH_UTF8EC  0x00080000    //UTF8 trans err char srch//~va1GR~
#define EXTFLAG_SEARCH_UTF8EC2 0x00040000    //UTF8 trans err char srch for 2nd word//~va1GR~
#define EXTFLAG_SEARCH_UTF8ECR 0x00020000    //UTF8 trans err reset, accept as locale code//~va1GI~
#define EXTFLAG_SEARCH_UCS2WORD  0x00010000                        //~va20I~
//#ifdef UTF8UCS4                                                    //~va1CI~//~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
#define EXTFLAG_SEARCH_UCS4      0x00008000   //repword by ucs4    //~va3xI~
#endif                                                             //~va1CI~//~va3xI~
#define EXTFLAG_SEARCH_DDSTR2    0x00004000   //Ssearchword contains utf8 data//~va7bM~
#define EXTFLAG_SEARCH_EBCWORD   0x00002000   //Ssearchword contains utf8 data for EBC data//~va7sI~
#define EXTFLAG_SEARCH_UCS4SW    0x00001000  //UCS4 is for 1st word//~vax1R~
#define EXTFLAG_SEARCH_UCS4SW2   0x00000800  //UCS4 UCS42 is for 2nd word of & search//~vax1I~
                            char escsrch2[64];	//top 1byte:strlen //~v741I~
             				char srchword[SAVE_SRCHWORDSZ];        //~v79VI~
                       } struc;                                    //~v47BI~
             } SAVE_EXTDATA;                                       //~v47BI~
//*******************************************************          //~v09II~
//static UCHAR Sfindpfile[]={WORKDIRPATHID FCMDPARMFILE};          //~v095R~
                                                                //~5114I~
//static  UCHAR *Sulsrchid="*U";                                   //~v73dR~
//static  UCHAR *Selsrchid="*E";                                   //~v73dR~
//static  UCHAR *Sllsrchid="*L";  //research last line search      //~v73dR~
//static  UCHAR *Sgrepsrchid="*G";  //search grepline              //~v73dR~
//static  UCHAR Seqsrchid[]="*=";                                  //~v73dR~
//static  UCHAR Smatchingid[]="*=M";                               //~v73dR~
//static  char Ssrch[MAXCOLUMN];                                   //~v73dR~
//static  char Ssrch2[MAXCOLUMN];     //for *&,2nd word            //~v73dR~
//static  char Srepword[MAXCOLUMN];                                //~v73dR~
//static  int  Ssrchlen=0;                                         //~v73dR~
//static  int  Ssrchlen2=0;                                        //~v73dR~
//static  char Seolsrchsw=0,Seolsrchsw2=0;        //eol req id     //~v73dR~
//static  int  Srepwordlen;                                        //~v73dR~
//static  int  Ssubcmdid=0;                                        //~v73dR~
//static  int  Scasesensesw;      //case sensitive sw              //~v73dR~
//static  int  Schangeopt=0;  //for rchange after rfind            //~v73dR~
//static  int Spfhfindctr=0;                                       //~v73dR~
//static  PUFILEH Spfhmatching=0; //2nd scr pfh for matching       //~v73dR~
//static  int  Sallkxinpctr=0;                                     //~v73dR~
//static  int  S2ndofallsw=0; //2nd search of all                  //~v73dR~
//static  PULINEH Sfoundplh=0;    //found line                     //~v73dR~
//static  PULINEH Splhafter=0;    //plh by -a option,0 if before found plh//~v73dR~
//static  int  Sfoundoffs=0;  //found word top offset              //~v73dR~
//static  int  Sstep=0;           //for rfind/rchange step         //~v73dR~
//static  int  Sdirstep=0;        //step after dir list filename find//~v73dR~
//static  int  Sdirstepr=0;   //for reverse serch                  //~v73dR~
//static  int  Sfoundctr=0;       //found count                    //~v73dR~
////static    int  Smfwtindex=0;  //Gfilemfwtbl index              //~v73dR~
//static  int  Smfwtovf=0;        //found count at Gfilemfwtbl overflow//~v73dR~
//static  LONG Sovflineno=0;                                       //~v73dR~
//static  ULONG Sovfoffset=0;                                      //~v73dR~
//static  int  Sovfsuffix=0;                                       //~v73dR~
//static  int  Snotfinpctr=0; //Gkbdinpctr resulted not found to chk wrap ope//~v73dR~
//static  int  Sfindcmdinpctr=0;  //to chk continued operation of rfind//~v73dR~
//static  char Swrapsw;       //reqid to wrap for linesrchstring   //~v73dR~
//                                                                 //~v73dR~
//static  char Sulsrchsw=0;   //1:update line search,2:errline search//~v73dR~
//static  char Sulsrchsw2=0;  //for 2nd opd of & srch              //~v73dR~
//static  int  Sscrollpendsw=0;   //set when 1st word found        //~v73dR~
//static  char Snotsrchsw=0;    //*! search                        //~v73dR~
//static  char Snotsrchsw2=0;    //*! search                       //~v73dR~
////static  char Srangeerr2;    //2nd word not found in the distance//~v73dR~
//static  UCHAR Sescsrchchar[MAXCOLUMN];  //escape sequence srch char//~v73dR~
//static  UCHAR Sescsrchchar2[MAXCOLUMN]; //for 2nd word of *&     //~v73dR~
//static  UCHAR Sescrepchar[MAXCOLUMN];   //escape sequence repl char//~v73dR~
//static  char Sescsrchlen;   //escape sequence char len           //~v73dR~
//static  char Sescsrchlen2;   //escape sequence char len          //~v73dR~
//static  char Sescreplen;    //replace to escape sequence len(1or 2)//~v73dR~
//static  char Stabsrchsw;    //tab search                         //~v73dR~
//static  char Sphasesw;      //1st/2nd word search phase of *&    //~v73dR~
//static  char Stabsrchsw2;   //tab search for *&                  //~v73dR~
//static  char Stabrepsw;     //repword contain tab                //~v73dR~
//static  char Srepnull=0;        //rep to null sw                 //~v73dR~
//static  char Sexcludesw;    //exclude cmd active                 //~v73dR~
//static  char Sexcludesw2=0; //exclude cmd active on edit/browse(0 when dir list screen)//~v73dR~
//static  int  Snxsw;         //nx line only sw                    //~v73dR~
//static  char Supctrsw;      //exclude/include occuerd(for undo)  //~v73dR~
//static  char Sallxfound=0;                                       //~v73dR~
////static int Srange1=0,Srange2=0,Srangeid1=0,Srangeid2=0;     //search change range//~v73dR~
//static  SHORT Srange1=0,Srange2=0,Srangeid1=0,Srangeid2=0;     //search change range//~v73dR~
//static  SHORT Srange1and=0,Srange2and=0,Srangeid1and=0,Srangeid2and=0;     //for and srch//~v73dR~
//static int Slinebefore=0,Slineafter=0,Slinedist=0;  //display line after,before found line//~v73dR~
//static int Sminsame=0;        //minimum same line count to exclude//~v73dR~
////static PULINEH Srangeplhs,Srangeplhe;                          //~v73dR~
//static PULINEH Srangeplhe;                                       //~v73dR~
//static PULINEH Srangeplhe2; //for 2nd word range of *&           //~v73dR~
//static PULINEH Ssrcherrplh=0;                                    //~v73dR~
//static int Slinerangesw;    //1:out of range                     //~v73dR~
////static    int  Sreadsw;       //once initial read sw           //~v73dR~
//static  PULINEH Sspanplh=0;     //word spaned to multiple line for bin//~v73dR~
//static  PULINEH Sandplh1=0;     //1st word plh of *&             //~v73dR~
//static  PULINEH Ssamelastplh=0; //last plh of same line(after first plh even if prev srch)//~v73dR~
//static  LONG    Ssamelinectr=0; //same line count                //~v73dR~
//static int  Sfindopt=0; //cmd parm option flag                   //~v73dR~
//static ULONG Sfindopt2=0;   //cmd parm option flag2              //~v73dR~
//static int  Sothopt=0;  //cmd parm option flag                   //~v73dR~
//static int  Sothererr_abrange=0;    //not notfound err count:ab range err//~v73dR~
//static int  Sothererr_selfjoin=0;   //not notfound err count:join myself case//~v73dR~
//static char Ssetlabel[ULHLINENOSZ];    //-l parm operand ptr     //~v73dR~
//**********
int fcmdfind(PUCLIENTWE Ppcw,int Pcasesw,int Pchangeopt,int Pbackopt,int Pnxopt);//~v10oR~
//int fcmdrfind(PUCLIENTWE Ppcw,int Preverse,int Pchangeopt);      //~vbCBR~
//int linesrchstring(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Plocatesw,//~v73dR~
//					int Pchangeopt,int Psubcmdid);                 //~v73dR~
//int linesrchstringsub(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Plocatesw,//~v73dR~
//					int Pchangeopt,int Psubcmdid);                 //~v73dR~
//int getstartoffs(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset);  //~v47iR~
//int operandchk(PUCLIENTWE Ppcw,UCHAR *Popd,int Pchangeopt,int Pbackward);//~v73dR~
//int wordrep(PUCLIENTWE Ppcw,PULINEH Pplh,int Poffset);           //~v73dR~
//char *fcmdescsrch(char *Ppc,int Pdirection,int Poffset);         //~v73dR~
//int fcmdrfparm(void);                                         //~v064R~
//int fcmdsrcherr(int Pchangeopt,int Plocatesw,int Psubcmdid,PULINEH Pplh);//~v73dR~
//int fcmdesctabchk(int Popt,PUFILEH Ppfh,UCHAR *Pstring,int Plen);//~v73dR~
//int fcmdaroundline(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,int Plinebefore,int Plineafter,//~v49bR~
//					int Pexcludesw2);                              //~v49bR~
//int fcmdaroundline(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PULINEH Psamelastplh,//~v547R~
//                    int Plinebefore,int Plineafter,int Pexcludesw2);//~v547R~
//int fcmdaroundline(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh,PULINEH Psamelastplh,//~v548R~
//                    int Plinebefore,int Plineafter,int Pexcludesw2);//~v548R~
//int fcmdaroundline(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Ppplh,PULINEH Psamelastplh,//~v73dR~
//                    int Plinebefore,int Plineafter,int Pexcludesw2,int *Ppoffs);//~v73dR~
//int fcmdallxchk(PULINEH Pplh,PULINEH Pspanplh,PULINEH Psnaplh1,int Plinebefore,int Plineafter);//~v49bR~
//int fcmdallxchk(PULINEH Pplh,PULINEH Pspanplh,PULINEH Psamelastplh,PULINEH Psnaplh1,int Plinebefore,int Plineafter);//~v73dR~
//int fcmdspannedline(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PULINEH Pspannedplh,//~v73dR~
//					PULINEH Psamelastplh,int Psubcmdid,            //~v73dR~
//					int Pexcludesw2,int Plocatesw);                //~v73dR~
//int fcmdaroundlinesub(PULINEH Pplh,int Plinebefore,int Plineafter,//~v49bR~
//					PULINEH *Pplh1,PULINEH *Pplh2);                //~v49bR~
//int fcmdaroundlinesub(PULINEH Pplh,PULINEH Psamelastplh,         //~v73dR~
//					int Plinebefore,int Plineafter,PULINEH *Pplh1,PULINEH *Pplh2);//~v73dR~
//int fcmdothererrmsgcat(int Psubcmdid);                           //~v73dR~
//****************************************************************
//****************************************************************
// func_find_file
//*find command
//*ret  :rc                                                     //~5106R~
//****************************************************************
int func_find_file(PUCLIENTWE Ppcw)
{
    Sexcludesw=0;                                                  //~v0hzI~
	return fcmdfind(Ppcw,1,CMDFIND,0,0);	//case sensitive,dest in cmd opd,no NX//~v10oR~
}//func_find_file

//****************************************************************
//!func_ifind_file
//*case insensitive search
//*ret  :rc                                                     //~5106R~
//****************************************************************
int func_ifind_file(PUCLIENTWE Ppcw)
{
    Sexcludesw=0;                                                  //~v0hzI~
	return fcmdfind(Ppcw,0,CMDFIND,0,0);//case insense,dest in cmd opd,no NX//~v10oR~
}//func_ifind_file

//**************************************************************** //~v40GI~
//save/restore sw for the case "x all"/"x=all"                     //~v40GI~
//*ret  :none                                                      //~v40GI~
//**************************************************************** //~v40GI~
void fcmd2saverestorx(int Psave)	//save for the case "x all"/"x=all"//~v40GI~
{                                                                  //~v40GI~
	static  char Sexcludeswsv;	//exclude cmd active               //~v40JR~
	static  int  Ssubcmdidsv;                                      //~v40JI~
	static  SHORT Srange1sv,Srange2sv;                             //~v40JI~
	static  SHORT Srange1andsv,Srange2andsv;                       //~v532I~
//***************************                                      //~v40GI~
	if (Psave)                                                     //~v40GI~
    {                                                              //~v40GI~
		Sexcludeswsv=Sexcludesw;	//exclude cmd active           //~v40GI~
		Ssubcmdidsv=Ssubcmdid;	//exclude cmd active               //~v40JI~
		Srange1sv=Srange1;                                         //~v40JI~
		Srange2sv=Srange2;                                         //~v40JI~
		Srange1andsv=Srange1and;                                   //~v532I~
		Srange2andsv=Srange2and;                                   //~v532I~
	}                                                              //~v40GI~
    else                                                           //~v40GI~
    {                                                              //~v40GI~
		Sexcludesw=Sexcludeswsv;	//exclude cmd active           //~v40GI~
		Ssubcmdid=Ssubcmdidsv;	//exclude cmd active               //~v40JI~
		Srange1=Srange1sv;                                         //~v40JI~
		Srange2=Srange2sv;                                         //~v40JI~
		Srange1and=Srange1andsv;                                   //~v532I~
		Srange2and=Srange2andsv;                                   //~v532I~
	}                                                              //~v40GI~
    return;                                                        //~v40GI~
}//fcmd2saverestorx                                                //~v40GI~
//**************************************************************** //~v0hzI~
//!func_exclude_file                                               //~v0hzI~
//*find and exclude                                                //~v0hzI~
//*ret  :rc                                                        //~v0hzI~
//**************************************************************** //~v0hzI~
int func_exclude_file(PUCLIENTWE Ppcw)                             //~v0hzI~
{                                                                  //~v0hzI~
    fcmd2saverestorx(1);	//save for the case "x all"/"x=all"    //~v40GI~
    Sexcludesw=1;                                                  //~v0hzI~
	return fcmdfind(Ppcw,1,CMDFIND,0,0);	//case sensitive,dest in cmd opd,no NX//~v10oR~
}//func_exclude_file                                               //~v0hBR~
                                                                   //~v0hzI~
//**************************************************************** //~v0hzI~
//!func_iexclude_file                                              //~v0hzI~
//*case insensitive search and exclude                             //~v0hzI~
//*ret  :rc                                                        //~v0hzI~
//**************************************************************** //~v0hzI~
int func_iexclude_file(PUCLIENTWE Ppcw)                            //~v0hzI~
{                                                                  //~v0hzI~
    fcmd2saverestorx(1);	//save for the case "x all"/"x=all"    //~v40GI~
    Sexcludesw=1;                                                  //~v0hzI~
	return fcmdfind(Ppcw,0,CMDFIND,0,0);//case insense,dest in cmd opd,no NX//~v10oR~
}//func_iexclude_file                                              //~v0hBR~
                                                                   //~v0hzI~
//**************************************************************** //~v10nI~
//!func_findnx_file                                                //~v10nI~
//*find NX line only                                               //~v10nI~
//*ret  :rc                                                        //~v10nI~
//**************************************************************** //~v10nI~
int func_findnx_file(PUCLIENTWE Ppcw)                              //~v10nI~
{                                                                  //~v10nI~
    Sexcludesw=0;                                                  //~v10oI~
	return fcmdfind(Ppcw,1,CMDFIND,0,1);	//case sensitive,dest in cmd opd,NX//~v10oR~
}//func_findnx_file                                                //~v10nI~
                                                                   //~v10nI~
//**************************************************************** //~v10nI~
//!func_iexclude_file                                              //~v10nI~
//*case insensitive search and exclude                             //~v10nI~
//*ret  :rc                                                        //~v10nI~
//**************************************************************** //~v10nI~
int func_ifindnx_file(PUCLIENTWE Ppcw)                             //~v10nI~
{                                                                  //~v10nI~
    Sexcludesw=0;                                                  //~v10oI~
	return fcmdfind(Ppcw,0,CMDFIND,0,1);//case insense,dest in cmd opd,NX//~v10oR~
}//func_ifindnx_file                                               //~v10nI~
                                                                   //~v10nI~
//****************************************************************
//!func_rfind_file
//*rfind command(forword repeat find)                           //~5106R~
//*ret  :rc                                                     //~5106R~
//****************************************************************
int func_rfind_file(PUCLIENTWE Ppcw)
{
	return fcmdrfind(Ppcw,0,CMDFIND);//no change direction,can change by cmd input//~5302R~
}//func_rfind_file                                              //~5106R~
//****************************************************************
//!func_revrfind_file
//*rfind reverse command(backword repeat find)                  //~5106R~
//*ret  :rc                                                     //~5106R~
//****************************************************************
int func_revrfind_file(PUCLIENTWE Ppcw)
{
//*By funct panfnlfind(PAN func) is not called                     //+vbi2I~
    if (Ppcw->UCWkeyshift & KBDSTF_CONTROL)                        //~vbCBR~
//  	return func_findPSF(Ppcw);                                 //~vbCBI~//+vbi2R~
		return func_findPSP(Ppcw);                                 //+vbi2I~
    if (Ppcw->UCWkeyshift & KBDSTF_ALT)                            //~vbCBR~
//  	return func_findPSP(Ppcw);                                 //~vbCBI~//+vbi2R~
    	return func_findPSF(Ppcw);                                 //+vbi2I~
	return fcmdrfind(Ppcw,1,CMDFIND);	//reverse direction     //~5302R~
}//func_revrfind_file                                           //~5106R~
                                                                //~5106I~
//****************************************************************//~5106I~
//!func_change_file                                             //~5106I~
//*change command                                               //~5106I~
//*ret  :rc                                                     //~5106I~
//****************************************************************//~5106I~
int func_change_file(PUCLIENTWE Ppcw)                           //~5106I~
{                                                               //~5106I~
    Sexcludesw=0;                                                  //~v0hzI~
	return fcmdfind(Ppcw,1,CMDCHANGE,0,0);//case sensitive,dest in cmd opd,no NX//~v10oR~
}//func_change_file                                             //~5106I~
                                                                //~5106I~
//**************************************************************** //~v10nI~
//!func_change_file                                                //~v10nI~
//*change command                                                  //~v10nI~
//*ret  :rc                                                        //~v10nI~
//**************************************************************** //~v10nI~
int func_changenx_file(PUCLIENTWE Ppcw)                            //~v10nI~
{                                                                  //~v10nI~
    Sexcludesw=0;                                                  //~v10oI~
	return fcmdfind(Ppcw,1,CMDCHANGE,0,1);//case sensitive,dest in cmd opd,NX//~v10oR~
}//func_changenx_file                                              //~v10nI~
                                                                   //~v10nI~
//**************************************************************** //~v72PI~
//!func_ichange_file                                               //~v72PI~
//*case insensitive change command                                 //~v72PI~
//*ret  :rc                                                        //~v72PI~
//**************************************************************** //~v72PI~
int func_ichange_file(PUCLIENTWE Ppcw)                             //~v72PI~
{                                                                  //~v72PI~
    Sexcludesw=0;                                                  //~v72PI~
	return fcmdfind(Ppcw,0,CMDCHANGE,0,0);//no case sensitive,dest in cmd opd,no NX//~v72PI~
}//func_change_file                                                //~v72PI~
                                                                   //~v72PI~
//**************************************************************** //~v72PI~
//!func_ichangenx_file                                             //~v72PI~
//*case insensitive change command                                 //~v72PI~
//*ret  :rc                                                        //~v72PI~
//**************************************************************** //~v72PI~
int func_ichangenx_file(PUCLIENTWE Ppcw)                           //~v72PI~
{                                                                  //~v72PI~
    Sexcludesw=0;                                                  //~v72PI~
	return fcmdfind(Ppcw,0,CMDCHANGE,0,1);//no case sensitive,dest in cmd opd,NX//~v72PI~
}//func_changenx_file                                              //~v72PI~
                                                                   //~v72PI~
//****************************************************************//~5106I~
//!func_rchange_file                                            //~5106I~
//*rchange command(forword repeat change)                       //~5106I~
//*ret  :rc                                                     //~5106I~
//****************************************************************//~5106I~
int func_rchange_file(PUCLIENTWE Ppcw)                          //~5106I~
{                                                               //~5106I~
//	Scasesensesw=1;		//case sensitive sw                        //~v10QR~
	return fcmdrfind(Ppcw,0,CMDCHANGE);//no change direction,can change by cmd opd//~5302R~
}//func_rchange_file                                            //~5106I~
                                                                //~5106I~
//****************************************************************//~5106I~
//!func_revrchange_file                                         //~5106I~
//*rchange reverse command(backword repeat change)              //~5106I~
//*ret  :rc                                                     //~5106I~
//****************************************************************//~5106I~
int func_revrchange_file(PUCLIENTWE Ppcw)                       //~5106I~
{                                                               //~5106I~
//  Scasesensesw=1;		//case sensitive sw                        //~v10QR~
	return fcmdrfind(Ppcw,1,CMDCHANGE);	//reverse direction     //~5302R~
}//func_revrchange_file                                         //~5106I~
//**************************************************************** //~v0hdI~
//* find word forward                                              //~v77EI~
//**************************************************************** //~v77EI~
int func_findwordF_file(PUCLIENTWE Ppcw)                           //~v77EI~
{                                                                  //~v77EI~
    if (Ppcw->UCWkeyshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT))  //~v785I~
	    return fcmdsrchword(Ppcw,0/*ifind*/,1/*forward*/);         //~v785I~
    return fcmdsrchword(Ppcw,1/*find*/,1/*forward*/);              //~v77ER~
}//func_findwordF_file                                             //~v77EI~
//**************************************************************** //~v77EI~
//* find word backward                                             //~v77EI~
//**************************************************************** //~v77EI~
int func_findwordB_file(PUCLIENTWE Ppcw)                           //~v77EI~
{                                                                  //~v77EI~
    if (Ppcw->UCWkeyshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT))  //~v785I~
	    return fcmdsrchword(Ppcw,0/*ifind*/,-1/*backword*/);       //~v785I~
    return fcmdsrchword(Ppcw,1/*find*/,-1/*backword*/);            //~v77ER~
}//func_findwordB_file                                             //~v77EI~
//**************************************************************** //~v77EI~
//* ifind word forward                                             //~v77EI~
//**************************************************************** //~v77EI~
int func_ifindwordF_file(PUCLIENTWE Ppcw)                          //~v77EI~
{                                                                  //~v77EI~
    if (Ppcw->UCWkeyshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT))  //~v785I~
	    return fcmdsrchword(Ppcw,1/*find*/,1/*forward*/);          //~v785I~
    return fcmdsrchword(Ppcw,0/*ifind*/,1/*forward*/);             //~v77ER~
}//func_findwordF_file                                             //~v77EI~
//**************************************************************** //~v77EI~
//* ifind word backward                                            //~v77EI~
//**************************************************************** //~v77EI~
int func_ifindwordB_file(PUCLIENTWE Ppcw)                          //~v77EI~
{                                                                  //~v77EI~
    if (Ppcw->UCWkeyshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT))  //~v785I~
	    return fcmdsrchword(Ppcw,1/*find*/,-1/*backword*/);        //~v785I~
    return fcmdsrchword(Ppcw,0/*ifind*/,-1/*backword*/);           //~v77ER~
}//func_findwordB_file                                             //~v77EI~
//**************************************************************** //~v77EI~
                                                                   //~v0hdI~
//**************************************************************** //~vbCBI~
//* find on this file spcific                                      //~vbCBI~
//**************************************************************** //~vbCBI~
int func_findPSF(PUCLIENTWE Ppcw)                                  //~vbCBI~
{                                                                  //~vbCBI~
    int dest=0;                                                    //~vbCBR~
//*************                                                    //~vbCBI~
//  if (Ppcw->UCWkeyshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT))  //~vb50R~
//      dest=1;                                                    //~vb50R~
    UTRACEP("%s:dest=%d\n",UTT,dest);                              //~vbCBR~
    return fcmdsrchPSF(0,Ppcw,dest,CMDFIND);                       //~vbCBR~
}//func_findPSF                                                    //~vbCBR~
//**************************************************************** //~vbCBI~
//* find on this split screen                                      //~vbCBI~
//**************************************************************** //~vbCBI~
int func_findPSP(PUCLIENTWE Ppcw)                                  //~vbCBI~
{                                                                  //~vbCBI~
    int dest=0;                                                    //~vbCBR~
//*************                                                    //~vbCBI~
//  if (Ppcw->UCWkeyshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT))  //~vb50R~
//      dest=1;                                                    //~vb50R~
    UTRACEP("%s:dest=%d\n",UTT,dest);                              //~vbCBR~
    return fcmdsrchPSP(0,Ppcw,dest,CMDFIND);                       //~vbCBR~
}//func_findPSP                                                    //~vbCBR~
//**************************************************************** //~vb50I~
//* find on this split screen                                      //~vb50I~
//**************************************************************** //~vb50I~
int func_revfindPSP(PUCLIENTWE Ppcw)                               //~vb50I~
{                                                                  //~vb50I~
    int dest=1;                                                    //~vb50I~
//*************                                                    //~vb50I~
    return fcmdsrchPSP(0,Ppcw,dest,CMDFIND);                       //~vb50I~
}//func_revfindPSP                                                 //~vb50I~
//**************************************************************** //~vb50I~
//* find on this split screen                                      //~vb50I~
//**************************************************************** //~vb50I~
int func_revfindPSF(PUCLIENTWE Ppcw)                               //~vb50I~
{                                                                  //~vb50I~
    int dest=1;                                                    //~vb50I~
//*************                                                    //~vb50I~
    return fcmdsrchPSF(0,Ppcw,dest,CMDFIND);                       //~vb50I~
}//func_revfindPSF                                                 //~vb50I~
//**************************************************************** //~vbCBI~
//* find on this split screen                                      //~vbCBI~
//**************************************************************** //~vbCBI~
int func_displayPS(PUCLIENTWE Ppcw)                                //~vbCBI~
{                                                                  //~vbCBI~
	fcmddisplayPSall(Ppcw);                                        //~vbCBR~
    return 0;                                                      //~vbCBI~
}//func_displayPS                                                  //~vbCBI~
//**************************************************************** //~vbCBI~
                                                                   //~vbCBI~
////****************************************************************//~v62bR~
////!fcmdcpymfwt                                                   //~v62bR~
////  copy multiword find tbl to pfh                               //~v62bR~
////* parm1 :pfh                                                   //~v62bR~
////*rc   :0                                                       //~v62bR~
////****************************************************************//~v62bR~
//int fcmdcpymfwt(PUFILEH Ppfh)                                    //~v62bR~
//{                                                                //~v62bR~
////    if (!Smfwtindex)    //multiple found                       //~v62bR~
////        return 0;                                              //~v62bR~
////    if (Ppfh->UFHmfwtbl)                                       //~v62bR~
////        ufree(Ppfh->UFHmfwtbl);  //free old                    //~v62bR~
////    Ppfh->UFHmfwtbl=UALLOCM((UINT)(Smfwtindex*sizeof(USHORT)));//~v62bR~
////    UALLOCCHK(Ppfh->UFHmfwtbl,8);    //return 8 if fail        //~v62bR~
////    memcpy(Ppfh->UFHmfwtbl,Gfilemfwtbl,(UINT)(Smfwtindex*sizeof(USHORT)));//~v62bR~
////    return 0;                                                  //~v62bR~
//    return fcmdcpymfwt2(Ppfh,Smfwtindex);                        //~v62bR~
//}//fcmdcpymfwt                                                   //~v62bR~
                                                                //~5504I~
//****************************************************************//~5504I~
//!fcmdwfparm                                                   //~5504I~
// write find parm to work dir file                             //~5504I~
//* parm  :FILE*                                                //~v064R~
//* ret   :rc                                                   //~5504I~
//****************************************************************//~5504I~
int fcmdwfparm(FILE *Pfh)                                       //~v064R~
{                                                               //~5504I~
//  UCHAR fullpath[_MAX_PATH];                                  //~v064R~
//  UCHAR wkbuff[8];                                               //~v09eR~
//  UCHAR wkbuff[12];                                              //~v0a9R~
    UCHAR wkbuff[MAXCOLUMN];                                       //~v0a9I~
    SAVE_EXTDATA wkextdata;                                        //~v47BI~
    UINT len;                                                   //~v064I~
    int othersw=0;                                                 //~v09II~
    int othersw2=0;                                                //~v47BI~
//  FILE *fh;                                                   //~v064R~
//*********************************                             //~5504I~
//  if (!Ssrch[0])	//no cmd entered                            //~v064R~
//  	return 0;                                               //~v064R~
//  if (filefind(Sfindpfile,fullpath,0,FFNONFMSG)>4)//no need fstat3//~v064R~
//      return 8;   //rc=4 not found                            //~v064R~
//  if (!(fh=fileopen(fullpath,"wb")))                          //~v064R~
//      return 12;                                              //~v064R~
//  sprintf(wkbuff,"%1d%1d%1d",Ssubcmdid,Scasesensesw,Schangeopt); //~v09eR~
	if (Stabsrchsw)                                                //~v09II~
    	othersw|=OTHERSW_TABSRCH;                                  //~v09II~
	if (Stabrepsw)                                                 //~v0apI~
    	othersw|=OTHERSW_TABREP;                                   //~v0apI~
	if (Srepnull)                                                  //~v09JI~
    	othersw|=OTHERSW_REPNULL;                                  //~v09JI~
	if (Sexcludesw)                                                //~v0hzI~
    	othersw|=OTHERSW_EXCLUDE;                                  //~v0hzI~
//  if (Snxsw)                                                     //~v73dR~
    if (Gnxsw)                                                     //~v73dI~
    	othersw|=OTHERSW_NXSRCH;                                   //~v10oI~
	if (Snotsrchsw)                                                //~v41rI~
    	othersw|=OTHERSW_NOTSRCH;                                  //~v41rI~
	if (Snotsrchsw2)                                               //~v43wI~
    	othersw|=OTHERSW_NOTSRCH2;                                 //~v43wI~
//  if (Ssrchlen2)                                                 //~v54zR~
    if (Ssrchlen2||Seolsrchsw2)                                    //~v54zI~
    	othersw|=OTHERSW_ANDSRCH;                                  //~v43wI~
//othersw2                                                         //~va1HI~
    othersw2=OTHERSW2_EXTENDED;                                    //~v47BI~
	if (Seolsrchsw)                                                //~v47BI~
    	othersw2|=OTHERSW2_EOLSRCH;                                //~v47BI~
	if (Seolsrchsw2)                                               //~v47BI~
    	othersw2|=OTHERSW2_EOLSRCH2;                               //~v47BI~
	if (Stabsrchsw2)                                               //~va1HM~
    	othersw2|=OTHERSW2_TABSRCH2;                               //~va1HM~
	memset(wkbuff,0,sizeof(wkbuff));                               //~v0a9I~
//  sprintf(wkbuff,"%1d%1d%1d%1d%c;%c%c",                          //~v47BR~
    sprintf(wkbuff,"%1d%1d%1d%1d%c%c%c%c",                         //~v47BI~
					Ssubcmdid,Scasesensesw,Schangeopt,(int)Sulsrchsw,//~v09II~
//  				othersw,Sescsrchlen,Sescreplen);               //~v47BR~
					othersw,othersw2,Sescsrchlen,Sescreplen);      //~v47BI~
	memcpy(wkbuff+8,&Srangeid1,sizeof(Srangeid1));                 //~v0eBR~
	memcpy(wkbuff+8+sizeof(Srangeid1),&Srangeid2,sizeof(Srangeid2));//~v0eBR~
	memcpy(wkbuff+8+sizeof(Srangeid1)+sizeof(Srangeid2),           //~v532I~
				&Srangeid1and,sizeof(Srangeid1and));               //~v532I~
	memcpy(wkbuff+8+sizeof(Srangeid1)+sizeof(Srangeid2)+sizeof(Srangeid1and),//~v532I~
				&Srangeid2and,sizeof(Srangeid2and));               //~v532I~
//	len=fwrite(wkbuff,3,1,Pfh);                                    //~v09eR~
//	len=fwrite(wkbuff,8,1,Pfh);     //8byte,rsv 4 byte             //~v0a9R~
//	len=fwrite(wkbuff,sizeof(wkbuff),1,Pfh);     //8byte,rsv 4 byte//~v0a9I~//~vb31R~
  	len=(UINT)fwrite(wkbuff,sizeof(wkbuff),1,Pfh);     //8byte,rsv 4 byte//~vb31I~
    if (!len)                                                   //~v064I~
    	return 16;                                              //~v064I~
//ext data                                                         //~v47BI~
	memset(&wkextdata,0,sizeof(wkextdata));                        //~v47BR~
    wkextdata.struc.dist=Slinedist;                                //~v47BI~
    wkextdata.struc.bef=Slinebefore;                               //~v47BI~
    wkextdata.struc.aft=Slineafter;                                //~v47BI~
    wkextdata.struc.minsame=Sminsame;                              //~v62eI~
    if (Sescsrchlen2)                                              //~v741I~
    {                                                              //~v741I~
	    wkextdata.struc.extflag|=EXTFLAG_ESCSRCH2;//escsrchchar written//~v741R~
	    *wkextdata.struc.escsrch2=Sescsrchlen2;                    //~v741I~
//      memcpy(wkextdata.struc.escsrch2+1,Sescsrchchar2,sizeof(wkextdata.struc.escsrch2-1));//~va7bR~
        memcpy(wkextdata.struc.escsrch2+1,Sescsrchchar2,sizeof(wkextdata.struc.escsrch2)-1);//~va7bI~
    }                                                              //~v741I~
    else                                                           //~va7bI~
    if (Sothopt & SEARCH_DDSTR2)                                   //~va7bI~
    {                                                              //~va7bI~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_DDSTR2;            //~va7bI~
//      *wkextdata.struc.escsrch2=strlen(Sescsrchchar2);           //~vaz8R~
        *wkextdata.struc.escsrch2=(UCHAR)strlen(Sescsrchchar2);    //~vaz8I~
	    memcpy(wkextdata.struc.escsrch2+1,Sescsrchchar2,sizeof(wkextdata.struc.escsrch2)-1);//~va7bR~
    }                                                              //~va7bI~
#ifdef UTF8UCS2                                                    //~va20M~
    if (*Gsrchwordforini)	//by u8 or lc                          //~va20R~
    {                                                              //~va20I~
	    wkextdata.struc.extflag|=EXTFLAG_SRCHWORD;//serch word saved//~va20I~
        UstrncpyZ(wkextdata.struc.srchword,Gsrchwordforini,SAVE_SRCHWORDSZ);//~va20I~
    }                                                              //~va20I~
#else                                                              //~va20I~
    if (*Ssrchword)                                                //~v79VI~
    {                                                              //~v79VI~
	    wkextdata.struc.extflag|=EXTFLAG_SRCHWORD;//serch word saved//~v79VI~
        UstrncpyZ(wkextdata.struc.srchword,Ssrchword,SAVE_SRCHWORDSZ);//~v79VR~
    }                                                              //~v79VI~
#endif                                                             //~va20M~
	if (Sfindopt & FINDOPT_MULTIREV)                               //~v76UI~
	    wkextdata.struc.extflag|=EXTFLAG_MULTIREV;                 //~v76UI~
	if (Sfindopt & FINDOPT_GREP)                                   //~v78dI~
	    wkextdata.struc.extflag|=EXTFLAG_GREP;                     //~v78dI~
	if (Sfindopt & FINDOPT_GREPP)                                  //~v78eI~
	    wkextdata.struc.extflag|=EXTFLAG_GREPP;                    //~v78eI~
	if (Sfindopt & FINDOPT_GREPPTARGET)                            //~v79LI~
	    wkextdata.struc.extflag|=EXTFLAG_GREPPTARGET;              //~v79LI~
#ifdef UTF8SUPPH                                                   //~va0cI~
	if (Sothopt  & SEARCH_UCS)                                     //~va0cI~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UCS;               //~va0cI~
	if (Sothopt  & SEARCH_UCS2)                                    //~va0cI~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UCS2;              //~va0cI~
	if (Sothopt  & SEARCH_UCSBE)                                   //~va0cI~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UCSBE;             //~va0cI~
	if (Sothopt  & SEARCH_UCSBE2)                                  //~va0cI~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UCSBE2;            //~va0cI~
	if (Sothopt  & SEARCH_UTF8)                                    //~va0yI~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UTF8;              //~va0yI~
	if (Sothopt  & SEARCH_UTF82)                                   //~va0yI~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UTF82;             //~va0yI~
	if (Sothopt & SEARCH_UTF8ECH)                                  //~va1GR~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UTF8EC;            //~va1GI~
	if (Sothopt & SEARCH_UTF8ECH2)                                 //~va1GR~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UTF8EC2;           //~va1GI~
	if (Sothopt & SEARCH_UTF8ECHR)                                 //~va1GI~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UTF8ECR;           //~va1GI~
#endif                                                             //~va0cI~
#ifdef UTF8UCS2                                                    //~va20I~
	if (Sothopt & SEARCH_UCS2WORD)    //FWF cmd searchword         //~va20R~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UCS2WORD;          //~va20I~
#endif                                                             //~va20I~
	if (Sothopt & SEARCH_EBCWORD)    //FWF cmd searchword          //~va7sM~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_EBCWORD;           //~va7sM~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
	if (Sothopt & SEARCH_UCS4)                                     //~va3xI~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UCS4;              //~va3xI~
	if (Sothopt & SEARCH_UCS4SW)                                   //~vax1R~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UCS4SW;            //~vax1R~
	if (Sothopt & SEARCH_UCS4SW2)                                  //~vax1I~
	    wkextdata.struc.extflag|=EXTFLAG_SEARCH_UCS4SW2;           //~vax1I~
#endif                                                             //~va3xI~
//	len=fwrite(&wkextdata,sizeof(wkextdata),1,Pfh);     //8byte,rsv 4 byte//~v47BR~//~vb31R~
  	len=(UINT)fwrite(&wkextdata,sizeof(wkextdata),1,Pfh);     //8byte,rsv 4 byte//~vb31I~
    if (!len)                                                      //~v47BI~
    	return 16;                                                 //~v47BI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//	fcmd_savelcctforerrmsg(FCSCFEMO_CT2INI,0/*type:Ssrch*/,Ssrch,strlen(Ssrch),0/*out:update Ssrch*/,0/*ppcd*/,0/*lenlc*/);//~va50R~//~vb30R~
  	fcmd_savelcctforerrmsg(FCSCFEMO_CT2INI,0/*type:Ssrch*/,Ssrch,(int)strlen(Ssrch),0/*out:update Ssrch*/,0/*ppcd*/,0/*lenlc*/);//~vb30I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//	len=fwrite(Ssrch,MAXCOLUMN,1,Pfh);                          //~v064R~//~vb31R~
  	len=(UINT)fwrite(Ssrch,MAXCOLUMN,1,Pfh);                       //~vb31I~
    if (!len)                                                   //~v064I~
    	return 16;                                              //~v064I~
//	len=fwrite(Sescsrchchar,sizeof(Sescsrchchar),1,Pfh);           //~v0a9R~
	memset(wkbuff,0,sizeof(wkbuff));                               //~v0a9I~
    memcpy(wkbuff,Sescsrchchar,sizeof(Sescsrchchar));              //~v0a9I~
//	len=fwrite(wkbuff,sizeof(wkbuff),1,Pfh);                       //~v0a9I~//~vb31R~
  	len=(UINT)fwrite(wkbuff,sizeof(wkbuff),1,Pfh);                 //~vb31I~
    if (!len)                                                      //~v09OI~
    	return 16;                                                 //~v09OI~
//#ifdef UTF8EBCD   //raw ebcdic file support                      //~va50R~
//    fcmd_savelcctforerrmsg(FCSCFEMO_CT2INI,SEARCH_CHANGE,Srepword,strlen(Srepword),0/*out:update Ssrch*/,0/*ppcd*/,0/*lenlc*/);//~va50R~
//#endif //UTF8EBCD raw ebcdic file support                        //~va50R~
//	len=fwrite(Srepword,MAXCOLUMN,1,Pfh);                       //~v064R~//~vb31R~
  	len=(UINT)fwrite(Srepword,MAXCOLUMN,1,Pfh);                    //~vb31I~
    if (!len)                                                   //~v064I~
    	return 16;                                              //~v064I~
//	len=fwrite(Sescrepchar,sizeof(Sescrepchar),1,Pfh);             //~v0a9R~
	memset(wkbuff,0,sizeof(wkbuff));                               //~v0a9I~
    memcpy(wkbuff,Sescrepchar,sizeof(Sescrepchar));                //~v0a9I~
//	len=fwrite(wkbuff,sizeof(wkbuff),1,Pfh);                       //~v0a9I~//~vb31R~
  	len=(UINT)fwrite(wkbuff,sizeof(wkbuff),1,Pfh);                 //~vb31I~
    if (!len)                                                      //~v09OI~
    	return 16;                                                 //~v09OI~
//  if (Ssrchlen2)                                                 //~v54zR~
    if (Ssrchlen2||Seolsrchsw2)                                    //~v54zI~
    {                                                              //~v43wI~
    	*wkbuff=(UCHAR)Ssrchlen2;                                  //~v43wI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  	fcmd_savelcctforerrmsg(FCSCFEMO_CT2INI,SEARCH_AND,Ssrch2,strlen(Ssrch2),0/*out:update Ssrch*/,0/*ppcd*/,0/*lenlc*/);//~va50R~//~vb30R~
    	fcmd_savelcctforerrmsg(FCSCFEMO_CT2INI,SEARCH_AND,Ssrch2,(int)strlen(Ssrch2),0/*out:update Ssrch*/,0/*ppcd*/,0/*lenlc*/);//~vb30I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	memcpy(wkbuff+1,Ssrch2,MAXCOLUMN-1);                       //~v43wI~
//		len=fwrite(wkbuff,sizeof(wkbuff),1,Pfh);                   //~v43wI~//~vb31R~
  		len=(UINT)fwrite(wkbuff,sizeof(wkbuff),1,Pfh);             //~vb31I~
    	if (!len)                                                  //~v43wI~
    		return 16;                                             //~v43wI~
    }                                                              //~v43wI~
//  fileclose(fullpath,fh);                                     //~v064R~
	return 0;                                                   //~5504I~
}//fcmdwfparm                                                   //~5504I~
                                                                //~5504I~
//**************************************************            //~5504I~
//!read previous find parm                                      //~5504I~
//*parm :FILE*                                                  //~v064R~
//*ret  :rc                                                     //~5504I~
//**************************************************            //~5504I~
int fcmdrfparm(FILE *Pfh)                                       //~v064R~
{                                                               //~5504I~
//  UCHAR  wkbuff[8];                                              //~v09eR~
//  UCHAR  wkbuff[12];                                             //~v0a9R~
    UCHAR  wkbuff[MAXCOLUMN];                                      //~v0a9R~
    SAVE_EXTDATA wkextdata;                                        //~v47BI~
    int  len;                                                   //~5504R~
    int othersw=0;                                                   //~v09II~//~vafcR~
    int othersw2;                                                  //~v47BI~
//  FILE *fh;                                                   //~v064R~
//*********************************                             //~5504I~
//  if (filefind(Sfindpfile,fullpath,0,FFNONFMSG))//no need fstat3 output//~v064R~
//      return 4;                                               //~v064R~
//  if (!(fh=fileopen(fullpath,"rb")))                          //~v064R~
//      return 8;                                               //~v064R~
//  if (len=(int)fread(wkbuff,3,1,Pfh),len)//success               //~v09eR~
//  if (len=(int)fread(wkbuff,8,1,Pfh),len)//success               //~v0a9R~
    if (len=(int)fread(wkbuff,sizeof(wkbuff),1,Pfh),len)//success  //~v0a9I~
    {                                                           //~5504I~
        Ssubcmdid=(int)(*wkbuff & 0x0f);                        //~5504I~
        Scasesensesw=(int)(*(wkbuff+1) & 0x0f);                 //~5504I~
        Schangeopt=(int)(*(wkbuff+2) & 0x0f);                   //~5504I~
//      Sulsrchsw=(char)(*(wkbuff+3) & 0x01);                      //~v0bqR~
//      Sulsrchsw=(char)(*(wkbuff+3) & 0x03);   //1 or 2           //~v62dR~
        Sulsrchsw=(char)(*(wkbuff+3) & 0x0f);   //1 -5             //~v62dI~
        othersw=(int)(*(wkbuff+4));                                //~v09II~
        othersw2=(int)(*(wkbuff+5));                               //~v47BI~
        Sescsrchlen=(char)(*(wkbuff+6));                           //~v09OR~
        Sescreplen=(char)(*(wkbuff+7));                            //~v09OI~
        Stabsrchsw=(char)(othersw & OTHERSW_TABSRCH);              //~v09II~
        Stabsrchsw2=(char)(othersw2 & OTHERSW2_TABSRCH2);          //~va1HI~
        Stabrepsw=(char)(othersw & OTHERSW_TABREP);                //~v0apI~
        Srepnull=(char)((othersw & OTHERSW_REPNULL)!=0);           //~v09JI~
		Sexcludesw=(char)((othersw & OTHERSW_EXCLUDE)!=0);         //~v0hzI~
//  	Snxsw=(char)((othersw & OTHERSW_NXSRCH)!=0);               //~v73dR~
    	Gnxsw=(char)((othersw & OTHERSW_NXSRCH)!=0);               //~v73dI~
    	Snotsrchsw=(char)((othersw & OTHERSW_NOTSRCH)!=0);         //~v41rI~
        if (Snotsrchsw)                                            //~v43wI~
		  Sothopt|=SEARCH_NOT;                                     //~v43wI~
    	Snotsrchsw2=(char)((othersw & OTHERSW_NOTSRCH2)!=0);       //~v43wI~
        if (Snotsrchsw2)                                           //~v43wI~
		  Sothopt|=SEARCH_NOT2;                                    //~v43wI~
                                                                   //~v47BI~
		memcpy(&Srangeid1,wkbuff+8,sizeof(Srangeid1));             //~v0eDM~
		memcpy(&Srangeid2,wkbuff+8+sizeof(Srangeid1),sizeof(Srangeid2));//~v0eDM~
		memcpy(&Srangeid1and,wkbuff+8+sizeof(Srangeid1)+sizeof(Srangeid2),//~v532I~
					sizeof(Srangeid1and));                         //~v532I~
		memcpy(&Srangeid2and,wkbuff+8+sizeof(Srangeid1)+sizeof(Srangeid2)+sizeof(Srangeid1and),//~v532I~
					sizeof(Srangeid2and));                         //~v532I~
                                                                   //~v47BI~
//ext data                                                         //~v47BI~
        if (othersw2 & OTHERSW2_EXTENDED)                          //~v47BR~
        {                                                          //~v47BI~
    		Seolsrchsw=(char)((othersw2 & OTHERSW2_EOLSRCH)!=0);   //~v47BI~
    		Seolsrchsw2=(char)((othersw2 & OTHERSW2_EOLSRCH2)!=0); //~v47BI~
		  	if (len=(int)fread(&wkextdata,sizeof(wkextdata),1,Pfh),len)     //8byte,rsv 4 byte//~v47BR~
            {                                                      //~v47BI~
    			Slinedist=wkextdata.struc.dist;                    //~v47BI~
		    	Slinebefore=wkextdata.struc.bef;                   //~v47BI~
    			Slineafter=wkextdata.struc.aft;                    //~v47BI~
			    Sminsame=wkextdata.struc.minsame;                  //~v62eI~
			    if (wkextdata.struc.extflag & EXTFLAG_ESCSRCH2)    //~v741I~
			    {                                                  //~v741I~
        			Sescsrchlen2=*wkextdata.struc.escsrch2;        //~v741I~
//          		memcpy(Sescsrchchar2,wkextdata.struc.escsrch2+1,sizeof(wkextdata.struc.escsrch2-1));//~va7bR~
            		memcpy(Sescsrchchar2,wkextdata.struc.escsrch2+1,sizeof(wkextdata.struc.escsrch2)-1);//~va7bI~
			    }                                                  //~v741I~
                else                                               //~va7bI~
			    if (wkextdata.struc.extflag & EXTFLAG_SEARCH_DDSTR2)//~va7bI~
			    {                                                  //~va7bI~
//          		memcpy(Sescsrchchar2,wkextdata.struc.escsrch2+1,sizeof(wkextdata.struc.escsrch2-1));//~va7bR~
            		memcpy(Sescsrchchar2,wkextdata.struc.escsrch2+1,sizeof(wkextdata.struc.escsrch2)-1);//~va7bI~
                    Sothopt|=SEARCH_DDSTR2;                        //~va7bI~
			    }                                                  //~va7bI~
				if (wkextdata.struc.extflag & EXTFLAG_SRCHWORD)//serch word saved//~v79VI~
                {                                                  //~v79VI~
#ifdef UTF8UCS2                                                    //~va20I~
//      			UstrncpyZ(Gsrchwordforini,wkextdata.struc.srchword,sizeof(Ssrchword));//~va20R~//~va41R~
        			UstrncpyZ(Gsrchwordforini,wkextdata.struc.srchword,sizeof(Gsrchwordforini));//~va41I~
#endif                                                             //~va20M~
        			UstrncpyZ(Ssrchword,wkextdata.struc.srchword,sizeof(Ssrchword));//~v79VR~
        			Ssrchwordlen=(int)strlen(Ssrchword);           //~v79VI~
    			}                                                  //~v79VI~
			    if (wkextdata.struc.extflag & EXTFLAG_MULTIREV)    //~v76UI~
					Sfindopt|=FINDOPT_MULTIREV;                    //~v76UR~
			    if (wkextdata.struc.extflag & EXTFLAG_GREP)        //~v78dI~
					Sfindopt|=FINDOPT_GREP;                        //~v78dI~
			    if (wkextdata.struc.extflag & EXTFLAG_GREPP)       //~v78eI~
					Sfindopt|=FINDOPT_GREPP;                       //~v78eI~
			    if (wkextdata.struc.extflag & EXTFLAG_GREPPTARGET) //~v79LI~
					Sfindopt|=FINDOPT_GREPPTARGET;                 //~v79LI~
#ifdef UTF8SUPPH                                                   //~va0cI~
			    if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UCS)  //~va0cI~
					Sothopt|=SEARCH_UCS;                           //~va0cI~
			    if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UCS2) //~va0cI~
					Sothopt|=SEARCH_UCS2;                          //~va0cI~
			    if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UCSBE)//~va0cI~
					Sothopt|=SEARCH_UCSBE;                         //~va0cI~
			    if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UCSBE2)//~va0cI~
					Sothopt|=SEARCH_UCSBE2;                        //~va0cI~
			    if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UTF8) //~va0yI~
					Sothopt|=SEARCH_UTF8;                          //~va0yI~
			    if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UTF82)//~va0yI~
					Sothopt|=SEARCH_UTF82;                         //~va0yI~
			    if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UTF8EC)//~va1GI~
					Sothopt|=SEARCH_UTF8ECH;                       //~va1GR~
			    if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UTF8EC2)//~va1GI~
					Sothopt|=SEARCH_UTF8ECH2;                      //~va1GR~
			    if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UTF8ECR)//~va1GI~
					Sothopt|=SEARCH_UTF8ECHR;                      //~va1GI~
#endif                                                             //~va0cI~
#ifdef UTF8UCS2                                                    //~va20I~
				if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UCS2WORD)//~va20I~
					Sothopt|=SEARCH_UCS2WORD;                      //~va20I~
#endif                                                             //~va20I~
				if (wkextdata.struc.extflag & EXTFLAG_SEARCH_EBCWORD)//~va7sM~
					Sothopt|=SEARCH_EBCWORD;                       //~va7sM~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
				if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UCS4) //~va3xI~
					Sothopt|=SEARCH_UCS4;                          //~va3xI~
				if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UCS4SW)//~vax1R~
					Sothopt|=SEARCH_UCS4SW;                        //~vax1R~
				if (wkextdata.struc.extflag & EXTFLAG_SEARCH_UCS4SW2)//~vax1I~
					Sothopt|=SEARCH_UCS4SW2;                       //~vax1I~
#endif                                                             //~va3xI~
        	}                                                      //~v47BI~
        }                                                          //~v47BI~
                                                                   //~v47BI~
		if (len=(int)fread(Ssrch,MAXCOLUMN,1,Pfh),len)          //~v064R~
        {                                                          //~va50I~
//  	  	if (len=(int)fread(Sescsrchchar,sizeof(Sescsrchchar),1,Pfh),len)//~v0a9R~
    	  	if (len=(int)fread(wkbuff,sizeof(wkbuff),1,Pfh),len)   //~v0a9I~
	        {                                                      //~v0a9I~
				memcpy(Sescsrchchar,wkbuff,sizeof(Sescsrchchar));  //~v0a9I~
				if (len=(int)fread(Srepword,MAXCOLUMN,1,Pfh),len)  //~v09OR~
//  	  			len=(int)fread(Sescrepchar,sizeof(Sescrepchar),1,Pfh);//~v0a9R~
    	  			if (len=(int)fread(wkbuff,sizeof(wkbuff),1,Pfh),len)//~v0a9I~
	    	  			memcpy(Sescrepchar,wkbuff,sizeof(Sescrepchar));//~v0a9I~
	        }                                                      //~v0a9I~
        }                                                          //~va50I~
    }                                                           //~5504R~
    if (!len)                                                   //~v064R~
//  	if (ferror(Pfh))                                        //~v064R~
//  		uerrexit("%s-I/O(fgets) error",                     //~v064R~
//  				 "%s-で I/O(fgets) エラー",                 //~v064R~
//  					 fullpath);                             //~v064R~
        return 16;                                              //~v064I~
  if (Sescsrchlen)                                                 //~v09OR~
    Ssrchlen=Sescsrchlen;                                          //~v09OR~
  else  	                                                       //~v09II~
  {                                                                //~va20I~
    Ssrchlen=(int)strlen(Ssrch);                                //~5504R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	fcmd_savelcctforerrmsg(FCSCFEMO_INI2CT,0/*srch1*/,Ssrch,Ssrchlen,0/*out:update Ssrch*/,0/*ppcd*/,0/*lenlc*/);//~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
  }                                                                //~va20I~
  if (Sescreplen)                                                  //~v09OR~
    Srepwordlen=Sescreplen;                                        //~v09OR~
  else                                                             //~v09II~
  {                                                                //~v79LI~
    Srepwordlen=(int)strlen(Srepword);                          //~5504R~
    if (Sfindopt & FINDOPT_GREPPTARGET)   //change target is P'..' pattern//~v79LI~
        Srepwordlen-=3;    //net len enclosed                      //~v79LI~
//#ifdef UTF8EBCD   //raw ebcdic file support                      //~va50R~
//    fcmd_savelcctforerrmsg(FCSCFEMO_INI2CT,SEARCH_CHANGE,Srepword,Srepwordlen,0/*out:update Ssrch*/,0/*ppcd*/,0/*lenlc*/);//~va50R~
//#endif //UTF8EBCD raw ebcdic file support                        //~va50R~
  }                                                                //~v79LI~
    if (othersw & OTHERSW_ANDSRCH)                                 //~v43wI~
    {                                                              //~v43wI~
    	if (len=(int)fread(wkbuff,sizeof(wkbuff),1,Pfh),len)//success//~v43wI~
        {                                                          //~v43wI~
        	Ssrchlen2=*wkbuff;                                     //~v43wI~
        	memcpy(Ssrch2,wkbuff+1,MAXCOLUMN-1);                   //~v43wI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
			fcmd_savelcctforerrmsg(FCSCFEMO_INI2CT,SEARCH_AND,Ssrch2,Ssrchlen2,0/*out:update Ssrch*/,0/*ppcd*/,0/*lenlc*/);//~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        }                                                          //~v43wI~
    }                                                              //~v43wI~
#ifdef UTF8UCS2                                                    //~va20I~
  	if (!Sescsrchlen && !(Sothopt & SEARCH_USEESCSTR))             //~va20R~
    {                                                              //~va20I~
//  	len=strlen(Sescsrchchar);    //utf8 str was set if not escsearch(escsrchlen=0)//~va20I~//~vb30R~
    	len=(int)strlen(Sescsrchchar);    //utf8 str was set if not escsearch(escsrchlen=0)//~vb30I~
        if (len)                                                   //~va20I~
//			fcmdsetupddsrch(0,Sescsrchchar,len);  //setup Gsrchdd  //~va20I~//~va79R~
  			fcmdsetupddsrch(0,-1/*handle*/,Sescsrchchar,len);  //setup Gsrchdd//~va79R~
    }                                                              //~va20I~
  	if (!Sescsrchlen2 && !(Sothopt & SEARCH_USEESCSTR2))           //~va20R~
    {                                                              //~va20I~
//  	len=strlen(Sescsrchchar2);    //utf8 str was set if not escsearch(escsrchlen=0)//~va20I~//~vb30R~
    	len=(int)strlen(Sescsrchchar2);    //utf8 str was set if not escsearch(escsrchlen=0)//~vb30I~
        if (len)                                                   //~va20I~
//  		fcmdsetupddsrch(SEARCH_AND,Sescsrchchar2,len);  //setup Gsrchdd//~va20I~//~va79R~
    		fcmdsetupddsrch(SEARCH_AND,-1/*handle*/,Sescsrchchar2,len);  //setup Gsrchdd//~va79R~
    }                                                              //~va20I~
    else                                                           //~va7bI~
  	if (!Sescsrchlen2 && (Sothopt & SEARCH_DDSTR2))                //~va7bI~
    {                                                              //~va7bI~
//  	len=strlen(Sescsrchchar2);    //utf8 str was set if not escsearch(escsrchlen=0)//~va7bI~//~vb30R~
    	len=(int)strlen(Sescsrchchar2);    //utf8 str was set if not escsearch(escsrchlen=0)//~vb30I~
        if (len)                                                   //~va7bI~
    		fcmdsetupddsrch(SEARCH_AND,-1/*handle*/,Sescsrchchar2,len);  //setup Gsrchdd//~va7bI~//~va79R~
    }                                                              //~va7bI~
  	if (!Sescreplen)                                               //~va20R~
    {                                                              //~va20I~
//  	len=strlen(Sescrepchar);    //utf8 str was set if not escsearch(escsrchlen=0)//~va20I~//~vb30R~
    	len=(int)strlen(Sescrepchar);    //utf8 str was set if not escsearch(escsrchlen=0)//~vb30I~
        if (len)                                                   //~va20I~
//  		fcmdsetupddsrch(SEARCH_CHANGE,Sescrepchar,len);  //setup Gsrchdd//~va20R~//~va79R~
    		fcmdsetupddsrch(SEARCH_CHANGE,-1/*handle*/,Sescrepchar,len);  //setup Gsrchdd//~va79R~
    }                                                              //~va20I~
#endif                                                             //~va20I~
//  fileclose(fullpath,fh);                                     //~v064R~
    return 0;                                                   //~5504I~
}//fcmdrfparm                                                   //~5504I~
//**************************************************               //~v09LI~
//!searchby esc char(sbcs or dbcs)                                 //~v09LR~
//*parm1:string                                                    //~v09LR~
//*parm2:direction                                                 //~v09LI~
//*ret  :found pos,0 if not found                                  //~v09LI~
//**************************************************               //~v09LI~
char *fcmdescsrch(char *Ppc,int Pdirection,int Poffset)            //~v09LR~
{                                                                  //~v09LI~
    char *pc;                                                      //~v0apR~
//    char *pce;                                                   //~v0apI~
//    int offset;                                                  //~v0apR~
//*********************************                                //~v09LI~
	if (Pdirection==SUBCMD_PREV)                                   //~v09LI~
    {                                                              //~v09LI~
        if (Sescsrchlen>1)                                         //~v09OR~
//      {                                                          //~v0apR~
//          for (offset=Poffset;;)                                 //~v0apR~
//          {                                                      //~v0apR~
//        		if (!(pc=umemrchr(Ppc,Sescsrchchar[1],(UINT)offset)))//~v0apR~
//              	break;                                         //~v0apR~
//          	if (pc==Ppc)                                       //~v0apR~
//              {                                                  //~v0apR~
//              	pc=0;                                          //~v0apR~
//                  break;                                         //~v0apR~
//  			}                                                  //~v0apR~
//  			if (*(--pc)==Sescsrchchar[0])                      //~v0apR~
//              	break;				//match                    //~v0apR~
//              offset=(int)((ULONG)pc-(ULONG)Ppc)+1;              //~v0apR~
//  		}                                                      //~v0apR~
//  	}                                                          //~v0apR~
//*fcmdescsrch is for non utf8 file                                //~va20I~
            pc=umemrmem(Ppc,Sescsrchchar,(UINT)Poffset,Sescsrchlen);//~v0apI~
        else                                                       //~v09LI~
	      	pc=umemrchr(Ppc,Sescsrchchar[0],(UINT)Poffset);        //~v09NR~
	}                                                              //~v09LI~
    else 	//forward search                                       //~v09LI~
	{                                                              //~v09LI~
//  	pce=Ppc+Poffset;		//end addr                         //~v0apR~
//  	for (pc=Ppc,offset=Poffset;pc;)                            //~v0apR~
//      {                                                          //~v0apR~
//  		if (!(pc=memchr(pc,Sescsrchchar[0],(UINT)offset)))     //~v0apR~
//          	break;                                             //~v0apR~
//      	if (Sescsrchlen==1)                                    //~v0apR~
//          	break;                                             //~v0apR~
//          if (++pc==pce)                                         //~v0apR~
//          {                                                      //~v0apR~
//          	pc=0;                                              //~v0apR~
//              break;                                             //~v0apR~
//  		}                                                      //~v0apR~
//  	    if (*pc==Sescsrchchar[1])                              //~v0apR~
//          {                                                      //~v0apR~
//              pc--;                                              //~v0apR~
//              break;                                             //~v0apR~
//          }                                                      //~v0apR~
//      	offset=(int)((ULONG)pce-(ULONG)pc);	//not found        //~v0apR~
//  	}                                                          //~v0apR~
//*fcmdescsrch is for non utf8 file                                //~va20I~
        if (Sescsrchlen>1)                                         //~v0apI~
            pc=umemmem(Ppc,Sescsrchchar,(UINT)Poffset,Sescsrchlen);//~v0apI~
        else                                                       //~v0apI~
 			pc=memchr(Ppc,Sescsrchchar[0],(UINT)Poffset);          //~v0b4R~
	}	                                                           //~v09LR~
    return pc;                                                     //~v09LR~
}//fcmdescsrch                                                     //~v09LR~
                                                                   //~v09LI~
//**************************************************               //~v0hxR~
//!not found err msg                                               //~v0hxR~
//*parm1:1st search id(0 if 2nd of all search)                     //~v0hxR~
//*parm2:direction                                                 //~v0hxR~
//*ret  :4                                                         //~v0hxR~
//**************************************************               //~v0hxR~
int fcmdsrcherr(int Pchangeopt,int Plocatesw,int Psubcmdid,PULINEH Pplh)//~v0hxR~
{                                                                  //~v0hxR~
//  char *caseid;                                                  //~v10oR~
    char  caseid[4];                                               //~v10oI~
    char *srch;                                                    //~v0ilI~
    char *eolsrch,*eolsrch2;                                       //~v47BI~
    char notsrch[4];                                               //~v41rI~
    char notsrch2[4];                                              //~v43wI~
    char srchdata[MAXCOLUMN*2+32];                                 //~v43iI~
    int  bineolsw=0,bineolsw2=0;                                   //~v47BR~
#ifdef UTF8SUPPH                                                   //~va0cI~
	char *pucsopt,*pucsopt2,*srch2;                                //~va0cR~
    int srchlen;                                                   //~va0cI~
    char srchdata1[MAXCOLUMN];                                     //~va0cI~
    char srchdata2[MAXCOLUMN];                                     //~va0cI~
#endif                                                             //~va0cI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~
    char srchct1[MAXCOLUMN];                                       //~va50R~
    UCHAR *psrchct;                                                //~va50I~
    char srchct2[MAXCOLUMN];                                       //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50R~
//*********************************                                //~v0hxR~
//    UTRACEP("find err:Pchangeopt=%d,Plocatesw=%d,Psubcmdid=%d,Sulsrchsw=%d,Sexcludesw=%d,Sexcludesw2=%d\n",//~v11sR~
//            Pchangeopt,Plocatesw,Psubcmdid,Sulsrchsw,Sexcludesw,Sexcludesw2);//~v11sR~
//    UTRACEP("Swrapsw=%d,Stabsrchsw=%d,Slinerangesw=%d,Srange1=%d,Srange2=%d,Srangeplhe=%08x,Srangeid1=%d,Srangeid2=%d\n",//~v11sR~
//             Swrapsw,Stabsrchsw,Slinerangesw,Srange1,Srange2,Srangeplhe,Srangeid1,Srangeid2);//~v11sR~
//    UTRACEP("Scasesensesw=%d,Ssrch=%s,Ssrchlen=%d,Sstep=%d,Sescsrchlen=%d,Stabsrchsw=%d,Snxsw=%d\n",//~v11sR~
//             Scasesensesw,Ssrch,Ssrchlen,Sstep,Sescsrchlen,Stabsrchsw,Snxsw);//~v11sR~
    if (Sphasesw)    //msg after Ssrch is restored                 //~v49eI~
    {                                                              //~v49eM~
        Ssrcherrplh=Pplh;                                          //~v49eM~
        return 4;                                                  //~v49eM~
    }                                                              //~v49eM~
//  if (Snotsrchsw)                                                //~v43wR~
	if (Sothopt & SEARCH_NOT)                                      //~v43wI~
    {                                                              //~v41rI~
    	sprintf(notsrch,"%s ",STR_SEARCH_NOT);                     //~v41rI~
    }                                                              //~v41rI~
    else                                                           //~v41rI~
    	*notsrch=0;                                                //~v41rI~
	if (Sothopt & SEARCH_NOT2)                                     //~v43wI~
    {                                                              //~v43wI~
    	sprintf(notsrch2,"%s ",STR_SEARCH_NOT);                    //~v43wI~
    }                                                              //~v43wI~
    else                                                           //~v43wI~
    	*notsrch2=0;                                               //~v43wI~
	if (Sulsrchsw==1)                                              //~v0ilI~
    	srch=Sulsrchid;                                            //~v0ilI~
    else                                                           //~v0ilI~
	if (Sulsrchsw==LINE_SAMEMATCH)                                 //~v62dI~
    	srch=Smatchingid;                                          //~v62fR~
    else                                                           //~v62dI~
	if (Sulsrchsw==LINE_SAMESRCH)                                  //~v49bI~
    	srch=Seqsrchid;                                            //~v49bI~
    else                                                           //~v49bI~
	if (Sulsrchsw==LINE_RESEARCH)                                  //~v496I~
    	srch=Sllsrchid;                                            //~v496I~
    else                                                           //~v496I~
	if (Sulsrchsw==LINE_GREPSEARCH)                                //~v632I~
    	srch=Sgrepsrchid;                                          //~v632I~
    else                                                           //~v632I~
	if (Sulsrchsw)                                                 //~v0ilI~
    	srch=Selsrchid;                                            //~v0ilI~
    else                                                           //~v0ilI~
    	srch=Ssrch;                                                //~v0ilI~
//  if (Seolsrchsw)                                                //~v54ZR~
    if (Seolsrchsw==1)	//by appended \n                           //~v54ZI~
    	eolsrch=EOLSRCHID;                                         //~v47BI~
    else                                                           //~v47BI~
    	if (*(Ssrch+Ssrchlen-1)=='\n')                             //~v47BR~
        {                                                          //~v47BI~
        	bineolsw=1;                                            //~v47BI~
	    	eolsrch=EOLSRCHID;                                     //~v47BI~
            *(Ssrch+Ssrchlen-1)=0;                                 //~v47BI~
        }                                                          //~v47BI~
        else                                                       //~v47BI~
    		eolsrch="";                                            //~v47BI~
    if (Seolsrchsw2)                                               //~v47BI~
    	eolsrch2=EOLSRCHID;                                        //~v47BI~
    else                                                           //~v47BI~
    	if (*(Ssrch2+Ssrchlen2-1)=='\n')                           //~v47BR~
        {                                                          //~v47BI~
        	bineolsw2=1;                                           //~v47BI~
	    	eolsrch2=EOLSRCHID;                                    //~v47BI~
            *(Ssrch2+Ssrchlen2-1)=0;                               //~v47BI~
        }                                                          //~v47BI~
        else                                                       //~v47BI~
    		eolsrch2="";                                           //~v47BR~
#ifdef UTF8SUPPH                                                   //~va0cI~
	if (Sothopt & SEARCH_UCS)                                      //~va0cI~
    {                                                              //~va0cI~
		if (Sothopt & SEARCH_UTF8)                                 //~va0yI~
			pucsopt=" " STR_SEARCH_UTF8;                           //~va0yI~
        else                                                       //~va0yI~
		if (Sothopt & SEARCH_UCS4SW)                               //~vax1R~
        {                                                          //~vax1R~
			if (Sothopt & SEARCH_UCSBE)                            //~vax1R~
				pucsopt=" " STR_SEARCH_UCSBE " " STR_SEARCH_UCS4;  //~vax1R~
        	else                                                   //~vax1R~
				pucsopt=" " STR_SEARCH_UCSLE " " STR_SEARCH_UCS4;  //~vax1R~
        }                                                          //~vax1R~
        else                                                       //~vax1R~
		if (Sothopt & SEARCH_UCSBE)                                //~va0cI~
			pucsopt=" " STR_SEARCH_UCSBE;                          //~va0cR~
        else                                                       //~va0cI~
			pucsopt=" " STR_SEARCH_UCSLE;                          //~va0cR~
    	if (Seolsrchsw!=1)	//chk appended \n                      //~va0cI~
        {                                                          //~va0cI~
        	srchlen=(int)strlen(srch);                             //~va0cI~
            if (*(srch+srchlen-1)=='\n')                           //~va0cI~
            {                                                      //~va0cI~
                eolsrch=EOLSRCHID;                                 //~va0cI~
//              UmemcpyZ(srchdata1,srch,srchlen-1);                //~va0cR~//~vb30R~
                UmemcpyZ(srchdata1,srch,(size_t)srchlen-1);        //~vb30I~
                srch=srchdata1;                                    //~va0cI~
            }                                                      //~va0cI~
        }                                                          //~va0cI~
    }                                                              //~va0cI~
    else                                                           //~va0cI~
		pucsopt="";                                                //~va0cI~
    srch2=Ssrch2;                                                  //~va0cI~
	if (Sothopt & SEARCH_UCS2)                                     //~va0cI~
    {                                                              //~va0cI~
		if (Sothopt & SEARCH_UTF82)                                //~va0yI~
//  		pucsopt=" " STR_SEARCH_UTF8;                           //~va0yI~//~vafdR~
    		pucsopt2=" " STR_SEARCH_UTF8;                          //~vafdR~
        else                                                       //~va0yI~
		if (Sothopt & SEARCH_UCS4SW2)                              //~vax1R~
        {                                                          //~vax1R~
            if (Sothopt & SEARCH_UCSBE2)                           //~vax1R~
                pucsopt2=" " STR_SEARCH_UCSBE " " STR_SEARCH_UCS4; //~vax1R~
            else                                                   //~vax1R~
                pucsopt2=" " STR_SEARCH_UCSLE " " STR_SEARCH_UCS4; //~vax1R~
        }                                                          //~vax1R~
        else                                                       //~vax1R~
		if (Sothopt & SEARCH_UCSBE2)                               //~va0cI~
			pucsopt2=" " STR_SEARCH_UCSBE;                         //~va0cR~
        else                                                       //~va0cI~
			pucsopt2=" " STR_SEARCH_UCSLE;                         //~va0cR~
    	if (!Seolsrchsw2)	//chk appended \n                      //~va0cI~
        {                                                          //~va0cI~
        	srchlen=(int)strlen(srch2);                            //~va0cI~
            if (*(srch2+srchlen-1)=='\n')                          //~va0cI~
            {                                                      //~va0cI~
                eolsrch2=EOLSRCHID;                                //~va0cI~
//              UmemcpyZ(srchdata2,srch2,srchlen-1);               //~va0cR~//~vb30R~
                UmemcpyZ(srchdata2,srch2,(size_t)srchlen-1);       //~vb30I~
                srch2=srchdata2;                                   //~va0cI~
            }                                                      //~va0cI~
        }                                                          //~va0cI~
    }                                                              //~va0cI~
    else                                                           //~va0cI~
		pucsopt2="";                                               //~va0cR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  if (psrchct=srchct1,!fcmd_savelcctforerrmsg(FCSCFEMO_SETCTPREFIX,0/*1st word*/,srch,strlen(srch),&psrchct,0/*ppdbcs*/,0/*lclen*/))//~va50R~//~vb30R~
    if (psrchct=srchct1,!fcmd_savelcctforerrmsg(FCSCFEMO_SETCTPREFIX,0/*1st word*/,srch,(int)strlen(srch),&psrchct,0/*ppdbcs*/,0/*lclen*/))//~vb30I~
        srch=psrchct;                                              //~va50R~
    if (Ssrchlen2||Seolsrchsw2)     //*& serch                     //~va50R~
    {                                                              //~va50I~
//      if (psrchct=srchct2,!fcmd_savelcctforerrmsg(FCSCFEMO_SETCTPREFIX,SEARCH_AND,srch2,strlen(srch2),&psrchct,0/*ppdbcs*/,0/*lclen*/))//~va50R~//~vb30R~
        if (psrchct=srchct2,!fcmd_savelcctforerrmsg(FCSCFEMO_SETCTPREFIX,SEARCH_AND,srch2,(int)strlen(srch2),&psrchct,0/*ppdbcs*/,0/*lclen*/))//~vb30I~
            srch2=psrchct;                                         //~va50R~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (Ssrchlen2||Seolsrchsw2)     //*& serch                     //~va0cI~
    	sprintf(srchdata,"%s%s%s%s %s %s%s%s%s",notsrch,srch,eolsrch,pucsopt,STR_SEARCH_AND,notsrch2,srch2,eolsrch2,pucsopt2);//~va0cR~
    else                                                           //~va0cI~
    	sprintf(srchdata,"%s%s%s%s",notsrch,srch,eolsrch,pucsopt); //~va0cI~
#else                                                              //~va0cR~
//  if (Ssrchlen2)      //*& serch                                 //~v54zR~
    if (Ssrchlen2||Seolsrchsw2)     //*& serch                     //~v54zI~
    	sprintf(srchdata,"%s%s%s %s %s%s%s",notsrch,srch,eolsrch,STR_SEARCH_AND,notsrch2,Ssrch2,eolsrch2);//~v47BR~
    else                                                           //~v43iM~
    	sprintf(srchdata,"%s%s%s",notsrch,srch,eolsrch);           //~v47BR~
#endif                                                             //~va0cI~
    if (bineolsw)                                                  //~v47BI~
    	*(Ssrch+Ssrchlen-1)='\n';                                  //~v47BI~
    if (bineolsw2)                                                 //~v47BI~
    	*(Ssrch2+Ssrchlen2-1)='\n';                                //~v47BI~
                                                                   //~v0ilI~
    if (Plocatesw)  //not 2nd of all                               //~v0hxR~
        Snotfinpctr=Gkbdinpctr; //save kbd input ctr to chk continuous ope//~v0hxR~
    if (Pchangeopt)                                                //~v0hxR~
//      caseid="C";                                                //~v10oR~
        caseid[0]='C';                                             //~v10oI~
    else                                                           //~v0hxR~
        if (Scasesensesw)                                          //~v0hxR~
//          caseid="F";                                            //~v10oR~
  			caseid[0]='F';                                         //~v10oI~
        else                                                       //~v0hxR~
//          caseid="I";                                            //~v10oR~
  			caseid[0]='I';                                         //~v10oI~
//  if (Snxsw)                                                     //~v73dR~
    if (Gnxsw)                                                     //~v73dI~
    {                                                              //~v10oI~
  		caseid[1]='N';                                             //~v10oI~
  		caseid[2]='X';                                             //~v10oI~
  		caseid[3]=0;                                               //~v10oI~
    }                                                              //~v10oI~
    else                                                           //~v10oI~
  		caseid[1]=0;                                               //~v10oI~
    if (Swrapsw)    //wrap search                                  //~v0hxR~
        uerrmsg("%s:None in this file(%s)",                        //~v43iR~
                "%s:一つも見つかりません(%s)",                     //~v43iR~
                caseid,srchdata);                                  //~v43iR~
    else                                                           //~v0hxR~
     	if (Slinerangesw)          //initialy outofrange           //~v0hxR~
        	uerrmsg("%s:Cursor position is out of label range(%s)",//~v43iR~
            	    "%s:行範囲指定の範囲外です(%s)",               //~v43iR~
                caseid,srchdata);                                  //~v43iI~
     else                                                          //~v0hxR~
      	if (Srangeplhe && Pplh==Srangeplhe)                        //~v0hxR~
        	uerrmsg("%s:Reached to End of Specified line range(%s)",//~v43iR~
            	    "%s:行範囲指定の限界に達しました(%s)",         //~v43iR~
                caseid,srchdata);                                  //~v43iI~
        else                                                       //~v43eI~
//    	if (Srangeplhe2 && Pplh==Srangeplhe2)                      //~v49eR~
//      	Srangeerr2=1;                                          //~v49eR~
//    	else                                                       //~v49eR~
      	if (!(Srangeplhe2 && Pplh==Srangeplhe2))                   //~v49eI~
        {                                                          //~v54aI~
        	if (Psubcmdid==SUBCMD_PREV)                            //~v0hxR~
            	uerrmsg("%s:Reached to Top of file(%s)",           //~v43iR~
                      	"%s:ファイルの先頭に達しました(%s)",       //~v43iR~
                caseid,srchdata);                                  //~v43iI~
            else                                                   //~v0hxR~
        		uerrmsg("%s:Reached to End of file(%s)",           //~v43iR~
            	    	"%s:ファイルの終りに達しました(%s)",       //~v43iR~
                caseid,srchdata);                                  //~v43iI~
        }//plh2                                                    //~v54aI~
    return 4;                                                      //~v0hxR~
}//fcmdsrcherr                                                     //~v0hxR~
//**************************************************               //~v614I~
//!other err disply my uerrmsgcat                                  //~v614I~
//*parm1:1st search id(0 if 2nd of all search)                     //~v614I~
//*parm2:direction                                                 //~v614I~
//*ret  :4                                                         //~v614I~
//**************************************************               //~v614I~
int fcmdothererrmsgcat(int Psubcmdid)                              //~v614I~
{                                                                  //~v614I~
    int rc=0;                                                      //~v614I~
//**********************                                           //~v614I~
    if (Sothererr_abrange)  //not notfound err count:ab range err  //~v614I~
    {                                                              //~v614I~
        uerrmsgcat(" ; found %d range err by -a and -b parm",0,    //~v61bR~
                            Sothererr_abrange); //not notfound err count:ab range err//~v614M~
        rc=4;                                                      //~v614I~
    }                                                              //~v614I~
    if (Sothererr_selfjoin)   //not notfound err count:join myself case//~v614I~
    {                                                              //~v614I~
        uerrmsgcat(" ; %d join skipped because join to itself",0,  //~v61bR~
                            Sothererr_selfjoin);   //not notfound err count:join myself case//~v614M~
        rc=4;                                                      //~v614I~
    }                                                              //~v614I~
	return rc;                                                     //~v614I~
}//fcmdothererrmsgcat                                              //~v614I~
