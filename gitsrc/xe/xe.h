//*CID://+vb5bR~:                             update#=  133;       //~vb5bR~
//*********************************************************************
//* common routine hdr                                             //~v07uR~
//*********************************************************************
//vb5b:160913 additional to vb54, DBCS space altch is changable by TAB cmd//~vb5bI~
//vb54:160903 TAB cmd new option to set altch; TAB {on|off} [altch1 [altch2]]//~vb54I~
//vb2V:160404 (Bug of vb2M) trace filename was changed by vb2M     //~vb2VI~
//vb2M:160319 (Wxe) pgmname of output of "wxe /?" whould not be xe but wxe.//~vb2MI~
//vb2n:160201 (W32)use FN{LC|U8} option translate input filename u8<-->lc regardless A+u kbd mode(like as (LNX)b2j)//~vb2nI~
//vb2j:160129 use FN{LC|U8} option translate input filename u8<-->lc regardless A+u kbd mode//~vb2jI~
//vaze:150112 expand MAXLINEDATA 9999 to 32760                     //~vazeI~
//vazd:150111 confirm large file open                              //~vazdI~
//vaw3:140526 (Win:UNICODE)hex kbd for 3byte unicode               //~vaw3I~
//vauE:140316 (Win)use ddfmt for dirlist;On cmd-prompt with setcp=65001,f2l dosenot change length but Windows display line shrinked//~vauEI~
//            use ddfmt to set USDfdata                            //~vauEI~
//vau0:140223 (LNX:BUG)utf8 filename on dirlist,filename locale:de is invalid if f2l on locale=ja_jp//~vau0I~
//            use ddfmt to set USDfdata                            //~vau0I~
//van9:131202 Issue warning to recover RCTL enter off-->on(if on "opt rctl ON" could not be enter)//~van9I~
//van2:131127 support deletion of invalid(wildcard) name entry on dir list//~va73I~
//va73:100805 (BUG:WXE)/n9 option ignored te on LP64               //~va73I~
//va47:100401 va46 for LNX                                         //~va47I~
//va46:100331 not use ctrl char for tab and tab padding,but use xff as default//~va46I~
//va44:100329 to print 0x14 glyph(q:0xb6),use another altchar(0xff)//~va44I~
//va3K:100316 allow unicode hex input on cmdline                   //~va3KI~
//va3H:100313 hexinput mode prefix for ucs,v:ucs4,default wait 2 byte//~va3HI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va1r:091108_(UTF8)cmd string get/set by all of lc, u8 and ct to avoid miss interpretation//~va1rI~
//va04:090606 expand cmdbuff to include edit cmd for the file with _max_path//~va04I~
//va03:090605 (BUG)"S" lcmd abend for long path filename(MAXCOLUMN is shorter than _MAX_PATH)//~va03I~
//v7ac:081108 Japanese bit is to be reset by -C option             //~v7acI~
//v7a5:081027 (BUG)dbcs evaluation required when /N8 option specified//~v79UI~
//v79U:081028 CID append mode                                      //~v79UI~
//v79M:081020 avoid that file spec start by '/' is treated as flag parm on cygwin//~v79MI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v792:080714 (BUG) rctl option is lost in 2nd session             //~v792I~
//v790:080709 RCTLNL cmd line parameter /yn                        //~v790I~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v768:070613 new RCTL option(Enter->Execute,Rctl->NewLine)        //~v768I~
//v74y:070223 new option to set COLS ON as default                 //~v74yI~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v71v:061022 not fixed(PAGE) scroll type for =0.1/2/3             //~v71vI~
//v716:060926 3270:"listds" cmd to chk file exist/dsorg            //~v716I~
//v69M:060713 (LNX)Change line drawing char effectiveness to optional. OPT LINECH [on|off]//~v69MI~
//            defaut is off because no code in iso8859 but in old IBM-PC Extended Char Set(ECS) only//~v69MI~
//v69F:060710 (LNX:BUG)box drawing not avail(use acs)              //~v69FI~
//v675:051226 (BUG of v66j)abend by dup enq CB pcw when split scr,"e ::cb" at 2nd , paste in 1st,"e ::cb" at 1st;//~v675I~
//v670:051224 cmd histry retrieve for each screen(A+F12) (maxstack 20-->40)//~v670I~
//v645:050617 OPT DELZ ON/OFF;option to prohibit dlcmd z/0;default is on//~v645R~
//v641:050614 (LNX)xxe support                                     //~v641I~
//v62b:050312 for -m[n] option of find cmd;assign mfwtbl for each pfh to avoid copy and copyback each time//~v62bI~
//v610:050207 change other pcw mode specification "*2"-->"!*"      //~v610I~
//v60y:050202 exe cmd *2 option(use other split screen file)       //~v60yM~
//v60k:050129 (BUG)GOPT4XLINENO is not recovered even if changed by "S" option//~v60kI~
//v584:040823 cap option not to copy to ::cb when cap-delete for performance up for large file//~v584I~
//v563:040325 (WIN)reject sleep and at cmd in exe cmd file         //~v563I~
//v55q:040228 option to scroll by csr move                         //~v55qI~
//v55j:040215 (LNX)use ctl+char as alternative of Shift+xx         //~v55jI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//v54S:040125 add opt cmd:beep on/off                              //~v54SI~
//v53U:031109 (WIN,UNX)ftp support                                 //~v53UI~
//v51D:030719 (LNX)RedHat9 <0x20 is not displayed normaly          //~v51DI~
//v51A:030711 abend when start screen size is narrow               //~v50AI~
//v501:020928 set default work dir when no env,/w parm             //~v501I~
//v500:020827 wxe support                                          //~v500I~
//v440:011125 browse hex                                           //~v440I~
//v43z:011124 7bit dump mode initial value is on for AIX           //~v43zI~
//v43y:011122 7bit dump mode                                       //~v30eI~
//v30e:010122 AIX support:(BUG)if dbcs space disp char is ove 0x40(range of dbcs 2nd byte)//~v30eI~
//            it is highlighten(ex ƒ_(x835F)                       //~v30eI~
//v30d:010104 AIX support:(BUG)if dbcs space disp char is same as dbcssplit char,//~v30dI~
//            split char is highlighten.                           //~v30dI~
//v303:001124 AIX support:unprintable char by '.'(ctl char unprintable under tera term)//~v303I~
//v21g:010107 LINUX support:lower case filename CB-->cb            //~v21gI~
//v21a:001209 LINUX support:lower case exe name(xe)                //~v21aI~
//v20g:001001 LINUX support(confirm when all member copy,move,...) //~v20gI~
//v20f:001001 LINUX support(uid/gid display on dirlist)            //~v20fI~
//v19C:000924 LINUX support(move PALNO_xx gro xe.h to uvio.h fo uviol.c)//~v19CI~
//v19i:000904 LINUX support(kbd io)                                //~v19iI~
//v190:000902 LINUX support(CRLF)                                  //~v190I~
//v158:000404 (BUG)when cap boundary plh is freed by undo which is inserted line,//~v158I~
//            Ssortplh is not now on plh chain.It cause abend at capreset to reset reverse.//~v158I~
//v13m:991031 no bell option support                               //~v13mI~
//v10X:990605 hex digit lineno display for binary file             //~v10XR~
//v10E:990417 another width value save for edit                    //~v10EI~
//v10w:990410 display width for eah text and binary                //~v10wI~
//v10m:990322 binary mode specification change /Mx-->/Mb,and save width once used//~v10mI~
//            until next explicit specification.(save also to sav file)//~v10mI~
//v106:981212 no tab expand when binaly file                       //~v106I~
//v101:981205 hex input                                            //~v101I~
//v0it:980717 funckey change option support                        //~v0itI~
//            write to ini when cmd/key assign changed             //~v0itI~
//v0im:980625 pfk cmd support(optk1 and optk2)                     //~v0imI~
//v0if:980620 pfk cmd support                                      //~v0ifI~
//v0g1:971207 print parm by short filename option(opt plfn on/off) //~v0g1I~
//v0f9:971017 UFCFLFN flag for lfn(common to os2/w95/gcc/dos)      //~v0f9I~
//v0f1:971010 os2 new malloc dump logic;no need initial heap alloc //~v0f1I~
//v0f0:971010 long filename support                                //~v0f0I~
//            win95 alias dir list option                          //~v0f0I~
//v0eq:970920 optionaize to update oom.default is prohibit         //~v0eqI~
//v0bb:970726 limit tabctr max 12,and tab expand limit chk         //~v0bbI~
//v0a1:970705:NULL data accept as 0x00.and change str___ to mem___ //~v0a1I~
//v09X:970629:.ini tab display char parm                           //~v09XI~
//v09U:970628:display unprintable char by 0x0f                     //~v09UI~
//v09P:970625:reject inhibit char input by change esc cmd          //~v09PI~
//v09L:970622:Find/Change *\x__,*\a etc(no support for replacing char)//~v08LI~
//v09K:970622:change char define value on dbcs tbl                 //~v08KI~
//v08l:961123:edit/browse line range parameter                     //~v08lI~
//v07u:960916:chk printcmd string where xprint is used             //~v07uR~
//v075:960608:color option                                         //~v075I~
//v06L:960424:alternative of v06I,use /J(unsigned char),it is default of cpp//~v06LI~
//v06I:960421:(BUG)for DOS,reverce color is not requested because  //~v06II~
//            signed char expanded flag for Gattrtbl               //~v06II~
//v06z:960407:stdout work last used seqno save to xe!SAVE!            //~v06zI~
//v06v:960406:assign pallette no to dir,cmd                           //~v06vI~
//v06n:960320:menu option 6(cmd) support(scrollsz and linenosz) //~v069I~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//v065:960217:save also cmd history to XE!SAVE!                 //~v065I~
//v064:960217:split inifile for Ginitscroll/Giniopt_/Ginifiletabskip//~v064I~
//v063:960217:sub shell prompt                                  //~v063I~
//v05k:951119:del dir confirm                                   //~v05kI~
//v05a:951104:xprint cmd string by ini file                     //~v05aI~
//*v031:950712:fixed cid variable apart from Scidtbl(alternative of v021)//~v031I~
//*v030:950709:dir proc avail flag on by 2nd line version id    //~v030I~
//*v01a:950705:kbd rate ini option(entry and exit value)        //~v01aI~
//*v018 950702:same ver/date to xe.ini and title msg            //~v018I~
//*v011:950610 clear reverse when double ESC enter              //~5610I~
//*********************************************************************//~5610I~
//* MACRO *******************************
#ifdef UNX                                                         //~v21aI~
	#define PGMID "xe"                                             //~v21aI~
