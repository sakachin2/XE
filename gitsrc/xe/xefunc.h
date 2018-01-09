//*CID://+vbe0R~:                             update#=  150;       //~vbe0R~
//*********************************************************************
//* xefunc.h
//*********************************************************************
//vbe0:171231 add function to search xml tag pair by A+/           //~vbe0I~
//vbds:171203 (BUG)FTFDUPACMDFUNC=FTFCMDONLY=0x40-->ini file error msg//~vbdsI~
//vbd7:171119 "SEL all" support on file panel                      //~vbd7I~
//vba2:170710 add SP cmd to register shortcut path name and use by  sp:xxx//~vba2I~
//vb55:160904 old func-key def on ::xe.in reset new added default key of xefunct//~vb55I~
//vb50:160827 accept S+A/C+extended key                            //~vb50I~
//vbCC:160825 (Bug)F5 with operand is missing chk INX cmd verb     //~vbCCI~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vavQ:140405 set parsed cmdlc(for xprint dcmd u8filename)         //~vavQI~
//vac0:120131 (SMB)node cmd to set volatile password to UFTPHOST   //~vac0I~
//va7K:100904 add RESET option to cv cmd B2B(change UFHhandle) and CP option to EBC cmd.//~va7KI~
//va3d:100206 (LNX)toggle ligature temprary by A+";", change combine key A+"/"-->C+":"//~va3dI~
//va30:100126 combine mode of diacritical marks by A+/             //~va30I~
//va0x:090920!kbd mode change(A+u)                                 //~va0xI~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v78r:080326 profile function                                     //~v78rI~
//v783:080227 CUT/PASTE cmd to use another clipboard(save/restore each time)//~v783I~
//v780:080212 syntaxhighlight support                              //~v780I~
//v77F:080204 C+W copy to cmdline(No cmd verb)                     //~v77EI~
//v77E:080203 FW(C+"["/"]")/IW(C+"{"|"}") cmd support              //~v773I~
//v773:071121*Ctrl+Tab for function to jump between char and ehx part//~v773I~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v76i:070622 more(key by key) allowance for duplicated function key assignment//~v76iI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HI~
//v755:070418 add TFLOW cmd                                        //~v755I~
//v74E:070315 BOUNDS cmd support                                   //~v74EI~
//v72P:061214 add ic cmd(case insensitive change)                  //~v72PI~
//v71Q:061107 functbl search faile when key change save if line-draw char string defined//~v71QI~
//v71P:061107 enable cmd verb change on =0.2 panel                 //~v71PI~
//v70z:060904 3270 ftp support(hostfile,TSO command)               //~v70zI~
//v705:060727 graphic char setup by external file(2 string for opt linech on/off)//~v705I~
//v69J:060712 cap(CAPS LOCK On) support                            //~v69JI~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//v67M:060206 os/2 compile err by v679                             //~v67MI~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~v67CI~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~v670I~
//v66f:051021 support standard mode cut & paste,assign Ctrl+v for stream insert//~v66fI~
//                     None   OpenBlock  ClosedBlock   OpenRegion ClosedRegion//~v66fI~
//            C+v    RgnIns   NoBlockErr BlockClearRep OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Ins  BlockIns NoBlockErr GetBlock+Ins  OpenRgnErr RgnModeErr//~v66fR~
//            A+Rep  BlockRep NoBlockErr GetBlock+Rep  OpenRgnErr RgnModeErr//~v66fR~
//v66e:051020 support standard mode cut & paste;                   //~v66eI~
//            A+F6/A+v:range specification, A+F9:copy, A+Ins:paste Ins, A+F8:paste Rep, C+v:paste Del then Ins//~v66eI~
//            Del/BackSpace:delete range, A+Del:del+copy to clipboard//~v66eI~
//v651:050712 (XXE)xxe support;AT cmd,sleep cmd                    //~v651I~
//v64v:050708 (LNX)openwith support(! lcmd & ASS cmd)              //~v64vI~
//v61t:050306 (LNX:BUG by v61j)funcname sjis->sbc change beyond name field by dup conv(hankaku expand),//~v61tI~
//v61d:050222 support pgtop/pglast for filename list               //~v61dI~
//v592:041031 rsh cmd support                                      //~v592I~
//v57j:040522 sort cmd for dirlist                                 //~v57jI~
//v564:040326 (WIN)at cmd ignore err option "-i"                   //~v564I~
//v562:040325 (WIN)AT cmd support                                  //~v562I~
//v560:040324 (WIN)break sleep by esc*2                            //~v560I~
//v55Y:040324 (WIN)Sleep cmd for multicmd                          //~v55YI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55WI~
//v55N:040318 linetop & lineend for dirlist                        //~v55NI~
//v55n:040218 EXE cmd(execute xe command file)                     //~v55nI~
//v55j:040215 (LNX)use ctl+char as alternative of Shift+xx         //~v55jI~
//v55h:040214 (FTP)uid/gid display for remote file                 //~v55hI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//v558:040204 new func:path up/down by A+left/right                //~v558I~
//v557:040203 filename list multi-page support                     //~v557I~
//v53c:030921 alt+w for C&P copy word                              //~v53cI~
//v51y:030704 xbc:option to set result output to cmd input line to continued operation//~v51yI~
//v511:030302 new rotate cmd                                       //~v511I~
//v50G:030201 add cmd "et"/"bt"/"st" for e/b/s /mt                 //~v50GI~
//v504:021006 accept ren cmd as "num reset" on edit scr            //~v504I~
//v503:021006 accept del cmd as drop on edit scr                   //~v503I~
//v48f:020504 more key for macro function(not only PFn but also A+q,A+a and 1 byte char)//~v48fI~
//v47U:020407 cv cmd(euc<-->sjis)                                  //~v47UI~
//v47k:020309 support cmd repeat key(alt+F11)                      //~v47kI~
//v47i:020302 join cmd support:"join nx/x .a .b"                   //~v47iI~
//v440:011125 browse hex                                           //~v440I~
//v42y:011010 add cmd ek,bk,sk,ekn,bkn,skn                         //~v414I~
//v42w:010929 pair-parenthesis search  by alt+, except excluded line//~v42wI~
//v42h:010929 pair-parenthesis search  by alt+.                    //~v42hI~
//v41k:010820 add XR command(reverse excluded line)                //~v41kI~
//v414:010728 EC/ENC/BC/BNC/SC/SNC cmd add for cobol               //~v182I~
//v20i:001009 dupkey list order;on edit screen-->dirlist screen    //~v20iI~
//v20f:001001 LINUX support(uid/gid display on dirlist)            //~v20fI~
//v182:001209 long filename display on dirlist(over attr fld)      //~v182I~
//v17f:000501 change TCN to TC and NX option.                      //~v17fI~
//v155:000318 numeric calc func                                    //~v155I~
//v152:000311 dir-list REFresh cmd                                 //~v152I~
//v11N:990829 COL cmd support                                      //~v11NI~
//v10M:990424 support cap to cmdline                               //~v10MI~
//v10L:990424 EN/BN/SN edit/browse command for SPF file specific.(No cid,margin=72,P=1)//~v10LI~
//v10I:990417 sort cmd                                             //~v10II~
//v10G:990417 EB/BB/SB for "e /mx","b /mx","s /mb"                 //~v10GI~
//v10r:990327 display lineno on dir list                           //~v10rI~
//v10n:990324 Find/Ifind NX (FNX/INX) cmd;search not excluded line only//~v10nI~
//v101:981205 hex input                                            //~v101I~
//v0k4:981128 SUBmit cmd                                           //~v0k4I~
//v0jn:980723 KEY cmd                                              //~v0jnI~
//v0j2:980720 POS cmd for fn-cmd key                               //~v0j2I~
//v0iw:980718 pfk cmd support(del 0.5,cmd change by ini only)      //~v0iwI~
//v0iu:980717 cmd compare by strcpy not by memcpy because i and iii is dup//~v0iuI~
//v0it:980717 funckey change option support                        //~v0itI~
//            write to ini when cmd/key assign changed             //~v0itI~
//v0is:980705 change max key number assign to func 8 to 4          //~v0isI~
//v0io:980702 pfk cmd support(opt 0.4)                             //~v0ioI~
//v0ih:980621 pfk cmd support(pfk table)                           //~v0ihI~
//v0ie:980607 Locate cmd for disrlist                              //~v0ieI~
//v0ia:980530 add APPend cmd                                       //~v0iaI~
//v0hP:980428 I changed mind,abondon DEL x all,use DRo  only.      //~v0hPI~
//v0hz:980412 EXCLUDE/IEXCLUDE cmd support                         //~v0hzI~
//v0hu:980410 DEL cmd on edit screen(same as DROP)                 //~v0h9I~
//v0hq:980316 add DROP cmd(del line XON/XOFF)                      //~v0h9R~
//v0he:980130 cap save operation for paste after end/cancel(Alt+f9)//~v0heI~
//v0cr:970814 NUM VER subcmd --> VER cmd                           //~v0a2I~
//v0a2:970705:allow 00 input                                       //~v0a2I~
//            ext_key NULL(ctrl+2) definition                      //~v0a2I~
//v09P:970625:reject inhibit char input by change esc cmd(Gbl ptr) //~v09PI~
//v09w:970524:Select cmd support on dir list                       //~v09wI~
//            (duplcate alias support)                             //~v09wI~
//v07e:960629:dir lcmd copy(PF10 and PF11)                         //~v07eI~
//v07b:960615:(BUG) FUNCID definition is duplicated                //~v07bI~
//v07a:960615:allow dup key assign to differrent function for only on of assigned key//~v07aI~
//            color option-2                                       //~v07aI~
//              -field next value function for color register field//~v07aI~
//v06l:960317:rearange key for no num option                    //~v06lI~
//           -alt+i/j/k to line insert mode copy/move/null move //~v06lI~
//           -change copy/move/null move is insert mode only,   //~v06lI~
//			  so join alt+c	to alt+Ins                          //~v06lI~
//           -COPY/MOVE destination not by alt+a but by any line insert cmd//~v06lI~
//           -include/exclude/include last/include first        //~v06lI~
//v06h:960310:support Copy/Move file by ALt+a                   //~v06hI~
//v06g:960310:Alt+c for copy ins/rep by Ins mode                //~v06gI~
//v06f:960309:change paste key Alt+o-->Alt+p,add Alt+o as override//~v06fI~
//v06e:960309:for num off case,add line mark(Alt+l) and posision mark(Alt+a)//~v06eI~
//v069:960224:linenosz changeable for edit/browse(func_number)  //~v069I~
//v05B:960104:Option commnad                                    //~v05BI~
//*v033:950715:SCROLL cmd for dir list scroll                   //~v033I~
//*v030:950709:dir pgup/pgdn/filetop/fileend/lineup/linedown share with file//~v030I~
//*v020:950624:dir support                                      //~v020R~
//*********************************************************************//~v020I~
//*DATA TYPE
#define FUNCPARMS  		PUCLIENTWE Ppcw
#define FUNCPARMSTYPE   PUCLIENTWE
#define FUNCPARMSPARM   Ppcw