#else                                                              //~v21aI~
    #ifdef WXE                                                     //~v500I~
//  	#define PGMID "xe"                                         //~v500R~//~vb2MR~
//  	#define PGMID "wxe"                                        //~vb2MI~//~vb2VR~
    	#define PGMID "xe"                                         //~vb2VI~
    #else                                                          //~v500I~
#define PGMID "XE"                                              //~5429M~
    #endif                                                         //~v500I~
#endif                                                             //~v21aI~
                                                                   //~v21aI~
#define MAXCOLUMN   240         //max display width
                                                                   //~va04I~
#ifdef UTF8SUPPH                                                   //~va04I~
#define MAXPARMSZ   (_MAX_PATH+MAXCOLUMN*UTF8_MAXCHARSZ)  //parameter size//~va04I~
#else                                                              //~va04I~
#define MAXPARMSZ   (_MAX_PATH+MAXCOLUMN)  //parameter size        //~va03I~
#endif                                                             //~va04I~
                                                                   //~va04I~
#define MINCOLUMN   16          //min display width                //~v50AI~
#define MAXLRECLV   32760                                          //~vazeI~
#ifdef DOSDOS                                                      //~v563I~
#define MAXLINEDATA 999         //max line data size except crlf
#else                                                              //~v563I~
//  #define MAXLINEDATA 9999    //max line data size except crlf   //~vazeR~
    #define MAXLINEDATA MAXLRECLV                                  //~vazeR~
#endif                                                             //~v563I~
#define GFILEBUFFSZ (MAXLINEDATA*4) //Gfilebuff size               //~v0bbI~
#define TABCTRMAX   12         //max tabctr                        //~v0bbI~
#define CMDLINENO 1            //second line is command line
#define TABCHAR  '\t'          //tabchar
#define EOFCHAR  0x1a          //eof iz                         //~5502I~
//#define TABPADCHAR   0x03    //tab skip id on dbcs tbl           //~v08KR~
//#define DBCS1STCHAR  0x01    //dbcs 1st char id on dbcs tbl      //~v08KR~
//#define DBCS2NDCHAR  0x02    //dbcs 2nd char id on dbcs tbl      //~v08KR~
#define TABPADCHAR   0x33      //tab skip id on dbcs tbl           //~v08LR~
#define DBCS1STCHAR  0x31      //dbcs 1st char id on dbcs tbl      //~v08LR~
#define DBCS2NDCHAR  0x32      //dbcs 2nd char id on dbcs tbl      //~v08LR~
//#define NULLCHARIDDATA   0x01 //null id on data tbl              //~v0a1R~
//#define NULLCHARIDDBCS   0x30 //null id on dbcs tbl              //~v0a1R~
#define DISPLINEATTRID 'l'     //display by lineno field attr,USDdbcs only//~v09UR~
                                                                   //~v501I~
#define XE_WKDIR "c:\\xe_wd"                                       //~v501I~
//#define FNMOF2NDSCR "*2"                                         //~v610R~
#define FNMOF2NDSCR "^*"                                           //~v610R~

//*************
#ifdef  GLOBAL
  #define EXT
  #define INIT(value) =value
#else
  #define EXT extern
  #define INIT(value)
#endif
//* FUNCTION *******************************
//*step count to next tab position                              //~4C29I~
//#define TABSKIPCTR(tabcharoffset)                                //~v8@2R~
//    (Gfiletabskip?Gfiletabskip-(tabcharoffset)%Gfiletabskip-1:0) //~v8@2R~
#define TABSKIPCTRF(tabskip,tabcharoffset) \
    ((tabskip) ? (tabskip)-(tabcharoffset) % (tabskip)-1:0)        //~v8@2I~
//#define TABSKIPCTR2(binsw,tabcharoffset)                         //~v8@2R~
//    (binsw?0:TABSKIPCTR(tabcharoffset))     //return 0 if binsw!=0//~v8@2R~
#define TABSKIPCTR2F(binsw,tabskip,tabcharoffset) \
    (binsw?0:TABSKIPCTRF(tabskip,tabcharoffset))     //return 0 if binsw!=0//~v8@2I~

//*Global variable *******************************
#if defined(ULIB64)||defined(ULIB64X)                              //~vazdI~
	#define LARGEFILESZ  (FILESZT)(1024*1024*1024)      //1GB      //~vazdR~
#else                                                              //~vazdI~
	#define LARGEFILESZ  (FILESZT)( 100*1024*1024)      //100MB    //~vazdR~
#endif                                                             //~vazdI~
EXT FILESZT Glargefilesz INIT(LARGEFILESZ);                        //~vazdR~
EXT UCHAR   *Gversion;              //version on xe.c           //~v018I~
EXT UCHAR   *Gverdate;              //version date on xe.c      //~v018I~
EXT UCHAR   Gopt;               //option
#define     GOPTUNDONOCONF       0x01       //no undo confirm required//~5430R~
#define     GOPTCANCELNOCONF     0x02       //no cancel confirm required//~5430R~
#define     GOPTNOABENDIFERREXIT 0x04       //abend if err exit //~5430R~
#define     GOPTPOPUPERRMSG      0x08       //errmsg by popup   //~5430R~
#define     GOPTTABDISPLAY       0x10       //tab char display  //~5430R~
#define     GOPTRCTLENTER        0x20       //use right-ctl as enter//~5430R~
#define     GOPTSAVENOCONF       0x40       //no save repl confirm required//~5430R~
#define     GOPTNOFTP            0x80       //no ftpsupport        //~v53UR~

EXT UCHAR   Gopt2;              //option                        //~5223I~
#define     GOPT2LINOINDENT     0x01        //no indent at line insert//~5223I~
#define     GOPT2NOCID          0x02        //CID set           //~5308R~
#define     GOPT2INITINSMODE    0x04        //Insert mode at atart//~5502R~
#define     GOPT2BOXREPCSR      0x08        //Rep mode csr is box//~5502R~
#define     GOPT2EOFWRITE       0x10        //Force EOF write   //~5502I~
#define     GOPT2EOFDROP        0x20        //Force drop EOF    //~5502I~
#define     GOPT2EOFWIFNEW      0x40        //write if new file //~5502R~
#define     GOPT2REJECTCTLCHAR  0x80        //reject ctl char   //~5506I~
                                                                //~5223I~