typedef int (FTFUNC)(FUNCPARMS);
                                                                //~5204I~
//*unction id number                                            //~5204I~
#define FUNCID_EXECNL        1                                  //~5205R~
#define FUNCID_NEXTLINE      2                                  //~5205I~
#define FUNCID_RESET         3                                  //~5205R~
#define FUNCID_INS           4                                  //~5205R~
#define FUNCID_UP            5                                  //~5205R~
#define FUNCID_DOWN          6                                  //~5205R~
#define FUNCID_LEFT          7                                  //~5205R~
#define FUNCID_RIGHT         8                                  //~5205R~
#define FUNCID_TAB           9                                  //~5205R~
#define FUNCID_BKTAB        20                                  //~5521R~
#define FUNCID_LINETOP      21                                  //~5521R~
#define FUNCID_LINEEND      22                                  //~5521R~
#define FUNCID_LINEUP       23                                  //~5521R~
#define FUNCID_LINEDOWN     24                                  //~5521R~
#define FUNCID_HOME         25                                  //~5521R~
#define FUNCID_PGUP         26                                  //~5521R~
#define FUNCID_PGDN         27                                  //~5521R~
#define FUNCID_PGLEFT       28                                  //~5521R~
#define FUNCID_PGRIGHT      29                                  //~5521R~
#define FUNCID_TOP          40                                  //~5521R~
#define FUNCID_BOTTOM       41                                  //~5521R~
#define FUNCID_BS           42                                  //~5521R~
#define FUNCID_DEL          43                                  //~5521R~
#define FUNCID_LINEDEL      44                                  //~5521R~
#define FUNCID_EEOL         45                                  //~5521R~
#define FUNCID_ETOL         46                                  //~5521R~
#define FUNCID_CTOL         47                                  //~5521R~
#define FUNCID_LINESPLIT    48                                  //~5521R~
#define FUNCID_LINEINS      49                                  //~5521R~
#define FUNCID_LINEREP      60                                  //~5521R~
#define FUNCID_BLOCK        61                                  //~5521R~
#define FUNCID_BLOCKREP     62                                  //~5521R~
#define FUNCID_BLOCKDEL     63                                  //~5521R~
#define FUNCID_BLOCKINS     64                                  //~5521R~
#define FUNCID_BLOCKCLEAR   65                                  //~5521R~
#define FUNCID_BLOCKCUTMOVE 66                                  //~5521I~
#define FUNCID_BLOCKCLRMOVE 67                                  //~5521I~
#define FUNCID_HSPLIT       68                                  //~5521R~
#define FUNCID_VSPLIT       69                                  //~5521R~
#define FUNCID_SWAP         80                                  //~5521R~
#define FUNCID_NEXTSCR      81                                  //~5521R~
#define FUNCID_PREVSCR      82                                  //~5521R~
#define FUNCID_HELP         83                                  //~5521R~
#define FUNCID_EXIT         84                                  //~5521R~
#define FUNCID_TERM         85                                  //~5521R~
#define FUNCID_QUIT         86                                  //~5521R~
#define FUNCID_END          87                                  //~5521R~
#define FUNCID_SAVE         88                                  //~5521R~
#define FUNCID_CANCEL       89                                  //~5521R~
#define FUNCID_NEXTVALUE    90  //next color RGB value and enter   //~v07aI~
#define FUNCID_PREVVALUE    91  //prev color RGB value and enter   //~v07aI~
#define FUNCID_DLCMDCUT     92  //dlcmd cut to paste               //~v07eR~
#define FUNCID_DLCMDPASTE   93  //dlcmd paste from save            //~v07eR~
#define FUNCID_EBC          94  //EBC cmd                          //~va7KI~
#define FUNCID_NODE         95  //NODE cmd                         //~vac0I~
#define FUNCID_XMLSRCH      96  //xml pair search                  //~vbe0I~
#define FUNCID_EDIT        100                                  //~5521R~
#define FUNCID_BROWSE      111                                     //~v07bR~
#define FUNCID_PREVCMD     112                                     //~v07bR~
#define FUNCID_NEXTCMD     113                                     //~v07bR~
#define FUNCID_CREATE      114                                     //~v07bR~
#define FUNCID_REPL        115                                     //~v07bR~
#define FUNCID_COPY        116                                     //~v07bR~
#define FUNCID_MOVE        117                                     //~v07bR~
#define FUNCID_UNDO        118                                     //~v07bR~
#define FUNCID_REDO        119                                     //~v07bR~
#define FUNCID_HEX         120                                  //~5521R~
#define FUNCID_LOCATE      121                                  //~5521R~
#define FUNCID_FIND        122                                  //~5521R~
#define FUNCID_IFIND       123                                  //~5521R~
#define FUNCID_RFIND       124                                  //~5521R~
#define FUNCID_REVRFIND    125                                  //~5521R~
#define FUNCID_CHANGE      126                                  //~5521R~
#define FUNCID_RCHANGE     127                                  //~5521R~
#define FUNCID_REVRCHANGE  128                                  //~5521R~
#define FUNCID_TABCMD      129                                  //~5521R~
#define FUNCID_FINDPSP     130                                     //~vbCBI~
#define FUNCID_FINDPSF     131                                     //~vbCBI~
#define FUNCID_DISPLAYPS   132                                     //~vbCBI~
#define FUNCID_REVRFINDPSP 133                                     //~vb50R~
#define FUNCID_REVRFINDPSF 134                                     //~vb50R~
#define FUNCID_SHORTPATH   135                                     //~vba2I~
#define FUNCID_DOS         140                                  //~5521R~
#define FUNCID_CSRSTEP     141                                  //~5521R~
#define FUNCID_CID         142                                  //~5521R~
#define FUNCID_INI         143                                  //~5521R~
#define FUNCID_SCROLL      144                                  //~v033I~
#define FUNCID_OPT         145                                  //~v05BI~
#define FUNCID_NUM         146                                  //~v069I~
#define FUNCID_LINEMARK    147                                        //~v06eR~
//#define FUNCID_LINECOPY    148      //cut/paste copy after line//~v06lR~
#define FUNCID_RENUM       148      //ren cmd on edit scr:renum    //~v504I~
#define FUNCID_BLOCKREPSPACE 149      //copy over               //~v06fR~
//#define FUNCID_BLOCKCOPY   150      //cut/paste copy block by Ins/rep mode//~v06lR~
#define FUNCID_COPYTOCB    150  //cut/paste copy block to CB       //~v0heI~
#define FUNCID_LIBLOCKINS  151  //line insert mode block copy   //~v06lR~
#define FUNCID_LIBLOCKCUTMOVE 152  //line insert mode block move//~v06lI~
#define FUNCID_LIBLOCKCLRMOVE 153  //line insert mode block move with nullify//~v06lI~
#define FUNCID_LINEEXCLUDE 154  //exclude line                  //~v06lI~
#define FUNCID_LINEINCLUDE 155  //include all                   //~v06lI~
#define FUNCID_LINEINCF    156  //include first                 //~v06lI~
#define FUNCID_LINEINCL    157  //include last                  //~v06lI~
#define FUNCID_SELECT      158  //select from dirlist              //~v09wI~
#define FUNCID_VERSION     159  //select from dirlist              //~v0h9R~
#define FUNCID_DROP        160  //del all exclude/include line     //~v0h9R~
//#define FUNCID_DELX        161  //same as drop on edit screen    //~v0hPR~
#define FUNCID_DELX        161  //same as drop on edit screen      //~v503I~
#define FUNCID_EXCLUDE     162  //find and exclude line            //~v0hzI~
#define FUNCID_IEXCLUDE    163  //ifind and exclude line           //~v0hzI~
#define FUNCID_APPEND      164  //append                           //~v0iaI~
#define FUNCID_POS         165  //csr position                     //~v0j2I~
#define FUNCID_KEY         166  //char input                       //~v0jnI~
#define FUNCID_SUBMIT      167  //submit                           //~v0k4I~
#define FUNCID_HEXINPUT    168  //hex inputmode on/off             //~v101I~
#define FUNCID_FINDNX      169  //find on displayed line only      //~v10nI~
#define FUNCID_IFINDNX     170  //ifind on displayed line only     //~v10nI~
#define FUNCID_CHANGENX    171  //ifind on displayed line only     //~v10nI~
#define FUNCID_DLCCHNGSZ   172  //change filesize display option(size<-->lineno)//~v10rR~
#define FUNCID_EDITBIN     173  //edit /mb                         //~v10GI~
#define FUNCID_BROWSEBIN   174  //browse /mb                       //~v10GI~
#define FUNCID_SELECTBIN   175  //select /mb                       //~v10IR~
#define FUNCID_SORT        176  //sort                             //~v10II~
#define FUNCID_EDITSPF     178  //edit /mn                         //~v174R~
#define FUNCID_BROWSESPF   179  //browse /mn                       //~v174R~
#define FUNCID_SELECTSPF   180  //select /mn                       //~v174R~
#define FUNCID_COL         181  //COL cmd                          //~v174R~
#define FUNCID_REFRESH     182  //REF cmd                          //~v174R~
#define FUNCID_BC          183  //BC                               //~v174R~
#define FUNCID_TC          184  //TC                               //~v174R~
//#define FUNCID_TCNX        185  //TCN                            //~v17fR~
                                                                   //~v182I~
//#ifdef UNX                                                       //~v55hR~
//#ifdef FTPSUPP                                                   //~v67MR~
#define FUNCID_DLCUIDORSZ  185  //display change uid/gid or filesize//~v20fI~
//#endif                                                           //~v67MR~
                                                                   //~v182I~
#define FUNCID_DLCLFN      186  //long filename display on dir list//~v182I~
                                                                   //~v182I~
#define FUNCID_EDITSPFCOB     187  //edit /mn                      //~v414R~
#define FUNCID_BROWSESPFCOB   188  //browse /mn                    //~v414R~
#define FUNCID_SELECTSPFCOB   189  //select /mn                    //~v414R~
#define FUNCID_EDITSPFCOBNUM     190  //edit /mn                   //~v414R~
#define FUNCID_BROWSESPFCOBNUM   191  //browse /mn                 //~v414R~
#define FUNCID_SELECTSPFCOBNUM   192  //select /mn                 //~v414R~
#define FUNCID_XEXCHANGE         193  //reverse excluded line      //~v41kR~
#define FUNCID_PPSRCH            194  //pair parenthesis search    //~v42hI~
#define FUNCID_PPSRCHNX          195  //pair parenthesis search    //~v42wI~
#define FUNCID_EDITSPFCOB2    196  //edit /mk                      //~v42yI~
#define FUNCID_BROWSESPFCOB2  197  //browse /mk                    //~v42yI~
#define FUNCID_SELECTSPFCOB2  198  //select /mk                    //~v42yI~
#define FUNCID_EDITSPFCOB2NUM    199  //edit /mkn                  //~v42yR~
#define FUNCID_BROWSESPFCOB2NUM  200  //browse /mkn                //~v42yR~
#define FUNCID_SELECTSPFCOB2NUM  201  //select /mkn                //~v42yR~
#define FUNCID_BROWSEHEX      202  //browse /mk                    //~v440I~
#define FUNCID_EDITHEX        203  //select /mk                    //~v440I~
#define FUNCID_SELECTHEX      204  //select /mk                    //~v440R~
#define FUNCID_JOIN           205  //join cmd                      //~v47iR~
#define FUNCID_CMDREPEAT      206  //repeat previous cmd           //~v47kI~
#define FUNCID_DBCSCONV       207  //dbcs conversion cmd           //~v47UR~
#define FUNCID_SHORTCUT       208  //shortcut key prefix           //~v48fI~
#define FUNCID_SHORTCUTQUERY  209  //shortcut query key prefix     //~v48fI~
#define FUNCID_EDITTEXT    210  //edit /mt                         //~v50GI~
#define FUNCID_BROWSETEXT  211  //browse /mt                       //~v50GI~
#define FUNCID_SELECTTEXT  212  //select /mt                       //~v50GI~
#define FUNCID_ROTATE      213  //rotate cmd                       //~v511I~
#define FUNCID_COPYWORD    214  //C&P copy word                    //~v53cI~
#define FUNCID_PATHUP      215  //dir path up                      //~v558I~
#define FUNCID_PATHDOWN    216  //dir path down                    //~v558I~
#define FUNCID_EXECMDFILE  217  //execute command file             //~v55nI~
#define FUNCID_ATCMD       218  //repeat cmd with interval         //~v55WI~
#define FUNCID_SLEEP       219  //sleep between multicmd           //~v55YI~
#define FUNCID_ASSOCIATE   220  //open with association            //~v564I~
#define FUNCID_RSH         221  //open with association            //~v592I~
#define FUNCID_STDCPREGION 222  //standard(stream) mode cut and paste region//~v66eI~
#define FUNCID_STDCPPASTE  223  //standard(stream) mode paste      //~v66fI~
#define FUNCID_PREVCMDSCR  224  //previous cmd of this screen      //~v670I~
#define FUNCID_NEXTCMDSCR  225  //next     cmd of this screen      //~v670I~
#define FUNCID_FILEDESC    226  //toggle "display file description" mode//~v690R~
#define FUNCID_CAPSLOCK    227  //capslock ob/off [all]            //~v69JI~
#define FUNCID_TSO         228  //tso cmd                          //~v70zI~
#define FUNCID_ICHANGE     229  //ichange                          //~v72PI~
#define FUNCID_ICHANGENX   230  //ichangenx                        //~v72PI~
#define FUNCID_BNDS        231  //bounds/bnds                      //~v74EI~
#define FUNCID_TFLOW       232  //TFLow/TF                         //~v755I~
#define FUNCID_EDITF80     233     //edit f80                      //~v75HI~
#define FUNCID_BROWSEF80   234     //browse f80                    //~v75HI~
#define FUNCID_SELECTF80   235     //select f80                    //~v75HI~
#define FUNCID_SENDREP     236     //filename send/recev rep mode  //~v76gI~
#define FUNCID_SENDINS     237     //filename send/recev ins mode  //~v76gI~
#define FUNCID_SENDDEL     238     //filename send/recev del mode  //~v76gR~
#define FUNCID_SENDUP      239     //filename send/recev csr up    //~v76gI~
#define FUNCID_SENDDOWN    240     //filename send/recev csr down  //~v76gI~
#define FUNCID_SWCHARHEX   241     //cursor jump between hex and char part//~v773I~
#define FUNCID_FINDWORDF   242     //find word under the cursor forward//~v77ER~
#define FUNCID_FINDWORDB   243     //find word under the cursor backword//~v77ER~
#define FUNCID_IFINDWORDF  244     //ifind word under the cursor forward//~v77ER~
#define FUNCID_IFINDWORDB  245     //ifind word under the cursor backword//~v77ER~
#define FUNCID_COPYWORDCMD 246     //copy word to cmd line         //~v77FR~
#define FUNCID_SYNTAX      247     //syntax highlight              //~v780I~
#define FUNCID_CUT         248     //cut/copy to work file         //~v783I~
#define FUNCID_PASTE       249     //paste from  work file         //~v783I~
#define FUNCID_PROFILE     250     //profile cmd                   //~v78rI~
#ifdef FTPSUPP                                                     //~v78ZI~
#define FUNCID_TSOHOTKEY   251     //sw 3270 key operation<->xe    //~v78ZI~
#endif                                                             //~v78ZI~
                                                                   //~va0xI~