EXT UCHAR   Gopt3;              //option                        //~5507I~
#define     GOPT3DOSPRECIZEMA   0x01        //presize umalloc for DOS//~5507I~
#define     GOPT3DIRLISTINDENT  0x02        //dir indent listing//~v031R~
#define     GOPT3TESTABEND      0x04        //for test,abend by Esc*2//~v031I~
#define     GOPT3TESTEXIT       0x08        //for test,uerrexit by Esc*2//~v031I~
#define     GOPT3UNDELFREE      0x10    //free  undelete data at term//~v05kR~
#define     GOPT3UNDELLEAVE     0x20    //leave undelete data at term//~v05kR~
#define     GOPT3OOMNOPROT      0x40    //oom update avail         //~v0eqI~
#define     GOPT3W95ALIAS       0x80    //dir list by alias for LFN//~v0f0I~
                                                                   //~v0f9I~
EXT UCHAR   Gopt4;              //option4 not save to save file    //~v0f9I~
#define     GOPT4W95VFAT        0x80    //vfat support(W95 and GCC)//~v0f9R~
#define     GOPT4W95ALIASP      0x40    //print cmd parm fmt       //~v0g1R~
#define     GOPT4XLINENO        0x20    //hex lineno for binary file//~v10XI~
#define     GOPT4NOBEEP         0x10    //no beep option           //~v13mI~
#define     GOPT47BIT           0x08    //7bit dump mode for binary file//~v43yR~
#define     GOPT47BITCMD        0x04    //opt ascii cmd entered    //~v43zI~
#define     GOPT4NOBEEPCMD      0x02    //no beep option by opt cmd//~v54SI~
#define GOPT4RCTLCMD        0x01    //opt rctl cmd entered         //~v55cR~
EXT UCHAR   Gopt5;              //option5                          //~v55jI~
#define     GOPT5NOCTLCHARFUNC  0x80    //not use Ctl+char key for func key//~v55jR~
#define     GOPT5CSRSCROLL      0x40    //scroll by csr move on file scr//~v55qI~
#define     GOPT5CBNOCOPY       0x20    //no implicit copy to clipboad//~v584I~
#define     GOPT5XLINENOS       0x10    //"num xon/xoff s" entered //~v60kR~
#define     GOPT5DLCZOFF        0x08    //reject dlcmd z/0         //~v645R~
#define     GOPT5ACS            0x04    //LNX:use acs for drawing line//~v69MR~
#define     GOPT5COLSON         0x02    //COLS ON as default       //~v74yI~
#define     GOPT5CIDAPPEND      0x01    //CID APPEND MODE          //~v79UI~
                                                                //~5507I~
EXT UCHAR   Gscrstatus;         //srcreen status
#define     GSCRSINS            0x01        //insert mode
#define     GSCRSDBCS           0x02        //dbcs   mode
#define     GSCRSSPLITV         0x04        //split virtical
#define     GSCRSSPLITH         0x08        //split horizontal
#define     GSCRSCSRDOWN        0x80        //csr advance downword//~5225R~
#define     GSCRSEXTSG          0x40        //r.c EXTENDED_SG accept//~5225I~
#define     GSCRSDIRUGID        0x20        //uid/gid display mode on dirlist//~v20fI~
#define     GSCRSDIRUGNAME      0x10        //user/group name display mode on dirlist//~v20fI~
                                                                   //~v716I~
                                                                   //~v79zI~
EXT ULONG   Gotheropt;          //other option effective in this session//~v716I~
#define     GOTHERO_TRACEON   0x00000001    //trace on to notify xe3270//~v716I~
#define     GOTHERO_RCTLNL    0x00000002    //Right Ctrl key is NewLine by ini file//~v768R~
#define     GOTHERO_RCTLOFF   0x00000004    //Right Ctrl key is Off by ini file//~v768I~
//#define   GOTHERO_CLRCTLNL  0x00000008    //Right Ctrl key is Newline by cmdline option//~v792R~
#define     GOTHERO_SVOPTNL   0x00000008    //Right Ctrl key is Newline by ini file//~v792I~
#define     GOTHERO_SVOPTRCTL 0x00000010    //Right Ctrl on by saved opt(continues to next session)//~v792I~
#define     GOTHERO_RCTLOFFCL 0x00000020    //Right Ctrl off by cmdline parm//~van9I~
//#ifdef LNX                                                         //~vau0I~//~vauER~
#define     GOTHERO_DDFMTDL   0x00000040    //use ddfmt for dirlist//~vau0I~
//#endif                                                             //~vau0I~//~vauER~
//#ifdef LNX                                                         //~vb2jI~//~vb2nR~
#define     GOTHERO_NOFNTRANSOPT 0x00000080    //no LC<-->U8 filename translation by Edit/Browse/Select cmd FN{LC|U8} option//~vb2jR~
//#endif                                                             //~vb2jI~//~vb2nR~

EXT UCHAR   Gprocstatus;        //process status                //~5228I~
#define     GPROCSTERM          0x01        //termination(all popuped)//~5228I~
#define     GPROCSCANTERM       0x02        //last file op is CANCEL(not END)//~5228I~
#define     GPROCSCSRDOWN       0x04        //csr down after draw//~5423I~
#define     GPROCSCSRRIGHT      0x08        //csr right after draw//~5423I~
//#define   GPROCSINIUPDATE     0x10        //must write ini at term//~v065R~
#define     GPROCSXPRINT        0x10        //print cmd use xprint //~v07uI~
#define     GPROCSCSRSET        0x20        //chk to avoid normal nextline//~5701I~
#define     GPROCSINIUPDATE     0x40        //must write ini at term//~v0itI~
#define     GPROCSEXECMDFILE    0x80        //processing exe cmd file//~v563I~
                                                                   //~v79zI~