#ifdef UTF8UCS2                                                    //~va3dI~
#define FUNCID_LIGATURE    252     //ligature toggle               //~va3dI~
#endif                                                             //~va3dI~
#ifdef UTF8SUPPH                                                   //~va0xR~
#define FUNCID_MODE        253     //mode change(codepage etc)     //~va0xI~
#endif                                                             //~va0xI~
#ifdef UTF8UCS2                                                    //~va30I~
#define FUNCID_COMBINE     254     //combine mode                  //~va30I~
#endif                                                             //~va30I~
                                                                   //~va0xI~
#define FUNCID_GRAPHCHAR    256                                 //~5224R~
#define FUNCID_NULLCHAR     FUNCID_GRAPHCHAR    //>=255 to get char from func tbl//~v0a2I~
#define FUNCID_GRAPHCHAR_LLC 	FUNCID_GRAPHCHAR+1              //~5224R~
#define FUNCID_GRAPHCHAR_LHS 	FUNCID_GRAPHCHAR+2              //~5224R~
#define FUNCID_GRAPHCHAR_LRC 	FUNCID_GRAPHCHAR+3              //~5224R~
#define FUNCID_GRAPHCHAR_LVS 	FUNCID_GRAPHCHAR+4              //~5224R~
#define FUNCID_GRAPHCHAR_CX  	FUNCID_GRAPHCHAR+5              //~5224R~
#define FUNCID_GRAPHCHAR_RVS 	FUNCID_GRAPHCHAR+6              //~5224R~
#define FUNCID_GRAPHCHAR_ULC 	FUNCID_GRAPHCHAR+7              //~5224R~
#define FUNCID_GRAPHCHAR_UHS 	FUNCID_GRAPHCHAR+8              //~5224R~
#define FUNCID_GRAPHCHAR_URC 	FUNCID_GRAPHCHAR+9              //~5224R~
#define FUNCID_GRAPHCHAR_HL  	FUNCID_GRAPHCHAR+10             //~5224R~
#define FUNCID_GRAPHCHAR_VL  	FUNCID_GRAPHCHAR+11             //~5224R~
                                                                   //~v705I~