EXT UINT    Gotherstatus;                                          //~v79zI~
#define     GOTHERS_DBCS         0x01        //DBCS env            //~v79zI~
#define     GOTHERS_DBCSJ        0x02        //win:SJIS, lnx:EUC-JP,EUC-JP-UTF8//~v79zI~
#define     GOTHERS_CYGWIN       0x04        //cygwin term         //~v79MI~
#define     GOTHERS_NOUTF8       0x08        //no utf8 under utf env//~v7a5R~
#define     GOTHERS_FORCEUCJ     0x10        //force EUC-JP  by /C parm//~v7acI~
#define     GOTHERS_N9PARM       0x20        //n9 parm to force english//~va73I~
                                                                   //~v79zI~
#define  XE_ISDBCS()            (Gotherstatus & GOTHERS_DBCS)  //all CJK dbcs including +UTF8//~v79zI~
#define  XE_ISDBCSJ()           (Gotherstatus & GOTHERS_DBCSJ) //SJIS/EUC/+UTF8//~v79zR~
#ifdef WCSUPP                                                      //~v79zI~
  #ifdef LNX                                                       //~v79zR~
	#define  XE_ISEUCJ()            (Gotherstatus & (GOTHERS_DBCSJ|GOTHERS_FORCEUCJ))//~v7acI~
   #ifdef XXE                                                      //~v79zI~
	#define XE_ISDBCSKON()   (Gotherstatus & GOTHERS_DBCS)         //~v79zR~
	#define XE_ISDBCSKONJ()  XE_ISDBCSJ()    //always KON(Kanji avail)//~v79zR~
	#define XE_ISKONEUCJ()   XE_ISEUCJ()     //always KON(Kanji avail)//~v7acR~
   #else                                                           //~v79zI~
	#define XE_ISDBCSKON()   ((Gotherstatus & GOTHERS_DBCS)&&(Gunxflag & GUNX_KON))//~v79zR~
	#define XE_ISDBCSKONJ()  ((Gotherstatus & GOTHERS_DBCSJ)&&(Gunxflag & GUNX_KON))//~v79zR~
	#define XE_ISKONEUCJ()   (XE_ISEUCJ() && (Gunxflag & GUNX_KON))//~v7acR~
   #endif                                                          //~v79zI~
  #else                                                            //~v79zR~
	#define XE_ISDBCSKON()   (Gotherstatus & GOTHERS_DBCS)         //~v79zR~
	#define XE_ISDBCSKONJ()  XE_ISDBCSJ()                          //~v79zR~
  #endif                                                           //~v79zR~
#else  //!WCSUPP                                                   //~v79zI~
	#define XE_ISDBCSKON()   (UCBITCHK(Gscrstatus,GSCRSDBCS))	//dbcs//~v79zR~
	#define XE_ISDBCSKONJ()  XE_ISDBCSJ()                          //~v79zR~
#endif                                                             //~v79zI~
                                                                //~5228I~
EXT void   *Gproclastpft;           //last called function tbl  //~5228R~
                                                                //~5228I~
EXT int     Gxdconfindex;       //xdelete confirmation index    //~v05kI~
EXT int     Gscrconfreqid;                  //confirm req id
EXT int     Gscrconfactid;                  //confirm active req id
#define GSCRCONFUNDO   1    //undo confirmation
#define GSCRCONFCANCEL 2    //cancel updated file confirmation  //~5128R~
#define GSCRCONFSAVE   3    //replace file by save cmd confirmation//~5128I~
#define GSCRCONFDELDIR 4    //delete dir confirm                //~v05kR~
#define GSCRCONFALLMEMB 5   //confirmation to cmd for all member   //~v20gI~//~va73R~
#define GSCRCONFWILDNAME  6 //confirmation to delete wildname member on dirlist//~va73R~
#define GSCRCONFLARGEFILE 7 //confirmation to open large file      //~vazdI~

EXT int     Gscrsplith;         //screen split row
EXT int     Gscrsplitv;         //screen split column
EXT int     Gscrcurclient;     //current client index 0/1
EXT int     Gscrwidth;      //screen hwidth
EXT int     Gscrheight;     //screen height
EXT UCHAR  *Gscrdbcstbl;        //srcreen dbcs attr tbl

EXT int     Gcsrposx;       //cursor x-pos
EXT int     Gcsrposy;       //cursor y-pos

#define COLOR_COUNT    12               //start reverse attr idx      //~v06vR~
#define COLOR_FRAME     0                        //normal screen
#define COLOR_FRAME_R   COLOR_COUNT+COLOR_FRAME  //line selected
#define COLOR_BCLIENT   1                        //normal screen//~5430R~
#define COLOR_BCLIENT_R COLOR_COUNT+COLOR_BCLIENT //line selected//~5430R~
#define COLOR_BLINENO   2                        //normal screen//~5430R~
#define COLOR_BLINENO_R COLOR_COUNT+COLOR_BLINENO //line selected//~5430R~
#define COLOR_ECLIENT   3                        //normal screen//~5430I~
#define COLOR_ECLIENT_R COLOR_COUNT+COLOR_ECLIENT //line selected//~5430R~
#define COLOR_ELINENO   4                        //normal screen//~5430I~
#define COLOR_ELINENO_R COLOR_COUNT+COLOR_ELINENO //line selected//~5430R~
#define COLOR_TITLE     5                        //normal screen//~5430R~
#define COLOR_TITLE_R   COLOR_COUNT+COLOR_TITLE  //line selected
#define COLOR_DCLIENT   6                        //normal screen      //~v06vI~
#define COLOR_DCLIENT_R COLOR_COUNT+COLOR_DCLIENT //line selected     //~v06vR~
#define COLOR_DLINCMD   7                        //normal screen      //~v06vI~
#define COLOR_DLINCMD_R COLOR_COUNT+COLOR_DLINCMD //line selected     //~v06vR~
#define COLOR_DLINENO   8                        //normal screen      //~v06vI~
#define COLOR_DLINENO_R COLOR_COUNT+COLOR_DLINENO //line selected     //~v06vR~
#define COLOR_CCLIENT   9                        //normal screen      //~v06vI~
#define COLOR_CCLIENT_R COLOR_COUNT+COLOR_CCLIENT //line selected     //~v06vR~
#define COLOR_CLINENO   10                       //normal screen      //~v06vI~
#define COLOR_CLINENO_R COLOR_COUNT+COLOR_CLINENO //line selected     //~v06vR~
EXT char Gattrtbl[COLOR_COUNT*2];//attribute tbl(value set at scrinit)//~v06NR~