#define GRAPHKEYENTNO  11                                          //~v705M~
#define GRAPHKEYENTNO2 9      //except HL/VL                       //~v705M~
#define GRAPHCHAR_FUNCIDLEN  13      //compare funcname upto "(E)LineChr-BT"//~v71QI~
//**************************************************
//*key/command function*****************************
//**************************************************

	FTFUNC func_up;
	FTFUNC func_down;
	FTFUNC func_left;
	FTFUNC func_right;
	FTFUNC func_nexttab_pan;
	FTFUNC func_nexttab_file;
	FTFUNC func_prevtab_pan;                                    //~5514R~
	FTFUNC func_prevtab_file;                                   //~5514I~
	FTFUNC func_bs_pan;
	FTFUNC func_bs_file;
	FTFUNC func_ins;
	FTFUNC func_del_pan;
	FTFUNC func_del_file;
	FTFUNC func_lineup_file;                                    //~5111R~
//  FTFUNC func_lineup_dir;                                     //~v030I~
	FTFUNC func_linedown_file;                                  //~5111R~
//  FTFUNC func_linedown_dir;                                   //~v030R~
	FTFUNC func_pgup_file;                                      //~5111I~
	FTFUNC func_pgup_pan;                                          //~v557I~
//  FTFUNC func_pgup_dir;                                       //~v030R~
	FTFUNC func_pgdown_file;                                    //~5111I~
	FTFUNC func_pgdown_pan;                                        //~v557I~
//  FTFUNC func_pgdown_dir;                                     //~v030R~
	FTFUNC func_pgleft_file;
	FTFUNC func_pgright_file;
	FTFUNC func_nextline;
	FTFUNC func_prevline;                                       //~5514I~
	FTFUNC func_exec_pan;
	FTFUNC func_exec_file;
	FTFUNC func_exec_dir;                                       //~v030I~
	FTFUNC func_linetop_pan;                                    //~4C24R~
	FTFUNC func_linetop_file;                                   //~4C23I~
	FTFUNC func_linetop_dir;                                       //~v55NI~
	FTFUNC func_lineend_pan;                                    //~4C23I~
	FTFUNC func_lineend_file;                                   //~4C23I~
	FTFUNC func_lineend_dir;                                       //~v55NI~
	FTFUNC func_filetop_file;
//  FTFUNC func_filetop_dir;                                    //~v030R~
	FTFUNC func_fileend_file;
//  FTFUNC func_fileend_dir;                                    //~v030R~
	FTFUNC func_pgtop_pan;                                         //~v61dI~
	FTFUNC func_pgend_pan;                                         //~v61dI~
    FTFUNC func_nextvalue_pan;                                     //~v07aI~
    FTFUNC func_prevvalue_pan;                                     //~v07aI~
    FTFUNC func_dlcmdcut_dir;                                      //~v07eR~
    FTFUNC func_dlcmdpaste_dir;                                    //~v07eR~
    FTFUNC func_dlcmdchngsz_dir;                                   //~v10rR~
//#ifdef UNX                                                       //~v55hR~
#ifdef FTPSUPP                                                     //~v55hI~
    FTFUNC func_dlcmduidorsz_dir;                                  //~v20fI~