//***************************************************************  //~v075I~
//*pallette no default assign(0-7) (see color reg assign)          //~v075M~
//*color of when window(not full screen)                           //~v075M~
//*palleteno assign tbl index                                      //~v075M~
#define PAL_TITLEFG     0                                          //~v075M~
#define PAL_TITLEBG     1                                          //~v075M~
#define PAL_FRAMEFG     2                                          //~v075M~
#define PAL_FRAMEBG     3                                          //~v075M~
#define PAL_BLINENOFG   4    //browse LINENO                       //~v075M~
#define PAL_BLINENOBG   5                                          //~v075M~
#define PAL_BCLIENTFG   6    //browse file area                    //~v075M~
#define PAL_BCLIENTBG   7                                          //~v075M~
#define PAL_ELINENOFG   8    //edit   LINENO                       //~v075M~
#define PAL_ELINENOBG   9                                          //~v075M~
#define PAL_ECLIENTFG  10    //edit   file area                    //~v075M~
#define PAL_ECLIENTBG  11                                          //~v075M~
#define PAL_DLINCMDFG  12    //dirlist LINENO                      //~v075M~
#define PAL_DLINCMDBG  13                                          //~v075M~
#define PAL_DLINENOFG  14    //dirlist LINENO                      //~v075M~
#define PAL_DLINENOBG  15                                          //~v075M~
#define PAL_DCLIENTFG  16    //dirlist file name area              //~v075M~
#define PAL_DCLIENTBG  17                                          //~v075M~
#define PAL_CLINENOFG  18    //cmd result  LINENO                  //~v075M~
#define PAL_CLINENOBG  19                                          //~v075M~
#define PAL_CCLIENTFG  20    //cmd result  file area               //~v075M~
#define PAL_CCLIENTBG  21                                          //~v075M~
                                                                   //~v075I~
#define PAL_MAXENTRY   11                                          //~v075M~
                                                                   //~v075I~
EXT     UCHAR Gpallassigntbl[PAL_MAXENTRY*2];//pallette no assign tbl//~v075R~
                                                                   //~v075I~
EXT  UCHAR Gpallette[16]; //color reg assign tbl for pallete no    //~v075R~
EXT  UCHAR Gdefpallette[16]; //default color reg assign tbl for pallete no//~v075I~
//*****************************************************************//~v075I~
EXT char Ghelpdir[_MAX_PATH];                                      //~v71AI~
EXT char Gworkdir[_MAX_PATH];                                   //~5118I~
#define  WORKDIRPATHID      "::"                                //~5224R~
#define  WORKDIRPATHIDLEN   2                                   //~5118I~
#define  CLIPBOARDID        "::cb"                                 //~v21gR~
                                                                //~5429I~
//#define  CMDMAXSTACK        20                                   //~v670R~
#define  CMDMAXSTACK        40                                     //~v670I~
EXT int  Gcmdmaxstack INIT(CMDMAXSTACK);        //stack max count for cmd retrieve//~5430R~
EXT UQUEH Gcmdstack;  //cmd stack que                           //~5114I~
//EXT char Gcmdbuff[MAXCOLUMN+2];   //null term and long cmd id on offs=1//~v0imR~//~va04R~
#ifndef UTF8SUPPH       //for versionup compare by xfc             //~va04R~
EXT char Gcmdbuff[MAXCOLUMN+2];   //null term and long cmd id on offs=1//~va04I~
#else                                                              //~va04I~
EXT char Gcmdbuff[MAXPARMSZ+2];   //null term and long cmd id on offs=1//~va04I~
EXT char Gcmdbuffu8[MAXPARMSZ+2];   //by utf8 code                 //~va1rI~
EXT char Gcmdbufflc[MAXPARMSZ+2];   //by locale code               //~va1rI~
EXT char Gcmdbuffct[MAXPARMSZ+2];   //codetype tbl for locale code //~va1rI~
EXT char Gcmdbuffdbcs[MAXPARMSZ+2]; //dbcstbl                      //~va1rI~
EXT int  Gcmdbufflclen;                                            //~va1rI~
#endif                                                             //~va04I~
                                                                //~5430I~
//#define  INITIALHEAP      5                                      //~v0f1R~
//EXT int  Ginitheap INIT(INITIALHEAP);     //stack max count for cmd retrieve//~v0f1R~

EXT UCHAR *Gfilebuff;       //buff for record manipuration
EXT UCHAR *Gfilebuff2;      //buff for record manipuration      //~5102I~
//EXT USHORT *Gfilemfwtbl;    //multiple find word tbl             //~v62bR~
                                                                //~5430I~
#define  TABSKIPCOUNT       4                                   //~5430I~
EXT int  Gfiletabskip INIT(TABSKIPCOUNT);       //tab step count//~5430R~
EXT char Gfiletabdisp1;         //for tab char display(itself)  //~5102R~
EXT char Gfiletabdisp2;         //for tab char display(skipped byte)//~5102R~
EXT char Gunpdispchar3_after_inigetopt;//to resore "tab on 000"    //+vb5bI~