#endif                                                             //~v20fI~
    FTFUNC func_dlcmdlfn_dir;   //long filename dispaly mode change//~v182I~
                                                                   //~v182I~
	FTFUNC func_home;
	FTFUNC func_splitline_file;
	FTFUNC func_join_file;      //join cmd                         //~v47iR~
	FTFUNC func_insline_file;
	FTFUNC func_delline_file;
	FTFUNC func_eraseeol_pan;                                   //~4C25R~
	FTFUNC func_eraseeol_file;                                  //~4C25R~
	FTFUNC func_erasetol_pan;                                   //~4C25R~
	FTFUNC func_erasetol_file;                                  //~4C25R~
	FTFUNC func_cleartol_pan;                                   //~5111I~
	FTFUNC func_cleartol_file;                                  //~5111I~
	FTFUNC func_help;
	FTFUNC func_save_file;
	FTFUNC func_quit;
	FTFUNC func_exit;                                            //~4C18I~
	FTFUNC func_term;                                           //~5224I~
	FTFUNC func_end_pan;
	FTFUNC func_end_file;
	FTFUNC func_end_dir;                                        //~v020I~
	FTFUNC func_find_file;
	FTFUNC func_find_pan;                                          //~v76mI~
	FTFUNC func_ifind_file;	//case insecsitive find
	FTFUNC func_ifind_pan;                                         //~v76mI~
	FTFUNC func_rfind_file;	//repeat find
	FTFUNC func_rfind_pan;                                         //~v76gI~
	FTFUNC func_revrfind_file;	//reverse repeat find
	FTFUNC func_revrfind_pan;                                      //~v76mI~
	FTFUNC func_change_file;
	FTFUNC func_ichange_file;                                      //~v72PI~
	FTFUNC func_ichangenx_file;                                    //~v72PI~
	FTFUNC func_rchange_file;
	FTFUNC func_revrchange_file;
	FTFUNC func_cancel_file;
	FTFUNC func_cancel_pan;                                     //~4C25I~
	FTFUNC func_cancel_dir;                                     //~v020I~
	FTFUNC func_splith;
	FTFUNC func_splitv;
	FTFUNC func_swap;
	FTFUNC func_create_file;
	FTFUNC func_edit_file;
	FTFUNC func_edittext_file;                                     //~v50GI~
	FTFUNC func_editbin_file;                                      //~v10GI~
	FTFUNC func_editspf_file;                                      //~v10LI~
	FTFUNC func_editspfcob_file;                                   //~v414R~
	FTFUNC func_editspfcobnum_file;                                //~v414R~
	FTFUNC func_editspfcob2_file;                                  //~v42yI~
	FTFUNC func_editspfcob2num_file;                               //~v42yI~
	FTFUNC func_editf80_file;                                      //~v75HI~
	FTFUNC func_browse_file;
	FTFUNC func_browsetext_file;                                   //~v50GI~
	FTFUNC func_browsebin_file;                                    //~v10GI~
	FTFUNC func_browsespf_file;                                    //~v10LI~
	FTFUNC func_browsespfcob_file;                                 //~v414R~
	FTFUNC func_browsespfcobnum_file;                              //~v414R~
	FTFUNC func_browsespfcob2_file;                                //~v42yI~
	FTFUNC func_browsespfcob2num_file;                             //~v42yI~
	FTFUNC func_browsef80_file;                                    //~v75HI~
	FTFUNC func_select;                                            //~v09wI~
	FTFUNC func_selecttext;                                        //~v50GI~
	FTFUNC func_selectbin;                                         //~v10GI~
	FTFUNC func_selectspf;                                         //~v10LI~
	FTFUNC func_selectspfcob;                                      //~v414R~
	FTFUNC func_selectspfcobnum;                                   //~v414R~
	FTFUNC func_selectspfcob2;                                     //~v42yI~
	FTFUNC func_selectspfcob2num;                                  //~v42yI~
	FTFUNC func_selectf80;                                         //~v75HI~
	FTFUNC func_retrieveprev;                                   //~5114R~
	FTFUNC func_retrieveprevscr;                                   //~v670I~
	FTFUNC func_retrievenext;                                   //~5114I~
	FTFUNC func_retrievenextscr;                                   //~v670I~
	FTFUNC func_undo_file;
	FTFUNC func_redo_file;
	FTFUNC func_repline_file;
	FTFUNC func_nextpan;                                        //~5105R~
	FTFUNC func_prevpan;                                        //~5105R~
	FTFUNC func_dos;
	FTFUNC func_locate_file;
	FTFUNC func_locate_dir;                                        //~v0ieI~
	FTFUNC func_copy_file;
	FTFUNC func_repl_file;                                      //~5106I~
	FTFUNC func_hex_file;
	FTFUNC func_tabctr_file;
	FTFUNC func_reset;
	FTFUNC func_char;
	FTFUNC func_char_pan;
	FTFUNC func_char_file;
	FTFUNC func_block_file;                                     //~5122I~
	FTFUNC func_stdcpregion_file;                                  //~v66eI~
	FTFUNC func_stdcppaste_file;                                   //~v66fI~
	FTFUNC func_stdcppaste_pan;                                    //~v66fI~
	FTFUNC func_copytocb_file;	//save cap dat to cb               //~v0heR~
	FTFUNC func_lmark_file;      //line mark                          //~v06eR~
	FTFUNC func_blockrep_file;                                  //~5122I~
	FTFUNC func_blockrep_pan;                                      //~v10MI~
	FTFUNC func_blockdel_file;                                  //~5122I~
	FTFUNC func_blockins_file;                                  //~5122I~
	FTFUNC func_blockins_pan;                                      //~v10MI~
	FTFUNC func_blockclear_file;                                //~5513I~
//  FTFUNC func_blockcopy_file;    //copy by Ins/Rep mode       //~v06lR~
	FTFUNC func_blockcutmove_file;                              //~5521M~
	FTFUNC func_blockclearmove_file;                            //~5521M~
	FTFUNC func_lineexclude_file;                               //~v06lI~
	FTFUNC func_lineinclude_file;                               //~v06lI~
	FTFUNC func_csrstep;                                        //~5225I~
	FTFUNC func_cid;                                            //~5225I~
	FTFUNC func_setscroll;                                      //~v033I~
	FTFUNC func_ini;                                            //~5429I~
	FTFUNC func_opt;                                            //~v05BI~
	FTFUNC func_number;                                         //~v069I~
//* internal function call
	FTFUNC func_draw_pan;
	FTFUNC func_draw_file;
	FTFUNC func_draw_dir;                                       //~v020I~
//*                                                                //~v0h9I~
	FTFUNC func_cmd;
	FTFUNC func_version;                                           //~v0a2I~
	FTFUNC func_drop_file;                                         //~v0h9I~
	FTFUNC func_exclude_file;                                      //~v0hzI~
	FTFUNC func_iexclude_file;                                     //~v0hzI~
	FTFUNC func_xx_file;        //reverse excluded                 //~v41kR~
	FTFUNC func_append_file;                                       //~v0iaI~
	FTFUNC func_pos_pan;                                           //~v0j2I~
	FTFUNC func_key;                                               //~v0jnR~
	FTFUNC func_submit;                                            //~v0k4I~
	FTFUNC func_hexinput;                                          //~v101I~
	FTFUNC func_findnx_file;                                       //~v10nI~
	FTFUNC func_ifindnx_file;	//case insecsitive find            //~v10nI~
	FTFUNC func_changenx_file;                                     //~v10nI~
	FTFUNC func_sort;                                              //~v10II~
	FTFUNC func_sort_dir;                                          //~v57jI~
	FTFUNC func_col;                                               //~v11NI~
	FTFUNC func_dlcmdrefresh;                                      //~v152I~
	FTFUNC func_bc;                                                //~v155R~
	FTFUNC func_tc;                                                //~v155I~