#define  KBDSPEED           30  //char/sec                      //~v01aI~
#define  KBDDELAY          250  //milisec                       //~v01aI~
EXT int  Gkbdspeed  INIT(KBDSPEED);   //keybord speed char/sec  //~v01aR~
EXT int  Gkbddelay  INIT(KBDDELAY);   //first delay milisecond  //~v01aR~
EXT int  Gkbdspeed2 INIT(KBDSPEED);   //keybord speed char/sec at exit//~v01aI~
EXT int  Gkbddelay2 INIT(KBDDELAY);   //first delay milisecond at exit//~v01aR~
EXT int  Gkbdinpctr;        //v011:key press ctr for double hit chk//~5610I~
                                                                //~5123I~
EXT PVOID Gcappcw;     //cut and paste active pcw               //~5223R~
EXT PVOID Gcapcbpcw;   //cut and paste clipboard file pcw save  //~5223I~
#ifdef WXEXXE                                                      //~v675R~
	EXT PVOID Gcapcbpfh;   //cut and paste clipboard file          //~v675R~
#endif                                                             //~v675R~
EXT PVOID Gcapplh1;    //cut and paste start plh                //~5223R~
EXT PVOID Gcapplh2;    //cut and paste end   plh                //~5223R~
                                                                   //~v158I~
EXT PVOID Gcalcpcw;     //calc target pcw                          //~v158I~
EXT PVOID Gcalcplh1;    //sorted top line                          //~v158I~
EXT PVOID Gcalcplh2;    //sorted end line                          //~v158I~
                                                                //~5429I~
#define  SHIFTIDNAMELEN     8                                   //~5429I~
EXT PVOID Gfunctbl;    //FUNCTBL                                //~5429I~
EXT PVOID Gkeytbl;     //KEYTBL                                 //~5429R~
EXT UCHAR **Gkeyshiftname;    //shift key id tbl                //~5501R~
                                                                //~5603I~
//*for ini file update                                          //~5603I~
EXT UCHAR   Giniopt;    //tab display on/off                    //~v064R~
EXT UCHAR   Giniopt2;   //cid defon/defoff                      //~v064R~
//EXT UCHAR     Giniopt3;           //option after when ini read//~v064R~
EXT UCHAR   Glastsono;      //last used stdout seqno                  //~v06zI~
EXT UCHAR   Glinenoszb;     //browse lineno field sz            //~v069I~
EXT UCHAR   Glinenosze;     //edit   lineno field sz            //~v069R~
EXT UCHAR   Glinenoszc;     //cmd    lineno field sz            //~v069I~
EXT int  Ginifiletabskip;   //tab column after when ini read    //~v064R~
                                                                //~v031I~
EXT UCHAR   Gfixcidid[16];      //fixed cid prefix id           //~v031I~
                                                                //~v031I~
#define GSCROLLBROWSE  0                                        //~v031I~
#define GSCROLLEDIT    1                                        //~v031I~
#define GSCROLLDIR     2                                        //~v031I~
#define GSCROLLCMD     3                                        //~v069R~
#define GSCROLLFKT     4   //opt =0.1/2/3                          //~v71vI~
//EXT int Ginitscroll[4];                                          //~v71vR~
EXT int Ginitscroll[5];                                            //~v71vI~
                                                                //~v031I~
EXT UCHAR *Gxprintcmd;      //xprint command and option         //~v05aR~
EXT UCHAR *Gxprintcmd0;     //xprint command and option default //~v05aI~
EXT UCHAR *Gprintcmd;       //print pgm name(default is same as xprint)//~v05aI~
                                                                //~v05kI~
EXT char *Gshellicmd;//sub shell init cmd                       //~v063R~
EXT char *Gshellicmd0;//sub shell init cmd default              //~v063I~
                                                                   //~v08lI~
EXT void *Gpodelmt;         //del and parse out area               //~v08lI~
EXT UCHAR *Gvalidchartbl;    //input char validation tbl           //~v09PR~
EXT UCHAR *Gunpdispchartbl; //selected unprintable char display table//~v09UI~
EXT UCHAR *Gunpdispchartblj;//english unprintable char display table//~v09UI~
EXT UCHAR *Gunpdispchartble;//english unprintable char display table//~v09UI~
EXT UCHAR *Gunpdispchartblj_wxe;//english unprintable char display table//~v500I~
EXT UCHAR *Gunpdispchartble_wxe;//english unprintable char display table//~v500I~
EXT UCHAR Gunpdispchar[4]; //curr/eng/jpn trans char               //~v09XR~
                                                                   //~v303I~
#define   DEFAULT_ALTDISPCH   0xff                                 //~va46I~
#ifdef UNX                                                         //~v303I~
	#define UNPCHARDISPXJ0 0x2e   //unprintable char display char('.')//~v303I~
	#define UNPCHARDISPXE0 0x2e   //unprintable char display char('.')//~v303I~
//  #define DBCSSPACEDISP0 0x2e   //dbcs space second byte         //~v30dR~
//  #define DBCSSPACEDISP0 0x5f   //dbcs space second byte "_"     //~v30eR~
//  #define DBCSSPACEDISP0 0x21   //dbcs space second byte "!"     //~v30eI~//~va44R~
    #define DBCSSPACEDISP0 0xff   //uviom replace it to shadow block//~va44I~
    #ifdef LNX                                                     //~v303I~