//    FTFUNC func_tcnx;                                            //~v17fR~
	FTFUNC func_ppsrch;                                            //~v42hR~
	FTFUNC func_ppsrchnx;                                          //~v42wI~
	FTFUNC func_xmlsrch;                                           //+vbe0I~
	FTFUNC func_browsehex_file;                                    //~v440R~
	FTFUNC func_edithex_file;                                      //~v440R~
	FTFUNC func_selecthex_file;                                    //~v440R~
	FTFUNC func_cmdrepeat;                                         //~v47kI~
	FTFUNC func_dbcsconv;                                          //~v47UR~
	FTFUNC func_shortcut;                                          //~v48fI~
	FTFUNC func_shortcutquery;                                     //~v48fI~
	FTFUNC func_renum;                                             //~v504I~
	FTFUNC func_rotate;                                            //~v511I~
	FTFUNC func_copyword;                                          //~v53cI~
	FTFUNC func_pathup;                                            //~v558I~
	FTFUNC func_pathdown;                                          //~v558I~
	FTFUNC func_execmdfile;                                        //~v55nI~
	FTFUNC func_tflow;                                             //~v755I~
//#ifdef W32                                                       //~v651R~
#if defined(W32)||defined(XXE)                                     //~v651I~
	FTFUNC func_at;                                                //~v55WI~
#endif                                                             //~v55WI~
//#ifdef W32                                                       //~v651R~
#if defined(W32)||defined(XXE)                                     //~v651I~
	FTFUNC func_sleep;                                             //~v55YI~
#endif                                                             //~v651I~
#if defined(W32)||defined(LNX)                                     //~v64vR~
	FTFUNC func_openwith;                                          //~v564I~
#endif                                                             //~v64vR~
#ifdef FTPSUPP                                                     //~v592I~
	FTFUNC func_rsh;                                               //~v592R~
#endif                                                             //~v592I~
	FTFUNC func_desc_dir;                                          //~v690R~
	FTFUNC func_capslock;                                          //~v69JI~
	FTFUNC func_tso;                                               //~v70zI~
	FTFUNC func_bnds;                                              //~v74EI~
	FTFUNC func_sendins_dir;                                       //~v76gI~
	FTFUNC func_sendins_pan;                                       //~v76gI~
	FTFUNC func_sendrep_dir;                                       //~v76gI~
	FTFUNC func_sendrep_pan;                                       //~v76gI~
	FTFUNC func_senddel_dir;                                       //~v76iI~
	FTFUNC func_sendup_dir;                                        //~v76gI~
	FTFUNC func_senddown_dir;                                      //~v76gI~
	FTFUNC func_jumpcharhex_file;                                  //~v773I~
	FTFUNC func_findwordF_file;                                    //~v77EI~
	FTFUNC func_findwordB_file;                                    //~v77EI~
	FTFUNC func_ifindwordF_file;                                   //~v77EI~
	FTFUNC func_ifindwordB_file;                                   //~v77EI~
	FTFUNC func_copywordcmd_file;                                  //~v77FR~
	FTFUNC func_syntax;                                            //~v780I~
	FTFUNC func_cut_file;                                          //~v783R~
	FTFUNC func_paste_file;                                        //~v783R~
	FTFUNC func_profile;                                           //~v78rI~
#ifdef FTPSUPP                                                     //~v78ZI~
	FTFUNC func_tsohotkey;                                         //~v78ZI~
	FTFUNC func_3270kbd;                                           //~v78ZI~
#endif                                                             //~v78ZI~
#ifdef UTF8SUPPH                                                   //~va0xR~
	FTFUNC func_mode;                                              //~va0xI~
#endif                                                             //~va0xI~
#ifdef UTF8UCS2                                                    //~va30I~
	FTFUNC func_optcombine;                                        //~va30I~
	FTFUNC func_optligature;                                       //~va3dI~
#endif                                                             //~va30I~
	FTFUNC func_ebc;                                               //~va7KI~
	FTFUNC func_node;                                              //~vac0I~
	FTFUNC func_findPSF;                                           //~vbCBI~
	FTFUNC func_findPSP;                                           //~vbCBI~
	FTFUNC func_revfindPSP;                                        //~vb50R~
	FTFUNC func_revfindPSF;                                        //~vb50R~
	FTFUNC func_displayPS;                                         //~vbCBI~
	FTFUNC func_shortpath;                                         //~vba2I~
                                                                //~5224I~
//************************************                          //~5224M~
//*function key asignment table                                 //~5224M~
//************************************                          //~5224M~
//*function asignment table entry                               //~5224M~
//#define FTMAXKEY  	8				//max asign key count      //~v0isR~
#define FTMAXKEY  	4				//max asign key count          //~v0isI~
#define CFTMAXSCAN 4                                               //~v0ihI~
                                                                   //~v51yI~
#define RC2CONSEQERR    2  	//conseqtive err to set csr next line  //~v51yR~
#define RC3LEAVECMDLINE 3	//rc=OK but leave cmd line uncleared   //~v51yR~
                                                                   //~v0ihI~
typedef struct _FUNCTBL                                         //~5224M~
{                                                               //~5224M~
 		UCHAR  FTnamee[20];			//description English       //~5224M~
#define FTNAMEGRAPHHEXPOS 			14  //hex value set pos        //~v705I~
 		UCHAR  FTnamej[20];			//description Japanese      //~5224M~
		USHORT FTfuncid;			//func id number            //~v06fR~
		UCHAR  FTflag;				//func flag                 //~5224M~
#define FTFEONLY		0x01		//for english mode only     //~5224M~
#define FTFJONLY		0x02		//for japanese mode only    //~5224M~
#define FTFFREECW   	0x04		//cw not avail after process end//~5429R~
#define FTFUPINI	   	0x08		//updated by ini process    //~5429I~
#define FTFCSRKEY      	0x10		//csr move key(short path required)//~5504I~
#define FTFDUPACMD     	0x20		//alias cmd duplicated         //~v09wI~
//#define FTFDUPACMDFUNC  0x40        //alias cmd duplicated allows and process both by a func//~vbd7I~//~vbdsR~
                                                                   //~v705I~
#define FTFLINECHSET   	0x20		//string input setupped for GRAPHIC func only//~v705I~
                                                                   //~v705I~
#define FTFCMDONLY   	0x40		//no key assignment allowed    //~v0ioI~
#define FTFEUC       	0x80		//euc conv done                //~v61tI~
		UCHAR  FTchar;				//graphic char              //~5224M~
 		FTFUNC *FTfunc[UCWMAXTYPE];	//function addr             //~5224M~
		UCHAR  FTcmd  [4];			//command word              //~5224M~
		UCHAR  FTcmda [4];			//command alias             //~5224M~
		USHORT FTkey[FTMAXKEY];		//asigned key               //~5224M~
		UCHAR  FTkflag[FTMAXKEY];	//for each key              //~5224M~
#define FTDMYF 			0x00		//dummy flag for coding only//~5224M~
#define FTFIX  			0x01		//cannot change asigned key //~5224M~
#define FTSHIFT			0x02		//chk SHIFT key status      //~5224M~
#define FTCTLC			0x04		//Ctrl+char key(optional use)  //~v55jI~
#define FTDUPER			0x80		//duplicated asign err      //~5224M~
#define FTKEYER			0x40		//invalid key used          //~5224M~
#define FTUPDATEINI		0x20		//control update by xe.ini file//~vb55I~
//  	char   FTcmdlen;			//command compair string len   //~v0iuR~
//  	char   FTcmdalen;			//command compair string len   //~v0iuR~
//      struct _FUNCTBL* FTdupnext;	//one of key duplicated assigned//~v76iR~
//      struct _FUNCTBL* FTdupprev;	//back chain                   //~v76iR~
		UCHAR  FTflag2; 			//func flag2                   //~v71PI~
#define FTF2FIXEDVERB    0x01		//command verb is not changable on=02 panel//~v71PR~
#define FTF2HASDUPKEY    0x02		//contains duplicated assigned key//~v76iI~
#define FTF2FIND_PSSUPP  0x04		//PSx cmd support              //~vbCBR~
#define FTF2FINDCMD      0x08		//find cmd                     //~vbCCI~
#define FTF2CHANGECMD    0x10		//change cmd                   //~vbCCI~
#define FTF2DUPACMDFUNC  0x20       //alias cmd duplicated allows and process both by a func//~vbdsI~
		UCHAR  FTrsv  [3];			//command word                 //~v71PI~
} FUNCTBL,*PFUNCTBL;                                               //~v0ioR~
typedef struct _FUNCTBLC {                                         //~v0ihI~
				FUNCTBL *ckpft [CFTMAXSCAN];	//function table entry ptr//~v0ihI~
				UCHAR    ckscan[CFTMAXSCAN];	//scan code        //~v0ihI~
				UCHAR    ckflag[CFTMAXSCAN];	//flags FTkflag    //~v55jI~
			  } FUNCTBLC,*PFUNCTBLC;                               //~v0ioR~
//*work functbl for option 0.4                                     //~v0ioI~
typedef struct _WORKFT                                             //~v0ioI~
{                                                                  //~v0ioI~
    	UCHAR           WFTcmd  [4];			//command word     //~v0iwR~,//~v71PR~
    	UCHAR           WFTcmda [4];			//command alias    //~v0iwR~,//~v71PR~
		USHORT          WFTkey[FTMAXKEY];		//asigned key      //~v0ioI~
		UCHAR           WFTkflag[FTMAXKEY];	//for each key         //~v0ioI~
} WORKFT,*PWORKFT;                                                 //~v0ioI~
typedef struct _WORKFTHDR {                                        //~v0ioI~
				PWORKFT   WFTHpwft;                                //~v0ioI~
				int       WFTHentno;                               //~v0ioI~
                PFUNCTBLC WFTHckft;	//char key                     //~v0ioR~
                PFUNCTBL *WFTHsckft;	//shift+char key           //~v0ioR~
                PFUNCTBL *WFTHekft;	//ext key                      //~v0ioR~
                PFUNCTBL *WFTHsekft;	//shift+ext key            //~v0ioR~
			  } WORKFTHDR,*PWORKFTHDR;                             //~v0ioI~
typedef struct _PMC {  		//pending multi cmd                    //~v67CR~
				UQUEE     PMCqe;                                   //~v67CR~
				int       PMCcmdlen;                               //~v67CR~
                char      PMCcmd[1];                               //~v67CR~
			  } PMC,*PPMC;                                         //~v67CR~
#define PMCSZ (sizeof(PMC))                                        //~v67CR~
//*FUNCTION*****************************************               //~v0ihR~
//int funcinit(void);                                              //~v705R~
int funcinit(char *Postype);                                       //~v705I~
//**************************************************            //~5224M~
void functerm(void);                                            //~5224M~
//**************************************************            //~5224M~
int funccall(int Pkeytype,UCHAR *Pkey,PUCLIENTWE Ppcw);         //~5224M~
//**************************************************               //~v0ihI~
FUNCTBL *funcftsrch(int Pkeytype,USHORT Pkey,int Pshift);          //~v0ihI~
//**************************************************               //~v0ioI~
int funcgetwfth(int Popt,PWORKFTHDR Ppwfth);                       //~v0ioI~
//**************************************************               //~v0ioI~
int funcputwfth(PWORKFTHDR Ppwfth,int Popt);                       //~v0ioR~
//**************************************************               //~v0itI~
void funcsetft(void);                                              //~v0itR~
//**************************************************            //~5504I~
void funcopdpostp(PUCLIENTWE Ppcw,int Prc);                     //~5504I~
//**************************************************            //~5224M~
int  funccmderr(PUCLIENTWE Ppcw,int Prc);                       //~5527R~
//**************************************************               //~v07aI~
int  funcinvalidkey(PUCLIENTWE Ppcw);                              //~v07aI~
//**************************************************               //~v09PI~
int  funcinhibitkey(UCHAR Pkey);                                   //~v09PR~
//**************************************************               //~v55cI~
int funcchngeenter(int Popt);                                      //~v55cR~
//**************************************************               //~v560I~
int funcsleepreset(PUCLIENTWE Ppcw);                               //~v562R~
//**************************************************               //~v55WI~
#ifdef WINCON                                                      //~v562I~
//**************************************************               //~v562I~
int funcatcmdreset(int Popt);                                      //~v562R~
    #define    FAT_RESET 0x01                                      //~v562I~
    #define    FAT_COMP  0x02                                      //~v562I~
    #define    FAT_CMDER 0x10  //multi cmd stop by cmd err         //~v562I~
    #define    FAT_IGNOREERR 0x0100	//ignore subcmd err            //~v564I~
#endif                                                             //~v562I~
//#ifdef WXE                                                       //~v64vR~
#ifdef WXEXXE                                                      //~v64vR~
//**************************************************               //~v55WI~
int funcsetsleepblock(int Pintvl);                                 //~v55WI~
#endif                                                             //~v55WI~
int funcdupktsrch(int Popt,/*KEYTBL*/void *Ppkt,int Pmodidx,FUNCTBL **Pppft);//~v76iR~
#define FDKSO_FTSHIFT   0x01      //S+A,S+C                        //~vb50I~
int funcgetOpdLCCT(int Popt,PUCLIENTWE Ppcw,int Popdno,char **Pplc,char **Ppct,int *Pplen);//~vavQI~