//  	#define UNPCHARDISPXJ 0x0e   //unprintable char display char//~v51DR~
//  	#define UNPCHARDISPXE 0x16   //unprintable char display char//~v51DR~
//  	#define DBCSSPACEDISP 0x14   //dbcs space second byte      //~v51DR~
    	#define DBCSSPACEDISP0 0xff   //uviom replace it to shadow block//~va44I~
//		#define UNPCHARDISPXJ UNPCHARDISPXJ0   //unprintable char display char('.')//~va47R~
//		#define UNPCHARDISPXE UNPCHARDISPXE0   //unprintable char display char('.')//~va47R~
		#define UNPCHARDISPXJ DEFAULT_ALTDISPCH //unprintable char display char('.')//~va47R~
		#define UNPCHARDISPXE DEFAULT_ALTDISPCH //unprintable char display char('.')//~va47R~
		#define DBCSSPACEDISP DBCSSPACEDISP0   //dbcs space second byte//~v51DI~
    #else                                                          //~v303I~
		#define DBCSSPACEDISP0 0x21   //dbcs space second byte "!" //~va44I~
		#define UNPCHARDISPXJ UNPCHARDISPXJ0   //unprintable char display char('.')//~v303R~
		#define UNPCHARDISPXE UNPCHARDISPXE0   //unprintable char display char('.')//~v303R~
		#define DBCSSPACEDISP DBCSSPACEDISP0   //dbcs space second byte//~v303I~
    #endif                                                         //~v303I~
#else                                                              //~v303I~
//#define UNPCHARDISPXJ 0x0e   //unprintable char display char     //~va46R~
//#define UNPCHARDISPXE 0x16   //unprintable char display char     //~va46R~
#define UNPCHARDISPXJ DEFAULT_ALTDISPCH   //unprintable char display char//~va46I~
#define UNPCHARDISPXE DEFAULT_ALTDISPCH   //unprintable char display char//~va46I~
#ifdef W32                                                         //~va44I~
	#define DBCSSPACEDISP 0xff  //uviom replace it to shadow block //~va44I~
#else                                                              //~va44I~
#define DBCSSPACEDISP 0x14   //dbcs space second byte              //~v09XI~
#endif                                                             //~va44I~
#endif                                                             //~v303M~
                                                                   //~v303I~
EXT UCHAR Gtabdispchar[4]; //eng1/eng2/jpn1/jpn2/dbcs space        //~v09XR~
//#define TABCHARDISPX1J 0x1c   //tab display char                 //~va46R~
//#define TABCHARDISPX2J 0x1e   //tab space display char           //~va46R~
//#define TABCHARDISPX1E 0x18   //tab display char                 //~va46R~
//#define TABCHARDISPX2E 0x1a   //tab space dispalay char          //~va46R~
#define TABCHARDISPX1J DEFAULT_ALTDISPCH   //tab display char      //~va46I~
#define TABCHARDISPX2J DEFAULT_ALTDISPCH   //tab space display char//~va46I~
#define TABCHARDISPX1E DEFAULT_ALTDISPCH   //tab display char      //~va46I~
#define TABCHARDISPX2E DEFAULT_ALTDISPCH   //tab space dispalay char//~va46I~
//EXT INT4 Gopttabaltch[2]; //tab and tabpad by TAB on cmd         //~vb5bR~
EXT INT4 Gopttabaltch[3]; //tab and tabpad and DBCSspace by TAB on cmd//~vb5bI~
                                                                   //~v101I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
    EXT UCHAR Ghexctl[12];   //0:mode,1-3:binary data,4:len, 5-10:saved char digit//~va3xI~
    #define HEXCTL_MODE   0                                        //~va3xI~
	#define HEXCTL_MODE_ON   0x01                                  //~va3HI~
	#define HEXCTL_MODE_UCS4 0x02                                  //~va3HI~
	#define HEXCTL_MODE_UCS2 0x04                                  //~va3KI~
	#define HEXCTL_MODE_UCS (HEXCTL_MODE_UCS2|HEXCTL_MODE_UCS4)    //~va3KI~
    #define HEXCTL_BIN    1     //binary converted max 3 byte      //~va3xI~
    #define HEXCTL_LEN    4                                        //~va3xI~
    #define HEXCTL_DATA   5     //max 6 char                       //~va3xI~
#else                                                              //~va3xI~
EXT UCHAR Ghexctl[8];   //0:mode,1-2:dbcs byte,3:len, 4-7:saved char//~v101I~
#define HEXCTL_MODE   0                                            //~v101M~
                                                                   //~va3KI~
#define HEXCTL_MODE_ON   0x01                                      //~va3KI~
#define HEXCTL_MODE_UCS2 0x04                                      //~va3KI~
#define HEXCTL_MODE_UCS (HEXCTL_MODE_UCS2)                         //~va3KI~
                                                                   //~va3KI~
#define HEXCTL_BIN    1     //binary converted max 2 byte          //~v101M~
#define HEXCTL_LEN    3                                            //~v101M~
#define HEXCTL_DATA   4     //max 4 char                           //~v101M~
#endif                                                             //~va3xI~
                                                                   //~v10mI~
EXT USHORT Gfhwidth;        //bin mode display width               //~v10mI~
EXT USHORT Gfhxwidth;       //hex bin mode display width           //~v440I~
EXT USHORT Gfhwidthtxt;     //text mode display width for browse   //~v10ER~
EXT USHORT Gfhwidthtxtedit; //text mode display width for edit     //~v10EI~
                                                                   //~v19iI~
EXT int Gkbdopt;                                                   //~v19iI~
//**************************                                       //~v500I~
//#ifdef WXE                                                       //~v641R~
#ifdef WXEXXE                                                      //~v641I~
	int xemain(int Preqtype,int parmc,char *parmp[]);              //~v500I~
#endif    // WXE                                                   //~v500I~
